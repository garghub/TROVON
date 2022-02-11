void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
unsigned V_6 = V_7 ;
( void ) V_5 ;
F_2 ( & V_2 -> V_8 , V_4 -> V_9 ) ;
V_2 -> V_10 = V_6 / V_2 -> V_8 . V_11 ;
assert ( V_6 % V_2 -> V_8 . V_11 == 0 ) ;
V_2 -> V_12 = V_4 -> V_13 -> V_12 ;
V_2 -> V_14 = V_4 -> V_9 -> V_14 ;
}
void
F_3 (
const struct V_15 * V_13 ,
const struct V_16 * V_17 ,
const struct V_18 * V_9 )
{
struct V_3 V_19 = V_20 ;
V_19 . V_13 = V_13 ;
V_19 . V_9 = V_9 ;
F_4 ( V_17 , & V_19 ) ;
}
