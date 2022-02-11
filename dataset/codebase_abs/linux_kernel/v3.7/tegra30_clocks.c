static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_4 ;
return F_2 ( V_4 ,
( F_3 ( F_4 ( V_4 ) ) + V_3 - 1 ) / V_3 ) ;
}
static inline T_1 F_5 (
struct V_1 * V_2 , T_1 V_6 , T_1 V_7 , int V_8 )
{
T_1 V_9 = V_2 -> V_10 . V_11 . V_12 / 32 ;
F_6 ( V_9 >= V_13 ) ;
if ( V_9 < 3 )
V_9 = V_6 + ( V_9 * V_8 ) ;
else
V_9 = V_7 + ( ( V_9 - 3 ) * V_8 ) ;
return V_9 ;
}
static unsigned long F_7 ( void )
{
T_1 V_14 ;
F_8 ( V_15 | 1 , V_16 ) ;
do {} while ( F_9 ( V_17 ) & V_18 );
V_14 = F_9 ( V_17 ) ;
if ( V_14 >= 732 - 3 && V_14 <= 732 + 3 ) {
return 12000000 ;
} else if ( V_14 >= 794 - 3 && V_14 <= 794 + 3 ) {
return 13000000 ;
} else if ( V_14 >= 1172 - 3 && V_14 <= 1172 + 3 ) {
return 19200000 ;
} else if ( V_14 >= 1587 - 3 && V_14 <= 1587 + 3 ) {
return 26000000 ;
} else if ( V_14 >= 1025 - 3 && V_14 <= 1025 + 3 ) {
return 16800000 ;
} else if ( V_14 >= 2344 - 3 && V_14 <= 2344 + 3 ) {
return 38400000 ;
} else if ( V_14 >= 2928 - 3 && V_14 <= 2928 + 3 ) {
return 48000000 ;
} else {
F_10 ( L_1 , V_19 ,
V_14 ) ;
F_11 () ;
return 0 ;
}
}
static int F_12 ( unsigned long V_20 , unsigned long V_21 ,
T_1 V_22 , T_1 V_23 )
{
T_2 V_24 = V_20 ;
if ( ! V_21 )
return - V_25 ;
if ( ! ( V_22 & V_26 ) )
V_24 *= 2 ;
if ( V_23 == V_27 )
V_24 += V_21 - 1 ;
F_13 ( V_24 , V_21 ) ;
if ( V_22 & V_26 )
V_24 *= 2 ;
if ( V_24 - 2 < 0 )
return 0 ;
if ( V_24 - 2 > 255 )
return - V_25 ;
return V_24 - 2 ;
}
static int F_14 ( unsigned long V_20 , unsigned long V_21 )
{
T_2 V_28 ;
V_28 = V_20 ;
if ( ! V_21 )
return - V_25 ;
V_28 += V_21 - 1 ;
F_13 ( V_28 , V_21 ) ;
if ( V_28 - 1 < 0 )
return 0 ;
if ( V_28 - 1 > 0xFFFF )
return - V_25 ;
return V_28 - 1 ;
}
static unsigned long F_15 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
return F_16 ( V_5 ) -> V_30 ;
}
static unsigned long F_17 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
if ( ! F_16 ( V_5 ) -> V_30 )
F_16 ( V_5 ) -> V_30 = F_7 () ;
return F_16 ( V_5 ) -> V_30 ;
}
static void F_18 ( struct V_29 * V_5 )
{
T_1 V_31 = F_9 ( V_32 ) ;
T_1 V_33 = V_31 & ~ V_34 ;
T_1 V_35 = V_31 & V_36 ;
switch ( F_16 ( V_5 ) -> V_30 ) {
case 12000000 :
V_33 |= V_37 ;
F_6 ( V_35 != V_38 ) ;
break;
case 13000000 :
V_33 |= V_39 ;
F_6 ( V_35 != V_38 ) ;
break;
case 19200000 :
V_33 |= V_40 ;
F_6 ( V_35 != V_38 ) ;
break;
case 26000000 :
V_33 |= V_41 ;
F_6 ( V_35 != V_38 ) ;
break;
case 16800000 :
V_33 |= V_42 ;
F_6 ( V_35 != V_38 ) ;
break;
case 38400000 :
V_33 |= V_43 ;
F_6 ( V_35 != V_44 ) ;
break;
case 48000000 :
V_33 |= V_45 ;
F_6 ( V_35 != V_46 ) ;
break;
default:
F_10 ( L_2 , V_19 ,
F_16 ( V_5 ) -> V_30 ) ;
F_11 () ;
}
F_8 ( V_33 , V_32 ) ;
}
static unsigned long F_19 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static unsigned long F_20 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_21 = V_20 ;
T_1 V_35 = F_9 ( V_32 ) & V_36 ;
switch ( V_35 ) {
case V_38 :
V_2 -> div = 1 ;
break;
case V_44 :
V_2 -> div = 2 ;
break;
case V_46 :
V_2 -> div = 4 ;
break;
default:
F_10 ( L_3 , V_19 , V_35 ) ;
F_11 () ;
}
V_2 -> V_47 = 1 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static void F_21 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_1 * V_48 =
F_16 ( F_22 ( F_4 ( V_5 -> V_4 ) ) ) ;
V_2 -> V_49 = V_50 ;
if ( V_2 -> V_22 & V_51 ) {
F_8 ( V_52 << V_53 ,
V_2 -> V_9 + V_54 ) ;
V_2 -> V_47 = 2 ;
V_2 -> div = 2 ;
if ( ! ( V_48 -> V_22 & V_55 ) )
V_2 -> div += V_52 ;
} else
F_8 ( 0 , V_2 -> V_9 + V_54 ) ;
}
static T_4 F_23 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
int V_57 ;
int V_58 ;
V_56 = F_9 ( V_2 -> V_9 + V_59 ) ;
F_6 ( ( ( V_56 & V_60 ) != V_61 ) &&
( ( V_56 & V_60 ) != V_62 ) ) ;
V_58 = ( ( V_56 & V_60 ) == V_62 ) ?
V_63 : V_64 ;
V_57 = ( V_56 >> V_58 ) & V_65 ;
if ( V_2 -> V_22 & V_66 )
V_57 |= V_56 & V_67 ;
return V_57 ;
}
static int F_24 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_1 * V_48 =
F_16 ( F_22 ( F_25 ( V_5 -> V_4 ) ) ) ;
T_1 V_56 ;
int V_58 ;
V_56 = F_9 ( V_2 -> V_9 + V_59 ) ;
F_6 ( ( ( V_56 & V_60 ) != V_61 ) &&
( ( V_56 & V_60 ) != V_62 ) ) ;
V_58 = ( ( V_56 & V_60 ) == V_62 ) ?
V_63 : V_64 ;
if ( ( V_2 -> V_22 & V_66 ) && ( V_48 -> V_22 & V_55 ) &&
( ( V_68 ^ V_56 ) & V_67 ) ) {
if ( V_48 -> V_22 & V_55 )
return - V_25 ;
V_56 ^= V_67 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
}
V_56 &= ~ ( V_65 << V_58 ) ;
V_56 |= ( V_68 & V_65 ) << V_58 ;
if ( V_2 -> V_22 & V_51 ) {
T_1 div = 0 ;
if ( ! ( V_48 -> V_22 & V_55 ) ) {
div = F_9 ( V_2 -> V_9 +
V_54 ) ;
div &= V_69 ;
div >>= V_53 ;
}
V_2 -> div = div + 2 ;
V_2 -> V_47 = 2 ;
}
F_26 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_70 = F_4 ( V_5 -> V_4 ) ;
struct V_1 * V_71 = F_16 ( F_22 ( V_70 ) ) ;
if ( ( V_2 -> V_22 & V_51 ) && ( V_71 -> V_22 & V_72 ) ) {
int div = F_12 ( V_20 ,
V_21 , V_2 -> V_22 , V_73 ) ;
div = F_28 ( div , V_52 ) ;
F_8 ( div << V_53 ,
V_2 -> V_9 + V_54 ) ;
V_2 -> div = div + 2 ;
V_2 -> V_47 = 2 ;
return 0 ;
}
return 0 ;
}
static unsigned long F_29 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static long F_30 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_70 = F_4 ( V_5 -> V_4 ) ;
struct V_1 * V_71 = F_16 ( F_22 ( V_70 ) ) ;
int V_47 = 2 ;
int div ;
if ( ( V_2 -> V_22 & V_51 ) && ( V_71 -> V_22 & V_72 ) ) {
div = F_12 ( * V_74 ,
V_21 , V_2 -> V_22 , V_73 ) ;
div = F_28 ( div , V_52 ) + 2 ;
V_21 = * V_74 * V_47 ;
V_21 += div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
return V_21 ;
}
return * V_74 ;
}
static unsigned long F_31 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static int F_32 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_33 ( V_75 ) ;
V_2 -> V_49 = ( V_56 & V_76 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static int F_34 ( struct V_29 * V_5 )
{
T_1 V_56 ;
V_56 = F_33 ( V_78 ) ;
F_35 ( V_56 | V_79 , V_78 ) ;
V_56 = F_33 ( V_75 ) ;
F_35 ( V_56 | V_76 , V_75 ) ;
return 0 ;
}
static void F_36 ( struct V_29 * V_5 )
{
T_1 V_56 ;
V_56 = F_33 ( V_75 ) ;
F_35 ( V_56 & ~ V_76 , V_75 ) ;
V_56 = F_33 ( V_78 ) ;
F_35 ( V_56 & ~ V_79 , V_78 ) ;
}
static int F_37 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_21 >= V_20 ) {
V_2 -> div = 1 ;
F_35 ( 0 , V_2 -> V_9 ) ;
} else {
unsigned int V_80 ;
T_1 V_56 ;
V_80 = F_38 ( V_20 / 8 , V_21 ) ;
V_2 -> div = V_80 * 8 ;
V_56 = ( V_80 & V_81 ) <<
V_82 ;
V_80 &= V_83 ;
V_80 <<= V_84 ;
V_56 |= V_80 ;
V_56 |= V_85 ;
F_35 ( V_56 , V_2 -> V_9 ) ;
}
return 0 ;
}
static unsigned long F_39 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 ;
T_1 V_47 ;
T_1 div ;
T_1 V_80 ;
V_47 = 1 ;
V_56 = F_33 ( V_2 -> V_9 ) ;
if ( V_56 & V_85 ) {
V_80 = ( V_56 >> V_82 ) &
V_81 ;
V_56 >>= V_84 ;
V_56 &= V_83 ;
V_80 += V_56 ;
div = V_80 * 4 ;
} else {
div = 1 ;
}
if ( V_47 != 0 && div != 0 ) {
V_21 *= V_47 ;
V_21 += div - 1 ;
F_13 ( V_21 , div ) ;
}
return V_21 ;
}
static long F_40 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
int div ;
int V_47 ;
long V_86 = * V_74 ;
V_47 = 1 ;
if ( V_21 >= * V_74 ) {
div = 1 ;
} else {
div = F_38 ( * V_74 / 8 , V_21 ) ;
div *= 8 ;
}
V_86 *= V_47 ;
V_86 += div - 1 ;
F_13 ( V_86 , div ) ;
return V_86 ;
}
static void F_41 ( struct V_29 * V_5 )
{
unsigned long V_87 =
F_3 ( F_4 ( F_4 ( V_5 -> V_4 ) ) ) ;
T_1 V_9 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < F_42 ( V_89 ) ; V_88 ++ ) {
if ( V_87 == V_89 [ V_88 ] . V_90 )
break;
}
if ( V_88 >= F_42 ( V_89 ) ) {
F_10 ( L_4 , V_19 , V_87 ) ;
return;
}
V_9 = F_9 ( V_91 ) ;
V_9 &= ~ F_43 ( ~ 0 ) ;
V_9 |= F_43 (
V_89 [ V_88 ] . V_92 ) ;
V_9 &= ~ F_44 ( ~ 0 ) ;
V_9 |= F_44 (
V_89 [ V_88 ] . V_93 ) ;
V_9 &= ~ V_94 ;
V_9 &= ~ V_95 ;
V_9 &= ~ V_96 ;
F_8 ( V_9 , V_91 ) ;
V_9 = F_9 ( V_97 ) ;
V_9 &= ~ F_45 ( ~ 0 ) ;
V_9 |= F_45 (
V_89 [ V_88 ] . V_98 ) ;
V_9 &= ~ F_46 ( ~ 0 ) ;
V_9 |= F_46 (
V_89 [ V_88 ] . V_99 ) ;
V_9 &= ~ V_100 ;
V_9 &= ~ V_101 ;
V_9 &= ~ V_102 ;
F_8 ( V_9 , V_97 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_103 ,
T_1 V_104 )
{
int V_105 = 0 ;
#if V_106
int V_88 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_10 . V_107 . V_108 ; V_88 ++ ) {
if ( F_9 ( V_103 ) & V_104 ) {
F_48 ( V_109 ) ;
return 0 ;
}
F_48 ( 2 ) ;
}
F_10 ( L_5 ,
F_49 ( V_5 -> V_4 ) ) ;
V_105 = - 1 ;
#else
F_48 ( V_2 -> V_10 . V_107 . V_108 ) ;
#endif
return V_105 ;
}
static int F_50 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_2 -> V_49 = ( V_56 & V_111 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static void F_51 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_2 -> V_22 & V_112 )
F_41 ( V_5 ) ;
}
static int F_52 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
F_53 ( L_6 , V_19 , F_49 ( V_5 -> V_4 ) ) ;
#if V_106
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 |= F_55 ( V_2 ) ;
F_8 ( V_56 , V_2 -> V_9 + F_54 ( V_2 ) ) ;
#endif
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_56 &= ~ V_113 ;
V_56 |= V_111 ;
F_8 ( V_56 , V_2 -> V_9 + V_110 ) ;
if ( V_2 -> V_22 & V_114 ) {
V_56 = F_33 ( V_115 ) ;
V_56 |= V_116 ;
F_35 ( V_56 , V_115 ) ;
}
F_47 ( V_2 , V_2 -> V_9 + V_110 , V_117 ) ;
return 0 ;
}
static void F_56 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
F_53 ( L_6 , V_19 , F_49 ( V_5 -> V_4 ) ) ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ ( V_113 | V_111 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
if ( V_2 -> V_22 & V_114 ) {
V_56 = F_33 ( V_115 ) ;
V_56 &= ~ V_116 ;
F_35 ( V_56 , V_115 ) ;
}
}
static int F_57 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 , V_118 , V_119 ;
unsigned long V_120 ;
const struct V_121 * V_122 ;
struct V_121 V_123 ;
if ( V_2 -> V_22 & V_72 ) {
int V_105 = 0 ;
if ( V_21 != V_2 -> V_10 . V_107 . V_30 ) {
F_10 ( L_7 ,
V_19 , F_49 ( V_5 -> V_4 ) ,
V_2 -> V_10 . V_107 . V_30 , V_21 ) ;
V_105 = - V_25 ;
}
return V_105 ;
}
if ( V_2 -> V_22 & V_114 ) {
if ( V_21 != F_3 ( V_5 -> V_4 ) ) {
F_10 ( L_8 ,
V_19 , F_49 ( V_5 -> V_4 ) ) ;
return - V_25 ;
}
}
V_118 = 0 ;
V_120 = V_20 ;
for ( V_122 = V_2 -> V_10 . V_107 . V_124 ; V_122 -> V_120 != 0 ; V_122 ++ ) {
if ( V_122 -> V_120 == V_120 && V_122 -> V_125 == V_21 ) {
if ( V_2 -> V_22 & V_112 ) {
F_6 ( V_122 -> V_48 < 1 || V_122 -> V_48 > 2 ) ;
if ( V_122 -> V_48 == 1 )
V_118 = V_126 ;
} else {
F_6 ( V_122 -> V_48 < 1 ) ;
for ( V_56 = V_122 -> V_48 ; V_56 > 1 ; V_56 >>= 1 )
V_118 ++ ;
V_118 <<= V_127 ;
}
break;
}
}
if ( V_122 -> V_120 == 0 ) {
unsigned long V_128 ;
F_6 ( V_2 -> V_22 & V_112 ) ;
V_122 = & V_123 ;
switch ( V_120 ) {
case 12000000 :
case 26000000 :
V_128 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2000000 ;
break;
case 13000000 :
V_128 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2600000 ;
break;
case 16800000 :
case 19200000 :
V_128 = ( V_21 <= 1200000 * 1000 ) ? 1200000 : 2400000 ;
break;
default:
F_10 ( L_9 ,
V_19 , V_120 ) ;
F_11 () ;
}
for ( V_123 . V_125 = V_21 ; V_123 . V_125 < 200 * V_128 ;
V_123 . V_125 <<= 1 )
V_118 ++ ;
V_123 . V_48 = 0x1 << V_118 ;
V_123 . V_129 = V_120 / V_128 ;
V_123 . V_3 = V_123 . V_125 / V_128 ;
V_123 . V_130 = V_131 ;
if ( ( V_123 . V_129 > ( V_132 >> V_133 ) ) ||
( V_123 . V_3 > ( V_134 >> V_135 ) ) ||
( V_118 > ( V_136 >> V_127 ) ) ||
( V_123 . V_125 > V_2 -> V_10 . V_107 . V_137 ) ) {
F_10 ( L_10 ,
V_19 , F_49 ( V_5 -> V_4 ) , V_21 ) ;
return - V_25 ;
}
V_118 <<= V_127 ;
}
V_2 -> V_47 = V_122 -> V_3 ;
V_2 -> div = V_122 -> V_129 * V_122 -> V_48 ;
V_119 = V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_56 &= ~ ( V_132 | V_134 |
( ( V_2 -> V_22 & V_112 ) ? V_126 : V_136 ) ) ;
V_56 |= ( V_122 -> V_129 << V_133 ) |
( V_122 -> V_3 << V_135 ) | V_118 ;
if ( V_56 == V_119 )
return 0 ;
if ( V_2 -> V_49 == V_50 ) {
F_56 ( V_5 ) ;
V_56 &= ~ ( V_113 | V_111 ) ;
}
F_8 ( V_56 , V_2 -> V_9 + V_110 ) ;
if ( V_2 -> V_22 & V_138 ) {
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 &= ~ V_139 ;
V_56 |= V_122 -> V_130 << V_140 ;
if ( V_2 -> V_22 & ( V_112 | V_141 ) ) {
V_56 &= ~ V_142 ;
if ( V_122 -> V_3 >= V_143 )
V_56 |= 0x1 << V_144 ;
} else if ( V_2 -> V_22 & ( V_55 | V_114 ) ) {
V_56 &= ~ ( 0x1 << V_145 ) ;
if ( V_21 >= ( V_2 -> V_10 . V_107 . V_137 >> 1 ) )
V_56 |= 0x1 << V_145 ;
}
F_8 ( V_56 , V_2 -> V_9 + F_54 ( V_2 ) ) ;
}
if ( V_2 -> V_49 == V_50 )
F_52 ( V_5 ) ;
V_2 -> V_10 . V_107 . V_30 = V_21 ;
return 0 ;
}
static long F_58 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_120 = * V_74 ;
T_3 V_125 = * V_74 ;
const struct V_121 * V_122 ;
struct V_121 V_123 ;
int V_47 ;
int div ;
T_1 V_118 ;
T_1 V_56 ;
if ( V_2 -> V_22 & V_72 )
return V_2 -> V_10 . V_107 . V_30 ;
if ( V_2 -> V_22 & V_114 )
return F_3 ( V_5 -> V_4 ) ;
V_118 = 0 ;
for ( V_122 = V_2 -> V_10 . V_107 . V_124 ; V_122 -> V_120 != 0 ; V_122 ++ ) {
if ( V_122 -> V_120 == V_120 && V_122 -> V_125 == V_21 ) {
if ( V_2 -> V_22 & V_112 ) {
F_6 ( V_122 -> V_48 < 1 || V_122 -> V_48 > 2 ) ;
if ( V_122 -> V_48 == 1 )
V_118 = V_126 ;
} else {
F_6 ( V_122 -> V_48 < 1 ) ;
for ( V_56 = V_122 -> V_48 ; V_56 > 1 ; V_56 >>= 1 )
V_118 ++ ;
V_118 <<= V_127 ;
}
break;
}
}
if ( V_122 -> V_120 == 0 ) {
unsigned long V_128 ;
F_6 ( V_2 -> V_22 & V_112 ) ;
V_122 = & V_123 ;
switch ( V_120 ) {
case 12000000 :
case 26000000 :
V_128 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2000000 ;
break;
case 13000000 :
V_128 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2600000 ;
break;
case 16800000 :
case 19200000 :
V_128 = ( V_21 <= 1200000 * 1000 ) ? 1200000 : 2400000 ;
break;
default:
F_10 ( L_9 ,
V_19 , V_120 ) ;
F_11 () ;
}
for ( V_123 . V_125 = V_21 ; V_123 . V_125 < 200 * V_128 ;
V_123 . V_125 <<= 1 )
V_118 ++ ;
V_123 . V_48 = 0x1 << V_118 ;
V_123 . V_129 = V_120 / V_128 ;
V_123 . V_3 = V_123 . V_125 / V_128 ;
}
V_47 = V_122 -> V_3 ;
div = V_122 -> V_129 * V_122 -> V_48 ;
V_125 *= V_47 ;
V_125 += div - 1 ;
F_13 ( V_125 , div ) ;
return V_125 ;
}
static unsigned long F_59 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
if ( V_2 -> V_22 & V_72 && ! ( V_56 & V_146 ) ) {
const struct V_121 * V_122 ;
for ( V_122 = V_2 -> V_10 . V_107 . V_124 ; V_122 -> V_120 != 0 ; V_122 ++ ) {
if ( V_122 -> V_120 == V_20 &&
V_122 -> V_125 == V_2 -> V_10 . V_107 . V_30 ) {
V_2 -> V_47 = V_122 -> V_3 ;
V_2 -> div = V_122 -> V_129 * V_122 -> V_48 ;
break;
}
}
F_10 ( L_11 ,
F_49 ( V_5 -> V_4 ) ) ;
F_11 () ;
} else if ( V_56 & V_113 ) {
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
} else {
V_2 -> V_47 = ( V_56 & V_134 ) >> V_135 ;
V_2 -> div = ( V_56 & V_132 ) >> V_133 ;
if ( V_2 -> V_22 & V_112 )
V_2 -> div *= ( V_56 & V_126 ) ? 1 : 2 ;
else
V_2 -> div *= ( 0x1 << ( ( V_56 & V_136 ) >>
V_127 ) ) ;
}
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
int F_60 ( struct V_29 * V_5 ,
enum V_147 V_48 , T_1 V_148 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 , V_149 , V_9 ;
switch ( V_48 ) {
case V_150 :
V_149 = V_151 ;
V_9 = V_2 -> V_9 + V_110 ;
break;
case V_152 :
V_149 = V_153 ;
V_9 = V_2 -> V_9 + F_54 ( V_2 ) ;
break;
case V_154 :
if ( ! ( V_2 -> V_22 & V_155 ) ) {
V_149 = V_156 ;
V_9 = V_2 -> V_9 + V_110 ;
break;
}
default:
return - V_25 ;
}
V_56 = F_9 ( V_9 ) ;
if ( V_148 )
V_56 |= V_149 ;
else
V_56 &= ~ V_149 ;
F_8 ( V_56 , V_9 ) ;
return 0 ;
}
static int F_61 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_2 -> V_49 = ( V_56 & V_157 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static void F_62 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_56 &= ~ ( V_158 | V_157 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_110 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_33 ( V_159 ) ;
V_56 |= V_160 ;
F_35 ( V_56 , V_159 ) ;
V_56 = F_33 ( V_159 ) ;
V_56 |= V_161 ;
F_35 ( V_56 , V_159 ) ;
V_56 = F_33 ( V_159 ) ;
V_56 &= ~ V_160 ;
F_35 ( V_56 , V_159 ) ;
do {
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
} while ( ! ( V_56 & V_162 ) );
}
static int F_64 ( struct V_29 * V_5 , bool V_163 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_70 = F_4 ( V_5 -> V_4 ) ;
const struct V_121 * V_122 ;
T_1 V_56 ;
unsigned long V_21 = V_2 -> V_10 . V_107 . V_30 ;
unsigned long V_120 = F_3 ( V_70 ) ;
for ( V_122 = V_2 -> V_10 . V_107 . V_124 ; V_122 -> V_120 != 0 ; V_122 ++ ) {
if ( V_122 -> V_120 == V_120 && V_122 -> V_125 == V_21 )
break;
}
if ( V_122 -> V_120 == 0 )
return - V_164 ;
F_62 ( V_5 ) ;
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 &= ~ ( V_165 | V_166 ) ;
F_8 ( V_56 , V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
if ( V_163 || ( ! ( V_56 & V_162 ) ) )
F_63 ( V_2 ) ;
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_56 &= ~ V_167 ;
V_56 |= F_65 ( V_122 -> V_129 , V_122 -> V_3 , V_122 -> V_48 , V_122 -> V_130 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_110 ) ;
V_2 -> V_47 = V_122 -> V_3 ;
V_2 -> div = V_122 -> V_129 * V_122 -> V_48 ;
V_56 = F_9 ( V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 |= V_168 ;
V_56 |= V_165 ;
F_8 ( V_56 , V_2 -> V_9 + F_54 ( V_2 ) ) ;
V_56 = F_9 ( V_169 ) ;
V_56 |= V_170 ;
F_8 ( V_56 , V_169 ) ;
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_56 |= ( V_158 | V_157 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_110 ) ;
F_47 ( V_2 , V_2 -> V_9 + F_54 ( V_2 ) , V_171 ) ;
return 0 ;
}
static int F_66 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
return F_64 ( V_5 , ! V_2 -> V_172 ) ;
}
static unsigned long F_67 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_21 = V_20 ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_110 ) ;
V_2 -> V_47 = ( V_56 & V_173 ) >> V_174 ;
V_2 -> div = ( V_56 & V_175 ) >> V_176 ;
V_2 -> div *= ( V_56 & V_177 ) >> V_178 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static int F_68 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 >>= V_2 -> V_179 ;
V_2 -> V_49 = ( V_56 & V_180 ) ? V_50 : V_77 ;
if ( ! ( V_56 & V_181 ) )
V_2 -> V_49 = V_77 ;
} else {
V_2 -> V_49 = V_50 ;
}
return V_2 -> V_49 ;
}
static int F_69 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_182 ;
F_53 ( L_12 , V_19 , F_49 ( V_5 -> V_4 ) ) ;
if ( V_2 -> V_22 & V_51 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_182 = V_56 >> V_2 -> V_179 ;
V_182 &= 0xFFFF ;
V_182 |= V_180 | V_181 ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_179 ) ;
V_56 |= V_182 << V_2 -> V_179 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
} else if ( V_2 -> V_22 & V_66 ) {
return 0 ;
}
return - V_25 ;
}
static void F_70 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_182 ;
F_53 ( L_12 , V_19 , F_49 ( V_5 -> V_4 ) ) ;
if ( V_2 -> V_22 & V_51 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_182 = V_56 >> V_2 -> V_179 ;
V_182 &= 0xFFFF ;
V_182 &= ~ ( V_180 | V_181 ) ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_179 ) ;
V_56 |= V_182 << V_2 -> V_179 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
}
}
static int F_71 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_182 ;
int V_24 ;
if ( V_2 -> V_22 & V_51 ) {
V_24 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_24 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_182 = V_56 >> V_2 -> V_179 ;
V_182 &= 0xFFFF ;
if ( V_2 -> V_22 & V_183 )
V_182 |= V_184 ;
V_182 &= ~ V_185 ;
V_182 |= V_24 << V_186 ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_179 ) ;
V_56 |= V_182 << V_2 -> V_179 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_24 + 2 ;
V_2 -> V_47 = 2 ;
V_2 -> V_30 = V_21 ;
return 0 ;
}
} else if ( V_2 -> V_22 & V_66 ) {
V_2 -> V_30 = V_21 ;
return 0 ;
}
return - V_25 ;
}
static unsigned long F_72 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_187 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 >>= V_2 -> V_179 ;
V_187 = ( V_56 & V_185 ) >> V_186 ;
V_2 -> div = ( V_187 + 2 ) ;
V_2 -> V_47 = 2 ;
} else if ( V_2 -> V_22 & V_66 ) {
if ( V_2 -> V_22 & ( V_141 | V_55 ) ) {
V_2 -> div = 2 ;
V_2 -> V_47 = 1 ;
} else
F_11 () ;
} else {
V_2 -> div = 1 ;
V_2 -> V_47 = 1 ;
}
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static long F_73 ( struct V_29 * V_5 ,
unsigned long V_21 , unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_20 = F_3 ( F_4 ( V_5 -> V_4 ) ) ;
int V_188 ;
if ( V_74 )
V_20 = * V_74 ;
if ( V_2 -> V_22 & V_51 ) {
V_188 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_188 < 0 )
return V_188 ;
return F_38 ( V_20 * 2 , V_188 + 2 ) ;
} else if ( V_2 -> V_22 & V_66 ) {
* V_74 = V_21 * 2 ;
return V_21 ;
}
return - V_25 ;
}
static inline T_1 F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_189 )
return 7 << 29 ;
else if ( V_2 -> V_22 & V_190 )
return 3 << 28 ;
else if ( V_2 -> V_22 & V_191 )
return 3 << ( V_2 -> V_10 . V_11 . V_12 + 4 ) ;
else if ( V_2 -> V_22 & V_141 )
return V_156 ;
else
return 3 << 30 ;
}
static inline T_1 F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_189 )
return 29 ;
else if ( V_2 -> V_22 & V_190 )
return 28 ;
else if ( V_2 -> V_22 & V_191 )
return V_2 -> V_10 . V_11 . V_12 + 4 ;
else if ( V_2 -> V_22 & V_141 )
return V_192 ;
else
return 30 ;
}
static int F_76 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_2 -> V_49 = V_50 ;
if ( ! ( F_9 ( F_77 ( V_2 ) ) & F_78 ( V_2 ) ) )
V_2 -> V_49 = V_77 ;
if ( ! ( V_2 -> V_22 & V_193 ) )
if ( F_9 ( F_79 ( V_2 ) ) & F_78 ( V_2 ) )
V_2 -> V_49 = V_77 ;
return V_2 -> V_49 ;
}
static int F_80 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_194 [ V_2 -> V_10 . V_11 . V_12 ] ++ ;
if ( V_194 [ V_2 -> V_10 . V_11 . V_12 ] > 1 )
return 0 ;
F_26 ( F_78 ( V_2 ) , F_81 ( V_2 ) ) ;
if ( ! ( V_2 -> V_22 & V_193 ) &&
! ( V_2 -> V_22 & V_195 ) ) {
if ( F_9 ( F_79 ( V_2 ) ) &
F_78 ( V_2 ) ) {
F_48 ( 5 ) ;
F_8 ( F_78 ( V_2 ) ,
F_82 ( V_2 ) ) ;
}
}
return 0 ;
}
static void F_83 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_56 ;
V_194 [ V_2 -> V_10 . V_11 . V_12 ] -- ;
if ( V_194 [ V_2 -> V_10 . V_11 . V_12 ] > 0 )
return;
if ( V_2 -> V_22 & V_196 )
V_56 = F_84 () ;
F_26 ( F_78 ( V_2 ) , F_85 ( V_2 ) ) ;
}
void F_86 ( struct V_29 * V_5 , bool assert )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_56 ;
if ( ! ( V_2 -> V_22 & V_193 ) ) {
if ( assert ) {
if ( V_2 -> V_22 & V_196 )
V_56 = F_84 () ;
F_8 ( F_78 ( V_2 ) ,
F_87 ( V_2 ) ) ;
} else
F_8 ( F_78 ( V_2 ) ,
F_82 ( V_2 ) ) ;
}
}
static int F_88 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
if ( ! ( V_2 -> V_22 & V_197 ) )
return ( V_68 == 0 ) ? 0 : ( - V_25 ) ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ F_74 ( V_2 ) ;
V_56 |= ( V_68 << F_75 ( V_2 ) ) ;
F_26 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static T_4 F_89 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
int V_57 = ( V_56 & F_74 ( V_2 ) ) >>
F_75 ( V_2 ) ;
if ( ! ( V_2 -> V_22 & V_197 ) )
return 0 ;
return V_57 ;
}
static int F_90 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
int V_188 ;
if ( V_2 -> V_22 & V_51 ) {
V_188 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_188 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_198 ;
V_56 |= V_188 ;
if ( V_2 -> V_22 & V_199 ) {
if ( V_188 )
V_56 |= V_200 ;
else
V_56 &= ~ V_200 ;
}
F_26 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_188 + 2 ;
V_2 -> V_47 = 2 ;
return 0 ;
}
} else if ( V_2 -> V_22 & V_201 ) {
V_188 = F_14 ( V_20 , V_21 ) ;
if ( V_188 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_202 ;
V_56 |= V_188 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_188 + 1 ;
V_2 -> V_47 = 1 ;
return 0 ;
}
} else if ( V_20 <= V_21 ) {
V_2 -> div = 1 ;
V_2 -> V_47 = 1 ;
return 0 ;
}
return - V_25 ;
}
static long F_91 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_20 = F_3 ( F_4 ( V_5 -> V_4 ) ) ;
int V_188 ;
if ( V_74 )
V_20 = * V_74 ;
if ( V_2 -> V_22 & V_51 ) {
V_188 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_188 < 0 )
return V_188 ;
return F_38 ( V_20 * 2 , V_188 + 2 ) ;
} else if ( V_2 -> V_22 & V_201 ) {
V_188 = F_14 ( V_20 , V_21 ) ;
if ( V_188 < 0 )
return V_188 ;
return F_38 ( V_20 , V_188 + 1 ) ;
}
return - V_25 ;
}
static unsigned long F_92 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_187 = V_56 & V_198 ;
if ( ( V_2 -> V_22 & V_199 ) &&
( ! ( V_56 & V_200 ) ) ) {
V_187 = 0 ;
}
if ( V_2 -> V_22 & V_203 ) {
V_56 &= ~ ( V_198 <<
V_204 ) ;
V_56 |= ( V_205 <<
V_204 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
}
V_2 -> div = V_187 + 2 ;
V_2 -> V_47 = 2 ;
} else if ( V_2 -> V_22 & V_201 ) {
T_1 V_206 = V_56 & V_202 ;
V_2 -> div = V_206 + 1 ;
V_2 -> V_47 = 1 ;
} else {
V_2 -> div = 1 ;
V_2 -> V_47 = 1 ;
}
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static int F_93 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_4 * V_207 = F_94 ( NULL , L_13 ) ;
F_95 (
V_207 , V_154 , V_68 ) ;
return 0 ;
}
int F_96 ( struct V_29 * V_5 ,
enum V_147 V_48 , T_1 V_148 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_208 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_209 ;
V_56 |= ( V_148 << V_210 ) &
V_209 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
int F_97 ( struct V_29 * V_5 ,
enum V_147 V_48 , T_1 V_148 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_211 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_148 )
V_56 |= V_212 ;
else
V_56 &= ~ V_212 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
int F_98 ( struct V_29 * V_5 ,
enum V_147 V_48 , T_1 V_148 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_213 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_148 )
V_56 |= V_214 ;
else
V_56 &= ~ V_214 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
static int F_99 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_33 ( V_2 -> V_9 ) ;
V_2 -> V_49 = ( V_56 & ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ) ? V_50 : V_77 ;
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
return V_2 -> V_49 ;
}
static int F_100 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_101 ( & V_215 , V_22 ) ;
V_56 = F_33 ( V_2 -> V_9 ) ;
V_56 |= ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_35 ( V_56 , V_2 -> V_9 ) ;
F_102 ( & V_215 , V_22 ) ;
return 0 ;
}
static void F_103 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_101 ( & V_215 , V_22 ) ;
V_56 = F_33 ( V_2 -> V_9 ) ;
V_56 &= ~ ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_35 ( V_56 , V_2 -> V_9 ) ;
F_102 ( & V_215 , V_22 ) ;
}
static int F_104 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_101 ( & V_215 , V_22 ) ;
V_56 = F_33 ( V_2 -> V_9 ) ;
V_56 &= ~ F_74 ( V_2 ) ;
V_56 |= ( V_68 << F_75 ( V_2 ) ) ;
F_35 ( V_56 , V_2 -> V_9 ) ;
F_102 ( & V_215 , V_22 ) ;
return 0 ;
}
static T_4 F_105 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_33 ( V_2 -> V_9 ) ;
int V_57 ;
V_57 = ( V_56 & F_74 ( V_2 ) ) >>
F_75 ( V_2 ) ;
return V_57 ;
}
static int F_106 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_2 -> V_49 = V_50 ;
if ( ! ( F_9 ( F_77 ( V_2 ) ) & F_78 ( V_2 ) ) )
V_2 -> V_49 = V_77 ;
return V_2 -> V_49 ;
}
static int F_107 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
if ( V_21 == V_20 ) {
V_56 = F_9 ( V_2 -> V_9 ) | ( 0x1 << V_2 -> V_179 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
return 0 ;
} else if ( V_21 == 2 * V_20 ) {
V_56 = F_9 ( V_2 -> V_9 ) & ( ~ ( 0x1 << V_2 -> V_179 ) ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
V_2 -> V_47 = 2 ;
V_2 -> div = 1 ;
return 0 ;
}
return - V_25 ;
}
static unsigned long F_108 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_47 = V_56 & ( 0x1 << V_2 -> V_179 ) ? 1 : 2 ;
V_2 -> div = 1 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static long F_109 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
unsigned long V_125 = * V_74 ;
F_13 ( V_125 , 2 ) ;
return V_125 ;
}
static int F_110 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_49 = ( V_56 & V_216 ) ? V_77 : V_50 ;
return V_2 -> V_49 ;
}
static int F_111 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
F_8 ( ( V_56 & ( ~ V_216 ) ) , V_2 -> V_9 ) ;
return 0 ;
}
static void F_112 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
F_8 ( ( V_56 | V_216 ) , V_2 -> V_9 ) ;
}
static int F_113 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_217 ;
V_56 |= V_68 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static T_4 F_114 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
int V_57 ;
V_57 = V_56 & V_217 ;
return V_57 ;
}
static int F_115 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_49 = V_56 & ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static int F_116 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 |= ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static void F_117 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
}
static void F_118 ( T_1 V_218 )
{
unsigned int V_9 ;
do {
V_9 = F_119 ( V_219 +
V_220 ) ;
F_120 () ;
} while ( ! ( V_9 & ( 1 << V_218 ) ) );
return;
}
static void F_121 ( T_1 V_218 )
{
F_122 ( F_123 ( V_218 ) ,
V_219 + V_221 ) ;
F_124 () ;
}
static void F_125 ( T_1 V_218 )
{
F_122 ( F_123 ( V_218 ) ,
V_219 + V_222 ) ;
F_126 () ;
}
static void F_127 ( T_1 V_218 )
{
unsigned int V_9 ;
F_122 ( F_128 ( V_218 ) ,
V_219 + V_223 ) ;
V_9 = F_119 ( V_219 +
V_223 ) ;
}
static void F_129 ( T_1 V_218 )
{
unsigned int V_9 ;
V_9 = F_119 ( V_219 + V_224 ) ;
F_122 ( V_9 | F_128 ( V_218 ) ,
V_219 + V_224 ) ;
}
void T_5 F_130 ( void )
{
V_225 = & V_226 ;
}
