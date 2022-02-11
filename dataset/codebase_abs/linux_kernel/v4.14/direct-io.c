static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 -> V_7 , V_5 -> V_8 , V_9 , V_10 ,
& V_2 -> V_11 ) ;
if ( V_6 < 0 && V_2 -> V_12 && ( V_5 -> V_13 == V_14 ) ) {
struct V_15 * V_15 = F_4 ( 0 ) ;
if ( V_5 -> V_16 == 0 )
V_5 -> V_16 = V_6 ;
F_5 ( V_15 ) ;
V_5 -> V_8 [ 0 ] = V_15 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = 1 ;
V_2 -> V_11 = 0 ;
V_2 -> V_17 = V_18 ;
return 0 ;
}
if ( V_6 >= 0 ) {
F_6 ( V_2 -> V_7 , V_6 ) ;
V_6 += V_2 -> V_11 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = ( V_6 + V_18 - 1 ) / V_18 ;
V_2 -> V_17 = ( ( V_6 - 1 ) & ( V_18 - 1 ) ) + 1 ;
return 0 ;
}
return V_6 ;
}
static inline struct V_15 * F_7 ( struct V_5 * V_5 ,
struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) == 0 ) {
int V_6 ;
V_6 = F_2 ( V_5 , V_2 ) ;
if ( V_6 )
return F_8 ( V_6 ) ;
F_9 ( F_1 ( V_2 ) == 0 ) ;
}
return V_5 -> V_8 [ V_2 -> V_4 ] ;
}
static T_1 F_10 ( struct V_5 * V_5 , T_1 V_6 , unsigned int V_19 )
{
T_2 V_20 = V_5 -> V_21 -> V_22 ;
T_1 V_23 = 0 ;
int V_24 ;
if ( V_6 == - V_25 )
V_6 = 0 ;
if ( V_5 -> V_26 ) {
V_23 = V_5 -> V_26 ;
if ( ( V_5 -> V_13 == V_27 ) &&
( ( V_20 + V_23 ) > V_5 -> V_28 ) )
V_23 = V_5 -> V_28 - V_20 ;
if ( F_11 ( V_6 == - V_29 ) && V_23 )
V_6 = 0 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_30 ;
if ( V_6 == 0 )
V_6 = V_23 ;
if ( V_5 -> V_31 ) {
V_24 = V_5 -> V_31 ( V_5 -> V_21 , V_20 , V_6 , V_5 -> V_32 ) ;
if ( V_24 )
V_6 = V_24 ;
}
if ( V_19 & V_33 &&
V_6 > 0 && V_5 -> V_13 == V_14 &&
V_5 -> V_34 -> V_35 -> V_36 ) {
V_24 = F_12 ( V_5 -> V_34 -> V_35 ,
V_20 >> V_37 ,
( V_20 + V_6 - 1 ) >> V_37 ) ;
F_13 ( V_24 ) ;
}
if ( ! ( V_5 -> V_19 & V_38 ) )
F_14 ( V_5 -> V_34 ) ;
if ( V_19 & V_39 ) {
V_5 -> V_21 -> V_22 += V_23 ;
if ( V_5 -> V_13 == V_14 )
V_6 = F_15 ( V_5 -> V_21 , V_23 ) ;
V_5 -> V_21 -> V_40 ( V_5 -> V_21 , V_6 , 0 ) ;
}
F_16 ( V_41 , V_5 ) ;
return V_6 ;
}
static void F_17 ( struct V_42 * V_43 )
{
struct V_5 * V_5 = F_18 ( V_43 , struct V_5 , V_44 ) ;
F_10 ( V_5 , 0 , V_39 | V_33 ) ;
}
static void F_19 ( struct V_45 * V_45 )
{
struct V_5 * V_5 = V_45 -> V_46 ;
unsigned long V_47 ;
unsigned long V_19 ;
bool V_48 = false ;
F_20 ( V_5 , V_45 ) ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_47 = -- V_5 -> V_50 ;
if ( V_47 == 1 && V_5 -> V_51 )
F_22 ( V_5 -> V_51 ) ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
if ( V_47 == 0 ) {
if ( V_5 -> V_26 )
V_48 = V_5 -> V_48 ||
( V_5 -> V_13 == V_14 &&
V_5 -> V_34 -> V_35 -> V_36 ) ;
if ( V_48 ) {
F_24 ( & V_5 -> V_44 , F_17 ) ;
F_25 ( V_5 -> V_34 -> V_52 -> V_53 ,
& V_5 -> V_44 ) ;
} else {
F_10 ( V_5 , 0 , V_39 ) ;
}
}
}
static void F_26 ( struct V_45 * V_45 )
{
struct V_5 * V_5 = V_45 -> V_46 ;
unsigned long V_19 ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_45 -> V_46 = V_5 -> V_54 ;
V_5 -> V_54 = V_45 ;
if ( -- V_5 -> V_50 == 1 && V_5 -> V_51 )
F_22 ( V_5 -> V_51 ) ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
}
void F_27 ( struct V_45 * V_45 )
{
struct V_5 * V_5 = V_45 -> V_46 ;
if ( V_5 -> V_55 )
F_19 ( V_45 ) ;
else
F_26 ( V_45 ) ;
}
static inline void
F_28 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_56 * V_57 ,
T_3 V_58 , int V_59 )
{
struct V_45 * V_45 ;
V_45 = F_29 ( V_60 , V_59 ) ;
F_30 ( V_45 , V_57 ) ;
V_45 -> V_61 . V_62 = V_58 ;
F_31 ( V_45 , V_5 -> V_13 , V_5 -> V_63 ) ;
if ( V_5 -> V_55 )
V_45 -> V_64 = F_19 ;
else
V_45 -> V_64 = F_26 ;
V_45 -> V_65 = V_5 -> V_21 -> V_66 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_67 = V_2 -> V_68 ;
}
static inline void F_32 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_45 * V_45 = V_2 -> V_45 ;
unsigned long V_19 ;
V_45 -> V_46 = V_5 ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_5 -> V_50 ++ ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
if ( V_5 -> V_55 && V_5 -> V_13 == V_27 && V_5 -> V_69 )
F_33 ( V_45 ) ;
V_5 -> V_70 = V_45 -> V_71 ;
if ( V_2 -> V_72 ) {
V_2 -> V_72 ( V_45 , V_5 -> V_34 , V_2 -> V_67 ) ;
V_5 -> V_73 = V_74 ;
} else
V_5 -> V_73 = F_34 ( V_45 ) ;
V_2 -> V_45 = NULL ;
V_2 -> V_75 = 0 ;
V_2 -> V_67 = 0 ;
}
static inline void F_35 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_36 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_45 * F_37 ( struct V_5 * V_5 )
{
unsigned long V_19 ;
struct V_45 * V_45 = NULL ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
while ( V_5 -> V_50 > 1 && V_5 -> V_54 == NULL ) {
F_38 ( V_76 ) ;
V_5 -> V_51 = V_77 ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
if ( ! ( V_5 -> V_21 -> V_78 & V_79 ) ||
! F_39 ( V_5 -> V_70 -> V_80 , V_5 -> V_73 ) )
F_40 () ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_5 -> V_51 = NULL ;
}
if ( V_5 -> V_54 ) {
V_45 = V_5 -> V_54 ;
V_5 -> V_54 = V_45 -> V_46 ;
}
F_23 ( & V_5 -> V_49 , V_19 ) ;
return V_45 ;
}
static T_4 F_20 ( struct V_5 * V_5 , struct V_45 * V_45 )
{
struct V_81 * V_82 ;
unsigned V_83 ;
T_4 V_24 = V_45 -> V_84 ;
if ( V_24 ) {
if ( V_24 == V_85 && ( V_45 -> V_86 & V_87 ) )
V_5 -> V_30 = - V_88 ;
else
V_5 -> V_30 = - V_89 ;
}
if ( V_5 -> V_55 && V_5 -> V_13 == V_27 && V_5 -> V_69 ) {
F_41 ( V_45 ) ;
} else {
F_42 (bvec, bio, i) {
struct V_15 * V_15 = V_82 -> V_90 ;
if ( V_5 -> V_13 == V_27 && ! F_43 ( V_15 ) &&
V_5 -> V_69 )
F_44 ( V_15 ) ;
F_36 ( V_15 ) ;
}
F_45 ( V_45 ) ;
}
return V_24 ;
}
static void F_46 ( struct V_5 * V_5 )
{
struct V_45 * V_45 ;
do {
V_45 = F_37 ( V_5 ) ;
if ( V_45 )
F_20 ( V_5 , V_45 ) ;
} while ( V_45 );
}
static inline int F_47 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_91 ++ >= 64 ) {
while ( V_5 -> V_54 ) {
unsigned long V_19 ;
struct V_45 * V_45 ;
int V_92 ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_45 = V_5 -> V_54 ;
V_5 -> V_54 = V_45 -> V_46 ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
V_92 = F_48 ( F_20 ( V_5 , V_45 ) ) ;
if ( V_6 == 0 )
V_6 = V_92 ;
}
V_2 -> V_91 = 0 ;
}
return V_6 ;
}
int F_49 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_95 * V_97 = F_50 ( L_1 ,
V_98 , 0 ,
V_94 -> V_99 ) ;
if ( ! V_97 )
return - V_100 ;
V_96 = F_51 ( & V_94 -> V_53 , NULL , V_97 ) ;
if ( V_96 )
F_52 ( V_97 ) ;
return 0 ;
}
static int F_53 ( struct V_5 * V_5 )
{
struct V_93 * V_94 = V_5 -> V_34 -> V_52 ;
if ( V_5 -> V_48 )
return 0 ;
V_5 -> V_48 = true ;
if ( ! V_94 -> V_53 )
return F_49 ( V_94 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_101 * V_102 )
{
int V_6 ;
T_3 V_103 ;
T_3 V_104 ;
unsigned long V_105 ;
int V_106 ;
unsigned int V_107 = V_2 -> V_108 + V_2 -> V_109 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_110 >= V_2 -> V_111 ) ;
V_103 = V_2 -> V_110 >> V_2 -> V_109 ;
V_104 = ( V_2 -> V_111 - 1 ) >>
V_2 -> V_109 ;
V_105 = V_104 - V_103 + 1 ;
V_102 -> V_112 = 0 ;
V_102 -> V_113 = V_105 << V_107 ;
V_106 = V_5 -> V_13 == V_14 ;
if ( V_5 -> V_19 & V_114 ) {
if ( V_103 <= ( ( F_55 ( V_5 -> V_34 ) - 1 ) >>
V_107 ) )
V_106 = 0 ;
}
V_6 = (* V_2 -> V_115 )( V_5 -> V_34 , V_103 ,
V_102 , V_106 ) ;
V_5 -> V_32 = V_102 -> V_116 ;
if ( V_6 == 0 && F_56 ( V_102 ) )
V_6 = F_53 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_57 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_117 , struct V_101 * V_102 )
{
T_3 V_118 ;
int V_6 , V_119 ;
V_6 = F_47 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_120;
V_118 = V_117 << ( V_2 -> V_108 - 9 ) ;
V_119 = F_58 ( V_2 -> V_121 , V_122 ) ;
F_9 ( V_119 <= 0 ) ;
F_28 ( V_5 , V_2 , V_102 -> V_123 , V_118 , V_119 ) ;
V_2 -> V_75 = 0 ;
V_120:
return V_6 ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_60 ( V_2 -> V_45 , V_2 -> V_124 ,
V_2 -> V_125 , V_2 -> V_126 ) ;
if ( V_6 == V_2 -> V_125 ) {
if ( ( V_2 -> V_125 + V_2 -> V_126 ) == V_18 )
V_2 -> V_121 -- ;
F_5 ( V_2 -> V_124 ) ;
V_2 -> V_127 = V_2 -> V_128 +
( V_2 -> V_125 >> V_2 -> V_108 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_101 * V_102 )
{
int V_6 = 0 ;
if ( V_2 -> V_45 ) {
T_2 V_129 = V_2 -> V_68 ;
T_2 V_130 = V_2 -> V_67 +
V_2 -> V_45 -> V_61 . V_131 ;
if ( V_2 -> V_127 != V_2 -> V_128 ||
V_129 != V_130 )
F_32 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_45 == NULL ) {
V_6 = F_57 ( V_5 , V_2 , V_2 -> V_128 , V_102 ) ;
if ( V_6 )
goto V_120;
}
if ( F_59 ( V_2 ) != 0 ) {
F_32 ( V_5 , V_2 ) ;
V_6 = F_57 ( V_5 , V_2 , V_2 -> V_128 , V_102 ) ;
if ( V_6 == 0 ) {
V_6 = F_59 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_120:
return V_6 ;
}
static inline int
F_62 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_20 , unsigned V_132 , T_3 V_133 ,
struct V_101 * V_102 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 == V_14 ) {
F_63 ( V_132 ) ;
}
if ( V_2 -> V_124 == V_15 &&
V_2 -> V_126 + V_2 -> V_125 == V_20 &&
V_2 -> V_128 +
( V_2 -> V_125 >> V_2 -> V_108 ) == V_133 ) {
V_2 -> V_125 += V_132 ;
goto V_120;
}
if ( V_2 -> V_124 ) {
V_6 = F_61 ( V_5 , V_2 , V_102 ) ;
F_36 ( V_2 -> V_124 ) ;
V_2 -> V_124 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_124 = V_15 ;
V_2 -> V_126 = V_20 ;
V_2 -> V_125 = V_132 ;
V_2 -> V_128 = V_133 ;
V_2 -> V_68 = V_2 -> V_110 << V_2 -> V_108 ;
V_120:
if ( V_2 -> V_75 ) {
V_6 = F_61 ( V_5 , V_2 , V_102 ) ;
if ( V_2 -> V_45 )
F_32 ( V_5 , V_2 ) ;
F_36 ( V_2 -> V_124 ) ;
V_2 -> V_124 = NULL ;
}
return V_6 ;
}
static inline void F_64 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_134 , struct V_101 * V_102 )
{
unsigned V_135 ;
unsigned V_136 ;
unsigned V_137 ;
struct V_15 * V_15 ;
V_2 -> V_138 = 1 ;
if ( ! V_2 -> V_109 || ! F_65 ( V_102 ) )
return;
V_135 = 1 << V_2 -> V_109 ;
V_136 = V_2 -> V_110 & ( V_135 - 1 ) ;
if ( ! V_136 )
return;
if ( V_134 )
V_136 = V_135 - V_136 ;
V_137 = V_136 << V_2 -> V_108 ;
V_15 = F_4 ( 0 ) ;
if ( F_62 ( V_5 , V_2 , V_15 , 0 , V_137 ,
V_2 -> V_139 , V_102 ) )
return;
V_2 -> V_139 += V_136 ;
}
static int F_66 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_101 * V_102 )
{
const unsigned V_108 = V_2 -> V_108 ;
const unsigned V_107 = V_108 + V_2 -> V_109 ;
int V_6 = 0 ;
while ( V_2 -> V_110 < V_2 -> V_111 ) {
struct V_15 * V_15 ;
T_5 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_67 ( V_15 ) ) {
V_6 = F_68 ( V_15 ) ;
goto V_120;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_137 ;
unsigned V_136 ;
unsigned V_140 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_141 ;
unsigned long V_142 ;
V_6 = F_54 ( V_5 , V_2 , V_102 ) ;
if ( V_6 ) {
F_36 ( V_15 ) ;
goto V_120;
}
if ( ! F_69 ( V_102 ) )
goto V_143;
V_2 -> V_12 =
V_102 -> V_113 >> V_108 ;
V_2 -> V_139 =
V_102 -> V_144 << V_2 -> V_109 ;
if ( F_65 ( V_102 ) ) {
F_70 (
V_102 -> V_123 ,
V_102 -> V_144 ,
V_102 -> V_113 >> V_107 ) ;
}
if ( ! V_2 -> V_109 )
goto V_143;
V_141 = ( 1 << V_2 -> V_109 ) - 1 ;
V_142 = ( V_2 -> V_110 & V_141 ) ;
if ( ! F_65 ( V_102 ) )
V_2 -> V_139 += V_142 ;
V_2 -> V_12 -= V_142 ;
}
V_143:
if ( ! F_69 ( V_102 ) ) {
T_2 V_145 ;
if ( V_5 -> V_13 == V_14 ) {
F_36 ( V_15 ) ;
return - V_146 ;
}
V_145 = F_71 ( F_55 ( V_5 -> V_34 ) ,
1 << V_108 ) ;
if ( V_2 -> V_110 >=
V_145 >> V_108 ) {
F_36 ( V_15 ) ;
goto V_120;
}
F_72 ( V_15 , V_11 , 1 << V_108 ) ;
V_2 -> V_110 ++ ;
V_11 += 1 << V_108 ;
V_5 -> V_26 += 1 << V_108 ;
goto V_147;
}
if ( F_11 ( V_2 -> V_109 && ! V_2 -> V_138 ) )
F_64 ( V_5 , V_2 , 0 , V_102 ) ;
V_136 = V_2 -> V_12 ;
V_140 = ( V_17 - V_11 ) >> V_108 ;
if ( V_136 > V_140 )
V_136 = V_140 ;
V_140 = V_2 -> V_111 - V_2 -> V_110 ;
if ( V_136 > V_140 )
V_136 = V_140 ;
V_137 = V_136 << V_108 ;
F_9 ( V_137 == 0 ) ;
if ( V_136 == V_2 -> V_12 )
V_2 -> V_75 = F_73 ( V_102 ) ;
V_6 = F_62 ( V_5 , V_2 , V_15 ,
V_11 ,
V_137 ,
V_2 -> V_139 ,
V_102 ) ;
if ( V_6 ) {
F_36 ( V_15 ) ;
goto V_120;
}
V_2 -> V_139 += V_136 ;
V_2 -> V_110 += V_136 ;
V_11 += V_137 ;
V_5 -> V_26 += V_137 ;
V_2 -> V_12 -= V_136 ;
V_147:
F_9 ( V_2 -> V_110 > V_2 -> V_111 ) ;
if ( V_2 -> V_110 == V_2 -> V_111 )
break;
}
F_36 ( V_15 ) ;
}
V_120:
return V_6 ;
}
static inline int F_74 ( struct V_5 * V_5 )
{
int V_92 ;
unsigned long V_19 ;
F_21 ( & V_5 -> V_49 , V_19 ) ;
V_92 = -- V_5 -> V_50 ;
F_23 ( & V_5 -> V_49 , V_19 ) ;
return V_92 ;
}
static inline T_1
F_75 ( struct V_148 * V_21 , struct V_34 * V_34 ,
struct V_56 * V_57 , struct V_149 * V_7 ,
T_6 V_115 , T_7 V_31 ,
T_8 V_72 , int V_19 )
{
unsigned V_107 = F_76 ( V_34 -> V_107 ) ;
unsigned V_108 = V_107 ;
unsigned V_150 = ( 1 << V_108 ) - 1 ;
T_1 V_151 = - V_152 ;
T_5 V_153 = F_77 ( V_7 ) ;
T_2 V_20 = V_21 -> V_22 ;
T_2 V_134 = V_20 + V_153 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_101 V_102 = { 0 , } ;
struct V_154 V_155 ;
unsigned long V_156 = V_20 | F_78 ( V_7 ) ;
if ( V_156 & V_150 ) {
if ( V_57 )
V_108 = F_79 ( F_80 ( V_57 ) ) ;
V_150 = ( 1 << V_108 ) - 1 ;
if ( V_156 & V_150 )
goto V_120;
}
if ( F_81 ( V_7 ) == V_157 && ! F_77 ( V_7 ) )
return 0 ;
V_5 = F_82 ( V_41 , V_60 ) ;
V_151 = - V_100 ;
if ( ! V_5 )
goto V_120;
memset ( V_5 , 0 , F_83 ( struct V_5 , V_8 ) ) ;
V_5 -> V_19 = V_19 ;
if ( V_5 -> V_19 & V_158 ) {
if ( F_81 ( V_7 ) == V_157 ) {
struct V_159 * V_160 =
V_21 -> V_161 -> V_162 ;
F_84 ( V_34 ) ;
V_151 = F_85 ( V_160 , V_20 ,
V_134 - 1 ) ;
if ( V_151 ) {
F_86 ( V_34 ) ;
F_16 ( V_41 , V_5 ) ;
goto V_120;
}
}
}
V_5 -> V_28 = F_55 ( V_34 ) ;
if ( F_81 ( V_7 ) == V_157 && V_20 >= V_5 -> V_28 ) {
if ( V_5 -> V_19 & V_158 )
F_86 ( V_34 ) ;
F_16 ( V_41 , V_5 ) ;
V_151 = 0 ;
goto V_120;
}
if ( F_87 ( V_21 ) )
V_5 -> V_55 = false ;
else if ( ! ( V_5 -> V_19 & V_163 ) &&
F_81 ( V_7 ) == V_164 && V_134 > F_55 ( V_34 ) )
V_5 -> V_55 = false ;
else
V_5 -> V_55 = true ;
V_5 -> V_34 = V_34 ;
if ( F_81 ( V_7 ) == V_164 ) {
V_5 -> V_13 = V_14 ;
V_5 -> V_63 = V_165 | V_166 ;
if ( V_21 -> V_78 & V_167 )
V_5 -> V_63 |= V_87 ;
} else {
V_5 -> V_13 = V_27 ;
}
if ( V_5 -> V_55 && F_81 ( V_7 ) == V_164 ) {
V_151 = 0 ;
if ( ( V_21 -> V_161 -> V_168 & V_169 ) ||
F_88 ( V_21 -> V_161 -> V_162 -> V_170 ) )
V_151 = F_53 ( V_5 ) ;
else if ( ! V_5 -> V_34 -> V_52 -> V_53 ) {
V_151 = F_49 ( V_5 -> V_34 -> V_52 ) ;
}
if ( V_151 ) {
F_16 ( V_41 , V_5 ) ;
goto V_120;
}
}
if ( ! ( V_5 -> V_19 & V_38 ) )
F_89 ( V_34 ) ;
V_151 = 0 ;
V_2 . V_108 = V_108 ;
V_2 . V_109 = V_107 - V_108 ;
V_2 . V_110 = V_20 >> V_108 ;
V_2 . V_115 = V_115 ;
V_5 -> V_31 = V_31 ;
V_2 . V_72 = V_72 ;
V_2 . V_127 = - 1 ;
V_2 . V_139 = - 1 ;
V_5 -> V_21 = V_21 ;
F_90 ( & V_5 -> V_49 ) ;
V_5 -> V_50 = 1 ;
V_5 -> V_69 = ( V_7 -> type == V_171 ) ;
V_2 . V_7 = V_7 ;
V_2 . V_111 =
( V_20 + F_77 ( V_7 ) ) >> V_108 ;
if ( F_11 ( V_2 . V_109 ) )
V_2 . V_121 = 2 ;
V_2 . V_121 += F_91 ( V_7 , V_172 ) ;
F_92 ( & V_155 ) ;
V_151 = F_66 ( V_5 , & V_2 , & V_102 ) ;
if ( V_151 )
F_35 ( V_5 , & V_2 ) ;
if ( V_151 == - V_146 ) {
V_151 = 0 ;
}
F_64 ( V_5 , & V_2 , 1 , & V_102 ) ;
if ( V_2 . V_124 ) {
T_1 V_92 ;
V_92 = F_61 ( V_5 , & V_2 , & V_102 ) ;
if ( V_151 == 0 )
V_151 = V_92 ;
F_36 ( V_2 . V_124 ) ;
V_2 . V_124 = NULL ;
}
if ( V_2 . V_45 )
F_32 ( V_5 , & V_2 ) ;
F_93 ( & V_155 ) ;
F_35 ( V_5 , & V_2 ) ;
if ( F_81 ( V_7 ) == V_157 && ( V_5 -> V_19 & V_158 ) )
F_86 ( V_5 -> V_34 ) ;
F_9 ( V_151 == - V_25 ) ;
if ( V_5 -> V_55 && V_151 == 0 && V_5 -> V_26 &&
( F_81 ( V_7 ) == V_157 || V_5 -> V_26 == V_153 ) )
V_151 = - V_25 ;
else
F_46 ( V_5 ) ;
if ( F_74 ( V_5 ) == 0 ) {
V_151 = F_10 ( V_5 , V_151 , V_33 ) ;
} else
F_9 ( V_151 != - V_25 ) ;
V_120:
return V_151 ;
}
T_1 F_94 ( struct V_148 * V_21 , struct V_34 * V_34 ,
struct V_56 * V_57 , struct V_149 * V_7 ,
T_6 V_115 ,
T_7 V_31 , T_8 V_72 ,
int V_19 )
{
F_95 ( & V_57 -> V_173 -> V_174 ) ;
F_95 ( V_57 -> V_175 ) ;
F_95 ( ( char * ) V_57 -> V_175 + V_176 ) ;
return F_75 ( V_21 , V_34 , V_57 , V_7 , V_115 ,
V_31 , V_72 , V_19 ) ;
}
static T_9 int F_96 ( void )
{
V_41 = F_97 ( V_5 , V_177 ) ;
return 0 ;
}
