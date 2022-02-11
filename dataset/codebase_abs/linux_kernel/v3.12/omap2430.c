static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = ( void * ) V_1 ;
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
switch ( V_2 -> V_7 -> V_8 ) {
case V_9 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 ) {
V_2 -> V_7 -> V_8 = V_13 ;
F_4 ( V_2 ) ;
} else {
V_2 -> V_7 -> V_8 = V_14 ;
F_5 ( V_2 ) ;
}
break;
case V_15 :
if ( V_2 -> V_16 & V_17 ) {
V_4 = F_3 ( V_2 -> V_10 , V_18 ) ;
V_4 &= ~ V_19 ;
F_6 ( V_2 -> V_20 , L_1 , V_4 ) ;
F_7 ( V_2 -> V_10 , V_18 , V_4 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_16 &= ~ ( V_22
| V_17 ) ;
V_2 -> V_16 |= V_23 << 16 ;
F_8 ( V_2 -> V_24 ) ;
V_2 -> V_7 -> V_8 = V_25 ;
}
break;
case V_25 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 )
V_2 -> V_7 -> V_8 = V_13 ;
else
V_2 -> V_7 -> V_8 = V_9 ;
default:
break;
}
F_9 ( & V_2 -> V_6 , V_3 ) ;
}
static void F_10 ( struct V_2 * V_2 , unsigned long V_26 )
{
unsigned long V_27 = V_28 + F_11 ( 3 ) ;
static unsigned long V_29 ;
if ( V_26 == 0 )
V_26 = V_27 ;
if ( V_2 -> V_21 || ( ( V_2 -> V_30 == 0 )
&& ( V_2 -> V_7 -> V_8 == V_9 ) ) ) {
F_6 ( V_2 -> V_20 , L_2 ,
F_12 ( V_2 -> V_7 -> V_8 ) ) ;
F_13 ( & V_31 ) ;
V_29 = V_28 ;
return;
}
if ( F_14 ( V_29 , V_26 ) ) {
if ( ! F_15 ( & V_31 ) )
V_29 = V_26 ;
else {
F_6 ( V_2 -> V_20 , L_3 ) ;
return;
}
}
V_29 = V_26 ;
F_6 ( V_2 -> V_20 , L_4 ,
F_12 ( V_2 -> V_7 -> V_8 ) ,
( unsigned long ) F_16 ( V_26 - V_28 ) ) ;
F_17 ( & V_31 , V_26 ) ;
}
static void F_18 ( struct V_2 * V_2 , int V_32 )
{
struct V_33 * V_34 = V_2 -> V_7 -> V_34 ;
T_1 V_5 ;
unsigned long V_26 = V_28 + F_11 ( 1000 ) ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_32 ) {
if ( V_2 -> V_7 -> V_8 == V_14 ) {
int V_35 = 100 ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) & 0x80 ) {
F_19 ( 5 ) ;
F_20 () ;
if ( F_14 ( V_28 , V_26 )
|| V_35 -- <= 0 ) {
F_21 ( V_2 -> V_20 ,
L_5 ) ;
break;
}
}
F_22 ( V_34 , 1 ) ;
} else {
V_2 -> V_21 = 1 ;
V_34 -> V_37 = 1 ;
V_2 -> V_7 -> V_8 = V_38 ;
V_5 |= V_36 ;
F_5 ( V_2 ) ;
}
} else {
V_2 -> V_21 = 0 ;
V_34 -> V_37 = 0 ;
V_2 -> V_7 -> V_8 = V_13 ;
V_5 &= ~ V_36 ;
F_4 ( V_2 ) ;
}
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
F_6 ( V_2 -> V_20 , L_6
L_7 ,
F_12 ( V_2 -> V_7 -> V_8 ) ,
F_3 ( V_2 -> V_10 , V_11 ) ) ;
}
static int F_23 ( struct V_2 * V_2 , T_1 V_39 )
{
T_1 V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static inline void F_24 ( struct V_2 * V_2 )
{
T_2 V_40 ;
V_40 = F_25 ( V_2 -> V_10 , V_41 ) ;
V_40 |= V_42 ;
F_26 ( V_2 -> V_10 , V_41 , V_40 ) ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
T_2 V_40 ;
V_40 = F_25 ( V_2 -> V_10 , V_41 ) ;
V_40 &= ~ V_42 ;
F_26 ( V_2 -> V_10 , V_41 , V_40 ) ;
}
void F_28 ( enum V_43 V_44 )
{
struct V_45 * V_46 = V_47 ;
if ( ! V_46 ) {
F_29 ( L_8 , V_48 ) ;
return;
}
V_46 -> V_44 = V_44 ;
if ( ! F_30 ( V_46 ) ) {
F_29 ( L_9 , V_48 ) ;
return;
}
F_31 ( & V_46 -> V_49 ) ;
}
static void F_32 ( struct V_45 * V_46 )
{
struct V_2 * V_2 = F_30 ( V_46 ) ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_52 * V_53 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_53 -> V_56 ;
struct V_33 * V_34 = V_2 -> V_7 -> V_34 ;
switch ( V_46 -> V_44 ) {
case V_57 :
F_6 ( V_51 , L_10 ) ;
V_34 -> V_37 = true ;
V_2 -> V_7 -> V_8 = V_14 ;
V_2 -> V_7 -> V_58 = V_59 ;
if ( V_2 -> V_60 ) {
F_34 ( V_51 ) ;
F_35 ( V_46 -> V_61 ,
V_62 ) ;
F_18 ( V_2 , 1 ) ;
}
break;
case V_63 :
F_6 ( V_51 , L_11 ) ;
V_34 -> V_37 = false ;
V_2 -> V_7 -> V_8 = V_13 ;
V_2 -> V_7 -> V_58 = V_64 ;
if ( V_2 -> V_60 )
F_34 ( V_51 ) ;
F_35 ( V_46 -> V_61 , V_65 ) ;
break;
case V_66 :
case V_67 :
F_6 ( V_51 , L_12 ) ;
V_2 -> V_7 -> V_58 = V_68 ;
if ( V_2 -> V_60 ) {
F_18 ( V_2 , 0 ) ;
F_36 ( V_51 ) ;
F_37 ( V_51 ) ;
}
if ( V_55 -> V_69 == V_70 )
F_22 ( V_2 -> V_7 -> V_34 , 0 ) ;
F_35 ( V_46 -> V_61 ,
V_71 ) ;
break;
default:
F_6 ( V_51 , L_13 ) ;
}
}
static void V_49 ( struct V_72 * V_73 )
{
struct V_45 * V_46 = F_38 ( V_73 ,
struct V_45 , V_49 ) ;
F_32 ( V_46 ) ;
}
static T_3 F_39 ( int V_74 , void * V_75 )
{
unsigned long V_3 ;
T_3 V_76 = V_77 ;
struct V_2 * V_2 = V_75 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
V_2 -> V_78 = F_3 ( V_2 -> V_10 , V_79 ) ;
V_2 -> V_80 = F_40 ( V_2 -> V_10 , V_81 ) ;
V_2 -> V_82 = F_40 ( V_2 -> V_10 , V_83 ) ;
if ( V_2 -> V_78 || V_2 -> V_80 || V_2 -> V_82 )
V_76 = F_41 ( V_2 ) ;
F_9 ( & V_2 -> V_6 , V_3 ) ;
return V_76 ;
}
static int F_42 ( struct V_2 * V_2 )
{
T_2 V_40 ;
int V_44 = 0 ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_43 ( V_51 -> V_84 ) ;
struct V_52 * V_85 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_85 -> V_56 ;
if ( V_51 -> V_84 -> V_86 )
V_2 -> V_7 = F_44 ( V_51 -> V_84 ,
L_14 , 0 ) ;
else
V_2 -> V_7 = F_45 ( V_51 , 0 ) ;
if ( F_46 ( V_2 -> V_7 ) ) {
V_44 = F_47 ( V_2 -> V_7 ) ;
if ( V_44 == - V_87 )
return V_44 ;
F_29 ( L_15 ) ;
return - V_88 ;
}
V_2 -> V_89 = F_39 ;
V_44 = F_34 ( V_51 ) ;
if ( V_44 < 0 ) {
F_21 ( V_51 , L_16 , V_44 ) ;
goto V_90;
}
V_40 = F_25 ( V_2 -> V_10 , V_91 ) ;
if ( V_55 -> V_69 == V_70 ) {
V_40 &= ~ V_92 ;
V_40 |= V_93 ;
} else {
V_40 |= V_92 ;
}
F_26 ( V_2 -> V_10 , V_91 , V_40 ) ;
F_48 ( L_17
L_18 ,
F_25 ( V_2 -> V_10 , V_94 ) ,
F_25 ( V_2 -> V_10 , V_95 ) ,
F_25 ( V_2 -> V_10 , V_96 ) ,
F_25 ( V_2 -> V_10 , V_91 ) ,
F_25 ( V_2 -> V_10 , V_97 ) ) ;
F_49 ( & V_31 , F_1 , ( unsigned long ) V_2 ) ;
if ( V_46 -> V_44 != V_98 )
F_32 ( V_46 ) ;
F_50 ( V_2 -> V_7 ) ;
F_51 ( V_2 -> V_20 ) ;
return 0 ;
V_90:
return V_44 ;
}
static void F_52 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_26 = V_28 + F_11 ( 1000 ) ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_43 ( V_51 -> V_84 ) ;
struct V_52 * V_53 = F_33 ( V_51 ) ;
struct V_54 * V_55 = V_53 -> V_56 ;
switch ( V_46 -> V_44 ) {
case V_57 :
F_35 ( V_46 -> V_61 , V_62 ) ;
if ( V_55 -> V_69 != V_70 )
break;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_36 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_20 () ;
if ( F_14 ( V_28 , V_26 ) ) {
F_21 ( V_51 , L_5 ) ;
break;
}
}
break;
case V_63 :
F_35 ( V_46 -> V_61 , V_65 ) ;
break;
default:
break;
}
}
static void F_53 ( struct V_2 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_43 ( V_51 -> V_84 ) ;
if ( V_46 -> V_44 != V_98 )
F_35 ( V_46 -> V_61 ,
V_71 ) ;
}
static int F_54 ( struct V_2 * V_2 )
{
F_55 ( & V_31 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_99 * V_100 )
{
struct V_101 V_102 [ 3 ] ;
struct V_52 * V_53 = F_33 ( & V_100 -> V_51 ) ;
struct V_54 * V_55 ;
struct V_99 * V_2 ;
struct V_45 * V_46 ;
struct V_103 * V_104 = V_100 -> V_51 . V_86 ;
struct V_105 * V_106 ;
int V_107 = - V_108 ;
V_46 = F_57 ( & V_100 -> V_51 , sizeof( * V_46 ) , V_109 ) ;
if ( ! V_46 ) {
F_21 ( & V_100 -> V_51 , L_19 ) ;
goto V_110;
}
V_2 = F_58 ( L_20 , V_111 ) ;
if ( ! V_2 ) {
F_21 ( & V_100 -> V_51 , L_21 ) ;
goto V_110;
}
V_2 -> V_51 . V_84 = & V_100 -> V_51 ;
V_2 -> V_51 . V_112 = & V_113 ;
V_2 -> V_51 . V_114 = V_113 ;
V_46 -> V_51 = & V_100 -> V_51 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_44 = V_98 ;
if ( V_104 ) {
V_53 = F_57 ( & V_100 -> V_51 , sizeof( * V_53 ) , V_109 ) ;
if ( ! V_53 ) {
F_21 ( & V_100 -> V_51 ,
L_22 ) ;
goto V_115;
}
V_55 = F_57 ( & V_100 -> V_51 , sizeof( * V_55 ) , V_109 ) ;
if ( ! V_55 ) {
F_21 ( & V_100 -> V_51 ,
L_23 ) ;
goto V_115;
}
V_106 = F_57 ( & V_100 -> V_51 , sizeof( * V_106 ) , V_109 ) ;
if ( ! V_106 ) {
F_21 ( & V_100 -> V_51 ,
L_24 ) ;
goto V_115;
}
F_59 ( V_104 , L_25 , ( T_2 * ) & V_53 -> V_116 ) ;
F_59 ( V_104 , L_26 ,
( T_2 * ) & V_55 -> V_69 ) ;
F_59 ( V_104 , L_27 , ( T_2 * ) & V_106 -> V_117 ) ;
F_59 ( V_104 , L_28 , ( T_2 * ) & V_106 -> V_118 ) ;
F_59 ( V_104 , L_29 , ( T_2 * ) & V_53 -> V_4 ) ;
V_106 -> V_119 = F_60 ( V_104 , L_30 ) ;
V_53 -> V_120 = F_60 ( V_104 ,
L_31 ) ;
V_53 -> V_56 = V_55 ;
V_53 -> V_106 = V_106 ;
}
if ( V_53 -> V_120 ) {
V_46 -> V_61 = F_61 () ;
if ( F_46 ( V_46 -> V_61 ) ) {
F_62 ( & V_100 -> V_51 , L_32 ) ;
V_107 = F_47 ( V_46 -> V_61 ) ;
goto V_115;
}
} else {
V_46 -> V_61 = F_63 ( - V_121 ) ;
}
V_53 -> V_122 = & V_123 ;
F_64 ( V_100 , V_46 ) ;
V_47 = V_46 ;
F_65 ( & V_46 -> V_49 , V_49 ) ;
memset ( V_102 , 0x00 , sizeof( * V_102 ) *
F_66 ( V_102 ) ) ;
V_102 [ 0 ] . V_124 = V_100 -> V_101 [ 0 ] . V_124 ;
V_102 [ 0 ] . V_125 = V_100 -> V_101 [ 0 ] . V_125 ;
V_102 [ 0 ] . V_126 = V_100 -> V_101 [ 0 ] . V_126 ;
V_102 [ 0 ] . V_3 = V_100 -> V_101 [ 0 ] . V_3 ;
V_102 [ 1 ] . V_124 = V_100 -> V_101 [ 1 ] . V_124 ;
V_102 [ 1 ] . V_125 = V_100 -> V_101 [ 1 ] . V_125 ;
V_102 [ 1 ] . V_126 = V_100 -> V_101 [ 1 ] . V_126 ;
V_102 [ 1 ] . V_3 = V_100 -> V_101 [ 1 ] . V_3 ;
V_102 [ 2 ] . V_124 = V_100 -> V_101 [ 2 ] . V_124 ;
V_102 [ 2 ] . V_125 = V_100 -> V_101 [ 2 ] . V_125 ;
V_102 [ 2 ] . V_126 = V_100 -> V_101 [ 2 ] . V_126 ;
V_102 [ 2 ] . V_3 = V_100 -> V_101 [ 2 ] . V_3 ;
V_107 = F_67 ( V_2 , V_102 ,
F_66 ( V_102 ) ) ;
if ( V_107 ) {
F_21 ( & V_100 -> V_51 , L_33 ) ;
goto V_115;
}
V_107 = F_68 ( V_2 , V_53 , sizeof( * V_53 ) ) ;
if ( V_107 ) {
F_21 ( & V_100 -> V_51 , L_34 ) ;
goto V_115;
}
F_69 ( & V_100 -> V_51 ) ;
V_107 = F_70 ( V_2 ) ;
if ( V_107 ) {
F_21 ( & V_100 -> V_51 , L_35 ) ;
goto V_115;
}
return 0 ;
V_115:
F_71 ( V_2 ) ;
V_110:
return V_107 ;
}
static int F_72 ( struct V_99 * V_100 )
{
struct V_45 * V_46 = F_73 ( V_100 ) ;
F_74 ( & V_46 -> V_49 ) ;
F_75 ( V_46 -> V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_43 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
V_2 -> V_127 . V_128 = F_25 ( V_2 -> V_10 ,
V_91 ) ;
F_24 ( V_2 ) ;
F_77 ( V_2 -> V_7 , 1 ) ;
}
return 0 ;
}
static int F_78 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_43 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 -> V_10 , V_91 ,
V_2 -> V_127 . V_128 ) ;
F_77 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
return F_80 ( & V_129 ) ;
}
static void T_5 F_81 ( void )
{
F_82 ( & V_129 ) ;
}
