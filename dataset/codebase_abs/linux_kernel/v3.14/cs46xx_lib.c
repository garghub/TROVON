static unsigned short F_1 ( struct V_1 * V_2 ,
unsigned short V_3 ,
int V_4 )
{
int V_5 ;
unsigned short V_6 , V_7 ;
T_1 V_8 = 0 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return 0xffff ;
V_2 -> V_11 ( V_2 , 1 ) ;
if ( V_4 == V_10 )
V_8 = V_12 ;
F_3 ( V_2 , V_13 + V_8 ) ;
V_7 = F_3 ( V_2 , V_14 ) ;
if ( ( V_7 & V_15 ) == 0 ) {
F_4 ( V_16 L_1 , V_7 ) ;
F_5 ( V_2 , V_14 , ( V_7 & ( ~ V_17 ) ) | V_15 ) ;
F_6 ( 50 ) ;
V_7 = F_3 ( V_2 , V_14 + V_8 ) ;
F_5 ( V_2 , V_14 , V_7 | V_17 | V_15 ) ;
}
F_5 ( V_2 , V_18 , V_3 ) ;
F_5 ( V_2 , V_19 , 0 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_20 |
V_15 | V_17 |
V_21 ) ;
F_5 ( V_2 , V_14 , V_22 | V_20 |
V_15 | V_17 |
V_21 ) ;
} else {
F_5 ( V_2 , V_14 , V_22 | V_23 |
V_20 | V_15 | V_17 |
V_21 ) ;
}
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_22 ) )
goto V_24;
}
F_4 ( V_25 L_2 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_24:
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
if ( F_3 ( V_2 , V_27 + V_8 ) & V_28 )
goto V_29;
F_7 ( 10 ) ;
}
F_4 ( V_25 L_3 , V_4 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_29:
#if 0
printk(KERN_DEBUG "e) reg = 0x%x, val = 0x%x, BA0_ACCAD = 0x%x\n", reg,
snd_cs46xx_peekBA0(chip, BA0_ACSDA),
snd_cs46xx_peekBA0(chip, BA0_ACCAD));
#endif
V_6 = F_3 ( V_2 , V_13 + V_8 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
return V_6 ;
}
static unsigned short F_8 ( struct V_30 * V_31 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned short V_33 ;
int V_4 = V_31 -> V_34 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return 0xffff ;
V_33 = F_1 ( V_2 , V_3 , V_4 ) ;
return V_33 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned short V_3 ,
unsigned short V_33 ,
int V_4 )
{
int V_5 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
V_2 -> V_11 ( V_2 , 1 ) ;
F_5 ( V_2 , V_18 , V_3 ) ;
F_5 ( V_2 , V_19 , V_33 ) ;
F_3 ( V_2 , V_14 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_15 |
V_17 | V_21 ) ;
F_5 ( V_2 , V_14 , V_22 | V_15 |
V_17 | V_21 ) ;
} else {
F_5 ( V_2 , V_14 , V_22 | V_23 |
V_15 | V_17 | V_21 ) ;
}
for ( V_5 = 0 ; V_5 < 4000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_22 ) ) {
goto V_26;
}
}
F_4 ( V_25 L_4 , V_4 , V_3 , V_33 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
}
static void F_10 ( struct V_30 * V_31 ,
unsigned short V_3 ,
unsigned short V_33 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
int V_4 = V_31 -> V_34 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
F_9 ( V_2 , V_3 , V_33 , V_4 ) ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 * V_35 ,
unsigned long V_8 ,
unsigned long V_36 )
{
void T_2 * V_37 ;
unsigned int V_38 = V_8 >> 16 ;
V_8 = V_8 & 0xffff ;
if ( F_2 ( ( V_8 & 3 ) || ( V_36 & 3 ) ) )
return - V_39 ;
V_37 = V_2 -> V_40 . V_41 [ V_38 + 1 ] . V_42 + V_8 ;
V_36 /= sizeof( T_1 ) ;
while ( V_36 -- > 0 ) {
F_12 ( * V_35 ++ , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
static inline void F_13 ( void * V_37 , const void * V_35 , unsigned int V_36 )
{
#ifdef F_14
memcpy ( V_37 , V_35 , V_36 ) ;
#else
T_1 * V_43 = V_37 ;
const T_3 * V_44 = V_35 ;
V_36 /= 4 ;
while ( V_36 -- > 0 )
* V_43 ++ = F_15 ( * V_44 ++ ) ;
#endif
}
static void F_16 ( struct V_45 * V_46 )
{
if ( ! V_46 )
return;
F_17 ( V_46 -> V_47 ) ;
F_17 ( V_46 -> V_48 . V_49 ) ;
if ( V_46 -> V_50 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_46 -> V_52 ; V_51 ++ )
F_17 ( V_46 -> V_50 [ V_51 ] . V_53 ) ;
F_17 ( V_46 -> V_50 ) ;
}
F_17 ( V_46 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_45 * * V_54 ,
const char * V_55 )
{
int V_51 , V_56 ;
unsigned int V_57 , V_58 , V_59 ;
const T_3 * V_60 ;
struct V_45 * V_46 = NULL ;
const struct V_61 * V_62 ;
char V_63 [ 32 ] ;
sprintf ( V_63 , L_5 , V_55 ) ;
V_56 = F_19 ( & V_62 , V_63 , & V_2 -> V_64 -> V_65 ) ;
if ( V_56 < 0 )
return V_56 ;
V_59 = V_62 -> V_66 / 4 ;
if ( V_59 < 2 ) {
V_56 = - V_39 ;
goto error;
}
V_56 = - V_67 ;
V_46 = F_20 ( sizeof( * V_46 ) , V_68 ) ;
if ( ! V_46 )
goto error;
V_46 -> V_47 = F_21 ( V_55 , V_68 ) ;
if ( ! V_46 -> V_47 )
goto error;
V_58 = 0 ;
V_60 = ( const T_3 * ) V_62 -> V_53 ;
V_57 = V_46 -> V_48 . V_69 = F_15 ( V_60 [ V_58 ++ ] ) ;
if ( V_57 >= 40 )
goto V_70;
V_46 -> V_48 . V_49 =
F_22 ( V_57 , sizeof( struct V_71 ) , V_68 ) ;
if ( ! V_46 -> V_48 . V_49 )
goto error;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
struct V_71 * V_72 =
& V_46 -> V_48 . V_49 [ V_51 ] ;
if ( V_58 + 2 + V_73 / 4 > V_59 )
goto V_70;
V_72 -> V_74 = F_15 ( V_60 [ V_58 ++ ] ) ;
memcpy ( V_72 -> V_75 , & V_60 [ V_58 ] , V_73 - 1 ) ;
V_58 += V_73 / 4 ;
V_72 -> V_76 = F_15 ( V_60 [ V_58 ++ ] ) ;
}
if ( V_58 >= V_59 )
goto V_70;
V_57 = V_46 -> V_52 = F_15 ( V_60 [ V_58 ++ ] ) ;
if ( V_57 > 10 )
goto V_70;
V_46 -> V_50 =
F_22 ( V_57 , sizeof( struct V_77 ) , V_68 ) ;
if ( ! V_46 -> V_50 )
goto error;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
struct V_77 * V_72 = & V_46 -> V_50 [ V_51 ] ;
if ( V_58 + 3 > V_59 )
goto V_70;
V_72 -> V_78 = F_15 ( V_60 [ V_58 ++ ] ) ;
V_72 -> V_8 = F_15 ( V_60 [ V_58 ++ ] ) ;
V_72 -> V_66 = F_15 ( V_60 [ V_58 ++ ] ) ;
if ( V_58 + V_72 -> V_66 > V_59 )
goto V_70;
V_72 -> V_53 = F_23 ( V_72 -> V_66 * 4 , V_68 ) ;
if ( ! V_72 -> V_53 )
goto error;
F_13 ( V_72 -> V_53 , & V_60 [ V_58 ] , V_72 -> V_66 * 4 ) ;
V_58 += V_72 -> V_66 ;
}
* V_54 = V_46 ;
F_24 ( V_62 ) ;
return 0 ;
V_70:
V_56 = - V_39 ;
error:
F_16 ( V_46 ) ;
F_24 ( V_62 ) ;
return V_56 ;
}
int F_25 ( struct V_1 * V_2 ,
unsigned long V_8 ,
unsigned long V_36 )
{
void T_2 * V_37 ;
unsigned int V_38 = V_8 >> 16 ;
V_8 = V_8 & 0xffff ;
if ( F_2 ( ( V_8 & 3 ) || ( V_36 & 3 ) ) )
return - V_39 ;
V_37 = V_2 -> V_40 . V_41 [ V_38 + 1 ] . V_42 + V_8 ;
V_36 /= sizeof( T_1 ) ;
while ( V_36 -- > 0 ) {
F_12 ( 0 , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const struct V_61 * V_62 ;
int V_51 , V_66 , V_56 ;
V_56 = F_19 ( & V_62 , L_6 , & V_2 -> V_64 -> V_65 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_62 -> V_66 != sizeof( * V_2 -> V_79 ) ) {
V_56 = - V_39 ;
goto error;
}
V_2 -> V_79 = F_26 ( sizeof( * V_2 -> V_79 ) ) ;
if ( ! V_2 -> V_79 ) {
V_56 = - V_67 ;
goto error;
}
F_13 ( V_2 -> V_79 , V_62 -> V_53 , sizeof( * V_2 -> V_79 ) ) ;
V_66 = 0 ;
for ( V_51 = 0 ; V_51 < V_80 ; V_51 ++ )
V_66 += V_2 -> V_79 -> V_81 [ V_51 ] . V_66 ;
if ( V_66 > V_82 * 4 )
V_56 = - V_39 ;
error:
F_24 ( V_62 ) ;
return V_56 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_41 , V_56 ;
unsigned int V_8 = 0 ;
struct V_83 * V_79 = V_2 -> V_79 ;
for ( V_41 = 0 ; V_41 < V_80 ; V_41 ++ ) {
V_56 = F_11 ( V_2 ,
& V_79 -> V_84 [ V_8 ] ,
V_79 -> V_81 [ V_41 ] . V_8 ,
V_79 -> V_81 [ V_41 ] . V_66 ) ;
if ( V_56 < 0 )
return V_56 ;
V_8 += V_79 -> V_81 [ V_41 ] . V_66 >> 2 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_41 ;
F_29 ( V_2 , V_85 , V_86 ) ;
F_29 ( V_2 , V_85 , V_87 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
F_29 ( V_2 , V_88 , V_89 + V_41 ) ;
F_29 ( V_2 , V_90 , 0xFFFF ) ;
}
F_29 ( V_2 , V_88 , 0 ) ;
F_29 ( V_2 , V_91 , 0xadf ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_92 )
{
T_1 V_51 , V_93 = 0 ;
for( V_51 = 0 ; V_51 < 50 ; V_51 ++ ) {
V_93 = F_3 ( V_2 , V_94 ) ;
if( ! ( V_93 & V_95 ) )
break;
F_31 ( V_92 ) ;
}
if( V_93 & V_95 ) {
F_4 ( V_25 L_7
L_8 ) ;
return - V_39 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_41 , V_96 = 0 ;
unsigned int V_7 ;
V_7 = F_3 ( V_2 , V_97 ) ;
if ( ! ( V_7 & V_98 ) ) {
F_5 ( V_2 , V_97 , V_7 | V_98 ) ;
V_96 = 1 ;
}
F_5 ( V_2 , V_99 , 0 ) ;
for ( V_41 = 0 ; V_41 < 0xFF ; V_41 ++ ) {
if ( F_30 ( V_2 , 1 ) ) {
F_33 ( L_9 , V_41 ) ;
if ( V_96 )
F_5 ( V_2 , V_97 , V_7 ) ;
break;
}
F_5 ( V_2 , V_100 , V_41 ) ;
F_5 ( V_2 , V_101 , V_102 ) ;
}
if ( V_96 )
F_5 ( V_2 , V_97 , V_7 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_103 ;
F_29 ( V_2 , V_91 , 0xadf ) ;
F_29 ( V_2 , V_85 , V_104 | V_105 | V_87 ) ;
for ( V_103 = 0 ; V_103 < 25 ; V_103 ++ ) {
F_7 ( 50 ) ;
if ( ! ( F_35 ( V_2 , V_85 ) & V_105 ) )
break;
}
if ( F_35 ( V_2 , V_85 ) & V_105 )
F_4 ( V_25 L_10 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_85 , 0 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_106 )
{
unsigned long V_107 ;
unsigned int V_108 , V_109 ;
unsigned int V_110 ;
unsigned int V_111 , V_112 ;
V_108 = V_106 << 16 ;
V_110 = V_108 / 48000 ;
V_108 -= V_110 * 48000 ;
V_108 <<= 10 ;
V_110 <<= 10 ;
V_109 = V_108 / 48000 ;
V_110 += V_109 ;
V_108 -= V_109 * 48000 ;
V_111 = V_108 / V_113 ;
V_108 -= V_111 * V_113 ;
V_112 = V_108 ;
F_38 ( & V_2 -> V_114 , V_107 ) ;
F_29 ( V_2 , V_115 ,
( ( V_112 << 16 ) & 0xFFFF0000 ) | ( V_111 & 0xFFFF ) ) ;
F_29 ( V_2 , V_116 , V_110 ) ;
F_39 ( & V_2 -> V_114 , V_107 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_106 )
{
unsigned long V_107 ;
unsigned int V_110 , V_117 , V_108 , V_109 ;
unsigned int V_111 , V_112 , V_118 ;
unsigned int V_119 , V_103 ;
if ( ( V_106 * 9 ) < 48000 )
V_106 = 48000 / 9 ;
if ( V_106 > 48000 )
V_106 = 48000 ;
V_108 = V_106 << 16 ;
V_117 = V_108 / 48000 ;
V_108 -= V_117 * 48000 ;
V_108 <<= 7 ;
V_117 <<= 7 ;
V_117 += V_108 / 48000 ;
V_117 ^= 0xFFFFFFFF ;
V_117 ++ ;
V_108 = 48000 << 16 ;
V_110 = V_108 / V_106 ;
V_108 -= V_110 * V_106 ;
V_108 <<= 10 ;
V_110 <<= 10 ;
V_109 = V_108 / V_106 ;
V_110 += V_109 ;
V_108 -= V_109 * V_106 ;
V_111 = V_108 / V_113 ;
V_108 -= V_111 * V_113 ;
V_112 = V_108 ;
V_118 = ( ( 48000 * 24 ) + V_106 - 1 ) / V_106 ;
F_38 ( & V_2 -> V_114 , V_107 ) ;
F_29 ( V_2 , V_120 ,
( ( V_112 << 16 ) & 0xFFFF0000 ) | ( V_111 & 0xFFFF ) ) ;
F_29 ( V_2 , V_121 , V_117 ) ;
F_29 ( V_2 , V_122 ,
( ( ( V_123 + ( V_118 << 2 ) ) << 16 ) & 0xFFFF0000 ) | 0x80 ) ;
F_29 ( V_2 , V_124 , V_110 ) ;
F_39 ( & V_2 -> V_114 , V_107 ) ;
V_119 = 1 ;
for ( V_103 = 2 ; V_103 <= 64 ; V_103 *= 2 ) {
if ( ( ( V_106 / V_103 ) * V_103 ) != V_106 )
V_119 *= 2 ;
}
if ( ( ( V_106 / 3 ) * 3 ) != V_106 ) {
V_119 *= 3 ;
}
for ( V_103 = 5 ; V_103 <= 125 ; V_103 *= 5 ) {
if ( ( ( V_106 / V_103 ) * V_103 ) != V_106 )
V_119 *= 5 ;
}
F_38 ( & V_2 -> V_114 , V_107 ) ;
F_29 ( V_2 , V_125 , V_119 ) ;
F_29 ( V_2 , V_126 , ( 0x00800000 | V_119 ) ) ;
F_29 ( V_2 , V_127 , 0x0000FFFF ) ;
F_29 ( V_2 , V_128 , ( ( 65536 * V_106 ) / 24000 ) ) ;
F_29 ( V_2 , ( V_128 + 4 ) , 0x0000FFFF ) ;
F_39 ( & V_2 -> V_114 , V_107 ) ;
}
static void F_41 ( struct V_129 * V_130 ,
struct V_131 * V_132 , T_4 V_133 )
{
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 = V_135 -> V_32 ;
memcpy ( V_137 -> V_138 . V_139 + V_132 -> V_140 , V_135 -> V_141 + V_132 -> V_142 , V_133 ) ;
}
static int F_42 ( struct V_129 * V_130 )
{
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 = V_135 -> V_32 ;
F_43 ( V_130 , & V_137 -> V_143 , F_41 ) ;
return 0 ;
}
static void F_44 ( struct V_129 * V_130 ,
struct V_131 * V_132 , T_4 V_133 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
memcpy ( V_135 -> V_141 + V_132 -> V_142 ,
V_2 -> V_144 . V_138 . V_139 + V_132 -> V_140 , V_133 ) ;
}
static int F_46 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
F_47 ( V_130 , & V_2 -> V_144 . V_143 , F_44 ) ;
return 0 ;
}
static T_5 F_48 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
T_4 V_145 ;
struct V_136 * V_137 = V_130 -> V_135 -> V_32 ;
if ( F_2 ( ! V_137 -> V_146 ) )
return - V_147 ;
#ifdef F_49
V_145 = F_35 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 + 2 ) << 2 ) ;
#else
V_145 = F_35 ( V_2 , V_149 ) ;
#endif
V_145 -= V_137 -> V_138 . V_150 ;
return V_145 >> V_137 -> V_151 ;
}
static T_5 F_50 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
T_4 V_145 ;
struct V_136 * V_137 = V_130 -> V_135 -> V_32 ;
#ifdef F_49
if ( F_2 ( ! V_137 -> V_146 ) )
return - V_147 ;
V_145 = F_35 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 + 2 ) << 2 ) ;
#else
V_145 = F_35 ( V_2 , V_149 ) ;
#endif
V_145 -= V_137 -> V_138 . V_150 ;
return F_51 ( V_130 , & V_137 -> V_143 , V_145 ) ;
}
static T_5 F_52 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
T_4 V_145 = F_35 ( V_2 , V_152 ) - V_2 -> V_144 . V_138 . V_150 ;
return V_145 >> V_2 -> V_144 . V_151 ;
}
static T_5 F_53 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
T_4 V_145 = F_35 ( V_2 , V_152 ) - V_2 -> V_144 . V_138 . V_150 ;
return F_54 ( V_130 , & V_2 -> V_144 . V_143 , V_145 ) ;
}
static int F_55 ( struct V_129 * V_130 ,
int V_153 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
int V_6 = 0 ;
#ifdef F_49
struct V_136 * V_137 = V_130 -> V_135 -> V_32 ;
if ( ! V_137 -> V_146 ) {
return - V_147 ;
}
#endif
switch ( V_153 ) {
case V_154 :
case V_155 :
#ifdef F_49
F_29 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 +
V_156 ) << 2 , 0x80008000 ) ;
if ( V_137 -> V_146 -> V_157 )
F_56 ( V_2 , V_137 -> V_146 ) ;
if ( V_130 -> V_135 -> V_158 != V_159 )
F_42 ( V_130 ) ;
#else
F_57 ( & V_2 -> V_114 ) ;
if ( V_130 -> V_135 -> V_158 != V_159 )
F_42 ( V_130 ) ;
{ unsigned int V_7 ;
V_7 = F_35 ( V_2 , V_160 ) ;
V_7 &= 0x0000ffff ;
F_29 ( V_2 , V_160 , V_2 -> V_161 | V_7 ) ;
}
F_58 ( & V_2 -> V_114 ) ;
#endif
break;
case V_162 :
case V_163 :
#ifdef F_49
F_29 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 +
V_156 ) << 2 , 0xffffffff ) ;
if ( ! V_137 -> V_146 -> V_157 )
F_59 ( V_2 , V_137 -> V_146 ) ;
#else
F_57 ( & V_2 -> V_114 ) ;
{ unsigned int V_7 ;
V_7 = F_35 ( V_2 , V_160 ) ;
V_7 &= 0x0000ffff ;
F_29 ( V_2 , V_160 , V_7 ) ;
}
F_58 ( & V_2 -> V_114 ) ;
#endif
break;
default:
V_6 = - V_39 ;
break;
}
return V_6 ;
}
static int F_60 ( struct V_129 * V_130 ,
int V_153 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
unsigned int V_7 ;
int V_6 = 0 ;
F_57 ( & V_2 -> V_114 ) ;
switch ( V_153 ) {
case V_154 :
case V_155 :
V_7 = F_35 ( V_2 , V_164 ) ;
V_7 &= 0xffff0000 ;
F_29 ( V_2 , V_164 , V_2 -> V_144 . V_165 | V_7 ) ;
break;
case V_162 :
case V_163 :
V_7 = F_35 ( V_2 , V_164 ) ;
V_7 &= 0xffff0000 ;
F_29 ( V_2 , V_164 , V_7 ) ;
break;
default:
V_6 = - V_39 ;
break;
}
F_58 ( & V_2 -> V_114 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_136 * V_137 ,
int V_166 )
{
if ( V_137 -> V_146 == NULL ) {
V_137 -> V_146 = F_62 ( V_2 , V_166 ,
V_137 , V_137 -> V_138 . V_150 , V_137 -> V_167 ) ;
if ( V_137 -> V_146 == NULL ) {
F_4 ( V_25 L_11 ) ;
return - V_67 ;
}
V_137 -> V_146 -> V_166 = V_166 ;
} else
if ( ( int ) V_137 -> V_146 -> V_166 != V_166 ) {
int V_157 = V_137 -> V_146 -> V_157 ;
F_63 ( V_2 , V_137 -> V_146 ) ;
if ( ( V_137 -> V_146 = F_62 ( V_2 , V_166 , V_137 ,
V_137 -> V_138 . V_150 ,
V_137 -> V_167 ) ) == NULL ) {
F_4 ( V_25 L_12 ) ;
return - V_67 ;
}
if ( ! V_157 ) F_56 ( V_2 , V_137 -> V_146 ) ;
V_137 -> V_146 -> V_166 = V_166 ;
}
return 0 ;
}
static int F_64 ( struct V_129 * V_130 ,
struct V_168 * V_169 )
{
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 ;
int V_56 ;
#ifdef F_49
struct V_1 * V_2 = F_45 ( V_130 ) ;
int V_166 = F_65 ( V_169 ) ;
int V_170 = F_66 ( V_169 ) ;
#endif
V_137 = V_135 -> V_32 ;
#ifdef F_49
if ( F_2 ( ! V_166 ) )
return - V_147 ;
F_67 ( & V_2 -> V_171 ) ;
if ( F_61 ( V_2 , V_137 , V_166 ) ) {
F_68 ( & V_2 -> V_171 ) ;
return - V_147 ;
}
F_2 ( ! V_137 -> V_146 ) ;
if ( ! V_137 -> V_146 ) {
F_68 ( & V_2 -> V_171 ) ;
return - V_147 ;
}
if ( F_69 ( V_2 , V_137 -> V_146 , V_170 ) ) {
F_68 ( & V_2 -> V_171 ) ;
return - V_39 ;
}
F_33 ( L_13 ,
V_170 , F_70 ( V_169 ) ,
F_71 ( V_169 ) ) ;
#endif
if ( F_70 ( V_169 ) == V_159 ) {
if ( V_135 -> V_141 != V_137 -> V_138 . V_139 )
F_72 ( V_130 ) ;
V_135 -> V_141 = V_137 -> V_138 . V_139 ;
V_135 -> V_172 = V_137 -> V_138 . V_150 ;
V_135 -> V_173 = V_137 -> V_138 . V_133 ;
#ifdef F_49
if ( V_137 -> V_167 == V_174 ) {
V_130 -> V_175 = & V_176 ;
} else if ( V_137 -> V_167 == V_177 ) {
V_130 -> V_175 = & V_178 ;
} else if ( V_137 -> V_167 == V_179 ) {
V_130 -> V_175 = & V_180 ;
} else if ( V_137 -> V_167 == V_181 ) {
V_130 -> V_175 = & V_182 ;
} else {
F_73 () ;
}
#else
V_130 -> V_175 = & V_176 ;
#endif
} else {
if ( V_135 -> V_141 == V_137 -> V_138 . V_139 ) {
V_135 -> V_141 = NULL ;
V_135 -> V_172 = 0 ;
V_135 -> V_173 = 0 ;
}
if ( ( V_56 = F_74 ( V_130 , F_71 ( V_169 ) ) ) < 0 ) {
#ifdef F_49
F_68 ( & V_2 -> V_171 ) ;
#endif
return V_56 ;
}
#ifdef F_49
if ( V_137 -> V_167 == V_174 ) {
V_130 -> V_175 = & V_183 ;
} else if ( V_137 -> V_167 == V_177 ) {
V_130 -> V_175 = & V_184 ;
} else if ( V_137 -> V_167 == V_179 ) {
V_130 -> V_175 = & V_185 ;
} else if ( V_137 -> V_167 == V_181 ) {
V_130 -> V_175 = & V_186 ;
} else {
F_73 () ;
}
#else
V_130 -> V_175 = & V_183 ;
#endif
}
#ifdef F_49
F_68 ( & V_2 -> V_171 ) ;
#endif
return 0 ;
}
static int F_75 ( struct V_129 * V_130 )
{
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 ;
V_137 = V_135 -> V_32 ;
if ( ! V_137 ) return - V_147 ;
if ( V_135 -> V_141 != V_137 -> V_138 . V_139 )
F_72 ( V_130 ) ;
V_135 -> V_141 = NULL ;
V_135 -> V_172 = 0 ;
V_135 -> V_173 = 0 ;
return 0 ;
}
static int F_76 ( struct V_129 * V_130 )
{
unsigned int V_7 ;
unsigned int V_187 ;
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 ;
V_137 = V_135 -> V_32 ;
#ifdef F_49
if ( F_2 ( ! V_137 -> V_146 ) )
return - V_147 ;
V_187 = F_35 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 + 1 ) << 2 ) ;
V_187 &= ~ 0x0000f03f ;
#else
V_187 = F_35 ( V_2 , V_188 ) ;
V_187 &= ~ 0x0000f03f ;
#endif
V_137 -> V_151 = 2 ;
if ( V_135 -> V_189 == 1 ) {
V_137 -> V_151 -- ;
V_187 |= 0x00002000 ;
}
if ( F_77 ( V_135 -> V_190 ) == 8 ) {
V_137 -> V_151 -- ;
V_187 |= 0x00001000 ;
}
if ( F_78 ( V_135 -> V_190 ) )
V_187 |= 0x00008000 ;
if ( F_77 ( V_135 -> V_190 ) != 8 ) {
if ( F_79 ( V_135 -> V_190 ) )
V_187 |= 0x00004000 ;
}
memset ( & V_137 -> V_143 , 0 , sizeof( V_137 -> V_143 ) ) ;
V_137 -> V_143 . V_191 = F_80 ( V_130 ) ;
V_137 -> V_143 . V_192 = V_135 -> V_170 * V_159 << V_137 -> V_151 ;
#ifdef F_49
V_7 = F_35 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 ) << 2 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_137 -> V_151 ) - 1 ;
F_29 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 ) << 2 , V_7 ) ;
F_29 ( V_2 , ( V_137 -> V_146 -> V_148 -> V_74 + 1 ) << 2 , V_187 | V_137 -> V_146 -> V_193 ) ;
#else
F_29 ( V_2 , V_149 , V_137 -> V_138 . V_150 ) ;
V_7 = F_35 ( V_2 , V_194 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_137 -> V_151 ) - 1 ;
F_29 ( V_2 , V_194 , V_7 ) ;
F_29 ( V_2 , V_188 , V_187 ) ;
F_37 ( V_2 , V_135 -> V_106 ) ;
#endif
return 0 ;
}
static int F_81 ( struct V_129 * V_130 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
int V_56 ;
#ifdef F_49
F_82 ( V_2 , F_66 ( V_169 ) ) ;
#endif
if ( V_135 -> V_158 == V_159 ) {
if ( V_135 -> V_141 != V_2 -> V_144 . V_138 . V_139 )
F_72 ( V_130 ) ;
V_135 -> V_141 = V_2 -> V_144 . V_138 . V_139 ;
V_135 -> V_172 = V_2 -> V_144 . V_138 . V_150 ;
V_135 -> V_173 = V_2 -> V_144 . V_138 . V_133 ;
V_130 -> V_175 = & V_195 ;
} else {
if ( V_135 -> V_141 == V_2 -> V_144 . V_138 . V_139 ) {
V_135 -> V_141 = NULL ;
V_135 -> V_172 = 0 ;
V_135 -> V_173 = 0 ;
}
if ( ( V_56 = F_74 ( V_130 , F_71 ( V_169 ) ) ) < 0 )
return V_56 ;
V_130 -> V_175 = & V_196 ;
}
return 0 ;
}
static int F_83 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
if ( V_135 -> V_141 != V_2 -> V_144 . V_138 . V_139 )
F_72 ( V_130 ) ;
V_135 -> V_141 = NULL ;
V_135 -> V_172 = 0 ;
V_135 -> V_173 = 0 ;
return 0 ;
}
static int F_84 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
F_29 ( V_2 , V_152 , V_2 -> V_144 . V_138 . V_150 ) ;
V_2 -> V_144 . V_151 = 2 ;
memset ( & V_2 -> V_144 . V_143 , 0 , sizeof( V_2 -> V_144 . V_143 ) ) ;
V_2 -> V_144 . V_143 . V_191 = F_80 ( V_130 ) ;
V_2 -> V_144 . V_143 . V_192 = V_135 -> V_170 * V_159 << 2 ;
F_40 ( V_2 , V_135 -> V_106 ) ;
return 0 ;
}
static T_6 F_85 ( int V_197 , void * V_198 )
{
struct V_1 * V_2 = V_198 ;
T_1 V_199 ;
#ifdef F_49
struct V_200 * V_201 = V_2 -> V_200 ;
T_1 V_202 ;
int V_51 ;
struct V_136 * V_137 = NULL ;
#endif
V_199 = F_3 ( V_2 , V_203 ) ;
if ( ( V_199 & 0x7fffffff ) == 0 ) {
F_5 ( V_2 , V_204 , V_205 | V_206 ) ;
return V_207 ;
}
#ifdef F_49
V_202 = F_3 ( V_2 , V_208 ) ;
for ( V_51 = 0 ; V_51 < V_209 ; ++ V_51 ) {
if ( V_51 <= 15 ) {
if ( V_199 & ( 1 << V_51 ) ) {
if ( V_51 == V_210 ) {
if ( V_2 -> V_144 . V_130 )
F_86 ( V_2 -> V_144 . V_130 ) ;
} else {
if ( V_201 -> V_211 [ V_51 ] . V_212 &&
V_201 -> V_211 [ V_51 ] . V_32 &&
! V_201 -> V_211 [ V_51 ] . V_157 ) {
V_137 = V_201 -> V_211 [ V_51 ] . V_32 ;
F_86 ( V_137 -> V_130 ) ;
}
}
}
} else {
if ( V_202 & ( 1 << ( V_51 - 16 ) ) ) {
if ( V_201 -> V_211 [ V_51 ] . V_212 &&
V_201 -> V_211 [ V_51 ] . V_32 &&
! V_201 -> V_211 [ V_51 ] . V_157 ) {
V_137 = V_201 -> V_211 [ V_51 ] . V_32 ;
F_86 ( V_137 -> V_130 ) ;
}
}
}
}
#else
if ( ( V_199 & V_213 ) && V_2 -> V_214 ) {
if ( V_2 -> V_214 -> V_130 )
F_86 ( V_2 -> V_214 -> V_130 ) ;
}
if ( ( V_199 & V_215 ) && V_2 -> V_216 ) {
if ( V_2 -> V_144 . V_130 )
F_86 ( V_2 -> V_144 . V_130 ) ;
}
#endif
if ( ( V_199 & V_217 ) && V_2 -> V_218 ) {
unsigned char V_219 ;
F_57 ( & V_2 -> V_114 ) ;
while ( ( F_3 ( V_2 , V_220 ) & V_221 ) == 0 ) {
V_219 = F_3 ( V_2 , V_222 ) ;
if ( ( V_2 -> V_223 & V_224 ) == 0 )
continue;
F_87 ( V_2 -> V_225 , & V_219 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_220 ) & V_226 ) == 0 ) {
if ( ( V_2 -> V_223 & V_227 ) == 0 )
break;
if ( F_88 ( V_2 -> V_228 , & V_219 , 1 ) != 1 ) {
V_2 -> V_223 &= ~ V_227 ;
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
break;
}
F_5 ( V_2 , V_230 , V_219 ) ;
}
F_58 ( & V_2 -> V_114 ) ;
}
F_5 ( V_2 , V_204 , V_205 | V_206 ) ;
return V_231 ;
}
static void F_89 ( struct V_134 * V_135 )
{
F_17 ( V_135 -> V_32 ) ;
}
static int F_90 ( struct V_129 * V_130 , int V_167 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_136 * V_137 ;
struct V_134 * V_135 = V_130 -> V_135 ;
V_137 = F_20 ( sizeof( * V_137 ) , V_68 ) ;
if ( V_137 == NULL )
return - V_67 ;
if ( F_91 ( V_232 , F_92 ( V_2 -> V_64 ) ,
V_233 , & V_137 -> V_138 ) < 0 ) {
F_17 ( V_137 ) ;
return - V_67 ;
}
V_135 -> V_234 = V_235 ;
V_135 -> V_32 = V_137 ;
V_135 -> V_236 = F_89 ;
V_137 -> V_130 = V_130 ;
#ifdef F_49
F_67 ( & V_2 -> V_171 ) ;
V_137 -> V_146 = NULL ;
V_137 -> V_167 = V_167 ;
F_93 ( V_135 , 0 ,
V_237 ,
& V_238 ) ;
F_68 ( & V_2 -> V_171 ) ;
#else
V_2 -> V_214 = V_137 ;
#endif
if ( V_2 -> V_239 )
V_130 -> V_135 -> V_234 . V_240 |= V_241 ;
V_2 -> V_11 ( V_2 , 1 ) ;
return 0 ;
}
static int F_94 ( struct V_129 * V_130 )
{
F_33 ( L_14 ) ;
return F_90 ( V_130 , V_174 ) ;
}
static int F_95 ( struct V_129 * V_130 )
{
F_33 ( L_15 ) ;
return F_90 ( V_130 , V_177 ) ;
}
static int F_96 ( struct V_129 * V_130 )
{
F_33 ( L_16 ) ;
return F_90 ( V_130 , V_179 ) ;
}
static int F_97 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
F_33 ( L_17 ) ;
F_67 ( & V_2 -> V_171 ) ;
F_98 ( V_2 ) ;
F_68 ( & V_2 -> V_171 ) ;
return F_90 ( V_130 , V_181 ) ;
}
static int F_99 ( struct V_129 * V_130 )
{
int V_56 ;
struct V_1 * V_2 = F_45 ( V_130 ) ;
F_33 ( L_18 ) ;
V_56 = F_100 ( V_130 ) ;
F_67 ( & V_2 -> V_171 ) ;
F_101 ( V_2 ) ;
F_68 ( & V_2 -> V_171 ) ;
return V_56 ;
}
static int F_102 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
if ( F_91 ( V_232 , F_92 ( V_2 -> V_64 ) ,
V_233 , & V_2 -> V_144 . V_138 ) < 0 )
return - V_67 ;
V_2 -> V_144 . V_130 = V_130 ;
V_130 -> V_135 -> V_234 = V_242 ;
if ( V_2 -> V_239 )
V_130 -> V_135 -> V_234 . V_240 |= V_241 ;
V_2 -> V_11 ( V_2 , 1 ) ;
#ifdef F_49
F_93 ( V_130 -> V_135 , 0 ,
V_237 ,
& V_238 ) ;
#endif
return 0 ;
}
static int F_100 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
struct V_134 * V_135 = V_130 -> V_135 ;
struct V_136 * V_137 ;
V_137 = V_135 -> V_32 ;
if ( ! V_137 ) return - V_147 ;
#ifdef F_49
F_67 ( & V_2 -> V_171 ) ;
if ( V_137 -> V_146 ) {
F_63 ( V_2 , V_137 -> V_146 ) ;
V_137 -> V_146 = NULL ;
}
F_68 ( & V_2 -> V_171 ) ;
#else
V_2 -> V_214 = NULL ;
#endif
V_137 -> V_130 = NULL ;
F_103 ( & V_137 -> V_138 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_104 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_45 ( V_130 ) ;
V_2 -> V_144 . V_130 = NULL ;
F_103 ( & V_2 -> V_144 . V_138 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
int V_136 ( struct V_1 * V_2 , int V_243 , struct V_244 * * V_245 )
{
struct V_244 * V_216 ;
int V_56 ;
if ( V_245 )
* V_245 = NULL ;
if ( ( V_56 = F_105 ( V_2 -> V_246 , L_19 , V_243 , V_247 , 1 , & V_216 ) ) < 0 )
return V_56 ;
V_216 -> V_32 = V_2 ;
F_106 ( V_216 , V_248 , & V_176 ) ;
F_106 ( V_216 , V_249 , & V_195 ) ;
V_216 -> V_250 = 0 ;
strcpy ( V_216 -> V_251 , L_19 ) ;
V_2 -> V_216 = V_216 ;
F_107 ( V_216 , V_232 ,
F_92 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_245 )
* V_245 = V_216 ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , int V_243 ,
struct V_244 * * V_245 )
{
struct V_244 * V_216 ;
int V_56 ;
if ( V_245 )
* V_245 = NULL ;
if ( ( V_56 = F_105 ( V_2 -> V_246 , L_20 , V_243 , V_247 , 0 , & V_216 ) ) < 0 )
return V_56 ;
V_216 -> V_32 = V_2 ;
F_106 ( V_216 , V_248 , & V_178 ) ;
V_216 -> V_250 = 0 ;
strcpy ( V_216 -> V_251 , L_20 ) ;
V_2 -> V_252 = V_216 ;
F_107 ( V_216 , V_232 ,
F_92 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_245 )
* V_245 = V_216 ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 , int V_243 ,
struct V_244 * * V_245 )
{
struct V_244 * V_216 ;
int V_56 ;
if ( V_245 )
* V_245 = NULL ;
if ( ( V_56 = F_105 ( V_2 -> V_246 , L_21 , V_243 , V_247 , 0 , & V_216 ) ) < 0 )
return V_56 ;
V_216 -> V_32 = V_2 ;
F_106 ( V_216 , V_248 , & V_180 ) ;
V_216 -> V_250 = 0 ;
strcpy ( V_216 -> V_251 , L_21 ) ;
V_2 -> V_253 = V_216 ;
F_107 ( V_216 , V_232 ,
F_92 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_245 )
* V_245 = V_216 ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , int V_243 ,
struct V_244 * * V_245 )
{
struct V_244 * V_216 ;
int V_56 ;
if ( V_245 )
* V_245 = NULL ;
if ( ( V_56 = F_105 ( V_2 -> V_246 , L_22 , V_243 , 1 , 0 , & V_216 ) ) < 0 )
return V_56 ;
V_216 -> V_32 = V_2 ;
F_106 ( V_216 , V_248 , & V_182 ) ;
V_216 -> V_250 = 0 ;
strcpy ( V_216 -> V_251 , L_22 ) ;
V_2 -> V_252 = V_216 ;
F_107 ( V_216 , V_232 ,
F_92 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_245 )
* V_245 = V_216 ;
return 0 ;
}
static void F_111 ( struct V_254 * V_255 )
{
struct V_1 * V_2 = V_255 -> V_32 ;
V_2 -> V_256 = NULL ;
}
static void F_112 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( F_2 ( V_31 != V_2 -> V_31 [ V_9 ] &&
V_31 != V_2 -> V_31 [ V_10 ] ) )
return;
if ( V_31 == V_2 -> V_31 [ V_9 ] ) {
V_2 -> V_31 [ V_9 ] = NULL ;
V_2 -> V_257 = NULL ;
}
else
V_2 -> V_31 [ V_10 ] = NULL ;
}
static int F_113 ( struct V_258 * V_259 ,
struct V_260 * V_261 )
{
V_261 -> type = V_262 ;
V_261 -> V_5 = 2 ;
V_261 -> V_263 . integer . V_264 = 0 ;
V_261 -> V_263 . integer . V_265 = 0x7fff ;
return 0 ;
}
static int F_114 ( struct V_258 * V_259 , struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_3 = V_259 -> V_268 ;
unsigned int V_33 = F_35 ( V_2 , V_3 ) ;
V_267 -> V_263 . integer . V_263 [ 0 ] = 0xffff - ( V_33 >> 16 ) ;
V_267 -> V_263 . integer . V_263 [ 1 ] = 0xffff - ( V_33 & 0xffff ) ;
return 0 ;
}
static int F_116 ( struct V_258 * V_259 , struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_3 = V_259 -> V_268 ;
unsigned int V_33 = ( ( 0xffff - V_267 -> V_263 . integer . V_263 [ 0 ] ) << 16 |
( 0xffff - V_267 -> V_263 . integer . V_263 [ 1 ] ) ) ;
unsigned int V_269 = F_35 ( V_2 , V_3 ) ;
int V_270 = ( V_269 != V_33 ) ;
if ( V_270 ) {
F_29 ( V_2 , V_3 , V_33 ) ;
}
return V_270 ;
}
static int F_117 ( struct V_258 * V_259 , struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
V_267 -> V_263 . integer . V_263 [ 0 ] = V_2 -> V_200 -> V_271 ;
V_267 -> V_263 . integer . V_263 [ 1 ] = V_2 -> V_200 -> V_272 ;
return 0 ;
}
static int F_118 ( struct V_258 * V_259 , struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_270 = 0 ;
if ( V_2 -> V_200 -> V_272 != V_267 -> V_263 . integer . V_263 [ 0 ] ||
V_2 -> V_200 -> V_271 != V_267 -> V_263 . integer . V_263 [ 1 ] ) {
F_119 ( V_2 ,
V_267 -> V_263 . integer . V_263 [ 0 ] ,
V_267 -> V_263 . integer . V_263 [ 1 ] ) ;
V_270 = 1 ;
}
return V_270 ;
}
static int F_120 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_3 = V_259 -> V_268 ;
if ( V_3 == V_273 )
V_267 -> V_263 . integer . V_263 [ 0 ] = ( V_2 -> V_200 -> V_274 & V_275 ) ;
else
V_267 -> V_263 . integer . V_263 [ 0 ] = V_2 -> V_200 -> V_276 ;
return 0 ;
}
static int F_121 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_270 , V_277 ;
switch ( V_259 -> V_268 ) {
case V_273 :
F_67 ( & V_2 -> V_171 ) ;
V_270 = ( V_2 -> V_200 -> V_274 & V_275 ) ;
if ( V_267 -> V_263 . integer . V_263 [ 0 ] && ! V_270 )
F_122 ( V_2 ) ;
else if ( V_270 && ! V_267 -> V_263 . integer . V_263 [ 0 ] )
F_123 ( V_2 ) ;
V_277 = ( V_270 != ( V_2 -> V_200 -> V_274 & V_275 ) ) ;
F_68 ( & V_2 -> V_171 ) ;
break;
case V_278 :
V_270 = V_2 -> V_200 -> V_276 ;
if ( V_267 -> V_263 . integer . V_263 [ 0 ] && ! V_270 ) {
F_124 ( V_2 ) ;
}
else if ( V_270 && ! V_267 -> V_263 . integer . V_263 [ 0 ] )
F_125 ( V_2 ) ;
V_277 = ( V_270 != V_2 -> V_200 -> V_276 ) ;
break;
default:
V_277 = - V_39 ;
F_73 () ;
}
return V_277 ;
}
static int F_126 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
if ( V_201 -> V_279 != NULL )
V_267 -> V_263 . integer . V_263 [ 0 ] = 1 ;
else
V_267 -> V_263 . integer . V_263 [ 0 ] = 0 ;
return 0 ;
}
static int F_127 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
int V_270 = 0 ;
if ( V_267 -> V_263 . integer . V_263 [ 0 ] && ! V_201 -> V_279 ) {
F_128 ( V_2 ) ;
V_270 = 1 ;
} else if ( ! V_267 -> V_263 . integer . V_263 [ 0 ] && V_201 -> V_279 ) {
F_129 ( V_2 ) ;
V_270 = 1 ;
}
return V_270 ;
}
static int F_130 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
if ( V_201 -> V_280 != NULL )
V_267 -> V_263 . integer . V_263 [ 0 ] = 1 ;
else
V_267 -> V_263 . integer . V_263 [ 0 ] = 0 ;
return 0 ;
}
static int F_131 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
int V_270 = 0 ;
if ( V_267 -> V_263 . integer . V_263 [ 0 ] && ! V_201 -> V_280 ) {
F_132 ( V_2 ) ;
V_270 = 1 ;
} else if ( ! V_267 -> V_263 . integer . V_263 [ 0 ] && V_201 -> V_280 ) {
F_133 ( V_2 ) ;
V_270 = 1 ;
}
return V_270 ;
}
static int F_134 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_281 = F_3 ( V_2 , V_282 ) ;
if ( V_281 & V_283 )
V_267 -> V_263 . integer . V_263 [ 0 ] = 1 ;
else
V_267 -> V_263 . integer . V_263 [ 0 ] = 0 ;
return 0 ;
}
static int F_135 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
int V_281 = F_3 ( V_2 , V_282 ) ;
int V_284 = F_3 ( V_2 , V_285 ) ;
if ( V_267 -> V_263 . integer . V_263 [ 0 ] ) {
F_5 ( V_2 , V_282 ,
V_283 | V_281 ) ;
F_5 ( V_2 , V_285 ,
V_286 | V_284 ) ;
} else {
F_5 ( V_2 , V_282 , V_281 & ~ V_283 ) ;
F_5 ( V_2 , V_285 , V_284 & ~ V_286 ) ;
}
return ( V_281 != ( int ) F_3 ( V_2 , V_282 ) ) ;
}
static int F_136 ( struct V_258 * V_259 , struct V_260 * V_261 )
{
V_261 -> type = V_287 ;
V_261 -> V_5 = 1 ;
return 0 ;
}
static int F_137 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
F_67 ( & V_2 -> V_171 ) ;
V_267 -> V_263 . V_288 . V_93 [ 0 ] = F_138 ( ( V_201 -> V_289 >> 24 ) & 0xff ) ;
V_267 -> V_263 . V_288 . V_93 [ 1 ] = F_138 ( ( V_201 -> V_289 >> 16 ) & 0xff ) ;
V_267 -> V_263 . V_288 . V_93 [ 2 ] = 0 ;
V_267 -> V_263 . V_288 . V_93 [ 3 ] = F_138 ( ( V_201 -> V_289 ) & 0xff ) ;
F_68 ( & V_2 -> V_171 ) ;
return 0 ;
}
static int F_139 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
unsigned int V_33 ;
int V_270 ;
F_67 ( & V_2 -> V_171 ) ;
V_33 = ( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 2 ] ) << 16 ) |
( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_270 = ( unsigned int ) V_201 -> V_289 != V_33 ;
V_201 -> V_289 = V_33 ;
if ( ! ( V_201 -> V_274 & V_290 ) )
F_140 ( V_2 , V_291 , V_33 ) ;
F_68 ( & V_2 -> V_171 ) ;
return V_270 ;
}
static int F_141 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
V_267 -> V_263 . V_288 . V_93 [ 0 ] = 0xff ;
V_267 -> V_263 . V_288 . V_93 [ 1 ] = 0xff ;
V_267 -> V_263 . V_288 . V_93 [ 2 ] = 0x00 ;
V_267 -> V_263 . V_288 . V_93 [ 3 ] = 0xff ;
return 0 ;
}
static int F_142 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
F_67 ( & V_2 -> V_171 ) ;
V_267 -> V_263 . V_288 . V_93 [ 0 ] = F_138 ( ( V_201 -> V_292 >> 24 ) & 0xff ) ;
V_267 -> V_263 . V_288 . V_93 [ 1 ] = F_138 ( ( V_201 -> V_292 >> 16 ) & 0xff ) ;
V_267 -> V_263 . V_288 . V_93 [ 2 ] = 0 ;
V_267 -> V_263 . V_288 . V_93 [ 3 ] = F_138 ( ( V_201 -> V_292 ) & 0xff ) ;
F_68 ( & V_2 -> V_171 ) ;
return 0 ;
}
static int F_143 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
struct V_200 * V_201 = V_2 -> V_200 ;
unsigned int V_33 ;
int V_270 ;
F_67 ( & V_2 -> V_171 ) ;
V_33 = ( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 1 ] ) << 16 ) |
( ( unsigned int ) F_138 ( V_267 -> V_263 . V_288 . V_93 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_270 = V_201 -> V_292 != V_33 ;
V_201 -> V_292 = V_33 ;
if ( V_201 -> V_274 & V_290 )
F_140 ( V_2 , V_291 , V_33 ) ;
F_68 ( & V_2 -> V_171 ) ;
return V_270 ;
}
static int F_144 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
unsigned short V_33 ;
V_33 = F_145 ( V_2 -> V_31 [ V_9 ] , V_293 ) ;
V_267 -> V_263 . integer . V_263 [ 0 ] = ( V_33 & 0x200 ) ? 0 : 1 ;
return 0 ;
}
static int F_146 ( struct V_258 * V_259 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_115 ( V_259 ) ;
return F_147 ( V_2 -> V_31 [ V_9 ] ,
V_293 , 0x200 ,
V_267 -> V_263 . integer . V_263 [ 0 ] ? 0 : 0x200 ) ;
}
static void F_148 ( struct V_30 * V_31 )
{
unsigned long V_294 ;
int V_56 ;
F_149 ( V_31 , V_295 , 0 ) ;
if ( V_31 -> V_34 == V_9 ) {
F_33 ( L_23 , 0x0 ) ;
F_10 ( V_31 , V_293 , 0x0 ) ;
} else if ( V_31 -> V_34 == V_10 ) {
F_33 ( L_24 , 0x3 ) ;
F_10 ( V_31 , V_293 , 0x3 ) ;
} else {
F_73 () ;
}
F_7 ( 50 ) ;
V_294 = V_296 + V_297 ;
do {
unsigned short V_298 ;
F_145 ( V_31 , V_295 ) ;
F_145 ( V_31 , V_299 ) ;
F_145 ( V_31 , V_300 ) ;
V_298 = F_145 ( V_31 , V_301 ) ;
if ( V_298 != 0xffff && ( V_298 & 1 ) != 0 )
return;
F_149 ( V_31 , V_302 , 0x8a05 ) ;
if ( ( V_56 = F_145 ( V_31 , V_302 ) ) == 0x8a05 )
return;
F_6 ( 10 ) ;
} while ( F_150 ( V_294 , V_296 ) );
F_4 ( V_25 L_25 ) ;
}
static int F_151 ( struct V_1 * V_2 , int V_303 )
{
int V_41 , V_56 ;
struct V_304 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = V_2 ;
V_31 . V_236 = F_112 ;
V_31 . V_34 = V_303 ;
if ( V_2 -> V_305 == V_306 )
V_31 . V_307 = V_308 ;
if ( V_303 == V_10 ) {
F_9 ( V_2 , V_295 , 0 , V_303 ) ;
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_295 , V_303 ) & 0x8000 ) {
F_33 ( L_26 ) ;
return - V_147 ;
}
}
F_9 ( V_2 , V_309 , 0x8000 , V_303 ) ;
for ( V_41 = 0 ; V_41 < 100 ; ++ V_41 ) {
if ( F_1 ( V_2 , V_309 , V_303 ) == 0x8000 ) {
V_56 = F_152 ( V_2 -> V_256 , & V_31 , & V_2 -> V_31 [ V_303 ] ) ;
return V_56 ;
}
F_6 ( 10 ) ;
}
F_33 ( L_27 , V_303 ) ;
return - V_147 ;
}
int F_153 ( struct V_1 * V_2 , int V_310 )
{
struct V_311 * V_246 = V_2 -> V_246 ;
struct V_312 V_313 ;
int V_56 ;
unsigned int V_41 ;
static struct V_314 V_175 = {
#ifdef F_49
. V_315 = F_148 ,
#endif
. V_316 = F_10 ,
. V_317 = F_8 ,
} ;
V_2 -> V_318 = 0 ;
F_33 ( L_28 ) ;
if ( ( V_56 = V_254 ( V_246 , 0 , & V_175 , V_2 , & V_2 -> V_256 ) ) < 0 )
return V_56 ;
V_2 -> V_256 -> V_236 = F_111 ;
if ( F_151 ( V_2 , V_9 ) < 0 )
return - V_147 ;
V_2 -> V_318 = 1 ;
#ifdef F_49
F_33 ( L_29 ) ;
if ( ! F_151 ( V_2 , V_10 ) )
V_2 -> V_318 = 2 ;
#endif
for ( V_41 = 0 ; V_41 < F_154 ( V_319 ) ; V_41 ++ ) {
struct V_258 * V_320 ;
V_320 = F_155 ( & V_319 [ V_41 ] , V_2 ) ;
if ( V_320 && V_320 -> V_313 . V_321 == V_322 )
V_320 -> V_313 . V_243 = V_310 ;
if ( ( V_56 = F_156 ( V_246 , V_320 ) ) < 0 )
return V_56 ;
}
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_321 = V_323 ;
strcpy ( V_313 . V_251 , L_30 ) ;
V_2 -> V_257 = F_157 ( V_2 -> V_246 , & V_313 ) ;
#ifdef F_49
if ( V_2 -> V_318 == 1 ) {
unsigned int V_324 = V_2 -> V_31 [ V_9 ] -> V_313 & 0xffff ;
if ( V_324 == 0x592b || V_324 == 0x592d ) {
V_56 = F_156 ( V_246 , F_155 ( & V_325 , V_2 ) ) ;
if ( V_56 < 0 )
return V_56 ;
F_158 ( V_2 -> V_31 [ V_9 ] ,
V_293 , 0x200 ) ;
}
}
if ( V_2 -> V_326 ) {
F_33 ( L_31 ) ;
V_2 -> V_326 ( V_2 ) ;
}
#endif
V_2 -> V_305 ( V_2 , 1 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_229 , V_327 ) ;
F_7 ( 100 ) ;
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
static int F_160 ( struct V_328 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_161 ( & V_2 -> V_114 ) ;
V_2 -> V_329 |= V_330 ;
V_2 -> V_223 |= V_331 ;
V_2 -> V_225 = V_130 ;
if ( ! ( V_2 -> V_329 & V_332 ) ) {
F_159 ( V_2 ) ;
} else {
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
F_162 ( & V_2 -> V_114 ) ;
return 0 ;
}
static int F_163 ( struct V_328 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
F_161 ( & V_2 -> V_114 ) ;
V_2 -> V_223 &= ~ ( V_331 | V_224 ) ;
V_2 -> V_225 = NULL ;
if ( ! ( V_2 -> V_329 & V_332 ) ) {
F_159 ( V_2 ) ;
} else {
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
V_2 -> V_329 &= ~ V_330 ;
F_162 ( & V_2 -> V_114 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_164 ( struct V_328 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_161 ( & V_2 -> V_114 ) ;
V_2 -> V_329 |= V_332 ;
V_2 -> V_223 |= V_333 ;
V_2 -> V_228 = V_130 ;
if ( ! ( V_2 -> V_329 & V_330 ) ) {
F_159 ( V_2 ) ;
} else {
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
F_162 ( & V_2 -> V_114 ) ;
return 0 ;
}
static int F_165 ( struct V_328 * V_130 )
{
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
F_161 ( & V_2 -> V_114 ) ;
V_2 -> V_223 &= ~ ( V_333 | V_227 ) ;
V_2 -> V_228 = NULL ;
if ( ! ( V_2 -> V_329 & V_330 ) ) {
F_159 ( V_2 ) ;
} else {
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
V_2 -> V_329 &= ~ V_332 ;
F_162 ( & V_2 -> V_114 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static void F_166 ( struct V_328 * V_130 , int V_334 )
{
unsigned long V_107 ;
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
F_38 ( & V_2 -> V_114 , V_107 ) ;
if ( V_334 ) {
if ( ( V_2 -> V_223 & V_224 ) == 0 ) {
V_2 -> V_223 |= V_224 ;
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
} else {
if ( V_2 -> V_223 & V_224 ) {
V_2 -> V_223 &= ~ V_224 ;
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
}
F_39 ( & V_2 -> V_114 , V_107 ) ;
}
static void F_167 ( struct V_328 * V_130 , int V_334 )
{
unsigned long V_107 ;
struct V_1 * V_2 = V_130 -> V_218 -> V_32 ;
unsigned char V_335 ;
F_38 ( & V_2 -> V_114 , V_107 ) ;
if ( V_334 ) {
if ( ( V_2 -> V_223 & V_227 ) == 0 ) {
V_2 -> V_223 |= V_227 ;
while ( ( V_2 -> V_223 & V_227 ) &&
( F_3 ( V_2 , V_220 ) & V_226 ) == 0 ) {
if ( F_88 ( V_130 , & V_335 , 1 ) != 1 ) {
V_2 -> V_223 &= ~ V_227 ;
} else {
F_5 ( V_2 , V_230 , V_335 ) ;
}
}
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
} else {
if ( V_2 -> V_223 & V_227 ) {
V_2 -> V_223 &= ~ V_227 ;
F_5 ( V_2 , V_229 , V_2 -> V_223 ) ;
}
}
F_39 ( & V_2 -> V_114 , V_107 ) ;
}
int F_168 ( struct V_1 * V_2 , int V_243 , struct V_336 * * V_337 )
{
struct V_336 * V_218 ;
int V_56 ;
if ( V_337 )
* V_337 = NULL ;
if ( ( V_56 = F_169 ( V_2 -> V_246 , L_32 , V_243 , 1 , 1 , & V_218 ) ) < 0 )
return V_56 ;
strcpy ( V_218 -> V_251 , L_32 ) ;
F_170 ( V_218 , V_338 , & V_339 ) ;
F_170 ( V_218 , V_340 , & V_341 ) ;
V_218 -> V_250 |= V_342 | V_343 | V_344 ;
V_218 -> V_32 = V_2 ;
V_2 -> V_218 = V_218 ;
if ( V_337 )
* V_337 = NULL ;
return 0 ;
}
static void F_171 ( struct V_345 * V_345 )
{
struct V_1 * V_2 = F_172 ( V_345 ) ;
if ( F_2 ( ! V_2 ) )
return;
F_5 ( V_2 , V_346 , 0xFF ) ;
}
static unsigned char F_173 ( struct V_345 * V_345 )
{
struct V_1 * V_2 = F_172 ( V_345 ) ;
if ( F_2 ( ! V_2 ) )
return 0 ;
return F_3 ( V_2 , V_346 ) ;
}
static int F_174 ( struct V_345 * V_345 , int * V_347 , int * V_348 )
{
struct V_1 * V_2 = F_172 ( V_345 ) ;
unsigned V_349 , V_350 , V_351 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_349 = F_3 ( V_2 , V_352 ) ;
V_350 = F_3 ( V_2 , V_353 ) ;
V_351 = F_3 ( V_2 , V_346 ) ;
* V_348 = ( ~ V_351 >> 4 ) & 0x0F ;
V_347 [ 0 ] = ( ( V_349 & V_354 ) >> V_355 ) & 0xFFFF ;
V_347 [ 1 ] = ( ( V_349 & V_356 ) >> V_357 ) & 0xFFFF ;
V_347 [ 2 ] = ( ( V_350 & V_358 ) >> V_359 ) & 0xFFFF ;
V_347 [ 3 ] = ( ( V_350 & V_360 ) >> V_361 ) & 0xFFFF ;
for( V_351 = 0 ; V_351 < 4 ; ++ V_351 )
if( V_347 [ V_351 ] == 0xFFFF ) V_347 [ V_351 ] = - 1 ;
return 0 ;
}
static int F_175 ( struct V_345 * V_345 , int V_362 )
{
switch ( V_362 ) {
case V_363 :
return 0 ;
case V_364 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
int F_176 ( struct V_1 * V_2 )
{
struct V_345 * V_365 ;
V_2 -> V_345 = V_365 = F_177 () ;
if ( ! V_365 ) {
F_178 ( V_25 L_33 ) ;
return - V_67 ;
}
F_179 ( V_365 , L_34 ) ;
F_180 ( V_365 , L_35 , F_181 ( V_2 -> V_64 ) ) ;
F_182 ( V_365 , & V_2 -> V_64 -> V_65 ) ;
F_183 ( V_365 , V_2 ) ;
V_365 -> V_366 = F_175 ;
V_365 -> V_317 = F_173 ;
V_365 -> V_367 = F_171 ;
V_365 -> V_368 = F_174 ;
F_5 ( V_2 , V_369 , 0xFF ) ;
F_5 ( V_2 , V_370 , V_371 ) ;
F_184 ( V_365 ) ;
return 0 ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
if ( V_2 -> V_345 ) {
F_186 ( V_2 -> V_345 ) ;
V_2 -> V_345 = NULL ;
}
}
int F_176 ( struct V_1 * V_2 ) { return - V_372 ; }
static inline void F_185 ( struct V_1 * V_2 ) { }
static T_7 F_187 ( struct V_373 * V_72 ,
void * V_374 ,
struct V_375 * V_375 , char T_8 * V_376 ,
T_4 V_5 , T_9 V_377 )
{
struct V_378 * V_40 = V_72 -> V_32 ;
if ( F_188 ( V_376 , V_40 -> V_42 + V_377 , V_5 ) )
return - V_379 ;
return V_5 ;
}
static int F_189 ( struct V_311 * V_246 , struct V_1 * V_2 )
{
struct V_373 * V_72 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_378 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ! F_190 ( V_246 , V_40 -> V_251 , & V_72 ) ) {
V_72 -> V_380 = V_381 ;
V_72 -> V_32 = V_2 ;
V_72 -> V_219 . V_175 = & V_382 ;
V_72 -> V_66 = V_40 -> V_66 ;
V_72 -> V_362 = V_383 | V_384 ;
}
}
#ifdef F_49
F_191 ( V_246 , V_2 ) ;
#endif
return 0 ;
}
static int F_192 ( struct V_1 * V_2 )
{
#ifdef F_49
F_193 ( V_2 ) ;
#endif
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
V_7 = F_35 ( V_2 , V_188 ) ;
V_7 &= ~ 0x0000f03f ;
V_7 |= 0x00000010 ;
F_29 ( V_2 , V_188 , V_7 ) ;
V_7 = F_35 ( V_2 , V_385 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000011 ;
F_29 ( V_2 , V_385 , V_7 ) ;
V_7 = F_35 ( V_2 , V_160 ) ;
F_29 ( V_2 , V_160 , V_7 & 0x0000ffff ) ;
V_7 = F_35 ( V_2 , V_164 ) ;
F_29 ( V_2 , V_164 , V_7 & 0xffff0000 ) ;
F_28 ( V_2 ) ;
F_36 ( V_2 ) ;
F_5 ( V_2 , V_97 , 0 ) ;
V_7 = F_3 ( V_2 , V_97 ) & ~ V_98 ;
F_5 ( V_2 , V_97 , V_7 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_41 ;
if ( F_2 ( ! V_2 ) )
return - V_39 ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , 1 ) ;
F_185 ( V_2 ) ;
if ( V_2 -> V_305 )
V_2 -> V_305 ( V_2 , - V_2 -> V_386 ) ;
F_192 ( V_2 ) ;
if ( V_2 -> V_40 . V_41 [ 0 ] . V_387 )
F_194 ( V_2 ) ;
if ( V_2 -> V_197 >= 0 )
F_196 ( V_2 -> V_197 , V_2 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , - V_2 -> V_386 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_378 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( V_40 -> V_42 )
F_197 ( V_40 -> V_42 ) ;
F_198 ( V_40 -> V_387 ) ;
}
#ifdef F_49
if ( V_2 -> V_200 ) {
F_199 ( V_2 ) ;
V_2 -> V_200 = NULL ;
}
for ( V_41 = 0 ; V_41 < V_388 ; V_41 ++ )
F_16 ( V_2 -> V_389 [ V_41 ] ) ;
#else
F_200 ( V_2 -> V_79 ) ;
#endif
#ifdef F_201
F_17 ( V_2 -> V_390 ) ;
#endif
F_202 ( V_2 -> V_64 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_203 ( struct V_391 * V_243 )
{
struct V_1 * V_2 = V_243 -> V_392 ;
return F_195 ( V_2 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
int V_393 ;
F_5 ( V_2 , V_97 , 0 ) ;
F_5 ( V_2 , V_394 , 0 ) ;
#ifdef F_49
F_5 ( V_2 , V_395 , V_396 | V_397 |
V_398 ) ;
#else
F_5 ( V_2 , V_395 , V_396 | V_399 ) ;
#endif
F_5 ( V_2 , V_14 , 0 ) ;
#ifdef F_49
F_5 ( V_2 , V_400 , 0 ) ;
#endif
F_7 ( 50 ) ;
F_5 ( V_2 , V_14 , V_21 ) ;
#ifdef F_49
F_5 ( V_2 , V_400 , V_21 ) ;
#endif
F_5 ( V_2 , V_14 , V_17 | V_21 ) ;
#ifdef F_49
F_5 ( V_2 , V_400 , V_17 | V_21 ) ;
#endif
F_31 ( 10 ) ;
F_5 ( V_2 , V_394 , V_401 ) ;
F_5 ( V_2 , V_402 , V_403 | V_404 ) ;
F_5 ( V_2 , V_405 , 0x3a ) ;
F_5 ( V_2 , V_406 , V_407 ) ;
F_5 ( V_2 , V_97 , V_408 ) ;
F_6 ( 100 ) ;
F_5 ( V_2 , V_97 , V_408 | V_98 ) ;
F_5 ( V_2 , V_409 , V_410 ) ;
F_32 ( V_2 ) ;
F_5 ( V_2 , V_411 , V_412 | V_413 ) ;
F_5 ( V_2 , V_414 , V_415 | V_413 ) ;
F_5 ( V_2 , V_394 , V_401 | V_416 ) ;
#ifdef F_49
F_5 ( V_2 , V_417 , V_418 ) ;
F_5 ( V_2 , V_419 , 0 ) ;
F_5 ( V_2 , V_420 , 0 ) ;
F_5 ( V_2 , V_421 , 0 ) ;
F_5 ( V_2 , V_422 , 1 ) ;
#endif
F_31 ( 5 ) ;
V_393 = 150 ;
while ( V_393 -- > 0 ) {
if ( F_3 ( V_2 , V_27 ) & V_423 )
goto V_24;
F_6 ( 10 ) ;
}
F_4 ( V_25 L_36 ) ;
F_4 ( V_25 L_37 ) ;
return - V_424 ;
V_24:
#ifdef F_49
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 150 ; V_5 ++ ) {
F_7 ( 25 ) ;
if ( F_3 ( V_2 , V_425 ) & V_423 )
break;
}
if ( ! ( F_3 ( V_2 , V_425 ) & V_423 ) )
F_33 ( L_38 ) ;
}
#endif
F_5 ( V_2 , V_14 , V_15 | V_17 | V_21 ) ;
#ifdef F_49
F_5 ( V_2 , V_400 , V_15 | V_17 | V_21 ) ;
#endif
V_393 = 150 ;
while ( V_393 -- > 0 ) {
if ( ( F_3 ( V_2 , V_426 ) & ( V_427 | V_428 ) ) == ( V_427 | V_428 ) )
goto V_29;
F_6 ( 10 ) ;
}
#ifndef F_49
F_4 ( V_25 L_39 ) ;
return - V_424 ;
#else
F_4 ( V_25 L_40 ) ;
F_4 ( V_25 L_41 ) ;
F_4 ( V_25 L_42 ) ;
F_4 ( V_25 L_43 ) ;
return - V_424 ;
#endif
V_29:
F_5 ( V_2 , V_429 , V_430 | V_431 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
F_5 ( V_2 , V_204 , V_206 | V_205 ) ;
V_7 = F_35 ( V_2 , V_188 ) ;
V_7 &= ~ 0x0000f03f ;
F_29 ( V_2 , V_188 , V_7 ) ;
V_7 = F_35 ( V_2 , V_385 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000001 ;
F_29 ( V_2 , V_385 , V_7 ) ;
}
int F_206 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
#ifdef F_49
int V_51 ;
#endif
int V_56 ;
F_28 ( V_2 ) ;
#ifdef F_49
for ( V_51 = 0 ; V_51 < V_388 ; V_51 ++ ) {
V_56 = F_18 ( V_2 , & V_2 -> V_389 [ V_51 ] , V_432 [ V_51 ] ) ;
if ( V_56 < 0 ) {
F_4 ( V_25 L_44 ,
V_432 [ V_51 ] ) ;
return V_56 ;
}
V_56 = F_207 ( V_2 , V_2 -> V_389 [ V_51 ] ) ;
if ( V_56 < 0 ) {
F_4 ( V_25 L_45 ,
V_432 [ V_51 ] ) ;
return V_56 ;
}
}
if ( F_208 ( V_2 ) < 0 )
return - V_424 ;
#else
V_56 = F_18 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_27 ( V_2 ) ;
if ( V_56 < 0 ) {
F_4 ( V_25 L_46 ) ;
return V_56 ;
}
V_7 = F_35 ( V_2 , V_160 ) ;
V_2 -> V_161 = V_7 & 0xffff0000 ;
F_29 ( V_2 , V_160 , V_7 & 0x0000ffff ) ;
#endif
V_7 = F_35 ( V_2 , V_164 ) ;
V_2 -> V_144 . V_165 = V_7 & 0x0000ffff ;
F_29 ( V_2 , V_164 , V_7 & 0xffff0000 ) ;
F_31 ( 5 ) ;
F_37 ( V_2 , 8000 ) ;
F_40 ( V_2 , 8000 ) ;
F_34 ( V_2 ) ;
F_205 ( V_2 ) ;
#ifndef F_49
F_29 ( V_2 , V_433 , 0x80008000 ) ;
F_29 ( V_2 , V_434 , 0x80008000 ) ;
#endif
return 0 ;
}
static void F_209 ( struct V_1 * V_2 , int V_270 )
{
}
static int F_210 ( struct V_1 * V_2 )
{
T_1 V_41 , V_435 , V_7 , V_96 = 0 ;
T_10 V_436 , V_437 , V_438 ;
F_33 ( L_47 ) ;
V_7 = F_3 ( V_2 , V_97 ) ;
if ( ! ( V_7 & V_98 ) ) {
F_5 ( V_2 , V_97 , V_7 | V_98 ) ;
V_96 = 1 ;
}
if( V_2 -> V_318 != 2 ) {
F_4 ( V_25 L_48 ) ;
return - V_39 ;
}
V_436 = F_1 ( V_2 ,
V_439 ,
V_10 ) ;
V_436 &= 0xFEFF ;
F_9 ( V_2 ,
V_439 , V_436 ,
V_10 ) ;
V_437 = F_1 ( V_2 ,
V_440 ,
V_10 ) ;
V_437 &= 0x27F ;
F_9 ( V_2 ,
V_440 , V_437 ,
V_10 ) ;
V_438 = F_1 ( V_2 , V_441 ,
V_10 ) ;
V_438 &= 0x27F ;
F_9 ( V_2 , V_441 , V_438 ,
V_10 ) ;
V_435 = F_3 ( V_2 , V_429 ) ;
V_435 |= 0x200 ;
F_5 ( V_2 , V_429 , V_435 ) ;
if ( F_30 ( V_2 , 1 ) ) {
F_33 ( L_49 ) ;
return - V_39 ;
}
for( V_41 = 0x90 ; V_41 <= 0x9F ; V_41 ++ ) {
F_5 ( V_2 , V_99 , 0x1800 ) ;
if ( F_30 ( V_2 , 200 ) ) {
F_33 ( L_9 , V_41 ) ;
return - V_39 ;
}
F_5 ( V_2 , V_100 , V_41 ) ;
F_5 ( V_2 , V_101 , V_102 ) ;
}
F_30 ( V_2 , 200 ) ;
if ( V_96 )
F_5 ( V_2 , V_97 , V_7 ) ;
return 0 ;
}
static void V_306 ( struct V_1 * V_2 , int V_270 )
{
#ifdef F_49
int V_269 = V_2 -> V_386 ;
#endif
int V_442 , V_33 ;
V_2 -> V_386 += V_270 ;
V_442 = F_1 ( V_2 , V_443 ,
V_9 ) ;
V_33 = V_442 ;
if ( V_2 -> V_386 ) {
V_33 |= 0x8000 ;
} else {
V_33 &= ~ 0x8000 ;
}
if ( V_33 != V_442 ) {
F_9 ( V_2 , V_443 , V_33 ,
V_9 ) ;
if ( V_2 -> V_257 )
F_211 ( V_2 -> V_246 , V_444 ,
& V_2 -> V_257 -> V_313 ) ;
}
#ifdef F_49
if ( V_2 -> V_386 && ! V_269 ) {
F_210 ( V_2 ) ;
}
#endif
}
static void F_212 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_282 , V_283 ) ;
F_5 ( V_2 , V_285 , V_283 ) ;
}
static void F_213 ( struct V_1 * V_2 , int V_270 )
{
int V_269 = V_2 -> V_386 ;
int V_281 = F_3 ( V_2 , V_282 ) ;
int V_284 = F_3 ( V_2 , V_285 ) ;
V_2 -> V_386 += V_270 ;
if ( V_2 -> V_386 && ! V_269 ) {
F_33 ( L_50 ) ;
F_5 ( V_2 , V_282 ,
V_445 | V_281 ) ;
F_5 ( V_2 , V_285 ,
V_446 | V_284 ) ;
} else if ( V_269 && ! V_2 -> V_386 ) {
F_33 ( L_51 ) ;
F_5 ( V_2 , V_282 , V_281 & ~ V_445 ) ;
F_5 ( V_2 , V_285 , V_284 & ~ V_446 ) ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
F_33 ( L_52 ) ;
F_5 ( V_2 , V_282 , V_283 ) ;
F_5 ( V_2 , V_285 , V_283 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
#ifdef F_49
unsigned int V_41 ;
int V_56 ;
struct V_311 * V_246 = V_2 -> V_246 ;
#endif
F_212 ( V_2 ) ;
F_33 ( L_53 ) ;
#ifdef F_49
if ( V_2 -> V_447 )
return;
for ( V_41 = 0 ; V_41 < F_154 ( V_448 ) ; V_41 ++ ) {
struct V_258 * V_320 ;
V_320 = F_155 ( & V_448 [ V_41 ] , V_2 ) ;
if ( ( V_56 = F_156 ( V_246 , V_320 ) ) < 0 ) {
F_178 ( V_25 L_54 , V_56 ) ;
break;
}
}
#endif
}
static void F_216 ( struct V_1 * V_2 , int V_270 )
{
T_10 V_449 , V_450 ;
if ( ! V_2 -> V_451 )
return;
V_2 -> V_386 += V_270 ;
V_450 = V_449 = F_217 ( V_2 -> V_451 + 0x10 ) ;
if ( ! V_2 -> V_386 )
V_450 |= 0x2000 ;
else
V_450 &= ~ 0x2000 ;
if ( V_450 != V_449 )
F_218 ( V_450 , V_2 -> V_451 + 0x10 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_452 * V_453 ;
T_11 V_454 ;
V_2 -> V_451 = 0 ;
V_453 = F_220 ( V_455 ,
V_456 , NULL ) ;
if ( V_453 == NULL )
return;
F_221 ( V_453 , 0x41 , & V_454 ) ;
V_2 -> V_451 = V_454 << 8 ;
F_222 ( V_453 ) ;
}
static int F_223 ( struct V_243 * V_65 )
{
struct V_452 * V_64 = F_224 ( V_65 ) ;
struct V_311 * V_246 = F_225 ( V_65 ) ;
struct V_1 * V_2 = V_246 -> V_32 ;
int V_51 , V_457 ;
F_226 ( V_246 , V_458 ) ;
V_2 -> V_447 = 1 ;
F_227 ( V_2 -> V_216 ) ;
F_228 ( V_2 -> V_31 [ V_9 ] ) ;
F_228 ( V_2 -> V_31 [ V_10 ] ) ;
for ( V_51 = 0 ; V_51 < F_154 ( V_390 ) ; V_51 ++ )
V_2 -> V_390 [ V_51 ] = F_3 ( V_2 , V_390 [ V_51 ] ) ;
V_457 = V_2 -> V_386 ;
V_2 -> V_305 ( V_2 , - V_2 -> V_386 ) ;
F_194 ( V_2 ) ;
V_2 -> V_11 ( V_2 , - V_2 -> V_386 ) ;
V_2 -> V_386 = V_457 ;
F_202 ( V_64 ) ;
F_229 ( V_64 ) ;
F_230 ( V_64 , V_459 ) ;
return 0 ;
}
static int F_231 ( struct V_243 * V_65 )
{
struct V_452 * V_64 = F_224 ( V_65 ) ;
struct V_311 * V_246 = F_225 ( V_65 ) ;
struct V_1 * V_2 = V_246 -> V_32 ;
int V_457 ;
#ifdef F_49
int V_51 ;
#endif
unsigned int V_7 ;
F_230 ( V_64 , V_460 ) ;
F_232 ( V_64 ) ;
if ( F_233 ( V_64 ) < 0 ) {
F_178 ( V_25 L_55
L_56 ) ;
F_234 ( V_246 ) ;
return - V_424 ;
}
F_235 ( V_64 ) ;
V_457 = V_2 -> V_386 ;
V_2 -> V_386 = 0 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_204 ( V_2 ) ;
F_28 ( V_2 ) ;
#ifdef F_49
F_236 ( V_2 ) ;
for ( V_51 = 0 ; V_51 < F_154 ( V_390 ) ; V_51 ++ )
F_5 ( V_2 , V_390 [ V_51 ] , V_2 -> V_390 [ V_51 ] ) ;
#else
F_27 ( V_2 ) ;
#endif
#if 0
snd_cs46xx_codec_write(chip, BA0_AC97_GENERAL_PURPOSE,
chip->ac97_general_purpose);
snd_cs46xx_codec_write(chip, AC97_POWER_CONTROL,
chip->ac97_powerdown);
mdelay(10);
snd_cs46xx_codec_write(chip, BA0_AC97_POWERDOWN,
chip->ac97_powerdown);
mdelay(5);
#endif
F_237 ( V_2 -> V_31 [ V_9 ] ) ;
F_237 ( V_2 -> V_31 [ V_10 ] ) ;
V_7 = F_35 ( V_2 , V_164 ) ;
V_2 -> V_144 . V_165 = V_7 & 0x0000ffff ;
F_29 ( V_2 , V_164 , V_7 & 0xffff0000 ) ;
F_31 ( 5 ) ;
F_37 ( V_2 , 8000 ) ;
F_40 ( V_2 , 8000 ) ;
F_34 ( V_2 ) ;
F_205 ( V_2 ) ;
if ( V_457 )
V_2 -> V_305 ( V_2 , 1 ) ;
else
V_2 -> V_11 ( V_2 , - 1 ) ;
V_2 -> V_386 = V_457 ;
V_2 -> V_447 = 0 ;
F_226 ( V_246 , V_461 ) ;
return 0 ;
}
int F_238 ( struct V_311 * V_246 ,
struct V_452 * V_64 ,
int V_462 , int V_463 ,
struct V_1 * * V_464 )
{
struct V_1 * V_2 ;
int V_56 , V_41 ;
struct V_378 * V_40 ;
struct V_465 * V_466 ;
T_10 V_467 , V_468 ;
static struct V_469 V_175 = {
. V_470 = F_203 ,
} ;
* V_464 = NULL ;
if ( ( V_56 = F_233 ( V_64 ) ) < 0 )
return V_56 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_68 ) ;
if ( V_2 == NULL ) {
F_202 ( V_64 ) ;
return - V_67 ;
}
F_239 ( & V_2 -> V_114 ) ;
#ifdef F_49
F_240 ( & V_2 -> V_171 ) ;
#endif
V_2 -> V_246 = V_246 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_197 = - 1 ;
V_2 -> V_471 = F_241 ( V_64 , 0 ) ;
V_2 -> V_472 = F_241 ( V_64 , 1 ) ;
if ( V_2 -> V_471 == 0 || V_2 -> V_471 == ( unsigned long ) ~ 0 ||
V_2 -> V_472 == 0 || V_2 -> V_472 == ( unsigned long ) ~ 0 ) {
F_4 ( V_25 L_57 ,
V_2 -> V_471 , V_2 -> V_472 ) ;
F_195 ( V_2 ) ;
return - V_67 ;
}
V_40 = & V_2 -> V_40 . V_251 . V_473 ;
strcpy ( V_40 -> V_251 , L_58 ) ;
V_40 -> V_474 = V_2 -> V_471 ;
V_40 -> V_66 = V_475 ;
V_40 = & V_2 -> V_40 . V_251 . V_476 ;
strcpy ( V_40 -> V_251 , L_59 ) ;
V_40 -> V_474 = V_2 -> V_472 + V_477 ;
V_40 -> V_66 = V_478 ;
V_40 = & V_2 -> V_40 . V_251 . V_479 ;
strcpy ( V_40 -> V_251 , L_60 ) ;
V_40 -> V_474 = V_2 -> V_472 + V_480 ;
V_40 -> V_66 = V_481 ;
V_40 = & V_2 -> V_40 . V_251 . V_482 ;
strcpy ( V_40 -> V_251 , L_61 ) ;
V_40 -> V_474 = V_2 -> V_472 + V_483 ;
V_40 -> V_66 = V_484 ;
V_40 = & V_2 -> V_40 . V_251 . V_3 ;
strcpy ( V_40 -> V_251 , L_62 ) ;
V_40 -> V_474 = V_2 -> V_472 + V_485 ;
V_40 -> V_66 = V_486 ;
F_242 ( V_64 , V_487 , & V_468 ) ;
F_242 ( V_64 , V_488 , & V_467 ) ;
for ( V_466 = & V_489 [ 0 ] ; V_466 -> V_251 ; V_466 ++ ) {
if ( V_466 -> V_490 == V_468 && V_466 -> V_313 == V_467 ) {
F_33 ( L_63 , V_466 -> V_251 ) ;
V_2 -> V_305 = V_466 -> V_491 ;
V_2 -> V_11 = V_466 -> V_212 ;
V_2 -> V_326 = V_466 -> V_326 ;
if ( V_466 -> V_492 )
V_466 -> V_492 ( V_2 ) ;
break;
}
}
if ( V_462 ) {
F_4 ( V_493 L_64 ) ;
V_2 -> V_305 = V_306 ;
}
if ( V_463 ) {
F_4 ( V_493 L_65 ) ;
V_2 -> V_11 = F_216 ;
F_219 ( V_2 ) ;
}
if ( V_2 -> V_305 == NULL )
V_2 -> V_305 = F_209 ;
if ( V_2 -> V_11 == NULL )
V_2 -> V_11 = F_209 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_235 ( V_64 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ( V_40 -> V_387 = F_243 ( V_40 -> V_474 , V_40 -> V_66 ,
V_40 -> V_251 ) ) == NULL ) {
F_4 ( V_25 L_66 ,
V_40 -> V_474 , V_40 -> V_474 + V_40 -> V_66 - 1 ) ;
F_195 ( V_2 ) ;
return - V_494 ;
}
V_40 -> V_42 = F_244 ( V_40 -> V_474 , V_40 -> V_66 ) ;
if ( V_40 -> V_42 == NULL ) {
F_4 ( V_25 L_67 , V_40 -> V_251 ) ;
F_195 ( V_2 ) ;
return - V_67 ;
}
}
if ( F_245 ( V_64 -> V_197 , F_85 , V_495 ,
V_496 , V_2 ) ) {
F_4 ( V_25 L_68 , V_64 -> V_197 ) ;
F_195 ( V_2 ) ;
return - V_494 ;
}
V_2 -> V_197 = V_64 -> V_197 ;
#ifdef F_49
V_2 -> V_200 = F_246 ( V_2 ) ;
if ( V_2 -> V_200 == NULL ) {
F_195 ( V_2 ) ;
return - V_67 ;
}
#endif
V_56 = F_204 ( V_2 ) ;
if ( V_56 < 0 ) {
F_195 ( V_2 ) ;
return V_56 ;
}
if ( ( V_56 = F_247 ( V_246 , V_497 , V_2 , & V_175 ) ) < 0 ) {
F_195 ( V_2 ) ;
return V_56 ;
}
F_189 ( V_246 , V_2 ) ;
#ifdef F_201
V_2 -> V_390 = F_23 ( sizeof( * V_2 -> V_390 ) *
F_154 ( V_390 ) , V_68 ) ;
if ( ! V_2 -> V_390 ) {
F_195 ( V_2 ) ;
return - V_67 ;
}
#endif
V_2 -> V_11 ( V_2 , - 1 ) ;
F_248 ( V_246 , & V_64 -> V_65 ) ;
* V_464 = V_2 ;
return 0 ;
}
