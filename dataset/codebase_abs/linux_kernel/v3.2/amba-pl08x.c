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
struct V_57 * V_58 ;
F_20 (dsg, &txd->dsg_list, node)
V_42 += V_58 -> V_59 ;
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_42 ;
}
static struct V_7 *
F_22 ( struct V_15 * V_16 ,
struct V_1 * V_60 )
{
struct V_7 * V_8 = NULL ;
unsigned long V_48 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
V_8 = & V_16 -> V_64 [ V_61 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
if ( ! V_8 -> V_65 ) {
V_8 -> V_65 = V_60 ;
V_8 -> signal = - 1 ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
break;
}
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
if ( V_61 == V_16 -> V_62 -> V_63 ) {
return NULL ;
}
F_23 ( & V_16 -> V_23 -> V_24 ) ;
return V_8 ;
}
static inline void F_24 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
unsigned long V_48 ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
F_14 ( V_16 , V_8 ) ;
F_25 ( & V_16 -> V_23 -> V_24 ) ;
V_8 -> V_65 = NULL ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
static inline unsigned int F_26 ( unsigned int V_66 )
{
switch ( V_66 ) {
case V_45 :
return 1 ;
case V_46 :
return 2 ;
case V_47 :
return 4 ;
default:
break;
}
F_27 () ;
return 0 ;
}
static inline T_1 F_28 ( T_1 V_28 , T_4 V_67 , T_4 V_68 ,
T_2 V_69 )
{
T_1 V_70 = V_28 ;
V_70 &= ~ V_71 ;
V_70 &= ~ V_72 ;
V_70 &= ~ V_43 ;
switch ( V_67 ) {
case 1 :
V_70 |= V_45 << V_44 ;
break;
case 2 :
V_70 |= V_46 << V_44 ;
break;
case 4 :
V_70 |= V_47 << V_44 ;
break;
default:
F_27 () ;
break;
}
switch ( V_68 ) {
case 1 :
V_70 |= V_45 << V_73 ;
break;
case 2 :
V_70 |= V_46 << V_73 ;
break;
case 4 :
V_70 |= V_47 << V_73 ;
break;
default:
F_27 () ;
break;
}
V_70 |= V_69 << V_74 ;
return V_70 ;
}
static void F_29 ( struct V_75 * V_76 ,
struct V_77 * * V_78 , struct V_77 * * V_79 , T_1 V_28 )
{
if ( ! ( V_28 & V_80 ) ) {
* V_78 = & V_76 -> V_81 ;
* V_79 = & V_76 -> V_82 ;
} else if ( ! ( V_28 & V_83 ) ) {
* V_78 = & V_76 -> V_82 ;
* V_79 = & V_76 -> V_81 ;
} else {
if ( V_76 -> V_81 . V_84 >= V_76 -> V_82 . V_84 ) {
* V_78 = & V_76 -> V_81 ;
* V_79 = & V_76 -> V_82 ;
} else {
* V_78 = & V_76 -> V_82 ;
* V_79 = & V_76 -> V_81 ;
}
}
}
static void F_30 ( struct V_75 * V_76 ,
int V_85 , int V_59 , T_1 V_28 )
{
struct V_19 * V_21 = V_76 -> V_14 -> V_21 ;
T_3 V_52 = V_76 -> V_14 -> V_52 ;
F_18 ( V_85 >= V_54 ) ;
V_21 [ V_85 ] . V_28 = V_28 ;
V_21 [ V_85 ] . V_26 = V_76 -> V_82 . V_86 ;
V_21 [ V_85 ] . V_27 = V_76 -> V_81 . V_86 ;
V_21 [ V_85 ] . V_20 = V_52 + ( V_85 + 1 ) *
sizeof( struct V_19 ) ;
V_21 [ V_85 ] . V_20 |= V_76 -> V_87 ;
if ( V_28 & V_83 )
V_76 -> V_82 . V_86 += V_59 ;
if ( V_28 & V_80 )
V_76 -> V_81 . V_86 += V_59 ;
F_18 ( V_76 -> V_88 < V_59 ) ;
V_76 -> V_88 -= V_59 ;
}
static inline void F_31 ( struct V_75 * V_76 ,
T_1 * V_28 , T_1 V_59 , int V_85 , T_2 * V_89 )
{
* V_28 = F_28 ( * V_28 , 1 , 1 , V_59 ) ;
F_30 ( V_76 , V_85 , V_59 , * V_28 ) ;
( * V_89 ) += V_59 ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_77 * V_78 , * V_79 ;
struct V_75 V_76 ;
int V_85 = 0 ;
T_1 V_28 , V_90 = 0 ;
T_2 V_91 , V_89 ;
struct V_19 * V_21 ;
struct V_57 * V_58 ;
V_14 -> V_21 = F_33 ( V_16 -> V_92 , V_93 , & V_14 -> V_52 ) ;
if ( ! V_14 -> V_21 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_4 , V_94 ) ;
return 0 ;
}
V_16 -> V_95 ++ ;
V_76 . V_14 = V_14 ;
V_76 . V_87 = ( V_16 -> V_96 & V_97 ) ? V_51 : 0 ;
V_28 = V_14 -> V_28 ;
V_76 . V_82 . V_98 =
F_26 ( ( V_28 & V_72 ) >>
V_44 ) ;
V_76 . V_81 . V_98 =
F_26 ( ( V_28 & V_71 ) >>
V_73 ) ;
F_20 (dsg, &txd->dsg_list, node) {
V_89 = 0 ;
V_28 = V_14 -> V_28 ;
V_76 . V_82 . V_86 = V_58 -> V_99 ;
V_76 . V_81 . V_86 = V_58 -> V_100 ;
V_76 . V_88 = V_58 -> V_59 ;
V_76 . V_82 . V_84 = V_76 . V_82 . V_98 ;
V_76 . V_81 . V_84 = V_76 . V_81 . V_98 ;
F_29 ( & V_76 , & V_78 , & V_79 , V_28 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_5 ,
V_76 . V_82 . V_86 , V_28 & V_83 ? L_6 : L_7 ,
V_76 . V_82 . V_84 ,
V_76 . V_81 . V_86 , V_28 & V_80 ? L_6 : L_7 ,
V_76 . V_81 . V_84 ,
V_76 . V_88 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_8 ,
V_78 == & V_76 . V_82 ? L_9 : L_10 ,
V_79 == & V_76 . V_82 ? L_9 : L_10 ) ;
if ( ! V_76 . V_88 ) {
T_1 V_101 = ( V_14 -> V_29 & V_102 ) >>
V_103 ;
if ( ! ( ( V_101 >= V_104 ) &&
( V_101 <= V_105 ) ) ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_11 ,
V_94 ) ;
return 0 ;
}
if ( ( V_76 . V_82 . V_86 % V_76 . V_82 . V_84 ) ||
( V_76 . V_82 . V_86 % V_76 . V_82 . V_84 ) ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_12
L_13 ,
V_94 ) ;
return 0 ;
}
V_28 = F_28 ( V_28 , V_76 . V_82 . V_84 ,
V_76 . V_81 . V_84 , 0 ) ;
F_30 ( & V_76 , V_85 ++ , 0 , V_28 ) ;
break;
}
if ( V_76 . V_88 < V_78 -> V_84 )
V_90 = V_76 . V_88 ;
else if ( ( V_78 -> V_86 ) % ( V_78 -> V_84 ) ) {
V_90 = V_78 -> V_84 - ( V_78 -> V_86 ) %
( V_78 -> V_84 ) ;
if ( ( V_76 . V_88 - V_90 ) < V_78 -> V_84 )
V_90 = V_76 . V_88 ;
}
if ( V_90 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_14 ,
V_94 , V_76 . V_88 ) ;
F_31 ( & V_76 , & V_28 , V_90 , V_85 ++ ,
& V_89 ) ;
}
if ( V_76 . V_88 ) {
if ( V_79 -> V_86 % V_79 -> V_84 ) {
F_35 ( & V_16 -> V_23 -> V_24 ,
L_15 ,
V_94 ) ;
V_79 -> V_84 = 1 ;
}
V_91 = V_76 . V_82 . V_84 *
V_43 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_16 ,
V_94 , V_91 ) ;
while ( V_76 . V_88 > ( V_78 -> V_84 - 1 ) ) {
T_2 V_106 , V_69 , V_107 ;
V_106 = F_36 ( V_76 . V_88 , V_91 ) ;
V_107 = F_37 ( V_78 -> V_84 , V_79 -> V_84 ) ;
V_106 = ( V_106 / V_107 ) * V_107 ;
V_69 = V_106 / V_76 . V_82 . V_84 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_17
L_18 ,
V_94 , V_106 , V_76 . V_88 ) ;
V_28 = F_28 ( V_28 , V_76 . V_82 . V_84 ,
V_76 . V_81 . V_84 , V_69 ) ;
F_30 ( & V_76 , V_85 ++ ,
V_106 , V_28 ) ;
V_89 += V_106 ;
}
if ( V_76 . V_88 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_19 ,
V_94 , V_76 . V_88 ) ;
F_31 ( & V_76 , & V_28 , V_76 . V_88 ,
V_85 ++ , & V_89 ) ;
}
}
if ( V_89 != V_58 -> V_59 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_20 ,
V_94 , V_89 , V_58 -> V_59 ) ;
return 0 ;
}
if ( V_85 >= V_54 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_21 ,
V_94 , ( T_1 ) V_54 ) ;
return 0 ;
}
}
V_21 = V_14 -> V_21 ;
V_21 [ V_85 - 1 ] . V_20 = 0 ;
V_21 [ V_85 - 1 ] . V_28 |= V_108 ;
#ifdef F_38
{
int V_61 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_22 ,
L_23 , L_7 , L_24 , L_25 , L_26 , L_27 ) ;
for ( V_61 = 0 ; V_61 < V_85 ; V_61 ++ ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_28 ,
V_61 , & V_21 [ V_61 ] , V_21 [ V_61 ] . V_26 ,
V_21 [ V_61 ] . V_27 , V_21 [ V_61 ] . V_20 , V_21 [ V_61 ] . V_28
) ;
}
}
#endif
return V_85 ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_57 * V_58 , * V_109 ;
if ( V_14 -> V_21 )
F_40 ( V_16 -> V_92 , V_14 -> V_21 , V_14 -> V_52 ) ;
V_16 -> V_95 -- ;
F_41 (dsg, _dsg, &txd->dsg_list, node) {
F_42 ( & V_58 -> V_110 ) ;
F_43 ( V_58 ) ;
}
F_43 ( V_14 ) ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_1 * V_13 )
{
struct V_4 * V_56 = NULL ;
struct V_4 * V_111 ;
if ( ! F_19 ( & V_13 -> V_55 ) ) {
F_41 (txdi,
next, &plchan->pend_list, node) {
F_42 ( & V_56 -> V_110 ) ;
F_39 ( V_16 , V_56 ) ;
}
}
}
static int F_45 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_46 ( struct V_2 * V_3 )
{
}
static int F_47 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_7 * V_8 ;
int V_112 ;
if ( V_13 -> V_18 )
return 0 ;
V_8 = F_22 ( V_16 , V_13 ) ;
if ( ! V_8 ) {
F_35 ( & V_16 -> V_23 -> V_24 , L_29 , V_13 -> V_113 ) ;
return - V_114 ;
}
if ( V_13 -> V_115 && V_16 -> V_116 -> V_117 ) {
V_112 = V_16 -> V_116 -> V_117 ( V_13 ) ;
if ( V_112 < 0 ) {
F_35 ( & V_16 -> V_23 -> V_24 ,
L_30 ,
V_8 -> V_25 , V_13 -> V_113 ) ;
F_24 ( V_16 , V_8 ) ;
return - V_114 ;
}
V_8 -> signal = V_112 ;
if ( V_14 -> V_118 == V_119 )
V_14 -> V_29 |= V_8 -> signal << V_120 ;
else if ( V_14 -> V_118 == V_121 )
V_14 -> V_29 |= V_8 -> signal << V_122 ;
}
F_35 ( & V_16 -> V_23 -> V_24 , L_31 ,
V_8 -> V_25 ,
V_8 -> signal ,
V_13 -> V_113 ) ;
V_13 -> V_123 ++ ;
V_13 -> V_18 = V_8 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( ( V_13 -> V_18 -> signal >= 0 ) && V_16 -> V_116 -> V_124 ) {
V_16 -> V_116 -> V_124 ( V_13 ) ;
V_13 -> V_18 -> signal = - 1 ;
}
F_24 ( V_16 , V_13 -> V_18 ) ;
V_13 -> V_18 = NULL ;
}
static T_5 F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_1 ( V_6 -> V_3 ) ;
struct V_4 * V_14 = F_3 ( V_6 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_13 -> V_3 . V_125 += 1 ;
if ( V_13 -> V_3 . V_125 < 0 )
V_13 -> V_3 . V_125 = 1 ;
V_6 -> V_125 = V_13 -> V_3 . V_125 ;
F_50 ( & V_14 -> V_110 , & V_13 -> V_55 ) ;
if ( ! V_13 -> V_115 && ! V_13 -> V_18 ) {
V_13 -> V_126 = V_127 ;
V_13 -> V_128 = V_14 ;
} else {
V_13 -> V_123 -- ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_6 -> V_125 ;
}
static struct V_5 * F_51 (
struct V_2 * V_3 , unsigned long V_48 )
{
struct V_5 * V_129 = NULL ;
return V_129 ;
}
static enum V_130 F_52 ( struct V_2 * V_3 ,
T_5 V_125 , struct V_131 * V_132 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_5 V_133 ;
T_5 V_134 ;
enum V_130 V_112 ;
T_1 V_135 = 0 ;
V_133 = V_13 -> V_3 . V_125 ;
V_134 = V_13 -> V_136 ;
V_112 = F_53 ( V_125 , V_134 , V_133 ) ;
if ( V_112 == V_137 ) {
F_54 ( V_132 , V_134 , V_133 , 0 ) ;
return V_112 ;
}
V_133 = V_13 -> V_3 . V_125 ;
V_134 = V_13 -> V_136 ;
V_135 = F_16 ( V_13 ) ;
F_54 ( V_132 , V_134 , V_133 ,
V_135 ) ;
if ( V_13 -> V_126 == V_138 )
return V_139 ;
return V_140 ;
}
static T_1 F_55 ( T_4 V_26 , T_4 V_27 )
{
T_1 V_28 = 0 ;
if ( ! ( V_27 & V_141 ) || ( ( V_27 & V_97 ) && ( V_26 & V_141 ) ) )
V_28 |= V_142 ;
if ( ! ( V_26 & V_141 ) || ( ( V_26 & V_97 ) && ! ( V_27 & V_97 ) ) )
V_28 |= V_143 ;
return V_28 ;
}
static T_1 F_56 ( T_1 V_28 )
{
V_28 &= ~ ( V_143 | V_142 |
V_83 | V_80 |
V_144 ) ;
return V_28 | V_145 ;
}
static T_1 F_57 ( enum V_146 V_107 )
{
switch ( V_107 ) {
case V_147 :
return V_45 ;
case V_148 :
return V_46 ;
case V_149 :
return V_47 ;
default:
return ~ 0 ;
}
}
static T_1 F_58 ( T_1 V_150 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_59 ( V_151 ) ; V_61 ++ )
if ( V_151 [ V_61 ] . V_152 <= V_150 )
break;
return V_151 [ V_61 ] . V_153 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_154 * V_155 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
enum V_146 V_156 ;
T_1 V_107 , V_157 , V_150 ;
T_1 V_28 = 0 ;
if ( ! V_13 -> V_115 )
return - V_158 ;
V_13 -> V_159 = V_155 -> V_118 ;
if ( V_155 -> V_118 == V_119 ) {
V_156 = V_155 -> V_160 ;
V_150 = V_155 -> V_161 ;
} else if ( V_155 -> V_118 == V_121 ) {
V_156 = V_155 -> V_162 ;
V_150 = V_155 -> V_163 ;
} else {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_32 ) ;
return - V_158 ;
}
V_107 = F_57 ( V_156 ) ;
if ( V_107 == ~ 0 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_33 ) ;
return - V_158 ;
}
V_28 |= V_107 << V_44 ;
V_28 |= V_107 << V_73 ;
if ( V_13 -> V_164 -> V_165 )
V_150 = 1 ;
V_157 = F_58 ( V_150 ) ;
V_28 |= V_157 << V_166 ;
V_28 |= V_157 << V_167 ;
if ( V_13 -> V_159 == V_121 ) {
V_13 -> V_99 = V_155 -> V_99 ;
V_13 -> V_168 = F_56 ( V_28 ) | V_80 |
F_55 ( V_13 -> V_164 -> V_169 ,
V_16 -> V_170 ) ;
} else {
V_13 -> V_100 = V_155 -> V_100 ;
V_13 -> V_171 = F_56 ( V_28 ) | V_83 |
F_55 ( V_16 -> V_170 ,
V_13 -> V_164 -> V_169 ) ;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_34
L_35 ,
F_61 ( V_3 ) , V_13 -> V_113 ,
( V_155 -> V_118 == V_121 ) ? L_36 : L_37 ,
V_156 ,
V_150 ,
V_28 ) ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( V_13 -> V_22 || V_13 -> V_126 == V_127 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_111 ;
V_111 = F_63 ( & V_13 -> V_55 ,
struct V_4 ,
V_110 ) ;
F_42 ( & V_111 -> V_110 ) ;
V_13 -> V_126 = V_172 ;
F_6 ( V_13 , V_111 ) ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
}
static int F_64 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_85 , V_112 ;
V_85 = F_32 ( V_16 , V_14 ) ;
if ( ! V_85 ) {
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_158 ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_112 = F_47 ( V_13 , V_14 ) ;
if ( V_112 ) {
if ( V_13 -> V_115 ) {
F_44 ( V_16 , V_13 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_114 ;
}
} else
if ( V_13 -> V_126 == V_173 )
V_13 -> V_126 = V_138 ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
static struct V_4 * F_65 ( struct V_1 * V_13 ,
unsigned long V_48 )
{
struct V_4 * V_14 = F_66 ( sizeof( * V_14 ) , V_93 ) ;
if ( V_14 ) {
F_67 ( & V_14 -> V_6 , & V_13 -> V_3 ) ;
V_14 -> V_6 . V_48 = V_48 ;
V_14 -> V_6 . V_174 = F_49 ;
F_68 ( & V_14 -> V_110 ) ;
F_68 ( & V_14 -> V_175 ) ;
V_14 -> V_29 = V_38 |
V_39 ;
}
return V_14 ;
}
static struct V_5 * F_69 (
struct V_2 * V_3 , T_3 V_176 , T_3 V_26 ,
T_2 V_59 , unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
struct V_57 * V_58 ;
int V_112 ;
V_14 = F_65 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_38 , V_94 ) ;
return NULL ;
}
V_58 = F_66 ( sizeof( struct V_57 ) , V_93 ) ;
if ( ! V_58 ) {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 , L_39 ,
V_94 ) ;
return NULL ;
}
F_50 ( & V_58 -> V_110 , & V_14 -> V_175 ) ;
V_14 -> V_118 = V_177 ;
V_58 -> V_99 = V_26 ;
V_58 -> V_100 = V_176 ;
V_58 -> V_59 = V_59 ;
V_14 -> V_29 |= V_178 << V_103 ;
V_14 -> V_28 = V_16 -> V_116 -> V_179 . V_28 &
~ ( V_142 | V_143 ) ;
V_14 -> V_28 |= V_83 | V_80 ;
if ( V_16 -> V_62 -> V_180 )
V_14 -> V_28 |= F_55 ( V_16 -> V_170 ,
V_16 -> V_170 ) ;
V_112 = F_64 ( V_13 , V_14 ) ;
if ( V_112 )
return NULL ;
return & V_14 -> V_6 ;
}
static struct V_5 * F_70 (
struct V_2 * V_3 , struct V_181 * V_182 ,
unsigned int V_183 , enum V_184 V_118 ,
unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
struct V_57 * V_58 ;
struct V_181 * V_185 ;
T_3 V_186 ;
int V_112 , V_187 ;
F_35 ( & V_16 -> V_23 -> V_24 , L_40 ,
V_94 , V_182 -> V_188 , V_13 -> V_113 ) ;
V_14 = F_65 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_41 , V_94 ) ;
return NULL ;
}
if ( V_118 != V_13 -> V_159 )
F_34 ( & V_16 -> V_23 -> V_24 , L_42
L_43 ,
V_94 ) ;
V_14 -> V_118 = V_118 ;
if ( V_118 == V_119 ) {
V_14 -> V_28 = V_13 -> V_171 ;
V_186 = V_13 -> V_100 ;
} else if ( V_118 == V_121 ) {
V_14 -> V_28 = V_13 -> V_168 ;
V_186 = V_13 -> V_99 ;
} else {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 ,
L_44 , V_94 ) ;
return NULL ;
}
if ( V_13 -> V_164 -> V_189 )
V_187 = ( V_118 == V_119 ) ? V_190 :
V_191 ;
else
V_187 = ( V_118 == V_119 ) ? V_192 :
V_193 ;
V_14 -> V_29 |= V_187 << V_103 ;
F_71 (sgl, sg, sg_len, tmp) {
V_58 = F_66 ( sizeof( struct V_57 ) , V_93 ) ;
if ( ! V_58 ) {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 , L_45 ,
V_94 ) ;
return NULL ;
}
F_50 ( & V_58 -> V_110 , & V_14 -> V_175 ) ;
V_58 -> V_59 = F_72 ( V_185 ) ;
if ( V_118 == V_119 ) {
V_58 -> V_99 = F_73 ( V_185 ) ;
V_58 -> V_100 = V_186 ;
} else {
V_58 -> V_99 = V_186 ;
V_58 -> V_100 = F_73 ( V_185 ) ;
}
}
V_112 = F_64 ( V_13 , V_14 ) ;
if ( V_112 )
return NULL ;
return & V_14 -> V_6 ;
}
static int F_74 ( struct V_2 * V_3 , enum V_194 V_195 ,
unsigned long V_196 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_112 = 0 ;
if ( V_195 == V_197 ) {
return F_60 ( V_3 ,
(struct V_154 * ) V_196 ) ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( ! V_13 -> V_18 && ! V_13 -> V_22 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
switch ( V_195 ) {
case V_198 :
V_13 -> V_126 = V_173 ;
if ( V_13 -> V_18 ) {
F_14 ( V_16 , V_13 -> V_18 ) ;
F_48 ( V_13 ) ;
}
if ( V_13 -> V_22 ) {
F_39 ( V_16 , V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
}
F_44 ( V_16 , V_13 ) ;
break;
case V_199 :
F_10 ( V_13 -> V_18 ) ;
V_13 -> V_126 = V_138 ;
break;
case V_200 :
F_13 ( V_13 -> V_18 ) ;
V_13 -> V_126 = V_172 ;
break;
default:
V_112 = - V_201 ;
break;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_112 ;
}
bool F_75 ( struct V_2 * V_3 , void * V_202 )
{
struct V_1 * V_13 ;
char * V_113 = V_202 ;
if ( V_3 -> V_203 -> V_24 -> V_204 != & V_205 . V_206 )
return false ;
V_13 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_13 -> V_113 , V_113 ) )
return true ;
return false ;
}
static void F_76 ( struct V_15 * V_16 )
{
F_9 ( V_35 , V_16 -> V_10 + V_207 ) ;
}
static void F_77 ( struct V_4 * V_14 )
{
struct V_203 * V_24 = V_14 -> V_6 . V_3 -> V_203 -> V_24 ;
struct V_57 * V_58 ;
if ( ! ( V_14 -> V_6 . V_48 & V_208 ) ) {
if ( V_14 -> V_6 . V_48 & V_209 )
F_20 (dsg, &txd->dsg_list, node)
F_78 ( V_24 , V_58 -> V_99 , V_58 -> V_59 ,
V_119 ) ;
else {
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_99 , V_58 -> V_59 ,
V_119 ) ;
}
}
if ( ! ( V_14 -> V_6 . V_48 & V_210 ) ) {
if ( V_14 -> V_6 . V_48 & V_211 )
F_20 (dsg, &txd->dsg_list, node)
F_78 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_121 ) ;
else
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_121 ) ;
}
}
static void F_80 ( unsigned long V_212 )
{
struct V_1 * V_13 = (struct V_1 * ) V_212 ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_14 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
if ( V_14 ) {
V_13 -> V_136 = V_14 -> V_6 . V_125 ;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_111 ;
V_111 = F_63 ( & V_13 -> V_55 ,
struct V_4 ,
V_110 ) ;
F_42 ( & V_111 -> V_110 ) ;
F_6 ( V_13 , V_111 ) ;
} else if ( V_13 -> V_123 ) {
} else {
struct V_1 * V_128 = NULL ;
F_48 ( V_13 ) ;
V_13 -> V_126 = V_173 ;
F_20 (waiting, &pl08x->memcpy.channels,
chan.device_node) {
if ( V_128 -> V_126 == V_127 &&
V_128 -> V_128 != NULL ) {
int V_112 ;
V_112 = F_47 ( V_128 ,
V_128 -> V_128 ) ;
F_18 ( V_112 ) ;
V_128 -> V_123 -- ;
V_128 -> V_126 = V_172 ;
V_128 -> V_128 = NULL ;
F_62 ( & V_128 -> V_3 ) ;
break;
}
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_14 ) {
T_6 V_213 = V_14 -> V_6 . V_213 ;
void * V_214 = V_14 -> V_6 . V_214 ;
if ( ! V_13 -> V_115 )
F_77 ( V_14 ) ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_213 )
V_213 ( V_214 ) ;
}
}
static T_7 F_81 ( int V_215 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
T_1 V_216 = 0 , V_217 , V_218 , V_61 ;
V_217 = F_5 ( V_16 -> V_10 + V_219 ) ;
if ( V_217 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_46 ,
V_94 , V_217 ) ;
F_9 ( V_217 , V_16 -> V_10 + V_40 ) ;
}
V_218 = F_5 ( V_16 -> V_10 + V_220 ) ;
if ( V_218 )
F_9 ( V_218 , V_16 -> V_10 + V_41 ) ;
if ( ! V_217 && ! V_218 )
return V_221 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
if ( ( ( 1 << V_61 ) & V_217 ) || ( ( 1 << V_61 ) & V_218 ) ) {
struct V_7 * V_18 = & V_16 -> V_64 [ V_61 ] ;
struct V_1 * V_13 = V_18 -> V_65 ;
if ( ! V_13 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_47 ,
V_94 , V_61 ) ;
continue;
}
F_82 ( & V_13 -> V_222 ) ;
V_216 |= ( 1 << V_61 ) ;
}
}
return V_216 ? V_223 : V_221 ;
}
static void F_83 ( struct V_1 * V_3 )
{
T_1 V_28 = F_56 ( V_3 -> V_164 -> V_28 ) ;
V_3 -> V_115 = true ;
V_3 -> V_113 = V_3 -> V_164 -> V_224 ;
V_3 -> V_99 = V_3 -> V_164 -> V_86 ;
V_3 -> V_100 = V_3 -> V_164 -> V_86 ;
V_3 -> V_168 = V_28 | V_80 |
F_55 ( V_3 -> V_164 -> V_169 , V_3 -> V_17 -> V_170 ) ;
V_3 -> V_171 = V_28 | V_83 |
F_55 ( V_3 -> V_17 -> V_170 , V_3 -> V_164 -> V_169 ) ;
}
static int F_84 ( struct V_15 * V_16 ,
struct V_225 * V_226 , unsigned int V_63 , bool V_115 )
{
struct V_1 * V_3 ;
int V_61 ;
F_68 ( & V_226 -> V_63 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_3 = F_66 ( sizeof( * V_3 ) , V_227 ) ;
if ( ! V_3 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_48 , V_94 ) ;
return - V_228 ;
}
V_3 -> V_17 = V_16 ;
V_3 -> V_126 = V_173 ;
if ( V_115 ) {
V_3 -> V_164 = & V_16 -> V_116 -> V_229 [ V_61 ] ;
F_83 ( V_3 ) ;
} else {
V_3 -> V_164 = & V_16 -> V_116 -> V_179 ;
V_3 -> V_113 = F_85 ( V_227 , L_49 , V_61 ) ;
if ( ! V_3 -> V_113 ) {
F_43 ( V_3 ) ;
return - V_228 ;
}
}
if ( V_3 -> V_164 -> V_230 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_50 ,
V_3 -> V_113 ) ;
F_43 ( V_3 ) ;
continue;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_51 ,
V_3 -> V_113 ) ;
V_3 -> V_3 . V_203 = V_226 ;
V_3 -> V_3 . V_125 = 0 ;
V_3 -> V_136 = 0 ;
F_86 ( & V_3 -> V_49 ) ;
F_68 ( & V_3 -> V_55 ) ;
F_87 ( & V_3 -> V_222 , F_80 ,
( unsigned long ) V_3 ) ;
F_50 ( & V_3 -> V_3 . V_231 , & V_226 -> V_63 ) ;
}
F_88 ( & V_16 -> V_23 -> V_24 , L_52 ,
V_61 , V_115 ? L_53 : L_54 ) ;
return V_61 ;
}
static void F_89 ( struct V_225 * V_226 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_111 ;
F_41 (chan,
next, &dmadev->channels, chan.device_node) {
F_42 ( & V_3 -> V_3 . V_231 ) ;
F_43 ( V_3 ) ;
}
}
static const char * F_90 ( enum V_232 V_126 )
{
switch ( V_126 ) {
case V_173 :
return L_55 ;
case V_172 :
return L_56 ;
case V_138 :
return L_57 ;
case V_127 :
return L_58 ;
default:
break;
}
return L_59 ;
}
static int F_91 ( struct V_233 * V_234 , void * V_212 )
{
struct V_15 * V_16 = V_234 -> V_235 ;
struct V_1 * V_3 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
int V_61 ;
F_92 ( V_234 , L_60 ) ;
F_92 ( V_234 , L_61 ) ;
F_92 ( V_234 , L_62 ) ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
struct V_1 * V_60 ;
V_8 = & V_16 -> V_64 [ V_61 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
V_60 = V_8 -> V_65 ;
F_92 ( V_234 , L_63 ,
V_8 -> V_25 , V_60 ? V_60 -> V_113 : L_64 ) ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
F_92 ( V_234 , L_65 ) ;
F_92 ( V_234 , L_66 ) ;
F_92 ( V_234 , L_67 ) ;
F_20 (chan, &pl08x->memcpy.channels, chan.device_node) {
F_92 ( V_234 , L_68 , V_3 -> V_113 ,
F_90 ( V_3 -> V_126 ) ) ;
}
F_92 ( V_234 , L_69 ) ;
F_92 ( V_234 , L_66 ) ;
F_92 ( V_234 , L_67 ) ;
F_20 (chan, &pl08x->slave.channels, chan.device_node) {
F_92 ( V_234 , L_68 , V_3 -> V_113 ,
F_90 ( V_3 -> V_126 ) ) ;
}
return 0 ;
}
static int F_93 ( struct V_236 * V_236 , struct V_237 * V_237 )
{
return F_94 ( V_237 , F_91 , V_236 -> V_238 ) ;
}
static void F_95 ( struct V_15 * V_16 )
{
( void ) F_96 ( F_97 ( & V_16 -> V_23 -> V_24 ) ,
V_239 | V_240 , NULL , V_16 ,
& V_241 ) ;
}
static inline void F_95 ( struct V_15 * V_16 )
{
}
static int F_98 ( struct V_242 * V_23 , const struct V_243 * V_25 )
{
struct V_15 * V_16 ;
const struct V_244 * V_62 = V_25 -> V_212 ;
int V_112 = 0 ;
int V_61 ;
V_112 = F_99 ( V_23 , NULL ) ;
if ( V_112 )
return V_112 ;
V_16 = F_66 ( sizeof( * V_16 ) , V_227 ) ;
if ( ! V_16 ) {
V_112 = - V_228 ;
goto V_245;
}
F_100 ( & V_23 -> V_24 ) ;
F_101 ( & V_23 -> V_24 ) ;
F_102 ( V_246 , V_16 -> memcpy . V_247 ) ;
V_16 -> memcpy . V_24 = & V_23 -> V_24 ;
V_16 -> memcpy . V_248 = F_45 ;
V_16 -> memcpy . V_249 = F_46 ;
V_16 -> memcpy . V_250 = F_69 ;
V_16 -> memcpy . V_251 = F_51 ;
V_16 -> memcpy . V_252 = F_52 ;
V_16 -> memcpy . V_253 = F_62 ;
V_16 -> memcpy . V_254 = F_74 ;
F_102 ( V_255 , V_16 -> V_115 . V_247 ) ;
V_16 -> V_115 . V_24 = & V_23 -> V_24 ;
V_16 -> V_115 . V_248 = F_45 ;
V_16 -> V_115 . V_249 = F_46 ;
V_16 -> V_115 . V_251 = F_51 ;
V_16 -> V_115 . V_252 = F_52 ;
V_16 -> V_115 . V_253 = F_62 ;
V_16 -> V_115 . V_256 = F_70 ;
V_16 -> V_115 . V_254 = F_74 ;
V_16 -> V_116 = F_103 ( & V_23 -> V_24 ) ;
if ( ! V_16 -> V_116 ) {
F_34 ( & V_23 -> V_24 , L_70 ) ;
goto V_257;
}
V_16 -> V_23 = V_23 ;
V_16 -> V_62 = V_62 ;
V_16 -> V_96 = V_141 ;
V_16 -> V_170 = V_141 ;
if ( V_16 -> V_62 -> V_180 ) {
V_16 -> V_96 = V_16 -> V_116 -> V_96 ;
V_16 -> V_170 = V_16 -> V_116 -> V_170 ;
}
V_16 -> V_92 = F_104 ( V_258 , & V_16 -> V_23 -> V_24 ,
V_259 , V_260 , 0 ) ;
if ( ! V_16 -> V_92 ) {
V_112 = - V_228 ;
goto V_261;
}
F_86 ( & V_16 -> V_49 ) ;
V_16 -> V_10 = F_105 ( V_23 -> V_262 . V_263 , F_106 ( & V_23 -> V_262 ) ) ;
if ( ! V_16 -> V_10 ) {
V_112 = - V_228 ;
goto V_264;
}
F_76 ( V_16 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_41 ) ;
V_112 = F_107 ( V_23 -> V_215 [ 0 ] , F_81 , V_265 ,
V_258 , V_16 ) ;
if ( V_112 ) {
F_34 ( & V_23 -> V_24 , L_71 ,
V_94 , V_23 -> V_215 [ 0 ] ) ;
goto V_266;
}
V_16 -> V_64 = F_108 ( ( V_62 -> V_63 * sizeof( * V_16 -> V_64 ) ) ,
V_227 ) ;
if ( ! V_16 -> V_64 ) {
F_34 ( & V_23 -> V_24 , L_72
L_73 ,
V_94 ) ;
goto V_267;
}
for ( V_61 = 0 ; V_61 < V_62 -> V_63 ; V_61 ++ ) {
struct V_7 * V_8 = & V_16 -> V_64 [ V_61 ] ;
V_8 -> V_25 = V_61 ;
V_8 -> V_10 = V_16 -> V_10 + F_109 ( V_61 ) ;
F_86 ( & V_8 -> V_49 ) ;
V_8 -> V_65 = NULL ;
V_8 -> signal = - 1 ;
F_35 ( & V_23 -> V_24 , L_74 ,
V_61 , F_4 ( V_8 ) ? L_75 : L_76 ) ;
}
V_112 = F_84 ( V_16 , & V_16 -> memcpy ,
V_16 -> V_62 -> V_63 , false ) ;
if ( V_112 <= 0 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_77 ,
V_94 , V_112 ) ;
goto V_268;
}
V_16 -> memcpy . V_269 = V_112 ;
V_112 = F_84 ( V_16 , & V_16 -> V_115 ,
V_16 -> V_116 -> V_270 , true ) ;
if ( V_112 <= 0 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_78 ,
V_94 , V_112 ) ;
goto V_271;
}
V_16 -> V_115 . V_269 = V_112 ;
V_112 = F_111 ( & V_16 -> memcpy ) ;
if ( V_112 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_79 ,
V_94 , V_112 ) ;
goto V_272;
}
V_112 = F_111 ( & V_16 -> V_115 ) ;
if ( V_112 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_80 ,
V_94 , V_112 ) ;
goto V_273;
}
F_112 ( V_23 , V_16 ) ;
F_95 ( V_16 ) ;
F_88 ( & V_16 -> V_23 -> V_24 , L_81 ,
F_113 ( V_23 ) , F_114 ( V_23 ) ,
( unsigned long long ) V_23 -> V_262 . V_263 , V_23 -> V_215 [ 0 ] ) ;
F_25 ( & V_23 -> V_24 ) ;
return 0 ;
V_273:
F_115 ( & V_16 -> memcpy ) ;
V_272:
F_89 ( & V_16 -> V_115 ) ;
V_271:
F_89 ( & V_16 -> memcpy ) ;
V_268:
F_43 ( V_16 -> V_64 ) ;
V_267:
F_116 ( V_23 -> V_215 [ 0 ] , V_16 ) ;
V_266:
F_117 ( V_16 -> V_10 ) ;
V_264:
F_118 ( V_16 -> V_92 ) ;
V_261:
V_257:
F_25 ( & V_23 -> V_24 ) ;
F_119 ( & V_23 -> V_24 ) ;
F_43 ( V_16 ) ;
V_245:
F_120 ( V_23 ) ;
return V_112 ;
}
static int T_8 F_121 ( void )
{
int V_129 ;
V_129 = F_122 ( & V_205 ) ;
if ( V_129 )
F_123 (KERN_WARNING DRIVER_NAME
L_82 ,
retval) ;
return V_129 ;
}
