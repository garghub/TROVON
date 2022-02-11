static T_1 F_1 ( int V_1 )
{
if ( V_2 )
V_1 <<= V_3 ;
return F_2 ( V_4 + V_1 ) ;
}
static void F_3 ( int V_1 , T_1 V_5 )
{
if ( V_2 )
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
V_22 = V_14 >> 3 ;
V_22 /= ( V_17 >> 3 ) ;
V_23 = V_22 * V_16 / 100 ;
V_24 = V_22 - V_23 ;
F_10 ( L_1 ,
V_17 , V_16 , F_9 ( V_25 . V_20 ) ,
V_23 , V_24 , V_26 ) ;
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
V_22 = 256 * 1000000L / V_17 ;
V_23 = V_22 * V_16 / 100 ;
V_24 = V_22 - V_23 ;
F_10 ( L_2 ,
V_17 , V_23 , V_24 ) ;
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
V_29 <<= 8 ;
V_41 = 0 ; V_42 = 0 ; V_40 = 0 ;
while ( V_41 < V_29 ) {
if ( V_40 ) {
V_9 () ;
V_42 += V_24 ;
} else {
F_5 () ;
V_42 += V_23 ;
}
V_43 = ( V_42 - V_41 -
V_27 + 128 ) >> 8 ;
F_7 ( V_43 ) ;
V_41 += ( V_43 << 8 ) + V_27 ;
V_40 = ! V_40 ;
}
return ( V_41 - V_29 ) >> 8 ;
}
static long F_13 ( unsigned long V_29 )
{
if ( V_29 <= 0 )
return 0 ;
if ( V_44 )
return F_12 ( V_29 ) ;
F_5 () ;
F_6 ( V_29 ) ;
return 0 ;
}
static void F_14 ( long V_29 )
{
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_15 ( long V_29 )
{
V_9 () ;
if ( V_29 <= 0 )
return;
F_6 ( V_29 ) ;
}
static void F_16 ( int V_45 )
{
if ( F_17 ( & V_46 ) ) {
F_10 ( L_3 ) ;
return;
}
F_18 ( & V_46 , ( void * ) & V_45 ) ;
}
static void F_19 ( int V_45 )
{
static int V_47 , V_48 ;
static unsigned int V_49 ;
if ( V_49 > 0 && ( V_45 & V_50 ) ) {
V_47 += V_45 & V_51 ;
if ( V_47 > 250 ) {
F_16 ( V_48 ) ;
F_16 ( V_47 | V_50 ) ;
V_49 = 0 ;
V_47 = 0 ;
}
return;
}
if ( ! ( V_45 & V_50 ) ) {
if ( V_49 == 0 ) {
if ( V_45 > 20000 ) {
V_48 = V_45 ;
V_49 ++ ;
return;
}
} else {
if ( V_45 > 20000 ) {
V_48 += V_47 ;
if ( V_48 > V_51 )
V_48 = V_51 ;
V_48 += V_45 ;
if ( V_48 > V_51 )
V_48 = V_51 ;
V_47 = 0 ;
return;
}
F_16 ( V_48 ) ;
F_16 ( V_47 | V_50 ) ;
V_49 = 0 ;
V_47 = 0 ;
}
}
F_16 ( V_45 ) ;
}
static T_3 F_20 ( int V_32 , void * V_52 )
{
struct V_53 V_54 ;
int V_55 , V_56 ;
T_1 V_57 ;
long V_58 ;
int V_59 ;
static int V_60 = - 1 ;
if ( ( F_1 ( V_61 ) & V_62 ) ) {
return V_63 ;
}
V_55 = 0 ;
do {
V_55 ++ ;
V_57 = F_1 ( V_64 ) ;
if ( V_55 > V_65 ) {
F_21 ( L_4 ) ;
break;
}
if ( ( V_57 & V_8 [ type ] . V_66 )
&& V_67 != - 1 ) {
F_22 ( & V_54 ) ;
V_56 = ( V_57 & V_8 [ type ] . V_68 ) ? 1 : 0 ;
if ( V_56 == V_60 ) {
F_21 ( L_5 ,
V_56 , V_67 ,
V_54 . V_69 , V_70 . V_69 ,
( unsigned long ) V_54 . V_71 ,
( unsigned long ) V_70 . V_71 ) ;
continue;
}
V_58 = V_54 . V_69 - V_70 . V_69 ;
if ( V_54 . V_69 < V_70 . V_69 ||
( V_54 . V_69 == V_70 . V_69 &&
V_54 . V_71 < V_70 . V_71 ) ) {
F_21 ( L_6 ) ;
F_21 ( L_7 ,
V_56 , V_67 ,
V_54 . V_69 , V_70 . V_69 ,
( unsigned long ) V_54 . V_71 ,
( unsigned long ) V_70 . V_71 ) ;
V_59 = V_51 ;
} else if ( V_58 > 15 ) {
V_59 = V_51 ;
if ( ! ( V_56 ^ V_67 ) ) {
F_21 ( L_8 ,
V_56 , V_67 ,
V_54 . V_69 , V_70 . V_69 ,
( unsigned long ) V_54 . V_71 ,
( unsigned long ) V_70 . V_71 ) ;
V_67 = V_67 ? 0 : 1 ;
}
} else
V_59 = ( int ) ( V_58 * 1000000 +
V_54 . V_71 -
V_70 . V_71 ) ;
F_19 ( V_56 ^ V_67 ? V_59 : ( V_59 | V_50 ) ) ;
V_70 = V_54 ;
V_60 = V_56 ;
F_23 ( & V_46 . V_72 ) ;
}
} while ( ! ( F_1 ( V_61 ) & V_62 ) );
return V_73 ;
}
static int F_24 ( void )
{
T_1 V_74 , V_75 , V_76 ;
V_74 = F_1 ( V_77 ) ;
F_3 ( V_77 , 0 ) ;
#ifdef F_25
F_4 ( 0xff , 0x080 ) ;
#endif
V_75 = F_1 ( V_77 ) & 0x0f ;
F_3 ( V_77 , 0x0f ) ;
#ifdef F_25
F_4 ( 0x00 , 0x080 ) ;
#endif
V_76 = F_1 ( V_77 ) & 0x0f ;
F_3 ( V_77 , V_74 ) ;
if ( V_75 != 0 || V_76 != 0x0f ) {
F_26 ( L_9 ) ;
return - V_78 ;
}
F_3 ( V_79 , F_1 ( V_79 ) & ( ~ V_80 ) ) ;
F_3 ( V_77 , F_1 ( V_77 ) &
( ~ ( V_81 | V_82 | V_83 | V_84 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_85 ) ;
F_1 ( V_61 ) ;
F_1 ( V_64 ) ;
V_9 () ;
F_1 ( V_37 ) ;
F_1 ( V_85 ) ;
F_1 ( V_61 ) ;
F_1 ( V_64 ) ;
switch ( type ) {
case V_86 :
case V_87 :
F_3 ( V_79 , F_1 ( V_79 ) | V_80 ) ;
F_3 ( V_88 , 0 ) ;
F_3 ( V_89 , 1 ) ;
F_3 ( V_79 , V_90 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_27 ( struct V_91 * V_92 )
{
int V_32 , V_93 , V_94 , V_95 ;
V_95 = F_28 ( & V_92 -> V_92 , V_96 , F_20 ,
( V_97 ? V_98 : 0 ) ,
V_99 , & V_8 ) ;
if ( V_95 < 0 ) {
if ( V_95 == - V_100 )
F_29 ( & V_92 -> V_92 , L_10 , V_96 ) ;
else if ( V_95 == - V_28 )
F_29 ( & V_92 -> V_92 , L_11 ) ;
return V_95 ;
}
if ( ( ( V_2 )
&& ( F_30 ( & V_92 -> V_92 , V_2 , 8 << V_3 ,
V_99 ) == NULL ) )
|| ( ( ! V_2 )
&& ( F_31 ( & V_92 -> V_92 , V_4 , 8 ,
V_99 ) == NULL ) ) ) {
F_29 ( & V_92 -> V_92 , L_12 , V_4 ) ;
F_32 ( & V_92 -> V_92 , L_13 ) ;
F_32 ( & V_92 -> V_92 ,
L_14 ) ;
F_32 ( & V_92 -> V_92 , L_15 ) ;
return - V_100 ;
}
V_95 = F_24 () ;
if ( V_95 < 0 )
return V_95 ;
F_8 ( V_16 , V_17 ) ;
if ( V_67 == - 1 ) {
F_33 ( 500 ) ;
V_93 = 0 ;
V_94 = 0 ;
for ( V_32 = 0 ; V_32 < 9 ; V_32 ++ ) {
if ( F_1 ( V_64 ) & V_8 [ type ] . V_68 )
V_93 ++ ;
else
V_94 ++ ;
F_33 ( 40 ) ;
}
V_67 = V_93 >= V_94 ? 1 : 0 ;
F_34 ( & V_92 -> V_92 , L_16 ,
V_67 ? L_17 : L_18 ) ;
} else
F_34 ( & V_92 -> V_92 , L_19 ,
V_67 ? L_17 : L_18 ) ;
F_35 ( & V_92 -> V_92 , L_20 , V_96 , V_4 ) ;
return 0 ;
}
static int F_36 ( void * V_59 )
{
unsigned long V_101 ;
F_22 ( & V_70 ) ;
F_37 ( & V_8 [ type ] . V_102 , V_101 ) ;
F_3 ( V_79 , F_1 ( V_79 ) & ( ~ V_80 ) ) ;
F_3 ( V_77 , F_1 ( V_77 ) | V_81 ) ;
F_38 ( & V_8 [ type ] . V_102 , V_101 ) ;
return 0 ;
}
static void F_39 ( void * V_59 )
{ unsigned long V_101 ;
F_37 ( & V_8 [ type ] . V_102 , V_101 ) ;
F_3 ( V_79 , F_1 ( V_79 ) & ( ~ V_80 ) ) ;
F_3 ( V_77 , F_1 ( V_77 ) &
( ~ ( V_81 | V_82 | V_83 | V_84 ) ) ) ;
F_38 ( & V_8 [ type ] . V_102 , V_101 ) ;
}
static T_4 F_40 ( struct V_103 * V_103 , const char T_5 * V_104 ,
T_6 V_105 , T_7 * V_106 )
{
int V_32 , V_107 ;
unsigned long V_101 ;
long V_108 = 0 ;
int * V_109 ;
if ( ! ( V_8 [ type ] . V_110 & V_111 ) )
return - V_112 ;
V_107 = V_105 / sizeof( int ) ;
if ( V_105 % sizeof( int ) || V_107 % 2 == 0 )
return - V_28 ;
V_109 = F_41 ( V_104 , V_105 ) ;
if ( F_42 ( V_109 ) )
return F_43 ( V_109 ) ;
F_37 ( & V_8 [ type ] . V_102 , V_101 ) ;
if ( type == V_86 ) {
F_5 () ;
}
for ( V_32 = 0 ; V_32 < V_107 ; V_32 ++ ) {
if ( V_32 % 2 )
V_8 [ type ] . F_44 ( V_109 [ V_32 ] - V_108 ) ;
else
V_108 = V_8 [ type ] . F_45 ( V_109 [ V_32 ] ) ;
}
V_9 () ;
F_38 ( & V_8 [ type ] . V_102 , V_101 ) ;
F_46 ( V_109 ) ;
return V_105 ;
}
static long F_47 ( struct V_103 * V_113 , unsigned int V_114 , unsigned long V_115 )
{
int V_95 ;
T_8 T_5 * V_116 = ( T_8 T_5 * ) V_115 ;
T_8 V_5 ;
switch ( V_114 ) {
case V_117 :
if ( ! ( V_8 [ type ] . V_110 & V_118 ) )
return - V_119 ;
V_95 = F_48 ( F_49
( V_8 [ type ] . V_110 & V_118 ) ,
V_116 ) ;
if ( V_95 )
return V_95 ;
break;
case V_120 :
if ( ! ( V_8 [ type ] . V_110 & V_118 ) )
return - V_119 ;
V_95 = F_50 ( V_5 , V_116 ) ;
if ( V_95 )
return V_95 ;
if ( V_5 != V_121 )
return - V_28 ;
break;
case V_122 :
return - V_119 ;
case V_123 :
F_10 ( L_21 ) ;
if ( ! ( V_8 [ type ] . V_110 & V_124 ) )
return - V_119 ;
V_95 = F_50 ( V_5 , V_116 ) ;
if ( V_95 )
return V_95 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_28 ;
return F_8 ( V_5 , V_17 ) ;
case V_125 :
F_10 ( L_22 ) ;
if ( ! ( V_8 [ type ] . V_110 & V_126 ) )
return - V_119 ;
V_95 = F_50 ( V_5 , V_116 ) ;
if ( V_95 )
return V_95 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_28 ;
return F_8 ( V_16 , V_5 ) ;
default:
return F_51 ( V_113 , V_114 , V_115 ) ;
}
return 0 ;
}
static int F_52 ( struct V_91 * V_92 ,
T_9 V_127 )
{
F_3 ( V_79 , F_1 ( V_79 ) & ( ~ V_80 ) ) ;
F_3 ( V_77 , F_1 ( V_77 ) &
( ~ ( V_81 | V_82 | V_83 | V_84 ) ) ) ;
F_1 ( V_37 ) ;
F_1 ( V_85 ) ;
F_1 ( V_61 ) ;
F_1 ( V_64 ) ;
return 0 ;
}
static int F_53 ( struct V_91 * V_92 )
{
unsigned long V_101 ;
int V_95 ;
V_95 = F_24 () ;
if ( V_95 < 0 )
return V_95 ;
F_37 ( & V_8 [ type ] . V_102 , V_101 ) ;
F_22 ( & V_70 ) ;
F_3 ( V_77 , F_1 ( V_77 ) | V_81 ) ;
V_9 () ;
F_54 ( & V_46 ) ;
F_38 ( & V_8 [ type ] . V_102 , V_101 ) ;
return 0 ;
}
static int T_10 F_55 ( void )
{
int V_95 ;
V_95 = F_56 ( & V_46 , sizeof( int ) , V_128 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_57 ( & V_129 ) ;
if ( V_95 ) {
F_58 ( L_23 , V_95 ) ;
goto V_130;
}
V_131 = F_59 ( L_24 , 0 ) ;
if ( ! V_131 ) {
V_95 = - V_132 ;
goto V_133;
}
V_95 = F_60 ( V_131 ) ;
if ( V_95 )
goto V_134;
return 0 ;
V_134:
F_61 ( V_131 ) ;
V_133:
F_62 ( & V_129 ) ;
V_130:
F_63 ( & V_46 ) ;
return V_95 ;
}
static void F_64 ( void )
{
F_65 ( V_131 ) ;
F_62 ( & V_129 ) ;
F_63 ( & V_46 ) ;
}
static int T_10 F_66 ( void )
{
int V_95 ;
switch ( type ) {
case V_135 :
case V_86 :
case V_87 :
case V_136 :
case V_137 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_96 = V_96 ? V_96 : 4 ;
break;
default:
return - V_28 ;
}
if ( ! V_44 ) {
switch ( type ) {
case V_135 :
case V_137 :
V_8 [ type ] . V_110 &=
~ ( V_124 |
V_126 ) ;
break;
}
}
if ( V_67 != - 1 )
V_67 = ! ! V_67 ;
V_95 = F_55 () ;
if ( V_95 )
return V_95 ;
V_138 . V_110 = V_8 [ type ] . V_110 ;
V_138 . V_92 = & V_131 -> V_92 ;
V_138 . V_139 = F_67 ( & V_138 ) ;
if ( V_138 . V_139 < 0 ) {
F_26 ( L_25 ) ;
F_64 () ;
return V_138 . V_139 ;
}
return 0 ;
}
static void T_11 F_68 ( void )
{
F_69 ( V_138 . V_139 ) ;
F_64 () ;
F_10 ( L_26 ) ;
}
