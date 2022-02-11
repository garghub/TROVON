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
F_4 ( V_2 -> V_16 -> V_17 , L_1 , V_7 ) ;
F_5 ( V_2 , V_14 , ( V_7 & ( ~ V_18 ) ) | V_15 ) ;
F_6 ( 50 ) ;
V_7 = F_3 ( V_2 , V_14 + V_8 ) ;
F_5 ( V_2 , V_14 , V_7 | V_18 | V_15 ) ;
}
F_5 ( V_2 , V_19 , V_3 ) ;
F_5 ( V_2 , V_20 , 0 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_21 |
V_15 | V_18 |
V_22 ) ;
F_5 ( V_2 , V_14 , V_23 | V_21 |
V_15 | V_18 |
V_22 ) ;
} else {
F_5 ( V_2 , V_14 , V_23 | V_24 |
V_21 | V_15 | V_18 |
V_22 ) ;
}
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_23 ) )
goto V_25;
}
F_8 ( V_2 -> V_16 -> V_17 ,
L_2 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_25:
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
if ( F_3 ( V_2 , V_27 + V_8 ) & V_28 )
goto V_29;
F_7 ( 10 ) ;
}
F_8 ( V_2 -> V_16 -> V_17 ,
L_3 ,
V_4 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_29:
#if 0
dev_dbg(chip->card->dev,
"e) reg = 0x%x, val = 0x%x, BA0_ACCAD = 0x%x\n", reg,
snd_cs46xx_peekBA0(chip, BA0_ACSDA),
snd_cs46xx_peekBA0(chip, BA0_ACCAD));
#endif
V_6 = F_3 ( V_2 , V_13 + V_8 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
return V_6 ;
}
static unsigned short F_9 ( struct V_30 * V_31 ,
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
static void F_10 ( struct V_1 * V_2 ,
unsigned short V_3 ,
unsigned short V_33 ,
int V_4 )
{
int V_5 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
V_2 -> V_11 ( V_2 , 1 ) ;
F_5 ( V_2 , V_19 , V_3 ) ;
F_5 ( V_2 , V_20 , V_33 ) ;
F_3 ( V_2 , V_14 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_15 |
V_18 | V_22 ) ;
F_5 ( V_2 , V_14 , V_23 | V_15 |
V_18 | V_22 ) ;
} else {
F_5 ( V_2 , V_14 , V_23 | V_24 |
V_15 | V_18 | V_22 ) ;
}
for ( V_5 = 0 ; V_5 < 4000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_23 ) ) {
goto V_26;
}
}
F_8 ( V_2 -> V_16 -> V_17 ,
L_4 ,
V_4 , V_3 , V_33 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
}
static void F_11 ( struct V_30 * V_31 ,
unsigned short V_3 ,
unsigned short V_33 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
int V_4 = V_31 -> V_34 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
F_10 ( V_2 , V_3 , V_33 , V_4 ) ;
}
int F_12 ( struct V_1 * V_2 ,
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
F_13 ( * V_35 ++ , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
static inline void F_14 ( void * V_37 , const void * V_35 , unsigned int V_36 )
{
#ifdef F_15
memcpy ( V_37 , V_35 , V_36 ) ;
#else
T_1 * V_43 = V_37 ;
const T_3 * V_44 = V_35 ;
V_36 /= 4 ;
while ( V_36 -- > 0 )
* V_43 ++ = F_16 ( * V_44 ++ ) ;
#endif
}
static void F_17 ( struct V_45 * V_46 )
{
if ( ! V_46 )
return;
F_18 ( V_46 -> V_47 ) ;
F_18 ( V_46 -> V_48 . V_49 ) ;
if ( V_46 -> V_50 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_46 -> V_52 ; V_51 ++ )
F_18 ( V_46 -> V_50 [ V_51 ] . V_53 ) ;
F_18 ( V_46 -> V_50 ) ;
}
F_18 ( V_46 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
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
V_56 = F_20 ( & V_62 , V_63 , & V_2 -> V_64 -> V_17 ) ;
if ( V_56 < 0 )
return V_56 ;
V_59 = V_62 -> V_65 / 4 ;
if ( V_59 < 2 ) {
V_56 = - V_39 ;
goto error;
}
V_56 = - V_66 ;
V_46 = F_21 ( sizeof( * V_46 ) , V_67 ) ;
if ( ! V_46 )
goto error;
V_46 -> V_47 = F_22 ( V_55 , V_67 ) ;
if ( ! V_46 -> V_47 )
goto error;
V_58 = 0 ;
V_60 = ( const T_3 * ) V_62 -> V_53 ;
V_57 = V_46 -> V_48 . V_68 = F_16 ( V_60 [ V_58 ++ ] ) ;
if ( V_57 >= 40 )
goto V_69;
V_46 -> V_48 . V_49 =
F_23 ( V_57 , sizeof( struct V_70 ) , V_67 ) ;
if ( ! V_46 -> V_48 . V_49 )
goto error;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
struct V_70 * V_71 =
& V_46 -> V_48 . V_49 [ V_51 ] ;
if ( V_58 + 2 + V_72 / 4 > V_59 )
goto V_69;
V_71 -> V_73 = F_16 ( V_60 [ V_58 ++ ] ) ;
memcpy ( V_71 -> V_74 , & V_60 [ V_58 ] , V_72 - 1 ) ;
V_58 += V_72 / 4 ;
V_71 -> V_75 = F_16 ( V_60 [ V_58 ++ ] ) ;
}
if ( V_58 >= V_59 )
goto V_69;
V_57 = V_46 -> V_52 = F_16 ( V_60 [ V_58 ++ ] ) ;
if ( V_57 > 10 )
goto V_69;
V_46 -> V_50 =
F_23 ( V_57 , sizeof( struct V_76 ) , V_67 ) ;
if ( ! V_46 -> V_50 )
goto error;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
struct V_76 * V_71 = & V_46 -> V_50 [ V_51 ] ;
if ( V_58 + 3 > V_59 )
goto V_69;
V_71 -> V_77 = F_16 ( V_60 [ V_58 ++ ] ) ;
V_71 -> V_8 = F_16 ( V_60 [ V_58 ++ ] ) ;
V_71 -> V_65 = F_16 ( V_60 [ V_58 ++ ] ) ;
if ( V_58 + V_71 -> V_65 > V_59 )
goto V_69;
V_71 -> V_53 = F_24 ( V_71 -> V_65 * 4 , V_67 ) ;
if ( ! V_71 -> V_53 )
goto error;
F_14 ( V_71 -> V_53 , & V_60 [ V_58 ] , V_71 -> V_65 * 4 ) ;
V_58 += V_71 -> V_65 ;
}
* V_54 = V_46 ;
F_25 ( V_62 ) ;
return 0 ;
V_69:
V_56 = - V_39 ;
error:
F_17 ( V_46 ) ;
F_25 ( V_62 ) ;
return V_56 ;
}
int F_26 ( struct V_1 * V_2 ,
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
F_13 ( 0 , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_61 * V_62 ;
int V_51 , V_65 , V_56 ;
V_56 = F_20 ( & V_62 , L_6 , & V_2 -> V_64 -> V_17 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_62 -> V_65 != sizeof( * V_2 -> V_78 ) ) {
V_56 = - V_39 ;
goto error;
}
V_2 -> V_78 = F_27 ( sizeof( * V_2 -> V_78 ) ) ;
if ( ! V_2 -> V_78 ) {
V_56 = - V_66 ;
goto error;
}
F_14 ( V_2 -> V_78 , V_62 -> V_53 , sizeof( * V_2 -> V_78 ) ) ;
V_65 = 0 ;
for ( V_51 = 0 ; V_51 < V_79 ; V_51 ++ )
V_65 += V_2 -> V_78 -> V_80 [ V_51 ] . V_65 ;
if ( V_65 > V_81 * 4 )
V_56 = - V_39 ;
error:
F_25 ( V_62 ) ;
return V_56 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_41 , V_56 ;
unsigned int V_8 = 0 ;
struct V_82 * V_78 = V_2 -> V_78 ;
for ( V_41 = 0 ; V_41 < V_79 ; V_41 ++ ) {
V_56 = F_12 ( V_2 ,
& V_78 -> V_83 [ V_8 ] ,
V_78 -> V_80 [ V_41 ] . V_8 ,
V_78 -> V_80 [ V_41 ] . V_65 ) ;
if ( V_56 < 0 )
return V_56 ;
V_8 += V_78 -> V_80 [ V_41 ] . V_65 >> 2 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_41 ;
F_30 ( V_2 , V_84 , V_85 ) ;
F_30 ( V_2 , V_84 , V_86 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
F_30 ( V_2 , V_87 , V_88 + V_41 ) ;
F_30 ( V_2 , V_89 , 0xFFFF ) ;
}
F_30 ( V_2 , V_87 , 0 ) ;
F_30 ( V_2 , V_90 , 0xadf ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_91 )
{
T_1 V_51 , V_92 = 0 ;
for( V_51 = 0 ; V_51 < 50 ; V_51 ++ ) {
V_92 = F_3 ( V_2 , V_93 ) ;
if( ! ( V_92 & V_94 ) )
break;
F_32 ( V_91 ) ;
}
if( V_92 & V_94 ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_7 ) ;
return - V_39 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_41 , V_95 = 0 ;
unsigned int V_7 ;
V_7 = F_3 ( V_2 , V_96 ) ;
if ( ! ( V_7 & V_97 ) ) {
F_5 ( V_2 , V_96 , V_7 | V_97 ) ;
V_95 = 1 ;
}
F_5 ( V_2 , V_98 , 0 ) ;
for ( V_41 = 0 ; V_41 < 0xFF ; V_41 ++ ) {
if ( F_31 ( V_2 , 1 ) ) {
F_34 ( V_2 -> V_16 -> V_17 ,
L_8 ,
V_41 ) ;
if ( V_95 )
F_5 ( V_2 , V_96 , V_7 ) ;
break;
}
F_5 ( V_2 , V_99 , V_41 ) ;
F_5 ( V_2 , V_100 , V_101 ) ;
}
if ( V_95 )
F_5 ( V_2 , V_96 , V_7 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_102 ;
F_30 ( V_2 , V_90 , 0xadf ) ;
F_30 ( V_2 , V_84 , V_103 | V_104 | V_86 ) ;
for ( V_102 = 0 ; V_102 < 25 ; V_102 ++ ) {
F_7 ( 50 ) ;
if ( ! ( F_36 ( V_2 , V_84 ) & V_104 ) )
break;
}
if ( F_36 ( V_2 , V_84 ) & V_104 )
F_8 ( V_2 -> V_16 -> V_17 , L_9 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_84 , 0 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned int V_105 )
{
unsigned long V_106 ;
unsigned int V_107 , V_108 ;
unsigned int V_109 ;
unsigned int V_110 , V_111 ;
V_107 = V_105 << 16 ;
V_109 = V_107 / 48000 ;
V_107 -= V_109 * 48000 ;
V_107 <<= 10 ;
V_109 <<= 10 ;
V_108 = V_107 / 48000 ;
V_109 += V_108 ;
V_107 -= V_108 * 48000 ;
V_110 = V_107 / V_112 ;
V_107 -= V_110 * V_112 ;
V_111 = V_107 ;
F_39 ( & V_2 -> V_113 , V_106 ) ;
F_30 ( V_2 , V_114 ,
( ( V_111 << 16 ) & 0xFFFF0000 ) | ( V_110 & 0xFFFF ) ) ;
F_30 ( V_2 , V_115 , V_109 ) ;
F_40 ( & V_2 -> V_113 , V_106 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_105 )
{
unsigned long V_106 ;
unsigned int V_109 , V_116 , V_107 , V_108 ;
unsigned int V_110 , V_111 , V_117 ;
unsigned int V_118 , V_102 ;
if ( ( V_105 * 9 ) < 48000 )
V_105 = 48000 / 9 ;
if ( V_105 > 48000 )
V_105 = 48000 ;
V_107 = V_105 << 16 ;
V_116 = V_107 / 48000 ;
V_107 -= V_116 * 48000 ;
V_107 <<= 7 ;
V_116 <<= 7 ;
V_116 += V_107 / 48000 ;
V_116 ^= 0xFFFFFFFF ;
V_116 ++ ;
V_107 = 48000 << 16 ;
V_109 = V_107 / V_105 ;
V_107 -= V_109 * V_105 ;
V_107 <<= 10 ;
V_109 <<= 10 ;
V_108 = V_107 / V_105 ;
V_109 += V_108 ;
V_107 -= V_108 * V_105 ;
V_110 = V_107 / V_112 ;
V_107 -= V_110 * V_112 ;
V_111 = V_107 ;
V_117 = ( ( 48000 * 24 ) + V_105 - 1 ) / V_105 ;
F_39 ( & V_2 -> V_113 , V_106 ) ;
F_30 ( V_2 , V_119 ,
( ( V_111 << 16 ) & 0xFFFF0000 ) | ( V_110 & 0xFFFF ) ) ;
F_30 ( V_2 , V_120 , V_116 ) ;
F_30 ( V_2 , V_121 ,
( ( ( V_122 + ( V_117 << 2 ) ) << 16 ) & 0xFFFF0000 ) | 0x80 ) ;
F_30 ( V_2 , V_123 , V_109 ) ;
F_40 ( & V_2 -> V_113 , V_106 ) ;
V_118 = 1 ;
for ( V_102 = 2 ; V_102 <= 64 ; V_102 *= 2 ) {
if ( ( ( V_105 / V_102 ) * V_102 ) != V_105 )
V_118 *= 2 ;
}
if ( ( ( V_105 / 3 ) * 3 ) != V_105 ) {
V_118 *= 3 ;
}
for ( V_102 = 5 ; V_102 <= 125 ; V_102 *= 5 ) {
if ( ( ( V_105 / V_102 ) * V_102 ) != V_105 )
V_118 *= 5 ;
}
F_39 ( & V_2 -> V_113 , V_106 ) ;
F_30 ( V_2 , V_124 , V_118 ) ;
F_30 ( V_2 , V_125 , ( 0x00800000 | V_118 ) ) ;
F_30 ( V_2 , V_126 , 0x0000FFFF ) ;
F_30 ( V_2 , V_127 , ( ( 65536 * V_105 ) / 24000 ) ) ;
F_30 ( V_2 , ( V_127 + 4 ) , 0x0000FFFF ) ;
F_40 ( & V_2 -> V_113 , V_106 ) ;
}
static void F_42 ( struct V_128 * V_129 ,
struct V_130 * V_131 , T_4 V_132 )
{
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 = V_134 -> V_32 ;
memcpy ( V_136 -> V_137 . V_138 + V_131 -> V_139 , V_134 -> V_140 + V_131 -> V_141 , V_132 ) ;
}
static int F_43 ( struct V_128 * V_129 )
{
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 = V_134 -> V_32 ;
F_44 ( V_129 , & V_136 -> V_142 , F_42 ) ;
return 0 ;
}
static void F_45 ( struct V_128 * V_129 ,
struct V_130 * V_131 , T_4 V_132 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
memcpy ( V_134 -> V_140 + V_131 -> V_141 ,
V_2 -> V_143 . V_137 . V_138 + V_131 -> V_139 , V_132 ) ;
}
static int F_47 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
F_48 ( V_129 , & V_2 -> V_143 . V_142 , F_45 ) ;
return 0 ;
}
static T_5 F_49 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
T_4 V_144 ;
struct V_135 * V_136 = V_129 -> V_134 -> V_32 ;
if ( F_2 ( ! V_136 -> V_145 ) )
return - V_146 ;
#ifdef F_50
V_144 = F_36 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 + 2 ) << 2 ) ;
#else
V_144 = F_36 ( V_2 , V_148 ) ;
#endif
V_144 -= V_136 -> V_137 . V_149 ;
return V_144 >> V_136 -> V_150 ;
}
static T_5 F_51 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
T_4 V_144 ;
struct V_135 * V_136 = V_129 -> V_134 -> V_32 ;
#ifdef F_50
if ( F_2 ( ! V_136 -> V_145 ) )
return - V_146 ;
V_144 = F_36 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 + 2 ) << 2 ) ;
#else
V_144 = F_36 ( V_2 , V_148 ) ;
#endif
V_144 -= V_136 -> V_137 . V_149 ;
return F_52 ( V_129 , & V_136 -> V_142 , V_144 ) ;
}
static T_5 F_53 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
T_4 V_144 = F_36 ( V_2 , V_151 ) - V_2 -> V_143 . V_137 . V_149 ;
return V_144 >> V_2 -> V_143 . V_150 ;
}
static T_5 F_54 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
T_4 V_144 = F_36 ( V_2 , V_151 ) - V_2 -> V_143 . V_137 . V_149 ;
return F_55 ( V_129 , & V_2 -> V_143 . V_142 , V_144 ) ;
}
static int F_56 ( struct V_128 * V_129 ,
int V_152 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
int V_6 = 0 ;
#ifdef F_50
struct V_135 * V_136 = V_129 -> V_134 -> V_32 ;
if ( ! V_136 -> V_145 ) {
return - V_146 ;
}
#endif
switch ( V_152 ) {
case V_153 :
case V_154 :
#ifdef F_50
F_30 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 +
V_155 ) << 2 , 0x80008000 ) ;
if ( V_136 -> V_145 -> V_156 )
F_57 ( V_2 , V_136 -> V_145 ) ;
if ( V_129 -> V_134 -> V_157 != V_158 )
F_43 ( V_129 ) ;
#else
F_58 ( & V_2 -> V_113 ) ;
if ( V_129 -> V_134 -> V_157 != V_158 )
F_43 ( V_129 ) ;
{ unsigned int V_7 ;
V_7 = F_36 ( V_2 , V_159 ) ;
V_7 &= 0x0000ffff ;
F_30 ( V_2 , V_159 , V_2 -> V_160 | V_7 ) ;
}
F_59 ( & V_2 -> V_113 ) ;
#endif
break;
case V_161 :
case V_162 :
#ifdef F_50
F_30 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 +
V_155 ) << 2 , 0xffffffff ) ;
if ( ! V_136 -> V_145 -> V_156 )
F_60 ( V_2 , V_136 -> V_145 ) ;
#else
F_58 ( & V_2 -> V_113 ) ;
{ unsigned int V_7 ;
V_7 = F_36 ( V_2 , V_159 ) ;
V_7 &= 0x0000ffff ;
F_30 ( V_2 , V_159 , V_7 ) ;
}
F_59 ( & V_2 -> V_113 ) ;
#endif
break;
default:
V_6 = - V_39 ;
break;
}
return V_6 ;
}
static int F_61 ( struct V_128 * V_129 ,
int V_152 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
unsigned int V_7 ;
int V_6 = 0 ;
F_58 ( & V_2 -> V_113 ) ;
switch ( V_152 ) {
case V_153 :
case V_154 :
V_7 = F_36 ( V_2 , V_163 ) ;
V_7 &= 0xffff0000 ;
F_30 ( V_2 , V_163 , V_2 -> V_143 . V_164 | V_7 ) ;
break;
case V_161 :
case V_162 :
V_7 = F_36 ( V_2 , V_163 ) ;
V_7 &= 0xffff0000 ;
F_30 ( V_2 , V_163 , V_7 ) ;
break;
default:
V_6 = - V_39 ;
break;
}
F_59 ( & V_2 -> V_113 ) ;
return V_6 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_135 * V_136 ,
int V_165 )
{
if ( V_136 -> V_145 == NULL ) {
V_136 -> V_145 = F_63 ( V_2 , V_165 ,
V_136 , V_136 -> V_137 . V_149 , V_136 -> V_166 ) ;
if ( V_136 -> V_145 == NULL ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_10 ) ;
return - V_66 ;
}
V_136 -> V_145 -> V_165 = V_165 ;
} else
if ( ( int ) V_136 -> V_145 -> V_165 != V_165 ) {
int V_156 = V_136 -> V_145 -> V_156 ;
F_64 ( V_2 , V_136 -> V_145 ) ;
if ( ( V_136 -> V_145 = F_63 ( V_2 , V_165 , V_136 ,
V_136 -> V_137 . V_149 ,
V_136 -> V_166 ) ) == NULL ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_11 ) ;
return - V_66 ;
}
if ( ! V_156 ) F_57 ( V_2 , V_136 -> V_145 ) ;
V_136 -> V_145 -> V_165 = V_165 ;
}
return 0 ;
}
static int F_65 ( struct V_128 * V_129 ,
struct V_167 * V_168 )
{
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 ;
int V_56 ;
#ifdef F_50
struct V_1 * V_2 = F_46 ( V_129 ) ;
int V_165 = F_66 ( V_168 ) ;
int V_169 = F_67 ( V_168 ) ;
#endif
V_136 = V_134 -> V_32 ;
#ifdef F_50
if ( F_2 ( ! V_165 ) )
return - V_146 ;
F_68 ( & V_2 -> V_170 ) ;
if ( F_62 ( V_2 , V_136 , V_165 ) ) {
F_69 ( & V_2 -> V_170 ) ;
return - V_146 ;
}
F_2 ( ! V_136 -> V_145 ) ;
if ( ! V_136 -> V_145 ) {
F_69 ( & V_2 -> V_170 ) ;
return - V_146 ;
}
if ( F_70 ( V_2 , V_136 -> V_145 , V_169 ) ) {
F_69 ( & V_2 -> V_170 ) ;
return - V_39 ;
}
F_34 ( V_2 -> V_16 -> V_17 ,
L_12 ,
V_169 , F_71 ( V_168 ) ,
F_72 ( V_168 ) ) ;
#endif
if ( F_71 ( V_168 ) == V_158 ) {
if ( V_134 -> V_140 != V_136 -> V_137 . V_138 )
F_73 ( V_129 ) ;
V_134 -> V_140 = V_136 -> V_137 . V_138 ;
V_134 -> V_171 = V_136 -> V_137 . V_149 ;
V_134 -> V_172 = V_136 -> V_137 . V_132 ;
#ifdef F_50
if ( V_136 -> V_166 == V_173 ) {
V_129 -> V_174 = & V_175 ;
} else if ( V_136 -> V_166 == V_176 ) {
V_129 -> V_174 = & V_177 ;
} else if ( V_136 -> V_166 == V_178 ) {
V_129 -> V_174 = & V_179 ;
} else if ( V_136 -> V_166 == V_180 ) {
V_129 -> V_174 = & V_181 ;
} else {
F_74 () ;
}
#else
V_129 -> V_174 = & V_175 ;
#endif
} else {
if ( V_134 -> V_140 == V_136 -> V_137 . V_138 ) {
V_134 -> V_140 = NULL ;
V_134 -> V_171 = 0 ;
V_134 -> V_172 = 0 ;
}
if ( ( V_56 = F_75 ( V_129 , F_72 ( V_168 ) ) ) < 0 ) {
#ifdef F_50
F_69 ( & V_2 -> V_170 ) ;
#endif
return V_56 ;
}
#ifdef F_50
if ( V_136 -> V_166 == V_173 ) {
V_129 -> V_174 = & V_182 ;
} else if ( V_136 -> V_166 == V_176 ) {
V_129 -> V_174 = & V_183 ;
} else if ( V_136 -> V_166 == V_178 ) {
V_129 -> V_174 = & V_184 ;
} else if ( V_136 -> V_166 == V_180 ) {
V_129 -> V_174 = & V_185 ;
} else {
F_74 () ;
}
#else
V_129 -> V_174 = & V_182 ;
#endif
}
#ifdef F_50
F_69 ( & V_2 -> V_170 ) ;
#endif
return 0 ;
}
static int F_76 ( struct V_128 * V_129 )
{
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 ;
V_136 = V_134 -> V_32 ;
if ( ! V_136 ) return - V_146 ;
if ( V_134 -> V_140 != V_136 -> V_137 . V_138 )
F_73 ( V_129 ) ;
V_134 -> V_140 = NULL ;
V_134 -> V_171 = 0 ;
V_134 -> V_172 = 0 ;
return 0 ;
}
static int F_77 ( struct V_128 * V_129 )
{
unsigned int V_7 ;
unsigned int V_186 ;
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 ;
V_136 = V_134 -> V_32 ;
#ifdef F_50
if ( F_2 ( ! V_136 -> V_145 ) )
return - V_146 ;
V_186 = F_36 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 + 1 ) << 2 ) ;
V_186 &= ~ 0x0000f03f ;
#else
V_186 = F_36 ( V_2 , V_187 ) ;
V_186 &= ~ 0x0000f03f ;
#endif
V_136 -> V_150 = 2 ;
if ( V_134 -> V_188 == 1 ) {
V_136 -> V_150 -- ;
V_186 |= 0x00002000 ;
}
if ( F_78 ( V_134 -> V_189 ) == 8 ) {
V_136 -> V_150 -- ;
V_186 |= 0x00001000 ;
}
if ( F_79 ( V_134 -> V_189 ) )
V_186 |= 0x00008000 ;
if ( F_78 ( V_134 -> V_189 ) != 8 ) {
if ( F_80 ( V_134 -> V_189 ) )
V_186 |= 0x00004000 ;
}
memset ( & V_136 -> V_142 , 0 , sizeof( V_136 -> V_142 ) ) ;
V_136 -> V_142 . V_190 = F_81 ( V_129 ) ;
V_136 -> V_142 . V_191 = V_134 -> V_169 * V_158 << V_136 -> V_150 ;
#ifdef F_50
V_7 = F_36 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 ) << 2 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_136 -> V_150 ) - 1 ;
F_30 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 ) << 2 , V_7 ) ;
F_30 ( V_2 , ( V_136 -> V_145 -> V_147 -> V_73 + 1 ) << 2 , V_186 | V_136 -> V_145 -> V_192 ) ;
#else
F_30 ( V_2 , V_148 , V_136 -> V_137 . V_149 ) ;
V_7 = F_36 ( V_2 , V_193 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_136 -> V_150 ) - 1 ;
F_30 ( V_2 , V_193 , V_7 ) ;
F_30 ( V_2 , V_187 , V_186 ) ;
F_38 ( V_2 , V_134 -> V_105 ) ;
#endif
return 0 ;
}
static int F_82 ( struct V_128 * V_129 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
int V_56 ;
#ifdef F_50
F_83 ( V_2 , F_67 ( V_168 ) ) ;
#endif
if ( V_134 -> V_157 == V_158 ) {
if ( V_134 -> V_140 != V_2 -> V_143 . V_137 . V_138 )
F_73 ( V_129 ) ;
V_134 -> V_140 = V_2 -> V_143 . V_137 . V_138 ;
V_134 -> V_171 = V_2 -> V_143 . V_137 . V_149 ;
V_134 -> V_172 = V_2 -> V_143 . V_137 . V_132 ;
V_129 -> V_174 = & V_194 ;
} else {
if ( V_134 -> V_140 == V_2 -> V_143 . V_137 . V_138 ) {
V_134 -> V_140 = NULL ;
V_134 -> V_171 = 0 ;
V_134 -> V_172 = 0 ;
}
if ( ( V_56 = F_75 ( V_129 , F_72 ( V_168 ) ) ) < 0 )
return V_56 ;
V_129 -> V_174 = & V_195 ;
}
return 0 ;
}
static int F_84 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
if ( V_134 -> V_140 != V_2 -> V_143 . V_137 . V_138 )
F_73 ( V_129 ) ;
V_134 -> V_140 = NULL ;
V_134 -> V_171 = 0 ;
V_134 -> V_172 = 0 ;
return 0 ;
}
static int F_85 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
F_30 ( V_2 , V_151 , V_2 -> V_143 . V_137 . V_149 ) ;
V_2 -> V_143 . V_150 = 2 ;
memset ( & V_2 -> V_143 . V_142 , 0 , sizeof( V_2 -> V_143 . V_142 ) ) ;
V_2 -> V_143 . V_142 . V_190 = F_81 ( V_129 ) ;
V_2 -> V_143 . V_142 . V_191 = V_134 -> V_169 * V_158 << 2 ;
F_41 ( V_2 , V_134 -> V_105 ) ;
return 0 ;
}
static T_6 F_86 ( int V_196 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
T_1 V_198 ;
#ifdef F_50
struct V_199 * V_200 = V_2 -> V_199 ;
T_1 V_201 ;
int V_51 ;
struct V_135 * V_136 = NULL ;
#endif
V_198 = F_3 ( V_2 , V_202 ) ;
if ( ( V_198 & 0x7fffffff ) == 0 ) {
F_5 ( V_2 , V_203 , V_204 | V_205 ) ;
return V_206 ;
}
#ifdef F_50
V_201 = F_3 ( V_2 , V_207 ) ;
for ( V_51 = 0 ; V_51 < V_208 ; ++ V_51 ) {
if ( V_51 <= 15 ) {
if ( V_198 & ( 1 << V_51 ) ) {
if ( V_51 == V_209 ) {
if ( V_2 -> V_143 . V_129 )
F_87 ( V_2 -> V_143 . V_129 ) ;
} else {
if ( V_200 -> V_210 [ V_51 ] . V_211 &&
V_200 -> V_210 [ V_51 ] . V_32 &&
! V_200 -> V_210 [ V_51 ] . V_156 ) {
V_136 = V_200 -> V_210 [ V_51 ] . V_32 ;
F_87 ( V_136 -> V_129 ) ;
}
}
}
} else {
if ( V_201 & ( 1 << ( V_51 - 16 ) ) ) {
if ( V_200 -> V_210 [ V_51 ] . V_211 &&
V_200 -> V_210 [ V_51 ] . V_32 &&
! V_200 -> V_210 [ V_51 ] . V_156 ) {
V_136 = V_200 -> V_210 [ V_51 ] . V_32 ;
F_87 ( V_136 -> V_129 ) ;
}
}
}
}
#else
if ( ( V_198 & V_212 ) && V_2 -> V_213 ) {
if ( V_2 -> V_213 -> V_129 )
F_87 ( V_2 -> V_213 -> V_129 ) ;
}
if ( ( V_198 & V_214 ) && V_2 -> V_215 ) {
if ( V_2 -> V_143 . V_129 )
F_87 ( V_2 -> V_143 . V_129 ) ;
}
#endif
if ( ( V_198 & V_216 ) && V_2 -> V_217 ) {
unsigned char V_218 ;
F_58 ( & V_2 -> V_113 ) ;
while ( ( F_3 ( V_2 , V_219 ) & V_220 ) == 0 ) {
V_218 = F_3 ( V_2 , V_221 ) ;
if ( ( V_2 -> V_222 & V_223 ) == 0 )
continue;
F_88 ( V_2 -> V_224 , & V_218 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_219 ) & V_225 ) == 0 ) {
if ( ( V_2 -> V_222 & V_226 ) == 0 )
break;
if ( F_89 ( V_2 -> V_227 , & V_218 , 1 ) != 1 ) {
V_2 -> V_222 &= ~ V_226 ;
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
break;
}
F_5 ( V_2 , V_229 , V_218 ) ;
}
F_59 ( & V_2 -> V_113 ) ;
}
F_5 ( V_2 , V_203 , V_204 | V_205 ) ;
return V_230 ;
}
static void F_90 ( struct V_133 * V_134 )
{
F_18 ( V_134 -> V_32 ) ;
}
static int F_91 ( struct V_128 * V_129 , int V_166 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_135 * V_136 ;
struct V_133 * V_134 = V_129 -> V_134 ;
V_136 = F_21 ( sizeof( * V_136 ) , V_67 ) ;
if ( V_136 == NULL )
return - V_66 ;
if ( F_92 ( V_231 , F_93 ( V_2 -> V_64 ) ,
V_232 , & V_136 -> V_137 ) < 0 ) {
F_18 ( V_136 ) ;
return - V_66 ;
}
V_134 -> V_233 = V_234 ;
V_134 -> V_32 = V_136 ;
V_134 -> V_235 = F_90 ;
V_136 -> V_129 = V_129 ;
#ifdef F_50
F_68 ( & V_2 -> V_170 ) ;
V_136 -> V_145 = NULL ;
V_136 -> V_166 = V_166 ;
F_94 ( V_134 , 0 ,
V_236 ,
& V_237 ) ;
F_69 ( & V_2 -> V_170 ) ;
#else
V_2 -> V_213 = V_136 ;
#endif
if ( V_2 -> V_238 )
V_129 -> V_134 -> V_233 . V_239 |= V_240 ;
V_2 -> V_11 ( V_2 , 1 ) ;
return 0 ;
}
static int F_95 ( struct V_128 * V_129 )
{
F_34 ( V_129 -> V_215 -> V_16 -> V_17 , L_13 ) ;
return F_91 ( V_129 , V_173 ) ;
}
static int F_96 ( struct V_128 * V_129 )
{
F_34 ( V_129 -> V_215 -> V_16 -> V_17 , L_14 ) ;
return F_91 ( V_129 , V_176 ) ;
}
static int F_97 ( struct V_128 * V_129 )
{
F_34 ( V_129 -> V_215 -> V_16 -> V_17 , L_15 ) ;
return F_91 ( V_129 , V_178 ) ;
}
static int F_98 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
F_34 ( V_2 -> V_16 -> V_17 , L_16 ) ;
F_68 ( & V_2 -> V_170 ) ;
F_99 ( V_2 ) ;
F_69 ( & V_2 -> V_170 ) ;
return F_91 ( V_129 , V_180 ) ;
}
static int F_100 ( struct V_128 * V_129 )
{
int V_56 ;
struct V_1 * V_2 = F_46 ( V_129 ) ;
F_34 ( V_2 -> V_16 -> V_17 , L_17 ) ;
V_56 = F_101 ( V_129 ) ;
F_68 ( & V_2 -> V_170 ) ;
F_102 ( V_2 ) ;
F_69 ( & V_2 -> V_170 ) ;
return V_56 ;
}
static int F_103 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
if ( F_92 ( V_231 , F_93 ( V_2 -> V_64 ) ,
V_232 , & V_2 -> V_143 . V_137 ) < 0 )
return - V_66 ;
V_2 -> V_143 . V_129 = V_129 ;
V_129 -> V_134 -> V_233 = V_241 ;
if ( V_2 -> V_238 )
V_129 -> V_134 -> V_233 . V_239 |= V_240 ;
V_2 -> V_11 ( V_2 , 1 ) ;
#ifdef F_50
F_94 ( V_129 -> V_134 , 0 ,
V_236 ,
& V_237 ) ;
#endif
return 0 ;
}
static int F_101 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
struct V_133 * V_134 = V_129 -> V_134 ;
struct V_135 * V_136 ;
V_136 = V_134 -> V_32 ;
if ( ! V_136 ) return - V_146 ;
#ifdef F_50
F_68 ( & V_2 -> V_170 ) ;
if ( V_136 -> V_145 ) {
F_64 ( V_2 , V_136 -> V_145 ) ;
V_136 -> V_145 = NULL ;
}
F_69 ( & V_2 -> V_170 ) ;
#else
V_2 -> V_213 = NULL ;
#endif
V_136 -> V_129 = NULL ;
F_104 ( & V_136 -> V_137 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_105 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_46 ( V_129 ) ;
V_2 -> V_143 . V_129 = NULL ;
F_104 ( & V_2 -> V_143 . V_137 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
int V_135 ( struct V_1 * V_2 , int V_242 )
{
struct V_243 * V_215 ;
int V_56 ;
if ( ( V_56 = F_106 ( V_2 -> V_16 , L_18 , V_242 , V_244 , 1 , & V_215 ) ) < 0 )
return V_56 ;
V_215 -> V_32 = V_2 ;
F_107 ( V_215 , V_245 , & V_175 ) ;
F_107 ( V_215 , V_246 , & V_194 ) ;
V_215 -> V_247 = 0 ;
strcpy ( V_215 -> V_248 , L_18 ) ;
V_2 -> V_215 = V_215 ;
F_108 ( V_215 , V_231 ,
F_93 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 , int V_242 )
{
struct V_243 * V_215 ;
int V_56 ;
if ( ( V_56 = F_106 ( V_2 -> V_16 , L_19 , V_242 , V_244 , 0 , & V_215 ) ) < 0 )
return V_56 ;
V_215 -> V_32 = V_2 ;
F_107 ( V_215 , V_245 , & V_177 ) ;
V_215 -> V_247 = 0 ;
strcpy ( V_215 -> V_248 , L_19 ) ;
V_2 -> V_249 = V_215 ;
F_108 ( V_215 , V_231 ,
F_93 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , int V_242 )
{
struct V_243 * V_215 ;
int V_56 ;
if ( ( V_56 = F_106 ( V_2 -> V_16 , L_20 , V_242 , V_244 , 0 , & V_215 ) ) < 0 )
return V_56 ;
V_215 -> V_32 = V_2 ;
F_107 ( V_215 , V_245 , & V_179 ) ;
V_215 -> V_247 = 0 ;
strcpy ( V_215 -> V_248 , L_20 ) ;
V_2 -> V_250 = V_215 ;
F_108 ( V_215 , V_231 ,
F_93 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
int F_111 ( struct V_1 * V_2 , int V_242 )
{
struct V_243 * V_215 ;
int V_56 ;
if ( ( V_56 = F_106 ( V_2 -> V_16 , L_21 , V_242 , 1 , 0 , & V_215 ) ) < 0 )
return V_56 ;
V_215 -> V_32 = V_2 ;
F_107 ( V_215 , V_245 , & V_181 ) ;
V_215 -> V_247 = 0 ;
strcpy ( V_215 -> V_248 , L_21 ) ;
V_2 -> V_249 = V_215 ;
F_108 ( V_215 , V_231 ,
F_93 ( V_2 -> V_64 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
static void F_112 ( struct V_251 * V_252 )
{
struct V_1 * V_2 = V_252 -> V_32 ;
V_2 -> V_253 = NULL ;
}
static void F_113 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( F_2 ( V_31 != V_2 -> V_31 [ V_9 ] &&
V_31 != V_2 -> V_31 [ V_10 ] ) )
return;
if ( V_31 == V_2 -> V_31 [ V_9 ] ) {
V_2 -> V_31 [ V_9 ] = NULL ;
V_2 -> V_254 = NULL ;
}
else
V_2 -> V_31 [ V_10 ] = NULL ;
}
static int F_114 ( struct V_255 * V_256 ,
struct V_257 * V_258 )
{
V_258 -> type = V_259 ;
V_258 -> V_5 = 2 ;
V_258 -> V_260 . integer . V_261 = 0 ;
V_258 -> V_260 . integer . V_262 = 0x7fff ;
return 0 ;
}
static int F_115 ( struct V_255 * V_256 , struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_3 = V_256 -> V_265 ;
unsigned int V_33 = F_36 ( V_2 , V_3 ) ;
V_264 -> V_260 . integer . V_260 [ 0 ] = 0xffff - ( V_33 >> 16 ) ;
V_264 -> V_260 . integer . V_260 [ 1 ] = 0xffff - ( V_33 & 0xffff ) ;
return 0 ;
}
static int F_117 ( struct V_255 * V_256 , struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_3 = V_256 -> V_265 ;
unsigned int V_33 = ( ( 0xffff - V_264 -> V_260 . integer . V_260 [ 0 ] ) << 16 |
( 0xffff - V_264 -> V_260 . integer . V_260 [ 1 ] ) ) ;
unsigned int V_266 = F_36 ( V_2 , V_3 ) ;
int V_267 = ( V_266 != V_33 ) ;
if ( V_267 ) {
F_30 ( V_2 , V_3 , V_33 ) ;
}
return V_267 ;
}
static int F_118 ( struct V_255 * V_256 , struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
V_264 -> V_260 . integer . V_260 [ 0 ] = V_2 -> V_199 -> V_268 ;
V_264 -> V_260 . integer . V_260 [ 1 ] = V_2 -> V_199 -> V_269 ;
return 0 ;
}
static int F_119 ( struct V_255 * V_256 , struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_267 = 0 ;
if ( V_2 -> V_199 -> V_269 != V_264 -> V_260 . integer . V_260 [ 0 ] ||
V_2 -> V_199 -> V_268 != V_264 -> V_260 . integer . V_260 [ 1 ] ) {
F_120 ( V_2 ,
V_264 -> V_260 . integer . V_260 [ 0 ] ,
V_264 -> V_260 . integer . V_260 [ 1 ] ) ;
V_267 = 1 ;
}
return V_267 ;
}
static int F_121 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_3 = V_256 -> V_265 ;
if ( V_3 == V_270 )
V_264 -> V_260 . integer . V_260 [ 0 ] = ( V_2 -> V_199 -> V_271 & V_272 ) ;
else
V_264 -> V_260 . integer . V_260 [ 0 ] = V_2 -> V_199 -> V_273 ;
return 0 ;
}
static int F_122 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_267 , V_274 ;
switch ( V_256 -> V_265 ) {
case V_270 :
F_68 ( & V_2 -> V_170 ) ;
V_267 = ( V_2 -> V_199 -> V_271 & V_272 ) ;
if ( V_264 -> V_260 . integer . V_260 [ 0 ] && ! V_267 )
F_123 ( V_2 ) ;
else if ( V_267 && ! V_264 -> V_260 . integer . V_260 [ 0 ] )
F_124 ( V_2 ) ;
V_274 = ( V_267 != ( V_2 -> V_199 -> V_271 & V_272 ) ) ;
F_69 ( & V_2 -> V_170 ) ;
break;
case V_275 :
V_267 = V_2 -> V_199 -> V_273 ;
if ( V_264 -> V_260 . integer . V_260 [ 0 ] && ! V_267 ) {
F_125 ( V_2 ) ;
}
else if ( V_267 && ! V_264 -> V_260 . integer . V_260 [ 0 ] )
F_126 ( V_2 ) ;
V_274 = ( V_267 != V_2 -> V_199 -> V_273 ) ;
break;
default:
V_274 = - V_39 ;
F_74 () ;
}
return V_274 ;
}
static int F_127 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
if ( V_200 -> V_276 != NULL )
V_264 -> V_260 . integer . V_260 [ 0 ] = 1 ;
else
V_264 -> V_260 . integer . V_260 [ 0 ] = 0 ;
return 0 ;
}
static int F_128 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
int V_267 = 0 ;
if ( V_264 -> V_260 . integer . V_260 [ 0 ] && ! V_200 -> V_276 ) {
F_129 ( V_2 ) ;
V_267 = 1 ;
} else if ( ! V_264 -> V_260 . integer . V_260 [ 0 ] && V_200 -> V_276 ) {
F_130 ( V_2 ) ;
V_267 = 1 ;
}
return V_267 ;
}
static int F_131 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
if ( V_200 -> V_277 != NULL )
V_264 -> V_260 . integer . V_260 [ 0 ] = 1 ;
else
V_264 -> V_260 . integer . V_260 [ 0 ] = 0 ;
return 0 ;
}
static int F_132 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
int V_267 = 0 ;
if ( V_264 -> V_260 . integer . V_260 [ 0 ] && ! V_200 -> V_277 ) {
F_133 ( V_2 ) ;
V_267 = 1 ;
} else if ( ! V_264 -> V_260 . integer . V_260 [ 0 ] && V_200 -> V_277 ) {
F_134 ( V_2 ) ;
V_267 = 1 ;
}
return V_267 ;
}
static int F_135 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_278 = F_3 ( V_2 , V_279 ) ;
if ( V_278 & V_280 )
V_264 -> V_260 . integer . V_260 [ 0 ] = 1 ;
else
V_264 -> V_260 . integer . V_260 [ 0 ] = 0 ;
return 0 ;
}
static int F_136 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
int V_278 = F_3 ( V_2 , V_279 ) ;
int V_281 = F_3 ( V_2 , V_282 ) ;
if ( V_264 -> V_260 . integer . V_260 [ 0 ] ) {
F_5 ( V_2 , V_279 ,
V_280 | V_278 ) ;
F_5 ( V_2 , V_282 ,
V_283 | V_281 ) ;
} else {
F_5 ( V_2 , V_279 , V_278 & ~ V_280 ) ;
F_5 ( V_2 , V_282 , V_281 & ~ V_283 ) ;
}
return ( V_278 != ( int ) F_3 ( V_2 , V_279 ) ) ;
}
static int F_137 ( struct V_255 * V_256 , struct V_257 * V_258 )
{
V_258 -> type = V_284 ;
V_258 -> V_5 = 1 ;
return 0 ;
}
static int F_138 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
F_68 ( & V_2 -> V_170 ) ;
V_264 -> V_260 . V_285 . V_92 [ 0 ] = F_139 ( ( V_200 -> V_286 >> 24 ) & 0xff ) ;
V_264 -> V_260 . V_285 . V_92 [ 1 ] = F_139 ( ( V_200 -> V_286 >> 16 ) & 0xff ) ;
V_264 -> V_260 . V_285 . V_92 [ 2 ] = 0 ;
V_264 -> V_260 . V_285 . V_92 [ 3 ] = F_139 ( ( V_200 -> V_286 ) & 0xff ) ;
F_69 ( & V_2 -> V_170 ) ;
return 0 ;
}
static int F_140 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
unsigned int V_33 ;
int V_267 ;
F_68 ( & V_2 -> V_170 ) ;
V_33 = ( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 2 ] ) << 16 ) |
( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_267 = ( unsigned int ) V_200 -> V_286 != V_33 ;
V_200 -> V_286 = V_33 ;
if ( ! ( V_200 -> V_271 & V_287 ) )
F_141 ( V_2 , V_288 , V_33 ) ;
F_69 ( & V_2 -> V_170 ) ;
return V_267 ;
}
static int F_142 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
V_264 -> V_260 . V_285 . V_92 [ 0 ] = 0xff ;
V_264 -> V_260 . V_285 . V_92 [ 1 ] = 0xff ;
V_264 -> V_260 . V_285 . V_92 [ 2 ] = 0x00 ;
V_264 -> V_260 . V_285 . V_92 [ 3 ] = 0xff ;
return 0 ;
}
static int F_143 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
F_68 ( & V_2 -> V_170 ) ;
V_264 -> V_260 . V_285 . V_92 [ 0 ] = F_139 ( ( V_200 -> V_289 >> 24 ) & 0xff ) ;
V_264 -> V_260 . V_285 . V_92 [ 1 ] = F_139 ( ( V_200 -> V_289 >> 16 ) & 0xff ) ;
V_264 -> V_260 . V_285 . V_92 [ 2 ] = 0 ;
V_264 -> V_260 . V_285 . V_92 [ 3 ] = F_139 ( ( V_200 -> V_289 ) & 0xff ) ;
F_69 ( & V_2 -> V_170 ) ;
return 0 ;
}
static int F_144 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
struct V_199 * V_200 = V_2 -> V_199 ;
unsigned int V_33 ;
int V_267 ;
F_68 ( & V_2 -> V_170 ) ;
V_33 = ( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 1 ] ) << 16 ) |
( ( unsigned int ) F_139 ( V_264 -> V_260 . V_285 . V_92 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_267 = V_200 -> V_289 != V_33 ;
V_200 -> V_289 = V_33 ;
if ( V_200 -> V_271 & V_287 )
F_141 ( V_2 , V_288 , V_33 ) ;
F_69 ( & V_2 -> V_170 ) ;
return V_267 ;
}
static int F_145 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
unsigned short V_33 ;
V_33 = F_146 ( V_2 -> V_31 [ V_9 ] , V_290 ) ;
V_264 -> V_260 . integer . V_260 [ 0 ] = ( V_33 & 0x200 ) ? 0 : 1 ;
return 0 ;
}
static int F_147 ( struct V_255 * V_256 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = F_116 ( V_256 ) ;
return F_148 ( V_2 -> V_31 [ V_9 ] ,
V_290 , 0x200 ,
V_264 -> V_260 . integer . V_260 [ 0 ] ? 0 : 0x200 ) ;
}
static void F_149 ( struct V_30 * V_31 )
{
unsigned long V_291 ;
int V_56 ;
F_150 ( V_31 , V_292 , 0 ) ;
if ( V_31 -> V_34 == V_9 ) {
F_34 ( V_31 -> V_252 -> V_16 -> V_17 , L_22 , 0x0 ) ;
F_11 ( V_31 , V_290 , 0x0 ) ;
} else if ( V_31 -> V_34 == V_10 ) {
F_34 ( V_31 -> V_252 -> V_16 -> V_17 , L_23 , 0x3 ) ;
F_11 ( V_31 , V_290 , 0x3 ) ;
} else {
F_74 () ;
}
F_7 ( 50 ) ;
V_291 = V_293 + V_294 ;
do {
unsigned short V_295 ;
F_146 ( V_31 , V_292 ) ;
F_146 ( V_31 , V_296 ) ;
F_146 ( V_31 , V_297 ) ;
V_295 = F_146 ( V_31 , V_298 ) ;
if ( V_295 != 0xffff && ( V_295 & 1 ) != 0 )
return;
F_150 ( V_31 , V_299 , 0x8a05 ) ;
if ( ( V_56 = F_146 ( V_31 , V_299 ) ) == 0x8a05 )
return;
F_6 ( 10 ) ;
} while ( F_151 ( V_291 , V_293 ) );
F_8 ( V_31 -> V_252 -> V_16 -> V_17 ,
L_24 ) ;
}
static int F_152 ( struct V_1 * V_2 , int V_300 )
{
int V_41 , V_56 ;
struct V_301 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = V_2 ;
V_31 . V_235 = F_113 ;
V_31 . V_34 = V_300 ;
if ( V_2 -> V_302 == V_303 )
V_31 . V_304 = V_305 ;
if ( V_300 == V_10 ) {
F_10 ( V_2 , V_292 , 0 , V_300 ) ;
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_292 , V_300 ) & 0x8000 ) {
F_34 ( V_2 -> V_16 -> V_17 ,
L_25 ) ;
return - V_146 ;
}
}
F_10 ( V_2 , V_306 , 0x8000 , V_300 ) ;
for ( V_41 = 0 ; V_41 < 100 ; ++ V_41 ) {
if ( F_1 ( V_2 , V_306 , V_300 ) == 0x8000 ) {
V_56 = F_153 ( V_2 -> V_253 , & V_31 , & V_2 -> V_31 [ V_300 ] ) ;
return V_56 ;
}
F_6 ( 10 ) ;
}
F_34 ( V_2 -> V_16 -> V_17 , L_26 , V_300 ) ;
return - V_146 ;
}
int F_154 ( struct V_1 * V_2 , int V_307 )
{
struct V_308 * V_16 = V_2 -> V_16 ;
struct V_309 V_310 ;
int V_56 ;
unsigned int V_41 ;
static struct V_311 V_174 = {
#ifdef F_50
. V_312 = F_149 ,
#endif
. V_313 = F_11 ,
. V_314 = F_9 ,
} ;
V_2 -> V_315 = 0 ;
F_34 ( V_2 -> V_16 -> V_17 , L_27 ) ;
if ( ( V_56 = V_251 ( V_16 , 0 , & V_174 , V_2 , & V_2 -> V_253 ) ) < 0 )
return V_56 ;
V_2 -> V_253 -> V_235 = F_112 ;
if ( F_152 ( V_2 , V_9 ) < 0 )
return - V_146 ;
V_2 -> V_315 = 1 ;
#ifdef F_50
F_34 ( V_2 -> V_16 -> V_17 , L_28 ) ;
if ( ! F_152 ( V_2 , V_10 ) )
V_2 -> V_315 = 2 ;
#endif
for ( V_41 = 0 ; V_41 < F_155 ( V_316 ) ; V_41 ++ ) {
struct V_255 * V_317 ;
V_317 = F_156 ( & V_316 [ V_41 ] , V_2 ) ;
if ( V_317 && V_317 -> V_310 . V_318 == V_319 )
V_317 -> V_310 . V_242 = V_307 ;
if ( ( V_56 = F_157 ( V_16 , V_317 ) ) < 0 )
return V_56 ;
}
memset ( & V_310 , 0 , sizeof( V_310 ) ) ;
V_310 . V_318 = V_320 ;
strcpy ( V_310 . V_248 , L_29 ) ;
V_2 -> V_254 = F_158 ( V_2 -> V_16 , & V_310 ) ;
#ifdef F_50
if ( V_2 -> V_315 == 1 ) {
unsigned int V_321 = V_2 -> V_31 [ V_9 ] -> V_310 & 0xffff ;
if ( V_321 == 0x592b || V_321 == 0x592d ) {
V_56 = F_157 ( V_16 , F_156 ( & V_322 , V_2 ) ) ;
if ( V_56 < 0 )
return V_56 ;
F_159 ( V_2 -> V_31 [ V_9 ] ,
V_290 , 0x200 ) ;
}
}
if ( V_2 -> V_323 ) {
F_34 ( V_2 -> V_16 -> V_17 , L_30 ) ;
V_2 -> V_323 ( V_2 ) ;
}
#endif
V_2 -> V_302 ( V_2 , 1 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_228 , V_324 ) ;
F_7 ( 100 ) ;
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
static int F_161 ( struct V_325 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_162 ( & V_2 -> V_113 ) ;
V_2 -> V_326 |= V_327 ;
V_2 -> V_222 |= V_328 ;
V_2 -> V_224 = V_129 ;
if ( ! ( V_2 -> V_326 & V_329 ) ) {
F_160 ( V_2 ) ;
} else {
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
F_163 ( & V_2 -> V_113 ) ;
return 0 ;
}
static int F_164 ( struct V_325 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
F_162 ( & V_2 -> V_113 ) ;
V_2 -> V_222 &= ~ ( V_328 | V_223 ) ;
V_2 -> V_224 = NULL ;
if ( ! ( V_2 -> V_326 & V_329 ) ) {
F_160 ( V_2 ) ;
} else {
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
V_2 -> V_326 &= ~ V_327 ;
F_163 ( & V_2 -> V_113 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_165 ( struct V_325 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_162 ( & V_2 -> V_113 ) ;
V_2 -> V_326 |= V_329 ;
V_2 -> V_222 |= V_330 ;
V_2 -> V_227 = V_129 ;
if ( ! ( V_2 -> V_326 & V_327 ) ) {
F_160 ( V_2 ) ;
} else {
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
F_163 ( & V_2 -> V_113 ) ;
return 0 ;
}
static int F_166 ( struct V_325 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
F_162 ( & V_2 -> V_113 ) ;
V_2 -> V_222 &= ~ ( V_330 | V_226 ) ;
V_2 -> V_227 = NULL ;
if ( ! ( V_2 -> V_326 & V_327 ) ) {
F_160 ( V_2 ) ;
} else {
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
V_2 -> V_326 &= ~ V_329 ;
F_163 ( & V_2 -> V_113 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static void F_167 ( struct V_325 * V_129 , int V_331 )
{
unsigned long V_106 ;
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
F_39 ( & V_2 -> V_113 , V_106 ) ;
if ( V_331 ) {
if ( ( V_2 -> V_222 & V_223 ) == 0 ) {
V_2 -> V_222 |= V_223 ;
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
} else {
if ( V_2 -> V_222 & V_223 ) {
V_2 -> V_222 &= ~ V_223 ;
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
}
F_40 ( & V_2 -> V_113 , V_106 ) ;
}
static void F_168 ( struct V_325 * V_129 , int V_331 )
{
unsigned long V_106 ;
struct V_1 * V_2 = V_129 -> V_217 -> V_32 ;
unsigned char V_332 ;
F_39 ( & V_2 -> V_113 , V_106 ) ;
if ( V_331 ) {
if ( ( V_2 -> V_222 & V_226 ) == 0 ) {
V_2 -> V_222 |= V_226 ;
while ( ( V_2 -> V_222 & V_226 ) &&
( F_3 ( V_2 , V_219 ) & V_225 ) == 0 ) {
if ( F_89 ( V_129 , & V_332 , 1 ) != 1 ) {
V_2 -> V_222 &= ~ V_226 ;
} else {
F_5 ( V_2 , V_229 , V_332 ) ;
}
}
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
} else {
if ( V_2 -> V_222 & V_226 ) {
V_2 -> V_222 &= ~ V_226 ;
F_5 ( V_2 , V_228 , V_2 -> V_222 ) ;
}
}
F_40 ( & V_2 -> V_113 , V_106 ) ;
}
int F_169 ( struct V_1 * V_2 , int V_242 )
{
struct V_333 * V_217 ;
int V_56 ;
if ( ( V_56 = F_170 ( V_2 -> V_16 , L_31 , V_242 , 1 , 1 , & V_217 ) ) < 0 )
return V_56 ;
strcpy ( V_217 -> V_248 , L_31 ) ;
F_171 ( V_217 , V_334 , & V_335 ) ;
F_171 ( V_217 , V_336 , & V_337 ) ;
V_217 -> V_247 |= V_338 | V_339 | V_340 ;
V_217 -> V_32 = V_2 ;
V_2 -> V_217 = V_217 ;
return 0 ;
}
static void F_172 ( struct V_341 * V_341 )
{
struct V_1 * V_2 = F_173 ( V_341 ) ;
if ( F_2 ( ! V_2 ) )
return;
F_5 ( V_2 , V_342 , 0xFF ) ;
}
static unsigned char F_174 ( struct V_341 * V_341 )
{
struct V_1 * V_2 = F_173 ( V_341 ) ;
if ( F_2 ( ! V_2 ) )
return 0 ;
return F_3 ( V_2 , V_342 ) ;
}
static int F_175 ( struct V_341 * V_341 , int * V_343 , int * V_344 )
{
struct V_1 * V_2 = F_173 ( V_341 ) ;
unsigned V_345 , V_346 , V_347 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_345 = F_3 ( V_2 , V_348 ) ;
V_346 = F_3 ( V_2 , V_349 ) ;
V_347 = F_3 ( V_2 , V_342 ) ;
* V_344 = ( ~ V_347 >> 4 ) & 0x0F ;
V_343 [ 0 ] = ( ( V_345 & V_350 ) >> V_351 ) & 0xFFFF ;
V_343 [ 1 ] = ( ( V_345 & V_352 ) >> V_353 ) & 0xFFFF ;
V_343 [ 2 ] = ( ( V_346 & V_354 ) >> V_355 ) & 0xFFFF ;
V_343 [ 3 ] = ( ( V_346 & V_356 ) >> V_357 ) & 0xFFFF ;
for( V_347 = 0 ; V_347 < 4 ; ++ V_347 )
if( V_343 [ V_347 ] == 0xFFFF ) V_343 [ V_347 ] = - 1 ;
return 0 ;
}
static int F_176 ( struct V_341 * V_341 , int V_358 )
{
switch ( V_358 ) {
case V_359 :
return 0 ;
case V_360 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
int F_177 ( struct V_1 * V_2 )
{
struct V_341 * V_361 ;
V_2 -> V_341 = V_361 = F_178 () ;
if ( ! V_361 ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_32 ) ;
return - V_66 ;
}
F_179 ( V_361 , L_33 ) ;
F_180 ( V_361 , L_34 , F_181 ( V_2 -> V_64 ) ) ;
F_182 ( V_361 , & V_2 -> V_64 -> V_17 ) ;
F_183 ( V_361 , V_2 ) ;
V_361 -> V_362 = F_176 ;
V_361 -> V_314 = F_174 ;
V_361 -> V_363 = F_172 ;
V_361 -> V_364 = F_175 ;
F_5 ( V_2 , V_365 , 0xFF ) ;
F_5 ( V_2 , V_366 , V_367 ) ;
F_184 ( V_361 ) ;
return 0 ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
if ( V_2 -> V_341 ) {
F_186 ( V_2 -> V_341 ) ;
V_2 -> V_341 = NULL ;
}
}
int F_177 ( struct V_1 * V_2 ) { return - V_368 ; }
static inline void F_185 ( struct V_1 * V_2 ) { }
static T_7 F_187 ( struct V_369 * V_71 ,
void * V_370 ,
struct V_371 * V_371 , char T_8 * V_372 ,
T_4 V_5 , T_9 V_373 )
{
struct V_374 * V_40 = V_71 -> V_32 ;
if ( F_188 ( V_372 , V_40 -> V_42 + V_373 , V_5 ) )
return - V_375 ;
return V_5 ;
}
static int F_189 ( struct V_308 * V_16 , struct V_1 * V_2 )
{
struct V_369 * V_71 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_374 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ! F_190 ( V_16 , V_40 -> V_248 , & V_71 ) ) {
V_71 -> V_376 = V_377 ;
V_71 -> V_32 = V_2 ;
V_71 -> V_218 . V_174 = & V_378 ;
V_71 -> V_65 = V_40 -> V_65 ;
V_71 -> V_358 = V_379 | V_380 ;
}
}
#ifdef F_50
F_191 ( V_16 , V_2 ) ;
#endif
return 0 ;
}
static int F_192 ( struct V_1 * V_2 )
{
#ifdef F_50
F_193 ( V_2 ) ;
#endif
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
V_7 = F_36 ( V_2 , V_187 ) ;
V_7 &= ~ 0x0000f03f ;
V_7 |= 0x00000010 ;
F_30 ( V_2 , V_187 , V_7 ) ;
V_7 = F_36 ( V_2 , V_381 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000011 ;
F_30 ( V_2 , V_381 , V_7 ) ;
V_7 = F_36 ( V_2 , V_159 ) ;
F_30 ( V_2 , V_159 , V_7 & 0x0000ffff ) ;
V_7 = F_36 ( V_2 , V_163 ) ;
F_30 ( V_2 , V_163 , V_7 & 0xffff0000 ) ;
F_29 ( V_2 ) ;
F_37 ( V_2 ) ;
F_5 ( V_2 , V_96 , 0 ) ;
V_7 = F_3 ( V_2 , V_96 ) & ~ V_97 ;
F_5 ( V_2 , V_96 , V_7 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_41 ;
if ( F_2 ( ! V_2 ) )
return - V_39 ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , 1 ) ;
F_185 ( V_2 ) ;
if ( V_2 -> V_302 )
V_2 -> V_302 ( V_2 , - V_2 -> V_382 ) ;
F_192 ( V_2 ) ;
if ( V_2 -> V_40 . V_41 [ 0 ] . V_383 )
F_194 ( V_2 ) ;
if ( V_2 -> V_196 >= 0 )
F_196 ( V_2 -> V_196 , V_2 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , - V_2 -> V_382 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_374 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
F_197 ( V_40 -> V_42 ) ;
F_198 ( V_40 -> V_383 ) ;
}
#ifdef F_50
if ( V_2 -> V_199 ) {
F_199 ( V_2 ) ;
V_2 -> V_199 = NULL ;
}
for ( V_41 = 0 ; V_41 < V_384 ; V_41 ++ )
F_17 ( V_2 -> V_385 [ V_41 ] ) ;
#else
F_200 ( V_2 -> V_78 ) ;
#endif
#ifdef F_201
F_18 ( V_2 -> V_386 ) ;
#endif
F_202 ( V_2 -> V_64 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_203 ( struct V_387 * V_242 )
{
struct V_1 * V_2 = V_242 -> V_388 ;
return F_195 ( V_2 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
int V_389 ;
F_5 ( V_2 , V_96 , 0 ) ;
F_5 ( V_2 , V_390 , 0 ) ;
#ifdef F_50
F_5 ( V_2 , V_391 , V_392 | V_393 |
V_394 ) ;
#else
F_5 ( V_2 , V_391 , V_392 | V_395 ) ;
#endif
F_5 ( V_2 , V_14 , 0 ) ;
#ifdef F_50
F_5 ( V_2 , V_396 , 0 ) ;
#endif
F_7 ( 50 ) ;
F_5 ( V_2 , V_14 , V_22 ) ;
#ifdef F_50
F_5 ( V_2 , V_396 , V_22 ) ;
#endif
F_5 ( V_2 , V_14 , V_18 | V_22 ) ;
#ifdef F_50
F_5 ( V_2 , V_396 , V_18 | V_22 ) ;
#endif
F_32 ( 10 ) ;
F_5 ( V_2 , V_390 , V_397 ) ;
F_5 ( V_2 , V_398 , V_399 | V_400 ) ;
F_5 ( V_2 , V_401 , 0x3a ) ;
F_5 ( V_2 , V_402 , V_403 ) ;
F_5 ( V_2 , V_96 , V_404 ) ;
F_6 ( 100 ) ;
F_5 ( V_2 , V_96 , V_404 | V_97 ) ;
F_5 ( V_2 , V_405 , V_406 ) ;
F_33 ( V_2 ) ;
F_5 ( V_2 , V_407 , V_408 | V_409 ) ;
F_5 ( V_2 , V_410 , V_411 | V_409 ) ;
F_5 ( V_2 , V_390 , V_397 | V_412 ) ;
#ifdef F_50
F_5 ( V_2 , V_413 , V_414 ) ;
F_5 ( V_2 , V_415 , 0 ) ;
F_5 ( V_2 , V_416 , 0 ) ;
F_5 ( V_2 , V_417 , 0 ) ;
F_5 ( V_2 , V_418 , 1 ) ;
#endif
F_32 ( 5 ) ;
V_389 = 150 ;
while ( V_389 -- > 0 ) {
if ( F_3 ( V_2 , V_27 ) & V_419 )
goto V_25;
F_6 ( 10 ) ;
}
F_8 ( V_2 -> V_16 -> V_17 ,
L_35 ) ;
F_8 ( V_2 -> V_16 -> V_17 ,
L_36 ) ;
return - V_420 ;
V_25:
#ifdef F_50
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 150 ; V_5 ++ ) {
F_7 ( 25 ) ;
if ( F_3 ( V_2 , V_421 ) & V_419 )
break;
}
if ( ! ( F_3 ( V_2 , V_421 ) & V_419 ) )
F_34 ( V_2 -> V_16 -> V_17 ,
L_37 ) ;
}
#endif
F_5 ( V_2 , V_14 , V_15 | V_18 | V_22 ) ;
#ifdef F_50
F_5 ( V_2 , V_396 , V_15 | V_18 | V_22 ) ;
#endif
V_389 = 150 ;
while ( V_389 -- > 0 ) {
if ( ( F_3 ( V_2 , V_422 ) & ( V_423 | V_424 ) ) == ( V_423 | V_424 ) )
goto V_29;
F_6 ( 10 ) ;
}
#ifndef F_50
F_8 ( V_2 -> V_16 -> V_17 ,
L_38 ) ;
return - V_420 ;
#else
F_8 ( V_2 -> V_16 -> V_17 , L_39 ) ;
F_8 ( V_2 -> V_16 -> V_17 ,
L_40 ) ;
F_8 ( V_2 -> V_16 -> V_17 ,
L_41 ) ;
F_8 ( V_2 -> V_16 -> V_17 ,
L_42 ) ;
return - V_420 ;
#endif
V_29:
F_5 ( V_2 , V_425 , V_426 | V_427 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
F_5 ( V_2 , V_203 , V_205 | V_204 ) ;
V_7 = F_36 ( V_2 , V_187 ) ;
V_7 &= ~ 0x0000f03f ;
F_30 ( V_2 , V_187 , V_7 ) ;
V_7 = F_36 ( V_2 , V_381 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000001 ;
F_30 ( V_2 , V_381 , V_7 ) ;
}
int F_206 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
#ifdef F_50
int V_51 ;
#endif
int V_56 ;
F_29 ( V_2 ) ;
#ifdef F_50
for ( V_51 = 0 ; V_51 < V_384 ; V_51 ++ ) {
V_56 = F_19 ( V_2 , & V_2 -> V_385 [ V_51 ] , V_428 [ V_51 ] ) ;
if ( V_56 < 0 ) {
F_8 ( V_2 -> V_16 -> V_17 , L_43 ,
V_428 [ V_51 ] ) ;
return V_56 ;
}
V_56 = F_207 ( V_2 , V_2 -> V_385 [ V_51 ] ) ;
if ( V_56 < 0 ) {
F_8 ( V_2 -> V_16 -> V_17 , L_44 ,
V_428 [ V_51 ] ) ;
return V_56 ;
}
}
if ( F_208 ( V_2 ) < 0 )
return - V_420 ;
#else
V_56 = F_19 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_28 ( V_2 ) ;
if ( V_56 < 0 ) {
F_8 ( V_2 -> V_16 -> V_17 , L_45 ) ;
return V_56 ;
}
V_7 = F_36 ( V_2 , V_159 ) ;
V_2 -> V_160 = V_7 & 0xffff0000 ;
F_30 ( V_2 , V_159 , V_7 & 0x0000ffff ) ;
#endif
V_7 = F_36 ( V_2 , V_163 ) ;
V_2 -> V_143 . V_164 = V_7 & 0x0000ffff ;
F_30 ( V_2 , V_163 , V_7 & 0xffff0000 ) ;
F_32 ( 5 ) ;
F_38 ( V_2 , 8000 ) ;
F_41 ( V_2 , 8000 ) ;
F_35 ( V_2 ) ;
F_205 ( V_2 ) ;
#ifndef F_50
F_30 ( V_2 , V_429 , 0x80008000 ) ;
F_30 ( V_2 , V_430 , 0x80008000 ) ;
#endif
return 0 ;
}
static void F_209 ( struct V_1 * V_2 , int V_267 )
{
}
static int F_210 ( struct V_1 * V_2 )
{
T_1 V_41 , V_431 , V_7 , V_95 = 0 ;
T_10 V_432 , V_433 , V_434 ;
F_34 ( V_2 -> V_16 -> V_17 , L_46 ) ;
V_7 = F_3 ( V_2 , V_96 ) ;
if ( ! ( V_7 & V_97 ) ) {
F_5 ( V_2 , V_96 , V_7 | V_97 ) ;
V_95 = 1 ;
}
if( V_2 -> V_315 != 2 ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_47 ) ;
return - V_39 ;
}
V_432 = F_1 ( V_2 ,
V_435 ,
V_10 ) ;
V_432 &= 0xFEFF ;
F_10 ( V_2 ,
V_435 , V_432 ,
V_10 ) ;
V_433 = F_1 ( V_2 ,
V_436 ,
V_10 ) ;
V_433 &= 0x27F ;
F_10 ( V_2 ,
V_436 , V_433 ,
V_10 ) ;
V_434 = F_1 ( V_2 , V_437 ,
V_10 ) ;
V_434 &= 0x27F ;
F_10 ( V_2 , V_437 , V_434 ,
V_10 ) ;
V_431 = F_3 ( V_2 , V_425 ) ;
V_431 |= 0x200 ;
F_5 ( V_2 , V_425 , V_431 ) ;
if ( F_31 ( V_2 , 1 ) ) {
F_34 ( V_2 -> V_16 -> V_17 , L_48 ) ;
return - V_39 ;
}
for( V_41 = 0x90 ; V_41 <= 0x9F ; V_41 ++ ) {
F_5 ( V_2 , V_98 , 0x1800 ) ;
if ( F_31 ( V_2 , 200 ) ) {
F_34 ( V_2 -> V_16 -> V_17 ,
L_8 ,
V_41 ) ;
return - V_39 ;
}
F_5 ( V_2 , V_99 , V_41 ) ;
F_5 ( V_2 , V_100 , V_101 ) ;
}
F_31 ( V_2 , 200 ) ;
if ( V_95 )
F_5 ( V_2 , V_96 , V_7 ) ;
return 0 ;
}
static void V_303 ( struct V_1 * V_2 , int V_267 )
{
#ifdef F_50
int V_266 = V_2 -> V_382 ;
#endif
int V_438 , V_33 ;
V_2 -> V_382 += V_267 ;
V_438 = F_1 ( V_2 , V_439 ,
V_9 ) ;
V_33 = V_438 ;
if ( V_2 -> V_382 ) {
V_33 |= 0x8000 ;
} else {
V_33 &= ~ 0x8000 ;
}
if ( V_33 != V_438 ) {
F_10 ( V_2 , V_439 , V_33 ,
V_9 ) ;
if ( V_2 -> V_254 )
F_211 ( V_2 -> V_16 , V_440 ,
& V_2 -> V_254 -> V_310 ) ;
}
#ifdef F_50
if ( V_2 -> V_382 && ! V_266 ) {
F_210 ( V_2 ) ;
}
#endif
}
static void F_212 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_279 , V_280 ) ;
F_5 ( V_2 , V_282 , V_280 ) ;
}
static void F_213 ( struct V_1 * V_2 , int V_267 )
{
int V_266 = V_2 -> V_382 ;
int V_278 = F_3 ( V_2 , V_279 ) ;
int V_281 = F_3 ( V_2 , V_282 ) ;
V_2 -> V_382 += V_267 ;
if ( V_2 -> V_382 && ! V_266 ) {
F_34 ( V_2 -> V_16 -> V_17 , L_49 ) ;
F_5 ( V_2 , V_279 ,
V_441 | V_278 ) ;
F_5 ( V_2 , V_282 ,
V_442 | V_281 ) ;
} else if ( V_266 && ! V_2 -> V_382 ) {
F_34 ( V_2 -> V_16 -> V_17 , L_50 ) ;
F_5 ( V_2 , V_279 , V_278 & ~ V_441 ) ;
F_5 ( V_2 , V_282 , V_281 & ~ V_442 ) ;
}
}
static void F_214 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_16 -> V_17 , L_51 ) ;
F_5 ( V_2 , V_279 , V_280 ) ;
F_5 ( V_2 , V_282 , V_280 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
#ifdef F_50
unsigned int V_41 ;
int V_56 ;
struct V_308 * V_16 = V_2 -> V_16 ;
#endif
F_212 ( V_2 ) ;
F_34 ( V_2 -> V_16 -> V_17 , L_52 ) ;
#ifdef F_50
if ( V_2 -> V_443 )
return;
for ( V_41 = 0 ; V_41 < F_155 ( V_444 ) ; V_41 ++ ) {
struct V_255 * V_317 ;
V_317 = F_156 ( & V_444 [ V_41 ] , V_2 ) ;
if ( ( V_56 = F_157 ( V_16 , V_317 ) ) < 0 ) {
F_8 ( V_16 -> V_17 ,
L_53 ,
V_56 ) ;
break;
}
}
#endif
}
static void F_216 ( struct V_1 * V_2 , int V_267 )
{
T_10 V_445 , V_446 ;
if ( ! V_2 -> V_447 )
return;
V_2 -> V_382 += V_267 ;
V_446 = V_445 = F_217 ( V_2 -> V_447 + 0x10 ) ;
if ( ! V_2 -> V_382 )
V_446 |= 0x2000 ;
else
V_446 &= ~ 0x2000 ;
if ( V_446 != V_445 )
F_218 ( V_446 , V_2 -> V_447 + 0x10 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_448 * V_449 ;
T_11 V_450 ;
V_2 -> V_447 = 0 ;
V_449 = F_220 ( V_451 ,
V_452 , NULL ) ;
if ( V_449 == NULL )
return;
F_221 ( V_449 , 0x41 , & V_450 ) ;
V_2 -> V_447 = V_450 << 8 ;
F_222 ( V_449 ) ;
}
static int F_223 ( struct V_242 * V_17 )
{
struct V_308 * V_16 = F_224 ( V_17 ) ;
struct V_1 * V_2 = V_16 -> V_32 ;
int V_51 , V_453 ;
F_225 ( V_16 , V_454 ) ;
V_2 -> V_443 = 1 ;
F_226 ( V_2 -> V_215 ) ;
F_227 ( V_2 -> V_31 [ V_9 ] ) ;
F_227 ( V_2 -> V_31 [ V_10 ] ) ;
for ( V_51 = 0 ; V_51 < F_155 ( V_386 ) ; V_51 ++ )
V_2 -> V_386 [ V_51 ] = F_3 ( V_2 , V_386 [ V_51 ] ) ;
V_453 = V_2 -> V_382 ;
V_2 -> V_302 ( V_2 , - V_2 -> V_382 ) ;
F_194 ( V_2 ) ;
V_2 -> V_11 ( V_2 , - V_2 -> V_382 ) ;
V_2 -> V_382 = V_453 ;
return 0 ;
}
static int F_228 ( struct V_242 * V_17 )
{
struct V_308 * V_16 = F_224 ( V_17 ) ;
struct V_1 * V_2 = V_16 -> V_32 ;
int V_453 ;
#ifdef F_50
int V_51 ;
#endif
unsigned int V_7 ;
V_453 = V_2 -> V_382 ;
V_2 -> V_382 = 0 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_204 ( V_2 ) ;
F_29 ( V_2 ) ;
#ifdef F_50
F_229 ( V_2 ) ;
for ( V_51 = 0 ; V_51 < F_155 ( V_386 ) ; V_51 ++ )
F_5 ( V_2 , V_386 [ V_51 ] , V_2 -> V_386 [ V_51 ] ) ;
#else
F_28 ( V_2 ) ;
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
F_230 ( V_2 -> V_31 [ V_9 ] ) ;
F_230 ( V_2 -> V_31 [ V_10 ] ) ;
V_7 = F_36 ( V_2 , V_163 ) ;
V_2 -> V_143 . V_164 = V_7 & 0x0000ffff ;
F_30 ( V_2 , V_163 , V_7 & 0xffff0000 ) ;
F_32 ( 5 ) ;
F_38 ( V_2 , 8000 ) ;
F_41 ( V_2 , 8000 ) ;
F_35 ( V_2 ) ;
F_205 ( V_2 ) ;
if ( V_453 )
V_2 -> V_302 ( V_2 , 1 ) ;
else
V_2 -> V_11 ( V_2 , - 1 ) ;
V_2 -> V_382 = V_453 ;
V_2 -> V_443 = 0 ;
F_225 ( V_16 , V_455 ) ;
return 0 ;
}
int F_231 ( struct V_308 * V_16 ,
struct V_448 * V_64 ,
int V_456 , int V_457 ,
struct V_1 * * V_458 )
{
struct V_1 * V_2 ;
int V_56 , V_41 ;
struct V_374 * V_40 ;
struct V_459 * V_460 ;
T_10 V_461 , V_462 ;
static struct V_463 V_174 = {
. V_464 = F_203 ,
} ;
* V_458 = NULL ;
if ( ( V_56 = F_232 ( V_64 ) ) < 0 )
return V_56 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_67 ) ;
if ( V_2 == NULL ) {
F_202 ( V_64 ) ;
return - V_66 ;
}
F_233 ( & V_2 -> V_113 ) ;
#ifdef F_50
F_234 ( & V_2 -> V_170 ) ;
#endif
V_2 -> V_16 = V_16 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_196 = - 1 ;
V_2 -> V_465 = F_235 ( V_64 , 0 ) ;
V_2 -> V_466 = F_235 ( V_64 , 1 ) ;
if ( V_2 -> V_465 == 0 || V_2 -> V_465 == ( unsigned long ) ~ 0 ||
V_2 -> V_466 == 0 || V_2 -> V_466 == ( unsigned long ) ~ 0 ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_54 ,
V_2 -> V_465 , V_2 -> V_466 ) ;
F_195 ( V_2 ) ;
return - V_66 ;
}
V_40 = & V_2 -> V_40 . V_248 . V_467 ;
strcpy ( V_40 -> V_248 , L_55 ) ;
V_40 -> V_468 = V_2 -> V_465 ;
V_40 -> V_65 = V_469 ;
V_40 = & V_2 -> V_40 . V_248 . V_470 ;
strcpy ( V_40 -> V_248 , L_56 ) ;
V_40 -> V_468 = V_2 -> V_466 + V_471 ;
V_40 -> V_65 = V_472 ;
V_40 = & V_2 -> V_40 . V_248 . V_473 ;
strcpy ( V_40 -> V_248 , L_57 ) ;
V_40 -> V_468 = V_2 -> V_466 + V_474 ;
V_40 -> V_65 = V_475 ;
V_40 = & V_2 -> V_40 . V_248 . V_476 ;
strcpy ( V_40 -> V_248 , L_58 ) ;
V_40 -> V_468 = V_2 -> V_466 + V_477 ;
V_40 -> V_65 = V_478 ;
V_40 = & V_2 -> V_40 . V_248 . V_3 ;
strcpy ( V_40 -> V_248 , L_59 ) ;
V_40 -> V_468 = V_2 -> V_466 + V_479 ;
V_40 -> V_65 = V_480 ;
F_236 ( V_64 , V_481 , & V_462 ) ;
F_236 ( V_64 , V_482 , & V_461 ) ;
for ( V_460 = & V_483 [ 0 ] ; V_460 -> V_248 ; V_460 ++ ) {
if ( V_460 -> V_484 == V_462 && V_460 -> V_310 == V_461 ) {
F_34 ( V_2 -> V_16 -> V_17 , L_60 ,
V_460 -> V_248 ) ;
V_2 -> V_302 = V_460 -> V_485 ;
V_2 -> V_11 = V_460 -> V_211 ;
V_2 -> V_323 = V_460 -> V_323 ;
if ( V_460 -> V_486 )
V_460 -> V_486 ( V_2 ) ;
break;
}
}
if ( V_456 ) {
F_237 ( V_2 -> V_16 -> V_17 ,
L_61 ) ;
V_2 -> V_302 = V_303 ;
}
if ( V_457 ) {
F_237 ( V_2 -> V_16 -> V_17 ,
L_62 ) ;
V_2 -> V_11 = F_216 ;
F_219 ( V_2 ) ;
}
if ( V_2 -> V_302 == NULL )
V_2 -> V_302 = F_209 ;
if ( V_2 -> V_11 == NULL )
V_2 -> V_11 = F_209 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_238 ( V_64 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ( V_40 -> V_383 = F_239 ( V_40 -> V_468 , V_40 -> V_65 ,
V_40 -> V_248 ) ) == NULL ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_63 ,
V_40 -> V_468 , V_40 -> V_468 + V_40 -> V_65 - 1 ) ;
F_195 ( V_2 ) ;
return - V_487 ;
}
V_40 -> V_42 = F_240 ( V_40 -> V_468 , V_40 -> V_65 ) ;
if ( V_40 -> V_42 == NULL ) {
F_8 ( V_2 -> V_16 -> V_17 ,
L_64 , V_40 -> V_248 ) ;
F_195 ( V_2 ) ;
return - V_66 ;
}
}
if ( F_241 ( V_64 -> V_196 , F_86 , V_488 ,
V_489 , V_2 ) ) {
F_8 ( V_2 -> V_16 -> V_17 , L_65 , V_64 -> V_196 ) ;
F_195 ( V_2 ) ;
return - V_487 ;
}
V_2 -> V_196 = V_64 -> V_196 ;
#ifdef F_50
V_2 -> V_199 = F_242 ( V_2 ) ;
if ( V_2 -> V_199 == NULL ) {
F_195 ( V_2 ) ;
return - V_66 ;
}
#endif
V_56 = F_204 ( V_2 ) ;
if ( V_56 < 0 ) {
F_195 ( V_2 ) ;
return V_56 ;
}
if ( ( V_56 = F_243 ( V_16 , V_490 , V_2 , & V_174 ) ) < 0 ) {
F_195 ( V_2 ) ;
return V_56 ;
}
F_189 ( V_16 , V_2 ) ;
#ifdef F_201
V_2 -> V_386 = F_24 ( sizeof( * V_2 -> V_386 ) *
F_155 ( V_386 ) , V_67 ) ;
if ( ! V_2 -> V_386 ) {
F_195 ( V_2 ) ;
return - V_66 ;
}
#endif
V_2 -> V_11 ( V_2 , - 1 ) ;
* V_458 = V_2 ;
return 0 ;
}
