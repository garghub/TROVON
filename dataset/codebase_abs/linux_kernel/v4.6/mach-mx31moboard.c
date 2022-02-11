static void T_1 F_1 ( void )
{
if ( ! F_2 ( F_3 ( V_1 ) , L_1 ) ) {
F_4 ( F_3 ( V_1 ) , 0 ) ;
F_5 ( F_3 ( V_1 ) ) ;
}
}
static int F_6 ( struct V_2 * V_3 )
{
return ! F_7 ( V_4 ) ;
}
static int F_8 ( struct V_2 * V_3 , T_2 V_5 ,
void * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_8 , L_2 ) ;
if ( V_7 )
return V_7 ;
F_9 ( V_8 ) ;
V_7 = F_2 ( V_4 , L_3 ) ;
if ( V_7 )
goto V_9;
F_9 ( V_4 ) ;
V_7 = F_10 ( F_11 ( V_8 ) , V_5 ,
V_10 | V_11 ,
L_4 , V_6 ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_5 ( V_4 ) ;
V_9:
F_5 ( V_8 ) ;
return V_7 ;
}
static void F_12 ( struct V_2 * V_3 , void * V_6 )
{
F_13 ( F_11 ( V_8 ) , V_6 ) ;
F_5 ( V_4 ) ;
F_5 ( V_8 ) ;
}
static void F_14 ( void )
{
F_15 ( V_13 , V_14 | V_15 ) ;
F_15 ( V_16 , V_14 | V_15 ) ;
F_15 ( V_17 , V_14 | V_15 ) ;
F_15 ( V_18 , V_14 | V_15 ) ;
F_15 ( V_19 , V_14 | V_15 ) ;
F_15 ( V_20 , V_14 | V_15 ) ;
F_15 ( V_21 , V_14 | V_15 ) ;
F_15 ( V_22 , V_14 | V_15 ) ;
F_15 ( V_23 , V_14 | V_24 ) ;
F_15 ( V_25 , V_14 | V_24 ) ;
F_15 ( V_26 , V_14 | V_24 ) ;
F_15 ( V_27 , V_14 | V_24 ) ;
F_16 ( V_28 , true ) ;
F_15 ( V_29 , V_14 | V_24 ) ;
F_15 ( V_30 , V_14 | V_24 ) ;
F_15 ( V_31 , V_14 | V_24 ) ;
F_15 ( V_32 , V_14 | V_24 ) ;
F_15 ( V_33 , V_14 | V_15 ) ;
F_15 ( V_34 , V_14 | V_15 ) ;
F_15 ( V_35 , V_14 | V_15 ) ;
F_15 ( V_36 , V_14 | V_15 ) ;
F_15 ( V_37 , V_14 | V_15 ) ;
F_15 ( V_38 , V_14 | V_15 ) ;
F_15 ( V_39 , V_14 | V_15 ) ;
F_15 ( V_40 , V_14 | V_15 ) ;
F_2 ( V_41 , L_5 ) ;
F_4 ( V_41 , 0 ) ;
F_2 ( V_42 , L_6 ) ;
F_4 ( V_42 , 0 ) ;
F_2 ( V_43 , L_7 ) ;
F_4 ( V_43 , 0 ) ;
F_17 ( 1 ) ;
F_18 ( V_43 , 1 ) ;
F_17 ( 1 ) ;
}
static int F_19 ( struct V_44 * V_45 )
{
return F_20 ( V_45 -> V_46 , V_47 ) ;
}
static int T_1 F_21 ( void )
{
struct V_44 * V_45 ;
V_48 . V_49 = F_22 ( V_50 |
V_51 ) ;
if ( ! V_48 . V_49 )
return - V_52 ;
V_45 = F_23 ( 2 , & V_48 ) ;
return F_24 ( V_45 ) ;
}
static int T_1 F_25 ( void )
{
int V_53 , V_7 = - V_54 ;
struct V_44 * V_45 ;
F_26 () ;
V_45 = F_27 ( & V_55 ) ;
if ( F_28 ( V_45 ) )
return F_29 ( V_45 ) ;
V_53 = F_30 ( & V_45 -> V_3 ,
V_56 , V_56 ,
V_57 ,
V_58 | V_59 ) ;
if ( ! ( V_53 & V_58 ) )
goto V_60;
V_7 = F_31 ( V_45 ) ;
if ( V_7 )
V_60:
F_32 ( V_45 ) ;
return V_7 ;
}
static void F_33 ( void )
{
struct V_61 * V_61 = F_34 ( L_8 , NULL ) ;
if ( ! F_28 ( V_61 ) )
F_35 ( V_61 ) ;
F_36 ( V_62 ) ;
F_37 ( 1 << 6 | 1 << 2 , F_38 ( V_63 ) ) ;
}
static void T_1 F_39 ( void )
{
F_40 () ;
F_41 ( V_64 , F_42 ( V_64 ) ,
L_9 ) ;
F_43 ( V_65 , F_42 ( V_65 ) ) ;
F_44 ( - 1 , & V_66 ) ;
F_45 () ;
F_1 () ;
F_46 ( & V_67 ) ;
F_47 ( & V_68 ) ;
F_48 ( & V_69 ) ;
F_49 ( & V_70 ) ;
F_50 ( & V_71 ) ;
F_51 ( & V_72 ) ;
F_2 ( F_3 ( V_73 ) , L_10 ) ;
F_9 ( F_3 ( V_73 ) ) ;
V_74 [ 0 ] . V_75 =
F_11 ( F_3 ( V_73 ) ) ;
F_52 ( V_74 ,
F_42 ( V_74 ) ) ;
F_53 ( 0 , & V_76 ) ;
F_25 () ;
F_14 () ;
F_21 () ;
F_54 ( 0 , & V_77 ) ;
F_55 ( L_11 , 0 , NULL , 0 , NULL , 0 ) ;
V_78 = F_33 ;
switch ( V_79 ) {
case V_80 :
break;
case V_81 :
F_56 () ;
break;
case V_82 :
F_57 () ;
break;
case V_83 :
case V_84 :
F_58 ( V_79 ) ;
break;
default:
F_59 ( V_85 L_12 ,
V_79 ) ;
}
}
static void T_1 F_60 ( void )
{
F_61 ( 26000000 ) ;
}
static void T_1 F_62 ( void )
{
V_56 = F_63 ( V_57 ,
V_57 ) ;
}
