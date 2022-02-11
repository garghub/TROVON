static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
if ( ! V_2 -> V_7 -> V_6 . V_9 || ! V_2 -> V_7 -> V_6 . V_9 -> V_10 )
return - V_11 ;
if ( V_4 . V_12 ) {
V_8 = F_2 ( V_13 ) ;
F_3 ( 2 , L_1 ) ;
} else if ( V_4 . V_14 ) {
V_8 = F_4 ( V_4 . V_15 ) ;
F_3 ( 2 , L_2 , V_8 ) ;
} else if ( V_4 . V_16 ) {
if ( V_6 -> V_17 )
return 0 ;
V_6 -> V_18 = F_5 () ;
V_6 -> V_17 = true ;
V_6 -> V_19 = V_4 . V_20 ;
if ( ! V_6 -> V_21 )
return 0 ;
V_8 = F_6 ( V_4 . V_20 / 1000 ) ;
F_3 ( 2 , L_3 , V_8 ) ;
} else {
if ( V_6 -> V_17 ) {
int V_22 ;
V_6 -> V_19 += F_7 ( F_8 ( F_5 () ,
V_6 -> V_18 ) ) ;
F_9 ( V_6 -> V_19 , 1000 ) ;
V_6 -> V_19 = F_10 ( V_6 -> V_19 ,
( V_23 ) V_13 ) ;
V_22 = F_2 ( V_6 -> V_19 ) ;
F_11 ( V_2 -> V_7 -> V_6 . V_9 -> V_10 ,
( unsigned char * ) & V_22 ) ;
V_6 -> V_17 = false ;
}
V_8 = V_4 . V_24 ? F_12 ( V_4 . V_20 / 1000 ) :
F_2 ( V_4 . V_20 / 1000 ) ;
F_3 ( 2 , L_4 ,
F_13 ( V_4 . V_20 ) , F_14 ( V_4 . V_24 ) ) ;
}
F_11 ( V_2 -> V_7 -> V_6 . V_9 -> V_10 ,
( unsigned char * ) & V_8 ) ;
F_15 ( & V_2 -> V_7 -> V_6 . V_9 -> V_10 -> V_25 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_26 * V_26 , const char T_2 * V_27 ,
T_3 V_28 , T_4 * V_29 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int * V_30 ;
T_1 V_31 = - V_11 ;
T_3 V_32 ;
T_5 V_33 ;
T_6 V_34 ;
unsigned int V_20 = 0 ;
int V_35 ;
V_33 = F_5 () ;
V_6 = F_17 ( V_26 ) ;
if ( ! V_6 )
return - V_36 ;
if ( V_28 < sizeof( unsigned ) || V_28 % sizeof( unsigned ) )
return - V_11 ;
V_32 = V_28 / sizeof( unsigned ) ;
if ( V_32 > V_37 || V_32 % 2 == 0 )
return - V_11 ;
V_30 = F_18 ( V_27 , V_28 ) ;
if ( F_19 ( V_30 ) )
return F_20 ( V_30 ) ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 ) {
V_31 = - V_36 ;
goto V_38;
}
if ( ! V_2 -> V_39 ) {
V_31 = - V_11 ;
goto V_38;
}
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
if ( V_30 [ V_35 ] > V_40 / 1000 - V_20 || ! V_30 [ V_35 ] ) {
V_31 = - V_11 ;
goto V_38;
}
V_20 += V_30 [ V_35 ] ;
}
V_31 = V_2 -> V_39 ( V_2 , V_30 , V_32 ) ;
if ( V_31 < 0 )
goto V_38;
for ( V_20 = V_35 = 0 ; V_35 < V_31 ; V_35 ++ )
V_20 += V_30 [ V_35 ] ;
V_31 *= sizeof( unsigned int ) ;
V_34 = F_21 ( F_22 ( V_33 , V_20 ) , F_5 () ) ;
if ( V_34 > 0 ) {
F_23 ( V_41 ) ;
F_24 ( F_25 ( V_34 ) ) ;
}
V_38:
F_26 ( V_30 ) ;
return V_31 ;
}
static long F_27 ( struct V_26 * V_42 , unsigned int V_43 ,
unsigned long V_44 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_7 T_2 * V_45 = ( T_7 T_2 * ) ( V_44 ) ;
int V_31 = 0 ;
T_8 V_46 = 0 , V_47 ;
V_6 = F_17 ( V_42 ) ;
if ( ! V_6 )
return - V_36 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_36 ;
if ( F_28 ( V_43 ) & V_48 ) {
V_31 = F_29 ( V_46 , V_45 ) ;
if ( V_31 )
return V_31 ;
}
switch ( V_43 ) {
case V_49 :
if ( ! V_2 -> V_39 )
return - V_50 ;
V_46 = V_51 ;
break;
case V_52 :
if ( ! V_2 -> V_39 )
return - V_50 ;
if ( V_46 != V_51 )
return - V_11 ;
return 0 ;
case V_53 :
if ( ! V_2 -> V_54 )
return - V_50 ;
return V_2 -> V_54 ( V_2 , V_46 ) ;
case V_55 :
if ( ! V_2 -> V_56 )
return - V_50 ;
return V_2 -> V_56 ( V_2 , V_46 ) ;
case V_57 :
if ( ! V_2 -> V_58 )
return - V_50 ;
if ( V_46 <= 0 || V_46 >= 100 )
return - V_11 ;
return V_2 -> V_58 ( V_2 , V_46 ) ;
case V_59 :
if ( ! V_2 -> V_60 )
return - V_50 ;
if ( V_46 <= 0 )
return - V_11 ;
return V_2 -> V_60 ( V_2 ,
V_2 -> V_7 -> V_6 . V_61 ,
V_46 ) ;
case V_62 :
if ( ! V_2 -> V_60 )
return - V_50 ;
if ( V_46 <= 0 )
return - V_11 ;
V_2 -> V_7 -> V_6 . V_61 = V_46 ;
return 0 ;
case V_63 :
if ( ! V_2 -> V_64 )
return - V_50 ;
V_46 = V_2 -> V_64 ;
break;
case V_65 :
if ( ! V_2 -> V_66 )
return - V_50 ;
return V_2 -> V_66 ( V_2 , ! ! V_46 ) ;
case V_67 :
if ( ! V_2 -> V_68 )
return - V_50 ;
return V_2 -> V_68 ( V_2 , ! ! V_46 ) ;
case V_69 :
if ( ! V_2 -> V_70 )
return - V_50 ;
V_46 = F_30 ( V_2 -> V_71 , 1000 ) ;
break;
case V_72 :
if ( ! V_2 -> V_70 )
return - V_50 ;
V_46 = V_2 -> V_70 / 1000 ;
break;
case V_73 :
if ( ! V_2 -> V_70 )
return - V_50 ;
V_47 = V_46 * 1000 ;
if ( V_47 < V_2 -> V_71 ||
V_47 > V_2 -> V_70 )
return - V_11 ;
if ( V_2 -> V_74 )
V_31 = V_2 -> V_74 ( V_2 , V_47 ) ;
if ( ! V_31 )
V_2 -> V_16 = V_47 ;
break;
case V_75 :
if ( ! V_2 -> V_16 )
return - V_50 ;
V_6 -> V_21 = ! ! V_46 ;
break;
default:
return F_31 ( V_42 , V_43 , V_44 ) ;
}
if ( F_28 ( V_43 ) & V_76 )
V_31 = F_32 ( V_46 , V_45 ) ;
return V_31 ;
}
static int F_33 ( void * V_77 )
{
return 0 ;
}
static void F_34 ( void * V_77 )
{
return;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_78 * V_9 ;
struct V_79 * V_10 ;
int V_80 = - V_81 ;
unsigned long V_82 = 0 ;
V_9 = F_36 ( sizeof( struct V_78 ) , V_83 ) ;
if ( ! V_9 )
return V_80 ;
V_10 = F_36 ( sizeof( struct V_79 ) , V_83 ) ;
if ( ! V_10 )
goto V_84;
V_80 = F_37 ( V_10 , sizeof( int ) , V_37 ) ;
if ( V_80 )
goto V_85;
if ( V_2 -> V_86 != V_87 ) {
V_82 |= V_88 ;
if ( V_2 -> V_64 )
V_82 |= V_89 ;
}
if ( V_2 -> V_39 ) {
V_82 |= V_90 ;
if ( V_2 -> V_54 )
V_82 |= V_91 ;
if ( V_2 -> V_56 )
V_82 |= V_92 ;
if ( V_2 -> V_58 )
V_82 |= V_93 ;
}
if ( V_2 -> V_60 )
V_82 |= V_94 |
V_95 ;
if ( V_2 -> V_66 )
V_82 |= V_96 ;
if ( V_2 -> V_68 )
V_82 |= V_97 ;
if ( V_2 -> V_70 )
V_82 |= V_98 ;
snprintf ( V_9 -> V_99 , sizeof( V_9 -> V_99 ) , L_5 ,
V_2 -> V_100 ) ;
V_9 -> V_101 = - 1 ;
V_9 -> V_82 = V_82 ;
V_9 -> V_77 = & V_2 -> V_7 -> V_6 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_102 = & F_33 ;
V_9 -> V_103 = & F_34 ;
V_9 -> V_104 = sizeof( struct V_3 ) * 8 ;
V_9 -> V_105 = & V_106 ;
V_9 -> V_2 = & V_2 -> V_2 ;
V_9 -> V_107 = V_2 ;
V_9 -> V_108 = V_109 ;
V_9 -> V_101 = F_38 ( V_9 ) ;
if ( V_9 -> V_101 < 0 ) {
V_80 = - V_110 ;
goto V_111;
}
V_2 -> V_7 -> V_6 . V_9 = V_9 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_111:
V_85:
F_26 ( V_10 ) ;
V_84:
F_26 ( V_9 ) ;
return V_80 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_40 ( V_6 -> V_9 -> V_101 ) ;
F_41 ( V_6 -> V_9 -> V_10 ) ;
F_26 ( V_6 -> V_9 -> V_10 ) ;
F_26 ( V_6 -> V_9 ) ;
return 0 ;
}
static int T_9 F_42 ( void )
{
F_43 ( & V_112 ) ;
F_44 ( V_113 L_6 ) ;
return 0 ;
}
static void T_10 F_45 ( void )
{
F_46 ( & V_112 ) ;
}
