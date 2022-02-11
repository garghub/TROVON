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
V_76 -> V_85 = V_82 ;
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
F_64 ( V_28 -> V_88 . V_93 , F_73 ( F_16 ( V_25 ) ) ) ;
}
static void F_74 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_72 ( V_25 , V_28 ) ;
}
static void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_64 ( V_28 -> V_88 . V_94 , F_65 ( V_28 -> V_88 . V_94 ,
F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_93 ) ) ;
F_64 ( V_28 -> V_88 . V_95 , V_28 -> V_88 . V_95 + 1 ) ;
F_64 ( V_28 -> V_88 . V_96 , V_28 -> V_88 . V_96 +
F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_93 ) ;
#ifdef F_76
if ( F_20 ( V_28 ) ) {
F_77 ( F_17 ( V_28 ) ,
F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_93 ) ;
}
#endif
F_64 ( V_28 -> V_88 . V_93 , 0 ) ;
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
if ( V_29 )
F_116 ( V_29 ) ;
V_159 -> V_161 = V_29 ;
V_159 -> V_162 = V_160 ;
V_159 -> V_163 = V_159 -> V_141 ;
}
static bool F_117 ( long V_164 , long V_165 ,
struct V_158 * V_159 )
{
long V_166 , V_167 ;
long V_168 , V_169 ;
long V_170 , V_171 ;
V_170 = V_159 -> V_172 . V_154 ;
V_171 = V_159 -> V_173 . V_154 ;
if ( V_165 < V_164 )
F_118 ( V_165 , V_164 ) ;
V_166 = V_165 * V_170 * 100 -
V_164 * V_171 * V_159 -> V_174 ;
if ( V_166 <= 0 )
return false ;
V_168 = V_159 -> V_172 . V_70 ;
V_169 = V_159 -> V_173 . V_70 ;
if ( V_169 < V_168 )
F_118 ( V_169 , V_168 ) ;
V_167 = V_169 * V_170 * 100 -
V_168 * V_171 * V_159 -> V_174 ;
return ( V_166 > V_167 ) ;
}
static void F_119 ( struct V_158 * V_159 ,
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
F_120 () ;
F_121 ( & V_179 -> V_182 ) ;
V_180 = V_179 -> V_45 ;
if ( ( V_180 -> V_183 & V_184 ) || F_122 ( V_180 ) )
V_180 = NULL ;
F_123 ( & V_179 -> V_182 ) ;
if ( V_180 == V_159 -> V_29 )
goto V_185;
if ( V_180 ) {
if ( ! F_124 ( V_159 -> V_178 , F_125 ( V_180 ) ) )
goto V_185;
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
goto V_185;
if ( ! V_180 ) {
if ( V_159 -> V_172 . V_72 <= V_159 -> V_172 . V_156 &&
! V_159 -> V_173 . V_157 )
goto V_185;
goto V_186;
}
if ( V_160 > V_159 -> V_162 && V_177 -> V_72 == 1 &&
V_179 -> V_72 == 1 )
goto V_187;
V_186:
V_70 = F_126 ( V_159 -> V_29 ) ;
V_165 = V_159 -> V_173 . V_70 + V_70 ;
V_164 = V_159 -> V_172 . V_70 - V_70 ;
if ( V_181 > V_160 && V_181 > V_159 -> V_162 ) {
if ( ! F_117 ( V_164 , V_165 , V_159 ) ) {
V_160 = V_181 - 1 ;
V_180 = NULL ;
goto V_187;
}
}
if ( V_160 <= V_159 -> V_162 )
goto V_185;
if ( V_180 ) {
V_70 = F_126 ( V_180 ) ;
V_165 -= V_70 ;
V_164 += V_70 ;
}
if ( F_117 ( V_164 , V_165 , V_159 ) )
goto V_185;
if ( ! V_180 )
V_159 -> V_141 = F_127 ( V_159 -> V_29 , V_159 -> V_141 ) ;
V_187:
F_114 ( V_159 , V_180 , V_160 ) ;
V_185:
F_128 () ;
}
static void F_129 ( struct V_158 * V_159 ,
long V_175 , long V_176 )
{
int V_152 ;
F_109 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_124 ( V_152 , F_125 ( V_159 -> V_29 ) ) )
continue;
V_159 -> V_141 = V_152 ;
F_119 ( V_159 , V_175 , V_176 ) ;
}
}
static bool F_130 ( struct V_158 * V_159 )
{
struct V_149 * V_188 = & V_159 -> V_172 ;
struct V_149 * V_189 = & V_159 -> V_173 ;
if ( V_188 -> V_157 && ! V_189 -> V_157 )
return false ;
if ( V_188 -> V_70 * V_189 -> V_154 * V_159 -> V_174 >
V_189 -> V_70 * V_188 -> V_154 * 100 )
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
struct V_190 * V_191 ;
unsigned long V_192 , V_193 ;
int V_117 , V_66 , V_132 ;
long V_175 , V_176 ;
F_120 () ;
V_191 = F_133 ( F_134 ( V_194 , V_159 . V_178 ) ) ;
if ( V_191 )
V_159 . V_174 = 100 + ( V_191 -> V_174 - 100 ) / 2 ;
F_128 () ;
if ( F_13 ( ! V_191 ) ) {
V_29 -> V_111 = F_88 ( V_29 ) ;
return - V_195 ;
}
V_159 . V_143 = V_29 -> V_111 ;
V_132 = V_159 . V_132 = F_97 ( V_159 . V_140 , V_159 . V_143 ) ;
V_192 = F_98 ( V_29 , V_159 . V_140 , V_132 ) ;
V_193 = F_99 ( V_29 , V_159 . V_140 , V_132 ) ;
F_108 ( & V_159 . V_172 , V_159 . V_140 ) ;
V_175 = F_98 ( V_29 , V_159 . V_143 , V_132 ) - V_192 ;
V_176 = F_99 ( V_29 , V_159 . V_143 , V_132 ) - V_193 ;
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
V_192 = F_98 ( V_29 , V_159 . V_140 , V_132 ) ;
V_193 = F_99 ( V_29 , V_159 . V_140 , V_132 ) ;
}
V_175 = F_98 ( V_29 , V_117 , V_132 ) - V_192 ;
V_176 = F_99 ( V_29 , V_117 , V_132 ) - V_193 ;
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
return - V_196 ;
V_29 -> V_197 = F_83 ( V_29 ) ;
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
unsigned long V_198 = V_199 ;
if ( F_13 ( V_29 -> V_111 == - 1 || ! V_29 -> V_121 ) )
return;
V_198 = F_141 ( V_198 , F_142 ( V_29 -> V_197 ) / 16 ) ;
V_29 -> V_200 = V_201 + V_198 ;
if ( F_88 ( V_29 ) == V_29 -> V_111 )
return;
F_131 ( V_29 ) ;
}
static void F_143 ( struct V_113 * V_113 )
{
unsigned long V_123 , V_202 = 0 ;
int V_117 ;
F_96 (nid) {
V_123 = F_94 ( V_113 , V_117 ) ;
if ( V_123 > V_202 )
V_202 = V_123 ;
}
F_96 (nid) {
V_123 = F_94 ( V_113 , V_117 ) ;
if ( ! F_107 ( V_117 , V_113 -> V_148 ) ) {
if ( V_123 > V_202 * 6 / 16 )
F_144 ( V_117 , V_113 -> V_148 ) ;
} else if ( V_123 < V_202 * 3 / 16 )
F_145 ( V_117 , V_113 -> V_148 ) ;
}
}
static void F_146 ( struct V_26 * V_29 ,
unsigned long V_203 , unsigned long V_204 )
{
unsigned int V_205 ;
int V_206 ;
int V_207 ;
unsigned long V_208 = V_29 -> V_209 [ 0 ] ;
unsigned long V_210 = V_29 -> V_209 [ 1 ] ;
if ( V_210 + V_203 == 0 || V_29 -> V_209 [ 2 ] ) {
V_29 -> V_197 = F_141 ( V_29 -> V_211 ,
V_29 -> V_197 << 1 ) ;
V_29 -> V_101 -> V_212 = V_201 +
F_142 ( V_29 -> V_197 ) ;
return;
}
V_205 = F_54 ( V_29 -> V_197 , V_213 ) ;
V_206 = ( V_210 * V_213 ) / ( V_210 + V_208 ) ;
if ( V_206 >= V_214 ) {
int V_215 = V_206 - V_214 ;
if ( ! V_215 )
V_215 = 1 ;
V_207 = V_215 * V_205 ;
} else {
V_207 = - ( V_214 - V_206 ) * V_205 ;
V_206 = F_54 ( V_204 * V_213 , ( V_204 + V_203 + 1 ) ) ;
V_207 = ( V_207 * V_206 ) / V_213 ;
}
V_29 -> V_197 = F_147 ( V_29 -> V_197 + V_207 ,
F_83 ( V_29 ) , F_86 ( V_29 ) ) ;
memset ( V_29 -> V_209 , 0 , sizeof( V_29 -> V_209 ) ) ;
}
static T_2 F_148 ( struct V_26 * V_29 , T_2 * V_216 )
{
T_2 V_217 , V_42 , V_86 ;
V_86 = V_29 -> V_28 . V_87 ;
V_217 = V_29 -> V_28 . V_90 ;
if ( V_29 -> V_218 ) {
V_42 = V_217 - V_29 -> V_219 ;
* V_216 = V_86 - V_29 -> V_218 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_70 . V_4 ;
* V_216 = V_82 ;
}
V_29 -> V_219 = V_217 ;
V_29 -> V_218 = V_86 ;
return V_42 ;
}
static int F_149 ( struct V_26 * V_29 , int V_117 )
{
T_8 V_220 ;
int V_132 ;
if ( V_130 == V_131 )
return V_117 ;
if ( V_130 == V_135 ) {
unsigned long V_128 , V_221 = 0 ;
int V_129 , V_222 = V_117 ;
V_132 = V_133 ;
F_96 (node) {
V_128 = F_99 ( V_29 , V_129 , V_132 ) ;
if ( V_128 > V_221 ) {
V_221 = V_128 ;
V_222 = V_129 ;
}
}
return V_222 ;
}
V_220 = V_223 ;
for ( V_132 = V_133 ; V_132 > V_136 ; V_132 -- ) {
unsigned long V_202 = 0 ;
T_8 V_224 = V_225 ;
int V_43 , V_44 ;
if ( ! F_150 ( V_132 ) )
continue;
F_151 (a, nodes) {
unsigned long V_123 = 0 ;
T_8 V_226 ;
F_152 ( V_226 ) ;
F_151 (b, nodes) {
if ( F_97 ( V_43 , V_44 ) < V_132 ) {
V_123 += F_93 ( V_29 , V_44 ) ;
F_144 ( V_44 , V_226 ) ;
F_145 ( V_44 , V_220 ) ;
}
}
if ( V_123 > V_202 ) {
V_202 = V_123 ;
V_224 = V_226 ;
V_117 = V_43 ;
}
}
if ( ! V_202 )
break;
V_220 = V_224 ;
}
return V_117 ;
}
static void F_153 ( struct V_26 * V_29 )
{
int V_227 , V_117 , V_228 = - 1 , V_229 = - 1 ;
unsigned long V_202 = 0 , V_230 = 0 ;
unsigned long V_231 [ 2 ] = { 0 , 0 } ;
unsigned long V_137 ;
T_2 V_217 , V_216 ;
T_9 * V_232 = NULL ;
V_227 = F_84 ( V_29 -> V_101 -> V_233 ) ;
if ( V_29 -> V_233 == V_227 )
return;
V_29 -> V_233 = V_227 ;
V_29 -> V_211 = F_86 ( V_29 ) ;
V_137 = V_29 -> V_209 [ 0 ] +
V_29 -> V_209 [ 1 ] ;
V_217 = F_148 ( V_29 , & V_216 ) ;
if ( V_29 -> V_113 ) {
V_232 = & V_29 -> V_113 -> V_182 ;
F_154 ( V_232 ) ;
}
F_96 (nid) {
int V_234 , V_235 , V_236 , V_237 ;
unsigned long V_123 = 0 , F_93 = 0 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
long V_207 , V_238 , V_239 ;
V_234 = F_91 ( V_122 , V_117 , V_118 ) ;
V_235 = F_91 ( V_240 , V_117 , V_118 ) ;
V_236 = F_91 ( V_241 , V_117 , V_118 ) ;
V_237 = F_91 ( V_242 , V_117 , V_118 ) ;
V_207 = V_29 -> V_121 [ V_235 ] - V_29 -> V_121 [ V_234 ] / 2 ;
V_231 [ V_118 ] += V_29 -> V_121 [ V_235 ] ;
V_29 -> V_121 [ V_235 ] = 0 ;
V_239 = F_155 ( V_217 << 16 , V_216 + 1 ) ;
V_239 = ( V_239 * V_29 -> V_121 [ V_237 ] ) /
( V_137 + 1 ) ;
V_238 = V_239 - V_29 -> V_121 [ V_236 ] / 2 ;
V_29 -> V_121 [ V_237 ] = 0 ;
V_29 -> V_121 [ V_234 ] += V_207 ;
V_29 -> V_121 [ V_236 ] += V_238 ;
V_123 += V_29 -> V_121 [ V_234 ] ;
V_29 -> V_138 += V_207 ;
if ( V_29 -> V_113 ) {
V_29 -> V_113 -> V_123 [ V_234 ] += V_207 ;
V_29 -> V_113 -> V_125 [ V_234 ] += V_238 ;
V_29 -> V_113 -> V_137 += V_207 ;
F_93 += V_29 -> V_113 -> V_123 [ V_234 ] ;
}
}
if ( V_123 > V_202 ) {
V_202 = V_123 ;
V_228 = V_117 ;
}
if ( F_93 > V_230 ) {
V_230 = F_93 ;
V_229 = V_117 ;
}
}
F_146 ( V_29 , V_231 [ 0 ] , V_231 [ 1 ] ) ;
if ( V_29 -> V_113 ) {
F_143 ( V_29 -> V_113 ) ;
F_156 ( V_232 ) ;
V_228 = F_149 ( V_29 , V_229 ) ;
}
if ( V_202 ) {
if ( V_228 != V_29 -> V_111 )
F_136 ( V_29 , V_228 ) ;
if ( F_88 ( V_29 ) != V_29 -> V_111 )
F_140 ( V_29 ) ;
}
}
static inline int F_157 ( struct V_113 * V_30 )
{
return F_158 ( & V_30 -> V_243 ) ;
}
static inline void F_159 ( struct V_113 * V_30 )
{
if ( F_160 ( & V_30 -> V_243 ) )
F_161 ( V_30 , V_244 ) ;
}
static void F_162 ( struct V_26 * V_29 , int V_245 , int V_183 ,
int * V_118 )
{
struct V_113 * V_30 , * V_246 ;
struct V_26 * V_247 ;
bool V_248 = false ;
int V_152 = F_163 ( V_245 ) ;
int V_249 ;
if ( F_13 ( ! V_29 -> V_113 ) ) {
unsigned int V_250 = sizeof( struct V_113 ) +
4 * V_120 *sizeof( unsigned long ) ;
V_30 = F_164 ( V_250 , V_251 | V_252 ) ;
if ( ! V_30 )
return;
F_165 ( & V_30 -> V_243 , 1 ) ;
F_166 ( & V_30 -> V_182 ) ;
V_30 -> V_114 = V_29 -> V_147 ;
V_30 -> V_125 = V_30 -> V_123 + V_119 *
V_120 ;
F_144 ( F_88 ( V_146 ) , V_30 -> V_148 ) ;
for ( V_249 = 0 ; V_249 < V_253 * V_120 ; V_249 ++ )
V_30 -> V_123 [ V_249 ] = V_29 -> V_121 [ V_249 ] ;
V_30 -> V_137 = V_29 -> V_138 ;
V_30 -> V_254 ++ ;
F_167 ( V_29 -> V_113 , V_30 ) ;
}
F_120 () ;
V_247 = F_84 ( F_110 ( V_152 ) -> V_45 ) ;
if ( ! F_106 ( V_247 , V_245 ) )
goto V_255;
V_30 = F_133 ( V_247 -> V_113 ) ;
if ( ! V_30 )
goto V_255;
V_246 = V_29 -> V_113 ;
if ( V_30 == V_246 )
goto V_255;
if ( V_246 -> V_254 > V_30 -> V_254 )
goto V_255;
if ( V_246 -> V_254 == V_30 -> V_254 && V_246 > V_30 )
goto V_255;
if ( V_247 -> V_101 == V_146 -> V_101 )
V_248 = true ;
if ( V_183 & V_256 )
V_248 = true ;
* V_118 = ! V_248 ;
if ( V_248 && ! F_157 ( V_30 ) )
goto V_255;
F_128 () ;
if ( ! V_248 )
return;
F_168 ( F_169 () ) ;
F_170 ( & V_246 -> V_182 , & V_30 -> V_182 ) ;
for ( V_249 = 0 ; V_249 < V_253 * V_120 ; V_249 ++ ) {
V_246 -> V_123 [ V_249 ] -= V_29 -> V_121 [ V_249 ] ;
V_30 -> V_123 [ V_249 ] += V_29 -> V_121 [ V_249 ] ;
}
V_246 -> V_137 -= V_29 -> V_138 ;
V_30 -> V_137 += V_29 -> V_138 ;
V_246 -> V_254 -- ;
V_30 -> V_254 ++ ;
F_171 ( & V_246 -> V_182 ) ;
F_156 ( & V_30 -> V_182 ) ;
F_167 ( V_29 -> V_113 , V_30 ) ;
F_159 ( V_246 ) ;
return;
V_255:
F_128 () ;
return;
}
void F_172 ( struct V_26 * V_29 )
{
struct V_113 * V_30 = V_29 -> V_113 ;
void * V_121 = V_29 -> V_121 ;
unsigned long V_183 ;
int V_249 ;
if ( V_30 ) {
F_173 ( & V_30 -> V_182 , V_183 ) ;
for ( V_249 = 0 ; V_249 < V_253 * V_120 ; V_249 ++ )
V_30 -> V_123 [ V_249 ] -= V_29 -> V_121 [ V_249 ] ;
V_30 -> V_137 -= V_29 -> V_138 ;
V_30 -> V_254 -- ;
F_174 ( & V_30 -> V_182 , V_183 ) ;
F_175 ( V_29 -> V_113 , NULL ) ;
F_159 ( V_30 ) ;
}
V_29 -> V_121 = NULL ;
F_176 ( V_121 ) ;
}
void F_177 ( int V_144 , int V_257 , int V_258 , int V_183 )
{
struct V_26 * V_29 = V_146 ;
bool V_259 = V_183 & V_260 ;
int V_261 = F_88 ( V_146 ) ;
int V_210 = ! ! ( V_183 & V_262 ) ;
int V_118 ;
if ( ! V_263 )
return;
if ( ! V_29 -> V_101 )
return;
if ( F_13 ( ! V_29 -> V_121 ) ) {
int V_250 = sizeof( * V_29 -> V_121 ) *
V_264 * V_120 ;
V_29 -> V_121 = F_164 ( V_250 , V_251 | V_252 ) ;
if ( ! V_29 -> V_121 )
return;
V_29 -> V_138 = 0 ;
memset ( V_29 -> V_209 , 0 , sizeof( V_29 -> V_209 ) ) ;
}
if ( F_13 ( V_144 == ( - 1 & V_265 ) ) ) {
V_118 = 1 ;
} else {
V_118 = F_106 ( V_29 , V_144 ) ;
if ( ! V_118 && ! ( V_183 & V_266 ) )
F_162 ( V_29 , V_144 , V_183 , & V_118 ) ;
}
if ( ! V_118 && ! V_210 && V_29 -> V_113 &&
F_107 ( V_261 , V_29 -> V_113 -> V_148 ) &&
F_107 ( V_257 , V_29 -> V_113 -> V_148 ) )
V_210 = 1 ;
F_153 ( V_29 ) ;
if ( F_178 ( V_201 , V_29 -> V_200 ) )
F_140 ( V_29 ) ;
if ( V_259 )
V_29 -> V_267 += V_258 ;
if ( V_183 & V_268 )
V_29 -> V_209 [ 2 ] += V_258 ;
V_29 -> V_121 [ F_91 ( V_240 , V_257 , V_118 ) ] += V_258 ;
V_29 -> V_121 [ F_91 ( V_242 , V_261 , V_118 ) ] += V_258 ;
V_29 -> V_209 [ V_210 ] += V_258 ;
}
static void F_179 ( struct V_26 * V_29 )
{
F_180 ( V_29 -> V_101 -> V_233 , F_84 ( V_29 -> V_101 -> V_233 ) + 1 ) ;
V_29 -> V_101 -> V_269 = 0 ;
}
void F_181 ( struct V_270 * V_271 )
{
unsigned long V_272 , V_273 , V_86 = V_201 ;
struct V_26 * V_29 = V_146 ;
struct V_274 * V_101 = V_29 -> V_101 ;
struct V_275 * V_276 ;
unsigned long V_277 , V_278 ;
unsigned long V_279 = 0 ;
long V_258 ;
F_19 ( V_29 != F_21 ( V_271 , struct V_26 , V_280 ) ) ;
V_271 -> V_58 = V_271 ;
if ( V_29 -> V_183 & V_184 )
return;
if ( ! V_101 -> V_212 ) {
V_101 -> V_212 = V_86 +
F_142 ( V_281 ) ;
}
V_272 = V_101 -> V_212 ;
if ( F_182 ( V_86 , V_272 ) )
return;
if ( V_29 -> V_197 == 0 ) {
V_29 -> V_211 = F_86 ( V_29 ) ;
V_29 -> V_197 = F_83 ( V_29 ) ;
}
V_273 = V_86 + F_142 ( V_29 -> V_197 ) ;
if ( F_183 ( & V_101 -> V_212 , V_272 , V_273 ) != V_272 )
return;
V_29 -> V_282 += 2 * V_283 ;
V_277 = V_101 -> V_269 ;
V_258 = V_99 ;
V_258 <<= 20 - V_100 ;
if ( ! V_258 )
return;
F_184 ( & V_101 -> V_284 ) ;
V_276 = F_185 ( V_101 , V_277 ) ;
if ( ! V_276 ) {
F_179 ( V_29 ) ;
V_277 = 0 ;
V_276 = V_101 -> V_285 ;
}
for (; V_276 ; V_276 = V_276 -> V_286 ) {
if ( ! F_186 ( V_276 ) || ! F_187 ( V_276 ) ||
F_188 ( V_276 ) || ( V_276 -> V_287 & V_288 ) ) {
continue;
}
if ( ! V_276 -> V_289 ||
( V_276 -> V_290 && ( V_276 -> V_287 & ( V_291 | V_292 ) ) == ( V_291 ) ) )
continue;
if ( ! ( V_276 -> V_287 & ( V_291 | V_293 | V_292 ) ) )
continue;
do {
V_277 = F_65 ( V_277 , V_276 -> V_294 ) ;
V_278 = F_189 ( V_277 + ( V_258 << V_100 ) , V_295 ) ;
V_278 = F_141 ( V_278 , V_276 -> V_296 ) ;
V_279 += F_190 ( V_276 , V_277 , V_278 ) ;
if ( V_279 )
V_258 -= ( V_278 - V_277 ) >> V_100 ;
V_277 = V_278 ;
if ( V_258 <= 0 )
goto V_297;
F_191 () ;
} while ( V_278 != V_276 -> V_296 );
}
V_297:
if ( V_276 )
V_101 -> V_269 = V_277 ;
else
F_179 ( V_29 ) ;
F_192 ( & V_101 -> V_284 ) ;
}
void F_193 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_270 * V_271 = & V_45 -> V_280 ;
T_2 V_216 , V_86 ;
if ( ! V_45 -> V_101 || ( V_45 -> V_183 & V_184 ) || V_271 -> V_58 != V_271 )
return;
V_86 = V_45 -> V_28 . V_90 ;
V_216 = ( T_2 ) V_45 -> V_197 * V_298 ;
if ( V_86 - V_45 -> V_282 > V_216 ) {
if ( ! V_45 -> V_282 )
V_45 -> V_197 = F_83 ( V_45 ) ;
V_45 -> V_282 += V_216 ;
if ( ! F_182 ( V_201 , V_45 -> V_101 -> V_212 ) ) {
F_194 ( V_271 , F_181 ) ;
F_195 ( V_45 , V_271 , true ) ;
}
}
}
static void F_193 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_87 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_196 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_1 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_197
if ( F_20 ( V_28 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_87 ( V_24 , F_17 ( V_28 ) ) ;
F_198 ( & V_28 -> V_299 , & V_24 -> V_300 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_199 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_2 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_20 ( V_28 ) ) {
F_89 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_200 ( & V_28 -> V_299 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_201 ( struct V_301 * V_33 , struct V_25 * V_25 )
{
long V_302 ;
V_302 = F_202 ( & V_33 -> V_80 ) ;
V_302 -= V_25 -> V_303 ;
V_302 += V_25 -> V_70 . V_4 ;
return V_302 ;
}
static long F_203 ( struct V_25 * V_25 , struct V_301 * V_33 )
{
long V_302 , V_70 , V_304 ;
V_302 = F_201 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_304 = ( V_33 -> V_304 * V_70 ) ;
if ( V_302 )
V_304 /= V_302 ;
if ( V_304 < V_305 )
V_304 = V_305 ;
if ( V_304 > V_33 -> V_304 )
V_304 = V_33 -> V_304 ;
return V_304 ;
}
static inline long F_203 ( struct V_25 * V_25 , struct V_301 * V_33 )
{
return V_33 -> V_304 ;
}
static void F_204 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_74 ) {
if ( V_25 -> V_45 == V_28 )
F_62 ( V_25 ) ;
F_199 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_74 )
F_196 ( V_25 , V_28 ) ;
}
static void F_205 ( struct V_25 * V_25 )
{
struct V_301 * V_33 ;
struct V_27 * V_28 ;
long V_304 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_206 ( V_25 ) )
return;
#ifndef F_197
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_304 ) )
return;
#endif
V_304 = F_203 ( V_25 , V_33 ) ;
F_204 ( F_23 ( V_28 ) , V_28 , V_304 ) ;
}
static inline void F_205 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_207 ( T_2 V_306 , T_2 V_307 )
{
unsigned int V_308 ;
if ( ! V_307 )
return V_306 ;
else if ( F_13 ( V_307 > V_309 * 63 ) )
return 0 ;
V_308 = V_307 ;
if ( F_13 ( V_308 >= V_309 ) ) {
V_306 >>= V_308 / V_309 ;
V_308 %= V_309 ;
}
V_306 = F_15 ( V_306 , V_310 [ V_308 ] , 32 ) ;
return V_306 ;
}
static V_23 F_208 ( T_2 V_307 )
{
V_23 V_311 = 0 ;
if ( F_11 ( V_307 <= V_309 ) )
return V_312 [ V_307 ] ;
else if ( F_13 ( V_307 >= V_313 ) )
return V_82 ;
do {
V_311 /= 2 ;
V_311 += V_312 [ V_309 ] ;
V_307 -= V_309 ;
} while ( V_307 > V_309 );
V_311 = F_207 ( V_311 , V_307 ) ;
return V_311 + V_312 [ V_307 ] ;
}
static T_10 int
F_209 ( T_2 V_86 , int V_152 , struct V_75 * V_76 ,
unsigned long V_4 , int V_314 , struct V_25 * V_25 )
{
T_2 V_42 , V_315 ;
V_23 V_311 ;
int V_316 , V_317 = 0 ;
unsigned long V_318 = F_210 ( NULL , V_152 ) ;
V_42 = V_86 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_86 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_86 ;
V_316 = V_76 -> V_79 ;
if ( V_42 + V_316 >= 1024 ) {
V_317 = 1 ;
V_76 -> V_79 = 0 ;
V_316 = 1024 - V_316 ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_316 ;
if ( V_25 )
V_25 -> V_319 += V_4 * V_316 ;
}
if ( V_314 )
V_76 -> V_85 += V_316 * V_318 >> V_320 ;
V_42 -= V_316 ;
V_315 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_207 ( V_76 -> V_81 , V_315 + 1 ) ;
if ( V_25 ) {
V_25 -> V_319 =
F_207 ( V_25 -> V_319 , V_315 + 1 ) ;
}
V_76 -> V_85 = F_207 ( ( T_2 ) ( V_76 -> V_85 ) , V_315 + 1 ) ;
V_311 = F_208 ( V_315 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_311 ;
if ( V_25 )
V_25 -> V_319 += V_4 * V_311 ;
}
if ( V_314 )
V_76 -> V_85 += V_311 * V_318 >> V_320 ;
}
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_42 ;
if ( V_25 )
V_25 -> V_319 += V_4 * V_42 ;
}
if ( V_314 )
V_76 -> V_85 += V_42 * V_318 >> V_320 ;
V_76 -> V_79 += V_42 ;
if ( V_317 ) {
V_76 -> V_80 = F_211 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_321 =
F_211 ( V_25 -> V_319 , V_82 ) ;
}
V_76 -> V_83 = ( V_76 -> V_85 << V_322 ) / V_82 ;
}
return V_317 ;
}
static inline void F_212 ( struct V_25 * V_25 , int V_323 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_303 ;
if ( V_323 || abs ( V_42 ) > V_25 -> V_303 / 64 ) {
F_213 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_303 = V_25 -> V_77 . V_80 ;
}
}
static inline void F_212 ( struct V_25 * V_25 , int V_323 ) {}
static inline int F_214 ( T_2 V_86 , struct V_25 * V_25 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_317 , V_324 = 0 ;
if ( F_202 ( & V_25 -> V_325 ) ) {
long V_326 = F_215 ( & V_25 -> V_325 , 0 ) ;
V_76 -> V_80 = F_85 ( long , V_76 -> V_80 - V_326 , 0 ) ;
V_76 -> V_81 = F_85 ( T_3 , V_76 -> V_81 - V_326 * V_82 , 0 ) ;
V_324 = 1 ;
}
if ( F_202 ( & V_25 -> V_327 ) ) {
long V_326 = F_215 ( & V_25 -> V_327 , 0 ) ;
V_76 -> V_83 = F_85 ( long , V_76 -> V_83 - V_326 , 0 ) ;
V_76 -> V_85 = F_85 ( V_328 , V_76 -> V_85 -
( ( V_326 * V_82 ) >> V_322 ) , 0 ) ;
}
V_317 = F_209 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_70 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_329 = V_76 -> V_78 ;
#endif
return V_317 || V_324 ;
}
static inline void F_216 ( struct V_27 * V_28 , int V_330 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
int V_152 = F_26 ( F_16 ( V_25 ) ) ;
T_2 V_86 = F_217 ( V_25 ) ;
F_209 ( V_86 , V_152 , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) , V_25 -> V_45 == V_28 , NULL ) ;
if ( F_214 ( V_86 , V_25 ) && V_330 )
F_212 ( V_25 , 0 ) ;
}
static inline void
F_218 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_86 = F_217 ( V_25 ) ;
int V_259 = 0 , V_317 ;
if ( V_76 -> V_78 == 0 ) {
V_76 -> V_78 = V_86 ;
V_259 = 1 ;
}
else {
F_209 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_317 = F_214 ( V_86 , V_25 ) ;
V_25 -> V_321 += V_76 -> V_80 ;
V_25 -> V_319 += V_76 -> V_81 ;
if ( V_259 ) {
V_25 -> V_77 . V_80 += V_76 -> V_80 ;
V_25 -> V_77 . V_81 += V_76 -> V_81 ;
V_25 -> V_77 . V_83 += V_76 -> V_83 ;
V_25 -> V_77 . V_85 += V_76 -> V_85 ;
}
if ( V_317 || V_259 )
F_212 ( V_25 , 0 ) ;
}
static inline void
F_219 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_216 ( V_28 , 1 ) ;
V_25 -> V_321 =
F_85 ( long , V_25 -> V_321 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_319 =
F_85 ( T_3 , V_25 -> V_319 - V_28 -> V_77 . V_81 , 0 ) ;
}
void F_220 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_78 ;
#ifndef F_40
T_2 V_331 ;
do {
V_331 = V_25 -> V_329 ;
F_221 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_331 );
#else
V_78 = V_25 -> V_77 . V_78 ;
#endif
F_209 ( V_78 , F_26 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_213 ( V_28 -> V_77 . V_80 , & V_25 -> V_325 ) ;
F_213 ( V_28 -> V_77 . V_83 , & V_25 -> V_327 ) ;
}
void F_222 ( struct V_24 * V_332 )
{
}
void F_223 ( struct V_24 * V_332 )
{
}
static inline unsigned long F_224 ( struct V_25 * V_25 )
{
return V_25 -> V_321 ;
}
static inline unsigned long F_225 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline void F_216 ( struct V_27 * V_28 , int V_330 ) {}
static inline void
F_218 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_219 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_220 ( struct V_27 * V_28 ) {}
static inline int F_226 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_227 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_76
struct V_26 * V_247 = NULL ;
if ( F_20 ( V_28 ) )
V_247 = F_17 ( V_28 ) ;
if ( V_28 -> V_88 . V_333 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_333 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_334 ) )
V_28 -> V_88 . V_334 = V_42 ;
V_28 -> V_88 . V_333 = 0 ;
V_28 -> V_88 . V_335 += V_42 ;
if ( V_247 ) {
F_228 ( V_247 , V_42 >> 10 , 1 ) ;
F_229 ( V_247 , V_42 ) ;
}
}
if ( V_28 -> V_88 . V_336 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_336 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_337 ) )
V_28 -> V_88 . V_337 = V_42 ;
V_28 -> V_88 . V_336 = 0 ;
V_28 -> V_88 . V_335 += V_42 ;
if ( V_247 ) {
if ( V_247 -> V_338 ) {
V_28 -> V_88 . V_339 += V_42 ;
V_28 -> V_88 . V_340 ++ ;
F_230 ( V_247 , V_42 ) ;
}
F_231 ( V_247 , V_42 ) ;
if ( F_13 ( V_341 == V_342 ) ) {
F_232 ( V_342 ,
( void * ) F_233 ( V_247 ) ,
V_42 >> 20 ) ;
}
F_228 ( V_247 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_234 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_343 = V_28 -> V_41 - V_25 -> F_36 ;
if ( V_343 < 0 )
V_343 = - V_343 ;
if ( V_343 > 3 * V_68 )
F_235 ( V_25 , V_344 ) ;
#endif
}
static void
F_236 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_345 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_345 && F_237 ( V_346 ) )
V_41 += F_60 ( V_25 , V_28 ) ;
if ( ! V_345 ) {
unsigned long V_347 = V_68 ;
if ( F_237 ( V_348 ) )
V_347 >>= 1 ;
V_41 -= V_347 ;
}
V_28 -> V_41 = F_35 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_238 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_183 )
{
if ( ! ( V_183 & V_349 ) || ( V_183 & V_350 ) )
V_28 -> V_41 += V_25 -> F_36 ;
F_62 ( V_25 ) ;
F_218 ( V_25 , V_28 ) ;
F_196 ( V_25 , V_28 ) ;
F_205 ( V_25 ) ;
if ( V_183 & V_349 ) {
F_236 ( V_25 , V_28 , 0 ) ;
F_227 ( V_25 , V_28 ) ;
}
F_74 ( V_25 , V_28 ) ;
F_234 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_42 ( V_25 , V_28 ) ;
V_28 -> V_74 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_239 ( V_25 ) ;
}
}
static void F_240 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_241 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_242 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_351 != V_28 )
break;
V_25 -> V_351 = NULL ;
}
}
static void F_243 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_240 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_241 ( V_28 ) ;
if ( V_25 -> V_351 == V_28 )
F_242 ( V_28 ) ;
}
static void
F_244 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_183 )
{
F_62 ( V_25 ) ;
F_219 ( V_25 , V_28 ) ;
F_78 ( V_25 , V_28 ) ;
if ( V_183 & V_352 ) {
#ifdef F_76
if ( F_20 ( V_28 ) ) {
struct V_26 * V_247 = F_17 ( V_28 ) ;
if ( V_247 -> V_353 & V_354 )
V_28 -> V_88 . V_333 = F_73 ( F_16 ( V_25 ) ) ;
if ( V_247 -> V_353 & V_355 )
V_28 -> V_88 . V_336 = F_73 ( F_16 ( V_25 ) ) ;
}
#endif
}
F_243 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_45 ( V_25 , V_28 ) ;
V_28 -> V_74 = 0 ;
F_199 ( V_25 , V_28 ) ;
if ( ! ( V_183 & V_352 ) )
V_28 -> V_41 -= V_25 -> F_36 ;
F_245 ( V_25 ) ;
F_38 ( V_25 ) ;
F_205 ( V_25 ) ;
}
static void
F_246 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_356 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_356 = F_58 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_90 - V_45 -> V_357 ;
if ( V_19 > V_356 ) {
F_247 ( F_16 ( V_25 ) ) ;
F_243 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_48 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_356 )
F_247 ( F_16 ( V_25 ) ) ;
}
static void
F_248 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_74 ) {
F_75 ( V_25 , V_28 ) ;
F_45 ( V_25 , V_28 ) ;
F_216 ( V_28 , 1 ) ;
}
F_79 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_76
if ( F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_88 . V_358 = F_65 ( V_28 -> V_88 . V_358 ,
V_28 -> V_90 - V_28 -> V_357 ) ;
}
#endif
V_28 -> V_357 = V_28 -> V_90 ;
}
static struct V_27 *
F_249 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_48 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_37 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_351 == V_28 ) {
struct V_27 * V_359 ;
if ( V_28 == V_45 ) {
V_359 = F_48 ( V_25 ) ;
} else {
V_359 = F_49 ( V_28 ) ;
if ( ! V_359 || ( V_45 && F_37 ( V_45 , V_359 ) ) )
V_359 = V_45 ;
}
if ( V_359 && F_250 ( V_359 , V_57 ) < 1 )
V_28 = V_359 ;
}
if ( V_25 -> V_59 && F_250 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_250 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_243 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_251 ( struct V_25 * V_25 , struct V_27 * V_360 )
{
if ( V_360 -> V_74 )
F_62 ( V_25 ) ;
F_252 ( V_25 ) ;
F_234 ( V_25 , V_360 ) ;
if ( V_360 -> V_74 ) {
F_72 ( V_25 , V_360 ) ;
F_42 ( V_25 , V_360 ) ;
F_216 ( V_360 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_253 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_361 )
{
F_62 ( V_25 ) ;
F_216 ( V_45 , 1 ) ;
F_205 ( V_25 ) ;
#ifdef F_254
if ( V_361 ) {
F_247 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_237 ( V_362 ) &&
F_255 ( & F_16 ( V_25 ) -> V_363 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_246 ( V_25 , V_45 ) ;
}
static inline bool F_256 ( void )
{
return F_257 ( & V_364 ) ;
}
void F_258 ( void )
{
F_259 ( & V_364 ) ;
}
void F_260 ( void )
{
F_261 ( & V_364 ) ;
}
static bool F_256 ( void )
{
return true ;
}
void F_258 ( void ) {}
void F_260 ( void ) {}
static inline T_2 F_262 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_263 ( void )
{
return ( T_2 ) V_365 * V_366 ;
}
void F_264 ( struct V_367 * V_368 )
{
T_2 V_86 ;
if ( V_368 -> V_369 == V_370 )
return;
V_86 = F_265 ( F_266 () ) ;
V_368 -> V_217 = V_368 -> V_369 ;
V_368 -> V_371 = V_86 + F_267 ( V_368 -> V_216 ) ;
}
static inline struct V_367 * F_268 ( struct V_301 * V_33 )
{
return & V_33 -> V_367 ;
}
static inline T_2 F_217 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_372 ) )
return V_25 -> V_373 ;
return F_63 ( F_16 ( V_25 ) ) - V_25 -> V_374 ;
}
static int F_269 ( struct V_25 * V_25 )
{
struct V_301 * V_33 = V_25 -> V_33 ;
struct V_367 * V_368 = F_268 ( V_33 ) ;
T_2 V_375 = 0 , V_376 , V_377 ;
V_376 = F_263 () - V_25 -> V_378 ;
F_270 ( & V_368 -> V_182 ) ;
if ( V_368 -> V_369 == V_370 )
V_375 = V_376 ;
else {
F_271 ( V_368 ) ;
if ( V_368 -> V_217 > 0 ) {
V_375 = F_141 ( V_368 -> V_217 , V_376 ) ;
V_368 -> V_217 -= V_375 ;
V_368 -> V_379 = 0 ;
}
}
V_377 = V_368 -> V_371 ;
F_272 ( & V_368 -> V_182 ) ;
V_25 -> V_378 += V_375 ;
if ( ( T_3 ) ( V_377 - V_25 -> V_371 ) > 0 )
V_25 -> V_371 = V_377 ;
return V_25 -> V_378 > 0 ;
}
static void F_273 ( struct V_25 * V_25 )
{
struct V_367 * V_368 = F_268 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_73 ( F_16 ( V_25 ) ) - V_25 -> V_371 ) < 0 ) )
return;
if ( V_25 -> V_378 < 0 )
return;
if ( V_25 -> V_371 != V_368 -> V_371 ) {
V_25 -> V_371 += V_283 ;
} else {
V_25 -> V_378 = 0 ;
}
}
static void F_274 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_378 -= V_19 ;
F_273 ( V_25 ) ;
if ( F_11 ( V_25 -> V_378 > 0 ) )
return;
if ( ! F_269 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_247 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_70 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_256 () || ! V_25 -> V_380 )
return;
F_274 ( V_25 , V_19 ) ;
}
static inline int F_275 ( struct V_25 * V_25 )
{
return F_256 () && V_25 -> V_381 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return F_256 () && V_25 -> V_372 ;
}
static inline int F_276 ( struct V_301 * V_33 ,
int V_178 , int V_382 )
{
struct V_25 * V_383 , * V_384 ;
V_383 = V_33 -> V_25 [ V_178 ] ;
V_384 = V_33 -> V_25 [ V_382 ] ;
return F_206 ( V_383 ) ||
F_206 ( V_384 ) ;
}
static int F_277 ( struct V_301 * V_33 , void * V_385 )
{
struct V_24 * V_24 = V_385 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_372 -- ;
#ifdef F_197
if ( ! V_25 -> V_372 ) {
V_25 -> V_374 += F_63 ( V_24 ) -
V_25 -> V_373 ;
}
#endif
return 0 ;
}
static int F_278 ( struct V_301 * V_33 , void * V_385 )
{
struct V_24 * V_24 = V_385 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_372 )
V_25 -> V_373 = F_63 ( V_24 ) ;
V_25 -> V_372 ++ ;
return 0 ;
}
static void F_279 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_367 * V_368 = F_268 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_386 , V_387 = 1 ;
bool V_388 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_120 () ;
F_280 ( V_25 -> V_33 , F_278 , V_389 , ( void * ) V_24 ) ;
F_128 () ;
V_386 = V_25 -> V_390 ;
F_59 (se) {
struct V_25 * V_391 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_74 )
break;
if ( V_387 )
F_244 ( V_391 , V_28 , V_352 ) ;
V_391 -> V_390 -= V_386 ;
if ( V_391 -> V_70 . V_4 )
V_387 = 0 ;
}
if ( ! V_28 )
F_281 ( V_24 , V_386 ) ;
V_25 -> V_381 = 1 ;
V_25 -> V_392 = F_73 ( V_24 ) ;
F_270 ( & V_368 -> V_182 ) ;
V_388 = F_282 ( & V_368 -> V_393 ) ;
F_27 ( & V_25 -> V_394 , & V_368 -> V_393 ) ;
if ( V_388 )
F_271 ( V_368 ) ;
F_272 ( & V_368 -> V_182 ) ;
}
void F_283 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_367 * V_368 = F_268 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_395 = 1 ;
long V_386 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_381 = 0 ;
F_284 ( V_24 ) ;
F_270 ( & V_368 -> V_182 ) ;
V_368 -> V_396 += F_73 ( V_24 ) - V_25 -> V_392 ;
F_30 ( & V_25 -> V_394 ) ;
F_272 ( & V_368 -> V_182 ) ;
F_280 ( V_25 -> V_33 , V_389 , F_277 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_386 = V_25 -> V_390 ;
F_59 (se) {
if ( V_28 -> V_74 )
V_395 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_395 )
F_238 ( V_25 , V_28 , V_349 ) ;
V_25 -> V_390 += V_386 ;
if ( F_275 ( V_25 ) )
break;
}
if ( ! V_28 )
F_285 ( V_24 , V_386 ) ;
if ( V_24 -> V_45 == V_24 -> V_379 && V_24 -> V_40 . V_72 )
F_247 ( V_24 ) ;
}
static T_2 F_286 ( struct V_367 * V_368 ,
T_2 V_397 , T_2 V_377 )
{
struct V_25 * V_25 ;
T_2 V_217 ;
T_2 V_398 = V_397 ;
F_120 () ;
F_287 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_270 ( & V_24 -> V_182 ) ;
if ( ! F_275 ( V_25 ) )
goto V_58;
V_217 = - V_25 -> V_378 + 1 ;
if ( V_217 > V_397 )
V_217 = V_397 ;
V_397 -= V_217 ;
V_25 -> V_378 += V_217 ;
V_25 -> V_371 = V_377 ;
if ( V_25 -> V_378 > 0 )
F_283 ( V_25 ) ;
V_58:
F_272 ( & V_24 -> V_182 ) ;
if ( ! V_397 )
break;
}
F_128 () ;
return V_398 - V_397 ;
}
static int F_288 ( struct V_367 * V_368 , int V_399 )
{
T_2 V_217 , V_371 ;
int V_381 ;
if ( V_368 -> V_369 == V_370 )
goto V_400;
V_381 = ! F_282 ( & V_368 -> V_393 ) ;
V_368 -> V_401 += V_399 ;
if ( V_368 -> V_379 && ! V_381 )
goto V_400;
F_264 ( V_368 ) ;
if ( ! V_381 ) {
V_368 -> V_379 = 1 ;
return 0 ;
}
V_368 -> V_402 += V_399 ;
V_371 = V_368 -> V_371 ;
while ( V_381 && V_368 -> V_217 > 0 ) {
V_217 = V_368 -> V_217 ;
F_272 ( & V_368 -> V_182 ) ;
V_217 = F_286 ( V_368 , V_217 ,
V_371 ) ;
F_270 ( & V_368 -> V_182 ) ;
V_381 = ! F_282 ( & V_368 -> V_393 ) ;
V_368 -> V_217 -= F_141 ( V_217 , V_368 -> V_217 ) ;
}
V_368 -> V_379 = 0 ;
return 0 ;
V_400:
return 1 ;
}
static int F_289 ( struct V_367 * V_368 , T_2 V_403 )
{
struct V_404 * V_405 = & V_368 -> V_406 ;
T_2 V_397 ;
if ( F_290 ( V_405 ) )
return 1 ;
V_397 = F_267 ( F_291 ( V_405 ) ) ;
if ( V_397 < V_403 )
return 1 ;
return 0 ;
}
static void F_292 ( struct V_367 * V_368 )
{
T_2 V_407 = V_408 + V_409 ;
if ( F_289 ( V_368 , V_407 ) )
return;
F_293 ( & V_368 -> V_410 ,
F_294 ( V_408 ) ,
V_411 ) ;
}
static void F_295 ( struct V_25 * V_25 )
{
struct V_367 * V_368 = F_268 ( V_25 -> V_33 ) ;
T_3 V_412 = V_25 -> V_378 - V_413 ;
if ( V_412 <= 0 )
return;
F_270 ( & V_368 -> V_182 ) ;
if ( V_368 -> V_369 != V_370 &&
V_25 -> V_371 == V_368 -> V_371 ) {
V_368 -> V_217 += V_412 ;
if ( V_368 -> V_217 > F_263 () &&
! F_282 ( & V_368 -> V_393 ) )
F_292 ( V_368 ) ;
}
F_272 ( & V_368 -> V_182 ) ;
V_25 -> V_378 -= V_412 ;
}
static T_10 void F_245 ( struct V_25 * V_25 )
{
if ( ! F_256 () )
return;
if ( ! V_25 -> V_380 || V_25 -> V_72 )
return;
F_295 ( V_25 ) ;
}
static void F_296 ( struct V_367 * V_368 )
{
T_2 V_217 = 0 , V_73 = F_263 () ;
T_2 V_377 ;
F_270 ( & V_368 -> V_182 ) ;
if ( F_289 ( V_368 , V_409 ) ) {
F_272 ( & V_368 -> V_182 ) ;
return;
}
if ( V_368 -> V_369 != V_370 && V_368 -> V_217 > V_73 )
V_217 = V_368 -> V_217 ;
V_377 = V_368 -> V_371 ;
F_272 ( & V_368 -> V_182 ) ;
if ( ! V_217 )
return;
V_217 = F_286 ( V_368 , V_217 , V_377 ) ;
F_270 ( & V_368 -> V_182 ) ;
if ( V_377 == V_368 -> V_371 )
V_368 -> V_217 -= F_141 ( V_217 , V_368 -> V_217 ) ;
F_272 ( & V_368 -> V_182 ) ;
}
static void F_239 ( struct V_25 * V_25 )
{
if ( ! F_256 () )
return;
if ( ! V_25 -> V_380 || V_25 -> V_45 )
return;
if ( F_275 ( V_25 ) )
return;
F_70 ( V_25 , 0 ) ;
if ( V_25 -> V_378 <= 0 )
F_279 ( V_25 ) ;
}
static bool F_252 ( struct V_25 * V_25 )
{
if ( ! F_256 () )
return false ;
if ( F_11 ( ! V_25 -> V_380 || V_25 -> V_378 > 0 ) )
return false ;
if ( F_275 ( V_25 ) )
return true ;
F_279 ( V_25 ) ;
return true ;
}
static enum V_414 F_297 ( struct V_404 * V_415 )
{
struct V_367 * V_368 =
F_21 ( V_415 , struct V_367 , V_410 ) ;
F_296 ( V_368 ) ;
return V_416 ;
}
static enum V_414 F_298 ( struct V_404 * V_415 )
{
struct V_367 * V_368 =
F_21 ( V_415 , struct V_367 , V_406 ) ;
int V_399 ;
int V_379 = 0 ;
F_270 ( & V_368 -> V_182 ) ;
for (; ; ) {
V_399 = F_299 ( V_415 , V_368 -> V_216 ) ;
if ( ! V_399 )
break;
V_379 = F_288 ( V_368 , V_399 ) ;
}
if ( V_379 )
V_368 -> V_417 = 0 ;
F_272 ( & V_368 -> V_182 ) ;
return V_379 ? V_416 : V_418 ;
}
void F_300 ( struct V_367 * V_368 )
{
F_301 ( & V_368 -> V_182 ) ;
V_368 -> V_217 = 0 ;
V_368 -> V_369 = V_370 ;
V_368 -> V_216 = F_294 ( F_262 () ) ;
F_302 ( & V_368 -> V_393 ) ;
F_303 ( & V_368 -> V_406 , V_419 , V_420 ) ;
V_368 -> V_406 . V_421 = F_298 ;
F_303 ( & V_368 -> V_410 , V_419 , V_411 ) ;
V_368 -> V_410 . V_421 = F_297 ;
}
static void F_304 ( struct V_25 * V_25 )
{
V_25 -> V_380 = 0 ;
F_302 ( & V_25 -> V_394 ) ;
}
void F_271 ( struct V_367 * V_368 )
{
F_305 ( & V_368 -> V_182 ) ;
if ( ! V_368 -> V_417 ) {
V_368 -> V_417 = 1 ;
F_299 ( & V_368 -> V_406 , V_368 -> V_216 ) ;
F_306 ( & V_368 -> V_406 , V_420 ) ;
}
}
static void F_307 ( struct V_367 * V_368 )
{
if ( ! V_368 -> V_393 . V_58 )
return;
F_308 ( & V_368 -> V_406 ) ;
F_308 ( & V_368 -> V_410 ) ;
}
static void T_11 F_309 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_310 (rq, cfs_rq) {
struct V_367 * V_368 = & V_25 -> V_33 -> V_367 ;
F_270 ( & V_368 -> V_182 ) ;
V_25 -> V_380 = V_368 -> V_369 != V_370 ;
F_272 ( & V_368 -> V_182 ) ;
}
}
static void T_11 F_311 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_310 (rq, cfs_rq) {
if ( ! V_25 -> V_380 )
continue;
V_25 -> V_378 = 1 ;
V_25 -> V_380 = 0 ;
if ( F_275 ( V_25 ) )
F_283 ( V_25 ) ;
}
}
static inline T_2 F_217 ( struct V_25 * V_25 )
{
return F_63 ( F_16 ( V_25 ) ) ;
}
static void F_70 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_252 ( struct V_25 * V_25 ) { return false ; }
static void F_239 ( struct V_25 * V_25 ) {}
static T_10 void F_245 ( struct V_25 * V_25 ) {}
static inline int F_275 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_276 ( struct V_301 * V_33 ,
int V_178 , int V_382 )
{
return 0 ;
}
void F_300 ( struct V_367 * V_368 ) {}
static void F_304 ( struct V_25 * V_25 ) {}
static inline struct V_367 * F_268 ( struct V_301 * V_33 )
{
return NULL ;
}
static inline void F_307 ( struct V_367 * V_368 ) {}
static inline void F_309 ( struct V_24 * V_24 ) {}
static inline void F_311 ( struct V_24 * V_24 ) {}
static void F_312 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_313 ( F_34 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_73 = F_58 ( V_25 , V_28 ) ;
T_2 V_422 = V_28 -> V_90 - V_28 -> V_357 ;
T_3 V_42 = V_73 - V_422 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_247 ( V_24 ) ;
return;
}
F_314 ( V_24 , V_42 ) ;
}
}
static void F_315 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_316 ( V_24 ) || V_45 -> V_423 != & V_424 )
return;
if ( F_23 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_312 ( V_24 , V_45 ) ;
}
static inline void
F_312 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_315 ( struct V_24 * V_24 )
{
}
static void
F_317 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_183 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_59 (se) {
if ( V_28 -> V_74 )
break;
V_25 = F_23 ( V_28 ) ;
F_238 ( V_25 , V_28 , V_183 ) ;
if ( F_275 ( V_25 ) )
break;
V_25 -> V_390 ++ ;
V_183 = V_349 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_390 ++ ;
if ( F_275 ( V_25 ) )
break;
F_216 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_285 ( V_24 , 1 ) ;
F_315 ( V_24 ) ;
}
static void F_318 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_183 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_425 = V_183 & V_352 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_244 ( V_25 , V_28 , V_183 ) ;
if ( F_275 ( V_25 ) )
break;
V_25 -> V_390 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_425 && F_32 ( V_28 ) )
F_319 ( F_32 ( V_28 ) ) ;
V_28 = F_32 ( V_28 ) ;
break;
}
V_183 |= V_352 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_390 -- ;
if ( F_275 ( V_25 ) )
break;
F_216 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_281 ( V_24 , 1 ) ;
F_315 ( V_24 ) ;
}
static unsigned long
F_320 ( unsigned long V_70 , unsigned long V_426 , int V_427 )
{
int V_428 = 0 ;
if ( ! V_426 )
return V_70 ;
if ( V_426 >= V_429 [ V_427 ] )
return 0 ;
if ( V_427 == 1 )
return V_70 >> V_426 ;
while ( V_426 ) {
if ( V_426 % 2 )
V_70 = ( V_70 * V_430 [ V_427 ] [ V_428 ] ) >> V_431 ;
V_426 >>= 1 ;
V_428 ++ ;
}
return V_70 ;
}
static void F_321 ( struct V_24 * V_332 , unsigned long V_432 ,
unsigned long V_433 )
{
int V_249 , V_434 ;
V_332 -> V_435 ++ ;
V_332 -> V_436 [ 0 ] = V_432 ;
for ( V_249 = 1 , V_434 = 2 ; V_249 < V_437 ; V_249 ++ , V_434 += V_434 ) {
unsigned long V_438 , V_439 ;
V_438 = V_332 -> V_436 [ V_249 ] ;
V_438 = F_320 ( V_438 , V_433 - 1 , V_249 ) ;
V_439 = V_432 ;
if ( V_439 > V_438 )
V_439 += V_434 - 1 ;
V_332 -> V_436 [ V_249 ] = ( V_438 * ( V_434 - 1 ) + V_439 ) >> V_249 ;
}
F_322 ( V_332 ) ;
}
static unsigned long F_111 ( const int V_152 )
{
return F_224 ( & F_110 ( V_152 ) -> V_40 ) ;
}
static void F_323 ( struct V_24 * V_332 )
{
unsigned long V_440 = F_84 ( V_201 ) ;
unsigned long V_70 = F_111 ( F_26 ( V_332 ) ) ;
unsigned long V_433 ;
if ( V_70 || V_440 == V_332 -> V_441 )
return;
V_433 = V_440 - V_332 -> V_441 ;
V_332 -> V_441 = V_440 ;
F_321 ( V_332 , V_70 , V_433 ) ;
}
void F_324 ( void )
{
struct V_24 * V_332 = V_332 () ;
unsigned long V_440 = F_84 ( V_201 ) ;
unsigned long V_433 ;
if ( V_440 == V_332 -> V_441 )
return;
F_270 ( & V_332 -> V_182 ) ;
V_433 = V_440 - V_332 -> V_441 ;
if ( V_433 ) {
V_332 -> V_441 = V_440 ;
F_321 ( V_332 , 0 , V_433 ) ;
}
F_272 ( & V_332 -> V_182 ) ;
}
void F_325 ( struct V_24 * V_332 )
{
unsigned long V_70 = F_111 ( F_26 ( V_332 ) ) ;
V_332 -> V_441 = V_201 ;
F_321 ( V_332 , V_70 , 1 ) ;
}
static unsigned long F_326 ( int V_152 , int type )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_442 = F_111 ( V_152 ) ;
if ( type == 0 || ! F_237 ( V_443 ) )
return V_442 ;
return F_141 ( V_24 -> V_436 [ type - 1 ] , V_442 ) ;
}
static unsigned long F_327 ( int V_152 , int type )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_442 = F_111 ( V_152 ) ;
if ( type == 0 || ! F_237 ( V_443 ) )
return V_442 ;
return F_65 ( V_24 -> V_436 [ type - 1 ] , V_442 ) ;
}
static unsigned long F_112 ( int V_152 )
{
return F_110 ( V_152 ) -> V_444 ;
}
static unsigned long F_328 ( int V_152 )
{
return F_110 ( V_152 ) -> V_445 ;
}
static unsigned long F_329 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_72 = F_84 ( V_24 -> V_40 . V_390 ) ;
unsigned long V_80 = F_111 ( V_152 ) ;
if ( V_72 )
return V_80 / V_72 ;
return 0 ;
}
static void F_330 ( struct V_26 * V_29 )
{
if ( F_178 ( V_201 , V_146 -> V_446 + V_199 ) ) {
V_146 -> V_447 >>= 1 ;
V_146 -> V_446 = V_201 ;
}
if ( V_146 -> V_448 != V_29 ) {
V_146 -> V_448 = V_29 ;
V_146 -> V_447 ++ ;
}
}
static void F_331 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_221 () ;
F_36 = V_25 -> F_36 ;
} while ( F_36 != V_48 );
#else
F_36 = V_25 -> F_36 ;
#endif
V_28 -> V_41 -= F_36 ;
F_330 ( V_29 ) ;
}
static long F_332 ( struct V_301 * V_33 , int V_152 , long V_449 , long V_450 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_152 ] ;
if ( ! V_33 -> V_34 )
return V_449 ;
F_59 (se) {
long V_7 , V_451 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_451 = V_450 + F_201 ( V_33 , V_28 -> V_31 ) ;
V_7 = F_225 ( V_28 -> V_31 ) + V_449 ;
if ( V_451 > 0 && V_7 < V_451 )
V_449 = ( V_7 * ( long ) V_33 -> V_304 ) / V_451 ;
else
V_449 = V_33 -> V_304 ;
if ( V_449 < V_305 )
V_449 = V_305 ;
V_449 -= V_28 -> V_77 . V_80 ;
V_450 = 0 ;
}
return V_449 ;
}
static long F_332 ( struct V_301 * V_33 , int V_152 , long V_449 , long V_450 )
{
return V_449 ;
}
static int F_333 ( struct V_26 * V_29 )
{
unsigned int V_452 = V_146 -> V_447 ;
unsigned int V_453 = V_29 -> V_447 ;
int V_9 = F_334 ( V_454 ) ;
if ( V_452 < V_453 )
F_118 ( V_452 , V_453 ) ;
if ( V_453 < V_9 || V_452 < V_453 * V_9 )
return 0 ;
return 1 ;
}
static int F_335 ( struct V_190 * V_191 , struct V_26 * V_29 , int V_455 )
{
T_3 V_432 , V_70 ;
T_3 V_456 , V_457 ;
int V_427 , V_458 , V_459 ;
struct V_301 * V_33 ;
unsigned long V_4 ;
int V_460 ;
V_427 = V_191 -> V_461 ;
V_458 = F_266 () ;
V_459 = F_132 ( V_29 ) ;
V_70 = F_326 ( V_459 , V_427 ) ;
V_432 = F_327 ( V_458 , V_427 ) ;
if ( V_455 ) {
V_33 = V_301 ( V_146 ) ;
V_4 = V_146 -> V_28 . V_77 . V_80 ;
V_432 += F_332 ( V_33 , V_458 , - V_4 , - V_4 ) ;
V_70 += F_332 ( V_33 , V_459 , 0 , - V_4 ) ;
}
V_33 = V_301 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_456 = 100 ;
V_456 *= F_112 ( V_459 ) ;
V_457 = 100 + ( V_191 -> V_174 - 100 ) / 2 ;
V_457 *= F_112 ( V_458 ) ;
if ( V_432 > 0 ) {
V_456 *= V_432 +
F_332 ( V_33 , V_458 , V_4 , V_4 ) ;
V_457 *= V_70 + F_332 ( V_33 , V_459 , 0 , V_4 ) ;
}
V_460 = V_456 <= V_457 ;
F_235 ( V_29 , V_28 . V_88 . V_462 ) ;
if ( ! V_460 )
return 0 ;
F_235 ( V_191 , V_463 ) ;
F_235 ( V_29 , V_28 . V_88 . V_464 ) ;
return 1 ;
}
static struct V_465 *
F_336 ( struct V_190 * V_191 , struct V_26 * V_29 ,
int V_458 , int V_466 )
{
struct V_465 * V_467 = NULL , * V_124 = V_191 -> V_468 ;
unsigned long V_469 = V_470 , V_432 = 0 ;
int V_471 = V_191 -> V_472 ;
int V_473 = 100 + ( V_191 -> V_174 - 100 ) / 2 ;
if ( V_466 & V_474 )
V_471 = V_191 -> V_461 ;
do {
unsigned long V_70 , V_475 ;
int V_476 ;
int V_249 ;
if ( ! F_337 ( F_338 ( V_124 ) ,
F_125 ( V_29 ) ) )
continue;
V_476 = F_124 ( V_458 ,
F_338 ( V_124 ) ) ;
V_475 = 0 ;
F_109 (i, sched_group_cpus(group)) {
if ( V_476 )
V_70 = F_326 ( V_249 , V_471 ) ;
else
V_70 = F_327 ( V_249 , V_471 ) ;
V_475 += V_70 ;
}
V_475 = ( V_475 * V_155 ) / V_124 -> V_477 -> V_153 ;
if ( V_476 ) {
V_432 = V_475 ;
} else if ( V_475 < V_469 ) {
V_469 = V_475 ;
V_467 = V_124 ;
}
} while ( V_124 = V_124 -> V_58 , V_124 != V_191 -> V_468 );
if ( ! V_467 || 100 * V_432 < V_473 * V_469 )
return NULL ;
return V_467 ;
}
static int
F_339 ( struct V_465 * V_124 , struct V_26 * V_29 , int V_458 )
{
unsigned long V_70 , V_469 = V_470 ;
unsigned int V_478 = V_479 ;
T_2 V_480 = 0 ;
int V_481 = V_458 ;
int V_482 = - 1 ;
int V_249 ;
F_340 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_341 ( V_249 ) ) {
struct V_24 * V_24 = F_110 ( V_249 ) ;
struct V_483 * V_379 = F_342 ( V_24 ) ;
if ( V_379 && V_379 -> V_484 < V_478 ) {
V_478 = V_379 -> V_484 ;
V_480 = V_24 -> V_485 ;
V_482 = V_249 ;
} else if ( ( ! V_379 || V_379 -> V_484 == V_478 ) &&
V_24 -> V_485 > V_480 ) {
V_480 = V_24 -> V_485 ;
V_482 = V_249 ;
}
} else if ( V_482 == - 1 ) {
V_70 = F_111 ( V_249 ) ;
if ( V_70 < V_469 || ( V_70 == V_469 && V_249 == V_458 ) ) {
V_469 = V_70 ;
V_481 = V_249 ;
}
}
}
return V_482 != - 1 ? V_482 : V_481 ;
}
static int F_127 ( struct V_26 * V_29 , int V_486 )
{
struct V_190 * V_191 ;
struct V_465 * V_487 ;
int V_249 = F_132 ( V_29 ) ;
if ( F_341 ( V_486 ) )
return V_486 ;
if ( V_249 != V_486 && F_343 ( V_249 , V_486 ) && F_341 ( V_249 ) )
return V_249 ;
V_191 = F_133 ( F_134 ( V_488 , V_486 ) ) ;
F_344 (sd) {
V_487 = V_191 -> V_468 ;
do {
if ( ! F_337 ( F_338 ( V_487 ) ,
F_125 ( V_29 ) ) )
goto V_58;
F_109 (i, sched_group_cpus(sg)) {
if ( V_249 == V_486 || ! F_341 ( V_249 ) )
goto V_58;
}
V_486 = F_345 ( F_338 ( V_487 ) ,
F_125 ( V_29 ) ) ;
goto V_489;
V_58:
V_487 = V_487 -> V_58 ;
} while ( V_487 != V_191 -> V_468 );
}
V_489:
return V_486 ;
}
static int F_346 ( int V_152 )
{
unsigned long V_490 = F_110 ( V_152 ) -> V_40 . V_77 . V_83 ;
unsigned long V_153 = F_328 ( V_152 ) ;
if ( V_490 >= V_84 )
return V_153 ;
return ( V_490 * V_153 ) >> V_322 ;
}
static int
F_347 ( struct V_26 * V_29 , int V_459 , int V_466 , int V_491 )
{
struct V_190 * V_492 , * V_493 = NULL , * V_191 = NULL ;
int V_152 = F_266 () ;
int V_494 = V_459 ;
int V_495 = 0 ;
int V_455 = V_491 & V_496 ;
if ( V_466 & V_474 )
V_495 = ! F_333 ( V_29 ) && F_124 ( V_152 , F_125 ( V_29 ) ) ;
F_120 () ;
F_348 (cpu, tmp) {
if ( ! ( V_492 -> V_183 & V_497 ) )
break;
if ( V_495 && ( V_492 -> V_183 & V_498 ) &&
F_124 ( V_459 , F_349 ( V_492 ) ) ) {
V_493 = V_492 ;
break;
}
if ( V_492 -> V_183 & V_466 )
V_191 = V_492 ;
else if ( ! V_495 )
break;
}
if ( V_493 ) {
V_191 = NULL ;
if ( V_152 != V_459 && F_335 ( V_493 , V_29 , V_455 ) )
V_494 = V_152 ;
}
if ( ! V_191 ) {
if ( V_466 & V_474 )
V_494 = F_127 ( V_29 , V_494 ) ;
} else while ( V_191 ) {
struct V_465 * V_124 ;
int V_4 ;
if ( ! ( V_191 -> V_183 & V_466 ) ) {
V_191 = V_191 -> V_499 ;
continue;
}
V_124 = F_336 ( V_191 , V_29 , V_152 , V_466 ) ;
if ( ! V_124 ) {
V_191 = V_191 -> V_499 ;
continue;
}
V_494 = F_339 ( V_124 , V_29 , V_152 ) ;
if ( V_494 == - 1 || V_494 == V_152 ) {
V_191 = V_191 -> V_499 ;
continue;
}
V_152 = V_494 ;
V_4 = V_191 -> V_500 ;
V_191 = NULL ;
F_348 (cpu, tmp) {
if ( V_4 <= V_492 -> V_500 )
break;
if ( V_492 -> V_183 & V_466 )
V_191 = V_492 ;
}
}
F_128 () ;
return V_494 ;
}
static void F_350 ( struct V_26 * V_29 , int V_501 )
{
F_220 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_87 = 0 ;
}
static void F_351 ( struct V_26 * V_29 )
{
F_220 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_352 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_502 = V_503 ;
return F_56 ( V_502 , V_28 ) ;
}
static int
F_250 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_502 , V_504 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_504 <= 0 )
return - 1 ;
V_502 = F_352 ( V_45 , V_28 ) ;
if ( V_504 > V_502 )
return 1 ;
return 0 ;
}
static void F_353 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_505 == V_506 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_319 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_505 == V_506 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_354 ( struct V_27 * V_28 )
{
F_59 (se)
F_23 ( V_28 ) -> V_351 = V_28 ;
}
static void F_355 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_491 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_434 = V_25 -> V_72 >= V_67 ;
int V_507 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_206 ( F_23 ( V_36 ) ) ) )
return;
if ( F_237 ( V_508 ) && V_434 && ! ( V_491 & V_509 ) ) {
F_319 ( V_36 ) ;
V_507 = 1 ;
}
if ( F_356 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_505 == V_506 ) &&
F_11 ( V_29 -> V_505 != V_506 ) )
goto V_510;
if ( F_13 ( V_29 -> V_505 != V_511 ) || ! F_237 ( V_512 ) )
return;
F_33 ( & V_28 , & V_36 ) ;
F_62 ( F_23 ( V_28 ) ) ;
F_168 ( ! V_36 ) ;
if ( F_250 ( V_28 , V_36 ) == 1 ) {
if ( ! V_507 )
F_319 ( V_36 ) ;
goto V_510;
}
return;
V_510:
F_247 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_74 || V_45 == V_24 -> V_379 ) )
return;
if ( F_237 ( V_513 ) && V_434 && F_20 ( V_28 ) )
F_353 ( V_28 ) ;
}
static struct V_26 *
F_357 ( struct V_24 * V_24 , struct V_26 * V_360 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_514 ;
V_515:
#ifdef F_358
if ( ! V_25 -> V_72 )
goto V_379;
if ( V_360 -> V_423 != & V_424 )
goto V_516;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_74 )
F_62 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_252 ( V_25 ) ) )
goto V_516;
}
V_28 = F_249 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_360 != V_29 ) {
struct V_27 * V_36 = & V_360 -> V_28 ;
while ( ! ( V_25 = F_31 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_251 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_32 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_248 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_32 ( V_28 ) ;
}
}
F_251 ( V_25 , V_36 ) ;
F_248 ( V_25 , V_28 ) ;
}
if ( F_316 ( V_24 ) )
F_312 ( V_24 , V_29 ) ;
return V_29 ;
V_516:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_379;
F_359 ( V_24 , V_360 ) ;
do {
V_28 = F_249 ( V_25 , NULL ) ;
F_248 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_316 ( V_24 ) )
F_312 ( V_24 , V_29 ) ;
return V_29 ;
V_379:
F_360 ( & V_24 -> V_182 ) ;
V_514 = F_226 ( V_24 ) ;
F_361 ( & V_24 -> V_182 ) ;
if ( V_514 < 0 )
return V_517 ;
if ( V_514 > 0 )
goto V_515;
return NULL ;
}
static void F_362 ( struct V_24 * V_24 , struct V_26 * V_360 )
{
struct V_27 * V_28 = & V_360 -> V_28 ;
struct V_25 * V_25 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_251 ( V_25 , V_28 ) ;
}
}
static void F_363 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_243 ( V_25 , V_28 ) ;
if ( V_45 -> V_505 != V_518 ) {
F_284 ( V_24 ) ;
F_62 ( V_25 ) ;
F_364 ( V_24 , true ) ;
}
F_354 ( V_28 ) ;
}
static bool F_365 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_510 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_74 || F_206 ( F_23 ( V_28 ) ) )
return false ;
F_319 ( V_28 ) ;
F_363 ( V_24 ) ;
return true ;
}
static int F_366 ( struct V_26 * V_29 , struct V_519 * V_159 )
{
T_3 V_42 ;
F_305 ( & V_159 -> V_177 -> V_182 ) ;
if ( V_29 -> V_423 != & V_424 )
return 0 ;
if ( F_13 ( V_29 -> V_505 == V_506 ) )
return 0 ;
if ( F_237 ( V_520 ) && V_159 -> V_179 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_521 == - 1 )
return 1 ;
if ( V_521 == 0 )
return 0 ;
V_42 = F_63 ( V_159 -> V_177 ) - V_29 -> V_28 . V_87 ;
return V_42 < ( T_3 ) V_521 ;
}
static int F_367 ( struct V_26 * V_29 , struct V_519 * V_159 )
{
struct V_113 * V_113 = F_133 ( V_29 -> V_113 ) ;
unsigned long V_522 , V_523 ;
int V_140 , V_143 ;
if ( ! V_29 -> V_121 || ! ( V_159 -> V_191 -> V_183 & V_524 ) )
return - 1 ;
if ( ! F_237 ( V_525 ) )
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
V_522 = F_93 ( V_29 , V_140 ) ;
V_523 = F_93 ( V_29 , V_143 ) ;
} else {
V_522 = F_92 ( V_29 , V_140 ) ;
V_523 = F_92 ( V_29 , V_143 ) ;
}
return V_523 < V_522 ;
}
static inline int F_367 ( struct V_26 * V_29 ,
struct V_519 * V_159 )
{
return - 1 ;
}
static
int F_368 ( struct V_26 * V_29 , struct V_519 * V_159 )
{
int V_526 ;
F_305 ( & V_159 -> V_177 -> V_182 ) ;
if ( F_276 ( V_301 ( V_29 ) , V_159 -> V_178 , V_159 -> V_141 ) )
return 0 ;
if ( ! F_124 ( V_159 -> V_141 , F_125 ( V_29 ) ) ) {
int V_152 ;
F_235 ( V_29 , V_28 . V_88 . V_527 ) ;
V_159 -> V_183 |= V_528 ;
if ( ! V_159 -> V_529 || ( V_159 -> V_183 & V_530 ) )
return 0 ;
F_340 (cpu, env->dst_grpmask, env->cpus) {
if ( F_124 ( V_152 , F_125 ( V_29 ) ) ) {
V_159 -> V_183 |= V_530 ;
V_159 -> V_531 = V_152 ;
break;
}
}
return 0 ;
}
V_159 -> V_183 &= ~ V_532 ;
if ( F_369 ( V_159 -> V_177 , V_29 ) ) {
F_235 ( V_29 , V_28 . V_88 . V_533 ) ;
return 0 ;
}
V_526 = F_367 ( V_29 , V_159 ) ;
if ( V_526 == - 1 )
V_526 = F_366 ( V_29 , V_159 ) ;
if ( V_526 <= 0 ||
V_159 -> V_191 -> V_534 > V_159 -> V_191 -> V_535 ) {
if ( V_526 == 1 ) {
F_235 ( V_159 -> V_191 , V_536 [ V_159 -> V_379 ] ) ;
F_235 ( V_29 , V_28 . V_88 . V_537 ) ;
}
return 1 ;
}
F_235 ( V_29 , V_28 . V_88 . V_538 ) ;
return 0 ;
}
static void F_370 ( struct V_26 * V_29 , struct V_519 * V_159 )
{
F_305 ( & V_159 -> V_177 -> V_182 ) ;
F_371 ( V_159 -> V_177 , V_29 , 0 ) ;
V_29 -> V_74 = V_539 ;
F_372 ( V_29 , V_159 -> V_141 ) ;
}
static struct V_26 * F_373 ( struct V_519 * V_159 )
{
struct V_26 * V_29 , * V_307 ;
F_305 ( & V_159 -> V_177 -> V_182 ) ;
F_374 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_368 ( V_29 , V_159 ) )
continue;
F_370 ( V_29 , V_159 ) ;
F_235 ( V_159 -> V_191 , V_540 [ V_159 -> V_379 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_375 ( struct V_519 * V_159 )
{
struct V_541 * V_542 = & V_159 -> V_177 -> V_300 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_543 = 0 ;
F_305 ( & V_159 -> V_177 -> V_182 ) ;
if ( V_159 -> V_473 <= 0 )
return 0 ;
while ( ! F_282 ( V_542 ) ) {
if ( V_159 -> V_379 != V_544 && V_159 -> V_177 -> V_72 <= 1 )
break;
V_29 = F_376 ( V_542 , struct V_26 , V_28 . V_299 ) ;
V_159 -> V_545 ++ ;
if ( V_159 -> V_545 > V_159 -> V_546 )
break;
if ( V_159 -> V_545 > V_159 -> V_547 ) {
V_159 -> V_547 += V_548 ;
V_159 -> V_183 |= V_549 ;
break;
}
if ( ! F_368 ( V_29 , V_159 ) )
goto V_58;
V_70 = F_126 ( V_29 ) ;
if ( F_237 ( V_550 ) && V_70 < 16 && ! V_159 -> V_191 -> V_534 )
goto V_58;
if ( ( V_70 / 2 ) > V_159 -> V_473 )
goto V_58;
F_370 ( V_29 , V_159 ) ;
F_198 ( & V_29 -> V_28 . V_299 , & V_159 -> V_542 ) ;
V_543 ++ ;
V_159 -> V_473 -= V_70 ;
#ifdef F_377
if ( V_159 -> V_379 == V_551 )
break;
#endif
if ( V_159 -> V_473 <= 0 )
break;
continue;
V_58:
F_378 ( & V_29 -> V_28 . V_299 , V_542 ) ;
}
F_66 ( V_159 -> V_191 , V_540 [ V_159 -> V_379 ] , V_543 ) ;
return V_543 ;
}
static void F_379 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_305 ( & V_24 -> V_182 ) ;
F_168 ( F_34 ( V_29 ) != V_24 ) ;
V_29 -> V_74 = V_552 ;
F_380 ( V_24 , V_29 , 0 ) ;
F_381 ( V_24 , V_29 , 0 ) ;
}
static void F_382 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_270 ( & V_24 -> V_182 ) ;
F_379 ( V_24 , V_29 ) ;
F_272 ( & V_24 -> V_182 ) ;
}
static void F_383 ( struct V_519 * V_159 )
{
struct V_541 * V_542 = & V_159 -> V_542 ;
struct V_26 * V_29 ;
F_270 ( & V_159 -> V_179 -> V_182 ) ;
while ( ! F_282 ( V_542 ) ) {
V_29 = F_376 ( V_542 , struct V_26 , V_28 . V_299 ) ;
F_200 ( & V_29 -> V_28 . V_299 ) ;
F_379 ( V_159 -> V_179 , V_29 ) ;
}
F_272 ( & V_159 -> V_179 -> V_182 ) ;
}
static void F_384 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
struct V_25 * V_25 ;
unsigned long V_183 ;
F_385 ( & V_24 -> V_182 , V_183 ) ;
F_284 ( V_24 ) ;
F_310 (rq, cfs_rq) {
if ( F_206 ( V_25 ) )
continue;
if ( F_214 ( F_217 ( V_25 ) , V_25 ) )
F_212 ( V_25 , 0 ) ;
}
F_386 ( & V_24 -> V_182 , V_183 ) ;
}
static void F_387 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_86 = V_201 ;
unsigned long V_70 ;
if ( V_25 -> V_553 == V_86 )
return;
V_25 -> V_554 = NULL ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_554 = V_28 ;
if ( V_25 -> V_553 == V_86 )
break;
}
if ( ! V_28 ) {
V_25 -> V_555 = F_225 ( V_25 ) ;
V_25 -> V_553 = V_86 ;
}
while ( ( V_28 = V_25 -> V_554 ) != NULL ) {
V_70 = V_25 -> V_555 ;
V_70 = F_388 ( V_70 * V_28 -> V_77 . V_80 ,
F_225 ( V_25 ) + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_555 = V_70 ;
V_25 -> V_553 = V_86 ;
}
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_387 ( V_25 ) ;
return F_388 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_555 ,
F_225 ( V_25 ) + 1 ) ;
}
static inline void F_384 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_183 ;
F_385 ( & V_24 -> V_182 , V_183 ) ;
F_284 ( V_24 ) ;
F_214 ( F_217 ( V_25 ) , V_25 ) ;
F_386 ( & V_24 -> V_182 , V_183 ) ;
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_389 ( struct V_556 * V_557 )
{
* V_557 = (struct V_556 ) {
. V_558 = NULL ,
. V_210 = NULL ,
. V_559 = 0UL ,
. V_560 = 0UL ,
. V_561 = {
. V_475 = 0UL ,
. V_562 = 0 ,
. V_563 = V_564 ,
} ,
} ;
}
static inline int F_390 ( struct V_190 * V_191 ,
enum V_565 V_379 )
{
int V_471 ;
switch ( V_379 ) {
case V_544 :
V_471 = V_191 -> V_566 ;
break;
case V_551 :
V_471 = V_191 -> V_567 ;
break;
default:
V_471 = V_191 -> V_568 ;
break;
}
return V_471 ;
}
static unsigned long F_391 ( struct V_190 * V_191 , int V_152 )
{
if ( ( V_191 -> V_183 & V_569 ) && ( V_191 -> V_500 > 1 ) )
return V_191 -> V_570 / V_191 -> V_500 ;
return V_155 ;
}
unsigned long __weak F_392 ( struct V_190 * V_191 , int V_152 )
{
return F_391 ( V_191 , V_152 ) ;
}
static unsigned long F_393 ( int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
T_2 V_442 , V_571 , V_572 , V_77 ;
T_3 V_42 ;
V_572 = F_84 ( V_24 -> V_572 ) ;
V_77 = F_84 ( V_24 -> V_573 ) ;
V_42 = F_394 ( V_24 ) - V_572 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_442 = F_395 () + V_42 ;
V_571 = F_211 ( V_77 , V_442 ) ;
if ( F_11 ( V_571 < V_155 ) )
return V_155 - V_571 ;
return 1 ;
}
static void F_396 ( struct V_190 * V_191 , int V_152 )
{
unsigned long V_153 = V_155 ;
struct V_465 * V_574 = V_191 -> V_468 ;
if ( F_237 ( V_575 ) )
V_153 *= F_392 ( V_191 , V_152 ) ;
else
V_153 *= F_391 ( V_191 , V_152 ) ;
V_153 >>= V_320 ;
F_110 ( V_152 ) -> V_445 = V_153 ;
V_153 *= F_393 ( V_152 ) ;
V_153 >>= V_320 ;
if ( ! V_153 )
V_153 = 1 ;
F_110 ( V_152 ) -> V_444 = V_153 ;
V_574 -> V_477 -> V_153 = V_153 ;
}
void F_397 ( struct V_190 * V_191 , int V_152 )
{
struct V_190 * V_499 = V_191 -> V_499 ;
struct V_465 * V_124 , * V_574 = V_191 -> V_468 ;
unsigned long V_153 ;
unsigned long V_198 ;
V_198 = F_142 ( V_191 -> V_576 ) ;
V_198 = F_147 ( V_198 , 1UL , V_577 ) ;
V_574 -> V_477 -> V_578 = V_201 + V_198 ;
if ( ! V_499 ) {
F_396 ( V_191 , V_152 ) ;
return;
}
V_153 = 0 ;
if ( V_499 -> V_183 & V_579 ) {
F_109 (cpu, sched_group_cpus(sdg)) {
struct V_580 * V_477 ;
struct V_24 * V_24 = F_110 ( V_152 ) ;
if ( F_13 ( ! V_24 -> V_191 ) ) {
V_153 += F_112 ( V_152 ) ;
continue;
}
V_477 = V_24 -> V_191 -> V_468 -> V_477 ;
V_153 += V_477 -> V_153 ;
}
} else {
V_124 = V_499 -> V_468 ;
do {
V_153 += V_124 -> V_477 -> V_153 ;
V_124 = V_124 -> V_58 ;
} while ( V_124 != V_499 -> V_468 );
}
V_574 -> V_477 -> V_153 = V_153 ;
}
static inline int
F_398 ( struct V_24 * V_24 , struct V_190 * V_191 )
{
return ( ( V_24 -> V_444 * V_191 -> V_174 ) <
( V_24 -> V_445 * 100 ) ) ;
}
static inline int F_399 ( struct V_465 * V_124 )
{
return V_124 -> V_477 -> V_473 ;
}
static inline bool
F_400 ( struct V_519 * V_159 , struct V_581 * V_582 )
{
if ( V_582 -> V_562 < V_582 -> F_99 )
return true ;
if ( ( V_582 -> V_583 * 100 ) >
( V_582 -> V_584 * V_159 -> V_191 -> V_174 ) )
return true ;
return false ;
}
static inline bool
F_401 ( struct V_519 * V_159 , struct V_581 * V_582 )
{
if ( V_582 -> V_562 <= V_582 -> F_99 )
return false ;
if ( ( V_582 -> V_583 * 100 ) <
( V_582 -> V_584 * V_159 -> V_191 -> V_174 ) )
return true ;
return false ;
}
static enum V_563 F_402 ( struct V_519 * V_159 ,
struct V_465 * V_124 ,
struct V_581 * V_582 )
{
if ( V_582 -> V_585 )
return V_586 ;
if ( F_399 ( V_124 ) )
return V_587 ;
return V_564 ;
}
static inline void F_403 ( struct V_519 * V_159 ,
struct V_465 * V_124 , int V_471 ,
int V_476 , struct V_581 * V_582 ,
bool * V_588 )
{
unsigned long V_70 ;
int V_249 ;
memset ( V_582 , 0 , sizeof( * V_582 ) ) ;
F_340 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_110 ( V_249 ) ;
if ( V_476 )
V_70 = F_327 ( V_249 , V_471 ) ;
else
V_70 = F_326 ( V_249 , V_471 ) ;
V_582 -> V_589 += V_70 ;
V_582 -> V_584 += F_346 ( V_249 ) ;
V_582 -> V_562 += V_24 -> V_40 . V_390 ;
if ( V_24 -> V_72 > 1 )
* V_588 = true ;
#ifdef F_404
V_582 -> V_110 += V_24 -> V_110 ;
V_582 -> V_112 += V_24 -> V_112 ;
#endif
V_582 -> V_590 += F_111 ( V_249 ) ;
if ( F_341 ( V_249 ) )
V_582 -> V_591 ++ ;
}
V_582 -> V_583 = V_124 -> V_477 -> V_153 ;
V_582 -> V_475 = ( V_582 -> V_589 * V_155 ) / V_582 -> V_583 ;
if ( V_582 -> V_562 )
V_582 -> V_592 = V_582 -> V_590 / V_582 -> V_562 ;
V_582 -> F_99 = V_124 -> F_99 ;
V_582 -> V_585 = F_401 ( V_159 , V_582 ) ;
V_582 -> V_563 = F_402 ( V_159 , V_124 , V_582 ) ;
}
static bool F_405 ( struct V_519 * V_159 ,
struct V_556 * V_557 ,
struct V_465 * V_487 ,
struct V_581 * V_582 )
{
struct V_581 * V_558 = & V_557 -> V_561 ;
if ( V_582 -> V_563 > V_558 -> V_563 )
return true ;
if ( V_582 -> V_563 < V_558 -> V_563 )
return false ;
if ( V_582 -> V_475 <= V_558 -> V_475 )
return false ;
if ( ! ( V_159 -> V_191 -> V_183 & V_593 ) )
return true ;
if ( V_582 -> V_562 && V_159 -> V_141 < F_406 ( V_487 ) ) {
if ( ! V_557 -> V_558 )
return true ;
if ( F_406 ( V_557 -> V_558 ) > F_406 ( V_487 ) )
return true ;
}
return false ;
}
static inline enum V_594 F_407 ( struct V_581 * V_582 )
{
if ( V_582 -> V_562 > V_582 -> V_110 )
return V_595 ;
if ( V_582 -> V_562 > V_582 -> V_112 )
return V_208 ;
return V_596 ;
}
static inline enum V_594 F_408 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_110 )
return V_595 ;
if ( V_24 -> V_72 > V_24 -> V_112 )
return V_208 ;
return V_596 ;
}
static inline enum V_594 F_407 ( struct V_581 * V_582 )
{
return V_596 ;
}
static inline enum V_594 F_408 ( struct V_24 * V_24 )
{
return V_595 ;
}
static inline void F_409 ( struct V_519 * V_159 , struct V_556 * V_557 )
{
struct V_190 * V_499 = V_159 -> V_191 -> V_499 ;
struct V_465 * V_487 = V_159 -> V_191 -> V_468 ;
struct V_581 V_597 ;
int V_471 , V_598 = 0 ;
bool V_588 = false ;
if ( V_499 && V_499 -> V_183 & V_599 )
V_598 = 1 ;
V_471 = F_390 ( V_159 -> V_191 , V_159 -> V_379 ) ;
do {
struct V_581 * V_582 = & V_597 ;
int V_476 ;
V_476 = F_124 ( V_159 -> V_141 , F_338 ( V_487 ) ) ;
if ( V_476 ) {
V_557 -> V_210 = V_487 ;
V_582 = & V_557 -> V_600 ;
if ( V_159 -> V_379 != V_551 ||
F_410 ( V_201 , V_487 -> V_477 -> V_578 ) )
F_397 ( V_159 -> V_191 , V_159 -> V_141 ) ;
}
F_403 ( V_159 , V_487 , V_471 , V_476 , V_582 ,
& V_588 ) ;
if ( V_476 )
goto V_601;
if ( V_598 && V_557 -> V_210 &&
F_400 ( V_159 , & V_557 -> V_600 ) &&
( V_582 -> V_562 > 1 ) ) {
V_582 -> V_585 = 1 ;
V_582 -> V_563 = V_586 ;
}
if ( F_405 ( V_159 , V_557 , V_487 , V_582 ) ) {
V_557 -> V_558 = V_487 ;
V_557 -> V_561 = * V_582 ;
}
V_601:
V_557 -> V_559 += V_582 -> V_589 ;
V_557 -> V_560 += V_582 -> V_583 ;
V_487 = V_487 -> V_58 ;
} while ( V_487 != V_159 -> V_191 -> V_468 );
if ( V_159 -> V_191 -> V_183 & V_524 )
V_159 -> V_594 = F_407 ( & V_557 -> V_561 ) ;
if ( ! V_159 -> V_191 -> V_34 ) {
if ( V_159 -> V_179 -> V_602 -> V_588 != V_588 )
V_159 -> V_179 -> V_602 -> V_588 = V_588 ;
}
}
static int F_411 ( struct V_519 * V_159 , struct V_556 * V_557 )
{
int V_603 ;
if ( ! ( V_159 -> V_191 -> V_183 & V_593 ) )
return 0 ;
if ( ! V_557 -> V_558 )
return 0 ;
V_603 = F_406 ( V_557 -> V_558 ) ;
if ( V_159 -> V_141 > V_603 )
return 0 ;
V_159 -> V_473 = F_113 (
V_557 -> V_561 . V_475 * V_557 -> V_561 . V_583 ,
V_155 ) ;
return 1 ;
}
static inline
void F_412 ( struct V_519 * V_159 , struct V_556 * V_557 )
{
unsigned long V_492 , V_604 = 0 , V_605 = 0 ;
unsigned int V_606 = 2 ;
unsigned long V_607 ;
struct V_581 * V_210 , * V_558 ;
V_210 = & V_557 -> V_600 ;
V_558 = & V_557 -> V_561 ;
if ( ! V_210 -> V_562 )
V_210 -> V_592 = F_329 ( V_159 -> V_141 ) ;
else if ( V_558 -> V_592 > V_210 -> V_592 )
V_606 = 1 ;
V_607 =
( V_558 -> V_592 * V_155 ) /
V_558 -> V_583 ;
if ( V_558 -> V_475 + V_607 >=
V_210 -> V_475 + ( V_607 * V_606 ) ) {
V_159 -> V_473 = V_558 -> V_592 ;
return;
}
V_604 += V_558 -> V_583 *
F_141 ( V_558 -> V_592 , V_558 -> V_475 ) ;
V_604 += V_210 -> V_583 *
F_141 ( V_210 -> V_592 , V_210 -> V_475 ) ;
V_604 /= V_155 ;
if ( V_558 -> V_475 > V_607 ) {
V_605 += V_558 -> V_583 *
F_141 ( V_558 -> V_592 ,
V_558 -> V_475 - V_607 ) ;
}
if ( V_558 -> V_475 * V_558 -> V_583 <
V_558 -> V_592 * V_155 ) {
V_492 = ( V_558 -> V_475 * V_558 -> V_583 ) /
V_210 -> V_583 ;
} else {
V_492 = ( V_558 -> V_592 * V_155 ) /
V_210 -> V_583 ;
}
V_605 += V_210 -> V_583 *
F_141 ( V_210 -> V_592 , V_210 -> V_475 + V_492 ) ;
V_605 /= V_155 ;
if ( V_605 > V_604 )
V_159 -> V_473 = V_558 -> V_592 ;
}
static inline void F_413 ( struct V_519 * V_159 , struct V_556 * V_557 )
{
unsigned long V_608 , V_609 = ~ 0UL ;
struct V_581 * V_210 , * V_558 ;
V_210 = & V_557 -> V_600 ;
V_558 = & V_557 -> V_561 ;
if ( V_558 -> V_563 == V_587 ) {
V_558 -> V_592 =
F_141 ( V_558 -> V_592 , V_557 -> V_475 ) ;
}
if ( V_558 -> V_475 <= V_557 -> V_475 ||
V_210 -> V_475 >= V_557 -> V_475 ) {
V_159 -> V_473 = 0 ;
return F_412 ( V_159 , V_557 ) ;
}
if ( V_558 -> V_563 == V_586 &&
V_210 -> V_563 == V_586 ) {
V_609 = V_558 -> V_562 *
V_84 ;
if ( V_609 > V_558 -> V_583 )
V_609 -= V_558 -> V_583 ;
else
V_609 = ~ 0UL ;
}
V_608 = F_141 ( V_558 -> V_475 - V_557 -> V_475 , V_609 ) ;
V_159 -> V_473 = F_141 (
V_608 * V_558 -> V_583 ,
( V_557 -> V_475 - V_210 -> V_475 ) * V_210 -> V_583
) / V_155 ;
if ( V_159 -> V_473 < V_558 -> V_592 )
return F_412 ( V_159 , V_557 ) ;
}
static struct V_465 * F_414 ( struct V_519 * V_159 )
{
struct V_581 * V_210 , * V_558 ;
struct V_556 V_557 ;
F_389 ( & V_557 ) ;
F_409 ( V_159 , & V_557 ) ;
V_210 = & V_557 . V_600 ;
V_558 = & V_557 . V_561 ;
if ( ( V_159 -> V_379 == V_610 || V_159 -> V_379 == V_551 ) &&
F_411 ( V_159 , & V_557 ) )
return V_557 . V_558 ;
if ( ! V_557 . V_558 || V_558 -> V_562 == 0 )
goto V_611;
V_557 . V_475 = ( V_155 * V_557 . V_559 )
/ V_557 . V_560 ;
if ( V_558 -> V_563 == V_587 )
goto V_612;
if ( V_159 -> V_379 == V_551 && F_400 ( V_159 , V_210 ) &&
V_558 -> V_585 )
goto V_612;
if ( V_210 -> V_475 >= V_558 -> V_475 )
goto V_611;
if ( V_210 -> V_475 >= V_557 . V_475 )
goto V_611;
if ( V_159 -> V_379 == V_610 ) {
if ( ( V_558 -> V_563 != V_586 ) &&
( V_210 -> V_591 <= ( V_558 -> V_591 + 1 ) ) )
goto V_611;
} else {
if ( 100 * V_558 -> V_475 <=
V_159 -> V_191 -> V_174 * V_210 -> V_475 )
goto V_611;
}
V_612:
F_413 ( V_159 , & V_557 ) ;
return V_557 . V_558 ;
V_611:
V_159 -> V_473 = 0 ;
return NULL ;
}
static struct V_24 * F_415 ( struct V_519 * V_159 ,
struct V_465 * V_124 )
{
struct V_24 * V_558 = NULL , * V_24 ;
unsigned long V_613 = 0 , V_614 = 1 ;
int V_249 ;
F_340 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_153 , V_449 ;
enum V_594 V_615 ;
V_24 = F_110 ( V_249 ) ;
V_615 = F_408 ( V_24 ) ;
if ( V_615 > V_159 -> V_594 )
continue;
V_153 = F_112 ( V_249 ) ;
V_449 = F_111 ( V_249 ) ;
if ( V_24 -> V_72 == 1 && V_449 > V_159 -> V_473 &&
! F_398 ( V_24 , V_159 -> V_191 ) )
continue;
if ( V_449 * V_614 > V_613 * V_153 ) {
V_613 = V_449 ;
V_614 = V_153 ;
V_558 = V_24 ;
}
}
return V_558 ;
}
static int F_416 ( struct V_519 * V_159 )
{
struct V_190 * V_191 = V_159 -> V_191 ;
if ( V_159 -> V_379 == V_551 ) {
if ( ( V_191 -> V_183 & V_593 ) && V_159 -> V_178 > V_159 -> V_141 )
return 1 ;
}
if ( ( V_159 -> V_379 != V_544 ) &&
( V_159 -> V_177 -> V_40 . V_390 == 1 ) ) {
if ( ( F_398 ( V_159 -> V_177 , V_191 ) ) &&
( F_112 ( V_159 -> V_178 ) * V_191 -> V_174 < F_112 ( V_159 -> V_141 ) * 100 ) )
return 1 ;
}
return F_13 ( V_191 -> V_534 > V_191 -> V_535 + 2 ) ;
}
static int F_417 ( struct V_519 * V_159 )
{
struct V_465 * V_487 = V_159 -> V_191 -> V_468 ;
struct V_616 * V_617 , * V_618 ;
int V_152 , V_619 = - 1 ;
if ( V_159 -> V_379 == V_551 )
return 1 ;
V_617 = F_338 ( V_487 ) ;
V_618 = F_418 ( V_487 ) ;
F_340 (cpu, sg_cpus, env->cpus) {
if ( ! F_124 ( V_152 , V_618 ) || ! F_341 ( V_152 ) )
continue;
V_619 = V_152 ;
break;
}
if ( V_619 == - 1 )
V_619 = F_419 ( V_487 ) ;
return V_619 == V_159 -> V_141 ;
}
static int F_420 ( int V_458 , struct V_24 * V_332 ,
struct V_190 * V_191 , enum V_565 V_379 ,
int * V_620 )
{
int V_621 , V_622 , V_623 = 0 ;
struct V_190 * V_624 = V_191 -> V_34 ;
struct V_465 * V_124 ;
struct V_24 * V_558 ;
unsigned long V_183 ;
struct V_616 * V_8 = F_421 ( V_625 ) ;
struct V_519 V_159 = {
. V_191 = V_191 ,
. V_141 = V_458 ,
. V_179 = V_332 ,
. V_529 = F_338 ( V_191 -> V_468 ) ,
. V_379 = V_379 ,
. V_547 = V_548 ,
. V_8 = V_8 ,
. V_594 = V_596 ,
. V_542 = F_422 ( V_159 . V_542 ) ,
} ;
if ( V_379 == V_551 )
V_159 . V_529 = NULL ;
F_423 ( V_8 , V_626 ) ;
F_235 ( V_191 , V_627 [ V_379 ] ) ;
V_628:
if ( ! F_417 ( & V_159 ) ) {
* V_620 = 0 ;
goto V_611;
}
V_124 = F_414 ( & V_159 ) ;
if ( ! V_124 ) {
F_235 ( V_191 , V_629 [ V_379 ] ) ;
goto V_611;
}
V_558 = F_415 ( & V_159 , V_124 ) ;
if ( ! V_558 ) {
F_235 ( V_191 , V_630 [ V_379 ] ) ;
goto V_611;
}
F_168 ( V_558 == V_159 . V_179 ) ;
F_66 ( V_191 , V_631 [ V_379 ] , V_159 . V_473 ) ;
V_159 . V_178 = V_558 -> V_152 ;
V_159 . V_177 = V_558 ;
V_621 = 0 ;
if ( V_558 -> V_72 > 1 ) {
V_159 . V_183 |= V_532 ;
V_159 . V_546 = F_141 ( V_632 , V_558 -> V_72 ) ;
V_633:
F_385 ( & V_558 -> V_182 , V_183 ) ;
V_622 = F_375 ( & V_159 ) ;
F_272 ( & V_558 -> V_182 ) ;
if ( V_622 ) {
F_383 ( & V_159 ) ;
V_621 += V_622 ;
}
F_424 ( V_183 ) ;
if ( V_159 . V_183 & V_549 ) {
V_159 . V_183 &= ~ V_549 ;
goto V_633;
}
if ( ( V_159 . V_183 & V_530 ) && V_159 . V_473 > 0 ) {
F_425 ( V_159 . V_141 , V_159 . V_8 ) ;
V_159 . V_179 = F_110 ( V_159 . V_531 ) ;
V_159 . V_141 = V_159 . V_531 ;
V_159 . V_183 &= ~ V_530 ;
V_159 . V_545 = 0 ;
V_159 . V_547 = V_548 ;
goto V_633;
}
if ( V_624 ) {
int * V_634 = & V_624 -> V_468 -> V_477 -> V_473 ;
if ( ( V_159 . V_183 & V_528 ) && V_159 . V_473 > 0 )
* V_634 = 1 ;
}
if ( F_13 ( V_159 . V_183 & V_532 ) ) {
F_425 ( F_26 ( V_558 ) , V_8 ) ;
if ( ! F_426 ( V_8 ) ) {
V_159 . V_545 = 0 ;
V_159 . V_547 = V_548 ;
goto V_628;
}
goto V_635;
}
}
if ( ! V_621 ) {
F_235 ( V_191 , V_636 [ V_379 ] ) ;
if ( V_379 != V_551 )
V_191 -> V_534 ++ ;
if ( F_416 ( & V_159 ) ) {
F_385 ( & V_558 -> V_182 , V_183 ) ;
if ( ! F_124 ( V_458 ,
F_125 ( V_558 -> V_45 ) ) ) {
F_386 ( & V_558 -> V_182 ,
V_183 ) ;
V_159 . V_183 |= V_532 ;
goto V_637;
}
if ( ! V_558 -> V_623 ) {
V_558 -> V_623 = 1 ;
V_558 -> V_638 = V_458 ;
V_623 = 1 ;
}
F_386 ( & V_558 -> V_182 , V_183 ) ;
if ( V_623 ) {
F_427 ( F_26 ( V_558 ) ,
V_639 , V_558 ,
& V_558 -> V_640 ) ;
}
V_191 -> V_534 = V_191 -> V_535 + 1 ;
}
} else
V_191 -> V_534 = 0 ;
if ( F_11 ( ! V_623 ) ) {
V_191 -> V_576 = V_191 -> V_641 ;
} else {
if ( V_191 -> V_576 < V_191 -> V_642 )
V_191 -> V_576 *= 2 ;
}
goto V_297;
V_611:
if ( V_624 ) {
int * V_634 = & V_624 -> V_468 -> V_477 -> V_473 ;
if ( * V_634 )
* V_634 = 0 ;
}
V_635:
F_235 ( V_191 , V_643 [ V_379 ] ) ;
V_191 -> V_534 = 0 ;
V_637:
if ( ( ( V_159 . V_183 & V_532 ) &&
V_191 -> V_576 < V_644 ) ||
( V_191 -> V_576 < V_191 -> V_642 ) )
V_191 -> V_576 *= 2 ;
V_621 = 0 ;
V_297:
return V_621 ;
}
static inline unsigned long
F_428 ( struct V_190 * V_191 , int V_645 )
{
unsigned long V_198 = V_191 -> V_576 ;
if ( V_645 )
V_198 *= V_191 -> V_646 ;
V_198 = F_142 ( V_198 ) ;
V_198 = F_147 ( V_198 , 1UL , V_577 ) ;
return V_198 ;
}
static inline void
F_429 ( struct V_190 * V_191 , int V_645 , unsigned long * V_647 )
{
unsigned long V_198 , V_58 ;
V_198 = F_428 ( V_191 , V_645 ) ;
V_58 = V_191 -> V_648 + V_198 ;
if ( F_178 ( * V_647 , V_58 ) )
* V_647 = V_58 ;
}
static int F_226 ( struct V_24 * V_332 )
{
unsigned long V_647 = V_201 + V_199 ;
int V_458 = V_332 -> V_152 ;
struct V_190 * V_191 ;
int V_649 = 0 ;
T_2 V_650 = 0 ;
F_222 ( V_332 ) ;
V_332 -> V_485 = F_73 ( V_332 ) ;
if ( V_332 -> V_651 < V_521 ||
! V_332 -> V_602 -> V_588 ) {
F_120 () ;
V_191 = F_430 ( V_332 -> V_191 ) ;
if ( V_191 )
F_429 ( V_191 , 0 , & V_647 ) ;
F_128 () ;
goto V_297;
}
F_272 ( & V_332 -> V_182 ) ;
F_384 ( V_458 ) ;
F_120 () ;
F_348 (this_cpu, sd) {
int V_620 = 1 ;
T_2 V_652 , V_653 ;
if ( ! ( V_191 -> V_183 & V_497 ) )
continue;
if ( V_332 -> V_651 < V_650 + V_191 -> V_654 ) {
F_429 ( V_191 , 0 , & V_647 ) ;
break;
}
if ( V_191 -> V_183 & V_655 ) {
V_652 = F_265 ( V_458 ) ;
V_649 = F_420 ( V_458 , V_332 ,
V_191 , V_551 ,
& V_620 ) ;
V_653 = F_265 ( V_458 ) - V_652 ;
if ( V_653 > V_191 -> V_654 )
V_191 -> V_654 = V_653 ;
V_650 += V_653 ;
}
F_429 ( V_191 , 0 , & V_647 ) ;
if ( V_649 || V_332 -> V_72 > 0 )
break;
}
F_128 () ;
F_270 ( & V_332 -> V_182 ) ;
if ( V_650 > V_332 -> V_656 )
V_332 -> V_656 = V_650 ;
if ( V_332 -> V_40 . V_390 && ! V_649 )
V_649 = 1 ;
V_297:
if ( F_178 ( V_332 -> V_647 , V_647 ) )
V_332 -> V_647 = V_647 ;
if ( V_332 -> V_72 != V_332 -> V_40 . V_390 )
V_649 = - 1 ;
if ( V_649 ) {
F_223 ( V_332 ) ;
V_332 -> V_485 = 0 ;
}
return V_649 ;
}
static int V_639 ( void * V_385 )
{
struct V_24 * V_657 = V_385 ;
int V_603 = F_26 ( V_657 ) ;
int V_658 = V_657 -> V_638 ;
struct V_24 * V_659 = F_110 ( V_658 ) ;
struct V_190 * V_191 ;
struct V_26 * V_29 = NULL ;
F_121 ( & V_657 -> V_182 ) ;
if ( F_13 ( V_603 != F_266 () ||
! V_657 -> V_623 ) )
goto V_660;
if ( V_657 -> V_72 <= 1 )
goto V_660;
F_168 ( V_657 == V_659 ) ;
F_120 () ;
F_348 (target_cpu, sd) {
if ( ( V_191 -> V_183 & V_497 ) &&
F_124 ( V_603 , F_349 ( V_191 ) ) )
break;
}
if ( F_11 ( V_191 ) ) {
struct V_519 V_159 = {
. V_191 = V_191 ,
. V_141 = V_658 ,
. V_179 = V_659 ,
. V_178 = V_657 -> V_152 ,
. V_177 = V_657 ,
. V_379 = V_610 ,
} ;
F_235 ( V_191 , V_661 ) ;
V_29 = F_373 ( & V_159 ) ;
if ( V_29 )
F_235 ( V_191 , V_662 ) ;
else
F_235 ( V_191 , V_663 ) ;
}
F_128 () ;
V_660:
V_657 -> V_623 = 0 ;
F_272 ( & V_657 -> V_182 ) ;
if ( V_29 )
F_382 ( V_659 , V_29 ) ;
F_431 () ;
return 0 ;
}
static inline int F_432 ( struct V_24 * V_24 )
{
return F_13 ( ! F_433 ( V_24 -> V_191 ) ) ;
}
static inline int F_434 ( void )
{
int V_664 = F_435 ( V_665 . V_666 ) ;
if ( V_664 < V_667 && F_341 ( V_664 ) )
return V_664 ;
return V_667 ;
}
static void F_436 ( void )
{
int V_668 ;
V_665 . V_647 ++ ;
V_668 = F_434 () ;
if ( V_668 >= V_667 )
return;
if ( F_437 ( V_669 , F_438 ( V_668 ) ) )
return;
F_439 ( V_668 ) ;
return;
}
static inline void F_440 ( int V_152 )
{
if ( F_13 ( F_441 ( V_670 , F_438 ( V_152 ) ) ) ) {
if ( F_11 ( F_124 ( V_152 , V_665 . V_666 ) ) ) {
F_425 ( V_152 , V_665 . V_666 ) ;
F_442 ( & V_665 . V_671 ) ;
}
F_443 ( V_670 , F_438 ( V_152 ) ) ;
}
}
static inline void F_444 ( void )
{
struct V_190 * V_191 ;
int V_152 = F_266 () ;
F_120 () ;
V_191 = F_133 ( F_134 ( V_672 , V_152 ) ) ;
if ( ! V_191 || ! V_191 -> V_673 )
goto V_185;
V_191 -> V_673 = 0 ;
F_445 ( & V_191 -> V_468 -> V_477 -> V_674 ) ;
V_185:
F_128 () ;
}
void F_446 ( void )
{
struct V_190 * V_191 ;
int V_152 = F_266 () ;
F_120 () ;
V_191 = F_133 ( F_134 ( V_672 , V_152 ) ) ;
if ( ! V_191 || V_191 -> V_673 )
goto V_185;
V_191 -> V_673 = 1 ;
F_442 ( & V_191 -> V_468 -> V_477 -> V_674 ) ;
V_185:
F_128 () ;
}
void F_447 ( int V_152 )
{
if ( ! F_448 ( V_152 ) )
return;
if ( F_441 ( V_670 , F_438 ( V_152 ) ) )
return;
if ( F_432 ( F_110 ( V_152 ) ) )
return;
F_449 ( V_152 , V_665 . V_666 ) ;
F_445 ( & V_665 . V_671 ) ;
F_450 ( V_670 , F_438 ( V_152 ) ) ;
}
static int F_451 ( struct V_675 * V_676 ,
unsigned long V_677 , void * V_678 )
{
switch ( V_677 & ~ V_679 ) {
case V_680 :
F_440 ( F_266 () ) ;
return V_681 ;
default:
return V_682 ;
}
}
void F_452 ( void )
{
V_577 = V_199 * F_453 () / 10 ;
}
static void F_454 ( struct V_24 * V_24 , enum V_565 V_379 )
{
int V_620 = 1 ;
int V_152 = V_24 -> V_152 ;
unsigned long V_198 ;
struct V_190 * V_191 ;
unsigned long V_647 = V_201 + 60 * V_199 ;
int F_429 = 0 ;
int V_683 , V_684 = 0 ;
T_2 V_685 = 0 ;
F_384 ( V_152 ) ;
F_120 () ;
F_348 (cpu, sd) {
if ( F_178 ( V_201 , V_191 -> V_686 ) ) {
V_191 -> V_654 =
( V_191 -> V_654 * 253 ) / 256 ;
V_191 -> V_686 = V_201 + V_199 ;
V_684 = 1 ;
}
V_685 += V_191 -> V_654 ;
if ( ! ( V_191 -> V_183 & V_497 ) )
continue;
if ( ! V_620 ) {
if ( V_684 )
continue;
break;
}
V_198 = F_428 ( V_191 , V_379 != V_610 ) ;
V_683 = V_191 -> V_183 & V_687 ;
if ( V_683 ) {
if ( ! F_455 ( & V_688 ) )
goto V_297;
}
if ( F_410 ( V_201 , V_191 -> V_648 + V_198 ) ) {
if ( F_420 ( V_152 , V_24 , V_191 , V_379 , & V_620 ) ) {
V_379 = F_341 ( V_152 ) ? V_610 : V_544 ;
}
V_191 -> V_648 = V_201 ;
V_198 = F_428 ( V_191 , V_379 != V_610 ) ;
}
if ( V_683 )
F_171 ( & V_688 ) ;
V_297:
if ( F_178 ( V_647 , V_191 -> V_648 + V_198 ) ) {
V_647 = V_191 -> V_648 + V_198 ;
F_429 = 1 ;
}
}
if ( V_684 ) {
V_24 -> V_656 =
F_65 ( ( T_2 ) V_521 , V_685 ) ;
}
F_128 () ;
if ( F_11 ( F_429 ) )
V_24 -> V_647 = V_647 ;
}
static void F_456 ( struct V_24 * V_332 , enum V_565 V_379 )
{
int V_458 = V_332 -> V_152 ;
struct V_24 * V_24 ;
int V_619 ;
if ( V_379 != V_610 ||
! F_441 ( V_669 , F_438 ( V_458 ) ) )
goto V_278;
F_109 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_619 == V_458 || ! F_341 ( V_619 ) )
continue;
if ( F_457 () )
break;
V_24 = F_110 ( V_619 ) ;
if ( F_410 ( V_201 , V_24 -> V_647 ) ) {
F_121 ( & V_24 -> V_182 ) ;
F_284 ( V_24 ) ;
F_323 ( V_24 ) ;
F_123 ( & V_24 -> V_182 ) ;
F_454 ( V_24 , V_610 ) ;
}
if ( F_178 ( V_332 -> V_647 , V_24 -> V_647 ) )
V_332 -> V_647 = V_24 -> V_647 ;
}
V_665 . V_647 = V_332 -> V_647 ;
V_278:
F_443 ( V_669 , F_438 ( V_458 ) ) ;
}
static inline bool F_458 ( struct V_24 * V_24 )
{
unsigned long V_86 = V_201 ;
struct V_190 * V_191 ;
struct V_580 * V_477 ;
int V_689 , V_152 = V_24 -> V_152 ;
bool V_690 = false ;
if ( F_13 ( V_24 -> F_226 ) )
return false ;
F_444 () ;
F_440 ( V_152 ) ;
if ( F_11 ( ! F_459 ( & V_665 . V_671 ) ) )
return false ;
if ( F_182 ( V_86 , V_665 . V_647 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_120 () ;
V_191 = F_133 ( F_134 ( V_672 , V_152 ) ) ;
if ( V_191 ) {
V_477 = V_191 -> V_468 -> V_477 ;
V_689 = F_459 ( & V_477 -> V_674 ) ;
if ( V_689 > 1 ) {
V_690 = true ;
goto V_185;
}
}
V_191 = F_133 ( V_24 -> V_191 ) ;
if ( V_191 ) {
if ( ( V_24 -> V_40 . V_390 >= 1 ) &&
F_398 ( V_24 , V_191 ) ) {
V_690 = true ;
goto V_185;
}
}
V_191 = F_133 ( F_134 ( V_691 , V_152 ) ) ;
if ( V_191 && ( F_345 ( V_665 . V_666 ,
F_349 ( V_191 ) ) < V_152 ) ) {
V_690 = true ;
goto V_185;
}
V_185:
F_128 () ;
return V_690 ;
}
static void F_456 ( struct V_24 * V_332 , enum V_565 V_379 ) { }
static void F_460 ( struct V_692 * V_693 )
{
struct V_24 * V_332 = V_332 () ;
enum V_565 V_379 = V_332 -> F_226 ?
V_610 : V_544 ;
F_456 ( V_332 , V_379 ) ;
F_454 ( V_332 , V_379 ) ;
}
void F_461 ( struct V_24 * V_24 )
{
if ( F_13 ( F_432 ( V_24 ) ) )
return;
if ( F_410 ( V_201 , V_24 -> V_647 ) )
F_462 ( V_694 ) ;
#ifdef F_463
if ( F_458 ( V_24 ) )
F_436 () ;
#endif
}
static void F_464 ( struct V_24 * V_24 )
{
F_7 () ;
F_309 ( V_24 ) ;
}
static void F_465 ( struct V_24 * V_24 )
{
F_7 () ;
F_311 ( V_24 ) ;
}
static void F_466 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_361 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_253 ( V_25 , V_28 , V_361 ) ;
}
if ( V_263 )
F_193 ( V_24 , V_45 ) ;
}
static void F_467 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_458 = F_266 () ;
struct V_24 * V_24 = V_332 () ;
unsigned long V_183 ;
F_385 ( & V_24 -> V_182 , V_183 ) ;
F_284 ( V_24 ) ;
V_25 = F_22 ( V_146 ) ;
V_45 = V_25 -> V_45 ;
F_120 () ;
F_468 ( V_29 , V_458 ) ;
F_128 () ;
F_62 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_236 ( V_25 , V_28 , 1 ) ;
if ( V_695 && V_45 && F_37 ( V_45 , V_28 ) ) {
F_118 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_247 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_36 ;
F_386 ( & V_24 -> V_182 , V_183 ) ;
}
static void
F_469 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_696 )
{
if ( ! F_470 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_697 > V_696 )
F_247 ( V_24 ) ;
} else
F_381 ( V_24 , V_29 , 0 ) ;
}
static void F_471 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( ! F_470 ( V_29 ) && V_29 -> V_353 != V_698 ) {
F_236 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_36 ;
}
#ifdef F_197
F_209 ( V_25 -> V_77 . V_78 , F_26 ( V_24 ) , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) , V_25 -> V_45 == V_28 , NULL ) ;
V_25 -> V_77 . V_80 =
F_85 ( long , V_25 -> V_77 . V_80 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_77 . V_81 =
F_85 ( T_3 , V_25 -> V_77 . V_81 - V_28 -> V_77 . V_81 , 0 ) ;
V_25 -> V_77 . V_83 =
F_85 ( long , V_25 -> V_77 . V_83 - V_28 -> V_77 . V_83 , 0 ) ;
V_25 -> V_77 . V_85 =
F_85 ( V_328 , V_25 -> V_77 . V_85 - V_28 -> V_77 . V_85 , 0 ) ;
#endif
}
static void F_472 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
#ifdef F_358
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_470 ( V_29 ) ) {
if ( V_29 -> V_353 != V_698 )
V_28 -> V_41 += F_23 ( V_28 ) -> F_36 ;
return;
}
if ( V_24 -> V_45 == V_29 )
F_247 ( V_24 ) ;
else
F_381 ( V_24 , V_29 , 0 ) ;
}
static void F_473 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_248 ( V_25 , V_28 ) ;
F_70 ( V_25 , 0 ) ;
}
}
void F_474 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_699 ;
V_25 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_25 -> V_48 = V_25 -> F_36 ;
#endif
#ifdef F_197
F_475 ( & V_25 -> V_325 , 0 ) ;
F_475 ( & V_25 -> V_327 , 0 ) ;
#endif
}
static void F_476 ( struct V_26 * V_29 , int V_361 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_361 && ( ! V_28 -> V_90 || V_29 -> V_353 == V_700 ) )
V_361 = 1 ;
if ( ! V_361 )
V_28 -> V_41 -= F_23 ( V_28 ) -> F_36 ;
F_477 ( V_29 , F_132 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_361 ) {
V_25 = F_23 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_36 ;
#ifdef F_197
V_29 -> V_28 . V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_29 -> V_28 . V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_29 -> V_28 . V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_29 -> V_28 . V_77 . V_83 ;
V_25 -> V_77 . V_85 += V_29 -> V_28 . V_77 . V_85 ;
#endif
}
}
void F_478 ( struct V_301 * V_33 )
{
int V_249 ;
F_307 ( F_268 ( V_33 ) ) ;
F_479 (i) {
if ( V_33 -> V_25 )
F_176 ( V_33 -> V_25 [ V_249 ] ) ;
if ( V_33 -> V_28 ) {
if ( V_33 -> V_28 [ V_249 ] )
F_220 ( V_33 -> V_28 [ V_249 ] ) ;
F_176 ( V_33 -> V_28 [ V_249 ] ) ;
}
}
F_176 ( V_33 -> V_25 ) ;
F_176 ( V_33 -> V_28 ) ;
}
int F_480 ( struct V_301 * V_33 , struct V_301 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_249 ;
V_33 -> V_25 = F_164 ( sizeof( V_25 ) * V_667 , V_251 ) ;
if ( ! V_33 -> V_25 )
goto V_701;
V_33 -> V_28 = F_164 ( sizeof( V_28 ) * V_667 , V_251 ) ;
if ( ! V_33 -> V_28 )
goto V_701;
V_33 -> V_304 = V_71 ;
F_300 ( F_268 ( V_33 ) ) ;
F_479 (i) {
V_25 = F_481 ( sizeof( struct V_25 ) ,
V_251 , F_101 ( V_249 ) ) ;
if ( ! V_25 )
goto V_701;
V_28 = F_481 ( sizeof( struct V_27 ) ,
V_251 , F_101 ( V_249 ) ) ;
if ( ! V_28 )
goto V_702;
F_474 ( V_25 ) ;
F_482 ( V_33 , V_25 , V_28 , V_249 , V_34 -> V_28 [ V_249 ] ) ;
F_61 ( V_28 ) ;
}
return 1 ;
V_702:
F_176 ( V_25 ) ;
V_701:
return 0 ;
}
void F_483 ( struct V_301 * V_33 , int V_152 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
unsigned long V_183 ;
if ( ! V_33 -> V_25 [ V_152 ] -> V_32 )
return;
F_385 ( & V_24 -> V_182 , V_183 ) ;
F_29 ( V_33 -> V_25 [ V_152 ] ) ;
F_386 ( & V_24 -> V_182 , V_183 ) ;
}
void F_482 ( struct V_301 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_152 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_110 ( V_152 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_304 ( V_25 ) ;
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
int F_484 ( struct V_301 * V_33 , unsigned long V_304 )
{
int V_249 ;
unsigned long V_183 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_195 ;
V_304 = F_147 ( V_304 , F_485 ( V_305 ) , F_485 ( V_703 ) ) ;
F_486 ( & V_704 ) ;
if ( V_33 -> V_304 == V_304 )
goto V_489;
V_33 -> V_304 = V_304 ;
F_479 (i) {
struct V_24 * V_24 = F_110 ( V_249 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_249 ] ;
F_385 ( & V_24 -> V_182 , V_183 ) ;
F_284 ( V_24 ) ;
F_59 (se)
F_205 ( F_24 ( V_28 ) ) ;
F_386 ( & V_24 -> V_182 , V_183 ) ;
}
V_489:
F_487 ( & V_704 ) ;
return 0 ;
}
void F_478 ( struct V_301 * V_33 ) { }
int F_480 ( struct V_301 * V_33 , struct V_301 * V_34 )
{
return 1 ;
}
void F_483 ( struct V_301 * V_33 , int V_152 ) { }
static unsigned int F_488 ( struct V_24 * V_24 , struct V_26 * V_127 )
{
struct V_27 * V_28 = & V_127 -> V_28 ;
unsigned int V_705 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_705 = F_489 ( F_58 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_705 ;
}
void F_490 ( struct V_706 * V_707 , int V_152 )
{
struct V_25 * V_25 ;
F_120 () ;
F_310 (cpu_rq(cpu), cfs_rq)
F_491 ( V_707 , V_152 , V_25 ) ;
F_128 () ;
}
void F_492 ( struct V_26 * V_29 , struct V_706 * V_707 )
{
int V_129 ;
unsigned long V_708 = 0 , V_709 = 0 , V_710 = 0 , V_711 = 0 ;
F_96 (node) {
if ( V_29 -> V_121 ) {
V_708 = V_29 -> V_121 [ F_91 ( V_122 , V_129 , 0 ) ] ;
V_709 = V_29 -> V_121 [ F_91 ( V_122 , V_129 , 1 ) ] ;
}
if ( V_29 -> V_113 ) {
V_710 = V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_129 , 0 ) ] ,
V_711 = V_29 -> V_113 -> V_123 [ F_91 ( V_122 , V_129 , 1 ) ] ;
}
F_493 ( V_707 , V_129 , V_708 , V_709 , V_710 , V_711 ) ;
}
}
T_12 void F_494 ( void )
{
#ifdef F_197
F_495 ( V_694 , F_460 ) ;
#ifdef F_463
V_665 . V_647 = V_201 ;
F_496 ( & V_665 . V_666 , V_712 ) ;
F_497 ( F_451 , 0 ) ;
#endif
#endif
}
