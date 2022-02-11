void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 . V_7 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_5 = V_2 -> V_6 . V_7 + V_3 ;
return F_4 ( V_5 ) ;
}
int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
T_1 V_13 , V_14 = 10 ;
F_1 ( V_2 , V_15 , 0x3 ) ;
F_1 ( V_2 , V_16 , 0xf ) ;
F_1 ( V_2 , V_16 , 0 ) ;
F_1 ( V_2 , V_17 , 1 ) ;
F_1 ( V_2 , V_17 , 0 ) ;
do {
F_7 ( 100 , 110 ) ;
V_13 = F_3 ( V_2 , V_18 ) ;
} while ( V_13 != V_19 && V_14 -- );
if ( V_13 != V_19 ) {
F_8 ( V_11 , L_1 , V_13 ) ;
return - V_20 ;
}
F_1 ( V_2 , V_21 , V_22 | V_23 ) ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_1 ( V_2 , V_24 , 1 ) ;
F_1 ( V_2 , V_25 , 1 ) ;
F_1 ( V_2 , V_26 , 1 ) ;
F_1 ( V_2 , V_27 , 1 ) ;
}
void F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
V_2 -> V_28 = V_29 ;
F_11 ( V_2 ) ;
F_9 ( V_9 ) ;
}
