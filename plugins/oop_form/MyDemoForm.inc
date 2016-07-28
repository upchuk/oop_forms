<?php

$plugin = array(
  'title' => 'My Demo Form',
  'description' => 'This is a demonstration OOP form',
  'class' => 'MyDemoForm'
);

class MyDemoForm extends OOPFormBase {

  private $test;

  /**
   * @return mixed
   */
  protected function getBaseFormId() {
    return 'my_demo_form';
  }

  /**
   * The form definition
   *
   * @param $form
   * @param $form_state
   *
   * @return array
   */
  public function form($form, &$form_state) {
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#description' => t('Your name'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
    $this->test = 'sadasd';
    return $form;
  }

  /**
   * The main form validation handler
   *
   * @param $form
   * @param $form_state
   *
   * @return mixed
   */
  public function validate(&$form, &$form_state) {
    // Perform validations
  }

  /**
   * The main form submit handler
   *
   * @param $form
   * @param $form_state
   *
   * @return mixed
   */
  public function submit(&$form, &$form_state) {
    // Handle the submit
  }
}