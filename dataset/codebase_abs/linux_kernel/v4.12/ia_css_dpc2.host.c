void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
( void ) V_5 ;
assert ( ( V_4 -> V_6 >= 0 ) && ( V_4 -> V_6 <= V_7 ) ) ;
assert ( ( V_4 -> V_8 >= 0 ) && ( V_4 -> V_8 <= V_9 ) ) ;
assert ( ( V_4 -> V_10 >= V_11 ) &&
( V_4 -> V_10 < 256 * V_11 ) ) ;
assert ( ( V_4 -> V_12 > 0 ) && ( V_4 -> V_12 < 16 * V_13 ) ) ;
assert ( ( V_4 -> V_14 > 0 ) && ( V_4 -> V_14 < 16 * V_13 ) ) ;
assert ( ( V_4 -> V_15 > 0 ) && ( V_4 -> V_15 < 16 * V_13 ) ) ;
assert ( ( V_4 -> V_16 > 0 ) && ( V_4 -> V_16 < 16 * V_13 ) ) ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_10 = V_4 -> V_10 ;
V_2 -> V_8 = V_4 -> V_8 ;
V_2 -> V_12 = V_4 -> V_12 ;
V_2 -> V_14 = V_4 -> V_14 ;
V_2 -> V_15 = V_4 -> V_15 ;
V_2 -> V_16 = V_4 -> V_16 ;
}
void
F_2 (
void * V_17 ,
T_1 V_5 )
{
( void ) V_17 ;
( void ) V_5 ;
}
void
F_3 (
const struct V_3 * V_18 ,
unsigned V_19 )
{
( void ) V_18 ;
( void ) V_19 ;
}
