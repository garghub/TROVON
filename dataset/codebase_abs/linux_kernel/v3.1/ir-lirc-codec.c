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
unsigned int * V_32 ;
T_1 V_33 = 0 ;
T_2 V_34 ;
V_6 = F_17 ( V_28 ) ;
if ( ! V_6 )
return - V_35 ;
if ( V_30 < sizeof( unsigned ) || V_30 % sizeof( unsigned ) )
return - V_13 ;
V_34 = V_30 / sizeof( unsigned ) ;
if ( V_34 > V_36 || V_34 % 2 == 0 )
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
V_33 = V_2 -> V_38 ( V_2 , V_32 , V_34 ) ;
if ( V_33 > 0 )
V_33 *= sizeof( unsigned ) ;
V_37:
F_21 ( V_32 ) ;
return V_33 ;
}
static long F_22 ( struct V_28 * V_39 , unsigned int V_40 ,
unsigned long T_4 V_41 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
T_5 V_42 = 0 , V_43 ;
V_6 = F_17 ( V_39 ) ;
if ( ! V_6 )
return - V_35 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_35 ;
if ( F_23 ( V_40 ) & V_44 ) {
V_33 = F_24 ( V_42 , ( T_5 * ) V_41 ) ;
if ( V_33 )
return V_33 ;
}
switch ( V_40 ) {
case V_45 :
V_42 = V_46 & V_47 ;
break;
case V_48 :
if ( V_42 != ( V_49 & V_47 ) )
return - V_13 ;
return 0 ;
case V_50 :
if ( ! V_2 -> V_51 )
return - V_13 ;
return V_2 -> V_51 ( V_2 , V_42 ) ;
case V_52 :
if ( ! V_2 -> V_53 )
return - V_13 ;
return V_2 -> V_53 ( V_2 , V_42 ) ;
case V_54 :
if ( ! V_2 -> V_55 )
return - V_56 ;
if ( V_42 <= 0 || V_42 >= 100 )
return - V_13 ;
return V_2 -> V_55 ( V_2 , V_42 ) ;
case V_57 :
if ( ! V_2 -> V_58 )
return - V_56 ;
if ( V_42 <= 0 )
return - V_13 ;
return V_2 -> V_58 ( V_2 ,
V_2 -> V_7 -> V_6 . V_59 ,
V_42 ) ;
case V_60 :
if ( V_42 <= 0 )
return - V_13 ;
V_2 -> V_7 -> V_6 . V_59 = V_42 ;
return 0 ;
case V_61 :
V_42 = V_2 -> V_62 ;
break;
case V_63 :
if ( ! V_2 -> V_64 )
return - V_56 ;
return V_2 -> V_64 ( V_2 , ! ! V_42 ) ;
case V_65 :
if ( ! V_2 -> V_66 )
return - V_56 ;
return V_2 -> V_66 ( V_2 , ! ! V_42 ) ;
case V_67 :
if ( ! V_2 -> V_68 )
return - V_56 ;
V_42 = V_2 -> V_69 / 1000 ;
break;
case V_70 :
if ( ! V_2 -> V_68 )
return - V_56 ;
V_42 = V_2 -> V_68 / 1000 ;
break;
case V_71 :
if ( ! V_2 -> V_68 )
return - V_56 ;
V_43 = V_42 * 1000 ;
if ( V_43 < V_2 -> V_69 ||
V_43 > V_2 -> V_68 )
return - V_13 ;
V_2 -> V_17 = V_43 ;
break;
case V_72 :
V_6 -> V_22 = ! ! V_42 ;
break;
default:
return F_25 ( V_39 , V_40 , V_41 ) ;
}
if ( F_23 ( V_40 ) & V_73 )
V_33 = F_26 ( V_42 , ( T_5 * ) V_41 ) ;
return V_33 ;
}
static int F_27 ( void * V_74 )
{
return 0 ;
}
static void F_28 ( void * V_74 )
{
return;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_75 * V_11 ;
struct V_76 * V_12 ;
int V_77 = - V_78 ;
unsigned long V_79 ;
V_11 = F_30 ( sizeof( struct V_75 ) , V_80 ) ;
if ( ! V_11 )
return V_77 ;
V_12 = F_30 ( sizeof( struct V_76 ) , V_80 ) ;
if ( ! V_12 )
goto V_81;
V_77 = F_31 ( V_12 , sizeof( int ) , V_36 ) ;
if ( V_77 )
goto V_82;
V_79 = V_83 ;
if ( V_2 -> V_38 ) {
V_79 |= V_46 ;
if ( V_2 -> V_51 )
V_79 |= V_84 ;
if ( V_2 -> V_53 )
V_79 |= V_85 ;
if ( V_2 -> V_55 )
V_79 |= V_86 ;
}
if ( V_2 -> V_58 )
V_79 |= V_87 |
V_88 ;
if ( V_2 -> V_64 )
V_79 |= V_89 ;
if ( V_2 -> V_66 )
V_79 |= V_90 ;
if ( V_2 -> V_68 )
V_79 |= V_91 ;
snprintf ( V_11 -> V_92 , sizeof( V_11 -> V_92 ) , L_4 ,
V_2 -> V_93 ) ;
V_11 -> V_94 = - 1 ;
V_11 -> V_79 = V_79 ;
V_11 -> V_74 = & V_2 -> V_7 -> V_6 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_95 = & F_27 ;
V_11 -> V_96 = & F_28 ;
V_11 -> V_97 = sizeof( struct V_3 ) * 8 ;
V_11 -> V_98 = & V_99 ;
V_11 -> V_2 = & V_2 -> V_2 ;
V_11 -> V_100 = V_101 ;
V_11 -> V_94 = F_32 ( V_11 ) ;
if ( V_11 -> V_94 < 0 ) {
V_77 = - V_102 ;
goto V_103;
}
V_2 -> V_7 -> V_6 . V_11 = V_11 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_103:
V_82:
F_21 ( V_12 ) ;
V_81:
F_21 ( V_11 ) ;
return V_77 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_34 ( V_6 -> V_11 -> V_94 ) ;
F_35 ( V_6 -> V_11 -> V_12 ) ;
F_21 ( V_6 -> V_11 ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
F_37 ( & V_104 ) ;
F_38 ( V_105 L_5 ) ;
return 0 ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_104 ) ;
}
