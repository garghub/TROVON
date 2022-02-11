static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_3 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_13 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_10 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_7 )
{
int time ;
if ( V_7 > 2 )
return - V_8 ;
if ( V_2 -> V_9 ) {
V_7 = V_2 -> V_10 ;
} else {
V_7 = V_2 -> V_11 [ V_2 -> V_12 [ V_7 ] ] ;
}
if ( ( F_5 ( V_2 , F_16 ( V_13 ) ) & V_7 ) == 0 )
return - V_8 ;
if ( V_2 -> V_14 )
return 0 ;
time = 100 ;
do {
if ( ! ( F_1 ( V_2 , F_16 ( V_15 ) ) & V_16 ) )
return 0 ;
F_17 ( 10 ) ;
} while ( time -- );
F_18 ( V_2 -> V_17 -> V_18 ,
L_1 ,
F_1 ( V_2 , F_16 ( V_15 ) ) , F_5 ( V_2 , F_16 ( V_13 ) ) ) ;
F_13 ( V_2 , 0 ) ;
return - V_19 ;
}
static void F_19 ( struct V_20 * V_21 ,
unsigned short V_22 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( F_15 ( V_2 , V_21 -> V_24 ) < 0 ) {
if ( ! V_2 -> V_25 )
F_18 ( V_2 -> V_17 -> V_18 ,
L_2 ,
V_21 -> V_24 , V_22 ) ;
}
F_14 ( V_2 , V_22 + V_21 -> V_24 * 0x80 , V_5 ) ;
}
static unsigned short F_20 ( struct V_20 * V_21 ,
unsigned short V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
unsigned short V_26 ;
unsigned int V_27 ;
if ( F_15 ( V_2 , V_21 -> V_24 ) < 0 ) {
if ( ! V_2 -> V_25 )
F_18 ( V_2 -> V_17 -> V_18 ,
L_3 ,
V_21 -> V_24 , V_22 ) ;
V_26 = 0xffff ;
} else {
V_26 = F_13 ( V_2 , V_22 + V_21 -> V_24 * 0x80 ) ;
if ( ( V_27 = F_5 ( V_2 , F_16 ( V_13 ) ) ) & V_28 ) {
F_11 ( V_2 , F_16 ( V_13 ) , V_27 &
~ ( V_2 -> V_29 | V_30 ) ) ;
if ( ! V_2 -> V_25 )
F_18 ( V_2 -> V_17 -> V_18 ,
L_4 ,
V_21 -> V_24 , V_22 ) ;
V_26 = 0xffff ;
}
}
return V_26 ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
unsigned int V_27 ;
if ( F_15 ( V_2 , V_7 ) >= 0 ) {
F_13 ( V_2 , V_7 * 0x80 ) ;
if ( ( V_27 = F_5 ( V_2 , F_16 ( V_13 ) ) ) & V_28 ) {
F_11 ( V_2 , F_16 ( V_13 ) , V_27 &
~ ( V_2 -> V_29 | V_30 ) ) ;
}
}
}
static int F_22 ( struct V_1 * V_2 , int V_31 )
{
int V_32 = 0 ;
for ( V_32 = 0 ; V_32 < 0x7f ; V_32 ++ ) {
int V_5 = F_1 ( V_2 , F_16 ( V_33 ) ) ;
if ( V_5 & V_31 )
return 0 ;
}
if ( ! V_2 -> V_25 )
F_23 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return - V_19 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int time = 100 ;
if ( V_2 -> V_14 )
return 0 ;
while ( -- time && ( F_5 ( V_2 , F_16 ( V_34 ) ) & V_35 ) )
F_17 ( 1 ) ;
if ( ! time && ! V_2 -> V_25 )
F_23 ( V_2 -> V_17 -> V_18 , L_6 ) ;
return F_22 ( V_2 , V_36 ) ;
}
static unsigned short F_25 ( struct V_20 * V_21 , unsigned short V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
unsigned short V_37 = 0xffff ;
if ( F_24 ( V_2 ) )
goto V_38;
V_22 |= V_39 ;
if ( V_21 -> V_24 )
V_22 |= V_40 ;
F_9 ( V_2 , F_16 ( V_41 ) , V_22 ) ;
if ( F_22 ( V_2 , V_42 ) )
goto V_38;
V_37 = F_3 ( V_2 , F_16 ( V_43 ) ) ;
V_38:
return V_37 ;
}
static void F_26 ( struct V_20 * V_21 , unsigned short V_22 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( F_24 ( V_2 ) )
return;
F_9 ( V_2 , F_16 ( V_44 ) , V_5 ) ;
if ( V_21 -> V_24 )
V_22 |= V_40 ;
F_9 ( V_2 , F_16 ( V_41 ) , V_22 ) ;
F_22 ( V_2 , V_45 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_46 * V_46 )
{
int V_47 ;
T_2 * V_48 = V_46 -> V_48 ;
unsigned long V_49 = V_46 -> V_50 ;
F_11 ( V_2 , V_49 + V_51 , V_46 -> V_52 ) ;
if ( V_46 -> V_53 == V_46 -> V_54 ) {
V_46 -> V_55 = V_46 -> V_56 = 2 ;
V_46 -> V_57 = V_46 -> V_54 >> 1 ;
for ( V_47 = 0 ; V_47 < ( V_58 + 1 ) * 2 ; V_47 += 4 ) {
V_48 [ V_47 + 0 ] = F_28 ( V_46 -> V_59 ) ;
V_48 [ V_47 + 1 ] = F_28 ( 0x80000000 |
V_46 -> V_57 >> V_46 -> V_60 ) ;
V_48 [ V_47 + 2 ] = F_28 ( V_46 -> V_59 + ( V_46 -> V_53 >> 1 ) ) ;
V_48 [ V_47 + 3 ] = F_28 ( 0x80000000 |
V_46 -> V_57 >> V_46 -> V_60 ) ;
}
V_46 -> V_61 = 2 ;
} else {
V_46 -> V_55 = V_46 -> V_56 = 1 ;
V_46 -> V_57 = V_46 -> V_54 ;
for ( V_47 = 0 ; V_47 < ( V_58 + 1 ) * 2 ; V_47 += 2 ) {
V_48 [ V_47 + 0 ] = F_28 ( V_46 -> V_59 +
( ( ( V_47 >> 1 ) * V_46 -> V_54 ) %
V_46 -> V_53 ) ) ;
V_48 [ V_47 + 1 ] = F_28 ( 0x80000000 |
V_46 -> V_54 >> V_46 -> V_60 ) ;
#if 0
dev_dbg(chip->card->dev, "bdbar[%i] = 0x%x [0x%x]\n",
idx + 0, bdbar[idx + 0], bdbar[idx + 1]);
#endif
}
V_46 -> V_61 = V_46 -> V_53 / V_46 -> V_54 ;
}
F_7 ( V_2 , V_49 + V_62 , V_46 -> V_63 = V_58 ) ;
V_46 -> V_64 = 0 ;
F_7 ( V_2 , V_49 + V_65 , 0 ) ;
V_46 -> V_66 = V_58 % V_46 -> V_61 ;
V_46 -> V_67 = 0 ;
#if 0
dev_dbg(chip->card->dev,
"lvi_frag = %i, frags = %i, period_size = 0x%x, period_size1 = 0x%x\n",
ichdev->lvi_frag, ichdev->frags, ichdev->fragsize,
ichdev->fragsize1);
#endif
F_7 ( V_2 , V_49 + V_46 -> V_68 , V_69 | V_70 | V_71 ) ;
}
static void F_29 ( void * V_72 , int V_53 , int V_73 )
{
V_53 = ( V_53 + V_74 - 1 ) >> V_75 ;
if ( V_73 )
F_30 ( F_31 ( V_72 ) , V_53 ) ;
else
F_32 ( F_31 ( V_72 ) , V_53 ) ;
}
static inline void F_33 ( struct V_1 * V_2 , struct V_46 * V_46 )
{
unsigned long V_49 = V_46 -> V_50 ;
unsigned long V_76 ;
int V_77 , V_64 , V_78 , V_79 ;
int V_56 = 0 ;
F_34 ( & V_2 -> V_80 , V_76 ) ;
V_77 = F_1 ( V_2 , V_49 + V_46 -> V_68 ) ;
V_64 = F_1 ( V_2 , V_49 + V_65 ) ;
if ( ! ( V_77 & V_70 ) ) {
V_79 = 0 ;
} else if ( V_64 == V_46 -> V_64 ) {
V_79 = 1 ;
V_46 -> V_64 ++ ;
V_46 -> V_64 &= V_58 ;
} else {
V_79 = V_64 - V_46 -> V_64 ;
if ( V_79 < 0 )
V_79 += V_58 + 1 ;
V_46 -> V_64 = V_64 ;
}
V_46 -> V_67 += V_79 * V_46 -> V_57 ;
if ( ! V_2 -> V_81 )
V_46 -> V_67 %= V_46 -> V_53 ;
V_46 -> V_63 += V_79 ;
V_46 -> V_63 &= V_58 ;
F_7 ( V_2 , V_49 + V_62 , V_46 -> V_63 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
V_46 -> V_66 ++ ;
V_46 -> V_66 %= V_46 -> V_61 ;
V_46 -> V_48 [ V_46 -> V_63 * 2 ] = F_28 ( V_46 -> V_59 + V_46 -> V_66 * V_46 -> V_57 ) ;
#if 0
dev_dbg(chip->card->dev,
"new: bdbar[%i] = 0x%x [0x%x], prefetch = %i, all = 0x%x, 0x%x\n",
ichdev->lvi * 2, ichdev->bdbar[ichdev->lvi * 2],
ichdev->bdbar[ichdev->lvi * 2 + 1], inb(ICH_REG_OFF_PIV + port),
inl(port + 4), inb(port + ICH_REG_OFF_CR));
#endif
if ( -- V_46 -> V_56 == 0 ) {
V_46 -> V_56 = V_46 -> V_55 ;
V_56 = 1 ;
}
}
F_35 ( & V_2 -> V_80 , V_76 ) ;
if ( V_56 && V_46 -> V_82 ) {
F_36 ( V_46 -> V_82 ) ;
}
F_7 ( V_2 , V_49 + V_46 -> V_68 ,
V_77 & ( V_69 | V_70 | V_71 ) ) ;
}
static T_4 F_37 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_46 * V_46 ;
unsigned int V_77 ;
unsigned int V_78 ;
V_77 = F_5 ( V_2 , V_2 -> V_85 ) ;
if ( V_77 == 0xffffffff )
return V_86 ;
if ( ( V_77 & V_2 -> V_87 ) == 0 ) {
if ( V_77 ) {
F_11 ( V_2 , V_2 -> V_85 , V_77 ) ;
if ( ! V_2 -> V_88 )
V_77 = 0 ;
}
return F_38 ( V_77 ) ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_46 = & V_2 -> V_90 [ V_78 ] ;
if ( V_77 & V_46 -> V_87 )
F_33 ( V_2 , V_46 ) ;
}
F_11 ( V_2 , V_2 -> V_85 , V_77 & V_2 -> V_87 ) ;
return V_91 ;
}
static int F_39 ( struct V_92 * V_82 , int V_93 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
unsigned char V_5 = 0 ;
unsigned long V_49 = V_46 -> V_50 ;
switch ( V_93 ) {
case V_94 :
V_46 -> V_95 = 0 ;
case V_96 :
case V_97 :
V_5 = V_98 | V_99 ;
V_46 -> V_100 = V_46 -> V_67 ;
break;
case V_101 :
V_46 -> V_95 = 1 ;
case V_102 :
V_5 = 0 ;
break;
case V_103 :
V_5 = V_98 ;
break;
default:
return - V_104 ;
}
F_7 ( V_2 , V_49 + V_105 , V_5 ) ;
if ( V_93 == V_102 ) {
while ( ! ( F_1 ( V_2 , V_49 + V_46 -> V_68 ) & V_106 ) ) ;
F_7 ( V_2 , V_49 + V_105 , V_107 ) ;
}
return 0 ;
}
static int F_42 ( struct V_92 * V_82 , int V_93 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
unsigned long V_49 = V_46 -> V_50 ;
static int V_108 [] = {
F_16 ( V_109 ) , F_16 ( V_110 ) , F_16 (ALI_FIFOCR3)
} ;
unsigned int V_5 , V_111 ;
V_5 = F_5 ( V_2 , F_16 ( V_112 ) ) ;
switch ( V_93 ) {
case V_94 :
V_46 -> V_95 = 0 ;
case V_96 :
case V_97 :
if ( V_82 -> V_113 == V_114 ) {
V_111 = F_5 ( V_2 , V_108 [ V_46 -> V_115 / 4 ] ) ;
V_111 &= ~ ( 0xff << ( V_46 -> V_115 % 4 ) ) ;
V_111 |= 0x83 << ( V_46 -> V_115 % 4 ) ;
F_11 ( V_2 , V_108 [ V_46 -> V_115 / 4 ] , V_111 ) ;
}
F_7 ( V_2 , V_49 + V_105 , V_98 ) ;
V_5 &= ~ ( 1 << ( V_46 -> V_115 + 16 ) ) ;
F_11 ( V_2 , F_16 ( V_112 ) , V_5 | ( 1 << V_46 -> V_115 ) ) ;
break;
case V_101 :
V_46 -> V_95 = 1 ;
case V_102 :
case V_103 :
F_11 ( V_2 , F_16 ( V_112 ) , V_5 | ( 1 << ( V_46 -> V_115 + 16 ) ) ) ;
F_7 ( V_2 , V_49 + V_105 , 0 ) ;
while ( F_1 ( V_2 , V_49 + V_105 ) )
;
if ( V_93 == V_103 )
break;
F_7 ( V_2 , V_49 + V_105 , V_107 ) ;
F_7 ( V_2 , V_49 + V_116 ,
F_1 ( V_2 , V_49 + V_116 ) | 0x1e ) ;
F_11 ( V_2 , F_16 ( V_117 ) ,
F_5 ( V_2 , F_16 ( V_117 ) ) & V_46 -> V_87 ) ;
break;
default:
return - V_104 ;
}
return 0 ;
}
static int F_43 ( struct V_92 * V_82 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
struct V_120 * V_121 = V_82 -> V_121 ;
int V_122 = F_44 ( V_119 ) > 48000 ;
int V_123 ;
if ( V_2 -> V_124 && V_46 -> V_125 ) {
F_29 ( V_121 -> V_126 , V_121 -> V_127 , 0 ) ;
V_46 -> V_125 = 0 ;
}
V_123 = F_45 ( V_82 , F_46 ( V_119 ) ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_2 -> V_124 ) {
if ( V_121 -> V_126 && ! V_46 -> V_125 ) {
F_29 ( V_121 -> V_126 , V_121 -> V_127 , 1 ) ;
V_46 -> V_125 = 1 ;
}
}
if ( V_46 -> V_128 ) {
F_47 ( V_46 -> V_129 ) ;
V_46 -> V_128 = 0 ;
}
V_123 = F_48 ( V_46 -> V_129 , F_44 ( V_119 ) ,
F_49 ( V_119 ) ,
V_46 -> V_129 -> V_130 [ V_122 ] . V_131 ) ;
if ( V_123 >= 0 ) {
V_46 -> V_128 = 1 ;
if ( V_46 -> V_90 == V_132 && V_2 -> V_133 < 0 )
F_50 ( V_46 -> V_129 -> V_130 [ 0 ] . V_7 [ 0 ] , V_134 ,
F_44 ( V_119 ) ) ;
}
return V_123 ;
}
static int F_51 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
if ( V_46 -> V_128 ) {
F_47 ( V_46 -> V_129 ) ;
V_46 -> V_128 = 0 ;
}
if ( V_2 -> V_124 && V_46 -> V_125 ) {
F_29 ( V_82 -> V_121 -> V_126 , V_82 -> V_121 -> V_127 , 0 ) ;
V_46 -> V_125 = 0 ;
}
return F_52 ( V_82 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
unsigned int V_135 ;
int V_122 = V_121 -> V_136 > 48000 ;
F_54 ( & V_2 -> V_80 ) ;
switch ( V_2 -> V_137 ) {
case V_138 :
V_135 = F_5 ( V_2 , F_16 ( V_139 ) ) ;
V_135 &= ~ V_140 ;
if ( V_121 -> V_141 == 4 || V_122 )
V_135 |= V_142 ;
else if ( V_121 -> V_141 == 6 )
V_135 |= V_143 ;
F_11 ( V_2 , F_16 ( V_139 ) , V_135 ) ;
break;
case V_144 :
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ V_146 ;
if ( V_121 -> V_141 == 4 || V_122 )
V_135 |= V_147 ;
else if ( V_121 -> V_141 == 6 )
V_135 |= V_148 ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 ) ;
break;
default:
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ ( V_149 | V_150 ) ;
if ( V_121 -> V_141 == 4 || V_122 )
V_135 |= V_151 ;
else if ( V_121 -> V_141 == 6 )
V_135 |= V_152 ;
else if ( V_121 -> V_141 == 8 )
V_135 |= V_153 ;
if ( V_2 -> V_137 == V_154 ) {
if ( V_135 & V_149 ) {
F_11 ( V_2 , F_16 ( V_145 ) , V_135 & ~ V_149 ) ;
F_55 ( & V_2 -> V_80 ) ;
F_56 ( 50 ) ;
F_54 ( & V_2 -> V_80 ) ;
}
} else if ( V_2 -> V_137 == V_155 ) {
if ( V_121 -> V_156 > 16 )
V_135 |= V_150 ;
}
F_11 ( V_2 , F_16 ( V_145 ) , V_135 ) ;
break;
}
F_55 ( & V_2 -> V_80 ) ;
}
static int F_57 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_120 * V_121 = V_82 -> V_121 ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
V_46 -> V_59 = V_121 -> V_157 ;
V_46 -> V_53 = F_58 ( V_82 ) ;
V_46 -> V_54 = F_59 ( V_82 ) ;
if ( V_46 -> V_90 == V_132 ) {
F_53 ( V_2 , V_121 ) ;
if ( V_2 -> V_137 == V_155 )
V_46 -> V_60 = ( V_121 -> V_156 > 16 ) ? 2 : 1 ;
}
F_27 ( V_2 , V_46 ) ;
return 0 ;
}
static T_5 F_60 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
T_6 V_158 , V_159 ;
int V_64 , V_160 = 10 ;
unsigned int V_67 ;
F_61 ( & V_2 -> V_80 ) ;
do {
V_64 = F_1 ( V_2 , V_46 -> V_50 + V_65 ) ;
V_158 = F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) ;
V_67 = V_46 -> V_67 ;
if ( V_158 == 0 ) {
F_17 ( 10 ) ;
continue;
}
if ( V_64 != F_1 ( V_2 , V_46 -> V_50 + V_65 ) )
continue;
if ( V_2 -> V_162 )
break;
if ( V_158 == F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) )
break;
} while ( V_160 -- );
V_159 = V_46 -> V_100 ;
if ( V_158 != 0 ) {
V_158 <<= V_46 -> V_60 ;
V_159 = V_46 -> V_57 - V_158 ;
V_159 += V_67 ;
if ( V_159 < V_46 -> V_100 ) {
unsigned int V_163 , V_164 ;
V_163 = V_67 / V_46 -> V_57 ;
V_164 = V_46 -> V_100 / V_46 -> V_57 ;
if ( V_163 == V_164 )
V_159 = V_46 -> V_100 ;
}
}
V_46 -> V_100 = V_159 ;
F_62 ( & V_2 -> V_80 ) ;
if ( V_159 >= V_46 -> V_53 )
return 0 ;
return F_63 ( V_82 -> V_121 , V_159 ) ;
}
static int F_64 ( struct V_92 * V_82 , struct V_46 * V_46 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_120 * V_121 = V_82 -> V_121 ;
int V_123 ;
V_46 -> V_82 = V_82 ;
V_121 -> V_165 = V_166 ;
V_121 -> V_165 . V_167 = V_46 -> V_129 -> V_167 ;
F_65 ( V_121 ) ;
if ( V_2 -> V_137 == V_144 ) {
V_121 -> V_165 . V_168 = 64 * 1024 ;
V_121 -> V_165 . V_169 = 64 * 1024 ;
}
if ( ( V_123 = F_66 ( V_121 , V_170 ) ) < 0 )
return V_123 ;
V_121 -> V_23 = V_46 ;
return 0 ;
}
static int F_67 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_120 * V_121 = V_82 -> V_121 ;
int V_123 ;
V_123 = F_64 ( V_82 , & V_2 -> V_90 [ V_132 ] ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_2 -> V_171 ) {
V_121 -> V_165 . V_172 = 8 ;
F_68 ( V_121 , 0 ,
V_173 ,
& V_174 ) ;
} else if ( V_2 -> V_175 ) {
V_121 -> V_165 . V_172 = 6 ;
F_68 ( V_121 , 0 , V_173 ,
& V_176 ) ;
} else if ( V_2 -> V_177 ) {
V_121 -> V_165 . V_172 = 4 ;
F_68 ( V_121 , 0 , V_173 ,
& V_178 ) ;
}
if ( V_2 -> V_179 ) {
F_69 ( V_121 ) ;
}
if ( V_2 -> V_180 ) {
V_121 -> V_165 . V_181 |= V_182 ;
F_70 ( V_121 , 0 , 32 , 20 ) ;
}
return 0 ;
}
static int F_71 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_132 ] . V_82 = NULL ;
return 0 ;
}
static int F_72 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_183 ] ) ;
}
static int F_73 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_183 ] . V_82 = NULL ;
return 0 ;
}
static int F_74 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_184 ] ) ;
}
static int F_75 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_184 ] . V_82 = NULL ;
return 0 ;
}
static int F_76 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_185 ] ) ;
}
static int F_77 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_185 ] . V_82 = NULL ;
return 0 ;
}
static int F_78 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_186 ] ) ;
}
static int F_79 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_186 ] . V_82 = NULL ;
return 0 ;
}
static int F_80 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
int V_47 = V_2 -> V_137 == V_154 ? V_187 : V_188 ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_47 ] ) ;
}
static int F_81 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
int V_47 = V_2 -> V_137 == V_154 ? V_187 : V_188 ;
V_2 -> V_90 [ V_47 ] . V_82 = NULL ;
return 0 ;
}
static int F_82 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
unsigned int V_5 ;
F_54 ( & V_2 -> V_80 ) ;
V_5 = F_5 ( V_2 , F_16 ( V_189 ) ) ;
V_5 |= V_190 ;
F_11 ( V_2 , F_16 ( V_189 ) , V_5 ) ;
F_55 ( & V_2 -> V_80 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_191 ] ) ;
}
static int F_83 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
unsigned int V_5 ;
V_2 -> V_90 [ V_191 ] . V_82 = NULL ;
F_54 ( & V_2 -> V_80 ) ;
V_5 = F_5 ( V_2 , F_16 ( V_189 ) ) ;
V_5 &= ~ V_190 ;
F_11 ( V_2 , F_16 ( V_189 ) , V_5 ) ;
F_55 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , int V_192 ,
struct V_193 * V_194 )
{
struct V_195 * V_129 ;
int V_123 ;
char V_196 [ 32 ] ;
if ( V_194 -> V_197 )
sprintf ( V_196 , L_7 , V_194 -> V_197 ) ;
else
strcpy ( V_196 , L_8 ) ;
V_123 = F_85 ( V_2 -> V_17 , V_196 , V_192 ,
V_194 -> V_198 ? 1 : 0 ,
V_194 -> V_199 ? 1 : 0 , & V_129 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_194 -> V_198 )
F_86 ( V_129 , V_114 , V_194 -> V_198 ) ;
if ( V_194 -> V_199 )
F_86 ( V_129 , V_200 , V_194 -> V_199 ) ;
V_129 -> V_23 = V_2 ;
V_129 -> V_201 = 0 ;
if ( V_194 -> V_197 )
sprintf ( V_129 -> V_196 , L_9 , V_2 -> V_17 -> V_202 , V_194 -> V_197 ) ;
else
strcpy ( V_129 -> V_196 , V_2 -> V_17 -> V_202 ) ;
V_2 -> V_129 [ V_192 ] = V_129 ;
F_87 ( V_129 , V_203 ,
F_88 ( V_2 -> V_204 ) ,
V_194 -> V_205 , V_194 -> V_206 ) ;
if ( V_194 -> V_198 &&
V_194 -> V_198 -> V_207 == F_67 ) {
struct V_208 * V_209 ;
int V_210 = 2 ;
if ( V_2 -> V_171 )
V_210 = 8 ;
else if ( V_2 -> V_175 )
V_210 = 6 ;
else if ( V_2 -> V_177 )
V_210 = 4 ;
V_123 = F_89 ( V_129 , V_114 ,
V_211 , V_210 , 0 ,
& V_209 ) ;
if ( V_123 < 0 )
return V_123 ;
V_209 -> V_212 = V_213 ;
V_2 -> V_21 [ 0 ] -> V_214 [ V_114 ] = V_209 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_78 , V_215 , V_192 , V_123 ;
struct V_193 * V_216 , * V_194 ;
switch ( V_2 -> V_137 ) {
case V_155 :
V_216 = V_217 ;
V_215 = F_91 ( V_217 ) ;
if ( V_218 )
V_215 -- ;
break;
case V_154 :
V_216 = V_219 ;
V_215 = F_91 ( V_219 ) ;
if ( V_218 )
V_215 -- ;
break;
case V_138 :
V_216 = V_220 ;
V_215 = F_91 ( V_220 ) ;
break;
default:
V_216 = V_217 ;
V_215 = 2 ;
break;
}
V_192 = 0 ;
for ( V_78 = 0 ; V_78 < V_215 ; V_78 ++ ) {
V_194 = V_216 + V_78 ;
if ( V_78 > 0 && V_194 -> V_221 ) {
if ( ! V_2 -> V_90 [ V_194 -> V_221 ] . V_129 )
continue;
}
V_123 = F_84 ( V_2 , V_192 , V_194 ) ;
if ( V_123 < 0 )
return V_123 ;
V_192 ++ ;
}
V_2 -> V_222 = V_192 ;
return 0 ;
}
static void F_92 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = V_224 -> V_23 ;
V_2 -> V_225 = NULL ;
}
static void F_93 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
V_2 -> V_21 [ V_21 -> V_24 ] = NULL ;
}
static int F_94 ( struct V_1 * V_2 , int V_226 ,
const char * V_227 )
{
struct V_223 * V_228 ;
struct V_229 V_21 ;
int V_123 ;
unsigned int V_78 , V_230 ;
unsigned int V_231 = 0 ;
struct V_232 * V_233 ;
static struct V_232 V_234 = {
. V_235 = F_19 ,
. V_236 = F_20 ,
} ;
static struct V_232 V_237 = {
. V_235 = F_26 ,
. V_236 = F_25 ,
} ;
V_2 -> V_133 = - 1 ;
if ( ! V_218 ) {
switch ( V_2 -> V_137 ) {
case V_154 :
V_2 -> V_133 = V_187 ;
break;
case V_138 :
V_2 -> V_133 = V_191 ;
break;
case V_155 :
V_2 -> V_133 = V_188 ;
break;
}
}
V_2 -> V_25 = 1 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_23 = V_2 ;
V_21 . V_238 = F_93 ;
V_21 . V_239 = V_240 | V_241 ;
if ( V_2 -> V_242 )
V_21 . V_239 |= V_243 ;
if ( V_2 -> V_137 != V_138 ) {
V_231 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
V_233 = & V_234 ;
V_2 -> V_9 = 1 ;
V_230 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_244 ; V_78 ++ ) {
if ( ! ( V_231 & V_2 -> V_11 [ V_78 ] ) )
continue;
if ( V_2 -> V_137 == V_155 ) {
F_21 ( V_2 , V_230 ) ;
V_2 -> V_12 [ V_230 ] =
F_1 ( V_2 , F_16 ( V_245 ) ) & V_246 ;
if ( F_95 ( V_2 -> V_12 [ V_230 ] >= 3 ) )
V_2 -> V_12 [ V_230 ] = 0 ;
} else
V_2 -> V_12 [ V_230 ] = V_78 ;
V_230 ++ ;
}
V_2 -> V_9 = 0 ;
if ( ! V_230 )
V_230 = 1 ;
} else {
V_233 = & V_237 ;
V_230 = 1 ;
for ( V_78 = 0 ; V_78 < 100 ; V_78 ++ ) {
unsigned int V_22 = F_5 ( V_2 , F_16 ( V_247 ) ) ;
if ( V_22 & 0x40 ) {
V_230 = 2 ;
break;
}
F_11 ( V_2 , F_16 ( V_247 ) , V_22 | 0x40 ) ;
F_17 ( 1 ) ;
}
}
if ( ( V_123 = V_223 ( V_2 -> V_17 , 0 , V_233 , V_2 , & V_228 ) ) < 0 )
goto V_38;
V_228 -> V_238 = F_92 ;
if ( V_226 >= 8000 && V_226 <= 48000 )
V_228 -> clock = V_226 ;
if ( V_2 -> V_137 == V_138 )
V_228 -> V_248 = 1 ;
else
V_228 -> V_179 = 1 ;
V_2 -> V_225 = V_228 ;
V_2 -> V_249 = V_230 ;
V_21 . V_204 = V_2 -> V_204 ;
for ( V_78 = 0 ; V_78 < V_230 ; V_78 ++ ) {
V_21 . V_24 = V_78 ;
if ( ( V_123 = F_96 ( V_228 , & V_21 , & V_2 -> V_21 [ V_78 ] ) ) < 0 ) {
if ( V_123 != - V_250 )
F_18 ( V_2 -> V_17 -> V_18 ,
L_10 , V_78 ) ;
if ( V_78 == 0 )
goto V_38;
}
}
F_97 ( V_2 -> V_21 [ 0 ] , V_251 , V_227 ) ;
if ( V_2 -> V_137 == V_155 )
V_228 -> V_252 = 1 ;
V_78 = F_91 ( V_253 ) ;
if ( V_2 -> V_137 != V_155 )
V_78 -= 2 ;
if ( V_2 -> V_133 < 0 )
V_78 -- ;
V_123 = F_98 ( V_228 , V_78 , V_253 ) ;
if ( V_123 < 0 )
goto V_38;
V_2 -> V_90 [ V_132 ] . V_129 = & V_228 -> V_254 [ 0 ] ;
V_2 -> V_90 [ V_183 ] . V_129 = & V_228 -> V_254 [ 1 ] ;
V_2 -> V_90 [ V_184 ] . V_129 = & V_228 -> V_254 [ 2 ] ;
if ( V_2 -> V_133 >= 0 )
V_2 -> V_90 [ V_2 -> V_133 ] . V_129 = & V_228 -> V_254 [ 3 ] ;
if ( V_2 -> V_137 == V_155 ) {
V_2 -> V_90 [ V_186 ] . V_129 = & V_228 -> V_254 [ 4 ] ;
V_2 -> V_90 [ V_185 ] . V_129 = & V_228 -> V_254 [ 5 ] ;
}
if ( V_2 -> V_137 == V_155 ) {
struct V_255 * V_129 = V_2 -> V_90 [ V_186 ] . V_129 ;
T_1 V_27 = F_1 ( V_2 , F_16 ( V_245 ) ) ;
V_27 &= ~ ( V_256 | V_257 ) ;
if ( V_129 ) {
V_27 |= V_258 ;
V_27 |= V_2 -> V_12 [ 0 ] << V_259 ;
for ( V_78 = 1 ; V_78 < 4 ; V_78 ++ ) {
if ( V_129 -> V_130 [ 0 ] . V_7 [ V_78 ] ) {
V_27 |= V_2 -> V_12 [ V_129 -> V_130 [ 0 ] . V_7 [ 1 ] -> V_24 ] << V_260 ;
break;
}
}
} else {
V_27 &= ~ V_258 ;
}
F_7 ( V_2 , F_16 ( V_245 ) , V_27 ) ;
}
if ( V_228 -> V_254 [ 0 ] . V_130 [ 0 ] . V_131 & ( 1 << V_261 ) ) {
V_2 -> V_177 = 1 ;
if ( V_228 -> V_254 [ 0 ] . V_130 [ 0 ] . V_131 & ( 1 << V_262 ) ) {
V_2 -> V_175 = 1 ;
if ( V_2 -> V_21 [ 0 ] -> V_76 & V_263 )
V_2 -> V_171 = 1 ;
}
}
if ( V_228 -> V_254 [ 0 ] . V_130 [ 1 ] . V_264 [ 0 ] ) {
V_2 -> V_179 = 1 ;
}
if ( V_2 -> V_137 == V_155 ) {
if ( ( F_5 ( V_2 , F_16 ( V_13 ) ) & V_265 ) == V_266 )
V_2 -> V_180 = 1 ;
}
if ( V_2 -> V_137 == V_154 && ! V_218 ) {
V_2 -> V_90 [ V_2 -> V_133 ] . V_129 -> V_167 = V_267 ;
}
if ( V_2 -> V_137 == V_155 && ! V_218 ) {
T_2 V_5 ;
V_5 = F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_268 ;
V_5 |= V_269 ;
F_11 ( V_2 , F_16 ( V_145 ) , V_5 ) ;
F_99 ( V_2 -> V_21 [ 0 ] , V_270 , 0x03 << 4 , 0x03 << 4 ) ;
}
V_2 -> V_25 = 0 ;
return 0 ;
V_38:
if ( V_2 -> V_137 != V_138 )
F_11 ( V_2 , F_16 ( V_145 ) ,
F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_271 ) ;
return V_123 ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_11 ( V_2 , F_16 ( V_139 ) , V_272 ) ;
F_11 ( V_2 , F_16 ( V_109 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_110 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_273 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_189 ) ,
V_274 | V_275 ) ;
F_11 ( V_2 , F_16 ( V_276 ) , 0x00000000 ) ;
F_11 ( V_2 , F_16 ( V_117 ) , 0x00000000 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
unsigned int V_135 ;
if ( F_102 ( V_2 -> V_204 , V_277 ) )
return - V_8 ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ ( V_278 | V_149 ) ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 & ~ V_271 ) ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
F_17 ( 10 ) ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 | V_271 ) ;
F_56 ( 1 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned long V_279 ;
unsigned int V_135 ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ ( V_278 | V_149 ) ;
V_135 |= ( V_135 & V_271 ) == 0 ? V_271 : V_280 ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 ) ;
V_279 = ( V_281 + ( V_282 / 4 ) ) + 1 ;
do {
if ( ( F_5 ( V_2 , F_16 ( V_145 ) ) & V_280 ) == 0 )
return 0 ;
F_104 ( 1 ) ;
} while ( F_105 ( V_279 , V_281 ) );
F_18 ( V_2 -> V_17 -> V_18 , L_11 ,
F_5 ( V_2 , F_16 ( V_145 ) ) ) ;
return - V_8 ;
}
static int F_106 ( struct V_1 * V_2 , int V_283 )
{
unsigned long V_279 ;
unsigned int V_77 , V_284 ;
unsigned int V_135 ;
int V_123 ;
V_77 = V_28 | V_285 | V_286 | V_287 ;
if ( V_2 -> V_137 == V_154 )
V_77 |= V_288 ;
V_135 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
F_11 ( V_2 , F_16 ( V_13 ) , V_135 & V_77 ) ;
if ( F_107 ( V_2 ) )
V_123 = F_101 ( V_2 ) ;
else
V_123 = F_103 ( V_2 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_283 ) {
V_279 = V_281 + V_282 ;
do {
V_77 = F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
if ( V_77 )
break;
F_104 ( 1 ) ;
} while ( F_105 ( V_279 , V_281 ) );
if ( ! V_77 ) {
F_18 ( V_2 -> V_17 -> V_18 ,
L_12 ,
F_5 ( V_2 , F_16 ( V_13 ) ) ) ;
return - V_8 ;
}
V_279 = V_281 + V_282 / 4 ;
while ( V_77 != V_2 -> V_10 &&
F_105 ( V_279 , V_281 ) ) {
F_104 ( 1 ) ;
V_77 |= F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
}
} else {
int V_78 ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_249 ; V_78 ++ )
if ( V_2 -> V_21 [ V_78 ] )
V_77 |= V_2 -> V_11 [ V_2 -> V_12 [ V_78 ] ] ;
V_279 = V_281 + V_282 ;
do {
V_284 = F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
if ( V_77 == V_284 )
break;
F_104 ( 1 ) ;
} while ( F_105 ( V_279 , V_281 ) );
}
if ( V_2 -> V_137 == V_144 ) {
F_9 ( V_2 , 0x4c , F_3 ( V_2 , 0x4c ) | 1 ) ;
}
if ( V_2 -> V_137 == V_154 && ! V_218 ) {
unsigned int V_5 ;
F_108 ( V_2 -> V_204 , 0x4c , & V_5 ) ;
V_5 |= 0x1000000 ;
F_109 ( V_2 -> V_204 , 0x4c , V_5 ) ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , int V_283 )
{
T_2 V_22 ;
int V_78 = 0 ;
V_22 = F_5 ( V_2 , F_16 ( V_139 ) ) ;
if ( ( V_22 & 2 ) == 0 )
V_22 |= 2 ;
else
V_22 |= 1 ;
V_22 &= ~ 0x80000000 ;
F_11 ( V_2 , F_16 ( V_139 ) , V_22 ) ;
for ( V_78 = 0 ; V_78 < V_282 / 2 ; V_78 ++ ) {
if ( ! ( F_5 ( V_2 , F_16 ( V_117 ) ) & V_289 ) )
goto V_290;
F_104 ( 1 ) ;
}
F_18 ( V_2 -> V_17 -> V_18 , L_13 ) ;
if ( V_283 )
return - V_8 ;
V_290:
for ( V_78 = 0 ; V_78 < V_282 / 2 ; V_78 ++ ) {
V_22 = F_5 ( V_2 , F_16 ( V_247 ) ) ;
if ( V_22 & 0x80 )
break;
F_11 ( V_2 , F_16 ( V_247 ) , V_22 | 0x80 ) ;
F_104 ( 1 ) ;
}
F_100 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , int V_283 )
{
unsigned int V_78 , V_160 ;
int V_123 ;
if ( V_2 -> V_137 != V_138 ) {
if ( ( V_123 = F_106 ( V_2 , V_283 ) ) < 0 )
return V_123 ;
F_13 ( V_2 , 0 ) ;
} else {
if ( ( V_123 = F_110 ( V_2 , V_283 ) ) < 0 )
return V_123 ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , 0x00 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , V_107 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_160 = 100000 ;
while ( -- V_160 != 0 ) {
if ( ( F_1 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 ) & V_107 ) == 0 )
break;
}
if ( V_160 == 0 )
F_18 ( V_2 -> V_17 -> V_18 , L_14 ) ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_11 ( V_2 , V_51 + V_2 -> V_90 [ V_78 ] . V_50 ,
V_2 -> V_90 [ V_78 ] . V_52 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 )
{
unsigned int V_78 ;
if ( V_2 -> V_83 < 0 )
goto V_291;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , 0x00 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , V_107 ) ;
if ( V_2 -> V_137 == V_154 && ! V_218 ) {
unsigned int V_5 ;
F_108 ( V_2 -> V_204 , 0x4c , & V_5 ) ;
V_5 &= ~ 0x1000000 ;
F_109 ( V_2 -> V_204 , 0x4c , V_5 ) ;
}
V_291:
if ( V_2 -> V_83 >= 0 )
F_113 ( V_2 -> V_83 , V_2 ) ;
if ( V_2 -> V_292 . V_293 ) {
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_292 . V_293 , V_2 -> V_292 . V_294 , 0 ) ;
F_114 ( & V_2 -> V_292 ) ;
}
if ( V_2 -> V_6 )
F_115 ( V_2 -> V_204 , V_2 -> V_6 ) ;
if ( V_2 -> V_4 )
F_115 ( V_2 -> V_204 , V_2 -> V_4 ) ;
F_116 ( V_2 -> V_204 ) ;
F_117 ( V_2 -> V_204 ) ;
F_118 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_192 * V_18 )
{
struct V_295 * V_17 = F_120 ( V_18 ) ;
struct V_1 * V_2 = V_17 -> V_23 ;
int V_78 ;
F_121 ( V_17 , V_296 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_222 ; V_78 ++ )
F_122 ( V_2 -> V_129 [ V_78 ] ) ;
if ( V_2 -> V_124 ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
struct V_46 * V_46 = & V_2 -> V_90 [ V_78 ] ;
if ( V_46 -> V_82 && V_46 -> V_125 ) {
struct V_120 * V_121 = V_46 -> V_82 -> V_121 ;
if ( V_121 -> V_126 )
F_29 ( V_121 -> V_126 , V_121 -> V_127 , 0 ) ;
}
}
}
for ( V_78 = 0 ; V_78 < V_2 -> V_249 ; V_78 ++ )
F_123 ( V_2 -> V_21 [ V_78 ] ) ;
if ( V_2 -> V_137 == V_155 )
V_2 -> V_297 = F_1 ( V_2 , F_16 ( V_245 ) ) ;
if ( V_2 -> V_83 >= 0 ) {
F_113 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
}
return 0 ;
}
static int F_124 ( struct V_192 * V_18 )
{
struct V_298 * V_204 = F_125 ( V_18 ) ;
struct V_295 * V_17 = F_120 ( V_18 ) ;
struct V_1 * V_2 = V_17 -> V_23 ;
int V_78 ;
F_111 ( V_2 , 0 ) ;
if ( F_126 ( V_204 -> V_83 , F_37 ,
V_299 , V_300 , V_2 ) ) {
F_18 ( V_18 , L_15 ,
V_204 -> V_83 ) ;
F_127 ( V_17 ) ;
return - V_8 ;
}
V_2 -> V_83 = V_204 -> V_83 ;
F_128 ( V_2 -> V_83 ) ;
if ( V_2 -> V_137 == V_155 && ! V_218 ) {
F_7 ( V_2 , F_16 ( V_245 ) , V_2 -> V_297 ) ;
F_11 ( V_2 , F_16 ( V_145 ) ,
( F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_268 ) |
V_269 ) ;
}
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_292 . V_293 , V_2 -> V_292 . V_294 , 1 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_249 ; V_78 ++ )
F_129 ( V_2 -> V_21 [ V_78 ] ) ;
if ( V_2 -> V_124 ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
struct V_46 * V_46 = & V_2 -> V_90 [ V_78 ] ;
if ( V_46 -> V_82 && V_46 -> V_125 ) {
struct V_120 * V_121 = V_46 -> V_82 -> V_121 ;
if ( V_121 -> V_126 )
F_29 ( V_121 -> V_126 , V_121 -> V_127 , 1 ) ;
}
}
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
struct V_46 * V_46 = & V_2 -> V_90 [ V_78 ] ;
unsigned long V_49 = V_46 -> V_50 ;
if ( ! V_46 -> V_82 || ! V_46 -> V_95 )
continue;
if ( V_46 -> V_90 == V_132 )
F_53 ( V_2 , V_46 -> V_82 -> V_121 ) ;
F_11 ( V_2 , V_49 + V_51 , V_46 -> V_52 ) ;
F_7 ( V_2 , V_49 + V_62 , V_46 -> V_63 ) ;
F_7 ( V_2 , V_49 + V_65 , V_46 -> V_64 ) ;
F_7 ( V_2 , V_49 + V_46 -> V_68 , V_69 | V_70 | V_71 ) ;
}
F_121 ( V_17 , V_301 ) ;
return 0 ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_92 * V_302 ;
struct V_46 * V_46 ;
unsigned long V_49 ;
unsigned long V_303 , V_304 , V_305 ;
int V_64 , V_160 = 1000 , V_306 = 1 ;
T_7 V_307 , V_308 ;
if ( V_2 -> V_225 -> clock != 48000 )
return;
V_309:
V_302 = V_2 -> V_129 [ 0 ] -> V_310 [ 0 ] . V_82 ;
if ( ! V_302 || V_302 -> V_311 . V_294 < V_312 ) {
F_23 ( V_2 -> V_17 -> V_18 ,
L_16 ) ;
return;
}
V_46 = & V_2 -> V_90 [ V_132 ] ;
V_46 -> V_59 = V_302 -> V_311 . V_6 ;
V_46 -> V_53 = V_46 -> V_54 = V_312 ;
V_46 -> V_82 = NULL ;
if ( F_50 ( V_2 -> V_21 [ 0 ] , V_313 , 48000 ) < 0 ) {
F_18 ( V_2 -> V_17 -> V_18 , L_17 ,
V_2 -> V_225 -> clock ) ;
return;
}
F_27 ( V_2 , V_46 ) ;
V_49 = V_46 -> V_50 ;
F_54 ( & V_2 -> V_80 ) ;
V_2 -> V_81 = 1 ;
if ( V_2 -> V_137 != V_138 )
F_7 ( V_2 , V_49 + V_105 , V_98 | V_99 ) ;
else {
F_7 ( V_2 , V_49 + V_105 , V_98 ) ;
F_11 ( V_2 , F_16 ( V_112 ) , 1 << V_46 -> V_115 ) ;
}
V_307 = F_131 () ;
F_55 ( & V_2 -> V_80 ) ;
F_56 ( 50 ) ;
F_54 ( & V_2 -> V_80 ) ;
do {
V_64 = F_1 ( V_2 , V_46 -> V_50 + V_65 ) ;
V_304 = F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) ;
if ( V_304 == 0 ) {
F_17 ( 10 ) ;
continue;
}
if ( V_64 == F_1 ( V_2 , V_46 -> V_50 + V_65 ) &&
V_304 == F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) )
break;
} while ( V_160 -- );
if ( V_304 == 0 ) {
V_303 = 0 ;
} else {
V_303 = V_46 -> V_57 ;
V_303 -= V_304 << V_46 -> V_60 ;
V_303 += V_46 -> V_67 ;
}
V_2 -> V_81 = 0 ;
V_308 = F_131 () ;
if ( V_2 -> V_137 == V_138 ) {
F_11 ( V_2 , F_16 ( V_112 ) , 1 << ( V_46 -> V_115 + 16 ) ) ;
F_7 ( V_2 , V_49 + V_105 , 0 ) ;
while ( F_1 ( V_2 , V_49 + V_105 ) )
;
} else {
F_7 ( V_2 , V_49 + V_105 , 0 ) ;
while ( ! ( F_1 ( V_2 , V_49 + V_46 -> V_68 ) & V_106 ) )
;
}
F_7 ( V_2 , V_49 + V_105 , V_107 ) ;
F_55 ( & V_2 -> V_80 ) ;
if ( V_303 == 0 ) {
F_18 ( V_2 -> V_17 -> V_18 ,
L_18 ) ;
V_314:
if ( V_306 < 3 ) {
F_56 ( 300 ) ;
V_306 ++ ;
goto V_309;
}
goto V_315;
}
V_303 /= 4 ;
V_305 = F_132 ( V_308 , V_307 ) ;
F_133 ( V_2 -> V_17 -> V_18 ,
L_19 , V_316 , V_305 , V_303 ) ;
if ( V_305 == 0 ) {
F_18 ( V_2 -> V_17 -> V_18 , L_20 ) ;
goto V_314;
}
V_303 *= 1000 ;
V_303 = ( V_303 / V_305 ) * 1000 + ( ( V_303 % V_305 ) * 1000 ) / V_305 ;
if ( V_303 < 40000 || V_303 >= 60000 ) {
F_133 ( V_2 -> V_17 -> V_18 , L_21 , V_303 ) ;
goto V_314;
} else if ( V_303 > 40500 && V_303 < 41500 )
V_2 -> V_225 -> clock = 41000 ;
else if ( V_303 > 43600 && V_303 < 44600 )
V_2 -> V_225 -> clock = 44100 ;
else if ( V_303 < 47500 || V_303 > 48500 )
V_2 -> V_225 -> clock = ( V_2 -> V_225 -> clock * 48000 ) / V_303 ;
V_315:
F_133 ( V_2 -> V_17 -> V_18 , L_22 , V_2 -> V_225 -> clock ) ;
F_134 ( V_2 -> V_21 [ 0 ] , V_313 , 0 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_298 * V_204 = V_2 -> V_204 ;
const struct V_317 * V_318 ;
V_318 = F_102 ( V_204 , V_319 ) ;
if ( ! V_318 )
return 0 ;
F_133 ( V_2 -> V_17 -> V_18 , L_23 ,
V_204 -> V_320 , V_204 -> V_321 , V_318 -> V_322 ) ;
V_2 -> V_225 -> clock = V_318 -> V_322 ;
return 1 ;
}
static void F_136 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_1 * V_2 = V_324 -> V_23 ;
unsigned int V_27 ;
F_137 ( V_326 , L_24 ) ;
if ( V_2 -> V_137 == V_138 )
return;
V_27 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
F_137 ( V_326 , L_25 , F_5 ( V_2 , F_16 ( V_145 ) ) ) ;
F_137 ( V_326 , L_26 , V_27 ) ;
if ( V_2 -> V_137 == V_155 )
F_137 ( V_326 , L_27 , F_5 ( V_2 , F_16 ( V_245 ) ) ) ;
F_137 ( V_326 , L_28 ) ;
if ( V_27 & V_2 -> V_10 ) {
int V_78 ;
static const char * V_230 [ 3 ] = {
L_29 , L_30 , L_31
} ;
for ( V_78 = 0 ; V_78 < V_2 -> V_244 ; V_78 ++ )
if ( V_27 & V_2 -> V_11 [ V_78 ] )
F_137 ( V_326 , L_32 , V_230 [ V_78 ] ) ;
} else
F_137 ( V_326 , L_33 ) ;
F_137 ( V_326 , L_34 ) ;
if ( V_2 -> V_137 == V_155 ||
V_2 -> V_137 == V_144 )
F_137 ( V_326 , L_35 ,
V_2 -> V_12 [ 0 ] ,
V_2 -> V_12 [ 1 ] ,
V_2 -> V_12 [ 2 ] ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_323 * V_324 ;
if ( ! F_139 ( V_2 -> V_17 , L_36 , & V_324 ) )
F_140 ( V_324 , V_2 , F_136 ) ;
}
static int F_141 ( struct V_327 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_328 ;
return F_112 ( V_2 ) ;
}
static int F_142 ( struct V_298 * V_204 )
{
int V_329 = V_162 ;
char * V_330 = NULL ;
if ( V_329 >= 0 ) {
V_330 = V_329 ? L_37 : L_38 ;
goto V_331;
}
V_329 = 0 ;
if ( V_204 -> V_320 == V_332 &&
V_204 -> V_321 == V_333 ) {
V_330 = L_39 ;
V_329 = 1 ;
} else if ( V_204 -> V_320 == 0x1ab8 ) {
V_330 = L_40 ;
V_329 = 1 ;
}
V_331:
if ( V_330 != NULL )
F_133 ( & V_204 -> V_18 , L_41 , V_330 ) ;
return V_329 ;
}
static int F_143 ( struct V_295 * V_17 ,
struct V_298 * V_204 ,
unsigned long V_137 ,
struct V_1 * * V_334 )
{
struct V_1 * V_2 ;
int V_123 ;
unsigned int V_78 ;
unsigned int V_335 ;
struct V_46 * V_46 ;
static struct V_336 V_233 = {
. V_337 = F_141 ,
} ;
static unsigned int V_292 [] = {
3 ,
6 ,
3 ,
6 ,
4 ,
} ;
static struct V_338 V_339 [ 6 ] = {
{ V_287 , 0 } ,
{ V_286 , 0x10 } ,
{ V_285 , 0x20 } ,
{ V_340 , 0x40 } ,
{ V_341 , 0x50 } ,
{ V_342 , 0x60 } ,
} ;
static struct V_338 V_343 [ 4 ] = {
{ V_287 , 0 } ,
{ V_286 , 0x10 } ,
{ V_285 , 0x20 } ,
{ V_288 , 0x70 } ,
} ;
static struct V_338 V_344 [ 6 ] = {
{ V_345 , 0x40 } ,
{ V_346 , 0x50 } ,
{ V_347 , 0x60 } ,
{ V_348 , 0x70 } ,
{ V_349 , 0xa0 } ,
{ V_350 , 0xb0 } ,
} ;
struct V_338 * V_216 ;
* V_334 = NULL ;
if ( ( V_123 = F_144 ( V_204 ) ) < 0 )
return V_123 ;
V_2 = F_145 ( sizeof( * V_2 ) , V_351 ) ;
if ( V_2 == NULL ) {
F_117 ( V_204 ) ;
return - V_352 ;
}
F_146 ( & V_2 -> V_80 ) ;
V_2 -> V_137 = V_137 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_204 = V_204 ;
V_2 -> V_83 = - 1 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_14 = V_14 ;
if ( V_242 )
V_2 -> V_242 = 1 ;
V_2 -> V_162 = F_142 ( V_204 ) ;
if ( V_204 -> V_353 == V_354 &&
V_204 -> V_192 == V_355 )
V_2 -> V_124 = 1 ;
if ( ( V_123 = F_147 ( V_204 , V_17 -> V_202 ) ) < 0 ) {
F_118 ( V_2 ) ;
F_117 ( V_204 ) ;
return V_123 ;
}
if ( V_137 == V_138 ) {
V_2 -> V_4 = F_148 ( V_204 , 0 , 0 ) ;
goto V_356;
}
if ( F_149 ( V_204 , 2 ) & V_357 )
V_2 -> V_6 = F_148 ( V_204 , 2 , 0 ) ;
else
V_2 -> V_6 = F_148 ( V_204 , 0 , 0 ) ;
if ( ! V_2 -> V_6 ) {
F_18 ( V_17 -> V_18 , L_42 ) ;
F_112 ( V_2 ) ;
return - V_8 ;
}
if ( F_149 ( V_204 , 3 ) & V_357 )
V_2 -> V_4 = F_148 ( V_204 , 3 , 0 ) ;
else
V_2 -> V_4 = F_148 ( V_204 , 1 , 0 ) ;
V_356:
if ( ! V_2 -> V_4 ) {
F_18 ( V_17 -> V_18 , L_43 ) ;
F_112 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_89 = V_292 [ V_137 ] ;
switch ( V_137 ) {
case V_154 :
V_216 = V_343 ;
break;
case V_138 :
V_216 = V_344 ;
break;
default:
V_216 = V_339 ;
break;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_46 = & V_2 -> V_90 [ V_78 ] ;
V_46 -> V_90 = V_78 ;
V_46 -> V_50 = V_216 [ V_78 ] . V_3 ;
V_46 -> V_87 = V_216 [ V_78 ] . V_87 ;
if ( V_137 == V_144 ) {
V_46 -> V_68 = V_358 ;
V_46 -> V_161 = V_116 ;
} else {
V_46 -> V_68 = V_116 ;
V_46 -> V_161 = V_358 ;
}
if ( V_137 == V_138 )
V_46 -> V_115 = ( V_46 -> V_50 - 0x40 ) / 0x10 ;
V_46 -> V_60 = ( V_137 == V_144 ) ? 0 : 1 ;
}
if ( F_150 ( V_203 , F_88 ( V_204 ) ,
V_2 -> V_89 * sizeof( T_2 ) * V_359 * 2 ,
& V_2 -> V_292 ) < 0 ) {
F_112 ( V_2 ) ;
F_18 ( V_17 -> V_18 , L_44 ) ;
return - V_352 ;
}
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_292 . V_293 , V_2 -> V_292 . V_294 , 1 ) ;
V_335 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_46 = & V_2 -> V_90 [ V_78 ] ;
V_46 -> V_48 = ( ( T_2 * ) V_2 -> V_292 . V_293 ) +
( V_78 * V_359 * 2 ) ;
V_46 -> V_52 = V_2 -> V_292 . V_6 +
( V_78 * sizeof( T_2 ) * V_359 * 2 ) ;
V_335 |= V_46 -> V_87 ;
}
V_2 -> V_85 = V_137 == V_138 ?
V_360 : V_361 ;
V_2 -> V_87 = V_335 ;
F_151 ( V_204 ) ;
switch( V_2 -> V_137 ) {
case V_155 :
V_2 -> V_244 = 3 ;
V_2 -> V_11 = V_362 ;
V_2 -> V_29 = V_363 | V_364 | V_365 ;
break;
case V_144 :
V_2 -> V_244 = 3 ;
V_2 -> V_11 = V_366 ;
V_2 -> V_29 = V_363 | V_364 | V_367 ;
break;
default:
V_2 -> V_244 = 2 ;
V_2 -> V_11 = V_362 ;
V_2 -> V_29 = V_363 | V_364 ;
break;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_244 ; V_78 ++ )
V_2 -> V_10 |= V_2 -> V_11 [ V_78 ] ;
if ( ( V_123 = F_111 ( V_2 , 1 ) ) < 0 ) {
F_112 ( V_2 ) ;
return V_123 ;
}
if ( F_126 ( V_204 -> V_83 , F_37 ,
V_299 , V_300 , V_2 ) ) {
F_18 ( V_17 -> V_18 , L_45 , V_204 -> V_83 ) ;
F_112 ( V_2 ) ;
return - V_19 ;
}
V_2 -> V_83 = V_204 -> V_83 ;
if ( ( V_123 = F_152 ( V_17 , V_368 , V_2 , & V_233 ) ) < 0 ) {
F_112 ( V_2 ) ;
return V_123 ;
}
* V_334 = V_2 ;
return 0 ;
}
static int F_153 ( struct V_298 * V_204 )
{
const struct V_317 * V_369 ;
V_369 = F_102 ( V_204 , V_370 ) ;
if ( V_369 ) {
if ( V_369 -> V_322 )
F_154 ( & V_204 -> V_18 ,
L_46 ,
F_155 ( V_369 ) ) ;
else
F_154 ( & V_204 -> V_18 ,
L_47 ,
F_155 ( V_369 ) ) ;
return V_369 -> V_322 ;
}
return 0 ;
}
static int F_156 ( struct V_298 * V_204 ,
const struct V_371 * V_372 )
{
struct V_295 * V_17 ;
struct V_1 * V_2 ;
int V_123 ;
struct V_373 * V_196 ;
V_123 = F_157 ( & V_204 -> V_18 , V_374 , V_375 , V_376 , 0 , & V_17 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_218 < 0 )
V_218 = F_153 ( V_204 ) ;
strcpy ( V_17 -> V_377 , L_48 ) ;
if ( ! V_218 ) {
switch ( V_372 -> V_378 ) {
case V_154 :
strcpy ( V_17 -> V_377 , L_49 ) ;
break;
case V_155 :
strcpy ( V_17 -> V_377 , L_50 ) ;
}
}
strcpy ( V_17 -> V_202 , L_8 ) ;
for ( V_196 = V_379 ; V_196 -> V_375 ; V_196 ++ ) {
if ( V_204 -> V_192 == V_196 -> V_375 ) {
strcpy ( V_17 -> V_202 , V_196 -> V_380 ) ;
break;
}
}
if ( V_88 < 0 ) {
if ( V_372 -> V_378 == V_154 )
V_88 = 1 ;
else
V_88 = 0 ;
}
if ( ( V_123 = F_143 ( V_17 , V_204 , V_372 -> V_378 ,
& V_2 ) ) < 0 ) {
F_158 ( V_17 ) ;
return V_123 ;
}
V_17 -> V_23 = V_2 ;
if ( ( V_123 = F_94 ( V_2 , V_226 , V_381 ) ) < 0 ) {
F_158 ( V_17 ) ;
return V_123 ;
}
if ( ( V_123 = F_90 ( V_2 ) ) < 0 ) {
F_158 ( V_17 ) ;
return V_123 ;
}
F_138 ( V_2 ) ;
snprintf ( V_17 -> V_382 , sizeof( V_17 -> V_382 ) ,
L_51 , V_17 -> V_202 ,
F_159 ( V_2 -> V_21 [ 0 ] ) , V_2 -> V_83 ) ;
if ( V_226 == 0 || V_226 == 1 ) {
if ( V_226 == 0 ) {
if ( F_135 ( V_2 ) == 0 )
F_130 ( V_2 ) ;
} else {
F_130 ( V_2 ) ;
}
}
if ( ( V_123 = F_160 ( V_17 ) ) < 0 ) {
F_158 ( V_17 ) ;
return V_123 ;
}
F_161 ( V_204 , V_17 ) ;
return 0 ;
}
static void F_162 ( struct V_298 * V_204 )
{
F_158 ( F_163 ( V_204 ) ) ;
}
