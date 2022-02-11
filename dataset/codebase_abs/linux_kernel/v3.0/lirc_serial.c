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
F_7 ( V_7 , V_8 ) ;
return;
}
#endif
if ( V_9 )
F_3 ( V_10 , V_11 [ type ] . V_12 ) ;
else
F_3 ( V_10 , V_11 [ type ] . F_5 ) ;
}
static void V_12 ( void )
{
#ifdef F_6
if ( type == V_6 ) {
F_7 ( V_7 , V_13 ) ;
return;
}
#endif
if ( V_9 )
F_3 ( V_10 , V_11 [ type ] . F_5 ) ;
else
F_3 ( V_10 , V_11 [ type ] . V_12 ) ;
}
static void F_8 ( unsigned long V_14 )
{
while ( V_14 > V_15 ) {
F_9 ( V_15 ) ;
V_14 -= V_15 ;
}
F_9 ( V_14 ) ;
}
static int F_10 ( unsigned int V_16 ,
unsigned int V_17 )
{
T_2 V_18 , V_19 ;
V_20 = V_16 ;
V_21 = V_17 ;
V_18 = F_11 ( V_22 . V_23 . V_24 ) ;
V_18 *= V_25 ;
V_19 = V_18 ;
V_19 *= 4295 ;
V_26 = ( V_19 >> 32 ) ;
V_27 = V_18 >> 3 ;
V_27 /= ( V_21 >> 3 ) ;
V_28 = V_27 * V_20 / 100 ;
V_29 = V_27 - V_28 ;
F_12 ( L_1
L_2
L_3 ,
V_21 , V_20 , F_11 ( V_30 . V_24 ) ,
V_28 , V_29 , V_26 ) ;
return 0 ;
}
static int F_10 ( unsigned int V_16 ,
unsigned int V_17 )
{
if ( 256 * 1000000L / V_17 * V_16 / 100 <=
V_31 )
return - V_32 ;
if ( 256 * 1000000L / V_17 * ( 100 - V_16 ) / 100 <=
V_31 )
return - V_32 ;
V_20 = V_16 ;
V_21 = V_17 ;
V_27 = 256 * 1000000L / V_21 ;
V_28 = V_27 * V_20 / 100 ;
V_29 = V_27 - V_28 ;
F_12 ( L_4
L_5 , V_21 , V_28 , V_29 ) ;
return 0 ;
}
static long F_13 ( unsigned long V_33 )
{
long V_34 , V_35 ;
int V_36 ;
unsigned char V_37 ;
unsigned char V_38 , V_39 ;
V_34 = V_33 * 1152 / 10000 ;
if ( V_20 > 50 )
V_38 = 3 ;
else
V_38 = 1 ;
for ( V_36 = 0 , V_37 = 0x7f ; V_34 > 0 ; V_34 -= 3 ) {
V_39 = V_38 << ( V_36 * 3 ) ;
V_39 >>= 1 ;
V_37 &= ( ~ V_39 ) ;
V_36 ++ ;
if ( V_36 == 3 ) {
F_3 ( V_40 , V_37 ) ;
while ( ! ( F_1 ( V_41 ) & V_42 ) )
;
V_37 = 0x7f ;
V_36 = 0 ;
}
}
if ( V_36 != 0 ) {
F_3 ( V_40 , V_37 ) ;
while ( ! ( F_1 ( V_41 ) & V_43 ) )
;
}
if ( V_36 == 0 )
V_35 = ( - V_34 ) * 10000 / 1152 ;
else
V_35 = ( 3 - V_36 ) * 3 * 10000 / 1152 + ( - V_34 ) * 10000 / 1152 ;
return V_35 ;
}
static long F_14 ( unsigned long V_33 )
{
int V_44 ;
unsigned long V_45 , V_46 , V_47 ;
F_15 ( V_46 ) ;
F_5 () ;
V_33 *= V_26 ;
V_47 = V_46 ;
V_45 = V_28 ;
V_44 = 1 ;
while ( ( V_47 - V_46 ) < V_33 ) {
do {
F_15 ( V_47 ) ;
} while ( ( V_47 - V_46 ) < V_45 );
if ( V_44 ) {
F_15 ( V_47 ) ;
V_12 () ;
V_45 += V_29 ;
} else {
F_15 ( V_47 ) ; F_5 () ;
V_45 += V_28 ;
}
V_44 = ! V_44 ;
}
F_15 ( V_47 ) ;
return ( ( V_47 - V_46 ) - V_33 ) / V_26 ;
}
static long F_14 ( unsigned long V_33 )
{
int V_44 ;
unsigned long V_48 , V_45 , V_49 ;
V_33 <<= 8 ;
V_48 = 0 ; V_45 = 0 ; V_44 = 0 ;
while ( V_48 < V_33 ) {
if ( V_44 ) {
V_12 () ;
V_45 += V_29 ;
} else {
F_5 () ;
V_45 += V_28 ;
}
V_49 = ( V_45 - V_48 -
V_31 + 128 ) >> 8 ;
F_9 ( V_49 ) ;
V_48 += ( V_49 << 8 ) + V_31 ;
V_44 = ! V_44 ;
}
return ( V_48 - V_33 ) >> 8 ;
}
static long F_16 ( unsigned long V_33 )
{
if ( V_33 <= 0 )
return 0 ;
if ( V_50 )
return F_14 ( V_33 ) ;
else {
F_5 () ;
F_8 ( V_33 ) ;
return 0 ;
}
}
static void F_17 ( long V_33 )
{
if ( V_33 <= 0 )
return;
F_8 ( V_33 ) ;
}
static void F_18 ( long V_33 )
{
V_12 () ;
if ( V_33 <= 0 )
return;
F_8 ( V_33 ) ;
}
static void F_19 ( int V_51 )
{
if ( F_20 ( & V_52 ) ) {
F_12 ( L_6 ) ;
return;
}
F_21 ( & V_52 , ( void * ) & V_51 ) ;
}
static void F_22 ( int V_51 )
{
static int V_53 , V_54 ;
static unsigned int V_55 ;
if ( V_55 > 0 && ( V_51 & V_56 ) ) {
V_53 += V_51 & V_57 ;
if ( V_53 > 250 ) {
F_19 ( V_54 ) ;
F_19 ( V_53 | V_56 ) ;
V_55 = 0 ;
V_53 = 0 ;
}
return;
}
if ( ! ( V_51 & V_56 ) ) {
if ( V_55 == 0 ) {
if ( V_51 > 20000 ) {
V_54 = V_51 ;
V_55 ++ ;
return;
}
} else {
if ( V_51 > 20000 ) {
V_54 += V_53 ;
if ( V_54 > V_57 )
V_54 = V_57 ;
V_54 += V_51 ;
if ( V_54 > V_57 )
V_54 = V_57 ;
V_53 = 0 ;
return;
}
F_19 ( V_54 ) ;
F_19 ( V_53 | V_56 ) ;
V_55 = 0 ;
V_53 = 0 ;
}
}
F_19 ( V_51 ) ;
}
static T_3 F_23 ( int V_36 , void * V_58 )
{
struct V_59 V_60 ;
int V_61 , V_62 ;
T_1 V_63 ;
long V_64 ;
int V_65 ;
static int V_66 = - 1 ;
if ( ( F_1 ( V_67 ) & V_68 ) ) {
return V_69 ;
}
V_61 = 0 ;
do {
V_61 ++ ;
V_63 = F_1 ( V_70 ) ;
if ( V_61 > V_71 ) {
F_24 (KERN_WARNING LIRC_DRIVER_NAME L_7
L_8 ) ;
break;
}
if ( ( V_63 & V_11 [ type ] . V_72 )
&& V_73 != - 1 ) {
F_25 ( & V_60 ) ;
V_62 = ( V_63 & V_11 [ type ] . V_74 ) ? 1 : 0 ;
if ( V_62 == V_66 ) {
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_9 ,
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
tv.tv_usec, lasttv.tv_usec) ;
continue;
}
V_64 = V_60 . V_75 - V_76 . V_75 ;
if ( V_60 . V_75 < V_76 . V_75 ||
( V_60 . V_75 == V_76 . V_75 &&
V_60 . V_77 < V_76 . V_77 ) ) {
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_10
L_11 ) ;
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_12 ,
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
tv.tv_usec, lasttv.tv_usec) ;
V_65 = V_57 ;
} else if ( V_64 > 15 ) {
V_65 = V_57 ;
if ( ! ( V_62 ^ V_73 ) ) {
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_7
L_13 ,
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
tv.tv_usec, lasttv.tv_usec) ;
V_73 = V_73 ? 0 : 1 ;
}
} else
V_65 = ( int ) ( V_64 * 1000000 +
V_60 . V_77 -
V_76 . V_77 ) ;
F_22 ( V_62 ^ V_73 ? V_65 : ( V_65 | V_56 ) ) ;
V_76 = V_60 ;
V_66 = V_62 ;
F_26 ( & V_52 . V_78 ) ;
}
} while ( ! ( F_1 ( V_67 ) & V_68 ) );
return V_79 ;
}
static int F_27 ( void )
{
T_1 V_80 , V_81 , V_82 ;
V_80 = F_1 ( V_83 ) ;
F_3 ( V_83 , 0 ) ;
#ifdef F_28
F_4 ( 0xff , 0x080 ) ;
#endif
V_81 = F_1 ( V_83 ) & 0x0f ;
F_3 ( V_83 , 0x0f ) ;
#ifdef F_28
F_4 ( 0x00 , 0x080 ) ;
#endif
V_82 = F_1 ( V_83 ) & 0x0f ;
F_3 ( V_83 , V_80 ) ;
if ( V_81 != 0 || V_82 != 0x0f ) {
F_24 (KERN_ERR LIRC_DRIVER_NAME L_14
L_15 ) ;
return - V_32 ;
}
F_3 ( V_84 , F_1 ( V_84 ) & ( ~ V_85 ) ) ;
F_3 ( V_83 , F_1 ( V_83 ) &
( ~ ( V_86 | V_87 | V_88 | V_89 ) ) ) ;
F_1 ( V_41 ) ;
F_1 ( V_90 ) ;
F_1 ( V_67 ) ;
F_1 ( V_70 ) ;
#ifdef F_6
if ( type == V_6 ) {
F_3 ( V_83 , F_1 ( V_83 ) | V_91 ) ;
F_3 ( V_83 , F_1 ( V_83 ) & ~ V_92 ) ;
F_3 ( V_10 , V_93 | V_94 ) ;
}
#endif
V_12 () ;
F_1 ( V_41 ) ;
F_1 ( V_90 ) ;
F_1 ( V_67 ) ;
F_1 ( V_70 ) ;
switch ( type ) {
case V_95 :
case V_96 :
F_3 ( V_84 , F_1 ( V_84 ) | V_85 ) ;
F_3 ( V_97 , 0 ) ;
F_3 ( V_98 , 1 ) ;
F_3 ( V_84 , V_99 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_29 ( void )
{
int V_36 , V_100 , V_101 , V_102 ;
V_102 = F_30 ( V_103 , F_23 ,
V_104 | ( V_105 ? V_106 : 0 ) ,
V_107 , ( void * ) & V_11 ) ;
switch ( V_102 ) {
case - V_108 :
F_24 (KERN_ERR LIRC_DRIVER_NAME L_16 , irq) ;
return - V_108 ;
case - V_32 :
F_24 (KERN_ERR LIRC_DRIVER_NAME
L_17 ) ;
return - V_32 ;
default:
break;
} ;
if ( ( ( V_2 != 0 )
&& ( F_31 ( V_2 , 8 << V_3 ,
V_107 ) == NULL ) )
|| ( ( V_2 == 0 )
&& ( F_32 ( V_4 , 8 , V_107 ) == NULL ) ) ) {
F_24 (KERN_ERR LIRC_DRIVER_NAME
L_18 , io) ;
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_19 ) ;
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_20 ) ;
F_24 (KERN_WARNING LIRC_DRIVER_NAME
L_21 ) ;
return - V_108 ;
}
if ( F_27 () < 0 )
return - V_32 ;
F_10 ( V_20 , V_21 ) ;
if ( V_73 == - 1 ) {
F_33 ( 500 ) ;
V_100 = 0 ;
V_101 = 0 ;
for ( V_36 = 0 ; V_36 < 9 ; V_36 ++ ) {
if ( F_1 ( V_70 ) & V_11 [ type ] . V_74 )
V_100 ++ ;
else
V_101 ++ ;
F_33 ( 40 ) ;
}
V_73 = ( V_100 >= V_101 ? 1 : 0 ) ;
F_24 (KERN_INFO LIRC_DRIVER_NAME L_22
L_23 , sense ? L_24 : L_25 ) ;
} else
F_24 (KERN_INFO LIRC_DRIVER_NAME L_26
L_23 , sense ? L_24 : L_25 ) ;
F_12 ( L_27 , V_103 , V_4 ) ;
return 0 ;
}
static int F_34 ( void * V_65 )
{
unsigned long V_109 ;
F_25 ( & V_76 ) ;
F_35 ( & V_11 [ type ] . V_110 , V_109 ) ;
F_3 ( V_84 , F_1 ( V_84 ) & ( ~ V_85 ) ) ;
F_3 ( V_83 , F_1 ( V_83 ) | V_86 ) ;
F_36 ( & V_11 [ type ] . V_110 , V_109 ) ;
return 0 ;
}
static void F_37 ( void * V_65 )
{ unsigned long V_109 ;
F_35 ( & V_11 [ type ] . V_110 , V_109 ) ;
F_3 ( V_84 , F_1 ( V_84 ) & ( ~ V_85 ) ) ;
F_3 ( V_83 , F_1 ( V_83 ) &
( ~ ( V_86 | V_87 | V_88 | V_89 ) ) ) ;
F_36 ( & V_11 [ type ] . V_110 , V_109 ) ;
}
static T_4 F_38 ( struct V_111 * V_111 , const char * V_112 ,
T_5 V_113 , T_6 * V_114 )
{
int V_36 , V_115 ;
unsigned long V_109 ;
long V_116 = 0 ;
int * V_117 ;
if ( ! ( V_11 [ type ] . V_118 & V_119 ) )
return - V_120 ;
V_115 = V_113 / sizeof( int ) ;
if ( V_113 % sizeof( int ) || V_115 % 2 == 0 )
return - V_32 ;
V_117 = F_39 ( V_112 , V_113 ) ;
if ( F_40 ( V_117 ) )
return F_41 ( V_117 ) ;
F_35 ( & V_11 [ type ] . V_110 , V_109 ) ;
if ( type == V_95 ) {
F_5 () ;
}
for ( V_36 = 0 ; V_36 < V_115 ; V_36 ++ ) {
if ( V_36 % 2 )
V_11 [ type ] . F_42 ( V_117 [ V_36 ] - V_116 ) ;
else
V_116 = V_11 [ type ] . F_43 ( V_117 [ V_36 ] ) ;
}
V_12 () ;
F_36 ( & V_11 [ type ] . V_110 , V_109 ) ;
F_44 ( V_117 ) ;
return V_113 ;
}
static long F_45 ( struct V_111 * V_121 , unsigned int V_122 , unsigned long V_123 )
{
int V_102 ;
T_7 V_5 ;
switch ( V_122 ) {
case V_124 :
if ( ! ( V_11 [ type ] . V_118 & V_125 ) )
return - V_126 ;
V_102 = F_46 ( F_47
( V_11 [ type ] . V_118 & V_125 ) ,
( T_7 * ) V_123 ) ;
if ( V_102 )
return V_102 ;
break;
case V_127 :
if ( ! ( V_11 [ type ] . V_118 & V_125 ) )
return - V_126 ;
V_102 = F_48 ( V_5 , ( T_7 * ) V_123 ) ;
if ( V_102 )
return V_102 ;
if ( V_5 != V_128 )
return - V_129 ;
break;
case V_130 :
return - V_129 ;
break;
case V_131 :
F_12 ( L_28 ) ;
if ( ! ( V_11 [ type ] . V_118 & V_132 ) )
return - V_126 ;
V_102 = F_48 ( V_5 , ( T_7 * ) V_123 ) ;
if ( V_102 )
return V_102 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_32 ;
return F_10 ( V_5 , V_21 ) ;
break;
case V_133 :
F_12 ( L_29 ) ;
if ( ! ( V_11 [ type ] . V_118 & V_134 ) )
return - V_126 ;
V_102 = F_48 ( V_5 , ( T_7 * ) V_123 ) ;
if ( V_102 )
return V_102 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_32 ;
return F_10 ( V_20 , V_5 ) ;
break;
default:
return F_49 ( V_121 , V_122 , V_123 ) ;
}
return 0 ;
}
static int T_8 F_50 ( struct V_135 * V_136 )
{
return 0 ;
}
static int T_9 F_51 ( struct V_135 * V_136 )
{
return 0 ;
}
static int F_52 ( struct V_135 * V_136 ,
T_10 V_137 )
{
F_3 ( V_84 , F_1 ( V_84 ) & ( ~ V_85 ) ) ;
F_3 ( V_83 , F_1 ( V_83 ) &
( ~ ( V_86 | V_87 | V_88 | V_89 ) ) ) ;
F_1 ( V_41 ) ;
F_1 ( V_90 ) ;
F_1 ( V_67 ) ;
F_1 ( V_70 ) ;
return 0 ;
}
static int F_53 ( struct V_135 * V_136 )
{
unsigned long V_109 ;
if ( F_27 () < 0 ) {
F_54 () ;
return - V_32 ;
}
F_35 ( & V_11 [ type ] . V_110 , V_109 ) ;
F_25 ( & V_76 ) ;
F_3 ( V_83 , F_1 ( V_83 ) | V_86 ) ;
V_12 () ;
F_55 ( & V_52 ) ;
F_36 ( & V_11 [ type ] . V_110 , V_109 ) ;
return 0 ;
}
static int T_11 F_56 ( void )
{
int V_102 ;
V_102 = F_57 ( & V_52 , sizeof( int ) , V_138 ) ;
if ( V_102 < 0 )
return - V_139 ;
V_102 = F_58 ( & V_140 ) ;
if ( V_102 ) {
F_24 ( L_30 , V_102 ) ;
goto V_141;
}
V_142 = F_59 ( L_31 , 0 ) ;
if ( ! V_142 ) {
V_102 = - V_139 ;
goto V_143;
}
V_102 = F_60 ( V_142 ) ;
if ( V_102 )
goto V_144;
return 0 ;
V_144:
F_61 ( V_142 ) ;
V_143:
F_62 ( & V_140 ) ;
V_141:
F_63 ( & V_52 ) ;
return V_102 ;
}
static void F_54 ( void )
{
F_64 ( V_142 ) ;
F_62 ( & V_140 ) ;
F_63 ( & V_52 ) ;
}
static int T_11 F_65 ( void )
{
int V_102 ;
V_102 = F_56 () ;
if ( V_102 )
return V_102 ;
switch ( type ) {
case V_145 :
case V_95 :
case V_96 :
case V_146 :
case V_147 :
V_4 = V_4 ? V_4 : 0x3f8 ;
V_103 = V_103 ? V_103 : 4 ;
break;
#ifdef F_6
case V_6 :
V_4 = V_4 ? V_4 : V_148 ;
V_103 = V_103 ? V_103 : ( V_149 + V_150 ) ;
V_2 = V_2 ? V_2 : V_151 ;
V_3 = V_3 ? V_3 : 2 ;
break;
#endif
default:
V_102 = - V_32 ;
goto V_152;
}
if ( ! V_50 ) {
switch ( type ) {
case V_145 :
case V_147 :
#ifdef F_6
case V_6 :
#endif
V_11 [ type ] . V_118 &=
~ ( V_132 |
V_134 ) ;
break;
}
}
V_102 = F_29 () ;
if ( V_102 < 0 )
goto V_152;
V_153 . V_118 = V_11 [ type ] . V_118 ;
V_153 . V_136 = & V_142 -> V_136 ;
V_153 . V_154 = F_66 ( & V_153 ) ;
if ( V_153 . V_154 < 0 ) {
F_24 (KERN_ERR LIRC_DRIVER_NAME
L_32 ) ;
V_102 = - V_155 ;
goto V_156;
}
return 0 ;
V_156:
F_67 ( V_4 , 8 ) ;
V_152:
F_54 () ;
return V_102 ;
}
static void T_12 F_68 ( void )
{
F_54 () ;
F_69 ( V_103 , ( void * ) & V_11 ) ;
if ( V_2 != 0 )
F_70 ( V_2 , 8 << V_3 ) ;
else
F_67 ( V_4 , 8 ) ;
F_71 ( V_153 . V_154 ) ;
F_12 ( L_33 ) ;
}
