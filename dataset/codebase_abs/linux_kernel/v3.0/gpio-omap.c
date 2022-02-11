static inline struct V_1 * F_1 ( int V_2 )
{
if ( F_2 () ) {
if ( F_3 ( V_2 ) )
return & V_1 [ 0 ] ;
return & V_1 [ 1 ] ;
}
if ( F_4 () ) {
if ( F_3 ( V_2 ) )
return & V_1 [ 0 ] ;
return & V_1 [ 1 + ( V_2 >> 4 ) ] ;
}
if ( F_5 () ) {
if ( F_3 ( V_2 ) )
return & V_1 [ 0 ] ;
return & V_1 [ 1 + ( V_2 >> 5 ) ] ;
}
if ( F_6 () )
return & V_1 [ V_2 >> 5 ] ;
if ( F_7 () || F_8 () )
return & V_1 [ V_2 >> 5 ] ;
F_9 () ;
return NULL ;
}
static inline int F_10 ( int V_2 )
{
if ( F_5 () )
return V_2 & 0x1f ;
if ( F_6 () )
return V_2 & 0x1f ;
if ( F_7 () || F_8 () )
return V_2 & 0x1f ;
return V_2 & 0x0f ;
}
static inline int F_11 ( int V_2 )
{
if ( V_2 < 0 )
return - 1 ;
if ( F_12 () && F_3 ( V_2 ) ) {
if ( V_2 >= V_3 + 16 )
return - 1 ;
return 0 ;
}
if ( F_2 () && V_2 < 16 )
return 0 ;
if ( ( F_4 () ) && V_2 < 64 )
return 0 ;
if ( F_5 () && V_2 < 192 )
return 0 ;
if ( F_13 () && V_2 < 128 )
return 0 ;
if ( F_14 () && V_2 < 160 )
return 0 ;
if ( ( F_7 () || F_8 () ) && V_2 < 192 )
return 0 ;
return - 1 ;
}
static int F_15 ( int V_2 )
{
if ( F_16 ( F_11 ( V_2 ) < 0 ) ) {
F_17 ( V_4 L_1 , V_2 ) ;
F_18 () ;
return - 1 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_5 , int V_2 , int V_6 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_12 / V_5 -> V_13 ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_15 ;
break;
#endif
#ifdef F_22
case V_16 :
V_7 += V_17 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_21 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_7 += V_25 ;
break;
#endif
#if F_23 ( V_26 )
case V_27 :
V_7 += V_28 ;
break;
#endif
default:
F_24 ( 1 ) ;
return;
}
V_9 = F_25 ( V_7 ) ;
if ( V_6 )
V_9 |= 1 << V_2 ;
else
V_9 &= ~ ( 1 << V_2 ) ;
F_26 ( V_9 , V_7 ) ;
}
static void F_27 ( struct V_1 * V_5 , int V_2 , int V_29 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 = 0 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_30 / V_5 -> V_13 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 |= 1 << V_2 ;
else
V_9 &= ~ ( 1 << V_2 ) ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_31 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 |= 1 << V_2 ;
else
V_9 &= ~ ( 1 << V_2 ) ;
break;
#endif
#ifdef F_22
case V_16 :
if ( V_29 )
V_7 += V_32 ;
else
V_7 += V_33 ;
V_9 = 1 << V_2 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_34 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 |= 1 << V_2 ;
else
V_9 &= ~ ( 1 << V_2 ) ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
if ( V_29 )
V_7 += V_35 ;
else
V_7 += V_36 ;
V_9 = 1 << V_2 ;
break;
#endif
#ifdef V_26
case V_27 :
if ( V_29 )
V_7 += V_37 ;
else
V_7 += V_38 ;
V_9 = 1 << V_2 ;
break;
#endif
default:
F_24 ( 1 ) ;
return;
}
F_26 ( V_9 , V_7 ) ;
}
static int F_28 ( struct V_1 * V_5 , int V_2 )
{
void T_1 * V_7 ;
if ( F_15 ( V_2 ) < 0 )
return - V_39 ;
V_7 = V_5 -> V_8 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_40 / V_5 -> V_13 ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_41 ;
break;
#endif
#ifdef F_22
case V_16 :
V_7 += V_42 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_43 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_7 += V_44 ;
break;
#endif
#ifdef V_26
case V_27 :
V_7 += V_45 ;
break;
#endif
default:
return - V_39 ;
}
return ( F_25 ( V_7 )
& ( 1 << F_10 ( V_2 ) ) ) != 0 ;
}
static int F_29 ( struct V_1 * V_5 , int V_2 )
{
void T_1 * V_7 ;
if ( F_15 ( V_2 ) < 0 )
return - V_39 ;
V_7 = V_5 -> V_8 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_30 / V_5 -> V_13 ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_31 ;
break;
#endif
#ifdef F_22
case V_16 :
V_7 += V_46 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_34 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_7 += V_47 ;
break;
#endif
#ifdef V_26
case V_27 :
V_7 += V_48 ;
break;
#endif
default:
return - V_39 ;
}
return ( F_25 ( V_7 ) & ( 1 << F_10 ( V_2 ) ) ) != 0 ;
}
static void F_30 ( struct V_1 * V_5 , unsigned V_2 ,
unsigned V_49 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_50 ;
T_2 V_9 ;
if ( ! V_5 -> V_51 )
return;
if ( V_49 < 32 )
V_49 = 0x01 ;
else if ( V_49 > 7936 )
V_49 = 0xff ;
else
V_49 = ( V_49 / 0x1f ) - 1 ;
V_9 = 1 << F_10 ( V_2 ) ;
if ( V_5 -> V_10 == V_27 )
V_7 += V_52 ;
else
V_7 += V_53 ;
F_26 ( V_49 , V_7 ) ;
V_7 = V_5 -> V_8 ;
if ( V_5 -> V_10 == V_27 )
V_7 += V_54 ;
else
V_7 += V_55 ;
V_50 = F_25 ( V_7 ) ;
if ( V_49 ) {
V_50 |= V_9 ;
F_31 ( V_5 -> V_56 ) ;
} else {
V_50 &= ~ V_9 ;
F_32 ( V_5 -> V_56 ) ;
}
V_5 -> V_57 = V_50 ;
F_26 ( V_50 , V_7 ) ;
}
static inline void F_33 ( struct V_1 * V_5 , int V_2 ,
int V_58 )
{
void T_1 * V_8 = V_5 -> V_8 ;
T_2 V_59 = 1 << V_2 ;
if ( F_8 () ) {
F_34 ( V_60 , V_59 ,
V_58 & V_61 ) ;
F_34 ( V_62 , V_59 ,
V_58 & V_63 ) ;
F_34 ( V_64 , V_59 ,
V_58 & V_65 ) ;
F_34 ( V_66 , V_59 ,
V_58 & V_67 ) ;
} else {
F_34 ( V_68 , V_59 ,
V_58 & V_61 ) ;
F_34 ( V_69 , V_59 ,
V_58 & V_63 ) ;
F_34 ( V_70 , V_59 ,
V_58 & V_65 ) ;
F_34 ( V_71 , V_59 ,
V_58 & V_67 ) ;
}
if ( F_35 ( ! ( V_5 -> V_72 & V_59 ) ) ) {
if ( F_8 () ) {
F_34 ( V_73 , V_59 ,
V_58 != 0 ) ;
} else {
if ( V_58 & V_74 )
F_26 ( 1 << V_2 , V_5 -> V_8
+ V_75 ) ;
else
F_26 ( 1 << V_2 , V_5 -> V_8
+ V_76 ) ;
}
}
if ( F_7 () || F_8 () ||
( V_5 -> V_72 & V_59 ) ) {
if ( V_58 & V_74 )
V_5 -> V_77 |= V_59 ;
else
V_5 -> V_77 &= ~ V_59 ;
}
if ( F_8 () ) {
V_5 -> V_78 =
F_25 ( V_5 -> V_8 + V_60 ) |
F_25 ( V_5 -> V_8 + V_62 ) ;
} else {
V_5 -> V_78 =
F_25 ( V_5 -> V_8 + V_68 ) |
F_25 ( V_5 -> V_8 + V_69 ) ;
}
}
static void F_36 ( struct V_1 * V_5 , int V_2 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 = 0 ;
switch ( V_5 -> V_10 ) {
case V_11 :
V_7 += V_79 / V_5 -> V_13 ;
break;
#ifdef F_21
case V_14 :
V_7 += V_80 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_81 ;
break;
#endif
default:
return;
}
V_9 = F_25 ( V_7 ) ;
if ( ( V_9 >> V_2 ) & 1 )
V_9 &= ~ ( 1 << V_2 ) ;
else
V_9 |= 1 << V_2 ;
F_26 ( V_9 , V_7 ) ;
}
static int F_37 ( struct V_1 * V_5 , int V_2 , int V_58 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 = 0 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_79 / V_5 -> V_13 ;
V_9 = F_25 ( V_7 ) ;
if ( ( V_58 & V_82 ) == V_74 )
V_5 -> V_83 |= 1 << V_2 ;
if ( V_58 & V_65 )
V_9 |= 1 << V_2 ;
else if ( V_58 & V_67 )
V_9 &= ~ ( 1 << V_2 ) ;
else
goto V_84;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_80 ;
V_9 = F_25 ( V_7 ) ;
if ( ( V_58 & V_82 ) == V_74 )
V_5 -> V_83 |= 1 << V_2 ;
if ( V_58 & V_65 )
V_9 |= 1 << V_2 ;
else if ( V_58 & V_67 )
V_9 &= ~ ( 1 << V_2 ) ;
else
goto V_84;
break;
#endif
#ifdef F_22
case V_16 :
if ( V_2 & 0x08 )
V_7 += V_85 ;
else
V_7 += V_86 ;
V_2 &= 0x07 ;
V_9 = F_25 ( V_7 ) ;
V_9 &= ~ ( 3 << ( V_2 << 1 ) ) ;
if ( V_58 & V_65 )
V_9 |= 2 << ( V_2 << 1 ) ;
if ( V_58 & V_67 )
V_9 |= 1 << ( V_2 << 1 ) ;
if ( V_58 )
F_26 ( 1 << V_2 , V_5 -> V_8 + V_87 ) ;
else
F_26 ( 1 << V_2 , V_5 -> V_8 + V_88 ) ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_81 ;
V_9 = F_25 ( V_7 ) ;
if ( ( V_58 & V_82 ) == V_74 )
V_5 -> V_83 |= 1 << V_2 ;
if ( V_58 & V_65 )
V_9 |= 1 << V_2 ;
else if ( V_58 & V_67 )
V_9 &= ~ ( 1 << V_2 ) ;
else
goto V_84;
break;
#endif
#ifdef F_38
case V_24 :
case V_27 :
F_33 ( V_5 , V_2 , V_58 ) ;
return 0 ;
#endif
default:
goto V_84;
}
F_26 ( V_9 , V_7 ) ;
return 0 ;
V_84:
return - V_39 ;
}
static int F_39 ( struct V_89 * V_90 , unsigned type )
{
struct V_1 * V_5 ;
unsigned V_2 ;
int V_91 ;
unsigned long V_92 ;
if ( ! F_40 () && V_90 -> V_93 > V_94 )
V_2 = F_41 ( V_90 -> V_93 - V_94 ) ;
else
V_2 = V_90 -> V_93 - V_95 ;
if ( F_15 ( V_2 ) < 0 )
return - V_39 ;
if ( type & ~ V_82 )
return - V_39 ;
if ( ! F_40 ()
&& ( type & ( V_61 | V_63 ) ) )
return - V_39 ;
V_5 = F_42 ( V_90 ) ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
V_91 = F_37 ( V_5 , F_10 ( V_2 ) , type ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
if ( type & ( V_61 | V_63 ) )
F_45 ( V_90 -> V_93 , V_97 ) ;
else if ( type & ( V_67 | V_65 ) )
F_45 ( V_90 -> V_93 , V_98 ) ;
return V_91 ;
}
static void F_46 ( struct V_1 * V_5 , int V_99 )
{
void T_1 * V_7 = V_5 -> V_8 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
return;
#endif
#ifdef F_21
case V_14 :
V_7 += V_100 ;
break;
#endif
#ifdef F_22
case V_16 :
V_7 += V_101 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_102 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_7 += V_103 ;
break;
#endif
#if F_23 ( V_26 )
case V_27 :
V_7 += V_104 ;
break;
#endif
default:
F_24 ( 1 ) ;
return;
}
F_26 ( V_99 , V_7 ) ;
if ( F_6 () || F_7 () )
V_7 = V_5 -> V_8 + V_105 ;
else if ( F_8 () )
V_7 = V_5 -> V_8 + V_106 ;
if ( F_6 () || F_7 () || F_8 () ) {
F_26 ( V_99 , V_7 ) ;
F_25 ( V_7 ) ;
}
}
static inline void F_47 ( struct V_1 * V_5 , int V_2 )
{
F_46 ( V_5 , 1 << F_10 ( V_2 ) ) ;
}
static T_2 F_48 ( struct V_1 * V_5 )
{
void T_1 * V_7 = V_5 -> V_8 ;
int V_107 = 0 ;
T_2 V_9 ;
T_2 V_108 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_109 / V_5 -> V_13 ;
V_108 = 0xffff ;
V_107 = 1 ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_110 ;
V_108 = 0xffff ;
V_107 = 1 ;
break;
#endif
#ifdef F_22
case V_16 :
V_7 += V_111 ;
V_108 = 0xffff ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_112 ;
V_108 = 0xffffffff ;
V_107 = 1 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_7 += V_113 ;
V_108 = 0xffffffff ;
break;
#endif
#if F_23 ( V_26 )
case V_27 :
V_7 += V_114 ;
V_108 = 0xffffffff ;
break;
#endif
default:
F_24 ( 1 ) ;
return 0 ;
}
V_9 = F_25 ( V_7 ) ;
if ( V_107 )
V_9 = ~ V_9 ;
V_9 &= V_108 ;
return V_9 ;
}
static void F_49 ( struct V_1 * V_5 , int V_99 , int V_29 )
{
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 ;
switch ( V_5 -> V_10 ) {
#ifdef F_20
case V_11 :
V_7 += V_109 / V_5 -> V_13 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 &= ~ ( V_99 ) ;
else
V_9 |= V_99 ;
break;
#endif
#ifdef F_21
case V_14 :
V_7 += V_110 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 &= ~ ( V_99 ) ;
else
V_9 |= V_99 ;
break;
#endif
#ifdef F_22
case V_16 :
if ( V_29 )
V_7 += V_115 ;
else
V_7 += V_116 ;
V_9 = V_99 ;
break;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
case V_20 :
V_7 += V_112 ;
V_9 = F_25 ( V_7 ) ;
if ( V_29 )
V_9 &= ~ ( V_99 ) ;
else
V_9 |= V_99 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
if ( V_29 )
V_7 += V_117 ;
else
V_7 += V_118 ;
V_9 = V_99 ;
break;
#endif
#ifdef V_26
case V_27 :
if ( V_29 )
V_7 += V_114 ;
else
V_7 += V_119 ;
V_9 = V_99 ;
break;
#endif
default:
F_24 ( 1 ) ;
return;
}
F_26 ( V_9 , V_7 ) ;
}
static inline void F_50 ( struct V_1 * V_5 , int V_2 , int V_29 )
{
F_49 ( V_5 , 1 << F_10 ( V_2 ) , V_29 ) ;
}
static int F_51 ( struct V_1 * V_5 , int V_2 , int V_29 )
{
unsigned long V_120 ( V_92 ) ;
switch ( V_5 -> V_10 ) {
#ifdef F_22
case V_11 :
case V_16 :
F_43 ( & V_5 -> V_96 , V_92 ) ;
if ( V_29 )
V_5 -> V_121 |= ( 1 << V_2 ) ;
else
V_5 -> V_121 &= ~ ( 1 << V_2 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
#endif
#ifdef F_38
case V_24 :
case V_27 :
if ( V_5 -> V_72 & ( 1 << V_2 ) ) {
F_17 ( V_4 L_2
L_3 ,
( V_5 - V_1 ) * 32 + V_2 ) ;
return - V_39 ;
}
F_43 ( & V_5 -> V_96 , V_92 ) ;
if ( V_29 )
V_5 -> V_121 |= ( 1 << V_2 ) ;
else
V_5 -> V_121 &= ~ ( 1 << V_2 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
#endif
default:
F_17 ( V_4 L_4 ,
V_5 -> V_10 ) ;
return - V_39 ;
}
}
static void F_52 ( struct V_1 * V_5 , int V_2 )
{
F_19 ( V_5 , F_10 ( V_2 ) , 1 ) ;
F_50 ( V_5 , V_2 , 0 ) ;
F_47 ( V_5 , V_2 ) ;
F_37 ( V_5 , F_10 ( V_2 ) , V_122 ) ;
}
static int F_53 ( struct V_89 * V_90 , unsigned int V_29 )
{
unsigned int V_2 = V_90 -> V_93 - V_95 ;
struct V_1 * V_5 ;
int V_91 ;
if ( F_15 ( V_2 ) < 0 )
return - V_123 ;
V_5 = F_42 ( V_90 ) ;
V_91 = F_51 ( V_5 , F_10 ( V_2 ) , V_29 ) ;
return V_91 ;
}
static int F_54 ( struct V_124 * V_125 , unsigned V_126 )
{
struct V_1 * V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_37 ( V_5 , V_126 , V_122 ) ;
#ifdef F_21
if ( V_5 -> V_10 == V_14 ) {
void T_1 * V_7 ;
V_7 = V_5 -> V_8 + V_127 ;
F_26 ( F_25 ( V_7 ) | ( 1 << V_126 ) , V_7 ) ;
}
#endif
if ( ! F_12 () ) {
if ( ! V_5 -> V_128 ) {
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_129 ;
if ( F_6 () || F_7 () )
V_7 += V_130 ;
else if ( F_8 () )
V_7 += V_131 ;
V_129 = F_25 ( V_7 ) ;
V_129 &= 0xFFFFFFFE ;
F_26 ( V_129 , V_7 ) ;
}
V_5 -> V_128 |= 1 << V_126 ;
}
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static void F_56 ( struct V_124 * V_125 , unsigned V_126 )
{
struct V_1 * V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
#ifdef F_22
if ( V_5 -> V_10 == V_16 ) {
void T_1 * V_7 = V_5 -> V_8 + V_88 ;
F_26 ( 1 << V_126 , V_7 ) ;
}
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
if ( V_5 -> V_10 == V_24 ) {
void T_1 * V_7 = V_5 -> V_8 + V_76 ;
F_26 ( 1 << V_126 , V_7 ) ;
}
#endif
#ifdef V_26
if ( V_5 -> V_10 == V_27 ) {
void T_1 * V_7 = V_5 -> V_8 + V_73 ;
F_26 ( 1 << V_126 , V_7 ) ;
}
#endif
if ( ! F_12 () ) {
V_5 -> V_128 &= ~ ( 1 << V_126 ) ;
if ( ! V_5 -> V_128 ) {
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_129 ;
if ( F_6 () || F_7 () )
V_7 += V_130 ;
else if ( F_8 () )
V_7 += V_131 ;
V_129 = F_25 ( V_7 ) ;
V_129 |= 1 ;
F_26 ( V_129 , V_7 ) ;
}
}
F_52 ( V_5 , V_5 -> V_125 . V_8 + V_126 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
static void F_57 ( unsigned int V_93 , struct V_132 * V_133 )
{
void T_1 * V_134 = NULL ;
T_2 V_135 ;
unsigned int V_136 , V_137 ;
struct V_1 * V_5 ;
T_2 V_138 = 0 ;
int V_139 = 0 ;
struct V_140 * V_125 = F_58 ( V_133 ) ;
F_59 ( V_125 , V_133 ) ;
V_5 = F_60 ( V_93 ) ;
#ifdef F_20
if ( V_5 -> V_10 == V_11 )
V_134 = V_5 -> V_8 +
V_141 / V_5 -> V_13 ;
#endif
#ifdef F_21
if ( V_5 -> V_10 == V_14 )
V_134 = V_5 -> V_8 + V_100 ;
#endif
#if F_23 ( F_22 )
if ( V_5 -> V_10 == V_16 )
V_134 = V_5 -> V_8 + V_101 ;
#endif
#if F_23 ( V_18 ) || F_23 ( V_19 )
if ( V_5 -> V_10 == V_20 )
V_134 = V_5 -> V_8 + V_102 ;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
if ( V_5 -> V_10 == V_24 )
V_134 = V_5 -> V_8 + V_103 ;
#endif
#if F_23 ( V_26 )
if ( V_5 -> V_10 == V_27 )
V_134 = V_5 -> V_8 + V_104 ;
#endif
if ( F_24 ( ! V_134 ) )
goto exit;
while( 1 ) {
T_2 V_142 , V_78 = 0 ;
T_2 V_143 ;
V_143 = F_48 ( V_5 ) ;
V_142 = V_135 = F_25 ( V_134 ) & V_143 ;
if ( F_2 () && ( V_5 -> V_10 == V_11 ) )
V_135 &= 0x0000ffff ;
if ( F_40 () ) {
V_78 = V_5 -> V_78 & V_143 ;
}
F_49 ( V_5 , V_142 & ~ V_78 , 0 ) ;
F_46 ( V_5 , V_142 & ~ V_78 ) ;
F_49 ( V_5 , V_142 & ~ V_78 , 1 ) ;
if ( ! V_78 && ! V_139 ) {
V_139 = 1 ;
F_61 ( V_125 , V_133 ) ;
}
V_135 |= V_138 ;
V_138 = 0 ;
if ( ! V_135 )
break;
V_136 = V_5 -> V_144 ;
for (; V_135 != 0 ; V_135 >>= 1 , V_136 ++ ) {
V_137 = F_10 ( F_62 ( V_136 ) ) ;
if ( ! ( V_135 & 1 ) )
continue;
#ifdef F_20
if ( V_5 -> V_83 & ( 1 << V_137 ) )
F_36 ( V_5 , V_137 ) ;
#endif
F_63 ( V_136 ) ;
}
}
exit:
if ( ! V_139 )
F_61 ( V_125 , V_133 ) ;
}
static void F_64 ( struct V_89 * V_90 )
{
unsigned int V_2 = V_90 -> V_93 - V_95 ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_52 ( V_5 , V_2 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
static void F_65 ( struct V_89 * V_90 )
{
unsigned int V_2 = V_90 -> V_93 - V_95 ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
F_47 ( V_5 , V_2 ) ;
}
static void F_66 ( struct V_89 * V_90 )
{
unsigned int V_2 = V_90 -> V_93 - V_95 ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_50 ( V_5 , V_2 , 0 ) ;
F_37 ( V_5 , F_10 ( V_2 ) , V_122 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
static void F_67 ( struct V_89 * V_90 )
{
unsigned int V_2 = V_90 -> V_93 - V_95 ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
unsigned int V_145 = 1 << F_10 ( V_2 ) ;
T_2 V_58 = F_68 ( V_90 ) ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
if ( V_58 )
F_37 ( V_5 , F_10 ( V_2 ) , V_58 ) ;
if ( V_5 -> V_78 & V_145 ) {
F_50 ( V_5 , V_2 , 0 ) ;
F_47 ( V_5 , V_2 ) ;
}
F_50 ( V_5 , V_2 , 1 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
static void F_69 ( struct V_89 * V_90 )
{
}
static void F_70 ( struct V_89 * V_90 )
{
unsigned int V_2 = F_41 ( V_90 -> V_93 - V_94 ) ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
F_50 ( V_5 , V_2 , 0 ) ;
}
static void F_71 ( struct V_89 * V_90 )
{
unsigned int V_2 = F_41 ( V_90 -> V_93 - V_94 ) ;
struct V_1 * V_5 = F_42 ( V_90 ) ;
F_50 ( V_5 , V_2 , 1 ) ;
}
static int F_72 ( struct V_146 * V_147 )
{
struct V_148 * V_149 = F_73 ( V_147 ) ;
struct V_1 * V_5 = F_74 ( V_149 ) ;
void T_1 * V_150 = V_5 -> V_8 +
V_109 / V_5 -> V_13 ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
V_5 -> V_151 = F_25 ( V_150 ) ;
F_26 ( 0xffff & ~ V_5 -> V_121 , V_150 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static int F_75 ( struct V_146 * V_147 )
{
struct V_148 * V_149 = F_73 ( V_147 ) ;
struct V_1 * V_5 = F_74 ( V_149 ) ;
void T_1 * V_150 = V_5 -> V_8 +
V_109 / V_5 -> V_13 ;
unsigned long V_92 ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_26 ( V_5 -> V_151 , V_150 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static inline void F_76 ( void )
{
struct V_1 * V_5 = F_1 ( F_41 ( 0 ) ) ;
F_77 ( & V_152 , V_5 ) ;
if ( F_78 ( & V_153 ) == 0 )
( void ) F_79 ( & V_152 ) ;
}
static inline void F_76 ( void ) {}
static inline void F_76 ( void ) {}
static int F_80 ( struct V_124 * V_125 , unsigned V_126 )
{
struct V_1 * V_5 ;
unsigned long V_92 ;
V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_19 ( V_5 , V_126 , 1 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_5 , int V_108 )
{
void T_1 * V_7 = V_5 -> V_8 ;
switch ( V_5 -> V_10 ) {
case V_11 :
V_7 += V_12 / V_5 -> V_13 ;
break;
case V_14 :
V_7 += V_15 ;
break;
case V_16 :
V_7 += V_17 ;
break;
case V_20 :
V_7 += V_21 ;
break;
case V_24 :
V_7 += V_25 ;
break;
case V_27 :
V_7 += V_28 ;
break;
default:
F_82 ( 1 , L_5 ) ;
return - V_39 ;
}
return F_25 ( V_7 ) & V_108 ;
}
static int F_83 ( struct V_124 * V_125 , unsigned V_126 )
{
struct V_1 * V_5 ;
void T_1 * V_7 ;
int V_2 ;
T_2 V_108 ;
V_2 = V_125 -> V_8 + V_126 ;
V_5 = F_1 ( V_2 ) ;
V_7 = V_5 -> V_8 ;
V_108 = 1 << F_10 ( V_2 ) ;
if ( F_81 ( V_5 , V_108 ) )
return F_28 ( V_5 , V_2 ) ;
else
return F_29 ( V_5 , V_2 ) ;
}
static int F_84 ( struct V_124 * V_125 , unsigned V_126 , int V_154 )
{
struct V_1 * V_5 ;
unsigned long V_92 ;
V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_27 ( V_5 , V_126 , V_154 ) ;
F_19 ( V_5 , V_126 , 0 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static int F_85 ( struct V_124 * V_125 , unsigned V_126 ,
unsigned V_49 )
{
struct V_1 * V_5 ;
unsigned long V_92 ;
V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
if ( ! V_5 -> V_56 ) {
V_5 -> V_56 = F_86 ( V_5 -> V_147 , L_6 ) ;
if ( F_87 ( V_5 -> V_56 ) )
F_88 ( V_5 -> V_147 , L_7 ) ;
}
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_30 ( V_5 , V_126 , V_49 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
return 0 ;
}
static void F_89 ( struct V_124 * V_125 , unsigned V_126 , int V_154 )
{
struct V_1 * V_5 ;
unsigned long V_92 ;
V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_27 ( V_5 , V_126 , V_154 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
static int F_90 ( struct V_124 * V_125 , unsigned V_126 )
{
struct V_1 * V_5 ;
V_5 = F_55 ( V_125 , struct V_1 , V_125 ) ;
return V_5 -> V_144 + V_126 ;
}
static void T_3 F_91 ( struct V_1 * V_5 )
{
T_2 V_155 ;
if ( F_4 () && ! ( V_5 -> V_10 != V_11 ) )
V_155 = F_92 ( V_5 -> V_8 + V_156 ) ;
else if ( F_6 () || F_7 () )
V_155 = F_25 ( V_5 -> V_8 + V_157 ) ;
else if ( F_8 () )
V_155 = F_25 ( V_5 -> V_8 + V_158 ) ;
else
return;
F_17 ( V_159 L_8 ,
( V_155 >> 4 ) & 0x0f , V_155 & 0x0f ) ;
}
static inline int F_93 ( struct V_148 * V_149 )
{
V_1 = F_94 ( V_160 * sizeof( struct V_1 ) ,
V_161 ) ;
if ( ! V_1 ) {
F_88 ( & V_149 -> V_147 , L_9 ) ;
return - V_162 ;
}
return 0 ;
}
static void F_95 ( struct V_1 * V_5 , int V_163 )
{
if ( F_40 () ) {
if ( F_8 () ) {
F_26 ( 0xffffffff , V_5 -> V_8 +
V_119 ) ;
F_26 ( 0x00000000 , V_5 -> V_8 +
V_54 ) ;
F_26 ( 0 , V_5 -> V_8 + V_131 ) ;
} else if ( F_7 () ) {
F_26 ( 0x00000000 , V_5 -> V_8 +
V_113 ) ;
F_26 ( 0xffffffff , V_5 -> V_8 +
V_103 ) ;
F_26 ( 0x00000000 , V_5 -> V_8 +
V_55 ) ;
F_26 ( 0 , V_5 -> V_8 + V_130 ) ;
} else if ( F_6 () ) {
static const T_2 V_72 [] = {
0xe203ffc0 , 0x08700040
} ;
if ( V_163 < F_96 ( V_72 ) )
V_5 -> V_72 = V_72 [ V_163 ] ;
}
} else if ( F_12 () ) {
if ( F_97 ( V_5 ) )
F_98 ( 0xffff , V_5 -> V_8 +
V_109 / V_5 -> V_13 ) ;
if ( F_2 () && V_5 -> V_10 == V_14 ) {
F_98 ( 0xffff , V_5 -> V_8
+ V_110 ) ;
F_98 ( 0x0000 , V_5 -> V_8
+ V_100 ) ;
}
if ( F_4 () && V_5 -> V_10 == V_16 ) {
F_98 ( 0x0000 , V_5 -> V_8
+ V_111 ) ;
F_98 ( 0xffff , V_5 -> V_8
+ V_101 ) ;
F_98 ( 0x0014 , V_5 -> V_8
+ V_164 ) ;
F_99 ( F_100 ( V_165 ) | 0x04 ,
V_165 ) ;
}
if ( F_5 () && V_5 -> V_10 == V_20 ) {
F_26 ( 0xffffffff , V_5 -> V_8
+ V_112 ) ;
F_26 ( 0x00000000 , V_5 -> V_8
+ V_102 ) ;
}
}
}
static void T_4 F_101 ( struct V_1 * V_5 )
{
int V_166 ;
static int V_2 ;
V_5 -> V_128 = 0 ;
V_5 -> V_125 . V_167 = F_54 ;
V_5 -> V_125 . free = F_56 ;
V_5 -> V_125 . V_168 = F_80 ;
V_5 -> V_125 . V_169 = F_83 ;
V_5 -> V_125 . V_170 = F_84 ;
V_5 -> V_125 . V_171 = F_85 ;
V_5 -> V_125 . V_172 = F_89 ;
V_5 -> V_125 . V_173 = F_90 ;
if ( F_97 ( V_5 ) ) {
V_5 -> V_125 . V_174 = L_10 ;
#ifdef F_22
V_5 -> V_125 . V_147 = & V_152 . V_147 ;
#endif
V_5 -> V_125 . V_8 = F_41 ( 0 ) ;
} else {
V_5 -> V_125 . V_174 = L_11 ;
V_5 -> V_125 . V_8 = V_2 ;
V_2 += V_175 ;
}
V_5 -> V_125 . V_176 = V_175 ;
F_102 ( & V_5 -> V_125 ) ;
for ( V_166 = V_5 -> V_144 ;
V_166 < V_5 -> V_144 + V_175 ; V_166 ++ ) {
F_103 ( V_166 , & V_177 ) ;
F_104 ( V_166 , V_5 ) ;
if ( F_97 ( V_5 ) )
F_105 ( V_166 , & V_178 ) ;
else
F_105 ( V_166 , & V_179 ) ;
F_106 ( V_166 , V_180 ) ;
F_107 ( V_166 , V_181 ) ;
}
F_108 ( V_5 -> V_93 , F_57 ) ;
F_109 ( V_5 -> V_93 , V_5 ) ;
}
static int T_4 F_110 ( struct V_148 * V_149 )
{
static int V_182 ;
struct V_183 * V_184 ;
struct V_185 * V_186 ;
int V_163 ;
struct V_1 * V_5 ;
if ( ! V_149 -> V_147 . V_187 )
return - V_39 ;
V_184 = V_149 -> V_147 . V_187 ;
if ( ! V_182 ) {
int V_188 ;
V_188 = F_93 ( V_149 ) ;
if ( V_188 )
return V_188 ;
}
V_163 = V_149 -> V_163 ;
V_5 = & V_1 [ V_163 ] ;
V_186 = F_111 ( V_149 , V_189 , 0 ) ;
if ( F_16 ( ! V_186 ) ) {
F_88 ( & V_149 -> V_147 , L_12 , V_163 ) ;
return - V_123 ;
}
V_5 -> V_93 = V_186 -> V_190 ;
V_5 -> V_144 = V_184 -> V_144 ;
V_5 -> V_10 = V_184 -> V_191 ;
V_5 -> V_147 = & V_149 -> V_147 ;
V_5 -> V_51 = V_184 -> V_51 ;
V_5 -> V_13 = V_184 -> V_192 ;
V_175 = V_184 -> V_175 ;
F_112 ( & V_5 -> V_96 ) ;
V_186 = F_111 ( V_149 , V_193 , 0 ) ;
if ( F_16 ( ! V_186 ) ) {
F_88 ( & V_149 -> V_147 , L_13 , V_163 ) ;
return - V_123 ;
}
V_5 -> V_8 = F_113 ( V_186 -> V_190 , F_114 ( V_186 ) ) ;
if ( ! V_5 -> V_8 ) {
F_88 ( & V_149 -> V_147 , L_14 , V_163 ) ;
return - V_162 ;
}
F_115 ( V_5 -> V_147 ) ;
F_116 ( V_5 -> V_147 ) ;
F_95 ( V_5 , V_163 ) ;
F_101 ( V_5 ) ;
F_91 ( V_5 ) ;
if ( ! V_182 )
V_182 = 1 ;
return 0 ;
}
static int F_117 ( void )
{
int V_194 ;
if ( ! F_40 () && ! F_4 () )
return 0 ;
for ( V_194 = 0 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
void T_1 * V_195 ;
void T_1 * V_196 ;
void T_1 * V_197 ;
unsigned long V_92 ;
switch ( V_5 -> V_10 ) {
#ifdef F_22
case V_16 :
V_195 = V_5 -> V_8 + V_198 ;
V_196 = V_5 -> V_8 + V_88 ;
V_197 = V_5 -> V_8 + V_87 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_195 = V_5 -> V_8 + V_199 ;
V_196 = V_5 -> V_8 + V_76 ;
V_197 = V_5 -> V_8 + V_75 ;
break;
#endif
#ifdef V_26
case V_27 :
V_195 = V_5 -> V_8 + V_73 ;
V_196 = V_5 -> V_8 + V_73 ;
V_197 = V_5 -> V_8 + V_73 ;
break;
#endif
default:
continue;
}
F_43 ( & V_5 -> V_96 , V_92 ) ;
V_5 -> V_151 = F_25 ( V_195 ) ;
F_26 ( 0xffffffff , V_196 ) ;
F_26 ( V_5 -> V_121 , V_197 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
return 0 ;
}
static void F_118 ( void )
{
int V_194 ;
if ( ! F_40 () && ! F_4 () )
return;
for ( V_194 = 0 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
void T_1 * V_196 ;
void T_1 * V_197 ;
unsigned long V_92 ;
switch ( V_5 -> V_10 ) {
#ifdef F_22
case V_16 :
V_196 = V_5 -> V_8 + V_88 ;
V_197 = V_5 -> V_8 + V_87 ;
break;
#endif
#if F_23 ( V_22 ) || F_23 ( V_23 )
case V_24 :
V_196 = V_5 -> V_8 + V_76 ;
V_197 = V_5 -> V_8 + V_75 ;
break;
#endif
#ifdef V_26
case V_27 :
V_196 = V_5 -> V_8 + V_73 ;
V_197 = V_5 -> V_8 + V_73 ;
break;
#endif
default:
continue;
}
F_43 ( & V_5 -> V_96 , V_92 ) ;
F_26 ( 0xffffffff , V_196 ) ;
F_26 ( V_5 -> V_151 , V_197 ) ;
F_44 ( & V_5 -> V_96 , V_92 ) ;
}
}
void F_119 ( int V_200 )
{
int V_194 , V_201 = 0 ;
int V_202 = 0 ;
if ( F_7 () )
V_202 = 1 ;
for ( V_194 = V_202 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
T_2 V_203 = 0 , V_204 = 0 ;
int V_166 ;
for ( V_166 = 0 ; V_166 < F_120 ( V_5 -> V_57 ) ; V_166 ++ )
F_32 ( V_5 -> V_56 ) ;
if ( ! V_200 )
continue;
if ( ! ( V_5 -> V_77 ) )
continue;
if ( F_6 () || F_7 () ) {
V_5 -> V_205 = F_25 ( V_5 -> V_8 +
V_44 ) ;
V_203 = F_25 ( V_5 -> V_8 +
V_71 ) ;
V_204 = F_25 ( V_5 -> V_8 +
V_70 ) ;
}
if ( F_8 () ) {
V_5 -> V_205 = F_25 ( V_5 -> V_8 +
V_45 ) ;
V_203 = F_25 ( V_5 -> V_8 +
V_66 ) ;
V_204 = F_25 ( V_5 -> V_8 +
V_64 ) ;
}
V_5 -> V_206 = V_203 ;
V_5 -> V_207 = V_204 ;
V_203 &= ~ V_5 -> V_77 ;
V_204 &= ~ V_5 -> V_77 ;
if ( F_6 () || F_7 () ) {
F_26 ( V_203 , V_5 -> V_8 +
V_71 ) ;
F_26 ( V_204 , V_5 -> V_8 +
V_70 ) ;
}
if ( F_8 () ) {
F_26 ( V_203 , V_5 -> V_8 + V_66 ) ;
F_26 ( V_204 , V_5 -> V_8 + V_64 ) ;
}
V_201 ++ ;
}
if ( ! V_201 ) {
V_208 = 0 ;
return;
}
V_208 = 1 ;
}
void F_121 ( void )
{
int V_194 ;
int V_202 = 0 ;
if ( F_7 () )
V_202 = 1 ;
for ( V_194 = V_202 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
T_2 V_9 = 0 , V_209 , V_210 , V_211 ;
int V_166 ;
for ( V_166 = 0 ; V_166 < F_120 ( V_5 -> V_57 ) ; V_166 ++ )
F_31 ( V_5 -> V_56 ) ;
if ( ! V_208 )
continue;
if ( ! ( V_5 -> V_77 ) )
continue;
if ( F_6 () || F_7 () ) {
F_26 ( V_5 -> V_206 ,
V_5 -> V_8 + V_71 ) ;
F_26 ( V_5 -> V_207 ,
V_5 -> V_8 + V_70 ) ;
V_9 = F_25 ( V_5 -> V_8 + V_44 ) ;
}
if ( F_8 () ) {
F_26 ( V_5 -> V_206 ,
V_5 -> V_8 + V_66 ) ;
F_26 ( V_5 -> V_207 ,
V_5 -> V_8 + V_64 ) ;
V_9 = F_25 ( V_5 -> V_8 + V_45 ) ;
}
V_9 ^= V_5 -> V_205 ;
V_9 &= V_5 -> V_77 ;
V_210 = V_9 & V_5 -> V_206 ;
V_210 &= V_5 -> V_205 ;
V_211 = V_9 & V_5 -> V_207 ;
V_211 &= ~ ( V_5 -> V_205 ) ;
V_209 = V_9 & ( ~ ( V_5 -> V_206 ) &
~ ( V_5 -> V_207 ) ) ;
V_209 |= V_210 | V_211 ;
if ( V_209 ) {
T_2 V_212 , V_213 ;
if ( F_6 () || F_7 () ) {
V_212 = F_25 ( V_5 -> V_8 +
V_68 ) ;
V_213 = F_25 ( V_5 -> V_8 +
V_69 ) ;
F_26 ( V_212 | V_209 , V_5 -> V_8 +
V_68 ) ;
F_26 ( V_213 | V_209 , V_5 -> V_8 +
V_69 ) ;
F_26 ( V_212 , V_5 -> V_8 +
V_68 ) ;
F_26 ( V_213 , V_5 -> V_8 +
V_69 ) ;
}
if ( F_8 () ) {
V_212 = F_25 ( V_5 -> V_8 +
V_60 ) ;
V_213 = F_25 ( V_5 -> V_8 +
V_62 ) ;
F_26 ( V_212 | V_9 , V_5 -> V_8 +
V_60 ) ;
F_26 ( V_213 | V_9 , V_5 -> V_8 +
V_62 ) ;
F_26 ( V_212 , V_5 -> V_8 +
V_60 ) ;
F_26 ( V_213 , V_5 -> V_8 +
V_62 ) ;
}
}
}
}
void F_122 ( void )
{
int V_194 ;
for ( V_194 = 1 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
V_214 [ V_194 ] . V_215 =
F_25 ( V_5 -> V_8 + V_113 ) ;
V_214 [ V_194 ] . V_216 =
F_25 ( V_5 -> V_8 + V_217 ) ;
V_214 [ V_194 ] . V_218 =
F_25 ( V_5 -> V_8 + V_199 ) ;
V_214 [ V_194 ] . V_129 =
F_25 ( V_5 -> V_8 + V_130 ) ;
V_214 [ V_194 ] . V_219 =
F_25 ( V_5 -> V_8 + V_25 ) ;
V_214 [ V_194 ] . V_220 =
F_25 ( V_5 -> V_8 + V_68 ) ;
V_214 [ V_194 ] . V_221 =
F_25 ( V_5 -> V_8 + V_69 ) ;
V_214 [ V_194 ] . V_222 =
F_25 ( V_5 -> V_8 + V_70 ) ;
V_214 [ V_194 ] . V_223 =
F_25 ( V_5 -> V_8 + V_71 ) ;
V_214 [ V_194 ] . V_224 =
F_25 ( V_5 -> V_8 + V_47 ) ;
}
}
void F_123 ( void )
{
int V_194 ;
for ( V_194 = 1 ; V_194 < V_160 ; V_194 ++ ) {
struct V_1 * V_5 = & V_1 [ V_194 ] ;
F_26 ( V_214 [ V_194 ] . V_215 ,
V_5 -> V_8 + V_113 ) ;
F_26 ( V_214 [ V_194 ] . V_216 ,
V_5 -> V_8 + V_217 ) ;
F_26 ( V_214 [ V_194 ] . V_218 ,
V_5 -> V_8 + V_199 ) ;
F_26 ( V_214 [ V_194 ] . V_129 ,
V_5 -> V_8 + V_130 ) ;
F_26 ( V_214 [ V_194 ] . V_219 ,
V_5 -> V_8 + V_25 ) ;
F_26 ( V_214 [ V_194 ] . V_220 ,
V_5 -> V_8 + V_68 ) ;
F_26 ( V_214 [ V_194 ] . V_221 ,
V_5 -> V_8 + V_69 ) ;
F_26 ( V_214 [ V_194 ] . V_222 ,
V_5 -> V_8 + V_70 ) ;
F_26 ( V_214 [ V_194 ] . V_223 ,
V_5 -> V_8 + V_71 ) ;
F_26 ( V_214 [ V_194 ] . V_224 ,
V_5 -> V_8 + V_47 ) ;
}
}
static int T_3 F_124 ( void )
{
return F_78 ( & V_225 ) ;
}
static int T_3 F_125 ( void )
{
F_76 () ;
#if F_23 ( F_22 ) || F_23 ( F_38 )
if ( F_4 () || F_40 () )
F_126 ( & V_226 ) ;
#endif
return 0 ;
}
