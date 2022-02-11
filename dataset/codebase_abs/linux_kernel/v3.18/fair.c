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
static inline int F_94 ( int V_110 , int V_111 )
{
return V_112 * V_110 + V_111 ;
}
static inline unsigned long F_95 ( struct V_26 * V_29 , int V_110 )
{
if ( ! V_29 -> V_113 )
return 0 ;
return V_29 -> V_113 [ F_94 ( V_110 , 0 ) ] +
V_29 -> V_113 [ F_94 ( V_110 , 1 ) ] ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_110 )
{
if ( ! V_29 -> V_108 )
return 0 ;
return V_29 -> V_108 -> V_114 [ F_94 ( V_110 , 0 ) ] +
V_29 -> V_108 -> V_114 [ F_94 ( V_110 , 1 ) ] ;
}
static inline unsigned long F_97 ( struct V_108 * V_115 , int V_110 )
{
return V_115 -> V_116 [ F_94 ( V_110 , 0 ) ] +
V_115 -> V_116 [ F_94 ( V_110 , 1 ) ] ;
}
static inline unsigned long F_98 ( struct V_26 * V_29 , int V_110 )
{
unsigned long V_117 ;
if ( ! V_29 -> V_113 )
return 0 ;
V_117 = V_29 -> V_118 ;
if ( ! V_117 )
return 0 ;
return 1000 * F_95 ( V_29 , V_110 ) / V_117 ;
}
static inline unsigned long F_99 ( struct V_26 * V_29 , int V_110 )
{
if ( ! V_29 -> V_108 || ! V_29 -> V_108 -> V_117 )
return 0 ;
return 1000 * F_96 ( V_29 , V_110 ) / V_29 -> V_108 -> V_117 ;
}
bool F_100 ( struct V_26 * V_29 , struct V_119 * V_119 ,
int V_120 , int V_121 )
{
struct V_108 * V_122 = V_29 -> V_108 ;
int V_123 = F_101 ( V_121 ) ;
int V_124 , V_125 ;
V_125 = F_102 ( V_121 , V_126 -> V_127 ) ;
V_124 = F_103 ( V_119 , V_125 ) ;
if ( ! F_104 ( V_124 ) &&
F_105 ( V_124 ) != V_123 )
return false ;
if ( F_106 ( V_29 , V_124 ) )
return true ;
if ( ! V_122 )
return true ;
if ( ! F_107 ( V_123 , V_122 -> V_128 ) )
return false ;
if ( ! F_107 ( V_120 , V_122 -> V_128 ) )
return true ;
return F_96 ( V_29 , V_123 ) < ( F_96 ( V_29 , V_120 ) * 3 / 4 ) ;
}
static void F_108 ( struct V_129 * V_130 , int V_110 )
{
int V_131 , V_132 , V_8 = 0 ;
unsigned long V_133 ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
F_109 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_110 ( V_132 ) ;
V_130 -> V_72 += V_24 -> V_72 ;
V_130 -> V_70 += F_111 ( V_132 ) ;
V_130 -> V_134 += F_112 ( V_132 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_131 = F_56 ( V_135 * V_8 , V_130 -> V_134 ) ;
V_133 = V_8 / V_131 ;
V_130 -> V_136 = F_5 ( unsigned , V_133 ,
F_113 ( V_130 -> V_134 , V_135 ) ) ;
V_130 -> V_137 = ( V_130 -> V_72 < V_130 -> V_136 ) ;
}
static void F_114 ( struct V_138 * V_139 ,
struct V_26 * V_29 , long V_140 )
{
if ( V_139 -> V_141 )
F_115 ( V_139 -> V_141 ) ;
if ( V_29 )
F_116 ( V_29 ) ;
V_139 -> V_141 = V_29 ;
V_139 -> V_142 = V_140 ;
V_139 -> V_143 = V_139 -> V_121 ;
}
static bool F_117 ( long V_144 , long V_145 ,
struct V_138 * V_139 )
{
long V_146 , V_147 ;
long V_148 , V_149 ;
long V_150 , V_151 ;
V_150 = V_139 -> V_152 . V_134 ;
V_151 = V_139 -> V_153 . V_134 ;
if ( V_145 < V_144 )
F_118 ( V_145 , V_144 ) ;
V_146 = V_145 * V_150 * 100 -
V_144 * V_151 * V_139 -> V_154 ;
if ( V_146 <= 0 )
return false ;
V_148 = V_139 -> V_152 . V_70 ;
V_149 = V_139 -> V_153 . V_70 ;
if ( V_149 < V_148 )
F_118 ( V_149 , V_148 ) ;
V_147 = V_149 * V_150 * 100 -
V_148 * V_151 * V_139 -> V_154 ;
return ( V_146 > V_147 ) ;
}
static void F_119 ( struct V_138 * V_139 ,
long V_155 , long V_156 )
{
struct V_24 * V_157 = F_110 ( V_139 -> V_158 ) ;
struct V_24 * V_159 = F_110 ( V_139 -> V_121 ) ;
struct V_26 * V_160 ;
long V_144 , V_145 ;
long V_70 ;
long V_140 = V_139 -> V_29 -> V_108 ? V_156 : V_155 ;
long V_161 = V_140 ;
F_120 () ;
F_121 ( & V_159 -> V_162 ) ;
V_160 = V_159 -> V_45 ;
if ( ( V_160 -> V_163 & V_164 ) || F_122 ( V_160 ) )
V_160 = NULL ;
F_123 ( & V_159 -> V_162 ) ;
if ( V_160 == V_139 -> V_29 )
goto V_165;
if ( V_160 ) {
if ( ! F_124 ( V_139 -> V_158 , F_125 ( V_160 ) ) )
goto V_165;
if ( V_160 -> V_108 == V_139 -> V_29 -> V_108 ) {
V_140 = V_155 + F_98 ( V_160 , V_139 -> V_120 ) -
F_98 ( V_160 , V_139 -> V_123 ) ;
if ( V_160 -> V_108 )
V_140 -= V_140 / 16 ;
} else {
if ( V_160 -> V_108 )
V_140 += F_99 ( V_160 , V_139 -> V_120 ) -
F_99 ( V_160 , V_139 -> V_123 ) ;
else
V_140 += F_98 ( V_160 , V_139 -> V_120 ) -
F_98 ( V_160 , V_139 -> V_123 ) ;
}
}
if ( V_140 <= V_139 -> V_142 && V_161 <= V_139 -> V_142 )
goto V_165;
if ( ! V_160 ) {
if ( V_139 -> V_152 . V_72 <= V_139 -> V_152 . V_136 &&
! V_139 -> V_153 . V_137 )
goto V_165;
goto V_166;
}
if ( V_140 > V_139 -> V_142 && V_157 -> V_72 == 1 &&
V_159 -> V_72 == 1 )
goto V_167;
V_166:
V_70 = F_126 ( V_139 -> V_29 ) ;
V_145 = V_139 -> V_153 . V_70 + V_70 ;
V_144 = V_139 -> V_152 . V_70 - V_70 ;
if ( V_161 > V_140 && V_161 > V_139 -> V_142 ) {
if ( ! F_117 ( V_144 , V_145 , V_139 ) ) {
V_140 = V_161 - 1 ;
V_160 = NULL ;
goto V_167;
}
}
if ( V_140 <= V_139 -> V_142 )
goto V_165;
if ( V_160 ) {
V_70 = F_126 ( V_160 ) ;
V_145 -= V_70 ;
V_144 += V_70 ;
}
if ( F_117 ( V_144 , V_145 , V_139 ) )
goto V_165;
if ( ! V_160 )
V_139 -> V_121 = F_127 ( V_139 -> V_29 , V_139 -> V_121 ) ;
V_167:
F_114 ( V_139 , V_160 , V_140 ) ;
V_165:
F_128 () ;
}
static void F_129 ( struct V_138 * V_139 ,
long V_155 , long V_156 )
{
int V_132 ;
F_109 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_124 ( V_132 , F_125 ( V_139 -> V_29 ) ) )
continue;
V_139 -> V_121 = V_132 ;
F_119 ( V_139 , V_155 , V_156 ) ;
}
}
static int F_130 ( struct V_26 * V_29 )
{
struct V_138 V_139 = {
. V_29 = V_29 ,
. V_158 = F_131 ( V_29 ) ,
. V_120 = F_91 ( V_29 ) ,
. V_154 = 112 ,
. V_141 = NULL ,
. V_142 = 0 ,
. V_143 = - 1
} ;
struct V_168 * V_169 ;
unsigned long V_170 , V_171 ;
int V_110 , V_66 ;
long V_155 , V_156 ;
F_120 () ;
V_169 = F_132 ( F_133 ( V_172 , V_139 . V_158 ) ) ;
if ( V_169 )
V_139 . V_154 = 100 + ( V_169 -> V_154 - 100 ) / 2 ;
F_128 () ;
if ( F_14 ( ! V_169 ) ) {
V_29 -> V_106 = F_91 ( V_29 ) ;
return - V_173 ;
}
V_170 = F_98 ( V_29 , V_139 . V_120 ) ;
V_171 = F_99 ( V_29 , V_139 . V_120 ) ;
F_108 ( & V_139 . V_152 , V_139 . V_120 ) ;
V_139 . V_123 = V_29 -> V_106 ;
V_155 = F_98 ( V_29 , V_139 . V_123 ) - V_170 ;
V_156 = F_99 ( V_29 , V_139 . V_123 ) - V_171 ;
F_108 ( & V_139 . V_153 , V_139 . V_123 ) ;
F_129 ( & V_139 , V_155 , V_156 ) ;
if ( V_139 . V_143 == - 1 ) {
F_134 (nid) {
if ( V_110 == V_139 . V_120 || V_110 == V_29 -> V_106 )
continue;
V_155 = F_98 ( V_29 , V_110 ) - V_170 ;
V_156 = F_99 ( V_29 , V_110 ) - V_171 ;
if ( V_155 < 0 && V_156 < 0 )
continue;
V_139 . V_123 = V_110 ;
F_108 ( & V_139 . V_153 , V_139 . V_123 ) ;
F_129 ( & V_139 , V_155 , V_156 ) ;
}
}
if ( V_29 -> V_108 ) {
if ( V_139 . V_143 == - 1 )
V_110 = V_139 . V_120 ;
else
V_110 = V_139 . V_123 ;
if ( F_107 ( V_110 , V_29 -> V_108 -> V_128 ) )
F_135 ( V_29 , V_139 . V_123 ) ;
}
if ( V_139 . V_143 == - 1 )
return - V_174 ;
V_29 -> V_175 = F_86 ( V_29 ) ;
if ( V_139 . V_141 == NULL ) {
V_66 = F_136 ( V_29 , V_139 . V_143 ) ;
if ( V_66 != 0 )
F_137 ( V_29 , V_139 . V_158 , V_139 . V_143 ) ;
return V_66 ;
}
V_66 = F_138 ( V_29 , V_139 . V_141 ) ;
if ( V_66 != 0 )
F_137 ( V_29 , V_139 . V_158 , F_131 ( V_139 . V_141 ) ) ;
F_115 ( V_139 . V_141 ) ;
return V_66 ;
}
static void F_139 ( struct V_26 * V_29 )
{
unsigned long V_176 = V_177 ;
if ( F_14 ( V_29 -> V_106 == - 1 || ! V_29 -> V_113 ) )
return;
V_176 = F_140 ( V_176 , F_141 ( V_29 -> V_175 ) / 16 ) ;
V_29 -> V_178 = V_179 + V_176 ;
if ( F_91 ( V_29 ) == V_29 -> V_106 )
return;
F_130 ( V_29 ) ;
}
static void F_142 ( struct V_108 * V_108 )
{
unsigned long V_114 , V_180 = 0 ;
int V_110 ;
F_134 (nid) {
V_114 = F_97 ( V_108 , V_110 ) ;
if ( V_114 > V_180 )
V_180 = V_114 ;
}
F_134 (nid) {
V_114 = F_97 ( V_108 , V_110 ) ;
if ( ! F_107 ( V_110 , V_108 -> V_128 ) ) {
if ( V_114 > V_180 * 6 / 16 )
F_143 ( V_110 , V_108 -> V_128 ) ;
} else if ( V_114 < V_180 * 3 / 16 )
F_144 ( V_110 , V_108 -> V_128 ) ;
}
}
static void F_145 ( struct V_26 * V_29 ,
unsigned long V_181 , unsigned long V_182 )
{
unsigned int V_183 ;
int V_184 ;
int V_185 ;
unsigned long V_186 = V_29 -> V_187 [ 0 ] ;
unsigned long V_188 = V_29 -> V_187 [ 1 ] ;
if ( V_188 + V_181 == 0 ) {
V_29 -> V_175 = F_140 ( V_29 -> V_189 ,
V_29 -> V_175 << 1 ) ;
V_29 -> V_96 -> V_190 = V_179 +
F_141 ( V_29 -> V_175 ) ;
return;
}
V_183 = F_56 ( V_29 -> V_175 , V_191 ) ;
V_184 = ( V_188 * V_191 ) / ( V_188 + V_186 ) ;
if ( V_184 >= V_192 ) {
int V_193 = V_184 - V_192 ;
if ( ! V_193 )
V_193 = 1 ;
V_185 = V_193 * V_183 ;
} else {
V_185 = - ( V_192 - V_184 ) * V_183 ;
V_184 = F_56 ( V_182 * V_191 , ( V_182 + V_181 + 1 ) ) ;
V_185 = ( V_185 * V_184 ) / V_191 ;
}
V_29 -> V_175 = F_146 ( V_29 -> V_175 + V_185 ,
F_86 ( V_29 ) , F_89 ( V_29 ) ) ;
memset ( V_29 -> V_187 , 0 , sizeof( V_29 -> V_187 ) ) ;
}
static T_2 F_147 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_194 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_194 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_195 ) {
V_42 = V_194 - V_29 -> V_196 ;
* V_73 = V_81 - V_29 -> V_195 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_79 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_196 = V_194 ;
V_29 -> V_195 = V_81 ;
return V_42 ;
}
static void F_148 ( struct V_26 * V_29 )
{
int V_197 , V_110 , V_198 = - 1 , V_199 = - 1 ;
unsigned long V_180 = 0 , V_200 = 0 ;
unsigned long V_201 [ 2 ] = { 0 , 0 } ;
unsigned long V_117 ;
T_2 V_194 , V_73 ;
T_8 * V_202 = NULL ;
V_197 = F_87 ( V_29 -> V_96 -> V_203 ) ;
if ( V_29 -> V_203 == V_197 )
return;
V_29 -> V_203 = V_197 ;
V_29 -> V_189 = F_89 ( V_29 ) ;
V_117 = V_29 -> V_187 [ 0 ] +
V_29 -> V_187 [ 1 ] ;
V_194 = F_147 ( V_29 , & V_73 ) ;
if ( V_29 -> V_108 ) {
V_202 = & V_29 -> V_108 -> V_162 ;
F_149 ( V_202 ) ;
}
F_134 (nid) {
unsigned long V_114 = 0 , F_96 = 0 ;
int V_111 , V_204 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
long V_185 , V_205 , V_206 ;
V_204 = F_94 ( V_110 , V_111 ) ;
V_185 = V_29 -> V_207 [ V_204 ] - V_29 -> V_113 [ V_204 ] / 2 ;
V_201 [ V_111 ] += V_29 -> V_207 [ V_204 ] ;
V_29 -> V_207 [ V_204 ] = 0 ;
V_206 = F_150 ( V_194 << 16 , V_73 + 1 ) ;
V_206 = ( V_206 * V_29 -> V_208 [ V_204 ] ) /
( V_117 + 1 ) ;
V_205 = V_206 - V_29 -> V_209 [ V_204 ] / 2 ;
V_29 -> V_208 [ V_204 ] = 0 ;
V_29 -> V_113 [ V_204 ] += V_185 ;
V_29 -> V_209 [ V_204 ] += V_205 ;
V_114 += V_29 -> V_113 [ V_204 ] ;
V_29 -> V_118 += V_185 ;
if ( V_29 -> V_108 ) {
V_29 -> V_108 -> V_114 [ V_204 ] += V_185 ;
V_29 -> V_108 -> V_116 [ V_204 ] += V_205 ;
V_29 -> V_108 -> V_117 += V_185 ;
F_96 += V_29 -> V_108 -> V_114 [ V_204 ] ;
}
}
if ( V_114 > V_180 ) {
V_180 = V_114 ;
V_198 = V_110 ;
}
if ( F_96 > V_200 ) {
V_200 = F_96 ;
V_199 = V_110 ;
}
}
F_145 ( V_29 , V_201 [ 0 ] , V_201 [ 1 ] ) ;
if ( V_29 -> V_108 ) {
F_142 ( V_29 -> V_108 ) ;
F_151 ( V_202 ) ;
V_198 = V_199 ;
}
if ( V_180 ) {
if ( V_198 != V_29 -> V_106 )
F_135 ( V_29 , V_198 ) ;
if ( F_91 ( V_29 ) != V_29 -> V_106 )
F_139 ( V_29 ) ;
}
}
static inline int F_152 ( struct V_108 * V_30 )
{
return F_153 ( & V_30 -> V_210 ) ;
}
static inline void F_154 ( struct V_108 * V_30 )
{
if ( F_155 ( & V_30 -> V_210 ) )
F_156 ( V_30 , V_211 ) ;
}
static void F_157 ( struct V_26 * V_29 , int V_212 , int V_163 ,
int * V_111 )
{
struct V_108 * V_30 , * V_213 ;
struct V_26 * V_214 ;
bool V_215 = false ;
int V_132 = F_158 ( V_212 ) ;
int V_204 ;
if ( F_14 ( ! V_29 -> V_108 ) ) {
unsigned int V_216 = sizeof( struct V_108 ) +
4 * V_217 *sizeof( unsigned long ) ;
V_30 = F_159 ( V_216 , V_218 | V_219 ) ;
if ( ! V_30 )
return;
F_160 ( & V_30 -> V_210 , 1 ) ;
F_161 ( & V_30 -> V_162 ) ;
F_162 ( & V_30 -> V_220 ) ;
V_30 -> V_109 = V_29 -> V_127 ;
V_30 -> V_116 = V_30 -> V_114 + V_112 *
V_217 ;
F_143 ( F_91 ( V_126 ) , V_30 -> V_128 ) ;
for ( V_204 = 0 ; V_204 < V_221 * V_217 ; V_204 ++ )
V_30 -> V_114 [ V_204 ] = V_29 -> V_113 [ V_204 ] ;
V_30 -> V_117 = V_29 -> V_118 ;
F_163 ( & V_29 -> V_222 , & V_30 -> V_220 ) ;
V_30 -> V_223 ++ ;
F_164 ( V_29 -> V_108 , V_30 ) ;
}
F_120 () ;
V_214 = F_87 ( F_110 ( V_132 ) -> V_45 ) ;
if ( ! F_106 ( V_214 , V_212 ) )
goto V_224;
V_30 = F_132 ( V_214 -> V_108 ) ;
if ( ! V_30 )
goto V_224;
V_213 = V_29 -> V_108 ;
if ( V_30 == V_213 )
goto V_224;
if ( V_213 -> V_223 > V_30 -> V_223 )
goto V_224;
if ( V_213 -> V_223 == V_30 -> V_223 && V_213 > V_30 )
goto V_224;
if ( V_214 -> V_96 == V_126 -> V_96 )
V_215 = true ;
if ( V_163 & V_225 )
V_215 = true ;
* V_111 = ! V_215 ;
if ( V_215 && ! F_152 ( V_30 ) )
goto V_224;
F_128 () ;
if ( ! V_215 )
return;
F_165 ( F_166 () ) ;
F_167 ( & V_213 -> V_162 , & V_30 -> V_162 ) ;
for ( V_204 = 0 ; V_204 < V_221 * V_217 ; V_204 ++ ) {
V_213 -> V_114 [ V_204 ] -= V_29 -> V_113 [ V_204 ] ;
V_30 -> V_114 [ V_204 ] += V_29 -> V_113 [ V_204 ] ;
}
V_213 -> V_117 -= V_29 -> V_118 ;
V_30 -> V_117 += V_29 -> V_118 ;
F_168 ( & V_29 -> V_222 , & V_30 -> V_220 ) ;
V_213 -> V_223 -- ;
V_30 -> V_223 ++ ;
F_169 ( & V_213 -> V_162 ) ;
F_151 ( & V_30 -> V_162 ) ;
F_164 ( V_29 -> V_108 , V_30 ) ;
F_154 ( V_213 ) ;
return;
V_224:
F_128 () ;
return;
}
void F_170 ( struct V_26 * V_29 )
{
struct V_108 * V_30 = V_29 -> V_108 ;
void * V_226 = V_29 -> V_113 ;
unsigned long V_163 ;
int V_204 ;
if ( V_30 ) {
F_171 ( & V_30 -> V_162 , V_163 ) ;
for ( V_204 = 0 ; V_204 < V_221 * V_217 ; V_204 ++ )
V_30 -> V_114 [ V_204 ] -= V_29 -> V_113 [ V_204 ] ;
V_30 -> V_117 -= V_29 -> V_118 ;
F_172 ( & V_29 -> V_222 ) ;
V_30 -> V_223 -- ;
F_173 ( & V_30 -> V_162 , V_163 ) ;
F_174 ( V_29 -> V_108 , NULL ) ;
F_154 ( V_30 ) ;
}
V_29 -> V_113 = NULL ;
V_29 -> V_207 = NULL ;
V_29 -> V_209 = NULL ;
V_29 -> V_208 = NULL ;
F_175 ( V_226 ) ;
}
void F_176 ( int V_124 , int V_227 , int V_228 , int V_163 )
{
struct V_26 * V_29 = V_126 ;
bool V_229 = V_163 & V_230 ;
int V_231 = F_91 ( V_126 ) ;
int V_188 = ! ! ( V_163 & V_232 ) ;
int V_111 ;
if ( ! V_233 )
return;
if ( ! V_29 -> V_96 )
return;
if ( F_14 ( ! V_29 -> V_113 ) ) {
int V_216 = sizeof( * V_29 -> V_113 ) *
V_234 * V_217 ;
V_29 -> V_113 = F_159 ( V_216 , V_218 | V_219 ) ;
if ( ! V_29 -> V_113 )
return;
F_165 ( V_29 -> V_207 ) ;
V_29 -> V_209 = V_29 -> V_113 + ( 2 * V_217 ) ;
V_29 -> V_207 = V_29 -> V_113 + ( 4 * V_217 ) ;
V_29 -> V_208 = V_29 -> V_113 + ( 6 * V_217 ) ;
V_29 -> V_118 = 0 ;
memset ( V_29 -> V_187 , 0 , sizeof( V_29 -> V_187 ) ) ;
}
if ( F_14 ( V_124 == ( - 1 & V_235 ) ) ) {
V_111 = 1 ;
} else {
V_111 = F_106 ( V_29 , V_124 ) ;
if ( ! V_111 && ! ( V_163 & V_236 ) )
F_157 ( V_29 , V_124 , V_163 , & V_111 ) ;
}
if ( ! V_111 && ! V_188 && V_29 -> V_108 &&
F_107 ( V_231 , V_29 -> V_108 -> V_128 ) &&
F_107 ( V_227 , V_29 -> V_108 -> V_128 ) )
V_188 = 1 ;
F_148 ( V_29 ) ;
if ( F_177 ( V_179 , V_29 -> V_178 ) )
F_139 ( V_29 ) ;
if ( V_229 )
V_29 -> V_237 += V_228 ;
V_29 -> V_207 [ F_94 ( V_227 , V_111 ) ] += V_228 ;
V_29 -> V_208 [ F_94 ( V_231 , V_111 ) ] += V_228 ;
V_29 -> V_187 [ V_188 ] += V_228 ;
}
static void F_178 ( struct V_26 * V_29 )
{
F_87 ( V_29 -> V_96 -> V_203 ) ++ ;
V_29 -> V_96 -> V_238 = 0 ;
}
void F_179 ( struct V_239 * V_240 )
{
unsigned long V_241 , V_242 , V_81 = V_179 ;
struct V_26 * V_29 = V_126 ;
struct V_243 * V_96 = V_29 -> V_96 ;
struct V_244 * V_245 ;
unsigned long V_246 , V_247 ;
unsigned long V_248 = 0 ;
long V_228 ;
F_20 ( V_29 != F_22 ( V_240 , struct V_26 , V_249 ) ) ;
V_240 -> V_58 = V_240 ;
if ( V_29 -> V_163 & V_164 )
return;
if ( ! V_96 -> V_190 ) {
V_96 -> V_190 = V_81 +
F_141 ( V_250 ) ;
}
V_241 = V_96 -> V_190 ;
if ( F_180 ( V_81 , V_241 ) )
return;
if ( V_29 -> V_175 == 0 ) {
V_29 -> V_189 = F_89 ( V_29 ) ;
V_29 -> V_175 = F_86 ( V_29 ) ;
}
V_242 = V_81 + F_141 ( V_29 -> V_175 ) ;
if ( F_181 ( & V_96 -> V_190 , V_241 , V_242 ) != V_241 )
return;
V_29 -> V_251 += 2 * V_252 ;
V_246 = V_96 -> V_238 ;
V_228 = V_94 ;
V_228 <<= 20 - V_95 ;
if ( ! V_228 )
return;
F_182 ( & V_96 -> V_253 ) ;
V_245 = F_183 ( V_96 , V_246 ) ;
if ( ! V_245 ) {
F_178 ( V_29 ) ;
V_246 = 0 ;
V_245 = V_96 -> V_254 ;
}
for (; V_245 ; V_245 = V_245 -> V_255 ) {
if ( ! F_184 ( V_245 ) || ! F_185 ( V_245 ) )
continue;
if ( ! V_245 -> V_256 ||
( V_245 -> V_257 && ( V_245 -> V_258 & ( V_259 | V_260 ) ) == ( V_259 ) ) )
continue;
if ( ! ( V_245 -> V_258 & ( V_259 | V_261 | V_260 ) ) )
continue;
do {
V_246 = F_68 ( V_246 , V_245 -> V_262 ) ;
V_247 = F_186 ( V_246 + ( V_228 << V_95 ) , V_263 ) ;
V_247 = F_140 ( V_247 , V_245 -> V_264 ) ;
V_248 += F_187 ( V_245 , V_246 , V_247 ) ;
if ( V_248 )
V_228 -= ( V_247 - V_246 ) >> V_95 ;
V_246 = V_247 ;
if ( V_228 <= 0 )
goto V_265;
F_188 () ;
} while ( V_247 != V_245 -> V_264 );
}
V_265:
if ( V_245 )
V_96 -> V_238 = V_246 ;
else
F_178 ( V_29 ) ;
F_189 ( & V_96 -> V_253 ) ;
}
void F_190 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_239 * V_240 = & V_45 -> V_249 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_163 & V_164 ) || V_240 -> V_58 != V_240 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_175 * V_266 ;
if ( V_81 - V_45 -> V_251 > V_73 ) {
if ( ! V_45 -> V_251 )
V_45 -> V_175 = F_86 ( V_45 ) ;
V_45 -> V_251 += V_73 ;
if ( ! F_180 ( V_179 , V_45 -> V_96 -> V_190 ) ) {
F_191 ( V_240 , F_179 ) ;
F_192 ( V_45 , V_240 , true ) ;
}
}
}
static void F_190 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_193 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_194
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_90 ( V_24 , F_18 ( V_28 ) ) ;
F_163 ( & V_28 -> V_267 , & V_24 -> V_268 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_195 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_92 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_196 ( & V_28 -> V_267 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_197 ( struct V_269 * V_33 , struct V_25 * V_25 )
{
long V_270 ;
V_270 = F_198 ( & V_33 -> V_271 ) ;
V_270 -= V_25 -> V_272 ;
V_270 += V_25 -> V_70 . V_4 ;
return V_270 ;
}
static long F_199 ( struct V_25 * V_25 , struct V_269 * V_33 )
{
long V_270 , V_70 , V_273 ;
V_270 = F_197 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_273 = ( V_33 -> V_273 * V_70 ) ;
if ( V_270 )
V_273 /= V_270 ;
if ( V_273 < V_274 )
V_273 = V_274 ;
if ( V_273 > V_33 -> V_273 )
V_273 = V_33 -> V_273 ;
return V_273 ;
}
static inline long F_199 ( struct V_25 * V_25 , struct V_269 * V_33 )
{
return V_33 -> V_273 ;
}
static void F_200 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_195 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_193 ( V_25 , V_28 ) ;
}
static void F_201 ( struct V_25 * V_25 )
{
struct V_269 * V_33 ;
struct V_27 * V_28 ;
long V_273 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_202 ( V_25 ) )
return;
#ifndef F_194
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_273 ) )
return;
#endif
V_273 = F_199 ( V_25 , V_33 ) ;
F_200 ( F_24 ( V_28 ) , V_28 , V_273 ) ;
}
static inline void F_201 ( struct V_25 * V_25 )
{
}
static T_9 T_2 F_203 ( T_2 V_275 , T_2 V_276 )
{
unsigned int V_277 ;
if ( ! V_276 )
return V_275 ;
else if ( F_14 ( V_276 > V_278 * 63 ) )
return 0 ;
V_277 = V_276 ;
if ( F_14 ( V_277 >= V_278 ) ) {
V_275 >>= V_277 / V_278 ;
V_277 %= V_278 ;
}
V_275 *= V_279 [ V_277 ] ;
return V_275 >> 32 ;
}
static V_23 F_204 ( T_2 V_276 )
{
V_23 V_280 = 0 ;
if ( F_12 ( V_276 <= V_278 ) )
return V_281 [ V_276 ] ;
else if ( F_14 ( V_276 >= V_282 ) )
return V_283 ;
do {
V_280 /= 2 ;
V_280 += V_281 [ V_278 ] ;
V_276 -= V_278 ;
} while ( V_276 > V_278 );
V_280 = F_203 ( V_280 , V_276 ) ;
return V_280 + V_281 [ V_276 ] ;
}
static T_9 int F_205 ( T_2 V_81 ,
struct V_284 * V_285 ,
int V_286 )
{
T_2 V_42 , V_287 ;
V_23 V_288 ;
int V_289 , V_290 = 0 ;
V_42 = V_81 - V_285 -> V_291 ;
if ( ( T_3 ) V_42 < 0 ) {
V_285 -> V_291 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_285 -> V_291 = V_81 ;
V_289 = V_285 -> V_80 % 1024 ;
if ( V_42 + V_289 >= 1024 ) {
V_290 = 1 ;
V_289 = 1024 - V_289 ;
if ( V_286 )
V_285 -> V_79 += V_289 ;
V_285 -> V_80 += V_289 ;
V_42 -= V_289 ;
V_287 = V_42 / 1024 ;
V_42 %= 1024 ;
V_285 -> V_79 = F_203 ( V_285 -> V_79 ,
V_287 + 1 ) ;
V_285 -> V_80 = F_203 ( V_285 -> V_80 ,
V_287 + 1 ) ;
V_288 = F_204 ( V_287 ) ;
if ( V_286 )
V_285 -> V_79 += V_288 ;
V_285 -> V_80 += V_288 ;
}
if ( V_286 )
V_285 -> V_79 += V_42 ;
V_285 -> V_80 += V_42 ;
return V_290 ;
}
static inline T_2 F_206 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_292 = F_207 ( & V_25 -> V_293 ) ;
V_292 -= V_28 -> V_77 . V_78 ;
if ( ! V_292 )
return 0 ;
V_28 -> V_77 . V_294 = F_203 ( V_28 -> V_77 . V_294 , V_292 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_292 ;
}
static inline void F_208 ( struct V_25 * V_25 ,
int V_295 )
{
struct V_269 * V_33 = V_25 -> V_33 ;
long V_296 ;
V_296 = V_25 -> V_297 + V_25 -> V_298 ;
V_296 -= V_25 -> V_272 ;
if ( ! V_296 )
return;
if ( V_295 || abs ( V_296 ) > V_25 -> V_272 / 8 ) {
F_209 ( V_296 , & V_33 -> V_271 ) ;
V_25 -> V_272 += V_296 ;
}
}
static inline void F_210 ( struct V_284 * V_285 ,
struct V_25 * V_25 )
{
struct V_269 * V_33 = V_25 -> V_33 ;
long V_280 ;
V_280 = F_211 ( ( T_2 ) V_285 -> V_79 << V_299 ,
V_285 -> V_80 + 1 ) ;
V_280 -= V_25 -> V_300 ;
if ( abs ( V_280 ) > V_25 -> V_300 / 64 ) {
F_212 ( V_280 , & V_33 -> V_301 ) ;
V_25 -> V_300 += V_280 ;
}
}
static inline void F_213 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_269 * V_33 = V_25 -> V_33 ;
int V_301 ;
T_2 V_280 ;
V_280 = V_25 -> V_272 * V_33 -> V_273 ;
V_28 -> V_77 . V_294 = F_211 ( V_280 ,
F_198 ( & V_33 -> V_271 ) + 1 ) ;
V_301 = F_214 ( & V_33 -> V_301 ) ;
if ( V_301 < V_71 ) {
V_28 -> V_77 . V_294 *= V_301 ;
V_28 -> V_77 . V_294 >>= V_299 ;
}
}
static inline void F_215 ( struct V_24 * V_24 , int V_286 )
{
F_205 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_286 ) ;
F_210 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_208 ( struct V_25 * V_25 ,
int V_295 ) {}
static inline void F_210 ( struct V_284 * V_285 ,
struct V_25 * V_25 ) {}
static inline void F_213 ( struct V_27 * V_28 ) {}
static inline void F_215 ( struct V_24 * V_24 , int V_286 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_280 ;
V_280 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_280 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_294 = F_216 ( V_280 ) ;
}
static long F_217 ( struct V_27 * V_28 )
{
long V_302 = V_28 -> V_77 . V_294 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_210 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_213 ( V_28 ) ;
}
return V_28 -> V_77 . V_294 - V_302 ;
}
static inline void F_218 ( struct V_25 * V_25 ,
long V_303 )
{
if ( F_12 ( V_303 < V_25 -> V_298 ) )
V_25 -> V_298 -= V_303 ;
else
V_25 -> V_298 = 0 ;
}
static inline void F_219 ( struct V_27 * V_28 ,
int V_304 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_305 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_220 ( V_25 ) ;
else
V_81 = F_220 ( F_25 ( V_28 ) ) ;
if ( ! F_205 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_305 = F_217 ( V_28 ) ;
if ( ! V_304 )
return;
if ( V_28 -> V_76 )
V_25 -> V_297 += V_305 ;
else
F_218 ( V_25 , - V_305 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_295 )
{
T_2 V_81 = F_220 ( V_25 ) >> 20 ;
T_2 V_292 ;
V_292 = V_81 - V_25 -> V_306 ;
if ( ! V_292 && ! V_295 )
return;
if ( F_198 ( & V_25 -> V_307 ) ) {
unsigned long V_307 ;
V_307 = F_221 ( & V_25 -> V_307 , 0 ) ;
F_218 ( V_25 , V_307 ) ;
}
if ( V_292 ) {
V_25 -> V_298 = F_203 ( V_25 -> V_298 ,
V_292 ) ;
F_222 ( V_292 , & V_25 -> V_293 ) ;
V_25 -> V_306 = V_81 ;
}
F_208 ( V_25 , V_295 ) ;
}
static inline void F_223 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_308 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_291 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_291 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_219 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_308 = 0 ;
} else {
F_206 ( V_28 ) ;
}
if ( V_308 ) {
F_218 ( V_25 , V_28 -> V_77 . V_294 ) ;
F_219 ( V_28 , 0 ) ;
}
V_25 -> V_297 += V_28 -> V_77 . V_294 ;
F_30 ( V_25 , ! V_308 ) ;
}
static inline void F_224 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_309 )
{
F_219 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_309 ) ;
V_25 -> V_297 -= V_28 -> V_77 . V_294 ;
if ( V_309 ) {
V_25 -> V_298 += V_28 -> V_77 . V_294 ;
V_28 -> V_77 . V_78 = F_207 ( & V_25 -> V_293 ) ;
}
}
void F_225 ( struct V_24 * V_310 )
{
F_215 ( V_310 , 1 ) ;
}
void F_226 ( struct V_24 * V_310 )
{
F_215 ( V_310 , 0 ) ;
}
static inline void F_219 ( struct V_27 * V_28 ,
int V_304 ) {}
static inline void F_215 ( struct V_24 * V_24 , int V_286 ) {}
static inline void F_223 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_308 ) {}
static inline void F_224 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_309 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_295 ) {}
static inline int F_227 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_228 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_79
struct V_26 * V_214 = NULL ;
if ( F_21 ( V_28 ) )
V_214 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_311 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_311 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_312 ) )
V_28 -> V_83 . V_312 = V_42 ;
V_28 -> V_83 . V_311 = 0 ;
V_28 -> V_83 . V_313 += V_42 ;
if ( V_214 ) {
F_229 ( V_214 , V_42 >> 10 , 1 ) ;
F_230 ( V_214 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_314 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_314 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_315 ) )
V_28 -> V_83 . V_315 = V_42 ;
V_28 -> V_83 . V_314 = 0 ;
V_28 -> V_83 . V_313 += V_42 ;
if ( V_214 ) {
if ( V_214 -> V_316 ) {
V_28 -> V_83 . V_317 += V_42 ;
V_28 -> V_83 . V_318 ++ ;
F_231 ( V_214 , V_42 ) ;
}
F_232 ( V_214 , V_42 ) ;
if ( F_14 ( V_319 == V_320 ) ) {
F_233 ( V_320 ,
( void * ) F_234 ( V_214 ) ,
V_42 >> 20 ) ;
}
F_229 ( V_214 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_235 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_321 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_321 < 0 )
V_321 = - V_321 ;
if ( V_321 > 3 * V_68 )
F_236 ( V_25 , V_322 ) ;
#endif
}
static void
F_237 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_323 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_323 && F_238 ( V_324 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_323 ) {
unsigned long V_325 = V_68 ;
if ( F_238 ( V_326 ) )
V_325 >>= 1 ;
V_41 -= V_325 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_239 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_163 )
{
if ( ! ( V_163 & V_327 ) || ( V_163 & V_328 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_223 ( V_25 , V_28 , V_163 & V_327 ) ;
F_193 ( V_25 , V_28 ) ;
F_201 ( V_25 ) ;
if ( V_163 & V_327 ) {
F_237 ( V_25 , V_28 , 0 ) ;
F_228 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_235 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_240 ( V_25 ) ;
}
}
static void F_241 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_242 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_243 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_329 != V_28 )
break;
V_25 -> V_329 = NULL ;
}
}
static void F_244 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_241 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_242 ( V_28 ) ;
if ( V_25 -> V_329 == V_28 )
F_243 ( V_28 ) ;
}
static void
F_245 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_163 )
{
F_65 ( V_25 ) ;
F_224 ( V_25 , V_28 , V_163 & V_330 ) ;
F_81 ( V_25 , V_28 ) ;
if ( V_163 & V_330 ) {
#ifdef F_79
if ( F_21 ( V_28 ) ) {
struct V_26 * V_214 = F_18 ( V_28 ) ;
if ( V_214 -> V_331 & V_332 )
V_28 -> V_83 . V_311 = F_76 ( F_17 ( V_25 ) ) ;
if ( V_214 -> V_331 & V_333 )
V_28 -> V_83 . V_314 = F_76 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_244 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_195 ( V_25 , V_28 ) ;
if ( ! ( V_163 & V_330 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_246 ( V_25 ) ;
F_40 ( V_25 ) ;
F_201 ( V_25 ) ;
}
static void
F_247 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_334 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_334 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_335 ;
if ( V_19 > V_334 ) {
F_248 ( F_17 ( V_25 ) ) ;
F_244 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_334 )
F_248 ( F_17 ( V_25 ) ) ;
}
static void
F_249 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_78 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
}
F_82 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_79
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_336 = F_68 ( V_28 -> V_83 . V_336 ,
V_28 -> V_85 - V_28 -> V_335 ) ;
}
#endif
V_28 -> V_335 = V_28 -> V_85 ;
}
static struct V_27 *
F_250 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_329 == V_28 ) {
struct V_27 * V_337 ;
if ( V_28 == V_45 ) {
V_337 = F_50 ( V_25 ) ;
} else {
V_337 = F_51 ( V_28 ) ;
if ( ! V_337 || ( V_45 && F_39 ( V_45 , V_337 ) ) )
V_337 = V_45 ;
}
if ( V_337 && F_251 ( V_337 , V_57 ) < 1 )
V_28 = V_337 ;
}
if ( V_25 -> V_59 && F_251 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_251 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_244 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_252 ( struct V_25 * V_25 , struct V_27 * V_338 )
{
if ( V_338 -> V_76 )
F_65 ( V_25 ) ;
F_253 ( V_25 ) ;
F_235 ( V_25 , V_338 ) ;
if ( V_338 -> V_76 ) {
F_75 ( V_25 , V_338 ) ;
F_44 ( V_25 , V_338 ) ;
F_219 ( V_338 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_254 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_339 )
{
F_65 ( V_25 ) ;
F_219 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_201 ( V_25 ) ;
#ifdef F_255
if ( V_339 ) {
F_248 ( F_17 ( V_25 ) ) ;
return;
}
if ( ! F_238 ( V_340 ) &&
F_256 ( & F_17 ( V_25 ) -> V_341 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_247 ( V_25 , V_45 ) ;
}
static inline bool F_257 ( void )
{
return F_258 ( & V_342 ) ;
}
void F_259 ( void )
{
F_260 ( & V_342 ) ;
}
void F_261 ( void )
{
F_262 ( & V_342 ) ;
}
static bool F_257 ( void )
{
return true ;
}
void F_259 ( void ) {}
void F_261 ( void ) {}
static inline T_2 F_263 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_264 ( void )
{
return ( T_2 ) V_343 * V_344 ;
}
void F_265 ( struct V_345 * V_346 )
{
T_2 V_81 ;
if ( V_346 -> V_347 == V_348 )
return;
V_81 = F_266 ( F_267 () ) ;
V_346 -> V_194 = V_346 -> V_347 ;
V_346 -> V_349 = V_81 + F_268 ( V_346 -> V_73 ) ;
}
static inline struct V_345 * F_269 ( struct V_269 * V_33 )
{
return & V_33 -> V_345 ;
}
static inline T_2 F_220 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_350 ) )
return V_25 -> V_351 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_352 ;
}
static int F_270 ( struct V_25 * V_25 )
{
struct V_269 * V_33 = V_25 -> V_33 ;
struct V_345 * V_346 = F_269 ( V_33 ) ;
T_2 V_353 = 0 , V_354 , V_355 ;
V_354 = F_264 () - V_25 -> V_356 ;
F_271 ( & V_346 -> V_162 ) ;
if ( V_346 -> V_347 == V_348 )
V_353 = V_354 ;
else {
if ( ! V_346 -> V_357 ) {
F_265 ( V_346 ) ;
F_272 ( V_346 , false ) ;
}
if ( V_346 -> V_194 > 0 ) {
V_353 = F_140 ( V_346 -> V_194 , V_354 ) ;
V_346 -> V_194 -= V_353 ;
V_346 -> V_358 = 0 ;
}
}
V_355 = V_346 -> V_349 ;
F_273 ( & V_346 -> V_162 ) ;
V_25 -> V_356 += V_353 ;
if ( ( T_3 ) ( V_355 - V_25 -> V_349 ) > 0 )
V_25 -> V_349 = V_355 ;
return V_25 -> V_356 > 0 ;
}
static void F_274 ( struct V_25 * V_25 )
{
struct V_345 * V_346 = F_269 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_76 ( F_17 ( V_25 ) ) - V_25 -> V_349 ) < 0 ) )
return;
if ( V_25 -> V_356 < 0 )
return;
if ( V_25 -> V_349 != V_346 -> V_349 ) {
V_25 -> V_349 += V_252 ;
} else {
V_25 -> V_356 = 0 ;
}
}
static void F_275 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_356 -= V_19 ;
F_274 ( V_25 ) ;
if ( F_12 ( V_25 -> V_356 > 0 ) )
return;
if ( ! F_270 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_248 ( F_17 ( V_25 ) ) ;
}
static T_9
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_257 () || ! V_25 -> V_359 )
return;
F_275 ( V_25 , V_19 ) ;
}
static inline int F_276 ( struct V_25 * V_25 )
{
return F_257 () && V_25 -> V_360 ;
}
static inline int F_202 ( struct V_25 * V_25 )
{
return F_257 () && V_25 -> V_350 ;
}
static inline int F_277 ( struct V_269 * V_33 ,
int V_158 , int V_361 )
{
struct V_25 * V_362 , * V_363 ;
V_362 = V_33 -> V_25 [ V_158 ] ;
V_363 = V_33 -> V_25 [ V_361 ] ;
return F_202 ( V_362 ) ||
F_202 ( V_363 ) ;
}
static int F_278 ( struct V_269 * V_33 , void * V_364 )
{
struct V_24 * V_24 = V_364 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_350 -- ;
#ifdef F_194
if ( ! V_25 -> V_350 ) {
V_25 -> V_352 += F_66 ( V_24 ) -
V_25 -> V_351 ;
}
#endif
return 0 ;
}
static int F_279 ( struct V_269 * V_33 , void * V_364 )
{
struct V_24 * V_24 = V_364 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_350 )
V_25 -> V_351 = F_66 ( V_24 ) ;
V_25 -> V_350 ++ ;
return 0 ;
}
static void F_280 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_345 * V_346 = F_269 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_365 , V_366 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_120 () ;
F_281 ( V_25 -> V_33 , F_279 , V_367 , ( void * ) V_24 ) ;
F_128 () ;
V_365 = V_25 -> V_368 ;
F_61 (se) {
struct V_25 * V_369 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_366 )
F_245 ( V_369 , V_28 , V_330 ) ;
V_369 -> V_368 -= V_365 ;
if ( V_369 -> V_70 . V_4 )
V_366 = 0 ;
}
if ( ! V_28 )
F_282 ( V_24 , V_365 ) ;
V_25 -> V_360 = 1 ;
V_25 -> V_370 = F_76 ( V_24 ) ;
F_271 ( & V_346 -> V_162 ) ;
F_28 ( & V_25 -> V_371 , & V_346 -> V_372 ) ;
if ( ! V_346 -> V_357 )
F_272 ( V_346 , false ) ;
F_273 ( & V_346 -> V_162 ) ;
}
void F_283 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_345 * V_346 = F_269 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_373 = 1 ;
long V_365 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_360 = 0 ;
F_284 ( V_24 ) ;
F_271 ( & V_346 -> V_162 ) ;
V_346 -> V_374 += F_76 ( V_24 ) - V_25 -> V_370 ;
F_32 ( & V_25 -> V_371 ) ;
F_273 ( & V_346 -> V_162 ) ;
F_281 ( V_25 -> V_33 , V_367 , F_278 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_365 = V_25 -> V_368 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_373 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_373 )
F_239 ( V_25 , V_28 , V_327 ) ;
V_25 -> V_368 += V_365 ;
if ( F_276 ( V_25 ) )
break;
}
if ( ! V_28 )
F_285 ( V_24 , V_365 ) ;
if ( V_24 -> V_45 == V_24 -> V_358 && V_24 -> V_40 . V_72 )
F_248 ( V_24 ) ;
}
static T_2 F_286 ( struct V_345 * V_346 ,
T_2 V_375 , T_2 V_355 )
{
struct V_25 * V_25 ;
T_2 V_194 ;
T_2 V_376 = V_375 ;
F_120 () ;
F_287 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_271 ( & V_24 -> V_162 ) ;
if ( ! F_276 ( V_25 ) )
goto V_58;
V_194 = - V_25 -> V_356 + 1 ;
if ( V_194 > V_375 )
V_194 = V_375 ;
V_375 -= V_194 ;
V_25 -> V_356 += V_194 ;
V_25 -> V_349 = V_355 ;
if ( V_25 -> V_356 > 0 )
F_283 ( V_25 ) ;
V_58:
F_273 ( & V_24 -> V_162 ) ;
if ( ! V_375 )
break;
}
F_128 () ;
return V_376 - V_375 ;
}
static int F_288 ( struct V_345 * V_346 , int V_377 )
{
T_2 V_194 , V_349 ;
int V_360 ;
if ( V_346 -> V_347 == V_348 )
goto V_378;
V_360 = ! F_289 ( & V_346 -> V_372 ) ;
V_346 -> V_379 += V_377 ;
if ( V_346 -> V_358 && ! V_360 )
goto V_378;
V_346 -> V_357 = 1 ;
F_265 ( V_346 ) ;
if ( ! V_360 ) {
V_346 -> V_358 = 1 ;
return 0 ;
}
V_346 -> V_380 += V_377 ;
V_349 = V_346 -> V_349 ;
while ( V_360 && V_346 -> V_194 > 0 ) {
V_194 = V_346 -> V_194 ;
F_273 ( & V_346 -> V_162 ) ;
V_194 = F_286 ( V_346 , V_194 ,
V_349 ) ;
F_271 ( & V_346 -> V_162 ) ;
V_360 = ! F_289 ( & V_346 -> V_372 ) ;
V_346 -> V_194 -= F_140 ( V_194 , V_346 -> V_194 ) ;
}
V_346 -> V_358 = 0 ;
return 0 ;
V_378:
V_346 -> V_357 = 0 ;
return 1 ;
}
static int F_290 ( struct V_345 * V_346 , T_2 V_381 )
{
struct V_382 * V_383 = & V_346 -> V_384 ;
T_2 V_375 ;
if ( F_291 ( V_383 ) )
return 1 ;
V_375 = F_268 ( F_292 ( V_383 ) ) ;
if ( V_375 < V_381 )
return 1 ;
return 0 ;
}
static void F_293 ( struct V_345 * V_346 )
{
T_2 V_385 = V_386 + V_387 ;
if ( F_290 ( V_346 , V_385 ) )
return;
F_294 ( & V_346 -> V_388 ,
F_295 ( V_386 ) ) ;
}
static void F_296 ( struct V_25 * V_25 )
{
struct V_345 * V_346 = F_269 ( V_25 -> V_33 ) ;
T_3 V_389 = V_25 -> V_356 - V_390 ;
if ( V_389 <= 0 )
return;
F_271 ( & V_346 -> V_162 ) ;
if ( V_346 -> V_347 != V_348 &&
V_25 -> V_349 == V_346 -> V_349 ) {
V_346 -> V_194 += V_389 ;
if ( V_346 -> V_194 > F_264 () &&
! F_289 ( & V_346 -> V_372 ) )
F_293 ( V_346 ) ;
}
F_273 ( & V_346 -> V_162 ) ;
V_25 -> V_356 -= V_389 ;
}
static T_9 void F_246 ( struct V_25 * V_25 )
{
if ( ! F_257 () )
return;
if ( ! V_25 -> V_359 || V_25 -> V_72 )
return;
F_296 ( V_25 ) ;
}
static void F_297 ( struct V_345 * V_346 )
{
T_2 V_194 = 0 , V_75 = F_264 () ;
T_2 V_355 ;
F_271 ( & V_346 -> V_162 ) ;
if ( F_290 ( V_346 , V_387 ) ) {
F_273 ( & V_346 -> V_162 ) ;
return;
}
if ( V_346 -> V_347 != V_348 && V_346 -> V_194 > V_75 )
V_194 = V_346 -> V_194 ;
V_355 = V_346 -> V_349 ;
F_273 ( & V_346 -> V_162 ) ;
if ( ! V_194 )
return;
V_194 = F_286 ( V_346 , V_194 , V_355 ) ;
F_271 ( & V_346 -> V_162 ) ;
if ( V_355 == V_346 -> V_349 )
V_346 -> V_194 -= F_140 ( V_194 , V_346 -> V_194 ) ;
F_273 ( & V_346 -> V_162 ) ;
}
static void F_240 ( struct V_25 * V_25 )
{
if ( ! F_257 () )
return;
if ( ! V_25 -> V_359 || V_25 -> V_45 )
return;
if ( F_276 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_356 <= 0 )
F_280 ( V_25 ) ;
}
static bool F_253 ( struct V_25 * V_25 )
{
if ( ! F_257 () )
return false ;
if ( F_12 ( ! V_25 -> V_359 || V_25 -> V_356 > 0 ) )
return false ;
if ( F_276 ( V_25 ) )
return true ;
F_280 ( V_25 ) ;
return true ;
}
static enum V_391 F_298 ( struct V_382 * V_392 )
{
struct V_345 * V_346 =
F_22 ( V_392 , struct V_345 , V_388 ) ;
F_297 ( V_346 ) ;
return V_393 ;
}
static enum V_391 F_299 ( struct V_382 * V_392 )
{
struct V_345 * V_346 =
F_22 ( V_392 , struct V_345 , V_384 ) ;
T_10 V_81 ;
int V_377 ;
int V_358 = 0 ;
F_271 ( & V_346 -> V_162 ) ;
for (; ; ) {
V_81 = F_300 ( V_392 ) ;
V_377 = F_301 ( V_392 , V_81 , V_346 -> V_73 ) ;
if ( ! V_377 )
break;
V_358 = F_288 ( V_346 , V_377 ) ;
}
F_273 ( & V_346 -> V_162 ) ;
return V_358 ? V_393 : V_394 ;
}
void F_302 ( struct V_345 * V_346 )
{
F_303 ( & V_346 -> V_162 ) ;
V_346 -> V_194 = 0 ;
V_346 -> V_347 = V_348 ;
V_346 -> V_73 = F_295 ( F_263 () ) ;
F_162 ( & V_346 -> V_372 ) ;
F_304 ( & V_346 -> V_384 , V_395 , V_396 ) ;
V_346 -> V_384 . V_397 = F_299 ;
F_304 ( & V_346 -> V_388 , V_395 , V_396 ) ;
V_346 -> V_388 . V_397 = F_298 ;
}
static void F_305 ( struct V_25 * V_25 )
{
V_25 -> V_359 = 0 ;
F_162 ( & V_25 -> V_371 ) ;
}
void F_272 ( struct V_345 * V_346 , bool V_398 )
{
while ( F_14 ( F_256 ( & V_346 -> V_384 ) ) &&
F_306 ( & V_346 -> V_384 ) < 0 ) {
F_273 ( & V_346 -> V_162 ) ;
F_307 () ;
F_271 ( & V_346 -> V_162 ) ;
if ( ! V_398 && V_346 -> V_357 )
return;
}
V_346 -> V_357 = 1 ;
F_294 ( & V_346 -> V_384 , V_346 -> V_73 ) ;
}
static void F_308 ( struct V_345 * V_346 )
{
F_309 ( & V_346 -> V_384 ) ;
F_309 ( & V_346 -> V_388 ) ;
}
static void T_11 F_310 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_311 (rq, cfs_rq) {
struct V_345 * V_346 = & V_25 -> V_33 -> V_345 ;
F_271 ( & V_346 -> V_162 ) ;
V_25 -> V_359 = V_346 -> V_347 != V_348 ;
F_273 ( & V_346 -> V_162 ) ;
}
}
static void T_11 F_312 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_311 (rq, cfs_rq) {
if ( ! V_25 -> V_359 )
continue;
V_25 -> V_356 = 1 ;
V_25 -> V_359 = 0 ;
if ( F_276 ( V_25 ) )
F_283 ( V_25 ) ;
}
}
static inline T_2 F_220 ( struct V_25 * V_25 )
{
return F_66 ( F_17 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_253 ( struct V_25 * V_25 ) { return false ; }
static void F_240 ( struct V_25 * V_25 ) {}
static T_9 void F_246 ( struct V_25 * V_25 ) {}
static inline int F_276 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_202 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_277 ( struct V_269 * V_33 ,
int V_158 , int V_361 )
{
return 0 ;
}
void F_302 ( struct V_345 * V_346 ) {}
static void F_305 ( struct V_25 * V_25 ) {}
static inline struct V_345 * F_269 ( struct V_269 * V_33 )
{
return NULL ;
}
static inline void F_308 ( struct V_345 * V_346 ) {}
static inline void F_310 ( struct V_24 * V_24 ) {}
static inline void F_312 ( struct V_24 * V_24 ) {}
static void F_313 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_314 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_399 = V_28 -> V_85 - V_28 -> V_335 ;
T_3 V_42 = V_75 - V_399 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_248 ( V_24 ) ;
return;
}
F_315 ( V_24 , V_42 ) ;
}
}
static void F_316 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_317 ( V_24 ) || V_45 -> V_400 != & V_401 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_313 ( V_24 , V_45 ) ;
}
static inline void
F_313 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_316 ( struct V_24 * V_24 )
{
}
static void
F_318 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_163 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_239 ( V_25 , V_28 , V_163 ) ;
if ( F_276 ( V_25 ) )
break;
V_25 -> V_368 ++ ;
V_163 = V_327 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_368 ++ ;
if ( F_276 ( V_25 ) )
break;
F_201 ( V_25 ) ;
F_219 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_215 ( V_24 , V_24 -> V_72 ) ;
F_285 ( V_24 , 1 ) ;
}
F_316 ( V_24 ) ;
}
static void F_319 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_163 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_402 = V_163 & V_330 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_245 ( V_25 , V_28 , V_163 ) ;
if ( F_276 ( V_25 ) )
break;
V_25 -> V_368 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_402 && F_34 ( V_28 ) )
F_320 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_163 |= V_330 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_368 -- ;
if ( F_276 ( V_25 ) )
break;
F_201 ( V_25 ) ;
F_219 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_282 ( V_24 , 1 ) ;
F_215 ( V_24 , 1 ) ;
}
F_316 ( V_24 ) ;
}
static unsigned long F_111 ( const int V_132 )
{
return F_110 ( V_132 ) -> V_40 . V_297 ;
}
static unsigned long F_321 ( int V_132 , int type )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
unsigned long V_403 = F_111 ( V_132 ) ;
if ( type == 0 || ! F_238 ( V_404 ) )
return V_403 ;
return F_140 ( V_24 -> V_405 [ type - 1 ] , V_403 ) ;
}
static unsigned long F_322 ( int V_132 , int type )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
unsigned long V_403 = F_111 ( V_132 ) ;
if ( type == 0 || ! F_238 ( V_404 ) )
return V_403 ;
return F_68 ( V_24 -> V_405 [ type - 1 ] , V_403 ) ;
}
static unsigned long F_112 ( int V_132 )
{
return F_110 ( V_132 ) -> V_406 ;
}
static unsigned long F_323 ( int V_132 )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
unsigned long V_72 = F_87 ( V_24 -> V_40 . V_368 ) ;
unsigned long V_271 = V_24 -> V_40 . V_297 ;
if ( V_72 )
return V_271 / V_72 ;
return 0 ;
}
static void F_324 ( struct V_26 * V_29 )
{
if ( F_177 ( V_179 , V_126 -> V_407 + V_177 ) ) {
V_126 -> V_408 >>= 1 ;
V_126 -> V_407 = V_179 ;
}
if ( V_126 -> V_409 != V_29 ) {
V_126 -> V_409 = V_29 ;
V_126 -> V_408 ++ ;
}
}
static void F_325 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_326 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_324 ( V_29 ) ;
}
static long F_327 ( struct V_269 * V_33 , int V_132 , long V_410 , long V_411 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_132 ] ;
if ( ! V_33 -> V_34 )
return V_410 ;
F_61 (se) {
long V_7 , V_412 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_412 = V_411 + F_197 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_410 ;
if ( V_412 > 0 && V_7 < V_412 )
V_410 = ( V_7 * V_33 -> V_273 ) / V_412 ;
else
V_410 = V_33 -> V_273 ;
if ( V_410 < V_274 )
V_410 = V_274 ;
V_410 -= V_28 -> V_70 . V_4 ;
V_411 = 0 ;
}
return V_410 ;
}
static long F_327 ( struct V_269 * V_33 , int V_132 , long V_410 , long V_411 )
{
return V_410 ;
}
static int F_328 ( struct V_26 * V_29 )
{
int V_9 = F_329 ( V_413 ) ;
if ( V_29 -> V_408 > V_9 ) {
if ( V_126 -> V_408 > ( V_9 * V_29 -> V_408 ) )
return 1 ;
}
return 0 ;
}
static int F_330 ( struct V_168 * V_169 , struct V_26 * V_29 , int V_414 )
{
T_3 V_415 , V_70 ;
T_3 V_416 , V_417 ;
int V_418 , V_419 , V_420 ;
struct V_269 * V_33 ;
unsigned long V_4 ;
int V_421 ;
if ( F_328 ( V_29 ) )
return 0 ;
V_418 = V_169 -> V_422 ;
V_419 = F_267 () ;
V_420 = F_131 ( V_29 ) ;
V_70 = F_321 ( V_420 , V_418 ) ;
V_415 = F_322 ( V_419 , V_418 ) ;
if ( V_414 ) {
V_33 = V_269 ( V_126 ) ;
V_4 = V_126 -> V_28 . V_70 . V_4 ;
V_415 += F_327 ( V_33 , V_419 , - V_4 , - V_4 ) ;
V_70 += F_327 ( V_33 , V_420 , 0 , - V_4 ) ;
}
V_33 = V_269 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
V_416 = 100 ;
V_416 *= F_112 ( V_420 ) ;
V_417 = 100 + ( V_169 -> V_154 - 100 ) / 2 ;
V_417 *= F_112 ( V_419 ) ;
if ( V_415 > 0 ) {
V_416 *= V_415 +
F_327 ( V_33 , V_419 , V_4 , V_4 ) ;
V_417 *= V_70 + F_327 ( V_33 , V_420 , 0 , V_4 ) ;
}
V_421 = V_416 <= V_417 ;
F_236 ( V_29 , V_28 . V_83 . V_423 ) ;
if ( ! V_421 )
return 0 ;
F_236 ( V_169 , V_424 ) ;
F_236 ( V_29 , V_28 . V_83 . V_425 ) ;
return 1 ;
}
static struct V_426 *
F_331 ( struct V_168 * V_169 , struct V_26 * V_29 ,
int V_419 , int V_427 )
{
struct V_426 * V_428 = NULL , * V_115 = V_169 -> V_429 ;
unsigned long V_430 = V_431 , V_415 = 0 ;
int V_432 = V_169 -> V_433 ;
int V_434 = 100 + ( V_169 -> V_154 - 100 ) / 2 ;
if ( V_427 & V_435 )
V_432 = V_169 -> V_422 ;
do {
unsigned long V_70 , V_436 ;
int V_437 ;
int V_204 ;
if ( ! F_332 ( F_333 ( V_115 ) ,
F_125 ( V_29 ) ) )
continue;
V_437 = F_124 ( V_419 ,
F_333 ( V_115 ) ) ;
V_436 = 0 ;
F_109 (i, sched_group_cpus(group)) {
if ( V_437 )
V_70 = F_321 ( V_204 , V_432 ) ;
else
V_70 = F_322 ( V_204 , V_432 ) ;
V_436 += V_70 ;
}
V_436 = ( V_436 * V_135 ) / V_115 -> V_438 -> V_133 ;
if ( V_437 ) {
V_415 = V_436 ;
} else if ( V_436 < V_430 ) {
V_430 = V_436 ;
V_428 = V_115 ;
}
} while ( V_115 = V_115 -> V_58 , V_115 != V_169 -> V_429 );
if ( ! V_428 || 100 * V_415 < V_434 * V_430 )
return NULL ;
return V_428 ;
}
static int
F_334 ( struct V_426 * V_115 , struct V_26 * V_29 , int V_419 )
{
unsigned long V_70 , V_430 = V_431 ;
unsigned int V_439 = V_440 ;
T_2 V_441 = 0 ;
int V_442 = V_419 ;
int V_443 = - 1 ;
int V_204 ;
F_335 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_336 ( V_204 ) ) {
struct V_24 * V_24 = F_110 ( V_204 ) ;
struct V_444 * V_358 = F_337 ( V_24 ) ;
if ( V_358 && V_358 -> V_445 < V_439 ) {
V_439 = V_358 -> V_445 ;
V_441 = V_24 -> V_446 ;
V_443 = V_204 ;
} else if ( ( ! V_358 || V_358 -> V_445 == V_439 ) &&
V_24 -> V_446 > V_441 ) {
V_441 = V_24 -> V_446 ;
V_443 = V_204 ;
}
} else {
V_70 = F_111 ( V_204 ) ;
if ( V_70 < V_430 || ( V_70 == V_430 && V_204 == V_419 ) ) {
V_430 = V_70 ;
V_442 = V_204 ;
}
}
}
return V_443 != - 1 ? V_443 : V_442 ;
}
static int F_127 ( struct V_26 * V_29 , int V_447 )
{
struct V_168 * V_169 ;
struct V_426 * V_448 ;
int V_204 = F_131 ( V_29 ) ;
if ( F_336 ( V_447 ) )
return V_447 ;
if ( V_204 != V_447 && F_338 ( V_204 , V_447 ) && F_336 ( V_204 ) )
return V_204 ;
V_169 = F_132 ( F_133 ( V_449 , V_447 ) ) ;
F_339 (sd) {
V_448 = V_169 -> V_429 ;
do {
if ( ! F_332 ( F_333 ( V_448 ) ,
F_125 ( V_29 ) ) )
goto V_58;
F_109 (i, sched_group_cpus(sg)) {
if ( V_204 == V_447 || ! F_336 ( V_204 ) )
goto V_58;
}
V_447 = F_340 ( F_333 ( V_448 ) ,
F_125 ( V_29 ) ) ;
goto V_450;
V_58:
V_448 = V_448 -> V_58 ;
} while ( V_448 != V_169 -> V_429 );
}
V_450:
return V_447 ;
}
static int
F_341 ( struct V_26 * V_29 , int V_420 , int V_427 , int V_451 )
{
struct V_168 * V_452 , * V_453 = NULL , * V_169 = NULL ;
int V_132 = F_267 () ;
int V_454 = V_132 ;
int V_455 = 0 ;
int V_414 = V_451 & V_456 ;
if ( V_29 -> V_457 == 1 )
return V_420 ;
if ( V_427 & V_435 )
V_455 = F_124 ( V_132 , F_125 ( V_29 ) ) ;
F_120 () ;
F_342 (cpu, tmp) {
if ( ! ( V_452 -> V_163 & V_458 ) )
continue;
if ( V_455 && ( V_452 -> V_163 & V_459 ) &&
F_124 ( V_420 , F_343 ( V_452 ) ) ) {
V_453 = V_452 ;
break;
}
if ( V_452 -> V_163 & V_427 )
V_169 = V_452 ;
}
if ( V_453 && V_132 != V_420 && F_330 ( V_453 , V_29 , V_414 ) )
V_420 = V_132 ;
if ( V_427 & V_435 ) {
V_454 = F_127 ( V_29 , V_420 ) ;
goto V_165;
}
while ( V_169 ) {
struct V_426 * V_115 ;
int V_4 ;
if ( ! ( V_169 -> V_163 & V_427 ) ) {
V_169 = V_169 -> V_460 ;
continue;
}
V_115 = F_331 ( V_169 , V_29 , V_132 , V_427 ) ;
if ( ! V_115 ) {
V_169 = V_169 -> V_460 ;
continue;
}
V_454 = F_334 ( V_115 , V_29 , V_132 ) ;
if ( V_454 == - 1 || V_454 == V_132 ) {
V_169 = V_169 -> V_460 ;
continue;
}
V_132 = V_454 ;
V_4 = V_169 -> V_461 ;
V_169 = NULL ;
F_342 (cpu, tmp) {
if ( V_4 <= V_452 -> V_461 )
break;
if ( V_452 -> V_163 & V_427 )
V_169 = V_452 ;
}
}
V_165:
F_128 () ;
return V_454 ;
}
static void
F_344 ( struct V_26 * V_29 , int V_462 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_206 ( V_28 ) ;
F_209 ( V_28 -> V_77 . V_294 ,
& V_25 -> V_307 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_345 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_463 = V_464 ;
return F_58 ( V_463 , V_28 ) ;
}
static int
F_251 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_463 , V_465 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_465 <= 0 )
return - 1 ;
V_463 = F_345 ( V_45 , V_28 ) ;
if ( V_465 > V_463 )
return 1 ;
return 0 ;
}
static void F_346 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_466 == V_467 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_320 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_466 == V_467 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_347 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_329 = V_28 ;
}
static void F_348 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_451 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_468 = V_25 -> V_72 >= V_67 ;
int V_469 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_202 ( F_24 ( V_36 ) ) ) )
return;
if ( F_238 ( V_470 ) && V_468 && ! ( V_451 & V_471 ) ) {
F_320 ( V_36 ) ;
V_469 = 1 ;
}
if ( F_349 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_466 == V_467 ) &&
F_12 ( V_29 -> V_466 != V_467 ) )
goto V_472;
if ( F_14 ( V_29 -> V_466 != V_473 ) || ! F_238 ( V_474 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_165 ( ! V_36 ) ;
if ( F_251 ( V_28 , V_36 ) == 1 ) {
if ( ! V_469 )
F_320 ( V_36 ) ;
goto V_472;
}
return;
V_472:
F_248 ( V_24 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_358 ) )
return;
if ( F_238 ( V_475 ) && V_468 && F_21 ( V_28 ) )
F_346 ( V_28 ) ;
}
static struct V_26 *
F_350 ( struct V_24 * V_24 , struct V_26 * V_338 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_476 ;
V_477:
#ifdef F_351
if ( ! V_25 -> V_72 )
goto V_358;
if ( V_338 -> V_400 != & V_401 )
goto V_478;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_253 ( V_25 ) ) )
goto V_478;
V_28 = F_250 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_338 != V_29 ) {
struct V_27 * V_36 = & V_338 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_252 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_249 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_252 ( V_25 , V_36 ) ;
F_249 ( V_25 , V_28 ) ;
}
if ( F_317 ( V_24 ) )
F_313 ( V_24 , V_29 ) ;
return V_29 ;
V_478:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_358;
F_352 ( V_24 , V_338 ) ;
do {
V_28 = F_250 ( V_25 , NULL ) ;
F_249 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_317 ( V_24 ) )
F_313 ( V_24 , V_29 ) ;
return V_29 ;
V_358:
V_476 = F_227 ( V_24 ) ;
if ( V_476 < 0 )
return V_479 ;
if ( V_476 > 0 )
goto V_477;
return NULL ;
}
static void F_353 ( struct V_24 * V_24 , struct V_26 * V_338 )
{
struct V_27 * V_28 = & V_338 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_252 ( V_25 , V_28 ) ;
}
}
static void F_354 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_244 ( V_25 , V_28 ) ;
if ( V_45 -> V_466 != V_480 ) {
F_284 ( V_24 ) ;
F_65 ( V_25 ) ;
V_24 -> V_481 = 1 ;
}
F_347 ( V_28 ) ;
}
static bool F_355 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_472 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_202 ( F_24 ( V_28 ) ) )
return false ;
F_320 ( V_28 ) ;
F_354 ( V_24 ) ;
return true ;
}
static int F_356 ( struct V_26 * V_29 , struct V_482 * V_139 )
{
T_3 V_42 ;
F_357 ( & V_139 -> V_157 -> V_162 ) ;
if ( V_29 -> V_400 != & V_401 )
return 0 ;
if ( F_14 ( V_29 -> V_466 == V_467 ) )
return 0 ;
if ( F_238 ( V_483 ) && V_139 -> V_159 -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_484 == - 1 )
return 1 ;
if ( V_484 == 0 )
return 0 ;
V_42 = F_66 ( V_139 -> V_157 ) - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_484 ;
}
static bool F_358 ( struct V_26 * V_29 , struct V_482 * V_139 )
{
struct V_108 * V_108 = F_132 ( V_29 -> V_108 ) ;
int V_120 , V_123 ;
if ( ! F_238 ( V_485 ) || ! V_29 -> V_113 ||
! ( V_139 -> V_169 -> V_163 & V_486 ) ) {
return false ;
}
V_120 = F_101 ( V_139 -> V_158 ) ;
V_123 = F_101 ( V_139 -> V_121 ) ;
if ( V_120 == V_123 )
return false ;
if ( V_108 ) {
if ( F_107 ( V_120 , V_108 -> V_128 ) )
return false ;
if ( F_107 ( V_123 , V_108 -> V_128 ) )
return true ;
return F_96 ( V_29 , V_123 ) > F_96 ( V_29 , V_120 ) ;
}
if ( V_123 == V_29 -> V_106 )
return true ;
return F_95 ( V_29 , V_123 ) > F_95 ( V_29 , V_120 ) ;
}
static bool F_359 ( struct V_26 * V_29 , struct V_482 * V_139 )
{
struct V_108 * V_108 = F_132 ( V_29 -> V_108 ) ;
int V_120 , V_123 ;
if ( ! F_238 ( V_487 ) || ! F_238 ( V_488 ) )
return false ;
if ( ! V_29 -> V_113 || ! ( V_139 -> V_169 -> V_163 & V_486 ) )
return false ;
V_120 = F_101 ( V_139 -> V_158 ) ;
V_123 = F_101 ( V_139 -> V_121 ) ;
if ( V_120 == V_123 )
return false ;
if ( V_108 ) {
if ( F_107 ( V_123 , V_108 -> V_128 ) )
return false ;
if ( F_107 ( V_120 , V_108 -> V_128 ) )
return true ;
return F_96 ( V_29 , V_123 ) < F_96 ( V_29 , V_120 ) ;
}
if ( V_120 == V_29 -> V_106 )
return true ;
return F_95 ( V_29 , V_123 ) < F_95 ( V_29 , V_120 ) ;
}
static inline bool F_358 ( struct V_26 * V_29 ,
struct V_482 * V_139 )
{
return false ;
}
static inline bool F_359 ( struct V_26 * V_29 ,
struct V_482 * V_139 )
{
return false ;
}
static
int F_360 ( struct V_26 * V_29 , struct V_482 * V_139 )
{
int V_489 = 0 ;
F_357 ( & V_139 -> V_157 -> V_162 ) ;
if ( F_277 ( V_269 ( V_29 ) , V_139 -> V_158 , V_139 -> V_121 ) )
return 0 ;
if ( ! F_124 ( V_139 -> V_121 , F_125 ( V_29 ) ) ) {
int V_132 ;
F_236 ( V_29 , V_28 . V_83 . V_490 ) ;
V_139 -> V_163 |= V_491 ;
if ( ! V_139 -> V_492 || ( V_139 -> V_163 & V_493 ) )
return 0 ;
F_335 (cpu, env->dst_grpmask, env->cpus) {
if ( F_124 ( V_132 , F_125 ( V_29 ) ) ) {
V_139 -> V_163 |= V_493 ;
V_139 -> V_494 = V_132 ;
break;
}
}
return 0 ;
}
V_139 -> V_163 &= ~ V_495 ;
if ( F_361 ( V_139 -> V_157 , V_29 ) ) {
F_236 ( V_29 , V_28 . V_83 . V_496 ) ;
return 0 ;
}
V_489 = F_356 ( V_29 , V_139 ) ;
if ( ! V_489 )
V_489 = F_359 ( V_29 , V_139 ) ;
if ( F_358 ( V_29 , V_139 ) || ! V_489 ||
V_139 -> V_169 -> V_497 > V_139 -> V_169 -> V_498 ) {
if ( V_489 ) {
F_236 ( V_139 -> V_169 , V_499 [ V_139 -> V_358 ] ) ;
F_236 ( V_29 , V_28 . V_83 . V_500 ) ;
}
return 1 ;
}
F_236 ( V_29 , V_28 . V_83 . V_501 ) ;
return 0 ;
}
static void F_362 ( struct V_26 * V_29 , struct V_482 * V_139 )
{
F_357 ( & V_139 -> V_157 -> V_162 ) ;
F_363 ( V_139 -> V_157 , V_29 , 0 ) ;
V_29 -> V_76 = V_502 ;
F_364 ( V_29 , V_139 -> V_121 ) ;
}
static struct V_26 * F_365 ( struct V_482 * V_139 )
{
struct V_26 * V_29 , * V_276 ;
F_357 ( & V_139 -> V_157 -> V_162 ) ;
F_366 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_360 ( V_29 , V_139 ) )
continue;
F_362 ( V_29 , V_139 ) ;
F_236 ( V_139 -> V_169 , V_503 [ V_139 -> V_358 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_367 ( struct V_482 * V_139 )
{
struct V_504 * V_505 = & V_139 -> V_157 -> V_268 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_506 = 0 ;
F_357 ( & V_139 -> V_157 -> V_162 ) ;
if ( V_139 -> V_434 <= 0 )
return 0 ;
while ( ! F_289 ( V_505 ) ) {
V_29 = F_368 ( V_505 , struct V_26 , V_28 . V_267 ) ;
V_139 -> V_507 ++ ;
if ( V_139 -> V_507 > V_139 -> V_508 )
break;
if ( V_139 -> V_507 > V_139 -> V_509 ) {
V_139 -> V_509 += V_510 ;
V_139 -> V_163 |= V_511 ;
break;
}
if ( ! F_360 ( V_29 , V_139 ) )
goto V_58;
V_70 = F_126 ( V_29 ) ;
if ( F_238 ( V_512 ) && V_70 < 16 && ! V_139 -> V_169 -> V_497 )
goto V_58;
if ( ( V_70 / 2 ) > V_139 -> V_434 )
goto V_58;
F_362 ( V_29 , V_139 ) ;
F_163 ( & V_29 -> V_28 . V_267 , & V_139 -> V_505 ) ;
V_506 ++ ;
V_139 -> V_434 -= V_70 ;
#ifdef F_369
if ( V_139 -> V_358 == V_513 )
break;
#endif
if ( V_139 -> V_434 <= 0 )
break;
continue;
V_58:
F_370 ( & V_29 -> V_28 . V_267 , V_505 ) ;
}
F_69 ( V_139 -> V_169 , V_503 [ V_139 -> V_358 ] , V_506 ) ;
return V_506 ;
}
static void F_371 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_357 ( & V_24 -> V_162 ) ;
F_165 ( F_36 ( V_29 ) != V_24 ) ;
V_29 -> V_76 = V_514 ;
F_372 ( V_24 , V_29 , 0 ) ;
F_373 ( V_24 , V_29 , 0 ) ;
}
static void F_374 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_271 ( & V_24 -> V_162 ) ;
F_371 ( V_24 , V_29 ) ;
F_273 ( & V_24 -> V_162 ) ;
}
static void F_375 ( struct V_482 * V_139 )
{
struct V_504 * V_505 = & V_139 -> V_505 ;
struct V_26 * V_29 ;
F_271 ( & V_139 -> V_159 -> V_162 ) ;
while ( ! F_289 ( V_505 ) ) {
V_29 = F_368 ( V_505 , struct V_26 , V_28 . V_267 ) ;
F_196 ( & V_29 -> V_28 . V_267 ) ;
F_371 ( V_139 -> V_159 , V_29 ) ;
}
F_273 ( & V_139 -> V_159 -> V_162 ) ;
}
static void F_376 ( struct V_269 * V_33 , int V_132 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_132 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_132 ] ;
if ( F_202 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_219 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_215 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_377 ( int V_132 )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
struct V_25 * V_25 ;
unsigned long V_163 ;
F_378 ( & V_24 -> V_162 , V_163 ) ;
F_284 ( V_24 ) ;
F_311 (rq, cfs_rq) {
F_376 ( V_25 -> V_33 , V_24 -> V_132 ) ;
}
F_379 ( & V_24 -> V_162 , V_163 ) ;
}
static void F_380 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_179 ;
unsigned long V_70 ;
if ( V_25 -> V_515 == V_81 )
return;
V_25 -> V_516 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_516 = V_28 ;
if ( V_25 -> V_515 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_517 = V_25 -> V_297 ;
V_25 -> V_515 = V_81 ;
}
while ( ( V_28 = V_25 -> V_516 ) != NULL ) {
V_70 = V_25 -> V_517 ;
V_70 = F_381 ( V_70 * V_28 -> V_77 . V_294 ,
V_25 -> V_297 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_517 = V_70 ;
V_25 -> V_515 = V_81 ;
}
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_380 ( V_25 ) ;
return F_381 ( V_29 -> V_28 . V_77 . V_294 * V_25 -> V_517 ,
V_25 -> V_297 + 1 ) ;
}
static inline void F_377 ( int V_132 )
{
}
static unsigned long F_126 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_294 ;
}
static inline void F_382 ( struct V_518 * V_519 )
{
* V_519 = (struct V_518 ) {
. V_520 = NULL ,
. V_188 = NULL ,
. V_521 = 0UL ,
. V_522 = 0UL ,
. V_523 = {
. V_436 = 0UL ,
. V_524 = 0 ,
. V_525 = V_526 ,
} ,
} ;
}
static inline int F_383 ( struct V_168 * V_169 ,
enum V_527 V_358 )
{
int V_432 ;
switch ( V_358 ) {
case V_528 :
V_432 = V_169 -> V_529 ;
break;
case V_513 :
V_432 = V_169 -> V_530 ;
break;
default:
V_432 = V_169 -> V_531 ;
break;
}
return V_432 ;
}
static unsigned long F_384 ( struct V_168 * V_169 , int V_132 )
{
return V_135 ;
}
unsigned long __weak F_385 ( struct V_168 * V_169 , int V_132 )
{
return F_384 ( V_169 , V_132 ) ;
}
static unsigned long F_386 ( struct V_168 * V_169 , int V_132 )
{
if ( ( V_169 -> V_163 & V_532 ) && ( V_169 -> V_461 > 1 ) )
return V_169 -> V_533 / V_169 -> V_461 ;
return V_135 ;
}
unsigned long __weak F_387 ( struct V_168 * V_169 , int V_132 )
{
return F_386 ( V_169 , V_132 ) ;
}
static unsigned long F_388 ( int V_132 )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
T_2 V_403 , V_534 , V_535 , V_77 ;
T_3 V_42 ;
V_535 = F_87 ( V_24 -> V_535 ) ;
V_77 = F_87 ( V_24 -> V_536 ) ;
V_42 = F_76 ( V_24 ) - V_535 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_403 = F_389 () + V_42 ;
if ( F_14 ( V_403 < V_77 ) ) {
V_534 = 0 ;
} else {
V_534 = V_403 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_403 < V_135 ) )
V_403 = V_135 ;
V_403 >>= V_537 ;
return F_211 ( V_534 , V_403 ) ;
}
static void F_390 ( struct V_168 * V_169 , int V_132 )
{
unsigned long V_133 = V_135 ;
struct V_426 * V_538 = V_169 -> V_429 ;
if ( F_238 ( V_539 ) )
V_133 *= F_387 ( V_169 , V_132 ) ;
else
V_133 *= F_386 ( V_169 , V_132 ) ;
V_133 >>= V_537 ;
V_538 -> V_438 -> V_540 = V_133 ;
if ( F_238 ( V_539 ) )
V_133 *= F_385 ( V_169 , V_132 ) ;
else
V_133 *= F_384 ( V_169 , V_132 ) ;
V_133 >>= V_537 ;
V_133 *= F_388 ( V_132 ) ;
V_133 >>= V_537 ;
if ( ! V_133 )
V_133 = 1 ;
F_110 ( V_132 ) -> V_406 = V_133 ;
V_538 -> V_438 -> V_133 = V_133 ;
}
void F_391 ( struct V_168 * V_169 , int V_132 )
{
struct V_168 * V_460 = V_169 -> V_460 ;
struct V_426 * V_115 , * V_538 = V_169 -> V_429 ;
unsigned long V_133 , V_540 ;
unsigned long V_176 ;
V_176 = F_141 ( V_169 -> V_541 ) ;
V_176 = F_146 ( V_176 , 1UL , V_542 ) ;
V_538 -> V_438 -> V_543 = V_179 + V_176 ;
if ( ! V_460 ) {
F_390 ( V_169 , V_132 ) ;
return;
}
V_540 = V_133 = 0 ;
if ( V_460 -> V_163 & V_544 ) {
F_109 (cpu, sched_group_cpus(sdg)) {
struct V_545 * V_438 ;
struct V_24 * V_24 = F_110 ( V_132 ) ;
if ( F_14 ( ! V_24 -> V_169 ) ) {
V_540 += F_112 ( V_132 ) ;
V_133 += F_112 ( V_132 ) ;
continue;
}
V_438 = V_24 -> V_169 -> V_429 -> V_438 ;
V_540 += V_438 -> V_540 ;
V_133 += V_438 -> V_133 ;
}
} else {
V_115 = V_460 -> V_429 ;
do {
V_540 += V_115 -> V_438 -> V_540 ;
V_133 += V_115 -> V_438 -> V_133 ;
V_115 = V_115 -> V_58 ;
} while ( V_115 != V_460 -> V_429 );
}
V_538 -> V_438 -> V_540 = V_540 ;
V_538 -> V_438 -> V_133 = V_133 ;
}
static inline int
F_392 ( struct V_168 * V_169 , struct V_426 * V_115 )
{
if ( ! ( V_169 -> V_163 & V_532 ) )
return 0 ;
if ( V_115 -> V_438 -> V_133 * 32 > V_115 -> V_438 -> V_540 * 29 )
return 1 ;
return 0 ;
}
static inline int F_393 ( struct V_426 * V_115 )
{
return V_115 -> V_438 -> V_434 ;
}
static inline int F_394 ( struct V_482 * V_139 , struct V_426 * V_115 )
{
unsigned int V_546 , V_131 , V_8 ;
unsigned int V_133 , V_540 ;
V_133 = V_115 -> V_438 -> V_133 ;
V_540 = V_115 -> V_438 -> V_540 ;
V_8 = V_115 -> F_99 ;
V_131 = F_56 ( V_135 * V_8 , V_540 ) ;
V_546 = V_8 / V_131 ;
V_546 = F_5 ( unsigned ,
V_546 , F_113 ( V_133 , V_135 ) ) ;
if ( ! V_546 )
V_546 = F_392 ( V_139 -> V_169 , V_115 ) ;
return V_546 ;
}
static enum V_525
F_395 ( struct V_426 * V_115 , struct V_547 * V_548 )
{
if ( V_548 -> V_524 > V_548 -> V_549 )
return V_550 ;
if ( F_393 ( V_115 ) )
return V_551 ;
return V_526 ;
}
static inline void F_396 ( struct V_482 * V_139 ,
struct V_426 * V_115 , int V_432 ,
int V_437 , struct V_547 * V_548 ,
bool * V_552 )
{
unsigned long V_70 ;
int V_204 ;
memset ( V_548 , 0 , sizeof( * V_548 ) ) ;
F_335 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_110 ( V_204 ) ;
if ( V_437 )
V_70 = F_322 ( V_204 , V_432 ) ;
else
V_70 = F_321 ( V_204 , V_432 ) ;
V_548 -> V_553 += V_70 ;
V_548 -> V_524 += V_24 -> V_40 . V_368 ;
if ( V_24 -> V_72 > 1 )
* V_552 = true ;
#ifdef F_397
V_548 -> V_105 += V_24 -> V_105 ;
V_548 -> V_107 += V_24 -> V_107 ;
#endif
V_548 -> V_554 += F_111 ( V_204 ) ;
if ( F_336 ( V_204 ) )
V_548 -> V_555 ++ ;
}
V_548 -> V_556 = V_115 -> V_438 -> V_133 ;
V_548 -> V_436 = ( V_548 -> V_553 * V_135 ) / V_548 -> V_556 ;
if ( V_548 -> V_524 )
V_548 -> V_557 = V_548 -> V_554 / V_548 -> V_524 ;
V_548 -> F_99 = V_115 -> F_99 ;
V_548 -> V_549 = F_394 ( V_139 , V_115 ) ;
V_548 -> V_525 = F_395 ( V_115 , V_548 ) ;
if ( V_548 -> V_549 > V_548 -> V_524 )
V_548 -> V_558 = 1 ;
}
static bool F_398 ( struct V_482 * V_139 ,
struct V_518 * V_519 ,
struct V_426 * V_448 ,
struct V_547 * V_548 )
{
struct V_547 * V_520 = & V_519 -> V_523 ;
if ( V_548 -> V_525 > V_520 -> V_525 )
return true ;
if ( V_548 -> V_525 < V_520 -> V_525 )
return false ;
if ( V_548 -> V_436 <= V_520 -> V_436 )
return false ;
if ( ! ( V_139 -> V_169 -> V_163 & V_559 ) )
return true ;
if ( V_548 -> V_524 && V_139 -> V_121 < F_399 ( V_448 ) ) {
if ( ! V_519 -> V_520 )
return true ;
if ( F_399 ( V_519 -> V_520 ) > F_399 ( V_448 ) )
return true ;
}
return false ;
}
static inline enum V_560 F_400 ( struct V_547 * V_548 )
{
if ( V_548 -> V_524 > V_548 -> V_105 )
return V_561 ;
if ( V_548 -> V_524 > V_548 -> V_107 )
return V_186 ;
return V_562 ;
}
static inline enum V_560 F_401 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_105 )
return V_561 ;
if ( V_24 -> V_72 > V_24 -> V_107 )
return V_186 ;
return V_562 ;
}
static inline enum V_560 F_400 ( struct V_547 * V_548 )
{
return V_562 ;
}
static inline enum V_560 F_401 ( struct V_24 * V_24 )
{
return V_561 ;
}
static inline void F_402 ( struct V_482 * V_139 , struct V_518 * V_519 )
{
struct V_168 * V_460 = V_139 -> V_169 -> V_460 ;
struct V_426 * V_448 = V_139 -> V_169 -> V_429 ;
struct V_547 V_563 ;
int V_432 , V_564 = 0 ;
bool V_552 = false ;
if ( V_460 && V_460 -> V_163 & V_565 )
V_564 = 1 ;
V_432 = F_383 ( V_139 -> V_169 , V_139 -> V_358 ) ;
do {
struct V_547 * V_548 = & V_563 ;
int V_437 ;
V_437 = F_124 ( V_139 -> V_121 , F_333 ( V_448 ) ) ;
if ( V_437 ) {
V_519 -> V_188 = V_448 ;
V_548 = & V_519 -> V_566 ;
if ( V_139 -> V_358 != V_513 ||
F_403 ( V_179 , V_448 -> V_438 -> V_543 ) )
F_391 ( V_139 -> V_169 , V_139 -> V_121 ) ;
}
F_396 ( V_139 , V_448 , V_432 , V_437 , V_548 ,
& V_552 ) ;
if ( V_437 )
goto V_567;
if ( V_564 && V_519 -> V_188 &&
V_519 -> V_566 . V_558 )
V_548 -> V_549 = F_140 ( V_548 -> V_549 , 1U ) ;
if ( F_398 ( V_139 , V_519 , V_448 , V_548 ) ) {
V_519 -> V_520 = V_448 ;
V_519 -> V_523 = * V_548 ;
}
V_567:
V_519 -> V_521 += V_548 -> V_553 ;
V_519 -> V_522 += V_548 -> V_556 ;
V_448 = V_448 -> V_58 ;
} while ( V_448 != V_139 -> V_169 -> V_429 );
if ( V_139 -> V_169 -> V_163 & V_486 )
V_139 -> V_560 = F_400 ( & V_519 -> V_523 ) ;
if ( ! V_139 -> V_169 -> V_34 ) {
if ( V_139 -> V_159 -> V_568 -> V_552 != V_552 )
V_139 -> V_159 -> V_568 -> V_552 = V_552 ;
}
}
static int F_404 ( struct V_482 * V_139 , struct V_518 * V_519 )
{
int V_569 ;
if ( ! ( V_139 -> V_169 -> V_163 & V_559 ) )
return 0 ;
if ( ! V_519 -> V_520 )
return 0 ;
V_569 = F_399 ( V_519 -> V_520 ) ;
if ( V_139 -> V_121 > V_569 )
return 0 ;
V_139 -> V_434 = F_113 (
V_519 -> V_523 . V_436 * V_519 -> V_523 . V_556 ,
V_135 ) ;
return 1 ;
}
static inline
void F_405 ( struct V_482 * V_139 , struct V_518 * V_519 )
{
unsigned long V_452 , V_570 = 0 , V_571 = 0 ;
unsigned int V_572 = 2 ;
unsigned long V_573 ;
struct V_547 * V_188 , * V_520 ;
V_188 = & V_519 -> V_566 ;
V_520 = & V_519 -> V_523 ;
if ( ! V_188 -> V_524 )
V_188 -> V_557 = F_323 ( V_139 -> V_121 ) ;
else if ( V_520 -> V_557 > V_188 -> V_557 )
V_572 = 1 ;
V_573 =
( V_520 -> V_557 * V_135 ) /
V_520 -> V_556 ;
if ( V_520 -> V_436 + V_573 >=
V_188 -> V_436 + ( V_573 * V_572 ) ) {
V_139 -> V_434 = V_520 -> V_557 ;
return;
}
V_570 += V_520 -> V_556 *
F_140 ( V_520 -> V_557 , V_520 -> V_436 ) ;
V_570 += V_188 -> V_556 *
F_140 ( V_188 -> V_557 , V_188 -> V_436 ) ;
V_570 /= V_135 ;
if ( V_520 -> V_436 > V_573 ) {
V_571 += V_520 -> V_556 *
F_140 ( V_520 -> V_557 ,
V_520 -> V_436 - V_573 ) ;
}
if ( V_520 -> V_436 * V_520 -> V_556 <
V_520 -> V_557 * V_135 ) {
V_452 = ( V_520 -> V_436 * V_520 -> V_556 ) /
V_188 -> V_556 ;
} else {
V_452 = ( V_520 -> V_557 * V_135 ) /
V_188 -> V_556 ;
}
V_571 += V_188 -> V_556 *
F_140 ( V_188 -> V_557 , V_188 -> V_436 + V_452 ) ;
V_571 /= V_135 ;
if ( V_571 > V_570 )
V_139 -> V_434 = V_520 -> V_557 ;
}
static inline void F_406 ( struct V_482 * V_139 , struct V_518 * V_519 )
{
unsigned long V_574 , V_575 = ~ 0UL ;
struct V_547 * V_188 , * V_520 ;
V_188 = & V_519 -> V_566 ;
V_520 = & V_519 -> V_523 ;
if ( V_520 -> V_525 == V_551 ) {
V_520 -> V_557 =
F_140 ( V_520 -> V_557 , V_519 -> V_436 ) ;
}
if ( V_520 -> V_436 <= V_519 -> V_436 ||
V_188 -> V_436 >= V_519 -> V_436 ) {
V_139 -> V_434 = 0 ;
return F_405 ( V_139 , V_519 ) ;
}
if ( V_520 -> V_525 == V_550 &&
V_188 -> V_525 == V_550 ) {
V_575 =
( V_520 -> V_524 - V_520 -> V_549 ) ;
V_575 *= ( V_576 * V_135 ) ;
V_575 /= V_520 -> V_556 ;
}
V_574 = F_140 ( V_520 -> V_436 - V_519 -> V_436 , V_575 ) ;
V_139 -> V_434 = F_140 (
V_574 * V_520 -> V_556 ,
( V_519 -> V_436 - V_188 -> V_436 ) * V_188 -> V_556
) / V_135 ;
if ( V_139 -> V_434 < V_520 -> V_557 )
return F_405 ( V_139 , V_519 ) ;
}
static struct V_426 * F_407 ( struct V_482 * V_139 )
{
struct V_547 * V_188 , * V_520 ;
struct V_518 V_519 ;
F_382 ( & V_519 ) ;
F_402 ( V_139 , & V_519 ) ;
V_188 = & V_519 . V_566 ;
V_520 = & V_519 . V_523 ;
if ( ( V_139 -> V_358 == V_577 || V_139 -> V_358 == V_513 ) &&
F_404 ( V_139 , & V_519 ) )
return V_519 . V_520 ;
if ( ! V_519 . V_520 || V_520 -> V_524 == 0 )
goto V_578;
V_519 . V_436 = ( V_135 * V_519 . V_521 )
/ V_519 . V_522 ;
if ( V_520 -> V_525 == V_551 )
goto V_579;
if ( V_139 -> V_358 == V_513 && V_188 -> V_558 &&
! V_520 -> V_558 )
goto V_579;
if ( V_188 -> V_436 >= V_520 -> V_436 )
goto V_578;
if ( V_188 -> V_436 >= V_519 . V_436 )
goto V_578;
if ( V_139 -> V_358 == V_577 ) {
if ( ( V_520 -> V_525 != V_550 ) &&
( V_188 -> V_555 <= ( V_520 -> V_555 + 1 ) ) )
goto V_578;
} else {
if ( 100 * V_520 -> V_436 <=
V_139 -> V_169 -> V_154 * V_188 -> V_436 )
goto V_578;
}
V_579:
F_406 ( V_139 , & V_519 ) ;
return V_519 . V_520 ;
V_578:
V_139 -> V_434 = 0 ;
return NULL ;
}
static struct V_24 * F_408 ( struct V_482 * V_139 ,
struct V_426 * V_115 )
{
struct V_24 * V_520 = NULL , * V_24 ;
unsigned long V_580 = 0 , V_581 = 1 ;
int V_204 ;
F_335 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_133 , V_546 , V_410 ;
enum V_560 V_582 ;
V_24 = F_110 ( V_204 ) ;
V_582 = F_401 ( V_24 ) ;
if ( V_582 > V_139 -> V_560 )
continue;
V_133 = F_112 ( V_204 ) ;
V_546 = F_113 ( V_133 , V_135 ) ;
if ( ! V_546 )
V_546 = F_392 ( V_139 -> V_169 , V_115 ) ;
V_410 = F_111 ( V_204 ) ;
if ( V_546 && V_24 -> V_72 == 1 && V_410 > V_139 -> V_434 )
continue;
if ( V_410 * V_581 > V_580 * V_133 ) {
V_580 = V_410 ;
V_581 = V_133 ;
V_520 = V_24 ;
}
}
return V_520 ;
}
static int F_409 ( struct V_482 * V_139 )
{
struct V_168 * V_169 = V_139 -> V_169 ;
if ( V_139 -> V_358 == V_513 ) {
if ( ( V_169 -> V_163 & V_559 ) && V_139 -> V_158 > V_139 -> V_121 )
return 1 ;
}
return F_14 ( V_169 -> V_497 > V_169 -> V_498 + 2 ) ;
}
static int F_410 ( struct V_482 * V_139 )
{
struct V_426 * V_448 = V_139 -> V_169 -> V_429 ;
struct V_583 * V_584 , * V_585 ;
int V_132 , V_586 = - 1 ;
if ( V_139 -> V_358 == V_513 )
return 1 ;
V_584 = F_333 ( V_448 ) ;
V_585 = F_411 ( V_448 ) ;
F_335 (cpu, sg_cpus, env->cpus) {
if ( ! F_124 ( V_132 , V_585 ) || ! F_336 ( V_132 ) )
continue;
V_586 = V_132 ;
break;
}
if ( V_586 == - 1 )
V_586 = F_412 ( V_448 ) ;
return V_586 == V_139 -> V_121 ;
}
static int F_413 ( int V_419 , struct V_24 * V_310 ,
struct V_168 * V_169 , enum V_527 V_358 ,
int * V_587 )
{
int V_588 , V_589 , V_590 = 0 ;
struct V_168 * V_591 = V_169 -> V_34 ;
struct V_426 * V_115 ;
struct V_24 * V_520 ;
unsigned long V_163 ;
struct V_583 * V_8 = F_414 ( V_592 ) ;
struct V_482 V_139 = {
. V_169 = V_169 ,
. V_121 = V_419 ,
. V_159 = V_310 ,
. V_492 = F_333 ( V_169 -> V_429 ) ,
. V_358 = V_358 ,
. V_509 = V_510 ,
. V_8 = V_8 ,
. V_560 = V_562 ,
. V_505 = F_415 ( V_139 . V_505 ) ,
} ;
if ( V_358 == V_513 )
V_139 . V_492 = NULL ;
F_416 ( V_8 , V_593 ) ;
F_236 ( V_169 , V_594 [ V_358 ] ) ;
V_595:
if ( ! F_410 ( & V_139 ) ) {
* V_587 = 0 ;
goto V_578;
}
V_115 = F_407 ( & V_139 ) ;
if ( ! V_115 ) {
F_236 ( V_169 , V_596 [ V_358 ] ) ;
goto V_578;
}
V_520 = F_408 ( & V_139 , V_115 ) ;
if ( ! V_520 ) {
F_236 ( V_169 , V_597 [ V_358 ] ) ;
goto V_578;
}
F_165 ( V_520 == V_139 . V_159 ) ;
F_69 ( V_169 , V_598 [ V_358 ] , V_139 . V_434 ) ;
V_588 = 0 ;
if ( V_520 -> V_72 > 1 ) {
V_139 . V_163 |= V_495 ;
V_139 . V_158 = V_520 -> V_132 ;
V_139 . V_157 = V_520 ;
V_139 . V_508 = F_140 ( V_599 , V_520 -> V_72 ) ;
V_600:
F_378 ( & V_520 -> V_162 , V_163 ) ;
V_589 = F_367 ( & V_139 ) ;
F_273 ( & V_520 -> V_162 ) ;
if ( V_589 ) {
F_375 ( & V_139 ) ;
V_588 += V_589 ;
}
F_417 ( V_163 ) ;
if ( V_139 . V_163 & V_511 ) {
V_139 . V_163 &= ~ V_511 ;
goto V_600;
}
if ( ( V_139 . V_163 & V_493 ) && V_139 . V_434 > 0 ) {
F_418 ( V_139 . V_121 , V_139 . V_8 ) ;
V_139 . V_159 = F_110 ( V_139 . V_494 ) ;
V_139 . V_121 = V_139 . V_494 ;
V_139 . V_163 &= ~ V_493 ;
V_139 . V_507 = 0 ;
V_139 . V_509 = V_510 ;
goto V_600;
}
if ( V_591 ) {
int * V_601 = & V_591 -> V_429 -> V_438 -> V_434 ;
if ( ( V_139 . V_163 & V_491 ) && V_139 . V_434 > 0 )
* V_601 = 1 ;
}
if ( F_14 ( V_139 . V_163 & V_495 ) ) {
F_418 ( F_27 ( V_520 ) , V_8 ) ;
if ( ! F_419 ( V_8 ) ) {
V_139 . V_507 = 0 ;
V_139 . V_509 = V_510 ;
goto V_595;
}
goto V_602;
}
}
if ( ! V_588 ) {
F_236 ( V_169 , V_603 [ V_358 ] ) ;
if ( V_358 != V_513 )
V_169 -> V_497 ++ ;
if ( F_409 ( & V_139 ) ) {
F_378 ( & V_520 -> V_162 , V_163 ) ;
if ( ! F_124 ( V_419 ,
F_125 ( V_520 -> V_45 ) ) ) {
F_379 ( & V_520 -> V_162 ,
V_163 ) ;
V_139 . V_163 |= V_495 ;
goto V_604;
}
if ( ! V_520 -> V_590 ) {
V_520 -> V_590 = 1 ;
V_520 -> V_605 = V_419 ;
V_590 = 1 ;
}
F_379 ( & V_520 -> V_162 , V_163 ) ;
if ( V_590 ) {
F_420 ( F_27 ( V_520 ) ,
V_606 , V_520 ,
& V_520 -> V_607 ) ;
}
V_169 -> V_497 = V_169 -> V_498 + 1 ;
}
} else
V_169 -> V_497 = 0 ;
if ( F_12 ( ! V_590 ) ) {
V_169 -> V_541 = V_169 -> V_608 ;
} else {
if ( V_169 -> V_541 < V_169 -> V_609 )
V_169 -> V_541 *= 2 ;
}
goto V_265;
V_578:
if ( V_591 ) {
int * V_601 = & V_591 -> V_429 -> V_438 -> V_434 ;
if ( * V_601 )
* V_601 = 0 ;
}
V_602:
F_236 ( V_169 , V_610 [ V_358 ] ) ;
V_169 -> V_497 = 0 ;
V_604:
if ( ( ( V_139 . V_163 & V_495 ) &&
V_169 -> V_541 < V_611 ) ||
( V_169 -> V_541 < V_169 -> V_609 ) )
V_169 -> V_541 *= 2 ;
V_588 = 0 ;
V_265:
return V_588 ;
}
static inline unsigned long
F_421 ( struct V_168 * V_169 , int V_612 )
{
unsigned long V_176 = V_169 -> V_541 ;
if ( V_612 )
V_176 *= V_169 -> V_613 ;
V_176 = F_141 ( V_176 ) ;
V_176 = F_146 ( V_176 , 1UL , V_542 ) ;
return V_176 ;
}
static inline void
F_422 ( struct V_168 * V_169 , int V_612 , unsigned long * V_614 )
{
unsigned long V_176 , V_58 ;
V_176 = F_421 ( V_169 , V_612 ) ;
V_58 = V_169 -> V_615 + V_176 ;
if ( F_177 ( * V_614 , V_58 ) )
* V_614 = V_58 ;
}
static int F_227 ( struct V_24 * V_310 )
{
unsigned long V_614 = V_179 + V_177 ;
int V_419 = V_310 -> V_132 ;
struct V_168 * V_169 ;
int V_616 = 0 ;
T_2 V_617 = 0 ;
F_225 ( V_310 ) ;
V_310 -> V_446 = F_76 ( V_310 ) ;
if ( V_310 -> V_618 < V_484 ||
! V_310 -> V_568 -> V_552 ) {
F_120 () ;
V_169 = F_423 ( V_310 -> V_169 ) ;
if ( V_169 )
F_422 ( V_169 , 0 , & V_614 ) ;
F_128 () ;
goto V_265;
}
F_273 ( & V_310 -> V_162 ) ;
F_377 ( V_419 ) ;
F_120 () ;
F_342 (this_cpu, sd) {
int V_587 = 1 ;
T_2 V_619 , V_620 ;
if ( ! ( V_169 -> V_163 & V_458 ) )
continue;
if ( V_310 -> V_618 < V_617 + V_169 -> V_621 ) {
F_422 ( V_169 , 0 , & V_614 ) ;
break;
}
if ( V_169 -> V_163 & V_622 ) {
V_619 = F_266 ( V_419 ) ;
V_616 = F_413 ( V_419 , V_310 ,
V_169 , V_513 ,
& V_587 ) ;
V_620 = F_266 ( V_419 ) - V_619 ;
if ( V_620 > V_169 -> V_621 )
V_169 -> V_621 = V_620 ;
V_617 += V_620 ;
}
F_422 ( V_169 , 0 , & V_614 ) ;
if ( V_616 || V_310 -> V_72 > 0 )
break;
}
F_128 () ;
F_271 ( & V_310 -> V_162 ) ;
if ( V_617 > V_310 -> V_623 )
V_310 -> V_623 = V_617 ;
if ( V_310 -> V_40 . V_368 && ! V_616 )
V_616 = 1 ;
V_265:
if ( F_177 ( V_310 -> V_614 , V_614 ) )
V_310 -> V_614 = V_614 ;
if ( V_310 -> V_72 != V_310 -> V_40 . V_368 )
V_616 = - 1 ;
if ( V_616 ) {
F_226 ( V_310 ) ;
V_310 -> V_446 = 0 ;
}
return V_616 ;
}
static int V_606 ( void * V_364 )
{
struct V_24 * V_624 = V_364 ;
int V_569 = F_27 ( V_624 ) ;
int V_625 = V_624 -> V_605 ;
struct V_24 * V_626 = F_110 ( V_625 ) ;
struct V_168 * V_169 ;
struct V_26 * V_29 = NULL ;
F_121 ( & V_624 -> V_162 ) ;
if ( F_14 ( V_569 != F_267 () ||
! V_624 -> V_590 ) )
goto V_627;
if ( V_624 -> V_72 <= 1 )
goto V_627;
F_165 ( V_624 == V_626 ) ;
F_120 () ;
F_342 (target_cpu, sd) {
if ( ( V_169 -> V_163 & V_458 ) &&
F_124 ( V_569 , F_343 ( V_169 ) ) )
break;
}
if ( F_12 ( V_169 ) ) {
struct V_482 V_139 = {
. V_169 = V_169 ,
. V_121 = V_625 ,
. V_159 = V_626 ,
. V_158 = V_624 -> V_132 ,
. V_157 = V_624 ,
. V_358 = V_577 ,
} ;
F_236 ( V_169 , V_628 ) ;
V_29 = F_365 ( & V_139 ) ;
if ( V_29 )
F_236 ( V_169 , V_629 ) ;
else
F_236 ( V_169 , V_630 ) ;
}
F_128 () ;
V_627:
V_624 -> V_590 = 0 ;
F_273 ( & V_624 -> V_162 ) ;
if ( V_29 )
F_374 ( V_626 , V_29 ) ;
F_424 () ;
return 0 ;
}
static inline int F_425 ( struct V_24 * V_24 )
{
return F_14 ( ! F_426 ( V_24 -> V_169 ) ) ;
}
static inline int F_427 ( void )
{
int V_631 = F_428 ( V_632 . V_633 ) ;
if ( V_631 < V_634 && F_336 ( V_631 ) )
return V_631 ;
return V_634 ;
}
static void F_429 ( void )
{
int V_635 ;
V_632 . V_614 ++ ;
V_635 = F_427 () ;
if ( V_635 >= V_634 )
return;
if ( F_430 ( V_636 , F_431 ( V_635 ) ) )
return;
F_432 ( V_635 ) ;
return;
}
static inline void F_433 ( int V_132 )
{
if ( F_14 ( F_434 ( V_637 , F_431 ( V_132 ) ) ) ) {
if ( F_12 ( F_124 ( V_132 , V_632 . V_633 ) ) ) {
F_418 ( V_132 , V_632 . V_633 ) ;
F_435 ( & V_632 . V_638 ) ;
}
F_436 ( V_637 , F_431 ( V_132 ) ) ;
}
}
static inline void F_437 ( void )
{
struct V_168 * V_169 ;
int V_132 = F_267 () ;
F_120 () ;
V_169 = F_132 ( F_133 ( V_639 , V_132 ) ) ;
if ( ! V_169 || ! V_169 -> V_640 )
goto V_165;
V_169 -> V_640 = 0 ;
F_438 ( & V_169 -> V_429 -> V_438 -> V_641 ) ;
V_165:
F_128 () ;
}
void F_439 ( void )
{
struct V_168 * V_169 ;
int V_132 = F_267 () ;
F_120 () ;
V_169 = F_132 ( F_133 ( V_639 , V_132 ) ) ;
if ( ! V_169 || V_169 -> V_640 )
goto V_165;
V_169 -> V_640 = 1 ;
F_435 ( & V_169 -> V_429 -> V_438 -> V_641 ) ;
V_165:
F_128 () ;
}
void F_440 ( int V_132 )
{
if ( ! F_441 ( V_132 ) )
return;
if ( F_434 ( V_637 , F_431 ( V_132 ) ) )
return;
if ( F_425 ( F_110 ( V_132 ) ) )
return;
F_442 ( V_132 , V_632 . V_633 ) ;
F_438 ( & V_632 . V_638 ) ;
F_443 ( V_637 , F_431 ( V_132 ) ) ;
}
static int F_444 ( struct V_642 * V_643 ,
unsigned long V_644 , void * V_645 )
{
switch ( V_644 & ~ V_646 ) {
case V_647 :
F_433 ( F_267 () ) ;
return V_648 ;
default:
return V_649 ;
}
}
void F_445 ( void )
{
V_542 = V_177 * F_6 () / 10 ;
}
static void F_446 ( struct V_24 * V_24 , enum V_527 V_358 )
{
int V_587 = 1 ;
int V_132 = V_24 -> V_132 ;
unsigned long V_176 ;
struct V_168 * V_169 ;
unsigned long V_614 = V_179 + 60 * V_177 ;
int F_422 = 0 ;
int V_650 , V_651 = 0 ;
T_2 V_652 = 0 ;
F_377 ( V_132 ) ;
F_120 () ;
F_342 (cpu, sd) {
if ( F_177 ( V_179 , V_169 -> V_653 ) ) {
V_169 -> V_621 =
( V_169 -> V_621 * 253 ) / 256 ;
V_169 -> V_653 = V_179 + V_177 ;
V_651 = 1 ;
}
V_652 += V_169 -> V_621 ;
if ( ! ( V_169 -> V_163 & V_458 ) )
continue;
if ( ! V_587 ) {
if ( V_651 )
continue;
break;
}
V_176 = F_421 ( V_169 , V_358 != V_577 ) ;
V_650 = V_169 -> V_163 & V_654 ;
if ( V_650 ) {
if ( ! F_447 ( & V_655 ) )
goto V_265;
}
if ( F_403 ( V_179 , V_169 -> V_615 + V_176 ) ) {
if ( F_413 ( V_132 , V_24 , V_169 , V_358 , & V_587 ) ) {
V_358 = F_336 ( V_132 ) ? V_577 : V_528 ;
}
V_169 -> V_615 = V_179 ;
V_176 = F_421 ( V_169 , V_358 != V_577 ) ;
}
if ( V_650 )
F_169 ( & V_655 ) ;
V_265:
if ( F_177 ( V_614 , V_169 -> V_615 + V_176 ) ) {
V_614 = V_169 -> V_615 + V_176 ;
F_422 = 1 ;
}
}
if ( V_651 ) {
V_24 -> V_623 =
F_68 ( ( T_2 ) V_484 , V_652 ) ;
}
F_128 () ;
if ( F_12 ( F_422 ) )
V_24 -> V_614 = V_614 ;
}
static void F_448 ( struct V_24 * V_310 , enum V_527 V_358 )
{
int V_419 = V_310 -> V_132 ;
struct V_24 * V_24 ;
int V_586 ;
if ( V_358 != V_577 ||
! F_434 ( V_636 , F_431 ( V_419 ) ) )
goto V_247;
F_109 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_586 == V_419 || ! F_336 ( V_586 ) )
continue;
if ( F_449 () )
break;
V_24 = F_110 ( V_586 ) ;
if ( F_403 ( V_179 , V_24 -> V_614 ) ) {
F_121 ( & V_24 -> V_162 ) ;
F_284 ( V_24 ) ;
F_450 ( V_24 ) ;
F_123 ( & V_24 -> V_162 ) ;
F_446 ( V_24 , V_577 ) ;
}
if ( F_177 ( V_310 -> V_614 , V_24 -> V_614 ) )
V_310 -> V_614 = V_24 -> V_614 ;
}
V_632 . V_614 = V_310 -> V_614 ;
V_247:
F_436 ( V_636 , F_431 ( V_419 ) ) ;
}
static inline int F_451 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_179 ;
struct V_168 * V_169 ;
struct V_545 * V_438 ;
int V_656 , V_132 = V_24 -> V_132 ;
if ( F_14 ( V_24 -> F_227 ) )
return 0 ;
F_437 () ;
F_433 ( V_132 ) ;
if ( F_12 ( ! F_214 ( & V_632 . V_638 ) ) )
return 0 ;
if ( F_180 ( V_81 , V_632 . V_614 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_657;
F_120 () ;
V_169 = F_132 ( F_133 ( V_639 , V_132 ) ) ;
if ( V_169 ) {
V_438 = V_169 -> V_429 -> V_438 ;
V_656 = F_214 ( & V_438 -> V_641 ) ;
if ( V_656 > 1 )
goto V_658;
}
V_169 = F_132 ( F_133 ( V_659 , V_132 ) ) ;
if ( V_169 && ( F_340 ( V_632 . V_633 ,
F_343 ( V_169 ) ) < V_132 ) )
goto V_658;
F_128 () ;
return 0 ;
V_658:
F_128 () ;
V_657:
return 1 ;
}
static void F_448 ( struct V_24 * V_310 , enum V_527 V_358 ) { }
static void F_452 ( struct V_660 * V_661 )
{
struct V_24 * V_310 = V_310 () ;
enum V_527 V_358 = V_310 -> F_227 ?
V_577 : V_528 ;
F_446 ( V_310 , V_358 ) ;
F_448 ( V_310 , V_358 ) ;
}
void F_453 ( struct V_24 * V_24 )
{
if ( F_14 ( F_425 ( V_24 ) ) )
return;
if ( F_403 ( V_179 , V_24 -> V_614 ) )
F_454 ( V_662 ) ;
#ifdef F_455
if ( F_451 ( V_24 ) )
F_429 () ;
#endif
}
static void F_456 ( struct V_24 * V_24 )
{
F_8 () ;
F_310 ( V_24 ) ;
}
static void F_457 ( struct V_24 * V_24 )
{
F_8 () ;
F_312 ( V_24 ) ;
}
static void F_458 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_339 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_254 ( V_25 , V_28 , V_339 ) ;
}
if ( V_233 )
F_190 ( V_24 , V_45 ) ;
F_215 ( V_24 , 1 ) ;
}
static void F_459 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_419 = F_267 () ;
struct V_24 * V_24 = V_310 () ;
unsigned long V_163 ;
F_378 ( & V_24 -> V_162 , V_163 ) ;
F_284 ( V_24 ) ;
V_25 = F_23 ( V_126 ) ;
V_45 = V_25 -> V_45 ;
F_120 () ;
F_460 ( V_29 , V_419 ) ;
F_128 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_237 ( V_25 , V_28 , 1 ) ;
if ( V_663 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_118 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_248 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_379 ( & V_24 -> V_162 , V_163 ) ;
}
static void
F_461 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_664 )
{
if ( ! F_462 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_665 > V_664 )
F_248 ( V_24 ) ;
} else
F_373 ( V_24 , V_29 , 0 ) ;
}
static void F_463 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! F_462 ( V_29 ) && V_29 -> V_331 != V_666 ) {
F_237 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_194
if ( V_28 -> V_77 . V_78 ) {
F_206 ( V_28 ) ;
F_218 ( V_25 , V_28 -> V_77 . V_294 ) ;
}
#endif
}
static void F_464 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
#ifdef F_351
struct V_27 * V_28 = & V_29 -> V_28 ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! F_462 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 )
F_248 ( V_24 ) ;
else
F_373 ( V_24 , V_29 , 0 ) ;
}
static void F_465 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_249 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_466 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_667 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_194
F_467 ( & V_25 -> V_293 , 1 ) ;
F_468 ( & V_25 -> V_307 , 0 ) ;
#endif
}
static void F_469 ( struct V_26 * V_29 , int V_339 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_339 && ( ! V_28 -> V_85 || V_29 -> V_331 == V_668 ) )
V_339 = 1 ;
if ( ! V_339 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_470 ( V_29 , F_131 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_339 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_194
V_28 -> V_77 . V_78 = F_207 ( & V_25 -> V_293 ) ;
V_25 -> V_298 += V_28 -> V_77 . V_294 ;
#endif
}
}
void F_471 ( struct V_269 * V_33 )
{
int V_204 ;
F_308 ( F_269 ( V_33 ) ) ;
F_472 (i) {
if ( V_33 -> V_25 )
F_175 ( V_33 -> V_25 [ V_204 ] ) ;
if ( V_33 -> V_28 )
F_175 ( V_33 -> V_28 [ V_204 ] ) ;
}
F_175 ( V_33 -> V_25 ) ;
F_175 ( V_33 -> V_28 ) ;
}
int F_473 ( struct V_269 * V_33 , struct V_269 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_204 ;
V_33 -> V_25 = F_159 ( sizeof( V_25 ) * V_634 , V_218 ) ;
if ( ! V_33 -> V_25 )
goto V_669;
V_33 -> V_28 = F_159 ( sizeof( V_28 ) * V_634 , V_218 ) ;
if ( ! V_33 -> V_28 )
goto V_669;
V_33 -> V_273 = V_71 ;
F_302 ( F_269 ( V_33 ) ) ;
F_472 (i) {
V_25 = F_474 ( sizeof( struct V_25 ) ,
V_218 , F_101 ( V_204 ) ) ;
if ( ! V_25 )
goto V_669;
V_28 = F_474 ( sizeof( struct V_27 ) ,
V_218 , F_101 ( V_204 ) ) ;
if ( ! V_28 )
goto V_670;
F_466 ( V_25 ) ;
F_475 ( V_33 , V_25 , V_28 , V_204 , V_34 -> V_28 [ V_204 ] ) ;
}
return 1 ;
V_670:
F_175 ( V_25 ) ;
V_669:
return 0 ;
}
void F_476 ( struct V_269 * V_33 , int V_132 )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
unsigned long V_163 ;
if ( ! V_33 -> V_25 [ V_132 ] -> V_32 )
return;
F_378 ( & V_24 -> V_162 , V_163 ) ;
F_31 ( V_33 -> V_25 [ V_132 ] ) ;
F_379 ( & V_24 -> V_162 , V_163 ) ;
}
void F_475 ( struct V_269 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_132 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_110 ( V_132 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_305 ( V_25 ) ;
V_33 -> V_25 [ V_132 ] = V_25 ;
V_33 -> V_28 [ V_132 ] = V_28 ;
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
int F_477 ( struct V_269 * V_33 , unsigned long V_273 )
{
int V_204 ;
unsigned long V_163 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_173 ;
V_273 = F_146 ( V_273 , F_216 ( V_274 ) , F_216 ( V_671 ) ) ;
F_478 ( & V_672 ) ;
if ( V_33 -> V_273 == V_273 )
goto V_450;
V_33 -> V_273 = V_273 ;
F_472 (i) {
struct V_24 * V_24 = F_110 ( V_204 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_204 ] ;
F_378 ( & V_24 -> V_162 , V_163 ) ;
F_284 ( V_24 ) ;
F_61 (se)
F_201 ( F_25 ( V_28 ) ) ;
F_379 ( & V_24 -> V_162 , V_163 ) ;
}
V_450:
F_479 ( & V_672 ) ;
return 0 ;
}
void F_471 ( struct V_269 * V_33 ) { }
int F_473 ( struct V_269 * V_33 , struct V_269 * V_34 )
{
return 1 ;
}
void F_476 ( struct V_269 * V_33 , int V_132 ) { }
static unsigned int F_480 ( struct V_24 * V_24 , struct V_26 * V_673 )
{
struct V_27 * V_28 = & V_673 -> V_28 ;
unsigned int V_674 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_674 = F_481 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_674 ;
}
void F_482 ( struct V_675 * V_676 , int V_132 )
{
struct V_25 * V_25 ;
F_120 () ;
F_311 (cpu_rq(cpu), cfs_rq)
F_483 ( V_676 , V_132 , V_25 ) ;
F_128 () ;
}
T_12 void F_484 ( void )
{
#ifdef F_194
F_485 ( V_662 , F_452 ) ;
#ifdef F_455
V_632 . V_614 = V_179 ;
F_486 ( & V_632 . V_633 , V_677 ) ;
F_487 ( F_444 , 0 ) ;
#endif
#endif
}
