--TEST--
Random: Randomizer: nextFloat(): Basic functionality
--FILE--
<?php

use Random\Engine;
use Random\Engine\Mt19937;
use Random\Engine\PcgOneseq128XslRr64;
use Random\Engine\Secure;
use Random\Engine\Test\TestShaEngine;
use Random\Engine\Xoshiro256StarStar;
use Random\Randomizer;

require __DIR__ . "/../../engines.inc";

$engines = [];
$engines[] = new Mt19937(null, MT_RAND_MT19937);
$engines[] = new Mt19937(null, MT_RAND_PHP);
$engines[] = new PcgOneseq128XslRr64();
$engines[] = new Xoshiro256StarStar();
$engines[] = new Secure();
$engines[] = new TestShaEngine();

foreach ($engines as $engine) {
    echo $engine::class, PHP_EOL;

    $randomizer = new Randomizer($engine);

    // Basic range test.
    for ($i = 0; $i < 10_000; $i++) {
        $result = $randomizer->nextFloat();

        if ($result >= 1 || $result < 0) {
            die("failure: out of range at {$i}");
        }
    }
}

die('success');

?>
--EXPECT--
Random\Engine\Mt19937
Random\Engine\Mt19937
Random\Engine\PcgOneseq128XslRr64
Random\Engine\Xoshiro256StarStar
Random\Engine\Secure
Random\Engine\Test\TestShaEngine
success
