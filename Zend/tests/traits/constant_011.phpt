--TEST--
Conflicting constants in a trait and another trait using it with different visibility modifiers should result in a fatal error, since this indicates that the code is incompatible.
--FILE--
<?php

trait Trait1 {
    public const Constant = 42;
}

trait Trait2 {
    use Trait1;
    private const Constant = 42;
}
?>
--EXPECTF--
Fatal error: Trait2 and Trait1 define the same constant (Constant) in the composition of Trait2. However, the definition differs and is considered incompatible. Class was composed in %s on line %d
