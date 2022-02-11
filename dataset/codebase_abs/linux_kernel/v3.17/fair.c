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
static inline void
F_74 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_83 . V_88 , F_75 ( F_17 ( V_25 ) ) ) ;
}
static void F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_74 ( V_25 , V_28 ) ;
}
static void
F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_83 . V_89 , F_68 ( V_28 -> V_83 . V_89 ,
F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ) ;
F_67 ( V_28 -> V_83 . V_90 , V_28 -> V_83 . V_90 + 1 ) ;
F_67 ( V_28 -> V_83 . V_91 , V_28 -> V_83 . V_91 +
F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
#ifdef F_78
if ( F_21 ( V_28 ) ) {
F_79 ( F_18 ( V_28 ) ,
F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
}
#endif
F_67 ( V_28 -> V_83 . V_88 , 0 ) ;
}
static inline void
F_80 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_77 ( V_25 , V_28 ) ;
}
static inline void
F_81 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_82 = F_66 ( F_17 ( V_25 ) ) ;
}
static unsigned int F_82 ( struct V_26 * V_29 )
{
unsigned long V_92 = 0 ;
unsigned long V_93 ;
V_93 = V_94 << ( 20 - V_95 ) ;
V_92 = F_83 ( V_29 -> V_96 ) ;
if ( ! V_92 )
V_92 = V_93 ;
V_92 = F_84 ( V_92 , V_93 ) ;
return V_92 / V_93 ;
}
static unsigned int F_85 ( struct V_26 * V_29 )
{
unsigned int V_97 , floor ;
unsigned int V_98 = 1 ;
if ( V_94 < V_99 )
V_98 = V_99 / V_94 ;
floor = 1000 / V_98 ;
V_97 = V_100 / F_82 ( V_29 ) ;
return F_86 (unsigned int, floor, scan) ;
}
static unsigned int F_87 ( struct V_26 * V_29 )
{
unsigned int V_101 = F_85 ( V_29 ) ;
unsigned int V_102 ;
V_102 = V_103 / F_82 ( V_29 ) ;
return F_68 ( V_101 , V_102 ) ;
}
static void F_88 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 += ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 += ( V_29 -> V_105 == F_89 ( V_29 ) ) ;
}
static void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 -= ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 -= ( V_29 -> V_105 == F_89 ( V_29 ) ) ;
}
T_7 F_91 ( struct V_26 * V_29 )
{
return V_29 -> V_107 ? V_29 -> V_107 -> V_108 : 0 ;
}
static inline int F_92 ( int V_109 , int V_110 )
{
return V_111 * V_109 + V_110 ;
}
static inline unsigned long F_93 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_112 )
return 0 ;
return V_29 -> V_112 [ F_92 ( V_109 , 0 ) ] +
V_29 -> V_112 [ F_92 ( V_109 , 1 ) ] ;
}
static inline unsigned long F_94 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_107 )
return 0 ;
return V_29 -> V_107 -> V_113 [ F_92 ( V_109 , 0 ) ] +
V_29 -> V_107 -> V_113 [ F_92 ( V_109 , 1 ) ] ;
}
static inline unsigned long F_95 ( struct V_107 * V_114 , int V_109 )
{
return V_114 -> V_115 [ F_92 ( V_109 , 0 ) ] +
V_114 -> V_115 [ F_92 ( V_109 , 1 ) ] ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_109 )
{
unsigned long V_116 ;
if ( ! V_29 -> V_112 )
return 0 ;
V_116 = V_29 -> V_117 ;
if ( ! V_116 )
return 0 ;
return 1000 * F_93 ( V_29 , V_109 ) / V_116 ;
}
static inline unsigned long F_97 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_107 || ! V_29 -> V_107 -> V_116 )
return 0 ;
return 1000 * F_94 ( V_29 , V_109 ) / V_29 -> V_107 -> V_116 ;
}
bool F_98 ( struct V_26 * V_29 , struct V_118 * V_118 ,
int V_119 , int V_120 )
{
struct V_107 * V_121 = V_29 -> V_107 ;
int V_122 = F_99 ( V_120 ) ;
int V_123 , V_124 ;
V_124 = F_100 ( V_120 , V_125 -> V_126 ) ;
V_123 = F_101 ( V_118 , V_124 ) ;
if ( ! F_102 ( V_123 ) &&
F_103 ( V_123 ) != V_122 )
return false ;
if ( F_104 ( V_29 , V_123 ) )
return true ;
if ( ! V_121 )
return true ;
if ( ! F_105 ( V_122 , V_121 -> V_127 ) )
return false ;
if ( ! F_105 ( V_119 , V_121 -> V_127 ) )
return true ;
return F_94 ( V_29 , V_122 ) < ( F_94 ( V_29 , V_119 ) * 3 / 4 ) ;
}
static void F_106 ( struct V_128 * V_129 , int V_109 )
{
int V_130 , V_8 = 0 ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
F_107 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_108 ( V_130 ) ;
V_129 -> V_72 += V_24 -> V_72 ;
V_129 -> V_70 += F_109 ( V_130 ) ;
V_129 -> V_131 += F_110 ( V_130 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_129 -> V_132 =
F_111 ( V_129 -> V_131 , V_133 ) ;
V_129 -> V_134 = ( V_129 -> V_72 < V_129 -> V_132 ) ;
}
static void F_112 ( struct V_135 * V_136 ,
struct V_26 * V_29 , long V_137 )
{
if ( V_136 -> V_138 )
F_113 ( V_136 -> V_138 ) ;
if ( V_29 )
F_114 ( V_29 ) ;
V_136 -> V_138 = V_29 ;
V_136 -> V_139 = V_137 ;
V_136 -> V_140 = V_136 -> V_120 ;
}
static bool F_115 ( long V_141 , long V_142 ,
struct V_135 * V_136 )
{
long V_143 , V_144 ;
long V_145 , V_146 ;
long V_147 , V_148 ;
V_147 = V_136 -> V_149 . V_131 ;
V_148 = V_136 -> V_150 . V_131 ;
if ( V_142 < V_141 )
F_116 ( V_142 , V_141 ) ;
V_143 = V_142 * V_147 * 100 -
V_141 * V_148 * V_136 -> V_151 ;
if ( V_143 <= 0 )
return false ;
V_145 = V_136 -> V_149 . V_70 ;
V_146 = V_136 -> V_150 . V_70 ;
if ( V_146 < V_145 )
F_116 ( V_146 , V_145 ) ;
V_144 = V_146 * V_147 * 100 -
V_145 * V_148 * V_136 -> V_151 ;
return ( V_143 > V_144 ) ;
}
static void F_117 ( struct V_135 * V_136 ,
long V_152 , long V_153 )
{
struct V_24 * V_154 = F_108 ( V_136 -> V_155 ) ;
struct V_24 * V_156 = F_108 ( V_136 -> V_120 ) ;
struct V_26 * V_157 ;
long V_141 , V_142 ;
long V_70 ;
long V_137 = V_136 -> V_29 -> V_107 ? V_153 : V_152 ;
long V_158 = V_137 ;
F_118 () ;
V_157 = F_119 ( V_156 -> V_45 ) ;
if ( V_157 -> V_126 == 0 )
V_157 = NULL ;
if ( V_157 ) {
if ( ! F_120 ( V_136 -> V_155 , F_121 ( V_157 ) ) )
goto V_159;
if ( V_157 -> V_107 == V_136 -> V_29 -> V_107 ) {
V_137 = V_152 + F_96 ( V_157 , V_136 -> V_119 ) -
F_96 ( V_157 , V_136 -> V_122 ) ;
if ( V_157 -> V_107 )
V_137 -= V_137 / 16 ;
} else {
if ( V_157 -> V_107 )
V_137 += F_97 ( V_157 , V_136 -> V_119 ) -
F_97 ( V_157 , V_136 -> V_122 ) ;
else
V_137 += F_96 ( V_157 , V_136 -> V_119 ) -
F_96 ( V_157 , V_136 -> V_122 ) ;
}
}
if ( V_137 <= V_136 -> V_139 && V_158 <= V_136 -> V_139 )
goto V_159;
if ( ! V_157 ) {
if ( V_136 -> V_149 . V_134 &&
! V_136 -> V_150 . V_134 )
goto V_159;
goto V_160;
}
if ( V_137 > V_136 -> V_139 && V_154 -> V_72 == 1 &&
V_156 -> V_72 == 1 )
goto V_161;
V_160:
V_70 = F_122 ( V_136 -> V_29 ) ;
V_142 = V_136 -> V_150 . V_70 + V_70 ;
V_141 = V_136 -> V_149 . V_70 - V_70 ;
if ( V_158 > V_137 && V_158 > V_136 -> V_139 ) {
if ( ! F_115 ( V_141 , V_142 , V_136 ) ) {
V_137 = V_158 - 1 ;
V_157 = NULL ;
goto V_161;
}
}
if ( V_137 <= V_136 -> V_139 )
goto V_159;
if ( V_157 ) {
V_70 = F_122 ( V_157 ) ;
V_142 -= V_70 ;
V_141 += V_70 ;
}
if ( F_115 ( V_141 , V_142 , V_136 ) )
goto V_159;
V_161:
F_112 ( V_136 , V_157 , V_137 ) ;
V_159:
F_123 () ;
}
static void F_124 ( struct V_135 * V_136 ,
long V_152 , long V_153 )
{
int V_130 ;
F_107 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_120 ( V_130 , F_121 ( V_136 -> V_29 ) ) )
continue;
V_136 -> V_120 = V_130 ;
F_117 ( V_136 , V_152 , V_153 ) ;
}
}
static int F_125 ( struct V_26 * V_29 )
{
struct V_135 V_136 = {
. V_29 = V_29 ,
. V_155 = F_126 ( V_29 ) ,
. V_119 = F_89 ( V_29 ) ,
. V_151 = 112 ,
. V_138 = NULL ,
. V_139 = 0 ,
. V_140 = - 1
} ;
struct V_162 * V_163 ;
unsigned long V_164 , V_165 ;
int V_109 , V_66 ;
long V_152 , V_153 ;
F_118 () ;
V_163 = F_127 ( F_128 ( V_166 , V_136 . V_155 ) ) ;
if ( V_163 )
V_136 . V_151 = 100 + ( V_163 -> V_151 - 100 ) / 2 ;
F_123 () ;
if ( F_14 ( ! V_163 ) ) {
V_29 -> V_105 = F_89 ( V_29 ) ;
return - V_167 ;
}
V_164 = F_96 ( V_29 , V_136 . V_119 ) ;
V_165 = F_97 ( V_29 , V_136 . V_119 ) ;
F_106 ( & V_136 . V_149 , V_136 . V_119 ) ;
V_136 . V_122 = V_29 -> V_105 ;
V_152 = F_96 ( V_29 , V_136 . V_122 ) - V_164 ;
V_153 = F_97 ( V_29 , V_136 . V_122 ) - V_165 ;
F_106 ( & V_136 . V_150 , V_136 . V_122 ) ;
F_124 ( & V_136 , V_152 , V_153 ) ;
if ( V_136 . V_140 == - 1 ) {
F_129 (nid) {
if ( V_109 == V_136 . V_119 || V_109 == V_29 -> V_105 )
continue;
V_152 = F_96 ( V_29 , V_109 ) - V_164 ;
V_153 = F_97 ( V_29 , V_109 ) - V_165 ;
if ( V_152 < 0 && V_153 < 0 )
continue;
V_136 . V_122 = V_109 ;
F_106 ( & V_136 . V_150 , V_136 . V_122 ) ;
F_124 ( & V_136 , V_152 , V_153 ) ;
}
}
if ( V_29 -> V_107 ) {
if ( V_136 . V_140 == - 1 )
V_109 = V_136 . V_119 ;
else
V_109 = V_136 . V_122 ;
if ( F_105 ( V_109 , V_29 -> V_107 -> V_127 ) )
F_130 ( V_29 , V_136 . V_122 ) ;
}
if ( V_136 . V_140 == - 1 )
return - V_168 ;
V_29 -> V_169 = F_85 ( V_29 ) ;
if ( V_136 . V_138 == NULL ) {
V_66 = F_131 ( V_29 , V_136 . V_140 ) ;
if ( V_66 != 0 )
F_132 ( V_29 , V_136 . V_155 , V_136 . V_140 ) ;
return V_66 ;
}
V_66 = F_133 ( V_29 , V_136 . V_138 ) ;
if ( V_66 != 0 )
F_132 ( V_29 , V_136 . V_155 , F_126 ( V_136 . V_138 ) ) ;
F_113 ( V_136 . V_138 ) ;
return V_66 ;
}
static void F_134 ( struct V_26 * V_29 )
{
unsigned long V_170 = V_171 ;
if ( F_14 ( V_29 -> V_105 == - 1 || ! V_29 -> V_112 ) )
return;
V_170 = F_135 ( V_170 , F_136 ( V_29 -> V_169 ) / 16 ) ;
V_29 -> V_172 = V_173 + V_170 ;
if ( F_89 ( V_29 ) == V_29 -> V_105 )
return;
F_125 ( V_29 ) ;
}
static void F_137 ( struct V_107 * V_107 )
{
unsigned long V_113 , V_174 = 0 ;
int V_109 ;
F_129 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( V_113 > V_174 )
V_174 = V_113 ;
}
F_129 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( ! F_105 ( V_109 , V_107 -> V_127 ) ) {
if ( V_113 > V_174 * 6 / 16 )
F_138 ( V_109 , V_107 -> V_127 ) ;
} else if ( V_113 < V_174 * 3 / 16 )
F_139 ( V_109 , V_107 -> V_127 ) ;
}
}
static void F_140 ( struct V_26 * V_29 ,
unsigned long V_175 , unsigned long V_176 )
{
unsigned int V_177 ;
int V_178 ;
int V_179 ;
unsigned long V_180 = V_29 -> V_181 [ 0 ] ;
unsigned long V_182 = V_29 -> V_181 [ 1 ] ;
if ( V_182 + V_175 == 0 ) {
V_29 -> V_169 = F_135 ( V_29 -> V_183 ,
V_29 -> V_169 << 1 ) ;
V_29 -> V_96 -> V_184 = V_173 +
F_136 ( V_29 -> V_169 ) ;
return;
}
V_177 = F_56 ( V_29 -> V_169 , V_185 ) ;
V_178 = ( V_182 * V_185 ) / ( V_182 + V_180 ) ;
if ( V_178 >= V_186 ) {
int V_187 = V_178 - V_186 ;
if ( ! V_187 )
V_187 = 1 ;
V_179 = V_187 * V_177 ;
} else {
V_179 = - ( V_186 - V_178 ) * V_177 ;
V_178 = F_56 ( V_176 * V_185 , ( V_176 + V_175 ) ) ;
V_179 = ( V_179 * V_178 ) / V_185 ;
}
V_29 -> V_169 = F_141 ( V_29 -> V_169 + V_179 ,
F_85 ( V_29 ) , F_87 ( V_29 ) ) ;
memset ( V_29 -> V_181 , 0 , sizeof( V_29 -> V_181 ) ) ;
}
static T_2 F_142 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_188 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_188 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_189 ) {
V_42 = V_188 - V_29 -> V_190 ;
* V_73 = V_81 - V_29 -> V_189 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_79 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_190 = V_188 ;
V_29 -> V_189 = V_81 ;
return V_42 ;
}
static void F_143 ( struct V_26 * V_29 )
{
int V_191 , V_109 , V_192 = - 1 , V_193 = - 1 ;
unsigned long V_174 = 0 , V_194 = 0 ;
unsigned long V_195 [ 2 ] = { 0 , 0 } ;
unsigned long V_116 ;
T_2 V_188 , V_73 ;
T_8 * V_196 = NULL ;
V_191 = F_119 ( V_29 -> V_96 -> V_197 ) ;
if ( V_29 -> V_197 == V_191 )
return;
V_29 -> V_197 = V_191 ;
V_29 -> V_183 = F_87 ( V_29 ) ;
V_116 = V_29 -> V_181 [ 0 ] +
V_29 -> V_181 [ 1 ] ;
V_188 = F_142 ( V_29 , & V_73 ) ;
if ( V_29 -> V_107 ) {
V_196 = & V_29 -> V_107 -> V_198 ;
F_144 ( V_196 ) ;
}
F_129 (nid) {
unsigned long V_113 = 0 , F_94 = 0 ;
int V_110 , V_199 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
long V_179 , V_200 , V_201 ;
V_199 = F_92 ( V_109 , V_110 ) ;
V_179 = V_29 -> V_202 [ V_199 ] - V_29 -> V_112 [ V_199 ] / 2 ;
V_195 [ V_110 ] += V_29 -> V_202 [ V_199 ] ;
V_29 -> V_202 [ V_199 ] = 0 ;
V_201 = F_145 ( V_188 << 16 , V_73 + 1 ) ;
V_201 = ( V_201 * V_29 -> V_203 [ V_199 ] ) /
( V_116 + 1 ) ;
V_200 = V_201 - V_29 -> V_204 [ V_199 ] / 2 ;
V_29 -> V_203 [ V_199 ] = 0 ;
V_29 -> V_112 [ V_199 ] += V_179 ;
V_29 -> V_204 [ V_199 ] += V_200 ;
V_113 += V_29 -> V_112 [ V_199 ] ;
V_29 -> V_117 += V_179 ;
if ( V_29 -> V_107 ) {
V_29 -> V_107 -> V_113 [ V_199 ] += V_179 ;
V_29 -> V_107 -> V_115 [ V_199 ] += V_200 ;
V_29 -> V_107 -> V_116 += V_179 ;
F_94 += V_29 -> V_107 -> V_113 [ V_199 ] ;
}
}
if ( V_113 > V_174 ) {
V_174 = V_113 ;
V_192 = V_109 ;
}
if ( F_94 > V_194 ) {
V_194 = F_94 ;
V_193 = V_109 ;
}
}
F_140 ( V_29 , V_195 [ 0 ] , V_195 [ 1 ] ) ;
if ( V_29 -> V_107 ) {
F_137 ( V_29 -> V_107 ) ;
F_146 ( V_196 ) ;
V_192 = V_193 ;
}
if ( V_174 ) {
if ( V_192 != V_29 -> V_105 )
F_130 ( V_29 , V_192 ) ;
if ( F_89 ( V_29 ) != V_29 -> V_105 )
F_134 ( V_29 ) ;
}
}
static inline int F_147 ( struct V_107 * V_30 )
{
return F_148 ( & V_30 -> V_205 ) ;
}
static inline void F_149 ( struct V_107 * V_30 )
{
if ( F_150 ( & V_30 -> V_205 ) )
F_151 ( V_30 , V_206 ) ;
}
static void F_152 ( struct V_26 * V_29 , int V_207 , int V_208 ,
int * V_110 )
{
struct V_107 * V_30 , * V_209 ;
struct V_26 * V_210 ;
bool V_211 = false ;
int V_130 = F_153 ( V_207 ) ;
int V_199 ;
if ( F_14 ( ! V_29 -> V_107 ) ) {
unsigned int V_212 = sizeof( struct V_107 ) +
4 * V_213 *sizeof( unsigned long ) ;
V_30 = F_154 ( V_212 , V_214 | V_215 ) ;
if ( ! V_30 )
return;
F_155 ( & V_30 -> V_205 , 1 ) ;
F_156 ( & V_30 -> V_198 ) ;
F_157 ( & V_30 -> V_216 ) ;
V_30 -> V_108 = V_29 -> V_126 ;
V_30 -> V_115 = V_30 -> V_113 + V_111 *
V_213 ;
F_138 ( F_89 ( V_125 ) , V_30 -> V_127 ) ;
for ( V_199 = 0 ; V_199 < V_217 * V_213 ; V_199 ++ )
V_30 -> V_113 [ V_199 ] = V_29 -> V_112 [ V_199 ] ;
V_30 -> V_116 = V_29 -> V_117 ;
F_158 ( & V_29 -> V_218 , & V_30 -> V_216 ) ;
V_30 -> V_219 ++ ;
F_159 ( V_29 -> V_107 , V_30 ) ;
}
F_118 () ;
V_210 = F_119 ( F_108 ( V_130 ) -> V_45 ) ;
if ( ! F_104 ( V_210 , V_207 ) )
goto V_220;
V_30 = F_127 ( V_210 -> V_107 ) ;
if ( ! V_30 )
goto V_220;
V_209 = V_29 -> V_107 ;
if ( V_30 == V_209 )
goto V_220;
if ( V_209 -> V_219 > V_30 -> V_219 )
goto V_220;
if ( V_209 -> V_219 == V_30 -> V_219 && V_209 > V_30 )
goto V_220;
if ( V_210 -> V_96 == V_125 -> V_96 )
V_211 = true ;
if ( V_208 & V_221 )
V_211 = true ;
* V_110 = ! V_211 ;
if ( V_211 && ! F_147 ( V_30 ) )
goto V_220;
F_123 () ;
if ( ! V_211 )
return;
F_160 ( F_161 () ) ;
F_162 ( & V_209 -> V_198 , & V_30 -> V_198 ) ;
for ( V_199 = 0 ; V_199 < V_217 * V_213 ; V_199 ++ ) {
V_209 -> V_113 [ V_199 ] -= V_29 -> V_112 [ V_199 ] ;
V_30 -> V_113 [ V_199 ] += V_29 -> V_112 [ V_199 ] ;
}
V_209 -> V_116 -= V_29 -> V_117 ;
V_30 -> V_116 += V_29 -> V_117 ;
F_163 ( & V_29 -> V_218 , & V_30 -> V_216 ) ;
V_209 -> V_219 -- ;
V_30 -> V_219 ++ ;
F_164 ( & V_209 -> V_198 ) ;
F_146 ( & V_30 -> V_198 ) ;
F_159 ( V_29 -> V_107 , V_30 ) ;
F_149 ( V_209 ) ;
return;
V_220:
F_123 () ;
return;
}
void F_165 ( struct V_26 * V_29 )
{
struct V_107 * V_30 = V_29 -> V_107 ;
void * V_222 = V_29 -> V_112 ;
unsigned long V_208 ;
int V_199 ;
if ( V_30 ) {
F_166 ( & V_30 -> V_198 , V_208 ) ;
for ( V_199 = 0 ; V_199 < V_217 * V_213 ; V_199 ++ )
V_30 -> V_113 [ V_199 ] -= V_29 -> V_112 [ V_199 ] ;
V_30 -> V_116 -= V_29 -> V_117 ;
F_167 ( & V_29 -> V_218 ) ;
V_30 -> V_219 -- ;
F_168 ( & V_30 -> V_198 , V_208 ) ;
F_159 ( V_29 -> V_107 , NULL ) ;
F_149 ( V_30 ) ;
}
V_29 -> V_112 = NULL ;
V_29 -> V_202 = NULL ;
V_29 -> V_204 = NULL ;
V_29 -> V_203 = NULL ;
F_169 ( V_222 ) ;
}
void F_170 ( int V_123 , int V_223 , int V_224 , int V_208 )
{
struct V_26 * V_29 = V_125 ;
bool V_225 = V_208 & V_226 ;
int V_227 = F_89 ( V_125 ) ;
int V_182 = ! ! ( V_208 & V_228 ) ;
int V_110 ;
if ( ! V_229 )
return;
if ( ! V_29 -> V_96 )
return;
if ( V_29 -> V_230 == V_231 )
return;
if ( F_14 ( ! V_29 -> V_112 ) ) {
int V_212 = sizeof( * V_29 -> V_112 ) *
V_232 * V_213 ;
V_29 -> V_112 = F_154 ( V_212 , V_214 | V_215 ) ;
if ( ! V_29 -> V_112 )
return;
F_160 ( V_29 -> V_202 ) ;
V_29 -> V_204 = V_29 -> V_112 + ( 2 * V_213 ) ;
V_29 -> V_202 = V_29 -> V_112 + ( 4 * V_213 ) ;
V_29 -> V_203 = V_29 -> V_112 + ( 6 * V_213 ) ;
V_29 -> V_117 = 0 ;
memset ( V_29 -> V_181 , 0 , sizeof( V_29 -> V_181 ) ) ;
}
if ( F_14 ( V_123 == ( - 1 & V_233 ) ) ) {
V_110 = 1 ;
} else {
V_110 = F_104 ( V_29 , V_123 ) ;
if ( ! V_110 && ! ( V_208 & V_234 ) )
F_152 ( V_29 , V_123 , V_208 , & V_110 ) ;
}
if ( ! V_110 && ! V_182 && V_29 -> V_107 &&
F_105 ( V_227 , V_29 -> V_107 -> V_127 ) &&
F_105 ( V_223 , V_29 -> V_107 -> V_127 ) )
V_182 = 1 ;
F_143 ( V_29 ) ;
if ( F_171 ( V_173 , V_29 -> V_172 ) )
F_134 ( V_29 ) ;
if ( V_225 )
V_29 -> V_235 += V_224 ;
V_29 -> V_202 [ F_92 ( V_223 , V_110 ) ] += V_224 ;
V_29 -> V_203 [ F_92 ( V_227 , V_110 ) ] += V_224 ;
V_29 -> V_181 [ V_182 ] += V_224 ;
}
static void F_172 ( struct V_26 * V_29 )
{
F_119 ( V_29 -> V_96 -> V_197 ) ++ ;
V_29 -> V_96 -> V_236 = 0 ;
}
void F_173 ( struct V_237 * V_238 )
{
unsigned long V_239 , V_240 , V_81 = V_173 ;
struct V_26 * V_29 = V_125 ;
struct V_241 * V_96 = V_29 -> V_96 ;
struct V_242 * V_243 ;
unsigned long V_244 , V_245 ;
unsigned long V_246 = 0 ;
long V_224 ;
F_20 ( V_29 != F_22 ( V_238 , struct V_26 , V_247 ) ) ;
V_238 -> V_58 = V_238 ;
if ( V_29 -> V_208 & V_248 )
return;
if ( ! V_96 -> V_184 ) {
V_96 -> V_184 = V_81 +
F_136 ( V_249 ) ;
}
V_239 = V_96 -> V_184 ;
if ( F_174 ( V_81 , V_239 ) )
return;
if ( V_29 -> V_169 == 0 ) {
V_29 -> V_183 = F_87 ( V_29 ) ;
V_29 -> V_169 = F_85 ( V_29 ) ;
}
V_240 = V_81 + F_136 ( V_29 -> V_169 ) ;
if ( F_175 ( & V_96 -> V_184 , V_239 , V_240 ) != V_239 )
return;
V_29 -> V_250 += 2 * V_251 ;
V_244 = V_96 -> V_236 ;
V_224 = V_94 ;
V_224 <<= 20 - V_95 ;
if ( ! V_224 )
return;
F_176 ( & V_96 -> V_252 ) ;
V_243 = F_177 ( V_96 , V_244 ) ;
if ( ! V_243 ) {
F_172 ( V_29 ) ;
V_244 = 0 ;
V_243 = V_96 -> V_253 ;
}
for (; V_243 ; V_243 = V_243 -> V_254 ) {
if ( ! F_178 ( V_243 ) || ! F_179 ( V_29 , V_243 ) )
continue;
if ( ! V_243 -> V_255 ||
( V_243 -> V_256 && ( V_243 -> V_257 & ( V_258 | V_259 ) ) == ( V_258 ) ) )
continue;
if ( ! ( V_243 -> V_257 & ( V_258 | V_260 | V_259 ) ) )
continue;
do {
V_244 = F_68 ( V_244 , V_243 -> V_261 ) ;
V_245 = F_180 ( V_244 + ( V_224 << V_95 ) , V_262 ) ;
V_245 = F_135 ( V_245 , V_243 -> V_263 ) ;
V_246 += F_181 ( V_243 , V_244 , V_245 ) ;
if ( V_246 )
V_224 -= ( V_245 - V_244 ) >> V_95 ;
V_244 = V_245 ;
if ( V_224 <= 0 )
goto V_264;
F_182 () ;
} while ( V_245 != V_243 -> V_263 );
}
V_264:
if ( V_243 )
V_96 -> V_236 = V_244 ;
else
F_172 ( V_29 ) ;
F_183 ( & V_96 -> V_252 ) ;
}
void F_184 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_237 * V_238 = & V_45 -> V_247 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_208 & V_248 ) || V_238 -> V_58 != V_238 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_169 * V_265 ;
if ( V_81 - V_45 -> V_250 > V_73 ) {
if ( ! V_45 -> V_250 )
V_45 -> V_169 = F_85 ( V_45 ) ;
V_45 -> V_250 += V_73 ;
if ( ! F_174 ( V_173 , V_45 -> V_96 -> V_184 ) ) {
F_185 ( V_238 , F_173 ) ;
F_186 ( V_45 , V_238 , true ) ;
}
}
}
static void F_184 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_88 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_187 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_188
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_88 ( V_24 , F_18 ( V_28 ) ) ;
F_158 ( & V_28 -> V_266 , & V_24 -> V_267 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_189 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_90 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_190 ( & V_28 -> V_266 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_191 ( struct V_268 * V_33 , struct V_25 * V_25 )
{
long V_269 ;
V_269 = F_192 ( & V_33 -> V_270 ) ;
V_269 -= V_25 -> V_271 ;
V_269 += V_25 -> V_70 . V_4 ;
return V_269 ;
}
static long F_193 ( struct V_25 * V_25 , struct V_268 * V_33 )
{
long V_269 , V_70 , V_272 ;
V_269 = F_191 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_272 = ( V_33 -> V_272 * V_70 ) ;
if ( V_269 )
V_272 /= V_269 ;
if ( V_272 < V_273 )
V_272 = V_273 ;
if ( V_272 > V_33 -> V_272 )
V_272 = V_33 -> V_272 ;
return V_272 ;
}
static inline long F_193 ( struct V_25 * V_25 , struct V_268 * V_33 )
{
return V_33 -> V_272 ;
}
static void F_194 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_189 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_187 ( V_25 , V_28 ) ;
}
static void F_195 ( struct V_25 * V_25 )
{
struct V_268 * V_33 ;
struct V_27 * V_28 ;
long V_272 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_196 ( V_25 ) )
return;
#ifndef F_188
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_272 ) )
return;
#endif
V_272 = F_193 ( V_25 , V_33 ) ;
F_194 ( F_24 ( V_28 ) , V_28 , V_272 ) ;
}
static inline void F_195 ( struct V_25 * V_25 )
{
}
static T_9 T_2 F_197 ( T_2 V_274 , T_2 V_275 )
{
unsigned int V_276 ;
if ( ! V_275 )
return V_274 ;
else if ( F_14 ( V_275 > V_277 * 63 ) )
return 0 ;
V_276 = V_275 ;
if ( F_14 ( V_276 >= V_277 ) ) {
V_274 >>= V_276 / V_277 ;
V_276 %= V_277 ;
}
V_274 *= V_278 [ V_276 ] ;
return V_274 >> 32 ;
}
static V_23 F_198 ( T_2 V_275 )
{
V_23 V_279 = 0 ;
if ( F_12 ( V_275 <= V_277 ) )
return V_280 [ V_275 ] ;
else if ( F_14 ( V_275 >= V_281 ) )
return V_282 ;
do {
V_279 /= 2 ;
V_279 += V_280 [ V_277 ] ;
V_275 -= V_277 ;
} while ( V_275 > V_277 );
V_279 = F_197 ( V_279 , V_275 ) ;
return V_279 + V_280 [ V_275 ] ;
}
static T_9 int F_199 ( T_2 V_81 ,
struct V_283 * V_284 ,
int V_285 )
{
T_2 V_42 , V_286 ;
V_23 V_287 ;
int V_288 , V_289 = 0 ;
V_42 = V_81 - V_284 -> V_290 ;
if ( ( T_3 ) V_42 < 0 ) {
V_284 -> V_290 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_284 -> V_290 = V_81 ;
V_288 = V_284 -> V_80 % 1024 ;
if ( V_42 + V_288 >= 1024 ) {
V_289 = 1 ;
V_288 = 1024 - V_288 ;
if ( V_285 )
V_284 -> V_79 += V_288 ;
V_284 -> V_80 += V_288 ;
V_42 -= V_288 ;
V_286 = V_42 / 1024 ;
V_42 %= 1024 ;
V_284 -> V_79 = F_197 ( V_284 -> V_79 ,
V_286 + 1 ) ;
V_284 -> V_80 = F_197 ( V_284 -> V_80 ,
V_286 + 1 ) ;
V_287 = F_198 ( V_286 ) ;
if ( V_285 )
V_284 -> V_79 += V_287 ;
V_284 -> V_80 += V_287 ;
}
if ( V_285 )
V_284 -> V_79 += V_42 ;
V_284 -> V_80 += V_42 ;
return V_289 ;
}
static inline T_2 F_200 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_291 = F_201 ( & V_25 -> V_292 ) ;
V_291 -= V_28 -> V_77 . V_78 ;
if ( ! V_291 )
return 0 ;
V_28 -> V_77 . V_293 = F_197 ( V_28 -> V_77 . V_293 , V_291 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_291 ;
}
static inline void F_202 ( struct V_25 * V_25 ,
int V_294 )
{
struct V_268 * V_33 = V_25 -> V_33 ;
long V_295 ;
V_295 = V_25 -> V_296 + V_25 -> V_297 ;
V_295 -= V_25 -> V_271 ;
if ( V_294 || abs ( V_295 ) > V_25 -> V_271 / 8 ) {
F_203 ( V_295 , & V_33 -> V_270 ) ;
V_25 -> V_271 += V_295 ;
}
}
static inline void F_204 ( struct V_283 * V_284 ,
struct V_25 * V_25 )
{
struct V_268 * V_33 = V_25 -> V_33 ;
long V_279 ;
V_279 = F_205 ( ( T_2 ) V_284 -> V_79 << V_298 ,
V_284 -> V_80 + 1 ) ;
V_279 -= V_25 -> V_299 ;
if ( abs ( V_279 ) > V_25 -> V_299 / 64 ) {
F_206 ( V_279 , & V_33 -> V_300 ) ;
V_25 -> V_299 += V_279 ;
}
}
static inline void F_207 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_268 * V_33 = V_25 -> V_33 ;
int V_300 ;
T_2 V_279 ;
V_279 = V_25 -> V_271 * V_33 -> V_272 ;
V_28 -> V_77 . V_293 = F_205 ( V_279 ,
F_192 ( & V_33 -> V_270 ) + 1 ) ;
V_300 = F_208 ( & V_33 -> V_300 ) ;
if ( V_300 < V_71 ) {
V_28 -> V_77 . V_293 *= V_300 ;
V_28 -> V_77 . V_293 >>= V_298 ;
}
}
static inline void F_209 ( struct V_24 * V_24 , int V_285 )
{
F_199 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_285 ) ;
F_204 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_202 ( struct V_25 * V_25 ,
int V_294 ) {}
static inline void F_204 ( struct V_283 * V_284 ,
struct V_25 * V_25 ) {}
static inline void F_207 ( struct V_27 * V_28 ) {}
static inline void F_209 ( struct V_24 * V_24 , int V_285 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_279 ;
V_279 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_279 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_293 = F_210 ( V_279 ) ;
}
static long F_211 ( struct V_27 * V_28 )
{
long V_301 = V_28 -> V_77 . V_293 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_204 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_207 ( V_28 ) ;
}
return V_28 -> V_77 . V_293 - V_301 ;
}
static inline void F_212 ( struct V_25 * V_25 ,
long V_302 )
{
if ( F_12 ( V_302 < V_25 -> V_297 ) )
V_25 -> V_297 -= V_302 ;
else
V_25 -> V_297 = 0 ;
}
static inline void F_213 ( struct V_27 * V_28 ,
int V_303 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_304 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_214 ( V_25 ) ;
else
V_81 = F_214 ( F_25 ( V_28 ) ) ;
if ( ! F_199 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_304 = F_211 ( V_28 ) ;
if ( ! V_303 )
return;
if ( V_28 -> V_76 )
V_25 -> V_296 += V_304 ;
else
F_212 ( V_25 , - V_304 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_294 )
{
T_2 V_81 = F_214 ( V_25 ) >> 20 ;
T_2 V_291 ;
V_291 = V_81 - V_25 -> V_305 ;
if ( ! V_291 && ! V_294 )
return;
if ( F_192 ( & V_25 -> V_306 ) ) {
unsigned long V_306 ;
V_306 = F_215 ( & V_25 -> V_306 , 0 ) ;
F_212 ( V_25 , V_306 ) ;
}
if ( V_291 ) {
V_25 -> V_297 = F_197 ( V_25 -> V_297 ,
V_291 ) ;
F_216 ( V_291 , & V_25 -> V_292 ) ;
V_25 -> V_305 = V_81 ;
}
F_202 ( V_25 , V_294 ) ;
}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_307 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_290 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_290 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_213 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_307 = 0 ;
} else {
F_200 ( V_28 ) ;
}
if ( V_307 ) {
F_212 ( V_25 , V_28 -> V_77 . V_293 ) ;
F_213 ( V_28 , 0 ) ;
}
V_25 -> V_296 += V_28 -> V_77 . V_293 ;
F_30 ( V_25 , ! V_307 ) ;
}
static inline void F_218 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_308 )
{
F_213 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_308 ) ;
V_25 -> V_296 -= V_28 -> V_77 . V_293 ;
if ( V_308 ) {
V_25 -> V_297 += V_28 -> V_77 . V_293 ;
V_28 -> V_77 . V_78 = F_201 ( & V_25 -> V_292 ) ;
}
}
void F_219 ( struct V_24 * V_309 )
{
F_209 ( V_309 , 1 ) ;
}
void F_220 ( struct V_24 * V_309 )
{
F_209 ( V_309 , 0 ) ;
}
static inline void F_213 ( struct V_27 * V_28 ,
int V_303 ) {}
static inline void F_209 ( struct V_24 * V_24 , int V_285 ) {}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_307 ) {}
static inline void F_218 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_308 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_294 ) {}
static inline int F_221 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_222 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_78
struct V_26 * V_210 = NULL ;
if ( F_21 ( V_28 ) )
V_210 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_310 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_310 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_311 ) )
V_28 -> V_83 . V_311 = V_42 ;
V_28 -> V_83 . V_310 = 0 ;
V_28 -> V_83 . V_312 += V_42 ;
if ( V_210 ) {
F_223 ( V_210 , V_42 >> 10 , 1 ) ;
F_224 ( V_210 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_313 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_313 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_314 ) )
V_28 -> V_83 . V_314 = V_42 ;
V_28 -> V_83 . V_313 = 0 ;
V_28 -> V_83 . V_312 += V_42 ;
if ( V_210 ) {
if ( V_210 -> V_315 ) {
V_28 -> V_83 . V_316 += V_42 ;
V_28 -> V_83 . V_317 ++ ;
F_225 ( V_210 , V_42 ) ;
}
F_226 ( V_210 , V_42 ) ;
if ( F_14 ( V_318 == V_319 ) ) {
F_227 ( V_319 ,
( void * ) F_228 ( V_210 ) ,
V_42 >> 20 ) ;
}
F_223 ( V_210 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_229 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_320 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_320 < 0 )
V_320 = - V_320 ;
if ( V_320 > 3 * V_68 )
F_230 ( V_25 , V_321 ) ;
#endif
}
static void
F_231 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_322 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_322 && F_232 ( V_323 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_322 ) {
unsigned long V_324 = V_68 ;
if ( F_232 ( V_325 ) )
V_324 >>= 1 ;
V_41 -= V_324 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_233 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_208 )
{
if ( ! ( V_208 & V_326 ) || ( V_208 & V_327 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_217 ( V_25 , V_28 , V_208 & V_326 ) ;
F_187 ( V_25 , V_28 ) ;
F_195 ( V_25 ) ;
if ( V_208 & V_326 ) {
F_231 ( V_25 , V_28 , 0 ) ;
F_222 ( V_25 , V_28 ) ;
}
F_76 ( V_25 , V_28 ) ;
F_229 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_234 ( V_25 ) ;
}
}
static void F_235 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_236 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_237 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_328 != V_28 )
break;
V_25 -> V_328 = NULL ;
}
}
static void F_238 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_235 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_236 ( V_28 ) ;
if ( V_25 -> V_328 == V_28 )
F_237 ( V_28 ) ;
}
static void
F_239 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_208 )
{
F_65 ( V_25 ) ;
F_218 ( V_25 , V_28 , V_208 & V_329 ) ;
F_80 ( V_25 , V_28 ) ;
if ( V_208 & V_329 ) {
#ifdef F_78
if ( F_21 ( V_28 ) ) {
struct V_26 * V_210 = F_18 ( V_28 ) ;
if ( V_210 -> V_230 & V_330 )
V_28 -> V_83 . V_310 = F_75 ( F_17 ( V_25 ) ) ;
if ( V_210 -> V_230 & V_331 )
V_28 -> V_83 . V_313 = F_75 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_238 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_189 ( V_25 , V_28 ) ;
if ( ! ( V_208 & V_329 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_240 ( V_25 ) ;
F_40 ( V_25 ) ;
F_195 ( V_25 ) ;
}
static void
F_241 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_332 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_332 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_333 ;
if ( V_19 > V_332 ) {
F_242 ( F_17 ( V_25 ) ) ;
F_238 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_332 )
F_242 ( F_17 ( V_25 ) ) ;
}
static void
F_243 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_77 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
}
F_81 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_78
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_334 = F_68 ( V_28 -> V_83 . V_334 ,
V_28 -> V_85 - V_28 -> V_333 ) ;
}
#endif
V_28 -> V_333 = V_28 -> V_85 ;
}
static struct V_27 *
F_244 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_328 == V_28 ) {
struct V_27 * V_335 ;
if ( V_28 == V_45 ) {
V_335 = F_50 ( V_25 ) ;
} else {
V_335 = F_51 ( V_28 ) ;
if ( ! V_335 || ( V_45 && F_39 ( V_45 , V_335 ) ) )
V_335 = V_45 ;
}
if ( V_335 && F_245 ( V_335 , V_57 ) < 1 )
V_28 = V_335 ;
}
if ( V_25 -> V_59 && F_245 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_245 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_238 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_246 ( struct V_25 * V_25 , struct V_27 * V_336 )
{
if ( V_336 -> V_76 )
F_65 ( V_25 ) ;
F_247 ( V_25 ) ;
F_229 ( V_25 , V_336 ) ;
if ( V_336 -> V_76 ) {
F_74 ( V_25 , V_336 ) ;
F_44 ( V_25 , V_336 ) ;
F_213 ( V_336 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_248 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_337 )
{
F_65 ( V_25 ) ;
F_213 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_195 ( V_25 ) ;
#ifdef F_249
if ( V_337 ) {
F_242 ( F_17 ( V_25 ) ) ;
return;
}
if ( ! F_232 ( V_338 ) &&
F_250 ( & F_17 ( V_25 ) -> V_339 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_241 ( V_25 , V_45 ) ;
}
static inline bool F_251 ( void )
{
return F_252 ( & V_340 ) ;
}
void F_253 ( void )
{
F_254 ( & V_340 ) ;
}
void F_255 ( void )
{
F_256 ( & V_340 ) ;
}
static bool F_251 ( void )
{
return true ;
}
void F_253 ( void ) {}
void F_255 ( void ) {}
static inline T_2 F_257 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_258 ( void )
{
return ( T_2 ) V_341 * V_342 ;
}
void F_259 ( struct V_343 * V_344 )
{
T_2 V_81 ;
if ( V_344 -> V_345 == V_346 )
return;
V_81 = F_260 ( F_261 () ) ;
V_344 -> V_188 = V_344 -> V_345 ;
V_344 -> V_347 = V_81 + F_262 ( V_344 -> V_73 ) ;
}
static inline struct V_343 * F_263 ( struct V_268 * V_33 )
{
return & V_33 -> V_343 ;
}
static inline T_2 F_214 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_348 ) )
return V_25 -> V_349 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_350 ;
}
static int F_264 ( struct V_25 * V_25 )
{
struct V_268 * V_33 = V_25 -> V_33 ;
struct V_343 * V_344 = F_263 ( V_33 ) ;
T_2 V_351 = 0 , V_352 , V_353 ;
V_352 = F_258 () - V_25 -> V_354 ;
F_265 ( & V_344 -> V_198 ) ;
if ( V_344 -> V_345 == V_346 )
V_351 = V_352 ;
else {
if ( ! V_344 -> V_355 ) {
F_259 ( V_344 ) ;
F_266 ( V_344 , false ) ;
}
if ( V_344 -> V_188 > 0 ) {
V_351 = F_135 ( V_344 -> V_188 , V_352 ) ;
V_344 -> V_188 -= V_351 ;
V_344 -> V_356 = 0 ;
}
}
V_353 = V_344 -> V_347 ;
F_267 ( & V_344 -> V_198 ) ;
V_25 -> V_354 += V_351 ;
if ( ( T_3 ) ( V_353 - V_25 -> V_347 ) > 0 )
V_25 -> V_347 = V_353 ;
return V_25 -> V_354 > 0 ;
}
static void F_268 ( struct V_25 * V_25 )
{
struct V_343 * V_344 = F_263 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_75 ( F_17 ( V_25 ) ) - V_25 -> V_347 ) < 0 ) )
return;
if ( V_25 -> V_354 < 0 )
return;
if ( V_25 -> V_347 != V_344 -> V_347 ) {
V_25 -> V_347 += V_251 ;
} else {
V_25 -> V_354 = 0 ;
}
}
static void F_269 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_354 -= V_19 ;
F_268 ( V_25 ) ;
if ( F_12 ( V_25 -> V_354 > 0 ) )
return;
if ( ! F_264 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_242 ( F_17 ( V_25 ) ) ;
}
static T_9
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_251 () || ! V_25 -> V_357 )
return;
F_269 ( V_25 , V_19 ) ;
}
static inline int F_270 ( struct V_25 * V_25 )
{
return F_251 () && V_25 -> V_358 ;
}
static inline int F_196 ( struct V_25 * V_25 )
{
return F_251 () && V_25 -> V_348 ;
}
static inline int F_271 ( struct V_268 * V_33 ,
int V_155 , int V_359 )
{
struct V_25 * V_360 , * V_361 ;
V_360 = V_33 -> V_25 [ V_155 ] ;
V_361 = V_33 -> V_25 [ V_359 ] ;
return F_196 ( V_360 ) ||
F_196 ( V_361 ) ;
}
static int F_272 ( struct V_268 * V_33 , void * V_362 )
{
struct V_24 * V_24 = V_362 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_348 -- ;
#ifdef F_188
if ( ! V_25 -> V_348 ) {
V_25 -> V_350 += F_66 ( V_24 ) -
V_25 -> V_349 ;
}
#endif
return 0 ;
}
static int F_273 ( struct V_268 * V_33 , void * V_362 )
{
struct V_24 * V_24 = V_362 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_348 )
V_25 -> V_349 = F_66 ( V_24 ) ;
V_25 -> V_348 ++ ;
return 0 ;
}
static void F_274 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_343 * V_344 = F_263 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_363 , V_364 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_118 () ;
F_275 ( V_25 -> V_33 , F_273 , V_365 , ( void * ) V_24 ) ;
F_123 () ;
V_363 = V_25 -> V_366 ;
F_61 (se) {
struct V_25 * V_367 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_364 )
F_239 ( V_367 , V_28 , V_329 ) ;
V_367 -> V_366 -= V_363 ;
if ( V_367 -> V_70 . V_4 )
V_364 = 0 ;
}
if ( ! V_28 )
F_276 ( V_24 , V_363 ) ;
V_25 -> V_358 = 1 ;
V_25 -> V_368 = F_75 ( V_24 ) ;
F_265 ( & V_344 -> V_198 ) ;
F_28 ( & V_25 -> V_369 , & V_344 -> V_370 ) ;
if ( ! V_344 -> V_355 )
F_266 ( V_344 , false ) ;
F_267 ( & V_344 -> V_198 ) ;
}
void F_277 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_343 * V_344 = F_263 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_371 = 1 ;
long V_363 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_358 = 0 ;
F_278 ( V_24 ) ;
F_265 ( & V_344 -> V_198 ) ;
V_344 -> V_372 += F_75 ( V_24 ) - V_25 -> V_368 ;
F_32 ( & V_25 -> V_369 ) ;
F_267 ( & V_344 -> V_198 ) ;
F_275 ( V_25 -> V_33 , V_365 , F_272 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_363 = V_25 -> V_366 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_371 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_371 )
F_233 ( V_25 , V_28 , V_326 ) ;
V_25 -> V_366 += V_363 ;
if ( F_270 ( V_25 ) )
break;
}
if ( ! V_28 )
F_279 ( V_24 , V_363 ) ;
if ( V_24 -> V_45 == V_24 -> V_356 && V_24 -> V_40 . V_72 )
F_242 ( V_24 ) ;
}
static T_2 F_280 ( struct V_343 * V_344 ,
T_2 V_373 , T_2 V_353 )
{
struct V_25 * V_25 ;
T_2 V_188 ;
T_2 V_374 = V_373 ;
F_118 () ;
F_281 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_265 ( & V_24 -> V_198 ) ;
if ( ! F_270 ( V_25 ) )
goto V_58;
V_188 = - V_25 -> V_354 + 1 ;
if ( V_188 > V_373 )
V_188 = V_373 ;
V_373 -= V_188 ;
V_25 -> V_354 += V_188 ;
V_25 -> V_347 = V_353 ;
if ( V_25 -> V_354 > 0 )
F_277 ( V_25 ) ;
V_58:
F_267 ( & V_24 -> V_198 ) ;
if ( ! V_373 )
break;
}
F_123 () ;
return V_374 - V_373 ;
}
static int F_282 ( struct V_343 * V_344 , int V_375 )
{
T_2 V_188 , V_347 ;
int V_358 ;
if ( V_344 -> V_345 == V_346 )
goto V_376;
V_358 = ! F_283 ( & V_344 -> V_370 ) ;
V_344 -> V_377 += V_375 ;
if ( V_344 -> V_356 && ! V_358 )
goto V_376;
V_344 -> V_355 = 1 ;
F_259 ( V_344 ) ;
if ( ! V_358 ) {
V_344 -> V_356 = 1 ;
return 0 ;
}
V_344 -> V_378 += V_375 ;
V_347 = V_344 -> V_347 ;
while ( V_358 && V_344 -> V_188 > 0 ) {
V_188 = V_344 -> V_188 ;
F_267 ( & V_344 -> V_198 ) ;
V_188 = F_280 ( V_344 , V_188 ,
V_347 ) ;
F_265 ( & V_344 -> V_198 ) ;
V_358 = ! F_283 ( & V_344 -> V_370 ) ;
V_344 -> V_188 -= F_135 ( V_188 , V_344 -> V_188 ) ;
}
V_344 -> V_356 = 0 ;
return 0 ;
V_376:
V_344 -> V_355 = 0 ;
return 1 ;
}
static int F_284 ( struct V_343 * V_344 , T_2 V_379 )
{
struct V_380 * V_381 = & V_344 -> V_382 ;
T_2 V_373 ;
if ( F_285 ( V_381 ) )
return 1 ;
V_373 = F_262 ( F_286 ( V_381 ) ) ;
if ( V_373 < V_379 )
return 1 ;
return 0 ;
}
static void F_287 ( struct V_343 * V_344 )
{
T_2 V_383 = V_384 + V_385 ;
if ( F_284 ( V_344 , V_383 ) )
return;
F_288 ( & V_344 -> V_386 ,
F_289 ( V_384 ) ) ;
}
static void F_290 ( struct V_25 * V_25 )
{
struct V_343 * V_344 = F_263 ( V_25 -> V_33 ) ;
T_3 V_387 = V_25 -> V_354 - V_388 ;
if ( V_387 <= 0 )
return;
F_265 ( & V_344 -> V_198 ) ;
if ( V_344 -> V_345 != V_346 &&
V_25 -> V_347 == V_344 -> V_347 ) {
V_344 -> V_188 += V_387 ;
if ( V_344 -> V_188 > F_258 () &&
! F_283 ( & V_344 -> V_370 ) )
F_287 ( V_344 ) ;
}
F_267 ( & V_344 -> V_198 ) ;
V_25 -> V_354 -= V_387 ;
}
static T_9 void F_240 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return;
if ( ! V_25 -> V_357 || V_25 -> V_72 )
return;
F_290 ( V_25 ) ;
}
static void F_291 ( struct V_343 * V_344 )
{
T_2 V_188 = 0 , V_75 = F_258 () ;
T_2 V_353 ;
F_265 ( & V_344 -> V_198 ) ;
if ( F_284 ( V_344 , V_385 ) ) {
F_267 ( & V_344 -> V_198 ) ;
return;
}
if ( V_344 -> V_345 != V_346 && V_344 -> V_188 > V_75 )
V_188 = V_344 -> V_188 ;
V_353 = V_344 -> V_347 ;
F_267 ( & V_344 -> V_198 ) ;
if ( ! V_188 )
return;
V_188 = F_280 ( V_344 , V_188 , V_353 ) ;
F_265 ( & V_344 -> V_198 ) ;
if ( V_353 == V_344 -> V_347 )
V_344 -> V_188 -= F_135 ( V_188 , V_344 -> V_188 ) ;
F_267 ( & V_344 -> V_198 ) ;
}
static void F_234 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return;
if ( ! V_25 -> V_357 || V_25 -> V_45 )
return;
if ( F_270 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_354 <= 0 )
F_274 ( V_25 ) ;
}
static bool F_247 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return false ;
if ( F_12 ( ! V_25 -> V_357 || V_25 -> V_354 > 0 ) )
return false ;
if ( F_270 ( V_25 ) )
return true ;
F_274 ( V_25 ) ;
return true ;
}
static enum V_389 F_292 ( struct V_380 * V_390 )
{
struct V_343 * V_344 =
F_22 ( V_390 , struct V_343 , V_386 ) ;
F_291 ( V_344 ) ;
return V_391 ;
}
static enum V_389 F_293 ( struct V_380 * V_390 )
{
struct V_343 * V_344 =
F_22 ( V_390 , struct V_343 , V_382 ) ;
T_10 V_81 ;
int V_375 ;
int V_356 = 0 ;
F_265 ( & V_344 -> V_198 ) ;
for (; ; ) {
V_81 = F_294 ( V_390 ) ;
V_375 = F_295 ( V_390 , V_81 , V_344 -> V_73 ) ;
if ( ! V_375 )
break;
V_356 = F_282 ( V_344 , V_375 ) ;
}
F_267 ( & V_344 -> V_198 ) ;
return V_356 ? V_391 : V_392 ;
}
void F_296 ( struct V_343 * V_344 )
{
F_297 ( & V_344 -> V_198 ) ;
V_344 -> V_188 = 0 ;
V_344 -> V_345 = V_346 ;
V_344 -> V_73 = F_289 ( F_257 () ) ;
F_157 ( & V_344 -> V_370 ) ;
F_298 ( & V_344 -> V_382 , V_393 , V_394 ) ;
V_344 -> V_382 . V_395 = F_293 ;
F_298 ( & V_344 -> V_386 , V_393 , V_394 ) ;
V_344 -> V_386 . V_395 = F_292 ;
}
static void F_299 ( struct V_25 * V_25 )
{
V_25 -> V_357 = 0 ;
F_157 ( & V_25 -> V_369 ) ;
}
void F_266 ( struct V_343 * V_344 , bool V_396 )
{
while ( F_14 ( F_250 ( & V_344 -> V_382 ) ) &&
F_300 ( & V_344 -> V_382 ) < 0 ) {
F_267 ( & V_344 -> V_198 ) ;
F_301 () ;
F_265 ( & V_344 -> V_198 ) ;
if ( ! V_396 && V_344 -> V_355 )
return;
}
V_344 -> V_355 = 1 ;
F_288 ( & V_344 -> V_382 , V_344 -> V_73 ) ;
}
static void F_302 ( struct V_343 * V_344 )
{
F_303 ( & V_344 -> V_382 ) ;
F_303 ( & V_344 -> V_386 ) ;
}
static void T_11 F_304 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_305 (rq, cfs_rq) {
struct V_343 * V_344 = & V_25 -> V_33 -> V_343 ;
F_265 ( & V_344 -> V_198 ) ;
V_25 -> V_357 = V_344 -> V_345 != V_346 ;
F_267 ( & V_344 -> V_198 ) ;
}
}
static void T_11 F_306 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_305 (rq, cfs_rq) {
if ( ! V_25 -> V_357 )
continue;
V_25 -> V_354 = 1 ;
V_25 -> V_357 = 0 ;
if ( F_270 ( V_25 ) )
F_277 ( V_25 ) ;
}
}
static inline T_2 F_214 ( struct V_25 * V_25 )
{
return F_66 ( F_17 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_247 ( struct V_25 * V_25 ) { return false ; }
static void F_234 ( struct V_25 * V_25 ) {}
static T_9 void F_240 ( struct V_25 * V_25 ) {}
static inline int F_270 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_196 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_271 ( struct V_268 * V_33 ,
int V_155 , int V_359 )
{
return 0 ;
}
void F_296 ( struct V_343 * V_344 ) {}
static void F_299 ( struct V_25 * V_25 ) {}
static inline struct V_343 * F_263 ( struct V_268 * V_33 )
{
return NULL ;
}
static inline void F_302 ( struct V_343 * V_344 ) {}
static inline void F_304 ( struct V_24 * V_24 ) {}
static inline void F_306 ( struct V_24 * V_24 ) {}
static void F_307 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_308 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_397 = V_28 -> V_85 - V_28 -> V_333 ;
T_3 V_42 = V_75 - V_397 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_242 ( V_24 ) ;
return;
}
if ( V_24 -> V_45 != V_29 )
V_42 = F_86 ( T_3 , 10000LL , V_42 ) ;
F_309 ( V_24 , V_42 ) ;
}
}
static void F_310 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_311 ( V_24 ) || V_45 -> V_398 != & V_399 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_307 ( V_24 , V_45 ) ;
}
static inline void
F_307 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_310 ( struct V_24 * V_24 )
{
}
static void
F_312 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_208 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_233 ( V_25 , V_28 , V_208 ) ;
if ( F_270 ( V_25 ) )
break;
V_25 -> V_366 ++ ;
V_208 = V_326 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_366 ++ ;
if ( F_270 ( V_25 ) )
break;
F_195 ( V_25 ) ;
F_213 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_209 ( V_24 , V_24 -> V_72 ) ;
F_279 ( V_24 , 1 ) ;
}
F_310 ( V_24 ) ;
}
static void F_313 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_208 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_400 = V_208 & V_329 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_239 ( V_25 , V_28 , V_208 ) ;
if ( F_270 ( V_25 ) )
break;
V_25 -> V_366 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_400 && F_34 ( V_28 ) )
F_314 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_208 |= V_329 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_366 -- ;
if ( F_270 ( V_25 ) )
break;
F_195 ( V_25 ) ;
F_213 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_276 ( V_24 , 1 ) ;
F_209 ( V_24 , 1 ) ;
}
F_310 ( V_24 ) ;
}
static unsigned long F_109 ( const int V_130 )
{
return F_108 ( V_130 ) -> V_40 . V_296 ;
}
static unsigned long F_315 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_401 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_232 ( V_402 ) )
return V_401 ;
return F_135 ( V_24 -> V_403 [ type - 1 ] , V_401 ) ;
}
static unsigned long F_316 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_401 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_232 ( V_402 ) )
return V_401 ;
return F_68 ( V_24 -> V_403 [ type - 1 ] , V_401 ) ;
}
static unsigned long F_110 ( int V_130 )
{
return F_108 ( V_130 ) -> V_404 ;
}
static unsigned long F_317 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_72 = F_119 ( V_24 -> V_72 ) ;
unsigned long V_270 = V_24 -> V_40 . V_296 ;
if ( V_72 )
return V_270 / V_72 ;
return 0 ;
}
static void F_318 ( struct V_26 * V_29 )
{
if ( F_171 ( V_173 , V_125 -> V_405 + V_171 ) ) {
V_125 -> V_406 >>= 1 ;
V_125 -> V_405 = V_173 ;
}
if ( V_125 -> V_407 != V_29 ) {
V_125 -> V_407 = V_29 ;
V_125 -> V_406 ++ ;
}
}
static void F_319 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_320 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_318 ( V_29 ) ;
}
static long F_321 ( struct V_268 * V_33 , int V_130 , long V_408 , long V_409 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_130 ] ;
if ( ! V_33 -> V_34 )
return V_408 ;
F_61 (se) {
long V_7 , V_410 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_410 = V_409 + F_191 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_408 ;
if ( V_410 > 0 && V_7 < V_410 )
V_408 = ( V_7 * V_33 -> V_272 ) / V_410 ;
else
V_408 = V_33 -> V_272 ;
if ( V_408 < V_273 )
V_408 = V_273 ;
V_408 -= V_28 -> V_70 . V_4 ;
V_409 = 0 ;
}
return V_408 ;
}
static long F_321 ( struct V_268 * V_33 , int V_130 , long V_408 , long V_409 )
{
return V_408 ;
}
static int F_322 ( struct V_26 * V_29 )
{
int V_9 = F_323 ( V_411 ) ;
if ( V_29 -> V_406 > V_9 ) {
if ( V_125 -> V_406 > ( V_9 * V_29 -> V_406 ) )
return 1 ;
}
return 0 ;
}
static int F_324 ( struct V_162 * V_163 , struct V_26 * V_29 , int V_412 )
{
T_3 V_413 , V_70 ;
int V_414 , V_415 , V_416 ;
unsigned long V_417 ;
struct V_268 * V_33 ;
unsigned long V_4 ;
int V_418 ;
if ( F_322 ( V_29 ) )
return 0 ;
V_414 = V_163 -> V_419 ;
V_415 = F_261 () ;
V_416 = F_126 ( V_29 ) ;
V_70 = F_315 ( V_416 , V_414 ) ;
V_413 = F_316 ( V_415 , V_414 ) ;
if ( V_412 ) {
V_33 = V_268 ( V_125 ) ;
V_4 = V_125 -> V_28 . V_70 . V_4 ;
V_413 += F_321 ( V_33 , V_415 , - V_4 , - V_4 ) ;
V_70 += F_321 ( V_33 , V_416 , 0 , - V_4 ) ;
}
V_33 = V_268 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_413 > 0 ) {
T_3 V_420 , V_421 ;
V_420 = 100 ;
V_420 *= F_110 ( V_416 ) ;
V_420 *= V_413 +
F_321 ( V_33 , V_415 , V_4 , V_4 ) ;
V_421 = 100 + ( V_163 -> V_151 - 100 ) / 2 ;
V_421 *= F_110 ( V_415 ) ;
V_421 *= V_70 + F_321 ( V_33 , V_416 , 0 , V_4 ) ;
V_418 = V_420 <= V_421 ;
} else
V_418 = true ;
if ( V_412 && V_418 )
return 1 ;
F_230 ( V_29 , V_28 . V_83 . V_422 ) ;
V_417 = F_317 ( V_415 ) ;
if ( V_418 ||
( V_413 <= V_70 &&
V_413 + F_316 ( V_416 , V_414 ) <= V_417 ) ) {
F_230 ( V_163 , V_423 ) ;
F_230 ( V_29 , V_28 . V_83 . V_424 ) ;
return 1 ;
}
return 0 ;
}
static struct V_425 *
F_325 ( struct V_162 * V_163 , struct V_26 * V_29 ,
int V_415 , int V_426 )
{
struct V_425 * V_427 = NULL , * V_114 = V_163 -> V_428 ;
unsigned long V_429 = V_430 , V_413 = 0 ;
int V_431 = V_163 -> V_432 ;
int V_433 = 100 + ( V_163 -> V_151 - 100 ) / 2 ;
if ( V_426 & V_434 )
V_431 = V_163 -> V_419 ;
do {
unsigned long V_70 , V_435 ;
int V_436 ;
int V_199 ;
if ( ! F_326 ( F_327 ( V_114 ) ,
F_121 ( V_29 ) ) )
continue;
V_436 = F_120 ( V_415 ,
F_327 ( V_114 ) ) ;
V_435 = 0 ;
F_107 (i, sched_group_cpus(group)) {
if ( V_436 )
V_70 = F_315 ( V_199 , V_431 ) ;
else
V_70 = F_316 ( V_199 , V_431 ) ;
V_435 += V_70 ;
}
V_435 = ( V_435 * V_133 ) / V_114 -> V_437 -> V_438 ;
if ( V_436 ) {
V_413 = V_435 ;
} else if ( V_435 < V_429 ) {
V_429 = V_435 ;
V_427 = V_114 ;
}
} while ( V_114 = V_114 -> V_58 , V_114 != V_163 -> V_428 );
if ( ! V_427 || 100 * V_413 < V_433 * V_429 )
return NULL ;
return V_427 ;
}
static int
F_328 ( struct V_425 * V_114 , struct V_26 * V_29 , int V_415 )
{
unsigned long V_70 , V_429 = V_430 ;
int V_427 = - 1 ;
int V_199 ;
F_329 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_109 ( V_199 ) ;
if ( V_70 < V_429 || ( V_70 == V_429 && V_199 == V_415 ) ) {
V_429 = V_70 ;
V_427 = V_199 ;
}
}
return V_427 ;
}
static int F_330 ( struct V_26 * V_29 , int V_439 )
{
struct V_162 * V_163 ;
struct V_425 * V_440 ;
int V_199 = F_126 ( V_29 ) ;
if ( F_331 ( V_439 ) )
return V_439 ;
if ( V_199 != V_439 && F_332 ( V_199 , V_439 ) && F_331 ( V_199 ) )
return V_199 ;
V_163 = F_127 ( F_128 ( V_441 , V_439 ) ) ;
F_333 (sd) {
V_440 = V_163 -> V_428 ;
do {
if ( ! F_326 ( F_327 ( V_440 ) ,
F_121 ( V_29 ) ) )
goto V_58;
F_107 (i, sched_group_cpus(sg)) {
if ( V_199 == V_439 || ! F_331 ( V_199 ) )
goto V_58;
}
V_439 = F_334 ( F_327 ( V_440 ) ,
F_121 ( V_29 ) ) ;
goto V_442;
V_58:
V_440 = V_440 -> V_58 ;
} while ( V_440 != V_163 -> V_428 );
}
V_442:
return V_439 ;
}
static int
F_335 ( struct V_26 * V_29 , int V_416 , int V_426 , int V_443 )
{
struct V_162 * V_444 , * V_445 = NULL , * V_163 = NULL ;
int V_130 = F_261 () ;
int V_446 = V_130 ;
int V_447 = 0 ;
int V_412 = V_443 & V_448 ;
if ( V_29 -> V_449 == 1 )
return V_416 ;
if ( V_426 & V_434 ) {
if ( F_120 ( V_130 , F_121 ( V_29 ) ) )
V_447 = 1 ;
V_446 = V_416 ;
}
F_118 () ;
F_336 (cpu, tmp) {
if ( ! ( V_444 -> V_208 & V_450 ) )
continue;
if ( V_447 && ( V_444 -> V_208 & V_451 ) &&
F_120 ( V_416 , F_337 ( V_444 ) ) ) {
V_445 = V_444 ;
break;
}
if ( V_444 -> V_208 & V_426 )
V_163 = V_444 ;
}
if ( V_445 && V_130 != V_416 && F_324 ( V_445 , V_29 , V_412 ) )
V_416 = V_130 ;
if ( V_426 & V_434 ) {
V_446 = F_330 ( V_29 , V_416 ) ;
goto V_159;
}
while ( V_163 ) {
struct V_425 * V_114 ;
int V_4 ;
if ( ! ( V_163 -> V_208 & V_426 ) ) {
V_163 = V_163 -> V_452 ;
continue;
}
V_114 = F_325 ( V_163 , V_29 , V_130 , V_426 ) ;
if ( ! V_114 ) {
V_163 = V_163 -> V_452 ;
continue;
}
V_446 = F_328 ( V_114 , V_29 , V_130 ) ;
if ( V_446 == - 1 || V_446 == V_130 ) {
V_163 = V_163 -> V_452 ;
continue;
}
V_130 = V_446 ;
V_4 = V_163 -> V_453 ;
V_163 = NULL ;
F_336 (cpu, tmp) {
if ( V_4 <= V_444 -> V_453 )
break;
if ( V_444 -> V_208 & V_426 )
V_163 = V_444 ;
}
}
V_159:
F_123 () ;
return V_446 ;
}
static void
F_338 ( struct V_26 * V_29 , int V_454 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_200 ( V_28 ) ;
F_203 ( V_28 -> V_77 . V_293 ,
& V_25 -> V_306 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_339 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_455 = V_456 ;
return F_58 ( V_455 , V_28 ) ;
}
static int
F_245 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_455 , V_457 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_457 <= 0 )
return - 1 ;
V_455 = F_339 ( V_45 , V_28 ) ;
if ( V_457 > V_455 )
return 1 ;
return 0 ;
}
static void F_340 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_458 == V_459 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_314 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_458 == V_459 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_341 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_328 = V_28 ;
}
static void F_342 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_443 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_460 = V_25 -> V_72 >= V_67 ;
int V_461 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_196 ( F_24 ( V_36 ) ) ) )
return;
if ( F_232 ( V_462 ) && V_460 && ! ( V_443 & V_463 ) ) {
F_314 ( V_36 ) ;
V_461 = 1 ;
}
if ( F_343 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_458 == V_459 ) &&
F_12 ( V_29 -> V_458 != V_459 ) )
goto V_464;
if ( F_14 ( V_29 -> V_458 != V_465 ) || ! F_232 ( V_466 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_160 ( ! V_36 ) ;
if ( F_245 ( V_28 , V_36 ) == 1 ) {
if ( ! V_461 )
F_314 ( V_36 ) ;
goto V_464;
}
return;
V_464:
F_242 ( V_24 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_356 ) )
return;
if ( F_232 ( V_467 ) && V_460 && F_21 ( V_28 ) )
F_340 ( V_28 ) ;
}
static struct V_26 *
F_344 ( struct V_24 * V_24 , struct V_26 * V_336 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_468 ;
V_469:
#ifdef F_345
if ( ! V_25 -> V_72 )
goto V_356;
if ( V_336 -> V_398 != & V_399 )
goto V_470;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_247 ( V_25 ) ) )
goto V_470;
V_28 = F_244 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_336 != V_29 ) {
struct V_27 * V_36 = & V_336 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_246 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_243 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_246 ( V_25 , V_36 ) ;
F_243 ( V_25 , V_28 ) ;
}
if ( F_311 ( V_24 ) )
F_307 ( V_24 , V_29 ) ;
return V_29 ;
V_470:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_356;
F_346 ( V_24 , V_336 ) ;
do {
V_28 = F_244 ( V_25 , NULL ) ;
F_243 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_311 ( V_24 ) )
F_307 ( V_24 , V_29 ) ;
return V_29 ;
V_356:
V_468 = F_221 ( V_24 ) ;
if ( V_468 < 0 )
return V_471 ;
if ( V_468 > 0 )
goto V_469;
return NULL ;
}
static void F_347 ( struct V_24 * V_24 , struct V_26 * V_336 )
{
struct V_27 * V_28 = & V_336 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_246 ( V_25 , V_28 ) ;
}
}
static void F_348 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_238 ( V_25 , V_28 ) ;
if ( V_45 -> V_458 != V_472 ) {
F_278 ( V_24 ) ;
F_65 ( V_25 ) ;
V_24 -> V_473 = 1 ;
}
F_341 ( V_28 ) ;
}
static bool F_349 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_464 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_196 ( F_24 ( V_28 ) ) )
return false ;
F_314 ( V_28 ) ;
F_348 ( V_24 ) ;
return true ;
}
static void F_350 ( struct V_26 * V_29 , struct V_474 * V_136 )
{
F_351 ( V_136 -> V_154 , V_29 , 0 ) ;
F_352 ( V_29 , V_136 -> V_120 ) ;
F_353 ( V_136 -> V_156 , V_29 , 0 ) ;
F_354 ( V_136 -> V_156 , V_29 , 0 ) ;
}
static int F_355 ( struct V_26 * V_29 , struct V_474 * V_136 )
{
T_3 V_42 ;
if ( V_29 -> V_398 != & V_399 )
return 0 ;
if ( F_14 ( V_29 -> V_458 == V_459 ) )
return 0 ;
if ( F_232 ( V_475 ) && V_136 -> V_156 -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_476 == - 1 )
return 1 ;
if ( V_476 == 0 )
return 0 ;
V_42 = F_66 ( V_136 -> V_154 ) - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_476 ;
}
static bool F_356 ( struct V_26 * V_29 , struct V_474 * V_136 )
{
struct V_107 * V_107 = F_127 ( V_29 -> V_107 ) ;
int V_119 , V_122 ;
if ( ! F_232 ( V_477 ) || ! V_29 -> V_112 ||
! ( V_136 -> V_163 -> V_208 & V_478 ) ) {
return false ;
}
V_119 = F_99 ( V_136 -> V_155 ) ;
V_122 = F_99 ( V_136 -> V_120 ) ;
if ( V_119 == V_122 )
return false ;
if ( V_107 ) {
if ( F_105 ( V_119 , V_107 -> V_127 ) )
return false ;
if ( F_105 ( V_122 , V_107 -> V_127 ) )
return true ;
return F_94 ( V_29 , V_122 ) > F_94 ( V_29 , V_119 ) ;
}
if ( V_122 == V_29 -> V_105 )
return true ;
return F_93 ( V_29 , V_122 ) > F_93 ( V_29 , V_119 ) ;
}
static bool F_357 ( struct V_26 * V_29 , struct V_474 * V_136 )
{
struct V_107 * V_107 = F_127 ( V_29 -> V_107 ) ;
int V_119 , V_122 ;
if ( ! F_232 ( V_479 ) || ! F_232 ( V_480 ) )
return false ;
if ( ! V_29 -> V_112 || ! ( V_136 -> V_163 -> V_208 & V_478 ) )
return false ;
V_119 = F_99 ( V_136 -> V_155 ) ;
V_122 = F_99 ( V_136 -> V_120 ) ;
if ( V_119 == V_122 )
return false ;
if ( V_107 ) {
if ( F_105 ( V_122 , V_107 -> V_127 ) )
return false ;
if ( F_105 ( V_119 , V_107 -> V_127 ) )
return true ;
return F_94 ( V_29 , V_122 ) < F_94 ( V_29 , V_119 ) ;
}
if ( V_119 == V_29 -> V_105 )
return true ;
return F_93 ( V_29 , V_122 ) < F_93 ( V_29 , V_119 ) ;
}
static inline bool F_356 ( struct V_26 * V_29 ,
struct V_474 * V_136 )
{
return false ;
}
static inline bool F_357 ( struct V_26 * V_29 ,
struct V_474 * V_136 )
{
return false ;
}
static
int F_358 ( struct V_26 * V_29 , struct V_474 * V_136 )
{
int V_481 = 0 ;
if ( F_271 ( V_268 ( V_29 ) , V_136 -> V_155 , V_136 -> V_120 ) )
return 0 ;
if ( ! F_120 ( V_136 -> V_120 , F_121 ( V_29 ) ) ) {
int V_130 ;
F_230 ( V_29 , V_28 . V_83 . V_482 ) ;
V_136 -> V_208 |= V_483 ;
if ( ! V_136 -> V_484 || ( V_136 -> V_208 & V_485 ) )
return 0 ;
F_329 (cpu, env->dst_grpmask, env->cpus) {
if ( F_120 ( V_130 , F_121 ( V_29 ) ) ) {
V_136 -> V_208 |= V_485 ;
V_136 -> V_486 = V_130 ;
break;
}
}
return 0 ;
}
V_136 -> V_208 &= ~ V_487 ;
if ( F_359 ( V_136 -> V_154 , V_29 ) ) {
F_230 ( V_29 , V_28 . V_83 . V_488 ) ;
return 0 ;
}
V_481 = F_355 ( V_29 , V_136 ) ;
if ( ! V_481 )
V_481 = F_357 ( V_29 , V_136 ) ;
if ( F_356 ( V_29 , V_136 ) ) {
#ifdef F_78
if ( V_481 ) {
F_230 ( V_136 -> V_163 , V_489 [ V_136 -> V_356 ] ) ;
F_230 ( V_29 , V_28 . V_83 . V_490 ) ;
}
#endif
return 1 ;
}
if ( ! V_481 ||
V_136 -> V_163 -> V_491 > V_136 -> V_163 -> V_492 ) {
if ( V_481 ) {
F_230 ( V_136 -> V_163 , V_489 [ V_136 -> V_356 ] ) ;
F_230 ( V_29 , V_28 . V_83 . V_490 ) ;
}
return 1 ;
}
F_230 ( V_29 , V_28 . V_83 . V_493 ) ;
return 0 ;
}
static int F_360 ( struct V_474 * V_136 )
{
struct V_26 * V_29 , * V_275 ;
F_361 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_358 ( V_29 , V_136 ) )
continue;
F_350 ( V_29 , V_136 ) ;
F_230 ( V_136 -> V_163 , V_494 [ V_136 -> V_356 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_362 ( struct V_474 * V_136 )
{
struct V_495 * V_496 = & V_136 -> V_154 -> V_267 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_497 = 0 ;
if ( V_136 -> V_433 <= 0 )
return 0 ;
while ( ! F_283 ( V_496 ) ) {
V_29 = F_363 ( V_496 , struct V_26 , V_28 . V_266 ) ;
V_136 -> V_498 ++ ;
if ( V_136 -> V_498 > V_136 -> V_499 )
break;
if ( V_136 -> V_498 > V_136 -> V_500 ) {
V_136 -> V_500 += V_501 ;
V_136 -> V_208 |= V_502 ;
break;
}
if ( ! F_358 ( V_29 , V_136 ) )
goto V_58;
V_70 = F_122 ( V_29 ) ;
if ( F_232 ( V_503 ) && V_70 < 16 && ! V_136 -> V_163 -> V_491 )
goto V_58;
if ( ( V_70 / 2 ) > V_136 -> V_433 )
goto V_58;
F_350 ( V_29 , V_136 ) ;
V_497 ++ ;
V_136 -> V_433 -= V_70 ;
#ifdef F_364
if ( V_136 -> V_356 == V_504 )
break;
#endif
if ( V_136 -> V_433 <= 0 )
break;
continue;
V_58:
F_365 ( & V_29 -> V_28 . V_266 , V_496 ) ;
}
F_69 ( V_136 -> V_163 , V_494 [ V_136 -> V_356 ] , V_497 ) ;
return V_497 ;
}
static void F_366 ( struct V_268 * V_33 , int V_130 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_130 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_130 ] ;
if ( F_196 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_213 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_209 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_367 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
struct V_25 * V_25 ;
unsigned long V_208 ;
F_368 ( & V_24 -> V_198 , V_208 ) ;
F_278 ( V_24 ) ;
F_305 (rq, cfs_rq) {
F_366 ( V_25 -> V_33 , V_24 -> V_130 ) ;
}
F_369 ( & V_24 -> V_198 , V_208 ) ;
}
static void F_370 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_173 ;
unsigned long V_70 ;
if ( V_25 -> V_505 == V_81 )
return;
V_25 -> V_506 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_506 = V_28 ;
if ( V_25 -> V_505 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_507 = V_25 -> V_296 ;
V_25 -> V_505 = V_81 ;
}
while ( ( V_28 = V_25 -> V_506 ) != NULL ) {
V_70 = V_25 -> V_507 ;
V_70 = F_371 ( V_70 * V_28 -> V_77 . V_293 ,
V_25 -> V_296 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_507 = V_70 ;
V_25 -> V_505 = V_81 ;
}
}
static unsigned long F_122 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_370 ( V_25 ) ;
return F_371 ( V_29 -> V_28 . V_77 . V_293 * V_25 -> V_507 ,
V_25 -> V_296 + 1 ) ;
}
static inline void F_367 ( int V_130 )
{
}
static unsigned long F_122 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_293 ;
}
static inline void F_372 ( struct V_508 * V_509 )
{
* V_509 = (struct V_508 ) {
. V_510 = NULL ,
. V_182 = NULL ,
. V_511 = 0UL ,
. V_512 = 0UL ,
. V_513 = {
. V_435 = 0UL ,
} ,
} ;
}
static inline int F_373 ( struct V_162 * V_163 ,
enum V_514 V_356 )
{
int V_431 ;
switch ( V_356 ) {
case V_515 :
V_431 = V_163 -> V_516 ;
break;
case V_504 :
V_431 = V_163 -> V_517 ;
break;
default:
V_431 = V_163 -> V_518 ;
break;
}
return V_431 ;
}
static unsigned long F_374 ( struct V_162 * V_163 , int V_130 )
{
return V_133 ;
}
unsigned long __weak F_375 ( struct V_162 * V_163 , int V_130 )
{
return F_374 ( V_163 , V_130 ) ;
}
static unsigned long F_376 ( struct V_162 * V_163 , int V_130 )
{
unsigned long V_4 = V_163 -> V_453 ;
unsigned long V_519 = V_163 -> V_519 ;
V_519 /= V_4 ;
return V_519 ;
}
unsigned long __weak F_377 ( struct V_162 * V_163 , int V_130 )
{
return F_376 ( V_163 , V_130 ) ;
}
static unsigned long F_378 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
T_2 V_401 , V_520 , V_521 , V_77 ;
T_3 V_42 ;
V_521 = F_119 ( V_24 -> V_521 ) ;
V_77 = F_119 ( V_24 -> V_522 ) ;
V_42 = F_75 ( V_24 ) - V_521 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_401 = F_379 () + V_42 ;
if ( F_14 ( V_401 < V_77 ) ) {
V_520 = 0 ;
} else {
V_520 = V_401 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_401 < V_133 ) )
V_401 = V_133 ;
V_401 >>= V_523 ;
return F_205 ( V_520 , V_401 ) ;
}
static void F_380 ( struct V_162 * V_163 , int V_130 )
{
unsigned long V_4 = V_163 -> V_453 ;
unsigned long V_438 = V_133 ;
struct V_425 * V_524 = V_163 -> V_428 ;
if ( ( V_163 -> V_208 & V_525 ) && V_4 > 1 ) {
if ( F_232 ( V_526 ) )
V_438 *= F_377 ( V_163 , V_130 ) ;
else
V_438 *= F_376 ( V_163 , V_130 ) ;
V_438 >>= V_523 ;
}
V_524 -> V_437 -> V_527 = V_438 ;
if ( F_232 ( V_526 ) )
V_438 *= F_375 ( V_163 , V_130 ) ;
else
V_438 *= F_374 ( V_163 , V_130 ) ;
V_438 >>= V_523 ;
V_438 *= F_378 ( V_130 ) ;
V_438 >>= V_523 ;
if ( ! V_438 )
V_438 = 1 ;
F_108 ( V_130 ) -> V_404 = V_438 ;
V_524 -> V_437 -> V_438 = V_438 ;
}
void F_381 ( struct V_162 * V_163 , int V_130 )
{
struct V_162 * V_452 = V_163 -> V_452 ;
struct V_425 * V_114 , * V_524 = V_163 -> V_428 ;
unsigned long V_438 , V_527 ;
unsigned long V_170 ;
V_170 = F_136 ( V_163 -> V_528 ) ;
V_170 = F_141 ( V_170 , 1UL , V_529 ) ;
V_524 -> V_437 -> V_530 = V_173 + V_170 ;
if ( ! V_452 ) {
F_380 ( V_163 , V_130 ) ;
return;
}
V_527 = V_438 = 0 ;
if ( V_452 -> V_208 & V_531 ) {
F_107 (cpu, sched_group_cpus(sdg)) {
struct V_532 * V_437 ;
struct V_24 * V_24 = F_108 ( V_130 ) ;
if ( F_14 ( ! V_24 -> V_163 ) ) {
V_527 += F_110 ( V_130 ) ;
V_438 += F_110 ( V_130 ) ;
continue;
}
V_437 = V_24 -> V_163 -> V_428 -> V_437 ;
V_527 += V_437 -> V_527 ;
V_438 += V_437 -> V_438 ;
}
} else {
V_114 = V_452 -> V_428 ;
do {
V_527 += V_114 -> V_437 -> V_527 ;
V_438 += V_114 -> V_437 -> V_438 ;
V_114 = V_114 -> V_58 ;
} while ( V_114 != V_452 -> V_428 );
}
V_524 -> V_437 -> V_527 = V_527 ;
V_524 -> V_437 -> V_438 = V_438 ;
}
static inline int
F_382 ( struct V_162 * V_163 , struct V_425 * V_114 )
{
if ( ! ( V_163 -> V_208 & V_525 ) )
return 0 ;
if ( V_114 -> V_437 -> V_438 * 32 > V_114 -> V_437 -> V_527 * 29 )
return 1 ;
return 0 ;
}
static inline int F_383 ( struct V_425 * V_114 )
{
return V_114 -> V_437 -> V_433 ;
}
static inline int F_384 ( struct V_474 * V_136 , struct V_425 * V_114 )
{
unsigned int V_533 , V_534 , V_8 ;
unsigned int V_438 , V_527 ;
V_438 = V_114 -> V_437 -> V_438 ;
V_527 = V_114 -> V_437 -> V_527 ;
V_8 = V_114 -> F_97 ;
V_534 = F_56 ( V_133 * V_8 , V_527 ) ;
V_533 = V_8 / V_534 ;
V_533 = F_5 ( unsigned ,
V_533 , F_111 ( V_438 , V_133 ) ) ;
if ( ! V_533 )
V_533 = F_382 ( V_136 -> V_163 , V_114 ) ;
return V_533 ;
}
static inline void F_385 ( struct V_474 * V_136 ,
struct V_425 * V_114 , int V_431 ,
int V_436 , struct V_535 * V_536 ,
bool * V_537 )
{
unsigned long V_70 ;
int V_199 ;
memset ( V_536 , 0 , sizeof( * V_536 ) ) ;
F_329 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_108 ( V_199 ) ;
if ( V_436 )
V_70 = F_316 ( V_199 , V_431 ) ;
else
V_70 = F_315 ( V_199 , V_431 ) ;
V_536 -> V_538 += V_70 ;
V_536 -> V_539 += V_24 -> V_72 ;
if ( V_24 -> V_72 > 1 )
* V_537 = true ;
#ifdef F_386
V_536 -> V_104 += V_24 -> V_104 ;
V_536 -> V_106 += V_24 -> V_106 ;
#endif
V_536 -> V_540 += F_109 ( V_199 ) ;
if ( F_331 ( V_199 ) )
V_536 -> V_541 ++ ;
}
V_536 -> V_542 = V_114 -> V_437 -> V_438 ;
V_536 -> V_435 = ( V_536 -> V_538 * V_133 ) / V_536 -> V_542 ;
if ( V_536 -> V_539 )
V_536 -> V_543 = V_536 -> V_540 / V_536 -> V_539 ;
V_536 -> F_97 = V_114 -> F_97 ;
V_536 -> V_544 = F_383 ( V_114 ) ;
V_536 -> V_545 = F_384 ( V_136 , V_114 ) ;
if ( V_536 -> V_545 > V_536 -> V_539 )
V_536 -> V_546 = 1 ;
}
static bool F_387 ( struct V_474 * V_136 ,
struct V_508 * V_509 ,
struct V_425 * V_440 ,
struct V_535 * V_536 )
{
if ( V_536 -> V_435 <= V_509 -> V_513 . V_435 )
return false ;
if ( V_536 -> V_539 > V_536 -> V_545 )
return true ;
if ( V_536 -> V_544 )
return true ;
if ( ( V_136 -> V_163 -> V_208 & V_547 ) && V_536 -> V_539 &&
V_136 -> V_120 < F_388 ( V_440 ) ) {
if ( ! V_509 -> V_510 )
return true ;
if ( F_388 ( V_509 -> V_510 ) > F_388 ( V_440 ) )
return true ;
}
return false ;
}
static inline enum V_548 F_389 ( struct V_535 * V_536 )
{
if ( V_536 -> V_539 > V_536 -> V_104 )
return V_549 ;
if ( V_536 -> V_539 > V_536 -> V_106 )
return V_180 ;
return V_550 ;
}
static inline enum V_548 F_390 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_104 )
return V_549 ;
if ( V_24 -> V_72 > V_24 -> V_106 )
return V_180 ;
return V_550 ;
}
static inline enum V_548 F_389 ( struct V_535 * V_536 )
{
return V_550 ;
}
static inline enum V_548 F_390 ( struct V_24 * V_24 )
{
return V_549 ;
}
static inline void F_391 ( struct V_474 * V_136 , struct V_508 * V_509 )
{
struct V_162 * V_452 = V_136 -> V_163 -> V_452 ;
struct V_425 * V_440 = V_136 -> V_163 -> V_428 ;
struct V_535 V_551 ;
int V_431 , V_552 = 0 ;
bool V_537 = false ;
if ( V_452 && V_452 -> V_208 & V_553 )
V_552 = 1 ;
V_431 = F_373 ( V_136 -> V_163 , V_136 -> V_356 ) ;
do {
struct V_535 * V_536 = & V_551 ;
int V_436 ;
V_436 = F_120 ( V_136 -> V_120 , F_327 ( V_440 ) ) ;
if ( V_436 ) {
V_509 -> V_182 = V_440 ;
V_536 = & V_509 -> V_554 ;
if ( V_136 -> V_356 != V_504 ||
F_392 ( V_173 , V_440 -> V_437 -> V_530 ) )
F_381 ( V_136 -> V_163 , V_136 -> V_120 ) ;
}
F_385 ( V_136 , V_440 , V_431 , V_436 , V_536 ,
& V_537 ) ;
if ( V_436 )
goto V_555;
if ( V_552 && V_509 -> V_182 &&
V_509 -> V_554 . V_546 )
V_536 -> V_545 = F_135 ( V_536 -> V_545 , 1U ) ;
if ( F_387 ( V_136 , V_509 , V_440 , V_536 ) ) {
V_509 -> V_510 = V_440 ;
V_509 -> V_513 = * V_536 ;
}
V_555:
V_509 -> V_511 += V_536 -> V_538 ;
V_509 -> V_512 += V_536 -> V_542 ;
V_440 = V_440 -> V_58 ;
} while ( V_440 != V_136 -> V_163 -> V_428 );
if ( V_136 -> V_163 -> V_208 & V_478 )
V_136 -> V_548 = F_389 ( & V_509 -> V_513 ) ;
if ( ! V_136 -> V_163 -> V_34 ) {
if ( V_136 -> V_156 -> V_556 -> V_537 != V_537 )
V_136 -> V_156 -> V_556 -> V_537 = V_537 ;
}
}
static int F_393 ( struct V_474 * V_136 , struct V_508 * V_509 )
{
int V_557 ;
if ( ! ( V_136 -> V_163 -> V_208 & V_547 ) )
return 0 ;
if ( ! V_509 -> V_510 )
return 0 ;
V_557 = F_388 ( V_509 -> V_510 ) ;
if ( V_136 -> V_120 > V_557 )
return 0 ;
V_136 -> V_433 = F_111 (
V_509 -> V_513 . V_435 * V_509 -> V_513 . V_542 ,
V_133 ) ;
return 1 ;
}
static inline
void F_394 ( struct V_474 * V_136 , struct V_508 * V_509 )
{
unsigned long V_444 , V_558 = 0 , V_559 = 0 ;
unsigned int V_560 = 2 ;
unsigned long V_561 ;
struct V_535 * V_182 , * V_510 ;
V_182 = & V_509 -> V_554 ;
V_510 = & V_509 -> V_513 ;
if ( ! V_182 -> V_539 )
V_182 -> V_543 = F_317 ( V_136 -> V_120 ) ;
else if ( V_510 -> V_543 > V_182 -> V_543 )
V_560 = 1 ;
V_561 =
( V_510 -> V_543 * V_133 ) /
V_510 -> V_542 ;
if ( V_510 -> V_435 + V_561 >=
V_182 -> V_435 + ( V_561 * V_560 ) ) {
V_136 -> V_433 = V_510 -> V_543 ;
return;
}
V_558 += V_510 -> V_542 *
F_135 ( V_510 -> V_543 , V_510 -> V_435 ) ;
V_558 += V_182 -> V_542 *
F_135 ( V_182 -> V_543 , V_182 -> V_435 ) ;
V_558 /= V_133 ;
if ( V_510 -> V_435 > V_561 ) {
V_559 += V_510 -> V_542 *
F_135 ( V_510 -> V_543 ,
V_510 -> V_435 - V_561 ) ;
}
if ( V_510 -> V_435 * V_510 -> V_542 <
V_510 -> V_543 * V_133 ) {
V_444 = ( V_510 -> V_435 * V_510 -> V_542 ) /
V_182 -> V_542 ;
} else {
V_444 = ( V_510 -> V_543 * V_133 ) /
V_182 -> V_542 ;
}
V_559 += V_182 -> V_542 *
F_135 ( V_182 -> V_543 , V_182 -> V_435 + V_444 ) ;
V_559 /= V_133 ;
if ( V_559 > V_558 )
V_136 -> V_433 = V_510 -> V_543 ;
}
static inline void F_395 ( struct V_474 * V_136 , struct V_508 * V_509 )
{
unsigned long V_562 , V_563 = ~ 0UL ;
struct V_535 * V_182 , * V_510 ;
V_182 = & V_509 -> V_554 ;
V_510 = & V_509 -> V_513 ;
if ( V_510 -> V_544 ) {
V_510 -> V_543 =
F_135 ( V_510 -> V_543 , V_509 -> V_435 ) ;
}
if ( V_510 -> V_435 <= V_509 -> V_435 ||
V_182 -> V_435 >= V_509 -> V_435 ) {
V_136 -> V_433 = 0 ;
return F_394 ( V_136 , V_509 ) ;
}
if ( ! V_510 -> V_544 ) {
V_563 =
( V_510 -> V_539 - V_510 -> V_545 ) ;
V_563 *= ( V_564 * V_133 ) ;
V_563 /= V_510 -> V_542 ;
}
V_562 = F_135 ( V_510 -> V_435 - V_509 -> V_435 , V_563 ) ;
V_136 -> V_433 = F_135 (
V_562 * V_510 -> V_542 ,
( V_509 -> V_435 - V_182 -> V_435 ) * V_182 -> V_542
) / V_133 ;
if ( V_136 -> V_433 < V_510 -> V_543 )
return F_394 ( V_136 , V_509 ) ;
}
static struct V_425 * F_396 ( struct V_474 * V_136 )
{
struct V_535 * V_182 , * V_510 ;
struct V_508 V_509 ;
F_372 ( & V_509 ) ;
F_391 ( V_136 , & V_509 ) ;
V_182 = & V_509 . V_554 ;
V_510 = & V_509 . V_513 ;
if ( ( V_136 -> V_356 == V_565 || V_136 -> V_356 == V_504 ) &&
F_393 ( V_136 , & V_509 ) )
return V_509 . V_510 ;
if ( ! V_509 . V_510 || V_510 -> V_539 == 0 )
goto V_566;
V_509 . V_435 = ( V_133 * V_509 . V_511 )
/ V_509 . V_512 ;
if ( V_510 -> V_544 )
goto V_567;
if ( V_136 -> V_356 == V_504 && V_182 -> V_546 &&
! V_510 -> V_546 )
goto V_567;
if ( V_182 -> V_435 >= V_510 -> V_435 )
goto V_566;
if ( V_182 -> V_435 >= V_509 . V_435 )
goto V_566;
if ( V_136 -> V_356 == V_565 ) {
if ( ( V_182 -> V_541 < V_510 -> V_541 ) &&
V_510 -> V_539 <= V_510 -> F_97 )
goto V_566;
} else {
if ( 100 * V_510 -> V_435 <=
V_136 -> V_163 -> V_151 * V_182 -> V_435 )
goto V_566;
}
V_567:
F_395 ( V_136 , & V_509 ) ;
return V_509 . V_510 ;
V_566:
V_136 -> V_433 = 0 ;
return NULL ;
}
static struct V_24 * F_397 ( struct V_474 * V_136 ,
struct V_425 * V_114 )
{
struct V_24 * V_510 = NULL , * V_24 ;
unsigned long V_568 = 0 , V_569 = 1 ;
int V_199 ;
F_329 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_438 , V_533 , V_408 ;
enum V_548 V_570 ;
V_24 = F_108 ( V_199 ) ;
V_570 = F_390 ( V_24 ) ;
if ( V_570 > V_136 -> V_548 )
continue;
V_438 = F_110 ( V_199 ) ;
V_533 = F_111 ( V_438 , V_133 ) ;
if ( ! V_533 )
V_533 = F_382 ( V_136 -> V_163 , V_114 ) ;
V_408 = F_109 ( V_199 ) ;
if ( V_533 && V_24 -> V_72 == 1 && V_408 > V_136 -> V_433 )
continue;
if ( V_408 * V_569 > V_568 * V_438 ) {
V_568 = V_408 ;
V_569 = V_438 ;
V_510 = V_24 ;
}
}
return V_510 ;
}
static int F_398 ( struct V_474 * V_136 )
{
struct V_162 * V_163 = V_136 -> V_163 ;
if ( V_136 -> V_356 == V_504 ) {
if ( ( V_163 -> V_208 & V_547 ) && V_136 -> V_155 > V_136 -> V_120 )
return 1 ;
}
return F_14 ( V_163 -> V_491 > V_163 -> V_492 + 2 ) ;
}
static int F_399 ( struct V_474 * V_136 )
{
struct V_425 * V_440 = V_136 -> V_163 -> V_428 ;
struct V_571 * V_572 , * V_573 ;
int V_130 , V_574 = - 1 ;
if ( V_136 -> V_356 == V_504 )
return 1 ;
V_572 = F_327 ( V_440 ) ;
V_573 = F_400 ( V_440 ) ;
F_329 (cpu, sg_cpus, env->cpus) {
if ( ! F_120 ( V_130 , V_573 ) || ! F_331 ( V_130 ) )
continue;
V_574 = V_130 ;
break;
}
if ( V_574 == - 1 )
V_574 = F_401 ( V_440 ) ;
return V_574 == V_136 -> V_120 ;
}
static int F_402 ( int V_415 , struct V_24 * V_309 ,
struct V_162 * V_163 , enum V_514 V_356 ,
int * V_575 )
{
int V_576 , V_577 , V_578 = 0 ;
struct V_162 * V_579 = V_163 -> V_34 ;
struct V_425 * V_114 ;
struct V_24 * V_510 ;
unsigned long V_208 ;
struct V_571 * V_8 = F_403 ( V_580 ) ;
struct V_474 V_136 = {
. V_163 = V_163 ,
. V_120 = V_415 ,
. V_156 = V_309 ,
. V_484 = F_327 ( V_163 -> V_428 ) ,
. V_356 = V_356 ,
. V_500 = V_501 ,
. V_8 = V_8 ,
. V_548 = V_550 ,
} ;
if ( V_356 == V_504 )
V_136 . V_484 = NULL ;
F_404 ( V_8 , V_581 ) ;
F_230 ( V_163 , V_582 [ V_356 ] ) ;
V_583:
if ( ! F_399 ( & V_136 ) ) {
* V_575 = 0 ;
goto V_566;
}
V_114 = F_396 ( & V_136 ) ;
if ( ! V_114 ) {
F_230 ( V_163 , V_584 [ V_356 ] ) ;
goto V_566;
}
V_510 = F_397 ( & V_136 , V_114 ) ;
if ( ! V_510 ) {
F_230 ( V_163 , V_585 [ V_356 ] ) ;
goto V_566;
}
F_160 ( V_510 == V_136 . V_156 ) ;
F_69 ( V_163 , V_586 [ V_356 ] , V_136 . V_433 ) ;
V_576 = 0 ;
if ( V_510 -> V_72 > 1 ) {
V_136 . V_208 |= V_487 ;
V_136 . V_155 = V_510 -> V_130 ;
V_136 . V_154 = V_510 ;
V_136 . V_499 = F_135 ( V_587 , V_510 -> V_72 ) ;
V_588:
F_405 ( V_208 ) ;
F_406 ( V_136 . V_156 , V_510 ) ;
V_577 = F_362 ( & V_136 ) ;
V_576 += V_577 ;
F_407 ( V_136 . V_156 , V_510 ) ;
F_408 ( V_208 ) ;
if ( V_577 && V_136 . V_120 != F_261 () )
F_409 ( V_136 . V_120 ) ;
if ( V_136 . V_208 & V_502 ) {
V_136 . V_208 &= ~ V_502 ;
goto V_588;
}
if ( ( V_136 . V_208 & V_485 ) && V_136 . V_433 > 0 ) {
F_410 ( V_136 . V_120 , V_136 . V_8 ) ;
V_136 . V_156 = F_108 ( V_136 . V_486 ) ;
V_136 . V_120 = V_136 . V_486 ;
V_136 . V_208 &= ~ V_485 ;
V_136 . V_498 = 0 ;
V_136 . V_500 = V_501 ;
goto V_588;
}
if ( V_579 ) {
int * V_589 = & V_579 -> V_428 -> V_437 -> V_433 ;
if ( ( V_136 . V_208 & V_483 ) && V_136 . V_433 > 0 ) {
* V_589 = 1 ;
} else if ( * V_589 )
* V_589 = 0 ;
}
if ( F_14 ( V_136 . V_208 & V_487 ) ) {
F_410 ( F_27 ( V_510 ) , V_8 ) ;
if ( ! F_411 ( V_8 ) ) {
V_136 . V_498 = 0 ;
V_136 . V_500 = V_501 ;
goto V_583;
}
goto V_566;
}
}
if ( ! V_576 ) {
F_230 ( V_163 , V_590 [ V_356 ] ) ;
if ( V_356 != V_504 )
V_163 -> V_491 ++ ;
if ( F_398 ( & V_136 ) ) {
F_368 ( & V_510 -> V_198 , V_208 ) ;
if ( ! F_120 ( V_415 ,
F_121 ( V_510 -> V_45 ) ) ) {
F_369 ( & V_510 -> V_198 ,
V_208 ) ;
V_136 . V_208 |= V_487 ;
goto V_591;
}
if ( ! V_510 -> V_578 ) {
V_510 -> V_578 = 1 ;
V_510 -> V_592 = V_415 ;
V_578 = 1 ;
}
F_369 ( & V_510 -> V_198 , V_208 ) ;
if ( V_578 ) {
F_412 ( F_27 ( V_510 ) ,
V_593 , V_510 ,
& V_510 -> V_594 ) ;
}
V_163 -> V_491 = V_163 -> V_492 + 1 ;
}
} else
V_163 -> V_491 = 0 ;
if ( F_12 ( ! V_578 ) ) {
V_163 -> V_528 = V_163 -> V_595 ;
} else {
if ( V_163 -> V_528 < V_163 -> V_596 )
V_163 -> V_528 *= 2 ;
}
goto V_264;
V_566:
F_230 ( V_163 , V_597 [ V_356 ] ) ;
V_163 -> V_491 = 0 ;
V_591:
if ( ( ( V_136 . V_208 & V_487 ) &&
V_163 -> V_528 < V_598 ) ||
( V_163 -> V_528 < V_163 -> V_596 ) )
V_163 -> V_528 *= 2 ;
V_576 = 0 ;
V_264:
return V_576 ;
}
static inline unsigned long
F_413 ( struct V_162 * V_163 , int V_599 )
{
unsigned long V_170 = V_163 -> V_528 ;
if ( V_599 )
V_170 *= V_163 -> V_600 ;
V_170 = F_136 ( V_170 ) ;
V_170 = F_141 ( V_170 , 1UL , V_529 ) ;
return V_170 ;
}
static inline void
F_414 ( struct V_162 * V_163 , int V_599 , unsigned long * V_601 )
{
unsigned long V_170 , V_58 ;
V_170 = F_413 ( V_163 , V_599 ) ;
V_58 = V_163 -> V_602 + V_170 ;
if ( F_171 ( * V_601 , V_58 ) )
* V_601 = V_58 ;
}
static int F_221 ( struct V_24 * V_309 )
{
unsigned long V_601 = V_173 + V_171 ;
int V_415 = V_309 -> V_130 ;
struct V_162 * V_163 ;
int V_603 = 0 ;
T_2 V_604 = 0 ;
F_219 ( V_309 ) ;
V_309 -> V_605 = F_75 ( V_309 ) ;
if ( V_309 -> V_606 < V_476 ||
! V_309 -> V_556 -> V_537 ) {
F_118 () ;
V_163 = F_415 ( V_309 -> V_163 ) ;
if ( V_163 )
F_414 ( V_163 , 0 , & V_601 ) ;
F_123 () ;
goto V_264;
}
F_267 ( & V_309 -> V_198 ) ;
F_367 ( V_415 ) ;
F_118 () ;
F_336 (this_cpu, sd) {
int V_575 = 1 ;
T_2 V_607 , V_608 ;
if ( ! ( V_163 -> V_208 & V_450 ) )
continue;
if ( V_309 -> V_606 < V_604 + V_163 -> V_609 ) {
F_414 ( V_163 , 0 , & V_601 ) ;
break;
}
if ( V_163 -> V_208 & V_610 ) {
V_607 = F_260 ( V_415 ) ;
V_603 = F_402 ( V_415 , V_309 ,
V_163 , V_504 ,
& V_575 ) ;
V_608 = F_260 ( V_415 ) - V_607 ;
if ( V_608 > V_163 -> V_609 )
V_163 -> V_609 = V_608 ;
V_604 += V_608 ;
}
F_414 ( V_163 , 0 , & V_601 ) ;
if ( V_603 || V_309 -> V_72 > 0 )
break;
}
F_123 () ;
F_265 ( & V_309 -> V_198 ) ;
if ( V_604 > V_309 -> V_611 )
V_309 -> V_611 = V_604 ;
if ( V_309 -> V_40 . V_366 && ! V_603 )
V_603 = 1 ;
V_264:
if ( F_171 ( V_309 -> V_601 , V_601 ) )
V_309 -> V_601 = V_601 ;
if ( V_309 -> V_72 != V_309 -> V_40 . V_366 )
V_603 = - 1 ;
if ( V_603 ) {
F_220 ( V_309 ) ;
V_309 -> V_605 = 0 ;
}
return V_603 ;
}
static int V_593 ( void * V_362 )
{
struct V_24 * V_612 = V_362 ;
int V_557 = F_27 ( V_612 ) ;
int V_613 = V_612 -> V_592 ;
struct V_24 * V_614 = F_108 ( V_613 ) ;
struct V_162 * V_163 ;
F_416 ( & V_612 -> V_198 ) ;
if ( F_14 ( V_557 != F_261 () ||
! V_612 -> V_578 ) )
goto V_615;
if ( V_612 -> V_72 <= 1 )
goto V_615;
F_160 ( V_612 == V_614 ) ;
F_417 ( V_612 , V_614 ) ;
F_118 () ;
F_336 (target_cpu, sd) {
if ( ( V_163 -> V_208 & V_450 ) &&
F_120 ( V_557 , F_337 ( V_163 ) ) )
break;
}
if ( F_12 ( V_163 ) ) {
struct V_474 V_136 = {
. V_163 = V_163 ,
. V_120 = V_613 ,
. V_156 = V_614 ,
. V_155 = V_612 -> V_130 ,
. V_154 = V_612 ,
. V_356 = V_565 ,
} ;
F_230 ( V_163 , V_616 ) ;
if ( F_360 ( & V_136 ) )
F_230 ( V_163 , V_617 ) ;
else
F_230 ( V_163 , V_618 ) ;
}
F_123 () ;
F_418 ( V_612 , V_614 ) ;
V_615:
V_612 -> V_578 = 0 ;
F_419 ( & V_612 -> V_198 ) ;
return 0 ;
}
static inline int F_420 ( struct V_24 * V_24 )
{
return F_14 ( ! F_421 ( V_24 -> V_163 ) ) ;
}
static inline int F_422 ( void )
{
int V_619 = F_423 ( V_620 . V_621 ) ;
if ( V_619 < V_622 && F_331 ( V_619 ) )
return V_619 ;
return V_622 ;
}
static void F_424 ( void )
{
int V_623 ;
V_620 . V_601 ++ ;
V_623 = F_422 () ;
if ( V_623 >= V_622 )
return;
if ( F_425 ( V_624 , F_426 ( V_623 ) ) )
return;
F_427 ( V_623 ) ;
return;
}
static inline void F_428 ( int V_130 )
{
if ( F_14 ( F_429 ( V_625 , F_426 ( V_130 ) ) ) ) {
if ( F_12 ( F_120 ( V_130 , V_620 . V_621 ) ) ) {
F_410 ( V_130 , V_620 . V_621 ) ;
F_430 ( & V_620 . V_626 ) ;
}
F_431 ( V_625 , F_426 ( V_130 ) ) ;
}
}
static inline void F_432 ( void )
{
struct V_162 * V_163 ;
int V_130 = F_261 () ;
F_118 () ;
V_163 = F_127 ( F_128 ( V_627 , V_130 ) ) ;
if ( ! V_163 || ! V_163 -> V_628 )
goto V_159;
V_163 -> V_628 = 0 ;
F_433 ( & V_163 -> V_428 -> V_437 -> V_629 ) ;
V_159:
F_123 () ;
}
void F_434 ( void )
{
struct V_162 * V_163 ;
int V_130 = F_261 () ;
F_118 () ;
V_163 = F_127 ( F_128 ( V_627 , V_130 ) ) ;
if ( ! V_163 || V_163 -> V_628 )
goto V_159;
V_163 -> V_628 = 1 ;
F_430 ( & V_163 -> V_428 -> V_437 -> V_629 ) ;
V_159:
F_123 () ;
}
void F_435 ( int V_130 )
{
if ( ! F_436 ( V_130 ) )
return;
if ( F_429 ( V_625 , F_426 ( V_130 ) ) )
return;
if ( F_420 ( F_108 ( V_130 ) ) )
return;
F_437 ( V_130 , V_620 . V_621 ) ;
F_433 ( & V_620 . V_626 ) ;
F_438 ( V_625 , F_426 ( V_130 ) ) ;
}
static int F_439 ( struct V_630 * V_631 ,
unsigned long V_632 , void * V_633 )
{
switch ( V_632 & ~ V_634 ) {
case V_635 :
F_428 ( F_261 () ) ;
return V_636 ;
default:
return V_637 ;
}
}
void F_440 ( void )
{
V_529 = V_171 * F_6 () / 10 ;
}
static void F_441 ( struct V_24 * V_24 , enum V_514 V_356 )
{
int V_575 = 1 ;
int V_130 = V_24 -> V_130 ;
unsigned long V_170 ;
struct V_162 * V_163 ;
unsigned long V_601 = V_173 + 60 * V_171 ;
int F_414 = 0 ;
int V_638 , V_639 = 0 ;
T_2 V_640 = 0 ;
F_367 ( V_130 ) ;
F_118 () ;
F_336 (cpu, sd) {
if ( F_171 ( V_173 , V_163 -> V_641 ) ) {
V_163 -> V_609 =
( V_163 -> V_609 * 253 ) / 256 ;
V_163 -> V_641 = V_173 + V_171 ;
V_639 = 1 ;
}
V_640 += V_163 -> V_609 ;
if ( ! ( V_163 -> V_208 & V_450 ) )
continue;
if ( ! V_575 ) {
if ( V_639 )
continue;
break;
}
V_170 = F_413 ( V_163 , V_356 != V_565 ) ;
V_638 = V_163 -> V_208 & V_642 ;
if ( V_638 ) {
if ( ! F_442 ( & V_643 ) )
goto V_264;
}
if ( F_392 ( V_173 , V_163 -> V_602 + V_170 ) ) {
if ( F_402 ( V_130 , V_24 , V_163 , V_356 , & V_575 ) ) {
V_356 = F_331 ( V_130 ) ? V_565 : V_515 ;
}
V_163 -> V_602 = V_173 ;
V_170 = F_413 ( V_163 , V_356 != V_565 ) ;
}
if ( V_638 )
F_164 ( & V_643 ) ;
V_264:
if ( F_171 ( V_601 , V_163 -> V_602 + V_170 ) ) {
V_601 = V_163 -> V_602 + V_170 ;
F_414 = 1 ;
}
}
if ( V_639 ) {
V_24 -> V_611 =
F_68 ( ( T_2 ) V_476 , V_640 ) ;
}
F_123 () ;
if ( F_12 ( F_414 ) )
V_24 -> V_601 = V_601 ;
}
static void F_443 ( struct V_24 * V_309 , enum V_514 V_356 )
{
int V_415 = V_309 -> V_130 ;
struct V_24 * V_24 ;
int V_574 ;
if ( V_356 != V_565 ||
! F_429 ( V_624 , F_426 ( V_415 ) ) )
goto V_245;
F_107 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_574 == V_415 || ! F_331 ( V_574 ) )
continue;
if ( F_444 () )
break;
V_24 = F_108 ( V_574 ) ;
if ( F_392 ( V_173 , V_24 -> V_601 ) ) {
F_416 ( & V_24 -> V_198 ) ;
F_278 ( V_24 ) ;
F_445 ( V_24 ) ;
F_419 ( & V_24 -> V_198 ) ;
F_441 ( V_24 , V_565 ) ;
}
if ( F_171 ( V_309 -> V_601 , V_24 -> V_601 ) )
V_309 -> V_601 = V_24 -> V_601 ;
}
V_620 . V_601 = V_309 -> V_601 ;
V_245:
F_431 ( V_624 , F_426 ( V_415 ) ) ;
}
static inline int F_446 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_173 ;
struct V_162 * V_163 ;
struct V_532 * V_437 ;
int V_644 , V_130 = V_24 -> V_130 ;
if ( F_14 ( V_24 -> F_221 ) )
return 0 ;
F_432 () ;
F_428 ( V_130 ) ;
if ( F_12 ( ! F_208 ( & V_620 . V_626 ) ) )
return 0 ;
if ( F_174 ( V_81 , V_620 . V_601 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_645;
F_118 () ;
V_163 = F_127 ( F_128 ( V_627 , V_130 ) ) ;
if ( V_163 ) {
V_437 = V_163 -> V_428 -> V_437 ;
V_644 = F_208 ( & V_437 -> V_629 ) ;
if ( V_644 > 1 )
goto V_646;
}
V_163 = F_127 ( F_128 ( V_647 , V_130 ) ) ;
if ( V_163 && ( F_334 ( V_620 . V_621 ,
F_337 ( V_163 ) ) < V_130 ) )
goto V_646;
F_123 () ;
return 0 ;
V_646:
F_123 () ;
V_645:
return 1 ;
}
static void F_443 ( struct V_24 * V_309 , enum V_514 V_356 ) { }
static void F_447 ( struct V_648 * V_649 )
{
struct V_24 * V_309 = V_309 () ;
enum V_514 V_356 = V_309 -> F_221 ?
V_565 : V_515 ;
F_441 ( V_309 , V_356 ) ;
F_443 ( V_309 , V_356 ) ;
}
void F_448 ( struct V_24 * V_24 )
{
if ( F_14 ( F_420 ( V_24 ) ) )
return;
if ( F_392 ( V_173 , V_24 -> V_601 ) )
F_449 ( V_650 ) ;
#ifdef F_450
if ( F_446 ( V_24 ) )
F_424 () ;
#endif
}
static void F_451 ( struct V_24 * V_24 )
{
F_8 () ;
F_304 ( V_24 ) ;
}
static void F_452 ( struct V_24 * V_24 )
{
F_8 () ;
F_306 ( V_24 ) ;
}
static void F_453 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_337 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_248 ( V_25 , V_28 , V_337 ) ;
}
if ( V_229 )
F_184 ( V_24 , V_45 ) ;
F_209 ( V_24 , 1 ) ;
}
static void F_454 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_415 = F_261 () ;
struct V_24 * V_24 = V_309 () ;
unsigned long V_208 ;
F_368 ( & V_24 -> V_198 , V_208 ) ;
F_278 ( V_24 ) ;
V_25 = F_23 ( V_125 ) ;
V_45 = V_25 -> V_45 ;
F_118 () ;
F_455 ( V_29 , V_415 ) ;
F_123 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_231 ( V_25 , V_28 , 1 ) ;
if ( V_651 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_116 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_242 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_369 ( & V_24 -> V_198 , V_208 ) ;
}
static void
F_456 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_652 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_653 > V_652 )
F_242 ( V_24 ) ;
} else
F_354 ( V_24 , V_29 , 0 ) ;
}
static void F_457 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_29 -> V_76 && V_29 -> V_230 != V_654 ) {
F_231 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_188
if ( V_28 -> V_77 . V_78 ) {
F_200 ( V_28 ) ;
F_212 ( V_25 , V_28 -> V_77 . V_293 ) ;
}
#endif
}
static void F_458 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
#ifdef F_345
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! V_28 -> V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_242 ( V_24 ) ;
else
F_354 ( V_24 , V_29 , 0 ) ;
}
static void F_459 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_243 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_460 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_655 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_188
F_461 ( & V_25 -> V_292 , 1 ) ;
F_462 ( & V_25 -> V_306 , 0 ) ;
#endif
}
static void F_463 ( struct V_26 * V_29 , int V_76 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_28 -> V_85 || V_29 -> V_230 == V_656 ) )
V_76 = 1 ;
if ( ! V_76 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_464 ( V_29 , F_126 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_76 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_188
V_28 -> V_77 . V_78 = F_201 ( & V_25 -> V_292 ) ;
V_25 -> V_297 += V_28 -> V_77 . V_293 ;
#endif
}
}
void F_465 ( struct V_268 * V_33 )
{
int V_199 ;
F_302 ( F_263 ( V_33 ) ) ;
F_466 (i) {
if ( V_33 -> V_25 )
F_169 ( V_33 -> V_25 [ V_199 ] ) ;
if ( V_33 -> V_28 )
F_169 ( V_33 -> V_28 [ V_199 ] ) ;
}
F_169 ( V_33 -> V_25 ) ;
F_169 ( V_33 -> V_28 ) ;
}
int F_467 ( struct V_268 * V_33 , struct V_268 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_199 ;
V_33 -> V_25 = F_154 ( sizeof( V_25 ) * V_622 , V_214 ) ;
if ( ! V_33 -> V_25 )
goto V_657;
V_33 -> V_28 = F_154 ( sizeof( V_28 ) * V_622 , V_214 ) ;
if ( ! V_33 -> V_28 )
goto V_657;
V_33 -> V_272 = V_71 ;
F_296 ( F_263 ( V_33 ) ) ;
F_466 (i) {
V_25 = F_468 ( sizeof( struct V_25 ) ,
V_214 , F_99 ( V_199 ) ) ;
if ( ! V_25 )
goto V_657;
V_28 = F_468 ( sizeof( struct V_27 ) ,
V_214 , F_99 ( V_199 ) ) ;
if ( ! V_28 )
goto V_658;
F_460 ( V_25 ) ;
F_469 ( V_33 , V_25 , V_28 , V_199 , V_34 -> V_28 [ V_199 ] ) ;
}
return 1 ;
V_658:
F_169 ( V_25 ) ;
V_657:
return 0 ;
}
void F_470 ( struct V_268 * V_33 , int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_208 ;
if ( ! V_33 -> V_25 [ V_130 ] -> V_32 )
return;
F_368 ( & V_24 -> V_198 , V_208 ) ;
F_31 ( V_33 -> V_25 [ V_130 ] ) ;
F_369 ( & V_24 -> V_198 , V_208 ) ;
}
void F_469 ( struct V_268 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_130 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_299 ( V_25 ) ;
V_33 -> V_25 [ V_130 ] = V_25 ;
V_33 -> V_28 [ V_130 ] = V_28 ;
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
int F_471 ( struct V_268 * V_33 , unsigned long V_272 )
{
int V_199 ;
unsigned long V_208 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_167 ;
V_272 = F_141 ( V_272 , F_210 ( V_273 ) , F_210 ( V_659 ) ) ;
F_472 ( & V_660 ) ;
if ( V_33 -> V_272 == V_272 )
goto V_442;
V_33 -> V_272 = V_272 ;
F_466 (i) {
struct V_24 * V_24 = F_108 ( V_199 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_199 ] ;
F_368 ( & V_24 -> V_198 , V_208 ) ;
F_278 ( V_24 ) ;
F_61 (se)
F_195 ( F_25 ( V_28 ) ) ;
F_369 ( & V_24 -> V_198 , V_208 ) ;
}
V_442:
F_473 ( & V_660 ) ;
return 0 ;
}
void F_465 ( struct V_268 * V_33 ) { }
int F_467 ( struct V_268 * V_33 , struct V_268 * V_34 )
{
return 1 ;
}
void F_470 ( struct V_268 * V_33 , int V_130 ) { }
static unsigned int F_474 ( struct V_24 * V_24 , struct V_26 * V_661 )
{
struct V_27 * V_28 = & V_661 -> V_28 ;
unsigned int V_662 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_662 = F_475 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_662 ;
}
void F_476 ( struct V_663 * V_664 , int V_130 )
{
struct V_25 * V_25 ;
F_118 () ;
F_305 (cpu_rq(cpu), cfs_rq)
F_477 ( V_664 , V_130 , V_25 ) ;
F_123 () ;
}
T_12 void F_478 ( void )
{
#ifdef F_188
F_479 ( V_650 , F_447 ) ;
#ifdef F_450
V_620 . V_601 = V_173 ;
F_480 ( & V_620 . V_621 , V_665 ) ;
F_481 ( F_439 , 0 ) ;
#endif
#endif
}
