void change_bit(unsigned long nr, volatile void *addr)
{
if (test_bit(nr, addr))
goto try_clear_bit;
try_set_bit:
if (!test_and_set_bit(nr, addr))
return;
try_clear_bit:
if (test_and_clear_bit(nr, addr))
return;
goto try_set_bit;
}
int test_and_change_bit(unsigned long nr, volatile void *addr)
{
if (test_bit(nr, addr))
goto try_clear_bit;
try_set_bit:
if (!test_and_set_bit(nr, addr))
return 0;
try_clear_bit:
if (test_and_clear_bit(nr, addr))
return 1;
goto try_set_bit;
}
