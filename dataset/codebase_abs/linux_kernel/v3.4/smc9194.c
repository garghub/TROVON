static void F_1 ( int V_1 )
{
F_2 ( 0 ) ;
F_3 ( V_2 , V_1 + V_3 ) ;
F_4 ( ) ;
F_3 ( V_4 , V_1 + V_3 ) ;
F_3 ( V_5 , V_1 + V_6 ) ;
F_2 ( 1 ) ;
F_3 ( F_5 ( V_1 + V_7 ) | V_8 , V_1 + V_7 ) ;
F_2 ( 2 ) ;
F_3 ( V_9 , V_1 + V_10 ) ;
F_6 ( 0 , V_1 + V_11 ) ;
}
static void F_7 ( int V_1 )
{
F_2 ( 0 ) ;
F_3 ( V_12 , V_1 + V_6 ) ;
F_3 ( V_13 , V_1 + V_3 ) ;
F_2 ( 2 ) ;
F_6 ( V_14 , V_1 + V_11 ) ;
}
static void F_8 ( int V_1 )
{
F_2 ( 2 ) ;
F_6 ( 0 , V_1 + V_11 ) ;
F_2 ( 0 ) ;
F_6 ( V_4 , V_1 + V_3 ) ;
F_6 ( V_5 , V_1 + V_6 ) ;
#if 0
SMC_SELECT_BANK( 1 );
outw( inw( ioaddr + CONTROL ), CTL_POWERDOWN, ioaddr + CONTROL );
#endif
}
static void F_9 ( int V_1 , struct V_15 * V_16 )
{
int V_17 ;
unsigned char V_18 [ 8 ] ;
struct V_19 * V_20 ;
unsigned char V_21 [] = { 0 , 4 , 2 , 6 , 1 , 5 , 3 , 7 } ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
F_10 (ha, dev) {
int V_22 ;
V_22 = F_11 ( 6 , V_20 -> V_23 ) & 0x3f ;
V_18 [ V_21 [ V_22 & 7 ] ] |=
( 1 << V_21 [ ( V_22 >> 3 ) & 7 ] ) ;
}
F_2 ( 3 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
F_6 ( V_18 [ V_17 ] , V_1 + V_24 + V_17 ) ;
}
}
static T_1 F_12 ( struct V_25 * V_26 ,
struct V_15 * V_16 )
{
struct V_27 * V_28 = F_13 ( V_16 ) ;
unsigned int V_1 = V_16 -> V_29 ;
T_2 V_30 ;
unsigned short V_31 ;
T_2 V_32 ;
F_14 ( V_16 ) ;
if ( V_28 -> V_33 ) {
V_16 -> V_34 . V_35 ++ ;
F_15 ( V_36 L_1 ) ;
return V_37 ;
}
V_28 -> V_33 = V_26 ;
V_30 = V_26 -> V_38 ;
if ( V_30 < V_39 ) {
if ( F_16 ( V_26 , V_39 ) ) {
F_17 ( V_16 ) ;
return V_40 ;
}
V_30 = V_39 ;
}
V_31 = ( ( V_30 & 0xfffe ) + 6 ) / 256 ;
if ( V_31 > 7 ) {
F_15 ( V_36 L_2 ) ;
F_18 ( V_26 ) ;
V_28 -> V_33 = NULL ;
F_17 ( V_16 ) ;
return V_40 ;
}
V_28 -> V_41 ++ ;
F_2 ( 2 ) ;
F_3 ( V_42 | V_31 , V_1 + V_10 ) ;
V_32 = V_43 ;
do {
T_2 V_44 ;
V_44 = F_19 ( V_1 + V_45 ) ;
if ( V_44 & V_46 ) {
F_6 ( V_46 , V_1 + V_45 ) ;
break;
}
} while ( -- V_32 );
if ( ! V_32 ) {
F_20 ( V_46 ) ;
F_21 ( ( V_36 L_3 ) ) ;
return V_40 ;
}
F_22 ( V_16 ) ;
F_17 ( V_16 ) ;
return V_40 ;
}
static void F_22 ( struct V_15 * V_16 )
{
struct V_27 * V_28 = F_13 ( V_16 ) ;
T_3 V_47 ;
struct V_25 * V_26 = V_28 -> V_33 ;
T_2 V_30 ;
unsigned int V_1 ;
T_3 * V_48 ;
V_1 = V_16 -> V_29 ;
if ( ! V_26 ) {
F_23 ( ( V_36 L_4 ) ) ;
return;
}
V_30 = V_39 < V_26 -> V_38 ? V_26 -> V_38 : V_39 ;
V_48 = V_26 -> V_49 ;
V_47 = F_19 ( V_1 + V_50 + 1 ) ;
if ( V_47 & 0x80 ) {
F_15 (KERN_DEBUG CARDNAMEL_5 ) ;
F_24 ( V_26 ) ;
V_28 -> V_33 = NULL ;
F_17 ( V_16 ) ;
return;
}
F_6 ( V_47 , V_1 + V_50 ) ;
F_3 ( V_51 , V_1 + V_52 ) ;
F_25 ( ( V_36 L_6 , V_30 ) ) ;
#if V_53 > 2
F_26 ( V_48 , V_30 ) ;
#endif
#ifdef F_27
F_28 ( ( V_30 + 6 ) << 16 , V_1 + V_54 ) ;
#else
F_3 ( 0 , V_1 + V_54 ) ;
F_6 ( ( V_30 + 6 ) & 0xFF , V_1 + V_54 ) ;
F_6 ( ( V_30 + 6 ) >> 8 , V_1 + V_54 ) ;
#endif
#ifdef F_27
if ( V_30 & 0x2 ) {
F_29 ( V_1 + V_54 , V_48 , V_30 >> 2 ) ;
#if ! F_30 ( V_55 ) && ! F_30 ( V_56 )
F_3 ( * ( ( T_2 * ) ( V_48 + ( V_30 & 0xFFFFFFFC ) ) ) , V_1 + V_54 ) ;
#else
F_31 ( * ( ( T_2 * ) ( V_48 + ( V_30 & 0xFFFFFFFC ) ) ) , V_1 + V_54 ) ;
#endif
}
else
F_29 ( V_1 + V_54 , V_48 , V_30 >> 2 ) ;
#else
F_32 ( V_1 + V_54 , V_48 , ( V_30 ) >> 1 ) ;
#endif
if ( ( V_30 & 1 ) == 0 ) {
F_3 ( 0 , V_1 + V_54 ) ;
} else {
F_6 ( V_48 [ V_30 - 1 ] , V_1 + V_54 ) ;
F_6 ( 0x20 , V_1 + V_54 ) ;
}
F_20 ( ( V_57 | V_58 ) ) ;
F_3 ( V_59 , V_1 + V_10 ) ;
F_21 ( ( V_36 L_7 , V_30 ) ) ;
V_28 -> V_33 = NULL ;
F_24 ( V_26 ) ;
V_16 -> V_60 = V_61 ;
F_17 ( V_16 ) ;
}
struct V_15 * T_4 F_33 ( int V_62 )
{
struct V_15 * V_16 = F_34 ( sizeof( struct V_27 ) ) ;
struct V_63 * V_64 = V_65 ;
int V_66 = 0 ;
if ( ! V_16 )
return F_35 ( - V_67 ) ;
if ( V_62 >= 0 ) {
sprintf ( V_16 -> V_68 , L_8 , V_62 ) ;
F_36 ( V_16 ) ;
V_69 = V_16 -> V_29 ;
V_70 = V_16 -> V_70 ;
}
if ( V_69 > 0x1ff ) {
V_66 = F_37 ( V_16 , V_69 ) ;
} else if ( V_69 != 0 ) {
V_66 = - V_71 ;
} else {
for (; V_64 -> V_72 ; V_64 ++ ) {
if ( F_37 ( V_16 , V_64 -> V_72 ) == 0 )
break;
}
if ( ! V_64 -> V_72 )
V_66 = - V_67 ;
}
if ( V_66 )
goto V_73;
V_66 = F_38 ( V_16 ) ;
if ( V_66 )
goto V_74;
return V_16 ;
V_74:
F_39 ( V_16 -> V_70 , V_16 ) ;
F_40 ( V_16 -> V_29 , V_75 ) ;
V_73:
F_41 ( V_16 ) ;
return F_35 ( V_66 ) ;
}
static int T_4 F_42 ( int V_1 )
{
#ifndef F_43
int V_76 = 20 ;
unsigned long V_77 ;
V_77 = F_44 () ;
F_2 ( 2 ) ;
F_6 ( V_46 , V_1 + V_11 ) ;
F_3 ( V_42 | 1 , V_1 + V_10 ) ;
while ( V_76 ) {
T_3 V_78 ;
V_78 = F_19 ( V_1 + V_45 ) ;
if ( V_78 & V_46 )
break;
V_76 -- ;
}
F_4 () ;
F_4 () ;
F_6 ( 0 , V_1 + V_11 ) ;
return F_45 ( V_77 ) ;
#else
struct V_63 * V_64 ;
for ( V_64 = V_65 ; V_64 -> V_72 ; V_64 ++ ) {
if ( V_64 -> V_72 == V_1 )
return V_64 -> V_70 ;
}
return 0 ;
#endif
}
static int T_4 F_37 ( struct V_15 * V_16 , int V_1 )
{
int V_17 , V_79 , V_80 ;
static unsigned V_81 ;
unsigned int V_82 ;
const char * V_83 ;
const char * V_84 ;
T_2 V_85 ;
T_2 V_86 ;
T_2 V_87 ;
T_2 V_88 ;
T_2 V_89 ;
if ( ! F_46 ( V_1 , V_75 , V_90 ) )
return - V_91 ;
V_16 -> V_70 = V_70 ;
V_16 -> V_92 = V_93 ;
V_82 = F_5 ( V_1 + V_94 ) ;
if ( ( V_82 & 0xFF00 ) != 0x3300 ) {
V_80 = - V_67 ;
goto V_95;
}
F_3 ( 0x0 , V_1 + V_94 ) ;
V_82 = F_5 ( V_1 + V_94 ) ;
if ( ( V_82 & 0xFF00 ) != 0x3300 ) {
V_80 = - V_67 ;
goto V_95;
}
#if ! F_30 ( V_96 )
F_2 ( 1 ) ;
V_86 = F_5 ( V_1 + V_97 ) ;
if ( V_1 != ( V_86 >> 3 & 0x3E0 ) ) {
F_15 ( V_36 L_9
L_10 ,
V_1 , V_86 >> 3 & 0x3E0 ) ;
V_80 = - V_67 ;
goto V_95;
}
#else
( void ) V_86 ;
#endif
F_2 ( 3 ) ;
V_85 = F_5 ( V_1 + V_98 ) ;
if ( ! V_99 [ ( V_85 >> 4 ) & 0xF ] ) {
F_15 ( V_36 L_11
L_12 , V_1 , V_85 ) ;
V_80 = - V_67 ;
goto V_95;
}
if ( V_81 ++ == 0 )
F_15 ( L_13 , V_100 ) ;
V_16 -> V_29 = V_1 ;
F_2 ( 1 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 += 2 ) {
T_2 V_101 ;
V_101 = F_5 ( V_1 + V_102 + V_17 ) ;
V_16 -> V_103 [ V_17 + 1 ] = V_101 >> 8 ;
V_16 -> V_103 [ V_17 ] = V_101 & 0xFF ;
}
F_2 ( 0 ) ;
V_88 = F_5 ( V_1 + V_104 ) ;
V_89 = F_5 ( V_1 + V_105 ) ;
V_79 = ( V_89 >> 9 ) & 0x7 ;
V_79 *= 256 * ( V_88 & 0xFF ) ;
F_2 ( 3 ) ;
V_85 = F_5 ( V_1 + V_98 ) ;
V_83 = V_99 [ ( V_85 >> 4 ) & 0xF ] ;
if ( ! V_83 ) {
V_80 = - V_67 ;
goto V_95;
}
if ( V_16 -> V_92 == 0 ) {
F_2 ( 1 ) ;
V_87 = F_5 ( V_1 + V_106 ) ;
if ( V_87 & V_107 )
V_16 -> V_92 = 2 ;
else
V_16 -> V_92 = 1 ;
}
V_84 = V_108 [ V_16 -> V_92 - 1 ] ;
F_1 ( V_1 ) ;
if ( V_16 -> V_70 < 2 ) {
int V_109 ;
V_109 = 3 ;
while ( V_109 -- ) {
V_16 -> V_70 = F_42 ( V_1 ) ;
if ( V_16 -> V_70 )
break;
F_1 ( V_1 ) ;
}
}
if ( V_16 -> V_70 == 0 ) {
F_15 ( V_36 L_14 ) ;
V_80 = - V_67 ;
goto V_95;
}
F_15 ( L_15 , V_16 -> V_68 ,
V_83 , V_85 & 0xF , V_1 , V_16 -> V_70 ,
V_84 , V_79 ) ;
F_15 ( L_16 , V_16 -> V_103 ) ;
V_80 = F_47 ( V_16 -> V_70 , V_110 , 0 , V_90 , V_16 ) ;
if ( V_80 ) {
F_15 ( L_17 , V_90 ,
V_16 -> V_70 , V_80 ) ;
goto V_95;
}
V_16 -> V_111 = & V_112 ;
V_16 -> V_113 = V_114 / 20 ;
return 0 ;
V_95:
F_40 ( V_1 , V_75 ) ;
return V_80 ;
}
static void F_26 ( T_3 * V_48 , int V_30 )
{
#if 0
int i;
int remainder;
int lines;
printk("Packet of length %d\n", length);
lines = length / 16;
remainder = length % 16;
for ( i = 0; i < lines ; i ++ ) {
int cur;
for ( cur = 0; cur < 8; cur ++ ) {
byte a, b;
a = *(buf ++ );
b = *(buf ++ );
printk("%02x%02x ", a, b );
}
printk("\n");
}
for ( i = 0; i < remainder/2 ; i++ ) {
byte a, b;
a = *(buf ++ );
b = *(buf ++ );
printk("%02x%02x ", a, b );
}
printk("\n");
#endif
}
static int F_48 ( struct V_15 * V_16 )
{
int V_1 = V_16 -> V_29 ;
int V_17 ;
memset ( F_13 ( V_16 ) , 0 , sizeof( struct V_27 ) ) ;
F_1 ( V_1 ) ;
F_7 ( V_1 ) ;
F_2 ( 1 ) ;
if ( V_16 -> V_92 == 1 ) {
F_3 ( F_5 ( V_1 + V_106 ) & ~ V_107 ,
V_1 + V_106 ) ;
}
else if ( V_16 -> V_92 == 2 ) {
F_3 ( F_5 ( V_1 + V_106 ) | V_107 ,
V_1 + V_106 ) ;
}
F_2 ( 1 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 += 2 ) {
T_2 V_101 ;
V_101 = V_16 -> V_103 [ V_17 + 1 ] << 8 ;
V_101 |= V_16 -> V_103 [ V_17 ] ;
F_3 ( V_101 , V_1 + V_102 + V_17 ) ;
}
F_49 ( V_16 ) ;
return 0 ;
}
static void F_50 ( struct V_15 * V_16 )
{
F_15 (KERN_WARNING CARDNAMEL_18 ,
tx_done(dev) ? L_19 :
L_20 ) ;
F_1 ( V_16 -> V_29 ) ;
F_7 ( V_16 -> V_29 ) ;
V_16 -> V_60 = V_61 ;
( (struct V_27 * ) F_13 ( V_16 ) ) -> V_33 = NULL ;
F_17 ( V_16 ) ;
}
static void F_51 ( struct V_15 * V_16 )
{
int V_1 = V_16 -> V_29 ;
int V_115 ;
T_2 V_44 ;
T_2 V_116 ;
V_115 = F_5 ( V_1 + V_117 ) ;
if ( V_115 & V_118 ) {
F_23 ( ( V_36 L_21 ) ) ;
return;
}
F_3 ( V_119 | V_120 | V_51 , V_1 + V_52 ) ;
V_44 = F_5 ( V_1 + V_54 ) ;
V_116 = F_5 ( V_1 + V_54 ) ;
V_116 &= 0x07ff ;
F_21 ( ( L_22 , V_44 , V_116 ) ) ;
V_116 -= 6 ;
if ( ! ( V_44 & V_121 ) ) {
struct V_25 * V_26 ;
T_3 * V_49 ;
if ( V_44 & V_122 )
V_116 ++ ;
if ( V_44 & V_123 )
V_16 -> V_34 . V_124 ++ ;
V_26 = F_52 ( V_16 , V_116 + 5 ) ;
if ( V_26 == NULL ) {
F_15 (KERN_NOTICE CARDNAME L_23 ) ;
V_16 -> V_34 . V_125 ++ ;
goto V_126;
}
F_53 ( V_26 , 2 ) ;
V_49 = F_54 ( V_26 , V_116 ) ;
#ifdef F_27
F_25 ( ( L_24 ,
V_116 >> 2 , V_116 & 3 ) ) ;
F_55 ( V_1 + V_54 , V_49 , V_116 >> 2 ) ;
F_56 ( V_1 + V_54 , V_49 + ( V_116 & 0xFFFFFC ) ,
V_116 & 0x3 ) ;
#else
F_25 ( ( L_25 ,
( V_116 >> 1 ) , V_116 & 1 ) ) ;
F_57 ( V_1 + V_54 , V_49 , V_116 >> 1 ) ;
if ( V_116 & 1 ) {
V_49 += V_116 & ~ 1 ;
* ( V_49 ++ ) = F_19 ( V_1 + V_54 ) ;
}
#endif
#if V_53 > 2
F_26 ( V_49 , V_116 ) ;
#endif
V_26 -> V_127 = F_58 ( V_26 , V_16 ) ;
F_59 ( V_26 ) ;
V_16 -> V_34 . V_128 ++ ;
V_16 -> V_34 . V_129 += V_116 ;
} else {
V_16 -> V_34 . V_130 ++ ;
if ( V_44 & V_131 ) V_16 -> V_34 . V_132 ++ ;
if ( V_44 & ( V_133 | V_134 ) )
V_16 -> V_34 . V_135 ++ ;
if ( V_44 & V_136 ) V_16 -> V_34 . V_137 ++ ;
}
V_126:
F_3 ( V_138 , V_1 + V_10 ) ;
}
static void F_60 ( struct V_15 * V_16 )
{
int V_1 = V_16 -> V_29 ;
struct V_27 * V_28 = F_13 ( V_16 ) ;
T_3 V_139 ;
T_3 V_47 ;
T_2 V_140 ;
V_139 = F_19 ( V_1 + V_50 ) ;
V_47 = F_5 ( V_1 + V_117 ) ;
V_47 &= 0x7F ;
F_6 ( V_47 , V_1 + V_50 ) ;
F_3 ( V_51 | V_119 , V_1 + V_52 ) ;
V_140 = F_5 ( V_1 + V_54 ) ;
F_25 ( ( V_36 L_26 , V_140 ) ) ;
V_16 -> V_34 . V_141 ++ ;
if ( V_140 & V_142 ) V_16 -> V_34 . V_143 ++ ;
if ( V_140 & V_144 ) {
F_15 (KERN_DEBUG CARDNAME
L_27 ) ;
V_16 -> V_34 . V_145 ++ ;
}
#if 0
if ( tx_status & TS_16COL ) { ... }
#endif
if ( V_140 & V_146 ) {
F_15 ( V_36 L_28 ) ;
}
F_2 ( 0 ) ;
F_3 ( F_5 ( V_1 + V_6 ) | V_147 , V_1 + V_6 ) ;
F_2 ( 2 ) ;
F_3 ( V_148 , V_1 + V_10 ) ;
V_28 -> V_41 -- ;
F_6 ( V_139 , V_1 + V_50 ) ;
}
static T_5 V_110 ( int V_70 , void * V_149 )
{
struct V_15 * V_16 = V_149 ;
int V_1 = V_16 -> V_29 ;
struct V_27 * V_28 = F_13 ( V_16 ) ;
T_3 V_44 ;
T_2 V_150 ;
T_3 V_151 ;
int V_76 ;
T_2 V_152 ;
T_2 V_153 ;
int V_154 = 0 ;
F_25 ( ( V_36 L_29 ) ) ;
V_152 = F_5 ( V_1 + V_94 ) ;
F_2 ( 2 ) ;
V_153 = F_5 ( V_1 + V_52 ) ;
V_151 = F_19 ( V_1 + V_11 ) ;
F_6 ( 0 , V_1 + V_11 ) ;
V_76 = 4 ;
F_21 ( ( V_155 V_36 L_30 , V_151 ) ) ;
do {
V_44 = F_19 ( V_1 + V_45 ) & V_151 ;
if ( ! V_44 )
break;
V_154 = 1 ;
F_25 ( ( V_155 V_36
L_31 , V_44 ) ) ;
if ( V_44 & V_156 ) {
F_21 ( ( V_155 V_36
L_32 ) ) ;
F_51 ( V_16 ) ;
} else if ( V_44 & V_57 ) {
F_21 ( ( V_155 V_36
L_33 ) ) ;
F_60 ( V_16 ) ;
F_6 ( V_57 , V_1 + V_45 ) ;
} else if ( V_44 & V_58 ) {
F_2 ( 0 ) ;
V_150 = F_5 ( V_1 + V_157 ) ;
V_16 -> V_34 . V_158 += V_150 & 0xF ;
V_150 >>= 4 ;
V_16 -> V_34 . V_158 += V_150 & 0xF ;
F_2 ( 2 ) ;
F_21 ( ( V_155 V_36
L_34 ) ) ;
F_6 ( V_58 , V_1 + V_45 ) ;
V_151 &= ~ V_58 ;
V_16 -> V_34 . V_159 += V_28 -> V_41 ;
V_28 -> V_41 = 0 ;
} else if ( V_44 & V_46 ) {
F_21 ( ( V_160 V_36
L_35 ) ) ;
V_151 &= ~ V_46 ;
F_22 ( V_16 ) ;
V_151 |= ( V_58 | V_57 ) ;
F_17 ( V_16 ) ;
F_21 ( ( V_36 L_36 ) ) ;
} else if ( V_44 & V_161 ) {
V_16 -> V_34 . V_130 ++ ;
V_16 -> V_34 . V_162 ++ ;
F_6 ( V_161 , V_1 + V_45 ) ;
} else if ( V_44 & V_163 ) {
F_23 ( ( V_36 L_37 ) ) ;
} else if ( V_44 & V_164 ) {
F_23 ( ( V_36 L_38 ) ) ;
F_6 ( V_164 , V_1 + V_45 ) ;
}
} while ( V_76 -- );
F_2 ( 2 ) ;
F_6 ( V_151 , V_1 + V_11 ) ;
F_25 ( ( V_155 V_36 L_39 , V_151 ) ) ;
F_3 ( V_153 , V_1 + V_52 ) ;
F_2 ( V_152 ) ;
F_25 ( ( V_36 L_40 ) ) ;
return F_61 ( V_154 ) ;
}
static int F_62 ( struct V_15 * V_16 )
{
F_14 ( V_16 ) ;
F_8 ( V_16 -> V_29 ) ;
return 0 ;
}
static void F_63 ( struct V_15 * V_16 )
{
short V_1 = V_16 -> V_29 ;
F_2 ( 0 ) ;
if ( V_16 -> V_165 & V_166 )
F_3 ( F_5 ( V_1 + V_3 ) | V_167 , V_1 + V_3 ) ;
else if ( V_16 -> V_165 & V_168 )
F_3 ( F_5 ( V_1 + V_3 ) | V_169 , V_1 + V_3 ) ;
else if ( ! F_64 ( V_16 ) ) {
F_3 ( F_5 ( V_1 + V_3 ) & ~ ( V_167 | V_169 ) ,
V_1 + V_3 ) ;
F_9 ( V_1 , V_16 ) ;
}
else {
F_3 ( F_5 ( V_1 + V_3 ) & ~ ( V_167 | V_169 ) ,
V_1 + V_3 ) ;
F_2 ( 3 ) ;
F_3 ( 0 , V_1 + V_24 ) ;
F_3 ( 0 , V_1 + V_170 ) ;
F_3 ( 0 , V_1 + V_171 ) ;
F_3 ( 0 , V_1 + V_172 ) ;
}
}
int T_4 F_65 ( void )
{
if ( V_69 == 0 )
F_15 (KERN_WARNING
CARDNAMEL_41 ) ;
V_173 = F_33 ( - 1 ) ;
if ( F_66 ( V_173 ) )
return F_67 ( V_173 ) ;
return 0 ;
}
void T_6 F_68 ( void )
{
F_69 ( V_173 ) ;
F_39 ( V_173 -> V_70 , V_173 ) ;
F_40 ( V_173 -> V_29 , V_75 ) ;
F_41 ( V_173 ) ;
}
