static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
if ( ! ( V_2 -> V_7 -> V_9 & V_10 ) )
return 0 ;
if ( ! V_2 -> V_7 -> V_6 . V_11 || ! V_2 -> V_7 -> V_6 . V_11 -> V_12 )
return - V_13 ;
if ( V_4 . V_14 )
return 0 ;
if ( V_4 . V_15 ) {
V_8 = F_2 ( V_4 . V_16 ) ;
F_3 ( 2 , L_1 , V_8 ) ;
} else if ( V_4 . V_17 ) {
if ( V_6 -> V_18 )
return 0 ;
V_6 -> V_19 = F_4 () ;
V_6 -> V_18 = true ;
V_6 -> V_20 = V_4 . V_21 ;
if ( ! V_6 -> V_22 )
return 0 ;
V_8 = F_5 ( V_4 . V_21 / 1000 ) ;
F_3 ( 2 , L_2 , V_8 ) ;
} else {
if ( V_6 -> V_18 ) {
int V_23 ;
V_6 -> V_20 += F_6 ( F_7 ( F_4 () ,
V_6 -> V_19 ) ) ;
F_8 ( V_6 -> V_20 , 1000 ) ;
V_6 -> V_20 = F_9 ( V_6 -> V_20 ,
( V_24 ) V_25 ) ;
V_23 = F_10 ( V_6 -> V_20 ) ;
F_11 ( V_2 -> V_7 -> V_6 . V_11 -> V_12 ,
( unsigned char * ) & V_23 ) ;
V_6 -> V_18 = false ;
}
V_8 = V_4 . V_26 ? F_12 ( V_4 . V_21 / 1000 ) :
F_10 ( V_4 . V_21 / 1000 ) ;
F_3 ( 2 , L_3 ,
F_13 ( V_4 . V_21 ) , F_14 ( V_4 . V_26 ) ) ;
}
F_11 ( V_2 -> V_7 -> V_6 . V_11 -> V_12 ,
( unsigned char * ) & V_8 ) ;
F_15 ( & V_2 -> V_7 -> V_6 . V_11 -> V_12 -> V_27 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_28 * V_28 , const char * V_29 ,
T_2 V_30 , T_3 * V_31 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int * V_32 ;
int V_33 = 0 ;
T_2 V_34 ;
V_6 = F_17 ( V_28 ) ;
if ( ! V_6 )
return - V_35 ;
if ( V_30 % sizeof( int ) )
return - V_13 ;
V_34 = V_30 / sizeof( int ) ;
if ( V_34 > V_36 || V_34 % 2 == 0 || V_30 % sizeof( int ) != 0 )
return - V_13 ;
V_32 = F_18 ( V_29 , V_30 ) ;
if ( F_19 ( V_32 ) )
return F_20 ( V_32 ) ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 ) {
V_33 = - V_35 ;
goto V_37;
}
if ( V_2 -> V_38 )
V_33 = V_2 -> V_38 ( V_2 , V_32 , ( V_39 ) V_30 ) ;
V_37:
F_21 ( V_32 ) ;
return V_33 ;
}
static long F_22 ( struct V_28 * V_40 , unsigned int V_41 ,
unsigned long T_4 V_42 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
T_5 V_43 = 0 , V_44 ;
V_6 = F_17 ( V_40 ) ;
if ( ! V_6 )
return - V_35 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_35 ;
if ( F_23 ( V_41 ) & V_45 ) {
V_33 = F_24 ( V_43 , ( T_5 * ) V_42 ) ;
if ( V_33 )
return V_33 ;
}
switch ( V_41 ) {
case V_46 :
V_43 = V_47 & V_48 ;
break;
case V_49 :
if ( V_43 != ( V_50 & V_48 ) )
return - V_13 ;
return 0 ;
case V_51 :
if ( ! V_2 -> V_52 )
return - V_13 ;
return V_2 -> V_52 ( V_2 , V_43 ) ;
case V_53 :
if ( ! V_2 -> V_54 )
return - V_13 ;
return V_2 -> V_54 ( V_2 , V_43 ) ;
case V_55 :
if ( ! V_2 -> V_56 )
return - V_57 ;
if ( V_43 <= 0 || V_43 >= 100 )
return - V_13 ;
return V_2 -> V_56 ( V_2 , V_43 ) ;
case V_58 :
if ( ! V_2 -> V_59 )
return - V_57 ;
if ( V_43 <= 0 )
return - V_13 ;
return V_2 -> V_59 ( V_2 ,
V_2 -> V_7 -> V_6 . V_60 ,
V_43 ) ;
case V_61 :
if ( V_43 <= 0 )
return - V_13 ;
V_2 -> V_7 -> V_6 . V_60 = V_43 ;
return 0 ;
case V_62 :
V_43 = V_2 -> V_63 ;
break;
case V_64 :
if ( ! V_2 -> V_65 )
return - V_57 ;
return V_2 -> V_65 ( V_2 , ! ! V_43 ) ;
case V_66 :
if ( ! V_2 -> V_67 )
return - V_57 ;
return V_2 -> V_67 ( V_2 , ! ! V_43 ) ;
case V_68 :
if ( ! V_2 -> V_69 )
return - V_57 ;
V_43 = V_2 -> V_70 / 1000 ;
break;
case V_71 :
if ( ! V_2 -> V_69 )
return - V_57 ;
V_43 = V_2 -> V_69 / 1000 ;
break;
case V_72 :
if ( ! V_2 -> V_69 )
return - V_57 ;
V_44 = V_43 * 1000 ;
if ( V_44 < V_2 -> V_70 ||
V_44 > V_2 -> V_69 )
return - V_13 ;
V_2 -> V_17 = V_44 ;
break;
case V_73 :
V_6 -> V_22 = ! ! V_43 ;
break;
default:
return F_25 ( V_40 , V_41 , V_42 ) ;
}
if ( F_23 ( V_41 ) & V_74 )
V_33 = F_26 ( V_43 , ( T_5 * ) V_42 ) ;
return V_33 ;
}
static int F_27 ( void * V_75 )
{
return 0 ;
}
static void F_28 ( void * V_75 )
{
return;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_76 * V_11 ;
struct V_77 * V_12 ;
int V_78 = - V_79 ;
unsigned long V_80 ;
V_11 = F_30 ( sizeof( struct V_76 ) , V_81 ) ;
if ( ! V_11 )
return V_78 ;
V_12 = F_30 ( sizeof( struct V_77 ) , V_81 ) ;
if ( ! V_12 )
goto V_82;
V_78 = F_31 ( V_12 , sizeof( int ) , V_36 ) ;
if ( V_78 )
goto V_83;
V_80 = V_84 ;
if ( V_2 -> V_38 ) {
V_80 |= V_47 ;
if ( V_2 -> V_52 )
V_80 |= V_85 ;
if ( V_2 -> V_54 )
V_80 |= V_86 ;
if ( V_2 -> V_56 )
V_80 |= V_87 ;
}
if ( V_2 -> V_59 )
V_80 |= V_88 |
V_89 ;
if ( V_2 -> V_65 )
V_80 |= V_90 ;
if ( V_2 -> V_67 )
V_80 |= V_91 ;
if ( V_2 -> V_69 )
V_80 |= V_92 ;
snprintf ( V_11 -> V_93 , sizeof( V_11 -> V_93 ) , L_4 ,
V_2 -> V_94 ) ;
V_11 -> V_95 = - 1 ;
V_11 -> V_80 = V_80 ;
V_11 -> V_75 = & V_2 -> V_7 -> V_6 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_96 = & F_27 ;
V_11 -> V_97 = & F_28 ;
V_11 -> V_98 = sizeof( struct V_3 ) * 8 ;
V_11 -> V_99 = & V_100 ;
V_11 -> V_2 = & V_2 -> V_2 ;
V_11 -> V_101 = V_102 ;
V_11 -> V_95 = F_32 ( V_11 ) ;
if ( V_11 -> V_95 < 0 ) {
V_78 = - V_103 ;
goto V_104;
}
V_2 -> V_7 -> V_6 . V_11 = V_11 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_104:
V_83:
F_21 ( V_12 ) ;
V_82:
F_21 ( V_11 ) ;
return V_78 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_34 ( V_6 -> V_11 -> V_95 ) ;
F_35 ( V_6 -> V_11 -> V_12 ) ;
F_21 ( V_6 -> V_11 ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
F_37 ( & V_105 ) ;
F_38 ( V_106 L_5 ) ;
return 0 ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_105 ) ;
}
