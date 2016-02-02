<?php

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/function.filter-has-var.php )
   *
   *
   * @type       mixed   One of INPUT_GET, INPUT_POST, INPUT_COOKIE,
   *                     INPUT_SERVER, or INPUT_ENV.
   * @variable_name
   *             mixed   Name of a variable to check.
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
function filter_has_var($type, $variable_name) {
  if (!is_int($type)) {
    trigger_error(
      'filter_has_var() expects parameter 1 to be long, '.
      gettype($type).' given', E_WARNING
    );
    return false;
  }

  switch ($type) {
    case INPUT_GET:
      return isset($_GET[$variable_name]);
    case INPUT_POST:
      return isset($_POST[$variable_name]);
    case INPUT_COOKIE:
      return isset($_COOKIE[$variable_name]);
    case INPUT_SERVER:
      return isset($_SERVER[$variable_name]);
    case INPUT_ENV:
      return isset($_ENV[$variable_name]);
  }
  return false;
}
