--TEST--
Calling mb_convert_case() with an invalid casing mode
--EXTENSIONS--
mbstring
--FILE--
<?php

var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_UPPER));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_LOWER));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_TITLE));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_FOLD));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_UPPER_SIMPLE));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_LOWER_SIMPLE));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_TITLE_SIMPLE));
var_dump(mb_convert_case('foo BAR Spaß', MB_CASE_FOLD_SIMPLE));

// Invalid mode
try {
    var_dump(mb_convert_case('foo BAR Spaß', 100));
} catch (\ValueError $e) {
    echo $e->getMessage() . \PHP_EOL;
}

/* Regression test for new implementation;
 * When converting a codepoint, if we overwrite it with the converted version before
 * checking whether we should shift in/out of 'title mode', then the conversion will be incorrect */
var_dump(bin2hex(mb_convert_case("\x01I\x01,", MB_CASE_TITLE, 'UCS-2BE')));
var_dump(bin2hex(mb_convert_case("\x01I\x01,", MB_CASE_TITLE_SIMPLE, 'UCS-2BE')));

?>
--EXPECT--
string(13) "FOO BAR SPASS"
string(13) "foo bar spaß"
string(13) "Foo Bar Spaß"
string(13) "foo bar spass"
string(13) "FOO BAR SPAß"
string(13) "foo bar spaß"
string(13) "Foo Bar Spaß"
string(13) "foo bar spaß"
mb_convert_case(): Argument #2 ($mode) must be one of the MB_CASE_* constants
string(12) "02bc004e012d"
string(8) "0149012d"
