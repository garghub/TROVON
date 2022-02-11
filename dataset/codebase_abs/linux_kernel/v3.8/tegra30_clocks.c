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
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_49 = ( ( V_56 >> V_2 -> V_75 ) & V_76 ) ? V_77 : V_50 ;
return V_2 -> V_49 ;
}
static int F_33 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ ( V_76 << V_2 -> V_75 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static void F_34 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 |= V_76 << V_2 -> V_75 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
}
static unsigned long F_35 ( struct V_29 * V_5 ,
unsigned long V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
T_3 V_21 = V_74 ;
V_2 -> div = ( ( V_56 >> V_2 -> V_75 ) & V_78 ) + 1 ;
V_2 -> V_47 = 1 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static int F_36 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
int V_79 = - V_25 ;
T_1 V_56 ;
int V_80 ;
V_56 = F_9 ( V_2 -> V_9 ) ;
for ( V_80 = 1 ; V_80 <= 4 ; V_80 ++ ) {
if ( V_21 == V_20 / V_80 ) {
V_56 &= ~ ( V_78 << V_2 -> V_75 ) ;
V_56 |= ( V_80 - 1 ) << V_2 -> V_75 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_80 ;
V_2 -> V_47 = 1 ;
V_79 = 0 ;
break;
}
}
return V_79 ;
}
static long F_37 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
unsigned long V_20 = * V_74 ;
T_2 V_81 ;
if ( V_21 >= V_20 )
return V_20 ;
V_81 = V_20 ;
V_81 += V_21 - 1 ;
F_13 ( V_81 , V_21 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_81 > 4 )
V_81 = 4 ;
F_13 ( V_20 , V_81 ) ;
return V_20 ;
}
static int F_38 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_39 ( V_82 ) ;
V_2 -> V_49 = ( V_56 & V_83 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static int F_40 ( struct V_29 * V_5 )
{
T_1 V_56 ;
V_56 = F_39 ( V_84 ) ;
F_41 ( V_56 | V_85 , V_84 ) ;
V_56 = F_39 ( V_82 ) ;
F_41 ( V_56 | V_83 , V_82 ) ;
return 0 ;
}
static void F_42 ( struct V_29 * V_5 )
{
T_1 V_56 ;
V_56 = F_39 ( V_82 ) ;
F_41 ( V_56 & ~ V_83 , V_82 ) ;
V_56 = F_39 ( V_84 ) ;
F_41 ( V_56 & ~ V_85 , V_84 ) ;
}
static int F_43 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_21 >= V_20 ) {
V_2 -> div = 1 ;
F_41 ( 0 , V_2 -> V_9 ) ;
} else {
unsigned int V_86 ;
T_1 V_56 ;
V_86 = F_44 ( V_20 / 8 , V_21 ) ;
V_2 -> div = V_86 * 8 ;
V_56 = ( V_86 & V_87 ) <<
V_88 ;
V_86 &= V_89 ;
V_86 <<= V_90 ;
V_56 |= V_86 ;
V_56 |= V_91 ;
F_41 ( V_56 , V_2 -> V_9 ) ;
}
return 0 ;
}
static unsigned long F_45 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 ;
T_1 V_47 ;
T_1 div ;
T_1 V_86 ;
V_47 = 1 ;
V_56 = F_39 ( V_2 -> V_9 ) ;
if ( V_56 & V_91 ) {
V_86 = ( V_56 >> V_88 ) &
V_87 ;
V_56 >>= V_90 ;
V_56 &= V_89 ;
V_86 += V_56 ;
div = V_86 * 4 ;
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
static long F_46 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
int div ;
int V_47 ;
long V_92 = * V_74 ;
V_47 = 1 ;
if ( V_21 >= * V_74 ) {
div = 1 ;
} else {
div = F_44 ( * V_74 / 8 , V_21 ) ;
div *= 8 ;
}
V_92 *= V_47 ;
V_92 += div - 1 ;
F_13 ( V_92 , div ) ;
return V_92 ;
}
static void F_47 ( struct V_29 * V_5 )
{
unsigned long V_93 =
F_3 ( F_4 ( F_4 ( V_5 -> V_4 ) ) ) ;
T_1 V_9 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_48 ( V_94 ) ; V_80 ++ ) {
if ( V_93 == V_94 [ V_80 ] . V_95 )
break;
}
if ( V_80 >= F_48 ( V_94 ) ) {
F_10 ( L_4 , V_19 , V_93 ) ;
return;
}
V_9 = F_9 ( V_96 ) ;
V_9 &= ~ F_49 ( ~ 0 ) ;
V_9 |= F_49 (
V_94 [ V_80 ] . V_97 ) ;
V_9 &= ~ F_50 ( ~ 0 ) ;
V_9 |= F_50 (
V_94 [ V_80 ] . V_98 ) ;
V_9 &= ~ V_99 ;
V_9 &= ~ V_100 ;
V_9 &= ~ V_101 ;
F_8 ( V_9 , V_96 ) ;
V_9 = F_9 ( V_102 ) ;
V_9 &= ~ F_51 ( ~ 0 ) ;
V_9 |= F_51 (
V_94 [ V_80 ] . V_103 ) ;
V_9 &= ~ F_52 ( ~ 0 ) ;
V_9 |= F_52 (
V_94 [ V_80 ] . V_104 ) ;
V_9 &= ~ V_105 ;
V_9 &= ~ V_106 ;
V_9 &= ~ V_107 ;
F_8 ( V_9 , V_102 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_108 ,
T_1 V_109 )
{
int V_79 = 0 ;
#if V_110
int V_80 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_10 . V_111 . V_112 ; V_80 ++ ) {
if ( F_9 ( V_108 ) & V_109 ) {
F_54 ( V_113 ) ;
return 0 ;
}
F_54 ( 2 ) ;
}
F_10 ( L_5 ,
F_55 ( V_5 -> V_4 ) ) ;
V_79 = - 1 ;
#else
F_54 ( V_2 -> V_10 . V_111 . V_112 ) ;
#endif
return V_79 ;
}
static int F_56 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_2 -> V_49 = ( V_56 & V_115 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static void F_57 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_2 -> V_22 & V_116 )
F_47 ( V_5 ) ;
}
static int F_58 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
F_59 ( L_6 , V_19 , F_55 ( V_5 -> V_4 ) ) ;
#if V_110
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 |= F_61 ( V_2 ) ;
F_8 ( V_56 , V_2 -> V_9 + F_60 ( V_2 ) ) ;
#endif
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_56 &= ~ V_117 ;
V_56 |= V_115 ;
F_8 ( V_56 , V_2 -> V_9 + V_114 ) ;
if ( V_2 -> V_22 & V_118 ) {
V_56 = F_39 ( V_119 ) ;
V_56 |= V_120 ;
F_41 ( V_56 , V_119 ) ;
}
F_53 ( V_2 , V_2 -> V_9 + V_114 , V_121 ) ;
return 0 ;
}
static void F_62 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
F_59 ( L_6 , V_19 , F_55 ( V_5 -> V_4 ) ) ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ ( V_117 | V_115 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
if ( V_2 -> V_22 & V_118 ) {
V_56 = F_39 ( V_119 ) ;
V_56 &= ~ V_120 ;
F_41 ( V_56 , V_119 ) ;
}
}
static int F_63 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 , V_122 , V_123 ;
unsigned long V_124 ;
const struct V_125 * V_126 ;
struct V_125 V_127 ;
if ( V_2 -> V_22 & V_72 ) {
int V_79 = 0 ;
if ( V_21 != V_2 -> V_10 . V_111 . V_30 ) {
F_10 ( L_7 ,
V_19 , F_55 ( V_5 -> V_4 ) ,
V_2 -> V_10 . V_111 . V_30 , V_21 ) ;
V_79 = - V_25 ;
}
return V_79 ;
}
if ( V_2 -> V_22 & V_118 ) {
if ( V_21 != F_3 ( V_5 -> V_4 ) ) {
F_10 ( L_8 ,
V_19 , F_55 ( V_5 -> V_4 ) ) ;
return - V_25 ;
}
}
V_122 = 0 ;
V_124 = V_20 ;
for ( V_126 = V_2 -> V_10 . V_111 . V_128 ; V_126 -> V_124 != 0 ; V_126 ++ ) {
if ( V_126 -> V_124 == V_124 && V_126 -> V_129 == V_21 ) {
if ( V_2 -> V_22 & V_116 ) {
F_6 ( V_126 -> V_48 < 1 || V_126 -> V_48 > 2 ) ;
if ( V_126 -> V_48 == 1 )
V_122 = V_130 ;
} else {
F_6 ( V_126 -> V_48 < 1 ) ;
for ( V_56 = V_126 -> V_48 ; V_56 > 1 ; V_56 >>= 1 )
V_122 ++ ;
V_122 <<= V_131 ;
}
break;
}
}
if ( V_126 -> V_124 == 0 ) {
unsigned long V_132 ;
F_6 ( V_2 -> V_22 & V_116 ) ;
V_126 = & V_127 ;
switch ( V_124 ) {
case 12000000 :
case 26000000 :
V_132 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2000000 ;
break;
case 13000000 :
V_132 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2600000 ;
break;
case 16800000 :
case 19200000 :
V_132 = ( V_21 <= 1200000 * 1000 ) ? 1200000 : 2400000 ;
break;
default:
F_10 ( L_9 ,
V_19 , V_124 ) ;
F_11 () ;
}
for ( V_127 . V_129 = V_21 ; V_127 . V_129 < 200 * V_132 ;
V_127 . V_129 <<= 1 )
V_122 ++ ;
V_127 . V_48 = 0x1 << V_122 ;
V_127 . V_133 = V_124 / V_132 ;
V_127 . V_3 = V_127 . V_129 / V_132 ;
V_127 . V_134 = V_135 ;
if ( ( V_127 . V_133 > ( V_136 >> V_137 ) ) ||
( V_127 . V_3 > ( V_138 >> V_139 ) ) ||
( V_122 > ( V_140 >> V_131 ) ) ||
( V_127 . V_129 > V_2 -> V_10 . V_111 . V_141 ) ) {
F_10 ( L_10 ,
V_19 , F_55 ( V_5 -> V_4 ) , V_21 ) ;
return - V_25 ;
}
V_122 <<= V_131 ;
}
V_2 -> V_47 = V_126 -> V_3 ;
V_2 -> div = V_126 -> V_133 * V_126 -> V_48 ;
V_123 = V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_56 &= ~ ( V_136 | V_138 |
( ( V_2 -> V_22 & V_116 ) ? V_130 : V_140 ) ) ;
V_56 |= ( V_126 -> V_133 << V_137 ) |
( V_126 -> V_3 << V_139 ) | V_122 ;
if ( V_56 == V_123 )
return 0 ;
if ( V_2 -> V_49 == V_50 ) {
F_62 ( V_5 ) ;
V_56 &= ~ ( V_117 | V_115 ) ;
}
F_8 ( V_56 , V_2 -> V_9 + V_114 ) ;
if ( V_2 -> V_22 & V_142 ) {
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 &= ~ V_143 ;
V_56 |= V_126 -> V_134 << V_144 ;
if ( V_2 -> V_22 & ( V_116 | V_145 ) ) {
V_56 &= ~ V_146 ;
if ( V_126 -> V_3 >= V_147 )
V_56 |= 0x1 << V_148 ;
} else if ( V_2 -> V_22 & ( V_55 | V_118 ) ) {
V_56 &= ~ ( 0x1 << V_149 ) ;
if ( V_21 >= ( V_2 -> V_10 . V_111 . V_141 >> 1 ) )
V_56 |= 0x1 << V_149 ;
}
F_8 ( V_56 , V_2 -> V_9 + F_60 ( V_2 ) ) ;
}
if ( V_2 -> V_49 == V_50 )
F_58 ( V_5 ) ;
V_2 -> V_10 . V_111 . V_30 = V_21 ;
return 0 ;
}
static long F_64 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_124 = * V_74 ;
T_3 V_129 = * V_74 ;
const struct V_125 * V_126 ;
struct V_125 V_127 ;
int V_47 ;
int div ;
T_1 V_122 ;
T_1 V_56 ;
if ( V_2 -> V_22 & V_72 )
return V_2 -> V_10 . V_111 . V_30 ;
if ( V_2 -> V_22 & V_118 )
return F_3 ( V_5 -> V_4 ) ;
V_122 = 0 ;
for ( V_126 = V_2 -> V_10 . V_111 . V_128 ; V_126 -> V_124 != 0 ; V_126 ++ ) {
if ( V_126 -> V_124 == V_124 && V_126 -> V_129 == V_21 ) {
if ( V_2 -> V_22 & V_116 ) {
F_6 ( V_126 -> V_48 < 1 || V_126 -> V_48 > 2 ) ;
if ( V_126 -> V_48 == 1 )
V_122 = V_130 ;
} else {
F_6 ( V_126 -> V_48 < 1 ) ;
for ( V_56 = V_126 -> V_48 ; V_56 > 1 ; V_56 >>= 1 )
V_122 ++ ;
V_122 <<= V_131 ;
}
break;
}
}
if ( V_126 -> V_124 == 0 ) {
unsigned long V_132 ;
F_6 ( V_2 -> V_22 & V_116 ) ;
V_126 = & V_127 ;
switch ( V_124 ) {
case 12000000 :
case 26000000 :
V_132 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2000000 ;
break;
case 13000000 :
V_132 = ( V_21 <= 1000000 * 1000 ) ? 1000000 : 2600000 ;
break;
case 16800000 :
case 19200000 :
V_132 = ( V_21 <= 1200000 * 1000 ) ? 1200000 : 2400000 ;
break;
default:
F_10 ( L_9 ,
V_19 , V_124 ) ;
F_11 () ;
}
for ( V_127 . V_129 = V_21 ; V_127 . V_129 < 200 * V_132 ;
V_127 . V_129 <<= 1 )
V_122 ++ ;
V_127 . V_48 = 0x1 << V_122 ;
V_127 . V_133 = V_124 / V_132 ;
V_127 . V_3 = V_127 . V_129 / V_132 ;
}
V_47 = V_126 -> V_3 ;
div = V_126 -> V_133 * V_126 -> V_48 ;
V_129 *= V_47 ;
V_129 += div - 1 ;
F_13 ( V_129 , div ) ;
return V_129 ;
}
static unsigned long F_65 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
if ( V_2 -> V_22 & V_72 && ! ( V_56 & V_150 ) ) {
const struct V_125 * V_126 ;
for ( V_126 = V_2 -> V_10 . V_111 . V_128 ; V_126 -> V_124 != 0 ; V_126 ++ ) {
if ( V_126 -> V_124 == V_20 &&
V_126 -> V_129 == V_2 -> V_10 . V_111 . V_30 ) {
V_2 -> V_47 = V_126 -> V_3 ;
V_2 -> div = V_126 -> V_133 * V_126 -> V_48 ;
break;
}
}
F_10 ( L_11 ,
F_55 ( V_5 -> V_4 ) ) ;
F_11 () ;
} else if ( V_56 & V_117 ) {
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
} else {
V_2 -> V_47 = ( V_56 & V_138 ) >> V_139 ;
V_2 -> div = ( V_56 & V_136 ) >> V_137 ;
if ( V_2 -> V_22 & V_116 )
V_2 -> div *= ( V_56 & V_130 ) ? 1 : 2 ;
else
V_2 -> div *= ( 0x1 << ( ( V_56 & V_140 ) >>
V_131 ) ) ;
}
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
int F_66 ( struct V_29 * V_5 ,
enum V_151 V_48 , T_1 V_152 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 , V_153 , V_9 ;
switch ( V_48 ) {
case V_154 :
V_153 = V_155 ;
V_9 = V_2 -> V_9 + V_114 ;
break;
case V_156 :
V_153 = V_157 ;
V_9 = V_2 -> V_9 + F_60 ( V_2 ) ;
break;
case V_158 :
if ( ! ( V_2 -> V_22 & V_159 ) ) {
V_153 = V_160 ;
V_9 = V_2 -> V_9 + V_114 ;
break;
}
default:
return - V_25 ;
}
V_56 = F_9 ( V_9 ) ;
if ( V_152 )
V_56 |= V_153 ;
else
V_56 &= ~ V_153 ;
F_8 ( V_56 , V_9 ) ;
return 0 ;
}
static int F_67 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_2 -> V_49 = ( V_56 & V_161 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static void F_68 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_56 &= ~ ( V_162 | V_161 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_114 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_39 ( V_163 ) ;
V_56 |= V_164 ;
F_41 ( V_56 , V_163 ) ;
V_56 = F_39 ( V_163 ) ;
V_56 |= V_165 ;
F_41 ( V_56 , V_163 ) ;
V_56 = F_39 ( V_163 ) ;
V_56 &= ~ V_164 ;
F_41 ( V_56 , V_163 ) ;
do {
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
} while ( ! ( V_56 & V_166 ) );
}
static int F_70 ( struct V_29 * V_5 , bool V_167 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_70 = F_4 ( V_5 -> V_4 ) ;
const struct V_125 * V_126 ;
T_1 V_56 ;
unsigned long V_21 = V_2 -> V_10 . V_111 . V_30 ;
unsigned long V_124 = F_3 ( V_70 ) ;
for ( V_126 = V_2 -> V_10 . V_111 . V_128 ; V_126 -> V_124 != 0 ; V_126 ++ ) {
if ( V_126 -> V_124 == V_124 && V_126 -> V_129 == V_21 )
break;
}
if ( V_126 -> V_124 == 0 )
return - V_168 ;
F_68 ( V_5 ) ;
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 &= ~ ( V_169 | V_170 ) ;
F_8 ( V_56 , V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
if ( V_167 || ( ! ( V_56 & V_166 ) ) )
F_69 ( V_2 ) ;
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_56 &= ~ V_171 ;
V_56 |= F_71 ( V_126 -> V_133 , V_126 -> V_3 , V_126 -> V_48 , V_126 -> V_134 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_114 ) ;
V_2 -> V_47 = V_126 -> V_3 ;
V_2 -> div = V_126 -> V_133 * V_126 -> V_48 ;
V_56 = F_9 ( V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 |= V_172 ;
V_56 |= V_169 ;
F_8 ( V_56 , V_2 -> V_9 + F_60 ( V_2 ) ) ;
V_56 = F_9 ( V_173 ) ;
V_56 |= V_174 ;
F_8 ( V_56 , V_173 ) ;
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_56 |= ( V_162 | V_161 ) ;
F_8 ( V_56 , V_2 -> V_9 + V_114 ) ;
F_53 ( V_2 , V_2 -> V_9 + F_60 ( V_2 ) , V_175 ) ;
return 0 ;
}
static int F_72 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
return F_70 ( V_5 , ! V_2 -> V_176 ) ;
}
static unsigned long F_73 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_21 = V_20 ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 + V_114 ) ;
V_2 -> V_47 = ( V_56 & V_177 ) >> V_178 ;
V_2 -> div = ( V_56 & V_179 ) >> V_180 ;
V_2 -> div *= ( V_56 & V_181 ) >> V_182 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static int F_74 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 >>= V_2 -> V_75 ;
V_2 -> V_49 = ( V_56 & V_183 ) ? V_50 : V_77 ;
if ( ! ( V_56 & V_184 ) )
V_2 -> V_49 = V_77 ;
} else {
V_2 -> V_49 = V_50 ;
}
return V_2 -> V_49 ;
}
static int F_75 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_185 ;
F_59 ( L_12 , V_19 , F_55 ( V_5 -> V_4 ) ) ;
if ( V_2 -> V_22 & V_51 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_185 = V_56 >> V_2 -> V_75 ;
V_185 &= 0xFFFF ;
V_185 |= V_183 | V_184 ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_75 ) ;
V_56 |= V_185 << V_2 -> V_75 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
} else if ( V_2 -> V_22 & V_66 ) {
return 0 ;
}
return - V_25 ;
}
static void F_76 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_185 ;
F_59 ( L_12 , V_19 , F_55 ( V_5 -> V_4 ) ) ;
if ( V_2 -> V_22 & V_51 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_185 = V_56 >> V_2 -> V_75 ;
V_185 &= 0xFFFF ;
V_185 &= ~ ( V_183 | V_184 ) ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_75 ) ;
V_56 |= V_185 << V_2 -> V_75 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
}
}
static int F_77 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
T_1 V_185 ;
int V_24 ;
if ( V_2 -> V_22 & V_51 ) {
V_24 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_24 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_185 = V_56 >> V_2 -> V_75 ;
V_185 &= 0xFFFF ;
if ( V_2 -> V_22 & V_186 )
V_185 |= V_187 ;
V_185 &= ~ V_188 ;
V_185 |= V_24 << V_189 ;
V_56 &= ~ ( 0xFFFF << V_2 -> V_75 ) ;
V_56 |= V_185 << V_2 -> V_75 ;
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
static unsigned long F_78 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_190 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 >>= V_2 -> V_75 ;
V_190 = ( V_56 & V_188 ) >> V_189 ;
V_2 -> div = ( V_190 + 2 ) ;
V_2 -> V_47 = 2 ;
} else if ( V_2 -> V_22 & V_66 ) {
if ( V_2 -> V_22 & ( V_145 | V_55 ) ) {
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
static long F_79 ( struct V_29 * V_5 ,
unsigned long V_21 , unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_20 = F_3 ( F_4 ( V_5 -> V_4 ) ) ;
int V_81 ;
if ( V_74 )
V_20 = * V_74 ;
if ( V_2 -> V_22 & V_51 ) {
V_81 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_81 < 0 )
return V_81 ;
return F_44 ( V_20 * 2 , V_81 + 2 ) ;
} else if ( V_2 -> V_22 & V_66 ) {
* V_74 = V_21 * 2 ;
return V_21 ;
}
return - V_25 ;
}
static inline T_1 F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_191 )
return 7 << 29 ;
else if ( V_2 -> V_22 & V_192 )
return 3 << 28 ;
else if ( V_2 -> V_22 & V_193 )
return 3 << ( V_2 -> V_10 . V_11 . V_12 + 4 ) ;
else if ( V_2 -> V_22 & V_145 )
return V_160 ;
else
return 3 << 30 ;
}
static inline T_1 F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_191 )
return 29 ;
else if ( V_2 -> V_22 & V_192 )
return 28 ;
else if ( V_2 -> V_22 & V_193 )
return V_2 -> V_10 . V_11 . V_12 + 4 ;
else if ( V_2 -> V_22 & V_145 )
return V_194 ;
else
return 30 ;
}
static int F_82 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_2 -> V_49 = V_50 ;
if ( ! ( F_9 ( F_83 ( V_2 ) ) & F_84 ( V_2 ) ) )
V_2 -> V_49 = V_77 ;
if ( ! ( V_2 -> V_22 & V_195 ) )
if ( F_9 ( F_85 ( V_2 ) ) & F_84 ( V_2 ) )
V_2 -> V_49 = V_77 ;
return V_2 -> V_49 ;
}
static int F_86 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_196 [ V_2 -> V_10 . V_11 . V_12 ] ++ ;
if ( V_196 [ V_2 -> V_10 . V_11 . V_12 ] > 1 )
return 0 ;
F_26 ( F_84 ( V_2 ) , F_87 ( V_2 ) ) ;
if ( ! ( V_2 -> V_22 & V_195 ) &&
! ( V_2 -> V_22 & V_197 ) ) {
if ( F_9 ( F_85 ( V_2 ) ) &
F_84 ( V_2 ) ) {
F_54 ( 5 ) ;
F_8 ( F_84 ( V_2 ) ,
F_88 ( V_2 ) ) ;
}
}
return 0 ;
}
static void F_89 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_56 ;
V_196 [ V_2 -> V_10 . V_11 . V_12 ] -- ;
if ( V_196 [ V_2 -> V_10 . V_11 . V_12 ] > 0 )
return;
if ( V_2 -> V_22 & V_198 )
V_56 = F_90 () ;
F_26 ( F_84 ( V_2 ) , F_91 ( V_2 ) ) ;
}
void F_92 ( struct V_29 * V_5 , bool assert )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_56 ;
if ( ! ( V_2 -> V_22 & V_195 ) ) {
if ( assert ) {
if ( V_2 -> V_22 & V_198 )
V_56 = F_90 () ;
F_8 ( F_84 ( V_2 ) ,
F_93 ( V_2 ) ) ;
} else
F_8 ( F_84 ( V_2 ) ,
F_88 ( V_2 ) ) ;
}
}
static int F_94 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
if ( ! ( V_2 -> V_22 & V_199 ) )
return ( V_68 == 0 ) ? 0 : ( - V_25 ) ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ F_80 ( V_2 ) ;
V_56 |= ( V_68 << F_81 ( V_2 ) ) ;
F_26 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static T_4 F_95 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
int V_57 = ( V_56 & F_80 ( V_2 ) ) >>
F_81 ( V_2 ) ;
if ( ! ( V_2 -> V_22 & V_199 ) )
return 0 ;
return V_57 ;
}
static int F_96 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
int V_81 ;
if ( V_2 -> V_22 & V_51 ) {
V_81 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_81 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_200 ;
V_56 |= V_81 ;
if ( V_2 -> V_22 & V_201 ) {
if ( V_81 )
V_56 |= V_202 ;
else
V_56 &= ~ V_202 ;
}
F_26 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_81 + 2 ;
V_2 -> V_47 = 2 ;
return 0 ;
}
} else if ( V_2 -> V_22 & V_203 ) {
V_81 = F_14 ( V_20 , V_21 ) ;
if ( V_81 >= 0 ) {
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_204 ;
V_56 |= V_81 ;
F_26 ( V_56 , V_2 -> V_9 ) ;
V_2 -> div = V_81 + 1 ;
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
static long F_97 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
unsigned long V_20 = F_3 ( F_4 ( V_5 -> V_4 ) ) ;
int V_81 ;
if ( V_74 )
V_20 = * V_74 ;
if ( V_2 -> V_22 & V_51 ) {
V_81 = F_12 (
V_20 , V_21 , V_2 -> V_22 , V_27 ) ;
if ( V_81 < 0 )
return V_81 ;
return F_44 ( V_20 * 2 , V_81 + 2 ) ;
} else if ( V_2 -> V_22 & V_203 ) {
V_81 = F_14 ( V_20 , V_21 ) ;
if ( V_81 < 0 )
return V_81 ;
return F_44 ( V_20 , V_81 + 1 ) ;
}
return - V_25 ;
}
static unsigned long F_98 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_2 -> V_22 & V_51 ) {
T_1 V_190 = V_56 & V_200 ;
if ( ( V_2 -> V_22 & V_201 ) &&
( ! ( V_56 & V_202 ) ) ) {
V_190 = 0 ;
}
if ( V_2 -> V_22 & V_205 ) {
V_56 &= ~ ( V_200 <<
V_206 ) ;
V_56 |= ( V_207 <<
V_206 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
}
V_2 -> div = V_190 + 2 ;
V_2 -> V_47 = 2 ;
} else if ( V_2 -> V_22 & V_203 ) {
T_1 V_208 = V_56 & V_204 ;
V_2 -> div = V_208 + 1 ;
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
static int F_99 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_4 * V_209 = F_100 ( NULL , L_13 ) ;
F_101 (
V_209 , V_158 , V_68 ) ;
return 0 ;
}
int F_102 ( struct V_29 * V_5 ,
enum V_151 V_48 , T_1 V_152 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_210 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_211 ;
V_56 |= ( V_152 << V_212 ) &
V_211 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
int F_103 ( struct V_29 * V_5 ,
enum V_151 V_48 , T_1 V_152 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_213 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_152 )
V_56 |= V_214 ;
else
V_56 &= ~ V_214 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
int F_104 ( struct V_29 * V_5 ,
enum V_151 V_48 , T_1 V_152 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
if ( V_48 == V_215 ) {
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
if ( V_152 )
V_56 |= V_216 ;
else
V_56 &= ~ V_216 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
return - V_25 ;
}
static int F_105 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_39 ( V_2 -> V_9 ) ;
V_2 -> V_49 = ( V_56 & ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ) ? V_50 : V_77 ;
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
return V_2 -> V_49 ;
}
static int F_106 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_107 ( & V_217 , V_22 ) ;
V_56 = F_39 ( V_2 -> V_9 ) ;
V_56 |= ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_41 ( V_56 , V_2 -> V_9 ) ;
F_108 ( & V_217 , V_22 ) ;
return 0 ;
}
static void F_109 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_107 ( & V_217 , V_22 ) ;
V_56 = F_39 ( V_2 -> V_9 ) ;
V_56 &= ~ ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_41 ( V_56 , V_2 -> V_9 ) ;
F_108 ( & V_217 , V_22 ) ;
}
static int F_110 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
unsigned long V_22 ;
F_107 ( & V_217 , V_22 ) ;
V_56 = F_39 ( V_2 -> V_9 ) ;
V_56 &= ~ F_80 ( V_2 ) ;
V_56 |= ( V_68 << F_81 ( V_2 ) ) ;
F_41 ( V_56 , V_2 -> V_9 ) ;
F_108 ( & V_217 , V_22 ) ;
return 0 ;
}
static T_4 F_111 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_39 ( V_2 -> V_9 ) ;
int V_57 ;
V_57 = ( V_56 & F_80 ( V_2 ) ) >>
F_81 ( V_2 ) ;
return V_57 ;
}
static int F_112 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
V_2 -> V_49 = V_50 ;
if ( ! ( F_9 ( F_83 ( V_2 ) ) & F_84 ( V_2 ) ) )
V_2 -> V_49 = V_77 ;
return V_2 -> V_49 ;
}
static int F_113 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
if ( V_21 == V_20 ) {
V_56 = F_9 ( V_2 -> V_9 ) | ( 0x1 << V_2 -> V_75 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
V_2 -> V_47 = 1 ;
V_2 -> div = 1 ;
return 0 ;
} else if ( V_21 == 2 * V_20 ) {
V_56 = F_9 ( V_2 -> V_9 ) & ( ~ ( 0x1 << V_2 -> V_75 ) ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
V_2 -> V_47 = 2 ;
V_2 -> div = 1 ;
return 0 ;
}
return - V_25 ;
}
static unsigned long F_114 ( struct V_29 * V_5 ,
unsigned long V_20 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_3 V_21 = V_20 ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_47 = V_56 & ( 0x1 << V_2 -> V_75 ) ? 1 : 2 ;
V_2 -> div = 1 ;
if ( V_2 -> V_47 != 0 && V_2 -> div != 0 ) {
V_21 *= V_2 -> V_47 ;
V_21 += V_2 -> div - 1 ;
F_13 ( V_21 , V_2 -> div ) ;
}
return V_21 ;
}
static long F_115 ( struct V_29 * V_5 , unsigned long V_21 ,
unsigned long * V_74 )
{
unsigned long V_129 = * V_74 ;
F_13 ( V_129 , 2 ) ;
return V_129 ;
}
static int F_116 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_49 = ( V_56 & V_218 ) ? V_77 : V_50 ;
return V_2 -> V_49 ;
}
static int F_117 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
F_8 ( ( V_56 & ( ~ V_218 ) ) , V_2 -> V_9 ) ;
return 0 ;
}
static void F_118 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
F_8 ( ( V_56 | V_218 ) , V_2 -> V_9 ) ;
}
static int F_119 ( struct V_29 * V_5 , T_4 V_68 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 ;
V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ V_219 ;
V_56 |= V_68 ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static T_4 F_120 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
int V_57 ;
V_57 = V_56 & V_219 ;
return V_57 ;
}
static int F_121 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_2 -> V_49 = V_56 & ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ? V_50 : V_77 ;
return V_2 -> V_49 ;
}
static int F_122 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 |= ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
return 0 ;
}
static void F_123 ( struct V_29 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
T_1 V_56 = F_9 ( V_2 -> V_9 ) ;
V_56 &= ~ ( 0x1 << V_2 -> V_10 . V_11 . V_12 ) ;
F_8 ( V_56 , V_2 -> V_9 ) ;
}
static void F_124 ( T_1 V_220 )
{
unsigned int V_9 ;
do {
V_9 = F_125 ( V_221 +
V_222 ) ;
F_126 () ;
} while ( ! ( V_9 & ( 1 << V_220 ) ) );
return;
}
static void F_127 ( T_1 V_220 )
{
F_128 ( F_129 ( V_220 ) ,
V_221 + V_223 ) ;
F_130 () ;
}
static void F_131 ( T_1 V_220 )
{
F_128 ( F_129 ( V_220 ) ,
V_221 + V_224 ) ;
F_132 () ;
}
static void F_133 ( T_1 V_220 )
{
unsigned int V_9 ;
F_128 ( F_134 ( V_220 ) ,
V_221 + V_225 ) ;
V_9 = F_125 ( V_221 +
V_225 ) ;
}
static void F_135 ( T_1 V_220 )
{
unsigned int V_9 ;
V_9 = F_125 ( V_221 + V_226 ) ;
F_128 ( V_9 | F_134 ( V_220 ) ,
V_221 + V_226 ) ;
}
static bool F_136 ( void )
{
unsigned int V_227 ;
int V_228 ;
V_227 = F_125 ( V_221 +
V_222 ) ;
V_228 = F_137 ( V_229 ) ||
F_137 ( V_230 ) ||
F_137 ( V_231 ) ;
if ( ( ( V_227 & 0xE ) != 0xE ) || V_228 )
return false ;
return true ;
}
static void F_138 ( void )
{
V_232 . V_233 =
F_125 ( V_221 + V_234 ) ;
F_128 ( 3 << 30 , V_221 + V_234 ) ;
V_232 . V_235 =
F_125 ( V_221 + V_236 ) ;
V_232 . V_237 =
F_125 ( V_221 + V_238 ) ;
V_232 . V_239 =
F_125 ( V_221 + V_240 ) ;
V_232 . V_241 =
F_125 ( V_221 + V_242 ) ;
}
static void F_139 ( void )
{
unsigned int V_9 , V_243 ;
V_9 = F_125 ( V_221 + V_236 ) ;
V_243 = ( V_9 >> V_244 ) & 0xF ;
if ( V_243 == V_245 )
V_9 = ( V_9 >> V_246 ) & 0xF ;
else if ( V_243 == V_247 )
V_9 = ( V_9 >> V_248 ) & 0xF ;
else
F_11 () ;
if ( V_9 != V_249 ) {
F_128 ( V_232 . V_239 ,
V_221 + V_240 ) ;
F_128 ( V_232 . V_237 ,
V_221 + V_238 ) ;
if ( V_232 . V_237 & ( 1 << 30 ) )
F_54 ( 300 ) ;
}
F_128 ( V_232 . V_241 ,
V_221 + V_242 ) ;
F_128 ( V_232 . V_235 ,
V_221 + V_236 ) ;
F_128 ( V_232 . V_233 ,
V_221 + V_234 ) ;
}
void T_5 F_140 ( void )
{
V_250 = & V_251 ;
}
