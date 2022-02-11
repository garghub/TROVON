static void T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 , V_3 ) ;
V_1 = F_3 ( V_2 , V_4 , L_1 ) ;
if ( V_1 < 0 ) {
F_4 ( V_5 L_2 ,
V_2 ) ;
return;
}
V_6 [ 0 ] . V_7 = F_5 ( V_2 ) ;
}
static int T_1 F_6 ( void )
{
F_7 ( 1 , 400 , NULL , 0 ) ;
F_7 ( 2 , 400 , V_8 ,
F_8 ( V_8 ) ) ;
F_7 ( 3 , 400 , V_9 ,
F_8 ( V_9 ) ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
int V_1 ;
F_2 ( V_10 , V_3 ) ;
F_2 ( V_11 , V_12 ) ;
F_2 ( V_13 , V_12 ) ;
V_1 = F_10 ( V_14 ,
F_8 ( V_14 ) ) ;
if ( V_1 ) {
F_4 ( V_15 L_3 ) ;
return;
}
F_4 ( V_16 L_4 ) ;
}
static void T_1 F_9 ( void ) {}
static int F_11 ( struct V_17 * V_18 )
{
if ( V_19 ) {
F_4 ( V_15 L_5 ) ;
return - V_20 ;
}
F_12 ( V_10 , 1 ) ;
V_21 = 1 ;
return 0 ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_12 ( V_10 , 0 ) ;
V_21 = 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
return 0 ;
}
static void F_15 ( struct V_17 * V_18 )
{
}
static int F_16 ( struct V_17 * V_18 )
{
if ( V_21 ) {
F_4 ( V_15 L_6 ) ;
return - V_20 ;
}
V_19 = 1 ;
return 0 ;
}
static void F_17 ( struct V_17 * V_18 )
{
V_19 = 0 ;
}
static T_1 void F_18 ( void )
{
T_2 V_22 ;
V_22 = F_19 ( V_23 ) ;
V_22 &= ~ ( V_24 | V_25 | V_26 ) ;
V_22 |= V_27 | V_28 | V_29
| V_30 ;
F_20 ( V_22 , V_23 ) ;
F_21 ( & V_31 ) ;
}
static void F_22 ( struct V_32 * V_33 )
{
V_34 . V_35 . V_36 = V_33 ;
F_23 ( & V_34 ) ;
}
static void T_1 F_24 ( void )
{
V_37 = V_38 ;
V_39 = F_8 ( V_38 ) ;
F_25 ( V_40 , V_41 ) ;
F_6 () ;
F_26 ( & V_42 ) ;
F_27 () ;
F_28 ( NULL , NULL ) ;
F_2 ( 57 , V_43 ) ;
F_29 ( & V_44 ) ;
F_22 ( & V_45 ) ;
F_9 () ;
F_1 () ;
F_30 ( 1 , V_6 ,
F_8 ( V_6 ) ) ;
F_31 ( V_46 , 1 ) ;
F_18 () ;
F_32 ( V_47 ) ;
}
