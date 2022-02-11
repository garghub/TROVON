static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return 0 ;
if ( ! V_2 -> V_7 -> V_6 . V_10 || ! V_2 -> V_7 -> V_6 . V_10 -> V_11 )
return - V_12 ;
if ( V_4 . V_13 )
return 0 ;
if ( V_4 . V_14 ) {
V_8 = F_3 ( V_4 . V_15 ) ;
F_4 ( 2 , L_1 , V_8 ) ;
} else if ( V_4 . V_16 ) {
if ( V_6 -> V_17 )
return 0 ;
V_6 -> V_18 = F_5 () ;
V_6 -> V_17 = true ;
V_6 -> V_19 = V_4 . V_20 ;
if ( ! V_6 -> V_21 )
return 0 ;
V_8 = F_6 ( V_4 . V_20 / 1000 ) ;
F_4 ( 2 , L_2 , V_8 ) ;
} else {
if ( V_6 -> V_17 ) {
int V_22 ;
V_6 -> V_19 += F_7 ( F_8 ( F_5 () ,
V_6 -> V_18 ) ) ;
F_9 ( V_6 -> V_19 , 1000 ) ;
V_6 -> V_19 = F_10 ( V_6 -> V_19 ,
( V_23 ) V_24 ) ;
V_22 = F_11 ( V_6 -> V_19 ) ;
F_12 ( V_2 -> V_7 -> V_6 . V_10 -> V_11 ,
( unsigned char * ) & V_22 ) ;
V_6 -> V_17 = false ;
}
V_8 = V_4 . V_25 ? F_13 ( V_4 . V_20 / 1000 ) :
F_11 ( V_4 . V_20 / 1000 ) ;
F_4 ( 2 , L_3 ,
F_14 ( V_4 . V_20 ) , F_15 ( V_4 . V_25 ) ) ;
}
F_12 ( V_2 -> V_7 -> V_6 . V_10 -> V_11 ,
( unsigned char * ) & V_8 ) ;
F_16 ( & V_2 -> V_7 -> V_6 . V_10 -> V_11 -> V_26 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_27 * V_27 , const char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned int * V_31 ;
T_1 V_32 = - V_12 ;
T_3 V_33 ;
T_5 V_34 ;
T_6 V_35 ;
unsigned int V_20 = 0 ;
int V_36 ;
V_34 = F_5 () ;
V_6 = F_18 ( V_27 ) ;
if ( ! V_6 )
return - V_37 ;
if ( V_29 < sizeof( unsigned ) || V_29 % sizeof( unsigned ) )
return - V_12 ;
V_33 = V_29 / sizeof( unsigned ) ;
if ( V_33 > V_38 || V_33 % 2 == 0 )
return - V_12 ;
V_31 = F_19 ( V_28 , V_29 ) ;
if ( F_20 ( V_31 ) )
return F_21 ( V_31 ) ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 ) {
V_32 = - V_37 ;
goto V_39;
}
if ( ! V_2 -> V_40 ) {
V_32 = - V_41 ;
goto V_39;
}
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
if ( V_31 [ V_36 ] > V_42 / 1000 - V_20 || ! V_31 [ V_36 ] ) {
V_32 = - V_12 ;
goto V_39;
}
V_20 += V_31 [ V_36 ] ;
}
V_32 = V_2 -> V_40 ( V_2 , V_31 , V_33 ) ;
if ( V_32 < 0 )
goto V_39;
for ( V_20 = V_36 = 0 ; V_36 < V_32 ; V_36 ++ )
V_20 += V_31 [ V_36 ] ;
V_32 *= sizeof( unsigned int ) ;
V_35 = F_22 ( F_23 ( V_34 , V_20 ) , F_5 () ) ;
if ( V_35 > 0 ) {
F_24 ( V_43 ) ;
F_25 ( F_26 ( V_35 ) ) ;
}
V_39:
F_27 ( V_31 ) ;
return V_32 ;
}
static long F_28 ( struct V_27 * V_44 , unsigned int V_45 ,
unsigned long V_46 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_7 T_2 * V_47 = ( T_7 T_2 * ) ( V_46 ) ;
int V_32 = 0 ;
T_8 V_48 = 0 , V_49 ;
V_6 = F_18 ( V_44 ) ;
if ( ! V_6 )
return - V_37 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_37 ;
if ( F_29 ( V_45 ) & V_50 ) {
V_32 = F_30 ( V_48 , V_47 ) ;
if ( V_32 )
return V_32 ;
}
switch ( V_45 ) {
case V_51 :
V_48 = V_52 & V_53 ;
break;
case V_54 :
if ( V_48 != ( V_55 & V_53 ) )
return - V_12 ;
return 0 ;
case V_56 :
if ( ! V_2 -> V_57 )
return - V_41 ;
return V_2 -> V_57 ( V_2 , V_48 ) ;
case V_58 :
if ( ! V_2 -> V_59 )
return - V_41 ;
return V_2 -> V_59 ( V_2 , V_48 ) ;
case V_60 :
if ( ! V_2 -> V_61 )
return - V_41 ;
if ( V_48 <= 0 || V_48 >= 100 )
return - V_12 ;
return V_2 -> V_61 ( V_2 , V_48 ) ;
case V_62 :
if ( ! V_2 -> V_63 )
return - V_41 ;
if ( V_48 <= 0 )
return - V_12 ;
return V_2 -> V_63 ( V_2 ,
V_2 -> V_7 -> V_6 . V_64 ,
V_48 ) ;
case V_65 :
if ( V_48 <= 0 )
return - V_12 ;
V_2 -> V_7 -> V_6 . V_64 = V_48 ;
return 0 ;
case V_66 :
V_48 = V_2 -> V_67 ;
break;
case V_68 :
if ( ! V_2 -> V_69 )
return - V_41 ;
return V_2 -> V_69 ( V_2 , ! ! V_48 ) ;
case V_70 :
if ( ! V_2 -> V_71 )
return - V_41 ;
return V_2 -> V_71 ( V_2 , ! ! V_48 ) ;
case V_72 :
if ( ! V_2 -> V_73 )
return - V_41 ;
V_48 = V_2 -> V_74 / 1000 ;
break;
case V_75 :
if ( ! V_2 -> V_73 )
return - V_41 ;
V_48 = V_2 -> V_73 / 1000 ;
break;
case V_76 :
if ( ! V_2 -> V_73 )
return - V_41 ;
V_49 = V_48 * 1000 ;
if ( V_49 < V_2 -> V_74 ||
V_49 > V_2 -> V_73 )
return - V_12 ;
V_2 -> V_16 = V_49 ;
break;
case V_77 :
V_6 -> V_21 = ! ! V_48 ;
break;
default:
return F_31 ( V_44 , V_45 , V_46 ) ;
}
if ( F_29 ( V_45 ) & V_78 )
V_32 = F_32 ( V_48 , V_47 ) ;
return V_32 ;
}
static int F_33 ( void * V_79 )
{
return 0 ;
}
static void F_34 ( void * V_79 )
{
return;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_80 * V_10 ;
struct V_81 * V_11 ;
int V_82 = - V_83 ;
unsigned long V_84 ;
V_10 = F_36 ( sizeof( struct V_80 ) , V_85 ) ;
if ( ! V_10 )
return V_82 ;
V_11 = F_36 ( sizeof( struct V_81 ) , V_85 ) ;
if ( ! V_11 )
goto V_86;
V_82 = F_37 ( V_11 , sizeof( int ) , V_38 ) ;
if ( V_82 )
goto V_87;
V_84 = V_88 ;
if ( V_2 -> V_40 ) {
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
snprintf ( V_10 -> V_97 , sizeof( V_10 -> V_97 ) , L_4 ,
V_2 -> V_98 ) ;
V_10 -> V_99 = - 1 ;
V_10 -> V_84 = V_84 ;
V_10 -> V_79 = & V_2 -> V_7 -> V_6 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_100 = & F_33 ;
V_10 -> V_101 = & F_34 ;
V_10 -> V_102 = sizeof( struct V_3 ) * 8 ;
V_10 -> V_103 = & V_104 ;
V_10 -> V_2 = & V_2 -> V_2 ;
V_10 -> V_105 = V_2 ;
V_10 -> V_106 = V_107 ;
V_10 -> V_99 = F_38 ( V_10 ) ;
if ( V_10 -> V_99 < 0 ) {
V_82 = - V_108 ;
goto V_109;
}
V_2 -> V_7 -> V_6 . V_10 = V_10 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_109:
V_87:
F_27 ( V_11 ) ;
V_86:
F_27 ( V_10 ) ;
return V_82 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_40 ( V_6 -> V_10 -> V_99 ) ;
F_41 ( V_6 -> V_10 -> V_11 ) ;
F_27 ( V_6 -> V_10 ) ;
return 0 ;
}
static int T_9 F_42 ( void )
{
F_43 ( & V_110 ) ;
F_44 ( V_111 L_5 ) ;
return 0 ;
}
static void T_10 F_45 ( void )
{
F_46 ( & V_110 ) ;
}
