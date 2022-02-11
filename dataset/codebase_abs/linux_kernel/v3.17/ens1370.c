static unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_3 = F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) ;
if ( ( V_3 & V_5 ) == 0 )
return V_3 ;
F_4 () ;
}
F_5 ( V_1 -> V_6 -> V_7 , L_1 ,
F_3 ( V_1 , 1371_SMPRATE ) , V_3 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_1 , unsigned short V_8 )
{
unsigned int V_9 , V_10 , V_11 , V_3 ;
V_9 = V_11 = F_1 ( V_1 ) ;
V_3 = V_9 & ( V_12 | V_13 |
V_14 | V_15 ) ;
V_3 |= F_7 ( V_8 ) | 0x10000 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
V_9 = F_1 ( V_1 ) ;
if ( ( V_9 & 0x00870000 ) != 0x00010000 ) {
for ( V_10 = 0 ; V_10 < V_4 ; V_10 ++ ) {
V_9 = F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) ;
if ( ( V_9 & 0x00870000 ) == 0x00010000 )
break;
}
}
V_3 = V_11 & ( V_12 | V_13 |
V_14 | V_15 ) ;
V_3 |= F_7 ( V_8 ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
return V_9 ;
}
static void F_9 ( struct V_1 * V_1 ,
unsigned short V_8 , unsigned short V_16 )
{
unsigned int V_3 ;
V_3 = F_1 ( V_1 ) &
( V_12 | V_13 |
V_14 | V_15 ) ;
V_3 |= F_7 ( V_8 ) | F_10 ( V_16 ) ;
F_8 ( V_3 | V_17 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
}
static void F_11 ( struct V_18 * V_19 ,
unsigned short V_8 , unsigned short V_20 )
{
struct V_1 * V_1 = V_19 -> V_21 ;
unsigned long V_22 = V_23 + V_24 / 10 ;
#if 0
dev_dbg(ensoniq->card->dev,
"CODEC WRITE: reg = 0x%x, val = 0x%x (0x%x), creg = 0x%x\n",
reg, val, ES_1370_CODEC_WRITE(reg, val), ES_REG(ensoniq, 1370_CODEC));
#endif
do {
if ( ! ( F_2 ( F_3 ( V_1 , V_25 ) ) & V_26 ) ) {
F_12 ( F_13 ( V_8 , V_20 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
return;
}
F_14 ( 1 ) ;
} while ( F_15 ( V_22 , V_23 ) );
F_5 ( V_1 -> V_6 -> V_7 , L_2 ,
F_2 ( F_3 ( V_1 , V_25 ) ) ) ;
}
static inline bool F_16 ( struct V_1 * V_1 )
{
return V_1 -> V_27 -> V_28 == 0x8938 ;
}
static void F_17 ( struct V_29 * V_30 ,
unsigned short V_8 , unsigned short V_20 )
{
struct V_1 * V_1 = V_30 -> V_21 ;
unsigned int V_2 , V_31 , V_32 ;
V_32 = F_16 ( V_1 ) ? V_33 : 0 ;
F_18 ( & V_1 -> V_34 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_35 ) ) {
V_31 = F_1 ( V_1 ) ;
F_8 ( ( V_31 & ( V_12 | V_13 |
V_14 | V_15 ) ) | 0x00010000 ,
F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) & 0x00870000 ) ==
0x00000000 )
break;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) & 0x00870000 ) ==
0x00010000 )
break;
}
F_8 ( F_19 ( V_8 , V_20 ) | V_32 ,
F_3 ( V_1 , 1371_CODEC ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_31 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_34 ) ;
return;
}
}
F_20 ( & V_1 -> V_34 ) ;
F_5 ( V_1 -> V_6 -> V_7 , L_3 ,
F_3 ( V_1 , 1371_CODEC ) , F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
}
static unsigned short F_21 ( struct V_29 * V_30 ,
unsigned short V_8 )
{
struct V_1 * V_1 = V_30 -> V_21 ;
unsigned int V_2 , V_31 , V_32 , V_36 = 0 ;
V_32 = F_16 ( V_1 ) ? V_33 : 0 ;
V_37:
F_18 ( & V_1 -> V_34 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_35 ) ) {
V_31 = F_1 ( V_1 ) ;
F_8 ( ( V_31 & ( V_12 | V_13 |
V_14 | V_15 ) ) | 0x00010000 ,
F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) & 0x00870000 ) ==
0x00000000 )
break;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) & 0x00870000 ) ==
0x00010000 )
break;
}
F_8 ( F_22 ( V_8 ) | V_32 ,
F_3 ( V_1 , 1371_CODEC ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_31 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_35 ) )
break;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( V_31 = F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) & V_38 ) {
if ( F_16 ( V_1 ) ) {
for ( V_2 = 0 ; V_2 < 100 ; V_2 ++ )
F_2 ( F_3 ( V_1 , V_39 ) ) ;
V_31 = F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ;
}
F_20 ( & V_1 -> V_34 ) ;
return F_23 ( V_31 ) ;
}
}
F_20 ( & V_1 -> V_34 ) ;
if ( ++ V_36 > 10 ) {
F_5 ( V_1 -> V_6 -> V_7 ,
L_4 ,
F_3 ( V_1 , 1371_CODEC ) , V_8 ,
F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
return 0 ;
}
goto V_37;
}
}
F_20 ( & V_1 -> V_34 ) ;
F_5 ( V_1 -> V_6 -> V_7 , L_5 ,
F_3 ( V_1 , 1371_CODEC ) , F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
return 0 ;
}
static void F_24 ( struct V_29 * V_30 )
{
F_25 ( 750 ) ;
F_21 ( V_30 , V_40 ) ;
F_21 ( V_30 , V_41 ) ;
F_21 ( V_30 , V_42 ) ;
F_25 ( 50 ) ;
}
static void F_26 ( struct V_1 * V_1 , unsigned int V_43 )
{
unsigned int V_44 , V_45 , V_46 , V_47 ;
F_18 ( & V_1 -> V_34 ) ;
V_44 = V_43 / 3000 ;
if ( ( 1 << V_44 ) & ( ( 1 << 15 ) | ( 1 << 13 ) | ( 1 << 11 ) | ( 1 << 9 ) ) )
V_44 -- ;
V_45 = ( 21 * V_44 - 1 ) | 1 ;
V_46 = ( ( 48000UL << 15 ) / V_43 ) * V_44 ;
V_47 = ( 48000UL << 15 ) / ( V_46 / V_44 ) ;
if ( V_43 >= 24000 ) {
if ( V_45 > 239 )
V_45 = 239 ;
F_9 ( V_1 , V_48 + V_49 ,
( ( ( 239 - V_45 ) >> 1 ) << 9 ) | ( V_44 << 4 ) ) ;
} else {
if ( V_45 > 119 )
V_45 = 119 ;
F_9 ( V_1 , V_48 + V_49 ,
0x8000 | ( ( ( 119 - V_45 ) >> 1 ) << 9 ) | ( V_44 << 4 ) ) ;
}
F_9 ( V_1 , V_48 + V_50 ,
( F_6 ( V_1 , V_48 +
V_50 ) & 0x00ff ) |
( ( V_46 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_48 + V_51 , V_46 & 0x7fff ) ;
F_9 ( V_1 , V_52 , V_44 << 8 ) ;
F_9 ( V_1 , V_52 + 1 , V_44 << 8 ) ;
F_20 ( & V_1 -> V_34 ) ;
}
static void F_27 ( struct V_1 * V_1 , unsigned int V_43 )
{
unsigned int V_46 , V_3 ;
F_18 ( & V_1 -> V_34 ) ;
V_46 = ( ( V_43 << 15 ) + 1500 ) / 3000 ;
V_3 = ( F_1 ( V_1 ) & ( V_12 |
V_14 | V_15 ) ) |
V_13 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_9 ( V_1 , V_53 + V_50 ,
( F_6 ( V_1 , V_53 +
V_50 ) & 0x00ff ) |
( ( V_46 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_53 + V_51 , V_46 & 0x7fff ) ;
V_3 = ( F_1 ( V_1 ) & ( V_12 |
V_14 | V_15 ) ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_34 ) ;
}
static void F_28 ( struct V_1 * V_1 , unsigned int V_43 )
{
unsigned int V_46 , V_3 ;
F_18 ( & V_1 -> V_34 ) ;
V_46 = ( ( V_43 << 15 ) + 1500 ) / 3000 ;
V_3 = ( F_1 ( V_1 ) & ( V_12 |
V_13 | V_15 ) ) |
V_14 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_9 ( V_1 , V_54 + V_50 ,
( F_6 ( V_1 , V_54 +
V_50 ) & 0x00ff ) |
( ( V_46 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_54 + V_51 ,
V_46 & 0x7fff ) ;
V_3 = ( F_1 ( V_1 ) & ( V_12 |
V_13 | V_15 ) ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_34 ) ;
}
static int F_29 ( struct V_55 * V_56 , int V_57 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
switch ( V_57 ) {
case V_58 :
case V_59 :
{
unsigned int V_60 = 0 ;
struct V_55 * V_61 ;
F_31 (s, substream) {
if ( V_61 == V_1 -> V_62 ) {
V_60 |= V_63 ;
F_32 ( V_61 , V_56 ) ;
} else if ( V_61 == V_1 -> V_64 ) {
V_60 |= V_65 ;
F_32 ( V_61 , V_56 ) ;
} else if ( V_61 == V_1 -> V_66 )
return - V_67 ;
}
F_33 ( & V_1 -> V_68 ) ;
if ( V_57 == V_58 )
V_1 -> V_69 |= V_60 ;
else
V_1 -> V_69 &= ~ V_60 ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_34 ( & V_1 -> V_68 ) ;
break;
}
case V_71 :
case V_72 :
{
unsigned int V_60 = 0 ;
struct V_55 * V_61 ;
F_31 (s, substream) {
if ( V_61 == V_1 -> V_62 ) {
V_60 |= V_73 ;
F_32 ( V_61 , V_56 ) ;
} else if ( V_61 == V_1 -> V_64 ) {
V_60 |= V_74 ;
F_32 ( V_61 , V_56 ) ;
} else if ( V_61 == V_1 -> V_66 ) {
V_60 |= V_75 ;
F_32 ( V_61 , V_56 ) ;
}
}
F_33 ( & V_1 -> V_68 ) ;
if ( V_57 == V_71 )
V_1 -> V_76 |= V_60 ;
else
V_1 -> V_76 &= ~ V_60 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_34 ( & V_1 -> V_68 ) ;
break;
}
default:
return - V_67 ;
}
return 0 ;
}
static int F_35 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
return F_36 ( V_56 , F_37 ( V_78 ) ) ;
}
static int F_38 ( struct V_55 * V_56 )
{
return F_39 ( V_56 ) ;
}
static int F_40 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
unsigned int V_81 = 0 ;
V_1 -> V_82 = F_41 ( V_56 ) ;
V_1 -> V_83 = F_42 ( V_56 ) ;
if ( F_43 ( V_80 -> V_84 ) == 16 )
V_81 |= 0x02 ;
if ( V_80 -> V_85 > 1 )
V_81 |= 0x01 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_76 &= ~ V_73 ;
#ifdef F_45
if ( V_80 -> V_43 == 48000 )
V_1 -> V_76 |= V_86 ;
else
V_1 -> V_76 &= ~ V_86 ;
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( F_46 ( V_87 ) , F_3 ( V_1 , V_88 ) ) ;
F_8 ( V_80 -> V_89 , F_3 ( V_1 , V_90 ) ) ;
F_8 ( ( V_1 -> V_82 >> 2 ) - 1 , F_3 ( V_1 , V_91 ) ) ;
V_1 -> V_69 &= ~ ( V_92 | V_63 | V_93 | V_94 ) ;
V_1 -> V_69 |= V_95 | F_47 ( V_81 ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( ( V_1 -> V_83 >> V_96 [ V_81 ] ) - 1 ,
F_3 ( V_1 , V_97 ) ) ;
#ifdef F_48
V_1 -> V_76 &= ~ V_98 ;
switch ( V_80 -> V_43 ) {
case 5512 : V_1 -> V_76 |= F_49 ( 0 ) ; break;
case 11025 : V_1 -> V_76 |= F_49 ( 1 ) ; break;
case 22050 : V_1 -> V_76 |= F_49 ( 2 ) ; break;
case 44100 : V_1 -> V_76 |= F_49 ( 3 ) ; break;
default: F_50 () ;
}
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
#ifndef F_48
F_27 ( V_1 , V_80 -> V_43 ) ;
#endif
return 0 ;
}
static int F_52 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
unsigned int V_81 = 0 ;
V_1 -> V_99 = F_41 ( V_56 ) ;
V_1 -> V_100 = F_42 ( V_56 ) ;
if ( F_43 ( V_80 -> V_84 ) == 16 )
V_81 |= 0x02 ;
if ( V_80 -> V_85 > 1 )
V_81 |= 0x01 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_76 &= ~ V_74 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( F_46 ( V_87 ) , F_3 ( V_1 , V_88 ) ) ;
F_8 ( V_80 -> V_89 , F_3 ( V_1 , V_101 ) ) ;
F_8 ( ( V_1 -> V_99 >> 2 ) - 1 , F_3 ( V_1 , V_102 ) ) ;
V_1 -> V_69 &= ~ ( V_103 | V_65 | V_104 |
V_105 | V_106 | V_107 ) ;
V_1 -> V_69 |= V_108 | F_53 ( V_81 ) |
F_54 ( V_81 & 2 ? 2 : 1 ) | F_55 ( 0 ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( ( V_1 -> V_100 >> V_96 [ V_81 ] ) - 1 ,
F_3 ( V_1 , V_109 ) ) ;
#ifdef F_48
if ( ! ( V_1 -> V_110 . V_111 . V_112 & V_113 ) ) {
V_1 -> V_76 &= ~ V_114 ;
V_1 -> V_76 |= F_56 ( F_57 ( V_80 -> V_43 ) ) ;
V_1 -> V_110 . V_111 . V_112 |= V_115 ;
}
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
#ifndef F_48
F_28 ( V_1 , V_80 -> V_43 ) ;
#endif
return 0 ;
}
static int F_58 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
unsigned int V_81 = 0 ;
V_1 -> V_116 = F_41 ( V_56 ) ;
V_1 -> V_117 = F_42 ( V_56 ) ;
if ( F_43 ( V_80 -> V_84 ) == 16 )
V_81 |= 0x02 ;
if ( V_80 -> V_85 > 1 )
V_81 |= 0x01 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_76 &= ~ V_75 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( F_46 ( V_118 ) , F_3 ( V_1 , V_88 ) ) ;
F_8 ( V_80 -> V_89 , F_3 ( V_1 , V_119 ) ) ;
F_8 ( ( V_1 -> V_116 >> 2 ) - 1 , F_3 ( V_1 , V_120 ) ) ;
V_1 -> V_69 &= ~ ( V_121 | V_122 ) ;
V_1 -> V_69 |= V_123 | F_59 ( V_81 ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( ( V_1 -> V_117 >> V_96 [ V_81 ] ) - 1 ,
F_3 ( V_1 , V_124 ) ) ;
#ifdef F_48
if ( ! ( V_1 -> V_110 . V_111 . V_112 & V_115 ) ) {
V_1 -> V_76 &= ~ V_114 ;
V_1 -> V_76 |= F_56 ( F_57 ( V_80 -> V_43 ) ) ;
V_1 -> V_110 . V_111 . V_112 |= V_113 ;
}
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
#ifndef F_48
F_26 ( V_1 , V_80 -> V_43 ) ;
#endif
return 0 ;
}
static T_1 F_60 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
T_2 V_125 ;
F_33 ( & V_1 -> V_68 ) ;
if ( F_2 ( F_3 ( V_1 , V_39 ) ) & V_73 ) {
F_8 ( F_46 ( V_87 ) , F_3 ( V_1 , V_88 ) ) ;
V_125 = F_61 ( F_2 ( F_3 ( V_1 , V_91 ) ) ) ;
V_125 = F_62 ( V_56 -> V_80 , V_125 ) ;
} else {
V_125 = 0 ;
}
F_34 ( & V_1 -> V_68 ) ;
return V_125 ;
}
static T_1 F_63 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
T_2 V_125 ;
F_33 ( & V_1 -> V_68 ) ;
if ( F_2 ( F_3 ( V_1 , V_39 ) ) & V_74 ) {
F_8 ( F_46 ( V_87 ) , F_3 ( V_1 , V_88 ) ) ;
V_125 = F_61 ( F_2 ( F_3 ( V_1 , V_102 ) ) ) ;
V_125 = F_62 ( V_56 -> V_80 , V_125 ) ;
} else {
V_125 = 0 ;
}
F_34 ( & V_1 -> V_68 ) ;
return V_125 ;
}
static T_1 F_64 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
T_2 V_125 ;
F_33 ( & V_1 -> V_68 ) ;
if ( F_2 ( F_3 ( V_1 , V_39 ) ) & V_75 ) {
F_8 ( F_46 ( V_118 ) , F_3 ( V_1 , V_88 ) ) ;
V_125 = F_61 ( F_2 ( F_3 ( V_1 , V_120 ) ) ) ;
V_125 = F_62 ( V_56 -> V_80 , V_125 ) ;
} else {
V_125 = 0 ;
}
F_34 ( & V_1 -> V_68 ) ;
return V_125 ;
}
static int F_65 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
V_1 -> V_81 |= V_126 ;
V_1 -> V_62 = V_56 ;
V_80 -> V_127 = V_128 ;
F_66 ( V_56 ) ;
F_44 ( & V_1 -> V_68 ) ;
if ( V_1 -> V_129 && V_1 -> V_64 == NULL )
V_1 -> V_130 = V_1 -> V_131 ;
F_51 ( & V_1 -> V_68 ) ;
#ifdef F_48
F_67 ( V_80 , 0 , V_132 ,
& V_133 ) ;
#else
F_68 ( V_80 , 0 , V_132 ,
& V_134 ) ;
#endif
return 0 ;
}
static int F_69 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
V_1 -> V_81 |= V_115 ;
V_1 -> V_64 = V_56 ;
V_80 -> V_127 = V_135 ;
F_66 ( V_56 ) ;
F_44 ( & V_1 -> V_68 ) ;
if ( V_1 -> V_129 && V_1 -> V_62 == NULL )
V_1 -> V_130 = V_1 -> V_131 ;
F_51 ( & V_1 -> V_68 ) ;
#ifdef F_48
F_70 ( V_80 , 0 , V_132 ,
& V_136 ) ;
#else
F_68 ( V_80 , 0 , V_132 ,
& V_134 ) ;
#endif
return 0 ;
}
static int F_71 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
struct V_79 * V_80 = V_56 -> V_80 ;
V_1 -> V_81 |= V_113 ;
V_1 -> V_66 = V_56 ;
V_80 -> V_127 = V_137 ;
F_66 ( V_56 ) ;
#ifdef F_48
F_70 ( V_80 , 0 , V_132 ,
& V_136 ) ;
#else
F_70 ( V_80 , 0 , V_132 ,
& V_138 ) ;
#endif
return 0 ;
}
static int F_72 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
V_1 -> V_62 = NULL ;
V_1 -> V_81 &= ~ V_126 ;
return 0 ;
}
static int F_73 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
V_1 -> V_64 = NULL ;
F_44 ( & V_1 -> V_68 ) ;
#ifdef F_48
V_1 -> V_110 . V_111 . V_112 &= ~ V_115 ;
#endif
V_1 -> V_81 &= ~ V_115 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_74 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_30 ( V_56 ) ;
V_1 -> V_66 = NULL ;
F_44 ( & V_1 -> V_68 ) ;
#ifdef F_48
V_1 -> V_110 . V_111 . V_112 &= ~ V_113 ;
#endif
V_1 -> V_81 &= ~ V_113 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_1 , int V_28 ,
struct V_139 * * V_140 )
{
struct V_139 * V_141 ;
int V_142 ;
if ( V_140 )
* V_140 = NULL ;
V_142 = F_76 ( V_1 -> V_6 , V_143 L_6 , V_28 , 1 , 1 , & V_141 ) ;
if ( V_142 < 0 )
return V_142 ;
#ifdef F_48
F_77 ( V_141 , V_144 , & V_145 ) ;
#else
F_77 ( V_141 , V_144 , & V_146 ) ;
#endif
F_77 ( V_141 , V_147 , & V_148 ) ;
V_141 -> V_21 = V_1 ;
V_141 -> V_149 = 0 ;
strcpy ( V_141 -> V_150 , V_143 L_7 ) ;
V_1 -> V_151 = V_141 ;
F_78 ( V_141 , V_152 ,
F_79 ( V_1 -> V_27 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_142 = F_80 ( V_141 , V_144 ,
V_153 , 2 , 0 , NULL ) ;
#else
V_142 = F_80 ( V_141 , V_144 ,
V_154 , 2 , 0 , NULL ) ;
#endif
if ( V_142 < 0 )
return V_142 ;
if ( V_140 )
* V_140 = V_141 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 , int V_28 ,
struct V_139 * * V_140 )
{
struct V_139 * V_141 ;
int V_142 ;
if ( V_140 )
* V_140 = NULL ;
V_142 = F_76 ( V_1 -> V_6 , V_143 L_8 , V_28 , 1 , 0 , & V_141 ) ;
if ( V_142 < 0 )
return V_142 ;
#ifdef F_48
F_77 ( V_141 , V_144 , & V_146 ) ;
#else
F_77 ( V_141 , V_144 , & V_145 ) ;
#endif
V_141 -> V_21 = V_1 ;
V_141 -> V_149 = 0 ;
strcpy ( V_141 -> V_150 , V_143 L_9 ) ;
V_1 -> V_155 = V_141 ;
F_78 ( V_141 , V_152 ,
F_79 ( V_1 -> V_27 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_142 = F_80 ( V_141 , V_144 ,
V_154 , 2 , 0 , NULL ) ;
#else
V_142 = F_80 ( V_141 , V_144 ,
V_153 , 2 , 0 , NULL ) ;
#endif
if ( V_142 < 0 )
return V_142 ;
if ( V_140 )
* V_140 = V_141 ;
return 0 ;
}
static int F_82 ( struct V_156 * V_157 ,
struct V_158 * V_159 )
{
V_159 -> type = V_160 ;
V_159 -> V_161 = 1 ;
return 0 ;
}
static int F_83 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_163 -> V_164 . V_165 . V_166 [ 0 ] = ( V_1 -> V_131 >> 0 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 1 ] = ( V_1 -> V_131 >> 8 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 2 ] = ( V_1 -> V_131 >> 16 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 3 ] = ( V_1 -> V_131 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_85 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_20 ;
int V_167 ;
V_20 = ( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 0 ] << 0 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 1 ] << 8 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 2 ] << 16 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_167 = V_1 -> V_131 != V_20 ;
V_1 -> V_131 = V_20 ;
if ( V_167 && V_1 -> V_62 == NULL &&
V_1 -> V_64 == NULL )
F_8 ( V_20 , F_3 ( V_1 , V_169 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_167 ;
}
static int F_86 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
V_163 -> V_164 . V_165 . V_166 [ 0 ] = 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 1 ] = 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 2 ] = 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 3 ] = 0xff ;
return 0 ;
}
static int F_87 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_163 -> V_164 . V_165 . V_166 [ 0 ] = ( V_1 -> V_130 >> 0 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 1 ] = ( V_1 -> V_130 >> 8 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 2 ] = ( V_1 -> V_130 >> 16 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 3 ] = ( V_1 -> V_130 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_88 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_20 ;
int V_167 ;
V_20 = ( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 0 ] << 0 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 1 ] << 8 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 2 ] << 16 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_167 = V_1 -> V_130 != V_20 ;
V_1 -> V_130 = V_20 ;
if ( V_167 && ( V_1 -> V_62 != NULL ||
V_1 -> V_64 != NULL ) )
F_8 ( V_20 , F_3 ( V_1 , V_169 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_167 ;
}
static int F_89 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_1 -> V_76 & V_170 ? 1 : 0 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_90 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_171 , V_172 ;
int V_167 ;
V_171 = V_163 -> V_164 . integer . V_164 [ 0 ] ? V_170 : 0 ;
V_172 = V_163 -> V_164 . integer . V_164 [ 0 ] ? V_173 : 0 ;
F_44 ( & V_1 -> V_68 ) ;
V_167 = ( V_1 -> V_76 & V_170 ) != V_171 ;
V_1 -> V_76 &= ~ V_170 ;
V_1 -> V_76 |= V_171 ;
V_1 -> V_174 &= ~ V_173 ;
V_1 -> V_174 |= V_172 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_25 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_167 ;
}
static int F_91 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_20 = 0 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ( V_1 -> V_174 & ( V_175 | V_176 |
V_177 ) ) == V_176 )
V_20 = 1 ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_20 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_92 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_171 ;
int V_167 ;
V_171 = V_163 -> V_164 . integer . V_164 [ 0 ] ?
V_176 : ( V_175 | V_177 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_167 = ( V_1 -> V_174 & ( V_175 |
V_176 | V_177 ) ) != V_171 ;
V_1 -> V_174 &= ~ ( V_175 | V_176 | V_177 ) ;
V_1 -> V_174 |= V_171 ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_25 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_167 ;
}
static int F_93 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_20 = 0 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ( V_1 -> V_76 & V_178 ) >= 4 )
V_20 = 1 ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_20 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_94 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_179 ;
unsigned int V_76 ;
F_44 ( & V_1 -> V_68 ) ;
V_76 = V_1 -> V_76 ;
if ( V_163 -> V_164 . integer . V_164 [ 0 ] )
V_1 -> V_76 |= F_95 ( 4 ) ;
else
V_1 -> V_76 &= ~ F_95 ( 4 ) ;
V_179 = ( V_76 != V_1 -> V_76 ) ;
if ( V_179 )
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_179 ;
}
static void F_96 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_21 ;
V_1 -> V_110 . V_180 . V_30 = NULL ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_181 * V_182 )
{
while ( V_182 -> V_183 != ( unsigned short ) V_184 ) {
if ( V_1 -> V_27 -> V_185 == V_182 -> V_183 &&
V_1 -> V_27 -> V_28 == V_182 -> V_186 &&
V_1 -> V_187 == V_182 -> V_187 )
return 1 ;
V_182 ++ ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_1 ,
int V_188 , int V_189 )
{
struct V_190 * V_6 = V_1 -> V_6 ;
struct V_191 * V_192 ;
struct V_193 V_30 ;
int V_142 ;
static struct V_194 V_195 = {
. V_196 = F_17 ,
. V_197 = F_21 ,
. V_198 = F_24 ,
} ;
if ( ( V_142 = V_191 ( V_6 , 0 , & V_195 , NULL , & V_192 ) ) < 0 )
return V_142 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_21 = V_1 ;
V_30 . V_199 = F_96 ;
V_30 . V_27 = V_1 -> V_27 ;
V_30 . V_200 = V_201 ;
if ( ( V_142 = F_99 ( V_192 , & V_30 , & V_1 -> V_110 . V_180 . V_30 ) ) < 0 )
return V_142 ;
if ( V_188 > 0 ||
( ! V_188 && F_97 ( V_1 , V_202 ) ) ) {
struct V_156 * V_203 ;
int V_10 , V_204 = 0 ;
V_1 -> V_131 = V_1 -> V_130 =
V_205 ;
F_8 ( V_1 -> V_131 , F_3 ( V_1 , V_169 ) ) ;
if ( V_1 -> V_110 . V_180 . V_30 -> V_206 & V_207 )
V_204 ++ ;
for ( V_10 = 0 ; V_10 < F_100 ( V_208 ) ; V_10 ++ ) {
V_203 = F_101 ( & V_208 [ V_10 ] , V_1 ) ;
if ( ! V_203 )
return - V_209 ;
V_203 -> V_210 . V_211 = V_204 ;
V_142 = F_102 ( V_6 , V_203 ) ;
if ( V_142 < 0 )
return V_142 ;
}
}
if ( V_1 -> V_110 . V_180 . V_30 -> V_206 & V_212 ) {
V_1 -> V_174 &= ~ ( V_175 | V_177 ) ;
V_1 -> V_174 |= V_176 ;
V_142 = F_102 ( V_6 , F_101 ( & V_213 , V_1 ) ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_189 > 0 ||
F_103 ( V_1 -> V_27 , V_214 ) ) {
V_142 = F_102 ( V_6 , F_101 ( & V_215 ,
V_1 ) ) ;
if ( V_142 < 0 )
return V_142 ;
}
return 0 ;
}
static int F_104 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_216 = V_157 -> V_217 ;
F_44 ( & V_1 -> V_68 ) ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_1 -> V_76 & V_216 ? 1 : 0 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_105 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_216 = V_157 -> V_217 ;
unsigned int V_218 ;
int V_167 ;
V_218 = V_163 -> V_164 . integer . V_164 [ 0 ] ? V_216 : 0 ;
F_44 ( & V_1 -> V_68 ) ;
V_167 = ( V_1 -> V_76 & V_216 ) != V_218 ;
V_1 -> V_76 &= ~ V_216 ;
V_1 -> V_76 |= V_218 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_167 ;
}
static void F_106 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_21 ;
V_1 -> V_110 . V_111 . V_19 = NULL ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_190 * V_6 = V_1 -> V_6 ;
struct V_18 V_19 ;
unsigned int V_219 ;
int V_142 ;
F_12 ( F_13 ( V_220 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_220 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_196 = F_11 ;
V_19 . V_21 = V_1 ;
V_19 . V_199 = F_106 ;
if ( ( V_142 = F_110 ( V_6 , & V_19 , & V_1 -> V_110 . V_111 . V_19 ) ) < 0 )
return V_142 ;
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
V_142 = F_102 ( V_6 , F_101 ( & V_222 [ V_219 ] , V_1 ) ) ;
if ( V_142 < 0 )
return V_142 ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_1 , int V_7 )
{
switch ( V_223 [ V_7 ] ) {
case 0 :
case 1 :
case 0x200 :
case 0x208 :
case 0x210 :
case 0x218 :
return V_223 [ V_7 ] ;
default:
F_5 ( V_1 -> V_6 -> V_7 ,
L_10 , V_223 [ V_7 ] ) ;
return 0 ;
}
}
static int F_111 ( struct V_1 * V_1 , int V_7 )
{
return V_224 [ V_7 ] ? 0x200 : 0 ;
}
static int F_112 ( struct V_1 * V_1 , int V_7 )
{
struct V_225 * V_226 ;
int V_227 ;
V_227 = F_111 ( V_1 , V_7 ) ;
switch ( V_227 ) {
case 0 :
return - V_228 ;
case 1 :
for ( V_227 = 0x200 ; V_227 <= 0x218 ; V_227 += 8 )
if ( F_113 ( V_227 , 8 , L_11 ) )
break;
if ( V_227 > 0x218 ) {
F_114 ( V_1 -> V_6 -> V_7 ,
L_12 ) ;
return - V_229 ;
}
break;
default:
if ( ! F_113 ( V_227 , 8 , L_11 ) ) {
F_114 ( V_1 -> V_6 -> V_7 ,
L_13 ,
V_227 ) ;
return - V_229 ;
}
break;
}
V_1 -> V_225 = V_226 = F_115 () ;
if ( ! V_226 ) {
F_5 ( V_1 -> V_6 -> V_7 ,
L_14 ) ;
F_116 ( V_227 , 8 ) ;
return - V_209 ;
}
F_117 ( V_226 , L_15 ) ;
F_118 ( V_226 , L_16 , F_119 ( V_1 -> V_27 ) ) ;
F_120 ( V_226 , & V_1 -> V_27 -> V_7 ) ;
V_226 -> V_230 = V_227 ;
V_1 -> V_76 |= V_231 ;
#ifdef F_45
V_1 -> V_76 &= ~ V_232 ;
V_1 -> V_76 |= F_121 ( ( V_227 - 0x200 ) / 8 ) ;
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_122 ( V_1 -> V_225 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_1 )
{
if ( V_1 -> V_225 ) {
int V_233 = V_1 -> V_225 -> V_230 ;
F_124 ( V_1 -> V_225 ) ;
V_1 -> V_225 = NULL ;
V_1 -> V_76 &= ~ V_231 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_116 ( V_233 , 8 ) ;
}
}
static inline int F_112 ( struct V_1 * V_1 , long V_233 ) { return - V_228 ; }
static inline void F_123 ( struct V_1 * V_1 ) { }
static void F_125 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_1 * V_1 = V_235 -> V_21 ;
F_126 ( V_237 , L_17 V_143 L_18 ) ;
F_126 ( V_237 , L_19 ,
V_1 -> V_76 & V_231 ? L_20 : L_21 ) ;
#ifdef F_48
F_126 ( V_237 , L_22 ,
V_1 -> V_76 & V_238 ? L_20 : L_21 ) ;
F_126 ( V_237 , L_23 ,
V_1 -> V_76 & V_239 ? L_20 : L_21 ) ;
#else
F_126 ( V_237 , L_24 ,
( F_127 ( V_1 -> V_76 ) * 8 ) + 0x200 ) ;
#endif
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_234 * V_235 ;
if ( ! F_129 ( V_1 -> V_6 , L_25 , & V_235 ) )
F_130 ( V_235 , V_1 , F_125 ) ;
}
static int F_131 ( struct V_1 * V_1 )
{
F_123 ( V_1 ) ;
if ( V_1 -> V_240 < 0 )
goto V_241;
#ifdef F_48
F_8 ( V_242 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_70 ) ) ;
#else
F_8 ( 0 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_70 ) ) ;
#endif
if ( V_1 -> V_240 >= 0 )
F_132 ( V_1 -> V_240 ) ;
F_133 ( V_1 -> V_27 , V_243 ) ;
V_241:
#ifdef F_48
if ( V_1 -> V_244 . V_245 )
F_134 ( & V_1 -> V_244 ) ;
#endif
if ( V_1 -> V_240 >= 0 )
F_135 ( V_1 -> V_240 , V_1 ) ;
F_136 ( V_1 -> V_27 ) ;
F_137 ( V_1 -> V_27 ) ;
F_138 ( V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_246 * V_28 )
{
struct V_1 * V_1 = V_28 -> V_247 ;
return F_131 ( V_1 ) ;
}
static void F_140 ( struct V_1 * V_1 )
{
#ifdef F_45
int V_219 ;
#endif
#ifdef F_48
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( F_46 ( V_118 ) , F_3 ( V_1 , V_88 ) ) ;
F_8 ( V_1 -> V_244 . V_248 , F_3 ( V_1 , V_249 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_250 ) ) ;
#else
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_LEGACY ) ) ;
if ( F_97 ( V_1 , V_251 ) ) {
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_25 ) ) ;
F_25 ( 20 ) ;
}
F_8 ( V_1 -> V_76 | V_252 , F_3 ( V_1 , V_39 ) ) ;
F_2 ( F_3 ( V_1 , V_39 ) ) ;
F_109 ( 20 ) ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_12 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_219 = 0 ; V_219 < 0x80 ; V_219 ++ )
F_9 ( V_1 , V_219 , 0 ) ;
F_9 ( V_1 , V_53 + V_49 , 16 << 4 ) ;
F_9 ( V_1 , V_53 + V_50 , 16 << 10 ) ;
F_9 ( V_1 , V_54 + V_49 , 16 << 4 ) ;
F_9 ( V_1 , V_54 + V_50 , 16 << 10 ) ;
F_9 ( V_1 , V_52 , 1 << 12 ) ;
F_9 ( V_1 , V_52 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_253 , 1 << 12 ) ;
F_9 ( V_1 , V_253 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_254 , 1 << 12 ) ;
F_9 ( V_1 , V_254 + 1 , 1 << 12 ) ;
F_26 ( V_1 , 22050 ) ;
F_27 ( V_1 , 22050 ) ;
F_28 ( V_1 , 22050 ) ;
F_1 ( V_1 ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_8 ( F_19 ( 0 , 0 ) , F_3 ( V_1 , 1371_CODEC ) ) ;
#endif
F_141 ( V_1 -> V_255 = 0x00 , F_3 ( V_1 , V_256 ) ) ;
F_141 ( 0x00 , F_3 ( V_1 , V_257 ) ) ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_25 ) ) ;
F_132 ( V_1 -> V_240 ) ;
}
static int F_142 ( struct V_28 * V_7 )
{
struct V_258 * V_27 = F_143 ( V_7 ) ;
struct V_190 * V_6 = F_144 ( V_7 ) ;
struct V_1 * V_1 = V_6 -> V_21 ;
F_145 ( V_6 , V_259 ) ;
F_146 ( V_1 -> V_151 ) ;
F_146 ( V_1 -> V_155 ) ;
#ifdef F_45
F_147 ( V_1 -> V_110 . V_180 . V_30 ) ;
#else
F_12 ( F_13 ( V_220 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_220 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_148 ( V_1 -> V_110 . V_111 . V_19 ) ;
#endif
F_137 ( V_27 ) ;
F_149 ( V_27 ) ;
F_133 ( V_27 , V_243 ) ;
return 0 ;
}
static int F_150 ( struct V_28 * V_7 )
{
struct V_258 * V_27 = F_143 ( V_7 ) ;
struct V_190 * V_6 = F_144 ( V_7 ) ;
struct V_1 * V_1 = V_6 -> V_21 ;
F_133 ( V_27 , V_260 ) ;
F_151 ( V_27 ) ;
if ( F_152 ( V_27 ) < 0 ) {
F_5 ( V_7 , L_26 ) ;
F_153 ( V_6 ) ;
return - V_261 ;
}
F_154 ( V_27 ) ;
F_140 ( V_1 ) ;
#ifdef F_45
F_155 ( V_1 -> V_110 . V_180 . V_30 ) ;
#else
F_156 ( V_1 -> V_110 . V_111 . V_19 ) ;
#endif
F_145 ( V_6 , V_262 ) ;
return 0 ;
}
static int F_157 ( struct V_190 * V_6 ,
struct V_258 * V_27 ,
struct V_1 * * V_263 )
{
struct V_1 * V_1 ;
int V_142 ;
static struct V_264 V_195 = {
. V_265 = F_139 ,
} ;
* V_263 = NULL ;
if ( ( V_142 = F_152 ( V_27 ) ) < 0 )
return V_142 ;
V_1 = F_158 ( sizeof( * V_1 ) , V_266 ) ;
if ( V_1 == NULL ) {
F_137 ( V_27 ) ;
return - V_209 ;
}
F_159 ( & V_1 -> V_68 ) ;
F_160 ( & V_1 -> V_34 ) ;
V_1 -> V_6 = V_6 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_240 = - 1 ;
if ( ( V_142 = F_161 ( V_27 , L_27 ) ) < 0 ) {
F_138 ( V_1 ) ;
F_137 ( V_27 ) ;
return V_142 ;
}
V_1 -> V_233 = F_162 ( V_27 , 0 ) ;
if ( F_163 ( V_27 -> V_240 , V_267 , V_268 ,
V_269 , V_1 ) ) {
F_5 ( V_6 -> V_7 , L_28 , V_27 -> V_240 ) ;
F_131 ( V_1 ) ;
return - V_229 ;
}
V_1 -> V_240 = V_27 -> V_240 ;
#ifdef F_48
if ( F_164 ( V_152 , F_79 ( V_27 ) ,
16 , & V_1 -> V_244 ) < 0 ) {
F_5 ( V_6 -> V_7 , L_29 ) ;
F_131 ( V_1 ) ;
return - V_229 ;
}
#endif
F_154 ( V_27 ) ;
V_1 -> V_187 = V_27 -> V_270 ;
#ifdef F_48
#if 0
ensoniq->ctrl = ES_1370_CDC_EN | ES_1370_SERR_DISABLE |
ES_1370_PCLKDIVO(ES_1370_SRTODIV(8000));
#else
V_1 -> V_76 = V_271 | F_56 ( F_57 ( 8000 ) ) ;
#endif
V_1 -> V_69 = 0 ;
#else
V_1 -> V_76 = 0 ;
V_1 -> V_69 = 0 ;
V_1 -> V_174 = 0 ;
if ( F_103 ( V_27 , V_272 ) )
V_1 -> V_76 |= F_95 ( 1 ) ;
if ( F_97 ( V_1 , V_251 ) )
V_1 -> V_174 |= V_273 ;
#endif
F_140 ( V_1 ) ;
if ( ( V_142 = F_165 ( V_6 , V_274 , V_1 , & V_195 ) ) < 0 ) {
F_131 ( V_1 ) ;
return V_142 ;
}
F_128 ( V_1 ) ;
* V_263 = V_1 ;
return 0 ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_275 * V_276 = V_1 -> V_276 ;
unsigned char V_166 , V_216 , V_277 ;
if ( V_276 == NULL )
return;
F_33 ( & V_1 -> V_68 ) ;
V_216 = V_1 -> V_278 & V_279 ? V_280 : 0 ;
while ( V_216 ) {
V_166 = F_167 ( F_3 ( V_1 , V_281 ) ) ;
if ( ( V_166 & V_216 ) == 0 )
break;
V_277 = F_167 ( F_3 ( V_1 , V_282 ) ) ;
F_168 ( V_1 -> V_283 , & V_277 , 1 ) ;
}
F_34 ( & V_1 -> V_68 ) ;
F_33 ( & V_1 -> V_68 ) ;
V_216 = V_1 -> V_278 & V_284 ? V_285 : 0 ;
while ( V_216 ) {
V_166 = F_167 ( F_3 ( V_1 , V_281 ) ) ;
if ( ( V_166 & V_216 ) == 0 )
break;
if ( F_169 ( V_1 -> V_286 , & V_277 , 1 ) != 1 ) {
V_1 -> V_255 &= ~ V_287 ;
F_141 ( V_1 -> V_255 , F_3 ( V_1 , V_256 ) ) ;
V_216 &= ~ V_285 ;
} else {
F_141 ( V_277 , F_3 ( V_1 , V_282 ) ) ;
}
}
F_34 ( & V_1 -> V_68 ) ;
}
static int F_170 ( struct V_288 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_278 |= V_279 ;
V_1 -> V_283 = V_56 ;
if ( ! ( V_1 -> V_278 & V_284 ) ) {
F_141 ( F_171 ( 3 ) , F_3 ( V_1 , V_256 ) ) ;
F_141 ( V_1 -> V_255 = 0 , F_3 ( V_1 , V_256 ) ) ;
F_8 ( V_1 -> V_76 |= V_289 , F_3 ( V_1 , V_39 ) ) ;
}
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_172 ( struct V_288 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ! ( V_1 -> V_278 & V_284 ) ) {
F_141 ( V_1 -> V_255 = 0 , F_3 ( V_1 , V_256 ) ) ;
F_8 ( V_1 -> V_76 &= ~ V_289 , F_3 ( V_1 , V_39 ) ) ;
} else {
F_141 ( V_1 -> V_255 &= ~ V_290 , F_3 ( V_1 , V_256 ) ) ;
}
V_1 -> V_283 = NULL ;
V_1 -> V_278 &= ~ V_279 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_173 ( struct V_288 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_278 |= V_284 ;
V_1 -> V_286 = V_56 ;
if ( ! ( V_1 -> V_278 & V_279 ) ) {
F_141 ( F_171 ( 3 ) , F_3 ( V_1 , V_256 ) ) ;
F_141 ( V_1 -> V_255 = 0 , F_3 ( V_1 , V_256 ) ) ;
F_8 ( V_1 -> V_76 |= V_289 , F_3 ( V_1 , V_39 ) ) ;
}
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_174 ( struct V_288 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ! ( V_1 -> V_278 & V_279 ) ) {
F_141 ( V_1 -> V_255 = 0 , F_3 ( V_1 , V_256 ) ) ;
F_8 ( V_1 -> V_76 &= ~ V_289 , F_3 ( V_1 , V_39 ) ) ;
} else {
F_141 ( V_1 -> V_255 &= ~ V_287 , F_3 ( V_1 , V_256 ) ) ;
}
V_1 -> V_286 = NULL ;
V_1 -> V_278 &= ~ V_284 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static void F_175 ( struct V_288 * V_56 , int V_291 )
{
unsigned long V_292 ;
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
int V_219 ;
F_176 ( & V_1 -> V_68 , V_292 ) ;
if ( V_291 ) {
if ( ( V_1 -> V_255 & V_290 ) == 0 ) {
for ( V_219 = 0 ; V_219 < 32 ; V_219 ++ )
F_167 ( F_3 ( V_1 , V_282 ) ) ;
V_1 -> V_255 |= V_290 ;
F_141 ( V_1 -> V_255 , F_3 ( V_1 , V_256 ) ) ;
}
} else {
if ( V_1 -> V_255 & V_290 ) {
V_1 -> V_255 &= ~ V_290 ;
F_141 ( V_1 -> V_255 , F_3 ( V_1 , V_256 ) ) ;
}
}
F_177 ( & V_1 -> V_68 , V_292 ) ;
}
static void F_178 ( struct V_288 * V_56 , int V_291 )
{
unsigned long V_292 ;
struct V_1 * V_1 = V_56 -> V_276 -> V_21 ;
unsigned char V_277 ;
F_176 ( & V_1 -> V_68 , V_292 ) ;
if ( V_291 ) {
if ( F_179 ( V_1 -> V_255 ) == 0 ) {
V_1 -> V_255 |= F_180 ( 1 ) ;
while ( F_179 ( V_1 -> V_255 ) == 1 &&
( F_167 ( F_3 ( V_1 , V_281 ) ) & V_285 ) ) {
if ( F_169 ( V_56 , & V_277 , 1 ) != 1 ) {
V_1 -> V_255 &= ~ V_287 ;
} else {
F_141 ( V_277 , F_3 ( V_1 , V_282 ) ) ;
}
}
F_141 ( V_1 -> V_255 , F_3 ( V_1 , V_256 ) ) ;
}
} else {
if ( F_179 ( V_1 -> V_255 ) == 1 ) {
V_1 -> V_255 &= ~ V_287 ;
F_141 ( V_1 -> V_255 , F_3 ( V_1 , V_256 ) ) ;
}
}
F_177 ( & V_1 -> V_68 , V_292 ) ;
}
static int F_181 ( struct V_1 * V_1 , int V_28 ,
struct V_275 * * V_293 )
{
struct V_275 * V_276 ;
int V_142 ;
if ( V_293 )
* V_293 = NULL ;
if ( ( V_142 = F_182 ( V_1 -> V_6 , L_30 , V_28 , 1 , 1 , & V_276 ) ) < 0 )
return V_142 ;
strcpy ( V_276 -> V_150 , V_143 ) ;
F_183 ( V_276 , V_294 , & V_295 ) ;
F_183 ( V_276 , V_296 , & V_297 ) ;
V_276 -> V_149 |= V_298 | V_299 |
V_300 ;
V_276 -> V_21 = V_1 ;
V_1 -> V_276 = V_276 ;
if ( V_293 )
* V_293 = V_276 ;
return 0 ;
}
static T_3 V_267 ( int V_240 , void * V_301 )
{
struct V_1 * V_1 = V_301 ;
unsigned int V_166 , V_69 ;
if ( V_1 == NULL )
return V_302 ;
V_166 = F_2 ( F_3 ( V_1 , V_25 ) ) ;
if ( ! ( V_166 & V_303 ) )
return V_302 ;
F_33 ( & V_1 -> V_68 ) ;
V_69 = V_1 -> V_69 ;
if ( V_166 & V_304 )
V_69 &= ~ V_95 ;
if ( V_166 & V_305 )
V_69 &= ~ V_108 ;
if ( V_166 & V_306 )
V_69 &= ~ V_123 ;
F_8 ( V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_34 ( & V_1 -> V_68 ) ;
if ( V_166 & V_307 )
F_166 ( V_1 ) ;
if ( ( V_166 & V_305 ) && V_1 -> V_64 )
F_184 ( V_1 -> V_64 ) ;
if ( ( V_166 & V_306 ) && V_1 -> V_66 )
F_184 ( V_1 -> V_66 ) ;
if ( ( V_166 & V_304 ) && V_1 -> V_62 )
F_184 ( V_1 -> V_62 ) ;
return V_308 ;
}
static int F_185 ( struct V_258 * V_27 ,
const struct V_309 * V_310 )
{
static int V_7 ;
struct V_190 * V_6 ;
struct V_1 * V_1 ;
int V_142 , V_311 [ 2 ] ;
if ( V_7 >= V_312 )
return - V_313 ;
if ( ! V_314 [ V_7 ] ) {
V_7 ++ ;
return - V_315 ;
}
V_142 = F_186 ( & V_27 -> V_7 , V_211 [ V_7 ] , V_210 [ V_7 ] , V_316 ,
0 , & V_6 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ( V_142 = F_157 ( V_6 , V_27 , & V_1 ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
V_6 -> V_21 = V_1 ;
V_311 [ 0 ] = 0 ; V_311 [ 1 ] = 1 ;
#ifdef F_48
if ( ( V_142 = F_107 ( V_1 ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
#endif
#ifdef F_45
if ( ( V_142 = F_98 ( V_1 , V_129 [ V_7 ] , V_317 [ V_7 ] ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
#endif
if ( ( V_142 = F_75 ( V_1 , 0 , NULL ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
if ( ( V_142 = F_81 ( V_1 , 1 , NULL ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
if ( ( V_142 = F_181 ( V_1 , 0 , NULL ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
F_112 ( V_1 , V_7 ) ;
strcpy ( V_6 -> V_318 , V_319 ) ;
strcpy ( V_6 -> V_320 , L_27 ) ;
sprintf ( V_6 -> V_321 , L_31 ,
V_6 -> V_320 ,
V_6 -> V_318 ,
V_1 -> V_233 ,
V_1 -> V_240 ) ;
if ( ( V_142 = F_188 ( V_6 ) ) < 0 ) {
F_187 ( V_6 ) ;
return V_142 ;
}
F_189 ( V_27 , V_6 ) ;
V_7 ++ ;
return 0 ;
}
static void F_190 ( struct V_258 * V_27 )
{
F_187 ( F_191 ( V_27 ) ) ;
}
