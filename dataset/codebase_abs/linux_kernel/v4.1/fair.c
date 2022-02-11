static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_4 += V_3 ;
V_2 -> V_5 = 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , unsigned long V_6 )
{
V_2 -> V_4 -= V_6 ;
V_2 -> V_5 = 0 ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned long V_7 )
{
V_2 -> V_4 = V_7 ;
V_2 -> V_5 = 0 ;
}
static int F_4 ( void )
{
unsigned int V_8 = F_5 ( int , F_6 () , 8 ) ;
unsigned int V_9 ;
switch ( V_10 ) {
case V_11 :
V_9 = 1 ;
break;
case V_12 :
V_9 = V_8 ;
break;
case V_13 :
default:
V_9 = 1 + F_7 ( V_8 ) ;
break;
}
return V_9 ;
}
static void F_8 ( void )
{
unsigned int V_9 = F_4 () ;
#define F_9 ( T_1 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_9 ( V_14 ) ;
F_9 ( V_15 ) ;
F_9 ( V_16 ) ;
#undef F_9
}
void F_10 ( void )
{
F_8 () ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
if ( F_12 ( V_2 -> V_5 ) )
return;
V_7 = F_13 ( V_2 -> V_4 ) ;
if ( V_17 > 32 && F_14 ( V_7 >= V_18 ) )
V_2 -> V_5 = 1 ;
else if ( F_14 ( ! V_7 ) )
V_2 -> V_5 = V_18 ;
else
V_2 -> V_5 = V_18 / V_7 ;
}
static T_2 F_15 ( T_2 V_19 , unsigned long V_4 , struct V_1 * V_2 )
{
T_2 V_20 = F_13 ( V_4 ) ;
int V_21 = V_22 ;
F_11 ( V_2 ) ;
if ( F_14 ( V_20 >> 32 ) ) {
while ( V_20 >> 32 ) {
V_20 >>= 1 ;
V_21 -- ;
}
}
V_20 = ( T_2 ) ( V_23 ) V_20 * V_2 -> V_5 ;
while ( V_20 >> 32 ) {
V_20 >>= 1 ;
V_21 -- ;
}
return F_16 ( V_19 , V_20 , V_21 ) ;
}
static inline struct V_24 * F_17 ( struct V_25 * V_25 )
{
return V_25 -> V_24 ;
}
static inline struct V_26 * F_18 ( struct V_27 * V_28 )
{
#ifdef F_19
F_20 ( ! F_21 ( V_28 ) ) ;
#endif
return F_22 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_25 * F_23 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_25 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_28 )
{
return V_28 -> V_25 ;
}
static inline struct V_25 * F_25 ( struct V_27 * V_30 )
{
return V_30 -> V_31 ;
}
static inline void F_26 ( struct V_25 * V_25 )
{
if ( ! V_25 -> V_32 ) {
if ( V_25 -> V_33 -> V_34 &&
V_25 -> V_33 -> V_34 -> V_25 [ F_27 ( F_17 ( V_25 ) ) ] -> V_32 ) {
F_28 ( & V_25 -> V_35 ,
& F_17 ( V_25 ) -> V_35 ) ;
} else {
F_29 ( & V_25 -> V_35 ,
& F_17 ( V_25 ) -> V_35 ) ;
}
V_25 -> V_32 = 1 ;
F_30 ( V_25 , 0 ) ;
}
}
static inline void F_31 ( struct V_25 * V_25 )
{
if ( V_25 -> V_32 ) {
F_32 ( & V_25 -> V_35 ) ;
V_25 -> V_32 = 0 ;
}
}
static inline struct V_25 *
F_33 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
if ( V_28 -> V_25 == V_36 -> V_25 )
return V_28 -> V_25 ;
return NULL ;
}
static inline struct V_27 * F_34 ( struct V_27 * V_28 )
{
return V_28 -> V_34 ;
}
static void
F_35 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
int V_37 , V_38 ;
V_37 = ( * V_28 ) -> V_39 ;
V_38 = ( * V_36 ) -> V_39 ;
while ( V_37 > V_38 ) {
V_37 -- ;
* V_28 = F_34 ( * V_28 ) ;
}
while ( V_38 > V_37 ) {
V_38 -- ;
* V_36 = F_34 ( * V_36 ) ;
}
while ( ! F_33 ( * V_28 , * V_36 ) ) {
* V_28 = F_34 ( * V_28 ) ;
* V_36 = F_34 ( * V_36 ) ;
}
}
static inline struct V_26 * F_18 ( struct V_27 * V_28 )
{
return F_22 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_24 * F_17 ( struct V_25 * V_25 )
{
return F_22 ( V_25 , struct V_24 , V_40 ) ;
}
static inline struct V_25 * F_23 ( struct V_26 * V_29 )
{
return & F_36 ( V_29 ) -> V_40 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_28 )
{
struct V_26 * V_29 = F_18 ( V_28 ) ;
struct V_24 * V_24 = F_36 ( V_29 ) ;
return & V_24 -> V_40 ;
}
static inline struct V_25 * F_25 ( struct V_27 * V_30 )
{
return NULL ;
}
static inline void F_26 ( struct V_25 * V_25 )
{
}
static inline void F_31 ( struct V_25 * V_25 )
{
}
static inline struct V_27 * F_34 ( struct V_27 * V_28 )
{
return NULL ;
}
static inline void
F_35 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
}
static inline T_2 F_37 ( T_2 F_37 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_37 ) ;
if ( V_42 > 0 )
F_37 = V_41 ;
return F_37 ;
}
static inline T_2 F_38 ( T_2 F_38 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_38 ) ;
if ( V_42 < 0 )
F_38 = V_41 ;
return F_38 ;
}
static inline int F_39 ( struct V_27 * V_43 ,
struct V_27 * V_44 )
{
return ( T_3 ) ( V_43 -> V_41 - V_44 -> V_41 ) < 0 ;
}
static void F_40 ( struct V_25 * V_25 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_25 -> V_45 )
V_41 = V_25 -> V_45 -> V_41 ;
if ( V_25 -> V_46 ) {
struct V_27 * V_28 = F_41 ( V_25 -> V_46 ,
struct V_27 ,
V_47 ) ;
if ( ! V_25 -> V_45 )
V_41 = V_28 -> V_41 ;
else
V_41 = F_38 ( V_41 , V_28 -> V_41 ) ;
}
V_25 -> F_38 = F_37 ( V_25 -> F_38 , V_41 ) ;
#ifndef F_42
F_43 () ;
V_25 -> V_48 = V_25 -> F_38 ;
#endif
}
static void F_44 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_49 * * V_50 = & V_25 -> V_51 . V_49 ;
struct V_49 * V_34 = NULL ;
struct V_27 * V_52 ;
int V_53 = 1 ;
while ( * V_50 ) {
V_34 = * V_50 ;
V_52 = F_41 ( V_34 , struct V_27 , V_47 ) ;
if ( F_39 ( V_28 , V_52 ) ) {
V_50 = & V_34 -> V_54 ;
} else {
V_50 = & V_34 -> V_55 ;
V_53 = 0 ;
}
}
if ( V_53 )
V_25 -> V_46 = & V_28 -> V_47 ;
F_45 ( & V_28 -> V_47 , V_34 , V_50 ) ;
F_46 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
static void F_47 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_46 == & V_28 -> V_47 ) {
struct V_49 * V_56 ;
V_56 = F_48 ( & V_28 -> V_47 ) ;
V_25 -> V_46 = V_56 ;
}
F_49 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
struct V_27 * F_50 ( struct V_25 * V_25 )
{
struct V_49 * V_57 = V_25 -> V_46 ;
if ( ! V_57 )
return NULL ;
return F_41 ( V_57 , struct V_27 , V_47 ) ;
}
static struct V_27 * F_51 ( struct V_27 * V_28 )
{
struct V_49 * V_58 = F_48 ( & V_28 -> V_47 ) ;
if ( ! V_58 )
return NULL ;
return F_41 ( V_58 , struct V_27 , V_47 ) ;
}
struct V_27 * F_52 ( struct V_25 * V_25 )
{
struct V_49 * V_59 = F_53 ( & V_25 -> V_51 ) ;
if ( ! V_59 )
return NULL ;
return F_41 ( V_59 , struct V_27 , V_47 ) ;
}
int F_54 ( struct V_60 * V_61 , int V_62 ,
void T_4 * V_63 , T_5 * V_64 ,
T_6 * V_65 )
{
int V_66 = F_55 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
int V_9 = F_4 () ;
if ( V_66 || ! V_62 )
return V_66 ;
V_67 = F_56 ( V_68 ,
V_69 ) ;
#define F_57 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_57 ( V_14 ) ;
F_57 ( V_15 ) ;
F_57 ( V_16 ) ;
#undef F_57
return 0 ;
}
static inline T_2 F_58 ( T_2 V_42 , struct V_27 * V_28 )
{
if ( F_14 ( V_28 -> V_70 . V_4 != V_71 ) )
V_42 = F_15 ( V_42 , V_71 , & V_28 -> V_70 ) ;
return V_42 ;
}
static T_2 F_59 ( unsigned long V_72 )
{
T_2 V_73 = V_68 ;
unsigned long V_74 = V_67 ;
if ( F_14 ( V_72 > V_74 ) ) {
V_73 = V_69 ;
V_73 *= V_72 ;
}
return V_73 ;
}
static T_2 F_60 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_75 = F_59 ( V_25 -> V_72 + ! V_28 -> V_76 ) ;
F_61 (se) {
struct V_1 * V_70 ;
struct V_1 V_2 ;
V_25 = F_24 ( V_28 ) ;
V_70 = & V_25 -> V_70 ;
if ( F_14 ( ! V_28 -> V_76 ) ) {
V_2 = V_25 -> V_70 ;
F_1 ( & V_2 , V_28 -> V_70 . V_4 ) ;
V_70 = & V_2 ;
}
V_75 = F_15 ( V_75 , V_28 -> V_70 . V_4 , V_70 ) ;
}
return V_75 ;
}
static T_2 F_62 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_58 ( F_60 ( V_25 , V_28 ) , V_28 ) ;
}
void F_63 ( struct V_26 * V_29 )
{
V_23 V_75 ;
V_75 = F_60 ( F_23 ( V_29 ) , & V_29 -> V_28 ) >> 10 ;
V_29 -> V_28 . V_77 . V_78 = V_29 -> V_28 . V_77 . V_79 = V_75 ;
V_29 -> V_28 . V_77 . V_80 = V_75 ;
F_64 ( & V_29 -> V_28 ) ;
F_65 ( & V_29 -> V_28 ) ;
}
void F_63 ( struct V_26 * V_29 )
{
}
static void F_66 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_81 = F_67 ( F_17 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_14 ( ! V_45 ) )
return;
V_19 = V_81 - V_45 -> V_82 ;
if ( F_14 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_82 = V_81 ;
F_68 ( V_45 -> V_83 . V_84 ,
F_69 ( V_19 , V_45 -> V_83 . V_84 ) ) ;
V_45 -> V_85 += V_19 ;
F_70 ( V_25 , V_86 , V_19 ) ;
V_45 -> V_41 += F_58 ( V_19 , V_45 ) ;
F_40 ( V_25 ) ;
if ( F_21 ( V_45 ) ) {
struct V_26 * V_87 = F_18 ( V_45 ) ;
F_71 ( V_87 , V_19 , V_45 -> V_41 ) ;
F_72 ( V_87 , V_19 ) ;
F_73 ( V_87 , V_19 ) ;
}
F_74 ( V_25 , V_19 ) ;
}
static void F_75 ( struct V_24 * V_24 )
{
F_66 ( F_24 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_68 ( V_28 -> V_83 . V_88 , F_77 ( F_17 ( V_25 ) ) ) ;
}
static void F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_76 ( V_25 , V_28 ) ;
}
static void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_68 ( V_28 -> V_83 . V_89 , F_69 ( V_28 -> V_83 . V_89 ,
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ) ;
F_68 ( V_28 -> V_83 . V_90 , V_28 -> V_83 . V_90 + 1 ) ;
F_68 ( V_28 -> V_83 . V_91 , V_28 -> V_83 . V_91 +
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
#ifdef F_80
if ( F_21 ( V_28 ) ) {
F_81 ( F_18 ( V_28 ) ,
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
}
#endif
F_68 ( V_28 -> V_83 . V_88 , 0 ) ;
}
static inline void
F_82 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_79 ( V_25 , V_28 ) ;
}
static inline void
F_83 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_82 = F_67 ( F_17 ( V_25 ) ) ;
}
static unsigned int F_84 ( struct V_26 * V_29 )
{
unsigned long V_92 = 0 ;
unsigned long V_93 ;
V_93 = V_94 << ( 20 - V_95 ) ;
V_92 = F_85 ( V_29 -> V_96 ) ;
if ( ! V_92 )
V_92 = V_93 ;
V_92 = F_86 ( V_92 , V_93 ) ;
return V_92 / V_93 ;
}
static unsigned int F_87 ( struct V_26 * V_29 )
{
unsigned int V_97 = F_88 ( V_94 ) ;
unsigned int V_98 , floor ;
unsigned int V_99 = 1 ;
if ( V_97 < V_100 )
V_99 = V_100 / V_97 ;
floor = 1000 / V_99 ;
V_98 = V_101 / F_84 ( V_29 ) ;
return F_89 (unsigned int, floor, scan) ;
}
static unsigned int F_90 ( struct V_26 * V_29 )
{
unsigned int V_102 = F_87 ( V_29 ) ;
unsigned int V_103 ;
V_103 = V_104 / F_84 ( V_29 ) ;
return F_69 ( V_102 , V_103 ) ;
}
static void F_91 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_105 += ( V_29 -> V_106 != - 1 ) ;
V_24 -> V_107 += ( V_29 -> V_106 == F_92 ( V_29 ) ) ;
}
static void F_93 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_105 -= ( V_29 -> V_106 != - 1 ) ;
V_24 -> V_107 -= ( V_29 -> V_106 == F_92 ( V_29 ) ) ;
}
T_7 F_94 ( struct V_26 * V_29 )
{
return V_29 -> V_108 ? V_29 -> V_108 -> V_109 : 0 ;
}
static inline int F_95 ( enum V_110 V_111 , int V_112 , int V_113 )
{
return V_114 * ( V_111 * V_115 + V_112 ) + V_113 ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_112 )
{
if ( ! V_29 -> V_116 )
return 0 ;
return V_29 -> V_116 [ F_95 ( V_117 , V_112 , 0 ) ] +
V_29 -> V_116 [ F_95 ( V_117 , V_112 , 1 ) ] ;
}
static inline unsigned long F_97 ( struct V_26 * V_29 , int V_112 )
{
if ( ! V_29 -> V_108 )
return 0 ;
return V_29 -> V_108 -> V_118 [ F_95 ( V_117 , V_112 , 0 ) ] +
V_29 -> V_108 -> V_118 [ F_95 ( V_117 , V_112 , 1 ) ] ;
}
static inline unsigned long F_98 ( struct V_108 * V_119 , int V_112 )
{
return V_119 -> V_120 [ F_95 ( V_117 , V_112 , 0 ) ] +
V_119 -> V_120 [ F_95 ( V_117 , V_112 , 1 ) ] ;
}
static unsigned long F_99 ( struct V_26 * V_29 , int V_112 ,
int V_121 , bool V_122 )
{
unsigned long V_123 = 0 ;
int V_124 ;
if ( V_125 == V_126 )
return 0 ;
F_100 (node) {
unsigned long V_118 ;
int V_127 = F_101 ( V_112 , V_124 ) ;
if ( V_127 == V_128 || V_124 == V_112 )
continue;
if ( V_125 == V_129 &&
V_127 > V_121 )
continue;
if ( V_122 )
V_118 = F_96 ( V_29 , V_124 ) ;
else
V_118 = F_97 ( V_29 , V_124 ) ;
if ( V_125 == V_130 ) {
V_118 *= ( V_128 - V_127 ) ;
V_118 /= ( V_128 - V_131 ) ;
}
V_123 += V_118 ;
}
return V_123 ;
}
static inline unsigned long F_102 ( struct V_26 * V_29 , int V_112 ,
int V_127 )
{
unsigned long V_118 , V_132 ;
if ( ! V_29 -> V_116 )
return 0 ;
V_132 = V_29 -> V_133 ;
if ( ! V_132 )
return 0 ;
V_118 = F_96 ( V_29 , V_112 ) ;
V_118 += F_99 ( V_29 , V_112 , V_127 , true ) ;
return 1000 * V_118 / V_132 ;
}
static inline unsigned long F_103 ( struct V_26 * V_29 , int V_112 ,
int V_127 )
{
unsigned long V_118 , V_132 ;
if ( ! V_29 -> V_108 )
return 0 ;
V_132 = V_29 -> V_108 -> V_132 ;
if ( ! V_132 )
return 0 ;
V_118 = F_97 ( V_29 , V_112 ) ;
V_118 += F_99 ( V_29 , V_112 , V_127 , false ) ;
return 1000 * V_118 / V_132 ;
}
bool F_104 ( struct V_26 * V_29 , struct V_134 * V_134 ,
int V_135 , int V_136 )
{
struct V_108 * V_137 = V_29 -> V_108 ;
int V_138 = F_105 ( V_136 ) ;
int V_139 , V_140 ;
V_140 = F_106 ( V_136 , V_141 -> V_142 ) ;
V_139 = F_107 ( V_134 , V_140 ) ;
if ( ! F_108 ( V_139 ) &&
F_109 ( V_139 ) != V_138 )
return false ;
if ( F_110 ( V_29 , V_139 ) )
return true ;
if ( ! V_137 )
return true ;
if ( ! F_111 ( V_138 , V_137 -> V_143 ) )
return false ;
if ( ! F_111 ( V_135 , V_137 -> V_143 ) )
return true ;
return F_97 ( V_29 , V_138 ) < ( F_97 ( V_29 , V_135 ) * 3 / 4 ) ;
}
static void F_112 ( struct V_144 * V_145 , int V_112 )
{
int V_146 , V_147 , V_8 = 0 ;
unsigned long V_148 ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
F_113 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_114 ( V_147 ) ;
V_145 -> V_72 += V_24 -> V_72 ;
V_145 -> V_70 += F_115 ( V_147 ) ;
V_145 -> V_149 += F_116 ( V_147 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_146 = F_56 ( V_150 * V_8 , V_145 -> V_149 ) ;
V_148 = V_8 / V_146 ;
V_145 -> V_151 = F_5 ( unsigned , V_148 ,
F_117 ( V_145 -> V_149 , V_150 ) ) ;
V_145 -> V_152 = ( V_145 -> V_72 < V_145 -> V_151 ) ;
}
static void F_118 ( struct V_153 * V_154 ,
struct V_26 * V_29 , long V_155 )
{
if ( V_154 -> V_156 )
F_119 ( V_154 -> V_156 ) ;
if ( V_29 )
F_120 ( V_29 ) ;
V_154 -> V_156 = V_29 ;
V_154 -> V_157 = V_155 ;
V_154 -> V_158 = V_154 -> V_136 ;
}
static bool F_121 ( long V_159 , long V_160 ,
struct V_153 * V_154 )
{
long V_161 , V_162 ;
long V_163 ;
long V_164 , V_165 ;
long V_166 ;
long V_167 ;
V_161 = V_154 -> V_168 . V_149 ;
V_162 = V_154 -> V_169 . V_149 ;
V_164 = V_160 ;
V_165 = V_159 ;
if ( V_164 < V_165 )
F_122 ( V_164 , V_165 ) ;
V_167 = V_164 * V_161 * 100 -
V_165 * V_162 * V_154 -> V_170 ;
if ( V_167 <= 0 )
return false ;
V_163 = V_154 -> V_168 . V_70 ;
V_166 = V_163 - V_159 ;
if ( V_166 > 0 )
return V_159 * V_162 < V_160 * V_161 ;
else
return V_160 * V_161 < V_159 * V_162 ;
}
static void F_123 ( struct V_153 * V_154 ,
long V_171 , long V_172 )
{
struct V_24 * V_173 = F_114 ( V_154 -> V_174 ) ;
struct V_24 * V_175 = F_114 ( V_154 -> V_136 ) ;
struct V_26 * V_176 ;
long V_159 , V_160 ;
long V_70 ;
long V_155 = V_154 -> V_29 -> V_108 ? V_172 : V_171 ;
long V_177 = V_155 ;
int V_127 = V_154 -> V_127 ;
F_124 () ;
F_125 ( & V_175 -> V_178 ) ;
V_176 = V_175 -> V_45 ;
if ( ( V_176 -> V_179 & V_180 ) || F_126 ( V_176 ) )
V_176 = NULL ;
F_127 ( & V_175 -> V_178 ) ;
if ( V_176 == V_154 -> V_29 )
goto V_181;
if ( V_176 ) {
if ( ! F_128 ( V_154 -> V_174 , F_129 ( V_176 ) ) )
goto V_181;
if ( V_176 -> V_108 == V_154 -> V_29 -> V_108 ) {
V_155 = V_171 + F_102 ( V_176 , V_154 -> V_135 , V_127 ) -
F_102 ( V_176 , V_154 -> V_138 , V_127 ) ;
if ( V_176 -> V_108 )
V_155 -= V_155 / 16 ;
} else {
if ( V_176 -> V_108 )
V_155 += F_103 ( V_176 , V_154 -> V_135 , V_127 ) -
F_103 ( V_176 , V_154 -> V_138 , V_127 ) ;
else
V_155 += F_102 ( V_176 , V_154 -> V_135 , V_127 ) -
F_102 ( V_176 , V_154 -> V_138 , V_127 ) ;
}
}
if ( V_155 <= V_154 -> V_157 && V_177 <= V_154 -> V_157 )
goto V_181;
if ( ! V_176 ) {
if ( V_154 -> V_168 . V_72 <= V_154 -> V_168 . V_151 &&
! V_154 -> V_169 . V_152 )
goto V_181;
goto V_182;
}
if ( V_155 > V_154 -> V_157 && V_173 -> V_72 == 1 &&
V_175 -> V_72 == 1 )
goto V_183;
V_182:
V_70 = F_130 ( V_154 -> V_29 ) ;
V_160 = V_154 -> V_169 . V_70 + V_70 ;
V_159 = V_154 -> V_168 . V_70 - V_70 ;
if ( V_177 > V_155 && V_177 > V_154 -> V_157 ) {
if ( ! F_121 ( V_159 , V_160 , V_154 ) ) {
V_155 = V_177 - 1 ;
V_176 = NULL ;
goto V_183;
}
}
if ( V_155 <= V_154 -> V_157 )
goto V_181;
if ( V_176 ) {
V_70 = F_130 ( V_176 ) ;
V_160 -= V_70 ;
V_159 += V_70 ;
}
if ( F_121 ( V_159 , V_160 , V_154 ) )
goto V_181;
if ( ! V_176 )
V_154 -> V_136 = F_131 ( V_154 -> V_29 , V_154 -> V_136 ) ;
V_183:
F_118 ( V_154 , V_176 , V_155 ) ;
V_181:
F_132 () ;
}
static void F_133 ( struct V_153 * V_154 ,
long V_171 , long V_172 )
{
int V_147 ;
F_113 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_128 ( V_147 , F_129 ( V_154 -> V_29 ) ) )
continue;
V_154 -> V_136 = V_147 ;
F_123 ( V_154 , V_171 , V_172 ) ;
}
}
static int F_134 ( struct V_26 * V_29 )
{
struct V_153 V_154 = {
. V_29 = V_29 ,
. V_174 = F_135 ( V_29 ) ,
. V_135 = F_92 ( V_29 ) ,
. V_170 = 112 ,
. V_156 = NULL ,
. V_157 = 0 ,
. V_158 = - 1
} ;
struct V_184 * V_185 ;
unsigned long V_186 , V_187 ;
int V_112 , V_66 , V_127 ;
long V_171 , V_172 ;
F_124 () ;
V_185 = F_136 ( F_137 ( V_188 , V_154 . V_174 ) ) ;
if ( V_185 )
V_154 . V_170 = 100 + ( V_185 -> V_170 - 100 ) / 2 ;
F_132 () ;
if ( F_14 ( ! V_185 ) ) {
V_29 -> V_106 = F_92 ( V_29 ) ;
return - V_189 ;
}
V_154 . V_138 = V_29 -> V_106 ;
V_127 = V_154 . V_127 = F_101 ( V_154 . V_135 , V_154 . V_138 ) ;
V_186 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
V_187 = F_103 ( V_29 , V_154 . V_135 , V_127 ) ;
F_112 ( & V_154 . V_168 , V_154 . V_135 ) ;
V_171 = F_102 ( V_29 , V_154 . V_138 , V_127 ) - V_186 ;
V_172 = F_103 ( V_29 , V_154 . V_138 , V_127 ) - V_187 ;
F_112 ( & V_154 . V_169 , V_154 . V_138 ) ;
F_133 ( & V_154 , V_171 , V_172 ) ;
if ( V_154 . V_158 == - 1 || ( V_29 -> V_108 &&
F_138 ( V_29 -> V_108 -> V_143 ) > 1 ) ) {
F_100 (nid) {
if ( V_112 == V_154 . V_135 || V_112 == V_29 -> V_106 )
continue;
V_127 = F_101 ( V_154 . V_135 , V_154 . V_138 ) ;
if ( V_125 == V_129 &&
V_127 != V_154 . V_127 ) {
V_186 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
V_187 = F_103 ( V_29 , V_154 . V_135 , V_127 ) ;
}
V_171 = F_102 ( V_29 , V_112 , V_127 ) - V_186 ;
V_172 = F_103 ( V_29 , V_112 , V_127 ) - V_187 ;
if ( V_171 < 0 && V_172 < 0 )
continue;
V_154 . V_127 = V_127 ;
V_154 . V_138 = V_112 ;
F_112 ( & V_154 . V_169 , V_154 . V_138 ) ;
F_133 ( & V_154 , V_171 , V_172 ) ;
}
}
if ( V_29 -> V_108 ) {
if ( V_154 . V_158 == - 1 )
V_112 = V_154 . V_135 ;
else
V_112 = V_154 . V_138 ;
if ( F_111 ( V_112 , V_29 -> V_108 -> V_143 ) )
F_139 ( V_29 , V_154 . V_138 ) ;
}
if ( V_154 . V_158 == - 1 )
return - V_190 ;
V_29 -> V_191 = F_87 ( V_29 ) ;
if ( V_154 . V_156 == NULL ) {
V_66 = F_140 ( V_29 , V_154 . V_158 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_154 . V_174 , V_154 . V_158 ) ;
return V_66 ;
}
V_66 = F_142 ( V_29 , V_154 . V_156 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_154 . V_174 , F_135 ( V_154 . V_156 ) ) ;
F_119 ( V_154 . V_156 ) ;
return V_66 ;
}
static void F_143 ( struct V_26 * V_29 )
{
unsigned long V_192 = V_193 ;
if ( F_14 ( V_29 -> V_106 == - 1 || ! V_29 -> V_116 ) )
return;
V_192 = F_144 ( V_192 , F_145 ( V_29 -> V_191 ) / 16 ) ;
V_29 -> V_194 = V_195 + V_192 ;
if ( F_92 ( V_29 ) == V_29 -> V_106 )
return;
F_134 ( V_29 ) ;
}
static void F_146 ( struct V_108 * V_108 )
{
unsigned long V_118 , V_196 = 0 ;
int V_112 ;
F_100 (nid) {
V_118 = F_98 ( V_108 , V_112 ) ;
if ( V_118 > V_196 )
V_196 = V_118 ;
}
F_100 (nid) {
V_118 = F_98 ( V_108 , V_112 ) ;
if ( ! F_111 ( V_112 , V_108 -> V_143 ) ) {
if ( V_118 > V_196 * 6 / 16 )
F_147 ( V_112 , V_108 -> V_143 ) ;
} else if ( V_118 < V_196 * 3 / 16 )
F_148 ( V_112 , V_108 -> V_143 ) ;
}
}
static void F_149 ( struct V_26 * V_29 ,
unsigned long V_197 , unsigned long V_198 )
{
unsigned int V_199 ;
int V_200 ;
int V_201 ;
unsigned long V_202 = V_29 -> V_203 [ 0 ] ;
unsigned long V_204 = V_29 -> V_203 [ 1 ] ;
if ( V_204 + V_197 == 0 || V_29 -> V_203 [ 2 ] ) {
V_29 -> V_191 = F_144 ( V_29 -> V_205 ,
V_29 -> V_191 << 1 ) ;
V_29 -> V_96 -> V_206 = V_195 +
F_145 ( V_29 -> V_191 ) ;
return;
}
V_199 = F_56 ( V_29 -> V_191 , V_207 ) ;
V_200 = ( V_204 * V_207 ) / ( V_204 + V_202 ) ;
if ( V_200 >= V_208 ) {
int V_209 = V_200 - V_208 ;
if ( ! V_209 )
V_209 = 1 ;
V_201 = V_209 * V_199 ;
} else {
V_201 = - ( V_208 - V_200 ) * V_199 ;
V_200 = F_56 ( V_198 * V_207 , ( V_198 + V_197 + 1 ) ) ;
V_201 = ( V_201 * V_200 ) / V_207 ;
}
V_29 -> V_191 = F_150 ( V_29 -> V_191 + V_201 ,
F_87 ( V_29 ) , F_90 ( V_29 ) ) ;
memset ( V_29 -> V_203 , 0 , sizeof( V_29 -> V_203 ) ) ;
}
static T_2 F_151 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_210 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_210 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_211 ) {
V_42 = V_210 - V_29 -> V_212 ;
* V_73 = V_81 - V_29 -> V_211 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_78 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_212 = V_210 ;
V_29 -> V_211 = V_81 ;
return V_42 ;
}
static int F_152 ( struct V_26 * V_29 , int V_112 )
{
T_8 V_213 ;
int V_127 ;
if ( V_125 == V_126 )
return V_112 ;
if ( V_125 == V_130 ) {
unsigned long V_123 , V_214 = 0 ;
int V_124 , V_215 = V_112 ;
V_127 = V_128 ;
F_100 (node) {
V_123 = F_103 ( V_29 , V_124 , V_127 ) ;
if ( V_123 > V_214 ) {
V_214 = V_123 ;
V_215 = V_124 ;
}
}
return V_215 ;
}
V_213 = V_216 ;
for ( V_127 = V_128 ; V_127 > V_131 ; V_127 -- ) {
unsigned long V_196 = 0 ;
T_8 V_217 = V_218 ;
int V_43 , V_44 ;
if ( ! F_153 ( V_127 ) )
continue;
F_154 (a, nodes) {
unsigned long V_118 = 0 ;
T_8 V_219 ;
F_155 ( V_219 ) ;
F_154 (b, nodes) {
if ( F_101 ( V_43 , V_44 ) < V_127 ) {
V_118 += F_97 ( V_29 , V_44 ) ;
F_147 ( V_44 , V_219 ) ;
F_148 ( V_44 , V_213 ) ;
}
}
if ( V_118 > V_196 ) {
V_196 = V_118 ;
V_217 = V_219 ;
V_112 = V_43 ;
}
}
if ( ! V_196 )
break;
V_213 = V_217 ;
}
return V_112 ;
}
static void F_156 ( struct V_26 * V_29 )
{
int V_220 , V_112 , V_221 = - 1 , V_222 = - 1 ;
unsigned long V_196 = 0 , V_223 = 0 ;
unsigned long V_224 [ 2 ] = { 0 , 0 } ;
unsigned long V_132 ;
T_2 V_210 , V_73 ;
T_9 * V_225 = NULL ;
V_220 = F_88 ( V_29 -> V_96 -> V_226 ) ;
if ( V_29 -> V_226 == V_220 )
return;
V_29 -> V_226 = V_220 ;
V_29 -> V_205 = F_90 ( V_29 ) ;
V_132 = V_29 -> V_203 [ 0 ] +
V_29 -> V_203 [ 1 ] ;
V_210 = F_151 ( V_29 , & V_73 ) ;
if ( V_29 -> V_108 ) {
V_225 = & V_29 -> V_108 -> V_178 ;
F_157 ( V_225 ) ;
}
F_100 (nid) {
int V_227 , V_228 , V_229 , V_230 ;
unsigned long V_118 = 0 , F_97 = 0 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
long V_201 , V_231 , V_232 ;
V_227 = F_95 ( V_117 , V_112 , V_113 ) ;
V_228 = F_95 ( V_233 , V_112 , V_113 ) ;
V_229 = F_95 ( V_234 , V_112 , V_113 ) ;
V_230 = F_95 ( V_235 , V_112 , V_113 ) ;
V_201 = V_29 -> V_116 [ V_228 ] - V_29 -> V_116 [ V_227 ] / 2 ;
V_224 [ V_113 ] += V_29 -> V_116 [ V_228 ] ;
V_29 -> V_116 [ V_228 ] = 0 ;
V_232 = F_158 ( V_210 << 16 , V_73 + 1 ) ;
V_232 = ( V_232 * V_29 -> V_116 [ V_230 ] ) /
( V_132 + 1 ) ;
V_231 = V_232 - V_29 -> V_116 [ V_229 ] / 2 ;
V_29 -> V_116 [ V_230 ] = 0 ;
V_29 -> V_116 [ V_227 ] += V_201 ;
V_29 -> V_116 [ V_229 ] += V_231 ;
V_118 += V_29 -> V_116 [ V_227 ] ;
V_29 -> V_133 += V_201 ;
if ( V_29 -> V_108 ) {
V_29 -> V_108 -> V_118 [ V_227 ] += V_201 ;
V_29 -> V_108 -> V_120 [ V_227 ] += V_231 ;
V_29 -> V_108 -> V_132 += V_201 ;
F_97 += V_29 -> V_108 -> V_118 [ V_227 ] ;
}
}
if ( V_118 > V_196 ) {
V_196 = V_118 ;
V_221 = V_112 ;
}
if ( F_97 > V_223 ) {
V_223 = F_97 ;
V_222 = V_112 ;
}
}
F_149 ( V_29 , V_224 [ 0 ] , V_224 [ 1 ] ) ;
if ( V_29 -> V_108 ) {
F_146 ( V_29 -> V_108 ) ;
F_159 ( V_225 ) ;
V_221 = F_152 ( V_29 , V_222 ) ;
}
if ( V_196 ) {
if ( V_221 != V_29 -> V_106 )
F_139 ( V_29 , V_221 ) ;
if ( F_92 ( V_29 ) != V_29 -> V_106 )
F_143 ( V_29 ) ;
}
}
static inline int F_160 ( struct V_108 * V_30 )
{
return F_161 ( & V_30 -> V_236 ) ;
}
static inline void F_162 ( struct V_108 * V_30 )
{
if ( F_163 ( & V_30 -> V_236 ) )
F_164 ( V_30 , V_237 ) ;
}
static void F_165 ( struct V_26 * V_29 , int V_238 , int V_179 ,
int * V_113 )
{
struct V_108 * V_30 , * V_239 ;
struct V_26 * V_240 ;
bool V_241 = false ;
int V_147 = F_166 ( V_238 ) ;
int V_242 ;
if ( F_14 ( ! V_29 -> V_108 ) ) {
unsigned int V_243 = sizeof( struct V_108 ) +
4 * V_115 *sizeof( unsigned long ) ;
V_30 = F_167 ( V_243 , V_244 | V_245 ) ;
if ( ! V_30 )
return;
F_168 ( & V_30 -> V_236 , 1 ) ;
F_169 ( & V_30 -> V_178 ) ;
V_30 -> V_109 = V_29 -> V_142 ;
V_30 -> V_120 = V_30 -> V_118 + V_114 *
V_115 ;
F_147 ( F_92 ( V_141 ) , V_30 -> V_143 ) ;
for ( V_242 = 0 ; V_242 < V_246 * V_115 ; V_242 ++ )
V_30 -> V_118 [ V_242 ] = V_29 -> V_116 [ V_242 ] ;
V_30 -> V_132 = V_29 -> V_133 ;
V_30 -> V_247 ++ ;
F_170 ( V_29 -> V_108 , V_30 ) ;
}
F_124 () ;
V_240 = F_88 ( F_114 ( V_147 ) -> V_45 ) ;
if ( ! F_110 ( V_240 , V_238 ) )
goto V_248;
V_30 = F_136 ( V_240 -> V_108 ) ;
if ( ! V_30 )
goto V_248;
V_239 = V_29 -> V_108 ;
if ( V_30 == V_239 )
goto V_248;
if ( V_239 -> V_247 > V_30 -> V_247 )
goto V_248;
if ( V_239 -> V_247 == V_30 -> V_247 && V_239 > V_30 )
goto V_248;
if ( V_240 -> V_96 == V_141 -> V_96 )
V_241 = true ;
if ( V_179 & V_249 )
V_241 = true ;
* V_113 = ! V_241 ;
if ( V_241 && ! F_160 ( V_30 ) )
goto V_248;
F_132 () ;
if ( ! V_241 )
return;
F_171 ( F_172 () ) ;
F_173 ( & V_239 -> V_178 , & V_30 -> V_178 ) ;
for ( V_242 = 0 ; V_242 < V_246 * V_115 ; V_242 ++ ) {
V_239 -> V_118 [ V_242 ] -= V_29 -> V_116 [ V_242 ] ;
V_30 -> V_118 [ V_242 ] += V_29 -> V_116 [ V_242 ] ;
}
V_239 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_132 += V_29 -> V_133 ;
V_239 -> V_247 -- ;
V_30 -> V_247 ++ ;
F_174 ( & V_239 -> V_178 ) ;
F_159 ( & V_30 -> V_178 ) ;
F_170 ( V_29 -> V_108 , V_30 ) ;
F_162 ( V_239 ) ;
return;
V_248:
F_132 () ;
return;
}
void F_175 ( struct V_26 * V_29 )
{
struct V_108 * V_30 = V_29 -> V_108 ;
void * V_116 = V_29 -> V_116 ;
unsigned long V_179 ;
int V_242 ;
if ( V_30 ) {
F_176 ( & V_30 -> V_178 , V_179 ) ;
for ( V_242 = 0 ; V_242 < V_246 * V_115 ; V_242 ++ )
V_30 -> V_118 [ V_242 ] -= V_29 -> V_116 [ V_242 ] ;
V_30 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_247 -- ;
F_177 ( & V_30 -> V_178 , V_179 ) ;
F_178 ( V_29 -> V_108 , NULL ) ;
F_162 ( V_30 ) ;
}
V_29 -> V_116 = NULL ;
F_179 ( V_116 ) ;
}
void F_180 ( int V_139 , int V_250 , int V_251 , int V_179 )
{
struct V_26 * V_29 = V_141 ;
bool V_252 = V_179 & V_253 ;
int V_254 = F_92 ( V_141 ) ;
int V_204 = ! ! ( V_179 & V_255 ) ;
int V_113 ;
if ( ! V_256 )
return;
if ( ! V_29 -> V_96 )
return;
if ( F_14 ( ! V_29 -> V_116 ) ) {
int V_243 = sizeof( * V_29 -> V_116 ) *
V_257 * V_115 ;
V_29 -> V_116 = F_167 ( V_243 , V_244 | V_245 ) ;
if ( ! V_29 -> V_116 )
return;
V_29 -> V_133 = 0 ;
memset ( V_29 -> V_203 , 0 , sizeof( V_29 -> V_203 ) ) ;
}
if ( F_14 ( V_139 == ( - 1 & V_258 ) ) ) {
V_113 = 1 ;
} else {
V_113 = F_110 ( V_29 , V_139 ) ;
if ( ! V_113 && ! ( V_179 & V_259 ) )
F_165 ( V_29 , V_139 , V_179 , & V_113 ) ;
}
if ( ! V_113 && ! V_204 && V_29 -> V_108 &&
F_111 ( V_254 , V_29 -> V_108 -> V_143 ) &&
F_111 ( V_250 , V_29 -> V_108 -> V_143 ) )
V_204 = 1 ;
F_156 ( V_29 ) ;
if ( F_181 ( V_195 , V_29 -> V_194 ) )
F_143 ( V_29 ) ;
if ( V_252 )
V_29 -> V_260 += V_251 ;
if ( V_179 & V_261 )
V_29 -> V_203 [ 2 ] += V_251 ;
V_29 -> V_116 [ F_95 ( V_233 , V_250 , V_113 ) ] += V_251 ;
V_29 -> V_116 [ F_95 ( V_235 , V_254 , V_113 ) ] += V_251 ;
V_29 -> V_203 [ V_204 ] += V_251 ;
}
static void F_182 ( struct V_26 * V_29 )
{
F_88 ( V_29 -> V_96 -> V_226 ) ++ ;
V_29 -> V_96 -> V_262 = 0 ;
}
void F_183 ( struct V_263 * V_264 )
{
unsigned long V_265 , V_266 , V_81 = V_195 ;
struct V_26 * V_29 = V_141 ;
struct V_267 * V_96 = V_29 -> V_96 ;
struct V_268 * V_269 ;
unsigned long V_270 , V_271 ;
unsigned long V_272 = 0 ;
long V_251 ;
F_20 ( V_29 != F_22 ( V_264 , struct V_26 , V_273 ) ) ;
V_264 -> V_58 = V_264 ;
if ( V_29 -> V_179 & V_180 )
return;
if ( ! V_96 -> V_206 ) {
V_96 -> V_206 = V_81 +
F_145 ( V_274 ) ;
}
V_265 = V_96 -> V_206 ;
if ( F_184 ( V_81 , V_265 ) )
return;
if ( V_29 -> V_191 == 0 ) {
V_29 -> V_205 = F_90 ( V_29 ) ;
V_29 -> V_191 = F_87 ( V_29 ) ;
}
V_266 = V_81 + F_145 ( V_29 -> V_191 ) ;
if ( F_185 ( & V_96 -> V_206 , V_265 , V_266 ) != V_265 )
return;
V_29 -> V_275 += 2 * V_276 ;
V_270 = V_96 -> V_262 ;
V_251 = V_94 ;
V_251 <<= 20 - V_95 ;
if ( ! V_251 )
return;
F_186 ( & V_96 -> V_277 ) ;
V_269 = F_187 ( V_96 , V_270 ) ;
if ( ! V_269 ) {
F_182 ( V_29 ) ;
V_270 = 0 ;
V_269 = V_96 -> V_278 ;
}
for (; V_269 ; V_269 = V_269 -> V_279 ) {
if ( ! F_188 ( V_269 ) || ! F_189 ( V_269 ) ||
F_190 ( V_269 ) || ( V_269 -> V_280 & V_281 ) ) {
continue;
}
if ( ! V_269 -> V_282 ||
( V_269 -> V_283 && ( V_269 -> V_280 & ( V_284 | V_285 ) ) == ( V_284 ) ) )
continue;
if ( ! ( V_269 -> V_280 & ( V_284 | V_286 | V_285 ) ) )
continue;
do {
V_270 = F_69 ( V_270 , V_269 -> V_287 ) ;
V_271 = F_191 ( V_270 + ( V_251 << V_95 ) , V_288 ) ;
V_271 = F_144 ( V_271 , V_269 -> V_289 ) ;
V_272 += F_192 ( V_269 , V_270 , V_271 ) ;
if ( V_272 )
V_251 -= ( V_271 - V_270 ) >> V_95 ;
V_270 = V_271 ;
if ( V_251 <= 0 )
goto V_290;
F_193 () ;
} while ( V_271 != V_269 -> V_289 );
}
V_290:
if ( V_269 )
V_96 -> V_262 = V_270 ;
else
F_182 ( V_29 ) ;
F_194 ( & V_96 -> V_277 ) ;
}
void F_195 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_263 * V_264 = & V_45 -> V_273 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_179 & V_180 ) || V_264 -> V_58 != V_264 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_191 * V_291 ;
if ( V_81 - V_45 -> V_275 > V_73 ) {
if ( ! V_45 -> V_275 )
V_45 -> V_191 = F_87 ( V_45 ) ;
V_45 -> V_275 += V_73 ;
if ( ! F_184 ( V_195 , V_45 -> V_96 -> V_206 ) ) {
F_196 ( V_264 , F_183 ) ;
F_197 ( V_45 , V_264 , true ) ;
}
}
}
static void F_195 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_91 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_93 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_198 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_199
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_91 ( V_24 , F_18 ( V_28 ) ) ;
F_200 ( & V_28 -> V_292 , & V_24 -> V_293 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_201 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_93 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_202 ( & V_28 -> V_292 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_203 ( struct V_294 * V_33 , struct V_25 * V_25 )
{
long V_295 ;
V_295 = F_204 ( & V_33 -> V_296 ) ;
V_295 -= V_25 -> V_297 ;
V_295 += V_25 -> V_70 . V_4 ;
return V_295 ;
}
static long F_205 ( struct V_25 * V_25 , struct V_294 * V_33 )
{
long V_295 , V_70 , V_298 ;
V_295 = F_203 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_298 = ( V_33 -> V_298 * V_70 ) ;
if ( V_295 )
V_298 /= V_295 ;
if ( V_298 < V_299 )
V_298 = V_299 ;
if ( V_298 > V_33 -> V_298 )
V_298 = V_33 -> V_298 ;
return V_298 ;
}
static inline long F_205 ( struct V_25 * V_25 , struct V_294 * V_33 )
{
return V_33 -> V_298 ;
}
static void F_206 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_66 ( V_25 ) ;
F_201 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_198 ( V_25 , V_28 ) ;
}
static void F_207 ( struct V_25 * V_25 )
{
struct V_294 * V_33 ;
struct V_27 * V_28 ;
long V_298 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_208 ( V_25 ) )
return;
#ifndef F_199
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_298 ) )
return;
#endif
V_298 = F_205 ( V_25 , V_33 ) ;
F_206 ( F_24 ( V_28 ) , V_28 , V_298 ) ;
}
static inline void F_207 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_209 ( T_2 V_300 , T_2 V_301 )
{
unsigned int V_302 ;
if ( ! V_301 )
return V_300 ;
else if ( F_14 ( V_301 > V_303 * 63 ) )
return 0 ;
V_302 = V_301 ;
if ( F_14 ( V_302 >= V_303 ) ) {
V_300 >>= V_302 / V_303 ;
V_302 %= V_303 ;
}
V_300 *= V_304 [ V_302 ] ;
return V_300 >> 32 ;
}
static V_23 F_210 ( T_2 V_301 )
{
V_23 V_305 = 0 ;
if ( F_12 ( V_301 <= V_303 ) )
return V_306 [ V_301 ] ;
else if ( F_14 ( V_301 >= V_307 ) )
return V_308 ;
do {
V_305 /= 2 ;
V_305 += V_306 [ V_303 ] ;
V_301 -= V_303 ;
} while ( V_301 > V_303 );
V_305 = F_209 ( V_305 , V_301 ) ;
return V_305 + V_306 [ V_301 ] ;
}
static T_10 int F_211 ( T_2 V_81 , int V_147 ,
struct V_309 * V_310 ,
int V_311 ,
int V_312 )
{
T_2 V_42 , V_313 ;
V_23 V_314 ;
int V_315 , V_316 = 0 ;
unsigned long V_317 = F_212 ( NULL , V_147 ) ;
V_42 = V_81 - V_310 -> V_318 ;
if ( ( T_3 ) V_42 < 0 ) {
V_310 -> V_318 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_310 -> V_318 = V_81 ;
V_315 = V_310 -> V_80 % 1024 ;
if ( V_42 + V_315 >= 1024 ) {
V_316 = 1 ;
V_315 = 1024 - V_315 ;
if ( V_311 )
V_310 -> V_78 += V_315 ;
if ( V_312 )
V_310 -> V_79 += V_315 * V_317
>> V_319 ;
V_310 -> V_80 += V_315 ;
V_42 -= V_315 ;
V_313 = V_42 / 1024 ;
V_42 %= 1024 ;
V_310 -> V_78 = F_209 ( V_310 -> V_78 ,
V_313 + 1 ) ;
V_310 -> V_79 = F_209 ( V_310 -> V_79 ,
V_313 + 1 ) ;
V_310 -> V_80 = F_209 ( V_310 -> V_80 ,
V_313 + 1 ) ;
V_314 = F_210 ( V_313 ) ;
if ( V_311 )
V_310 -> V_78 += V_314 ;
if ( V_312 )
V_310 -> V_79 += V_314 * V_317
>> V_319 ;
V_310 -> V_80 += V_314 ;
}
if ( V_311 )
V_310 -> V_78 += V_42 ;
if ( V_312 )
V_310 -> V_79 += V_42 * V_317
>> V_319 ;
V_310 -> V_80 += V_42 ;
return V_316 ;
}
static inline T_2 F_213 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_320 = F_214 ( & V_25 -> V_321 ) ;
V_320 -= V_28 -> V_77 . V_322 ;
V_28 -> V_77 . V_322 = 0 ;
if ( ! V_320 )
return 0 ;
V_28 -> V_77 . V_323 = F_209 ( V_28 -> V_77 . V_323 , V_320 ) ;
V_28 -> V_77 . V_324 =
F_209 ( V_28 -> V_77 . V_324 , V_320 ) ;
return V_320 ;
}
static inline void F_215 ( struct V_25 * V_25 ,
int V_325 )
{
struct V_294 * V_33 = V_25 -> V_33 ;
long V_326 ;
V_326 = V_25 -> V_327 + V_25 -> V_328 ;
V_326 -= V_25 -> V_297 ;
if ( ! V_326 )
return;
if ( V_325 || abs ( V_326 ) > V_25 -> V_297 / 8 ) {
F_216 ( V_326 , & V_33 -> V_296 ) ;
V_25 -> V_297 += V_326 ;
}
}
static inline void F_217 ( struct V_309 * V_310 ,
struct V_25 * V_25 )
{
struct V_294 * V_33 = V_25 -> V_33 ;
long V_305 ;
V_305 = F_218 ( ( T_2 ) V_310 -> V_78 << V_329 ,
V_310 -> V_80 + 1 ) ;
V_305 -= V_25 -> V_330 ;
if ( abs ( V_305 ) > V_25 -> V_330 / 64 ) {
F_219 ( V_305 , & V_33 -> V_331 ) ;
V_25 -> V_330 += V_305 ;
}
}
static inline void F_220 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_294 * V_33 = V_25 -> V_33 ;
int V_331 ;
T_2 V_305 ;
V_305 = V_25 -> V_297 * V_33 -> V_298 ;
V_28 -> V_77 . V_323 = F_218 ( V_305 ,
F_204 ( & V_33 -> V_296 ) + 1 ) ;
V_331 = F_221 ( & V_33 -> V_331 ) ;
if ( V_331 < V_71 ) {
V_28 -> V_77 . V_323 *= V_331 ;
V_28 -> V_77 . V_323 >>= V_329 ;
}
}
static inline void F_222 ( struct V_24 * V_24 , int V_311 )
{
F_211 ( F_67 ( V_24 ) , F_27 ( V_24 ) , & V_24 -> V_77 ,
V_311 , V_311 ) ;
F_217 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_215 ( struct V_25 * V_25 ,
int V_325 ) {}
static inline void F_217 ( struct V_309 * V_310 ,
struct V_25 * V_25 ) {}
static inline void F_220 ( struct V_27 * V_28 ) {}
static inline void F_222 ( struct V_24 * V_24 , int V_311 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_305 ;
V_305 = V_28 -> V_77 . V_78 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_305 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_323 = F_223 ( V_305 ) ;
}
static long F_224 ( struct V_27 * V_28 )
{
long V_332 = V_28 -> V_77 . V_323 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_217 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_220 ( V_28 ) ;
}
return V_28 -> V_77 . V_323 - V_332 ;
}
static inline void F_65 ( struct V_27 * V_28 )
{
V_23 V_305 ;
V_305 = V_28 -> V_77 . V_79 * F_13 ( V_333 ) ;
V_305 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_324 = F_223 ( V_305 ) ;
}
static long F_225 ( struct V_27 * V_28 )
{
long V_332 = V_28 -> V_77 . V_324 ;
if ( F_21 ( V_28 ) )
F_65 ( V_28 ) ;
else
V_28 -> V_77 . V_324 =
F_25 ( V_28 ) -> V_334 ;
return V_28 -> V_77 . V_324 - V_332 ;
}
static inline void F_226 ( struct V_25 * V_25 ,
long V_335 )
{
if ( F_12 ( V_335 < V_25 -> V_328 ) )
V_25 -> V_328 -= V_335 ;
else
V_25 -> V_328 = 0 ;
}
static inline void F_227 ( struct V_27 * V_28 ,
int V_336 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_337 , V_338 ;
int V_147 = F_27 ( F_17 ( V_25 ) ) ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_228 ( V_25 ) ;
else
V_81 = F_228 ( F_25 ( V_28 ) ) ;
if ( ! F_211 ( V_81 , V_147 , & V_28 -> V_77 , V_28 -> V_76 ,
V_25 -> V_45 == V_28 ) )
return;
V_337 = F_224 ( V_28 ) ;
V_338 = F_225 ( V_28 ) ;
if ( ! V_336 )
return;
if ( V_28 -> V_76 ) {
V_25 -> V_327 += V_337 ;
V_25 -> V_334 += V_338 ;
} else {
F_226 ( V_25 , - V_337 ) ;
}
}
static void F_30 ( struct V_25 * V_25 , int V_325 )
{
T_2 V_81 = F_228 ( V_25 ) >> 20 ;
T_2 V_320 ;
V_320 = V_81 - V_25 -> V_339 ;
if ( ! V_320 && ! V_325 )
return;
if ( F_204 ( & V_25 -> V_340 ) ) {
unsigned long V_340 ;
V_340 = F_229 ( & V_25 -> V_340 , 0 ) ;
F_226 ( V_25 , V_340 ) ;
}
if ( V_320 ) {
V_25 -> V_328 = F_209 ( V_25 -> V_328 ,
V_320 ) ;
F_230 ( V_320 , & V_25 -> V_321 ) ;
V_25 -> V_339 = V_81 ;
}
F_215 ( V_25 , V_325 ) ;
}
static inline void F_231 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_341 )
{
if ( F_14 ( V_28 -> V_77 . V_322 <= 0 ) ) {
V_28 -> V_77 . V_318 = F_67 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_322 ) {
V_28 -> V_77 . V_318 -= ( - V_28 -> V_77 . V_322 )
<< 20 ;
F_227 ( V_28 , 0 ) ;
V_28 -> V_77 . V_322 = 0 ;
}
V_341 = 0 ;
} else {
F_213 ( V_28 ) ;
}
if ( V_341 ) {
F_226 ( V_25 , V_28 -> V_77 . V_323 ) ;
F_227 ( V_28 , 0 ) ;
}
V_25 -> V_327 += V_28 -> V_77 . V_323 ;
V_25 -> V_334 += V_28 -> V_77 . V_324 ;
F_30 ( V_25 , ! V_341 ) ;
}
static inline void F_232 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_342 )
{
F_227 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_342 ) ;
V_25 -> V_327 -= V_28 -> V_77 . V_323 ;
V_25 -> V_334 -= V_28 -> V_77 . V_324 ;
if ( V_342 ) {
V_25 -> V_328 += V_28 -> V_77 . V_323 ;
V_28 -> V_77 . V_322 = F_214 ( & V_25 -> V_321 ) ;
}
}
void F_233 ( struct V_24 * V_343 )
{
F_222 ( V_343 , 1 ) ;
}
void F_234 ( struct V_24 * V_343 )
{
F_222 ( V_343 , 0 ) ;
}
static inline void F_227 ( struct V_27 * V_28 ,
int V_336 ) {}
static inline void F_222 ( struct V_24 * V_24 , int V_311 ) {}
static inline void F_231 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_341 ) {}
static inline void F_232 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_342 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_325 ) {}
static inline int F_235 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_236 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_80
struct V_26 * V_240 = NULL ;
if ( F_21 ( V_28 ) )
V_240 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_344 ) {
T_2 V_42 = F_77 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_344 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_345 ) )
V_28 -> V_83 . V_345 = V_42 ;
V_28 -> V_83 . V_344 = 0 ;
V_28 -> V_83 . V_346 += V_42 ;
if ( V_240 ) {
F_237 ( V_240 , V_42 >> 10 , 1 ) ;
F_238 ( V_240 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_347 ) {
T_2 V_42 = F_77 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_347 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_348 ) )
V_28 -> V_83 . V_348 = V_42 ;
V_28 -> V_83 . V_347 = 0 ;
V_28 -> V_83 . V_346 += V_42 ;
if ( V_240 ) {
if ( V_240 -> V_349 ) {
V_28 -> V_83 . V_350 += V_42 ;
V_28 -> V_83 . V_351 ++ ;
F_239 ( V_240 , V_42 ) ;
}
F_240 ( V_240 , V_42 ) ;
if ( F_14 ( V_352 == V_353 ) ) {
F_241 ( V_353 ,
( void * ) F_242 ( V_240 ) ,
V_42 >> 20 ) ;
}
F_237 ( V_240 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_243 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_354 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_354 < 0 )
V_354 = - V_354 ;
if ( V_354 > 3 * V_68 )
F_244 ( V_25 , V_355 ) ;
#endif
}
static void
F_245 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_356 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_356 && F_246 ( V_357 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_356 ) {
unsigned long V_358 = V_68 ;
if ( F_246 ( V_359 ) )
V_358 >>= 1 ;
V_41 -= V_358 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_247 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_179 )
{
if ( ! ( V_179 & V_360 ) || ( V_179 & V_361 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_66 ( V_25 ) ;
F_231 ( V_25 , V_28 , V_179 & V_360 ) ;
F_198 ( V_25 , V_28 ) ;
F_207 ( V_25 ) ;
if ( V_179 & V_360 ) {
F_245 ( V_25 , V_28 , 0 ) ;
F_236 ( V_25 , V_28 ) ;
}
F_78 ( V_25 , V_28 ) ;
F_243 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_248 ( V_25 ) ;
}
}
static void F_249 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_250 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_251 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_362 != V_28 )
break;
V_25 -> V_362 = NULL ;
}
}
static void F_252 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_249 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_250 ( V_28 ) ;
if ( V_25 -> V_362 == V_28 )
F_251 ( V_28 ) ;
}
static void
F_253 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_179 )
{
F_66 ( V_25 ) ;
F_232 ( V_25 , V_28 , V_179 & V_363 ) ;
F_82 ( V_25 , V_28 ) ;
if ( V_179 & V_363 ) {
#ifdef F_80
if ( F_21 ( V_28 ) ) {
struct V_26 * V_240 = F_18 ( V_28 ) ;
if ( V_240 -> V_364 & V_365 )
V_28 -> V_83 . V_344 = F_77 ( F_17 ( V_25 ) ) ;
if ( V_240 -> V_364 & V_366 )
V_28 -> V_83 . V_347 = F_77 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_252 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_201 ( V_25 , V_28 ) ;
if ( ! ( V_179 & V_363 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_254 ( V_25 ) ;
F_40 ( V_25 ) ;
F_207 ( V_25 ) ;
}
static void
F_255 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_367 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_367 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_368 ;
if ( V_19 > V_367 ) {
F_256 ( F_17 ( V_25 ) ) ;
F_252 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_367 )
F_256 ( F_17 ( V_25 ) ) ;
}
static void
F_257 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_79 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
F_227 ( V_28 , 1 ) ;
}
F_83 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_80
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_369 = F_69 ( V_28 -> V_83 . V_369 ,
V_28 -> V_85 - V_28 -> V_368 ) ;
}
#endif
V_28 -> V_368 = V_28 -> V_85 ;
}
static struct V_27 *
F_258 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_362 == V_28 ) {
struct V_27 * V_370 ;
if ( V_28 == V_45 ) {
V_370 = F_50 ( V_25 ) ;
} else {
V_370 = F_51 ( V_28 ) ;
if ( ! V_370 || ( V_45 && F_39 ( V_45 , V_370 ) ) )
V_370 = V_45 ;
}
if ( V_370 && F_259 ( V_370 , V_57 ) < 1 )
V_28 = V_370 ;
}
if ( V_25 -> V_59 && F_259 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_259 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_252 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_260 ( struct V_25 * V_25 , struct V_27 * V_371 )
{
if ( V_371 -> V_76 )
F_66 ( V_25 ) ;
F_261 ( V_25 ) ;
F_243 ( V_25 , V_371 ) ;
if ( V_371 -> V_76 ) {
F_76 ( V_25 , V_371 ) ;
F_44 ( V_25 , V_371 ) ;
F_227 ( V_371 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_262 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_372 )
{
F_66 ( V_25 ) ;
F_227 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_207 ( V_25 ) ;
#ifdef F_263
if ( V_372 ) {
F_256 ( F_17 ( V_25 ) ) ;
return;
}
if ( ! F_246 ( V_373 ) &&
F_264 ( & F_17 ( V_25 ) -> V_374 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_255 ( V_25 , V_45 ) ;
}
static inline bool F_265 ( void )
{
return F_266 ( & V_375 ) ;
}
void F_267 ( void )
{
F_268 ( & V_375 ) ;
}
void F_269 ( void )
{
F_270 ( & V_375 ) ;
}
static bool F_265 ( void )
{
return true ;
}
void F_267 ( void ) {}
void F_269 ( void ) {}
static inline T_2 F_271 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_272 ( void )
{
return ( T_2 ) V_376 * V_377 ;
}
void F_273 ( struct V_378 * V_379 )
{
T_2 V_81 ;
if ( V_379 -> V_380 == V_381 )
return;
V_81 = F_274 ( F_275 () ) ;
V_379 -> V_210 = V_379 -> V_380 ;
V_379 -> V_382 = V_81 + F_276 ( V_379 -> V_73 ) ;
}
static inline struct V_378 * F_277 ( struct V_294 * V_33 )
{
return & V_33 -> V_378 ;
}
static inline T_2 F_228 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_383 ) )
return V_25 -> V_384 ;
return F_67 ( F_17 ( V_25 ) ) - V_25 -> V_385 ;
}
static int F_278 ( struct V_25 * V_25 )
{
struct V_294 * V_33 = V_25 -> V_33 ;
struct V_378 * V_379 = F_277 ( V_33 ) ;
T_2 V_386 = 0 , V_387 , V_388 ;
V_387 = F_272 () - V_25 -> V_389 ;
F_279 ( & V_379 -> V_178 ) ;
if ( V_379 -> V_380 == V_381 )
V_386 = V_387 ;
else {
if ( ! V_379 -> V_390 ) {
F_273 ( V_379 ) ;
F_280 ( V_379 , false ) ;
}
if ( V_379 -> V_210 > 0 ) {
V_386 = F_144 ( V_379 -> V_210 , V_387 ) ;
V_379 -> V_210 -= V_386 ;
V_379 -> V_391 = 0 ;
}
}
V_388 = V_379 -> V_382 ;
F_281 ( & V_379 -> V_178 ) ;
V_25 -> V_389 += V_386 ;
if ( ( T_3 ) ( V_388 - V_25 -> V_382 ) > 0 )
V_25 -> V_382 = V_388 ;
return V_25 -> V_389 > 0 ;
}
static void F_282 ( struct V_25 * V_25 )
{
struct V_378 * V_379 = F_277 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_77 ( F_17 ( V_25 ) ) - V_25 -> V_382 ) < 0 ) )
return;
if ( V_25 -> V_389 < 0 )
return;
if ( V_25 -> V_382 != V_379 -> V_382 ) {
V_25 -> V_382 += V_276 ;
} else {
V_25 -> V_389 = 0 ;
}
}
static void F_283 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_389 -= V_19 ;
F_282 ( V_25 ) ;
if ( F_12 ( V_25 -> V_389 > 0 ) )
return;
if ( ! F_278 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_256 ( F_17 ( V_25 ) ) ;
}
static T_10
void F_74 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_265 () || ! V_25 -> V_392 )
return;
F_283 ( V_25 , V_19 ) ;
}
static inline int F_284 ( struct V_25 * V_25 )
{
return F_265 () && V_25 -> V_393 ;
}
static inline int F_208 ( struct V_25 * V_25 )
{
return F_265 () && V_25 -> V_383 ;
}
static inline int F_285 ( struct V_294 * V_33 ,
int V_174 , int V_394 )
{
struct V_25 * V_395 , * V_396 ;
V_395 = V_33 -> V_25 [ V_174 ] ;
V_396 = V_33 -> V_25 [ V_394 ] ;
return F_208 ( V_395 ) ||
F_208 ( V_396 ) ;
}
static int F_286 ( struct V_294 * V_33 , void * V_397 )
{
struct V_24 * V_24 = V_397 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_383 -- ;
#ifdef F_199
if ( ! V_25 -> V_383 ) {
V_25 -> V_385 += F_67 ( V_24 ) -
V_25 -> V_384 ;
}
#endif
return 0 ;
}
static int F_287 ( struct V_294 * V_33 , void * V_397 )
{
struct V_24 * V_24 = V_397 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_383 )
V_25 -> V_384 = F_67 ( V_24 ) ;
V_25 -> V_383 ++ ;
return 0 ;
}
static void F_288 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_378 * V_379 = F_277 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_398 , V_399 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_124 () ;
F_289 ( V_25 -> V_33 , F_287 , V_400 , ( void * ) V_24 ) ;
F_132 () ;
V_398 = V_25 -> V_401 ;
F_61 (se) {
struct V_25 * V_402 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_399 )
F_253 ( V_402 , V_28 , V_363 ) ;
V_402 -> V_401 -= V_398 ;
if ( V_402 -> V_70 . V_4 )
V_399 = 0 ;
}
if ( ! V_28 )
F_290 ( V_24 , V_398 ) ;
V_25 -> V_393 = 1 ;
V_25 -> V_403 = F_77 ( V_24 ) ;
F_279 ( & V_379 -> V_178 ) ;
F_28 ( & V_25 -> V_404 , & V_379 -> V_405 ) ;
if ( ! V_379 -> V_390 )
F_280 ( V_379 , false ) ;
F_281 ( & V_379 -> V_178 ) ;
}
void F_291 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_378 * V_379 = F_277 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_406 = 1 ;
long V_398 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_393 = 0 ;
F_292 ( V_24 ) ;
F_279 ( & V_379 -> V_178 ) ;
V_379 -> V_407 += F_77 ( V_24 ) - V_25 -> V_403 ;
F_32 ( & V_25 -> V_404 ) ;
F_281 ( & V_379 -> V_178 ) ;
F_289 ( V_25 -> V_33 , V_400 , F_286 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_398 = V_25 -> V_401 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_406 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_406 )
F_247 ( V_25 , V_28 , V_360 ) ;
V_25 -> V_401 += V_398 ;
if ( F_284 ( V_25 ) )
break;
}
if ( ! V_28 )
F_293 ( V_24 , V_398 ) ;
if ( V_24 -> V_45 == V_24 -> V_391 && V_24 -> V_40 . V_72 )
F_256 ( V_24 ) ;
}
static T_2 F_294 ( struct V_378 * V_379 ,
T_2 V_408 , T_2 V_388 )
{
struct V_25 * V_25 ;
T_2 V_210 ;
T_2 V_409 = V_408 ;
F_124 () ;
F_295 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_279 ( & V_24 -> V_178 ) ;
if ( ! F_284 ( V_25 ) )
goto V_58;
V_210 = - V_25 -> V_389 + 1 ;
if ( V_210 > V_408 )
V_210 = V_408 ;
V_408 -= V_210 ;
V_25 -> V_389 += V_210 ;
V_25 -> V_382 = V_388 ;
if ( V_25 -> V_389 > 0 )
F_291 ( V_25 ) ;
V_58:
F_281 ( & V_24 -> V_178 ) ;
if ( ! V_408 )
break;
}
F_132 () ;
return V_409 - V_408 ;
}
static int F_296 ( struct V_378 * V_379 , int V_410 )
{
T_2 V_210 , V_382 ;
int V_393 ;
if ( V_379 -> V_380 == V_381 )
goto V_411;
V_393 = ! F_297 ( & V_379 -> V_405 ) ;
V_379 -> V_412 += V_410 ;
if ( V_379 -> V_391 && ! V_393 )
goto V_411;
V_379 -> V_390 = 1 ;
F_273 ( V_379 ) ;
if ( ! V_393 ) {
V_379 -> V_391 = 1 ;
return 0 ;
}
V_379 -> V_413 += V_410 ;
V_382 = V_379 -> V_382 ;
while ( V_393 && V_379 -> V_210 > 0 ) {
V_210 = V_379 -> V_210 ;
F_281 ( & V_379 -> V_178 ) ;
V_210 = F_294 ( V_379 , V_210 ,
V_382 ) ;
F_279 ( & V_379 -> V_178 ) ;
V_393 = ! F_297 ( & V_379 -> V_405 ) ;
V_379 -> V_210 -= F_144 ( V_210 , V_379 -> V_210 ) ;
}
V_379 -> V_391 = 0 ;
return 0 ;
V_411:
V_379 -> V_390 = 0 ;
return 1 ;
}
static int F_298 ( struct V_378 * V_379 , T_2 V_414 )
{
struct V_415 * V_416 = & V_379 -> V_417 ;
T_2 V_408 ;
if ( F_299 ( V_416 ) )
return 1 ;
V_408 = F_276 ( F_300 ( V_416 ) ) ;
if ( V_408 < V_414 )
return 1 ;
return 0 ;
}
static void F_301 ( struct V_378 * V_379 )
{
T_2 V_418 = V_419 + V_420 ;
if ( F_298 ( V_379 , V_418 ) )
return;
F_302 ( & V_379 -> V_421 ,
F_303 ( V_419 ) ) ;
}
static void F_304 ( struct V_25 * V_25 )
{
struct V_378 * V_379 = F_277 ( V_25 -> V_33 ) ;
T_3 V_422 = V_25 -> V_389 - V_423 ;
if ( V_422 <= 0 )
return;
F_279 ( & V_379 -> V_178 ) ;
if ( V_379 -> V_380 != V_381 &&
V_25 -> V_382 == V_379 -> V_382 ) {
V_379 -> V_210 += V_422 ;
if ( V_379 -> V_210 > F_272 () &&
! F_297 ( & V_379 -> V_405 ) )
F_301 ( V_379 ) ;
}
F_281 ( & V_379 -> V_178 ) ;
V_25 -> V_389 -= V_422 ;
}
static T_10 void F_254 ( struct V_25 * V_25 )
{
if ( ! F_265 () )
return;
if ( ! V_25 -> V_392 || V_25 -> V_72 )
return;
F_304 ( V_25 ) ;
}
static void F_305 ( struct V_378 * V_379 )
{
T_2 V_210 = 0 , V_75 = F_272 () ;
T_2 V_388 ;
F_279 ( & V_379 -> V_178 ) ;
if ( F_298 ( V_379 , V_420 ) ) {
F_281 ( & V_379 -> V_178 ) ;
return;
}
if ( V_379 -> V_380 != V_381 && V_379 -> V_210 > V_75 )
V_210 = V_379 -> V_210 ;
V_388 = V_379 -> V_382 ;
F_281 ( & V_379 -> V_178 ) ;
if ( ! V_210 )
return;
V_210 = F_294 ( V_379 , V_210 , V_388 ) ;
F_279 ( & V_379 -> V_178 ) ;
if ( V_388 == V_379 -> V_382 )
V_379 -> V_210 -= F_144 ( V_210 , V_379 -> V_210 ) ;
F_281 ( & V_379 -> V_178 ) ;
}
static void F_248 ( struct V_25 * V_25 )
{
if ( ! F_265 () )
return;
if ( ! V_25 -> V_392 || V_25 -> V_45 )
return;
if ( F_284 ( V_25 ) )
return;
F_74 ( V_25 , 0 ) ;
if ( V_25 -> V_389 <= 0 )
F_288 ( V_25 ) ;
}
static bool F_261 ( struct V_25 * V_25 )
{
if ( ! F_265 () )
return false ;
if ( F_12 ( ! V_25 -> V_392 || V_25 -> V_389 > 0 ) )
return false ;
if ( F_284 ( V_25 ) )
return true ;
F_288 ( V_25 ) ;
return true ;
}
static enum V_424 F_306 ( struct V_415 * V_425 )
{
struct V_378 * V_379 =
F_22 ( V_425 , struct V_378 , V_421 ) ;
F_305 ( V_379 ) ;
return V_426 ;
}
static enum V_424 F_307 ( struct V_415 * V_425 )
{
struct V_378 * V_379 =
F_22 ( V_425 , struct V_378 , V_417 ) ;
T_11 V_81 ;
int V_410 ;
int V_391 = 0 ;
F_279 ( & V_379 -> V_178 ) ;
for (; ; ) {
V_81 = F_308 ( V_425 ) ;
V_410 = F_309 ( V_425 , V_81 , V_379 -> V_73 ) ;
if ( ! V_410 )
break;
V_391 = F_296 ( V_379 , V_410 ) ;
}
F_281 ( & V_379 -> V_178 ) ;
return V_391 ? V_426 : V_427 ;
}
void F_310 ( struct V_378 * V_379 )
{
F_311 ( & V_379 -> V_178 ) ;
V_379 -> V_210 = 0 ;
V_379 -> V_380 = V_381 ;
V_379 -> V_73 = F_303 ( F_271 () ) ;
F_312 ( & V_379 -> V_405 ) ;
F_313 ( & V_379 -> V_417 , V_428 , V_429 ) ;
V_379 -> V_417 . V_430 = F_307 ;
F_313 ( & V_379 -> V_421 , V_428 , V_429 ) ;
V_379 -> V_421 . V_430 = F_306 ;
}
static void F_314 ( struct V_25 * V_25 )
{
V_25 -> V_392 = 0 ;
F_312 ( & V_25 -> V_404 ) ;
}
void F_280 ( struct V_378 * V_379 , bool V_431 )
{
while ( F_14 ( F_264 ( & V_379 -> V_417 ) ) &&
F_315 ( & V_379 -> V_417 ) < 0 ) {
F_281 ( & V_379 -> V_178 ) ;
F_316 () ;
F_279 ( & V_379 -> V_178 ) ;
if ( ! V_431 && V_379 -> V_390 )
return;
}
V_379 -> V_390 = 1 ;
F_302 ( & V_379 -> V_417 , V_379 -> V_73 ) ;
}
static void F_317 ( struct V_378 * V_379 )
{
if ( ! V_379 -> V_405 . V_58 )
return;
F_318 ( & V_379 -> V_417 ) ;
F_318 ( & V_379 -> V_421 ) ;
}
static void T_12 F_319 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_320 (rq, cfs_rq) {
struct V_378 * V_379 = & V_25 -> V_33 -> V_378 ;
F_279 ( & V_379 -> V_178 ) ;
V_25 -> V_392 = V_379 -> V_380 != V_381 ;
F_281 ( & V_379 -> V_178 ) ;
}
}
static void T_12 F_321 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_320 (rq, cfs_rq) {
if ( ! V_25 -> V_392 )
continue;
V_25 -> V_389 = 1 ;
V_25 -> V_392 = 0 ;
if ( F_284 ( V_25 ) )
F_291 ( V_25 ) ;
}
}
static inline T_2 F_228 ( struct V_25 * V_25 )
{
return F_67 ( F_17 ( V_25 ) ) ;
}
static void F_74 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_261 ( struct V_25 * V_25 ) { return false ; }
static void F_248 ( struct V_25 * V_25 ) {}
static T_10 void F_254 ( struct V_25 * V_25 ) {}
static inline int F_284 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_208 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_285 ( struct V_294 * V_33 ,
int V_174 , int V_394 )
{
return 0 ;
}
void F_310 ( struct V_378 * V_379 ) {}
static void F_314 ( struct V_25 * V_25 ) {}
static inline struct V_378 * F_277 ( struct V_294 * V_33 )
{
return NULL ;
}
static inline void F_317 ( struct V_378 * V_379 ) {}
static inline void F_319 ( struct V_24 * V_24 ) {}
static inline void F_321 ( struct V_24 * V_24 ) {}
static void F_322 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_323 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_432 = V_28 -> V_85 - V_28 -> V_368 ;
T_3 V_42 = V_75 - V_432 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_256 ( V_24 ) ;
return;
}
F_324 ( V_24 , V_42 ) ;
}
}
static void F_325 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_326 ( V_24 ) || V_45 -> V_433 != & V_434 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_322 ( V_24 , V_45 ) ;
}
static inline void
F_322 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_325 ( struct V_24 * V_24 )
{
}
static void
F_327 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_179 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_247 ( V_25 , V_28 , V_179 ) ;
if ( F_284 ( V_25 ) )
break;
V_25 -> V_401 ++ ;
V_179 = V_360 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_401 ++ ;
if ( F_284 ( V_25 ) )
break;
F_207 ( V_25 ) ;
F_227 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_222 ( V_24 , V_24 -> V_72 ) ;
F_293 ( V_24 , 1 ) ;
}
F_325 ( V_24 ) ;
}
static void F_328 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_179 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_435 = V_179 & V_363 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_253 ( V_25 , V_28 , V_179 ) ;
if ( F_284 ( V_25 ) )
break;
V_25 -> V_401 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_435 && F_34 ( V_28 ) )
F_329 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_179 |= V_363 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_401 -- ;
if ( F_284 ( V_25 ) )
break;
F_207 ( V_25 ) ;
F_227 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_290 ( V_24 , 1 ) ;
F_222 ( V_24 , 1 ) ;
}
F_325 ( V_24 ) ;
}
static unsigned long F_115 ( const int V_147 )
{
return F_114 ( V_147 ) -> V_40 . V_327 ;
}
static unsigned long F_330 ( int V_147 , int type )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
unsigned long V_436 = F_115 ( V_147 ) ;
if ( type == 0 || ! F_246 ( V_437 ) )
return V_436 ;
return F_144 ( V_24 -> V_438 [ type - 1 ] , V_436 ) ;
}
static unsigned long F_331 ( int V_147 , int type )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
unsigned long V_436 = F_115 ( V_147 ) ;
if ( type == 0 || ! F_246 ( V_437 ) )
return V_436 ;
return F_69 ( V_24 -> V_438 [ type - 1 ] , V_436 ) ;
}
static unsigned long F_116 ( int V_147 )
{
return F_114 ( V_147 ) -> V_439 ;
}
static unsigned long F_332 ( int V_147 )
{
return F_114 ( V_147 ) -> V_440 ;
}
static unsigned long F_333 ( int V_147 )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
unsigned long V_72 = F_88 ( V_24 -> V_40 . V_401 ) ;
unsigned long V_296 = V_24 -> V_40 . V_327 ;
if ( V_72 )
return V_296 / V_72 ;
return 0 ;
}
static void F_334 ( struct V_26 * V_29 )
{
if ( F_181 ( V_195 , V_141 -> V_441 + V_193 ) ) {
V_141 -> V_442 >>= 1 ;
V_141 -> V_441 = V_195 ;
}
if ( V_141 -> V_443 != V_29 ) {
V_141 -> V_443 = V_29 ;
V_141 -> V_442 ++ ;
}
}
static void F_335 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_336 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_334 ( V_29 ) ;
}
static long F_337 ( struct V_294 * V_33 , int V_147 , long V_444 , long V_445 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
if ( ! V_33 -> V_34 )
return V_444 ;
F_61 (se) {
long V_7 , V_446 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_446 = V_445 + F_203 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_444 ;
if ( V_446 > 0 && V_7 < V_446 )
V_444 = ( V_7 * ( long ) V_33 -> V_298 ) / V_446 ;
else
V_444 = V_33 -> V_298 ;
if ( V_444 < V_299 )
V_444 = V_299 ;
V_444 -= V_28 -> V_70 . V_4 ;
V_445 = 0 ;
}
return V_444 ;
}
static long F_337 ( struct V_294 * V_33 , int V_147 , long V_444 , long V_445 )
{
return V_444 ;
}
static int F_338 ( struct V_26 * V_29 )
{
int V_9 = F_339 ( V_447 ) ;
if ( V_29 -> V_442 > V_9 ) {
if ( V_141 -> V_442 > ( V_9 * V_29 -> V_442 ) )
return 1 ;
}
return 0 ;
}
static int F_340 ( struct V_184 * V_185 , struct V_26 * V_29 , int V_448 )
{
T_3 V_449 , V_70 ;
T_3 V_450 , V_451 ;
int V_452 , V_453 , V_454 ;
struct V_294 * V_33 ;
unsigned long V_4 ;
int V_455 ;
if ( F_338 ( V_29 ) )
return 0 ;
V_452 = V_185 -> V_456 ;
V_453 = F_275 () ;
V_454 = F_135 ( V_29 ) ;
V_70 = F_330 ( V_454 , V_452 ) ;
V_449 = F_331 ( V_453 , V_452 ) ;
if ( V_448 ) {
V_33 = V_294 ( V_141 ) ;
V_4 = V_141 -> V_28 . V_70 . V_4 ;
V_449 += F_337 ( V_33 , V_453 , - V_4 , - V_4 ) ;
V_70 += F_337 ( V_33 , V_454 , 0 , - V_4 ) ;
}
V_33 = V_294 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
V_450 = 100 ;
V_450 *= F_116 ( V_454 ) ;
V_451 = 100 + ( V_185 -> V_170 - 100 ) / 2 ;
V_451 *= F_116 ( V_453 ) ;
if ( V_449 > 0 ) {
V_450 *= V_449 +
F_337 ( V_33 , V_453 , V_4 , V_4 ) ;
V_451 *= V_70 + F_337 ( V_33 , V_454 , 0 , V_4 ) ;
}
V_455 = V_450 <= V_451 ;
F_244 ( V_29 , V_28 . V_83 . V_457 ) ;
if ( ! V_455 )
return 0 ;
F_244 ( V_185 , V_458 ) ;
F_244 ( V_29 , V_28 . V_83 . V_459 ) ;
return 1 ;
}
static struct V_460 *
F_341 ( struct V_184 * V_185 , struct V_26 * V_29 ,
int V_453 , int V_461 )
{
struct V_460 * V_462 = NULL , * V_119 = V_185 -> V_463 ;
unsigned long V_464 = V_465 , V_449 = 0 ;
int V_466 = V_185 -> V_467 ;
int V_468 = 100 + ( V_185 -> V_170 - 100 ) / 2 ;
if ( V_461 & V_469 )
V_466 = V_185 -> V_456 ;
do {
unsigned long V_70 , V_470 ;
int V_471 ;
int V_242 ;
if ( ! F_342 ( F_343 ( V_119 ) ,
F_129 ( V_29 ) ) )
continue;
V_471 = F_128 ( V_453 ,
F_343 ( V_119 ) ) ;
V_470 = 0 ;
F_113 (i, sched_group_cpus(group)) {
if ( V_471 )
V_70 = F_330 ( V_242 , V_466 ) ;
else
V_70 = F_331 ( V_242 , V_466 ) ;
V_470 += V_70 ;
}
V_470 = ( V_470 * V_150 ) / V_119 -> V_472 -> V_148 ;
if ( V_471 ) {
V_449 = V_470 ;
} else if ( V_470 < V_464 ) {
V_464 = V_470 ;
V_462 = V_119 ;
}
} while ( V_119 = V_119 -> V_58 , V_119 != V_185 -> V_463 );
if ( ! V_462 || 100 * V_449 < V_468 * V_464 )
return NULL ;
return V_462 ;
}
static int
F_344 ( struct V_460 * V_119 , struct V_26 * V_29 , int V_453 )
{
unsigned long V_70 , V_464 = V_465 ;
unsigned int V_473 = V_474 ;
T_2 V_475 = 0 ;
int V_476 = V_453 ;
int V_477 = - 1 ;
int V_242 ;
F_345 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_346 ( V_242 ) ) {
struct V_24 * V_24 = F_114 ( V_242 ) ;
struct V_478 * V_391 = F_347 ( V_24 ) ;
if ( V_391 && V_391 -> V_479 < V_473 ) {
V_473 = V_391 -> V_479 ;
V_475 = V_24 -> V_480 ;
V_477 = V_242 ;
} else if ( ( ! V_391 || V_391 -> V_479 == V_473 ) &&
V_24 -> V_480 > V_475 ) {
V_475 = V_24 -> V_480 ;
V_477 = V_242 ;
}
} else if ( V_477 == - 1 ) {
V_70 = F_115 ( V_242 ) ;
if ( V_70 < V_464 || ( V_70 == V_464 && V_242 == V_453 ) ) {
V_464 = V_70 ;
V_476 = V_242 ;
}
}
}
return V_477 != - 1 ? V_477 : V_476 ;
}
static int F_131 ( struct V_26 * V_29 , int V_481 )
{
struct V_184 * V_185 ;
struct V_460 * V_482 ;
int V_242 = F_135 ( V_29 ) ;
if ( F_346 ( V_481 ) )
return V_481 ;
if ( V_242 != V_481 && F_348 ( V_242 , V_481 ) && F_346 ( V_242 ) )
return V_242 ;
V_185 = F_136 ( F_137 ( V_483 , V_481 ) ) ;
F_349 (sd) {
V_482 = V_185 -> V_463 ;
do {
if ( ! F_342 ( F_343 ( V_482 ) ,
F_129 ( V_29 ) ) )
goto V_58;
F_113 (i, sched_group_cpus(sg)) {
if ( V_242 == V_481 || ! F_346 ( V_242 ) )
goto V_58;
}
V_481 = F_350 ( F_343 ( V_482 ) ,
F_129 ( V_29 ) ) ;
goto V_484;
V_58:
V_482 = V_482 -> V_58 ;
} while ( V_482 != V_185 -> V_463 );
}
V_484:
return V_481 ;
}
static int F_351 ( int V_147 )
{
unsigned long V_485 = F_114 ( V_147 ) -> V_40 . V_334 ;
unsigned long V_148 = F_332 ( V_147 ) ;
if ( V_485 >= V_333 )
return V_148 ;
return ( V_485 * V_148 ) >> V_486 ;
}
static int
F_352 ( struct V_26 * V_29 , int V_454 , int V_461 , int V_487 )
{
struct V_184 * V_488 , * V_489 = NULL , * V_185 = NULL ;
int V_147 = F_275 () ;
int V_490 = V_147 ;
int V_491 = 0 ;
int V_448 = V_487 & V_492 ;
if ( V_461 & V_469 )
V_491 = F_128 ( V_147 , F_129 ( V_29 ) ) ;
F_124 () ;
F_353 (cpu, tmp) {
if ( ! ( V_488 -> V_179 & V_493 ) )
continue;
if ( V_491 && ( V_488 -> V_179 & V_494 ) &&
F_128 ( V_454 , F_354 ( V_488 ) ) ) {
V_489 = V_488 ;
break;
}
if ( V_488 -> V_179 & V_461 )
V_185 = V_488 ;
}
if ( V_489 && V_147 != V_454 && F_340 ( V_489 , V_29 , V_448 ) )
V_454 = V_147 ;
if ( V_461 & V_469 ) {
V_490 = F_131 ( V_29 , V_454 ) ;
goto V_181;
}
while ( V_185 ) {
struct V_460 * V_119 ;
int V_4 ;
if ( ! ( V_185 -> V_179 & V_461 ) ) {
V_185 = V_185 -> V_495 ;
continue;
}
V_119 = F_341 ( V_185 , V_29 , V_147 , V_461 ) ;
if ( ! V_119 ) {
V_185 = V_185 -> V_495 ;
continue;
}
V_490 = F_344 ( V_119 , V_29 , V_147 ) ;
if ( V_490 == - 1 || V_490 == V_147 ) {
V_185 = V_185 -> V_495 ;
continue;
}
V_147 = V_490 ;
V_4 = V_185 -> V_496 ;
V_185 = NULL ;
F_353 (cpu, tmp) {
if ( V_4 <= V_488 -> V_496 )
break;
if ( V_488 -> V_179 & V_461 )
V_185 = V_488 ;
}
}
V_181:
F_132 () ;
return V_490 ;
}
static void
F_355 ( struct V_26 * V_29 , int V_497 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_322 ) {
V_28 -> V_77 . V_322 = - F_213 ( V_28 ) ;
F_216 ( V_28 -> V_77 . V_323 ,
& V_25 -> V_340 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_356 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_498 = V_499 ;
return F_58 ( V_498 , V_28 ) ;
}
static int
F_259 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_498 , V_500 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_500 <= 0 )
return - 1 ;
V_498 = F_356 ( V_45 , V_28 ) ;
if ( V_500 > V_498 )
return 1 ;
return 0 ;
}
static void F_357 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_501 == V_502 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_329 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_501 == V_502 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_358 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_362 = V_28 ;
}
static void F_359 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_487 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_503 = V_25 -> V_72 >= V_67 ;
int V_504 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_208 ( F_24 ( V_36 ) ) ) )
return;
if ( F_246 ( V_505 ) && V_503 && ! ( V_487 & V_506 ) ) {
F_329 ( V_36 ) ;
V_504 = 1 ;
}
if ( F_360 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_501 == V_502 ) &&
F_12 ( V_29 -> V_501 != V_502 ) )
goto V_507;
if ( F_14 ( V_29 -> V_501 != V_508 ) || ! F_246 ( V_509 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_66 ( F_24 ( V_28 ) ) ;
F_171 ( ! V_36 ) ;
if ( F_259 ( V_28 , V_36 ) == 1 ) {
if ( ! V_504 )
F_329 ( V_36 ) ;
goto V_507;
}
return;
V_507:
F_256 ( V_24 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_391 ) )
return;
if ( F_246 ( V_510 ) && V_503 && F_21 ( V_28 ) )
F_357 ( V_28 ) ;
}
static struct V_26 *
F_361 ( struct V_24 * V_24 , struct V_26 * V_371 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_511 ;
V_512:
#ifdef F_362
if ( ! V_25 -> V_72 )
goto V_391;
if ( V_371 -> V_433 != & V_434 )
goto V_513;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_66 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_261 ( V_25 ) ) )
goto V_513;
V_28 = F_258 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_371 != V_29 ) {
struct V_27 * V_36 = & V_371 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_260 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_257 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_260 ( V_25 , V_36 ) ;
F_257 ( V_25 , V_28 ) ;
}
if ( F_326 ( V_24 ) )
F_322 ( V_24 , V_29 ) ;
return V_29 ;
V_513:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_391;
F_363 ( V_24 , V_371 ) ;
do {
V_28 = F_258 ( V_25 , NULL ) ;
F_257 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_326 ( V_24 ) )
F_322 ( V_24 , V_29 ) ;
return V_29 ;
V_391:
V_511 = F_235 ( V_24 ) ;
if ( V_511 < 0 )
return V_514 ;
if ( V_511 > 0 )
goto V_512;
return NULL ;
}
static void F_364 ( struct V_24 * V_24 , struct V_26 * V_371 )
{
struct V_27 * V_28 = & V_371 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_260 ( V_25 , V_28 ) ;
}
}
static void F_365 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_252 ( V_25 , V_28 ) ;
if ( V_45 -> V_501 != V_515 ) {
F_292 ( V_24 ) ;
F_66 ( V_25 ) ;
F_366 ( V_24 , true ) ;
}
F_358 ( V_28 ) ;
}
static bool F_367 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_507 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_208 ( F_24 ( V_28 ) ) )
return false ;
F_329 ( V_28 ) ;
F_365 ( V_24 ) ;
return true ;
}
static int F_368 ( struct V_26 * V_29 , struct V_516 * V_154 )
{
T_3 V_42 ;
F_369 ( & V_154 -> V_173 -> V_178 ) ;
if ( V_29 -> V_433 != & V_434 )
return 0 ;
if ( F_14 ( V_29 -> V_501 == V_502 ) )
return 0 ;
if ( F_246 ( V_517 ) && V_154 -> V_175 -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_518 == - 1 )
return 1 ;
if ( V_518 == 0 )
return 0 ;
V_42 = F_67 ( V_154 -> V_173 ) - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_518 ;
}
static bool F_370 ( struct V_26 * V_29 , struct V_516 * V_154 )
{
struct V_108 * V_108 = F_136 ( V_29 -> V_108 ) ;
int V_135 , V_138 ;
if ( ! F_246 ( V_519 ) || ! V_29 -> V_116 ||
! ( V_154 -> V_185 -> V_179 & V_520 ) ) {
return false ;
}
V_135 = F_105 ( V_154 -> V_174 ) ;
V_138 = F_105 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_108 ) {
if ( F_111 ( V_135 , V_108 -> V_143 ) )
return false ;
if ( F_111 ( V_138 , V_108 -> V_143 ) )
return true ;
return F_97 ( V_29 , V_138 ) > F_97 ( V_29 , V_135 ) ;
}
if ( V_138 == V_29 -> V_106 )
return true ;
return F_96 ( V_29 , V_138 ) > F_96 ( V_29 , V_135 ) ;
}
static bool F_371 ( struct V_26 * V_29 , struct V_516 * V_154 )
{
struct V_108 * V_108 = F_136 ( V_29 -> V_108 ) ;
int V_135 , V_138 ;
if ( ! F_246 ( V_521 ) || ! F_246 ( V_522 ) )
return false ;
if ( ! V_29 -> V_116 || ! ( V_154 -> V_185 -> V_179 & V_520 ) )
return false ;
V_135 = F_105 ( V_154 -> V_174 ) ;
V_138 = F_105 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_108 ) {
if ( F_111 ( V_138 , V_108 -> V_143 ) )
return false ;
if ( F_111 ( V_135 , V_108 -> V_143 ) )
return true ;
return F_97 ( V_29 , V_138 ) < F_97 ( V_29 , V_135 ) ;
}
if ( V_135 == V_29 -> V_106 )
return true ;
return F_96 ( V_29 , V_138 ) < F_96 ( V_29 , V_135 ) ;
}
static inline bool F_370 ( struct V_26 * V_29 ,
struct V_516 * V_154 )
{
return false ;
}
static inline bool F_371 ( struct V_26 * V_29 ,
struct V_516 * V_154 )
{
return false ;
}
static
int F_372 ( struct V_26 * V_29 , struct V_516 * V_154 )
{
int V_523 = 0 ;
F_369 ( & V_154 -> V_173 -> V_178 ) ;
if ( F_285 ( V_294 ( V_29 ) , V_154 -> V_174 , V_154 -> V_136 ) )
return 0 ;
if ( ! F_128 ( V_154 -> V_136 , F_129 ( V_29 ) ) ) {
int V_147 ;
F_244 ( V_29 , V_28 . V_83 . V_524 ) ;
V_154 -> V_179 |= V_525 ;
if ( ! V_154 -> V_526 || ( V_154 -> V_179 & V_527 ) )
return 0 ;
F_345 (cpu, env->dst_grpmask, env->cpus) {
if ( F_128 ( V_147 , F_129 ( V_29 ) ) ) {
V_154 -> V_179 |= V_527 ;
V_154 -> V_528 = V_147 ;
break;
}
}
return 0 ;
}
V_154 -> V_179 &= ~ V_529 ;
if ( F_373 ( V_154 -> V_173 , V_29 ) ) {
F_244 ( V_29 , V_28 . V_83 . V_530 ) ;
return 0 ;
}
V_523 = F_368 ( V_29 , V_154 ) ;
if ( ! V_523 )
V_523 = F_371 ( V_29 , V_154 ) ;
if ( F_370 ( V_29 , V_154 ) || ! V_523 ||
V_154 -> V_185 -> V_531 > V_154 -> V_185 -> V_532 ) {
if ( V_523 ) {
F_244 ( V_154 -> V_185 , V_533 [ V_154 -> V_391 ] ) ;
F_244 ( V_29 , V_28 . V_83 . V_534 ) ;
}
return 1 ;
}
F_244 ( V_29 , V_28 . V_83 . V_535 ) ;
return 0 ;
}
static void F_374 ( struct V_26 * V_29 , struct V_516 * V_154 )
{
F_369 ( & V_154 -> V_173 -> V_178 ) ;
F_375 ( V_154 -> V_173 , V_29 , 0 ) ;
V_29 -> V_76 = V_536 ;
F_376 ( V_29 , V_154 -> V_136 ) ;
}
static struct V_26 * F_377 ( struct V_516 * V_154 )
{
struct V_26 * V_29 , * V_301 ;
F_369 ( & V_154 -> V_173 -> V_178 ) ;
F_378 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_372 ( V_29 , V_154 ) )
continue;
F_374 ( V_29 , V_154 ) ;
F_244 ( V_154 -> V_185 , V_537 [ V_154 -> V_391 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_379 ( struct V_516 * V_154 )
{
struct V_538 * V_539 = & V_154 -> V_173 -> V_293 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_540 = 0 ;
F_369 ( & V_154 -> V_173 -> V_178 ) ;
if ( V_154 -> V_468 <= 0 )
return 0 ;
while ( ! F_297 ( V_539 ) ) {
V_29 = F_380 ( V_539 , struct V_26 , V_28 . V_292 ) ;
V_154 -> V_541 ++ ;
if ( V_154 -> V_541 > V_154 -> V_542 )
break;
if ( V_154 -> V_541 > V_154 -> V_543 ) {
V_154 -> V_543 += V_544 ;
V_154 -> V_179 |= V_545 ;
break;
}
if ( ! F_372 ( V_29 , V_154 ) )
goto V_58;
V_70 = F_130 ( V_29 ) ;
if ( F_246 ( V_546 ) && V_70 < 16 && ! V_154 -> V_185 -> V_531 )
goto V_58;
if ( ( V_70 / 2 ) > V_154 -> V_468 )
goto V_58;
F_374 ( V_29 , V_154 ) ;
F_200 ( & V_29 -> V_28 . V_292 , & V_154 -> V_539 ) ;
V_540 ++ ;
V_154 -> V_468 -= V_70 ;
#ifdef F_381
if ( V_154 -> V_391 == V_547 )
break;
#endif
if ( V_154 -> V_468 <= 0 )
break;
continue;
V_58:
F_382 ( & V_29 -> V_28 . V_292 , V_539 ) ;
}
F_70 ( V_154 -> V_185 , V_537 [ V_154 -> V_391 ] , V_540 ) ;
return V_540 ;
}
static void F_383 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_369 ( & V_24 -> V_178 ) ;
F_171 ( F_36 ( V_29 ) != V_24 ) ;
V_29 -> V_76 = V_548 ;
F_384 ( V_24 , V_29 , 0 ) ;
F_385 ( V_24 , V_29 , 0 ) ;
}
static void F_386 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_279 ( & V_24 -> V_178 ) ;
F_383 ( V_24 , V_29 ) ;
F_281 ( & V_24 -> V_178 ) ;
}
static void F_387 ( struct V_516 * V_154 )
{
struct V_538 * V_539 = & V_154 -> V_539 ;
struct V_26 * V_29 ;
F_279 ( & V_154 -> V_175 -> V_178 ) ;
while ( ! F_297 ( V_539 ) ) {
V_29 = F_380 ( V_539 , struct V_26 , V_28 . V_292 ) ;
F_202 ( & V_29 -> V_28 . V_292 ) ;
F_383 ( V_154 -> V_175 , V_29 ) ;
}
F_281 ( & V_154 -> V_175 -> V_178 ) ;
}
static void F_388 ( struct V_294 * V_33 , int V_147 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_147 ] ;
if ( F_208 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_227 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_78 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_222 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_389 ( int V_147 )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
struct V_25 * V_25 ;
unsigned long V_179 ;
F_390 ( & V_24 -> V_178 , V_179 ) ;
F_292 ( V_24 ) ;
F_320 (rq, cfs_rq) {
F_388 ( V_25 -> V_33 , V_24 -> V_147 ) ;
}
F_391 ( & V_24 -> V_178 , V_179 ) ;
}
static void F_392 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_195 ;
unsigned long V_70 ;
if ( V_25 -> V_549 == V_81 )
return;
V_25 -> V_550 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_550 = V_28 ;
if ( V_25 -> V_549 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_551 = V_25 -> V_327 ;
V_25 -> V_549 = V_81 ;
}
while ( ( V_28 = V_25 -> V_550 ) != NULL ) {
V_70 = V_25 -> V_551 ;
V_70 = F_393 ( V_70 * V_28 -> V_77 . V_323 ,
V_25 -> V_327 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_551 = V_70 ;
V_25 -> V_549 = V_81 ;
}
}
static unsigned long F_130 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_392 ( V_25 ) ;
return F_393 ( V_29 -> V_28 . V_77 . V_323 * V_25 -> V_551 ,
V_25 -> V_327 + 1 ) ;
}
static inline void F_389 ( int V_147 )
{
}
static unsigned long F_130 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_323 ;
}
static inline void F_394 ( struct V_552 * V_553 )
{
* V_553 = (struct V_552 ) {
. V_554 = NULL ,
. V_204 = NULL ,
. V_555 = 0UL ,
. V_556 = 0UL ,
. V_557 = {
. V_470 = 0UL ,
. V_558 = 0 ,
. V_559 = V_560 ,
} ,
} ;
}
static inline int F_395 ( struct V_184 * V_185 ,
enum V_561 V_391 )
{
int V_466 ;
switch ( V_391 ) {
case V_562 :
V_466 = V_185 -> V_563 ;
break;
case V_547 :
V_466 = V_185 -> V_564 ;
break;
default:
V_466 = V_185 -> V_565 ;
break;
}
return V_466 ;
}
static unsigned long F_396 ( struct V_184 * V_185 , int V_147 )
{
if ( ( V_185 -> V_179 & V_566 ) && ( V_185 -> V_496 > 1 ) )
return V_185 -> V_567 / V_185 -> V_496 ;
return V_150 ;
}
unsigned long __weak F_397 ( struct V_184 * V_185 , int V_147 )
{
return F_396 ( V_185 , V_147 ) ;
}
static unsigned long F_398 ( int V_147 )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
T_2 V_436 , V_568 , V_569 , V_77 ;
T_3 V_42 ;
V_569 = F_88 ( V_24 -> V_569 ) ;
V_77 = F_88 ( V_24 -> V_570 ) ;
V_42 = F_399 ( V_24 ) - V_569 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_436 = F_400 () + V_42 ;
V_568 = F_218 ( V_77 , V_436 ) ;
if ( F_12 ( V_568 < V_150 ) )
return V_150 - V_568 ;
return 1 ;
}
static void F_401 ( struct V_184 * V_185 , int V_147 )
{
unsigned long V_148 = V_150 ;
struct V_460 * V_571 = V_185 -> V_463 ;
if ( F_246 ( V_572 ) )
V_148 *= F_397 ( V_185 , V_147 ) ;
else
V_148 *= F_396 ( V_185 , V_147 ) ;
V_148 >>= V_319 ;
F_114 ( V_147 ) -> V_440 = V_148 ;
V_148 *= F_398 ( V_147 ) ;
V_148 >>= V_319 ;
if ( ! V_148 )
V_148 = 1 ;
F_114 ( V_147 ) -> V_439 = V_148 ;
V_571 -> V_472 -> V_148 = V_148 ;
}
void F_402 ( struct V_184 * V_185 , int V_147 )
{
struct V_184 * V_495 = V_185 -> V_495 ;
struct V_460 * V_119 , * V_571 = V_185 -> V_463 ;
unsigned long V_148 ;
unsigned long V_192 ;
V_192 = F_145 ( V_185 -> V_573 ) ;
V_192 = F_150 ( V_192 , 1UL , V_574 ) ;
V_571 -> V_472 -> V_575 = V_195 + V_192 ;
if ( ! V_495 ) {
F_401 ( V_185 , V_147 ) ;
return;
}
V_148 = 0 ;
if ( V_495 -> V_179 & V_576 ) {
F_113 (cpu, sched_group_cpus(sdg)) {
struct V_577 * V_472 ;
struct V_24 * V_24 = F_114 ( V_147 ) ;
if ( F_14 ( ! V_24 -> V_185 ) ) {
V_148 += F_116 ( V_147 ) ;
continue;
}
V_472 = V_24 -> V_185 -> V_463 -> V_472 ;
V_148 += V_472 -> V_148 ;
}
} else {
V_119 = V_495 -> V_463 ;
do {
V_148 += V_119 -> V_472 -> V_148 ;
V_119 = V_119 -> V_58 ;
} while ( V_119 != V_495 -> V_463 );
}
V_571 -> V_472 -> V_148 = V_148 ;
}
static inline int
F_403 ( struct V_24 * V_24 , struct V_184 * V_185 )
{
return ( ( V_24 -> V_439 * V_185 -> V_170 ) <
( V_24 -> V_440 * 100 ) ) ;
}
static inline int F_404 ( struct V_460 * V_119 )
{
return V_119 -> V_472 -> V_468 ;
}
static inline bool
F_405 ( struct V_516 * V_154 , struct V_578 * V_579 )
{
if ( V_579 -> V_558 < V_579 -> F_103 )
return true ;
if ( ( V_579 -> V_580 * 100 ) >
( V_579 -> V_581 * V_154 -> V_185 -> V_170 ) )
return true ;
return false ;
}
static inline bool
F_406 ( struct V_516 * V_154 , struct V_578 * V_579 )
{
if ( V_579 -> V_558 <= V_579 -> F_103 )
return false ;
if ( ( V_579 -> V_580 * 100 ) <
( V_579 -> V_581 * V_154 -> V_185 -> V_170 ) )
return true ;
return false ;
}
static enum V_559 F_407 ( struct V_516 * V_154 ,
struct V_460 * V_119 ,
struct V_578 * V_579 )
{
if ( V_579 -> V_582 )
return V_583 ;
if ( F_404 ( V_119 ) )
return V_584 ;
return V_560 ;
}
static inline void F_408 ( struct V_516 * V_154 ,
struct V_460 * V_119 , int V_466 ,
int V_471 , struct V_578 * V_579 ,
bool * V_585 )
{
unsigned long V_70 ;
int V_242 ;
memset ( V_579 , 0 , sizeof( * V_579 ) ) ;
F_345 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_114 ( V_242 ) ;
if ( V_471 )
V_70 = F_331 ( V_242 , V_466 ) ;
else
V_70 = F_330 ( V_242 , V_466 ) ;
V_579 -> V_586 += V_70 ;
V_579 -> V_581 += F_351 ( V_242 ) ;
V_579 -> V_558 += V_24 -> V_40 . V_401 ;
if ( V_24 -> V_72 > 1 )
* V_585 = true ;
#ifdef F_409
V_579 -> V_105 += V_24 -> V_105 ;
V_579 -> V_107 += V_24 -> V_107 ;
#endif
V_579 -> V_587 += F_115 ( V_242 ) ;
if ( F_346 ( V_242 ) )
V_579 -> V_588 ++ ;
}
V_579 -> V_580 = V_119 -> V_472 -> V_148 ;
V_579 -> V_470 = ( V_579 -> V_586 * V_150 ) / V_579 -> V_580 ;
if ( V_579 -> V_558 )
V_579 -> V_589 = V_579 -> V_587 / V_579 -> V_558 ;
V_579 -> F_103 = V_119 -> F_103 ;
V_579 -> V_582 = F_406 ( V_154 , V_579 ) ;
V_579 -> V_559 = F_407 ( V_154 , V_119 , V_579 ) ;
}
static bool F_410 ( struct V_516 * V_154 ,
struct V_552 * V_553 ,
struct V_460 * V_482 ,
struct V_578 * V_579 )
{
struct V_578 * V_554 = & V_553 -> V_557 ;
if ( V_579 -> V_559 > V_554 -> V_559 )
return true ;
if ( V_579 -> V_559 < V_554 -> V_559 )
return false ;
if ( V_579 -> V_470 <= V_554 -> V_470 )
return false ;
if ( ! ( V_154 -> V_185 -> V_179 & V_590 ) )
return true ;
if ( V_579 -> V_558 && V_154 -> V_136 < F_411 ( V_482 ) ) {
if ( ! V_553 -> V_554 )
return true ;
if ( F_411 ( V_553 -> V_554 ) > F_411 ( V_482 ) )
return true ;
}
return false ;
}
static inline enum V_591 F_412 ( struct V_578 * V_579 )
{
if ( V_579 -> V_558 > V_579 -> V_105 )
return V_592 ;
if ( V_579 -> V_558 > V_579 -> V_107 )
return V_202 ;
return V_593 ;
}
static inline enum V_591 F_413 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_105 )
return V_592 ;
if ( V_24 -> V_72 > V_24 -> V_107 )
return V_202 ;
return V_593 ;
}
static inline enum V_591 F_412 ( struct V_578 * V_579 )
{
return V_593 ;
}
static inline enum V_591 F_413 ( struct V_24 * V_24 )
{
return V_592 ;
}
static inline void F_414 ( struct V_516 * V_154 , struct V_552 * V_553 )
{
struct V_184 * V_495 = V_154 -> V_185 -> V_495 ;
struct V_460 * V_482 = V_154 -> V_185 -> V_463 ;
struct V_578 V_594 ;
int V_466 , V_595 = 0 ;
bool V_585 = false ;
if ( V_495 && V_495 -> V_179 & V_596 )
V_595 = 1 ;
V_466 = F_395 ( V_154 -> V_185 , V_154 -> V_391 ) ;
do {
struct V_578 * V_579 = & V_594 ;
int V_471 ;
V_471 = F_128 ( V_154 -> V_136 , F_343 ( V_482 ) ) ;
if ( V_471 ) {
V_553 -> V_204 = V_482 ;
V_579 = & V_553 -> V_597 ;
if ( V_154 -> V_391 != V_547 ||
F_415 ( V_195 , V_482 -> V_472 -> V_575 ) )
F_402 ( V_154 -> V_185 , V_154 -> V_136 ) ;
}
F_408 ( V_154 , V_482 , V_466 , V_471 , V_579 ,
& V_585 ) ;
if ( V_471 )
goto V_598;
if ( V_595 && V_553 -> V_204 &&
F_405 ( V_154 , & V_553 -> V_597 ) &&
( V_579 -> V_558 > 1 ) ) {
V_579 -> V_582 = 1 ;
V_579 -> V_559 = V_583 ;
}
if ( F_410 ( V_154 , V_553 , V_482 , V_579 ) ) {
V_553 -> V_554 = V_482 ;
V_553 -> V_557 = * V_579 ;
}
V_598:
V_553 -> V_555 += V_579 -> V_586 ;
V_553 -> V_556 += V_579 -> V_580 ;
V_482 = V_482 -> V_58 ;
} while ( V_482 != V_154 -> V_185 -> V_463 );
if ( V_154 -> V_185 -> V_179 & V_520 )
V_154 -> V_591 = F_412 ( & V_553 -> V_557 ) ;
if ( ! V_154 -> V_185 -> V_34 ) {
if ( V_154 -> V_175 -> V_599 -> V_585 != V_585 )
V_154 -> V_175 -> V_599 -> V_585 = V_585 ;
}
}
static int F_416 ( struct V_516 * V_154 , struct V_552 * V_553 )
{
int V_600 ;
if ( ! ( V_154 -> V_185 -> V_179 & V_590 ) )
return 0 ;
if ( ! V_553 -> V_554 )
return 0 ;
V_600 = F_411 ( V_553 -> V_554 ) ;
if ( V_154 -> V_136 > V_600 )
return 0 ;
V_154 -> V_468 = F_117 (
V_553 -> V_557 . V_470 * V_553 -> V_557 . V_580 ,
V_150 ) ;
return 1 ;
}
static inline
void F_417 ( struct V_516 * V_154 , struct V_552 * V_553 )
{
unsigned long V_488 , V_601 = 0 , V_602 = 0 ;
unsigned int V_603 = 2 ;
unsigned long V_604 ;
struct V_578 * V_204 , * V_554 ;
V_204 = & V_553 -> V_597 ;
V_554 = & V_553 -> V_557 ;
if ( ! V_204 -> V_558 )
V_204 -> V_589 = F_333 ( V_154 -> V_136 ) ;
else if ( V_554 -> V_589 > V_204 -> V_589 )
V_603 = 1 ;
V_604 =
( V_554 -> V_589 * V_150 ) /
V_554 -> V_580 ;
if ( V_554 -> V_470 + V_604 >=
V_204 -> V_470 + ( V_604 * V_603 ) ) {
V_154 -> V_468 = V_554 -> V_589 ;
return;
}
V_601 += V_554 -> V_580 *
F_144 ( V_554 -> V_589 , V_554 -> V_470 ) ;
V_601 += V_204 -> V_580 *
F_144 ( V_204 -> V_589 , V_204 -> V_470 ) ;
V_601 /= V_150 ;
if ( V_554 -> V_470 > V_604 ) {
V_602 += V_554 -> V_580 *
F_144 ( V_554 -> V_589 ,
V_554 -> V_470 - V_604 ) ;
}
if ( V_554 -> V_470 * V_554 -> V_580 <
V_554 -> V_589 * V_150 ) {
V_488 = ( V_554 -> V_470 * V_554 -> V_580 ) /
V_204 -> V_580 ;
} else {
V_488 = ( V_554 -> V_589 * V_150 ) /
V_204 -> V_580 ;
}
V_602 += V_204 -> V_580 *
F_144 ( V_204 -> V_589 , V_204 -> V_470 + V_488 ) ;
V_602 /= V_150 ;
if ( V_602 > V_601 )
V_154 -> V_468 = V_554 -> V_589 ;
}
static inline void F_418 ( struct V_516 * V_154 , struct V_552 * V_553 )
{
unsigned long V_605 , V_606 = ~ 0UL ;
struct V_578 * V_204 , * V_554 ;
V_204 = & V_553 -> V_597 ;
V_554 = & V_553 -> V_557 ;
if ( V_554 -> V_559 == V_584 ) {
V_554 -> V_589 =
F_144 ( V_554 -> V_589 , V_553 -> V_470 ) ;
}
if ( V_554 -> V_470 <= V_553 -> V_470 ||
V_204 -> V_470 >= V_553 -> V_470 ) {
V_154 -> V_468 = 0 ;
return F_417 ( V_154 , V_553 ) ;
}
if ( V_554 -> V_559 == V_583 &&
V_204 -> V_559 == V_583 ) {
V_606 = V_554 -> V_558 *
V_333 ;
if ( V_606 > V_554 -> V_580 )
V_606 -= V_554 -> V_580 ;
else
V_606 = ~ 0UL ;
}
V_605 = F_144 ( V_554 -> V_470 - V_553 -> V_470 , V_606 ) ;
V_154 -> V_468 = F_144 (
V_605 * V_554 -> V_580 ,
( V_553 -> V_470 - V_204 -> V_470 ) * V_204 -> V_580
) / V_150 ;
if ( V_154 -> V_468 < V_554 -> V_589 )
return F_417 ( V_154 , V_553 ) ;
}
static struct V_460 * F_419 ( struct V_516 * V_154 )
{
struct V_578 * V_204 , * V_554 ;
struct V_552 V_553 ;
F_394 ( & V_553 ) ;
F_414 ( V_154 , & V_553 ) ;
V_204 = & V_553 . V_597 ;
V_554 = & V_553 . V_557 ;
if ( ( V_154 -> V_391 == V_607 || V_154 -> V_391 == V_547 ) &&
F_416 ( V_154 , & V_553 ) )
return V_553 . V_554 ;
if ( ! V_553 . V_554 || V_554 -> V_558 == 0 )
goto V_608;
V_553 . V_470 = ( V_150 * V_553 . V_555 )
/ V_553 . V_556 ;
if ( V_554 -> V_559 == V_584 )
goto V_609;
if ( V_154 -> V_391 == V_547 && F_405 ( V_154 , V_204 ) &&
V_554 -> V_582 )
goto V_609;
if ( V_204 -> V_470 >= V_554 -> V_470 )
goto V_608;
if ( V_204 -> V_470 >= V_553 . V_470 )
goto V_608;
if ( V_154 -> V_391 == V_607 ) {
if ( ( V_554 -> V_559 != V_583 ) &&
( V_204 -> V_588 <= ( V_554 -> V_588 + 1 ) ) )
goto V_608;
} else {
if ( 100 * V_554 -> V_470 <=
V_154 -> V_185 -> V_170 * V_204 -> V_470 )
goto V_608;
}
V_609:
F_418 ( V_154 , & V_553 ) ;
return V_553 . V_554 ;
V_608:
V_154 -> V_468 = 0 ;
return NULL ;
}
static struct V_24 * F_420 ( struct V_516 * V_154 ,
struct V_460 * V_119 )
{
struct V_24 * V_554 = NULL , * V_24 ;
unsigned long V_610 = 0 , V_611 = 1 ;
int V_242 ;
F_345 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_148 , V_444 ;
enum V_591 V_612 ;
V_24 = F_114 ( V_242 ) ;
V_612 = F_413 ( V_24 ) ;
if ( V_612 > V_154 -> V_591 )
continue;
V_148 = F_116 ( V_242 ) ;
V_444 = F_115 ( V_242 ) ;
if ( V_24 -> V_72 == 1 && V_444 > V_154 -> V_468 &&
! F_403 ( V_24 , V_154 -> V_185 ) )
continue;
if ( V_444 * V_611 > V_610 * V_148 ) {
V_610 = V_444 ;
V_611 = V_148 ;
V_554 = V_24 ;
}
}
return V_554 ;
}
static int F_421 ( struct V_516 * V_154 )
{
struct V_184 * V_185 = V_154 -> V_185 ;
if ( V_154 -> V_391 == V_547 ) {
if ( ( V_185 -> V_179 & V_590 ) && V_154 -> V_174 > V_154 -> V_136 )
return 1 ;
}
if ( ( V_154 -> V_391 != V_562 ) &&
( V_154 -> V_173 -> V_40 . V_401 == 1 ) ) {
if ( ( F_403 ( V_154 -> V_173 , V_185 ) ) &&
( F_116 ( V_154 -> V_174 ) * V_185 -> V_170 < F_116 ( V_154 -> V_136 ) * 100 ) )
return 1 ;
}
return F_14 ( V_185 -> V_531 > V_185 -> V_532 + 2 ) ;
}
static int F_422 ( struct V_516 * V_154 )
{
struct V_460 * V_482 = V_154 -> V_185 -> V_463 ;
struct V_613 * V_614 , * V_615 ;
int V_147 , V_616 = - 1 ;
if ( V_154 -> V_391 == V_547 )
return 1 ;
V_614 = F_343 ( V_482 ) ;
V_615 = F_423 ( V_482 ) ;
F_345 (cpu, sg_cpus, env->cpus) {
if ( ! F_128 ( V_147 , V_615 ) || ! F_346 ( V_147 ) )
continue;
V_616 = V_147 ;
break;
}
if ( V_616 == - 1 )
V_616 = F_424 ( V_482 ) ;
return V_616 == V_154 -> V_136 ;
}
static int F_425 ( int V_453 , struct V_24 * V_343 ,
struct V_184 * V_185 , enum V_561 V_391 ,
int * V_617 )
{
int V_618 , V_619 , V_620 = 0 ;
struct V_184 * V_621 = V_185 -> V_34 ;
struct V_460 * V_119 ;
struct V_24 * V_554 ;
unsigned long V_179 ;
struct V_613 * V_8 = F_426 ( V_622 ) ;
struct V_516 V_154 = {
. V_185 = V_185 ,
. V_136 = V_453 ,
. V_175 = V_343 ,
. V_526 = F_343 ( V_185 -> V_463 ) ,
. V_391 = V_391 ,
. V_543 = V_544 ,
. V_8 = V_8 ,
. V_591 = V_593 ,
. V_539 = F_427 ( V_154 . V_539 ) ,
} ;
if ( V_391 == V_547 )
V_154 . V_526 = NULL ;
F_428 ( V_8 , V_623 ) ;
F_244 ( V_185 , V_624 [ V_391 ] ) ;
V_625:
if ( ! F_422 ( & V_154 ) ) {
* V_617 = 0 ;
goto V_608;
}
V_119 = F_419 ( & V_154 ) ;
if ( ! V_119 ) {
F_244 ( V_185 , V_626 [ V_391 ] ) ;
goto V_608;
}
V_554 = F_420 ( & V_154 , V_119 ) ;
if ( ! V_554 ) {
F_244 ( V_185 , V_627 [ V_391 ] ) ;
goto V_608;
}
F_171 ( V_554 == V_154 . V_175 ) ;
F_70 ( V_185 , V_628 [ V_391 ] , V_154 . V_468 ) ;
V_154 . V_174 = V_554 -> V_147 ;
V_154 . V_173 = V_554 ;
V_618 = 0 ;
if ( V_554 -> V_72 > 1 ) {
V_154 . V_179 |= V_529 ;
V_154 . V_542 = F_144 ( V_629 , V_554 -> V_72 ) ;
V_630:
F_390 ( & V_554 -> V_178 , V_179 ) ;
V_619 = F_379 ( & V_154 ) ;
F_281 ( & V_554 -> V_178 ) ;
if ( V_619 ) {
F_387 ( & V_154 ) ;
V_618 += V_619 ;
}
F_429 ( V_179 ) ;
if ( V_154 . V_179 & V_545 ) {
V_154 . V_179 &= ~ V_545 ;
goto V_630;
}
if ( ( V_154 . V_179 & V_527 ) && V_154 . V_468 > 0 ) {
F_430 ( V_154 . V_136 , V_154 . V_8 ) ;
V_154 . V_175 = F_114 ( V_154 . V_528 ) ;
V_154 . V_136 = V_154 . V_528 ;
V_154 . V_179 &= ~ V_527 ;
V_154 . V_541 = 0 ;
V_154 . V_543 = V_544 ;
goto V_630;
}
if ( V_621 ) {
int * V_631 = & V_621 -> V_463 -> V_472 -> V_468 ;
if ( ( V_154 . V_179 & V_525 ) && V_154 . V_468 > 0 )
* V_631 = 1 ;
}
if ( F_14 ( V_154 . V_179 & V_529 ) ) {
F_430 ( F_27 ( V_554 ) , V_8 ) ;
if ( ! F_431 ( V_8 ) ) {
V_154 . V_541 = 0 ;
V_154 . V_543 = V_544 ;
goto V_625;
}
goto V_632;
}
}
if ( ! V_618 ) {
F_244 ( V_185 , V_633 [ V_391 ] ) ;
if ( V_391 != V_547 )
V_185 -> V_531 ++ ;
if ( F_421 ( & V_154 ) ) {
F_390 ( & V_554 -> V_178 , V_179 ) ;
if ( ! F_128 ( V_453 ,
F_129 ( V_554 -> V_45 ) ) ) {
F_391 ( & V_554 -> V_178 ,
V_179 ) ;
V_154 . V_179 |= V_529 ;
goto V_634;
}
if ( ! V_554 -> V_620 ) {
V_554 -> V_620 = 1 ;
V_554 -> V_635 = V_453 ;
V_620 = 1 ;
}
F_391 ( & V_554 -> V_178 , V_179 ) ;
if ( V_620 ) {
F_432 ( F_27 ( V_554 ) ,
V_636 , V_554 ,
& V_554 -> V_637 ) ;
}
V_185 -> V_531 = V_185 -> V_532 + 1 ;
}
} else
V_185 -> V_531 = 0 ;
if ( F_12 ( ! V_620 ) ) {
V_185 -> V_573 = V_185 -> V_638 ;
} else {
if ( V_185 -> V_573 < V_185 -> V_639 )
V_185 -> V_573 *= 2 ;
}
goto V_290;
V_608:
if ( V_621 ) {
int * V_631 = & V_621 -> V_463 -> V_472 -> V_468 ;
if ( * V_631 )
* V_631 = 0 ;
}
V_632:
F_244 ( V_185 , V_640 [ V_391 ] ) ;
V_185 -> V_531 = 0 ;
V_634:
if ( ( ( V_154 . V_179 & V_529 ) &&
V_185 -> V_573 < V_641 ) ||
( V_185 -> V_573 < V_185 -> V_639 ) )
V_185 -> V_573 *= 2 ;
V_618 = 0 ;
V_290:
return V_618 ;
}
static inline unsigned long
F_433 ( struct V_184 * V_185 , int V_642 )
{
unsigned long V_192 = V_185 -> V_573 ;
if ( V_642 )
V_192 *= V_185 -> V_643 ;
V_192 = F_145 ( V_192 ) ;
V_192 = F_150 ( V_192 , 1UL , V_574 ) ;
return V_192 ;
}
static inline void
F_434 ( struct V_184 * V_185 , int V_642 , unsigned long * V_644 )
{
unsigned long V_192 , V_58 ;
V_192 = F_433 ( V_185 , V_642 ) ;
V_58 = V_185 -> V_645 + V_192 ;
if ( F_181 ( * V_644 , V_58 ) )
* V_644 = V_58 ;
}
static int F_235 ( struct V_24 * V_343 )
{
unsigned long V_644 = V_195 + V_193 ;
int V_453 = V_343 -> V_147 ;
struct V_184 * V_185 ;
int V_646 = 0 ;
T_2 V_647 = 0 ;
F_233 ( V_343 ) ;
V_343 -> V_480 = F_77 ( V_343 ) ;
if ( V_343 -> V_648 < V_518 ||
! V_343 -> V_599 -> V_585 ) {
F_124 () ;
V_185 = F_435 ( V_343 -> V_185 ) ;
if ( V_185 )
F_434 ( V_185 , 0 , & V_644 ) ;
F_132 () ;
goto V_290;
}
F_281 ( & V_343 -> V_178 ) ;
F_389 ( V_453 ) ;
F_124 () ;
F_353 (this_cpu, sd) {
int V_617 = 1 ;
T_2 V_649 , V_650 ;
if ( ! ( V_185 -> V_179 & V_493 ) )
continue;
if ( V_343 -> V_648 < V_647 + V_185 -> V_651 ) {
F_434 ( V_185 , 0 , & V_644 ) ;
break;
}
if ( V_185 -> V_179 & V_652 ) {
V_649 = F_274 ( V_453 ) ;
V_646 = F_425 ( V_453 , V_343 ,
V_185 , V_547 ,
& V_617 ) ;
V_650 = F_274 ( V_453 ) - V_649 ;
if ( V_650 > V_185 -> V_651 )
V_185 -> V_651 = V_650 ;
V_647 += V_650 ;
}
F_434 ( V_185 , 0 , & V_644 ) ;
if ( V_646 || V_343 -> V_72 > 0 )
break;
}
F_132 () ;
F_279 ( & V_343 -> V_178 ) ;
if ( V_647 > V_343 -> V_653 )
V_343 -> V_653 = V_647 ;
if ( V_343 -> V_40 . V_401 && ! V_646 )
V_646 = 1 ;
V_290:
if ( F_181 ( V_343 -> V_644 , V_644 ) )
V_343 -> V_644 = V_644 ;
if ( V_343 -> V_72 != V_343 -> V_40 . V_401 )
V_646 = - 1 ;
if ( V_646 ) {
F_234 ( V_343 ) ;
V_343 -> V_480 = 0 ;
}
return V_646 ;
}
static int V_636 ( void * V_397 )
{
struct V_24 * V_654 = V_397 ;
int V_600 = F_27 ( V_654 ) ;
int V_655 = V_654 -> V_635 ;
struct V_24 * V_656 = F_114 ( V_655 ) ;
struct V_184 * V_185 ;
struct V_26 * V_29 = NULL ;
F_125 ( & V_654 -> V_178 ) ;
if ( F_14 ( V_600 != F_275 () ||
! V_654 -> V_620 ) )
goto V_657;
if ( V_654 -> V_72 <= 1 )
goto V_657;
F_171 ( V_654 == V_656 ) ;
F_124 () ;
F_353 (target_cpu, sd) {
if ( ( V_185 -> V_179 & V_493 ) &&
F_128 ( V_600 , F_354 ( V_185 ) ) )
break;
}
if ( F_12 ( V_185 ) ) {
struct V_516 V_154 = {
. V_185 = V_185 ,
. V_136 = V_655 ,
. V_175 = V_656 ,
. V_174 = V_654 -> V_147 ,
. V_173 = V_654 ,
. V_391 = V_607 ,
} ;
F_244 ( V_185 , V_658 ) ;
V_29 = F_377 ( & V_154 ) ;
if ( V_29 )
F_244 ( V_185 , V_659 ) ;
else
F_244 ( V_185 , V_660 ) ;
}
F_132 () ;
V_657:
V_654 -> V_620 = 0 ;
F_281 ( & V_654 -> V_178 ) ;
if ( V_29 )
F_386 ( V_656 , V_29 ) ;
F_436 () ;
return 0 ;
}
static inline int F_437 ( struct V_24 * V_24 )
{
return F_14 ( ! F_438 ( V_24 -> V_185 ) ) ;
}
static inline int F_439 ( void )
{
int V_661 = F_440 ( V_662 . V_663 ) ;
if ( V_661 < V_664 && F_346 ( V_661 ) )
return V_661 ;
return V_664 ;
}
static void F_441 ( void )
{
int V_665 ;
V_662 . V_644 ++ ;
V_665 = F_439 () ;
if ( V_665 >= V_664 )
return;
if ( F_442 ( V_666 , F_443 ( V_665 ) ) )
return;
F_444 ( V_665 ) ;
return;
}
static inline void F_445 ( int V_147 )
{
if ( F_14 ( F_446 ( V_667 , F_443 ( V_147 ) ) ) ) {
if ( F_12 ( F_128 ( V_147 , V_662 . V_663 ) ) ) {
F_430 ( V_147 , V_662 . V_663 ) ;
F_447 ( & V_662 . V_668 ) ;
}
F_448 ( V_667 , F_443 ( V_147 ) ) ;
}
}
static inline void F_449 ( void )
{
struct V_184 * V_185 ;
int V_147 = F_275 () ;
F_124 () ;
V_185 = F_136 ( F_137 ( V_669 , V_147 ) ) ;
if ( ! V_185 || ! V_185 -> V_670 )
goto V_181;
V_185 -> V_670 = 0 ;
F_450 ( & V_185 -> V_463 -> V_472 -> V_671 ) ;
V_181:
F_132 () ;
}
void F_451 ( void )
{
struct V_184 * V_185 ;
int V_147 = F_275 () ;
F_124 () ;
V_185 = F_136 ( F_137 ( V_669 , V_147 ) ) ;
if ( ! V_185 || V_185 -> V_670 )
goto V_181;
V_185 -> V_670 = 1 ;
F_447 ( & V_185 -> V_463 -> V_472 -> V_671 ) ;
V_181:
F_132 () ;
}
void F_452 ( int V_147 )
{
if ( ! F_453 ( V_147 ) )
return;
if ( F_446 ( V_667 , F_443 ( V_147 ) ) )
return;
if ( F_437 ( F_114 ( V_147 ) ) )
return;
F_454 ( V_147 , V_662 . V_663 ) ;
F_450 ( & V_662 . V_668 ) ;
F_455 ( V_667 , F_443 ( V_147 ) ) ;
}
static int F_456 ( struct V_672 * V_673 ,
unsigned long V_674 , void * V_675 )
{
switch ( V_674 & ~ V_676 ) {
case V_677 :
F_445 ( F_275 () ) ;
return V_678 ;
default:
return V_679 ;
}
}
void F_457 ( void )
{
V_574 = V_193 * F_6 () / 10 ;
}
static void F_458 ( struct V_24 * V_24 , enum V_561 V_391 )
{
int V_617 = 1 ;
int V_147 = V_24 -> V_147 ;
unsigned long V_192 ;
struct V_184 * V_185 ;
unsigned long V_644 = V_195 + 60 * V_193 ;
int F_434 = 0 ;
int V_680 , V_681 = 0 ;
T_2 V_682 = 0 ;
F_389 ( V_147 ) ;
F_124 () ;
F_353 (cpu, sd) {
if ( F_181 ( V_195 , V_185 -> V_683 ) ) {
V_185 -> V_651 =
( V_185 -> V_651 * 253 ) / 256 ;
V_185 -> V_683 = V_195 + V_193 ;
V_681 = 1 ;
}
V_682 += V_185 -> V_651 ;
if ( ! ( V_185 -> V_179 & V_493 ) )
continue;
if ( ! V_617 ) {
if ( V_681 )
continue;
break;
}
V_192 = F_433 ( V_185 , V_391 != V_607 ) ;
V_680 = V_185 -> V_179 & V_684 ;
if ( V_680 ) {
if ( ! F_459 ( & V_685 ) )
goto V_290;
}
if ( F_415 ( V_195 , V_185 -> V_645 + V_192 ) ) {
if ( F_425 ( V_147 , V_24 , V_185 , V_391 , & V_617 ) ) {
V_391 = F_346 ( V_147 ) ? V_607 : V_562 ;
}
V_185 -> V_645 = V_195 ;
V_192 = F_433 ( V_185 , V_391 != V_607 ) ;
}
if ( V_680 )
F_174 ( & V_685 ) ;
V_290:
if ( F_181 ( V_644 , V_185 -> V_645 + V_192 ) ) {
V_644 = V_185 -> V_645 + V_192 ;
F_434 = 1 ;
}
}
if ( V_681 ) {
V_24 -> V_653 =
F_69 ( ( T_2 ) V_518 , V_682 ) ;
}
F_132 () ;
if ( F_12 ( F_434 ) )
V_24 -> V_644 = V_644 ;
}
static void F_460 ( struct V_24 * V_343 , enum V_561 V_391 )
{
int V_453 = V_343 -> V_147 ;
struct V_24 * V_24 ;
int V_616 ;
if ( V_391 != V_607 ||
! F_446 ( V_666 , F_443 ( V_453 ) ) )
goto V_271;
F_113 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_616 == V_453 || ! F_346 ( V_616 ) )
continue;
if ( F_461 () )
break;
V_24 = F_114 ( V_616 ) ;
if ( F_415 ( V_195 , V_24 -> V_644 ) ) {
F_125 ( & V_24 -> V_178 ) ;
F_292 ( V_24 ) ;
F_462 ( V_24 ) ;
F_127 ( & V_24 -> V_178 ) ;
F_458 ( V_24 , V_607 ) ;
}
if ( F_181 ( V_343 -> V_644 , V_24 -> V_644 ) )
V_343 -> V_644 = V_24 -> V_644 ;
}
V_662 . V_644 = V_343 -> V_644 ;
V_271:
F_448 ( V_666 , F_443 ( V_453 ) ) ;
}
static inline bool F_463 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_195 ;
struct V_184 * V_185 ;
struct V_577 * V_472 ;
int V_686 , V_147 = V_24 -> V_147 ;
bool V_687 = false ;
if ( F_14 ( V_24 -> F_235 ) )
return false ;
F_449 () ;
F_445 ( V_147 ) ;
if ( F_12 ( ! F_221 ( & V_662 . V_668 ) ) )
return false ;
if ( F_184 ( V_81 , V_662 . V_644 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_124 () ;
V_185 = F_136 ( F_137 ( V_669 , V_147 ) ) ;
if ( V_185 ) {
V_472 = V_185 -> V_463 -> V_472 ;
V_686 = F_221 ( & V_472 -> V_671 ) ;
if ( V_686 > 1 ) {
V_687 = true ;
goto V_181;
}
}
V_185 = F_136 ( V_24 -> V_185 ) ;
if ( V_185 ) {
if ( ( V_24 -> V_40 . V_401 >= 1 ) &&
F_403 ( V_24 , V_185 ) ) {
V_687 = true ;
goto V_181;
}
}
V_185 = F_136 ( F_137 ( V_688 , V_147 ) ) ;
if ( V_185 && ( F_350 ( V_662 . V_663 ,
F_354 ( V_185 ) ) < V_147 ) ) {
V_687 = true ;
goto V_181;
}
V_181:
F_132 () ;
return V_687 ;
}
static void F_460 ( struct V_24 * V_343 , enum V_561 V_391 ) { }
static void F_464 ( struct V_689 * V_690 )
{
struct V_24 * V_343 = V_343 () ;
enum V_561 V_391 = V_343 -> F_235 ?
V_607 : V_562 ;
F_460 ( V_343 , V_391 ) ;
F_458 ( V_343 , V_391 ) ;
}
void F_465 ( struct V_24 * V_24 )
{
if ( F_14 ( F_437 ( V_24 ) ) )
return;
if ( F_415 ( V_195 , V_24 -> V_644 ) )
F_466 ( V_691 ) ;
#ifdef F_467
if ( F_463 ( V_24 ) )
F_441 () ;
#endif
}
static void F_468 ( struct V_24 * V_24 )
{
F_8 () ;
F_319 ( V_24 ) ;
}
static void F_469 ( struct V_24 * V_24 )
{
F_8 () ;
F_321 ( V_24 ) ;
}
static void F_470 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_372 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_262 ( V_25 , V_28 , V_372 ) ;
}
if ( V_256 )
F_195 ( V_24 , V_45 ) ;
F_222 ( V_24 , 1 ) ;
}
static void F_471 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_453 = F_275 () ;
struct V_24 * V_24 = V_343 () ;
unsigned long V_179 ;
F_390 ( & V_24 -> V_178 , V_179 ) ;
F_292 ( V_24 ) ;
V_25 = F_23 ( V_141 ) ;
V_45 = V_25 -> V_45 ;
F_124 () ;
F_472 ( V_29 , V_453 ) ;
F_132 () ;
F_66 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_245 ( V_25 , V_28 , 1 ) ;
if ( V_692 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_122 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_256 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_391 ( & V_24 -> V_178 , V_179 ) ;
}
static void
F_473 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_693 )
{
if ( ! F_474 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_694 > V_693 )
F_256 ( V_24 ) ;
} else
F_385 ( V_24 , V_29 , 0 ) ;
}
static void F_475 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! F_474 ( V_29 ) && V_29 -> V_364 != V_695 ) {
F_245 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_199
if ( V_28 -> V_77 . V_322 ) {
F_213 ( V_28 ) ;
F_226 ( V_25 , V_28 -> V_77 . V_323 ) ;
}
#endif
}
static void F_476 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
#ifdef F_362
struct V_27 * V_28 = & V_29 -> V_28 ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_474 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 )
F_256 ( V_24 ) ;
else
F_385 ( V_24 , V_29 , 0 ) ;
}
static void F_477 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_257 ( V_25 , V_28 ) ;
F_74 ( V_25 , 0 ) ;
}
}
void F_478 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_696 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_199
F_479 ( & V_25 -> V_321 , 1 ) ;
F_480 ( & V_25 -> V_340 , 0 ) ;
#endif
}
static void F_481 ( struct V_26 * V_29 , int V_372 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_372 && ( ! V_28 -> V_85 || V_29 -> V_364 == V_697 ) )
V_372 = 1 ;
if ( ! V_372 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_482 ( V_29 , F_135 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_372 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_199
V_28 -> V_77 . V_322 = F_214 ( & V_25 -> V_321 ) ;
V_25 -> V_328 += V_28 -> V_77 . V_323 ;
#endif
}
}
void F_483 ( struct V_294 * V_33 )
{
int V_242 ;
F_317 ( F_277 ( V_33 ) ) ;
F_484 (i) {
if ( V_33 -> V_25 )
F_179 ( V_33 -> V_25 [ V_242 ] ) ;
if ( V_33 -> V_28 )
F_179 ( V_33 -> V_28 [ V_242 ] ) ;
}
F_179 ( V_33 -> V_25 ) ;
F_179 ( V_33 -> V_28 ) ;
}
int F_485 ( struct V_294 * V_33 , struct V_294 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_242 ;
V_33 -> V_25 = F_167 ( sizeof( V_25 ) * V_664 , V_244 ) ;
if ( ! V_33 -> V_25 )
goto V_698;
V_33 -> V_28 = F_167 ( sizeof( V_28 ) * V_664 , V_244 ) ;
if ( ! V_33 -> V_28 )
goto V_698;
V_33 -> V_298 = V_71 ;
F_310 ( F_277 ( V_33 ) ) ;
F_484 (i) {
V_25 = F_486 ( sizeof( struct V_25 ) ,
V_244 , F_105 ( V_242 ) ) ;
if ( ! V_25 )
goto V_698;
V_28 = F_486 ( sizeof( struct V_27 ) ,
V_244 , F_105 ( V_242 ) ) ;
if ( ! V_28 )
goto V_699;
F_478 ( V_25 ) ;
F_487 ( V_33 , V_25 , V_28 , V_242 , V_34 -> V_28 [ V_242 ] ) ;
}
return 1 ;
V_699:
F_179 ( V_25 ) ;
V_698:
return 0 ;
}
void F_488 ( struct V_294 * V_33 , int V_147 )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
unsigned long V_179 ;
if ( ! V_33 -> V_25 [ V_147 ] -> V_32 )
return;
F_390 ( & V_24 -> V_178 , V_179 ) ;
F_31 ( V_33 -> V_25 [ V_147 ] ) ;
F_391 ( & V_24 -> V_178 , V_179 ) ;
}
void F_487 ( struct V_294 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_147 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_114 ( V_147 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_314 ( V_25 ) ;
V_33 -> V_25 [ V_147 ] = V_25 ;
V_33 -> V_28 [ V_147 ] = V_28 ;
if ( ! V_28 )
return;
if ( ! V_34 ) {
V_28 -> V_25 = & V_24 -> V_40 ;
V_28 -> V_39 = 0 ;
} else {
V_28 -> V_25 = V_34 -> V_31 ;
V_28 -> V_39 = V_34 -> V_39 + 1 ;
}
V_28 -> V_31 = V_25 ;
F_3 ( & V_28 -> V_70 , V_71 ) ;
V_28 -> V_34 = V_34 ;
}
int F_489 ( struct V_294 * V_33 , unsigned long V_298 )
{
int V_242 ;
unsigned long V_179 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_189 ;
V_298 = F_150 ( V_298 , F_223 ( V_299 ) , F_223 ( V_700 ) ) ;
F_490 ( & V_701 ) ;
if ( V_33 -> V_298 == V_298 )
goto V_484;
V_33 -> V_298 = V_298 ;
F_484 (i) {
struct V_24 * V_24 = F_114 ( V_242 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_242 ] ;
F_390 ( & V_24 -> V_178 , V_179 ) ;
F_292 ( V_24 ) ;
F_61 (se)
F_207 ( F_25 ( V_28 ) ) ;
F_391 ( & V_24 -> V_178 , V_179 ) ;
}
V_484:
F_491 ( & V_701 ) ;
return 0 ;
}
void F_483 ( struct V_294 * V_33 ) { }
int F_485 ( struct V_294 * V_33 , struct V_294 * V_34 )
{
return 1 ;
}
void F_488 ( struct V_294 * V_33 , int V_147 ) { }
static unsigned int F_492 ( struct V_24 * V_24 , struct V_26 * V_122 )
{
struct V_27 * V_28 = & V_122 -> V_28 ;
unsigned int V_702 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_702 = F_493 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_702 ;
}
void F_494 ( struct V_703 * V_704 , int V_147 )
{
struct V_25 * V_25 ;
F_124 () ;
F_320 (cpu_rq(cpu), cfs_rq)
F_495 ( V_704 , V_147 , V_25 ) ;
F_132 () ;
}
T_13 void F_496 ( void )
{
#ifdef F_199
F_497 ( V_691 , F_464 ) ;
#ifdef F_467
V_662 . V_644 = V_195 ;
F_498 ( & V_662 . V_663 , V_705 ) ;
F_499 ( F_456 , 0 ) ;
#endif
#endif
}
