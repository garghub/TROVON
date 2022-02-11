static void
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_5 ) -> V_12 ;
int V_13 ;
F_3 ( V_5 , L_1 ) ;
if ( V_3 && V_2 -> V_14 . V_15 )
return;
V_13 = F_4 ( V_11 , ( V_8 -> V_16 != 0x50 ? 5 : 3 ) + V_3 * 2 ) ;
if ( V_13 ) {
F_5 ( V_5 , L_2 ) ;
return;
}
if ( V_8 -> V_16 != 0x50 ) {
F_6 ( V_11 , 0 , F_7 ( V_2 -> V_17 , V_18 ) , 1 ) ;
F_8 ( V_11 , V_19 ) ;
}
F_6 ( V_11 , 0 , F_9 ( V_2 -> V_17 , V_20 ) , 2 ) ;
F_8 ( V_11 , V_21 ) ;
F_8 ( V_11 , V_2 -> V_14 . V_22 >> 8 ) ;
if ( V_3 ) {
F_6 ( V_11 , 0 , V_23 , 1 ) ;
F_8 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
V_2 -> V_14 . V_15 = true ;
}
}
static void
F_11 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_5 ) -> V_12 ;
int V_13 ;
F_3 ( V_5 , L_1 ) ;
if ( V_3 && ! V_2 -> V_14 . V_15 )
return;
V_13 = F_4 ( V_11 , ( V_8 -> V_16 != 0x50 ? 5 : 3 ) + V_3 * 2 ) ;
if ( V_13 ) {
F_5 ( V_5 , L_3 ) ;
return;
}
F_6 ( V_11 , 0 , F_9 ( V_2 -> V_17 , V_20 ) , 2 ) ;
F_8 ( V_11 , V_24 ) ;
F_8 ( V_11 , 0 ) ;
if ( V_8 -> V_16 != 0x50 ) {
F_6 ( V_11 , 0 , F_7 ( V_2 -> V_17 , V_18 ) , 1 ) ;
F_8 ( V_11 , V_25 ) ;
}
if ( V_3 ) {
F_6 ( V_11 , 0 , V_23 , 1 ) ;
F_8 ( V_11 , 0 ) ;
F_10 ( V_11 ) ;
V_2 -> V_14 . V_15 = false ;
}
}
static void
F_12 ( struct V_1 * V_2 , int V_26 , int V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
V_2 -> V_28 = V_26 ; V_2 -> V_29 = V_27 ;
F_13 ( V_5 , F_14 ( V_2 -> V_17 ) ,
( ( V_27 & 0xFFFF ) << 16 ) | ( V_26 & 0xFFFF ) ) ;
F_13 ( V_5 , F_15 ( V_2 -> V_17 ) , 0 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_22 )
{
F_3 ( V_2 -> V_6 . V_5 , L_1 ) ;
if ( V_22 == V_2 -> V_14 . V_22 )
return;
V_2 -> V_14 . V_22 = V_22 ;
if ( V_2 -> V_14 . V_15 ) {
V_2 -> V_14 . V_15 = false ;
V_2 -> V_14 . V_30 ( V_2 , true ) ;
}
}
int
F_17 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_31 = F_16 ;
V_2 -> V_14 . V_32 = F_12 ;
V_2 -> V_14 . V_33 = F_11 ;
V_2 -> V_14 . V_30 = F_1 ;
return 0 ;
}
void
F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
int V_34 = V_2 -> V_17 ;
F_3 ( V_5 , L_1 ) ;
F_13 ( V_5 , F_19 ( V_34 ) , 0 ) ;
if ( ! F_20 ( V_5 , F_19 ( V_34 ) ,
V_35 , 0 ) ) {
F_5 ( V_5 , L_4 ) ;
F_5 ( V_5 , L_5 ,
F_21 ( V_5 , F_19 ( V_34 ) ) ) ;
}
}
