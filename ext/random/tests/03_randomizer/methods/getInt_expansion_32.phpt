--TEST--
Random: Randomizer: getInt(): Returned values with insufficient bits are correctly expanded
--FILE--
<?php

use Random\Engine;
use Random\Randomizer;

final class ByteEngine implements Engine
{
    public $count = 0;

    public function generate(): string
    {
        return "\x01\x02\x03\x04\x05\x06\x07\x08"[$this->count++];
    }
}

$randomizer = new Randomizer(new ByteEngine());

var_dump(bin2hex(pack('V', $randomizer->getInt(0, 0x00FF_FFFF))));

?>
--EXPECT--
string(8) "01020300"
