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
V_76 -> V_83 = 0 ;
V_76 -> V_84 = 0 ;
}
void F_62 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
struct V_75 * V_76 = & V_28 -> V_77 ;
long V_85 = ( long ) ( V_86 - V_25 -> V_77 . V_83 ) / 2 ;
if ( V_85 > 0 ) {
if ( V_25 -> V_77 . V_83 != 0 ) {
V_76 -> V_83 = V_25 -> V_77 . V_83 * V_28 -> V_70 . V_4 ;
V_76 -> V_83 /= ( V_25 -> V_77 . V_80 + 1 ) ;
if ( V_76 -> V_83 > V_85 )
V_76 -> V_83 = V_85 ;
} else {
V_76 -> V_83 = V_85 ;
}
V_76 -> V_84 = V_76 -> V_83 * V_82 ;
}
}
void F_61 ( struct V_27 * V_28 )
{
}
void F_62 ( struct V_27 * V_28 )
{
}
static void F_63 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_87 = F_64 ( F_16 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_13 ( ! V_45 ) )
return;
V_19 = V_87 - V_45 -> V_88 ;
if ( F_13 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_88 = V_87 ;
F_65 ( V_45 -> V_89 . V_90 ,
F_66 ( V_19 , V_45 -> V_89 . V_90 ) ) ;
V_45 -> V_91 += V_19 ;
F_67 ( V_25 , V_92 , V_19 ) ;
V_45 -> V_41 += F_56 ( V_19 , V_45 ) ;
F_38 ( V_25 ) ;
if ( F_20 ( V_45 ) ) {
struct V_26 * V_93 = F_17 ( V_45 ) ;
F_68 ( V_93 , V_19 , V_45 -> V_41 ) ;
F_69 ( V_93 , V_19 ) ;
F_70 ( V_93 , V_19 ) ;
}
F_71 ( V_25 , V_19 ) ;
}
static void F_72 ( struct V_24 * V_24 )
{
F_63 ( F_23 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_73 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_94 = F_74 ( F_16 ( V_25 ) ) ;
if ( F_20 ( V_28 ) && F_75 ( F_17 ( V_28 ) ) &&
F_11 ( V_94 > V_28 -> V_89 . V_94 ) )
V_94 -= V_28 -> V_89 . V_94 ;
V_28 -> V_89 . V_94 = V_94 ;
}
static void
F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_26 * V_29 ;
T_2 V_42 ;
V_42 = F_74 ( F_16 ( V_25 ) ) - V_28 -> V_89 . V_94 ;
if ( F_20 ( V_28 ) ) {
V_29 = F_17 ( V_28 ) ;
if ( F_75 ( V_29 ) ) {
V_28 -> V_89 . V_94 = V_42 ;
return;
}
F_77 ( V_29 , V_42 ) ;
}
V_28 -> V_89 . V_95 = F_66 ( V_28 -> V_89 . V_95 , V_42 ) ;
V_28 -> V_89 . V_96 ++ ;
V_28 -> V_89 . V_97 += V_42 ;
V_28 -> V_89 . V_94 = 0 ;
}
static inline void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_73 ( V_25 , V_28 ) ;
}
static inline void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_98 )
{
if ( V_28 != V_25 -> V_45 )
F_76 ( V_25 , V_28 ) ;
if ( V_98 & V_99 ) {
if ( F_20 ( V_28 ) ) {
struct V_26 * V_100 = F_17 ( V_28 ) ;
if ( V_100 -> V_101 & V_102 )
V_28 -> V_89 . V_103 = F_74 ( F_16 ( V_25 ) ) ;
if ( V_100 -> V_101 & V_104 )
V_28 -> V_89 . V_105 = F_74 ( F_16 ( V_25 ) ) ;
}
}
}
static inline void
F_73 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_98 )
{
}
static inline void
F_80 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_88 = F_64 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_81 ( struct V_26 * V_29 )
{
unsigned long V_106 = 0 ;
unsigned long V_107 ;
V_107 = V_108 << ( 20 - V_109 ) ;
V_106 = F_82 ( V_29 -> V_110 ) ;
if ( ! V_106 )
V_106 = V_107 ;
V_106 = F_83 ( V_106 , V_107 ) ;
return V_106 / V_107 ;
}
static unsigned int F_84 ( struct V_26 * V_29 )
{
unsigned int V_111 = F_85 ( V_108 ) ;
unsigned int V_112 , floor ;
unsigned int V_113 = 1 ;
if ( V_111 < V_114 )
V_113 = V_114 / V_111 ;
floor = 1000 / V_113 ;
V_112 = V_115 / F_81 ( V_29 ) ;
return F_86 (unsigned int, floor, scan) ;
}
static unsigned int F_87 ( struct V_26 * V_29 )
{
unsigned int V_116 = F_84 ( V_29 ) ;
unsigned int V_117 ;
V_117 = V_118 / F_81 ( V_29 ) ;
return F_66 ( V_116 , V_117 ) ;
}
static void F_88 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_119 += ( V_29 -> V_120 != - 1 ) ;
V_24 -> V_121 += ( V_29 -> V_120 == F_89 ( V_29 ) ) ;
}
static void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_119 -= ( V_29 -> V_120 != - 1 ) ;
V_24 -> V_121 -= ( V_29 -> V_120 == F_89 ( V_29 ) ) ;
}
T_7 F_91 ( struct V_26 * V_29 )
{
return V_29 -> V_122 ? V_29 -> V_122 -> V_123 : 0 ;
}
static inline int F_92 ( enum V_124 V_125 , int V_126 , int V_127 )
{
return V_128 * ( V_125 * V_129 + V_126 ) + V_127 ;
}
static inline unsigned long F_93 ( struct V_26 * V_29 , int V_126 )
{
if ( ! V_29 -> V_130 )
return 0 ;
return V_29 -> V_130 [ F_92 ( V_131 , V_126 , 0 ) ] +
V_29 -> V_130 [ F_92 ( V_131 , V_126 , 1 ) ] ;
}
static inline unsigned long F_94 ( struct V_26 * V_29 , int V_126 )
{
if ( ! V_29 -> V_122 )
return 0 ;
return V_29 -> V_122 -> V_132 [ F_92 ( V_131 , V_126 , 0 ) ] +
V_29 -> V_122 -> V_132 [ F_92 ( V_131 , V_126 , 1 ) ] ;
}
static inline unsigned long F_95 ( struct V_122 * V_133 , int V_126 )
{
return V_133 -> V_134 [ F_92 ( V_131 , V_126 , 0 ) ] +
V_133 -> V_134 [ F_92 ( V_131 , V_126 , 1 ) ] ;
}
static bool F_96 ( int V_126 , struct V_122 * V_135 )
{
return F_95 ( V_135 , V_126 ) * V_136 > V_135 -> V_137 ;
}
static unsigned long F_97 ( struct V_26 * V_29 , int V_126 ,
int V_138 , bool V_139 )
{
unsigned long V_140 = 0 ;
int V_141 ;
if ( V_142 == V_143 )
return 0 ;
F_98 (node) {
unsigned long V_132 ;
int V_144 = F_99 ( V_126 , V_141 ) ;
if ( V_144 == V_145 || V_141 == V_126 )
continue;
if ( V_142 == V_146 &&
V_144 > V_138 )
continue;
if ( V_139 )
V_132 = F_93 ( V_29 , V_141 ) ;
else
V_132 = F_94 ( V_29 , V_141 ) ;
if ( V_142 == V_147 ) {
V_132 *= ( V_145 - V_144 ) ;
V_132 /= ( V_145 - V_148 ) ;
}
V_140 += V_132 ;
}
return V_140 ;
}
static inline unsigned long F_100 ( struct V_26 * V_29 , int V_126 ,
int V_144 )
{
unsigned long V_132 , V_149 ;
if ( ! V_29 -> V_130 )
return 0 ;
V_149 = V_29 -> V_150 ;
if ( ! V_149 )
return 0 ;
V_132 = F_93 ( V_29 , V_126 ) ;
V_132 += F_97 ( V_29 , V_126 , V_144 , true ) ;
return 1000 * V_132 / V_149 ;
}
static inline unsigned long F_101 ( struct V_26 * V_29 , int V_126 ,
int V_144 )
{
unsigned long V_132 , V_149 ;
if ( ! V_29 -> V_122 )
return 0 ;
V_149 = V_29 -> V_122 -> V_149 ;
if ( ! V_149 )
return 0 ;
V_132 = F_94 ( V_29 , V_126 ) ;
V_132 += F_97 ( V_29 , V_126 , V_144 , false ) ;
return 1000 * V_132 / V_149 ;
}
bool F_102 ( struct V_26 * V_29 , struct V_151 * V_151 ,
int V_152 , int V_153 )
{
struct V_122 * V_135 = V_29 -> V_122 ;
int V_154 = F_103 ( V_153 ) ;
int V_155 , V_156 ;
V_156 = F_104 ( V_153 , V_157 -> V_158 ) ;
V_155 = F_105 ( V_151 , V_156 ) ;
if ( ! F_106 ( V_155 ) &&
F_107 ( V_155 ) != V_154 )
return false ;
if ( F_108 ( V_29 , V_155 ) )
return true ;
if ( ! V_135 )
return true ;
if ( F_95 ( V_135 , V_154 ) > F_95 ( V_135 , V_152 ) *
V_136 )
return true ;
return F_95 ( V_135 , V_154 ) * F_94 ( V_29 , V_152 ) * 3 >
F_95 ( V_135 , V_152 ) * F_94 ( V_29 , V_154 ) * 4 ;
}
static void F_109 ( struct V_159 * V_160 , int V_126 )
{
int V_161 , V_162 , V_8 = 0 ;
unsigned long V_163 ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
F_110 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_111 ( V_162 ) ;
V_160 -> V_72 += V_24 -> V_72 ;
V_160 -> V_70 += F_112 ( V_162 ) ;
V_160 -> V_164 += F_113 ( V_162 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_161 = F_54 ( V_86 * V_8 , V_160 -> V_164 ) ;
V_163 = V_8 / V_161 ;
V_160 -> V_165 = F_5 ( unsigned , V_163 ,
F_114 ( V_160 -> V_164 , V_86 ) ) ;
V_160 -> V_166 = ( V_160 -> V_72 < V_160 -> V_165 ) ;
}
static void F_115 ( struct V_167 * V_168 ,
struct V_26 * V_29 , long V_169 )
{
if ( V_168 -> V_170 )
F_116 ( V_168 -> V_170 ) ;
V_168 -> V_170 = V_29 ;
V_168 -> V_171 = V_169 ;
V_168 -> V_172 = V_168 -> V_153 ;
}
static bool F_117 ( long V_173 , long V_174 ,
struct V_167 * V_168 )
{
long V_175 , V_176 ;
long V_177 , V_178 ;
long V_179 , V_180 ;
V_179 = V_168 -> V_181 . V_164 ;
V_180 = V_168 -> V_182 . V_164 ;
if ( V_174 < V_173 )
F_118 ( V_174 , V_173 ) ;
V_175 = V_174 * V_179 * 100 -
V_173 * V_180 * V_168 -> V_183 ;
if ( V_175 <= 0 )
return false ;
V_177 = V_168 -> V_181 . V_70 ;
V_178 = V_168 -> V_182 . V_70 ;
if ( V_178 < V_177 )
F_118 ( V_178 , V_177 ) ;
V_176 = V_178 * V_179 * 100 -
V_177 * V_180 * V_168 -> V_183 ;
return ( V_175 > V_176 ) ;
}
static void F_119 ( struct V_167 * V_168 ,
long V_184 , long V_185 )
{
struct V_24 * V_186 = F_111 ( V_168 -> V_187 ) ;
struct V_24 * V_188 = F_111 ( V_168 -> V_153 ) ;
struct V_26 * V_189 ;
long V_173 , V_174 ;
long V_70 ;
long V_169 = V_168 -> V_29 -> V_122 ? V_185 : V_184 ;
long V_190 = V_169 ;
int V_144 = V_168 -> V_144 ;
bool V_191 = false ;
F_120 () ;
F_121 ( & V_188 -> V_192 ) ;
V_189 = V_188 -> V_45 ;
if ( ( V_189 -> V_98 & V_193 ) || F_122 ( V_189 ) )
V_189 = NULL ;
else {
F_123 ( V_189 ) ;
}
F_124 ( & V_188 -> V_192 ) ;
if ( V_189 == V_168 -> V_29 )
goto V_194;
if ( V_189 ) {
if ( ! F_125 ( V_168 -> V_187 , F_126 ( V_189 ) ) )
goto V_194;
if ( V_189 -> V_122 == V_168 -> V_29 -> V_122 ) {
V_169 = V_184 + F_100 ( V_189 , V_168 -> V_152 , V_144 ) -
F_100 ( V_189 , V_168 -> V_154 , V_144 ) ;
if ( V_189 -> V_122 )
V_169 -= V_169 / 16 ;
} else {
if ( V_189 -> V_122 )
V_169 += F_101 ( V_189 , V_168 -> V_152 , V_144 ) -
F_101 ( V_189 , V_168 -> V_154 , V_144 ) ;
else
V_169 += F_100 ( V_189 , V_168 -> V_152 , V_144 ) -
F_100 ( V_189 , V_168 -> V_154 , V_144 ) ;
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
V_70 = F_127 ( V_168 -> V_29 ) ;
V_174 = V_168 -> V_182 . V_70 + V_70 ;
V_173 = V_168 -> V_181 . V_70 - V_70 ;
if ( V_190 > V_169 && V_190 > V_168 -> V_171 ) {
if ( ! F_117 ( V_173 , V_174 , V_168 ) ) {
V_169 = V_190 - 1 ;
F_116 ( V_189 ) ;
V_189 = NULL ;
goto V_196;
}
}
if ( V_169 <= V_168 -> V_171 )
goto V_194;
if ( V_189 ) {
V_70 = F_127 ( V_189 ) ;
V_174 -= V_70 ;
V_173 += V_70 ;
}
if ( F_117 ( V_173 , V_174 , V_168 ) )
goto V_194;
if ( ! V_189 )
V_168 -> V_153 = F_128 ( V_168 -> V_29 , V_168 -> V_153 ) ;
V_196:
V_191 = true ;
F_115 ( V_168 , V_189 , V_169 ) ;
V_194:
F_129 () ;
if ( V_189 && ! V_191 )
F_116 ( V_189 ) ;
}
static void F_130 ( struct V_167 * V_168 ,
long V_184 , long V_185 )
{
int V_162 ;
F_110 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_125 ( V_162 , F_126 ( V_168 -> V_29 ) ) )
continue;
V_168 -> V_153 = V_162 ;
F_119 ( V_168 , V_184 , V_185 ) ;
}
}
static bool F_131 ( struct V_167 * V_168 )
{
struct V_159 * V_197 = & V_168 -> V_181 ;
struct V_159 * V_198 = & V_168 -> V_182 ;
if ( V_197 -> V_166 && ! V_198 -> V_166 )
return false ;
if ( V_197 -> V_70 * V_198 -> V_164 * V_168 -> V_183 >
V_198 -> V_70 * V_197 -> V_164 * 100 )
return true ;
return false ;
}
static int F_132 ( struct V_26 * V_29 )
{
struct V_167 V_168 = {
. V_29 = V_29 ,
. V_187 = F_133 ( V_29 ) ,
. V_152 = F_89 ( V_29 ) ,
. V_183 = 112 ,
. V_170 = NULL ,
. V_171 = 0 ,
. V_172 = - 1 ,
} ;
struct V_199 * V_200 ;
unsigned long V_201 , V_202 ;
int V_126 , V_66 , V_144 ;
long V_184 , V_185 ;
F_120 () ;
V_200 = F_134 ( F_135 ( V_203 , V_168 . V_187 ) ) ;
if ( V_200 )
V_168 . V_183 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
F_129 () ;
if ( F_13 ( ! V_200 ) ) {
V_29 -> V_120 = F_89 ( V_29 ) ;
return - V_204 ;
}
V_168 . V_154 = V_29 -> V_120 ;
V_144 = V_168 . V_144 = F_99 ( V_168 . V_152 , V_168 . V_154 ) ;
V_201 = F_100 ( V_29 , V_168 . V_152 , V_144 ) ;
V_202 = F_101 ( V_29 , V_168 . V_152 , V_144 ) ;
F_109 ( & V_168 . V_181 , V_168 . V_152 ) ;
V_184 = F_100 ( V_29 , V_168 . V_154 , V_144 ) - V_201 ;
V_185 = F_101 ( V_29 , V_168 . V_154 , V_144 ) - V_202 ;
F_109 ( & V_168 . V_182 , V_168 . V_154 ) ;
if ( F_131 ( & V_168 ) )
F_130 ( & V_168 , V_184 , V_185 ) ;
if ( V_168 . V_172 == - 1 || ( V_29 -> V_122 && V_29 -> V_122 -> V_205 > 1 ) ) {
F_98 (nid) {
if ( V_126 == V_168 . V_152 || V_126 == V_29 -> V_120 )
continue;
V_144 = F_99 ( V_168 . V_152 , V_168 . V_154 ) ;
if ( V_142 == V_146 &&
V_144 != V_168 . V_144 ) {
V_201 = F_100 ( V_29 , V_168 . V_152 , V_144 ) ;
V_202 = F_101 ( V_29 , V_168 . V_152 , V_144 ) ;
}
V_184 = F_100 ( V_29 , V_126 , V_144 ) - V_201 ;
V_185 = F_101 ( V_29 , V_126 , V_144 ) - V_202 ;
if ( V_184 < 0 && V_185 < 0 )
continue;
V_168 . V_144 = V_144 ;
V_168 . V_154 = V_126 ;
F_109 ( & V_168 . V_182 , V_168 . V_154 ) ;
if ( F_131 ( & V_168 ) )
F_130 ( & V_168 , V_184 , V_185 ) ;
}
}
if ( V_29 -> V_122 ) {
struct V_122 * V_135 = V_29 -> V_122 ;
if ( V_168 . V_172 == - 1 )
V_126 = V_168 . V_152 ;
else
V_126 = V_168 . V_154 ;
if ( V_135 -> V_205 > 1 && F_96 ( V_168 . V_154 , V_135 ) )
F_136 ( V_29 , V_168 . V_154 ) ;
}
if ( V_168 . V_172 == - 1 )
return - V_206 ;
V_29 -> V_207 = F_84 ( V_29 ) ;
if ( V_168 . V_170 == NULL ) {
V_66 = F_137 ( V_29 , V_168 . V_172 ) ;
if ( V_66 != 0 )
F_138 ( V_29 , V_168 . V_187 , V_168 . V_172 ) ;
return V_66 ;
}
V_66 = F_139 ( V_29 , V_168 . V_170 ) ;
if ( V_66 != 0 )
F_138 ( V_29 , V_168 . V_187 , F_133 ( V_168 . V_170 ) ) ;
F_116 ( V_168 . V_170 ) ;
return V_66 ;
}
static void F_140 ( struct V_26 * V_29 )
{
unsigned long V_208 = V_209 ;
if ( F_13 ( V_29 -> V_120 == - 1 || ! V_29 -> V_130 ) )
return;
V_208 = F_141 ( V_208 , F_142 ( V_29 -> V_207 ) / 16 ) ;
V_29 -> V_210 = V_211 + V_208 ;
if ( F_89 ( V_29 ) == V_29 -> V_120 )
return;
F_132 ( V_29 ) ;
}
static void F_143 ( struct V_122 * V_122 )
{
unsigned long V_132 , V_212 = 0 ;
int V_126 , V_205 = 0 ;
F_98 (nid) {
V_132 = F_95 ( V_122 , V_126 ) ;
if ( V_132 > V_212 )
V_212 = V_132 ;
}
F_98 (nid) {
V_132 = F_95 ( V_122 , V_126 ) ;
if ( V_132 * V_136 > V_212 )
V_205 ++ ;
}
V_122 -> V_137 = V_212 ;
V_122 -> V_205 = V_205 ;
}
static void F_144 ( struct V_26 * V_29 ,
unsigned long V_213 , unsigned long V_214 )
{
unsigned int V_215 ;
int V_216 ;
int V_217 ;
unsigned long V_218 = V_29 -> V_219 [ 0 ] ;
unsigned long V_220 = V_29 -> V_219 [ 1 ] ;
if ( V_220 + V_213 == 0 || V_29 -> V_219 [ 2 ] ) {
V_29 -> V_207 = F_141 ( V_29 -> V_221 ,
V_29 -> V_207 << 1 ) ;
V_29 -> V_110 -> V_222 = V_211 +
F_142 ( V_29 -> V_207 ) ;
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
V_29 -> V_207 = F_145 ( V_29 -> V_207 + V_217 ,
F_84 ( V_29 ) , F_87 ( V_29 ) ) ;
memset ( V_29 -> V_219 , 0 , sizeof( V_29 -> V_219 ) ) ;
}
static T_2 F_146 ( struct V_26 * V_29 , T_2 * V_226 )
{
T_2 V_227 , V_42 , V_87 ;
V_87 = V_29 -> V_28 . V_88 ;
V_227 = V_29 -> V_28 . V_91 ;
if ( V_29 -> V_228 ) {
V_42 = V_227 - V_29 -> V_229 ;
* V_226 = V_87 - V_29 -> V_228 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_70 . V_4 ;
* V_226 = V_82 ;
}
V_29 -> V_229 = V_227 ;
V_29 -> V_228 = V_87 ;
return V_42 ;
}
static int F_147 ( struct V_26 * V_29 , int V_126 )
{
T_8 V_230 ;
int V_144 ;
if ( V_142 == V_143 )
return V_126 ;
if ( V_142 == V_147 ) {
unsigned long V_140 , V_231 = 0 ;
int V_141 , V_232 = V_126 ;
V_144 = V_145 ;
F_98 (node) {
V_140 = F_101 ( V_29 , V_141 , V_144 ) ;
if ( V_140 > V_231 ) {
V_231 = V_140 ;
V_232 = V_141 ;
}
}
return V_232 ;
}
V_230 = V_233 ;
for ( V_144 = V_145 ; V_144 > V_148 ; V_144 -- ) {
unsigned long V_212 = 0 ;
T_8 V_234 = V_235 ;
int V_43 , V_44 ;
if ( ! F_148 ( V_144 ) )
continue;
F_149 (a, nodes) {
unsigned long V_132 = 0 ;
T_8 V_236 ;
F_150 ( V_236 ) ;
F_149 (b, nodes) {
if ( F_99 ( V_43 , V_44 ) < V_144 ) {
V_132 += F_94 ( V_29 , V_44 ) ;
F_151 ( V_44 , V_236 ) ;
F_152 ( V_44 , V_230 ) ;
}
}
if ( V_132 > V_212 ) {
V_212 = V_132 ;
V_234 = V_236 ;
V_126 = V_43 ;
}
}
if ( ! V_212 )
break;
V_230 = V_234 ;
}
return V_126 ;
}
static void F_153 ( struct V_26 * V_29 )
{
int V_237 , V_126 , V_238 = - 1 , V_239 = - 1 ;
unsigned long V_212 = 0 , V_240 = 0 ;
unsigned long V_241 [ 2 ] = { 0 , 0 } ;
unsigned long V_149 ;
T_2 V_227 , V_226 ;
T_9 * V_242 = NULL ;
V_237 = F_85 ( V_29 -> V_110 -> V_243 ) ;
if ( V_29 -> V_243 == V_237 )
return;
V_29 -> V_243 = V_237 ;
V_29 -> V_221 = F_87 ( V_29 ) ;
V_149 = V_29 -> V_219 [ 0 ] +
V_29 -> V_219 [ 1 ] ;
V_227 = F_146 ( V_29 , & V_226 ) ;
if ( V_29 -> V_122 ) {
V_242 = & V_29 -> V_122 -> V_192 ;
F_154 ( V_242 ) ;
}
F_98 (nid) {
int V_244 , V_245 , V_246 , V_247 ;
unsigned long V_132 = 0 , F_94 = 0 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
long V_217 , V_248 , V_249 ;
V_244 = F_92 ( V_131 , V_126 , V_127 ) ;
V_245 = F_92 ( V_250 , V_126 , V_127 ) ;
V_246 = F_92 ( V_251 , V_126 , V_127 ) ;
V_247 = F_92 ( V_252 , V_126 , V_127 ) ;
V_217 = V_29 -> V_130 [ V_245 ] - V_29 -> V_130 [ V_244 ] / 2 ;
V_241 [ V_127 ] += V_29 -> V_130 [ V_245 ] ;
V_29 -> V_130 [ V_245 ] = 0 ;
V_249 = F_155 ( V_227 << 16 , V_226 + 1 ) ;
V_249 = ( V_249 * V_29 -> V_130 [ V_247 ] ) /
( V_149 + 1 ) ;
V_248 = V_249 - V_29 -> V_130 [ V_246 ] / 2 ;
V_29 -> V_130 [ V_247 ] = 0 ;
V_29 -> V_130 [ V_244 ] += V_217 ;
V_29 -> V_130 [ V_246 ] += V_248 ;
V_132 += V_29 -> V_130 [ V_244 ] ;
V_29 -> V_150 += V_217 ;
if ( V_29 -> V_122 ) {
V_29 -> V_122 -> V_132 [ V_244 ] += V_217 ;
V_29 -> V_122 -> V_134 [ V_244 ] += V_248 ;
V_29 -> V_122 -> V_149 += V_217 ;
F_94 += V_29 -> V_122 -> V_132 [ V_244 ] ;
}
}
if ( V_132 > V_212 ) {
V_212 = V_132 ;
V_238 = V_126 ;
}
if ( F_94 > V_240 ) {
V_240 = F_94 ;
V_239 = V_126 ;
}
}
F_144 ( V_29 , V_241 [ 0 ] , V_241 [ 1 ] ) ;
if ( V_29 -> V_122 ) {
F_143 ( V_29 -> V_122 ) ;
F_156 ( V_242 ) ;
V_238 = F_147 ( V_29 , V_239 ) ;
}
if ( V_212 ) {
if ( V_238 != V_29 -> V_120 )
F_136 ( V_29 , V_238 ) ;
if ( F_89 ( V_29 ) != V_29 -> V_120 )
F_140 ( V_29 ) ;
}
}
static inline int F_157 ( struct V_122 * V_30 )
{
return F_158 ( & V_30 -> V_253 ) ;
}
static inline void F_159 ( struct V_122 * V_30 )
{
if ( F_160 ( & V_30 -> V_253 ) )
F_161 ( V_30 , V_254 ) ;
}
static void F_162 ( struct V_26 * V_29 , int V_255 , int V_98 ,
int * V_127 )
{
struct V_122 * V_30 , * V_256 ;
struct V_26 * V_100 ;
bool V_257 = false ;
int V_162 = F_163 ( V_255 ) ;
int V_258 ;
if ( F_13 ( ! V_29 -> V_122 ) ) {
unsigned int V_259 = sizeof( struct V_122 ) +
4 * V_129 *sizeof( unsigned long ) ;
V_30 = F_164 ( V_259 , V_260 | V_261 ) ;
if ( ! V_30 )
return;
F_165 ( & V_30 -> V_253 , 1 ) ;
V_30 -> V_205 = 1 ;
V_30 -> V_137 = 0 ;
F_166 ( & V_30 -> V_192 ) ;
V_30 -> V_123 = V_29 -> V_158 ;
V_30 -> V_134 = V_30 -> V_132 + V_128 *
V_129 ;
for ( V_258 = 0 ; V_258 < V_262 * V_129 ; V_258 ++ )
V_30 -> V_132 [ V_258 ] = V_29 -> V_130 [ V_258 ] ;
V_30 -> V_149 = V_29 -> V_150 ;
V_30 -> V_263 ++ ;
F_167 ( V_29 -> V_122 , V_30 ) ;
}
F_120 () ;
V_100 = F_85 ( F_111 ( V_162 ) -> V_45 ) ;
if ( ! F_108 ( V_100 , V_255 ) )
goto V_264;
V_30 = F_134 ( V_100 -> V_122 ) ;
if ( ! V_30 )
goto V_264;
V_256 = V_29 -> V_122 ;
if ( V_30 == V_256 )
goto V_264;
if ( V_256 -> V_263 > V_30 -> V_263 )
goto V_264;
if ( V_256 -> V_263 == V_30 -> V_263 && V_256 > V_30 )
goto V_264;
if ( V_100 -> V_110 == V_157 -> V_110 )
V_257 = true ;
if ( V_98 & V_265 )
V_257 = true ;
* V_127 = ! V_257 ;
if ( V_257 && ! F_157 ( V_30 ) )
goto V_264;
F_129 () ;
if ( ! V_257 )
return;
F_168 ( F_169 () ) ;
F_170 ( & V_256 -> V_192 , & V_30 -> V_192 ) ;
for ( V_258 = 0 ; V_258 < V_262 * V_129 ; V_258 ++ ) {
V_256 -> V_132 [ V_258 ] -= V_29 -> V_130 [ V_258 ] ;
V_30 -> V_132 [ V_258 ] += V_29 -> V_130 [ V_258 ] ;
}
V_256 -> V_149 -= V_29 -> V_150 ;
V_30 -> V_149 += V_29 -> V_150 ;
V_256 -> V_263 -- ;
V_30 -> V_263 ++ ;
F_171 ( & V_256 -> V_192 ) ;
F_156 ( & V_30 -> V_192 ) ;
F_167 ( V_29 -> V_122 , V_30 ) ;
F_159 ( V_256 ) ;
return;
V_264:
F_129 () ;
return;
}
void F_172 ( struct V_26 * V_29 )
{
struct V_122 * V_30 = V_29 -> V_122 ;
void * V_130 = V_29 -> V_130 ;
unsigned long V_98 ;
int V_258 ;
if ( V_30 ) {
F_173 ( & V_30 -> V_192 , V_98 ) ;
for ( V_258 = 0 ; V_258 < V_262 * V_129 ; V_258 ++ )
V_30 -> V_132 [ V_258 ] -= V_29 -> V_130 [ V_258 ] ;
V_30 -> V_149 -= V_29 -> V_150 ;
V_30 -> V_263 -- ;
F_174 ( & V_30 -> V_192 , V_98 ) ;
F_175 ( V_29 -> V_122 , NULL ) ;
F_159 ( V_30 ) ;
}
V_29 -> V_130 = NULL ;
F_176 ( V_130 ) ;
}
void F_177 ( int V_155 , int V_266 , int V_267 , int V_98 )
{
struct V_26 * V_29 = V_157 ;
bool V_268 = V_98 & V_269 ;
int V_270 = F_89 ( V_157 ) ;
int V_220 = ! ! ( V_98 & V_271 ) ;
struct V_122 * V_135 ;
int V_127 ;
if ( ! F_178 ( & V_272 ) )
return;
if ( ! V_29 -> V_110 )
return;
if ( F_13 ( ! V_29 -> V_130 ) ) {
int V_259 = sizeof( * V_29 -> V_130 ) *
V_273 * V_129 ;
V_29 -> V_130 = F_164 ( V_259 , V_260 | V_261 ) ;
if ( ! V_29 -> V_130 )
return;
V_29 -> V_150 = 0 ;
memset ( V_29 -> V_219 , 0 , sizeof( V_29 -> V_219 ) ) ;
}
if ( F_13 ( V_155 == ( - 1 & V_274 ) ) ) {
V_127 = 1 ;
} else {
V_127 = F_108 ( V_29 , V_155 ) ;
if ( ! V_127 && ! ( V_98 & V_275 ) )
F_162 ( V_29 , V_155 , V_98 , & V_127 ) ;
}
V_135 = V_29 -> V_122 ;
if ( ! V_127 && ! V_220 && V_135 && V_135 -> V_205 > 1 &&
F_96 ( V_270 , V_135 ) &&
F_96 ( V_266 , V_135 ) )
V_220 = 1 ;
F_153 ( V_29 ) ;
if ( F_179 ( V_211 , V_29 -> V_210 ) )
F_140 ( V_29 ) ;
if ( V_268 )
V_29 -> V_276 += V_267 ;
if ( V_98 & V_277 )
V_29 -> V_219 [ 2 ] += V_267 ;
V_29 -> V_130 [ F_92 ( V_250 , V_266 , V_127 ) ] += V_267 ;
V_29 -> V_130 [ F_92 ( V_252 , V_270 , V_127 ) ] += V_267 ;
V_29 -> V_219 [ V_220 ] += V_267 ;
}
static void F_180 ( struct V_26 * V_29 )
{
F_181 ( V_29 -> V_110 -> V_243 , F_85 ( V_29 -> V_110 -> V_243 ) + 1 ) ;
V_29 -> V_110 -> V_278 = 0 ;
}
void F_182 ( struct V_279 * V_280 )
{
unsigned long V_281 , V_282 , V_87 = V_211 ;
struct V_26 * V_29 = V_157 ;
struct V_283 * V_110 = V_29 -> V_110 ;
T_2 V_227 = V_29 -> V_28 . V_91 ;
struct V_284 * V_285 ;
unsigned long V_286 , V_287 ;
unsigned long V_288 = 0 ;
long V_267 , V_289 ;
F_19 ( V_29 != F_21 ( V_280 , struct V_26 , V_290 ) ) ;
V_280 -> V_58 = V_280 ;
if ( V_29 -> V_98 & V_193 )
return;
if ( ! V_110 -> V_222 ) {
V_110 -> V_222 = V_87 +
F_142 ( V_291 ) ;
}
V_281 = V_110 -> V_222 ;
if ( F_183 ( V_87 , V_281 ) )
return;
if ( V_29 -> V_207 == 0 ) {
V_29 -> V_221 = F_87 ( V_29 ) ;
V_29 -> V_207 = F_84 ( V_29 ) ;
}
V_282 = V_87 + F_142 ( V_29 -> V_207 ) ;
if ( F_184 ( & V_110 -> V_222 , V_281 , V_282 ) != V_281 )
return;
V_29 -> V_292 += 2 * V_293 ;
V_286 = V_110 -> V_278 ;
V_267 = V_108 ;
V_267 <<= 20 - V_109 ;
V_289 = V_267 * 8 ;
if ( ! V_267 )
return;
F_185 ( & V_110 -> V_294 ) ;
V_285 = F_186 ( V_110 , V_286 ) ;
if ( ! V_285 ) {
F_180 ( V_29 ) ;
V_286 = 0 ;
V_285 = V_110 -> V_295 ;
}
for (; V_285 ; V_285 = V_285 -> V_296 ) {
if ( ! F_187 ( V_285 ) || ! F_188 ( V_285 ) ||
F_189 ( V_285 ) || ( V_285 -> V_297 & V_298 ) ) {
continue;
}
if ( ! V_285 -> V_299 ||
( V_285 -> V_300 && ( V_285 -> V_297 & ( V_301 | V_302 ) ) == ( V_301 ) ) )
continue;
if ( ! ( V_285 -> V_297 & ( V_301 | V_303 | V_302 ) ) )
continue;
do {
V_286 = F_66 ( V_286 , V_285 -> V_304 ) ;
V_287 = F_190 ( V_286 + ( V_267 << V_109 ) , V_305 ) ;
V_287 = F_141 ( V_287 , V_285 -> V_306 ) ;
V_288 = F_191 ( V_285 , V_286 , V_287 ) ;
if ( V_288 )
V_267 -= ( V_287 - V_286 ) >> V_109 ;
V_289 -= ( V_287 - V_286 ) >> V_109 ;
V_286 = V_287 ;
if ( V_267 <= 0 || V_289 <= 0 )
goto V_307;
F_192 () ;
} while ( V_287 != V_285 -> V_306 );
}
V_307:
if ( V_285 )
V_110 -> V_278 = V_286 ;
else
F_180 ( V_29 ) ;
F_193 ( & V_110 -> V_294 ) ;
if ( F_13 ( V_29 -> V_28 . V_91 != V_227 ) ) {
T_2 V_217 = V_29 -> V_28 . V_91 - V_227 ;
V_29 -> V_292 += 32 * V_217 ;
}
}
void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_279 * V_280 = & V_45 -> V_290 ;
T_2 V_226 , V_87 ;
if ( ! V_45 -> V_110 || ( V_45 -> V_98 & V_193 ) || V_280 -> V_58 != V_280 )
return;
V_87 = V_45 -> V_28 . V_91 ;
V_226 = ( T_2 ) V_45 -> V_207 * V_308 ;
if ( V_87 > V_45 -> V_292 + V_226 ) {
if ( ! V_45 -> V_292 )
V_45 -> V_207 = F_84 ( V_45 ) ;
V_45 -> V_292 += V_226 ;
if ( ! F_183 ( V_211 , V_45 -> V_110 -> V_222 ) ) {
F_195 ( V_280 , F_182 ) ;
F_196 ( V_45 , V_280 , true ) ;
}
}
}
static void F_194 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_88 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
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
F_88 ( V_24 , F_17 ( V_28 ) ) ;
F_199 ( & V_28 -> V_309 , & V_24 -> V_310 ) ;
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
#ifdef F_198
if ( F_20 ( V_28 ) ) {
F_90 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_201 ( & V_28 -> V_309 ) ;
}
#endif
V_25 -> V_72 -- ;
}
static long F_202 ( struct V_25 * V_25 , struct V_311 * V_33 )
{
long V_312 , V_70 , V_313 ;
V_70 = F_12 ( V_25 -> V_70 . V_4 ) ;
V_312 = F_203 ( & V_33 -> V_80 ) ;
V_312 -= V_25 -> V_314 ;
V_312 += V_70 ;
V_313 = ( V_33 -> V_313 * V_70 ) ;
if ( V_312 )
V_313 /= V_312 ;
if ( V_313 < V_315 )
V_313 = V_315 ;
if ( V_313 > V_33 -> V_313 )
V_313 = V_33 -> V_313 ;
return V_313 ;
}
static inline long F_202 ( struct V_25 * V_25 , struct V_311 * V_33 )
{
return V_33 -> V_313 ;
}
static void F_204 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_74 ) {
if ( V_25 -> V_45 == V_28 )
F_63 ( V_25 ) ;
F_200 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_74 )
F_197 ( V_25 , V_28 ) ;
}
static void F_205 ( struct V_25 * V_25 )
{
struct V_311 * V_33 ;
struct V_27 * V_28 ;
long V_313 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_206 ( V_25 ) )
return;
#ifndef F_198
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_313 ) )
return;
#endif
V_313 = F_202 ( V_25 , V_33 ) ;
F_204 ( F_23 ( V_28 ) , V_28 , V_313 ) ;
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
V_321 = V_324 [ V_317 / V_319 ] ;
V_317 %= V_319 ;
V_321 = F_207 ( V_321 , V_317 ) ;
return V_321 + V_322 [ V_317 ] ;
}
static T_10 int
F_209 ( T_2 V_87 , int V_162 , struct V_75 * V_76 ,
unsigned long V_4 , int V_325 , struct V_25 * V_25 )
{
T_2 V_42 , V_326 , V_327 ;
V_23 V_321 ;
unsigned int V_328 , V_329 , V_330 = 0 ;
unsigned long V_331 , V_332 ;
V_42 = V_87 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_87 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_87 ;
V_331 = F_210 ( NULL , V_162 ) ;
V_332 = F_211 ( NULL , V_162 ) ;
V_328 = V_76 -> V_79 ;
if ( V_42 + V_328 >= 1024 ) {
V_330 = 1 ;
V_76 -> V_79 = 0 ;
V_328 = 1024 - V_328 ;
V_329 = F_212 ( V_328 , V_331 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_329 ;
if ( V_25 ) {
V_25 -> V_333 +=
V_4 * V_329 ;
}
}
if ( V_325 )
V_76 -> V_84 += V_329 * V_332 ;
V_42 -= V_328 ;
V_327 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_207 ( V_76 -> V_81 , V_327 + 1 ) ;
if ( V_25 ) {
V_25 -> V_333 =
F_207 ( V_25 -> V_333 , V_327 + 1 ) ;
}
V_76 -> V_84 = F_207 ( ( T_2 ) ( V_76 -> V_84 ) , V_327 + 1 ) ;
V_321 = F_208 ( V_327 ) ;
V_321 = F_212 ( V_321 , V_331 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_321 ;
if ( V_25 )
V_25 -> V_333 += V_4 * V_321 ;
}
if ( V_325 )
V_76 -> V_84 += V_321 * V_332 ;
}
V_326 = F_212 ( V_42 , V_331 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_326 ;
if ( V_25 )
V_25 -> V_333 += V_4 * V_326 ;
}
if ( V_325 )
V_76 -> V_84 += V_326 * V_332 ;
V_76 -> V_79 += V_42 ;
if ( V_330 ) {
V_76 -> V_80 = F_213 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_334 =
F_213 ( V_25 -> V_333 , V_82 ) ;
}
V_76 -> V_83 = V_76 -> V_84 / V_82 ;
}
return V_330 ;
}
static inline void F_214 ( struct V_25 * V_25 , int V_335 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_314 ;
if ( V_25 -> V_33 == & V_336 )
return;
if ( V_335 || abs ( V_42 ) > V_25 -> V_314 / 64 ) {
F_215 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_314 = V_25 -> V_77 . V_80 ;
}
}
void F_216 ( struct V_27 * V_28 ,
struct V_25 * V_337 , struct V_25 * V_58 )
{
if ( ! F_217 ( V_338 ) )
return;
if ( V_28 -> V_77 . V_78 && V_337 ) {
T_2 V_339 ;
T_2 V_340 ;
#ifndef F_40
T_2 V_341 ;
T_2 V_342 ;
do {
V_341 = V_337 -> V_343 ;
V_342 = V_58 -> V_343 ;
F_218 () ;
V_339 = V_337 -> V_77 . V_78 ;
V_340 = V_58 -> V_77 . V_78 ;
} while ( V_339 != V_341 ||
V_340 != V_342 );
#else
V_339 = V_337 -> V_77 . V_78 ;
V_340 = V_58 -> V_77 . V_78 ;
#endif
F_209 ( V_339 , F_26 ( F_16 ( V_337 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
V_28 -> V_77 . V_78 = V_340 ;
}
}
static inline void F_214 ( struct V_25 * V_25 , int V_335 ) {}
static inline void F_219 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_162 = F_26 ( V_24 ) ;
if ( V_162 == F_220 () && & V_24 -> V_40 == V_25 ) {
unsigned long F_66 = V_24 -> V_344 ;
F_221 ( F_74 ( V_24 ) ,
F_141 ( V_25 -> V_77 . V_83 , F_66 ) , F_66 ) ;
}
}
static inline int
F_222 ( T_2 V_87 , struct V_25 * V_25 , bool V_345 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_330 , V_346 = 0 , V_347 = 0 ;
if ( F_203 ( & V_25 -> V_348 ) ) {
T_3 V_349 = F_223 ( & V_25 -> V_348 , 0 ) ;
F_224 ( & V_76 -> V_80 , V_349 ) ;
F_224 ( & V_76 -> V_81 , V_349 * V_82 ) ;
V_346 = 1 ;
}
if ( F_203 ( & V_25 -> V_350 ) ) {
long V_349 = F_223 ( & V_25 -> V_350 , 0 ) ;
F_224 ( & V_76 -> V_83 , V_349 ) ;
F_224 ( & V_76 -> V_84 , V_349 * V_82 ) ;
V_347 = 1 ;
}
V_330 = F_209 ( V_87 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_70 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_343 = V_76 -> V_78 ;
#endif
if ( V_345 && ( V_330 || V_347 ) )
F_219 ( V_25 ) ;
return V_330 || V_346 ;
}
static inline void F_225 ( struct V_27 * V_28 , int V_351 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_87 = F_226 ( V_25 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_162 = F_26 ( V_24 ) ;
F_209 ( V_87 , V_162 , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
if ( F_222 ( V_87 , V_25 , true ) && V_351 )
F_214 ( V_25 , 0 ) ;
}
static void F_227 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( ! F_217 ( V_338 ) )
goto V_352;
if ( V_28 -> V_77 . V_78 ) {
F_209 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
}
V_352:
V_28 -> V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_28 -> V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_28 -> V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_28 -> V_77 . V_83 ;
V_25 -> V_77 . V_84 += V_28 -> V_77 . V_84 ;
F_219 ( V_25 ) ;
}
static void F_228 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_209 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
F_224 ( & V_25 -> V_77 . V_80 , V_28 -> V_77 . V_80 ) ;
F_224 ( & V_25 -> V_77 . V_81 , V_28 -> V_77 . V_81 ) ;
F_224 ( & V_25 -> V_77 . V_83 , V_28 -> V_77 . V_83 ) ;
F_224 ( & V_25 -> V_77 . V_84 , V_28 -> V_77 . V_84 ) ;
F_219 ( V_25 ) ;
}
static inline void
F_229 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_87 = F_226 ( V_25 ) ;
int V_268 , V_330 ;
V_268 = ! V_76 -> V_78 ;
if ( ! V_268 ) {
F_209 ( V_87 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_330 = F_222 ( V_87 , V_25 , ! V_268 ) ;
V_25 -> V_334 += V_76 -> V_80 ;
V_25 -> V_333 += V_76 -> V_81 ;
if ( V_268 )
F_227 ( V_25 , V_28 ) ;
if ( V_330 || V_268 )
F_214 ( V_25 , 0 ) ;
}
static inline void
F_230 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_225 ( V_28 , 1 ) ;
V_25 -> V_334 =
F_86 ( long , V_25 -> V_334 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_333 =
F_86 ( T_3 , V_25 -> V_333 - V_28 -> V_77 . V_81 , 0 ) ;
}
static inline T_2 F_231 ( struct V_25 * V_25 )
{
T_2 V_353 ;
T_2 V_78 ;
do {
V_353 = V_25 -> V_343 ;
F_218 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_353 );
return V_78 ;
}
static inline T_2 F_231 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_78 ;
}
void F_232 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_78 ;
if ( V_28 -> V_77 . V_78 == 0 )
return;
V_78 = F_231 ( V_25 ) ;
F_209 ( V_78 , F_26 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_215 ( V_28 -> V_77 . V_80 , & V_25 -> V_348 ) ;
F_215 ( V_28 -> V_77 . V_83 , & V_25 -> V_350 ) ;
}
static inline unsigned long F_233 ( struct V_25 * V_25 )
{
return V_25 -> V_334 ;
}
static inline unsigned long F_234 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline void F_225 ( struct V_27 * V_28 , int V_354 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_235 ( F_74 ( V_24 ) ) ;
}
static inline void
F_229 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_230 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_232 ( struct V_27 * V_28 ) {}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_228 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline int F_236 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_237 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_238
struct V_26 * V_100 = NULL ;
if ( F_20 ( V_28 ) )
V_100 = F_17 ( V_28 ) ;
if ( V_28 -> V_89 . V_103 ) {
T_2 V_42 = F_74 ( F_16 ( V_25 ) ) - V_28 -> V_89 . V_103 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_89 . V_355 ) )
V_28 -> V_89 . V_355 = V_42 ;
V_28 -> V_89 . V_103 = 0 ;
V_28 -> V_89 . V_356 += V_42 ;
if ( V_100 ) {
F_239 ( V_100 , V_42 >> 10 , 1 ) ;
F_240 ( V_100 , V_42 ) ;
}
}
if ( V_28 -> V_89 . V_105 ) {
T_2 V_42 = F_74 ( F_16 ( V_25 ) ) - V_28 -> V_89 . V_105 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_89 . V_357 ) )
V_28 -> V_89 . V_357 = V_42 ;
V_28 -> V_89 . V_105 = 0 ;
V_28 -> V_89 . V_356 += V_42 ;
if ( V_100 ) {
if ( V_100 -> V_358 ) {
V_28 -> V_89 . V_359 += V_42 ;
V_28 -> V_89 . V_360 ++ ;
F_241 ( V_100 , V_42 ) ;
}
F_242 ( V_100 , V_42 ) ;
if ( F_13 ( V_361 == V_362 ) ) {
F_243 ( V_362 ,
( void * ) F_244 ( V_100 ) ,
V_42 >> 20 ) ;
}
F_239 ( V_100 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_245 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_363 = V_28 -> V_41 - V_25 -> F_36 ;
if ( V_363 < 0 )
V_363 = - V_363 ;
if ( V_363 > 3 * V_68 )
F_246 ( V_25 , V_364 ) ;
#endif
}
static void
F_247 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_365 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_365 && F_217 ( V_366 ) )
V_41 += F_60 ( V_25 , V_28 ) ;
if ( ! V_365 ) {
unsigned long V_367 = V_68 ;
if ( F_217 ( V_368 ) )
V_367 >>= 1 ;
V_41 -= V_367 ;
}
V_28 -> V_41 = F_35 ( V_28 -> V_41 , V_41 ) ;
}
static inline void F_248 ( void )
{
#ifdef F_238
if ( F_249 () )
return;
if ( F_250 () ||
F_251 () ||
F_252 () ||
F_253 () ||
F_254 () ) {
F_255 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_256 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_98 )
{
bool V_369 = ! ( V_98 & V_370 ) || ( V_98 & V_371 ) ;
bool V_45 = V_25 -> V_45 == V_28 ;
if ( V_369 && V_45 )
V_28 -> V_41 += V_25 -> F_36 ;
F_63 ( V_25 ) ;
if ( V_369 && ! V_45 )
V_28 -> V_41 += V_25 -> F_36 ;
F_229 ( V_25 , V_28 ) ;
F_197 ( V_25 , V_28 ) ;
F_205 ( V_25 ) ;
if ( V_98 & V_370 ) {
F_247 ( V_25 , V_28 , 0 ) ;
if ( F_249 () )
F_237 ( V_25 , V_28 ) ;
}
F_248 () ;
if ( F_249 () ) {
F_78 ( V_25 , V_28 ) ;
F_245 ( V_25 , V_28 ) ;
}
if ( ! V_45 )
F_42 ( V_25 , V_28 ) ;
V_28 -> V_74 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_257 ( V_25 ) ;
}
}
static void F_258 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_259 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_260 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_372 != V_28 )
break;
V_25 -> V_372 = NULL ;
}
}
static void F_261 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_258 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_259 ( V_28 ) ;
if ( V_25 -> V_372 == V_28 )
F_260 ( V_28 ) ;
}
static void
F_262 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_98 )
{
F_63 ( V_25 ) ;
F_230 ( V_25 , V_28 ) ;
if ( F_249 () )
F_79 ( V_25 , V_28 , V_98 ) ;
F_261 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_45 ( V_25 , V_28 ) ;
V_28 -> V_74 = 0 ;
F_200 ( V_25 , V_28 ) ;
if ( ! ( V_98 & V_99 ) )
V_28 -> V_41 -= V_25 -> F_36 ;
F_263 ( V_25 ) ;
F_38 ( V_25 ) ;
F_205 ( V_25 ) ;
}
static void
F_264 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_373 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_373 = F_58 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_91 - V_45 -> V_374 ;
if ( V_19 > V_373 ) {
F_265 ( F_16 ( V_25 ) ) ;
F_261 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_48 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_373 )
F_265 ( F_16 ( V_25 ) ) ;
}
static void
F_266 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_74 ) {
if ( F_249 () )
F_76 ( V_25 , V_28 ) ;
F_45 ( V_25 , V_28 ) ;
F_225 ( V_28 , 1 ) ;
}
F_80 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_238
if ( F_249 () && F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_89 . V_375 = F_66 ( V_28 -> V_89 . V_375 ,
V_28 -> V_91 - V_28 -> V_374 ) ;
}
#endif
V_28 -> V_374 = V_28 -> V_91 ;
}
static struct V_27 *
F_267 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_48 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_37 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_372 == V_28 ) {
struct V_27 * V_376 ;
if ( V_28 == V_45 ) {
V_376 = F_48 ( V_25 ) ;
} else {
V_376 = F_49 ( V_28 ) ;
if ( ! V_376 || ( V_45 && F_37 ( V_45 , V_376 ) ) )
V_376 = V_45 ;
}
if ( V_376 && F_268 ( V_376 , V_57 ) < 1 )
V_28 = V_376 ;
}
if ( V_25 -> V_59 && F_268 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_268 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_261 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_269 ( struct V_25 * V_25 , struct V_27 * V_337 )
{
if ( V_337 -> V_74 )
F_63 ( V_25 ) ;
F_270 ( V_25 ) ;
if ( F_249 () ) {
F_245 ( V_25 , V_337 ) ;
if ( V_337 -> V_74 )
F_73 ( V_25 , V_337 ) ;
}
if ( V_337 -> V_74 ) {
F_42 ( V_25 , V_337 ) ;
F_225 ( V_337 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_271 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_377 )
{
F_63 ( V_25 ) ;
F_225 ( V_45 , 1 ) ;
F_205 ( V_25 ) ;
#ifdef F_272
if ( V_377 ) {
F_265 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_217 ( V_378 ) &&
F_273 ( & F_16 ( V_25 ) -> V_379 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_264 ( V_25 , V_45 ) ;
}
static inline bool F_274 ( void )
{
return F_275 ( & V_380 ) ;
}
void F_276 ( void )
{
F_277 ( & V_380 ) ;
}
void F_278 ( void )
{
F_279 ( & V_380 ) ;
}
static bool F_274 ( void )
{
return true ;
}
void F_276 ( void ) {}
void F_278 ( void ) {}
static inline T_2 F_280 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_281 ( void )
{
return ( T_2 ) V_381 * V_382 ;
}
void F_282 ( struct V_383 * V_384 )
{
T_2 V_87 ;
if ( V_384 -> V_385 == V_386 )
return;
V_87 = F_283 ( F_220 () ) ;
V_384 -> V_227 = V_384 -> V_385 ;
V_384 -> V_387 = V_87 + F_284 ( V_384 -> V_226 ) ;
}
static inline struct V_383 * F_285 ( struct V_311 * V_33 )
{
return & V_33 -> V_383 ;
}
static inline T_2 F_226 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_388 ) )
return V_25 -> V_389 ;
return F_64 ( F_16 ( V_25 ) ) - V_25 -> V_390 ;
}
static int F_286 ( struct V_25 * V_25 )
{
struct V_311 * V_33 = V_25 -> V_33 ;
struct V_383 * V_384 = F_285 ( V_33 ) ;
T_2 V_391 = 0 , V_392 , V_393 ;
V_392 = F_281 () - V_25 -> V_394 ;
F_287 ( & V_384 -> V_192 ) ;
if ( V_384 -> V_385 == V_386 )
V_391 = V_392 ;
else {
F_288 ( V_384 ) ;
if ( V_384 -> V_227 > 0 ) {
V_391 = F_141 ( V_384 -> V_227 , V_392 ) ;
V_384 -> V_227 -= V_391 ;
V_384 -> V_395 = 0 ;
}
}
V_393 = V_384 -> V_387 ;
F_289 ( & V_384 -> V_192 ) ;
V_25 -> V_394 += V_391 ;
if ( ( T_3 ) ( V_393 - V_25 -> V_387 ) > 0 )
V_25 -> V_387 = V_393 ;
return V_25 -> V_394 > 0 ;
}
static void F_290 ( struct V_25 * V_25 )
{
struct V_383 * V_384 = F_285 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_74 ( F_16 ( V_25 ) ) - V_25 -> V_387 ) < 0 ) )
return;
if ( V_25 -> V_394 < 0 )
return;
if ( V_25 -> V_387 != V_384 -> V_387 ) {
V_25 -> V_387 += V_293 ;
} else {
V_25 -> V_394 = 0 ;
}
}
static void F_291 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_394 -= V_19 ;
F_290 ( V_25 ) ;
if ( F_11 ( V_25 -> V_394 > 0 ) )
return;
if ( ! F_286 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_265 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_71 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_274 () || ! V_25 -> V_396 )
return;
F_291 ( V_25 , V_19 ) ;
}
static inline int F_292 ( struct V_25 * V_25 )
{
return F_274 () && V_25 -> V_397 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return F_274 () && V_25 -> V_388 ;
}
static inline int F_293 ( struct V_311 * V_33 ,
int V_187 , int V_398 )
{
struct V_25 * V_399 , * V_400 ;
V_399 = V_33 -> V_25 [ V_187 ] ;
V_400 = V_33 -> V_25 [ V_398 ] ;
return F_206 ( V_399 ) ||
F_206 ( V_400 ) ;
}
static int F_294 ( struct V_311 * V_33 , void * V_401 )
{
struct V_24 * V_24 = V_401 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_388 -- ;
#ifdef F_198
if ( ! V_25 -> V_388 ) {
V_25 -> V_390 += F_64 ( V_24 ) -
V_25 -> V_389 ;
}
#endif
return 0 ;
}
static int F_295 ( struct V_311 * V_33 , void * V_401 )
{
struct V_24 * V_24 = V_401 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_388 )
V_25 -> V_389 = F_64 ( V_24 ) ;
V_25 -> V_388 ++ ;
return 0 ;
}
static void F_296 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_383 * V_384 = F_285 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_402 , V_403 = 1 ;
bool V_404 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_120 () ;
F_297 ( V_25 -> V_33 , F_295 , V_405 , ( void * ) V_24 ) ;
F_129 () ;
V_402 = V_25 -> V_406 ;
F_59 (se) {
struct V_25 * V_407 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_74 )
break;
if ( V_403 )
F_262 ( V_407 , V_28 , V_99 ) ;
V_407 -> V_406 -= V_402 ;
if ( V_407 -> V_70 . V_4 )
V_403 = 0 ;
}
if ( ! V_28 )
F_298 ( V_24 , V_402 ) ;
V_25 -> V_397 = 1 ;
V_25 -> V_408 = F_74 ( V_24 ) ;
F_287 ( & V_384 -> V_192 ) ;
V_404 = F_299 ( & V_384 -> V_409 ) ;
F_27 ( & V_25 -> V_410 , & V_384 -> V_409 ) ;
if ( V_404 )
F_288 ( V_384 ) ;
F_289 ( & V_384 -> V_192 ) ;
}
void F_300 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_383 * V_384 = F_285 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_411 = 1 ;
long V_402 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_397 = 0 ;
F_301 ( V_24 ) ;
F_287 ( & V_384 -> V_192 ) ;
V_384 -> V_412 += F_74 ( V_24 ) - V_25 -> V_408 ;
F_30 ( & V_25 -> V_410 ) ;
F_289 ( & V_384 -> V_192 ) ;
F_297 ( V_25 -> V_33 , V_405 , F_294 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_402 = V_25 -> V_406 ;
F_59 (se) {
if ( V_28 -> V_74 )
V_411 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_411 )
F_256 ( V_25 , V_28 , V_370 ) ;
V_25 -> V_406 += V_402 ;
if ( F_292 ( V_25 ) )
break;
}
if ( ! V_28 )
F_302 ( V_24 , V_402 ) ;
if ( V_24 -> V_45 == V_24 -> V_395 && V_24 -> V_40 . V_72 )
F_265 ( V_24 ) ;
}
static T_2 F_303 ( struct V_383 * V_384 ,
T_2 V_413 , T_2 V_393 )
{
struct V_25 * V_25 ;
T_2 V_227 ;
T_2 V_414 = V_413 ;
F_120 () ;
F_304 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_287 ( & V_24 -> V_192 ) ;
if ( ! F_292 ( V_25 ) )
goto V_58;
V_227 = - V_25 -> V_394 + 1 ;
if ( V_227 > V_413 )
V_227 = V_413 ;
V_413 -= V_227 ;
V_25 -> V_394 += V_227 ;
V_25 -> V_387 = V_393 ;
if ( V_25 -> V_394 > 0 )
F_300 ( V_25 ) ;
V_58:
F_289 ( & V_24 -> V_192 ) ;
if ( ! V_413 )
break;
}
F_129 () ;
return V_414 - V_413 ;
}
static int F_305 ( struct V_383 * V_384 , int V_415 )
{
T_2 V_227 , V_387 ;
int V_397 ;
if ( V_384 -> V_385 == V_386 )
goto V_416;
V_397 = ! F_299 ( & V_384 -> V_409 ) ;
V_384 -> V_417 += V_415 ;
if ( V_384 -> V_395 && ! V_397 )
goto V_416;
F_282 ( V_384 ) ;
if ( ! V_397 ) {
V_384 -> V_395 = 1 ;
return 0 ;
}
V_384 -> V_418 += V_415 ;
V_387 = V_384 -> V_387 ;
while ( V_397 && V_384 -> V_227 > 0 ) {
V_227 = V_384 -> V_227 ;
F_289 ( & V_384 -> V_192 ) ;
V_227 = F_303 ( V_384 , V_227 ,
V_387 ) ;
F_287 ( & V_384 -> V_192 ) ;
V_397 = ! F_299 ( & V_384 -> V_409 ) ;
V_384 -> V_227 -= F_141 ( V_227 , V_384 -> V_227 ) ;
}
V_384 -> V_395 = 0 ;
return 0 ;
V_416:
return 1 ;
}
static int F_306 ( struct V_383 * V_384 , T_2 V_419 )
{
struct V_420 * V_421 = & V_384 -> V_422 ;
T_2 V_413 ;
if ( F_307 ( V_421 ) )
return 1 ;
V_413 = F_284 ( F_308 ( V_421 ) ) ;
if ( V_413 < V_419 )
return 1 ;
return 0 ;
}
static void F_309 ( struct V_383 * V_384 )
{
T_2 V_423 = V_424 + V_425 ;
if ( F_306 ( V_384 , V_423 ) )
return;
F_310 ( & V_384 -> V_426 ,
F_311 ( V_424 ) ,
V_427 ) ;
}
static void F_312 ( struct V_25 * V_25 )
{
struct V_383 * V_384 = F_285 ( V_25 -> V_33 ) ;
T_3 V_428 = V_25 -> V_394 - V_429 ;
if ( V_428 <= 0 )
return;
F_287 ( & V_384 -> V_192 ) ;
if ( V_384 -> V_385 != V_386 &&
V_25 -> V_387 == V_384 -> V_387 ) {
V_384 -> V_227 += V_428 ;
if ( V_384 -> V_227 > F_281 () &&
! F_299 ( & V_384 -> V_409 ) )
F_309 ( V_384 ) ;
}
F_289 ( & V_384 -> V_192 ) ;
V_25 -> V_394 -= V_428 ;
}
static T_10 void F_263 ( struct V_25 * V_25 )
{
if ( ! F_274 () )
return;
if ( ! V_25 -> V_396 || V_25 -> V_72 )
return;
F_312 ( V_25 ) ;
}
static void F_313 ( struct V_383 * V_384 )
{
T_2 V_227 = 0 , V_73 = F_281 () ;
T_2 V_393 ;
F_287 ( & V_384 -> V_192 ) ;
if ( F_306 ( V_384 , V_425 ) ) {
F_289 ( & V_384 -> V_192 ) ;
return;
}
if ( V_384 -> V_385 != V_386 && V_384 -> V_227 > V_73 )
V_227 = V_384 -> V_227 ;
V_393 = V_384 -> V_387 ;
F_289 ( & V_384 -> V_192 ) ;
if ( ! V_227 )
return;
V_227 = F_303 ( V_384 , V_227 , V_393 ) ;
F_287 ( & V_384 -> V_192 ) ;
if ( V_393 == V_384 -> V_387 )
V_384 -> V_227 -= F_141 ( V_227 , V_384 -> V_227 ) ;
F_289 ( & V_384 -> V_192 ) ;
}
static void F_257 ( struct V_25 * V_25 )
{
if ( ! F_274 () )
return;
if ( F_13 ( ! V_25 -> V_430 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_25 * V_431 ;
struct V_311 * V_33 ;
V_25 -> V_430 = 1 ;
for ( V_33 = V_25 -> V_33 -> V_34 ; V_33 ; V_33 = V_33 -> V_34 ) {
V_431 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( V_431 -> V_430 )
break;
}
if ( V_33 ) {
V_25 -> V_388 = V_431 -> V_388 ;
V_25 -> V_389 = F_64 ( V_24 ) ;
}
}
if ( ! V_25 -> V_396 || V_25 -> V_45 )
return;
if ( F_292 ( V_25 ) )
return;
F_71 ( V_25 , 0 ) ;
if ( V_25 -> V_394 <= 0 )
F_296 ( V_25 ) ;
}
static bool F_270 ( struct V_25 * V_25 )
{
if ( ! F_274 () )
return false ;
if ( F_11 ( ! V_25 -> V_396 || V_25 -> V_394 > 0 ) )
return false ;
if ( F_292 ( V_25 ) )
return true ;
F_296 ( V_25 ) ;
return true ;
}
static enum V_432 F_314 ( struct V_420 * V_433 )
{
struct V_383 * V_384 =
F_21 ( V_433 , struct V_383 , V_426 ) ;
F_313 ( V_384 ) ;
return V_434 ;
}
static enum V_432 F_315 ( struct V_420 * V_433 )
{
struct V_383 * V_384 =
F_21 ( V_433 , struct V_383 , V_422 ) ;
int V_415 ;
int V_395 = 0 ;
F_287 ( & V_384 -> V_192 ) ;
for (; ; ) {
V_415 = F_316 ( V_433 , V_384 -> V_226 ) ;
if ( ! V_415 )
break;
V_395 = F_305 ( V_384 , V_415 ) ;
}
if ( V_395 )
V_384 -> V_435 = 0 ;
F_289 ( & V_384 -> V_192 ) ;
return V_395 ? V_434 : V_436 ;
}
void F_317 ( struct V_383 * V_384 )
{
F_318 ( & V_384 -> V_192 ) ;
V_384 -> V_227 = 0 ;
V_384 -> V_385 = V_386 ;
V_384 -> V_226 = F_311 ( F_280 () ) ;
F_319 ( & V_384 -> V_409 ) ;
F_320 ( & V_384 -> V_422 , V_437 , V_438 ) ;
V_384 -> V_422 . V_439 = F_315 ;
F_320 ( & V_384 -> V_426 , V_437 , V_427 ) ;
V_384 -> V_426 . V_439 = F_314 ;
}
static void F_321 ( struct V_25 * V_25 )
{
V_25 -> V_396 = 0 ;
F_319 ( & V_25 -> V_410 ) ;
}
void F_288 ( struct V_383 * V_384 )
{
F_322 ( & V_384 -> V_192 ) ;
if ( ! V_384 -> V_435 ) {
V_384 -> V_435 = 1 ;
F_316 ( & V_384 -> V_422 , V_384 -> V_226 ) ;
F_323 ( & V_384 -> V_422 , V_438 ) ;
}
}
static void F_324 ( struct V_383 * V_384 )
{
if ( ! V_384 -> V_409 . V_58 )
return;
F_325 ( & V_384 -> V_422 ) ;
F_325 ( & V_384 -> V_426 ) ;
}
static void T_11 F_326 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_327 (rq, cfs_rq) {
struct V_383 * V_384 = & V_25 -> V_33 -> V_383 ;
F_287 ( & V_384 -> V_192 ) ;
V_25 -> V_396 = V_384 -> V_385 != V_386 ;
F_289 ( & V_384 -> V_192 ) ;
}
}
static void T_11 F_328 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_327 (rq, cfs_rq) {
if ( ! V_25 -> V_396 )
continue;
V_25 -> V_394 = 1 ;
V_25 -> V_396 = 0 ;
if ( F_292 ( V_25 ) )
F_300 ( V_25 ) ;
}
}
static inline T_2 F_226 ( struct V_25 * V_25 )
{
return F_64 ( F_16 ( V_25 ) ) ;
}
static void F_71 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_270 ( struct V_25 * V_25 ) { return false ; }
static void F_257 ( struct V_25 * V_25 ) {}
static T_10 void F_263 ( struct V_25 * V_25 ) {}
static inline int F_292 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_206 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_293 ( struct V_311 * V_33 ,
int V_187 , int V_398 )
{
return 0 ;
}
void F_317 ( struct V_383 * V_384 ) {}
static void F_321 ( struct V_25 * V_25 ) {}
static inline struct V_383 * F_285 ( struct V_311 * V_33 )
{
return NULL ;
}
static inline void F_324 ( struct V_383 * V_384 ) {}
static inline void F_326 ( struct V_24 * V_24 ) {}
static inline void F_328 ( struct V_24 * V_24 ) {}
static void F_329 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_330 ( F_34 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_73 = F_58 ( V_25 , V_28 ) ;
T_2 V_440 = V_28 -> V_91 - V_28 -> V_374 ;
T_3 V_42 = V_73 - V_440 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_265 ( V_24 ) ;
return;
}
F_331 ( V_24 , V_42 ) ;
}
}
static void F_332 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_333 ( V_24 ) || V_45 -> V_441 != & V_442 )
return;
if ( F_23 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_329 ( V_24 , V_45 ) ;
}
static inline void
F_329 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_332 ( struct V_24 * V_24 )
{
}
static void
F_334 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_98 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_59 (se) {
if ( V_28 -> V_74 )
break;
V_25 = F_23 ( V_28 ) ;
F_256 ( V_25 , V_28 , V_98 ) ;
if ( F_292 ( V_25 ) )
break;
V_25 -> V_406 ++ ;
V_98 = V_370 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_406 ++ ;
if ( F_292 ( V_25 ) )
break;
F_225 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_302 ( V_24 , 1 ) ;
F_332 ( V_24 ) ;
}
static void F_335 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_98 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_443 = V_98 & V_99 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_262 ( V_25 , V_28 , V_98 ) ;
if ( F_292 ( V_25 ) )
break;
V_25 -> V_406 -- ;
if ( V_25 -> V_70 . V_4 ) {
V_28 = F_32 ( V_28 ) ;
if ( V_443 && V_28 && ! F_206 ( V_25 ) )
F_336 ( V_28 ) ;
break;
}
V_98 |= V_99 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_406 -- ;
if ( F_292 ( V_25 ) )
break;
F_225 ( V_28 , 1 ) ;
F_205 ( V_25 ) ;
}
if ( ! V_28 )
F_298 ( V_24 , 1 ) ;
F_332 ( V_24 ) ;
}
static unsigned long
F_337 ( unsigned long V_70 , unsigned long V_444 , int V_445 )
{
int V_446 = 0 ;
if ( ! V_444 )
return V_70 ;
if ( V_444 >= V_447 [ V_445 ] )
return 0 ;
if ( V_445 == 1 )
return V_70 >> V_444 ;
while ( V_444 ) {
if ( V_444 % 2 )
V_70 = ( V_70 * V_448 [ V_445 ] [ V_446 ] ) >> V_449 ;
V_444 >>= 1 ;
V_446 ++ ;
}
return V_70 ;
}
static void F_338 ( struct V_24 * V_450 , unsigned long V_451 ,
unsigned long V_452 )
{
unsigned long T_11 V_453 = V_450 -> V_454 [ 0 ] ;
int V_258 , V_455 ;
V_450 -> V_456 ++ ;
V_450 -> V_454 [ 0 ] = V_451 ;
for ( V_258 = 1 , V_455 = 2 ; V_258 < V_457 ; V_258 ++ , V_455 += V_455 ) {
unsigned long V_458 , V_459 ;
V_458 = V_450 -> V_454 [ V_258 ] ;
#ifdef F_339
V_458 = F_337 ( V_458 , V_452 - 1 , V_258 ) ;
if ( V_453 ) {
V_458 -= F_337 ( V_453 , V_452 - 1 , V_258 ) ;
V_458 += V_453 ;
}
#endif
V_459 = V_451 ;
if ( V_459 > V_458 )
V_459 += V_455 - 1 ;
V_450 -> V_454 [ V_258 ] = ( V_458 * ( V_455 - 1 ) + V_459 ) >> V_258 ;
}
F_340 ( V_450 ) ;
}
static unsigned long F_112 ( const int V_162 )
{
return F_233 ( & F_111 ( V_162 ) -> V_40 ) ;
}
static void F_341 ( struct V_24 * V_450 ,
unsigned long V_460 ,
unsigned long V_70 )
{
unsigned long V_452 ;
V_452 = V_460 - V_450 -> V_461 ;
if ( V_452 ) {
V_450 -> V_461 = V_460 ;
F_338 ( V_450 , V_70 , V_452 ) ;
}
}
static void F_342 ( struct V_24 * V_450 )
{
if ( F_112 ( F_26 ( V_450 ) ) )
return;
F_341 ( V_450 , F_85 ( V_211 ) , 0 ) ;
}
void F_343 ( void )
{
struct V_24 * V_450 = V_450 () ;
V_450 -> V_454 [ 0 ] = F_112 ( F_26 ( V_450 ) ) ;
}
void F_344 ( void )
{
unsigned long V_460 = F_85 ( V_211 ) ;
struct V_24 * V_450 = V_450 () ;
unsigned long V_70 ;
if ( V_460 == V_450 -> V_461 )
return;
V_70 = F_112 ( F_26 ( V_450 ) ) ;
F_287 ( & V_450 -> V_192 ) ;
F_301 ( V_450 ) ;
F_341 ( V_450 , V_460 , V_70 ) ;
F_289 ( & V_450 -> V_192 ) ;
}
static inline void F_341 ( struct V_24 * V_450 ,
unsigned long V_460 ,
unsigned long V_70 ) { }
static void F_345 ( struct V_24 * V_450 , unsigned long V_70 )
{
#ifdef F_339
V_450 -> V_461 = F_85 ( V_211 ) ;
#endif
F_338 ( V_450 , V_70 , 1 ) ;
}
void F_346 ( struct V_24 * V_450 )
{
unsigned long V_70 = F_112 ( F_26 ( V_450 ) ) ;
if ( F_347 () )
F_341 ( V_450 , F_85 ( V_211 ) , V_70 ) ;
else
F_345 ( V_450 , V_70 ) ;
}
static unsigned long F_348 ( int V_162 , int type )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
unsigned long V_462 = F_112 ( V_162 ) ;
if ( type == 0 || ! F_217 ( V_463 ) )
return V_462 ;
return F_141 ( V_24 -> V_454 [ type - 1 ] , V_462 ) ;
}
static unsigned long F_349 ( int V_162 , int type )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
unsigned long V_462 = F_112 ( V_162 ) ;
if ( type == 0 || ! F_217 ( V_463 ) )
return V_462 ;
return F_66 ( V_24 -> V_454 [ type - 1 ] , V_462 ) ;
}
static unsigned long F_113 ( int V_162 )
{
return F_111 ( V_162 ) -> V_464 ;
}
static unsigned long F_350 ( int V_162 )
{
return F_111 ( V_162 ) -> V_344 ;
}
static unsigned long F_351 ( int V_162 )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
unsigned long V_72 = F_85 ( V_24 -> V_40 . V_406 ) ;
unsigned long V_80 = F_112 ( V_162 ) ;
if ( V_72 )
return V_80 / V_72 ;
return 0 ;
}
static long F_352 ( struct V_311 * V_33 , int V_162 , long V_465 , long V_466 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_162 ] ;
if ( ! V_33 -> V_34 )
return V_465 ;
F_59 (se) {
struct V_25 * V_25 = V_28 -> V_31 ;
long V_467 , V_7 = F_234 ( V_25 ) ;
V_33 = V_25 -> V_33 ;
V_467 = V_466 + F_203 ( & V_33 -> V_80 ) ;
V_467 -= V_25 -> V_314 ;
V_467 += V_7 ;
V_7 += V_465 ;
if ( V_467 > 0 && V_7 < V_467 )
V_465 = ( V_7 * ( long ) V_33 -> V_313 ) / V_467 ;
else
V_465 = V_33 -> V_313 ;
if ( V_465 < V_315 )
V_465 = V_315 ;
V_465 -= V_28 -> V_77 . V_80 ;
V_466 = 0 ;
}
return V_465 ;
}
static long F_352 ( struct V_311 * V_33 , int V_162 , long V_465 , long V_466 )
{
return V_465 ;
}
static void F_353 ( struct V_26 * V_29 )
{
if ( F_179 ( V_211 , V_157 -> V_468 + V_209 ) ) {
V_157 -> V_469 >>= 1 ;
V_157 -> V_468 = V_211 ;
}
if ( V_157 -> V_470 != V_29 ) {
V_157 -> V_470 = V_29 ;
V_157 -> V_469 ++ ;
}
}
static int F_354 ( struct V_26 * V_29 )
{
unsigned int V_471 = V_157 -> V_469 ;
unsigned int V_472 = V_29 -> V_469 ;
int V_9 = F_355 ( V_473 ) ;
if ( V_471 < V_472 )
F_118 ( V_471 , V_472 ) ;
if ( V_472 < V_9 || V_471 < V_472 * V_9 )
return 0 ;
return 1 ;
}
static int F_356 ( struct V_199 * V_200 , struct V_26 * V_29 , int V_474 )
{
T_3 V_451 , V_70 ;
T_3 V_475 , V_476 ;
int V_445 , V_477 , V_478 ;
struct V_311 * V_33 ;
unsigned long V_4 ;
int V_479 ;
V_445 = V_200 -> V_480 ;
V_477 = F_220 () ;
V_478 = F_133 ( V_29 ) ;
V_70 = F_348 ( V_478 , V_445 ) ;
V_451 = F_349 ( V_477 , V_445 ) ;
if ( V_474 ) {
V_33 = V_311 ( V_157 ) ;
V_4 = V_157 -> V_28 . V_77 . V_80 ;
V_451 += F_352 ( V_33 , V_477 , - V_4 , - V_4 ) ;
V_70 += F_352 ( V_33 , V_478 , 0 , - V_4 ) ;
}
V_33 = V_311 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_475 = 100 ;
V_475 *= F_113 ( V_478 ) ;
V_476 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
V_476 *= F_113 ( V_477 ) ;
if ( V_451 > 0 ) {
V_475 *= V_451 +
F_352 ( V_33 , V_477 , V_4 , V_4 ) ;
V_476 *= V_70 + F_352 ( V_33 , V_478 , 0 , V_4 ) ;
}
V_479 = V_475 <= V_476 ;
F_246 ( V_29 , V_28 . V_89 . V_481 ) ;
if ( ! V_479 )
return 0 ;
F_246 ( V_200 , V_482 ) ;
F_246 ( V_29 , V_28 . V_89 . V_483 ) ;
return 1 ;
}
static struct V_484 *
F_357 ( struct V_199 * V_200 , struct V_26 * V_29 ,
int V_477 , int V_485 )
{
struct V_484 * V_486 = NULL , * V_133 = V_200 -> V_487 ;
unsigned long V_488 = V_489 , V_451 = 0 ;
int V_490 = V_200 -> V_491 ;
int V_492 = 100 + ( V_200 -> V_183 - 100 ) / 2 ;
if ( V_485 & V_493 )
V_490 = V_200 -> V_480 ;
do {
unsigned long V_70 , V_494 ;
int V_495 ;
int V_258 ;
if ( ! F_358 ( F_359 ( V_133 ) ,
F_126 ( V_29 ) ) )
continue;
V_495 = F_125 ( V_477 ,
F_359 ( V_133 ) ) ;
V_494 = 0 ;
F_110 (i, sched_group_cpus(group)) {
if ( V_495 )
V_70 = F_348 ( V_258 , V_490 ) ;
else
V_70 = F_349 ( V_258 , V_490 ) ;
V_494 += V_70 ;
}
V_494 = ( V_494 * V_86 ) / V_133 -> V_496 -> V_163 ;
if ( V_495 ) {
V_451 = V_494 ;
} else if ( V_494 < V_488 ) {
V_488 = V_494 ;
V_486 = V_133 ;
}
} while ( V_133 = V_133 -> V_58 , V_133 != V_200 -> V_487 );
if ( ! V_486 || 100 * V_451 < V_492 * V_488 )
return NULL ;
return V_486 ;
}
static int
F_360 ( struct V_484 * V_133 , struct V_26 * V_29 , int V_477 )
{
unsigned long V_70 , V_488 = V_489 ;
unsigned int V_497 = V_498 ;
T_2 V_499 = 0 ;
int V_500 = V_477 ;
int V_501 = - 1 ;
int V_258 ;
F_361 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_362 ( V_258 ) ) {
struct V_24 * V_24 = F_111 ( V_258 ) ;
struct V_502 * V_395 = F_363 ( V_24 ) ;
if ( V_395 && V_395 -> V_503 < V_497 ) {
V_497 = V_395 -> V_503 ;
V_499 = V_24 -> V_504 ;
V_501 = V_258 ;
} else if ( ( ! V_395 || V_395 -> V_503 == V_497 ) &&
V_24 -> V_504 > V_499 ) {
V_499 = V_24 -> V_504 ;
V_501 = V_258 ;
}
} else if ( V_501 == - 1 ) {
V_70 = F_112 ( V_258 ) ;
if ( V_70 < V_488 || ( V_70 == V_488 && V_258 == V_477 ) ) {
V_488 = V_70 ;
V_500 = V_258 ;
}
}
}
return V_501 != - 1 ? V_501 : V_500 ;
}
static int F_128 ( struct V_26 * V_29 , int V_505 )
{
struct V_199 * V_200 ;
struct V_484 * V_506 ;
int V_258 = F_133 ( V_29 ) ;
if ( F_362 ( V_505 ) )
return V_505 ;
if ( V_258 != V_505 && F_364 ( V_258 , V_505 ) && F_362 ( V_258 ) )
return V_258 ;
V_200 = F_134 ( F_135 ( V_507 , V_505 ) ) ;
F_365 (sd) {
V_506 = V_200 -> V_487 ;
do {
if ( ! F_358 ( F_359 ( V_506 ) ,
F_126 ( V_29 ) ) )
goto V_58;
F_110 (i, sched_group_cpus(sg)) {
if ( V_258 == V_505 || ! F_362 ( V_258 ) )
goto V_58;
}
V_505 = F_366 ( F_359 ( V_506 ) ,
F_126 ( V_29 ) ) ;
goto V_508;
V_58:
V_506 = V_506 -> V_58 ;
} while ( V_506 != V_200 -> V_487 );
}
V_508:
return V_505 ;
}
static int F_367 ( int V_162 )
{
unsigned long V_509 = F_111 ( V_162 ) -> V_40 . V_77 . V_83 ;
unsigned long V_163 = F_350 ( V_162 ) ;
return ( V_509 >= V_163 ) ? V_163 : V_509 ;
}
static int
F_368 ( struct V_26 * V_29 , int V_478 , int V_485 , int V_510 )
{
struct V_199 * V_511 , * V_512 = NULL , * V_200 = NULL ;
int V_162 = F_220 () ;
int V_513 = V_478 ;
int V_514 = 0 ;
int V_474 = V_510 & V_515 ;
if ( V_485 & V_493 ) {
F_353 ( V_29 ) ;
V_514 = ! F_354 ( V_29 ) && F_125 ( V_162 , F_126 ( V_29 ) ) ;
}
F_120 () ;
F_369 (cpu, tmp) {
if ( ! ( V_511 -> V_98 & V_516 ) )
break;
if ( V_514 && ( V_511 -> V_98 & V_517 ) &&
F_125 ( V_478 , F_370 ( V_511 ) ) ) {
V_512 = V_511 ;
break;
}
if ( V_511 -> V_98 & V_485 )
V_200 = V_511 ;
else if ( ! V_514 )
break;
}
if ( V_512 ) {
V_200 = NULL ;
if ( V_162 != V_478 && F_356 ( V_512 , V_29 , V_474 ) )
V_513 = V_162 ;
}
if ( ! V_200 ) {
if ( V_485 & V_493 )
V_513 = F_128 ( V_29 , V_513 ) ;
} else while ( V_200 ) {
struct V_484 * V_133 ;
int V_4 ;
if ( ! ( V_200 -> V_98 & V_485 ) ) {
V_200 = V_200 -> V_518 ;
continue;
}
V_133 = F_357 ( V_200 , V_29 , V_162 , V_485 ) ;
if ( ! V_133 ) {
V_200 = V_200 -> V_518 ;
continue;
}
V_513 = F_360 ( V_133 , V_29 , V_162 ) ;
if ( V_513 == - 1 || V_513 == V_162 ) {
V_200 = V_200 -> V_518 ;
continue;
}
V_162 = V_513 ;
V_4 = V_200 -> V_519 ;
V_200 = NULL ;
F_369 (cpu, tmp) {
if ( V_4 <= V_511 -> V_519 )
break;
if ( V_511 -> V_98 & V_485 )
V_200 = V_511 ;
}
}
F_129 () ;
return V_513 ;
}
static void F_371 ( struct V_26 * V_29 )
{
if ( V_29 -> V_101 == V_520 ) {
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
}
F_232 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_88 = 0 ;
}
static void F_372 ( struct V_26 * V_29 )
{
F_232 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_373 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_521 = V_522 ;
return F_56 ( V_521 , V_28 ) ;
}
static int
F_268 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_521 , V_523 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_523 <= 0 )
return - 1 ;
V_521 = F_373 ( V_45 , V_28 ) ;
if ( V_523 > V_521 )
return 1 ;
return 0 ;
}
static void F_374 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_524 == V_525 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_336 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_524 == V_525 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_375 ( struct V_27 * V_28 )
{
F_59 (se)
F_23 ( V_28 ) -> V_372 = V_28 ;
}
static void F_376 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_510 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_455 = V_25 -> V_72 >= V_67 ;
int V_526 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_206 ( F_23 ( V_36 ) ) ) )
return;
if ( F_217 ( V_527 ) && V_455 && ! ( V_510 & V_528 ) ) {
F_336 ( V_36 ) ;
V_526 = 1 ;
}
if ( F_377 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_524 == V_525 ) &&
F_11 ( V_29 -> V_524 != V_525 ) )
goto V_529;
if ( F_13 ( V_29 -> V_524 != V_530 ) || ! F_217 ( V_531 ) )
return;
F_33 ( & V_28 , & V_36 ) ;
F_63 ( F_23 ( V_28 ) ) ;
F_168 ( ! V_36 ) ;
if ( F_268 ( V_28 , V_36 ) == 1 ) {
if ( ! V_526 )
F_336 ( V_36 ) ;
goto V_529;
}
return;
V_529:
F_265 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_74 || V_45 == V_24 -> V_395 ) )
return;
if ( F_217 ( V_532 ) && V_455 && F_20 ( V_28 ) )
F_374 ( V_28 ) ;
}
static struct V_26 *
F_378 ( struct V_24 * V_24 , struct V_26 * V_337 , struct V_533 V_534 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_535 ;
V_536:
#ifdef F_379
if ( ! V_25 -> V_72 )
goto V_395;
if ( V_337 -> V_441 != & V_442 )
goto V_537;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_74 )
F_63 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_270 ( V_25 ) ) )
goto V_537;
}
V_28 = F_267 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_337 != V_29 ) {
struct V_27 * V_36 = & V_337 -> V_28 ;
while ( ! ( V_25 = F_31 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_269 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_32 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_266 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_32 ( V_28 ) ;
}
}
F_269 ( V_25 , V_36 ) ;
F_266 ( V_25 , V_28 ) ;
}
if ( F_333 ( V_24 ) )
F_329 ( V_24 , V_29 ) ;
return V_29 ;
V_537:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_395;
F_380 ( V_24 , V_337 ) ;
do {
V_28 = F_267 ( V_25 , NULL ) ;
F_266 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_333 ( V_24 ) )
F_329 ( V_24 , V_29 ) ;
return V_29 ;
V_395:
F_381 ( & V_24 -> V_192 , V_534 ) ;
V_535 = F_236 ( V_24 ) ;
F_382 ( & V_24 -> V_192 , V_534 ) ;
if ( V_535 < 0 )
return V_538 ;
if ( V_535 > 0 )
goto V_536;
return NULL ;
}
static void F_383 ( struct V_24 * V_24 , struct V_26 * V_337 )
{
struct V_27 * V_28 = & V_337 -> V_28 ;
struct V_25 * V_25 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_269 ( V_25 , V_28 ) ;
}
}
static void F_384 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_261 ( V_25 , V_28 ) ;
if ( V_45 -> V_524 != V_539 ) {
F_301 ( V_24 ) ;
F_63 ( V_25 ) ;
F_385 ( V_24 , true ) ;
}
F_375 ( V_28 ) ;
}
static bool F_386 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_529 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_74 || F_206 ( F_23 ( V_28 ) ) )
return false ;
F_336 ( V_28 ) ;
F_384 ( V_24 ) ;
return true ;
}
static int F_387 ( struct V_26 * V_29 , struct V_540 * V_168 )
{
T_3 V_42 ;
F_322 ( & V_168 -> V_186 -> V_192 ) ;
if ( V_29 -> V_441 != & V_442 )
return 0 ;
if ( F_13 ( V_29 -> V_524 == V_525 ) )
return 0 ;
if ( F_217 ( V_541 ) && V_168 -> V_188 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_542 == - 1 )
return 1 ;
if ( V_542 == 0 )
return 0 ;
V_42 = F_64 ( V_168 -> V_186 ) - V_29 -> V_28 . V_88 ;
return V_42 < ( T_3 ) V_542 ;
}
static int F_388 ( struct V_26 * V_29 , struct V_540 * V_168 )
{
struct V_122 * V_122 = F_134 ( V_29 -> V_122 ) ;
unsigned long V_543 , V_544 ;
int V_152 , V_154 ;
if ( ! F_178 ( & V_272 ) )
return - 1 ;
if ( ! V_29 -> V_130 || ! ( V_168 -> V_200 -> V_98 & V_545 ) )
return - 1 ;
V_152 = F_103 ( V_168 -> V_187 ) ;
V_154 = F_103 ( V_168 -> V_153 ) ;
if ( V_152 == V_154 )
return - 1 ;
if ( V_152 == V_29 -> V_120 ) {
if ( V_168 -> V_186 -> V_72 > V_168 -> V_186 -> V_121 )
return 1 ;
else
return - 1 ;
}
if ( V_154 == V_29 -> V_120 )
return 0 ;
if ( V_122 ) {
V_543 = F_94 ( V_29 , V_152 ) ;
V_544 = F_94 ( V_29 , V_154 ) ;
} else {
V_543 = F_93 ( V_29 , V_152 ) ;
V_544 = F_93 ( V_29 , V_154 ) ;
}
return V_544 < V_543 ;
}
static inline int F_388 ( struct V_26 * V_29 ,
struct V_540 * V_168 )
{
return - 1 ;
}
static
int F_389 ( struct V_26 * V_29 , struct V_540 * V_168 )
{
int V_546 ;
F_322 ( & V_168 -> V_186 -> V_192 ) ;
if ( F_293 ( V_311 ( V_29 ) , V_168 -> V_187 , V_168 -> V_153 ) )
return 0 ;
if ( ! F_125 ( V_168 -> V_153 , F_126 ( V_29 ) ) ) {
int V_162 ;
F_246 ( V_29 , V_28 . V_89 . V_547 ) ;
V_168 -> V_98 |= V_548 ;
if ( ! V_168 -> V_549 || ( V_168 -> V_98 & V_550 ) )
return 0 ;
F_361 (cpu, env->dst_grpmask, env->cpus) {
if ( F_125 ( V_162 , F_126 ( V_29 ) ) ) {
V_168 -> V_98 |= V_550 ;
V_168 -> V_551 = V_162 ;
break;
}
}
return 0 ;
}
V_168 -> V_98 &= ~ V_552 ;
if ( F_390 ( V_168 -> V_186 , V_29 ) ) {
F_246 ( V_29 , V_28 . V_89 . V_553 ) ;
return 0 ;
}
V_546 = F_388 ( V_29 , V_168 ) ;
if ( V_546 == - 1 )
V_546 = F_387 ( V_29 , V_168 ) ;
if ( V_546 <= 0 ||
V_168 -> V_200 -> V_554 > V_168 -> V_200 -> V_555 ) {
if ( V_546 == 1 ) {
F_246 ( V_168 -> V_200 , V_556 [ V_168 -> V_395 ] ) ;
F_246 ( V_29 , V_28 . V_89 . V_557 ) ;
}
return 1 ;
}
F_246 ( V_29 , V_28 . V_89 . V_558 ) ;
return 0 ;
}
static void F_391 ( struct V_26 * V_29 , struct V_540 * V_168 )
{
F_322 ( & V_168 -> V_186 -> V_192 ) ;
V_29 -> V_74 = V_559 ;
F_392 ( V_168 -> V_186 , V_29 , 0 ) ;
F_393 ( V_29 , V_168 -> V_153 ) ;
}
static struct V_26 * F_394 ( struct V_540 * V_168 )
{
struct V_26 * V_29 , * V_317 ;
F_322 ( & V_168 -> V_186 -> V_192 ) ;
F_395 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_389 ( V_29 , V_168 ) )
continue;
F_391 ( V_29 , V_168 ) ;
F_246 ( V_168 -> V_200 , V_560 [ V_168 -> V_395 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_396 ( struct V_540 * V_168 )
{
struct V_561 * V_562 = & V_168 -> V_186 -> V_310 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_563 = 0 ;
F_322 ( & V_168 -> V_186 -> V_192 ) ;
if ( V_168 -> V_492 <= 0 )
return 0 ;
while ( ! F_299 ( V_562 ) ) {
if ( V_168 -> V_395 != V_564 && V_168 -> V_186 -> V_72 <= 1 )
break;
V_29 = F_397 ( V_562 , struct V_26 , V_28 . V_309 ) ;
V_168 -> V_565 ++ ;
if ( V_168 -> V_565 > V_168 -> V_566 )
break;
if ( V_168 -> V_565 > V_168 -> V_567 ) {
V_168 -> V_567 += V_568 ;
V_168 -> V_98 |= V_569 ;
break;
}
if ( ! F_389 ( V_29 , V_168 ) )
goto V_58;
V_70 = F_127 ( V_29 ) ;
if ( F_217 ( V_570 ) && V_70 < 16 && ! V_168 -> V_200 -> V_554 )
goto V_58;
if ( ( V_70 / 2 ) > V_168 -> V_492 )
goto V_58;
F_391 ( V_29 , V_168 ) ;
F_199 ( & V_29 -> V_28 . V_309 , & V_168 -> V_562 ) ;
V_563 ++ ;
V_168 -> V_492 -= V_70 ;
#ifdef F_398
if ( V_168 -> V_395 == V_571 )
break;
#endif
if ( V_168 -> V_492 <= 0 )
break;
continue;
V_58:
F_399 ( & V_29 -> V_28 . V_309 , V_562 ) ;
}
F_67 ( V_168 -> V_200 , V_560 [ V_168 -> V_395 ] , V_563 ) ;
return V_563 ;
}
static void F_400 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_322 ( & V_24 -> V_192 ) ;
F_168 ( F_34 ( V_29 ) != V_24 ) ;
F_401 ( V_24 , V_29 , 0 ) ;
V_29 -> V_74 = V_572 ;
F_402 ( V_24 , V_29 , 0 ) ;
}
static void F_403 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_287 ( & V_24 -> V_192 ) ;
F_400 ( V_24 , V_29 ) ;
F_289 ( & V_24 -> V_192 ) ;
}
static void F_404 ( struct V_540 * V_168 )
{
struct V_561 * V_562 = & V_168 -> V_562 ;
struct V_26 * V_29 ;
F_287 ( & V_168 -> V_188 -> V_192 ) ;
while ( ! F_299 ( V_562 ) ) {
V_29 = F_397 ( V_562 , struct V_26 , V_28 . V_309 ) ;
F_201 ( & V_29 -> V_28 . V_309 ) ;
F_400 ( V_168 -> V_188 , V_29 ) ;
}
F_289 ( & V_168 -> V_188 -> V_192 ) ;
}
static void F_405 ( int V_162 )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
struct V_25 * V_25 ;
unsigned long V_98 ;
F_406 ( & V_24 -> V_192 , V_98 ) ;
F_301 ( V_24 ) ;
F_327 (rq, cfs_rq) {
if ( F_206 ( V_25 ) )
continue;
if ( F_222 ( F_226 ( V_25 ) , V_25 , true ) )
F_214 ( V_25 , 0 ) ;
}
F_407 ( & V_24 -> V_192 , V_98 ) ;
}
static void F_408 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_87 = V_211 ;
unsigned long V_70 ;
if ( V_25 -> V_573 == V_87 )
return;
V_25 -> V_574 = NULL ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_574 = V_28 ;
if ( V_25 -> V_573 == V_87 )
break;
}
if ( ! V_28 ) {
V_25 -> V_575 = F_234 ( V_25 ) ;
V_25 -> V_573 = V_87 ;
}
while ( ( V_28 = V_25 -> V_574 ) != NULL ) {
V_70 = V_25 -> V_575 ;
V_70 = F_409 ( V_70 * V_28 -> V_77 . V_80 ,
F_234 ( V_25 ) + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_575 = V_70 ;
V_25 -> V_573 = V_87 ;
}
}
static unsigned long F_127 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_408 ( V_25 ) ;
return F_409 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_575 ,
F_234 ( V_25 ) + 1 ) ;
}
static inline void F_405 ( int V_162 )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_98 ;
F_406 ( & V_24 -> V_192 , V_98 ) ;
F_301 ( V_24 ) ;
F_222 ( F_226 ( V_25 ) , V_25 , true ) ;
F_407 ( & V_24 -> V_192 , V_98 ) ;
}
static unsigned long F_127 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_410 ( struct V_576 * V_577 )
{
* V_577 = (struct V_576 ) {
. V_578 = NULL ,
. V_220 = NULL ,
. V_579 = 0UL ,
. V_580 = 0UL ,
. V_581 = {
. V_494 = 0UL ,
. V_582 = 0 ,
. V_583 = V_584 ,
} ,
} ;
}
static inline int F_411 ( struct V_199 * V_200 ,
enum V_585 V_395 )
{
int V_490 ;
switch ( V_395 ) {
case V_564 :
V_490 = V_200 -> V_586 ;
break;
case V_571 :
V_490 = V_200 -> V_587 ;
break;
default:
V_490 = V_200 -> V_588 ;
break;
}
return V_490 ;
}
static unsigned long F_412 ( int V_162 )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
T_2 V_462 , V_589 , V_590 , V_77 ;
T_3 V_42 ;
V_590 = F_85 ( V_24 -> V_590 ) ;
V_77 = F_85 ( V_24 -> V_591 ) ;
V_42 = F_413 ( V_24 ) - V_590 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_462 = F_414 () + V_42 ;
V_589 = F_213 ( V_77 , V_462 ) ;
if ( F_11 ( V_589 < V_86 ) )
return V_86 - V_589 ;
return 1 ;
}
static void F_415 ( struct V_199 * V_200 , int V_162 )
{
unsigned long V_163 = F_211 ( V_200 , V_162 ) ;
struct V_484 * V_592 = V_200 -> V_487 ;
F_111 ( V_162 ) -> V_344 = V_163 ;
V_163 *= F_412 ( V_162 ) ;
V_163 >>= V_593 ;
if ( ! V_163 )
V_163 = 1 ;
F_111 ( V_162 ) -> V_464 = V_163 ;
V_592 -> V_496 -> V_163 = V_163 ;
}
void F_416 ( struct V_199 * V_200 , int V_162 )
{
struct V_199 * V_518 = V_200 -> V_518 ;
struct V_484 * V_133 , * V_592 = V_200 -> V_487 ;
unsigned long V_163 ;
unsigned long V_208 ;
V_208 = F_142 ( V_200 -> V_594 ) ;
V_208 = F_145 ( V_208 , 1UL , V_595 ) ;
V_592 -> V_496 -> V_596 = V_211 + V_208 ;
if ( ! V_518 ) {
F_415 ( V_200 , V_162 ) ;
return;
}
V_163 = 0 ;
if ( V_518 -> V_98 & V_597 ) {
F_110 (cpu, sched_group_cpus(sdg)) {
struct V_598 * V_496 ;
struct V_24 * V_24 = F_111 ( V_162 ) ;
if ( F_13 ( ! V_24 -> V_200 ) ) {
V_163 += F_113 ( V_162 ) ;
continue;
}
V_496 = V_24 -> V_200 -> V_487 -> V_496 ;
V_163 += V_496 -> V_163 ;
}
} else {
V_133 = V_518 -> V_487 ;
do {
V_163 += V_133 -> V_496 -> V_163 ;
V_133 = V_133 -> V_58 ;
} while ( V_133 != V_518 -> V_487 );
}
V_592 -> V_496 -> V_163 = V_163 ;
}
static inline int
F_417 ( struct V_24 * V_24 , struct V_199 * V_200 )
{
return ( ( V_24 -> V_464 * V_200 -> V_183 ) <
( V_24 -> V_344 * 100 ) ) ;
}
static inline int F_418 ( struct V_484 * V_133 )
{
return V_133 -> V_496 -> V_492 ;
}
static inline bool
F_419 ( struct V_540 * V_168 , struct V_599 * V_600 )
{
if ( V_600 -> V_582 < V_600 -> F_101 )
return true ;
if ( ( V_600 -> V_601 * 100 ) >
( V_600 -> V_602 * V_168 -> V_200 -> V_183 ) )
return true ;
return false ;
}
static inline bool
F_420 ( struct V_540 * V_168 , struct V_599 * V_600 )
{
if ( V_600 -> V_582 <= V_600 -> F_101 )
return false ;
if ( ( V_600 -> V_601 * 100 ) <
( V_600 -> V_602 * V_168 -> V_200 -> V_183 ) )
return true ;
return false ;
}
static inline enum
V_583 F_421 ( struct V_484 * V_133 ,
struct V_599 * V_600 )
{
if ( V_600 -> V_603 )
return V_604 ;
if ( F_418 ( V_133 ) )
return V_605 ;
return V_584 ;
}
static inline void F_422 ( struct V_540 * V_168 ,
struct V_484 * V_133 , int V_490 ,
int V_495 , struct V_599 * V_600 ,
bool * V_606 )
{
unsigned long V_70 ;
int V_258 , V_72 ;
memset ( V_600 , 0 , sizeof( * V_600 ) ) ;
F_361 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_111 ( V_258 ) ;
if ( V_495 )
V_70 = F_349 ( V_258 , V_490 ) ;
else
V_70 = F_348 ( V_258 , V_490 ) ;
V_600 -> V_607 += V_70 ;
V_600 -> V_602 += F_367 ( V_258 ) ;
V_600 -> V_582 += V_24 -> V_40 . V_406 ;
V_72 = V_24 -> V_72 ;
if ( V_72 > 1 )
* V_606 = true ;
#ifdef F_423
V_600 -> V_119 += V_24 -> V_119 ;
V_600 -> V_121 += V_24 -> V_121 ;
#endif
V_600 -> V_608 += F_112 ( V_258 ) ;
if ( ! V_72 && F_362 ( V_258 ) )
V_600 -> V_609 ++ ;
}
V_600 -> V_601 = V_133 -> V_496 -> V_163 ;
V_600 -> V_494 = ( V_600 -> V_607 * V_86 ) / V_600 -> V_601 ;
if ( V_600 -> V_582 )
V_600 -> V_610 = V_600 -> V_608 / V_600 -> V_582 ;
V_600 -> F_101 = V_133 -> F_101 ;
V_600 -> V_603 = F_420 ( V_168 , V_600 ) ;
V_600 -> V_583 = F_421 ( V_133 , V_600 ) ;
}
static bool F_424 ( struct V_540 * V_168 ,
struct V_576 * V_577 ,
struct V_484 * V_506 ,
struct V_599 * V_600 )
{
struct V_599 * V_578 = & V_577 -> V_581 ;
if ( V_600 -> V_583 > V_578 -> V_583 )
return true ;
if ( V_600 -> V_583 < V_578 -> V_583 )
return false ;
if ( V_600 -> V_494 <= V_578 -> V_494 )
return false ;
if ( ! ( V_168 -> V_200 -> V_98 & V_611 ) )
return true ;
if ( V_168 -> V_395 == V_564 )
return true ;
if ( V_600 -> V_582 && V_168 -> V_153 < F_425 ( V_506 ) ) {
if ( ! V_577 -> V_578 )
return true ;
if ( F_425 ( V_577 -> V_578 ) < F_425 ( V_506 ) )
return true ;
}
return false ;
}
static inline enum V_612 F_426 ( struct V_599 * V_600 )
{
if ( V_600 -> V_582 > V_600 -> V_119 )
return V_613 ;
if ( V_600 -> V_582 > V_600 -> V_121 )
return V_218 ;
return V_614 ;
}
static inline enum V_612 F_427 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_119 )
return V_613 ;
if ( V_24 -> V_72 > V_24 -> V_121 )
return V_218 ;
return V_614 ;
}
static inline enum V_612 F_426 ( struct V_599 * V_600 )
{
return V_614 ;
}
static inline enum V_612 F_427 ( struct V_24 * V_24 )
{
return V_613 ;
}
static inline void F_428 ( struct V_540 * V_168 , struct V_576 * V_577 )
{
struct V_199 * V_518 = V_168 -> V_200 -> V_518 ;
struct V_484 * V_506 = V_168 -> V_200 -> V_487 ;
struct V_599 V_615 ;
int V_490 , V_616 = 0 ;
bool V_606 = false ;
if ( V_518 && V_518 -> V_98 & V_617 )
V_616 = 1 ;
V_490 = F_411 ( V_168 -> V_200 , V_168 -> V_395 ) ;
do {
struct V_599 * V_600 = & V_615 ;
int V_495 ;
V_495 = F_125 ( V_168 -> V_153 , F_359 ( V_506 ) ) ;
if ( V_495 ) {
V_577 -> V_220 = V_506 ;
V_600 = & V_577 -> V_618 ;
if ( V_168 -> V_395 != V_571 ||
F_429 ( V_211 , V_506 -> V_496 -> V_596 ) )
F_416 ( V_168 -> V_200 , V_168 -> V_153 ) ;
}
F_422 ( V_168 , V_506 , V_490 , V_495 , V_600 ,
& V_606 ) ;
if ( V_495 )
goto V_619;
if ( V_616 && V_577 -> V_220 &&
F_419 ( V_168 , & V_577 -> V_618 ) &&
( V_600 -> V_582 > 1 ) ) {
V_600 -> V_603 = 1 ;
V_600 -> V_583 = F_421 ( V_506 , V_600 ) ;
}
if ( F_424 ( V_168 , V_577 , V_506 , V_600 ) ) {
V_577 -> V_578 = V_506 ;
V_577 -> V_581 = * V_600 ;
}
V_619:
V_577 -> V_579 += V_600 -> V_607 ;
V_577 -> V_580 += V_600 -> V_601 ;
V_506 = V_506 -> V_58 ;
} while ( V_506 != V_168 -> V_200 -> V_487 );
if ( V_168 -> V_200 -> V_98 & V_545 )
V_168 -> V_612 = F_426 ( & V_577 -> V_581 ) ;
if ( ! V_168 -> V_200 -> V_34 ) {
if ( V_168 -> V_188 -> V_620 -> V_606 != V_606 )
V_168 -> V_188 -> V_620 -> V_606 = V_606 ;
}
}
static int F_430 ( struct V_540 * V_168 , struct V_576 * V_577 )
{
int V_621 ;
if ( ! ( V_168 -> V_200 -> V_98 & V_611 ) )
return 0 ;
if ( V_168 -> V_395 == V_564 )
return 0 ;
if ( ! V_577 -> V_578 )
return 0 ;
V_621 = F_425 ( V_577 -> V_578 ) ;
if ( V_168 -> V_153 > V_621 )
return 0 ;
V_168 -> V_492 = F_114 (
V_577 -> V_581 . V_494 * V_577 -> V_581 . V_601 ,
V_86 ) ;
return 1 ;
}
static inline
void F_431 ( struct V_540 * V_168 , struct V_576 * V_577 )
{
unsigned long V_511 , V_622 = 0 , V_623 = 0 ;
unsigned int V_624 = 2 ;
unsigned long V_625 ;
struct V_599 * V_220 , * V_578 ;
V_220 = & V_577 -> V_618 ;
V_578 = & V_577 -> V_581 ;
if ( ! V_220 -> V_582 )
V_220 -> V_610 = F_351 ( V_168 -> V_153 ) ;
else if ( V_578 -> V_610 > V_220 -> V_610 )
V_624 = 1 ;
V_625 =
( V_578 -> V_610 * V_86 ) /
V_578 -> V_601 ;
if ( V_578 -> V_494 + V_625 >=
V_220 -> V_494 + ( V_625 * V_624 ) ) {
V_168 -> V_492 = V_578 -> V_610 ;
return;
}
V_622 += V_578 -> V_601 *
F_141 ( V_578 -> V_610 , V_578 -> V_494 ) ;
V_622 += V_220 -> V_601 *
F_141 ( V_220 -> V_610 , V_220 -> V_494 ) ;
V_622 /= V_86 ;
if ( V_578 -> V_494 > V_625 ) {
V_623 += V_578 -> V_601 *
F_141 ( V_578 -> V_610 ,
V_578 -> V_494 - V_625 ) ;
}
if ( V_578 -> V_494 * V_578 -> V_601 <
V_578 -> V_610 * V_86 ) {
V_511 = ( V_578 -> V_494 * V_578 -> V_601 ) /
V_220 -> V_601 ;
} else {
V_511 = ( V_578 -> V_610 * V_86 ) /
V_220 -> V_601 ;
}
V_623 += V_220 -> V_601 *
F_141 ( V_220 -> V_610 , V_220 -> V_494 + V_511 ) ;
V_623 /= V_86 ;
if ( V_623 > V_622 )
V_168 -> V_492 = V_578 -> V_610 ;
}
static inline void F_432 ( struct V_540 * V_168 , struct V_576 * V_577 )
{
unsigned long V_626 , V_627 = ~ 0UL ;
struct V_599 * V_220 , * V_578 ;
V_220 = & V_577 -> V_618 ;
V_578 = & V_577 -> V_581 ;
if ( V_578 -> V_583 == V_605 ) {
V_578 -> V_610 =
F_141 ( V_578 -> V_610 , V_577 -> V_494 ) ;
}
if ( V_578 -> V_494 <= V_577 -> V_494 ||
V_220 -> V_494 >= V_577 -> V_494 ) {
V_168 -> V_492 = 0 ;
return F_431 ( V_168 , V_577 ) ;
}
if ( V_578 -> V_583 == V_604 &&
V_220 -> V_583 == V_604 ) {
V_627 = V_578 -> V_582 * V_86 ;
if ( V_627 > V_578 -> V_601 ) {
V_627 -= V_578 -> V_601 ;
V_627 *= V_71 ;
V_627 /= V_578 -> V_601 ;
} else
V_627 = ~ 0UL ;
}
V_626 = F_141 ( V_578 -> V_494 - V_577 -> V_494 , V_627 ) ;
V_168 -> V_492 = F_141 (
V_626 * V_578 -> V_601 ,
( V_577 -> V_494 - V_220 -> V_494 ) * V_220 -> V_601
) / V_86 ;
if ( V_168 -> V_492 < V_578 -> V_610 )
return F_431 ( V_168 , V_577 ) ;
}
static struct V_484 * F_433 ( struct V_540 * V_168 )
{
struct V_599 * V_220 , * V_578 ;
struct V_576 V_577 ;
F_410 ( & V_577 ) ;
F_428 ( V_168 , & V_577 ) ;
V_220 = & V_577 . V_618 ;
V_578 = & V_577 . V_581 ;
if ( F_430 ( V_168 , & V_577 ) )
return V_577 . V_578 ;
if ( ! V_577 . V_578 || V_578 -> V_582 == 0 )
goto V_628;
V_577 . V_494 = ( V_86 * V_577 . V_579 )
/ V_577 . V_580 ;
if ( V_578 -> V_583 == V_605 )
goto V_629;
if ( V_168 -> V_395 == V_571 && F_419 ( V_168 , V_220 ) &&
V_578 -> V_603 )
goto V_629;
if ( V_220 -> V_494 >= V_578 -> V_494 )
goto V_628;
if ( V_220 -> V_494 >= V_577 . V_494 )
goto V_628;
if ( V_168 -> V_395 == V_630 ) {
if ( ( V_578 -> V_583 != V_604 ) &&
( V_220 -> V_609 <= ( V_578 -> V_609 + 1 ) ) )
goto V_628;
} else {
if ( 100 * V_578 -> V_494 <=
V_168 -> V_200 -> V_183 * V_220 -> V_494 )
goto V_628;
}
V_629:
F_432 ( V_168 , & V_577 ) ;
return V_577 . V_578 ;
V_628:
V_168 -> V_492 = 0 ;
return NULL ;
}
static struct V_24 * F_434 ( struct V_540 * V_168 ,
struct V_484 * V_133 )
{
struct V_24 * V_578 = NULL , * V_24 ;
unsigned long V_631 = 0 , V_632 = 1 ;
int V_258 ;
F_361 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_163 , V_465 ;
enum V_612 V_633 ;
V_24 = F_111 ( V_258 ) ;
V_633 = F_427 ( V_24 ) ;
if ( V_633 > V_168 -> V_612 )
continue;
V_163 = F_113 ( V_258 ) ;
V_465 = F_112 ( V_258 ) ;
if ( V_24 -> V_72 == 1 && V_465 > V_168 -> V_492 &&
! F_417 ( V_24 , V_168 -> V_200 ) )
continue;
if ( V_465 * V_632 > V_631 * V_163 ) {
V_631 = V_465 ;
V_632 = V_163 ;
V_578 = V_24 ;
}
}
return V_578 ;
}
static int F_435 ( struct V_540 * V_168 )
{
struct V_199 * V_200 = V_168 -> V_200 ;
if ( V_168 -> V_395 == V_571 ) {
if ( ( V_200 -> V_98 & V_611 ) && V_168 -> V_187 > V_168 -> V_153 )
return 1 ;
}
if ( ( V_168 -> V_395 != V_564 ) &&
( V_168 -> V_186 -> V_40 . V_406 == 1 ) ) {
if ( ( F_417 ( V_168 -> V_186 , V_200 ) ) &&
( F_113 ( V_168 -> V_187 ) * V_200 -> V_183 < F_113 ( V_168 -> V_153 ) * 100 ) )
return 1 ;
}
return F_13 ( V_200 -> V_554 > V_200 -> V_555 + 2 ) ;
}
static int F_436 ( struct V_540 * V_168 )
{
struct V_484 * V_506 = V_168 -> V_200 -> V_487 ;
struct V_634 * V_635 , * V_636 ;
int V_162 , V_637 = - 1 ;
if ( V_168 -> V_395 == V_571 )
return 1 ;
V_635 = F_359 ( V_506 ) ;
V_636 = F_437 ( V_506 ) ;
F_361 (cpu, sg_cpus, env->cpus) {
if ( ! F_125 ( V_162 , V_636 ) || ! F_362 ( V_162 ) )
continue;
V_637 = V_162 ;
break;
}
if ( V_637 == - 1 )
V_637 = F_438 ( V_506 ) ;
return V_637 == V_168 -> V_153 ;
}
static int F_439 ( int V_477 , struct V_24 * V_450 ,
struct V_199 * V_200 , enum V_585 V_395 ,
int * V_638 )
{
int V_639 , V_640 , V_641 = 0 ;
struct V_199 * V_642 = V_200 -> V_34 ;
struct V_484 * V_133 ;
struct V_24 * V_578 ;
unsigned long V_98 ;
struct V_634 * V_8 = F_440 ( V_643 ) ;
struct V_540 V_168 = {
. V_200 = V_200 ,
. V_153 = V_477 ,
. V_188 = V_450 ,
. V_549 = F_359 ( V_200 -> V_487 ) ,
. V_395 = V_395 ,
. V_567 = V_568 ,
. V_8 = V_8 ,
. V_612 = V_614 ,
. V_562 = F_441 ( V_168 . V_562 ) ,
} ;
if ( V_395 == V_571 )
V_168 . V_549 = NULL ;
F_442 ( V_8 , V_644 ) ;
F_246 ( V_200 , V_645 [ V_395 ] ) ;
V_646:
if ( ! F_436 ( & V_168 ) ) {
* V_638 = 0 ;
goto V_628;
}
V_133 = F_433 ( & V_168 ) ;
if ( ! V_133 ) {
F_246 ( V_200 , V_647 [ V_395 ] ) ;
goto V_628;
}
V_578 = F_434 ( & V_168 , V_133 ) ;
if ( ! V_578 ) {
F_246 ( V_200 , V_648 [ V_395 ] ) ;
goto V_628;
}
F_168 ( V_578 == V_168 . V_188 ) ;
F_67 ( V_200 , V_649 [ V_395 ] , V_168 . V_492 ) ;
V_168 . V_187 = V_578 -> V_162 ;
V_168 . V_186 = V_578 ;
V_639 = 0 ;
if ( V_578 -> V_72 > 1 ) {
V_168 . V_98 |= V_552 ;
V_168 . V_566 = F_141 ( V_650 , V_578 -> V_72 ) ;
V_651:
F_406 ( & V_578 -> V_192 , V_98 ) ;
V_640 = F_396 ( & V_168 ) ;
F_289 ( & V_578 -> V_192 ) ;
if ( V_640 ) {
F_404 ( & V_168 ) ;
V_639 += V_640 ;
}
F_443 ( V_98 ) ;
if ( V_168 . V_98 & V_569 ) {
V_168 . V_98 &= ~ V_569 ;
goto V_651;
}
if ( ( V_168 . V_98 & V_550 ) && V_168 . V_492 > 0 ) {
F_444 ( V_168 . V_153 , V_168 . V_8 ) ;
V_168 . V_188 = F_111 ( V_168 . V_551 ) ;
V_168 . V_153 = V_168 . V_551 ;
V_168 . V_98 &= ~ V_550 ;
V_168 . V_565 = 0 ;
V_168 . V_567 = V_568 ;
goto V_651;
}
if ( V_642 ) {
int * V_652 = & V_642 -> V_487 -> V_496 -> V_492 ;
if ( ( V_168 . V_98 & V_548 ) && V_168 . V_492 > 0 )
* V_652 = 1 ;
}
if ( F_13 ( V_168 . V_98 & V_552 ) ) {
F_444 ( F_26 ( V_578 ) , V_8 ) ;
if ( ! F_445 ( V_8 ) ) {
V_168 . V_565 = 0 ;
V_168 . V_567 = V_568 ;
goto V_646;
}
goto V_653;
}
}
if ( ! V_639 ) {
F_246 ( V_200 , V_654 [ V_395 ] ) ;
if ( V_395 != V_571 )
V_200 -> V_554 ++ ;
if ( F_435 ( & V_168 ) ) {
F_406 ( & V_578 -> V_192 , V_98 ) ;
if ( ! F_125 ( V_477 ,
F_126 ( V_578 -> V_45 ) ) ) {
F_407 ( & V_578 -> V_192 ,
V_98 ) ;
V_168 . V_98 |= V_552 ;
goto V_655;
}
if ( ! V_578 -> V_641 ) {
V_578 -> V_641 = 1 ;
V_578 -> V_656 = V_477 ;
V_641 = 1 ;
}
F_407 ( & V_578 -> V_192 , V_98 ) ;
if ( V_641 ) {
F_446 ( F_26 ( V_578 ) ,
V_657 , V_578 ,
& V_578 -> V_658 ) ;
}
V_200 -> V_554 = V_200 -> V_555 + 1 ;
}
} else
V_200 -> V_554 = 0 ;
if ( F_11 ( ! V_641 ) ) {
V_200 -> V_594 = V_200 -> V_659 ;
} else {
if ( V_200 -> V_594 < V_200 -> V_660 )
V_200 -> V_594 *= 2 ;
}
goto V_307;
V_628:
if ( V_642 ) {
int * V_652 = & V_642 -> V_487 -> V_496 -> V_492 ;
if ( * V_652 )
* V_652 = 0 ;
}
V_653:
F_246 ( V_200 , V_661 [ V_395 ] ) ;
V_200 -> V_554 = 0 ;
V_655:
if ( ( ( V_168 . V_98 & V_552 ) &&
V_200 -> V_594 < V_662 ) ||
( V_200 -> V_594 < V_200 -> V_660 ) )
V_200 -> V_594 *= 2 ;
V_639 = 0 ;
V_307:
return V_639 ;
}
static inline unsigned long
F_447 ( struct V_199 * V_200 , int V_663 )
{
unsigned long V_208 = V_200 -> V_594 ;
if ( V_663 )
V_208 *= V_200 -> V_664 ;
V_208 = F_142 ( V_208 ) ;
V_208 = F_145 ( V_208 , 1UL , V_595 ) ;
return V_208 ;
}
static inline void
F_448 ( struct V_199 * V_200 , int V_663 , unsigned long * V_665 )
{
unsigned long V_208 , V_58 ;
V_208 = F_447 ( V_200 , V_663 ) ;
V_58 = V_200 -> V_666 + V_208 ;
if ( F_179 ( * V_665 , V_58 ) )
* V_665 = V_58 ;
}
static int F_236 ( struct V_24 * V_450 )
{
unsigned long V_665 = V_211 + V_209 ;
int V_477 = V_450 -> V_162 ;
struct V_199 * V_200 ;
int V_667 = 0 ;
T_2 V_668 = 0 ;
V_450 -> V_504 = F_74 ( V_450 ) ;
if ( V_450 -> V_669 < V_542 ||
! V_450 -> V_620 -> V_606 ) {
F_120 () ;
V_200 = F_449 ( V_450 -> V_200 ) ;
if ( V_200 )
F_448 ( V_200 , 0 , & V_665 ) ;
F_129 () ;
goto V_307;
}
F_289 ( & V_450 -> V_192 ) ;
F_405 ( V_477 ) ;
F_120 () ;
F_369 (this_cpu, sd) {
int V_638 = 1 ;
T_2 V_670 , V_671 ;
if ( ! ( V_200 -> V_98 & V_516 ) )
continue;
if ( V_450 -> V_669 < V_668 + V_200 -> V_672 ) {
F_448 ( V_200 , 0 , & V_665 ) ;
break;
}
if ( V_200 -> V_98 & V_673 ) {
V_670 = F_283 ( V_477 ) ;
V_667 = F_439 ( V_477 , V_450 ,
V_200 , V_571 ,
& V_638 ) ;
V_671 = F_283 ( V_477 ) - V_670 ;
if ( V_671 > V_200 -> V_672 )
V_200 -> V_672 = V_671 ;
V_668 += V_671 ;
}
F_448 ( V_200 , 0 , & V_665 ) ;
if ( V_667 || V_450 -> V_72 > 0 )
break;
}
F_129 () ;
F_287 ( & V_450 -> V_192 ) ;
if ( V_668 > V_450 -> V_674 )
V_450 -> V_674 = V_668 ;
if ( V_450 -> V_40 . V_406 && ! V_667 )
V_667 = 1 ;
V_307:
if ( F_179 ( V_450 -> V_665 , V_665 ) )
V_450 -> V_665 = V_665 ;
if ( V_450 -> V_72 != V_450 -> V_40 . V_406 )
V_667 = - 1 ;
if ( V_667 )
V_450 -> V_504 = 0 ;
return V_667 ;
}
static int V_657 ( void * V_401 )
{
struct V_24 * V_675 = V_401 ;
int V_621 = F_26 ( V_675 ) ;
int V_676 = V_675 -> V_656 ;
struct V_24 * V_677 = F_111 ( V_676 ) ;
struct V_199 * V_200 ;
struct V_26 * V_29 = NULL ;
F_121 ( & V_675 -> V_192 ) ;
if ( F_13 ( V_621 != F_220 () ||
! V_675 -> V_641 ) )
goto V_678;
if ( V_675 -> V_72 <= 1 )
goto V_678;
F_168 ( V_675 == V_677 ) ;
F_120 () ;
F_369 (target_cpu, sd) {
if ( ( V_200 -> V_98 & V_516 ) &&
F_125 ( V_621 , F_370 ( V_200 ) ) )
break;
}
if ( F_11 ( V_200 ) ) {
struct V_540 V_168 = {
. V_200 = V_200 ,
. V_153 = V_676 ,
. V_188 = V_677 ,
. V_187 = V_675 -> V_162 ,
. V_186 = V_675 ,
. V_395 = V_630 ,
} ;
F_246 ( V_200 , V_679 ) ;
V_29 = F_394 ( & V_168 ) ;
if ( V_29 ) {
F_246 ( V_200 , V_680 ) ;
V_200 -> V_554 = 0 ;
} else {
F_246 ( V_200 , V_681 ) ;
}
}
F_129 () ;
V_678:
V_675 -> V_641 = 0 ;
F_289 ( & V_675 -> V_192 ) ;
if ( V_29 )
F_403 ( V_677 , V_29 ) ;
F_450 () ;
return 0 ;
}
static inline int F_451 ( struct V_24 * V_24 )
{
return F_13 ( ! F_452 ( V_24 -> V_200 ) ) ;
}
static inline int F_453 ( void )
{
int V_682 = F_454 ( V_683 . V_684 ) ;
if ( V_682 < V_685 && F_362 ( V_682 ) )
return V_682 ;
return V_685 ;
}
static void F_455 ( void )
{
int V_686 ;
V_683 . V_665 ++ ;
V_686 = F_453 () ;
if ( V_686 >= V_685 )
return;
if ( F_456 ( V_687 , F_457 ( V_686 ) ) )
return;
F_458 ( V_686 ) ;
return;
}
void F_459 ( unsigned int V_162 )
{
if ( F_13 ( F_460 ( V_688 , F_457 ( V_162 ) ) ) ) {
if ( F_11 ( F_125 ( V_162 , V_683 . V_684 ) ) ) {
F_444 ( V_162 , V_683 . V_684 ) ;
F_461 ( & V_683 . V_689 ) ;
}
F_462 ( V_688 , F_457 ( V_162 ) ) ;
}
}
static inline void F_463 ( void )
{
struct V_199 * V_200 ;
int V_162 = F_220 () ;
F_120 () ;
V_200 = F_134 ( F_135 ( V_690 , V_162 ) ) ;
if ( ! V_200 || ! V_200 -> V_691 )
goto V_194;
V_200 -> V_691 = 0 ;
F_464 ( & V_200 -> V_487 -> V_496 -> V_692 ) ;
V_194:
F_129 () ;
}
void F_465 ( void )
{
struct V_199 * V_200 ;
int V_162 = F_220 () ;
F_120 () ;
V_200 = F_134 ( F_135 ( V_690 , V_162 ) ) ;
if ( ! V_200 || V_200 -> V_691 )
goto V_194;
V_200 -> V_691 = 1 ;
F_461 ( & V_200 -> V_487 -> V_496 -> V_692 ) ;
V_194:
F_129 () ;
}
void F_466 ( int V_162 )
{
if ( ! F_467 ( V_162 ) )
return;
if ( F_460 ( V_688 , F_457 ( V_162 ) ) )
return;
if ( F_451 ( F_111 ( V_162 ) ) )
return;
F_468 ( V_162 , V_683 . V_684 ) ;
F_464 ( & V_683 . V_689 ) ;
F_469 ( V_688 , F_457 ( V_162 ) ) ;
}
void F_470 ( void )
{
V_595 = V_209 * F_471 () / 10 ;
}
static void F_472 ( struct V_24 * V_24 , enum V_585 V_395 )
{
int V_638 = 1 ;
int V_162 = V_24 -> V_162 ;
unsigned long V_208 ;
struct V_199 * V_200 ;
unsigned long V_665 = V_211 + 60 * V_209 ;
int F_448 = 0 ;
int V_693 , V_694 = 0 ;
T_2 V_695 = 0 ;
F_405 ( V_162 ) ;
F_120 () ;
F_369 (cpu, sd) {
if ( F_179 ( V_211 , V_200 -> V_696 ) ) {
V_200 -> V_672 =
( V_200 -> V_672 * 253 ) / 256 ;
V_200 -> V_696 = V_211 + V_209 ;
V_694 = 1 ;
}
V_695 += V_200 -> V_672 ;
if ( ! ( V_200 -> V_98 & V_516 ) )
continue;
if ( ! V_638 ) {
if ( V_694 )
continue;
break;
}
V_208 = F_447 ( V_200 , V_395 != V_630 ) ;
V_693 = V_200 -> V_98 & V_697 ;
if ( V_693 ) {
if ( ! F_473 ( & V_698 ) )
goto V_307;
}
if ( F_429 ( V_211 , V_200 -> V_666 + V_208 ) ) {
if ( F_439 ( V_162 , V_24 , V_200 , V_395 , & V_638 ) ) {
V_395 = F_362 ( V_162 ) ? V_630 : V_564 ;
}
V_200 -> V_666 = V_211 ;
V_208 = F_447 ( V_200 , V_395 != V_630 ) ;
}
if ( V_693 )
F_171 ( & V_698 ) ;
V_307:
if ( F_179 ( V_665 , V_200 -> V_666 + V_208 ) ) {
V_665 = V_200 -> V_666 + V_208 ;
F_448 = 1 ;
}
}
if ( V_694 ) {
V_24 -> V_674 =
F_66 ( ( T_2 ) V_542 , V_695 ) ;
}
F_129 () ;
if ( F_11 ( F_448 ) ) {
V_24 -> V_665 = V_665 ;
#ifdef F_339
if ( ( V_395 == V_630 ) && F_179 ( V_683 . V_665 , V_24 -> V_665 ) )
V_683 . V_665 = V_24 -> V_665 ;
#endif
}
}
static void F_474 ( struct V_24 * V_450 , enum V_585 V_395 )
{
int V_477 = V_450 -> V_162 ;
struct V_24 * V_24 ;
int V_637 ;
unsigned long V_665 = V_211 + 60 * V_209 ;
int F_448 = 0 ;
if ( V_395 != V_630 ||
! F_460 ( V_687 , F_457 ( V_477 ) ) )
goto V_287;
F_110 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_637 == V_477 || ! F_362 ( V_637 ) )
continue;
if ( F_475 () )
break;
V_24 = F_111 ( V_637 ) ;
if ( F_429 ( V_211 , V_24 -> V_665 ) ) {
F_121 ( & V_24 -> V_192 ) ;
F_301 ( V_24 ) ;
F_342 ( V_24 ) ;
F_124 ( & V_24 -> V_192 ) ;
F_472 ( V_24 , V_630 ) ;
}
if ( F_179 ( V_665 , V_24 -> V_665 ) ) {
V_665 = V_24 -> V_665 ;
F_448 = 1 ;
}
}
if ( F_11 ( F_448 ) )
V_683 . V_665 = V_665 ;
V_287:
F_462 ( V_687 , F_457 ( V_477 ) ) ;
}
static inline bool F_476 ( struct V_24 * V_24 )
{
unsigned long V_87 = V_211 ;
struct V_199 * V_200 ;
struct V_598 * V_496 ;
int V_699 , V_162 = V_24 -> V_162 ;
bool V_700 = false ;
if ( F_13 ( V_24 -> F_236 ) )
return false ;
F_463 () ;
F_459 ( V_162 ) ;
if ( F_11 ( ! F_477 ( & V_683 . V_689 ) ) )
return false ;
if ( F_183 ( V_87 , V_683 . V_665 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_120 () ;
V_200 = F_134 ( F_135 ( V_690 , V_162 ) ) ;
if ( V_200 ) {
V_496 = V_200 -> V_487 -> V_496 ;
V_699 = F_477 ( & V_496 -> V_692 ) ;
if ( V_699 > 1 ) {
V_700 = true ;
goto V_194;
}
}
V_200 = F_134 ( V_24 -> V_200 ) ;
if ( V_200 ) {
if ( ( V_24 -> V_40 . V_406 >= 1 ) &&
F_417 ( V_24 , V_200 ) ) {
V_700 = true ;
goto V_194;
}
}
V_200 = F_134 ( F_135 ( V_701 , V_162 ) ) ;
if ( V_200 && ( F_366 ( V_683 . V_684 ,
F_370 ( V_200 ) ) < V_162 ) ) {
V_700 = true ;
goto V_194;
}
V_194:
F_129 () ;
return V_700 ;
}
static void F_474 ( struct V_24 * V_450 , enum V_585 V_395 ) { }
static void F_478 ( struct V_702 * V_703 )
{
struct V_24 * V_450 = V_450 () ;
enum V_585 V_395 = V_450 -> F_236 ?
V_630 : V_564 ;
F_474 ( V_450 , V_395 ) ;
F_472 ( V_450 , V_395 ) ;
}
void F_479 ( struct V_24 * V_24 )
{
if ( F_13 ( F_451 ( V_24 ) ) )
return;
if ( F_429 ( V_211 , V_24 -> V_665 ) )
F_480 ( V_704 ) ;
#ifdef F_339
if ( F_476 ( V_24 ) )
F_455 () ;
#endif
}
static void F_481 ( struct V_24 * V_24 )
{
F_7 () ;
F_326 ( V_24 ) ;
}
static void F_482 ( struct V_24 * V_24 )
{
F_7 () ;
F_328 ( V_24 ) ;
}
static void F_483 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_377 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_271 ( V_25 , V_28 , V_377 ) ;
}
if ( F_484 ( & V_272 ) )
F_194 ( V_24 , V_45 ) ;
}
static void F_485 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_477 = F_220 () ;
struct V_24 * V_24 = V_450 () ;
unsigned long V_98 ;
F_406 ( & V_24 -> V_192 , V_98 ) ;
F_301 ( V_24 ) ;
V_25 = F_22 ( V_157 ) ;
V_45 = V_25 -> V_45 ;
F_120 () ;
F_486 ( V_29 , V_477 ) ;
F_129 () ;
F_63 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_247 ( V_25 , V_28 , 1 ) ;
if ( V_705 && V_45 && F_37 ( V_45 , V_28 ) ) {
F_118 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_265 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_36 ;
F_407 ( & V_24 -> V_192 , V_98 ) ;
}
static void
F_487 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_706 )
{
if ( ! F_488 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_707 > V_706 )
F_265 ( V_24 ) ;
} else
F_402 ( V_24 , V_29 , 0 ) ;
}
static inline bool F_489 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_74 )
return true ;
if ( ! V_28 -> V_91 || V_29 -> V_101 == V_520 )
return true ;
return false ;
}
static void F_490 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( ! F_489 ( V_29 ) ) {
F_247 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_36 ;
}
F_228 ( V_25 , V_28 ) ;
}
static void F_491 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
#ifdef F_379
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
F_227 ( V_25 , V_28 ) ;
if ( ! F_489 ( V_29 ) )
V_28 -> V_41 += V_25 -> F_36 ;
}
static void F_492 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_490 ( V_29 ) ;
}
static void F_493 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_491 ( V_29 ) ;
if ( F_488 ( V_29 ) ) {
if ( V_24 -> V_45 == V_29 )
F_265 ( V_24 ) ;
else
F_402 ( V_24 , V_29 , 0 ) ;
}
}
static void F_494 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_266 ( V_25 , V_28 ) ;
F_71 ( V_25 , 0 ) ;
}
}
void F_495 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_708 ;
V_25 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_25 -> V_48 = V_25 -> F_36 ;
#endif
#ifdef F_198
F_496 ( & V_25 -> V_348 , 0 ) ;
F_496 ( & V_25 -> V_350 , 0 ) ;
#endif
}
static void F_497 ( struct V_26 * V_29 )
{
F_490 ( V_29 ) ;
F_498 ( V_29 , F_133 ( V_29 ) ) ;
#ifdef F_198
V_29 -> V_28 . V_77 . V_78 = 0 ;
#endif
F_491 ( V_29 ) ;
}
void F_499 ( struct V_311 * V_33 )
{
int V_258 ;
F_324 ( F_285 ( V_33 ) ) ;
F_500 (i) {
if ( V_33 -> V_25 )
F_176 ( V_33 -> V_25 [ V_258 ] ) ;
if ( V_33 -> V_28 )
F_176 ( V_33 -> V_28 [ V_258 ] ) ;
}
F_176 ( V_33 -> V_25 ) ;
F_176 ( V_33 -> V_28 ) ;
}
int F_501 ( struct V_311 * V_33 , struct V_311 * V_34 )
{
struct V_27 * V_28 ;
struct V_25 * V_25 ;
struct V_24 * V_24 ;
int V_258 ;
V_33 -> V_25 = F_164 ( sizeof( V_25 ) * V_685 , V_260 ) ;
if ( ! V_33 -> V_25 )
goto V_709;
V_33 -> V_28 = F_164 ( sizeof( V_28 ) * V_685 , V_260 ) ;
if ( ! V_33 -> V_28 )
goto V_709;
V_33 -> V_313 = V_71 ;
F_317 ( F_285 ( V_33 ) ) ;
F_500 (i) {
V_24 = F_111 ( V_258 ) ;
V_25 = F_502 ( sizeof( struct V_25 ) ,
V_260 , F_103 ( V_258 ) ) ;
if ( ! V_25 )
goto V_709;
V_28 = F_502 ( sizeof( struct V_27 ) ,
V_260 , F_103 ( V_258 ) ) ;
if ( ! V_28 )
goto V_710;
F_495 ( V_25 ) ;
F_503 ( V_33 , V_25 , V_28 , V_258 , V_34 -> V_28 [ V_258 ] ) ;
F_61 ( V_28 ) ;
F_121 ( & V_24 -> V_192 ) ;
F_62 ( V_28 ) ;
F_124 ( & V_24 -> V_192 ) ;
}
return 1 ;
V_710:
F_176 ( V_25 ) ;
V_709:
return 0 ;
}
void F_504 ( struct V_311 * V_33 )
{
unsigned long V_98 ;
struct V_24 * V_24 ;
int V_162 ;
F_500 (cpu) {
if ( V_33 -> V_28 [ V_162 ] )
F_232 ( V_33 -> V_28 [ V_162 ] ) ;
if ( ! V_33 -> V_25 [ V_162 ] -> V_32 )
continue;
V_24 = F_111 ( V_162 ) ;
F_406 ( & V_24 -> V_192 , V_98 ) ;
F_29 ( V_33 -> V_25 [ V_162 ] ) ;
F_407 ( & V_24 -> V_192 , V_98 ) ;
}
}
void F_503 ( struct V_311 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_162 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_111 ( V_162 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_321 ( V_25 ) ;
V_33 -> V_25 [ V_162 ] = V_25 ;
V_33 -> V_28 [ V_162 ] = V_28 ;
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
int F_505 ( struct V_311 * V_33 , unsigned long V_313 )
{
int V_258 ;
unsigned long V_98 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_204 ;
V_313 = F_145 ( V_313 , F_506 ( V_315 ) , F_506 ( V_711 ) ) ;
F_507 ( & V_712 ) ;
if ( V_33 -> V_313 == V_313 )
goto V_508;
V_33 -> V_313 = V_313 ;
F_500 (i) {
struct V_24 * V_24 = F_111 ( V_258 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_258 ] ;
F_406 ( & V_24 -> V_192 , V_98 ) ;
F_301 ( V_24 ) ;
F_59 (se)
F_205 ( F_24 ( V_28 ) ) ;
F_407 ( & V_24 -> V_192 , V_98 ) ;
}
V_508:
F_508 ( & V_712 ) ;
return 0 ;
}
void F_499 ( struct V_311 * V_33 ) { }
int F_501 ( struct V_311 * V_33 , struct V_311 * V_34 )
{
return 1 ;
}
void F_504 ( struct V_311 * V_33 ) { }
static unsigned int F_509 ( struct V_24 * V_24 , struct V_26 * V_139 )
{
struct V_27 * V_28 = & V_139 -> V_28 ;
unsigned int V_713 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_713 = F_510 ( F_58 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_713 ;
}
void F_511 ( struct V_714 * V_715 , int V_162 )
{
struct V_25 * V_25 ;
F_120 () ;
F_327 (cpu_rq(cpu), cfs_rq)
F_512 ( V_715 , V_162 , V_25 ) ;
F_129 () ;
}
void F_513 ( struct V_26 * V_29 , struct V_714 * V_715 )
{
int V_141 ;
unsigned long V_716 = 0 , V_717 = 0 , V_718 = 0 , V_719 = 0 ;
F_98 (node) {
if ( V_29 -> V_130 ) {
V_716 = V_29 -> V_130 [ F_92 ( V_131 , V_141 , 0 ) ] ;
V_717 = V_29 -> V_130 [ F_92 ( V_131 , V_141 , 1 ) ] ;
}
if ( V_29 -> V_122 ) {
V_718 = V_29 -> V_122 -> V_132 [ F_92 ( V_131 , V_141 , 0 ) ] ,
V_719 = V_29 -> V_122 -> V_132 [ F_92 ( V_131 , V_141 , 1 ) ] ;
}
F_514 ( V_715 , V_141 , V_716 , V_717 , V_718 , V_719 ) ;
}
}
T_12 void F_515 ( void )
{
#ifdef F_198
F_516 ( V_704 , F_478 ) ;
#ifdef F_339
V_683 . V_665 = V_211 ;
F_517 ( & V_683 . V_684 , V_720 ) ;
#endif
#endif
}
