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
V_129 -> V_70 = ( V_129 -> V_70 * V_132 ) / V_129 -> V_131 ;
V_129 -> V_133 =
F_111 ( V_129 -> V_131 , V_132 ) ;
V_129 -> V_134 = ( V_129 -> V_72 < V_129 -> V_133 ) ;
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
long V_143 , long V_144 ,
struct V_135 * V_136 )
{
long V_145 , V_146 ;
if ( V_144 < V_143 )
F_116 ( V_144 , V_143 ) ;
V_145 = V_144 * 100 - V_143 * V_136 -> V_147 ;
if ( V_145 <= 0 )
return false ;
if ( V_142 < V_141 )
F_116 ( V_142 , V_141 ) ;
V_146 = V_142 * 100 - V_141 * V_136 -> V_147 ;
return ( V_145 > V_146 ) ;
}
static void F_117 ( struct V_135 * V_136 ,
long V_148 , long V_149 )
{
struct V_24 * V_150 = F_108 ( V_136 -> V_151 ) ;
struct V_24 * V_152 = F_108 ( V_136 -> V_120 ) ;
struct V_26 * V_153 ;
long V_141 , V_143 ;
long V_142 , V_144 ;
long V_70 ;
long V_137 = ( V_149 > 0 ) ? V_149 : V_148 ;
F_118 () ;
V_153 = F_119 ( V_152 -> V_45 ) ;
if ( V_153 -> V_126 == 0 )
V_153 = NULL ;
if ( V_153 ) {
if ( ! F_120 ( V_136 -> V_151 , F_121 ( V_153 ) ) )
goto V_154;
if ( V_153 -> V_107 == V_136 -> V_29 -> V_107 ) {
V_137 = V_148 + F_96 ( V_153 , V_136 -> V_119 ) -
F_96 ( V_153 , V_136 -> V_122 ) ;
if ( V_153 -> V_107 )
V_137 -= V_137 / 16 ;
} else {
if ( V_136 -> V_29 -> V_107 )
V_137 = V_149 ;
else
V_137 = V_148 ;
if ( V_153 -> V_107 )
V_137 += F_97 ( V_153 , V_136 -> V_119 ) -
F_97 ( V_153 , V_136 -> V_122 ) ;
else
V_137 += F_96 ( V_153 , V_136 -> V_119 ) -
F_96 ( V_153 , V_136 -> V_122 ) ;
}
}
if ( V_137 < V_136 -> V_139 )
goto V_154;
if ( ! V_153 ) {
if ( V_136 -> V_155 . V_134 &&
! V_136 -> V_156 . V_134 )
goto V_154;
goto V_157;
}
if ( V_150 -> V_72 == 1 && V_152 -> V_72 == 1 )
goto V_158;
V_157:
V_142 = V_136 -> V_156 . V_70 ;
V_141 = V_136 -> V_155 . V_70 ;
V_70 = F_122 ( V_136 -> V_29 ) ;
V_144 = V_142 + V_70 ;
V_143 = V_141 - V_70 ;
if ( V_153 ) {
V_70 = F_122 ( V_153 ) ;
V_144 -= V_70 ;
V_143 += V_70 ;
}
if ( F_115 ( V_141 , V_142 ,
V_143 , V_144 , V_136 ) )
goto V_154;
V_158:
F_112 ( V_136 , V_153 , V_137 ) ;
V_154:
F_123 () ;
}
static void F_124 ( struct V_135 * V_136 ,
long V_148 , long V_149 )
{
int V_130 ;
F_107 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_120 ( V_130 , F_121 ( V_136 -> V_29 ) ) )
continue;
V_136 -> V_120 = V_130 ;
F_117 ( V_136 , V_148 , V_149 ) ;
}
}
static int F_125 ( struct V_26 * V_29 )
{
struct V_135 V_136 = {
. V_29 = V_29 ,
. V_151 = F_126 ( V_29 ) ,
. V_119 = F_89 ( V_29 ) ,
. V_147 = 112 ,
. V_138 = NULL ,
. V_139 = 0 ,
. V_140 = - 1
} ;
struct V_159 * V_160 ;
unsigned long V_161 , V_162 ;
int V_109 , V_66 ;
long V_148 , V_149 ;
F_118 () ;
V_160 = F_127 ( F_128 ( V_163 , V_136 . V_151 ) ) ;
if ( V_160 )
V_136 . V_147 = 100 + ( V_160 -> V_147 - 100 ) / 2 ;
F_123 () ;
if ( F_14 ( ! V_160 ) ) {
V_29 -> V_105 = F_89 ( V_29 ) ;
return - V_164 ;
}
V_161 = F_96 ( V_29 , V_136 . V_119 ) ;
V_162 = F_97 ( V_29 , V_136 . V_119 ) ;
F_106 ( & V_136 . V_155 , V_136 . V_119 ) ;
V_136 . V_122 = V_29 -> V_105 ;
V_148 = F_96 ( V_29 , V_136 . V_122 ) - V_161 ;
V_149 = F_97 ( V_29 , V_136 . V_122 ) - V_162 ;
F_106 ( & V_136 . V_156 , V_136 . V_122 ) ;
if ( V_136 . V_156 . V_134 )
F_124 ( & V_136 , V_148 , V_149 ) ;
if ( V_136 . V_140 == - 1 ) {
F_129 (nid) {
if ( V_109 == V_136 . V_119 || V_109 == V_29 -> V_105 )
continue;
V_148 = F_96 ( V_29 , V_109 ) - V_161 ;
V_149 = F_97 ( V_29 , V_109 ) - V_162 ;
if ( V_148 < 0 && V_149 < 0 )
continue;
V_136 . V_122 = V_109 ;
F_106 ( & V_136 . V_156 , V_136 . V_122 ) ;
F_124 ( & V_136 , V_148 , V_149 ) ;
}
}
if ( V_136 . V_140 == - 1 )
return - V_165 ;
if ( V_29 -> V_107 && F_105 ( V_136 . V_122 , V_29 -> V_107 -> V_127 ) )
F_130 ( V_29 , V_136 . V_122 ) ;
V_29 -> V_166 = F_85 ( V_29 ) ;
if ( V_136 . V_138 == NULL ) {
V_66 = F_131 ( V_29 , V_136 . V_140 ) ;
if ( V_66 != 0 )
F_132 ( V_29 , V_136 . V_151 , V_136 . V_140 ) ;
return V_66 ;
}
V_66 = F_133 ( V_29 , V_136 . V_138 ) ;
if ( V_66 != 0 )
F_132 ( V_29 , V_136 . V_151 , F_126 ( V_136 . V_138 ) ) ;
F_113 ( V_136 . V_138 ) ;
return V_66 ;
}
static void F_134 ( struct V_26 * V_29 )
{
unsigned long V_167 = V_168 ;
if ( F_14 ( V_29 -> V_105 == - 1 || ! V_29 -> V_112 ) )
return;
V_167 = F_135 ( V_167 , F_136 ( V_29 -> V_166 ) / 16 ) ;
V_29 -> V_169 = V_170 + V_167 ;
if ( F_89 ( V_29 ) == V_29 -> V_105 )
return;
F_125 ( V_29 ) ;
}
static void F_137 ( struct V_107 * V_107 )
{
unsigned long V_113 , V_171 = 0 ;
int V_109 ;
F_129 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( V_113 > V_171 )
V_171 = V_113 ;
}
F_129 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( ! F_105 ( V_109 , V_107 -> V_127 ) ) {
if ( V_113 > V_171 * 6 / 16 )
F_138 ( V_109 , V_107 -> V_127 ) ;
} else if ( V_113 < V_171 * 3 / 16 )
F_139 ( V_109 , V_107 -> V_127 ) ;
}
}
static void F_140 ( struct V_26 * V_29 ,
unsigned long V_172 , unsigned long V_173 )
{
unsigned int V_174 ;
int V_175 ;
int V_176 ;
unsigned long V_177 = V_29 -> V_178 [ 0 ] ;
unsigned long V_179 = V_29 -> V_178 [ 1 ] ;
if ( V_179 + V_172 == 0 ) {
V_29 -> V_166 = F_135 ( V_29 -> V_180 ,
V_29 -> V_166 << 1 ) ;
V_29 -> V_96 -> V_181 = V_170 +
F_136 ( V_29 -> V_166 ) ;
return;
}
V_174 = F_56 ( V_29 -> V_166 , V_182 ) ;
V_175 = ( V_179 * V_182 ) / ( V_179 + V_177 ) ;
if ( V_175 >= V_183 ) {
int V_184 = V_175 - V_183 ;
if ( ! V_184 )
V_184 = 1 ;
V_176 = V_184 * V_174 ;
} else {
V_176 = - ( V_183 - V_175 ) * V_174 ;
V_175 = F_56 ( V_173 * V_182 , ( V_173 + V_172 ) ) ;
V_176 = ( V_176 * V_175 ) / V_182 ;
}
V_29 -> V_166 = F_141 ( V_29 -> V_166 + V_176 ,
F_85 ( V_29 ) , F_87 ( V_29 ) ) ;
memset ( V_29 -> V_178 , 0 , sizeof( V_29 -> V_178 ) ) ;
}
static T_2 F_142 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_185 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_185 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_186 ) {
V_42 = V_185 - V_29 -> V_187 ;
* V_73 = V_81 - V_29 -> V_186 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_79 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_187 = V_185 ;
V_29 -> V_186 = V_81 ;
return V_42 ;
}
static void F_143 ( struct V_26 * V_29 )
{
int V_188 , V_109 , V_189 = - 1 , V_190 = - 1 ;
unsigned long V_171 = 0 , V_191 = 0 ;
unsigned long V_192 [ 2 ] = { 0 , 0 } ;
unsigned long V_116 ;
T_2 V_185 , V_73 ;
T_8 * V_193 = NULL ;
V_188 = F_119 ( V_29 -> V_96 -> V_194 ) ;
if ( V_29 -> V_194 == V_188 )
return;
V_29 -> V_194 = V_188 ;
V_29 -> V_180 = F_87 ( V_29 ) ;
V_116 = V_29 -> V_178 [ 0 ] +
V_29 -> V_178 [ 1 ] ;
V_185 = F_142 ( V_29 , & V_73 ) ;
if ( V_29 -> V_107 ) {
V_193 = & V_29 -> V_107 -> V_195 ;
F_144 ( V_193 ) ;
}
F_129 (nid) {
unsigned long V_113 = 0 , F_94 = 0 ;
int V_110 , V_196 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
long V_176 , V_197 , V_198 ;
V_196 = F_92 ( V_109 , V_110 ) ;
V_176 = V_29 -> V_199 [ V_196 ] - V_29 -> V_112 [ V_196 ] / 2 ;
V_192 [ V_110 ] += V_29 -> V_199 [ V_196 ] ;
V_29 -> V_199 [ V_196 ] = 0 ;
V_198 = F_145 ( V_185 << 16 , V_73 + 1 ) ;
V_198 = ( V_198 * V_29 -> V_200 [ V_196 ] ) /
( V_116 + 1 ) ;
V_197 = V_198 - V_29 -> V_201 [ V_196 ] / 2 ;
V_29 -> V_200 [ V_196 ] = 0 ;
V_29 -> V_112 [ V_196 ] += V_176 ;
V_29 -> V_201 [ V_196 ] += V_197 ;
V_113 += V_29 -> V_112 [ V_196 ] ;
V_29 -> V_117 += V_176 ;
if ( V_29 -> V_107 ) {
V_29 -> V_107 -> V_113 [ V_196 ] += V_176 ;
V_29 -> V_107 -> V_115 [ V_196 ] += V_197 ;
V_29 -> V_107 -> V_116 += V_176 ;
F_94 += V_29 -> V_107 -> V_113 [ V_196 ] ;
}
}
if ( V_113 > V_171 ) {
V_171 = V_113 ;
V_189 = V_109 ;
}
if ( F_94 > V_191 ) {
V_191 = F_94 ;
V_190 = V_109 ;
}
}
F_140 ( V_29 , V_192 [ 0 ] , V_192 [ 1 ] ) ;
if ( V_29 -> V_107 ) {
F_137 ( V_29 -> V_107 ) ;
if ( V_189 != V_190 ) {
unsigned long V_4 , V_202 = 0 ;
F_129 (nid) {
V_4 = F_96 ( V_29 , V_109 ) + F_97 ( V_29 , V_109 ) ;
if ( V_4 > V_202 ) {
V_202 = V_4 ;
V_189 = V_109 ;
}
}
}
F_146 ( V_193 ) ;
}
if ( V_171 && V_189 != V_29 -> V_105 ) {
F_130 ( V_29 , V_189 ) ;
F_134 ( V_29 ) ;
}
}
static inline int F_147 ( struct V_107 * V_30 )
{
return F_148 ( & V_30 -> V_203 ) ;
}
static inline void F_149 ( struct V_107 * V_30 )
{
if ( F_150 ( & V_30 -> V_203 ) )
F_151 ( V_30 , V_204 ) ;
}
static void F_152 ( struct V_26 * V_29 , int V_205 , int V_206 ,
int * V_110 )
{
struct V_107 * V_30 , * V_207 ;
struct V_26 * V_208 ;
bool V_209 = false ;
int V_130 = F_153 ( V_205 ) ;
int V_196 ;
if ( F_14 ( ! V_29 -> V_107 ) ) {
unsigned int V_210 = sizeof( struct V_107 ) +
4 * V_211 *sizeof( unsigned long ) ;
V_30 = F_154 ( V_210 , V_212 | V_213 ) ;
if ( ! V_30 )
return;
F_155 ( & V_30 -> V_203 , 1 ) ;
F_156 ( & V_30 -> V_195 ) ;
F_157 ( & V_30 -> V_214 ) ;
V_30 -> V_108 = V_29 -> V_126 ;
V_30 -> V_115 = V_30 -> V_113 + V_111 *
V_211 ;
F_138 ( F_89 ( V_125 ) , V_30 -> V_127 ) ;
for ( V_196 = 0 ; V_196 < V_215 * V_211 ; V_196 ++ )
V_30 -> V_113 [ V_196 ] = V_29 -> V_112 [ V_196 ] ;
V_30 -> V_116 = V_29 -> V_117 ;
F_158 ( & V_29 -> V_216 , & V_30 -> V_214 ) ;
V_30 -> V_217 ++ ;
F_159 ( V_29 -> V_107 , V_30 ) ;
}
F_118 () ;
V_208 = F_119 ( F_108 ( V_130 ) -> V_45 ) ;
if ( ! F_104 ( V_208 , V_205 ) )
goto V_218;
V_30 = F_127 ( V_208 -> V_107 ) ;
if ( ! V_30 )
goto V_218;
V_207 = V_29 -> V_107 ;
if ( V_30 == V_207 )
goto V_218;
if ( V_207 -> V_217 > V_30 -> V_217 )
goto V_218;
if ( V_207 -> V_217 == V_30 -> V_217 && V_207 > V_30 )
goto V_218;
if ( V_208 -> V_96 == V_125 -> V_96 )
V_209 = true ;
if ( V_206 & V_219 )
V_209 = true ;
* V_110 = ! V_209 ;
if ( V_209 && ! F_147 ( V_30 ) )
goto V_218;
F_123 () ;
if ( ! V_209 )
return;
F_160 ( F_161 () ) ;
F_162 ( & V_207 -> V_195 , & V_30 -> V_195 ) ;
for ( V_196 = 0 ; V_196 < V_215 * V_211 ; V_196 ++ ) {
V_207 -> V_113 [ V_196 ] -= V_29 -> V_112 [ V_196 ] ;
V_30 -> V_113 [ V_196 ] += V_29 -> V_112 [ V_196 ] ;
}
V_207 -> V_116 -= V_29 -> V_117 ;
V_30 -> V_116 += V_29 -> V_117 ;
F_163 ( & V_29 -> V_216 , & V_30 -> V_214 ) ;
V_207 -> V_217 -- ;
V_30 -> V_217 ++ ;
F_164 ( & V_207 -> V_195 ) ;
F_146 ( & V_30 -> V_195 ) ;
F_159 ( V_29 -> V_107 , V_30 ) ;
F_149 ( V_207 ) ;
return;
V_218:
F_123 () ;
return;
}
void F_165 ( struct V_26 * V_29 )
{
struct V_107 * V_30 = V_29 -> V_107 ;
void * V_220 = V_29 -> V_112 ;
unsigned long V_206 ;
int V_196 ;
if ( V_30 ) {
F_166 ( & V_30 -> V_195 , V_206 ) ;
for ( V_196 = 0 ; V_196 < V_215 * V_211 ; V_196 ++ )
V_30 -> V_113 [ V_196 ] -= V_29 -> V_112 [ V_196 ] ;
V_30 -> V_116 -= V_29 -> V_117 ;
F_167 ( & V_29 -> V_216 ) ;
V_30 -> V_217 -- ;
F_168 ( & V_30 -> V_195 , V_206 ) ;
F_159 ( V_29 -> V_107 , NULL ) ;
F_149 ( V_30 ) ;
}
V_29 -> V_112 = NULL ;
V_29 -> V_199 = NULL ;
V_29 -> V_201 = NULL ;
V_29 -> V_200 = NULL ;
F_169 ( V_220 ) ;
}
void F_170 ( int V_123 , int V_221 , int V_222 , int V_206 )
{
struct V_26 * V_29 = V_125 ;
bool V_223 = V_206 & V_224 ;
int V_225 = F_89 ( V_125 ) ;
int V_179 = ! ! ( V_206 & V_226 ) ;
int V_110 ;
if ( ! V_227 )
return;
if ( ! V_29 -> V_96 )
return;
if ( V_29 -> V_228 == V_229 )
return;
if ( F_14 ( ! V_29 -> V_112 ) ) {
int V_210 = sizeof( * V_29 -> V_112 ) *
V_230 * V_211 ;
V_29 -> V_112 = F_154 ( V_210 , V_212 | V_213 ) ;
if ( ! V_29 -> V_112 )
return;
F_160 ( V_29 -> V_199 ) ;
V_29 -> V_201 = V_29 -> V_112 + ( 2 * V_211 ) ;
V_29 -> V_199 = V_29 -> V_112 + ( 4 * V_211 ) ;
V_29 -> V_200 = V_29 -> V_112 + ( 6 * V_211 ) ;
V_29 -> V_117 = 0 ;
memset ( V_29 -> V_178 , 0 , sizeof( V_29 -> V_178 ) ) ;
}
if ( F_14 ( V_123 == ( - 1 & V_231 ) ) ) {
V_110 = 1 ;
} else {
V_110 = F_104 ( V_29 , V_123 ) ;
if ( ! V_110 && ! ( V_206 & V_232 ) )
F_152 ( V_29 , V_123 , V_206 , & V_110 ) ;
}
if ( ! V_110 && ! V_179 && V_29 -> V_107 &&
F_105 ( V_225 , V_29 -> V_107 -> V_127 ) &&
F_105 ( V_221 , V_29 -> V_107 -> V_127 ) )
V_179 = 1 ;
F_143 ( V_29 ) ;
if ( F_171 ( V_170 , V_29 -> V_169 ) )
F_134 ( V_29 ) ;
if ( V_223 )
V_29 -> V_233 += V_222 ;
V_29 -> V_199 [ F_92 ( V_221 , V_110 ) ] += V_222 ;
V_29 -> V_200 [ F_92 ( V_225 , V_110 ) ] += V_222 ;
V_29 -> V_178 [ V_179 ] += V_222 ;
}
static void F_172 ( struct V_26 * V_29 )
{
F_119 ( V_29 -> V_96 -> V_194 ) ++ ;
V_29 -> V_96 -> V_234 = 0 ;
}
void F_173 ( struct V_235 * V_236 )
{
unsigned long V_237 , V_238 , V_81 = V_170 ;
struct V_26 * V_29 = V_125 ;
struct V_239 * V_96 = V_29 -> V_96 ;
struct V_240 * V_241 ;
unsigned long V_242 , V_243 ;
unsigned long V_244 = 0 ;
long V_222 ;
F_20 ( V_29 != F_22 ( V_236 , struct V_26 , V_245 ) ) ;
V_236 -> V_58 = V_236 ;
if ( V_29 -> V_206 & V_246 )
return;
if ( ! V_96 -> V_181 ) {
V_96 -> V_181 = V_81 +
F_136 ( V_247 ) ;
}
V_237 = V_96 -> V_181 ;
if ( F_174 ( V_81 , V_237 ) )
return;
if ( V_29 -> V_166 == 0 ) {
V_29 -> V_180 = F_87 ( V_29 ) ;
V_29 -> V_166 = F_85 ( V_29 ) ;
}
V_238 = V_81 + F_136 ( V_29 -> V_166 ) ;
if ( F_175 ( & V_96 -> V_181 , V_237 , V_238 ) != V_237 )
return;
V_29 -> V_248 += 2 * V_249 ;
V_242 = V_96 -> V_234 ;
V_222 = V_94 ;
V_222 <<= 20 - V_95 ;
if ( ! V_222 )
return;
F_176 ( & V_96 -> V_250 ) ;
V_241 = F_177 ( V_96 , V_242 ) ;
if ( ! V_241 ) {
F_172 ( V_29 ) ;
V_242 = 0 ;
V_241 = V_96 -> V_251 ;
}
for (; V_241 ; V_241 = V_241 -> V_252 ) {
if ( ! F_178 ( V_241 ) || ! F_179 ( V_29 , V_241 ) )
continue;
if ( ! V_241 -> V_253 ||
( V_241 -> V_254 && ( V_241 -> V_255 & ( V_256 | V_257 ) ) == ( V_256 ) ) )
continue;
if ( ! ( V_241 -> V_255 & ( V_256 | V_258 | V_257 ) ) )
continue;
do {
V_242 = F_68 ( V_242 , V_241 -> V_259 ) ;
V_243 = F_180 ( V_242 + ( V_222 << V_95 ) , V_260 ) ;
V_243 = F_135 ( V_243 , V_241 -> V_261 ) ;
V_244 += F_181 ( V_241 , V_242 , V_243 ) ;
if ( V_244 )
V_222 -= ( V_243 - V_242 ) >> V_95 ;
V_242 = V_243 ;
if ( V_222 <= 0 )
goto V_262;
F_182 () ;
} while ( V_243 != V_241 -> V_261 );
}
V_262:
if ( V_241 )
V_96 -> V_234 = V_242 ;
else
F_172 ( V_29 ) ;
F_183 ( & V_96 -> V_250 ) ;
}
void F_184 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_235 * V_236 = & V_45 -> V_245 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_206 & V_246 ) || V_236 -> V_58 != V_236 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_166 * V_263 ;
if ( V_81 - V_45 -> V_248 > V_73 ) {
if ( ! V_45 -> V_248 )
V_45 -> V_166 = F_85 ( V_45 ) ;
V_45 -> V_248 += V_73 ;
if ( ! F_174 ( V_170 , V_45 -> V_96 -> V_181 ) ) {
F_185 ( V_236 , F_173 ) ;
F_186 ( V_45 , V_236 , true ) ;
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
F_158 ( & V_28 -> V_264 , & V_24 -> V_265 ) ;
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
F_190 ( & V_28 -> V_264 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_191 ( struct V_266 * V_33 , struct V_25 * V_25 )
{
long V_267 ;
V_267 = F_192 ( & V_33 -> V_268 ) ;
V_267 -= V_25 -> V_269 ;
V_267 += V_25 -> V_70 . V_4 ;
return V_267 ;
}
static long F_193 ( struct V_25 * V_25 , struct V_266 * V_33 )
{
long V_267 , V_70 , V_270 ;
V_267 = F_191 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_270 = ( V_33 -> V_270 * V_70 ) ;
if ( V_267 )
V_270 /= V_267 ;
if ( V_270 < V_271 )
V_270 = V_271 ;
if ( V_270 > V_33 -> V_270 )
V_270 = V_33 -> V_270 ;
return V_270 ;
}
static inline long F_193 ( struct V_25 * V_25 , struct V_266 * V_33 )
{
return V_33 -> V_270 ;
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
struct V_266 * V_33 ;
struct V_27 * V_28 ;
long V_270 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_196 ( V_25 ) )
return;
#ifndef F_188
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_270 ) )
return;
#endif
V_270 = F_193 ( V_25 , V_33 ) ;
F_194 ( F_24 ( V_28 ) , V_28 , V_270 ) ;
}
static inline void F_195 ( struct V_25 * V_25 )
{
}
static T_9 T_2 F_197 ( T_2 V_272 , T_2 V_273 )
{
unsigned int V_274 ;
if ( ! V_273 )
return V_272 ;
else if ( F_14 ( V_273 > V_275 * 63 ) )
return 0 ;
V_274 = V_273 ;
if ( F_14 ( V_274 >= V_275 ) ) {
V_272 >>= V_274 / V_275 ;
V_274 %= V_275 ;
}
V_272 *= V_276 [ V_274 ] ;
return V_272 >> 32 ;
}
static V_23 F_198 ( T_2 V_273 )
{
V_23 V_277 = 0 ;
if ( F_12 ( V_273 <= V_275 ) )
return V_278 [ V_273 ] ;
else if ( F_14 ( V_273 >= V_279 ) )
return V_280 ;
do {
V_277 /= 2 ;
V_277 += V_278 [ V_275 ] ;
V_273 -= V_275 ;
} while ( V_273 > V_275 );
V_277 = F_197 ( V_277 , V_273 ) ;
return V_277 + V_278 [ V_273 ] ;
}
static T_9 int F_199 ( T_2 V_81 ,
struct V_281 * V_282 ,
int V_283 )
{
T_2 V_42 , V_284 ;
V_23 V_285 ;
int V_286 , V_287 = 0 ;
V_42 = V_81 - V_282 -> V_288 ;
if ( ( T_3 ) V_42 < 0 ) {
V_282 -> V_288 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_282 -> V_288 = V_81 ;
V_286 = V_282 -> V_80 % 1024 ;
if ( V_42 + V_286 >= 1024 ) {
V_287 = 1 ;
V_286 = 1024 - V_286 ;
if ( V_283 )
V_282 -> V_79 += V_286 ;
V_282 -> V_80 += V_286 ;
V_42 -= V_286 ;
V_284 = V_42 / 1024 ;
V_42 %= 1024 ;
V_282 -> V_79 = F_197 ( V_282 -> V_79 ,
V_284 + 1 ) ;
V_282 -> V_80 = F_197 ( V_282 -> V_80 ,
V_284 + 1 ) ;
V_285 = F_198 ( V_284 ) ;
if ( V_283 )
V_282 -> V_79 += V_285 ;
V_282 -> V_80 += V_285 ;
}
if ( V_283 )
V_282 -> V_79 += V_42 ;
V_282 -> V_80 += V_42 ;
return V_287 ;
}
static inline T_2 F_200 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_289 = F_201 ( & V_25 -> V_290 ) ;
V_289 -= V_28 -> V_77 . V_78 ;
if ( ! V_289 )
return 0 ;
V_28 -> V_77 . V_291 = F_197 ( V_28 -> V_77 . V_291 , V_289 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_289 ;
}
static inline void F_202 ( struct V_25 * V_25 ,
int V_292 )
{
struct V_266 * V_33 = V_25 -> V_33 ;
long V_293 ;
V_293 = V_25 -> V_294 + V_25 -> V_295 ;
V_293 -= V_25 -> V_269 ;
if ( V_292 || abs ( V_293 ) > V_25 -> V_269 / 8 ) {
F_203 ( V_293 , & V_33 -> V_268 ) ;
V_25 -> V_269 += V_293 ;
}
}
static inline void F_204 ( struct V_281 * V_282 ,
struct V_25 * V_25 )
{
struct V_266 * V_33 = V_25 -> V_33 ;
long V_277 ;
V_277 = F_205 ( ( T_2 ) V_282 -> V_79 << V_296 ,
V_282 -> V_80 + 1 ) ;
V_277 -= V_25 -> V_297 ;
if ( abs ( V_277 ) > V_25 -> V_297 / 64 ) {
F_206 ( V_277 , & V_33 -> V_298 ) ;
V_25 -> V_297 += V_277 ;
}
}
static inline void F_207 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_266 * V_33 = V_25 -> V_33 ;
int V_298 ;
T_2 V_277 ;
V_277 = V_25 -> V_269 * V_33 -> V_270 ;
V_28 -> V_77 . V_291 = F_205 ( V_277 ,
F_192 ( & V_33 -> V_268 ) + 1 ) ;
V_298 = F_208 ( & V_33 -> V_298 ) ;
if ( V_298 < V_71 ) {
V_28 -> V_77 . V_291 *= V_298 ;
V_28 -> V_77 . V_291 >>= V_296 ;
}
}
static inline void F_209 ( struct V_24 * V_24 , int V_283 )
{
F_199 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_283 ) ;
F_204 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_202 ( struct V_25 * V_25 ,
int V_292 ) {}
static inline void F_204 ( struct V_281 * V_282 ,
struct V_25 * V_25 ) {}
static inline void F_207 ( struct V_27 * V_28 ) {}
static inline void F_209 ( struct V_24 * V_24 , int V_283 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_277 ;
V_277 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_277 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_291 = F_210 ( V_277 ) ;
}
static long F_211 ( struct V_27 * V_28 )
{
long V_299 = V_28 -> V_77 . V_291 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_204 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_207 ( V_28 ) ;
}
return V_28 -> V_77 . V_291 - V_299 ;
}
static inline void F_212 ( struct V_25 * V_25 ,
long V_300 )
{
if ( F_12 ( V_300 < V_25 -> V_295 ) )
V_25 -> V_295 -= V_300 ;
else
V_25 -> V_295 = 0 ;
}
static inline void F_213 ( struct V_27 * V_28 ,
int V_301 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_302 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_214 ( V_25 ) ;
else
V_81 = F_214 ( F_25 ( V_28 ) ) ;
if ( ! F_199 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_302 = F_211 ( V_28 ) ;
if ( ! V_301 )
return;
if ( V_28 -> V_76 )
V_25 -> V_294 += V_302 ;
else
F_212 ( V_25 , - V_302 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_292 )
{
T_2 V_81 = F_214 ( V_25 ) >> 20 ;
T_2 V_289 ;
V_289 = V_81 - V_25 -> V_303 ;
if ( ! V_289 && ! V_292 )
return;
if ( F_192 ( & V_25 -> V_304 ) ) {
unsigned long V_304 ;
V_304 = F_215 ( & V_25 -> V_304 , 0 ) ;
F_212 ( V_25 , V_304 ) ;
}
if ( V_289 ) {
V_25 -> V_295 = F_197 ( V_25 -> V_295 ,
V_289 ) ;
F_216 ( V_289 , & V_25 -> V_290 ) ;
V_25 -> V_303 = V_81 ;
}
F_202 ( V_25 , V_292 ) ;
}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_305 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_288 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_288 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_213 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_305 = 0 ;
} else {
F_200 ( V_28 ) ;
}
if ( V_305 ) {
F_212 ( V_25 , V_28 -> V_77 . V_291 ) ;
F_213 ( V_28 , 0 ) ;
}
V_25 -> V_294 += V_28 -> V_77 . V_291 ;
F_30 ( V_25 , ! V_305 ) ;
}
static inline void F_218 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_306 )
{
F_213 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_306 ) ;
V_25 -> V_294 -= V_28 -> V_77 . V_291 ;
if ( V_306 ) {
V_25 -> V_295 += V_28 -> V_77 . V_291 ;
V_28 -> V_77 . V_78 = F_201 ( & V_25 -> V_290 ) ;
}
}
void F_219 ( struct V_24 * V_307 )
{
F_209 ( V_307 , 1 ) ;
}
void F_220 ( struct V_24 * V_307 )
{
F_209 ( V_307 , 0 ) ;
}
static inline void F_213 ( struct V_27 * V_28 ,
int V_301 ) {}
static inline void F_209 ( struct V_24 * V_24 , int V_283 ) {}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_305 ) {}
static inline void F_218 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_306 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_292 ) {}
static inline int F_221 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_222 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_78
struct V_26 * V_208 = NULL ;
if ( F_21 ( V_28 ) )
V_208 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_308 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_308 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_309 ) )
V_28 -> V_83 . V_309 = V_42 ;
V_28 -> V_83 . V_308 = 0 ;
V_28 -> V_83 . V_310 += V_42 ;
if ( V_208 ) {
F_223 ( V_208 , V_42 >> 10 , 1 ) ;
F_224 ( V_208 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_311 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_311 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_312 ) )
V_28 -> V_83 . V_312 = V_42 ;
V_28 -> V_83 . V_311 = 0 ;
V_28 -> V_83 . V_310 += V_42 ;
if ( V_208 ) {
if ( V_208 -> V_313 ) {
V_28 -> V_83 . V_314 += V_42 ;
V_28 -> V_83 . V_315 ++ ;
F_225 ( V_208 , V_42 ) ;
}
F_226 ( V_208 , V_42 ) ;
if ( F_14 ( V_316 == V_317 ) ) {
F_227 ( V_317 ,
( void * ) F_228 ( V_208 ) ,
V_42 >> 20 ) ;
}
F_223 ( V_208 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_229 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_318 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_318 < 0 )
V_318 = - V_318 ;
if ( V_318 > 3 * V_68 )
F_230 ( V_25 , V_319 ) ;
#endif
}
static void
F_231 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_320 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_320 && F_232 ( V_321 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_320 ) {
unsigned long V_322 = V_68 ;
if ( F_232 ( V_323 ) )
V_322 >>= 1 ;
V_41 -= V_322 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_233 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_206 )
{
if ( ! ( V_206 & V_324 ) || ( V_206 & V_325 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_217 ( V_25 , V_28 , V_206 & V_324 ) ;
F_187 ( V_25 , V_28 ) ;
F_195 ( V_25 ) ;
if ( V_206 & V_324 ) {
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
if ( V_25 -> V_326 != V_28 )
break;
V_25 -> V_326 = NULL ;
}
}
static void F_238 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_235 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_236 ( V_28 ) ;
if ( V_25 -> V_326 == V_28 )
F_237 ( V_28 ) ;
}
static void
F_239 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_206 )
{
F_65 ( V_25 ) ;
F_218 ( V_25 , V_28 , V_206 & V_327 ) ;
F_80 ( V_25 , V_28 ) ;
if ( V_206 & V_327 ) {
#ifdef F_78
if ( F_21 ( V_28 ) ) {
struct V_26 * V_208 = F_18 ( V_28 ) ;
if ( V_208 -> V_228 & V_328 )
V_28 -> V_83 . V_308 = F_75 ( F_17 ( V_25 ) ) ;
if ( V_208 -> V_228 & V_329 )
V_28 -> V_83 . V_311 = F_75 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_238 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_189 ( V_25 , V_28 ) ;
if ( ! ( V_206 & V_327 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_240 ( V_25 ) ;
F_40 ( V_25 ) ;
F_195 ( V_25 ) ;
}
static void
F_241 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_330 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_330 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_331 ;
if ( V_19 > V_330 ) {
F_242 ( F_17 ( V_25 ) -> V_45 ) ;
F_238 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_330 )
F_242 ( F_17 ( V_25 ) -> V_45 ) ;
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
V_28 -> V_83 . V_332 = F_68 ( V_28 -> V_83 . V_332 ,
V_28 -> V_85 - V_28 -> V_331 ) ;
}
#endif
V_28 -> V_331 = V_28 -> V_85 ;
}
static struct V_27 *
F_244 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_326 == V_28 ) {
struct V_27 * V_333 ;
if ( V_28 == V_45 ) {
V_333 = F_50 ( V_25 ) ;
} else {
V_333 = F_51 ( V_28 ) ;
if ( ! V_333 || ( V_45 && F_39 ( V_45 , V_333 ) ) )
V_333 = V_45 ;
}
if ( V_333 && F_245 ( V_333 , V_57 ) < 1 )
V_28 = V_333 ;
}
if ( V_25 -> V_59 && F_245 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_245 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_238 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_246 ( struct V_25 * V_25 , struct V_27 * V_334 )
{
if ( V_334 -> V_76 )
F_65 ( V_25 ) ;
F_247 ( V_25 ) ;
F_229 ( V_25 , V_334 ) ;
if ( V_334 -> V_76 ) {
F_74 ( V_25 , V_334 ) ;
F_44 ( V_25 , V_334 ) ;
F_213 ( V_334 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_248 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_335 )
{
F_65 ( V_25 ) ;
F_213 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_195 ( V_25 ) ;
#ifdef F_249
if ( V_335 ) {
F_242 ( F_17 ( V_25 ) -> V_45 ) ;
return;
}
if ( ! F_232 ( V_336 ) &&
F_250 ( & F_17 ( V_25 ) -> V_337 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_241 ( V_25 , V_45 ) ;
}
static inline bool F_251 ( void )
{
return F_252 ( & V_338 ) ;
}
void F_253 ( void )
{
F_254 ( & V_338 ) ;
}
void F_255 ( void )
{
F_256 ( & V_338 ) ;
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
return ( T_2 ) V_339 * V_340 ;
}
void F_259 ( struct V_341 * V_342 )
{
T_2 V_81 ;
if ( V_342 -> V_343 == V_344 )
return;
V_81 = F_260 ( F_261 () ) ;
V_342 -> V_185 = V_342 -> V_343 ;
V_342 -> V_345 = V_81 + F_262 ( V_342 -> V_73 ) ;
}
static inline struct V_341 * F_263 ( struct V_266 * V_33 )
{
return & V_33 -> V_341 ;
}
static inline T_2 F_214 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_346 ) )
return V_25 -> V_347 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_348 ;
}
static int F_264 ( struct V_25 * V_25 )
{
struct V_266 * V_33 = V_25 -> V_33 ;
struct V_341 * V_342 = F_263 ( V_33 ) ;
T_2 V_349 = 0 , V_350 , V_351 ;
V_350 = F_258 () - V_25 -> V_352 ;
F_265 ( & V_342 -> V_195 ) ;
if ( V_342 -> V_343 == V_344 )
V_349 = V_350 ;
else {
if ( ! V_342 -> V_353 ) {
F_259 ( V_342 ) ;
F_266 ( V_342 , false ) ;
}
if ( V_342 -> V_185 > 0 ) {
V_349 = F_135 ( V_342 -> V_185 , V_350 ) ;
V_342 -> V_185 -= V_349 ;
V_342 -> V_354 = 0 ;
}
}
V_351 = V_342 -> V_345 ;
F_267 ( & V_342 -> V_195 ) ;
V_25 -> V_352 += V_349 ;
if ( ( T_3 ) ( V_351 - V_25 -> V_345 ) > 0 )
V_25 -> V_345 = V_351 ;
return V_25 -> V_352 > 0 ;
}
static void F_268 ( struct V_25 * V_25 )
{
struct V_341 * V_342 = F_263 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_75 ( F_17 ( V_25 ) ) - V_25 -> V_345 ) < 0 ) )
return;
if ( V_25 -> V_352 < 0 )
return;
if ( V_25 -> V_345 != V_342 -> V_345 ) {
V_25 -> V_345 += V_249 ;
} else {
V_25 -> V_352 = 0 ;
}
}
static void F_269 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_352 -= V_19 ;
F_268 ( V_25 ) ;
if ( F_12 ( V_25 -> V_352 > 0 ) )
return;
if ( ! F_264 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_242 ( F_17 ( V_25 ) -> V_45 ) ;
}
static T_9
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_251 () || ! V_25 -> V_355 )
return;
F_269 ( V_25 , V_19 ) ;
}
static inline int F_270 ( struct V_25 * V_25 )
{
return F_251 () && V_25 -> V_356 ;
}
static inline int F_196 ( struct V_25 * V_25 )
{
return F_251 () && V_25 -> V_346 ;
}
static inline int F_271 ( struct V_266 * V_33 ,
int V_151 , int V_357 )
{
struct V_25 * V_358 , * V_359 ;
V_358 = V_33 -> V_25 [ V_151 ] ;
V_359 = V_33 -> V_25 [ V_357 ] ;
return F_196 ( V_358 ) ||
F_196 ( V_359 ) ;
}
static int F_272 ( struct V_266 * V_33 , void * V_360 )
{
struct V_24 * V_24 = V_360 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_346 -- ;
#ifdef F_188
if ( ! V_25 -> V_346 ) {
V_25 -> V_348 += F_66 ( V_24 ) -
V_25 -> V_347 ;
}
#endif
return 0 ;
}
static int F_273 ( struct V_266 * V_33 , void * V_360 )
{
struct V_24 * V_24 = V_360 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_346 )
V_25 -> V_347 = F_66 ( V_24 ) ;
V_25 -> V_346 ++ ;
return 0 ;
}
static void F_274 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_341 * V_342 = F_263 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_361 , V_362 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_118 () ;
F_275 ( V_25 -> V_33 , F_273 , V_363 , ( void * ) V_24 ) ;
F_123 () ;
V_361 = V_25 -> V_364 ;
F_61 (se) {
struct V_25 * V_365 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_362 )
F_239 ( V_365 , V_28 , V_327 ) ;
V_365 -> V_364 -= V_361 ;
if ( V_365 -> V_70 . V_4 )
V_362 = 0 ;
}
if ( ! V_28 )
F_276 ( V_24 , V_361 ) ;
V_25 -> V_356 = 1 ;
V_25 -> V_366 = F_75 ( V_24 ) ;
F_265 ( & V_342 -> V_195 ) ;
F_29 ( & V_25 -> V_367 , & V_342 -> V_368 ) ;
if ( ! V_342 -> V_353 )
F_266 ( V_342 , false ) ;
F_267 ( & V_342 -> V_195 ) ;
}
void F_277 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_341 * V_342 = F_263 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_369 = 1 ;
long V_361 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_356 = 0 ;
F_278 ( V_24 ) ;
F_265 ( & V_342 -> V_195 ) ;
V_342 -> V_370 += F_75 ( V_24 ) - V_25 -> V_366 ;
F_32 ( & V_25 -> V_367 ) ;
F_267 ( & V_342 -> V_195 ) ;
F_275 ( V_25 -> V_33 , V_363 , F_272 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_361 = V_25 -> V_364 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_369 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_369 )
F_233 ( V_25 , V_28 , V_324 ) ;
V_25 -> V_364 += V_361 ;
if ( F_270 ( V_25 ) )
break;
}
if ( ! V_28 )
F_279 ( V_24 , V_361 ) ;
if ( V_24 -> V_45 == V_24 -> V_354 && V_24 -> V_40 . V_72 )
F_242 ( V_24 -> V_45 ) ;
}
static T_2 F_280 ( struct V_341 * V_342 ,
T_2 V_371 , T_2 V_351 )
{
struct V_25 * V_25 ;
T_2 V_185 = V_371 ;
F_118 () ;
F_281 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_265 ( & V_24 -> V_195 ) ;
if ( ! F_270 ( V_25 ) )
goto V_58;
V_185 = - V_25 -> V_352 + 1 ;
if ( V_185 > V_371 )
V_185 = V_371 ;
V_371 -= V_185 ;
V_25 -> V_352 += V_185 ;
V_25 -> V_345 = V_351 ;
if ( V_25 -> V_352 > 0 )
F_277 ( V_25 ) ;
V_58:
F_267 ( & V_24 -> V_195 ) ;
if ( ! V_371 )
break;
}
F_123 () ;
return V_371 ;
}
static int F_282 ( struct V_341 * V_342 , int V_372 )
{
T_2 V_185 , V_345 ;
int V_356 ;
if ( V_342 -> V_343 == V_344 )
goto V_373;
V_356 = ! F_283 ( & V_342 -> V_368 ) ;
V_342 -> V_374 += V_372 ;
if ( V_342 -> V_354 && ! V_356 )
goto V_373;
V_342 -> V_353 = 1 ;
F_259 ( V_342 ) ;
if ( ! V_356 ) {
V_342 -> V_354 = 1 ;
return 0 ;
}
V_342 -> V_375 += V_372 ;
V_185 = V_342 -> V_185 ;
V_345 = V_342 -> V_345 ;
V_342 -> V_185 = 0 ;
while ( V_356 && V_185 > 0 ) {
F_267 ( & V_342 -> V_195 ) ;
V_185 = F_280 ( V_342 , V_185 ,
V_345 ) ;
F_265 ( & V_342 -> V_195 ) ;
V_356 = ! F_283 ( & V_342 -> V_368 ) ;
}
V_342 -> V_185 = V_185 ;
V_342 -> V_354 = 0 ;
return 0 ;
V_373:
V_342 -> V_353 = 0 ;
return 1 ;
}
static int F_284 ( struct V_341 * V_342 , T_2 V_376 )
{
struct V_377 * V_378 = & V_342 -> V_379 ;
T_2 V_371 ;
if ( F_285 ( V_378 ) )
return 1 ;
V_371 = F_262 ( F_286 ( V_378 ) ) ;
if ( V_371 < V_376 )
return 1 ;
return 0 ;
}
static void F_287 ( struct V_341 * V_342 )
{
T_2 V_380 = V_381 + V_382 ;
if ( F_284 ( V_342 , V_380 ) )
return;
F_288 ( & V_342 -> V_383 ,
F_289 ( V_381 ) ) ;
}
static void F_290 ( struct V_25 * V_25 )
{
struct V_341 * V_342 = F_263 ( V_25 -> V_33 ) ;
T_3 V_384 = V_25 -> V_352 - V_385 ;
if ( V_384 <= 0 )
return;
F_265 ( & V_342 -> V_195 ) ;
if ( V_342 -> V_343 != V_344 &&
V_25 -> V_345 == V_342 -> V_345 ) {
V_342 -> V_185 += V_384 ;
if ( V_342 -> V_185 > F_258 () &&
! F_283 ( & V_342 -> V_368 ) )
F_287 ( V_342 ) ;
}
F_267 ( & V_342 -> V_195 ) ;
V_25 -> V_352 -= V_384 ;
}
static T_9 void F_240 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return;
if ( ! V_25 -> V_355 || V_25 -> V_72 )
return;
F_290 ( V_25 ) ;
}
static void F_291 ( struct V_341 * V_342 )
{
T_2 V_185 = 0 , V_75 = F_258 () ;
T_2 V_351 ;
F_265 ( & V_342 -> V_195 ) ;
if ( F_284 ( V_342 , V_382 ) ) {
F_267 ( & V_342 -> V_195 ) ;
return;
}
if ( V_342 -> V_343 != V_344 && V_342 -> V_185 > V_75 ) {
V_185 = V_342 -> V_185 ;
V_342 -> V_185 = 0 ;
}
V_351 = V_342 -> V_345 ;
F_267 ( & V_342 -> V_195 ) ;
if ( ! V_185 )
return;
V_185 = F_280 ( V_342 , V_185 , V_351 ) ;
F_265 ( & V_342 -> V_195 ) ;
if ( V_351 == V_342 -> V_345 )
V_342 -> V_185 = V_185 ;
F_267 ( & V_342 -> V_195 ) ;
}
static void F_234 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return;
if ( ! V_25 -> V_355 || V_25 -> V_45 )
return;
if ( F_270 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_352 <= 0 )
F_274 ( V_25 ) ;
}
static bool F_247 ( struct V_25 * V_25 )
{
if ( ! F_251 () )
return false ;
if ( F_12 ( ! V_25 -> V_355 || V_25 -> V_352 > 0 ) )
return false ;
if ( F_270 ( V_25 ) )
return true ;
F_274 ( V_25 ) ;
return true ;
}
static enum V_386 F_292 ( struct V_377 * V_387 )
{
struct V_341 * V_342 =
F_22 ( V_387 , struct V_341 , V_383 ) ;
F_291 ( V_342 ) ;
return V_388 ;
}
static enum V_386 F_293 ( struct V_377 * V_387 )
{
struct V_341 * V_342 =
F_22 ( V_387 , struct V_341 , V_379 ) ;
T_10 V_81 ;
int V_372 ;
int V_354 = 0 ;
F_265 ( & V_342 -> V_195 ) ;
for (; ; ) {
V_81 = F_294 ( V_387 ) ;
V_372 = F_295 ( V_387 , V_81 , V_342 -> V_73 ) ;
if ( ! V_372 )
break;
V_354 = F_282 ( V_342 , V_372 ) ;
}
F_267 ( & V_342 -> V_195 ) ;
return V_354 ? V_388 : V_389 ;
}
void F_296 ( struct V_341 * V_342 )
{
F_297 ( & V_342 -> V_195 ) ;
V_342 -> V_185 = 0 ;
V_342 -> V_343 = V_344 ;
V_342 -> V_73 = F_289 ( F_257 () ) ;
F_157 ( & V_342 -> V_368 ) ;
F_298 ( & V_342 -> V_379 , V_390 , V_391 ) ;
V_342 -> V_379 . V_392 = F_293 ;
F_298 ( & V_342 -> V_383 , V_390 , V_391 ) ;
V_342 -> V_383 . V_392 = F_292 ;
}
static void F_299 ( struct V_25 * V_25 )
{
V_25 -> V_355 = 0 ;
F_157 ( & V_25 -> V_367 ) ;
}
void F_266 ( struct V_341 * V_342 , bool V_393 )
{
while ( F_14 ( F_250 ( & V_342 -> V_379 ) ) &&
F_300 ( & V_342 -> V_379 ) < 0 ) {
F_267 ( & V_342 -> V_195 ) ;
F_301 () ;
F_265 ( & V_342 -> V_195 ) ;
if ( ! V_393 && V_342 -> V_353 )
return;
}
V_342 -> V_353 = 1 ;
F_288 ( & V_342 -> V_379 , V_342 -> V_73 ) ;
}
static void F_302 ( struct V_341 * V_342 )
{
F_303 ( & V_342 -> V_379 ) ;
F_303 ( & V_342 -> V_383 ) ;
}
static void T_11 F_304 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_305 (rq, cfs_rq) {
if ( ! V_25 -> V_355 )
continue;
V_25 -> V_352 = 1 ;
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
static inline int F_271 ( struct V_266 * V_33 ,
int V_151 , int V_357 )
{
return 0 ;
}
void F_296 ( struct V_341 * V_342 ) {}
static void F_299 ( struct V_25 * V_25 ) {}
static inline struct V_341 * F_263 ( struct V_266 * V_33 )
{
return NULL ;
}
static inline void F_302 ( struct V_341 * V_342 ) {}
static inline void F_304 ( struct V_24 * V_24 ) {}
static void F_306 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_307 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_394 = V_28 -> V_85 - V_28 -> V_331 ;
T_3 V_42 = V_75 - V_394 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_242 ( V_29 ) ;
return;
}
if ( V_24 -> V_45 != V_29 )
V_42 = F_86 ( T_3 , 10000LL , V_42 ) ;
F_308 ( V_24 , V_42 ) ;
}
}
static void F_309 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_310 ( V_24 ) || V_45 -> V_395 != & V_396 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_306 ( V_24 , V_45 ) ;
}
static inline void
F_306 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_309 ( struct V_24 * V_24 )
{
}
static void
F_311 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_206 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_233 ( V_25 , V_28 , V_206 ) ;
if ( F_270 ( V_25 ) )
break;
V_25 -> V_364 ++ ;
V_206 = V_324 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_364 ++ ;
if ( F_270 ( V_25 ) )
break;
F_195 ( V_25 ) ;
F_213 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_209 ( V_24 , V_24 -> V_72 ) ;
F_279 ( V_24 , 1 ) ;
}
F_309 ( V_24 ) ;
}
static void F_312 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_206 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_397 = V_206 & V_327 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_239 ( V_25 , V_28 , V_206 ) ;
if ( F_270 ( V_25 ) )
break;
V_25 -> V_364 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_397 && F_34 ( V_28 ) )
F_313 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_206 |= V_327 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_364 -- ;
if ( F_270 ( V_25 ) )
break;
F_195 ( V_25 ) ;
F_213 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_276 ( V_24 , 1 ) ;
F_209 ( V_24 , 1 ) ;
}
F_309 ( V_24 ) ;
}
static unsigned long F_109 ( const int V_130 )
{
return F_108 ( V_130 ) -> V_40 . V_294 ;
}
static unsigned long F_314 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_398 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_232 ( V_399 ) )
return V_398 ;
return F_135 ( V_24 -> V_400 [ type - 1 ] , V_398 ) ;
}
static unsigned long F_315 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_398 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_232 ( V_399 ) )
return V_398 ;
return F_68 ( V_24 -> V_400 [ type - 1 ] , V_398 ) ;
}
static unsigned long F_110 ( int V_130 )
{
return F_108 ( V_130 ) -> V_401 ;
}
static unsigned long F_316 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_72 = F_119 ( V_24 -> V_72 ) ;
unsigned long V_268 = V_24 -> V_40 . V_294 ;
if ( V_72 )
return V_268 / V_72 ;
return 0 ;
}
static void F_317 ( struct V_26 * V_29 )
{
if ( F_171 ( V_170 , V_125 -> V_402 + V_168 ) ) {
V_125 -> V_403 >>= 1 ;
V_125 -> V_402 = V_170 ;
}
if ( V_125 -> V_404 != V_29 ) {
V_125 -> V_404 = V_29 ;
V_125 -> V_403 ++ ;
}
}
static void F_318 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_319 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_317 ( V_29 ) ;
}
static long F_320 ( struct V_266 * V_33 , int V_130 , long V_405 , long V_406 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_130 ] ;
if ( ! V_33 -> V_34 )
return V_405 ;
F_61 (se) {
long V_7 , V_407 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_407 = V_406 + F_191 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_405 ;
if ( V_407 > 0 && V_7 < V_407 )
V_405 = ( V_7 * V_33 -> V_270 ) / V_407 ;
else
V_405 = V_33 -> V_270 ;
if ( V_405 < V_271 )
V_405 = V_271 ;
V_405 -= V_28 -> V_70 . V_4 ;
V_406 = 0 ;
}
return V_405 ;
}
static long F_320 ( struct V_266 * V_33 , int V_130 , long V_405 , long V_406 )
{
return V_405 ;
}
static int F_321 ( struct V_26 * V_29 )
{
int V_9 = F_322 ( V_408 ) ;
if ( V_29 -> V_403 > V_9 ) {
if ( V_125 -> V_403 > ( V_9 * V_29 -> V_403 ) )
return 1 ;
}
return 0 ;
}
static int F_323 ( struct V_159 * V_160 , struct V_26 * V_29 , int V_409 )
{
T_3 V_410 , V_70 ;
int V_411 , V_412 , V_413 ;
unsigned long V_414 ;
struct V_266 * V_33 ;
unsigned long V_4 ;
int V_415 ;
if ( F_321 ( V_29 ) )
return 0 ;
V_411 = V_160 -> V_416 ;
V_412 = F_261 () ;
V_413 = F_126 ( V_29 ) ;
V_70 = F_314 ( V_413 , V_411 ) ;
V_410 = F_315 ( V_412 , V_411 ) ;
if ( V_409 ) {
V_33 = V_266 ( V_125 ) ;
V_4 = V_125 -> V_28 . V_70 . V_4 ;
V_410 += F_320 ( V_33 , V_412 , - V_4 , - V_4 ) ;
V_70 += F_320 ( V_33 , V_413 , 0 , - V_4 ) ;
}
V_33 = V_266 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_410 > 0 ) {
T_3 V_417 , V_418 ;
V_417 = 100 ;
V_417 *= F_110 ( V_413 ) ;
V_417 *= V_410 +
F_320 ( V_33 , V_412 , V_4 , V_4 ) ;
V_418 = 100 + ( V_160 -> V_147 - 100 ) / 2 ;
V_418 *= F_110 ( V_412 ) ;
V_418 *= V_70 + F_320 ( V_33 , V_413 , 0 , V_4 ) ;
V_415 = V_417 <= V_418 ;
} else
V_415 = true ;
if ( V_409 && V_415 )
return 1 ;
F_230 ( V_29 , V_28 . V_83 . V_419 ) ;
V_414 = F_316 ( V_412 ) ;
if ( V_415 ||
( V_410 <= V_70 &&
V_410 + F_315 ( V_413 , V_411 ) <= V_414 ) ) {
F_230 ( V_160 , V_420 ) ;
F_230 ( V_29 , V_28 . V_83 . V_421 ) ;
return 1 ;
}
return 0 ;
}
static struct V_422 *
F_324 ( struct V_159 * V_160 , struct V_26 * V_29 ,
int V_412 , int V_423 )
{
struct V_422 * V_424 = NULL , * V_114 = V_160 -> V_425 ;
unsigned long V_426 = V_427 , V_410 = 0 ;
int V_428 = V_160 -> V_429 ;
int V_430 = 100 + ( V_160 -> V_147 - 100 ) / 2 ;
if ( V_423 & V_431 )
V_428 = V_160 -> V_416 ;
do {
unsigned long V_70 , V_432 ;
int V_433 ;
int V_196 ;
if ( ! F_325 ( F_326 ( V_114 ) ,
F_121 ( V_29 ) ) )
continue;
V_433 = F_120 ( V_412 ,
F_326 ( V_114 ) ) ;
V_432 = 0 ;
F_107 (i, sched_group_cpus(group)) {
if ( V_433 )
V_70 = F_314 ( V_196 , V_428 ) ;
else
V_70 = F_315 ( V_196 , V_428 ) ;
V_432 += V_70 ;
}
V_432 = ( V_432 * V_132 ) / V_114 -> V_434 -> V_435 ;
if ( V_433 ) {
V_410 = V_432 ;
} else if ( V_432 < V_426 ) {
V_426 = V_432 ;
V_424 = V_114 ;
}
} while ( V_114 = V_114 -> V_58 , V_114 != V_160 -> V_425 );
if ( ! V_424 || 100 * V_410 < V_430 * V_426 )
return NULL ;
return V_424 ;
}
static int
F_327 ( struct V_422 * V_114 , struct V_26 * V_29 , int V_412 )
{
unsigned long V_70 , V_426 = V_427 ;
int V_424 = - 1 ;
int V_196 ;
F_328 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_109 ( V_196 ) ;
if ( V_70 < V_426 || ( V_70 == V_426 && V_196 == V_412 ) ) {
V_426 = V_70 ;
V_424 = V_196 ;
}
}
return V_424 ;
}
static int F_329 ( struct V_26 * V_29 , int V_436 )
{
struct V_159 * V_160 ;
struct V_422 * V_437 ;
int V_196 = F_126 ( V_29 ) ;
if ( F_330 ( V_436 ) )
return V_436 ;
if ( V_196 != V_436 && F_331 ( V_196 , V_436 ) && F_330 ( V_196 ) )
return V_196 ;
V_160 = F_127 ( F_128 ( V_438 , V_436 ) ) ;
F_332 (sd) {
V_437 = V_160 -> V_425 ;
do {
if ( ! F_325 ( F_326 ( V_437 ) ,
F_121 ( V_29 ) ) )
goto V_58;
F_107 (i, sched_group_cpus(sg)) {
if ( V_196 == V_436 || ! F_330 ( V_196 ) )
goto V_58;
}
V_436 = F_333 ( F_326 ( V_437 ) ,
F_121 ( V_29 ) ) ;
goto V_439;
V_58:
V_437 = V_437 -> V_58 ;
} while ( V_437 != V_160 -> V_425 );
}
V_439:
return V_436 ;
}
static int
F_334 ( struct V_26 * V_29 , int V_413 , int V_423 , int V_440 )
{
struct V_159 * V_441 , * V_442 = NULL , * V_160 = NULL ;
int V_130 = F_261 () ;
int V_443 = V_130 ;
int V_444 = 0 ;
int V_409 = V_440 & V_445 ;
if ( V_29 -> V_446 == 1 )
return V_413 ;
if ( V_423 & V_431 ) {
if ( F_120 ( V_130 , F_121 ( V_29 ) ) )
V_444 = 1 ;
V_443 = V_413 ;
}
F_118 () ;
F_335 (cpu, tmp) {
if ( ! ( V_441 -> V_206 & V_447 ) )
continue;
if ( V_444 && ( V_441 -> V_206 & V_448 ) &&
F_120 ( V_413 , F_336 ( V_441 ) ) ) {
V_442 = V_441 ;
break;
}
if ( V_441 -> V_206 & V_423 )
V_160 = V_441 ;
}
if ( V_442 && V_130 != V_413 && F_323 ( V_442 , V_29 , V_409 ) )
V_413 = V_130 ;
if ( V_423 & V_431 ) {
V_443 = F_329 ( V_29 , V_413 ) ;
goto V_154;
}
while ( V_160 ) {
struct V_422 * V_114 ;
int V_4 ;
if ( ! ( V_160 -> V_206 & V_423 ) ) {
V_160 = V_160 -> V_449 ;
continue;
}
V_114 = F_324 ( V_160 , V_29 , V_130 , V_423 ) ;
if ( ! V_114 ) {
V_160 = V_160 -> V_449 ;
continue;
}
V_443 = F_327 ( V_114 , V_29 , V_130 ) ;
if ( V_443 == - 1 || V_443 == V_130 ) {
V_160 = V_160 -> V_449 ;
continue;
}
V_130 = V_443 ;
V_4 = V_160 -> V_450 ;
V_160 = NULL ;
F_335 (cpu, tmp) {
if ( V_4 <= V_441 -> V_450 )
break;
if ( V_441 -> V_206 & V_423 )
V_160 = V_441 ;
}
}
V_154:
F_123 () ;
return V_443 ;
}
static void
F_337 ( struct V_26 * V_29 , int V_451 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_200 ( V_28 ) ;
F_203 ( V_28 -> V_77 . V_291 ,
& V_25 -> V_304 ) ;
}
V_28 -> V_82 = 0 ;
}
static unsigned long
F_338 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_452 = V_453 ;
return F_58 ( V_452 , V_28 ) ;
}
static int
F_245 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_452 , V_454 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_454 <= 0 )
return - 1 ;
V_452 = F_338 ( V_45 , V_28 ) ;
if ( V_454 > V_452 )
return 1 ;
return 0 ;
}
static void F_339 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_455 == V_456 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_313 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_455 == V_456 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_340 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_326 = V_28 ;
}
static void F_341 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_440 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_457 = V_25 -> V_72 >= V_67 ;
int V_458 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_196 ( F_24 ( V_36 ) ) ) )
return;
if ( F_232 ( V_459 ) && V_457 && ! ( V_440 & V_460 ) ) {
F_313 ( V_36 ) ;
V_458 = 1 ;
}
if ( F_342 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_455 == V_456 ) &&
F_12 ( V_29 -> V_455 != V_456 ) )
goto V_461;
if ( F_14 ( V_29 -> V_455 != V_462 ) || ! F_232 ( V_463 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_160 ( ! V_36 ) ;
if ( F_245 ( V_28 , V_36 ) == 1 ) {
if ( ! V_458 )
F_313 ( V_36 ) ;
goto V_461;
}
return;
V_461:
F_242 ( V_45 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_354 ) )
return;
if ( F_232 ( V_464 ) && V_457 && F_21 ( V_28 ) )
F_339 ( V_28 ) ;
}
static struct V_26 *
F_343 ( struct V_24 * V_24 , struct V_26 * V_334 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_465 ;
V_466:
#ifdef F_344
if ( ! V_25 -> V_72 )
goto V_354;
if ( V_334 -> V_395 != & V_396 )
goto V_467;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_247 ( V_25 ) ) )
goto V_467;
V_28 = F_244 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_334 != V_29 ) {
struct V_27 * V_36 = & V_334 -> V_28 ;
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
if ( F_310 ( V_24 ) )
F_306 ( V_24 , V_29 ) ;
return V_29 ;
V_467:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_354;
F_345 ( V_24 , V_334 ) ;
do {
V_28 = F_244 ( V_25 , NULL ) ;
F_243 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_310 ( V_24 ) )
F_306 ( V_24 , V_29 ) ;
return V_29 ;
V_354:
V_465 = F_221 ( V_24 ) ;
if ( V_465 < 0 )
return V_468 ;
if ( V_465 > 0 )
goto V_466;
return NULL ;
}
static void F_346 ( struct V_24 * V_24 , struct V_26 * V_334 )
{
struct V_27 * V_28 = & V_334 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_246 ( V_25 , V_28 ) ;
}
}
static void F_347 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_238 ( V_25 , V_28 ) ;
if ( V_45 -> V_455 != V_469 ) {
F_278 ( V_24 ) ;
F_65 ( V_25 ) ;
V_24 -> V_470 = 1 ;
}
F_340 ( V_28 ) ;
}
static bool F_348 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_461 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_196 ( F_24 ( V_28 ) ) )
return false ;
F_313 ( V_28 ) ;
F_347 ( V_24 ) ;
return true ;
}
static void F_349 ( struct V_26 * V_29 , struct V_471 * V_136 )
{
F_350 ( V_136 -> V_150 , V_29 , 0 ) ;
F_351 ( V_29 , V_136 -> V_120 ) ;
F_352 ( V_136 -> V_152 , V_29 , 0 ) ;
F_353 ( V_136 -> V_152 , V_29 , 0 ) ;
}
static int
F_354 ( struct V_26 * V_29 , T_2 V_81 )
{
T_3 V_42 ;
if ( V_29 -> V_395 != & V_396 )
return 0 ;
if ( F_14 ( V_29 -> V_455 == V_456 ) )
return 0 ;
if ( F_232 ( V_472 ) && V_307 () -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_473 == - 1 )
return 1 ;
if ( V_473 == 0 )
return 0 ;
V_42 = V_81 - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_473 ;
}
static bool F_355 ( struct V_26 * V_29 , struct V_471 * V_136 )
{
struct V_107 * V_107 = F_127 ( V_29 -> V_107 ) ;
int V_119 , V_122 ;
if ( ! F_232 ( V_474 ) || ! V_29 -> V_112 ||
! ( V_136 -> V_160 -> V_206 & V_475 ) ) {
return false ;
}
V_119 = F_99 ( V_136 -> V_151 ) ;
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
static bool F_356 ( struct V_26 * V_29 , struct V_471 * V_136 )
{
struct V_107 * V_107 = F_127 ( V_29 -> V_107 ) ;
int V_119 , V_122 ;
if ( ! F_232 ( V_476 ) || ! F_232 ( V_477 ) )
return false ;
if ( ! V_29 -> V_112 || ! ( V_136 -> V_160 -> V_206 & V_475 ) )
return false ;
V_119 = F_99 ( V_136 -> V_151 ) ;
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
static inline bool F_355 ( struct V_26 * V_29 ,
struct V_471 * V_136 )
{
return false ;
}
static inline bool F_356 ( struct V_26 * V_29 ,
struct V_471 * V_136 )
{
return false ;
}
static
int F_357 ( struct V_26 * V_29 , struct V_471 * V_136 )
{
int V_478 = 0 ;
if ( F_271 ( V_266 ( V_29 ) , V_136 -> V_151 , V_136 -> V_120 ) )
return 0 ;
if ( ! F_120 ( V_136 -> V_120 , F_121 ( V_29 ) ) ) {
int V_130 ;
F_230 ( V_29 , V_28 . V_83 . V_479 ) ;
V_136 -> V_206 |= V_480 ;
if ( ! V_136 -> V_481 || ( V_136 -> V_206 & V_482 ) )
return 0 ;
F_328 (cpu, env->dst_grpmask, env->cpus) {
if ( F_120 ( V_130 , F_121 ( V_29 ) ) ) {
V_136 -> V_206 |= V_482 ;
V_136 -> V_483 = V_130 ;
break;
}
}
return 0 ;
}
V_136 -> V_206 &= ~ V_484 ;
if ( F_358 ( V_136 -> V_150 , V_29 ) ) {
F_230 ( V_29 , V_28 . V_83 . V_485 ) ;
return 0 ;
}
V_478 = F_354 ( V_29 , F_66 ( V_136 -> V_150 ) ) ;
if ( ! V_478 )
V_478 = F_356 ( V_29 , V_136 ) ;
if ( F_355 ( V_29 , V_136 ) ) {
#ifdef F_78
if ( V_478 ) {
F_230 ( V_136 -> V_160 , V_486 [ V_136 -> V_354 ] ) ;
F_230 ( V_29 , V_28 . V_83 . V_487 ) ;
}
#endif
return 1 ;
}
if ( ! V_478 ||
V_136 -> V_160 -> V_488 > V_136 -> V_160 -> V_489 ) {
if ( V_478 ) {
F_230 ( V_136 -> V_160 , V_486 [ V_136 -> V_354 ] ) ;
F_230 ( V_29 , V_28 . V_83 . V_487 ) ;
}
return 1 ;
}
F_230 ( V_29 , V_28 . V_83 . V_490 ) ;
return 0 ;
}
static int F_359 ( struct V_471 * V_136 )
{
struct V_26 * V_29 , * V_273 ;
F_360 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_357 ( V_29 , V_136 ) )
continue;
F_349 ( V_29 , V_136 ) ;
F_230 ( V_136 -> V_160 , V_491 [ V_136 -> V_354 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_361 ( struct V_471 * V_136 )
{
struct V_492 * V_493 = & V_136 -> V_150 -> V_265 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_494 = 0 ;
if ( V_136 -> V_430 <= 0 )
return 0 ;
while ( ! F_283 ( V_493 ) ) {
V_29 = F_362 ( V_493 , struct V_26 , V_28 . V_264 ) ;
V_136 -> V_495 ++ ;
if ( V_136 -> V_495 > V_136 -> V_496 )
break;
if ( V_136 -> V_495 > V_136 -> V_497 ) {
V_136 -> V_497 += V_498 ;
V_136 -> V_206 |= V_499 ;
break;
}
if ( ! F_357 ( V_29 , V_136 ) )
goto V_58;
V_70 = F_122 ( V_29 ) ;
if ( F_232 ( V_500 ) && V_70 < 16 && ! V_136 -> V_160 -> V_488 )
goto V_58;
if ( ( V_70 / 2 ) > V_136 -> V_430 )
goto V_58;
F_349 ( V_29 , V_136 ) ;
V_494 ++ ;
V_136 -> V_430 -= V_70 ;
#ifdef F_363
if ( V_136 -> V_354 == V_501 )
break;
#endif
if ( V_136 -> V_430 <= 0 )
break;
continue;
V_58:
F_364 ( & V_29 -> V_28 . V_264 , V_493 ) ;
}
F_69 ( V_136 -> V_160 , V_491 [ V_136 -> V_354 ] , V_494 ) ;
return V_494 ;
}
static void F_365 ( struct V_266 * V_33 , int V_130 )
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
static void F_366 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
struct V_25 * V_25 ;
unsigned long V_206 ;
F_367 ( & V_24 -> V_195 , V_206 ) ;
F_278 ( V_24 ) ;
F_305 (rq, cfs_rq) {
F_365 ( V_25 -> V_33 , V_24 -> V_130 ) ;
}
F_368 ( & V_24 -> V_195 , V_206 ) ;
}
static void F_369 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_170 ;
unsigned long V_70 ;
if ( V_25 -> V_502 == V_81 )
return;
V_25 -> V_503 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_503 = V_28 ;
if ( V_25 -> V_502 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_504 = V_25 -> V_294 ;
V_25 -> V_502 = V_81 ;
}
while ( ( V_28 = V_25 -> V_503 ) != NULL ) {
V_70 = V_25 -> V_504 ;
V_70 = F_370 ( V_70 * V_28 -> V_77 . V_291 ,
V_25 -> V_294 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_504 = V_70 ;
V_25 -> V_502 = V_81 ;
}
}
static unsigned long F_122 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_369 ( V_25 ) ;
return F_370 ( V_29 -> V_28 . V_77 . V_291 * V_25 -> V_504 ,
V_25 -> V_294 + 1 ) ;
}
static inline void F_366 ( int V_130 )
{
}
static unsigned long F_122 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_291 ;
}
static inline void F_371 ( struct V_505 * V_506 )
{
* V_506 = (struct V_505 ) {
. V_507 = NULL ,
. V_179 = NULL ,
. V_508 = 0UL ,
. V_509 = 0UL ,
. V_510 = {
. V_432 = 0UL ,
} ,
} ;
}
static inline int F_372 ( struct V_159 * V_160 ,
enum V_511 V_354 )
{
int V_428 ;
switch ( V_354 ) {
case V_512 :
V_428 = V_160 -> V_513 ;
break;
case V_501 :
V_428 = V_160 -> V_514 ;
break;
default:
V_428 = V_160 -> V_515 ;
break;
}
return V_428 ;
}
static unsigned long F_373 ( struct V_159 * V_160 , int V_130 )
{
return V_132 ;
}
unsigned long __weak F_374 ( struct V_159 * V_160 , int V_130 )
{
return F_373 ( V_160 , V_130 ) ;
}
static unsigned long F_375 ( struct V_159 * V_160 , int V_130 )
{
unsigned long V_4 = V_160 -> V_450 ;
unsigned long V_516 = V_160 -> V_516 ;
V_516 /= V_4 ;
return V_516 ;
}
unsigned long __weak F_376 ( struct V_159 * V_160 , int V_130 )
{
return F_375 ( V_160 , V_130 ) ;
}
static unsigned long F_377 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
T_2 V_398 , V_517 , V_518 , V_77 ;
T_3 V_42 ;
V_518 = F_119 ( V_24 -> V_518 ) ;
V_77 = F_119 ( V_24 -> V_519 ) ;
V_42 = F_75 ( V_24 ) - V_518 ;
if ( F_14 ( V_42 < 0 ) )
V_42 = 0 ;
V_398 = F_378 () + V_42 ;
if ( F_14 ( V_398 < V_77 ) ) {
V_517 = 0 ;
} else {
V_517 = V_398 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_398 < V_132 ) )
V_398 = V_132 ;
V_398 >>= V_520 ;
return F_205 ( V_517 , V_398 ) ;
}
static void F_379 ( struct V_159 * V_160 , int V_130 )
{
unsigned long V_4 = V_160 -> V_450 ;
unsigned long V_435 = V_132 ;
struct V_422 * V_521 = V_160 -> V_425 ;
if ( ( V_160 -> V_206 & V_522 ) && V_4 > 1 ) {
if ( F_232 ( V_523 ) )
V_435 *= F_376 ( V_160 , V_130 ) ;
else
V_435 *= F_375 ( V_160 , V_130 ) ;
V_435 >>= V_520 ;
}
V_521 -> V_434 -> V_524 = V_435 ;
if ( F_232 ( V_523 ) )
V_435 *= F_374 ( V_160 , V_130 ) ;
else
V_435 *= F_373 ( V_160 , V_130 ) ;
V_435 >>= V_520 ;
V_435 *= F_377 ( V_130 ) ;
V_435 >>= V_520 ;
if ( ! V_435 )
V_435 = 1 ;
F_108 ( V_130 ) -> V_401 = V_435 ;
V_521 -> V_434 -> V_435 = V_435 ;
}
void F_380 ( struct V_159 * V_160 , int V_130 )
{
struct V_159 * V_449 = V_160 -> V_449 ;
struct V_422 * V_114 , * V_521 = V_160 -> V_425 ;
unsigned long V_435 , V_524 ;
unsigned long V_167 ;
V_167 = F_136 ( V_160 -> V_525 ) ;
V_167 = F_141 ( V_167 , 1UL , V_526 ) ;
V_521 -> V_434 -> V_527 = V_170 + V_167 ;
if ( ! V_449 ) {
F_379 ( V_160 , V_130 ) ;
return;
}
V_524 = V_435 = 0 ;
if ( V_449 -> V_206 & V_528 ) {
F_107 (cpu, sched_group_cpus(sdg)) {
struct V_529 * V_434 ;
struct V_24 * V_24 = F_108 ( V_130 ) ;
if ( F_14 ( ! V_24 -> V_160 ) ) {
V_524 += F_110 ( V_130 ) ;
V_435 += F_110 ( V_130 ) ;
continue;
}
V_434 = V_24 -> V_160 -> V_425 -> V_434 ;
V_524 += V_434 -> V_524 ;
V_435 += V_434 -> V_435 ;
}
} else {
V_114 = V_449 -> V_425 ;
do {
V_524 += V_114 -> V_434 -> V_524 ;
V_435 += V_114 -> V_434 -> V_435 ;
V_114 = V_114 -> V_58 ;
} while ( V_114 != V_449 -> V_425 );
}
V_521 -> V_434 -> V_524 = V_524 ;
V_521 -> V_434 -> V_435 = V_435 ;
}
static inline int
F_381 ( struct V_159 * V_160 , struct V_422 * V_114 )
{
if ( ! ( V_160 -> V_206 & V_522 ) )
return 0 ;
if ( V_114 -> V_434 -> V_435 * 32 > V_114 -> V_434 -> V_524 * 29 )
return 1 ;
return 0 ;
}
static inline int F_382 ( struct V_422 * V_114 )
{
return V_114 -> V_434 -> V_430 ;
}
static inline int F_383 ( struct V_471 * V_136 , struct V_422 * V_114 )
{
unsigned int V_530 , V_531 , V_8 ;
unsigned int V_435 , V_524 ;
V_435 = V_114 -> V_434 -> V_435 ;
V_524 = V_114 -> V_434 -> V_524 ;
V_8 = V_114 -> F_97 ;
V_531 = F_56 ( V_132 * V_8 , V_524 ) ;
V_530 = V_8 / V_531 ;
V_530 = F_5 ( unsigned ,
V_530 , F_111 ( V_435 , V_132 ) ) ;
if ( ! V_530 )
V_530 = F_381 ( V_136 -> V_160 , V_114 ) ;
return V_530 ;
}
static inline void F_384 ( struct V_471 * V_136 ,
struct V_422 * V_114 , int V_428 ,
int V_433 , struct V_532 * V_533 )
{
unsigned long V_70 ;
int V_196 ;
memset ( V_533 , 0 , sizeof( * V_533 ) ) ;
F_328 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_108 ( V_196 ) ;
if ( V_433 )
V_70 = F_315 ( V_196 , V_428 ) ;
else
V_70 = F_314 ( V_196 , V_428 ) ;
V_533 -> V_534 += V_70 ;
V_533 -> V_535 += V_24 -> V_72 ;
#ifdef F_385
V_533 -> V_104 += V_24 -> V_104 ;
V_533 -> V_106 += V_24 -> V_106 ;
#endif
V_533 -> V_536 += F_109 ( V_196 ) ;
if ( F_330 ( V_196 ) )
V_533 -> V_537 ++ ;
}
V_533 -> V_538 = V_114 -> V_434 -> V_435 ;
V_533 -> V_432 = ( V_533 -> V_534 * V_132 ) / V_533 -> V_538 ;
if ( V_533 -> V_535 )
V_533 -> V_539 = V_533 -> V_536 / V_533 -> V_535 ;
V_533 -> F_97 = V_114 -> F_97 ;
V_533 -> V_540 = F_382 ( V_114 ) ;
V_533 -> V_541 = F_383 ( V_136 , V_114 ) ;
if ( V_533 -> V_541 > V_533 -> V_535 )
V_533 -> V_542 = 1 ;
}
static bool F_386 ( struct V_471 * V_136 ,
struct V_505 * V_506 ,
struct V_422 * V_437 ,
struct V_532 * V_533 )
{
if ( V_533 -> V_432 <= V_506 -> V_510 . V_432 )
return false ;
if ( V_533 -> V_535 > V_533 -> V_541 )
return true ;
if ( V_533 -> V_540 )
return true ;
if ( ( V_136 -> V_160 -> V_206 & V_543 ) && V_533 -> V_535 &&
V_136 -> V_120 < F_387 ( V_437 ) ) {
if ( ! V_506 -> V_507 )
return true ;
if ( F_387 ( V_506 -> V_507 ) > F_387 ( V_437 ) )
return true ;
}
return false ;
}
static inline enum V_544 F_388 ( struct V_532 * V_533 )
{
if ( V_533 -> V_535 > V_533 -> V_104 )
return V_545 ;
if ( V_533 -> V_535 > V_533 -> V_106 )
return V_177 ;
return V_546 ;
}
static inline enum V_544 F_389 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_104 )
return V_545 ;
if ( V_24 -> V_72 > V_24 -> V_106 )
return V_177 ;
return V_546 ;
}
static inline enum V_544 F_388 ( struct V_532 * V_533 )
{
return V_546 ;
}
static inline enum V_544 F_389 ( struct V_24 * V_24 )
{
return V_545 ;
}
static inline void F_390 ( struct V_471 * V_136 , struct V_505 * V_506 )
{
struct V_159 * V_449 = V_136 -> V_160 -> V_449 ;
struct V_422 * V_437 = V_136 -> V_160 -> V_425 ;
struct V_532 V_547 ;
int V_428 , V_548 = 0 ;
if ( V_449 && V_449 -> V_206 & V_549 )
V_548 = 1 ;
V_428 = F_372 ( V_136 -> V_160 , V_136 -> V_354 ) ;
do {
struct V_532 * V_533 = & V_547 ;
int V_433 ;
V_433 = F_120 ( V_136 -> V_120 , F_326 ( V_437 ) ) ;
if ( V_433 ) {
V_506 -> V_179 = V_437 ;
V_533 = & V_506 -> V_550 ;
if ( V_136 -> V_354 != V_501 ||
F_391 ( V_170 , V_437 -> V_434 -> V_527 ) )
F_380 ( V_136 -> V_160 , V_136 -> V_120 ) ;
}
F_384 ( V_136 , V_437 , V_428 , V_433 , V_533 ) ;
if ( V_433 )
goto V_551;
if ( V_548 && V_506 -> V_179 &&
V_506 -> V_550 . V_542 )
V_533 -> V_541 = F_135 ( V_533 -> V_541 , 1U ) ;
if ( F_386 ( V_136 , V_506 , V_437 , V_533 ) ) {
V_506 -> V_507 = V_437 ;
V_506 -> V_510 = * V_533 ;
}
V_551:
V_506 -> V_508 += V_533 -> V_534 ;
V_506 -> V_509 += V_533 -> V_538 ;
V_437 = V_437 -> V_58 ;
} while ( V_437 != V_136 -> V_160 -> V_425 );
if ( V_136 -> V_160 -> V_206 & V_475 )
V_136 -> V_544 = F_388 ( & V_506 -> V_510 ) ;
}
static int F_392 ( struct V_471 * V_136 , struct V_505 * V_506 )
{
int V_552 ;
if ( ! ( V_136 -> V_160 -> V_206 & V_543 ) )
return 0 ;
if ( ! V_506 -> V_507 )
return 0 ;
V_552 = F_387 ( V_506 -> V_507 ) ;
if ( V_136 -> V_120 > V_552 )
return 0 ;
V_136 -> V_430 = F_111 (
V_506 -> V_510 . V_432 * V_506 -> V_510 . V_538 ,
V_132 ) ;
return 1 ;
}
static inline
void F_393 ( struct V_471 * V_136 , struct V_505 * V_506 )
{
unsigned long V_441 , V_553 = 0 , V_554 = 0 ;
unsigned int V_555 = 2 ;
unsigned long V_556 ;
struct V_532 * V_179 , * V_507 ;
V_179 = & V_506 -> V_550 ;
V_507 = & V_506 -> V_510 ;
if ( ! V_179 -> V_535 )
V_179 -> V_539 = F_316 ( V_136 -> V_120 ) ;
else if ( V_507 -> V_539 > V_179 -> V_539 )
V_555 = 1 ;
V_556 =
( V_507 -> V_539 * V_132 ) /
V_507 -> V_538 ;
if ( V_507 -> V_432 + V_556 >=
V_179 -> V_432 + ( V_556 * V_555 ) ) {
V_136 -> V_430 = V_507 -> V_539 ;
return;
}
V_553 += V_507 -> V_538 *
F_135 ( V_507 -> V_539 , V_507 -> V_432 ) ;
V_553 += V_179 -> V_538 *
F_135 ( V_179 -> V_539 , V_179 -> V_432 ) ;
V_553 /= V_132 ;
if ( V_507 -> V_432 > V_556 ) {
V_554 += V_507 -> V_538 *
F_135 ( V_507 -> V_539 ,
V_507 -> V_432 - V_556 ) ;
}
if ( V_507 -> V_432 * V_507 -> V_538 <
V_507 -> V_539 * V_132 ) {
V_441 = ( V_507 -> V_432 * V_507 -> V_538 ) /
V_179 -> V_538 ;
} else {
V_441 = ( V_507 -> V_539 * V_132 ) /
V_179 -> V_538 ;
}
V_554 += V_179 -> V_538 *
F_135 ( V_179 -> V_539 , V_179 -> V_432 + V_441 ) ;
V_554 /= V_132 ;
if ( V_554 > V_553 )
V_136 -> V_430 = V_507 -> V_539 ;
}
static inline void F_394 ( struct V_471 * V_136 , struct V_505 * V_506 )
{
unsigned long V_557 , V_558 = ~ 0UL ;
struct V_532 * V_179 , * V_507 ;
V_179 = & V_506 -> V_550 ;
V_507 = & V_506 -> V_510 ;
if ( V_507 -> V_540 ) {
V_507 -> V_539 =
F_135 ( V_507 -> V_539 , V_506 -> V_432 ) ;
}
if ( V_507 -> V_432 <= V_506 -> V_432 ||
V_179 -> V_432 >= V_506 -> V_432 ) {
V_136 -> V_430 = 0 ;
return F_393 ( V_136 , V_506 ) ;
}
if ( ! V_507 -> V_540 ) {
V_558 =
( V_507 -> V_535 - V_507 -> V_541 ) ;
V_558 *= ( V_559 * V_132 ) ;
V_558 /= V_507 -> V_538 ;
}
V_557 = F_135 ( V_507 -> V_432 - V_506 -> V_432 , V_558 ) ;
V_136 -> V_430 = F_135 (
V_557 * V_507 -> V_538 ,
( V_506 -> V_432 - V_179 -> V_432 ) * V_179 -> V_538
) / V_132 ;
if ( V_136 -> V_430 < V_507 -> V_539 )
return F_393 ( V_136 , V_506 ) ;
}
static struct V_422 * F_395 ( struct V_471 * V_136 )
{
struct V_532 * V_179 , * V_507 ;
struct V_505 V_506 ;
F_371 ( & V_506 ) ;
F_390 ( V_136 , & V_506 ) ;
V_179 = & V_506 . V_550 ;
V_507 = & V_506 . V_510 ;
if ( ( V_136 -> V_354 == V_560 || V_136 -> V_354 == V_501 ) &&
F_392 ( V_136 , & V_506 ) )
return V_506 . V_507 ;
if ( ! V_506 . V_507 || V_507 -> V_535 == 0 )
goto V_561;
V_506 . V_432 = ( V_132 * V_506 . V_508 )
/ V_506 . V_509 ;
if ( V_507 -> V_540 )
goto V_562;
if ( V_136 -> V_354 == V_501 && V_179 -> V_542 &&
! V_507 -> V_542 )
goto V_562;
if ( V_179 -> V_432 >= V_507 -> V_432 )
goto V_561;
if ( V_179 -> V_432 >= V_506 . V_432 )
goto V_561;
if ( V_136 -> V_354 == V_560 ) {
if ( ( V_179 -> V_537 < V_507 -> V_537 ) &&
V_507 -> V_535 <= V_507 -> F_97 )
goto V_561;
} else {
if ( 100 * V_507 -> V_432 <=
V_136 -> V_160 -> V_147 * V_179 -> V_432 )
goto V_561;
}
V_562:
F_394 ( V_136 , & V_506 ) ;
return V_506 . V_507 ;
V_561:
V_136 -> V_430 = 0 ;
return NULL ;
}
static struct V_24 * F_396 ( struct V_471 * V_136 ,
struct V_422 * V_114 )
{
struct V_24 * V_507 = NULL , * V_24 ;
unsigned long V_563 = 0 , V_564 = 1 ;
int V_196 ;
F_328 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_435 , V_530 , V_405 ;
enum V_544 V_565 ;
V_24 = F_108 ( V_196 ) ;
V_565 = F_389 ( V_24 ) ;
if ( V_565 > V_136 -> V_544 )
continue;
V_435 = F_110 ( V_196 ) ;
V_530 = F_111 ( V_435 , V_132 ) ;
if ( ! V_530 )
V_530 = F_381 ( V_136 -> V_160 , V_114 ) ;
V_405 = F_109 ( V_196 ) ;
if ( V_530 && V_24 -> V_72 == 1 && V_405 > V_136 -> V_430 )
continue;
if ( V_405 * V_564 > V_563 * V_435 ) {
V_563 = V_405 ;
V_564 = V_435 ;
V_507 = V_24 ;
}
}
return V_507 ;
}
static int F_397 ( struct V_471 * V_136 )
{
struct V_159 * V_160 = V_136 -> V_160 ;
if ( V_136 -> V_354 == V_501 ) {
if ( ( V_160 -> V_206 & V_543 ) && V_136 -> V_151 > V_136 -> V_120 )
return 1 ;
}
return F_14 ( V_160 -> V_488 > V_160 -> V_489 + 2 ) ;
}
static int F_398 ( struct V_471 * V_136 )
{
struct V_422 * V_437 = V_136 -> V_160 -> V_425 ;
struct V_566 * V_567 , * V_568 ;
int V_130 , V_569 = - 1 ;
if ( V_136 -> V_354 == V_501 )
return 1 ;
V_567 = F_326 ( V_437 ) ;
V_568 = F_399 ( V_437 ) ;
F_328 (cpu, sg_cpus, env->cpus) {
if ( ! F_120 ( V_130 , V_568 ) || ! F_330 ( V_130 ) )
continue;
V_569 = V_130 ;
break;
}
if ( V_569 == - 1 )
V_569 = F_400 ( V_437 ) ;
return V_569 == V_136 -> V_120 ;
}
static int F_401 ( int V_412 , struct V_24 * V_307 ,
struct V_159 * V_160 , enum V_511 V_354 ,
int * V_570 )
{
int V_571 , V_572 , V_573 = 0 ;
struct V_159 * V_574 = V_160 -> V_34 ;
struct V_422 * V_114 ;
struct V_24 * V_507 ;
unsigned long V_206 ;
struct V_566 * V_8 = F_402 ( V_575 ) ;
struct V_471 V_136 = {
. V_160 = V_160 ,
. V_120 = V_412 ,
. V_152 = V_307 ,
. V_481 = F_326 ( V_160 -> V_425 ) ,
. V_354 = V_354 ,
. V_497 = V_498 ,
. V_8 = V_8 ,
. V_544 = V_546 ,
} ;
if ( V_354 == V_501 )
V_136 . V_481 = NULL ;
F_403 ( V_8 , V_576 ) ;
F_230 ( V_160 , V_577 [ V_354 ] ) ;
V_578:
if ( ! F_398 ( & V_136 ) ) {
* V_570 = 0 ;
goto V_561;
}
V_114 = F_395 ( & V_136 ) ;
if ( ! V_114 ) {
F_230 ( V_160 , V_579 [ V_354 ] ) ;
goto V_561;
}
V_507 = F_396 ( & V_136 , V_114 ) ;
if ( ! V_507 ) {
F_230 ( V_160 , V_580 [ V_354 ] ) ;
goto V_561;
}
F_160 ( V_507 == V_136 . V_152 ) ;
F_69 ( V_160 , V_581 [ V_354 ] , V_136 . V_430 ) ;
V_571 = 0 ;
if ( V_507 -> V_72 > 1 ) {
V_136 . V_206 |= V_484 ;
V_136 . V_151 = V_507 -> V_130 ;
V_136 . V_150 = V_507 ;
V_136 . V_496 = F_135 ( V_582 , V_507 -> V_72 ) ;
V_583:
F_404 ( V_206 ) ;
F_405 ( V_136 . V_152 , V_507 ) ;
V_572 = F_361 ( & V_136 ) ;
V_571 += V_572 ;
F_406 ( V_136 . V_152 , V_507 ) ;
F_407 ( V_206 ) ;
if ( V_572 && V_136 . V_120 != F_261 () )
F_408 ( V_136 . V_120 ) ;
if ( V_136 . V_206 & V_499 ) {
V_136 . V_206 &= ~ V_499 ;
goto V_583;
}
if ( ( V_136 . V_206 & V_482 ) && V_136 . V_430 > 0 ) {
F_409 ( V_136 . V_120 , V_136 . V_8 ) ;
V_136 . V_152 = F_108 ( V_136 . V_483 ) ;
V_136 . V_120 = V_136 . V_483 ;
V_136 . V_206 &= ~ V_482 ;
V_136 . V_495 = 0 ;
V_136 . V_497 = V_498 ;
goto V_583;
}
if ( V_574 ) {
int * V_584 = & V_574 -> V_425 -> V_434 -> V_430 ;
if ( ( V_136 . V_206 & V_480 ) && V_136 . V_430 > 0 ) {
* V_584 = 1 ;
} else if ( * V_584 )
* V_584 = 0 ;
}
if ( F_14 ( V_136 . V_206 & V_484 ) ) {
F_409 ( F_27 ( V_507 ) , V_8 ) ;
if ( ! F_410 ( V_8 ) ) {
V_136 . V_495 = 0 ;
V_136 . V_497 = V_498 ;
goto V_578;
}
goto V_561;
}
}
if ( ! V_571 ) {
F_230 ( V_160 , V_585 [ V_354 ] ) ;
if ( V_354 != V_501 )
V_160 -> V_488 ++ ;
if ( F_397 ( & V_136 ) ) {
F_367 ( & V_507 -> V_195 , V_206 ) ;
if ( ! F_120 ( V_412 ,
F_121 ( V_507 -> V_45 ) ) ) {
F_368 ( & V_507 -> V_195 ,
V_206 ) ;
V_136 . V_206 |= V_484 ;
goto V_586;
}
if ( ! V_507 -> V_573 ) {
V_507 -> V_573 = 1 ;
V_507 -> V_587 = V_412 ;
V_573 = 1 ;
}
F_368 ( & V_507 -> V_195 , V_206 ) ;
if ( V_573 ) {
F_411 ( F_27 ( V_507 ) ,
V_588 , V_507 ,
& V_507 -> V_589 ) ;
}
V_160 -> V_488 = V_160 -> V_489 + 1 ;
}
} else
V_160 -> V_488 = 0 ;
if ( F_12 ( ! V_573 ) ) {
V_160 -> V_525 = V_160 -> V_590 ;
} else {
if ( V_160 -> V_525 < V_160 -> V_591 )
V_160 -> V_525 *= 2 ;
}
goto V_262;
V_561:
F_230 ( V_160 , V_592 [ V_354 ] ) ;
V_160 -> V_488 = 0 ;
V_586:
if ( ( ( V_136 . V_206 & V_484 ) &&
V_160 -> V_525 < V_593 ) ||
( V_160 -> V_525 < V_160 -> V_591 ) )
V_160 -> V_525 *= 2 ;
V_571 = 0 ;
V_262:
return V_571 ;
}
static inline unsigned long
F_412 ( struct V_159 * V_160 , int V_594 )
{
unsigned long V_167 = V_160 -> V_525 ;
if ( V_594 )
V_167 *= V_160 -> V_595 ;
V_167 = F_136 ( V_167 ) ;
V_167 = F_141 ( V_167 , 1UL , V_526 ) ;
return V_167 ;
}
static inline void
F_413 ( struct V_159 * V_160 , int V_594 , unsigned long * V_596 )
{
unsigned long V_167 , V_58 ;
V_167 = F_412 ( V_160 , V_594 ) ;
V_58 = V_160 -> V_597 + V_167 ;
if ( F_171 ( * V_596 , V_58 ) )
* V_596 = V_58 ;
}
static int F_221 ( struct V_24 * V_307 )
{
unsigned long V_596 = V_170 + V_168 ;
int V_412 = V_307 -> V_130 ;
struct V_159 * V_160 ;
int V_598 = 0 ;
T_2 V_599 = 0 ;
F_219 ( V_307 ) ;
V_307 -> V_600 = F_75 ( V_307 ) ;
if ( V_307 -> V_601 < V_473 ) {
F_118 () ;
V_160 = F_414 ( V_307 -> V_160 ) ;
if ( V_160 )
F_413 ( V_160 , 0 , & V_596 ) ;
F_123 () ;
goto V_262;
}
F_267 ( & V_307 -> V_195 ) ;
F_366 ( V_412 ) ;
F_118 () ;
F_335 (this_cpu, sd) {
int V_570 = 1 ;
T_2 V_602 , V_603 ;
if ( ! ( V_160 -> V_206 & V_447 ) )
continue;
if ( V_307 -> V_601 < V_599 + V_160 -> V_604 ) {
F_413 ( V_160 , 0 , & V_596 ) ;
break;
}
if ( V_160 -> V_206 & V_605 ) {
V_602 = F_260 ( V_412 ) ;
V_598 = F_401 ( V_412 , V_307 ,
V_160 , V_501 ,
& V_570 ) ;
V_603 = F_260 ( V_412 ) - V_602 ;
if ( V_603 > V_160 -> V_604 )
V_160 -> V_604 = V_603 ;
V_599 += V_603 ;
}
F_413 ( V_160 , 0 , & V_596 ) ;
if ( V_598 || V_307 -> V_72 > 0 )
break;
}
F_123 () ;
F_265 ( & V_307 -> V_195 ) ;
if ( V_599 > V_307 -> V_606 )
V_307 -> V_606 = V_599 ;
if ( V_307 -> V_40 . V_364 && ! V_598 )
V_598 = 1 ;
V_262:
if ( F_171 ( V_307 -> V_596 , V_596 ) )
V_307 -> V_596 = V_596 ;
if ( V_307 -> V_72 != V_307 -> V_40 . V_364 )
V_598 = - 1 ;
if ( V_598 ) {
F_220 ( V_307 ) ;
V_307 -> V_600 = 0 ;
}
return V_598 ;
}
static int V_588 ( void * V_360 )
{
struct V_24 * V_607 = V_360 ;
int V_552 = F_27 ( V_607 ) ;
int V_608 = V_607 -> V_587 ;
struct V_24 * V_609 = F_108 ( V_608 ) ;
struct V_159 * V_160 ;
F_415 ( & V_607 -> V_195 ) ;
if ( F_14 ( V_552 != F_261 () ||
! V_607 -> V_573 ) )
goto V_610;
if ( V_607 -> V_72 <= 1 )
goto V_610;
F_160 ( V_607 == V_609 ) ;
F_416 ( V_607 , V_609 ) ;
F_118 () ;
F_335 (target_cpu, sd) {
if ( ( V_160 -> V_206 & V_447 ) &&
F_120 ( V_552 , F_336 ( V_160 ) ) )
break;
}
if ( F_12 ( V_160 ) ) {
struct V_471 V_136 = {
. V_160 = V_160 ,
. V_120 = V_608 ,
. V_152 = V_609 ,
. V_151 = V_607 -> V_130 ,
. V_150 = V_607 ,
. V_354 = V_560 ,
} ;
F_230 ( V_160 , V_611 ) ;
if ( F_359 ( & V_136 ) )
F_230 ( V_160 , V_612 ) ;
else
F_230 ( V_160 , V_613 ) ;
}
F_123 () ;
F_417 ( V_607 , V_609 ) ;
V_610:
V_607 -> V_573 = 0 ;
F_418 ( & V_607 -> V_195 ) ;
return 0 ;
}
static inline int F_419 ( struct V_24 * V_24 )
{
return F_14 ( ! F_420 ( V_24 -> V_160 ) ) ;
}
static inline int F_421 ( void )
{
int V_614 = F_422 ( V_615 . V_616 ) ;
if ( V_614 < V_617 && F_330 ( V_614 ) )
return V_614 ;
return V_617 ;
}
static void F_423 ( void )
{
int V_618 ;
V_615 . V_596 ++ ;
V_618 = F_421 () ;
if ( V_618 >= V_617 )
return;
if ( F_424 ( V_619 , F_425 ( V_618 ) ) )
return;
F_426 ( V_618 ) ;
return;
}
static inline void F_427 ( int V_130 )
{
if ( F_14 ( F_428 ( V_620 , F_425 ( V_130 ) ) ) ) {
if ( F_12 ( F_120 ( V_130 , V_615 . V_616 ) ) ) {
F_409 ( V_130 , V_615 . V_616 ) ;
F_429 ( & V_615 . V_621 ) ;
}
F_430 ( V_620 , F_425 ( V_130 ) ) ;
}
}
static inline void F_431 ( void )
{
struct V_159 * V_160 ;
int V_130 = F_261 () ;
F_118 () ;
V_160 = F_127 ( F_128 ( V_622 , V_130 ) ) ;
if ( ! V_160 || ! V_160 -> V_623 )
goto V_154;
V_160 -> V_623 = 0 ;
F_432 ( & V_160 -> V_425 -> V_434 -> V_624 ) ;
V_154:
F_123 () ;
}
void F_433 ( void )
{
struct V_159 * V_160 ;
int V_130 = F_261 () ;
F_118 () ;
V_160 = F_127 ( F_128 ( V_622 , V_130 ) ) ;
if ( ! V_160 || V_160 -> V_623 )
goto V_154;
V_160 -> V_623 = 1 ;
F_429 ( & V_160 -> V_425 -> V_434 -> V_624 ) ;
V_154:
F_123 () ;
}
void F_434 ( int V_130 )
{
if ( ! F_435 ( V_130 ) )
return;
if ( F_428 ( V_620 , F_425 ( V_130 ) ) )
return;
if ( F_419 ( F_108 ( V_130 ) ) )
return;
F_436 ( V_130 , V_615 . V_616 ) ;
F_432 ( & V_615 . V_621 ) ;
F_437 ( V_620 , F_425 ( V_130 ) ) ;
}
static int F_438 ( struct V_625 * V_626 ,
unsigned long V_627 , void * V_628 )
{
switch ( V_627 & ~ V_629 ) {
case V_630 :
F_427 ( F_261 () ) ;
return V_631 ;
default:
return V_632 ;
}
}
void F_439 ( void )
{
V_526 = V_168 * F_6 () / 10 ;
}
static void F_440 ( struct V_24 * V_24 , enum V_511 V_354 )
{
int V_570 = 1 ;
int V_130 = V_24 -> V_130 ;
unsigned long V_167 ;
struct V_159 * V_160 ;
unsigned long V_596 = V_170 + 60 * V_168 ;
int F_413 = 0 ;
int V_633 , V_634 = 0 ;
T_2 V_635 = 0 ;
F_366 ( V_130 ) ;
F_118 () ;
F_335 (cpu, sd) {
if ( F_171 ( V_170 , V_160 -> V_636 ) ) {
V_160 -> V_604 =
( V_160 -> V_604 * 253 ) / 256 ;
V_160 -> V_636 = V_170 + V_168 ;
V_634 = 1 ;
}
V_635 += V_160 -> V_604 ;
if ( ! ( V_160 -> V_206 & V_447 ) )
continue;
if ( ! V_570 ) {
if ( V_634 )
continue;
break;
}
V_167 = F_412 ( V_160 , V_354 != V_560 ) ;
V_633 = V_160 -> V_206 & V_637 ;
if ( V_633 ) {
if ( ! F_441 ( & V_638 ) )
goto V_262;
}
if ( F_391 ( V_170 , V_160 -> V_597 + V_167 ) ) {
if ( F_401 ( V_130 , V_24 , V_160 , V_354 , & V_570 ) ) {
V_354 = F_330 ( V_130 ) ? V_560 : V_512 ;
}
V_160 -> V_597 = V_170 ;
V_167 = F_412 ( V_160 , V_354 != V_560 ) ;
}
if ( V_633 )
F_164 ( & V_638 ) ;
V_262:
if ( F_171 ( V_596 , V_160 -> V_597 + V_167 ) ) {
V_596 = V_160 -> V_597 + V_167 ;
F_413 = 1 ;
}
}
if ( V_634 ) {
V_24 -> V_606 =
F_68 ( ( T_2 ) V_473 , V_635 ) ;
}
F_123 () ;
if ( F_12 ( F_413 ) )
V_24 -> V_596 = V_596 ;
}
static void F_442 ( struct V_24 * V_307 , enum V_511 V_354 )
{
int V_412 = V_307 -> V_130 ;
struct V_24 * V_24 ;
int V_569 ;
if ( V_354 != V_560 ||
! F_428 ( V_619 , F_425 ( V_412 ) ) )
goto V_243;
F_107 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_569 == V_412 || ! F_330 ( V_569 ) )
continue;
if ( F_443 () )
break;
V_24 = F_108 ( V_569 ) ;
if ( F_391 ( V_170 , V_24 -> V_596 ) ) {
F_415 ( & V_24 -> V_195 ) ;
F_278 ( V_24 ) ;
F_444 ( V_24 ) ;
F_418 ( & V_24 -> V_195 ) ;
F_440 ( V_24 , V_560 ) ;
}
if ( F_171 ( V_307 -> V_596 , V_24 -> V_596 ) )
V_307 -> V_596 = V_24 -> V_596 ;
}
V_615 . V_596 = V_307 -> V_596 ;
V_243:
F_430 ( V_619 , F_425 ( V_412 ) ) ;
}
static inline int F_445 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_170 ;
struct V_159 * V_160 ;
struct V_529 * V_434 ;
int V_639 , V_130 = V_24 -> V_130 ;
if ( F_14 ( V_24 -> F_221 ) )
return 0 ;
F_431 () ;
F_427 ( V_130 ) ;
if ( F_12 ( ! F_208 ( & V_615 . V_621 ) ) )
return 0 ;
if ( F_174 ( V_81 , V_615 . V_596 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_640;
F_118 () ;
V_160 = F_127 ( F_128 ( V_622 , V_130 ) ) ;
if ( V_160 ) {
V_434 = V_160 -> V_425 -> V_434 ;
V_639 = F_208 ( & V_434 -> V_624 ) ;
if ( V_639 > 1 )
goto V_641;
}
V_160 = F_127 ( F_128 ( V_642 , V_130 ) ) ;
if ( V_160 && ( F_333 ( V_615 . V_616 ,
F_336 ( V_160 ) ) < V_130 ) )
goto V_641;
F_123 () ;
return 0 ;
V_641:
F_123 () ;
V_640:
return 1 ;
}
static void F_442 ( struct V_24 * V_307 , enum V_511 V_354 ) { }
static void F_446 ( struct V_643 * V_644 )
{
struct V_24 * V_307 = V_307 () ;
enum V_511 V_354 = V_307 -> F_221 ?
V_560 : V_512 ;
F_440 ( V_307 , V_354 ) ;
F_442 ( V_307 , V_354 ) ;
}
void F_447 ( struct V_24 * V_24 )
{
if ( F_14 ( F_419 ( V_24 ) ) )
return;
if ( F_391 ( V_170 , V_24 -> V_596 ) )
F_448 ( V_645 ) ;
#ifdef F_449
if ( F_445 ( V_24 ) )
F_423 () ;
#endif
}
static void F_450 ( struct V_24 * V_24 )
{
F_8 () ;
}
static void F_451 ( struct V_24 * V_24 )
{
F_8 () ;
F_304 ( V_24 ) ;
}
static void F_452 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_335 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_248 ( V_25 , V_28 , V_335 ) ;
}
if ( V_227 )
F_184 ( V_24 , V_45 ) ;
F_209 ( V_24 , 1 ) ;
}
static void F_453 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_412 = F_261 () ;
struct V_24 * V_24 = V_307 () ;
unsigned long V_206 ;
F_367 ( & V_24 -> V_195 , V_206 ) ;
F_278 ( V_24 ) ;
V_25 = F_23 ( V_125 ) ;
V_45 = V_25 -> V_45 ;
F_118 () ;
F_454 ( V_29 , V_412 ) ;
F_123 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_231 ( V_25 , V_28 , 1 ) ;
if ( V_646 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_116 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_242 ( V_24 -> V_45 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_368 ( & V_24 -> V_195 , V_206 ) ;
}
static void
F_455 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_647 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_648 > V_647 )
F_242 ( V_24 -> V_45 ) ;
} else
F_353 ( V_24 , V_29 , 0 ) ;
}
static void F_456 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_29 -> V_76 && V_29 -> V_228 != V_649 ) {
F_231 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_188
if ( V_28 -> V_77 . V_78 ) {
F_200 ( V_28 ) ;
F_212 ( V_25 , V_28 -> V_77 . V_291 ) ;
}
#endif
}
static void F_457 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
#ifdef F_344
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! V_28 -> V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_242 ( V_24 -> V_45 ) ;
else
F_353 ( V_24 , V_29 , 0 ) ;
}
static void F_458 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_243 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_459 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_650 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_188
F_460 ( & V_25 -> V_290 , 1 ) ;
F_461 ( & V_25 -> V_304 , 0 ) ;
#endif
}
static void F_462 ( struct V_26 * V_29 , int V_76 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_28 -> V_85 || V_29 -> V_228 == V_651 ) )
V_76 = 1 ;
if ( ! V_76 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_463 ( V_29 , F_126 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_76 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_188
V_28 -> V_77 . V_78 = F_201 ( & V_25 -> V_290 ) ;
V_25 -> V_295 += V_28 -> V_77 . V_291 ;
#endif
}
}
void F_464 ( struct V_266 * V_33 )
{
int V_196 ;
F_302 ( F_263 ( V_33 ) ) ;
F_465 (i) {
if ( V_33 -> V_25 )
F_169 ( V_33 -> V_25 [ V_196 ] ) ;
if ( V_33 -> V_28 )
F_169 ( V_33 -> V_28 [ V_196 ] ) ;
}
F_169 ( V_33 -> V_25 ) ;
F_169 ( V_33 -> V_28 ) ;
}
int F_466 ( struct V_266 * V_33 , struct V_266 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_196 ;
V_33 -> V_25 = F_154 ( sizeof( V_25 ) * V_617 , V_212 ) ;
if ( ! V_33 -> V_25 )
goto V_652;
V_33 -> V_28 = F_154 ( sizeof( V_28 ) * V_617 , V_212 ) ;
if ( ! V_33 -> V_28 )
goto V_652;
V_33 -> V_270 = V_71 ;
F_296 ( F_263 ( V_33 ) ) ;
F_465 (i) {
V_25 = F_467 ( sizeof( struct V_25 ) ,
V_212 , F_99 ( V_196 ) ) ;
if ( ! V_25 )
goto V_652;
V_28 = F_467 ( sizeof( struct V_27 ) ,
V_212 , F_99 ( V_196 ) ) ;
if ( ! V_28 )
goto V_653;
F_459 ( V_25 ) ;
F_468 ( V_33 , V_25 , V_28 , V_196 , V_34 -> V_28 [ V_196 ] ) ;
}
return 1 ;
V_653:
F_169 ( V_25 ) ;
V_652:
return 0 ;
}
void F_469 ( struct V_266 * V_33 , int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_206 ;
if ( ! V_33 -> V_25 [ V_130 ] -> V_32 )
return;
F_367 ( & V_24 -> V_195 , V_206 ) ;
F_31 ( V_33 -> V_25 [ V_130 ] ) ;
F_368 ( & V_24 -> V_195 , V_206 ) ;
}
void F_468 ( struct V_266 * V_33 , struct V_25 * V_25 ,
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
int F_470 ( struct V_266 * V_33 , unsigned long V_270 )
{
int V_196 ;
unsigned long V_206 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_164 ;
V_270 = F_141 ( V_270 , F_210 ( V_271 ) , F_210 ( V_654 ) ) ;
F_471 ( & V_655 ) ;
if ( V_33 -> V_270 == V_270 )
goto V_439;
V_33 -> V_270 = V_270 ;
F_465 (i) {
struct V_24 * V_24 = F_108 ( V_196 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_196 ] ;
F_367 ( & V_24 -> V_195 , V_206 ) ;
F_278 ( V_24 ) ;
F_61 (se)
F_195 ( F_25 ( V_28 ) ) ;
F_368 ( & V_24 -> V_195 , V_206 ) ;
}
V_439:
F_472 ( & V_655 ) ;
return 0 ;
}
void F_464 ( struct V_266 * V_33 ) { }
int F_466 ( struct V_266 * V_33 , struct V_266 * V_34 )
{
return 1 ;
}
void F_469 ( struct V_266 * V_33 , int V_130 ) { }
static unsigned int F_473 ( struct V_24 * V_24 , struct V_26 * V_656 )
{
struct V_27 * V_28 = & V_656 -> V_28 ;
unsigned int V_657 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_657 = F_474 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_657 ;
}
void F_475 ( struct V_658 * V_659 , int V_130 )
{
struct V_25 * V_25 ;
F_118 () ;
F_305 (cpu_rq(cpu), cfs_rq)
F_476 ( V_659 , V_130 , V_25 ) ;
F_123 () ;
}
T_12 void F_477 ( void )
{
#ifdef F_188
F_478 ( V_645 , F_446 ) ;
#ifdef F_449
V_615 . V_596 = V_170 ;
F_479 ( & V_615 . V_616 , V_660 ) ;
F_480 ( F_438 , 0 ) ;
#endif
#endif
}
