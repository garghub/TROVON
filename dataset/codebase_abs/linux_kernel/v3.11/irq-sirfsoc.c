static T_1 void
F_1 ( void T_2 * V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
unsigned int V_9 = V_10 | V_11 | V_12 ;
V_8 = F_2 ( V_13 , V_3 , 1 , L_1 ,
V_14 , V_9 , 0 , V_15 ) ;
V_5 = F_3 ( V_13 , V_2 ) ;
V_5 -> V_16 = V_1 ;
V_7 = V_5 -> V_17 ;
V_7 -> V_18 . V_19 = V_20 ;
V_7 -> V_18 . V_21 = V_22 ;
V_7 -> V_23 . V_24 = V_25 ;
}
static T_3 void T_4 F_4 ( struct V_26 * V_23 )
{
void T_2 * V_1 = V_13 -> V_27 ;
T_5 V_28 , V_29 ;
V_28 = F_5 ( V_1 + V_30 ) ;
V_29 = F_6 ( V_13 , V_28 & 0xff ) ;
F_7 ( V_29 , V_23 ) ;
}
static int T_1 F_8 ( struct V_31 * V_32 , struct V_31 * V_33 )
{
void T_2 * V_1 = F_9 ( V_32 , 0 ) ;
if ( ! V_1 )
F_10 ( L_2 ) ;
V_13 = F_11 ( V_32 , V_34 ,
& V_35 , V_1 ) ;
F_1 ( V_1 , 0 , 32 ) ;
F_1 ( V_1 + 4 , 32 , V_34 - 32 ) ;
F_12 ( 0 , V_1 + V_36 ) ;
F_12 ( 0 , V_1 + V_37 ) ;
F_12 ( 0 , V_1 + V_25 ) ;
F_12 ( 0 , V_1 + V_38 ) ;
F_13 ( F_4 ) ;
return 0 ;
}
static int F_14 ( void )
{
void T_2 * V_1 = V_13 -> V_27 ;
V_39 . V_40 = F_5 ( V_1 + V_25 ) ;
V_39 . V_41 = F_5 ( V_1 + V_38 ) ;
V_39 . V_42 = F_5 ( V_1 + V_36 ) ;
V_39 . V_43 = F_5 ( V_1 + V_37 ) ;
return 0 ;
}
static void F_15 ( void )
{
void T_2 * V_1 = V_13 -> V_27 ;
F_12 ( V_39 . V_40 , V_1 + V_25 ) ;
F_12 ( V_39 . V_41 , V_1 + V_38 ) ;
F_12 ( V_39 . V_42 , V_1 + V_36 ) ;
F_12 ( V_39 . V_43 , V_1 + V_37 ) ;
}
static int T_1 F_16 ( void )
{
if ( ! V_13 )
return 0 ;
F_17 ( & V_44 ) ;
return 0 ;
}
