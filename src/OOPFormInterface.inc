<?php

/**
 * Interface OOPFormInterface
 */
interface OOPFormInterface {

  /**
   * The form definition
   *
   * @param $form
   * @param $form_state
   *
   * @return array
   */
  public function form($form, &$form_state);

  /**
   * Prepares the form handlers and any other set up task for OOP readyness.
   *
   * @param $form
   * @param $form_state
   *
   * @return mixed
   */
  public function prepareForm(&$form, &$form_state);

  /**
   * The main form validation handler
   *
   * @param $form
   * @param $form_state
   *
   * @return mixed
   */
  public function validate(&$form, &$form_state);

  /**
   * The main form submit handler
   *
   * @param $form
   * @param $form_state
   *
   * @return mixed
   */
  public function submit(&$form, &$form_state);
}