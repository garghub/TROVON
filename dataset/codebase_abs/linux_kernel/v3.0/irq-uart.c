static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
T_1 V_8 = F_2 ( V_5 -> V_9 + V_10 ) ;
int V_11 = V_5 -> V_12 ;
if ( V_8 & ( 1 << 0 ) )
F_3 ( V_11 ) ;
if ( V_8 & ( 1 << 1 ) )
F_3 ( V_11 + 1 ) ;
if ( V_8 & ( 1 << 2 ) )
F_3 ( V_11 + 2 ) ;
if ( V_8 & ( 1 << 3 ) )
F_3 ( V_11 + 3 ) ;
}
static void T_2 F_4 ( struct V_4 * V_5 )
{
void T_3 * V_13 = V_5 -> V_9 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_5 ( 0xf , V_13 + V_18 ) ;
V_15 = F_6 ( L_1 , 1 , V_5 -> V_12 , V_13 ,
V_19 ) ;
if ( ! V_15 ) {
F_7 ( L_2 ,
V_20 , V_5 -> V_12 ) ;
return;
}
V_17 = V_15 -> V_21 ;
V_17 -> V_22 . V_23 = V_24 ;
V_17 -> V_22 . V_25 = V_26 ;
V_17 -> V_22 . V_27 = V_28 ;
V_17 -> V_9 . V_29 = V_10 ;
V_17 -> V_9 . V_30 = V_18 ;
F_8 ( V_15 , F_9 ( 4 ) , V_31 ,
V_32 | V_33 , 0 ) ;
F_10 ( V_5 -> V_34 , V_5 ) ;
F_11 ( V_5 -> V_34 , F_1 ) ;
}
void T_2 F_12 ( struct V_4 * V_1 , unsigned int V_35 )
{
for (; V_35 > 0 ; V_35 -- , V_1 ++ )
F_4 ( V_1 ) ;
}
