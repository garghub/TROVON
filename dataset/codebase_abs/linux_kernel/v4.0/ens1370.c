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
static int F_75 ( struct V_1 * V_1 , int V_28 )
{
struct V_139 * V_140 ;
int V_141 ;
V_141 = F_76 ( V_1 -> V_6 , V_142 L_6 , V_28 , 1 , 1 , & V_140 ) ;
if ( V_141 < 0 )
return V_141 ;
#ifdef F_48
F_77 ( V_140 , V_143 , & V_144 ) ;
#else
F_77 ( V_140 , V_143 , & V_145 ) ;
#endif
F_77 ( V_140 , V_146 , & V_147 ) ;
V_140 -> V_21 = V_1 ;
V_140 -> V_148 = 0 ;
strcpy ( V_140 -> V_149 , V_142 L_7 ) ;
V_1 -> V_150 = V_140 ;
F_78 ( V_140 , V_151 ,
F_79 ( V_1 -> V_27 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_141 = F_80 ( V_140 , V_143 ,
V_152 , 2 , 0 , NULL ) ;
#else
V_141 = F_80 ( V_140 , V_143 ,
V_153 , 2 , 0 , NULL ) ;
#endif
return V_141 ;
}
static int F_81 ( struct V_1 * V_1 , int V_28 )
{
struct V_139 * V_140 ;
int V_141 ;
V_141 = F_76 ( V_1 -> V_6 , V_142 L_8 , V_28 , 1 , 0 , & V_140 ) ;
if ( V_141 < 0 )
return V_141 ;
#ifdef F_48
F_77 ( V_140 , V_143 , & V_145 ) ;
#else
F_77 ( V_140 , V_143 , & V_144 ) ;
#endif
V_140 -> V_21 = V_1 ;
V_140 -> V_148 = 0 ;
strcpy ( V_140 -> V_149 , V_142 L_9 ) ;
V_1 -> V_154 = V_140 ;
F_78 ( V_140 , V_151 ,
F_79 ( V_1 -> V_27 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_141 = F_80 ( V_140 , V_143 ,
V_153 , 2 , 0 , NULL ) ;
#else
V_141 = F_80 ( V_140 , V_143 ,
V_152 , 2 , 0 , NULL ) ;
#endif
return V_141 ;
}
static int F_82 ( struct V_155 * V_156 ,
struct V_157 * V_158 )
{
V_158 -> type = V_159 ;
V_158 -> V_160 = 1 ;
return 0 ;
}
static int F_83 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_162 -> V_163 . V_164 . V_165 [ 0 ] = ( V_1 -> V_131 >> 0 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 1 ] = ( V_1 -> V_131 >> 8 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 2 ] = ( V_1 -> V_131 >> 16 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 3 ] = ( V_1 -> V_131 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_85 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
unsigned int V_20 ;
int V_166 ;
V_20 = ( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 0 ] << 0 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 1 ] << 8 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 2 ] << 16 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_166 = V_1 -> V_131 != V_20 ;
V_1 -> V_131 = V_20 ;
if ( V_166 && V_1 -> V_62 == NULL &&
V_1 -> V_64 == NULL )
F_8 ( V_20 , F_3 ( V_1 , V_168 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_166 ;
}
static int F_86 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
V_162 -> V_163 . V_164 . V_165 [ 0 ] = 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 1 ] = 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 2 ] = 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 3 ] = 0xff ;
return 0 ;
}
static int F_87 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_162 -> V_163 . V_164 . V_165 [ 0 ] = ( V_1 -> V_130 >> 0 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 1 ] = ( V_1 -> V_130 >> 8 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 2 ] = ( V_1 -> V_130 >> 16 ) & 0xff ;
V_162 -> V_163 . V_164 . V_165 [ 3 ] = ( V_1 -> V_130 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_88 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
unsigned int V_20 ;
int V_166 ;
V_20 = ( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 0 ] << 0 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 1 ] << 8 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 2 ] << 16 ) |
( ( V_167 ) V_162 -> V_163 . V_164 . V_165 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_166 = V_1 -> V_130 != V_20 ;
V_1 -> V_130 = V_20 ;
if ( V_166 && ( V_1 -> V_62 != NULL ||
V_1 -> V_64 != NULL ) )
F_8 ( V_20 , F_3 ( V_1 , V_168 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_166 ;
}
static int F_89 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_162 -> V_163 . integer . V_163 [ 0 ] = V_1 -> V_76 & V_169 ? 1 : 0 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_90 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
unsigned int V_170 , V_171 ;
int V_166 ;
V_170 = V_162 -> V_163 . integer . V_163 [ 0 ] ? V_169 : 0 ;
V_171 = V_162 -> V_163 . integer . V_163 [ 0 ] ? V_172 : 0 ;
F_44 ( & V_1 -> V_68 ) ;
V_166 = ( V_1 -> V_76 & V_169 ) != V_170 ;
V_1 -> V_76 &= ~ V_169 ;
V_1 -> V_76 |= V_170 ;
V_1 -> V_173 &= ~ V_172 ;
V_1 -> V_173 |= V_171 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_173 , F_3 ( V_1 , V_25 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_166 ;
}
static int F_91 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
int V_20 = 0 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ( V_1 -> V_173 & ( V_174 | V_175 |
V_176 ) ) == V_175 )
V_20 = 1 ;
V_162 -> V_163 . integer . V_163 [ 0 ] = V_20 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_92 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
unsigned int V_170 ;
int V_166 ;
V_170 = V_162 -> V_163 . integer . V_163 [ 0 ] ?
V_175 : ( V_174 | V_176 ) ;
F_44 ( & V_1 -> V_68 ) ;
V_166 = ( V_1 -> V_173 & ( V_174 |
V_175 | V_176 ) ) != V_170 ;
V_1 -> V_173 &= ~ ( V_174 | V_175 | V_176 ) ;
V_1 -> V_173 |= V_170 ;
F_8 ( V_1 -> V_173 , F_3 ( V_1 , V_25 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_166 ;
}
static int F_93 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
int V_20 = 0 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ( V_1 -> V_76 & V_177 ) >= 4 )
V_20 = 1 ;
V_162 -> V_163 . integer . V_163 [ 0 ] = V_20 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_94 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
int V_178 ;
unsigned int V_76 ;
F_44 ( & V_1 -> V_68 ) ;
V_76 = V_1 -> V_76 ;
if ( V_162 -> V_163 . integer . V_163 [ 0 ] )
V_1 -> V_76 |= F_95 ( 4 ) ;
else
V_1 -> V_76 &= ~ F_95 ( 4 ) ;
V_178 = ( V_76 != V_1 -> V_76 ) ;
if ( V_178 )
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_178 ;
}
static void F_96 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_21 ;
V_1 -> V_110 . V_179 . V_30 = NULL ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_180 * V_181 )
{
while ( V_181 -> V_182 != ( unsigned short ) V_183 ) {
if ( V_1 -> V_27 -> V_184 == V_181 -> V_182 &&
V_1 -> V_27 -> V_28 == V_181 -> V_185 &&
V_1 -> V_186 == V_181 -> V_186 )
return 1 ;
V_181 ++ ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_1 ,
int V_187 , int V_188 )
{
struct V_189 * V_6 = V_1 -> V_6 ;
struct V_190 * V_191 ;
struct V_192 V_30 ;
int V_141 ;
static struct V_193 V_194 = {
. V_195 = F_17 ,
. V_196 = F_21 ,
. V_197 = F_24 ,
} ;
if ( ( V_141 = V_190 ( V_6 , 0 , & V_194 , NULL , & V_191 ) ) < 0 )
return V_141 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_21 = V_1 ;
V_30 . V_198 = F_96 ;
V_30 . V_27 = V_1 -> V_27 ;
V_30 . V_199 = V_200 ;
if ( ( V_141 = F_99 ( V_191 , & V_30 , & V_1 -> V_110 . V_179 . V_30 ) ) < 0 )
return V_141 ;
if ( V_187 > 0 ||
( ! V_187 && F_97 ( V_1 , V_201 ) ) ) {
struct V_155 * V_202 ;
int V_10 , V_203 = 0 ;
V_1 -> V_131 = V_1 -> V_130 =
V_204 ;
F_8 ( V_1 -> V_131 , F_3 ( V_1 , V_168 ) ) ;
if ( V_1 -> V_110 . V_179 . V_30 -> V_205 & V_206 )
V_203 ++ ;
for ( V_10 = 0 ; V_10 < F_100 ( V_207 ) ; V_10 ++ ) {
V_202 = F_101 ( & V_207 [ V_10 ] , V_1 ) ;
if ( ! V_202 )
return - V_208 ;
V_202 -> V_209 . V_210 = V_203 ;
V_141 = F_102 ( V_6 , V_202 ) ;
if ( V_141 < 0 )
return V_141 ;
}
}
if ( V_1 -> V_110 . V_179 . V_30 -> V_205 & V_211 ) {
V_1 -> V_173 &= ~ ( V_174 | V_176 ) ;
V_1 -> V_173 |= V_175 ;
V_141 = F_102 ( V_6 , F_101 ( & V_212 , V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_188 > 0 ||
F_103 ( V_1 -> V_27 , V_213 ) ) {
V_141 = F_102 ( V_6 , F_101 ( & V_214 ,
V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
return 0 ;
}
static int F_104 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
int V_215 = V_156 -> V_216 ;
F_44 ( & V_1 -> V_68 ) ;
V_162 -> V_163 . integer . V_163 [ 0 ] = V_1 -> V_76 & V_215 ? 1 : 0 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_105 ( struct V_155 * V_156 ,
struct V_161 * V_162 )
{
struct V_1 * V_1 = F_84 ( V_156 ) ;
int V_215 = V_156 -> V_216 ;
unsigned int V_217 ;
int V_166 ;
V_217 = V_162 -> V_163 . integer . V_163 [ 0 ] ? V_215 : 0 ;
F_44 ( & V_1 -> V_68 ) ;
V_166 = ( V_1 -> V_76 & V_215 ) != V_217 ;
V_1 -> V_76 &= ~ V_215 ;
V_1 -> V_76 |= V_217 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_51 ( & V_1 -> V_68 ) ;
return V_166 ;
}
static void F_106 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_21 ;
V_1 -> V_110 . V_111 . V_19 = NULL ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_189 * V_6 = V_1 -> V_6 ;
struct V_18 V_19 ;
unsigned int V_218 ;
int V_141 ;
F_12 ( F_13 ( V_219 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_219 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_195 = F_11 ;
V_19 . V_21 = V_1 ;
V_19 . V_198 = F_106 ;
if ( ( V_141 = F_110 ( V_6 , & V_19 , & V_1 -> V_110 . V_111 . V_19 ) ) < 0 )
return V_141 ;
for ( V_218 = 0 ; V_218 < V_220 ; V_218 ++ ) {
V_141 = F_102 ( V_6 , F_101 ( & V_221 [ V_218 ] , V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_1 , int V_7 )
{
switch ( V_222 [ V_7 ] ) {
case 0 :
case 1 :
case 0x200 :
case 0x208 :
case 0x210 :
case 0x218 :
return V_222 [ V_7 ] ;
default:
F_5 ( V_1 -> V_6 -> V_7 ,
L_10 , V_222 [ V_7 ] ) ;
return 0 ;
}
}
static int F_111 ( struct V_1 * V_1 , int V_7 )
{
return V_223 [ V_7 ] ? 0x200 : 0 ;
}
static int F_112 ( struct V_1 * V_1 , int V_7 )
{
struct V_224 * V_225 ;
int V_226 ;
V_226 = F_111 ( V_1 , V_7 ) ;
switch ( V_226 ) {
case 0 :
return - V_227 ;
case 1 :
for ( V_226 = 0x200 ; V_226 <= 0x218 ; V_226 += 8 )
if ( F_113 ( V_226 , 8 , L_11 ) )
break;
if ( V_226 > 0x218 ) {
F_114 ( V_1 -> V_6 -> V_7 ,
L_12 ) ;
return - V_228 ;
}
break;
default:
if ( ! F_113 ( V_226 , 8 , L_11 ) ) {
F_114 ( V_1 -> V_6 -> V_7 ,
L_13 ,
V_226 ) ;
return - V_228 ;
}
break;
}
V_1 -> V_224 = V_225 = F_115 () ;
if ( ! V_225 ) {
F_5 ( V_1 -> V_6 -> V_7 ,
L_14 ) ;
F_116 ( V_226 , 8 ) ;
return - V_208 ;
}
F_117 ( V_225 , L_15 ) ;
F_118 ( V_225 , L_16 , F_119 ( V_1 -> V_27 ) ) ;
F_120 ( V_225 , & V_1 -> V_27 -> V_7 ) ;
V_225 -> V_229 = V_226 ;
V_1 -> V_76 |= V_230 ;
#ifdef F_45
V_1 -> V_76 &= ~ V_231 ;
V_1 -> V_76 |= F_121 ( ( V_226 - 0x200 ) / 8 ) ;
#endif
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_122 ( V_1 -> V_224 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_1 )
{
if ( V_1 -> V_224 ) {
int V_232 = V_1 -> V_224 -> V_229 ;
F_124 ( V_1 -> V_224 ) ;
V_1 -> V_224 = NULL ;
V_1 -> V_76 &= ~ V_230 ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_116 ( V_232 , 8 ) ;
}
}
static inline int F_112 ( struct V_1 * V_1 , long V_232 ) { return - V_227 ; }
static inline void F_123 ( struct V_1 * V_1 ) { }
static void F_125 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
struct V_1 * V_1 = V_234 -> V_21 ;
F_126 ( V_236 , L_17 V_142 L_18 ) ;
F_126 ( V_236 , L_19 ,
V_1 -> V_76 & V_230 ? L_20 : L_21 ) ;
#ifdef F_48
F_126 ( V_236 , L_22 ,
V_1 -> V_76 & V_237 ? L_20 : L_21 ) ;
F_126 ( V_236 , L_23 ,
V_1 -> V_76 & V_238 ? L_20 : L_21 ) ;
#else
F_126 ( V_236 , L_24 ,
( F_127 ( V_1 -> V_76 ) * 8 ) + 0x200 ) ;
#endif
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_233 * V_234 ;
if ( ! F_129 ( V_1 -> V_6 , L_25 , & V_234 ) )
F_130 ( V_234 , V_1 , F_125 ) ;
}
static int F_131 ( struct V_1 * V_1 )
{
F_123 ( V_1 ) ;
if ( V_1 -> V_239 < 0 )
goto V_240;
#ifdef F_48
F_8 ( V_241 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_70 ) ) ;
#else
F_8 ( 0 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_70 ) ) ;
#endif
if ( V_1 -> V_239 >= 0 )
F_132 ( V_1 -> V_239 ) ;
F_133 ( V_1 -> V_27 , V_242 ) ;
V_240:
#ifdef F_48
if ( V_1 -> V_243 . V_244 )
F_134 ( & V_1 -> V_243 ) ;
#endif
if ( V_1 -> V_239 >= 0 )
F_135 ( V_1 -> V_239 , V_1 ) ;
F_136 ( V_1 -> V_27 ) ;
F_137 ( V_1 -> V_27 ) ;
F_138 ( V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_245 * V_28 )
{
struct V_1 * V_1 = V_28 -> V_246 ;
return F_131 ( V_1 ) ;
}
static void F_140 ( struct V_1 * V_1 )
{
#ifdef F_45
int V_218 ;
#endif
#ifdef F_48
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( F_46 ( V_118 ) , F_3 ( V_1 , V_88 ) ) ;
F_8 ( V_1 -> V_243 . V_247 , F_3 ( V_1 , V_248 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_249 ) ) ;
#else
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_LEGACY ) ) ;
if ( F_97 ( V_1 , V_250 ) ) {
F_8 ( V_1 -> V_173 , F_3 ( V_1 , V_25 ) ) ;
F_25 ( 20 ) ;
}
F_8 ( V_1 -> V_76 | V_251 , F_3 ( V_1 , V_39 ) ) ;
F_2 ( F_3 ( V_1 , V_39 ) ) ;
F_109 ( 20 ) ;
F_8 ( V_1 -> V_76 , F_3 ( V_1 , V_39 ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_12 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_218 = 0 ; V_218 < 0x80 ; V_218 ++ )
F_9 ( V_1 , V_218 , 0 ) ;
F_9 ( V_1 , V_53 + V_49 , 16 << 4 ) ;
F_9 ( V_1 , V_53 + V_50 , 16 << 10 ) ;
F_9 ( V_1 , V_54 + V_49 , 16 << 4 ) ;
F_9 ( V_1 , V_54 + V_50 , 16 << 10 ) ;
F_9 ( V_1 , V_52 , 1 << 12 ) ;
F_9 ( V_1 , V_52 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_252 , 1 << 12 ) ;
F_9 ( V_1 , V_252 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_253 , 1 << 12 ) ;
F_9 ( V_1 , V_253 + 1 , 1 << 12 ) ;
F_26 ( V_1 , 22050 ) ;
F_27 ( V_1 , 22050 ) ;
F_28 ( V_1 , 22050 ) ;
F_1 ( V_1 ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_8 ( F_19 ( 0 , 0 ) , F_3 ( V_1 , 1371_CODEC ) ) ;
#endif
F_141 ( V_1 -> V_254 = 0x00 , F_3 ( V_1 , V_255 ) ) ;
F_141 ( 0x00 , F_3 ( V_1 , V_256 ) ) ;
F_8 ( V_1 -> V_173 , F_3 ( V_1 , V_25 ) ) ;
F_132 ( V_1 -> V_239 ) ;
}
static int F_142 ( struct V_28 * V_7 )
{
struct V_189 * V_6 = F_143 ( V_7 ) ;
struct V_1 * V_1 = V_6 -> V_21 ;
F_144 ( V_6 , V_257 ) ;
F_145 ( V_1 -> V_150 ) ;
F_145 ( V_1 -> V_154 ) ;
#ifdef F_45
F_146 ( V_1 -> V_110 . V_179 . V_30 ) ;
#else
F_12 ( F_13 ( V_219 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_219 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_147 ( V_1 -> V_110 . V_111 . V_19 ) ;
#endif
return 0 ;
}
static int F_148 ( struct V_28 * V_7 )
{
struct V_189 * V_6 = F_143 ( V_7 ) ;
struct V_1 * V_1 = V_6 -> V_21 ;
F_140 ( V_1 ) ;
#ifdef F_45
F_149 ( V_1 -> V_110 . V_179 . V_30 ) ;
#else
F_150 ( V_1 -> V_110 . V_111 . V_19 ) ;
#endif
F_144 ( V_6 , V_258 ) ;
return 0 ;
}
static int F_151 ( struct V_189 * V_6 ,
struct V_259 * V_27 ,
struct V_1 * * V_260 )
{
struct V_1 * V_1 ;
int V_141 ;
static struct V_261 V_194 = {
. V_262 = F_139 ,
} ;
* V_260 = NULL ;
if ( ( V_141 = F_152 ( V_27 ) ) < 0 )
return V_141 ;
V_1 = F_153 ( sizeof( * V_1 ) , V_263 ) ;
if ( V_1 == NULL ) {
F_137 ( V_27 ) ;
return - V_208 ;
}
F_154 ( & V_1 -> V_68 ) ;
F_155 ( & V_1 -> V_34 ) ;
V_1 -> V_6 = V_6 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_239 = - 1 ;
if ( ( V_141 = F_156 ( V_27 , L_26 ) ) < 0 ) {
F_138 ( V_1 ) ;
F_137 ( V_27 ) ;
return V_141 ;
}
V_1 -> V_232 = F_157 ( V_27 , 0 ) ;
if ( F_158 ( V_27 -> V_239 , V_264 , V_265 ,
V_266 , V_1 ) ) {
F_5 ( V_6 -> V_7 , L_27 , V_27 -> V_239 ) ;
F_131 ( V_1 ) ;
return - V_228 ;
}
V_1 -> V_239 = V_27 -> V_239 ;
#ifdef F_48
if ( F_159 ( V_151 , F_79 ( V_27 ) ,
16 , & V_1 -> V_243 ) < 0 ) {
F_5 ( V_6 -> V_7 , L_28 ) ;
F_131 ( V_1 ) ;
return - V_228 ;
}
#endif
F_160 ( V_27 ) ;
V_1 -> V_186 = V_27 -> V_267 ;
#ifdef F_48
#if 0
ensoniq->ctrl = ES_1370_CDC_EN | ES_1370_SERR_DISABLE |
ES_1370_PCLKDIVO(ES_1370_SRTODIV(8000));
#else
V_1 -> V_76 = V_268 | F_56 ( F_57 ( 8000 ) ) ;
#endif
V_1 -> V_69 = 0 ;
#else
V_1 -> V_76 = 0 ;
V_1 -> V_69 = 0 ;
V_1 -> V_173 = 0 ;
if ( F_103 ( V_27 , V_269 ) )
V_1 -> V_76 |= F_95 ( 1 ) ;
if ( F_97 ( V_1 , V_250 ) )
V_1 -> V_173 |= V_270 ;
#endif
F_140 ( V_1 ) ;
if ( ( V_141 = F_161 ( V_6 , V_271 , V_1 , & V_194 ) ) < 0 ) {
F_131 ( V_1 ) ;
return V_141 ;
}
F_128 ( V_1 ) ;
* V_260 = V_1 ;
return 0 ;
}
static void F_162 ( struct V_1 * V_1 )
{
struct V_272 * V_273 = V_1 -> V_273 ;
unsigned char V_165 , V_215 , V_274 ;
if ( V_273 == NULL )
return;
F_33 ( & V_1 -> V_68 ) ;
V_215 = V_1 -> V_275 & V_276 ? V_277 : 0 ;
while ( V_215 ) {
V_165 = F_163 ( F_3 ( V_1 , V_278 ) ) ;
if ( ( V_165 & V_215 ) == 0 )
break;
V_274 = F_163 ( F_3 ( V_1 , V_279 ) ) ;
F_164 ( V_1 -> V_280 , & V_274 , 1 ) ;
}
F_34 ( & V_1 -> V_68 ) ;
F_33 ( & V_1 -> V_68 ) ;
V_215 = V_1 -> V_275 & V_281 ? V_282 : 0 ;
while ( V_215 ) {
V_165 = F_163 ( F_3 ( V_1 , V_278 ) ) ;
if ( ( V_165 & V_215 ) == 0 )
break;
if ( F_165 ( V_1 -> V_283 , & V_274 , 1 ) != 1 ) {
V_1 -> V_254 &= ~ V_284 ;
F_141 ( V_1 -> V_254 , F_3 ( V_1 , V_255 ) ) ;
V_215 &= ~ V_282 ;
} else {
F_141 ( V_274 , F_3 ( V_1 , V_279 ) ) ;
}
}
F_34 ( & V_1 -> V_68 ) ;
}
static int F_166 ( struct V_285 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_275 |= V_276 ;
V_1 -> V_280 = V_56 ;
if ( ! ( V_1 -> V_275 & V_281 ) ) {
F_141 ( F_167 ( 3 ) , F_3 ( V_1 , V_255 ) ) ;
F_141 ( V_1 -> V_254 = 0 , F_3 ( V_1 , V_255 ) ) ;
F_8 ( V_1 -> V_76 |= V_286 , F_3 ( V_1 , V_39 ) ) ;
}
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_168 ( struct V_285 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ! ( V_1 -> V_275 & V_281 ) ) {
F_141 ( V_1 -> V_254 = 0 , F_3 ( V_1 , V_255 ) ) ;
F_8 ( V_1 -> V_76 &= ~ V_286 , F_3 ( V_1 , V_39 ) ) ;
} else {
F_141 ( V_1 -> V_254 &= ~ V_287 , F_3 ( V_1 , V_255 ) ) ;
}
V_1 -> V_280 = NULL ;
V_1 -> V_275 &= ~ V_276 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_169 ( struct V_285 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
V_1 -> V_275 |= V_281 ;
V_1 -> V_283 = V_56 ;
if ( ! ( V_1 -> V_275 & V_276 ) ) {
F_141 ( F_167 ( 3 ) , F_3 ( V_1 , V_255 ) ) ;
F_141 ( V_1 -> V_254 = 0 , F_3 ( V_1 , V_255 ) ) ;
F_8 ( V_1 -> V_76 |= V_286 , F_3 ( V_1 , V_39 ) ) ;
}
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static int F_170 ( struct V_285 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
F_44 ( & V_1 -> V_68 ) ;
if ( ! ( V_1 -> V_275 & V_276 ) ) {
F_141 ( V_1 -> V_254 = 0 , F_3 ( V_1 , V_255 ) ) ;
F_8 ( V_1 -> V_76 &= ~ V_286 , F_3 ( V_1 , V_39 ) ) ;
} else {
F_141 ( V_1 -> V_254 &= ~ V_284 , F_3 ( V_1 , V_255 ) ) ;
}
V_1 -> V_283 = NULL ;
V_1 -> V_275 &= ~ V_281 ;
F_51 ( & V_1 -> V_68 ) ;
return 0 ;
}
static void F_171 ( struct V_285 * V_56 , int V_288 )
{
unsigned long V_289 ;
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
int V_218 ;
F_172 ( & V_1 -> V_68 , V_289 ) ;
if ( V_288 ) {
if ( ( V_1 -> V_254 & V_287 ) == 0 ) {
for ( V_218 = 0 ; V_218 < 32 ; V_218 ++ )
F_163 ( F_3 ( V_1 , V_279 ) ) ;
V_1 -> V_254 |= V_287 ;
F_141 ( V_1 -> V_254 , F_3 ( V_1 , V_255 ) ) ;
}
} else {
if ( V_1 -> V_254 & V_287 ) {
V_1 -> V_254 &= ~ V_287 ;
F_141 ( V_1 -> V_254 , F_3 ( V_1 , V_255 ) ) ;
}
}
F_173 ( & V_1 -> V_68 , V_289 ) ;
}
static void F_174 ( struct V_285 * V_56 , int V_288 )
{
unsigned long V_289 ;
struct V_1 * V_1 = V_56 -> V_273 -> V_21 ;
unsigned char V_274 ;
F_172 ( & V_1 -> V_68 , V_289 ) ;
if ( V_288 ) {
if ( F_175 ( V_1 -> V_254 ) == 0 ) {
V_1 -> V_254 |= F_176 ( 1 ) ;
while ( F_175 ( V_1 -> V_254 ) == 1 &&
( F_163 ( F_3 ( V_1 , V_278 ) ) & V_282 ) ) {
if ( F_165 ( V_56 , & V_274 , 1 ) != 1 ) {
V_1 -> V_254 &= ~ V_284 ;
} else {
F_141 ( V_274 , F_3 ( V_1 , V_279 ) ) ;
}
}
F_141 ( V_1 -> V_254 , F_3 ( V_1 , V_255 ) ) ;
}
} else {
if ( F_175 ( V_1 -> V_254 ) == 1 ) {
V_1 -> V_254 &= ~ V_284 ;
F_141 ( V_1 -> V_254 , F_3 ( V_1 , V_255 ) ) ;
}
}
F_173 ( & V_1 -> V_68 , V_289 ) ;
}
static int F_177 ( struct V_1 * V_1 , int V_28 )
{
struct V_272 * V_273 ;
int V_141 ;
if ( ( V_141 = F_178 ( V_1 -> V_6 , L_29 , V_28 , 1 , 1 , & V_273 ) ) < 0 )
return V_141 ;
strcpy ( V_273 -> V_149 , V_142 ) ;
F_179 ( V_273 , V_290 , & V_291 ) ;
F_179 ( V_273 , V_292 , & V_293 ) ;
V_273 -> V_148 |= V_294 | V_295 |
V_296 ;
V_273 -> V_21 = V_1 ;
V_1 -> V_273 = V_273 ;
return 0 ;
}
static T_3 V_264 ( int V_239 , void * V_297 )
{
struct V_1 * V_1 = V_297 ;
unsigned int V_165 , V_69 ;
if ( V_1 == NULL )
return V_298 ;
V_165 = F_2 ( F_3 ( V_1 , V_25 ) ) ;
if ( ! ( V_165 & V_299 ) )
return V_298 ;
F_33 ( & V_1 -> V_68 ) ;
V_69 = V_1 -> V_69 ;
if ( V_165 & V_300 )
V_69 &= ~ V_95 ;
if ( V_165 & V_301 )
V_69 &= ~ V_108 ;
if ( V_165 & V_302 )
V_69 &= ~ V_123 ;
F_8 ( V_69 , F_3 ( V_1 , V_70 ) ) ;
F_8 ( V_1 -> V_69 , F_3 ( V_1 , V_70 ) ) ;
F_34 ( & V_1 -> V_68 ) ;
if ( V_165 & V_303 )
F_162 ( V_1 ) ;
if ( ( V_165 & V_301 ) && V_1 -> V_64 )
F_180 ( V_1 -> V_64 ) ;
if ( ( V_165 & V_302 ) && V_1 -> V_66 )
F_180 ( V_1 -> V_66 ) ;
if ( ( V_165 & V_300 ) && V_1 -> V_62 )
F_180 ( V_1 -> V_62 ) ;
return V_304 ;
}
static int F_181 ( struct V_259 * V_27 ,
const struct V_305 * V_306 )
{
static int V_7 ;
struct V_189 * V_6 ;
struct V_1 * V_1 ;
int V_141 , V_307 [ 2 ] ;
if ( V_7 >= V_308 )
return - V_309 ;
if ( ! V_310 [ V_7 ] ) {
V_7 ++ ;
return - V_311 ;
}
V_141 = F_182 ( & V_27 -> V_7 , V_210 [ V_7 ] , V_209 [ V_7 ] , V_312 ,
0 , & V_6 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ( V_141 = F_151 ( V_6 , V_27 , & V_1 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
V_6 -> V_21 = V_1 ;
V_307 [ 0 ] = 0 ; V_307 [ 1 ] = 1 ;
#ifdef F_48
if ( ( V_141 = F_107 ( V_1 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
#endif
#ifdef F_45
if ( ( V_141 = F_98 ( V_1 , V_129 [ V_7 ] , V_313 [ V_7 ] ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
#endif
if ( ( V_141 = F_75 ( V_1 , 0 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
if ( ( V_141 = F_81 ( V_1 , 1 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
if ( ( V_141 = F_177 ( V_1 , 0 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
F_112 ( V_1 , V_7 ) ;
strcpy ( V_6 -> V_314 , V_315 ) ;
strcpy ( V_6 -> V_316 , L_26 ) ;
sprintf ( V_6 -> V_317 , L_30 ,
V_6 -> V_316 ,
V_6 -> V_314 ,
V_1 -> V_232 ,
V_1 -> V_239 ) ;
if ( ( V_141 = F_184 ( V_6 ) ) < 0 ) {
F_183 ( V_6 ) ;
return V_141 ;
}
F_185 ( V_27 , V_6 ) ;
V_7 ++ ;
return 0 ;
}
static void F_186 ( struct V_259 * V_27 )
{
F_183 ( F_187 ( V_27 ) ) ;
}
