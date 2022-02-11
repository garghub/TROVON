static unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_3 = F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) ;
if ( ( V_3 & V_5 ) == 0 )
return V_3 ;
F_4 () ;
}
F_5 ( V_6 L_1 ,
F_3 ( V_1 , 1371_SMPRATE ) , V_3 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_1 , unsigned short V_7 )
{
unsigned int V_8 , V_9 , V_10 , V_3 ;
V_8 = V_10 = F_1 ( V_1 ) ;
V_3 = V_8 & ( V_11 | V_12 |
V_13 | V_14 ) ;
V_3 |= F_7 ( V_7 ) | 0x10000 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
V_8 = F_1 ( V_1 ) ;
if ( ( V_8 & 0x00870000 ) != 0x00010000 ) {
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_8 = F_2 ( F_3 ( V_1 , 1371_SMPRATE ) ) ;
if ( ( V_8 & 0x00870000 ) == 0x00010000 )
break;
}
}
V_3 = V_10 & ( V_11 | V_12 |
V_13 | V_14 ) ;
V_3 |= F_7 ( V_7 ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_1 ,
unsigned short V_7 , unsigned short V_15 )
{
unsigned int V_3 ;
V_3 = F_1 ( V_1 ) &
( V_11 | V_12 |
V_13 | V_14 ) ;
V_3 |= F_7 ( V_7 ) | F_10 ( V_15 ) ;
F_8 ( V_3 | V_16 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
}
static void F_11 ( struct V_17 * V_18 ,
unsigned short V_7 , unsigned short V_19 )
{
struct V_1 * V_1 = V_18 -> V_20 ;
unsigned long V_21 = V_22 + V_23 / 10 ;
#if 0
printk(KERN_DEBUG
"CODEC WRITE: reg = 0x%x, val = 0x%x (0x%x), creg = 0x%x\n",
reg, val, ES_1370_CODEC_WRITE(reg, val), ES_REG(ensoniq, 1370_CODEC));
#endif
do {
if ( ! ( F_2 ( F_3 ( V_1 , V_24 ) ) & V_25 ) ) {
F_12 ( F_13 ( V_7 , V_19 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
return;
}
F_14 ( 1 ) ;
} while ( F_15 ( V_21 , V_22 ) );
F_5 ( V_6 L_2 ,
F_2 ( F_3 ( V_1 , V_24 ) ) ) ;
}
static inline bool F_16 ( struct V_1 * V_1 )
{
return V_1 -> V_26 -> V_27 == 0x8938 ;
}
static void F_17 ( struct V_28 * V_29 ,
unsigned short V_7 , unsigned short V_19 )
{
struct V_1 * V_1 = V_29 -> V_20 ;
unsigned int V_2 , V_30 , V_31 ;
V_31 = F_16 ( V_1 ) ? V_32 : 0 ;
F_18 ( & V_1 -> V_33 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_34 ) ) {
V_30 = F_1 ( V_1 ) ;
F_8 ( ( V_30 & ( V_11 | V_12 |
V_13 | V_14 ) ) | 0x00010000 ,
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
F_8 ( F_19 ( V_7 , V_19 ) | V_31 ,
F_3 ( V_1 , 1371_CODEC ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_30 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_33 ) ;
return;
}
}
F_20 ( & V_1 -> V_33 ) ;
F_5 ( V_6 L_3 ,
F_3 ( V_1 , 1371_CODEC ) , F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
}
static unsigned short F_21 ( struct V_28 * V_29 ,
unsigned short V_7 )
{
struct V_1 * V_1 = V_29 -> V_20 ;
unsigned int V_2 , V_30 , V_31 , V_35 = 0 ;
V_31 = F_16 ( V_1 ) ? V_32 : 0 ;
V_36:
F_18 ( & V_1 -> V_33 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_34 ) ) {
V_30 = F_1 ( V_1 ) ;
F_8 ( ( V_30 & ( V_11 | V_12 |
V_13 | V_14 ) ) | 0x00010000 ,
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
F_8 ( F_22 ( V_7 ) | V_31 ,
F_3 ( V_1 , 1371_CODEC ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_30 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ! ( F_2 ( F_3 ( V_1 , 1371_CODEC ) ) & V_34 ) )
break;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( V_30 = F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) & V_37 ) {
if ( F_16 ( V_1 ) ) {
for ( V_2 = 0 ; V_2 < 100 ; V_2 ++ )
F_2 ( F_3 ( V_1 , V_38 ) ) ;
V_30 = F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ;
}
F_20 ( & V_1 -> V_33 ) ;
return F_23 ( V_30 ) ;
}
}
F_20 ( & V_1 -> V_33 ) ;
if ( ++ V_35 > 10 ) {
F_5 ( V_6 L_4
L_5 ,
F_3 ( V_1 , 1371_CODEC ) , V_7 ,
F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
return 0 ;
}
goto V_36;
}
}
F_20 ( & V_1 -> V_33 ) ;
F_5 ( V_6 L_6 ,
F_3 ( V_1 , 1371_CODEC ) , F_2 ( F_3 ( V_1 , 1371_CODEC ) ) ) ;
return 0 ;
}
static void F_24 ( struct V_28 * V_29 )
{
F_25 ( 750 ) ;
F_21 ( V_29 , V_39 ) ;
F_21 ( V_29 , V_40 ) ;
F_21 ( V_29 , V_41 ) ;
F_25 ( 50 ) ;
}
static void F_26 ( struct V_1 * V_1 , unsigned int V_42 )
{
unsigned int V_43 , V_44 , V_45 , V_46 ;
F_18 ( & V_1 -> V_33 ) ;
V_43 = V_42 / 3000 ;
if ( ( 1 << V_43 ) & ( ( 1 << 15 ) | ( 1 << 13 ) | ( 1 << 11 ) | ( 1 << 9 ) ) )
V_43 -- ;
V_44 = ( 21 * V_43 - 1 ) | 1 ;
V_45 = ( ( 48000UL << 15 ) / V_42 ) * V_43 ;
V_46 = ( 48000UL << 15 ) / ( V_45 / V_43 ) ;
if ( V_42 >= 24000 ) {
if ( V_44 > 239 )
V_44 = 239 ;
F_9 ( V_1 , V_47 + V_48 ,
( ( ( 239 - V_44 ) >> 1 ) << 9 ) | ( V_43 << 4 ) ) ;
} else {
if ( V_44 > 119 )
V_44 = 119 ;
F_9 ( V_1 , V_47 + V_48 ,
0x8000 | ( ( ( 119 - V_44 ) >> 1 ) << 9 ) | ( V_43 << 4 ) ) ;
}
F_9 ( V_1 , V_47 + V_49 ,
( F_6 ( V_1 , V_47 +
V_49 ) & 0x00ff ) |
( ( V_45 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_47 + V_50 , V_45 & 0x7fff ) ;
F_9 ( V_1 , V_51 , V_43 << 8 ) ;
F_9 ( V_1 , V_51 + 1 , V_43 << 8 ) ;
F_20 ( & V_1 -> V_33 ) ;
}
static void F_27 ( struct V_1 * V_1 , unsigned int V_42 )
{
unsigned int V_45 , V_3 ;
F_18 ( & V_1 -> V_33 ) ;
V_45 = ( ( V_42 << 15 ) + 1500 ) / 3000 ;
V_3 = ( F_1 ( V_1 ) & ( V_11 |
V_13 | V_14 ) ) |
V_12 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_9 ( V_1 , V_52 + V_49 ,
( F_6 ( V_1 , V_52 +
V_49 ) & 0x00ff ) |
( ( V_45 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_52 + V_50 , V_45 & 0x7fff ) ;
V_3 = ( F_1 ( V_1 ) & ( V_11 |
V_13 | V_14 ) ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_33 ) ;
}
static void F_28 ( struct V_1 * V_1 , unsigned int V_42 )
{
unsigned int V_45 , V_3 ;
F_18 ( & V_1 -> V_33 ) ;
V_45 = ( ( V_42 << 15 ) + 1500 ) / 3000 ;
V_3 = ( F_1 ( V_1 ) & ( V_11 |
V_12 | V_14 ) ) |
V_13 ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_9 ( V_1 , V_53 + V_49 ,
( F_6 ( V_1 , V_53 +
V_49 ) & 0x00ff ) |
( ( V_45 >> 5 ) & 0xfc00 ) ) ;
F_9 ( V_1 , V_53 + V_50 ,
V_45 & 0x7fff ) ;
V_3 = ( F_1 ( V_1 ) & ( V_11 |
V_12 | V_14 ) ) ;
F_8 ( V_3 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_20 ( & V_1 -> V_33 ) ;
}
static int F_29 ( struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
switch ( V_56 ) {
case V_57 :
case V_58 :
{
unsigned int V_59 = 0 ;
struct V_54 * V_60 ;
F_31 (s, substream) {
if ( V_60 == V_1 -> V_61 ) {
V_59 |= V_62 ;
F_32 ( V_60 , V_55 ) ;
} else if ( V_60 == V_1 -> V_63 ) {
V_59 |= V_64 ;
F_32 ( V_60 , V_55 ) ;
} else if ( V_60 == V_1 -> V_65 )
return - V_66 ;
}
F_33 ( & V_1 -> V_67 ) ;
if ( V_56 == V_57 )
V_1 -> V_68 |= V_59 ;
else
V_1 -> V_68 &= ~ V_59 ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_34 ( & V_1 -> V_67 ) ;
break;
}
case V_70 :
case V_71 :
{
unsigned int V_59 = 0 ;
struct V_54 * V_60 ;
F_31 (s, substream) {
if ( V_60 == V_1 -> V_61 ) {
V_59 |= V_72 ;
F_32 ( V_60 , V_55 ) ;
} else if ( V_60 == V_1 -> V_63 ) {
V_59 |= V_73 ;
F_32 ( V_60 , V_55 ) ;
} else if ( V_60 == V_1 -> V_65 ) {
V_59 |= V_74 ;
F_32 ( V_60 , V_55 ) ;
}
}
F_33 ( & V_1 -> V_67 ) ;
if ( V_56 == V_70 )
V_1 -> V_75 |= V_59 ;
else
V_1 -> V_75 &= ~ V_59 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_34 ( & V_1 -> V_67 ) ;
break;
}
default:
return - V_66 ;
}
return 0 ;
}
static int F_35 ( struct V_54 * V_55 ,
struct V_76 * V_77 )
{
return F_36 ( V_55 , F_37 ( V_77 ) ) ;
}
static int F_38 ( struct V_54 * V_55 )
{
return F_39 ( V_55 ) ;
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
unsigned int V_80 = 0 ;
V_1 -> V_81 = F_41 ( V_55 ) ;
V_1 -> V_82 = F_42 ( V_55 ) ;
if ( F_43 ( V_79 -> V_83 ) == 16 )
V_80 |= 0x02 ;
if ( V_79 -> V_84 > 1 )
V_80 |= 0x01 ;
F_44 ( & V_1 -> V_67 ) ;
V_1 -> V_75 &= ~ V_72 ;
#ifdef F_45
if ( V_79 -> V_42 == 48000 )
V_1 -> V_75 |= V_85 ;
else
V_1 -> V_75 &= ~ V_85 ;
#endif
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( F_46 ( V_86 ) , F_3 ( V_1 , V_87 ) ) ;
F_8 ( V_79 -> V_88 , F_3 ( V_1 , V_89 ) ) ;
F_8 ( ( V_1 -> V_81 >> 2 ) - 1 , F_3 ( V_1 , V_90 ) ) ;
V_1 -> V_68 &= ~ ( V_91 | V_62 | V_92 | V_93 ) ;
V_1 -> V_68 |= V_94 | F_47 ( V_80 ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( ( V_1 -> V_82 >> V_95 [ V_80 ] ) - 1 ,
F_3 ( V_1 , V_96 ) ) ;
#ifdef F_48
V_1 -> V_75 &= ~ V_97 ;
switch ( V_79 -> V_42 ) {
case 5512 : V_1 -> V_75 |= F_49 ( 0 ) ; break;
case 11025 : V_1 -> V_75 |= F_49 ( 1 ) ; break;
case 22050 : V_1 -> V_75 |= F_49 ( 2 ) ; break;
case 44100 : V_1 -> V_75 |= F_49 ( 3 ) ; break;
default: F_50 () ;
}
#endif
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
#ifndef F_48
F_27 ( V_1 , V_79 -> V_42 ) ;
#endif
return 0 ;
}
static int F_52 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
unsigned int V_80 = 0 ;
V_1 -> V_98 = F_41 ( V_55 ) ;
V_1 -> V_99 = F_42 ( V_55 ) ;
if ( F_43 ( V_79 -> V_83 ) == 16 )
V_80 |= 0x02 ;
if ( V_79 -> V_84 > 1 )
V_80 |= 0x01 ;
F_44 ( & V_1 -> V_67 ) ;
V_1 -> V_75 &= ~ V_73 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( F_46 ( V_86 ) , F_3 ( V_1 , V_87 ) ) ;
F_8 ( V_79 -> V_88 , F_3 ( V_1 , V_100 ) ) ;
F_8 ( ( V_1 -> V_98 >> 2 ) - 1 , F_3 ( V_1 , V_101 ) ) ;
V_1 -> V_68 &= ~ ( V_102 | V_64 | V_103 |
V_104 | V_105 | V_106 ) ;
V_1 -> V_68 |= V_107 | F_53 ( V_80 ) |
F_54 ( V_80 & 2 ? 2 : 1 ) | F_55 ( 0 ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( ( V_1 -> V_99 >> V_95 [ V_80 ] ) - 1 ,
F_3 ( V_1 , V_108 ) ) ;
#ifdef F_48
if ( ! ( V_1 -> V_109 . V_110 . V_111 & V_112 ) ) {
V_1 -> V_75 &= ~ V_113 ;
V_1 -> V_75 |= F_56 ( F_57 ( V_79 -> V_42 ) ) ;
V_1 -> V_109 . V_110 . V_111 |= V_114 ;
}
#endif
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
#ifndef F_48
F_28 ( V_1 , V_79 -> V_42 ) ;
#endif
return 0 ;
}
static int F_58 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
unsigned int V_80 = 0 ;
V_1 -> V_115 = F_41 ( V_55 ) ;
V_1 -> V_116 = F_42 ( V_55 ) ;
if ( F_43 ( V_79 -> V_83 ) == 16 )
V_80 |= 0x02 ;
if ( V_79 -> V_84 > 1 )
V_80 |= 0x01 ;
F_44 ( & V_1 -> V_67 ) ;
V_1 -> V_75 &= ~ V_74 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( F_46 ( V_117 ) , F_3 ( V_1 , V_87 ) ) ;
F_8 ( V_79 -> V_88 , F_3 ( V_1 , V_118 ) ) ;
F_8 ( ( V_1 -> V_115 >> 2 ) - 1 , F_3 ( V_1 , V_119 ) ) ;
V_1 -> V_68 &= ~ ( V_120 | V_121 ) ;
V_1 -> V_68 |= V_122 | F_59 ( V_80 ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( ( V_1 -> V_116 >> V_95 [ V_80 ] ) - 1 ,
F_3 ( V_1 , V_123 ) ) ;
#ifdef F_48
if ( ! ( V_1 -> V_109 . V_110 . V_111 & V_114 ) ) {
V_1 -> V_75 &= ~ V_113 ;
V_1 -> V_75 |= F_56 ( F_57 ( V_79 -> V_42 ) ) ;
V_1 -> V_109 . V_110 . V_111 |= V_112 ;
}
#endif
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
#ifndef F_48
F_26 ( V_1 , V_79 -> V_42 ) ;
#endif
return 0 ;
}
static T_1 F_60 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
T_2 V_124 ;
F_33 ( & V_1 -> V_67 ) ;
if ( F_2 ( F_3 ( V_1 , V_38 ) ) & V_72 ) {
F_8 ( F_46 ( V_86 ) , F_3 ( V_1 , V_87 ) ) ;
V_124 = F_61 ( F_2 ( F_3 ( V_1 , V_90 ) ) ) ;
V_124 = F_62 ( V_55 -> V_79 , V_124 ) ;
} else {
V_124 = 0 ;
}
F_34 ( & V_1 -> V_67 ) ;
return V_124 ;
}
static T_1 F_63 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
T_2 V_124 ;
F_33 ( & V_1 -> V_67 ) ;
if ( F_2 ( F_3 ( V_1 , V_38 ) ) & V_73 ) {
F_8 ( F_46 ( V_86 ) , F_3 ( V_1 , V_87 ) ) ;
V_124 = F_61 ( F_2 ( F_3 ( V_1 , V_101 ) ) ) ;
V_124 = F_62 ( V_55 -> V_79 , V_124 ) ;
} else {
V_124 = 0 ;
}
F_34 ( & V_1 -> V_67 ) ;
return V_124 ;
}
static T_1 F_64 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
T_2 V_124 ;
F_33 ( & V_1 -> V_67 ) ;
if ( F_2 ( F_3 ( V_1 , V_38 ) ) & V_74 ) {
F_8 ( F_46 ( V_117 ) , F_3 ( V_1 , V_87 ) ) ;
V_124 = F_61 ( F_2 ( F_3 ( V_1 , V_119 ) ) ) ;
V_124 = F_62 ( V_55 -> V_79 , V_124 ) ;
} else {
V_124 = 0 ;
}
F_34 ( & V_1 -> V_67 ) ;
return V_124 ;
}
static int F_65 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
V_1 -> V_80 |= V_125 ;
V_1 -> V_61 = V_55 ;
V_79 -> V_126 = V_127 ;
F_66 ( V_55 ) ;
F_44 ( & V_1 -> V_67 ) ;
if ( V_1 -> V_128 && V_1 -> V_63 == NULL )
V_1 -> V_129 = V_1 -> V_130 ;
F_51 ( & V_1 -> V_67 ) ;
#ifdef F_48
F_67 ( V_79 , 0 , V_131 ,
& V_132 ) ;
#else
F_68 ( V_79 , 0 , V_131 ,
& V_133 ) ;
#endif
return 0 ;
}
static int F_69 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
V_1 -> V_80 |= V_114 ;
V_1 -> V_63 = V_55 ;
V_79 -> V_126 = V_134 ;
F_66 ( V_55 ) ;
F_44 ( & V_1 -> V_67 ) ;
if ( V_1 -> V_128 && V_1 -> V_61 == NULL )
V_1 -> V_129 = V_1 -> V_130 ;
F_51 ( & V_1 -> V_67 ) ;
#ifdef F_48
F_70 ( V_79 , 0 , V_131 ,
& V_135 ) ;
#else
F_68 ( V_79 , 0 , V_131 ,
& V_133 ) ;
#endif
return 0 ;
}
static int F_71 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
struct V_78 * V_79 = V_55 -> V_79 ;
V_1 -> V_80 |= V_112 ;
V_1 -> V_65 = V_55 ;
V_79 -> V_126 = V_136 ;
F_66 ( V_55 ) ;
#ifdef F_48
F_70 ( V_79 , 0 , V_131 ,
& V_135 ) ;
#else
F_70 ( V_79 , 0 , V_131 ,
& V_137 ) ;
#endif
return 0 ;
}
static int F_72 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
V_1 -> V_61 = NULL ;
V_1 -> V_80 &= ~ V_125 ;
return 0 ;
}
static int F_73 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
V_1 -> V_63 = NULL ;
F_44 ( & V_1 -> V_67 ) ;
#ifdef F_48
V_1 -> V_109 . V_110 . V_111 &= ~ V_114 ;
#endif
V_1 -> V_80 &= ~ V_114 ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_74 ( struct V_54 * V_55 )
{
struct V_1 * V_1 = F_30 ( V_55 ) ;
V_1 -> V_65 = NULL ;
F_44 ( & V_1 -> V_67 ) ;
#ifdef F_48
V_1 -> V_109 . V_110 . V_111 &= ~ V_112 ;
#endif
V_1 -> V_80 &= ~ V_112 ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_1 , int V_27 ,
struct V_138 * * V_139 )
{
struct V_138 * V_140 ;
int V_141 ;
if ( V_139 )
* V_139 = NULL ;
V_141 = F_76 ( V_1 -> V_142 , V_143 L_7 , V_27 , 1 , 1 , & V_140 ) ;
if ( V_141 < 0 )
return V_141 ;
#ifdef F_48
F_77 ( V_140 , V_144 , & V_145 ) ;
#else
F_77 ( V_140 , V_144 , & V_146 ) ;
#endif
F_77 ( V_140 , V_147 , & V_148 ) ;
V_140 -> V_20 = V_1 ;
V_140 -> V_149 = 0 ;
strcpy ( V_140 -> V_150 , V_143 L_8 ) ;
V_1 -> V_151 = V_140 ;
F_78 ( V_140 , V_152 ,
F_79 ( V_1 -> V_26 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_141 = F_80 ( V_140 , V_144 ,
V_153 , 2 , 0 , NULL ) ;
#else
V_141 = F_80 ( V_140 , V_144 ,
V_154 , 2 , 0 , NULL ) ;
#endif
if ( V_141 < 0 )
return V_141 ;
if ( V_139 )
* V_139 = V_140 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_1 , int V_27 ,
struct V_138 * * V_139 )
{
struct V_138 * V_140 ;
int V_141 ;
if ( V_139 )
* V_139 = NULL ;
V_141 = F_76 ( V_1 -> V_142 , V_143 L_9 , V_27 , 1 , 0 , & V_140 ) ;
if ( V_141 < 0 )
return V_141 ;
#ifdef F_48
F_77 ( V_140 , V_144 , & V_146 ) ;
#else
F_77 ( V_140 , V_144 , & V_145 ) ;
#endif
V_140 -> V_20 = V_1 ;
V_140 -> V_149 = 0 ;
strcpy ( V_140 -> V_150 , V_143 L_10 ) ;
V_1 -> V_155 = V_140 ;
F_78 ( V_140 , V_152 ,
F_79 ( V_1 -> V_26 ) , 64 * 1024 , 128 * 1024 ) ;
#ifdef F_48
V_141 = F_80 ( V_140 , V_144 ,
V_154 , 2 , 0 , NULL ) ;
#else
V_141 = F_80 ( V_140 , V_144 ,
V_153 , 2 , 0 , NULL ) ;
#endif
if ( V_141 < 0 )
return V_141 ;
if ( V_139 )
* V_139 = V_140 ;
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
F_44 ( & V_1 -> V_67 ) ;
V_163 -> V_164 . V_165 . V_166 [ 0 ] = ( V_1 -> V_130 >> 0 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 1 ] = ( V_1 -> V_130 >> 8 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 2 ] = ( V_1 -> V_130 >> 16 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 3 ] = ( V_1 -> V_130 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_85 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_19 ;
int V_167 ;
V_19 = ( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 0 ] << 0 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 1 ] << 8 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 2 ] << 16 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_67 ) ;
V_167 = V_1 -> V_130 != V_19 ;
V_1 -> V_130 = V_19 ;
if ( V_167 && V_1 -> V_61 == NULL &&
V_1 -> V_63 == NULL )
F_8 ( V_19 , F_3 ( V_1 , V_169 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
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
F_44 ( & V_1 -> V_67 ) ;
V_163 -> V_164 . V_165 . V_166 [ 0 ] = ( V_1 -> V_129 >> 0 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 1 ] = ( V_1 -> V_129 >> 8 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 2 ] = ( V_1 -> V_129 >> 16 ) & 0xff ;
V_163 -> V_164 . V_165 . V_166 [ 3 ] = ( V_1 -> V_129 >> 24 ) & 0xff ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_88 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
unsigned int V_19 ;
int V_167 ;
V_19 = ( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 0 ] << 0 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 1 ] << 8 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 2 ] << 16 ) |
( ( V_168 ) V_163 -> V_164 . V_165 . V_166 [ 3 ] << 24 ) ;
F_44 ( & V_1 -> V_67 ) ;
V_167 = V_1 -> V_129 != V_19 ;
V_1 -> V_129 = V_19 ;
if ( V_167 && ( V_1 -> V_61 != NULL ||
V_1 -> V_63 != NULL ) )
F_8 ( V_19 , F_3 ( V_1 , V_169 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
return V_167 ;
}
static int F_89 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
F_44 ( & V_1 -> V_67 ) ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_1 -> V_75 & V_170 ? 1 : 0 ;
F_51 ( & V_1 -> V_67 ) ;
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
F_44 ( & V_1 -> V_67 ) ;
V_167 = ( V_1 -> V_75 & V_170 ) != V_171 ;
V_1 -> V_75 &= ~ V_170 ;
V_1 -> V_75 |= V_171 ;
V_1 -> V_174 &= ~ V_173 ;
V_1 -> V_174 |= V_172 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_24 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
return V_167 ;
}
static int F_91 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_19 = 0 ;
F_44 ( & V_1 -> V_67 ) ;
if ( ( V_1 -> V_174 & ( V_175 | V_176 |
V_177 ) ) == V_176 )
V_19 = 1 ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_19 ;
F_51 ( & V_1 -> V_67 ) ;
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
F_44 ( & V_1 -> V_67 ) ;
V_167 = ( V_1 -> V_174 & ( V_175 |
V_176 | V_177 ) ) != V_171 ;
V_1 -> V_174 &= ~ ( V_175 | V_176 | V_177 ) ;
V_1 -> V_174 |= V_171 ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_24 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
return V_167 ;
}
static int F_93 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_19 = 0 ;
F_44 ( & V_1 -> V_67 ) ;
if ( ( V_1 -> V_75 & V_178 ) >= 4 )
V_19 = 1 ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_19 ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_94 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_179 ;
unsigned int V_75 ;
F_44 ( & V_1 -> V_67 ) ;
V_75 = V_1 -> V_75 ;
if ( V_163 -> V_164 . integer . V_164 [ 0 ] )
V_1 -> V_75 |= F_95 ( 4 ) ;
else
V_1 -> V_75 &= ~ F_95 ( 4 ) ;
V_179 = ( V_75 != V_1 -> V_75 ) ;
if ( V_179 )
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
return V_179 ;
}
static void F_96 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = V_29 -> V_20 ;
V_1 -> V_109 . V_180 . V_29 = NULL ;
}
static int F_97 ( struct V_1 * V_1 ,
struct V_181 * V_182 )
{
while ( V_182 -> V_183 != ( unsigned short ) V_184 ) {
if ( V_1 -> V_26 -> V_185 == V_182 -> V_183 &&
V_1 -> V_26 -> V_27 == V_182 -> V_186 &&
V_1 -> V_187 == V_182 -> V_187 )
return 1 ;
V_182 ++ ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_1 ,
int V_188 , int V_189 )
{
struct V_190 * V_142 = V_1 -> V_142 ;
struct V_191 * V_192 ;
struct V_193 V_29 ;
int V_141 ;
static struct V_194 V_195 = {
. V_196 = F_17 ,
. V_197 = F_21 ,
. V_198 = F_24 ,
} ;
if ( ( V_141 = V_191 ( V_142 , 0 , & V_195 , NULL , & V_192 ) ) < 0 )
return V_141 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_20 = V_1 ;
V_29 . V_199 = F_96 ;
V_29 . V_26 = V_1 -> V_26 ;
V_29 . V_200 = V_201 ;
if ( ( V_141 = F_99 ( V_192 , & V_29 , & V_1 -> V_109 . V_180 . V_29 ) ) < 0 )
return V_141 ;
if ( V_188 > 0 ||
( ! V_188 && F_97 ( V_1 , V_202 ) ) ) {
struct V_156 * V_203 ;
int V_9 , V_204 = 0 ;
V_1 -> V_130 = V_1 -> V_129 =
V_205 ;
F_8 ( V_1 -> V_130 , F_3 ( V_1 , V_169 ) ) ;
if ( V_1 -> V_109 . V_180 . V_29 -> V_206 & V_207 )
V_204 ++ ;
for ( V_9 = 0 ; V_9 < F_100 ( V_208 ) ; V_9 ++ ) {
V_203 = F_101 ( & V_208 [ V_9 ] , V_1 ) ;
if ( ! V_203 )
return - V_209 ;
V_203 -> V_210 . V_211 = V_204 ;
V_141 = F_102 ( V_142 , V_203 ) ;
if ( V_141 < 0 )
return V_141 ;
}
}
if ( V_1 -> V_109 . V_180 . V_29 -> V_206 & V_212 ) {
V_1 -> V_174 &= ~ ( V_175 | V_177 ) ;
V_1 -> V_174 |= V_176 ;
V_141 = F_102 ( V_142 , F_101 ( & V_213 , V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_189 > 0 ||
F_103 ( V_1 -> V_26 , V_214 ) ) {
V_141 = F_102 ( V_142 , F_101 ( & V_215 ,
V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
return 0 ;
}
static int F_104 ( struct V_156 * V_157 ,
struct V_162 * V_163 )
{
struct V_1 * V_1 = F_84 ( V_157 ) ;
int V_216 = V_157 -> V_217 ;
F_44 ( & V_1 -> V_67 ) ;
V_163 -> V_164 . integer . V_164 [ 0 ] = V_1 -> V_75 & V_216 ? 1 : 0 ;
F_51 ( & V_1 -> V_67 ) ;
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
F_44 ( & V_1 -> V_67 ) ;
V_167 = ( V_1 -> V_75 & V_216 ) != V_218 ;
V_1 -> V_75 &= ~ V_216 ;
V_1 -> V_75 |= V_218 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_51 ( & V_1 -> V_67 ) ;
return V_167 ;
}
static void F_106 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_20 ;
V_1 -> V_109 . V_110 . V_18 = NULL ;
}
static int F_107 ( struct V_1 * V_1 )
{
struct V_190 * V_142 = V_1 -> V_142 ;
struct V_17 V_18 ;
unsigned int V_219 ;
int V_141 ;
F_12 ( F_13 ( V_220 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_220 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_196 = F_11 ;
V_18 . V_20 = V_1 ;
V_18 . V_199 = F_106 ;
if ( ( V_141 = F_110 ( V_142 , & V_18 , & V_1 -> V_109 . V_110 . V_18 ) ) < 0 )
return V_141 ;
for ( V_219 = 0 ; V_219 < V_221 ; V_219 ++ ) {
V_141 = F_102 ( V_142 , F_101 ( & V_222 [ V_219 ] , V_1 ) ) ;
if ( V_141 < 0 )
return V_141 ;
}
return 0 ;
}
static int F_111 ( int V_223 )
{
switch ( V_224 [ V_223 ] ) {
case 0 :
case 1 :
case 0x200 :
case 0x208 :
case 0x210 :
case 0x218 :
return V_224 [ V_223 ] ;
default:
F_112 ( V_6 L_11 , V_224 [ V_223 ] ) ;
return 0 ;
}
}
static inline int F_111 ( int V_223 )
{
return V_225 [ V_223 ] ? 0x200 : 0 ;
}
static int F_113 ( struct V_1 * V_1 , int V_223 )
{
struct V_226 * V_227 ;
int V_228 ;
V_228 = F_111 ( V_223 ) ;
switch ( V_228 ) {
case 0 :
return - V_229 ;
case 1 :
for ( V_228 = 0x200 ; V_228 <= 0x218 ; V_228 += 8 )
if ( F_114 ( V_228 , 8 , L_12 ) )
break;
if ( V_228 > 0x218 ) {
F_112 ( V_230 L_13 ) ;
return - V_231 ;
}
break;
default:
if ( ! F_114 ( V_228 , 8 , L_12 ) ) {
F_112 ( V_230 L_14 ,
V_228 ) ;
return - V_231 ;
}
break;
}
V_1 -> V_226 = V_227 = F_115 () ;
if ( ! V_227 ) {
F_112 ( V_6 L_15 ) ;
F_116 ( V_228 , 8 ) ;
return - V_209 ;
}
F_117 ( V_227 , L_16 ) ;
F_118 ( V_227 , L_17 , F_119 ( V_1 -> V_26 ) ) ;
F_120 ( V_227 , & V_1 -> V_26 -> V_223 ) ;
V_227 -> V_232 = V_228 ;
V_1 -> V_75 |= V_233 ;
#ifdef F_45
V_1 -> V_75 &= ~ V_234 ;
V_1 -> V_75 |= F_121 ( ( V_228 - 0x200 ) / 8 ) ;
#endif
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_122 ( V_1 -> V_226 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_1 )
{
if ( V_1 -> V_226 ) {
int V_235 = V_1 -> V_226 -> V_232 ;
F_124 ( V_1 -> V_226 ) ;
V_1 -> V_226 = NULL ;
V_1 -> V_75 &= ~ V_233 ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_116 ( V_235 , 8 ) ;
}
}
static inline int F_113 ( struct V_1 * V_1 , long V_235 ) { return - V_229 ; }
static inline void F_123 ( struct V_1 * V_1 ) { }
static void F_125 ( struct V_236 * V_237 ,
struct V_238 * V_239 )
{
struct V_1 * V_1 = V_237 -> V_20 ;
F_126 ( V_239 , L_18 V_143 L_19 ) ;
F_126 ( V_239 , L_20 ,
V_1 -> V_75 & V_233 ? L_21 : L_22 ) ;
#ifdef F_48
F_126 ( V_239 , L_23 ,
V_1 -> V_75 & V_240 ? L_21 : L_22 ) ;
F_126 ( V_239 , L_24 ,
V_1 -> V_75 & V_241 ? L_21 : L_22 ) ;
#else
F_126 ( V_239 , L_25 ,
( F_127 ( V_1 -> V_75 ) * 8 ) + 0x200 ) ;
#endif
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_236 * V_237 ;
if ( ! F_129 ( V_1 -> V_142 , L_26 , & V_237 ) )
F_130 ( V_237 , V_1 , F_125 ) ;
}
static int F_131 ( struct V_1 * V_1 )
{
F_123 ( V_1 ) ;
if ( V_1 -> V_242 < 0 )
goto V_243;
#ifdef F_48
F_8 ( V_244 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_69 ) ) ;
#else
F_8 ( 0 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_69 ) ) ;
#endif
if ( V_1 -> V_242 >= 0 )
F_132 ( V_1 -> V_242 ) ;
F_133 ( V_1 -> V_26 , V_245 ) ;
V_243:
#ifdef F_48
if ( V_1 -> V_246 . V_247 )
F_134 ( & V_1 -> V_246 ) ;
#endif
if ( V_1 -> V_242 >= 0 )
F_135 ( V_1 -> V_242 , V_1 ) ;
F_136 ( V_1 -> V_26 ) ;
F_137 ( V_1 -> V_26 ) ;
F_138 ( V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_248 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_249 ;
return F_131 ( V_1 ) ;
}
static void F_140 ( struct V_1 * V_1 )
{
#ifdef F_45
int V_219 ;
#endif
#ifdef F_48
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( F_46 ( V_117 ) , F_3 ( V_1 , V_87 ) ) ;
F_8 ( V_1 -> V_246 . V_250 , F_3 ( V_1 , V_251 ) ) ;
F_8 ( 0 , F_3 ( V_1 , V_252 ) ) ;
#else
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_LEGACY ) ) ;
if ( F_97 ( V_1 , V_253 ) ) {
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_24 ) ) ;
F_25 ( 20 ) ;
}
F_8 ( V_1 -> V_75 | V_254 , F_3 ( V_1 , V_38 ) ) ;
F_2 ( F_3 ( V_1 , V_38 ) ) ;
F_109 ( 20 ) ;
F_8 ( V_1 -> V_75 , F_3 ( V_1 , V_38 ) ) ;
F_1 ( V_1 ) ;
F_8 ( V_11 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
for ( V_219 = 0 ; V_219 < 0x80 ; V_219 ++ )
F_9 ( V_1 , V_219 , 0 ) ;
F_9 ( V_1 , V_52 + V_48 , 16 << 4 ) ;
F_9 ( V_1 , V_52 + V_49 , 16 << 10 ) ;
F_9 ( V_1 , V_53 + V_48 , 16 << 4 ) ;
F_9 ( V_1 , V_53 + V_49 , 16 << 10 ) ;
F_9 ( V_1 , V_51 , 1 << 12 ) ;
F_9 ( V_1 , V_51 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_255 , 1 << 12 ) ;
F_9 ( V_1 , V_255 + 1 , 1 << 12 ) ;
F_9 ( V_1 , V_256 , 1 << 12 ) ;
F_9 ( V_1 , V_256 + 1 , 1 << 12 ) ;
F_26 ( V_1 , 22050 ) ;
F_27 ( V_1 , 22050 ) ;
F_28 ( V_1 , 22050 ) ;
F_1 ( V_1 ) ;
F_8 ( 0 , F_3 ( V_1 , 1371_SMPRATE ) ) ;
F_8 ( F_19 ( 0 , 0 ) , F_3 ( V_1 , 1371_CODEC ) ) ;
#endif
F_141 ( V_1 -> V_257 = 0x00 , F_3 ( V_1 , V_258 ) ) ;
F_141 ( 0x00 , F_3 ( V_1 , V_259 ) ) ;
F_8 ( V_1 -> V_174 , F_3 ( V_1 , V_24 ) ) ;
F_132 ( V_1 -> V_242 ) ;
}
static int F_142 ( struct V_27 * V_223 )
{
struct V_260 * V_26 = F_143 ( V_223 ) ;
struct V_190 * V_142 = F_144 ( V_223 ) ;
struct V_1 * V_1 = V_142 -> V_20 ;
F_145 ( V_142 , V_261 ) ;
F_146 ( V_1 -> V_151 ) ;
F_146 ( V_1 -> V_155 ) ;
#ifdef F_45
F_147 ( V_1 -> V_109 . V_180 . V_29 ) ;
#else
F_12 ( F_13 ( V_220 , 0x02 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_12 ( F_13 ( V_220 , 0x03 ) , F_3 ( V_1 , 1370_CODEC ) ) ;
F_108 ( F_3 ( V_1 , 1370_CODEC ) ) ;
F_109 ( 100 ) ;
F_148 ( V_1 -> V_109 . V_110 . V_18 ) ;
#endif
F_137 ( V_26 ) ;
F_149 ( V_26 ) ;
F_133 ( V_26 , V_245 ) ;
return 0 ;
}
static int F_150 ( struct V_27 * V_223 )
{
struct V_260 * V_26 = F_143 ( V_223 ) ;
struct V_190 * V_142 = F_144 ( V_223 ) ;
struct V_1 * V_1 = V_142 -> V_20 ;
F_133 ( V_26 , V_262 ) ;
F_151 ( V_26 ) ;
if ( F_152 ( V_26 ) < 0 ) {
F_112 (KERN_ERR DRIVER_NAME L_27
L_28 ) ;
F_153 ( V_142 ) ;
return - V_263 ;
}
F_154 ( V_26 ) ;
F_140 ( V_1 ) ;
#ifdef F_45
F_155 ( V_1 -> V_109 . V_180 . V_29 ) ;
#else
F_156 ( V_1 -> V_109 . V_110 . V_18 ) ;
#endif
F_145 ( V_142 , V_264 ) ;
return 0 ;
}
static int F_157 ( struct V_190 * V_142 ,
struct V_260 * V_26 ,
struct V_1 * * V_265 )
{
struct V_1 * V_1 ;
int V_141 ;
static struct V_266 V_195 = {
. V_267 = F_139 ,
} ;
* V_265 = NULL ;
if ( ( V_141 = F_152 ( V_26 ) ) < 0 )
return V_141 ;
V_1 = F_158 ( sizeof( * V_1 ) , V_268 ) ;
if ( V_1 == NULL ) {
F_137 ( V_26 ) ;
return - V_209 ;
}
F_159 ( & V_1 -> V_67 ) ;
F_160 ( & V_1 -> V_33 ) ;
V_1 -> V_142 = V_142 ;
V_1 -> V_26 = V_26 ;
V_1 -> V_242 = - 1 ;
if ( ( V_141 = F_161 ( V_26 , L_29 ) ) < 0 ) {
F_138 ( V_1 ) ;
F_137 ( V_26 ) ;
return V_141 ;
}
V_1 -> V_235 = F_162 ( V_26 , 0 ) ;
if ( F_163 ( V_26 -> V_242 , V_269 , V_270 ,
V_271 , V_1 ) ) {
F_5 ( V_6 L_30 , V_26 -> V_242 ) ;
F_131 ( V_1 ) ;
return - V_231 ;
}
V_1 -> V_242 = V_26 -> V_242 ;
#ifdef F_48
if ( F_164 ( V_152 , F_79 ( V_26 ) ,
16 , & V_1 -> V_246 ) < 0 ) {
F_5 ( V_6 L_31 ) ;
F_131 ( V_1 ) ;
return - V_231 ;
}
#endif
F_154 ( V_26 ) ;
V_1 -> V_187 = V_26 -> V_272 ;
#ifdef F_48
#if 0
ensoniq->ctrl = ES_1370_CDC_EN | ES_1370_SERR_DISABLE |
ES_1370_PCLKDIVO(ES_1370_SRTODIV(8000));
#else
V_1 -> V_75 = V_273 | F_56 ( F_57 ( 8000 ) ) ;
#endif
V_1 -> V_68 = 0 ;
#else
V_1 -> V_75 = 0 ;
V_1 -> V_68 = 0 ;
V_1 -> V_174 = 0 ;
if ( F_103 ( V_26 , V_274 ) )
V_1 -> V_75 |= F_95 ( 1 ) ;
if ( F_97 ( V_1 , V_253 ) )
V_1 -> V_174 |= V_275 ;
#endif
F_140 ( V_1 ) ;
if ( ( V_141 = F_165 ( V_142 , V_276 , V_1 , & V_195 ) ) < 0 ) {
F_131 ( V_1 ) ;
return V_141 ;
}
F_128 ( V_1 ) ;
F_166 ( V_142 , & V_26 -> V_223 ) ;
* V_265 = V_1 ;
return 0 ;
}
static void F_167 ( struct V_1 * V_1 )
{
struct V_277 * V_278 = V_1 -> V_278 ;
unsigned char V_166 , V_216 , V_279 ;
if ( V_278 == NULL )
return;
F_33 ( & V_1 -> V_67 ) ;
V_216 = V_1 -> V_280 & V_281 ? V_282 : 0 ;
while ( V_216 ) {
V_166 = F_168 ( F_3 ( V_1 , V_283 ) ) ;
if ( ( V_166 & V_216 ) == 0 )
break;
V_279 = F_168 ( F_3 ( V_1 , V_284 ) ) ;
F_169 ( V_1 -> V_285 , & V_279 , 1 ) ;
}
F_34 ( & V_1 -> V_67 ) ;
F_33 ( & V_1 -> V_67 ) ;
V_216 = V_1 -> V_280 & V_286 ? V_287 : 0 ;
while ( V_216 ) {
V_166 = F_168 ( F_3 ( V_1 , V_283 ) ) ;
if ( ( V_166 & V_216 ) == 0 )
break;
if ( F_170 ( V_1 -> V_288 , & V_279 , 1 ) != 1 ) {
V_1 -> V_257 &= ~ V_289 ;
F_141 ( V_1 -> V_257 , F_3 ( V_1 , V_258 ) ) ;
V_216 &= ~ V_287 ;
} else {
F_141 ( V_279 , F_3 ( V_1 , V_284 ) ) ;
}
}
F_34 ( & V_1 -> V_67 ) ;
}
static int F_171 ( struct V_290 * V_55 )
{
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
F_44 ( & V_1 -> V_67 ) ;
V_1 -> V_280 |= V_281 ;
V_1 -> V_285 = V_55 ;
if ( ! ( V_1 -> V_280 & V_286 ) ) {
F_141 ( F_172 ( 3 ) , F_3 ( V_1 , V_258 ) ) ;
F_141 ( V_1 -> V_257 = 0 , F_3 ( V_1 , V_258 ) ) ;
F_8 ( V_1 -> V_75 |= V_291 , F_3 ( V_1 , V_38 ) ) ;
}
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_173 ( struct V_290 * V_55 )
{
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
F_44 ( & V_1 -> V_67 ) ;
if ( ! ( V_1 -> V_280 & V_286 ) ) {
F_141 ( V_1 -> V_257 = 0 , F_3 ( V_1 , V_258 ) ) ;
F_8 ( V_1 -> V_75 &= ~ V_291 , F_3 ( V_1 , V_38 ) ) ;
} else {
F_141 ( V_1 -> V_257 &= ~ V_292 , F_3 ( V_1 , V_258 ) ) ;
}
V_1 -> V_285 = NULL ;
V_1 -> V_280 &= ~ V_281 ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_174 ( struct V_290 * V_55 )
{
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
F_44 ( & V_1 -> V_67 ) ;
V_1 -> V_280 |= V_286 ;
V_1 -> V_288 = V_55 ;
if ( ! ( V_1 -> V_280 & V_281 ) ) {
F_141 ( F_172 ( 3 ) , F_3 ( V_1 , V_258 ) ) ;
F_141 ( V_1 -> V_257 = 0 , F_3 ( V_1 , V_258 ) ) ;
F_8 ( V_1 -> V_75 |= V_291 , F_3 ( V_1 , V_38 ) ) ;
}
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int F_175 ( struct V_290 * V_55 )
{
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
F_44 ( & V_1 -> V_67 ) ;
if ( ! ( V_1 -> V_280 & V_281 ) ) {
F_141 ( V_1 -> V_257 = 0 , F_3 ( V_1 , V_258 ) ) ;
F_8 ( V_1 -> V_75 &= ~ V_291 , F_3 ( V_1 , V_38 ) ) ;
} else {
F_141 ( V_1 -> V_257 &= ~ V_289 , F_3 ( V_1 , V_258 ) ) ;
}
V_1 -> V_288 = NULL ;
V_1 -> V_280 &= ~ V_286 ;
F_51 ( & V_1 -> V_67 ) ;
return 0 ;
}
static void F_176 ( struct V_290 * V_55 , int V_293 )
{
unsigned long V_294 ;
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
int V_219 ;
F_177 ( & V_1 -> V_67 , V_294 ) ;
if ( V_293 ) {
if ( ( V_1 -> V_257 & V_292 ) == 0 ) {
for ( V_219 = 0 ; V_219 < 32 ; V_219 ++ )
F_168 ( F_3 ( V_1 , V_284 ) ) ;
V_1 -> V_257 |= V_292 ;
F_141 ( V_1 -> V_257 , F_3 ( V_1 , V_258 ) ) ;
}
} else {
if ( V_1 -> V_257 & V_292 ) {
V_1 -> V_257 &= ~ V_292 ;
F_141 ( V_1 -> V_257 , F_3 ( V_1 , V_258 ) ) ;
}
}
F_178 ( & V_1 -> V_67 , V_294 ) ;
}
static void F_179 ( struct V_290 * V_55 , int V_293 )
{
unsigned long V_294 ;
struct V_1 * V_1 = V_55 -> V_278 -> V_20 ;
unsigned char V_279 ;
F_177 ( & V_1 -> V_67 , V_294 ) ;
if ( V_293 ) {
if ( F_180 ( V_1 -> V_257 ) == 0 ) {
V_1 -> V_257 |= F_181 ( 1 ) ;
while ( F_180 ( V_1 -> V_257 ) == 1 &&
( F_168 ( F_3 ( V_1 , V_283 ) ) & V_287 ) ) {
if ( F_170 ( V_55 , & V_279 , 1 ) != 1 ) {
V_1 -> V_257 &= ~ V_289 ;
} else {
F_141 ( V_279 , F_3 ( V_1 , V_284 ) ) ;
}
}
F_141 ( V_1 -> V_257 , F_3 ( V_1 , V_258 ) ) ;
}
} else {
if ( F_180 ( V_1 -> V_257 ) == 1 ) {
V_1 -> V_257 &= ~ V_289 ;
F_141 ( V_1 -> V_257 , F_3 ( V_1 , V_258 ) ) ;
}
}
F_178 ( & V_1 -> V_67 , V_294 ) ;
}
static int F_182 ( struct V_1 * V_1 , int V_27 ,
struct V_277 * * V_295 )
{
struct V_277 * V_278 ;
int V_141 ;
if ( V_295 )
* V_295 = NULL ;
if ( ( V_141 = F_183 ( V_1 -> V_142 , L_32 , V_27 , 1 , 1 , & V_278 ) ) < 0 )
return V_141 ;
strcpy ( V_278 -> V_150 , V_143 ) ;
F_184 ( V_278 , V_296 , & V_297 ) ;
F_184 ( V_278 , V_298 , & V_299 ) ;
V_278 -> V_149 |= V_300 | V_301 |
V_302 ;
V_278 -> V_20 = V_1 ;
V_1 -> V_278 = V_278 ;
if ( V_295 )
* V_295 = V_278 ;
return 0 ;
}
static T_3 V_269 ( int V_242 , void * V_303 )
{
struct V_1 * V_1 = V_303 ;
unsigned int V_166 , V_68 ;
if ( V_1 == NULL )
return V_304 ;
V_166 = F_2 ( F_3 ( V_1 , V_24 ) ) ;
if ( ! ( V_166 & V_305 ) )
return V_304 ;
F_33 ( & V_1 -> V_67 ) ;
V_68 = V_1 -> V_68 ;
if ( V_166 & V_306 )
V_68 &= ~ V_94 ;
if ( V_166 & V_307 )
V_68 &= ~ V_107 ;
if ( V_166 & V_308 )
V_68 &= ~ V_122 ;
F_8 ( V_68 , F_3 ( V_1 , V_69 ) ) ;
F_8 ( V_1 -> V_68 , F_3 ( V_1 , V_69 ) ) ;
F_34 ( & V_1 -> V_67 ) ;
if ( V_166 & V_309 )
F_167 ( V_1 ) ;
if ( ( V_166 & V_307 ) && V_1 -> V_63 )
F_185 ( V_1 -> V_63 ) ;
if ( ( V_166 & V_308 ) && V_1 -> V_65 )
F_185 ( V_1 -> V_65 ) ;
if ( ( V_166 & V_306 ) && V_1 -> V_61 )
F_185 ( V_1 -> V_61 ) ;
return V_310 ;
}
static int F_186 ( struct V_260 * V_26 ,
const struct V_311 * V_312 )
{
static int V_223 ;
struct V_190 * V_142 ;
struct V_1 * V_1 ;
int V_141 , V_313 [ 2 ] ;
if ( V_223 >= V_314 )
return - V_315 ;
if ( ! V_316 [ V_223 ] ) {
V_223 ++ ;
return - V_317 ;
}
V_141 = F_187 ( V_211 [ V_223 ] , V_210 [ V_223 ] , V_318 , 0 , & V_142 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ( V_141 = F_157 ( V_142 , V_26 , & V_1 ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
V_142 -> V_20 = V_1 ;
V_313 [ 0 ] = 0 ; V_313 [ 1 ] = 1 ;
#ifdef F_48
if ( ( V_141 = F_107 ( V_1 ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
#endif
#ifdef F_45
if ( ( V_141 = F_98 ( V_1 , V_128 [ V_223 ] , V_319 [ V_223 ] ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
#endif
if ( ( V_141 = F_75 ( V_1 , 0 , NULL ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
if ( ( V_141 = F_81 ( V_1 , 1 , NULL ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
if ( ( V_141 = F_182 ( V_1 , 0 , NULL ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
F_113 ( V_1 , V_223 ) ;
strcpy ( V_142 -> V_320 , V_321 ) ;
strcpy ( V_142 -> V_322 , L_29 ) ;
sprintf ( V_142 -> V_323 , L_33 ,
V_142 -> V_322 ,
V_142 -> V_320 ,
V_1 -> V_235 ,
V_1 -> V_242 ) ;
if ( ( V_141 = F_189 ( V_142 ) ) < 0 ) {
F_188 ( V_142 ) ;
return V_141 ;
}
F_190 ( V_26 , V_142 ) ;
V_223 ++ ;
return 0 ;
}
static void F_191 ( struct V_260 * V_26 )
{
F_188 ( F_192 ( V_26 ) ) ;
}
