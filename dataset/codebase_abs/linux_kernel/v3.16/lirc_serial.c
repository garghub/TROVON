static T_1 F_1 ( int V_1 )
{
if ( V_2 != 0 )
V_1 <<= V_3 ;
return F_2 ( V_4 + V_1 ) ;
}
static void F_3 ( int V_1 , T_1 V_5 )
{
if ( V_2 != 0 )
V_1 <<= V_3 ;
F_4 ( V_5 , V_4 + V_1 ) ;
}
static void F_5 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
else
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
}
static void V_9 ( void )
{
if ( V_6 )
F_3 ( V_7 , V_8 [ type ] . F_5 ) ;
else
F_3 ( V_7 , V_8 [ type ] . V_9 ) ;
}
static void F_6 ( unsigned long V_10 )
{
while ( V_10 > V_11 ) {
F_7 ( V_11 ) ;
V_10 -= V_11 ;
}
F_7 ( V_10 ) ;
}
static int F_8 ( unsigned int V_12 ,
unsigned int V_13 )
{
T_2 V_14 , V_15 ;
V_16 = V_12 ;
V_17 = V_13 ;
V_14 = F_9 ( V_18 . V_19 . V_20 ) ;
V_14 *= V_21 ;
V_15 = V_14 ;
V_15 *= 4295 ;
V_22 = ( V_15 >> 32 ) ;
V_23 = V_14 >> 3 ;
V_23 /= ( V_17 >> 3 ) ;
V_24 = V_23 * V_16 / 100 ;
V_25 = V_23 - V_24 ;
F_10 ( L_1
L_2
L_3 ,
V_17 , V_16 , F_9 ( V_26 . V_20 ) ,
V_24 , V_25 , V_22 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_12 ,
unsigned int V_13 )
{
if ( 256 * 1000000L / V_13 * V_12 / 100 <=
V_27 )
return - V_28 ;
if ( 256 * 1000000L / V_13 * ( 100 - V_12 ) / 100 <=
V_27 )
return - V_28 ;
V_16 = V_12 ;
V_17 = V_13 ;
V_23 = 256 * 1000000L / V_17 ;
V_24 = V_23 * V_16 / 100 ;
V_25 = V_23 - V_24 ;
F_10 ( L_4 ,
V_17 , V_24 , V_25 ) ;
return 0 ;
}
static long F_11 ( unsigned long V_29 )
{
long V_30 , V_31 ;
int V_32 ;
unsigned char V_33 ;
unsigned char V_34 , V_35 ;
V_30 = V_29 * 1152 / 10000 ;
if ( V_16 > 50 )
V_34 = 3 ;
else
V_34 = 1 ;
for ( V_32 = 0 , V_33 = 0x7f ; V_30 > 0 ; V_30 -= 3 ) {
V_35 = V_34 << ( V_32 * 3 ) ;
V_35 >>= 1 ;
V_33 &= ( ~ V_35 ) ;
V_32 ++ ;
if ( V_32 == 3 ) {
F_3 ( V_36 , V_33 ) ;
while ( ! ( F_1 ( V_37 ) & V_38 ) )
;
V_33 = 0x7f ;
V_32 = 0 ;
}
}
if ( V_32 != 0 ) {
F_3 ( V_36 , V_33 ) ;
while ( ! ( F_1 ( V_37 ) & V_39 ) )
;
}
if ( V_32 == 0 )
V_31 = ( - V_30 ) * 10000 / 1152 ;
else
V_31 = ( 3 - V_32 ) * 3 * 10000 / 1152 + ( - V_30 ) * 10000 / 1152 ;
return V_31 ;
}
static long F_12 ( unsigned long V_29 )
{
int V_40 ;
unsigned long V_41 , V_42 , V_43 ;
F_13 ( V_42 ) ;
F_5 () ;
V_29 *= V_22 ;
V_43 = V_42 ;
V_41 = V_24 ;
V_40 = 1 ;
while ( ( V_43 - V_42 ) < V_29 ) {
do {
F_13 ( V_43 ) ;
} while ( ( V_43 - V_42 ) < V_41 );
if ( V_40 ) {
F_13 ( V_43 ) ;
V_9 () ;
V_41 += V_25 ;
} else {
F_13 ( V_43 ) ; F_5 () ;
V_41 += V_24 ;
}
V_40 = ! V_40 ;
}
F_13 ( V_43 ) ;
return ( ( V_43 - V_42 ) - V_29 ) / V_22 ;
}
static long F_12 ( unsigned long V_29 )
{
int V_40 ;
unsigned long V_44 , V_41 , V_45 ;
V_29 <<= 8 ;
V_44 = 0 ; V_41 = 0 ; V_40 = 0 ;
while ( V_44 < V_29 ) {
if ( V_40 ) {
V_9 () ;
V_41 += V_25 ;
} else {
F_5 () ;
V_41 += V_24 ;
}
V_45 = ( V_41 - V_44 -
V_27 + 128 ) >> 8 ;
F_7 ( V_45 ) ;
V_44 += ( V_45 << 8 ) + V_27 ;
V_40 = ! V_40 ;
}
return ( V_44 - V_29 ) >> 8 ;
}
static long F_14 ( unsigned long V_29 )
{
if ( V_29 <= 0 )
return 0 ;
if ( V_46 )
return F_12 ( V_29 ) ;
else {
F_5 () ;
F_6 ( V_29 ) ;
return 0 ;
}
}
static void F_15 ( long V_29 )
{
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_16 ( long V_29 )
{
V_9 () ;
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_17 ( int V_47 )
{
if ( F_18 ( & V_48 ) ) {
F_10 ( L_5 ) ;
return;
}
F_19 ( & V_48 , ( void * ) & V_47 ) ;
}
static void F_20 ( int V_47 )
{
static int V_49 , V_50 ;
static unsigned int V_51 ;
if ( V_51 > 0 && ( V_47 & V_52 ) ) {
V_49 += V_47 & V_53 ;
if ( V_49 > 250 ) {
F_17 ( V_50 ) ;
F_17 ( V_49 | V_52 ) ;
V_51 = 0 ;
V_49 = 0 ;
}
return;
}
if ( ! ( V_47 & V_52 ) ) {
if ( V_51 == 0 ) {
if ( V_47 > 20000 ) {
V_50 = V_47 ;
V_51 ++ ;
return;
}
} else {
if ( V_47 > 20000 ) {
V_50 += V_49 ;
if ( V_50 > V_53 )
V_50 = V_53 ;
V_50 += V_47 ;
if ( V_50 > V_53 )
V_50 = V_53 ;
V_49 = 0 ;
return;
}
F_17 ( V_50 ) ;
F_17 ( V_49 | V_52 ) ;
V_51 = 0 ;
V_49 = 0 ;
}
}
F_17 ( V_47 ) ;
}
static T_3 F_21 ( int V_32 , void * V_54 )
{
struct V_55 V_56 ;
int V_57 , V_58 ;
T_1 V_59 ;
long V_60 ;
int V_61 ;
static int V_62 = - 1 ;
if ( ( F_1 ( V_63 ) & V_64 ) ) {
return V_65 ;
}
V_57 = 0 ;
do {
V_57 ++ ;
V_59 = F_1 ( V_66 ) ;
if ( V_57 > V_67 ) {
F_22 ( L_6 ) ;
break;
}
if ( ( V_59 & V_8 [ type ] . V_68 )
&& V_69 != - 1 ) {
F_23 ( & V_56 ) ;
V_58 = ( V_59 & V_8 [ type ] . V_70 ) ? 1 : 0 ;
if ( V_58 == V_62 ) {
F_22 ( L_7 ,
V_58 , V_69 ,
V_56 . V_71 , V_72 . V_71 ,
( unsigned long ) V_56 . V_73 ,
( unsigned long ) V_72 . V_73 ) ;
continue;
}
V_60 = V_56 . V_71 - V_72 . V_71 ;
if ( V_56 . V_71 < V_72 . V_71 ||
( V_56 . V_71 == V_72 . V_71 &&
V_56 . V_73 < V_72 . V_73 ) ) {
F_22 ( L_8 ) ;
F_22 ( L_9 ,
V_58 , V_69 ,
V_56 . V_71 , V_72 . V_71 ,
( unsigned long ) V_56 . V_73 ,
( unsigned long ) V_72 . V_73 ) ;
V_61 = V_53 ;
} else if ( V_60 > 15 ) {
V_61 = V_53 ;
if ( ! ( V_58 ^ V_69 ) ) {
F_22 ( L_10 ,
V_58 , V_69 ,
V_56 . V_71 , V_72 . V_71 ,
( unsigned long ) V_56 . V_73 ,
( unsigned long ) V_72 . V_73 ) ;
V_69 = V_69 ? 0 : 1 ;
}
} else
V_61 = ( int ) ( V_60 * 1000000 +
V_56 . V_73 -
V_72 . V_73 ) ;
F_20 ( V_58 ^ V_69 ? V_61 : ( V_61 | V_52 ) ) ;
V_72 = V_56 ;
V_62 = V_58 ;
F_24 ( & V_48 . V_74 ) ;
}
} while ( ! ( F_1 ( V_63 ) & V_64 ) );
return V_75 ;
}
static int F_25 ( void )
{
T_1 V_76 , V_77 , V_78 ;
V_76 = F_1 ( V_79 ) ;
F_3 ( V_79 , 0 ) ;
#ifdef F_26
F_4 ( 0xff , 0x080 ) ;
#endif
V_77 = F_1 ( V_79 ) & 0x0f ;
F_3 ( V_79 , 0x0f ) ;
#ifdef F_26
F_4 ( 0x00 , 0x080 ) ;
#endif
V_78 = F_1 ( V_79 ) & 0x0f ;
F_3 ( V_79 , V_76 ) ;
if ( V_77 != 0 || V_78 != 0x0f ) {
F_27 ( L_11 ) ;
return - V_80 ;
}
F_3 ( V_81 , F_1 ( V_81 ) & ( ~ V_82 ) ) ;
F_3 ( V_79 , F_1 ( V_79 ) &
( ~ ( V_83 | V_84 | V_85 | V_86 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_87 ) ;
F_1 ( V_63 ) ;
F_1 ( V_66 ) ;
V_9 () ;
F_1 ( V_37 ) ;
F_1 ( V_87 ) ;
F_1 ( V_63 ) ;
F_1 ( V_66 ) ;
switch ( type ) {
case V_88 :
case V_89 :
F_3 ( V_81 , F_1 ( V_81 ) | V_82 ) ;
F_3 ( V_90 , 0 ) ;
F_3 ( V_91 , 1 ) ;
F_3 ( V_81 , V_92 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_28 ( struct V_93 * V_94 )
{
int V_32 , V_95 , V_96 , V_97 ;
V_97 = F_29 ( V_98 , F_21 ,
( V_99 ? V_100 : 0 ) ,
V_101 , ( void * ) & V_8 ) ;
if ( V_97 < 0 ) {
if ( V_97 == - V_102 )
F_30 ( & V_94 -> V_94 , L_12 , V_98 ) ;
else if ( V_97 == - V_28 )
F_30 ( & V_94 -> V_94 , L_13 ) ;
return V_97 ;
}
if ( ( ( V_2 != 0 )
&& ( F_31 ( V_2 , 8 << V_3 ,
V_101 ) == NULL ) )
|| ( ( V_2 == 0 )
&& ( F_32 ( V_4 , 8 , V_101 ) == NULL ) ) ) {
F_30 ( & V_94 -> V_94 , L_14 , V_4 ) ;
F_33 ( & V_94 -> V_94 , L_15 ) ;
F_33 ( & V_94 -> V_94 ,
L_16 ) ;
F_33 ( & V_94 -> V_94 , L_17 ) ;
V_97 = - V_102 ;
goto V_103;
}
V_97 = F_25 () ;
if ( V_97 < 0 )
goto V_104;
F_8 ( V_16 , V_17 ) ;
if ( V_69 == - 1 ) {
F_34 ( 500 ) ;
V_95 = 0 ;
V_96 = 0 ;
for ( V_32 = 0 ; V_32 < 9 ; V_32 ++ ) {
if ( F_1 ( V_66 ) & V_8 [ type ] . V_70 )
V_95 ++ ;
else
V_96 ++ ;
F_34 ( 40 ) ;
}
V_69 = ( V_95 >= V_96 ? 1 : 0 ) ;
F_35 ( & V_94 -> V_94 , L_18 ,
V_69 ? L_19 : L_20 ) ;
} else
F_35 ( & V_94 -> V_94 , L_21 ,
V_69 ? L_19 : L_20 ) ;
F_10 ( L_22 , V_98 , V_4 ) ;
return 0 ;
V_104:
if ( V_2 != 0 )
F_36 ( V_2 , 8 << V_3 ) ;
else
F_37 ( V_4 , 8 ) ;
V_103:
F_38 ( V_98 , ( void * ) & V_8 ) ;
return V_97 ;
}
static int F_39 ( struct V_93 * V_94 )
{
F_38 ( V_98 , ( void * ) & V_8 ) ;
if ( V_2 != 0 )
F_36 ( V_2 , 8 << V_3 ) ;
else
F_37 ( V_4 , 8 ) ;
return 0 ;
}
static int F_40 ( void * V_61 )
{
unsigned long V_105 ;
F_23 ( & V_72 ) ;
F_41 ( & V_8 [ type ] . V_106 , V_105 ) ;
F_3 ( V_81 , F_1 ( V_81 ) & ( ~ V_82 ) ) ;
F_3 ( V_79 , F_1 ( V_79 ) | V_83 ) ;
F_42 ( & V_8 [ type ] . V_106 , V_105 ) ;
return 0 ;
}
static void F_43 ( void * V_61 )
{ unsigned long V_105 ;
F_41 ( & V_8 [ type ] . V_106 , V_105 ) ;
F_3 ( V_81 , F_1 ( V_81 ) & ( ~ V_82 ) ) ;
F_3 ( V_79 , F_1 ( V_79 ) &
( ~ ( V_83 | V_84 | V_85 | V_86 ) ) ) ;
F_42 ( & V_8 [ type ] . V_106 , V_105 ) ;
}
static T_4 F_44 ( struct V_107 * V_107 , const char T_5 * V_108 ,
T_6 V_109 , T_7 * V_110 )
{
int V_32 , V_111 ;
unsigned long V_105 ;
long V_112 = 0 ;
int * V_113 ;
if ( ! ( V_8 [ type ] . V_114 & V_115 ) )
return - V_116 ;
V_111 = V_109 / sizeof( int ) ;
if ( V_109 % sizeof( int ) || V_111 % 2 == 0 )
return - V_28 ;
V_113 = F_45 ( V_108 , V_109 ) ;
if ( F_46 ( V_113 ) )
return F_47 ( V_113 ) ;
F_41 ( & V_8 [ type ] . V_106 , V_105 ) ;
if ( type == V_88 ) {
F_5 () ;
}
for ( V_32 = 0 ; V_32 < V_111 ; V_32 ++ ) {
if ( V_32 % 2 )
V_8 [ type ] . F_48 ( V_113 [ V_32 ] - V_112 ) ;
else
V_112 = V_8 [ type ] . F_49 ( V_113 [ V_32 ] ) ;
}
V_9 () ;
F_42 ( & V_8 [ type ] . V_106 , V_105 ) ;
F_50 ( V_113 ) ;
return V_109 ;
}
static long F_51 ( struct V_107 * V_117 , unsigned int V_118 , unsigned long V_119 )
{
int V_97 ;
T_8 T_5 * V_120 = ( T_8 T_5 * ) V_119 ;
T_8 V_5 ;
switch ( V_118 ) {
case V_121 :
if ( ! ( V_8 [ type ] . V_114 & V_122 ) )
return - V_123 ;
V_97 = F_52 ( F_53
( V_8 [ type ] . V_114 & V_122 ) ,
V_120 ) ;
if ( V_97 )
return V_97 ;
break;
case V_124 :
if ( ! ( V_8 [ type ] . V_114 & V_122 ) )
return - V_123 ;
V_97 = F_54 ( V_5 , V_120 ) ;
if ( V_97 )
return V_97 ;
if ( V_5 != V_125 )
return - V_28 ;
break;
case V_126 :
return - V_123 ;
break;
case V_127 :
F_10 ( L_23 ) ;
if ( ! ( V_8 [ type ] . V_114 & V_128 ) )
return - V_123 ;
V_97 = F_54 ( V_5 , V_120 ) ;
if ( V_97 )
return V_97 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_28 ;
return F_8 ( V_5 , V_17 ) ;
break;
case V_129 :
F_10 ( L_24 ) ;
if ( ! ( V_8 [ type ] . V_114 & V_130 ) )
return - V_123 ;
V_97 = F_54 ( V_5 , V_120 ) ;
if ( V_97 )
return V_97 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_28 ;
return F_8 ( V_16 , V_5 ) ;
break;
default:
return F_55 ( V_117 , V_118 , V_119 ) ;
}
return 0 ;
}
static int F_56 ( struct V_93 * V_94 ,
T_9 V_131 )
{
F_3 ( V_81 , F_1 ( V_81 ) & ( ~ V_82 ) ) ;
F_3 ( V_79 , F_1 ( V_79 ) &
( ~ ( V_83 | V_84 | V_85 | V_86 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_87 ) ;
F_1 ( V_63 ) ;
F_1 ( V_66 ) ;
return 0 ;
}
static int F_57 ( struct V_93 * V_94 )
{
unsigned long V_105 ;
int V_97 ;
V_97 = F_25 () ;
if ( V_97 < 0 )
return V_97 ;
F_41 ( & V_8 [ type ] . V_106 , V_105 ) ;
F_23 ( & V_72 ) ;
F_3 ( V_79 , F_1 ( V_79 ) | V_83 ) ;
V_9 () ;
F_58 ( & V_48 ) ;
F_42 ( & V_8 [ type ] . V_106 , V_105 ) ;
return 0 ;
}
static int T_10 F_59 ( void )
{
int V_97 ;
V_97 = F_60 ( & V_48 , sizeof( int ) , V_132 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_61 ( & V_133 ) ;
if ( V_97 ) {
F_62 ( L_25 , V_97 ) ;
goto V_134;
}
V_135 = F_63 ( L_26 , 0 ) ;
if ( ! V_135 ) {
V_97 = - V_136 ;
goto V_137;
}
V_97 = F_64 ( V_135 ) ;
if ( V_97 )
goto V_138;
return 0 ;
V_138:
F_65 ( V_135 ) ;
V_137:
F_66 ( & V_133 ) ;
V_134:
F_67 ( & V_48 ) ;
return V_97 ;
}
static void F_68 ( void )
{
F_69 ( V_135 ) ;
F_66 ( & V_133 ) ;
F_67 ( & V_48 ) ;
}
static int T_10 F_70 ( void )
{
int V_97 ;
switch ( type ) {
case V_139 :
case V_88 :
case V_89 :
case V_140 :
case V_141 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_98 = V_98 ? V_98 : 4 ;
break;
default:
return - V_28 ;
}
if ( ! V_46 ) {
switch ( type ) {
case V_139 :
case V_141 :
V_8 [ type ] . V_114 &=
~ ( V_128 |
V_130 ) ;
break;
}
}
if ( V_69 != - 1 )
V_69 = ! ! V_69 ;
V_97 = F_59 () ;
if ( V_97 )
return V_97 ;
V_142 . V_114 = V_8 [ type ] . V_114 ;
V_142 . V_94 = & V_135 -> V_94 ;
V_142 . V_143 = F_71 ( & V_142 ) ;
if ( V_142 . V_143 < 0 ) {
F_27 ( L_27 ) ;
F_68 () ;
return V_142 . V_143 ;
}
return 0 ;
}
static void T_11 F_72 ( void )
{
F_73 ( V_142 . V_143 ) ;
F_68 () ;
F_10 ( L_28 ) ;
}
