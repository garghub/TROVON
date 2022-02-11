void F_1 ( int V_1 , int V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = 0 ;
T_1 V_6 = 1 << V_5 ;
for (; V_5 < V_2 ; V_5 ++ , V_6 = V_6 << 1 ) {
if ( ! ( V_3 & V_6 ) )
continue;
else
F_2 ( V_1 + V_5 , ( V_4 & V_6 ) != 0 ) ;
}
}
static int F_3 ( struct V_7 * V_8 , int V_9 )
{
if ( V_9 )
F_4 ( V_10 , V_11 ) ;
else
F_4 ( V_10 , V_12 ) ;
return 0 ;
}
static void T_2 F_5 ( void )
{
F_6 ( V_13 ) ;
F_6 ( V_14 ) ;
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
F_6 ( V_23 ) ;
F_6 ( V_24 ) ;
F_6 ( V_25 ) ;
F_6 ( V_26 ) ;
F_7 () ;
F_8 ( 1 , 100 , NULL , 0 ) ;
F_9 ( & V_27 ) ;
F_10 ( & V_28 ) ;
#ifdef F_11
F_12 ( L_1 ,
& V_10 ) ;
#endif
F_13 ( - 1 , & V_29 ) ;
F_14 ( V_30 , F_15 ( V_30 ) ) ;
F_16 () ;
F_17 ( F_18 ( V_31 ) | 0x0004 , V_31 ) ;
F_19 ( & V_32 ) ;
}
static void F_20 ( struct V_33 * V_34 , unsigned int V_35 , unsigned V_36 )
{
struct V_37 * V_38 = V_34 -> V_39 ;
int V_40 ;
if ( F_21 ( V_38 -> V_41 ) )
return;
if ( V_35 == V_36 )
return;
if ( V_35 == 0 )
V_40 = F_22 ( V_38 -> V_41 ) ;
else if ( V_36 == 0 )
V_40 = F_23 ( V_38 -> V_41 ) ;
else
V_40 = 0 ;
if ( V_40 )
F_24 ( V_34 -> V_8 ,
L_2 ,
V_35 ? L_3 : L_4 , V_40 ) ;
}
static int T_2 F_25 ( void )
{
int V_42 ;
if ( ! F_26 () )
return - V_43 ;
V_42 = F_27 ( V_44 , F_15 ( V_44 ) ) ;
if ( V_42 ) {
F_28 ( L_5 ) ;
return V_42 ;
}
F_14 ( V_45 , F_15 ( V_45 ) ) ;
V_42 = F_29 ( & V_46 ) ;
if ( V_42 ) {
F_28 ( L_6 ) ;
return V_42 ;
}
F_6 ( V_47 ) ;
V_48 [ 0 ] . V_49 =
F_30 ( V_50 ) ;
V_42 = F_31 ( V_50 , L_7 ) ;
if ( V_42 ) {
F_28 ( L_8 ) ;
return V_42 ;
}
F_32 ( V_50 ) ;
V_51 . V_41 = F_33 ( - V_43 ) ;
F_34 ( V_52 ,
V_52 ) ;
V_42 = F_29 ( & V_53 ) ;
if ( V_42 )
goto V_54;
V_51 . V_41 = F_35 ( & V_53 . V_8 ,
L_9 ) ;
if ( F_21 ( V_51 . V_41 ) ) {
V_42 = F_36 ( V_51 . V_41 ) ;
goto V_55;
}
return 0 ;
V_55:
F_37 ( & V_53 ) ;
V_54:
V_54 ( V_50 ) ;
return V_42 ;
}
static void T_2 F_38 ( void )
{
F_39 () ;
F_25 () ;
}
static void T_2 F_40 ( void )
{
F_41 () ;
F_42 ( V_56 , F_15 ( V_56 ) ) ;
}
