--TEST--
IntlCalendar::FIELD_FIELD_COUNT
--INI--
date.timezone=Atlantic/Azores
--EXTENSIONS--
intl
--FILE--
<?php
var_dump(IntlCalendar::FIELD_FIELD_COUNT);
?>
--EXPECTF--
int(%d)
