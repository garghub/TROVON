void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 = V_4 -> V_6 ;
V_2 -> V_7 = V_4 -> V_8 != NULL ;
}
void
F_2 (
const struct V_1 * V_9 ,
unsigned V_10 )
{
if ( ! V_9 ) return;
F_3 ( V_10 , L_1 ) ;
F_3 ( V_10 , L_2 ,
L_3 , V_9 -> V_6 ) ;
F_3 ( V_10 , L_2 ,
L_4 , V_9 -> V_7 ) ;
}
void
F_4 (
struct V_11 * V_2 ,
const struct V_12 * V_4 ,
unsigned V_5 )
{
unsigned V_13 = V_14 ;
( void ) V_5 ;
F_5 ( & V_2 -> V_15 , V_4 -> V_16 ) ;
V_2 -> V_17 = V_13 / V_2 -> V_15 . V_18 ;
assert ( V_13 % V_2 -> V_15 . V_18 == 0 ) ;
}
void
F_6 (
const struct V_19 * V_20 ,
const struct V_21 * V_16 )
{
struct V_21 V_22 = V_23 ;
const struct V_12 V_24 = {
& V_22
} ;
V_22 . V_25 . V_26 = F_7 ( V_16 -> V_25 . V_26 , 2 ) ;
V_22 . V_25 . V_27 = V_16 -> V_25 . V_27 ;
V_22 . V_28 = F_7 ( V_16 -> V_28 , 2 ) ;
V_22 . V_29 = V_16 -> V_29 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_16 -> V_32 ;
V_22 . V_33 = V_16 -> V_33 ;
F_8 ( V_20 , & V_24 ) ;
}
