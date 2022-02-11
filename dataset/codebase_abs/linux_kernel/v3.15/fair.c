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
V_129 -> V_133 = F_111 ( V_129 -> V_131 , V_132 ) ;
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
static void F_115 ( struct V_135 * V_136 ,
long V_141 , long V_142 )
{
struct V_24 * V_143 = F_108 ( V_136 -> V_144 ) ;
struct V_24 * V_145 = F_108 ( V_136 -> V_120 ) ;
struct V_26 * V_146 ;
long V_147 , V_148 ;
long V_70 ;
long V_137 = ( V_142 > 0 ) ? V_142 : V_141 ;
F_116 () ;
V_146 = F_117 ( V_145 -> V_45 ) ;
if ( V_146 -> V_126 == 0 )
V_146 = NULL ;
if ( V_146 ) {
if ( ! F_118 ( V_136 -> V_144 , F_119 ( V_146 ) ) )
goto V_149;
if ( V_146 -> V_107 == V_136 -> V_29 -> V_107 ) {
V_137 = V_141 + F_96 ( V_146 , V_136 -> V_119 ) -
F_96 ( V_146 , V_136 -> V_122 ) ;
if ( V_146 -> V_107 )
V_137 -= V_137 / 16 ;
} else {
if ( V_136 -> V_29 -> V_107 )
V_137 = V_142 ;
else
V_137 = V_141 ;
if ( V_146 -> V_107 )
V_137 += F_97 ( V_146 , V_136 -> V_119 ) -
F_97 ( V_146 , V_136 -> V_122 ) ;
else
V_137 += F_96 ( V_146 , V_136 -> V_119 ) -
F_96 ( V_146 , V_136 -> V_122 ) ;
}
}
if ( V_137 < V_136 -> V_139 )
goto V_149;
if ( ! V_146 ) {
if ( V_136 -> V_150 . V_134 &&
! V_136 -> V_151 . V_134 )
goto V_149;
goto V_152;
}
if ( V_143 -> V_72 == 1 && V_145 -> V_72 == 1 )
goto V_153;
V_152:
V_147 = V_136 -> V_151 . V_70 ;
V_148 = V_136 -> V_150 . V_70 ;
V_70 = F_120 ( V_136 -> V_29 ) ;
V_147 += V_70 ;
V_148 -= V_70 ;
if ( V_146 ) {
V_70 = F_120 ( V_146 ) ;
V_147 -= V_70 ;
V_148 += V_70 ;
}
if ( V_147 < V_148 )
F_121 ( V_147 , V_148 ) ;
if ( V_148 * V_136 -> V_154 < V_147 * 100 )
goto V_149;
V_153:
F_112 ( V_136 , V_146 , V_137 ) ;
V_149:
F_122 () ;
}
static void F_123 ( struct V_135 * V_136 ,
long V_141 , long V_142 )
{
int V_130 ;
F_107 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_118 ( V_130 , F_119 ( V_136 -> V_29 ) ) )
continue;
V_136 -> V_120 = V_130 ;
F_115 ( V_136 , V_141 , V_142 ) ;
}
}
static int F_124 ( struct V_26 * V_29 )
{
struct V_135 V_136 = {
. V_29 = V_29 ,
. V_144 = F_125 ( V_29 ) ,
. V_119 = F_89 ( V_29 ) ,
. V_154 = 112 ,
. V_138 = NULL ,
. V_139 = 0 ,
. V_140 = - 1
} ;
struct V_155 * V_156 ;
unsigned long V_157 , V_158 ;
int V_109 , V_66 ;
long V_141 , V_142 ;
F_116 () ;
V_156 = F_126 ( F_127 ( V_159 , V_136 . V_144 ) ) ;
if ( V_156 )
V_136 . V_154 = 100 + ( V_156 -> V_154 - 100 ) / 2 ;
F_122 () ;
if ( F_14 ( ! V_156 ) ) {
V_29 -> V_105 = F_89 ( V_29 ) ;
return - V_160 ;
}
V_157 = F_96 ( V_29 , V_136 . V_119 ) ;
V_158 = F_97 ( V_29 , V_136 . V_119 ) ;
F_106 ( & V_136 . V_150 , V_136 . V_119 ) ;
V_136 . V_122 = V_29 -> V_105 ;
V_141 = F_96 ( V_29 , V_136 . V_122 ) - V_157 ;
V_142 = F_97 ( V_29 , V_136 . V_122 ) - V_158 ;
F_106 ( & V_136 . V_151 , V_136 . V_122 ) ;
if ( V_136 . V_151 . V_134 )
F_123 ( & V_136 , V_141 , V_142 ) ;
if ( V_136 . V_140 == - 1 ) {
F_128 (nid) {
if ( V_109 == V_136 . V_119 || V_109 == V_29 -> V_105 )
continue;
V_141 = F_96 ( V_29 , V_109 ) - V_157 ;
V_142 = F_97 ( V_29 , V_109 ) - V_158 ;
if ( V_141 < 0 && V_142 < 0 )
continue;
V_136 . V_122 = V_109 ;
F_106 ( & V_136 . V_151 , V_136 . V_122 ) ;
F_123 ( & V_136 , V_141 , V_142 ) ;
}
}
if ( V_136 . V_140 == - 1 )
return - V_161 ;
F_129 ( V_29 , V_136 . V_122 ) ;
V_29 -> V_162 = F_85 ( V_29 ) ;
if ( V_136 . V_138 == NULL ) {
V_66 = F_130 ( V_29 , V_136 . V_140 ) ;
if ( V_66 != 0 )
F_131 ( V_29 , V_136 . V_144 , V_136 . V_140 ) ;
return V_66 ;
}
V_66 = F_132 ( V_29 , V_136 . V_138 ) ;
if ( V_66 != 0 )
F_131 ( V_29 , V_136 . V_144 , F_125 ( V_136 . V_138 ) ) ;
F_113 ( V_136 . V_138 ) ;
return V_66 ;
}
static void F_133 ( struct V_26 * V_29 )
{
if ( F_14 ( V_29 -> V_105 == - 1 || ! V_29 -> V_112 ) )
return;
V_29 -> V_163 = V_164 + V_165 ;
if ( F_89 ( V_29 ) == V_29 -> V_105 )
return;
F_124 ( V_29 ) ;
}
static void F_134 ( struct V_107 * V_107 )
{
unsigned long V_113 , V_166 = 0 ;
int V_109 ;
F_128 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( V_113 > V_166 )
V_166 = V_113 ;
}
F_128 (nid) {
V_113 = F_95 ( V_107 , V_109 ) ;
if ( ! F_105 ( V_109 , V_107 -> V_127 ) ) {
if ( V_113 > V_166 * 6 / 16 )
F_135 ( V_109 , V_107 -> V_127 ) ;
} else if ( V_113 < V_166 * 3 / 16 )
F_136 ( V_109 , V_107 -> V_127 ) ;
}
}
static void F_137 ( struct V_26 * V_29 ,
unsigned long V_167 , unsigned long V_168 )
{
unsigned int V_169 ;
int V_170 ;
int V_171 ;
unsigned long V_172 = V_29 -> V_173 [ 0 ] ;
unsigned long V_174 = V_29 -> V_173 [ 1 ] ;
if ( V_174 + V_167 == 0 ) {
V_29 -> V_162 = F_138 ( V_29 -> V_175 ,
V_29 -> V_162 << 1 ) ;
V_29 -> V_96 -> V_176 = V_164 +
F_139 ( V_29 -> V_162 ) ;
return;
}
V_169 = F_56 ( V_29 -> V_162 , V_177 ) ;
V_170 = ( V_174 * V_177 ) / ( V_174 + V_172 ) ;
if ( V_170 >= V_178 ) {
int V_179 = V_170 - V_178 ;
if ( ! V_179 )
V_179 = 1 ;
V_171 = V_179 * V_169 ;
} else {
V_171 = - ( V_178 - V_170 ) * V_169 ;
V_170 = F_56 ( V_168 * V_177 , ( V_168 + V_167 ) ) ;
V_171 = ( V_171 * V_170 ) / V_177 ;
}
V_29 -> V_162 = F_140 ( V_29 -> V_162 + V_171 ,
F_85 ( V_29 ) , F_87 ( V_29 ) ) ;
memset ( V_29 -> V_173 , 0 , sizeof( V_29 -> V_173 ) ) ;
}
static T_2 F_141 ( struct V_26 * V_29 , T_2 * V_73 )
{
T_2 V_180 , V_42 , V_81 ;
V_81 = V_29 -> V_28 . V_82 ;
V_180 = V_29 -> V_28 . V_85 ;
if ( V_29 -> V_181 ) {
V_42 = V_180 - V_29 -> V_182 ;
* V_73 = V_81 - V_29 -> V_181 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_79 ;
* V_73 = V_29 -> V_28 . V_77 . V_80 ;
}
V_29 -> V_182 = V_180 ;
V_29 -> V_181 = V_81 ;
return V_42 ;
}
static void F_142 ( struct V_26 * V_29 )
{
int V_183 , V_109 , V_184 = - 1 , V_185 = - 1 ;
unsigned long V_166 = 0 , V_186 = 0 ;
unsigned long V_187 [ 2 ] = { 0 , 0 } ;
unsigned long V_116 ;
T_2 V_180 , V_73 ;
T_8 * V_188 = NULL ;
V_183 = F_117 ( V_29 -> V_96 -> V_189 ) ;
if ( V_29 -> V_189 == V_183 )
return;
V_29 -> V_189 = V_183 ;
V_29 -> V_175 = F_87 ( V_29 ) ;
V_116 = V_29 -> V_173 [ 0 ] +
V_29 -> V_173 [ 1 ] ;
V_180 = F_141 ( V_29 , & V_73 ) ;
if ( V_29 -> V_107 ) {
V_188 = & V_29 -> V_107 -> V_190 ;
F_143 ( V_188 ) ;
}
F_128 (nid) {
unsigned long V_113 = 0 , F_94 = 0 ;
int V_110 , V_191 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
long V_171 , V_192 , V_193 ;
V_191 = F_92 ( V_109 , V_110 ) ;
V_171 = V_29 -> V_194 [ V_191 ] - V_29 -> V_112 [ V_191 ] / 2 ;
V_187 [ V_110 ] += V_29 -> V_194 [ V_191 ] ;
V_29 -> V_194 [ V_191 ] = 0 ;
V_193 = F_144 ( V_180 << 16 , V_73 + 1 ) ;
V_193 = ( V_193 * V_29 -> V_195 [ V_191 ] ) /
( V_116 + 1 ) ;
V_192 = V_193 - V_29 -> V_196 [ V_191 ] / 2 ;
V_29 -> V_195 [ V_191 ] = 0 ;
V_29 -> V_112 [ V_191 ] += V_171 ;
V_29 -> V_196 [ V_191 ] += V_192 ;
V_113 += V_29 -> V_112 [ V_191 ] ;
V_29 -> V_117 += V_171 ;
if ( V_29 -> V_107 ) {
V_29 -> V_107 -> V_113 [ V_191 ] += V_171 ;
V_29 -> V_107 -> V_115 [ V_191 ] += V_192 ;
V_29 -> V_107 -> V_116 += V_171 ;
F_94 += V_29 -> V_107 -> V_113 [ V_191 ] ;
}
}
if ( V_113 > V_166 ) {
V_166 = V_113 ;
V_184 = V_109 ;
}
if ( F_94 > V_186 ) {
V_186 = F_94 ;
V_185 = V_109 ;
}
}
F_137 ( V_29 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
if ( V_29 -> V_107 ) {
F_134 ( V_29 -> V_107 ) ;
if ( V_184 != V_185 ) {
unsigned long V_4 , V_197 = 0 ;
F_128 (nid) {
V_4 = F_96 ( V_29 , V_109 ) + F_97 ( V_29 , V_109 ) ;
if ( V_4 > V_197 ) {
V_197 = V_4 ;
V_184 = V_109 ;
}
}
}
F_145 ( V_188 ) ;
}
if ( V_166 && V_184 != V_29 -> V_105 ) {
F_129 ( V_29 , V_184 ) ;
F_133 ( V_29 ) ;
}
}
static inline int F_146 ( struct V_107 * V_30 )
{
return F_147 ( & V_30 -> V_198 ) ;
}
static inline void F_148 ( struct V_107 * V_30 )
{
if ( F_149 ( & V_30 -> V_198 ) )
F_150 ( V_30 , V_199 ) ;
}
static void F_151 ( struct V_26 * V_29 , int V_200 , int V_201 ,
int * V_110 )
{
struct V_107 * V_30 , * V_202 ;
struct V_26 * V_203 ;
bool V_204 = false ;
int V_130 = F_152 ( V_200 ) ;
int V_191 ;
if ( F_14 ( ! V_29 -> V_107 ) ) {
unsigned int V_205 = sizeof( struct V_107 ) +
4 * V_206 *sizeof( unsigned long ) ;
V_30 = F_153 ( V_205 , V_207 | V_208 ) ;
if ( ! V_30 )
return;
F_154 ( & V_30 -> V_198 , 1 ) ;
F_155 ( & V_30 -> V_190 ) ;
F_156 ( & V_30 -> V_209 ) ;
V_30 -> V_108 = V_29 -> V_126 ;
V_30 -> V_115 = V_30 -> V_113 + V_111 *
V_206 ;
F_135 ( F_89 ( V_125 ) , V_30 -> V_127 ) ;
for ( V_191 = 0 ; V_191 < V_210 * V_206 ; V_191 ++ )
V_30 -> V_113 [ V_191 ] = V_29 -> V_112 [ V_191 ] ;
V_30 -> V_116 = V_29 -> V_117 ;
F_157 ( & V_29 -> V_211 , & V_30 -> V_209 ) ;
V_30 -> V_212 ++ ;
F_158 ( V_29 -> V_107 , V_30 ) ;
}
F_116 () ;
V_203 = F_117 ( F_108 ( V_130 ) -> V_45 ) ;
if ( ! F_104 ( V_203 , V_200 ) )
goto V_213;
V_30 = F_126 ( V_203 -> V_107 ) ;
if ( ! V_30 )
goto V_213;
V_202 = V_29 -> V_107 ;
if ( V_30 == V_202 )
goto V_213;
if ( V_202 -> V_212 > V_30 -> V_212 )
goto V_213;
if ( V_202 -> V_212 == V_30 -> V_212 && V_202 > V_30 )
goto V_213;
if ( V_203 -> V_96 == V_125 -> V_96 )
V_204 = true ;
if ( V_201 & V_214 )
V_204 = true ;
* V_110 = ! V_204 ;
if ( V_204 && ! F_146 ( V_30 ) )
goto V_213;
F_122 () ;
if ( ! V_204 )
return;
F_159 ( F_160 () ) ;
F_161 ( & V_202 -> V_190 , & V_30 -> V_190 ) ;
for ( V_191 = 0 ; V_191 < V_210 * V_206 ; V_191 ++ ) {
V_202 -> V_113 [ V_191 ] -= V_29 -> V_112 [ V_191 ] ;
V_30 -> V_113 [ V_191 ] += V_29 -> V_112 [ V_191 ] ;
}
V_202 -> V_116 -= V_29 -> V_117 ;
V_30 -> V_116 += V_29 -> V_117 ;
F_162 ( & V_29 -> V_211 , & V_30 -> V_209 ) ;
V_202 -> V_212 -- ;
V_30 -> V_212 ++ ;
F_163 ( & V_202 -> V_190 ) ;
F_145 ( & V_30 -> V_190 ) ;
F_158 ( V_29 -> V_107 , V_30 ) ;
F_148 ( V_202 ) ;
return;
V_213:
F_122 () ;
return;
}
void F_164 ( struct V_26 * V_29 )
{
struct V_107 * V_30 = V_29 -> V_107 ;
void * V_215 = V_29 -> V_112 ;
unsigned long V_201 ;
int V_191 ;
if ( V_30 ) {
F_165 ( & V_30 -> V_190 , V_201 ) ;
for ( V_191 = 0 ; V_191 < V_210 * V_206 ; V_191 ++ )
V_30 -> V_113 [ V_191 ] -= V_29 -> V_112 [ V_191 ] ;
V_30 -> V_116 -= V_29 -> V_117 ;
F_166 ( & V_29 -> V_211 ) ;
V_30 -> V_212 -- ;
F_167 ( & V_30 -> V_190 , V_201 ) ;
F_158 ( V_29 -> V_107 , NULL ) ;
F_148 ( V_30 ) ;
}
V_29 -> V_112 = NULL ;
V_29 -> V_194 = NULL ;
V_29 -> V_196 = NULL ;
V_29 -> V_195 = NULL ;
F_168 ( V_215 ) ;
}
void F_169 ( int V_123 , int V_216 , int V_217 , int V_201 )
{
struct V_26 * V_29 = V_125 ;
bool V_218 = V_201 & V_219 ;
int V_220 = F_89 ( V_125 ) ;
int V_110 ;
if ( ! V_221 )
return;
if ( ! V_29 -> V_96 )
return;
if ( V_29 -> V_222 == V_223 )
return;
if ( F_14 ( ! V_29 -> V_112 ) ) {
int V_205 = sizeof( * V_29 -> V_112 ) *
V_224 * V_206 ;
V_29 -> V_112 = F_153 ( V_205 , V_207 | V_208 ) ;
if ( ! V_29 -> V_112 )
return;
F_159 ( V_29 -> V_194 ) ;
V_29 -> V_196 = V_29 -> V_112 + ( 2 * V_206 ) ;
V_29 -> V_194 = V_29 -> V_112 + ( 4 * V_206 ) ;
V_29 -> V_195 = V_29 -> V_112 + ( 6 * V_206 ) ;
V_29 -> V_117 = 0 ;
memset ( V_29 -> V_173 , 0 , sizeof( V_29 -> V_173 ) ) ;
}
if ( F_14 ( V_123 == ( - 1 & V_225 ) ) ) {
V_110 = 1 ;
} else {
V_110 = F_104 ( V_29 , V_123 ) ;
if ( ! V_110 && ! ( V_201 & V_226 ) )
F_151 ( V_29 , V_123 , V_201 , & V_110 ) ;
}
F_142 ( V_29 ) ;
if ( F_170 ( V_164 , V_29 -> V_163 ) )
F_133 ( V_29 ) ;
if ( V_218 )
V_29 -> V_227 += V_217 ;
V_29 -> V_194 [ F_92 ( V_216 , V_110 ) ] += V_217 ;
V_29 -> V_195 [ F_92 ( V_220 , V_110 ) ] += V_217 ;
V_29 -> V_173 [ ! ! ( V_201 & V_228 ) ] += V_217 ;
}
static void F_171 ( struct V_26 * V_29 )
{
F_117 ( V_29 -> V_96 -> V_189 ) ++ ;
V_29 -> V_96 -> V_229 = 0 ;
}
void F_172 ( struct V_230 * V_231 )
{
unsigned long V_232 , V_233 , V_81 = V_164 ;
struct V_26 * V_29 = V_125 ;
struct V_234 * V_96 = V_29 -> V_96 ;
struct V_235 * V_236 ;
unsigned long V_237 , V_238 ;
unsigned long V_239 = 0 ;
long V_217 ;
F_20 ( V_29 != F_22 ( V_231 , struct V_26 , V_240 ) ) ;
V_231 -> V_58 = V_231 ;
if ( V_29 -> V_201 & V_241 )
return;
if ( ! V_96 -> V_176 ) {
V_96 -> V_176 = V_81 +
F_139 ( V_242 ) ;
}
V_232 = V_96 -> V_176 ;
if ( F_173 ( V_81 , V_232 ) )
return;
if ( V_29 -> V_162 == 0 ) {
V_29 -> V_175 = F_87 ( V_29 ) ;
V_29 -> V_162 = F_85 ( V_29 ) ;
}
V_233 = V_81 + F_139 ( V_29 -> V_162 ) ;
if ( F_174 ( & V_96 -> V_176 , V_232 , V_233 ) != V_232 )
return;
V_29 -> V_243 += 2 * V_244 ;
V_237 = V_96 -> V_229 ;
V_217 = V_94 ;
V_217 <<= 20 - V_95 ;
if ( ! V_217 )
return;
F_175 ( & V_96 -> V_245 ) ;
V_236 = F_176 ( V_96 , V_237 ) ;
if ( ! V_236 ) {
F_171 ( V_29 ) ;
V_237 = 0 ;
V_236 = V_96 -> V_246 ;
}
for (; V_236 ; V_236 = V_236 -> V_247 ) {
if ( ! F_177 ( V_236 ) || ! F_178 ( V_29 , V_236 ) )
continue;
if ( ! V_236 -> V_248 ||
( V_236 -> V_249 && ( V_236 -> V_250 & ( V_251 | V_252 ) ) == ( V_251 ) ) )
continue;
if ( ! ( V_236 -> V_250 & ( V_251 | V_253 | V_252 ) ) )
continue;
do {
V_237 = F_68 ( V_237 , V_236 -> V_254 ) ;
V_238 = F_179 ( V_237 + ( V_217 << V_95 ) , V_255 ) ;
V_238 = F_138 ( V_238 , V_236 -> V_256 ) ;
V_239 += F_180 ( V_236 , V_237 , V_238 ) ;
if ( V_239 )
V_217 -= ( V_238 - V_237 ) >> V_95 ;
V_237 = V_238 ;
if ( V_217 <= 0 )
goto V_257;
F_181 () ;
} while ( V_238 != V_236 -> V_256 );
}
V_257:
if ( V_236 )
V_96 -> V_229 = V_237 ;
else
F_171 ( V_29 ) ;
F_182 ( & V_96 -> V_245 ) ;
}
void F_183 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_230 * V_231 = & V_45 -> V_240 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_201 & V_241 ) || V_231 -> V_58 != V_231 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_162 * V_258 ;
if ( V_81 - V_45 -> V_243 > V_73 ) {
if ( ! V_45 -> V_243 )
V_45 -> V_162 = F_85 ( V_45 ) ;
V_45 -> V_243 += V_73 ;
if ( ! F_173 ( V_164 , V_45 -> V_96 -> V_176 ) ) {
F_184 ( V_231 , F_172 ) ;
F_185 ( V_45 , V_231 , true ) ;
}
}
}
static void F_183 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_88 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_90 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_186 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_187
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_88 ( V_24 , F_18 ( V_28 ) ) ;
F_157 ( & V_28 -> V_259 , & V_24 -> V_260 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_188 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_90 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_189 ( & V_28 -> V_259 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_190 ( struct V_261 * V_33 , struct V_25 * V_25 )
{
long V_262 ;
V_262 = F_191 ( & V_33 -> V_263 ) ;
V_262 -= V_25 -> V_264 ;
V_262 += V_25 -> V_70 . V_4 ;
return V_262 ;
}
static long F_192 ( struct V_25 * V_25 , struct V_261 * V_33 )
{
long V_262 , V_70 , V_265 ;
V_262 = F_190 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_265 = ( V_33 -> V_265 * V_70 ) ;
if ( V_262 )
V_265 /= V_262 ;
if ( V_265 < V_266 )
V_265 = V_266 ;
if ( V_265 > V_33 -> V_265 )
V_265 = V_33 -> V_265 ;
return V_265 ;
}
static inline long F_192 ( struct V_25 * V_25 , struct V_261 * V_33 )
{
return V_33 -> V_265 ;
}
static void F_193 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_65 ( V_25 ) ;
F_188 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_186 ( V_25 , V_28 ) ;
}
static void F_194 ( struct V_25 * V_25 )
{
struct V_261 * V_33 ;
struct V_27 * V_28 ;
long V_265 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_195 ( V_25 ) )
return;
#ifndef F_187
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_265 ) )
return;
#endif
V_265 = F_192 ( V_25 , V_33 ) ;
F_193 ( F_24 ( V_28 ) , V_28 , V_265 ) ;
}
static inline void F_194 ( struct V_25 * V_25 )
{
}
static T_9 T_2 F_196 ( T_2 V_267 , T_2 V_268 )
{
unsigned int V_269 ;
if ( ! V_268 )
return V_267 ;
else if ( F_14 ( V_268 > V_270 * 63 ) )
return 0 ;
V_269 = V_268 ;
if ( F_14 ( V_269 >= V_270 ) ) {
V_267 >>= V_269 / V_270 ;
V_269 %= V_270 ;
}
V_267 *= V_271 [ V_269 ] ;
return V_267 >> 32 ;
}
static V_23 F_197 ( T_2 V_268 )
{
V_23 V_272 = 0 ;
if ( F_12 ( V_268 <= V_270 ) )
return V_273 [ V_268 ] ;
else if ( F_14 ( V_268 >= V_274 ) )
return V_275 ;
do {
V_272 /= 2 ;
V_272 += V_273 [ V_270 ] ;
V_268 -= V_270 ;
} while ( V_268 > V_270 );
V_272 = F_196 ( V_272 , V_268 ) ;
return V_272 + V_273 [ V_268 ] ;
}
static T_9 int F_198 ( T_2 V_81 ,
struct V_276 * V_277 ,
int V_278 )
{
T_2 V_42 , V_279 ;
V_23 V_280 ;
int V_281 , V_282 = 0 ;
V_42 = V_81 - V_277 -> V_283 ;
if ( ( T_3 ) V_42 < 0 ) {
V_277 -> V_283 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_277 -> V_283 = V_81 ;
V_281 = V_277 -> V_80 % 1024 ;
if ( V_42 + V_281 >= 1024 ) {
V_282 = 1 ;
V_281 = 1024 - V_281 ;
if ( V_278 )
V_277 -> V_79 += V_281 ;
V_277 -> V_80 += V_281 ;
V_42 -= V_281 ;
V_279 = V_42 / 1024 ;
V_42 %= 1024 ;
V_277 -> V_79 = F_196 ( V_277 -> V_79 ,
V_279 + 1 ) ;
V_277 -> V_80 = F_196 ( V_277 -> V_80 ,
V_279 + 1 ) ;
V_280 = F_197 ( V_279 ) ;
if ( V_278 )
V_277 -> V_79 += V_280 ;
V_277 -> V_80 += V_280 ;
}
if ( V_278 )
V_277 -> V_79 += V_42 ;
V_277 -> V_80 += V_42 ;
return V_282 ;
}
static inline T_2 F_199 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_284 = F_200 ( & V_25 -> V_285 ) ;
V_284 -= V_28 -> V_77 . V_78 ;
if ( ! V_284 )
return 0 ;
V_28 -> V_77 . V_286 = F_196 ( V_28 -> V_77 . V_286 , V_284 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_284 ;
}
static inline void F_201 ( struct V_25 * V_25 ,
int V_287 )
{
struct V_261 * V_33 = V_25 -> V_33 ;
long V_288 ;
V_288 = V_25 -> V_289 + V_25 -> V_290 ;
V_288 -= V_25 -> V_264 ;
if ( V_287 || abs ( V_288 ) > V_25 -> V_264 / 8 ) {
F_202 ( V_288 , & V_33 -> V_263 ) ;
V_25 -> V_264 += V_288 ;
}
}
static inline void F_203 ( struct V_276 * V_277 ,
struct V_25 * V_25 )
{
struct V_261 * V_33 = V_25 -> V_33 ;
long V_272 ;
V_272 = F_204 ( ( T_2 ) V_277 -> V_79 << V_291 ,
V_277 -> V_80 + 1 ) ;
V_272 -= V_25 -> V_292 ;
if ( abs ( V_272 ) > V_25 -> V_292 / 64 ) {
F_205 ( V_272 , & V_33 -> V_293 ) ;
V_25 -> V_292 += V_272 ;
}
}
static inline void F_206 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_261 * V_33 = V_25 -> V_33 ;
int V_293 ;
T_2 V_272 ;
V_272 = V_25 -> V_264 * V_33 -> V_265 ;
V_28 -> V_77 . V_286 = F_204 ( V_272 ,
F_191 ( & V_33 -> V_263 ) + 1 ) ;
V_293 = F_207 ( & V_33 -> V_293 ) ;
if ( V_293 < V_71 ) {
V_28 -> V_77 . V_286 *= V_293 ;
V_28 -> V_77 . V_286 >>= V_291 ;
}
}
static inline void F_208 ( struct V_24 * V_24 , int V_278 )
{
F_198 ( F_66 ( V_24 ) , & V_24 -> V_77 , V_278 ) ;
F_203 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_201 ( struct V_25 * V_25 ,
int V_287 ) {}
static inline void F_203 ( struct V_276 * V_277 ,
struct V_25 * V_25 ) {}
static inline void F_206 ( struct V_27 * V_28 ) {}
static inline void F_208 ( struct V_24 * V_24 , int V_278 ) {}
static inline void F_64 ( struct V_27 * V_28 )
{
V_23 V_272 ;
V_272 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_272 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_286 = F_209 ( V_272 ) ;
}
static long F_210 ( struct V_27 * V_28 )
{
long V_294 = V_28 -> V_77 . V_286 ;
if ( F_21 ( V_28 ) ) {
F_64 ( V_28 ) ;
} else {
F_203 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_206 ( V_28 ) ;
}
return V_28 -> V_77 . V_286 - V_294 ;
}
static inline void F_211 ( struct V_25 * V_25 ,
long V_295 )
{
if ( F_12 ( V_295 < V_25 -> V_290 ) )
V_25 -> V_290 -= V_295 ;
else
V_25 -> V_290 = 0 ;
}
static inline void F_212 ( struct V_27 * V_28 ,
int V_296 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_297 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_213 ( V_25 ) ;
else
V_81 = F_213 ( F_25 ( V_28 ) ) ;
if ( ! F_198 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_297 = F_210 ( V_28 ) ;
if ( ! V_296 )
return;
if ( V_28 -> V_76 )
V_25 -> V_289 += V_297 ;
else
F_211 ( V_25 , - V_297 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_287 )
{
T_2 V_81 = F_213 ( V_25 ) >> 20 ;
T_2 V_284 ;
V_284 = V_81 - V_25 -> V_298 ;
if ( ! V_284 && ! V_287 )
return;
if ( F_191 ( & V_25 -> V_299 ) ) {
unsigned long V_299 ;
V_299 = F_214 ( & V_25 -> V_299 , 0 ) ;
F_211 ( V_25 , V_299 ) ;
}
if ( V_284 ) {
V_25 -> V_290 = F_196 ( V_25 -> V_290 ,
V_284 ) ;
F_215 ( V_284 , & V_25 -> V_285 ) ;
V_25 -> V_298 = V_81 ;
}
F_201 ( V_25 , V_287 ) ;
}
static inline void F_216 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_300 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_283 = F_66 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_283 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_212 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_300 = 0 ;
} else {
F_199 ( V_28 ) ;
}
if ( V_300 ) {
F_211 ( V_25 , V_28 -> V_77 . V_286 ) ;
F_212 ( V_28 , 0 ) ;
}
V_25 -> V_289 += V_28 -> V_77 . V_286 ;
F_30 ( V_25 , ! V_300 ) ;
}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_301 )
{
F_212 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_301 ) ;
V_25 -> V_289 -= V_28 -> V_77 . V_286 ;
if ( V_301 ) {
V_25 -> V_290 += V_28 -> V_77 . V_286 ;
V_28 -> V_77 . V_78 = F_200 ( & V_25 -> V_285 ) ;
}
}
void F_218 ( struct V_24 * V_302 )
{
F_208 ( V_302 , 1 ) ;
}
void F_219 ( struct V_24 * V_302 )
{
F_208 ( V_302 , 0 ) ;
}
static inline void F_212 ( struct V_27 * V_28 ,
int V_296 ) {}
static inline void F_208 ( struct V_24 * V_24 , int V_278 ) {}
static inline void F_216 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_300 ) {}
static inline void F_217 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_301 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_287 ) {}
static inline int F_220 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_221 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_78
struct V_26 * V_203 = NULL ;
if ( F_21 ( V_28 ) )
V_203 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_303 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_303 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_304 ) )
V_28 -> V_83 . V_304 = V_42 ;
V_28 -> V_83 . V_303 = 0 ;
V_28 -> V_83 . V_305 += V_42 ;
if ( V_203 ) {
F_222 ( V_203 , V_42 >> 10 , 1 ) ;
F_223 ( V_203 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_306 ) {
T_2 V_42 = F_75 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_306 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_307 ) )
V_28 -> V_83 . V_307 = V_42 ;
V_28 -> V_83 . V_306 = 0 ;
V_28 -> V_83 . V_305 += V_42 ;
if ( V_203 ) {
if ( V_203 -> V_308 ) {
V_28 -> V_83 . V_309 += V_42 ;
V_28 -> V_83 . V_310 ++ ;
F_224 ( V_203 , V_42 ) ;
}
F_225 ( V_203 , V_42 ) ;
if ( F_14 ( V_311 == V_312 ) ) {
F_226 ( V_312 ,
( void * ) F_227 ( V_203 ) ,
V_42 >> 20 ) ;
}
F_222 ( V_203 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_228 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_313 = V_28 -> V_41 - V_25 -> F_38 ;
if ( V_313 < 0 )
V_313 = - V_313 ;
if ( V_313 > 3 * V_68 )
F_229 ( V_25 , V_314 ) ;
#endif
}
static void
F_230 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_315 )
{
T_2 V_41 = V_25 -> F_38 ;
if ( V_315 && F_231 ( V_316 ) )
V_41 += F_62 ( V_25 , V_28 ) ;
if ( ! V_315 ) {
unsigned long V_317 = V_68 ;
if ( F_231 ( V_318 ) )
V_317 >>= 1 ;
V_41 -= V_317 ;
}
V_28 -> V_41 = F_37 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_232 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_201 )
{
if ( ! ( V_201 & V_319 ) || ( V_201 & V_320 ) )
V_28 -> V_41 += V_25 -> F_38 ;
F_65 ( V_25 ) ;
F_216 ( V_25 , V_28 , V_201 & V_319 ) ;
F_186 ( V_25 , V_28 ) ;
F_194 ( V_25 ) ;
if ( V_201 & V_319 ) {
F_230 ( V_25 , V_28 , 0 ) ;
F_221 ( V_25 , V_28 ) ;
}
F_76 ( V_25 , V_28 ) ;
F_228 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_233 ( V_25 ) ;
}
}
static void F_234 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_235 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 != V_28 )
break;
V_25 -> V_58 = NULL ;
}
}
static void F_236 ( struct V_27 * V_28 )
{
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_321 != V_28 )
break;
V_25 -> V_321 = NULL ;
}
}
static void F_237 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_234 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_235 ( V_28 ) ;
if ( V_25 -> V_321 == V_28 )
F_236 ( V_28 ) ;
}
static void
F_238 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_201 )
{
F_65 ( V_25 ) ;
F_217 ( V_25 , V_28 , V_201 & V_322 ) ;
F_80 ( V_25 , V_28 ) ;
if ( V_201 & V_322 ) {
#ifdef F_78
if ( F_21 ( V_28 ) ) {
struct V_26 * V_203 = F_18 ( V_28 ) ;
if ( V_203 -> V_222 & V_323 )
V_28 -> V_83 . V_303 = F_75 ( F_17 ( V_25 ) ) ;
if ( V_203 -> V_222 & V_324 )
V_28 -> V_83 . V_306 = F_75 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_237 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_47 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_188 ( V_25 , V_28 ) ;
if ( ! ( V_201 & V_322 ) )
V_28 -> V_41 -= V_25 -> F_38 ;
F_239 ( V_25 ) ;
F_40 ( V_25 ) ;
F_194 ( V_25 ) ;
}
static void
F_240 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_325 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_325 = F_60 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_326 ;
if ( V_19 > V_325 ) {
F_241 ( F_17 ( V_25 ) -> V_45 ) ;
F_237 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_50 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_325 )
F_241 ( F_17 ( V_25 ) -> V_45 ) ;
}
static void
F_242 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_77 ( V_25 , V_28 ) ;
F_47 ( V_25 , V_28 ) ;
}
F_81 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_78
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_327 = F_68 ( V_28 -> V_83 . V_327 ,
V_28 -> V_85 - V_28 -> V_326 ) ;
}
#endif
V_28 -> V_326 = V_28 -> V_85 ;
}
static struct V_27 *
F_243 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_57 = F_50 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_57 || ( V_45 && F_39 ( V_45 , V_57 ) ) )
V_57 = V_45 ;
V_28 = V_57 ;
if ( V_25 -> V_321 == V_28 ) {
struct V_27 * V_328 ;
if ( V_28 == V_45 ) {
V_328 = F_50 ( V_25 ) ;
} else {
V_328 = F_51 ( V_28 ) ;
if ( ! V_328 || ( V_45 && F_39 ( V_45 , V_328 ) ) )
V_328 = V_45 ;
}
if ( V_328 && F_244 ( V_328 , V_57 ) < 1 )
V_28 = V_328 ;
}
if ( V_25 -> V_59 && F_244 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_244 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_237 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_245 ( struct V_25 * V_25 , struct V_27 * V_329 )
{
if ( V_329 -> V_76 )
F_65 ( V_25 ) ;
F_246 ( V_25 ) ;
F_228 ( V_25 , V_329 ) ;
if ( V_329 -> V_76 ) {
F_74 ( V_25 , V_329 ) ;
F_44 ( V_25 , V_329 ) ;
F_212 ( V_329 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_247 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_330 )
{
F_65 ( V_25 ) ;
F_212 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_194 ( V_25 ) ;
#ifdef F_248
if ( V_330 ) {
F_241 ( F_17 ( V_25 ) -> V_45 ) ;
return;
}
if ( ! F_231 ( V_331 ) &&
F_249 ( & F_17 ( V_25 ) -> V_332 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_240 ( V_25 , V_45 ) ;
}
static inline bool F_250 ( void )
{
return F_251 ( & V_333 ) ;
}
void F_252 ( void )
{
F_253 ( & V_333 ) ;
}
void F_254 ( void )
{
F_255 ( & V_333 ) ;
}
static bool F_250 ( void )
{
return true ;
}
void F_252 ( void ) {}
void F_254 ( void ) {}
static inline T_2 F_256 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_257 ( void )
{
return ( T_2 ) V_334 * V_335 ;
}
void F_258 ( struct V_336 * V_337 )
{
T_2 V_81 ;
if ( V_337 -> V_338 == V_339 )
return;
V_81 = F_259 ( F_260 () ) ;
V_337 -> V_180 = V_337 -> V_338 ;
V_337 -> V_340 = V_81 + F_261 ( V_337 -> V_73 ) ;
}
static inline struct V_336 * F_262 ( struct V_261 * V_33 )
{
return & V_33 -> V_336 ;
}
static inline T_2 F_213 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_341 ) )
return V_25 -> V_342 ;
return F_66 ( F_17 ( V_25 ) ) - V_25 -> V_343 ;
}
static int F_263 ( struct V_25 * V_25 )
{
struct V_261 * V_33 = V_25 -> V_33 ;
struct V_336 * V_337 = F_262 ( V_33 ) ;
T_2 V_344 = 0 , V_345 , V_346 ;
V_345 = F_257 () - V_25 -> V_347 ;
F_264 ( & V_337 -> V_190 ) ;
if ( V_337 -> V_338 == V_339 )
V_344 = V_345 ;
else {
if ( ! V_337 -> V_348 ) {
F_258 ( V_337 ) ;
F_265 ( V_337 , false ) ;
}
if ( V_337 -> V_180 > 0 ) {
V_344 = F_138 ( V_337 -> V_180 , V_345 ) ;
V_337 -> V_180 -= V_344 ;
V_337 -> V_349 = 0 ;
}
}
V_346 = V_337 -> V_340 ;
F_266 ( & V_337 -> V_190 ) ;
V_25 -> V_347 += V_344 ;
if ( ( T_3 ) ( V_346 - V_25 -> V_340 ) > 0 )
V_25 -> V_340 = V_346 ;
return V_25 -> V_347 > 0 ;
}
static void F_267 ( struct V_25 * V_25 )
{
struct V_336 * V_337 = F_262 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_75 ( F_17 ( V_25 ) ) - V_25 -> V_340 ) < 0 ) )
return;
if ( V_25 -> V_347 < 0 )
return;
if ( ( T_3 ) ( V_25 -> V_340 - V_337 -> V_340 ) >= 0 ) {
V_25 -> V_340 += V_244 ;
} else {
V_25 -> V_347 = 0 ;
}
}
static void F_268 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_347 -= V_19 ;
F_267 ( V_25 ) ;
if ( F_12 ( V_25 -> V_347 > 0 ) )
return;
if ( ! F_263 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_241 ( F_17 ( V_25 ) -> V_45 ) ;
}
static T_9
void F_73 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_250 () || ! V_25 -> V_350 )
return;
F_268 ( V_25 , V_19 ) ;
}
static inline int F_269 ( struct V_25 * V_25 )
{
return F_250 () && V_25 -> V_351 ;
}
static inline int F_195 ( struct V_25 * V_25 )
{
return F_250 () && V_25 -> V_341 ;
}
static inline int F_270 ( struct V_261 * V_33 ,
int V_144 , int V_352 )
{
struct V_25 * V_353 , * V_354 ;
V_353 = V_33 -> V_25 [ V_144 ] ;
V_354 = V_33 -> V_25 [ V_352 ] ;
return F_195 ( V_353 ) ||
F_195 ( V_354 ) ;
}
static int F_271 ( struct V_261 * V_33 , void * V_355 )
{
struct V_24 * V_24 = V_355 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_341 -- ;
#ifdef F_187
if ( ! V_25 -> V_341 ) {
V_25 -> V_343 += F_66 ( V_24 ) -
V_25 -> V_342 ;
}
#endif
return 0 ;
}
static int F_272 ( struct V_261 * V_33 , void * V_355 )
{
struct V_24 * V_24 = V_355 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_341 )
V_25 -> V_342 = F_66 ( V_24 ) ;
V_25 -> V_341 ++ ;
return 0 ;
}
static void F_273 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_336 * V_337 = F_262 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_356 , V_357 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_116 () ;
F_274 ( V_25 -> V_33 , F_272 , V_358 , ( void * ) V_24 ) ;
F_122 () ;
V_356 = V_25 -> V_359 ;
F_61 (se) {
struct V_25 * V_360 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_357 )
F_238 ( V_360 , V_28 , V_322 ) ;
V_360 -> V_359 -= V_356 ;
if ( V_360 -> V_70 . V_4 )
V_357 = 0 ;
}
if ( ! V_28 )
V_24 -> V_72 -= V_356 ;
V_25 -> V_351 = 1 ;
V_25 -> V_361 = F_75 ( V_24 ) ;
F_264 ( & V_337 -> V_190 ) ;
F_29 ( & V_25 -> V_362 , & V_337 -> V_363 ) ;
if ( ! V_337 -> V_348 )
F_265 ( V_337 , false ) ;
F_266 ( & V_337 -> V_190 ) ;
}
void F_275 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_336 * V_337 = F_262 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_364 = 1 ;
long V_356 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_351 = 0 ;
F_276 ( V_24 ) ;
F_264 ( & V_337 -> V_190 ) ;
V_337 -> V_365 += F_75 ( V_24 ) - V_25 -> V_361 ;
F_32 ( & V_25 -> V_362 ) ;
F_266 ( & V_337 -> V_190 ) ;
F_274 ( V_25 -> V_33 , V_358 , F_271 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_356 = V_25 -> V_359 ;
F_61 (se) {
if ( V_28 -> V_76 )
V_364 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_364 )
F_232 ( V_25 , V_28 , V_319 ) ;
V_25 -> V_359 += V_356 ;
if ( F_269 ( V_25 ) )
break;
}
if ( ! V_28 )
V_24 -> V_72 += V_356 ;
if ( V_24 -> V_45 == V_24 -> V_349 && V_24 -> V_40 . V_72 )
F_241 ( V_24 -> V_45 ) ;
}
static T_2 F_277 ( struct V_336 * V_337 ,
T_2 V_366 , T_2 V_346 )
{
struct V_25 * V_25 ;
T_2 V_180 = V_366 ;
F_116 () ;
F_278 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_264 ( & V_24 -> V_190 ) ;
if ( ! F_269 ( V_25 ) )
goto V_58;
V_180 = - V_25 -> V_347 + 1 ;
if ( V_180 > V_366 )
V_180 = V_366 ;
V_366 -= V_180 ;
V_25 -> V_347 += V_180 ;
V_25 -> V_340 = V_346 ;
if ( V_25 -> V_347 > 0 )
F_275 ( V_25 ) ;
V_58:
F_266 ( & V_24 -> V_190 ) ;
if ( ! V_366 )
break;
}
F_122 () ;
return V_366 ;
}
static int F_279 ( struct V_336 * V_337 , int V_367 )
{
T_2 V_180 , V_340 ;
int V_349 = 1 , V_351 ;
F_264 ( & V_337 -> V_190 ) ;
if ( V_337 -> V_338 == V_339 )
goto V_368;
V_351 = ! F_280 ( & V_337 -> V_363 ) ;
V_349 = V_337 -> V_349 && ! V_351 ;
V_337 -> V_369 += V_367 ;
if ( V_349 )
goto V_368;
V_337 -> V_348 = 1 ;
F_258 ( V_337 ) ;
if ( ! V_351 ) {
V_337 -> V_349 = 1 ;
goto V_368;
}
V_337 -> V_370 += V_367 ;
V_180 = V_337 -> V_180 ;
V_340 = V_337 -> V_340 ;
V_337 -> V_180 = 0 ;
while ( V_351 && V_180 > 0 ) {
F_266 ( & V_337 -> V_190 ) ;
V_180 = F_277 ( V_337 , V_180 ,
V_340 ) ;
F_264 ( & V_337 -> V_190 ) ;
V_351 = ! F_280 ( & V_337 -> V_363 ) ;
}
V_337 -> V_180 = V_180 ;
V_337 -> V_349 = 0 ;
V_368:
if ( V_349 )
V_337 -> V_348 = 0 ;
F_266 ( & V_337 -> V_190 ) ;
return V_349 ;
}
static int F_281 ( struct V_336 * V_337 , T_2 V_371 )
{
struct V_372 * V_373 = & V_337 -> V_374 ;
T_2 V_366 ;
if ( F_282 ( V_373 ) )
return 1 ;
V_366 = F_261 ( F_283 ( V_373 ) ) ;
if ( V_366 < V_371 )
return 1 ;
return 0 ;
}
static void F_284 ( struct V_336 * V_337 )
{
T_2 V_375 = V_376 + V_377 ;
if ( F_281 ( V_337 , V_375 ) )
return;
F_285 ( & V_337 -> V_378 ,
F_286 ( V_376 ) ) ;
}
static void F_287 ( struct V_25 * V_25 )
{
struct V_336 * V_337 = F_262 ( V_25 -> V_33 ) ;
T_3 V_379 = V_25 -> V_347 - V_380 ;
if ( V_379 <= 0 )
return;
F_264 ( & V_337 -> V_190 ) ;
if ( V_337 -> V_338 != V_339 &&
V_25 -> V_340 == V_337 -> V_340 ) {
V_337 -> V_180 += V_379 ;
if ( V_337 -> V_180 > F_257 () &&
! F_280 ( & V_337 -> V_363 ) )
F_284 ( V_337 ) ;
}
F_266 ( & V_337 -> V_190 ) ;
V_25 -> V_347 -= V_379 ;
}
static T_9 void F_239 ( struct V_25 * V_25 )
{
if ( ! F_250 () )
return;
if ( ! V_25 -> V_350 || V_25 -> V_72 )
return;
F_287 ( V_25 ) ;
}
static void F_288 ( struct V_336 * V_337 )
{
T_2 V_180 = 0 , V_75 = F_257 () ;
T_2 V_346 ;
F_264 ( & V_337 -> V_190 ) ;
if ( F_281 ( V_337 , V_377 ) ) {
F_266 ( & V_337 -> V_190 ) ;
return;
}
if ( V_337 -> V_338 != V_339 && V_337 -> V_180 > V_75 ) {
V_180 = V_337 -> V_180 ;
V_337 -> V_180 = 0 ;
}
V_346 = V_337 -> V_340 ;
F_266 ( & V_337 -> V_190 ) ;
if ( ! V_180 )
return;
V_180 = F_277 ( V_337 , V_180 , V_346 ) ;
F_264 ( & V_337 -> V_190 ) ;
if ( V_346 == V_337 -> V_340 )
V_337 -> V_180 = V_180 ;
F_266 ( & V_337 -> V_190 ) ;
}
static void F_233 ( struct V_25 * V_25 )
{
if ( ! F_250 () )
return;
if ( ! V_25 -> V_350 || V_25 -> V_45 )
return;
if ( F_269 ( V_25 ) )
return;
F_73 ( V_25 , 0 ) ;
if ( V_25 -> V_347 <= 0 )
F_273 ( V_25 ) ;
}
static bool F_246 ( struct V_25 * V_25 )
{
if ( ! F_250 () )
return false ;
if ( F_12 ( ! V_25 -> V_350 || V_25 -> V_347 > 0 ) )
return false ;
if ( F_269 ( V_25 ) )
return true ;
F_273 ( V_25 ) ;
return true ;
}
static enum V_381 F_289 ( struct V_372 * V_382 )
{
struct V_336 * V_337 =
F_22 ( V_382 , struct V_336 , V_378 ) ;
F_288 ( V_337 ) ;
return V_383 ;
}
static enum V_381 F_290 ( struct V_372 * V_382 )
{
struct V_336 * V_337 =
F_22 ( V_382 , struct V_336 , V_374 ) ;
T_10 V_81 ;
int V_367 ;
int V_349 = 0 ;
for (; ; ) {
V_81 = F_291 ( V_382 ) ;
V_367 = F_292 ( V_382 , V_81 , V_337 -> V_73 ) ;
if ( ! V_367 )
break;
V_349 = F_279 ( V_337 , V_367 ) ;
}
return V_349 ? V_383 : V_384 ;
}
void F_293 ( struct V_336 * V_337 )
{
F_294 ( & V_337 -> V_190 ) ;
V_337 -> V_180 = 0 ;
V_337 -> V_338 = V_339 ;
V_337 -> V_73 = F_286 ( F_256 () ) ;
F_156 ( & V_337 -> V_363 ) ;
F_295 ( & V_337 -> V_374 , V_385 , V_386 ) ;
V_337 -> V_374 . V_387 = F_290 ;
F_295 ( & V_337 -> V_378 , V_385 , V_386 ) ;
V_337 -> V_378 . V_387 = F_289 ;
}
static void F_296 ( struct V_25 * V_25 )
{
V_25 -> V_350 = 0 ;
F_156 ( & V_25 -> V_362 ) ;
}
void F_265 ( struct V_336 * V_337 , bool V_388 )
{
while ( F_14 ( F_249 ( & V_337 -> V_374 ) ) &&
F_297 ( & V_337 -> V_374 ) < 0 ) {
F_266 ( & V_337 -> V_190 ) ;
F_298 () ;
F_264 ( & V_337 -> V_190 ) ;
if ( ! V_388 && V_337 -> V_348 )
return;
}
V_337 -> V_348 = 1 ;
F_285 ( & V_337 -> V_374 , V_337 -> V_73 ) ;
}
static void F_299 ( struct V_336 * V_337 )
{
F_300 ( & V_337 -> V_374 ) ;
F_300 ( & V_337 -> V_378 ) ;
}
static void T_11 F_301 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_302 (rq, cfs_rq) {
struct V_336 * V_337 = F_262 ( V_25 -> V_33 ) ;
if ( ! V_25 -> V_350 )
continue;
V_25 -> V_347 = V_337 -> V_338 ;
if ( F_269 ( V_25 ) )
F_275 ( V_25 ) ;
}
}
static inline T_2 F_213 ( struct V_25 * V_25 )
{
return F_66 ( F_17 ( V_25 ) ) ;
}
static void F_73 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_246 ( struct V_25 * V_25 ) { return false ; }
static void F_233 ( struct V_25 * V_25 ) {}
static T_9 void F_239 ( struct V_25 * V_25 ) {}
static inline int F_269 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_195 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_270 ( struct V_261 * V_33 ,
int V_144 , int V_352 )
{
return 0 ;
}
void F_293 ( struct V_336 * V_337 ) {}
static void F_296 ( struct V_25 * V_25 ) {}
static inline struct V_336 * F_262 ( struct V_261 * V_33 )
{
return NULL ;
}
static inline void F_299 ( struct V_336 * V_337 ) {}
static inline void F_301 ( struct V_24 * V_24 ) {}
static void F_303 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_304 ( F_36 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_60 ( V_25 , V_28 ) ;
T_2 V_389 = V_28 -> V_85 - V_28 -> V_326 ;
T_3 V_42 = V_75 - V_389 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_241 ( V_29 ) ;
return;
}
if ( V_24 -> V_45 != V_29 )
V_42 = F_86 ( T_3 , 10000LL , V_42 ) ;
F_305 ( V_24 , V_42 ) ;
}
}
static void F_306 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_307 ( V_24 ) || V_45 -> V_390 != & V_391 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_303 ( V_24 , V_45 ) ;
}
static inline void
F_303 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_306 ( struct V_24 * V_24 )
{
}
static void
F_308 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_201 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_61 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_232 ( V_25 , V_28 , V_201 ) ;
if ( F_269 ( V_25 ) )
break;
V_25 -> V_359 ++ ;
V_201 = V_319 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_359 ++ ;
if ( F_269 ( V_25 ) )
break;
F_194 ( V_25 ) ;
F_212 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_208 ( V_24 , V_24 -> V_72 ) ;
F_309 ( V_24 ) ;
}
F_306 ( V_24 ) ;
}
static void F_310 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_201 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_392 = V_201 & V_322 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_238 ( V_25 , V_28 , V_201 ) ;
if ( F_269 ( V_25 ) )
break;
V_25 -> V_359 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_392 && F_34 ( V_28 ) )
F_311 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_201 |= V_322 ;
}
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_359 -- ;
if ( F_269 ( V_25 ) )
break;
F_194 ( V_25 ) ;
F_212 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_312 ( V_24 ) ;
F_208 ( V_24 , 1 ) ;
}
F_306 ( V_24 ) ;
}
static unsigned long F_109 ( const int V_130 )
{
return F_108 ( V_130 ) -> V_40 . V_289 ;
}
static unsigned long F_313 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_393 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_231 ( V_394 ) )
return V_393 ;
return F_138 ( V_24 -> V_395 [ type - 1 ] , V_393 ) ;
}
static unsigned long F_314 ( int V_130 , int type )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_393 = F_109 ( V_130 ) ;
if ( type == 0 || ! F_231 ( V_394 ) )
return V_393 ;
return F_68 ( V_24 -> V_395 [ type - 1 ] , V_393 ) ;
}
static unsigned long F_110 ( int V_130 )
{
return F_108 ( V_130 ) -> V_396 ;
}
static unsigned long F_315 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_72 = F_117 ( V_24 -> V_72 ) ;
unsigned long V_263 = V_24 -> V_40 . V_289 ;
if ( V_72 )
return V_263 / V_72 ;
return 0 ;
}
static void F_316 ( struct V_26 * V_29 )
{
if ( V_164 > V_125 -> V_397 + V_165 ) {
V_125 -> V_398 = 0 ;
V_125 -> V_397 = V_164 ;
}
if ( V_125 -> V_399 != V_29 ) {
V_125 -> V_399 = V_29 ;
V_125 -> V_398 ++ ;
}
}
static void F_317 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_38 ;
#ifndef F_42
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_318 () ;
F_38 = V_25 -> F_38 ;
} while ( F_38 != V_48 );
#else
F_38 = V_25 -> F_38 ;
#endif
V_28 -> V_41 -= F_38 ;
F_316 ( V_29 ) ;
}
static long F_319 ( struct V_261 * V_33 , int V_130 , long V_400 , long V_401 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_130 ] ;
if ( ! V_33 -> V_34 )
return V_400 ;
F_61 (se) {
long V_7 , V_402 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_402 = V_401 + F_190 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_400 ;
if ( V_402 > 0 && V_7 < V_402 )
V_400 = ( V_7 * V_33 -> V_265 ) / V_402 ;
else
V_400 = V_33 -> V_265 ;
if ( V_400 < V_266 )
V_400 = V_266 ;
V_400 -= V_28 -> V_70 . V_4 ;
V_401 = 0 ;
}
return V_400 ;
}
static long F_319 ( struct V_261 * V_33 , int V_130 , long V_400 , long V_401 )
{
return V_400 ;
}
static int F_320 ( struct V_26 * V_29 )
{
int V_9 = F_321 ( V_403 ) ;
if ( V_29 -> V_398 > V_9 ) {
if ( V_125 -> V_398 > ( V_9 * V_29 -> V_398 ) )
return 1 ;
}
return 0 ;
}
static int F_322 ( struct V_155 * V_156 , struct V_26 * V_29 , int V_404 )
{
T_3 V_405 , V_70 ;
int V_406 , V_407 , V_408 ;
unsigned long V_409 ;
struct V_261 * V_33 ;
unsigned long V_4 ;
int V_410 ;
if ( F_320 ( V_29 ) )
return 0 ;
V_406 = V_156 -> V_411 ;
V_407 = F_260 () ;
V_408 = F_125 ( V_29 ) ;
V_70 = F_313 ( V_408 , V_406 ) ;
V_405 = F_314 ( V_407 , V_406 ) ;
if ( V_404 ) {
V_33 = V_261 ( V_125 ) ;
V_4 = V_125 -> V_28 . V_70 . V_4 ;
V_405 += F_319 ( V_33 , V_407 , - V_4 , - V_4 ) ;
V_70 += F_319 ( V_33 , V_408 , 0 , - V_4 ) ;
}
V_33 = V_261 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_405 > 0 ) {
T_3 V_412 , V_413 ;
V_412 = 100 ;
V_412 *= F_110 ( V_408 ) ;
V_412 *= V_405 +
F_319 ( V_33 , V_407 , V_4 , V_4 ) ;
V_413 = 100 + ( V_156 -> V_154 - 100 ) / 2 ;
V_413 *= F_110 ( V_407 ) ;
V_413 *= V_70 + F_319 ( V_33 , V_408 , 0 , V_4 ) ;
V_410 = V_412 <= V_413 ;
} else
V_410 = true ;
if ( V_404 && V_410 )
return 1 ;
F_229 ( V_29 , V_28 . V_83 . V_414 ) ;
V_409 = F_315 ( V_407 ) ;
if ( V_410 ||
( V_405 <= V_70 &&
V_405 + F_314 ( V_408 , V_406 ) <= V_409 ) ) {
F_229 ( V_156 , V_415 ) ;
F_229 ( V_29 , V_28 . V_83 . V_416 ) ;
return 1 ;
}
return 0 ;
}
static struct V_417 *
F_323 ( struct V_155 * V_156 , struct V_26 * V_29 ,
int V_407 , int V_418 )
{
struct V_417 * V_419 = NULL , * V_114 = V_156 -> V_420 ;
unsigned long V_421 = V_422 , V_405 = 0 ;
int V_423 = V_156 -> V_424 ;
int V_425 = 100 + ( V_156 -> V_154 - 100 ) / 2 ;
if ( V_418 & V_426 )
V_423 = V_156 -> V_411 ;
do {
unsigned long V_70 , V_427 ;
int V_428 ;
int V_191 ;
if ( ! F_324 ( F_325 ( V_114 ) ,
F_119 ( V_29 ) ) )
continue;
V_428 = F_118 ( V_407 ,
F_325 ( V_114 ) ) ;
V_427 = 0 ;
F_107 (i, sched_group_cpus(group)) {
if ( V_428 )
V_70 = F_313 ( V_191 , V_423 ) ;
else
V_70 = F_314 ( V_191 , V_423 ) ;
V_427 += V_70 ;
}
V_427 = ( V_427 * V_132 ) / V_114 -> V_429 -> V_131 ;
if ( V_428 ) {
V_405 = V_427 ;
} else if ( V_427 < V_421 ) {
V_421 = V_427 ;
V_419 = V_114 ;
}
} while ( V_114 = V_114 -> V_58 , V_114 != V_156 -> V_420 );
if ( ! V_419 || 100 * V_405 < V_425 * V_421 )
return NULL ;
return V_419 ;
}
static int
F_326 ( struct V_417 * V_114 , struct V_26 * V_29 , int V_407 )
{
unsigned long V_70 , V_421 = V_422 ;
int V_419 = - 1 ;
int V_191 ;
F_327 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_109 ( V_191 ) ;
if ( V_70 < V_421 || ( V_70 == V_421 && V_191 == V_407 ) ) {
V_421 = V_70 ;
V_419 = V_191 ;
}
}
return V_419 ;
}
static int F_328 ( struct V_26 * V_29 , int V_430 )
{
struct V_155 * V_156 ;
struct V_417 * V_431 ;
int V_191 = F_125 ( V_29 ) ;
if ( F_329 ( V_430 ) )
return V_430 ;
if ( V_191 != V_430 && F_330 ( V_191 , V_430 ) && F_329 ( V_191 ) )
return V_191 ;
V_156 = F_126 ( F_127 ( V_432 , V_430 ) ) ;
F_331 (sd) {
V_431 = V_156 -> V_420 ;
do {
if ( ! F_324 ( F_325 ( V_431 ) ,
F_119 ( V_29 ) ) )
goto V_58;
F_107 (i, sched_group_cpus(sg)) {
if ( V_191 == V_430 || ! F_329 ( V_191 ) )
goto V_58;
}
V_430 = F_332 ( F_325 ( V_431 ) ,
F_119 ( V_29 ) ) ;
goto V_433;
V_58:
V_431 = V_431 -> V_58 ;
} while ( V_431 != V_156 -> V_420 );
}
V_433:
return V_430 ;
}
static int
F_333 ( struct V_26 * V_29 , int V_408 , int V_418 , int V_434 )
{
struct V_155 * V_435 , * V_436 = NULL , * V_156 = NULL ;
int V_130 = F_260 () ;
int V_437 = V_130 ;
int V_438 = 0 ;
int V_404 = V_434 & V_439 ;
if ( V_29 -> V_440 == 1 )
return V_408 ;
if ( V_418 & V_426 ) {
if ( F_118 ( V_130 , F_119 ( V_29 ) ) )
V_438 = 1 ;
V_437 = V_408 ;
}
F_116 () ;
F_334 (cpu, tmp) {
if ( ! ( V_435 -> V_201 & V_441 ) )
continue;
if ( V_438 && ( V_435 -> V_201 & V_442 ) &&
F_118 ( V_408 , F_335 ( V_435 ) ) ) {
V_436 = V_435 ;
break;
}
if ( V_435 -> V_201 & V_418 )
V_156 = V_435 ;
}
if ( V_436 ) {
if ( V_130 != V_408 && F_322 ( V_436 , V_29 , V_404 ) )
V_408 = V_130 ;
V_437 = F_328 ( V_29 , V_408 ) ;
goto V_149;
}
while ( V_156 ) {
struct V_417 * V_114 ;
int V_4 ;
if ( ! ( V_156 -> V_201 & V_418 ) ) {
V_156 = V_156 -> V_443 ;
continue;
}
V_114 = F_323 ( V_156 , V_29 , V_130 , V_418 ) ;
if ( ! V_114 ) {
V_156 = V_156 -> V_443 ;
continue;
}
V_437 = F_326 ( V_114 , V_29 , V_130 ) ;
if ( V_437 == - 1 || V_437 == V_130 ) {
V_156 = V_156 -> V_443 ;
continue;
}
V_130 = V_437 ;
V_4 = V_156 -> V_444 ;
V_156 = NULL ;
F_334 (cpu, tmp) {
if ( V_4 <= V_435 -> V_444 )
break;
if ( V_435 -> V_201 & V_418 )
V_156 = V_435 ;
}
}
V_149:
F_122 () ;
return V_437 ;
}
static void
F_336 ( struct V_26 * V_29 , int V_445 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_199 ( V_28 ) ;
F_202 ( V_28 -> V_77 . V_286 ,
& V_25 -> V_299 ) ;
}
}
static unsigned long
F_337 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_446 = V_447 ;
return F_58 ( V_446 , V_28 ) ;
}
static int
F_244 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_446 , V_448 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_448 <= 0 )
return - 1 ;
V_446 = F_337 ( V_45 , V_28 ) ;
if ( V_448 > V_446 )
return 1 ;
return 0 ;
}
static void F_338 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_449 == V_450 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_311 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_449 == V_450 ) )
return;
F_61 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_339 ( struct V_27 * V_28 )
{
F_61 (se)
F_24 ( V_28 ) -> V_321 = V_28 ;
}
static void F_340 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_434 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_451 = V_25 -> V_72 >= V_67 ;
int V_452 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_195 ( F_24 ( V_36 ) ) ) )
return;
if ( F_231 ( V_453 ) && V_451 && ! ( V_434 & V_454 ) ) {
F_311 ( V_36 ) ;
V_452 = 1 ;
}
if ( F_341 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_449 == V_450 ) &&
F_12 ( V_29 -> V_449 != V_450 ) )
goto V_455;
if ( F_14 ( V_29 -> V_449 != V_456 ) || ! F_231 ( V_457 ) )
return;
F_35 ( & V_28 , & V_36 ) ;
F_65 ( F_24 ( V_28 ) ) ;
F_159 ( ! V_36 ) ;
if ( F_244 ( V_28 , V_36 ) == 1 ) {
if ( ! V_452 )
F_311 ( V_36 ) ;
goto V_455;
}
return;
V_455:
F_241 ( V_45 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_349 ) )
return;
if ( F_231 ( V_458 ) && V_451 && F_21 ( V_28 ) )
F_338 ( V_28 ) ;
}
static struct V_26 *
F_342 ( struct V_24 * V_24 , struct V_26 * V_329 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_459 ;
V_460:
#ifdef F_343
if ( ! V_25 -> V_72 )
goto V_349;
if ( V_329 -> V_390 != & V_391 )
goto V_461;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 && V_45 -> V_76 )
F_65 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_14 ( F_246 ( V_25 ) ) )
goto V_461;
V_28 = F_243 ( V_25 , V_45 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( V_329 != V_29 ) {
struct V_27 * V_36 = & V_329 -> V_28 ;
while ( ! ( V_25 = F_33 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_245 ( F_24 ( V_36 ) , V_36 ) ;
V_36 = F_34 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_242 ( F_24 ( V_28 ) , V_28 ) ;
V_28 = F_34 ( V_28 ) ;
}
}
F_245 ( V_25 , V_36 ) ;
F_242 ( V_25 , V_28 ) ;
}
if ( F_307 ( V_24 ) )
F_303 ( V_24 , V_29 ) ;
return V_29 ;
V_461:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_72 )
goto V_349;
F_344 ( V_24 , V_329 ) ;
do {
V_28 = F_243 ( V_25 , NULL ) ;
F_242 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_307 ( V_24 ) )
F_303 ( V_24 , V_29 ) ;
return V_29 ;
V_349:
V_459 = F_220 ( V_24 ) ;
if ( V_459 < 0 )
return V_462 ;
if ( V_459 > 0 )
goto V_460;
return NULL ;
}
static void F_345 ( struct V_24 * V_24 , struct V_26 * V_329 )
{
struct V_27 * V_28 = & V_329 -> V_28 ;
struct V_25 * V_25 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_245 ( V_25 , V_28 ) ;
}
}
static void F_346 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_237 ( V_25 , V_28 ) ;
if ( V_45 -> V_449 != V_463 ) {
F_276 ( V_24 ) ;
F_65 ( V_25 ) ;
V_24 -> V_464 = 1 ;
}
F_339 ( V_28 ) ;
}
static bool F_347 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_455 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_195 ( F_24 ( V_28 ) ) )
return false ;
F_311 ( V_28 ) ;
F_346 ( V_24 ) ;
return true ;
}
static void F_348 ( struct V_26 * V_29 , struct V_465 * V_136 )
{
F_349 ( V_136 -> V_143 , V_29 , 0 ) ;
F_350 ( V_29 , V_136 -> V_120 ) ;
F_351 ( V_136 -> V_145 , V_29 , 0 ) ;
F_352 ( V_136 -> V_145 , V_29 , 0 ) ;
}
static int
F_353 ( struct V_26 * V_29 , T_2 V_81 )
{
T_3 V_42 ;
if ( V_29 -> V_390 != & V_391 )
return 0 ;
if ( F_14 ( V_29 -> V_449 == V_450 ) )
return 0 ;
if ( F_231 ( V_466 ) && V_302 () -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_467 == - 1 )
return 1 ;
if ( V_467 == 0 )
return 0 ;
V_42 = V_81 - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_467 ;
}
static bool F_354 ( struct V_26 * V_29 , struct V_465 * V_136 )
{
int V_119 , V_122 ;
if ( ! F_231 ( V_468 ) || ! V_29 -> V_112 ||
! ( V_136 -> V_156 -> V_201 & V_469 ) ) {
return false ;
}
V_119 = F_99 ( V_136 -> V_144 ) ;
V_122 = F_99 ( V_136 -> V_120 ) ;
if ( V_119 == V_122 )
return false ;
if ( V_122 == V_29 -> V_105 )
return true ;
if ( F_96 ( V_29 , V_122 ) > F_96 ( V_29 , V_119 ) &&
F_97 ( V_29 , V_122 ) > F_97 ( V_29 , V_119 ) )
return true ;
return false ;
}
static bool F_355 ( struct V_26 * V_29 , struct V_465 * V_136 )
{
int V_119 , V_122 ;
if ( ! F_231 ( V_470 ) || ! F_231 ( V_471 ) )
return false ;
if ( ! V_29 -> V_112 || ! ( V_136 -> V_156 -> V_201 & V_469 ) )
return false ;
V_119 = F_99 ( V_136 -> V_144 ) ;
V_122 = F_99 ( V_136 -> V_120 ) ;
if ( V_119 == V_122 )
return false ;
if ( V_119 == V_29 -> V_105 )
return true ;
if ( F_96 ( V_29 , V_122 ) < F_96 ( V_29 , V_119 ) ||
F_97 ( V_29 , V_122 ) < F_97 ( V_29 , V_119 ) )
return true ;
return false ;
}
static inline bool F_354 ( struct V_26 * V_29 ,
struct V_465 * V_136 )
{
return false ;
}
static inline bool F_355 ( struct V_26 * V_29 ,
struct V_465 * V_136 )
{
return false ;
}
static
int F_356 ( struct V_26 * V_29 , struct V_465 * V_136 )
{
int V_472 = 0 ;
if ( F_270 ( V_261 ( V_29 ) , V_136 -> V_144 , V_136 -> V_120 ) )
return 0 ;
if ( ! F_118 ( V_136 -> V_120 , F_119 ( V_29 ) ) ) {
int V_130 ;
F_229 ( V_29 , V_28 . V_83 . V_473 ) ;
V_136 -> V_201 |= V_474 ;
if ( ! V_136 -> V_475 || ( V_136 -> V_201 & V_476 ) )
return 0 ;
F_327 (cpu, env->dst_grpmask, env->cpus) {
if ( F_118 ( V_130 , F_119 ( V_29 ) ) ) {
V_136 -> V_201 |= V_476 ;
V_136 -> V_477 = V_130 ;
break;
}
}
return 0 ;
}
V_136 -> V_201 &= ~ V_478 ;
if ( F_357 ( V_136 -> V_143 , V_29 ) ) {
F_229 ( V_29 , V_28 . V_83 . V_479 ) ;
return 0 ;
}
V_472 = F_353 ( V_29 , F_66 ( V_136 -> V_143 ) ) ;
if ( ! V_472 )
V_472 = F_355 ( V_29 , V_136 ) ;
if ( F_354 ( V_29 , V_136 ) ) {
#ifdef F_78
if ( V_472 ) {
F_229 ( V_136 -> V_156 , V_480 [ V_136 -> V_349 ] ) ;
F_229 ( V_29 , V_28 . V_83 . V_481 ) ;
}
#endif
return 1 ;
}
if ( ! V_472 ||
V_136 -> V_156 -> V_482 > V_136 -> V_156 -> V_483 ) {
if ( V_472 ) {
F_229 ( V_136 -> V_156 , V_480 [ V_136 -> V_349 ] ) ;
F_229 ( V_29 , V_28 . V_83 . V_481 ) ;
}
return 1 ;
}
F_229 ( V_29 , V_28 . V_83 . V_484 ) ;
return 0 ;
}
static int F_358 ( struct V_465 * V_136 )
{
struct V_26 * V_29 , * V_268 ;
F_359 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_356 ( V_29 , V_136 ) )
continue;
F_348 ( V_29 , V_136 ) ;
F_229 ( V_136 -> V_156 , V_485 [ V_136 -> V_349 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_360 ( struct V_465 * V_136 )
{
struct V_486 * V_487 = & V_136 -> V_143 -> V_260 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_488 = 0 ;
if ( V_136 -> V_425 <= 0 )
return 0 ;
while ( ! F_280 ( V_487 ) ) {
V_29 = F_361 ( V_487 , struct V_26 , V_28 . V_259 ) ;
V_136 -> V_489 ++ ;
if ( V_136 -> V_489 > V_136 -> V_490 )
break;
if ( V_136 -> V_489 > V_136 -> V_491 ) {
V_136 -> V_491 += V_492 ;
V_136 -> V_201 |= V_493 ;
break;
}
if ( ! F_356 ( V_29 , V_136 ) )
goto V_58;
V_70 = F_120 ( V_29 ) ;
if ( F_231 ( V_494 ) && V_70 < 16 && ! V_136 -> V_156 -> V_482 )
goto V_58;
if ( ( V_70 / 2 ) > V_136 -> V_425 )
goto V_58;
F_348 ( V_29 , V_136 ) ;
V_488 ++ ;
V_136 -> V_425 -= V_70 ;
#ifdef F_362
if ( V_136 -> V_349 == V_495 )
break;
#endif
if ( V_136 -> V_425 <= 0 )
break;
continue;
V_58:
F_363 ( & V_29 -> V_28 . V_259 , V_487 ) ;
}
F_69 ( V_136 -> V_156 , V_485 [ V_136 -> V_349 ] , V_488 ) ;
return V_488 ;
}
static void F_364 ( struct V_261 * V_33 , int V_130 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_130 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_130 ] ;
if ( F_195 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_212 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_208 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_365 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
struct V_25 * V_25 ;
unsigned long V_201 ;
F_366 ( & V_24 -> V_190 , V_201 ) ;
F_276 ( V_24 ) ;
F_302 (rq, cfs_rq) {
F_364 ( V_25 -> V_33 , V_24 -> V_130 ) ;
}
F_367 ( & V_24 -> V_190 , V_201 ) ;
}
static void F_368 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_164 ;
unsigned long V_70 ;
if ( V_25 -> V_496 == V_81 )
return;
V_25 -> V_497 = NULL ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_497 = V_28 ;
if ( V_25 -> V_496 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_498 = V_25 -> V_289 ;
V_25 -> V_496 = V_81 ;
}
while ( ( V_28 = V_25 -> V_497 ) != NULL ) {
V_70 = V_25 -> V_498 ;
V_70 = F_369 ( V_70 * V_28 -> V_77 . V_286 ,
V_25 -> V_289 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_498 = V_70 ;
V_25 -> V_496 = V_81 ;
}
}
static unsigned long F_120 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_368 ( V_25 ) ;
return F_369 ( V_29 -> V_28 . V_77 . V_286 * V_25 -> V_498 ,
V_25 -> V_289 + 1 ) ;
}
static inline void F_365 ( int V_130 )
{
}
static unsigned long F_120 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_286 ;
}
static inline void F_370 ( struct V_499 * V_500 )
{
* V_500 = (struct V_499 ) {
. V_501 = NULL ,
. V_174 = NULL ,
. V_502 = 0UL ,
. V_503 = 0UL ,
. V_504 = {
. V_427 = 0UL ,
} ,
} ;
}
static inline int F_371 ( struct V_155 * V_156 ,
enum V_505 V_349 )
{
int V_423 ;
switch ( V_349 ) {
case V_506 :
V_423 = V_156 -> V_507 ;
break;
case V_495 :
V_423 = V_156 -> V_508 ;
break;
default:
V_423 = V_156 -> V_509 ;
break;
}
return V_423 ;
}
static unsigned long F_372 ( struct V_155 * V_156 , int V_130 )
{
return V_132 ;
}
unsigned long __weak F_373 ( struct V_155 * V_156 , int V_130 )
{
return F_372 ( V_156 , V_130 ) ;
}
static unsigned long F_374 ( struct V_155 * V_156 , int V_130 )
{
unsigned long V_4 = V_156 -> V_444 ;
unsigned long V_510 = V_156 -> V_510 ;
V_510 /= V_4 ;
return V_510 ;
}
unsigned long __weak F_375 ( struct V_155 * V_156 , int V_130 )
{
return F_374 ( V_156 , V_130 ) ;
}
static unsigned long F_376 ( int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
T_2 V_393 , V_511 , V_512 , V_77 ;
V_512 = F_117 ( V_24 -> V_512 ) ;
V_77 = F_117 ( V_24 -> V_513 ) ;
V_393 = F_377 () + ( F_75 ( V_24 ) - V_512 ) ;
if ( F_14 ( V_393 < V_77 ) ) {
V_511 = 0 ;
} else {
V_511 = V_393 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_393 < V_132 ) )
V_393 = V_132 ;
V_393 >>= V_514 ;
return F_204 ( V_511 , V_393 ) ;
}
static void F_378 ( struct V_155 * V_156 , int V_130 )
{
unsigned long V_4 = V_156 -> V_444 ;
unsigned long V_131 = V_132 ;
struct V_417 * V_515 = V_156 -> V_420 ;
if ( ( V_156 -> V_201 & V_516 ) && V_4 > 1 ) {
if ( F_231 ( V_517 ) )
V_131 *= F_375 ( V_156 , V_130 ) ;
else
V_131 *= F_374 ( V_156 , V_130 ) ;
V_131 >>= V_514 ;
}
V_515 -> V_429 -> V_518 = V_131 ;
if ( F_231 ( V_517 ) )
V_131 *= F_373 ( V_156 , V_130 ) ;
else
V_131 *= F_372 ( V_156 , V_130 ) ;
V_131 >>= V_514 ;
V_131 *= F_376 ( V_130 ) ;
V_131 >>= V_514 ;
if ( ! V_131 )
V_131 = 1 ;
F_108 ( V_130 ) -> V_396 = V_131 ;
V_515 -> V_429 -> V_131 = V_131 ;
}
void F_379 ( struct V_155 * V_156 , int V_130 )
{
struct V_155 * V_443 = V_156 -> V_443 ;
struct V_417 * V_114 , * V_515 = V_156 -> V_420 ;
unsigned long V_131 , V_518 ;
unsigned long V_519 ;
V_519 = F_139 ( V_156 -> V_520 ) ;
V_519 = F_140 ( V_519 , 1UL , V_521 ) ;
V_515 -> V_429 -> V_522 = V_164 + V_519 ;
if ( ! V_443 ) {
F_378 ( V_156 , V_130 ) ;
return;
}
V_518 = V_131 = 0 ;
if ( V_443 -> V_201 & V_523 ) {
F_107 (cpu, sched_group_cpus(sdg)) {
struct V_524 * V_429 ;
struct V_24 * V_24 = F_108 ( V_130 ) ;
if ( F_14 ( ! V_24 -> V_156 ) ) {
V_518 += F_110 ( V_130 ) ;
V_131 += F_110 ( V_130 ) ;
continue;
}
V_429 = V_24 -> V_156 -> V_420 -> V_429 ;
V_518 += V_429 -> V_518 ;
V_131 += V_429 -> V_131 ;
}
} else {
V_114 = V_443 -> V_420 ;
do {
V_518 += V_114 -> V_429 -> V_518 ;
V_131 += V_114 -> V_429 -> V_131 ;
V_114 = V_114 -> V_58 ;
} while ( V_114 != V_443 -> V_420 );
}
V_515 -> V_429 -> V_518 = V_518 ;
V_515 -> V_429 -> V_131 = V_131 ;
}
static inline int
F_380 ( struct V_155 * V_156 , struct V_417 * V_114 )
{
if ( ! ( V_156 -> V_201 & V_516 ) )
return 0 ;
if ( V_114 -> V_429 -> V_131 * 32 > V_114 -> V_429 -> V_518 * 29 )
return 1 ;
return 0 ;
}
static inline int F_381 ( struct V_417 * V_114 )
{
return V_114 -> V_429 -> V_425 ;
}
static inline int F_382 ( struct V_465 * V_136 , struct V_417 * V_114 )
{
unsigned int V_133 , V_525 , V_8 ;
unsigned int V_131 , V_518 ;
V_131 = V_114 -> V_429 -> V_131 ;
V_518 = V_114 -> V_429 -> V_518 ;
V_8 = V_114 -> F_97 ;
V_525 = F_56 ( V_132 * V_8 , V_518 ) ;
V_133 = V_8 / V_525 ;
V_133 = F_5 ( unsigned , V_133 , F_111 ( V_131 , V_132 ) ) ;
if ( ! V_133 )
V_133 = F_380 ( V_136 -> V_156 , V_114 ) ;
return V_133 ;
}
static inline void F_383 ( struct V_465 * V_136 ,
struct V_417 * V_114 , int V_423 ,
int V_428 , struct V_526 * V_527 )
{
unsigned long V_70 ;
int V_191 ;
memset ( V_527 , 0 , sizeof( * V_527 ) ) ;
F_327 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_108 ( V_191 ) ;
if ( V_428 )
V_70 = F_314 ( V_191 , V_423 ) ;
else
V_70 = F_313 ( V_191 , V_423 ) ;
V_527 -> V_528 += V_70 ;
V_527 -> V_529 += V_24 -> V_72 ;
#ifdef F_384
V_527 -> V_104 += V_24 -> V_104 ;
V_527 -> V_106 += V_24 -> V_106 ;
#endif
V_527 -> V_530 += F_109 ( V_191 ) ;
if ( F_329 ( V_191 ) )
V_527 -> V_531 ++ ;
}
V_527 -> V_532 = V_114 -> V_429 -> V_131 ;
V_527 -> V_427 = ( V_527 -> V_528 * V_132 ) / V_527 -> V_532 ;
if ( V_527 -> V_529 )
V_527 -> V_533 = V_527 -> V_530 / V_527 -> V_529 ;
V_527 -> F_97 = V_114 -> F_97 ;
V_527 -> V_534 = F_381 ( V_114 ) ;
V_527 -> V_535 = F_382 ( V_136 , V_114 ) ;
if ( V_527 -> V_535 > V_527 -> V_529 )
V_527 -> V_536 = 1 ;
}
static bool F_385 ( struct V_465 * V_136 ,
struct V_499 * V_500 ,
struct V_417 * V_431 ,
struct V_526 * V_527 )
{
if ( V_527 -> V_427 <= V_500 -> V_504 . V_427 )
return false ;
if ( V_527 -> V_529 > V_527 -> V_535 )
return true ;
if ( V_527 -> V_534 )
return true ;
if ( ( V_136 -> V_156 -> V_201 & V_537 ) && V_527 -> V_529 &&
V_136 -> V_120 < F_386 ( V_431 ) ) {
if ( ! V_500 -> V_501 )
return true ;
if ( F_386 ( V_500 -> V_501 ) > F_386 ( V_431 ) )
return true ;
}
return false ;
}
static inline enum V_538 F_387 ( struct V_526 * V_527 )
{
if ( V_527 -> V_529 > V_527 -> V_104 )
return V_539 ;
if ( V_527 -> V_529 > V_527 -> V_106 )
return V_172 ;
return V_540 ;
}
static inline enum V_538 F_388 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_104 )
return V_539 ;
if ( V_24 -> V_72 > V_24 -> V_106 )
return V_172 ;
return V_540 ;
}
static inline enum V_538 F_387 ( struct V_526 * V_527 )
{
return V_540 ;
}
static inline enum V_538 F_388 ( struct V_24 * V_24 )
{
return V_539 ;
}
static inline void F_389 ( struct V_465 * V_136 , struct V_499 * V_500 )
{
struct V_155 * V_443 = V_136 -> V_156 -> V_443 ;
struct V_417 * V_431 = V_136 -> V_156 -> V_420 ;
struct V_526 V_541 ;
int V_423 , V_542 = 0 ;
if ( V_443 && V_443 -> V_201 & V_543 )
V_542 = 1 ;
V_423 = F_371 ( V_136 -> V_156 , V_136 -> V_349 ) ;
do {
struct V_526 * V_527 = & V_541 ;
int V_428 ;
V_428 = F_118 ( V_136 -> V_120 , F_325 ( V_431 ) ) ;
if ( V_428 ) {
V_500 -> V_174 = V_431 ;
V_527 = & V_500 -> V_544 ;
if ( V_136 -> V_349 != V_495 ||
F_390 ( V_164 , V_431 -> V_429 -> V_522 ) )
F_379 ( V_136 -> V_156 , V_136 -> V_120 ) ;
}
F_383 ( V_136 , V_431 , V_423 , V_428 , V_527 ) ;
if ( V_428 )
goto V_545;
if ( V_542 && V_500 -> V_174 &&
V_500 -> V_544 . V_536 )
V_527 -> V_535 = F_138 ( V_527 -> V_535 , 1U ) ;
if ( F_385 ( V_136 , V_500 , V_431 , V_527 ) ) {
V_500 -> V_501 = V_431 ;
V_500 -> V_504 = * V_527 ;
}
V_545:
V_500 -> V_502 += V_527 -> V_528 ;
V_500 -> V_503 += V_527 -> V_532 ;
V_431 = V_431 -> V_58 ;
} while ( V_431 != V_136 -> V_156 -> V_420 );
if ( V_136 -> V_156 -> V_201 & V_469 )
V_136 -> V_538 = F_387 ( & V_500 -> V_504 ) ;
}
static int F_391 ( struct V_465 * V_136 , struct V_499 * V_500 )
{
int V_546 ;
if ( ! ( V_136 -> V_156 -> V_201 & V_537 ) )
return 0 ;
if ( ! V_500 -> V_501 )
return 0 ;
V_546 = F_386 ( V_500 -> V_501 ) ;
if ( V_136 -> V_120 > V_546 )
return 0 ;
V_136 -> V_425 = F_111 (
V_500 -> V_504 . V_427 * V_500 -> V_504 . V_532 ,
V_132 ) ;
return 1 ;
}
static inline
void F_392 ( struct V_465 * V_136 , struct V_499 * V_500 )
{
unsigned long V_435 , V_547 = 0 , V_548 = 0 ;
unsigned int V_549 = 2 ;
unsigned long V_550 ;
struct V_526 * V_174 , * V_501 ;
V_174 = & V_500 -> V_544 ;
V_501 = & V_500 -> V_504 ;
if ( ! V_174 -> V_529 )
V_174 -> V_533 = F_315 ( V_136 -> V_120 ) ;
else if ( V_501 -> V_533 > V_174 -> V_533 )
V_549 = 1 ;
V_550 =
( V_501 -> V_533 * V_132 ) /
V_501 -> V_532 ;
if ( V_501 -> V_427 + V_550 >=
V_174 -> V_427 + ( V_550 * V_549 ) ) {
V_136 -> V_425 = V_501 -> V_533 ;
return;
}
V_547 += V_501 -> V_532 *
F_138 ( V_501 -> V_533 , V_501 -> V_427 ) ;
V_547 += V_174 -> V_532 *
F_138 ( V_174 -> V_533 , V_174 -> V_427 ) ;
V_547 /= V_132 ;
if ( V_501 -> V_427 > V_550 ) {
V_548 += V_501 -> V_532 *
F_138 ( V_501 -> V_533 ,
V_501 -> V_427 - V_550 ) ;
}
if ( V_501 -> V_427 * V_501 -> V_532 <
V_501 -> V_533 * V_132 ) {
V_435 = ( V_501 -> V_427 * V_501 -> V_532 ) /
V_174 -> V_532 ;
} else {
V_435 = ( V_501 -> V_533 * V_132 ) /
V_174 -> V_532 ;
}
V_548 += V_174 -> V_532 *
F_138 ( V_174 -> V_533 , V_174 -> V_427 + V_435 ) ;
V_548 /= V_132 ;
if ( V_548 > V_547 )
V_136 -> V_425 = V_501 -> V_533 ;
}
static inline void F_393 ( struct V_465 * V_136 , struct V_499 * V_500 )
{
unsigned long V_551 , V_552 = ~ 0UL ;
struct V_526 * V_174 , * V_501 ;
V_174 = & V_500 -> V_544 ;
V_501 = & V_500 -> V_504 ;
if ( V_501 -> V_534 ) {
V_501 -> V_533 =
F_138 ( V_501 -> V_533 , V_500 -> V_427 ) ;
}
if ( V_501 -> V_427 <= V_500 -> V_427 ||
V_174 -> V_427 >= V_500 -> V_427 ) {
V_136 -> V_425 = 0 ;
return F_392 ( V_136 , V_500 ) ;
}
if ( ! V_501 -> V_534 ) {
V_552 =
( V_501 -> V_529 - V_501 -> V_535 ) ;
V_552 *= ( V_553 * V_132 ) ;
V_552 /= V_501 -> V_532 ;
}
V_551 = F_138 ( V_501 -> V_427 - V_500 -> V_427 , V_552 ) ;
V_136 -> V_425 = F_138 (
V_551 * V_501 -> V_532 ,
( V_500 -> V_427 - V_174 -> V_427 ) * V_174 -> V_532
) / V_132 ;
if ( V_136 -> V_425 < V_501 -> V_533 )
return F_392 ( V_136 , V_500 ) ;
}
static struct V_417 * F_394 ( struct V_465 * V_136 )
{
struct V_526 * V_174 , * V_501 ;
struct V_499 V_500 ;
F_370 ( & V_500 ) ;
F_389 ( V_136 , & V_500 ) ;
V_174 = & V_500 . V_544 ;
V_501 = & V_500 . V_504 ;
if ( ( V_136 -> V_349 == V_554 || V_136 -> V_349 == V_495 ) &&
F_391 ( V_136 , & V_500 ) )
return V_500 . V_501 ;
if ( ! V_500 . V_501 || V_501 -> V_529 == 0 )
goto V_555;
V_500 . V_427 = ( V_132 * V_500 . V_502 ) / V_500 . V_503 ;
if ( V_501 -> V_534 )
goto V_556;
if ( V_136 -> V_349 == V_495 && V_174 -> V_536 &&
! V_501 -> V_536 )
goto V_556;
if ( V_174 -> V_427 >= V_501 -> V_427 )
goto V_555;
if ( V_174 -> V_427 >= V_500 . V_427 )
goto V_555;
if ( V_136 -> V_349 == V_554 ) {
if ( ( V_174 -> V_531 < V_501 -> V_531 ) &&
V_501 -> V_529 <= V_501 -> F_97 )
goto V_555;
} else {
if ( 100 * V_501 -> V_427 <=
V_136 -> V_156 -> V_154 * V_174 -> V_427 )
goto V_555;
}
V_556:
F_393 ( V_136 , & V_500 ) ;
return V_500 . V_501 ;
V_555:
V_136 -> V_425 = 0 ;
return NULL ;
}
static struct V_24 * F_395 ( struct V_465 * V_136 ,
struct V_417 * V_114 )
{
struct V_24 * V_501 = NULL , * V_24 ;
unsigned long V_557 = 0 , V_558 = 1 ;
int V_191 ;
F_327 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_131 , V_133 , V_400 ;
enum V_538 V_559 ;
V_24 = F_108 ( V_191 ) ;
V_559 = F_388 ( V_24 ) ;
if ( V_559 > V_136 -> V_538 )
continue;
V_131 = F_110 ( V_191 ) ;
V_133 = F_111 ( V_131 , V_132 ) ;
if ( ! V_133 )
V_133 = F_380 ( V_136 -> V_156 , V_114 ) ;
V_400 = F_109 ( V_191 ) ;
if ( V_133 && V_24 -> V_72 == 1 && V_400 > V_136 -> V_425 )
continue;
if ( V_400 * V_558 > V_557 * V_131 ) {
V_557 = V_400 ;
V_558 = V_131 ;
V_501 = V_24 ;
}
}
return V_501 ;
}
static int F_396 ( struct V_465 * V_136 )
{
struct V_155 * V_156 = V_136 -> V_156 ;
if ( V_136 -> V_349 == V_495 ) {
if ( ( V_156 -> V_201 & V_537 ) && V_136 -> V_144 > V_136 -> V_120 )
return 1 ;
}
return F_14 ( V_156 -> V_482 > V_156 -> V_483 + 2 ) ;
}
static int F_397 ( struct V_465 * V_136 )
{
struct V_417 * V_431 = V_136 -> V_156 -> V_420 ;
struct V_560 * V_561 , * V_562 ;
int V_130 , V_563 = - 1 ;
if ( V_136 -> V_349 == V_495 )
return 1 ;
V_561 = F_325 ( V_431 ) ;
V_562 = F_398 ( V_431 ) ;
F_327 (cpu, sg_cpus, env->cpus) {
if ( ! F_118 ( V_130 , V_562 ) || ! F_329 ( V_130 ) )
continue;
V_563 = V_130 ;
break;
}
if ( V_563 == - 1 )
V_563 = F_399 ( V_431 ) ;
return V_563 == V_136 -> V_120 ;
}
static int F_400 ( int V_407 , struct V_24 * V_302 ,
struct V_155 * V_156 , enum V_505 V_349 ,
int * V_564 )
{
int V_565 , V_566 , V_567 = 0 ;
struct V_155 * V_568 = V_156 -> V_34 ;
struct V_417 * V_114 ;
struct V_24 * V_501 ;
unsigned long V_201 ;
struct V_560 * V_8 = F_401 ( V_569 ) ;
struct V_465 V_136 = {
. V_156 = V_156 ,
. V_120 = V_407 ,
. V_145 = V_302 ,
. V_475 = F_325 ( V_156 -> V_420 ) ,
. V_349 = V_349 ,
. V_491 = V_492 ,
. V_8 = V_8 ,
. V_538 = V_540 ,
} ;
if ( V_349 == V_495 )
V_136 . V_475 = NULL ;
F_402 ( V_8 , V_570 ) ;
F_229 ( V_156 , V_571 [ V_349 ] ) ;
V_572:
if ( ! F_397 ( & V_136 ) ) {
* V_564 = 0 ;
goto V_555;
}
V_114 = F_394 ( & V_136 ) ;
if ( ! V_114 ) {
F_229 ( V_156 , V_573 [ V_349 ] ) ;
goto V_555;
}
V_501 = F_395 ( & V_136 , V_114 ) ;
if ( ! V_501 ) {
F_229 ( V_156 , V_574 [ V_349 ] ) ;
goto V_555;
}
F_159 ( V_501 == V_136 . V_145 ) ;
F_69 ( V_156 , V_575 [ V_349 ] , V_136 . V_425 ) ;
V_565 = 0 ;
if ( V_501 -> V_72 > 1 ) {
V_136 . V_201 |= V_478 ;
V_136 . V_144 = V_501 -> V_130 ;
V_136 . V_143 = V_501 ;
V_136 . V_490 = F_138 ( V_576 , V_501 -> V_72 ) ;
V_577:
F_403 ( V_201 ) ;
F_404 ( V_136 . V_145 , V_501 ) ;
V_566 = F_360 ( & V_136 ) ;
V_565 += V_566 ;
F_405 ( V_136 . V_145 , V_501 ) ;
F_406 ( V_201 ) ;
if ( V_566 && V_136 . V_120 != F_260 () )
F_407 ( V_136 . V_120 ) ;
if ( V_136 . V_201 & V_493 ) {
V_136 . V_201 &= ~ V_493 ;
goto V_577;
}
if ( ( V_136 . V_201 & V_476 ) && V_136 . V_425 > 0 ) {
F_408 ( V_136 . V_120 , V_136 . V_8 ) ;
V_136 . V_145 = F_108 ( V_136 . V_477 ) ;
V_136 . V_120 = V_136 . V_477 ;
V_136 . V_201 &= ~ V_476 ;
V_136 . V_489 = 0 ;
V_136 . V_491 = V_492 ;
goto V_577;
}
if ( V_568 ) {
int * V_578 = & V_568 -> V_420 -> V_429 -> V_425 ;
if ( ( V_136 . V_201 & V_474 ) && V_136 . V_425 > 0 ) {
* V_578 = 1 ;
} else if ( * V_578 )
* V_578 = 0 ;
}
if ( F_14 ( V_136 . V_201 & V_478 ) ) {
F_408 ( F_27 ( V_501 ) , V_8 ) ;
if ( ! F_409 ( V_8 ) ) {
V_136 . V_489 = 0 ;
V_136 . V_491 = V_492 ;
goto V_572;
}
goto V_555;
}
}
if ( ! V_565 ) {
F_229 ( V_156 , V_579 [ V_349 ] ) ;
if ( V_349 != V_495 )
V_156 -> V_482 ++ ;
if ( F_396 ( & V_136 ) ) {
F_366 ( & V_501 -> V_190 , V_201 ) ;
if ( ! F_118 ( V_407 ,
F_119 ( V_501 -> V_45 ) ) ) {
F_367 ( & V_501 -> V_190 ,
V_201 ) ;
V_136 . V_201 |= V_478 ;
goto V_580;
}
if ( ! V_501 -> V_567 ) {
V_501 -> V_567 = 1 ;
V_501 -> V_581 = V_407 ;
V_567 = 1 ;
}
F_367 ( & V_501 -> V_190 , V_201 ) ;
if ( V_567 ) {
F_410 ( F_27 ( V_501 ) ,
V_582 , V_501 ,
& V_501 -> V_583 ) ;
}
V_156 -> V_482 = V_156 -> V_483 + 1 ;
}
} else
V_156 -> V_482 = 0 ;
if ( F_12 ( ! V_567 ) ) {
V_156 -> V_520 = V_156 -> V_584 ;
} else {
if ( V_156 -> V_520 < V_156 -> V_585 )
V_156 -> V_520 *= 2 ;
}
goto V_257;
V_555:
F_229 ( V_156 , V_586 [ V_349 ] ) ;
V_156 -> V_482 = 0 ;
V_580:
if ( ( ( V_136 . V_201 & V_478 ) &&
V_156 -> V_520 < V_587 ) ||
( V_156 -> V_520 < V_156 -> V_585 ) )
V_156 -> V_520 *= 2 ;
V_565 = 0 ;
V_257:
return V_565 ;
}
static int F_220 ( struct V_24 * V_302 )
{
struct V_155 * V_156 ;
int V_588 = 0 ;
unsigned long V_589 = V_164 + V_165 ;
T_2 V_590 = 0 ;
int V_407 = V_302 -> V_130 ;
F_218 ( V_302 ) ;
V_302 -> V_591 = F_75 ( V_302 ) ;
if ( V_302 -> V_592 < V_467 )
goto V_257;
F_266 ( & V_302 -> V_190 ) ;
F_365 ( V_407 ) ;
F_116 () ;
F_334 (this_cpu, sd) {
unsigned long V_519 ;
int V_564 = 1 ;
T_2 V_593 , V_594 ;
if ( ! ( V_156 -> V_201 & V_441 ) )
continue;
if ( V_302 -> V_592 < V_590 + V_156 -> V_595 )
break;
if ( V_156 -> V_201 & V_596 ) {
V_593 = F_259 ( V_407 ) ;
V_588 = F_400 ( V_407 , V_302 ,
V_156 , V_495 ,
& V_564 ) ;
V_594 = F_259 ( V_407 ) - V_593 ;
if ( V_594 > V_156 -> V_595 )
V_156 -> V_595 = V_594 ;
V_590 += V_594 ;
}
V_519 = F_139 ( V_156 -> V_520 ) ;
if ( F_170 ( V_589 , V_156 -> V_597 + V_519 ) )
V_589 = V_156 -> V_597 + V_519 ;
if ( V_588 )
break;
}
F_122 () ;
F_264 ( & V_302 -> V_190 ) ;
if ( V_590 > V_302 -> V_598 )
V_302 -> V_598 = V_590 ;
if ( V_302 -> V_40 . V_359 && ! V_588 )
V_588 = 1 ;
if ( V_588 || F_170 ( V_164 , V_302 -> V_589 ) ) {
V_302 -> V_589 = V_589 ;
}
V_257:
if ( V_302 -> V_72 != V_302 -> V_40 . V_359 &&
( ( V_302 -> V_599 && V_302 -> V_599 -> V_76 ) ||
V_302 -> V_600 . V_601 ||
( V_302 -> V_559 . V_602 && ! F_411 ( & V_302 -> V_559 ) ) ) )
V_588 = - 1 ;
if ( V_588 ) {
F_219 ( V_302 ) ;
V_302 -> V_591 = 0 ;
}
return V_588 ;
}
static int V_582 ( void * V_355 )
{
struct V_24 * V_603 = V_355 ;
int V_546 = F_27 ( V_603 ) ;
int V_604 = V_603 -> V_581 ;
struct V_24 * V_605 = F_108 ( V_604 ) ;
struct V_155 * V_156 ;
F_412 ( & V_603 -> V_190 ) ;
if ( F_14 ( V_546 != F_260 () ||
! V_603 -> V_567 ) )
goto V_368;
if ( V_603 -> V_72 <= 1 )
goto V_368;
F_159 ( V_603 == V_605 ) ;
F_413 ( V_603 , V_605 ) ;
F_116 () ;
F_334 (target_cpu, sd) {
if ( ( V_156 -> V_201 & V_441 ) &&
F_118 ( V_546 , F_335 ( V_156 ) ) )
break;
}
if ( F_12 ( V_156 ) ) {
struct V_465 V_136 = {
. V_156 = V_156 ,
. V_120 = V_604 ,
. V_145 = V_605 ,
. V_144 = V_603 -> V_130 ,
. V_143 = V_603 ,
. V_349 = V_554 ,
} ;
F_229 ( V_156 , V_606 ) ;
if ( F_358 ( & V_136 ) )
F_229 ( V_156 , V_607 ) ;
else
F_229 ( V_156 , V_608 ) ;
}
F_122 () ;
F_414 ( V_603 , V_605 ) ;
V_368:
V_603 -> V_567 = 0 ;
F_415 ( & V_603 -> V_190 ) ;
return 0 ;
}
static inline int F_416 ( struct V_24 * V_24 )
{
return F_14 ( ! F_417 ( V_24 -> V_156 ) ) ;
}
static inline int F_418 ( void )
{
int V_609 = F_419 ( V_610 . V_611 ) ;
if ( V_609 < V_612 && F_329 ( V_609 ) )
return V_609 ;
return V_612 ;
}
static void F_420 ( void )
{
int V_613 ;
V_610 . V_589 ++ ;
V_613 = F_418 () ;
if ( V_613 >= V_612 )
return;
if ( F_421 ( V_614 , F_422 ( V_613 ) ) )
return;
F_423 ( V_613 ) ;
return;
}
static inline void F_424 ( int V_130 )
{
if ( F_14 ( F_425 ( V_615 , F_422 ( V_130 ) ) ) ) {
if ( F_12 ( F_118 ( V_130 , V_610 . V_611 ) ) ) {
F_408 ( V_130 , V_610 . V_611 ) ;
F_426 ( & V_610 . V_616 ) ;
}
F_427 ( V_615 , F_422 ( V_130 ) ) ;
}
}
static inline void F_428 ( void )
{
struct V_155 * V_156 ;
int V_130 = F_260 () ;
F_116 () ;
V_156 = F_126 ( F_127 ( V_617 , V_130 ) ) ;
if ( ! V_156 || ! V_156 -> V_618 )
goto V_149;
V_156 -> V_618 = 0 ;
F_429 ( & V_156 -> V_420 -> V_429 -> V_619 ) ;
V_149:
F_122 () ;
}
void F_430 ( void )
{
struct V_155 * V_156 ;
int V_130 = F_260 () ;
F_116 () ;
V_156 = F_126 ( F_127 ( V_617 , V_130 ) ) ;
if ( ! V_156 || V_156 -> V_618 )
goto V_149;
V_156 -> V_618 = 1 ;
F_426 ( & V_156 -> V_420 -> V_429 -> V_619 ) ;
V_149:
F_122 () ;
}
void F_431 ( int V_130 )
{
if ( ! F_432 ( V_130 ) )
return;
if ( F_425 ( V_615 , F_422 ( V_130 ) ) )
return;
if ( F_416 ( F_108 ( V_130 ) ) )
return;
F_433 ( V_130 , V_610 . V_611 ) ;
F_429 ( & V_610 . V_616 ) ;
F_434 ( V_615 , F_422 ( V_130 ) ) ;
}
static int F_435 ( struct V_620 * V_621 ,
unsigned long V_622 , void * V_623 )
{
switch ( V_622 & ~ V_624 ) {
case V_625 :
F_424 ( F_260 () ) ;
return V_626 ;
default:
return V_627 ;
}
}
void F_436 ( void )
{
V_521 = V_165 * F_6 () / 10 ;
}
static void F_437 ( struct V_24 * V_24 , enum V_505 V_349 )
{
int V_564 = 1 ;
int V_130 = V_24 -> V_130 ;
unsigned long V_519 ;
struct V_155 * V_156 ;
unsigned long V_589 = V_164 + 60 * V_165 ;
int V_628 = 0 ;
int V_629 , V_630 = 0 ;
T_2 V_631 = 0 ;
F_365 ( V_130 ) ;
F_116 () ;
F_334 (cpu, sd) {
if ( F_170 ( V_164 , V_156 -> V_632 ) ) {
V_156 -> V_595 =
( V_156 -> V_595 * 253 ) / 256 ;
V_156 -> V_632 = V_164 + V_165 ;
V_630 = 1 ;
}
V_631 += V_156 -> V_595 ;
if ( ! ( V_156 -> V_201 & V_441 ) )
continue;
if ( ! V_564 ) {
if ( V_630 )
continue;
break;
}
V_519 = V_156 -> V_520 ;
if ( V_349 != V_554 )
V_519 *= V_156 -> V_633 ;
V_519 = F_139 ( V_519 ) ;
V_519 = F_140 ( V_519 , 1UL , V_521 ) ;
V_629 = V_156 -> V_201 & V_634 ;
if ( V_629 ) {
if ( ! F_438 ( & V_635 ) )
goto V_257;
}
if ( F_390 ( V_164 , V_156 -> V_597 + V_519 ) ) {
if ( F_400 ( V_130 , V_24 , V_156 , V_349 , & V_564 ) ) {
V_349 = F_329 ( V_130 ) ? V_554 : V_506 ;
}
V_156 -> V_597 = V_164 ;
}
if ( V_629 )
F_163 ( & V_635 ) ;
V_257:
if ( F_170 ( V_589 , V_156 -> V_597 + V_519 ) ) {
V_589 = V_156 -> V_597 + V_519 ;
V_628 = 1 ;
}
}
if ( V_630 ) {
V_24 -> V_598 =
F_68 ( ( T_2 ) V_467 , V_631 ) ;
}
F_122 () ;
if ( F_12 ( V_628 ) )
V_24 -> V_589 = V_589 ;
}
static void F_439 ( struct V_24 * V_302 , enum V_505 V_349 )
{
int V_407 = V_302 -> V_130 ;
struct V_24 * V_24 ;
int V_563 ;
if ( V_349 != V_554 ||
! F_425 ( V_614 , F_422 ( V_407 ) ) )
goto V_238;
F_107 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_563 == V_407 || ! F_329 ( V_563 ) )
continue;
if ( F_440 () )
break;
V_24 = F_108 ( V_563 ) ;
F_412 ( & V_24 -> V_190 ) ;
F_276 ( V_24 ) ;
F_441 ( V_24 ) ;
F_415 ( & V_24 -> V_190 ) ;
F_437 ( V_24 , V_554 ) ;
if ( F_170 ( V_302 -> V_589 , V_24 -> V_589 ) )
V_302 -> V_589 = V_24 -> V_589 ;
}
V_610 . V_589 = V_302 -> V_589 ;
V_238:
F_427 ( V_614 , F_422 ( V_407 ) ) ;
}
static inline int F_442 ( struct V_24 * V_24 )
{
unsigned long V_81 = V_164 ;
struct V_155 * V_156 ;
struct V_524 * V_429 ;
int V_636 , V_130 = V_24 -> V_130 ;
if ( F_14 ( V_24 -> F_220 ) )
return 0 ;
F_428 () ;
F_424 ( V_130 ) ;
if ( F_12 ( ! F_207 ( & V_610 . V_616 ) ) )
return 0 ;
if ( F_173 ( V_81 , V_610 . V_589 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_637;
F_116 () ;
V_156 = F_126 ( F_127 ( V_617 , V_130 ) ) ;
if ( V_156 ) {
V_429 = V_156 -> V_420 -> V_429 ;
V_636 = F_207 ( & V_429 -> V_619 ) ;
if ( V_636 > 1 )
goto V_638;
}
V_156 = F_126 ( F_127 ( V_639 , V_130 ) ) ;
if ( V_156 && ( F_332 ( V_610 . V_611 ,
F_335 ( V_156 ) ) < V_130 ) )
goto V_638;
F_122 () ;
return 0 ;
V_638:
F_122 () ;
V_637:
return 1 ;
}
static void F_439 ( struct V_24 * V_302 , enum V_505 V_349 ) { }
static void F_443 ( struct V_640 * V_641 )
{
struct V_24 * V_302 = V_302 () ;
enum V_505 V_349 = V_302 -> F_220 ?
V_554 : V_506 ;
F_437 ( V_302 , V_349 ) ;
F_439 ( V_302 , V_349 ) ;
}
void F_444 ( struct V_24 * V_24 )
{
if ( F_14 ( F_416 ( V_24 ) ) )
return;
if ( F_390 ( V_164 , V_24 -> V_589 ) )
F_445 ( V_642 ) ;
#ifdef F_446
if ( F_442 ( V_24 ) )
F_420 () ;
#endif
}
static void F_447 ( struct V_24 * V_24 )
{
F_8 () ;
}
static void F_448 ( struct V_24 * V_24 )
{
F_8 () ;
F_301 ( V_24 ) ;
}
static void F_449 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_330 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_61 (se) {
V_25 = F_24 ( V_28 ) ;
F_247 ( V_25 , V_28 , V_330 ) ;
}
if ( V_221 )
F_183 ( V_24 , V_45 ) ;
F_208 ( V_24 , 1 ) ;
}
static void F_450 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_407 = F_260 () ;
struct V_24 * V_24 = V_302 () ;
unsigned long V_201 ;
F_366 ( & V_24 -> V_190 , V_201 ) ;
F_276 ( V_24 ) ;
V_25 = F_23 ( V_125 ) ;
V_45 = V_25 -> V_45 ;
F_116 () ;
F_451 ( V_29 , V_407 ) ;
F_122 () ;
F_65 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_230 ( V_25 , V_28 , 1 ) ;
if ( V_643 && V_45 && F_39 ( V_45 , V_28 ) ) {
F_121 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_241 ( V_24 -> V_45 ) ;
}
V_28 -> V_41 -= V_25 -> F_38 ;
F_367 ( & V_24 -> V_190 , V_201 ) ;
}
static void
F_452 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_644 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_645 > V_644 )
F_241 ( V_24 -> V_45 ) ;
} else
F_352 ( V_24 , V_29 , 0 ) ;
}
static void F_453 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_29 -> V_76 && V_29 -> V_222 != V_646 ) {
F_230 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_38 ;
}
#ifdef F_187
if ( V_28 -> V_77 . V_78 ) {
F_199 ( V_28 ) ;
F_211 ( V_25 , V_28 -> V_77 . V_286 ) ;
}
#endif
}
static void F_454 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
#ifdef F_343
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
if ( ! V_28 -> V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_241 ( V_24 -> V_45 ) ;
else
F_352 ( V_24 , V_29 , 0 ) ;
}
static void F_455 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_61 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_242 ( V_25 , V_28 ) ;
F_73 ( V_25 , 0 ) ;
}
}
void F_456 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_647 ;
V_25 -> F_38 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_42
V_25 -> V_48 = V_25 -> F_38 ;
#endif
#ifdef F_187
F_457 ( & V_25 -> V_285 , 1 ) ;
F_458 ( & V_25 -> V_299 , 0 ) ;
#endif
}
static void F_459 ( struct V_26 * V_29 , int V_76 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_28 -> V_85 || V_29 -> V_222 == V_648 ) )
V_76 = 1 ;
if ( ! V_76 )
V_28 -> V_41 -= F_24 ( V_28 ) -> F_38 ;
F_460 ( V_29 , F_125 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
if ( ! V_76 ) {
V_25 = F_24 ( V_28 ) ;
V_28 -> V_41 += V_25 -> F_38 ;
#ifdef F_187
V_28 -> V_77 . V_78 = F_200 ( & V_25 -> V_285 ) ;
V_25 -> V_290 += V_28 -> V_77 . V_286 ;
#endif
}
}
void F_461 ( struct V_261 * V_33 )
{
int V_191 ;
F_299 ( F_262 ( V_33 ) ) ;
F_462 (i) {
if ( V_33 -> V_25 )
F_168 ( V_33 -> V_25 [ V_191 ] ) ;
if ( V_33 -> V_28 )
F_168 ( V_33 -> V_28 [ V_191 ] ) ;
}
F_168 ( V_33 -> V_25 ) ;
F_168 ( V_33 -> V_28 ) ;
}
int F_463 ( struct V_261 * V_33 , struct V_261 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_191 ;
V_33 -> V_25 = F_153 ( sizeof( V_25 ) * V_612 , V_207 ) ;
if ( ! V_33 -> V_25 )
goto V_649;
V_33 -> V_28 = F_153 ( sizeof( V_28 ) * V_612 , V_207 ) ;
if ( ! V_33 -> V_28 )
goto V_649;
V_33 -> V_265 = V_71 ;
F_293 ( F_262 ( V_33 ) ) ;
F_462 (i) {
V_25 = F_464 ( sizeof( struct V_25 ) ,
V_207 , F_99 ( V_191 ) ) ;
if ( ! V_25 )
goto V_649;
V_28 = F_464 ( sizeof( struct V_27 ) ,
V_207 , F_99 ( V_191 ) ) ;
if ( ! V_28 )
goto V_650;
F_456 ( V_25 ) ;
F_465 ( V_33 , V_25 , V_28 , V_191 , V_34 -> V_28 [ V_191 ] ) ;
}
return 1 ;
V_650:
F_168 ( V_25 ) ;
V_649:
return 0 ;
}
void F_466 ( struct V_261 * V_33 , int V_130 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
unsigned long V_201 ;
if ( ! V_33 -> V_25 [ V_130 ] -> V_32 )
return;
F_366 ( & V_24 -> V_190 , V_201 ) ;
F_31 ( V_33 -> V_25 [ V_130 ] ) ;
F_367 ( & V_24 -> V_190 , V_201 ) ;
}
void F_465 ( struct V_261 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_130 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_108 ( V_130 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_296 ( V_25 ) ;
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
int F_467 ( struct V_261 * V_33 , unsigned long V_265 )
{
int V_191 ;
unsigned long V_201 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_160 ;
V_265 = F_140 ( V_265 , F_209 ( V_266 ) , F_209 ( V_651 ) ) ;
F_468 ( & V_652 ) ;
if ( V_33 -> V_265 == V_265 )
goto V_433;
V_33 -> V_265 = V_265 ;
F_462 (i) {
struct V_24 * V_24 = F_108 ( V_191 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_191 ] ;
F_366 ( & V_24 -> V_190 , V_201 ) ;
F_276 ( V_24 ) ;
F_61 (se)
F_194 ( F_25 ( V_28 ) ) ;
F_367 ( & V_24 -> V_190 , V_201 ) ;
}
V_433:
F_469 ( & V_652 ) ;
return 0 ;
}
void F_461 ( struct V_261 * V_33 ) { }
int F_463 ( struct V_261 * V_33 , struct V_261 * V_34 )
{
return 1 ;
}
void F_466 ( struct V_261 * V_33 , int V_130 ) { }
static unsigned int F_470 ( struct V_24 * V_24 , struct V_26 * V_653 )
{
struct V_27 * V_28 = & V_653 -> V_28 ;
unsigned int V_654 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_654 = F_471 ( F_60 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_654 ;
}
void F_472 ( struct V_655 * V_656 , int V_130 )
{
struct V_25 * V_25 ;
F_116 () ;
F_302 (cpu_rq(cpu), cfs_rq)
F_473 ( V_656 , V_130 , V_25 ) ;
F_122 () ;
}
T_12 void F_474 ( void )
{
#ifdef F_187
F_475 ( V_642 , F_443 ) ;
#ifdef F_446
V_610 . V_589 = V_164 ;
F_476 ( & V_610 . V_611 , V_657 ) ;
F_477 ( F_435 , 0 ) ;
#endif
#endif
}
