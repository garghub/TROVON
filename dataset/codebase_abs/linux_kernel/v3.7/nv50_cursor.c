static void
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
struct V_7 * V_8 = V_7 ( V_5 ) ;
struct V_9 * V_10 = F_2 ( V_5 ) -> V_11 ;
int V_12 ;
F_3 ( V_8 , L_1 ) ;
if ( V_3 && V_2 -> V_13 . V_14 )
return;
V_12 = F_4 ( V_10 , ( F_5 ( V_8 -> V_15 ) -> V_16 != 0x50 ? 5 : 3 ) + V_3 * 2 ) ;
if ( V_12 ) {
F_6 ( V_8 , L_2 ) ;
return;
}
if ( F_5 ( V_8 -> V_15 ) -> V_16 != 0x50 ) {
F_7 ( V_10 , 0 , F_8 ( V_2 -> V_17 , V_18 ) , 1 ) ;
F_9 ( V_10 , V_19 ) ;
}
F_7 ( V_10 , 0 , F_10 ( V_2 -> V_17 , V_20 ) , 2 ) ;
F_9 ( V_10 , V_21 ) ;
F_9 ( V_10 , V_2 -> V_13 . V_22 >> 8 ) ;
if ( V_3 ) {
F_7 ( V_10 , 0 , V_23 , 1 ) ;
F_9 ( V_10 , 0 ) ;
F_11 ( V_10 ) ;
V_2 -> V_13 . V_14 = true ;
}
}
static void
F_12 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
struct V_7 * V_8 = V_7 ( V_5 ) ;
struct V_9 * V_10 = F_2 ( V_5 ) -> V_11 ;
int V_12 ;
F_3 ( V_8 , L_1 ) ;
if ( V_3 && ! V_2 -> V_13 . V_14 )
return;
V_12 = F_4 ( V_10 , ( F_5 ( V_8 -> V_15 ) -> V_16 != 0x50 ? 5 : 3 ) + V_3 * 2 ) ;
if ( V_12 ) {
F_6 ( V_8 , L_3 ) ;
return;
}
F_7 ( V_10 , 0 , F_10 ( V_2 -> V_17 , V_20 ) , 2 ) ;
F_9 ( V_10 , V_24 ) ;
F_9 ( V_10 , 0 ) ;
if ( F_5 ( V_8 -> V_15 ) -> V_16 != 0x50 ) {
F_7 ( V_10 , 0 , F_8 ( V_2 -> V_17 , V_18 ) , 1 ) ;
F_9 ( V_10 , V_25 ) ;
}
if ( V_3 ) {
F_7 ( V_10 , 0 , V_23 , 1 ) ;
F_9 ( V_10 , 0 ) ;
F_11 ( V_10 ) ;
V_2 -> V_13 . V_14 = false ;
}
}
static void
F_13 ( struct V_1 * V_2 , int V_26 , int V_27 )
{
struct V_28 * V_15 = F_14 ( V_2 -> V_6 . V_5 ) ;
V_2 -> V_29 = V_26 ; V_2 -> V_30 = V_27 ;
F_15 ( V_15 , F_16 ( V_2 -> V_17 ) ,
( ( V_27 & 0xFFFF ) << 16 ) | ( V_26 & 0xFFFF ) ) ;
F_15 ( V_15 , F_17 ( V_2 -> V_17 ) , 0 ) ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_22 )
{
if ( V_22 == V_2 -> V_13 . V_22 )
return;
V_2 -> V_13 . V_22 = V_22 ;
if ( V_2 -> V_13 . V_14 ) {
V_2 -> V_13 . V_14 = false ;
V_2 -> V_13 . V_31 ( V_2 , true ) ;
}
}
int
F_19 ( struct V_1 * V_2 )
{
V_2 -> V_13 . V_32 = F_18 ;
V_2 -> V_13 . V_33 = F_13 ;
V_2 -> V_13 . V_34 = F_12 ;
V_2 -> V_13 . V_31 = F_1 ;
return 0 ;
}
