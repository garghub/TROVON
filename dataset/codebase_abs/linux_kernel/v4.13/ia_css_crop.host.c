void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
}
void
V_3 (
struct V_7 * V_2 ,
const struct V_8 * V_4 ,
unsigned V_5 )
{
unsigned V_9 = V_10 ;
( void ) V_5 ;
F_2 ( & V_2 -> V_11 , V_4 -> V_12 ) ;
V_2 -> V_13 = V_9 / V_2 -> V_11 . V_14 ;
assert ( V_9 % V_2 -> V_11 . V_14 == 0 ) ;
}
void
F_3 (
const struct V_15 * V_16 ,
const struct V_17 * V_12 )
{
struct V_8 V_18 = V_19 ;
V_18 . V_12 = V_12 ;
F_4 ( V_16 , & V_18 ) ;
}
