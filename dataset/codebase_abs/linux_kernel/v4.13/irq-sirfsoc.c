static void T_1 * F_1 ( void )
{
return ( void T_1 V_1 * ) V_2 -> V_3 ;
}
static T_2 void F_2 ( void T_1 * V_4 )
{
unsigned int V_5 = V_6 | V_7 | V_8 ;
unsigned int V_9 = V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
F_3 ( V_2 , 32 , 1 , L_1 ,
V_16 , V_5 , V_9 ,
V_17 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
V_12 = F_4 ( V_2 , V_15 * 32 ) ;
V_12 -> V_19 = V_4 + V_15 * V_20 ;
V_14 = V_12 -> V_21 ;
V_14 -> V_22 . V_23 = V_24 ;
V_14 -> V_22 . V_25 = V_26 ;
V_14 -> V_27 . V_28 = V_29 ;
}
}
static void T_3 F_5 ( struct V_30 * V_27 )
{
void T_1 * V_4 = F_1 () ;
T_4 V_31 ;
V_31 = F_6 ( V_4 + V_32 ) ;
F_7 ( V_2 , V_31 & 0xff , V_27 ) ;
}
static int T_2 F_8 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
void T_1 * V_4 = F_9 ( V_34 , 0 ) ;
if ( ! V_4 )
F_10 ( L_2 ) ;
V_2 = F_11 ( V_34 , V_36 ,
& V_37 , V_4 ) ;
F_2 ( V_4 ) ;
F_12 ( 0 , V_4 + V_38 ) ;
F_12 ( 0 , V_4 + V_39 ) ;
F_12 ( 0 , V_4 + V_29 ) ;
F_12 ( 0 , V_4 + V_40 ) ;
F_13 ( F_5 ) ;
return 0 ;
}
static int F_14 ( void )
{
void T_1 * V_4 = F_1 () ;
V_41 . V_42 = F_6 ( V_4 + V_29 ) ;
V_41 . V_43 = F_6 ( V_4 + V_40 ) ;
V_41 . V_44 = F_6 ( V_4 + V_38 ) ;
V_41 . V_45 = F_6 ( V_4 + V_39 ) ;
return 0 ;
}
static void F_15 ( void )
{
void T_1 * V_4 = F_1 () ;
F_12 ( V_41 . V_42 , V_4 + V_29 ) ;
F_12 ( V_41 . V_43 , V_4 + V_40 ) ;
F_12 ( V_41 . V_44 , V_4 + V_38 ) ;
F_12 ( V_41 . V_45 , V_4 + V_39 ) ;
}
static int T_2 F_16 ( void )
{
if ( ! V_2 )
return 0 ;
F_17 ( & V_46 ) ;
return 0 ;
}
