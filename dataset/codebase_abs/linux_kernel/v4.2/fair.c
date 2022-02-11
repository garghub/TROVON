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
F_29 ( V_25 , 0 ) ;
}
}
static inline void F_30 ( struct V_25 * V_25 )
{
if ( V_25 -> V_32 ) {
F_31 ( & V_25 -> V_35 ) ;
V_25 -> V_32 = 0 ;
}
}
static inline struct V_25 *
F_32 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
if ( V_28 -> V_25 == V_36 -> V_25 )
return V_28 -> V_25 ;
return NULL ;
}
static inline struct V_27 * F_33 ( struct V_27 * V_28 )
{
return V_28 -> V_34 ;
}
static void
F_34 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
int V_37 , V_38 ;
V_37 = ( * V_28 ) -> V_39 ;
V_38 = ( * V_36 ) -> V_39 ;
while ( V_37 > V_38 ) {
V_37 -- ;
* V_28 = F_33 ( * V_28 ) ;
}
while ( V_38 > V_37 ) {
V_38 -- ;
* V_36 = F_33 ( * V_36 ) ;
}
while ( ! F_32 ( * V_28 , * V_36 ) ) {
* V_28 = F_33 ( * V_28 ) ;
* V_36 = F_33 ( * V_36 ) ;
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
return & F_35 ( V_29 ) -> V_40 ;
}
static inline struct V_25 * F_23 ( struct V_27 * V_28 )
{
struct V_26 * V_29 = F_17 ( V_28 ) ;
struct V_24 * V_24 = F_35 ( V_29 ) ;
return & V_24 -> V_40 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_30 )
{
return NULL ;
}
static inline void F_25 ( struct V_25 * V_25 )
{
}
static inline void F_30 ( struct V_25 * V_25 )
{
}
static inline struct V_27 * F_33 ( struct V_27 * V_28 )
{
return NULL ;
}
static inline void
F_34 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
}
static inline T_2 F_36 ( T_2 F_36 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_36 ) ;
if ( V_42 > 0 )
F_36 = V_41 ;
return F_36 ;
}
static inline T_2 F_37 ( T_2 F_37 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_37 ) ;
if ( V_42 < 0 )
F_37 = V_41 ;
return F_37 ;
}
static inline int F_38 ( struct V_27 * V_43 ,
struct V_27 * V_44 )
{
return ( T_3 ) ( V_43 -> V_41 - V_44 -> V_41 ) < 0 ;
}
static void F_39 ( struct V_25 * V_25 )
{
T_2 V_41 = V_25 -> F_37 ;
if ( V_25 -> V_45 )
V_41 = V_25 -> V_45 -> V_41 ;
if ( V_25 -> V_46 ) {
struct V_27 * V_28 = F_40 ( V_25 -> V_46 ,
struct V_27 ,
V_47 ) ;
if ( ! V_25 -> V_45 )
V_41 = V_28 -> V_41 ;
else
V_41 = F_37 ( V_41 , V_28 -> V_41 ) ;
}
V_25 -> F_37 = F_36 ( V_25 -> F_37 , V_41 ) ;
#ifndef F_41
F_42 () ;
V_25 -> V_48 = V_25 -> F_37 ;
#endif
}
static void F_43 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_49 * * V_50 = & V_25 -> V_51 . V_49 ;
struct V_49 * V_34 = NULL ;
struct V_27 * V_52 ;
int V_53 = 1 ;
while ( * V_50 ) {
V_34 = * V_50 ;
V_52 = F_40 ( V_34 , struct V_27 , V_47 ) ;
if ( F_38 ( V_28 , V_52 ) ) {
V_50 = & V_34 -> V_54 ;
} else {
V_50 = & V_34 -> V_55 ;
V_53 = 0 ;
}
}
if ( V_53 )
V_25 -> V_46 = & V_28 -> V_47 ;
F_44 ( & V_28 -> V_47 , V_34 , V_50 ) ;
F_45 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
static void F_46 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_46 == & V_28 -> V_47 ) {
struct V_49 * V_56 ;
V_56 = F_47 ( & V_28 -> V_47 ) ;
V_25 -> V_46 = V_56 ;
}
F_48 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
struct V_27 * F_49 ( struct V_25 * V_25 )
{
struct V_49 * V_57 = V_25 -> V_46 ;
if ( ! V_57 )
return NULL ;
return F_40 ( V_57 , struct V_27 , V_47 ) ;
}
static struct V_27 * F_50 ( struct V_27 * V_28 )
{
struct V_49 * V_58 = F_47 ( & V_28 -> V_47 ) ;
if ( ! V_58 )
return NULL ;
return F_40 ( V_58 , struct V_27 , V_47 ) ;
}
struct V_27 * F_51 ( struct V_25 * V_25 )
{
struct V_49 * V_59 = F_52 ( & V_25 -> V_51 ) ;
if ( ! V_59 )
return NULL ;
return F_40 ( V_59 , struct V_27 , V_47 ) ;
}
int F_53 ( struct V_60 * V_61 , int V_62 ,
void T_4 * V_63 , T_5 * V_64 ,
T_6 * V_65 )
{
int V_66 = F_54 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
unsigned int V_9 = F_4 () ;
if ( V_66 || ! V_62 )
return V_66 ;
V_67 = F_55 ( V_68 ,
V_69 ) ;
#define F_56 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_56 ( V_14 ) ;
F_56 ( V_15 ) ;
F_56 ( V_16 ) ;
#undef F_56
return 0 ;
}
static inline T_2 F_57 ( T_2 V_42 , struct V_27 * V_28 )
{
if ( F_13 ( V_28 -> V_70 . V_4 != V_71 ) )
V_42 = F_14 ( V_42 , V_71 , & V_28 -> V_70 ) ;
return V_42 ;
}
static T_2 F_58 ( unsigned long V_72 )
{
T_2 V_73 = V_68 ;
unsigned long V_74 = V_67 ;
if ( F_13 ( V_72 > V_74 ) ) {
V_73 = V_69 ;
V_73 *= V_72 ;
}
return V_73 ;
}
static T_2 F_59 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_75 = F_58 ( V_25 -> V_72 + ! V_28 -> V_76 ) ;
F_60 (se) {
struct V_1 * V_70 ;
struct V_1 V_2 ;
V_25 = F_23 ( V_28 ) ;
V_70 = & V_25 -> V_70 ;
if ( F_13 ( ! V_28 -> V_76 ) ) {
V_2 = V_25 -> V_70 ;
F_1 ( & V_2 , V_28 -> V_70 . V_4 ) ;
V_70 = & V_2 ;
}
V_75 = F_14 ( V_75 , V_28 -> V_70 . V_4 , V_70 ) ;
}
return V_75 ;
}
static T_2 F_61 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_57 ( F_59 ( V_25 , V_28 ) , V_28 ) ;
}
void F_62 ( struct V_26 * V_29 )
{
V_23 V_75 ;
V_75 = F_59 ( F_22 ( V_29 ) , & V_29 -> V_28 ) >> 10 ;
V_29 -> V_28 . V_77 . V_78 = V_29 -> V_28 . V_77 . V_79 = V_75 ;
V_29 -> V_28 . V_77 . V_80 = V_75 ;
F_63 ( & V_29 -> V_28 ) ;
F_64 ( & V_29 -> V_28 ) ;
}
void F_62 ( struct V_26 * V_29 )
{
}
static void F_65 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_81 = F_66 ( F_16 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_13 ( ! V_45 ) )
return;
V_19 = V_81 - V_45 -> V_82 ;
if ( F_13 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_82 = V_81 ;
F_67 ( V_45 -> V_83 . V_84 ,
F_68 ( V_19 , V_45 -> V_83 . V_84 ) ) ;
V_45 -> V_85 += V_19 ;
F_69 ( V_25 , V_86 , V_19 ) ;
V_45 -> V_41 += F_57 ( V_19 , V_45 ) ;
F_39 ( V_25 ) ;
if ( F_20 ( V_45 ) ) {
struct V_26 * V_87 = F_17 ( V_45 ) ;
F_70 ( V_87 , V_19 , V_45 -> V_41 ) ;
F_71 ( V_87 , V_19 ) ;
F_72 ( V_87 , V_19 ) ;
}
F_73 ( V_25 , V_19 ) ;
}
static void F_74 ( struct V_24 * V_24 )
{
F_65 ( F_23 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_83 . V_88 , F_76 ( F_16 ( V_25 ) ) ) ;
}
static void F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_75 ( V_25 , V_28 ) ;
}
static void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_83 . V_89 , F_68 ( V_28 -> V_83 . V_89 ,
F_76 ( F_16 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ) ;
F_67 ( V_28 -> V_83 . V_90 , V_28 -> V_83 . V_90 + 1 ) ;
F_67 ( V_28 -> V_83 . V_91 , V_28 -> V_83 . V_91 +
F_76 ( F_16 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
#ifdef F_79
if ( F_20 ( V_28 ) ) {
F_80 ( F_17 ( V_28 ) ,
F_76 ( F_16 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
}
#endif
F_67 ( V_28 -> V_83 . V_88 , 0 ) ;
}
static inline void
F_81 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_78 ( V_25 , V_28 ) ;
}
static inline void
F_82 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_82 = F_66 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_83 ( struct V_26 * V_29 )
{
unsigned long V_92 = 0 ;
unsigned long V_93 ;
V_93 = V_94 << ( 20 - V_95 ) ;
V_92 = F_84 ( V_29 -> V_96 ) ;
if ( ! V_92 )
V_92 = V_93 ;
V_92 = F_85 ( V_92 , V_93 ) ;
return V_92 / V_93 ;
}
static unsigned int F_86 ( struct V_26 * V_29 )
{
unsigned int V_97 = F_87 ( V_94 ) ;
unsigned int V_98 , floor ;
unsigned int V_99 = 1 ;
if ( V_97 < V_100 )
V_99 = V_100 / V_97 ;
floor = 1000 / V_99 ;
V_98 = V_101 / F_83 ( V_29 ) ;
return F_88 (unsigned int, floor, scan) ;
}
static unsigned int F_89 ( struct V_26 * V_29 )
{
unsigned int V_102 = F_86 ( V_29 ) ;
unsigned int V_103 ;
V_103 = V_104 / F_83 ( V_29 ) ;
return F_68 ( V_102 , V_103 ) ;
}
static void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_105 += ( V_29 -> V_106 != - 1 ) ;
V_24 -> V_107 += ( V_29 -> V_106 == F_91 ( V_29 ) ) ;
}
static void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_105 -= ( V_29 -> V_106 != - 1 ) ;
V_24 -> V_107 -= ( V_29 -> V_106 == F_91 ( V_29 ) ) ;
}
T_7 F_93 ( struct V_26 * V_29 )
{
return V_29 -> V_108 ? V_29 -> V_108 -> V_109 : 0 ;
}
static inline int F_94 ( enum V_110 V_111 , int V_112 , int V_113 )
{
return V_114 * ( V_111 * V_115 + V_112 ) + V_113 ;
}
static inline unsigned long F_95 ( struct V_26 * V_29 , int V_112 )
{
if ( ! V_29 -> V_116 )
return 0 ;
return V_29 -> V_116 [ F_94 ( V_117 , V_112 , 0 ) ] +
V_29 -> V_116 [ F_94 ( V_117 , V_112 , 1 ) ] ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_112 )
{
if ( ! V_29 -> V_108 )
return 0 ;
return V_29 -> V_108 -> V_118 [ F_94 ( V_117 , V_112 , 0 ) ] +
V_29 -> V_108 -> V_118 [ F_94 ( V_117 , V_112 , 1 ) ] ;
}
static inline unsigned long F_97 ( struct V_108 * V_119 , int V_112 )
{
return V_119 -> V_120 [ F_94 ( V_117 , V_112 , 0 ) ] +
V_119 -> V_120 [ F_94 ( V_117 , V_112 , 1 ) ] ;
}
static unsigned long F_98 ( struct V_26 * V_29 , int V_112 ,
int V_121 , bool V_122 )
{
unsigned long V_123 = 0 ;
int V_124 ;
if ( V_125 == V_126 )
return 0 ;
F_99 (node) {
unsigned long V_118 ;
int V_127 = F_100 ( V_112 , V_124 ) ;
if ( V_127 == V_128 || V_124 == V_112 )
continue;
if ( V_125 == V_129 &&
V_127 > V_121 )
continue;
if ( V_122 )
V_118 = F_95 ( V_29 , V_124 ) ;
else
V_118 = F_96 ( V_29 , V_124 ) ;
if ( V_125 == V_130 ) {
V_118 *= ( V_128 - V_127 ) ;
V_118 /= ( V_128 - V_131 ) ;
}
V_123 += V_118 ;
}
return V_123 ;
}
static inline unsigned long F_101 ( struct V_26 * V_29 , int V_112 ,
int V_127 )
{
unsigned long V_118 , V_132 ;
if ( ! V_29 -> V_116 )
return 0 ;
V_132 = V_29 -> V_133 ;
if ( ! V_132 )
return 0 ;
V_118 = F_95 ( V_29 , V_112 ) ;
V_118 += F_98 ( V_29 , V_112 , V_127 , true ) ;
return 1000 * V_118 / V_132 ;
}
static inline unsigned long F_102 ( struct V_26 * V_29 , int V_112 ,
int V_127 )
{
unsigned long V_118 , V_132 ;
if ( ! V_29 -> V_108 )
return 0 ;
V_132 = V_29 -> V_108 -> V_132 ;
if ( ! V_132 )
return 0 ;
V_118 = F_96 ( V_29 , V_112 ) ;
V_118 += F_98 ( V_29 , V_112 , V_127 , false ) ;
return 1000 * V_118 / V_132 ;
}
bool F_103 ( struct V_26 * V_29 , struct V_134 * V_134 ,
int V_135 , int V_136 )
{
struct V_108 * V_137 = V_29 -> V_108 ;
int V_138 = F_104 ( V_136 ) ;
int V_139 , V_140 ;
V_140 = F_105 ( V_136 , V_141 -> V_142 ) ;
V_139 = F_106 ( V_134 , V_140 ) ;
if ( ! F_107 ( V_139 ) &&
F_108 ( V_139 ) != V_138 )
return false ;
if ( F_109 ( V_29 , V_139 ) )
return true ;
if ( ! V_137 )
return true ;
if ( ! F_110 ( V_138 , V_137 -> V_143 ) )
return false ;
if ( ! F_110 ( V_135 , V_137 -> V_143 ) )
return true ;
return F_96 ( V_29 , V_138 ) < ( F_96 ( V_29 , V_135 ) * 3 / 4 ) ;
}
static void F_111 ( struct V_144 * V_145 , int V_112 )
{
int V_146 , V_147 , V_8 = 0 ;
unsigned long V_148 ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
F_112 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_113 ( V_147 ) ;
V_145 -> V_72 += V_24 -> V_72 ;
V_145 -> V_70 += F_114 ( V_147 ) ;
V_145 -> V_149 += F_115 ( V_147 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_146 = F_55 ( V_150 * V_8 , V_145 -> V_149 ) ;
V_148 = V_8 / V_146 ;
V_145 -> V_151 = F_5 ( unsigned , V_148 ,
F_116 ( V_145 -> V_149 , V_150 ) ) ;
V_145 -> V_152 = ( V_145 -> V_72 < V_145 -> V_151 ) ;
}
static void F_117 ( struct V_153 * V_154 ,
struct V_26 * V_29 , long V_155 )
{
if ( V_154 -> V_156 )
F_118 ( V_154 -> V_156 ) ;
if ( V_29 )
F_119 ( V_29 ) ;
V_154 -> V_156 = V_29 ;
V_154 -> V_157 = V_155 ;
V_154 -> V_158 = V_154 -> V_136 ;
}
static bool F_120 ( long V_159 , long V_160 ,
struct V_153 * V_154 )
{
long V_161 , V_162 ;
long V_163 , V_164 ;
long V_165 , V_166 ;
V_165 = V_154 -> V_167 . V_149 ;
V_166 = V_154 -> V_168 . V_149 ;
if ( V_160 < V_159 )
F_121 ( V_160 , V_159 ) ;
V_161 = V_160 * V_165 * 100 -
V_159 * V_166 * V_154 -> V_169 ;
if ( V_161 <= 0 )
return false ;
V_163 = V_154 -> V_167 . V_70 ;
V_164 = V_154 -> V_168 . V_70 ;
if ( V_164 < V_163 )
F_121 ( V_164 , V_163 ) ;
V_162 = V_164 * V_165 * 100 -
V_163 * V_166 * V_154 -> V_169 ;
return ( V_161 > V_162 ) ;
}
static void F_122 ( struct V_153 * V_154 ,
long V_170 , long V_171 )
{
struct V_24 * V_172 = F_113 ( V_154 -> V_173 ) ;
struct V_24 * V_174 = F_113 ( V_154 -> V_136 ) ;
struct V_26 * V_175 ;
long V_159 , V_160 ;
long V_70 ;
long V_155 = V_154 -> V_29 -> V_108 ? V_171 : V_170 ;
long V_176 = V_155 ;
int V_127 = V_154 -> V_127 ;
F_123 () ;
F_124 ( & V_174 -> V_177 ) ;
V_175 = V_174 -> V_45 ;
if ( ( V_175 -> V_178 & V_179 ) || F_125 ( V_175 ) )
V_175 = NULL ;
F_126 ( & V_174 -> V_177 ) ;
if ( V_175 == V_154 -> V_29 )
goto V_180;
if ( V_175 ) {
if ( ! F_127 ( V_154 -> V_173 , F_128 ( V_175 ) ) )
goto V_180;
if ( V_175 -> V_108 == V_154 -> V_29 -> V_108 ) {
V_155 = V_170 + F_101 ( V_175 , V_154 -> V_135 , V_127 ) -
F_101 ( V_175 , V_154 -> V_138 , V_127 ) ;
if ( V_175 -> V_108 )
V_155 -= V_155 / 16 ;
} else {
if ( V_175 -> V_108 )
V_155 += F_102 ( V_175 , V_154 -> V_135 , V_127 ) -
F_102 ( V_175 , V_154 -> V_138 , V_127 ) ;
else
V_155 += F_101 ( V_175 , V_154 -> V_135 , V_127 ) -
F_101 ( V_175 , V_154 -> V_138 , V_127 ) ;
}
}
if ( V_155 <= V_154 -> V_157 && V_176 <= V_154 -> V_157 )
goto V_180;
if ( ! V_175 ) {
if ( V_154 -> V_167 . V_72 <= V_154 -> V_167 . V_151 &&
! V_154 -> V_168 . V_152 )
goto V_180;
goto V_181;
}
if ( V_155 > V_154 -> V_157 && V_172 -> V_72 == 1 &&
V_174 -> V_72 == 1 )
goto V_182;
V_181:
V_70 = F_129 ( V_154 -> V_29 ) ;
V_160 = V_154 -> V_168 . V_70 + V_70 ;
V_159 = V_154 -> V_167 . V_70 - V_70 ;
if ( V_176 > V_155 && V_176 > V_154 -> V_157 ) {
if ( ! F_120 ( V_159 , V_160 , V_154 ) ) {
V_155 = V_176 - 1 ;
V_175 = NULL ;
goto V_182;
}
}
if ( V_155 <= V_154 -> V_157 )
goto V_180;
if ( V_175 ) {
V_70 = F_129 ( V_175 ) ;
V_160 -= V_70 ;
V_159 += V_70 ;
}
if ( F_120 ( V_159 , V_160 , V_154 ) )
goto V_180;
if ( ! V_175 )
V_154 -> V_136 = F_130 ( V_154 -> V_29 , V_154 -> V_136 ) ;
V_182:
F_117 ( V_154 , V_175 , V_155 ) ;
V_180:
F_131 () ;
}
static void F_132 ( struct V_153 * V_154 ,
long V_170 , long V_171 )
{
int V_147 ;
F_112 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_127 ( V_147 , F_128 ( V_154 -> V_29 ) ) )
continue;
V_154 -> V_136 = V_147 ;
F_122 ( V_154 , V_170 , V_171 ) ;
}
}
static bool F_133 ( struct V_153 * V_154 )
{
struct V_144 * V_183 = & V_154 -> V_167 ;
struct V_144 * V_184 = & V_154 -> V_168 ;
if ( V_183 -> V_152 && ! V_184 -> V_152 )
return false ;
if ( V_183 -> V_70 * V_184 -> V_149 >
V_184 -> V_70 * V_183 -> V_149 )
return true ;
return false ;
}
static int F_134 ( struct V_26 * V_29 )
{
struct V_153 V_154 = {
. V_29 = V_29 ,
. V_173 = F_135 ( V_29 ) ,
. V_135 = F_91 ( V_29 ) ,
. V_169 = 112 ,
. V_156 = NULL ,
. V_157 = 0 ,
. V_158 = - 1
} ;
struct V_185 * V_186 ;
unsigned long V_187 , V_188 ;
int V_112 , V_66 , V_127 ;
long V_170 , V_171 ;
F_123 () ;
V_186 = F_136 ( F_137 ( V_189 , V_154 . V_173 ) ) ;
if ( V_186 )
V_154 . V_169 = 100 + ( V_186 -> V_169 - 100 ) / 2 ;
F_131 () ;
if ( F_13 ( ! V_186 ) ) {
V_29 -> V_106 = F_91 ( V_29 ) ;
return - V_190 ;
}
V_154 . V_138 = V_29 -> V_106 ;
V_127 = V_154 . V_127 = F_100 ( V_154 . V_135 , V_154 . V_138 ) ;
V_187 = F_101 ( V_29 , V_154 . V_135 , V_127 ) ;
V_188 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
F_111 ( & V_154 . V_167 , V_154 . V_135 ) ;
V_170 = F_101 ( V_29 , V_154 . V_138 , V_127 ) - V_187 ;
V_171 = F_102 ( V_29 , V_154 . V_138 , V_127 ) - V_188 ;
F_111 ( & V_154 . V_168 , V_154 . V_138 ) ;
if ( F_133 ( & V_154 ) )
F_132 ( & V_154 , V_170 , V_171 ) ;
if ( V_154 . V_158 == - 1 || ( V_29 -> V_108 &&
F_138 ( V_29 -> V_108 -> V_143 ) > 1 ) ) {
F_99 (nid) {
if ( V_112 == V_154 . V_135 || V_112 == V_29 -> V_106 )
continue;
V_127 = F_100 ( V_154 . V_135 , V_154 . V_138 ) ;
if ( V_125 == V_129 &&
V_127 != V_154 . V_127 ) {
V_187 = F_101 ( V_29 , V_154 . V_135 , V_127 ) ;
V_188 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
}
V_170 = F_101 ( V_29 , V_112 , V_127 ) - V_187 ;
V_171 = F_102 ( V_29 , V_112 , V_127 ) - V_188 ;
if ( V_170 < 0 && V_171 < 0 )
continue;
V_154 . V_127 = V_127 ;
V_154 . V_138 = V_112 ;
F_111 ( & V_154 . V_168 , V_154 . V_138 ) ;
if ( F_133 ( & V_154 ) )
F_132 ( & V_154 , V_170 , V_171 ) ;
}
}
if ( V_29 -> V_108 ) {
if ( V_154 . V_158 == - 1 )
V_112 = V_154 . V_135 ;
else
V_112 = V_154 . V_138 ;
if ( F_110 ( V_112 , V_29 -> V_108 -> V_143 ) )
F_139 ( V_29 , V_154 . V_138 ) ;
}
if ( V_154 . V_158 == - 1 )
return - V_191 ;
V_29 -> V_192 = F_86 ( V_29 ) ;
if ( V_154 . V_156 == NULL ) {
V_66 = F_140 ( V_29 , V_154 . V_158 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_154 . V_173 , V_154 . V_158 ) ;
return V_66 ;
}
V_66 = F_142 ( V_29 , V_154 . V_156 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_154 . V_173 , F_135 ( V_154 . V_156 ) ) ;
F_118 ( V_154 . V_156 ) ;
return V_66 ;
}
static void F_143 ( struct V_26 * V_29 )
{
unsigned long V_193 = V_194 ;
if ( F_13 ( V_29 -> V_106 == - 1 || ! V_29 -> V_116 ) )
return;
V_193 = F_144 ( V_193 , F_145 ( V_29 -> V_192 ) / 16 ) ;
V_29 -> V_195 = V_196 + V_193 ;
if ( F_91 ( V_29 ) == V_29 -> V_106 )
return;
F_134 ( V_29 ) ;
}
static void F_146 ( struct V_108 * V_108 )
{
unsigned long V_118 , V_197 = 0 ;
int V_112 ;
F_99 (nid) {
V_118 = F_97 ( V_108 , V_112 ) ;
if ( V_118 > V_197 )
V_197 = V_118 ;
}
F_99 (nid) {
V_118 = F_97 ( V_108 , V_112 ) ;
if ( ! F_110 ( V_112 , V_108 -> V_143 ) ) {
if ( V_118 > V_197 * 6 / 16 )
F_147 ( V_112 , V_108 -> V_143 ) ;
} else if ( V_118 < V_197 * 3 / 16 )
F_148 ( V_112 , V_108 -> V_143 ) ;
}
}
static void F_149 ( struct V_26 * V_29 ,
unsigned long V_198 , unsigned long V_199 )
{
unsigned int V_200 ;
int V_201 ;
int V_202 ;
unsigned long V_203 = V_29 -> V_204 [ 0 ] ;
unsigned long V_205 = V_29 -> V_204 [ 1 ] ;
if ( V_205 + V_198 == 0 || V_29 -> V_204 [ 2 ] ) {
V_29 -> V_192 = F_144 ( V_29 -> V_206 ,
V_29 -> V_192 << 1 ) ;
V_29 -> V_96 -> V_207 = V_196 +
F_145 ( V_29 -> V_192 ) ;
return;
}
V_200 = F_55 ( V_29 -> V_192 , V_208 ) ;
V_201 = ( V_205 * V_208 ) / ( V_205 + V_203 ) ;
if ( V_201 >= V_209 ) {
int V_210 = V_201 - V_209 ;
if ( ! V_210 )
V_210 = 1 ;
V_202 = V_210 * V_200 ;
} else {
V_202 = - ( V_209 - V_201 ) * V_200 ;
V_201 = F_55 ( V_199 * V_208 , ( V_199 + V_198 + 1 ) ) ;
V_202 = ( V_202 * V_201 ) / V_208 ;
}
V_29 -> V_192 = F_150 ( V_29 -> V_192 + V_202 ,
F_86 ( V_29 ) , F_89 ( V_29 ) ) ;
memset ( V_29 -> V_204 , 0 , sizeof( V_29 -> V_204 ) ) ;
}
static T_2 F_151 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_211 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_211 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_212 ) {
V_42 = V_211 - V_29 -> V_213 ;
* V_73 = V_81 - V_29 -> V_212 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_78 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_213 = V_211 ;
V_29 -> V_212 = V_81 ;
return V_42 ;
}
static int F_152 ( struct V_26 * V_29 , int V_112 )
{
T_8 V_214 ;
int V_127 ;
if ( V_125 == V_126 )
return V_112 ;
if ( V_125 == V_130 ) {
unsigned long V_123 , V_215 = 0 ;
int V_124 , V_216 = V_112 ;
V_127 = V_128 ;
F_99 (node) {
V_123 = F_102 ( V_29 , V_124 , V_127 ) ;
if ( V_123 > V_215 ) {
V_215 = V_123 ;
V_216 = V_124 ;
}
}
return V_216 ;
}
V_214 = V_217 ;
for ( V_127 = V_128 ; V_127 > V_131 ; V_127 -- ) {
unsigned long V_197 = 0 ;
T_8 V_218 = V_219 ;
int V_43 , V_44 ;
if ( ! F_153 ( V_127 ) )
continue;
F_154 (a, nodes) {
unsigned long V_118 = 0 ;
T_8 V_220 ;
F_155 ( V_220 ) ;
F_154 (b, nodes) {
if ( F_100 ( V_43 , V_44 ) < V_127 ) {
V_118 += F_96 ( V_29 , V_44 ) ;
F_147 ( V_44 , V_220 ) ;
F_148 ( V_44 , V_214 ) ;
}
}
if ( V_118 > V_197 ) {
V_197 = V_118 ;
V_218 = V_220 ;
V_112 = V_43 ;
}
}
if ( ! V_197 )
break;
V_214 = V_218 ;
}
return V_112 ;
}
static void F_156 ( struct V_26 * V_29 )
{
int V_221 , V_112 , V_222 = - 1 , V_223 = - 1 ;
unsigned long V_197 = 0 , V_224 = 0 ;
unsigned long V_225 [ 2 ] = { 0 , 0 } ;
unsigned long V_132 ;
T_2 V_211 , V_73 ;
T_9 * V_226 = NULL ;
V_221 = F_87 ( V_29 -> V_96 -> V_227 ) ;
if ( V_29 -> V_227 == V_221 )
return;
V_29 -> V_227 = V_221 ;
V_29 -> V_206 = F_89 ( V_29 ) ;
V_132 = V_29 -> V_204 [ 0 ] +
V_29 -> V_204 [ 1 ] ;
V_211 = F_151 ( V_29 , & V_73 ) ;
if ( V_29 -> V_108 ) {
V_226 = & V_29 -> V_108 -> V_177 ;
F_157 ( V_226 ) ;
}
F_99 (nid) {
int V_228 , V_229 , V_230 , V_231 ;
unsigned long V_118 = 0 , F_96 = 0 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
long V_202 , V_232 , V_233 ;
V_228 = F_94 ( V_117 , V_112 , V_113 ) ;
V_229 = F_94 ( V_234 , V_112 , V_113 ) ;
V_230 = F_94 ( V_235 , V_112 , V_113 ) ;
V_231 = F_94 ( V_236 , V_112 , V_113 ) ;
V_202 = V_29 -> V_116 [ V_229 ] - V_29 -> V_116 [ V_228 ] / 2 ;
V_225 [ V_113 ] += V_29 -> V_116 [ V_229 ] ;
V_29 -> V_116 [ V_229 ] = 0 ;
V_233 = F_158 ( V_211 << 16 , V_73 + 1 ) ;
V_233 = ( V_233 * V_29 -> V_116 [ V_231 ] ) /
( V_132 + 1 ) ;
V_232 = V_233 - V_29 -> V_116 [ V_230 ] / 2 ;
V_29 -> V_116 [ V_231 ] = 0 ;
V_29 -> V_116 [ V_228 ] += V_202 ;
V_29 -> V_116 [ V_230 ] += V_232 ;
V_118 += V_29 -> V_116 [ V_228 ] ;
V_29 -> V_133 += V_202 ;
if ( V_29 -> V_108 ) {
V_29 -> V_108 -> V_118 [ V_228 ] += V_202 ;
V_29 -> V_108 -> V_120 [ V_228 ] += V_232 ;
V_29 -> V_108 -> V_132 += V_202 ;
F_96 += V_29 -> V_108 -> V_118 [ V_228 ] ;
}
}
if ( V_118 > V_197 ) {
V_197 = V_118 ;
V_222 = V_112 ;
}
if ( F_96 > V_224 ) {
V_224 = F_96 ;
V_223 = V_112 ;
}
}
F_149 ( V_29 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
if ( V_29 -> V_108 ) {
F_146 ( V_29 -> V_108 ) ;
F_159 ( V_226 ) ;
V_222 = F_152 ( V_29 , V_223 ) ;
}
if ( V_197 ) {
if ( V_222 != V_29 -> V_106 )
F_139 ( V_29 , V_222 ) ;
if ( F_91 ( V_29 ) != V_29 -> V_106 )
F_143 ( V_29 ) ;
}
}
static inline int F_160 ( struct V_108 * V_30 )
{
return F_161 ( & V_30 -> V_237 ) ;
}
static inline void F_162 ( struct V_108 * V_30 )
{
if ( F_163 ( & V_30 -> V_237 ) )
F_164 ( V_30 , V_238 ) ;
}
static void F_165 ( struct V_26 * V_29 , int V_239 , int V_178 ,
int * V_113 )
{
struct V_108 * V_30 , * V_240 ;
struct V_26 * V_241 ;
bool V_242 = false ;
int V_147 = F_166 ( V_239 ) ;
int V_243 ;
if ( F_13 ( ! V_29 -> V_108 ) ) {
unsigned int V_244 = sizeof( struct V_108 ) +
4 * V_115 *sizeof( unsigned long ) ;
V_30 = F_167 ( V_244 , V_245 | V_246 ) ;
if ( ! V_30 )
return;
F_168 ( & V_30 -> V_237 , 1 ) ;
F_169 ( & V_30 -> V_177 ) ;
V_30 -> V_109 = V_29 -> V_142 ;
V_30 -> V_120 = V_30 -> V_118 + V_114 *
V_115 ;
F_147 ( F_91 ( V_141 ) , V_30 -> V_143 ) ;
for ( V_243 = 0 ; V_243 < V_247 * V_115 ; V_243 ++ )
V_30 -> V_118 [ V_243 ] = V_29 -> V_116 [ V_243 ] ;
V_30 -> V_132 = V_29 -> V_133 ;
V_30 -> V_248 ++ ;
F_170 ( V_29 -> V_108 , V_30 ) ;
}
F_123 () ;
V_241 = F_87 ( F_113 ( V_147 ) -> V_45 ) ;
if ( ! F_109 ( V_241 , V_239 ) )
goto V_249;
V_30 = F_136 ( V_241 -> V_108 ) ;
if ( ! V_30 )
goto V_249;
V_240 = V_29 -> V_108 ;
if ( V_30 == V_240 )
goto V_249;
if ( V_240 -> V_248 > V_30 -> V_248 )
goto V_249;
if ( V_240 -> V_248 == V_30 -> V_248 && V_240 > V_30 )
goto V_249;
if ( V_241 -> V_96 == V_141 -> V_96 )
V_242 = true ;
if ( V_178 & V_250 )
V_242 = true ;
* V_113 = ! V_242 ;
if ( V_242 && ! F_160 ( V_30 ) )
goto V_249;
F_131 () ;
if ( ! V_242 )
return;
F_171 ( F_172 () ) ;
F_173 ( & V_240 -> V_177 , & V_30 -> V_177 ) ;
for ( V_243 = 0 ; V_243 < V_247 * V_115 ; V_243 ++ ) {
V_240 -> V_118 [ V_243 ] -= V_29 -> V_116 [ V_243 ] ;
V_30 -> V_118 [ V_243 ] += V_29 -> V_116 [ V_243 ] ;
}
V_240 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_132 += V_29 -> V_133 ;
V_240 -> V_248 -- ;
V_30 -> V_248 ++ ;
F_174 ( & V_240 -> V_177 ) ;
F_159 ( & V_30 -> V_177 ) ;
F_170 ( V_29 -> V_108 , V_30 ) ;
F_162 ( V_240 ) ;
return;
V_249:
F_131 () ;
return;
}
void F_175 ( struct V_26 * V_29 )
{
struct V_108 * V_30 = V_29 -> V_108 ;
void * V_116 = V_29 -> V_116 ;
unsigned long V_178 ;
int V_243 ;
if ( V_30 ) {
F_176 ( & V_30 -> V_177 , V_178 ) ;
for ( V_243 = 0 ; V_243 < V_247 * V_115 ; V_243 ++ )
V_30 -> V_118 [ V_243 ] -= V_29 -> V_116 [ V_243 ] ;
V_30 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_248 -- ;
F_177 ( & V_30 -> V_177 , V_178 ) ;
F_178 ( V_29 -> V_108 , NULL ) ;
F_162 ( V_30 ) ;
}
V_29 -> V_116 = NULL ;
F_179 ( V_116 ) ;
}
void F_180 ( int V_139 , int V_251 , int V_252 , int V_178 )
{
struct V_26 * V_29 = V_141 ;
bool V_253 = V_178 & V_254 ;
int V_255 = F_91 ( V_141 ) ;
int V_205 = ! ! ( V_178 & V_256 ) ;
int V_113 ;
if ( ! V_257 )
return;
if ( ! V_29 -> V_96 )
return;
if ( F_13 ( ! V_29 -> V_116 ) ) {
int V_244 = sizeof( * V_29 -> V_116 ) *
V_258 * V_115 ;
V_29 -> V_116 = F_167 ( V_244 , V_245 | V_246 ) ;
if ( ! V_29 -> V_116 )
return;
V_29 -> V_133 = 0 ;
memset ( V_29 -> V_204 , 0 , sizeof( V_29 -> V_204 ) ) ;
}
if ( F_13 ( V_139 == ( - 1 & V_259 ) ) ) {
V_113 = 1 ;
} else {
V_113 = F_109 ( V_29 , V_139 ) ;
if ( ! V_113 && ! ( V_178 & V_260 ) )
F_165 ( V_29 , V_139 , V_178 , & V_113 ) ;
}
if ( ! V_113 && ! V_205 && V_29 -> V_108 &&
F_110 ( V_255 , V_29 -> V_108 -> V_143 ) &&
F_110 ( V_251 , V_29 -> V_108 -> V_143 ) )
V_205 = 1 ;
F_156 ( V_29 ) ;
if ( F_181 ( V_196 , V_29 -> V_195 ) )
F_143 ( V_29 ) ;
if ( V_253 )
V_29 -> V_261 += V_252 ;
if ( V_178 & V_262 )
V_29 -> V_204 [ 2 ] += V_252 ;
V_29 -> V_116 [ F_94 ( V_234 , V_251 , V_113 ) ] += V_252 ;
V_29 -> V_116 [ F_94 ( V_236 , V_255 , V_113 ) ] += V_252 ;
V_29 -> V_204 [ V_205 ] += V_252 ;
}
static void F_182 ( struct V_26 * V_29 )
{
F_183 ( V_29 -> V_96 -> V_227 , F_87 ( V_29 -> V_96 -> V_227 ) + 1 ) ;
V_29 -> V_96 -> V_263 = 0 ;
}
void F_184 ( struct V_264 * V_265 )
{
unsigned long V_266 , V_267 , V_81 = V_196 ;
struct V_26 * V_29 = V_141 ;
struct V_268 * V_96 = V_29 -> V_96 ;
struct V_269 * V_270 ;
unsigned long V_271 , V_272 ;
unsigned long V_273 = 0 ;
long V_252 ;
F_19 ( V_29 != F_21 ( V_265 , struct V_26 , V_274 ) ) ;
V_265 -> V_58 = V_265 ;
if ( V_29 -> V_178 & V_179 )
return;
if ( ! V_96 -> V_207 ) {
V_96 -> V_207 = V_81 +
F_145 ( V_275 ) ;
}
V_266 = V_96 -> V_207 ;
if ( F_185 ( V_81 , V_266 ) )
return;
if ( V_29 -> V_192 == 0 ) {
V_29 -> V_206 = F_89 ( V_29 ) ;
V_29 -> V_192 = F_86 ( V_29 ) ;
}
V_267 = V_81 + F_145 ( V_29 -> V_192 ) ;
if ( F_186 ( & V_96 -> V_207 , V_266 , V_267 ) != V_266 )
return;
V_29 -> V_276 += 2 * V_277 ;
V_271 = V_96 -> V_263 ;
V_252 = V_94 ;
V_252 <<= 20 - V_95 ;
if ( ! V_252 )
return;
F_187 ( & V_96 -> V_278 ) ;
V_270 = F_188 ( V_96 , V_271 ) ;
if ( ! V_270 ) {
F_182 ( V_29 ) ;
V_271 = 0 ;
V_270 = V_96 -> V_279 ;
}
for (; V_270 ; V_270 = V_270 -> V_280 ) {
if ( ! F_189 ( V_270 ) || ! F_190 ( V_270 ) ||
F_191 ( V_270 ) || ( V_270 -> V_281 & V_282 ) ) {
continue;
}
if ( ! V_270 -> V_283 ||
( V_270 -> V_284 && ( V_270 -> V_281 & ( V_285 | V_286 ) ) == ( V_285 ) ) )
continue;
if ( ! ( V_270 -> V_281 & ( V_285 | V_287 | V_286 ) ) )
continue;
do {
V_271 = F_68 ( V_271 , V_270 -> V_288 ) ;
V_272 = F_192 ( V_271 + ( V_252 << V_95 ) , V_289 ) ;
V_272 = F_144 ( V_272 , V_270 -> V_290 ) ;
V_273 += F_193 ( V_270 , V_271 , V_272 ) ;
if ( V_273 )
V_252 -= ( V_272 - V_271 ) >> V_95 ;
V_271 = V_272 ;
if ( V_252 <= 0 )
goto V_291;
F_194 () ;
} while ( V_272 != V_270 -> V_290 );
}
V_291:
if ( V_270 )
V_96 -> V_263 = V_271 ;
else
F_182 ( V_29 ) ;
F_195 ( & V_96 -> V_278 ) ;
}
void F_196 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_264 * V_265 = & V_45 -> V_274 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_178 & V_179 ) || V_265 -> V_58 != V_265 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_192 * V_292 ;
if ( V_81 - V_45 -> V_276 > V_73 ) {
if ( ! V_45 -> V_276 )
V_45 -> V_192 = F_86 ( V_45 ) ;
V_45 -> V_276 += V_73 ;
if ( ! F_185 ( V_196 , V_45 -> V_96 -> V_207 ) ) {
F_197 ( V_265 , F_184 ) ;
F_198 ( V_45 , V_265 , true ) ;
}
}
}
static void F_196 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_199 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_33 ( V_28 ) )
F_1 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_200
if ( F_20 ( V_28 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_90 ( V_24 , F_17 ( V_28 ) ) ;
F_201 ( & V_28 -> V_293 , & V_24 -> V_294 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_202 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_33 ( V_28 ) )
F_2 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_20 ( V_28 ) ) {
F_92 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_203 ( & V_28 -> V_293 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_204 ( struct V_295 * V_33 , struct V_25 * V_25 )
{
long V_296 ;
V_296 = F_205 ( & V_33 -> V_297 ) ;
V_296 -= V_25 -> V_298 ;
V_296 += V_25 -> V_70 . V_4 ;
return V_296 ;
}
static long F_206 ( struct V_25 * V_25 , struct V_295 * V_33 )
{
long V_296 , V_70 , V_299 ;
V_296 = F_204 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_299 = ( V_33 -> V_299 * V_70 ) ;
if ( V_296 )
V_299 /= V_296 ;
if ( V_299 < V_300 )
V_299 = V_300 ;
if ( V_299 > V_33 -> V_299 )
V_299 = V_33 -> V_299 ;
return V_299 ;
}
static inline long F_206 ( struct V_25 * V_25 , struct V_295 * V_33 )
{
return V_33 -> V_299 ;
}
static void F_207 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_202 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_199 ( V_25 , V_28 ) ;
}
static void F_208 ( struct V_25 * V_25 )
{
struct V_295 * V_33 ;
struct V_27 * V_28 ;
long V_299 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_209 ( V_25 ) )
return;
#ifndef F_200
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_299 ) )
return;
#endif
V_299 = F_206 ( V_25 , V_33 ) ;
F_207 ( F_23 ( V_28 ) , V_28 , V_299 ) ;
}
static inline void F_208 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_210 ( T_2 V_301 , T_2 V_302 )
{
unsigned int V_303 ;
if ( ! V_302 )
return V_301 ;
else if ( F_13 ( V_302 > V_304 * 63 ) )
return 0 ;
V_303 = V_302 ;
if ( F_13 ( V_303 >= V_304 ) ) {
V_301 >>= V_303 / V_304 ;
V_303 %= V_304 ;
}
V_301 *= V_305 [ V_303 ] ;
return V_301 >> 32 ;
}
static V_23 F_211 ( T_2 V_302 )
{
V_23 V_306 = 0 ;
if ( F_11 ( V_302 <= V_304 ) )
return V_307 [ V_302 ] ;
else if ( F_13 ( V_302 >= V_308 ) )
return V_309 ;
do {
V_306 /= 2 ;
V_306 += V_307 [ V_304 ] ;
V_302 -= V_304 ;
} while ( V_302 > V_304 );
V_306 = F_210 ( V_306 , V_302 ) ;
return V_306 + V_307 [ V_302 ] ;
}
static T_10 int F_212 ( T_2 V_81 , int V_147 ,
struct V_310 * V_311 ,
int V_312 ,
int V_313 )
{
T_2 V_42 , V_314 ;
V_23 V_315 ;
int V_316 , V_317 = 0 ;
unsigned long V_318 = F_213 ( NULL , V_147 ) ;
V_42 = V_81 - V_311 -> V_319 ;
if ( ( T_3 ) V_42 < 0 ) {
V_311 -> V_319 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_311 -> V_319 = V_81 ;
V_316 = V_311 -> V_80 % 1024 ;
if ( V_42 + V_316 >= 1024 ) {
V_317 = 1 ;
V_316 = 1024 - V_316 ;
if ( V_312 )
V_311 -> V_78 += V_316 ;
if ( V_313 )
V_311 -> V_79 += V_316 * V_318
>> V_320 ;
V_311 -> V_80 += V_316 ;
V_42 -= V_316 ;
V_314 = V_42 / 1024 ;
V_42 %= 1024 ;
V_311 -> V_78 = F_210 ( V_311 -> V_78 ,
V_314 + 1 ) ;
V_311 -> V_79 = F_210 ( V_311 -> V_79 ,
V_314 + 1 ) ;
V_311 -> V_80 = F_210 ( V_311 -> V_80 ,
V_314 + 1 ) ;
V_315 = F_211 ( V_314 ) ;
if ( V_312 )
V_311 -> V_78 += V_315 ;
if ( V_313 )
V_311 -> V_79 += V_315 * V_318
>> V_320 ;
V_311 -> V_80 += V_315 ;
}
if ( V_312 )
V_311 -> V_78 += V_42 ;
if ( V_313 )
V_311 -> V_79 += V_42 * V_318
>> V_320 ;
V_311 -> V_80 += V_42 ;
return V_317 ;
}
static inline T_2 F_214 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_321 = F_215 ( & V_25 -> V_322 ) ;
V_321 -= V_28 -> V_77 . V_323 ;
V_28 -> V_77 . V_323 = 0 ;
if ( ! V_321 )
return 0 ;
V_28 -> V_77 . V_324 = F_210 ( V_28 -> V_77 . V_324 , V_321 ) ;
V_28 -> V_77 . V_325 =
F_210 ( V_28 -> V_77 . V_325 , V_321 ) ;
return V_321 ;
}
static inline void F_216 ( struct V_25 * V_25 ,
int V_326 )
{
struct V_295 * V_33 = V_25 -> V_33 ;
long V_327 ;
V_327 = V_25 -> V_328 + V_25 -> V_329 ;
V_327 -= V_25 -> V_298 ;
if ( ! V_327 )
return;
if ( V_326 || abs ( V_327 ) > V_25 -> V_298 / 8 ) {
F_217 ( V_327 , & V_33 -> V_297 ) ;
V_25 -> V_298 += V_327 ;
}
}
static inline void F_218 ( struct V_310 * V_311 ,
struct V_25 * V_25 )
{
struct V_295 * V_33 = V_25 -> V_33 ;
long V_306 ;
V_306 = F_219 ( ( T_2 ) V_311 -> V_78 << V_330 ,
V_311 -> V_80 + 1 ) ;
V_306 -= V_25 -> V_331 ;
if ( abs ( V_306 ) > V_25 -> V_331 / 64 ) {
F_220 ( V_306 , & V_33 -> V_332 ) ;
V_25 -> V_331 += V_306 ;
}
}
static inline void F_221 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
struct V_295 * V_33 = V_25 -> V_33 ;
int V_332 ;
T_2 V_306 ;
V_306 = V_25 -> V_298 * V_33 -> V_299 ;
V_28 -> V_77 . V_324 = F_219 ( V_306 ,
F_205 ( & V_33 -> V_297 ) + 1 ) ;
V_332 = F_222 ( & V_33 -> V_332 ) ;
if ( V_332 < V_71 ) {
V_28 -> V_77 . V_324 *= V_332 ;
V_28 -> V_77 . V_324 >>= V_330 ;
}
}
static inline void F_223 ( struct V_24 * V_24 , int V_312 )
{
F_212 ( F_66 ( V_24 ) , F_26 ( V_24 ) , & V_24 -> V_77 ,
V_312 , V_312 ) ;
F_218 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_216 ( struct V_25 * V_25 ,
int V_326 ) {}
static inline void F_218 ( struct V_310 * V_311 ,
struct V_25 * V_25 ) {}
static inline void F_221 ( struct V_27 * V_28 ) {}
static inline void F_223 ( struct V_24 * V_24 , int V_312 ) {}
static inline void F_63 ( struct V_27 * V_28 )
{
V_23 V_306 ;
V_306 = V_28 -> V_77 . V_78 * F_12 ( V_28 -> V_70 . V_4 ) ;
V_306 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_324 = F_224 ( V_306 ) ;
}
static long F_225 ( struct V_27 * V_28 )
{
long V_333 = V_28 -> V_77 . V_324 ;
if ( F_20 ( V_28 ) ) {
F_63 ( V_28 ) ;
} else {
F_218 ( & V_28 -> V_77 , F_24 ( V_28 ) ) ;
F_221 ( V_28 ) ;
}
return V_28 -> V_77 . V_324 - V_333 ;
}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_306 ;
V_306 = V_28 -> V_77 . V_79 * F_12 ( V_334 ) ;
V_306 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_325 = F_224 ( V_306 ) ;
}
static long F_226 ( struct V_27 * V_28 )
{
long V_333 = V_28 -> V_77 . V_325 ;
if ( F_20 ( V_28 ) )
F_64 ( V_28 ) ;
else
V_28 -> V_77 . V_325 =
F_24 ( V_28 ) -> V_335 ;
return V_28 -> V_77 . V_325 - V_333 ;
}
static inline void F_227 ( struct V_25 * V_25 ,
long V_336 )
{
if ( F_11 ( V_336 < V_25 -> V_329 ) )
V_25 -> V_329 -= V_336 ;
else
V_25 -> V_329 = 0 ;
}
static inline void F_228 ( struct V_27 * V_28 ,
int V_337 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
long V_338 , V_339 ;
int V_147 = F_26 ( F_16 ( V_25 ) ) ;
T_2 V_81 ;
if ( F_20 ( V_28 ) )
V_81 = F_229 ( V_25 ) ;
else
V_81 = F_229 ( F_24 ( V_28 ) ) ;
if ( ! F_212 ( V_81 , V_147 , & V_28 -> V_77 , V_28 -> V_76 ,
V_25 -> V_45 == V_28 ) )
return;
V_338 = F_225 ( V_28 ) ;
V_339 = F_226 ( V_28 ) ;
if ( ! V_337 )
return;
if ( V_28 -> V_76 ) {
V_25 -> V_328 += V_338 ;
V_25 -> V_335 += V_339 ;
} else {
F_227 ( V_25 , - V_338 ) ;
}
}
static void F_29 ( struct V_25 * V_25 , int V_326 )
{
T_2 V_81 = F_229 ( V_25 ) >> 20 ;
T_2 V_321 ;
V_321 = V_81 - V_25 -> V_340 ;
if ( ! V_321 && ! V_326 )
return;
if ( F_205 ( & V_25 -> V_341 ) ) {
unsigned long V_341 ;
V_341 = F_230 ( & V_25 -> V_341 , 0 ) ;
F_227 ( V_25 , V_341 ) ;
}
if ( V_321 ) {
V_25 -> V_329 = F_210 ( V_25 -> V_329 ,
V_321 ) ;
F_231 ( V_321 , & V_25 -> V_322 ) ;
V_25 -> V_340 = V_81 ;
}
F_216 ( V_25 , V_326 ) ;
}
static inline void F_232 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_342 )
{
if ( F_13 ( V_28 -> V_77 . V_323 <= 0 ) ) {
V_28 -> V_77 . V_319 = F_66 ( F_16 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_323 ) {
V_28 -> V_77 . V_319 -= ( - V_28 -> V_77 . V_323 )
<< 20 ;
F_228 ( V_28 , 0 ) ;
V_28 -> V_77 . V_323 = 0 ;
}
V_342 = 0 ;
} else {
F_214 ( V_28 ) ;
}
if ( V_342 ) {
F_227 ( V_25 , V_28 -> V_77 . V_324 ) ;
F_228 ( V_28 , 0 ) ;
}
V_25 -> V_328 += V_28 -> V_77 . V_324 ;
V_25 -> V_335 += V_28 -> V_77 . V_325 ;
F_29 ( V_25 , ! V_342 ) ;
}
static inline void F_233 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_343 )
{
F_228 ( V_28 , 1 ) ;
F_29 ( V_25 , ! V_343 ) ;
V_25 -> V_328 -= V_28 -> V_77 . V_324 ;
V_25 -> V_335 -= V_28 -> V_77 . V_325 ;
if ( V_343 ) {
V_25 -> V_329 += V_28 -> V_77 . V_324 ;
V_28 -> V_77 . V_323 = F_215 ( & V_25 -> V_322 ) ;
}
}
void F_234 ( struct V_24 * V_344 )
{
F_223 ( V_344 , 1 ) ;
}
void F_235 ( struct V_24 * V_344 )
{
F_223 ( V_344 , 0 ) ;
}
static inline void F_228 ( struct V_27 * V_28 ,
int V_337 ) {}
static inline void F_223 ( struct V_24 * V_24 , int V_312 ) {}
static inline void F_232 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_342 ) {}
static inline void F_233 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_343 ) {}
static inline void F_29 ( struct V_25 * V_25 ,
int V_326 ) {}
static inline int F_236 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_237 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_79
struct V_26 * V_241 = NULL ;
if ( F_20 ( V_28 ) )
V_241 = F_17 ( V_28 ) ;
if ( V_28 -> V_83 . V_345 ) {
T_2 V_42 = F_76 ( F_16 ( V_25 ) ) - V_28 -> V_83 . V_345 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_83 . V_346 ) )
V_28 -> V_83 . V_346 = V_42 ;
V_28 -> V_83 . V_345 = 0 ;
V_28 -> V_83 . V_347 += V_42 ;
if ( V_241 ) {
F_238 ( V_241 , V_42 >> 10 , 1 ) ;
F_239 ( V_241 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_348 ) {
T_2 V_42 = F_76 ( F_16 ( V_25 ) ) - V_28 -> V_83 . V_348 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_83 . V_349 ) )
V_28 -> V_83 . V_349 = V_42 ;
V_28 -> V_83 . V_348 = 0 ;
V_28 -> V_83 . V_347 += V_42 ;
if ( V_241 ) {
if ( V_241 -> V_350 ) {
V_28 -> V_83 . V_351 += V_42 ;
V_28 -> V_83 . V_352 ++ ;
F_240 ( V_241 , V_42 ) ;
}
F_241 ( V_241 , V_42 ) ;
if ( F_13 ( V_353 == V_354 ) ) {
F_242 ( V_354 ,
( void * ) F_243 ( V_241 ) ,
V_42 >> 20 ) ;
}
F_238 ( V_241 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_244 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_355 = V_28 -> V_41 - V_25 -> F_37 ;
if ( V_355 < 0 )
V_355 = - V_355 ;
if ( V_355 > 3 * V_68 )
F_245 ( V_25 , V_356 ) ;
#endif
}
static void
F_246 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_357 )
{
T_2 V_41 = V_25 -> F_37 ;
if ( V_357 && F_247 ( V_358 ) )
V_41 += F_61 ( V_25 , V_28 ) ;
if ( ! V_357 ) {
unsigned long V_359 = V_68 ;
if ( F_247 ( V_360 ) )
V_359 >>= 1 ;
V_41 -= V_359 ;
}
V_28 -> V_41 = F_36 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_248 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_178 )
{
if ( ! ( V_178 & V_361 ) || ( V_178 & V_362 ) )
V_28 -> V_41 += V_25 -> F_37 ;
F_65 ( V_25 ) ;
F_232 ( V_25 , V_28 , V_178 & V_361 ) ;
F_199 ( V_25 , V_28 ) ;
F_208 ( V_25 ) ;
if ( V_178 & V_361 ) {
F_246 ( V_25 , V_28 , 0 ) ;
F_237 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_244 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_43 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_249 ( V_25 ) ;
}
}
static void F_250 ( struct V_27 * V_28 )
{
F_60 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_251 ( struct V_27 * V_28 )
{
F_60 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_252 ( struct V_27 * V_28 )
{
F_60 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_363 != V_28 )
break;
V_25 -> V_363 = NULL ;
}
}
static void F_253 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_250 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_251 ( V_28 ) ;
if ( V_25 -> V_363 == V_28 )
F_252 ( V_28 ) ;
}
static void
F_254 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_178 )
{
F_65 ( V_25 ) ;
F_233 ( V_25 , V_28 , V_178 & V_364 ) ;
F_81 ( V_25 , V_28 ) ;
if ( V_178 & V_364 ) {
#ifdef F_79
if ( F_20 ( V_28 ) ) {
struct V_26 * V_241 = F_17 ( V_28 ) ;
if ( V_241 -> V_365 & V_366 )
V_28 -> V_83 . V_345 = F_76 ( F_16 ( V_25 ) ) ;
if ( V_241 -> V_365 & V_367 )
V_28 -> V_83 . V_348 = F_76 ( F_16 ( V_25 ) ) ;
}
#endif
}
F_253 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_46 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_202 ( V_25 , V_28 ) ;
if ( ! ( V_178 & V_364 ) )
V_28 -> V_41 -= V_25 -> F_37 ;
F_255 ( V_25 ) ;
F_39 ( V_25 ) ;
F_208 ( V_25 ) ;
}
static void
F_256 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_368 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_368 = F_59 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_369 ;
if ( V_19 > V_368 ) {
F_257 ( F_16 ( V_25 ) ) ;
F_253 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_49 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_368 )
F_257 ( F_16 ( V_25 ) ) ;
}
static void
F_258 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_78 ( V_25 , V_28 ) ;
F_46 ( V_25 , V_28 ) ;
F_228 ( V_28 , 1 ) ;
}
F_82 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_79
if ( F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_370 = F_68 ( V_28 -> V_83 . V_370 ,
V_28 -> V_85 - V_28 -> V_369 ) ;
}
#endif
V_28 -> V_369 = V_28 -> V_85 ;
}
static struct V_27 *
F_259 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_49 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_38 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_363 == V_28 ) {
struct V_27 * V_371 ;
if ( V_28 == V_45 ) {
V_371 = F_49 ( V_25 ) ;
} else {
V_371 = F_50 ( V_28 ) ;
if ( ! V_371 || ( V_45 && F_38 ( V_45 , V_371 ) ) )
V_371 = V_45 ;
}
if ( V_371 && F_260 ( V_371 , V_57 ) < 1 )
V_28 = V_371 ;
}
if ( V_25 -> V_59 && F_260 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_260 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_253 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_261 ( struct V_25 * V_25 , struct V_27 * V_372 )
{
if ( V_372 -> V_76 )
F_65 ( V_25 ) ;
F_262 ( V_25 ) ;
F_244 ( V_25 , V_372 ) ;
if ( V_372 -> V_76 ) {
F_75 ( V_25 , V_372 ) ;
F_43 ( V_25 , V_372 ) ;
F_228 ( V_372 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_263 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_373 )
{
F_65 ( V_25 ) ;
F_228 ( V_45 , 1 ) ;
F_29 ( V_25 , 1 ) ;
F_208 ( V_25 ) ;
#ifdef F_264
if ( V_373 ) {
F_257 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_247 ( V_374 ) &&
F_265 ( & F_16 ( V_25 ) -> V_375 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_256 ( V_25 , V_45 ) ;
}
static inline bool F_266 ( void )
{
return F_267 ( & V_376 ) ;
}
void F_268 ( void )
{
F_269 ( & V_376 ) ;
}
void F_270 ( void )
{
F_271 ( & V_376 ) ;
}
static bool F_266 ( void )
{
return true ;
}
void F_268 ( void ) {}
void F_270 ( void ) {}
static inline T_2 F_272 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_273 ( void )
{
return ( T_2 ) V_377 * V_378 ;
}
void F_274 ( struct V_379 * V_380 )
{
T_2 V_81 ;
if ( V_380 -> V_381 == V_382 )
return;
V_81 = F_275 ( F_276 () ) ;
V_380 -> V_211 = V_380 -> V_381 ;
V_380 -> V_383 = V_81 + F_277 ( V_380 -> V_73 ) ;
}
static inline struct V_379 * F_278 ( struct V_295 * V_33 )
{
return & V_33 -> V_379 ;
}
static inline T_2 F_229 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_384 ) )
return V_25 -> V_385 ;
return F_66 ( F_16 ( V_25 ) ) - V_25 -> V_386 ;
}
static int F_279 ( struct V_25 * V_25 )
{
struct V_295 * V_33 = V_25 -> V_33 ;
struct V_379 * V_380 = F_278 ( V_33 ) ;
T_2 V_387 = 0 , V_388 , V_389 ;
V_388 = F_273 () - V_25 -> V_390 ;
F_280 ( & V_380 -> V_177 ) ;
if ( V_380 -> V_381 == V_382 )
V_387 = V_388 ;
else {
F_281 ( V_380 ) ;
if ( V_380 -> V_211 > 0 ) {
V_387 = F_144 ( V_380 -> V_211 , V_388 ) ;
V_380 -> V_211 -= V_387 ;
V_380 -> V_391 = 0 ;
}
}
V_389 = V_380 -> V_383 ;
F_282 ( & V_380 -> V_177 ) ;
V_25 -> V_390 += V_387 ;
if ( ( T_3 ) ( V_389 - V_25 -> V_383 ) > 0 )
V_25 -> V_383 = V_389 ;
return V_25 -> V_390 > 0 ;
}
static void F_283 ( struct V_25 * V_25 )
{
struct V_379 * V_380 = F_278 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_76 ( F_16 ( V_25 ) ) - V_25 -> V_383 ) < 0 ) )
return;
if ( V_25 -> V_390 < 0 )
return;
if ( V_25 -> V_383 != V_380 -> V_383 ) {
V_25 -> V_383 += V_277 ;
} else {
V_25 -> V_390 = 0 ;
}
}
static void F_284 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_390 -= V_19 ;
F_283 ( V_25 ) ;
if ( F_11 ( V_25 -> V_390 > 0 ) )
return;
if ( ! F_279 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_257 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_266 () || ! V_25 -> V_392 )
return;
F_284 ( V_25 , V_19 ) ;
}
static inline int F_285 ( struct V_25 * V_25 )
{
return F_266 () && V_25 -> V_393 ;
}
static inline int F_209 ( struct V_25 * V_25 )
{
return F_266 () && V_25 -> V_384 ;
}
static inline int F_286 ( struct V_295 * V_33 ,
int V_173 , int V_394 )
{
struct V_25 * V_395 , * V_396 ;
V_395 = V_33 -> V_25 [ V_173 ] ;
V_396 = V_33 -> V_25 [ V_394 ] ;
return F_209 ( V_395 ) ||
F_209 ( V_396 ) ;
}
static int F_287 ( struct V_295 * V_33 , void * V_397 )
{
struct V_24 * V_24 = V_397 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_384 -- ;
#ifdef F_200
if ( ! V_25 -> V_384 ) {
V_25 -> V_386 += F_66 ( V_24 ) -
V_25 -> V_385 ;
}
#endif
return 0 ;
}
static int F_288 ( struct V_295 * V_33 , void * V_397 )
{
struct V_24 * V_24 = V_397 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_384 )
V_25 -> V_385 = F_66 ( V_24 ) ;
V_25 -> V_384 ++ ;
return 0 ;
}
static void F_289 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_379 * V_380 = F_278 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_398 , V_399 = 1 ;
bool V_400 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_123 () ;
F_290 ( V_25 -> V_33 , F_288 , V_401 , ( void * ) V_24 ) ;
F_131 () ;
V_398 = V_25 -> V_402 ;
F_60 (se) {
struct V_25 * V_403 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_399 )
F_254 ( V_403 , V_28 , V_364 ) ;
V_403 -> V_402 -= V_398 ;
if ( V_403 -> V_70 . V_4 )
V_399 = 0 ;
}
if ( ! V_28 )
F_291 ( V_24 , V_398 ) ;
V_25 -> V_393 = 1 ;
V_25 -> V_404 = F_76 ( V_24 ) ;
F_280 ( & V_380 -> V_177 ) ;
V_400 = F_292 ( & V_380 -> V_405 ) ;
F_27 ( & V_25 -> V_406 , & V_380 -> V_405 ) ;
if ( V_400 )
F_281 ( V_380 ) ;
F_282 ( & V_380 -> V_177 ) ;
}
void F_293 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_379 * V_380 = F_278 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_407 = 1 ;
long V_398 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_393 = 0 ;
F_294 ( V_24 ) ;
F_280 ( & V_380 -> V_177 ) ;
V_380 -> V_408 += F_76 ( V_24 ) - V_25 -> V_404 ;
F_31 ( & V_25 -> V_406 ) ;
F_282 ( & V_380 -> V_177 ) ;
F_290 ( V_25 -> V_33 , V_401 , F_287 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_398 = V_25 -> V_402 ;
F_60 (se) {
if ( V_28 -> V_76 )
V_407 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_407 )
F_248 ( V_25 , V_28 , V_361 ) ;
V_25 -> V_402 += V_398 ;
if ( F_285 ( V_25 ) )
break;
}
if ( ! V_28 )
F_295 ( V_24 , V_398 ) ;
if ( V_24 -> V_45 == V_24 -> V_391 && V_24 -> V_40 . V_72 )
F_257 ( V_24 ) ;
}
static T_2 F_296 ( struct V_379 * V_380 ,
T_2 V_409 , T_2 V_389 )
{
struct V_25 * V_25 ;
T_2 V_211 ;
T_2 V_410 = V_409 ;
F_123 () ;
F_297 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_280 ( & V_24 -> V_177 ) ;
if ( ! F_285 ( V_25 ) )
goto V_58;
V_211 = - V_25 -> V_390 + 1 ;
if ( V_211 > V_409 )
V_211 = V_409 ;
V_409 -= V_211 ;
V_25 -> V_390 += V_211 ;
V_25 -> V_383 = V_389 ;
if ( V_25 -> V_390 > 0 )
F_293 ( V_25 ) ;
V_58:
F_282 ( & V_24 -> V_177 ) ;
if ( ! V_409 )
break;
}
F_131 () ;
return V_410 - V_409 ;
}
static int F_298 ( struct V_379 * V_380 , int V_411 )
{
T_2 V_211 , V_383 ;
int V_393 ;
if ( V_380 -> V_381 == V_382 )
goto V_412;
V_393 = ! F_292 ( & V_380 -> V_405 ) ;
V_380 -> V_413 += V_411 ;
if ( V_380 -> V_391 && ! V_393 )
goto V_412;
F_274 ( V_380 ) ;
if ( ! V_393 ) {
V_380 -> V_391 = 1 ;
return 0 ;
}
V_380 -> V_414 += V_411 ;
V_383 = V_380 -> V_383 ;
while ( V_393 && V_380 -> V_211 > 0 ) {
V_211 = V_380 -> V_211 ;
F_282 ( & V_380 -> V_177 ) ;
V_211 = F_296 ( V_380 , V_211 ,
V_383 ) ;
F_280 ( & V_380 -> V_177 ) ;
V_393 = ! F_292 ( & V_380 -> V_405 ) ;
V_380 -> V_211 -= F_144 ( V_211 , V_380 -> V_211 ) ;
}
V_380 -> V_391 = 0 ;
return 0 ;
V_412:
return 1 ;
}
static int F_299 ( struct V_379 * V_380 , T_2 V_415 )
{
struct V_416 * V_417 = & V_380 -> V_418 ;
T_2 V_409 ;
if ( F_300 ( V_417 ) )
return 1 ;
V_409 = F_277 ( F_301 ( V_417 ) ) ;
if ( V_409 < V_415 )
return 1 ;
return 0 ;
}
static void F_302 ( struct V_379 * V_380 )
{
T_2 V_419 = V_420 + V_421 ;
if ( F_299 ( V_380 , V_419 ) )
return;
F_303 ( & V_380 -> V_422 ,
F_304 ( V_420 ) ,
V_423 ) ;
}
static void F_305 ( struct V_25 * V_25 )
{
struct V_379 * V_380 = F_278 ( V_25 -> V_33 ) ;
T_3 V_424 = V_25 -> V_390 - V_425 ;
if ( V_424 <= 0 )
return;
F_280 ( & V_380 -> V_177 ) ;
if ( V_380 -> V_381 != V_382 &&
V_25 -> V_383 == V_380 -> V_383 ) {
V_380 -> V_211 += V_424 ;
if ( V_380 -> V_211 > F_273 () &&
! F_292 ( & V_380 -> V_405 ) )
F_302 ( V_380 ) ;
}
F_282 ( & V_380 -> V_177 ) ;
V_25 -> V_390 -= V_424 ;
}
static T_10 void F_255 ( struct V_25 * V_25 )
{
if ( ! F_266 () )
return;
if ( ! V_25 -> V_392 || V_25 -> V_72 )
return;
F_305 ( V_25 ) ;
}
static void F_306 ( struct V_379 * V_380 )
{
T_2 V_211 = 0 , V_75 = F_273 () ;
T_2 V_389 ;
F_280 ( & V_380 -> V_177 ) ;
if ( F_299 ( V_380 , V_421 ) ) {
F_282 ( & V_380 -> V_177 ) ;
return;
}
if ( V_380 -> V_381 != V_382 && V_380 -> V_211 > V_75 )
V_211 = V_380 -> V_211 ;
V_389 = V_380 -> V_383 ;
F_282 ( & V_380 -> V_177 ) ;
if ( ! V_211 )
return;
V_211 = F_296 ( V_380 , V_211 , V_389 ) ;
F_280 ( & V_380 -> V_177 ) ;
if ( V_389 == V_380 -> V_383 )
V_380 -> V_211 -= F_144 ( V_211 , V_380 -> V_211 ) ;
F_282 ( & V_380 -> V_177 ) ;
}
static void F_249 ( struct V_25 * V_25 )
{
if ( ! F_266 () )
return;
if ( ! V_25 -> V_392 || V_25 -> V_45 )
return;
if ( F_285 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_390 <= 0 )
F_289 ( V_25 ) ;
}
static bool F_262 ( struct V_25 * V_25 )
{
if ( ! F_266 () )
return false ;
if ( F_11 ( ! V_25 -> V_392 || V_25 -> V_390 > 0 ) )
return false ;
if ( F_285 ( V_25 ) )
return true ;
F_289 ( V_25 ) ;
return true ;
}
static enum V_426 F_307 ( struct V_416 * V_427 )
{
struct V_379 * V_380 =
F_21 ( V_427 , struct V_379 , V_422 ) ;
F_306 ( V_380 ) ;
return V_428 ;
}
static enum V_426 F_308 ( struct V_416 * V_427 )
{
struct V_379 * V_380 =
F_21 ( V_427 , struct V_379 , V_418 ) ;
int V_411 ;
int V_391 = 0 ;
F_280 ( & V_380 -> V_177 ) ;
for (; ; ) {
V_411 = F_309 ( V_427 , V_380 -> V_73 ) ;
if ( ! V_411 )
break;
V_391 = F_298 ( V_380 , V_411 ) ;
}
if ( V_391 )
V_380 -> V_429 = 0 ;
F_282 ( & V_380 -> V_177 ) ;
return V_391 ? V_428 : V_430 ;
}
void F_310 ( struct V_379 * V_380 )
{
F_311 ( & V_380 -> V_177 ) ;
V_380 -> V_211 = 0 ;
V_380 -> V_381 = V_382 ;
V_380 -> V_73 = F_304 ( F_272 () ) ;
F_312 ( & V_380 -> V_405 ) ;
F_313 ( & V_380 -> V_418 , V_431 , V_432 ) ;
V_380 -> V_418 . V_433 = F_308 ;
F_313 ( & V_380 -> V_422 , V_431 , V_423 ) ;
V_380 -> V_422 . V_433 = F_307 ;
}
static void F_314 ( struct V_25 * V_25 )
{
V_25 -> V_392 = 0 ;
F_312 ( & V_25 -> V_406 ) ;
}
void F_281 ( struct V_379 * V_380 )
{
F_315 ( & V_380 -> V_177 ) ;
if ( ! V_380 -> V_429 ) {
V_380 -> V_429 = 1 ;
F_309 ( & V_380 -> V_418 , V_380 -> V_73 ) ;
F_316 ( & V_380 -> V_418 , V_432 ) ;
}
}
static void F_317 ( struct V_379 * V_380 )
{
if ( ! V_380 -> V_405 . V_58 )
return;
F_318 ( & V_380 -> V_418 ) ;
F_318 ( & V_380 -> V_422 ) ;
}
static void T_11 F_319 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_320 (rq, cfs_rq) {
struct V_379 * V_380 = & V_25 -> V_33 -> V_379 ;
F_280 ( & V_380 -> V_177 ) ;
V_25 -> V_392 = V_380 -> V_381 != V_382 ;
F_282 ( & V_380 -> V_177 ) ;
}
}
static void T_11 F_321 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_320 (rq, cfs_rq) {
if ( ! V_25 -> V_392 )
continue;
V_25 -> V_390 = 1 ;
V_25 -> V_392 = 0 ;
if ( F_285 ( V_25 ) )
F_293 ( V_25 ) ;
}
}
static inline T_2 F_229 ( struct V_25 * V_25 )
{
return F_66 ( F_16 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_262 ( struct V_25 * V_25 ) { return false ; }
static void F_249 ( struct V_25 * V_25 ) {}
static T_10 void F_255 ( struct V_25 * V_25 ) {}
static inline int F_285 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_209 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_286 ( struct V_295 * V_33 ,
int V_173 , int V_394 )
{
return 0 ;
}
void F_310 ( struct V_379 * V_380 ) {}
static void F_314 ( struct V_25 * V_25 ) {}
static inline struct V_379 * F_278 ( struct V_295 * V_33 )
{
return NULL ;
}
static inline void F_317 ( struct V_379 * V_380 ) {}
static inline void F_319 ( struct V_24 * V_24 ) {}
static inline void F_321 ( struct V_24 * V_24 ) {}
static void F_322 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_323 ( F_35 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_59 ( V_25 , V_28 ) ;
T_2 V_434 = V_28 -> V_85 - V_28 -> V_369 ;
T_3 V_42 = V_75 - V_434 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_257 ( V_24 ) ;
return;
}
F_324 ( V_24 , V_42 ) ;
}
}
static void F_325 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_326 ( V_24 ) || V_45 -> V_435 != & V_436 )
return;
if ( F_23 ( & V_45 -> V_28 ) -> V_72 < V_67 )
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
F_327 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_178 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_60 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_23 ( V_28 ) ;
F_248 ( V_25 , V_28 , V_178 ) ;
if ( F_285 ( V_25 ) )
break;
V_25 -> V_402 ++ ;
V_178 = V_361 ;
}
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_402 ++ ;
if ( F_285 ( V_25 ) )
break;
F_208 ( V_25 ) ;
F_228 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_223 ( V_24 , V_24 -> V_72 ) ;
F_295 ( V_24 , 1 ) ;
}
F_325 ( V_24 ) ;
}
static void F_328 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_178 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_437 = V_178 & V_364 ;
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
F_254 ( V_25 , V_28 , V_178 ) ;
if ( F_285 ( V_25 ) )
break;
V_25 -> V_402 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_437 && F_33 ( V_28 ) )
F_329 ( F_33 ( V_28 ) ) ;
V_28 = F_33 ( V_28 ) ;
break;
}
V_178 |= V_364 ;
}
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_402 -- ;
if ( F_285 ( V_25 ) )
break;
F_208 ( V_25 ) ;
F_228 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_291 ( V_24 , 1 ) ;
F_223 ( V_24 , 1 ) ;
}
F_325 ( V_24 ) ;
}
static unsigned long
F_330 ( unsigned long V_70 , unsigned long V_438 , int V_439 )
{
int V_440 = 0 ;
if ( ! V_438 )
return V_70 ;
if ( V_438 >= V_441 [ V_439 ] )
return 0 ;
if ( V_439 == 1 )
return V_70 >> V_438 ;
while ( V_438 ) {
if ( V_438 % 2 )
V_70 = ( V_70 * V_442 [ V_439 ] [ V_440 ] ) >> V_443 ;
V_438 >>= 1 ;
V_440 ++ ;
}
return V_70 ;
}
static void F_331 ( struct V_24 * V_344 , unsigned long V_444 ,
unsigned long V_445 )
{
int V_243 , V_446 ;
V_344 -> V_447 ++ ;
V_344 -> V_448 [ 0 ] = V_444 ;
for ( V_243 = 1 , V_446 = 2 ; V_243 < V_449 ; V_243 ++ , V_446 += V_446 ) {
unsigned long V_450 , V_451 ;
V_450 = V_344 -> V_448 [ V_243 ] ;
V_450 = F_330 ( V_450 , V_445 - 1 , V_243 ) ;
V_451 = V_444 ;
if ( V_451 > V_450 )
V_451 += V_446 - 1 ;
V_344 -> V_448 [ V_243 ] = ( V_450 * ( V_446 - 1 ) + V_451 ) >> V_243 ;
}
F_332 ( V_344 ) ;
}
static void F_333 ( struct V_24 * V_344 )
{
unsigned long V_452 = F_87 ( V_196 ) ;
unsigned long V_70 = V_344 -> V_40 . V_328 ;
unsigned long V_445 ;
if ( V_70 || V_452 == V_344 -> V_453 )
return;
V_445 = V_452 - V_344 -> V_453 ;
V_344 -> V_453 = V_452 ;
F_331 ( V_344 , V_70 , V_445 ) ;
}
void F_334 ( void )
{
struct V_24 * V_344 = V_344 () ;
unsigned long V_452 = F_87 ( V_196 ) ;
unsigned long V_445 ;
if ( V_452 == V_344 -> V_453 )
return;
F_280 ( & V_344 -> V_177 ) ;
V_445 = V_452 - V_344 -> V_453 ;
if ( V_445 ) {
V_344 -> V_453 = V_452 ;
F_331 ( V_344 , 0 , V_445 ) ;
}
F_282 ( & V_344 -> V_177 ) ;
}
void F_335 ( struct V_24 * V_344 )
{
unsigned long V_70 = V_344 -> V_40 . V_328 ;
V_344 -> V_453 = V_196 ;
F_331 ( V_344 , V_70 , 1 ) ;
}
static unsigned long F_114 ( const int V_147 )
{
return F_113 ( V_147 ) -> V_40 . V_328 ;
}
static unsigned long F_336 ( int V_147 , int type )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_454 = F_114 ( V_147 ) ;
if ( type == 0 || ! F_247 ( V_455 ) )
return V_454 ;
return F_144 ( V_24 -> V_448 [ type - 1 ] , V_454 ) ;
}
static unsigned long F_337 ( int V_147 , int type )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_454 = F_114 ( V_147 ) ;
if ( type == 0 || ! F_247 ( V_455 ) )
return V_454 ;
return F_68 ( V_24 -> V_448 [ type - 1 ] , V_454 ) ;
}
static unsigned long F_115 ( int V_147 )
{
return F_113 ( V_147 ) -> V_456 ;
}
static unsigned long F_338 ( int V_147 )
{
return F_113 ( V_147 ) -> V_457 ;
}
static unsigned long F_339 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_72 = F_87 ( V_24 -> V_40 . V_402 ) ;
unsigned long V_297 = V_24 -> V_40 . V_328 ;
if ( V_72 )
return V_297 / V_72 ;
return 0 ;
}
static void F_340 ( struct V_26 * V_29 )
{
if ( F_181 ( V_196 , V_141 -> V_458 + V_194 ) ) {
V_141 -> V_459 >>= 1 ;
V_141 -> V_458 = V_196 ;
}
if ( V_141 -> V_460 != V_29 ) {
V_141 -> V_460 = V_29 ;
V_141 -> V_459 ++ ;
}
}
static void F_341 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 F_37 ;
#ifndef F_41
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_342 () ;
F_37 = V_25 -> F_37 ;
} while ( F_37 != V_48 );
#else
F_37 = V_25 -> F_37 ;
#endif
V_28 -> V_41 -= F_37 ;
F_340 ( V_29 ) ;
}
static long F_343 ( struct V_295 * V_33 , int V_147 , long V_461 , long V_462 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
if ( ! V_33 -> V_34 )
return V_461 ;
F_60 (se) {
long V_7 , V_463 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_463 = V_462 + F_204 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_461 ;
if ( V_463 > 0 && V_7 < V_463 )
V_461 = ( V_7 * ( long ) V_33 -> V_299 ) / V_463 ;
else
V_461 = V_33 -> V_299 ;
if ( V_461 < V_300 )
V_461 = V_300 ;
V_461 -= V_28 -> V_70 . V_4 ;
V_462 = 0 ;
}
return V_461 ;
}
static long F_343 ( struct V_295 * V_33 , int V_147 , long V_461 , long V_462 )
{
return V_461 ;
}
static int F_344 ( struct V_26 * V_29 )
{
int V_9 = F_345 ( V_464 ) ;
if ( V_29 -> V_459 > V_9 ) {
if ( V_141 -> V_459 > ( V_9 * V_29 -> V_459 ) )
return 1 ;
}
return 0 ;
}
static int F_346 ( struct V_185 * V_186 , struct V_26 * V_29 , int V_465 )
{
T_3 V_444 , V_70 ;
T_3 V_466 , V_467 ;
int V_439 , V_468 , V_469 ;
struct V_295 * V_33 ;
unsigned long V_4 ;
int V_470 ;
if ( F_344 ( V_29 ) )
return 0 ;
V_439 = V_186 -> V_471 ;
V_468 = F_276 () ;
V_469 = F_135 ( V_29 ) ;
V_70 = F_336 ( V_469 , V_439 ) ;
V_444 = F_337 ( V_468 , V_439 ) ;
if ( V_465 ) {
V_33 = V_295 ( V_141 ) ;
V_4 = V_141 -> V_28 . V_70 . V_4 ;
V_444 += F_343 ( V_33 , V_468 , - V_4 , - V_4 ) ;
V_70 += F_343 ( V_33 , V_469 , 0 , - V_4 ) ;
}
V_33 = V_295 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
V_466 = 100 ;
V_466 *= F_115 ( V_469 ) ;
V_467 = 100 + ( V_186 -> V_169 - 100 ) / 2 ;
V_467 *= F_115 ( V_468 ) ;
if ( V_444 > 0 ) {
V_466 *= V_444 +
F_343 ( V_33 , V_468 , V_4 , V_4 ) ;
V_467 *= V_70 + F_343 ( V_33 , V_469 , 0 , V_4 ) ;
}
V_470 = V_466 <= V_467 ;
F_245 ( V_29 , V_28 . V_83 . V_472 ) ;
if ( ! V_470 )
return 0 ;
F_245 ( V_186 , V_473 ) ;
F_245 ( V_29 , V_28 . V_83 . V_474 ) ;
return 1 ;
}
static struct V_475 *
F_347 ( struct V_185 * V_186 , struct V_26 * V_29 ,
int V_468 , int V_476 )
{
struct V_475 * V_477 = NULL , * V_119 = V_186 -> V_478 ;
unsigned long V_479 = V_480 , V_444 = 0 ;
int V_481 = V_186 -> V_482 ;
int V_483 = 100 + ( V_186 -> V_169 - 100 ) / 2 ;
if ( V_476 & V_484 )
V_481 = V_186 -> V_471 ;
do {
unsigned long V_70 , V_485 ;
int V_486 ;
int V_243 ;
if ( ! F_348 ( F_349 ( V_119 ) ,
F_128 ( V_29 ) ) )
continue;
V_486 = F_127 ( V_468 ,
F_349 ( V_119 ) ) ;
V_485 = 0 ;
F_112 (i, sched_group_cpus(group)) {
if ( V_486 )
V_70 = F_336 ( V_243 , V_481 ) ;
else
V_70 = F_337 ( V_243 , V_481 ) ;
V_485 += V_70 ;
}
V_485 = ( V_485 * V_150 ) / V_119 -> V_487 -> V_148 ;
if ( V_486 ) {
V_444 = V_485 ;
} else if ( V_485 < V_479 ) {
V_479 = V_485 ;
V_477 = V_119 ;
}
} while ( V_119 = V_119 -> V_58 , V_119 != V_186 -> V_478 );
if ( ! V_477 || 100 * V_444 < V_483 * V_479 )
return NULL ;
return V_477 ;
}
static int
F_350 ( struct V_475 * V_119 , struct V_26 * V_29 , int V_468 )
{
unsigned long V_70 , V_479 = V_480 ;
unsigned int V_488 = V_489 ;
T_2 V_490 = 0 ;
int V_491 = V_468 ;
int V_492 = - 1 ;
int V_243 ;
F_351 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_352 ( V_243 ) ) {
struct V_24 * V_24 = F_113 ( V_243 ) ;
struct V_493 * V_391 = F_353 ( V_24 ) ;
if ( V_391 && V_391 -> V_494 < V_488 ) {
V_488 = V_391 -> V_494 ;
V_490 = V_24 -> V_495 ;
V_492 = V_243 ;
} else if ( ( ! V_391 || V_391 -> V_494 == V_488 ) &&
V_24 -> V_495 > V_490 ) {
V_490 = V_24 -> V_495 ;
V_492 = V_243 ;
}
} else if ( V_492 == - 1 ) {
V_70 = F_114 ( V_243 ) ;
if ( V_70 < V_479 || ( V_70 == V_479 && V_243 == V_468 ) ) {
V_479 = V_70 ;
V_491 = V_243 ;
}
}
}
return V_492 != - 1 ? V_492 : V_491 ;
}
static int F_130 ( struct V_26 * V_29 , int V_496 )
{
struct V_185 * V_186 ;
struct V_475 * V_497 ;
int V_243 = F_135 ( V_29 ) ;
if ( F_352 ( V_496 ) )
return V_496 ;
if ( V_243 != V_496 && F_354 ( V_243 , V_496 ) && F_352 ( V_243 ) )
return V_243 ;
V_186 = F_136 ( F_137 ( V_498 , V_496 ) ) ;
F_355 (sd) {
V_497 = V_186 -> V_478 ;
do {
if ( ! F_348 ( F_349 ( V_497 ) ,
F_128 ( V_29 ) ) )
goto V_58;
F_112 (i, sched_group_cpus(sg)) {
if ( V_243 == V_496 || ! F_352 ( V_243 ) )
goto V_58;
}
V_496 = F_356 ( F_349 ( V_497 ) ,
F_128 ( V_29 ) ) ;
goto V_499;
V_58:
V_497 = V_497 -> V_58 ;
} while ( V_497 != V_186 -> V_478 );
}
V_499:
return V_496 ;
}
static int F_357 ( int V_147 )
{
unsigned long V_500 = F_113 ( V_147 ) -> V_40 . V_335 ;
unsigned long V_148 = F_338 ( V_147 ) ;
if ( V_500 >= V_334 )
return V_148 ;
return ( V_500 * V_148 ) >> V_501 ;
}
static int
F_358 ( struct V_26 * V_29 , int V_469 , int V_476 , int V_502 )
{
struct V_185 * V_503 , * V_504 = NULL , * V_186 = NULL ;
int V_147 = F_276 () ;
int V_505 = V_147 ;
int V_506 = 0 ;
int V_465 = V_502 & V_507 ;
if ( V_476 & V_484 )
V_506 = F_127 ( V_147 , F_128 ( V_29 ) ) ;
F_123 () ;
F_359 (cpu, tmp) {
if ( ! ( V_503 -> V_178 & V_508 ) )
continue;
if ( V_506 && ( V_503 -> V_178 & V_509 ) &&
F_127 ( V_469 , F_360 ( V_503 ) ) ) {
V_504 = V_503 ;
break;
}
if ( V_503 -> V_178 & V_476 )
V_186 = V_503 ;
}
if ( V_504 && V_147 != V_469 && F_346 ( V_504 , V_29 , V_465 ) )
V_469 = V_147 ;
if ( V_476 & V_484 ) {
V_505 = F_130 ( V_29 , V_469 ) ;
goto V_180;
}
while ( V_186 ) {
struct V_475 * V_119 ;
int V_4 ;
if ( ! ( V_186 -> V_178 & V_476 ) ) {
V_186 = V_186 -> V_510 ;
continue;
}
V_119 = F_347 ( V_186 , V_29 , V_147 , V_476 ) ;
if ( ! V_119 ) {
V_186 = V_186 -> V_510 ;
continue;
}
V_505 = F_350 ( V_119 , V_29 , V_147 ) ;
if ( V_505 == - 1 || V_505 == V_147 ) {
V_186 = V_186 -> V_510 ;
continue;
}
V_147 = V_505 ;
V_4 = V_186 -> V_511 ;
V_186 = NULL ;
F_359 (cpu, tmp) {
if ( V_4 <= V_503 -> V_511 )
break;
if ( V_503 -> V_178 & V_476 )
V_186 = V_503 ;
}
}
V_180:
F_131 () ;
return V_505 ;
}
static void
F_361 ( struct V_26 * V_29 , int V_512 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_28 -> V_77 . V_323 ) {
V_28 -> V_77 . V_323 = - F_214 ( V_28 ) ;
F_217 ( V_28 -> V_77 . V_324 ,
& V_25 -> V_341 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_362 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_513 = V_514 ;
return F_57 ( V_513 , V_28 ) ;
}
static int
F_260 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_513 , V_515 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_515 <= 0 )
return - 1 ;
V_513 = F_362 ( V_45 , V_28 ) ;
if ( V_515 > V_513 )
return 1 ;
return 0 ;
}
static void F_363 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_516 == V_517 ) )
return;
F_60 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_329 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_516 == V_517 ) )
return;
F_60 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_364 ( struct V_27 * V_28 )
{
F_60 (se)
F_23 ( V_28 ) -> V_363 = V_28 ;
}
static void F_365 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_502 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_446 = V_25 -> V_72 >= V_67 ;
int V_518 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_209 ( F_23 ( V_36 ) ) ) )
return;
if ( F_247 ( V_519 ) && V_446 && ! ( V_502 & V_520 ) ) {
F_329 ( V_36 ) ;
V_518 = 1 ;
}
if ( F_366 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_516 == V_517 ) &&
F_11 ( V_29 -> V_516 != V_517 ) )
goto V_521;
if ( F_13 ( V_29 -> V_516 != V_522 ) || ! F_247 ( V_523 ) )
return;
F_34 ( & V_28 , & V_36 ) ;
F_65 ( F_23 ( V_28 ) ) ;
F_171 ( ! V_36 ) ;
if ( F_260 ( V_28 , V_36 ) == 1 ) {
if ( ! V_518 )
F_329 ( V_36 ) ;
goto V_521;
}
return;
V_521:
F_257 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_76 || V_45 == V_24 -> V_391 ) )
return;
if ( F_247 ( V_524 ) && V_446 && F_20 ( V_28 ) )
F_363 ( V_28 ) ;
}
static struct V_26 *
F_367 ( struct V_24 * V_24 , struct V_26 * V_372 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_525 ;
V_526:
#ifdef F_368
if ( ! V_25 -> V_72 )
goto V_391;
if ( V_372 -> V_435 != & V_436 )
goto V_527;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_262 ( V_25 ) ) )
goto V_527;
}
V_28 = F_259 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_372 != V_29 ) {
struct V_27 * V_36 = & V_372 -> V_28 ;
while ( ! ( V_25 = F_32 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_261 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_33 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_258 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_33 ( V_28 ) ;
}
}
F_261 ( V_25 , V_36 ) ;
F_258 ( V_25 , V_28 ) ;
}
if ( F_326 ( V_24 ) )
F_322 ( V_24 , V_29 ) ;
return V_29 ;
V_527:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_391;
F_369 ( V_24 , V_372 ) ;
do {
V_28 = F_259 ( V_25 , NULL ) ;
F_258 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_326 ( V_24 ) )
F_322 ( V_24 , V_29 ) ;
return V_29 ;
V_391:
F_370 ( & V_24 -> V_177 ) ;
V_525 = F_236 ( V_24 ) ;
F_371 ( & V_24 -> V_177 ) ;
if ( V_525 < 0 )
return V_528 ;
if ( V_525 > 0 )
goto V_526;
return NULL ;
}
static void F_372 ( struct V_24 * V_24 , struct V_26 * V_372 )
{
struct V_27 * V_28 = & V_372 -> V_28 ;
struct V_25 * V_25 ;
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
F_261 ( V_25 , V_28 ) ;
}
}
static void F_373 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_253 ( V_25 , V_28 ) ;
if ( V_45 -> V_516 != V_529 ) {
F_294 ( V_24 ) ;
F_65 ( V_25 ) ;
F_374 ( V_24 , true ) ;
}
F_364 ( V_28 ) ;
}
static bool F_375 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_521 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_209 ( F_23 ( V_28 ) ) )
return false ;
F_329 ( V_28 ) ;
F_373 ( V_24 ) ;
return true ;
}
static int F_376 ( struct V_26 * V_29 , struct V_530 * V_154 )
{
T_3 V_42 ;
F_315 ( & V_154 -> V_172 -> V_177 ) ;
if ( V_29 -> V_435 != & V_436 )
return 0 ;
if ( F_13 ( V_29 -> V_516 == V_517 ) )
return 0 ;
if ( F_247 ( V_531 ) && V_154 -> V_174 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_532 == - 1 )
return 1 ;
if ( V_532 == 0 )
return 0 ;
V_42 = F_66 ( V_154 -> V_172 ) - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_532 ;
}
static bool F_377 ( struct V_26 * V_29 , struct V_530 * V_154 )
{
struct V_108 * V_108 = F_136 ( V_29 -> V_108 ) ;
unsigned long V_533 , V_534 ;
int V_135 , V_138 ;
if ( ! F_247 ( V_535 ) || ! V_29 -> V_116 ||
! ( V_154 -> V_186 -> V_178 & V_536 ) ) {
return false ;
}
V_135 = F_104 ( V_154 -> V_173 ) ;
V_138 = F_104 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_138 == V_29 -> V_106 )
return true ;
if ( V_135 == V_29 -> V_106 )
return false ;
if ( V_108 ) {
V_533 = F_96 ( V_29 , V_135 ) ;
V_534 = F_96 ( V_29 , V_138 ) ;
} else {
V_533 = F_95 ( V_29 , V_135 ) ;
V_534 = F_95 ( V_29 , V_138 ) ;
}
return V_534 > V_533 ;
}
static bool F_378 ( struct V_26 * V_29 , struct V_530 * V_154 )
{
struct V_108 * V_108 = F_136 ( V_29 -> V_108 ) ;
unsigned long V_533 , V_534 ;
int V_135 , V_138 ;
if ( ! F_247 ( V_537 ) || ! F_247 ( V_538 ) )
return false ;
if ( ! V_29 -> V_116 || ! ( V_154 -> V_186 -> V_178 & V_536 ) )
return false ;
V_135 = F_104 ( V_154 -> V_173 ) ;
V_138 = F_104 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_135 == V_29 -> V_106 )
return true ;
if ( V_138 == V_29 -> V_106 )
return false ;
if ( V_108 ) {
V_533 = F_96 ( V_29 , V_135 ) ;
V_534 = F_96 ( V_29 , V_138 ) ;
} else {
V_533 = F_95 ( V_29 , V_135 ) ;
V_534 = F_95 ( V_29 , V_138 ) ;
}
return V_534 < V_533 ;
}
static inline bool F_377 ( struct V_26 * V_29 ,
struct V_530 * V_154 )
{
return false ;
}
static inline bool F_378 ( struct V_26 * V_29 ,
struct V_530 * V_154 )
{
return false ;
}
static
int F_379 ( struct V_26 * V_29 , struct V_530 * V_154 )
{
int V_539 = 0 ;
F_315 ( & V_154 -> V_172 -> V_177 ) ;
if ( F_286 ( V_295 ( V_29 ) , V_154 -> V_173 , V_154 -> V_136 ) )
return 0 ;
if ( ! F_127 ( V_154 -> V_136 , F_128 ( V_29 ) ) ) {
int V_147 ;
F_245 ( V_29 , V_28 . V_83 . V_540 ) ;
V_154 -> V_178 |= V_541 ;
if ( ! V_154 -> V_542 || ( V_154 -> V_178 & V_543 ) )
return 0 ;
F_351 (cpu, env->dst_grpmask, env->cpus) {
if ( F_127 ( V_147 , F_128 ( V_29 ) ) ) {
V_154 -> V_178 |= V_543 ;
V_154 -> V_544 = V_147 ;
break;
}
}
return 0 ;
}
V_154 -> V_178 &= ~ V_545 ;
if ( F_380 ( V_154 -> V_172 , V_29 ) ) {
F_245 ( V_29 , V_28 . V_83 . V_546 ) ;
return 0 ;
}
V_539 = F_376 ( V_29 , V_154 ) ;
if ( ! V_539 )
V_539 = F_378 ( V_29 , V_154 ) ;
if ( F_377 ( V_29 , V_154 ) || ! V_539 ||
V_154 -> V_186 -> V_547 > V_154 -> V_186 -> V_548 ) {
if ( V_539 ) {
F_245 ( V_154 -> V_186 , V_549 [ V_154 -> V_391 ] ) ;
F_245 ( V_29 , V_28 . V_83 . V_550 ) ;
}
return 1 ;
}
F_245 ( V_29 , V_28 . V_83 . V_551 ) ;
return 0 ;
}
static void F_381 ( struct V_26 * V_29 , struct V_530 * V_154 )
{
F_315 ( & V_154 -> V_172 -> V_177 ) ;
F_382 ( V_154 -> V_172 , V_29 , 0 ) ;
V_29 -> V_76 = V_552 ;
F_383 ( V_29 , V_154 -> V_136 ) ;
}
static struct V_26 * F_384 ( struct V_530 * V_154 )
{
struct V_26 * V_29 , * V_302 ;
F_315 ( & V_154 -> V_172 -> V_177 ) ;
F_385 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_379 ( V_29 , V_154 ) )
continue;
F_381 ( V_29 , V_154 ) ;
F_245 ( V_154 -> V_186 , V_553 [ V_154 -> V_391 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_386 ( struct V_530 * V_154 )
{
struct V_554 * V_555 = & V_154 -> V_172 -> V_294 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_556 = 0 ;
F_315 ( & V_154 -> V_172 -> V_177 ) ;
if ( V_154 -> V_483 <= 0 )
return 0 ;
while ( ! F_292 ( V_555 ) ) {
V_29 = F_387 ( V_555 , struct V_26 , V_28 . V_293 ) ;
V_154 -> V_557 ++ ;
if ( V_154 -> V_557 > V_154 -> V_558 )
break;
if ( V_154 -> V_557 > V_154 -> V_559 ) {
V_154 -> V_559 += V_560 ;
V_154 -> V_178 |= V_561 ;
break;
}
if ( ! F_379 ( V_29 , V_154 ) )
goto V_58;
V_70 = F_129 ( V_29 ) ;
if ( F_247 ( V_562 ) && V_70 < 16 && ! V_154 -> V_186 -> V_547 )
goto V_58;
if ( ( V_70 / 2 ) > V_154 -> V_483 )
goto V_58;
F_381 ( V_29 , V_154 ) ;
F_201 ( & V_29 -> V_28 . V_293 , & V_154 -> V_555 ) ;
V_556 ++ ;
V_154 -> V_483 -= V_70 ;
#ifdef F_388
if ( V_154 -> V_391 == V_563 )
break;
#endif
if ( V_154 -> V_483 <= 0 )
break;
continue;
V_58:
F_389 ( & V_29 -> V_28 . V_293 , V_555 ) ;
}
F_69 ( V_154 -> V_186 , V_553 [ V_154 -> V_391 ] , V_556 ) ;
return V_556 ;
}
static void F_390 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_315 ( & V_24 -> V_177 ) ;
F_171 ( F_35 ( V_29 ) != V_24 ) ;
V_29 -> V_76 = V_564 ;
F_391 ( V_24 , V_29 , 0 ) ;
F_392 ( V_24 , V_29 , 0 ) ;
}
static void F_393 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_280 ( & V_24 -> V_177 ) ;
F_390 ( V_24 , V_29 ) ;
F_282 ( & V_24 -> V_177 ) ;
}
static void F_394 ( struct V_530 * V_154 )
{
struct V_554 * V_555 = & V_154 -> V_555 ;
struct V_26 * V_29 ;
F_280 ( & V_154 -> V_174 -> V_177 ) ;
while ( ! F_292 ( V_555 ) ) {
V_29 = F_387 ( V_555 , struct V_26 , V_28 . V_293 ) ;
F_203 ( & V_29 -> V_28 . V_293 ) ;
F_390 ( V_154 -> V_174 , V_29 ) ;
}
F_282 ( & V_154 -> V_174 -> V_177 ) ;
}
static void F_395 ( struct V_295 * V_33 , int V_147 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_147 ] ;
if ( F_209 ( V_25 ) )
return;
F_29 ( V_25 , 1 ) ;
if ( V_28 ) {
F_228 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_78 && ! V_25 -> V_72 )
F_30 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_223 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_396 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
struct V_25 * V_25 ;
unsigned long V_178 ;
F_397 ( & V_24 -> V_177 , V_178 ) ;
F_294 ( V_24 ) ;
F_320 (rq, cfs_rq) {
F_395 ( V_25 -> V_33 , V_24 -> V_147 ) ;
}
F_398 ( & V_24 -> V_177 , V_178 ) ;
}
static void F_399 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_81 = V_196 ;
unsigned long V_70 ;
if ( V_25 -> V_565 == V_81 )
return;
V_25 -> V_566 = NULL ;
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_566 = V_28 ;
if ( V_25 -> V_565 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_567 = V_25 -> V_328 ;
V_25 -> V_565 = V_81 ;
}
while ( ( V_28 = V_25 -> V_566 ) != NULL ) {
V_70 = V_25 -> V_567 ;
V_70 = F_400 ( V_70 * V_28 -> V_77 . V_324 ,
V_25 -> V_328 + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_567 = V_70 ;
V_25 -> V_565 = V_81 ;
}
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_399 ( V_25 ) ;
return F_400 ( V_29 -> V_28 . V_77 . V_324 * V_25 -> V_567 ,
V_25 -> V_328 + 1 ) ;
}
static inline void F_396 ( int V_147 )
{
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_324 ;
}
static inline void F_401 ( struct V_568 * V_569 )
{
* V_569 = (struct V_568 ) {
. V_570 = NULL ,
. V_205 = NULL ,
. V_571 = 0UL ,
. V_572 = 0UL ,
. V_573 = {
. V_485 = 0UL ,
. V_574 = 0 ,
. V_575 = V_576 ,
} ,
} ;
}
static inline int F_402 ( struct V_185 * V_186 ,
enum V_577 V_391 )
{
int V_481 ;
switch ( V_391 ) {
case V_578 :
V_481 = V_186 -> V_579 ;
break;
case V_563 :
V_481 = V_186 -> V_580 ;
break;
default:
V_481 = V_186 -> V_581 ;
break;
}
return V_481 ;
}
static unsigned long F_403 ( struct V_185 * V_186 , int V_147 )
{
if ( ( V_186 -> V_178 & V_582 ) && ( V_186 -> V_511 > 1 ) )
return V_186 -> V_583 / V_186 -> V_511 ;
return V_150 ;
}
unsigned long __weak F_404 ( struct V_185 * V_186 , int V_147 )
{
return F_403 ( V_186 , V_147 ) ;
}
static unsigned long F_405 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
T_2 V_454 , V_584 , V_585 , V_77 ;
T_3 V_42 ;
V_585 = F_87 ( V_24 -> V_585 ) ;
V_77 = F_87 ( V_24 -> V_586 ) ;
V_42 = F_406 ( V_24 ) - V_585 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_454 = F_407 () + V_42 ;
V_584 = F_219 ( V_77 , V_454 ) ;
if ( F_11 ( V_584 < V_150 ) )
return V_150 - V_584 ;
return 1 ;
}
static void F_408 ( struct V_185 * V_186 , int V_147 )
{
unsigned long V_148 = V_150 ;
struct V_475 * V_587 = V_186 -> V_478 ;
if ( F_247 ( V_588 ) )
V_148 *= F_404 ( V_186 , V_147 ) ;
else
V_148 *= F_403 ( V_186 , V_147 ) ;
V_148 >>= V_320 ;
F_113 ( V_147 ) -> V_457 = V_148 ;
V_148 *= F_405 ( V_147 ) ;
V_148 >>= V_320 ;
if ( ! V_148 )
V_148 = 1 ;
F_113 ( V_147 ) -> V_456 = V_148 ;
V_587 -> V_487 -> V_148 = V_148 ;
}
void F_409 ( struct V_185 * V_186 , int V_147 )
{
struct V_185 * V_510 = V_186 -> V_510 ;
struct V_475 * V_119 , * V_587 = V_186 -> V_478 ;
unsigned long V_148 ;
unsigned long V_193 ;
V_193 = F_145 ( V_186 -> V_589 ) ;
V_193 = F_150 ( V_193 , 1UL , V_590 ) ;
V_587 -> V_487 -> V_591 = V_196 + V_193 ;
if ( ! V_510 ) {
F_408 ( V_186 , V_147 ) ;
return;
}
V_148 = 0 ;
if ( V_510 -> V_178 & V_592 ) {
F_112 (cpu, sched_group_cpus(sdg)) {
struct V_593 * V_487 ;
struct V_24 * V_24 = F_113 ( V_147 ) ;
if ( F_13 ( ! V_24 -> V_186 ) ) {
V_148 += F_115 ( V_147 ) ;
continue;
}
V_487 = V_24 -> V_186 -> V_478 -> V_487 ;
V_148 += V_487 -> V_148 ;
}
} else {
V_119 = V_510 -> V_478 ;
do {
V_148 += V_119 -> V_487 -> V_148 ;
V_119 = V_119 -> V_58 ;
} while ( V_119 != V_510 -> V_478 );
}
V_587 -> V_487 -> V_148 = V_148 ;
}
static inline int
F_410 ( struct V_24 * V_24 , struct V_185 * V_186 )
{
return ( ( V_24 -> V_456 * V_186 -> V_169 ) <
( V_24 -> V_457 * 100 ) ) ;
}
static inline int F_411 ( struct V_475 * V_119 )
{
return V_119 -> V_487 -> V_483 ;
}
static inline bool
F_412 ( struct V_530 * V_154 , struct V_594 * V_595 )
{
if ( V_595 -> V_574 < V_595 -> F_102 )
return true ;
if ( ( V_595 -> V_596 * 100 ) >
( V_595 -> V_597 * V_154 -> V_186 -> V_169 ) )
return true ;
return false ;
}
static inline bool
F_413 ( struct V_530 * V_154 , struct V_594 * V_595 )
{
if ( V_595 -> V_574 <= V_595 -> F_102 )
return false ;
if ( ( V_595 -> V_596 * 100 ) <
( V_595 -> V_597 * V_154 -> V_186 -> V_169 ) )
return true ;
return false ;
}
static enum V_575 F_414 ( struct V_530 * V_154 ,
struct V_475 * V_119 ,
struct V_594 * V_595 )
{
if ( V_595 -> V_598 )
return V_599 ;
if ( F_411 ( V_119 ) )
return V_600 ;
return V_576 ;
}
static inline void F_415 ( struct V_530 * V_154 ,
struct V_475 * V_119 , int V_481 ,
int V_486 , struct V_594 * V_595 ,
bool * V_601 )
{
unsigned long V_70 ;
int V_243 ;
memset ( V_595 , 0 , sizeof( * V_595 ) ) ;
F_351 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_113 ( V_243 ) ;
if ( V_486 )
V_70 = F_337 ( V_243 , V_481 ) ;
else
V_70 = F_336 ( V_243 , V_481 ) ;
V_595 -> V_602 += V_70 ;
V_595 -> V_597 += F_357 ( V_243 ) ;
V_595 -> V_574 += V_24 -> V_40 . V_402 ;
if ( V_24 -> V_72 > 1 )
* V_601 = true ;
#ifdef F_416
V_595 -> V_105 += V_24 -> V_105 ;
V_595 -> V_107 += V_24 -> V_107 ;
#endif
V_595 -> V_603 += F_114 ( V_243 ) ;
if ( F_352 ( V_243 ) )
V_595 -> V_604 ++ ;
}
V_595 -> V_596 = V_119 -> V_487 -> V_148 ;
V_595 -> V_485 = ( V_595 -> V_602 * V_150 ) / V_595 -> V_596 ;
if ( V_595 -> V_574 )
V_595 -> V_605 = V_595 -> V_603 / V_595 -> V_574 ;
V_595 -> F_102 = V_119 -> F_102 ;
V_595 -> V_598 = F_413 ( V_154 , V_595 ) ;
V_595 -> V_575 = F_414 ( V_154 , V_119 , V_595 ) ;
}
static bool F_417 ( struct V_530 * V_154 ,
struct V_568 * V_569 ,
struct V_475 * V_497 ,
struct V_594 * V_595 )
{
struct V_594 * V_570 = & V_569 -> V_573 ;
if ( V_595 -> V_575 > V_570 -> V_575 )
return true ;
if ( V_595 -> V_575 < V_570 -> V_575 )
return false ;
if ( V_595 -> V_485 <= V_570 -> V_485 )
return false ;
if ( ! ( V_154 -> V_186 -> V_178 & V_606 ) )
return true ;
if ( V_595 -> V_574 && V_154 -> V_136 < F_418 ( V_497 ) ) {
if ( ! V_569 -> V_570 )
return true ;
if ( F_418 ( V_569 -> V_570 ) > F_418 ( V_497 ) )
return true ;
}
return false ;
}
static inline enum V_607 F_419 ( struct V_594 * V_595 )
{
if ( V_595 -> V_574 > V_595 -> V_105 )
return V_608 ;
if ( V_595 -> V_574 > V_595 -> V_107 )
return V_203 ;
return V_609 ;
}
static inline enum V_607 F_420 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_105 )
return V_608 ;
if ( V_24 -> V_72 > V_24 -> V_107 )
return V_203 ;
return V_609 ;
}
static inline enum V_607 F_419 ( struct V_594 * V_595 )
{
return V_609 ;
}
static inline enum V_607 F_420 ( struct V_24 * V_24 )
{
return V_608 ;
}
static inline void F_421 ( struct V_530 * V_154 , struct V_568 * V_569 )
{
struct V_185 * V_510 = V_154 -> V_186 -> V_510 ;
struct V_475 * V_497 = V_154 -> V_186 -> V_478 ;
struct V_594 V_610 ;
int V_481 , V_611 = 0 ;
bool V_601 = false ;
if ( V_510 && V_510 -> V_178 & V_612 )
V_611 = 1 ;
V_481 = F_402 ( V_154 -> V_186 , V_154 -> V_391 ) ;
do {
struct V_594 * V_595 = & V_610 ;
int V_486 ;
V_486 = F_127 ( V_154 -> V_136 , F_349 ( V_497 ) ) ;
if ( V_486 ) {
V_569 -> V_205 = V_497 ;
V_595 = & V_569 -> V_613 ;
if ( V_154 -> V_391 != V_563 ||
F_422 ( V_196 , V_497 -> V_487 -> V_591 ) )
F_409 ( V_154 -> V_186 , V_154 -> V_136 ) ;
}
F_415 ( V_154 , V_497 , V_481 , V_486 , V_595 ,
& V_601 ) ;
if ( V_486 )
goto V_614;
if ( V_611 && V_569 -> V_205 &&
F_412 ( V_154 , & V_569 -> V_613 ) &&
( V_595 -> V_574 > 1 ) ) {
V_595 -> V_598 = 1 ;
V_595 -> V_575 = V_599 ;
}
if ( F_417 ( V_154 , V_569 , V_497 , V_595 ) ) {
V_569 -> V_570 = V_497 ;
V_569 -> V_573 = * V_595 ;
}
V_614:
V_569 -> V_571 += V_595 -> V_602 ;
V_569 -> V_572 += V_595 -> V_596 ;
V_497 = V_497 -> V_58 ;
} while ( V_497 != V_154 -> V_186 -> V_478 );
if ( V_154 -> V_186 -> V_178 & V_536 )
V_154 -> V_607 = F_419 ( & V_569 -> V_573 ) ;
if ( ! V_154 -> V_186 -> V_34 ) {
if ( V_154 -> V_174 -> V_615 -> V_601 != V_601 )
V_154 -> V_174 -> V_615 -> V_601 = V_601 ;
}
}
static int F_423 ( struct V_530 * V_154 , struct V_568 * V_569 )
{
int V_616 ;
if ( ! ( V_154 -> V_186 -> V_178 & V_606 ) )
return 0 ;
if ( ! V_569 -> V_570 )
return 0 ;
V_616 = F_418 ( V_569 -> V_570 ) ;
if ( V_154 -> V_136 > V_616 )
return 0 ;
V_154 -> V_483 = F_116 (
V_569 -> V_573 . V_485 * V_569 -> V_573 . V_596 ,
V_150 ) ;
return 1 ;
}
static inline
void F_424 ( struct V_530 * V_154 , struct V_568 * V_569 )
{
unsigned long V_503 , V_617 = 0 , V_618 = 0 ;
unsigned int V_619 = 2 ;
unsigned long V_620 ;
struct V_594 * V_205 , * V_570 ;
V_205 = & V_569 -> V_613 ;
V_570 = & V_569 -> V_573 ;
if ( ! V_205 -> V_574 )
V_205 -> V_605 = F_339 ( V_154 -> V_136 ) ;
else if ( V_570 -> V_605 > V_205 -> V_605 )
V_619 = 1 ;
V_620 =
( V_570 -> V_605 * V_150 ) /
V_570 -> V_596 ;
if ( V_570 -> V_485 + V_620 >=
V_205 -> V_485 + ( V_620 * V_619 ) ) {
V_154 -> V_483 = V_570 -> V_605 ;
return;
}
V_617 += V_570 -> V_596 *
F_144 ( V_570 -> V_605 , V_570 -> V_485 ) ;
V_617 += V_205 -> V_596 *
F_144 ( V_205 -> V_605 , V_205 -> V_485 ) ;
V_617 /= V_150 ;
if ( V_570 -> V_485 > V_620 ) {
V_618 += V_570 -> V_596 *
F_144 ( V_570 -> V_605 ,
V_570 -> V_485 - V_620 ) ;
}
if ( V_570 -> V_485 * V_570 -> V_596 <
V_570 -> V_605 * V_150 ) {
V_503 = ( V_570 -> V_485 * V_570 -> V_596 ) /
V_205 -> V_596 ;
} else {
V_503 = ( V_570 -> V_605 * V_150 ) /
V_205 -> V_596 ;
}
V_618 += V_205 -> V_596 *
F_144 ( V_205 -> V_605 , V_205 -> V_485 + V_503 ) ;
V_618 /= V_150 ;
if ( V_618 > V_617 )
V_154 -> V_483 = V_570 -> V_605 ;
}
static inline void F_425 ( struct V_530 * V_154 , struct V_568 * V_569 )
{
unsigned long V_621 , V_622 = ~ 0UL ;
struct V_594 * V_205 , * V_570 ;
V_205 = & V_569 -> V_613 ;
V_570 = & V_569 -> V_573 ;
if ( V_570 -> V_575 == V_600 ) {
V_570 -> V_605 =
F_144 ( V_570 -> V_605 , V_569 -> V_485 ) ;
}
if ( V_570 -> V_485 <= V_569 -> V_485 ||
V_205 -> V_485 >= V_569 -> V_485 ) {
V_154 -> V_483 = 0 ;
return F_424 ( V_154 , V_569 ) ;
}
if ( V_570 -> V_575 == V_599 &&
V_205 -> V_575 == V_599 ) {
V_622 = V_570 -> V_574 *
V_334 ;
if ( V_622 > V_570 -> V_596 )
V_622 -= V_570 -> V_596 ;
else
V_622 = ~ 0UL ;
}
V_621 = F_144 ( V_570 -> V_485 - V_569 -> V_485 , V_622 ) ;
V_154 -> V_483 = F_144 (
V_621 * V_570 -> V_596 ,
( V_569 -> V_485 - V_205 -> V_485 ) * V_205 -> V_596
) / V_150 ;
if ( V_154 -> V_483 < V_570 -> V_605 )
return F_424 ( V_154 , V_569 ) ;
}
static struct V_475 * F_426 ( struct V_530 * V_154 )
{
struct V_594 * V_205 , * V_570 ;
struct V_568 V_569 ;
F_401 ( & V_569 ) ;
F_421 ( V_154 , & V_569 ) ;
V_205 = & V_569 . V_613 ;
V_570 = & V_569 . V_573 ;
if ( ( V_154 -> V_391 == V_623 || V_154 -> V_391 == V_563 ) &&
F_423 ( V_154 , & V_569 ) )
return V_569 . V_570 ;
if ( ! V_569 . V_570 || V_570 -> V_574 == 0 )
goto V_624;
V_569 . V_485 = ( V_150 * V_569 . V_571 )
/ V_569 . V_572 ;
if ( V_570 -> V_575 == V_600 )
goto V_625;
if ( V_154 -> V_391 == V_563 && F_412 ( V_154 , V_205 ) &&
V_570 -> V_598 )
goto V_625;
if ( V_205 -> V_485 >= V_570 -> V_485 )
goto V_624;
if ( V_205 -> V_485 >= V_569 . V_485 )
goto V_624;
if ( V_154 -> V_391 == V_623 ) {
if ( ( V_570 -> V_575 != V_599 ) &&
( V_205 -> V_604 <= ( V_570 -> V_604 + 1 ) ) )
goto V_624;
} else {
if ( 100 * V_570 -> V_485 <=
V_154 -> V_186 -> V_169 * V_205 -> V_485 )
goto V_624;
}
V_625:
F_425 ( V_154 , & V_569 ) ;
return V_569 . V_570 ;
V_624:
V_154 -> V_483 = 0 ;
return NULL ;
}
static struct V_24 * F_427 ( struct V_530 * V_154 ,
struct V_475 * V_119 )
{
struct V_24 * V_570 = NULL , * V_24 ;
unsigned long V_626 = 0 , V_627 = 1 ;
int V_243 ;
F_351 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_148 , V_461 ;
enum V_607 V_628 ;
V_24 = F_113 ( V_243 ) ;
V_628 = F_420 ( V_24 ) ;
if ( V_628 > V_154 -> V_607 )
continue;
V_148 = F_115 ( V_243 ) ;
V_461 = F_114 ( V_243 ) ;
if ( V_24 -> V_72 == 1 && V_461 > V_154 -> V_483 &&
! F_410 ( V_24 , V_154 -> V_186 ) )
continue;
if ( V_461 * V_627 > V_626 * V_148 ) {
V_626 = V_461 ;
V_627 = V_148 ;
V_570 = V_24 ;
}
}
return V_570 ;
}
static int F_428 ( struct V_530 * V_154 )
{
struct V_185 * V_186 = V_154 -> V_186 ;
if ( V_154 -> V_391 == V_563 ) {
if ( ( V_186 -> V_178 & V_606 ) && V_154 -> V_173 > V_154 -> V_136 )
return 1 ;
}
if ( ( V_154 -> V_391 != V_578 ) &&
( V_154 -> V_172 -> V_40 . V_402 == 1 ) ) {
if ( ( F_410 ( V_154 -> V_172 , V_186 ) ) &&
( F_115 ( V_154 -> V_173 ) * V_186 -> V_169 < F_115 ( V_154 -> V_136 ) * 100 ) )
return 1 ;
}
return F_13 ( V_186 -> V_547 > V_186 -> V_548 + 2 ) ;
}
static int F_429 ( struct V_530 * V_154 )
{
struct V_475 * V_497 = V_154 -> V_186 -> V_478 ;
struct V_629 * V_630 , * V_631 ;
int V_147 , V_632 = - 1 ;
if ( V_154 -> V_391 == V_563 )
return 1 ;
V_630 = F_349 ( V_497 ) ;
V_631 = F_430 ( V_497 ) ;
F_351 (cpu, sg_cpus, env->cpus) {
if ( ! F_127 ( V_147 , V_631 ) || ! F_352 ( V_147 ) )
continue;
V_632 = V_147 ;
break;
}
if ( V_632 == - 1 )
V_632 = F_431 ( V_497 ) ;
return V_632 == V_154 -> V_136 ;
}
static int F_432 ( int V_468 , struct V_24 * V_344 ,
struct V_185 * V_186 , enum V_577 V_391 ,
int * V_633 )
{
int V_634 , V_635 , V_636 = 0 ;
struct V_185 * V_637 = V_186 -> V_34 ;
struct V_475 * V_119 ;
struct V_24 * V_570 ;
unsigned long V_178 ;
struct V_629 * V_8 = F_433 ( V_638 ) ;
struct V_530 V_154 = {
. V_186 = V_186 ,
. V_136 = V_468 ,
. V_174 = V_344 ,
. V_542 = F_349 ( V_186 -> V_478 ) ,
. V_391 = V_391 ,
. V_559 = V_560 ,
. V_8 = V_8 ,
. V_607 = V_609 ,
. V_555 = F_434 ( V_154 . V_555 ) ,
} ;
if ( V_391 == V_563 )
V_154 . V_542 = NULL ;
F_435 ( V_8 , V_639 ) ;
F_245 ( V_186 , V_640 [ V_391 ] ) ;
V_641:
if ( ! F_429 ( & V_154 ) ) {
* V_633 = 0 ;
goto V_624;
}
V_119 = F_426 ( & V_154 ) ;
if ( ! V_119 ) {
F_245 ( V_186 , V_642 [ V_391 ] ) ;
goto V_624;
}
V_570 = F_427 ( & V_154 , V_119 ) ;
if ( ! V_570 ) {
F_245 ( V_186 , V_643 [ V_391 ] ) ;
goto V_624;
}
F_171 ( V_570 == V_154 . V_174 ) ;
F_69 ( V_186 , V_644 [ V_391 ] , V_154 . V_483 ) ;
V_154 . V_173 = V_570 -> V_147 ;
V_154 . V_172 = V_570 ;
V_634 = 0 ;
if ( V_570 -> V_72 > 1 ) {
V_154 . V_178 |= V_545 ;
V_154 . V_558 = F_144 ( V_645 , V_570 -> V_72 ) ;
V_646:
F_397 ( & V_570 -> V_177 , V_178 ) ;
V_635 = F_386 ( & V_154 ) ;
F_282 ( & V_570 -> V_177 ) ;
if ( V_635 ) {
F_394 ( & V_154 ) ;
V_634 += V_635 ;
}
F_436 ( V_178 ) ;
if ( V_154 . V_178 & V_561 ) {
V_154 . V_178 &= ~ V_561 ;
goto V_646;
}
if ( ( V_154 . V_178 & V_543 ) && V_154 . V_483 > 0 ) {
F_437 ( V_154 . V_136 , V_154 . V_8 ) ;
V_154 . V_174 = F_113 ( V_154 . V_544 ) ;
V_154 . V_136 = V_154 . V_544 ;
V_154 . V_178 &= ~ V_543 ;
V_154 . V_557 = 0 ;
V_154 . V_559 = V_560 ;
goto V_646;
}
if ( V_637 ) {
int * V_647 = & V_637 -> V_478 -> V_487 -> V_483 ;
if ( ( V_154 . V_178 & V_541 ) && V_154 . V_483 > 0 )
* V_647 = 1 ;
}
if ( F_13 ( V_154 . V_178 & V_545 ) ) {
F_437 ( F_26 ( V_570 ) , V_8 ) ;
if ( ! F_438 ( V_8 ) ) {
V_154 . V_557 = 0 ;
V_154 . V_559 = V_560 ;
goto V_641;
}
goto V_648;
}
}
if ( ! V_634 ) {
F_245 ( V_186 , V_649 [ V_391 ] ) ;
if ( V_391 != V_563 )
V_186 -> V_547 ++ ;
if ( F_428 ( & V_154 ) ) {
F_397 ( & V_570 -> V_177 , V_178 ) ;
if ( ! F_127 ( V_468 ,
F_128 ( V_570 -> V_45 ) ) ) {
F_398 ( & V_570 -> V_177 ,
V_178 ) ;
V_154 . V_178 |= V_545 ;
goto V_650;
}
if ( ! V_570 -> V_636 ) {
V_570 -> V_636 = 1 ;
V_570 -> V_651 = V_468 ;
V_636 = 1 ;
}
F_398 ( & V_570 -> V_177 , V_178 ) ;
if ( V_636 ) {
F_439 ( F_26 ( V_570 ) ,
V_652 , V_570 ,
& V_570 -> V_653 ) ;
}
V_186 -> V_547 = V_186 -> V_548 + 1 ;
}
} else
V_186 -> V_547 = 0 ;
if ( F_11 ( ! V_636 ) ) {
V_186 -> V_589 = V_186 -> V_654 ;
} else {
if ( V_186 -> V_589 < V_186 -> V_655 )
V_186 -> V_589 *= 2 ;
}
goto V_291;
V_624:
if ( V_637 ) {
int * V_647 = & V_637 -> V_478 -> V_487 -> V_483 ;
if ( * V_647 )
* V_647 = 0 ;
}
V_648:
F_245 ( V_186 , V_656 [ V_391 ] ) ;
V_186 -> V_547 = 0 ;
V_650:
if ( ( ( V_154 . V_178 & V_545 ) &&
V_186 -> V_589 < V_657 ) ||
( V_186 -> V_589 < V_186 -> V_655 ) )
V_186 -> V_589 *= 2 ;
V_634 = 0 ;
V_291:
return V_634 ;
}
static inline unsigned long
F_440 ( struct V_185 * V_186 , int V_658 )
{
unsigned long V_193 = V_186 -> V_589 ;
if ( V_658 )
V_193 *= V_186 -> V_659 ;
V_193 = F_145 ( V_193 ) ;
V_193 = F_150 ( V_193 , 1UL , V_590 ) ;
return V_193 ;
}
static inline void
F_441 ( struct V_185 * V_186 , int V_658 , unsigned long * V_660 )
{
unsigned long V_193 , V_58 ;
V_193 = F_440 ( V_186 , V_658 ) ;
V_58 = V_186 -> V_661 + V_193 ;
if ( F_181 ( * V_660 , V_58 ) )
* V_660 = V_58 ;
}
static int F_236 ( struct V_24 * V_344 )
{
unsigned long V_660 = V_196 + V_194 ;
int V_468 = V_344 -> V_147 ;
struct V_185 * V_186 ;
int V_662 = 0 ;
T_2 V_663 = 0 ;
F_234 ( V_344 ) ;
V_344 -> V_495 = F_76 ( V_344 ) ;
if ( V_344 -> V_664 < V_532 ||
! V_344 -> V_615 -> V_601 ) {
F_123 () ;
V_186 = F_442 ( V_344 -> V_186 ) ;
if ( V_186 )
F_441 ( V_186 , 0 , & V_660 ) ;
F_131 () ;
goto V_291;
}
F_282 ( & V_344 -> V_177 ) ;
F_396 ( V_468 ) ;
F_123 () ;
F_359 (this_cpu, sd) {
int V_633 = 1 ;
T_2 V_665 , V_666 ;
if ( ! ( V_186 -> V_178 & V_508 ) )
continue;
if ( V_344 -> V_664 < V_663 + V_186 -> V_667 ) {
F_441 ( V_186 , 0 , & V_660 ) ;
break;
}
if ( V_186 -> V_178 & V_668 ) {
V_665 = F_275 ( V_468 ) ;
V_662 = F_432 ( V_468 , V_344 ,
V_186 , V_563 ,
& V_633 ) ;
V_666 = F_275 ( V_468 ) - V_665 ;
if ( V_666 > V_186 -> V_667 )
V_186 -> V_667 = V_666 ;
V_663 += V_666 ;
}
F_441 ( V_186 , 0 , & V_660 ) ;
if ( V_662 || V_344 -> V_72 > 0 )
break;
}
F_131 () ;
F_280 ( & V_344 -> V_177 ) ;
if ( V_663 > V_344 -> V_669 )
V_344 -> V_669 = V_663 ;
if ( V_344 -> V_40 . V_402 && ! V_662 )
V_662 = 1 ;
V_291:
if ( F_181 ( V_344 -> V_660 , V_660 ) )
V_344 -> V_660 = V_660 ;
if ( V_344 -> V_72 != V_344 -> V_40 . V_402 )
V_662 = - 1 ;
if ( V_662 ) {
F_235 ( V_344 ) ;
V_344 -> V_495 = 0 ;
}
return V_662 ;
}
static int V_652 ( void * V_397 )
{
struct V_24 * V_670 = V_397 ;
int V_616 = F_26 ( V_670 ) ;
int V_671 = V_670 -> V_651 ;
struct V_24 * V_672 = F_113 ( V_671 ) ;
struct V_185 * V_186 ;
struct V_26 * V_29 = NULL ;
F_124 ( & V_670 -> V_177 ) ;
if ( F_13 ( V_616 != F_276 () ||
! V_670 -> V_636 ) )
goto V_673;
if ( V_670 -> V_72 <= 1 )
goto V_673;
F_171 ( V_670 == V_672 ) ;
F_123 () ;
F_359 (target_cpu, sd) {
if ( ( V_186 -> V_178 & V_508 ) &&
F_127 ( V_616 , F_360 ( V_186 ) ) )
break;
}
if ( F_11 ( V_186 ) ) {
struct V_530 V_154 = {
. V_186 = V_186 ,
. V_136 = V_671 ,
. V_174 = V_672 ,
. V_173 = V_670 -> V_147 ,
. V_172 = V_670 ,
. V_391 = V_623 ,
} ;
F_245 ( V_186 , V_674 ) ;
V_29 = F_384 ( & V_154 ) ;
if ( V_29 )
F_245 ( V_186 , V_675 ) ;
else
F_245 ( V_186 , V_676 ) ;
}
F_131 () ;
V_673:
V_670 -> V_636 = 0 ;
F_282 ( & V_670 -> V_177 ) ;
if ( V_29 )
F_393 ( V_672 , V_29 ) ;
F_443 () ;
return 0 ;
}
static inline int F_444 ( struct V_24 * V_24 )
{
return F_13 ( ! F_445 ( V_24 -> V_186 ) ) ;
}
static inline int F_446 ( void )
{
int V_677 = F_447 ( V_678 . V_679 ) ;
if ( V_677 < V_680 && F_352 ( V_677 ) )
return V_677 ;
return V_680 ;
}
static void F_448 ( void )
{
int V_681 ;
V_678 . V_660 ++ ;
V_681 = F_446 () ;
if ( V_681 >= V_680 )
return;
if ( F_449 ( V_682 , F_450 ( V_681 ) ) )
return;
F_451 ( V_681 ) ;
return;
}
static inline void F_452 ( int V_147 )
{
if ( F_13 ( F_453 ( V_683 , F_450 ( V_147 ) ) ) ) {
if ( F_11 ( F_127 ( V_147 , V_678 . V_679 ) ) ) {
F_437 ( V_147 , V_678 . V_679 ) ;
F_454 ( & V_678 . V_684 ) ;
}
F_455 ( V_683 , F_450 ( V_147 ) ) ;
}
}
static inline void F_456 ( void )
{
struct V_185 * V_186 ;
int V_147 = F_276 () ;
F_123 () ;
V_186 = F_136 ( F_137 ( V_685 , V_147 ) ) ;
if ( ! V_186 || ! V_186 -> V_686 )
goto V_180;
V_186 -> V_686 = 0 ;
F_457 ( & V_186 -> V_478 -> V_487 -> V_687 ) ;
V_180:
F_131 () ;
}
void F_458 ( void )
{
struct V_185 * V_186 ;
int V_147 = F_276 () ;
F_123 () ;
V_186 = F_136 ( F_137 ( V_685 , V_147 ) ) ;
if ( ! V_186 || V_186 -> V_686 )
goto V_180;
V_186 -> V_686 = 1 ;
F_454 ( & V_186 -> V_478 -> V_487 -> V_687 ) ;
V_180:
F_131 () ;
}
void F_459 ( int V_147 )
{
if ( ! F_460 ( V_147 ) )
return;
if ( F_453 ( V_683 , F_450 ( V_147 ) ) )
return;
if ( F_444 ( F_113 ( V_147 ) ) )
return;
F_461 ( V_147 , V_678 . V_679 ) ;
F_457 ( & V_678 . V_684 ) ;
F_462 ( V_683 , F_450 ( V_147 ) ) ;
}
static int F_463 ( struct V_688 * V_689 ,
unsigned long V_690 , void * V_691 )
{
switch ( V_690 & ~ V_692 ) {
case V_693 :
F_452 ( F_276 () ) ;
return V_694 ;
default:
return V_695 ;
}
}
void F_464 ( void )
{
V_590 = V_194 * F_465 () / 10 ;
}
static void F_466 ( struct V_24 * V_24 , enum V_577 V_391 )
{
int V_633 = 1 ;
int V_147 = V_24 -> V_147 ;
unsigned long V_193 ;
struct V_185 * V_186 ;
unsigned long V_660 = V_196 + 60 * V_194 ;
int F_441 = 0 ;
int V_696 , V_697 = 0 ;
T_2 V_698 = 0 ;
F_396 ( V_147 ) ;
F_123 () ;
F_359 (cpu, sd) {
if ( F_181 ( V_196 , V_186 -> V_699 ) ) {
V_186 -> V_667 =
( V_186 -> V_667 * 253 ) / 256 ;
V_186 -> V_699 = V_196 + V_194 ;
V_697 = 1 ;
}
V_698 += V_186 -> V_667 ;
if ( ! ( V_186 -> V_178 & V_508 ) )
continue;
if ( ! V_633 ) {
if ( V_697 )
continue;
break;
}
V_193 = F_440 ( V_186 , V_391 != V_623 ) ;
V_696 = V_186 -> V_178 & V_700 ;
if ( V_696 ) {
if ( ! F_467 ( & V_701 ) )
goto V_291;
}
if ( F_422 ( V_196 , V_186 -> V_661 + V_193 ) ) {
if ( F_432 ( V_147 , V_24 , V_186 , V_391 , & V_633 ) ) {
V_391 = F_352 ( V_147 ) ? V_623 : V_578 ;
}
V_186 -> V_661 = V_196 ;
V_193 = F_440 ( V_186 , V_391 != V_623 ) ;
}
if ( V_696 )
F_174 ( & V_701 ) ;
V_291:
if ( F_181 ( V_660 , V_186 -> V_661 + V_193 ) ) {
V_660 = V_186 -> V_661 + V_193 ;
F_441 = 1 ;
}
}
if ( V_697 ) {
V_24 -> V_669 =
F_68 ( ( T_2 ) V_532 , V_698 ) ;
}
F_131 () ;
if ( F_11 ( F_441 ) )
V_24 -> V_660 = V_660 ;
}
static void F_468 ( struct V_24 * V_344 , enum V_577 V_391 )
{
int V_468 = V_344 -> V_147 ;
struct V_24 * V_24 ;
int V_632 ;
if ( V_391 != V_623 ||
! F_453 ( V_682 , F_450 ( V_468 ) ) )
goto V_272;
F_112 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_632 == V_468 || ! F_352 ( V_632 ) )
continue;
if ( F_469 () )
break;
V_24 = F_113 ( V_632 ) ;
if ( F_422 ( V_196 , V_24 -> V_660 ) ) {
F_124 ( & V_24 -> V_177 ) ;
F_294 ( V_24 ) ;
F_333 ( V_24 ) ;
F_126 ( & V_24 -> V_177 ) ;
F_466 ( V_24 , V_623 ) ;
}
if ( F_181 ( V_344 -> V_660 , V_24 -> V_660 ) )
V_344 -> V_660 = V_24 -> V_660 ;
}
V_678 . V_660 = V_344 -> V_660 ;
V_272:
F_455 ( V_682 , F_450 ( V_468 ) ) ;
}
static inline bool F_470 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_196 ;
struct V_185 * V_186 ;
struct V_593 * V_487 ;
int V_702 , V_147 = V_24 -> V_147 ;
bool V_703 = false ;
if ( F_13 ( V_24 -> F_236 ) )
return false ;
F_456 () ;
F_452 ( V_147 ) ;
if ( F_11 ( ! F_222 ( & V_678 . V_684 ) ) )
return false ;
if ( F_185 ( V_81 , V_678 . V_660 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_123 () ;
V_186 = F_136 ( F_137 ( V_685 , V_147 ) ) ;
if ( V_186 ) {
V_487 = V_186 -> V_478 -> V_487 ;
V_702 = F_222 ( & V_487 -> V_687 ) ;
if ( V_702 > 1 ) {
V_703 = true ;
goto V_180;
}
}
V_186 = F_136 ( V_24 -> V_186 ) ;
if ( V_186 ) {
if ( ( V_24 -> V_40 . V_402 >= 1 ) &&
F_410 ( V_24 , V_186 ) ) {
V_703 = true ;
goto V_180;
}
}
V_186 = F_136 ( F_137 ( V_704 , V_147 ) ) ;
if ( V_186 && ( F_356 ( V_678 . V_679 ,
F_360 ( V_186 ) ) < V_147 ) ) {
V_703 = true ;
goto V_180;
}
V_180:
F_131 () ;
return V_703 ;
}
static void F_468 ( struct V_24 * V_344 , enum V_577 V_391 ) { }
static void F_471 ( struct V_705 * V_706 )
{
struct V_24 * V_344 = V_344 () ;
enum V_577 V_391 = V_344 -> F_236 ?
V_623 : V_578 ;
F_468 ( V_344 , V_391 ) ;
F_466 ( V_344 , V_391 ) ;
}
void F_472 ( struct V_24 * V_24 )
{
if ( F_13 ( F_444 ( V_24 ) ) )
return;
if ( F_422 ( V_196 , V_24 -> V_660 ) )
F_473 ( V_707 ) ;
#ifdef F_474
if ( F_470 ( V_24 ) )
F_448 () ;
#endif
}
static void F_475 ( struct V_24 * V_24 )
{
F_7 () ;
F_319 ( V_24 ) ;
}
static void F_476 ( struct V_24 * V_24 )
{
F_7 () ;
F_321 ( V_24 ) ;
}
static void F_477 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_373 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_60 (se) {
V_25 = F_23 ( V_28 ) ;
F_263 ( V_25 , V_28 , V_373 ) ;
}
if ( V_257 )
F_196 ( V_24 , V_45 ) ;
F_223 ( V_24 , 1 ) ;
}
static void F_478 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_468 = F_276 () ;
struct V_24 * V_24 = V_344 () ;
unsigned long V_178 ;
F_397 ( & V_24 -> V_177 , V_178 ) ;
F_294 ( V_24 ) ;
V_25 = F_22 ( V_141 ) ;
V_45 = V_25 -> V_45 ;
F_123 () ;
F_479 ( V_29 , V_468 ) ;
F_131 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_246 ( V_25 , V_28 , 1 ) ;
if ( V_708 && V_45 && F_38 ( V_45 , V_28 ) ) {
F_121 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_257 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_37 ;
F_398 ( & V_24 -> V_177 , V_178 ) ;
}
static void
F_480 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_709 )
{
if ( ! F_481 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_710 > V_709 )
F_257 ( V_24 ) ;
} else
F_392 ( V_24 , V_29 , 0 ) ;
}
static void F_482 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( ! F_481 ( V_29 ) && V_29 -> V_365 != V_711 ) {
F_246 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_37 ;
}
#ifdef F_200
if ( V_28 -> V_77 . V_323 ) {
F_214 ( V_28 ) ;
F_227 ( V_25 , V_28 -> V_77 . V_324 ) ;
}
#endif
}
static void F_483 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
#ifdef F_368
struct V_27 * V_28 = & V_29 -> V_28 ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_481 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 )
F_257 ( V_24 ) ;
else
F_392 ( V_24 , V_29 , 0 ) ;
}
static void F_484 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_60 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_258 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_485 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_712 ;
V_25 -> F_37 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_41
V_25 -> V_48 = V_25 -> F_37 ;
#endif
#ifdef F_200
F_486 ( & V_25 -> V_322 , 1 ) ;
F_487 ( & V_25 -> V_341 , 0 ) ;
#endif
}
static void F_488 ( struct V_26 * V_29 , int V_373 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_373 && ( ! V_28 -> V_85 || V_29 -> V_365 == V_713 ) )
V_373 = 1 ;
if ( ! V_373 )
V_28 -> V_41 -= F_23 ( V_28 ) -> F_37 ;
F_489 ( V_29 , F_135 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_373 ) {
V_25 = F_23 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_37 ;
#ifdef F_200
V_28 -> V_77 . V_323 = F_215 ( & V_25 -> V_322 ) ;
V_25 -> V_329 += V_28 -> V_77 . V_324 ;
#endif
}
}
void F_490 ( struct V_295 * V_33 )
{
int V_243 ;
F_317 ( F_278 ( V_33 ) ) ;
F_491 (i) {
if ( V_33 -> V_25 )
F_179 ( V_33 -> V_25 [ V_243 ] ) ;
if ( V_33 -> V_28 )
F_179 ( V_33 -> V_28 [ V_243 ] ) ;
}
F_179 ( V_33 -> V_25 ) ;
F_179 ( V_33 -> V_28 ) ;
}
int F_492 ( struct V_295 * V_33 , struct V_295 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_243 ;
V_33 -> V_25 = F_167 ( sizeof( V_25 ) * V_680 , V_245 ) ;
if ( ! V_33 -> V_25 )
goto V_714;
V_33 -> V_28 = F_167 ( sizeof( V_28 ) * V_680 , V_245 ) ;
if ( ! V_33 -> V_28 )
goto V_714;
V_33 -> V_299 = V_71 ;
F_310 ( F_278 ( V_33 ) ) ;
F_491 (i) {
V_25 = F_493 ( sizeof( struct V_25 ) ,
V_245 , F_104 ( V_243 ) ) ;
if ( ! V_25 )
goto V_714;
V_28 = F_493 ( sizeof( struct V_27 ) ,
V_245 , F_104 ( V_243 ) ) ;
if ( ! V_28 )
goto V_715;
F_485 ( V_25 ) ;
F_494 ( V_33 , V_25 , V_28 , V_243 , V_34 -> V_28 [ V_243 ] ) ;
}
return 1 ;
V_715:
F_179 ( V_25 ) ;
V_714:
return 0 ;
}
void F_495 ( struct V_295 * V_33 , int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_178 ;
if ( ! V_33 -> V_25 [ V_147 ] -> V_32 )
return;
F_397 ( & V_24 -> V_177 , V_178 ) ;
F_30 ( V_33 -> V_25 [ V_147 ] ) ;
F_398 ( & V_24 -> V_177 , V_178 ) ;
}
void F_494 ( struct V_295 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_147 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
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
int F_496 ( struct V_295 * V_33 , unsigned long V_299 )
{
int V_243 ;
unsigned long V_178 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_190 ;
V_299 = F_150 ( V_299 , F_224 ( V_300 ) , F_224 ( V_716 ) ) ;
F_497 ( & V_717 ) ;
if ( V_33 -> V_299 == V_299 )
goto V_499;
V_33 -> V_299 = V_299 ;
F_491 (i) {
struct V_24 * V_24 = F_113 ( V_243 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_243 ] ;
F_397 ( & V_24 -> V_177 , V_178 ) ;
F_294 ( V_24 ) ;
F_60 (se)
F_208 ( F_24 ( V_28 ) ) ;
F_398 ( & V_24 -> V_177 , V_178 ) ;
}
V_499:
F_498 ( & V_717 ) ;
return 0 ;
}
void F_490 ( struct V_295 * V_33 ) { }
int F_492 ( struct V_295 * V_33 , struct V_295 * V_34 )
{
return 1 ;
}
void F_495 ( struct V_295 * V_33 , int V_147 ) { }
static unsigned int F_499 ( struct V_24 * V_24 , struct V_26 * V_122 )
{
struct V_27 * V_28 = & V_122 -> V_28 ;
unsigned int V_718 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_718 = F_500 ( F_59 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_718 ;
}
void F_501 ( struct V_719 * V_720 , int V_147 )
{
struct V_25 * V_25 ;
F_123 () ;
F_320 (cpu_rq(cpu), cfs_rq)
F_502 ( V_720 , V_147 , V_25 ) ;
F_131 () ;
}
void F_503 ( struct V_26 * V_29 , struct V_719 * V_720 )
{
int V_124 ;
unsigned long V_721 = 0 , V_722 = 0 , V_723 = 0 , V_724 = 0 ;
F_99 (node) {
if ( V_29 -> V_116 ) {
V_721 = V_29 -> V_116 [ F_94 ( V_117 , V_124 , 0 ) ] ;
V_722 = V_29 -> V_116 [ F_94 ( V_117 , V_124 , 1 ) ] ;
}
if ( V_29 -> V_108 ) {
V_723 = V_29 -> V_108 -> V_118 [ F_94 ( V_117 , V_124 , 0 ) ] ,
V_724 = V_29 -> V_108 -> V_118 [ F_94 ( V_117 , V_124 , 1 ) ] ;
}
F_504 ( V_720 , V_124 , V_721 , V_722 , V_723 , V_724 ) ;
}
}
T_12 void F_505 ( void )
{
#ifdef F_200
F_506 ( V_707 , F_471 ) ;
#ifdef F_474
V_678 . V_660 = V_196 ;
F_507 ( & V_678 . V_679 , V_725 ) ;
F_508 ( F_463 , 0 ) ;
#endif
#endif
}
