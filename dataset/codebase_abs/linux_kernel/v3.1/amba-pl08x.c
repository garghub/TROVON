static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
return V_9 & V_12 ;
}
static void F_6 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_7 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = & V_14 -> V_21 [ 0 ] ;
T_1 V_9 ;
V_13 -> V_22 = V_14 ;
while ( F_4 ( V_18 ) )
F_7 () ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_1
L_2 ,
V_18 -> V_25 , V_20 -> V_26 , V_20 -> V_27 , V_20 -> V_20 , V_20 -> V_28 ,
V_14 -> V_29 ) ;
F_9 ( V_20 -> V_26 , V_18 -> V_10 + V_30 ) ;
F_9 ( V_20 -> V_27 , V_18 -> V_10 + V_31 ) ;
F_9 ( V_20 -> V_20 , V_18 -> V_10 + V_32 ) ;
F_9 ( V_20 -> V_28 , V_18 -> V_10 + V_33 ) ;
F_9 ( V_14 -> V_29 , V_18 -> V_10 + V_11 ) ;
while ( F_5 ( V_16 -> V_10 + V_34 ) & ( 1 << V_18 -> V_25 ) )
F_7 () ;
V_9 = F_5 ( V_18 -> V_10 + V_11 ) ;
while ( ( V_9 & V_12 ) || ( V_9 & V_35 ) )
V_9 = F_5 ( V_18 -> V_10 + V_11 ) ;
F_9 ( V_9 | V_35 , V_18 -> V_10 + V_11 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
T_1 V_9 ;
int V_36 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 |= V_37 ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
for ( V_36 = 1000 ; V_36 ; V_36 -- ) {
if ( ! F_4 ( V_8 ) )
break;
F_11 ( 1 ) ;
}
if ( F_4 ( V_8 ) )
F_12 ( L_3 , V_8 -> V_25 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
T_1 V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ V_37 ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
}
static void F_14 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ ( V_35 | V_38 |
V_39 ) ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
F_9 ( 1 << V_8 -> V_25 , V_16 -> V_10 + V_40 ) ;
F_9 ( 1 << V_8 -> V_25 , V_16 -> V_10 + V_41 ) ;
}
static inline T_1 F_15 ( T_1 V_28 )
{
T_1 V_42 = V_28 & V_43 ;
switch ( V_28 >> V_44 ) {
case V_45 :
break;
case V_46 :
V_42 *= 2 ;
break;
case V_47 :
V_42 *= 4 ;
break;
}
return V_42 ;
}
static T_1 F_16 ( struct V_1 * V_13 )
{
struct V_7 * V_8 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
T_2 V_42 = 0 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_8 = V_13 -> V_18 ;
V_14 = V_13 -> V_22 ;
if ( V_8 && V_14 ) {
T_1 V_50 = F_5 ( V_8 -> V_10 + V_32 ) & ~ V_51 ;
V_42 = F_15 ( F_5 ( V_8 -> V_10 + V_33 ) ) ;
if ( V_50 ) {
struct V_19 * V_21 = V_14 -> V_21 ;
T_3 V_52 = V_14 -> V_52 ;
int V_53 ;
F_18 ( V_50 < V_52 || V_50 >= V_52 +
sizeof( struct V_19 ) * V_54 ) ;
V_53 = ( V_50 - V_52 ) / sizeof( struct V_19 ) ;
for (; V_53 < V_54 ; V_53 ++ ) {
V_42 += F_15 ( V_21 [ V_53 ] . V_28 ) ;
if ( ! V_21 [ V_53 ] . V_20 )
break;
}
}
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_56 ;
F_20 (txdi, &plchan->pend_list, node) {
V_42 += V_56 -> V_57 ;
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_42 ;
}
static struct V_7 *
F_22 ( struct V_15 * V_16 ,
struct V_1 * V_58 )
{
struct V_7 * V_8 = NULL ;
unsigned long V_48 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
V_8 = & V_16 -> V_62 [ V_59 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
if ( ! V_8 -> V_63 ) {
V_8 -> V_63 = V_58 ;
V_8 -> signal = - 1 ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
break;
}
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
if ( V_59 == V_16 -> V_60 -> V_61 ) {
return NULL ;
}
return V_8 ;
}
static inline void F_23 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
unsigned long V_48 ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
F_14 ( V_16 , V_8 ) ;
V_8 -> V_63 = NULL ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
static inline unsigned int F_24 ( unsigned int V_64 )
{
switch ( V_64 ) {
case V_45 :
return 1 ;
case V_46 :
return 2 ;
case V_47 :
return 4 ;
default:
break;
}
F_25 () ;
return 0 ;
}
static inline T_1 F_26 ( T_1 V_28 , T_4 V_65 , T_4 V_66 ,
T_2 V_67 )
{
T_1 V_68 = V_28 ;
V_68 &= ~ V_69 ;
V_68 &= ~ V_70 ;
V_68 &= ~ V_43 ;
switch ( V_65 ) {
case 1 :
V_68 |= V_45 << V_44 ;
break;
case 2 :
V_68 |= V_46 << V_44 ;
break;
case 4 :
V_68 |= V_47 << V_44 ;
break;
default:
F_25 () ;
break;
}
switch ( V_66 ) {
case 1 :
V_68 |= V_45 << V_71 ;
break;
case 2 :
V_68 |= V_46 << V_71 ;
break;
case 4 :
V_68 |= V_47 << V_71 ;
break;
default:
F_25 () ;
break;
}
V_68 |= V_67 << V_72 ;
return V_68 ;
}
static void F_27 ( struct V_73 * V_74 ,
struct V_75 * * V_76 , struct V_75 * * V_77 , T_1 V_28 )
{
if ( ! ( V_28 & V_78 ) ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else if ( ! ( V_28 & V_81 ) ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else {
if ( V_74 -> V_80 . V_82 == 4 ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else if ( V_74 -> V_79 . V_82 == 4 ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else if ( V_74 -> V_80 . V_82 == 2 ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else if ( V_74 -> V_79 . V_82 == 2 ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
}
}
}
static void F_28 ( struct V_73 * V_74 ,
int V_83 , int V_57 , T_1 V_28 )
{
struct V_19 * V_21 = V_74 -> V_14 -> V_21 ;
T_3 V_52 = V_74 -> V_14 -> V_52 ;
F_18 ( V_83 >= V_54 ) ;
V_21 [ V_83 ] . V_28 = V_28 ;
V_21 [ V_83 ] . V_26 = V_74 -> V_79 . V_84 ;
V_21 [ V_83 ] . V_27 = V_74 -> V_80 . V_84 ;
V_21 [ V_83 ] . V_20 = V_52 + ( V_83 + 1 ) * sizeof( struct V_19 ) ;
V_21 [ V_83 ] . V_20 |= V_74 -> V_85 ;
if ( V_28 & V_81 )
V_74 -> V_79 . V_84 += V_57 ;
if ( V_28 & V_78 )
V_74 -> V_80 . V_84 += V_57 ;
F_18 ( V_74 -> V_86 < V_57 ) ;
V_74 -> V_86 -= V_57 ;
}
static inline T_2 F_29 ( T_1 V_84 , T_2 V_57 )
{
T_2 V_87 = V_88 -
( V_84 & ( V_88 - 1 ) ) ;
return F_30 ( V_87 , V_57 ) ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_75 * V_76 , * V_77 ;
struct V_73 V_74 ;
int V_83 = 0 ;
T_1 V_28 ;
T_2 V_89 ;
T_2 V_90 = 0 ;
struct V_19 * V_21 ;
V_14 -> V_21 = F_32 ( V_16 -> V_91 , V_92 ,
& V_14 -> V_52 ) ;
if ( ! V_14 -> V_21 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_4 , V_93 ) ;
return 0 ;
}
V_16 -> V_94 ++ ;
V_28 = V_14 -> V_28 ;
V_74 . V_14 = V_14 ;
V_74 . V_79 . V_84 = V_14 -> V_95 ;
V_74 . V_80 . V_84 = V_14 -> V_96 ;
V_74 . V_85 = ( V_16 -> V_97 & V_98 ) ? V_51 : 0 ;
V_74 . V_79 . V_99 =
F_24 ( ( V_28 & V_70 ) >>
V_44 ) ;
V_74 . V_80 . V_99 =
F_24 ( ( V_28 & V_69 ) >>
V_71 ) ;
V_74 . V_79 . V_82 = V_74 . V_79 . V_99 ;
V_74 . V_80 . V_82 = V_74 . V_80 . V_99 ;
V_89 = F_30 ( V_74 . V_79 . V_82 , V_74 . V_80 . V_82 ) *
V_43 ;
V_74 . V_86 = V_14 -> V_57 ;
F_27 ( & V_74 , & V_76 , & V_77 , V_28 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_5 ,
V_74 . V_79 . V_84 , V_28 & V_81 ? L_6 : L_7 ,
V_74 . V_79 . V_82 ,
V_74 . V_80 . V_84 , V_28 & V_78 ? L_6 : L_7 ,
V_74 . V_80 . V_82 ,
V_74 . V_86 , V_89 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_8 ,
V_76 == & V_74 . V_79 ? L_9 : L_10 ,
V_77 == & V_74 . V_79 ? L_9 : L_10 ) ;
if ( V_14 -> V_57 < V_76 -> V_82 ) {
while ( V_74 . V_86 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_11
L_12 ,
V_93 , V_74 . V_86 ) ;
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_90 ++ ;
}
} else {
while ( ( V_76 -> V_84 ) % ( V_76 -> V_82 ) ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_13
L_14 ,
V_93 , V_74 . V_86 ) ;
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_90 ++ ;
}
if ( V_77 -> V_84 % V_77 -> V_82 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_15 ,
V_93 ) ;
V_77 -> V_82 = 1 ;
}
while ( V_74 . V_86 > ( V_76 -> V_82 - 1 ) ) {
T_2 V_100 , V_101 , V_67 , V_102 ;
V_101 = F_30 ( V_74 . V_86 , V_89 ) ;
if ( V_28 & V_81 )
V_74 . V_79 . V_103 =
F_29 ( V_74 . V_79 . V_84 ,
V_101 ) ;
else
V_74 . V_79 . V_103 = V_101 ;
if ( V_28 & V_78 )
V_74 . V_80 . V_103 =
F_29 ( V_74 . V_80 . V_84 ,
V_101 ) ;
else
V_74 . V_80 . V_103 = V_101 ;
V_100 = F_30 ( V_74 . V_79 . V_103 ,
V_74 . V_80 . V_103 ) ;
F_18 ( V_100 > V_74 . V_86 ) ;
if ( V_100 <= 0 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_16 ,
V_93 , V_100 ) ;
return 0 ;
}
if ( V_100 == V_101 ) {
V_100 = ( V_100 / V_76 -> V_82 ) *
V_76 -> V_82 ;
V_102 = 0 ;
} else {
V_102 = V_100 % V_76 -> V_82 ;
V_100 -= V_102 ;
}
if ( V_100 ) {
V_67 = V_100 / F_30 ( V_76 -> V_82 ,
V_77 -> V_82 ) ;
V_100 = V_67 * F_30 ( V_76 -> V_82 ,
V_77 -> V_82 ) ;
if ( V_101 != V_100 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_17 ,
V_93 , V_101 , V_100 , V_14 -> V_57 ) ;
}
V_28 = F_26 ( V_28 ,
V_74 . V_79 . V_82 ,
V_74 . V_80 . V_82 ,
V_67 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_18 ,
V_93 , V_100 , V_74 . V_86 ) ;
F_28 ( & V_74 , V_83 ++ ,
V_100 , V_28 ) ;
V_90 += V_100 ;
}
if ( V_102 ) {
int V_104 ;
for ( V_104 = 0 ; ( V_104 < V_76 -> V_82 )
&& ( V_74 . V_86 ) ; V_104 ++ ) {
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_19 ,
V_93 , V_74 . V_86 ) ;
F_28 ( & V_74 ,
V_83 ++ , 1 , V_28 ) ;
V_90 ++ ;
}
}
}
while ( V_74 . V_86 ) {
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_20 ,
V_93 , V_74 . V_86 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_90 ++ ;
}
}
if ( V_90 != V_14 -> V_57 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_21 ,
V_93 , V_90 , V_14 -> V_57 ) ;
return 0 ;
}
if ( V_83 >= V_54 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_22 ,
V_93 , ( T_1 ) V_54 ) ;
return 0 ;
}
V_21 = V_14 -> V_21 ;
V_21 [ V_83 - 1 ] . V_20 = 0 ;
V_21 [ V_83 - 1 ] . V_28 |= V_105 ;
#ifdef F_35
{
int V_59 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_23 ,
L_24 , L_7 , L_25 , L_26 , L_27 , L_28 ) ;
for ( V_59 = 0 ; V_59 < V_83 ; V_59 ++ ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_29 ,
V_59 , & V_21 [ V_59 ] , V_21 [ V_59 ] . V_26 ,
V_21 [ V_59 ] . V_27 , V_21 [ V_59 ] . V_20 , V_21 [ V_59 ] . V_28
) ;
}
}
#endif
return V_83 ;
}
static void F_36 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
F_37 ( V_16 -> V_91 , V_14 -> V_21 , V_14 -> V_52 ) ;
V_16 -> V_94 -- ;
F_38 ( V_14 ) ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_1 * V_13 )
{
struct V_4 * V_56 = NULL ;
struct V_4 * V_106 ;
if ( ! F_19 ( & V_13 -> V_55 ) ) {
F_40 (txdi,
next, &plchan->pend_list, node) {
F_41 ( & V_56 -> V_107 ) ;
F_36 ( V_16 , V_56 ) ;
}
}
}
static int F_42 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
}
static int F_44 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_7 * V_8 ;
int V_108 ;
if ( V_13 -> V_18 )
return 0 ;
V_8 = F_22 ( V_16 , V_13 ) ;
if ( ! V_8 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_30 , V_13 -> V_109 ) ;
return - V_110 ;
}
if ( V_13 -> V_111 &&
V_8 -> signal < 0 &&
V_16 -> V_112 -> V_113 ) {
V_108 = V_16 -> V_112 -> V_113 ( V_13 ) ;
if ( V_108 < 0 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_31 ,
V_8 -> V_25 , V_13 -> V_109 ) ;
F_23 ( V_16 , V_8 ) ;
return - V_110 ;
}
V_8 -> signal = V_108 ;
if ( V_14 -> V_114 == V_115 )
V_14 -> V_29 |= V_8 -> signal << V_116 ;
else if ( V_14 -> V_114 == V_117 )
V_14 -> V_29 |= V_8 -> signal << V_118 ;
}
F_34 ( & V_16 -> V_23 -> V_24 , L_32 ,
V_8 -> V_25 ,
V_8 -> signal ,
V_13 -> V_109 ) ;
V_13 -> V_119 ++ ;
V_13 -> V_18 = V_8 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( ( V_13 -> V_18 -> signal >= 0 ) && V_16 -> V_112 -> V_120 ) {
V_16 -> V_112 -> V_120 ( V_13 ) ;
V_13 -> V_18 -> signal = - 1 ;
}
F_23 ( V_16 , V_13 -> V_18 ) ;
V_13 -> V_18 = NULL ;
}
static T_5 F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_1 ( V_6 -> V_3 ) ;
struct V_4 * V_14 = F_3 ( V_6 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_13 -> V_3 . V_121 += 1 ;
if ( V_13 -> V_3 . V_121 < 0 )
V_13 -> V_3 . V_121 = 1 ;
V_6 -> V_121 = V_13 -> V_3 . V_121 ;
F_47 ( & V_14 -> V_107 , & V_13 -> V_55 ) ;
if ( ! V_13 -> V_111 && ! V_13 -> V_18 ) {
V_13 -> V_122 = V_123 ;
V_13 -> V_124 = V_14 ;
} else {
V_13 -> V_119 -- ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_6 -> V_121 ;
}
static struct V_5 * F_48 (
struct V_2 * V_3 , unsigned long V_48 )
{
struct V_5 * V_125 = NULL ;
return V_125 ;
}
static enum V_126
F_49 ( struct V_2 * V_3 ,
T_5 V_121 ,
struct V_127 * V_128 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_5 V_129 ;
T_5 V_130 ;
enum V_126 V_108 ;
T_1 V_131 = 0 ;
V_129 = V_13 -> V_3 . V_121 ;
V_130 = V_13 -> V_132 ;
V_108 = F_50 ( V_121 , V_130 , V_129 ) ;
if ( V_108 == V_133 ) {
F_51 ( V_128 , V_130 , V_129 , 0 ) ;
return V_108 ;
}
V_129 = V_13 -> V_3 . V_121 ;
V_130 = V_13 -> V_132 ;
V_131 = F_16 ( V_13 ) ;
F_51 ( V_128 , V_130 , V_129 ,
V_131 ) ;
if ( V_13 -> V_122 == V_134 )
return V_135 ;
return V_136 ;
}
static T_1 F_52 ( T_4 V_26 , T_4 V_27 )
{
T_1 V_28 = 0 ;
if ( ! ( V_27 & V_137 ) || ( ( V_27 & V_98 ) && ( V_26 & V_137 ) ) )
V_28 |= V_138 ;
if ( ! ( V_26 & V_137 ) || ( ( V_26 & V_98 ) && ! ( V_27 & V_98 ) ) )
V_28 |= V_139 ;
return V_28 ;
}
static T_1 F_53 ( T_1 V_28 )
{
V_28 &= ~ ( V_139 | V_138 |
V_81 | V_78 |
V_140 ) ;
return V_28 | V_141 ;
}
static T_1 F_54 ( enum V_142 V_143 )
{
switch ( V_143 ) {
case V_144 :
return V_45 ;
case V_145 :
return V_46 ;
case V_146 :
return V_47 ;
default:
return ~ 0 ;
}
}
static T_1 F_55 ( T_1 V_147 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < F_56 ( V_148 ) ; V_59 ++ )
if ( V_148 [ V_59 ] . V_149 <= V_147 )
break;
return V_148 [ V_59 ] . V_150 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_151 * V_152 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
enum V_142 V_153 ;
T_1 V_143 , V_154 , V_147 ;
T_1 V_28 = 0 ;
if ( ! V_13 -> V_111 )
return - V_155 ;
V_13 -> V_156 = V_152 -> V_114 ;
if ( V_152 -> V_114 == V_115 ) {
V_153 = V_152 -> V_157 ;
V_147 = V_152 -> V_158 ;
} else if ( V_152 -> V_114 == V_117 ) {
V_153 = V_152 -> V_159 ;
V_147 = V_152 -> V_160 ;
} else {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_33 ) ;
return - V_155 ;
}
V_143 = F_54 ( V_153 ) ;
if ( V_143 == ~ 0 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_34 ) ;
return - V_155 ;
}
V_28 |= V_143 << V_44 ;
V_28 |= V_143 << V_71 ;
if ( V_13 -> V_161 -> V_162 )
V_147 = 1 ;
V_154 = F_55 ( V_147 ) ;
V_28 |= V_154 << V_163 ;
V_28 |= V_154 << V_164 ;
if ( V_13 -> V_156 == V_117 ) {
V_13 -> V_95 = V_152 -> V_95 ;
V_13 -> V_165 = F_53 ( V_28 ) | V_78 |
F_52 ( V_13 -> V_161 -> V_166 ,
V_16 -> V_167 ) ;
} else {
V_13 -> V_96 = V_152 -> V_96 ;
V_13 -> V_168 = F_53 ( V_28 ) | V_81 |
F_52 ( V_16 -> V_167 ,
V_13 -> V_161 -> V_166 ) ;
}
F_34 ( & V_16 -> V_23 -> V_24 ,
L_35
L_36 ,
F_58 ( V_3 ) , V_13 -> V_109 ,
( V_152 -> V_114 == V_117 ) ? L_37 : L_38 ,
V_153 ,
V_147 ,
V_28 ) ;
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( V_13 -> V_22 || V_13 -> V_122 == V_123 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_106 ;
V_106 = F_60 ( & V_13 -> V_55 ,
struct V_4 ,
V_107 ) ;
F_41 ( & V_106 -> V_107 ) ;
V_13 -> V_122 = V_169 ;
F_6 ( V_13 , V_106 ) ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
}
static int F_61 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_83 , V_108 ;
V_83 = F_31 ( V_16 , V_14 ) ;
if ( ! V_83 ) {
F_38 ( V_14 ) ;
return - V_155 ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_108 = F_44 ( V_13 , V_14 ) ;
if ( V_108 ) {
if ( V_13 -> V_111 ) {
F_39 ( V_16 , V_13 ) ;
F_36 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_110 ;
}
} else
if ( V_13 -> V_122 == V_170 )
V_13 -> V_122 = V_134 ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
static struct V_4 * F_62 ( struct V_1 * V_13 ,
unsigned long V_48 )
{
struct V_4 * V_14 = F_63 ( sizeof( struct V_4 ) , V_92 ) ;
if ( V_14 ) {
F_64 ( & V_14 -> V_6 , & V_13 -> V_3 ) ;
V_14 -> V_6 . V_48 = V_48 ;
V_14 -> V_6 . V_171 = F_46 ;
F_65 ( & V_14 -> V_107 ) ;
V_14 -> V_29 = V_38 |
V_39 ;
}
return V_14 ;
}
static struct V_5 * F_66 (
struct V_2 * V_3 , T_3 V_172 , T_3 V_26 ,
T_2 V_57 , unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
int V_108 ;
V_14 = F_62 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_39 , V_93 ) ;
return NULL ;
}
V_14 -> V_114 = V_173 ;
V_14 -> V_95 = V_26 ;
V_14 -> V_96 = V_172 ;
V_14 -> V_57 = V_57 ;
V_14 -> V_29 |= V_174 << V_175 ;
V_14 -> V_28 = V_16 -> V_112 -> V_176 . V_28 &
~ ( V_138 | V_139 ) ;
V_14 -> V_28 |= V_81 | V_78 ;
if ( V_16 -> V_60 -> V_177 )
V_14 -> V_28 |= F_52 ( V_16 -> V_167 ,
V_16 -> V_167 ) ;
V_108 = F_61 ( V_13 , V_14 ) ;
if ( V_108 )
return NULL ;
return & V_14 -> V_6 ;
}
static struct V_5 * F_67 (
struct V_2 * V_3 , struct V_178 * V_179 ,
unsigned int V_180 , enum V_181 V_114 ,
unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
int V_108 ;
if ( V_180 != 1 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_40 ,
V_93 ) ;
F_25 () ;
}
F_34 ( & V_16 -> V_23 -> V_24 , L_41 ,
V_93 , V_179 -> V_182 , V_13 -> V_109 ) ;
V_14 = F_62 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_42 , V_93 ) ;
return NULL ;
}
if ( V_114 != V_13 -> V_156 )
F_33 ( & V_16 -> V_23 -> V_24 , L_43
L_44 ,
V_93 ) ;
V_14 -> V_114 = V_114 ;
V_14 -> V_57 = V_179 -> V_182 ;
if ( V_114 == V_115 ) {
V_14 -> V_29 |= V_183 << V_175 ;
V_14 -> V_28 = V_13 -> V_168 ;
V_14 -> V_95 = V_179 -> V_184 ;
V_14 -> V_96 = V_13 -> V_96 ;
} else if ( V_114 == V_117 ) {
V_14 -> V_29 |= V_185 << V_175 ;
V_14 -> V_28 = V_13 -> V_165 ;
V_14 -> V_95 = V_13 -> V_95 ;
V_14 -> V_96 = V_179 -> V_184 ;
} else {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_45 , V_93 ) ;
return NULL ;
}
V_108 = F_61 ( V_13 , V_14 ) ;
if ( V_108 )
return NULL ;
return & V_14 -> V_6 ;
}
static int F_68 ( struct V_2 * V_3 , enum V_186 V_187 ,
unsigned long V_188 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_108 = 0 ;
if ( V_187 == V_189 ) {
return F_57 ( V_3 ,
(struct V_151 * ) V_188 ) ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( ! V_13 -> V_18 && ! V_13 -> V_22 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
switch ( V_187 ) {
case V_190 :
V_13 -> V_122 = V_170 ;
if ( V_13 -> V_18 ) {
F_14 ( V_16 , V_13 -> V_18 ) ;
F_45 ( V_13 ) ;
}
if ( V_13 -> V_22 ) {
F_36 ( V_16 , V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
}
F_39 ( V_16 , V_13 ) ;
break;
case V_191 :
F_10 ( V_13 -> V_18 ) ;
V_13 -> V_122 = V_134 ;
break;
case V_192 :
F_13 ( V_13 -> V_18 ) ;
V_13 -> V_122 = V_169 ;
break;
default:
V_108 = - V_193 ;
break;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_108 ;
}
bool F_69 ( struct V_2 * V_3 , void * V_194 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
char * V_109 = V_194 ;
if ( ! strcmp ( V_13 -> V_109 , V_109 ) )
return true ;
return false ;
}
static void F_70 ( struct V_15 * V_16 )
{
T_1 V_9 ;
V_9 = F_5 ( V_16 -> V_10 + V_195 ) ;
V_9 &= ~ ( V_196 | V_197 | V_35 ) ;
V_9 |= V_35 ;
F_9 ( V_9 , V_16 -> V_10 + V_195 ) ;
}
static void F_71 ( struct V_4 * V_14 )
{
struct V_198 * V_24 = V_14 -> V_6 . V_3 -> V_198 -> V_24 ;
if ( ! ( V_14 -> V_6 . V_48 & V_199 ) ) {
if ( V_14 -> V_6 . V_48 & V_200 )
F_72 ( V_24 , V_14 -> V_95 , V_14 -> V_57 ,
V_115 ) ;
else
F_73 ( V_24 , V_14 -> V_95 , V_14 -> V_57 ,
V_115 ) ;
}
if ( ! ( V_14 -> V_6 . V_48 & V_201 ) ) {
if ( V_14 -> V_6 . V_48 & V_202 )
F_72 ( V_24 , V_14 -> V_96 , V_14 -> V_57 ,
V_117 ) ;
else
F_73 ( V_24 , V_14 -> V_96 , V_14 -> V_57 ,
V_117 ) ;
}
}
static void F_74 ( unsigned long V_203 )
{
struct V_1 * V_13 = (struct V_1 * ) V_203 ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_14 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
if ( V_14 ) {
V_13 -> V_132 = V_14 -> V_6 . V_121 ;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_106 ;
V_106 = F_60 ( & V_13 -> V_55 ,
struct V_4 ,
V_107 ) ;
F_41 ( & V_106 -> V_107 ) ;
F_6 ( V_13 , V_106 ) ;
} else if ( V_13 -> V_119 ) {
} else {
struct V_1 * V_124 = NULL ;
F_45 ( V_13 ) ;
V_13 -> V_122 = V_170 ;
F_20 (waiting, &pl08x->memcpy.channels,
chan.device_node) {
if ( V_124 -> V_122 == V_123 &&
V_124 -> V_124 != NULL ) {
int V_108 ;
V_108 = F_44 ( V_124 ,
V_124 -> V_124 ) ;
F_18 ( V_108 ) ;
V_124 -> V_119 -- ;
V_124 -> V_122 = V_169 ;
V_124 -> V_124 = NULL ;
F_59 ( & V_124 -> V_3 ) ;
break;
}
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_14 ) {
T_6 V_204 = V_14 -> V_6 . V_204 ;
void * V_205 = V_14 -> V_6 . V_205 ;
if ( ! V_13 -> V_111 )
F_71 ( V_14 ) ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_36 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_204 )
V_204 ( V_205 ) ;
}
}
static T_7 F_75 ( int V_206 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
T_1 V_207 = 0 ;
T_1 V_9 ;
int V_59 ;
V_9 = F_5 ( V_16 -> V_10 + V_208 ) ;
if ( V_9 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_46 ,
V_93 , V_9 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
}
V_9 = F_5 ( V_16 -> V_10 + V_209 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
if ( ( 1 << V_59 ) & V_9 ) {
struct V_7 * V_18 = & V_16 -> V_62 [ V_59 ] ;
struct V_1 * V_13 = V_18 -> V_63 ;
F_76 ( & V_13 -> V_210 ) ;
V_207 |= ( 1 << V_59 ) ;
}
}
F_9 ( V_207 , V_16 -> V_10 + V_41 ) ;
return V_207 ? V_211 : V_212 ;
}
static void F_77 ( struct V_1 * V_3 )
{
T_1 V_28 = F_53 ( V_3 -> V_161 -> V_28 ) ;
V_3 -> V_111 = true ;
V_3 -> V_109 = V_3 -> V_161 -> V_213 ;
V_3 -> V_95 = V_3 -> V_161 -> V_84 ;
V_3 -> V_96 = V_3 -> V_161 -> V_84 ;
V_3 -> V_165 = V_28 | V_78 |
F_52 ( V_3 -> V_161 -> V_166 , V_3 -> V_17 -> V_167 ) ;
V_3 -> V_168 = V_28 | V_81 |
F_52 ( V_3 -> V_17 -> V_167 , V_3 -> V_161 -> V_166 ) ;
}
static int F_78 ( struct V_15 * V_16 ,
struct V_214 * V_215 ,
unsigned int V_61 ,
bool V_111 )
{
struct V_1 * V_3 ;
int V_59 ;
F_65 ( & V_215 -> V_61 ) ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ ) {
V_3 = F_63 ( sizeof( struct V_1 ) , V_216 ) ;
if ( ! V_3 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_47 , V_93 ) ;
return - V_217 ;
}
V_3 -> V_17 = V_16 ;
V_3 -> V_122 = V_170 ;
if ( V_111 ) {
V_3 -> V_161 = & V_16 -> V_112 -> V_218 [ V_59 ] ;
F_77 ( V_3 ) ;
} else {
V_3 -> V_161 = & V_16 -> V_112 -> V_176 ;
V_3 -> V_109 = F_79 ( V_216 , L_48 , V_59 ) ;
if ( ! V_3 -> V_109 ) {
F_38 ( V_3 ) ;
return - V_217 ;
}
}
if ( V_3 -> V_161 -> V_219 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_49 ,
V_3 -> V_109 ) ;
F_38 ( V_3 ) ;
continue;
}
F_80 ( & V_16 -> V_23 -> V_24 ,
L_50 ,
V_3 -> V_109 ) ;
V_3 -> V_3 . V_198 = V_215 ;
V_3 -> V_3 . V_121 = 0 ;
V_3 -> V_132 = 0 ;
F_81 ( & V_3 -> V_49 ) ;
F_65 ( & V_3 -> V_55 ) ;
F_82 ( & V_3 -> V_210 , F_74 ,
( unsigned long ) V_3 ) ;
F_47 ( & V_3 -> V_3 . V_220 , & V_215 -> V_61 ) ;
}
F_80 ( & V_16 -> V_23 -> V_24 , L_51 ,
V_59 , V_111 ? L_52 : L_53 ) ;
return V_59 ;
}
static void F_83 ( struct V_214 * V_215 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_106 ;
F_40 (chan,
next, &dmadev->channels, chan.device_node) {
F_41 ( & V_3 -> V_3 . V_220 ) ;
F_38 ( V_3 ) ;
}
}
static const char * F_84 ( enum V_221 V_122 )
{
switch ( V_122 ) {
case V_170 :
return L_54 ;
case V_169 :
return L_55 ;
case V_134 :
return L_56 ;
case V_123 :
return L_57 ;
default:
break;
}
return L_58 ;
}
static int F_85 ( struct V_222 * V_223 , void * V_203 )
{
struct V_15 * V_16 = V_223 -> V_224 ;
struct V_1 * V_3 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
int V_59 ;
F_86 ( V_223 , L_59 ) ;
F_86 ( V_223 , L_60 ) ;
F_86 ( V_223 , L_61 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
struct V_1 * V_58 ;
V_8 = & V_16 -> V_62 [ V_59 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
V_58 = V_8 -> V_63 ;
F_86 ( V_223 , L_62 ,
V_8 -> V_25 , V_58 ? V_58 -> V_109 : L_63 ) ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
F_86 ( V_223 , L_64 ) ;
F_86 ( V_223 , L_65 ) ;
F_86 ( V_223 , L_66 ) ;
F_20 (chan, &pl08x->memcpy.channels, chan.device_node) {
F_86 ( V_223 , L_67 , V_3 -> V_109 ,
F_84 ( V_3 -> V_122 ) ) ;
}
F_86 ( V_223 , L_68 ) ;
F_86 ( V_223 , L_65 ) ;
F_86 ( V_223 , L_66 ) ;
F_20 (chan, &pl08x->slave.channels, chan.device_node) {
F_86 ( V_223 , L_67 , V_3 -> V_109 ,
F_84 ( V_3 -> V_122 ) ) ;
}
return 0 ;
}
static int F_87 ( struct V_225 * V_225 , struct V_226 * V_226 )
{
return F_88 ( V_226 , F_85 , V_225 -> V_227 ) ;
}
static void F_89 ( struct V_15 * V_16 )
{
( void ) F_90 ( F_91 ( & V_16 -> V_23 -> V_24 ) , V_228 | V_229 ,
NULL , V_16 ,
& V_230 ) ;
}
static inline void F_89 ( struct V_15 * V_16 )
{
}
static int F_92 ( struct V_231 * V_23 , const struct V_232 * V_25 )
{
struct V_15 * V_16 ;
const struct V_233 * V_60 = V_25 -> V_203 ;
int V_108 = 0 ;
int V_59 ;
V_108 = F_93 ( V_23 , NULL ) ;
if ( V_108 )
return V_108 ;
V_16 = F_63 ( sizeof( struct V_15 ) , V_216 ) ;
if ( ! V_16 ) {
V_108 = - V_217 ;
goto V_234;
}
F_94 ( V_235 , V_16 -> memcpy . V_236 ) ;
V_16 -> memcpy . V_24 = & V_23 -> V_24 ;
V_16 -> memcpy . V_237 = F_42 ;
V_16 -> memcpy . V_238 = F_43 ;
V_16 -> memcpy . V_239 = F_66 ;
V_16 -> memcpy . V_240 = F_48 ;
V_16 -> memcpy . V_241 = F_49 ;
V_16 -> memcpy . V_242 = F_59 ;
V_16 -> memcpy . V_243 = F_68 ;
F_94 ( V_244 , V_16 -> V_111 . V_236 ) ;
V_16 -> V_111 . V_24 = & V_23 -> V_24 ;
V_16 -> V_111 . V_237 = F_42 ;
V_16 -> V_111 . V_238 = F_43 ;
V_16 -> V_111 . V_240 = F_48 ;
V_16 -> V_111 . V_241 = F_49 ;
V_16 -> V_111 . V_242 = F_59 ;
V_16 -> V_111 . V_245 = F_67 ;
V_16 -> V_111 . V_243 = F_68 ;
V_16 -> V_112 = F_95 ( & V_23 -> V_24 ) ;
if ( ! V_16 -> V_112 ) {
F_33 ( & V_23 -> V_24 , L_69 ) ;
goto V_246;
}
V_16 -> V_23 = V_23 ;
V_16 -> V_60 = V_60 ;
V_16 -> V_97 = V_137 ;
V_16 -> V_167 = V_137 ;
if ( V_16 -> V_60 -> V_177 ) {
V_16 -> V_97 = V_16 -> V_112 -> V_97 ;
V_16 -> V_167 = V_16 -> V_112 -> V_167 ;
}
V_16 -> V_91 = F_96 ( V_247 , & V_16 -> V_23 -> V_24 ,
V_248 , V_249 , 0 ) ;
if ( ! V_16 -> V_91 ) {
V_108 = - V_217 ;
goto V_250;
}
F_81 ( & V_16 -> V_49 ) ;
V_16 -> V_10 = F_97 ( V_23 -> V_251 . V_252 , F_98 ( & V_23 -> V_251 ) ) ;
if ( ! V_16 -> V_10 ) {
V_108 = - V_217 ;
goto V_253;
}
F_70 ( V_16 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_41 ) ;
V_108 = F_99 ( V_23 -> V_206 [ 0 ] , F_75 , V_254 ,
V_247 , V_16 ) ;
if ( V_108 ) {
F_33 ( & V_23 -> V_24 , L_70 ,
V_93 , V_23 -> V_206 [ 0 ] ) ;
goto V_255;
}
V_16 -> V_62 = F_100 ( ( V_60 -> V_61 * sizeof( struct V_7 ) ) ,
V_216 ) ;
if ( ! V_16 -> V_62 ) {
F_33 ( & V_23 -> V_24 , L_71
L_72 ,
V_93 ) ;
goto V_256;
}
for ( V_59 = 0 ; V_59 < V_60 -> V_61 ; V_59 ++ ) {
struct V_7 * V_8 = & V_16 -> V_62 [ V_59 ] ;
V_8 -> V_25 = V_59 ;
V_8 -> V_10 = V_16 -> V_10 + F_101 ( V_59 ) ;
F_81 ( & V_8 -> V_49 ) ;
V_8 -> V_63 = NULL ;
V_8 -> signal = - 1 ;
F_80 ( & V_23 -> V_24 ,
L_73 , V_59 ,
F_4 ( V_8 ) ? L_74 : L_75 ) ;
}
V_108 = F_78 ( V_16 , & V_16 -> memcpy ,
V_16 -> V_60 -> V_61 , false ) ;
if ( V_108 <= 0 ) {
F_102 ( & V_16 -> V_23 -> V_24 ,
L_76 ,
V_93 , V_108 ) ;
goto V_257;
}
V_16 -> memcpy . V_258 = V_108 ;
V_108 = F_78 ( V_16 , & V_16 -> V_111 ,
V_16 -> V_112 -> V_259 ,
true ) ;
if ( V_108 <= 0 ) {
F_102 ( & V_16 -> V_23 -> V_24 ,
L_77 ,
V_93 , V_108 ) ;
goto V_260;
}
V_16 -> V_111 . V_258 = V_108 ;
V_108 = F_103 ( & V_16 -> memcpy ) ;
if ( V_108 ) {
F_102 ( & V_16 -> V_23 -> V_24 ,
L_78 ,
V_93 , V_108 ) ;
goto V_261;
}
V_108 = F_103 ( & V_16 -> V_111 ) ;
if ( V_108 ) {
F_102 ( & V_16 -> V_23 -> V_24 ,
L_79 ,
V_93 , V_108 ) ;
goto V_262;
}
F_104 ( V_23 , V_16 ) ;
F_89 ( V_16 ) ;
F_80 ( & V_16 -> V_23 -> V_24 , L_80 ,
F_105 ( V_23 ) , F_106 ( V_23 ) ,
( unsigned long long ) V_23 -> V_251 . V_252 , V_23 -> V_206 [ 0 ] ) ;
return 0 ;
V_262:
F_107 ( & V_16 -> memcpy ) ;
V_261:
F_83 ( & V_16 -> V_111 ) ;
V_260:
F_83 ( & V_16 -> memcpy ) ;
V_257:
F_38 ( V_16 -> V_62 ) ;
V_256:
F_108 ( V_23 -> V_206 [ 0 ] , V_16 ) ;
V_255:
F_109 ( V_16 -> V_10 ) ;
V_253:
F_110 ( V_16 -> V_91 ) ;
V_250:
V_246:
F_38 ( V_16 ) ;
V_234:
F_111 ( V_23 ) ;
return V_108 ;
}
static int T_8 F_112 ( void )
{
int V_125 ;
V_125 = F_113 ( & V_263 ) ;
if ( V_125 )
F_114 (KERN_WARNING DRIVER_NAME
L_81 ,
retval) ;
return V_125 ;
}
