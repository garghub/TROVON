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
V_31 = - V_40 ;
goto V_38;
}
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
if ( V_30 [ V_35 ] > V_41 / 1000 - V_20 || ! V_30 [ V_35 ] ) {
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
F_23 ( V_42 ) ;
F_24 ( F_25 ( V_34 ) ) ;
}
V_38:
F_26 ( V_30 ) ;
return V_31 ;
}
static long F_27 ( struct V_26 * V_43 , unsigned int V_44 ,
unsigned long V_45 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_7 T_2 * V_46 = ( T_7 T_2 * ) ( V_45 ) ;
int V_31 = 0 ;
T_8 V_47 = 0 , V_48 ;
V_6 = F_17 ( V_43 ) ;
if ( ! V_6 )
return - V_36 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_36 ;
if ( F_28 ( V_44 ) & V_49 ) {
V_31 = F_29 ( V_47 , V_46 ) ;
if ( V_31 )
return V_31 ;
}
switch ( V_44 ) {
case V_50 :
V_47 = V_51 & V_52 ;
break;
case V_53 :
if ( V_47 != ( V_54 & V_52 ) )
return - V_11 ;
return 0 ;
case V_55 :
if ( ! V_2 -> V_56 )
return - V_40 ;
return V_2 -> V_56 ( V_2 , V_47 ) ;
case V_57 :
if ( ! V_2 -> V_58 )
return - V_40 ;
return V_2 -> V_58 ( V_2 , V_47 ) ;
case V_59 :
if ( ! V_2 -> V_60 )
return - V_40 ;
if ( V_47 <= 0 || V_47 >= 100 )
return - V_11 ;
return V_2 -> V_60 ( V_2 , V_47 ) ;
case V_61 :
if ( ! V_2 -> V_62 )
return - V_40 ;
if ( V_47 <= 0 )
return - V_11 ;
return V_2 -> V_62 ( V_2 ,
V_2 -> V_7 -> V_6 . V_63 ,
V_47 ) ;
case V_64 :
if ( V_47 <= 0 )
return - V_11 ;
V_2 -> V_7 -> V_6 . V_63 = V_47 ;
return 0 ;
case V_65 :
V_47 = V_2 -> V_66 ;
break;
case V_67 :
if ( ! V_2 -> V_68 )
return - V_40 ;
return V_2 -> V_68 ( V_2 , ! ! V_47 ) ;
case V_69 :
if ( ! V_2 -> V_70 )
return - V_40 ;
return V_2 -> V_70 ( V_2 , ! ! V_47 ) ;
case V_71 :
if ( ! V_2 -> V_72 )
return - V_40 ;
V_47 = V_2 -> V_73 / 1000 ;
break;
case V_74 :
if ( ! V_2 -> V_72 )
return - V_40 ;
V_47 = V_2 -> V_72 / 1000 ;
break;
case V_75 :
if ( ! V_2 -> V_72 )
return - V_40 ;
V_48 = V_47 * 1000 ;
if ( V_48 < V_2 -> V_73 ||
V_48 > V_2 -> V_72 )
return - V_11 ;
if ( V_2 -> V_76 )
V_31 = V_2 -> V_76 ( V_2 , V_48 ) ;
if ( ! V_31 )
V_2 -> V_16 = V_48 ;
break;
case V_77 :
V_6 -> V_21 = ! ! V_47 ;
break;
default:
return F_30 ( V_43 , V_44 , V_45 ) ;
}
if ( F_28 ( V_44 ) & V_78 )
V_31 = F_31 ( V_47 , V_46 ) ;
return V_31 ;
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
struct V_80 * V_9 ;
struct V_81 * V_10 ;
int V_82 = - V_83 ;
unsigned long V_84 ;
V_9 = F_35 ( sizeof( struct V_80 ) , V_85 ) ;
if ( ! V_9 )
return V_82 ;
V_10 = F_35 ( sizeof( struct V_81 ) , V_85 ) ;
if ( ! V_10 )
goto V_86;
V_82 = F_36 ( V_10 , sizeof( int ) , V_37 ) ;
if ( V_82 )
goto V_87;
V_84 = V_88 ;
if ( V_2 -> V_39 ) {
V_84 |= V_51 ;
if ( V_2 -> V_56 )
V_84 |= V_89 ;
if ( V_2 -> V_58 )
V_84 |= V_90 ;
if ( V_2 -> V_60 )
V_84 |= V_91 ;
}
if ( V_2 -> V_62 )
V_84 |= V_92 |
V_93 ;
if ( V_2 -> V_68 )
V_84 |= V_94 ;
if ( V_2 -> V_70 )
V_84 |= V_95 ;
if ( V_2 -> V_72 )
V_84 |= V_96 ;
snprintf ( V_9 -> V_97 , sizeof( V_9 -> V_97 ) , L_5 ,
V_2 -> V_98 ) ;
V_9 -> V_99 = - 1 ;
V_9 -> V_84 = V_84 ;
V_9 -> V_79 = & V_2 -> V_7 -> V_6 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_100 = & F_32 ;
V_9 -> V_101 = & F_33 ;
V_9 -> V_102 = sizeof( struct V_3 ) * 8 ;
V_9 -> V_103 = & V_104 ;
V_9 -> V_2 = & V_2 -> V_2 ;
V_9 -> V_105 = V_2 ;
V_9 -> V_106 = V_107 ;
V_9 -> V_99 = F_37 ( V_9 ) ;
if ( V_9 -> V_99 < 0 ) {
V_82 = - V_108 ;
goto V_109;
}
V_2 -> V_7 -> V_6 . V_9 = V_9 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_109:
V_87:
F_26 ( V_10 ) ;
V_86:
F_26 ( V_9 ) ;
return V_82 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_39 ( V_6 -> V_9 -> V_99 ) ;
F_40 ( V_6 -> V_9 -> V_10 ) ;
F_26 ( V_6 -> V_9 -> V_10 ) ;
F_26 ( V_6 -> V_9 ) ;
return 0 ;
}
static int T_9 F_41 ( void )
{
F_42 ( & V_110 ) ;
F_43 ( V_111 L_6 ) ;
return 0 ;
}
static void T_10 F_44 ( void )
{
F_45 ( & V_110 ) ;
}
