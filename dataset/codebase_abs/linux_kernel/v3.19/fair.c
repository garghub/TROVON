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
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_75 = F_60 ( F_23 ( V_29 ) , & V_29 -> V_28 ) >> 10 ;
V_29 -> V_28 . V_77 . V_79 = V_75 ;
V_29 -> V_28 . V_77 . V_80 = V_75 ;
F_64 ( & V_29 -> V_28 ) ;
}
void F_63 ( struct V_26 * V_29 )
{
}
static void F_65 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_81 = F_66 ( F_17 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_14 ( ! V_45 ) )
return;
V_19 = V_81 - V_45 -> V_82 ;
if ( F_14 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_82 = V_81 ;
F_67 ( V_45 -> V_83 . V_84 ,
F_68 ( V_19 , V_45 -> V_83 . V_84 ) ) ;
V_45 -> V_85 += V_19 ;
F_69 ( V_25 , V_86 , V_19 ) ;
V_45 -> V_41 += F_58 ( V_19 , V_45 ) ;
F_40 ( V_25 ) ;
if ( F_21 ( V_45 ) ) {
struct V_26 * V_87 = F_18 ( V_45 ) ;
F_70 ( V_87 , V_19 , V_45 -> V_41 ) ;
F_71 ( V_87 , V_19 ) ;
F_72 ( V_87 , V_19 ) ;
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
F_67 ( V_28 -> V_83 . V_88 , F_76 ( F_17 ( V_25 ) ) ) ;
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
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ) ;
F_67 ( V_28 -> V_83 . V_90 , V_28 -> V_83 . V_90 + 1 ) ;
F_67 ( V_28 -> V_83 . V_91 , V_28 -> V_83 . V_91 +
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
#ifdef F_79
if ( F_21 ( V_28 ) ) {
F_80 ( F_18 ( V_28 ) ,
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
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
V_28 -> V_82 = F_66 ( F_17 ( V_25 ) ) ;
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
V_146 = F_56 ( V_150 * V_8 , V_145 -> V_149 ) ;
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
static int F_133 ( struct V_26 * V_29 )
{
struct V_153 V_154 = {
. V_29 = V_29 ,
. V_173 = F_134 ( V_29 ) ,
. V_135 = F_91 ( V_29 ) ,
. V_169 = 112 ,
. V_156 = NULL ,
. V_157 = 0 ,
. V_158 = - 1
} ;
struct V_183 * V_184 ;
unsigned long V_185 , V_186 ;
int V_112 , V_66 , V_127 ;
long V_170 , V_171 ;
F_123 () ;
V_184 = F_135 ( F_136 ( V_187 , V_154 . V_173 ) ) ;
if ( V_184 )
V_154 . V_169 = 100 + ( V_184 -> V_169 - 100 ) / 2 ;
F_131 () ;
if ( F_14 ( ! V_184 ) ) {
V_29 -> V_106 = F_91 ( V_29 ) ;
return - V_188 ;
}
V_154 . V_138 = V_29 -> V_106 ;
V_127 = V_154 . V_127 = F_100 ( V_154 . V_135 , V_154 . V_138 ) ;
V_185 = F_101 ( V_29 , V_154 . V_135 , V_127 ) ;
V_186 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
F_111 ( & V_154 . V_167 , V_154 . V_135 ) ;
V_170 = F_101 ( V_29 , V_154 . V_138 , V_127 ) - V_185 ;
V_171 = F_102 ( V_29 , V_154 . V_138 , V_127 ) - V_186 ;
F_111 ( & V_154 . V_168 , V_154 . V_138 ) ;
F_132 ( & V_154 , V_170 , V_171 ) ;
if ( V_154 . V_158 == - 1 || ( V_29 -> V_108 &&
F_137 ( V_29 -> V_108 -> V_143 ) > 1 ) ) {
F_99 (nid) {
if ( V_112 == V_154 . V_135 || V_112 == V_29 -> V_106 )
continue;
V_127 = F_100 ( V_154 . V_135 , V_154 . V_138 ) ;
if ( V_125 == V_129 &&
V_127 != V_154 . V_127 ) {
V_185 = F_101 ( V_29 , V_154 . V_135 , V_127 ) ;
V_186 = F_102 ( V_29 , V_154 . V_135 , V_127 ) ;
}
V_170 = F_101 ( V_29 , V_112 , V_127 ) - V_185 ;
V_171 = F_102 ( V_29 , V_112 , V_127 ) - V_186 ;
if ( V_170 < 0 && V_171 < 0 )
continue;
V_154 . V_127 = V_127 ;
V_154 . V_138 = V_112 ;
F_111 ( & V_154 . V_168 , V_154 . V_138 ) ;
F_132 ( & V_154 , V_170 , V_171 ) ;
}
}
if ( V_29 -> V_108 ) {
if ( V_154 . V_158 == - 1 )
V_112 = V_154 . V_135 ;
else
V_112 = V_154 . V_138 ;
if ( F_110 ( V_112 , V_29 -> V_108 -> V_143 ) )
F_138 ( V_29 , V_154 . V_138 ) ;
}
if ( V_154 . V_158 == - 1 )
return - V_189 ;
V_29 -> V_190 = F_86 ( V_29 ) ;
if ( V_154 . V_156 == NULL ) {
V_66 = F_139 ( V_29 , V_154 . V_158 ) ;
if ( V_66 != 0 )
F_140 ( V_29 , V_154 . V_173 , V_154 . V_158 ) ;
return V_66 ;
}
V_66 = F_141 ( V_29 , V_154 . V_156 ) ;
if ( V_66 != 0 )
F_140 ( V_29 , V_154 . V_173 , F_134 ( V_154 . V_156 ) ) ;
F_118 ( V_154 . V_156 ) ;
return V_66 ;
}
static void F_142 ( struct V_26 * V_29 )
{
unsigned long V_191 = V_192 ;
if ( F_14 ( V_29 -> V_106 == - 1 || ! V_29 -> V_116 ) )
return;
V_191 = F_143 ( V_191 , F_144 ( V_29 -> V_190 ) / 16 ) ;
V_29 -> V_193 = V_194 + V_191 ;
if ( F_91 ( V_29 ) == V_29 -> V_106 )
return;
F_133 ( V_29 ) ;
}
static void F_145 ( struct V_108 * V_108 )
{
unsigned long V_118 , V_195 = 0 ;
int V_112 ;
F_99 (nid) {
V_118 = F_97 ( V_108 , V_112 ) ;
if ( V_118 > V_195 )
V_195 = V_118 ;
}
F_99 (nid) {
V_118 = F_97 ( V_108 , V_112 ) ;
if ( ! F_110 ( V_112 , V_108 -> V_143 ) ) {
if ( V_118 > V_195 * 6 / 16 )
F_146 ( V_112 , V_108 -> V_143 ) ;
} else if ( V_118 < V_195 * 3 / 16 )
F_147 ( V_112 , V_108 -> V_143 ) ;
}
}
static void F_148 ( struct V_26 * V_29 ,
unsigned long V_196 , unsigned long V_197 )
{
unsigned int V_198 ;
int V_199 ;
int V_200 ;
unsigned long V_201 = V_29 -> V_202 [ 0 ] ;
unsigned long V_203 = V_29 -> V_202 [ 1 ] ;
if ( V_203 + V_196 == 0 ) {
V_29 -> V_190 = F_143 ( V_29 -> V_204 ,
V_29 -> V_190 << 1 ) ;
V_29 -> V_96 -> V_205 = V_194 +
F_144 ( V_29 -> V_190 ) ;
return;
}
V_198 = F_56 ( V_29 -> V_190 , V_206 ) ;
V_199 = ( V_203 * V_206 ) / ( V_203 + V_201 ) ;
if ( V_199 >= V_207 ) {
int V_208 = V_199 - V_207 ;
if ( ! V_208 )
V_208 = 1 ;
V_200 = V_208 * V_198 ;
} else {
V_200 = - ( V_207 - V_199 ) * V_198 ;
V_199 = F_56 ( V_197 * V_206 , ( V_197 + V_196 + 1 ) ) ;
V_200 = ( V_200 * V_199 ) / V_206 ;
}
V_29 -> V_190 = F_149 ( V_29 -> V_190 + V_200 ,
F_86 ( V_29 ) , F_89 ( V_29 ) ) ;
memset ( V_29 -> V_202 , 0 , sizeof( V_29 -> V_202 ) ) ;
}
static T_2 F_150 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_209 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_209 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_210 ) {
V_42 = V_209 - V_29 -> V_211 ;
* V_73 = V_81 - V_29 -> V_210 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_79 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_211 = V_209 ;
V_29 -> V_210 = V_81 ;
return V_42 ;
}
static int F_151 ( struct V_26 * V_29 , int V_112 )
{
T_8 V_212 ;
int V_127 ;
if ( V_125 == V_126 )
return V_112 ;
if ( V_125 == V_130 ) {
unsigned long V_123 , V_213 = 0 ;
int V_124 , V_214 = V_112 ;
V_127 = V_128 ;
F_99 (node) {
V_123 = F_102 ( V_29 , V_124 , V_127 ) ;
if ( V_123 > V_213 ) {
V_213 = V_123 ;
V_214 = V_124 ;
}
}
return V_214 ;
}
V_212 = V_215 ;
for ( V_127 = V_128 ; V_127 > V_131 ; V_127 -- ) {
unsigned long V_195 = 0 ;
T_8 V_216 = V_217 ;
int V_43 , V_44 ;
if ( ! F_152 ( V_127 ) )
continue;
F_153 (a, nodes) {
unsigned long V_118 = 0 ;
T_8 V_218 ;
F_154 ( V_218 ) ;
F_153 (b, nodes) {
if ( F_100 ( V_43 , V_44 ) < V_127 ) {
V_118 += F_96 ( V_29 , V_44 ) ;
F_146 ( V_44 , V_218 ) ;
F_147 ( V_44 , V_212 ) ;
}
}
if ( V_118 > V_195 ) {
V_195 = V_118 ;
V_216 = V_218 ;
V_112 = V_43 ;
}
}
V_212 = V_216 ;
}
return V_112 ;
}
static void F_155 ( struct V_26 * V_29 )
{
int V_219 , V_112 , V_220 = - 1 , V_221 = - 1 ;
unsigned long V_195 = 0 , V_222 = 0 ;
unsigned long V_223 [ 2 ] = { 0 , 0 } ;
unsigned long V_132 ;
T_2 V_209 , V_73 ;
T_9 * V_224 = NULL ;
V_219 = F_87 ( V_29 -> V_96 -> V_225 ) ;
if ( V_29 -> V_225 == V_219 )
return;
V_29 -> V_225 = V_219 ;
V_29 -> V_204 = F_89 ( V_29 ) ;
V_132 = V_29 -> V_202 [ 0 ] +
V_29 -> V_202 [ 1 ] ;
V_209 = F_150 ( V_29 , & V_73 ) ;
if ( V_29 -> V_108 ) {
V_224 = & V_29 -> V_108 -> V_177 ;
F_156 ( V_224 ) ;
}
F_99 (nid) {
int V_226 , V_227 , V_228 , V_229 ;
unsigned long V_118 = 0 , F_96 = 0 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
long V_200 , V_230 , V_231 ;
V_226 = F_94 ( V_117 , V_112 , V_113 ) ;
V_227 = F_94 ( V_232 , V_112 , V_113 ) ;
V_228 = F_94 ( V_233 , V_112 , V_113 ) ;
V_229 = F_94 ( V_234 , V_112 , V_113 ) ;
V_200 = V_29 -> V_116 [ V_227 ] - V_29 -> V_116 [ V_226 ] / 2 ;
V_223 [ V_113 ] += V_29 -> V_116 [ V_227 ] ;
V_29 -> V_116 [ V_227 ] = 0 ;
V_231 = F_157 ( V_209 << 16 , V_73 + 1 ) ;
V_231 = ( V_231 * V_29 -> V_116 [ V_229 ] ) /
( V_132 + 1 ) ;
V_230 = V_231 - V_29 -> V_116 [ V_228 ] / 2 ;
V_29 -> V_116 [ V_229 ] = 0 ;
V_29 -> V_116 [ V_226 ] += V_200 ;
V_29 -> V_116 [ V_228 ] += V_230 ;
V_118 += V_29 -> V_116 [ V_226 ] ;
V_29 -> V_133 += V_200 ;
if ( V_29 -> V_108 ) {
V_29 -> V_108 -> V_118 [ V_226 ] += V_200 ;
V_29 -> V_108 -> V_120 [ V_226 ] += V_230 ;
V_29 -> V_108 -> V_132 += V_200 ;
F_96 += V_29 -> V_108 -> V_118 [ V_226 ] ;
}
}
if ( V_118 > V_195 ) {
V_195 = V_118 ;
V_220 = V_112 ;
}
if ( F_96 > V_222 ) {
V_222 = F_96 ;
V_221 = V_112 ;
}
}
F_148 ( V_29 , V_223 [ 0 ] , V_223 [ 1 ] ) ;
if ( V_29 -> V_108 ) {
F_145 ( V_29 -> V_108 ) ;
F_158 ( V_224 ) ;
V_220 = F_151 ( V_29 , V_221 ) ;
}
if ( V_195 ) {
if ( V_220 != V_29 -> V_106 )
F_138 ( V_29 , V_220 ) ;
if ( F_91 ( V_29 ) != V_29 -> V_106 )
F_142 ( V_29 ) ;
}
}
static inline int F_159 ( struct V_108 * V_30 )
{
return F_160 ( & V_30 -> V_235 ) ;
}
static inline void F_161 ( struct V_108 * V_30 )
{
if ( F_162 ( & V_30 -> V_235 ) )
F_163 ( V_30 , V_236 ) ;
}
static void F_164 ( struct V_26 * V_29 , int V_237 , int V_178 ,
int * V_113 )
{
struct V_108 * V_30 , * V_238 ;
struct V_26 * V_239 ;
bool V_240 = false ;
int V_147 = F_165 ( V_237 ) ;
int V_241 ;
if ( F_14 ( ! V_29 -> V_108 ) ) {
unsigned int V_242 = sizeof( struct V_108 ) +
4 * V_115 *sizeof( unsigned long ) ;
V_30 = F_166 ( V_242 , V_243 | V_244 ) ;
if ( ! V_30 )
return;
F_167 ( & V_30 -> V_235 , 1 ) ;
F_168 ( & V_30 -> V_177 ) ;
V_30 -> V_109 = V_29 -> V_142 ;
V_30 -> V_120 = V_30 -> V_118 + V_114 *
V_115 ;
F_146 ( F_91 ( V_141 ) , V_30 -> V_143 ) ;
for ( V_241 = 0 ; V_241 < V_245 * V_115 ; V_241 ++ )
V_30 -> V_118 [ V_241 ] = V_29 -> V_116 [ V_241 ] ;
V_30 -> V_132 = V_29 -> V_133 ;
V_30 -> V_246 ++ ;
F_169 ( V_29 -> V_108 , V_30 ) ;
}
F_123 () ;
V_239 = F_87 ( F_113 ( V_147 ) -> V_45 ) ;
if ( ! F_109 ( V_239 , V_237 ) )
goto V_247;
V_30 = F_135 ( V_239 -> V_108 ) ;
if ( ! V_30 )
goto V_247;
V_238 = V_29 -> V_108 ;
if ( V_30 == V_238 )
goto V_247;
if ( V_238 -> V_246 > V_30 -> V_246 )
goto V_247;
if ( V_238 -> V_246 == V_30 -> V_246 && V_238 > V_30 )
goto V_247;
if ( V_239 -> V_96 == V_141 -> V_96 )
V_240 = true ;
if ( V_178 & V_248 )
V_240 = true ;
* V_113 = ! V_240 ;
if ( V_240 && ! F_159 ( V_30 ) )
goto V_247;
F_131 () ;
if ( ! V_240 )
return;
F_170 ( F_171 () ) ;
F_172 ( & V_238 -> V_177 , & V_30 -> V_177 ) ;
for ( V_241 = 0 ; V_241 < V_245 * V_115 ; V_241 ++ ) {
V_238 -> V_118 [ V_241 ] -= V_29 -> V_116 [ V_241 ] ;
V_30 -> V_118 [ V_241 ] += V_29 -> V_116 [ V_241 ] ;
}
V_238 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_132 += V_29 -> V_133 ;
V_238 -> V_246 -- ;
V_30 -> V_246 ++ ;
F_173 ( & V_238 -> V_177 ) ;
F_158 ( & V_30 -> V_177 ) ;
F_169 ( V_29 -> V_108 , V_30 ) ;
F_161 ( V_238 ) ;
return;
V_247:
F_131 () ;
return;
}
void F_174 ( struct V_26 * V_29 )
{
struct V_108 * V_30 = V_29 -> V_108 ;
void * V_116 = V_29 -> V_116 ;
unsigned long V_178 ;
int V_241 ;
if ( V_30 ) {
F_175 ( & V_30 -> V_177 , V_178 ) ;
for ( V_241 = 0 ; V_241 < V_245 * V_115 ; V_241 ++ )
V_30 -> V_118 [ V_241 ] -= V_29 -> V_116 [ V_241 ] ;
V_30 -> V_132 -= V_29 -> V_133 ;
V_30 -> V_246 -- ;
F_176 ( & V_30 -> V_177 , V_178 ) ;
F_177 ( V_29 -> V_108 , NULL ) ;
F_161 ( V_30 ) ;
}
V_29 -> V_116 = NULL ;
F_178 ( V_116 ) ;
}
void F_179 ( int V_139 , int V_249 , int V_250 , int V_178 )
{
struct V_26 * V_29 = V_141 ;
bool V_251 = V_178 & V_252 ;
int V_253 = F_91 ( V_141 ) ;
int V_203 = ! ! ( V_178 & V_254 ) ;
int V_113 ;
if ( ! V_255 )
return;
if ( ! V_29 -> V_96 )
return;
if ( F_14 ( ! V_29 -> V_116 ) ) {
int V_242 = sizeof( * V_29 -> V_116 ) *
V_256 * V_115 ;
V_29 -> V_116 = F_166 ( V_242 , V_243 | V_244 ) ;
if ( ! V_29 -> V_116 )
return;
V_29 -> V_133 = 0 ;
memset ( V_29 -> V_202 , 0 , sizeof( V_29 -> V_202 ) ) ;
}
if ( F_14 ( V_139 == ( - 1 & V_257 ) ) ) {
V_113 = 1 ;
} else {
V_113 = F_109 ( V_29 , V_139 ) ;
if ( ! V_113 && ! ( V_178 & V_258 ) )
F_164 ( V_29 , V_139 , V_178 , & V_113 ) ;
}
if ( ! V_113 && ! V_203 && V_29 -> V_108 &&
F_110 ( V_253 , V_29 -> V_108 -> V_143 ) &&
F_110 ( V_249 , V_29 -> V_108 -> V_143 ) )
V_203 = 1 ;
F_155 ( V_29 ) ;
if ( F_180 ( V_194 , V_29 -> V_193 ) )
F_142 ( V_29 ) ;
if ( V_251 )
V_29 -> V_259 += V_250 ;
V_29 -> V_116 [ F_94 ( V_232 , V_249 , V_113 ) ] += V_250 ;
V_29 -> V_116 [ F_94 ( V_234 , V_253 , V_113 ) ] += V_250 ;
V_29 -> V_202 [ V_203 ] += V_250 ;
}
static void F_181 ( struct V_26 * V_29 )
{
F_87 ( V_29 -> V_96 -> V_225 ) ++ ;
V_29 -> V_96 -> V_260 = 0 ;
}
void F_182 ( struct V_261 * V_262 )
{
unsigned long V_263 , V_264 , V_81 = V_194 ;
struct V_26 * V_29 = V_141 ;
struct V_265 * V_96 = V_29 -> V_96 ;
struct V_266 * V_267 ;
unsigned long V_268 , V_269 ;
unsigned long V_270 = 0 ;
long V_250 ;
F_20 ( V_29 != F_22 ( V_262 , struct V_26 , V_271 ) ) ;
V_262 -> V_58 = V_262 ;
if ( V_29 -> V_178 & V_179 )
return;
if ( ! V_96 -> V_205 ) {
V_96 -> V_205 = V_81 +
F_144 ( V_272 ) ;
}
V_263 = V_96 -> V_205 ;
if ( F_183 ( V_81 , V_263 ) )
return;
if ( V_29 -> V_190 == 0 ) {
V_29 -> V_204 = F_89 ( V_29 ) ;
V_29 -> V_190 = F_86 ( V_29 ) ;
}
V_264 = V_81 + F_144 ( V_29 -> V_190 ) ;
if ( F_184 ( & V_96 -> V_205 , V_263 , V_264 ) != V_263 )
return;
V_29 -> V_273 += 2 * V_274 ;
V_268 = V_96 -> V_260 ;
V_250 = V_94 ;
V_250 <<= 20 - V_95 ;
if ( ! V_250 )
return;
F_185 ( & V_96 -> V_275 ) ;
V_267 = F_186 ( V_96 , V_268 ) ;
if ( ! V_267 ) {
F_181 ( V_29 ) ;
V_268 = 0 ;
V_267 = V_96 -> V_276 ;
}
for (; V_267 ; V_267 = V_267 -> V_277 ) {
if ( ! F_187 ( V_267 ) || ! F_188 ( V_267 ) )
continue;
if ( ! V_267 -> V_278 ||
( V_267 -> V_279 && ( V_267 -> V_280 & ( V_281 | V_282 ) ) == ( V_281 ) ) )
continue;
if ( ! ( V_267 -> V_280 & ( V_281 | V_283 | V_282 ) ) )
continue;
do {
V_268 = F_68 ( V_268 , V_267 -> V_284 ) ;
V_269 = F_189 ( V_268 + ( V_250 << V_95 ) , V_285 ) ;
V_269 = F_143 ( V_269 , V_267 -> V_286 ) ;
V_270 += F_190 ( V_267 , V_268 , V_269 ) ;
if ( V_270 )
V_250 -= ( V_269 - V_268 ) >> V_95 ;
V_268 = V_269 ;
if ( V_250 <= 0 )
goto V_287;
F_191 () ;
} while ( V_269 != V_267 -> V_286 );
}
V_287:
if ( V_267 )
V_96 -> V_260 = V_268 ;
else
F_181 ( V_29 ) ;
F_192 ( & V_96 -> V_275 ) ;
}
void F_193 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_261 * V_262 = & V_45 -> V_271 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_178 & V_179 ) || V_262 -> V_58 != V_262 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_190 * V_288 ;
if ( V_81 - V_45 -> V_273 > V_73 ) {
if ( ! V_45 -> V_273 )
V_45 -> V_190 = F_86 ( V_45 ) ;
V_45 -> V_273 += V_73 ;
if ( ! F_183 ( V_194 , V_45 -> V_96 -> V_205 ) ) {
F_194 ( V_262 , F_182 ) ;
F_195 ( V_45 , V_262 , true ) ;
}
}
}
static void F_193 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_196 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_197
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_90 ( V_24 , F_18 ( V_28 ) ) ;
F_198 ( & V_28 -> V_289 , & V_24 -> V_290 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_199 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_92 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_200 ( & V_28 -> V_289 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_201 ( struct V_291 * V_33 , struct V_25 * V_25 )
{
long V_292 ;
V_292 = F_202 ( & V_33 -> V_293 ) ;
V_292 -= V_25 -> V_294 ;
V_292 += V_25 -> V_70 . V_4 ;
return V_292 ;
}
static long F_203 ( struct V_25 * V_25 , struct V_291 * V_33 )
{
long V_292 , V_70 , V_295 ;
V_292 = F_201 ( V_33 , V_25 ) ;
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
static inline long F_203 ( struct V_25 * V_25 , struct V_291 * V_33 )
{
return V_33 -> V_295 ;
}
static void F_204 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_199 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_196 ( V_25 , V_28 ) ;
}
static void F_205 ( struct V_25 * V_25 )
{
struct V_291 * V_33 ;
struct V_27 * V_28 ;
long V_295 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_206 ( V_25 ) )
return;
#ifndef F_197
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_295 ) )
return;
#endif
V_295 = F_203 ( V_25 , V_33 ) ;
F_204 ( F_24 ( V_28 ) , V_28 , V_295 ) ;
}
static inline void F_205 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_207 ( T_2 V_297 , T_2 V_298 )
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
static V_23 F_208 ( T_2 V_298 )
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
V_302 = F_207 ( V_302 , V_298 ) ;
return V_302 + V_303 [ V_298 ] ;
}
static T_10 int F_209 ( T_2 V_81 ,
struct V_306 * V_307 ,
int V_308 )
{
T_2 V_42 , V_309 ;
V_23 V_310 ;
int V_311 , V_312 = 0 ;
V_42 = V_81 - V_307 -> V_313 ;
if ( ( T_3 ) V_42 < 0 ) {
V_307 -> V_313 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_307 -> V_313 = V_81 ;
V_311 = V_307 -> V_80 % 1024 ;
if ( V_42 + V_311 >= 1024 ) {
V_312 = 1 ;
V_311 = 1024 - V_311 ;
if ( V_308 )
V_307 -> V_79 += V_311 ;
V_307 -> V_80 += V_311 ;
V_42 -= V_311 ;
V_309 = V_42 / 1024 ;
V_42 %= 1024 ;
V_307 -> V_79 = F_207 ( V_307 -> V_79 ,
V_309 + 1 ) ;
V_307 -> V_80 = F_207 ( V_307 -> V_80 ,
V_309 + 1 ) ;
V_310 = F_208 ( V_309 ) ;
if ( V_308 )
V_307 -> V_79 += V_310 ;
V_307 -> V_80 += V_310 ;
}
if ( V_308 )
V_307 -> V_79 += V_42 ;
V_307 -> V_80 += V_42 ;
return V_312 ;
}
static inline T_2 F_210 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_314 = F_211 ( & V_25 -> V_315 ) ;
V_314 -= V_28 -> V_77 . V_78 ;
if ( ! V_314 )
return 0 ;
V_28 -> V_77 . V_316 = F_207 ( V_28 -> V_77 . V_316 , V_314 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_314 ;
}
static inline void F_212 ( struct V_25 * V_25 ,
int V_317 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
long V_318 ;
V_318 = V_25 -> V_319 + V_25 -> V_320 ;
V_318 -= V_25 -> V_294 ;
if ( ! V_318 )
return;
if ( V_317 || abs ( V_318 ) > V_25 -> V_294 / 8 ) {
F_213 ( V_318 , & V_33 -> V_293 ) ;
V_25 -> V_294 += V_318 ;
}
}
static inline void F_214 ( struct V_306 * V_307 ,
struct V_25 * V_25 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
long V_302 ;
V_302 = F_215 ( ( T_2 ) V_307 -> V_79 << V_321 ,
V_307 -> V_80 + 1 ) ;
V_302 -= V_25 -> V_322 ;
if ( abs ( V_302 ) > V_25 -> V_322 / 64 ) {
F_216 ( V_302 , & V_33 -> V_323 ) ;
V_25 -> V_322 += V_302 ;
}
}
static inline void F_217 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_291 * V_33 = V_25 -> V_33 ;
int V_323 ;
T_2 V_302 ;
V_302 = V_25 -> V_294 * V_33 -> V_295 ;
V_28 -> V_77 . V_316 = F_215 ( V_302 ,
F_202 ( & V_33 -> V_293 ) + 1 ) ;
V_323 = F_218 ( & V_33 -> V_323 ) ;
if ( V_323 < V_71 ) {
V_28 -> V_77 . V_316 *= V_323 ;
V_28 -> V_77 . V_316 >>= V_321 ;
}
}
static inline void F_219 ( struct V_24 * V_24 , int V_308 )
{
F_209 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_308 ) ;
F_214 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_212 ( struct V_25 * V_25 ,
int V_317 ) {}
static inline void F_214 ( struct V_306 * V_307 ,
struct V_25 * V_25 ) {}
static inline void F_217 ( struct V_27 * V_28 ) {}
static inline void F_219 ( struct V_24 * V_24 , int V_308 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_302 ;
V_302 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_302 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_316 = F_220 ( V_302 ) ;
}
static long F_221 ( struct V_27 * V_28 )
{
long V_324 = V_28 -> V_77 . V_316 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_214 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_217 ( V_28 ) ;
}
return V_28 -> V_77 . V_316 - V_324 ;
}
static inline void F_222 ( struct V_25 * V_25 ,
long V_325 )
{
if ( F_12 ( V_325 < V_25 -> V_320 ) )
V_25 -> V_320 -= V_325 ;
else
V_25 -> V_320 = 0 ;
}
static inline void F_223 ( struct V_27 * V_28 ,
int V_326 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_327 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_224 ( V_25 ) ;
else
V_81 = F_224 ( F_25 ( V_28 ) ) ;
if ( ! F_209 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_327 = F_221 ( V_28 ) ;
if ( ! V_326 )
return;
if ( V_28 -> V_76 )
V_25 -> V_319 += V_327 ;
else
F_222 ( V_25 , - V_327 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_317 )
{
T_2 V_81 = F_224 ( V_25 ) >> 20 ;
T_2 V_314 ;
V_314 = V_81 - V_25 -> V_328 ;
if ( ! V_314 && ! V_317 )
return;
if ( F_202 ( & V_25 -> V_329 ) ) {
unsigned long V_329 ;
V_329 = F_225 ( & V_25 -> V_329 , 0 ) ;
F_222 ( V_25 , V_329 ) ;
}
if ( V_314 ) {
V_25 -> V_320 = F_207 ( V_25 -> V_320 ,
V_314 ) ;
F_226 ( V_314 , & V_25 -> V_315 ) ;
V_25 -> V_328 = V_81 ;
}
F_212 ( V_25 , V_317 ) ;
}
static inline void F_227 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_330 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_313 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_313 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_223 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_330 = 0 ;
} else {
F_210 ( V_28 ) ;
}
if ( V_330 ) {
F_222 ( V_25 , V_28 -> V_77 . V_316 ) ;
F_223 ( V_28 , 0 ) ;
}
V_25 -> V_319 += V_28 -> V_77 . V_316 ;
F_30 ( V_25 , ! V_330 ) ;
}
static inline void F_228 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_331 )
{
F_223 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_331 ) ;
V_25 -> V_319 -= V_28 -> V_77 . V_316 ;
if ( V_331 ) {
V_25 -> V_320 += V_28 -> V_77 . V_316 ;
V_28 -> V_77 . V_78 = F_211 ( & V_25 -> V_315 ) ;
}
}
void F_229 ( struct V_24 * V_332 )
{
F_219 ( V_332 , 1 ) ;
}
void F_230 ( struct V_24 * V_332 )
{
F_219 ( V_332 , 0 ) ;
}
static inline void F_223 ( struct V_27 * V_28 ,
int V_326 ) {}
static inline void F_219 ( struct V_24 * V_24 , int V_308 ) {}
static inline void F_227 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_330 ) {}
static inline void F_228 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_331 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_317 ) {}
static inline int F_231 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_232 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_79
struct V_26 * V_239 = NULL ;
if ( F_21 ( V_28 ) )
V_239 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_333 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_333 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_334 ) )
V_28 -> V_83 . V_334 = V_42 ;
V_28 -> V_83 . V_333 = 0 ;
V_28 -> V_83 . V_335 += V_42 ;
if ( V_239 ) {
F_233 ( V_239 , V_42 >> 10 , 1 ) ;
F_234 ( V_239 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_336 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_336 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_337 ) )
V_28 -> V_83 . V_337 = V_42 ;
V_28 -> V_83 . V_336 = 0 ;
V_28 -> V_83 . V_335 += V_42 ;
if ( V_239 ) {
if ( V_239 -> V_338 ) {
V_28 -> V_83 . V_339 += V_42 ;
V_28 -> V_83 . V_340 ++ ;
F_235 ( V_239 , V_42 ) ;
}
F_236 ( V_239 , V_42 ) ;
if ( F_14 ( V_341 == V_342 ) ) {
F_237 ( V_342 ,
( void * ) F_238 ( V_239 ) ,
V_42 >> 20 ) ;
}
F_233 ( V_239 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_239 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_343 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_343 < 0 )
V_343 = - V_343 ;
if ( V_343 > 3 * V_68 )
F_240 ( V_25 , V_344 ) ;
#endif
}
static void
F_241 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_345 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_345 && F_242 ( V_346 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_345 ) {
unsigned long V_347 = V_68 ;
if ( F_242 ( V_348 ) )
V_347 >>= 1 ;
V_41 -= V_347 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_243 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_178 )
{
if ( ! ( V_178 & V_349 ) || ( V_178 & V_350 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_227 ( V_25 , V_28 , V_178 & V_349 ) ;
F_196 ( V_25 , V_28 ) ;
F_205 ( V_25 ) ;
if ( V_178 & V_349 ) {
F_241 ( V_25 , V_28 , 0 ) ;
F_232 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_239 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_244 ( V_25 ) ;
}
}
static void F_245 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_246 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_247 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_351 != V_28 )
break;
V_25 -> V_351 = NULL ;
}
}
static void F_248 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_245 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_246 ( V_28 ) ;
if ( V_25 -> V_351 == V_28 )
F_247 ( V_28 ) ;
}
static void
F_249 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_178 )
{
F_65 ( V_25 ) ;
F_228 ( V_25 , V_28 , V_178 & V_352 ) ;
F_81 ( V_25 , V_28 ) ;
if ( V_178 & V_352 ) {
#ifdef F_79
if ( F_21 ( V_28 ) ) {
struct V_26 * V_239 = F_18 ( V_28 ) ;
if ( V_239 -> V_353 & V_354 )
V_28 -> V_83 . V_333 = F_76 ( F_17 ( V_25 ) ) ;
if ( V_239 -> V_353 & V_355 )
V_28 -> V_83 . V_336 = F_76 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_248 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_199 ( V_25 , V_28 ) ;
if ( ! ( V_178 & V_352 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_250 ( V_25 ) ;
F_40 ( V_25 ) ;
F_205 ( V_25 ) ;
}
static void
F_251 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_356 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_356 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_357 ;
if ( V_19 > V_356 ) {
F_252 ( F_17 ( V_25 ) ) ;
F_248 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_356 )
F_252 ( F_17 ( V_25 ) ) ;
}
static void
F_253 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_78 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
}
F_82 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_79
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_358 = F_68 ( V_28 -> V_83 . V_358 ,
V_28 -> V_85 - V_28 -> V_357 ) ;
}
#endif
V_28 -> V_357 = V_28 -> V_85 ;
}
static struct V_27 *
F_254 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_351 == V_28 ) {
struct V_27 * V_359 ;
if ( V_28 == V_45 ) {
V_359 = F_50 ( V_25 ) ;
} else {
V_359 = F_51 ( V_28 ) ;
if ( ! V_359 || ( V_45 && F_39 ( V_45 , V_359 ) ) )
V_359 = V_45 ;
}
if ( V_359 && F_255 ( V_359 , V_57 ) < 1 )
V_28 = V_359 ;
}
if ( V_25 -> V_59 && F_255 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_255 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_248 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_256 ( struct V_25 * V_25 , struct V_27 * V_360 )
{
if ( V_360 -> V_76 )
F_65 ( V_25 ) ;
F_257 ( V_25 ) ;
F_239 ( V_25 , V_360 ) ;
if ( V_360 -> V_76 ) {
F_75 ( V_25 , V_360 ) ;
F_44 ( V_25 , V_360 ) ;
F_223 ( V_360 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_258 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_361 )
{
F_65 ( V_25 ) ;
F_223 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_205 ( V_25 ) ;
#ifdef F_259
if ( V_361 ) {
F_252 ( F_17 ( V_25 ) ) ;
return;
}
if ( ! F_242 ( V_362 ) &&
F_260 ( & F_17 ( V_25 ) -> V_363 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_251 ( V_25 , V_45 ) ;
}
static inline bool F_261 ( void )
{
return F_262 ( & V_364 ) ;
}
void F_263 ( void )
{
F_264 ( & V_364 ) ;
}
void F_265 ( void )
{
F_266 ( & V_364 ) ;
}
static bool F_261 ( void )
{
return true ;
}
void F_263 ( void ) {}
void F_265 ( void ) {}
static inline T_2 F_267 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_268 ( void )
{
return ( T_2 ) V_365 * V_366 ;
}
void F_269 ( struct V_367 * V_368 )
{
T_2 V_81 ;
if ( V_368 -> V_369 == V_370 )
return;
V_81 = F_270 ( F_271 () ) ;
V_368 -> V_209 = V_368 -> V_369 ;
V_368 -> V_371 = V_81 + F_272 ( V_368 -> V_73 ) ;
}
static inline struct V_367 * F_273 ( struct V_291 * V_33 )
{
return & V_33 -> V_367 ;
}
static inline T_2 F_224 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_372 ) )
return V_25 -> V_373 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_374 ;
}
static int F_274 ( struct V_25 * V_25 )
{
struct V_291 * V_33 = V_25 -> V_33 ;
struct V_367 * V_368 = F_273 ( V_33 ) ;
T_2 V_375 = 0 , V_376 , V_377 ;
V_376 = F_268 () - V_25 -> V_378 ;
F_275 ( & V_368 -> V_177 ) ;
if ( V_368 -> V_369 == V_370 )
V_375 = V_376 ;
else {
if ( ! V_368 -> V_379 ) {
F_269 ( V_368 ) ;
F_276 ( V_368 , false ) ;
}
if ( V_368 -> V_209 > 0 ) {
V_375 = F_143 ( V_368 -> V_209 , V_376 ) ;
V_368 -> V_209 -= V_375 ;
V_368 -> V_380 = 0 ;
}
}
V_377 = V_368 -> V_371 ;
F_277 ( & V_368 -> V_177 ) ;
V_25 -> V_378 += V_375 ;
if ( ( T_3 ) ( V_377 - V_25 -> V_371 ) > 0 )
V_25 -> V_371 = V_377 ;
return V_25 -> V_378 > 0 ;
}
static void F_278 ( struct V_25 * V_25 )
{
struct V_367 * V_368 = F_273 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_76 ( F_17 ( V_25 ) ) - V_25 -> V_371 ) < 0 ) )
return;
if ( V_25 -> V_378 < 0 )
return;
if ( V_25 -> V_371 != V_368 -> V_371 ) {
V_25 -> V_371 += V_274 ;
} else {
V_25 -> V_378 = 0 ;
}
}
static void F_279 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_378 -= V_19 ;
F_278 ( V_25 ) ;
if ( F_12 ( V_25 -> V_378 > 0 ) )
return;
if ( ! F_274 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_252 ( F_17 ( V_25 ) ) ;
}
static T_10
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_261 () || ! V_25 -> V_381 )
return;
F_279 ( V_25 , V_19 ) ;
}
static inline int F_280 ( struct V_25 * V_25 )
{
return F_261 () && V_25 -> V_382 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return F_261 () && V_25 -> V_372 ;
}
static inline int F_281 ( struct V_291 * V_33 ,
int V_173 , int V_383 )
{
struct V_25 * V_384 , * V_385 ;
V_384 = V_33 -> V_25 [ V_173 ] ;
V_385 = V_33 -> V_25 [ V_383 ] ;
return F_206 ( V_384 ) ||
F_206 ( V_385 ) ;
}
static int F_282 ( struct V_291 * V_33 , void * V_386 )
{
struct V_24 * V_24 = V_386 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_372 -- ;
#ifdef F_197
if ( ! V_25 -> V_372 ) {
V_25 -> V_374 += F_66 ( V_24 ) -
V_25 -> V_373 ;
}
#endif
return 0 ;
}
static int F_283 ( struct V_291 * V_33 , void * V_386 )
{
struct V_24 * V_24 = V_386 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_372 )
V_25 -> V_373 = F_66 ( V_24 ) ;
V_25 -> V_372 ++ ;
return 0 ;
}
static void F_284 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_367 * V_368 = F_273 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_387 , V_388 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_123 () ;
F_285 ( V_25 -> V_33 , F_283 , V_389 , ( void * ) V_24 ) ;
F_131 () ;
V_387 = V_25 -> V_390 ;
F_61 (se) {
struct V_25 * V_391 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_388 )
F_249 ( V_391 , V_28 , V_352 ) ;
V_391 -> V_390 -= V_387 ;
if ( V_391 -> V_70 . V_4 )
V_388 = 0 ;
}
if ( ! V_28 )
F_286 ( V_24 , V_387 ) ;
V_25 -> V_382 = 1 ;
V_25 -> V_392 = F_76 ( V_24 ) ;
F_275 ( & V_368 -> V_177 ) ;
F_28 ( & V_25 -> V_393 , & V_368 -> V_394 ) ;
if ( ! V_368 -> V_379 )
F_276 ( V_368 , false ) ;
F_277 ( & V_368 -> V_177 ) ;
}
void F_287 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_367 * V_368 = F_273 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_395 = 1 ;
long V_387 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_382 = 0 ;
F_288 ( V_24 ) ;
F_275 ( & V_368 -> V_177 ) ;
V_368 -> V_396 += F_76 ( V_24 ) - V_25 -> V_392 ;
F_32 ( & V_25 -> V_393 ) ;
F_277 ( & V_368 -> V_177 ) ;
F_285 ( V_25 -> V_33 , V_389 , F_282 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_387 = V_25 -> V_390 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_395 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_395 )
F_243 ( V_25 , V_28 , V_349 ) ;
V_25 -> V_390 += V_387 ;
if ( F_280 ( V_25 ) )
break;
}
if ( ! V_28 )
F_289 ( V_24 , V_387 ) ;
if ( V_24 -> V_45 == V_24 -> V_380 && V_24 -> V_40 . V_72 )
F_252 ( V_24 ) ;
}
static T_2 F_290 ( struct V_367 * V_368 ,
T_2 V_397 , T_2 V_377 )
{
struct V_25 * V_25 ;
T_2 V_209 ;
T_2 V_398 = V_397 ;
F_123 () ;
F_291 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_275 ( & V_24 -> V_177 ) ;
if ( ! F_280 ( V_25 ) )
goto V_58;
V_209 = - V_25 -> V_378 + 1 ;
if ( V_209 > V_397 )
V_209 = V_397 ;
V_397 -= V_209 ;
V_25 -> V_378 += V_209 ;
V_25 -> V_371 = V_377 ;
if ( V_25 -> V_378 > 0 )
F_287 ( V_25 ) ;
V_58:
F_277 ( & V_24 -> V_177 ) ;
if ( ! V_397 )
break;
}
F_131 () ;
return V_398 - V_397 ;
}
static int F_292 ( struct V_367 * V_368 , int V_399 )
{
T_2 V_209 , V_371 ;
int V_382 ;
if ( V_368 -> V_369 == V_370 )
goto V_400;
V_382 = ! F_293 ( & V_368 -> V_394 ) ;
V_368 -> V_401 += V_399 ;
if ( V_368 -> V_380 && ! V_382 )
goto V_400;
V_368 -> V_379 = 1 ;
F_269 ( V_368 ) ;
if ( ! V_382 ) {
V_368 -> V_380 = 1 ;
return 0 ;
}
V_368 -> V_402 += V_399 ;
V_371 = V_368 -> V_371 ;
while ( V_382 && V_368 -> V_209 > 0 ) {
V_209 = V_368 -> V_209 ;
F_277 ( & V_368 -> V_177 ) ;
V_209 = F_290 ( V_368 , V_209 ,
V_371 ) ;
F_275 ( & V_368 -> V_177 ) ;
V_382 = ! F_293 ( & V_368 -> V_394 ) ;
V_368 -> V_209 -= F_143 ( V_209 , V_368 -> V_209 ) ;
}
V_368 -> V_380 = 0 ;
return 0 ;
V_400:
V_368 -> V_379 = 0 ;
return 1 ;
}
static int F_294 ( struct V_367 * V_368 , T_2 V_403 )
{
struct V_404 * V_405 = & V_368 -> V_406 ;
T_2 V_397 ;
if ( F_295 ( V_405 ) )
return 1 ;
V_397 = F_272 ( F_296 ( V_405 ) ) ;
if ( V_397 < V_403 )
return 1 ;
return 0 ;
}
static void F_297 ( struct V_367 * V_368 )
{
T_2 V_407 = V_408 + V_409 ;
if ( F_294 ( V_368 , V_407 ) )
return;
F_298 ( & V_368 -> V_410 ,
F_299 ( V_408 ) ) ;
}
static void F_300 ( struct V_25 * V_25 )
{
struct V_367 * V_368 = F_273 ( V_25 -> V_33 ) ;
T_3 V_411 = V_25 -> V_378 - V_412 ;
if ( V_411 <= 0 )
return;
F_275 ( & V_368 -> V_177 ) ;
if ( V_368 -> V_369 != V_370 &&
V_25 -> V_371 == V_368 -> V_371 ) {
V_368 -> V_209 += V_411 ;
if ( V_368 -> V_209 > F_268 () &&
! F_293 ( & V_368 -> V_394 ) )
F_297 ( V_368 ) ;
}
F_277 ( & V_368 -> V_177 ) ;
V_25 -> V_378 -= V_411 ;
}
static T_10 void F_250 ( struct V_25 * V_25 )
{
if ( ! F_261 () )
return;
if ( ! V_25 -> V_381 || V_25 -> V_72 )
return;
F_300 ( V_25 ) ;
}
static void F_301 ( struct V_367 * V_368 )
{
T_2 V_209 = 0 , V_75 = F_268 () ;
T_2 V_377 ;
F_275 ( & V_368 -> V_177 ) ;
if ( F_294 ( V_368 , V_409 ) ) {
F_277 ( & V_368 -> V_177 ) ;
return;
}
if ( V_368 -> V_369 != V_370 && V_368 -> V_209 > V_75 )
V_209 = V_368 -> V_209 ;
V_377 = V_368 -> V_371 ;
F_277 ( & V_368 -> V_177 ) ;
if ( ! V_209 )
return;
V_209 = F_290 ( V_368 , V_209 , V_377 ) ;
F_275 ( & V_368 -> V_177 ) ;
if ( V_377 == V_368 -> V_371 )
V_368 -> V_209 -= F_143 ( V_209 , V_368 -> V_209 ) ;
F_277 ( & V_368 -> V_177 ) ;
}
static void F_244 ( struct V_25 * V_25 )
{
if ( ! F_261 () )
return;
if ( ! V_25 -> V_381 || V_25 -> V_45 )
return;
if ( F_280 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_378 <= 0 )
F_284 ( V_25 ) ;
}
static bool F_257 ( struct V_25 * V_25 )
{
if ( ! F_261 () )
return false ;
if ( F_12 ( ! V_25 -> V_381 || V_25 -> V_378 > 0 ) )
return false ;
if ( F_280 ( V_25 ) )
return true ;
F_284 ( V_25 ) ;
return true ;
}
static enum V_413 F_302 ( struct V_404 * V_414 )
{
struct V_367 * V_368 =
F_22 ( V_414 , struct V_367 , V_410 ) ;
F_301 ( V_368 ) ;
return V_415 ;
}
static enum V_413 F_303 ( struct V_404 * V_414 )
{
struct V_367 * V_368 =
F_22 ( V_414 , struct V_367 , V_406 ) ;
T_11 V_81 ;
int V_399 ;
int V_380 = 0 ;
F_275 ( & V_368 -> V_177 ) ;
for (; ; ) {
V_81 = F_304 ( V_414 ) ;
V_399 = F_305 ( V_414 , V_81 , V_368 -> V_73 ) ;
if ( ! V_399 )
break;
V_380 = F_292 ( V_368 , V_399 ) ;
}
F_277 ( & V_368 -> V_177 ) ;
return V_380 ? V_415 : V_416 ;
}
void F_306 ( struct V_367 * V_368 )
{
F_307 ( & V_368 -> V_177 ) ;
V_368 -> V_209 = 0 ;
V_368 -> V_369 = V_370 ;
V_368 -> V_73 = F_299 ( F_267 () ) ;
F_308 ( & V_368 -> V_394 ) ;
F_309 ( & V_368 -> V_406 , V_417 , V_418 ) ;
V_368 -> V_406 . V_419 = F_303 ;
F_309 ( & V_368 -> V_410 , V_417 , V_418 ) ;
V_368 -> V_410 . V_419 = F_302 ;
}
static void F_310 ( struct V_25 * V_25 )
{
V_25 -> V_381 = 0 ;
F_308 ( & V_25 -> V_393 ) ;
}
void F_276 ( struct V_367 * V_368 , bool V_420 )
{
while ( F_14 ( F_260 ( & V_368 -> V_406 ) ) &&
F_311 ( & V_368 -> V_406 ) < 0 ) {
F_277 ( & V_368 -> V_177 ) ;
F_312 () ;
F_275 ( & V_368 -> V_177 ) ;
if ( ! V_420 && V_368 -> V_379 )
return;
}
V_368 -> V_379 = 1 ;
F_298 ( & V_368 -> V_406 , V_368 -> V_73 ) ;
}
static void F_313 ( struct V_367 * V_368 )
{
if ( ! V_368 -> V_394 . V_58 )
return;
F_314 ( & V_368 -> V_406 ) ;
F_314 ( & V_368 -> V_410 ) ;
}
static void T_12 F_315 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_316 (rq, cfs_rq) {
struct V_367 * V_368 = & V_25 -> V_33 -> V_367 ;
F_275 ( & V_368 -> V_177 ) ;
V_25 -> V_381 = V_368 -> V_369 != V_370 ;
F_277 ( & V_368 -> V_177 ) ;
}
}
static void T_12 F_317 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_316 (rq, cfs_rq) {
if ( ! V_25 -> V_381 )
continue;
V_25 -> V_378 = 1 ;
V_25 -> V_381 = 0 ;
if ( F_280 ( V_25 ) )
F_287 ( V_25 ) ;
}
}
static inline T_2 F_224 ( struct V_25 * V_25 )
{
return F_66 ( F_17 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_257 ( struct V_25 * V_25 ) { return false ; }
static void F_244 ( struct V_25 * V_25 ) {}
static T_10 void F_250 ( struct V_25 * V_25 ) {}
static inline int F_280 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_281 ( struct V_291 * V_33 ,
int V_173 , int V_383 )
{
return 0 ;
}
void F_306 ( struct V_367 * V_368 ) {}
static void F_310 ( struct V_25 * V_25 ) {}
static inline struct V_367 * F_273 ( struct V_291 * V_33 )
{
return NULL ;
}
static inline void F_313 ( struct V_367 * V_368 ) {}
static inline void F_315 ( struct V_24 * V_24 ) {}
static inline void F_317 ( struct V_24 * V_24 ) {}
static void F_318 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_319 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_421 = V_28 -> V_85 - V_28 -> V_357 ;
T_3 V_42 = V_75 - V_421 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_252 ( V_24 ) ;
return;
}
F_320 ( V_24 , V_42 ) ;
}
}
static void F_321 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_322 ( V_24 ) || V_45 -> V_422 != & V_423 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
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
F_323 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_178 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_243 ( V_25 , V_28 , V_178 ) ;
if ( F_280 ( V_25 ) )
break;
V_25 -> V_390 ++ ;
V_178 = V_349 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_390 ++ ;
if ( F_280 ( V_25 ) )
break;
F_205 ( V_25 ) ;
F_223 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_219 ( V_24 , V_24 -> V_72 ) ;
F_289 ( V_24 , 1 ) ;
}
F_321 ( V_24 ) ;
}
static void F_324 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_178 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_424 = V_178 & V_352 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_249 ( V_25 , V_28 , V_178 ) ;
if ( F_280 ( V_25 ) )
break;
V_25 -> V_390 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_424 && F_34 ( V_28 ) )
F_325 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_178 |= V_352 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_390 -- ;
if ( F_280 ( V_25 ) )
break;
F_205 ( V_25 ) ;
F_223 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_286 ( V_24 , 1 ) ;
F_219 ( V_24 , 1 ) ;
}
F_321 ( V_24 ) ;
}
static unsigned long F_114 ( const int V_147 )
{
return F_113 ( V_147 ) -> V_40 . V_319 ;
}
static unsigned long F_326 ( int V_147 , int type )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_425 = F_114 ( V_147 ) ;
if ( type == 0 || ! F_242 ( V_426 ) )
return V_425 ;
return F_143 ( V_24 -> V_427 [ type - 1 ] , V_425 ) ;
}
static unsigned long F_327 ( int V_147 , int type )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_425 = F_114 ( V_147 ) ;
if ( type == 0 || ! F_242 ( V_426 ) )
return V_425 ;
return F_68 ( V_24 -> V_427 [ type - 1 ] , V_425 ) ;
}
static unsigned long F_115 ( int V_147 )
{
return F_113 ( V_147 ) -> V_428 ;
}
static unsigned long F_328 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_72 = F_87 ( V_24 -> V_40 . V_390 ) ;
unsigned long V_293 = V_24 -> V_40 . V_319 ;
if ( V_72 )
return V_293 / V_72 ;
return 0 ;
}
static void F_329 ( struct V_26 * V_29 )
{
if ( F_180 ( V_194 , V_141 -> V_429 + V_192 ) ) {
V_141 -> V_430 >>= 1 ;
V_141 -> V_429 = V_194 ;
}
if ( V_141 -> V_431 != V_29 ) {
V_141 -> V_431 = V_29 ;
V_141 -> V_430 ++ ;
}
}
static void F_330 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_331 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_329 ( V_29 ) ;
}
static long F_332 ( struct V_291 * V_33 , int V_147 , long V_432 , long V_433 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
if ( ! V_33 -> V_34 )
return V_432 ;
F_61 (se) {
long V_7 , V_434 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_434 = V_433 + F_201 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_432 ;
if ( V_434 > 0 && V_7 < V_434 )
V_432 = ( V_7 * ( long ) V_33 -> V_295 ) / V_434 ;
else
V_432 = V_33 -> V_295 ;
if ( V_432 < V_296 )
V_432 = V_296 ;
V_432 -= V_28 -> V_70 . V_4 ;
V_433 = 0 ;
}
return V_432 ;
}
static long F_332 ( struct V_291 * V_33 , int V_147 , long V_432 , long V_433 )
{
return V_432 ;
}
static int F_333 ( struct V_26 * V_29 )
{
int V_9 = F_334 ( V_435 ) ;
if ( V_29 -> V_430 > V_9 ) {
if ( V_141 -> V_430 > ( V_9 * V_29 -> V_430 ) )
return 1 ;
}
return 0 ;
}
static int F_335 ( struct V_183 * V_184 , struct V_26 * V_29 , int V_436 )
{
T_3 V_437 , V_70 ;
T_3 V_438 , V_439 ;
int V_440 , V_441 , V_442 ;
struct V_291 * V_33 ;
unsigned long V_4 ;
int V_443 ;
if ( F_333 ( V_29 ) )
return 0 ;
V_440 = V_184 -> V_444 ;
V_441 = F_271 () ;
V_442 = F_134 ( V_29 ) ;
V_70 = F_326 ( V_442 , V_440 ) ;
V_437 = F_327 ( V_441 , V_440 ) ;
if ( V_436 ) {
V_33 = V_291 ( V_141 ) ;
V_4 = V_141 -> V_28 . V_70 . V_4 ;
V_437 += F_332 ( V_33 , V_441 , - V_4 , - V_4 ) ;
V_70 += F_332 ( V_33 , V_442 , 0 , - V_4 ) ;
}
V_33 = V_291 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
V_438 = 100 ;
V_438 *= F_115 ( V_442 ) ;
V_439 = 100 + ( V_184 -> V_169 - 100 ) / 2 ;
V_439 *= F_115 ( V_441 ) ;
if ( V_437 > 0 ) {
V_438 *= V_437 +
F_332 ( V_33 , V_441 , V_4 , V_4 ) ;
V_439 *= V_70 + F_332 ( V_33 , V_442 , 0 , V_4 ) ;
}
V_443 = V_438 <= V_439 ;
F_240 ( V_29 , V_28 . V_83 . V_445 ) ;
if ( ! V_443 )
return 0 ;
F_240 ( V_184 , V_446 ) ;
F_240 ( V_29 , V_28 . V_83 . V_447 ) ;
return 1 ;
}
static struct V_448 *
F_336 ( struct V_183 * V_184 , struct V_26 * V_29 ,
int V_441 , int V_449 )
{
struct V_448 * V_450 = NULL , * V_119 = V_184 -> V_451 ;
unsigned long V_452 = V_453 , V_437 = 0 ;
int V_454 = V_184 -> V_455 ;
int V_456 = 100 + ( V_184 -> V_169 - 100 ) / 2 ;
if ( V_449 & V_457 )
V_454 = V_184 -> V_444 ;
do {
unsigned long V_70 , V_458 ;
int V_459 ;
int V_241 ;
if ( ! F_337 ( F_338 ( V_119 ) ,
F_128 ( V_29 ) ) )
continue;
V_459 = F_127 ( V_441 ,
F_338 ( V_119 ) ) ;
V_458 = 0 ;
F_112 (i, sched_group_cpus(group)) {
if ( V_459 )
V_70 = F_326 ( V_241 , V_454 ) ;
else
V_70 = F_327 ( V_241 , V_454 ) ;
V_458 += V_70 ;
}
V_458 = ( V_458 * V_150 ) / V_119 -> V_460 -> V_148 ;
if ( V_459 ) {
V_437 = V_458 ;
} else if ( V_458 < V_452 ) {
V_452 = V_458 ;
V_450 = V_119 ;
}
} while ( V_119 = V_119 -> V_58 , V_119 != V_184 -> V_451 );
if ( ! V_450 || 100 * V_437 < V_456 * V_452 )
return NULL ;
return V_450 ;
}
static int
F_339 ( struct V_448 * V_119 , struct V_26 * V_29 , int V_441 )
{
unsigned long V_70 , V_452 = V_453 ;
unsigned int V_461 = V_462 ;
T_2 V_463 = 0 ;
int V_464 = V_441 ;
int V_465 = - 1 ;
int V_241 ;
F_340 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_341 ( V_241 ) ) {
struct V_24 * V_24 = F_113 ( V_241 ) ;
struct V_466 * V_380 = F_342 ( V_24 ) ;
if ( V_380 && V_380 -> V_467 < V_461 ) {
V_461 = V_380 -> V_467 ;
V_463 = V_24 -> V_468 ;
V_465 = V_241 ;
} else if ( ( ! V_380 || V_380 -> V_467 == V_461 ) &&
V_24 -> V_468 > V_463 ) {
V_463 = V_24 -> V_468 ;
V_465 = V_241 ;
}
} else if ( V_465 == - 1 ) {
V_70 = F_114 ( V_241 ) ;
if ( V_70 < V_452 || ( V_70 == V_452 && V_241 == V_441 ) ) {
V_452 = V_70 ;
V_464 = V_241 ;
}
}
}
return V_465 != - 1 ? V_465 : V_464 ;
}
static int F_130 ( struct V_26 * V_29 , int V_469 )
{
struct V_183 * V_184 ;
struct V_448 * V_470 ;
int V_241 = F_134 ( V_29 ) ;
if ( F_341 ( V_469 ) )
return V_469 ;
if ( V_241 != V_469 && F_343 ( V_241 , V_469 ) && F_341 ( V_241 ) )
return V_241 ;
V_184 = F_135 ( F_136 ( V_471 , V_469 ) ) ;
F_344 (sd) {
V_470 = V_184 -> V_451 ;
do {
if ( ! F_337 ( F_338 ( V_470 ) ,
F_128 ( V_29 ) ) )
goto V_58;
F_112 (i, sched_group_cpus(sg)) {
if ( V_241 == V_469 || ! F_341 ( V_241 ) )
goto V_58;
}
V_469 = F_345 ( F_338 ( V_470 ) ,
F_128 ( V_29 ) ) ;
goto V_472;
V_58:
V_470 = V_470 -> V_58 ;
} while ( V_470 != V_184 -> V_451 );
}
V_472:
return V_469 ;
}
static int
F_346 ( struct V_26 * V_29 , int V_442 , int V_449 , int V_473 )
{
struct V_183 * V_474 , * V_475 = NULL , * V_184 = NULL ;
int V_147 = F_271 () ;
int V_476 = V_147 ;
int V_477 = 0 ;
int V_436 = V_473 & V_478 ;
if ( V_449 & V_457 )
V_477 = F_127 ( V_147 , F_128 ( V_29 ) ) ;
F_123 () ;
F_347 (cpu, tmp) {
if ( ! ( V_474 -> V_178 & V_479 ) )
continue;
if ( V_477 && ( V_474 -> V_178 & V_480 ) &&
F_127 ( V_442 , F_348 ( V_474 ) ) ) {
V_475 = V_474 ;
break;
}
if ( V_474 -> V_178 & V_449 )
V_184 = V_474 ;
}
if ( V_475 && V_147 != V_442 && F_335 ( V_475 , V_29 , V_436 ) )
V_442 = V_147 ;
if ( V_449 & V_457 ) {
V_476 = F_130 ( V_29 , V_442 ) ;
goto V_180;
}
while ( V_184 ) {
struct V_448 * V_119 ;
int V_4 ;
if ( ! ( V_184 -> V_178 & V_449 ) ) {
V_184 = V_184 -> V_481 ;
continue;
}
V_119 = F_336 ( V_184 , V_29 , V_147 , V_449 ) ;
if ( ! V_119 ) {
V_184 = V_184 -> V_481 ;
continue;
}
V_476 = F_339 ( V_119 , V_29 , V_147 ) ;
if ( V_476 == - 1 || V_476 == V_147 ) {
V_184 = V_184 -> V_481 ;
continue;
}
V_147 = V_476 ;
V_4 = V_184 -> V_482 ;
V_184 = NULL ;
F_347 (cpu, tmp) {
if ( V_4 <= V_474 -> V_482 )
break;
if ( V_474 -> V_178 & V_449 )
V_184 = V_474 ;
}
}
V_180:
F_131 () ;
return V_476 ;
}
static void
F_349 ( struct V_26 * V_29 , int V_483 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_210 ( V_28 ) ;
F_213 ( V_28 -> V_77 . V_316 ,
& V_25 -> V_329 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_350 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_484 = V_485 ;
return F_58 ( V_484 , V_28 ) ;
}
static int
F_255 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_484 , V_486 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_486 <= 0 )
return - 1 ;
V_484 = F_350 ( V_45 , V_28 ) ;
if ( V_486 > V_484 )
return 1 ;
return 0 ;
}
static void F_351 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_487 == V_488 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_325 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_487 == V_488 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_352 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_351 = V_28 ;
}
static void F_353 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_473 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_489 = V_25 -> V_72 >= V_67 ;
int V_490 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_206 ( F_24 ( V_36 ) ) ) )
return;
if ( F_242 ( V_491 ) && V_489 && ! ( V_473 & V_492 ) ) {
F_325 ( V_36 ) ;
V_490 = 1 ;
}
if ( F_354 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_487 == V_488 ) &&
F_12 ( V_29 -> V_487 != V_488 ) )
goto V_493;
if ( F_14 ( V_29 -> V_487 != V_494 ) || ! F_242 ( V_495 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_170 ( ! V_36 ) ;
if ( F_255 ( V_28 , V_36 ) == 1 ) {
if ( ! V_490 )
F_325 ( V_36 ) ;
goto V_493;
}
return;
V_493:
F_252 ( V_24 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_380 ) )
return;
if ( F_242 ( V_496 ) && V_489 && F_21 ( V_28 ) )
F_351 ( V_28 ) ;
}
static struct V_26 *
F_355 ( struct V_24 * V_24 , struct V_26 * V_360 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_497 ;
V_498:
#ifdef F_356
if ( ! V_25 -> V_72 )
goto V_380;
if ( V_360 -> V_422 != & V_423 )
goto V_499;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_257 ( V_25 ) ) )
goto V_499;
V_28 = F_254 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_360 != V_29 ) {
struct V_27 * V_36 = & V_360 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_256 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_253 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_256 ( V_25 , V_36 ) ;
F_253 ( V_25 , V_28 ) ;
}
if ( F_322 ( V_24 ) )
F_318 ( V_24 , V_29 ) ;
return V_29 ;
V_499:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_380;
F_357 ( V_24 , V_360 ) ;
do {
V_28 = F_254 ( V_25 , NULL ) ;
F_253 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_322 ( V_24 ) )
F_318 ( V_24 , V_29 ) ;
return V_29 ;
V_380:
V_497 = F_231 ( V_24 ) ;
if ( V_497 < 0 )
return V_500 ;
if ( V_497 > 0 )
goto V_498;
return NULL ;
}
static void F_358 ( struct V_24 * V_24 , struct V_26 * V_360 )
{
struct V_27 * V_28 = & V_360 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_256 ( V_25 , V_28 ) ;
}
}
static void F_359 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_248 ( V_25 , V_28 ) ;
if ( V_45 -> V_487 != V_501 ) {
F_288 ( V_24 ) ;
F_65 ( V_25 ) ;
V_24 -> V_502 = 1 ;
}
F_352 ( V_28 ) ;
}
static bool F_360 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_493 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_206 ( F_24 ( V_28 ) ) )
return false ;
F_325 ( V_28 ) ;
F_359 ( V_24 ) ;
return true ;
}
static int F_361 ( struct V_26 * V_29 , struct V_503 * V_154 )
{
T_3 V_42 ;
F_362 ( & V_154 -> V_172 -> V_177 ) ;
if ( V_29 -> V_422 != & V_423 )
return 0 ;
if ( F_14 ( V_29 -> V_487 == V_488 ) )
return 0 ;
if ( F_242 ( V_504 ) && V_154 -> V_174 -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_505 == - 1 )
return 1 ;
if ( V_505 == 0 )
return 0 ;
V_42 = F_66 ( V_154 -> V_172 ) - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_505 ;
}
static bool F_363 ( struct V_26 * V_29 , struct V_503 * V_154 )
{
struct V_108 * V_108 = F_135 ( V_29 -> V_108 ) ;
int V_135 , V_138 ;
if ( ! F_242 ( V_506 ) || ! V_29 -> V_116 ||
! ( V_154 -> V_184 -> V_178 & V_507 ) ) {
return false ;
}
V_135 = F_104 ( V_154 -> V_173 ) ;
V_138 = F_104 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_108 ) {
if ( F_110 ( V_135 , V_108 -> V_143 ) )
return false ;
if ( F_110 ( V_138 , V_108 -> V_143 ) )
return true ;
return F_96 ( V_29 , V_138 ) > F_96 ( V_29 , V_135 ) ;
}
if ( V_138 == V_29 -> V_106 )
return true ;
return F_95 ( V_29 , V_138 ) > F_95 ( V_29 , V_135 ) ;
}
static bool F_364 ( struct V_26 * V_29 , struct V_503 * V_154 )
{
struct V_108 * V_108 = F_135 ( V_29 -> V_108 ) ;
int V_135 , V_138 ;
if ( ! F_242 ( V_508 ) || ! F_242 ( V_509 ) )
return false ;
if ( ! V_29 -> V_116 || ! ( V_154 -> V_184 -> V_178 & V_507 ) )
return false ;
V_135 = F_104 ( V_154 -> V_173 ) ;
V_138 = F_104 ( V_154 -> V_136 ) ;
if ( V_135 == V_138 )
return false ;
if ( V_108 ) {
if ( F_110 ( V_138 , V_108 -> V_143 ) )
return false ;
if ( F_110 ( V_135 , V_108 -> V_143 ) )
return true ;
return F_96 ( V_29 , V_138 ) < F_96 ( V_29 , V_135 ) ;
}
if ( V_135 == V_29 -> V_106 )
return true ;
return F_95 ( V_29 , V_138 ) < F_95 ( V_29 , V_135 ) ;
}
static inline bool F_363 ( struct V_26 * V_29 ,
struct V_503 * V_154 )
{
return false ;
}
static inline bool F_364 ( struct V_26 * V_29 ,
struct V_503 * V_154 )
{
return false ;
}
static
int F_365 ( struct V_26 * V_29 , struct V_503 * V_154 )
{
int V_510 = 0 ;
F_362 ( & V_154 -> V_172 -> V_177 ) ;
if ( F_281 ( V_291 ( V_29 ) , V_154 -> V_173 , V_154 -> V_136 ) )
return 0 ;
if ( ! F_127 ( V_154 -> V_136 , F_128 ( V_29 ) ) ) {
int V_147 ;
F_240 ( V_29 , V_28 . V_83 . V_511 ) ;
V_154 -> V_178 |= V_512 ;
if ( ! V_154 -> V_513 || ( V_154 -> V_178 & V_514 ) )
return 0 ;
F_340 (cpu, env->dst_grpmask, env->cpus) {
if ( F_127 ( V_147 , F_128 ( V_29 ) ) ) {
V_154 -> V_178 |= V_514 ;
V_154 -> V_515 = V_147 ;
break;
}
}
return 0 ;
}
V_154 -> V_178 &= ~ V_516 ;
if ( F_366 ( V_154 -> V_172 , V_29 ) ) {
F_240 ( V_29 , V_28 . V_83 . V_517 ) ;
return 0 ;
}
V_510 = F_361 ( V_29 , V_154 ) ;
if ( ! V_510 )
V_510 = F_364 ( V_29 , V_154 ) ;
if ( F_363 ( V_29 , V_154 ) || ! V_510 ||
V_154 -> V_184 -> V_518 > V_154 -> V_184 -> V_519 ) {
if ( V_510 ) {
F_240 ( V_154 -> V_184 , V_520 [ V_154 -> V_380 ] ) ;
F_240 ( V_29 , V_28 . V_83 . V_521 ) ;
}
return 1 ;
}
F_240 ( V_29 , V_28 . V_83 . V_522 ) ;
return 0 ;
}
static void F_367 ( struct V_26 * V_29 , struct V_503 * V_154 )
{
F_362 ( & V_154 -> V_172 -> V_177 ) ;
F_368 ( V_154 -> V_172 , V_29 , 0 ) ;
V_29 -> V_76 = V_523 ;
F_369 ( V_29 , V_154 -> V_136 ) ;
}
static struct V_26 * F_370 ( struct V_503 * V_154 )
{
struct V_26 * V_29 , * V_298 ;
F_362 ( & V_154 -> V_172 -> V_177 ) ;
F_371 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_365 ( V_29 , V_154 ) )
continue;
F_367 ( V_29 , V_154 ) ;
F_240 ( V_154 -> V_184 , V_524 [ V_154 -> V_380 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_372 ( struct V_503 * V_154 )
{
struct V_525 * V_526 = & V_154 -> V_172 -> V_290 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_527 = 0 ;
F_362 ( & V_154 -> V_172 -> V_177 ) ;
if ( V_154 -> V_456 <= 0 )
return 0 ;
while ( ! F_293 ( V_526 ) ) {
V_29 = F_373 ( V_526 , struct V_26 , V_28 . V_289 ) ;
V_154 -> V_528 ++ ;
if ( V_154 -> V_528 > V_154 -> V_529 )
break;
if ( V_154 -> V_528 > V_154 -> V_530 ) {
V_154 -> V_530 += V_531 ;
V_154 -> V_178 |= V_532 ;
break;
}
if ( ! F_365 ( V_29 , V_154 ) )
goto V_58;
V_70 = F_129 ( V_29 ) ;
if ( F_242 ( V_533 ) && V_70 < 16 && ! V_154 -> V_184 -> V_518 )
goto V_58;
if ( ( V_70 / 2 ) > V_154 -> V_456 )
goto V_58;
F_367 ( V_29 , V_154 ) ;
F_198 ( & V_29 -> V_28 . V_289 , & V_154 -> V_526 ) ;
V_527 ++ ;
V_154 -> V_456 -= V_70 ;
#ifdef F_374
if ( V_154 -> V_380 == V_534 )
break;
#endif
if ( V_154 -> V_456 <= 0 )
break;
continue;
V_58:
F_375 ( & V_29 -> V_28 . V_289 , V_526 ) ;
}
F_69 ( V_154 -> V_184 , V_524 [ V_154 -> V_380 ] , V_527 ) ;
return V_527 ;
}
static void F_376 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_362 ( & V_24 -> V_177 ) ;
F_170 ( F_36 ( V_29 ) != V_24 ) ;
V_29 -> V_76 = V_535 ;
F_377 ( V_24 , V_29 , 0 ) ;
F_378 ( V_24 , V_29 , 0 ) ;
}
static void F_379 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_275 ( & V_24 -> V_177 ) ;
F_376 ( V_24 , V_29 ) ;
F_277 ( & V_24 -> V_177 ) ;
}
static void F_380 ( struct V_503 * V_154 )
{
struct V_525 * V_526 = & V_154 -> V_526 ;
struct V_26 * V_29 ;
F_275 ( & V_154 -> V_174 -> V_177 ) ;
while ( ! F_293 ( V_526 ) ) {
V_29 = F_373 ( V_526 , struct V_26 , V_28 . V_289 ) ;
F_200 ( & V_29 -> V_28 . V_289 ) ;
F_376 ( V_154 -> V_174 , V_29 ) ;
}
F_277 ( & V_154 -> V_174 -> V_177 ) ;
}
static void F_381 ( struct V_291 * V_33 , int V_147 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_147 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_147 ] ;
if ( F_206 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_223 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_219 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_382 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
struct V_25 * V_25 ;
unsigned long V_178 ;
F_383 ( & V_24 -> V_177 , V_178 ) ;
F_288 ( V_24 ) ;
F_316 (rq, cfs_rq) {
F_381 ( V_25 -> V_33 , V_24 -> V_147 ) ;
}
F_384 ( & V_24 -> V_177 , V_178 ) ;
}
static void F_385 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_194 ;
unsigned long V_70 ;
if ( V_25 -> V_536 == V_81 )
return;
V_25 -> V_537 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_537 = V_28 ;
if ( V_25 -> V_536 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_538 = V_25 -> V_319 ;
V_25 -> V_536 = V_81 ;
}
while ( ( V_28 = V_25 -> V_537 ) != NULL ) {
V_70 = V_25 -> V_538 ;
V_70 = F_386 ( V_70 * V_28 -> V_77 . V_316 ,
V_25 -> V_319 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_538 = V_70 ;
V_25 -> V_536 = V_81 ;
}
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_385 ( V_25 ) ;
return F_386 ( V_29 -> V_28 . V_77 . V_316 * V_25 -> V_538 ,
V_25 -> V_319 + 1 ) ;
}
static inline void F_382 ( int V_147 )
{
}
static unsigned long F_129 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_316 ;
}
static inline void F_387 ( struct V_539 * V_540 )
{
* V_540 = (struct V_539 ) {
. V_541 = NULL ,
. V_203 = NULL ,
. V_542 = 0UL ,
. V_543 = 0UL ,
. V_544 = {
. V_458 = 0UL ,
. V_545 = 0 ,
. V_546 = V_547 ,
} ,
} ;
}
static inline int F_388 ( struct V_183 * V_184 ,
enum V_548 V_380 )
{
int V_454 ;
switch ( V_380 ) {
case V_549 :
V_454 = V_184 -> V_550 ;
break;
case V_534 :
V_454 = V_184 -> V_551 ;
break;
default:
V_454 = V_184 -> V_552 ;
break;
}
return V_454 ;
}
static unsigned long F_389 ( struct V_183 * V_184 , int V_147 )
{
return V_150 ;
}
unsigned long __weak F_390 ( struct V_183 * V_184 , int V_147 )
{
return F_389 ( V_184 , V_147 ) ;
}
static unsigned long F_391 ( struct V_183 * V_184 , int V_147 )
{
if ( ( V_184 -> V_178 & V_553 ) && ( V_184 -> V_482 > 1 ) )
return V_184 -> V_554 / V_184 -> V_482 ;
return V_150 ;
}
unsigned long __weak F_392 ( struct V_183 * V_184 , int V_147 )
{
return F_391 ( V_184 , V_147 ) ;
}
static unsigned long F_393 ( int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
T_2 V_425 , V_555 , V_556 , V_77 ;
T_3 V_42 ;
V_556 = F_87 ( V_24 -> V_556 ) ;
V_77 = F_87 ( V_24 -> V_557 ) ;
V_42 = F_76 ( V_24 ) - V_556 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_425 = F_394 () + V_42 ;
if ( F_14 ( V_425 < V_77 ) ) {
V_555 = 0 ;
} else {
V_555 = V_425 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_425 < V_150 ) )
V_425 = V_150 ;
V_425 >>= V_558 ;
return F_215 ( V_555 , V_425 ) ;
}
static void F_395 ( struct V_183 * V_184 , int V_147 )
{
unsigned long V_148 = V_150 ;
struct V_448 * V_559 = V_184 -> V_451 ;
if ( F_242 ( V_560 ) )
V_148 *= F_392 ( V_184 , V_147 ) ;
else
V_148 *= F_391 ( V_184 , V_147 ) ;
V_148 >>= V_558 ;
V_559 -> V_460 -> V_561 = V_148 ;
if ( F_242 ( V_560 ) )
V_148 *= F_390 ( V_184 , V_147 ) ;
else
V_148 *= F_389 ( V_184 , V_147 ) ;
V_148 >>= V_558 ;
V_148 *= F_393 ( V_147 ) ;
V_148 >>= V_558 ;
if ( ! V_148 )
V_148 = 1 ;
F_113 ( V_147 ) -> V_428 = V_148 ;
V_559 -> V_460 -> V_148 = V_148 ;
}
void F_396 ( struct V_183 * V_184 , int V_147 )
{
struct V_183 * V_481 = V_184 -> V_481 ;
struct V_448 * V_119 , * V_559 = V_184 -> V_451 ;
unsigned long V_148 , V_561 ;
unsigned long V_191 ;
V_191 = F_144 ( V_184 -> V_562 ) ;
V_191 = F_149 ( V_191 , 1UL , V_563 ) ;
V_559 -> V_460 -> V_564 = V_194 + V_191 ;
if ( ! V_481 ) {
F_395 ( V_184 , V_147 ) ;
return;
}
V_561 = V_148 = 0 ;
if ( V_481 -> V_178 & V_565 ) {
F_112 (cpu, sched_group_cpus(sdg)) {
struct V_566 * V_460 ;
struct V_24 * V_24 = F_113 ( V_147 ) ;
if ( F_14 ( ! V_24 -> V_184 ) ) {
V_561 += F_115 ( V_147 ) ;
V_148 += F_115 ( V_147 ) ;
continue;
}
V_460 = V_24 -> V_184 -> V_451 -> V_460 ;
V_561 += V_460 -> V_561 ;
V_148 += V_460 -> V_148 ;
}
} else {
V_119 = V_481 -> V_451 ;
do {
V_561 += V_119 -> V_460 -> V_561 ;
V_148 += V_119 -> V_460 -> V_148 ;
V_119 = V_119 -> V_58 ;
} while ( V_119 != V_481 -> V_451 );
}
V_559 -> V_460 -> V_561 = V_561 ;
V_559 -> V_460 -> V_148 = V_148 ;
}
static inline int
F_397 ( struct V_183 * V_184 , struct V_448 * V_119 )
{
if ( ! ( V_184 -> V_178 & V_553 ) )
return 0 ;
if ( V_119 -> V_460 -> V_148 * 32 > V_119 -> V_460 -> V_561 * 29 )
return 1 ;
return 0 ;
}
static inline int F_398 ( struct V_448 * V_119 )
{
return V_119 -> V_460 -> V_456 ;
}
static inline int F_399 ( struct V_503 * V_154 , struct V_448 * V_119 )
{
unsigned int V_567 , V_146 , V_8 ;
unsigned int V_148 , V_561 ;
V_148 = V_119 -> V_460 -> V_148 ;
V_561 = V_119 -> V_460 -> V_561 ;
V_8 = V_119 -> F_102 ;
V_146 = F_56 ( V_150 * V_8 , V_561 ) ;
V_567 = V_8 / V_146 ;
V_567 = F_5 ( unsigned ,
V_567 , F_116 ( V_148 , V_150 ) ) ;
if ( ! V_567 )
V_567 = F_397 ( V_154 -> V_184 , V_119 ) ;
return V_567 ;
}
static enum V_546
F_400 ( struct V_448 * V_119 , struct V_568 * V_569 )
{
if ( V_569 -> V_545 > V_569 -> V_570 )
return V_571 ;
if ( F_398 ( V_119 ) )
return V_572 ;
return V_547 ;
}
static inline void F_401 ( struct V_503 * V_154 ,
struct V_448 * V_119 , int V_454 ,
int V_459 , struct V_568 * V_569 ,
bool * V_573 )
{
unsigned long V_70 ;
int V_241 ;
memset ( V_569 , 0 , sizeof( * V_569 ) ) ;
F_340 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_113 ( V_241 ) ;
if ( V_459 )
V_70 = F_327 ( V_241 , V_454 ) ;
else
V_70 = F_326 ( V_241 , V_454 ) ;
V_569 -> V_574 += V_70 ;
V_569 -> V_545 += V_24 -> V_40 . V_390 ;
if ( V_24 -> V_72 > 1 )
* V_573 = true ;
#ifdef F_402
V_569 -> V_105 += V_24 -> V_105 ;
V_569 -> V_107 += V_24 -> V_107 ;
#endif
V_569 -> V_575 += F_114 ( V_241 ) ;
if ( F_341 ( V_241 ) )
V_569 -> V_576 ++ ;
}
V_569 -> V_577 = V_119 -> V_460 -> V_148 ;
V_569 -> V_458 = ( V_569 -> V_574 * V_150 ) / V_569 -> V_577 ;
if ( V_569 -> V_545 )
V_569 -> V_578 = V_569 -> V_575 / V_569 -> V_545 ;
V_569 -> F_102 = V_119 -> F_102 ;
V_569 -> V_570 = F_399 ( V_154 , V_119 ) ;
V_569 -> V_546 = F_400 ( V_119 , V_569 ) ;
if ( V_569 -> V_570 > V_569 -> V_545 )
V_569 -> V_579 = 1 ;
}
static bool F_403 ( struct V_503 * V_154 ,
struct V_539 * V_540 ,
struct V_448 * V_470 ,
struct V_568 * V_569 )
{
struct V_568 * V_541 = & V_540 -> V_544 ;
if ( V_569 -> V_546 > V_541 -> V_546 )
return true ;
if ( V_569 -> V_546 < V_541 -> V_546 )
return false ;
if ( V_569 -> V_458 <= V_541 -> V_458 )
return false ;
if ( ! ( V_154 -> V_184 -> V_178 & V_580 ) )
return true ;
if ( V_569 -> V_545 && V_154 -> V_136 < F_404 ( V_470 ) ) {
if ( ! V_540 -> V_541 )
return true ;
if ( F_404 ( V_540 -> V_541 ) > F_404 ( V_470 ) )
return true ;
}
return false ;
}
static inline enum V_581 F_405 ( struct V_568 * V_569 )
{
if ( V_569 -> V_545 > V_569 -> V_105 )
return V_582 ;
if ( V_569 -> V_545 > V_569 -> V_107 )
return V_201 ;
return V_583 ;
}
static inline enum V_581 F_406 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_105 )
return V_582 ;
if ( V_24 -> V_72 > V_24 -> V_107 )
return V_201 ;
return V_583 ;
}
static inline enum V_581 F_405 ( struct V_568 * V_569 )
{
return V_583 ;
}
static inline enum V_581 F_406 ( struct V_24 * V_24 )
{
return V_582 ;
}
static inline void F_407 ( struct V_503 * V_154 , struct V_539 * V_540 )
{
struct V_183 * V_481 = V_154 -> V_184 -> V_481 ;
struct V_448 * V_470 = V_154 -> V_184 -> V_451 ;
struct V_568 V_584 ;
int V_454 , V_585 = 0 ;
bool V_573 = false ;
if ( V_481 && V_481 -> V_178 & V_586 )
V_585 = 1 ;
V_454 = F_388 ( V_154 -> V_184 , V_154 -> V_380 ) ;
do {
struct V_568 * V_569 = & V_584 ;
int V_459 ;
V_459 = F_127 ( V_154 -> V_136 , F_338 ( V_470 ) ) ;
if ( V_459 ) {
V_540 -> V_203 = V_470 ;
V_569 = & V_540 -> V_587 ;
if ( V_154 -> V_380 != V_534 ||
F_408 ( V_194 , V_470 -> V_460 -> V_564 ) )
F_396 ( V_154 -> V_184 , V_154 -> V_136 ) ;
}
F_401 ( V_154 , V_470 , V_454 , V_459 , V_569 ,
& V_573 ) ;
if ( V_459 )
goto V_588;
if ( V_585 && V_540 -> V_203 &&
V_540 -> V_587 . V_579 ) {
V_569 -> V_570 = F_143 ( V_569 -> V_570 , 1U ) ;
V_569 -> V_546 = F_400 ( V_470 , V_569 ) ;
}
if ( F_403 ( V_154 , V_540 , V_470 , V_569 ) ) {
V_540 -> V_541 = V_470 ;
V_540 -> V_544 = * V_569 ;
}
V_588:
V_540 -> V_542 += V_569 -> V_574 ;
V_540 -> V_543 += V_569 -> V_577 ;
V_470 = V_470 -> V_58 ;
} while ( V_470 != V_154 -> V_184 -> V_451 );
if ( V_154 -> V_184 -> V_178 & V_507 )
V_154 -> V_581 = F_405 ( & V_540 -> V_544 ) ;
if ( ! V_154 -> V_184 -> V_34 ) {
if ( V_154 -> V_174 -> V_589 -> V_573 != V_573 )
V_154 -> V_174 -> V_589 -> V_573 = V_573 ;
}
}
static int F_409 ( struct V_503 * V_154 , struct V_539 * V_540 )
{
int V_590 ;
if ( ! ( V_154 -> V_184 -> V_178 & V_580 ) )
return 0 ;
if ( ! V_540 -> V_541 )
return 0 ;
V_590 = F_404 ( V_540 -> V_541 ) ;
if ( V_154 -> V_136 > V_590 )
return 0 ;
V_154 -> V_456 = F_116 (
V_540 -> V_544 . V_458 * V_540 -> V_544 . V_577 ,
V_150 ) ;
return 1 ;
}
static inline
void F_410 ( struct V_503 * V_154 , struct V_539 * V_540 )
{
unsigned long V_474 , V_591 = 0 , V_592 = 0 ;
unsigned int V_593 = 2 ;
unsigned long V_594 ;
struct V_568 * V_203 , * V_541 ;
V_203 = & V_540 -> V_587 ;
V_541 = & V_540 -> V_544 ;
if ( ! V_203 -> V_545 )
V_203 -> V_578 = F_328 ( V_154 -> V_136 ) ;
else if ( V_541 -> V_578 > V_203 -> V_578 )
V_593 = 1 ;
V_594 =
( V_541 -> V_578 * V_150 ) /
V_541 -> V_577 ;
if ( V_541 -> V_458 + V_594 >=
V_203 -> V_458 + ( V_594 * V_593 ) ) {
V_154 -> V_456 = V_541 -> V_578 ;
return;
}
V_591 += V_541 -> V_577 *
F_143 ( V_541 -> V_578 , V_541 -> V_458 ) ;
V_591 += V_203 -> V_577 *
F_143 ( V_203 -> V_578 , V_203 -> V_458 ) ;
V_591 /= V_150 ;
if ( V_541 -> V_458 > V_594 ) {
V_592 += V_541 -> V_577 *
F_143 ( V_541 -> V_578 ,
V_541 -> V_458 - V_594 ) ;
}
if ( V_541 -> V_458 * V_541 -> V_577 <
V_541 -> V_578 * V_150 ) {
V_474 = ( V_541 -> V_458 * V_541 -> V_577 ) /
V_203 -> V_577 ;
} else {
V_474 = ( V_541 -> V_578 * V_150 ) /
V_203 -> V_577 ;
}
V_592 += V_203 -> V_577 *
F_143 ( V_203 -> V_578 , V_203 -> V_458 + V_474 ) ;
V_592 /= V_150 ;
if ( V_592 > V_591 )
V_154 -> V_456 = V_541 -> V_578 ;
}
static inline void F_411 ( struct V_503 * V_154 , struct V_539 * V_540 )
{
unsigned long V_595 , V_596 = ~ 0UL ;
struct V_568 * V_203 , * V_541 ;
V_203 = & V_540 -> V_587 ;
V_541 = & V_540 -> V_544 ;
if ( V_541 -> V_546 == V_572 ) {
V_541 -> V_578 =
F_143 ( V_541 -> V_578 , V_540 -> V_458 ) ;
}
if ( V_541 -> V_458 <= V_540 -> V_458 ||
V_203 -> V_458 >= V_540 -> V_458 ) {
V_154 -> V_456 = 0 ;
return F_410 ( V_154 , V_540 ) ;
}
if ( V_541 -> V_546 == V_571 &&
V_203 -> V_546 == V_571 ) {
V_596 =
( V_541 -> V_545 - V_541 -> V_570 ) ;
V_596 *= ( V_597 * V_150 ) ;
V_596 /= V_541 -> V_577 ;
}
V_595 = F_143 ( V_541 -> V_458 - V_540 -> V_458 , V_596 ) ;
V_154 -> V_456 = F_143 (
V_595 * V_541 -> V_577 ,
( V_540 -> V_458 - V_203 -> V_458 ) * V_203 -> V_577
) / V_150 ;
if ( V_154 -> V_456 < V_541 -> V_578 )
return F_410 ( V_154 , V_540 ) ;
}
static struct V_448 * F_412 ( struct V_503 * V_154 )
{
struct V_568 * V_203 , * V_541 ;
struct V_539 V_540 ;
F_387 ( & V_540 ) ;
F_407 ( V_154 , & V_540 ) ;
V_203 = & V_540 . V_587 ;
V_541 = & V_540 . V_544 ;
if ( ( V_154 -> V_380 == V_598 || V_154 -> V_380 == V_534 ) &&
F_409 ( V_154 , & V_540 ) )
return V_540 . V_541 ;
if ( ! V_540 . V_541 || V_541 -> V_545 == 0 )
goto V_599;
V_540 . V_458 = ( V_150 * V_540 . V_542 )
/ V_540 . V_543 ;
if ( V_541 -> V_546 == V_572 )
goto V_600;
if ( V_154 -> V_380 == V_534 && V_203 -> V_579 &&
! V_541 -> V_579 )
goto V_600;
if ( V_203 -> V_458 >= V_541 -> V_458 )
goto V_599;
if ( V_203 -> V_458 >= V_540 . V_458 )
goto V_599;
if ( V_154 -> V_380 == V_598 ) {
if ( ( V_541 -> V_546 != V_571 ) &&
( V_203 -> V_576 <= ( V_541 -> V_576 + 1 ) ) )
goto V_599;
} else {
if ( 100 * V_541 -> V_458 <=
V_154 -> V_184 -> V_169 * V_203 -> V_458 )
goto V_599;
}
V_600:
F_411 ( V_154 , & V_540 ) ;
return V_540 . V_541 ;
V_599:
V_154 -> V_456 = 0 ;
return NULL ;
}
static struct V_24 * F_413 ( struct V_503 * V_154 ,
struct V_448 * V_119 )
{
struct V_24 * V_541 = NULL , * V_24 ;
unsigned long V_601 = 0 , V_602 = 1 ;
int V_241 ;
F_340 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_148 , V_567 , V_432 ;
enum V_581 V_603 ;
V_24 = F_113 ( V_241 ) ;
V_603 = F_406 ( V_24 ) ;
if ( V_603 > V_154 -> V_581 )
continue;
V_148 = F_115 ( V_241 ) ;
V_567 = F_116 ( V_148 , V_150 ) ;
if ( ! V_567 )
V_567 = F_397 ( V_154 -> V_184 , V_119 ) ;
V_432 = F_114 ( V_241 ) ;
if ( V_567 && V_24 -> V_72 == 1 && V_432 > V_154 -> V_456 )
continue;
if ( V_432 * V_602 > V_601 * V_148 ) {
V_601 = V_432 ;
V_602 = V_148 ;
V_541 = V_24 ;
}
}
return V_541 ;
}
static int F_414 ( struct V_503 * V_154 )
{
struct V_183 * V_184 = V_154 -> V_184 ;
if ( V_154 -> V_380 == V_534 ) {
if ( ( V_184 -> V_178 & V_580 ) && V_154 -> V_173 > V_154 -> V_136 )
return 1 ;
}
return F_14 ( V_184 -> V_518 > V_184 -> V_519 + 2 ) ;
}
static int F_415 ( struct V_503 * V_154 )
{
struct V_448 * V_470 = V_154 -> V_184 -> V_451 ;
struct V_604 * V_605 , * V_606 ;
int V_147 , V_607 = - 1 ;
if ( V_154 -> V_380 == V_534 )
return 1 ;
V_605 = F_338 ( V_470 ) ;
V_606 = F_416 ( V_470 ) ;
F_340 (cpu, sg_cpus, env->cpus) {
if ( ! F_127 ( V_147 , V_606 ) || ! F_341 ( V_147 ) )
continue;
V_607 = V_147 ;
break;
}
if ( V_607 == - 1 )
V_607 = F_417 ( V_470 ) ;
return V_607 == V_154 -> V_136 ;
}
static int F_418 ( int V_441 , struct V_24 * V_332 ,
struct V_183 * V_184 , enum V_548 V_380 ,
int * V_608 )
{
int V_609 , V_610 , V_611 = 0 ;
struct V_183 * V_612 = V_184 -> V_34 ;
struct V_448 * V_119 ;
struct V_24 * V_541 ;
unsigned long V_178 ;
struct V_604 * V_8 = F_419 ( V_613 ) ;
struct V_503 V_154 = {
. V_184 = V_184 ,
. V_136 = V_441 ,
. V_174 = V_332 ,
. V_513 = F_338 ( V_184 -> V_451 ) ,
. V_380 = V_380 ,
. V_530 = V_531 ,
. V_8 = V_8 ,
. V_581 = V_583 ,
. V_526 = F_420 ( V_154 . V_526 ) ,
} ;
if ( V_380 == V_534 )
V_154 . V_513 = NULL ;
F_421 ( V_8 , V_614 ) ;
F_240 ( V_184 , V_615 [ V_380 ] ) ;
V_616:
if ( ! F_415 ( & V_154 ) ) {
* V_608 = 0 ;
goto V_599;
}
V_119 = F_412 ( & V_154 ) ;
if ( ! V_119 ) {
F_240 ( V_184 , V_617 [ V_380 ] ) ;
goto V_599;
}
V_541 = F_413 ( & V_154 , V_119 ) ;
if ( ! V_541 ) {
F_240 ( V_184 , V_618 [ V_380 ] ) ;
goto V_599;
}
F_170 ( V_541 == V_154 . V_174 ) ;
F_69 ( V_184 , V_619 [ V_380 ] , V_154 . V_456 ) ;
V_609 = 0 ;
if ( V_541 -> V_72 > 1 ) {
V_154 . V_178 |= V_516 ;
V_154 . V_173 = V_541 -> V_147 ;
V_154 . V_172 = V_541 ;
V_154 . V_529 = F_143 ( V_620 , V_541 -> V_72 ) ;
V_621:
F_383 ( & V_541 -> V_177 , V_178 ) ;
V_610 = F_372 ( & V_154 ) ;
F_277 ( & V_541 -> V_177 ) ;
if ( V_610 ) {
F_380 ( & V_154 ) ;
V_609 += V_610 ;
}
F_422 ( V_178 ) ;
if ( V_154 . V_178 & V_532 ) {
V_154 . V_178 &= ~ V_532 ;
goto V_621;
}
if ( ( V_154 . V_178 & V_514 ) && V_154 . V_456 > 0 ) {
F_423 ( V_154 . V_136 , V_154 . V_8 ) ;
V_154 . V_174 = F_113 ( V_154 . V_515 ) ;
V_154 . V_136 = V_154 . V_515 ;
V_154 . V_178 &= ~ V_514 ;
V_154 . V_528 = 0 ;
V_154 . V_530 = V_531 ;
goto V_621;
}
if ( V_612 ) {
int * V_622 = & V_612 -> V_451 -> V_460 -> V_456 ;
if ( ( V_154 . V_178 & V_512 ) && V_154 . V_456 > 0 )
* V_622 = 1 ;
}
if ( F_14 ( V_154 . V_178 & V_516 ) ) {
F_423 ( F_27 ( V_541 ) , V_8 ) ;
if ( ! F_424 ( V_8 ) ) {
V_154 . V_528 = 0 ;
V_154 . V_530 = V_531 ;
goto V_616;
}
goto V_623;
}
}
if ( ! V_609 ) {
F_240 ( V_184 , V_624 [ V_380 ] ) ;
if ( V_380 != V_534 )
V_184 -> V_518 ++ ;
if ( F_414 ( & V_154 ) ) {
F_383 ( & V_541 -> V_177 , V_178 ) ;
if ( ! F_127 ( V_441 ,
F_128 ( V_541 -> V_45 ) ) ) {
F_384 ( & V_541 -> V_177 ,
V_178 ) ;
V_154 . V_178 |= V_516 ;
goto V_625;
}
if ( ! V_541 -> V_611 ) {
V_541 -> V_611 = 1 ;
V_541 -> V_626 = V_441 ;
V_611 = 1 ;
}
F_384 ( & V_541 -> V_177 , V_178 ) ;
if ( V_611 ) {
F_425 ( F_27 ( V_541 ) ,
V_627 , V_541 ,
& V_541 -> V_628 ) ;
}
V_184 -> V_518 = V_184 -> V_519 + 1 ;
}
} else
V_184 -> V_518 = 0 ;
if ( F_12 ( ! V_611 ) ) {
V_184 -> V_562 = V_184 -> V_629 ;
} else {
if ( V_184 -> V_562 < V_184 -> V_630 )
V_184 -> V_562 *= 2 ;
}
goto V_287;
V_599:
if ( V_612 ) {
int * V_622 = & V_612 -> V_451 -> V_460 -> V_456 ;
if ( * V_622 )
* V_622 = 0 ;
}
V_623:
F_240 ( V_184 , V_631 [ V_380 ] ) ;
V_184 -> V_518 = 0 ;
V_625:
if ( ( ( V_154 . V_178 & V_516 ) &&
V_184 -> V_562 < V_632 ) ||
( V_184 -> V_562 < V_184 -> V_630 ) )
V_184 -> V_562 *= 2 ;
V_609 = 0 ;
V_287:
return V_609 ;
}
static inline unsigned long
F_426 ( struct V_183 * V_184 , int V_633 )
{
unsigned long V_191 = V_184 -> V_562 ;
if ( V_633 )
V_191 *= V_184 -> V_634 ;
V_191 = F_144 ( V_191 ) ;
V_191 = F_149 ( V_191 , 1UL , V_563 ) ;
return V_191 ;
}
static inline void
F_427 ( struct V_183 * V_184 , int V_633 , unsigned long * V_635 )
{
unsigned long V_191 , V_58 ;
V_191 = F_426 ( V_184 , V_633 ) ;
V_58 = V_184 -> V_636 + V_191 ;
if ( F_180 ( * V_635 , V_58 ) )
* V_635 = V_58 ;
}
static int F_231 ( struct V_24 * V_332 )
{
unsigned long V_635 = V_194 + V_192 ;
int V_441 = V_332 -> V_147 ;
struct V_183 * V_184 ;
int V_637 = 0 ;
T_2 V_638 = 0 ;
F_229 ( V_332 ) ;
V_332 -> V_468 = F_76 ( V_332 ) ;
if ( V_332 -> V_639 < V_505 ||
! V_332 -> V_589 -> V_573 ) {
F_123 () ;
V_184 = F_428 ( V_332 -> V_184 ) ;
if ( V_184 )
F_427 ( V_184 , 0 , & V_635 ) ;
F_131 () ;
goto V_287;
}
F_277 ( & V_332 -> V_177 ) ;
F_382 ( V_441 ) ;
F_123 () ;
F_347 (this_cpu, sd) {
int V_608 = 1 ;
T_2 V_640 , V_641 ;
if ( ! ( V_184 -> V_178 & V_479 ) )
continue;
if ( V_332 -> V_639 < V_638 + V_184 -> V_642 ) {
F_427 ( V_184 , 0 , & V_635 ) ;
break;
}
if ( V_184 -> V_178 & V_643 ) {
V_640 = F_270 ( V_441 ) ;
V_637 = F_418 ( V_441 , V_332 ,
V_184 , V_534 ,
& V_608 ) ;
V_641 = F_270 ( V_441 ) - V_640 ;
if ( V_641 > V_184 -> V_642 )
V_184 -> V_642 = V_641 ;
V_638 += V_641 ;
}
F_427 ( V_184 , 0 , & V_635 ) ;
if ( V_637 || V_332 -> V_72 > 0 )
break;
}
F_131 () ;
F_275 ( & V_332 -> V_177 ) ;
if ( V_638 > V_332 -> V_644 )
V_332 -> V_644 = V_638 ;
if ( V_332 -> V_40 . V_390 && ! V_637 )
V_637 = 1 ;
V_287:
if ( F_180 ( V_332 -> V_635 , V_635 ) )
V_332 -> V_635 = V_635 ;
if ( V_332 -> V_72 != V_332 -> V_40 . V_390 )
V_637 = - 1 ;
if ( V_637 ) {
F_230 ( V_332 ) ;
V_332 -> V_468 = 0 ;
}
return V_637 ;
}
static int V_627 ( void * V_386 )
{
struct V_24 * V_645 = V_386 ;
int V_590 = F_27 ( V_645 ) ;
int V_646 = V_645 -> V_626 ;
struct V_24 * V_647 = F_113 ( V_646 ) ;
struct V_183 * V_184 ;
struct V_26 * V_29 = NULL ;
F_124 ( & V_645 -> V_177 ) ;
if ( F_14 ( V_590 != F_271 () ||
! V_645 -> V_611 ) )
goto V_648;
if ( V_645 -> V_72 <= 1 )
goto V_648;
F_170 ( V_645 == V_647 ) ;
F_123 () ;
F_347 (target_cpu, sd) {
if ( ( V_184 -> V_178 & V_479 ) &&
F_127 ( V_590 , F_348 ( V_184 ) ) )
break;
}
if ( F_12 ( V_184 ) ) {
struct V_503 V_154 = {
. V_184 = V_184 ,
. V_136 = V_646 ,
. V_174 = V_647 ,
. V_173 = V_645 -> V_147 ,
. V_172 = V_645 ,
. V_380 = V_598 ,
} ;
F_240 ( V_184 , V_649 ) ;
V_29 = F_370 ( & V_154 ) ;
if ( V_29 )
F_240 ( V_184 , V_650 ) ;
else
F_240 ( V_184 , V_651 ) ;
}
F_131 () ;
V_648:
V_645 -> V_611 = 0 ;
F_277 ( & V_645 -> V_177 ) ;
if ( V_29 )
F_379 ( V_647 , V_29 ) ;
F_429 () ;
return 0 ;
}
static inline int F_430 ( struct V_24 * V_24 )
{
return F_14 ( ! F_431 ( V_24 -> V_184 ) ) ;
}
static inline int F_432 ( void )
{
int V_652 = F_433 ( V_653 . V_654 ) ;
if ( V_652 < V_655 && F_341 ( V_652 ) )
return V_652 ;
return V_655 ;
}
static void F_434 ( void )
{
int V_656 ;
V_653 . V_635 ++ ;
V_656 = F_432 () ;
if ( V_656 >= V_655 )
return;
if ( F_435 ( V_657 , F_436 ( V_656 ) ) )
return;
F_437 ( V_656 ) ;
return;
}
static inline void F_438 ( int V_147 )
{
if ( F_14 ( F_439 ( V_658 , F_436 ( V_147 ) ) ) ) {
if ( F_12 ( F_127 ( V_147 , V_653 . V_654 ) ) ) {
F_423 ( V_147 , V_653 . V_654 ) ;
F_440 ( & V_653 . V_659 ) ;
}
F_441 ( V_658 , F_436 ( V_147 ) ) ;
}
}
static inline void F_442 ( void )
{
struct V_183 * V_184 ;
int V_147 = F_271 () ;
F_123 () ;
V_184 = F_135 ( F_136 ( V_660 , V_147 ) ) ;
if ( ! V_184 || ! V_184 -> V_661 )
goto V_180;
V_184 -> V_661 = 0 ;
F_443 ( & V_184 -> V_451 -> V_460 -> V_662 ) ;
V_180:
F_131 () ;
}
void F_444 ( void )
{
struct V_183 * V_184 ;
int V_147 = F_271 () ;
F_123 () ;
V_184 = F_135 ( F_136 ( V_660 , V_147 ) ) ;
if ( ! V_184 || V_184 -> V_661 )
goto V_180;
V_184 -> V_661 = 1 ;
F_440 ( & V_184 -> V_451 -> V_460 -> V_662 ) ;
V_180:
F_131 () ;
}
void F_445 ( int V_147 )
{
if ( ! F_446 ( V_147 ) )
return;
if ( F_439 ( V_658 , F_436 ( V_147 ) ) )
return;
if ( F_430 ( F_113 ( V_147 ) ) )
return;
F_447 ( V_147 , V_653 . V_654 ) ;
F_443 ( & V_653 . V_659 ) ;
F_448 ( V_658 , F_436 ( V_147 ) ) ;
}
static int F_449 ( struct V_663 * V_664 ,
unsigned long V_665 , void * V_666 )
{
switch ( V_665 & ~ V_667 ) {
case V_668 :
F_438 ( F_271 () ) ;
return V_669 ;
default:
return V_670 ;
}
}
void F_450 ( void )
{
V_563 = V_192 * F_6 () / 10 ;
}
static void F_451 ( struct V_24 * V_24 , enum V_548 V_380 )
{
int V_608 = 1 ;
int V_147 = V_24 -> V_147 ;
unsigned long V_191 ;
struct V_183 * V_184 ;
unsigned long V_635 = V_194 + 60 * V_192 ;
int F_427 = 0 ;
int V_671 , V_672 = 0 ;
T_2 V_673 = 0 ;
F_382 ( V_147 ) ;
F_123 () ;
F_347 (cpu, sd) {
if ( F_180 ( V_194 , V_184 -> V_674 ) ) {
V_184 -> V_642 =
( V_184 -> V_642 * 253 ) / 256 ;
V_184 -> V_674 = V_194 + V_192 ;
V_672 = 1 ;
}
V_673 += V_184 -> V_642 ;
if ( ! ( V_184 -> V_178 & V_479 ) )
continue;
if ( ! V_608 ) {
if ( V_672 )
continue;
break;
}
V_191 = F_426 ( V_184 , V_380 != V_598 ) ;
V_671 = V_184 -> V_178 & V_675 ;
if ( V_671 ) {
if ( ! F_452 ( & V_676 ) )
goto V_287;
}
if ( F_408 ( V_194 , V_184 -> V_636 + V_191 ) ) {
if ( F_418 ( V_147 , V_24 , V_184 , V_380 , & V_608 ) ) {
V_380 = F_341 ( V_147 ) ? V_598 : V_549 ;
}
V_184 -> V_636 = V_194 ;
V_191 = F_426 ( V_184 , V_380 != V_598 ) ;
}
if ( V_671 )
F_173 ( & V_676 ) ;
V_287:
if ( F_180 ( V_635 , V_184 -> V_636 + V_191 ) ) {
V_635 = V_184 -> V_636 + V_191 ;
F_427 = 1 ;
}
}
if ( V_672 ) {
V_24 -> V_644 =
F_68 ( ( T_2 ) V_505 , V_673 ) ;
}
F_131 () ;
if ( F_12 ( F_427 ) )
V_24 -> V_635 = V_635 ;
}
static void F_453 ( struct V_24 * V_332 , enum V_548 V_380 )
{
int V_441 = V_332 -> V_147 ;
struct V_24 * V_24 ;
int V_607 ;
if ( V_380 != V_598 ||
! F_439 ( V_657 , F_436 ( V_441 ) ) )
goto V_269;
F_112 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_607 == V_441 || ! F_341 ( V_607 ) )
continue;
if ( F_454 () )
break;
V_24 = F_113 ( V_607 ) ;
if ( F_408 ( V_194 , V_24 -> V_635 ) ) {
F_124 ( & V_24 -> V_177 ) ;
F_288 ( V_24 ) ;
F_455 ( V_24 ) ;
F_126 ( & V_24 -> V_177 ) ;
F_451 ( V_24 , V_598 ) ;
}
if ( F_180 ( V_332 -> V_635 , V_24 -> V_635 ) )
V_332 -> V_635 = V_24 -> V_635 ;
}
V_653 . V_635 = V_332 -> V_635 ;
V_269:
F_441 ( V_657 , F_436 ( V_441 ) ) ;
}
static inline int F_456 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_194 ;
struct V_183 * V_184 ;
struct V_566 * V_460 ;
int V_677 , V_147 = V_24 -> V_147 ;
if ( F_14 ( V_24 -> F_231 ) )
return 0 ;
F_442 () ;
F_438 ( V_147 ) ;
if ( F_12 ( ! F_218 ( & V_653 . V_659 ) ) )
return 0 ;
if ( F_183 ( V_81 , V_653 . V_635 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_678;
F_123 () ;
V_184 = F_135 ( F_136 ( V_660 , V_147 ) ) ;
if ( V_184 ) {
V_460 = V_184 -> V_451 -> V_460 ;
V_677 = F_218 ( & V_460 -> V_662 ) ;
if ( V_677 > 1 )
goto V_679;
}
V_184 = F_135 ( F_136 ( V_680 , V_147 ) ) ;
if ( V_184 && ( F_345 ( V_653 . V_654 ,
F_348 ( V_184 ) ) < V_147 ) )
goto V_679;
F_131 () ;
return 0 ;
V_679:
F_131 () ;
V_678:
return 1 ;
}
static void F_453 ( struct V_24 * V_332 , enum V_548 V_380 ) { }
static void F_457 ( struct V_681 * V_682 )
{
struct V_24 * V_332 = V_332 () ;
enum V_548 V_380 = V_332 -> F_231 ?
V_598 : V_549 ;
F_451 ( V_332 , V_380 ) ;
F_453 ( V_332 , V_380 ) ;
}
void F_458 ( struct V_24 * V_24 )
{
if ( F_14 ( F_430 ( V_24 ) ) )
return;
if ( F_408 ( V_194 , V_24 -> V_635 ) )
F_459 ( V_683 ) ;
#ifdef F_460
if ( F_456 ( V_24 ) )
F_434 () ;
#endif
}
static void F_461 ( struct V_24 * V_24 )
{
F_8 () ;
F_315 ( V_24 ) ;
}
static void F_462 ( struct V_24 * V_24 )
{
F_8 () ;
F_317 ( V_24 ) ;
}
static void F_463 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_361 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_258 ( V_25 , V_28 , V_361 ) ;
}
if ( V_255 )
F_193 ( V_24 , V_45 ) ;
F_219 ( V_24 , 1 ) ;
}
static void F_464 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_441 = F_271 () ;
struct V_24 * V_24 = V_332 () ;
unsigned long V_178 ;
F_383 ( & V_24 -> V_177 , V_178 ) ;
F_288 ( V_24 ) ;
V_25 = F_23 ( V_141 ) ;
V_45 = V_25 -> V_45 ;
F_123 () ;
F_465 ( V_29 , V_441 ) ;
F_131 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_241 ( V_25 , V_28 , 1 ) ;
if ( V_684 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_121 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_252 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_384 ( & V_24 -> V_177 , V_178 ) ;
}
static void
F_466 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_685 )
{
if ( ! F_467 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_686 > V_685 )
F_252 ( V_24 ) ;
} else
F_378 ( V_24 , V_29 , 0 ) ;
}
static void F_468 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! F_467 ( V_29 ) && V_29 -> V_353 != V_687 ) {
F_241 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_197
if ( V_28 -> V_77 . V_78 ) {
F_210 ( V_28 ) ;
F_222 ( V_25 , V_28 -> V_77 . V_316 ) ;
}
#endif
}
static void F_469 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
#ifdef F_356
struct V_27 * V_28 = & V_29 -> V_28 ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_467 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 )
F_252 ( V_24 ) ;
else
F_378 ( V_24 , V_29 , 0 ) ;
}
static void F_470 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_253 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_471 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_688 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_197
F_472 ( & V_25 -> V_315 , 1 ) ;
F_473 ( & V_25 -> V_329 , 0 ) ;
#endif
}
static void F_474 ( struct V_26 * V_29 , int V_361 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_361 && ( ! V_28 -> V_85 || V_29 -> V_353 == V_689 ) )
V_361 = 1 ;
if ( ! V_361 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_475 ( V_29 , F_134 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_361 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_197
V_28 -> V_77 . V_78 = F_211 ( & V_25 -> V_315 ) ;
V_25 -> V_320 += V_28 -> V_77 . V_316 ;
#endif
}
}
void F_476 ( struct V_291 * V_33 )
{
int V_241 ;
F_313 ( F_273 ( V_33 ) ) ;
F_477 (i) {
if ( V_33 -> V_25 )
F_178 ( V_33 -> V_25 [ V_241 ] ) ;
if ( V_33 -> V_28 )
F_178 ( V_33 -> V_28 [ V_241 ] ) ;
}
F_178 ( V_33 -> V_25 ) ;
F_178 ( V_33 -> V_28 ) ;
}
int F_478 ( struct V_291 * V_33 , struct V_291 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_241 ;
V_33 -> V_25 = F_166 ( sizeof( V_25 ) * V_655 , V_243 ) ;
if ( ! V_33 -> V_25 )
goto V_690;
V_33 -> V_28 = F_166 ( sizeof( V_28 ) * V_655 , V_243 ) ;
if ( ! V_33 -> V_28 )
goto V_690;
V_33 -> V_295 = V_71 ;
F_306 ( F_273 ( V_33 ) ) ;
F_477 (i) {
V_25 = F_479 ( sizeof( struct V_25 ) ,
V_243 , F_104 ( V_241 ) ) ;
if ( ! V_25 )
goto V_690;
V_28 = F_479 ( sizeof( struct V_27 ) ,
V_243 , F_104 ( V_241 ) ) ;
if ( ! V_28 )
goto V_691;
F_471 ( V_25 ) ;
F_480 ( V_33 , V_25 , V_28 , V_241 , V_34 -> V_28 [ V_241 ] ) ;
}
return 1 ;
V_691:
F_178 ( V_25 ) ;
V_690:
return 0 ;
}
void F_481 ( struct V_291 * V_33 , int V_147 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
unsigned long V_178 ;
if ( ! V_33 -> V_25 [ V_147 ] -> V_32 )
return;
F_383 ( & V_24 -> V_177 , V_178 ) ;
F_31 ( V_33 -> V_25 [ V_147 ] ) ;
F_384 ( & V_24 -> V_177 , V_178 ) ;
}
void F_480 ( struct V_291 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_147 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_113 ( V_147 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_310 ( V_25 ) ;
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
int F_482 ( struct V_291 * V_33 , unsigned long V_295 )
{
int V_241 ;
unsigned long V_178 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_188 ;
V_295 = F_149 ( V_295 , F_220 ( V_296 ) , F_220 ( V_692 ) ) ;
F_483 ( & V_693 ) ;
if ( V_33 -> V_295 == V_295 )
goto V_472;
V_33 -> V_295 = V_295 ;
F_477 (i) {
struct V_24 * V_24 = F_113 ( V_241 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_241 ] ;
F_383 ( & V_24 -> V_177 , V_178 ) ;
F_288 ( V_24 ) ;
F_61 (se)
F_205 ( F_25 ( V_28 ) ) ;
F_384 ( & V_24 -> V_177 , V_178 ) ;
}
V_472:
F_484 ( & V_693 ) ;
return 0 ;
}
void F_476 ( struct V_291 * V_33 ) { }
int F_478 ( struct V_291 * V_33 , struct V_291 * V_34 )
{
return 1 ;
}
void F_481 ( struct V_291 * V_33 , int V_147 ) { }
static unsigned int F_485 ( struct V_24 * V_24 , struct V_26 * V_122 )
{
struct V_27 * V_28 = & V_122 -> V_28 ;
unsigned int V_694 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_694 = F_486 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_694 ;
}
void F_487 ( struct V_695 * V_696 , int V_147 )
{
struct V_25 * V_25 ;
F_123 () ;
F_316 (cpu_rq(cpu), cfs_rq)
F_488 ( V_696 , V_147 , V_25 ) ;
F_131 () ;
}
T_13 void F_489 ( void )
{
#ifdef F_197
F_490 ( V_683 , F_457 ) ;
#ifdef F_460
V_653 . V_635 = V_194 ;
F_491 ( & V_653 . V_654 , V_697 ) ;
F_492 ( F_449 , 0 ) ;
#endif
#endif
}
