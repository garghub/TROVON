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
static T_1 F_16 ( struct V_28 * V_28 , const char T_2 * V_29 ,
T_3 V_30 , T_4 * V_31 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int * V_32 ;
T_1 V_33 = - V_13 ;
T_3 V_34 ;
T_5 V_35 ;
T_6 V_36 ;
unsigned int V_21 = 0 ;
int V_37 ;
V_35 = F_4 () ;
V_6 = F_17 ( V_28 ) ;
if ( ! V_6 )
return - V_38 ;
if ( V_30 < sizeof( unsigned ) || V_30 % sizeof( unsigned ) )
return - V_13 ;
V_34 = V_30 / sizeof( unsigned ) ;
if ( V_34 > V_39 || V_34 % 2 == 0 )
return - V_13 ;
V_32 = F_18 ( V_29 , V_30 ) ;
if ( F_19 ( V_32 ) )
return F_20 ( V_32 ) ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 ) {
V_33 = - V_38 ;
goto V_40;
}
if ( ! V_2 -> V_41 ) {
V_33 = - V_42 ;
goto V_40;
}
V_33 = V_2 -> V_41 ( V_2 , V_32 , V_34 ) ;
if ( V_33 < 0 )
goto V_40;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
V_21 += V_32 [ V_37 ] ;
V_33 *= sizeof( unsigned int ) ;
V_36 = F_21 ( F_22 ( V_35 , V_21 ) , F_4 () ) ;
if ( V_36 > 0 ) {
F_23 ( V_43 ) ;
F_24 ( F_25 ( V_36 ) ) ;
}
V_40:
F_26 ( V_32 ) ;
return V_33 ;
}
static long F_27 ( struct V_28 * V_44 , unsigned int V_45 ,
unsigned long V_46 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_7 T_2 * V_47 = ( T_7 T_2 * ) ( V_46 ) ;
int V_33 = 0 ;
T_8 V_48 = 0 , V_49 ;
V_6 = F_17 ( V_44 ) ;
if ( ! V_6 )
return - V_38 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_38 ;
if ( F_28 ( V_45 ) & V_50 ) {
V_33 = F_29 ( V_48 , V_47 ) ;
if ( V_33 )
return V_33 ;
}
switch ( V_45 ) {
case V_51 :
V_48 = V_52 & V_53 ;
break;
case V_54 :
if ( V_48 != ( V_55 & V_53 ) )
return - V_13 ;
return 0 ;
case V_56 :
if ( ! V_2 -> V_57 )
return - V_42 ;
return V_2 -> V_57 ( V_2 , V_48 ) ;
case V_58 :
if ( ! V_2 -> V_59 )
return - V_42 ;
return V_2 -> V_59 ( V_2 , V_48 ) ;
case V_60 :
if ( ! V_2 -> V_61 )
return - V_42 ;
if ( V_48 <= 0 || V_48 >= 100 )
return - V_13 ;
return V_2 -> V_61 ( V_2 , V_48 ) ;
case V_62 :
if ( ! V_2 -> V_63 )
return - V_42 ;
if ( V_48 <= 0 )
return - V_13 ;
return V_2 -> V_63 ( V_2 ,
V_2 -> V_7 -> V_6 . V_64 ,
V_48 ) ;
case V_65 :
if ( V_48 <= 0 )
return - V_13 ;
V_2 -> V_7 -> V_6 . V_64 = V_48 ;
return 0 ;
case V_66 :
V_48 = V_2 -> V_67 ;
break;
case V_68 :
if ( ! V_2 -> V_69 )
return - V_42 ;
return V_2 -> V_69 ( V_2 , ! ! V_48 ) ;
case V_70 :
if ( ! V_2 -> V_71 )
return - V_42 ;
return V_2 -> V_71 ( V_2 , ! ! V_48 ) ;
case V_72 :
if ( ! V_2 -> V_73 )
return - V_42 ;
V_48 = V_2 -> V_74 / 1000 ;
break;
case V_75 :
if ( ! V_2 -> V_73 )
return - V_42 ;
V_48 = V_2 -> V_73 / 1000 ;
break;
case V_76 :
if ( ! V_2 -> V_73 )
return - V_42 ;
V_49 = V_48 * 1000 ;
if ( V_49 < V_2 -> V_74 ||
V_49 > V_2 -> V_73 )
return - V_13 ;
V_2 -> V_17 = V_49 ;
break;
case V_77 :
V_6 -> V_22 = ! ! V_48 ;
break;
default:
return F_30 ( V_44 , V_45 , V_46 ) ;
}
if ( F_28 ( V_45 ) & V_78 )
V_33 = F_31 ( V_48 , V_47 ) ;
return V_33 ;
}
static int F_32 ( void * V_79 )
{
return 0 ;
}
static void F_33 ( void * V_79 )
{
return;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_80 * V_11 ;
struct V_81 * V_12 ;
int V_82 = - V_83 ;
unsigned long V_84 ;
V_11 = F_35 ( sizeof( struct V_80 ) , V_85 ) ;
if ( ! V_11 )
return V_82 ;
V_12 = F_35 ( sizeof( struct V_81 ) , V_85 ) ;
if ( ! V_12 )
goto V_86;
V_82 = F_36 ( V_12 , sizeof( int ) , V_39 ) ;
if ( V_82 )
goto V_87;
V_84 = V_88 ;
if ( V_2 -> V_41 ) {
V_84 |= V_52 ;
if ( V_2 -> V_57 )
V_84 |= V_89 ;
if ( V_2 -> V_59 )
V_84 |= V_90 ;
if ( V_2 -> V_61 )
V_84 |= V_91 ;
}
if ( V_2 -> V_63 )
V_84 |= V_92 |
V_93 ;
if ( V_2 -> V_69 )
V_84 |= V_94 ;
if ( V_2 -> V_71 )
V_84 |= V_95 ;
if ( V_2 -> V_73 )
V_84 |= V_96 ;
snprintf ( V_11 -> V_97 , sizeof( V_11 -> V_97 ) , L_4 ,
V_2 -> V_98 ) ;
V_11 -> V_99 = - 1 ;
V_11 -> V_84 = V_84 ;
V_11 -> V_79 = & V_2 -> V_7 -> V_6 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_100 = & F_32 ;
V_11 -> V_101 = & F_33 ;
V_11 -> V_102 = sizeof( struct V_3 ) * 8 ;
V_11 -> V_103 = & V_104 ;
V_11 -> V_2 = & V_2 -> V_2 ;
V_11 -> V_105 = V_106 ;
V_11 -> V_99 = F_37 ( V_11 ) ;
if ( V_11 -> V_99 < 0 ) {
V_82 = - V_107 ;
goto V_108;
}
V_2 -> V_7 -> V_6 . V_11 = V_11 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_108:
V_87:
F_26 ( V_12 ) ;
V_86:
F_26 ( V_11 ) ;
return V_82 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_39 ( V_6 -> V_11 -> V_99 ) ;
F_40 ( V_6 -> V_11 -> V_12 ) ;
F_26 ( V_6 -> V_11 ) ;
return 0 ;
}
static int T_9 F_41 ( void )
{
F_42 ( & V_109 ) ;
F_43 ( V_110 L_5 ) ;
return 0 ;
}
static void T_10 F_44 ( void )
{
F_45 ( & V_109 ) ;
}
