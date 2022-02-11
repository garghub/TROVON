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
F_10 ( L_1
L_2 ,
V_17 , V_16 , F_9 ( V_25 . V_20 ) ,
V_23 , V_24 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_12 ,
unsigned int V_13 )
{
if ( 256 * 1000000L / V_13 * V_12 / 100 <=
V_26 )
return - V_27 ;
if ( 256 * 1000000L / V_13 * ( 100 - V_12 ) / 100 <=
V_26 )
return - V_27 ;
V_16 = V_12 ;
V_17 = V_13 ;
V_22 = 256 * 1000000L / V_17 ;
V_23 = V_22 * V_16 / 100 ;
V_24 = V_22 - V_23 ;
F_10 ( L_3 ,
V_17 , V_23 , V_24 ) ;
return 0 ;
}
static long F_11 ( unsigned long V_28 )
{
long V_29 , V_30 ;
int V_31 ;
unsigned char V_32 ;
unsigned char V_33 , V_34 ;
V_29 = V_28 * 1152 / 10000 ;
if ( V_16 > 50 )
V_33 = 3 ;
else
V_33 = 1 ;
for ( V_31 = 0 , V_32 = 0x7f ; V_29 > 0 ; V_29 -= 3 ) {
V_34 = V_33 << ( V_31 * 3 ) ;
V_34 >>= 1 ;
V_32 &= ( ~ V_34 ) ;
V_31 ++ ;
if ( V_31 == 3 ) {
F_3 ( V_35 , V_32 ) ;
while ( ! ( F_1 ( V_36 ) & V_37 ) )
;
V_32 = 0x7f ;
V_31 = 0 ;
}
}
if ( V_31 != 0 ) {
F_3 ( V_35 , V_32 ) ;
while ( ! ( F_1 ( V_36 ) & V_38 ) )
;
}
if ( V_31 == 0 )
V_30 = ( - V_29 ) * 10000 / 1152 ;
else
V_30 = ( 3 - V_31 ) * 3 * 10000 / 1152 + ( - V_29 ) * 10000 / 1152 ;
return V_30 ;
}
static long F_12 ( unsigned long V_28 )
{
int V_39 ;
unsigned long V_40 , V_41 , V_42 ;
V_28 <<= 8 ;
V_40 = 0 ; V_41 = 0 ; V_39 = 0 ;
while ( V_40 < V_28 ) {
if ( V_39 ) {
V_9 () ;
V_41 += V_24 ;
} else {
F_5 () ;
V_41 += V_23 ;
}
V_42 = ( V_41 - V_40 -
V_26 + 128 ) >> 8 ;
F_7 ( V_42 ) ;
V_40 += ( V_42 << 8 ) + V_26 ;
V_39 = ! V_39 ;
}
return ( V_40 - V_28 ) >> 8 ;
}
static long F_13 ( unsigned long V_28 )
{
if ( V_28 <= 0 )
return 0 ;
if ( V_43 )
return F_12 ( V_28 ) ;
F_5 () ;
F_6 ( V_28 ) ;
return 0 ;
}
static void F_14 ( long V_28 )
{
if ( V_28 <= 0 )
return;
F_6 ( V_28 ) ;
}
static void F_15 ( long V_28 )
{
V_9 () ;
if ( V_28 <= 0 )
return;
F_6 ( V_28 ) ;
}
static void F_16 ( int V_44 )
{
if ( F_17 ( & V_45 ) ) {
F_10 ( L_4 ) ;
return;
}
F_18 ( & V_45 , ( void * ) & V_44 ) ;
}
static void F_19 ( int V_44 )
{
static int V_46 , V_47 ;
static unsigned int V_48 ;
if ( V_48 > 0 && ( V_44 & V_49 ) ) {
V_46 += V_44 & V_50 ;
if ( V_46 > 250 ) {
F_16 ( V_47 ) ;
F_16 ( V_46 | V_49 ) ;
V_48 = 0 ;
V_46 = 0 ;
}
return;
}
if ( ! ( V_44 & V_49 ) ) {
if ( V_48 == 0 ) {
if ( V_44 > 20000 ) {
V_47 = V_44 ;
V_48 ++ ;
return;
}
} else {
if ( V_44 > 20000 ) {
V_47 += V_46 ;
if ( V_47 > V_50 )
V_47 = V_50 ;
V_47 += V_44 ;
if ( V_47 > V_50 )
V_47 = V_50 ;
V_46 = 0 ;
return;
}
F_16 ( V_47 ) ;
F_16 ( V_46 | V_49 ) ;
V_48 = 0 ;
V_46 = 0 ;
}
}
F_16 ( V_44 ) ;
}
static T_3 F_20 ( int V_31 , void * V_51 )
{
struct V_52 V_53 ;
int V_54 , V_55 ;
T_1 V_56 ;
long V_57 ;
int V_58 ;
static int V_59 = - 1 ;
if ( ( F_1 ( V_60 ) & V_61 ) ) {
return V_62 ;
}
V_54 = 0 ;
do {
V_54 ++ ;
V_56 = F_1 ( V_63 ) ;
if ( V_54 > V_64 ) {
F_21 ( L_5 ) ;
break;
}
if ( ( V_56 & V_8 [ type ] . V_65 )
&& V_66 != - 1 ) {
F_22 ( & V_53 ) ;
V_55 = ( V_56 & V_8 [ type ] . V_67 ) ? 1 : 0 ;
if ( V_55 == V_59 ) {
F_21 ( L_6 ,
V_55 , V_66 ,
V_53 . V_68 , V_69 . V_68 ,
( unsigned long ) V_53 . V_70 ,
( unsigned long ) V_69 . V_70 ) ;
continue;
}
V_57 = V_53 . V_68 - V_69 . V_68 ;
if ( V_53 . V_68 < V_69 . V_68 ||
( V_53 . V_68 == V_69 . V_68 &&
V_53 . V_70 < V_69 . V_70 ) ) {
F_21 ( L_7 ) ;
F_21 ( L_8 ,
V_55 , V_66 ,
V_53 . V_68 , V_69 . V_68 ,
( unsigned long ) V_53 . V_70 ,
( unsigned long ) V_69 . V_70 ) ;
V_58 = V_50 ;
} else if ( V_57 > 15 ) {
V_58 = V_50 ;
if ( ! ( V_55 ^ V_66 ) ) {
F_21 ( L_9 ,
V_55 , V_66 ,
V_53 . V_68 , V_69 . V_68 ,
( unsigned long ) V_53 . V_70 ,
( unsigned long ) V_69 . V_70 ) ;
V_66 = V_66 ? 0 : 1 ;
}
} else
V_58 = ( int ) ( V_57 * 1000000 +
V_53 . V_70 -
V_69 . V_70 ) ;
F_19 ( V_55 ^ V_66 ? V_58 : ( V_58 | V_49 ) ) ;
V_69 = V_53 ;
V_59 = V_55 ;
F_23 ( & V_45 . V_71 ) ;
}
} while ( ! ( F_1 ( V_60 ) & V_61 ) );
return V_72 ;
}
static int F_24 ( void )
{
T_1 V_73 , V_74 , V_75 ;
V_73 = F_1 ( V_76 ) ;
F_3 ( V_76 , 0 ) ;
#ifdef F_25
F_4 ( 0xff , 0x080 ) ;
#endif
V_74 = F_1 ( V_76 ) & 0x0f ;
F_3 ( V_76 , 0x0f ) ;
#ifdef F_25
F_4 ( 0x00 , 0x080 ) ;
#endif
V_75 = F_1 ( V_76 ) & 0x0f ;
F_3 ( V_76 , V_73 ) ;
if ( V_74 != 0 || V_75 != 0x0f ) {
F_26 ( L_10 ) ;
return - V_77 ;
}
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_76 , F_1 ( V_76 ) &
( ~ ( V_80 | V_81 | V_82 | V_83 ) ) ) ;
F_1 ( V_36 ) ;
F_1 ( V_84 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
V_9 () ;
F_1 ( V_36 ) ;
F_1 ( V_84 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
switch ( type ) {
case V_85 :
case V_86 :
F_3 ( V_78 , F_1 ( V_78 ) | V_79 ) ;
F_3 ( V_87 , 0 ) ;
F_3 ( V_88 , 1 ) ;
F_3 ( V_78 , V_89 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_27 ( struct V_90 * V_91 )
{
int V_31 , V_92 , V_93 , V_94 ;
V_94 = F_28 ( & V_91 -> V_91 , V_95 , F_20 ,
( V_96 ? V_97 : 0 ) ,
V_98 , & V_8 ) ;
if ( V_94 < 0 ) {
if ( V_94 == - V_99 )
F_29 ( & V_91 -> V_91 , L_11 , V_95 ) ;
else if ( V_94 == - V_27 )
F_29 ( & V_91 -> V_91 , L_12 ) ;
return V_94 ;
}
if ( ( ( V_2 )
&& ( F_30 ( & V_91 -> V_91 , V_2 , 8 << V_3 ,
V_98 ) == NULL ) )
|| ( ( ! V_2 )
&& ( F_31 ( & V_91 -> V_91 , V_4 , 8 ,
V_98 ) == NULL ) ) ) {
F_29 ( & V_91 -> V_91 , L_13 , V_4 ) ;
F_32 ( & V_91 -> V_91 , L_14 ) ;
F_32 ( & V_91 -> V_91 ,
L_15 ) ;
F_32 ( & V_91 -> V_91 , L_16 ) ;
return - V_99 ;
}
V_94 = F_24 () ;
if ( V_94 < 0 )
return V_94 ;
F_8 ( V_16 , V_17 ) ;
if ( V_66 == - 1 ) {
F_33 ( 500 ) ;
V_92 = 0 ;
V_93 = 0 ;
for ( V_31 = 0 ; V_31 < 9 ; V_31 ++ ) {
if ( F_1 ( V_63 ) & V_8 [ type ] . V_67 )
V_92 ++ ;
else
V_93 ++ ;
F_33 ( 40 ) ;
}
V_66 = V_92 >= V_93 ? 1 : 0 ;
F_34 ( & V_91 -> V_91 , L_17 ,
V_66 ? L_18 : L_19 ) ;
} else
F_34 ( & V_91 -> V_91 , L_20 ,
V_66 ? L_18 : L_19 ) ;
F_10 ( L_21 , V_95 , V_4 ) ;
return 0 ;
}
static int F_35 ( void * V_58 )
{
unsigned long V_100 ;
F_22 ( & V_69 ) ;
F_36 ( & V_8 [ type ] . V_101 , V_100 ) ;
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_76 , F_1 ( V_76 ) | V_80 ) ;
F_37 ( & V_8 [ type ] . V_101 , V_100 ) ;
return 0 ;
}
static void F_38 ( void * V_58 )
{ unsigned long V_100 ;
F_36 ( & V_8 [ type ] . V_101 , V_100 ) ;
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_76 , F_1 ( V_76 ) &
( ~ ( V_80 | V_81 | V_82 | V_83 ) ) ) ;
F_37 ( & V_8 [ type ] . V_101 , V_100 ) ;
}
static T_4 F_39 ( struct V_102 * V_102 , const char T_5 * V_103 ,
T_6 V_104 , T_7 * V_105 )
{
int V_31 , V_106 ;
unsigned long V_100 ;
long V_107 = 0 ;
int * V_108 ;
if ( ! ( V_8 [ type ] . V_109 & V_110 ) )
return - V_111 ;
V_106 = V_104 / sizeof( int ) ;
if ( V_104 % sizeof( int ) || V_106 % 2 == 0 )
return - V_27 ;
V_108 = F_40 ( V_103 , V_104 ) ;
if ( F_41 ( V_108 ) )
return F_42 ( V_108 ) ;
F_36 ( & V_8 [ type ] . V_101 , V_100 ) ;
if ( type == V_85 ) {
F_5 () ;
}
for ( V_31 = 0 ; V_31 < V_106 ; V_31 ++ ) {
if ( V_31 % 2 )
V_8 [ type ] . F_43 ( V_108 [ V_31 ] - V_107 ) ;
else
V_107 = V_8 [ type ] . F_44 ( V_108 [ V_31 ] ) ;
}
V_9 () ;
F_37 ( & V_8 [ type ] . V_101 , V_100 ) ;
F_45 ( V_108 ) ;
return V_104 ;
}
static long F_46 ( struct V_102 * V_112 , unsigned int V_113 , unsigned long V_114 )
{
int V_94 ;
T_8 T_5 * V_115 = ( T_8 T_5 * ) V_114 ;
T_8 V_5 ;
switch ( V_113 ) {
case V_116 :
if ( ! ( V_8 [ type ] . V_109 & V_117 ) )
return - V_118 ;
V_94 = F_47 ( F_48
( V_8 [ type ] . V_109 & V_117 ) ,
V_115 ) ;
if ( V_94 )
return V_94 ;
break;
case V_119 :
if ( ! ( V_8 [ type ] . V_109 & V_117 ) )
return - V_118 ;
V_94 = F_49 ( V_5 , V_115 ) ;
if ( V_94 )
return V_94 ;
if ( V_5 != V_120 )
return - V_27 ;
break;
case V_121 :
return - V_118 ;
case V_122 :
F_10 ( L_22 ) ;
if ( ! ( V_8 [ type ] . V_109 & V_123 ) )
return - V_118 ;
V_94 = F_49 ( V_5 , V_115 ) ;
if ( V_94 )
return V_94 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_27 ;
return F_8 ( V_5 , V_17 ) ;
case V_124 :
F_10 ( L_23 ) ;
if ( ! ( V_8 [ type ] . V_109 & V_125 ) )
return - V_118 ;
V_94 = F_49 ( V_5 , V_115 ) ;
if ( V_94 )
return V_94 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_27 ;
return F_8 ( V_16 , V_5 ) ;
default:
return F_50 ( V_112 , V_113 , V_114 ) ;
}
return 0 ;
}
static int F_51 ( struct V_90 * V_91 ,
T_9 V_126 )
{
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_76 , F_1 ( V_76 ) &
( ~ ( V_80 | V_81 | V_82 | V_83 ) ) ) ;
F_1 ( V_36 ) ;
F_1 ( V_84 ) ;
F_1 ( V_60 ) ;
F_1 ( V_63 ) ;
return 0 ;
}
static int F_52 ( struct V_90 * V_91 )
{
unsigned long V_100 ;
int V_94 ;
V_94 = F_24 () ;
if ( V_94 < 0 )
return V_94 ;
F_36 ( & V_8 [ type ] . V_101 , V_100 ) ;
F_22 ( & V_69 ) ;
F_3 ( V_76 , F_1 ( V_76 ) | V_80 ) ;
V_9 () ;
F_53 ( & V_45 ) ;
F_37 ( & V_8 [ type ] . V_101 , V_100 ) ;
return 0 ;
}
static int T_10 F_54 ( void )
{
int V_94 ;
V_94 = F_55 ( & V_45 , sizeof( int ) , V_127 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_56 ( & V_128 ) ;
if ( V_94 ) {
F_57 ( L_24 , V_94 ) ;
goto V_129;
}
V_130 = F_58 ( L_25 , 0 ) ;
if ( ! V_130 ) {
V_94 = - V_131 ;
goto V_132;
}
V_94 = F_59 ( V_130 ) ;
if ( V_94 )
goto V_133;
return 0 ;
V_133:
F_60 ( V_130 ) ;
V_132:
F_61 ( & V_128 ) ;
V_129:
F_62 ( & V_45 ) ;
return V_94 ;
}
static void F_63 ( void )
{
F_64 ( V_130 ) ;
F_61 ( & V_128 ) ;
F_62 ( & V_45 ) ;
}
static int T_10 F_65 ( void )
{
int V_94 ;
switch ( type ) {
case V_134 :
case V_85 :
case V_86 :
case V_135 :
case V_136 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_95 = V_95 ? V_95 : 4 ;
break;
default:
return - V_27 ;
}
if ( ! V_43 ) {
switch ( type ) {
case V_134 :
case V_136 :
V_8 [ type ] . V_109 &=
~ ( V_123 |
V_125 ) ;
break;
}
}
if ( V_66 != - 1 )
V_66 = ! ! V_66 ;
V_94 = F_54 () ;
if ( V_94 )
return V_94 ;
V_137 . V_109 = V_8 [ type ] . V_109 ;
V_137 . V_91 = & V_130 -> V_91 ;
V_137 . V_138 = F_66 ( & V_137 ) ;
if ( V_137 . V_138 < 0 ) {
F_26 ( L_26 ) ;
F_63 () ;
return V_137 . V_138 ;
}
return 0 ;
}
static void T_11 F_67 ( void )
{
F_68 ( V_137 . V_138 ) ;
F_63 () ;
F_10 ( L_27 ) ;
}
