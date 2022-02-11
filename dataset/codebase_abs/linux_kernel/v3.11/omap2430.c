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
struct V_52 * V_53 = V_51 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_33 * V_34 = V_2 -> V_7 -> V_34 ;
switch ( V_46 -> V_44 ) {
case V_58 :
F_6 ( V_51 , L_10 ) ;
V_34 -> V_37 = true ;
V_2 -> V_7 -> V_8 = V_14 ;
V_2 -> V_7 -> V_59 = V_60 ;
if ( V_2 -> V_61 ) {
F_33 ( V_51 ) ;
F_34 ( V_46 -> V_62 ,
V_63 ) ;
F_18 ( V_2 , 1 ) ;
}
break;
case V_64 :
F_6 ( V_51 , L_11 ) ;
V_34 -> V_37 = false ;
V_2 -> V_7 -> V_8 = V_13 ;
V_2 -> V_7 -> V_59 = V_65 ;
if ( V_2 -> V_61 )
F_33 ( V_51 ) ;
F_34 ( V_46 -> V_62 , V_66 ) ;
break;
case V_67 :
case V_68 :
F_6 ( V_51 , L_12 ) ;
V_2 -> V_7 -> V_59 = V_69 ;
if ( V_2 -> V_61 ) {
F_18 ( V_2 , 0 ) ;
F_35 ( V_51 ) ;
F_36 ( V_51 ) ;
}
if ( V_56 -> V_70 == V_71 )
F_22 ( V_2 -> V_7 -> V_34 , 0 ) ;
F_34 ( V_46 -> V_62 ,
V_72 ) ;
break;
default:
F_6 ( V_51 , L_13 ) ;
}
}
static void V_49 ( struct V_73 * V_74 )
{
struct V_45 * V_46 = F_37 ( V_74 ,
struct V_45 , V_49 ) ;
F_32 ( V_46 ) ;
}
static T_3 F_38 ( int V_75 , void * V_76 )
{
unsigned long V_3 ;
T_3 V_77 = V_78 ;
struct V_2 * V_2 = V_76 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
V_2 -> V_79 = F_3 ( V_2 -> V_10 , V_80 ) ;
V_2 -> V_81 = F_39 ( V_2 -> V_10 , V_82 ) ;
V_2 -> V_83 = F_39 ( V_2 -> V_10 , V_84 ) ;
if ( V_2 -> V_79 || V_2 -> V_81 || V_2 -> V_83 )
V_77 = F_40 ( V_2 ) ;
F_9 ( & V_2 -> V_6 , V_3 ) ;
return V_77 ;
}
static int F_41 ( struct V_2 * V_2 )
{
T_2 V_40 ;
int V_44 = 0 ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_42 ( V_51 -> V_85 ) ;
struct V_52 * V_86 = V_51 -> V_54 ;
struct V_55 * V_56 = V_86 -> V_57 ;
if ( V_51 -> V_85 -> V_87 )
V_2 -> V_7 = F_43 ( V_51 -> V_85 ,
L_14 , 0 ) ;
else
V_2 -> V_7 = F_44 ( V_51 , 0 ) ;
if ( F_45 ( V_2 -> V_7 ) ) {
V_44 = F_46 ( V_2 -> V_7 ) ;
if ( V_44 == - V_88 )
return V_44 ;
F_29 ( L_15 ) ;
return - V_89 ;
}
V_2 -> V_90 = F_38 ;
V_44 = F_33 ( V_51 ) ;
if ( V_44 < 0 ) {
F_21 ( V_51 , L_16 , V_44 ) ;
goto V_91;
}
V_40 = F_25 ( V_2 -> V_10 , V_92 ) ;
if ( V_56 -> V_70 == V_71 ) {
V_40 &= ~ V_93 ;
V_40 |= V_94 ;
} else {
V_40 |= V_93 ;
}
F_26 ( V_2 -> V_10 , V_92 , V_40 ) ;
F_47 ( L_17
L_18 ,
F_25 ( V_2 -> V_10 , V_95 ) ,
F_25 ( V_2 -> V_10 , V_96 ) ,
F_25 ( V_2 -> V_10 , V_97 ) ,
F_25 ( V_2 -> V_10 , V_92 ) ,
F_25 ( V_2 -> V_10 , V_98 ) ) ;
F_48 ( & V_31 , F_1 , ( unsigned long ) V_2 ) ;
if ( V_46 -> V_44 != V_99 )
F_32 ( V_46 ) ;
F_49 ( V_2 -> V_7 ) ;
F_50 ( V_2 -> V_20 ) ;
return 0 ;
V_91:
return V_44 ;
}
static void F_51 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_26 = V_28 + F_11 ( 1000 ) ;
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_42 ( V_51 -> V_85 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_57 ;
switch ( V_46 -> V_44 ) {
case V_58 :
F_34 ( V_46 -> V_62 , V_63 ) ;
if ( V_56 -> V_70 != V_71 )
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
case V_64 :
F_34 ( V_46 -> V_62 , V_66 ) ;
break;
default:
break;
}
}
static void F_52 ( struct V_2 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_20 ;
struct V_45 * V_46 = F_42 ( V_51 -> V_85 ) ;
if ( V_46 -> V_44 != V_99 )
F_34 ( V_46 -> V_62 ,
V_72 ) ;
}
static int F_53 ( struct V_2 * V_2 )
{
F_54 ( & V_31 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_100 * V_101 )
{
struct V_102 V_103 [ 3 ] ;
struct V_52 * V_53 = V_101 -> V_51 . V_54 ;
struct V_55 * V_56 ;
struct V_100 * V_2 ;
struct V_45 * V_46 ;
struct V_104 * V_105 = V_101 -> V_51 . V_87 ;
struct V_106 * V_107 ;
int V_108 = - V_109 ;
V_46 = F_56 ( & V_101 -> V_51 , sizeof( * V_46 ) , V_110 ) ;
if ( ! V_46 ) {
F_21 ( & V_101 -> V_51 , L_19 ) ;
goto V_111;
}
V_2 = F_57 ( L_20 , V_112 ) ;
if ( ! V_2 ) {
F_21 ( & V_101 -> V_51 , L_21 ) ;
goto V_111;
}
V_2 -> V_51 . V_85 = & V_101 -> V_51 ;
V_2 -> V_51 . V_113 = & V_114 ;
V_2 -> V_51 . V_115 = V_114 ;
V_46 -> V_51 = & V_101 -> V_51 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_44 = V_99 ;
if ( V_105 ) {
V_53 = F_56 ( & V_101 -> V_51 , sizeof( * V_53 ) , V_110 ) ;
if ( ! V_53 ) {
F_21 ( & V_101 -> V_51 ,
L_22 ) ;
goto V_116;
}
V_56 = F_56 ( & V_101 -> V_51 , sizeof( * V_56 ) , V_110 ) ;
if ( ! V_56 ) {
F_21 ( & V_101 -> V_51 ,
L_23 ) ;
goto V_116;
}
V_107 = F_56 ( & V_101 -> V_51 , sizeof( * V_107 ) , V_110 ) ;
if ( ! V_107 ) {
F_21 ( & V_101 -> V_51 ,
L_24 ) ;
goto V_116;
}
F_58 ( V_105 , L_25 , ( T_2 * ) & V_53 -> V_117 ) ;
F_58 ( V_105 , L_26 ,
( T_2 * ) & V_56 -> V_70 ) ;
F_58 ( V_105 , L_27 , ( T_2 * ) & V_107 -> V_118 ) ;
F_58 ( V_105 , L_28 , ( T_2 * ) & V_107 -> V_119 ) ;
F_58 ( V_105 , L_29 , ( T_2 * ) & V_53 -> V_4 ) ;
V_107 -> V_120 = F_59 ( V_105 , L_30 ) ;
V_53 -> V_121 = F_59 ( V_105 ,
L_31 ) ;
V_53 -> V_57 = V_56 ;
V_53 -> V_107 = V_107 ;
}
if ( V_53 -> V_121 ) {
V_46 -> V_62 = F_60 () ;
if ( F_45 ( V_46 -> V_62 ) ) {
F_61 ( & V_101 -> V_51 , L_32 ) ;
V_108 = F_46 ( V_46 -> V_62 ) ;
goto V_116;
}
} else {
V_46 -> V_62 = F_62 ( - V_122 ) ;
}
V_53 -> V_123 = & V_124 ;
F_63 ( V_101 , V_46 ) ;
V_47 = V_46 ;
F_64 ( & V_46 -> V_49 , V_49 ) ;
memset ( V_103 , 0x00 , sizeof( * V_103 ) *
F_65 ( V_103 ) ) ;
V_103 [ 0 ] . V_125 = V_101 -> V_102 [ 0 ] . V_125 ;
V_103 [ 0 ] . V_126 = V_101 -> V_102 [ 0 ] . V_126 ;
V_103 [ 0 ] . V_127 = V_101 -> V_102 [ 0 ] . V_127 ;
V_103 [ 0 ] . V_3 = V_101 -> V_102 [ 0 ] . V_3 ;
V_103 [ 1 ] . V_125 = V_101 -> V_102 [ 1 ] . V_125 ;
V_103 [ 1 ] . V_126 = V_101 -> V_102 [ 1 ] . V_126 ;
V_103 [ 1 ] . V_127 = V_101 -> V_102 [ 1 ] . V_127 ;
V_103 [ 1 ] . V_3 = V_101 -> V_102 [ 1 ] . V_3 ;
V_103 [ 2 ] . V_125 = V_101 -> V_102 [ 2 ] . V_125 ;
V_103 [ 2 ] . V_126 = V_101 -> V_102 [ 2 ] . V_126 ;
V_103 [ 2 ] . V_127 = V_101 -> V_102 [ 2 ] . V_127 ;
V_103 [ 2 ] . V_3 = V_101 -> V_102 [ 2 ] . V_3 ;
V_108 = F_66 ( V_2 , V_103 ,
F_65 ( V_103 ) ) ;
if ( V_108 ) {
F_21 ( & V_101 -> V_51 , L_33 ) ;
goto V_116;
}
V_108 = F_67 ( V_2 , V_53 , sizeof( * V_53 ) ) ;
if ( V_108 ) {
F_21 ( & V_101 -> V_51 , L_34 ) ;
goto V_116;
}
F_68 ( & V_101 -> V_51 ) ;
V_108 = F_69 ( V_2 ) ;
if ( V_108 ) {
F_21 ( & V_101 -> V_51 , L_35 ) ;
goto V_116;
}
return 0 ;
V_116:
F_70 ( V_2 ) ;
V_111:
return V_108 ;
}
static int F_71 ( struct V_100 * V_101 )
{
struct V_45 * V_46 = F_72 ( V_101 ) ;
F_73 ( & V_46 -> V_49 ) ;
F_74 ( V_46 -> V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_42 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
V_2 -> V_128 . V_129 = F_25 ( V_2 -> V_10 ,
V_92 ) ;
F_24 ( V_2 ) ;
F_76 ( V_2 -> V_7 , 1 ) ;
}
return 0 ;
}
static int F_77 ( struct V_50 * V_51 )
{
struct V_45 * V_46 = F_42 ( V_51 ) ;
struct V_2 * V_2 = F_30 ( V_46 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 -> V_10 , V_92 ,
V_2 -> V_128 . V_129 ) ;
F_76 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_130 ) ;
}
static void T_5 F_80 ( void )
{
F_81 ( & V_130 ) ;
}
