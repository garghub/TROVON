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
T_2 V_87 = F_63 ( V_25 ) ;
int V_88 ;
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
if ( F_20 ( V_28 ) ) {
struct V_26 * V_29 = F_17 ( V_28 ) ;
if ( V_29 -> V_89 != & V_90 ) {
V_28 -> V_77 . V_78 = V_87 ;
return;
}
}
V_88 = F_64 ( V_87 , V_25 , false ) ;
F_65 ( V_25 , V_28 ) ;
if ( V_88 )
F_66 ( V_25 , false ) ;
}
void F_61 ( struct V_27 * V_28 )
{
}
void F_62 ( struct V_27 * V_28 )
{
}
static void F_66 ( struct V_25 * V_25 , int V_91 )
{
}
static void F_67 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_87 = F_68 ( F_16 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_13 ( ! V_45 ) )
return;
V_19 = V_87 - V_45 -> V_92 ;
if ( F_13 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_92 = V_87 ;
F_69 ( V_45 -> V_93 . V_94 ,
F_70 ( V_19 , V_45 -> V_93 . V_94 ) ) ;
V_45 -> V_95 += V_19 ;
F_71 ( V_25 , V_96 , V_19 ) ;
V_45 -> V_41 += F_56 ( V_19 , V_45 ) ;
F_38 ( V_25 ) ;
if ( F_20 ( V_45 ) ) {
struct V_26 * V_97 = F_17 ( V_45 ) ;
F_72 ( V_97 , V_19 , V_45 -> V_41 ) ;
F_73 ( V_97 , V_19 ) ;
F_74 ( V_97 , V_19 ) ;
}
F_75 ( V_25 , V_19 ) ;
}
static void F_76 ( struct V_24 * V_24 )
{
F_67 ( F_23 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_98 = F_78 ( F_16 ( V_25 ) ) ;
if ( F_20 ( V_28 ) && F_79 ( F_17 ( V_28 ) ) &&
F_11 ( V_98 > V_28 -> V_93 . V_98 ) )
V_98 -= V_28 -> V_93 . V_98 ;
V_28 -> V_93 . V_98 = V_98 ;
}
static void
F_80 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_26 * V_29 ;
T_2 V_42 ;
V_42 = F_78 ( F_16 ( V_25 ) ) - V_28 -> V_93 . V_98 ;
if ( F_20 ( V_28 ) ) {
V_29 = F_17 ( V_28 ) ;
if ( F_79 ( V_29 ) ) {
V_28 -> V_93 . V_98 = V_42 ;
return;
}
F_81 ( V_29 , V_42 ) ;
}
V_28 -> V_93 . V_99 = F_70 ( V_28 -> V_93 . V_99 , V_42 ) ;
V_28 -> V_93 . V_100 ++ ;
V_28 -> V_93 . V_101 += V_42 ;
V_28 -> V_93 . V_98 = 0 ;
}
static inline void
F_82 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_77 ( V_25 , V_28 ) ;
}
static inline void
F_83 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_102 )
{
if ( V_28 != V_25 -> V_45 )
F_80 ( V_25 , V_28 ) ;
if ( V_102 & V_103 ) {
if ( F_20 ( V_28 ) ) {
struct V_26 * V_104 = F_17 ( V_28 ) ;
if ( V_104 -> V_105 & V_106 )
V_28 -> V_93 . V_107 = F_78 ( F_16 ( V_25 ) ) ;
if ( V_104 -> V_105 & V_108 )
V_28 -> V_93 . V_109 = F_78 ( F_16 ( V_25 ) ) ;
}
}
}
static inline void
F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_80 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_82 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
}
static inline void
F_83 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_102 )
{
}
static inline void
F_84 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_92 = F_68 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_85 ( struct V_26 * V_29 )
{
unsigned long V_110 = 0 ;
unsigned long V_111 ;
V_111 = V_112 << ( 20 - V_113 ) ;
V_110 = F_86 ( V_29 -> V_114 ) ;
if ( ! V_110 )
V_110 = V_111 ;
V_110 = F_87 ( V_110 , V_111 ) ;
return V_110 / V_111 ;
}
static unsigned int F_88 ( struct V_26 * V_29 )
{
unsigned int V_115 = F_89 ( V_112 ) ;
unsigned int V_116 , floor ;
unsigned int V_117 = 1 ;
if ( V_115 < V_118 )
V_117 = V_118 / V_115 ;
floor = 1000 / V_117 ;
V_116 = V_119 / F_85 ( V_29 ) ;
return F_90 (unsigned int, floor, scan) ;
}
static unsigned int F_91 ( struct V_26 * V_29 )
{
unsigned int V_120 = F_88 ( V_29 ) ;
unsigned int V_121 ;
V_121 = V_122 / F_85 ( V_29 ) ;
return F_70 ( V_120 , V_121 ) ;
}
static void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_123 += ( V_29 -> V_124 != - 1 ) ;
V_24 -> V_125 += ( V_29 -> V_124 == F_93 ( V_29 ) ) ;
}
static void F_94 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_123 -= ( V_29 -> V_124 != - 1 ) ;
V_24 -> V_125 -= ( V_29 -> V_124 == F_93 ( V_29 ) ) ;
}
T_7 F_95 ( struct V_26 * V_29 )
{
return V_29 -> V_126 ? V_29 -> V_126 -> V_127 : 0 ;
}
static inline int F_96 ( enum V_128 V_129 , int V_130 , int V_131 )
{
return V_132 * ( V_129 * V_133 + V_130 ) + V_131 ;
}
static inline unsigned long F_97 ( struct V_26 * V_29 , int V_130 )
{
if ( ! V_29 -> V_134 )
return 0 ;
return V_29 -> V_134 [ F_96 ( V_135 , V_130 , 0 ) ] +
V_29 -> V_134 [ F_96 ( V_135 , V_130 , 1 ) ] ;
}
static inline unsigned long F_98 ( struct V_26 * V_29 , int V_130 )
{
if ( ! V_29 -> V_126 )
return 0 ;
return V_29 -> V_126 -> V_136 [ F_96 ( V_135 , V_130 , 0 ) ] +
V_29 -> V_126 -> V_136 [ F_96 ( V_135 , V_130 , 1 ) ] ;
}
static inline unsigned long F_99 ( struct V_126 * V_137 , int V_130 )
{
return V_137 -> V_138 [ F_96 ( V_135 , V_130 , 0 ) ] +
V_137 -> V_138 [ F_96 ( V_135 , V_130 , 1 ) ] ;
}
static bool F_100 ( int V_130 , struct V_126 * V_139 )
{
return F_99 ( V_139 , V_130 ) * V_140 > V_139 -> V_141 ;
}
static unsigned long F_101 ( struct V_26 * V_29 , int V_130 ,
int V_142 , bool V_143 )
{
unsigned long V_144 = 0 ;
int V_145 ;
if ( V_146 == V_147 )
return 0 ;
F_102 (node) {
unsigned long V_136 ;
int V_148 = F_103 ( V_130 , V_145 ) ;
if ( V_148 == V_149 || V_145 == V_130 )
continue;
if ( V_146 == V_150 &&
V_148 > V_142 )
continue;
if ( V_143 )
V_136 = F_97 ( V_29 , V_145 ) ;
else
V_136 = F_98 ( V_29 , V_145 ) ;
if ( V_146 == V_151 ) {
V_136 *= ( V_149 - V_148 ) ;
V_136 /= ( V_149 - V_152 ) ;
}
V_144 += V_136 ;
}
return V_144 ;
}
static inline unsigned long F_104 ( struct V_26 * V_29 , int V_130 ,
int V_148 )
{
unsigned long V_136 , V_153 ;
if ( ! V_29 -> V_134 )
return 0 ;
V_153 = V_29 -> V_154 ;
if ( ! V_153 )
return 0 ;
V_136 = F_97 ( V_29 , V_130 ) ;
V_136 += F_101 ( V_29 , V_130 , V_148 , true ) ;
return 1000 * V_136 / V_153 ;
}
static inline unsigned long F_105 ( struct V_26 * V_29 , int V_130 ,
int V_148 )
{
unsigned long V_136 , V_153 ;
if ( ! V_29 -> V_126 )
return 0 ;
V_153 = V_29 -> V_126 -> V_153 ;
if ( ! V_153 )
return 0 ;
V_136 = F_98 ( V_29 , V_130 ) ;
V_136 += F_101 ( V_29 , V_130 , V_148 , false ) ;
return 1000 * V_136 / V_153 ;
}
bool F_106 ( struct V_26 * V_29 , struct V_155 * V_155 ,
int V_156 , int V_157 )
{
struct V_126 * V_139 = V_29 -> V_126 ;
int V_158 = F_107 ( V_157 ) ;
int V_159 , V_160 ;
V_160 = F_108 ( V_157 , V_161 -> V_162 ) ;
V_159 = F_109 ( V_155 , V_160 ) ;
if ( ! F_110 ( V_159 ) &&
F_111 ( V_159 ) != V_158 )
return false ;
if ( F_112 ( V_29 , V_159 ) )
return true ;
if ( ! V_139 )
return true ;
if ( F_99 ( V_139 , V_158 ) > F_99 ( V_139 , V_156 ) *
V_140 )
return true ;
return F_99 ( V_139 , V_158 ) * F_98 ( V_29 , V_156 ) * 3 >
F_99 ( V_139 , V_156 ) * F_98 ( V_29 , V_158 ) * 4 ;
}
static void F_113 ( struct V_163 * V_164 , int V_130 )
{
int V_165 , V_166 , V_8 = 0 ;
unsigned long V_167 ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
F_114 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_115 ( V_166 ) ;
V_164 -> V_72 += V_24 -> V_72 ;
V_164 -> V_70 += F_116 ( V_166 ) ;
V_164 -> V_168 += F_117 ( V_166 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_165 = F_54 ( V_86 * V_8 , V_164 -> V_168 ) ;
V_167 = V_8 / V_165 ;
V_164 -> V_169 = F_5 ( unsigned , V_167 ,
F_118 ( V_164 -> V_168 , V_86 ) ) ;
V_164 -> V_170 = ( V_164 -> V_72 < V_164 -> V_169 ) ;
}
static void F_119 ( struct V_171 * V_172 ,
struct V_26 * V_29 , long V_173 )
{
if ( V_172 -> V_174 )
F_120 ( V_172 -> V_174 ) ;
if ( V_29 )
F_121 ( V_29 ) ;
V_172 -> V_174 = V_29 ;
V_172 -> V_175 = V_173 ;
V_172 -> V_176 = V_172 -> V_157 ;
}
static bool F_122 ( long V_177 , long V_178 ,
struct V_171 * V_172 )
{
long V_179 , V_180 ;
long V_181 , V_182 ;
long V_183 , V_184 ;
V_183 = V_172 -> V_185 . V_168 ;
V_184 = V_172 -> V_186 . V_168 ;
if ( V_178 < V_177 )
F_123 ( V_178 , V_177 ) ;
V_179 = V_178 * V_183 * 100 -
V_177 * V_184 * V_172 -> V_187 ;
if ( V_179 <= 0 )
return false ;
V_181 = V_172 -> V_185 . V_70 ;
V_182 = V_172 -> V_186 . V_70 ;
if ( V_182 < V_181 )
F_123 ( V_182 , V_181 ) ;
V_180 = V_182 * V_183 * 100 -
V_181 * V_184 * V_172 -> V_187 ;
return ( V_179 > V_180 ) ;
}
static void F_124 ( struct V_171 * V_172 ,
long V_188 , long V_189 )
{
struct V_24 * V_190 = F_115 ( V_172 -> V_191 ) ;
struct V_24 * V_192 = F_115 ( V_172 -> V_157 ) ;
struct V_26 * V_193 ;
long V_177 , V_178 ;
long V_70 ;
long V_173 = V_172 -> V_29 -> V_126 ? V_189 : V_188 ;
long V_194 = V_173 ;
int V_148 = V_172 -> V_148 ;
F_125 () ;
V_193 = F_126 ( & V_192 -> V_45 ) ;
if ( V_193 && ( ( V_193 -> V_102 & V_195 ) || F_127 ( V_193 ) ) )
V_193 = NULL ;
if ( V_193 == V_172 -> V_29 )
goto V_196;
if ( V_193 ) {
if ( ! F_128 ( V_172 -> V_191 , F_129 ( V_193 ) ) )
goto V_196;
if ( V_193 -> V_126 == V_172 -> V_29 -> V_126 ) {
V_173 = V_188 + F_104 ( V_193 , V_172 -> V_156 , V_148 ) -
F_104 ( V_193 , V_172 -> V_158 , V_148 ) ;
if ( V_193 -> V_126 )
V_173 -= V_173 / 16 ;
} else {
if ( V_193 -> V_126 )
V_173 += F_105 ( V_193 , V_172 -> V_156 , V_148 ) -
F_105 ( V_193 , V_172 -> V_158 , V_148 ) ;
else
V_173 += F_104 ( V_193 , V_172 -> V_156 , V_148 ) -
F_104 ( V_193 , V_172 -> V_158 , V_148 ) ;
}
}
if ( V_173 <= V_172 -> V_175 && V_194 <= V_172 -> V_175 )
goto V_196;
if ( ! V_193 ) {
if ( V_172 -> V_185 . V_72 <= V_172 -> V_185 . V_169 &&
! V_172 -> V_186 . V_170 )
goto V_196;
goto V_197;
}
if ( V_173 > V_172 -> V_175 && V_190 -> V_72 == 1 &&
V_192 -> V_72 == 1 )
goto V_198;
V_197:
V_70 = F_130 ( V_172 -> V_29 ) ;
V_178 = V_172 -> V_186 . V_70 + V_70 ;
V_177 = V_172 -> V_185 . V_70 - V_70 ;
if ( V_194 > V_173 && V_194 > V_172 -> V_175 ) {
if ( ! F_122 ( V_177 , V_178 , V_172 ) ) {
V_173 = V_194 - 1 ;
V_193 = NULL ;
goto V_198;
}
}
if ( V_173 <= V_172 -> V_175 )
goto V_196;
if ( V_193 ) {
V_70 = F_130 ( V_193 ) ;
V_178 -= V_70 ;
V_177 += V_70 ;
}
if ( F_122 ( V_177 , V_178 , V_172 ) )
goto V_196;
if ( ! V_193 )
V_172 -> V_157 = F_131 ( V_172 -> V_29 , V_172 -> V_157 ) ;
V_198:
F_119 ( V_172 , V_193 , V_173 ) ;
V_196:
F_132 () ;
}
static void F_133 ( struct V_171 * V_172 ,
long V_188 , long V_189 )
{
int V_166 ;
F_114 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_128 ( V_166 , F_129 ( V_172 -> V_29 ) ) )
continue;
V_172 -> V_157 = V_166 ;
F_124 ( V_172 , V_188 , V_189 ) ;
}
}
static bool F_134 ( struct V_171 * V_172 )
{
struct V_163 * V_199 = & V_172 -> V_185 ;
struct V_163 * V_200 = & V_172 -> V_186 ;
if ( V_199 -> V_170 && ! V_200 -> V_170 )
return false ;
if ( V_199 -> V_70 * V_200 -> V_168 * V_172 -> V_187 >
V_200 -> V_70 * V_199 -> V_168 * 100 )
return true ;
return false ;
}
static int F_135 ( struct V_26 * V_29 )
{
struct V_171 V_172 = {
. V_29 = V_29 ,
. V_191 = F_136 ( V_29 ) ,
. V_156 = F_93 ( V_29 ) ,
. V_187 = 112 ,
. V_174 = NULL ,
. V_175 = 0 ,
. V_176 = - 1 ,
} ;
struct V_201 * V_202 ;
unsigned long V_203 , V_204 ;
int V_130 , V_66 , V_148 ;
long V_188 , V_189 ;
F_125 () ;
V_202 = F_137 ( F_138 ( V_205 , V_172 . V_191 ) ) ;
if ( V_202 )
V_172 . V_187 = 100 + ( V_202 -> V_187 - 100 ) / 2 ;
F_132 () ;
if ( F_13 ( ! V_202 ) ) {
V_29 -> V_124 = F_93 ( V_29 ) ;
return - V_206 ;
}
V_172 . V_158 = V_29 -> V_124 ;
V_148 = V_172 . V_148 = F_103 ( V_172 . V_156 , V_172 . V_158 ) ;
V_203 = F_104 ( V_29 , V_172 . V_156 , V_148 ) ;
V_204 = F_105 ( V_29 , V_172 . V_156 , V_148 ) ;
F_113 ( & V_172 . V_185 , V_172 . V_156 ) ;
V_188 = F_104 ( V_29 , V_172 . V_158 , V_148 ) - V_203 ;
V_189 = F_105 ( V_29 , V_172 . V_158 , V_148 ) - V_204 ;
F_113 ( & V_172 . V_186 , V_172 . V_158 ) ;
if ( F_134 ( & V_172 ) )
F_133 ( & V_172 , V_188 , V_189 ) ;
if ( V_172 . V_176 == - 1 || ( V_29 -> V_126 && V_29 -> V_126 -> V_207 > 1 ) ) {
F_102 (nid) {
if ( V_130 == V_172 . V_156 || V_130 == V_29 -> V_124 )
continue;
V_148 = F_103 ( V_172 . V_156 , V_172 . V_158 ) ;
if ( V_146 == V_150 &&
V_148 != V_172 . V_148 ) {
V_203 = F_104 ( V_29 , V_172 . V_156 , V_148 ) ;
V_204 = F_105 ( V_29 , V_172 . V_156 , V_148 ) ;
}
V_188 = F_104 ( V_29 , V_130 , V_148 ) - V_203 ;
V_189 = F_105 ( V_29 , V_130 , V_148 ) - V_204 ;
if ( V_188 < 0 && V_189 < 0 )
continue;
V_172 . V_148 = V_148 ;
V_172 . V_158 = V_130 ;
F_113 ( & V_172 . V_186 , V_172 . V_158 ) ;
if ( F_134 ( & V_172 ) )
F_133 ( & V_172 , V_188 , V_189 ) ;
}
}
if ( V_29 -> V_126 ) {
struct V_126 * V_139 = V_29 -> V_126 ;
if ( V_172 . V_176 == - 1 )
V_130 = V_172 . V_156 ;
else
V_130 = V_172 . V_158 ;
if ( V_139 -> V_207 > 1 && F_100 ( V_172 . V_158 , V_139 ) )
F_139 ( V_29 , V_172 . V_158 ) ;
}
if ( V_172 . V_176 == - 1 )
return - V_208 ;
V_29 -> V_209 = F_88 ( V_29 ) ;
if ( V_172 . V_174 == NULL ) {
V_66 = F_140 ( V_29 , V_172 . V_176 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_172 . V_191 , V_172 . V_176 ) ;
return V_66 ;
}
V_66 = F_142 ( V_29 , V_172 . V_174 ) ;
if ( V_66 != 0 )
F_141 ( V_29 , V_172 . V_191 , F_136 ( V_172 . V_174 ) ) ;
F_120 ( V_172 . V_174 ) ;
return V_66 ;
}
static void F_143 ( struct V_26 * V_29 )
{
unsigned long V_210 = V_211 ;
if ( F_13 ( V_29 -> V_124 == - 1 || ! V_29 -> V_134 ) )
return;
V_210 = F_144 ( V_210 , F_145 ( V_29 -> V_209 ) / 16 ) ;
V_29 -> V_212 = V_213 + V_210 ;
if ( F_93 ( V_29 ) == V_29 -> V_124 )
return;
F_135 ( V_29 ) ;
}
static void F_146 ( struct V_126 * V_126 )
{
unsigned long V_136 , V_214 = 0 ;
int V_130 , V_207 = 0 ;
F_102 (nid) {
V_136 = F_99 ( V_126 , V_130 ) ;
if ( V_136 > V_214 )
V_214 = V_136 ;
}
F_102 (nid) {
V_136 = F_99 ( V_126 , V_130 ) ;
if ( V_136 * V_140 > V_214 )
V_207 ++ ;
}
V_126 -> V_141 = V_214 ;
V_126 -> V_207 = V_207 ;
}
static void F_147 ( struct V_26 * V_29 ,
unsigned long V_215 , unsigned long V_216 )
{
unsigned int V_217 ;
int V_218 ;
int V_219 ;
unsigned long V_220 = V_29 -> V_221 [ 0 ] ;
unsigned long V_222 = V_29 -> V_221 [ 1 ] ;
if ( V_222 + V_215 == 0 || V_29 -> V_221 [ 2 ] ) {
V_29 -> V_209 = F_144 ( V_29 -> V_223 ,
V_29 -> V_209 << 1 ) ;
V_29 -> V_114 -> V_224 = V_213 +
F_145 ( V_29 -> V_209 ) ;
return;
}
V_217 = F_54 ( V_29 -> V_209 , V_225 ) ;
V_218 = ( V_222 * V_225 ) / ( V_222 + V_220 ) ;
if ( V_218 >= V_226 ) {
int V_227 = V_218 - V_226 ;
if ( ! V_227 )
V_227 = 1 ;
V_219 = V_227 * V_217 ;
} else {
V_219 = - ( V_226 - V_218 ) * V_217 ;
V_218 = F_54 ( V_216 * V_225 , ( V_216 + V_215 + 1 ) ) ;
V_219 = ( V_219 * V_218 ) / V_225 ;
}
V_29 -> V_209 = F_148 ( V_29 -> V_209 + V_219 ,
F_88 ( V_29 ) , F_91 ( V_29 ) ) ;
memset ( V_29 -> V_221 , 0 , sizeof( V_29 -> V_221 ) ) ;
}
static T_2 F_149 ( struct V_26 * V_29 , T_2 * V_228 )
{
T_2 V_229 , V_42 , V_87 ;
V_87 = V_29 -> V_28 . V_92 ;
V_229 = V_29 -> V_28 . V_95 ;
if ( V_29 -> V_230 ) {
V_42 = V_229 - V_29 -> V_231 ;
* V_228 = V_87 - V_29 -> V_230 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_70 . V_4 ;
* V_228 = V_82 ;
}
V_29 -> V_231 = V_229 ;
V_29 -> V_230 = V_87 ;
return V_42 ;
}
static int F_150 ( struct V_26 * V_29 , int V_130 )
{
T_8 V_232 ;
int V_148 ;
if ( V_146 == V_147 )
return V_130 ;
if ( V_146 == V_151 ) {
unsigned long V_144 , V_233 = 0 ;
int V_145 , V_234 = V_130 ;
V_148 = V_149 ;
F_102 (node) {
V_144 = F_105 ( V_29 , V_145 , V_148 ) ;
if ( V_144 > V_233 ) {
V_233 = V_144 ;
V_234 = V_145 ;
}
}
return V_234 ;
}
V_232 = V_235 ;
for ( V_148 = V_149 ; V_148 > V_152 ; V_148 -- ) {
unsigned long V_214 = 0 ;
T_8 V_236 = V_237 ;
int V_43 , V_44 ;
if ( ! F_151 ( V_148 ) )
continue;
F_152 (a, nodes) {
unsigned long V_136 = 0 ;
T_8 V_238 ;
F_153 ( V_238 ) ;
F_152 (b, nodes) {
if ( F_103 ( V_43 , V_44 ) < V_148 ) {
V_136 += F_98 ( V_29 , V_44 ) ;
F_154 ( V_44 , V_238 ) ;
F_155 ( V_44 , V_232 ) ;
}
}
if ( V_136 > V_214 ) {
V_214 = V_136 ;
V_236 = V_238 ;
V_130 = V_43 ;
}
}
if ( ! V_214 )
break;
V_232 = V_236 ;
}
return V_130 ;
}
static void F_156 ( struct V_26 * V_29 )
{
int V_239 , V_130 , V_240 = - 1 , V_241 = - 1 ;
unsigned long V_214 = 0 , V_242 = 0 ;
unsigned long V_243 [ 2 ] = { 0 , 0 } ;
unsigned long V_153 ;
T_2 V_229 , V_228 ;
T_9 * V_244 = NULL ;
V_239 = F_89 ( V_29 -> V_114 -> V_245 ) ;
if ( V_29 -> V_245 == V_239 )
return;
V_29 -> V_245 = V_239 ;
V_29 -> V_223 = F_91 ( V_29 ) ;
V_153 = V_29 -> V_221 [ 0 ] +
V_29 -> V_221 [ 1 ] ;
V_229 = F_149 ( V_29 , & V_228 ) ;
if ( V_29 -> V_126 ) {
V_244 = & V_29 -> V_126 -> V_246 ;
F_157 ( V_244 ) ;
}
F_102 (nid) {
int V_247 , V_248 , V_249 , V_250 ;
unsigned long V_136 = 0 , F_98 = 0 ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
long V_219 , V_251 , V_252 ;
V_247 = F_96 ( V_135 , V_130 , V_131 ) ;
V_248 = F_96 ( V_253 , V_130 , V_131 ) ;
V_249 = F_96 ( V_254 , V_130 , V_131 ) ;
V_250 = F_96 ( V_255 , V_130 , V_131 ) ;
V_219 = V_29 -> V_134 [ V_248 ] - V_29 -> V_134 [ V_247 ] / 2 ;
V_243 [ V_131 ] += V_29 -> V_134 [ V_248 ] ;
V_29 -> V_134 [ V_248 ] = 0 ;
V_252 = F_158 ( V_229 << 16 , V_228 + 1 ) ;
V_252 = ( V_252 * V_29 -> V_134 [ V_250 ] ) /
( V_153 + 1 ) ;
V_251 = V_252 - V_29 -> V_134 [ V_249 ] / 2 ;
V_29 -> V_134 [ V_250 ] = 0 ;
V_29 -> V_134 [ V_247 ] += V_219 ;
V_29 -> V_134 [ V_249 ] += V_251 ;
V_136 += V_29 -> V_134 [ V_247 ] ;
V_29 -> V_154 += V_219 ;
if ( V_29 -> V_126 ) {
V_29 -> V_126 -> V_136 [ V_247 ] += V_219 ;
V_29 -> V_126 -> V_138 [ V_247 ] += V_251 ;
V_29 -> V_126 -> V_153 += V_219 ;
F_98 += V_29 -> V_126 -> V_136 [ V_247 ] ;
}
}
if ( V_136 > V_214 ) {
V_214 = V_136 ;
V_240 = V_130 ;
}
if ( F_98 > V_242 ) {
V_242 = F_98 ;
V_241 = V_130 ;
}
}
F_147 ( V_29 , V_243 [ 0 ] , V_243 [ 1 ] ) ;
if ( V_29 -> V_126 ) {
F_146 ( V_29 -> V_126 ) ;
F_159 ( V_244 ) ;
V_240 = F_150 ( V_29 , V_241 ) ;
}
if ( V_214 ) {
if ( V_240 != V_29 -> V_124 )
F_139 ( V_29 , V_240 ) ;
if ( F_93 ( V_29 ) != V_29 -> V_124 )
F_143 ( V_29 ) ;
}
}
static inline int F_160 ( struct V_126 * V_30 )
{
return F_161 ( & V_30 -> V_256 ) ;
}
static inline void F_162 ( struct V_126 * V_30 )
{
if ( F_163 ( & V_30 -> V_256 ) )
F_164 ( V_30 , V_257 ) ;
}
static void F_165 ( struct V_26 * V_29 , int V_258 , int V_102 ,
int * V_131 )
{
struct V_126 * V_30 , * V_259 ;
struct V_26 * V_104 ;
bool V_260 = false ;
int V_166 = F_166 ( V_258 ) ;
int V_261 ;
if ( F_13 ( ! V_29 -> V_126 ) ) {
unsigned int V_262 = sizeof( struct V_126 ) +
4 * V_133 *sizeof( unsigned long ) ;
V_30 = F_167 ( V_262 , V_263 | V_264 ) ;
if ( ! V_30 )
return;
F_168 ( & V_30 -> V_256 , 1 ) ;
V_30 -> V_207 = 1 ;
V_30 -> V_141 = 0 ;
F_169 ( & V_30 -> V_246 ) ;
V_30 -> V_127 = V_29 -> V_162 ;
V_30 -> V_138 = V_30 -> V_136 + V_132 *
V_133 ;
for ( V_261 = 0 ; V_261 < V_265 * V_133 ; V_261 ++ )
V_30 -> V_136 [ V_261 ] = V_29 -> V_134 [ V_261 ] ;
V_30 -> V_153 = V_29 -> V_154 ;
V_30 -> V_266 ++ ;
F_170 ( V_29 -> V_126 , V_30 ) ;
}
F_125 () ;
V_104 = F_89 ( F_115 ( V_166 ) -> V_45 ) ;
if ( ! F_112 ( V_104 , V_258 ) )
goto V_267;
V_30 = F_137 ( V_104 -> V_126 ) ;
if ( ! V_30 )
goto V_267;
V_259 = V_29 -> V_126 ;
if ( V_30 == V_259 )
goto V_267;
if ( V_259 -> V_266 > V_30 -> V_266 )
goto V_267;
if ( V_259 -> V_266 == V_30 -> V_266 && V_259 > V_30 )
goto V_267;
if ( V_104 -> V_114 == V_161 -> V_114 )
V_260 = true ;
if ( V_102 & V_268 )
V_260 = true ;
* V_131 = ! V_260 ;
if ( V_260 && ! F_160 ( V_30 ) )
goto V_267;
F_132 () ;
if ( ! V_260 )
return;
F_171 ( F_172 () ) ;
F_173 ( & V_259 -> V_246 , & V_30 -> V_246 ) ;
for ( V_261 = 0 ; V_261 < V_265 * V_133 ; V_261 ++ ) {
V_259 -> V_136 [ V_261 ] -= V_29 -> V_134 [ V_261 ] ;
V_30 -> V_136 [ V_261 ] += V_29 -> V_134 [ V_261 ] ;
}
V_259 -> V_153 -= V_29 -> V_154 ;
V_30 -> V_153 += V_29 -> V_154 ;
V_259 -> V_266 -- ;
V_30 -> V_266 ++ ;
F_174 ( & V_259 -> V_246 ) ;
F_159 ( & V_30 -> V_246 ) ;
F_170 ( V_29 -> V_126 , V_30 ) ;
F_162 ( V_259 ) ;
return;
V_267:
F_132 () ;
return;
}
void F_175 ( struct V_26 * V_29 )
{
struct V_126 * V_30 = V_29 -> V_126 ;
void * V_134 = V_29 -> V_134 ;
unsigned long V_102 ;
int V_261 ;
if ( V_30 ) {
F_176 ( & V_30 -> V_246 , V_102 ) ;
for ( V_261 = 0 ; V_261 < V_265 * V_133 ; V_261 ++ )
V_30 -> V_136 [ V_261 ] -= V_29 -> V_134 [ V_261 ] ;
V_30 -> V_153 -= V_29 -> V_154 ;
V_30 -> V_266 -- ;
F_177 ( & V_30 -> V_246 , V_102 ) ;
F_178 ( V_29 -> V_126 , NULL ) ;
F_162 ( V_30 ) ;
}
V_29 -> V_134 = NULL ;
F_179 ( V_134 ) ;
}
void F_180 ( int V_159 , int V_269 , int V_270 , int V_102 )
{
struct V_26 * V_29 = V_161 ;
bool V_271 = V_102 & V_272 ;
int V_273 = F_93 ( V_161 ) ;
int V_222 = ! ! ( V_102 & V_274 ) ;
struct V_126 * V_139 ;
int V_131 ;
if ( ! F_181 ( & V_275 ) )
return;
if ( ! V_29 -> V_114 )
return;
if ( F_13 ( ! V_29 -> V_134 ) ) {
int V_262 = sizeof( * V_29 -> V_134 ) *
V_276 * V_133 ;
V_29 -> V_134 = F_167 ( V_262 , V_263 | V_264 ) ;
if ( ! V_29 -> V_134 )
return;
V_29 -> V_154 = 0 ;
memset ( V_29 -> V_221 , 0 , sizeof( V_29 -> V_221 ) ) ;
}
if ( F_13 ( V_159 == ( - 1 & V_277 ) ) ) {
V_131 = 1 ;
} else {
V_131 = F_112 ( V_29 , V_159 ) ;
if ( ! V_131 && ! ( V_102 & V_278 ) )
F_165 ( V_29 , V_159 , V_102 , & V_131 ) ;
}
V_139 = V_29 -> V_126 ;
if ( ! V_131 && ! V_222 && V_139 && V_139 -> V_207 > 1 &&
F_100 ( V_273 , V_139 ) &&
F_100 ( V_269 , V_139 ) )
V_222 = 1 ;
F_156 ( V_29 ) ;
if ( F_182 ( V_213 , V_29 -> V_212 ) )
F_143 ( V_29 ) ;
if ( V_271 )
V_29 -> V_279 += V_270 ;
if ( V_102 & V_280 )
V_29 -> V_221 [ 2 ] += V_270 ;
V_29 -> V_134 [ F_96 ( V_253 , V_269 , V_131 ) ] += V_270 ;
V_29 -> V_134 [ F_96 ( V_255 , V_273 , V_131 ) ] += V_270 ;
V_29 -> V_221 [ V_222 ] += V_270 ;
}
static void F_183 ( struct V_26 * V_29 )
{
F_184 ( V_29 -> V_114 -> V_245 , F_89 ( V_29 -> V_114 -> V_245 ) + 1 ) ;
V_29 -> V_114 -> V_281 = 0 ;
}
void F_185 ( struct V_282 * V_283 )
{
unsigned long V_284 , V_285 , V_87 = V_213 ;
struct V_26 * V_29 = V_161 ;
struct V_286 * V_114 = V_29 -> V_114 ;
T_2 V_229 = V_29 -> V_28 . V_95 ;
struct V_287 * V_288 ;
unsigned long V_289 , V_290 ;
unsigned long V_291 = 0 ;
long V_270 , V_292 ;
F_19 ( V_29 != F_21 ( V_283 , struct V_26 , V_293 ) ) ;
V_283 -> V_58 = V_283 ;
if ( V_29 -> V_102 & V_195 )
return;
if ( ! V_114 -> V_224 ) {
V_114 -> V_224 = V_87 +
F_145 ( V_294 ) ;
}
V_284 = V_114 -> V_224 ;
if ( F_186 ( V_87 , V_284 ) )
return;
if ( V_29 -> V_209 == 0 ) {
V_29 -> V_223 = F_91 ( V_29 ) ;
V_29 -> V_209 = F_88 ( V_29 ) ;
}
V_285 = V_87 + F_145 ( V_29 -> V_209 ) ;
if ( F_187 ( & V_114 -> V_224 , V_284 , V_285 ) != V_284 )
return;
V_29 -> V_295 += 2 * V_296 ;
V_289 = V_114 -> V_281 ;
V_270 = V_112 ;
V_270 <<= 20 - V_113 ;
V_292 = V_270 * 8 ;
if ( ! V_270 )
return;
F_188 ( & V_114 -> V_297 ) ;
V_288 = F_189 ( V_114 , V_289 ) ;
if ( ! V_288 ) {
F_183 ( V_29 ) ;
V_289 = 0 ;
V_288 = V_114 -> V_298 ;
}
for (; V_288 ; V_288 = V_288 -> V_299 ) {
if ( ! F_190 ( V_288 ) || ! F_191 ( V_288 ) ||
F_192 ( V_288 ) || ( V_288 -> V_300 & V_301 ) ) {
continue;
}
if ( ! V_288 -> V_302 ||
( V_288 -> V_303 && ( V_288 -> V_300 & ( V_304 | V_305 ) ) == ( V_304 ) ) )
continue;
if ( ! ( V_288 -> V_300 & ( V_304 | V_306 | V_305 ) ) )
continue;
do {
V_289 = F_70 ( V_289 , V_288 -> V_307 ) ;
V_290 = F_193 ( V_289 + ( V_270 << V_113 ) , V_308 ) ;
V_290 = F_144 ( V_290 , V_288 -> V_309 ) ;
V_291 = F_194 ( V_288 , V_289 , V_290 ) ;
if ( V_291 )
V_270 -= ( V_290 - V_289 ) >> V_113 ;
V_292 -= ( V_290 - V_289 ) >> V_113 ;
V_289 = V_290 ;
if ( V_270 <= 0 || V_292 <= 0 )
goto V_310;
F_195 () ;
} while ( V_290 != V_288 -> V_309 );
}
V_310:
if ( V_288 )
V_114 -> V_281 = V_289 ;
else
F_183 ( V_29 ) ;
F_196 ( & V_114 -> V_297 ) ;
if ( F_13 ( V_29 -> V_28 . V_95 != V_229 ) ) {
T_2 V_219 = V_29 -> V_28 . V_95 - V_229 ;
V_29 -> V_295 += 32 * V_219 ;
}
}
void F_197 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_282 * V_283 = & V_45 -> V_293 ;
T_2 V_228 , V_87 ;
if ( ! V_45 -> V_114 || ( V_45 -> V_102 & V_195 ) || V_283 -> V_58 != V_283 )
return;
V_87 = V_45 -> V_28 . V_95 ;
V_228 = ( T_2 ) V_45 -> V_209 * V_311 ;
if ( V_87 > V_45 -> V_295 + V_228 ) {
if ( ! V_45 -> V_295 )
V_45 -> V_209 = F_88 ( V_45 ) ;
V_45 -> V_295 += V_228 ;
if ( ! F_186 ( V_213 , V_45 -> V_114 -> V_224 ) ) {
F_198 ( V_283 , F_185 ) ;
F_199 ( V_45 , V_283 , true ) ;
}
}
}
static void F_197 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_92 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_94 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_200 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_1 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_201
if ( F_20 ( V_28 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_92 ( V_24 , F_17 ( V_28 ) ) ;
F_202 ( & V_28 -> V_312 , & V_24 -> V_313 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_203 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_32 ( V_28 ) )
F_2 ( & F_16 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_201
if ( F_20 ( V_28 ) ) {
F_94 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_204 ( & V_28 -> V_312 ) ;
}
#endif
V_25 -> V_72 -- ;
}
static long F_205 ( struct V_25 * V_25 , struct V_314 * V_33 )
{
long V_315 , V_70 , V_316 ;
V_70 = F_12 ( V_25 -> V_70 . V_4 ) ;
V_315 = F_206 ( & V_33 -> V_80 ) ;
V_315 -= V_25 -> V_317 ;
V_315 += V_70 ;
V_316 = ( V_33 -> V_316 * V_70 ) ;
if ( V_315 )
V_316 /= V_315 ;
if ( V_316 < V_318 )
V_316 = V_318 ;
if ( V_316 > V_33 -> V_316 )
V_316 = V_33 -> V_316 ;
return V_316 ;
}
static inline long F_205 ( struct V_25 * V_25 , struct V_314 * V_33 )
{
return V_33 -> V_316 ;
}
static void F_207 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_74 ) {
if ( V_25 -> V_45 == V_28 )
F_67 ( V_25 ) ;
F_203 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_74 )
F_200 ( V_25 , V_28 ) ;
}
static void F_208 ( struct V_25 * V_25 )
{
struct V_314 * V_33 ;
struct V_27 * V_28 ;
long V_316 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_209 ( V_25 ) )
return;
#ifndef F_201
if ( F_11 ( V_28 -> V_70 . V_4 == V_33 -> V_316 ) )
return;
#endif
V_316 = F_205 ( V_25 , V_33 ) ;
F_207 ( F_23 ( V_28 ) , V_28 , V_316 ) ;
}
static inline void F_208 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_210 ( T_2 V_319 , T_2 V_320 )
{
unsigned int V_321 ;
if ( ! V_320 )
return V_319 ;
else if ( F_13 ( V_320 > V_322 * 63 ) )
return 0 ;
V_321 = V_320 ;
if ( F_13 ( V_321 >= V_322 ) ) {
V_319 >>= V_321 / V_322 ;
V_321 %= V_322 ;
}
V_319 = F_15 ( V_319 , V_323 [ V_321 ] , 32 ) ;
return V_319 ;
}
static V_23 F_211 ( T_2 V_320 )
{
V_23 V_324 = 0 ;
if ( F_11 ( V_320 <= V_322 ) )
return V_325 [ V_320 ] ;
else if ( F_13 ( V_320 >= V_326 ) )
return V_82 ;
V_324 = V_327 [ V_320 / V_322 ] ;
V_320 %= V_322 ;
V_324 = F_210 ( V_324 , V_320 ) ;
return V_324 + V_325 [ V_320 ] ;
}
static T_10 int
F_212 ( T_2 V_87 , int V_166 , struct V_75 * V_76 ,
unsigned long V_4 , int V_328 , struct V_25 * V_25 )
{
T_2 V_42 , V_329 , V_330 ;
V_23 V_324 ;
unsigned int V_331 , V_332 , V_333 = 0 ;
unsigned long V_334 , V_335 ;
V_42 = V_87 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_87 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_87 ;
V_334 = F_213 ( NULL , V_166 ) ;
V_335 = F_214 ( NULL , V_166 ) ;
V_331 = V_76 -> V_79 ;
if ( V_42 + V_331 >= 1024 ) {
V_333 = 1 ;
V_76 -> V_79 = 0 ;
V_331 = 1024 - V_331 ;
V_332 = F_215 ( V_331 , V_334 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_332 ;
if ( V_25 ) {
V_25 -> V_336 +=
V_4 * V_332 ;
}
}
if ( V_328 )
V_76 -> V_84 += V_332 * V_335 ;
V_42 -= V_331 ;
V_330 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_210 ( V_76 -> V_81 , V_330 + 1 ) ;
if ( V_25 ) {
V_25 -> V_336 =
F_210 ( V_25 -> V_336 , V_330 + 1 ) ;
}
V_76 -> V_84 = F_210 ( ( T_2 ) ( V_76 -> V_84 ) , V_330 + 1 ) ;
V_324 = F_211 ( V_330 ) ;
V_324 = F_215 ( V_324 , V_334 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_324 ;
if ( V_25 )
V_25 -> V_336 += V_4 * V_324 ;
}
if ( V_328 )
V_76 -> V_84 += V_324 * V_335 ;
}
V_329 = F_215 ( V_42 , V_334 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_329 ;
if ( V_25 )
V_25 -> V_336 += V_4 * V_329 ;
}
if ( V_328 )
V_76 -> V_84 += V_329 * V_335 ;
V_76 -> V_79 += V_42 ;
if ( V_333 ) {
V_76 -> V_80 = F_216 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_337 =
F_216 ( V_25 -> V_336 , V_82 ) ;
}
V_76 -> V_83 = V_76 -> V_84 / V_82 ;
}
return V_333 ;
}
static inline void F_66 ( struct V_25 * V_25 , int V_91 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_317 ;
if ( V_25 -> V_33 == & V_338 )
return;
if ( V_91 || abs ( V_42 ) > V_25 -> V_317 / 64 ) {
F_217 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_317 = V_25 -> V_77 . V_80 ;
}
}
void F_218 ( struct V_27 * V_28 ,
struct V_25 * V_339 , struct V_25 * V_58 )
{
if ( ! F_219 ( V_340 ) )
return;
if ( V_28 -> V_77 . V_78 && V_339 ) {
T_2 V_341 ;
T_2 V_342 ;
#ifndef F_40
T_2 V_343 ;
T_2 V_344 ;
do {
V_343 = V_339 -> V_345 ;
V_344 = V_58 -> V_345 ;
F_220 () ;
V_341 = V_339 -> V_77 . V_78 ;
V_342 = V_58 -> V_77 . V_78 ;
} while ( V_341 != V_343 ||
V_342 != V_344 );
#else
V_341 = V_339 -> V_77 . V_78 ;
V_342 = V_58 -> V_77 . V_78 ;
#endif
F_212 ( V_341 , F_26 ( F_16 ( V_339 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
V_28 -> V_77 . V_78 = V_342 ;
}
}
static inline void F_66 ( struct V_25 * V_25 , int V_91 ) {}
static inline void F_221 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_166 = F_26 ( V_24 ) ;
if ( V_166 == F_222 () && & V_24 -> V_40 == V_25 ) {
unsigned long F_70 = V_24 -> V_346 ;
F_223 ( F_78 ( V_24 ) ,
F_144 ( V_25 -> V_77 . V_83 , F_70 ) , F_70 ) ;
}
}
static inline int
F_64 ( T_2 V_87 , struct V_25 * V_25 , bool V_347 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_333 , V_348 = 0 , V_349 = 0 ;
if ( F_206 ( & V_25 -> V_350 ) ) {
T_3 V_351 = F_224 ( & V_25 -> V_350 , 0 ) ;
F_225 ( & V_76 -> V_80 , V_351 ) ;
F_225 ( & V_76 -> V_81 , V_351 * V_82 ) ;
V_348 = 1 ;
}
if ( F_206 ( & V_25 -> V_352 ) ) {
long V_351 = F_224 ( & V_25 -> V_352 , 0 ) ;
F_225 ( & V_76 -> V_83 , V_351 ) ;
F_225 ( & V_76 -> V_84 , V_351 * V_82 ) ;
V_349 = 1 ;
}
V_333 = F_212 ( V_87 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_70 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_40
F_41 () ;
V_25 -> V_345 = V_76 -> V_78 ;
#endif
if ( V_347 && ( V_333 || V_349 ) )
F_221 ( V_25 ) ;
return V_333 || V_348 ;
}
static inline void F_226 ( struct V_27 * V_28 , int V_353 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_87 = F_63 ( V_25 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_166 = F_26 ( V_24 ) ;
F_212 ( V_87 , V_166 , & V_28 -> V_77 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
if ( F_64 ( V_87 , V_25 , true ) && V_353 )
F_66 ( V_25 , 0 ) ;
}
static void F_65 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( ! F_219 ( V_340 ) )
goto V_354;
if ( V_28 -> V_77 . V_78 ) {
F_212 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
}
V_354:
V_28 -> V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_28 -> V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_28 -> V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_28 -> V_77 . V_83 ;
V_25 -> V_77 . V_84 += V_28 -> V_77 . V_84 ;
F_221 ( V_25 ) ;
}
static void F_227 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_212 ( V_25 -> V_77 . V_78 , F_26 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
F_225 ( & V_25 -> V_77 . V_80 , V_28 -> V_77 . V_80 ) ;
F_225 ( & V_25 -> V_77 . V_81 , V_28 -> V_77 . V_81 ) ;
F_225 ( & V_25 -> V_77 . V_83 , V_28 -> V_77 . V_83 ) ;
F_225 ( & V_25 -> V_77 . V_84 , V_28 -> V_77 . V_84 ) ;
F_221 ( V_25 ) ;
}
static inline void
F_228 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_87 = F_63 ( V_25 ) ;
int V_271 , V_333 ;
V_271 = ! V_76 -> V_78 ;
if ( ! V_271 ) {
F_212 ( V_87 , F_26 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_74 * F_12 ( V_28 -> V_70 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_333 = F_64 ( V_87 , V_25 , ! V_271 ) ;
V_25 -> V_337 += V_76 -> V_80 ;
V_25 -> V_336 += V_76 -> V_81 ;
if ( V_271 )
F_65 ( V_25 , V_28 ) ;
if ( V_333 || V_271 )
F_66 ( V_25 , 0 ) ;
}
static inline void
F_229 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_226 ( V_28 , 1 ) ;
V_25 -> V_337 =
F_90 ( long , V_25 -> V_337 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_336 =
F_90 ( T_3 , V_25 -> V_336 - V_28 -> V_77 . V_81 , 0 ) ;
}
static inline T_2 F_230 ( struct V_25 * V_25 )
{
T_2 V_355 ;
T_2 V_78 ;
do {
V_355 = V_25 -> V_345 ;
F_220 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_355 );
return V_78 ;
}
static inline T_2 F_230 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_78 ;
}
void F_231 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_78 ;
V_78 = F_230 ( V_25 ) ;
F_212 ( V_78 , F_26 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_217 ( V_28 -> V_77 . V_80 , & V_25 -> V_350 ) ;
F_217 ( V_28 -> V_77 . V_83 , & V_25 -> V_352 ) ;
}
static inline unsigned long F_232 ( struct V_25 * V_25 )
{
return V_25 -> V_337 ;
}
static inline unsigned long F_233 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline int
F_64 ( T_2 V_87 , struct V_25 * V_25 , bool V_347 )
{
return 0 ;
}
static inline void F_226 ( struct V_27 * V_28 , int V_356 )
{
struct V_25 * V_25 = F_23 ( V_28 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_234 ( F_78 ( V_24 ) ) ;
}
static inline void
F_228 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_229 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_231 ( struct V_27 * V_28 ) {}
static inline void
F_65 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_227 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline int F_235 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_236 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_237
struct V_26 * V_104 = NULL ;
if ( F_20 ( V_28 ) )
V_104 = F_17 ( V_28 ) ;
if ( V_28 -> V_93 . V_107 ) {
T_2 V_42 = F_78 ( F_16 ( V_25 ) ) - V_28 -> V_93 . V_107 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_93 . V_357 ) )
V_28 -> V_93 . V_357 = V_42 ;
V_28 -> V_93 . V_107 = 0 ;
V_28 -> V_93 . V_358 += V_42 ;
if ( V_104 ) {
F_238 ( V_104 , V_42 >> 10 , 1 ) ;
F_239 ( V_104 , V_42 ) ;
}
}
if ( V_28 -> V_93 . V_109 ) {
T_2 V_42 = F_78 ( F_16 ( V_25 ) ) - V_28 -> V_93 . V_109 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > V_28 -> V_93 . V_359 ) )
V_28 -> V_93 . V_359 = V_42 ;
V_28 -> V_93 . V_109 = 0 ;
V_28 -> V_93 . V_358 += V_42 ;
if ( V_104 ) {
if ( V_104 -> V_360 ) {
V_28 -> V_93 . V_361 += V_42 ;
V_28 -> V_93 . V_362 ++ ;
F_240 ( V_104 , V_42 ) ;
}
F_241 ( V_104 , V_42 ) ;
if ( F_13 ( V_363 == V_364 ) ) {
F_242 ( V_364 ,
( void * ) F_243 ( V_104 ) ,
V_42 >> 20 ) ;
}
F_238 ( V_104 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_244 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_18
T_3 V_365 = V_28 -> V_41 - V_25 -> F_36 ;
if ( V_365 < 0 )
V_365 = - V_365 ;
if ( V_365 > 3 * V_68 )
F_245 ( V_25 , V_366 ) ;
#endif
}
static void
F_246 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_367 )
{
T_2 V_41 = V_25 -> F_36 ;
if ( V_367 && F_219 ( V_368 ) )
V_41 += F_60 ( V_25 , V_28 ) ;
if ( ! V_367 ) {
unsigned long V_369 = V_68 ;
if ( F_219 ( V_370 ) )
V_369 >>= 1 ;
V_41 -= V_369 ;
}
V_28 -> V_41 = F_35 ( V_28 -> V_41 , V_41 ) ;
}
static inline void F_247 ( void )
{
#ifdef F_237
if ( F_248 () )
return;
if ( F_249 () ||
F_250 () ||
F_251 () ||
F_252 () ||
F_253 () ) {
F_254 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_255 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_102 )
{
bool V_371 = ! ( V_102 & V_372 ) || ( V_102 & V_373 ) ;
bool V_45 = V_25 -> V_45 == V_28 ;
if ( V_371 && V_45 )
V_28 -> V_41 += V_25 -> F_36 ;
F_67 ( V_25 ) ;
if ( V_371 && ! V_45 )
V_28 -> V_41 += V_25 -> F_36 ;
F_228 ( V_25 , V_28 ) ;
F_200 ( V_25 , V_28 ) ;
F_208 ( V_25 ) ;
if ( V_102 & V_372 ) {
F_246 ( V_25 , V_28 , 0 ) ;
if ( F_248 () )
F_236 ( V_25 , V_28 ) ;
}
F_247 () ;
if ( F_248 () ) {
F_82 ( V_25 , V_28 ) ;
F_244 ( V_25 , V_28 ) ;
}
if ( ! V_45 )
F_42 ( V_25 , V_28 ) ;
V_28 -> V_74 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_25 ( V_25 ) ;
F_256 ( V_25 ) ;
}
}
static void F_257 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_258 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_259 ( struct V_27 * V_28 )
{
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
if ( V_25 -> V_374 != V_28 )
break;
V_25 -> V_374 = NULL ;
}
}
static void F_260 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_257 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_258 ( V_28 ) ;
if ( V_25 -> V_374 == V_28 )
F_259 ( V_28 ) ;
}
static void
F_261 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_102 )
{
F_67 ( V_25 ) ;
F_229 ( V_25 , V_28 ) ;
if ( F_248 () )
F_83 ( V_25 , V_28 , V_102 ) ;
F_260 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_45 ( V_25 , V_28 ) ;
V_28 -> V_74 = 0 ;
F_203 ( V_25 , V_28 ) ;
if ( ! ( V_102 & V_103 ) )
V_28 -> V_41 -= V_25 -> F_36 ;
F_262 ( V_25 ) ;
F_38 ( V_25 ) ;
F_208 ( V_25 ) ;
}
static void
F_263 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_375 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_375 = F_58 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_95 - V_45 -> V_376 ;
if ( V_19 > V_375 ) {
F_264 ( F_16 ( V_25 ) ) ;
F_260 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_48 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_375 )
F_264 ( F_16 ( V_25 ) ) ;
}
static void
F_265 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_74 ) {
if ( F_248 () )
F_80 ( V_25 , V_28 ) ;
F_45 ( V_25 , V_28 ) ;
F_226 ( V_28 , 1 ) ;
}
F_84 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_237
if ( F_248 () && F_16 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_93 . V_377 = F_70 ( V_28 -> V_93 . V_377 ,
V_28 -> V_95 - V_28 -> V_376 ) ;
}
#endif
V_28 -> V_376 = V_28 -> V_95 ;
}
static struct V_27 *
F_266 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_48 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_37 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_374 == V_28 ) {
struct V_27 * V_378 ;
if ( V_28 == V_45 ) {
V_378 = F_48 ( V_25 ) ;
} else {
V_378 = F_49 ( V_28 ) ;
if ( ! V_378 || ( V_45 && F_37 ( V_45 , V_378 ) ) )
V_378 = V_45 ;
}
if ( V_378 && F_267 ( V_378 , V_57 ) < 1 )
V_28 = V_378 ;
}
if ( V_25 -> V_59 && F_267 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_267 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_260 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_268 ( struct V_25 * V_25 , struct V_27 * V_339 )
{
if ( V_339 -> V_74 )
F_67 ( V_25 ) ;
F_269 ( V_25 ) ;
if ( F_248 () ) {
F_244 ( V_25 , V_339 ) ;
if ( V_339 -> V_74 )
F_77 ( V_25 , V_339 ) ;
}
if ( V_339 -> V_74 ) {
F_42 ( V_25 , V_339 ) ;
F_226 ( V_339 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_270 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_379 )
{
F_67 ( V_25 ) ;
F_226 ( V_45 , 1 ) ;
F_208 ( V_25 ) ;
#ifdef F_271
if ( V_379 ) {
F_264 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_219 ( V_380 ) &&
F_272 ( & F_16 ( V_25 ) -> V_381 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_263 ( V_25 , V_45 ) ;
}
static inline bool F_273 ( void )
{
return F_274 ( & V_382 ) ;
}
void F_275 ( void )
{
F_276 ( & V_382 ) ;
}
void F_277 ( void )
{
F_278 ( & V_382 ) ;
}
static bool F_273 ( void )
{
return true ;
}
void F_275 ( void ) {}
void F_277 ( void ) {}
static inline T_2 F_279 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_280 ( void )
{
return ( T_2 ) V_383 * V_384 ;
}
void F_281 ( struct V_385 * V_386 )
{
T_2 V_87 ;
if ( V_386 -> V_387 == V_388 )
return;
V_87 = F_282 ( F_222 () ) ;
V_386 -> V_229 = V_386 -> V_387 ;
V_386 -> V_389 = V_87 + F_283 ( V_386 -> V_228 ) ;
}
static inline struct V_385 * F_284 ( struct V_314 * V_33 )
{
return & V_33 -> V_385 ;
}
static inline T_2 F_63 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_390 ) )
return V_25 -> V_391 - V_25 -> V_392 ;
return F_68 ( F_16 ( V_25 ) ) - V_25 -> V_392 ;
}
static int F_285 ( struct V_25 * V_25 )
{
struct V_314 * V_33 = V_25 -> V_33 ;
struct V_385 * V_386 = F_284 ( V_33 ) ;
T_2 V_393 = 0 , V_394 , V_395 ;
V_394 = F_280 () - V_25 -> V_396 ;
F_286 ( & V_386 -> V_246 ) ;
if ( V_386 -> V_387 == V_388 )
V_393 = V_394 ;
else {
F_287 ( V_386 ) ;
if ( V_386 -> V_229 > 0 ) {
V_393 = F_144 ( V_386 -> V_229 , V_394 ) ;
V_386 -> V_229 -= V_393 ;
V_386 -> V_397 = 0 ;
}
}
V_395 = V_386 -> V_389 ;
F_288 ( & V_386 -> V_246 ) ;
V_25 -> V_396 += V_393 ;
if ( ( T_3 ) ( V_395 - V_25 -> V_389 ) > 0 )
V_25 -> V_389 = V_395 ;
return V_25 -> V_396 > 0 ;
}
static void F_289 ( struct V_25 * V_25 )
{
struct V_385 * V_386 = F_284 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_78 ( F_16 ( V_25 ) ) - V_25 -> V_389 ) < 0 ) )
return;
if ( V_25 -> V_396 < 0 )
return;
if ( V_25 -> V_389 != V_386 -> V_389 ) {
V_25 -> V_389 += V_296 ;
} else {
V_25 -> V_396 = 0 ;
}
}
static void F_290 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_396 -= V_19 ;
F_289 ( V_25 ) ;
if ( F_11 ( V_25 -> V_396 > 0 ) )
return;
if ( ! F_285 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_264 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_75 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_273 () || ! V_25 -> V_398 )
return;
F_290 ( V_25 , V_19 ) ;
}
static inline int F_291 ( struct V_25 * V_25 )
{
return F_273 () && V_25 -> V_399 ;
}
static inline int F_209 ( struct V_25 * V_25 )
{
return F_273 () && V_25 -> V_390 ;
}
static inline int F_292 ( struct V_314 * V_33 ,
int V_191 , int V_400 )
{
struct V_25 * V_401 , * V_402 ;
V_401 = V_33 -> V_25 [ V_191 ] ;
V_402 = V_33 -> V_25 [ V_400 ] ;
return F_209 ( V_401 ) ||
F_209 ( V_402 ) ;
}
static int F_293 ( struct V_314 * V_33 , void * V_403 )
{
struct V_24 * V_24 = V_403 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
V_25 -> V_390 -- ;
if ( ! V_25 -> V_390 ) {
V_25 -> V_392 += F_68 ( V_24 ) -
V_25 -> V_391 ;
}
return 0 ;
}
static int F_294 ( struct V_314 * V_33 , void * V_403 )
{
struct V_24 * V_24 = V_403 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_26 ( V_24 ) ] ;
if ( ! V_25 -> V_390 )
V_25 -> V_391 = F_68 ( V_24 ) ;
V_25 -> V_390 ++ ;
return 0 ;
}
static void F_295 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_385 * V_386 = F_284 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_404 , V_405 = 1 ;
bool V_406 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( F_16 ( V_25 ) ) ] ;
F_125 () ;
F_296 ( V_25 -> V_33 , F_294 , V_407 , ( void * ) V_24 ) ;
F_132 () ;
V_404 = V_25 -> V_408 ;
F_59 (se) {
struct V_25 * V_409 = F_23 ( V_28 ) ;
if ( ! V_28 -> V_74 )
break;
if ( V_405 )
F_261 ( V_409 , V_28 , V_103 ) ;
V_409 -> V_408 -= V_404 ;
if ( V_409 -> V_70 . V_4 )
V_405 = 0 ;
}
if ( ! V_28 )
F_297 ( V_24 , V_404 ) ;
V_25 -> V_399 = 1 ;
V_25 -> V_410 = F_78 ( V_24 ) ;
F_286 ( & V_386 -> V_246 ) ;
V_406 = F_298 ( & V_386 -> V_411 ) ;
F_27 ( & V_25 -> V_412 , & V_386 -> V_411 ) ;
if ( V_406 )
F_287 ( V_386 ) ;
F_288 ( & V_386 -> V_246 ) ;
}
void F_299 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_385 * V_386 = F_284 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_413 = 1 ;
long V_404 ;
V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
V_25 -> V_399 = 0 ;
F_300 ( V_24 ) ;
F_286 ( & V_386 -> V_246 ) ;
V_386 -> V_414 += F_78 ( V_24 ) - V_25 -> V_410 ;
F_30 ( & V_25 -> V_412 ) ;
F_288 ( & V_386 -> V_246 ) ;
F_296 ( V_25 -> V_33 , V_407 , F_293 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_404 = V_25 -> V_408 ;
F_59 (se) {
if ( V_28 -> V_74 )
V_413 = 0 ;
V_25 = F_23 ( V_28 ) ;
if ( V_413 )
F_255 ( V_25 , V_28 , V_372 ) ;
V_25 -> V_408 += V_404 ;
if ( F_291 ( V_25 ) )
break;
}
if ( ! V_28 )
F_301 ( V_24 , V_404 ) ;
if ( V_24 -> V_45 == V_24 -> V_397 && V_24 -> V_40 . V_72 )
F_264 ( V_24 ) ;
}
static T_2 F_302 ( struct V_385 * V_386 ,
T_2 V_415 , T_2 V_395 )
{
struct V_25 * V_25 ;
T_2 V_229 ;
T_2 V_416 = V_415 ;
F_125 () ;
F_303 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_286 ( & V_24 -> V_246 ) ;
if ( ! F_291 ( V_25 ) )
goto V_58;
V_229 = - V_25 -> V_396 + 1 ;
if ( V_229 > V_415 )
V_229 = V_415 ;
V_415 -= V_229 ;
V_25 -> V_396 += V_229 ;
V_25 -> V_389 = V_395 ;
if ( V_25 -> V_396 > 0 )
F_299 ( V_25 ) ;
V_58:
F_288 ( & V_24 -> V_246 ) ;
if ( ! V_415 )
break;
}
F_132 () ;
return V_416 - V_415 ;
}
static int F_304 ( struct V_385 * V_386 , int V_417 )
{
T_2 V_229 , V_389 ;
int V_399 ;
if ( V_386 -> V_387 == V_388 )
goto V_418;
V_399 = ! F_298 ( & V_386 -> V_411 ) ;
V_386 -> V_419 += V_417 ;
if ( V_386 -> V_397 && ! V_399 )
goto V_418;
F_281 ( V_386 ) ;
if ( ! V_399 ) {
V_386 -> V_397 = 1 ;
return 0 ;
}
V_386 -> V_420 += V_417 ;
V_389 = V_386 -> V_389 ;
while ( V_399 && V_386 -> V_229 > 0 ) {
V_229 = V_386 -> V_229 ;
F_288 ( & V_386 -> V_246 ) ;
V_229 = F_302 ( V_386 , V_229 ,
V_389 ) ;
F_286 ( & V_386 -> V_246 ) ;
V_399 = ! F_298 ( & V_386 -> V_411 ) ;
V_386 -> V_229 -= F_144 ( V_229 , V_386 -> V_229 ) ;
}
V_386 -> V_397 = 0 ;
return 0 ;
V_418:
return 1 ;
}
static int F_305 ( struct V_385 * V_386 , T_2 V_421 )
{
struct V_422 * V_423 = & V_386 -> V_424 ;
T_2 V_415 ;
if ( F_306 ( V_423 ) )
return 1 ;
V_415 = F_283 ( F_307 ( V_423 ) ) ;
if ( V_415 < V_421 )
return 1 ;
return 0 ;
}
static void F_308 ( struct V_385 * V_386 )
{
T_2 V_425 = V_426 + V_427 ;
if ( F_305 ( V_386 , V_425 ) )
return;
F_309 ( & V_386 -> V_428 ,
F_310 ( V_426 ) ,
V_429 ) ;
}
static void F_311 ( struct V_25 * V_25 )
{
struct V_385 * V_386 = F_284 ( V_25 -> V_33 ) ;
T_3 V_430 = V_25 -> V_396 - V_431 ;
if ( V_430 <= 0 )
return;
F_286 ( & V_386 -> V_246 ) ;
if ( V_386 -> V_387 != V_388 &&
V_25 -> V_389 == V_386 -> V_389 ) {
V_386 -> V_229 += V_430 ;
if ( V_386 -> V_229 > F_280 () &&
! F_298 ( & V_386 -> V_411 ) )
F_308 ( V_386 ) ;
}
F_288 ( & V_386 -> V_246 ) ;
V_25 -> V_396 -= V_430 ;
}
static T_10 void F_262 ( struct V_25 * V_25 )
{
if ( ! F_273 () )
return;
if ( ! V_25 -> V_398 || V_25 -> V_72 )
return;
F_311 ( V_25 ) ;
}
static void F_312 ( struct V_385 * V_386 )
{
T_2 V_229 = 0 , V_73 = F_280 () ;
T_2 V_395 ;
F_286 ( & V_386 -> V_246 ) ;
if ( F_305 ( V_386 , V_427 ) ) {
F_288 ( & V_386 -> V_246 ) ;
return;
}
if ( V_386 -> V_387 != V_388 && V_386 -> V_229 > V_73 )
V_229 = V_386 -> V_229 ;
V_395 = V_386 -> V_389 ;
F_288 ( & V_386 -> V_246 ) ;
if ( ! V_229 )
return;
V_229 = F_302 ( V_386 , V_229 , V_395 ) ;
F_286 ( & V_386 -> V_246 ) ;
if ( V_395 == V_386 -> V_389 )
V_386 -> V_229 -= F_144 ( V_229 , V_386 -> V_229 ) ;
F_288 ( & V_386 -> V_246 ) ;
}
static void F_256 ( struct V_25 * V_25 )
{
if ( ! F_273 () )
return;
if ( ! V_25 -> V_398 || V_25 -> V_45 )
return;
if ( F_291 ( V_25 ) )
return;
F_75 ( V_25 , 0 ) ;
if ( V_25 -> V_396 <= 0 )
F_295 ( V_25 ) ;
}
static void F_313 ( struct V_314 * V_33 , int V_166 )
{
struct V_25 * V_432 , * V_25 ;
if ( ! F_273 () )
return;
if ( ! V_33 -> V_34 )
return;
V_25 = V_33 -> V_25 [ V_166 ] ;
V_432 = V_33 -> V_34 -> V_25 [ V_166 ] ;
V_25 -> V_390 = V_432 -> V_390 ;
V_25 -> V_391 = F_68 ( F_115 ( V_166 ) ) ;
}
static bool F_269 ( struct V_25 * V_25 )
{
if ( ! F_273 () )
return false ;
if ( F_11 ( ! V_25 -> V_398 || V_25 -> V_396 > 0 ) )
return false ;
if ( F_291 ( V_25 ) )
return true ;
F_295 ( V_25 ) ;
return true ;
}
static enum V_433 F_314 ( struct V_422 * V_434 )
{
struct V_385 * V_386 =
F_21 ( V_434 , struct V_385 , V_428 ) ;
F_312 ( V_386 ) ;
return V_435 ;
}
static enum V_433 F_315 ( struct V_422 * V_434 )
{
struct V_385 * V_386 =
F_21 ( V_434 , struct V_385 , V_424 ) ;
int V_417 ;
int V_397 = 0 ;
F_286 ( & V_386 -> V_246 ) ;
for (; ; ) {
V_417 = F_316 ( V_434 , V_386 -> V_228 ) ;
if ( ! V_417 )
break;
V_397 = F_304 ( V_386 , V_417 ) ;
}
if ( V_397 )
V_386 -> V_436 = 0 ;
F_288 ( & V_386 -> V_246 ) ;
return V_397 ? V_435 : V_437 ;
}
void F_317 ( struct V_385 * V_386 )
{
F_318 ( & V_386 -> V_246 ) ;
V_386 -> V_229 = 0 ;
V_386 -> V_387 = V_388 ;
V_386 -> V_228 = F_310 ( F_279 () ) ;
F_319 ( & V_386 -> V_411 ) ;
F_320 ( & V_386 -> V_424 , V_438 , V_439 ) ;
V_386 -> V_424 . V_440 = F_315 ;
F_320 ( & V_386 -> V_428 , V_438 , V_429 ) ;
V_386 -> V_428 . V_440 = F_314 ;
}
static void F_321 ( struct V_25 * V_25 )
{
V_25 -> V_398 = 0 ;
F_319 ( & V_25 -> V_412 ) ;
}
void F_287 ( struct V_385 * V_386 )
{
F_322 ( & V_386 -> V_246 ) ;
if ( ! V_386 -> V_436 ) {
V_386 -> V_436 = 1 ;
F_316 ( & V_386 -> V_424 , V_386 -> V_228 ) ;
F_323 ( & V_386 -> V_424 , V_439 ) ;
}
}
static void F_324 ( struct V_385 * V_386 )
{
if ( ! V_386 -> V_411 . V_58 )
return;
F_325 ( & V_386 -> V_424 ) ;
F_325 ( & V_386 -> V_428 ) ;
}
static void T_11 F_326 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_327 (rq, cfs_rq) {
struct V_385 * V_386 = & V_25 -> V_33 -> V_385 ;
F_286 ( & V_386 -> V_246 ) ;
V_25 -> V_398 = V_386 -> V_387 != V_388 ;
F_288 ( & V_386 -> V_246 ) ;
}
}
static void T_11 F_328 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_327 (rq, cfs_rq) {
if ( ! V_25 -> V_398 )
continue;
V_25 -> V_396 = 1 ;
V_25 -> V_398 = 0 ;
if ( F_291 ( V_25 ) )
F_299 ( V_25 ) ;
}
}
static inline T_2 F_63 ( struct V_25 * V_25 )
{
return F_68 ( F_16 ( V_25 ) ) ;
}
static void F_75 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_269 ( struct V_25 * V_25 ) { return false ; }
static void F_256 ( struct V_25 * V_25 ) {}
static inline void F_313 ( struct V_314 * V_33 , int V_166 ) {}
static T_10 void F_262 ( struct V_25 * V_25 ) {}
static inline int F_291 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_209 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_292 ( struct V_314 * V_33 ,
int V_191 , int V_400 )
{
return 0 ;
}
void F_317 ( struct V_385 * V_386 ) {}
static void F_321 ( struct V_25 * V_25 ) {}
static inline struct V_385 * F_284 ( struct V_314 * V_33 )
{
return NULL ;
}
static inline void F_324 ( struct V_385 * V_386 ) {}
static inline void F_326 ( struct V_24 * V_24 ) {}
static inline void F_328 ( struct V_24 * V_24 ) {}
static void F_329 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_330 ( F_34 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_73 = F_58 ( V_25 , V_28 ) ;
T_2 V_441 = V_28 -> V_95 - V_28 -> V_376 ;
T_3 V_42 = V_73 - V_441 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_264 ( V_24 ) ;
return;
}
F_331 ( V_24 , V_42 ) ;
}
}
static void F_332 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_333 ( V_24 ) || V_45 -> V_89 != & V_90 )
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
F_334 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_102 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_59 (se) {
if ( V_28 -> V_74 )
break;
V_25 = F_23 ( V_28 ) ;
F_255 ( V_25 , V_28 , V_102 ) ;
if ( F_291 ( V_25 ) )
break;
V_25 -> V_408 ++ ;
V_102 = V_372 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_408 ++ ;
if ( F_291 ( V_25 ) )
break;
F_226 ( V_28 , 1 ) ;
F_208 ( V_25 ) ;
}
if ( ! V_28 )
F_301 ( V_24 , 1 ) ;
F_332 ( V_24 ) ;
}
static void F_335 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_102 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_442 = V_102 & V_103 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_261 ( V_25 , V_28 , V_102 ) ;
if ( F_291 ( V_25 ) )
break;
V_25 -> V_408 -- ;
if ( V_25 -> V_70 . V_4 ) {
V_28 = F_32 ( V_28 ) ;
if ( V_442 && V_28 && ! F_209 ( V_25 ) )
F_336 ( V_28 ) ;
break;
}
V_102 |= V_103 ;
}
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_408 -- ;
if ( F_291 ( V_25 ) )
break;
F_226 ( V_28 , 1 ) ;
F_208 ( V_25 ) ;
}
if ( ! V_28 )
F_297 ( V_24 , 1 ) ;
F_332 ( V_24 ) ;
}
static unsigned long
F_337 ( unsigned long V_70 , unsigned long V_443 , int V_444 )
{
int V_445 = 0 ;
if ( ! V_443 )
return V_70 ;
if ( V_443 >= V_446 [ V_444 ] )
return 0 ;
if ( V_444 == 1 )
return V_70 >> V_443 ;
while ( V_443 ) {
if ( V_443 % 2 )
V_70 = ( V_70 * V_447 [ V_444 ] [ V_445 ] ) >> V_448 ;
V_443 >>= 1 ;
V_445 ++ ;
}
return V_70 ;
}
static void F_338 ( struct V_24 * V_449 , unsigned long V_450 ,
unsigned long V_451 )
{
unsigned long T_11 V_452 = V_449 -> V_453 [ 0 ] ;
int V_261 , V_454 ;
V_449 -> V_455 ++ ;
V_449 -> V_453 [ 0 ] = V_450 ;
for ( V_261 = 1 , V_454 = 2 ; V_261 < V_456 ; V_261 ++ , V_454 += V_454 ) {
unsigned long V_457 , V_458 ;
V_457 = V_449 -> V_453 [ V_261 ] ;
#ifdef F_339
V_457 = F_337 ( V_457 , V_451 - 1 , V_261 ) ;
if ( V_452 ) {
V_457 -= F_337 ( V_452 , V_451 - 1 , V_261 ) ;
V_457 += V_452 ;
}
#endif
V_458 = V_450 ;
if ( V_458 > V_457 )
V_458 += V_454 - 1 ;
V_449 -> V_453 [ V_261 ] = ( V_457 * ( V_454 - 1 ) + V_458 ) >> V_261 ;
}
F_340 ( V_449 ) ;
}
static unsigned long F_116 ( const int V_166 )
{
return F_232 ( & F_115 ( V_166 ) -> V_40 ) ;
}
static void F_341 ( struct V_24 * V_449 ,
unsigned long V_459 ,
unsigned long V_70 )
{
unsigned long V_451 ;
V_451 = V_459 - V_449 -> V_460 ;
if ( V_451 ) {
V_449 -> V_460 = V_459 ;
F_338 ( V_449 , V_70 , V_451 ) ;
}
}
static void F_342 ( struct V_24 * V_449 )
{
if ( F_116 ( F_26 ( V_449 ) ) )
return;
F_341 ( V_449 , F_89 ( V_213 ) , 0 ) ;
}
void F_343 ( void )
{
struct V_24 * V_449 = V_449 () ;
V_449 -> V_453 [ 0 ] = F_116 ( F_26 ( V_449 ) ) ;
}
void F_344 ( void )
{
unsigned long V_459 = F_89 ( V_213 ) ;
struct V_24 * V_449 = V_449 () ;
unsigned long V_70 ;
if ( V_459 == V_449 -> V_460 )
return;
V_70 = F_116 ( F_26 ( V_449 ) ) ;
F_286 ( & V_449 -> V_246 ) ;
F_300 ( V_449 ) ;
F_341 ( V_449 , V_459 , V_70 ) ;
F_288 ( & V_449 -> V_246 ) ;
}
static inline void F_341 ( struct V_24 * V_449 ,
unsigned long V_459 ,
unsigned long V_70 ) { }
static void F_345 ( struct V_24 * V_449 , unsigned long V_70 )
{
#ifdef F_339
V_449 -> V_460 = F_89 ( V_213 ) ;
#endif
F_338 ( V_449 , V_70 , 1 ) ;
}
void F_346 ( struct V_24 * V_449 )
{
unsigned long V_70 = F_116 ( F_26 ( V_449 ) ) ;
if ( F_347 () )
F_341 ( V_449 , F_89 ( V_213 ) , V_70 ) ;
else
F_345 ( V_449 , V_70 ) ;
}
static unsigned long F_348 ( int V_166 , int type )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
unsigned long V_461 = F_116 ( V_166 ) ;
if ( type == 0 || ! F_219 ( V_462 ) )
return V_461 ;
return F_144 ( V_24 -> V_453 [ type - 1 ] , V_461 ) ;
}
static unsigned long F_349 ( int V_166 , int type )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
unsigned long V_461 = F_116 ( V_166 ) ;
if ( type == 0 || ! F_219 ( V_462 ) )
return V_461 ;
return F_70 ( V_24 -> V_453 [ type - 1 ] , V_461 ) ;
}
static unsigned long F_117 ( int V_166 )
{
return F_115 ( V_166 ) -> V_463 ;
}
static unsigned long F_350 ( int V_166 )
{
return F_115 ( V_166 ) -> V_346 ;
}
static unsigned long F_351 ( int V_166 )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
unsigned long V_72 = F_89 ( V_24 -> V_40 . V_408 ) ;
unsigned long V_80 = F_116 ( V_166 ) ;
if ( V_72 )
return V_80 / V_72 ;
return 0 ;
}
static long F_352 ( struct V_314 * V_33 , int V_166 , long V_464 , long V_465 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_166 ] ;
if ( ! V_33 -> V_34 )
return V_464 ;
F_59 (se) {
struct V_25 * V_25 = V_28 -> V_31 ;
long V_466 , V_7 = F_233 ( V_25 ) ;
V_33 = V_25 -> V_33 ;
V_466 = V_465 + F_206 ( & V_33 -> V_80 ) ;
V_466 -= V_25 -> V_317 ;
V_466 += V_7 ;
V_7 += V_464 ;
if ( V_466 > 0 && V_7 < V_466 )
V_464 = ( V_7 * ( long ) V_33 -> V_316 ) / V_466 ;
else
V_464 = V_33 -> V_316 ;
if ( V_464 < V_318 )
V_464 = V_318 ;
V_464 -= V_28 -> V_77 . V_80 ;
V_465 = 0 ;
}
return V_464 ;
}
static long F_352 ( struct V_314 * V_33 , int V_166 , long V_464 , long V_465 )
{
return V_464 ;
}
static void F_353 ( struct V_26 * V_29 )
{
if ( F_182 ( V_213 , V_161 -> V_467 + V_211 ) ) {
V_161 -> V_468 >>= 1 ;
V_161 -> V_467 = V_213 ;
}
if ( V_161 -> V_469 != V_29 ) {
V_161 -> V_469 = V_29 ;
V_161 -> V_468 ++ ;
}
}
static int F_354 ( struct V_26 * V_29 )
{
unsigned int V_470 = V_161 -> V_468 ;
unsigned int V_471 = V_29 -> V_468 ;
int V_9 = F_355 ( V_472 ) ;
if ( V_470 < V_471 )
F_123 ( V_470 , V_471 ) ;
if ( V_471 < V_9 || V_470 < V_471 * V_9 )
return 0 ;
return 1 ;
}
static int F_356 ( struct V_201 * V_202 , struct V_26 * V_29 , int V_473 )
{
T_3 V_450 , V_70 ;
T_3 V_474 , V_475 ;
int V_444 , V_476 , V_477 ;
struct V_314 * V_33 ;
unsigned long V_4 ;
int V_478 ;
V_444 = V_202 -> V_479 ;
V_476 = F_222 () ;
V_477 = F_136 ( V_29 ) ;
V_70 = F_348 ( V_477 , V_444 ) ;
V_450 = F_349 ( V_476 , V_444 ) ;
if ( V_473 ) {
V_33 = V_314 ( V_161 ) ;
V_4 = V_161 -> V_28 . V_77 . V_80 ;
V_450 += F_352 ( V_33 , V_476 , - V_4 , - V_4 ) ;
V_70 += F_352 ( V_33 , V_477 , 0 , - V_4 ) ;
}
V_33 = V_314 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_474 = 100 ;
V_474 *= F_117 ( V_477 ) ;
V_475 = 100 + ( V_202 -> V_187 - 100 ) / 2 ;
V_475 *= F_117 ( V_476 ) ;
if ( V_450 > 0 ) {
V_474 *= V_450 +
F_352 ( V_33 , V_476 , V_4 , V_4 ) ;
V_475 *= V_70 + F_352 ( V_33 , V_477 , 0 , V_4 ) ;
}
V_478 = V_474 <= V_475 ;
F_245 ( V_29 , V_28 . V_93 . V_480 ) ;
if ( ! V_478 )
return 0 ;
F_245 ( V_202 , V_481 ) ;
F_245 ( V_29 , V_28 . V_93 . V_482 ) ;
return 1 ;
}
static struct V_483 *
F_357 ( struct V_201 * V_202 , struct V_26 * V_29 ,
int V_476 , int V_484 )
{
struct V_483 * V_485 = NULL , * V_137 = V_202 -> V_486 ;
unsigned long V_487 = V_488 , V_450 = 0 ;
int V_489 = V_202 -> V_490 ;
int V_491 = 100 + ( V_202 -> V_187 - 100 ) / 2 ;
if ( V_484 & V_492 )
V_489 = V_202 -> V_479 ;
do {
unsigned long V_70 , V_493 ;
int V_494 ;
int V_261 ;
if ( ! F_358 ( F_359 ( V_137 ) ,
F_129 ( V_29 ) ) )
continue;
V_494 = F_128 ( V_476 ,
F_359 ( V_137 ) ) ;
V_493 = 0 ;
F_114 (i, sched_group_cpus(group)) {
if ( V_494 )
V_70 = F_348 ( V_261 , V_489 ) ;
else
V_70 = F_349 ( V_261 , V_489 ) ;
V_493 += V_70 ;
}
V_493 = ( V_493 * V_86 ) / V_137 -> V_495 -> V_167 ;
if ( V_494 ) {
V_450 = V_493 ;
} else if ( V_493 < V_487 ) {
V_487 = V_493 ;
V_485 = V_137 ;
}
} while ( V_137 = V_137 -> V_58 , V_137 != V_202 -> V_486 );
if ( ! V_485 || 100 * V_450 < V_491 * V_487 )
return NULL ;
return V_485 ;
}
static int
F_360 ( struct V_483 * V_137 , struct V_26 * V_29 , int V_476 )
{
unsigned long V_70 , V_487 = V_488 ;
unsigned int V_496 = V_497 ;
T_2 V_498 = 0 ;
int V_499 = V_476 ;
int V_500 = - 1 ;
int V_261 ;
F_361 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_362 ( V_261 ) ) {
struct V_24 * V_24 = F_115 ( V_261 ) ;
struct V_501 * V_397 = F_363 ( V_24 ) ;
if ( V_397 && V_397 -> V_502 < V_496 ) {
V_496 = V_397 -> V_502 ;
V_498 = V_24 -> V_503 ;
V_500 = V_261 ;
} else if ( ( ! V_397 || V_397 -> V_502 == V_496 ) &&
V_24 -> V_503 > V_498 ) {
V_498 = V_24 -> V_503 ;
V_500 = V_261 ;
}
} else if ( V_500 == - 1 ) {
V_70 = F_116 ( V_261 ) ;
if ( V_70 < V_487 || ( V_70 == V_487 && V_261 == V_476 ) ) {
V_487 = V_70 ;
V_499 = V_261 ;
}
}
}
return V_500 != - 1 ? V_500 : V_499 ;
}
static int F_131 ( struct V_26 * V_29 , int V_504 )
{
struct V_201 * V_202 ;
struct V_483 * V_505 ;
int V_261 = F_136 ( V_29 ) ;
if ( F_362 ( V_504 ) )
return V_504 ;
if ( V_261 != V_504 && F_364 ( V_261 , V_504 ) && F_362 ( V_261 ) )
return V_261 ;
V_202 = F_137 ( F_138 ( V_506 , V_504 ) ) ;
F_365 (sd) {
V_505 = V_202 -> V_486 ;
do {
if ( ! F_358 ( F_359 ( V_505 ) ,
F_129 ( V_29 ) ) )
goto V_58;
F_114 (i, sched_group_cpus(sg)) {
if ( V_261 == V_504 || ! F_362 ( V_261 ) )
goto V_58;
}
V_504 = F_366 ( F_359 ( V_505 ) ,
F_129 ( V_29 ) ) ;
goto V_507;
V_58:
V_505 = V_505 -> V_58 ;
} while ( V_505 != V_202 -> V_486 );
}
V_507:
return V_504 ;
}
static int F_367 ( int V_166 )
{
unsigned long V_508 = F_115 ( V_166 ) -> V_40 . V_77 . V_83 ;
unsigned long V_167 = F_350 ( V_166 ) ;
return ( V_508 >= V_167 ) ? V_167 : V_508 ;
}
static int
F_368 ( struct V_26 * V_29 , int V_477 , int V_484 , int V_509 )
{
struct V_201 * V_510 , * V_511 = NULL , * V_202 = NULL ;
int V_166 = F_222 () ;
int V_512 = V_477 ;
int V_513 = 0 ;
int V_473 = V_509 & V_514 ;
if ( V_484 & V_492 ) {
F_353 ( V_29 ) ;
V_513 = ! F_354 ( V_29 ) && F_128 ( V_166 , F_129 ( V_29 ) ) ;
}
F_125 () ;
F_369 (cpu, tmp) {
if ( ! ( V_510 -> V_102 & V_515 ) )
break;
if ( V_513 && ( V_510 -> V_102 & V_516 ) &&
F_128 ( V_477 , F_370 ( V_510 ) ) ) {
V_511 = V_510 ;
break;
}
if ( V_510 -> V_102 & V_484 )
V_202 = V_510 ;
else if ( ! V_513 )
break;
}
if ( V_511 ) {
V_202 = NULL ;
if ( V_166 != V_477 && F_356 ( V_511 , V_29 , V_473 ) )
V_512 = V_166 ;
}
if ( ! V_202 ) {
if ( V_484 & V_492 )
V_512 = F_131 ( V_29 , V_512 ) ;
} else while ( V_202 ) {
struct V_483 * V_137 ;
int V_4 ;
if ( ! ( V_202 -> V_102 & V_484 ) ) {
V_202 = V_202 -> V_517 ;
continue;
}
V_137 = F_357 ( V_202 , V_29 , V_166 , V_484 ) ;
if ( ! V_137 ) {
V_202 = V_202 -> V_517 ;
continue;
}
V_512 = F_360 ( V_137 , V_29 , V_166 ) ;
if ( V_512 == - 1 || V_512 == V_166 ) {
V_202 = V_202 -> V_517 ;
continue;
}
V_166 = V_512 ;
V_4 = V_202 -> V_518 ;
V_202 = NULL ;
F_369 (cpu, tmp) {
if ( V_4 <= V_510 -> V_518 )
break;
if ( V_510 -> V_102 & V_484 )
V_202 = V_510 ;
}
}
F_132 () ;
return V_512 ;
}
static void F_371 ( struct V_26 * V_29 )
{
if ( V_29 -> V_105 == V_519 ) {
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_220 () ;
F_36 = V_25 -> F_36 ;
} while ( F_36 != V_48 );
#else
F_36 = V_25 -> F_36 ;
#endif
V_28 -> V_41 -= F_36 ;
}
F_231 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_92 = 0 ;
}
static void F_372 ( struct V_26 * V_29 )
{
F_231 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_373 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_520 = V_521 ;
return F_56 ( V_520 , V_28 ) ;
}
static int
F_267 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_520 , V_522 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_522 <= 0 )
return - 1 ;
V_520 = F_373 ( V_45 , V_28 ) ;
if ( V_522 > V_520 )
return 1 ;
return 0 ;
}
static void F_374 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_523 == V_524 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_59 = V_28 ;
}
static void F_336 ( struct V_27 * V_28 )
{
if ( F_20 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_523 == V_524 ) )
return;
F_59 (se)
F_23 ( V_28 ) -> V_58 = V_28 ;
}
static void F_375 ( struct V_27 * V_28 )
{
F_59 (se)
F_23 ( V_28 ) -> V_374 = V_28 ;
}
static void F_376 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_509 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
int V_454 = V_25 -> V_72 >= V_67 ;
int V_525 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_209 ( F_23 ( V_36 ) ) ) )
return;
if ( F_219 ( V_526 ) && V_454 && ! ( V_509 & V_527 ) ) {
F_336 ( V_36 ) ;
V_525 = 1 ;
}
if ( F_377 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_523 == V_524 ) &&
F_11 ( V_29 -> V_523 != V_524 ) )
goto V_528;
if ( F_13 ( V_29 -> V_523 != V_529 ) || ! F_219 ( V_530 ) )
return;
F_33 ( & V_28 , & V_36 ) ;
F_67 ( F_23 ( V_28 ) ) ;
F_171 ( ! V_36 ) ;
if ( F_267 ( V_28 , V_36 ) == 1 ) {
if ( ! V_525 )
F_336 ( V_36 ) ;
goto V_528;
}
return;
V_528:
F_264 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_74 || V_45 == V_24 -> V_397 ) )
return;
if ( F_219 ( V_531 ) && V_454 && F_20 ( V_28 ) )
F_374 ( V_28 ) ;
}
static struct V_26 *
F_378 ( struct V_24 * V_24 , struct V_26 * V_339 , struct V_532 V_533 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_534 ;
V_535:
#ifdef F_379
if ( ! V_25 -> V_72 )
goto V_397;
if ( V_339 -> V_89 != & V_90 )
goto V_536;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_74 )
F_67 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_269 ( V_25 ) ) )
goto V_536;
}
V_28 = F_266 ( V_25 , V_45 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_339 != V_29 ) {
struct V_27 * V_36 = & V_339 -> V_28 ;
while ( ! ( V_25 = F_31 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_268 ( F_23 ( V_36 ) , V_36 ) ;
V_36 = F_32 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_265 ( F_23 ( V_28 ) , V_28 ) ;
V_28 = F_32 ( V_28 ) ;
}
}
F_268 ( V_25 , V_36 ) ;
F_265 ( V_25 , V_28 ) ;
}
if ( F_333 ( V_24 ) )
F_329 ( V_24 , V_29 ) ;
return V_29 ;
V_536:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_397;
F_380 ( V_24 , V_339 ) ;
do {
V_28 = F_266 ( V_25 , NULL ) ;
F_265 ( V_25 , V_28 ) ;
V_25 = F_24 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_333 ( V_24 ) )
F_329 ( V_24 , V_29 ) ;
return V_29 ;
V_397:
F_381 ( & V_24 -> V_246 , V_533 ) ;
V_534 = F_235 ( V_24 ) ;
F_382 ( & V_24 -> V_246 , V_533 ) ;
if ( V_534 < 0 )
return V_537 ;
if ( V_534 > 0 )
goto V_535;
return NULL ;
}
static void F_383 ( struct V_24 * V_24 , struct V_26 * V_339 )
{
struct V_27 * V_28 = & V_339 -> V_28 ;
struct V_25 * V_25 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_268 ( V_25 , V_28 ) ;
}
}
static void F_384 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_22 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_72 == 1 ) )
return;
F_260 ( V_25 , V_28 ) ;
if ( V_45 -> V_523 != V_538 ) {
F_300 ( V_24 ) ;
F_67 ( V_25 ) ;
F_385 ( V_24 , true ) ;
}
F_375 ( V_28 ) ;
}
static bool F_386 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_528 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_74 || F_209 ( F_23 ( V_28 ) ) )
return false ;
F_336 ( V_28 ) ;
F_384 ( V_24 ) ;
return true ;
}
static int F_387 ( struct V_26 * V_29 , struct V_539 * V_172 )
{
T_3 V_42 ;
F_322 ( & V_172 -> V_190 -> V_246 ) ;
if ( V_29 -> V_89 != & V_90 )
return 0 ;
if ( F_13 ( V_29 -> V_523 == V_524 ) )
return 0 ;
if ( F_219 ( V_540 ) && V_172 -> V_192 -> V_72 &&
( & V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_23 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_541 == - 1 )
return 1 ;
if ( V_541 == 0 )
return 0 ;
V_42 = F_68 ( V_172 -> V_190 ) - V_29 -> V_28 . V_92 ;
return V_42 < ( T_3 ) V_541 ;
}
static int F_388 ( struct V_26 * V_29 , struct V_539 * V_172 )
{
struct V_126 * V_126 = F_137 ( V_29 -> V_126 ) ;
unsigned long V_542 , V_543 ;
int V_156 , V_158 ;
if ( ! F_181 ( & V_275 ) )
return - 1 ;
if ( ! V_29 -> V_134 || ! ( V_172 -> V_202 -> V_102 & V_544 ) )
return - 1 ;
V_156 = F_107 ( V_172 -> V_191 ) ;
V_158 = F_107 ( V_172 -> V_157 ) ;
if ( V_156 == V_158 )
return - 1 ;
if ( V_156 == V_29 -> V_124 ) {
if ( V_172 -> V_190 -> V_72 > V_172 -> V_190 -> V_125 )
return 1 ;
else
return - 1 ;
}
if ( V_158 == V_29 -> V_124 )
return 0 ;
if ( V_126 ) {
V_542 = F_98 ( V_29 , V_156 ) ;
V_543 = F_98 ( V_29 , V_158 ) ;
} else {
V_542 = F_97 ( V_29 , V_156 ) ;
V_543 = F_97 ( V_29 , V_158 ) ;
}
return V_543 < V_542 ;
}
static inline int F_388 ( struct V_26 * V_29 ,
struct V_539 * V_172 )
{
return - 1 ;
}
static
int F_389 ( struct V_26 * V_29 , struct V_539 * V_172 )
{
int V_545 ;
F_322 ( & V_172 -> V_190 -> V_246 ) ;
if ( F_292 ( V_314 ( V_29 ) , V_172 -> V_191 , V_172 -> V_157 ) )
return 0 ;
if ( ! F_128 ( V_172 -> V_157 , F_129 ( V_29 ) ) ) {
int V_166 ;
F_245 ( V_29 , V_28 . V_93 . V_546 ) ;
V_172 -> V_102 |= V_547 ;
if ( ! V_172 -> V_548 || ( V_172 -> V_102 & V_549 ) )
return 0 ;
F_361 (cpu, env->dst_grpmask, env->cpus) {
if ( F_128 ( V_166 , F_129 ( V_29 ) ) ) {
V_172 -> V_102 |= V_549 ;
V_172 -> V_550 = V_166 ;
break;
}
}
return 0 ;
}
V_172 -> V_102 &= ~ V_551 ;
if ( F_390 ( V_172 -> V_190 , V_29 ) ) {
F_245 ( V_29 , V_28 . V_93 . V_552 ) ;
return 0 ;
}
V_545 = F_388 ( V_29 , V_172 ) ;
if ( V_545 == - 1 )
V_545 = F_387 ( V_29 , V_172 ) ;
if ( V_545 <= 0 ||
V_172 -> V_202 -> V_553 > V_172 -> V_202 -> V_554 ) {
if ( V_545 == 1 ) {
F_245 ( V_172 -> V_202 , V_555 [ V_172 -> V_397 ] ) ;
F_245 ( V_29 , V_28 . V_93 . V_556 ) ;
}
return 1 ;
}
F_245 ( V_29 , V_28 . V_93 . V_557 ) ;
return 0 ;
}
static void F_391 ( struct V_26 * V_29 , struct V_539 * V_172 )
{
F_322 ( & V_172 -> V_190 -> V_246 ) ;
V_29 -> V_74 = V_558 ;
F_392 ( V_172 -> V_190 , V_29 , 0 ) ;
F_393 ( V_29 , V_172 -> V_157 ) ;
}
static struct V_26 * F_394 ( struct V_539 * V_172 )
{
struct V_26 * V_29 , * V_320 ;
F_322 ( & V_172 -> V_190 -> V_246 ) ;
F_395 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_389 ( V_29 , V_172 ) )
continue;
F_391 ( V_29 , V_172 ) ;
F_245 ( V_172 -> V_202 , V_559 [ V_172 -> V_397 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_396 ( struct V_539 * V_172 )
{
struct V_560 * V_561 = & V_172 -> V_190 -> V_313 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_562 = 0 ;
F_322 ( & V_172 -> V_190 -> V_246 ) ;
if ( V_172 -> V_491 <= 0 )
return 0 ;
while ( ! F_298 ( V_561 ) ) {
if ( V_172 -> V_397 != V_563 && V_172 -> V_190 -> V_72 <= 1 )
break;
V_29 = F_397 ( V_561 , struct V_26 , V_28 . V_312 ) ;
V_172 -> V_564 ++ ;
if ( V_172 -> V_564 > V_172 -> V_565 )
break;
if ( V_172 -> V_564 > V_172 -> V_566 ) {
V_172 -> V_566 += V_567 ;
V_172 -> V_102 |= V_568 ;
break;
}
if ( ! F_389 ( V_29 , V_172 ) )
goto V_58;
V_70 = F_130 ( V_29 ) ;
if ( F_219 ( V_569 ) && V_70 < 16 && ! V_172 -> V_202 -> V_553 )
goto V_58;
if ( ( V_70 / 2 ) > V_172 -> V_491 )
goto V_58;
F_391 ( V_29 , V_172 ) ;
F_202 ( & V_29 -> V_28 . V_312 , & V_172 -> V_561 ) ;
V_562 ++ ;
V_172 -> V_491 -= V_70 ;
#ifdef F_398
if ( V_172 -> V_397 == V_570 )
break;
#endif
if ( V_172 -> V_491 <= 0 )
break;
continue;
V_58:
F_399 ( & V_29 -> V_28 . V_312 , V_561 ) ;
}
F_71 ( V_172 -> V_202 , V_559 [ V_172 -> V_397 ] , V_562 ) ;
return V_562 ;
}
static void F_400 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_322 ( & V_24 -> V_246 ) ;
F_171 ( F_34 ( V_29 ) != V_24 ) ;
F_401 ( V_24 , V_29 , 0 ) ;
V_29 -> V_74 = V_571 ;
F_402 ( V_24 , V_29 , 0 ) ;
}
static void F_403 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_286 ( & V_24 -> V_246 ) ;
F_400 ( V_24 , V_29 ) ;
F_288 ( & V_24 -> V_246 ) ;
}
static void F_404 ( struct V_539 * V_172 )
{
struct V_560 * V_561 = & V_172 -> V_561 ;
struct V_26 * V_29 ;
F_286 ( & V_172 -> V_192 -> V_246 ) ;
while ( ! F_298 ( V_561 ) ) {
V_29 = F_397 ( V_561 , struct V_26 , V_28 . V_312 ) ;
F_204 ( & V_29 -> V_28 . V_312 ) ;
F_400 ( V_172 -> V_192 , V_29 ) ;
}
F_288 ( & V_172 -> V_192 -> V_246 ) ;
}
static void F_405 ( int V_166 )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
struct V_25 * V_25 ;
unsigned long V_102 ;
F_406 ( & V_24 -> V_246 , V_102 ) ;
F_300 ( V_24 ) ;
F_327 (rq, cfs_rq) {
if ( F_209 ( V_25 ) )
continue;
if ( F_64 ( F_63 ( V_25 ) , V_25 , true ) )
F_66 ( V_25 , 0 ) ;
}
F_407 ( & V_24 -> V_246 , V_102 ) ;
}
static void F_408 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_26 ( V_24 ) ] ;
unsigned long V_87 = V_213 ;
unsigned long V_70 ;
if ( V_25 -> V_572 == V_87 )
return;
V_25 -> V_573 = NULL ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
V_25 -> V_573 = V_28 ;
if ( V_25 -> V_572 == V_87 )
break;
}
if ( ! V_28 ) {
V_25 -> V_574 = F_233 ( V_25 ) ;
V_25 -> V_572 = V_87 ;
}
while ( ( V_28 = V_25 -> V_573 ) != NULL ) {
V_70 = V_25 -> V_574 ;
V_70 = F_409 ( V_70 * V_28 -> V_77 . V_80 ,
F_233 ( V_25 ) + 1 ) ;
V_25 = F_24 ( V_28 ) ;
V_25 -> V_574 = V_70 ;
V_25 -> V_572 = V_87 ;
}
}
static unsigned long F_130 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_22 ( V_29 ) ;
F_408 ( V_25 ) ;
return F_409 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_574 ,
F_233 ( V_25 ) + 1 ) ;
}
static inline void F_405 ( int V_166 )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_102 ;
F_406 ( & V_24 -> V_246 , V_102 ) ;
F_300 ( V_24 ) ;
F_64 ( F_63 ( V_25 ) , V_25 , true ) ;
F_407 ( & V_24 -> V_246 , V_102 ) ;
}
static unsigned long F_130 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_410 ( struct V_575 * V_576 )
{
* V_576 = (struct V_575 ) {
. V_577 = NULL ,
. V_222 = NULL ,
. V_578 = 0UL ,
. V_579 = 0UL ,
. V_580 = {
. V_493 = 0UL ,
. V_581 = 0 ,
. V_582 = V_583 ,
} ,
} ;
}
static inline int F_411 ( struct V_201 * V_202 ,
enum V_584 V_397 )
{
int V_489 ;
switch ( V_397 ) {
case V_563 :
V_489 = V_202 -> V_585 ;
break;
case V_570 :
V_489 = V_202 -> V_586 ;
break;
default:
V_489 = V_202 -> V_587 ;
break;
}
return V_489 ;
}
static unsigned long F_412 ( int V_166 )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
T_2 V_461 , V_588 , V_589 , V_77 ;
T_3 V_42 ;
V_589 = F_89 ( V_24 -> V_589 ) ;
V_77 = F_89 ( V_24 -> V_590 ) ;
V_42 = F_413 ( V_24 ) - V_589 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_461 = F_414 () + V_42 ;
V_588 = F_216 ( V_77 , V_461 ) ;
if ( F_11 ( V_588 < V_86 ) )
return V_86 - V_588 ;
return 1 ;
}
static void F_415 ( struct V_201 * V_202 , int V_166 )
{
unsigned long V_167 = F_214 ( V_202 , V_166 ) ;
struct V_483 * V_591 = V_202 -> V_486 ;
F_115 ( V_166 ) -> V_346 = V_167 ;
V_167 *= F_412 ( V_166 ) ;
V_167 >>= V_592 ;
if ( ! V_167 )
V_167 = 1 ;
F_115 ( V_166 ) -> V_463 = V_167 ;
V_591 -> V_495 -> V_167 = V_167 ;
}
void F_416 ( struct V_201 * V_202 , int V_166 )
{
struct V_201 * V_517 = V_202 -> V_517 ;
struct V_483 * V_137 , * V_591 = V_202 -> V_486 ;
unsigned long V_167 ;
unsigned long V_210 ;
V_210 = F_145 ( V_202 -> V_593 ) ;
V_210 = F_148 ( V_210 , 1UL , V_594 ) ;
V_591 -> V_495 -> V_595 = V_213 + V_210 ;
if ( ! V_517 ) {
F_415 ( V_202 , V_166 ) ;
return;
}
V_167 = 0 ;
if ( V_517 -> V_102 & V_596 ) {
F_114 (cpu, sched_group_cpus(sdg)) {
struct V_597 * V_495 ;
struct V_24 * V_24 = F_115 ( V_166 ) ;
if ( F_13 ( ! V_24 -> V_202 ) ) {
V_167 += F_117 ( V_166 ) ;
continue;
}
V_495 = V_24 -> V_202 -> V_486 -> V_495 ;
V_167 += V_495 -> V_167 ;
}
} else {
V_137 = V_517 -> V_486 ;
do {
V_167 += V_137 -> V_495 -> V_167 ;
V_137 = V_137 -> V_58 ;
} while ( V_137 != V_517 -> V_486 );
}
V_591 -> V_495 -> V_167 = V_167 ;
}
static inline int
F_417 ( struct V_24 * V_24 , struct V_201 * V_202 )
{
return ( ( V_24 -> V_463 * V_202 -> V_187 ) <
( V_24 -> V_346 * 100 ) ) ;
}
static inline int F_418 ( struct V_483 * V_137 )
{
return V_137 -> V_495 -> V_491 ;
}
static inline bool
F_419 ( struct V_539 * V_172 , struct V_598 * V_599 )
{
if ( V_599 -> V_581 < V_599 -> F_105 )
return true ;
if ( ( V_599 -> V_600 * 100 ) >
( V_599 -> V_601 * V_172 -> V_202 -> V_187 ) )
return true ;
return false ;
}
static inline bool
F_420 ( struct V_539 * V_172 , struct V_598 * V_599 )
{
if ( V_599 -> V_581 <= V_599 -> F_105 )
return false ;
if ( ( V_599 -> V_600 * 100 ) <
( V_599 -> V_601 * V_172 -> V_202 -> V_187 ) )
return true ;
return false ;
}
static inline enum
V_582 F_421 ( struct V_483 * V_137 ,
struct V_598 * V_599 )
{
if ( V_599 -> V_602 )
return V_603 ;
if ( F_418 ( V_137 ) )
return V_604 ;
return V_583 ;
}
static inline void F_422 ( struct V_539 * V_172 ,
struct V_483 * V_137 , int V_489 ,
int V_494 , struct V_598 * V_599 ,
bool * V_605 )
{
unsigned long V_70 ;
int V_261 , V_72 ;
memset ( V_599 , 0 , sizeof( * V_599 ) ) ;
F_361 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_115 ( V_261 ) ;
if ( V_494 )
V_70 = F_349 ( V_261 , V_489 ) ;
else
V_70 = F_348 ( V_261 , V_489 ) ;
V_599 -> V_606 += V_70 ;
V_599 -> V_601 += F_367 ( V_261 ) ;
V_599 -> V_581 += V_24 -> V_40 . V_408 ;
V_72 = V_24 -> V_72 ;
if ( V_72 > 1 )
* V_605 = true ;
#ifdef F_423
V_599 -> V_123 += V_24 -> V_123 ;
V_599 -> V_125 += V_24 -> V_125 ;
#endif
V_599 -> V_607 += F_116 ( V_261 ) ;
if ( ! V_72 && F_362 ( V_261 ) )
V_599 -> V_608 ++ ;
}
V_599 -> V_600 = V_137 -> V_495 -> V_167 ;
V_599 -> V_493 = ( V_599 -> V_606 * V_86 ) / V_599 -> V_600 ;
if ( V_599 -> V_581 )
V_599 -> V_609 = V_599 -> V_607 / V_599 -> V_581 ;
V_599 -> F_105 = V_137 -> F_105 ;
V_599 -> V_602 = F_420 ( V_172 , V_599 ) ;
V_599 -> V_582 = F_421 ( V_137 , V_599 ) ;
}
static bool F_424 ( struct V_539 * V_172 ,
struct V_575 * V_576 ,
struct V_483 * V_505 ,
struct V_598 * V_599 )
{
struct V_598 * V_577 = & V_576 -> V_580 ;
if ( V_599 -> V_582 > V_577 -> V_582 )
return true ;
if ( V_599 -> V_582 < V_577 -> V_582 )
return false ;
if ( V_599 -> V_493 <= V_577 -> V_493 )
return false ;
if ( ! ( V_172 -> V_202 -> V_102 & V_610 ) )
return true ;
if ( V_172 -> V_397 == V_563 )
return true ;
if ( V_599 -> V_581 && V_172 -> V_157 < F_425 ( V_505 ) ) {
if ( ! V_576 -> V_577 )
return true ;
if ( F_425 ( V_576 -> V_577 ) < F_425 ( V_505 ) )
return true ;
}
return false ;
}
static inline enum V_611 F_426 ( struct V_598 * V_599 )
{
if ( V_599 -> V_581 > V_599 -> V_123 )
return V_612 ;
if ( V_599 -> V_581 > V_599 -> V_125 )
return V_220 ;
return V_613 ;
}
static inline enum V_611 F_427 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_123 )
return V_612 ;
if ( V_24 -> V_72 > V_24 -> V_125 )
return V_220 ;
return V_613 ;
}
static inline enum V_611 F_426 ( struct V_598 * V_599 )
{
return V_613 ;
}
static inline enum V_611 F_427 ( struct V_24 * V_24 )
{
return V_612 ;
}
static inline void F_428 ( struct V_539 * V_172 , struct V_575 * V_576 )
{
struct V_201 * V_517 = V_172 -> V_202 -> V_517 ;
struct V_483 * V_505 = V_172 -> V_202 -> V_486 ;
struct V_598 V_614 ;
int V_489 , V_615 = 0 ;
bool V_605 = false ;
if ( V_517 && V_517 -> V_102 & V_616 )
V_615 = 1 ;
V_489 = F_411 ( V_172 -> V_202 , V_172 -> V_397 ) ;
do {
struct V_598 * V_599 = & V_614 ;
int V_494 ;
V_494 = F_128 ( V_172 -> V_157 , F_359 ( V_505 ) ) ;
if ( V_494 ) {
V_576 -> V_222 = V_505 ;
V_599 = & V_576 -> V_617 ;
if ( V_172 -> V_397 != V_570 ||
F_429 ( V_213 , V_505 -> V_495 -> V_595 ) )
F_416 ( V_172 -> V_202 , V_172 -> V_157 ) ;
}
F_422 ( V_172 , V_505 , V_489 , V_494 , V_599 ,
& V_605 ) ;
if ( V_494 )
goto V_618;
if ( V_615 && V_576 -> V_222 &&
F_419 ( V_172 , & V_576 -> V_617 ) &&
( V_599 -> V_581 > 1 ) ) {
V_599 -> V_602 = 1 ;
V_599 -> V_582 = F_421 ( V_505 , V_599 ) ;
}
if ( F_424 ( V_172 , V_576 , V_505 , V_599 ) ) {
V_576 -> V_577 = V_505 ;
V_576 -> V_580 = * V_599 ;
}
V_618:
V_576 -> V_578 += V_599 -> V_606 ;
V_576 -> V_579 += V_599 -> V_600 ;
V_505 = V_505 -> V_58 ;
} while ( V_505 != V_172 -> V_202 -> V_486 );
if ( V_172 -> V_202 -> V_102 & V_544 )
V_172 -> V_611 = F_426 ( & V_576 -> V_580 ) ;
if ( ! V_172 -> V_202 -> V_34 ) {
if ( V_172 -> V_192 -> V_619 -> V_605 != V_605 )
V_172 -> V_192 -> V_619 -> V_605 = V_605 ;
}
}
static int F_430 ( struct V_539 * V_172 , struct V_575 * V_576 )
{
int V_620 ;
if ( ! ( V_172 -> V_202 -> V_102 & V_610 ) )
return 0 ;
if ( V_172 -> V_397 == V_563 )
return 0 ;
if ( ! V_576 -> V_577 )
return 0 ;
V_620 = F_425 ( V_576 -> V_577 ) ;
if ( V_172 -> V_157 > V_620 )
return 0 ;
V_172 -> V_491 = F_118 (
V_576 -> V_580 . V_493 * V_576 -> V_580 . V_600 ,
V_86 ) ;
return 1 ;
}
static inline
void F_431 ( struct V_539 * V_172 , struct V_575 * V_576 )
{
unsigned long V_510 , V_621 = 0 , V_622 = 0 ;
unsigned int V_623 = 2 ;
unsigned long V_624 ;
struct V_598 * V_222 , * V_577 ;
V_222 = & V_576 -> V_617 ;
V_577 = & V_576 -> V_580 ;
if ( ! V_222 -> V_581 )
V_222 -> V_609 = F_351 ( V_172 -> V_157 ) ;
else if ( V_577 -> V_609 > V_222 -> V_609 )
V_623 = 1 ;
V_624 =
( V_577 -> V_609 * V_86 ) /
V_577 -> V_600 ;
if ( V_577 -> V_493 + V_624 >=
V_222 -> V_493 + ( V_624 * V_623 ) ) {
V_172 -> V_491 = V_577 -> V_609 ;
return;
}
V_621 += V_577 -> V_600 *
F_144 ( V_577 -> V_609 , V_577 -> V_493 ) ;
V_621 += V_222 -> V_600 *
F_144 ( V_222 -> V_609 , V_222 -> V_493 ) ;
V_621 /= V_86 ;
if ( V_577 -> V_493 > V_624 ) {
V_622 += V_577 -> V_600 *
F_144 ( V_577 -> V_609 ,
V_577 -> V_493 - V_624 ) ;
}
if ( V_577 -> V_493 * V_577 -> V_600 <
V_577 -> V_609 * V_86 ) {
V_510 = ( V_577 -> V_493 * V_577 -> V_600 ) /
V_222 -> V_600 ;
} else {
V_510 = ( V_577 -> V_609 * V_86 ) /
V_222 -> V_600 ;
}
V_622 += V_222 -> V_600 *
F_144 ( V_222 -> V_609 , V_222 -> V_493 + V_510 ) ;
V_622 /= V_86 ;
if ( V_622 > V_621 )
V_172 -> V_491 = V_577 -> V_609 ;
}
static inline void F_432 ( struct V_539 * V_172 , struct V_575 * V_576 )
{
unsigned long V_625 , V_626 = ~ 0UL ;
struct V_598 * V_222 , * V_577 ;
V_222 = & V_576 -> V_617 ;
V_577 = & V_576 -> V_580 ;
if ( V_577 -> V_582 == V_604 ) {
V_577 -> V_609 =
F_144 ( V_577 -> V_609 , V_576 -> V_493 ) ;
}
if ( V_577 -> V_493 <= V_576 -> V_493 ||
V_222 -> V_493 >= V_576 -> V_493 ) {
V_172 -> V_491 = 0 ;
return F_431 ( V_172 , V_576 ) ;
}
if ( V_577 -> V_582 == V_603 &&
V_222 -> V_582 == V_603 ) {
V_626 = V_577 -> V_581 * V_86 ;
if ( V_626 > V_577 -> V_600 ) {
V_626 -= V_577 -> V_600 ;
V_626 *= V_71 ;
V_626 /= V_577 -> V_600 ;
} else
V_626 = ~ 0UL ;
}
V_625 = F_144 ( V_577 -> V_493 - V_576 -> V_493 , V_626 ) ;
V_172 -> V_491 = F_144 (
V_625 * V_577 -> V_600 ,
( V_576 -> V_493 - V_222 -> V_493 ) * V_222 -> V_600
) / V_86 ;
if ( V_172 -> V_491 < V_577 -> V_609 )
return F_431 ( V_172 , V_576 ) ;
}
static struct V_483 * F_433 ( struct V_539 * V_172 )
{
struct V_598 * V_222 , * V_577 ;
struct V_575 V_576 ;
F_410 ( & V_576 ) ;
F_428 ( V_172 , & V_576 ) ;
V_222 = & V_576 . V_617 ;
V_577 = & V_576 . V_580 ;
if ( F_430 ( V_172 , & V_576 ) )
return V_576 . V_577 ;
if ( ! V_576 . V_577 || V_577 -> V_581 == 0 )
goto V_627;
V_576 . V_493 = ( V_86 * V_576 . V_578 )
/ V_576 . V_579 ;
if ( V_577 -> V_582 == V_604 )
goto V_628;
if ( V_172 -> V_397 == V_570 && F_419 ( V_172 , V_222 ) &&
V_577 -> V_602 )
goto V_628;
if ( V_222 -> V_493 >= V_577 -> V_493 )
goto V_627;
if ( V_222 -> V_493 >= V_576 . V_493 )
goto V_627;
if ( V_172 -> V_397 == V_629 ) {
if ( ( V_577 -> V_582 != V_603 ) &&
( V_222 -> V_608 <= ( V_577 -> V_608 + 1 ) ) )
goto V_627;
} else {
if ( 100 * V_577 -> V_493 <=
V_172 -> V_202 -> V_187 * V_222 -> V_493 )
goto V_627;
}
V_628:
F_432 ( V_172 , & V_576 ) ;
return V_576 . V_577 ;
V_627:
V_172 -> V_491 = 0 ;
return NULL ;
}
static struct V_24 * F_434 ( struct V_539 * V_172 ,
struct V_483 * V_137 )
{
struct V_24 * V_577 = NULL , * V_24 ;
unsigned long V_630 = 0 , V_631 = 1 ;
int V_261 ;
F_361 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_167 , V_464 ;
enum V_611 V_632 ;
V_24 = F_115 ( V_261 ) ;
V_632 = F_427 ( V_24 ) ;
if ( V_632 > V_172 -> V_611 )
continue;
V_167 = F_117 ( V_261 ) ;
V_464 = F_116 ( V_261 ) ;
if ( V_24 -> V_72 == 1 && V_464 > V_172 -> V_491 &&
! F_417 ( V_24 , V_172 -> V_202 ) )
continue;
if ( V_464 * V_631 > V_630 * V_167 ) {
V_630 = V_464 ;
V_631 = V_167 ;
V_577 = V_24 ;
}
}
return V_577 ;
}
static int F_435 ( struct V_539 * V_172 )
{
struct V_201 * V_202 = V_172 -> V_202 ;
if ( V_172 -> V_397 == V_570 ) {
if ( ( V_202 -> V_102 & V_610 ) && V_172 -> V_191 > V_172 -> V_157 )
return 1 ;
}
if ( ( V_172 -> V_397 != V_563 ) &&
( V_172 -> V_190 -> V_40 . V_408 == 1 ) ) {
if ( ( F_417 ( V_172 -> V_190 , V_202 ) ) &&
( F_117 ( V_172 -> V_191 ) * V_202 -> V_187 < F_117 ( V_172 -> V_157 ) * 100 ) )
return 1 ;
}
return F_13 ( V_202 -> V_553 > V_202 -> V_554 + 2 ) ;
}
static int F_436 ( struct V_539 * V_172 )
{
struct V_483 * V_505 = V_172 -> V_202 -> V_486 ;
struct V_633 * V_634 , * V_635 ;
int V_166 , V_636 = - 1 ;
if ( V_172 -> V_397 == V_570 )
return 1 ;
V_634 = F_359 ( V_505 ) ;
V_635 = F_437 ( V_505 ) ;
F_361 (cpu, sg_cpus, env->cpus) {
if ( ! F_128 ( V_166 , V_635 ) || ! F_362 ( V_166 ) )
continue;
V_636 = V_166 ;
break;
}
if ( V_636 == - 1 )
V_636 = F_438 ( V_505 ) ;
return V_636 == V_172 -> V_157 ;
}
static int F_439 ( int V_476 , struct V_24 * V_449 ,
struct V_201 * V_202 , enum V_584 V_397 ,
int * V_637 )
{
int V_638 , V_639 , V_640 = 0 ;
struct V_201 * V_641 = V_202 -> V_34 ;
struct V_483 * V_137 ;
struct V_24 * V_577 ;
unsigned long V_102 ;
struct V_633 * V_8 = F_440 ( V_642 ) ;
struct V_539 V_172 = {
. V_202 = V_202 ,
. V_157 = V_476 ,
. V_192 = V_449 ,
. V_548 = F_359 ( V_202 -> V_486 ) ,
. V_397 = V_397 ,
. V_566 = V_567 ,
. V_8 = V_8 ,
. V_611 = V_613 ,
. V_561 = F_441 ( V_172 . V_561 ) ,
} ;
if ( V_397 == V_570 )
V_172 . V_548 = NULL ;
F_442 ( V_8 , V_643 ) ;
F_245 ( V_202 , V_644 [ V_397 ] ) ;
V_645:
if ( ! F_436 ( & V_172 ) ) {
* V_637 = 0 ;
goto V_627;
}
V_137 = F_433 ( & V_172 ) ;
if ( ! V_137 ) {
F_245 ( V_202 , V_646 [ V_397 ] ) ;
goto V_627;
}
V_577 = F_434 ( & V_172 , V_137 ) ;
if ( ! V_577 ) {
F_245 ( V_202 , V_647 [ V_397 ] ) ;
goto V_627;
}
F_171 ( V_577 == V_172 . V_192 ) ;
F_71 ( V_202 , V_648 [ V_397 ] , V_172 . V_491 ) ;
V_172 . V_191 = V_577 -> V_166 ;
V_172 . V_190 = V_577 ;
V_638 = 0 ;
if ( V_577 -> V_72 > 1 ) {
V_172 . V_102 |= V_551 ;
V_172 . V_565 = F_144 ( V_649 , V_577 -> V_72 ) ;
V_650:
F_406 ( & V_577 -> V_246 , V_102 ) ;
V_639 = F_396 ( & V_172 ) ;
F_288 ( & V_577 -> V_246 ) ;
if ( V_639 ) {
F_404 ( & V_172 ) ;
V_638 += V_639 ;
}
F_443 ( V_102 ) ;
if ( V_172 . V_102 & V_568 ) {
V_172 . V_102 &= ~ V_568 ;
goto V_650;
}
if ( ( V_172 . V_102 & V_549 ) && V_172 . V_491 > 0 ) {
F_444 ( V_172 . V_157 , V_172 . V_8 ) ;
V_172 . V_192 = F_115 ( V_172 . V_550 ) ;
V_172 . V_157 = V_172 . V_550 ;
V_172 . V_102 &= ~ V_549 ;
V_172 . V_564 = 0 ;
V_172 . V_566 = V_567 ;
goto V_650;
}
if ( V_641 ) {
int * V_651 = & V_641 -> V_486 -> V_495 -> V_491 ;
if ( ( V_172 . V_102 & V_547 ) && V_172 . V_491 > 0 )
* V_651 = 1 ;
}
if ( F_13 ( V_172 . V_102 & V_551 ) ) {
F_444 ( F_26 ( V_577 ) , V_8 ) ;
if ( ! F_445 ( V_8 ) ) {
V_172 . V_564 = 0 ;
V_172 . V_566 = V_567 ;
goto V_645;
}
goto V_652;
}
}
if ( ! V_638 ) {
F_245 ( V_202 , V_653 [ V_397 ] ) ;
if ( V_397 != V_570 )
V_202 -> V_553 ++ ;
if ( F_435 ( & V_172 ) ) {
F_406 ( & V_577 -> V_246 , V_102 ) ;
if ( ! F_128 ( V_476 ,
F_129 ( V_577 -> V_45 ) ) ) {
F_407 ( & V_577 -> V_246 ,
V_102 ) ;
V_172 . V_102 |= V_551 ;
goto V_654;
}
if ( ! V_577 -> V_640 ) {
V_577 -> V_640 = 1 ;
V_577 -> V_655 = V_476 ;
V_640 = 1 ;
}
F_407 ( & V_577 -> V_246 , V_102 ) ;
if ( V_640 ) {
F_446 ( F_26 ( V_577 ) ,
V_656 , V_577 ,
& V_577 -> V_657 ) ;
}
V_202 -> V_553 = V_202 -> V_554 + 1 ;
}
} else
V_202 -> V_553 = 0 ;
if ( F_11 ( ! V_640 ) ) {
V_202 -> V_593 = V_202 -> V_658 ;
} else {
if ( V_202 -> V_593 < V_202 -> V_659 )
V_202 -> V_593 *= 2 ;
}
goto V_310;
V_627:
if ( V_641 ) {
int * V_651 = & V_641 -> V_486 -> V_495 -> V_491 ;
if ( * V_651 )
* V_651 = 0 ;
}
V_652:
F_245 ( V_202 , V_660 [ V_397 ] ) ;
V_202 -> V_553 = 0 ;
V_654:
if ( ( ( V_172 . V_102 & V_551 ) &&
V_202 -> V_593 < V_661 ) ||
( V_202 -> V_593 < V_202 -> V_659 ) )
V_202 -> V_593 *= 2 ;
V_638 = 0 ;
V_310:
return V_638 ;
}
static inline unsigned long
F_447 ( struct V_201 * V_202 , int V_662 )
{
unsigned long V_210 = V_202 -> V_593 ;
if ( V_662 )
V_210 *= V_202 -> V_663 ;
V_210 = F_145 ( V_210 ) ;
V_210 = F_148 ( V_210 , 1UL , V_594 ) ;
return V_210 ;
}
static inline void
F_448 ( struct V_201 * V_202 , int V_662 , unsigned long * V_664 )
{
unsigned long V_210 , V_58 ;
V_210 = F_447 ( V_202 , V_662 ) ;
V_58 = V_202 -> V_665 + V_210 ;
if ( F_182 ( * V_664 , V_58 ) )
* V_664 = V_58 ;
}
static int F_235 ( struct V_24 * V_449 )
{
unsigned long V_664 = V_213 + V_211 ;
int V_476 = V_449 -> V_166 ;
struct V_201 * V_202 ;
int V_666 = 0 ;
T_2 V_667 = 0 ;
V_449 -> V_503 = F_78 ( V_449 ) ;
if ( V_449 -> V_668 < V_541 ||
! V_449 -> V_619 -> V_605 ) {
F_125 () ;
V_202 = F_449 ( V_449 -> V_202 ) ;
if ( V_202 )
F_448 ( V_202 , 0 , & V_664 ) ;
F_132 () ;
goto V_310;
}
F_288 ( & V_449 -> V_246 ) ;
F_405 ( V_476 ) ;
F_125 () ;
F_369 (this_cpu, sd) {
int V_637 = 1 ;
T_2 V_669 , V_670 ;
if ( ! ( V_202 -> V_102 & V_515 ) )
continue;
if ( V_449 -> V_668 < V_667 + V_202 -> V_671 ) {
F_448 ( V_202 , 0 , & V_664 ) ;
break;
}
if ( V_202 -> V_102 & V_672 ) {
V_669 = F_282 ( V_476 ) ;
V_666 = F_439 ( V_476 , V_449 ,
V_202 , V_570 ,
& V_637 ) ;
V_670 = F_282 ( V_476 ) - V_669 ;
if ( V_670 > V_202 -> V_671 )
V_202 -> V_671 = V_670 ;
V_667 += V_670 ;
}
F_448 ( V_202 , 0 , & V_664 ) ;
if ( V_666 || V_449 -> V_72 > 0 )
break;
}
F_132 () ;
F_286 ( & V_449 -> V_246 ) ;
if ( V_667 > V_449 -> V_673 )
V_449 -> V_673 = V_667 ;
if ( V_449 -> V_40 . V_408 && ! V_666 )
V_666 = 1 ;
V_310:
if ( F_182 ( V_449 -> V_664 , V_664 ) )
V_449 -> V_664 = V_664 ;
if ( V_449 -> V_72 != V_449 -> V_40 . V_408 )
V_666 = - 1 ;
if ( V_666 )
V_449 -> V_503 = 0 ;
return V_666 ;
}
static int V_656 ( void * V_403 )
{
struct V_24 * V_674 = V_403 ;
int V_620 = F_26 ( V_674 ) ;
int V_675 = V_674 -> V_655 ;
struct V_24 * V_676 = F_115 ( V_675 ) ;
struct V_201 * V_202 ;
struct V_26 * V_29 = NULL ;
F_450 ( & V_674 -> V_246 ) ;
if ( F_13 ( V_620 != F_222 () ||
! V_674 -> V_640 ) )
goto V_677;
if ( V_674 -> V_72 <= 1 )
goto V_677;
F_171 ( V_674 == V_676 ) ;
F_125 () ;
F_369 (target_cpu, sd) {
if ( ( V_202 -> V_102 & V_515 ) &&
F_128 ( V_620 , F_370 ( V_202 ) ) )
break;
}
if ( F_11 ( V_202 ) ) {
struct V_539 V_172 = {
. V_202 = V_202 ,
. V_157 = V_675 ,
. V_192 = V_676 ,
. V_191 = V_674 -> V_166 ,
. V_190 = V_674 ,
. V_397 = V_629 ,
} ;
F_245 ( V_202 , V_678 ) ;
V_29 = F_394 ( & V_172 ) ;
if ( V_29 ) {
F_245 ( V_202 , V_679 ) ;
V_202 -> V_553 = 0 ;
} else {
F_245 ( V_202 , V_680 ) ;
}
}
F_132 () ;
V_677:
V_674 -> V_640 = 0 ;
F_288 ( & V_674 -> V_246 ) ;
if ( V_29 )
F_403 ( V_676 , V_29 ) ;
F_451 () ;
return 0 ;
}
static inline int F_452 ( struct V_24 * V_24 )
{
return F_13 ( ! F_453 ( V_24 -> V_202 ) ) ;
}
static inline int F_454 ( void )
{
int V_681 = F_455 ( V_682 . V_683 ) ;
if ( V_681 < V_684 && F_362 ( V_681 ) )
return V_681 ;
return V_684 ;
}
static void F_456 ( void )
{
int V_685 ;
V_682 . V_664 ++ ;
V_685 = F_454 () ;
if ( V_685 >= V_684 )
return;
if ( F_457 ( V_686 , F_458 ( V_685 ) ) )
return;
F_459 ( V_685 ) ;
return;
}
void F_460 ( unsigned int V_166 )
{
if ( F_13 ( F_461 ( V_687 , F_458 ( V_166 ) ) ) ) {
if ( F_11 ( F_128 ( V_166 , V_682 . V_683 ) ) ) {
F_444 ( V_166 , V_682 . V_683 ) ;
F_462 ( & V_682 . V_688 ) ;
}
F_463 ( V_687 , F_458 ( V_166 ) ) ;
}
}
static inline void F_464 ( void )
{
struct V_201 * V_202 ;
int V_166 = F_222 () ;
F_125 () ;
V_202 = F_137 ( F_138 ( V_689 , V_166 ) ) ;
if ( ! V_202 || ! V_202 -> V_690 )
goto V_196;
V_202 -> V_690 = 0 ;
F_465 ( & V_202 -> V_486 -> V_495 -> V_691 ) ;
V_196:
F_132 () ;
}
void F_466 ( void )
{
struct V_201 * V_202 ;
int V_166 = F_222 () ;
F_125 () ;
V_202 = F_137 ( F_138 ( V_689 , V_166 ) ) ;
if ( ! V_202 || V_202 -> V_690 )
goto V_196;
V_202 -> V_690 = 1 ;
F_462 ( & V_202 -> V_486 -> V_495 -> V_691 ) ;
V_196:
F_132 () ;
}
void F_467 ( int V_166 )
{
if ( ! F_468 ( V_166 ) )
return;
if ( F_461 ( V_687 , F_458 ( V_166 ) ) )
return;
if ( F_452 ( F_115 ( V_166 ) ) )
return;
F_469 ( V_166 , V_682 . V_683 ) ;
F_465 ( & V_682 . V_688 ) ;
F_470 ( V_687 , F_458 ( V_166 ) ) ;
}
void F_471 ( void )
{
V_594 = V_211 * F_472 () / 10 ;
}
static void F_473 ( struct V_24 * V_24 , enum V_584 V_397 )
{
int V_637 = 1 ;
int V_166 = V_24 -> V_166 ;
unsigned long V_210 ;
struct V_201 * V_202 ;
unsigned long V_664 = V_213 + 60 * V_211 ;
int F_448 = 0 ;
int V_692 , V_693 = 0 ;
T_2 V_694 = 0 ;
F_405 ( V_166 ) ;
F_125 () ;
F_369 (cpu, sd) {
if ( F_182 ( V_213 , V_202 -> V_695 ) ) {
V_202 -> V_671 =
( V_202 -> V_671 * 253 ) / 256 ;
V_202 -> V_695 = V_213 + V_211 ;
V_693 = 1 ;
}
V_694 += V_202 -> V_671 ;
if ( ! ( V_202 -> V_102 & V_515 ) )
continue;
if ( ! V_637 ) {
if ( V_693 )
continue;
break;
}
V_210 = F_447 ( V_202 , V_397 != V_629 ) ;
V_692 = V_202 -> V_102 & V_696 ;
if ( V_692 ) {
if ( ! F_474 ( & V_697 ) )
goto V_310;
}
if ( F_429 ( V_213 , V_202 -> V_665 + V_210 ) ) {
if ( F_439 ( V_166 , V_24 , V_202 , V_397 , & V_637 ) ) {
V_397 = F_362 ( V_166 ) ? V_629 : V_563 ;
}
V_202 -> V_665 = V_213 ;
V_210 = F_447 ( V_202 , V_397 != V_629 ) ;
}
if ( V_692 )
F_174 ( & V_697 ) ;
V_310:
if ( F_182 ( V_664 , V_202 -> V_665 + V_210 ) ) {
V_664 = V_202 -> V_665 + V_210 ;
F_448 = 1 ;
}
}
if ( V_693 ) {
V_24 -> V_673 =
F_70 ( ( T_2 ) V_541 , V_694 ) ;
}
F_132 () ;
if ( F_11 ( F_448 ) ) {
V_24 -> V_664 = V_664 ;
#ifdef F_339
if ( ( V_397 == V_629 ) && F_182 ( V_682 . V_664 , V_24 -> V_664 ) )
V_682 . V_664 = V_24 -> V_664 ;
#endif
}
}
static void F_475 ( struct V_24 * V_449 , enum V_584 V_397 )
{
int V_476 = V_449 -> V_166 ;
struct V_24 * V_24 ;
int V_636 ;
unsigned long V_664 = V_213 + 60 * V_211 ;
int F_448 = 0 ;
if ( V_397 != V_629 ||
! F_461 ( V_686 , F_458 ( V_476 ) ) )
goto V_290;
F_114 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_636 == V_476 || ! F_362 ( V_636 ) )
continue;
if ( F_476 () )
break;
V_24 = F_115 ( V_636 ) ;
if ( F_429 ( V_213 , V_24 -> V_664 ) ) {
F_450 ( & V_24 -> V_246 ) ;
F_300 ( V_24 ) ;
F_342 ( V_24 ) ;
F_477 ( & V_24 -> V_246 ) ;
F_473 ( V_24 , V_629 ) ;
}
if ( F_182 ( V_664 , V_24 -> V_664 ) ) {
V_664 = V_24 -> V_664 ;
F_448 = 1 ;
}
}
if ( F_11 ( F_448 ) )
V_682 . V_664 = V_664 ;
V_290:
F_463 ( V_686 , F_458 ( V_476 ) ) ;
}
static inline bool F_478 ( struct V_24 * V_24 )
{
unsigned long V_87 = V_213 ;
struct V_201 * V_202 ;
struct V_597 * V_495 ;
int V_698 , V_166 = V_24 -> V_166 ;
bool V_699 = false ;
if ( F_13 ( V_24 -> F_235 ) )
return false ;
F_464 () ;
F_460 ( V_166 ) ;
if ( F_11 ( ! F_479 ( & V_682 . V_688 ) ) )
return false ;
if ( F_186 ( V_87 , V_682 . V_664 ) )
return false ;
if ( V_24 -> V_72 >= 2 )
return true ;
F_125 () ;
V_202 = F_137 ( F_138 ( V_689 , V_166 ) ) ;
if ( V_202 ) {
V_495 = V_202 -> V_486 -> V_495 ;
V_698 = F_479 ( & V_495 -> V_691 ) ;
if ( V_698 > 1 ) {
V_699 = true ;
goto V_196;
}
}
V_202 = F_137 ( V_24 -> V_202 ) ;
if ( V_202 ) {
if ( ( V_24 -> V_40 . V_408 >= 1 ) &&
F_417 ( V_24 , V_202 ) ) {
V_699 = true ;
goto V_196;
}
}
V_202 = F_137 ( F_138 ( V_700 , V_166 ) ) ;
if ( V_202 && ( F_366 ( V_682 . V_683 ,
F_370 ( V_202 ) ) < V_166 ) ) {
V_699 = true ;
goto V_196;
}
V_196:
F_132 () ;
return V_699 ;
}
static void F_475 ( struct V_24 * V_449 , enum V_584 V_397 ) { }
static void F_480 ( struct V_701 * V_702 )
{
struct V_24 * V_449 = V_449 () ;
enum V_584 V_397 = V_449 -> F_235 ?
V_629 : V_563 ;
F_475 ( V_449 , V_397 ) ;
F_473 ( V_449 , V_397 ) ;
}
void F_481 ( struct V_24 * V_24 )
{
if ( F_13 ( F_452 ( V_24 ) ) )
return;
if ( F_429 ( V_213 , V_24 -> V_664 ) )
F_482 ( V_703 ) ;
#ifdef F_339
if ( F_478 ( V_24 ) )
F_456 () ;
#endif
}
static void F_483 ( struct V_24 * V_24 )
{
F_7 () ;
F_326 ( V_24 ) ;
}
static void F_484 ( struct V_24 * V_24 )
{
F_7 () ;
F_328 ( V_24 ) ;
}
static void F_485 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_379 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_59 (se) {
V_25 = F_23 ( V_28 ) ;
F_270 ( V_25 , V_28 , V_379 ) ;
}
if ( F_486 ( & V_275 ) )
F_197 ( V_24 , V_45 ) ;
}
static void F_487 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
struct V_24 * V_24 = V_449 () ;
F_286 ( & V_24 -> V_246 ) ;
F_300 ( V_24 ) ;
V_25 = F_22 ( V_161 ) ;
V_45 = V_25 -> V_45 ;
if ( V_45 ) {
F_67 ( V_25 ) ;
V_28 -> V_41 = V_45 -> V_41 ;
}
F_246 ( V_25 , V_28 , 1 ) ;
if ( V_704 && V_45 && F_37 ( V_45 , V_28 ) ) {
F_123 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_264 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_36 ;
F_288 ( & V_24 -> V_246 ) ;
}
static void
F_488 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_705 )
{
if ( ! F_489 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_706 > V_705 )
F_264 ( V_24 ) ;
} else
F_402 ( V_24 , V_29 , 0 ) ;
}
static inline bool F_490 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_74 )
return true ;
if ( ! V_28 -> V_95 || V_29 -> V_105 == V_519 )
return true ;
return false ;
}
static void F_491 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_87 = F_63 ( V_25 ) ;
int V_88 ;
if ( ! F_490 ( V_29 ) ) {
F_246 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_36 ;
}
V_88 = F_64 ( V_87 , V_25 , false ) ;
F_227 ( V_25 , V_28 ) ;
if ( V_88 )
F_66 ( V_25 , false ) ;
}
static void F_492 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_28 ) ;
T_2 V_87 = F_63 ( V_25 ) ;
int V_88 ;
#ifdef F_379
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
V_88 = F_64 ( V_87 , V_25 , false ) ;
F_65 ( V_25 , V_28 ) ;
if ( V_88 )
F_66 ( V_25 , false ) ;
if ( ! F_490 ( V_29 ) )
V_28 -> V_41 += V_25 -> F_36 ;
}
static void F_493 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_491 ( V_29 ) ;
}
static void F_494 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_492 ( V_29 ) ;
if ( F_489 ( V_29 ) ) {
if ( V_24 -> V_45 == V_29 )
F_264 ( V_24 ) ;
else
F_402 ( V_24 , V_29 , 0 ) ;
}
}
static void F_495 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_59 (se) {
struct V_25 * V_25 = F_23 ( V_28 ) ;
F_265 ( V_25 , V_28 ) ;
F_75 ( V_25 , 0 ) ;
}
}
void F_496 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_707 ;
V_25 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_25 -> V_48 = V_25 -> F_36 ;
#endif
#ifdef F_201
F_497 ( & V_25 -> V_350 , 0 ) ;
F_497 ( & V_25 -> V_352 , 0 ) ;
#endif
}
static void F_498 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
F_499 ( V_29 , F_136 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
}
static void F_500 ( struct V_26 * V_29 )
{
F_491 ( V_29 ) ;
F_499 ( V_29 , F_136 ( V_29 ) ) ;
#ifdef F_201
V_29 -> V_28 . V_77 . V_78 = 0 ;
#endif
F_492 ( V_29 ) ;
}
static void F_501 ( struct V_26 * V_29 , int type )
{
switch ( type ) {
case V_708 :
F_498 ( V_29 ) ;
break;
case V_709 :
F_500 ( V_29 ) ;
break;
}
}
void F_502 ( struct V_314 * V_33 )
{
int V_261 ;
F_324 ( F_284 ( V_33 ) ) ;
F_503 (i) {
if ( V_33 -> V_25 )
F_179 ( V_33 -> V_25 [ V_261 ] ) ;
if ( V_33 -> V_28 )
F_179 ( V_33 -> V_28 [ V_261 ] ) ;
}
F_179 ( V_33 -> V_25 ) ;
F_179 ( V_33 -> V_28 ) ;
}
int F_504 ( struct V_314 * V_33 , struct V_314 * V_34 )
{
struct V_27 * V_28 ;
struct V_25 * V_25 ;
struct V_24 * V_24 ;
int V_261 ;
V_33 -> V_25 = F_167 ( sizeof( V_25 ) * V_684 , V_263 ) ;
if ( ! V_33 -> V_25 )
goto V_710;
V_33 -> V_28 = F_167 ( sizeof( V_28 ) * V_684 , V_263 ) ;
if ( ! V_33 -> V_28 )
goto V_710;
V_33 -> V_316 = V_71 ;
F_317 ( F_284 ( V_33 ) ) ;
F_503 (i) {
V_24 = F_115 ( V_261 ) ;
V_25 = F_505 ( sizeof( struct V_25 ) ,
V_263 , F_107 ( V_261 ) ) ;
if ( ! V_25 )
goto V_710;
V_28 = F_505 ( sizeof( struct V_27 ) ,
V_263 , F_107 ( V_261 ) ) ;
if ( ! V_28 )
goto V_711;
F_496 ( V_25 ) ;
F_506 ( V_33 , V_25 , V_28 , V_261 , V_34 -> V_28 [ V_261 ] ) ;
F_61 ( V_28 ) ;
}
return 1 ;
V_711:
F_179 ( V_25 ) ;
V_710:
return 0 ;
}
void F_507 ( struct V_314 * V_33 )
{
struct V_27 * V_28 ;
struct V_24 * V_24 ;
int V_261 ;
F_503 (i) {
V_24 = F_115 ( V_261 ) ;
V_28 = V_33 -> V_28 [ V_261 ] ;
F_450 ( & V_24 -> V_246 ) ;
F_62 ( V_28 ) ;
F_313 ( V_33 , V_261 ) ;
F_477 ( & V_24 -> V_246 ) ;
}
}
void F_508 ( struct V_314 * V_33 )
{
unsigned long V_102 ;
struct V_24 * V_24 ;
int V_166 ;
F_503 (cpu) {
if ( V_33 -> V_28 [ V_166 ] )
F_231 ( V_33 -> V_28 [ V_166 ] ) ;
if ( ! V_33 -> V_25 [ V_166 ] -> V_32 )
continue;
V_24 = F_115 ( V_166 ) ;
F_406 ( & V_24 -> V_246 , V_102 ) ;
F_29 ( V_33 -> V_25 [ V_166 ] ) ;
F_407 ( & V_24 -> V_246 , V_102 ) ;
}
}
void F_506 ( struct V_314 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_166 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_115 ( V_166 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_321 ( V_25 ) ;
V_33 -> V_25 [ V_166 ] = V_25 ;
V_33 -> V_28 [ V_166 ] = V_28 ;
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
int F_509 ( struct V_314 * V_33 , unsigned long V_316 )
{
int V_261 ;
unsigned long V_102 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_206 ;
V_316 = F_148 ( V_316 , F_510 ( V_318 ) , F_510 ( V_712 ) ) ;
F_511 ( & V_713 ) ;
if ( V_33 -> V_316 == V_316 )
goto V_507;
V_33 -> V_316 = V_316 ;
F_503 (i) {
struct V_24 * V_24 = F_115 ( V_261 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_261 ] ;
F_406 ( & V_24 -> V_246 , V_102 ) ;
F_300 ( V_24 ) ;
F_59 (se)
F_208 ( F_24 ( V_28 ) ) ;
F_407 ( & V_24 -> V_246 , V_102 ) ;
}
V_507:
F_512 ( & V_713 ) ;
return 0 ;
}
void F_502 ( struct V_314 * V_33 ) { }
int F_504 ( struct V_314 * V_33 , struct V_314 * V_34 )
{
return 1 ;
}
void F_507 ( struct V_314 * V_33 ) { }
void F_508 ( struct V_314 * V_33 ) { }
static unsigned int F_513 ( struct V_24 * V_24 , struct V_26 * V_143 )
{
struct V_27 * V_28 = & V_143 -> V_28 ;
unsigned int V_714 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_714 = F_514 ( F_58 ( F_23 ( V_28 ) , V_28 ) ) ;
return V_714 ;
}
void F_515 ( struct V_715 * V_716 , int V_166 )
{
struct V_25 * V_25 ;
F_125 () ;
F_327 (cpu_rq(cpu), cfs_rq)
F_516 ( V_716 , V_166 , V_25 ) ;
F_132 () ;
}
void F_517 ( struct V_26 * V_29 , struct V_715 * V_716 )
{
int V_145 ;
unsigned long V_717 = 0 , V_718 = 0 , V_719 = 0 , V_720 = 0 ;
F_102 (node) {
if ( V_29 -> V_134 ) {
V_717 = V_29 -> V_134 [ F_96 ( V_135 , V_145 , 0 ) ] ;
V_718 = V_29 -> V_134 [ F_96 ( V_135 , V_145 , 1 ) ] ;
}
if ( V_29 -> V_126 ) {
V_719 = V_29 -> V_126 -> V_136 [ F_96 ( V_135 , V_145 , 0 ) ] ,
V_720 = V_29 -> V_126 -> V_136 [ F_96 ( V_135 , V_145 , 1 ) ] ;
}
F_518 ( V_716 , V_145 , V_717 , V_718 , V_719 , V_720 ) ;
}
}
T_12 void F_519 ( void )
{
#ifdef F_201
F_520 ( V_703 , F_480 ) ;
#ifdef F_339
V_682 . V_664 = V_213 ;
F_521 ( & V_682 . V_683 , V_721 ) ;
#endif
#endif
}
