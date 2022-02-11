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
static unsigned int F_4 ( void )
{
unsigned int V_8 = F_5 (unsigned int, num_online_cpus(), 8 ) ;
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
V_9 = 1 + F_6 ( V_8 ) ;
break;
}
return V_9 ;
}
static void F_7 ( void )
{
unsigned int V_9 = F_4 () ;
#define F_8 ( T_1 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_8 ( V_14 ) ;
F_8 ( V_15 ) ;
F_8 ( V_16 ) ;
#undef F_8
}
void F_9 ( void )
{
F_7 () ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
if ( F_11 ( V_2 -> V_5 ) )
return;
V_7 = F_12 ( V_2 -> V_4 ) ;
if ( V_17 > 32 && F_13 ( V_7 >= V_18 ) )
V_2 -> V_5 = 1 ;
else if ( F_13 ( ! V_7 ) )
V_2 -> V_5 = V_18 ;
else
V_2 -> V_5 = V_18 / V_7 ;
}
static T_2 F_14 ( T_2 V_19 , unsigned long V_4 , struct V_1 * V_2 )
{
T_2 V_20 = F_12 ( V_4 ) ;
int V_21 = V_22 ;
F_10 ( V_2 ) ;
if ( F_13 ( V_20 >> 32 ) ) {
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
return F_15 ( V_19 , V_20 , V_21 ) ;
}
static inline struct V_24 * F_16 ( struct V_25 * V_25 )
{
return V_25 -> V_24 ;
}
static inline struct V_26 * F_17 ( struct V_27 * V_28 )
{
#ifdef F_18
F_19 ( ! F_20 ( V_28 ) ) ;
#endif
return F_21 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_25 * F_22 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_25 ;
}
static inline struct V_25 * F_23 ( struct V_27 * V_28 )
{
return V_28 -> V_25 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_30 )
{
return V_30 -> V_31 ;
}
static inline void F_25 ( struct V_25 * V_25 )
{
if ( ! V_25 -> V_32 ) {
if ( V_25 -> V_33 -> V_34 &&
V_25 -> V_33 -> V_34 -> V_25 [ F_26 ( F_16 ( V_25 ) ) ] -> V_32 ) {
F_27 ( & V_25 -> V_35 ,
& F_16 ( V_25 ) -> V_35 ) ;
} else {
F_28 ( & V_25 -> V_35 ,
& F_16 ( V_25 ) -> V_35 ) ;
}
V_25 -> V_32 = 1 ;
}
}
static inline void F_29 ( struct V_25 * V_25 )
{
if ( V_25 -> V_32 ) {
F_30 ( & V_25 -> V_35 ) ;
V_25 -> V_32 = 0 ;
}
}
static inline struct V_25 *
F_31 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
if ( V_28 -> V_25 == V_36 -> V_25 )
return V_28 -> V_25 ;
return NULL ;
}
static inline struct V_27 * F_32 ( struct V_27 * V_28 )
{
return V_28 -> V_34 ;
}
static void
F_33 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
int V_37 , V_38 ;
V_37 = ( * V_28 ) -> V_39 ;
V_38 = ( * V_36 ) -> V_39 ;
while ( V_37 > V_38 ) {
V_37 -- ;
* V_28 = F_32 ( * V_28 ) ;
}
while ( V_38 > V_37 ) {
V_38 -- ;
* V_36 = F_32 ( * V_36 ) ;
}
while ( ! F_31 ( * V_28 , * V_36 ) ) {
* V_28 = F_32 ( * V_28 ) ;
* V_36 = F_32 ( * V_36 ) ;
}
}
static inline struct V_26 * F_17 ( struct V_27 * V_28 )
{
return F_21 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_24 * F_16 ( struct V_25 * V_25 )
{
return F_21 ( V_25 , struct V_24 , V_40 ) ;
}
static inline struct V_25 * F_22 ( struct V_26 * V_29 )
{
return & F_34 ( V_29 ) -> V_40 ;
}
static inline struct V_25 * F_23 ( struct V_27 * V_28 )
{
struct V_26 * V_29 = F_17 ( V_28 ) ;
struct V_24 * V_24 = F_34 ( V_29 ) ;
return & V_24 -> V_40 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_30 )
{
return NULL ;
}
static inline void F_25 ( struct V_25 * V_25 )
{
}
static inline void F_29 ( struct V_25 * V_25 )
{
}
static inline struct V_27 * F_32 ( struct V_27 * V_28 )
{
return NULL ;
}
static inline void
F_33 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
}
static inline T_2 F_35 ( T_2 F_35 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_35 ) ;
if ( V_42 > 0 )
F_35 = V_41 ;
return F_35 ;
}
static inline T_2 F_36 ( T_2 F_36 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_36 ) ;
if ( V_42 < 0 )
F_36 = V_41 ;
return F_36 ;
}
static inline int F_37 ( struct V_27 * V_43 ,
struct V_27 * V_44 )
{
return ( T_3 ) ( V_43 -> V_41 - V_44 -> V_41 ) < 0 ;
}
static void F_38 ( struct V_25 * V_25 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_25 -> V_45 )
V_41 = V_25 -> V_45 -> V_41 ;
if ( V_25 -> V_46 ) {
struct V_27 * V_28 = F_39 ( V_25 -> V_46 ,
struct V_27 ,
V_47 ) ;
if ( ! V_25 -> V_45 )
V_41 = V_28 -> V_41 ;
else
V_41 = F_36 ( V_41 , V_28 -> V_41 ) ;
}
V_25 -> F_36 = F_35 ( V_25 -> F_36 , V_41 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_48 = V_25 -> F_36 ;
#endif
}
static void F_42 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_49 * * V_50 = & V_25 -> V_51 . V_49 ;
struct V_49 * V_34 = NULL ;
struct V_27 * V_52 ;
int V_53 = 1 ;
while ( * V_50 ) {
V_34 = * V_50 ;
V_52 = F_39 ( V_34 , struct V_27 , V_47 ) ;
if ( F_37 ( V_28 , V_52 ) ) {
V_50 = & V_34 -> V_54 ;
} else {
V_50 = & V_34 -> V_55 ;
V_53 = 0 ;
}
}
if ( V_53 )
V_25 -> V_46 = & V_28 -> V_47 ;
F_43 ( & V_28 -> V_47 , V_34 , V_50 ) ;
F_44 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
static void F_45 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_46 == & V_28 -> V_47 ) {
struct V_49 * V_56 ;
V_56 = F_46 ( & V_28 -> V_47 ) ;
V_25 -> V_46 = V_56 ;
}
F_47 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
struct V_27 * F_48 ( struct V_25 * V_25 )
{
struct V_49 * V_57 = V_25 -> V_46 ;
if ( ! V_57 )
return NULL ;
return F_39 ( V_57 , struct V_27 , V_47 ) ;
}
static struct V_27 * F_49 ( struct V_27 * V_28 )
{
struct V_49 * V_58 = F_46 ( & V_28 -> V_47 ) ;
if ( ! V_58 )
return NULL ;
return F_39 ( V_58 , struct V_27 , V_47 ) ;
}
struct V_27 * F_50 ( struct V_25 * V_25 )
{
struct V_49 * V_59 = F_51 ( & V_25 -> V_51 ) ;
if ( ! V_59 )
return NULL ;
return F_39 ( V_59 , struct V_27 , V_47 ) ;
}
int F_52 ( struct V_60 * V_61 , int V_62 ,
void T_4 * V_63 , T_5 * V_64 ,
T_6 * V_65 )
{
int V_66 = F_53 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
unsigned int V_9 = F_4 () ;
if ( V_66 || ! V_62 )
return V_66 ;
V_67 = F_54 ( V_68 ,
V_69 ) ;
#define F_55 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_55 ( V_14 ) ;
F_55 ( V_15 ) ;
F_55 ( V_16 ) ;
#undef F_55
return 0 ;
}
static inline T_2 F_56 ( T_2 V_42 , struct V_27 * V_28 )
{
if ( F_13 ( V_28 -> V_70 . V_4 != V_71 ) )
V_42 = F_14 ( V_42 , V_71 , & V_28 -> V_70 ) ;
return V_42 ;
}
static T_2 F_57 ( unsigned long V_72 )
{
if ( F_13 ( V_72 > V_67 ) )
return V_72 * V_69 ;
else
return V_68 ;
}
static T_2 F_58 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_73 = F_57 ( V_25 -> V_72 + ! V_28 -> V_74 ) ;
F_59 (se) {
struct V_1 * V_70 ;
struct V_1 V_2 ;
V_25 = F_23 ( V_28 ) ;
V_70 = & V_25 -> V_70 ;
if ( F_13 ( ! V_28 -> V_74 ) ) {
V_2 = V_25 -> V_70 ;
F_1 ( & V_2 , V_28 -> V_70 . V_4 ) ;
V_70 = & V_2 ;
}
V_73 = F_14 ( V_73 , V_28 -> V_70 . V_4 , V_70 ) ;
}
return V_73 ;
}
static T_2 F_60 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_56 ( F_58 ( V_25 , V_28 ) , V_28 ) ;
}
void F_61 ( struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
V_76 -> V_78 = 0 ;
V_76 -> V_79 = 1023 ;
V_76 -> V_80 = F_12 ( V_28 -> V_70 . V_4 ) ;
V_76 -> V_81 = V_76 -> V_80 * V_82 ;
V_76 -> V_83 = F_12 ( V_84 ) ;
V_76 -> V_85 = V_76 -> V_83 * V_82 ;
}
void F_61 ( struct V_27 * V_28 )
{
}
static void F_62 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_86 = F_63 ( F_16 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_13 ( ! V_45 ) )
return;
V_19 = V_86 - V_45 -> V_87 ;
if ( F_13 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_87 = V_86 ;
F_64 ( V_45 -> V_88 . V_89 ,
F_65 ( V_19 , V_45 -> V_88 . V_89 ) ) ;
V_45 -> V_90 += V_19 ;
F_66 ( V_25 , V_91 , V_19 ) ;
V_45 -> V_41 += F_56 ( V_19 , V_45 ) ;
F_38 ( V_25 ) ;
if ( F_20 ( V_45 ) ) {
struct V_26 * V_92 = F_17 ( V_45 ) ;
F_67 ( V_92 , V_19 , V_45 -> V_41 ) ;
F_68 ( V_92 , V_19 ) ;
F_69 ( V_92 , V_19 ) ;
}
F_70 ( V_25 , V_19 ) ;
}
static void F_71 ( struct V_24 * V_24 )
{
F_62 ( F_23 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_72 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_93 = F_73 ( F_16 ( V_25 ) ) ;
if ( F_20 ( V_28 ) && F_74 ( F_17 ( V_28 ) ) &&
F_11 ( V_93 > V_28 -> V_88 . V_93 ) )
V_93 -= V_28 -> V_88 . V_93 ;
V_28 -> V_88 . V_93 = V_93 ;
}
static void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_26 * V_29 ;
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_93 ;
if ( F_20 ( V_28 ) ) {
V_29 = F_17 ( V_28 ) ;
if ( F_74 ( V_29 ) ) {
V_28 -> V_88 . V_93 = V_42 ;
return;
}
F_76 ( V_29 , V_42 ) ;
}
V_28 -> V_88 . V_94 = F_65 ( V_28 -> V_88 . V_94 , V_42 ) ;
V_28 -> V_88 . V_95 ++ ;
V_28 -> V_88 . V_96 += V_42 ;
V_28 -> V_88 . V_93 = 0 ;
}
static inline void
F_72 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static void F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_72 ( V_25 , V_28 ) ;
}
static inline void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_75 ( V_25 , V_28 ) ;
}
static inline void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_87 = F_63 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_80 ( struct V_26 * V_29 )
{
unsigned long V_97 = 0 ;
unsigned long V_98 ;
V_98 = V_99 << ( 20 - V_100 ) ;
V_97 = F_81 ( V_29 -> V_101 ) ;
if ( ! V_97 )
V_97 = V_98 ;
V_97 = F_82 ( V_97 , V_98 ) ;
return V_97 / V_98 ;
}
static unsigned int F_83 ( struct V_26 * V_29 )
{
unsigned int V_102 = F_84 ( V_99 ) ;
unsigned int V_103 , floor ;
unsigned int V_104 = 1 ;
if ( V_102 < V_105 )
V_104 = V_105 / V_102 ;
floor = 1000 / V_104 ;
V_103 = V_106 / F_80 ( V_29 ) ;
return F_85 (unsigned int, floor, scan) ;
}
static unsigned int F_86 ( struct V_26 * V_29 )
{
unsigned int V_107 = F_83 ( V_29 ) ;
unsigned int V_108 ;
V_108 = V_109 / F_80 ( V_29 ) ;
return F_65 ( V_107 , V_108 ) ;
}
static void F_87 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_110 += ( V_29 -> V_111 != - 1 ) ;
V_24 -> V_112 += ( V_29 -> V_111 == F_88 ( V_29 ) ) ;
}
static void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_110 -= ( V_29 -> V_111 != - 1 ) ;
V_24 -> V_112 -= ( V_29 -> V_111 == F_88 ( V_29 ) ) ;
}
T_7 F_90 ( struct V_26 * V_29 )
{
return V_29 -> V_113 ? V_29 -> V_113 -> V_114 : 0 ;
}
static inline int F_91 ( enum V_115 V_116 , int V_117 , int V_118 )
{
return V_119 * ( V_116 * V_120 + V_117 ) + V_118 ;
}
static inline unsigned long F_92 ( struct V_26 * V_29 , int V_117 )
{
if ( ! V_29 -> V_121 )
return 0 ;
return V_29 -> V_121 [ F_91 ( V_122 , V_117 , 0 ) ] +
V_29 -> V_121 [ F_91 ( V_122 , V_117 , 1 ) ] ;
}
static inline unsigned long F_93 ( struct V_26 * V_29 , int V_117 )
{
if ( ! V_29 -> V_113 )
return 0 ;
return V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_117 , 0 ) ] +
V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_117 , 1 ) ] ;
}
static inline unsigned long F_94 ( struct V_113 * V_124 , int V_117 )
{
return V_124 -> V_125 [ F_91 ( V_122 , V_117 , 0 ) ] +
V_124 -> V_125 [ F_91 ( V_122 , V_117 , 1 ) ] ;
}
static unsigned long F_95 ( struct V_26 * V_29 , int V_117 ,
int V_126 , bool V_127 )
{
unsigned long V_128 = 0 ;
int V_129 ;
if ( V_130 == V_131 )
return 0 ;
F_96 (node) {
unsigned long V_123 ;
int V_132 = F_97 ( V_117 , V_129 ) ;
if ( V_132 == V_133 || V_129 == V_117 )
continue;
if ( V_130 == V_134 &&
V_132 > V_126 )
continue;
if ( V_127 )
V_123 = F_92 ( V_29 , V_129 ) ;
else
V_123 = F_93 ( V_29 , V_129 ) ;
if ( V_130 == V_135 ) {
V_123 *= ( V_133 - V_132 ) ;
V_123 /= ( V_133 - V_136 ) ;
}
V_128 += V_123 ;
}
return V_128 ;
}
static inline unsigned long F_98 ( struct V_26 * V_29 , int V_117 ,
int V_132 )
{
unsigned long V_123 , V_137 ;
if ( ! V_29 -> V_121 )
return 0 ;
V_137 = V_29 -> V_138 ;
if ( ! V_137 )
return 0 ;
V_123 = F_92 ( V_29 , V_117 ) ;
V_123 += F_95 ( V_29 , V_117 , V_132 , true ) ;
return 1000 * V_123 / V_137 ;
}
static inline unsigned long F_99 ( struct V_26 * V_29 , int V_117 ,
int V_132 )
{
unsigned long V_123 , V_137 ;
if ( ! V_29 -> V_113 )
return 0 ;
V_137 = V_29 -> V_113 -> V_137 ;
if ( ! V_137 )
return 0 ;
V_123 = F_93 ( V_29 , V_117 ) ;
V_123 += F_95 ( V_29 , V_117 , V_132 , false ) ;
return 1000 * V_123 / V_137 ;
}
bool F_100 ( struct V_26 * V_29 , struct V_139 * V_139 ,
int V_140 , int V_141 )
{
struct V_113 * V_142 = V_29 -> V_113 ;
int V_143 = F_101 ( V_141 ) ;
int V_144 , V_145 ;
V_145 = F_102 ( V_141 , V_146 -> V_147 ) ;
V_144 = F_103 ( V_139 , V_145 ) ;
if ( ! F_104 ( V_144 ) &&
F_105 ( V_144 ) != V_143 )
return false ;
if ( F_106 ( V_29 , V_144 ) )
return true ;
if ( ! V_142 )
return true ;
if ( ! F_107 ( V_143 , V_142 -> V_148 ) )
return false ;
if ( ! F_107 ( V_140 , V_142 -> V_148 ) )
return true ;
return F_93 ( V_29 , V_143 ) < ( F_93 ( V_29 , V_140 ) * 3 / 4 ) ;
}
static void F_108 ( struct V_149 * V_150 , int V_117 )
{
int V_151 , V_152 , V_8 = 0 ;
unsigned long V_153 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
F_109 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_110 ( V_152 ) ;
V_150 -> V_72 += V_24 -> V_72 ;
V_150 -> V_70 += F_111 ( V_152 ) ;
V_150 -> V_154 += F_112 ( V_152 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_151 = F_54 ( V_155 * V_8 , V_150 -> V_154 ) ;
V_153 = V_8 / V_151 ;
V_150 -> V_156 = F_5 ( unsigned , V_153 ,
F_113 ( V_150 -> V_154 , V_155 ) ) ;
V_150 -> V_157 = ( V_150 -> V_72 < V_150 -> V_156 ) ;
}
static void F_114 ( struct V_158 * V_159 ,
struct V_26 * V_29 , long V_160 )
{
if ( V_159 -> V_161 )
F_115 ( V_159 -> V_161 ) ;
V_159 -> V_161 = V_29 ;
V_159 -> V_162 = V_160 ;
V_159 -> V_163 = V_159 -> V_141 ;
}
static bool F_116 ( long V_164 , long V_165 ,
struct V_158 * V_159 )
{
long V_166 , V_167 ;
long V_168 , V_169 ;
long V_170 , V_171 ;
V_170 = V_159 -> V_172 . V_154 ;
V_171 = V_159 -> V_173 . V_154 ;
if ( V_165 < V_164 )
F_117 ( V_165 , V_164 ) ;
V_166 = V_165 * V_170 * 100 -
V_164 * V_171 * V_159 -> V_174 ;
if ( V_166 <= 0 )
return false ;
V_168 = V_159 -> V_172 . V_70 ;
V_169 = V_159 -> V_173 . V_70 ;
if ( V_169 < V_168 )
F_117 ( V_169 , V_168 ) ;
V_167 = V_169 * V_170 * 100 -
V_168 * V_171 * V_159 -> V_174 ;
return ( V_166 > V_167 ) ;
}
static void F_118 ( struct V_158 * V_159 ,
long V_175 , long V_176 )
{
struct V_24 * V_177 = F_110 ( V_159 -> V_178 ) ;
struct V_24 * V_179 = F_110 ( V_159 -> V_141 ) ;
struct V_26 * V_180 ;
long V_164 , V_165 ;
long V_70 ;
long V_160 = V_159 -> V_29 -> V_113 ? V_176 : V_175 ;
long V_181 = V_160 ;
int V_132 = V_159 -> V_132 ;
bool V_182 = false ;
F_119 () ;
F_120 ( & V_179 -> V_183 ) ;
V_180 = V_179 -> V_45 ;
if ( ( V_180 -> V_184 & V_185 ) || F_121 ( V_180 ) )
V_180 = NULL ;
else {
F_122 ( V_180 ) ;
}
F_123 ( & V_179 -> V_183 ) ;
if ( V_180 == V_159 -> V_29 )
goto V_186;
if ( V_180 ) {
if ( ! F_124 ( V_159 -> V_178 , F_125 ( V_180 ) ) )
goto V_186;
if ( V_180 -> V_113 == V_159 -> V_29 -> V_113 ) {
V_160 = V_175 + F_98 ( V_180 , V_159 -> V_140 , V_132 ) -
F_98 ( V_180 , V_159 -> V_143 , V_132 ) ;
if ( V_180 -> V_113 )
V_160 -= V_160 / 16 ;
} else {
if ( V_180 -> V_113 )
V_160 += F_99 ( V_180 , V_159 -> V_140 , V_132 ) -
F_99 ( V_180 , V_159 -> V_143 , V_132 ) ;
else
V_160 += F_98 ( V_180 , V_159 -> V_140 , V_132 ) -
F_98 ( V_180 , V_159 -> V_143 , V_132 ) ;
}
}
if ( V_160 <= V_159 -> V_162 && V_181 <= V_159 -> V_162 )
goto V_186;
if ( ! V_180 ) {
if ( V_159 -> V_172 . V_72 <= V_159 -> V_172 . V_156 &&
! V_159 -> V_173 . V_157 )
goto V_186;
goto V_187;
}
if ( V_160 > V_159 -> V_162 && V_177 -> V_72 == 1 &&
V_179 -> V_72 == 1 )
goto V_188;
V_187:
V_70 = F_126 ( V_159 -> V_29 ) ;
V_165 = V_159 -> V_173 . V_70 + V_70 ;
V_164 = V_159 -> V_172 . V_70 - V_70 ;
if ( V_181 > V_160 && V_181 > V_159 -> V_162 ) {
if ( ! F_116 ( V_164 , V_165 , V_159 ) ) {
V_160 = V_181 - 1 ;
F_115 ( V_180 ) ;
V_180 = NULL ;
goto V_188;
}
}
if ( V_160 <= V_159 -> V_162 )
goto V_186;
if ( V_180 ) {
V_70 = F_126 ( V_180 ) ;
V_165 -= V_70 ;
V_164 += V_70 ;
}
if ( F_116 ( V_164 , V_165 , V_159 ) )
goto V_186;
if ( ! V_180 )
V_159 -> V_141 = F_127 ( V_159 -> V_29 , V_159 -> V_141 ) ;
V_188:
V_182 = true ;
F_114 ( V_159 , V_180 , V_160 ) ;
V_186:
F_128 () ;
if ( V_180 && ! V_182 )
F_115 ( V_180 ) ;
}
static void F_129 ( struct V_158 * V_159 ,
long V_175 , long V_176 )
{
int V_152 ;
F_109 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_124 ( V_152 , F_125 ( V_159 -> V_29 ) ) )
continue;
V_159 -> V_141 = V_152 ;
F_118 ( V_159 , V_175 , V_176 ) ;
}
}
static bool F_130 ( struct V_158 * V_159 )
{
struct V_149 * V_189 = & V_159 -> V_172 ;
struct V_149 * V_190 = & V_159 -> V_173 ;
if ( V_189 -> V_157 && ! V_190 -> V_157 )
return false ;
if ( V_189 -> V_70 * V_190 -> V_154 * V_159 -> V_174 >
V_190 -> V_70 * V_189 -> V_154 * 100 )
return true ;
return false ;
}
static int F_131 ( struct V_26 * V_29 )
{
struct V_158 V_159 = {
. V_29 = V_29 ,
. V_178 = F_132 ( V_29 ) ,
. V_140 = F_88 ( V_29 ) ,
. V_174 = 112 ,
. V_161 = NULL ,
. V_162 = 0 ,
. V_163 = - 1
} ;
struct V_191 * V_192 ;
unsigned long V_193 , V_194 ;
int V_117 , V_66 , V_132 ;
long V_175 , V_176 ;
F_119 () ;
V_192 = F_133 ( F_134 ( V_195 , V_159 . V_178 ) ) ;
if ( V_192 )
V_159 . V_174 = 100 + ( V_192 -> V_174 - 100 ) / 2 ;
F_128 () ;
if ( F_13 ( ! V_192 ) ) {
V_29 -> V_111 = F_88 ( V_29 ) ;
return - V_196 ;
}
V_159 . V_143 = V_29 -> V_111 ;
V_132 = V_159 . V_132 = F_97 ( V_159 . V_140 , V_159 . V_143 ) ;
V_193 = F_98 ( V_29 , V_159 . V_140 , V_132 ) ;
V_194 = F_99 ( V_29 , V_159 . V_140 , V_132 ) ;
F_108 ( & V_159 . V_172 , V_159 . V_140 ) ;
V_175 = F_98 ( V_29 , V_159 . V_143 , V_132 ) - V_193 ;
V_176 = F_99 ( V_29 , V_159 . V_143 , V_132 ) - V_194 ;
F_108 ( & V_159 . V_173 , V_159 . V_143 ) ;
if ( F_130 ( & V_159 ) )
F_129 ( & V_159 , V_175 , V_176 ) ;
if ( V_159 . V_163 == - 1 || ( V_29 -> V_113 &&
F_135 ( V_29 -> V_113 -> V_148 ) > 1 ) ) {
F_96 (nid) {
if ( V_117 == V_159 . V_140 || V_117 == V_29 -> V_111 )
continue;
V_132 = F_97 ( V_159 . V_140 , V_159 . V_143 ) ;
if ( V_130 == V_134 &&
V_132 != V_159 . V_132 ) {
V_193 = F_98 ( V_29 , V_159 . V_140 , V_132 ) ;
V_194 = F_99 ( V_29 , V_159 . V_140 , V_132 ) ;
}
V_175 = F_98 ( V_29 , V_117 , V_132 ) - V_193 ;
V_176 = F_99 ( V_29 , V_117 , V_132 ) - V_194 ;
if ( V_175 < 0 && V_176 < 0 )
continue;
V_159 . V_132 = V_132 ;
V_159 . V_143 = V_117 ;
F_108 ( & V_159 . V_173 , V_159 . V_143 ) ;
if ( F_130 ( & V_159 ) )
F_129 ( & V_159 , V_175 , V_176 ) ;
}
}
if ( V_29 -> V_113 ) {
if ( V_159 . V_163 == - 1 )
V_117 = V_159 . V_140 ;
else
V_117 = V_159 . V_143 ;
if ( F_107 ( V_117 , V_29 -> V_113 -> V_148 ) )
F_136 ( V_29 , V_159 . V_143 ) ;
}
if ( V_159 . V_163 == - 1 )
return - V_197 ;
V_29 -> V_198 = F_83 ( V_29 ) ;
if ( V_159 . V_161 == NULL ) {
V_66 = F_137 ( V_29 , V_159 . V_163 ) ;
if ( V_66 != 0 )
F_138 ( V_29 , V_159 . V_178 , V_159 . V_163 ) ;
return V_66 ;
}
V_66 = F_139 ( V_29 , V_159 . V_161 ) ;
if ( V_66 != 0 )
F_138 ( V_29 , V_159 . V_178 , F_132 ( V_159 . V_161 ) ) ;
F_115 ( V_159 . V_161 ) ;
return V_66 ;
}
static void F_140 ( struct V_26 * V_29 )
{
unsigned long V_199 = V_200 ;
if ( F_13 ( V_29 -> V_111 == - 1 || ! V_29 -> V_121 ) )
return;
V_199 = F_141 ( V_199 , F_142 ( V_29 -> V_198 ) / 16 ) ;
V_29 -> V_201 = V_202 + V_199 ;
if ( F_88 ( V_29 ) == V_29 -> V_111 )
return;
F_131 ( V_29 ) ;
}
static void F_143 ( struct V_113 * V_113 )
{
unsigned long V_123 , V_203 = 0 ;
int V_117 ;
F_96 (nid) {
V_123 = F_94 ( V_113 , V_117 ) ;
if ( V_123 > V_203 )
V_203 = V_123 ;
}
F_96 (nid) {
V_123 = F_94 ( V_113 , V_117 ) ;
if ( ! F_107 ( V_117 , V_113 -> V_148 ) ) {
if ( V_123 > V_203 * 6 / 16 )
F_144 ( V_117 , V_113 -> V_148 ) ;
} else if ( V_123 < V_203 * 3 / 16 )
F_145 ( V_117 , V_113 -> V_148 ) ;
}
}
static void F_146 ( struct V_26 * V_29 ,
unsigned long V_204 , unsigned long V_205 )
{
unsigned int V_206 ;
int V_207 ;
int V_208 ;
unsigned long V_209 = V_29 -> V_210 [ 0 ] ;
unsigned long V_211 = V_29 -> V_210 [ 1 ] ;
if ( V_211 + V_204 == 0 || V_29 -> V_210 [ 2 ] ) {
V_29 -> V_198 = F_141 ( V_29 -> V_212 ,
V_29 -> V_198 << 1 ) ;
V_29 -> V_101 -> V_213 = V_202 +
F_142 ( V_29 -> V_198 ) ;
return;
}
V_206 = F_54 ( V_29 -> V_198 , V_214 ) ;
V_207 = ( V_211 * V_214 ) / ( V_211 + V_209 ) ;
if ( V_207 >= V_215 ) {
int V_216 = V_207 - V_215 ;
if ( ! V_216 )
V_216 = 1 ;
V_208 = V_216 * V_206 ;
} else {
V_208 = - ( V_215 - V_207 ) * V_206 ;
V_207 = F_54 ( V_205 * V_214 , ( V_205 + V_204 + 1 ) ) ;
V_208 = ( V_208 * V_207 ) / V_214 ;
}
V_29 -> V_198 = F_147 ( V_29 -> V_198 + V_208 ,
F_83 ( V_29 ) , F_86 ( V_29 ) ) ;
memset ( V_29 -> V_210 , 0 , sizeof( V_29 -> V_210 ) ) ;
}
static T_2 F_148 ( struct V_26 * V_29 , T_2 * V_217 )
{
T_2 V_218 , V_42 , V_86 ;
V_86 = V_29 -> V_28 . V_87 ;
V_218 = V_29 -> V_28 . V_90 ;
if ( V_29 -> V_219 ) {
V_42 = V_218 - V_29 -> V_220 ;
* V_217 = V_86 - V_29 -> V_219 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_70 . V_4 ;
* V_217 = V_82 ;
}
V_29 -> V_220 = V_218 ;
V_29 -> V_219 = V_86 ;
return V_42 ;
}
static int F_149 ( struct V_26 * V_29 , int V_117 )
{
T_8 V_221 ;
int V_132 ;
if ( V_130 == V_131 )
return V_117 ;
if ( V_130 == V_135 ) {
unsigned long V_128 , V_222 = 0 ;
int V_129 , V_223 = V_117 ;
V_132 = V_133 ;
F_96 (node) {
V_128 = F_99 ( V_29 , V_129 , V_132 ) ;
if ( V_128 > V_222 ) {
V_222 = V_128 ;
V_223 = V_129 ;
}
}
return V_223 ;
}
V_221 = V_224 ;
for ( V_132 = V_133 ; V_132 > V_136 ; V_132 -- ) {
unsigned long V_203 = 0 ;
T_8 V_225 = V_226 ;
int V_43 , V_44 ;
if ( ! F_150 ( V_132 ) )
continue;
F_151 (a, nodes) {
unsigned long V_123 = 0 ;
T_8 V_227 ;
F_152 ( V_227 ) ;
F_151 (b, nodes) {
if ( F_97 ( V_43 , V_44 ) < V_132 ) {
V_123 += F_93 ( V_29 , V_44 ) ;
F_144 ( V_44 , V_227 ) ;
F_145 ( V_44 , V_221 ) ;
}
}
if ( V_123 > V_203 ) {
V_203 = V_123 ;
V_225 = V_227 ;
V_117 = V_43 ;
}
}
if ( ! V_203 )
break;
V_221 = V_225 ;
}
return V_117 ;
}
static void F_153 ( struct V_26 * V_29 )
{
int V_228 , V_117 , V_229 = - 1 , V_230 = - 1 ;
unsigned long V_203 = 0 , V_231 = 0 ;
unsigned long V_232 [ 2 ] = { 0 , 0 } ;
unsigned long V_137 ;
T_2 V_218 , V_217 ;
T_9 * V_233 = NULL ;
V_228 = F_84 ( V_29 -> V_101 -> V_234 ) ;
if ( V_29 -> V_234 == V_228 )
return;
V_29 -> V_234 = V_228 ;
V_29 -> V_212 = F_86 ( V_29 ) ;
V_137 = V_29 -> V_210 [ 0 ] +
V_29 -> V_210 [ 1 ] ;
V_218 = F_148 ( V_29 , & V_217 ) ;
if ( V_29 -> V_113 ) {
V_233 = & V_29 -> V_113 -> V_183 ;
F_154 ( V_233 ) ;
}
F_96 (nid) {
int V_235 , V_236 , V_237 , V_238 ;
unsigned long V_123 = 0 , F_93 = 0 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
long V_208 , V_239 , V_240 ;
V_235 = F_91 ( V_122 , V_117 , V_118 ) ;
V_236 = F_91 ( V_241 , V_117 , V_118 ) ;
V_237 = F_91 ( V_242 , V_117 , V_118 ) ;
V_238 = F_91 ( V_243 , V_117 , V_118 ) ;
V_208 = V_29 -> V_121 [ V_236 ] - V_29 -> V_121 [ V_235 ] / 2 ;
V_232 [ V_118 ] += V_29 -> V_121 [ V_236 ] ;
V_29 -> V_121 [ V_236 ] = 0 ;
V_240 = F_155 ( V_218 << 16 , V_217 + 1 ) ;
V_240 = ( V_240 * V_29 -> V_121 [ V_238 ] ) /
( V_137 + 1 ) ;
V_239 = V_240 - V_29 -> V_121 [ V_237 ] / 2 ;
V_29 -> V_121 [ V_238 ] = 0 ;
V_29 -> V_121 [ V_235 ] += V_208 ;
V_29 -> V_121 [ V_237 ] += V_239 ;
V_123 += V_29 -> V_121 [ V_235 ] ;
V_29 -> V_138 += V_208 ;
if ( V_29 -> V_113 ) {
V_29 -> V_113 -> V_123 [ V_235 ] += V_208 ;
V_29 -> V_113 -> V_125 [ V_235 ] += V_239 ;
V_29 -> V_113 -> V_137 += V_208 ;
F_93 += V_29 -> V_113 -> V_123 [ V_235 ] ;
}
}
if ( V_123 > V_203 ) {
V_203 = V_123 ;
V_229 = V_117 ;
}
if ( F_93 > V_231 ) {
V_231 = F_93 ;
V_230 = V_117 ;
}
}
F_146 ( V_29 , V_232 [ 0 ] , V_232 [ 1 ] ) ;
if ( V_29 -> V_113 ) {
F_143 ( V_29 -> V_113 ) ;
F_156 ( V_233 ) ;
V_229 = F_149 ( V_29 , V_230 ) ;
}
if ( V_203 ) {
if ( V_229 != V_29 -> V_111 )
F_136 ( V_29 , V_229 ) ;
if ( F_88 ( V_29 ) != V_29 -> V_111 )
F_140 ( V_29 ) ;
}
}
static inline int F_157 ( struct V_113 * V_30 )
{
return F_158 ( & V_30 -> V_244 ) ;
}
static inline void F_159 ( struct V_113 * V_30 )
{
if ( F_160 ( & V_30 -> V_244 ) )
F_161 ( V_30 , V_245 ) ;
}
static void F_162 ( struct V_26 * V_29 , int V_246 , int V_184 ,
int * V_118 )
{
struct V_113 * V_30 , * V_247 ;
struct V_26 * V_248 ;
bool V_249 = false ;
int V_152 = F_163 ( V_246 ) ;
int V_250 ;
if ( F_13 ( ! V_29 -> V_113 ) ) {
unsigned int V_251 = sizeof( struct V_113 ) +
4 * V_120 *sizeof( unsigned long ) ;
V_30 = F_164 ( V_251 , V_252 | V_253 ) ;
if ( ! V_30 )
return;
F_165 ( & V_30 -> V_244 , 1 ) ;
F_166 ( & V_30 -> V_183 ) ;
V_30 -> V_114 = V_29 -> V_147 ;
V_30 -> V_125 = V_30 -> V_123 + V_119 *
V_120 ;
F_144 ( F_88 ( V_146 ) , V_30 -> V_148 ) ;
for ( V_250 = 0 ; V_250 < V_254 * V_120 ; V_250 ++ )
V_30 -> V_123 [ V_250 ] = V_29 -> V_121 [ V_250 ] ;
V_30 -> V_137 = V_29 -> V_138 ;
V_30 -> V_255 ++ ;
F_167 ( V_29 -> V_113 , V_30 ) ;
}
F_119 () ;
V_248 = F_84 ( F_110 ( V_152 ) -> V_45 ) ;
if ( ! F_106 ( V_248 , V_246 ) )
goto V_256;
V_30 = F_133 ( V_248 -> V_113 ) ;
if ( ! V_30 )
goto V_256;
V_247 = V_29 -> V_113 ;
if ( V_30 == V_247 )
goto V_256;
if ( V_247 -> V_255 > V_30 -> V_255 )
goto V_256;
if ( V_247 -> V_255 == V_30 -> V_255 && V_247 > V_30 )
goto V_256;
if ( V_248 -> V_101 == V_146 -> V_101 )
V_249 = true ;
if ( V_184 & V_257 )
V_249 = true ;
* V_118 = ! V_249 ;
if ( V_249 && ! F_157 ( V_30 ) )
goto V_256;
F_128 () ;
if ( ! V_249 )
return;
F_168 ( F_169 () ) ;
F_170 ( & V_247 -> V_183 , & V_30 -> V_183 ) ;
for ( V_250 = 0 ; V_250 < V_254 * V_120 ; V_250 ++ ) {
V_247 -> V_123 [ V_250 ] -= V_29 -> V_121 [ V_250 ] ;
V_30 -> V_123 [ V_250 ] += V_29 -> V_121 [ V_250 ] ;
}
V_247 -> V_137 -= V_29 -> V_138 ;
V_30 -> V_137 += V_29 -> V_138 ;
V_247 -> V_255 -- ;
V_30 -> V_255 ++ ;
F_171 ( & V_247 -> V_183 ) ;
F_156 ( & V_30 -> V_183 ) ;
F_167 ( V_29 -> V_113 , V_30 ) ;
F_159 ( V_247 ) ;
return;
V_256:
F_128 () ;
return;
}
void F_172 ( struct V_26 * V_29 )
{
struct V_113 * V_30 = V_29 -> V_113 ;
void * V_121 = V_29 -> V_121 ;
unsigned long V_184 ;
int V_250 ;
if ( V_30 ) {
F_173 ( & V_30 -> V_183 , V_184 ) ;
for ( V_250 = 0 ; V_250 < V_254 * V_120 ; V_250 ++ )
V_30 -> V_123 [ V_250 ] -= V_29 -> V_121 [ V_250 ] ;
V_30 -> V_137 -= V_29 -> V_138 ;
V_30 -> V_255 -- ;
F_174 ( & V_30 -> V_183 , V_184 ) ;
F_175 ( V_29 -> V_113 , NULL ) ;
F_159 ( V_30 ) ;
}
V_29 -> V_121 = NULL ;
F_176 ( V_121 ) ;
}
void F_177 ( int V_144 , int V_258 , int V_259 , int V_184 )
{
struct V_26 * V_29 = V_146 ;
bool V_260 = V_184 & V_261 ;
int V_262 = F_88 ( V_146 ) ;
int V_211 = ! ! ( V_184 & V_263 ) ;
int V_118 ;
if ( ! F_178 ( & V_264 ) )
return;
if ( ! V_29 -> V_101 )
return;
if ( F_13 ( ! V_29 -> V_121 ) ) {
int V_251 = sizeof( * V_29 -> V_121 ) *
V_265 * V_120 ;
V_29 -> V_121 = F_164 ( V_251 , V_252 | V_253 ) ;
if ( ! V_29 -> V_121 )
return;
V_29 -> V_138 = 0 ;
memset ( V_29 -> V_210 , 0 , sizeof( V_29 -> V_210 ) ) ;
}
if ( F_13 ( V_144 == ( - 1 & V_266 ) ) ) {
V_118 = 1 ;
} else {
V_118 = F_106 ( V_29 , V_144 ) ;
if ( ! V_118 && ! ( V_184 & V_267 ) )
F_162 ( V_29 , V_144 , V_184 , & V_118 ) ;
}
if ( ! V_118 && ! V_211 && V_29 -> V_113 &&
F_107 ( V_262 , V_29 -> V_113 -> V_148 ) &&
F_107 ( V_258 , V_29 -> V_113 -> V_148 ) )
V_211 = 1 ;
F_153 ( V_29 ) ;
if ( F_179 ( V_202 , V_29 -> V_201 ) )
F_140 ( V_29 ) ;
if ( V_260 )
V_29 -> V_268 += V_259 ;
if ( V_184 & V_269 )
V_29 -> V_210 [ 2 ] += V_259 ;
V_29 -> V_121 [ F_91 ( V_241 , V_258 , V_118 ) ] += V_259 ;
V_29 -> V_121 [ F_91 ( V_243 , V_262 , V_118 ) ] += V_259 ;
V_29 -> V_210 [ V_211 ] += V_259 ;
}
static void F_180 ( struct V_26 * V_29 )
{
F_181 ( V_29 -> V_101 -> V_234 , F_84 ( V_29 -> V_101 -> V_234 ) + 1 ) ;
V_29 -> V_101 -> V_270 = 0 ;
}
void F_182 ( struct V_271 * V_272 )
{
unsigned long V_273 , V_274 , V_86 = V_202 ;
struct V_26 * V_29 = V_146 ;
struct V_275 * V_101 = V_29 -> V_101 ;
T_2 V_218 = V_29 -> V_28 . V_90 ;
struct V_276 * V_277 ;
unsigned long V_278 , V_279 ;
unsigned long V_280 = 0 ;
long V_259 , V_281 ;
F_19 ( V_29 != F_21 ( V_272 , struct V_26 , V_282 ) ) ;
V_272 -> V_58 = V_272 ;
if ( V_29 -> V_184 & V_185 )
return;
if ( ! V_101 -> V_213 ) {
V_101 -> V_213 = V_86 +
F_142 ( V_283 ) ;
}
V_273 = V_101 -> V_213 ;
if ( F_183 ( V_86 , V_273 ) )
return;
if ( V_29 -> V_198 == 0 ) {
V_29 -> V_212 = F_86 ( V_29 ) ;
V_29 -> V_198 = F_83 ( V_29 ) ;
}
V_274 = V_86 + F_142 ( V_29 -> V_198 ) ;
if ( F_184 ( & V_101 -> V_213 , V_273 , V_274 ) != V_273 )
return;
V_29 -> V_284 += 2 * V_285 ;
V_278 = V_101 -> V_270 ;
V_259 = V_99 ;
V_259 <<= 20 - V_100 ;
V_281 = V_259 * 8 ;
if ( ! V_259 )
return;
F_185 ( & V_101 -> V_286 ) ;
V_277 = F_186 ( V_101 , V_278 ) ;
if ( ! V_277 ) {
F_180 ( V_29 ) ;
V_278 = 0 ;
V_277 = V_101 -> V_287 ;
}
for (; V_277 ; V_277 = V_277 -> V_288 ) {
if ( ! F_187 ( V_277 ) || ! F_188 ( V_277 ) ||
F_189 ( V_277 ) || ( V_277 -> V_289 & V_290 ) ) {
continue;
}
if ( ! V_277 -> V_291 ||
( V_277 -> V_292 && ( V_277 -> V_289 & ( V_293 | V_294 ) ) == ( V_293 ) ) )
continue;
if ( ! ( V_277 -> V_289 & ( V_293 | V_295 | V_294 ) ) )
continue;
do {
V_278 = F_65 ( V_278 , V_277 -> V_296 ) ;
V_279 = F_190 ( V_278 + ( V_259 << V_100 ) , V_297 ) ;
V_279 = F_141 ( V_279 , V_277 -> V_298 ) ;
V_280 = F_191 ( V_277 , V_278 , V_279 ) ;
if ( V_280 )
V_259 -= ( V_279 - V_278 ) >> V_100 ;
V_281 -= ( V_279 - V_278 ) >> V_100 ;
V_278 = V_279 ;
if ( V_259 <= 0 || V_281 <= 0 )
goto V_299;
F_192 () ;
} while ( V_279 != V_277 -> V_298 );
}
V_299:
if ( V_277 )
V_101 -> V_270 = V_278 ;
else
F_180 ( V_29 ) ;
F_193 ( & V_101 -> V_286 ) ;
if ( F_13 ( V_29 -> V_28 . V_90 != V_218 ) ) {
T_2 V_208 = V_29 -> V_28 . V_90 - V_218 ;
V_29 -> V_284 += 32 * V_208 ;
}
}
void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_271 * V_272 = & V_45 -> V_282 ;
T_2 V_217 , V_86 ;
if ( ! V_45 -> V_101 || ( V_45 -> V_184 & V_185 ) || V_272 -> V_58 != V_272 )
return;
V_86 = V_45 -> V_28 . V_90 ;
V_217 = ( T_2 ) V_45 -> V_198 * V_300 ;
if ( V_86 > V_45 -> V_284 + V_217 ) {
if ( ! V_45 -> V_284 )
V_45 -> V_198 = F_83 ( V_45 ) ;
V_45 -> V_284 += V_217 ;
if ( ! F_183 ( V_202 , V_45 -> V_101 -> V_213 ) ) {
F_195 ( V_272 , F_182 ) ;
F_196 ( V_45 , V_272 , true ) ;
}
}
}
static void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_87 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_197 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_1 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_198
if ( F_20 ( V_28 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_87 ( V_24 , F_17 ( V_28 ) ) ;
F_199 ( & V_28 -> V_301 , & V_24 -> V_302 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_200 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_2 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_20 ( V_28 ) ) {
F_89 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_201 ( & V_28 -> V_301 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_202 ( struct V_303 * V_33 , struct V_25 * V_25 )
{
long V_304 ;
V_304 = F_203 ( & V_33 -> V_80 ) ;
V_304 -= V_25 -> V_305 ;
V_304 += V_25 -> V_70 . V_4 ;
return V_304 ;
}
static long F_204 ( struct V_25 * V_25 , struct V_303 * V_33 )
{
long V_304 , V_70 , V_306 ;
V_304 = F_202 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_306 = ( V_33 -> V_306 * V_70 ) ;
if ( V_304 )
V_306 /= V_304 ;
if ( V_306 < V_307 )
V_306 = V_307 ;
if ( V_306 > V_33 -> V_306 )
V_306 = V_33 -> V_306 ;
return V_306 ;
}
static inline long F_204 ( struct V_25 * V_25 , struct V_303 * V_33 )
{
return V_33 -> V_306 ;
}
static void F_205 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_74 ) {
if ( V_25 -> V_45 == V_28 )
F_62 ( V_25 ) ;
F_200 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_74 )
F_197 ( V_25 , V_28 ) ;
}
static void F_206 ( struct V_25 * V_25 )
{
struct V_303 * V_33 ;
struct V_27 * V_28 ;
long V_306 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_207 ( V_25 ) )
return;
#ifndef F_198
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_306 ) )
return;
#endif
V_306 = F_204 ( V_25 , V_33 ) ;
F_205 ( F_23 ( V_28 ) , V_28 , V_306 ) ;
}
static inline void F_206 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_208 ( T_2 V_308 , T_2 V_309 )
{
unsigned int V_310 ;
if ( ! V_309 )
return V_308 ;
else if ( F_13 ( V_309 > V_311 * 63 ) )
return 0 ;
V_310 = V_309 ;
if ( F_13 ( V_310 >= V_311 ) ) {
V_308 >>= V_310 / V_311 ;
V_310 %= V_311 ;
}
V_308 = F_15 ( V_308 , V_312 [ V_310 ] , 32 ) ;
return V_308 ;
}
static V_23 F_209 ( T_2 V_309 )
{
V_23 V_313 = 0 ;
if ( F_11 ( V_309 <= V_311 ) )
return V_314 [ V_309 ] ;
else if ( F_13 ( V_309 >= V_315 ) )
return V_82 ;
do {
V_313 /= 2 ;
V_313 += V_314 [ V_311 ] ;
V_309 -= V_311 ;
} while ( V_309 > V_311 );
V_313 = F_208 ( V_313 , V_309 ) ;
return V_313 + V_314 [ V_309 ] ;
}
static T_10 int
F_210 ( T_2 V_86 , int V_152 , struct V_75 * V_76 ,
unsigned long V_4 , int V_316 , struct V_25 * V_25 )
{
T_2 V_42 , V_317 , V_318 ;
V_23 V_313 ;
unsigned int V_319 , V_320 , V_321 = 0 ;
unsigned long V_322 , V_323 ;
V_42 = V_86 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_86 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_86 ;
V_322 = F_211 ( NULL , V_152 ) ;
V_323 = F_212 ( NULL , V_152 ) ;
V_319 = V_76 -> V_79 ;
if ( V_42 + V_319 >= 1024 ) {
V_321 = 1 ;
V_76 -> V_79 = 0 ;
V_319 = 1024 - V_319 ;
V_320 = F_213 ( V_319 , V_322 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_320 ;
if ( V_25 ) {
V_25 -> V_324 +=
V_4 * V_320 ;
}
}
if ( V_316 )
V_76 -> V_85 += V_320 * V_323 ;
V_42 -= V_319 ;
V_318 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_208 ( V_76 -> V_81 , V_318 + 1 ) ;
if ( V_25 ) {
V_25 -> V_324 =
F_208 ( V_25 -> V_324 , V_318 + 1 ) ;
}
V_76 -> V_85 = F_208 ( ( T_2 ) ( V_76 -> V_85 ) , V_318 + 1 ) ;
V_313 = F_209 ( V_318 ) ;
V_313 = F_213 ( V_313 , V_322 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_313 ;
if ( V_25 )
V_25 -> V_324 += V_4 * V_313 ;
}
if ( V_316 )
V_76 -> V_85 += V_313 * V_323 ;
}
V_317 = F_213 ( V_42 , V_322 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_317 ;
if ( V_25 )
V_25 -> V_324 += V_4 * V_317 ;
}
if ( V_316 )
V_76 -> V_85 += V_317 * V_323 ;
V_76 -> V_79 += V_42 ;
if ( V_321 ) {
V_76 -> V_80 = F_214 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_325 =
F_214 ( V_25 -> V_324 , V_82 ) ;
}
V_76 -> V_83 = V_76 -> V_85 / V_82 ;
}
return V_321 ;
}
static inline void F_215 ( struct V_25 * V_25 , int V_326 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_305 ;
if ( V_25 -> V_33 == & V_327 )
return;
if ( V_326 || abs ( V_42 ) > V_25 -> V_305 / 64 ) {
F_216 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_305 = V_25 -> V_77 . V_80 ;
}
}
void F_217 ( struct V_27 * V_28 ,
struct V_25 * V_328 , struct V_25 * V_58 )
{
if ( ! F_218 ( V_329 ) )
return;
if ( V_28 -> V_77 . V_78 && V_328 ) {
T_2 V_330 ;
T_2 V_331 ;
#ifndef F_40
T_2 V_332 ;
T_2 V_333 ;
do {
V_332 = V_328 -> V_334 ;
V_333 = V_58 -> V_334 ;
F_219 () ;
V_330 = V_328 -> V_77 . V_78 ;
V_331 = V_58 -> V_77 . V_78 ;
} while ( V_330 != V_332 ||
V_331 != V_333 );
#else
V_330 = V_328 -> V_77 . V_78 ;
V_331 = V_58 -> V_77 . V_78 ;
#endif
F_210 ( V_330 , F_26 ( F_16 ( V_328 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
V_28 -> V_77 . V_78 = V_331 ;
}
}
static inline void F_215 ( struct V_25 * V_25 , int V_326 ) {}
static inline int F_220 ( T_2 V_86 , struct V_25 * V_25 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_321 , V_335 = 0 ;
if ( F_203 ( & V_25 -> V_336 ) ) {
T_3 V_337 = F_221 ( & V_25 -> V_336 , 0 ) ;
V_76 -> V_80 = F_85 ( long , V_76 -> V_80 - V_337 , 0 ) ;
V_76 -> V_81 = F_85 ( T_3 , V_76 -> V_81 - V_337 * V_82 , 0 ) ;
V_335 = 1 ;
}
if ( F_203 ( & V_25 -> V_338 ) ) {
long V_337 = F_221 ( & V_25 -> V_338 , 0 ) ;
V_76 -> V_83 = F_85 ( long , V_76 -> V_83 - V_337 , 0 ) ;
V_76 -> V_85 = F_85 ( V_339 , V_76 -> V_85 - V_337 * V_82 , 0 ) ;
}
V_321 = F_210 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_70 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_334 = V_76 -> V_78 ;
#endif
return V_321 || V_335 ;
}
static inline void F_222 ( struct V_27 * V_28 , int V_340 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_86 = F_223 ( V_25 ) ;
int V_152 = F_26 ( F_16 ( V_25 ) ) ;
F_210 ( V_86 , V_152 , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
if ( F_220 ( V_86 , V_25 ) && V_340 )
F_215 ( V_25 , 0 ) ;
}
static void F_224 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( ! F_218 ( V_329 ) )
goto V_341;
if ( V_28 -> V_77 . V_78 ) {
F_210 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
}
V_341:
V_28 -> V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_28 -> V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_28 -> V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_28 -> V_77 . V_83 ;
V_25 -> V_77 . V_85 += V_28 -> V_77 . V_85 ;
}
static void F_225 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_210 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
V_25 -> V_77 . V_80 = F_85 ( long , V_25 -> V_77 . V_80 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_77 . V_81 = F_85 ( T_3 , V_25 -> V_77 . V_81 - V_28 -> V_77 . V_81 , 0 ) ;
V_25 -> V_77 . V_83 = F_85 ( long , V_25 -> V_77 . V_83 - V_28 -> V_77 . V_83 , 0 ) ;
V_25 -> V_77 . V_85 = F_85 ( V_339 , V_25 -> V_77 . V_85 - V_28 -> V_77 . V_85 , 0 ) ;
}
static inline void
F_226 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_86 = F_223 ( V_25 ) ;
int V_260 , V_321 ;
V_260 = ! V_76 -> V_78 ;
if ( ! V_260 ) {
F_210 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_321 = F_220 ( V_86 , V_25 ) ;
V_25 -> V_325 += V_76 -> V_80 ;
V_25 -> V_324 += V_76 -> V_81 ;
if ( V_260 )
F_224 ( V_25 , V_28 ) ;
if ( V_321 || V_260 )
F_215 ( V_25 , 0 ) ;
}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_222 ( V_28 , 1 ) ;
V_25 -> V_325 =
F_85 ( long , V_25 -> V_325 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_324 =
F_85 ( T_3 , V_25 -> V_324 - V_28 -> V_77 . V_81 , 0 ) ;
}
static inline T_2 F_228 ( struct V_25 * V_25 )
{
T_2 V_342 ;
T_2 V_78 ;
do {
V_342 = V_25 -> V_334 ;
F_219 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_342 );
return V_78 ;
}
static inline T_2 F_228 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_78 ;
}
void F_229 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_78 ;
if ( V_28 -> V_77 . V_78 == 0 )
return;
V_78 = F_228 ( V_25 ) ;
F_210 ( V_78 , F_26 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_216 ( V_28 -> V_77 . V_80 , & V_25 -> V_336 ) ;
F_216 ( V_28 -> V_77 . V_83 , & V_25 -> V_338 ) ;
}
static inline unsigned long F_230 ( struct V_25 * V_25 )
{
return V_25 -> V_325 ;
}
static inline unsigned long F_231 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline void F_222 ( struct V_27 * V_28 , int V_340 ) {}
static inline void
F_226 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_229 ( struct V_27 * V_28 ) {}
static inline void
F_224 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_225 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline int F_232 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_233 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_234
struct V_26 * V_248 = NULL ;
if ( F_20 ( V_28 ) )
V_248 = F_17 ( V_28 ) ;
if ( V_28 -> V_88 . V_343 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_343 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_344 ) )
V_28 -> V_88 . V_344 = V_42 ;
V_28 -> V_88 . V_343 = 0 ;
V_28 -> V_88 . V_345 += V_42 ;
if ( V_248 ) {
F_235 ( V_248 , V_42 >> 10 , 1 ) ;
F_236 ( V_248 , V_42 ) ;
}
}
if ( V_28 -> V_88 . V_346 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_346 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_347 ) )
V_28 -> V_88 . V_347 = V_42 ;
V_28 -> V_88 . V_346 = 0 ;
V_28 -> V_88 . V_345 += V_42 ;
if ( V_248 ) {
if ( V_248 -> V_348 ) {
V_28 -> V_88 . V_349 += V_42 ;
V_28 -> V_88 . V_350 ++ ;
F_237 ( V_248 , V_42 ) ;
}
F_238 ( V_248 , V_42 ) ;
if ( F_13 ( V_351 == V_352 ) ) {
F_239 ( V_352 ,
( void * ) F_240 ( V_248 ) ,
V_42 >> 20 ) ;
}
F_235 ( V_248 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_241 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_353 = V_28 -> V_41 - V_25 -> F_36 ;
if ( V_353 < 0 )
V_353 = - V_353 ;
if ( V_353 > 3 * V_68 )
F_242 ( V_25 , V_354 ) ;
#endif
}
static void
F_243 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_355 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_355 && F_218 ( V_356 ) )
V_41 += F_60 ( V_25 , V_28 ) ;
if ( ! V_355 ) {
unsigned long V_357 = V_68 ;
if ( F_218 ( V_358 ) )
V_357 >>= 1 ;
V_41 -= V_357 ;
}
V_28 -> V_41 = F_35 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_244 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_184 )
{
if ( ! ( V_184 & V_359 ) || ( V_184 & V_360 ) )
V_28 -> V_41 += V_25 -> F_36 ;
F_62 ( V_25 ) ;
F_226 ( V_25 , V_28 ) ;
F_197 ( V_25 , V_28 ) ;
F_206 ( V_25 ) ;
if ( V_184 & V_359 ) {
F_243 ( V_25 , V_28 , 0 ) ;
F_233 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_241 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_42 ( V_25 , V_28 ) ;
V_28 -> V_74 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_245 ( V_25 ) ;
}
}
static void F_246 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_247 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_248 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_361 != V_28 )
break;
V_25 -> V_361 = NULL ;
}
}
static void F_249 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_246 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_247 ( V_28 ) ;
if ( V_25 -> V_361 == V_28 )
F_248 ( V_28 ) ;
}
static void
F_250 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_184 )
{
F_62 ( V_25 ) ;
F_227 ( V_25 , V_28 ) ;
F_78 ( V_25 , V_28 ) ;
if ( V_184 & V_362 ) {
#ifdef F_234
if ( F_20 ( V_28 ) ) {
struct V_26 * V_248 = F_17 ( V_28 ) ;
if ( V_248 -> V_363 & V_364 )
V_28 -> V_88 . V_343 = F_73 ( F_16 ( V_25 ) ) ;
if ( V_248 -> V_363 & V_365 )
V_28 -> V_88 . V_346 = F_73 ( F_16 ( V_25 ) ) ;
}
#endif
}
F_249 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_45 ( V_25 , V_28 ) ;
V_28 -> V_74 = 0 ;
F_200 ( V_25 , V_28 ) ;
if ( ! ( V_184 & V_362 ) )
V_28 -> V_41 -= V_25 -> F_36 ;
F_251 ( V_25 ) ;
F_38 ( V_25 ) ;
F_206 ( V_25 ) ;
}
static void
F_252 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_366 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_366 = F_58 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_90 - V_45 -> V_367 ;
if ( V_19 > V_366 ) {
F_253 ( F_16 ( V_25 ) ) ;
F_249 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_48 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_366 )
F_253 ( F_16 ( V_25 ) ) ;
}
static void
F_254 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_74 ) {
F_75 ( V_25 , V_28 ) ;
F_45 ( V_25 , V_28 ) ;
F_222 ( V_28 , 1 ) ;
}
F_79 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_234
if ( F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_88 . V_368 = F_65 ( V_28 -> V_88 . V_368 ,
V_28 -> V_90 - V_28 -> V_367 ) ;
}
#endif
V_28 -> V_367 = V_28 -> V_90 ;
}
static struct V_27 *
F_255 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_48 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_37 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_361 == V_28 ) {
struct V_27 * V_369 ;
if ( V_28 == V_45 ) {
V_369 = F_48 ( V_25 ) ;
} else {
V_369 = F_49 ( V_28 ) ;
if ( ! V_369 || ( V_45 && F_37 ( V_45 , V_369 ) ) )
V_369 = V_45 ;
}
if ( V_369 && F_256 ( V_369 , V_57 ) < 1 )
V_28 = V_369 ;
}
if ( V_25 -> V_59 && F_256 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_256 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_249 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_257 ( struct V_25 * V_25 , struct V_27 * V_328 )
{
if ( V_328 -> V_74 )
F_62 ( V_25 ) ;
F_258 ( V_25 ) ;
F_241 ( V_25 , V_328 ) ;
if ( V_328 -> V_74 ) {
F_72 ( V_25 , V_328 ) ;
F_42 ( V_25 , V_328 ) ;
F_222 ( V_328 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_259 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_370 )
{
F_62 ( V_25 ) ;
F_222 ( V_45 , 1 ) ;
F_206 ( V_25 ) ;
#ifdef F_260
if ( V_370 ) {
F_253 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_218 ( V_371 ) &&
F_261 ( & F_16 ( V_25 ) -> V_372 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_252 ( V_25 , V_45 ) ;
}
static inline bool F_262 ( void )
{
return F_263 ( & V_373 ) ;
}
void F_264 ( void )
{
F_265 ( & V_373 ) ;
}
void F_266 ( void )
{
F_267 ( & V_373 ) ;
}
static bool F_262 ( void )
{
return true ;
}
void F_264 ( void ) {}
void F_266 ( void ) {}
static inline T_2 F_268 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_269 ( void )
{
return ( T_2 ) V_374 * V_375 ;
}
void F_270 ( struct V_376 * V_377 )
{
T_2 V_86 ;
if ( V_377 -> V_378 == V_379 )
return;
V_86 = F_271 ( F_272 () ) ;
V_377 -> V_218 = V_377 -> V_378 ;
V_377 -> V_380 = V_86 + F_273 ( V_377 -> V_217 ) ;
}
static inline struct V_376 * F_274 ( struct V_303 * V_33 )
{
return & V_33 -> V_376 ;
}
static inline T_2 F_223 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_381 ) )
return V_25 -> V_382 ;
return F_63 ( F_16 ( V_25 ) ) - V_25 -> V_383 ;
}
static int F_275 ( struct V_25 * V_25 )
{
struct V_303 * V_33 = V_25 -> V_33 ;
struct V_376 * V_377 = F_274 ( V_33 ) ;
T_2 V_384 = 0 , V_385 , V_386 ;
V_385 = F_269 () - V_25 -> V_387 ;
F_276 ( & V_377 -> V_183 ) ;
if ( V_377 -> V_378 == V_379 )
V_384 = V_385 ;
else {
F_277 ( V_377 ) ;
if ( V_377 -> V_218 > 0 ) {
V_384 = F_141 ( V_377 -> V_218 , V_385 ) ;
V_377 -> V_218 -= V_384 ;
V_377 -> V_388 = 0 ;
}
}
V_386 = V_377 -> V_380 ;
F_278 ( & V_377 -> V_183 ) ;
V_25 -> V_387 += V_384 ;
if ( ( T_3 ) ( V_386 - V_25 -> V_380 ) > 0 )
V_25 -> V_380 = V_386 ;
return V_25 -> V_387 > 0 ;
}
static void F_279 ( struct V_25 * V_25 )
{
struct V_376 * V_377 = F_274 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_73 ( F_16 ( V_25 ) ) - V_25 -> V_380 ) < 0 ) )
return;
if ( V_25 -> V_387 < 0 )
return;
if ( V_25 -> V_380 != V_377 -> V_380 ) {
V_25 -> V_380 += V_285 ;
} else {
V_25 -> V_387 = 0 ;
}
}
static void F_280 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_387 -= V_19 ;
F_279 ( V_25 ) ;
if ( F_11 ( V_25 -> V_387 > 0 ) )
return;
if ( ! F_275 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_253 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_70 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_262 () || ! V_25 -> V_389 )
return;
F_280 ( V_25 , V_19 ) ;
}
static inline int F_281 ( struct V_25 * V_25 )
{
return F_262 () && V_25 -> V_390 ;
}
static inline int F_207 ( struct V_25 * V_25 )
{
return F_262 () && V_25 -> V_381 ;
}
static inline int F_282 ( struct V_303 * V_33 ,
int V_178 , int V_391 )
{
struct V_25 * V_392 , * V_393 ;
V_392 = V_33 -> V_25 [ V_178 ] ;
V_393 = V_33 -> V_25 [ V_391 ] ;
return F_207 ( V_392 ) ||
F_207 ( V_393 ) ;
}
static int F_283 ( struct V_303 * V_33 , void * V_394 )
{
struct V_24 * V_24 = V_394 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_381 -- ;
#ifdef F_198
if ( ! V_25 -> V_381 ) {
V_25 -> V_383 += F_63 ( V_24 ) -
V_25 -> V_382 ;
}
#endif
return 0 ;
}
static int F_284 ( struct V_303 * V_33 , void * V_394 )
{
struct V_24 * V_24 = V_394 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_381 )
V_25 -> V_382 = F_63 ( V_24 ) ;
V_25 -> V_381 ++ ;
return 0 ;
}
static void F_285 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_376 * V_377 = F_274 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_395 , V_396 = 1 ;
bool V_397 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_119 () ;
F_286 ( V_25 -> V_33 , F_284 , V_398 , ( void * ) V_24 ) ;
F_128 () ;
V_395 = V_25 -> V_399 ;
F_59 (se) {
struct V_25 * V_400 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_74 )
break;
if ( V_396 )
F_250 ( V_400 , V_28 , V_362 ) ;
V_400 -> V_399 -= V_395 ;
if ( V_400 -> V_70 . V_4 )
V_396 = 0 ;
}
if ( ! V_28 )
F_287 ( V_24 , V_395 ) ;
V_25 -> V_390 = 1 ;
V_25 -> V_401 = F_73 ( V_24 ) ;
F_276 ( & V_377 -> V_183 ) ;
V_397 = F_288 ( & V_377 -> V_402 ) ;
F_27 ( & V_25 -> V_403 , & V_377 -> V_402 ) ;
if ( V_397 )
F_277 ( V_377 ) ;
F_278 ( & V_377 -> V_183 ) ;
}
void F_289 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_376 * V_377 = F_274 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_404 = 1 ;
long V_395 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_390 = 0 ;
F_290 ( V_24 ) ;
F_276 ( & V_377 -> V_183 ) ;
V_377 -> V_405 += F_73 ( V_24 ) - V_25 -> V_401 ;
F_30 ( & V_25 -> V_403 ) ;
F_278 ( & V_377 -> V_183 ) ;
F_286 ( V_25 -> V_33 , V_398 , F_283 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_395 = V_25 -> V_399 ;
F_59 (se) {
if ( V_28 -> V_74 )
V_404 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_404 )
F_244 ( V_25 , V_28 , V_359 ) ;
V_25 -> V_399 += V_395 ;
if ( F_281 ( V_25 ) )
break;
}
if ( ! V_28 )
F_291 ( V_24 , V_395 ) ;
if ( V_24 -> V_45 == V_24 -> V_388 && V_24 -> V_40 . V_72 )
F_253 ( V_24 ) ;
}
static T_2 F_292 ( struct V_376 * V_377 ,
T_2 V_406 , T_2 V_386 )
{
struct V_25 * V_25 ;
T_2 V_218 ;
T_2 V_407 = V_406 ;
F_119 () ;
F_293 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_276 ( & V_24 -> V_183 ) ;
if ( ! F_281 ( V_25 ) )
goto V_58;
V_218 = - V_25 -> V_387 + 1 ;
if ( V_218 > V_406 )
V_218 = V_406 ;
V_406 -= V_218 ;
V_25 -> V_387 += V_218 ;
V_25 -> V_380 = V_386 ;
if ( V_25 -> V_387 > 0 )
F_289 ( V_25 ) ;
V_58:
F_278 ( & V_24 -> V_183 ) ;
if ( ! V_406 )
break;
}
F_128 () ;
return V_407 - V_406 ;
}
static int F_294 ( struct V_376 * V_377 , int V_408 )
{
T_2 V_218 , V_380 ;
int V_390 ;
if ( V_377 -> V_378 == V_379 )
goto V_409;
V_390 = ! F_288 ( & V_377 -> V_402 ) ;
V_377 -> V_410 += V_408 ;
if ( V_377 -> V_388 && ! V_390 )
goto V_409;
F_270 ( V_377 ) ;
if ( ! V_390 ) {
V_377 -> V_388 = 1 ;
return 0 ;
}
V_377 -> V_411 += V_408 ;
V_380 = V_377 -> V_380 ;
while ( V_390 && V_377 -> V_218 > 0 ) {
V_218 = V_377 -> V_218 ;
F_278 ( & V_377 -> V_183 ) ;
V_218 = F_292 ( V_377 , V_218 ,
V_380 ) ;
F_276 ( & V_377 -> V_183 ) ;
V_390 = ! F_288 ( & V_377 -> V_402 ) ;
V_377 -> V_218 -= F_141 ( V_218 , V_377 -> V_218 ) ;
}
V_377 -> V_388 = 0 ;
return 0 ;
V_409:
return 1 ;
}
static int F_295 ( struct V_376 * V_377 , T_2 V_412 )
{
struct V_413 * V_414 = & V_377 -> V_415 ;
T_2 V_406 ;
if ( F_296 ( V_414 ) )
return 1 ;
V_406 = F_273 ( F_297 ( V_414 ) ) ;
if ( V_406 < V_412 )
return 1 ;
return 0 ;
}
static void F_298 ( struct V_376 * V_377 )
{
T_2 V_416 = V_417 + V_418 ;
if ( F_295 ( V_377 , V_416 ) )
return;
F_299 ( & V_377 -> V_419 ,
F_300 ( V_417 ) ,
V_420 ) ;
}
static void F_301 ( struct V_25 * V_25 )
{
struct V_376 * V_377 = F_274 ( V_25 -> V_33 ) ;
T_3 V_421 = V_25 -> V_387 - V_422 ;
if ( V_421 <= 0 )
return;
F_276 ( & V_377 -> V_183 ) ;
if ( V_377 -> V_378 != V_379 &&
V_25 -> V_380 == V_377 -> V_380 ) {
V_377 -> V_218 += V_421 ;
if ( V_377 -> V_218 > F_269 () &&
! F_288 ( & V_377 -> V_402 ) )
F_298 ( V_377 ) ;
}
F_278 ( & V_377 -> V_183 ) ;
V_25 -> V_387 -= V_421 ;
}
static T_10 void F_251 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return;
if ( ! V_25 -> V_389 || V_25 -> V_72 )
return;
F_301 ( V_25 ) ;
}
static void F_302 ( struct V_376 * V_377 )
{
T_2 V_218 = 0 , V_73 = F_269 () ;
T_2 V_386 ;
F_276 ( & V_377 -> V_183 ) ;
if ( F_295 ( V_377 , V_418 ) ) {
F_278 ( & V_377 -> V_183 ) ;
return;
}
if ( V_377 -> V_378 != V_379 && V_377 -> V_218 > V_73 )
V_218 = V_377 -> V_218 ;
V_386 = V_377 -> V_380 ;
F_278 ( & V_377 -> V_183 ) ;
if ( ! V_218 )
return;
V_218 = F_292 ( V_377 , V_218 , V_386 ) ;
F_276 ( & V_377 -> V_183 ) ;
if ( V_386 == V_377 -> V_380 )
V_377 -> V_218 -= F_141 ( V_218 , V_377 -> V_218 ) ;
F_278 ( & V_377 -> V_183 ) ;
}
static void F_245 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return;
if ( ! V_25 -> V_389 || V_25 -> V_45 )
return;
if ( F_281 ( V_25 ) )
return;
F_70 ( V_25 , 0 ) ;
if ( V_25 -> V_387 <= 0 )
F_285 ( V_25 ) ;
}
static bool F_258 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return false ;
if ( F_11 ( ! V_25 -> V_389 || V_25 -> V_387 > 0 ) )
return false ;
if ( F_281 ( V_25 ) )
return true ;
F_285 ( V_25 ) ;
return true ;
}
static enum V_423 F_303 ( struct V_413 * V_424 )
{
struct V_376 * V_377 =
F_21 ( V_424 , struct V_376 , V_419 ) ;
F_302 ( V_377 ) ;
return V_425 ;
}
static enum V_423 F_304 ( struct V_413 * V_424 )
{
struct V_376 * V_377 =
F_21 ( V_424 , struct V_376 , V_415 ) ;
int V_408 ;
int V_388 = 0 ;
F_276 ( & V_377 -> V_183 ) ;
for (; ; ) {
V_408 = F_305 ( V_424 , V_377 -> V_217 ) ;
if ( ! V_408 )
break;
V_388 = F_294 ( V_377 , V_408 ) ;
}
if ( V_388 )
V_377 -> V_426 = 0 ;
F_278 ( & V_377 -> V_183 ) ;
return V_388 ? V_425 : V_427 ;
}
void F_306 ( struct V_376 * V_377 )
{
F_307 ( & V_377 -> V_183 ) ;
V_377 -> V_218 = 0 ;
V_377 -> V_378 = V_379 ;
V_377 -> V_217 = F_300 ( F_268 () ) ;
F_308 ( & V_377 -> V_402 ) ;
F_309 ( & V_377 -> V_415 , V_428 , V_429 ) ;
V_377 -> V_415 . V_430 = F_304 ;
F_309 ( & V_377 -> V_419 , V_428 , V_420 ) ;
V_377 -> V_419 . V_430 = F_303 ;
}
static void F_310 ( struct V_25 * V_25 )
{
V_25 -> V_389 = 0 ;
F_308 ( & V_25 -> V_403 ) ;
}
void F_277 ( struct V_376 * V_377 )
{
F_311 ( & V_377 -> V_183 ) ;
if ( ! V_377 -> V_426 ) {
V_377 -> V_426 = 1 ;
F_305 ( & V_377 -> V_415 , V_377 -> V_217 ) ;
F_312 ( & V_377 -> V_415 , V_429 ) ;
}
}
static void F_313 ( struct V_376 * V_377 )
{
if ( ! V_377 -> V_402 . V_58 )
return;
F_314 ( & V_377 -> V_415 ) ;
F_314 ( & V_377 -> V_419 ) ;
}
static void T_11 F_315 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_316 (rq, cfs_rq) {
struct V_376 * V_377 = & V_25 -> V_33 -> V_376 ;
F_276 ( & V_377 -> V_183 ) ;
V_25 -> V_389 = V_377 -> V_378 != V_379 ;
F_278 ( & V_377 -> V_183 ) ;
}
}
static void T_11 F_317 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_316 (rq, cfs_rq) {
if ( ! V_25 -> V_389 )
continue;
V_25 -> V_387 = 1 ;
V_25 -> V_389 = 0 ;
if ( F_281 ( V_25 ) )
F_289 ( V_25 ) ;
}
}
static inline T_2 F_223 ( struct V_25 * V_25 )
{
return F_63 ( F_16 ( V_25 ) ) ;
}
static void F_70 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_258 ( struct V_25 * V_25 ) { return false ; }
static void F_245 ( struct V_25 * V_25 ) {}
static T_10 void F_251 ( struct V_25 * V_25 ) {}
static inline int F_281 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_207 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_282 ( struct V_303 * V_33 ,
int V_178 , int V_391 )
{
return 0 ;
}
void F_306 ( struct V_376 * V_377 ) {}
static void F_310 ( struct V_25 * V_25 ) {}
static inline struct V_376 * F_274 ( struct V_303 * V_33 )
{
return NULL ;
}
static inline void F_313 ( struct V_376 * V_377 ) {}
static inline void F_315 ( struct V_24 * V_24 ) {}
static inline void F_317 ( struct V_24 * V_24 ) {}
static void F_318 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_319 ( F_34 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_73 = F_58 ( V_25 , V_28 ) ;
T_2 V_431 = V_28 -> V_90 - V_28 -> V_367 ;
T_3 V_42 = V_73 - V_431 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_253 ( V_24 ) ;
return;
}
F_320 ( V_24 , V_42 ) ;
}
}
static void F_321 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_322 ( V_24 ) || V_45 -> V_432 != & V_433 )
return;
if ( F_23 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_318 ( V_24 , V_45 ) ;
}
static inline void
F_318 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_321 ( struct V_24 * V_24 )
{
}
static void
F_323 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_184 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_59 (se) {
if ( V_28 -> V_74 )
break;
V_25 = F_23 ( V_28 ) ;
F_244 ( V_25 , V_28 , V_184 ) ;
if ( F_281 ( V_25 ) )
break;
V_25 -> V_399 ++ ;
V_184 = V_359 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_399 ++ ;
if ( F_281 ( V_25 ) )
break;
F_222 ( V_28 , 1 ) ;
F_206 ( V_25 ) ;
}
if ( ! V_28 )
F_291 ( V_24 , 1 ) ;
F_321 ( V_24 ) ;
}
static void F_324 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_184 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_434 = V_184 & V_362 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_250 ( V_25 , V_28 , V_184 ) ;
if ( F_281 ( V_25 ) )
break;
V_25 -> V_399 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_434 && F_32 ( V_28 ) )
F_325 ( F_32 ( V_28 ) ) ;
V_28 = F_32 ( V_28 ) ;
break;
}
V_184 |= V_362 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_399 -- ;
if ( F_281 ( V_25 ) )
break;
F_222 ( V_28 , 1 ) ;
F_206 ( V_25 ) ;
}
if ( ! V_28 )
F_287 ( V_24 , 1 ) ;
F_321 ( V_24 ) ;
}
static unsigned long
F_326 ( unsigned long V_70 , unsigned long V_435 , int V_436 )
{
int V_437 = 0 ;
if ( ! V_435 )
return V_70 ;
if ( V_435 >= V_438 [ V_436 ] )
return 0 ;
if ( V_436 == 1 )
return V_70 >> V_435 ;
while ( V_435 ) {
if ( V_435 % 2 )
V_70 = ( V_70 * V_439 [ V_436 ] [ V_437 ] ) >> V_440 ;
V_435 >>= 1 ;
V_437 ++ ;
}
return V_70 ;
}
static void F_327 ( struct V_24 * V_441 , unsigned long V_442 ,
unsigned long V_443 , int V_444 )
{
unsigned long V_445 = V_444 ? V_441 -> V_446 [ 0 ] : 0 ;
int V_250 , V_447 ;
V_441 -> V_448 ++ ;
V_441 -> V_446 [ 0 ] = V_442 ;
for ( V_250 = 1 , V_447 = 2 ; V_250 < V_449 ; V_250 ++ , V_447 += V_447 ) {
unsigned long V_450 , V_451 ;
V_450 = V_441 -> V_446 [ V_250 ] - V_445 ;
V_450 = F_326 ( V_450 , V_443 - 1 , V_250 ) ;
V_450 += V_445 ;
V_451 = V_442 ;
if ( V_451 > V_450 )
V_451 += V_447 - 1 ;
V_441 -> V_446 [ V_250 ] = ( V_450 * ( V_447 - 1 ) + V_451 ) >> V_250 ;
}
F_328 ( V_441 ) ;
}
static unsigned long F_111 ( const int V_152 )
{
return F_230 ( & F_110 ( V_152 ) -> V_40 ) ;
}
static void F_329 ( struct V_24 * V_441 )
{
unsigned long V_452 = F_84 ( V_202 ) ;
unsigned long V_70 = F_111 ( F_26 ( V_441 ) ) ;
unsigned long V_443 ;
if ( V_70 || V_452 == V_441 -> V_453 )
return;
V_443 = V_452 - V_441 -> V_453 ;
V_441 -> V_453 = V_452 ;
F_327 ( V_441 , V_70 , V_443 , 0 ) ;
}
void F_330 ( int V_444 )
{
struct V_24 * V_441 = V_441 () ;
unsigned long V_452 = F_84 ( V_202 ) ;
unsigned long V_70 = V_444 ? F_111 ( F_26 ( V_441 ) ) : 0 ;
unsigned long V_443 ;
if ( V_452 == V_441 -> V_453 )
return;
F_276 ( & V_441 -> V_183 ) ;
V_443 = V_452 - V_441 -> V_453 ;
if ( V_443 ) {
V_441 -> V_453 = V_452 ;
F_327 ( V_441 , V_70 , V_443 , V_444 ) ;
}
F_278 ( & V_441 -> V_183 ) ;
}
void F_331 ( struct V_24 * V_441 )
{
unsigned long V_70 = F_111 ( F_26 ( V_441 ) ) ;
V_441 -> V_453 = V_202 ;
F_327 ( V_441 , V_70 , 1 , 1 ) ;
}
static unsigned long F_332 ( int V_152 , int type )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_454 = F_111 ( V_152 ) ;
if ( type == 0 || ! F_218 ( V_455 ) )
return V_454 ;
return F_141 ( V_24 -> V_446 [ type - 1 ] , V_454 ) ;
}
static unsigned long F_333 ( int V_152 , int type )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_454 = F_111 ( V_152 ) ;
if ( type == 0 || ! F_218 ( V_455 ) )
return V_454 ;
return F_65 ( V_24 -> V_446 [ type - 1 ] , V_454 ) ;
}
static unsigned long F_112 ( int V_152 )
{
return F_110 ( V_152 ) -> V_456 ;
}
static unsigned long F_334 ( int V_152 )
{
return F_110 ( V_152 ) -> V_457 ;
}
static unsigned long F_335 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_72 = F_84 ( V_24 -> V_40 . V_399 ) ;
unsigned long V_80 = F_111 ( V_152 ) ;
if ( V_72 )
return V_80 / V_72 ;
return 0 ;
}
static void F_336 ( struct V_26 * V_29 )
{
if ( F_179 ( V_202 , V_146 -> V_458 + V_200 ) ) {
V_146 -> V_459 >>= 1 ;
V_146 -> V_458 = V_202 ;
}
if ( V_146 -> V_460 != V_29 ) {
V_146 -> V_460 = V_29 ;
V_146 -> V_459 ++ ;
}
}
static void F_337 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_219 () ;
F_36 = V_25 -> F_36 ;
} while ( F_36 != V_48 );
#else
F_36 = V_25 -> F_36 ;
#endif
V_28 -> V_41 -= F_36 ;
F_336 ( V_29 ) ;
}
static long F_338 ( struct V_303 * V_33 , int V_152 , long V_461 , long V_462 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_152 ] ;
if ( ! V_33 -> V_34 )
return V_461 ;
F_59 (se) {
long V_7 , V_463 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_463 = V_462 + F_202 ( V_33 , V_28 -> V_31 ) ;
V_7 = F_231 ( V_28 -> V_31 ) + V_461 ;
if ( V_463 > 0 && V_7 < V_463 )
V_461 = ( V_7 * ( long ) V_33 -> V_306 ) / V_463 ;
else
V_461 = V_33 -> V_306 ;
if ( V_461 < V_307 )
V_461 = V_307 ;
V_461 -= V_28 -> V_77 . V_80 ;
V_462 = 0 ;
}
return V_461 ;
}
static long F_338 ( struct V_303 * V_33 , int V_152 , long V_461 , long V_462 )
{
return V_461 ;
}
static int F_339 ( struct V_26 * V_29 )
{
unsigned int V_464 = V_146 -> V_459 ;
unsigned int V_465 = V_29 -> V_459 ;
int V_9 = F_340 ( V_466 ) ;
if ( V_464 < V_465 )
F_117 ( V_464 , V_465 ) ;
if ( V_465 < V_9 || V_464 < V_465 * V_9 )
return 0 ;
return 1 ;
}
static int F_341 ( struct V_191 * V_192 , struct V_26 * V_29 , int V_467 )
{
T_3 V_442 , V_70 ;
T_3 V_468 , V_469 ;
int V_436 , V_470 , V_471 ;
struct V_303 * V_33 ;
unsigned long V_4 ;
int V_472 ;
V_436 = V_192 -> V_473 ;
V_470 = F_272 () ;
V_471 = F_132 ( V_29 ) ;
V_70 = F_332 ( V_471 , V_436 ) ;
V_442 = F_333 ( V_470 , V_436 ) ;
if ( V_467 ) {
V_33 = V_303 ( V_146 ) ;
V_4 = V_146 -> V_28 . V_77 . V_80 ;
V_442 += F_338 ( V_33 , V_470 , - V_4 , - V_4 ) ;
V_70 += F_338 ( V_33 , V_471 , 0 , - V_4 ) ;
}
V_33 = V_303 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_468 = 100 ;
V_468 *= F_112 ( V_471 ) ;
V_469 = 100 + ( V_192 -> V_174 - 100 ) / 2 ;
V_469 *= F_112 ( V_470 ) ;
if ( V_442 > 0 ) {
V_468 *= V_442 +
F_338 ( V_33 , V_470 , V_4 , V_4 ) ;
V_469 *= V_70 + F_338 ( V_33 , V_471 , 0 , V_4 ) ;
}
V_472 = V_468 <= V_469 ;
F_242 ( V_29 , V_28 . V_88 . V_474 ) ;
if ( ! V_472 )
return 0 ;
F_242 ( V_192 , V_475 ) ;
F_242 ( V_29 , V_28 . V_88 . V_476 ) ;
return 1 ;
}
static struct V_477 *
F_342 ( struct V_191 * V_192 , struct V_26 * V_29 ,
int V_470 , int V_478 )
{
struct V_477 * V_479 = NULL , * V_124 = V_192 -> V_480 ;
unsigned long V_481 = V_482 , V_442 = 0 ;
int V_483 = V_192 -> V_484 ;
int V_485 = 100 + ( V_192 -> V_174 - 100 ) / 2 ;
if ( V_478 & V_486 )
V_483 = V_192 -> V_473 ;
do {
unsigned long V_70 , V_487 ;
int V_488 ;
int V_250 ;
if ( ! F_343 ( F_344 ( V_124 ) ,
F_125 ( V_29 ) ) )
continue;
V_488 = F_124 ( V_470 ,
F_344 ( V_124 ) ) ;
V_487 = 0 ;
F_109 (i, sched_group_cpus(group)) {
if ( V_488 )
V_70 = F_332 ( V_250 , V_483 ) ;
else
V_70 = F_333 ( V_250 , V_483 ) ;
V_487 += V_70 ;
}
V_487 = ( V_487 * V_155 ) / V_124 -> V_489 -> V_153 ;
if ( V_488 ) {
V_442 = V_487 ;
} else if ( V_487 < V_481 ) {
V_481 = V_487 ;
V_479 = V_124 ;
}
} while ( V_124 = V_124 -> V_58 , V_124 != V_192 -> V_480 );
if ( ! V_479 || 100 * V_442 < V_485 * V_481 )
return NULL ;
return V_479 ;
}
static int
F_345 ( struct V_477 * V_124 , struct V_26 * V_29 , int V_470 )
{
unsigned long V_70 , V_481 = V_482 ;
unsigned int V_490 = V_491 ;
T_2 V_492 = 0 ;
int V_493 = V_470 ;
int V_494 = - 1 ;
int V_250 ;
F_346 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_347 ( V_250 ) ) {
struct V_24 * V_24 = F_110 ( V_250 ) ;
struct V_495 * V_388 = F_348 ( V_24 ) ;
if ( V_388 && V_388 -> V_496 < V_490 ) {
V_490 = V_388 -> V_496 ;
V_492 = V_24 -> V_497 ;
V_494 = V_250 ;
} else if ( ( ! V_388 || V_388 -> V_496 == V_490 ) &&
V_24 -> V_497 > V_492 ) {
V_492 = V_24 -> V_497 ;
V_494 = V_250 ;
}
} else if ( V_494 == - 1 ) {
V_70 = F_111 ( V_250 ) ;
if ( V_70 < V_481 || ( V_70 == V_481 && V_250 == V_470 ) ) {
V_481 = V_70 ;
V_493 = V_250 ;
}
}
}
return V_494 != - 1 ? V_494 : V_493 ;
}
static int F_127 ( struct V_26 * V_29 , int V_498 )
{
struct V_191 * V_192 ;
struct V_477 * V_499 ;
int V_250 = F_132 ( V_29 ) ;
if ( F_347 ( V_498 ) )
return V_498 ;
if ( V_250 != V_498 && F_349 ( V_250 , V_498 ) && F_347 ( V_250 ) )
return V_250 ;
V_192 = F_133 ( F_134 ( V_500 , V_498 ) ) ;
F_350 (sd) {
V_499 = V_192 -> V_480 ;
do {
if ( ! F_343 ( F_344 ( V_499 ) ,
F_125 ( V_29 ) ) )
goto V_58;
F_109 (i, sched_group_cpus(sg)) {
if ( V_250 == V_498 || ! F_347 ( V_250 ) )
goto V_58;
}
V_498 = F_351 ( F_344 ( V_499 ) ,
F_125 ( V_29 ) ) ;
goto V_501;
V_58:
V_499 = V_499 -> V_58 ;
} while ( V_499 != V_192 -> V_480 );
}
V_501:
return V_498 ;
}
static int F_352 ( int V_152 )
{
unsigned long V_502 = F_110 ( V_152 ) -> V_40 . V_77 . V_83 ;
unsigned long V_153 = F_334 ( V_152 ) ;
return ( V_502 >= V_153 ) ? V_153 : V_502 ;
}
static int
F_353 ( struct V_26 * V_29 , int V_471 , int V_478 , int V_503 )
{
struct V_191 * V_504 , * V_505 = NULL , * V_192 = NULL ;
int V_152 = F_272 () ;
int V_506 = V_471 ;
int V_507 = 0 ;
int V_467 = V_503 & V_508 ;
if ( V_478 & V_486 )
V_507 = ! F_339 ( V_29 ) && F_124 ( V_152 , F_125 ( V_29 ) ) ;
F_119 () ;
F_354 (cpu, tmp) {
if ( ! ( V_504 -> V_184 & V_509 ) )
break;
if ( V_507 && ( V_504 -> V_184 & V_510 ) &&
F_124 ( V_471 , F_355 ( V_504 ) ) ) {
V_505 = V_504 ;
break;
}
if ( V_504 -> V_184 & V_478 )
V_192 = V_504 ;
else if ( ! V_507 )
break;
}
if ( V_505 ) {
V_192 = NULL ;
if ( V_152 != V_471 && F_341 ( V_505 , V_29 , V_467 ) )
V_506 = V_152 ;
}
if ( ! V_192 ) {
if ( V_478 & V_486 )
V_506 = F_127 ( V_29 , V_506 ) ;
} else while ( V_192 ) {
struct V_477 * V_124 ;
int V_4 ;
if ( ! ( V_192 -> V_184 & V_478 ) ) {
V_192 = V_192 -> V_511 ;
continue;
}
V_124 = F_342 ( V_192 , V_29 , V_152 , V_478 ) ;
if ( ! V_124 ) {
V_192 = V_192 -> V_511 ;
continue;
}
V_506 = F_345 ( V_124 , V_29 , V_152 ) ;
if ( V_506 == - 1 || V_506 == V_152 ) {
V_192 = V_192 -> V_511 ;
continue;
}
V_152 = V_506 ;
V_4 = V_192 -> V_512 ;
V_192 = NULL ;
F_354 (cpu, tmp) {
if ( V_4 <= V_504 -> V_512 )
break;
if ( V_504 -> V_184 & V_478 )
V_192 = V_504 ;
}
}
F_128 () ;
return V_506 ;
}
static void F_356 ( struct V_26 * V_29 )
{
F_229 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_87 = 0 ;
}
static void F_357 ( struct V_26 * V_29 )
{
F_229 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_358 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_513 = V_514 ;
return F_56 ( V_513 , V_28 ) ;
}
static int
F_256 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_513 , V_515 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_515 <= 0 )
return - 1 ;
V_513 = F_358 ( V_45 , V_28 ) ;
if ( V_515 > V_513 )
return 1 ;
return 0 ;
}
static void F_359 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_516 == V_517 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_325 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_516 == V_517 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_360 ( struct V_27 * V_28 )
{
F_59 (se)
F_23 ( V_28 ) -> V_361 = V_28 ;
}
static void F_361 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_503 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_447 = V_25 -> V_72 >= V_67 ;
int V_518 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_207 ( F_23 ( V_36 ) ) ) )
return;
if ( F_218 ( V_519 ) && V_447 && ! ( V_503 & V_520 ) ) {
F_325 ( V_36 ) ;
V_518 = 1 ;
}
if ( F_362 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_516 == V_517 ) &&
F_11 ( V_29 -> V_516 != V_517 ) )
goto V_521;
if ( F_13 ( V_29 -> V_516 != V_522 ) || ! F_218 ( V_523 ) )
return;
F_33 ( & V_28 , & V_36 ) ;
F_62 ( F_23 ( V_28 ) ) ;
F_168 ( ! V_36 ) ;
if ( F_256 ( V_28 , V_36 ) == 1 ) {
if ( ! V_518 )
F_325 ( V_36 ) ;
goto V_521;
}
return;
V_521:
F_253 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_74 || V_45 == V_24 -> V_388 ) )
return;
if ( F_218 ( V_524 ) && V_447 && F_20 ( V_28 ) )
F_359 ( V_28 ) ;
}
static struct V_26 *
F_363 ( struct V_24 * V_24 , struct V_26 * V_328 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_525 ;
V_526:
#ifdef F_364
if ( ! V_25 -> V_72 )
goto V_388;
if ( V_328 -> V_432 != & V_433 )
goto V_527;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_74 )
F_62 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_258 ( V_25 ) ) )
goto V_527;
}
V_28 = F_255 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_328 != V_29 ) {
struct V_27 * V_36 = & V_328 -> V_28 ;
while ( ! ( V_25 = F_31 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_257 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_32 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_254 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_32 ( V_28 ) ;
}
}
F_257 ( V_25 , V_36 ) ;
F_254 ( V_25 , V_28 ) ;
}
if ( F_322 ( V_24 ) )
F_318 ( V_24 , V_29 ) ;
return V_29 ;
V_527:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_388;
F_365 ( V_24 , V_328 ) ;
do {
V_28 = F_255 ( V_25 , NULL ) ;
F_254 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_322 ( V_24 ) )
F_318 ( V_24 , V_29 ) ;
return V_29 ;
V_388:
F_366 ( & V_24 -> V_183 ) ;
V_525 = F_232 ( V_24 ) ;
F_367 ( & V_24 -> V_183 ) ;
if ( V_525 < 0 )
return V_528 ;
if ( V_525 > 0 )
goto V_526;
return NULL ;
}
static void F_368 ( struct V_24 * V_24 , struct V_26 * V_328 )
{
struct V_27 * V_28 = & V_328 -> V_28 ;
struct V_25 * V_25 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_257 ( V_25 , V_28 ) ;
}
}
static void F_369 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_249 ( V_25 , V_28 ) ;
if ( V_45 -> V_516 != V_529 ) {
F_290 ( V_24 ) ;
F_62 ( V_25 ) ;
F_370 ( V_24 , true ) ;
}
F_360 ( V_28 ) ;
}
static bool F_371 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_521 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_74 || F_207 ( F_23 ( V_28 ) ) )
return false ;
F_325 ( V_28 ) ;
F_369 ( V_24 ) ;
return true ;
}
static int F_372 ( struct V_26 * V_29 , struct V_530 * V_159 )
{
T_3 V_42 ;
F_311 ( & V_159 -> V_177 -> V_183 ) ;
if ( V_29 -> V_432 != & V_433 )
return 0 ;
if ( F_13 ( V_29 -> V_516 == V_517 ) )
return 0 ;
if ( F_218 ( V_531 ) && V_159 -> V_179 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_532 == - 1 )
return 1 ;
if ( V_532 == 0 )
return 0 ;
V_42 = F_63 ( V_159 -> V_177 ) - V_29 -> V_28 . V_87 ;
return V_42 < ( T_3 ) V_532 ;
}
static int F_373 ( struct V_26 * V_29 , struct V_530 * V_159 )
{
struct V_113 * V_113 = F_133 ( V_29 -> V_113 ) ;
unsigned long V_533 , V_534 ;
int V_140 , V_143 ;
if ( ! F_178 ( & V_264 ) )
return - 1 ;
if ( ! V_29 -> V_121 || ! ( V_159 -> V_192 -> V_184 & V_535 ) )
return - 1 ;
V_140 = F_101 ( V_159 -> V_178 ) ;
V_143 = F_101 ( V_159 -> V_141 ) ;
if ( V_140 == V_143 )
return - 1 ;
if ( V_140 == V_29 -> V_111 ) {
if ( V_159 -> V_177 -> V_72 > V_159 -> V_177 -> V_112 )
return 1 ;
else
return - 1 ;
}
if ( V_143 == V_29 -> V_111 )
return 0 ;
if ( V_113 ) {
V_533 = F_93 ( V_29 , V_140 ) ;
V_534 = F_93 ( V_29 , V_143 ) ;
} else {
V_533 = F_92 ( V_29 , V_140 ) ;
V_534 = F_92 ( V_29 , V_143 ) ;
}
return V_534 < V_533 ;
}
static inline int F_373 ( struct V_26 * V_29 ,
struct V_530 * V_159 )
{
return - 1 ;
}
static
int F_374 ( struct V_26 * V_29 , struct V_530 * V_159 )
{
int V_536 ;
F_311 ( & V_159 -> V_177 -> V_183 ) ;
if ( F_282 ( V_303 ( V_29 ) , V_159 -> V_178 , V_159 -> V_141 ) )
return 0 ;
if ( ! F_124 ( V_159 -> V_141 , F_125 ( V_29 ) ) ) {
int V_152 ;
F_242 ( V_29 , V_28 . V_88 . V_537 ) ;
V_159 -> V_184 |= V_538 ;
if ( ! V_159 -> V_539 || ( V_159 -> V_184 & V_540 ) )
return 0 ;
F_346 (cpu, env->dst_grpmask, env->cpus) {
if ( F_124 ( V_152 , F_125 ( V_29 ) ) ) {
V_159 -> V_184 |= V_540 ;
V_159 -> V_541 = V_152 ;
break;
}
}
return 0 ;
}
V_159 -> V_184 &= ~ V_542 ;
if ( F_375 ( V_159 -> V_177 , V_29 ) ) {
F_242 ( V_29 , V_28 . V_88 . V_543 ) ;
return 0 ;
}
V_536 = F_373 ( V_29 , V_159 ) ;
if ( V_536 == - 1 )
V_536 = F_372 ( V_29 , V_159 ) ;
if ( V_536 <= 0 ||
V_159 -> V_192 -> V_544 > V_159 -> V_192 -> V_545 ) {
if ( V_536 == 1 ) {
F_242 ( V_159 -> V_192 , V_546 [ V_159 -> V_388 ] ) ;
F_242 ( V_29 , V_28 . V_88 . V_547 ) ;
}
return 1 ;
}
F_242 ( V_29 , V_28 . V_88 . V_548 ) ;
return 0 ;
}
static void F_376 ( struct V_26 * V_29 , struct V_530 * V_159 )
{
F_311 ( & V_159 -> V_177 -> V_183 ) ;
V_29 -> V_74 = V_549 ;
F_377 ( V_159 -> V_177 , V_29 , 0 ) ;
F_378 ( V_29 , V_159 -> V_141 ) ;
}
static struct V_26 * F_379 ( struct V_530 * V_159 )
{
struct V_26 * V_29 , * V_309 ;
F_311 ( & V_159 -> V_177 -> V_183 ) ;
F_380 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_374 ( V_29 , V_159 ) )
continue;
F_376 ( V_29 , V_159 ) ;
F_242 ( V_159 -> V_192 , V_550 [ V_159 -> V_388 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_381 ( struct V_530 * V_159 )
{
struct V_551 * V_552 = & V_159 -> V_177 -> V_302 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_553 = 0 ;
F_311 ( & V_159 -> V_177 -> V_183 ) ;
if ( V_159 -> V_485 <= 0 )
return 0 ;
while ( ! F_288 ( V_552 ) ) {
if ( V_159 -> V_388 != V_554 && V_159 -> V_177 -> V_72 <= 1 )
break;
V_29 = F_382 ( V_552 , struct V_26 , V_28 . V_301 ) ;
V_159 -> V_555 ++ ;
if ( V_159 -> V_555 > V_159 -> V_556 )
break;
if ( V_159 -> V_555 > V_159 -> V_557 ) {
V_159 -> V_557 += V_558 ;
V_159 -> V_184 |= V_559 ;
break;
}
if ( ! F_374 ( V_29 , V_159 ) )
goto V_58;
V_70 = F_126 ( V_29 ) ;
if ( F_218 ( V_560 ) && V_70 < 16 && ! V_159 -> V_192 -> V_544 )
goto V_58;
if ( ( V_70 / 2 ) > V_159 -> V_485 )
goto V_58;
F_376 ( V_29 , V_159 ) ;
F_199 ( & V_29 -> V_28 . V_301 , & V_159 -> V_552 ) ;
V_553 ++ ;
V_159 -> V_485 -= V_70 ;
#ifdef F_383
if ( V_159 -> V_388 == V_561 )
break;
#endif
if ( V_159 -> V_485 <= 0 )
break;
continue;
V_58:
F_384 ( & V_29 -> V_28 . V_301 , V_552 ) ;
}
F_66 ( V_159 -> V_192 , V_550 [ V_159 -> V_388 ] , V_553 ) ;
return V_553 ;
}
static void F_385 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_311 ( & V_24 -> V_183 ) ;
F_168 ( F_34 ( V_29 ) != V_24 ) ;
F_386 ( V_24 , V_29 , 0 ) ;
V_29 -> V_74 = V_562 ;
F_387 ( V_24 , V_29 , 0 ) ;
}
static void F_388 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_276 ( & V_24 -> V_183 ) ;
F_385 ( V_24 , V_29 ) ;
F_278 ( & V_24 -> V_183 ) ;
}
static void F_389 ( struct V_530 * V_159 )
{
struct V_551 * V_552 = & V_159 -> V_552 ;
struct V_26 * V_29 ;
F_276 ( & V_159 -> V_179 -> V_183 ) ;
while ( ! F_288 ( V_552 ) ) {
V_29 = F_382 ( V_552 , struct V_26 , V_28 . V_301 ) ;
F_201 ( & V_29 -> V_28 . V_301 ) ;
F_385 ( V_159 -> V_179 , V_29 ) ;
}
F_278 ( & V_159 -> V_179 -> V_183 ) ;
}
static void F_390 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
struct V_25 * V_25 ;
unsigned long V_184 ;
F_391 ( & V_24 -> V_183 , V_184 ) ;
F_290 ( V_24 ) ;
F_316 (rq, cfs_rq) {
if ( F_207 ( V_25 ) )
continue;
if ( F_220 ( F_223 ( V_25 ) , V_25 ) )
F_215 ( V_25 , 0 ) ;
}
F_392 ( & V_24 -> V_183 , V_184 ) ;
}
static void F_393 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_86 = V_202 ;
unsigned long V_70 ;
if ( V_25 -> V_563 == V_86 )
return;
V_25 -> V_564 = NULL ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_564 = V_28 ;
if ( V_25 -> V_563 == V_86 )
break;
}
if ( ! V_28 ) {
V_25 -> V_565 = F_231 ( V_25 ) ;
V_25 -> V_563 = V_86 ;
}
while ( ( V_28 = V_25 -> V_564 ) != NULL ) {
V_70 = V_25 -> V_565 ;
V_70 = F_394 ( V_70 * V_28 -> V_77 . V_80 ,
F_231 ( V_25 ) + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_565 = V_70 ;
V_25 -> V_563 = V_86 ;
}
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_393 ( V_25 ) ;
return F_394 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_565 ,
F_231 ( V_25 ) + 1 ) ;
}
static inline void F_390 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_184 ;
F_391 ( & V_24 -> V_183 , V_184 ) ;
F_290 ( V_24 ) ;
F_220 ( F_223 ( V_25 ) , V_25 ) ;
F_392 ( & V_24 -> V_183 , V_184 ) ;
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_395 ( struct V_566 * V_567 )
{
* V_567 = (struct V_566 ) {
. V_568 = NULL ,
. V_211 = NULL ,
. V_569 = 0UL ,
. V_570 = 0UL ,
. V_571 = {
. V_487 = 0UL ,
. V_572 = 0 ,
. V_573 = V_574 ,
} ,
} ;
}
static inline int F_396 ( struct V_191 * V_192 ,
enum V_575 V_388 )
{
int V_483 ;
switch ( V_388 ) {
case V_554 :
V_483 = V_192 -> V_576 ;
break;
case V_561 :
V_483 = V_192 -> V_577 ;
break;
default:
V_483 = V_192 -> V_578 ;
break;
}
return V_483 ;
}
static unsigned long F_397 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
T_2 V_454 , V_579 , V_580 , V_77 ;
T_3 V_42 ;
V_580 = F_84 ( V_24 -> V_580 ) ;
V_77 = F_84 ( V_24 -> V_581 ) ;
V_42 = F_398 ( V_24 ) - V_580 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_454 = F_399 () + V_42 ;
V_579 = F_214 ( V_77 , V_454 ) ;
if ( F_11 ( V_579 < V_155 ) )
return V_155 - V_579 ;
return 1 ;
}
static void F_400 ( struct V_191 * V_192 , int V_152 )
{
unsigned long V_153 = F_212 ( V_192 , V_152 ) ;
struct V_477 * V_582 = V_192 -> V_480 ;
F_110 ( V_152 ) -> V_457 = V_153 ;
V_153 *= F_397 ( V_152 ) ;
V_153 >>= V_583 ;
if ( ! V_153 )
V_153 = 1 ;
F_110 ( V_152 ) -> V_456 = V_153 ;
V_582 -> V_489 -> V_153 = V_153 ;
}
void F_401 ( struct V_191 * V_192 , int V_152 )
{
struct V_191 * V_511 = V_192 -> V_511 ;
struct V_477 * V_124 , * V_582 = V_192 -> V_480 ;
unsigned long V_153 ;
unsigned long V_199 ;
V_199 = F_142 ( V_192 -> V_584 ) ;
V_199 = F_147 ( V_199 , 1UL , V_585 ) ;
V_582 -> V_489 -> V_586 = V_202 + V_199 ;
if ( ! V_511 ) {
F_400 ( V_192 , V_152 ) ;
return;
}
V_153 = 0 ;
if ( V_511 -> V_184 & V_587 ) {
F_109 (cpu, sched_group_cpus(sdg)) {
struct V_588 * V_489 ;
struct V_24 * V_24 = F_110 ( V_152 ) ;
if ( F_13 ( ! V_24 -> V_192 ) ) {
V_153 += F_112 ( V_152 ) ;
continue;
}
V_489 = V_24 -> V_192 -> V_480 -> V_489 ;
V_153 += V_489 -> V_153 ;
}
} else {
V_124 = V_511 -> V_480 ;
do {
V_153 += V_124 -> V_489 -> V_153 ;
V_124 = V_124 -> V_58 ;
} while ( V_124 != V_511 -> V_480 );
}
V_582 -> V_489 -> V_153 = V_153 ;
}
static inline int
F_402 ( struct V_24 * V_24 , struct V_191 * V_192 )
{
return ( ( V_24 -> V_456 * V_192 -> V_174 ) <
( V_24 -> V_457 * 100 ) ) ;
}
static inline int F_403 ( struct V_477 * V_124 )
{
return V_124 -> V_489 -> V_485 ;
}
static inline bool
F_404 ( struct V_530 * V_159 , struct V_589 * V_590 )
{
if ( V_590 -> V_572 < V_590 -> F_99 )
return true ;
if ( ( V_590 -> V_591 * 100 ) >
( V_590 -> V_592 * V_159 -> V_192 -> V_174 ) )
return true ;
return false ;
}
static inline bool
F_405 ( struct V_530 * V_159 , struct V_589 * V_590 )
{
if ( V_590 -> V_572 <= V_590 -> F_99 )
return false ;
if ( ( V_590 -> V_591 * 100 ) <
( V_590 -> V_592 * V_159 -> V_192 -> V_174 ) )
return true ;
return false ;
}
static inline enum
V_573 F_406 ( struct V_477 * V_124 ,
struct V_589 * V_590 )
{
if ( V_590 -> V_593 )
return V_594 ;
if ( F_403 ( V_124 ) )
return V_595 ;
return V_574 ;
}
static inline void F_407 ( struct V_530 * V_159 ,
struct V_477 * V_124 , int V_483 ,
int V_488 , struct V_589 * V_590 ,
bool * V_596 )
{
unsigned long V_70 ;
int V_250 , V_72 ;
memset ( V_590 , 0 , sizeof( * V_590 ) ) ;
F_346 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_110 ( V_250 ) ;
if ( V_488 )
V_70 = F_333 ( V_250 , V_483 ) ;
else
V_70 = F_332 ( V_250 , V_483 ) ;
V_590 -> V_597 += V_70 ;
V_590 -> V_592 += F_352 ( V_250 ) ;
V_590 -> V_572 += V_24 -> V_40 . V_399 ;
V_72 = V_24 -> V_72 ;
if ( V_72 > 1 )
* V_596 = true ;
#ifdef F_408
V_590 -> V_110 += V_24 -> V_110 ;
V_590 -> V_112 += V_24 -> V_112 ;
#endif
V_590 -> V_598 += F_111 ( V_250 ) ;
if ( ! V_72 && F_347 ( V_250 ) )
V_590 -> V_599 ++ ;
}
V_590 -> V_591 = V_124 -> V_489 -> V_153 ;
V_590 -> V_487 = ( V_590 -> V_597 * V_155 ) / V_590 -> V_591 ;
if ( V_590 -> V_572 )
V_590 -> V_600 = V_590 -> V_598 / V_590 -> V_572 ;
V_590 -> F_99 = V_124 -> F_99 ;
V_590 -> V_593 = F_405 ( V_159 , V_590 ) ;
V_590 -> V_573 = F_406 ( V_124 , V_590 ) ;
}
static bool F_409 ( struct V_530 * V_159 ,
struct V_566 * V_567 ,
struct V_477 * V_499 ,
struct V_589 * V_590 )
{
struct V_589 * V_568 = & V_567 -> V_571 ;
if ( V_590 -> V_573 > V_568 -> V_573 )
return true ;
if ( V_590 -> V_573 < V_568 -> V_573 )
return false ;
if ( V_590 -> V_487 <= V_568 -> V_487 )
return false ;
if ( ! ( V_159 -> V_192 -> V_184 & V_601 ) )
return true ;
if ( V_590 -> V_572 && V_159 -> V_141 < F_410 ( V_499 ) ) {
if ( ! V_567 -> V_568 )
return true ;
if ( F_410 ( V_567 -> V_568 ) > F_410 ( V_499 ) )
return true ;
}
return false ;
}
static inline enum V_602 F_411 ( struct V_589 * V_590 )
{
if ( V_590 -> V_572 > V_590 -> V_110 )
return V_603 ;
if ( V_590 -> V_572 > V_590 -> V_112 )
return V_209 ;
return V_604 ;
}
static inline enum V_602 F_412 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_110 )
return V_603 ;
if ( V_24 -> V_72 > V_24 -> V_112 )
return V_209 ;
return V_604 ;
}
static inline enum V_602 F_411 ( struct V_589 * V_590 )
{
return V_604 ;
}
static inline enum V_602 F_412 ( struct V_24 * V_24 )
{
return V_603 ;
}
static inline void F_413 ( struct V_530 * V_159 , struct V_566 * V_567 )
{
struct V_191 * V_511 = V_159 -> V_192 -> V_511 ;
struct V_477 * V_499 = V_159 -> V_192 -> V_480 ;
struct V_589 V_605 ;
int V_483 , V_606 = 0 ;
bool V_596 = false ;
if ( V_511 && V_511 -> V_184 & V_607 )
V_606 = 1 ;
V_483 = F_396 ( V_159 -> V_192 , V_159 -> V_388 ) ;
do {
struct V_589 * V_590 = & V_605 ;
int V_488 ;
V_488 = F_124 ( V_159 -> V_141 , F_344 ( V_499 ) ) ;
if ( V_488 ) {
V_567 -> V_211 = V_499 ;
V_590 = & V_567 -> V_608 ;
if ( V_159 -> V_388 != V_561 ||
F_414 ( V_202 , V_499 -> V_489 -> V_586 ) )
F_401 ( V_159 -> V_192 , V_159 -> V_141 ) ;
}
F_407 ( V_159 , V_499 , V_483 , V_488 , V_590 ,
& V_596 ) ;
if ( V_488 )
goto V_609;
if ( V_606 && V_567 -> V_211 &&
F_404 ( V_159 , & V_567 -> V_608 ) &&
( V_590 -> V_572 > 1 ) ) {
V_590 -> V_593 = 1 ;
V_590 -> V_573 = F_406 ( V_499 , V_590 ) ;
}
if ( F_409 ( V_159 , V_567 , V_499 , V_590 ) ) {
V_567 -> V_568 = V_499 ;
V_567 -> V_571 = * V_590 ;
}
V_609:
V_567 -> V_569 += V_590 -> V_597 ;
V_567 -> V_570 += V_590 -> V_591 ;
V_499 = V_499 -> V_58 ;
} while ( V_499 != V_159 -> V_192 -> V_480 );
if ( V_159 -> V_192 -> V_184 & V_535 )
V_159 -> V_602 = F_411 ( & V_567 -> V_571 ) ;
if ( ! V_159 -> V_192 -> V_34 ) {
if ( V_159 -> V_179 -> V_610 -> V_596 != V_596 )
V_159 -> V_179 -> V_610 -> V_596 = V_596 ;
}
}
static int F_415 ( struct V_530 * V_159 , struct V_566 * V_567 )
{
int V_611 ;
if ( ! ( V_159 -> V_192 -> V_184 & V_601 ) )
return 0 ;
if ( ! V_567 -> V_568 )
return 0 ;
V_611 = F_410 ( V_567 -> V_568 ) ;
if ( V_159 -> V_141 > V_611 )
return 0 ;
V_159 -> V_485 = F_113 (
V_567 -> V_571 . V_487 * V_567 -> V_571 . V_591 ,
V_155 ) ;
return 1 ;
}
static inline
void F_416 ( struct V_530 * V_159 , struct V_566 * V_567 )
{
unsigned long V_504 , V_612 = 0 , V_613 = 0 ;
unsigned int V_614 = 2 ;
unsigned long V_615 ;
struct V_589 * V_211 , * V_568 ;
V_211 = & V_567 -> V_608 ;
V_568 = & V_567 -> V_571 ;
if ( ! V_211 -> V_572 )
V_211 -> V_600 = F_335 ( V_159 -> V_141 ) ;
else if ( V_568 -> V_600 > V_211 -> V_600 )
V_614 = 1 ;
V_615 =
( V_568 -> V_600 * V_155 ) /
V_568 -> V_591 ;
if ( V_568 -> V_487 + V_615 >=
V_211 -> V_487 + ( V_615 * V_614 ) ) {
V_159 -> V_485 = V_568 -> V_600 ;
return;
}
V_612 += V_568 -> V_591 *
F_141 ( V_568 -> V_600 , V_568 -> V_487 ) ;
V_612 += V_211 -> V_591 *
F_141 ( V_211 -> V_600 , V_211 -> V_487 ) ;
V_612 /= V_155 ;
if ( V_568 -> V_487 > V_615 ) {
V_613 += V_568 -> V_591 *
F_141 ( V_568 -> V_600 ,
V_568 -> V_487 - V_615 ) ;
}
if ( V_568 -> V_487 * V_568 -> V_591 <
V_568 -> V_600 * V_155 ) {
V_504 = ( V_568 -> V_487 * V_568 -> V_591 ) /
V_211 -> V_591 ;
} else {
V_504 = ( V_568 -> V_600 * V_155 ) /
V_211 -> V_591 ;
}
V_613 += V_211 -> V_591 *
F_141 ( V_211 -> V_600 , V_211 -> V_487 + V_504 ) ;
V_613 /= V_155 ;
if ( V_613 > V_612 )
V_159 -> V_485 = V_568 -> V_600 ;
}
static inline void F_417 ( struct V_530 * V_159 , struct V_566 * V_567 )
{
unsigned long V_616 , V_617 = ~ 0UL ;
struct V_589 * V_211 , * V_568 ;
V_211 = & V_567 -> V_608 ;
V_568 = & V_567 -> V_571 ;
if ( V_568 -> V_573 == V_595 ) {
V_568 -> V_600 =
F_141 ( V_568 -> V_600 , V_567 -> V_487 ) ;
}
if ( V_568 -> V_487 <= V_567 -> V_487 ||
V_211 -> V_487 >= V_567 -> V_487 ) {
V_159 -> V_485 = 0 ;
return F_416 ( V_159 , V_567 ) ;
}
if ( V_568 -> V_573 == V_594 &&
V_211 -> V_573 == V_594 ) {
V_617 = V_568 -> V_572 *
V_84 ;
if ( V_617 > V_568 -> V_591 )
V_617 -= V_568 -> V_591 ;
else
V_617 = ~ 0UL ;
}
V_616 = F_141 ( V_568 -> V_487 - V_567 -> V_487 , V_617 ) ;
V_159 -> V_485 = F_141 (
V_616 * V_568 -> V_591 ,
( V_567 -> V_487 - V_211 -> V_487 ) * V_211 -> V_591
) / V_155 ;
if ( V_159 -> V_485 < V_568 -> V_600 )
return F_416 ( V_159 , V_567 ) ;
}
static struct V_477 * F_418 ( struct V_530 * V_159 )
{
struct V_589 * V_211 , * V_568 ;
struct V_566 V_567 ;
F_395 ( & V_567 ) ;
F_413 ( V_159 , & V_567 ) ;
V_211 = & V_567 . V_608 ;
V_568 = & V_567 . V_571 ;
if ( ( V_159 -> V_388 == V_618 || V_159 -> V_388 == V_561 ) &&
F_415 ( V_159 , & V_567 ) )
return V_567 . V_568 ;
if ( ! V_567 . V_568 || V_568 -> V_572 == 0 )
goto V_619;
V_567 . V_487 = ( V_155 * V_567 . V_569 )
/ V_567 . V_570 ;
if ( V_568 -> V_573 == V_595 )
goto V_620;
if ( V_159 -> V_388 == V_561 && F_404 ( V_159 , V_211 ) &&
V_568 -> V_593 )
goto V_620;
if ( V_211 -> V_487 >= V_568 -> V_487 )
goto V_619;
if ( V_211 -> V_487 >= V_567 . V_487 )
goto V_619;
if ( V_159 -> V_388 == V_618 ) {
if ( ( V_568 -> V_573 != V_594 ) &&
( V_211 -> V_599 <= ( V_568 -> V_599 + 1 ) ) )
goto V_619;
} else {
if ( 100 * V_568 -> V_487 <=
V_159 -> V_192 -> V_174 * V_211 -> V_487 )
goto V_619;
}
V_620:
F_417 ( V_159 , & V_567 ) ;
return V_567 . V_568 ;
V_619:
V_159 -> V_485 = 0 ;
return NULL ;
}
static struct V_24 * F_419 ( struct V_530 * V_159 ,
struct V_477 * V_124 )
{
struct V_24 * V_568 = NULL , * V_24 ;
unsigned long V_621 = 0 , V_622 = 1 ;
int V_250 ;
F_346 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_153 , V_461 ;
enum V_602 V_623 ;
V_24 = F_110 ( V_250 ) ;
V_623 = F_412 ( V_24 ) ;
if ( V_623 > V_159 -> V_602 )
continue;
V_153 = F_112 ( V_250 ) ;
V_461 = F_111 ( V_250 ) ;
if ( V_24 -> V_72 == 1 && V_461 > V_159 -> V_485 &&
! F_402 ( V_24 , V_159 -> V_192 ) )
continue;
if ( V_461 * V_622 > V_621 * V_153 ) {
V_621 = V_461 ;
V_622 = V_153 ;
V_568 = V_24 ;
}
}
return V_568 ;
}
static int F_420 ( struct V_530 * V_159 )
{
struct V_191 * V_192 = V_159 -> V_192 ;
if ( V_159 -> V_388 == V_561 ) {
if ( ( V_192 -> V_184 & V_601 ) && V_159 -> V_178 > V_159 -> V_141 )
return 1 ;
}
if ( ( V_159 -> V_388 != V_554 ) &&
( V_159 -> V_177 -> V_40 . V_399 == 1 ) ) {
if ( ( F_402 ( V_159 -> V_177 , V_192 ) ) &&
( F_112 ( V_159 -> V_178 ) * V_192 -> V_174 < F_112 ( V_159 -> V_141 ) * 100 ) )
return 1 ;
}
return F_13 ( V_192 -> V_544 > V_192 -> V_545 + 2 ) ;
}
static int F_421 ( struct V_530 * V_159 )
{
struct V_477 * V_499 = V_159 -> V_192 -> V_480 ;
struct V_624 * V_625 , * V_626 ;
int V_152 , V_627 = - 1 ;
if ( V_159 -> V_388 == V_561 )
return 1 ;
V_625 = F_344 ( V_499 ) ;
V_626 = F_422 ( V_499 ) ;
F_346 (cpu, sg_cpus, env->cpus) {
if ( ! F_124 ( V_152 , V_626 ) || ! F_347 ( V_152 ) )
continue;
V_627 = V_152 ;
break;
}
if ( V_627 == - 1 )
V_627 = F_423 ( V_499 ) ;
return V_627 == V_159 -> V_141 ;
}
static int F_424 ( int V_470 , struct V_24 * V_441 ,
struct V_191 * V_192 , enum V_575 V_388 ,
int * V_628 )
{
int V_629 , V_630 , V_631 = 0 ;
struct V_191 * V_632 = V_192 -> V_34 ;
struct V_477 * V_124 ;
struct V_24 * V_568 ;
unsigned long V_184 ;
struct V_624 * V_8 = F_425 ( V_633 ) ;
struct V_530 V_159 = {
. V_192 = V_192 ,
. V_141 = V_470 ,
. V_179 = V_441 ,
. V_539 = F_344 ( V_192 -> V_480 ) ,
. V_388 = V_388 ,
. V_557 = V_558 ,
. V_8 = V_8 ,
. V_602 = V_604 ,
. V_552 = F_426 ( V_159 . V_552 ) ,
} ;
if ( V_388 == V_561 )
V_159 . V_539 = NULL ;
F_427 ( V_8 , V_634 ) ;
F_242 ( V_192 , V_635 [ V_388 ] ) ;
V_636:
if ( ! F_421 ( & V_159 ) ) {
* V_628 = 0 ;
goto V_619;
}
V_124 = F_418 ( & V_159 ) ;
if ( ! V_124 ) {
F_242 ( V_192 , V_637 [ V_388 ] ) ;
goto V_619;
}
V_568 = F_419 ( & V_159 , V_124 ) ;
if ( ! V_568 ) {
F_242 ( V_192 , V_638 [ V_388 ] ) ;
goto V_619;
}
F_168 ( V_568 == V_159 . V_179 ) ;
F_66 ( V_192 , V_639 [ V_388 ] , V_159 . V_485 ) ;
V_159 . V_178 = V_568 -> V_152 ;
V_159 . V_177 = V_568 ;
V_629 = 0 ;
if ( V_568 -> V_72 > 1 ) {
V_159 . V_184 |= V_542 ;
V_159 . V_556 = F_141 ( V_640 , V_568 -> V_72 ) ;
V_641:
F_391 ( & V_568 -> V_183 , V_184 ) ;
V_630 = F_381 ( & V_159 ) ;
F_278 ( & V_568 -> V_183 ) ;
if ( V_630 ) {
F_389 ( & V_159 ) ;
V_629 += V_630 ;
}
F_428 ( V_184 ) ;
if ( V_159 . V_184 & V_559 ) {
V_159 . V_184 &= ~ V_559 ;
goto V_641;
}
if ( ( V_159 . V_184 & V_540 ) && V_159 . V_485 > 0 ) {
F_429 ( V_159 . V_141 , V_159 . V_8 ) ;
V_159 . V_179 = F_110 ( V_159 . V_541 ) ;
V_159 . V_141 = V_159 . V_541 ;
V_159 . V_184 &= ~ V_540 ;
V_159 . V_555 = 0 ;
V_159 . V_557 = V_558 ;
goto V_641;
}
if ( V_632 ) {
int * V_642 = & V_632 -> V_480 -> V_489 -> V_485 ;
if ( ( V_159 . V_184 & V_538 ) && V_159 . V_485 > 0 )
* V_642 = 1 ;
}
if ( F_13 ( V_159 . V_184 & V_542 ) ) {
F_429 ( F_26 ( V_568 ) , V_8 ) ;
if ( ! F_430 ( V_8 ) ) {
V_159 . V_555 = 0 ;
V_159 . V_557 = V_558 ;
goto V_636;
}
goto V_643;
}
}
if ( ! V_629 ) {
F_242 ( V_192 , V_644 [ V_388 ] ) ;
if ( V_388 != V_561 )
V_192 -> V_544 ++ ;
if ( F_420 ( & V_159 ) ) {
F_391 ( & V_568 -> V_183 , V_184 ) ;
if ( ! F_124 ( V_470 ,
F_125 ( V_568 -> V_45 ) ) ) {
F_392 ( & V_568 -> V_183 ,
V_184 ) ;
V_159 . V_184 |= V_542 ;
goto V_645;
}
if ( ! V_568 -> V_631 ) {
V_568 -> V_631 = 1 ;
V_568 -> V_646 = V_470 ;
V_631 = 1 ;
}
F_392 ( & V_568 -> V_183 , V_184 ) ;
if ( V_631 ) {
F_431 ( F_26 ( V_568 ) ,
V_647 , V_568 ,
& V_568 -> V_648 ) ;
}
V_192 -> V_544 = V_192 -> V_545 + 1 ;
}
} else
V_192 -> V_544 = 0 ;
if ( F_11 ( ! V_631 ) ) {
V_192 -> V_584 = V_192 -> V_649 ;
} else {
if ( V_192 -> V_584 < V_192 -> V_650 )
V_192 -> V_584 *= 2 ;
}
goto V_299;
V_619:
if ( V_632 ) {
int * V_642 = & V_632 -> V_480 -> V_489 -> V_485 ;
if ( * V_642 )
* V_642 = 0 ;
}
V_643:
F_242 ( V_192 , V_651 [ V_388 ] ) ;
V_192 -> V_544 = 0 ;
V_645:
if ( ( ( V_159 . V_184 & V_542 ) &&
V_192 -> V_584 < V_652 ) ||
( V_192 -> V_584 < V_192 -> V_650 ) )
V_192 -> V_584 *= 2 ;
V_629 = 0 ;
V_299:
return V_629 ;
}
static inline unsigned long
F_432 ( struct V_191 * V_192 , int V_653 )
{
unsigned long V_199 = V_192 -> V_584 ;
if ( V_653 )
V_199 *= V_192 -> V_654 ;
V_199 = F_142 ( V_199 ) ;
V_199 = F_147 ( V_199 , 1UL , V_585 ) ;
return V_199 ;
}
static inline void
F_433 ( struct V_191 * V_192 , int V_653 , unsigned long * V_655 )
{
unsigned long V_199 , V_58 ;
V_199 = F_432 ( V_192 , V_653 ) ;
V_58 = V_192 -> V_656 + V_199 ;
if ( F_179 ( * V_655 , V_58 ) )
* V_655 = V_58 ;
}
static int F_232 ( struct V_24 * V_441 )
{
unsigned long V_655 = V_202 + V_200 ;
int V_470 = V_441 -> V_152 ;
struct V_191 * V_192 ;
int V_657 = 0 ;
T_2 V_658 = 0 ;
V_441 -> V_497 = F_73 ( V_441 ) ;
if ( V_441 -> V_659 < V_532 ||
! V_441 -> V_610 -> V_596 ) {
F_119 () ;
V_192 = F_434 ( V_441 -> V_192 ) ;
if ( V_192 )
F_433 ( V_192 , 0 , & V_655 ) ;
F_128 () ;
goto V_299;
}
F_278 ( & V_441 -> V_183 ) ;
F_390 ( V_470 ) ;
F_119 () ;
F_354 (this_cpu, sd) {
int V_628 = 1 ;
T_2 V_660 , V_661 ;
if ( ! ( V_192 -> V_184 & V_509 ) )
continue;
if ( V_441 -> V_659 < V_658 + V_192 -> V_662 ) {
F_433 ( V_192 , 0 , & V_655 ) ;
break;
}
if ( V_192 -> V_184 & V_663 ) {
V_660 = F_271 ( V_470 ) ;
V_657 = F_424 ( V_470 , V_441 ,
V_192 , V_561 ,
& V_628 ) ;
V_661 = F_271 ( V_470 ) - V_660 ;
if ( V_661 > V_192 -> V_662 )
V_192 -> V_662 = V_661 ;
V_658 += V_661 ;
}
F_433 ( V_192 , 0 , & V_655 ) ;
if ( V_657 || V_441 -> V_72 > 0 )
break;
}
F_128 () ;
F_276 ( & V_441 -> V_183 ) ;
if ( V_658 > V_441 -> V_664 )
V_441 -> V_664 = V_658 ;
if ( V_441 -> V_40 . V_399 && ! V_657 )
V_657 = 1 ;
V_299:
if ( F_179 ( V_441 -> V_655 , V_655 ) )
V_441 -> V_655 = V_655 ;
if ( V_441 -> V_72 != V_441 -> V_40 . V_399 )
V_657 = - 1 ;
if ( V_657 )
V_441 -> V_497 = 0 ;
return V_657 ;
}
static int V_647 ( void * V_394 )
{
struct V_24 * V_665 = V_394 ;
int V_611 = F_26 ( V_665 ) ;
int V_666 = V_665 -> V_646 ;
struct V_24 * V_667 = F_110 ( V_666 ) ;
struct V_191 * V_192 ;
struct V_26 * V_29 = NULL ;
F_120 ( & V_665 -> V_183 ) ;
if ( F_13 ( V_611 != F_272 () ||
! V_665 -> V_631 ) )
goto V_668;
if ( V_665 -> V_72 <= 1 )
goto V_668;
F_168 ( V_665 == V_667 ) ;
F_119 () ;
F_354 (target_cpu, sd) {
if ( ( V_192 -> V_184 & V_509 ) &&
F_124 ( V_611 , F_355 ( V_192 ) ) )
break;
}
if ( F_11 ( V_192 ) ) {
struct V_530 V_159 = {
. V_192 = V_192 ,
. V_141 = V_666 ,
. V_179 = V_667 ,
. V_178 = V_665 -> V_152 ,
. V_177 = V_665 ,
. V_388 = V_618 ,
} ;
F_242 ( V_192 , V_669 ) ;
V_29 = F_379 ( & V_159 ) ;
if ( V_29 )
F_242 ( V_192 , V_670 ) ;
else
F_242 ( V_192 , V_671 ) ;
}
F_128 () ;
V_668:
V_665 -> V_631 = 0 ;
F_278 ( & V_665 -> V_183 ) ;
if ( V_29 )
F_388 ( V_667 , V_29 ) ;
F_435 () ;
return 0 ;
}
static inline int F_436 ( struct V_24 * V_24 )
{
return F_13 ( ! F_437 ( V_24 -> V_192 ) ) ;
}
static inline int F_438 ( void )
{
int V_672 = F_439 ( V_673 . V_674 ) ;
if ( V_672 < V_675 && F_347 ( V_672 ) )
return V_672 ;
return V_675 ;
}
static void F_440 ( void )
{
int V_676 ;
V_673 . V_655 ++ ;
V_676 = F_438 () ;
if ( V_676 >= V_675 )
return;
if ( F_441 ( V_677 , F_442 ( V_676 ) ) )
return;
F_443 ( V_676 ) ;
return;
}
static inline void F_444 ( int V_152 )
{
if ( F_13 ( F_445 ( V_678 , F_442 ( V_152 ) ) ) ) {
if ( F_11 ( F_124 ( V_152 , V_673 . V_674 ) ) ) {
F_429 ( V_152 , V_673 . V_674 ) ;
F_446 ( & V_673 . V_679 ) ;
}
F_447 ( V_678 , F_442 ( V_152 ) ) ;
}
}
static inline void F_448 ( void )
{
struct V_191 * V_192 ;
int V_152 = F_272 () ;
F_119 () ;
V_192 = F_133 ( F_134 ( V_680 , V_152 ) ) ;
if ( ! V_192 || ! V_192 -> V_681 )
goto V_186;
V_192 -> V_681 = 0 ;
F_449 ( & V_192 -> V_480 -> V_489 -> V_682 ) ;
V_186:
F_128 () ;
}
void F_450 ( void )
{
struct V_191 * V_192 ;
int V_152 = F_272 () ;
F_119 () ;
V_192 = F_133 ( F_134 ( V_680 , V_152 ) ) ;
if ( ! V_192 || V_192 -> V_681 )
goto V_186;
V_192 -> V_681 = 1 ;
F_446 ( & V_192 -> V_480 -> V_489 -> V_682 ) ;
V_186:
F_128 () ;
}
void F_451 ( int V_152 )
{
if ( ! F_452 ( V_152 ) )
return;
if ( F_445 ( V_678 , F_442 ( V_152 ) ) )
return;
if ( F_436 ( F_110 ( V_152 ) ) )
return;
F_453 ( V_152 , V_673 . V_674 ) ;
F_449 ( & V_673 . V_679 ) ;
F_454 ( V_678 , F_442 ( V_152 ) ) ;
}
static int F_455 ( struct V_683 * V_684 ,
unsigned long V_685 , void * V_686 )
{
switch ( V_685 & ~ V_687 ) {
case V_688 :
F_444 ( F_272 () ) ;
return V_689 ;
default:
return V_690 ;
}
}
void F_456 ( void )
{
V_585 = V_200 * F_457 () / 10 ;
}
static void F_458 ( struct V_24 * V_24 , enum V_575 V_388 )
{
int V_628 = 1 ;
int V_152 = V_24 -> V_152 ;
unsigned long V_199 ;
struct V_191 * V_192 ;
unsigned long V_655 = V_202 + 60 * V_200 ;
int F_433 = 0 ;
int V_691 , V_692 = 0 ;
T_2 V_693 = 0 ;
F_390 ( V_152 ) ;
F_119 () ;
F_354 (cpu, sd) {
if ( F_179 ( V_202 , V_192 -> V_694 ) ) {
V_192 -> V_662 =
( V_192 -> V_662 * 253 ) / 256 ;
V_192 -> V_694 = V_202 + V_200 ;
V_692 = 1 ;
}
V_693 += V_192 -> V_662 ;
if ( ! ( V_192 -> V_184 & V_509 ) )
continue;
if ( ! V_628 ) {
if ( V_692 )
continue;
break;
}
V_199 = F_432 ( V_192 , V_388 != V_618 ) ;
V_691 = V_192 -> V_184 & V_695 ;
if ( V_691 ) {
if ( ! F_459 ( & V_696 ) )
goto V_299;
}
if ( F_414 ( V_202 , V_192 -> V_656 + V_199 ) ) {
if ( F_424 ( V_152 , V_24 , V_192 , V_388 , & V_628 ) ) {
V_388 = F_347 ( V_152 ) ? V_618 : V_554 ;
}
V_192 -> V_656 = V_202 ;
V_199 = F_432 ( V_192 , V_388 != V_618 ) ;
}
if ( V_691 )
F_171 ( & V_696 ) ;
V_299:
if ( F_179 ( V_655 , V_192 -> V_656 + V_199 ) ) {
V_655 = V_192 -> V_656 + V_199 ;
F_433 = 1 ;
}
}
if ( V_692 ) {
V_24 -> V_664 =
F_65 ( ( T_2 ) V_532 , V_693 ) ;
}
F_128 () ;
if ( F_11 ( F_433 ) ) {
V_24 -> V_655 = V_655 ;
#ifdef F_460
if ( ( V_388 == V_618 ) && F_179 ( V_673 . V_655 , V_24 -> V_655 ) )
V_673 . V_655 = V_24 -> V_655 ;
#endif
}
}
static void F_461 ( struct V_24 * V_441 , enum V_575 V_388 )
{
int V_470 = V_441 -> V_152 ;
struct V_24 * V_24 ;
int V_627 ;
unsigned long V_655 = V_202 + 60 * V_200 ;
int F_433 = 0 ;
if ( V_388 != V_618 ||
! F_445 ( V_677 , F_442 ( V_470 ) ) )
goto V_279;
F_109 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_627 == V_470 || ! F_347 ( V_627 ) )
continue;
if ( F_462 () )
break;
V_24 = F_110 ( V_627 ) ;
if ( F_414 ( V_202 , V_24 -> V_655 ) ) {
F_120 ( & V_24 -> V_183 ) ;
F_290 ( V_24 ) ;
F_329 ( V_24 ) ;
F_123 ( & V_24 -> V_183 ) ;
F_458 ( V_24 , V_618 ) ;
}
if ( F_179 ( V_655 , V_24 -> V_655 ) ) {
V_655 = V_24 -> V_655 ;
F_433 = 1 ;
}
}
if ( F_11 ( F_433 ) )
V_673 . V_655 = V_655 ;
V_279:
F_447 ( V_677 , F_442 ( V_470 ) ) ;
}
static inline bool F_463 ( struct V_24 * V_24 )
{
unsigned long V_86 = V_202 ;
struct V_191 * V_192 ;
struct V_588 * V_489 ;
int V_697 , V_152 = V_24 -> V_152 ;
bool V_698 = false ;
if ( F_13 ( V_24 -> F_232 ) )
return false ;
F_448 () ;
F_444 ( V_152 ) ;
if ( F_11 ( ! F_464 ( & V_673 . V_679 ) ) )
return false ;
if ( F_183 ( V_86 , V_673 . V_655 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_119 () ;
V_192 = F_133 ( F_134 ( V_680 , V_152 ) ) ;
if ( V_192 ) {
V_489 = V_192 -> V_480 -> V_489 ;
V_697 = F_464 ( & V_489 -> V_682 ) ;
if ( V_697 > 1 ) {
V_698 = true ;
goto V_186;
}
}
V_192 = F_133 ( V_24 -> V_192 ) ;
if ( V_192 ) {
if ( ( V_24 -> V_40 . V_399 >= 1 ) &&
F_402 ( V_24 , V_192 ) ) {
V_698 = true ;
goto V_186;
}
}
V_192 = F_133 ( F_134 ( V_699 , V_152 ) ) ;
if ( V_192 && ( F_351 ( V_673 . V_674 ,
F_355 ( V_192 ) ) < V_152 ) ) {
V_698 = true ;
goto V_186;
}
V_186:
F_128 () ;
return V_698 ;
}
static void F_461 ( struct V_24 * V_441 , enum V_575 V_388 ) { }
static void F_465 ( struct V_700 * V_701 )
{
struct V_24 * V_441 = V_441 () ;
enum V_575 V_388 = V_441 -> F_232 ?
V_618 : V_554 ;
F_461 ( V_441 , V_388 ) ;
F_458 ( V_441 , V_388 ) ;
}
void F_466 ( struct V_24 * V_24 )
{
if ( F_13 ( F_436 ( V_24 ) ) )
return;
if ( F_414 ( V_202 , V_24 -> V_655 ) )
F_467 ( V_702 ) ;
#ifdef F_460
if ( F_463 ( V_24 ) )
F_440 () ;
#endif
}
static void F_468 ( struct V_24 * V_24 )
{
F_7 () ;
F_315 ( V_24 ) ;
}
static void F_469 ( struct V_24 * V_24 )
{
F_7 () ;
F_317 ( V_24 ) ;
}
static void F_470 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_370 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_259 ( V_25 , V_28 , V_370 ) ;
}
if ( F_471 ( & V_264 ) )
F_194 ( V_24 , V_45 ) ;
}
static void F_472 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_470 = F_272 () ;
struct V_24 * V_24 = V_441 () ;
unsigned long V_184 ;
F_391 ( & V_24 -> V_183 , V_184 ) ;
F_290 ( V_24 ) ;
V_25 = F_22 ( V_146 ) ;
V_45 = V_25 -> V_45 ;
F_119 () ;
F_473 ( V_29 , V_470 ) ;
F_128 () ;
F_62 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_243 ( V_25 , V_28 , 1 ) ;
if ( V_703 && V_45 && F_37 ( V_45 , V_28 ) ) {
F_117 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_253 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_36 ;
F_392 ( & V_24 -> V_183 , V_184 ) ;
}
static void
F_474 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_704 )
{
if ( ! F_475 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_705 > V_704 )
F_253 ( V_24 ) ;
} else
F_387 ( V_24 , V_29 , 0 ) ;
}
static inline bool F_476 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_74 )
return true ;
if ( ! V_28 -> V_90 || V_29 -> V_363 == V_706 )
return true ;
return false ;
}
static void F_477 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( ! F_476 ( V_29 ) ) {
F_243 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_36 ;
}
F_225 ( V_25 , V_28 ) ;
}
static void F_478 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
#ifdef F_364
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
F_224 ( V_25 , V_28 ) ;
if ( ! F_476 ( V_29 ) )
V_28 -> V_41 += V_25 -> F_36 ;
}
static void F_479 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_477 ( V_29 ) ;
}
static void F_480 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_478 ( V_29 ) ;
if ( F_475 ( V_29 ) ) {
if ( V_24 -> V_45 == V_29 )
F_253 ( V_24 ) ;
else
F_387 ( V_24 , V_29 , 0 ) ;
}
}
static void F_481 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_254 ( V_25 , V_28 ) ;
F_70 ( V_25 , 0 ) ;
}
}
void F_482 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_707 ;
V_25 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_25 -> V_48 = V_25 -> F_36 ;
#endif
#ifdef F_198
F_483 ( & V_25 -> V_336 , 0 ) ;
F_483 ( & V_25 -> V_338 , 0 ) ;
#endif
}
static void F_484 ( struct V_26 * V_29 )
{
F_477 ( V_29 ) ;
F_485 ( V_29 , F_132 ( V_29 ) ) ;
#ifdef F_198
V_29 -> V_28 . V_77 . V_78 = 0 ;
#endif
F_478 ( V_29 ) ;
}
void F_486 ( struct V_303 * V_33 )
{
int V_250 ;
F_313 ( F_274 ( V_33 ) ) ;
F_487 (i) {
if ( V_33 -> V_25 )
F_176 ( V_33 -> V_25 [ V_250 ] ) ;
if ( V_33 -> V_28 ) {
if ( V_33 -> V_28 [ V_250 ] )
F_229 ( V_33 -> V_28 [ V_250 ] ) ;
F_176 ( V_33 -> V_28 [ V_250 ] ) ;
}
}
F_176 ( V_33 -> V_25 ) ;
F_176 ( V_33 -> V_28 ) ;
}
int F_488 ( struct V_303 * V_33 , struct V_303 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_250 ;
V_33 -> V_25 = F_164 ( sizeof( V_25 ) * V_675 , V_252 ) ;
if ( ! V_33 -> V_25 )
goto V_708;
V_33 -> V_28 = F_164 ( sizeof( V_28 ) * V_675 , V_252 ) ;
if ( ! V_33 -> V_28 )
goto V_708;
V_33 -> V_306 = V_71 ;
F_306 ( F_274 ( V_33 ) ) ;
F_487 (i) {
V_25 = F_489 ( sizeof( struct V_25 ) ,
V_252 , F_101 ( V_250 ) ) ;
if ( ! V_25 )
goto V_708;
V_28 = F_489 ( sizeof( struct V_27 ) ,
V_252 , F_101 ( V_250 ) ) ;
if ( ! V_28 )
goto V_709;
F_482 ( V_25 ) ;
F_490 ( V_33 , V_25 , V_28 , V_250 , V_34 -> V_28 [ V_250 ] ) ;
F_61 ( V_28 ) ;
}
return 1 ;
V_709:
F_176 ( V_25 ) ;
V_708:
return 0 ;
}
void F_491 ( struct V_303 * V_33 , int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_184 ;
if ( ! V_33 -> V_25 [ V_152 ] -> V_32 )
return;
F_391 ( & V_24 -> V_183 , V_184 ) ;
F_29 ( V_33 -> V_25 [ V_152 ] ) ;
F_392 ( & V_24 -> V_183 , V_184 ) ;
}
void F_490 ( struct V_303 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_152 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_310 ( V_25 ) ;
V_33 -> V_25 [ V_152 ] = V_25 ;
V_33 -> V_28 [ V_152 ] = V_28 ;
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
int F_492 ( struct V_303 * V_33 , unsigned long V_306 )
{
int V_250 ;
unsigned long V_184 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_196 ;
V_306 = F_147 ( V_306 , F_493 ( V_307 ) , F_493 ( V_710 ) ) ;
F_494 ( & V_711 ) ;
if ( V_33 -> V_306 == V_306 )
goto V_501;
V_33 -> V_306 = V_306 ;
F_487 (i) {
struct V_24 * V_24 = F_110 ( V_250 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_250 ] ;
F_391 ( & V_24 -> V_183 , V_184 ) ;
F_290 ( V_24 ) ;
F_59 (se)
F_206 ( F_24 ( V_28 ) ) ;
F_392 ( & V_24 -> V_183 , V_184 ) ;
}
V_501:
F_495 ( & V_711 ) ;
return 0 ;
}
void F_486 ( struct V_303 * V_33 ) { }
int F_488 ( struct V_303 * V_33 , struct V_303 * V_34 )
{
return 1 ;
}
void F_491 ( struct V_303 * V_33 , int V_152 ) { }
static unsigned int F_496 ( struct V_24 * V_24 , struct V_26 * V_127 )
{
struct V_27 * V_28 = & V_127 -> V_28 ;
unsigned int V_712 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_712 = F_497 ( F_58 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_712 ;
}
void F_498 ( struct V_713 * V_714 , int V_152 )
{
struct V_25 * V_25 ;
F_119 () ;
F_316 (cpu_rq(cpu), cfs_rq)
F_499 ( V_714 , V_152 , V_25 ) ;
F_128 () ;
}
void F_500 ( struct V_26 * V_29 , struct V_713 * V_714 )
{
int V_129 ;
unsigned long V_715 = 0 , V_716 = 0 , V_717 = 0 , V_718 = 0 ;
F_96 (node) {
if ( V_29 -> V_121 ) {
V_715 = V_29 -> V_121 [ F_91 ( V_122 , V_129 , 0 ) ] ;
V_716 = V_29 -> V_121 [ F_91 ( V_122 , V_129 , 1 ) ] ;
}
if ( V_29 -> V_113 ) {
V_717 = V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_129 , 0 ) ] ,
V_718 = V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_129 , 1 ) ] ;
}
F_501 ( V_714 , V_129 , V_715 , V_716 , V_717 , V_718 ) ;
}
}
T_12 void F_502 ( void )
{
#ifdef F_198
F_503 ( V_702 , F_465 ) ;
#ifdef F_460
V_673 . V_655 = V_202 ;
F_504 ( & V_673 . V_674 , V_719 ) ;
F_505 ( F_455 , 0 ) ;
#endif
#endif
}
