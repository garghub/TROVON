static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
struct V_8 * V_9 = F_2 ( V_1 ) ;
T_1 V_10 = F_3 ( V_5 -> V_11 + V_12 ) ;
int V_13 = V_5 -> V_14 ;
F_4 ( V_9 , V_3 ) ;
if ( V_10 & ( 1 << 0 ) )
F_5 ( V_13 ) ;
if ( V_10 & ( 1 << 1 ) )
F_5 ( V_13 + 1 ) ;
if ( V_10 & ( 1 << 2 ) )
F_5 ( V_13 + 2 ) ;
if ( V_10 & ( 1 << 3 ) )
F_5 ( V_13 + 3 ) ;
F_6 ( V_9 , V_3 ) ;
}
static void T_2 F_7 ( struct V_4 * V_5 )
{
void T_3 * V_15 = V_5 -> V_11 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_8 ( 0xf , V_15 + V_20 ) ;
V_17 = F_9 ( L_1 , 1 , V_5 -> V_14 , V_15 ,
V_21 ) ;
if ( ! V_17 ) {
F_10 ( L_2 ,
V_22 , V_5 -> V_14 ) ;
return;
}
V_19 = V_17 -> V_23 ;
V_19 -> V_9 . V_24 = V_25 ;
V_19 -> V_9 . V_26 = V_27 ;
V_19 -> V_9 . V_28 = V_29 ;
V_19 -> V_11 . V_30 = V_12 ;
V_19 -> V_11 . V_31 = V_20 ;
F_11 ( V_17 , F_12 ( 4 ) , V_32 ,
V_33 | V_34 , 0 ) ;
F_13 ( V_5 -> V_35 , V_5 ) ;
F_14 ( V_5 -> V_35 , F_1 ) ;
}
void T_2 F_15 ( struct V_4 * V_1 , unsigned int V_36 )
{
for (; V_36 > 0 ; V_36 -- , V_1 ++ )
F_7 ( V_1 ) ;
}
