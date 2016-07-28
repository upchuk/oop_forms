<?php

/**
 * Class OOPFormFactory
 *
 * Factory class for the OOP forms
 */
class OOPFormFactory {

  private static $instance;
  private $forms = array();
  private $plugins = array();

  /**
   * OOPFormFactory constructor.
   */
  private function __construct() {
    $this->plugins = ctools_get_plugins('oop_forms', 'oop_form');
  }

  /**
   * @return OOPFormFactory
   */
  public static function getInstance() {
    if (!static::$instance) {
      static::$instance = new static();
    }

    return static::$instance;
  }

  /**
   * Returns an array of Form IDs used to respond to all the Form requests.
   *
   * @return array
   */
  public function getFormIds() {
    return array_keys($this->plugins);
  }

  /**
   * Builds and returns a certain form.
   *
   * Callback function to the drupal_retrieve_form() that triages to the right
   * form class defined in the ctools plugin.
   *
   * @param $form
   * @param $form_state
   *
   * @return array|void
   */
  public function buildForm($form, &$form_state) {
    $id = $form_state['build_info']['form_id'];
    if (isset($this->forms[$id])) {
      $object = $this->forms[$id];
    }
    else {
      $class = $this->plugins[$id]['class'];
      $object = $this->forms[$id] = new $class();
    }

    if (!$object instanceof OOPFormInterface) {
      return $form;
    }

    $form = $object->form($form, $form_state);
    $object->prepareForm($form, $form_state);
    return $form;
  }

  /**
   * Returns a certain form object.
   *
   * @param $id
   *
   * @return OOPFormInterface
   */
  public function getForm($id) {
    if (isset($this->forms[$id])) {
      return $this->forms[$id];
    }

    $class = $this->plugins[$id]['class'];
    return $this->forms[$id] = new $class();
  }

}