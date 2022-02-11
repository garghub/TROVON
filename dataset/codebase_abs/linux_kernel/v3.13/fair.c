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
static inline int
F_33 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
if ( V_28 -> V_25 == V_36 -> V_25 )
return 1 ;
return 0 ;
}
static inline struct V_27 * F_34 ( struct V_27 * V_28 )
{
return V_28 -> V_34 ;
}
static inline int F_35 ( struct V_27 * V_28 )
{
int V_37 = 0 ;
F_36 (se)
V_37 ++ ;
return V_37 ;
}
static void
F_37 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
int V_38 , V_39 ;
V_38 = F_35 ( * V_28 ) ;
V_39 = F_35 ( * V_36 ) ;
while ( V_38 > V_39 ) {
V_38 -- ;
* V_28 = F_34 ( * V_28 ) ;
}
while ( V_39 > V_38 ) {
V_39 -- ;
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
return & F_38 ( V_29 ) -> V_40 ;
}
static inline struct V_25 * F_24 ( struct V_27 * V_28 )
{
struct V_26 * V_29 = F_18 ( V_28 ) ;
struct V_24 * V_24 = F_38 ( V_29 ) ;
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
static inline int
F_33 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
return 1 ;
}
static inline struct V_27 * F_34 ( struct V_27 * V_28 )
{
return NULL ;
}
static inline void
F_37 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
}
static inline T_2 F_39 ( T_2 F_39 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_39 ) ;
if ( V_42 > 0 )
F_39 = V_41 ;
return F_39 ;
}
static inline T_2 F_40 ( T_2 F_40 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_40 ) ;
if ( V_42 < 0 )
F_40 = V_41 ;
return F_40 ;
}
static inline int F_41 ( struct V_27 * V_43 ,
struct V_27 * V_44 )
{
return ( T_3 ) ( V_43 -> V_41 - V_44 -> V_41 ) < 0 ;
}
static void F_42 ( struct V_25 * V_25 )
{
T_2 V_41 = V_25 -> F_40 ;
if ( V_25 -> V_45 )
V_41 = V_25 -> V_45 -> V_41 ;
if ( V_25 -> V_46 ) {
struct V_27 * V_28 = F_43 ( V_25 -> V_46 ,
struct V_27 ,
V_47 ) ;
if ( ! V_25 -> V_45 )
V_41 = V_28 -> V_41 ;
else
V_41 = F_40 ( V_41 , V_28 -> V_41 ) ;
}
V_25 -> F_40 = F_39 ( V_25 -> F_40 , V_41 ) ;
#ifndef F_44
F_45 () ;
V_25 -> V_48 = V_25 -> F_40 ;
#endif
}
static void F_46 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_49 * * V_50 = & V_25 -> V_51 . V_49 ;
struct V_49 * V_34 = NULL ;
struct V_27 * V_52 ;
int V_53 = 1 ;
while ( * V_50 ) {
V_34 = * V_50 ;
V_52 = F_43 ( V_34 , struct V_27 , V_47 ) ;
if ( F_41 ( V_28 , V_52 ) ) {
V_50 = & V_34 -> V_54 ;
} else {
V_50 = & V_34 -> V_55 ;
V_53 = 0 ;
}
}
if ( V_53 )
V_25 -> V_46 = & V_28 -> V_47 ;
F_47 ( & V_28 -> V_47 , V_34 , V_50 ) ;
F_48 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
static void F_49 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_46 == & V_28 -> V_47 ) {
struct V_49 * V_56 ;
V_56 = F_50 ( & V_28 -> V_47 ) ;
V_25 -> V_46 = V_56 ;
}
F_51 ( & V_28 -> V_47 , & V_25 -> V_51 ) ;
}
struct V_27 * F_52 ( struct V_25 * V_25 )
{
struct V_49 * V_57 = V_25 -> V_46 ;
if ( ! V_57 )
return NULL ;
return F_43 ( V_57 , struct V_27 , V_47 ) ;
}
static struct V_27 * F_53 ( struct V_27 * V_28 )
{
struct V_49 * V_58 = F_50 ( & V_28 -> V_47 ) ;
if ( ! V_58 )
return NULL ;
return F_43 ( V_58 , struct V_27 , V_47 ) ;
}
struct V_27 * F_54 ( struct V_25 * V_25 )
{
struct V_49 * V_59 = F_55 ( & V_25 -> V_51 ) ;
if ( ! V_59 )
return NULL ;
return F_43 ( V_59 , struct V_27 , V_47 ) ;
}
int F_56 ( struct V_60 * V_61 , int V_62 ,
void T_4 * V_63 , T_5 * V_64 ,
T_6 * V_65 )
{
int V_66 = F_57 ( V_61 , V_62 , V_63 , V_64 , V_65 ) ;
int V_9 = F_4 () ;
if ( V_66 || ! V_62 )
return V_66 ;
V_67 = F_58 ( V_68 ,
V_69 ) ;
#define F_59 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_59 ( V_14 ) ;
F_59 ( V_15 ) ;
F_59 ( V_16 ) ;
#undef F_59
return 0 ;
}
static inline T_2 F_60 ( T_2 V_42 , struct V_27 * V_28 )
{
if ( F_14 ( V_28 -> V_70 . V_4 != V_71 ) )
V_42 = F_15 ( V_42 , V_71 , & V_28 -> V_70 ) ;
return V_42 ;
}
static T_2 F_61 ( unsigned long V_72 )
{
T_2 V_73 = V_68 ;
unsigned long V_74 = V_67 ;
if ( F_14 ( V_72 > V_74 ) ) {
V_73 = V_69 ;
V_73 *= V_72 ;
}
return V_73 ;
}
static T_2 F_62 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_75 = F_61 ( V_25 -> V_72 + ! V_28 -> V_76 ) ;
F_36 (se) {
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
static T_2 F_63 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_60 ( F_62 ( V_25 , V_28 ) , V_28 ) ;
}
void F_64 ( struct V_26 * V_29 )
{
V_23 V_75 ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_75 = F_62 ( F_23 ( V_29 ) , & V_29 -> V_28 ) >> 10 ;
V_29 -> V_28 . V_77 . V_79 = V_75 ;
V_29 -> V_28 . V_77 . V_80 = V_75 ;
F_65 ( & V_29 -> V_28 ) ;
}
void F_64 ( struct V_26 * V_29 )
{
}
static void F_66 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_81 = F_67 ( F_17 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_14 ( ! V_45 ) )
return;
V_19 = V_81 - V_45 -> V_82 ;
if ( F_14 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_82 = V_81 ;
F_68 ( V_45 -> V_83 . V_84 ,
F_69 ( V_19 , V_45 -> V_83 . V_84 ) ) ;
V_45 -> V_85 += V_19 ;
F_70 ( V_25 , V_86 , V_19 ) ;
V_45 -> V_41 += F_60 ( V_19 , V_45 ) ;
F_42 ( V_25 ) ;
if ( F_21 ( V_45 ) ) {
struct V_26 * V_87 = F_18 ( V_45 ) ;
F_71 ( V_87 , V_19 , V_45 -> V_41 ) ;
F_72 ( V_87 , V_19 ) ;
F_73 ( V_87 , V_19 ) ;
}
F_74 ( V_25 , V_19 ) ;
}
static inline void
F_75 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_68 ( V_28 -> V_83 . V_88 , F_76 ( F_17 ( V_25 ) ) ) ;
}
static void F_77 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_75 ( V_25 , V_28 ) ;
}
static void
F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_68 ( V_28 -> V_83 . V_89 , F_69 ( V_28 -> V_83 . V_89 ,
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ) ;
F_68 ( V_28 -> V_83 . V_90 , V_28 -> V_83 . V_90 + 1 ) ;
F_68 ( V_28 -> V_83 . V_91 , V_28 -> V_83 . V_91 +
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
#ifdef F_79
if ( F_21 ( V_28 ) ) {
F_80 ( F_18 ( V_28 ) ,
F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_88 ) ;
}
#endif
F_68 ( V_28 -> V_83 . V_88 , 0 ) ;
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
V_28 -> V_82 = F_67 ( F_17 ( V_25 ) ) ;
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
unsigned int V_97 , floor ;
unsigned int V_98 = 1 ;
if ( V_94 < V_99 )
V_98 = V_99 / V_94 ;
floor = 1000 / V_98 ;
V_97 = V_100 / F_83 ( V_29 ) ;
return F_87 (unsigned int, floor, scan) ;
}
static unsigned int F_88 ( struct V_26 * V_29 )
{
unsigned int V_101 = F_86 ( V_29 ) ;
unsigned int V_102 ;
V_102 = V_103 / F_83 ( V_29 ) ;
return F_69 ( V_101 , V_102 ) ;
}
static void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 += ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 += ( V_29 -> V_105 == F_90 ( V_29 ) ) ;
}
static void F_91 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_104 -= ( V_29 -> V_105 != - 1 ) ;
V_24 -> V_106 -= ( V_29 -> V_105 == F_90 ( V_29 ) ) ;
}
T_7 F_92 ( struct V_26 * V_29 )
{
return V_29 -> V_107 ? V_29 -> V_107 -> V_108 : 0 ;
}
static inline int F_93 ( int V_109 , int V_110 )
{
return 2 * V_109 + V_110 ;
}
static inline unsigned long F_94 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_111 )
return 0 ;
return V_29 -> V_111 [ F_93 ( V_109 , 0 ) ] +
V_29 -> V_111 [ F_93 ( V_109 , 1 ) ] ;
}
static inline unsigned long F_95 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_107 )
return 0 ;
return V_29 -> V_107 -> V_112 [ 2 * V_109 ] + V_29 -> V_107 -> V_112 [ 2 * V_109 + 1 ] ;
}
static inline unsigned long F_96 ( struct V_26 * V_29 , int V_109 )
{
unsigned long V_113 ;
if ( ! V_29 -> V_111 )
return 0 ;
V_113 = V_29 -> V_114 ;
if ( ! V_113 )
return 0 ;
return 1000 * F_94 ( V_29 , V_109 ) / V_113 ;
}
static inline unsigned long F_97 ( struct V_26 * V_29 , int V_109 )
{
if ( ! V_29 -> V_107 || ! V_29 -> V_107 -> V_113 )
return 0 ;
return 1000 * F_95 ( V_29 , V_109 ) / V_29 -> V_107 -> V_113 ;
}
static void F_98 ( struct V_115 * V_116 , int V_109 )
{
int V_117 , V_8 = 0 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
F_99 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_100 ( V_117 ) ;
V_116 -> V_72 += V_24 -> V_72 ;
V_116 -> V_70 += F_101 ( V_117 ) ;
V_116 -> V_118 += F_102 ( V_117 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_116 -> V_70 = ( V_116 -> V_70 * V_119 ) / V_116 -> V_118 ;
V_116 -> V_120 = F_103 ( V_116 -> V_118 , V_119 ) ;
V_116 -> V_121 = ( V_116 -> V_72 < V_116 -> V_120 ) ;
}
static void F_104 ( struct V_122 * V_123 ,
struct V_26 * V_29 , long V_124 )
{
if ( V_123 -> V_125 )
F_105 ( V_123 -> V_125 ) ;
if ( V_29 )
F_106 ( V_29 ) ;
V_123 -> V_125 = V_29 ;
V_123 -> V_126 = V_124 ;
V_123 -> V_127 = V_123 -> V_128 ;
}
static void F_107 ( struct V_122 * V_123 ,
long V_129 , long V_130 )
{
struct V_24 * V_131 = F_100 ( V_123 -> V_132 ) ;
struct V_24 * V_133 = F_100 ( V_123 -> V_128 ) ;
struct V_26 * V_134 ;
long V_135 , V_136 ;
long V_70 ;
long V_124 = ( V_130 > 0 ) ? V_130 : V_129 ;
F_108 () ;
V_134 = F_109 ( V_133 -> V_45 ) ;
if ( V_134 -> V_137 == 0 )
V_134 = NULL ;
if ( V_134 ) {
if ( ! F_110 ( V_123 -> V_132 , F_111 ( V_134 ) ) )
goto V_138;
if ( V_134 -> V_107 == V_123 -> V_29 -> V_107 ) {
V_124 = V_129 + F_96 ( V_134 , V_123 -> V_139 ) -
F_96 ( V_134 , V_123 -> V_140 ) ;
if ( V_134 -> V_107 )
V_124 -= V_124 / 16 ;
} else {
if ( V_123 -> V_29 -> V_107 )
V_124 = V_130 ;
else
V_124 = V_129 ;
if ( V_134 -> V_107 )
V_124 += F_97 ( V_134 , V_123 -> V_139 ) -
F_97 ( V_134 , V_123 -> V_140 ) ;
else
V_124 += F_96 ( V_134 , V_123 -> V_139 ) -
F_96 ( V_134 , V_123 -> V_140 ) ;
}
}
if ( V_124 < V_123 -> V_126 )
goto V_138;
if ( ! V_134 ) {
if ( V_123 -> V_141 . V_121 &&
! V_123 -> V_142 . V_121 )
goto V_138;
goto V_143;
}
if ( V_131 -> V_72 == 1 && V_133 -> V_72 == 1 )
goto V_144;
V_143:
V_135 = V_123 -> V_142 . V_70 ;
V_136 = V_123 -> V_141 . V_70 ;
V_70 = F_112 ( V_123 -> V_29 ) ;
V_135 += V_70 ;
V_136 -= V_70 ;
if ( V_134 ) {
V_70 = F_112 ( V_134 ) ;
V_135 -= V_70 ;
V_136 += V_70 ;
}
if ( V_135 < V_136 )
F_113 ( V_135 , V_136 ) ;
if ( V_136 * V_123 -> V_145 < V_135 * 100 )
goto V_138;
V_144:
F_104 ( V_123 , V_134 , V_124 ) ;
V_138:
F_114 () ;
}
static void F_115 ( struct V_122 * V_123 ,
long V_129 , long V_130 )
{
int V_117 ;
F_99 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_110 ( V_117 , F_111 ( V_123 -> V_29 ) ) )
continue;
V_123 -> V_128 = V_117 ;
F_107 ( V_123 , V_129 , V_130 ) ;
}
}
static int F_116 ( struct V_26 * V_29 )
{
struct V_122 V_123 = {
. V_29 = V_29 ,
. V_132 = F_117 ( V_29 ) ,
. V_139 = F_90 ( V_29 ) ,
. V_145 = 112 ,
. V_125 = NULL ,
. V_126 = 0 ,
. V_127 = - 1
} ;
struct V_146 * V_147 ;
unsigned long V_148 , V_149 ;
int V_109 , V_66 ;
long V_129 , V_130 ;
F_108 () ;
V_147 = F_118 ( F_119 ( V_150 , V_123 . V_132 ) ) ;
if ( V_147 )
V_123 . V_145 = 100 + ( V_147 -> V_145 - 100 ) / 2 ;
F_114 () ;
if ( F_14 ( ! V_147 ) ) {
V_29 -> V_105 = F_120 ( F_117 ( V_29 ) ) ;
return - V_151 ;
}
V_148 = F_96 ( V_29 , V_123 . V_139 ) ;
V_149 = F_97 ( V_29 , V_123 . V_139 ) ;
F_98 ( & V_123 . V_141 , V_123 . V_139 ) ;
V_123 . V_140 = V_29 -> V_105 ;
V_129 = F_96 ( V_29 , V_123 . V_140 ) - V_148 ;
V_130 = F_97 ( V_29 , V_123 . V_140 ) - V_149 ;
F_98 ( & V_123 . V_142 , V_123 . V_140 ) ;
if ( V_123 . V_142 . V_121 )
F_115 ( & V_123 , V_129 , V_130 ) ;
if ( V_123 . V_127 == - 1 ) {
F_121 (nid) {
if ( V_109 == V_123 . V_139 || V_109 == V_29 -> V_105 )
continue;
V_129 = F_96 ( V_29 , V_109 ) - V_148 ;
V_130 = F_97 ( V_29 , V_109 ) - V_149 ;
if ( V_129 < 0 && V_130 < 0 )
continue;
V_123 . V_140 = V_109 ;
F_98 ( & V_123 . V_142 , V_123 . V_140 ) ;
F_115 ( & V_123 , V_129 , V_130 ) ;
}
}
if ( V_123 . V_127 == - 1 )
return - V_152 ;
F_122 ( V_29 , V_123 . V_140 ) ;
V_29 -> V_153 = F_86 ( V_29 ) ;
if ( V_123 . V_125 == NULL ) {
int V_66 = F_123 ( V_29 , V_123 . V_127 ) ;
return V_66 ;
}
V_66 = F_124 ( V_29 , V_123 . V_125 ) ;
F_105 ( V_123 . V_125 ) ;
return V_66 ;
}
static void F_125 ( struct V_26 * V_29 )
{
if ( F_14 ( V_29 -> V_105 == - 1 || ! V_29 -> V_111 ) )
return;
V_29 -> V_154 = V_155 + V_156 ;
if ( F_120 ( F_117 ( V_29 ) ) == V_29 -> V_105 )
return;
F_116 ( V_29 ) ;
}
static void F_126 ( struct V_26 * V_29 ,
unsigned long V_157 , unsigned long V_158 )
{
unsigned int V_159 ;
int V_160 ;
int V_161 ;
unsigned long V_162 = V_29 -> V_163 [ 0 ] ;
unsigned long V_164 = V_29 -> V_163 [ 1 ] ;
if ( V_164 + V_157 == 0 ) {
V_29 -> V_153 = F_127 ( V_29 -> V_165 ,
V_29 -> V_153 << 1 ) ;
V_29 -> V_96 -> V_166 = V_155 +
F_128 ( V_29 -> V_153 ) ;
return;
}
V_159 = F_58 ( V_29 -> V_153 , V_167 ) ;
V_160 = ( V_164 * V_167 ) / ( V_164 + V_162 ) ;
if ( V_160 >= V_168 ) {
int V_169 = V_160 - V_168 ;
if ( ! V_169 )
V_169 = 1 ;
V_161 = V_169 * V_159 ;
} else {
V_161 = - ( V_168 - V_160 ) * V_159 ;
V_159 = F_58 ( V_161 , V_167 ) ;
V_160 = F_58 ( V_158 * V_167 , ( V_158 + V_157 ) ) ;
V_161 = ( V_161 * V_160 ) / V_167 ;
}
V_29 -> V_153 = F_129 ( V_29 -> V_153 + V_161 ,
F_86 ( V_29 ) , F_88 ( V_29 ) ) ;
memset ( V_29 -> V_163 , 0 , sizeof( V_29 -> V_163 ) ) ;
}
static void F_130 ( struct V_26 * V_29 )
{
int V_170 , V_109 , V_171 = - 1 , V_172 = - 1 ;
unsigned long V_173 = 0 , V_174 = 0 ;
unsigned long V_175 [ 2 ] = { 0 , 0 } ;
T_8 * V_176 = NULL ;
V_170 = F_109 ( V_29 -> V_96 -> V_177 ) ;
if ( V_29 -> V_177 == V_170 )
return;
V_29 -> V_177 = V_170 ;
V_29 -> V_165 = F_88 ( V_29 ) ;
if ( V_29 -> V_107 ) {
V_176 = & V_29 -> V_107 -> V_178 ;
F_131 ( V_176 ) ;
}
F_121 (nid) {
unsigned long V_112 = 0 , F_95 = 0 ;
int V_110 , V_179 ;
for ( V_110 = 0 ; V_110 < 2 ; V_110 ++ ) {
long V_161 ;
V_179 = F_93 ( V_109 , V_110 ) ;
V_161 = - V_29 -> V_111 [ V_179 ] ;
V_29 -> V_111 [ V_179 ] >>= 1 ;
V_29 -> V_111 [ V_179 ] += V_29 -> V_180 [ V_179 ] ;
V_175 [ V_110 ] += V_29 -> V_180 [ V_179 ] ;
V_29 -> V_180 [ V_179 ] = 0 ;
V_112 += V_29 -> V_111 [ V_179 ] ;
V_161 += V_29 -> V_111 [ V_179 ] ;
V_29 -> V_114 += V_161 ;
if ( V_29 -> V_107 ) {
V_29 -> V_107 -> V_112 [ V_179 ] += V_161 ;
V_29 -> V_107 -> V_113 += V_161 ;
F_95 += V_29 -> V_107 -> V_112 [ V_179 ] ;
}
}
if ( V_112 > V_173 ) {
V_173 = V_112 ;
V_171 = V_109 ;
}
if ( F_95 > V_174 ) {
V_174 = F_95 ;
V_172 = V_109 ;
}
}
F_126 ( V_29 , V_175 [ 0 ] , V_175 [ 1 ] ) ;
if ( V_29 -> V_107 ) {
if ( V_171 != V_172 ) {
unsigned long V_4 , V_181 = 0 ;
F_121 (nid) {
V_4 = F_96 ( V_29 , V_109 ) + F_97 ( V_29 , V_109 ) ;
if ( V_4 > V_181 ) {
V_181 = V_4 ;
V_171 = V_109 ;
}
}
}
F_132 ( V_176 ) ;
}
if ( V_173 && V_171 != V_29 -> V_105 ) {
F_122 ( V_29 , V_171 ) ;
F_125 ( V_29 ) ;
}
}
static inline int F_133 ( struct V_107 * V_30 )
{
return F_134 ( & V_30 -> V_182 ) ;
}
static inline void F_135 ( struct V_107 * V_30 )
{
if ( F_136 ( & V_30 -> V_182 ) )
F_137 ( V_30 , V_183 ) ;
}
static void F_138 ( struct V_26 * V_29 , int V_184 , int V_185 ,
int * V_110 )
{
struct V_107 * V_30 , * V_186 ;
struct V_26 * V_187 ;
bool V_188 = false ;
int V_117 = F_139 ( V_184 ) ;
int V_179 ;
if ( F_14 ( ! V_29 -> V_107 ) ) {
unsigned int V_189 = sizeof( struct V_107 ) +
2 * V_190 *sizeof( unsigned long ) ;
V_30 = F_140 ( V_189 , V_191 | V_192 ) ;
if ( ! V_30 )
return;
F_141 ( & V_30 -> V_182 , 1 ) ;
F_142 ( & V_30 -> V_178 ) ;
F_143 ( & V_30 -> V_193 ) ;
V_30 -> V_108 = V_29 -> V_137 ;
for ( V_179 = 0 ; V_179 < 2 * V_190 ; V_179 ++ )
V_30 -> V_112 [ V_179 ] = V_29 -> V_111 [ V_179 ] ;
V_30 -> V_113 = V_29 -> V_114 ;
F_144 ( & V_29 -> V_194 , & V_30 -> V_193 ) ;
V_30 -> V_195 ++ ;
F_145 ( V_29 -> V_107 , V_30 ) ;
}
F_108 () ;
V_187 = F_109 ( F_100 ( V_117 ) -> V_45 ) ;
if ( ! F_146 ( V_187 , V_184 ) )
goto V_196;
V_30 = F_118 ( V_187 -> V_107 ) ;
if ( ! V_30 )
goto V_196;
V_186 = V_29 -> V_107 ;
if ( V_30 == V_186 )
goto V_196;
if ( V_186 -> V_195 > V_30 -> V_195 )
goto V_196;
if ( V_186 -> V_195 == V_30 -> V_195 && V_186 > V_30 )
goto V_196;
if ( V_187 -> V_96 == V_197 -> V_96 )
V_188 = true ;
if ( V_185 & V_198 )
V_188 = true ;
* V_110 = ! V_188 ;
if ( V_188 && ! F_133 ( V_30 ) )
goto V_196;
F_114 () ;
if ( ! V_188 )
return;
F_147 ( & V_186 -> V_178 , & V_30 -> V_178 ) ;
for ( V_179 = 0 ; V_179 < 2 * V_190 ; V_179 ++ ) {
V_186 -> V_112 [ V_179 ] -= V_29 -> V_111 [ V_179 ] ;
V_30 -> V_112 [ V_179 ] += V_29 -> V_111 [ V_179 ] ;
}
V_186 -> V_113 -= V_29 -> V_114 ;
V_30 -> V_113 += V_29 -> V_114 ;
F_148 ( & V_29 -> V_194 , & V_30 -> V_193 ) ;
V_186 -> V_195 -- ;
V_30 -> V_195 ++ ;
F_132 ( & V_186 -> V_178 ) ;
F_132 ( & V_30 -> V_178 ) ;
F_145 ( V_29 -> V_107 , V_30 ) ;
F_135 ( V_186 ) ;
return;
V_196:
F_114 () ;
return;
}
void F_149 ( struct V_26 * V_29 )
{
struct V_107 * V_30 = V_29 -> V_107 ;
int V_179 ;
void * V_111 = V_29 -> V_111 ;
if ( V_30 ) {
F_131 ( & V_30 -> V_178 ) ;
for ( V_179 = 0 ; V_179 < 2 * V_190 ; V_179 ++ )
V_30 -> V_112 [ V_179 ] -= V_29 -> V_111 [ V_179 ] ;
V_30 -> V_113 -= V_29 -> V_114 ;
F_150 ( & V_29 -> V_194 ) ;
V_30 -> V_195 -- ;
F_132 ( & V_30 -> V_178 ) ;
F_145 ( V_29 -> V_107 , NULL ) ;
F_135 ( V_30 ) ;
}
V_29 -> V_111 = NULL ;
V_29 -> V_180 = NULL ;
F_151 ( V_111 ) ;
}
void F_152 ( int V_199 , int V_200 , int V_201 , int V_185 )
{
struct V_26 * V_29 = V_197 ;
bool V_202 = V_185 & V_203 ;
int V_110 ;
if ( ! V_204 )
return;
if ( ! V_29 -> V_96 )
return;
if ( V_29 -> V_205 == V_206 )
return;
if ( F_14 ( ! V_29 -> V_111 ) ) {
int V_189 = sizeof( * V_29 -> V_111 ) * 2 * V_190 ;
V_29 -> V_111 = F_140 ( V_189 * 2 , V_191 | V_192 ) ;
if ( ! V_29 -> V_111 )
return;
F_153 ( V_29 -> V_180 ) ;
V_29 -> V_180 = V_29 -> V_111 + ( 2 * V_190 ) ;
V_29 -> V_114 = 0 ;
memset ( V_29 -> V_163 , 0 , sizeof( V_29 -> V_163 ) ) ;
}
if ( F_14 ( V_199 == ( - 1 & V_207 ) ) ) {
V_110 = 1 ;
} else {
V_110 = F_146 ( V_29 , V_199 ) ;
if ( ! V_110 && ! ( V_185 & V_208 ) )
F_138 ( V_29 , V_199 , V_185 , & V_110 ) ;
}
F_130 ( V_29 ) ;
if ( F_154 ( V_155 , V_29 -> V_154 ) )
F_125 ( V_29 ) ;
if ( V_202 )
V_29 -> V_209 += V_201 ;
V_29 -> V_180 [ F_93 ( V_200 , V_110 ) ] += V_201 ;
V_29 -> V_163 [ ! ! ( V_185 & V_210 ) ] += V_201 ;
}
static void F_155 ( struct V_26 * V_29 )
{
F_109 ( V_29 -> V_96 -> V_177 ) ++ ;
V_29 -> V_96 -> V_211 = 0 ;
}
void F_156 ( struct V_212 * V_213 )
{
unsigned long V_214 , V_215 , V_81 = V_155 ;
struct V_26 * V_29 = V_197 ;
struct V_216 * V_96 = V_29 -> V_96 ;
struct V_217 * V_218 ;
unsigned long V_219 , V_220 ;
unsigned long V_221 = 0 ;
long V_201 ;
F_20 ( V_29 != F_22 ( V_213 , struct V_26 , V_222 ) ) ;
V_213 -> V_58 = V_213 ;
if ( V_29 -> V_185 & V_223 )
return;
if ( ! V_96 -> V_166 ) {
V_96 -> V_166 = V_81 +
F_128 ( V_224 ) ;
}
V_214 = V_96 -> V_166 ;
if ( F_157 ( V_81 , V_214 ) )
return;
if ( V_29 -> V_153 == 0 ) {
V_29 -> V_165 = F_88 ( V_29 ) ;
V_29 -> V_153 = F_86 ( V_29 ) ;
}
V_215 = V_81 + F_128 ( V_29 -> V_153 ) ;
if ( F_158 ( & V_96 -> V_166 , V_214 , V_215 ) != V_214 )
return;
V_29 -> V_225 += 2 * V_226 ;
V_219 = V_96 -> V_211 ;
V_201 = V_94 ;
V_201 <<= 20 - V_95 ;
if ( ! V_201 )
return;
F_159 ( & V_96 -> V_227 ) ;
V_218 = F_160 ( V_96 , V_219 ) ;
if ( ! V_218 ) {
F_155 ( V_29 ) ;
V_219 = 0 ;
V_218 = V_96 -> V_228 ;
}
for (; V_218 ; V_218 = V_218 -> V_229 ) {
if ( ! F_161 ( V_218 ) || ! F_162 ( V_29 , V_218 ) )
continue;
if ( ! V_218 -> V_230 ||
( V_218 -> V_231 && ( V_218 -> V_232 & ( V_233 | V_234 ) ) == ( V_233 ) ) )
continue;
if ( ! ( V_218 -> V_232 & ( V_233 | V_235 | V_234 ) ) )
continue;
do {
V_219 = F_69 ( V_219 , V_218 -> V_236 ) ;
V_220 = F_163 ( V_219 + ( V_201 << V_95 ) , V_237 ) ;
V_220 = F_127 ( V_220 , V_218 -> V_238 ) ;
V_221 += F_164 ( V_218 , V_219 , V_220 ) ;
if ( V_221 )
V_201 -= ( V_220 - V_219 ) >> V_95 ;
V_219 = V_220 ;
if ( V_201 <= 0 )
goto V_239;
} while ( V_220 != V_218 -> V_238 );
}
V_239:
if ( V_218 )
V_96 -> V_211 = V_219 ;
else
F_155 ( V_29 ) ;
F_165 ( & V_96 -> V_227 ) ;
}
void F_166 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_212 * V_213 = & V_45 -> V_222 ;
T_2 V_73 , V_81 ;
if ( ! V_45 -> V_96 || ( V_45 -> V_185 & V_223 ) || V_213 -> V_58 != V_213 )
return;
V_81 = V_45 -> V_28 . V_85 ;
V_73 = ( T_2 ) V_45 -> V_153 * V_240 ;
if ( V_81 - V_45 -> V_225 > V_73 ) {
if ( ! V_45 -> V_225 )
V_45 -> V_153 = F_86 ( V_45 ) ;
V_45 -> V_225 += V_73 ;
if ( ! F_157 ( V_155 , V_45 -> V_96 -> V_166 ) ) {
F_167 ( V_213 , F_156 ) ;
F_168 ( V_45 , V_213 , true ) ;
}
}
}
static void F_166 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_89 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_91 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_169 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_170
if ( F_21 ( V_28 ) ) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_89 ( V_24 , F_18 ( V_28 ) ) ;
F_144 ( & V_28 -> V_241 , & V_24 -> V_242 ) ;
}
#endif
V_25 -> V_72 ++ ;
}
static void
F_171 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) ) {
F_91 ( F_17 ( V_25 ) , F_18 ( V_28 ) ) ;
F_172 ( & V_28 -> V_241 ) ;
}
V_25 -> V_72 -- ;
}
static inline long F_173 ( struct V_243 * V_33 , struct V_25 * V_25 )
{
long V_244 ;
V_244 = F_174 ( & V_33 -> V_245 ) ;
V_244 -= V_25 -> V_246 ;
V_244 += V_25 -> V_70 . V_4 ;
return V_244 ;
}
static long F_175 ( struct V_25 * V_25 , struct V_243 * V_33 )
{
long V_244 , V_70 , V_247 ;
V_244 = F_173 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_247 = ( V_33 -> V_247 * V_70 ) ;
if ( V_244 )
V_247 /= V_244 ;
if ( V_247 < V_248 )
V_247 = V_248 ;
if ( V_247 > V_33 -> V_247 )
V_247 = V_33 -> V_247 ;
return V_247 ;
}
static inline long F_175 ( struct V_25 * V_25 , struct V_243 * V_33 )
{
return V_33 -> V_247 ;
}
static void F_176 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_66 ( V_25 ) ;
F_171 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_169 ( V_25 , V_28 ) ;
}
static void F_177 ( struct V_25 * V_25 )
{
struct V_243 * V_33 ;
struct V_27 * V_28 ;
long V_247 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_178 ( V_25 ) )
return;
#ifndef F_170
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_247 ) )
return;
#endif
V_247 = F_175 ( V_25 , V_33 ) ;
F_176 ( F_24 ( V_28 ) , V_28 , V_247 ) ;
}
static inline void F_177 ( struct V_25 * V_25 )
{
}
static T_9 T_2 F_179 ( T_2 V_249 , T_2 V_250 )
{
unsigned int V_251 ;
if ( ! V_250 )
return V_249 ;
else if ( F_14 ( V_250 > V_252 * 63 ) )
return 0 ;
V_251 = V_250 ;
if ( F_14 ( V_251 >= V_252 ) ) {
V_249 >>= V_251 / V_252 ;
V_251 %= V_252 ;
}
V_249 *= V_253 [ V_251 ] ;
return V_249 >> 32 ;
}
static V_23 F_180 ( T_2 V_250 )
{
V_23 V_254 = 0 ;
if ( F_12 ( V_250 <= V_252 ) )
return V_255 [ V_250 ] ;
else if ( F_14 ( V_250 >= V_256 ) )
return V_257 ;
do {
V_254 /= 2 ;
V_254 += V_255 [ V_252 ] ;
V_250 -= V_252 ;
} while ( V_250 > V_252 );
V_254 = F_179 ( V_254 , V_250 ) ;
return V_254 + V_255 [ V_250 ] ;
}
static T_9 int F_181 ( T_2 V_81 ,
struct V_258 * V_259 ,
int V_260 )
{
T_2 V_42 , V_261 ;
V_23 V_262 ;
int V_263 , V_264 = 0 ;
V_42 = V_81 - V_259 -> V_265 ;
if ( ( T_3 ) V_42 < 0 ) {
V_259 -> V_265 = V_81 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_259 -> V_265 = V_81 ;
V_263 = V_259 -> V_80 % 1024 ;
if ( V_42 + V_263 >= 1024 ) {
V_264 = 1 ;
V_263 = 1024 - V_263 ;
if ( V_260 )
V_259 -> V_79 += V_263 ;
V_259 -> V_80 += V_263 ;
V_42 -= V_263 ;
V_261 = V_42 / 1024 ;
V_42 %= 1024 ;
V_259 -> V_79 = F_179 ( V_259 -> V_79 ,
V_261 + 1 ) ;
V_259 -> V_80 = F_179 ( V_259 -> V_80 ,
V_261 + 1 ) ;
V_262 = F_180 ( V_261 ) ;
if ( V_260 )
V_259 -> V_79 += V_262 ;
V_259 -> V_80 += V_262 ;
}
if ( V_260 )
V_259 -> V_79 += V_42 ;
V_259 -> V_80 += V_42 ;
return V_264 ;
}
static inline T_2 F_182 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_266 = F_183 ( & V_25 -> V_267 ) ;
V_266 -= V_28 -> V_77 . V_78 ;
if ( ! V_266 )
return 0 ;
V_28 -> V_77 . V_268 = F_179 ( V_28 -> V_77 . V_268 , V_266 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_266 ;
}
static inline void F_184 ( struct V_25 * V_25 ,
int V_269 )
{
struct V_243 * V_33 = V_25 -> V_33 ;
long V_270 ;
V_270 = V_25 -> V_271 + V_25 -> V_272 ;
V_270 -= V_25 -> V_246 ;
if ( V_269 || abs ( V_270 ) > V_25 -> V_246 / 8 ) {
F_185 ( V_270 , & V_33 -> V_245 ) ;
V_25 -> V_246 += V_270 ;
}
}
static inline void F_186 ( struct V_258 * V_259 ,
struct V_25 * V_25 )
{
struct V_243 * V_33 = V_25 -> V_33 ;
long V_254 ;
V_254 = F_187 ( ( T_2 ) V_259 -> V_79 << V_273 ,
V_259 -> V_80 + 1 ) ;
V_254 -= V_25 -> V_274 ;
if ( abs ( V_254 ) > V_25 -> V_274 / 64 ) {
F_188 ( V_254 , & V_33 -> V_275 ) ;
V_25 -> V_274 += V_254 ;
}
}
static inline void F_189 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_243 * V_33 = V_25 -> V_33 ;
int V_275 ;
T_2 V_254 ;
V_254 = V_25 -> V_246 * V_33 -> V_247 ;
V_28 -> V_77 . V_268 = F_187 ( V_254 ,
F_174 ( & V_33 -> V_245 ) + 1 ) ;
V_275 = F_190 ( & V_33 -> V_275 ) ;
if ( V_275 < V_71 ) {
V_28 -> V_77 . V_268 *= V_275 ;
V_28 -> V_77 . V_268 >>= V_273 ;
}
}
static inline void F_184 ( struct V_25 * V_25 ,
int V_269 ) {}
static inline void F_186 ( struct V_258 * V_259 ,
struct V_25 * V_25 ) {}
static inline void F_189 ( struct V_27 * V_28 ) {}
static inline void F_65 ( struct V_27 * V_28 )
{
V_23 V_254 ;
V_254 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_254 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_268 = F_191 ( V_254 ) ;
}
static long F_192 ( struct V_27 * V_28 )
{
long V_276 = V_28 -> V_77 . V_268 ;
if ( F_21 ( V_28 ) ) {
F_65 ( V_28 ) ;
} else {
F_186 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_189 ( V_28 ) ;
}
return V_28 -> V_77 . V_268 - V_276 ;
}
static inline void F_193 ( struct V_25 * V_25 ,
long V_277 )
{
if ( F_12 ( V_277 < V_25 -> V_272 ) )
V_25 -> V_272 -= V_277 ;
else
V_25 -> V_272 = 0 ;
}
static inline void F_194 ( struct V_27 * V_28 ,
int V_278 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_279 ;
T_2 V_81 ;
if ( F_21 ( V_28 ) )
V_81 = F_195 ( V_25 ) ;
else
V_81 = F_195 ( F_25 ( V_28 ) ) ;
if ( ! F_181 ( V_81 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_279 = F_192 ( V_28 ) ;
if ( ! V_278 )
return;
if ( V_28 -> V_76 )
V_25 -> V_271 += V_279 ;
else
F_193 ( V_25 , - V_279 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_269 )
{
T_2 V_81 = F_195 ( V_25 ) >> 20 ;
T_2 V_266 ;
V_266 = V_81 - V_25 -> V_280 ;
if ( ! V_266 && ! V_269 )
return;
if ( F_174 ( & V_25 -> V_281 ) ) {
unsigned long V_281 ;
V_281 = F_196 ( & V_25 -> V_281 , 0 ) ;
F_193 ( V_25 , V_281 ) ;
}
if ( V_266 ) {
V_25 -> V_272 = F_179 ( V_25 -> V_272 ,
V_266 ) ;
F_197 ( V_266 , & V_25 -> V_267 ) ;
V_25 -> V_280 = V_81 ;
}
F_184 ( V_25 , V_269 ) ;
}
static inline void F_198 ( struct V_24 * V_24 , int V_260 )
{
F_181 ( F_67 ( V_24 ) , & V_24 -> V_77 , V_260 ) ;
F_186 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_199 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_282 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_265 = F_67 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_265 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_194 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_282 = 0 ;
} else {
V_28 -> V_77 . V_265 += F_182 ( V_28 )
<< 20 ;
}
if ( V_282 ) {
F_193 ( V_25 , V_28 -> V_77 . V_268 ) ;
F_194 ( V_28 , 0 ) ;
}
V_25 -> V_271 += V_28 -> V_77 . V_268 ;
F_30 ( V_25 , ! V_282 ) ;
}
static inline void F_200 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_283 )
{
F_194 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_283 ) ;
V_25 -> V_271 -= V_28 -> V_77 . V_268 ;
if ( V_283 ) {
V_25 -> V_272 += V_28 -> V_77 . V_268 ;
V_28 -> V_77 . V_78 = F_183 ( & V_25 -> V_267 ) ;
}
}
void F_201 ( struct V_24 * V_284 )
{
F_198 ( V_284 , 1 ) ;
}
void F_202 ( struct V_24 * V_284 )
{
F_198 ( V_284 , 0 ) ;
}
static inline void F_194 ( struct V_27 * V_28 ,
int V_278 ) {}
static inline void F_198 ( struct V_24 * V_24 , int V_260 ) {}
static inline void F_199 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_282 ) {}
static inline void F_200 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_283 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_269 ) {}
static void F_203 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_79
struct V_26 * V_187 = NULL ;
if ( F_21 ( V_28 ) )
V_187 = F_18 ( V_28 ) ;
if ( V_28 -> V_83 . V_285 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_285 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_286 ) )
V_28 -> V_83 . V_286 = V_42 ;
V_28 -> V_83 . V_285 = 0 ;
V_28 -> V_83 . V_287 += V_42 ;
if ( V_187 ) {
F_204 ( V_187 , V_42 >> 10 , 1 ) ;
F_205 ( V_187 , V_42 ) ;
}
}
if ( V_28 -> V_83 . V_288 ) {
T_2 V_42 = F_76 ( F_17 ( V_25 ) ) - V_28 -> V_83 . V_288 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_83 . V_289 ) )
V_28 -> V_83 . V_289 = V_42 ;
V_28 -> V_83 . V_288 = 0 ;
V_28 -> V_83 . V_287 += V_42 ;
if ( V_187 ) {
if ( V_187 -> V_290 ) {
V_28 -> V_83 . V_291 += V_42 ;
V_28 -> V_83 . V_292 ++ ;
F_206 ( V_187 , V_42 ) ;
}
F_207 ( V_187 , V_42 ) ;
if ( F_14 ( V_293 == V_294 ) ) {
F_208 ( V_294 ,
( void * ) F_209 ( V_187 ) ,
V_42 >> 20 ) ;
}
F_204 ( V_187 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_210 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_295 = V_28 -> V_41 - V_25 -> F_40 ;
if ( V_295 < 0 )
V_295 = - V_295 ;
if ( V_295 > 3 * V_68 )
F_211 ( V_25 , V_296 ) ;
#endif
}
static void
F_212 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_297 )
{
T_2 V_41 = V_25 -> F_40 ;
if ( V_297 && F_213 ( V_298 ) )
V_41 += F_63 ( V_25 , V_28 ) ;
if ( ! V_297 ) {
unsigned long V_299 = V_68 ;
if ( F_213 ( V_300 ) )
V_299 >>= 1 ;
V_41 -= V_299 ;
}
V_28 -> V_41 = F_39 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_214 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_185 )
{
if ( ! ( V_185 & V_301 ) || ( V_185 & V_302 ) )
V_28 -> V_41 += V_25 -> F_40 ;
F_66 ( V_25 ) ;
F_199 ( V_25 , V_28 , V_185 & V_301 ) ;
F_169 ( V_25 , V_28 ) ;
F_177 ( V_25 ) ;
if ( V_185 & V_301 ) {
F_212 ( V_25 , V_28 , 0 ) ;
F_203 ( V_25 , V_28 ) ;
}
F_77 ( V_25 , V_28 ) ;
F_210 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_46 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_215 ( V_25 ) ;
}
}
static void F_216 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 == V_28 )
V_25 -> V_59 = NULL ;
else
break;
}
}
static void F_217 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
V_25 -> V_58 = NULL ;
else
break;
}
}
static void F_218 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_303 == V_28 )
V_25 -> V_303 = NULL ;
else
break;
}
}
static void F_219 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_216 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_217 ( V_28 ) ;
if ( V_25 -> V_303 == V_28 )
F_218 ( V_28 ) ;
}
static void
F_220 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_185 )
{
F_66 ( V_25 ) ;
F_200 ( V_25 , V_28 , V_185 & V_304 ) ;
F_81 ( V_25 , V_28 ) ;
if ( V_185 & V_304 ) {
#ifdef F_79
if ( F_21 ( V_28 ) ) {
struct V_26 * V_187 = F_18 ( V_28 ) ;
if ( V_187 -> V_205 & V_305 )
V_28 -> V_83 . V_285 = F_76 ( F_17 ( V_25 ) ) ;
if ( V_187 -> V_205 & V_306 )
V_28 -> V_83 . V_288 = F_76 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_219 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_49 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_171 ( V_25 , V_28 ) ;
if ( ! ( V_185 & V_304 ) )
V_28 -> V_41 -= V_25 -> F_40 ;
F_221 ( V_25 ) ;
F_42 ( V_25 ) ;
F_177 ( V_25 ) ;
}
static void
F_222 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_307 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_307 = F_62 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_85 - V_45 -> V_308 ;
if ( V_19 > V_307 ) {
F_223 ( F_17 ( V_25 ) -> V_45 ) ;
F_219 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_69 )
return;
V_28 = F_52 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_307 )
F_223 ( F_17 ( V_25 ) -> V_45 ) ;
}
static void
F_224 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_78 ( V_25 , V_28 ) ;
F_49 ( V_25 , V_28 ) ;
}
F_82 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_79
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_83 . V_309 = F_69 ( V_28 -> V_83 . V_309 ,
V_28 -> V_85 - V_28 -> V_308 ) ;
}
#endif
V_28 -> V_308 = V_28 -> V_85 ;
}
static struct V_27 * F_225 ( struct V_25 * V_25 )
{
struct V_27 * V_28 = F_52 ( V_25 ) ;
struct V_27 * V_57 = V_28 ;
if ( V_25 -> V_303 == V_28 ) {
struct V_27 * V_310 = F_53 ( V_28 ) ;
if ( V_310 && F_226 ( V_310 , V_57 ) < 1 )
V_28 = V_310 ;
}
if ( V_25 -> V_59 && F_226 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_226 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_219 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_227 ( struct V_25 * V_25 , struct V_27 * V_311 )
{
if ( V_311 -> V_76 )
F_66 ( V_25 ) ;
F_228 ( V_25 ) ;
F_210 ( V_25 , V_311 ) ;
if ( V_311 -> V_76 ) {
F_75 ( V_25 , V_311 ) ;
F_46 ( V_25 , V_311 ) ;
F_194 ( V_311 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_229 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_312 )
{
F_66 ( V_25 ) ;
F_194 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_177 ( V_25 ) ;
#ifdef F_230
if ( V_312 ) {
F_223 ( F_17 ( V_25 ) -> V_45 ) ;
return;
}
if ( ! F_213 ( V_313 ) &&
F_231 ( & F_17 ( V_25 ) -> V_314 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_222 ( V_25 , V_45 ) ;
}
static inline bool F_232 ( void )
{
return F_233 ( & V_315 ) ;
}
void F_234 ( void )
{
F_235 ( & V_315 ) ;
}
void F_236 ( void )
{
F_237 ( & V_315 ) ;
}
static bool F_232 ( void )
{
return true ;
}
void F_234 ( void ) {}
void F_236 ( void ) {}
static inline T_2 F_238 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_239 ( void )
{
return ( T_2 ) V_316 * V_317 ;
}
void F_240 ( struct V_318 * V_319 )
{
T_2 V_81 ;
if ( V_319 -> V_320 == V_321 )
return;
V_81 = F_241 ( F_242 () ) ;
V_319 -> V_322 = V_319 -> V_320 ;
V_319 -> V_323 = V_81 + F_243 ( V_319 -> V_73 ) ;
}
static inline struct V_318 * F_244 ( struct V_243 * V_33 )
{
return & V_33 -> V_318 ;
}
static inline T_2 F_195 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_324 ) )
return V_25 -> V_325 ;
return F_67 ( F_17 ( V_25 ) ) - V_25 -> V_326 ;
}
static int F_245 ( struct V_25 * V_25 )
{
struct V_243 * V_33 = V_25 -> V_33 ;
struct V_318 * V_319 = F_244 ( V_33 ) ;
T_2 V_327 = 0 , V_328 , V_329 ;
V_328 = F_239 () - V_25 -> V_330 ;
F_246 ( & V_319 -> V_178 ) ;
if ( V_319 -> V_320 == V_321 )
V_327 = V_328 ;
else {
if ( ! V_319 -> V_331 ) {
F_240 ( V_319 ) ;
F_247 ( V_319 ) ;
}
if ( V_319 -> V_322 > 0 ) {
V_327 = F_127 ( V_319 -> V_322 , V_328 ) ;
V_319 -> V_322 -= V_327 ;
V_319 -> V_332 = 0 ;
}
}
V_329 = V_319 -> V_323 ;
F_248 ( & V_319 -> V_178 ) ;
V_25 -> V_330 += V_327 ;
if ( ( T_3 ) ( V_329 - V_25 -> V_323 ) > 0 )
V_25 -> V_323 = V_329 ;
return V_25 -> V_330 > 0 ;
}
static void F_249 ( struct V_25 * V_25 )
{
struct V_318 * V_319 = F_244 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_76 ( F_17 ( V_25 ) ) - V_25 -> V_323 ) < 0 ) )
return;
if ( V_25 -> V_330 < 0 )
return;
if ( ( T_3 ) ( V_25 -> V_323 - V_319 -> V_323 ) >= 0 ) {
V_25 -> V_323 += V_226 ;
} else {
V_25 -> V_330 = 0 ;
}
}
static void F_250 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_330 -= V_19 ;
F_249 ( V_25 ) ;
if ( F_12 ( V_25 -> V_330 > 0 ) )
return;
if ( ! F_245 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_223 ( F_17 ( V_25 ) -> V_45 ) ;
}
static T_9
void F_74 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_232 () || ! V_25 -> V_333 )
return;
F_250 ( V_25 , V_19 ) ;
}
static inline int F_251 ( struct V_25 * V_25 )
{
return F_232 () && V_25 -> V_334 ;
}
static inline int F_178 ( struct V_25 * V_25 )
{
return F_232 () && V_25 -> V_324 ;
}
static inline int F_252 ( struct V_243 * V_33 ,
int V_132 , int V_335 )
{
struct V_25 * V_336 , * V_337 ;
V_336 = V_33 -> V_25 [ V_132 ] ;
V_337 = V_33 -> V_25 [ V_335 ] ;
return F_178 ( V_336 ) ||
F_178 ( V_337 ) ;
}
static int F_253 ( struct V_243 * V_33 , void * V_338 )
{
struct V_24 * V_24 = V_338 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_324 -- ;
#ifdef F_170
if ( ! V_25 -> V_324 ) {
V_25 -> V_326 += F_67 ( V_24 ) -
V_25 -> V_325 ;
}
#endif
return 0 ;
}
static int F_254 ( struct V_243 * V_33 , void * V_338 )
{
struct V_24 * V_24 = V_338 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_324 )
V_25 -> V_325 = F_67 ( V_24 ) ;
V_25 -> V_324 ++ ;
return 0 ;
}
static void F_255 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_318 * V_319 = F_244 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_339 , V_340 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_108 () ;
F_256 ( V_25 -> V_33 , F_254 , V_341 , ( void * ) V_24 ) ;
F_114 () ;
V_339 = V_25 -> V_342 ;
F_36 (se) {
struct V_25 * V_343 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_340 )
F_220 ( V_343 , V_28 , V_304 ) ;
V_343 -> V_342 -= V_339 ;
if ( V_343 -> V_70 . V_4 )
V_340 = 0 ;
}
if ( ! V_28 )
V_24 -> V_72 -= V_339 ;
V_25 -> V_334 = 1 ;
V_25 -> V_344 = F_76 ( V_24 ) ;
F_246 ( & V_319 -> V_178 ) ;
F_29 ( & V_25 -> V_345 , & V_319 -> V_346 ) ;
if ( ! V_319 -> V_331 )
F_247 ( V_319 ) ;
F_248 ( & V_319 -> V_178 ) ;
}
void F_257 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_318 * V_319 = F_244 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_347 = 1 ;
long V_339 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_334 = 0 ;
F_258 ( V_24 ) ;
F_246 ( & V_319 -> V_178 ) ;
V_319 -> V_348 += F_76 ( V_24 ) - V_25 -> V_344 ;
F_32 ( & V_25 -> V_345 ) ;
F_248 ( & V_319 -> V_178 ) ;
F_256 ( V_25 -> V_33 , V_341 , F_253 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_339 = V_25 -> V_342 ;
F_36 (se) {
if ( V_28 -> V_76 )
V_347 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_347 )
F_214 ( V_25 , V_28 , V_301 ) ;
V_25 -> V_342 += V_339 ;
if ( F_251 ( V_25 ) )
break;
}
if ( ! V_28 )
V_24 -> V_72 += V_339 ;
if ( V_24 -> V_45 == V_24 -> V_332 && V_24 -> V_40 . V_72 )
F_223 ( V_24 -> V_45 ) ;
}
static T_2 F_259 ( struct V_318 * V_319 ,
T_2 V_349 , T_2 V_329 )
{
struct V_25 * V_25 ;
T_2 V_322 = V_349 ;
F_108 () ;
F_260 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_246 ( & V_24 -> V_178 ) ;
if ( ! F_251 ( V_25 ) )
goto V_58;
V_322 = - V_25 -> V_330 + 1 ;
if ( V_322 > V_349 )
V_322 = V_349 ;
V_349 -= V_322 ;
V_25 -> V_330 += V_322 ;
V_25 -> V_323 = V_329 ;
if ( V_25 -> V_330 > 0 )
F_257 ( V_25 ) ;
V_58:
F_248 ( & V_24 -> V_178 ) ;
if ( ! V_349 )
break;
}
F_114 () ;
return V_349 ;
}
static int F_261 ( struct V_318 * V_319 , int V_350 )
{
T_2 V_322 , V_323 ;
int V_332 = 1 , V_334 ;
F_246 ( & V_319 -> V_178 ) ;
if ( V_319 -> V_320 == V_321 )
goto V_351;
V_334 = ! F_262 ( & V_319 -> V_346 ) ;
V_332 = V_319 -> V_332 && ! V_334 ;
V_319 -> V_352 += V_350 ;
if ( V_332 )
goto V_351;
V_319 -> V_331 = 1 ;
F_240 ( V_319 ) ;
if ( ! V_334 ) {
V_319 -> V_332 = 1 ;
goto V_351;
}
V_319 -> V_353 += V_350 ;
V_322 = V_319 -> V_322 ;
V_323 = V_319 -> V_323 ;
V_319 -> V_322 = 0 ;
while ( V_334 && V_322 > 0 ) {
F_248 ( & V_319 -> V_178 ) ;
V_322 = F_259 ( V_319 , V_322 ,
V_323 ) ;
F_246 ( & V_319 -> V_178 ) ;
V_334 = ! F_262 ( & V_319 -> V_346 ) ;
}
V_319 -> V_322 = V_322 ;
V_319 -> V_332 = 0 ;
V_351:
if ( V_332 )
V_319 -> V_331 = 0 ;
F_248 ( & V_319 -> V_178 ) ;
return V_332 ;
}
static int F_263 ( struct V_318 * V_319 , T_2 V_354 )
{
struct V_355 * V_356 = & V_319 -> V_357 ;
T_2 V_349 ;
if ( F_264 ( V_356 ) )
return 1 ;
V_349 = F_243 ( F_265 ( V_356 ) ) ;
if ( V_349 < V_354 )
return 1 ;
return 0 ;
}
static void F_266 ( struct V_318 * V_319 )
{
T_2 V_358 = V_359 + V_360 ;
if ( F_263 ( V_319 , V_358 ) )
return;
F_267 ( & V_319 -> V_361 ,
F_268 ( V_359 ) ) ;
}
static void F_269 ( struct V_25 * V_25 )
{
struct V_318 * V_319 = F_244 ( V_25 -> V_33 ) ;
T_3 V_362 = V_25 -> V_330 - V_363 ;
if ( V_362 <= 0 )
return;
F_246 ( & V_319 -> V_178 ) ;
if ( V_319 -> V_320 != V_321 &&
V_25 -> V_323 == V_319 -> V_323 ) {
V_319 -> V_322 += V_362 ;
if ( V_319 -> V_322 > F_239 () &&
! F_262 ( & V_319 -> V_346 ) )
F_266 ( V_319 ) ;
}
F_248 ( & V_319 -> V_178 ) ;
V_25 -> V_330 -= V_362 ;
}
static T_9 void F_221 ( struct V_25 * V_25 )
{
if ( ! F_232 () )
return;
if ( ! V_25 -> V_333 || V_25 -> V_72 )
return;
F_269 ( V_25 ) ;
}
static void F_270 ( struct V_318 * V_319 )
{
T_2 V_322 = 0 , V_75 = F_239 () ;
T_2 V_329 ;
F_246 ( & V_319 -> V_178 ) ;
if ( F_263 ( V_319 , V_360 ) ) {
F_248 ( & V_319 -> V_178 ) ;
return;
}
if ( V_319 -> V_320 != V_321 && V_319 -> V_322 > V_75 ) {
V_322 = V_319 -> V_322 ;
V_319 -> V_322 = 0 ;
}
V_329 = V_319 -> V_323 ;
F_248 ( & V_319 -> V_178 ) ;
if ( ! V_322 )
return;
V_322 = F_259 ( V_319 , V_322 , V_329 ) ;
F_246 ( & V_319 -> V_178 ) ;
if ( V_329 == V_319 -> V_323 )
V_319 -> V_322 = V_322 ;
F_248 ( & V_319 -> V_178 ) ;
}
static void F_215 ( struct V_25 * V_25 )
{
if ( ! F_232 () )
return;
if ( ! V_25 -> V_333 || V_25 -> V_45 )
return;
if ( F_251 ( V_25 ) )
return;
F_74 ( V_25 , 0 ) ;
if ( V_25 -> V_330 <= 0 )
F_255 ( V_25 ) ;
}
static void F_228 ( struct V_25 * V_25 )
{
if ( ! F_232 () )
return;
if ( F_12 ( ! V_25 -> V_333 || V_25 -> V_330 > 0 ) )
return;
if ( F_251 ( V_25 ) )
return;
F_255 ( V_25 ) ;
}
static enum V_364 F_271 ( struct V_355 * V_365 )
{
struct V_318 * V_319 =
F_22 ( V_365 , struct V_318 , V_361 ) ;
F_270 ( V_319 ) ;
return V_366 ;
}
static enum V_364 F_272 ( struct V_355 * V_365 )
{
struct V_318 * V_319 =
F_22 ( V_365 , struct V_318 , V_357 ) ;
T_10 V_81 ;
int V_350 ;
int V_332 = 0 ;
for (; ; ) {
V_81 = F_273 ( V_365 ) ;
V_350 = F_274 ( V_365 , V_81 , V_319 -> V_73 ) ;
if ( ! V_350 )
break;
V_332 = F_261 ( V_319 , V_350 ) ;
}
return V_332 ? V_366 : V_367 ;
}
void F_275 ( struct V_318 * V_319 )
{
F_276 ( & V_319 -> V_178 ) ;
V_319 -> V_322 = 0 ;
V_319 -> V_320 = V_321 ;
V_319 -> V_73 = F_268 ( F_238 () ) ;
F_143 ( & V_319 -> V_346 ) ;
F_277 ( & V_319 -> V_357 , V_368 , V_369 ) ;
V_319 -> V_357 . V_370 = F_272 ;
F_277 ( & V_319 -> V_361 , V_368 , V_369 ) ;
V_319 -> V_361 . V_370 = F_271 ;
}
static void F_278 ( struct V_25 * V_25 )
{
V_25 -> V_333 = 0 ;
F_143 ( & V_25 -> V_345 ) ;
}
void F_247 ( struct V_318 * V_319 )
{
while ( F_14 ( F_231 ( & V_319 -> V_357 ) ) &&
F_279 ( & V_319 -> V_357 ) < 0 ) {
F_248 ( & V_319 -> V_178 ) ;
F_280 () ;
F_246 ( & V_319 -> V_178 ) ;
if ( V_319 -> V_331 )
return;
}
V_319 -> V_331 = 1 ;
F_267 ( & V_319 -> V_357 , V_319 -> V_73 ) ;
}
static void F_281 ( struct V_318 * V_319 )
{
F_282 ( & V_319 -> V_357 ) ;
F_282 ( & V_319 -> V_361 ) ;
}
static void T_11 F_283 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_284 (rq, cfs_rq) {
struct V_318 * V_319 = F_244 ( V_25 -> V_33 ) ;
if ( ! V_25 -> V_333 )
continue;
V_25 -> V_330 = V_319 -> V_320 ;
if ( F_251 ( V_25 ) )
F_257 ( V_25 ) ;
}
}
static inline T_2 F_195 ( struct V_25 * V_25 )
{
return F_67 ( F_17 ( V_25 ) ) ;
}
static void F_74 ( struct V_25 * V_25 , T_2 V_19 ) {}
static void F_228 ( struct V_25 * V_25 ) {}
static void F_215 ( struct V_25 * V_25 ) {}
static T_9 void F_221 ( struct V_25 * V_25 ) {}
static inline int F_251 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_178 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_252 ( struct V_243 * V_33 ,
int V_132 , int V_335 )
{
return 0 ;
}
void F_275 ( struct V_318 * V_319 ) {}
static void F_278 ( struct V_25 * V_25 ) {}
static inline struct V_318 * F_244 ( struct V_243 * V_33 )
{
return NULL ;
}
static inline void F_281 ( struct V_318 * V_319 ) {}
static inline void F_283 ( struct V_24 * V_24 ) {}
static void F_285 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_286 ( F_38 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_62 ( V_25 , V_28 ) ;
T_2 V_371 = V_28 -> V_85 - V_28 -> V_308 ;
T_3 V_42 = V_75 - V_371 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_223 ( V_29 ) ;
return;
}
if ( V_24 -> V_45 != V_29 )
V_42 = F_87 ( T_3 , 10000LL , V_42 ) ;
F_287 ( V_24 , V_42 ) ;
}
}
static void F_288 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_289 ( V_24 ) || V_45 -> V_372 != & V_373 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_285 ( V_24 , V_45 ) ;
}
static inline void
F_285 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_288 ( struct V_24 * V_24 )
{
}
static void
F_290 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_185 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_36 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_214 ( V_25 , V_28 , V_185 ) ;
if ( F_251 ( V_25 ) )
break;
V_25 -> V_342 ++ ;
V_185 = V_301 ;
}
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_342 ++ ;
if ( F_251 ( V_25 ) )
break;
F_177 ( V_25 ) ;
F_194 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_198 ( V_24 , V_24 -> V_72 ) ;
F_291 ( V_24 ) ;
}
F_288 ( V_24 ) ;
}
static void F_292 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_185 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_374 = V_185 & V_304 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_220 ( V_25 , V_28 , V_185 ) ;
if ( F_251 ( V_25 ) )
break;
V_25 -> V_342 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_374 && F_34 ( V_28 ) )
F_293 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_185 |= V_304 ;
}
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_342 -- ;
if ( F_251 ( V_25 ) )
break;
F_177 ( V_25 ) ;
F_194 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_294 ( V_24 ) ;
F_198 ( V_24 , 1 ) ;
}
F_288 ( V_24 ) ;
}
static unsigned long F_101 ( const int V_117 )
{
return F_100 ( V_117 ) -> V_40 . V_271 ;
}
static unsigned long F_295 ( int V_117 , int type )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
unsigned long V_375 = F_101 ( V_117 ) ;
if ( type == 0 || ! F_213 ( V_376 ) )
return V_375 ;
return F_127 ( V_24 -> V_377 [ type - 1 ] , V_375 ) ;
}
static unsigned long F_296 ( int V_117 , int type )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
unsigned long V_375 = F_101 ( V_117 ) ;
if ( type == 0 || ! F_213 ( V_376 ) )
return V_375 ;
return F_69 ( V_24 -> V_377 [ type - 1 ] , V_375 ) ;
}
static unsigned long F_102 ( int V_117 )
{
return F_100 ( V_117 ) -> V_378 ;
}
static unsigned long F_297 ( int V_117 )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
unsigned long V_72 = F_109 ( V_24 -> V_72 ) ;
unsigned long V_245 = V_24 -> V_40 . V_271 ;
if ( V_72 )
return V_245 / V_72 ;
return 0 ;
}
static void F_298 ( struct V_26 * V_29 )
{
if ( V_155 > V_197 -> V_379 + V_156 ) {
V_197 -> V_380 = 0 ;
V_197 -> V_379 = V_155 ;
}
if ( V_197 -> V_381 != V_29 ) {
V_197 -> V_381 = V_29 ;
V_197 -> V_380 ++ ;
}
}
static void F_299 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_40 ;
#ifndef F_44
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_300 () ;
F_40 = V_25 -> F_40 ;
} while ( F_40 != V_48 );
#else
F_40 = V_25 -> F_40 ;
#endif
V_28 -> V_41 -= F_40 ;
F_298 ( V_29 ) ;
}
static long F_301 ( struct V_243 * V_33 , int V_117 , long V_382 , long V_383 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_117 ] ;
if ( ! V_33 -> V_34 )
return V_382 ;
F_36 (se) {
long V_7 , V_384 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_384 = V_383 + F_173 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_382 ;
if ( V_384 > 0 && V_7 < V_384 )
V_382 = ( V_7 * V_33 -> V_247 ) / V_384 ;
else
V_382 = V_33 -> V_247 ;
if ( V_382 < V_248 )
V_382 = V_248 ;
V_382 -= V_28 -> V_70 . V_4 ;
V_383 = 0 ;
}
return V_382 ;
}
static long F_301 ( struct V_243 * V_33 , int V_117 , long V_382 , long V_383 )
{
return V_382 ;
}
static int F_302 ( struct V_26 * V_29 )
{
int V_9 = F_303 ( V_385 ) ;
if ( V_29 -> V_380 > V_9 ) {
if ( V_197 -> V_380 > ( V_9 * V_29 -> V_380 ) )
return 1 ;
}
return 0 ;
}
static int F_304 ( struct V_146 * V_147 , struct V_26 * V_29 , int V_386 )
{
T_3 V_387 , V_70 ;
int V_388 , V_389 , V_390 ;
unsigned long V_391 ;
struct V_243 * V_33 ;
unsigned long V_4 ;
int V_392 ;
if ( F_302 ( V_29 ) )
return 0 ;
V_388 = V_147 -> V_393 ;
V_389 = F_242 () ;
V_390 = F_117 ( V_29 ) ;
V_70 = F_295 ( V_390 , V_388 ) ;
V_387 = F_296 ( V_389 , V_388 ) ;
if ( V_386 ) {
V_33 = V_243 ( V_197 ) ;
V_4 = V_197 -> V_28 . V_70 . V_4 ;
V_387 += F_301 ( V_33 , V_389 , - V_4 , - V_4 ) ;
V_70 += F_301 ( V_33 , V_390 , 0 , - V_4 ) ;
}
V_33 = V_243 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_387 > 0 ) {
T_3 V_394 , V_395 ;
V_394 = 100 ;
V_394 *= F_102 ( V_390 ) ;
V_394 *= V_387 +
F_301 ( V_33 , V_389 , V_4 , V_4 ) ;
V_395 = 100 + ( V_147 -> V_145 - 100 ) / 2 ;
V_395 *= F_102 ( V_389 ) ;
V_395 *= V_70 + F_301 ( V_33 , V_390 , 0 , V_4 ) ;
V_392 = V_394 <= V_395 ;
} else
V_392 = true ;
if ( V_386 && V_392 )
return 1 ;
F_211 ( V_29 , V_28 . V_83 . V_396 ) ;
V_391 = F_297 ( V_389 ) ;
if ( V_392 ||
( V_387 <= V_70 &&
V_387 + F_296 ( V_390 , V_388 ) <= V_391 ) ) {
F_211 ( V_147 , V_397 ) ;
F_211 ( V_29 , V_28 . V_83 . V_398 ) ;
return 1 ;
}
return 0 ;
}
static struct V_399 *
F_305 ( struct V_146 * V_147 , struct V_26 * V_29 ,
int V_389 , int V_400 )
{
struct V_399 * V_401 = NULL , * V_402 = V_147 -> V_403 ;
unsigned long V_404 = V_405 , V_387 = 0 ;
int V_406 = 100 + ( V_147 -> V_145 - 100 ) / 2 ;
do {
unsigned long V_70 , V_407 ;
int V_408 ;
int V_179 ;
if ( ! F_306 ( F_307 ( V_402 ) ,
F_111 ( V_29 ) ) )
continue;
V_408 = F_110 ( V_389 ,
F_307 ( V_402 ) ) ;
V_407 = 0 ;
F_99 (i, sched_group_cpus(group)) {
if ( V_408 )
V_70 = F_295 ( V_179 , V_400 ) ;
else
V_70 = F_296 ( V_179 , V_400 ) ;
V_407 += V_70 ;
}
V_407 = ( V_407 * V_119 ) / V_402 -> V_409 -> V_118 ;
if ( V_408 ) {
V_387 = V_407 ;
} else if ( V_407 < V_404 ) {
V_404 = V_407 ;
V_401 = V_402 ;
}
} while ( V_402 = V_402 -> V_58 , V_402 != V_147 -> V_403 );
if ( ! V_401 || 100 * V_387 < V_406 * V_404 )
return NULL ;
return V_401 ;
}
static int
F_308 ( struct V_399 * V_402 , struct V_26 * V_29 , int V_389 )
{
unsigned long V_70 , V_404 = V_405 ;
int V_401 = - 1 ;
int V_179 ;
F_309 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_101 ( V_179 ) ;
if ( V_70 < V_404 || ( V_70 == V_404 && V_179 == V_389 ) ) {
V_404 = V_70 ;
V_401 = V_179 ;
}
}
return V_401 ;
}
static int F_310 ( struct V_26 * V_29 , int V_410 )
{
struct V_146 * V_147 ;
struct V_399 * V_411 ;
int V_179 = F_117 ( V_29 ) ;
if ( F_311 ( V_410 ) )
return V_410 ;
if ( V_179 != V_410 && F_312 ( V_179 , V_410 ) && F_311 ( V_179 ) )
return V_179 ;
V_147 = F_118 ( F_119 ( V_412 , V_410 ) ) ;
F_313 (sd) {
V_411 = V_147 -> V_403 ;
do {
if ( ! F_306 ( F_307 ( V_411 ) ,
F_111 ( V_29 ) ) )
goto V_58;
F_99 (i, sched_group_cpus(sg)) {
if ( V_179 == V_410 || ! F_311 ( V_179 ) )
goto V_58;
}
V_410 = F_314 ( F_307 ( V_411 ) ,
F_111 ( V_29 ) ) ;
goto V_413;
V_58:
V_411 = V_411 -> V_58 ;
} while ( V_411 != V_147 -> V_403 );
}
V_413:
return V_410 ;
}
static int
F_315 ( struct V_26 * V_29 , int V_390 , int V_414 , int V_415 )
{
struct V_146 * V_416 , * V_417 = NULL , * V_147 = NULL ;
int V_117 = F_242 () ;
int V_418 = V_117 ;
int V_419 = 0 ;
int V_386 = V_415 & V_420 ;
if ( V_29 -> V_421 == 1 )
return V_390 ;
if ( V_414 & V_422 ) {
if ( F_110 ( V_117 , F_111 ( V_29 ) ) )
V_419 = 1 ;
V_418 = V_390 ;
}
F_108 () ;
F_316 (cpu, tmp) {
if ( ! ( V_416 -> V_185 & V_423 ) )
continue;
if ( V_419 && ( V_416 -> V_185 & V_424 ) &&
F_110 ( V_390 , F_317 ( V_416 ) ) ) {
V_417 = V_416 ;
break;
}
if ( V_416 -> V_185 & V_414 )
V_147 = V_416 ;
}
if ( V_417 ) {
if ( V_117 != V_390 && F_304 ( V_417 , V_29 , V_386 ) )
V_390 = V_117 ;
V_418 = F_310 ( V_29 , V_390 ) ;
goto V_138;
}
while ( V_147 ) {
int V_400 = V_147 -> V_425 ;
struct V_399 * V_402 ;
int V_4 ;
if ( ! ( V_147 -> V_185 & V_414 ) ) {
V_147 = V_147 -> V_426 ;
continue;
}
if ( V_414 & V_422 )
V_400 = V_147 -> V_393 ;
V_402 = F_305 ( V_147 , V_29 , V_117 , V_400 ) ;
if ( ! V_402 ) {
V_147 = V_147 -> V_426 ;
continue;
}
V_418 = F_308 ( V_402 , V_29 , V_117 ) ;
if ( V_418 == - 1 || V_418 == V_117 ) {
V_147 = V_147 -> V_426 ;
continue;
}
V_117 = V_418 ;
V_4 = V_147 -> V_427 ;
V_147 = NULL ;
F_316 (cpu, tmp) {
if ( V_4 <= V_416 -> V_427 )
break;
if ( V_416 -> V_185 & V_414 )
V_147 = V_416 ;
}
}
V_138:
F_114 () ;
return V_418 ;
}
static void
F_318 ( struct V_26 * V_29 , int V_428 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_182 ( V_28 ) ;
F_185 ( V_28 -> V_77 . V_268 ,
& V_25 -> V_281 ) ;
}
}
static unsigned long
F_319 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_429 = V_430 ;
return F_60 ( V_429 , V_28 ) ;
}
static int
F_226 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_429 , V_431 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_431 <= 0 )
return - 1 ;
V_429 = F_319 ( V_45 , V_28 ) ;
if ( V_431 > V_429 )
return 1 ;
return 0 ;
}
static void F_320 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_432 == V_433 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_293 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_432 == V_433 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_321 ( struct V_27 * V_28 )
{
F_36 (se)
F_24 ( V_28 ) -> V_303 = V_28 ;
}
static void F_322 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_415 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_434 = V_25 -> V_72 >= V_67 ;
int V_435 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_178 ( F_24 ( V_36 ) ) ) )
return;
if ( F_213 ( V_436 ) && V_434 && ! ( V_415 & V_437 ) ) {
F_293 ( V_36 ) ;
V_435 = 1 ;
}
if ( F_323 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_432 == V_433 ) &&
F_12 ( V_29 -> V_432 != V_433 ) )
goto V_438;
if ( F_14 ( V_29 -> V_432 != V_439 ) || ! F_213 ( V_440 ) )
return;
F_37 ( & V_28 , & V_36 ) ;
F_66 ( F_24 ( V_28 ) ) ;
F_153 ( ! V_36 ) ;
if ( F_226 ( V_28 , V_36 ) == 1 ) {
if ( ! V_435 )
F_293 ( V_36 ) ;
goto V_438;
}
return;
V_438:
F_223 ( V_45 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_332 ) )
return;
if ( F_213 ( V_441 ) && V_434 && F_21 ( V_28 ) )
F_320 ( V_28 ) ;
}
static struct V_26 * F_324 ( struct V_24 * V_24 )
{
struct V_26 * V_29 ;
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
if ( ! V_25 -> V_72 )
return NULL ;
do {
V_28 = F_225 ( V_25 ) ;
F_224 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_289 ( V_24 ) )
F_285 ( V_24 , V_29 ) ;
return V_29 ;
}
static void F_325 ( struct V_24 * V_24 , struct V_26 * V_311 )
{
struct V_27 * V_28 = & V_311 -> V_28 ;
struct V_25 * V_25 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_227 ( V_25 , V_28 ) ;
}
}
static void F_326 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_219 ( V_25 , V_28 ) ;
if ( V_45 -> V_432 != V_442 ) {
F_258 ( V_24 ) ;
F_66 ( V_25 ) ;
V_24 -> V_443 = 1 ;
}
F_321 ( V_28 ) ;
}
static bool F_327 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_438 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_178 ( F_24 ( V_28 ) ) )
return false ;
F_293 ( V_28 ) ;
F_326 ( V_24 ) ;
return true ;
}
static void F_328 ( struct V_26 * V_29 , struct V_444 * V_123 )
{
F_329 ( V_123 -> V_131 , V_29 , 0 ) ;
F_330 ( V_29 , V_123 -> V_128 ) ;
F_331 ( V_123 -> V_133 , V_29 , 0 ) ;
F_332 ( V_123 -> V_133 , V_29 , 0 ) ;
}
static int
F_333 ( struct V_26 * V_29 , T_2 V_81 , struct V_146 * V_147 )
{
T_3 V_42 ;
if ( V_29 -> V_372 != & V_373 )
return 0 ;
if ( F_14 ( V_29 -> V_432 == V_433 ) )
return 0 ;
if ( F_213 ( V_445 ) && V_284 () -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_446 == - 1 )
return 1 ;
if ( V_446 == 0 )
return 0 ;
V_42 = V_81 - V_29 -> V_28 . V_82 ;
return V_42 < ( T_3 ) V_446 ;
}
static bool F_334 ( struct V_26 * V_29 , struct V_444 * V_123 )
{
int V_139 , V_140 ;
if ( ! F_213 ( V_447 ) || ! V_29 -> V_111 ||
! ( V_123 -> V_147 -> V_185 & V_448 ) ) {
return false ;
}
V_139 = F_120 ( V_123 -> V_132 ) ;
V_140 = F_120 ( V_123 -> V_128 ) ;
if ( V_139 == V_140 )
return false ;
if ( V_140 == V_29 -> V_105 )
return true ;
if ( F_96 ( V_29 , V_140 ) > F_96 ( V_29 , V_139 ) &&
F_97 ( V_29 , V_140 ) > F_97 ( V_29 , V_139 ) )
return true ;
return false ;
}
static bool F_335 ( struct V_26 * V_29 , struct V_444 * V_123 )
{
int V_139 , V_140 ;
if ( ! F_213 ( V_449 ) || ! F_213 ( V_450 ) )
return false ;
if ( ! V_29 -> V_111 || ! ( V_123 -> V_147 -> V_185 & V_448 ) )
return false ;
V_139 = F_120 ( V_123 -> V_132 ) ;
V_140 = F_120 ( V_123 -> V_128 ) ;
if ( V_139 == V_140 )
return false ;
if ( V_139 == V_29 -> V_105 )
return true ;
if ( F_96 ( V_29 , V_140 ) < F_96 ( V_29 , V_139 ) ||
F_97 ( V_29 , V_140 ) < F_97 ( V_29 , V_139 ) )
return true ;
return false ;
}
static inline bool F_334 ( struct V_26 * V_29 ,
struct V_444 * V_123 )
{
return false ;
}
static inline bool F_335 ( struct V_26 * V_29 ,
struct V_444 * V_123 )
{
return false ;
}
static
int F_336 ( struct V_26 * V_29 , struct V_444 * V_123 )
{
int V_451 = 0 ;
if ( F_252 ( V_243 ( V_29 ) , V_123 -> V_132 , V_123 -> V_128 ) )
return 0 ;
if ( ! F_110 ( V_123 -> V_128 , F_111 ( V_29 ) ) ) {
int V_117 ;
F_211 ( V_29 , V_28 . V_83 . V_452 ) ;
V_123 -> V_185 |= V_453 ;
if ( ! V_123 -> V_454 || ( V_123 -> V_185 & V_455 ) )
return 0 ;
F_309 (cpu, env->dst_grpmask, env->cpus) {
if ( F_110 ( V_117 , F_111 ( V_29 ) ) ) {
V_123 -> V_185 |= V_455 ;
V_123 -> V_456 = V_117 ;
break;
}
}
return 0 ;
}
V_123 -> V_185 &= ~ V_457 ;
if ( F_337 ( V_123 -> V_131 , V_29 ) ) {
F_211 ( V_29 , V_28 . V_83 . V_458 ) ;
return 0 ;
}
V_451 = F_333 ( V_29 , F_67 ( V_123 -> V_131 ) , V_123 -> V_147 ) ;
if ( ! V_451 )
V_451 = F_335 ( V_29 , V_123 ) ;
if ( F_334 ( V_29 , V_123 ) ) {
#ifdef F_79
if ( V_451 ) {
F_211 ( V_123 -> V_147 , V_459 [ V_123 -> V_332 ] ) ;
F_211 ( V_29 , V_28 . V_83 . V_460 ) ;
}
#endif
return 1 ;
}
if ( ! V_451 ||
V_123 -> V_147 -> V_461 > V_123 -> V_147 -> V_462 ) {
if ( V_451 ) {
F_211 ( V_123 -> V_147 , V_459 [ V_123 -> V_332 ] ) ;
F_211 ( V_29 , V_28 . V_83 . V_460 ) ;
}
return 1 ;
}
F_211 ( V_29 , V_28 . V_83 . V_463 ) ;
return 0 ;
}
static int F_338 ( struct V_444 * V_123 )
{
struct V_26 * V_29 , * V_250 ;
F_339 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_336 ( V_29 , V_123 ) )
continue;
F_328 ( V_29 , V_123 ) ;
F_211 ( V_123 -> V_147 , V_464 [ V_123 -> V_332 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_340 ( struct V_444 * V_123 )
{
struct V_465 * V_466 = & V_123 -> V_131 -> V_242 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_467 = 0 ;
if ( V_123 -> V_406 <= 0 )
return 0 ;
while ( ! F_262 ( V_466 ) ) {
V_29 = F_341 ( V_466 , struct V_26 , V_28 . V_241 ) ;
V_123 -> V_468 ++ ;
if ( V_123 -> V_468 > V_123 -> V_469 )
break;
if ( V_123 -> V_468 > V_123 -> V_470 ) {
V_123 -> V_470 += V_471 ;
V_123 -> V_185 |= V_472 ;
break;
}
if ( ! F_336 ( V_29 , V_123 ) )
goto V_58;
V_70 = F_112 ( V_29 ) ;
if ( F_213 ( V_473 ) && V_70 < 16 && ! V_123 -> V_147 -> V_461 )
goto V_58;
if ( ( V_70 / 2 ) > V_123 -> V_406 )
goto V_58;
F_328 ( V_29 , V_123 ) ;
V_467 ++ ;
V_123 -> V_406 -= V_70 ;
#ifdef F_342
if ( V_123 -> V_332 == V_474 )
break;
#endif
if ( V_123 -> V_406 <= 0 )
break;
continue;
V_58:
F_343 ( & V_29 -> V_28 . V_241 , V_466 ) ;
}
F_70 ( V_123 -> V_147 , V_464 [ V_123 -> V_332 ] , V_467 ) ;
return V_467 ;
}
static void F_344 ( struct V_243 * V_33 , int V_117 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_117 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_117 ] ;
if ( F_178 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_194 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_198 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_345 ( int V_117 )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
struct V_25 * V_25 ;
unsigned long V_185 ;
F_346 ( & V_24 -> V_178 , V_185 ) ;
F_258 ( V_24 ) ;
F_284 (rq, cfs_rq) {
F_344 ( V_25 -> V_33 , V_24 -> V_117 ) ;
}
F_347 ( & V_24 -> V_178 , V_185 ) ;
}
static void F_348 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_81 = V_155 ;
unsigned long V_70 ;
if ( V_25 -> V_475 == V_81 )
return;
V_25 -> V_476 = NULL ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_476 = V_28 ;
if ( V_25 -> V_475 == V_81 )
break;
}
if ( ! V_28 ) {
V_25 -> V_477 = V_25 -> V_271 ;
V_25 -> V_475 = V_81 ;
}
while ( ( V_28 = V_25 -> V_476 ) != NULL ) {
V_70 = V_25 -> V_477 ;
V_70 = F_349 ( V_70 * V_28 -> V_77 . V_268 ,
V_25 -> V_271 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_477 = V_70 ;
V_25 -> V_475 = V_81 ;
}
}
static unsigned long F_112 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_348 ( V_25 ) ;
return F_349 ( V_29 -> V_28 . V_77 . V_268 * V_25 -> V_477 ,
V_25 -> V_271 + 1 ) ;
}
static inline void F_345 ( int V_117 )
{
}
static unsigned long F_112 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_268 ;
}
static inline void F_350 ( struct V_478 * V_479 )
{
* V_479 = (struct V_478 ) {
. V_480 = NULL ,
. V_164 = NULL ,
. V_481 = 0UL ,
. V_482 = 0UL ,
. V_483 = {
. V_407 = 0UL ,
} ,
} ;
}
static inline int F_351 ( struct V_146 * V_147 ,
enum V_484 V_332 )
{
int V_400 ;
switch ( V_332 ) {
case V_485 :
V_400 = V_147 -> V_486 ;
break;
case V_474 :
V_400 = V_147 -> V_487 ;
break;
default:
V_400 = V_147 -> V_488 ;
break;
}
return V_400 ;
}
static unsigned long F_352 ( struct V_146 * V_147 , int V_117 )
{
return V_119 ;
}
unsigned long __weak F_353 ( struct V_146 * V_147 , int V_117 )
{
return F_352 ( V_147 , V_117 ) ;
}
static unsigned long F_354 ( struct V_146 * V_147 , int V_117 )
{
unsigned long V_4 = V_147 -> V_427 ;
unsigned long V_489 = V_147 -> V_489 ;
V_489 /= V_4 ;
return V_489 ;
}
unsigned long __weak F_355 ( struct V_146 * V_147 , int V_117 )
{
return F_354 ( V_147 , V_117 ) ;
}
static unsigned long F_356 ( int V_117 )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
T_2 V_375 , V_490 , V_491 , V_77 ;
V_491 = F_109 ( V_24 -> V_491 ) ;
V_77 = F_109 ( V_24 -> V_492 ) ;
V_375 = F_357 () + ( F_76 ( V_24 ) - V_491 ) ;
if ( F_14 ( V_375 < V_77 ) ) {
V_490 = 0 ;
} else {
V_490 = V_375 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_375 < V_119 ) )
V_375 = V_119 ;
V_375 >>= V_493 ;
return F_187 ( V_490 , V_375 ) ;
}
static void F_358 ( struct V_146 * V_147 , int V_117 )
{
unsigned long V_4 = V_147 -> V_427 ;
unsigned long V_118 = V_119 ;
struct V_399 * V_494 = V_147 -> V_403 ;
if ( ( V_147 -> V_185 & V_495 ) && V_4 > 1 ) {
if ( F_213 ( V_496 ) )
V_118 *= F_355 ( V_147 , V_117 ) ;
else
V_118 *= F_354 ( V_147 , V_117 ) ;
V_118 >>= V_493 ;
}
V_494 -> V_409 -> V_497 = V_118 ;
if ( F_213 ( V_496 ) )
V_118 *= F_353 ( V_147 , V_117 ) ;
else
V_118 *= F_352 ( V_147 , V_117 ) ;
V_118 >>= V_493 ;
V_118 *= F_356 ( V_117 ) ;
V_118 >>= V_493 ;
if ( ! V_118 )
V_118 = 1 ;
F_100 ( V_117 ) -> V_378 = V_118 ;
V_494 -> V_409 -> V_118 = V_118 ;
}
void F_359 ( struct V_146 * V_147 , int V_117 )
{
struct V_146 * V_426 = V_147 -> V_426 ;
struct V_399 * V_402 , * V_494 = V_147 -> V_403 ;
unsigned long V_118 , V_497 ;
unsigned long V_498 ;
V_498 = F_128 ( V_147 -> V_499 ) ;
V_498 = F_129 ( V_498 , 1UL , V_500 ) ;
V_494 -> V_409 -> V_501 = V_155 + V_498 ;
if ( ! V_426 ) {
F_358 ( V_147 , V_117 ) ;
return;
}
V_497 = V_118 = 0 ;
if ( V_426 -> V_185 & V_502 ) {
F_99 (cpu, sched_group_cpus(sdg)) {
struct V_503 * V_409 ;
struct V_24 * V_24 = F_100 ( V_117 ) ;
if ( F_14 ( ! V_24 -> V_147 ) ) {
V_497 += F_102 ( V_117 ) ;
V_118 += F_102 ( V_117 ) ;
continue;
}
V_409 = V_24 -> V_147 -> V_403 -> V_409 ;
V_497 += V_409 -> V_497 ;
V_118 += V_409 -> V_118 ;
}
} else {
V_402 = V_426 -> V_403 ;
do {
V_497 += V_402 -> V_409 -> V_497 ;
V_118 += V_402 -> V_409 -> V_118 ;
V_402 = V_402 -> V_58 ;
} while ( V_402 != V_426 -> V_403 );
}
V_494 -> V_409 -> V_497 = V_497 ;
V_494 -> V_409 -> V_118 = V_118 ;
}
static inline int
F_360 ( struct V_146 * V_147 , struct V_399 * V_402 )
{
if ( ! ( V_147 -> V_185 & V_495 ) )
return 0 ;
if ( V_402 -> V_409 -> V_118 * 32 > V_402 -> V_409 -> V_497 * 29 )
return 1 ;
return 0 ;
}
static inline int F_361 ( struct V_399 * V_402 )
{
return V_402 -> V_409 -> V_406 ;
}
static inline int F_362 ( struct V_444 * V_123 , struct V_399 * V_402 )
{
unsigned int V_120 , V_504 , V_8 ;
unsigned int V_118 , V_497 ;
V_118 = V_402 -> V_409 -> V_118 ;
V_497 = V_402 -> V_409 -> V_497 ;
V_8 = V_402 -> F_97 ;
V_504 = F_58 ( V_119 * V_8 , V_497 ) ;
V_120 = V_8 / V_504 ;
V_120 = F_5 ( unsigned , V_120 , F_103 ( V_118 , V_119 ) ) ;
if ( ! V_120 )
V_120 = F_360 ( V_123 -> V_147 , V_402 ) ;
return V_120 ;
}
static inline void F_363 ( struct V_444 * V_123 ,
struct V_399 * V_402 , int V_400 ,
int V_408 , struct V_505 * V_506 )
{
unsigned long V_72 ;
unsigned long V_70 ;
int V_179 ;
memset ( V_506 , 0 , sizeof( * V_506 ) ) ;
F_309 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_100 ( V_179 ) ;
V_72 = V_24 -> V_72 ;
if ( V_408 )
V_70 = F_296 ( V_179 , V_400 ) ;
else
V_70 = F_295 ( V_179 , V_400 ) ;
V_506 -> V_507 += V_70 ;
V_506 -> V_508 += V_72 ;
#ifdef F_364
V_506 -> V_104 += V_24 -> V_104 ;
V_506 -> V_106 += V_24 -> V_106 ;
#endif
V_506 -> V_509 += F_101 ( V_179 ) ;
if ( F_311 ( V_179 ) )
V_506 -> V_510 ++ ;
}
V_506 -> V_511 = V_402 -> V_409 -> V_118 ;
V_506 -> V_407 = ( V_506 -> V_507 * V_119 ) / V_506 -> V_511 ;
if ( V_506 -> V_508 )
V_506 -> V_512 = V_506 -> V_509 / V_506 -> V_508 ;
V_506 -> F_97 = V_402 -> F_97 ;
V_506 -> V_513 = F_361 ( V_402 ) ;
V_506 -> V_514 = F_362 ( V_123 , V_402 ) ;
if ( V_506 -> V_514 > V_506 -> V_508 )
V_506 -> V_515 = 1 ;
}
static bool F_365 ( struct V_444 * V_123 ,
struct V_478 * V_479 ,
struct V_399 * V_411 ,
struct V_505 * V_506 )
{
if ( V_506 -> V_407 <= V_479 -> V_483 . V_407 )
return false ;
if ( V_506 -> V_508 > V_506 -> V_514 )
return true ;
if ( V_506 -> V_513 )
return true ;
if ( ( V_123 -> V_147 -> V_185 & V_516 ) && V_506 -> V_508 &&
V_123 -> V_128 < F_366 ( V_411 ) ) {
if ( ! V_479 -> V_480 )
return true ;
if ( F_366 ( V_479 -> V_480 ) > F_366 ( V_411 ) )
return true ;
}
return false ;
}
static inline enum V_517 F_367 ( struct V_505 * V_506 )
{
if ( V_506 -> V_508 > V_506 -> V_104 )
return V_518 ;
if ( V_506 -> V_508 > V_506 -> V_106 )
return V_162 ;
return V_519 ;
}
static inline enum V_517 F_368 ( struct V_24 * V_24 )
{
if ( V_24 -> V_72 > V_24 -> V_104 )
return V_518 ;
if ( V_24 -> V_72 > V_24 -> V_106 )
return V_162 ;
return V_519 ;
}
static inline enum V_517 F_367 ( struct V_505 * V_506 )
{
return V_519 ;
}
static inline enum V_517 F_368 ( struct V_24 * V_24 )
{
return V_518 ;
}
static inline void F_369 ( struct V_444 * V_123 , struct V_478 * V_479 )
{
struct V_146 * V_426 = V_123 -> V_147 -> V_426 ;
struct V_399 * V_411 = V_123 -> V_147 -> V_403 ;
struct V_505 V_520 ;
int V_400 , V_521 = 0 ;
if ( V_426 && V_426 -> V_185 & V_522 )
V_521 = 1 ;
V_400 = F_351 ( V_123 -> V_147 , V_123 -> V_332 ) ;
do {
struct V_505 * V_506 = & V_520 ;
int V_408 ;
V_408 = F_110 ( V_123 -> V_128 , F_307 ( V_411 ) ) ;
if ( V_408 ) {
V_479 -> V_164 = V_411 ;
V_506 = & V_479 -> V_523 ;
if ( V_123 -> V_332 != V_474 ||
F_370 ( V_155 , V_411 -> V_409 -> V_501 ) )
F_359 ( V_123 -> V_147 , V_123 -> V_128 ) ;
}
F_363 ( V_123 , V_411 , V_400 , V_408 , V_506 ) ;
if ( V_408 )
goto V_524;
if ( V_521 && V_479 -> V_164 &&
V_479 -> V_523 . V_515 )
V_506 -> V_514 = F_127 ( V_506 -> V_514 , 1U ) ;
if ( F_365 ( V_123 , V_479 , V_411 , V_506 ) ) {
V_479 -> V_480 = V_411 ;
V_479 -> V_483 = * V_506 ;
}
V_524:
V_479 -> V_481 += V_506 -> V_507 ;
V_479 -> V_482 += V_506 -> V_511 ;
V_411 = V_411 -> V_58 ;
} while ( V_411 != V_123 -> V_147 -> V_403 );
if ( V_123 -> V_147 -> V_185 & V_448 )
V_123 -> V_517 = F_367 ( & V_479 -> V_483 ) ;
}
static int F_371 ( struct V_444 * V_123 , struct V_478 * V_479 )
{
int V_525 ;
if ( ! ( V_123 -> V_147 -> V_185 & V_516 ) )
return 0 ;
if ( ! V_479 -> V_480 )
return 0 ;
V_525 = F_366 ( V_479 -> V_480 ) ;
if ( V_123 -> V_128 > V_525 )
return 0 ;
V_123 -> V_406 = F_103 (
V_479 -> V_483 . V_407 * V_479 -> V_483 . V_511 ,
V_119 ) ;
return 1 ;
}
static inline
void F_372 ( struct V_444 * V_123 , struct V_478 * V_479 )
{
unsigned long V_416 , V_526 = 0 , V_527 = 0 ;
unsigned int V_528 = 2 ;
unsigned long V_529 ;
struct V_505 * V_164 , * V_480 ;
V_164 = & V_479 -> V_523 ;
V_480 = & V_479 -> V_483 ;
if ( ! V_164 -> V_508 )
V_164 -> V_512 = F_297 ( V_123 -> V_128 ) ;
else if ( V_480 -> V_512 > V_164 -> V_512 )
V_528 = 1 ;
V_529 =
( V_480 -> V_512 * V_119 ) /
V_480 -> V_511 ;
if ( V_480 -> V_407 + V_529 >=
V_164 -> V_407 + ( V_529 * V_528 ) ) {
V_123 -> V_406 = V_480 -> V_512 ;
return;
}
V_526 += V_480 -> V_511 *
F_127 ( V_480 -> V_512 , V_480 -> V_407 ) ;
V_526 += V_164 -> V_511 *
F_127 ( V_164 -> V_512 , V_164 -> V_407 ) ;
V_526 /= V_119 ;
V_416 = ( V_480 -> V_512 * V_119 ) /
V_480 -> V_511 ;
if ( V_480 -> V_407 > V_416 ) {
V_527 += V_480 -> V_511 *
F_127 ( V_480 -> V_512 ,
V_480 -> V_407 - V_416 ) ;
}
if ( V_480 -> V_407 * V_480 -> V_511 <
V_480 -> V_512 * V_119 ) {
V_416 = ( V_480 -> V_407 * V_480 -> V_511 ) /
V_164 -> V_511 ;
} else {
V_416 = ( V_480 -> V_512 * V_119 ) /
V_164 -> V_511 ;
}
V_527 += V_164 -> V_511 *
F_127 ( V_164 -> V_512 , V_164 -> V_407 + V_416 ) ;
V_527 /= V_119 ;
if ( V_527 > V_526 )
V_123 -> V_406 = V_480 -> V_512 ;
}
static inline void F_373 ( struct V_444 * V_123 , struct V_478 * V_479 )
{
unsigned long V_530 , V_531 = ~ 0UL ;
struct V_505 * V_164 , * V_480 ;
V_164 = & V_479 -> V_523 ;
V_480 = & V_479 -> V_483 ;
if ( V_480 -> V_513 ) {
V_480 -> V_512 =
F_127 ( V_480 -> V_512 , V_479 -> V_407 ) ;
}
if ( V_480 -> V_407 <= V_479 -> V_407 ||
V_164 -> V_407 >= V_479 -> V_407 ) {
V_123 -> V_406 = 0 ;
return F_372 ( V_123 , V_479 ) ;
}
if ( ! V_480 -> V_513 ) {
V_531 =
( V_480 -> V_508 - V_480 -> V_514 ) ;
V_531 *= ( V_532 * V_119 ) ;
V_531 /= V_480 -> V_511 ;
}
V_530 = F_127 ( V_480 -> V_407 - V_479 -> V_407 , V_531 ) ;
V_123 -> V_406 = F_127 (
V_530 * V_480 -> V_511 ,
( V_479 -> V_407 - V_164 -> V_407 ) * V_164 -> V_511
) / V_119 ;
if ( V_123 -> V_406 < V_480 -> V_512 )
return F_372 ( V_123 , V_479 ) ;
}
static struct V_399 * F_374 ( struct V_444 * V_123 )
{
struct V_505 * V_164 , * V_480 ;
struct V_478 V_479 ;
F_350 ( & V_479 ) ;
F_369 ( V_123 , & V_479 ) ;
V_164 = & V_479 . V_523 ;
V_480 = & V_479 . V_483 ;
if ( ( V_123 -> V_332 == V_533 || V_123 -> V_332 == V_474 ) &&
F_371 ( V_123 , & V_479 ) )
return V_479 . V_480 ;
if ( ! V_479 . V_480 || V_480 -> V_508 == 0 )
goto V_534;
V_479 . V_407 = ( V_119 * V_479 . V_481 ) / V_479 . V_482 ;
if ( V_480 -> V_513 )
goto V_535;
if ( V_123 -> V_332 == V_474 && V_164 -> V_515 &&
! V_480 -> V_515 )
goto V_535;
if ( V_164 -> V_407 >= V_480 -> V_407 )
goto V_534;
if ( V_164 -> V_407 >= V_479 . V_407 )
goto V_534;
if ( V_123 -> V_332 == V_533 ) {
if ( ( V_164 -> V_510 < V_480 -> V_510 ) &&
V_480 -> V_508 <= V_480 -> F_97 )
goto V_534;
} else {
if ( 100 * V_480 -> V_407 <=
V_123 -> V_147 -> V_145 * V_164 -> V_407 )
goto V_534;
}
V_535:
F_373 ( V_123 , & V_479 ) ;
return V_479 . V_480 ;
V_534:
V_123 -> V_406 = 0 ;
return NULL ;
}
static struct V_24 * F_375 ( struct V_444 * V_123 ,
struct V_399 * V_402 )
{
struct V_24 * V_480 = NULL , * V_24 ;
unsigned long V_536 = 0 , V_537 = 1 ;
int V_179 ;
F_309 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_118 , V_120 , V_382 ;
enum V_517 V_538 ;
V_24 = F_100 ( V_179 ) ;
V_538 = F_368 ( V_24 ) ;
if ( V_538 > V_123 -> V_517 )
continue;
V_118 = F_102 ( V_179 ) ;
V_120 = F_103 ( V_118 , V_119 ) ;
if ( ! V_120 )
V_120 = F_360 ( V_123 -> V_147 , V_402 ) ;
V_382 = F_101 ( V_179 ) ;
if ( V_120 && V_24 -> V_72 == 1 && V_382 > V_123 -> V_406 )
continue;
if ( V_382 * V_537 > V_536 * V_118 ) {
V_536 = V_382 ;
V_537 = V_118 ;
V_480 = V_24 ;
}
}
return V_480 ;
}
static int F_376 ( struct V_444 * V_123 )
{
struct V_146 * V_147 = V_123 -> V_147 ;
if ( V_123 -> V_332 == V_474 ) {
if ( ( V_147 -> V_185 & V_516 ) && V_123 -> V_132 > V_123 -> V_128 )
return 1 ;
}
return F_14 ( V_147 -> V_461 > V_147 -> V_462 + 2 ) ;
}
static int F_377 ( struct V_444 * V_123 )
{
struct V_399 * V_411 = V_123 -> V_147 -> V_403 ;
struct V_539 * V_540 , * V_541 ;
int V_117 , V_542 = - 1 ;
if ( V_123 -> V_332 == V_474 )
return 1 ;
V_540 = F_307 ( V_411 ) ;
V_541 = F_378 ( V_411 ) ;
F_309 (cpu, sg_cpus, env->cpus) {
if ( ! F_110 ( V_117 , V_541 ) || ! F_311 ( V_117 ) )
continue;
V_542 = V_117 ;
break;
}
if ( V_542 == - 1 )
V_542 = F_379 ( V_411 ) ;
return V_542 == V_123 -> V_128 ;
}
static int F_380 ( int V_389 , struct V_24 * V_284 ,
struct V_146 * V_147 , enum V_484 V_332 ,
int * V_543 )
{
int V_544 , V_545 , V_546 = 0 ;
struct V_146 * V_547 = V_147 -> V_34 ;
struct V_399 * V_402 ;
struct V_24 * V_480 ;
unsigned long V_185 ;
struct V_539 * V_8 = F_381 ( V_548 ) ;
struct V_444 V_123 = {
. V_147 = V_147 ,
. V_128 = V_389 ,
. V_133 = V_284 ,
. V_454 = F_307 ( V_147 -> V_403 ) ,
. V_332 = V_332 ,
. V_470 = V_471 ,
. V_8 = V_8 ,
. V_517 = V_519 ,
} ;
if ( V_332 == V_474 )
V_123 . V_454 = NULL ;
F_382 ( V_8 , V_549 ) ;
F_211 ( V_147 , V_550 [ V_332 ] ) ;
V_551:
if ( ! F_377 ( & V_123 ) ) {
* V_543 = 0 ;
goto V_534;
}
V_402 = F_374 ( & V_123 ) ;
if ( ! V_402 ) {
F_211 ( V_147 , V_552 [ V_332 ] ) ;
goto V_534;
}
V_480 = F_375 ( & V_123 , V_402 ) ;
if ( ! V_480 ) {
F_211 ( V_147 , V_553 [ V_332 ] ) ;
goto V_534;
}
F_153 ( V_480 == V_123 . V_133 ) ;
F_70 ( V_147 , V_554 [ V_332 ] , V_123 . V_406 ) ;
V_544 = 0 ;
if ( V_480 -> V_72 > 1 ) {
V_123 . V_185 |= V_457 ;
V_123 . V_132 = V_480 -> V_117 ;
V_123 . V_131 = V_480 ;
V_123 . V_469 = F_127 ( V_555 , V_480 -> V_72 ) ;
V_556:
F_383 ( V_185 ) ;
F_384 ( V_123 . V_133 , V_480 ) ;
V_545 = F_340 ( & V_123 ) ;
V_544 += V_545 ;
F_385 ( V_123 . V_133 , V_480 ) ;
F_386 ( V_185 ) ;
if ( V_545 && V_123 . V_128 != F_242 () )
F_387 ( V_123 . V_128 ) ;
if ( V_123 . V_185 & V_472 ) {
V_123 . V_185 &= ~ V_472 ;
goto V_556;
}
if ( ( V_123 . V_185 & V_455 ) && V_123 . V_406 > 0 ) {
F_388 ( V_123 . V_128 , V_123 . V_8 ) ;
V_123 . V_133 = F_100 ( V_123 . V_456 ) ;
V_123 . V_128 = V_123 . V_456 ;
V_123 . V_185 &= ~ V_455 ;
V_123 . V_468 = 0 ;
V_123 . V_470 = V_471 ;
goto V_556;
}
if ( V_547 ) {
int * V_557 = & V_547 -> V_403 -> V_409 -> V_406 ;
if ( ( V_123 . V_185 & V_453 ) && V_123 . V_406 > 0 ) {
* V_557 = 1 ;
} else if ( * V_557 )
* V_557 = 0 ;
}
if ( F_14 ( V_123 . V_185 & V_457 ) ) {
F_388 ( F_27 ( V_480 ) , V_8 ) ;
if ( ! F_389 ( V_8 ) ) {
V_123 . V_468 = 0 ;
V_123 . V_470 = V_471 ;
goto V_551;
}
goto V_534;
}
}
if ( ! V_544 ) {
F_211 ( V_147 , V_558 [ V_332 ] ) ;
if ( V_332 != V_474 )
V_147 -> V_461 ++ ;
if ( F_376 ( & V_123 ) ) {
F_346 ( & V_480 -> V_178 , V_185 ) ;
if ( ! F_110 ( V_389 ,
F_111 ( V_480 -> V_45 ) ) ) {
F_347 ( & V_480 -> V_178 ,
V_185 ) ;
V_123 . V_185 |= V_457 ;
goto V_559;
}
if ( ! V_480 -> V_546 ) {
V_480 -> V_546 = 1 ;
V_480 -> V_560 = V_389 ;
V_546 = 1 ;
}
F_347 ( & V_480 -> V_178 , V_185 ) ;
if ( V_546 ) {
F_390 ( F_27 ( V_480 ) ,
V_561 , V_480 ,
& V_480 -> V_562 ) ;
}
V_147 -> V_461 = V_147 -> V_462 + 1 ;
}
} else
V_147 -> V_461 = 0 ;
if ( F_12 ( ! V_546 ) ) {
V_147 -> V_499 = V_147 -> V_563 ;
} else {
if ( V_147 -> V_499 < V_147 -> V_564 )
V_147 -> V_499 *= 2 ;
}
goto V_239;
V_534:
F_211 ( V_147 , V_565 [ V_332 ] ) ;
V_147 -> V_461 = 0 ;
V_559:
if ( ( ( V_123 . V_185 & V_457 ) &&
V_147 -> V_499 < V_566 ) ||
( V_147 -> V_499 < V_147 -> V_564 ) )
V_147 -> V_499 *= 2 ;
V_544 = 0 ;
V_239:
return V_544 ;
}
void F_391 ( int V_389 , struct V_24 * V_284 )
{
struct V_146 * V_147 ;
int V_567 = 0 ;
unsigned long V_568 = V_155 + V_156 ;
T_2 V_569 = 0 ;
V_284 -> V_570 = F_76 ( V_284 ) ;
if ( V_284 -> V_571 < V_446 )
return;
F_248 ( & V_284 -> V_178 ) ;
F_345 ( V_389 ) ;
F_108 () ;
F_316 (this_cpu, sd) {
unsigned long V_498 ;
int V_543 = 1 ;
T_2 V_572 , V_573 ;
if ( ! ( V_147 -> V_185 & V_423 ) )
continue;
if ( V_284 -> V_571 < V_569 + V_147 -> V_574 )
break;
if ( V_147 -> V_185 & V_575 ) {
V_572 = F_241 ( V_389 ) ;
V_567 = F_380 ( V_389 , V_284 ,
V_147 , V_474 ,
& V_543 ) ;
V_573 = F_241 ( V_389 ) - V_572 ;
if ( V_573 > V_147 -> V_574 )
V_147 -> V_574 = V_573 ;
V_569 += V_573 ;
}
V_498 = F_128 ( V_147 -> V_499 ) ;
if ( F_154 ( V_568 , V_147 -> V_576 + V_498 ) )
V_568 = V_147 -> V_576 + V_498 ;
if ( V_567 ) {
V_284 -> V_570 = 0 ;
break;
}
}
F_114 () ;
F_246 ( & V_284 -> V_178 ) ;
if ( V_567 || F_154 ( V_155 , V_284 -> V_568 ) ) {
V_284 -> V_568 = V_568 ;
}
if ( V_569 > V_284 -> V_577 )
V_284 -> V_577 = V_569 ;
}
static int V_561 ( void * V_338 )
{
struct V_24 * V_578 = V_338 ;
int V_525 = F_27 ( V_578 ) ;
int V_579 = V_578 -> V_560 ;
struct V_24 * V_580 = F_100 ( V_579 ) ;
struct V_146 * V_147 ;
F_392 ( & V_578 -> V_178 ) ;
if ( F_14 ( V_525 != F_242 () ||
! V_578 -> V_546 ) )
goto V_351;
if ( V_578 -> V_72 <= 1 )
goto V_351;
F_153 ( V_578 == V_580 ) ;
F_393 ( V_578 , V_580 ) ;
F_108 () ;
F_316 (target_cpu, sd) {
if ( ( V_147 -> V_185 & V_423 ) &&
F_110 ( V_525 , F_317 ( V_147 ) ) )
break;
}
if ( F_12 ( V_147 ) ) {
struct V_444 V_123 = {
. V_147 = V_147 ,
. V_128 = V_579 ,
. V_133 = V_580 ,
. V_132 = V_578 -> V_117 ,
. V_131 = V_578 ,
. V_332 = V_533 ,
} ;
F_211 ( V_147 , V_581 ) ;
if ( F_338 ( & V_123 ) )
F_211 ( V_147 , V_582 ) ;
else
F_211 ( V_147 , V_583 ) ;
}
F_114 () ;
F_394 ( V_578 , V_580 ) ;
V_351:
V_578 -> V_546 = 0 ;
F_395 ( & V_578 -> V_178 ) ;
return 0 ;
}
static inline int F_396 ( int V_584 )
{
int V_585 = F_397 ( V_586 . V_587 ) ;
if ( V_585 < V_588 && F_311 ( V_585 ) )
return V_585 ;
return V_588 ;
}
static void F_398 ( int V_117 )
{
int V_589 ;
V_586 . V_568 ++ ;
V_589 = F_396 ( V_117 ) ;
if ( V_589 >= V_588 )
return;
if ( F_399 ( V_590 , F_400 ( V_589 ) ) )
return;
F_401 ( V_589 ) ;
return;
}
static inline void F_402 ( int V_117 )
{
if ( F_14 ( F_403 ( V_591 , F_400 ( V_117 ) ) ) ) {
F_388 ( V_117 , V_586 . V_587 ) ;
F_404 ( & V_586 . V_592 ) ;
F_405 ( V_591 , F_400 ( V_117 ) ) ;
}
}
static inline void F_406 ( void )
{
struct V_146 * V_147 ;
int V_117 = F_242 () ;
F_108 () ;
V_147 = F_118 ( F_119 ( V_593 , V_117 ) ) ;
if ( ! V_147 || ! V_147 -> V_594 )
goto V_138;
V_147 -> V_594 = 0 ;
F_407 ( & V_147 -> V_403 -> V_409 -> V_595 ) ;
V_138:
F_114 () ;
}
void F_408 ( void )
{
struct V_146 * V_147 ;
int V_117 = F_242 () ;
F_108 () ;
V_147 = F_118 ( F_119 ( V_593 , V_117 ) ) ;
if ( ! V_147 || V_147 -> V_594 )
goto V_138;
V_147 -> V_594 = 1 ;
F_404 ( & V_147 -> V_403 -> V_409 -> V_595 ) ;
V_138:
F_114 () ;
}
void F_409 ( int V_117 )
{
if ( ! F_410 ( V_117 ) )
return;
if ( F_403 ( V_591 , F_400 ( V_117 ) ) )
return;
F_411 ( V_117 , V_586 . V_587 ) ;
F_407 ( & V_586 . V_592 ) ;
F_412 ( V_591 , F_400 ( V_117 ) ) ;
}
static int F_413 ( struct V_596 * V_597 ,
unsigned long V_598 , void * V_599 )
{
switch ( V_598 & ~ V_600 ) {
case V_601 :
F_402 ( F_242 () ) ;
return V_602 ;
default:
return V_603 ;
}
}
void F_414 ( void )
{
V_500 = V_156 * F_6 () / 10 ;
}
static void F_415 ( int V_117 , enum V_484 V_332 )
{
int V_543 = 1 ;
struct V_24 * V_24 = F_100 ( V_117 ) ;
unsigned long V_498 ;
struct V_146 * V_147 ;
unsigned long V_568 = V_155 + 60 * V_156 ;
int V_604 = 0 ;
int V_605 , V_606 = 0 ;
T_2 V_607 = 0 ;
F_345 ( V_117 ) ;
F_108 () ;
F_316 (cpu, sd) {
if ( F_154 ( V_155 , V_147 -> V_608 ) ) {
V_147 -> V_574 =
( V_147 -> V_574 * 253 ) / 256 ;
V_147 -> V_608 = V_155 + V_156 ;
V_606 = 1 ;
}
V_607 += V_147 -> V_574 ;
if ( ! ( V_147 -> V_185 & V_423 ) )
continue;
if ( ! V_543 ) {
if ( V_606 )
continue;
break;
}
V_498 = V_147 -> V_499 ;
if ( V_332 != V_533 )
V_498 *= V_147 -> V_609 ;
V_498 = F_128 ( V_498 ) ;
V_498 = F_129 ( V_498 , 1UL , V_500 ) ;
V_605 = V_147 -> V_185 & V_610 ;
if ( V_605 ) {
if ( ! F_416 ( & V_611 ) )
goto V_239;
}
if ( F_370 ( V_155 , V_147 -> V_576 + V_498 ) ) {
if ( F_380 ( V_117 , V_24 , V_147 , V_332 , & V_543 ) ) {
V_332 = F_311 ( V_117 ) ? V_533 : V_485 ;
}
V_147 -> V_576 = V_155 ;
}
if ( V_605 )
F_132 ( & V_611 ) ;
V_239:
if ( F_154 ( V_568 , V_147 -> V_576 + V_498 ) ) {
V_568 = V_147 -> V_576 + V_498 ;
V_604 = 1 ;
}
}
if ( V_606 ) {
V_24 -> V_577 =
F_69 ( ( T_2 ) V_446 , V_607 ) ;
}
F_114 () ;
if ( F_12 ( V_604 ) )
V_24 -> V_568 = V_568 ;
}
static void F_417 ( int V_389 , enum V_484 V_332 )
{
struct V_24 * V_284 = F_100 ( V_389 ) ;
struct V_24 * V_24 ;
int V_542 ;
if ( V_332 != V_533 ||
! F_403 ( V_590 , F_400 ( V_389 ) ) )
goto V_220;
F_99 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_542 == V_389 || ! F_311 ( V_542 ) )
continue;
if ( F_418 () )
break;
V_24 = F_100 ( V_542 ) ;
F_392 ( & V_24 -> V_178 ) ;
F_258 ( V_24 ) ;
F_419 ( V_24 ) ;
F_395 ( & V_24 -> V_178 ) ;
F_415 ( V_542 , V_533 ) ;
if ( F_154 ( V_284 -> V_568 , V_24 -> V_568 ) )
V_284 -> V_568 = V_24 -> V_568 ;
}
V_586 . V_568 = V_284 -> V_568 ;
V_220:
F_405 ( V_590 , F_400 ( V_389 ) ) ;
}
static inline int F_420 ( struct V_24 * V_24 , int V_117 )
{
unsigned long V_81 = V_155 ;
struct V_146 * V_147 ;
struct V_503 * V_409 ;
int V_612 ;
if ( F_14 ( F_311 ( V_117 ) ) )
return 0 ;
F_406 () ;
F_402 ( V_117 ) ;
if ( F_12 ( ! F_190 ( & V_586 . V_592 ) ) )
return 0 ;
if ( F_157 ( V_81 , V_586 . V_568 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_613;
F_108 () ;
V_147 = F_118 ( F_119 ( V_593 , V_117 ) ) ;
if ( V_147 ) {
V_409 = V_147 -> V_403 -> V_409 ;
V_612 = F_190 ( & V_409 -> V_595 ) ;
if ( V_612 > 1 )
goto V_614;
}
V_147 = F_118 ( F_119 ( V_615 , V_117 ) ) ;
if ( V_147 && ( F_314 ( V_586 . V_587 ,
F_317 ( V_147 ) ) < V_117 ) )
goto V_614;
F_114 () ;
return 0 ;
V_614:
F_114 () ;
V_613:
return 1 ;
}
static void F_417 ( int V_389 , enum V_484 V_332 ) { }
static void F_421 ( struct V_616 * V_617 )
{
int V_389 = F_242 () ;
struct V_24 * V_284 = F_100 ( V_389 ) ;
enum V_484 V_332 = V_284 -> F_391 ?
V_533 : V_485 ;
F_415 ( V_389 , V_332 ) ;
F_417 ( V_389 , V_332 ) ;
}
static inline int F_422 ( int V_117 )
{
return ! F_423 ( F_100 ( V_117 ) -> V_147 ) ;
}
void F_424 ( struct V_24 * V_24 , int V_117 )
{
if ( F_370 ( V_155 , V_24 -> V_568 ) &&
F_12 ( ! F_422 ( V_117 ) ) )
F_425 ( V_618 ) ;
#ifdef F_426
if ( F_420 ( V_24 , V_117 ) && F_12 ( ! F_422 ( V_117 ) ) )
F_398 ( V_117 ) ;
#endif
}
static void F_427 ( struct V_24 * V_24 )
{
F_8 () ;
}
static void F_428 ( struct V_24 * V_24 )
{
F_8 () ;
F_283 ( V_24 ) ;
}
static void F_429 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_312 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_229 ( V_25 , V_28 , V_312 ) ;
}
if ( V_204 )
F_166 ( V_24 , V_45 ) ;
F_198 ( V_24 , 1 ) ;
}
static void F_430 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_389 = F_242 () ;
struct V_24 * V_24 = V_284 () ;
unsigned long V_185 ;
F_346 ( & V_24 -> V_178 , V_185 ) ;
F_258 ( V_24 ) ;
V_25 = F_23 ( V_197 ) ;
V_45 = V_25 -> V_45 ;
F_108 () ;
F_431 ( V_29 , V_389 ) ;
F_114 () ;
F_66 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_212 ( V_25 , V_28 , 1 ) ;
if ( V_619 && V_45 && F_41 ( V_45 , V_28 ) ) {
F_113 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_223 ( V_24 -> V_45 ) ;
}
V_28 -> V_41 -= V_25 -> F_40 ;
F_347 ( & V_24 -> V_178 , V_185 ) ;
}
static void
F_432 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_620 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_621 > V_620 )
F_223 ( V_24 -> V_45 ) ;
} else
F_332 ( V_24 , V_29 , 0 ) ;
}
static void F_433 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 && V_29 -> V_205 != V_622 ) {
F_212 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_40 ;
}
#ifdef F_170
if ( V_28 -> V_77 . V_78 ) {
F_182 ( V_28 ) ;
F_193 ( V_25 , V_28 -> V_77 . V_268 ) ;
}
#endif
}
static void F_434 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_223 ( V_24 -> V_45 ) ;
else
F_332 ( V_24 , V_29 , 0 ) ;
}
static void F_435 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_224 ( V_25 , V_28 ) ;
F_74 ( V_25 , 0 ) ;
}
}
void F_436 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_623 ;
V_25 -> F_40 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_44
V_25 -> V_48 = V_25 -> F_40 ;
#endif
#ifdef F_170
F_437 ( & V_25 -> V_267 , 1 ) ;
F_438 ( & V_25 -> V_281 , 0 ) ;
#endif
}
static void F_439 ( struct V_26 * V_29 , int V_76 )
{
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_29 -> V_28 . V_85 || V_29 -> V_205 == V_624 ) )
V_76 = 1 ;
if ( ! V_76 )
V_29 -> V_28 . V_41 -= F_24 ( & V_29 -> V_28 ) -> F_40 ;
F_440 ( V_29 , F_117 ( V_29 ) ) ;
if ( ! V_76 ) {
V_25 = F_24 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_41 += V_25 -> F_40 ;
#ifdef F_170
V_29 -> V_28 . V_77 . V_78 = F_183 ( & V_25 -> V_267 ) ;
V_25 -> V_272 += V_29 -> V_28 . V_77 . V_268 ;
#endif
}
}
void F_441 ( struct V_243 * V_33 )
{
int V_179 ;
F_281 ( F_244 ( V_33 ) ) ;
F_442 (i) {
if ( V_33 -> V_25 )
F_151 ( V_33 -> V_25 [ V_179 ] ) ;
if ( V_33 -> V_28 )
F_151 ( V_33 -> V_28 [ V_179 ] ) ;
}
F_151 ( V_33 -> V_25 ) ;
F_151 ( V_33 -> V_28 ) ;
}
int F_443 ( struct V_243 * V_33 , struct V_243 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_179 ;
V_33 -> V_25 = F_140 ( sizeof( V_25 ) * V_588 , V_191 ) ;
if ( ! V_33 -> V_25 )
goto V_625;
V_33 -> V_28 = F_140 ( sizeof( V_28 ) * V_588 , V_191 ) ;
if ( ! V_33 -> V_28 )
goto V_625;
V_33 -> V_247 = V_71 ;
F_275 ( F_244 ( V_33 ) ) ;
F_442 (i) {
V_25 = F_444 ( sizeof( struct V_25 ) ,
V_191 , F_120 ( V_179 ) ) ;
if ( ! V_25 )
goto V_625;
V_28 = F_444 ( sizeof( struct V_27 ) ,
V_191 , F_120 ( V_179 ) ) ;
if ( ! V_28 )
goto V_626;
F_436 ( V_25 ) ;
F_445 ( V_33 , V_25 , V_28 , V_179 , V_34 -> V_28 [ V_179 ] ) ;
}
return 1 ;
V_626:
F_151 ( V_25 ) ;
V_625:
return 0 ;
}
void F_446 ( struct V_243 * V_33 , int V_117 )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
unsigned long V_185 ;
if ( ! V_33 -> V_25 [ V_117 ] -> V_32 )
return;
F_346 ( & V_24 -> V_178 , V_185 ) ;
F_31 ( V_33 -> V_25 [ V_117 ] ) ;
F_347 ( & V_24 -> V_178 , V_185 ) ;
}
void F_445 ( struct V_243 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_117 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_100 ( V_117 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_278 ( V_25 ) ;
V_33 -> V_25 [ V_117 ] = V_25 ;
V_33 -> V_28 [ V_117 ] = V_28 ;
if ( ! V_28 )
return;
if ( ! V_34 )
V_28 -> V_25 = & V_24 -> V_40 ;
else
V_28 -> V_25 = V_34 -> V_31 ;
V_28 -> V_31 = V_25 ;
F_3 ( & V_28 -> V_70 , V_71 ) ;
V_28 -> V_34 = V_34 ;
}
int F_447 ( struct V_243 * V_33 , unsigned long V_247 )
{
int V_179 ;
unsigned long V_185 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_151 ;
V_247 = F_129 ( V_247 , F_191 ( V_248 ) , F_191 ( V_627 ) ) ;
F_448 ( & V_628 ) ;
if ( V_33 -> V_247 == V_247 )
goto V_413;
V_33 -> V_247 = V_247 ;
F_442 (i) {
struct V_24 * V_24 = F_100 ( V_179 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_179 ] ;
F_346 ( & V_24 -> V_178 , V_185 ) ;
F_258 ( V_24 ) ;
F_36 (se)
F_177 ( F_25 ( V_28 ) ) ;
F_347 ( & V_24 -> V_178 , V_185 ) ;
}
V_413:
F_449 ( & V_628 ) ;
return 0 ;
}
void F_441 ( struct V_243 * V_33 ) { }
int F_443 ( struct V_243 * V_33 , struct V_243 * V_34 )
{
return 1 ;
}
void F_446 ( struct V_243 * V_33 , int V_117 ) { }
static unsigned int F_450 ( struct V_24 * V_24 , struct V_26 * V_629 )
{
struct V_27 * V_28 = & V_629 -> V_28 ;
unsigned int V_630 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_630 = F_451 ( F_62 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_630 ;
}
void F_452 ( struct V_631 * V_632 , int V_117 )
{
struct V_25 * V_25 ;
F_108 () ;
F_284 (cpu_rq(cpu), cfs_rq)
F_453 ( V_632 , V_117 , V_25 ) ;
F_114 () ;
}
T_12 void F_454 ( void )
{
#ifdef F_170
F_455 ( V_618 , F_421 ) ;
#ifdef F_426
V_586 . V_568 = V_155 ;
F_456 ( & V_586 . V_587 , V_633 ) ;
F_457 ( F_413 , 0 ) ;
#endif
#endif
}
