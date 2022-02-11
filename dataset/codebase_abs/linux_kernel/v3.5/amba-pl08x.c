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
if ( ! V_8 -> V_65 && ! V_8 -> V_66 ) {
V_8 -> V_66 = V_60 ;
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
V_8 -> V_66 = NULL ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
static inline unsigned int F_26 ( unsigned int V_67 )
{
switch ( V_67 ) {
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
static inline T_1 F_28 ( T_1 V_28 , T_4 V_68 , T_4 V_69 ,
T_2 V_70 )
{
T_1 V_71 = V_28 ;
V_71 &= ~ V_72 ;
V_71 &= ~ V_73 ;
V_71 &= ~ V_43 ;
switch ( V_68 ) {
case 1 :
V_71 |= V_45 << V_44 ;
break;
case 2 :
V_71 |= V_46 << V_44 ;
break;
case 4 :
V_71 |= V_47 << V_44 ;
break;
default:
F_27 () ;
break;
}
switch ( V_69 ) {
case 1 :
V_71 |= V_45 << V_74 ;
break;
case 2 :
V_71 |= V_46 << V_74 ;
break;
case 4 :
V_71 |= V_47 << V_74 ;
break;
default:
F_27 () ;
break;
}
V_71 |= V_70 << V_75 ;
return V_71 ;
}
static void F_29 ( struct V_76 * V_77 ,
struct V_78 * * V_79 , struct V_78 * * V_80 , T_1 V_28 )
{
if ( ! ( V_28 & V_81 ) ) {
* V_79 = & V_77 -> V_82 ;
* V_80 = & V_77 -> V_83 ;
} else if ( ! ( V_28 & V_84 ) ) {
* V_79 = & V_77 -> V_83 ;
* V_80 = & V_77 -> V_82 ;
} else {
if ( V_77 -> V_82 . V_85 >= V_77 -> V_83 . V_85 ) {
* V_79 = & V_77 -> V_82 ;
* V_80 = & V_77 -> V_83 ;
} else {
* V_79 = & V_77 -> V_83 ;
* V_80 = & V_77 -> V_82 ;
}
}
}
static void F_30 ( struct V_76 * V_77 ,
int V_86 , int V_59 , T_1 V_28 )
{
struct V_19 * V_21 = V_77 -> V_14 -> V_21 ;
T_3 V_52 = V_77 -> V_14 -> V_52 ;
F_18 ( V_86 >= V_54 ) ;
V_21 [ V_86 ] . V_28 = V_28 ;
V_21 [ V_86 ] . V_26 = V_77 -> V_83 . V_87 ;
V_21 [ V_86 ] . V_27 = V_77 -> V_82 . V_87 ;
V_21 [ V_86 ] . V_20 = V_52 + ( V_86 + 1 ) *
sizeof( struct V_19 ) ;
V_21 [ V_86 ] . V_20 |= V_77 -> V_88 ;
if ( V_28 & V_84 )
V_77 -> V_83 . V_87 += V_59 ;
if ( V_28 & V_81 )
V_77 -> V_82 . V_87 += V_59 ;
F_18 ( V_77 -> V_89 < V_59 ) ;
V_77 -> V_89 -= V_59 ;
}
static inline void F_31 ( struct V_76 * V_77 ,
T_1 * V_28 , T_1 V_59 , int V_86 , T_2 * V_90 )
{
* V_28 = F_28 ( * V_28 , 1 , 1 , V_59 ) ;
F_30 ( V_77 , V_86 , V_59 , * V_28 ) ;
( * V_90 ) += V_59 ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_78 * V_79 , * V_80 ;
struct V_76 V_77 ;
int V_86 = 0 ;
T_1 V_28 , V_91 = 0 ;
T_2 V_92 , V_90 ;
struct V_19 * V_21 ;
struct V_57 * V_58 ;
V_14 -> V_21 = F_33 ( V_16 -> V_93 , V_94 , & V_14 -> V_52 ) ;
if ( ! V_14 -> V_21 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_4 , V_95 ) ;
return 0 ;
}
V_16 -> V_96 ++ ;
V_77 . V_14 = V_14 ;
V_77 . V_88 = ( V_16 -> V_97 & V_98 ) ? V_51 : 0 ;
V_28 = V_14 -> V_28 ;
V_77 . V_83 . V_99 =
F_26 ( ( V_28 & V_73 ) >>
V_44 ) ;
V_77 . V_82 . V_99 =
F_26 ( ( V_28 & V_72 ) >>
V_74 ) ;
F_20 (dsg, &txd->dsg_list, node) {
V_90 = 0 ;
V_28 = V_14 -> V_28 ;
V_77 . V_83 . V_87 = V_58 -> V_100 ;
V_77 . V_82 . V_87 = V_58 -> V_101 ;
V_77 . V_89 = V_58 -> V_59 ;
V_77 . V_83 . V_85 = V_77 . V_83 . V_99 ;
V_77 . V_82 . V_85 = V_77 . V_82 . V_99 ;
F_29 ( & V_77 , & V_79 , & V_80 , V_28 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_5 ,
V_77 . V_83 . V_87 , V_28 & V_84 ? L_6 : L_7 ,
V_77 . V_83 . V_85 ,
V_77 . V_82 . V_87 , V_28 & V_81 ? L_6 : L_7 ,
V_77 . V_82 . V_85 ,
V_77 . V_89 ) ;
F_8 ( & V_16 -> V_23 -> V_24 , L_8 ,
V_79 == & V_77 . V_83 ? L_9 : L_10 ,
V_80 == & V_77 . V_83 ? L_9 : L_10 ) ;
if ( ! V_77 . V_89 ) {
T_1 V_102 = ( V_14 -> V_29 & V_103 ) >>
V_104 ;
if ( ! ( ( V_102 >= V_105 ) &&
( V_102 <= V_106 ) ) ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_11 ,
V_95 ) ;
return 0 ;
}
if ( ( V_77 . V_83 . V_87 % V_77 . V_83 . V_85 ) ||
( V_77 . V_82 . V_87 % V_77 . V_82 . V_85 ) ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_12
L_13 ,
V_95 ) ;
return 0 ;
}
V_28 = F_28 ( V_28 , V_77 . V_83 . V_85 ,
V_77 . V_82 . V_85 , 0 ) ;
F_30 ( & V_77 , V_86 ++ , 0 , V_28 ) ;
break;
}
if ( V_77 . V_89 < V_79 -> V_85 )
V_91 = V_77 . V_89 ;
else if ( ( V_79 -> V_87 ) % ( V_79 -> V_85 ) ) {
V_91 = V_79 -> V_85 - ( V_79 -> V_87 ) %
( V_79 -> V_85 ) ;
if ( ( V_77 . V_89 - V_91 ) < V_79 -> V_85 )
V_91 = V_77 . V_89 ;
}
if ( V_91 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_14 ,
V_95 , V_77 . V_89 ) ;
F_31 ( & V_77 , & V_28 , V_91 , V_86 ++ ,
& V_90 ) ;
}
if ( V_77 . V_89 ) {
if ( V_80 -> V_87 % V_80 -> V_85 ) {
F_35 ( & V_16 -> V_23 -> V_24 ,
L_15 ,
V_95 ) ;
V_80 -> V_85 = 1 ;
}
V_92 = V_77 . V_83 . V_85 *
V_43 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_16 ,
V_95 , V_92 ) ;
while ( V_77 . V_89 > ( V_79 -> V_85 - 1 ) ) {
T_2 V_107 , V_70 , V_108 ;
V_107 = F_36 ( V_77 . V_89 , V_92 ) ;
V_108 = F_37 ( V_79 -> V_85 , V_80 -> V_85 ) ;
V_107 = ( V_107 / V_108 ) * V_108 ;
V_70 = V_107 / V_77 . V_83 . V_85 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_17
L_18 ,
V_95 , V_107 , V_77 . V_89 ) ;
V_28 = F_28 ( V_28 , V_77 . V_83 . V_85 ,
V_77 . V_82 . V_85 , V_70 ) ;
F_30 ( & V_77 , V_86 ++ ,
V_107 , V_28 ) ;
V_90 += V_107 ;
}
if ( V_77 . V_89 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_19 ,
V_95 , V_77 . V_89 ) ;
F_31 ( & V_77 , & V_28 , V_77 . V_89 ,
V_86 ++ , & V_90 ) ;
}
}
if ( V_90 != V_58 -> V_59 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_20 ,
V_95 , V_90 , V_58 -> V_59 ) ;
return 0 ;
}
if ( V_86 >= V_54 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_21 ,
V_95 , ( T_1 ) V_54 ) ;
return 0 ;
}
}
V_21 = V_14 -> V_21 ;
V_21 [ V_86 - 1 ] . V_20 = 0 ;
V_21 [ V_86 - 1 ] . V_28 |= V_109 ;
#ifdef F_38
{
int V_61 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_22 ,
L_23 , L_7 , L_24 , L_25 , L_26 , L_27 ) ;
for ( V_61 = 0 ; V_61 < V_86 ; V_61 ++ ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_28 ,
V_61 , & V_21 [ V_61 ] , V_21 [ V_61 ] . V_26 ,
V_21 [ V_61 ] . V_27 , V_21 [ V_61 ] . V_20 , V_21 [ V_61 ] . V_28
) ;
}
}
#endif
return V_86 ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_57 * V_58 , * V_110 ;
if ( V_14 -> V_21 )
F_40 ( V_16 -> V_93 , V_14 -> V_21 , V_14 -> V_52 ) ;
V_16 -> V_96 -- ;
F_41 (dsg, _dsg, &txd->dsg_list, node) {
F_42 ( & V_58 -> V_111 ) ;
F_43 ( V_58 ) ;
}
F_43 ( V_14 ) ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_1 * V_13 )
{
struct V_4 * V_56 = NULL ;
struct V_4 * V_112 ;
if ( ! F_19 ( & V_13 -> V_55 ) ) {
F_41 (txdi,
next, &plchan->pend_list, node) {
F_42 ( & V_56 -> V_111 ) ;
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
int V_113 ;
if ( V_13 -> V_18 ) {
V_8 = V_13 -> V_18 ;
goto V_114;
}
V_8 = F_22 ( V_16 , V_13 ) ;
if ( ! V_8 ) {
F_35 ( & V_16 -> V_23 -> V_24 , L_29 , V_13 -> V_115 ) ;
return - V_116 ;
}
if ( V_13 -> V_117 && V_16 -> V_118 -> V_119 ) {
V_113 = V_16 -> V_118 -> V_119 ( V_13 ) ;
if ( V_113 < 0 ) {
F_35 ( & V_16 -> V_23 -> V_24 ,
L_30 ,
V_8 -> V_25 , V_13 -> V_115 ) ;
F_24 ( V_16 , V_8 ) ;
return - V_116 ;
}
V_8 -> signal = V_113 ;
}
V_13 -> V_18 = V_8 ;
F_35 ( & V_16 -> V_23 -> V_24 , L_31 ,
V_8 -> V_25 ,
V_8 -> signal ,
V_13 -> V_115 ) ;
V_114:
if ( V_14 -> V_120 == V_121 )
V_14 -> V_29 |= V_8 -> signal << V_122 ;
else if ( V_14 -> V_120 == V_123 )
V_14 -> V_29 |= V_8 -> signal << V_124 ;
V_13 -> V_125 ++ ;
return 0 ;
}
static void F_48 ( struct V_1 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( ( V_13 -> V_18 -> signal >= 0 ) && V_16 -> V_118 -> V_126 ) {
V_16 -> V_118 -> V_126 ( V_13 ) ;
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
T_5 V_127 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_127 = F_50 ( V_6 ) ;
F_51 ( & V_14 -> V_111 , & V_13 -> V_55 ) ;
if ( ! V_13 -> V_117 && ! V_13 -> V_18 ) {
V_13 -> V_128 = V_129 ;
V_13 -> V_130 = V_14 ;
} else {
V_13 -> V_125 -- ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_127 ;
}
static struct V_5 * F_52 (
struct V_2 * V_3 , unsigned long V_48 )
{
struct V_5 * V_131 = NULL ;
return V_131 ;
}
static enum V_132 F_53 ( struct V_2 * V_3 ,
T_5 V_127 , struct V_133 * V_134 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
enum V_132 V_113 ;
V_113 = F_54 ( V_3 , V_127 , V_134 ) ;
if ( V_113 == V_135 )
return V_113 ;
F_55 ( V_134 , F_16 ( V_13 ) ) ;
if ( V_13 -> V_128 == V_136 )
return V_137 ;
return V_138 ;
}
static T_1 F_56 ( T_4 V_26 , T_4 V_27 )
{
T_1 V_28 = 0 ;
if ( ! ( V_27 & V_139 ) || ( ( V_27 & V_98 ) && ( V_26 & V_139 ) ) )
V_28 |= V_140 ;
if ( ! ( V_26 & V_139 ) || ( ( V_26 & V_98 ) && ! ( V_27 & V_98 ) ) )
V_28 |= V_141 ;
return V_28 ;
}
static T_1 F_57 ( T_1 V_28 )
{
V_28 &= ~ ( V_141 | V_140 |
V_84 | V_81 |
V_142 ) ;
return V_28 | V_143 ;
}
static T_1 F_58 ( enum V_144 V_108 )
{
switch ( V_108 ) {
case V_145 :
return V_45 ;
case V_146 :
return V_46 ;
case V_147 :
return V_47 ;
default:
return ~ 0 ;
}
}
static T_1 F_59 ( T_1 V_148 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_60 ( V_149 ) ; V_61 ++ )
if ( V_149 [ V_61 ] . V_150 <= V_148 )
break;
return V_149 [ V_61 ] . V_151 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_152 * V_153 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
enum V_144 V_154 ;
T_1 V_108 , V_155 , V_148 ;
T_1 V_28 = 0 ;
if ( ! V_13 -> V_117 )
return - V_156 ;
V_13 -> V_157 = V_153 -> V_120 ;
if ( V_153 -> V_120 == V_121 ) {
V_154 = V_153 -> V_158 ;
V_148 = V_153 -> V_159 ;
} else if ( V_153 -> V_120 == V_123 ) {
V_154 = V_153 -> V_160 ;
V_148 = V_153 -> V_161 ;
} else {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_32 ) ;
return - V_156 ;
}
V_108 = F_58 ( V_154 ) ;
if ( V_108 == ~ 0 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_33 ) ;
return - V_156 ;
}
V_28 |= V_108 << V_44 ;
V_28 |= V_108 << V_74 ;
if ( V_13 -> V_162 -> V_163 )
V_148 = 1 ;
V_155 = F_59 ( V_148 ) ;
V_28 |= V_155 << V_164 ;
V_28 |= V_155 << V_165 ;
V_13 -> V_166 = V_153 -> V_166 ;
if ( V_13 -> V_157 == V_123 ) {
V_13 -> V_100 = V_153 -> V_100 ;
V_13 -> V_167 = F_57 ( V_28 ) | V_81 |
F_56 ( V_13 -> V_162 -> V_168 ,
V_16 -> V_169 ) ;
} else {
V_13 -> V_101 = V_153 -> V_101 ;
V_13 -> V_170 = F_57 ( V_28 ) | V_84 |
F_56 ( V_16 -> V_169 ,
V_13 -> V_162 -> V_168 ) ;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_34
L_35 ,
F_62 ( V_3 ) , V_13 -> V_115 ,
( V_153 -> V_120 == V_123 ) ? L_36 : L_37 ,
V_154 ,
V_148 ,
V_28 ) ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( V_13 -> V_22 || V_13 -> V_128 == V_129 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_112 ;
V_112 = F_64 ( & V_13 -> V_55 ,
struct V_4 ,
V_111 ) ;
F_42 ( & V_112 -> V_111 ) ;
V_13 -> V_128 = V_171 ;
F_6 ( V_13 , V_112 ) ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
}
static int F_65 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_86 , V_113 ;
V_86 = F_32 ( V_16 , V_14 ) ;
if ( ! V_86 ) {
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_156 ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_113 = F_47 ( V_13 , V_14 ) ;
if ( V_113 ) {
if ( V_13 -> V_117 ) {
F_44 ( V_16 , V_13 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_116 ;
}
} else
if ( V_13 -> V_128 == V_172 )
V_13 -> V_128 = V_136 ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
static struct V_4 * F_66 ( struct V_1 * V_13 ,
unsigned long V_48 )
{
struct V_4 * V_14 = F_67 ( sizeof( * V_14 ) , V_94 ) ;
if ( V_14 ) {
F_68 ( & V_14 -> V_6 , & V_13 -> V_3 ) ;
V_14 -> V_6 . V_48 = V_48 ;
V_14 -> V_6 . V_173 = F_49 ;
F_69 ( & V_14 -> V_111 ) ;
F_69 ( & V_14 -> V_174 ) ;
V_14 -> V_29 = V_38 |
V_39 ;
}
return V_14 ;
}
static struct V_5 * F_70 (
struct V_2 * V_3 , T_3 V_175 , T_3 V_26 ,
T_2 V_59 , unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
struct V_57 * V_58 ;
int V_113 ;
V_14 = F_66 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_38 , V_95 ) ;
return NULL ;
}
V_58 = F_67 ( sizeof( struct V_57 ) , V_94 ) ;
if ( ! V_58 ) {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 , L_39 ,
V_95 ) ;
return NULL ;
}
F_51 ( & V_58 -> V_111 , & V_14 -> V_174 ) ;
V_14 -> V_120 = V_176 ;
V_58 -> V_100 = V_26 ;
V_58 -> V_101 = V_175 ;
V_58 -> V_59 = V_59 ;
V_14 -> V_29 |= V_177 << V_104 ;
V_14 -> V_28 = V_16 -> V_118 -> V_178 . V_28 &
~ ( V_140 | V_141 ) ;
V_14 -> V_28 |= V_84 | V_81 ;
if ( V_16 -> V_62 -> V_179 )
V_14 -> V_28 |= F_56 ( V_16 -> V_169 ,
V_16 -> V_169 ) ;
V_113 = F_65 ( V_13 , V_14 ) ;
if ( V_113 )
return NULL ;
return & V_14 -> V_6 ;
}
static struct V_5 * F_71 (
struct V_2 * V_3 , struct V_180 * V_181 ,
unsigned int V_182 , enum V_183 V_120 ,
unsigned long V_48 , void * V_184 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
struct V_57 * V_58 ;
struct V_180 * V_185 ;
T_3 V_186 ;
int V_113 , V_187 ;
F_35 ( & V_16 -> V_23 -> V_24 , L_40 ,
V_95 , F_72 ( V_181 ) , V_13 -> V_115 ) ;
V_14 = F_66 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_41 , V_95 ) ;
return NULL ;
}
if ( V_120 != V_13 -> V_157 )
F_34 ( & V_16 -> V_23 -> V_24 , L_42
L_43 ,
V_95 ) ;
V_14 -> V_120 = V_120 ;
if ( V_120 == V_121 ) {
V_14 -> V_28 = V_13 -> V_170 ;
V_186 = V_13 -> V_101 ;
} else if ( V_120 == V_123 ) {
V_14 -> V_28 = V_13 -> V_167 ;
V_186 = V_13 -> V_100 ;
} else {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 ,
L_44 , V_95 ) ;
return NULL ;
}
if ( V_13 -> V_166 )
V_187 = ( V_120 == V_121 ) ? V_188 :
V_189 ;
else
V_187 = ( V_120 == V_121 ) ? V_190 :
V_191 ;
V_14 -> V_29 |= V_187 << V_104 ;
F_73 (sgl, sg, sg_len, tmp) {
V_58 = F_67 ( sizeof( struct V_57 ) , V_94 ) ;
if ( ! V_58 ) {
F_39 ( V_16 , V_14 ) ;
F_34 ( & V_16 -> V_23 -> V_24 , L_45 ,
V_95 ) ;
return NULL ;
}
F_51 ( & V_58 -> V_111 , & V_14 -> V_174 ) ;
V_58 -> V_59 = F_72 ( V_185 ) ;
if ( V_120 == V_121 ) {
V_58 -> V_100 = F_74 ( V_185 ) ;
V_58 -> V_101 = V_186 ;
} else {
V_58 -> V_100 = V_186 ;
V_58 -> V_101 = F_74 ( V_185 ) ;
}
}
V_113 = F_65 ( V_13 , V_14 ) ;
if ( V_113 )
return NULL ;
return & V_14 -> V_6 ;
}
static int F_75 ( struct V_2 * V_3 , enum V_192 V_193 ,
unsigned long V_194 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_113 = 0 ;
if ( V_193 == V_195 ) {
return F_61 ( V_3 ,
(struct V_152 * ) V_194 ) ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( ! V_13 -> V_18 && ! V_13 -> V_22 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
switch ( V_193 ) {
case V_196 :
V_13 -> V_128 = V_172 ;
if ( V_13 -> V_18 ) {
F_14 ( V_16 , V_13 -> V_18 ) ;
F_48 ( V_13 ) ;
V_13 -> V_125 = 0 ;
}
if ( V_13 -> V_22 ) {
F_39 ( V_16 , V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
}
F_44 ( V_16 , V_13 ) ;
break;
case V_197 :
F_10 ( V_13 -> V_18 ) ;
V_13 -> V_128 = V_136 ;
break;
case V_198 :
F_13 ( V_13 -> V_18 ) ;
V_13 -> V_128 = V_171 ;
break;
default:
V_113 = - V_199 ;
break;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_113 ;
}
bool F_76 ( struct V_2 * V_3 , void * V_200 )
{
struct V_1 * V_13 ;
char * V_115 = V_200 ;
if ( V_3 -> V_201 -> V_24 -> V_202 != & V_203 . V_204 )
return false ;
V_13 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_13 -> V_115 , V_115 ) )
return true ;
return false ;
}
static void F_77 ( struct V_15 * V_16 )
{
if ( V_16 -> V_62 -> V_205 )
return;
F_9 ( V_35 , V_16 -> V_10 + V_206 ) ;
}
static void F_78 ( struct V_4 * V_14 )
{
struct V_201 * V_24 = V_14 -> V_6 . V_3 -> V_201 -> V_24 ;
struct V_57 * V_58 ;
if ( ! ( V_14 -> V_6 . V_48 & V_207 ) ) {
if ( V_14 -> V_6 . V_48 & V_208 )
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_209 ) ;
else {
F_20 (dsg, &txd->dsg_list, node)
F_80 ( V_24 , V_58 -> V_100 , V_58 -> V_59 ,
V_209 ) ;
}
}
if ( ! ( V_14 -> V_6 . V_48 & V_210 ) ) {
if ( V_14 -> V_6 . V_48 & V_211 )
F_20 (dsg, &txd->dsg_list, node)
F_79 ( V_24 , V_58 -> V_101 , V_58 -> V_59 ,
V_212 ) ;
else
F_20 (dsg, &txd->dsg_list, node)
F_80 ( V_24 , V_58 -> V_101 , V_58 -> V_59 ,
V_212 ) ;
}
}
static void F_81 ( unsigned long V_213 )
{
struct V_1 * V_13 = (struct V_1 * ) V_213 ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_14 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
if ( V_14 ) {
F_82 ( & V_14 -> V_6 ) ;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_112 ;
V_112 = F_64 ( & V_13 -> V_55 ,
struct V_4 ,
V_111 ) ;
F_42 ( & V_112 -> V_111 ) ;
F_6 ( V_13 , V_112 ) ;
} else if ( V_13 -> V_125 ) {
} else {
struct V_1 * V_130 = NULL ;
F_48 ( V_13 ) ;
V_13 -> V_128 = V_172 ;
F_20 (waiting, &pl08x->memcpy.channels,
chan.device_node) {
if ( V_130 -> V_128 == V_129 &&
V_130 -> V_130 != NULL ) {
int V_113 ;
V_113 = F_47 ( V_130 ,
V_130 -> V_130 ) ;
F_18 ( V_113 ) ;
V_130 -> V_125 -- ;
V_130 -> V_128 = V_171 ;
V_130 -> V_130 = NULL ;
F_63 ( & V_130 -> V_3 ) ;
break;
}
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_14 ) {
T_6 V_214 = V_14 -> V_6 . V_214 ;
void * V_215 = V_14 -> V_6 . V_215 ;
if ( ! V_13 -> V_117 )
F_78 ( V_14 ) ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_39 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_214 )
V_214 ( V_215 ) ;
}
}
static T_7 F_83 ( int V_216 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
T_1 V_217 = 0 , V_218 , V_219 , V_61 ;
V_218 = F_5 ( V_16 -> V_10 + V_220 ) ;
if ( V_218 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_46 ,
V_95 , V_218 ) ;
F_9 ( V_218 , V_16 -> V_10 + V_40 ) ;
}
V_219 = F_5 ( V_16 -> V_10 + V_221 ) ;
if ( V_219 )
F_9 ( V_219 , V_16 -> V_10 + V_41 ) ;
if ( ! V_218 && ! V_219 )
return V_222 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
if ( ( ( 1 << V_61 ) & V_218 ) || ( ( 1 << V_61 ) & V_219 ) ) {
struct V_7 * V_18 = & V_16 -> V_64 [ V_61 ] ;
struct V_1 * V_13 = V_18 -> V_66 ;
if ( ! V_13 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_47 ,
V_95 , V_61 ) ;
continue;
}
F_84 ( & V_13 -> V_223 ) ;
V_217 |= ( 1 << V_61 ) ;
}
}
return V_217 ? V_224 : V_222 ;
}
static void F_85 ( struct V_1 * V_3 )
{
T_1 V_28 = F_57 ( V_3 -> V_162 -> V_28 ) ;
V_3 -> V_117 = true ;
V_3 -> V_115 = V_3 -> V_162 -> V_225 ;
V_3 -> V_100 = V_3 -> V_162 -> V_87 ;
V_3 -> V_101 = V_3 -> V_162 -> V_87 ;
V_3 -> V_167 = V_28 | V_81 |
F_56 ( V_3 -> V_162 -> V_168 , V_3 -> V_17 -> V_169 ) ;
V_3 -> V_170 = V_28 | V_84 |
F_56 ( V_3 -> V_17 -> V_169 , V_3 -> V_162 -> V_168 ) ;
}
static int F_86 ( struct V_15 * V_16 ,
struct V_226 * V_227 , unsigned int V_63 , bool V_117 )
{
struct V_1 * V_3 ;
int V_61 ;
F_69 ( & V_227 -> V_63 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_3 = F_67 ( sizeof( * V_3 ) , V_228 ) ;
if ( ! V_3 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_48 , V_95 ) ;
return - V_229 ;
}
V_3 -> V_17 = V_16 ;
V_3 -> V_128 = V_172 ;
if ( V_117 ) {
V_3 -> V_162 = & V_16 -> V_118 -> V_230 [ V_61 ] ;
F_85 ( V_3 ) ;
} else {
V_3 -> V_162 = & V_16 -> V_118 -> V_178 ;
V_3 -> V_115 = F_87 ( V_228 , L_49 , V_61 ) ;
if ( ! V_3 -> V_115 ) {
F_43 ( V_3 ) ;
return - V_229 ;
}
}
if ( V_3 -> V_162 -> V_231 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_50 ,
V_3 -> V_115 ) ;
F_43 ( V_3 ) ;
continue;
}
F_35 ( & V_16 -> V_23 -> V_24 ,
L_51 ,
V_3 -> V_115 ) ;
V_3 -> V_3 . V_201 = V_227 ;
F_88 ( & V_3 -> V_3 ) ;
F_89 ( & V_3 -> V_49 ) ;
F_69 ( & V_3 -> V_55 ) ;
F_90 ( & V_3 -> V_223 , F_81 ,
( unsigned long ) V_3 ) ;
F_51 ( & V_3 -> V_3 . V_232 , & V_227 -> V_63 ) ;
}
F_91 ( & V_16 -> V_23 -> V_24 , L_52 ,
V_61 , V_117 ? L_53 : L_54 ) ;
return V_61 ;
}
static void F_92 ( struct V_226 * V_227 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_112 ;
F_41 (chan,
next, &dmadev->channels, chan.device_node) {
F_42 ( & V_3 -> V_3 . V_232 ) ;
F_43 ( V_3 ) ;
}
}
static const char * F_93 ( enum V_233 V_128 )
{
switch ( V_128 ) {
case V_172 :
return L_55 ;
case V_171 :
return L_56 ;
case V_136 :
return L_57 ;
case V_129 :
return L_58 ;
default:
break;
}
return L_59 ;
}
static int F_94 ( struct V_234 * V_235 , void * V_213 )
{
struct V_15 * V_16 = V_235 -> V_236 ;
struct V_1 * V_3 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
int V_61 ;
F_95 ( V_235 , L_60 ) ;
F_95 ( V_235 , L_61 ) ;
F_95 ( V_235 , L_62 ) ;
for ( V_61 = 0 ; V_61 < V_16 -> V_62 -> V_63 ; V_61 ++ ) {
struct V_1 * V_60 ;
V_8 = & V_16 -> V_64 [ V_61 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
V_60 = V_8 -> V_66 ;
F_95 ( V_235 , L_63 ,
V_8 -> V_25 ,
V_60 ? V_60 -> V_115 : L_64 ,
V_8 -> V_65 ? L_65 : L_7 ) ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
F_95 ( V_235 , L_66 ) ;
F_95 ( V_235 , L_67 ) ;
F_95 ( V_235 , L_68 ) ;
F_20 (chan, &pl08x->memcpy.channels, chan.device_node) {
F_95 ( V_235 , L_69 , V_3 -> V_115 ,
F_93 ( V_3 -> V_128 ) ) ;
}
F_95 ( V_235 , L_70 ) ;
F_95 ( V_235 , L_67 ) ;
F_95 ( V_235 , L_68 ) ;
F_20 (chan, &pl08x->slave.channels, chan.device_node) {
F_95 ( V_235 , L_69 , V_3 -> V_115 ,
F_93 ( V_3 -> V_128 ) ) ;
}
return 0 ;
}
static int F_96 ( struct V_237 * V_237 , struct V_238 * V_238 )
{
return F_97 ( V_238 , F_94 , V_237 -> V_239 ) ;
}
static void F_98 ( struct V_15 * V_16 )
{
( void ) F_99 ( F_100 ( & V_16 -> V_23 -> V_24 ) ,
V_240 | V_241 , NULL , V_16 ,
& V_242 ) ;
}
static inline void F_98 ( struct V_15 * V_16 )
{
}
static int F_101 ( struct V_243 * V_23 , const struct V_244 * V_25 )
{
struct V_15 * V_16 ;
const struct V_245 * V_62 = V_25 -> V_213 ;
int V_113 = 0 ;
int V_61 ;
V_113 = F_102 ( V_23 , NULL ) ;
if ( V_113 )
return V_113 ;
V_16 = F_67 ( sizeof( * V_16 ) , V_228 ) ;
if ( ! V_16 ) {
V_113 = - V_229 ;
goto V_246;
}
F_103 ( & V_23 -> V_24 ) ;
F_104 ( & V_23 -> V_24 ) ;
F_105 ( V_247 , V_16 -> memcpy . V_248 ) ;
V_16 -> memcpy . V_24 = & V_23 -> V_24 ;
V_16 -> memcpy . V_249 = F_45 ;
V_16 -> memcpy . V_250 = F_46 ;
V_16 -> memcpy . V_251 = F_70 ;
V_16 -> memcpy . V_252 = F_52 ;
V_16 -> memcpy . V_253 = F_53 ;
V_16 -> memcpy . V_254 = F_63 ;
V_16 -> memcpy . V_255 = F_75 ;
F_105 ( V_256 , V_16 -> V_117 . V_248 ) ;
V_16 -> V_117 . V_24 = & V_23 -> V_24 ;
V_16 -> V_117 . V_249 = F_45 ;
V_16 -> V_117 . V_250 = F_46 ;
V_16 -> V_117 . V_252 = F_52 ;
V_16 -> V_117 . V_253 = F_53 ;
V_16 -> V_117 . V_254 = F_63 ;
V_16 -> V_117 . V_257 = F_71 ;
V_16 -> V_117 . V_255 = F_75 ;
V_16 -> V_118 = F_106 ( & V_23 -> V_24 ) ;
if ( ! V_16 -> V_118 ) {
F_34 ( & V_23 -> V_24 , L_71 ) ;
goto V_258;
}
V_16 -> V_23 = V_23 ;
V_16 -> V_62 = V_62 ;
V_16 -> V_97 = V_139 ;
V_16 -> V_169 = V_139 ;
if ( V_16 -> V_62 -> V_179 ) {
V_16 -> V_97 = V_16 -> V_118 -> V_97 ;
V_16 -> V_169 = V_16 -> V_118 -> V_169 ;
}
V_16 -> V_93 = F_107 ( V_259 , & V_16 -> V_23 -> V_24 ,
V_260 , V_261 , 0 ) ;
if ( ! V_16 -> V_93 ) {
V_113 = - V_229 ;
goto V_262;
}
F_89 ( & V_16 -> V_49 ) ;
V_16 -> V_10 = F_108 ( V_23 -> V_263 . V_264 , F_109 ( & V_23 -> V_263 ) ) ;
if ( ! V_16 -> V_10 ) {
V_113 = - V_229 ;
goto V_265;
}
F_77 ( V_16 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_41 ) ;
V_113 = F_110 ( V_23 -> V_216 [ 0 ] , F_83 , V_266 ,
V_259 , V_16 ) ;
if ( V_113 ) {
F_34 ( & V_23 -> V_24 , L_72 ,
V_95 , V_23 -> V_216 [ 0 ] ) ;
goto V_267;
}
V_16 -> V_64 = F_67 ( ( V_62 -> V_63 * sizeof( * V_16 -> V_64 ) ) ,
V_228 ) ;
if ( ! V_16 -> V_64 ) {
F_34 ( & V_23 -> V_24 , L_73
L_74 ,
V_95 ) ;
goto V_268;
}
for ( V_61 = 0 ; V_61 < V_62 -> V_63 ; V_61 ++ ) {
struct V_7 * V_8 = & V_16 -> V_64 [ V_61 ] ;
V_8 -> V_25 = V_61 ;
V_8 -> V_10 = V_16 -> V_10 + F_111 ( V_61 ) ;
F_89 ( & V_8 -> V_49 ) ;
V_8 -> signal = - 1 ;
if ( V_62 -> V_205 ) {
T_1 V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
if ( V_9 & ( V_269 | V_270 ) ) {
F_91 ( & V_23 -> V_24 , L_75 , V_61 ) ;
V_8 -> V_65 = true ;
}
}
F_35 ( & V_23 -> V_24 , L_76 ,
V_61 , F_4 ( V_8 ) ? L_77 : L_78 ) ;
}
V_113 = F_86 ( V_16 , & V_16 -> memcpy ,
V_16 -> V_62 -> V_63 , false ) ;
if ( V_113 <= 0 ) {
F_112 ( & V_16 -> V_23 -> V_24 ,
L_79 ,
V_95 , V_113 ) ;
goto V_271;
}
V_16 -> memcpy . V_272 = V_113 ;
V_113 = F_86 ( V_16 , & V_16 -> V_117 ,
V_16 -> V_118 -> V_273 , true ) ;
if ( V_113 <= 0 ) {
F_112 ( & V_16 -> V_23 -> V_24 ,
L_80 ,
V_95 , V_113 ) ;
goto V_274;
}
V_16 -> V_117 . V_272 = V_113 ;
V_113 = F_113 ( & V_16 -> memcpy ) ;
if ( V_113 ) {
F_112 ( & V_16 -> V_23 -> V_24 ,
L_81 ,
V_95 , V_113 ) ;
goto V_275;
}
V_113 = F_113 ( & V_16 -> V_117 ) ;
if ( V_113 ) {
F_112 ( & V_16 -> V_23 -> V_24 ,
L_82 ,
V_95 , V_113 ) ;
goto V_276;
}
F_114 ( V_23 , V_16 ) ;
F_98 ( V_16 ) ;
F_91 ( & V_16 -> V_23 -> V_24 , L_83 ,
F_115 ( V_23 ) , F_116 ( V_23 ) ,
( unsigned long long ) V_23 -> V_263 . V_264 , V_23 -> V_216 [ 0 ] ) ;
F_25 ( & V_23 -> V_24 ) ;
return 0 ;
V_276:
F_117 ( & V_16 -> memcpy ) ;
V_275:
F_92 ( & V_16 -> V_117 ) ;
V_274:
F_92 ( & V_16 -> memcpy ) ;
V_271:
F_43 ( V_16 -> V_64 ) ;
V_268:
F_118 ( V_23 -> V_216 [ 0 ] , V_16 ) ;
V_267:
F_119 ( V_16 -> V_10 ) ;
V_265:
F_120 ( V_16 -> V_93 ) ;
V_262:
V_258:
F_25 ( & V_23 -> V_24 ) ;
F_121 ( & V_23 -> V_24 ) ;
F_43 ( V_16 ) ;
V_246:
F_122 ( V_23 ) ;
return V_113 ;
}
static int T_8 F_123 ( void )
{
int V_131 ;
V_131 = F_124 ( & V_203 ) ;
if ( V_131 )
F_125 (KERN_WARNING DRIVER_NAME
L_84 ,
retval) ;
return V_131 ;
}
