<?hh

class F {
  function __construct($a) { $this->a = $a; }

  async function retA() { return $this->a; }
  async function awaitA() {
    $b = await $this->retA();
    return 1 + $b;
  }
}

$f = new F(42);
var_dump(HH\Asio\join($f->retA()));
var_dump(HH\Asio\join($f->awaitA()));
