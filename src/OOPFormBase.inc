<?php


/**
 * Starter for the OOP forms. All new OOP Forms have to extend this class
 *
 * Class OOPFormBase
 */
abstract class OOPFormBase implements OOPFormInterface {

  /**
   * @return mixed
   */
  abstract protected function getBaseFormId();

  /**
   * {@inheritdoc}
   */
  public function prepareForm(&$form, &$form_state) {

    $form['#validate'] = array('oop_forms_validate');
    $form['#submit'] = array('oop_forms_submit');
    $form_state['build_info']['base_form_id'] = $this->getBaseFormId();
  }
}