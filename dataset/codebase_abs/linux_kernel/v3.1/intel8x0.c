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
F_18 ( V_17 L_1 ,
F_1 ( V_2 , F_16 ( V_15 ) ) , F_5 ( V_2 , F_16 ( V_13 ) ) ) ;
F_13 ( V_2 , 0 ) ;
return - V_18 ;
}
static void F_19 ( struct V_19 * V_20 ,
unsigned short V_21 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
if ( F_15 ( V_2 , V_20 -> V_23 ) < 0 ) {
if ( ! V_2 -> V_24 )
F_18 ( V_17 L_2 , V_20 -> V_23 , V_21 ) ;
}
F_14 ( V_2 , V_21 + V_20 -> V_23 * 0x80 , V_5 ) ;
}
static unsigned short F_20 ( struct V_19 * V_20 ,
unsigned short V_21 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
unsigned short V_25 ;
unsigned int V_26 ;
if ( F_15 ( V_2 , V_20 -> V_23 ) < 0 ) {
if ( ! V_2 -> V_24 )
F_18 ( V_17 L_3 , V_20 -> V_23 , V_21 ) ;
V_25 = 0xffff ;
} else {
V_25 = F_13 ( V_2 , V_21 + V_20 -> V_23 * 0x80 ) ;
if ( ( V_26 = F_5 ( V_2 , F_16 ( V_13 ) ) ) & V_27 ) {
F_11 ( V_2 , F_16 ( V_13 ) , V_26 &
~ ( V_2 -> V_28 | V_29 ) ) ;
if ( ! V_2 -> V_24 )
F_18 ( V_17 L_4 , V_20 -> V_23 , V_21 ) ;
V_25 = 0xffff ;
}
}
return V_25 ;
}
static void T_4 F_21 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
unsigned int V_26 ;
if ( F_15 ( V_2 , V_7 ) >= 0 ) {
F_13 ( V_2 , V_7 * 0x80 ) ;
if ( ( V_26 = F_5 ( V_2 , F_16 ( V_13 ) ) ) & V_27 ) {
F_11 ( V_2 , F_16 ( V_13 ) , V_26 &
~ ( V_2 -> V_28 | V_29 ) ) ;
}
}
}
static int F_22 ( struct V_1 * V_2 , int V_30 )
{
int V_31 = 0 ;
for ( V_31 = 0 ; V_31 < 0x7f ; V_31 ++ ) {
int V_5 = F_1 ( V_2 , F_16 ( V_32 ) ) ;
if ( V_5 & V_30 )
return 0 ;
}
if ( ! V_2 -> V_24 )
F_23 ( V_33 L_5 ) ;
return - V_18 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int time = 100 ;
if ( V_2 -> V_14 )
return 0 ;
while ( -- time && ( F_5 ( V_2 , F_16 ( V_34 ) ) & V_35 ) )
F_17 ( 1 ) ;
if ( ! time && ! V_2 -> V_24 )
F_18 ( V_33 L_6 ) ;
return F_22 ( V_2 , V_36 ) ;
}
static unsigned short F_25 ( struct V_19 * V_20 , unsigned short V_21 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
unsigned short V_37 = 0xffff ;
if ( F_24 ( V_2 ) )
goto V_38;
V_21 |= V_39 ;
if ( V_20 -> V_23 )
V_21 |= V_40 ;
F_9 ( V_2 , F_16 ( V_41 ) , V_21 ) ;
if ( F_22 ( V_2 , V_42 ) )
goto V_38;
V_37 = F_3 ( V_2 , F_16 ( V_43 ) ) ;
V_38:
return V_37 ;
}
static void F_26 ( struct V_19 * V_20 , unsigned short V_21 ,
unsigned short V_5 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
if ( F_24 ( V_2 ) )
return;
F_9 ( V_2 , F_16 ( V_44 ) , V_5 ) ;
if ( V_20 -> V_23 )
V_21 |= V_40 ;
F_9 ( V_2 , F_16 ( V_41 ) , V_21 ) ;
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
printk(KERN_DEBUG "bdbar[%i] = 0x%x [0x%x]\n",
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
printk(KERN_DEBUG "lvi_frag = %i, frags = %i, period_size = 0x%x, "
"period_size1 = 0x%x\n",
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
printk(KERN_DEBUG "new: bdbar[%i] = 0x%x [0x%x], prefetch = %i, "
"all = 0x%x, 0x%x\n",
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
static T_5 F_37 ( int V_83 , void * V_84 )
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
static T_6 F_60 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
struct V_46 * V_46 = F_41 ( V_82 ) ;
T_7 V_158 , V_159 ;
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
if ( V_64 == F_1 ( V_2 , V_46 -> V_50 + V_65 ) &&
V_158 == F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) )
break;
} while ( V_160 -- );
V_159 = V_46 -> V_100 ;
if ( V_158 != 0 ) {
V_158 <<= V_46 -> V_60 ;
V_159 = V_46 -> V_57 - V_158 ;
V_159 += V_67 ;
if ( V_159 < V_46 -> V_100 ) {
unsigned int V_162 , V_163 ;
V_162 = V_67 / V_46 -> V_57 ;
V_163 = V_46 -> V_100 / V_46 -> V_57 ;
if ( V_162 == V_163 )
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
V_121 -> V_164 = V_165 ;
V_121 -> V_164 . V_166 = V_46 -> V_129 -> V_166 ;
F_65 ( V_121 ) ;
if ( V_2 -> V_137 == V_144 ) {
V_121 -> V_164 . V_167 = 64 * 1024 ;
V_121 -> V_164 . V_168 = 64 * 1024 ;
}
if ( ( V_123 = F_66 ( V_121 , V_169 ) ) < 0 )
return V_123 ;
V_121 -> V_22 = V_46 ;
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
if ( V_2 -> V_170 ) {
V_121 -> V_164 . V_171 = 8 ;
F_68 ( V_121 , 0 ,
V_172 ,
& V_173 ) ;
} else if ( V_2 -> V_174 ) {
V_121 -> V_164 . V_171 = 6 ;
F_68 ( V_121 , 0 , V_172 ,
& V_175 ) ;
} else if ( V_2 -> V_176 ) {
V_121 -> V_164 . V_171 = 4 ;
F_68 ( V_121 , 0 , V_172 ,
& V_177 ) ;
}
if ( V_2 -> V_178 ) {
F_69 ( V_121 ) ;
}
if ( V_2 -> V_179 ) {
V_121 -> V_164 . V_180 |= V_181 ;
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
return F_64 ( V_82 , & V_2 -> V_90 [ V_182 ] ) ;
}
static int F_73 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_182 ] . V_82 = NULL ;
return 0 ;
}
static int F_74 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_183 ] ) ;
}
static int F_75 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_183 ] . V_82 = NULL ;
return 0 ;
}
static int F_76 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_184 ] ) ;
}
static int F_77 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_184 ] . V_82 = NULL ;
return 0 ;
}
static int F_78 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_185 ] ) ;
}
static int F_79 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
V_2 -> V_90 [ V_185 ] . V_82 = NULL ;
return 0 ;
}
static int F_80 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
int V_47 = V_2 -> V_137 == V_154 ? V_186 : V_187 ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_47 ] ) ;
}
static int F_81 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
int V_47 = V_2 -> V_137 == V_154 ? V_186 : V_187 ;
V_2 -> V_90 [ V_47 ] . V_82 = NULL ;
return 0 ;
}
static int F_82 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
unsigned int V_5 ;
F_54 ( & V_2 -> V_80 ) ;
V_5 = F_5 ( V_2 , F_16 ( V_188 ) ) ;
V_5 |= V_189 ;
F_11 ( V_2 , F_16 ( V_188 ) , V_5 ) ;
F_55 ( & V_2 -> V_80 ) ;
return F_64 ( V_82 , & V_2 -> V_90 [ V_190 ] ) ;
}
static int F_83 ( struct V_92 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 ) ;
unsigned int V_5 ;
V_2 -> V_90 [ V_190 ] . V_82 = NULL ;
F_54 ( & V_2 -> V_80 ) ;
V_5 = F_5 ( V_2 , F_16 ( V_188 ) ) ;
V_5 &= ~ V_189 ;
F_11 ( V_2 , F_16 ( V_188 ) , V_5 ) ;
F_55 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int T_4 F_84 ( struct V_1 * V_2 , int V_191 ,
struct V_192 * V_193 )
{
struct V_194 * V_129 ;
int V_123 ;
char V_195 [ 32 ] ;
if ( V_193 -> V_196 )
sprintf ( V_195 , L_7 , V_193 -> V_196 ) ;
else
strcpy ( V_195 , L_8 ) ;
V_123 = F_85 ( V_2 -> V_197 , V_195 , V_191 ,
V_193 -> V_198 ? 1 : 0 ,
V_193 -> V_199 ? 1 : 0 , & V_129 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_193 -> V_198 )
F_86 ( V_129 , V_114 , V_193 -> V_198 ) ;
if ( V_193 -> V_199 )
F_86 ( V_129 , V_200 , V_193 -> V_199 ) ;
V_129 -> V_22 = V_2 ;
V_129 -> V_201 = 0 ;
if ( V_193 -> V_196 )
sprintf ( V_129 -> V_195 , L_9 , V_2 -> V_197 -> V_202 , V_193 -> V_196 ) ;
else
strcpy ( V_129 -> V_195 , V_2 -> V_197 -> V_202 ) ;
V_2 -> V_129 [ V_191 ] = V_129 ;
F_87 ( V_129 , V_203 ,
F_88 ( V_2 -> V_204 ) ,
V_193 -> V_205 , V_193 -> V_206 ) ;
return 0 ;
}
static int T_4 F_89 ( struct V_1 * V_2 )
{
int V_78 , V_207 , V_191 , V_123 ;
struct V_192 * V_208 , * V_193 ;
switch ( V_2 -> V_137 ) {
case V_155 :
V_208 = V_209 ;
V_207 = F_90 ( V_209 ) ;
if ( V_210 )
V_207 -- ;
break;
case V_154 :
V_208 = V_211 ;
V_207 = F_90 ( V_211 ) ;
if ( V_210 )
V_207 -- ;
break;
case V_138 :
V_208 = V_212 ;
V_207 = F_90 ( V_212 ) ;
break;
default:
V_208 = V_209 ;
V_207 = 2 ;
break;
}
V_191 = 0 ;
for ( V_78 = 0 ; V_78 < V_207 ; V_78 ++ ) {
V_193 = V_208 + V_78 ;
if ( V_78 > 0 && V_193 -> V_213 ) {
if ( ! V_2 -> V_90 [ V_193 -> V_213 ] . V_129 )
continue;
}
V_123 = F_84 ( V_2 , V_191 , V_193 ) ;
if ( V_123 < 0 )
return V_123 ;
V_191 ++ ;
}
V_2 -> V_214 = V_191 ;
return 0 ;
}
static void F_91 ( struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_22 ;
V_2 -> V_217 = NULL ;
}
static void F_92 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
V_2 -> V_20 [ V_20 -> V_23 ] = NULL ;
}
static int T_4 F_93 ( struct V_1 * V_2 , int V_218 ,
const char * V_219 )
{
struct V_215 * V_220 ;
struct V_221 V_20 ;
int V_123 ;
unsigned int V_78 , V_222 ;
unsigned int V_223 = 0 ;
struct V_224 * V_225 ;
static struct V_224 V_226 = {
. V_227 = F_19 ,
. V_228 = F_20 ,
} ;
static struct V_224 V_229 = {
. V_227 = F_26 ,
. V_228 = F_25 ,
} ;
V_2 -> V_133 = - 1 ;
if ( ! V_210 ) {
switch ( V_2 -> V_137 ) {
case V_154 :
V_2 -> V_133 = V_186 ;
break;
case V_138 :
V_2 -> V_133 = V_190 ;
break;
case V_155 :
V_2 -> V_133 = V_187 ;
break;
} ;
}
V_2 -> V_24 = 1 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_22 = V_2 ;
V_20 . V_230 = F_92 ;
V_20 . V_231 = V_232 | V_233 ;
if ( V_2 -> V_234 )
V_20 . V_231 |= V_235 ;
if ( V_2 -> V_137 != V_138 ) {
V_223 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
V_225 = & V_226 ;
V_2 -> V_9 = 1 ;
V_222 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_236 ; V_78 ++ ) {
if ( ! ( V_223 & V_2 -> V_11 [ V_78 ] ) )
continue;
if ( V_2 -> V_137 == V_155 ) {
F_21 ( V_2 , V_222 ) ;
V_2 -> V_12 [ V_222 ] =
F_1 ( V_2 , F_16 ( V_237 ) ) & V_238 ;
if ( F_94 ( V_2 -> V_12 [ V_222 ] >= 3 ) )
V_2 -> V_12 [ V_222 ] = 0 ;
} else
V_2 -> V_12 [ V_222 ] = V_78 ;
V_222 ++ ;
}
V_2 -> V_9 = 0 ;
if ( ! V_222 )
V_222 = 1 ;
} else {
V_225 = & V_229 ;
V_222 = 1 ;
for ( V_78 = 0 ; V_78 < 100 ; V_78 ++ ) {
unsigned int V_21 = F_5 ( V_2 , F_16 ( V_239 ) ) ;
if ( V_21 & 0x40 ) {
V_222 = 2 ;
break;
}
F_11 ( V_2 , F_16 ( V_239 ) , V_21 | 0x40 ) ;
F_17 ( 1 ) ;
}
}
if ( ( V_123 = V_215 ( V_2 -> V_197 , 0 , V_225 , V_2 , & V_220 ) ) < 0 )
goto V_38;
V_220 -> V_230 = F_91 ;
if ( V_218 >= 8000 && V_218 <= 48000 )
V_220 -> clock = V_218 ;
if ( V_2 -> V_137 == V_138 )
V_220 -> V_240 = 1 ;
else
V_220 -> V_178 = 1 ;
V_2 -> V_217 = V_220 ;
V_2 -> V_241 = V_222 ;
V_20 . V_204 = V_2 -> V_204 ;
for ( V_78 = 0 ; V_78 < V_222 ; V_78 ++ ) {
V_20 . V_23 = V_78 ;
if ( ( V_123 = F_95 ( V_220 , & V_20 , & V_2 -> V_20 [ V_78 ] ) ) < 0 ) {
if ( V_123 != - V_242 )
F_18 ( V_17 L_10 , V_78 ) ;
if ( V_78 == 0 )
goto V_38;
}
}
F_96 ( V_2 -> V_20 [ 0 ] , V_243 , V_219 ) ;
if ( V_2 -> V_137 == V_155 )
V_220 -> V_244 = 1 ;
V_78 = F_90 ( V_245 ) ;
if ( V_2 -> V_137 != V_155 )
V_78 -= 2 ;
if ( V_2 -> V_133 < 0 )
V_78 -- ;
V_123 = F_97 ( V_220 , V_78 , V_245 ) ;
if ( V_123 < 0 )
goto V_38;
V_2 -> V_90 [ V_132 ] . V_129 = & V_220 -> V_246 [ 0 ] ;
V_2 -> V_90 [ V_182 ] . V_129 = & V_220 -> V_246 [ 1 ] ;
V_2 -> V_90 [ V_183 ] . V_129 = & V_220 -> V_246 [ 2 ] ;
if ( V_2 -> V_133 >= 0 )
V_2 -> V_90 [ V_2 -> V_133 ] . V_129 = & V_220 -> V_246 [ 3 ] ;
if ( V_2 -> V_137 == V_155 ) {
V_2 -> V_90 [ V_185 ] . V_129 = & V_220 -> V_246 [ 4 ] ;
V_2 -> V_90 [ V_184 ] . V_129 = & V_220 -> V_246 [ 5 ] ;
}
if ( V_2 -> V_137 == V_155 ) {
struct V_247 * V_129 = V_2 -> V_90 [ V_185 ] . V_129 ;
T_1 V_26 = F_1 ( V_2 , F_16 ( V_237 ) ) ;
V_26 &= ~ ( V_248 | V_249 ) ;
if ( V_129 ) {
V_26 |= V_250 ;
V_26 |= V_2 -> V_12 [ 0 ] << V_251 ;
for ( V_78 = 1 ; V_78 < 4 ; V_78 ++ ) {
if ( V_129 -> V_130 [ 0 ] . V_7 [ V_78 ] ) {
V_26 |= V_2 -> V_12 [ V_129 -> V_130 [ 0 ] . V_7 [ 1 ] -> V_23 ] << V_252 ;
break;
}
}
} else {
V_26 &= ~ V_250 ;
}
F_7 ( V_2 , F_16 ( V_237 ) , V_26 ) ;
}
if ( V_220 -> V_246 [ 0 ] . V_130 [ 0 ] . V_131 & ( 1 << V_253 ) ) {
V_2 -> V_176 = 1 ;
if ( V_220 -> V_246 [ 0 ] . V_130 [ 0 ] . V_131 & ( 1 << V_254 ) ) {
V_2 -> V_174 = 1 ;
if ( V_2 -> V_20 [ 0 ] -> V_76 & V_255 )
V_2 -> V_170 = 1 ;
}
}
if ( V_220 -> V_246 [ 0 ] . V_130 [ 1 ] . V_256 [ 0 ] ) {
V_2 -> V_178 = 1 ;
}
if ( V_2 -> V_137 == V_155 ) {
if ( ( F_5 ( V_2 , F_16 ( V_13 ) ) & V_257 ) == V_258 )
V_2 -> V_179 = 1 ;
}
if ( V_2 -> V_137 == V_154 && ! V_210 ) {
V_2 -> V_90 [ V_2 -> V_133 ] . V_129 -> V_166 = V_259 ;
}
if ( V_2 -> V_137 == V_155 && ! V_210 ) {
T_2 V_5 ;
V_5 = F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_260 ;
V_5 |= V_261 ;
F_11 ( V_2 , F_16 ( V_145 ) , V_5 ) ;
F_98 ( V_2 -> V_20 [ 0 ] , V_262 , 0x03 << 4 , 0x03 << 4 ) ;
}
V_2 -> V_24 = 0 ;
return 0 ;
V_38:
if ( V_2 -> V_137 != V_138 )
F_11 ( V_2 , F_16 ( V_145 ) ,
F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_263 ) ;
return V_123 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_11 ( V_2 , F_16 ( V_139 ) , V_264 ) ;
F_11 ( V_2 , F_16 ( V_109 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_110 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_265 ) , 0x83838383 ) ;
F_11 ( V_2 , F_16 ( V_188 ) ,
V_266 | V_267 ) ;
F_11 ( V_2 , F_16 ( V_268 ) , 0x00000000 ) ;
F_11 ( V_2 , F_16 ( V_117 ) , 0x00000000 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned int V_135 ;
if ( F_101 ( V_2 -> V_204 , V_269 ) )
return - V_8 ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ ( V_270 | V_149 ) ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 & ~ V_263 ) ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
F_17 ( 10 ) ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 | V_263 ) ;
F_56 ( 1 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned long V_271 ;
unsigned int V_135 ;
V_135 = F_5 ( V_2 , F_16 ( V_145 ) ) ;
V_135 &= ~ ( V_270 | V_149 ) ;
V_135 |= ( V_135 & V_263 ) == 0 ? V_263 : V_272 ;
F_11 ( V_2 , F_16 ( V_145 ) , V_135 ) ;
V_271 = ( V_273 + ( V_274 / 4 ) ) + 1 ;
do {
if ( ( F_5 ( V_2 , F_16 ( V_145 ) ) & V_272 ) == 0 )
return 0 ;
F_103 ( 1 ) ;
} while ( F_104 ( V_271 , V_273 ) );
F_18 ( V_17 L_11 ,
F_5 ( V_2 , F_16 ( V_145 ) ) ) ;
return - V_8 ;
}
static int F_105 ( struct V_1 * V_2 , int V_275 )
{
unsigned long V_271 ;
unsigned int V_77 , V_276 ;
unsigned int V_135 ;
int V_123 ;
V_77 = V_27 | V_277 | V_278 | V_279 ;
if ( V_2 -> V_137 == V_154 )
V_77 |= V_280 ;
V_135 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
F_11 ( V_2 , F_16 ( V_13 ) , V_135 & V_77 ) ;
if ( F_106 ( V_2 ) )
V_123 = F_100 ( V_2 ) ;
else
V_123 = F_102 ( V_2 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_275 ) {
V_271 = V_273 + V_274 ;
do {
V_77 = F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
if ( V_77 )
break;
F_103 ( 1 ) ;
} while ( F_104 ( V_271 , V_273 ) );
if ( ! V_77 ) {
F_18 ( V_17 L_12 ,
F_5 ( V_2 , F_16 ( V_13 ) ) ) ;
return - V_8 ;
}
V_271 = V_273 + V_274 / 4 ;
while ( V_77 != V_2 -> V_10 &&
F_104 ( V_271 , V_273 ) ) {
F_103 ( 1 ) ;
V_77 |= F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
}
} else {
int V_78 ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_241 ; V_78 ++ )
if ( V_2 -> V_20 [ V_78 ] )
V_77 |= V_2 -> V_11 [ V_2 -> V_12 [ V_78 ] ] ;
V_271 = V_273 + V_274 ;
do {
V_276 = F_5 ( V_2 , F_16 ( V_13 ) ) &
V_2 -> V_10 ;
if ( V_77 == V_276 )
break;
F_103 ( 1 ) ;
} while ( F_104 ( V_271 , V_273 ) );
}
if ( V_2 -> V_137 == V_144 ) {
F_9 ( V_2 , 0x4c , F_3 ( V_2 , 0x4c ) | 1 ) ;
}
if ( V_2 -> V_137 == V_154 && ! V_210 ) {
unsigned int V_5 ;
F_107 ( V_2 -> V_204 , 0x4c , & V_5 ) ;
V_5 |= 0x1000000 ;
F_108 ( V_2 -> V_204 , 0x4c , V_5 ) ;
}
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , int V_275 )
{
T_2 V_21 ;
int V_78 = 0 ;
V_21 = F_5 ( V_2 , F_16 ( V_139 ) ) ;
if ( ( V_21 & 2 ) == 0 )
V_21 |= 2 ;
else
V_21 |= 1 ;
V_21 &= ~ 0x80000000 ;
F_11 ( V_2 , F_16 ( V_139 ) , V_21 ) ;
for ( V_78 = 0 ; V_78 < V_274 / 2 ; V_78 ++ ) {
if ( ! ( F_5 ( V_2 , F_16 ( V_117 ) ) & V_281 ) )
goto V_282;
F_103 ( 1 ) ;
}
F_18 ( V_17 L_13 ) ;
if ( V_275 )
return - V_8 ;
V_282:
for ( V_78 = 0 ; V_78 < V_274 / 2 ; V_78 ++ ) {
V_21 = F_5 ( V_2 , F_16 ( V_239 ) ) ;
if ( V_21 & 0x80 )
break;
F_11 ( V_2 , F_16 ( V_239 ) , V_21 | 0x80 ) ;
F_103 ( 1 ) ;
}
F_99 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , int V_275 )
{
unsigned int V_78 , V_160 ;
int V_123 ;
if ( V_2 -> V_137 != V_138 ) {
if ( ( V_123 = F_105 ( V_2 , V_275 ) ) < 0 )
return V_123 ;
F_13 ( V_2 , 0 ) ;
} else {
if ( ( V_123 = F_109 ( V_2 , V_275 ) ) < 0 )
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
F_111 ( V_17 L_14 ) ;
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
goto V_283;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , 0x00 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ )
F_7 ( V_2 , V_105 + V_2 -> V_90 [ V_78 ] . V_50 , V_107 ) ;
if ( V_2 -> V_137 == V_154 && ! V_210 ) {
unsigned int V_5 ;
F_107 ( V_2 -> V_204 , 0x4c , & V_5 ) ;
V_5 &= ~ 0x1000000 ;
F_108 ( V_2 -> V_204 , 0x4c , V_5 ) ;
}
V_283:
if ( V_2 -> V_83 >= 0 )
F_113 ( V_2 -> V_83 , V_2 ) ;
if ( V_2 -> V_284 . V_285 ) {
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_284 . V_285 , V_2 -> V_284 . V_286 , 0 ) ;
F_114 ( & V_2 -> V_284 ) ;
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
static int F_119 ( struct V_287 * V_204 , T_8 V_288 )
{
struct V_289 * V_197 = F_120 ( V_204 ) ;
struct V_1 * V_2 = V_197 -> V_22 ;
int V_78 ;
F_121 ( V_197 , V_290 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_214 ; V_78 ++ )
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
for ( V_78 = 0 ; V_78 < V_2 -> V_241 ; V_78 ++ )
F_123 ( V_2 -> V_20 [ V_78 ] ) ;
if ( V_2 -> V_137 == V_155 )
V_2 -> V_291 = F_1 ( V_2 , F_16 ( V_237 ) ) ;
if ( V_2 -> V_83 >= 0 ) {
F_113 ( V_2 -> V_83 , V_2 ) ;
V_2 -> V_83 = - 1 ;
}
F_117 ( V_204 ) ;
F_124 ( V_204 ) ;
return 0 ;
}
static int F_125 ( struct V_287 * V_204 )
{
struct V_289 * V_197 = F_120 ( V_204 ) ;
struct V_1 * V_2 = V_197 -> V_22 ;
int V_78 ;
F_126 ( V_204 , V_292 ) ;
F_127 ( V_204 ) ;
if ( F_128 ( V_204 ) < 0 ) {
F_111 ( V_17 L_15
L_16 ) ;
F_129 ( V_197 ) ;
return - V_8 ;
}
F_130 ( V_204 ) ;
F_110 ( V_2 , 0 ) ;
if ( F_131 ( V_204 -> V_83 , F_37 ,
V_293 , V_294 , V_2 ) ) {
F_111 ( V_17 L_17
L_16 , V_204 -> V_83 ) ;
F_129 ( V_197 ) ;
return - V_8 ;
}
V_2 -> V_83 = V_204 -> V_83 ;
F_132 ( V_2 -> V_83 ) ;
if ( V_2 -> V_137 == V_155 && ! V_210 ) {
F_7 ( V_2 , F_16 ( V_237 ) , V_2 -> V_291 ) ;
F_11 ( V_2 , F_16 ( V_145 ) ,
( F_5 ( V_2 , F_16 ( V_145 ) ) & ~ V_260 ) |
V_261 ) ;
}
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_284 . V_285 , V_2 -> V_284 . V_286 , 1 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_241 ; V_78 ++ )
F_133 ( V_2 -> V_20 [ V_78 ] ) ;
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
F_121 ( V_197 , V_295 ) ;
return 0 ;
}
static void T_4 F_134 ( struct V_1 * V_2 )
{
struct V_92 * V_296 ;
struct V_46 * V_46 ;
unsigned long V_49 ;
unsigned long V_297 , V_298 , V_299 ;
int V_64 , V_160 = 1000 , V_300 = 1 ;
struct V_301 V_302 , V_303 ;
if ( V_2 -> V_217 -> clock != 48000 )
return;
V_304:
V_296 = V_2 -> V_129 [ 0 ] -> V_305 [ 0 ] . V_82 ;
if ( ! V_296 || V_296 -> V_306 . V_286 < V_307 ) {
F_18 ( V_33 L_18 ) ;
return;
}
V_46 = & V_2 -> V_90 [ V_132 ] ;
V_46 -> V_59 = V_296 -> V_306 . V_6 ;
V_46 -> V_53 = V_46 -> V_54 = V_307 ;
V_46 -> V_82 = NULL ;
if ( F_50 ( V_2 -> V_20 [ 0 ] , V_308 , 48000 ) < 0 ) {
F_18 ( V_17 L_19 , V_2 -> V_217 -> clock ) ;
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
F_135 ( & V_302 ) ;
F_55 ( & V_2 -> V_80 ) ;
F_56 ( 50 ) ;
F_54 ( & V_2 -> V_80 ) ;
do {
V_64 = F_1 ( V_2 , V_46 -> V_50 + V_65 ) ;
V_298 = F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) ;
if ( V_298 == 0 ) {
F_17 ( 10 ) ;
continue;
}
if ( V_64 == F_1 ( V_2 , V_46 -> V_50 + V_65 ) &&
V_298 == F_3 ( V_2 , V_46 -> V_50 + V_46 -> V_161 ) )
break;
} while ( V_160 -- );
if ( V_298 == 0 ) {
V_297 = 0 ;
} else {
V_297 = V_46 -> V_57 ;
V_297 -= V_298 << V_46 -> V_60 ;
V_297 += V_46 -> V_67 ;
}
V_2 -> V_81 = 0 ;
F_135 ( & V_303 ) ;
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
if ( V_297 == 0 ) {
F_18 ( V_17 L_20 ) ;
V_309:
if ( V_300 < 3 ) {
F_56 ( 300 ) ;
V_300 ++ ;
goto V_304;
}
goto V_310;
}
V_297 /= 4 ;
V_299 = V_303 . V_311 - V_302 . V_311 ;
V_299 *= 1000000 ;
V_299 += ( V_303 . V_312 - V_302 . V_312 ) / 1000 ;
F_111 ( V_313 L_21 , V_314 , V_299 , V_297 ) ;
if ( V_299 == 0 ) {
F_18 ( V_17 L_22 ) ;
goto V_309;
}
V_297 *= 1000 ;
V_297 = ( V_297 / V_299 ) * 1000 + ( ( V_297 % V_299 ) * 1000 ) / V_299 ;
if ( V_297 < 40000 || V_297 >= 60000 ) {
F_111 ( V_313 L_23 , V_297 ) ;
goto V_309;
} else if ( V_297 > 40500 && V_297 < 41500 )
V_2 -> V_217 -> clock = 41000 ;
else if ( V_297 > 43600 && V_297 < 44600 )
V_2 -> V_217 -> clock = 44100 ;
else if ( V_297 < 47500 || V_297 > 48500 )
V_2 -> V_217 -> clock = ( V_2 -> V_217 -> clock * 48000 ) / V_297 ;
V_310:
F_111 ( V_313 L_24 , V_2 -> V_217 -> clock ) ;
F_136 ( V_2 -> V_20 [ 0 ] , V_308 , 0 ) ;
}
static int T_4 F_137 ( struct V_1 * V_2 )
{
struct V_287 * V_204 = V_2 -> V_204 ;
const struct V_315 * V_316 ;
V_316 = F_101 ( V_204 , V_317 ) ;
if ( ! V_316 )
return 0 ;
F_111 ( V_313 L_25 ,
V_204 -> V_318 , V_204 -> V_319 , V_316 -> V_320 ) ;
V_2 -> V_217 -> clock = V_316 -> V_320 ;
return 1 ;
}
static void F_138 ( struct V_321 * V_322 ,
struct V_323 * V_324 )
{
struct V_1 * V_2 = V_322 -> V_22 ;
unsigned int V_26 ;
F_139 ( V_324 , L_26 ) ;
if ( V_2 -> V_137 == V_138 )
return;
V_26 = F_5 ( V_2 , F_16 ( V_13 ) ) ;
F_139 ( V_324 , L_27 , F_5 ( V_2 , F_16 ( V_145 ) ) ) ;
F_139 ( V_324 , L_28 , V_26 ) ;
if ( V_2 -> V_137 == V_155 )
F_139 ( V_324 , L_29 , F_5 ( V_2 , F_16 ( V_237 ) ) ) ;
F_139 ( V_324 , L_30 ) ;
if ( V_26 & V_2 -> V_10 ) {
int V_78 ;
static const char * V_222 [ 3 ] = {
L_31 , L_32 , L_33
} ;
for ( V_78 = 0 ; V_78 < V_2 -> V_236 ; V_78 ++ )
if ( V_26 & V_2 -> V_11 [ V_78 ] )
F_139 ( V_324 , L_34 , V_222 [ V_78 ] ) ;
} else
F_139 ( V_324 , L_35 ) ;
F_139 ( V_324 , L_36 ) ;
if ( V_2 -> V_137 == V_155 ||
V_2 -> V_137 == V_144 )
F_139 ( V_324 , L_37 ,
V_2 -> V_12 [ 0 ] ,
V_2 -> V_12 [ 1 ] ,
V_2 -> V_12 [ 2 ] ) ;
}
static void T_4 F_140 ( struct V_1 * V_2 )
{
struct V_321 * V_322 ;
if ( ! F_141 ( V_2 -> V_197 , L_38 , & V_322 ) )
F_142 ( V_322 , V_2 , F_138 ) ;
}
static int F_143 ( struct V_325 * V_191 )
{
struct V_1 * V_2 = V_191 -> V_326 ;
return F_112 ( V_2 ) ;
}
static int T_4 F_144 ( struct V_289 * V_197 ,
struct V_287 * V_204 ,
unsigned long V_137 ,
struct V_1 * * V_327 )
{
struct V_1 * V_2 ;
int V_123 ;
unsigned int V_78 ;
unsigned int V_328 ;
struct V_46 * V_46 ;
static struct V_329 V_225 = {
. V_330 = F_143 ,
} ;
static unsigned int V_284 [] = {
3 ,
6 ,
3 ,
6 ,
4 ,
} ;
static struct V_331 V_332 [ 6 ] = {
{ V_279 , 0 } ,
{ V_278 , 0x10 } ,
{ V_277 , 0x20 } ,
{ V_333 , 0x40 } ,
{ V_334 , 0x50 } ,
{ V_335 , 0x60 } ,
} ;
static struct V_331 V_336 [ 4 ] = {
{ V_279 , 0 } ,
{ V_278 , 0x10 } ,
{ V_277 , 0x20 } ,
{ V_280 , 0x70 } ,
} ;
static struct V_331 V_337 [ 6 ] = {
{ V_338 , 0x40 } ,
{ V_339 , 0x50 } ,
{ V_340 , 0x60 } ,
{ V_341 , 0x70 } ,
{ V_342 , 0xa0 } ,
{ V_343 , 0xb0 } ,
} ;
struct V_331 * V_208 ;
* V_327 = NULL ;
if ( ( V_123 = F_128 ( V_204 ) ) < 0 )
return V_123 ;
V_2 = F_145 ( sizeof( * V_2 ) , V_344 ) ;
if ( V_2 == NULL ) {
F_117 ( V_204 ) ;
return - V_345 ;
}
F_146 ( & V_2 -> V_80 ) ;
V_2 -> V_137 = V_137 ;
V_2 -> V_197 = V_197 ;
V_2 -> V_204 = V_204 ;
V_2 -> V_83 = - 1 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_14 = V_14 ;
if ( V_234 )
V_2 -> V_234 = 1 ;
if ( V_204 -> V_346 == V_347 &&
V_204 -> V_191 == V_348 )
V_2 -> V_124 = 1 ;
if ( ( V_123 = F_147 ( V_204 , V_197 -> V_202 ) ) < 0 ) {
F_118 ( V_2 ) ;
F_117 ( V_204 ) ;
return V_123 ;
}
if ( V_137 == V_138 ) {
V_2 -> V_4 = F_148 ( V_204 , 0 , 0 ) ;
goto V_349;
}
if ( F_149 ( V_204 , 2 ) & V_350 )
V_2 -> V_6 = F_148 ( V_204 , 2 , 0 ) ;
else
V_2 -> V_6 = F_148 ( V_204 , 0 , 0 ) ;
if ( ! V_2 -> V_6 ) {
F_18 ( V_17 L_39 ) ;
F_112 ( V_2 ) ;
return - V_8 ;
}
if ( F_149 ( V_204 , 3 ) & V_350 )
V_2 -> V_4 = F_148 ( V_204 , 3 , 0 ) ;
else
V_2 -> V_4 = F_148 ( V_204 , 1 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_18 ( V_17 L_40 ) ;
F_112 ( V_2 ) ;
return - V_8 ;
}
V_349:
V_2 -> V_89 = V_284 [ V_137 ] ;
switch ( V_137 ) {
case V_154 :
V_208 = V_336 ;
break;
case V_138 :
V_208 = V_337 ;
break;
default:
V_208 = V_332 ;
break;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_46 = & V_2 -> V_90 [ V_78 ] ;
V_46 -> V_90 = V_78 ;
V_46 -> V_50 = V_208 [ V_78 ] . V_3 ;
V_46 -> V_87 = V_208 [ V_78 ] . V_87 ;
if ( V_137 == V_144 ) {
V_46 -> V_68 = V_351 ;
V_46 -> V_161 = V_116 ;
} else {
V_46 -> V_68 = V_116 ;
V_46 -> V_161 = V_351 ;
}
if ( V_137 == V_138 )
V_46 -> V_115 = ( V_46 -> V_50 - 0x40 ) / 0x10 ;
V_46 -> V_60 = ( V_137 == V_144 ) ? 0 : 1 ;
}
if ( F_150 ( V_203 , F_88 ( V_204 ) ,
V_2 -> V_89 * sizeof( T_2 ) * V_352 * 2 ,
& V_2 -> V_284 ) < 0 ) {
F_112 ( V_2 ) ;
F_18 ( V_17 L_41 ) ;
return - V_345 ;
}
if ( V_2 -> V_124 )
F_29 ( V_2 -> V_284 . V_285 , V_2 -> V_284 . V_286 , 1 ) ;
V_328 = 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_89 ; V_78 ++ ) {
V_46 = & V_2 -> V_90 [ V_78 ] ;
V_46 -> V_48 = ( ( T_2 * ) V_2 -> V_284 . V_285 ) +
( V_78 * V_352 * 2 ) ;
V_46 -> V_52 = V_2 -> V_284 . V_6 +
( V_78 * sizeof( T_2 ) * V_352 * 2 ) ;
V_328 |= V_46 -> V_87 ;
}
V_2 -> V_85 = V_137 == V_138 ?
V_353 : V_354 ;
V_2 -> V_87 = V_328 ;
F_130 ( V_204 ) ;
switch( V_2 -> V_137 ) {
case V_155 :
V_2 -> V_236 = 3 ;
V_2 -> V_11 = V_355 ;
V_2 -> V_28 = V_356 | V_357 | V_358 ;
break;
case V_144 :
V_2 -> V_236 = 3 ;
V_2 -> V_11 = V_359 ;
V_2 -> V_28 = V_356 | V_357 | V_360 ;
break;
default:
V_2 -> V_236 = 2 ;
V_2 -> V_11 = V_355 ;
V_2 -> V_28 = V_356 | V_357 ;
break;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_236 ; V_78 ++ )
V_2 -> V_10 |= V_2 -> V_11 [ V_78 ] ;
if ( ( V_123 = F_110 ( V_2 , 1 ) ) < 0 ) {
F_112 ( V_2 ) ;
return V_123 ;
}
if ( F_131 ( V_204 -> V_83 , F_37 ,
V_293 , V_294 , V_2 ) ) {
F_18 ( V_17 L_42 , V_204 -> V_83 ) ;
F_112 ( V_2 ) ;
return - V_18 ;
}
V_2 -> V_83 = V_204 -> V_83 ;
if ( ( V_123 = F_151 ( V_197 , V_361 , V_2 , & V_225 ) ) < 0 ) {
F_112 ( V_2 ) ;
return V_123 ;
}
F_152 ( V_197 , & V_204 -> V_362 ) ;
* V_327 = V_2 ;
return 0 ;
}
static int T_4 F_153 ( struct V_287 * V_204 )
{
const struct V_315 * V_363 ;
V_363 = F_101 ( V_204 , V_364 ) ;
if ( V_363 ) {
if ( V_363 -> V_320 )
F_154 ( V_313 L_43
L_44 , V_363 -> V_195 ) ;
else
F_154 ( V_313 L_45
L_46 , V_363 -> V_195 ) ;
return V_363 -> V_320 ;
}
return 0 ;
}
static int T_4 F_155 ( struct V_287 * V_204 ,
const struct V_365 * V_366 )
{
struct V_289 * V_197 ;
struct V_1 * V_2 ;
int V_123 ;
struct V_367 * V_195 ;
V_123 = F_156 ( V_368 , V_369 , V_370 , 0 , & V_197 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_210 < 0 )
V_210 = F_153 ( V_204 ) ;
strcpy ( V_197 -> V_371 , L_47 ) ;
if ( ! V_210 ) {
switch ( V_366 -> V_372 ) {
case V_154 :
strcpy ( V_197 -> V_371 , L_48 ) ;
break;
case V_155 :
strcpy ( V_197 -> V_371 , L_49 ) ;
}
}
strcpy ( V_197 -> V_202 , L_8 ) ;
for ( V_195 = V_373 ; V_195 -> V_369 ; V_195 ++ ) {
if ( V_204 -> V_191 == V_195 -> V_369 ) {
strcpy ( V_197 -> V_202 , V_195 -> V_374 ) ;
break;
}
}
if ( V_88 < 0 ) {
if ( V_366 -> V_372 == V_154 )
V_88 = 1 ;
else
V_88 = 0 ;
}
if ( ( V_123 = F_144 ( V_197 , V_204 , V_366 -> V_372 ,
& V_2 ) ) < 0 ) {
F_157 ( V_197 ) ;
return V_123 ;
}
V_197 -> V_22 = V_2 ;
if ( ( V_123 = F_93 ( V_2 , V_218 , V_375 ) ) < 0 ) {
F_157 ( V_197 ) ;
return V_123 ;
}
if ( ( V_123 = F_89 ( V_2 ) ) < 0 ) {
F_157 ( V_197 ) ;
return V_123 ;
}
F_140 ( V_2 ) ;
snprintf ( V_197 -> V_376 , sizeof( V_197 -> V_376 ) ,
L_50 , V_197 -> V_202 ,
F_158 ( V_2 -> V_20 [ 0 ] ) , V_2 -> V_83 ) ;
if ( V_218 == 0 || V_218 == 1 ) {
if ( V_218 == 0 ) {
if ( F_137 ( V_2 ) == 0 )
F_134 ( V_2 ) ;
} else {
F_134 ( V_2 ) ;
}
}
if ( ( V_123 = F_159 ( V_197 ) ) < 0 ) {
F_157 ( V_197 ) ;
return V_123 ;
}
F_160 ( V_204 , V_197 ) ;
return 0 ;
}
static void T_9 F_161 ( struct V_287 * V_204 )
{
F_157 ( F_120 ( V_204 ) ) ;
F_160 ( V_204 , NULL ) ;
}
static int T_10 F_162 ( void )
{
return F_163 ( & V_371 ) ;
}
static void T_11 F_164 ( void )
{
F_165 ( & V_371 ) ;
}
