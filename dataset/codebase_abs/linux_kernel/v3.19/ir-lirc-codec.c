static int F_1 ( struct V_1 * V_2 , struct V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return 0 ;
if ( ! V_2 -> V_7 -> V_6 . V_11 || ! V_2 -> V_7 -> V_6 . V_11 -> V_12 )
return - V_13 ;
if ( V_4 . V_14 ) {
V_8 = F_2 ( V_15 ) ;
F_3 ( 2 , L_1 ) ;
} else if ( V_4 . V_16 ) {
V_8 = F_4 ( V_4 . V_17 ) ;
F_3 ( 2 , L_2 , V_8 ) ;
} else if ( V_4 . V_18 ) {
if ( V_6 -> V_19 )
return 0 ;
V_6 -> V_20 = F_5 () ;
V_6 -> V_19 = true ;
V_6 -> V_21 = V_4 . V_22 ;
if ( ! V_6 -> V_23 )
return 0 ;
V_8 = F_6 ( V_4 . V_22 / 1000 ) ;
F_3 ( 2 , L_3 , V_8 ) ;
} else {
if ( V_6 -> V_19 ) {
int V_24 ;
V_6 -> V_21 += F_7 ( F_8 ( F_5 () ,
V_6 -> V_20 ) ) ;
F_9 ( V_6 -> V_21 , 1000 ) ;
V_6 -> V_21 = F_10 ( V_6 -> V_21 ,
( V_25 ) V_15 ) ;
V_24 = F_2 ( V_6 -> V_21 ) ;
F_11 ( V_2 -> V_7 -> V_6 . V_11 -> V_12 ,
( unsigned char * ) & V_24 ) ;
V_6 -> V_19 = false ;
}
V_8 = V_4 . V_26 ? F_12 ( V_4 . V_22 / 1000 ) :
F_2 ( V_4 . V_22 / 1000 ) ;
F_3 ( 2 , L_4 ,
F_13 ( V_4 . V_22 ) , F_14 ( V_4 . V_26 ) ) ;
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
unsigned int V_22 = 0 ;
int V_37 ;
V_35 = F_5 () ;
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
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
if ( V_32 [ V_37 ] > V_43 / 1000 - V_22 || ! V_32 [ V_37 ] ) {
V_33 = - V_13 ;
goto V_40;
}
V_22 += V_32 [ V_37 ] ;
}
V_33 = V_2 -> V_41 ( V_2 , V_32 , V_34 ) ;
if ( V_33 < 0 )
goto V_40;
for ( V_22 = V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
V_22 += V_32 [ V_37 ] ;
V_33 *= sizeof( unsigned int ) ;
V_36 = F_21 ( F_22 ( V_35 , V_22 ) , F_5 () ) ;
if ( V_36 > 0 ) {
F_23 ( V_44 ) ;
F_24 ( F_25 ( V_36 ) ) ;
}
V_40:
F_26 ( V_32 ) ;
return V_33 ;
}
static long F_27 ( struct V_28 * V_45 , unsigned int V_46 ,
unsigned long V_47 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_7 T_2 * V_48 = ( T_7 T_2 * ) ( V_47 ) ;
int V_33 = 0 ;
T_8 V_49 = 0 , V_50 ;
V_6 = F_17 ( V_45 ) ;
if ( ! V_6 )
return - V_38 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return - V_38 ;
if ( F_28 ( V_46 ) & V_51 ) {
V_33 = F_29 ( V_49 , V_48 ) ;
if ( V_33 )
return V_33 ;
}
switch ( V_46 ) {
case V_52 :
V_49 = V_53 & V_54 ;
break;
case V_55 :
if ( V_49 != ( V_56 & V_54 ) )
return - V_13 ;
return 0 ;
case V_57 :
if ( ! V_2 -> V_58 )
return - V_42 ;
return V_2 -> V_58 ( V_2 , V_49 ) ;
case V_59 :
if ( ! V_2 -> V_60 )
return - V_42 ;
return V_2 -> V_60 ( V_2 , V_49 ) ;
case V_61 :
if ( ! V_2 -> V_62 )
return - V_42 ;
if ( V_49 <= 0 || V_49 >= 100 )
return - V_13 ;
return V_2 -> V_62 ( V_2 , V_49 ) ;
case V_63 :
if ( ! V_2 -> V_64 )
return - V_42 ;
if ( V_49 <= 0 )
return - V_13 ;
return V_2 -> V_64 ( V_2 ,
V_2 -> V_7 -> V_6 . V_65 ,
V_49 ) ;
case V_66 :
if ( V_49 <= 0 )
return - V_13 ;
V_2 -> V_7 -> V_6 . V_65 = V_49 ;
return 0 ;
case V_67 :
V_49 = V_2 -> V_68 ;
break;
case V_69 :
if ( ! V_2 -> V_70 )
return - V_42 ;
return V_2 -> V_70 ( V_2 , ! ! V_49 ) ;
case V_71 :
if ( ! V_2 -> V_72 )
return - V_42 ;
return V_2 -> V_72 ( V_2 , ! ! V_49 ) ;
case V_73 :
if ( ! V_2 -> V_74 )
return - V_42 ;
V_49 = V_2 -> V_75 / 1000 ;
break;
case V_76 :
if ( ! V_2 -> V_74 )
return - V_42 ;
V_49 = V_2 -> V_74 / 1000 ;
break;
case V_77 :
if ( ! V_2 -> V_74 )
return - V_42 ;
V_50 = V_49 * 1000 ;
if ( V_50 < V_2 -> V_75 ||
V_50 > V_2 -> V_74 )
return - V_13 ;
V_2 -> V_18 = V_50 ;
break;
case V_78 :
V_6 -> V_23 = ! ! V_49 ;
break;
default:
return F_30 ( V_45 , V_46 , V_47 ) ;
}
if ( F_28 ( V_46 ) & V_79 )
V_33 = F_31 ( V_49 , V_48 ) ;
return V_33 ;
}
static int F_32 ( void * V_80 )
{
return 0 ;
}
static void F_33 ( void * V_80 )
{
return;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_81 * V_11 ;
struct V_82 * V_12 ;
int V_83 = - V_84 ;
unsigned long V_85 ;
V_11 = F_35 ( sizeof( struct V_81 ) , V_86 ) ;
if ( ! V_11 )
return V_83 ;
V_12 = F_35 ( sizeof( struct V_82 ) , V_86 ) ;
if ( ! V_12 )
goto V_87;
V_83 = F_36 ( V_12 , sizeof( int ) , V_39 ) ;
if ( V_83 )
goto V_88;
V_85 = V_89 ;
if ( V_2 -> V_41 ) {
V_85 |= V_53 ;
if ( V_2 -> V_58 )
V_85 |= V_90 ;
if ( V_2 -> V_60 )
V_85 |= V_91 ;
if ( V_2 -> V_62 )
V_85 |= V_92 ;
}
if ( V_2 -> V_64 )
V_85 |= V_93 |
V_94 ;
if ( V_2 -> V_70 )
V_85 |= V_95 ;
if ( V_2 -> V_72 )
V_85 |= V_96 ;
if ( V_2 -> V_74 )
V_85 |= V_97 ;
snprintf ( V_11 -> V_98 , sizeof( V_11 -> V_98 ) , L_5 ,
V_2 -> V_99 ) ;
V_11 -> V_100 = - 1 ;
V_11 -> V_85 = V_85 ;
V_11 -> V_80 = & V_2 -> V_7 -> V_6 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_101 = & F_32 ;
V_11 -> V_102 = & F_33 ;
V_11 -> V_103 = sizeof( struct V_3 ) * 8 ;
V_11 -> V_104 = & V_105 ;
V_11 -> V_2 = & V_2 -> V_2 ;
V_11 -> V_106 = V_2 ;
V_11 -> V_107 = V_108 ;
V_11 -> V_100 = F_37 ( V_11 ) ;
if ( V_11 -> V_100 < 0 ) {
V_83 = - V_109 ;
goto V_110;
}
V_2 -> V_7 -> V_6 . V_11 = V_11 ;
V_2 -> V_7 -> V_6 . V_2 = V_2 ;
return 0 ;
V_110:
V_88:
F_26 ( V_12 ) ;
V_87:
F_26 ( V_11 ) ;
return V_83 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
F_39 ( V_6 -> V_11 -> V_100 ) ;
F_40 ( V_6 -> V_11 -> V_12 ) ;
F_26 ( V_6 -> V_11 ) ;
return 0 ;
}
static int T_9 F_41 ( void )
{
F_42 ( & V_111 ) ;
F_43 ( V_112 L_6 ) ;
return 0 ;
}
static void T_10 F_44 ( void )
{
F_45 ( & V_111 ) ;
}
