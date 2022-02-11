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
#ifdef F_6
if ( type == V_6 ) {
F_7 ( V_7 , 0 ) ;
return;
}
#endif
if ( V_8 )
F_3 ( V_9 , V_10 [ type ] . V_11 ) ;
else
F_3 ( V_9 , V_10 [ type ] . F_5 ) ;
}
static void V_11 ( void )
{
#ifdef F_6
if ( type == V_6 ) {
F_7 ( V_7 , 1 ) ;
return;
}
#endif
if ( V_8 )
F_3 ( V_9 , V_10 [ type ] . F_5 ) ;
else
F_3 ( V_9 , V_10 [ type ] . V_11 ) ;
}
static void F_8 ( unsigned long V_12 )
{
while ( V_12 > V_13 ) {
F_9 ( V_13 ) ;
V_12 -= V_13 ;
}
F_9 ( V_12 ) ;
}
static int F_10 ( unsigned int V_14 ,
unsigned int V_15 )
{
T_2 V_16 , V_17 ;
V_18 = V_14 ;
V_19 = V_15 ;
V_16 = F_11 ( V_20 . V_21 . V_22 ) ;
V_16 *= V_23 ;
V_17 = V_16 ;
V_17 *= 4295 ;
V_24 = ( V_17 >> 32 ) ;
V_25 = V_16 >> 3 ;
V_25 /= ( V_19 >> 3 ) ;
V_26 = V_25 * V_18 / 100 ;
V_27 = V_25 - V_26 ;
F_12 ( L_1
L_2
L_3 ,
V_19 , V_18 , F_11 ( V_28 . V_22 ) ,
V_26 , V_27 , V_24 ) ;
return 0 ;
}
static int F_10 ( unsigned int V_14 ,
unsigned int V_15 )
{
if ( 256 * 1000000L / V_15 * V_14 / 100 <=
V_29 )
return - V_30 ;
if ( 256 * 1000000L / V_15 * ( 100 - V_14 ) / 100 <=
V_29 )
return - V_30 ;
V_18 = V_14 ;
V_19 = V_15 ;
V_25 = 256 * 1000000L / V_19 ;
V_26 = V_25 * V_18 / 100 ;
V_27 = V_25 - V_26 ;
F_12 ( L_4
L_5 , V_19 , V_26 , V_27 ) ;
return 0 ;
}
static long F_13 ( unsigned long V_31 )
{
long V_32 , V_33 ;
int V_34 ;
unsigned char V_35 ;
unsigned char V_36 , V_37 ;
V_32 = V_31 * 1152 / 10000 ;
if ( V_18 > 50 )
V_36 = 3 ;
else
V_36 = 1 ;
for ( V_34 = 0 , V_35 = 0x7f ; V_32 > 0 ; V_32 -= 3 ) {
V_37 = V_36 << ( V_34 * 3 ) ;
V_37 >>= 1 ;
V_35 &= ( ~ V_37 ) ;
V_34 ++ ;
if ( V_34 == 3 ) {
F_3 ( V_38 , V_35 ) ;
while ( ! ( F_1 ( V_39 ) & V_40 ) )
;
V_35 = 0x7f ;
V_34 = 0 ;
}
}
if ( V_34 != 0 ) {
F_3 ( V_38 , V_35 ) ;
while ( ! ( F_1 ( V_39 ) & V_41 ) )
;
}
if ( V_34 == 0 )
V_33 = ( - V_32 ) * 10000 / 1152 ;
else
V_33 = ( 3 - V_34 ) * 3 * 10000 / 1152 + ( - V_32 ) * 10000 / 1152 ;
return V_33 ;
}
static long F_14 ( unsigned long V_31 )
{
int V_42 ;
unsigned long V_43 , V_44 , V_45 ;
F_15 ( V_44 ) ;
F_5 () ;
V_31 *= V_24 ;
V_45 = V_44 ;
V_43 = V_26 ;
V_42 = 1 ;
while ( ( V_45 - V_44 ) < V_31 ) {
do {
F_15 ( V_45 ) ;
} while ( ( V_45 - V_44 ) < V_43 );
if ( V_42 ) {
F_15 ( V_45 ) ;
V_11 () ;
V_43 += V_27 ;
} else {
F_15 ( V_45 ) ; F_5 () ;
V_43 += V_26 ;
}
V_42 = ! V_42 ;
}
F_15 ( V_45 ) ;
return ( ( V_45 - V_44 ) - V_31 ) / V_24 ;
}
static long F_14 ( unsigned long V_31 )
{
int V_42 ;
unsigned long V_46 , V_43 , V_47 ;
V_31 <<= 8 ;
V_46 = 0 ; V_43 = 0 ; V_42 = 0 ;
while ( V_46 < V_31 ) {
if ( V_42 ) {
V_11 () ;
V_43 += V_27 ;
} else {
F_5 () ;
V_43 += V_26 ;
}
V_47 = ( V_43 - V_46 -
V_29 + 128 ) >> 8 ;
F_9 ( V_47 ) ;
V_46 += ( V_47 << 8 ) + V_29 ;
V_42 = ! V_42 ;
}
return ( V_46 - V_31 ) >> 8 ;
}
static long F_16 ( unsigned long V_31 )
{
if ( V_31 <= 0 )
return 0 ;
if ( V_48 )
return F_14 ( V_31 ) ;
else {
F_5 () ;
F_8 ( V_31 ) ;
return 0 ;
}
}
static void F_17 ( long V_31 )
{
if ( V_31 <= 0 )
return;
F_8 ( V_31 ) ;
}
static void F_18 ( long V_31 )
{
V_11 () ;
if ( V_31 <= 0 )
return;
F_8 ( V_31 ) ;
}
static void F_19 ( int V_49 )
{
if ( F_20 ( & V_50 ) ) {
F_12 ( L_6 ) ;
return;
}
F_21 ( & V_50 , ( void * ) & V_49 ) ;
}
static void F_22 ( int V_49 )
{
static int V_51 , V_52 ;
static unsigned int V_53 ;
if ( V_53 > 0 && ( V_49 & V_54 ) ) {
V_51 += V_49 & V_55 ;
if ( V_51 > 250 ) {
F_19 ( V_52 ) ;
F_19 ( V_51 | V_54 ) ;
V_53 = 0 ;
V_51 = 0 ;
}
return;
}
if ( ! ( V_49 & V_54 ) ) {
if ( V_53 == 0 ) {
if ( V_49 > 20000 ) {
V_52 = V_49 ;
V_53 ++ ;
return;
}
} else {
if ( V_49 > 20000 ) {
V_52 += V_51 ;
if ( V_52 > V_55 )
V_52 = V_55 ;
V_52 += V_49 ;
if ( V_52 > V_55 )
V_52 = V_55 ;
V_51 = 0 ;
return;
}
F_19 ( V_52 ) ;
F_19 ( V_51 | V_54 ) ;
V_53 = 0 ;
V_51 = 0 ;
}
}
F_19 ( V_49 ) ;
}
static T_3 F_23 ( int V_34 , void * V_56 )
{
struct V_57 V_58 ;
int V_59 , V_60 ;
T_1 V_61 ;
long V_62 ;
int V_63 ;
static int V_64 = - 1 ;
if ( ( F_1 ( V_65 ) & V_66 ) ) {
return V_67 ;
}
V_59 = 0 ;
do {
V_59 ++ ;
V_61 = F_1 ( V_68 ) ;
if ( V_59 > V_69 ) {
F_24 ( L_7 ) ;
break;
}
if ( ( V_61 & V_10 [ type ] . V_70 )
&& V_71 != - 1 ) {
F_25 ( & V_58 ) ;
V_60 = ( V_61 & V_10 [ type ] . V_72 ) ? 1 : 0 ;
if ( V_60 == V_64 ) {
F_24 ( L_8 ,
V_60 , V_71 ,
V_58 . V_73 , V_74 . V_73 ,
( unsigned long ) V_58 . V_75 ,
( unsigned long ) V_74 . V_75 ) ;
continue;
}
V_62 = V_58 . V_73 - V_74 . V_73 ;
if ( V_58 . V_73 < V_74 . V_73 ||
( V_58 . V_73 == V_74 . V_73 &&
V_58 . V_75 < V_74 . V_75 ) ) {
F_24 ( L_9 ) ;
F_24 ( L_10 ,
V_60 , V_71 ,
V_58 . V_73 , V_74 . V_73 ,
( unsigned long ) V_58 . V_75 ,
( unsigned long ) V_74 . V_75 ) ;
V_63 = V_55 ;
} else if ( V_62 > 15 ) {
V_63 = V_55 ;
if ( ! ( V_60 ^ V_71 ) ) {
F_24 ( L_11 ,
V_60 , V_71 ,
V_58 . V_73 , V_74 . V_73 ,
( unsigned long ) V_58 . V_75 ,
( unsigned long ) V_74 . V_75 ) ;
V_71 = V_71 ? 0 : 1 ;
}
} else
V_63 = ( int ) ( V_62 * 1000000 +
V_58 . V_75 -
V_74 . V_75 ) ;
F_22 ( V_60 ^ V_71 ? V_63 : ( V_63 | V_54 ) ) ;
V_74 = V_58 ;
V_64 = V_60 ;
F_26 ( & V_50 . V_76 ) ;
}
} while ( ! ( F_1 ( V_65 ) & V_66 ) );
return V_77 ;
}
static int F_27 ( void )
{
T_1 V_78 , V_79 , V_80 ;
V_78 = F_1 ( V_81 ) ;
F_3 ( V_81 , 0 ) ;
#ifdef F_28
F_4 ( 0xff , 0x080 ) ;
#endif
V_79 = F_1 ( V_81 ) & 0x0f ;
F_3 ( V_81 , 0x0f ) ;
#ifdef F_28
F_4 ( 0x00 , 0x080 ) ;
#endif
V_80 = F_1 ( V_81 ) & 0x0f ;
F_3 ( V_81 , V_78 ) ;
if ( V_79 != 0 || V_80 != 0x0f ) {
F_29 ( L_12 ) ;
return - V_82 ;
}
F_3 ( V_83 , F_1 ( V_83 ) & ( ~ V_84 ) ) ;
F_3 ( V_81 , F_1 ( V_81 ) &
( ~ ( V_85 | V_86 | V_87 | V_88 ) ) ) ;
F_1 ( V_39 ) ;
F_1 ( V_89 ) ;
F_1 ( V_65 ) ;
F_1 ( V_68 ) ;
#ifdef F_6
if ( type == V_6 ) {
F_3 ( V_81 , F_1 ( V_81 ) | V_90 ) ;
F_3 ( V_81 , F_1 ( V_81 ) & ~ V_91 ) ;
F_3 ( V_9 , V_92 | V_93 ) ;
}
#endif
V_11 () ;
F_1 ( V_39 ) ;
F_1 ( V_89 ) ;
F_1 ( V_65 ) ;
F_1 ( V_68 ) ;
switch ( type ) {
case V_94 :
case V_95 :
F_3 ( V_83 , F_1 ( V_83 ) | V_84 ) ;
F_3 ( V_96 , 0 ) ;
F_3 ( V_97 , 1 ) ;
F_3 ( V_83 , V_98 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_99 * V_100 )
{
int V_34 , V_101 , V_102 , V_103 ;
#ifdef F_6
V_103 = F_31 ( V_100 , V_7 , L_13 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_32 ( V_7 , 0 ) ;
if ( V_103 )
return V_103 ;
#endif
V_103 = F_33 ( V_104 , F_23 ,
( V_105 ? V_106 : 0 ) ,
V_107 , ( void * ) & V_10 ) ;
if ( V_103 < 0 ) {
if ( V_103 == - V_108 )
F_34 ( & V_100 -> V_100 , L_14 , V_104 ) ;
else if ( V_103 == - V_30 )
F_34 ( & V_100 -> V_100 , L_15 ) ;
return V_103 ;
}
if ( ( ( V_2 != 0 )
&& ( F_35 ( V_2 , 8 << V_3 ,
V_107 ) == NULL ) )
|| ( ( V_2 == 0 )
&& ( F_36 ( V_4 , 8 , V_107 ) == NULL ) ) ) {
F_34 ( & V_100 -> V_100 , L_16 , V_4 ) ;
F_37 ( & V_100 -> V_100 , L_17 ) ;
F_37 ( & V_100 -> V_100 ,
L_18 ) ;
F_37 ( & V_100 -> V_100 , L_19 ) ;
V_103 = - V_108 ;
goto V_109;
}
V_103 = F_27 () ;
if ( V_103 < 0 )
goto V_110;
F_10 ( V_18 , V_19 ) ;
if ( V_71 == - 1 ) {
F_38 ( 500 ) ;
V_101 = 0 ;
V_102 = 0 ;
for ( V_34 = 0 ; V_34 < 9 ; V_34 ++ ) {
if ( F_1 ( V_68 ) & V_10 [ type ] . V_72 )
V_101 ++ ;
else
V_102 ++ ;
F_38 ( 40 ) ;
}
V_71 = ( V_101 >= V_102 ? 1 : 0 ) ;
F_39 ( & V_100 -> V_100 , L_20 ,
V_71 ? L_21 : L_22 ) ;
} else
F_39 ( & V_100 -> V_100 , L_23 ,
V_71 ? L_21 : L_22 ) ;
F_12 ( L_24 , V_104 , V_4 ) ;
return 0 ;
V_110:
if ( V_2 != 0 )
F_40 ( V_2 , 8 << V_3 ) ;
else
F_41 ( V_4 , 8 ) ;
V_109:
F_42 ( V_104 , ( void * ) & V_10 ) ;
return V_103 ;
}
static int F_43 ( struct V_99 * V_100 )
{
F_42 ( V_104 , ( void * ) & V_10 ) ;
if ( V_2 != 0 )
F_40 ( V_2 , 8 << V_3 ) ;
else
F_41 ( V_4 , 8 ) ;
return 0 ;
}
static int F_44 ( void * V_63 )
{
unsigned long V_111 ;
F_25 ( & V_74 ) ;
F_45 ( & V_10 [ type ] . V_112 , V_111 ) ;
F_3 ( V_83 , F_1 ( V_83 ) & ( ~ V_84 ) ) ;
F_3 ( V_81 , F_1 ( V_81 ) | V_85 ) ;
F_46 ( & V_10 [ type ] . V_112 , V_111 ) ;
return 0 ;
}
static void F_47 ( void * V_63 )
{ unsigned long V_111 ;
F_45 ( & V_10 [ type ] . V_112 , V_111 ) ;
F_3 ( V_83 , F_1 ( V_83 ) & ( ~ V_84 ) ) ;
F_3 ( V_81 , F_1 ( V_81 ) &
( ~ ( V_85 | V_86 | V_87 | V_88 ) ) ) ;
F_46 ( & V_10 [ type ] . V_112 , V_111 ) ;
}
static T_4 F_48 ( struct V_113 * V_113 , const char * V_114 ,
T_5 V_115 , T_6 * V_116 )
{
int V_34 , V_117 ;
unsigned long V_111 ;
long V_118 = 0 ;
int * V_119 ;
if ( ! ( V_10 [ type ] . V_120 & V_121 ) )
return - V_122 ;
V_117 = V_115 / sizeof( int ) ;
if ( V_115 % sizeof( int ) || V_117 % 2 == 0 )
return - V_30 ;
V_119 = F_49 ( V_114 , V_115 ) ;
if ( F_50 ( V_119 ) )
return F_51 ( V_119 ) ;
F_45 ( & V_10 [ type ] . V_112 , V_111 ) ;
if ( type == V_94 ) {
F_5 () ;
}
for ( V_34 = 0 ; V_34 < V_117 ; V_34 ++ ) {
if ( V_34 % 2 )
V_10 [ type ] . F_52 ( V_119 [ V_34 ] - V_118 ) ;
else
V_118 = V_10 [ type ] . F_53 ( V_119 [ V_34 ] ) ;
}
V_11 () ;
F_46 ( & V_10 [ type ] . V_112 , V_111 ) ;
F_54 ( V_119 ) ;
return V_115 ;
}
static long F_55 ( struct V_113 * V_123 , unsigned int V_124 , unsigned long V_125 )
{
int V_103 ;
T_7 V_5 ;
switch ( V_124 ) {
case V_126 :
if ( ! ( V_10 [ type ] . V_120 & V_127 ) )
return - V_128 ;
V_103 = F_56 ( F_57
( V_10 [ type ] . V_120 & V_127 ) ,
( T_7 * ) V_125 ) ;
if ( V_103 )
return V_103 ;
break;
case V_129 :
if ( ! ( V_10 [ type ] . V_120 & V_127 ) )
return - V_128 ;
V_103 = F_58 ( V_5 , ( T_7 * ) V_125 ) ;
if ( V_103 )
return V_103 ;
if ( V_5 != V_130 )
return - V_30 ;
break;
case V_131 :
return - V_128 ;
break;
case V_132 :
F_12 ( L_25 ) ;
if ( ! ( V_10 [ type ] . V_120 & V_133 ) )
return - V_128 ;
V_103 = F_58 ( V_5 , ( T_7 * ) V_125 ) ;
if ( V_103 )
return V_103 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_30 ;
return F_10 ( V_5 , V_19 ) ;
break;
case V_134 :
F_12 ( L_26 ) ;
if ( ! ( V_10 [ type ] . V_120 & V_135 ) )
return - V_128 ;
V_103 = F_58 ( V_5 , ( T_7 * ) V_125 ) ;
if ( V_103 )
return V_103 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_30 ;
return F_10 ( V_18 , V_5 ) ;
break;
default:
return F_59 ( V_123 , V_124 , V_125 ) ;
}
return 0 ;
}
static int F_60 ( struct V_99 * V_100 ,
T_8 V_136 )
{
F_3 ( V_83 , F_1 ( V_83 ) & ( ~ V_84 ) ) ;
F_3 ( V_81 , F_1 ( V_81 ) &
( ~ ( V_85 | V_86 | V_87 | V_88 ) ) ) ;
F_1 ( V_39 ) ;
F_1 ( V_89 ) ;
F_1 ( V_65 ) ;
F_1 ( V_68 ) ;
return 0 ;
}
static int F_61 ( struct V_99 * V_100 )
{
unsigned long V_111 ;
int V_103 ;
V_103 = F_27 () ;
if ( V_103 < 0 )
return V_103 ;
F_45 ( & V_10 [ type ] . V_112 , V_111 ) ;
F_25 ( & V_74 ) ;
F_3 ( V_81 , F_1 ( V_81 ) | V_85 ) ;
V_11 () ;
F_62 ( & V_50 ) ;
F_46 ( & V_10 [ type ] . V_112 , V_111 ) ;
return 0 ;
}
static int T_9 F_63 ( void )
{
int V_103 ;
V_103 = F_64 ( & V_50 , sizeof( int ) , V_137 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_65 ( & V_138 ) ;
if ( V_103 ) {
F_66 ( L_27 , V_103 ) ;
goto V_139;
}
V_140 = F_67 ( L_28 , 0 ) ;
if ( ! V_140 ) {
V_103 = - V_141 ;
goto V_142;
}
V_103 = F_68 ( V_140 ) ;
if ( V_103 )
goto V_143;
return 0 ;
V_143:
F_69 ( V_140 ) ;
V_142:
F_70 ( & V_138 ) ;
V_139:
F_71 ( & V_50 ) ;
return V_103 ;
}
static void F_72 ( void )
{
F_73 ( V_140 ) ;
F_70 ( & V_138 ) ;
F_71 ( & V_50 ) ;
}
static int T_9 F_74 ( void )
{
int V_103 ;
switch ( type ) {
case V_144 :
case V_94 :
case V_95 :
case V_145 :
case V_146 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_104 = V_104 ? V_104 : 4 ;
break;
#ifdef F_6
case V_6 :
V_4 = V_4 ? V_4 : V_147 ;
V_104 = V_104 ? V_104 : ( V_148 + V_149 ) ;
V_2 = V_2 ? V_2 : V_150 ;
V_3 = V_3 ? V_3 : 2 ;
break;
#endif
default:
return - V_30 ;
}
if ( ! V_48 ) {
switch ( type ) {
case V_144 :
case V_146 :
#ifdef F_6
case V_6 :
#endif
V_10 [ type ] . V_120 &=
~ ( V_133 |
V_135 ) ;
break;
}
}
if ( V_71 != - 1 )
V_71 = ! ! V_71 ;
V_103 = F_63 () ;
if ( V_103 )
return V_103 ;
V_151 . V_120 = V_10 [ type ] . V_120 ;
V_151 . V_100 = & V_140 -> V_100 ;
V_151 . V_152 = F_75 ( & V_151 ) ;
if ( V_151 . V_152 < 0 ) {
F_29 ( L_29 ) ;
F_72 () ;
return V_151 . V_152 ;
}
return 0 ;
}
static void T_10 F_76 ( void )
{
F_77 ( V_151 . V_152 ) ;
F_72 () ;
F_12 ( L_30 ) ;
}
