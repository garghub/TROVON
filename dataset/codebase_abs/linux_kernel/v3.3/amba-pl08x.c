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
if ( V_13 -> V_18 ) {
V_8 = V_13 -> V_18 ;
goto V_113;
}
V_8 = F_22 ( V_16 , V_13 ) ;
if ( ! V_8 ) {
F_35 ( & V_16 -> V_23 -> V_24 , L_29 , V_13 -> V_114 ) ;
return - V_115 ;
}
if ( V_13 -> V_116 && V_16 -> V_117 -> V_118 ) {
V_112 = V_16 -> V_117 -> V_118 ( V_13 ) ;
if ( V_112 < 0 ) {
F_35 ( & V_16 -> V_23 -> V_24 ,
L_30 ,
V_8 -> V_25 , V_13 -> V_114 ) ;
F_24 ( V_16 , V_8 ) ;
return - V_115 ;
}
V_8 -> signal = V_112 ;
}
V_13 -> V_18 = V_8 ;
F_35 ( & V_16 -> V_23 -> V_24 , L_31 ,
V_8 -> V_25 ,
V_8 -> signal ,
V_13 -> V_114 ) ;
V_113:
if ( V_14 -> V_119 == V_120 )
V_14 -> V_29 |= V_8 -> signal << V_121 ;
else if ( V_14 -> V_119 == V_122 )
V_14 -> V_29 |= V_8 -> signal << V_123 ;
V_13 -> V_124 ++ ;
return 0 ;
}
static void F_48 ( struct V_1 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( ( V_13 -> V_18 -> signal >= 0 ) && V_16 -> V_117 -> V_125 ) {
V_16 -> V_117 -> V_125 ( V_13 ) ;
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
V_13 -> V_3 . V_126 += 1 ;
if ( V_13 -> V_3 . V_126 < 0 )
V_13 -> V_3 . V_126 = 1 ;
V_6 -> V_126 = V_13 -> V_3 . V_126 ;
F_50 ( & V_14 -> V_110 , & V_13 -> V_55 ) ;
if ( ! V_13 -> V_116 && ! V_13 -> V_18 ) {
V_13 -> V_127 = V_128 ;
V_13 -> V_129 = V_14 ;
} else {
V_13 -> V_124 -- ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_6 -> V_126 ;
}
static struct V_5 * F_51 (
struct V_2 * V_3 , unsigned long V_48 )
{
struct V_5 * V_130 = NULL ;
return V_130 ;
}
static enum V_131 F_52 ( struct V_2 * V_3 ,
T_5 V_126 , struct V_132 * V_133 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_5 V_134 ;
T_5 V_135 ;
enum V_131 V_112 ;
T_1 V_136 = 0 ;
V_134 = V_13 -> V_3 . V_126 ;
V_135 = V_13 -> V_137 ;
V_112 = F_53 ( V_126 , V_135 , V_134 ) ;
if ( V_112 == V_138 ) {
F_54 ( V_133 , V_135 , V_134 , 0 ) ;
return V_112 ;
}
V_134 = V_13 -> V_3 . V_126 ;
V_135 = V_13 -> V_137 ;
V_136 = F_16 ( V_13 ) ;
F_54 ( V_133 , V_135 , V_134 ,
V_136 ) ;
if ( V_13 -> V_127 == V_139 )
return V_140 ;
return V_141 ;
}
static T_1 F_55 ( T_4 V_26 , T_4 V_27 )
{
T_1 V_28 = 0 ;
if ( ! ( V_27 & V_142 ) || ( ( V_27 & V_97 ) && ( V_26 & V_142 ) ) )
V_28 |= V_143 ;
if ( ! ( V_26 & V_142 ) || ( ( V_26 & V_97 ) && ! ( V_27 & V_97 ) ) )
V_28 |= V_144 ;
return V_28 ;
}
static T_1 F_56 ( T_1 V_28 )
{
V_28 &= ~ ( V_144 | V_143 |
V_83 | V_80 |
V_145 ) ;
return V_28 | V_146 ;
}
static T_1 F_57 ( enum V_147 V_107 )
{
switch ( V_107 ) {
case V_148 :
return V_45 ;
case V_149 :
return V_46 ;
case V_150 :
return V_47 ;
default:
return ~ 0 ;
}
}
static T_1 F_58 ( T_1 V_151 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_59 ( V_152 ) ; V_61 ++ )
if ( V_152 [ V_61 ] . V_153 <= V_151 )
break;
return V_152 [ V_61 ] . V_154 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_155 * V_156 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
enum V_147 V_157 ;
T_1 V_107 , V_158 , V_151 ;
T_1 V_28 = 0 ;
if ( ! V_13 -> V_116 )
return - V_159 ;
V_13 -> V_160 = V_156 -> V_119 ;
if ( V_156 -> V_119 == V_120 ) {
V_157 = V_156 -> V_161 ;
V_151 = V_156 -> V_162 ;
} else if ( V_156 -> V_119 == V_122 ) {
V_157 = V_156 -> V_163 ;
V_151 = V_156 -> V_164 ;
} else {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_32 ) ;
return - V_159 ;
}
V_107 = F_57 ( V_157 ) ;
if ( V_107 == ~ 0 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_33 ) ;
return - V_159 ;
}
V_28 |= V_107 << V_44 ;
V_28 |= V_107 << V_73 ;
if ( V_13 -> V_165 -> V_166 )
V_151 = 1 ;
V_158 = F_58 ( V_151 ) ;
V_28 |= V_158 << V_167 ;
V_28 |= V_158 << V_168 ;
if ( V_13 -> V_160 == V_122 ) {
V_13 -> V_99 = V_156 -> V_99 ;
V_13 -> V_169 = F_56 ( V_28 ) | V_80 |
F_55 ( V_13 -> V_165 -> V_170 ,
V_16 -> V_171 ) ;
} else {
V_13 -> V_100 = V_156 -> V_100 ;
V_13 -> V_172 = F_56 ( V_28 ) | V_83 |
F_55 ( V_16 -> V_171 ,
V_13 -> V_165 -> V_170 ) ;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_34
L_35 ,
F_61 ( V_3 ) , V_13 -> V_114 ,
( V_156 -> V_119 == V_122 ) ? L_36 : L_37 ,
V_157 ,
V_151 ,
V_28 ) ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( V_13 -> V_22 || V_13 -> V_127 == V_128 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_111 ;
V_111 = F_63 ( & V_13 -> V_55 ,
struct V_4 ,
V_110 ) ;
F_42 ( & V_111 -> V_110 ) ;
V_13 -> V_127 = V_173 ;
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
return - V_159 ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_112 = F_47 ( V_13 , V_14 ) ;
if ( V_112 ) {
if ( V_13 -> V_116 ) {
F_44 ( V_16 , V_13 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_115 ;
}
} else
if ( V_13 -> V_127 == V_174 )
V_13 -> V_127 = V_139 ;
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
V_14 -> V_6 . V_175 = F_49 ;
F_68 ( & V_14 -> V_110 ) ;
F_68 ( & V_14 -> V_176 ) ;
V_14 -> V_29 = V_38 |
V_39 ;
}
return V_14 ;
}
static struct V_5 * F_69 (
struct V_2 * V_3 , T_3 V_177 , T_3 V_26 ,
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
F_50 ( & V_58 -> V_110 , & V_14 -> V_176 ) ;
V_14 -> V_119 = V_178 ;
V_58 -> V_99 = V_26 ;
V_58 -> V_100 = V_177 ;
V_58 -> V_59 = V_59 ;
V_14 -> V_29 |= V_179 << V_103 ;
V_14 -> V_28 = V_16 -> V_117 -> V_180 . V_28 &
~ ( V_143 | V_144 ) ;
V_14 -> V_28 |= V_83 | V_80 ;
if ( V_16 -> V_62 -> V_181 )
V_14 -> V_28 |= F_55 ( V_16 -> V_171 ,
V_16 -> V_171 ) ;
V_112 = F_64 ( V_13 , V_14 ) ;
if ( V_112 )
return NULL ;
return & V_14 -> V_6 ;
}
static struct V_5 * F_70 (
struct V_2 * V_3 , struct V_182 * V_183 ,
unsigned int V_184 , enum V_185 V_119 ,
unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
struct V_57 * V_58 ;
struct V_182 * V_186 ;
T_3 V_187 ;
int V_112 , V_188 ;
F_35 ( & V_16 -> V_23 -> V_24 , L_40 ,
V_94 , V_183 -> V_189 , V_13 -> V_114 ) ;
V_14 = F_65 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_41 , V_94 ) ;
return NULL ;
}
if ( V_119 != V_13 -> V_160 )
F_34 ( & V_16 -> V_23 -> V_24 , L_42
L_43 ,
V_94 ) ;
V_14 -> V_119 = V_119 ;
if ( V_119 == V_120 ) {
V_14 -> V_28 = V_13 -> V_172 ;
V_187 = V_13 -> V_100 ;
} else if ( V_119 == V_122 ) {
V_14 -> V_28 = V_13 -> V_169 ;
V_187 = V_13 -> V_99 ;
} else {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 ,
L_44 , V_94 ) ;
return NULL ;
}
if ( V_13 -> V_165 -> V_190 )
V_188 = ( V_119 == V_120 ) ? V_191 :
V_192 ;
else
V_188 = ( V_119 == V_120 ) ? V_193 :
V_194 ;
V_14 -> V_29 |= V_188 << V_103 ;
F_71 (sgl, sg, sg_len, tmp) {
V_58 = F_66 ( sizeof( struct V_57 ) , V_93 ) ;
if ( ! V_58 ) {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 , L_45 ,
V_94 ) ;
return NULL ;
}
F_50 ( & V_58 -> V_110 , & V_14 -> V_176 ) ;
V_58 -> V_59 = F_72 ( V_186 ) ;
if ( V_119 == V_120 ) {
V_58 -> V_99 = F_73 ( V_186 ) ;
V_58 -> V_100 = V_187 ;
} else {
V_58 -> V_99 = V_187 ;
V_58 -> V_100 = F_73 ( V_186 ) ;
}
}
V_112 = F_64 ( V_13 , V_14 ) ;
if ( V_112 )
return NULL ;
return & V_14 -> V_6 ;
}
static int F_74 ( struct V_2 * V_3 , enum V_195 V_196 ,
unsigned long V_197 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_112 = 0 ;
if ( V_196 == V_198 ) {
return F_60 ( V_3 ,
(struct V_155 * ) V_197 ) ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( ! V_13 -> V_18 && ! V_13 -> V_22 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
switch ( V_196 ) {
case V_199 :
V_13 -> V_127 = V_174 ;
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
case V_200 :
F_10 ( V_13 -> V_18 ) ;
V_13 -> V_127 = V_139 ;
break;
case V_201 :
F_13 ( V_13 -> V_18 ) ;
V_13 -> V_127 = V_173 ;
break;
default:
V_112 = - V_202 ;
break;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_112 ;
}
bool F_75 ( struct V_2 * V_3 , void * V_203 )
{
struct V_1 * V_13 ;
char * V_114 = V_203 ;
if ( V_3 -> V_204 -> V_24 -> V_205 != & V_206 . V_207 )
return false ;
V_13 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_13 -> V_114 , V_114 ) )
return true ;
return false ;
}
static void F_76 ( struct V_15 * V_16 )
{
F_9 ( V_35 , V_16 -> V_10 + V_208 ) ;
}
static void F_77 ( struct V_4 * V_14 )
{
struct V_204 * V_24 = V_14 -> V_6 . V_3 -> V_204 -> V_24 ;
struct V_57 * V_58 ;
if ( ! ( V_14 -> V_6 . V_48 & V_209 ) ) {
if ( V_14 -> V_6 . V_48 & V_210 )
F_20 (dsg, &txd->dsg_list, node)
F_78 ( V_24 , V_58 -> V_99 , V_58 -> V_59 ,
V_211 ) ;
else {
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_99 , V_58 -> V_59 ,
V_211 ) ;
}
}
if ( ! ( V_14 -> V_6 . V_48 & V_212 ) ) {
if ( V_14 -> V_6 . V_48 & V_213 )
F_20 (dsg, &txd->dsg_list, node)
F_78 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_214 ) ;
else
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_214 ) ;
}
}
static void F_80 ( unsigned long V_215 )
{
struct V_1 * V_13 = (struct V_1 * ) V_215 ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_14 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
if ( V_14 ) {
V_13 -> V_137 = V_14 -> V_6 . V_126 ;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_111 ;
V_111 = F_63 ( & V_13 -> V_55 ,
struct V_4 ,
V_110 ) ;
F_42 ( & V_111 -> V_110 ) ;
F_6 ( V_13 , V_111 ) ;
} else if ( V_13 -> V_124 ) {
} else {
struct V_1 * V_129 = NULL ;
F_48 ( V_13 ) ;
V_13 -> V_127 = V_174 ;
F_20 (waiting, &pl08x->memcpy.channels,
chan.device_node) {
if ( V_129 -> V_127 == V_128 &&
V_129 -> V_129 != NULL ) {
int V_112 ;
V_112 = F_47 ( V_129 ,
V_129 -> V_129 ) ;
F_18 ( V_112 ) ;
V_129 -> V_124 -- ;
V_129 -> V_127 = V_173 ;
V_129 -> V_129 = NULL ;
F_62 ( & V_129 -> V_3 ) ;
break;
}
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_14 ) {
T_6 V_216 = V_14 -> V_6 . V_216 ;
void * V_217 = V_14 -> V_6 . V_217 ;
if ( ! V_13 -> V_116 )
F_77 ( V_14 ) ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_216 )
V_216 ( V_217 ) ;
}
}
static T_7 F_81 ( int V_218 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
T_1 V_219 = 0 , V_220 , V_221 , V_61 ;
V_220 = F_5 ( V_16 -> V_10 + V_222 ) ;
if ( V_220 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_46 ,
V_94 , V_220 ) ;
F_9 ( V_220 , V_16 -> V_10 + V_40 ) ;
}
V_221 = F_5 ( V_16 -> V_10 + V_223 ) ;
if ( V_221 )
F_9 ( V_221 , V_16 -> V_10 + V_41 ) ;
if ( ! V_220 && ! V_221 )
return V_224 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
if ( ( ( 1 << V_61 ) & V_220 ) || ( ( 1 << V_61 ) & V_221 ) ) {
struct V_7 * V_18 = & V_16 -> V_64 [ V_61 ] ;
struct V_1 * V_13 = V_18 -> V_65 ;
if ( ! V_13 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_47 ,
V_94 , V_61 ) ;
continue;
}
F_82 ( & V_13 -> V_225 ) ;
V_219 |= ( 1 << V_61 ) ;
}
}
return V_219 ? V_226 : V_224 ;
}
static void F_83 ( struct V_1 * V_3 )
{
T_1 V_28 = F_56 ( V_3 -> V_165 -> V_28 ) ;
V_3 -> V_116 = true ;
V_3 -> V_114 = V_3 -> V_165 -> V_227 ;
V_3 -> V_99 = V_3 -> V_165 -> V_86 ;
V_3 -> V_100 = V_3 -> V_165 -> V_86 ;
V_3 -> V_169 = V_28 | V_80 |
F_55 ( V_3 -> V_165 -> V_170 , V_3 -> V_17 -> V_171 ) ;
V_3 -> V_172 = V_28 | V_83 |
F_55 ( V_3 -> V_17 -> V_171 , V_3 -> V_165 -> V_170 ) ;
}
static int F_84 ( struct V_15 * V_16 ,
struct V_228 * V_229 , unsigned int V_63 , bool V_116 )
{
struct V_1 * V_3 ;
int V_61 ;
F_68 ( & V_229 -> V_63 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_3 = F_66 ( sizeof( * V_3 ) , V_230 ) ;
if ( ! V_3 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_48 , V_94 ) ;
return - V_231 ;
}
V_3 -> V_17 = V_16 ;
V_3 -> V_127 = V_174 ;
if ( V_116 ) {
V_3 -> V_165 = & V_16 -> V_117 -> V_232 [ V_61 ] ;
F_83 ( V_3 ) ;
} else {
V_3 -> V_165 = & V_16 -> V_117 -> V_180 ;
V_3 -> V_114 = F_85 ( V_230 , L_49 , V_61 ) ;
if ( ! V_3 -> V_114 ) {
F_43 ( V_3 ) ;
return - V_231 ;
}
}
if ( V_3 -> V_165 -> V_233 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_50 ,
V_3 -> V_114 ) ;
F_43 ( V_3 ) ;
continue;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_51 ,
V_3 -> V_114 ) ;
V_3 -> V_3 . V_204 = V_229 ;
V_3 -> V_3 . V_126 = 0 ;
V_3 -> V_137 = 0 ;
F_86 ( & V_3 -> V_49 ) ;
F_68 ( & V_3 -> V_55 ) ;
F_87 ( & V_3 -> V_225 , F_80 ,
( unsigned long ) V_3 ) ;
F_50 ( & V_3 -> V_3 . V_234 , & V_229 -> V_63 ) ;
}
F_88 ( & V_16 -> V_23 -> V_24 , L_52 ,
V_61 , V_116 ? L_53 : L_54 ) ;
return V_61 ;
}
static void F_89 ( struct V_228 * V_229 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_111 ;
F_41 (chan,
next, &dmadev->channels, chan.device_node) {
F_42 ( & V_3 -> V_3 . V_234 ) ;
F_43 ( V_3 ) ;
}
}
static const char * F_90 ( enum V_235 V_127 )
{
switch ( V_127 ) {
case V_174 :
return L_55 ;
case V_173 :
return L_56 ;
case V_139 :
return L_57 ;
case V_128 :
return L_58 ;
default:
break;
}
return L_59 ;
}
static int F_91 ( struct V_236 * V_237 , void * V_215 )
{
struct V_15 * V_16 = V_237 -> V_238 ;
struct V_1 * V_3 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
int V_61 ;
F_92 ( V_237 , L_60 ) ;
F_92 ( V_237 , L_61 ) ;
F_92 ( V_237 , L_62 ) ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
struct V_1 * V_60 ;
V_8 = & V_16 -> V_64 [ V_61 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
V_60 = V_8 -> V_65 ;
F_92 ( V_237 , L_63 ,
V_8 -> V_25 , V_60 ? V_60 -> V_114 : L_64 ) ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
F_92 ( V_237 , L_65 ) ;
F_92 ( V_237 , L_66 ) ;
F_92 ( V_237 , L_67 ) ;
F_20 (chan, &pl08x->memcpy.channels, chan.device_node) {
F_92 ( V_237 , L_68 , V_3 -> V_114 ,
F_90 ( V_3 -> V_127 ) ) ;
}
F_92 ( V_237 , L_69 ) ;
F_92 ( V_237 , L_66 ) ;
F_92 ( V_237 , L_67 ) ;
F_20 (chan, &pl08x->slave.channels, chan.device_node) {
F_92 ( V_237 , L_68 , V_3 -> V_114 ,
F_90 ( V_3 -> V_127 ) ) ;
}
return 0 ;
}
static int F_93 ( struct V_239 * V_239 , struct V_240 * V_240 )
{
return F_94 ( V_240 , F_91 , V_239 -> V_241 ) ;
}
static void F_95 ( struct V_15 * V_16 )
{
( void ) F_96 ( F_97 ( & V_16 -> V_23 -> V_24 ) ,
V_242 | V_243 , NULL , V_16 ,
& V_244 ) ;
}
static inline void F_95 ( struct V_15 * V_16 )
{
}
static int F_98 ( struct V_245 * V_23 , const struct V_246 * V_25 )
{
struct V_15 * V_16 ;
const struct V_247 * V_62 = V_25 -> V_215 ;
int V_112 = 0 ;
int V_61 ;
V_112 = F_99 ( V_23 , NULL ) ;
if ( V_112 )
return V_112 ;
V_16 = F_66 ( sizeof( * V_16 ) , V_230 ) ;
if ( ! V_16 ) {
V_112 = - V_231 ;
goto V_248;
}
F_100 ( & V_23 -> V_24 ) ;
F_101 ( & V_23 -> V_24 ) ;
F_102 ( V_249 , V_16 -> memcpy . V_250 ) ;
V_16 -> memcpy . V_24 = & V_23 -> V_24 ;
V_16 -> memcpy . V_251 = F_45 ;
V_16 -> memcpy . V_252 = F_46 ;
V_16 -> memcpy . V_253 = F_69 ;
V_16 -> memcpy . V_254 = F_51 ;
V_16 -> memcpy . V_255 = F_52 ;
V_16 -> memcpy . V_256 = F_62 ;
V_16 -> memcpy . V_257 = F_74 ;
F_102 ( V_258 , V_16 -> V_116 . V_250 ) ;
V_16 -> V_116 . V_24 = & V_23 -> V_24 ;
V_16 -> V_116 . V_251 = F_45 ;
V_16 -> V_116 . V_252 = F_46 ;
V_16 -> V_116 . V_254 = F_51 ;
V_16 -> V_116 . V_255 = F_52 ;
V_16 -> V_116 . V_256 = F_62 ;
V_16 -> V_116 . V_259 = F_70 ;
V_16 -> V_116 . V_257 = F_74 ;
V_16 -> V_117 = F_103 ( & V_23 -> V_24 ) ;
if ( ! V_16 -> V_117 ) {
F_34 ( & V_23 -> V_24 , L_70 ) ;
goto V_260;
}
V_16 -> V_23 = V_23 ;
V_16 -> V_62 = V_62 ;
V_16 -> V_96 = V_142 ;
V_16 -> V_171 = V_142 ;
if ( V_16 -> V_62 -> V_181 ) {
V_16 -> V_96 = V_16 -> V_117 -> V_96 ;
V_16 -> V_171 = V_16 -> V_117 -> V_171 ;
}
V_16 -> V_92 = F_104 ( V_261 , & V_16 -> V_23 -> V_24 ,
V_262 , V_263 , 0 ) ;
if ( ! V_16 -> V_92 ) {
V_112 = - V_231 ;
goto V_264;
}
F_86 ( & V_16 -> V_49 ) ;
V_16 -> V_10 = F_105 ( V_23 -> V_265 . V_266 , F_106 ( & V_23 -> V_265 ) ) ;
if ( ! V_16 -> V_10 ) {
V_112 = - V_231 ;
goto V_267;
}
F_76 ( V_16 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_41 ) ;
V_112 = F_107 ( V_23 -> V_218 [ 0 ] , F_81 , V_268 ,
V_261 , V_16 ) ;
if ( V_112 ) {
F_34 ( & V_23 -> V_24 , L_71 ,
V_94 , V_23 -> V_218 [ 0 ] ) ;
goto V_269;
}
V_16 -> V_64 = F_108 ( ( V_62 -> V_63 * sizeof( * V_16 -> V_64 ) ) ,
V_230 ) ;
if ( ! V_16 -> V_64 ) {
F_34 ( & V_23 -> V_24 , L_72
L_73 ,
V_94 ) ;
goto V_270;
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
goto V_271;
}
V_16 -> memcpy . V_272 = V_112 ;
V_112 = F_84 ( V_16 , & V_16 -> V_116 ,
V_16 -> V_117 -> V_273 , true ) ;
if ( V_112 <= 0 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_78 ,
V_94 , V_112 ) ;
goto V_274;
}
V_16 -> V_116 . V_272 = V_112 ;
V_112 = F_111 ( & V_16 -> memcpy ) ;
if ( V_112 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_79 ,
V_94 , V_112 ) ;
goto V_275;
}
V_112 = F_111 ( & V_16 -> V_116 ) ;
if ( V_112 ) {
F_110 ( & V_16 -> V_23 -> V_24 ,
L_80 ,
V_94 , V_112 ) ;
goto V_276;
}
F_112 ( V_23 , V_16 ) ;
F_95 ( V_16 ) ;
F_88 ( & V_16 -> V_23 -> V_24 , L_81 ,
F_113 ( V_23 ) , F_114 ( V_23 ) ,
( unsigned long long ) V_23 -> V_265 . V_266 , V_23 -> V_218 [ 0 ] ) ;
F_25 ( & V_23 -> V_24 ) ;
return 0 ;
V_276:
F_115 ( & V_16 -> memcpy ) ;
V_275:
F_89 ( & V_16 -> V_116 ) ;
V_274:
F_89 ( & V_16 -> memcpy ) ;
V_271:
F_43 ( V_16 -> V_64 ) ;
V_270:
F_116 ( V_23 -> V_218 [ 0 ] , V_16 ) ;
V_269:
F_117 ( V_16 -> V_10 ) ;
V_267:
F_118 ( V_16 -> V_92 ) ;
V_264:
V_260:
F_25 ( & V_23 -> V_24 ) ;
F_119 ( & V_23 -> V_24 ) ;
F_43 ( V_16 ) ;
V_248:
F_120 ( V_23 ) ;
return V_112 ;
}
static int T_8 F_121 ( void )
{
int V_130 ;
V_130 = F_122 ( & V_206 ) ;
if ( V_130 )
F_123 (KERN_WARNING DRIVER_NAME
L_82 ,
retval) ;
return V_130 ;
}
