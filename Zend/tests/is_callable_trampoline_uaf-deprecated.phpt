--TEST--
is_callable() with trampoline should not caused UAF [original test with deprecated syntax]
--FILE--
<?php

class B {}
class A extends B {
    public function bar($func) {
        var_dump(is_callable(array('parent', 'foo')));
    }

    public function __call($func, $args) {
    }
}

class X {
    public static function __callStatic($func, $args) {
    }
}

$a = new A();
// Extra X::foo() wrapper to force use of allocated trampoline.
X::foo($a->bar('foo'));

?>
--EXPECTF--
Deprecated: Use of "parent" in callables is deprecated in %s on line %d
bool(false)
