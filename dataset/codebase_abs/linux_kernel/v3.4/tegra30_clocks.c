static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , ( F_3 ( V_2 -> V_4 ) + V_3 - 1 ) / V_3 ) ;
}
static inline T_1 F_4 (
struct V_1 * V_2 , T_1 V_5 , T_1 V_6 , int V_7 )
{
T_1 V_8 = V_2 -> V_9 . V_10 . V_11 / 32 ;
F_5 ( V_8 >= V_12 ) ;
if ( V_8 < 3 )
V_8 = V_5 + ( V_8 * V_7 ) ;
else
V_8 = V_6 + ( ( V_8 - 3 ) * V_7 ) ;
return V_8 ;
}
static unsigned long F_6 ( void )
{
T_1 V_13 ;
F_7 ( V_14 | 1 , V_15 ) ;
do {} while ( F_8 ( V_16 ) & V_17 );
V_13 = F_8 ( V_16 ) ;
if ( V_13 >= 732 - 3 && V_13 <= 732 + 3 ) {
return 12000000 ;
} else if ( V_13 >= 794 - 3 && V_13 <= 794 + 3 ) {
return 13000000 ;
} else if ( V_13 >= 1172 - 3 && V_13 <= 1172 + 3 ) {
return 19200000 ;
} else if ( V_13 >= 1587 - 3 && V_13 <= 1587 + 3 ) {
return 26000000 ;
} else if ( V_13 >= 1025 - 3 && V_13 <= 1025 + 3 ) {
return 16800000 ;
} else if ( V_13 >= 2344 - 3 && V_13 <= 2344 + 3 ) {
return 38400000 ;
} else if ( V_13 >= 2928 - 3 && V_13 <= 2928 + 3 ) {
return 48000000 ;
} else {
F_9 ( L_1 , V_18 ,
V_13 ) ;
F_10 () ;
return 0 ;
}
}
static int F_11 ( unsigned long V_19 , unsigned long V_20 ,
T_1 V_21 , T_1 V_22 )
{
T_2 V_23 = V_19 ;
if ( ! V_20 )
return - V_24 ;
if ( ! ( V_21 & V_25 ) )
V_23 *= 2 ;
if ( V_22 == V_26 )
V_23 += V_20 - 1 ;
F_12 ( V_23 , V_20 ) ;
if ( V_21 & V_25 )
V_23 *= 2 ;
if ( V_23 - 2 < 0 )
return 0 ;
if ( V_23 - 2 > 255 )
return - V_24 ;
return V_23 - 2 ;
}
static int F_13 ( unsigned long V_19 , unsigned long V_20 )
{
T_2 V_27 ;
V_27 = V_19 ;
if ( ! V_20 )
return - V_24 ;
V_27 += V_20 - 1 ;
F_12 ( V_27 , V_20 ) ;
if ( V_27 - 1 < 0 )
return 0 ;
if ( V_27 - 1 > 0xFFFF )
return - V_24 ;
return V_27 - 1 ;
}
static unsigned long F_14 ( struct V_1 * V_2 )
{
T_1 V_28 = F_8 ( V_29 ) ;
T_1 V_30 = V_28 & ~ V_31 ;
T_1 V_32 = V_28 & V_33 ;
V_2 -> V_20 = F_6 () ;
switch ( V_2 -> V_20 ) {
case 12000000 :
V_30 |= V_34 ;
F_5 ( V_32 != V_35 ) ;
break;
case 13000000 :
V_30 |= V_36 ;
F_5 ( V_32 != V_35 ) ;
break;
case 19200000 :
V_30 |= V_37 ;
F_5 ( V_32 != V_35 ) ;
break;
case 26000000 :
V_30 |= V_38 ;
F_5 ( V_32 != V_35 ) ;
break;
case 16800000 :
V_30 |= V_39 ;
F_5 ( V_32 != V_35 ) ;
break;
case 38400000 :
V_30 |= V_40 ;
F_5 ( V_32 != V_41 ) ;
break;
case 48000000 :
V_30 |= V_42 ;
F_5 ( V_32 != V_43 ) ;
break;
default:
F_9 ( L_2 , V_18 , V_2 -> V_20 ) ;
F_10 () ;
}
F_7 ( V_30 , V_29 ) ;
return V_2 -> V_20 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
F_14 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
F_19 ( 1 , L_4 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_32 = F_8 ( V_29 ) & V_33 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
switch ( V_32 ) {
case V_35 :
V_2 -> div = 1 ;
break;
case V_41 :
V_2 -> div = 2 ;
break;
case V_43 :
V_2 -> div = 4 ;
break;
default:
F_9 ( L_5 , V_18 , V_32 ) ;
F_10 () ;
}
V_2 -> V_45 = 1 ;
V_2 -> V_46 = V_47 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_48 ;
int V_49 ;
int V_50 ;
const struct V_51 * V_52 ;
V_48 = F_8 ( V_2 -> V_8 + V_53 ) ;
V_2 -> V_46 = V_47 ;
F_5 ( ( ( V_48 & V_54 ) != V_55 ) &&
( ( V_48 & V_54 ) != V_56 ) ) ;
V_50 = ( ( V_48 & V_54 ) == V_56 ) ?
V_57 : V_58 ;
V_49 = ( V_48 >> V_50 ) & V_59 ;
if ( V_2 -> V_21 & V_60 )
V_49 |= V_48 & V_61 ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_64 == V_49 )
break;
}
F_5 ( V_52 -> V_63 == NULL ) ;
V_2 -> V_4 = V_52 -> V_63 ;
if ( V_2 -> V_21 & V_65 ) {
F_7 ( V_66 << V_67 ,
V_2 -> V_8 + V_68 ) ;
V_2 -> V_45 = 2 ;
V_2 -> div = 2 ;
if ( ! ( V_2 -> V_4 -> V_21 & V_69 ) )
V_2 -> div += V_66 ;
} else
F_7 ( 0 , V_2 -> V_8 + V_68 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static int F_24 ( struct V_1 * V_2 , struct V_1 * V_70 )
{
T_1 V_48 ;
const struct V_51 * V_52 ;
int V_50 ;
V_48 = F_8 ( V_2 -> V_8 + V_53 ) ;
F_5 ( ( ( V_48 & V_54 ) != V_55 ) &&
( ( V_48 & V_54 ) != V_56 ) ) ;
V_50 = ( ( V_48 & V_54 ) == V_56 ) ?
V_57 : V_58 ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_63 == V_70 ) {
if ( ( V_2 -> V_21 & V_60 ) && ( V_70 -> V_21 & V_69 ) &&
( ( V_52 -> V_64 ^ V_48 ) & V_61 ) ) {
if ( V_2 -> V_4 -> V_21 & V_69 )
return - V_24 ;
V_48 ^= V_61 ;
F_25 ( V_48 , V_2 -> V_8 ) ;
}
V_48 &= ~ ( V_59 << V_50 ) ;
V_48 |= ( V_52 -> V_64 & V_59 ) << V_50 ;
if ( V_2 -> V_21 & V_65 ) {
T_1 div = 0 ;
if ( ! ( V_70 -> V_21 & V_69 ) ) {
div = F_8 ( V_2 -> V_8 +
V_68 ) ;
div &= V_71 ;
div >>= V_67 ;
}
V_2 -> div = div + 2 ;
V_2 -> V_45 = 2 ;
}
if ( V_2 -> V_72 )
F_26 ( V_70 ) ;
F_25 ( V_48 , V_2 -> V_8 ) ;
if ( V_2 -> V_72 && V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 , V_70 ) ;
return 0 ;
}
}
return - V_24 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_20 )
{
if ( ( V_2 -> V_21 & V_65 ) && ( V_2 -> V_4 -> V_21 & V_73 ) ) {
int div = F_11 ( V_2 -> V_4 -> V_9 . V_74 . V_75 ,
V_20 , V_2 -> V_21 , V_76 ) ;
div = F_30 ( div , V_66 ) ;
F_7 ( div << V_67 ,
V_2 -> V_8 + V_68 ) ;
V_2 -> div = div + 2 ;
V_2 -> V_45 = 2 ;
return 0 ;
}
return F_2 ( V_2 -> V_4 , V_20 ) ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_20 )
{
V_2 -> V_20 = ( V_20 * V_2 -> V_45 ) / V_2 -> div ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_48 ;
V_48 = F_33 ( V_77 ) ;
V_2 -> V_46 = ( V_48 & V_78 ) ? V_47 : V_79 ;
V_2 -> V_45 = 1 ;
V_48 = F_33 ( V_2 -> V_8 ) ;
if ( V_48 & V_80 ) {
unsigned int V_81 ;
V_81 = ( V_48 >> V_82 ) &
V_83 ;
V_48 >>= V_84 ;
V_48 &= V_85 ;
V_81 += V_48 ;
V_2 -> div = V_81 * 4 ;
} else {
V_2 -> div = 1 ;
}
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_48 ;
V_48 = F_33 ( V_86 ) ;
F_35 ( V_48 | V_87 , V_86 ) ;
V_48 = F_33 ( V_77 ) ;
F_35 ( V_48 | V_78 , V_77 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_48 ;
V_48 = F_33 ( V_77 ) ;
F_35 ( V_48 & ~ V_78 , V_77 ) ;
V_48 = F_33 ( V_86 ) ;
F_35 ( V_48 & ~ V_87 , V_86 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_20 )
{
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
if ( V_20 >= V_19 ) {
V_2 -> div = 1 ;
F_35 ( 0 , V_2 -> V_8 ) ;
} else {
unsigned int V_81 ;
T_1 V_48 ;
V_81 = F_38 ( V_19 / 8 , V_20 ) ;
V_2 -> div = V_81 * 8 ;
V_48 = ( V_81 & V_83 ) <<
V_82 ;
V_81 &= V_85 ;
V_81 <<= V_84 ;
V_48 |= V_81 ;
V_48 |= V_80 ;
F_35 ( V_48 , V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_88 ,
T_1 V_89 )
{
#if V_90
int V_91 ;
for ( V_91 = 0 ; V_91 < V_2 -> V_9 . V_74 . V_92 ; V_91 ++ ) {
if ( F_8 ( V_88 ) & V_89 ) {
F_40 ( V_93 ) ;
return 0 ;
}
F_40 ( 2 ) ;
}
F_9 ( L_6 , V_2 -> V_44 ) ;
return - 1 ;
#endif
F_40 ( V_2 -> V_9 . V_74 . V_92 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_8 ;
int V_91 ;
unsigned long V_94 =
F_3 ( V_2 -> V_4 -> V_4 ) ;
for ( V_91 = 0 ; V_91 < F_42 ( V_95 ) ; V_91 ++ ) {
if ( V_94 == V_95 [ V_91 ] . V_96 )
break;
}
if ( V_91 >= F_42 ( V_95 ) ) {
F_9 ( L_7 , V_18 , V_94 ) ;
return;
}
V_8 = F_8 ( V_97 ) ;
V_8 &= ~ F_43 ( ~ 0 ) ;
V_8 |= F_43 (
V_95 [ V_91 ] . V_98 ) ;
V_8 &= ~ F_44 ( ~ 0 ) ;
V_8 |= F_44 (
V_95 [ V_91 ] . V_99 ) ;
V_8 &= ~ V_100 ;
V_8 &= ~ V_101 ;
V_8 &= ~ V_102 ;
F_7 ( V_8 , V_97 ) ;
V_8 = F_8 ( V_103 ) ;
V_8 &= ~ F_45 ( ~ 0 ) ;
V_8 |= F_45 (
V_95 [ V_91 ] . V_104 ) ;
V_8 &= ~ F_46 ( ~ 0 ) ;
V_8 |= F_46 (
V_95 [ V_91 ] . V_105 ) ;
V_8 &= ~ V_106 ;
V_8 &= ~ V_107 ;
V_8 &= ~ V_108 ;
F_7 ( V_8 , V_103 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_2 -> V_46 = ( V_48 & V_110 ) ? V_47 : V_79 ;
if ( V_2 -> V_21 & V_73 && ! ( V_48 & V_111 ) ) {
const struct V_112 * V_52 ;
unsigned long V_113 = F_3 ( V_2 -> V_4 ) ;
for ( V_52 = V_2 -> V_9 . V_74 . V_114 ; V_52 -> V_113 != 0 ; V_52 ++ ) {
if ( V_52 -> V_113 == V_113 &&
V_52 -> V_115 == V_2 -> V_9 . V_74 . V_75 ) {
V_2 -> V_45 = V_52 -> V_3 ;
V_2 -> div = V_52 -> V_116 * V_52 -> V_70 ;
return;
}
}
F_9 ( L_8 , V_2 -> V_44 ) ;
F_10 () ;
} else if ( V_48 & V_117 ) {
V_2 -> V_45 = 1 ;
V_2 -> div = 1 ;
} else {
V_2 -> V_45 = ( V_48 & V_118 ) >> V_119 ;
V_2 -> div = ( V_48 & V_120 ) >> V_121 ;
if ( V_2 -> V_21 & V_122 )
V_2 -> div *= ( V_48 & V_123 ) ? 1 : 2 ;
else
V_2 -> div *= ( 0x1 << ( ( V_48 & V_124 ) >>
V_125 ) ) ;
if ( V_2 -> V_21 & V_73 ) {
unsigned long V_20 = F_48 ( V_2 ) ;
F_5 ( V_20 != V_2 -> V_9 . V_74 . V_75 ) ;
}
}
if ( V_2 -> V_21 & V_122 )
F_41 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_1 V_48 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
#if V_90
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 |= F_51 ( V_2 ) ;
F_7 ( V_48 , V_2 -> V_8 + F_50 ( V_2 ) ) ;
#endif
V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_48 &= ~ V_117 ;
V_48 |= V_110 ;
F_7 ( V_48 , V_2 -> V_8 + V_109 ) ;
if ( V_2 -> V_21 & V_126 ) {
V_48 = F_33 ( V_127 ) ;
V_48 |= V_128 ;
F_35 ( V_48 , V_127 ) ;
}
F_39 ( V_2 , V_2 -> V_8 + V_109 , V_129 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_48 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ ( V_117 | V_110 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
if ( V_2 -> V_21 & V_126 ) {
V_48 = F_33 ( V_127 ) ;
V_48 &= ~ V_128 ;
F_35 ( V_48 , V_127 ) ;
}
}
static int F_53 ( struct V_1 * V_2 , unsigned long V_20 )
{
T_1 V_48 , V_130 , V_131 ;
unsigned long V_113 ;
const struct V_112 * V_52 ;
struct V_112 V_132 ;
F_16 ( L_9 , V_18 , V_2 -> V_44 , V_20 ) ;
if ( V_2 -> V_21 & V_73 ) {
int V_133 = 0 ;
if ( V_20 != V_2 -> V_9 . V_74 . V_75 ) {
F_9 ( L_10 ,
V_18 , V_2 -> V_44 , V_2 -> V_9 . V_74 . V_75 , V_20 ) ;
V_133 = - V_24 ;
}
return V_133 ;
}
if ( V_2 -> V_21 & V_126 ) {
if ( V_20 != F_48 ( V_2 ) ) {
F_9 ( L_11 ,
V_18 , V_2 -> V_44 ) ;
return - V_24 ;
}
return 0 ;
}
V_130 = 0 ;
V_113 = F_3 ( V_2 -> V_4 ) ;
for ( V_52 = V_2 -> V_9 . V_74 . V_114 ; V_52 -> V_113 != 0 ; V_52 ++ ) {
if ( V_52 -> V_113 == V_113 && V_52 -> V_115 == V_20 ) {
if ( V_2 -> V_21 & V_122 ) {
F_5 ( V_52 -> V_70 < 1 || V_52 -> V_70 > 2 ) ;
if ( V_52 -> V_70 == 1 )
V_130 = V_123 ;
} else {
F_5 ( V_52 -> V_70 < 1 ) ;
for ( V_48 = V_52 -> V_70 ; V_48 > 1 ; V_48 >>= 1 )
V_130 ++ ;
V_130 <<= V_125 ;
}
break;
}
}
if ( V_52 -> V_113 == 0 ) {
unsigned long V_134 ;
F_5 ( V_2 -> V_21 & V_122 ) ;
V_52 = & V_132 ;
switch ( V_113 ) {
case 12000000 :
case 26000000 :
V_134 = ( V_20 <= 1000000 * 1000 ) ? 1000000 : 2000000 ;
break;
case 13000000 :
V_134 = ( V_20 <= 1000000 * 1000 ) ? 1000000 : 2600000 ;
break;
case 16800000 :
case 19200000 :
V_134 = ( V_20 <= 1200000 * 1000 ) ? 1200000 : 2400000 ;
break;
default:
F_9 ( L_12 ,
V_18 , V_113 ) ;
F_10 () ;
}
for ( V_132 . V_115 = V_20 ; V_132 . V_115 < 200 * V_134 ;
V_132 . V_115 <<= 1 )
V_130 ++ ;
V_132 . V_70 = 0x1 << V_130 ;
V_132 . V_116 = V_113 / V_134 ;
V_132 . V_3 = V_132 . V_115 / V_134 ;
V_132 . V_135 = V_136 ;
if ( ( V_132 . V_116 > ( V_120 >> V_121 ) ) ||
( V_132 . V_3 > ( V_118 >> V_119 ) ) ||
( V_130 > ( V_124 >> V_125 ) ) ||
( V_132 . V_115 > V_2 -> V_9 . V_74 . V_137 ) ) {
F_9 ( L_13 ,
V_18 , V_2 -> V_44 , V_20 ) ;
return - V_24 ;
}
V_130 <<= V_125 ;
}
V_2 -> V_45 = V_52 -> V_3 ;
V_2 -> div = V_52 -> V_116 * V_52 -> V_70 ;
V_131 = V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_48 &= ~ ( V_120 | V_118 |
( ( V_2 -> V_21 & V_122 ) ? V_123 : V_124 ) ) ;
V_48 |= ( V_52 -> V_116 << V_121 ) |
( V_52 -> V_3 << V_119 ) | V_130 ;
if ( V_48 == V_131 )
return 0 ;
if ( V_2 -> V_46 == V_47 ) {
F_52 ( V_2 ) ;
V_48 &= ~ ( V_117 | V_110 ) ;
}
F_7 ( V_48 , V_2 -> V_8 + V_109 ) ;
if ( V_2 -> V_21 & V_138 ) {
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 &= ~ V_139 ;
V_48 |= V_52 -> V_135 << V_140 ;
if ( V_2 -> V_21 & ( V_122 | V_141 ) ) {
V_48 &= ~ V_142 ;
if ( V_52 -> V_3 >= V_143 )
V_48 |= 0x1 << V_144 ;
} else if ( V_2 -> V_21 & ( V_69 | V_126 ) ) {
V_48 &= ~ ( 0x1 << V_145 ) ;
if ( V_20 >= ( V_2 -> V_9 . V_74 . V_137 >> 1 ) )
V_48 |= 0x1 << V_145 ;
}
F_7 ( V_48 , V_2 -> V_8 + F_50 ( V_2 ) ) ;
}
if ( V_2 -> V_46 == V_47 )
F_49 ( V_2 ) ;
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 , enum V_146 V_70 , T_1 V_147 )
{
T_1 V_48 , V_148 , V_8 ;
switch ( V_70 ) {
case V_149 :
V_148 = V_150 ;
V_8 = V_2 -> V_8 + V_109 ;
break;
case V_151 :
V_148 = V_152 ;
V_8 = V_2 -> V_8 + F_50 ( V_2 ) ;
break;
case V_153 :
if ( ! ( V_2 -> V_21 & V_154 ) ) {
V_148 = V_155 ;
V_8 = V_2 -> V_8 + V_109 ;
break;
}
default:
return - V_24 ;
}
V_48 = F_8 ( V_8 ) ;
if ( V_147 )
V_48 |= V_148 ;
else
V_48 &= ~ V_148 ;
F_7 ( V_48 , V_8 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_1 V_48 ;
V_48 = F_8 ( V_156 ) ;
V_2 -> V_4 = ( V_48 & V_157 ) ?
F_56 ( L_14 ) :
F_56 ( L_15 ) ;
V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_2 -> V_46 = ( V_48 & V_158 ) ? V_47 : V_79 ;
V_2 -> V_45 = ( V_48 & V_159 ) >> V_160 ;
V_2 -> div = ( V_48 & V_161 ) >> V_162 ;
V_2 -> div *= ( V_48 & V_163 ) >> V_164 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_48 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_48 &= ~ ( V_165 | V_158 ) ;
F_7 ( V_48 , V_2 -> V_8 + V_109 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_1 V_48 ;
V_48 = F_33 ( V_166 ) ;
V_48 |= V_167 ;
F_35 ( V_48 , V_166 ) ;
V_48 = F_33 ( V_166 ) ;
V_48 |= V_168 ;
F_35 ( V_48 , V_166 ) ;
V_48 = F_33 ( V_166 ) ;
V_48 &= ~ V_167 ;
F_35 ( V_48 , V_166 ) ;
do {
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
} while ( ! ( V_48 & V_169 ) );
}
static int F_59 ( struct V_1 * V_2 , bool V_170 )
{
T_1 V_48 ;
const struct V_112 * V_52 ;
unsigned long V_20 = V_2 -> V_9 . V_74 . V_75 ;
unsigned long V_113 = F_3 ( V_2 -> V_4 ) ;
for ( V_52 = V_2 -> V_9 . V_74 . V_114 ; V_52 -> V_113 != 0 ; V_52 ++ ) {
if ( V_52 -> V_113 == V_113 && V_52 -> V_115 == V_20 )
break;
}
if ( V_52 -> V_113 == 0 )
return - V_171 ;
F_57 ( V_2 ) ;
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 &= ~ ( V_172 | V_173 ) ;
F_7 ( V_48 , V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
if ( V_170 || ( ! ( V_48 & V_169 ) ) )
F_58 ( V_2 ) ;
V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_48 &= ~ V_174 ;
V_48 |= F_60 ( V_52 -> V_116 , V_52 -> V_3 , V_52 -> V_70 , V_52 -> V_135 ) ;
F_7 ( V_48 , V_2 -> V_8 + V_109 ) ;
V_2 -> V_45 = V_52 -> V_3 ;
V_2 -> div = V_52 -> V_116 * V_52 -> V_70 ;
V_48 = F_8 ( V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 |= V_175 ;
V_48 |= V_172 ;
F_7 ( V_48 , V_2 -> V_8 + F_50 ( V_2 ) ) ;
V_48 = F_8 ( V_176 ) ;
V_48 |= V_177 ;
F_7 ( V_48 , V_176 ) ;
V_48 = F_8 ( V_2 -> V_8 + V_109 ) ;
V_48 |= ( V_165 | V_158 ) ;
F_7 ( V_48 , V_2 -> V_8 + V_109 ) ;
F_39 ( V_2 , V_2 -> V_8 + F_50 ( V_2 ) , V_178 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
return F_59 ( V_2 , ! V_2 -> V_179 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 & V_65 ) {
T_1 V_180 ;
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 >>= V_2 -> V_181 ;
V_2 -> V_46 = ( V_48 & V_182 ) ? V_47 : V_79 ;
if ( ! ( V_48 & V_183 ) )
V_2 -> V_46 = V_79 ;
V_180 = ( V_48 & V_184 ) >> V_185 ;
V_2 -> div = ( V_180 + 2 ) ;
V_2 -> V_45 = 2 ;
} else if ( V_2 -> V_21 & V_60 ) {
V_2 -> V_46 = V_47 ;
if ( V_2 -> V_21 & ( V_141 | V_69 ) ) {
V_2 -> div = 2 ;
V_2 -> V_45 = 1 ;
} else
F_10 () ;
} else {
V_2 -> V_46 = V_47 ;
V_2 -> div = 1 ;
V_2 -> V_45 = 1 ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
T_1 V_48 ;
T_1 V_186 ;
F_16 ( L_16 , V_18 , V_2 -> V_44 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_186 = V_48 >> V_2 -> V_181 ;
V_186 &= 0xFFFF ;
V_186 |= V_182 | V_183 ;
V_48 &= ~ ( 0xFFFF << V_2 -> V_181 ) ;
V_48 |= V_186 << V_2 -> V_181 ;
F_25 ( V_48 , V_2 -> V_8 ) ;
return 0 ;
} else if ( V_2 -> V_21 & V_60 ) {
return 0 ;
}
return - V_24 ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_48 ;
T_1 V_186 ;
F_16 ( L_16 , V_18 , V_2 -> V_44 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_186 = V_48 >> V_2 -> V_181 ;
V_186 &= 0xFFFF ;
V_186 &= ~ ( V_182 | V_183 ) ;
V_48 &= ~ ( 0xFFFF << V_2 -> V_181 ) ;
V_48 |= V_186 << V_2 -> V_181 ;
F_25 ( V_48 , V_2 -> V_8 ) ;
}
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_20 )
{
T_1 V_48 ;
T_1 V_186 ;
int V_23 ;
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
F_16 ( L_9 , V_18 , V_2 -> V_44 , V_20 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_23 = F_11 (
V_19 , V_20 , V_2 -> V_21 , V_26 ) ;
if ( V_23 >= 0 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_186 = V_48 >> V_2 -> V_181 ;
V_186 &= 0xFFFF ;
if ( V_2 -> V_21 & V_187 )
V_186 |= V_188 ;
V_186 &= ~ V_184 ;
V_186 |= V_23 << V_185 ;
V_48 &= ~ ( 0xFFFF << V_2 -> V_181 ) ;
V_48 |= V_186 << V_2 -> V_181 ;
F_25 ( V_48 , V_2 -> V_8 ) ;
V_2 -> div = V_23 + 2 ;
V_2 -> V_45 = 2 ;
return 0 ;
}
} else if ( V_2 -> V_21 & V_60 )
return F_2 ( V_2 -> V_4 , V_20 * 2 ) ;
return - V_24 ;
}
static long F_66 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_189 ;
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
F_16 ( L_9 , V_18 , V_2 -> V_44 , V_20 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_189 = F_11 (
V_19 , V_20 , V_2 -> V_21 , V_26 ) ;
if ( V_189 < 0 )
return V_189 ;
return F_38 ( V_19 * 2 , V_189 + 2 ) ;
} else if ( V_2 -> V_21 & V_60 )
return V_20 ;
return - V_24 ;
}
static inline T_1 F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 & V_190 )
return 7 << 29 ;
else if ( V_2 -> V_21 & V_191 )
return 3 << 28 ;
else if ( V_2 -> V_21 & V_192 )
return 3 << ( V_2 -> V_9 . V_10 . V_11 + 4 ) ;
else if ( V_2 -> V_21 & V_141 )
return V_155 ;
else
return 3 << 30 ;
}
static inline T_1 F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 & V_190 )
return 29 ;
else if ( V_2 -> V_21 & V_191 )
return 28 ;
else if ( V_2 -> V_21 & V_192 )
return V_2 -> V_9 . V_10 . V_11 + 4 ;
else if ( V_2 -> V_21 & V_141 )
return V_193 ;
else
return 30 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
const struct V_51 * V_194 = 0 ;
const struct V_51 * V_52 ;
if ( V_2 -> V_21 & V_195 ) {
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( ( ( V_48 & F_67 ( V_2 ) ) >>
F_68 ( V_2 ) ) == V_52 -> V_64 )
V_194 = V_52 ;
}
F_5 ( ! V_194 ) ;
V_2 -> V_4 = V_194 -> V_63 ;
} else {
V_2 -> V_4 = V_2 -> V_62 [ 0 ] . V_63 ;
}
if ( V_2 -> V_21 & V_65 ) {
T_1 V_180 = V_48 & V_196 ;
if ( ( V_2 -> V_21 & V_197 ) &&
( ! ( V_48 & V_198 ) ) ) {
V_180 = 0 ;
}
if ( V_2 -> V_21 & V_199 ) {
V_48 &= ~ ( V_196 <<
V_200 ) ;
V_48 |= ( V_201 <<
V_200 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
}
V_2 -> div = V_180 + 2 ;
V_2 -> V_45 = 2 ;
} else if ( V_2 -> V_21 & V_202 ) {
T_1 V_203 = V_48 & V_204 ;
V_2 -> div = V_203 + 1 ;
V_2 -> V_45 = 1 ;
} else {
V_2 -> div = 1 ;
V_2 -> V_45 = 1 ;
}
V_2 -> V_46 = V_47 ;
if ( ! ( F_8 ( F_70 ( V_2 ) ) & F_71 ( V_2 ) ) )
V_2 -> V_46 = V_79 ;
if ( ! ( V_2 -> V_21 & V_205 ) )
if ( F_8 ( F_72 ( V_2 ) ) & F_71 ( V_2 ) )
V_2 -> V_46 = V_79 ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
V_206 [ V_2 -> V_9 . V_10 . V_11 ] ++ ;
if ( V_206 [ V_2 -> V_9 . V_10 . V_11 ] > 1 )
return 0 ;
F_25 ( F_71 ( V_2 ) , F_74 ( V_2 ) ) ;
if ( ! ( V_2 -> V_21 & V_205 ) &&
! ( V_2 -> V_21 & V_207 ) ) {
if ( F_8 ( F_72 ( V_2 ) ) &
F_71 ( V_2 ) ) {
F_40 ( 5 ) ;
F_7 ( F_71 ( V_2 ) ,
F_75 ( V_2 ) ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned long V_48 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
if ( V_2 -> V_72 )
V_206 [ V_2 -> V_9 . V_10 . V_11 ] -- ;
if ( V_206 [ V_2 -> V_9 . V_10 . V_11 ] == 0 ) {
if ( V_2 -> V_21 & V_208 )
V_48 = F_77 () ;
F_25 (
F_71 ( V_2 ) , F_78 ( V_2 ) ) ;
}
}
static void F_79 ( struct V_1 * V_2 , bool assert )
{
unsigned long V_48 ;
F_16 ( L_17 , V_18 ,
assert ? L_18 : L_19 , V_2 -> V_44 ) ;
if ( ! ( V_2 -> V_21 & V_205 ) ) {
if ( assert ) {
if ( V_2 -> V_21 & V_208 )
V_48 = F_77 () ;
F_7 ( F_71 ( V_2 ) ,
F_80 ( V_2 ) ) ;
} else
F_7 ( F_71 ( V_2 ) ,
F_75 ( V_2 ) ) ;
}
}
static int F_81 ( struct V_1 * V_2 , struct V_1 * V_70 )
{
T_1 V_48 ;
const struct V_51 * V_52 ;
F_16 ( L_20 , V_18 , V_2 -> V_44 , V_70 -> V_44 ) ;
if ( ! ( V_2 -> V_21 & V_195 ) )
return ( V_70 == V_2 -> V_4 ) ? 0 : ( - V_24 ) ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_63 == V_70 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ F_67 ( V_2 ) ;
V_48 |= ( V_52 -> V_64 << F_68 ( V_2 ) ) ;
if ( V_2 -> V_72 )
F_26 ( V_70 ) ;
F_25 ( V_48 , V_2 -> V_8 ) ;
if ( V_2 -> V_72 && V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 , V_70 ) ;
return 0 ;
}
}
return - V_24 ;
}
static int F_82 ( struct V_1 * V_2 , unsigned long V_20 )
{
T_1 V_48 ;
int V_189 ;
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_189 = F_11 (
V_19 , V_20 , V_2 -> V_21 , V_26 ) ;
if ( V_189 >= 0 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ V_196 ;
V_48 |= V_189 ;
if ( V_2 -> V_21 & V_197 ) {
if ( V_189 )
V_48 |= V_198 ;
else
V_48 &= ~ V_198 ;
}
F_25 ( V_48 , V_2 -> V_8 ) ;
V_2 -> div = V_189 + 2 ;
V_2 -> V_45 = 2 ;
return 0 ;
}
} else if ( V_2 -> V_21 & V_202 ) {
V_189 = F_13 ( V_19 , V_20 ) ;
if ( V_189 >= 0 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ V_204 ;
V_48 |= V_189 ;
F_25 ( V_48 , V_2 -> V_8 ) ;
V_2 -> div = V_189 + 1 ;
V_2 -> V_45 = 1 ;
return 0 ;
}
} else if ( V_19 <= V_20 ) {
V_2 -> div = 1 ;
V_2 -> V_45 = 1 ;
return 0 ;
}
return - V_24 ;
}
static long F_83 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
int V_189 ;
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
F_16 ( L_9 , V_18 , V_2 -> V_44 , V_20 ) ;
if ( V_2 -> V_21 & V_65 ) {
V_189 = F_11 (
V_19 , V_20 , V_2 -> V_21 , V_26 ) ;
if ( V_189 < 0 )
return V_189 ;
return F_38 ( V_19 * 2 , V_189 + 2 ) ;
} else if ( V_2 -> V_21 & V_202 ) {
V_189 = F_13 ( V_19 , V_20 ) ;
if ( V_189 < 0 )
return V_189 ;
return F_38 ( V_19 , V_189 + 1 ) ;
}
return - V_24 ;
}
static int
F_84 ( struct V_1 * V_2 , enum V_146 V_70 , T_1 V_147 )
{
if ( V_70 == V_209 ) {
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ V_210 ;
V_48 |= ( V_147 << V_211 ) &
V_210 ;
F_7 ( V_48 , V_2 -> V_8 ) ;
return 0 ;
}
return - V_24 ;
}
static int
F_85 ( struct V_1 * V_2 , enum V_146 V_70 , T_1 V_147 )
{
if ( V_70 == V_212 ) {
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
if ( V_147 )
V_48 |= V_213 ;
else
V_48 &= ~ V_213 ;
F_7 ( V_48 , V_2 -> V_8 ) ;
return 0 ;
}
return - V_24 ;
}
static int
F_86 ( struct V_1 * V_2 , enum V_146 V_70 , T_1 V_147 )
{
if ( V_70 == V_214 ) {
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
if ( V_147 )
V_48 |= V_215 ;
else
V_48 &= ~ V_215 ;
F_7 ( V_48 , V_2 -> V_8 ) ;
return 0 ;
}
return - V_24 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_1 * V_70 )
{
const struct V_51 * V_52 ;
struct V_1 * V_216 = F_56 ( L_21 ) ;
F_16 ( L_20 , V_18 , V_2 -> V_44 , V_70 -> V_44 ) ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_63 == V_70 ) {
if ( V_2 -> V_72 )
F_26 ( V_70 ) ;
F_88 (
V_216 , V_153 , V_52 -> V_64 ) ;
if ( V_2 -> V_72 && V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 , V_70 ) ;
return 0 ;
}
}
return - V_24 ;
}
static void F_89 ( struct V_1 * V_2 )
{
const struct V_51 * V_194 = 0 ;
const struct V_51 * V_52 ;
T_1 V_48 = F_33 ( V_2 -> V_8 ) ;
V_2 -> V_46 = ( V_48 & ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ) ? V_47 : V_79 ;
V_2 -> V_45 = 1 ;
V_2 -> div = 1 ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( ( ( V_48 & F_67 ( V_2 ) ) >>
F_68 ( V_2 ) ) == V_52 -> V_64 )
V_194 = V_52 ;
}
F_5 ( ! V_194 ) ;
V_2 -> V_4 = V_194 -> V_63 ;
}
static int F_90 ( struct V_1 * V_2 )
{
T_1 V_48 ;
unsigned long V_21 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
F_91 ( & V_217 , V_21 ) ;
V_48 = F_33 ( V_2 -> V_8 ) ;
V_48 |= ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ;
F_35 ( V_48 , V_2 -> V_8 ) ;
F_92 ( & V_217 , V_21 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
T_1 V_48 ;
unsigned long V_21 ;
F_16 ( L_3 , V_18 , V_2 -> V_44 ) ;
F_91 ( & V_217 , V_21 ) ;
V_48 = F_33 ( V_2 -> V_8 ) ;
V_48 &= ~ ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ;
F_35 ( V_48 , V_2 -> V_8 ) ;
F_92 ( & V_217 , V_21 ) ;
}
static int F_94 ( struct V_1 * V_2 , struct V_1 * V_70 )
{
T_1 V_48 ;
unsigned long V_21 ;
const struct V_51 * V_52 ;
F_16 ( L_20 , V_18 , V_2 -> V_44 , V_70 -> V_44 ) ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_63 == V_70 ) {
if ( V_2 -> V_72 )
F_26 ( V_70 ) ;
F_91 ( & V_217 , V_21 ) ;
V_48 = F_33 ( V_2 -> V_8 ) ;
V_48 &= ~ F_67 ( V_2 ) ;
V_48 |= ( V_52 -> V_64 << F_68 ( V_2 ) ) ;
F_35 ( V_48 , V_2 -> V_8 ) ;
F_92 ( & V_217 , V_21 ) ;
if ( V_2 -> V_72 && V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 , V_70 ) ;
return 0 ;
}
}
return - V_24 ;
}
static void F_95 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_2 -> V_45 = V_48 & ( 0x1 << V_2 -> V_181 ) ? 1 : 2 ;
V_2 -> div = 1 ;
V_2 -> V_46 = V_47 ;
if ( ! ( F_8 ( F_70 ( V_2 ) ) & F_71 ( V_2 ) ) )
V_2 -> V_46 = V_79 ;
}
static int F_96 ( struct V_1 * V_2 , unsigned long V_20 )
{
T_1 V_48 ;
unsigned long V_19 = F_3 ( V_2 -> V_4 ) ;
if ( V_20 == V_19 ) {
V_48 = F_8 ( V_2 -> V_8 ) | ( 0x1 << V_2 -> V_181 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
V_2 -> V_45 = 1 ;
V_2 -> div = 1 ;
return 0 ;
} else if ( V_20 == 2 * V_19 ) {
V_48 = F_8 ( V_2 -> V_8 ) & ( ~ ( 0x1 << V_2 -> V_181 ) ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
V_2 -> V_45 = 2 ;
V_2 -> div = 1 ;
return 0 ;
}
return - V_24 ;
}
static int F_97 ( struct V_1 * V_2 , unsigned long V_20 )
{
V_2 -> V_20 = V_20 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
int V_49 ;
const struct V_51 * V_52 ;
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_2 -> V_46 = ( V_48 & V_218 ) ? V_79 : V_47 ;
V_49 = V_48 & V_219 ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ )
if ( V_52 -> V_64 == V_49 )
break;
F_5 ( V_52 -> V_63 == NULL ) ;
V_2 -> V_4 = V_52 -> V_63 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
F_7 ( ( V_48 & ( ~ V_218 ) ) , V_2 -> V_8 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
F_7 ( ( V_48 | V_218 ) , V_2 -> V_8 ) ;
}
static int F_101 ( struct V_1 * V_2 , struct V_1 * V_70 )
{
T_1 V_48 ;
const struct V_51 * V_52 ;
for ( V_52 = V_2 -> V_62 ; V_52 -> V_63 != NULL ; V_52 ++ ) {
if ( V_52 -> V_63 == V_70 ) {
V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ V_219 ;
V_48 |= V_52 -> V_64 ;
if ( V_2 -> V_72 )
F_26 ( V_70 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
if ( V_2 -> V_72 && V_2 -> V_4 )
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 , V_70 ) ;
return 0 ;
}
}
return - V_24 ;
}
static void F_102 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_2 -> V_46 = V_48 & ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ? V_47 : V_79 ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 |= ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_1 V_48 = F_8 ( V_2 -> V_8 ) ;
V_48 &= ~ ( 0x1 << V_2 -> V_9 . V_10 . V_11 ) ;
F_7 ( V_48 , V_2 -> V_8 ) ;
}
static void F_105 ( void )
{
int V_91 ;
struct V_1 * V_2 ;
for ( V_91 = 0 ; V_91 < F_42 ( V_220 ) ; V_91 ++ ) {
V_2 = F_56 (
V_220 [ V_91 ] . V_221 . V_222 ) ;
if ( ! V_2 )
F_9 ( L_22 , V_18 ,
V_220 [ V_91 ] . V_221 . V_222 ) ;
V_223 [ V_91 ] [ 3 ] . V_63 = V_2 ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
F_107 ( V_2 ) ;
F_108 ( & V_2 -> V_224 ) ;
if ( ! V_2 -> V_221 . V_225 && ! V_2 -> V_221 . V_222 )
V_2 -> V_221 . V_222 = V_2 -> V_44 ;
V_2 -> V_221 . V_1 = V_2 ;
F_109 ( & V_2 -> V_221 ) ;
}
void T_3 F_110 ( void )
{
int V_91 ;
struct V_1 * V_2 ;
for ( V_91 = 0 ; V_91 < F_42 ( V_226 ) ; V_91 ++ )
F_106 ( V_226 [ V_91 ] ) ;
for ( V_91 = 0 ; V_91 < F_42 ( V_227 ) ; V_91 ++ )
F_106 ( & V_227 [ V_91 ] ) ;
for ( V_91 = 0 ; V_91 < F_42 ( V_228 ) ; V_91 ++ ) {
V_2 = F_56 ( V_228 [ V_91 ] . V_44 ) ;
if ( ! V_2 ) {
F_9 ( L_23 , V_18 ,
V_228 [ V_91 ] . V_44 ) ;
continue;
}
V_228 [ V_91 ] . V_221 . V_1 = V_2 ;
F_109 ( & V_228 [ V_91 ] . V_221 ) ;
}
for ( V_91 = 0 ; V_91 < F_42 ( V_229 ) ; V_91 ++ )
F_106 ( & V_229 [ V_91 ] ) ;
for ( V_91 = 0 ; V_91 < F_42 ( V_230 ) ; V_91 ++ )
F_106 ( & V_230 [ V_91 ] ) ;
for ( V_91 = 0 ; V_91 < F_42 ( V_231 ) ; V_91 ++ )
F_106 ( & V_231 [ V_91 ] ) ;
F_105 () ;
for ( V_91 = 0 ; V_91 < F_42 ( V_220 ) ; V_91 ++ )
F_106 ( & V_220 [ V_91 ] ) ;
}
