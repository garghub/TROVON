static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 = ( V_1 | V_3 |
V_4 |
V_5 |
V_6 ) ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_2 ) ;
}
static void F_4 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 = ( V_1 | V_3 |
V_4 ) ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_2 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
unsigned int V_1 ;
V_8 -> V_9 = V_10 ;
V_8 -> V_11 = V_12 ;
V_8 -> V_13 = V_14 ;
V_8 -> V_15 = V_16 ;
V_8 -> V_17 = V_18 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = F_1 ;
V_8 -> V_22 = F_4 ;
V_23 . V_24 . V_25 = V_8 ;
F_6 ( & V_23 ) ;
F_6 ( & V_26 ) ;
F_7 ( NULL , F_8 ( & V_26 . V_24 ) ,
NULL , & V_23 . V_24 ) ;
V_1 = F_2 ( V_27 ) ;
V_1 = V_1 & ( ~ ( V_28 ) ) ;
F_3 ( V_1 , V_27 ) ;
V_1 = F_2 ( V_27 ) ;
return ;
}
static void T_2 F_9 ( void )
{
int V_29 ;
F_10 ( V_30 , V_31 ) ;
V_29 = F_11 ( V_30 , V_32 , L_1 ) ;
if ( V_29 < 0 ) {
F_12 ( V_33 L_2 ,
V_30 ) ;
return;
}
V_34 [ 0 ] . V_35 = F_13 ( V_30 ) ;
}
static int T_2 F_14 ( void )
{
F_15 ( 1 , 400 , NULL , 0 ) ;
F_15 ( 2 , 400 , V_36 ,
F_16 ( V_36 ) ) ;
F_15 ( 3 , 400 , V_37 ,
F_16 ( V_37 ) ) ;
return 0 ;
}
static void T_2 F_17 ( void )
{
int V_29 ;
F_10 ( V_38 , V_31 ) ;
F_10 ( V_39 , V_40 ) ;
F_10 ( V_41 , V_40 ) ;
V_29 = F_18 ( V_42 ,
F_16 ( V_42 ) ) ;
if ( V_29 ) {
F_12 ( V_43 L_3 ) ;
return;
}
F_12 ( V_44 L_4 ) ;
}
static void T_2 F_17 ( void ) {}
static int F_19 ( struct V_45 * V_46 )
{
if ( V_47 ) {
F_12 ( V_43 L_5 ) ;
return - V_48 ;
}
F_20 ( V_38 , 1 ) ;
V_49 = 1 ;
return 0 ;
}
static void F_21 ( struct V_45 * V_46 )
{
F_20 ( V_38 , 0 ) ;
V_49 = 0 ;
}
static int F_22 ( struct V_45 * V_46 )
{
return 0 ;
}
static void F_23 ( struct V_45 * V_46 )
{
}
static int F_24 ( struct V_45 * V_46 )
{
if ( V_49 ) {
F_12 ( V_43 L_6 ) ;
return - V_48 ;
}
V_47 = 1 ;
return 0 ;
}
static void F_25 ( struct V_45 * V_46 )
{
V_47 = 0 ;
}
static void T_2 F_26 ( void )
{
F_27 () ;
F_28 ( NULL , NULL ) ;
}
static T_2 void F_29 ( void )
{
T_1 V_50 ;
V_50 = F_2 ( V_51 ) ;
V_50 &= ~ ( V_52 | V_53 | V_54 ) ;
V_50 |= V_55 | V_56 | V_57
| V_58 ;
F_3 ( V_50 , V_51 ) ;
F_30 ( & V_59 ) ;
}
static void F_31 ( struct V_60 * V_8 )
{
V_61 . V_24 . V_25 = V_8 ;
F_6 ( & V_61 ) ;
}
static void T_2 F_32 ( void )
{
V_62 = V_63 ;
V_64 = F_16 ( V_63 ) ;
F_33 ( V_65 , V_66 ) ;
F_14 () ;
F_34 ( & V_67 ) ;
F_35 () ;
F_10 ( 57 , V_68 ) ;
F_36 ( & V_69 ) ;
F_31 ( & V_70 ) ;
F_17 () ;
F_9 () ;
F_37 ( 1 , V_34 ,
F_16 ( V_34 ) ) ;
F_5 ( & V_71 ) ;
F_29 () ;
}
