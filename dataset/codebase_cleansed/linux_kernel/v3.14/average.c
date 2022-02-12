void ewma_init(struct ewma *avg, unsigned long factor, unsigned long weight)
{
WARN_ON(!is_power_of_2(weight) || !is_power_of_2(factor));
avg->weight = ilog2(weight);
avg->factor = ilog2(factor);
avg->internal = 0;
}
struct ewma *ewma_add(struct ewma *avg, unsigned long val)
{
unsigned long internal = ACCESS_ONCE(avg->internal);
ACCESS_ONCE(avg->internal) = internal ?
(((internal << avg->weight) - internal) +
(val << avg->factor)) >> avg->weight :
(val << avg->factor);
return avg;
}
