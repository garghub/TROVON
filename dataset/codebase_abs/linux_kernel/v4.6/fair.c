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
T_2 V_42 ;
V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_93 ;
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
F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_72 ( V_25 , V_28 ) ;
}
static inline void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_97 )
{
if ( V_28 != V_25 -> V_45 )
F_75 ( V_25 , V_28 ) ;
if ( V_97 & V_98 ) {
if ( F_20 ( V_28 ) ) {
struct V_26 * V_99 = F_17 ( V_28 ) ;
if ( V_99 -> V_100 & V_101 )
V_28 -> V_88 . V_102 = F_73 ( F_16 ( V_25 ) ) ;
if ( V_99 -> V_100 & V_103 )
V_28 -> V_88 . V_104 = F_73 ( F_16 ( V_25 ) ) ;
}
}
}
static inline void
F_72 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_97 )
{
}
static inline void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_87 = F_63 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_80 ( struct V_26 * V_29 )
{
unsigned long V_105 = 0 ;
unsigned long V_106 ;
V_106 = V_107 << ( 20 - V_108 ) ;
V_105 = F_81 ( V_29 -> V_109 ) ;
if ( ! V_105 )
V_105 = V_106 ;
V_105 = F_82 ( V_105 , V_106 ) ;
return V_105 / V_106 ;
}
static unsigned int F_83 ( struct V_26 * V_29 )
{
unsigned int V_110 = F_84 ( V_107 ) ;
unsigned int V_111 , floor ;
unsigned int V_112 = 1 ;
if ( V_110 < V_113 )
V_112 = V_113 / V_110 ;
floor = 1000 / V_112 ;
V_111 = V_114 / F_80 ( V_29 ) ;
return F_85 (unsigned int, floor, scan) ;
}
static unsigned int F_86 ( struct V_26 * V_29 )
{
unsigned int V_115 = F_83 ( V_29 ) ;
unsigned int V_116 ;
V_116 = V_117 / F_80 ( V_29 ) ;
return F_65 ( V_115 , V_116 ) ;
}
static void F_87 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_118 += ( V_29 -> V_119 != - 1 ) ;
V_24 -> V_120 += ( V_29 -> V_119 == F_88 ( V_29 ) ) ;
}
static void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_118 -= ( V_29 -> V_119 != - 1 ) ;
V_24 -> V_120 -= ( V_29 -> V_119 == F_88 ( V_29 ) ) ;
}
T_7 F_90 ( struct V_26 * V_29 )
{
return V_29 -> V_121 ? V_29 -> V_121 -> V_122 : 0 ;
}
static inline int F_91 ( enum V_123 V_124 , int V_125 , int V_126 )
{
return V_127 * ( V_124 * V_128 + V_125 ) + V_126 ;
}
static inline unsigned long F_92 ( struct V_26 * V_29 , int V_125 )
{
if ( ! V_29 -> V_129 )
return 0 ;
return V_29 -> V_129 [ F_91 ( V_130 , V_125 , 0 ) ] +
V_29 -> V_129 [ F_91 ( V_130 , V_125 , 1 ) ] ;
}
static inline unsigned long F_93 ( struct V_26 * V_29 , int V_125 )
{
if ( ! V_29 -> V_121 )
return 0 ;
return V_29 -> V_121 -> V_131 [ F_91 ( V_130 , V_125 , 0 ) ] +
V_29 -> V_121 -> V_131 [ F_91 ( V_130 , V_125 , 1 ) ] ;
}
static inline unsigned long F_94 ( struct V_121 * V_132 , int V_125 )
{
return V_132 -> V_133 [ F_91 ( V_130 , V_125 , 0 ) ] +
V_132 -> V_133 [ F_91 ( V_130 , V_125 , 1 ) ] ;
}
static bool F_95 ( int V_125 , struct V_121 * V_134 )
{
return F_94 ( V_134 , V_125 ) * V_135 > V_134 -> V_136 ;
}
static unsigned long F_96 ( struct V_26 * V_29 , int V_125 ,
int V_137 , bool V_138 )
{
unsigned long V_139 = 0 ;
int V_140 ;
if ( V_141 == V_142 )
return 0 ;
F_97 (node) {
unsigned long V_131 ;
int V_143 = F_98 ( V_125 , V_140 ) ;
if ( V_143 == V_144 || V_140 == V_125 )
continue;
if ( V_141 == V_145 &&
V_143 > V_137 )
continue;
if ( V_138 )
V_131 = F_92 ( V_29 , V_140 ) ;
else
V_131 = F_93 ( V_29 , V_140 ) ;
if ( V_141 == V_146 ) {
V_131 *= ( V_144 - V_143 ) ;
V_131 /= ( V_144 - V_147 ) ;
}
V_139 += V_131 ;
}
return V_139 ;
}
static inline unsigned long F_99 ( struct V_26 * V_29 , int V_125 ,
int V_143 )
{
unsigned long V_131 , V_148 ;
if ( ! V_29 -> V_129 )
return 0 ;
V_148 = V_29 -> V_149 ;
if ( ! V_148 )
return 0 ;
V_131 = F_92 ( V_29 , V_125 ) ;
V_131 += F_96 ( V_29 , V_125 , V_143 , true ) ;
return 1000 * V_131 / V_148 ;
}
static inline unsigned long F_100 ( struct V_26 * V_29 , int V_125 ,
int V_143 )
{
unsigned long V_131 , V_148 ;
if ( ! V_29 -> V_121 )
return 0 ;
V_148 = V_29 -> V_121 -> V_148 ;
if ( ! V_148 )
return 0 ;
V_131 = F_93 ( V_29 , V_125 ) ;
V_131 += F_96 ( V_29 , V_125 , V_143 , false ) ;
return 1000 * V_131 / V_148 ;
}
bool F_101 ( struct V_26 * V_29 , struct V_150 * V_150 ,
int V_151 , int V_152 )
{
struct V_121 * V_134 = V_29 -> V_121 ;
int V_153 = F_102 ( V_152 ) ;
int V_154 , V_155 ;
V_155 = F_103 ( V_152 , V_156 -> V_157 ) ;
V_154 = F_104 ( V_150 , V_155 ) ;
if ( ! F_105 ( V_154 ) &&
F_106 ( V_154 ) != V_153 )
return false ;
if ( F_107 ( V_29 , V_154 ) )
return true ;
if ( ! V_134 )
return true ;
if ( F_94 ( V_134 , V_153 ) > F_94 ( V_134 , V_151 ) *
V_135 )
return true ;
return F_94 ( V_134 , V_153 ) * F_93 ( V_29 , V_151 ) * 3 >
F_94 ( V_134 , V_151 ) * F_93 ( V_29 , V_153 ) * 4 ;
}
static void F_108 ( struct V_158 * V_159 , int V_125 )
{
int V_160 , V_161 , V_8 = 0 ;
unsigned long V_162 ;
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
F_109 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_110 ( V_161 ) ;
V_159 -> V_72 += V_24 -> V_72 ;
V_159 -> V_70 += F_111 ( V_161 ) ;
V_159 -> V_163 += F_112 ( V_161 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_160 = F_54 ( V_164 * V_8 , V_159 -> V_163 ) ;
V_162 = V_8 / V_160 ;
V_159 -> V_165 = F_5 ( unsigned , V_162 ,
F_113 ( V_159 -> V_163 , V_164 ) ) ;
V_159 -> V_166 = ( V_159 -> V_72 < V_159 -> V_165 ) ;
}
static void F_114 ( struct V_167 * V_168 ,
struct V_26 * V_29 , long V_169 )
{
if ( V_168 -> V_170 )
F_115 ( V_168 -> V_170 ) ;
V_168 -> V_170 = V_29 ;
V_168 -> V_171 = V_169 ;
V_168 -> V_172 = V_168 -> V_152 ;
}
static bool F_116 ( long V_173 , long V_174 ,
struct V_167 * V_168 )
{
long V_175 , V_176 ;
long V_177 , V_178 ;
long V_179 , V_180 ;
V_179 = V_168 -> V_181 . V_163 ;
V_180 = V_168 -> V_182 . V_163 ;
if ( V_174 < V_173 )
F_117 ( V_174 , V_173 ) ;
V_175 = V_174 * V_179 * 100 -
V_173 * V_180 * V_168 -> V_183 ;
if ( V_175 <= 0 )
return false ;
V_177 = V_168 -> V_181 . V_70 ;
V_178 = V_168 -> V_182 . V_70 ;
if ( V_178 < V_177 )
F_117 ( V_178 , V_177 ) ;
V_176 = V_178 * V_179 * 100 -
V_177 * V_180 * V_168 -> V_183 ;
return ( V_175 > V_176 ) ;
}
static void F_118 ( struct V_167 * V_168 ,
long V_184 , long V_185 )
{
struct V_24 * V_186 = F_110 ( V_168 -> V_187 ) ;
struct V_24 * V_188 = F_110 ( V_168 -> V_152 ) ;
struct V_26 * V_189 ;
long V_173 , V_174 ;
long V_70 ;
long V_169 = V_168 -> V_29 -> V_121 ? V_185 : V_184 ;
long V_190 = V_169 ;
int V_143 = V_168 -> V_143 ;
bool V_191 = false ;
F_119 () ;
F_120 ( & V_188 -> V_192 ) ;
V_189 = V_188 -> V_45 ;
if ( ( V_189 -> V_97 & V_193 ) || F_121 ( V_189 ) )
V_189 = NULL ;
else {
F_122 ( V_189 ) ;
}
F_123 ( & V_188 -> V_192 ) ;
if ( V_189 == V_168 -> V_29 )
goto V_194;
if ( V_189 ) {
if ( ! F_124 ( V_168 -> V_187 , F_125 ( V_189 ) ) )
goto V_194;
if ( V_189 -> V_121 == V_168 -> V_29 -> V_121 ) {
V_169 = V_184 + F_99 ( V_189 , V_168 -> V_151 , V_143 ) -
F_99 ( V_189 , V_168 -> V_153 , V_143 ) ;
if ( V_189 -> V_121 )
V_169 -= V_169 / 16 ;
} else {
if ( V_189 -> V_121 )
V_169 += F_100 ( V_189 , V_168 -> V_151 , V_143 ) -
F_100 ( V_189 , V_168 -> V_153 , V_143 ) ;
else
V_169 += F_99 ( V_189 , V_168 -> V_151 , V_143 ) -
F_99 ( V_189 , V_168 -> V_153 , V_143 ) ;
}
}
if ( V_169 <= V_168 -> V_171 && V_190 <= V_168 -> V_171 )
goto V_194;
if ( ! V_189 ) {
if ( V_168 -> V_181 . V_72 <= V_168 -> V_181 . V_165 &&
! V_168 -> V_182 . V_166 )
goto V_194;
goto V_195;
}
if ( V_169 > V_168 -> V_171 && V_186 -> V_72 == 1 &&
V_188 -> V_72 == 1 )
goto V_196;
V_195:
V_70 = F_126 ( V_168 -> V_29 ) ;
V_174 = V_168 -> V_182 . V_70 + V_70 ;
V_173 = V_168 -> V_181 . V_70 - V_70 ;
if ( V_190 > V_169 && V_190 > V_168 -> V_171 ) {
if ( ! F_116 ( V_173 , V_174 , V_168 ) ) {
V_169 = V_190 - 1 ;
F_115 ( V_189 ) ;
V_189 = NULL ;
goto V_196;
}
}
if ( V_169 <= V_168 -> V_171 )
goto V_194;
if ( V_189 ) {
V_70 = F_126 ( V_189 ) ;
V_174 -= V_70 ;
V_173 += V_70 ;
}
if ( F_116 ( V_173 , V_174 , V_168 ) )
goto V_194;
if ( ! V_189 )
V_168 -> V_152 = F_127 ( V_168 -> V_29 , V_168 -> V_152 ) ;
V_196:
V_191 = true ;
F_114 ( V_168 , V_189 , V_169 ) ;
V_194:
F_128 () ;
if ( V_189 && ! V_191 )
F_115 ( V_189 ) ;
}
static void F_129 ( struct V_167 * V_168 ,
long V_184 , long V_185 )
{
int V_161 ;
F_109 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_124 ( V_161 , F_125 ( V_168 -> V_29 ) ) )
continue;
V_168 -> V_152 = V_161 ;
F_118 ( V_168 , V_184 , V_185 ) ;
}
}
static bool F_130 ( struct V_167 * V_168 )
{
struct V_158 * V_197 = & V_168 -> V_181 ;
struct V_158 * V_198 = & V_168 -> V_182 ;
if ( V_197 -> V_166 && ! V_198 -> V_166 )
return false ;
if ( V_197 -> V_70 * V_198 -> V_163 * V_168 -> V_183 >
V_198 -> V_70 * V_197 -> V_163 * 100 )
return true ;
return false ;
}
static int F_131 ( struct V_26 * V_29 )
{
struct V_167 V_168 = {
. V_29 = V_29 ,
. V_187 = F_132 ( V_29 ) ,
. V_151 = F_88 ( V_29 ) ,
. V_183 = 112 ,
. V_170 = NULL ,
. V_171 = 0 ,
. V_172 = - 1 ,
} ;
struct V_199 * V_200 ;
unsigned long V_201 , V_202 ;
int V_125 , V_66 , V_143 ;
long V_184 , V_185 ;
F_119 () ;
V_200 = F_133 ( F_134 ( V_203 , V_168 . V_187 ) ) ;
if ( V_200 )
V_168 . V_183 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
F_128 () ;
if ( F_13 ( ! V_200 ) ) {
V_29 -> V_119 = F_88 ( V_29 ) ;
return - V_204 ;
}
V_168 . V_153 = V_29 -> V_119 ;
V_143 = V_168 . V_143 = F_98 ( V_168 . V_151 , V_168 . V_153 ) ;
V_201 = F_99 ( V_29 , V_168 . V_151 , V_143 ) ;
V_202 = F_100 ( V_29 , V_168 . V_151 , V_143 ) ;
F_108 ( & V_168 . V_181 , V_168 . V_151 ) ;
V_184 = F_99 ( V_29 , V_168 . V_153 , V_143 ) - V_201 ;
V_185 = F_100 ( V_29 , V_168 . V_153 , V_143 ) - V_202 ;
F_108 ( & V_168 . V_182 , V_168 . V_153 ) ;
if ( F_130 ( & V_168 ) )
F_129 ( & V_168 , V_184 , V_185 ) ;
if ( V_168 . V_172 == - 1 || ( V_29 -> V_121 && V_29 -> V_121 -> V_205 > 1 ) ) {
F_97 (nid) {
if ( V_125 == V_168 . V_151 || V_125 == V_29 -> V_119 )
continue;
V_143 = F_98 ( V_168 . V_151 , V_168 . V_153 ) ;
if ( V_141 == V_145 &&
V_143 != V_168 . V_143 ) {
V_201 = F_99 ( V_29 , V_168 . V_151 , V_143 ) ;
V_202 = F_100 ( V_29 , V_168 . V_151 , V_143 ) ;
}
V_184 = F_99 ( V_29 , V_125 , V_143 ) - V_201 ;
V_185 = F_100 ( V_29 , V_125 , V_143 ) - V_202 ;
if ( V_184 < 0 && V_185 < 0 )
continue;
V_168 . V_143 = V_143 ;
V_168 . V_153 = V_125 ;
F_108 ( & V_168 . V_182 , V_168 . V_153 ) ;
if ( F_130 ( & V_168 ) )
F_129 ( & V_168 , V_184 , V_185 ) ;
}
}
if ( V_29 -> V_121 ) {
struct V_121 * V_134 = V_29 -> V_121 ;
if ( V_168 . V_172 == - 1 )
V_125 = V_168 . V_151 ;
else
V_125 = V_168 . V_153 ;
if ( V_134 -> V_205 > 1 && F_95 ( V_168 . V_153 , V_134 ) )
F_135 ( V_29 , V_168 . V_153 ) ;
}
if ( V_168 . V_172 == - 1 )
return - V_206 ;
V_29 -> V_207 = F_83 ( V_29 ) ;
if ( V_168 . V_170 == NULL ) {
V_66 = F_136 ( V_29 , V_168 . V_172 ) ;
if ( V_66 != 0 )
F_137 ( V_29 , V_168 . V_187 , V_168 . V_172 ) ;
return V_66 ;
}
V_66 = F_138 ( V_29 , V_168 . V_170 ) ;
if ( V_66 != 0 )
F_137 ( V_29 , V_168 . V_187 , F_132 ( V_168 . V_170 ) ) ;
F_115 ( V_168 . V_170 ) ;
return V_66 ;
}
static void F_139 ( struct V_26 * V_29 )
{
unsigned long V_208 = V_209 ;
if ( F_13 ( V_29 -> V_119 == - 1 || ! V_29 -> V_129 ) )
return;
V_208 = F_140 ( V_208 , F_141 ( V_29 -> V_207 ) / 16 ) ;
V_29 -> V_210 = V_211 + V_208 ;
if ( F_88 ( V_29 ) == V_29 -> V_119 )
return;
F_131 ( V_29 ) ;
}
static void F_142 ( struct V_121 * V_121 )
{
unsigned long V_131 , V_212 = 0 ;
int V_125 , V_205 = 0 ;
F_97 (nid) {
V_131 = F_94 ( V_121 , V_125 ) ;
if ( V_131 > V_212 )
V_212 = V_131 ;
}
F_97 (nid) {
V_131 = F_94 ( V_121 , V_125 ) ;
if ( V_131 * V_135 > V_212 )
V_205 ++ ;
}
V_121 -> V_136 = V_212 ;
V_121 -> V_205 = V_205 ;
}
static void F_143 ( struct V_26 * V_29 ,
unsigned long V_213 , unsigned long V_214 )
{
unsigned int V_215 ;
int V_216 ;
int V_217 ;
unsigned long V_218 = V_29 -> V_219 [ 0 ] ;
unsigned long V_220 = V_29 -> V_219 [ 1 ] ;
if ( V_220 + V_213 == 0 || V_29 -> V_219 [ 2 ] ) {
V_29 -> V_207 = F_140 ( V_29 -> V_221 ,
V_29 -> V_207 << 1 ) ;
V_29 -> V_109 -> V_222 = V_211 +
F_141 ( V_29 -> V_207 ) ;
return;
}
V_215 = F_54 ( V_29 -> V_207 , V_223 ) ;
V_216 = ( V_220 * V_223 ) / ( V_220 + V_218 ) ;
if ( V_216 >= V_224 ) {
int V_225 = V_216 - V_224 ;
if ( ! V_225 )
V_225 = 1 ;
V_217 = V_225 * V_215 ;
} else {
V_217 = - ( V_224 - V_216 ) * V_215 ;
V_216 = F_54 ( V_214 * V_223 , ( V_214 + V_213 + 1 ) ) ;
V_217 = ( V_217 * V_216 ) / V_223 ;
}
V_29 -> V_207 = F_144 ( V_29 -> V_207 + V_217 ,
F_83 ( V_29 ) , F_86 ( V_29 ) ) ;
memset ( V_29 -> V_219 , 0 , sizeof( V_29 -> V_219 ) ) ;
}
static T_2 F_145 ( struct V_26 * V_29 , T_2 * V_226 )
{
T_2 V_227 , V_42 , V_86 ;
V_86 = V_29 -> V_28 . V_87 ;
V_227 = V_29 -> V_28 . V_90 ;
if ( V_29 -> V_228 ) {
V_42 = V_227 - V_29 -> V_229 ;
* V_226 = V_86 - V_29 -> V_228 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_70 . V_4 ;
* V_226 = V_82 ;
}
V_29 -> V_229 = V_227 ;
V_29 -> V_228 = V_86 ;
return V_42 ;
}
static int F_146 ( struct V_26 * V_29 , int V_125 )
{
T_8 V_230 ;
int V_143 ;
if ( V_141 == V_142 )
return V_125 ;
if ( V_141 == V_146 ) {
unsigned long V_139 , V_231 = 0 ;
int V_140 , V_232 = V_125 ;
V_143 = V_144 ;
F_97 (node) {
V_139 = F_100 ( V_29 , V_140 , V_143 ) ;
if ( V_139 > V_231 ) {
V_231 = V_139 ;
V_232 = V_140 ;
}
}
return V_232 ;
}
V_230 = V_233 ;
for ( V_143 = V_144 ; V_143 > V_147 ; V_143 -- ) {
unsigned long V_212 = 0 ;
T_8 V_234 = V_235 ;
int V_43 , V_44 ;
if ( ! F_147 ( V_143 ) )
continue;
F_148 (a, nodes) {
unsigned long V_131 = 0 ;
T_8 V_236 ;
F_149 ( V_236 ) ;
F_148 (b, nodes) {
if ( F_98 ( V_43 , V_44 ) < V_143 ) {
V_131 += F_93 ( V_29 , V_44 ) ;
F_150 ( V_44 , V_236 ) ;
F_151 ( V_44 , V_230 ) ;
}
}
if ( V_131 > V_212 ) {
V_212 = V_131 ;
V_234 = V_236 ;
V_125 = V_43 ;
}
}
if ( ! V_212 )
break;
V_230 = V_234 ;
}
return V_125 ;
}
static void F_152 ( struct V_26 * V_29 )
{
int V_237 , V_125 , V_238 = - 1 , V_239 = - 1 ;
unsigned long V_212 = 0 , V_240 = 0 ;
unsigned long V_241 [ 2 ] = { 0 , 0 } ;
unsigned long V_148 ;
T_2 V_227 , V_226 ;
T_9 * V_242 = NULL ;
V_237 = F_84 ( V_29 -> V_109 -> V_243 ) ;
if ( V_29 -> V_243 == V_237 )
return;
V_29 -> V_243 = V_237 ;
V_29 -> V_221 = F_86 ( V_29 ) ;
V_148 = V_29 -> V_219 [ 0 ] +
V_29 -> V_219 [ 1 ] ;
V_227 = F_145 ( V_29 , & V_226 ) ;
if ( V_29 -> V_121 ) {
V_242 = & V_29 -> V_121 -> V_192 ;
F_153 ( V_242 ) ;
}
F_97 (nid) {
int V_244 , V_245 , V_246 , V_247 ;
unsigned long V_131 = 0 , F_93 = 0 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
long V_217 , V_248 , V_249 ;
V_244 = F_91 ( V_130 , V_125 , V_126 ) ;
V_245 = F_91 ( V_250 , V_125 , V_126 ) ;
V_246 = F_91 ( V_251 , V_125 , V_126 ) ;
V_247 = F_91 ( V_252 , V_125 , V_126 ) ;
V_217 = V_29 -> V_129 [ V_245 ] - V_29 -> V_129 [ V_244 ] / 2 ;
V_241 [ V_126 ] += V_29 -> V_129 [ V_245 ] ;
V_29 -> V_129 [ V_245 ] = 0 ;
V_249 = F_154 ( V_227 << 16 , V_226 + 1 ) ;
V_249 = ( V_249 * V_29 -> V_129 [ V_247 ] ) /
( V_148 + 1 ) ;
V_248 = V_249 - V_29 -> V_129 [ V_246 ] / 2 ;
V_29 -> V_129 [ V_247 ] = 0 ;
V_29 -> V_129 [ V_244 ] += V_217 ;
V_29 -> V_129 [ V_246 ] += V_248 ;
V_131 += V_29 -> V_129 [ V_244 ] ;
V_29 -> V_149 += V_217 ;
if ( V_29 -> V_121 ) {
V_29 -> V_121 -> V_131 [ V_244 ] += V_217 ;
V_29 -> V_121 -> V_133 [ V_244 ] += V_248 ;
V_29 -> V_121 -> V_148 += V_217 ;
F_93 += V_29 -> V_121 -> V_131 [ V_244 ] ;
}
}
if ( V_131 > V_212 ) {
V_212 = V_131 ;
V_238 = V_125 ;
}
if ( F_93 > V_240 ) {
V_240 = F_93 ;
V_239 = V_125 ;
}
}
F_143 ( V_29 , V_241 [ 0 ] , V_241 [ 1 ] ) ;
if ( V_29 -> V_121 ) {
F_142 ( V_29 -> V_121 ) ;
F_155 ( V_242 ) ;
V_238 = F_146 ( V_29 , V_239 ) ;
}
if ( V_212 ) {
if ( V_238 != V_29 -> V_119 )
F_135 ( V_29 , V_238 ) ;
if ( F_88 ( V_29 ) != V_29 -> V_119 )
F_139 ( V_29 ) ;
}
}
static inline int F_156 ( struct V_121 * V_30 )
{
return F_157 ( & V_30 -> V_253 ) ;
}
static inline void F_158 ( struct V_121 * V_30 )
{
if ( F_159 ( & V_30 -> V_253 ) )
F_160 ( V_30 , V_254 ) ;
}
static void F_161 ( struct V_26 * V_29 , int V_255 , int V_97 ,
int * V_126 )
{
struct V_121 * V_30 , * V_256 ;
struct V_26 * V_99 ;
bool V_257 = false ;
int V_161 = F_162 ( V_255 ) ;
int V_258 ;
if ( F_13 ( ! V_29 -> V_121 ) ) {
unsigned int V_259 = sizeof( struct V_121 ) +
4 * V_128 *sizeof( unsigned long ) ;
V_30 = F_163 ( V_259 , V_260 | V_261 ) ;
if ( ! V_30 )
return;
F_164 ( & V_30 -> V_253 , 1 ) ;
V_30 -> V_205 = 1 ;
V_30 -> V_136 = 0 ;
F_165 ( & V_30 -> V_192 ) ;
V_30 -> V_122 = V_29 -> V_157 ;
V_30 -> V_133 = V_30 -> V_131 + V_127 *
V_128 ;
for ( V_258 = 0 ; V_258 < V_262 * V_128 ; V_258 ++ )
V_30 -> V_131 [ V_258 ] = V_29 -> V_129 [ V_258 ] ;
V_30 -> V_148 = V_29 -> V_149 ;
V_30 -> V_263 ++ ;
F_166 ( V_29 -> V_121 , V_30 ) ;
}
F_119 () ;
V_99 = F_84 ( F_110 ( V_161 ) -> V_45 ) ;
if ( ! F_107 ( V_99 , V_255 ) )
goto V_264;
V_30 = F_133 ( V_99 -> V_121 ) ;
if ( ! V_30 )
goto V_264;
V_256 = V_29 -> V_121 ;
if ( V_30 == V_256 )
goto V_264;
if ( V_256 -> V_263 > V_30 -> V_263 )
goto V_264;
if ( V_256 -> V_263 == V_30 -> V_263 && V_256 > V_30 )
goto V_264;
if ( V_99 -> V_109 == V_156 -> V_109 )
V_257 = true ;
if ( V_97 & V_265 )
V_257 = true ;
* V_126 = ! V_257 ;
if ( V_257 && ! F_156 ( V_30 ) )
goto V_264;
F_128 () ;
if ( ! V_257 )
return;
F_167 ( F_168 () ) ;
F_169 ( & V_256 -> V_192 , & V_30 -> V_192 ) ;
for ( V_258 = 0 ; V_258 < V_262 * V_128 ; V_258 ++ ) {
V_256 -> V_131 [ V_258 ] -= V_29 -> V_129 [ V_258 ] ;
V_30 -> V_131 [ V_258 ] += V_29 -> V_129 [ V_258 ] ;
}
V_256 -> V_148 -= V_29 -> V_149 ;
V_30 -> V_148 += V_29 -> V_149 ;
V_256 -> V_263 -- ;
V_30 -> V_263 ++ ;
F_170 ( & V_256 -> V_192 ) ;
F_155 ( & V_30 -> V_192 ) ;
F_166 ( V_29 -> V_121 , V_30 ) ;
F_158 ( V_256 ) ;
return;
V_264:
F_128 () ;
return;
}
void F_171 ( struct V_26 * V_29 )
{
struct V_121 * V_30 = V_29 -> V_121 ;
void * V_129 = V_29 -> V_129 ;
unsigned long V_97 ;
int V_258 ;
if ( V_30 ) {
F_172 ( & V_30 -> V_192 , V_97 ) ;
for ( V_258 = 0 ; V_258 < V_262 * V_128 ; V_258 ++ )
V_30 -> V_131 [ V_258 ] -= V_29 -> V_129 [ V_258 ] ;
V_30 -> V_148 -= V_29 -> V_149 ;
V_30 -> V_263 -- ;
F_173 ( & V_30 -> V_192 , V_97 ) ;
F_174 ( V_29 -> V_121 , NULL ) ;
F_158 ( V_30 ) ;
}
V_29 -> V_129 = NULL ;
F_175 ( V_129 ) ;
}
void F_176 ( int V_154 , int V_266 , int V_267 , int V_97 )
{
struct V_26 * V_29 = V_156 ;
bool V_268 = V_97 & V_269 ;
int V_270 = F_88 ( V_156 ) ;
int V_220 = ! ! ( V_97 & V_271 ) ;
struct V_121 * V_134 ;
int V_126 ;
if ( ! F_177 ( & V_272 ) )
return;
if ( ! V_29 -> V_109 )
return;
if ( F_13 ( ! V_29 -> V_129 ) ) {
int V_259 = sizeof( * V_29 -> V_129 ) *
V_273 * V_128 ;
V_29 -> V_129 = F_163 ( V_259 , V_260 | V_261 ) ;
if ( ! V_29 -> V_129 )
return;
V_29 -> V_149 = 0 ;
memset ( V_29 -> V_219 , 0 , sizeof( V_29 -> V_219 ) ) ;
}
if ( F_13 ( V_154 == ( - 1 & V_274 ) ) ) {
V_126 = 1 ;
} else {
V_126 = F_107 ( V_29 , V_154 ) ;
if ( ! V_126 && ! ( V_97 & V_275 ) )
F_161 ( V_29 , V_154 , V_97 , & V_126 ) ;
}
V_134 = V_29 -> V_121 ;
if ( ! V_126 && ! V_220 && V_134 && V_134 -> V_205 > 1 &&
F_95 ( V_270 , V_134 ) &&
F_95 ( V_266 , V_134 ) )
V_220 = 1 ;
F_152 ( V_29 ) ;
if ( F_178 ( V_211 , V_29 -> V_210 ) )
F_139 ( V_29 ) ;
if ( V_268 )
V_29 -> V_276 += V_267 ;
if ( V_97 & V_277 )
V_29 -> V_219 [ 2 ] += V_267 ;
V_29 -> V_129 [ F_91 ( V_250 , V_266 , V_126 ) ] += V_267 ;
V_29 -> V_129 [ F_91 ( V_252 , V_270 , V_126 ) ] += V_267 ;
V_29 -> V_219 [ V_220 ] += V_267 ;
}
static void F_179 ( struct V_26 * V_29 )
{
F_180 ( V_29 -> V_109 -> V_243 , F_84 ( V_29 -> V_109 -> V_243 ) + 1 ) ;
V_29 -> V_109 -> V_278 = 0 ;
}
void F_181 ( struct V_279 * V_280 )
{
unsigned long V_281 , V_282 , V_86 = V_211 ;
struct V_26 * V_29 = V_156 ;
struct V_283 * V_109 = V_29 -> V_109 ;
T_2 V_227 = V_29 -> V_28 . V_90 ;
struct V_284 * V_285 ;
unsigned long V_286 , V_287 ;
unsigned long V_288 = 0 ;
long V_267 , V_289 ;
F_19 ( V_29 != F_21 ( V_280 , struct V_26 , V_290 ) ) ;
V_280 -> V_58 = V_280 ;
if ( V_29 -> V_97 & V_193 )
return;
if ( ! V_109 -> V_222 ) {
V_109 -> V_222 = V_86 +
F_141 ( V_291 ) ;
}
V_281 = V_109 -> V_222 ;
if ( F_182 ( V_86 , V_281 ) )
return;
if ( V_29 -> V_207 == 0 ) {
V_29 -> V_221 = F_86 ( V_29 ) ;
V_29 -> V_207 = F_83 ( V_29 ) ;
}
V_282 = V_86 + F_141 ( V_29 -> V_207 ) ;
if ( F_183 ( & V_109 -> V_222 , V_281 , V_282 ) != V_281 )
return;
V_29 -> V_292 += 2 * V_293 ;
V_286 = V_109 -> V_278 ;
V_267 = V_107 ;
V_267 <<= 20 - V_108 ;
V_289 = V_267 * 8 ;
if ( ! V_267 )
return;
F_184 ( & V_109 -> V_294 ) ;
V_285 = F_185 ( V_109 , V_286 ) ;
if ( ! V_285 ) {
F_179 ( V_29 ) ;
V_286 = 0 ;
V_285 = V_109 -> V_295 ;
}
for (; V_285 ; V_285 = V_285 -> V_296 ) {
if ( ! F_186 ( V_285 ) || ! F_187 ( V_285 ) ||
F_188 ( V_285 ) || ( V_285 -> V_297 & V_298 ) ) {
continue;
}
if ( ! V_285 -> V_299 ||
( V_285 -> V_300 && ( V_285 -> V_297 & ( V_301 | V_302 ) ) == ( V_301 ) ) )
continue;
if ( ! ( V_285 -> V_297 & ( V_301 | V_303 | V_302 ) ) )
continue;
do {
V_286 = F_65 ( V_286 , V_285 -> V_304 ) ;
V_287 = F_189 ( V_286 + ( V_267 << V_108 ) , V_305 ) ;
V_287 = F_140 ( V_287 , V_285 -> V_306 ) ;
V_288 = F_190 ( V_285 , V_286 , V_287 ) ;
if ( V_288 )
V_267 -= ( V_287 - V_286 ) >> V_108 ;
V_289 -= ( V_287 - V_286 ) >> V_108 ;
V_286 = V_287 ;
if ( V_267 <= 0 || V_289 <= 0 )
goto V_307;
F_191 () ;
} while ( V_287 != V_285 -> V_306 );
}
V_307:
if ( V_285 )
V_109 -> V_278 = V_286 ;
else
F_179 ( V_29 ) ;
F_192 ( & V_109 -> V_294 ) ;
if ( F_13 ( V_29 -> V_28 . V_90 != V_227 ) ) {
T_2 V_217 = V_29 -> V_28 . V_90 - V_227 ;
V_29 -> V_292 += 32 * V_217 ;
}
}
void F_193 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_279 * V_280 = & V_45 -> V_290 ;
T_2 V_226 , V_86 ;
if ( ! V_45 -> V_109 || ( V_45 -> V_97 & V_193 ) || V_280 -> V_58 != V_280 )
return;
V_86 = V_45 -> V_28 . V_90 ;
V_226 = ( T_2 ) V_45 -> V_207 * V_308 ;
if ( V_86 > V_45 -> V_292 + V_226 ) {
if ( ! V_45 -> V_292 )
V_45 -> V_207 = F_83 ( V_45 ) ;
V_45 -> V_292 += V_226 ;
if ( ! F_182 ( V_211 , V_45 -> V_109 -> V_222 ) ) {
F_194 ( V_280 , F_181 ) ;
F_195 ( V_45 , V_280 , true ) ;
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
F_198 ( & V_28 -> V_309 , & V_24 -> V_310 ) ;
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
F_200 ( & V_28 -> V_309 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_201 ( struct V_311 * V_33 , struct V_25 * V_25 )
{
long V_312 ;
V_312 = F_202 ( & V_33 -> V_80 ) ;
V_312 -= V_25 -> V_313 ;
V_312 += V_25 -> V_70 . V_4 ;
return V_312 ;
}
static long F_203 ( struct V_25 * V_25 , struct V_311 * V_33 )
{
long V_312 , V_70 , V_314 ;
V_312 = F_201 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_314 = ( V_33 -> V_314 * V_70 ) ;
if ( V_312 )
V_314 /= V_312 ;
if ( V_314 < V_315 )
V_314 = V_315 ;
if ( V_314 > V_33 -> V_314 )
V_314 = V_33 -> V_314 ;
return V_314 ;
}
static inline long F_203 ( struct V_25 * V_25 , struct V_311 * V_33 )
{
return V_33 -> V_314 ;
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
struct V_311 * V_33 ;
struct V_27 * V_28 ;
long V_314 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_206 ( V_25 ) )
return;
#ifndef F_197
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_314 ) )
return;
#endif
V_314 = F_203 ( V_25 , V_33 ) ;
F_204 ( F_23 ( V_28 ) , V_28 , V_314 ) ;
}
static inline void F_205 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_207 ( T_2 V_316 , T_2 V_317 )
{
unsigned int V_318 ;
if ( ! V_317 )
return V_316 ;
else if ( F_13 ( V_317 > V_319 * 63 ) )
return 0 ;
V_318 = V_317 ;
if ( F_13 ( V_318 >= V_319 ) ) {
V_316 >>= V_318 / V_319 ;
V_318 %= V_319 ;
}
V_316 = F_15 ( V_316 , V_320 [ V_318 ] , 32 ) ;
return V_316 ;
}
static V_23 F_208 ( T_2 V_317 )
{
V_23 V_321 = 0 ;
if ( F_11 ( V_317 <= V_319 ) )
return V_322 [ V_317 ] ;
else if ( F_13 ( V_317 >= V_323 ) )
return V_82 ;
do {
V_321 /= 2 ;
V_321 += V_322 [ V_319 ] ;
V_317 -= V_319 ;
} while ( V_317 > V_319 );
V_321 = F_207 ( V_321 , V_317 ) ;
return V_321 + V_322 [ V_317 ] ;
}
static T_10 int
F_209 ( T_2 V_86 , int V_161 , struct V_75 * V_76 ,
unsigned long V_4 , int V_324 , struct V_25 * V_25 )
{
T_2 V_42 , V_325 , V_326 ;
V_23 V_321 ;
unsigned int V_327 , V_328 , V_329 = 0 ;
unsigned long V_330 , V_331 ;
V_42 = V_86 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_86 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_86 ;
V_330 = F_210 ( NULL , V_161 ) ;
V_331 = F_211 ( NULL , V_161 ) ;
V_327 = V_76 -> V_79 ;
if ( V_42 + V_327 >= 1024 ) {
V_329 = 1 ;
V_76 -> V_79 = 0 ;
V_327 = 1024 - V_327 ;
V_328 = F_212 ( V_327 , V_330 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_328 ;
if ( V_25 ) {
V_25 -> V_332 +=
V_4 * V_328 ;
}
}
if ( V_324 )
V_76 -> V_85 += V_328 * V_331 ;
V_42 -= V_327 ;
V_326 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_207 ( V_76 -> V_81 , V_326 + 1 ) ;
if ( V_25 ) {
V_25 -> V_332 =
F_207 ( V_25 -> V_332 , V_326 + 1 ) ;
}
V_76 -> V_85 = F_207 ( ( T_2 ) ( V_76 -> V_85 ) , V_326 + 1 ) ;
V_321 = F_208 ( V_326 ) ;
V_321 = F_212 ( V_321 , V_330 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_321 ;
if ( V_25 )
V_25 -> V_332 += V_4 * V_321 ;
}
if ( V_324 )
V_76 -> V_85 += V_321 * V_331 ;
}
V_325 = F_212 ( V_42 , V_330 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_325 ;
if ( V_25 )
V_25 -> V_332 += V_4 * V_325 ;
}
if ( V_324 )
V_76 -> V_85 += V_325 * V_331 ;
V_76 -> V_79 += V_42 ;
if ( V_329 ) {
V_76 -> V_80 = F_213 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_333 =
F_213 ( V_25 -> V_332 , V_82 ) ;
}
V_76 -> V_83 = V_76 -> V_85 / V_82 ;
}
return V_329 ;
}
static inline void F_214 ( struct V_25 * V_25 , int V_334 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_313 ;
if ( V_25 -> V_33 == & V_335 )
return;
if ( V_334 || abs ( V_42 ) > V_25 -> V_313 / 64 ) {
F_215 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_313 = V_25 -> V_77 . V_80 ;
}
}
void F_216 ( struct V_27 * V_28 ,
struct V_25 * V_336 , struct V_25 * V_58 )
{
if ( ! F_217 ( V_337 ) )
return;
if ( V_28 -> V_77 . V_78 && V_336 ) {
T_2 V_338 ;
T_2 V_339 ;
#ifndef F_40
T_2 V_340 ;
T_2 V_341 ;
do {
V_340 = V_336 -> V_342 ;
V_341 = V_58 -> V_342 ;
F_218 () ;
V_338 = V_336 -> V_77 . V_78 ;
V_339 = V_58 -> V_77 . V_78 ;
} while ( V_338 != V_340 ||
V_339 != V_341 );
#else
V_338 = V_336 -> V_77 . V_78 ;
V_339 = V_58 -> V_77 . V_78 ;
#endif
F_209 ( V_338 , F_26 ( F_16 ( V_336 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
V_28 -> V_77 . V_78 = V_339 ;
}
}
static inline void F_214 ( struct V_25 * V_25 , int V_334 ) {}
static inline int F_219 ( T_2 V_86 , struct V_25 * V_25 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_329 , V_343 = 0 ;
if ( F_202 ( & V_25 -> V_344 ) ) {
T_3 V_345 = F_220 ( & V_25 -> V_344 , 0 ) ;
V_76 -> V_80 = F_85 ( long , V_76 -> V_80 - V_345 , 0 ) ;
V_76 -> V_81 = F_85 ( T_3 , V_76 -> V_81 - V_345 * V_82 , 0 ) ;
V_343 = 1 ;
}
if ( F_202 ( & V_25 -> V_346 ) ) {
long V_345 = F_220 ( & V_25 -> V_346 , 0 ) ;
V_76 -> V_83 = F_85 ( long , V_76 -> V_83 - V_345 , 0 ) ;
V_76 -> V_85 = F_85 ( V_347 , V_76 -> V_85 - V_345 * V_82 , 0 ) ;
}
V_329 = F_209 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_70 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_342 = V_76 -> V_78 ;
#endif
return V_329 || V_343 ;
}
static inline void F_221 ( struct V_27 * V_28 , int V_348 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_86 = F_222 ( V_25 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_161 = F_26 ( V_24 ) ;
F_209 ( V_86 , V_161 , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
if ( F_219 ( V_86 , V_25 ) && V_348 )
F_214 ( V_25 , 0 ) ;
if ( V_161 == F_223 () && & V_24 -> V_40 == V_25 ) {
unsigned long F_65 = V_24 -> V_349 ;
F_224 ( F_73 ( V_24 ) ,
F_140 ( V_25 -> V_77 . V_83 , F_65 ) , F_65 ) ;
}
}
static void F_225 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( ! F_217 ( V_337 ) )
goto V_350;
if ( V_28 -> V_77 . V_78 ) {
F_209 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
}
V_350:
V_28 -> V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_28 -> V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_28 -> V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_28 -> V_77 . V_83 ;
V_25 -> V_77 . V_85 += V_28 -> V_77 . V_85 ;
}
static void F_226 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_209 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
V_25 -> V_77 . V_80 = F_85 ( long , V_25 -> V_77 . V_80 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_77 . V_81 = F_85 ( T_3 , V_25 -> V_77 . V_81 - V_28 -> V_77 . V_81 , 0 ) ;
V_25 -> V_77 . V_83 = F_85 ( long , V_25 -> V_77 . V_83 - V_28 -> V_77 . V_83 , 0 ) ;
V_25 -> V_77 . V_85 = F_85 ( V_347 , V_25 -> V_77 . V_85 - V_28 -> V_77 . V_85 , 0 ) ;
}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_86 = F_222 ( V_25 ) ;
int V_268 , V_329 ;
V_268 = ! V_76 -> V_78 ;
if ( ! V_268 ) {
F_209 ( V_86 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_329 = F_219 ( V_86 , V_25 ) ;
V_25 -> V_333 += V_76 -> V_80 ;
V_25 -> V_332 += V_76 -> V_81 ;
if ( V_268 )
F_225 ( V_25 , V_28 ) ;
if ( V_329 || V_268 )
F_214 ( V_25 , 0 ) ;
}
static inline void
F_228 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_221 ( V_28 , 1 ) ;
V_25 -> V_333 =
F_85 ( long , V_25 -> V_333 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_332 =
F_85 ( T_3 , V_25 -> V_332 - V_28 -> V_77 . V_81 , 0 ) ;
}
static inline T_2 F_229 ( struct V_25 * V_25 )
{
T_2 V_351 ;
T_2 V_78 ;
do {
V_351 = V_25 -> V_342 ;
F_218 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_351 );
return V_78 ;
}
static inline T_2 F_229 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_78 ;
}
void F_230 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_78 ;
if ( V_28 -> V_77 . V_78 == 0 )
return;
V_78 = F_229 ( V_25 ) ;
F_209 ( V_78 , F_26 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_215 ( V_28 -> V_77 . V_80 , & V_25 -> V_344 ) ;
F_215 ( V_28 -> V_77 . V_83 , & V_25 -> V_346 ) ;
}
static inline unsigned long F_231 ( struct V_25 * V_25 )
{
return V_25 -> V_333 ;
}
static inline unsigned long F_232 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline void F_221 ( struct V_27 * V_28 , int V_352 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_233 ( F_73 ( V_24 ) ) ;
}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_228 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_230 ( struct V_27 * V_28 ) {}
static inline void
F_225 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_226 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline int F_234 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_235 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_236
struct V_26 * V_99 = NULL ;
if ( F_20 ( V_28 ) )
V_99 = F_17 ( V_28 ) ;
if ( V_28 -> V_88 . V_102 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_102 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_353 ) )
V_28 -> V_88 . V_353 = V_42 ;
V_28 -> V_88 . V_102 = 0 ;
V_28 -> V_88 . V_354 += V_42 ;
if ( V_99 ) {
F_237 ( V_99 , V_42 >> 10 , 1 ) ;
F_238 ( V_99 , V_42 ) ;
}
}
if ( V_28 -> V_88 . V_104 ) {
T_2 V_42 = F_73 ( F_16 ( V_25 ) ) - V_28 -> V_88 . V_104 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_88 . V_355 ) )
V_28 -> V_88 . V_355 = V_42 ;
V_28 -> V_88 . V_104 = 0 ;
V_28 -> V_88 . V_354 += V_42 ;
if ( V_99 ) {
if ( V_99 -> V_356 ) {
V_28 -> V_88 . V_357 += V_42 ;
V_28 -> V_88 . V_358 ++ ;
F_239 ( V_99 , V_42 ) ;
}
F_240 ( V_99 , V_42 ) ;
if ( F_13 ( V_359 == V_360 ) ) {
F_241 ( V_360 ,
( void * ) F_242 ( V_99 ) ,
V_42 >> 20 ) ;
}
F_237 ( V_99 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_243 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_361 = V_28 -> V_41 - V_25 -> F_36 ;
if ( V_361 < 0 )
V_361 = - V_361 ;
if ( V_361 > 3 * V_68 )
F_244 ( V_25 , V_362 ) ;
#endif
}
static void
F_245 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_363 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_363 && F_217 ( V_364 ) )
V_41 += F_60 ( V_25 , V_28 ) ;
if ( ! V_363 ) {
unsigned long V_365 = V_68 ;
if ( F_217 ( V_366 ) )
V_365 >>= 1 ;
V_41 -= V_365 ;
}
V_28 -> V_41 = F_35 ( V_28 -> V_41 , V_41 ) ;
}
static inline void F_246 ( void )
{
#ifdef F_236
if ( F_247 () )
return;
if ( F_248 () ||
F_249 () ||
F_250 () ||
F_251 () ||
F_252 () ) {
F_253 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_254 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_97 )
{
if ( ! ( V_97 & V_367 ) || ( V_97 & V_368 ) )
V_28 -> V_41 += V_25 -> F_36 ;
F_62 ( V_25 ) ;
F_227 ( V_25 , V_28 ) ;
F_196 ( V_25 , V_28 ) ;
F_205 ( V_25 ) ;
if ( V_97 & V_367 ) {
F_245 ( V_25 , V_28 , 0 ) ;
if ( F_247 () )
F_235 ( V_25 , V_28 ) ;
}
F_246 () ;
if ( F_247 () ) {
F_77 ( V_25 , V_28 ) ;
F_243 ( V_25 , V_28 ) ;
}
if ( V_28 != V_25 -> V_45 )
F_42 ( V_25 , V_28 ) ;
V_28 -> V_74 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_255 ( V_25 ) ;
}
}
static void F_256 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_257 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_258 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_369 != V_28 )
break;
V_25 -> V_369 = NULL ;
}
}
static void F_259 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_256 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_257 ( V_28 ) ;
if ( V_25 -> V_369 == V_28 )
F_258 ( V_28 ) ;
}
static void
F_260 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_97 )
{
F_62 ( V_25 ) ;
F_228 ( V_25 , V_28 ) ;
if ( F_247 () )
F_78 ( V_25 , V_28 , V_97 ) ;
F_259 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_45 ( V_25 , V_28 ) ;
V_28 -> V_74 = 0 ;
F_199 ( V_25 , V_28 ) ;
if ( ! ( V_97 & V_98 ) )
V_28 -> V_41 -= V_25 -> F_36 ;
F_261 ( V_25 ) ;
F_38 ( V_25 ) ;
F_205 ( V_25 ) ;
}
static void
F_262 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_370 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_370 = F_58 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_90 - V_45 -> V_371 ;
if ( V_19 > V_370 ) {
F_263 ( F_16 ( V_25 ) ) ;
F_259 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_48 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_370 )
F_263 ( F_16 ( V_25 ) ) ;
}
static void
F_264 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_74 ) {
if ( F_247 () )
F_75 ( V_25 , V_28 ) ;
F_45 ( V_25 , V_28 ) ;
F_221 ( V_28 , 1 ) ;
}
F_79 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_236
if ( F_247 () && F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_88 . V_372 = F_65 ( V_28 -> V_88 . V_372 ,
V_28 -> V_90 - V_28 -> V_371 ) ;
}
#endif
V_28 -> V_371 = V_28 -> V_90 ;
}
static struct V_27 *
F_265 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_48 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_37 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_369 == V_28 ) {
struct V_27 * V_373 ;
if ( V_28 == V_45 ) {
V_373 = F_48 ( V_25 ) ;
} else {
V_373 = F_49 ( V_28 ) ;
if ( ! V_373 || ( V_45 && F_37 ( V_45 , V_373 ) ) )
V_373 = V_45 ;
}
if ( V_373 && F_266 ( V_373 , V_57 ) < 1 )
V_28 = V_373 ;
}
if ( V_25 -> V_59 && F_266 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_266 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_259 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_267 ( struct V_25 * V_25 , struct V_27 * V_336 )
{
if ( V_336 -> V_74 )
F_62 ( V_25 ) ;
F_268 ( V_25 ) ;
if ( F_247 () ) {
F_243 ( V_25 , V_336 ) ;
if ( V_336 -> V_74 )
F_72 ( V_25 , V_336 ) ;
}
if ( V_336 -> V_74 ) {
F_42 ( V_25 , V_336 ) ;
F_221 ( V_336 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_269 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_374 )
{
F_62 ( V_25 ) ;
F_221 ( V_45 , 1 ) ;
F_205 ( V_25 ) ;
#ifdef F_270
if ( V_374 ) {
F_263 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_217 ( V_375 ) &&
F_271 ( & F_16 ( V_25 ) -> V_376 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_262 ( V_25 , V_45 ) ;
}
static inline bool F_272 ( void )
{
return F_273 ( & V_377 ) ;
}
void F_274 ( void )
{
F_275 ( & V_377 ) ;
}
void F_276 ( void )
{
F_277 ( & V_377 ) ;
}
static bool F_272 ( void )
{
return true ;
}
void F_274 ( void ) {}
void F_276 ( void ) {}
static inline T_2 F_278 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_279 ( void )
{
return ( T_2 ) V_378 * V_379 ;
}
void F_280 ( struct V_380 * V_381 )
{
T_2 V_86 ;
if ( V_381 -> V_382 == V_383 )
return;
V_86 = F_281 ( F_223 () ) ;
V_381 -> V_227 = V_381 -> V_382 ;
V_381 -> V_384 = V_86 + F_282 ( V_381 -> V_226 ) ;
}
static inline struct V_380 * F_283 ( struct V_311 * V_33 )
{
return & V_33 -> V_380 ;
}
static inline T_2 F_222 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_385 ) )
return V_25 -> V_386 ;
return F_63 ( F_16 ( V_25 ) ) - V_25 -> V_387 ;
}
static int F_284 ( struct V_25 * V_25 )
{
struct V_311 * V_33 = V_25 -> V_33 ;
struct V_380 * V_381 = F_283 ( V_33 ) ;
T_2 V_388 = 0 , V_389 , V_390 ;
V_389 = F_279 () - V_25 -> V_391 ;
F_285 ( & V_381 -> V_192 ) ;
if ( V_381 -> V_382 == V_383 )
V_388 = V_389 ;
else {
F_286 ( V_381 ) ;
if ( V_381 -> V_227 > 0 ) {
V_388 = F_140 ( V_381 -> V_227 , V_389 ) ;
V_381 -> V_227 -= V_388 ;
V_381 -> V_392 = 0 ;
}
}
V_390 = V_381 -> V_384 ;
F_287 ( & V_381 -> V_192 ) ;
V_25 -> V_391 += V_388 ;
if ( ( T_3 ) ( V_390 - V_25 -> V_384 ) > 0 )
V_25 -> V_384 = V_390 ;
return V_25 -> V_391 > 0 ;
}
static void F_288 ( struct V_25 * V_25 )
{
struct V_380 * V_381 = F_283 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_73 ( F_16 ( V_25 ) ) - V_25 -> V_384 ) < 0 ) )
return;
if ( V_25 -> V_391 < 0 )
return;
if ( V_25 -> V_384 != V_381 -> V_384 ) {
V_25 -> V_384 += V_293 ;
} else {
V_25 -> V_391 = 0 ;
}
}
static void F_289 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_391 -= V_19 ;
F_288 ( V_25 ) ;
if ( F_11 ( V_25 -> V_391 > 0 ) )
return;
if ( ! F_284 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_263 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_70 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_272 () || ! V_25 -> V_393 )
return;
F_289 ( V_25 , V_19 ) ;
}
static inline int F_290 ( struct V_25 * V_25 )
{
return F_272 () && V_25 -> V_394 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return F_272 () && V_25 -> V_385 ;
}
static inline int F_291 ( struct V_311 * V_33 ,
int V_187 , int V_395 )
{
struct V_25 * V_396 , * V_397 ;
V_396 = V_33 -> V_25 [ V_187 ] ;
V_397 = V_33 -> V_25 [ V_395 ] ;
return F_206 ( V_396 ) ||
F_206 ( V_397 ) ;
}
static int F_292 ( struct V_311 * V_33 , void * V_398 )
{
struct V_24 * V_24 = V_398 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_385 -- ;
#ifdef F_197
if ( ! V_25 -> V_385 ) {
V_25 -> V_387 += F_63 ( V_24 ) -
V_25 -> V_386 ;
}
#endif
return 0 ;
}
static int F_293 ( struct V_311 * V_33 , void * V_398 )
{
struct V_24 * V_24 = V_398 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_385 )
V_25 -> V_386 = F_63 ( V_24 ) ;
V_25 -> V_385 ++ ;
return 0 ;
}
static void F_294 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_380 * V_381 = F_283 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_399 , V_400 = 1 ;
bool V_401 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_119 () ;
F_295 ( V_25 -> V_33 , F_293 , V_402 , ( void * ) V_24 ) ;
F_128 () ;
V_399 = V_25 -> V_403 ;
F_59 (se) {
struct V_25 * V_404 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_74 )
break;
if ( V_400 )
F_260 ( V_404 , V_28 , V_98 ) ;
V_404 -> V_403 -= V_399 ;
if ( V_404 -> V_70 . V_4 )
V_400 = 0 ;
}
if ( ! V_28 )
F_296 ( V_24 , V_399 ) ;
V_25 -> V_394 = 1 ;
V_25 -> V_405 = F_73 ( V_24 ) ;
F_285 ( & V_381 -> V_192 ) ;
V_401 = F_297 ( & V_381 -> V_406 ) ;
F_27 ( & V_25 -> V_407 , & V_381 -> V_406 ) ;
if ( V_401 )
F_286 ( V_381 ) ;
F_287 ( & V_381 -> V_192 ) ;
}
void F_298 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_380 * V_381 = F_283 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_408 = 1 ;
long V_399 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_394 = 0 ;
F_299 ( V_24 ) ;
F_285 ( & V_381 -> V_192 ) ;
V_381 -> V_409 += F_73 ( V_24 ) - V_25 -> V_405 ;
F_30 ( & V_25 -> V_407 ) ;
F_287 ( & V_381 -> V_192 ) ;
F_295 ( V_25 -> V_33 , V_402 , F_292 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_399 = V_25 -> V_403 ;
F_59 (se) {
if ( V_28 -> V_74 )
V_408 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_408 )
F_254 ( V_25 , V_28 , V_367 ) ;
V_25 -> V_403 += V_399 ;
if ( F_290 ( V_25 ) )
break;
}
if ( ! V_28 )
F_300 ( V_24 , V_399 ) ;
if ( V_24 -> V_45 == V_24 -> V_392 && V_24 -> V_40 . V_72 )
F_263 ( V_24 ) ;
}
static T_2 F_301 ( struct V_380 * V_381 ,
T_2 V_410 , T_2 V_390 )
{
struct V_25 * V_25 ;
T_2 V_227 ;
T_2 V_411 = V_410 ;
F_119 () ;
F_302 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_285 ( & V_24 -> V_192 ) ;
if ( ! F_290 ( V_25 ) )
goto V_58;
V_227 = - V_25 -> V_391 + 1 ;
if ( V_227 > V_410 )
V_227 = V_410 ;
V_410 -= V_227 ;
V_25 -> V_391 += V_227 ;
V_25 -> V_384 = V_390 ;
if ( V_25 -> V_391 > 0 )
F_298 ( V_25 ) ;
V_58:
F_287 ( & V_24 -> V_192 ) ;
if ( ! V_410 )
break;
}
F_128 () ;
return V_411 - V_410 ;
}
static int F_303 ( struct V_380 * V_381 , int V_412 )
{
T_2 V_227 , V_384 ;
int V_394 ;
if ( V_381 -> V_382 == V_383 )
goto V_413;
V_394 = ! F_297 ( & V_381 -> V_406 ) ;
V_381 -> V_414 += V_412 ;
if ( V_381 -> V_392 && ! V_394 )
goto V_413;
F_280 ( V_381 ) ;
if ( ! V_394 ) {
V_381 -> V_392 = 1 ;
return 0 ;
}
V_381 -> V_415 += V_412 ;
V_384 = V_381 -> V_384 ;
while ( V_394 && V_381 -> V_227 > 0 ) {
V_227 = V_381 -> V_227 ;
F_287 ( & V_381 -> V_192 ) ;
V_227 = F_301 ( V_381 , V_227 ,
V_384 ) ;
F_285 ( & V_381 -> V_192 ) ;
V_394 = ! F_297 ( & V_381 -> V_406 ) ;
V_381 -> V_227 -= F_140 ( V_227 , V_381 -> V_227 ) ;
}
V_381 -> V_392 = 0 ;
return 0 ;
V_413:
return 1 ;
}
static int F_304 ( struct V_380 * V_381 , T_2 V_416 )
{
struct V_417 * V_418 = & V_381 -> V_419 ;
T_2 V_410 ;
if ( F_305 ( V_418 ) )
return 1 ;
V_410 = F_282 ( F_306 ( V_418 ) ) ;
if ( V_410 < V_416 )
return 1 ;
return 0 ;
}
static void F_307 ( struct V_380 * V_381 )
{
T_2 V_420 = V_421 + V_422 ;
if ( F_304 ( V_381 , V_420 ) )
return;
F_308 ( & V_381 -> V_423 ,
F_309 ( V_421 ) ,
V_424 ) ;
}
static void F_310 ( struct V_25 * V_25 )
{
struct V_380 * V_381 = F_283 ( V_25 -> V_33 ) ;
T_3 V_425 = V_25 -> V_391 - V_426 ;
if ( V_425 <= 0 )
return;
F_285 ( & V_381 -> V_192 ) ;
if ( V_381 -> V_382 != V_383 &&
V_25 -> V_384 == V_381 -> V_384 ) {
V_381 -> V_227 += V_425 ;
if ( V_381 -> V_227 > F_279 () &&
! F_297 ( & V_381 -> V_406 ) )
F_307 ( V_381 ) ;
}
F_287 ( & V_381 -> V_192 ) ;
V_25 -> V_391 -= V_425 ;
}
static T_10 void F_261 ( struct V_25 * V_25 )
{
if ( ! F_272 () )
return;
if ( ! V_25 -> V_393 || V_25 -> V_72 )
return;
F_310 ( V_25 ) ;
}
static void F_311 ( struct V_380 * V_381 )
{
T_2 V_227 = 0 , V_73 = F_279 () ;
T_2 V_390 ;
F_285 ( & V_381 -> V_192 ) ;
if ( F_304 ( V_381 , V_422 ) ) {
F_287 ( & V_381 -> V_192 ) ;
return;
}
if ( V_381 -> V_382 != V_383 && V_381 -> V_227 > V_73 )
V_227 = V_381 -> V_227 ;
V_390 = V_381 -> V_384 ;
F_287 ( & V_381 -> V_192 ) ;
if ( ! V_227 )
return;
V_227 = F_301 ( V_381 , V_227 , V_390 ) ;
F_285 ( & V_381 -> V_192 ) ;
if ( V_390 == V_381 -> V_384 )
V_381 -> V_227 -= F_140 ( V_227 , V_381 -> V_227 ) ;
F_287 ( & V_381 -> V_192 ) ;
}
static void F_255 ( struct V_25 * V_25 )
{
if ( ! F_272 () )
return;
if ( ! V_25 -> V_393 || V_25 -> V_45 )
return;
if ( F_290 ( V_25 ) )
return;
F_70 ( V_25 , 0 ) ;
if ( V_25 -> V_391 <= 0 )
F_294 ( V_25 ) ;
}
static bool F_268 ( struct V_25 * V_25 )
{
if ( ! F_272 () )
return false ;
if ( F_11 ( ! V_25 -> V_393 || V_25 -> V_391 > 0 ) )
return false ;
if ( F_290 ( V_25 ) )
return true ;
F_294 ( V_25 ) ;
return true ;
}
static enum V_427 F_312 ( struct V_417 * V_428 )
{
struct V_380 * V_381 =
F_21 ( V_428 , struct V_380 , V_423 ) ;
F_311 ( V_381 ) ;
return V_429 ;
}
static enum V_427 F_313 ( struct V_417 * V_428 )
{
struct V_380 * V_381 =
F_21 ( V_428 , struct V_380 , V_419 ) ;
int V_412 ;
int V_392 = 0 ;
F_285 ( & V_381 -> V_192 ) ;
for (; ; ) {
V_412 = F_314 ( V_428 , V_381 -> V_226 ) ;
if ( ! V_412 )
break;
V_392 = F_303 ( V_381 , V_412 ) ;
}
if ( V_392 )
V_381 -> V_430 = 0 ;
F_287 ( & V_381 -> V_192 ) ;
return V_392 ? V_429 : V_431 ;
}
void F_315 ( struct V_380 * V_381 )
{
F_316 ( & V_381 -> V_192 ) ;
V_381 -> V_227 = 0 ;
V_381 -> V_382 = V_383 ;
V_381 -> V_226 = F_309 ( F_278 () ) ;
F_317 ( & V_381 -> V_406 ) ;
F_318 ( & V_381 -> V_419 , V_432 , V_433 ) ;
V_381 -> V_419 . V_434 = F_313 ;
F_318 ( & V_381 -> V_423 , V_432 , V_424 ) ;
V_381 -> V_423 . V_434 = F_312 ;
}
static void F_319 ( struct V_25 * V_25 )
{
V_25 -> V_393 = 0 ;
F_317 ( & V_25 -> V_407 ) ;
}
void F_286 ( struct V_380 * V_381 )
{
F_320 ( & V_381 -> V_192 ) ;
if ( ! V_381 -> V_430 ) {
V_381 -> V_430 = 1 ;
F_314 ( & V_381 -> V_419 , V_381 -> V_226 ) ;
F_321 ( & V_381 -> V_419 , V_433 ) ;
}
}
static void F_322 ( struct V_380 * V_381 )
{
if ( ! V_381 -> V_406 . V_58 )
return;
F_323 ( & V_381 -> V_419 ) ;
F_323 ( & V_381 -> V_423 ) ;
}
static void T_11 F_324 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_325 (rq, cfs_rq) {
struct V_380 * V_381 = & V_25 -> V_33 -> V_380 ;
F_285 ( & V_381 -> V_192 ) ;
V_25 -> V_393 = V_381 -> V_382 != V_383 ;
F_287 ( & V_381 -> V_192 ) ;
}
}
static void T_11 F_326 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_325 (rq, cfs_rq) {
if ( ! V_25 -> V_393 )
continue;
V_25 -> V_391 = 1 ;
V_25 -> V_393 = 0 ;
if ( F_290 ( V_25 ) )
F_298 ( V_25 ) ;
}
}
static inline T_2 F_222 ( struct V_25 * V_25 )
{
return F_63 ( F_16 ( V_25 ) ) ;
}
static void F_70 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_268 ( struct V_25 * V_25 ) { return false ; }
static void F_255 ( struct V_25 * V_25 ) {}
static T_10 void F_261 ( struct V_25 * V_25 ) {}
static inline int F_290 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_291 ( struct V_311 * V_33 ,
int V_187 , int V_395 )
{
return 0 ;
}
void F_315 ( struct V_380 * V_381 ) {}
static void F_319 ( struct V_25 * V_25 ) {}
static inline struct V_380 * F_283 ( struct V_311 * V_33 )
{
return NULL ;
}
static inline void F_322 ( struct V_380 * V_381 ) {}
static inline void F_324 ( struct V_24 * V_24 ) {}
static inline void F_326 ( struct V_24 * V_24 ) {}
static void F_327 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_328 ( F_34 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_73 = F_58 ( V_25 , V_28 ) ;
T_2 V_435 = V_28 -> V_90 - V_28 -> V_371 ;
T_3 V_42 = V_73 - V_435 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_263 ( V_24 ) ;
return;
}
F_329 ( V_24 , V_42 ) ;
}
}
static void F_330 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_331 ( V_24 ) || V_45 -> V_436 != & V_437 )
return;
if ( F_23 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_327 ( V_24 , V_45 ) ;
}
static inline void
F_327 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_330 ( struct V_24 * V_24 )
{
}
static void
F_332 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_97 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_59 (se) {
if ( V_28 -> V_74 )
break;
V_25 = F_23 ( V_28 ) ;
F_254 ( V_25 , V_28 , V_97 ) ;
if ( F_290 ( V_25 ) )
break;
V_25 -> V_403 ++ ;
V_97 = V_367 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_403 ++ ;
if ( F_290 ( V_25 ) )
break;
F_221 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_300 ( V_24 , 1 ) ;
F_330 ( V_24 ) ;
}
static void F_333 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_97 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_438 = V_97 & V_98 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_260 ( V_25 , V_28 , V_97 ) ;
if ( F_290 ( V_25 ) )
break;
V_25 -> V_403 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_438 && F_32 ( V_28 ) )
F_334 ( F_32 ( V_28 ) ) ;
V_28 = F_32 ( V_28 ) ;
break;
}
V_97 |= V_98 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_403 -- ;
if ( F_290 ( V_25 ) )
break;
F_221 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_296 ( V_24 , 1 ) ;
F_330 ( V_24 ) ;
}
static unsigned long
F_335 ( unsigned long V_70 , unsigned long V_439 , int V_440 )
{
int V_441 = 0 ;
if ( ! V_439 )
return V_70 ;
if ( V_439 >= V_442 [ V_440 ] )
return 0 ;
if ( V_440 == 1 )
return V_70 >> V_439 ;
while ( V_439 ) {
if ( V_439 % 2 )
V_70 = ( V_70 * V_443 [ V_440 ] [ V_441 ] ) >> V_444 ;
V_439 >>= 1 ;
V_441 ++ ;
}
return V_70 ;
}
static void F_336 ( struct V_24 * V_445 , unsigned long V_446 ,
unsigned long V_447 , int V_448 )
{
unsigned long V_449 = V_448 ? V_445 -> V_450 [ 0 ] : 0 ;
int V_258 , V_451 ;
V_445 -> V_452 ++ ;
V_445 -> V_450 [ 0 ] = V_446 ;
for ( V_258 = 1 , V_451 = 2 ; V_258 < V_453 ; V_258 ++ , V_451 += V_451 ) {
unsigned long V_454 , V_455 ;
V_454 = V_445 -> V_450 [ V_258 ] ;
V_454 = F_335 ( V_454 , V_447 - 1 , V_258 ) ;
if ( V_449 ) {
V_454 -= F_335 ( V_449 , V_447 - 1 , V_258 ) ;
V_454 += V_449 ;
}
V_455 = V_446 ;
if ( V_455 > V_454 )
V_455 += V_451 - 1 ;
V_445 -> V_450 [ V_258 ] = ( V_454 * ( V_451 - 1 ) + V_455 ) >> V_258 ;
}
F_337 ( V_445 ) ;
}
static unsigned long F_111 ( const int V_161 )
{
return F_231 ( & F_110 ( V_161 ) -> V_40 ) ;
}
static void F_338 ( struct V_24 * V_445 ,
unsigned long V_456 ,
unsigned long V_70 ,
int V_448 )
{
unsigned long V_447 ;
V_447 = V_456 - V_445 -> V_457 ;
if ( V_447 ) {
V_445 -> V_457 = V_456 ;
F_336 ( V_445 , V_70 , V_447 , V_448 ) ;
}
}
static void F_339 ( struct V_24 * V_445 )
{
if ( F_111 ( F_26 ( V_445 ) ) )
return;
F_338 ( V_445 , F_84 ( V_211 ) , 0 , 0 ) ;
}
void F_340 ( int V_448 )
{
struct V_24 * V_445 = V_445 () ;
unsigned long V_456 = F_84 ( V_211 ) ;
unsigned long V_70 = V_448 ? F_111 ( F_26 ( V_445 ) ) : 0 ;
if ( V_456 == V_445 -> V_457 )
return;
F_285 ( & V_445 -> V_192 ) ;
F_338 ( V_445 , V_456 , V_70 , V_448 ) ;
F_287 ( & V_445 -> V_192 ) ;
}
void F_341 ( struct V_24 * V_445 )
{
unsigned long V_70 = F_111 ( F_26 ( V_445 ) ) ;
V_445 -> V_457 = V_211 ;
F_336 ( V_445 , V_70 , 1 , 1 ) ;
}
static unsigned long F_342 ( int V_161 , int type )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
unsigned long V_458 = F_111 ( V_161 ) ;
if ( type == 0 || ! F_217 ( V_459 ) )
return V_458 ;
return F_140 ( V_24 -> V_450 [ type - 1 ] , V_458 ) ;
}
static unsigned long F_343 ( int V_161 , int type )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
unsigned long V_458 = F_111 ( V_161 ) ;
if ( type == 0 || ! F_217 ( V_459 ) )
return V_458 ;
return F_65 ( V_24 -> V_450 [ type - 1 ] , V_458 ) ;
}
static unsigned long F_112 ( int V_161 )
{
return F_110 ( V_161 ) -> V_460 ;
}
static unsigned long F_344 ( int V_161 )
{
return F_110 ( V_161 ) -> V_349 ;
}
static unsigned long F_345 ( int V_161 )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
unsigned long V_72 = F_84 ( V_24 -> V_40 . V_403 ) ;
unsigned long V_80 = F_111 ( V_161 ) ;
if ( V_72 )
return V_80 / V_72 ;
return 0 ;
}
static void F_346 ( struct V_26 * V_29 )
{
if ( F_178 ( V_211 , V_156 -> V_461 + V_209 ) ) {
V_156 -> V_462 >>= 1 ;
V_156 -> V_461 = V_211 ;
}
if ( V_156 -> V_463 != V_29 ) {
V_156 -> V_463 = V_29 ;
V_156 -> V_462 ++ ;
}
}
static void F_347 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_218 () ;
F_36 = V_25 -> F_36 ;
} while ( F_36 != V_48 );
#else
F_36 = V_25 -> F_36 ;
#endif
V_28 -> V_41 -= F_36 ;
F_346 ( V_29 ) ;
}
static long F_348 ( struct V_311 * V_33 , int V_161 , long V_464 , long V_465 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_161 ] ;
if ( ! V_33 -> V_34 )
return V_464 ;
F_59 (se) {
long V_7 , V_466 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_466 = V_465 + F_201 ( V_33 , V_28 -> V_31 ) ;
V_7 = F_232 ( V_28 -> V_31 ) + V_464 ;
if ( V_466 > 0 && V_7 < V_466 )
V_464 = ( V_7 * ( long ) V_33 -> V_314 ) / V_466 ;
else
V_464 = V_33 -> V_314 ;
if ( V_464 < V_315 )
V_464 = V_315 ;
V_464 -= V_28 -> V_77 . V_80 ;
V_465 = 0 ;
}
return V_464 ;
}
static long F_348 ( struct V_311 * V_33 , int V_161 , long V_464 , long V_465 )
{
return V_464 ;
}
static int F_349 ( struct V_26 * V_29 )
{
unsigned int V_467 = V_156 -> V_462 ;
unsigned int V_468 = V_29 -> V_462 ;
int V_9 = F_350 ( V_469 ) ;
if ( V_467 < V_468 )
F_117 ( V_467 , V_468 ) ;
if ( V_468 < V_9 || V_467 < V_468 * V_9 )
return 0 ;
return 1 ;
}
static int F_351 ( struct V_199 * V_200 , struct V_26 * V_29 , int V_470 )
{
T_3 V_446 , V_70 ;
T_3 V_471 , V_472 ;
int V_440 , V_473 , V_474 ;
struct V_311 * V_33 ;
unsigned long V_4 ;
int V_475 ;
V_440 = V_200 -> V_476 ;
V_473 = F_223 () ;
V_474 = F_132 ( V_29 ) ;
V_70 = F_342 ( V_474 , V_440 ) ;
V_446 = F_343 ( V_473 , V_440 ) ;
if ( V_470 ) {
V_33 = V_311 ( V_156 ) ;
V_4 = V_156 -> V_28 . V_77 . V_80 ;
V_446 += F_348 ( V_33 , V_473 , - V_4 , - V_4 ) ;
V_70 += F_348 ( V_33 , V_474 , 0 , - V_4 ) ;
}
V_33 = V_311 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_471 = 100 ;
V_471 *= F_112 ( V_474 ) ;
V_472 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
V_472 *= F_112 ( V_473 ) ;
if ( V_446 > 0 ) {
V_471 *= V_446 +
F_348 ( V_33 , V_473 , V_4 , V_4 ) ;
V_472 *= V_70 + F_348 ( V_33 , V_474 , 0 , V_4 ) ;
}
V_475 = V_471 <= V_472 ;
F_244 ( V_29 , V_28 . V_88 . V_477 ) ;
if ( ! V_475 )
return 0 ;
F_244 ( V_200 , V_478 ) ;
F_244 ( V_29 , V_28 . V_88 . V_479 ) ;
return 1 ;
}
static struct V_480 *
F_352 ( struct V_199 * V_200 , struct V_26 * V_29 ,
int V_473 , int V_481 )
{
struct V_480 * V_482 = NULL , * V_132 = V_200 -> V_483 ;
unsigned long V_484 = V_485 , V_446 = 0 ;
int V_486 = V_200 -> V_487 ;
int V_488 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
if ( V_481 & V_489 )
V_486 = V_200 -> V_476 ;
do {
unsigned long V_70 , V_490 ;
int V_491 ;
int V_258 ;
if ( ! F_353 ( F_354 ( V_132 ) ,
F_125 ( V_29 ) ) )
continue;
V_491 = F_124 ( V_473 ,
F_354 ( V_132 ) ) ;
V_490 = 0 ;
F_109 (i, sched_group_cpus(group)) {
if ( V_491 )
V_70 = F_342 ( V_258 , V_486 ) ;
else
V_70 = F_343 ( V_258 , V_486 ) ;
V_490 += V_70 ;
}
V_490 = ( V_490 * V_164 ) / V_132 -> V_492 -> V_162 ;
if ( V_491 ) {
V_446 = V_490 ;
} else if ( V_490 < V_484 ) {
V_484 = V_490 ;
V_482 = V_132 ;
}
} while ( V_132 = V_132 -> V_58 , V_132 != V_200 -> V_483 );
if ( ! V_482 || 100 * V_446 < V_488 * V_484 )
return NULL ;
return V_482 ;
}
static int
F_355 ( struct V_480 * V_132 , struct V_26 * V_29 , int V_473 )
{
unsigned long V_70 , V_484 = V_485 ;
unsigned int V_493 = V_494 ;
T_2 V_495 = 0 ;
int V_496 = V_473 ;
int V_497 = - 1 ;
int V_258 ;
F_356 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_357 ( V_258 ) ) {
struct V_24 * V_24 = F_110 ( V_258 ) ;
struct V_498 * V_392 = F_358 ( V_24 ) ;
if ( V_392 && V_392 -> V_499 < V_493 ) {
V_493 = V_392 -> V_499 ;
V_495 = V_24 -> V_500 ;
V_497 = V_258 ;
} else if ( ( ! V_392 || V_392 -> V_499 == V_493 ) &&
V_24 -> V_500 > V_495 ) {
V_495 = V_24 -> V_500 ;
V_497 = V_258 ;
}
} else if ( V_497 == - 1 ) {
V_70 = F_111 ( V_258 ) ;
if ( V_70 < V_484 || ( V_70 == V_484 && V_258 == V_473 ) ) {
V_484 = V_70 ;
V_496 = V_258 ;
}
}
}
return V_497 != - 1 ? V_497 : V_496 ;
}
static int F_127 ( struct V_26 * V_29 , int V_501 )
{
struct V_199 * V_200 ;
struct V_480 * V_502 ;
int V_258 = F_132 ( V_29 ) ;
if ( F_357 ( V_501 ) )
return V_501 ;
if ( V_258 != V_501 && F_359 ( V_258 , V_501 ) && F_357 ( V_258 ) )
return V_258 ;
V_200 = F_133 ( F_134 ( V_503 , V_501 ) ) ;
F_360 (sd) {
V_502 = V_200 -> V_483 ;
do {
if ( ! F_353 ( F_354 ( V_502 ) ,
F_125 ( V_29 ) ) )
goto V_58;
F_109 (i, sched_group_cpus(sg)) {
if ( V_258 == V_501 || ! F_357 ( V_258 ) )
goto V_58;
}
V_501 = F_361 ( F_354 ( V_502 ) ,
F_125 ( V_29 ) ) ;
goto V_504;
V_58:
V_502 = V_502 -> V_58 ;
} while ( V_502 != V_200 -> V_483 );
}
V_504:
return V_501 ;
}
static int F_362 ( int V_161 )
{
unsigned long V_505 = F_110 ( V_161 ) -> V_40 . V_77 . V_83 ;
unsigned long V_162 = F_344 ( V_161 ) ;
return ( V_505 >= V_162 ) ? V_162 : V_505 ;
}
static int
F_363 ( struct V_26 * V_29 , int V_474 , int V_481 , int V_506 )
{
struct V_199 * V_507 , * V_508 = NULL , * V_200 = NULL ;
int V_161 = F_223 () ;
int V_509 = V_474 ;
int V_510 = 0 ;
int V_470 = V_506 & V_511 ;
if ( V_481 & V_489 )
V_510 = ! F_349 ( V_29 ) && F_124 ( V_161 , F_125 ( V_29 ) ) ;
F_119 () ;
F_364 (cpu, tmp) {
if ( ! ( V_507 -> V_97 & V_512 ) )
break;
if ( V_510 && ( V_507 -> V_97 & V_513 ) &&
F_124 ( V_474 , F_365 ( V_507 ) ) ) {
V_508 = V_507 ;
break;
}
if ( V_507 -> V_97 & V_481 )
V_200 = V_507 ;
else if ( ! V_510 )
break;
}
if ( V_508 ) {
V_200 = NULL ;
if ( V_161 != V_474 && F_351 ( V_508 , V_29 , V_470 ) )
V_509 = V_161 ;
}
if ( ! V_200 ) {
if ( V_481 & V_489 )
V_509 = F_127 ( V_29 , V_509 ) ;
} else while ( V_200 ) {
struct V_480 * V_132 ;
int V_4 ;
if ( ! ( V_200 -> V_97 & V_481 ) ) {
V_200 = V_200 -> V_514 ;
continue;
}
V_132 = F_352 ( V_200 , V_29 , V_161 , V_481 ) ;
if ( ! V_132 ) {
V_200 = V_200 -> V_514 ;
continue;
}
V_509 = F_355 ( V_132 , V_29 , V_161 ) ;
if ( V_509 == - 1 || V_509 == V_161 ) {
V_200 = V_200 -> V_514 ;
continue;
}
V_161 = V_509 ;
V_4 = V_200 -> V_515 ;
V_200 = NULL ;
F_364 (cpu, tmp) {
if ( V_4 <= V_507 -> V_515 )
break;
if ( V_507 -> V_97 & V_481 )
V_200 = V_507 ;
}
}
F_128 () ;
return V_509 ;
}
static void F_366 ( struct V_26 * V_29 )
{
F_230 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_87 = 0 ;
}
static void F_367 ( struct V_26 * V_29 )
{
F_230 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_368 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_516 = V_517 ;
return F_56 ( V_516 , V_28 ) ;
}
static int
F_266 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_516 , V_518 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_518 <= 0 )
return - 1 ;
V_516 = F_368 ( V_45 , V_28 ) ;
if ( V_518 > V_516 )
return 1 ;
return 0 ;
}
static void F_369 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_519 == V_520 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_334 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_519 == V_520 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_370 ( struct V_27 * V_28 )
{
F_59 (se)
F_23 ( V_28 ) -> V_369 = V_28 ;
}
static void F_371 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_506 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_451 = V_25 -> V_72 >= V_67 ;
int V_521 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_206 ( F_23 ( V_36 ) ) ) )
return;
if ( F_217 ( V_522 ) && V_451 && ! ( V_506 & V_523 ) ) {
F_334 ( V_36 ) ;
V_521 = 1 ;
}
if ( F_372 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_519 == V_520 ) &&
F_11 ( V_29 -> V_519 != V_520 ) )
goto V_524;
if ( F_13 ( V_29 -> V_519 != V_525 ) || ! F_217 ( V_526 ) )
return;
F_33 ( & V_28 , & V_36 ) ;
F_62 ( F_23 ( V_28 ) ) ;
F_167 ( ! V_36 ) ;
if ( F_266 ( V_28 , V_36 ) == 1 ) {
if ( ! V_521 )
F_334 ( V_36 ) ;
goto V_524;
}
return;
V_524:
F_263 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_74 || V_45 == V_24 -> V_392 ) )
return;
if ( F_217 ( V_527 ) && V_451 && F_20 ( V_28 ) )
F_369 ( V_28 ) ;
}
static struct V_26 *
F_373 ( struct V_24 * V_24 , struct V_26 * V_336 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_528 ;
V_529:
#ifdef F_374
if ( ! V_25 -> V_72 )
goto V_392;
if ( V_336 -> V_436 != & V_437 )
goto V_530;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_74 )
F_62 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_268 ( V_25 ) ) )
goto V_530;
}
V_28 = F_265 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_336 != V_29 ) {
struct V_27 * V_36 = & V_336 -> V_28 ;
while ( ! ( V_25 = F_31 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_267 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_32 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_264 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_32 ( V_28 ) ;
}
}
F_267 ( V_25 , V_36 ) ;
F_264 ( V_25 , V_28 ) ;
}
if ( F_331 ( V_24 ) )
F_327 ( V_24 , V_29 ) ;
return V_29 ;
V_530:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_392;
F_375 ( V_24 , V_336 ) ;
do {
V_28 = F_265 ( V_25 , NULL ) ;
F_264 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_331 ( V_24 ) )
F_327 ( V_24 , V_29 ) ;
return V_29 ;
V_392:
F_376 ( & V_24 -> V_192 ) ;
V_528 = F_234 ( V_24 ) ;
F_377 ( & V_24 -> V_192 ) ;
if ( V_528 < 0 )
return V_531 ;
if ( V_528 > 0 )
goto V_529;
return NULL ;
}
static void F_378 ( struct V_24 * V_24 , struct V_26 * V_336 )
{
struct V_27 * V_28 = & V_336 -> V_28 ;
struct V_25 * V_25 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_267 ( V_25 , V_28 ) ;
}
}
static void F_379 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_259 ( V_25 , V_28 ) ;
if ( V_45 -> V_519 != V_532 ) {
F_299 ( V_24 ) ;
F_62 ( V_25 ) ;
F_380 ( V_24 , true ) ;
}
F_370 ( V_28 ) ;
}
static bool F_381 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_524 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_74 || F_206 ( F_23 ( V_28 ) ) )
return false ;
F_334 ( V_28 ) ;
F_379 ( V_24 ) ;
return true ;
}
static int F_382 ( struct V_26 * V_29 , struct V_533 * V_168 )
{
T_3 V_42 ;
F_320 ( & V_168 -> V_186 -> V_192 ) ;
if ( V_29 -> V_436 != & V_437 )
return 0 ;
if ( F_13 ( V_29 -> V_519 == V_520 ) )
return 0 ;
if ( F_217 ( V_534 ) && V_168 -> V_188 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_535 == - 1 )
return 1 ;
if ( V_535 == 0 )
return 0 ;
V_42 = F_63 ( V_168 -> V_186 ) - V_29 -> V_28 . V_87 ;
return V_42 < ( T_3 ) V_535 ;
}
static int F_383 ( struct V_26 * V_29 , struct V_533 * V_168 )
{
struct V_121 * V_121 = F_133 ( V_29 -> V_121 ) ;
unsigned long V_536 , V_537 ;
int V_151 , V_153 ;
if ( ! F_177 ( & V_272 ) )
return - 1 ;
if ( ! V_29 -> V_129 || ! ( V_168 -> V_200 -> V_97 & V_538 ) )
return - 1 ;
V_151 = F_102 ( V_168 -> V_187 ) ;
V_153 = F_102 ( V_168 -> V_152 ) ;
if ( V_151 == V_153 )
return - 1 ;
if ( V_151 == V_29 -> V_119 ) {
if ( V_168 -> V_186 -> V_72 > V_168 -> V_186 -> V_120 )
return 1 ;
else
return - 1 ;
}
if ( V_153 == V_29 -> V_119 )
return 0 ;
if ( V_121 ) {
V_536 = F_93 ( V_29 , V_151 ) ;
V_537 = F_93 ( V_29 , V_153 ) ;
} else {
V_536 = F_92 ( V_29 , V_151 ) ;
V_537 = F_92 ( V_29 , V_153 ) ;
}
return V_537 < V_536 ;
}
static inline int F_383 ( struct V_26 * V_29 ,
struct V_533 * V_168 )
{
return - 1 ;
}
static
int F_384 ( struct V_26 * V_29 , struct V_533 * V_168 )
{
int V_539 ;
F_320 ( & V_168 -> V_186 -> V_192 ) ;
if ( F_291 ( V_311 ( V_29 ) , V_168 -> V_187 , V_168 -> V_152 ) )
return 0 ;
if ( ! F_124 ( V_168 -> V_152 , F_125 ( V_29 ) ) ) {
int V_161 ;
F_244 ( V_29 , V_28 . V_88 . V_540 ) ;
V_168 -> V_97 |= V_541 ;
if ( ! V_168 -> V_542 || ( V_168 -> V_97 & V_543 ) )
return 0 ;
F_356 (cpu, env->dst_grpmask, env->cpus) {
if ( F_124 ( V_161 , F_125 ( V_29 ) ) ) {
V_168 -> V_97 |= V_543 ;
V_168 -> V_544 = V_161 ;
break;
}
}
return 0 ;
}
V_168 -> V_97 &= ~ V_545 ;
if ( F_385 ( V_168 -> V_186 , V_29 ) ) {
F_244 ( V_29 , V_28 . V_88 . V_546 ) ;
return 0 ;
}
V_539 = F_383 ( V_29 , V_168 ) ;
if ( V_539 == - 1 )
V_539 = F_382 ( V_29 , V_168 ) ;
if ( V_539 <= 0 ||
V_168 -> V_200 -> V_547 > V_168 -> V_200 -> V_548 ) {
if ( V_539 == 1 ) {
F_244 ( V_168 -> V_200 , V_549 [ V_168 -> V_392 ] ) ;
F_244 ( V_29 , V_28 . V_88 . V_550 ) ;
}
return 1 ;
}
F_244 ( V_29 , V_28 . V_88 . V_551 ) ;
return 0 ;
}
static void F_386 ( struct V_26 * V_29 , struct V_533 * V_168 )
{
F_320 ( & V_168 -> V_186 -> V_192 ) ;
V_29 -> V_74 = V_552 ;
F_387 ( V_168 -> V_186 , V_29 , 0 ) ;
F_388 ( V_29 , V_168 -> V_152 ) ;
}
static struct V_26 * F_389 ( struct V_533 * V_168 )
{
struct V_26 * V_29 , * V_317 ;
F_320 ( & V_168 -> V_186 -> V_192 ) ;
F_390 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_384 ( V_29 , V_168 ) )
continue;
F_386 ( V_29 , V_168 ) ;
F_244 ( V_168 -> V_200 , V_553 [ V_168 -> V_392 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_391 ( struct V_533 * V_168 )
{
struct V_554 * V_555 = & V_168 -> V_186 -> V_310 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_556 = 0 ;
F_320 ( & V_168 -> V_186 -> V_192 ) ;
if ( V_168 -> V_488 <= 0 )
return 0 ;
while ( ! F_297 ( V_555 ) ) {
if ( V_168 -> V_392 != V_557 && V_168 -> V_186 -> V_72 <= 1 )
break;
V_29 = F_392 ( V_555 , struct V_26 , V_28 . V_309 ) ;
V_168 -> V_558 ++ ;
if ( V_168 -> V_558 > V_168 -> V_559 )
break;
if ( V_168 -> V_558 > V_168 -> V_560 ) {
V_168 -> V_560 += V_561 ;
V_168 -> V_97 |= V_562 ;
break;
}
if ( ! F_384 ( V_29 , V_168 ) )
goto V_58;
V_70 = F_126 ( V_29 ) ;
if ( F_217 ( V_563 ) && V_70 < 16 && ! V_168 -> V_200 -> V_547 )
goto V_58;
if ( ( V_70 / 2 ) > V_168 -> V_488 )
goto V_58;
F_386 ( V_29 , V_168 ) ;
F_198 ( & V_29 -> V_28 . V_309 , & V_168 -> V_555 ) ;
V_556 ++ ;
V_168 -> V_488 -= V_70 ;
#ifdef F_393
if ( V_168 -> V_392 == V_564 )
break;
#endif
if ( V_168 -> V_488 <= 0 )
break;
continue;
V_58:
F_394 ( & V_29 -> V_28 . V_309 , V_555 ) ;
}
F_66 ( V_168 -> V_200 , V_553 [ V_168 -> V_392 ] , V_556 ) ;
return V_556 ;
}
static void F_395 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_320 ( & V_24 -> V_192 ) ;
F_167 ( F_34 ( V_29 ) != V_24 ) ;
F_396 ( V_24 , V_29 , 0 ) ;
V_29 -> V_74 = V_565 ;
F_397 ( V_24 , V_29 , 0 ) ;
}
static void F_398 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_285 ( & V_24 -> V_192 ) ;
F_395 ( V_24 , V_29 ) ;
F_287 ( & V_24 -> V_192 ) ;
}
static void F_399 ( struct V_533 * V_168 )
{
struct V_554 * V_555 = & V_168 -> V_555 ;
struct V_26 * V_29 ;
F_285 ( & V_168 -> V_188 -> V_192 ) ;
while ( ! F_297 ( V_555 ) ) {
V_29 = F_392 ( V_555 , struct V_26 , V_28 . V_309 ) ;
F_200 ( & V_29 -> V_28 . V_309 ) ;
F_395 ( V_168 -> V_188 , V_29 ) ;
}
F_287 ( & V_168 -> V_188 -> V_192 ) ;
}
static void F_400 ( int V_161 )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
struct V_25 * V_25 ;
unsigned long V_97 ;
F_401 ( & V_24 -> V_192 , V_97 ) ;
F_299 ( V_24 ) ;
F_325 (rq, cfs_rq) {
if ( F_206 ( V_25 ) )
continue;
if ( F_219 ( F_222 ( V_25 ) , V_25 ) )
F_214 ( V_25 , 0 ) ;
}
F_402 ( & V_24 -> V_192 , V_97 ) ;
}
static void F_403 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_86 = V_211 ;
unsigned long V_70 ;
if ( V_25 -> V_566 == V_86 )
return;
V_25 -> V_567 = NULL ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_567 = V_28 ;
if ( V_25 -> V_566 == V_86 )
break;
}
if ( ! V_28 ) {
V_25 -> V_568 = F_232 ( V_25 ) ;
V_25 -> V_566 = V_86 ;
}
while ( ( V_28 = V_25 -> V_567 ) != NULL ) {
V_70 = V_25 -> V_568 ;
V_70 = F_404 ( V_70 * V_28 -> V_77 . V_80 ,
F_232 ( V_25 ) + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_568 = V_70 ;
V_25 -> V_566 = V_86 ;
}
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_403 ( V_25 ) ;
return F_404 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_568 ,
F_232 ( V_25 ) + 1 ) ;
}
static inline void F_400 ( int V_161 )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_97 ;
F_401 ( & V_24 -> V_192 , V_97 ) ;
F_299 ( V_24 ) ;
F_219 ( F_222 ( V_25 ) , V_25 ) ;
F_402 ( & V_24 -> V_192 , V_97 ) ;
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_405 ( struct V_569 * V_570 )
{
* V_570 = (struct V_569 ) {
. V_571 = NULL ,
. V_220 = NULL ,
. V_572 = 0UL ,
. V_573 = 0UL ,
. V_574 = {
. V_490 = 0UL ,
. V_575 = 0 ,
. V_576 = V_577 ,
} ,
} ;
}
static inline int F_406 ( struct V_199 * V_200 ,
enum V_578 V_392 )
{
int V_486 ;
switch ( V_392 ) {
case V_557 :
V_486 = V_200 -> V_579 ;
break;
case V_564 :
V_486 = V_200 -> V_580 ;
break;
default:
V_486 = V_200 -> V_581 ;
break;
}
return V_486 ;
}
static unsigned long F_407 ( int V_161 )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
T_2 V_458 , V_582 , V_583 , V_77 ;
T_3 V_42 ;
V_583 = F_84 ( V_24 -> V_583 ) ;
V_77 = F_84 ( V_24 -> V_584 ) ;
V_42 = F_408 ( V_24 ) - V_583 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_458 = F_409 () + V_42 ;
V_582 = F_213 ( V_77 , V_458 ) ;
if ( F_11 ( V_582 < V_164 ) )
return V_164 - V_582 ;
return 1 ;
}
static void F_410 ( struct V_199 * V_200 , int V_161 )
{
unsigned long V_162 = F_211 ( V_200 , V_161 ) ;
struct V_480 * V_585 = V_200 -> V_483 ;
F_110 ( V_161 ) -> V_349 = V_162 ;
V_162 *= F_407 ( V_161 ) ;
V_162 >>= V_586 ;
if ( ! V_162 )
V_162 = 1 ;
F_110 ( V_161 ) -> V_460 = V_162 ;
V_585 -> V_492 -> V_162 = V_162 ;
}
void F_411 ( struct V_199 * V_200 , int V_161 )
{
struct V_199 * V_514 = V_200 -> V_514 ;
struct V_480 * V_132 , * V_585 = V_200 -> V_483 ;
unsigned long V_162 ;
unsigned long V_208 ;
V_208 = F_141 ( V_200 -> V_587 ) ;
V_208 = F_144 ( V_208 , 1UL , V_588 ) ;
V_585 -> V_492 -> V_589 = V_211 + V_208 ;
if ( ! V_514 ) {
F_410 ( V_200 , V_161 ) ;
return;
}
V_162 = 0 ;
if ( V_514 -> V_97 & V_590 ) {
F_109 (cpu, sched_group_cpus(sdg)) {
struct V_591 * V_492 ;
struct V_24 * V_24 = F_110 ( V_161 ) ;
if ( F_13 ( ! V_24 -> V_200 ) ) {
V_162 += F_112 ( V_161 ) ;
continue;
}
V_492 = V_24 -> V_200 -> V_483 -> V_492 ;
V_162 += V_492 -> V_162 ;
}
} else {
V_132 = V_514 -> V_483 ;
do {
V_162 += V_132 -> V_492 -> V_162 ;
V_132 = V_132 -> V_58 ;
} while ( V_132 != V_514 -> V_483 );
}
V_585 -> V_492 -> V_162 = V_162 ;
}
static inline int
F_412 ( struct V_24 * V_24 , struct V_199 * V_200 )
{
return ( ( V_24 -> V_460 * V_200 -> V_183 ) <
( V_24 -> V_349 * 100 ) ) ;
}
static inline int F_413 ( struct V_480 * V_132 )
{
return V_132 -> V_492 -> V_488 ;
}
static inline bool
F_414 ( struct V_533 * V_168 , struct V_592 * V_593 )
{
if ( V_593 -> V_575 < V_593 -> F_100 )
return true ;
if ( ( V_593 -> V_594 * 100 ) >
( V_593 -> V_595 * V_168 -> V_200 -> V_183 ) )
return true ;
return false ;
}
static inline bool
F_415 ( struct V_533 * V_168 , struct V_592 * V_593 )
{
if ( V_593 -> V_575 <= V_593 -> F_100 )
return false ;
if ( ( V_593 -> V_594 * 100 ) <
( V_593 -> V_595 * V_168 -> V_200 -> V_183 ) )
return true ;
return false ;
}
static inline enum
V_576 F_416 ( struct V_480 * V_132 ,
struct V_592 * V_593 )
{
if ( V_593 -> V_596 )
return V_597 ;
if ( F_413 ( V_132 ) )
return V_598 ;
return V_577 ;
}
static inline void F_417 ( struct V_533 * V_168 ,
struct V_480 * V_132 , int V_486 ,
int V_491 , struct V_592 * V_593 ,
bool * V_599 )
{
unsigned long V_70 ;
int V_258 , V_72 ;
memset ( V_593 , 0 , sizeof( * V_593 ) ) ;
F_356 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_110 ( V_258 ) ;
if ( V_491 )
V_70 = F_343 ( V_258 , V_486 ) ;
else
V_70 = F_342 ( V_258 , V_486 ) ;
V_593 -> V_600 += V_70 ;
V_593 -> V_595 += F_362 ( V_258 ) ;
V_593 -> V_575 += V_24 -> V_40 . V_403 ;
V_72 = V_24 -> V_72 ;
if ( V_72 > 1 )
* V_599 = true ;
#ifdef F_418
V_593 -> V_118 += V_24 -> V_118 ;
V_593 -> V_120 += V_24 -> V_120 ;
#endif
V_593 -> V_601 += F_111 ( V_258 ) ;
if ( ! V_72 && F_357 ( V_258 ) )
V_593 -> V_602 ++ ;
}
V_593 -> V_594 = V_132 -> V_492 -> V_162 ;
V_593 -> V_490 = ( V_593 -> V_600 * V_164 ) / V_593 -> V_594 ;
if ( V_593 -> V_575 )
V_593 -> V_603 = V_593 -> V_601 / V_593 -> V_575 ;
V_593 -> F_100 = V_132 -> F_100 ;
V_593 -> V_596 = F_415 ( V_168 , V_593 ) ;
V_593 -> V_576 = F_416 ( V_132 , V_593 ) ;
}
static bool F_419 ( struct V_533 * V_168 ,
struct V_569 * V_570 ,
struct V_480 * V_502 ,
struct V_592 * V_593 )
{
struct V_592 * V_571 = & V_570 -> V_574 ;
if ( V_593 -> V_576 > V_571 -> V_576 )
return true ;
if ( V_593 -> V_576 < V_571 -> V_576 )
return false ;
if ( V_593 -> V_490 <= V_571 -> V_490 )
return false ;
if ( ! ( V_168 -> V_200 -> V_97 & V_604 ) )
return true ;
if ( V_593 -> V_575 && V_168 -> V_152 < F_420 ( V_502 ) ) {
if ( ! V_570 -> V_571 )
return true ;
if ( F_420 ( V_570 -> V_571 ) > F_420 ( V_502 ) )
return true ;
}
return false ;
}
static inline enum V_605 F_421 ( struct V_592 * V_593 )
{
if ( V_593 -> V_575 > V_593 -> V_118 )
return V_606 ;
if ( V_593 -> V_575 > V_593 -> V_120 )
return V_218 ;
return V_607 ;
}
static inline enum V_605 F_422 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_118 )
return V_606 ;
if ( V_24 -> V_72 > V_24 -> V_120 )
return V_218 ;
return V_607 ;
}
static inline enum V_605 F_421 ( struct V_592 * V_593 )
{
return V_607 ;
}
static inline enum V_605 F_422 ( struct V_24 * V_24 )
{
return V_606 ;
}
static inline void F_423 ( struct V_533 * V_168 , struct V_569 * V_570 )
{
struct V_199 * V_514 = V_168 -> V_200 -> V_514 ;
struct V_480 * V_502 = V_168 -> V_200 -> V_483 ;
struct V_592 V_608 ;
int V_486 , V_609 = 0 ;
bool V_599 = false ;
if ( V_514 && V_514 -> V_97 & V_610 )
V_609 = 1 ;
V_486 = F_406 ( V_168 -> V_200 , V_168 -> V_392 ) ;
do {
struct V_592 * V_593 = & V_608 ;
int V_491 ;
V_491 = F_124 ( V_168 -> V_152 , F_354 ( V_502 ) ) ;
if ( V_491 ) {
V_570 -> V_220 = V_502 ;
V_593 = & V_570 -> V_611 ;
if ( V_168 -> V_392 != V_564 ||
F_424 ( V_211 , V_502 -> V_492 -> V_589 ) )
F_411 ( V_168 -> V_200 , V_168 -> V_152 ) ;
}
F_417 ( V_168 , V_502 , V_486 , V_491 , V_593 ,
& V_599 ) ;
if ( V_491 )
goto V_612;
if ( V_609 && V_570 -> V_220 &&
F_414 ( V_168 , & V_570 -> V_611 ) &&
( V_593 -> V_575 > 1 ) ) {
V_593 -> V_596 = 1 ;
V_593 -> V_576 = F_416 ( V_502 , V_593 ) ;
}
if ( F_419 ( V_168 , V_570 , V_502 , V_593 ) ) {
V_570 -> V_571 = V_502 ;
V_570 -> V_574 = * V_593 ;
}
V_612:
V_570 -> V_572 += V_593 -> V_600 ;
V_570 -> V_573 += V_593 -> V_594 ;
V_502 = V_502 -> V_58 ;
} while ( V_502 != V_168 -> V_200 -> V_483 );
if ( V_168 -> V_200 -> V_97 & V_538 )
V_168 -> V_605 = F_421 ( & V_570 -> V_574 ) ;
if ( ! V_168 -> V_200 -> V_34 ) {
if ( V_168 -> V_188 -> V_613 -> V_599 != V_599 )
V_168 -> V_188 -> V_613 -> V_599 = V_599 ;
}
}
static int F_425 ( struct V_533 * V_168 , struct V_569 * V_570 )
{
int V_614 ;
if ( ! ( V_168 -> V_200 -> V_97 & V_604 ) )
return 0 ;
if ( ! V_570 -> V_571 )
return 0 ;
V_614 = F_420 ( V_570 -> V_571 ) ;
if ( V_168 -> V_152 > V_614 )
return 0 ;
V_168 -> V_488 = F_113 (
V_570 -> V_574 . V_490 * V_570 -> V_574 . V_594 ,
V_164 ) ;
return 1 ;
}
static inline
void F_426 ( struct V_533 * V_168 , struct V_569 * V_570 )
{
unsigned long V_507 , V_615 = 0 , V_616 = 0 ;
unsigned int V_617 = 2 ;
unsigned long V_618 ;
struct V_592 * V_220 , * V_571 ;
V_220 = & V_570 -> V_611 ;
V_571 = & V_570 -> V_574 ;
if ( ! V_220 -> V_575 )
V_220 -> V_603 = F_345 ( V_168 -> V_152 ) ;
else if ( V_571 -> V_603 > V_220 -> V_603 )
V_617 = 1 ;
V_618 =
( V_571 -> V_603 * V_164 ) /
V_571 -> V_594 ;
if ( V_571 -> V_490 + V_618 >=
V_220 -> V_490 + ( V_618 * V_617 ) ) {
V_168 -> V_488 = V_571 -> V_603 ;
return;
}
V_615 += V_571 -> V_594 *
F_140 ( V_571 -> V_603 , V_571 -> V_490 ) ;
V_615 += V_220 -> V_594 *
F_140 ( V_220 -> V_603 , V_220 -> V_490 ) ;
V_615 /= V_164 ;
if ( V_571 -> V_490 > V_618 ) {
V_616 += V_571 -> V_594 *
F_140 ( V_571 -> V_603 ,
V_571 -> V_490 - V_618 ) ;
}
if ( V_571 -> V_490 * V_571 -> V_594 <
V_571 -> V_603 * V_164 ) {
V_507 = ( V_571 -> V_490 * V_571 -> V_594 ) /
V_220 -> V_594 ;
} else {
V_507 = ( V_571 -> V_603 * V_164 ) /
V_220 -> V_594 ;
}
V_616 += V_220 -> V_594 *
F_140 ( V_220 -> V_603 , V_220 -> V_490 + V_507 ) ;
V_616 /= V_164 ;
if ( V_616 > V_615 )
V_168 -> V_488 = V_571 -> V_603 ;
}
static inline void F_427 ( struct V_533 * V_168 , struct V_569 * V_570 )
{
unsigned long V_619 , V_620 = ~ 0UL ;
struct V_592 * V_220 , * V_571 ;
V_220 = & V_570 -> V_611 ;
V_571 = & V_570 -> V_574 ;
if ( V_571 -> V_576 == V_598 ) {
V_571 -> V_603 =
F_140 ( V_571 -> V_603 , V_570 -> V_490 ) ;
}
if ( V_571 -> V_490 <= V_570 -> V_490 ||
V_220 -> V_490 >= V_570 -> V_490 ) {
V_168 -> V_488 = 0 ;
return F_426 ( V_168 , V_570 ) ;
}
if ( V_571 -> V_576 == V_597 &&
V_220 -> V_576 == V_597 ) {
V_620 = V_571 -> V_575 *
V_84 ;
if ( V_620 > V_571 -> V_594 )
V_620 -= V_571 -> V_594 ;
else
V_620 = ~ 0UL ;
}
V_619 = F_140 ( V_571 -> V_490 - V_570 -> V_490 , V_620 ) ;
V_168 -> V_488 = F_140 (
V_619 * V_571 -> V_594 ,
( V_570 -> V_490 - V_220 -> V_490 ) * V_220 -> V_594
) / V_164 ;
if ( V_168 -> V_488 < V_571 -> V_603 )
return F_426 ( V_168 , V_570 ) ;
}
static struct V_480 * F_428 ( struct V_533 * V_168 )
{
struct V_592 * V_220 , * V_571 ;
struct V_569 V_570 ;
F_405 ( & V_570 ) ;
F_423 ( V_168 , & V_570 ) ;
V_220 = & V_570 . V_611 ;
V_571 = & V_570 . V_574 ;
if ( ( V_168 -> V_392 == V_621 || V_168 -> V_392 == V_564 ) &&
F_425 ( V_168 , & V_570 ) )
return V_570 . V_571 ;
if ( ! V_570 . V_571 || V_571 -> V_575 == 0 )
goto V_622;
V_570 . V_490 = ( V_164 * V_570 . V_572 )
/ V_570 . V_573 ;
if ( V_571 -> V_576 == V_598 )
goto V_623;
if ( V_168 -> V_392 == V_564 && F_414 ( V_168 , V_220 ) &&
V_571 -> V_596 )
goto V_623;
if ( V_220 -> V_490 >= V_571 -> V_490 )
goto V_622;
if ( V_220 -> V_490 >= V_570 . V_490 )
goto V_622;
if ( V_168 -> V_392 == V_621 ) {
if ( ( V_571 -> V_576 != V_597 ) &&
( V_220 -> V_602 <= ( V_571 -> V_602 + 1 ) ) )
goto V_622;
} else {
if ( 100 * V_571 -> V_490 <=
V_168 -> V_200 -> V_183 * V_220 -> V_490 )
goto V_622;
}
V_623:
F_427 ( V_168 , & V_570 ) ;
return V_570 . V_571 ;
V_622:
V_168 -> V_488 = 0 ;
return NULL ;
}
static struct V_24 * F_429 ( struct V_533 * V_168 ,
struct V_480 * V_132 )
{
struct V_24 * V_571 = NULL , * V_24 ;
unsigned long V_624 = 0 , V_625 = 1 ;
int V_258 ;
F_356 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_162 , V_464 ;
enum V_605 V_626 ;
V_24 = F_110 ( V_258 ) ;
V_626 = F_422 ( V_24 ) ;
if ( V_626 > V_168 -> V_605 )
continue;
V_162 = F_112 ( V_258 ) ;
V_464 = F_111 ( V_258 ) ;
if ( V_24 -> V_72 == 1 && V_464 > V_168 -> V_488 &&
! F_412 ( V_24 , V_168 -> V_200 ) )
continue;
if ( V_464 * V_625 > V_624 * V_162 ) {
V_624 = V_464 ;
V_625 = V_162 ;
V_571 = V_24 ;
}
}
return V_571 ;
}
static int F_430 ( struct V_533 * V_168 )
{
struct V_199 * V_200 = V_168 -> V_200 ;
if ( V_168 -> V_392 == V_564 ) {
if ( ( V_200 -> V_97 & V_604 ) && V_168 -> V_187 > V_168 -> V_152 )
return 1 ;
}
if ( ( V_168 -> V_392 != V_557 ) &&
( V_168 -> V_186 -> V_40 . V_403 == 1 ) ) {
if ( ( F_412 ( V_168 -> V_186 , V_200 ) ) &&
( F_112 ( V_168 -> V_187 ) * V_200 -> V_183 < F_112 ( V_168 -> V_152 ) * 100 ) )
return 1 ;
}
return F_13 ( V_200 -> V_547 > V_200 -> V_548 + 2 ) ;
}
static int F_431 ( struct V_533 * V_168 )
{
struct V_480 * V_502 = V_168 -> V_200 -> V_483 ;
struct V_627 * V_628 , * V_629 ;
int V_161 , V_630 = - 1 ;
if ( V_168 -> V_392 == V_564 )
return 1 ;
V_628 = F_354 ( V_502 ) ;
V_629 = F_432 ( V_502 ) ;
F_356 (cpu, sg_cpus, env->cpus) {
if ( ! F_124 ( V_161 , V_629 ) || ! F_357 ( V_161 ) )
continue;
V_630 = V_161 ;
break;
}
if ( V_630 == - 1 )
V_630 = F_433 ( V_502 ) ;
return V_630 == V_168 -> V_152 ;
}
static int F_434 ( int V_473 , struct V_24 * V_445 ,
struct V_199 * V_200 , enum V_578 V_392 ,
int * V_631 )
{
int V_632 , V_633 , V_634 = 0 ;
struct V_199 * V_635 = V_200 -> V_34 ;
struct V_480 * V_132 ;
struct V_24 * V_571 ;
unsigned long V_97 ;
struct V_627 * V_8 = F_435 ( V_636 ) ;
struct V_533 V_168 = {
. V_200 = V_200 ,
. V_152 = V_473 ,
. V_188 = V_445 ,
. V_542 = F_354 ( V_200 -> V_483 ) ,
. V_392 = V_392 ,
. V_560 = V_561 ,
. V_8 = V_8 ,
. V_605 = V_607 ,
. V_555 = F_436 ( V_168 . V_555 ) ,
} ;
if ( V_392 == V_564 )
V_168 . V_542 = NULL ;
F_437 ( V_8 , V_637 ) ;
F_244 ( V_200 , V_638 [ V_392 ] ) ;
V_639:
if ( ! F_431 ( & V_168 ) ) {
* V_631 = 0 ;
goto V_622;
}
V_132 = F_428 ( & V_168 ) ;
if ( ! V_132 ) {
F_244 ( V_200 , V_640 [ V_392 ] ) ;
goto V_622;
}
V_571 = F_429 ( & V_168 , V_132 ) ;
if ( ! V_571 ) {
F_244 ( V_200 , V_641 [ V_392 ] ) ;
goto V_622;
}
F_167 ( V_571 == V_168 . V_188 ) ;
F_66 ( V_200 , V_642 [ V_392 ] , V_168 . V_488 ) ;
V_168 . V_187 = V_571 -> V_161 ;
V_168 . V_186 = V_571 ;
V_632 = 0 ;
if ( V_571 -> V_72 > 1 ) {
V_168 . V_97 |= V_545 ;
V_168 . V_559 = F_140 ( V_643 , V_571 -> V_72 ) ;
V_644:
F_401 ( & V_571 -> V_192 , V_97 ) ;
V_633 = F_391 ( & V_168 ) ;
F_287 ( & V_571 -> V_192 ) ;
if ( V_633 ) {
F_399 ( & V_168 ) ;
V_632 += V_633 ;
}
F_438 ( V_97 ) ;
if ( V_168 . V_97 & V_562 ) {
V_168 . V_97 &= ~ V_562 ;
goto V_644;
}
if ( ( V_168 . V_97 & V_543 ) && V_168 . V_488 > 0 ) {
F_439 ( V_168 . V_152 , V_168 . V_8 ) ;
V_168 . V_188 = F_110 ( V_168 . V_544 ) ;
V_168 . V_152 = V_168 . V_544 ;
V_168 . V_97 &= ~ V_543 ;
V_168 . V_558 = 0 ;
V_168 . V_560 = V_561 ;
goto V_644;
}
if ( V_635 ) {
int * V_645 = & V_635 -> V_483 -> V_492 -> V_488 ;
if ( ( V_168 . V_97 & V_541 ) && V_168 . V_488 > 0 )
* V_645 = 1 ;
}
if ( F_13 ( V_168 . V_97 & V_545 ) ) {
F_439 ( F_26 ( V_571 ) , V_8 ) ;
if ( ! F_440 ( V_8 ) ) {
V_168 . V_558 = 0 ;
V_168 . V_560 = V_561 ;
goto V_639;
}
goto V_646;
}
}
if ( ! V_632 ) {
F_244 ( V_200 , V_647 [ V_392 ] ) ;
if ( V_392 != V_564 )
V_200 -> V_547 ++ ;
if ( F_430 ( & V_168 ) ) {
F_401 ( & V_571 -> V_192 , V_97 ) ;
if ( ! F_124 ( V_473 ,
F_125 ( V_571 -> V_45 ) ) ) {
F_402 ( & V_571 -> V_192 ,
V_97 ) ;
V_168 . V_97 |= V_545 ;
goto V_648;
}
if ( ! V_571 -> V_634 ) {
V_571 -> V_634 = 1 ;
V_571 -> V_649 = V_473 ;
V_634 = 1 ;
}
F_402 ( & V_571 -> V_192 , V_97 ) ;
if ( V_634 ) {
F_441 ( F_26 ( V_571 ) ,
V_650 , V_571 ,
& V_571 -> V_651 ) ;
}
V_200 -> V_547 = V_200 -> V_548 + 1 ;
}
} else
V_200 -> V_547 = 0 ;
if ( F_11 ( ! V_634 ) ) {
V_200 -> V_587 = V_200 -> V_652 ;
} else {
if ( V_200 -> V_587 < V_200 -> V_653 )
V_200 -> V_587 *= 2 ;
}
goto V_307;
V_622:
if ( V_635 ) {
int * V_645 = & V_635 -> V_483 -> V_492 -> V_488 ;
if ( * V_645 )
* V_645 = 0 ;
}
V_646:
F_244 ( V_200 , V_654 [ V_392 ] ) ;
V_200 -> V_547 = 0 ;
V_648:
if ( ( ( V_168 . V_97 & V_545 ) &&
V_200 -> V_587 < V_655 ) ||
( V_200 -> V_587 < V_200 -> V_653 ) )
V_200 -> V_587 *= 2 ;
V_632 = 0 ;
V_307:
return V_632 ;
}
static inline unsigned long
F_442 ( struct V_199 * V_200 , int V_656 )
{
unsigned long V_208 = V_200 -> V_587 ;
if ( V_656 )
V_208 *= V_200 -> V_657 ;
V_208 = F_141 ( V_208 ) ;
V_208 = F_144 ( V_208 , 1UL , V_588 ) ;
return V_208 ;
}
static inline void
F_443 ( struct V_199 * V_200 , int V_656 , unsigned long * V_658 )
{
unsigned long V_208 , V_58 ;
V_208 = F_442 ( V_200 , V_656 ) ;
V_58 = V_200 -> V_659 + V_208 ;
if ( F_178 ( * V_658 , V_58 ) )
* V_658 = V_58 ;
}
static int F_234 ( struct V_24 * V_445 )
{
unsigned long V_658 = V_211 + V_209 ;
int V_473 = V_445 -> V_161 ;
struct V_199 * V_200 ;
int V_660 = 0 ;
T_2 V_661 = 0 ;
V_445 -> V_500 = F_73 ( V_445 ) ;
if ( V_445 -> V_662 < V_535 ||
! V_445 -> V_613 -> V_599 ) {
F_119 () ;
V_200 = F_444 ( V_445 -> V_200 ) ;
if ( V_200 )
F_443 ( V_200 , 0 , & V_658 ) ;
F_128 () ;
goto V_307;
}
F_287 ( & V_445 -> V_192 ) ;
F_400 ( V_473 ) ;
F_119 () ;
F_364 (this_cpu, sd) {
int V_631 = 1 ;
T_2 V_663 , V_664 ;
if ( ! ( V_200 -> V_97 & V_512 ) )
continue;
if ( V_445 -> V_662 < V_661 + V_200 -> V_665 ) {
F_443 ( V_200 , 0 , & V_658 ) ;
break;
}
if ( V_200 -> V_97 & V_666 ) {
V_663 = F_281 ( V_473 ) ;
V_660 = F_434 ( V_473 , V_445 ,
V_200 , V_564 ,
& V_631 ) ;
V_664 = F_281 ( V_473 ) - V_663 ;
if ( V_664 > V_200 -> V_665 )
V_200 -> V_665 = V_664 ;
V_661 += V_664 ;
}
F_443 ( V_200 , 0 , & V_658 ) ;
if ( V_660 || V_445 -> V_72 > 0 )
break;
}
F_128 () ;
F_285 ( & V_445 -> V_192 ) ;
if ( V_661 > V_445 -> V_667 )
V_445 -> V_667 = V_661 ;
if ( V_445 -> V_40 . V_403 && ! V_660 )
V_660 = 1 ;
V_307:
if ( F_178 ( V_445 -> V_658 , V_658 ) )
V_445 -> V_658 = V_658 ;
if ( V_445 -> V_72 != V_445 -> V_40 . V_403 )
V_660 = - 1 ;
if ( V_660 )
V_445 -> V_500 = 0 ;
return V_660 ;
}
static int V_650 ( void * V_398 )
{
struct V_24 * V_668 = V_398 ;
int V_614 = F_26 ( V_668 ) ;
int V_669 = V_668 -> V_649 ;
struct V_24 * V_670 = F_110 ( V_669 ) ;
struct V_199 * V_200 ;
struct V_26 * V_29 = NULL ;
F_120 ( & V_668 -> V_192 ) ;
if ( F_13 ( V_614 != F_223 () ||
! V_668 -> V_634 ) )
goto V_671;
if ( V_668 -> V_72 <= 1 )
goto V_671;
F_167 ( V_668 == V_670 ) ;
F_119 () ;
F_364 (target_cpu, sd) {
if ( ( V_200 -> V_97 & V_512 ) &&
F_124 ( V_614 , F_365 ( V_200 ) ) )
break;
}
if ( F_11 ( V_200 ) ) {
struct V_533 V_168 = {
. V_200 = V_200 ,
. V_152 = V_669 ,
. V_188 = V_670 ,
. V_187 = V_668 -> V_161 ,
. V_186 = V_668 ,
. V_392 = V_621 ,
} ;
F_244 ( V_200 , V_672 ) ;
V_29 = F_389 ( & V_168 ) ;
if ( V_29 )
F_244 ( V_200 , V_673 ) ;
else
F_244 ( V_200 , V_674 ) ;
}
F_128 () ;
V_671:
V_668 -> V_634 = 0 ;
F_287 ( & V_668 -> V_192 ) ;
if ( V_29 )
F_398 ( V_670 , V_29 ) ;
F_445 () ;
return 0 ;
}
static inline int F_446 ( struct V_24 * V_24 )
{
return F_13 ( ! F_447 ( V_24 -> V_200 ) ) ;
}
static inline int F_448 ( void )
{
int V_675 = F_449 ( V_676 . V_677 ) ;
if ( V_675 < V_678 && F_357 ( V_675 ) )
return V_675 ;
return V_678 ;
}
static void F_450 ( void )
{
int V_679 ;
V_676 . V_658 ++ ;
V_679 = F_448 () ;
if ( V_679 >= V_678 )
return;
if ( F_451 ( V_680 , F_452 ( V_679 ) ) )
return;
F_453 ( V_679 ) ;
return;
}
static inline void F_454 ( int V_161 )
{
if ( F_13 ( F_455 ( V_681 , F_452 ( V_161 ) ) ) ) {
if ( F_11 ( F_124 ( V_161 , V_676 . V_677 ) ) ) {
F_439 ( V_161 , V_676 . V_677 ) ;
F_456 ( & V_676 . V_682 ) ;
}
F_457 ( V_681 , F_452 ( V_161 ) ) ;
}
}
static inline void F_458 ( void )
{
struct V_199 * V_200 ;
int V_161 = F_223 () ;
F_119 () ;
V_200 = F_133 ( F_134 ( V_683 , V_161 ) ) ;
if ( ! V_200 || ! V_200 -> V_684 )
goto V_194;
V_200 -> V_684 = 0 ;
F_459 ( & V_200 -> V_483 -> V_492 -> V_685 ) ;
V_194:
F_128 () ;
}
void F_460 ( void )
{
struct V_199 * V_200 ;
int V_161 = F_223 () ;
F_119 () ;
V_200 = F_133 ( F_134 ( V_683 , V_161 ) ) ;
if ( ! V_200 || V_200 -> V_684 )
goto V_194;
V_200 -> V_684 = 1 ;
F_456 ( & V_200 -> V_483 -> V_492 -> V_685 ) ;
V_194:
F_128 () ;
}
void F_461 ( int V_161 )
{
if ( ! F_462 ( V_161 ) )
return;
if ( F_455 ( V_681 , F_452 ( V_161 ) ) )
return;
if ( F_446 ( F_110 ( V_161 ) ) )
return;
F_463 ( V_161 , V_676 . V_677 ) ;
F_459 ( & V_676 . V_682 ) ;
F_464 ( V_681 , F_452 ( V_161 ) ) ;
}
static int F_465 ( struct V_686 * V_687 ,
unsigned long V_688 , void * V_689 )
{
switch ( V_688 & ~ V_690 ) {
case V_691 :
F_454 ( F_223 () ) ;
return V_692 ;
default:
return V_693 ;
}
}
void F_466 ( void )
{
V_588 = V_209 * F_467 () / 10 ;
}
static void F_468 ( struct V_24 * V_24 , enum V_578 V_392 )
{
int V_631 = 1 ;
int V_161 = V_24 -> V_161 ;
unsigned long V_208 ;
struct V_199 * V_200 ;
unsigned long V_658 = V_211 + 60 * V_209 ;
int F_443 = 0 ;
int V_694 , V_695 = 0 ;
T_2 V_696 = 0 ;
F_400 ( V_161 ) ;
F_119 () ;
F_364 (cpu, sd) {
if ( F_178 ( V_211 , V_200 -> V_697 ) ) {
V_200 -> V_665 =
( V_200 -> V_665 * 253 ) / 256 ;
V_200 -> V_697 = V_211 + V_209 ;
V_695 = 1 ;
}
V_696 += V_200 -> V_665 ;
if ( ! ( V_200 -> V_97 & V_512 ) )
continue;
if ( ! V_631 ) {
if ( V_695 )
continue;
break;
}
V_208 = F_442 ( V_200 , V_392 != V_621 ) ;
V_694 = V_200 -> V_97 & V_698 ;
if ( V_694 ) {
if ( ! F_469 ( & V_699 ) )
goto V_307;
}
if ( F_424 ( V_211 , V_200 -> V_659 + V_208 ) ) {
if ( F_434 ( V_161 , V_24 , V_200 , V_392 , & V_631 ) ) {
V_392 = F_357 ( V_161 ) ? V_621 : V_557 ;
}
V_200 -> V_659 = V_211 ;
V_208 = F_442 ( V_200 , V_392 != V_621 ) ;
}
if ( V_694 )
F_170 ( & V_699 ) ;
V_307:
if ( F_178 ( V_658 , V_200 -> V_659 + V_208 ) ) {
V_658 = V_200 -> V_659 + V_208 ;
F_443 = 1 ;
}
}
if ( V_695 ) {
V_24 -> V_667 =
F_65 ( ( T_2 ) V_535 , V_696 ) ;
}
F_128 () ;
if ( F_11 ( F_443 ) ) {
V_24 -> V_658 = V_658 ;
#ifdef F_470
if ( ( V_392 == V_621 ) && F_178 ( V_676 . V_658 , V_24 -> V_658 ) )
V_676 . V_658 = V_24 -> V_658 ;
#endif
}
}
static void F_471 ( struct V_24 * V_445 , enum V_578 V_392 )
{
int V_473 = V_445 -> V_161 ;
struct V_24 * V_24 ;
int V_630 ;
unsigned long V_658 = V_211 + 60 * V_209 ;
int F_443 = 0 ;
if ( V_392 != V_621 ||
! F_455 ( V_680 , F_452 ( V_473 ) ) )
goto V_287;
F_109 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_630 == V_473 || ! F_357 ( V_630 ) )
continue;
if ( F_472 () )
break;
V_24 = F_110 ( V_630 ) ;
if ( F_424 ( V_211 , V_24 -> V_658 ) ) {
F_120 ( & V_24 -> V_192 ) ;
F_299 ( V_24 ) ;
F_339 ( V_24 ) ;
F_123 ( & V_24 -> V_192 ) ;
F_468 ( V_24 , V_621 ) ;
}
if ( F_178 ( V_658 , V_24 -> V_658 ) ) {
V_658 = V_24 -> V_658 ;
F_443 = 1 ;
}
}
if ( F_11 ( F_443 ) )
V_676 . V_658 = V_658 ;
V_287:
F_457 ( V_680 , F_452 ( V_473 ) ) ;
}
static inline bool F_473 ( struct V_24 * V_24 )
{
unsigned long V_86 = V_211 ;
struct V_199 * V_200 ;
struct V_591 * V_492 ;
int V_700 , V_161 = V_24 -> V_161 ;
bool V_701 = false ;
if ( F_13 ( V_24 -> F_234 ) )
return false ;
F_458 () ;
F_454 ( V_161 ) ;
if ( F_11 ( ! F_474 ( & V_676 . V_682 ) ) )
return false ;
if ( F_182 ( V_86 , V_676 . V_658 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_119 () ;
V_200 = F_133 ( F_134 ( V_683 , V_161 ) ) ;
if ( V_200 ) {
V_492 = V_200 -> V_483 -> V_492 ;
V_700 = F_474 ( & V_492 -> V_685 ) ;
if ( V_700 > 1 ) {
V_701 = true ;
goto V_194;
}
}
V_200 = F_133 ( V_24 -> V_200 ) ;
if ( V_200 ) {
if ( ( V_24 -> V_40 . V_403 >= 1 ) &&
F_412 ( V_24 , V_200 ) ) {
V_701 = true ;
goto V_194;
}
}
V_200 = F_133 ( F_134 ( V_702 , V_161 ) ) ;
if ( V_200 && ( F_361 ( V_676 . V_677 ,
F_365 ( V_200 ) ) < V_161 ) ) {
V_701 = true ;
goto V_194;
}
V_194:
F_128 () ;
return V_701 ;
}
static void F_471 ( struct V_24 * V_445 , enum V_578 V_392 ) { }
static void F_475 ( struct V_703 * V_704 )
{
struct V_24 * V_445 = V_445 () ;
enum V_578 V_392 = V_445 -> F_234 ?
V_621 : V_557 ;
F_471 ( V_445 , V_392 ) ;
F_468 ( V_445 , V_392 ) ;
}
void F_476 ( struct V_24 * V_24 )
{
if ( F_13 ( F_446 ( V_24 ) ) )
return;
if ( F_424 ( V_211 , V_24 -> V_658 ) )
F_477 ( V_705 ) ;
#ifdef F_470
if ( F_473 ( V_24 ) )
F_450 () ;
#endif
}
static void F_478 ( struct V_24 * V_24 )
{
F_7 () ;
F_324 ( V_24 ) ;
}
static void F_479 ( struct V_24 * V_24 )
{
F_7 () ;
F_326 ( V_24 ) ;
}
static void F_480 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_374 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_269 ( V_25 , V_28 , V_374 ) ;
}
if ( F_481 ( & V_272 ) )
F_193 ( V_24 , V_45 ) ;
}
static void F_482 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_473 = F_223 () ;
struct V_24 * V_24 = V_445 () ;
unsigned long V_97 ;
F_401 ( & V_24 -> V_192 , V_97 ) ;
F_299 ( V_24 ) ;
V_25 = F_22 ( V_156 ) ;
V_45 = V_25 -> V_45 ;
F_119 () ;
F_483 ( V_29 , V_473 ) ;
F_128 () ;
F_62 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_245 ( V_25 , V_28 , 1 ) ;
if ( V_706 && V_45 && F_37 ( V_45 , V_28 ) ) {
F_117 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_263 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_36 ;
F_402 ( & V_24 -> V_192 , V_97 ) ;
}
static void
F_484 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_707 )
{
if ( ! F_485 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_708 > V_707 )
F_263 ( V_24 ) ;
} else
F_397 ( V_24 , V_29 , 0 ) ;
}
static inline bool F_486 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_74 )
return true ;
if ( ! V_28 -> V_90 || V_29 -> V_100 == V_709 )
return true ;
return false ;
}
static void F_487 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( ! F_486 ( V_29 ) ) {
F_245 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_36 ;
}
F_226 ( V_25 , V_28 ) ;
}
static void F_488 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
#ifdef F_374
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
F_225 ( V_25 , V_28 ) ;
if ( ! F_486 ( V_29 ) )
V_28 -> V_41 += V_25 -> F_36 ;
}
static void F_489 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_487 ( V_29 ) ;
}
static void F_490 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_488 ( V_29 ) ;
if ( F_485 ( V_29 ) ) {
if ( V_24 -> V_45 == V_29 )
F_263 ( V_24 ) ;
else
F_397 ( V_24 , V_29 , 0 ) ;
}
}
static void F_491 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_264 ( V_25 , V_28 ) ;
F_70 ( V_25 , 0 ) ;
}
}
void F_492 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_710 ;
V_25 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_25 -> V_48 = V_25 -> F_36 ;
#endif
#ifdef F_197
F_493 ( & V_25 -> V_344 , 0 ) ;
F_493 ( & V_25 -> V_346 , 0 ) ;
#endif
}
static void F_494 ( struct V_26 * V_29 )
{
F_487 ( V_29 ) ;
F_495 ( V_29 , F_132 ( V_29 ) ) ;
#ifdef F_197
V_29 -> V_28 . V_77 . V_78 = 0 ;
#endif
F_488 ( V_29 ) ;
}
void F_496 ( struct V_311 * V_33 )
{
int V_258 ;
F_322 ( F_283 ( V_33 ) ) ;
F_497 (i) {
if ( V_33 -> V_25 )
F_175 ( V_33 -> V_25 [ V_258 ] ) ;
if ( V_33 -> V_28 )
F_175 ( V_33 -> V_28 [ V_258 ] ) ;
}
F_175 ( V_33 -> V_25 ) ;
F_175 ( V_33 -> V_28 ) ;
}
int F_498 ( struct V_311 * V_33 , struct V_311 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_258 ;
V_33 -> V_25 = F_163 ( sizeof( V_25 ) * V_678 , V_260 ) ;
if ( ! V_33 -> V_25 )
goto V_711;
V_33 -> V_28 = F_163 ( sizeof( V_28 ) * V_678 , V_260 ) ;
if ( ! V_33 -> V_28 )
goto V_711;
V_33 -> V_314 = V_71 ;
F_315 ( F_283 ( V_33 ) ) ;
F_497 (i) {
V_25 = F_499 ( sizeof( struct V_25 ) ,
V_260 , F_102 ( V_258 ) ) ;
if ( ! V_25 )
goto V_711;
V_28 = F_499 ( sizeof( struct V_27 ) ,
V_260 , F_102 ( V_258 ) ) ;
if ( ! V_28 )
goto V_712;
F_492 ( V_25 ) ;
F_500 ( V_33 , V_25 , V_28 , V_258 , V_34 -> V_28 [ V_258 ] ) ;
F_61 ( V_28 ) ;
}
return 1 ;
V_712:
F_175 ( V_25 ) ;
V_711:
return 0 ;
}
void F_501 ( struct V_311 * V_33 )
{
unsigned long V_97 ;
struct V_24 * V_24 ;
int V_161 ;
F_497 (cpu) {
if ( V_33 -> V_28 [ V_161 ] )
F_230 ( V_33 -> V_28 [ V_161 ] ) ;
if ( ! V_33 -> V_25 [ V_161 ] -> V_32 )
continue;
V_24 = F_110 ( V_161 ) ;
F_401 ( & V_24 -> V_192 , V_97 ) ;
F_29 ( V_33 -> V_25 [ V_161 ] ) ;
F_402 ( & V_24 -> V_192 , V_97 ) ;
}
}
void F_500 ( struct V_311 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_161 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_110 ( V_161 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_319 ( V_25 ) ;
V_33 -> V_25 [ V_161 ] = V_25 ;
V_33 -> V_28 [ V_161 ] = V_28 ;
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
int F_502 ( struct V_311 * V_33 , unsigned long V_314 )
{
int V_258 ;
unsigned long V_97 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_204 ;
V_314 = F_144 ( V_314 , F_503 ( V_315 ) , F_503 ( V_713 ) ) ;
F_504 ( & V_714 ) ;
if ( V_33 -> V_314 == V_314 )
goto V_504;
V_33 -> V_314 = V_314 ;
F_497 (i) {
struct V_24 * V_24 = F_110 ( V_258 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_258 ] ;
F_401 ( & V_24 -> V_192 , V_97 ) ;
F_299 ( V_24 ) ;
F_59 (se)
F_205 ( F_24 ( V_28 ) ) ;
F_402 ( & V_24 -> V_192 , V_97 ) ;
}
V_504:
F_505 ( & V_714 ) ;
return 0 ;
}
void F_496 ( struct V_311 * V_33 ) { }
int F_498 ( struct V_311 * V_33 , struct V_311 * V_34 )
{
return 1 ;
}
void F_501 ( struct V_311 * V_33 ) { }
static unsigned int F_506 ( struct V_24 * V_24 , struct V_26 * V_138 )
{
struct V_27 * V_28 = & V_138 -> V_28 ;
unsigned int V_715 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_715 = F_507 ( F_58 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_715 ;
}
void F_508 ( struct V_716 * V_717 , int V_161 )
{
struct V_25 * V_25 ;
F_119 () ;
F_325 (cpu_rq(cpu), cfs_rq)
F_509 ( V_717 , V_161 , V_25 ) ;
F_128 () ;
}
void F_510 ( struct V_26 * V_29 , struct V_716 * V_717 )
{
int V_140 ;
unsigned long V_718 = 0 , V_719 = 0 , V_720 = 0 , V_721 = 0 ;
F_97 (node) {
if ( V_29 -> V_129 ) {
V_718 = V_29 -> V_129 [ F_91 ( V_130 , V_140 , 0 ) ] ;
V_719 = V_29 -> V_129 [ F_91 ( V_130 , V_140 , 1 ) ] ;
}
if ( V_29 -> V_121 ) {
V_720 = V_29 -> V_121 -> V_131 [ F_91 ( V_130 , V_140 , 0 ) ] ,
V_721 = V_29 -> V_121 -> V_131 [ F_91 ( V_130 , V_140 , 1 ) ] ;
}
F_511 ( V_717 , V_140 , V_718 , V_719 , V_720 , V_721 ) ;
}
}
T_12 void F_512 ( void )
{
#ifdef F_197
F_513 ( V_705 , F_475 ) ;
#ifdef F_470
V_676 . V_658 = V_211 ;
F_514 ( & V_676 . V_677 , V_722 ) ;
F_515 ( F_465 , 0 ) ;
#endif
#endif
}
