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
V_29 -> V_28 . V_77 . V_78 = V_75 ;
V_29 -> V_28 . V_77 . V_79 = V_75 ;
F_64 ( & V_29 -> V_28 ) ;
}
void F_63 ( struct V_26 * V_29 )
{
}
static void F_65 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_80 = F_66 ( F_17 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_14 ( ! V_45 ) )
return;
V_19 = V_80 - V_45 -> V_81 ;
if ( F_14 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_81 = V_80 ;
F_67 ( V_45 -> V_82 . V_83 ,
F_68 ( V_19 , V_45 -> V_82 . V_83 ) ) ;
V_45 -> V_84 += V_19 ;
F_69 ( V_25 , V_85 , V_19 ) ;
V_45 -> V_41 += F_58 ( V_19 , V_45 ) ;
F_40 ( V_25 ) ;
if ( F_21 ( V_45 ) ) {
struct V_26 * V_86 = F_18 ( V_45 ) ;
F_70 ( V_86 , V_19 , V_45 -> V_41 ) ;
F_71 ( V_86 , V_19 ) ;
F_72 ( V_86 , V_19 ) ;
}
F_73 ( V_25 , V_19 ) ;
}
static void F_74 ( struct V_24 * V_24 )
{
F_65 ( F_24 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_82 . V_87 , F_76 ( F_17 ( V_25 ) ) ) ;
}
static void F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_75 ( V_25 , V_28 ) ;
}
static void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_82 . V_88 , F_68 ( V_28 -> V_82 . V_88 ,
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_87 ) ) ;
F_67 ( V_28 -> V_82 . V_89 , V_28 -> V_82 . V_89 + 1 ) ;
F_67 ( V_28 -> V_82 . V_90 , V_28 -> V_82 . V_90 +
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_87 ) ;
#ifdef F_79
if ( F_21 ( V_28 ) ) {
F_80 ( F_18 ( V_28 ) ,
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_87 ) ;
}
#endif
F_67 ( V_28 -> V_82 . V_87 , 0 ) ;
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
V_28 -> V_81 = F_66 ( F_17 ( V_25 ) ) ;
}
static unsigned int F_83 ( struct V_26 * V_29 )
{
unsigned long V_91 = 0 ;
unsigned long V_92 ;
V_92 = V_93 << ( 20 - V_94 ) ;
V_91 = F_84 ( V_29 -> V_95 ) ;
if ( ! V_91 )
V_91 = V_92 ;
V_91 = F_85 ( V_91 , V_92 ) ;
return V_91 / V_92 ;
}
static unsigned int F_86 ( struct V_26 * V_29 )
{
unsigned int V_96 = F_87 ( V_93 ) ;
unsigned int V_97 , floor ;
unsigned int V_98 = 1 ;
if ( V_96 < V_99 )
V_98 = V_99 / V_96 ;
floor = 1000 / V_98 ;
V_97 = V_100 / F_83 ( V_29 ) ;
return F_88 (unsigned int, floor, scan) ;
}
static unsigned int F_89 ( struct V_26 * V_29 )
{
unsigned int V_101 = F_86 ( V_29 ) ;
unsigned int V_102 ;
V_102 = V_103 / F_83 ( V_29 ) ;
return F_68 ( V_101 , V_102 ) ;
}
static void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 += ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 += ( V_29 -> V_105 == F_91 ( V_29 ) ) ;
}
static void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 -= ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 -= ( V_29 -> V_105 == F_91 ( V_29 ) ) ;
}
T_7 F_93 ( struct V_26 * V_29 )
{
return V_29 -> V_107 ? V_29 -> V_107 -> V_108 : 0 ;
}
static inline int F_94 ( enum V_109 V_110 , int V_111 , int V_112 )
{
return V_113 * ( V_110 * V_114 + V_111 ) + V_112 ;
}
static inline unsigned long F_95 ( struct V_26 * V_29 , int V_111 )
{
if ( ! V_29 -> V_115 )
return 0 ;
return V_29 -> V_115 [ F_94 ( V_116 , V_111 , 0 ) ] +
V_29 -> V_115 [ F_94 ( V_116 , V_111 , 1 ) ] ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_111 )
{
if ( ! V_29 -> V_107 )
return 0 ;
return V_29 -> V_107 -> V_117 [ F_94 ( V_116 , V_111 , 0 ) ] +
V_29 -> V_107 -> V_117 [ F_94 ( V_116 , V_111 , 1 ) ] ;
}
static inline unsigned long F_97 ( struct V_107 * V_118 , int V_111 )
{
return V_118 -> V_119 [ F_94 ( V_116 , V_111 , 0 ) ] +
V_118 -> V_119 [ F_94 ( V_116 , V_111 , 1 ) ] ;
}
static unsigned long F_98 ( struct V_26 * V_29 , int V_111 ,
int V_120 , bool V_121 )
{
unsigned long V_122 = 0 ;
int V_123 ;
if ( V_124 == V_125 )
return 0 ;
F_99 (node) {
unsigned long V_117 ;
int V_126 = F_100 ( V_111 , V_123 ) ;
if ( V_126 == V_127 || V_123 == V_111 )
continue;
if ( V_124 == V_128 &&
V_126 > V_120 )
continue;
if ( V_121 )
V_117 = F_95 ( V_29 , V_123 ) ;
else
V_117 = F_96 ( V_29 , V_123 ) ;
if ( V_124 == V_129 ) {
V_117 *= ( V_127 - V_126 ) ;
V_117 /= ( V_127 - V_130 ) ;
}
V_122 += V_117 ;
}
return V_122 ;
}
static inline unsigned long F_101 ( struct V_26 * V_29 , int V_111 ,
int V_126 )
{
unsigned long V_117 , V_131 ;
if ( ! V_29 -> V_115 )
return 0 ;
V_131 = V_29 -> V_132 ;
if ( ! V_131 )
return 0 ;
V_117 = F_95 ( V_29 , V_111 ) ;
V_117 += F_98 ( V_29 , V_111 , V_126 , true ) ;
return 1000 * V_117 / V_131 ;
}
static inline unsigned long F_102 ( struct V_26 * V_29 , int V_111 ,
int V_126 )
{
unsigned long V_117 , V_131 ;
if ( ! V_29 -> V_107 )
return 0 ;
V_131 = V_29 -> V_107 -> V_131 ;
if ( ! V_131 )
return 0 ;
V_117 = F_96 ( V_29 , V_111 ) ;
V_117 += F_98 ( V_29 , V_111 , V_126 , false ) ;
return 1000 * V_117 / V_131 ;
}
bool F_103 ( struct V_26 * V_29 , struct V_133 * V_133 ,
int V_134 , int V_135 )
{
struct V_107 * V_136 = V_29 -> V_107 ;
int V_137 = F_104 ( V_135 ) ;
int V_138 , V_139 ;
V_139 = F_105 ( V_135 , V_140 -> V_141 ) ;
V_138 = F_106 ( V_133 , V_139 ) ;
if ( ! F_107 ( V_138 ) &&
F_108 ( V_138 ) != V_137 )
return false ;
if ( F_109 ( V_29 , V_138 ) )
return true ;
if ( ! V_136 )
return true ;
if ( ! F_110 ( V_137 , V_136 -> V_142 ) )
return false ;
if ( ! F_110 ( V_134 , V_136 -> V_142 ) )
return true ;
return F_96 ( V_29 , V_137 ) < ( F_96 ( V_29 , V_134 ) * 3 / 4 ) ;
}
static void F_111 ( struct V_143 * V_144 , int V_111 )
{
int V_145 , V_146 , V_8 = 0 ;
unsigned long V_147 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
F_112 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_113 ( V_146 ) ;
V_144 -> V_72 += V_24 -> V_72 ;
V_144 -> V_70 += F_114 ( V_146 ) ;
V_144 -> V_148 += F_115 ( V_146 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_145 = F_56 ( V_149 * V_8 , V_144 -> V_148 ) ;
V_147 = V_8 / V_145 ;
V_144 -> V_150 = F_5 ( unsigned , V_147 ,
F_116 ( V_144 -> V_148 , V_149 ) ) ;
V_144 -> V_151 = ( V_144 -> V_72 < V_144 -> V_150 ) ;
}
static void F_117 ( struct V_152 * V_153 ,
struct V_26 * V_29 , long V_154 )
{
if ( V_153 -> V_155 )
F_118 ( V_153 -> V_155 ) ;
if ( V_29 )
F_119 ( V_29 ) ;
V_153 -> V_155 = V_29 ;
V_153 -> V_156 = V_154 ;
V_153 -> V_157 = V_153 -> V_135 ;
}
static bool F_120 ( long V_158 , long V_159 ,
struct V_152 * V_153 )
{
long V_160 , V_161 ;
long V_162 , V_163 ;
long V_164 , V_165 ;
V_164 = V_153 -> V_166 . V_148 ;
V_165 = V_153 -> V_167 . V_148 ;
if ( V_159 < V_158 )
F_121 ( V_159 , V_158 ) ;
V_160 = V_159 * V_164 * 100 -
V_158 * V_165 * V_153 -> V_168 ;
if ( V_160 <= 0 )
return false ;
V_162 = V_153 -> V_166 . V_70 ;
V_163 = V_153 -> V_167 . V_70 ;
if ( V_163 < V_162 )
F_121 ( V_163 , V_162 ) ;
V_161 = V_163 * V_164 * 100 -
V_162 * V_165 * V_153 -> V_168 ;
return ( V_160 > V_161 ) ;
}
static void F_122 ( struct V_152 * V_153 ,
long V_169 , long V_170 )
{
struct V_24 * V_171 = F_113 ( V_153 -> V_172 ) ;
struct V_24 * V_173 = F_113 ( V_153 -> V_135 ) ;
struct V_26 * V_174 ;
long V_158 , V_159 ;
long V_70 ;
long V_154 = V_153 -> V_29 -> V_107 ? V_170 : V_169 ;
long V_175 = V_154 ;
int V_126 = V_153 -> V_126 ;
F_123 () ;
F_124 ( & V_173 -> V_176 ) ;
V_174 = V_173 -> V_45 ;
if ( ( V_174 -> V_177 & V_178 ) || F_125 ( V_174 ) )
V_174 = NULL ;
F_126 ( & V_173 -> V_176 ) ;
if ( V_174 == V_153 -> V_29 )
goto V_179;
if ( V_174 ) {
if ( ! F_127 ( V_153 -> V_172 , F_128 ( V_174 ) ) )
goto V_179;
if ( V_174 -> V_107 == V_153 -> V_29 -> V_107 ) {
V_154 = V_169 + F_101 ( V_174 , V_153 -> V_134 , V_126 ) -
F_101 ( V_174 , V_153 -> V_137 , V_126 ) ;
if ( V_174 -> V_107 )
V_154 -= V_154 / 16 ;
} else {
if ( V_174 -> V_107 )
V_154 += F_102 ( V_174 , V_153 -> V_134 , V_126 ) -
F_102 ( V_174 , V_153 -> V_137 , V_126 ) ;
else
V_154 += F_101 ( V_174 , V_153 -> V_134 , V_126 ) -
F_101 ( V_174 , V_153 -> V_137 , V_126 ) ;
}
}
if ( V_154 <= V_153 -> V_156 && V_175 <= V_153 -> V_156 )
goto V_179;
if ( ! V_174 ) {
if ( V_153 -> V_166 . V_72 <= V_153 -> V_166 . V_150 &&
! V_153 -> V_167 . V_151 )
goto V_179;
goto V_180;
}
if ( V_154 > V_153 -> V_156 && V_171 -> V_72 == 1 &&
V_173 -> V_72 == 1 )
goto V_181;
V_180:
V_70 = F_129 ( V_153 -> V_29 ) ;
V_159 = V_153 -> V_167 . V_70 + V_70 ;
V_158 = V_153 -> V_166 . V_70 - V_70 ;
if ( V_175 > V_154 && V_175 > V_153 -> V_156 ) {
if ( ! F_120 ( V_158 , V_159 , V_153 ) ) {
V_154 = V_175 - 1 ;
V_174 = NULL ;
goto V_181;
}
}
if ( V_154 <= V_153 -> V_156 )
goto V_179;
if ( V_174 ) {
V_70 = F_129 ( V_174 ) ;
V_159 -= V_70 ;
V_158 += V_70 ;
}
if ( F_120 ( V_158 , V_159 , V_153 ) )
goto V_179;
if ( ! V_174 )
V_153 -> V_135 = F_130 ( V_153 -> V_29 , V_153 -> V_135 ) ;
V_181:
F_117 ( V_153 , V_174 , V_154 ) ;
V_179:
F_131 () ;
}
static void F_132 ( struct V_152 * V_153 ,
long V_169 , long V_170 )
{
int V_146 ;
F_112 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_127 ( V_146 , F_128 ( V_153 -> V_29 ) ) )
continue;
V_153 -> V_135 = V_146 ;
F_122 ( V_153 , V_169 , V_170 ) ;
}
}
static int F_133 ( struct V_26 * V_29 )
{
struct V_152 V_153 = {
. V_29 = V_29 ,
. V_172 = F_134 ( V_29 ) ,
. V_134 = F_91 ( V_29 ) ,
. V_168 = 112 ,
. V_155 = NULL ,
. V_156 = 0 ,
. V_157 = - 1
} ;
struct V_182 * V_183 ;
unsigned long V_184 , V_185 ;
int V_111 , V_66 , V_126 ;
long V_169 , V_170 ;
F_123 () ;
V_183 = F_135 ( F_136 ( V_186 , V_153 . V_172 ) ) ;
if ( V_183 )
V_153 . V_168 = 100 + ( V_183 -> V_168 - 100 ) / 2 ;
F_131 () ;
if ( F_14 ( ! V_183 ) ) {
V_29 -> V_105 = F_91 ( V_29 ) ;
return - V_187 ;
}
V_153 . V_137 = V_29 -> V_105 ;
V_126 = V_153 . V_126 = F_100 ( V_153 . V_134 , V_153 . V_137 ) ;
V_184 = F_101 ( V_29 , V_153 . V_134 , V_126 ) ;
V_185 = F_102 ( V_29 , V_153 . V_134 , V_126 ) ;
F_111 ( & V_153 . V_166 , V_153 . V_134 ) ;
V_169 = F_101 ( V_29 , V_153 . V_137 , V_126 ) - V_184 ;
V_170 = F_102 ( V_29 , V_153 . V_137 , V_126 ) - V_185 ;
F_111 ( & V_153 . V_167 , V_153 . V_137 ) ;
F_132 ( & V_153 , V_169 , V_170 ) ;
if ( V_153 . V_157 == - 1 || ( V_29 -> V_107 &&
F_137 ( V_29 -> V_107 -> V_142 ) > 1 ) ) {
F_99 (nid) {
if ( V_111 == V_153 . V_134 || V_111 == V_29 -> V_105 )
continue;
V_126 = F_100 ( V_153 . V_134 , V_153 . V_137 ) ;
if ( V_124 == V_128 &&
V_126 != V_153 . V_126 ) {
V_184 = F_101 ( V_29 , V_153 . V_134 , V_126 ) ;
V_185 = F_102 ( V_29 , V_153 . V_134 , V_126 ) ;
}
V_169 = F_101 ( V_29 , V_111 , V_126 ) - V_184 ;
V_170 = F_102 ( V_29 , V_111 , V_126 ) - V_185 ;
if ( V_169 < 0 && V_170 < 0 )
continue;
V_153 . V_126 = V_126 ;
V_153 . V_137 = V_111 ;
F_111 ( & V_153 . V_167 , V_153 . V_137 ) ;
F_132 ( & V_153 , V_169 , V_170 ) ;
}
}
if ( V_29 -> V_107 ) {
if ( V_153 . V_157 == - 1 )
V_111 = V_153 . V_134 ;
else
V_111 = V_153 . V_137 ;
if ( F_110 ( V_111 , V_29 -> V_107 -> V_142 ) )
F_138 ( V_29 , V_153 . V_137 ) ;
}
if ( V_153 . V_157 == - 1 )
return - V_188 ;
V_29 -> V_189 = F_86 ( V_29 ) ;
if ( V_153 . V_155 == NULL ) {
V_66 = F_139 ( V_29 , V_153 . V_157 ) ;
if ( V_66 != 0 )
F_140 ( V_29 , V_153 . V_172 , V_153 . V_157 ) ;
return V_66 ;
}
V_66 = F_141 ( V_29 , V_153 . V_155 ) ;
if ( V_66 != 0 )
F_140 ( V_29 , V_153 . V_172 , F_134 ( V_153 . V_155 ) ) ;
F_118 ( V_153 . V_155 ) ;
return V_66 ;
}
static void F_142 ( struct V_26 * V_29 )
{
unsigned long V_190 = V_191 ;
if ( F_14 ( V_29 -> V_105 == - 1 || ! V_29 -> V_115 ) )
return;
V_190 = F_143 ( V_190 , F_144 ( V_29 -> V_189 ) / 16 ) ;
V_29 -> V_192 = V_193 + V_190 ;
if ( F_91 ( V_29 ) == V_29 -> V_105 )
return;
F_133 ( V_29 ) ;
}
static void F_145 ( struct V_107 * V_107 )
{
unsigned long V_117 , V_194 = 0 ;
int V_111 ;
F_99 (nid) {
V_117 = F_97 ( V_107 , V_111 ) ;
if ( V_117 > V_194 )
V_194 = V_117 ;
}
F_99 (nid) {
V_117 = F_97 ( V_107 , V_111 ) ;
if ( ! F_110 ( V_111 , V_107 -> V_142 ) ) {
if ( V_117 > V_194 * 6 / 16 )
F_146 ( V_111 , V_107 -> V_142 ) ;
} else if ( V_117 < V_194 * 3 / 16 )
F_147 ( V_111 , V_107 -> V_142 ) ;
}
}
static void F_148 ( struct V_26 * V_29 ,
unsigned long V_195 , unsigned long V_196 )
{
unsigned int V_197 ;
int V_198 ;
int V_199 ;
unsigned long V_200 = V_29 -> V_201 [ 0 ] ;
unsigned long V_202 = V_29 -> V_201 [ 1 ] ;
if ( V_202 + V_195 == 0 || V_29 -> V_201 [ 2 ] ) {
V_29 -> V_189 = F_143 ( V_29 -> V_203 ,
V_29 -> V_189 << 1 ) ;
V_29 -> V_95 -> V_204 = V_193 +
F_144 ( V_29 -> V_189 ) ;
return;
}
V_197 = F_56 ( V_29 -> V_189 , V_205 ) ;
V_198 = ( V_202 * V_205 ) / ( V_202 + V_200 ) ;
if ( V_198 >= V_206 ) {
int V_207 = V_198 - V_206 ;
if ( ! V_207 )
V_207 = 1 ;
V_199 = V_207 * V_197 ;
} else {
V_199 = - ( V_206 - V_198 ) * V_197 ;
V_198 = F_56 ( V_196 * V_205 , ( V_196 + V_195 + 1 ) ) ;
V_199 = ( V_199 * V_198 ) / V_205 ;
}
V_29 -> V_189 = F_149 ( V_29 -> V_189 + V_199 ,
F_86 ( V_29 ) , F_89 ( V_29 ) ) ;
memset ( V_29 -> V_201 , 0 , sizeof( V_29 -> V_201 ) ) ;
}
static T_2 F_150 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_208 , V_42 , V_80 ;
V_80 = V_29 -> V_28 . V_81 ;
V_208 = V_29 -> V_28 . V_84 ;
if ( V_29 -> V_209 ) {
V_42 = V_208 - V_29 -> V_210 ;
* V_73 = V_80 - V_29 -> V_209 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_78 ;
* V_73 = V_29 -> V_28 . V_77 . V_79 ;
}
V_29 -> V_210 = V_208 ;
V_29 -> V_209 = V_80 ;
return V_42 ;
}
static int F_151 ( struct V_26 * V_29 , int V_111 )
{
T_8 V_211 ;
int V_126 ;
if ( V_124 == V_125 )
return V_111 ;
if ( V_124 == V_129 ) {
unsigned long V_122 , V_212 = 0 ;
int V_123 , V_213 = V_111 ;
V_126 = V_127 ;
F_99 (node) {
V_122 = F_102 ( V_29 , V_123 , V_126 ) ;
if ( V_122 > V_212 ) {
V_212 = V_122 ;
V_213 = V_123 ;
}
}
return V_213 ;
}
V_211 = V_214 ;
for ( V_126 = V_127 ; V_126 > V_130 ; V_126 -- ) {
unsigned long V_194 = 0 ;
T_8 V_215 = V_216 ;
int V_43 , V_44 ;
if ( ! F_152 ( V_126 ) )
continue;
F_153 (a, nodes) {
unsigned long V_117 = 0 ;
T_8 V_217 ;
F_154 ( V_217 ) ;
F_153 (b, nodes) {
if ( F_100 ( V_43 , V_44 ) < V_126 ) {
V_117 += F_96 ( V_29 , V_44 ) ;
F_146 ( V_44 , V_217 ) ;
F_147 ( V_44 , V_211 ) ;
}
}
if ( V_117 > V_194 ) {
V_194 = V_117 ;
V_215 = V_217 ;
V_111 = V_43 ;
}
}
V_211 = V_215 ;
}
return V_111 ;
}
static void F_155 ( struct V_26 * V_29 )
{
int V_218 , V_111 , V_219 = - 1 , V_220 = - 1 ;
unsigned long V_194 = 0 , V_221 = 0 ;
unsigned long V_222 [ 2 ] = { 0 , 0 } ;
unsigned long V_131 ;
T_2 V_208 , V_73 ;
T_9 * V_223 = NULL ;
V_218 = F_87 ( V_29 -> V_95 -> V_224 ) ;
if ( V_29 -> V_224 == V_218 )
return;
V_29 -> V_224 = V_218 ;
V_29 -> V_203 = F_89 ( V_29 ) ;
V_131 = V_29 -> V_201 [ 0 ] +
V_29 -> V_201 [ 1 ] ;
V_208 = F_150 ( V_29 , & V_73 ) ;
if ( V_29 -> V_107 ) {
V_223 = & V_29 -> V_107 -> V_176 ;
F_156 ( V_223 ) ;
}
F_99 (nid) {
int V_225 , V_226 , V_227 , V_228 ;
unsigned long V_117 = 0 , F_96 = 0 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_113 ; V_112 ++ ) {
long V_199 , V_229 , V_230 ;
V_225 = F_94 ( V_116 , V_111 , V_112 ) ;
V_226 = F_94 ( V_231 , V_111 , V_112 ) ;
V_227 = F_94 ( V_232 , V_111 , V_112 ) ;
V_228 = F_94 ( V_233 , V_111 , V_112 ) ;
V_199 = V_29 -> V_115 [ V_226 ] - V_29 -> V_115 [ V_225 ] / 2 ;
V_222 [ V_112 ] += V_29 -> V_115 [ V_226 ] ;
V_29 -> V_115 [ V_226 ] = 0 ;
V_230 = F_157 ( V_208 << 16 , V_73 + 1 ) ;
V_230 = ( V_230 * V_29 -> V_115 [ V_228 ] ) /
( V_131 + 1 ) ;
V_229 = V_230 - V_29 -> V_115 [ V_227 ] / 2 ;
V_29 -> V_115 [ V_228 ] = 0 ;
V_29 -> V_115 [ V_225 ] += V_199 ;
V_29 -> V_115 [ V_227 ] += V_229 ;
V_117 += V_29 -> V_115 [ V_225 ] ;
V_29 -> V_132 += V_199 ;
if ( V_29 -> V_107 ) {
V_29 -> V_107 -> V_117 [ V_225 ] += V_199 ;
V_29 -> V_107 -> V_119 [ V_225 ] += V_229 ;
V_29 -> V_107 -> V_131 += V_199 ;
F_96 += V_29 -> V_107 -> V_117 [ V_225 ] ;
}
}
if ( V_117 > V_194 ) {
V_194 = V_117 ;
V_219 = V_111 ;
}
if ( F_96 > V_221 ) {
V_221 = F_96 ;
V_220 = V_111 ;
}
}
F_148 ( V_29 , V_222 [ 0 ] , V_222 [ 1 ] ) ;
if ( V_29 -> V_107 ) {
F_145 ( V_29 -> V_107 ) ;
F_158 ( V_223 ) ;
V_219 = F_151 ( V_29 , V_220 ) ;
}
if ( V_194 ) {
if ( V_219 != V_29 -> V_105 )
F_138 ( V_29 , V_219 ) ;
if ( F_91 ( V_29 ) != V_29 -> V_105 )
F_142 ( V_29 ) ;
}
}
static inline int F_159 ( struct V_107 * V_30 )
{
return F_160 ( & V_30 -> V_234 ) ;
}
static inline void F_161 ( struct V_107 * V_30 )
{
if ( F_162 ( & V_30 -> V_234 ) )
F_163 ( V_30 , V_235 ) ;
}
static void F_164 ( struct V_26 * V_29 , int V_236 , int V_177 ,
int * V_112 )
{
struct V_107 * V_30 , * V_237 ;
struct V_26 * V_238 ;
bool V_239 = false ;
int V_146 = F_165 ( V_236 ) ;
int V_240 ;
if ( F_14 ( ! V_29 -> V_107 ) ) {
unsigned int V_241 = sizeof( struct V_107 ) +
4 * V_114 *sizeof( unsigned long ) ;
V_30 = F_166 ( V_241 , V_242 | V_243 ) ;
if ( ! V_30 )
return;
F_167 ( & V_30 -> V_234 , 1 ) ;
F_168 ( & V_30 -> V_176 ) ;
V_30 -> V_108 = V_29 -> V_141 ;
V_30 -> V_119 = V_30 -> V_117 + V_113 *
V_114 ;
F_146 ( F_91 ( V_140 ) , V_30 -> V_142 ) ;
for ( V_240 = 0 ; V_240 < V_244 * V_114 ; V_240 ++ )
V_30 -> V_117 [ V_240 ] = V_29 -> V_115 [ V_240 ] ;
V_30 -> V_131 = V_29 -> V_132 ;
V_30 -> V_245 ++ ;
F_169 ( V_29 -> V_107 , V_30 ) ;
}
F_123 () ;
V_238 = F_87 ( F_113 ( V_146 ) -> V_45 ) ;
if ( ! F_109 ( V_238 , V_236 ) )
goto V_246;
V_30 = F_135 ( V_238 -> V_107 ) ;
if ( ! V_30 )
goto V_246;
V_237 = V_29 -> V_107 ;
if ( V_30 == V_237 )
goto V_246;
if ( V_237 -> V_245 > V_30 -> V_245 )
goto V_246;
if ( V_237 -> V_245 == V_30 -> V_245 && V_237 > V_30 )
goto V_246;
if ( V_238 -> V_95 == V_140 -> V_95 )
V_239 = true ;
if ( V_177 & V_247 )
V_239 = true ;
* V_112 = ! V_239 ;
if ( V_239 && ! F_159 ( V_30 ) )
goto V_246;
F_131 () ;
if ( ! V_239 )
return;
F_170 ( F_171 () ) ;
F_172 ( & V_237 -> V_176 , & V_30 -> V_176 ) ;
for ( V_240 = 0 ; V_240 < V_244 * V_114 ; V_240 ++ ) {
V_237 -> V_117 [ V_240 ] -= V_29 -> V_115 [ V_240 ] ;
V_30 -> V_117 [ V_240 ] += V_29 -> V_115 [ V_240 ] ;
}
V_237 -> V_131 -= V_29 -> V_132 ;
V_30 -> V_131 += V_29 -> V_132 ;
V_237 -> V_245 -- ;
V_30 -> V_245 ++ ;
F_173 ( & V_237 -> V_176 ) ;
F_158 ( & V_30 -> V_176 ) ;
F_169 ( V_29 -> V_107 , V_30 ) ;
F_161 ( V_237 ) ;
return;
V_246:
F_131 () ;
return;
}
void F_174 ( struct V_26 * V_29 )
{
struct V_107 * V_30 = V_29 -> V_107 ;
void * V_115 = V_29 -> V_115 ;
unsigned long V_177 ;
int V_240 ;
if ( V_30 ) {
F_175 ( & V_30 -> V_176 , V_177 ) ;
for ( V_240 = 0 ; V_240 < V_244 * V_114 ; V_240 ++ )
V_30 -> V_117 [ V_240 ] -= V_29 -> V_115 [ V_240 ] ;
V_30 -> V_131 -= V_29 -> V_132 ;
V_30 -> V_245 -- ;
F_176 ( & V_30 -> V_176 , V_177 ) ;
F_177 ( V_29 -> V_107 , NULL ) ;
F_161 ( V_30 ) ;
}
V_29 -> V_115 = NULL ;
F_178 ( V_115 ) ;
}
void F_179 ( int V_138 , int V_248 , int V_249 , int V_177 )
{
struct V_26 * V_29 = V_140 ;
bool V_250 = V_177 & V_251 ;
int V_252 = F_91 ( V_140 ) ;
int V_202 = ! ! ( V_177 & V_253 ) ;
int V_112 ;
if ( ! V_254 )
return;
if ( ! V_29 -> V_95 )
return;
if ( F_14 ( ! V_29 -> V_115 ) ) {
int V_241 = sizeof( * V_29 -> V_115 ) *
V_255 * V_114 ;
V_29 -> V_115 = F_166 ( V_241 , V_242 | V_243 ) ;
if ( ! V_29 -> V_115 )
return;
V_29 -> V_132 = 0 ;
memset ( V_29 -> V_201 , 0 , sizeof( V_29 -> V_201 ) ) ;
}
if ( F_14 ( V_138 == ( - 1 & V_256 ) ) ) {
V_112 = 1 ;
} else {
V_112 = F_109 ( V_29 , V_138 ) ;
if ( ! V_112 && ! ( V_177 & V_257 ) )
F_164 ( V_29 , V_138 , V_177 , & V_112 ) ;
}
if ( ! V_112 && ! V_202 && V_29 -> V_107 &&
F_110 ( V_252 , V_29 -> V_107 -> V_142 ) &&
F_110 ( V_248 , V_29 -> V_107 -> V_142 ) )
V_202 = 1 ;
F_155 ( V_29 ) ;
if ( F_180 ( V_193 , V_29 -> V_192 ) )
F_142 ( V_29 ) ;
if ( V_250 )
V_29 -> V_258 += V_249 ;
if ( V_177 & V_259 )
V_29 -> V_201 [ 2 ] += V_249 ;
V_29 -> V_115 [ F_94 ( V_231 , V_248 , V_112 ) ] += V_249 ;
V_29 -> V_115 [ F_94 ( V_233 , V_252 , V_112 ) ] += V_249 ;
V_29 -> V_201 [ V_202 ] += V_249 ;
}
static void F_181 ( struct V_26 * V_29 )
{
F_87 ( V_29 -> V_95 -> V_224 ) ++ ;
V_29 -> V_95 -> V_260 = 0 ;
}
void F_182 ( struct V_261 * V_262 )
{
unsigned long V_263 , V_264 , V_80 = V_193 ;
struct V_26 * V_29 = V_140 ;
struct V_265 * V_95 = V_29 -> V_95 ;
struct V_266 * V_267 ;
unsigned long V_268 , V_269 ;
unsigned long V_270 = 0 ;
long V_249 ;
F_20 ( V_29 != F_22 ( V_262 , struct V_26 , V_271 ) ) ;
V_262 -> V_58 = V_262 ;
if ( V_29 -> V_177 & V_178 )
return;
if ( ! V_95 -> V_204 ) {
V_95 -> V_204 = V_80 +
F_144 ( V_272 ) ;
}
V_263 = V_95 -> V_204 ;
if ( F_183 ( V_80 , V_263 ) )
return;
if ( V_29 -> V_189 == 0 ) {
V_29 -> V_203 = F_89 ( V_29 ) ;
V_29 -> V_189 = F_86 ( V_29 ) ;
}
V_264 = V_80 + F_144 ( V_29 -> V_189 ) ;
if ( F_184 ( & V_95 -> V_204 , V_263 , V_264 ) != V_263 )
return;
V_29 -> V_273 += 2 * V_274 ;
V_268 = V_95 -> V_260 ;
V_249 = V_93 ;
V_249 <<= 20 - V_94 ;
if ( ! V_249 )
return;
F_185 ( & V_95 -> V_275 ) ;
V_267 = F_186 ( V_95 , V_268 ) ;
if ( ! V_267 ) {
F_181 ( V_29 ) ;
V_268 = 0 ;
V_267 = V_95 -> V_276 ;
}
for (; V_267 ; V_267 = V_267 -> V_277 ) {
if ( ! F_187 ( V_267 ) || ! F_188 ( V_267 ) ||
F_189 ( V_267 ) ) {
continue;
}
if ( ! V_267 -> V_278 ||
( V_267 -> V_279 && ( V_267 -> V_280 & ( V_281 | V_282 ) ) == ( V_281 ) ) )
continue;
if ( ! ( V_267 -> V_280 & ( V_281 | V_283 | V_282 ) ) )
continue;
do {
V_268 = F_68 ( V_268 , V_267 -> V_284 ) ;
V_269 = F_190 ( V_268 + ( V_249 << V_94 ) , V_285 ) ;
V_269 = F_143 ( V_269 , V_267 -> V_286 ) ;
V_270 += F_191 ( V_267 , V_268 , V_269 ) ;
if ( V_270 )
V_249 -= ( V_269 - V_268 ) >> V_94 ;
V_268 = V_269 ;
if ( V_249 <= 0 )
goto V_287;
F_192 () ;
} while ( V_269 != V_267 -> V_286 );
}
V_287:
if ( V_267 )
V_95 -> V_260 = V_268 ;
else
F_181 ( V_29 ) ;
F_193 ( & V_95 -> V_275 ) ;
}
void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_261 * V_262 = & V_45 -> V_271 ;
T_2 V_73 , V_80 ;
if ( ! V_45 -> V_95 || ( V_45 -> V_177 & V_178 ) || V_262 -> V_58 != V_262 )
return;
V_80 = V_45 -> V_28 . V_84 ;
V_73 = ( T_2 ) V_45 -> V_189 * V_288 ;
if ( V_80 - V_45 -> V_273 > V_73 ) {
if ( ! V_45 -> V_273 )
V_45 -> V_189 = F_86 ( V_45 ) ;
V_45 -> V_273 += V_73 ;
if ( ! F_183 ( V_193 , V_45 -> V_95 -> V_204 ) ) {
F_195 ( V_262 , F_182 ) ;
F_196 ( V_45 , V_262 , true ) ;
}
}
}
static void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_197 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_198
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_90 ( V_24 , F_18 ( V_28 ) ) ;
F_199 ( & V_28 -> V_289 , & V_24 -> V_290 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_200 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_92 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_201 ( & V_28 -> V_289 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_202 ( struct V_291 * V_33 , struct V_25 * V_25 )
{
long V_292 ;
V_292 = F_203 ( & V_33 -> V_293 ) ;
V_292 -= V_25 -> V_294 ;
V_292 += V_25 -> V_70 . V_4 ;
return V_292 ;
}
static long F_204 ( struct V_25 * V_25 , struct V_291 * V_33 )
{
long V_292 , V_70 , V_295 ;
V_292 = F_202 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_295 = ( V_33 -> V_295 * V_70 ) ;
if ( V_292 )
V_295 /= V_292 ;
if ( V_295 < V_296 )
V_295 = V_296 ;
if ( V_295 > V_33 -> V_295 )
V_295 = V_33 -> V_295 ;
return V_295 ;
}
static inline long F_204 ( struct V_25 * V_25 , struct V_291 * V_33 )
{
return V_33 -> V_295 ;
}
static void F_205 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_200 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_197 ( V_25 , V_28 ) ;
}
static void F_206 ( struct V_25 * V_25 )
{
struct V_291 * V_33 ;
struct V_27 * V_28 ;
long V_295 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_207 ( V_25 ) )
return;
#ifndef F_198
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_295 ) )
return;
#endif
V_295 = F_204 ( V_25 , V_33 ) ;
F_205 ( F_24 ( V_28 ) , V_28 , V_295 ) ;
}
static inline void F_206 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_208 ( T_2 V_297 , T_2 V_298 )
{
unsigned int V_299 ;
if ( ! V_298 )
return V_297 ;
else if ( F_14 ( V_298 > V_300 * 63 ) )
return 0 ;
V_299 = V_298 ;
if ( F_14 ( V_299 >= V_300 ) ) {
V_297 >>= V_299 / V_300 ;
V_299 %= V_300 ;
}
V_297 *= V_301 [ V_299 ] ;
return V_297 >> 32 ;
}
static V_23 F_209 ( T_2 V_298 )
{
V_23 V_302 = 0 ;
if ( F_12 ( V_298 <= V_300 ) )
return V_303 [ V_298 ] ;
else if ( F_14 ( V_298 >= V_304 ) )
return V_305 ;
do {
V_302 /= 2 ;
V_302 += V_303 [ V_300 ] ;
V_298 -= V_300 ;
} while ( V_298 > V_300 );
V_302 = F_208 ( V_302 , V_298 ) ;
return V_302 + V_303 [ V_298 ] ;
}
static T_10 int F_210 ( T_2 V_80 ,
struct V_306 * V_307 ,
int V_308 )
{
T_2 V_42 , V_309 ;
V_23 V_310 ;
int V_311 , V_312 = 0 ;
V_42 = V_80 - V_307 -> V_313 ;
if ( ( T_3 ) V_42 < 0 ) {
V_307 -> V_313 = V_80 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_307 -> V_313 = V_80 ;
V_311 = V_307 -> V_79 % 1024 ;
if ( V_42 + V_311 >= 1024 ) {
V_312 = 1 ;
V_311 = 1024 - V_311 ;
if ( V_308 )
V_307 -> V_78 += V_311 ;
V_307 -> V_79 += V_311 ;
V_42 -= V_311 ;
V_309 = V_42 / 1024 ;
V_42 %= 1024 ;
V_307 -> V_78 = F_208 ( V_307 -> V_78 ,
V_309 + 1 ) ;
V_307 -> V_79 = F_208 ( V_307 -> V_79 ,
V_309 + 1 ) ;
V_310 = F_209 ( V_309 ) ;
if ( V_308 )
V_307 -> V_78 += V_310 ;
V_307 -> V_79 += V_310 ;
}
if ( V_308 )
V_307 -> V_78 += V_42 ;
V_307 -> V_79 += V_42 ;
return V_312 ;
}
static inline T_2 F_211 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_314 = F_212 ( & V_25 -> V_315 ) ;
V_314 -= V_28 -> V_77 . V_316 ;
V_28 -> V_77 . V_316 = 0 ;
if ( ! V_314 )
return 0 ;
V_28 -> V_77 . V_317 = F_208 ( V_28 -> V_77 . V_317 , V_314 ) ;
return V_314 ;
}
static inline void F_213 ( struct V_25 * V_25 ,
int V_318 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
long V_319 ;
V_319 = V_25 -> V_320 + V_25 -> V_321 ;
V_319 -= V_25 -> V_294 ;
if ( ! V_319 )
return;
if ( V_318 || abs ( V_319 ) > V_25 -> V_294 / 8 ) {
F_214 ( V_319 , & V_33 -> V_293 ) ;
V_25 -> V_294 += V_319 ;
}
}
static inline void F_215 ( struct V_306 * V_307 ,
struct V_25 * V_25 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
long V_302 ;
V_302 = F_216 ( ( T_2 ) V_307 -> V_78 << V_322 ,
V_307 -> V_79 + 1 ) ;
V_302 -= V_25 -> V_323 ;
if ( abs ( V_302 ) > V_25 -> V_323 / 64 ) {
F_217 ( V_302 , & V_33 -> V_324 ) ;
V_25 -> V_323 += V_302 ;
}
}
static inline void F_218 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_291 * V_33 = V_25 -> V_33 ;
int V_324 ;
T_2 V_302 ;
V_302 = V_25 -> V_294 * V_33 -> V_295 ;
V_28 -> V_77 . V_317 = F_216 ( V_302 ,
F_203 ( & V_33 -> V_293 ) + 1 ) ;
V_324 = F_219 ( & V_33 -> V_324 ) ;
if ( V_324 < V_71 ) {
V_28 -> V_77 . V_317 *= V_324 ;
V_28 -> V_77 . V_317 >>= V_322 ;
}
}
static inline void F_220 ( struct V_24 * V_24 , int V_308 )
{
F_210 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_308 ) ;
F_215 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_213 ( struct V_25 * V_25 ,
int V_318 ) {}
static inline void F_215 ( struct V_306 * V_307 ,
struct V_25 * V_25 ) {}
static inline void F_218 ( struct V_27 * V_28 ) {}
static inline void F_220 ( struct V_24 * V_24 , int V_308 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_302 ;
V_302 = V_28 -> V_77 . V_78 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_302 /= ( V_28 -> V_77 . V_79 + 1 ) ;
V_28 -> V_77 . V_317 = F_221 ( V_302 ) ;
}
static long F_222 ( struct V_27 * V_28 )
{
long V_325 = V_28 -> V_77 . V_317 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_215 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_218 ( V_28 ) ;
}
return V_28 -> V_77 . V_317 - V_325 ;
}
static inline void F_223 ( struct V_25 * V_25 ,
long V_326 )
{
if ( F_12 ( V_326 < V_25 -> V_321 ) )
V_25 -> V_321 -= V_326 ;
else
V_25 -> V_321 = 0 ;
}
static inline void F_224 ( struct V_27 * V_28 ,
int V_327 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_328 ;
T_2 V_80 ;
if ( F_21 ( V_28 ) )
V_80 = F_225 ( V_25 ) ;
else
V_80 = F_225 ( F_25 ( V_28 ) ) ;
if ( ! F_210 ( V_80 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_328 = F_222 ( V_28 ) ;
if ( ! V_327 )
return;
if ( V_28 -> V_76 )
V_25 -> V_320 += V_328 ;
else
F_223 ( V_25 , - V_328 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_318 )
{
T_2 V_80 = F_225 ( V_25 ) >> 20 ;
T_2 V_314 ;
V_314 = V_80 - V_25 -> V_329 ;
if ( ! V_314 && ! V_318 )
return;
if ( F_203 ( & V_25 -> V_330 ) ) {
unsigned long V_330 ;
V_330 = F_226 ( & V_25 -> V_330 , 0 ) ;
F_223 ( V_25 , V_330 ) ;
}
if ( V_314 ) {
V_25 -> V_321 = F_208 ( V_25 -> V_321 ,
V_314 ) ;
F_227 ( V_314 , & V_25 -> V_315 ) ;
V_25 -> V_329 = V_80 ;
}
F_213 ( V_25 , V_318 ) ;
}
static inline void F_228 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_331 )
{
if ( F_14 ( V_28 -> V_77 . V_316 <= 0 ) ) {
V_28 -> V_77 . V_313 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_316 ) {
V_28 -> V_77 . V_313 -= ( - V_28 -> V_77 . V_316 )
<< 20 ;
F_224 ( V_28 , 0 ) ;
V_28 -> V_77 . V_316 = 0 ;
}
V_331 = 0 ;
} else {
F_211 ( V_28 ) ;
}
if ( V_331 ) {
F_223 ( V_25 , V_28 -> V_77 . V_317 ) ;
F_224 ( V_28 , 0 ) ;
}
V_25 -> V_320 += V_28 -> V_77 . V_317 ;
F_30 ( V_25 , ! V_331 ) ;
}
static inline void F_229 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_332 )
{
F_224 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_332 ) ;
V_25 -> V_320 -= V_28 -> V_77 . V_317 ;
if ( V_332 ) {
V_25 -> V_321 += V_28 -> V_77 . V_317 ;
V_28 -> V_77 . V_316 = F_212 ( & V_25 -> V_315 ) ;
}
}
void F_230 ( struct V_24 * V_333 )
{
F_220 ( V_333 , 1 ) ;
}
void F_231 ( struct V_24 * V_333 )
{
F_220 ( V_333 , 0 ) ;
}
static inline void F_224 ( struct V_27 * V_28 ,
int V_327 ) {}
static inline void F_220 ( struct V_24 * V_24 , int V_308 ) {}
static inline void F_228 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_331 ) {}
static inline void F_229 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_332 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_318 ) {}
static inline int F_232 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_233 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_79
struct V_26 * V_238 = NULL ;
if ( F_21 ( V_28 ) )
V_238 = F_18 ( V_28 ) ;
if ( V_28 -> V_82 . V_334 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_334 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_82 . V_335 ) )
V_28 -> V_82 . V_335 = V_42 ;
V_28 -> V_82 . V_334 = 0 ;
V_28 -> V_82 . V_336 += V_42 ;
if ( V_238 ) {
F_234 ( V_238 , V_42 >> 10 , 1 ) ;
F_235 ( V_238 , V_42 ) ;
}
}
if ( V_28 -> V_82 . V_337 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_337 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_82 . V_338 ) )
V_28 -> V_82 . V_338 = V_42 ;
V_28 -> V_82 . V_337 = 0 ;
V_28 -> V_82 . V_336 += V_42 ;
if ( V_238 ) {
if ( V_238 -> V_339 ) {
V_28 -> V_82 . V_340 += V_42 ;
V_28 -> V_82 . V_341 ++ ;
F_236 ( V_238 , V_42 ) ;
}
F_237 ( V_238 , V_42 ) ;
if ( F_14 ( V_342 == V_343 ) ) {
F_238 ( V_343 ,
( void * ) F_239 ( V_238 ) ,
V_42 >> 20 ) ;
}
F_234 ( V_238 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_240 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_344 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_344 < 0 )
V_344 = - V_344 ;
if ( V_344 > 3 * V_68 )
F_241 ( V_25 , V_345 ) ;
#endif
}
static void
F_242 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_346 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_346 && F_243 ( V_347 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_346 ) {
unsigned long V_348 = V_68 ;
if ( F_243 ( V_349 ) )
V_348 >>= 1 ;
V_41 -= V_348 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_244 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_177 )
{
if ( ! ( V_177 & V_350 ) || ( V_177 & V_351 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_228 ( V_25 , V_28 , V_177 & V_350 ) ;
F_197 ( V_25 , V_28 ) ;
F_206 ( V_25 ) ;
if ( V_177 & V_350 ) {
F_242 ( V_25 , V_28 , 0 ) ;
F_233 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_240 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_245 ( V_25 ) ;
}
}
static void F_246 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_247 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_248 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_352 != V_28 )
break;
V_25 -> V_352 = NULL ;
}
}
static void F_249 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_246 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_247 ( V_28 ) ;
if ( V_25 -> V_352 == V_28 )
F_248 ( V_28 ) ;
}
static void
F_250 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_177 )
{
F_65 ( V_25 ) ;
F_229 ( V_25 , V_28 , V_177 & V_353 ) ;
F_81 ( V_25 , V_28 ) ;
if ( V_177 & V_353 ) {
#ifdef F_79
if ( F_21 ( V_28 ) ) {
struct V_26 * V_238 = F_18 ( V_28 ) ;
if ( V_238 -> V_354 & V_355 )
V_28 -> V_82 . V_334 = F_76 ( F_17 ( V_25 ) ) ;
if ( V_238 -> V_354 & V_356 )
V_28 -> V_82 . V_337 = F_76 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_249 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_200 ( V_25 , V_28 ) ;
if ( ! ( V_177 & V_353 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_251 ( V_25 ) ;
F_40 ( V_25 ) ;
F_206 ( V_25 ) ;
}
static void
F_252 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_357 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_357 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_84 - V_45 -> V_358 ;
if ( V_19 > V_357 ) {
F_253 ( F_17 ( V_25 ) ) ;
F_249 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_357 )
F_253 ( F_17 ( V_25 ) ) ;
}
static void
F_254 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_78 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
}
F_82 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_79
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_82 . V_359 = F_68 ( V_28 -> V_82 . V_359 ,
V_28 -> V_84 - V_28 -> V_358 ) ;
}
#endif
V_28 -> V_358 = V_28 -> V_84 ;
}
static struct V_27 *
F_255 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_352 == V_28 ) {
struct V_27 * V_360 ;
if ( V_28 == V_45 ) {
V_360 = F_50 ( V_25 ) ;
} else {
V_360 = F_51 ( V_28 ) ;
if ( ! V_360 || ( V_45 && F_39 ( V_45 , V_360 ) ) )
V_360 = V_45 ;
}
if ( V_360 && F_256 ( V_360 , V_57 ) < 1 )
V_28 = V_360 ;
}
if ( V_25 -> V_59 && F_256 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_256 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_249 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_257 ( struct V_25 * V_25 , struct V_27 * V_361 )
{
if ( V_361 -> V_76 )
F_65 ( V_25 ) ;
F_258 ( V_25 ) ;
F_240 ( V_25 , V_361 ) ;
if ( V_361 -> V_76 ) {
F_75 ( V_25 , V_361 ) ;
F_44 ( V_25 , V_361 ) ;
F_224 ( V_361 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_259 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_362 )
{
F_65 ( V_25 ) ;
F_224 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_206 ( V_25 ) ;
#ifdef F_260
if ( V_362 ) {
F_253 ( F_17 ( V_25 ) ) ;
return;
}
if ( ! F_243 ( V_363 ) &&
F_261 ( & F_17 ( V_25 ) -> V_364 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_252 ( V_25 , V_45 ) ;
}
static inline bool F_262 ( void )
{
return F_263 ( & V_365 ) ;
}
void F_264 ( void )
{
F_265 ( & V_365 ) ;
}
void F_266 ( void )
{
F_267 ( & V_365 ) ;
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
return ( T_2 ) V_366 * V_367 ;
}
void F_270 ( struct V_368 * V_369 )
{
T_2 V_80 ;
if ( V_369 -> V_370 == V_371 )
return;
V_80 = F_271 ( F_272 () ) ;
V_369 -> V_208 = V_369 -> V_370 ;
V_369 -> V_372 = V_80 + F_273 ( V_369 -> V_73 ) ;
}
static inline struct V_368 * F_274 ( struct V_291 * V_33 )
{
return & V_33 -> V_368 ;
}
static inline T_2 F_225 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_373 ) )
return V_25 -> V_374 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_375 ;
}
static int F_275 ( struct V_25 * V_25 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
struct V_368 * V_369 = F_274 ( V_33 ) ;
T_2 V_376 = 0 , V_377 , V_378 ;
V_377 = F_269 () - V_25 -> V_379 ;
F_276 ( & V_369 -> V_176 ) ;
if ( V_369 -> V_370 == V_371 )
V_376 = V_377 ;
else {
if ( ! V_369 -> V_380 ) {
F_270 ( V_369 ) ;
F_277 ( V_369 , false ) ;
}
if ( V_369 -> V_208 > 0 ) {
V_376 = F_143 ( V_369 -> V_208 , V_377 ) ;
V_369 -> V_208 -= V_376 ;
V_369 -> V_381 = 0 ;
}
}
V_378 = V_369 -> V_372 ;
F_278 ( & V_369 -> V_176 ) ;
V_25 -> V_379 += V_376 ;
if ( ( T_3 ) ( V_378 - V_25 -> V_372 ) > 0 )
V_25 -> V_372 = V_378 ;
return V_25 -> V_379 > 0 ;
}
static void F_279 ( struct V_25 * V_25 )
{
struct V_368 * V_369 = F_274 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_76 ( F_17 ( V_25 ) ) - V_25 -> V_372 ) < 0 ) )
return;
if ( V_25 -> V_379 < 0 )
return;
if ( V_25 -> V_372 != V_369 -> V_372 ) {
V_25 -> V_372 += V_274 ;
} else {
V_25 -> V_379 = 0 ;
}
}
static void F_280 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_379 -= V_19 ;
F_279 ( V_25 ) ;
if ( F_12 ( V_25 -> V_379 > 0 ) )
return;
if ( ! F_275 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_253 ( F_17 ( V_25 ) ) ;
}
static T_10
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_262 () || ! V_25 -> V_382 )
return;
F_280 ( V_25 , V_19 ) ;
}
static inline int F_281 ( struct V_25 * V_25 )
{
return F_262 () && V_25 -> V_383 ;
}
static inline int F_207 ( struct V_25 * V_25 )
{
return F_262 () && V_25 -> V_373 ;
}
static inline int F_282 ( struct V_291 * V_33 ,
int V_172 , int V_384 )
{
struct V_25 * V_385 , * V_386 ;
V_385 = V_33 -> V_25 [ V_172 ] ;
V_386 = V_33 -> V_25 [ V_384 ] ;
return F_207 ( V_385 ) ||
F_207 ( V_386 ) ;
}
static int F_283 ( struct V_291 * V_33 , void * V_387 )
{
struct V_24 * V_24 = V_387 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_373 -- ;
#ifdef F_198
if ( ! V_25 -> V_373 ) {
V_25 -> V_375 += F_66 ( V_24 ) -
V_25 -> V_374 ;
}
#endif
return 0 ;
}
static int F_284 ( struct V_291 * V_33 , void * V_387 )
{
struct V_24 * V_24 = V_387 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_373 )
V_25 -> V_374 = F_66 ( V_24 ) ;
V_25 -> V_373 ++ ;
return 0 ;
}
static void F_285 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_368 * V_369 = F_274 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_388 , V_389 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_123 () ;
F_286 ( V_25 -> V_33 , F_284 , V_390 , ( void * ) V_24 ) ;
F_131 () ;
V_388 = V_25 -> V_391 ;
F_61 (se) {
struct V_25 * V_392 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_389 )
F_250 ( V_392 , V_28 , V_353 ) ;
V_392 -> V_391 -= V_388 ;
if ( V_392 -> V_70 . V_4 )
V_389 = 0 ;
}
if ( ! V_28 )
F_287 ( V_24 , V_388 ) ;
V_25 -> V_383 = 1 ;
V_25 -> V_393 = F_76 ( V_24 ) ;
F_276 ( & V_369 -> V_176 ) ;
F_28 ( & V_25 -> V_394 , & V_369 -> V_395 ) ;
if ( ! V_369 -> V_380 )
F_277 ( V_369 , false ) ;
F_278 ( & V_369 -> V_176 ) ;
}
void F_288 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_368 * V_369 = F_274 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_396 = 1 ;
long V_388 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_383 = 0 ;
F_289 ( V_24 ) ;
F_276 ( & V_369 -> V_176 ) ;
V_369 -> V_397 += F_76 ( V_24 ) - V_25 -> V_393 ;
F_32 ( & V_25 -> V_394 ) ;
F_278 ( & V_369 -> V_176 ) ;
F_286 ( V_25 -> V_33 , V_390 , F_283 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_388 = V_25 -> V_391 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_396 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_396 )
F_244 ( V_25 , V_28 , V_350 ) ;
V_25 -> V_391 += V_388 ;
if ( F_281 ( V_25 ) )
break;
}
if ( ! V_28 )
F_290 ( V_24 , V_388 ) ;
if ( V_24 -> V_45 == V_24 -> V_381 && V_24 -> V_40 . V_72 )
F_253 ( V_24 ) ;
}
static T_2 F_291 ( struct V_368 * V_369 ,
T_2 V_398 , T_2 V_378 )
{
struct V_25 * V_25 ;
T_2 V_208 ;
T_2 V_399 = V_398 ;
F_123 () ;
F_292 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_276 ( & V_24 -> V_176 ) ;
if ( ! F_281 ( V_25 ) )
goto V_58;
V_208 = - V_25 -> V_379 + 1 ;
if ( V_208 > V_398 )
V_208 = V_398 ;
V_398 -= V_208 ;
V_25 -> V_379 += V_208 ;
V_25 -> V_372 = V_378 ;
if ( V_25 -> V_379 > 0 )
F_288 ( V_25 ) ;
V_58:
F_278 ( & V_24 -> V_176 ) ;
if ( ! V_398 )
break;
}
F_131 () ;
return V_399 - V_398 ;
}
static int F_293 ( struct V_368 * V_369 , int V_400 )
{
T_2 V_208 , V_372 ;
int V_383 ;
if ( V_369 -> V_370 == V_371 )
goto V_401;
V_383 = ! F_294 ( & V_369 -> V_395 ) ;
V_369 -> V_402 += V_400 ;
if ( V_369 -> V_381 && ! V_383 )
goto V_401;
V_369 -> V_380 = 1 ;
F_270 ( V_369 ) ;
if ( ! V_383 ) {
V_369 -> V_381 = 1 ;
return 0 ;
}
V_369 -> V_403 += V_400 ;
V_372 = V_369 -> V_372 ;
while ( V_383 && V_369 -> V_208 > 0 ) {
V_208 = V_369 -> V_208 ;
F_278 ( & V_369 -> V_176 ) ;
V_208 = F_291 ( V_369 , V_208 ,
V_372 ) ;
F_276 ( & V_369 -> V_176 ) ;
V_383 = ! F_294 ( & V_369 -> V_395 ) ;
V_369 -> V_208 -= F_143 ( V_208 , V_369 -> V_208 ) ;
}
V_369 -> V_381 = 0 ;
return 0 ;
V_401:
V_369 -> V_380 = 0 ;
return 1 ;
}
static int F_295 ( struct V_368 * V_369 , T_2 V_404 )
{
struct V_405 * V_406 = & V_369 -> V_407 ;
T_2 V_398 ;
if ( F_296 ( V_406 ) )
return 1 ;
V_398 = F_273 ( F_297 ( V_406 ) ) ;
if ( V_398 < V_404 )
return 1 ;
return 0 ;
}
static void F_298 ( struct V_368 * V_369 )
{
T_2 V_408 = V_409 + V_410 ;
if ( F_295 ( V_369 , V_408 ) )
return;
F_299 ( & V_369 -> V_411 ,
F_300 ( V_409 ) ) ;
}
static void F_301 ( struct V_25 * V_25 )
{
struct V_368 * V_369 = F_274 ( V_25 -> V_33 ) ;
T_3 V_412 = V_25 -> V_379 - V_413 ;
if ( V_412 <= 0 )
return;
F_276 ( & V_369 -> V_176 ) ;
if ( V_369 -> V_370 != V_371 &&
V_25 -> V_372 == V_369 -> V_372 ) {
V_369 -> V_208 += V_412 ;
if ( V_369 -> V_208 > F_269 () &&
! F_294 ( & V_369 -> V_395 ) )
F_298 ( V_369 ) ;
}
F_278 ( & V_369 -> V_176 ) ;
V_25 -> V_379 -= V_412 ;
}
static T_10 void F_251 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return;
if ( ! V_25 -> V_382 || V_25 -> V_72 )
return;
F_301 ( V_25 ) ;
}
static void F_302 ( struct V_368 * V_369 )
{
T_2 V_208 = 0 , V_75 = F_269 () ;
T_2 V_378 ;
F_276 ( & V_369 -> V_176 ) ;
if ( F_295 ( V_369 , V_410 ) ) {
F_278 ( & V_369 -> V_176 ) ;
return;
}
if ( V_369 -> V_370 != V_371 && V_369 -> V_208 > V_75 )
V_208 = V_369 -> V_208 ;
V_378 = V_369 -> V_372 ;
F_278 ( & V_369 -> V_176 ) ;
if ( ! V_208 )
return;
V_208 = F_291 ( V_369 , V_208 , V_378 ) ;
F_276 ( & V_369 -> V_176 ) ;
if ( V_378 == V_369 -> V_372 )
V_369 -> V_208 -= F_143 ( V_208 , V_369 -> V_208 ) ;
F_278 ( & V_369 -> V_176 ) ;
}
static void F_245 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return;
if ( ! V_25 -> V_382 || V_25 -> V_45 )
return;
if ( F_281 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_379 <= 0 )
F_285 ( V_25 ) ;
}
static bool F_258 ( struct V_25 * V_25 )
{
if ( ! F_262 () )
return false ;
if ( F_12 ( ! V_25 -> V_382 || V_25 -> V_379 > 0 ) )
return false ;
if ( F_281 ( V_25 ) )
return true ;
F_285 ( V_25 ) ;
return true ;
}
static enum V_414 F_303 ( struct V_405 * V_415 )
{
struct V_368 * V_369 =
F_22 ( V_415 , struct V_368 , V_411 ) ;
F_302 ( V_369 ) ;
return V_416 ;
}
static enum V_414 F_304 ( struct V_405 * V_415 )
{
struct V_368 * V_369 =
F_22 ( V_415 , struct V_368 , V_407 ) ;
T_11 V_80 ;
int V_400 ;
int V_381 = 0 ;
F_276 ( & V_369 -> V_176 ) ;
for (; ; ) {
V_80 = F_305 ( V_415 ) ;
V_400 = F_306 ( V_415 , V_80 , V_369 -> V_73 ) ;
if ( ! V_400 )
break;
V_381 = F_293 ( V_369 , V_400 ) ;
}
F_278 ( & V_369 -> V_176 ) ;
return V_381 ? V_416 : V_417 ;
}
void F_307 ( struct V_368 * V_369 )
{
F_308 ( & V_369 -> V_176 ) ;
V_369 -> V_208 = 0 ;
V_369 -> V_370 = V_371 ;
V_369 -> V_73 = F_300 ( F_268 () ) ;
F_309 ( & V_369 -> V_395 ) ;
F_310 ( & V_369 -> V_407 , V_418 , V_419 ) ;
V_369 -> V_407 . V_420 = F_304 ;
F_310 ( & V_369 -> V_411 , V_418 , V_419 ) ;
V_369 -> V_411 . V_420 = F_303 ;
}
static void F_311 ( struct V_25 * V_25 )
{
V_25 -> V_382 = 0 ;
F_309 ( & V_25 -> V_394 ) ;
}
void F_277 ( struct V_368 * V_369 , bool V_421 )
{
while ( F_14 ( F_261 ( & V_369 -> V_407 ) ) &&
F_312 ( & V_369 -> V_407 ) < 0 ) {
F_278 ( & V_369 -> V_176 ) ;
F_313 () ;
F_276 ( & V_369 -> V_176 ) ;
if ( ! V_421 && V_369 -> V_380 )
return;
}
V_369 -> V_380 = 1 ;
F_299 ( & V_369 -> V_407 , V_369 -> V_73 ) ;
}
static void F_314 ( struct V_368 * V_369 )
{
if ( ! V_369 -> V_395 . V_58 )
return;
F_315 ( & V_369 -> V_407 ) ;
F_315 ( & V_369 -> V_411 ) ;
}
static void T_12 F_316 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_317 (rq, cfs_rq) {
struct V_368 * V_369 = & V_25 -> V_33 -> V_368 ;
F_276 ( & V_369 -> V_176 ) ;
V_25 -> V_382 = V_369 -> V_370 != V_371 ;
F_278 ( & V_369 -> V_176 ) ;
}
}
static void T_12 F_318 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_317 (rq, cfs_rq) {
if ( ! V_25 -> V_382 )
continue;
V_25 -> V_379 = 1 ;
V_25 -> V_382 = 0 ;
if ( F_281 ( V_25 ) )
F_288 ( V_25 ) ;
}
}
static inline T_2 F_225 ( struct V_25 * V_25 )
{
return F_66 ( F_17 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
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
static inline int F_282 ( struct V_291 * V_33 ,
int V_172 , int V_384 )
{
return 0 ;
}
void F_307 ( struct V_368 * V_369 ) {}
static void F_311 ( struct V_25 * V_25 ) {}
static inline struct V_368 * F_274 ( struct V_291 * V_33 )
{
return NULL ;
}
static inline void F_314 ( struct V_368 * V_369 ) {}
static inline void F_316 ( struct V_24 * V_24 ) {}
static inline void F_318 ( struct V_24 * V_24 ) {}
static void F_319 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_320 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_422 = V_28 -> V_84 - V_28 -> V_358 ;
T_3 V_42 = V_75 - V_422 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_253 ( V_24 ) ;
return;
}
F_321 ( V_24 , V_42 ) ;
}
}
static void F_322 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_323 ( V_24 ) || V_45 -> V_423 != & V_424 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_319 ( V_24 , V_45 ) ;
}
static inline void
F_319 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_322 ( struct V_24 * V_24 )
{
}
static void
F_324 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_177 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_244 ( V_25 , V_28 , V_177 ) ;
if ( F_281 ( V_25 ) )
break;
V_25 -> V_391 ++ ;
V_177 = V_350 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_391 ++ ;
if ( F_281 ( V_25 ) )
break;
F_206 ( V_25 ) ;
F_224 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_220 ( V_24 , V_24 -> V_72 ) ;
F_290 ( V_24 , 1 ) ;
}
F_322 ( V_24 ) ;
}
static void F_325 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_177 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_425 = V_177 & V_353 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_250 ( V_25 , V_28 , V_177 ) ;
if ( F_281 ( V_25 ) )
break;
V_25 -> V_391 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_425 && F_34 ( V_28 ) )
F_326 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_177 |= V_353 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_391 -- ;
if ( F_281 ( V_25 ) )
break;
F_206 ( V_25 ) ;
F_224 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_287 ( V_24 , 1 ) ;
F_220 ( V_24 , 1 ) ;
}
F_322 ( V_24 ) ;
}
static unsigned long F_114 ( const int V_146 )
{
return F_113 ( V_146 ) -> V_40 . V_320 ;
}
static unsigned long F_327 ( int V_146 , int type )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
unsigned long V_426 = F_114 ( V_146 ) ;
if ( type == 0 || ! F_243 ( V_427 ) )
return V_426 ;
return F_143 ( V_24 -> V_428 [ type - 1 ] , V_426 ) ;
}
static unsigned long F_328 ( int V_146 , int type )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
unsigned long V_426 = F_114 ( V_146 ) ;
if ( type == 0 || ! F_243 ( V_427 ) )
return V_426 ;
return F_68 ( V_24 -> V_428 [ type - 1 ] , V_426 ) ;
}
static unsigned long F_115 ( int V_146 )
{
return F_113 ( V_146 ) -> V_429 ;
}
static unsigned long F_329 ( int V_146 )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
unsigned long V_72 = F_87 ( V_24 -> V_40 . V_391 ) ;
unsigned long V_293 = V_24 -> V_40 . V_320 ;
if ( V_72 )
return V_293 / V_72 ;
return 0 ;
}
static void F_330 ( struct V_26 * V_29 )
{
if ( F_180 ( V_193 , V_140 -> V_430 + V_191 ) ) {
V_140 -> V_431 >>= 1 ;
V_140 -> V_430 = V_193 ;
}
if ( V_140 -> V_432 != V_29 ) {
V_140 -> V_432 = V_29 ;
V_140 -> V_431 ++ ;
}
}
static void F_331 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_332 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_330 ( V_29 ) ;
}
static long F_333 ( struct V_291 * V_33 , int V_146 , long V_433 , long V_434 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_146 ] ;
if ( ! V_33 -> V_34 )
return V_433 ;
F_61 (se) {
long V_7 , V_435 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_435 = V_434 + F_202 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_433 ;
if ( V_435 > 0 && V_7 < V_435 )
V_433 = ( V_7 * ( long ) V_33 -> V_295 ) / V_435 ;
else
V_433 = V_33 -> V_295 ;
if ( V_433 < V_296 )
V_433 = V_296 ;
V_433 -= V_28 -> V_70 . V_4 ;
V_434 = 0 ;
}
return V_433 ;
}
static long F_333 ( struct V_291 * V_33 , int V_146 , long V_433 , long V_434 )
{
return V_433 ;
}
static int F_334 ( struct V_26 * V_29 )
{
int V_9 = F_335 ( V_436 ) ;
if ( V_29 -> V_431 > V_9 ) {
if ( V_140 -> V_431 > ( V_9 * V_29 -> V_431 ) )
return 1 ;
}
return 0 ;
}
static int F_336 ( struct V_182 * V_183 , struct V_26 * V_29 , int V_437 )
{
T_3 V_438 , V_70 ;
T_3 V_439 , V_440 ;
int V_441 , V_442 , V_443 ;
struct V_291 * V_33 ;
unsigned long V_4 ;
int V_444 ;
if ( F_334 ( V_29 ) )
return 0 ;
V_441 = V_183 -> V_445 ;
V_442 = F_272 () ;
V_443 = F_134 ( V_29 ) ;
V_70 = F_327 ( V_443 , V_441 ) ;
V_438 = F_328 ( V_442 , V_441 ) ;
if ( V_437 ) {
V_33 = V_291 ( V_140 ) ;
V_4 = V_140 -> V_28 . V_70 . V_4 ;
V_438 += F_333 ( V_33 , V_442 , - V_4 , - V_4 ) ;
V_70 += F_333 ( V_33 , V_443 , 0 , - V_4 ) ;
}
V_33 = V_291 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
V_439 = 100 ;
V_439 *= F_115 ( V_443 ) ;
V_440 = 100 + ( V_183 -> V_168 - 100 ) / 2 ;
V_440 *= F_115 ( V_442 ) ;
if ( V_438 > 0 ) {
V_439 *= V_438 +
F_333 ( V_33 , V_442 , V_4 , V_4 ) ;
V_440 *= V_70 + F_333 ( V_33 , V_443 , 0 , V_4 ) ;
}
V_444 = V_439 <= V_440 ;
F_241 ( V_29 , V_28 . V_82 . V_446 ) ;
if ( ! V_444 )
return 0 ;
F_241 ( V_183 , V_447 ) ;
F_241 ( V_29 , V_28 . V_82 . V_448 ) ;
return 1 ;
}
static struct V_449 *
F_337 ( struct V_182 * V_183 , struct V_26 * V_29 ,
int V_442 , int V_450 )
{
struct V_449 * V_451 = NULL , * V_118 = V_183 -> V_452 ;
unsigned long V_453 = V_454 , V_438 = 0 ;
int V_455 = V_183 -> V_456 ;
int V_457 = 100 + ( V_183 -> V_168 - 100 ) / 2 ;
if ( V_450 & V_458 )
V_455 = V_183 -> V_445 ;
do {
unsigned long V_70 , V_459 ;
int V_460 ;
int V_240 ;
if ( ! F_338 ( F_339 ( V_118 ) ,
F_128 ( V_29 ) ) )
continue;
V_460 = F_127 ( V_442 ,
F_339 ( V_118 ) ) ;
V_459 = 0 ;
F_112 (i, sched_group_cpus(group)) {
if ( V_460 )
V_70 = F_327 ( V_240 , V_455 ) ;
else
V_70 = F_328 ( V_240 , V_455 ) ;
V_459 += V_70 ;
}
V_459 = ( V_459 * V_149 ) / V_118 -> V_461 -> V_147 ;
if ( V_460 ) {
V_438 = V_459 ;
} else if ( V_459 < V_453 ) {
V_453 = V_459 ;
V_451 = V_118 ;
}
} while ( V_118 = V_118 -> V_58 , V_118 != V_183 -> V_452 );
if ( ! V_451 || 100 * V_438 < V_457 * V_453 )
return NULL ;
return V_451 ;
}
static int
F_340 ( struct V_449 * V_118 , struct V_26 * V_29 , int V_442 )
{
unsigned long V_70 , V_453 = V_454 ;
unsigned int V_462 = V_463 ;
T_2 V_464 = 0 ;
int V_465 = V_442 ;
int V_466 = - 1 ;
int V_240 ;
F_341 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_342 ( V_240 ) ) {
struct V_24 * V_24 = F_113 ( V_240 ) ;
struct V_467 * V_381 = F_343 ( V_24 ) ;
if ( V_381 && V_381 -> V_468 < V_462 ) {
V_462 = V_381 -> V_468 ;
V_464 = V_24 -> V_469 ;
V_466 = V_240 ;
} else if ( ( ! V_381 || V_381 -> V_468 == V_462 ) &&
V_24 -> V_469 > V_464 ) {
V_464 = V_24 -> V_469 ;
V_466 = V_240 ;
}
} else if ( V_466 == - 1 ) {
V_70 = F_114 ( V_240 ) ;
if ( V_70 < V_453 || ( V_70 == V_453 && V_240 == V_442 ) ) {
V_453 = V_70 ;
V_465 = V_240 ;
}
}
}
return V_466 != - 1 ? V_466 : V_465 ;
}
static int F_130 ( struct V_26 * V_29 , int V_470 )
{
struct V_182 * V_183 ;
struct V_449 * V_471 ;
int V_240 = F_134 ( V_29 ) ;
if ( F_342 ( V_470 ) )
return V_470 ;
if ( V_240 != V_470 && F_344 ( V_240 , V_470 ) && F_342 ( V_240 ) )
return V_240 ;
V_183 = F_135 ( F_136 ( V_472 , V_470 ) ) ;
F_345 (sd) {
V_471 = V_183 -> V_452 ;
do {
if ( ! F_338 ( F_339 ( V_471 ) ,
F_128 ( V_29 ) ) )
goto V_58;
F_112 (i, sched_group_cpus(sg)) {
if ( V_240 == V_470 || ! F_342 ( V_240 ) )
goto V_58;
}
V_470 = F_346 ( F_339 ( V_471 ) ,
F_128 ( V_29 ) ) ;
goto V_473;
V_58:
V_471 = V_471 -> V_58 ;
} while ( V_471 != V_183 -> V_452 );
}
V_473:
return V_470 ;
}
static int
F_347 ( struct V_26 * V_29 , int V_443 , int V_450 , int V_474 )
{
struct V_182 * V_475 , * V_476 = NULL , * V_183 = NULL ;
int V_146 = F_272 () ;
int V_477 = V_146 ;
int V_478 = 0 ;
int V_437 = V_474 & V_479 ;
if ( V_450 & V_458 )
V_478 = F_127 ( V_146 , F_128 ( V_29 ) ) ;
F_123 () ;
F_348 (cpu, tmp) {
if ( ! ( V_475 -> V_177 & V_480 ) )
continue;
if ( V_478 && ( V_475 -> V_177 & V_481 ) &&
F_127 ( V_443 , F_349 ( V_475 ) ) ) {
V_476 = V_475 ;
break;
}
if ( V_475 -> V_177 & V_450 )
V_183 = V_475 ;
}
if ( V_476 && V_146 != V_443 && F_336 ( V_476 , V_29 , V_437 ) )
V_443 = V_146 ;
if ( V_450 & V_458 ) {
V_477 = F_130 ( V_29 , V_443 ) ;
goto V_179;
}
while ( V_183 ) {
struct V_449 * V_118 ;
int V_4 ;
if ( ! ( V_183 -> V_177 & V_450 ) ) {
V_183 = V_183 -> V_482 ;
continue;
}
V_118 = F_337 ( V_183 , V_29 , V_146 , V_450 ) ;
if ( ! V_118 ) {
V_183 = V_183 -> V_482 ;
continue;
}
V_477 = F_340 ( V_118 , V_29 , V_146 ) ;
if ( V_477 == - 1 || V_477 == V_146 ) {
V_183 = V_183 -> V_482 ;
continue;
}
V_146 = V_477 ;
V_4 = V_183 -> V_483 ;
V_183 = NULL ;
F_348 (cpu, tmp) {
if ( V_4 <= V_475 -> V_483 )
break;
if ( V_475 -> V_177 & V_450 )
V_183 = V_475 ;
}
}
V_179:
F_131 () ;
return V_477 ;
}
static void
F_350 ( struct V_26 * V_29 , int V_484 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_316 ) {
V_28 -> V_77 . V_316 = - F_211 ( V_28 ) ;
F_214 ( V_28 -> V_77 . V_317 ,
& V_25 -> V_330 ) ;
}
V_28 -> V_81 = 0 ;
}
static unsigned long
F_351 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_485 = V_486 ;
return F_58 ( V_485 , V_28 ) ;
}
static int
F_256 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_485 , V_487 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_487 <= 0 )
return - 1 ;
V_485 = F_351 ( V_45 , V_28 ) ;
if ( V_487 > V_485 )
return 1 ;
return 0 ;
}
static void F_352 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_488 == V_489 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_326 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_488 == V_489 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_353 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_352 = V_28 ;
}
static void F_354 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_474 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_490 = V_25 -> V_72 >= V_67 ;
int V_491 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_207 ( F_24 ( V_36 ) ) ) )
return;
if ( F_243 ( V_492 ) && V_490 && ! ( V_474 & V_493 ) ) {
F_326 ( V_36 ) ;
V_491 = 1 ;
}
if ( F_355 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_488 == V_489 ) &&
F_12 ( V_29 -> V_488 != V_489 ) )
goto V_494;
if ( F_14 ( V_29 -> V_488 != V_495 ) || ! F_243 ( V_496 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_170 ( ! V_36 ) ;
if ( F_256 ( V_28 , V_36 ) == 1 ) {
if ( ! V_491 )
F_326 ( V_36 ) ;
goto V_494;
}
return;
V_494:
F_253 ( V_24 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_381 ) )
return;
if ( F_243 ( V_497 ) && V_490 && F_21 ( V_28 ) )
F_352 ( V_28 ) ;
}
static struct V_26 *
F_356 ( struct V_24 * V_24 , struct V_26 * V_361 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_498 ;
V_499:
#ifdef F_357
if ( ! V_25 -> V_72 )
goto V_381;
if ( V_361 -> V_423 != & V_424 )
goto V_500;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_258 ( V_25 ) ) )
goto V_500;
V_28 = F_255 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_361 != V_29 ) {
struct V_27 * V_36 = & V_361 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_257 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_254 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_257 ( V_25 , V_36 ) ;
F_254 ( V_25 , V_28 ) ;
}
if ( F_323 ( V_24 ) )
F_319 ( V_24 , V_29 ) ;
return V_29 ;
V_500:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_381;
F_358 ( V_24 , V_361 ) ;
do {
V_28 = F_255 ( V_25 , NULL ) ;
F_254 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_323 ( V_24 ) )
F_319 ( V_24 , V_29 ) ;
return V_29 ;
V_381:
V_498 = F_232 ( V_24 ) ;
if ( V_498 < 0 )
return V_501 ;
if ( V_498 > 0 )
goto V_499;
return NULL ;
}
static void F_359 ( struct V_24 * V_24 , struct V_26 * V_361 )
{
struct V_27 * V_28 = & V_361 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_257 ( V_25 , V_28 ) ;
}
}
static void F_360 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_249 ( V_25 , V_28 ) ;
if ( V_45 -> V_488 != V_502 ) {
F_289 ( V_24 ) ;
F_65 ( V_25 ) ;
F_361 ( V_24 , true ) ;
}
F_353 ( V_28 ) ;
}
static bool F_362 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_494 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_207 ( F_24 ( V_28 ) ) )
return false ;
F_326 ( V_28 ) ;
F_360 ( V_24 ) ;
return true ;
}
static int F_363 ( struct V_26 * V_29 , struct V_503 * V_153 )
{
T_3 V_42 ;
F_364 ( & V_153 -> V_171 -> V_176 ) ;
if ( V_29 -> V_423 != & V_424 )
return 0 ;
if ( F_14 ( V_29 -> V_488 == V_489 ) )
return 0 ;
if ( F_243 ( V_504 ) && V_153 -> V_173 -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_505 == - 1 )
return 1 ;
if ( V_505 == 0 )
return 0 ;
V_42 = F_66 ( V_153 -> V_171 ) - V_29 -> V_28 . V_81 ;
return V_42 < ( T_3 ) V_505 ;
}
static bool F_365 ( struct V_26 * V_29 , struct V_503 * V_153 )
{
struct V_107 * V_107 = F_135 ( V_29 -> V_107 ) ;
int V_134 , V_137 ;
if ( ! F_243 ( V_506 ) || ! V_29 -> V_115 ||
! ( V_153 -> V_183 -> V_177 & V_507 ) ) {
return false ;
}
V_134 = F_104 ( V_153 -> V_172 ) ;
V_137 = F_104 ( V_153 -> V_135 ) ;
if ( V_134 == V_137 )
return false ;
if ( V_107 ) {
if ( F_110 ( V_134 , V_107 -> V_142 ) )
return false ;
if ( F_110 ( V_137 , V_107 -> V_142 ) )
return true ;
return F_96 ( V_29 , V_137 ) > F_96 ( V_29 , V_134 ) ;
}
if ( V_137 == V_29 -> V_105 )
return true ;
return F_95 ( V_29 , V_137 ) > F_95 ( V_29 , V_134 ) ;
}
static bool F_366 ( struct V_26 * V_29 , struct V_503 * V_153 )
{
struct V_107 * V_107 = F_135 ( V_29 -> V_107 ) ;
int V_134 , V_137 ;
if ( ! F_243 ( V_508 ) || ! F_243 ( V_509 ) )
return false ;
if ( ! V_29 -> V_115 || ! ( V_153 -> V_183 -> V_177 & V_507 ) )
return false ;
V_134 = F_104 ( V_153 -> V_172 ) ;
V_137 = F_104 ( V_153 -> V_135 ) ;
if ( V_134 == V_137 )
return false ;
if ( V_107 ) {
if ( F_110 ( V_137 , V_107 -> V_142 ) )
return false ;
if ( F_110 ( V_134 , V_107 -> V_142 ) )
return true ;
return F_96 ( V_29 , V_137 ) < F_96 ( V_29 , V_134 ) ;
}
if ( V_134 == V_29 -> V_105 )
return true ;
return F_95 ( V_29 , V_137 ) < F_95 ( V_29 , V_134 ) ;
}
static inline bool F_365 ( struct V_26 * V_29 ,
struct V_503 * V_153 )
{
return false ;
}
static inline bool F_366 ( struct V_26 * V_29 ,
struct V_503 * V_153 )
{
return false ;
}
static
int F_367 ( struct V_26 * V_29 , struct V_503 * V_153 )
{
int V_510 = 0 ;
F_364 ( & V_153 -> V_171 -> V_176 ) ;
if ( F_282 ( V_291 ( V_29 ) , V_153 -> V_172 , V_153 -> V_135 ) )
return 0 ;
if ( ! F_127 ( V_153 -> V_135 , F_128 ( V_29 ) ) ) {
int V_146 ;
F_241 ( V_29 , V_28 . V_82 . V_511 ) ;
V_153 -> V_177 |= V_512 ;
if ( ! V_153 -> V_513 || ( V_153 -> V_177 & V_514 ) )
return 0 ;
F_341 (cpu, env->dst_grpmask, env->cpus) {
if ( F_127 ( V_146 , F_128 ( V_29 ) ) ) {
V_153 -> V_177 |= V_514 ;
V_153 -> V_515 = V_146 ;
break;
}
}
return 0 ;
}
V_153 -> V_177 &= ~ V_516 ;
if ( F_368 ( V_153 -> V_171 , V_29 ) ) {
F_241 ( V_29 , V_28 . V_82 . V_517 ) ;
return 0 ;
}
V_510 = F_363 ( V_29 , V_153 ) ;
if ( ! V_510 )
V_510 = F_366 ( V_29 , V_153 ) ;
if ( F_365 ( V_29 , V_153 ) || ! V_510 ||
V_153 -> V_183 -> V_518 > V_153 -> V_183 -> V_519 ) {
if ( V_510 ) {
F_241 ( V_153 -> V_183 , V_520 [ V_153 -> V_381 ] ) ;
F_241 ( V_29 , V_28 . V_82 . V_521 ) ;
}
return 1 ;
}
F_241 ( V_29 , V_28 . V_82 . V_522 ) ;
return 0 ;
}
static void F_369 ( struct V_26 * V_29 , struct V_503 * V_153 )
{
F_364 ( & V_153 -> V_171 -> V_176 ) ;
F_370 ( V_153 -> V_171 , V_29 , 0 ) ;
V_29 -> V_76 = V_523 ;
F_371 ( V_29 , V_153 -> V_135 ) ;
}
static struct V_26 * F_372 ( struct V_503 * V_153 )
{
struct V_26 * V_29 , * V_298 ;
F_364 ( & V_153 -> V_171 -> V_176 ) ;
F_373 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_367 ( V_29 , V_153 ) )
continue;
F_369 ( V_29 , V_153 ) ;
F_241 ( V_153 -> V_183 , V_524 [ V_153 -> V_381 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_374 ( struct V_503 * V_153 )
{
struct V_525 * V_526 = & V_153 -> V_171 -> V_290 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_527 = 0 ;
F_364 ( & V_153 -> V_171 -> V_176 ) ;
if ( V_153 -> V_457 <= 0 )
return 0 ;
while ( ! F_294 ( V_526 ) ) {
V_29 = F_375 ( V_526 , struct V_26 , V_28 . V_289 ) ;
V_153 -> V_528 ++ ;
if ( V_153 -> V_528 > V_153 -> V_529 )
break;
if ( V_153 -> V_528 > V_153 -> V_530 ) {
V_153 -> V_530 += V_531 ;
V_153 -> V_177 |= V_532 ;
break;
}
if ( ! F_367 ( V_29 , V_153 ) )
goto V_58;
V_70 = F_129 ( V_29 ) ;
if ( F_243 ( V_533 ) && V_70 < 16 && ! V_153 -> V_183 -> V_518 )
goto V_58;
if ( ( V_70 / 2 ) > V_153 -> V_457 )
goto V_58;
F_369 ( V_29 , V_153 ) ;
F_199 ( & V_29 -> V_28 . V_289 , & V_153 -> V_526 ) ;
V_527 ++ ;
V_153 -> V_457 -= V_70 ;
#ifdef F_376
if ( V_153 -> V_381 == V_534 )
break;
#endif
if ( V_153 -> V_457 <= 0 )
break;
continue;
V_58:
F_377 ( & V_29 -> V_28 . V_289 , V_526 ) ;
}
F_69 ( V_153 -> V_183 , V_524 [ V_153 -> V_381 ] , V_527 ) ;
return V_527 ;
}
static void F_378 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_364 ( & V_24 -> V_176 ) ;
F_170 ( F_36 ( V_29 ) != V_24 ) ;
V_29 -> V_76 = V_535 ;
F_379 ( V_24 , V_29 , 0 ) ;
F_380 ( V_24 , V_29 , 0 ) ;
}
static void F_381 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_276 ( & V_24 -> V_176 ) ;
F_378 ( V_24 , V_29 ) ;
F_278 ( & V_24 -> V_176 ) ;
}
static void F_382 ( struct V_503 * V_153 )
{
struct V_525 * V_526 = & V_153 -> V_526 ;
struct V_26 * V_29 ;
F_276 ( & V_153 -> V_173 -> V_176 ) ;
while ( ! F_294 ( V_526 ) ) {
V_29 = F_375 ( V_526 , struct V_26 , V_28 . V_289 ) ;
F_201 ( & V_29 -> V_28 . V_289 ) ;
F_378 ( V_153 -> V_173 , V_29 ) ;
}
F_278 ( & V_153 -> V_173 -> V_176 ) ;
}
static void F_383 ( struct V_291 * V_33 , int V_146 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_146 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_146 ] ;
if ( F_207 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_224 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_78 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_220 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_384 ( int V_146 )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
struct V_25 * V_25 ;
unsigned long V_177 ;
F_385 ( & V_24 -> V_176 , V_177 ) ;
F_289 ( V_24 ) ;
F_317 (rq, cfs_rq) {
F_383 ( V_25 -> V_33 , V_24 -> V_146 ) ;
}
F_386 ( & V_24 -> V_176 , V_177 ) ;
}
static void F_387 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_80 = V_193 ;
unsigned long V_70 ;
if ( V_25 -> V_536 == V_80 )
return;
V_25 -> V_537 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_537 = V_28 ;
if ( V_25 -> V_536 == V_80 )
break;
}
if ( ! V_28 ) {
V_25 -> V_538 = V_25 -> V_320 ;
V_25 -> V_536 = V_80 ;
}
while ( ( V_28 = V_25 -> V_537 ) != NULL ) {
V_70 = V_25 -> V_538 ;
V_70 = F_388 ( V_70 * V_28 -> V_77 . V_317 ,
V_25 -> V_320 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_538 = V_70 ;
V_25 -> V_536 = V_80 ;
}
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_387 ( V_25 ) ;
return F_388 ( V_29 -> V_28 . V_77 . V_317 * V_25 -> V_538 ,
V_25 -> V_320 + 1 ) ;
}
static inline void F_384 ( int V_146 )
{
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_317 ;
}
static inline void F_389 ( struct V_539 * V_540 )
{
* V_540 = (struct V_539 ) {
. V_541 = NULL ,
. V_202 = NULL ,
. V_542 = 0UL ,
. V_543 = 0UL ,
. V_544 = {
. V_459 = 0UL ,
. V_545 = 0 ,
. V_546 = V_547 ,
} ,
} ;
}
static inline int F_390 ( struct V_182 * V_183 ,
enum V_548 V_381 )
{
int V_455 ;
switch ( V_381 ) {
case V_549 :
V_455 = V_183 -> V_550 ;
break;
case V_534 :
V_455 = V_183 -> V_551 ;
break;
default:
V_455 = V_183 -> V_552 ;
break;
}
return V_455 ;
}
static unsigned long F_391 ( struct V_182 * V_183 , int V_146 )
{
return V_149 ;
}
unsigned long __weak F_392 ( struct V_182 * V_183 , int V_146 )
{
return F_391 ( V_183 , V_146 ) ;
}
static unsigned long F_393 ( struct V_182 * V_183 , int V_146 )
{
if ( ( V_183 -> V_177 & V_553 ) && ( V_183 -> V_483 > 1 ) )
return V_183 -> V_554 / V_183 -> V_483 ;
return V_149 ;
}
unsigned long __weak F_394 ( struct V_182 * V_183 , int V_146 )
{
return F_393 ( V_183 , V_146 ) ;
}
static unsigned long F_395 ( int V_146 )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
T_2 V_426 , V_555 , V_556 , V_77 ;
T_3 V_42 ;
V_556 = F_87 ( V_24 -> V_556 ) ;
V_77 = F_87 ( V_24 -> V_557 ) ;
V_42 = F_396 ( V_24 ) - V_556 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_426 = F_397 () + V_42 ;
if ( F_14 ( V_426 < V_77 ) ) {
V_555 = 0 ;
} else {
V_555 = V_426 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_426 < V_149 ) )
V_426 = V_149 ;
V_426 >>= V_558 ;
return F_216 ( V_555 , V_426 ) ;
}
static void F_398 ( struct V_182 * V_183 , int V_146 )
{
unsigned long V_147 = V_149 ;
struct V_449 * V_559 = V_183 -> V_452 ;
if ( F_243 ( V_560 ) )
V_147 *= F_394 ( V_183 , V_146 ) ;
else
V_147 *= F_393 ( V_183 , V_146 ) ;
V_147 >>= V_558 ;
V_559 -> V_461 -> V_561 = V_147 ;
if ( F_243 ( V_560 ) )
V_147 *= F_392 ( V_183 , V_146 ) ;
else
V_147 *= F_391 ( V_183 , V_146 ) ;
V_147 >>= V_558 ;
V_147 *= F_395 ( V_146 ) ;
V_147 >>= V_558 ;
if ( ! V_147 )
V_147 = 1 ;
F_113 ( V_146 ) -> V_429 = V_147 ;
V_559 -> V_461 -> V_147 = V_147 ;
}
void F_399 ( struct V_182 * V_183 , int V_146 )
{
struct V_182 * V_482 = V_183 -> V_482 ;
struct V_449 * V_118 , * V_559 = V_183 -> V_452 ;
unsigned long V_147 , V_561 ;
unsigned long V_190 ;
V_190 = F_144 ( V_183 -> V_562 ) ;
V_190 = F_149 ( V_190 , 1UL , V_563 ) ;
V_559 -> V_461 -> V_564 = V_193 + V_190 ;
if ( ! V_482 ) {
F_398 ( V_183 , V_146 ) ;
return;
}
V_561 = V_147 = 0 ;
if ( V_482 -> V_177 & V_565 ) {
F_112 (cpu, sched_group_cpus(sdg)) {
struct V_566 * V_461 ;
struct V_24 * V_24 = F_113 ( V_146 ) ;
if ( F_14 ( ! V_24 -> V_183 ) ) {
V_561 += F_115 ( V_146 ) ;
V_147 += F_115 ( V_146 ) ;
continue;
}
V_461 = V_24 -> V_183 -> V_452 -> V_461 ;
V_561 += V_461 -> V_561 ;
V_147 += V_461 -> V_147 ;
}
} else {
V_118 = V_482 -> V_452 ;
do {
V_561 += V_118 -> V_461 -> V_561 ;
V_147 += V_118 -> V_461 -> V_147 ;
V_118 = V_118 -> V_58 ;
} while ( V_118 != V_482 -> V_452 );
}
V_559 -> V_461 -> V_561 = V_561 ;
V_559 -> V_461 -> V_147 = V_147 ;
}
static inline int
F_400 ( struct V_182 * V_183 , struct V_449 * V_118 )
{
if ( ! ( V_183 -> V_177 & V_553 ) )
return 0 ;
if ( V_118 -> V_461 -> V_147 * 32 > V_118 -> V_461 -> V_561 * 29 )
return 1 ;
return 0 ;
}
static inline int F_401 ( struct V_449 * V_118 )
{
return V_118 -> V_461 -> V_457 ;
}
static inline int F_402 ( struct V_503 * V_153 , struct V_449 * V_118 )
{
unsigned int V_567 , V_145 , V_8 ;
unsigned int V_147 , V_561 ;
V_147 = V_118 -> V_461 -> V_147 ;
V_561 = V_118 -> V_461 -> V_561 ;
V_8 = V_118 -> F_102 ;
V_145 = F_56 ( V_149 * V_8 , V_561 ) ;
V_567 = V_8 / V_145 ;
V_567 = F_5 ( unsigned ,
V_567 , F_116 ( V_147 , V_149 ) ) ;
if ( ! V_567 )
V_567 = F_400 ( V_153 -> V_183 , V_118 ) ;
return V_567 ;
}
static enum V_546
F_403 ( struct V_449 * V_118 , struct V_568 * V_569 )
{
if ( V_569 -> V_545 > V_569 -> V_570 )
return V_571 ;
if ( F_401 ( V_118 ) )
return V_572 ;
return V_547 ;
}
static inline void F_404 ( struct V_503 * V_153 ,
struct V_449 * V_118 , int V_455 ,
int V_460 , struct V_568 * V_569 ,
bool * V_573 )
{
unsigned long V_70 ;
int V_240 ;
memset ( V_569 , 0 , sizeof( * V_569 ) ) ;
F_341 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_113 ( V_240 ) ;
if ( V_460 )
V_70 = F_328 ( V_240 , V_455 ) ;
else
V_70 = F_327 ( V_240 , V_455 ) ;
V_569 -> V_574 += V_70 ;
V_569 -> V_545 += V_24 -> V_40 . V_391 ;
if ( V_24 -> V_72 > 1 )
* V_573 = true ;
#ifdef F_405
V_569 -> V_104 += V_24 -> V_104 ;
V_569 -> V_106 += V_24 -> V_106 ;
#endif
V_569 -> V_575 += F_114 ( V_240 ) ;
if ( F_342 ( V_240 ) )
V_569 -> V_576 ++ ;
}
V_569 -> V_577 = V_118 -> V_461 -> V_147 ;
V_569 -> V_459 = ( V_569 -> V_574 * V_149 ) / V_569 -> V_577 ;
if ( V_569 -> V_545 )
V_569 -> V_578 = V_569 -> V_575 / V_569 -> V_545 ;
V_569 -> F_102 = V_118 -> F_102 ;
V_569 -> V_570 = F_402 ( V_153 , V_118 ) ;
V_569 -> V_546 = F_403 ( V_118 , V_569 ) ;
if ( V_569 -> V_570 > V_569 -> V_545 )
V_569 -> V_579 = 1 ;
}
static bool F_406 ( struct V_503 * V_153 ,
struct V_539 * V_540 ,
struct V_449 * V_471 ,
struct V_568 * V_569 )
{
struct V_568 * V_541 = & V_540 -> V_544 ;
if ( V_569 -> V_546 > V_541 -> V_546 )
return true ;
if ( V_569 -> V_546 < V_541 -> V_546 )
return false ;
if ( V_569 -> V_459 <= V_541 -> V_459 )
return false ;
if ( ! ( V_153 -> V_183 -> V_177 & V_580 ) )
return true ;
if ( V_569 -> V_545 && V_153 -> V_135 < F_407 ( V_471 ) ) {
if ( ! V_540 -> V_541 )
return true ;
if ( F_407 ( V_540 -> V_541 ) > F_407 ( V_471 ) )
return true ;
}
return false ;
}
static inline enum V_581 F_408 ( struct V_568 * V_569 )
{
if ( V_569 -> V_545 > V_569 -> V_104 )
return V_582 ;
if ( V_569 -> V_545 > V_569 -> V_106 )
return V_200 ;
return V_583 ;
}
static inline enum V_581 F_409 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_104 )
return V_582 ;
if ( V_24 -> V_72 > V_24 -> V_106 )
return V_200 ;
return V_583 ;
}
static inline enum V_581 F_408 ( struct V_568 * V_569 )
{
return V_583 ;
}
static inline enum V_581 F_409 ( struct V_24 * V_24 )
{
return V_582 ;
}
static inline void F_410 ( struct V_503 * V_153 , struct V_539 * V_540 )
{
struct V_182 * V_482 = V_153 -> V_183 -> V_482 ;
struct V_449 * V_471 = V_153 -> V_183 -> V_452 ;
struct V_568 V_584 ;
int V_455 , V_585 = 0 ;
bool V_573 = false ;
if ( V_482 && V_482 -> V_177 & V_586 )
V_585 = 1 ;
V_455 = F_390 ( V_153 -> V_183 , V_153 -> V_381 ) ;
do {
struct V_568 * V_569 = & V_584 ;
int V_460 ;
V_460 = F_127 ( V_153 -> V_135 , F_339 ( V_471 ) ) ;
if ( V_460 ) {
V_540 -> V_202 = V_471 ;
V_569 = & V_540 -> V_587 ;
if ( V_153 -> V_381 != V_534 ||
F_411 ( V_193 , V_471 -> V_461 -> V_564 ) )
F_399 ( V_153 -> V_183 , V_153 -> V_135 ) ;
}
F_404 ( V_153 , V_471 , V_455 , V_460 , V_569 ,
& V_573 ) ;
if ( V_460 )
goto V_588;
if ( V_585 && V_540 -> V_202 &&
V_540 -> V_587 . V_579 ) {
V_569 -> V_570 = F_143 ( V_569 -> V_570 , 1U ) ;
V_569 -> V_546 = F_403 ( V_471 , V_569 ) ;
}
if ( F_406 ( V_153 , V_540 , V_471 , V_569 ) ) {
V_540 -> V_541 = V_471 ;
V_540 -> V_544 = * V_569 ;
}
V_588:
V_540 -> V_542 += V_569 -> V_574 ;
V_540 -> V_543 += V_569 -> V_577 ;
V_471 = V_471 -> V_58 ;
} while ( V_471 != V_153 -> V_183 -> V_452 );
if ( V_153 -> V_183 -> V_177 & V_507 )
V_153 -> V_581 = F_408 ( & V_540 -> V_544 ) ;
if ( ! V_153 -> V_183 -> V_34 ) {
if ( V_153 -> V_173 -> V_589 -> V_573 != V_573 )
V_153 -> V_173 -> V_589 -> V_573 = V_573 ;
}
}
static int F_412 ( struct V_503 * V_153 , struct V_539 * V_540 )
{
int V_590 ;
if ( ! ( V_153 -> V_183 -> V_177 & V_580 ) )
return 0 ;
if ( ! V_540 -> V_541 )
return 0 ;
V_590 = F_407 ( V_540 -> V_541 ) ;
if ( V_153 -> V_135 > V_590 )
return 0 ;
V_153 -> V_457 = F_116 (
V_540 -> V_544 . V_459 * V_540 -> V_544 . V_577 ,
V_149 ) ;
return 1 ;
}
static inline
void F_413 ( struct V_503 * V_153 , struct V_539 * V_540 )
{
unsigned long V_475 , V_591 = 0 , V_592 = 0 ;
unsigned int V_593 = 2 ;
unsigned long V_594 ;
struct V_568 * V_202 , * V_541 ;
V_202 = & V_540 -> V_587 ;
V_541 = & V_540 -> V_544 ;
if ( ! V_202 -> V_545 )
V_202 -> V_578 = F_329 ( V_153 -> V_135 ) ;
else if ( V_541 -> V_578 > V_202 -> V_578 )
V_593 = 1 ;
V_594 =
( V_541 -> V_578 * V_149 ) /
V_541 -> V_577 ;
if ( V_541 -> V_459 + V_594 >=
V_202 -> V_459 + ( V_594 * V_593 ) ) {
V_153 -> V_457 = V_541 -> V_578 ;
return;
}
V_591 += V_541 -> V_577 *
F_143 ( V_541 -> V_578 , V_541 -> V_459 ) ;
V_591 += V_202 -> V_577 *
F_143 ( V_202 -> V_578 , V_202 -> V_459 ) ;
V_591 /= V_149 ;
if ( V_541 -> V_459 > V_594 ) {
V_592 += V_541 -> V_577 *
F_143 ( V_541 -> V_578 ,
V_541 -> V_459 - V_594 ) ;
}
if ( V_541 -> V_459 * V_541 -> V_577 <
V_541 -> V_578 * V_149 ) {
V_475 = ( V_541 -> V_459 * V_541 -> V_577 ) /
V_202 -> V_577 ;
} else {
V_475 = ( V_541 -> V_578 * V_149 ) /
V_202 -> V_577 ;
}
V_592 += V_202 -> V_577 *
F_143 ( V_202 -> V_578 , V_202 -> V_459 + V_475 ) ;
V_592 /= V_149 ;
if ( V_592 > V_591 )
V_153 -> V_457 = V_541 -> V_578 ;
}
static inline void F_414 ( struct V_503 * V_153 , struct V_539 * V_540 )
{
unsigned long V_595 , V_596 = ~ 0UL ;
struct V_568 * V_202 , * V_541 ;
V_202 = & V_540 -> V_587 ;
V_541 = & V_540 -> V_544 ;
if ( V_541 -> V_546 == V_572 ) {
V_541 -> V_578 =
F_143 ( V_541 -> V_578 , V_540 -> V_459 ) ;
}
if ( V_541 -> V_459 <= V_540 -> V_459 ||
V_202 -> V_459 >= V_540 -> V_459 ) {
V_153 -> V_457 = 0 ;
return F_413 ( V_153 , V_540 ) ;
}
if ( V_541 -> V_546 == V_571 &&
V_202 -> V_546 == V_571 ) {
V_596 =
( V_541 -> V_545 - V_541 -> V_570 ) ;
V_596 *= ( V_597 * V_149 ) ;
V_596 /= V_541 -> V_577 ;
}
V_595 = F_143 ( V_541 -> V_459 - V_540 -> V_459 , V_596 ) ;
V_153 -> V_457 = F_143 (
V_595 * V_541 -> V_577 ,
( V_540 -> V_459 - V_202 -> V_459 ) * V_202 -> V_577
) / V_149 ;
if ( V_153 -> V_457 < V_541 -> V_578 )
return F_413 ( V_153 , V_540 ) ;
}
static struct V_449 * F_415 ( struct V_503 * V_153 )
{
struct V_568 * V_202 , * V_541 ;
struct V_539 V_540 ;
F_389 ( & V_540 ) ;
F_410 ( V_153 , & V_540 ) ;
V_202 = & V_540 . V_587 ;
V_541 = & V_540 . V_544 ;
if ( ( V_153 -> V_381 == V_598 || V_153 -> V_381 == V_534 ) &&
F_412 ( V_153 , & V_540 ) )
return V_540 . V_541 ;
if ( ! V_540 . V_541 || V_541 -> V_545 == 0 )
goto V_599;
V_540 . V_459 = ( V_149 * V_540 . V_542 )
/ V_540 . V_543 ;
if ( V_541 -> V_546 == V_572 )
goto V_600;
if ( V_153 -> V_381 == V_534 && V_202 -> V_579 &&
! V_541 -> V_579 )
goto V_600;
if ( V_202 -> V_459 >= V_541 -> V_459 )
goto V_599;
if ( V_202 -> V_459 >= V_540 . V_459 )
goto V_599;
if ( V_153 -> V_381 == V_598 ) {
if ( ( V_541 -> V_546 != V_571 ) &&
( V_202 -> V_576 <= ( V_541 -> V_576 + 1 ) ) )
goto V_599;
} else {
if ( 100 * V_541 -> V_459 <=
V_153 -> V_183 -> V_168 * V_202 -> V_459 )
goto V_599;
}
V_600:
F_414 ( V_153 , & V_540 ) ;
return V_540 . V_541 ;
V_599:
V_153 -> V_457 = 0 ;
return NULL ;
}
static struct V_24 * F_416 ( struct V_503 * V_153 ,
struct V_449 * V_118 )
{
struct V_24 * V_541 = NULL , * V_24 ;
unsigned long V_601 = 0 , V_602 = 1 ;
int V_240 ;
F_341 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_147 , V_567 , V_433 ;
enum V_581 V_603 ;
V_24 = F_113 ( V_240 ) ;
V_603 = F_409 ( V_24 ) ;
if ( V_603 > V_153 -> V_581 )
continue;
V_147 = F_115 ( V_240 ) ;
V_567 = F_116 ( V_147 , V_149 ) ;
if ( ! V_567 )
V_567 = F_400 ( V_153 -> V_183 , V_118 ) ;
V_433 = F_114 ( V_240 ) ;
if ( V_567 && V_24 -> V_72 == 1 && V_433 > V_153 -> V_457 )
continue;
if ( V_433 * V_602 > V_601 * V_147 ) {
V_601 = V_433 ;
V_602 = V_147 ;
V_541 = V_24 ;
}
}
return V_541 ;
}
static int F_417 ( struct V_503 * V_153 )
{
struct V_182 * V_183 = V_153 -> V_183 ;
if ( V_153 -> V_381 == V_534 ) {
if ( ( V_183 -> V_177 & V_580 ) && V_153 -> V_172 > V_153 -> V_135 )
return 1 ;
}
return F_14 ( V_183 -> V_518 > V_183 -> V_519 + 2 ) ;
}
static int F_418 ( struct V_503 * V_153 )
{
struct V_449 * V_471 = V_153 -> V_183 -> V_452 ;
struct V_604 * V_605 , * V_606 ;
int V_146 , V_607 = - 1 ;
if ( V_153 -> V_381 == V_534 )
return 1 ;
V_605 = F_339 ( V_471 ) ;
V_606 = F_419 ( V_471 ) ;
F_341 (cpu, sg_cpus, env->cpus) {
if ( ! F_127 ( V_146 , V_606 ) || ! F_342 ( V_146 ) )
continue;
V_607 = V_146 ;
break;
}
if ( V_607 == - 1 )
V_607 = F_420 ( V_471 ) ;
return V_607 == V_153 -> V_135 ;
}
static int F_421 ( int V_442 , struct V_24 * V_333 ,
struct V_182 * V_183 , enum V_548 V_381 ,
int * V_608 )
{
int V_609 , V_610 , V_611 = 0 ;
struct V_182 * V_612 = V_183 -> V_34 ;
struct V_449 * V_118 ;
struct V_24 * V_541 ;
unsigned long V_177 ;
struct V_604 * V_8 = F_422 ( V_613 ) ;
struct V_503 V_153 = {
. V_183 = V_183 ,
. V_135 = V_442 ,
. V_173 = V_333 ,
. V_513 = F_339 ( V_183 -> V_452 ) ,
. V_381 = V_381 ,
. V_530 = V_531 ,
. V_8 = V_8 ,
. V_581 = V_583 ,
. V_526 = F_423 ( V_153 . V_526 ) ,
} ;
if ( V_381 == V_534 )
V_153 . V_513 = NULL ;
F_424 ( V_8 , V_614 ) ;
F_241 ( V_183 , V_615 [ V_381 ] ) ;
V_616:
if ( ! F_418 ( & V_153 ) ) {
* V_608 = 0 ;
goto V_599;
}
V_118 = F_415 ( & V_153 ) ;
if ( ! V_118 ) {
F_241 ( V_183 , V_617 [ V_381 ] ) ;
goto V_599;
}
V_541 = F_416 ( & V_153 , V_118 ) ;
if ( ! V_541 ) {
F_241 ( V_183 , V_618 [ V_381 ] ) ;
goto V_599;
}
F_170 ( V_541 == V_153 . V_173 ) ;
F_69 ( V_183 , V_619 [ V_381 ] , V_153 . V_457 ) ;
V_609 = 0 ;
if ( V_541 -> V_72 > 1 ) {
V_153 . V_177 |= V_516 ;
V_153 . V_172 = V_541 -> V_146 ;
V_153 . V_171 = V_541 ;
V_153 . V_529 = F_143 ( V_620 , V_541 -> V_72 ) ;
V_621:
F_385 ( & V_541 -> V_176 , V_177 ) ;
V_610 = F_374 ( & V_153 ) ;
F_278 ( & V_541 -> V_176 ) ;
if ( V_610 ) {
F_382 ( & V_153 ) ;
V_609 += V_610 ;
}
F_425 ( V_177 ) ;
if ( V_153 . V_177 & V_532 ) {
V_153 . V_177 &= ~ V_532 ;
goto V_621;
}
if ( ( V_153 . V_177 & V_514 ) && V_153 . V_457 > 0 ) {
F_426 ( V_153 . V_135 , V_153 . V_8 ) ;
V_153 . V_173 = F_113 ( V_153 . V_515 ) ;
V_153 . V_135 = V_153 . V_515 ;
V_153 . V_177 &= ~ V_514 ;
V_153 . V_528 = 0 ;
V_153 . V_530 = V_531 ;
goto V_621;
}
if ( V_612 ) {
int * V_622 = & V_612 -> V_452 -> V_461 -> V_457 ;
if ( ( V_153 . V_177 & V_512 ) && V_153 . V_457 > 0 )
* V_622 = 1 ;
}
if ( F_14 ( V_153 . V_177 & V_516 ) ) {
F_426 ( F_27 ( V_541 ) , V_8 ) ;
if ( ! F_427 ( V_8 ) ) {
V_153 . V_528 = 0 ;
V_153 . V_530 = V_531 ;
goto V_616;
}
goto V_623;
}
}
if ( ! V_609 ) {
F_241 ( V_183 , V_624 [ V_381 ] ) ;
if ( V_381 != V_534 )
V_183 -> V_518 ++ ;
if ( F_417 ( & V_153 ) ) {
F_385 ( & V_541 -> V_176 , V_177 ) ;
if ( ! F_127 ( V_442 ,
F_128 ( V_541 -> V_45 ) ) ) {
F_386 ( & V_541 -> V_176 ,
V_177 ) ;
V_153 . V_177 |= V_516 ;
goto V_625;
}
if ( ! V_541 -> V_611 ) {
V_541 -> V_611 = 1 ;
V_541 -> V_626 = V_442 ;
V_611 = 1 ;
}
F_386 ( & V_541 -> V_176 , V_177 ) ;
if ( V_611 ) {
F_428 ( F_27 ( V_541 ) ,
V_627 , V_541 ,
& V_541 -> V_628 ) ;
}
V_183 -> V_518 = V_183 -> V_519 + 1 ;
}
} else
V_183 -> V_518 = 0 ;
if ( F_12 ( ! V_611 ) ) {
V_183 -> V_562 = V_183 -> V_629 ;
} else {
if ( V_183 -> V_562 < V_183 -> V_630 )
V_183 -> V_562 *= 2 ;
}
goto V_287;
V_599:
if ( V_612 ) {
int * V_622 = & V_612 -> V_452 -> V_461 -> V_457 ;
if ( * V_622 )
* V_622 = 0 ;
}
V_623:
F_241 ( V_183 , V_631 [ V_381 ] ) ;
V_183 -> V_518 = 0 ;
V_625:
if ( ( ( V_153 . V_177 & V_516 ) &&
V_183 -> V_562 < V_632 ) ||
( V_183 -> V_562 < V_183 -> V_630 ) )
V_183 -> V_562 *= 2 ;
V_609 = 0 ;
V_287:
return V_609 ;
}
static inline unsigned long
F_429 ( struct V_182 * V_183 , int V_633 )
{
unsigned long V_190 = V_183 -> V_562 ;
if ( V_633 )
V_190 *= V_183 -> V_634 ;
V_190 = F_144 ( V_190 ) ;
V_190 = F_149 ( V_190 , 1UL , V_563 ) ;
return V_190 ;
}
static inline void
F_430 ( struct V_182 * V_183 , int V_633 , unsigned long * V_635 )
{
unsigned long V_190 , V_58 ;
V_190 = F_429 ( V_183 , V_633 ) ;
V_58 = V_183 -> V_636 + V_190 ;
if ( F_180 ( * V_635 , V_58 ) )
* V_635 = V_58 ;
}
static int F_232 ( struct V_24 * V_333 )
{
unsigned long V_635 = V_193 + V_191 ;
int V_442 = V_333 -> V_146 ;
struct V_182 * V_183 ;
int V_637 = 0 ;
T_2 V_638 = 0 ;
F_230 ( V_333 ) ;
V_333 -> V_469 = F_76 ( V_333 ) ;
if ( V_333 -> V_639 < V_505 ||
! V_333 -> V_589 -> V_573 ) {
F_123 () ;
V_183 = F_431 ( V_333 -> V_183 ) ;
if ( V_183 )
F_430 ( V_183 , 0 , & V_635 ) ;
F_131 () ;
goto V_287;
}
F_278 ( & V_333 -> V_176 ) ;
F_384 ( V_442 ) ;
F_123 () ;
F_348 (this_cpu, sd) {
int V_608 = 1 ;
T_2 V_640 , V_641 ;
if ( ! ( V_183 -> V_177 & V_480 ) )
continue;
if ( V_333 -> V_639 < V_638 + V_183 -> V_642 ) {
F_430 ( V_183 , 0 , & V_635 ) ;
break;
}
if ( V_183 -> V_177 & V_643 ) {
V_640 = F_271 ( V_442 ) ;
V_637 = F_421 ( V_442 , V_333 ,
V_183 , V_534 ,
& V_608 ) ;
V_641 = F_271 ( V_442 ) - V_640 ;
if ( V_641 > V_183 -> V_642 )
V_183 -> V_642 = V_641 ;
V_638 += V_641 ;
}
F_430 ( V_183 , 0 , & V_635 ) ;
if ( V_637 || V_333 -> V_72 > 0 )
break;
}
F_131 () ;
F_276 ( & V_333 -> V_176 ) ;
if ( V_638 > V_333 -> V_644 )
V_333 -> V_644 = V_638 ;
if ( V_333 -> V_40 . V_391 && ! V_637 )
V_637 = 1 ;
V_287:
if ( F_180 ( V_333 -> V_635 , V_635 ) )
V_333 -> V_635 = V_635 ;
if ( V_333 -> V_72 != V_333 -> V_40 . V_391 )
V_637 = - 1 ;
if ( V_637 ) {
F_231 ( V_333 ) ;
V_333 -> V_469 = 0 ;
}
return V_637 ;
}
static int V_627 ( void * V_387 )
{
struct V_24 * V_645 = V_387 ;
int V_590 = F_27 ( V_645 ) ;
int V_646 = V_645 -> V_626 ;
struct V_24 * V_647 = F_113 ( V_646 ) ;
struct V_182 * V_183 ;
struct V_26 * V_29 = NULL ;
F_124 ( & V_645 -> V_176 ) ;
if ( F_14 ( V_590 != F_272 () ||
! V_645 -> V_611 ) )
goto V_648;
if ( V_645 -> V_72 <= 1 )
goto V_648;
F_170 ( V_645 == V_647 ) ;
F_123 () ;
F_348 (target_cpu, sd) {
if ( ( V_183 -> V_177 & V_480 ) &&
F_127 ( V_590 , F_349 ( V_183 ) ) )
break;
}
if ( F_12 ( V_183 ) ) {
struct V_503 V_153 = {
. V_183 = V_183 ,
. V_135 = V_646 ,
. V_173 = V_647 ,
. V_172 = V_645 -> V_146 ,
. V_171 = V_645 ,
. V_381 = V_598 ,
} ;
F_241 ( V_183 , V_649 ) ;
V_29 = F_372 ( & V_153 ) ;
if ( V_29 )
F_241 ( V_183 , V_650 ) ;
else
F_241 ( V_183 , V_651 ) ;
}
F_131 () ;
V_648:
V_645 -> V_611 = 0 ;
F_278 ( & V_645 -> V_176 ) ;
if ( V_29 )
F_381 ( V_647 , V_29 ) ;
F_432 () ;
return 0 ;
}
static inline int F_433 ( struct V_24 * V_24 )
{
return F_14 ( ! F_434 ( V_24 -> V_183 ) ) ;
}
static inline int F_435 ( void )
{
int V_652 = F_436 ( V_653 . V_654 ) ;
if ( V_652 < V_655 && F_342 ( V_652 ) )
return V_652 ;
return V_655 ;
}
static void F_437 ( void )
{
int V_656 ;
V_653 . V_635 ++ ;
V_656 = F_435 () ;
if ( V_656 >= V_655 )
return;
if ( F_438 ( V_657 , F_439 ( V_656 ) ) )
return;
F_440 ( V_656 ) ;
return;
}
static inline void F_441 ( int V_146 )
{
if ( F_14 ( F_442 ( V_658 , F_439 ( V_146 ) ) ) ) {
if ( F_12 ( F_127 ( V_146 , V_653 . V_654 ) ) ) {
F_426 ( V_146 , V_653 . V_654 ) ;
F_443 ( & V_653 . V_659 ) ;
}
F_444 ( V_658 , F_439 ( V_146 ) ) ;
}
}
static inline void F_445 ( void )
{
struct V_182 * V_183 ;
int V_146 = F_272 () ;
F_123 () ;
V_183 = F_135 ( F_136 ( V_660 , V_146 ) ) ;
if ( ! V_183 || ! V_183 -> V_661 )
goto V_179;
V_183 -> V_661 = 0 ;
F_446 ( & V_183 -> V_452 -> V_461 -> V_662 ) ;
V_179:
F_131 () ;
}
void F_447 ( void )
{
struct V_182 * V_183 ;
int V_146 = F_272 () ;
F_123 () ;
V_183 = F_135 ( F_136 ( V_660 , V_146 ) ) ;
if ( ! V_183 || V_183 -> V_661 )
goto V_179;
V_183 -> V_661 = 1 ;
F_443 ( & V_183 -> V_452 -> V_461 -> V_662 ) ;
V_179:
F_131 () ;
}
void F_448 ( int V_146 )
{
if ( ! F_449 ( V_146 ) )
return;
if ( F_442 ( V_658 , F_439 ( V_146 ) ) )
return;
if ( F_433 ( F_113 ( V_146 ) ) )
return;
F_450 ( V_146 , V_653 . V_654 ) ;
F_446 ( & V_653 . V_659 ) ;
F_451 ( V_658 , F_439 ( V_146 ) ) ;
}
static int F_452 ( struct V_663 * V_664 ,
unsigned long V_665 , void * V_666 )
{
switch ( V_665 & ~ V_667 ) {
case V_668 :
F_441 ( F_272 () ) ;
return V_669 ;
default:
return V_670 ;
}
}
void F_453 ( void )
{
V_563 = V_191 * F_6 () / 10 ;
}
static void F_454 ( struct V_24 * V_24 , enum V_548 V_381 )
{
int V_608 = 1 ;
int V_146 = V_24 -> V_146 ;
unsigned long V_190 ;
struct V_182 * V_183 ;
unsigned long V_635 = V_193 + 60 * V_191 ;
int F_430 = 0 ;
int V_671 , V_672 = 0 ;
T_2 V_673 = 0 ;
F_384 ( V_146 ) ;
F_123 () ;
F_348 (cpu, sd) {
if ( F_180 ( V_193 , V_183 -> V_674 ) ) {
V_183 -> V_642 =
( V_183 -> V_642 * 253 ) / 256 ;
V_183 -> V_674 = V_193 + V_191 ;
V_672 = 1 ;
}
V_673 += V_183 -> V_642 ;
if ( ! ( V_183 -> V_177 & V_480 ) )
continue;
if ( ! V_608 ) {
if ( V_672 )
continue;
break;
}
V_190 = F_429 ( V_183 , V_381 != V_598 ) ;
V_671 = V_183 -> V_177 & V_675 ;
if ( V_671 ) {
if ( ! F_455 ( & V_676 ) )
goto V_287;
}
if ( F_411 ( V_193 , V_183 -> V_636 + V_190 ) ) {
if ( F_421 ( V_146 , V_24 , V_183 , V_381 , & V_608 ) ) {
V_381 = F_342 ( V_146 ) ? V_598 : V_549 ;
}
V_183 -> V_636 = V_193 ;
V_190 = F_429 ( V_183 , V_381 != V_598 ) ;
}
if ( V_671 )
F_173 ( & V_676 ) ;
V_287:
if ( F_180 ( V_635 , V_183 -> V_636 + V_190 ) ) {
V_635 = V_183 -> V_636 + V_190 ;
F_430 = 1 ;
}
}
if ( V_672 ) {
V_24 -> V_644 =
F_68 ( ( T_2 ) V_505 , V_673 ) ;
}
F_131 () ;
if ( F_12 ( F_430 ) )
V_24 -> V_635 = V_635 ;
}
static void F_456 ( struct V_24 * V_333 , enum V_548 V_381 )
{
int V_442 = V_333 -> V_146 ;
struct V_24 * V_24 ;
int V_607 ;
if ( V_381 != V_598 ||
! F_442 ( V_657 , F_439 ( V_442 ) ) )
goto V_269;
F_112 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_607 == V_442 || ! F_342 ( V_607 ) )
continue;
if ( F_457 () )
break;
V_24 = F_113 ( V_607 ) ;
if ( F_411 ( V_193 , V_24 -> V_635 ) ) {
F_124 ( & V_24 -> V_176 ) ;
F_289 ( V_24 ) ;
F_458 ( V_24 ) ;
F_126 ( & V_24 -> V_176 ) ;
F_454 ( V_24 , V_598 ) ;
}
if ( F_180 ( V_333 -> V_635 , V_24 -> V_635 ) )
V_333 -> V_635 = V_24 -> V_635 ;
}
V_653 . V_635 = V_333 -> V_635 ;
V_269:
F_444 ( V_657 , F_439 ( V_442 ) ) ;
}
static inline int F_459 ( struct V_24 * V_24 )
{
unsigned long V_80 = V_193 ;
struct V_182 * V_183 ;
struct V_566 * V_461 ;
int V_677 , V_146 = V_24 -> V_146 ;
if ( F_14 ( V_24 -> F_232 ) )
return 0 ;
F_445 () ;
F_441 ( V_146 ) ;
if ( F_12 ( ! F_219 ( & V_653 . V_659 ) ) )
return 0 ;
if ( F_183 ( V_80 , V_653 . V_635 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_678;
F_123 () ;
V_183 = F_135 ( F_136 ( V_660 , V_146 ) ) ;
if ( V_183 ) {
V_461 = V_183 -> V_452 -> V_461 ;
V_677 = F_219 ( & V_461 -> V_662 ) ;
if ( V_677 > 1 )
goto V_679;
}
V_183 = F_135 ( F_136 ( V_680 , V_146 ) ) ;
if ( V_183 && ( F_346 ( V_653 . V_654 ,
F_349 ( V_183 ) ) < V_146 ) )
goto V_679;
F_131 () ;
return 0 ;
V_679:
F_131 () ;
V_678:
return 1 ;
}
static void F_456 ( struct V_24 * V_333 , enum V_548 V_381 ) { }
static void F_460 ( struct V_681 * V_682 )
{
struct V_24 * V_333 = V_333 () ;
enum V_548 V_381 = V_333 -> F_232 ?
V_598 : V_549 ;
F_454 ( V_333 , V_381 ) ;
F_456 ( V_333 , V_381 ) ;
}
void F_461 ( struct V_24 * V_24 )
{
if ( F_14 ( F_433 ( V_24 ) ) )
return;
if ( F_411 ( V_193 , V_24 -> V_635 ) )
F_462 ( V_683 ) ;
#ifdef F_463
if ( F_459 ( V_24 ) )
F_437 () ;
#endif
}
static void F_464 ( struct V_24 * V_24 )
{
F_8 () ;
F_316 ( V_24 ) ;
}
static void F_465 ( struct V_24 * V_24 )
{
F_8 () ;
F_318 ( V_24 ) ;
}
static void F_466 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_362 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_259 ( V_25 , V_28 , V_362 ) ;
}
if ( V_254 )
F_194 ( V_24 , V_45 ) ;
F_220 ( V_24 , 1 ) ;
}
static void F_467 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_442 = F_272 () ;
struct V_24 * V_24 = V_333 () ;
unsigned long V_177 ;
F_385 ( & V_24 -> V_176 , V_177 ) ;
F_289 ( V_24 ) ;
V_25 = F_23 ( V_140 ) ;
V_45 = V_25 -> V_45 ;
F_123 () ;
F_468 ( V_29 , V_442 ) ;
F_131 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_242 ( V_25 , V_28 , 1 ) ;
if ( V_684 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_121 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_253 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_386 ( & V_24 -> V_176 , V_177 ) ;
}
static void
F_469 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_685 )
{
if ( ! F_470 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_686 > V_685 )
F_253 ( V_24 ) ;
} else
F_380 ( V_24 , V_29 , 0 ) ;
}
static void F_471 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! F_470 ( V_29 ) && V_29 -> V_354 != V_687 ) {
F_242 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_198
if ( V_28 -> V_77 . V_316 ) {
F_211 ( V_28 ) ;
F_223 ( V_25 , V_28 -> V_77 . V_317 ) ;
}
#endif
}
static void F_472 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
#ifdef F_357
struct V_27 * V_28 = & V_29 -> V_28 ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_470 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 )
F_253 ( V_24 ) ;
else
F_380 ( V_24 , V_29 , 0 ) ;
}
static void F_473 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_254 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_474 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_688 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_198
F_475 ( & V_25 -> V_315 , 1 ) ;
F_476 ( & V_25 -> V_330 , 0 ) ;
#endif
}
static void F_477 ( struct V_26 * V_29 , int V_362 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_362 && ( ! V_28 -> V_84 || V_29 -> V_354 == V_689 ) )
V_362 = 1 ;
if ( ! V_362 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_478 ( V_29 , F_134 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_362 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_198
V_28 -> V_77 . V_316 = F_212 ( & V_25 -> V_315 ) ;
V_25 -> V_321 += V_28 -> V_77 . V_317 ;
#endif
}
}
void F_479 ( struct V_291 * V_33 )
{
int V_240 ;
F_314 ( F_274 ( V_33 ) ) ;
F_480 (i) {
if ( V_33 -> V_25 )
F_178 ( V_33 -> V_25 [ V_240 ] ) ;
if ( V_33 -> V_28 )
F_178 ( V_33 -> V_28 [ V_240 ] ) ;
}
F_178 ( V_33 -> V_25 ) ;
F_178 ( V_33 -> V_28 ) ;
}
int F_481 ( struct V_291 * V_33 , struct V_291 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_240 ;
V_33 -> V_25 = F_166 ( sizeof( V_25 ) * V_655 , V_242 ) ;
if ( ! V_33 -> V_25 )
goto V_690;
V_33 -> V_28 = F_166 ( sizeof( V_28 ) * V_655 , V_242 ) ;
if ( ! V_33 -> V_28 )
goto V_690;
V_33 -> V_295 = V_71 ;
F_307 ( F_274 ( V_33 ) ) ;
F_480 (i) {
V_25 = F_482 ( sizeof( struct V_25 ) ,
V_242 , F_104 ( V_240 ) ) ;
if ( ! V_25 )
goto V_690;
V_28 = F_482 ( sizeof( struct V_27 ) ,
V_242 , F_104 ( V_240 ) ) ;
if ( ! V_28 )
goto V_691;
F_474 ( V_25 ) ;
F_483 ( V_33 , V_25 , V_28 , V_240 , V_34 -> V_28 [ V_240 ] ) ;
}
return 1 ;
V_691:
F_178 ( V_25 ) ;
V_690:
return 0 ;
}
void F_484 ( struct V_291 * V_33 , int V_146 )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
unsigned long V_177 ;
if ( ! V_33 -> V_25 [ V_146 ] -> V_32 )
return;
F_385 ( & V_24 -> V_176 , V_177 ) ;
F_31 ( V_33 -> V_25 [ V_146 ] ) ;
F_386 ( & V_24 -> V_176 , V_177 ) ;
}
void F_483 ( struct V_291 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_146 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_113 ( V_146 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_311 ( V_25 ) ;
V_33 -> V_25 [ V_146 ] = V_25 ;
V_33 -> V_28 [ V_146 ] = V_28 ;
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
int F_485 ( struct V_291 * V_33 , unsigned long V_295 )
{
int V_240 ;
unsigned long V_177 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_187 ;
V_295 = F_149 ( V_295 , F_221 ( V_296 ) , F_221 ( V_692 ) ) ;
F_486 ( & V_693 ) ;
if ( V_33 -> V_295 == V_295 )
goto V_473;
V_33 -> V_295 = V_295 ;
F_480 (i) {
struct V_24 * V_24 = F_113 ( V_240 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_240 ] ;
F_385 ( & V_24 -> V_176 , V_177 ) ;
F_289 ( V_24 ) ;
F_61 (se)
F_206 ( F_25 ( V_28 ) ) ;
F_386 ( & V_24 -> V_176 , V_177 ) ;
}
V_473:
F_487 ( & V_693 ) ;
return 0 ;
}
void F_479 ( struct V_291 * V_33 ) { }
int F_481 ( struct V_291 * V_33 , struct V_291 * V_34 )
{
return 1 ;
}
void F_484 ( struct V_291 * V_33 , int V_146 ) { }
static unsigned int F_488 ( struct V_24 * V_24 , struct V_26 * V_121 )
{
struct V_27 * V_28 = & V_121 -> V_28 ;
unsigned int V_694 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_694 = F_489 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_694 ;
}
void F_490 ( struct V_695 * V_696 , int V_146 )
{
struct V_25 * V_25 ;
F_123 () ;
F_317 (cpu_rq(cpu), cfs_rq)
F_491 ( V_696 , V_146 , V_25 ) ;
F_131 () ;
}
T_13 void F_492 ( void )
{
#ifdef F_198
F_493 ( V_683 , F_460 ) ;
#ifdef F_463
V_653 . V_635 = V_193 ;
F_494 ( & V_653 . V_654 , V_697 ) ;
F_495 ( F_452 , 0 ) ;
#endif
#endif
}
