static T_1 void
F_1 ( void T_2 * V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( L_1 , 1 , V_2 , V_1 , V_8 ) ;
V_7 = V_5 -> V_9 ;
V_7 -> V_10 . V_11 = V_12 ;
V_7 -> V_10 . V_13 = V_14 ;
V_7 -> V_15 . V_16 = V_17 ;
F_3 ( V_5 , F_4 ( V_3 ) , V_18 , V_19 , 0 ) ;
}
static T_3 void T_4 F_5 ( struct V_20 * V_15 )
{
void T_2 * V_1 = V_21 -> V_22 ;
T_5 V_23 , V_24 ;
V_23 = F_6 ( V_1 + V_25 ) ;
V_24 = F_7 ( V_21 , V_23 & 0xff ) ;
F_8 ( V_24 , V_15 ) ;
}
static int T_1 F_9 ( struct V_26 * V_27 , struct V_26 * V_28 )
{
void T_2 * V_1 = F_10 ( V_27 , 0 ) ;
if ( ! V_1 )
F_11 ( L_2 ) ;
V_21 = F_12 ( V_27 , V_29 , 0 , 0 ,
& V_30 , V_1 ) ;
F_1 ( V_1 , 0 , 32 ) ;
F_1 ( V_1 + 4 , 32 , V_29 - 32 ) ;
F_13 ( 0 , V_1 + V_31 ) ;
F_13 ( 0 , V_1 + V_32 ) ;
F_13 ( 0 , V_1 + V_17 ) ;
F_13 ( 0 , V_1 + V_33 ) ;
F_14 ( F_5 ) ;
return 0 ;
}
static int F_15 ( void )
{
void T_2 * V_1 = V_21 -> V_22 ;
V_34 . V_35 = F_6 ( V_1 + V_17 ) ;
V_34 . V_36 = F_6 ( V_1 + V_33 ) ;
V_34 . V_37 = F_6 ( V_1 + V_31 ) ;
V_34 . V_38 = F_6 ( V_1 + V_32 ) ;
return 0 ;
}
static void F_16 ( void )
{
void T_2 * V_1 = V_21 -> V_22 ;
F_13 ( V_34 . V_35 , V_1 + V_17 ) ;
F_13 ( V_34 . V_36 , V_1 + V_33 ) ;
F_13 ( V_34 . V_37 , V_1 + V_31 ) ;
F_13 ( V_34 . V_38 , V_1 + V_32 ) ;
}
static int T_1 F_17 ( void )
{
if ( ! V_21 )
return 0 ;
F_18 ( & V_39 ) ;
return 0 ;
}
