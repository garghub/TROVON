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
F_18 ( ! F_19 ( V_28 ) ) ;
return F_20 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_25 * F_21 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_25 ;
}
static inline struct V_25 * F_22 ( struct V_27 * V_28 )
{
return V_28 -> V_25 ;
}
static inline struct V_25 * F_23 ( struct V_27 * V_30 )
{
return V_30 -> V_31 ;
}
static inline void F_24 ( struct V_25 * V_25 )
{
if ( ! V_25 -> V_32 ) {
if ( V_25 -> V_33 -> V_34 &&
V_25 -> V_33 -> V_34 -> V_25 [ F_25 ( F_16 ( V_25 ) ) ] -> V_32 ) {
F_26 ( & V_25 -> V_35 ,
& F_16 ( V_25 ) -> V_35 ) ;
} else {
F_27 ( & V_25 -> V_35 ,
& F_16 ( V_25 ) -> V_35 ) ;
}
V_25 -> V_32 = 1 ;
}
}
static inline void F_28 ( struct V_25 * V_25 )
{
if ( V_25 -> V_32 ) {
F_29 ( & V_25 -> V_35 ) ;
V_25 -> V_32 = 0 ;
}
}
static inline struct V_25 *
F_30 ( struct V_27 * V_28 , struct V_27 * V_36 )
{
if ( V_28 -> V_25 == V_36 -> V_25 )
return V_28 -> V_25 ;
return NULL ;
}
static inline struct V_27 * F_31 ( struct V_27 * V_28 )
{
return V_28 -> V_34 ;
}
static void
F_32 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
int V_37 , V_38 ;
V_37 = ( * V_28 ) -> V_39 ;
V_38 = ( * V_36 ) -> V_39 ;
while ( V_37 > V_38 ) {
V_37 -- ;
* V_28 = F_31 ( * V_28 ) ;
}
while ( V_38 > V_37 ) {
V_38 -- ;
* V_36 = F_31 ( * V_36 ) ;
}
while ( ! F_30 ( * V_28 , * V_36 ) ) {
* V_28 = F_31 ( * V_28 ) ;
* V_36 = F_31 ( * V_36 ) ;
}
}
static inline struct V_26 * F_17 ( struct V_27 * V_28 )
{
return F_20 ( V_28 , struct V_26 , V_28 ) ;
}
static inline struct V_24 * F_16 ( struct V_25 * V_25 )
{
return F_20 ( V_25 , struct V_24 , V_40 ) ;
}
static inline struct V_25 * F_21 ( struct V_26 * V_29 )
{
return & F_33 ( V_29 ) -> V_40 ;
}
static inline struct V_25 * F_22 ( struct V_27 * V_28 )
{
struct V_26 * V_29 = F_17 ( V_28 ) ;
struct V_24 * V_24 = F_33 ( V_29 ) ;
return & V_24 -> V_40 ;
}
static inline struct V_25 * F_23 ( struct V_27 * V_30 )
{
return NULL ;
}
static inline void F_24 ( struct V_25 * V_25 )
{
}
static inline void F_28 ( struct V_25 * V_25 )
{
}
static inline struct V_27 * F_31 ( struct V_27 * V_28 )
{
return NULL ;
}
static inline void
F_32 ( struct V_27 * * V_28 , struct V_27 * * V_36 )
{
}
static inline T_2 F_34 ( T_2 F_34 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_34 ) ;
if ( V_42 > 0 )
F_34 = V_41 ;
return F_34 ;
}
static inline T_2 F_35 ( T_2 F_35 , T_2 V_41 )
{
T_3 V_42 = ( T_3 ) ( V_41 - F_35 ) ;
if ( V_42 < 0 )
F_35 = V_41 ;
return F_35 ;
}
static inline int F_36 ( struct V_27 * V_43 ,
struct V_27 * V_44 )
{
return ( T_3 ) ( V_43 -> V_41 - V_44 -> V_41 ) < 0 ;
}
static void F_37 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_41 = V_25 -> F_35 ;
if ( V_45 ) {
if ( V_45 -> V_46 )
V_41 = V_45 -> V_41 ;
else
V_45 = NULL ;
}
if ( V_25 -> V_47 ) {
struct V_27 * V_28 = F_38 ( V_25 -> V_47 ,
struct V_27 ,
V_48 ) ;
if ( ! V_45 )
V_41 = V_28 -> V_41 ;
else
V_41 = F_35 ( V_41 , V_28 -> V_41 ) ;
}
V_25 -> F_35 = F_34 ( V_25 -> F_35 , V_41 ) ;
#ifndef F_39
F_40 () ;
V_25 -> V_49 = V_25 -> F_35 ;
#endif
}
static void F_41 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_50 * * V_51 = & V_25 -> V_52 . V_50 ;
struct V_50 * V_34 = NULL ;
struct V_27 * V_53 ;
int V_54 = 1 ;
while ( * V_51 ) {
V_34 = * V_51 ;
V_53 = F_38 ( V_34 , struct V_27 , V_48 ) ;
if ( F_36 ( V_28 , V_53 ) ) {
V_51 = & V_34 -> V_55 ;
} else {
V_51 = & V_34 -> V_56 ;
V_54 = 0 ;
}
}
if ( V_54 )
V_25 -> V_47 = & V_28 -> V_48 ;
F_42 ( & V_28 -> V_48 , V_34 , V_51 ) ;
F_43 ( & V_28 -> V_48 , & V_25 -> V_52 ) ;
}
static void F_44 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_47 == & V_28 -> V_48 ) {
struct V_50 * V_57 ;
V_57 = F_45 ( & V_28 -> V_48 ) ;
V_25 -> V_47 = V_57 ;
}
F_46 ( & V_28 -> V_48 , & V_25 -> V_52 ) ;
}
struct V_27 * F_47 ( struct V_25 * V_25 )
{
struct V_50 * V_58 = V_25 -> V_47 ;
if ( ! V_58 )
return NULL ;
return F_38 ( V_58 , struct V_27 , V_48 ) ;
}
static struct V_27 * F_48 ( struct V_27 * V_28 )
{
struct V_50 * V_59 = F_45 ( & V_28 -> V_48 ) ;
if ( ! V_59 )
return NULL ;
return F_38 ( V_59 , struct V_27 , V_48 ) ;
}
struct V_27 * F_49 ( struct V_25 * V_25 )
{
struct V_50 * V_60 = F_50 ( & V_25 -> V_52 ) ;
if ( ! V_60 )
return NULL ;
return F_38 ( V_60 , struct V_27 , V_48 ) ;
}
int F_51 ( struct V_61 * V_62 , int V_63 ,
void T_4 * V_64 , T_5 * V_65 ,
T_6 * V_66 )
{
int V_67 = F_52 ( V_62 , V_63 , V_64 , V_65 , V_66 ) ;
unsigned int V_9 = F_4 () ;
if ( V_67 || ! V_63 )
return V_67 ;
V_68 = F_53 ( V_69 ,
V_70 ) ;
#define F_54 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_54 ( V_14 ) ;
F_54 ( V_15 ) ;
F_54 ( V_16 ) ;
#undef F_54
return 0 ;
}
static inline T_2 F_55 ( T_2 V_42 , struct V_27 * V_28 )
{
if ( F_13 ( V_28 -> V_71 . V_4 != V_72 ) )
V_42 = F_14 ( V_42 , V_72 , & V_28 -> V_71 ) ;
return V_42 ;
}
static T_2 F_56 ( unsigned long V_73 )
{
if ( F_13 ( V_73 > V_68 ) )
return V_73 * V_70 ;
else
return V_69 ;
}
static T_2 F_57 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_74 = F_56 ( V_25 -> V_73 + ! V_28 -> V_46 ) ;
F_58 (se) {
struct V_1 * V_71 ;
struct V_1 V_2 ;
V_25 = F_22 ( V_28 ) ;
V_71 = & V_25 -> V_71 ;
if ( F_13 ( ! V_28 -> V_46 ) ) {
V_2 = V_25 -> V_71 ;
F_1 ( & V_2 , V_28 -> V_71 . V_4 ) ;
V_71 = & V_2 ;
}
V_74 = F_14 ( V_74 , V_28 -> V_71 . V_4 , V_71 ) ;
}
return V_74 ;
}
static T_2 F_59 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_55 ( F_57 ( V_25 , V_28 ) , V_28 ) ;
}
void F_60 ( struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
V_76 -> V_78 = 0 ;
V_76 -> V_79 = 1023 ;
if ( F_19 ( V_28 ) )
V_76 -> V_80 = F_12 ( V_28 -> V_71 . V_4 ) ;
V_76 -> V_81 = V_76 -> V_80 * V_82 ;
V_76 -> V_83 = 0 ;
V_76 -> V_84 = 0 ;
}
void F_61 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_22 ( V_28 ) ;
struct V_75 * V_76 = & V_28 -> V_77 ;
long V_85 = ( long ) ( V_86 - V_25 -> V_77 . V_83 ) / 2 ;
T_2 V_87 = F_62 ( V_25 ) ;
if ( V_85 > 0 ) {
if ( V_25 -> V_77 . V_83 != 0 ) {
V_76 -> V_83 = V_25 -> V_77 . V_83 * V_28 -> V_71 . V_4 ;
V_76 -> V_83 /= ( V_25 -> V_77 . V_80 + 1 ) ;
if ( V_76 -> V_83 > V_85 )
V_76 -> V_83 = V_85 ;
} else {
V_76 -> V_83 = V_85 ;
}
V_76 -> V_84 = V_76 -> V_83 * V_82 ;
}
if ( F_19 ( V_28 ) ) {
struct V_26 * V_29 = F_17 ( V_28 ) ;
if ( V_29 -> V_88 != & V_89 ) {
V_28 -> V_77 . V_78 = V_87 ;
return;
}
}
F_63 ( V_87 , V_25 , false ) ;
F_64 ( V_25 , V_28 ) ;
F_65 ( V_25 , false ) ;
}
void F_60 ( struct V_27 * V_28 )
{
}
void F_61 ( struct V_27 * V_28 )
{
}
static void F_65 ( struct V_25 * V_25 , int V_90 )
{
}
static void F_66 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_87 = F_67 ( F_16 ( V_25 ) ) ;
T_2 V_19 ;
if ( F_13 ( ! V_45 ) )
return;
V_19 = V_87 - V_45 -> V_91 ;
if ( F_13 ( ( T_3 ) V_19 <= 0 ) )
return;
V_45 -> V_91 = V_87 ;
F_68 ( V_45 -> V_92 . V_93 ,
F_69 ( V_19 , V_45 -> V_92 . V_93 ) ) ;
V_45 -> V_94 += V_19 ;
F_70 ( V_25 -> V_95 , V_19 ) ;
V_45 -> V_41 += F_55 ( V_19 , V_45 ) ;
F_37 ( V_25 ) ;
if ( F_19 ( V_45 ) ) {
struct V_26 * V_96 = F_17 ( V_45 ) ;
F_71 ( V_96 , V_19 , V_45 -> V_41 ) ;
F_72 ( V_96 , V_19 ) ;
F_73 ( V_96 , V_19 ) ;
}
F_74 ( V_25 , V_19 ) ;
}
static void F_75 ( struct V_24 * V_24 )
{
F_66 ( F_22 ( & V_24 -> V_45 -> V_28 ) ) ;
}
static inline void
F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
T_2 V_97 , V_98 ;
if ( ! F_77 () )
return;
V_97 = F_78 ( F_16 ( V_25 ) ) ;
V_98 = F_79 ( V_28 -> V_92 . V_97 ) ;
if ( F_19 ( V_28 ) && F_80 ( F_17 ( V_28 ) ) &&
F_11 ( V_97 > V_98 ) )
V_97 -= V_98 ;
F_68 ( V_28 -> V_92 . V_97 , V_97 ) ;
}
static inline void
F_81 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_26 * V_29 ;
T_2 V_42 ;
if ( ! F_77 () )
return;
V_42 = F_78 ( F_16 ( V_25 ) ) - F_79 ( V_28 -> V_92 . V_97 ) ;
if ( F_19 ( V_28 ) ) {
V_29 = F_17 ( V_28 ) ;
if ( F_80 ( V_29 ) ) {
F_68 ( V_28 -> V_92 . V_97 , V_42 ) ;
return;
}
F_82 ( V_29 , V_42 ) ;
}
F_68 ( V_28 -> V_92 . V_99 ,
F_69 ( F_79 ( V_28 -> V_92 . V_99 ) , V_42 ) ) ;
F_83 ( V_28 -> V_92 . V_100 ) ;
F_70 ( V_28 -> V_92 . V_101 , V_42 ) ;
F_68 ( V_28 -> V_92 . V_97 , 0 ) ;
}
static inline void
F_84 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_26 * V_102 = NULL ;
T_2 V_103 , V_104 ;
if ( ! F_77 () )
return;
V_103 = F_79 ( V_28 -> V_92 . V_103 ) ;
V_104 = F_79 ( V_28 -> V_92 . V_104 ) ;
if ( F_19 ( V_28 ) )
V_102 = F_17 ( V_28 ) ;
if ( V_103 ) {
T_2 V_42 = F_78 ( F_16 ( V_25 ) ) - V_103 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > F_79 ( V_28 -> V_92 . V_105 ) ) )
F_68 ( V_28 -> V_92 . V_105 , V_42 ) ;
F_68 ( V_28 -> V_92 . V_103 , 0 ) ;
F_70 ( V_28 -> V_92 . V_106 , V_42 ) ;
if ( V_102 ) {
F_85 ( V_102 , V_42 >> 10 , 1 ) ;
F_86 ( V_102 , V_42 ) ;
}
}
if ( V_104 ) {
T_2 V_42 = F_78 ( F_16 ( V_25 ) ) - V_104 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_13 ( V_42 > F_79 ( V_28 -> V_92 . V_107 ) ) )
F_68 ( V_28 -> V_92 . V_107 , V_42 ) ;
F_68 ( V_28 -> V_92 . V_104 , 0 ) ;
F_70 ( V_28 -> V_92 . V_106 , V_42 ) ;
if ( V_102 ) {
if ( V_102 -> V_108 ) {
F_70 ( V_28 -> V_92 . V_109 , V_42 ) ;
F_83 ( V_28 -> V_92 . V_110 ) ;
F_87 ( V_102 , V_42 ) ;
}
F_88 ( V_102 , V_42 ) ;
if ( F_13 ( V_111 == V_112 ) ) {
F_89 ( V_112 ,
( void * ) F_90 ( V_102 ) ,
V_42 >> 20 ) ;
}
F_85 ( V_102 , V_42 >> 10 , 0 ) ;
}
}
}
static inline void
F_91 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_113 )
{
if ( ! F_77 () )
return;
if ( V_28 != V_25 -> V_45 )
F_76 ( V_25 , V_28 ) ;
if ( V_113 & V_114 )
F_84 ( V_25 , V_28 ) ;
}
static inline void
F_92 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_113 )
{
if ( ! F_77 () )
return;
if ( V_28 != V_25 -> V_45 )
F_81 ( V_25 , V_28 ) ;
if ( ( V_113 & V_115 ) && F_19 ( V_28 ) ) {
struct V_26 * V_102 = F_17 ( V_28 ) ;
if ( V_102 -> V_116 & V_117 )
F_68 ( V_28 -> V_92 . V_103 ,
F_78 ( F_16 ( V_25 ) ) ) ;
if ( V_102 -> V_116 & V_118 )
F_68 ( V_28 -> V_92 . V_104 ,
F_78 ( F_16 ( V_25 ) ) ) ;
}
}
static inline void
F_93 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_91 = F_67 ( F_16 ( V_25 ) ) ;
}
static unsigned int F_94 ( struct V_26 * V_29 )
{
unsigned long V_119 = 0 ;
unsigned long V_120 ;
V_120 = V_121 << ( 20 - V_122 ) ;
V_119 = F_95 ( V_29 -> V_123 ) ;
if ( ! V_119 )
V_119 = V_120 ;
V_119 = F_96 ( V_119 , V_120 ) ;
return V_119 / V_120 ;
}
static unsigned int F_97 ( struct V_26 * V_29 )
{
unsigned int V_124 = F_98 ( V_121 ) ;
unsigned int V_125 , floor ;
unsigned int V_126 = 1 ;
if ( V_124 < V_127 )
V_126 = V_127 / V_124 ;
floor = 1000 / V_126 ;
V_125 = V_128 / F_94 ( V_29 ) ;
return F_99 (unsigned int, floor, scan) ;
}
static unsigned int F_100 ( struct V_26 * V_29 )
{
unsigned int V_129 = F_97 ( V_29 ) ;
unsigned int V_130 ;
V_130 = V_131 / F_94 ( V_29 ) ;
return F_69 ( V_129 , V_130 ) ;
}
static void F_101 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_132 += ( V_29 -> V_133 != - 1 ) ;
V_24 -> V_134 += ( V_29 -> V_133 == F_102 ( V_29 ) ) ;
}
static void F_103 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
V_24 -> V_132 -= ( V_29 -> V_133 != - 1 ) ;
V_24 -> V_134 -= ( V_29 -> V_133 == F_102 ( V_29 ) ) ;
}
T_7 F_104 ( struct V_26 * V_29 )
{
return V_29 -> V_135 ? V_29 -> V_135 -> V_136 : 0 ;
}
static inline int F_105 ( enum V_137 V_138 , int V_139 , int V_140 )
{
return V_141 * ( V_138 * V_142 + V_139 ) + V_140 ;
}
static inline unsigned long F_106 ( struct V_26 * V_29 , int V_139 )
{
if ( ! V_29 -> V_143 )
return 0 ;
return V_29 -> V_143 [ F_105 ( V_144 , V_139 , 0 ) ] +
V_29 -> V_143 [ F_105 ( V_144 , V_139 , 1 ) ] ;
}
static inline unsigned long F_107 ( struct V_26 * V_29 , int V_139 )
{
if ( ! V_29 -> V_135 )
return 0 ;
return V_29 -> V_135 -> V_145 [ F_105 ( V_144 , V_139 , 0 ) ] +
V_29 -> V_135 -> V_145 [ F_105 ( V_144 , V_139 , 1 ) ] ;
}
static inline unsigned long F_108 ( struct V_135 * V_146 , int V_139 )
{
return V_146 -> V_147 [ F_105 ( V_144 , V_139 , 0 ) ] +
V_146 -> V_147 [ F_105 ( V_144 , V_139 , 1 ) ] ;
}
static bool F_109 ( int V_139 , struct V_135 * V_148 )
{
return F_108 ( V_148 , V_139 ) * V_149 > V_148 -> V_150 ;
}
static unsigned long F_110 ( struct V_26 * V_29 , int V_139 ,
int V_151 , bool V_152 )
{
unsigned long V_153 = 0 ;
int V_154 ;
if ( V_155 == V_156 )
return 0 ;
F_111 (node) {
unsigned long V_145 ;
int V_157 = F_112 ( V_139 , V_154 ) ;
if ( V_157 == V_158 || V_154 == V_139 )
continue;
if ( V_155 == V_159 &&
V_157 > V_151 )
continue;
if ( V_152 )
V_145 = F_106 ( V_29 , V_154 ) ;
else
V_145 = F_107 ( V_29 , V_154 ) ;
if ( V_155 == V_160 ) {
V_145 *= ( V_158 - V_157 ) ;
V_145 /= ( V_158 - V_161 ) ;
}
V_153 += V_145 ;
}
return V_153 ;
}
static inline unsigned long F_113 ( struct V_26 * V_29 , int V_139 ,
int V_157 )
{
unsigned long V_145 , V_162 ;
if ( ! V_29 -> V_143 )
return 0 ;
V_162 = V_29 -> V_163 ;
if ( ! V_162 )
return 0 ;
V_145 = F_106 ( V_29 , V_139 ) ;
V_145 += F_110 ( V_29 , V_139 , V_157 , true ) ;
return 1000 * V_145 / V_162 ;
}
static inline unsigned long F_114 ( struct V_26 * V_29 , int V_139 ,
int V_157 )
{
unsigned long V_145 , V_162 ;
if ( ! V_29 -> V_135 )
return 0 ;
V_162 = V_29 -> V_135 -> V_162 ;
if ( ! V_162 )
return 0 ;
V_145 = F_107 ( V_29 , V_139 ) ;
V_145 += F_110 ( V_29 , V_139 , V_157 , false ) ;
return 1000 * V_145 / V_162 ;
}
bool F_115 ( struct V_26 * V_29 , struct V_164 * V_164 ,
int V_165 , int V_166 )
{
struct V_135 * V_148 = V_29 -> V_135 ;
int V_167 = F_116 ( V_166 ) ;
int V_168 , V_169 ;
V_169 = F_117 ( V_166 , V_170 -> V_171 ) ;
V_168 = F_118 ( V_164 , V_169 ) ;
if ( ! F_119 ( V_168 ) &&
F_120 ( V_168 ) != V_167 )
return false ;
if ( F_121 ( V_29 , V_168 ) )
return true ;
if ( ! V_148 )
return true ;
if ( F_108 ( V_148 , V_167 ) > F_108 ( V_148 , V_165 ) *
V_149 )
return true ;
return F_108 ( V_148 , V_167 ) * F_107 ( V_29 , V_165 ) * 3 >
F_108 ( V_148 , V_165 ) * F_107 ( V_29 , V_167 ) * 4 ;
}
static void F_122 ( struct V_172 * V_173 , int V_139 )
{
int V_174 , V_175 , V_8 = 0 ;
unsigned long V_176 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
F_123 (cpu, cpumask_of_node(nid)) {
struct V_24 * V_24 = F_124 ( V_175 ) ;
V_173 -> V_73 += V_24 -> V_73 ;
V_173 -> V_71 += F_125 ( V_175 ) ;
V_173 -> V_177 += F_126 ( V_175 ) ;
V_8 ++ ;
}
if ( ! V_8 )
return;
V_174 = F_53 ( V_86 * V_8 , V_173 -> V_177 ) ;
V_176 = V_8 / V_174 ;
V_173 -> V_178 = F_5 ( unsigned , V_176 ,
F_127 ( V_173 -> V_177 , V_86 ) ) ;
V_173 -> V_179 = ( V_173 -> V_73 < V_173 -> V_178 ) ;
}
static void F_128 ( struct V_180 * V_181 ,
struct V_26 * V_29 , long V_182 )
{
if ( V_181 -> V_183 )
F_129 ( V_181 -> V_183 ) ;
if ( V_29 )
F_130 ( V_29 ) ;
V_181 -> V_183 = V_29 ;
V_181 -> V_184 = V_182 ;
V_181 -> V_185 = V_181 -> V_166 ;
}
static bool F_131 ( long V_186 , long V_187 ,
struct V_180 * V_181 )
{
long V_188 , V_189 ;
long V_190 , V_191 ;
long V_192 , V_193 ;
V_192 = V_181 -> V_194 . V_177 ;
V_193 = V_181 -> V_195 . V_177 ;
if ( V_187 < V_186 )
F_132 ( V_187 , V_186 ) ;
V_188 = V_187 * V_192 * 100 -
V_186 * V_193 * V_181 -> V_196 ;
if ( V_188 <= 0 )
return false ;
V_190 = V_181 -> V_194 . V_71 ;
V_191 = V_181 -> V_195 . V_71 ;
if ( V_191 < V_190 )
F_132 ( V_191 , V_190 ) ;
V_189 = V_191 * V_192 * 100 -
V_190 * V_193 * V_181 -> V_196 ;
return ( V_188 > V_189 ) ;
}
static void F_133 ( struct V_180 * V_181 ,
long V_197 , long V_198 )
{
struct V_24 * V_199 = F_124 ( V_181 -> V_200 ) ;
struct V_24 * V_201 = F_124 ( V_181 -> V_166 ) ;
struct V_26 * V_202 ;
long V_186 , V_187 ;
long V_71 ;
long V_182 = V_181 -> V_29 -> V_135 ? V_198 : V_197 ;
long V_203 = V_182 ;
int V_157 = V_181 -> V_157 ;
F_134 () ;
V_202 = F_135 ( & V_201 -> V_45 ) ;
if ( V_202 && ( ( V_202 -> V_113 & V_204 ) || F_136 ( V_202 ) ) )
V_202 = NULL ;
if ( V_202 == V_181 -> V_29 )
goto V_205;
if ( V_202 ) {
if ( ! F_137 ( V_181 -> V_200 , F_138 ( V_202 ) ) )
goto V_205;
if ( V_202 -> V_135 == V_181 -> V_29 -> V_135 ) {
V_182 = V_197 + F_113 ( V_202 , V_181 -> V_165 , V_157 ) -
F_113 ( V_202 , V_181 -> V_167 , V_157 ) ;
if ( V_202 -> V_135 )
V_182 -= V_182 / 16 ;
} else {
if ( V_202 -> V_135 )
V_182 += F_114 ( V_202 , V_181 -> V_165 , V_157 ) -
F_114 ( V_202 , V_181 -> V_167 , V_157 ) ;
else
V_182 += F_113 ( V_202 , V_181 -> V_165 , V_157 ) -
F_113 ( V_202 , V_181 -> V_167 , V_157 ) ;
}
}
if ( V_182 <= V_181 -> V_184 && V_203 <= V_181 -> V_184 )
goto V_205;
if ( ! V_202 ) {
if ( V_181 -> V_194 . V_73 <= V_181 -> V_194 . V_178 &&
! V_181 -> V_195 . V_179 )
goto V_205;
goto V_206;
}
if ( V_182 > V_181 -> V_184 && V_199 -> V_73 == 1 &&
V_201 -> V_73 == 1 )
goto V_207;
V_206:
V_71 = F_139 ( V_181 -> V_29 ) ;
V_187 = V_181 -> V_195 . V_71 + V_71 ;
V_186 = V_181 -> V_194 . V_71 - V_71 ;
if ( V_203 > V_182 && V_203 > V_181 -> V_184 ) {
if ( ! F_131 ( V_186 , V_187 , V_181 ) ) {
V_182 = V_203 - 1 ;
V_202 = NULL ;
goto V_207;
}
}
if ( V_182 <= V_181 -> V_184 )
goto V_205;
if ( V_202 ) {
V_71 = F_139 ( V_202 ) ;
V_187 -= V_71 ;
V_186 += V_71 ;
}
if ( F_131 ( V_186 , V_187 , V_181 ) )
goto V_205;
if ( ! V_202 ) {
F_140 () ;
V_181 -> V_166 = F_141 ( V_181 -> V_29 , V_181 -> V_200 ,
V_181 -> V_166 ) ;
F_142 () ;
}
V_207:
F_128 ( V_181 , V_202 , V_182 ) ;
V_205:
F_143 () ;
}
static void F_144 ( struct V_180 * V_181 ,
long V_197 , long V_198 )
{
int V_175 ;
F_123 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_137 ( V_175 , F_138 ( V_181 -> V_29 ) ) )
continue;
V_181 -> V_166 = V_175 ;
F_133 ( V_181 , V_197 , V_198 ) ;
}
}
static bool F_145 ( struct V_180 * V_181 )
{
struct V_172 * V_208 = & V_181 -> V_194 ;
struct V_172 * V_209 = & V_181 -> V_195 ;
if ( V_208 -> V_179 && ! V_209 -> V_179 )
return false ;
if ( V_208 -> V_71 * V_209 -> V_177 * V_181 -> V_196 >
V_209 -> V_71 * V_208 -> V_177 * 100 )
return true ;
return false ;
}
static int F_146 ( struct V_26 * V_29 )
{
struct V_180 V_181 = {
. V_29 = V_29 ,
. V_200 = F_147 ( V_29 ) ,
. V_165 = F_102 ( V_29 ) ,
. V_196 = 112 ,
. V_183 = NULL ,
. V_184 = 0 ,
. V_185 = - 1 ,
} ;
struct V_210 * V_211 ;
unsigned long V_212 , V_213 ;
int V_139 , V_67 , V_157 ;
long V_197 , V_198 ;
F_134 () ;
V_211 = F_148 ( F_149 ( V_214 , V_181 . V_200 ) ) ;
if ( V_211 )
V_181 . V_196 = 100 + ( V_211 -> V_196 - 100 ) / 2 ;
F_143 () ;
if ( F_13 ( ! V_211 ) ) {
V_29 -> V_133 = F_102 ( V_29 ) ;
return - V_215 ;
}
V_181 . V_167 = V_29 -> V_133 ;
V_157 = V_181 . V_157 = F_112 ( V_181 . V_165 , V_181 . V_167 ) ;
V_212 = F_113 ( V_29 , V_181 . V_165 , V_157 ) ;
V_213 = F_114 ( V_29 , V_181 . V_165 , V_157 ) ;
F_122 ( & V_181 . V_194 , V_181 . V_165 ) ;
V_197 = F_113 ( V_29 , V_181 . V_167 , V_157 ) - V_212 ;
V_198 = F_114 ( V_29 , V_181 . V_167 , V_157 ) - V_213 ;
F_122 ( & V_181 . V_195 , V_181 . V_167 ) ;
if ( F_145 ( & V_181 ) )
F_144 ( & V_181 , V_197 , V_198 ) ;
if ( V_181 . V_185 == - 1 || ( V_29 -> V_135 && V_29 -> V_135 -> V_216 > 1 ) ) {
F_111 (nid) {
if ( V_139 == V_181 . V_165 || V_139 == V_29 -> V_133 )
continue;
V_157 = F_112 ( V_181 . V_165 , V_181 . V_167 ) ;
if ( V_155 == V_159 &&
V_157 != V_181 . V_157 ) {
V_212 = F_113 ( V_29 , V_181 . V_165 , V_157 ) ;
V_213 = F_114 ( V_29 , V_181 . V_165 , V_157 ) ;
}
V_197 = F_113 ( V_29 , V_139 , V_157 ) - V_212 ;
V_198 = F_114 ( V_29 , V_139 , V_157 ) - V_213 ;
if ( V_197 < 0 && V_198 < 0 )
continue;
V_181 . V_157 = V_157 ;
V_181 . V_167 = V_139 ;
F_122 ( & V_181 . V_195 , V_181 . V_167 ) ;
if ( F_145 ( & V_181 ) )
F_144 ( & V_181 , V_197 , V_198 ) ;
}
}
if ( V_29 -> V_135 ) {
struct V_135 * V_148 = V_29 -> V_135 ;
if ( V_181 . V_185 == - 1 )
V_139 = V_181 . V_165 ;
else
V_139 = V_181 . V_167 ;
if ( V_148 -> V_216 > 1 && F_109 ( V_181 . V_167 , V_148 ) )
F_150 ( V_29 , V_181 . V_167 ) ;
}
if ( V_181 . V_185 == - 1 )
return - V_217 ;
V_29 -> V_218 = F_97 ( V_29 ) ;
if ( V_181 . V_183 == NULL ) {
V_67 = F_151 ( V_29 , V_181 . V_185 ) ;
if ( V_67 != 0 )
F_152 ( V_29 , V_181 . V_200 , V_181 . V_185 ) ;
return V_67 ;
}
V_67 = F_153 ( V_29 , V_181 . V_183 ) ;
if ( V_67 != 0 )
F_152 ( V_29 , V_181 . V_200 , F_147 ( V_181 . V_183 ) ) ;
F_129 ( V_181 . V_183 ) ;
return V_67 ;
}
static void F_154 ( struct V_26 * V_29 )
{
unsigned long V_219 = V_220 ;
if ( F_13 ( V_29 -> V_133 == - 1 || ! V_29 -> V_143 ) )
return;
V_219 = F_155 ( V_219 , F_156 ( V_29 -> V_218 ) / 16 ) ;
V_29 -> V_221 = V_222 + V_219 ;
if ( F_102 ( V_29 ) == V_29 -> V_133 )
return;
F_146 ( V_29 ) ;
}
static void F_157 ( struct V_135 * V_135 )
{
unsigned long V_145 , V_223 = 0 ;
int V_139 , V_216 = 0 ;
F_111 (nid) {
V_145 = F_108 ( V_135 , V_139 ) ;
if ( V_145 > V_223 )
V_223 = V_145 ;
}
F_111 (nid) {
V_145 = F_108 ( V_135 , V_139 ) ;
if ( V_145 * V_149 > V_223 )
V_216 ++ ;
}
V_135 -> V_150 = V_223 ;
V_135 -> V_216 = V_216 ;
}
static void F_158 ( struct V_26 * V_29 ,
unsigned long V_224 , unsigned long V_225 )
{
unsigned int V_226 ;
int V_227 ;
int V_228 ;
unsigned long V_229 = V_29 -> V_230 [ 0 ] ;
unsigned long V_231 = V_29 -> V_230 [ 1 ] ;
if ( V_231 + V_224 == 0 || V_29 -> V_230 [ 2 ] ) {
V_29 -> V_218 = F_155 ( V_29 -> V_232 ,
V_29 -> V_218 << 1 ) ;
V_29 -> V_123 -> V_233 = V_222 +
F_156 ( V_29 -> V_218 ) ;
return;
}
V_226 = F_53 ( V_29 -> V_218 , V_234 ) ;
V_227 = ( V_231 * V_234 ) / ( V_231 + V_229 ) ;
if ( V_227 >= V_235 ) {
int V_236 = V_227 - V_235 ;
if ( ! V_236 )
V_236 = 1 ;
V_228 = V_236 * V_226 ;
} else {
V_228 = - ( V_235 - V_227 ) * V_226 ;
V_227 = F_53 ( V_225 * V_234 , ( V_225 + V_224 + 1 ) ) ;
V_228 = ( V_228 * V_227 ) / V_234 ;
}
V_29 -> V_218 = F_159 ( V_29 -> V_218 + V_228 ,
F_97 ( V_29 ) , F_100 ( V_29 ) ) ;
memset ( V_29 -> V_230 , 0 , sizeof( V_29 -> V_230 ) ) ;
}
static T_2 F_160 ( struct V_26 * V_29 , T_2 * V_237 )
{
T_2 V_238 , V_42 , V_87 ;
V_87 = V_29 -> V_28 . V_91 ;
V_238 = V_29 -> V_28 . V_94 ;
if ( V_29 -> V_239 ) {
V_42 = V_238 - V_29 -> V_240 ;
* V_237 = V_87 - V_29 -> V_239 ;
} else {
V_42 = V_29 -> V_28 . V_77 . V_81 / V_29 -> V_28 . V_71 . V_4 ;
* V_237 = V_82 ;
}
V_29 -> V_240 = V_238 ;
V_29 -> V_239 = V_87 ;
return V_42 ;
}
static int F_161 ( struct V_26 * V_29 , int V_139 )
{
T_8 V_241 ;
int V_157 ;
if ( V_155 == V_156 )
return V_139 ;
if ( V_155 == V_160 ) {
unsigned long V_153 , V_242 = 0 ;
int V_154 , V_243 = V_139 ;
V_157 = V_158 ;
F_111 (node) {
V_153 = F_114 ( V_29 , V_154 , V_157 ) ;
if ( V_153 > V_242 ) {
V_242 = V_153 ;
V_243 = V_154 ;
}
}
return V_243 ;
}
V_241 = V_244 ;
for ( V_157 = V_158 ; V_157 > V_161 ; V_157 -- ) {
unsigned long V_223 = 0 ;
T_8 V_245 = V_246 ;
int V_43 , V_44 ;
if ( ! F_162 ( V_157 ) )
continue;
F_163 (a, nodes) {
unsigned long V_145 = 0 ;
T_8 V_247 ;
F_164 ( V_247 ) ;
F_163 (b, nodes) {
if ( F_112 ( V_43 , V_44 ) < V_157 ) {
V_145 += F_107 ( V_29 , V_44 ) ;
F_165 ( V_44 , V_247 ) ;
F_166 ( V_44 , V_241 ) ;
}
}
if ( V_145 > V_223 ) {
V_223 = V_145 ;
V_245 = V_247 ;
V_139 = V_43 ;
}
}
if ( ! V_223 )
break;
V_241 = V_245 ;
}
return V_139 ;
}
static void F_167 ( struct V_26 * V_29 )
{
int V_248 , V_139 , V_249 = - 1 , V_250 = - 1 ;
unsigned long V_223 = 0 , V_251 = 0 ;
unsigned long V_252 [ 2 ] = { 0 , 0 } ;
unsigned long V_162 ;
T_2 V_238 , V_237 ;
T_9 * V_253 = NULL ;
V_248 = F_98 ( V_29 -> V_123 -> V_254 ) ;
if ( V_29 -> V_254 == V_248 )
return;
V_29 -> V_254 = V_248 ;
V_29 -> V_232 = F_100 ( V_29 ) ;
V_162 = V_29 -> V_230 [ 0 ] +
V_29 -> V_230 [ 1 ] ;
V_238 = F_160 ( V_29 , & V_237 ) ;
if ( V_29 -> V_135 ) {
V_253 = & V_29 -> V_135 -> V_255 ;
F_168 ( V_253 ) ;
}
F_111 (nid) {
int V_256 , V_257 , V_258 , V_259 ;
unsigned long V_145 = 0 , F_107 = 0 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
long V_228 , V_260 , V_261 ;
V_256 = F_105 ( V_144 , V_139 , V_140 ) ;
V_257 = F_105 ( V_262 , V_139 , V_140 ) ;
V_258 = F_105 ( V_263 , V_139 , V_140 ) ;
V_259 = F_105 ( V_264 , V_139 , V_140 ) ;
V_228 = V_29 -> V_143 [ V_257 ] - V_29 -> V_143 [ V_256 ] / 2 ;
V_252 [ V_140 ] += V_29 -> V_143 [ V_257 ] ;
V_29 -> V_143 [ V_257 ] = 0 ;
V_261 = F_169 ( V_238 << 16 , V_237 + 1 ) ;
V_261 = ( V_261 * V_29 -> V_143 [ V_259 ] ) /
( V_162 + 1 ) ;
V_260 = V_261 - V_29 -> V_143 [ V_258 ] / 2 ;
V_29 -> V_143 [ V_259 ] = 0 ;
V_29 -> V_143 [ V_256 ] += V_228 ;
V_29 -> V_143 [ V_258 ] += V_260 ;
V_145 += V_29 -> V_143 [ V_256 ] ;
V_29 -> V_163 += V_228 ;
if ( V_29 -> V_135 ) {
V_29 -> V_135 -> V_145 [ V_256 ] += V_228 ;
V_29 -> V_135 -> V_147 [ V_256 ] += V_260 ;
V_29 -> V_135 -> V_162 += V_228 ;
F_107 += V_29 -> V_135 -> V_145 [ V_256 ] ;
}
}
if ( V_145 > V_223 ) {
V_223 = V_145 ;
V_249 = V_139 ;
}
if ( F_107 > V_251 ) {
V_251 = F_107 ;
V_250 = V_139 ;
}
}
F_158 ( V_29 , V_252 [ 0 ] , V_252 [ 1 ] ) ;
if ( V_29 -> V_135 ) {
F_157 ( V_29 -> V_135 ) ;
F_170 ( V_253 ) ;
V_249 = F_161 ( V_29 , V_250 ) ;
}
if ( V_223 ) {
if ( V_249 != V_29 -> V_133 )
F_150 ( V_29 , V_249 ) ;
if ( F_102 ( V_29 ) != V_29 -> V_133 )
F_154 ( V_29 ) ;
}
}
static inline int F_171 ( struct V_135 * V_30 )
{
return F_172 ( & V_30 -> V_265 ) ;
}
static inline void F_173 ( struct V_135 * V_30 )
{
if ( F_174 ( & V_30 -> V_265 ) )
F_175 ( V_30 , V_266 ) ;
}
static void F_176 ( struct V_26 * V_29 , int V_267 , int V_113 ,
int * V_140 )
{
struct V_135 * V_30 , * V_268 ;
struct V_26 * V_102 ;
bool V_269 = false ;
int V_175 = F_177 ( V_267 ) ;
int V_270 ;
if ( F_13 ( ! V_29 -> V_135 ) ) {
unsigned int V_271 = sizeof( struct V_135 ) +
4 * V_142 *sizeof( unsigned long ) ;
V_30 = F_178 ( V_271 , V_272 | V_273 ) ;
if ( ! V_30 )
return;
F_179 ( & V_30 -> V_265 , 1 ) ;
V_30 -> V_216 = 1 ;
V_30 -> V_150 = 0 ;
F_180 ( & V_30 -> V_255 ) ;
V_30 -> V_136 = V_29 -> V_171 ;
V_30 -> V_147 = V_30 -> V_145 + V_141 *
V_142 ;
for ( V_270 = 0 ; V_270 < V_274 * V_142 ; V_270 ++ )
V_30 -> V_145 [ V_270 ] = V_29 -> V_143 [ V_270 ] ;
V_30 -> V_162 = V_29 -> V_163 ;
V_30 -> V_275 ++ ;
F_181 ( V_29 -> V_135 , V_30 ) ;
}
F_134 () ;
V_102 = F_98 ( F_124 ( V_175 ) -> V_45 ) ;
if ( ! F_121 ( V_102 , V_267 ) )
goto V_276;
V_30 = F_148 ( V_102 -> V_135 ) ;
if ( ! V_30 )
goto V_276;
V_268 = V_29 -> V_135 ;
if ( V_30 == V_268 )
goto V_276;
if ( V_268 -> V_275 > V_30 -> V_275 )
goto V_276;
if ( V_268 -> V_275 == V_30 -> V_275 && V_268 > V_30 )
goto V_276;
if ( V_102 -> V_123 == V_170 -> V_123 )
V_269 = true ;
if ( V_113 & V_277 )
V_269 = true ;
* V_140 = ! V_269 ;
if ( V_269 && ! F_171 ( V_30 ) )
goto V_276;
F_143 () ;
if ( ! V_269 )
return;
F_182 ( F_183 () ) ;
F_184 ( & V_268 -> V_255 , & V_30 -> V_255 ) ;
for ( V_270 = 0 ; V_270 < V_274 * V_142 ; V_270 ++ ) {
V_268 -> V_145 [ V_270 ] -= V_29 -> V_143 [ V_270 ] ;
V_30 -> V_145 [ V_270 ] += V_29 -> V_143 [ V_270 ] ;
}
V_268 -> V_162 -= V_29 -> V_163 ;
V_30 -> V_162 += V_29 -> V_163 ;
V_268 -> V_275 -- ;
V_30 -> V_275 ++ ;
F_185 ( & V_268 -> V_255 ) ;
F_170 ( & V_30 -> V_255 ) ;
F_181 ( V_29 -> V_135 , V_30 ) ;
F_173 ( V_268 ) ;
return;
V_276:
F_143 () ;
return;
}
void F_186 ( struct V_26 * V_29 )
{
struct V_135 * V_30 = V_29 -> V_135 ;
void * V_143 = V_29 -> V_143 ;
unsigned long V_113 ;
int V_270 ;
if ( V_30 ) {
F_187 ( & V_30 -> V_255 , V_113 ) ;
for ( V_270 = 0 ; V_270 < V_274 * V_142 ; V_270 ++ )
V_30 -> V_145 [ V_270 ] -= V_29 -> V_143 [ V_270 ] ;
V_30 -> V_162 -= V_29 -> V_163 ;
V_30 -> V_275 -- ;
F_188 ( & V_30 -> V_255 , V_113 ) ;
F_189 ( V_29 -> V_135 , NULL ) ;
F_173 ( V_30 ) ;
}
V_29 -> V_143 = NULL ;
F_190 ( V_143 ) ;
}
void F_191 ( int V_168 , int V_278 , int V_279 , int V_113 )
{
struct V_26 * V_29 = V_170 ;
bool V_280 = V_113 & V_281 ;
int V_282 = F_102 ( V_170 ) ;
int V_231 = ! ! ( V_113 & V_283 ) ;
struct V_135 * V_148 ;
int V_140 ;
if ( ! F_192 ( & V_284 ) )
return;
if ( ! V_29 -> V_123 )
return;
if ( F_13 ( ! V_29 -> V_143 ) ) {
int V_271 = sizeof( * V_29 -> V_143 ) *
V_285 * V_142 ;
V_29 -> V_143 = F_178 ( V_271 , V_272 | V_273 ) ;
if ( ! V_29 -> V_143 )
return;
V_29 -> V_163 = 0 ;
memset ( V_29 -> V_230 , 0 , sizeof( V_29 -> V_230 ) ) ;
}
if ( F_13 ( V_168 == ( - 1 & V_286 ) ) ) {
V_140 = 1 ;
} else {
V_140 = F_121 ( V_29 , V_168 ) ;
if ( ! V_140 && ! ( V_113 & V_287 ) )
F_176 ( V_29 , V_168 , V_113 , & V_140 ) ;
}
V_148 = V_29 -> V_135 ;
if ( ! V_140 && ! V_231 && V_148 && V_148 -> V_216 > 1 &&
F_109 ( V_282 , V_148 ) &&
F_109 ( V_278 , V_148 ) )
V_231 = 1 ;
F_167 ( V_29 ) ;
if ( F_193 ( V_222 , V_29 -> V_221 ) )
F_154 ( V_29 ) ;
if ( V_280 )
V_29 -> V_288 += V_279 ;
if ( V_113 & V_289 )
V_29 -> V_230 [ 2 ] += V_279 ;
V_29 -> V_143 [ F_105 ( V_262 , V_278 , V_140 ) ] += V_279 ;
V_29 -> V_143 [ F_105 ( V_264 , V_282 , V_140 ) ] += V_279 ;
V_29 -> V_230 [ V_231 ] += V_279 ;
}
static void F_194 ( struct V_26 * V_29 )
{
F_195 ( V_29 -> V_123 -> V_254 , F_98 ( V_29 -> V_123 -> V_254 ) + 1 ) ;
V_29 -> V_123 -> V_290 = 0 ;
}
void F_196 ( struct V_291 * V_292 )
{
unsigned long V_293 , V_294 , V_87 = V_222 ;
struct V_26 * V_29 = V_170 ;
struct V_295 * V_123 = V_29 -> V_123 ;
T_2 V_238 = V_29 -> V_28 . V_94 ;
struct V_296 * V_297 ;
unsigned long V_298 , V_299 ;
unsigned long V_300 = 0 ;
long V_279 , V_301 ;
F_18 ( V_29 != F_20 ( V_292 , struct V_26 , V_302 ) ) ;
V_292 -> V_59 = V_292 ;
if ( V_29 -> V_113 & V_204 )
return;
if ( ! V_123 -> V_233 ) {
V_123 -> V_233 = V_87 +
F_156 ( V_303 ) ;
}
V_293 = V_123 -> V_233 ;
if ( F_197 ( V_87 , V_293 ) )
return;
if ( V_29 -> V_218 == 0 ) {
V_29 -> V_232 = F_100 ( V_29 ) ;
V_29 -> V_218 = F_97 ( V_29 ) ;
}
V_294 = V_87 + F_156 ( V_29 -> V_218 ) ;
if ( F_198 ( & V_123 -> V_233 , V_293 , V_294 ) != V_293 )
return;
V_29 -> V_304 += 2 * V_305 ;
V_298 = V_123 -> V_290 ;
V_279 = V_121 ;
V_279 <<= 20 - V_122 ;
V_301 = V_279 * 8 ;
if ( ! V_279 )
return;
F_199 ( & V_123 -> V_306 ) ;
V_297 = F_200 ( V_123 , V_298 ) ;
if ( ! V_297 ) {
F_194 ( V_29 ) ;
V_298 = 0 ;
V_297 = V_123 -> V_307 ;
}
for (; V_297 ; V_297 = V_297 -> V_308 ) {
if ( ! F_201 ( V_297 ) || ! F_202 ( V_297 ) ||
F_203 ( V_297 ) || ( V_297 -> V_309 & V_310 ) ) {
continue;
}
if ( ! V_297 -> V_311 ||
( V_297 -> V_312 && ( V_297 -> V_309 & ( V_313 | V_314 ) ) == ( V_313 ) ) )
continue;
if ( ! ( V_297 -> V_309 & ( V_313 | V_315 | V_314 ) ) )
continue;
do {
V_298 = F_69 ( V_298 , V_297 -> V_316 ) ;
V_299 = F_204 ( V_298 + ( V_279 << V_122 ) , V_317 ) ;
V_299 = F_155 ( V_299 , V_297 -> V_318 ) ;
V_300 = F_205 ( V_297 , V_298 , V_299 ) ;
if ( V_300 )
V_279 -= ( V_299 - V_298 ) >> V_122 ;
V_301 -= ( V_299 - V_298 ) >> V_122 ;
V_298 = V_299 ;
if ( V_279 <= 0 || V_301 <= 0 )
goto V_319;
F_206 () ;
} while ( V_299 != V_297 -> V_318 );
}
V_319:
if ( V_297 )
V_123 -> V_290 = V_298 ;
else
F_194 ( V_29 ) ;
F_207 ( & V_123 -> V_306 ) ;
if ( F_13 ( V_29 -> V_28 . V_94 != V_238 ) ) {
T_2 V_228 = V_29 -> V_28 . V_94 - V_238 ;
V_29 -> V_304 += 32 * V_228 ;
}
}
void F_208 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_291 * V_292 = & V_45 -> V_302 ;
T_2 V_237 , V_87 ;
if ( ! V_45 -> V_123 || ( V_45 -> V_113 & V_204 ) || V_292 -> V_59 != V_292 )
return;
V_87 = V_45 -> V_28 . V_94 ;
V_237 = ( T_2 ) V_45 -> V_218 * V_320 ;
if ( V_87 > V_45 -> V_304 + V_237 ) {
if ( ! V_45 -> V_304 )
V_45 -> V_218 = F_97 ( V_45 ) ;
V_45 -> V_304 += V_237 ;
if ( ! F_197 ( V_222 , V_45 -> V_123 -> V_233 ) ) {
F_209 ( V_292 , F_196 ) ;
F_210 ( V_45 , V_292 , true ) ;
}
}
}
static void F_208 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static inline void F_101 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_103 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static void
F_211 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_71 , V_28 -> V_71 . V_4 ) ;
if ( ! F_31 ( V_28 ) )
F_1 ( & F_16 ( V_25 ) -> V_71 , V_28 -> V_71 . V_4 ) ;
#ifdef F_212
if ( F_19 ( V_28 ) ) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_101 ( V_24 , F_17 ( V_28 ) ) ;
F_213 ( & V_28 -> V_321 , & V_24 -> V_322 ) ;
}
#endif
V_25 -> V_73 ++ ;
}
static void
F_214 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_71 , V_28 -> V_71 . V_4 ) ;
if ( ! F_31 ( V_28 ) )
F_2 ( & F_16 ( V_25 ) -> V_71 , V_28 -> V_71 . V_4 ) ;
#ifdef F_212
if ( F_19 ( V_28 ) ) {
F_103 ( F_16 ( V_25 ) , F_17 ( V_28 ) ) ;
F_215 ( & V_28 -> V_321 ) ;
}
#endif
V_25 -> V_73 -- ;
}
static long F_216 ( struct V_25 * V_25 , struct V_323 * V_33 )
{
long V_324 , V_71 , V_325 ;
V_71 = F_12 ( V_25 -> V_71 . V_4 ) ;
V_324 = F_217 ( & V_33 -> V_80 ) ;
V_324 -= V_25 -> V_326 ;
V_324 += V_71 ;
V_325 = ( V_33 -> V_325 * V_71 ) ;
if ( V_324 )
V_325 /= V_324 ;
if ( V_325 < V_327 )
V_325 = V_327 ;
if ( V_325 > V_33 -> V_325 )
V_325 = V_33 -> V_325 ;
return V_325 ;
}
static inline long F_216 ( struct V_25 * V_25 , struct V_323 * V_33 )
{
return V_33 -> V_325 ;
}
static void F_218 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_46 ) {
if ( V_25 -> V_45 == V_28 )
F_66 ( V_25 ) ;
F_214 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_71 , V_4 ) ;
if ( V_28 -> V_46 )
F_211 ( V_25 , V_28 ) ;
}
static void F_219 ( struct V_25 * V_25 )
{
struct V_323 * V_33 ;
struct V_27 * V_28 ;
long V_325 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_25 ( F_16 ( V_25 ) ) ] ;
if ( ! V_28 || F_220 ( V_25 ) )
return;
#ifndef F_212
if ( F_11 ( V_28 -> V_71 . V_4 == V_33 -> V_325 ) )
return;
#endif
V_325 = F_216 ( V_25 , V_33 ) ;
F_218 ( F_22 ( V_28 ) , V_28 , V_325 ) ;
}
static inline void F_219 ( struct V_25 * V_25 )
{
}
static T_10 T_2 F_221 ( T_2 V_328 , T_2 V_329 )
{
unsigned int V_330 ;
if ( ! V_329 )
return V_328 ;
else if ( F_13 ( V_329 > V_331 * 63 ) )
return 0 ;
V_330 = V_329 ;
if ( F_13 ( V_330 >= V_331 ) ) {
V_328 >>= V_330 / V_331 ;
V_330 %= V_331 ;
}
V_328 = F_15 ( V_328 , V_332 [ V_330 ] , 32 ) ;
return V_328 ;
}
static V_23 F_222 ( T_2 V_329 )
{
V_23 V_333 = 0 ;
if ( F_11 ( V_329 <= V_331 ) )
return V_334 [ V_329 ] ;
else if ( F_13 ( V_329 >= V_335 ) )
return V_82 ;
V_333 = V_336 [ V_329 / V_331 ] ;
V_329 %= V_331 ;
V_333 = F_221 ( V_333 , V_329 ) ;
return V_333 + V_334 [ V_329 ] ;
}
static T_10 int
F_223 ( T_2 V_87 , int V_175 , struct V_75 * V_76 ,
unsigned long V_4 , int V_337 , struct V_25 * V_25 )
{
T_2 V_42 , V_338 , V_339 ;
V_23 V_333 ;
unsigned int V_340 , V_341 , V_342 = 0 ;
unsigned long V_343 , V_344 ;
V_42 = V_87 - V_76 -> V_78 ;
if ( ( T_3 ) V_42 < 0 ) {
V_76 -> V_78 = V_87 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_76 -> V_78 = V_87 ;
V_343 = F_224 ( NULL , V_175 ) ;
V_344 = F_225 ( NULL , V_175 ) ;
V_340 = V_76 -> V_79 ;
if ( V_42 + V_340 >= 1024 ) {
V_342 = 1 ;
V_76 -> V_79 = 0 ;
V_340 = 1024 - V_340 ;
V_341 = F_226 ( V_340 , V_343 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_341 ;
if ( V_25 ) {
V_25 -> V_345 +=
V_4 * V_341 ;
}
}
if ( V_337 )
V_76 -> V_84 += V_341 * V_344 ;
V_42 -= V_340 ;
V_339 = V_42 / 1024 ;
V_42 %= 1024 ;
V_76 -> V_81 = F_221 ( V_76 -> V_81 , V_339 + 1 ) ;
if ( V_25 ) {
V_25 -> V_345 =
F_221 ( V_25 -> V_345 , V_339 + 1 ) ;
}
V_76 -> V_84 = F_221 ( ( T_2 ) ( V_76 -> V_84 ) , V_339 + 1 ) ;
V_333 = F_222 ( V_339 ) ;
V_333 = F_226 ( V_333 , V_343 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_333 ;
if ( V_25 )
V_25 -> V_345 += V_4 * V_333 ;
}
if ( V_337 )
V_76 -> V_84 += V_333 * V_344 ;
}
V_338 = F_226 ( V_42 , V_343 ) ;
if ( V_4 ) {
V_76 -> V_81 += V_4 * V_338 ;
if ( V_25 )
V_25 -> V_345 += V_4 * V_338 ;
}
if ( V_337 )
V_76 -> V_84 += V_338 * V_344 ;
V_76 -> V_79 += V_42 ;
if ( V_342 ) {
V_76 -> V_80 = F_227 ( V_76 -> V_81 , V_82 ) ;
if ( V_25 ) {
V_25 -> V_346 =
F_227 ( V_25 -> V_345 , V_82 ) ;
}
V_76 -> V_83 = V_76 -> V_84 / V_82 ;
}
return V_342 ;
}
static inline void F_65 ( struct V_25 * V_25 , int V_90 )
{
long V_42 = V_25 -> V_77 . V_80 - V_25 -> V_326 ;
if ( V_25 -> V_33 == & V_347 )
return;
if ( V_90 || abs ( V_42 ) > V_25 -> V_326 / 64 ) {
F_228 ( V_42 , & V_25 -> V_33 -> V_80 ) ;
V_25 -> V_326 = V_25 -> V_77 . V_80 ;
}
}
void F_229 ( struct V_27 * V_28 ,
struct V_25 * V_348 , struct V_25 * V_59 )
{
if ( ! F_230 ( V_349 ) )
return;
if ( V_28 -> V_77 . V_78 && V_348 ) {
T_2 V_350 ;
T_2 V_351 ;
#ifndef F_39
T_2 V_352 ;
T_2 V_353 ;
do {
V_352 = V_348 -> V_354 ;
V_353 = V_59 -> V_354 ;
F_231 () ;
V_350 = V_348 -> V_77 . V_78 ;
V_351 = V_59 -> V_77 . V_78 ;
} while ( V_350 != V_352 ||
V_351 != V_353 );
#else
V_350 = V_348 -> V_77 . V_78 ;
V_351 = V_59 -> V_77 . V_78 ;
#endif
F_223 ( V_350 , F_25 ( F_16 ( V_348 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
V_28 -> V_77 . V_78 = V_351 ;
}
}
static inline void F_65 ( struct V_25 * V_25 , int V_90 ) {}
static inline void F_232 ( struct V_25 * V_25 )
{
if ( & F_233 () -> V_40 == V_25 ) {
F_234 ( F_16 ( V_25 ) , 0 ) ;
}
}
static inline int
F_63 ( T_2 V_87 , struct V_25 * V_25 , bool V_355 )
{
struct V_75 * V_76 = & V_25 -> V_77 ;
int V_342 , V_356 = 0 , V_357 = 0 ;
if ( F_217 ( & V_25 -> V_358 ) ) {
T_3 V_359 = F_235 ( & V_25 -> V_358 , 0 ) ;
F_236 ( & V_76 -> V_80 , V_359 ) ;
F_236 ( & V_76 -> V_81 , V_359 * V_82 ) ;
V_356 = 1 ;
}
if ( F_217 ( & V_25 -> V_360 ) ) {
long V_359 = F_235 ( & V_25 -> V_360 , 0 ) ;
F_236 ( & V_76 -> V_83 , V_359 ) ;
F_236 ( & V_76 -> V_84 , V_359 * V_82 ) ;
V_357 = 1 ;
}
V_342 = F_223 ( V_87 , F_25 ( F_16 ( V_25 ) ) , V_76 ,
F_12 ( V_25 -> V_71 . V_4 ) , V_25 -> V_45 != NULL , V_25 ) ;
#ifndef F_39
F_40 () ;
V_25 -> V_354 = V_76 -> V_78 ;
#endif
if ( V_355 && ( V_342 || V_357 ) )
F_232 ( V_25 ) ;
return V_342 || V_356 ;
}
static inline void F_237 ( struct V_27 * V_28 , int V_361 )
{
struct V_25 * V_25 = F_22 ( V_28 ) ;
T_2 V_87 = F_62 ( V_25 ) ;
struct V_24 * V_24 = F_16 ( V_25 ) ;
int V_175 = F_25 ( V_24 ) ;
F_223 ( V_87 , V_175 , & V_28 -> V_77 ,
V_28 -> V_46 * F_12 ( V_28 -> V_71 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
if ( F_63 ( V_87 , V_25 , true ) && V_361 )
F_65 ( V_25 , 0 ) ;
}
static void F_64 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( ! F_230 ( V_349 ) )
goto V_362;
if ( V_28 -> V_77 . V_78 ) {
F_223 ( V_25 -> V_77 . V_78 , F_25 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , 0 , 0 , NULL ) ;
}
V_362:
V_28 -> V_77 . V_78 = V_25 -> V_77 . V_78 ;
V_25 -> V_77 . V_80 += V_28 -> V_77 . V_80 ;
V_25 -> V_77 . V_81 += V_28 -> V_77 . V_81 ;
V_25 -> V_77 . V_83 += V_28 -> V_77 . V_83 ;
V_25 -> V_77 . V_84 += V_28 -> V_77 . V_84 ;
F_232 ( V_25 ) ;
}
static void F_238 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_223 ( V_25 -> V_77 . V_78 , F_25 ( F_16 ( V_25 ) ) ,
& V_28 -> V_77 , V_28 -> V_46 * F_12 ( V_28 -> V_71 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
F_236 ( & V_25 -> V_77 . V_80 , V_28 -> V_77 . V_80 ) ;
F_236 ( & V_25 -> V_77 . V_81 , V_28 -> V_77 . V_81 ) ;
F_236 ( & V_25 -> V_77 . V_83 , V_28 -> V_77 . V_83 ) ;
F_236 ( & V_25 -> V_77 . V_84 , V_28 -> V_77 . V_84 ) ;
F_232 ( V_25 ) ;
}
static inline void
F_239 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_75 * V_76 = & V_28 -> V_77 ;
T_2 V_87 = F_62 ( V_25 ) ;
int V_280 , V_342 ;
V_280 = ! V_76 -> V_78 ;
if ( ! V_280 ) {
F_223 ( V_87 , F_25 ( F_16 ( V_25 ) ) , V_76 ,
V_28 -> V_46 * F_12 ( V_28 -> V_71 . V_4 ) ,
V_25 -> V_45 == V_28 , NULL ) ;
}
V_342 = F_63 ( V_87 , V_25 , ! V_280 ) ;
V_25 -> V_346 += V_76 -> V_80 ;
V_25 -> V_345 += V_76 -> V_81 ;
if ( V_280 )
F_64 ( V_25 , V_28 ) ;
if ( V_342 || V_280 )
F_65 ( V_25 , 0 ) ;
}
static inline void
F_240 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_237 ( V_28 , 1 ) ;
V_25 -> V_346 =
F_99 ( long , V_25 -> V_346 - V_28 -> V_77 . V_80 , 0 ) ;
V_25 -> V_345 =
F_99 ( T_3 , V_25 -> V_345 - V_28 -> V_77 . V_81 , 0 ) ;
}
static inline T_2 F_241 ( struct V_25 * V_25 )
{
T_2 V_363 ;
T_2 V_78 ;
do {
V_363 = V_25 -> V_354 ;
F_231 () ;
V_78 = V_25 -> V_77 . V_78 ;
} while ( V_78 != V_363 );
return V_78 ;
}
static inline T_2 F_241 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_78 ;
}
void F_242 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_22 ( V_28 ) ;
T_2 V_78 ;
V_78 = F_241 ( V_25 ) ;
F_223 ( V_78 , F_25 ( F_16 ( V_25 ) ) , & V_28 -> V_77 , 0 , 0 , NULL ) ;
F_228 ( V_28 -> V_77 . V_80 , & V_25 -> V_358 ) ;
F_228 ( V_28 -> V_77 . V_83 , & V_25 -> V_360 ) ;
}
static inline unsigned long F_243 ( struct V_25 * V_25 )
{
return V_25 -> V_346 ;
}
static inline unsigned long F_244 ( struct V_25 * V_25 )
{
return V_25 -> V_77 . V_80 ;
}
static inline int
F_63 ( T_2 V_87 , struct V_25 * V_25 , bool V_355 )
{
return 0 ;
}
static inline void F_237 ( struct V_27 * V_28 , int V_364 )
{
F_234 ( F_16 ( F_22 ( V_28 ) ) , 0 ) ;
}
static inline void
F_239 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_240 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void F_242 ( struct V_27 * V_28 ) {}
static inline void
F_64 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline void
F_238 ( struct V_25 * V_25 , struct V_27 * V_28 ) {}
static inline int F_245 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_246 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_247
T_3 V_365 = V_28 -> V_41 - V_25 -> F_35 ;
if ( V_365 < 0 )
V_365 = - V_365 ;
if ( V_365 > 3 * V_69 )
F_83 ( V_25 -> V_366 ) ;
#endif
}
static void
F_248 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_367 )
{
T_2 V_41 = V_25 -> F_35 ;
if ( V_367 && F_230 ( V_368 ) )
V_41 += F_59 ( V_25 , V_28 ) ;
if ( ! V_367 ) {
unsigned long V_369 = V_69 ;
if ( F_230 ( V_370 ) )
V_369 >>= 1 ;
V_41 -= V_369 ;
}
V_28 -> V_41 = F_34 ( V_28 -> V_41 , V_41 ) ;
}
static inline void F_249 ( void )
{
#ifdef F_250
if ( F_77 () )
return;
if ( F_251 () ||
F_252 () ||
F_253 () ||
F_254 () ||
F_255 () ) {
F_256 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_257 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_113 )
{
bool V_371 = ! ( V_113 & V_114 ) || ( V_113 & V_372 ) ;
bool V_45 = V_25 -> V_45 == V_28 ;
if ( V_371 && V_45 )
V_28 -> V_41 += V_25 -> F_35 ;
F_66 ( V_25 ) ;
if ( V_371 && ! V_45 )
V_28 -> V_41 += V_25 -> F_35 ;
F_239 ( V_25 , V_28 ) ;
F_211 ( V_25 , V_28 ) ;
F_219 ( V_25 ) ;
if ( V_113 & V_114 )
F_248 ( V_25 , V_28 , 0 ) ;
F_249 () ;
F_91 ( V_25 , V_28 , V_113 ) ;
F_246 ( V_25 , V_28 ) ;
if ( ! V_45 )
F_41 ( V_25 , V_28 ) ;
V_28 -> V_46 = 1 ;
if ( V_25 -> V_73 == 1 ) {
F_24 ( V_25 ) ;
F_258 ( V_25 ) ;
}
}
static void F_259 ( struct V_27 * V_28 )
{
F_58 (se) {
struct V_25 * V_25 = F_22 ( V_28 ) ;
if ( V_25 -> V_60 != V_28 )
break;
V_25 -> V_60 = NULL ;
}
}
static void F_260 ( struct V_27 * V_28 )
{
F_58 (se) {
struct V_25 * V_25 = F_22 ( V_28 ) ;
if ( V_25 -> V_59 != V_28 )
break;
V_25 -> V_59 = NULL ;
}
}
static void F_261 ( struct V_27 * V_28 )
{
F_58 (se) {
struct V_25 * V_25 = F_22 ( V_28 ) ;
if ( V_25 -> V_373 != V_28 )
break;
V_25 -> V_373 = NULL ;
}
}
static void F_262 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_60 == V_28 )
F_259 ( V_28 ) ;
if ( V_25 -> V_59 == V_28 )
F_260 ( V_28 ) ;
if ( V_25 -> V_373 == V_28 )
F_261 ( V_28 ) ;
}
static void
F_263 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_113 )
{
F_66 ( V_25 ) ;
F_240 ( V_25 , V_28 ) ;
F_92 ( V_25 , V_28 , V_113 ) ;
F_262 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_44 ( V_25 , V_28 ) ;
V_28 -> V_46 = 0 ;
F_214 ( V_25 , V_28 ) ;
if ( ! ( V_113 & V_115 ) )
V_28 -> V_41 -= V_25 -> F_35 ;
F_264 ( V_25 ) ;
F_219 ( V_25 ) ;
if ( ( V_113 & ( V_374 | V_375 ) ) == V_374 )
F_37 ( V_25 ) ;
}
static void
F_265 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_376 , V_19 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_376 = F_57 ( V_25 , V_45 ) ;
V_19 = V_45 -> V_94 - V_45 -> V_377 ;
if ( V_19 > V_376 ) {
F_266 ( F_16 ( V_25 ) ) ;
F_262 ( V_25 , V_45 ) ;
return;
}
if ( V_19 < V_70 )
return;
V_28 = F_47 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_376 )
F_266 ( F_16 ( V_25 ) ) ;
}
static void
F_267 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_46 ) {
F_81 ( V_25 , V_28 ) ;
F_44 ( V_25 , V_28 ) ;
F_237 ( V_28 , 1 ) ;
}
F_93 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
if ( F_77 () && F_16 ( V_25 ) -> V_71 . V_4 >= 2 * V_28 -> V_71 . V_4 ) {
F_68 ( V_28 -> V_92 . V_378 ,
F_69 ( ( T_2 ) F_79 ( V_28 -> V_92 . V_378 ) ,
V_28 -> V_94 - V_28 -> V_377 ) ) ;
}
V_28 -> V_377 = V_28 -> V_94 ;
}
static struct V_27 *
F_268 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
struct V_27 * V_58 = F_47 ( V_25 ) ;
struct V_27 * V_28 ;
if ( ! V_58 || ( V_45 && F_36 ( V_45 , V_58 ) ) )
V_58 = V_45 ;
V_28 = V_58 ;
if ( V_25 -> V_373 == V_28 ) {
struct V_27 * V_379 ;
if ( V_28 == V_45 ) {
V_379 = F_47 ( V_25 ) ;
} else {
V_379 = F_48 ( V_28 ) ;
if ( ! V_379 || ( V_45 && F_36 ( V_45 , V_379 ) ) )
V_379 = V_45 ;
}
if ( V_379 && F_269 ( V_379 , V_58 ) < 1 )
V_28 = V_379 ;
}
if ( V_25 -> V_60 && F_269 ( V_25 -> V_60 , V_58 ) < 1 )
V_28 = V_25 -> V_60 ;
if ( V_25 -> V_59 && F_269 ( V_25 -> V_59 , V_58 ) < 1 )
V_28 = V_25 -> V_59 ;
F_262 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_270 ( struct V_25 * V_25 , struct V_27 * V_348 )
{
if ( V_348 -> V_46 )
F_66 ( V_25 ) ;
F_271 ( V_25 ) ;
F_246 ( V_25 , V_348 ) ;
if ( V_348 -> V_46 ) {
F_76 ( V_25 , V_348 ) ;
F_41 ( V_25 , V_348 ) ;
F_237 ( V_348 , 0 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_272 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_380 )
{
F_66 ( V_25 ) ;
F_237 ( V_45 , 1 ) ;
F_219 ( V_25 ) ;
#ifdef F_273
if ( V_380 ) {
F_266 ( F_16 ( V_25 ) ) ;
return;
}
if ( ! F_230 ( V_381 ) &&
F_274 ( & F_16 ( V_25 ) -> V_382 ) )
return;
#endif
if ( V_25 -> V_73 > 1 )
F_265 ( V_25 , V_45 ) ;
}
static inline bool F_275 ( void )
{
return F_276 ( & V_383 ) ;
}
void F_277 ( void )
{
F_278 ( & V_383 ) ;
}
void F_279 ( void )
{
F_280 ( & V_383 ) ;
}
static bool F_275 ( void )
{
return true ;
}
void F_277 ( void ) {}
void F_279 ( void ) {}
static inline T_2 F_281 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_282 ( void )
{
return ( T_2 ) V_384 * V_385 ;
}
void F_283 ( struct V_386 * V_387 )
{
T_2 V_87 ;
if ( V_387 -> V_388 == V_389 )
return;
V_87 = F_284 ( F_285 () ) ;
V_387 -> V_238 = V_387 -> V_388 ;
V_387 -> V_390 = V_87 + F_286 ( V_387 -> V_237 ) ;
}
static inline struct V_386 * F_287 ( struct V_323 * V_33 )
{
return & V_33 -> V_386 ;
}
static inline T_2 F_62 ( struct V_25 * V_25 )
{
if ( F_13 ( V_25 -> V_391 ) )
return V_25 -> V_392 - V_25 -> V_393 ;
return F_67 ( F_16 ( V_25 ) ) - V_25 -> V_393 ;
}
static int F_288 ( struct V_25 * V_25 )
{
struct V_323 * V_33 = V_25 -> V_33 ;
struct V_386 * V_387 = F_287 ( V_33 ) ;
T_2 V_394 = 0 , V_395 , V_396 ;
V_395 = F_282 () - V_25 -> V_397 ;
F_289 ( & V_387 -> V_255 ) ;
if ( V_387 -> V_388 == V_389 )
V_394 = V_395 ;
else {
F_290 ( V_387 ) ;
if ( V_387 -> V_238 > 0 ) {
V_394 = F_155 ( V_387 -> V_238 , V_395 ) ;
V_387 -> V_238 -= V_394 ;
V_387 -> V_398 = 0 ;
}
}
V_396 = V_387 -> V_390 ;
F_291 ( & V_387 -> V_255 ) ;
V_25 -> V_397 += V_394 ;
if ( ( T_3 ) ( V_396 - V_25 -> V_390 ) > 0 )
V_25 -> V_390 = V_396 ;
return V_25 -> V_397 > 0 ;
}
static void F_292 ( struct V_25 * V_25 )
{
struct V_386 * V_387 = F_287 ( V_25 -> V_33 ) ;
if ( F_11 ( ( T_3 ) ( F_78 ( F_16 ( V_25 ) ) - V_25 -> V_390 ) < 0 ) )
return;
if ( V_25 -> V_397 < 0 )
return;
if ( V_25 -> V_390 != V_387 -> V_390 ) {
V_25 -> V_390 += V_305 ;
} else {
V_25 -> V_397 = 0 ;
}
}
static void F_293 ( struct V_25 * V_25 , T_2 V_19 )
{
V_25 -> V_397 -= V_19 ;
F_292 ( V_25 ) ;
if ( F_11 ( V_25 -> V_397 > 0 ) )
return;
if ( ! F_288 ( V_25 ) && F_11 ( V_25 -> V_45 ) )
F_266 ( F_16 ( V_25 ) ) ;
}
static T_10
void F_74 ( struct V_25 * V_25 , T_2 V_19 )
{
if ( ! F_275 () || ! V_25 -> V_399 )
return;
F_293 ( V_25 , V_19 ) ;
}
static inline int F_294 ( struct V_25 * V_25 )
{
return F_275 () && V_25 -> V_400 ;
}
static inline int F_220 ( struct V_25 * V_25 )
{
return F_275 () && V_25 -> V_391 ;
}
static inline int F_295 ( struct V_323 * V_33 ,
int V_200 , int V_401 )
{
struct V_25 * V_402 , * V_403 ;
V_402 = V_33 -> V_25 [ V_200 ] ;
V_403 = V_33 -> V_25 [ V_401 ] ;
return F_220 ( V_402 ) ||
F_220 ( V_403 ) ;
}
static int F_296 ( struct V_323 * V_33 , void * V_404 )
{
struct V_24 * V_24 = V_404 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_25 ( V_24 ) ] ;
V_25 -> V_391 -- ;
if ( ! V_25 -> V_391 ) {
V_25 -> V_393 += F_67 ( V_24 ) -
V_25 -> V_392 ;
}
return 0 ;
}
static int F_297 ( struct V_323 * V_33 , void * V_404 )
{
struct V_24 * V_24 = V_404 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_25 ( V_24 ) ] ;
if ( ! V_25 -> V_391 )
V_25 -> V_392 = F_67 ( V_24 ) ;
V_25 -> V_391 ++ ;
return 0 ;
}
static void F_298 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_386 * V_387 = F_287 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_405 , V_406 = 1 ;
bool V_407 ;
V_28 = V_25 -> V_33 -> V_28 [ F_25 ( F_16 ( V_25 ) ) ] ;
F_134 () ;
F_299 ( V_25 -> V_33 , F_297 , V_408 , ( void * ) V_24 ) ;
F_143 () ;
V_405 = V_25 -> V_409 ;
F_58 (se) {
struct V_25 * V_410 = F_22 ( V_28 ) ;
if ( ! V_28 -> V_46 )
break;
if ( V_406 )
F_263 ( V_410 , V_28 , V_115 ) ;
V_410 -> V_409 -= V_405 ;
if ( V_410 -> V_71 . V_4 )
V_406 = 0 ;
}
if ( ! V_28 )
F_300 ( V_24 , V_405 ) ;
V_25 -> V_400 = 1 ;
V_25 -> V_411 = F_78 ( V_24 ) ;
F_289 ( & V_387 -> V_255 ) ;
V_407 = F_301 ( & V_387 -> V_412 ) ;
F_26 ( & V_25 -> V_413 , & V_387 -> V_412 ) ;
if ( V_407 )
F_290 ( V_387 ) ;
F_291 ( & V_387 -> V_255 ) ;
}
void F_302 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_386 * V_387 = F_287 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_414 = 1 ;
long V_405 ;
V_28 = V_25 -> V_33 -> V_28 [ F_25 ( V_24 ) ] ;
V_25 -> V_400 = 0 ;
F_303 ( V_24 ) ;
F_289 ( & V_387 -> V_255 ) ;
V_387 -> V_415 += F_78 ( V_24 ) - V_25 -> V_411 ;
F_29 ( & V_25 -> V_413 ) ;
F_291 ( & V_387 -> V_255 ) ;
F_299 ( V_25 -> V_33 , V_408 , F_296 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_71 . V_4 )
return;
V_405 = V_25 -> V_409 ;
F_58 (se) {
if ( V_28 -> V_46 )
V_414 = 0 ;
V_25 = F_22 ( V_28 ) ;
if ( V_414 )
F_257 ( V_25 , V_28 , V_114 ) ;
V_25 -> V_409 += V_405 ;
if ( F_294 ( V_25 ) )
break;
}
if ( ! V_28 )
F_304 ( V_24 , V_405 ) ;
if ( V_24 -> V_45 == V_24 -> V_398 && V_24 -> V_40 . V_73 )
F_266 ( V_24 ) ;
}
static T_2 F_305 ( struct V_386 * V_387 ,
T_2 V_416 , T_2 V_396 )
{
struct V_25 * V_25 ;
T_2 V_238 ;
T_2 V_417 = V_416 ;
F_134 () ;
F_306 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_16 ( V_25 ) ;
F_289 ( & V_24 -> V_255 ) ;
if ( ! F_294 ( V_25 ) )
goto V_59;
V_238 = - V_25 -> V_397 + 1 ;
if ( V_238 > V_416 )
V_238 = V_416 ;
V_416 -= V_238 ;
V_25 -> V_397 += V_238 ;
V_25 -> V_390 = V_396 ;
if ( V_25 -> V_397 > 0 )
F_302 ( V_25 ) ;
V_59:
F_291 ( & V_24 -> V_255 ) ;
if ( ! V_416 )
break;
}
F_143 () ;
return V_417 - V_416 ;
}
static int F_307 ( struct V_386 * V_387 , int V_418 )
{
T_2 V_238 , V_390 ;
int V_400 ;
if ( V_387 -> V_388 == V_389 )
goto V_419;
V_400 = ! F_301 ( & V_387 -> V_412 ) ;
V_387 -> V_420 += V_418 ;
if ( V_387 -> V_398 && ! V_400 )
goto V_419;
F_283 ( V_387 ) ;
if ( ! V_400 ) {
V_387 -> V_398 = 1 ;
return 0 ;
}
V_387 -> V_421 += V_418 ;
V_390 = V_387 -> V_390 ;
while ( V_400 && V_387 -> V_238 > 0 ) {
V_238 = V_387 -> V_238 ;
F_291 ( & V_387 -> V_255 ) ;
V_238 = F_305 ( V_387 , V_238 ,
V_390 ) ;
F_289 ( & V_387 -> V_255 ) ;
V_400 = ! F_301 ( & V_387 -> V_412 ) ;
V_387 -> V_238 -= F_155 ( V_238 , V_387 -> V_238 ) ;
}
V_387 -> V_398 = 0 ;
return 0 ;
V_419:
return 1 ;
}
static int F_308 ( struct V_386 * V_387 , T_2 V_422 )
{
struct V_423 * V_424 = & V_387 -> V_425 ;
T_2 V_416 ;
if ( F_309 ( V_424 ) )
return 1 ;
V_416 = F_286 ( F_310 ( V_424 ) ) ;
if ( V_416 < V_422 )
return 1 ;
return 0 ;
}
static void F_311 ( struct V_386 * V_387 )
{
T_2 V_426 = V_427 + V_428 ;
if ( F_308 ( V_387 , V_426 ) )
return;
F_312 ( & V_387 -> V_429 ,
F_313 ( V_427 ) ,
V_430 ) ;
}
static void F_314 ( struct V_25 * V_25 )
{
struct V_386 * V_387 = F_287 ( V_25 -> V_33 ) ;
T_3 V_431 = V_25 -> V_397 - V_432 ;
if ( V_431 <= 0 )
return;
F_289 ( & V_387 -> V_255 ) ;
if ( V_387 -> V_388 != V_389 &&
V_25 -> V_390 == V_387 -> V_390 ) {
V_387 -> V_238 += V_431 ;
if ( V_387 -> V_238 > F_282 () &&
! F_301 ( & V_387 -> V_412 ) )
F_311 ( V_387 ) ;
}
F_291 ( & V_387 -> V_255 ) ;
V_25 -> V_397 -= V_431 ;
}
static T_10 void F_264 ( struct V_25 * V_25 )
{
if ( ! F_275 () )
return;
if ( ! V_25 -> V_399 || V_25 -> V_73 )
return;
F_314 ( V_25 ) ;
}
static void F_315 ( struct V_386 * V_387 )
{
T_2 V_238 = 0 , V_74 = F_282 () ;
T_2 V_396 ;
F_289 ( & V_387 -> V_255 ) ;
if ( F_308 ( V_387 , V_428 ) ) {
F_291 ( & V_387 -> V_255 ) ;
return;
}
if ( V_387 -> V_388 != V_389 && V_387 -> V_238 > V_74 )
V_238 = V_387 -> V_238 ;
V_396 = V_387 -> V_390 ;
F_291 ( & V_387 -> V_255 ) ;
if ( ! V_238 )
return;
V_238 = F_305 ( V_387 , V_238 , V_396 ) ;
F_289 ( & V_387 -> V_255 ) ;
if ( V_396 == V_387 -> V_390 )
V_387 -> V_238 -= F_155 ( V_238 , V_387 -> V_238 ) ;
F_291 ( & V_387 -> V_255 ) ;
}
static void F_258 ( struct V_25 * V_25 )
{
if ( ! F_275 () )
return;
if ( ! V_25 -> V_399 || V_25 -> V_45 )
return;
if ( F_294 ( V_25 ) )
return;
F_74 ( V_25 , 0 ) ;
if ( V_25 -> V_397 <= 0 )
F_298 ( V_25 ) ;
}
static void F_316 ( struct V_323 * V_33 , int V_175 )
{
struct V_25 * V_433 , * V_25 ;
if ( ! F_275 () )
return;
if ( ! V_33 -> V_34 )
return;
V_25 = V_33 -> V_25 [ V_175 ] ;
V_433 = V_33 -> V_34 -> V_25 [ V_175 ] ;
V_25 -> V_391 = V_433 -> V_391 ;
V_25 -> V_392 = F_67 ( F_124 ( V_175 ) ) ;
}
static bool F_271 ( struct V_25 * V_25 )
{
if ( ! F_275 () )
return false ;
if ( F_11 ( ! V_25 -> V_399 || V_25 -> V_397 > 0 ) )
return false ;
if ( F_294 ( V_25 ) )
return true ;
F_298 ( V_25 ) ;
return true ;
}
static enum V_434 F_317 ( struct V_423 * V_435 )
{
struct V_386 * V_387 =
F_20 ( V_435 , struct V_386 , V_429 ) ;
F_315 ( V_387 ) ;
return V_436 ;
}
static enum V_434 F_318 ( struct V_423 * V_435 )
{
struct V_386 * V_387 =
F_20 ( V_435 , struct V_386 , V_425 ) ;
int V_418 ;
int V_398 = 0 ;
F_289 ( & V_387 -> V_255 ) ;
for (; ; ) {
V_418 = F_319 ( V_435 , V_387 -> V_237 ) ;
if ( ! V_418 )
break;
V_398 = F_307 ( V_387 , V_418 ) ;
}
if ( V_398 )
V_387 -> V_437 = 0 ;
F_291 ( & V_387 -> V_255 ) ;
return V_398 ? V_436 : V_438 ;
}
void F_320 ( struct V_386 * V_387 )
{
F_321 ( & V_387 -> V_255 ) ;
V_387 -> V_238 = 0 ;
V_387 -> V_388 = V_389 ;
V_387 -> V_237 = F_313 ( F_281 () ) ;
F_322 ( & V_387 -> V_412 ) ;
F_323 ( & V_387 -> V_425 , V_439 , V_440 ) ;
V_387 -> V_425 . V_441 = F_318 ;
F_323 ( & V_387 -> V_429 , V_439 , V_430 ) ;
V_387 -> V_429 . V_441 = F_317 ;
}
static void F_324 ( struct V_25 * V_25 )
{
V_25 -> V_399 = 0 ;
F_322 ( & V_25 -> V_413 ) ;
}
void F_290 ( struct V_386 * V_387 )
{
F_325 ( & V_387 -> V_255 ) ;
if ( ! V_387 -> V_437 ) {
V_387 -> V_437 = 1 ;
F_319 ( & V_387 -> V_425 , V_387 -> V_237 ) ;
F_326 ( & V_387 -> V_425 , V_440 ) ;
}
}
static void F_327 ( struct V_386 * V_387 )
{
if ( ! V_387 -> V_412 . V_59 )
return;
F_328 ( & V_387 -> V_425 ) ;
F_328 ( & V_387 -> V_429 ) ;
}
static void T_11 F_329 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_330 (rq, cfs_rq) {
struct V_386 * V_387 = & V_25 -> V_33 -> V_386 ;
F_289 ( & V_387 -> V_255 ) ;
V_25 -> V_399 = V_387 -> V_388 != V_389 ;
F_291 ( & V_387 -> V_255 ) ;
}
}
static void T_11 F_331 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_330 (rq, cfs_rq) {
if ( ! V_25 -> V_399 )
continue;
V_25 -> V_397 = 1 ;
V_25 -> V_399 = 0 ;
if ( F_294 ( V_25 ) )
F_302 ( V_25 ) ;
}
}
static inline T_2 F_62 ( struct V_25 * V_25 )
{
return F_67 ( F_16 ( V_25 ) ) ;
}
static void F_74 ( struct V_25 * V_25 , T_2 V_19 ) {}
static bool F_271 ( struct V_25 * V_25 ) { return false ; }
static void F_258 ( struct V_25 * V_25 ) {}
static inline void F_316 ( struct V_323 * V_33 , int V_175 ) {}
static T_10 void F_264 ( struct V_25 * V_25 ) {}
static inline int F_294 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_220 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_295 ( struct V_323 * V_33 ,
int V_200 , int V_401 )
{
return 0 ;
}
void F_320 ( struct V_386 * V_387 ) {}
static void F_324 ( struct V_25 * V_25 ) {}
static inline struct V_386 * F_287 ( struct V_323 * V_33 )
{
return NULL ;
}
static inline void F_327 ( struct V_386 * V_387 ) {}
static inline void F_329 ( struct V_24 * V_24 ) {}
static inline void F_331 ( struct V_24 * V_24 ) {}
static void F_332 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_28 ) ;
F_18 ( F_33 ( V_29 ) != V_24 ) ;
if ( V_24 -> V_40 . V_409 > 1 ) {
T_2 V_74 = F_57 ( V_25 , V_28 ) ;
T_2 V_442 = V_28 -> V_94 - V_28 -> V_377 ;
T_3 V_42 = V_74 - V_442 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_266 ( V_24 ) ;
return;
}
F_333 ( V_24 , V_42 ) ;
}
}
static void F_334 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_335 ( V_24 ) || V_45 -> V_88 != & V_89 )
return;
if ( F_22 ( & V_45 -> V_28 ) -> V_73 < V_68 )
F_332 ( V_24 , V_45 ) ;
}
static inline void
F_332 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_334 ( struct V_24 * V_24 )
{
}
static void
F_336 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_113 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_108 )
F_337 ( V_24 , V_443 ) ;
F_58 (se) {
if ( V_28 -> V_46 )
break;
V_25 = F_22 ( V_28 ) ;
F_257 ( V_25 , V_28 , V_113 ) ;
if ( F_294 ( V_25 ) )
break;
V_25 -> V_409 ++ ;
V_113 = V_114 ;
}
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
V_25 -> V_409 ++ ;
if ( F_294 ( V_25 ) )
break;
F_237 ( V_28 , 1 ) ;
F_219 ( V_25 ) ;
}
if ( ! V_28 )
F_304 ( V_24 , 1 ) ;
F_334 ( V_24 ) ;
}
static void F_338 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_113 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_444 = V_113 & V_115 ;
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
F_263 ( V_25 , V_28 , V_113 ) ;
if ( F_294 ( V_25 ) )
break;
V_25 -> V_409 -- ;
if ( V_25 -> V_71 . V_4 ) {
V_28 = F_31 ( V_28 ) ;
if ( V_444 && V_28 && ! F_220 ( V_25 ) )
F_339 ( V_28 ) ;
break;
}
V_113 |= V_115 ;
}
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
V_25 -> V_409 -- ;
if ( F_294 ( V_25 ) )
break;
F_237 ( V_28 , 1 ) ;
F_219 ( V_25 ) ;
}
if ( ! V_28 )
F_300 ( V_24 , 1 ) ;
F_334 ( V_24 ) ;
}
static unsigned long
F_340 ( unsigned long V_71 , unsigned long V_445 , int V_446 )
{
int V_447 = 0 ;
if ( ! V_445 )
return V_71 ;
if ( V_445 >= V_448 [ V_446 ] )
return 0 ;
if ( V_446 == 1 )
return V_71 >> V_445 ;
while ( V_445 ) {
if ( V_445 % 2 )
V_71 = ( V_71 * V_449 [ V_446 ] [ V_447 ] ) >> V_450 ;
V_445 >>= 1 ;
V_447 ++ ;
}
return V_71 ;
}
static void F_341 ( struct V_24 * F_233 , unsigned long V_451 ,
unsigned long V_452 )
{
unsigned long T_11 V_453 = F_233 -> V_454 [ 0 ] ;
int V_270 , V_455 ;
F_233 -> V_456 ++ ;
F_233 -> V_454 [ 0 ] = V_451 ;
for ( V_270 = 1 , V_455 = 2 ; V_270 < V_457 ; V_270 ++ , V_455 += V_455 ) {
unsigned long V_458 , V_459 ;
V_458 = F_233 -> V_454 [ V_270 ] ;
#ifdef F_342
V_458 = F_340 ( V_458 , V_452 - 1 , V_270 ) ;
if ( V_453 ) {
V_458 -= F_340 ( V_453 , V_452 - 1 , V_270 ) ;
V_458 += V_453 ;
}
#endif
V_459 = V_451 ;
if ( V_459 > V_458 )
V_459 += V_455 - 1 ;
F_233 -> V_454 [ V_270 ] = ( V_458 * ( V_455 - 1 ) + V_459 ) >> V_270 ;
}
F_343 ( F_233 ) ;
}
static unsigned long F_125 ( const int V_175 )
{
return F_243 ( & F_124 ( V_175 ) -> V_40 ) ;
}
static void F_344 ( struct V_24 * F_233 ,
unsigned long V_460 ,
unsigned long V_71 )
{
unsigned long V_452 ;
V_452 = V_460 - F_233 -> V_461 ;
if ( V_452 ) {
F_233 -> V_461 = V_460 ;
F_341 ( F_233 , V_71 , V_452 ) ;
}
}
static void F_345 ( struct V_24 * F_233 )
{
if ( F_125 ( F_25 ( F_233 ) ) )
return;
F_344 ( F_233 , F_98 ( V_222 ) , 0 ) ;
}
void F_346 ( void )
{
struct V_24 * F_233 = F_233 () ;
F_233 -> V_454 [ 0 ] = F_125 ( F_25 ( F_233 ) ) ;
}
void F_347 ( void )
{
unsigned long V_460 = F_98 ( V_222 ) ;
struct V_24 * F_233 = F_233 () ;
unsigned long V_71 ;
if ( V_460 == F_233 -> V_461 )
return;
V_71 = F_125 ( F_25 ( F_233 ) ) ;
F_289 ( & F_233 -> V_255 ) ;
F_303 ( F_233 ) ;
F_344 ( F_233 , V_460 , V_71 ) ;
F_291 ( & F_233 -> V_255 ) ;
}
static inline void F_344 ( struct V_24 * F_233 ,
unsigned long V_460 ,
unsigned long V_71 ) { }
static void F_348 ( struct V_24 * F_233 , unsigned long V_71 )
{
#ifdef F_342
F_233 -> V_461 = F_98 ( V_222 ) ;
#endif
F_341 ( F_233 , V_71 , 1 ) ;
}
void F_349 ( struct V_24 * F_233 )
{
unsigned long V_71 = F_125 ( F_25 ( F_233 ) ) ;
if ( F_350 () )
F_344 ( F_233 , F_98 ( V_222 ) , V_71 ) ;
else
F_348 ( F_233 , V_71 ) ;
}
static unsigned long F_351 ( int V_175 , int type )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
unsigned long V_462 = F_125 ( V_175 ) ;
if ( type == 0 || ! F_230 ( V_463 ) )
return V_462 ;
return F_155 ( V_24 -> V_454 [ type - 1 ] , V_462 ) ;
}
static unsigned long F_352 ( int V_175 , int type )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
unsigned long V_462 = F_125 ( V_175 ) ;
if ( type == 0 || ! F_230 ( V_463 ) )
return V_462 ;
return F_69 ( V_24 -> V_454 [ type - 1 ] , V_462 ) ;
}
static unsigned long F_126 ( int V_175 )
{
return F_124 ( V_175 ) -> V_464 ;
}
static unsigned long F_353 ( int V_175 )
{
return F_124 ( V_175 ) -> V_465 ;
}
static unsigned long F_354 ( int V_175 )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
unsigned long V_73 = F_98 ( V_24 -> V_40 . V_409 ) ;
unsigned long V_80 = F_125 ( V_175 ) ;
if ( V_73 )
return V_80 / V_73 ;
return 0 ;
}
static long F_355 ( struct V_323 * V_33 , int V_175 , long V_466 , long V_467 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_175 ] ;
if ( ! V_33 -> V_34 )
return V_466 ;
F_58 (se) {
struct V_25 * V_25 = V_28 -> V_31 ;
long V_468 , V_7 = F_244 ( V_25 ) ;
V_33 = V_25 -> V_33 ;
V_468 = V_467 + F_217 ( & V_33 -> V_80 ) ;
V_468 -= V_25 -> V_326 ;
V_468 += V_7 ;
V_7 += V_466 ;
if ( V_468 > 0 && V_7 < V_468 )
V_466 = ( V_7 * ( long ) F_12 ( V_33 -> V_325 ) ) / V_468 ;
else
V_466 = F_12 ( V_33 -> V_325 ) ;
if ( V_466 < V_327 )
V_466 = V_327 ;
V_466 -= V_28 -> V_77 . V_80 ;
V_467 = 0 ;
}
return V_466 ;
}
static long F_355 ( struct V_323 * V_33 , int V_175 , long V_466 , long V_467 )
{
return V_466 ;
}
static void F_356 ( struct V_26 * V_29 )
{
if ( F_193 ( V_222 , V_170 -> V_469 + V_220 ) ) {
V_170 -> V_470 >>= 1 ;
V_170 -> V_469 = V_222 ;
}
if ( V_170 -> V_471 != V_29 ) {
V_170 -> V_471 = V_29 ;
V_170 -> V_470 ++ ;
}
}
static int F_357 ( struct V_26 * V_29 )
{
unsigned int V_472 = V_170 -> V_470 ;
unsigned int V_473 = V_29 -> V_470 ;
int V_9 = F_358 ( V_474 ) ;
if ( V_472 < V_473 )
F_132 ( V_472 , V_473 ) ;
if ( V_473 < V_9 || V_472 < V_473 * V_9 )
return 0 ;
return 1 ;
}
static int F_359 ( struct V_210 * V_211 , struct V_26 * V_29 ,
int V_475 , int V_476 )
{
T_3 V_451 , V_71 ;
T_3 V_477 , V_478 ;
int V_446 , V_479 ;
struct V_323 * V_33 ;
unsigned long V_4 ;
int V_480 ;
V_446 = V_211 -> V_481 ;
V_479 = F_285 () ;
V_71 = F_351 ( V_475 , V_446 ) ;
V_451 = F_352 ( V_479 , V_446 ) ;
if ( V_476 ) {
V_33 = V_323 ( V_170 ) ;
V_4 = V_170 -> V_28 . V_77 . V_80 ;
V_451 += F_355 ( V_33 , V_479 , - V_4 , - V_4 ) ;
V_71 += F_355 ( V_33 , V_475 , 0 , - V_4 ) ;
}
V_33 = V_323 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_77 . V_80 ;
V_477 = 100 ;
V_477 *= F_126 ( V_475 ) ;
V_478 = 100 + ( V_211 -> V_196 - 100 ) / 2 ;
V_478 *= F_126 ( V_479 ) ;
if ( V_451 > 0 ) {
V_477 *= V_451 +
F_355 ( V_33 , V_479 , V_4 , V_4 ) ;
V_478 *= V_71 + F_355 ( V_33 , V_475 , 0 , V_4 ) ;
}
V_480 = V_477 <= V_478 ;
F_83 ( V_29 -> V_28 . V_92 . V_482 ) ;
if ( ! V_480 )
return 0 ;
F_83 ( V_211 -> V_483 ) ;
F_83 ( V_29 -> V_28 . V_92 . V_484 ) ;
return 1 ;
}
static struct V_485 *
F_360 ( struct V_210 * V_211 , struct V_26 * V_29 ,
int V_479 , int V_486 )
{
struct V_485 * V_487 = NULL , * V_146 = V_211 -> V_488 ;
unsigned long V_489 = V_490 , V_451 = 0 ;
int V_491 = V_211 -> V_492 ;
int V_493 = 100 + ( V_211 -> V_196 - 100 ) / 2 ;
if ( V_486 & V_494 )
V_491 = V_211 -> V_481 ;
do {
unsigned long V_71 , V_495 ;
int V_496 ;
int V_270 ;
if ( ! F_361 ( F_362 ( V_146 ) ,
F_138 ( V_29 ) ) )
continue;
V_496 = F_137 ( V_479 ,
F_362 ( V_146 ) ) ;
V_495 = 0 ;
F_123 (i, sched_group_cpus(group)) {
if ( V_496 )
V_71 = F_351 ( V_270 , V_491 ) ;
else
V_71 = F_352 ( V_270 , V_491 ) ;
V_495 += V_71 ;
}
V_495 = ( V_495 * V_86 ) / V_146 -> V_497 -> V_176 ;
if ( V_496 ) {
V_451 = V_495 ;
} else if ( V_495 < V_489 ) {
V_489 = V_495 ;
V_487 = V_146 ;
}
} while ( V_146 = V_146 -> V_59 , V_146 != V_211 -> V_488 );
if ( ! V_487 || 100 * V_451 < V_493 * V_489 )
return NULL ;
return V_487 ;
}
static int
F_363 ( struct V_485 * V_146 , struct V_26 * V_29 , int V_479 )
{
unsigned long V_71 , V_489 = V_490 ;
unsigned int V_498 = V_499 ;
T_2 V_500 = 0 ;
int V_501 = V_479 ;
int V_502 = - 1 ;
int V_270 ;
if ( V_146 -> F_114 == 1 )
return F_364 ( F_362 ( V_146 ) ) ;
F_365 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_366 ( V_270 ) ) {
struct V_24 * V_24 = F_124 ( V_270 ) ;
struct V_503 * V_398 = F_367 ( V_24 ) ;
if ( V_398 && V_398 -> V_504 < V_498 ) {
V_498 = V_398 -> V_504 ;
V_500 = V_24 -> V_505 ;
V_502 = V_270 ;
} else if ( ( ! V_398 || V_398 -> V_504 == V_498 ) &&
V_24 -> V_505 > V_500 ) {
V_500 = V_24 -> V_505 ;
V_502 = V_270 ;
}
} else if ( V_502 == - 1 ) {
V_71 = F_125 ( V_270 ) ;
if ( V_71 < V_489 || ( V_71 == V_489 && V_270 == V_479 ) ) {
V_489 = V_71 ;
V_501 = V_270 ;
}
}
}
return V_502 != - 1 ? V_502 : V_501 ;
}
static int F_368 ( int V_329 , const struct V_506 * V_507 , int V_298 , int * V_508 )
{
int V_59 ;
V_509:
V_59 = F_369 ( F_370 ( V_507 ) , V_510 , V_329 + 1 ) ;
if ( * V_508 ) {
if ( V_59 >= V_298 )
return V_510 ;
} else {
if ( V_59 >= V_510 ) {
* V_508 = 1 ;
V_329 = - 1 ;
goto V_509;
}
}
return V_59 ;
}
static inline void F_371 ( int V_175 , int V_328 )
{
struct V_511 * V_512 ;
V_512 = F_148 ( F_149 ( V_513 , V_175 ) ) ;
if ( V_512 )
F_195 ( V_512 -> V_514 , V_328 ) ;
}
static inline bool F_372 ( int V_175 , bool V_515 )
{
struct V_511 * V_512 ;
V_512 = F_148 ( F_149 ( V_513 , V_175 ) ) ;
if ( V_512 )
return F_98 ( V_512 -> V_514 ) ;
return V_515 ;
}
void F_373 ( struct V_24 * V_24 )
{
int V_516 = F_25 ( V_24 ) ;
int V_175 ;
F_134 () ;
if ( F_372 ( V_516 , true ) )
goto V_205;
F_123 (cpu, cpu_smt_mask(core)) {
if ( V_175 == V_516 )
continue;
if ( ! F_366 ( V_175 ) )
goto V_205;
}
F_371 ( V_516 , 1 ) ;
V_205:
F_143 () ;
}
static int F_374 ( struct V_26 * V_29 , struct V_210 * V_211 , int V_517 )
{
struct V_506 * V_8 = F_375 ( V_518 ) ;
int V_516 , V_175 , V_519 ;
if ( ! F_192 ( & V_520 ) )
return - 1 ;
if ( ! F_372 ( V_517 , false ) )
return - 1 ;
F_376 ( V_8 , F_377 ( V_211 ) , F_138 ( V_29 ) ) ;
F_378 (core, cpus, target, wrap) {
bool V_398 = true ;
F_123 (cpu, cpu_smt_mask(core)) {
F_379 ( V_175 , V_8 ) ;
if ( ! F_366 ( V_175 ) )
V_398 = false ;
}
if ( V_398 )
return V_516 ;
}
F_371 ( V_517 , 0 ) ;
return - 1 ;
}
static int F_380 ( struct V_26 * V_29 , struct V_210 * V_211 , int V_517 )
{
int V_175 ;
if ( ! F_192 ( & V_520 ) )
return - 1 ;
F_123 (cpu, cpu_smt_mask(target)) {
if ( ! F_137 ( V_175 , F_138 ( V_29 ) ) )
continue;
if ( F_366 ( V_175 ) )
return V_175 ;
}
return - 1 ;
}
static inline int F_374 ( struct V_26 * V_29 , struct V_210 * V_211 , int V_517 )
{
return - 1 ;
}
static inline int F_380 ( struct V_26 * V_29 , struct V_210 * V_211 , int V_517 )
{
return - 1 ;
}
static int F_381 ( struct V_26 * V_29 , struct V_210 * V_211 , int V_517 )
{
struct V_210 * V_521 ;
T_2 V_522 , V_523 = F_233 () -> V_523 ;
T_2 time , V_524 ;
T_3 V_42 ;
int V_175 , V_519 ;
V_521 = F_148 ( * F_382 ( & V_525 ) ) ;
if ( ! V_521 )
return - 1 ;
V_522 = V_521 -> V_526 ;
if ( ( V_523 / 512 ) < V_522 )
return - 1 ;
time = F_383 () ;
F_378 (cpu, sched_domain_span(sd), target, wrap) {
if ( ! F_137 ( V_175 , F_138 ( V_29 ) ) )
continue;
if ( F_366 ( V_175 ) )
break;
}
time = F_383 () - time ;
V_524 = V_521 -> V_526 ;
V_42 = ( T_3 ) ( time - V_524 ) / 8 ;
V_521 -> V_526 += V_42 ;
return V_175 ;
}
static int F_141 ( struct V_26 * V_29 , int V_348 , int V_517 )
{
struct V_210 * V_211 ;
int V_270 ;
if ( F_366 ( V_517 ) )
return V_517 ;
if ( V_348 != V_517 && F_384 ( V_348 , V_517 ) && F_366 ( V_348 ) )
return V_348 ;
V_211 = F_148 ( F_149 ( V_525 , V_517 ) ) ;
if ( ! V_211 )
return V_517 ;
V_270 = F_374 ( V_29 , V_211 , V_517 ) ;
if ( ( unsigned ) V_270 < V_510 )
return V_270 ;
V_270 = F_381 ( V_29 , V_211 , V_517 ) ;
if ( ( unsigned ) V_270 < V_510 )
return V_270 ;
V_270 = F_380 ( V_29 , V_211 , V_517 ) ;
if ( ( unsigned ) V_270 < V_510 )
return V_270 ;
return V_517 ;
}
static int F_385 ( int V_175 )
{
unsigned long V_527 = F_124 ( V_175 ) -> V_40 . V_77 . V_83 ;
unsigned long V_176 = F_353 ( V_175 ) ;
return ( V_527 >= V_176 ) ? V_176 : V_527 ;
}
static inline int F_386 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_83 ;
}
static int F_387 ( struct V_26 * V_29 , int V_175 , int V_475 )
{
long V_528 , V_529 ;
V_528 = F_155 ( F_353 ( V_475 ) , F_353 ( V_175 ) ) ;
V_529 = F_124 ( V_175 ) -> V_530 -> V_531 ;
if ( V_529 - V_528 < V_529 > > 3 )
return 0 ;
return V_528 * 1024 < F_386 ( V_29 ) * V_532 ;
}
static int
F_388 ( struct V_26 * V_29 , int V_475 , int V_486 , int V_533 )
{
struct V_210 * V_534 , * V_535 = NULL , * V_211 = NULL ;
int V_175 = F_285 () ;
int V_536 = V_475 ;
int V_537 = 0 ;
int V_476 = V_533 & V_538 ;
if ( V_486 & V_494 ) {
F_356 ( V_29 ) ;
V_537 = ! F_357 ( V_29 ) && ! F_387 ( V_29 , V_175 , V_475 )
&& F_137 ( V_175 , F_138 ( V_29 ) ) ;
}
F_134 () ;
F_389 (cpu, tmp) {
if ( ! ( V_534 -> V_113 & V_539 ) )
break;
if ( V_537 && ( V_534 -> V_113 & V_540 ) &&
F_137 ( V_475 , F_377 ( V_534 ) ) ) {
V_535 = V_534 ;
break;
}
if ( V_534 -> V_113 & V_486 )
V_211 = V_534 ;
else if ( ! V_537 )
break;
}
if ( V_535 ) {
V_211 = NULL ;
if ( V_175 != V_475 && F_359 ( V_535 , V_29 , V_475 , V_476 ) )
V_536 = V_175 ;
}
if ( ! V_211 ) {
if ( V_486 & V_494 )
V_536 = F_141 ( V_29 , V_475 , V_536 ) ;
} else while ( V_211 ) {
struct V_485 * V_146 ;
int V_4 ;
if ( ! ( V_211 -> V_113 & V_486 ) ) {
V_211 = V_211 -> V_541 ;
continue;
}
V_146 = F_360 ( V_211 , V_29 , V_175 , V_486 ) ;
if ( ! V_146 ) {
V_211 = V_211 -> V_541 ;
continue;
}
V_536 = F_363 ( V_146 , V_29 , V_175 ) ;
if ( V_536 == - 1 || V_536 == V_175 ) {
V_211 = V_211 -> V_541 ;
continue;
}
V_175 = V_536 ;
V_4 = V_211 -> V_542 ;
V_211 = NULL ;
F_389 (cpu, tmp) {
if ( V_4 <= V_534 -> V_542 )
break;
if ( V_534 -> V_113 & V_486 )
V_211 = V_534 ;
}
}
F_143 () ;
return V_536 ;
}
static void F_390 ( struct V_26 * V_29 )
{
if ( V_29 -> V_116 == V_543 ) {
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_28 ) ;
T_2 F_35 ;
#ifndef F_39
T_2 V_49 ;
do {
V_49 = V_25 -> V_49 ;
F_231 () ;
F_35 = V_25 -> F_35 ;
} while ( F_35 != V_49 );
#else
F_35 = V_25 -> F_35 ;
#endif
V_28 -> V_41 -= F_35 ;
}
F_242 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_29 -> V_28 . V_91 = 0 ;
}
static void F_391 ( struct V_26 * V_29 )
{
F_242 ( & V_29 -> V_28 ) ;
}
static unsigned long
F_392 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_544 = V_545 ;
return F_55 ( V_544 , V_28 ) ;
}
static int
F_269 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_544 , V_546 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_546 <= 0 )
return - 1 ;
V_544 = F_392 ( V_45 , V_28 ) ;
if ( V_546 > V_544 )
return 1 ;
return 0 ;
}
static void F_393 ( struct V_27 * V_28 )
{
if ( F_19 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_547 == V_548 ) )
return;
F_58 (se)
F_22 ( V_28 ) -> V_60 = V_28 ;
}
static void F_339 ( struct V_27 * V_28 )
{
if ( F_19 ( V_28 ) && F_13 ( F_17 ( V_28 ) -> V_547 == V_548 ) )
return;
F_58 (se)
F_22 ( V_28 ) -> V_59 = V_28 ;
}
static void F_394 ( struct V_27 * V_28 )
{
F_58 (se)
F_22 ( V_28 ) -> V_373 = V_28 ;
}
static void F_395 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_533 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_21 ( V_45 ) ;
int V_455 = V_25 -> V_73 >= V_68 ;
int V_549 = 0 ;
if ( F_13 ( V_28 == V_36 ) )
return;
if ( F_13 ( F_220 ( F_22 ( V_36 ) ) ) )
return;
if ( F_230 ( V_550 ) && V_455 && ! ( V_533 & V_551 ) ) {
F_339 ( V_36 ) ;
V_549 = 1 ;
}
if ( F_396 ( V_45 ) )
return;
if ( F_13 ( V_45 -> V_547 == V_548 ) &&
F_11 ( V_29 -> V_547 != V_548 ) )
goto V_552;
if ( F_13 ( V_29 -> V_547 != V_553 ) || ! F_230 ( V_554 ) )
return;
F_32 ( & V_28 , & V_36 ) ;
F_66 ( F_22 ( V_28 ) ) ;
F_182 ( ! V_36 ) ;
if ( F_269 ( V_28 , V_36 ) == 1 ) {
if ( ! V_549 )
F_339 ( V_36 ) ;
goto V_552;
}
return;
V_552:
F_266 ( V_24 ) ;
if ( F_13 ( ! V_28 -> V_46 || V_45 == V_24 -> V_398 ) )
return;
if ( F_230 ( V_555 ) && V_455 && F_19 ( V_28 ) )
F_393 ( V_28 ) ;
}
static struct V_26 *
F_397 ( struct V_24 * V_24 , struct V_26 * V_348 , struct V_556 V_557 )
{
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
int V_558 ;
V_509:
#ifdef F_398
if ( ! V_25 -> V_73 )
goto V_398;
if ( V_348 -> V_88 != & V_89 )
goto V_559;
do {
struct V_27 * V_45 = V_25 -> V_45 ;
if ( V_45 ) {
if ( V_45 -> V_46 )
F_66 ( V_25 ) ;
else
V_45 = NULL ;
if ( F_13 ( F_271 ( V_25 ) ) )
goto V_559;
}
V_28 = F_268 ( V_25 , V_45 ) ;
V_25 = F_23 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( V_348 != V_29 ) {
struct V_27 * V_36 = & V_348 -> V_28 ;
while ( ! ( V_25 = F_30 ( V_28 , V_36 ) ) ) {
int V_37 = V_28 -> V_39 ;
int V_38 = V_36 -> V_39 ;
if ( V_37 <= V_38 ) {
F_270 ( F_22 ( V_36 ) , V_36 ) ;
V_36 = F_31 ( V_36 ) ;
}
if ( V_37 >= V_38 ) {
F_267 ( F_22 ( V_28 ) , V_28 ) ;
V_28 = F_31 ( V_28 ) ;
}
}
F_270 ( V_25 , V_36 ) ;
F_267 ( V_25 , V_28 ) ;
}
if ( F_335 ( V_24 ) )
F_332 ( V_24 , V_29 ) ;
return V_29 ;
V_559:
V_25 = & V_24 -> V_40 ;
#endif
if ( ! V_25 -> V_73 )
goto V_398;
F_399 ( V_24 , V_348 ) ;
do {
V_28 = F_268 ( V_25 , NULL ) ;
F_267 ( V_25 , V_28 ) ;
V_25 = F_23 ( V_28 ) ;
} while ( V_25 );
V_29 = F_17 ( V_28 ) ;
if ( F_335 ( V_24 ) )
F_332 ( V_24 , V_29 ) ;
return V_29 ;
V_398:
F_400 ( & V_24 -> V_255 , V_557 ) ;
V_558 = F_245 ( V_24 ) ;
F_401 ( & V_24 -> V_255 , V_557 ) ;
if ( V_558 < 0 )
return V_560 ;
if ( V_558 > 0 )
goto V_509;
return NULL ;
}
static void F_402 ( struct V_24 * V_24 , struct V_26 * V_348 )
{
struct V_27 * V_28 = & V_348 -> V_28 ;
struct V_25 * V_25 ;
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
F_270 ( V_25 , V_28 ) ;
}
}
static void F_403 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_21 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_13 ( V_24 -> V_73 == 1 ) )
return;
F_262 ( V_25 , V_28 ) ;
if ( V_45 -> V_547 != V_561 ) {
F_303 ( V_24 ) ;
F_66 ( V_25 ) ;
F_404 ( V_24 , true ) ;
}
F_394 ( V_28 ) ;
}
static bool F_405 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_552 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_46 || F_220 ( F_22 ( V_28 ) ) )
return false ;
F_339 ( V_28 ) ;
F_403 ( V_24 ) ;
return true ;
}
static int F_406 ( struct V_26 * V_29 , struct V_562 * V_181 )
{
T_3 V_42 ;
F_325 ( & V_181 -> V_199 -> V_255 ) ;
if ( V_29 -> V_88 != & V_89 )
return 0 ;
if ( F_13 ( V_29 -> V_547 == V_548 ) )
return 0 ;
if ( F_230 ( V_563 ) && V_181 -> V_201 -> V_73 &&
( & V_29 -> V_28 == F_22 ( & V_29 -> V_28 ) -> V_59 ||
& V_29 -> V_28 == F_22 ( & V_29 -> V_28 ) -> V_60 ) )
return 1 ;
if ( V_564 == - 1 )
return 1 ;
if ( V_564 == 0 )
return 0 ;
V_42 = F_67 ( V_181 -> V_199 ) - V_29 -> V_28 . V_91 ;
return V_42 < ( T_3 ) V_564 ;
}
static int F_407 ( struct V_26 * V_29 , struct V_562 * V_181 )
{
struct V_135 * V_135 = F_148 ( V_29 -> V_135 ) ;
unsigned long V_565 , V_566 ;
int V_165 , V_167 ;
if ( ! F_192 ( & V_284 ) )
return - 1 ;
if ( ! V_29 -> V_143 || ! ( V_181 -> V_211 -> V_113 & V_567 ) )
return - 1 ;
V_165 = F_116 ( V_181 -> V_200 ) ;
V_167 = F_116 ( V_181 -> V_166 ) ;
if ( V_165 == V_167 )
return - 1 ;
if ( V_165 == V_29 -> V_133 ) {
if ( V_181 -> V_199 -> V_73 > V_181 -> V_199 -> V_134 )
return 1 ;
else
return - 1 ;
}
if ( V_167 == V_29 -> V_133 )
return 0 ;
if ( V_135 ) {
V_565 = F_107 ( V_29 , V_165 ) ;
V_566 = F_107 ( V_29 , V_167 ) ;
} else {
V_565 = F_106 ( V_29 , V_165 ) ;
V_566 = F_106 ( V_29 , V_167 ) ;
}
return V_566 < V_565 ;
}
static inline int F_407 ( struct V_26 * V_29 ,
struct V_562 * V_181 )
{
return - 1 ;
}
static
int F_408 ( struct V_26 * V_29 , struct V_562 * V_181 )
{
int V_568 ;
F_325 ( & V_181 -> V_199 -> V_255 ) ;
if ( F_295 ( V_323 ( V_29 ) , V_181 -> V_200 , V_181 -> V_166 ) )
return 0 ;
if ( ! F_137 ( V_181 -> V_166 , F_138 ( V_29 ) ) ) {
int V_175 ;
F_83 ( V_29 -> V_28 . V_92 . V_569 ) ;
V_181 -> V_113 |= V_570 ;
if ( ! V_181 -> V_571 || ( V_181 -> V_113 & V_572 ) )
return 0 ;
F_365 (cpu, env->dst_grpmask, env->cpus) {
if ( F_137 ( V_175 , F_138 ( V_29 ) ) ) {
V_181 -> V_113 |= V_572 ;
V_181 -> V_573 = V_175 ;
break;
}
}
return 0 ;
}
V_181 -> V_113 &= ~ V_574 ;
if ( F_409 ( V_181 -> V_199 , V_29 ) ) {
F_83 ( V_29 -> V_28 . V_92 . V_575 ) ;
return 0 ;
}
V_568 = F_407 ( V_29 , V_181 ) ;
if ( V_568 == - 1 )
V_568 = F_406 ( V_29 , V_181 ) ;
if ( V_568 <= 0 ||
V_181 -> V_211 -> V_576 > V_181 -> V_211 -> V_577 ) {
if ( V_568 == 1 ) {
F_83 ( V_181 -> V_211 -> V_578 [ V_181 -> V_398 ] ) ;
F_83 ( V_29 -> V_28 . V_92 . V_579 ) ;
}
return 1 ;
}
F_83 ( V_29 -> V_28 . V_92 . V_580 ) ;
return 0 ;
}
static void F_410 ( struct V_26 * V_29 , struct V_562 * V_181 )
{
F_325 ( & V_181 -> V_199 -> V_255 ) ;
V_29 -> V_46 = V_581 ;
F_411 ( V_181 -> V_199 , V_29 , 0 ) ;
F_412 ( V_29 , V_181 -> V_166 ) ;
}
static struct V_26 * F_413 ( struct V_562 * V_181 )
{
struct V_26 * V_29 , * V_329 ;
F_325 ( & V_181 -> V_199 -> V_255 ) ;
F_414 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_408 ( V_29 , V_181 ) )
continue;
F_410 ( V_29 , V_181 ) ;
F_83 ( V_181 -> V_211 -> V_582 [ V_181 -> V_398 ] ) ;
return V_29 ;
}
return NULL ;
}
static int F_415 ( struct V_562 * V_181 )
{
struct V_583 * V_584 = & V_181 -> V_199 -> V_322 ;
struct V_26 * V_29 ;
unsigned long V_71 ;
int V_585 = 0 ;
F_325 ( & V_181 -> V_199 -> V_255 ) ;
if ( V_181 -> V_493 <= 0 )
return 0 ;
while ( ! F_301 ( V_584 ) ) {
if ( V_181 -> V_398 != V_586 && V_181 -> V_199 -> V_73 <= 1 )
break;
V_29 = F_416 ( V_584 , struct V_26 , V_28 . V_321 ) ;
V_181 -> V_587 ++ ;
if ( V_181 -> V_587 > V_181 -> V_588 )
break;
if ( V_181 -> V_587 > V_181 -> V_589 ) {
V_181 -> V_589 += V_590 ;
V_181 -> V_113 |= V_591 ;
break;
}
if ( ! F_408 ( V_29 , V_181 ) )
goto V_59;
V_71 = F_139 ( V_29 ) ;
if ( F_230 ( V_592 ) && V_71 < 16 && ! V_181 -> V_211 -> V_576 )
goto V_59;
if ( ( V_71 / 2 ) > V_181 -> V_493 )
goto V_59;
F_410 ( V_29 , V_181 ) ;
F_213 ( & V_29 -> V_28 . V_321 , & V_181 -> V_584 ) ;
V_585 ++ ;
V_181 -> V_493 -= V_71 ;
#ifdef F_417
if ( V_181 -> V_398 == V_593 )
break;
#endif
if ( V_181 -> V_493 <= 0 )
break;
continue;
V_59:
F_418 ( & V_29 -> V_28 . V_321 , V_584 ) ;
}
F_70 ( V_181 -> V_211 -> V_582 [ V_181 -> V_398 ] , V_585 ) ;
return V_585 ;
}
static void F_419 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_325 ( & V_24 -> V_255 ) ;
F_182 ( F_33 ( V_29 ) != V_24 ) ;
F_420 ( V_24 , V_29 , 0 ) ;
V_29 -> V_46 = V_594 ;
F_421 ( V_24 , V_29 , 0 ) ;
}
static void F_422 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_289 ( & V_24 -> V_255 ) ;
F_419 ( V_24 , V_29 ) ;
F_291 ( & V_24 -> V_255 ) ;
}
static void F_423 ( struct V_562 * V_181 )
{
struct V_583 * V_584 = & V_181 -> V_584 ;
struct V_26 * V_29 ;
F_289 ( & V_181 -> V_201 -> V_255 ) ;
while ( ! F_301 ( V_584 ) ) {
V_29 = F_416 ( V_584 , struct V_26 , V_28 . V_321 ) ;
F_215 ( & V_29 -> V_28 . V_321 ) ;
F_419 ( V_181 -> V_201 , V_29 ) ;
}
F_291 ( & V_181 -> V_201 -> V_255 ) ;
}
static void F_424 ( int V_175 )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
struct V_25 * V_25 ;
unsigned long V_113 ;
F_425 ( & V_24 -> V_255 , V_113 ) ;
F_303 ( V_24 ) ;
F_330 (rq, cfs_rq) {
if ( F_220 ( V_25 ) )
continue;
if ( F_63 ( F_62 ( V_25 ) , V_25 , true ) )
F_65 ( V_25 , 0 ) ;
}
F_426 ( & V_24 -> V_255 , V_113 ) ;
}
static void F_427 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_16 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_25 ( V_24 ) ] ;
unsigned long V_87 = V_222 ;
unsigned long V_71 ;
if ( V_25 -> V_595 == V_87 )
return;
V_25 -> V_596 = NULL ;
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
V_25 -> V_596 = V_28 ;
if ( V_25 -> V_595 == V_87 )
break;
}
if ( ! V_28 ) {
V_25 -> V_597 = F_244 ( V_25 ) ;
V_25 -> V_595 = V_87 ;
}
while ( ( V_28 = V_25 -> V_596 ) != NULL ) {
V_71 = V_25 -> V_597 ;
V_71 = F_428 ( V_71 * V_28 -> V_77 . V_80 ,
F_244 ( V_25 ) + 1 ) ;
V_25 = F_23 ( V_28 ) ;
V_25 -> V_597 = V_71 ;
V_25 -> V_595 = V_87 ;
}
}
static unsigned long F_139 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_21 ( V_29 ) ;
F_427 ( V_25 ) ;
return F_428 ( V_29 -> V_28 . V_77 . V_80 * V_25 -> V_597 ,
F_244 ( V_25 ) + 1 ) ;
}
static inline void F_424 ( int V_175 )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
struct V_25 * V_25 = & V_24 -> V_40 ;
unsigned long V_113 ;
F_425 ( & V_24 -> V_255 , V_113 ) ;
F_303 ( V_24 ) ;
F_63 ( F_62 ( V_25 ) , V_25 , true ) ;
F_426 ( & V_24 -> V_255 , V_113 ) ;
}
static unsigned long F_139 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_80 ;
}
static inline void F_429 ( struct V_598 * V_512 )
{
* V_512 = (struct V_598 ) {
. V_599 = NULL ,
. V_231 = NULL ,
. V_600 = 0UL ,
. V_601 = 0UL ,
. V_602 = {
. V_495 = 0UL ,
. V_603 = 0 ,
. V_604 = V_605 ,
} ,
} ;
}
static inline int F_430 ( struct V_210 * V_211 ,
enum V_606 V_398 )
{
int V_491 ;
switch ( V_398 ) {
case V_586 :
V_491 = V_211 -> V_607 ;
break;
case V_593 :
V_491 = V_211 -> V_608 ;
break;
default:
V_491 = V_211 -> V_609 ;
break;
}
return V_491 ;
}
static unsigned long F_431 ( int V_175 )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
T_2 V_462 , V_610 , V_611 , V_77 ;
T_3 V_42 ;
V_611 = F_98 ( V_24 -> V_611 ) ;
V_77 = F_98 ( V_24 -> V_612 ) ;
V_42 = F_432 ( V_24 ) - V_611 ;
if ( F_13 ( V_42 < 0 ) )
V_42 = 0 ;
V_462 = F_433 () + V_42 ;
V_610 = F_227 ( V_77 , V_462 ) ;
if ( F_11 ( V_610 < V_86 ) )
return V_86 - V_610 ;
return 1 ;
}
static void F_434 ( struct V_210 * V_211 , int V_175 )
{
unsigned long V_176 = F_225 ( V_211 , V_175 ) ;
struct V_485 * V_613 = V_211 -> V_488 ;
F_124 ( V_175 ) -> V_465 = V_176 ;
V_176 *= F_431 ( V_175 ) ;
V_176 >>= V_614 ;
if ( ! V_176 )
V_176 = 1 ;
F_124 ( V_175 ) -> V_464 = V_176 ;
V_613 -> V_497 -> V_176 = V_176 ;
}
void F_435 ( struct V_210 * V_211 , int V_175 )
{
struct V_210 * V_541 = V_211 -> V_541 ;
struct V_485 * V_146 , * V_613 = V_211 -> V_488 ;
unsigned long V_176 ;
unsigned long V_219 ;
V_219 = F_156 ( V_211 -> V_615 ) ;
V_219 = F_159 ( V_219 , 1UL , V_616 ) ;
V_613 -> V_497 -> V_617 = V_222 + V_219 ;
if ( ! V_541 ) {
F_434 ( V_211 , V_175 ) ;
return;
}
V_176 = 0 ;
if ( V_541 -> V_113 & V_618 ) {
F_123 (cpu, sched_group_cpus(sdg)) {
struct V_619 * V_497 ;
struct V_24 * V_24 = F_124 ( V_175 ) ;
if ( F_13 ( ! V_24 -> V_211 ) ) {
V_176 += F_126 ( V_175 ) ;
continue;
}
V_497 = V_24 -> V_211 -> V_488 -> V_497 ;
V_176 += V_497 -> V_176 ;
}
} else {
V_146 = V_541 -> V_488 ;
do {
V_176 += V_146 -> V_497 -> V_176 ;
V_146 = V_146 -> V_59 ;
} while ( V_146 != V_541 -> V_488 );
}
V_613 -> V_497 -> V_176 = V_176 ;
}
static inline int
F_436 ( struct V_24 * V_24 , struct V_210 * V_211 )
{
return ( ( V_24 -> V_464 * V_211 -> V_196 ) <
( V_24 -> V_465 * 100 ) ) ;
}
static inline int F_437 ( struct V_485 * V_146 )
{
return V_146 -> V_497 -> V_493 ;
}
static inline bool
F_438 ( struct V_562 * V_181 , struct V_620 * V_621 )
{
if ( V_621 -> V_603 < V_621 -> F_114 )
return true ;
if ( ( V_621 -> V_622 * 100 ) >
( V_621 -> V_623 * V_181 -> V_211 -> V_196 ) )
return true ;
return false ;
}
static inline bool
F_439 ( struct V_562 * V_181 , struct V_620 * V_621 )
{
if ( V_621 -> V_603 <= V_621 -> F_114 )
return false ;
if ( ( V_621 -> V_622 * 100 ) <
( V_621 -> V_623 * V_181 -> V_211 -> V_196 ) )
return true ;
return false ;
}
static inline enum
V_604 F_440 ( struct V_485 * V_146 ,
struct V_620 * V_621 )
{
if ( V_621 -> V_624 )
return V_625 ;
if ( F_437 ( V_146 ) )
return V_626 ;
return V_605 ;
}
static inline void F_441 ( struct V_562 * V_181 ,
struct V_485 * V_146 , int V_491 ,
int V_496 , struct V_620 * V_621 ,
bool * V_627 )
{
unsigned long V_71 ;
int V_270 , V_73 ;
memset ( V_621 , 0 , sizeof( * V_621 ) ) ;
F_365 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_124 ( V_270 ) ;
if ( V_496 )
V_71 = F_352 ( V_270 , V_491 ) ;
else
V_71 = F_351 ( V_270 , V_491 ) ;
V_621 -> V_628 += V_71 ;
V_621 -> V_623 += F_385 ( V_270 ) ;
V_621 -> V_603 += V_24 -> V_40 . V_409 ;
V_73 = V_24 -> V_73 ;
if ( V_73 > 1 )
* V_627 = true ;
#ifdef F_442
V_621 -> V_132 += V_24 -> V_132 ;
V_621 -> V_134 += V_24 -> V_134 ;
#endif
V_621 -> V_629 += F_125 ( V_270 ) ;
if ( ! V_73 && F_366 ( V_270 ) )
V_621 -> V_630 ++ ;
}
V_621 -> V_622 = V_146 -> V_497 -> V_176 ;
V_621 -> V_495 = ( V_621 -> V_628 * V_86 ) / V_621 -> V_622 ;
if ( V_621 -> V_603 )
V_621 -> V_631 = V_621 -> V_629 / V_621 -> V_603 ;
V_621 -> F_114 = V_146 -> F_114 ;
V_621 -> V_624 = F_439 ( V_181 , V_621 ) ;
V_621 -> V_604 = F_440 ( V_146 , V_621 ) ;
}
static bool F_443 ( struct V_562 * V_181 ,
struct V_598 * V_512 ,
struct V_485 * V_632 ,
struct V_620 * V_621 )
{
struct V_620 * V_599 = & V_512 -> V_602 ;
if ( V_621 -> V_604 > V_599 -> V_604 )
return true ;
if ( V_621 -> V_604 < V_599 -> V_604 )
return false ;
if ( V_621 -> V_495 <= V_599 -> V_495 )
return false ;
if ( ! ( V_181 -> V_211 -> V_113 & V_633 ) )
return true ;
if ( V_181 -> V_398 == V_586 )
return true ;
if ( V_621 -> V_603 && V_181 -> V_166 < F_444 ( V_632 ) ) {
if ( ! V_512 -> V_599 )
return true ;
if ( F_444 ( V_512 -> V_599 ) < F_444 ( V_632 ) )
return true ;
}
return false ;
}
static inline enum V_634 F_445 ( struct V_620 * V_621 )
{
if ( V_621 -> V_603 > V_621 -> V_132 )
return V_635 ;
if ( V_621 -> V_603 > V_621 -> V_134 )
return V_229 ;
return V_636 ;
}
static inline enum V_634 F_446 ( struct V_24 * V_24 )
{
if ( V_24 -> V_73 > V_24 -> V_132 )
return V_635 ;
if ( V_24 -> V_73 > V_24 -> V_134 )
return V_229 ;
return V_636 ;
}
static inline enum V_634 F_445 ( struct V_620 * V_621 )
{
return V_636 ;
}
static inline enum V_634 F_446 ( struct V_24 * V_24 )
{
return V_635 ;
}
static inline void F_447 ( struct V_562 * V_181 , struct V_598 * V_512 )
{
struct V_210 * V_541 = V_181 -> V_211 -> V_541 ;
struct V_485 * V_632 = V_181 -> V_211 -> V_488 ;
struct V_620 V_637 ;
int V_491 , V_638 = 0 ;
bool V_627 = false ;
if ( V_541 && V_541 -> V_113 & V_639 )
V_638 = 1 ;
V_491 = F_430 ( V_181 -> V_211 , V_181 -> V_398 ) ;
do {
struct V_620 * V_621 = & V_637 ;
int V_496 ;
V_496 = F_137 ( V_181 -> V_166 , F_362 ( V_632 ) ) ;
if ( V_496 ) {
V_512 -> V_231 = V_632 ;
V_621 = & V_512 -> V_640 ;
if ( V_181 -> V_398 != V_593 ||
F_448 ( V_222 , V_632 -> V_497 -> V_617 ) )
F_435 ( V_181 -> V_211 , V_181 -> V_166 ) ;
}
F_441 ( V_181 , V_632 , V_491 , V_496 , V_621 ,
& V_627 ) ;
if ( V_496 )
goto V_641;
if ( V_638 && V_512 -> V_231 &&
F_438 ( V_181 , & V_512 -> V_640 ) &&
( V_621 -> V_603 > 1 ) ) {
V_621 -> V_624 = 1 ;
V_621 -> V_604 = F_440 ( V_632 , V_621 ) ;
}
if ( F_443 ( V_181 , V_512 , V_632 , V_621 ) ) {
V_512 -> V_599 = V_632 ;
V_512 -> V_602 = * V_621 ;
}
V_641:
V_512 -> V_600 += V_621 -> V_628 ;
V_512 -> V_601 += V_621 -> V_622 ;
V_632 = V_632 -> V_59 ;
} while ( V_632 != V_181 -> V_211 -> V_488 );
if ( V_181 -> V_211 -> V_113 & V_567 )
V_181 -> V_634 = F_445 ( & V_512 -> V_602 ) ;
if ( ! V_181 -> V_211 -> V_34 ) {
if ( V_181 -> V_201 -> V_530 -> V_627 != V_627 )
V_181 -> V_201 -> V_530 -> V_627 = V_627 ;
}
}
static int F_449 ( struct V_562 * V_181 , struct V_598 * V_512 )
{
int V_642 ;
if ( ! ( V_181 -> V_211 -> V_113 & V_633 ) )
return 0 ;
if ( V_181 -> V_398 == V_586 )
return 0 ;
if ( ! V_512 -> V_599 )
return 0 ;
V_642 = F_444 ( V_512 -> V_599 ) ;
if ( V_181 -> V_166 > V_642 )
return 0 ;
V_181 -> V_493 = F_127 (
V_512 -> V_602 . V_495 * V_512 -> V_602 . V_622 ,
V_86 ) ;
return 1 ;
}
static inline
void F_450 ( struct V_562 * V_181 , struct V_598 * V_512 )
{
unsigned long V_534 , V_643 = 0 , V_644 = 0 ;
unsigned int V_645 = 2 ;
unsigned long V_646 ;
struct V_620 * V_231 , * V_599 ;
V_231 = & V_512 -> V_640 ;
V_599 = & V_512 -> V_602 ;
if ( ! V_231 -> V_603 )
V_231 -> V_631 = F_354 ( V_181 -> V_166 ) ;
else if ( V_599 -> V_631 > V_231 -> V_631 )
V_645 = 1 ;
V_646 =
( V_599 -> V_631 * V_86 ) /
V_599 -> V_622 ;
if ( V_599 -> V_495 + V_646 >=
V_231 -> V_495 + ( V_646 * V_645 ) ) {
V_181 -> V_493 = V_599 -> V_631 ;
return;
}
V_643 += V_599 -> V_622 *
F_155 ( V_599 -> V_631 , V_599 -> V_495 ) ;
V_643 += V_231 -> V_622 *
F_155 ( V_231 -> V_631 , V_231 -> V_495 ) ;
V_643 /= V_86 ;
if ( V_599 -> V_495 > V_646 ) {
V_644 += V_599 -> V_622 *
F_155 ( V_599 -> V_631 ,
V_599 -> V_495 - V_646 ) ;
}
if ( V_599 -> V_495 * V_599 -> V_622 <
V_599 -> V_631 * V_86 ) {
V_534 = ( V_599 -> V_495 * V_599 -> V_622 ) /
V_231 -> V_622 ;
} else {
V_534 = ( V_599 -> V_631 * V_86 ) /
V_231 -> V_622 ;
}
V_644 += V_231 -> V_622 *
F_155 ( V_231 -> V_631 , V_231 -> V_495 + V_534 ) ;
V_644 /= V_86 ;
if ( V_644 > V_643 )
V_181 -> V_493 = V_599 -> V_631 ;
}
static inline void F_451 ( struct V_562 * V_181 , struct V_598 * V_512 )
{
unsigned long V_647 , V_648 = ~ 0UL ;
struct V_620 * V_231 , * V_599 ;
V_231 = & V_512 -> V_640 ;
V_599 = & V_512 -> V_602 ;
if ( V_599 -> V_604 == V_626 ) {
V_599 -> V_631 =
F_155 ( V_599 -> V_631 , V_512 -> V_495 ) ;
}
if ( V_599 -> V_495 <= V_512 -> V_495 ||
V_231 -> V_495 >= V_512 -> V_495 ) {
V_181 -> V_493 = 0 ;
return F_450 ( V_181 , V_512 ) ;
}
if ( V_599 -> V_604 == V_625 &&
V_231 -> V_604 == V_625 ) {
V_648 = V_599 -> V_603 * V_86 ;
if ( V_648 > V_599 -> V_622 ) {
V_648 -= V_599 -> V_622 ;
V_648 *= F_12 ( V_72 ) ;
V_648 /= V_599 -> V_622 ;
} else
V_648 = ~ 0UL ;
}
V_647 = F_155 ( V_599 -> V_495 - V_512 -> V_495 , V_648 ) ;
V_181 -> V_493 = F_155 (
V_647 * V_599 -> V_622 ,
( V_512 -> V_495 - V_231 -> V_495 ) * V_231 -> V_622
) / V_86 ;
if ( V_181 -> V_493 < V_599 -> V_631 )
return F_450 ( V_181 , V_512 ) ;
}
static struct V_485 * F_452 ( struct V_562 * V_181 )
{
struct V_620 * V_231 , * V_599 ;
struct V_598 V_512 ;
F_429 ( & V_512 ) ;
F_447 ( V_181 , & V_512 ) ;
V_231 = & V_512 . V_640 ;
V_599 = & V_512 . V_602 ;
if ( F_449 ( V_181 , & V_512 ) )
return V_512 . V_599 ;
if ( ! V_512 . V_599 || V_599 -> V_603 == 0 )
goto V_649;
V_512 . V_495 = ( V_86 * V_512 . V_600 )
/ V_512 . V_601 ;
if ( V_599 -> V_604 == V_626 )
goto V_650;
if ( V_181 -> V_398 == V_593 && F_438 ( V_181 , V_231 ) &&
V_599 -> V_624 )
goto V_650;
if ( V_231 -> V_495 >= V_599 -> V_495 )
goto V_649;
if ( V_231 -> V_495 >= V_512 . V_495 )
goto V_649;
if ( V_181 -> V_398 == V_651 ) {
if ( ( V_599 -> V_604 != V_625 ) &&
( V_231 -> V_630 <= ( V_599 -> V_630 + 1 ) ) )
goto V_649;
} else {
if ( 100 * V_599 -> V_495 <=
V_181 -> V_211 -> V_196 * V_231 -> V_495 )
goto V_649;
}
V_650:
F_451 ( V_181 , & V_512 ) ;
return V_512 . V_599 ;
V_649:
V_181 -> V_493 = 0 ;
return NULL ;
}
static struct V_24 * F_453 ( struct V_562 * V_181 ,
struct V_485 * V_146 )
{
struct V_24 * V_599 = NULL , * V_24 ;
unsigned long V_652 = 0 , V_653 = 1 ;
int V_270 ;
F_365 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_176 , V_466 ;
enum V_634 V_654 ;
V_24 = F_124 ( V_270 ) ;
V_654 = F_446 ( V_24 ) ;
if ( V_654 > V_181 -> V_634 )
continue;
V_176 = F_126 ( V_270 ) ;
V_466 = F_125 ( V_270 ) ;
if ( V_24 -> V_73 == 1 && V_466 > V_181 -> V_493 &&
! F_436 ( V_24 , V_181 -> V_211 ) )
continue;
if ( V_466 * V_653 > V_652 * V_176 ) {
V_652 = V_466 ;
V_653 = V_176 ;
V_599 = V_24 ;
}
}
return V_599 ;
}
static int F_454 ( struct V_562 * V_181 )
{
struct V_210 * V_211 = V_181 -> V_211 ;
if ( V_181 -> V_398 == V_593 ) {
if ( ( V_211 -> V_113 & V_633 ) && V_181 -> V_200 > V_181 -> V_166 )
return 1 ;
}
if ( ( V_181 -> V_398 != V_586 ) &&
( V_181 -> V_199 -> V_40 . V_409 == 1 ) ) {
if ( ( F_436 ( V_181 -> V_199 , V_211 ) ) &&
( F_126 ( V_181 -> V_200 ) * V_211 -> V_196 < F_126 ( V_181 -> V_166 ) * 100 ) )
return 1 ;
}
return F_13 ( V_211 -> V_576 > V_211 -> V_577 + 2 ) ;
}
static int F_455 ( struct V_562 * V_181 )
{
struct V_485 * V_632 = V_181 -> V_211 -> V_488 ;
struct V_506 * V_655 , * V_656 ;
int V_175 , V_657 = - 1 ;
if ( V_181 -> V_398 == V_593 )
return 1 ;
V_655 = F_362 ( V_632 ) ;
V_656 = F_456 ( V_632 ) ;
F_365 (cpu, sg_cpus, env->cpus) {
if ( ! F_137 ( V_175 , V_656 ) || ! F_366 ( V_175 ) )
continue;
V_657 = V_175 ;
break;
}
if ( V_657 == - 1 )
V_657 = F_457 ( V_632 ) ;
return V_657 == V_181 -> V_166 ;
}
static int F_458 ( int V_479 , struct V_24 * F_233 ,
struct V_210 * V_211 , enum V_606 V_398 ,
int * V_658 )
{
int V_659 , V_660 , V_661 = 0 ;
struct V_210 * V_662 = V_211 -> V_34 ;
struct V_485 * V_146 ;
struct V_24 * V_599 ;
unsigned long V_113 ;
struct V_506 * V_8 = F_375 ( V_663 ) ;
struct V_562 V_181 = {
. V_211 = V_211 ,
. V_166 = V_479 ,
. V_201 = F_233 ,
. V_571 = F_362 ( V_211 -> V_488 ) ,
. V_398 = V_398 ,
. V_589 = V_590 ,
. V_8 = V_8 ,
. V_634 = V_636 ,
. V_584 = F_459 ( V_181 . V_584 ) ,
} ;
if ( V_398 == V_593 )
V_181 . V_571 = NULL ;
F_460 ( V_8 , V_664 ) ;
F_83 ( V_211 -> V_665 [ V_398 ] ) ;
V_666:
if ( ! F_455 ( & V_181 ) ) {
* V_658 = 0 ;
goto V_649;
}
V_146 = F_452 ( & V_181 ) ;
if ( ! V_146 ) {
F_83 ( V_211 -> V_667 [ V_398 ] ) ;
goto V_649;
}
V_599 = F_453 ( & V_181 , V_146 ) ;
if ( ! V_599 ) {
F_83 ( V_211 -> V_668 [ V_398 ] ) ;
goto V_649;
}
F_182 ( V_599 == V_181 . V_201 ) ;
F_70 ( V_211 -> V_669 [ V_398 ] , V_181 . V_493 ) ;
V_181 . V_200 = V_599 -> V_175 ;
V_181 . V_199 = V_599 ;
V_659 = 0 ;
if ( V_599 -> V_73 > 1 ) {
V_181 . V_113 |= V_574 ;
V_181 . V_588 = F_155 ( V_670 , V_599 -> V_73 ) ;
V_671:
F_425 ( & V_599 -> V_255 , V_113 ) ;
V_660 = F_415 ( & V_181 ) ;
F_291 ( & V_599 -> V_255 ) ;
if ( V_660 ) {
F_423 ( & V_181 ) ;
V_659 += V_660 ;
}
F_461 ( V_113 ) ;
if ( V_181 . V_113 & V_591 ) {
V_181 . V_113 &= ~ V_591 ;
goto V_671;
}
if ( ( V_181 . V_113 & V_572 ) && V_181 . V_493 > 0 ) {
F_379 ( V_181 . V_166 , V_181 . V_8 ) ;
V_181 . V_201 = F_124 ( V_181 . V_573 ) ;
V_181 . V_166 = V_181 . V_573 ;
V_181 . V_113 &= ~ V_572 ;
V_181 . V_587 = 0 ;
V_181 . V_589 = V_590 ;
goto V_671;
}
if ( V_662 ) {
int * V_672 = & V_662 -> V_488 -> V_497 -> V_493 ;
if ( ( V_181 . V_113 & V_570 ) && V_181 . V_493 > 0 )
* V_672 = 1 ;
}
if ( F_13 ( V_181 . V_113 & V_574 ) ) {
F_379 ( F_25 ( V_599 ) , V_8 ) ;
if ( ! F_462 ( V_8 ) ) {
V_181 . V_587 = 0 ;
V_181 . V_589 = V_590 ;
goto V_666;
}
goto V_673;
}
}
if ( ! V_659 ) {
F_83 ( V_211 -> V_674 [ V_398 ] ) ;
if ( V_398 != V_593 )
V_211 -> V_576 ++ ;
if ( F_454 ( & V_181 ) ) {
F_425 ( & V_599 -> V_255 , V_113 ) ;
if ( ! F_137 ( V_479 ,
F_138 ( V_599 -> V_45 ) ) ) {
F_426 ( & V_599 -> V_255 ,
V_113 ) ;
V_181 . V_113 |= V_574 ;
goto V_675;
}
if ( ! V_599 -> V_661 ) {
V_599 -> V_661 = 1 ;
V_599 -> V_676 = V_479 ;
V_661 = 1 ;
}
F_426 ( & V_599 -> V_255 , V_113 ) ;
if ( V_661 ) {
F_463 ( F_25 ( V_599 ) ,
V_677 , V_599 ,
& V_599 -> V_678 ) ;
}
V_211 -> V_576 = V_211 -> V_577 + 1 ;
}
} else
V_211 -> V_576 = 0 ;
if ( F_11 ( ! V_661 ) ) {
V_211 -> V_615 = V_211 -> V_679 ;
} else {
if ( V_211 -> V_615 < V_211 -> V_680 )
V_211 -> V_615 *= 2 ;
}
goto V_319;
V_649:
if ( V_662 ) {
int * V_672 = & V_662 -> V_488 -> V_497 -> V_493 ;
if ( * V_672 )
* V_672 = 0 ;
}
V_673:
F_83 ( V_211 -> V_681 [ V_398 ] ) ;
V_211 -> V_576 = 0 ;
V_675:
if ( ( ( V_181 . V_113 & V_574 ) &&
V_211 -> V_615 < V_682 ) ||
( V_211 -> V_615 < V_211 -> V_680 ) )
V_211 -> V_615 *= 2 ;
V_659 = 0 ;
V_319:
return V_659 ;
}
static inline unsigned long
F_464 ( struct V_210 * V_211 , int V_683 )
{
unsigned long V_219 = V_211 -> V_615 ;
if ( V_683 )
V_219 *= V_211 -> V_684 ;
V_219 = F_156 ( V_219 ) ;
V_219 = F_159 ( V_219 , 1UL , V_616 ) ;
return V_219 ;
}
static inline void
F_465 ( struct V_210 * V_211 , unsigned long * V_685 )
{
unsigned long V_219 , V_59 ;
V_219 = F_464 ( V_211 , 0 ) ;
V_59 = V_211 -> V_686 + V_219 ;
if ( F_193 ( * V_685 , V_59 ) )
* V_685 = V_59 ;
}
static int F_245 ( struct V_24 * F_233 )
{
unsigned long V_685 = V_222 + V_220 ;
int V_479 = F_233 -> V_175 ;
struct V_210 * V_211 ;
int V_687 = 0 ;
T_2 V_688 = 0 ;
F_233 -> V_505 = F_78 ( F_233 ) ;
if ( F_233 -> V_523 < V_564 ||
! F_233 -> V_530 -> V_627 ) {
F_134 () ;
V_211 = F_466 ( F_233 -> V_211 ) ;
if ( V_211 )
F_465 ( V_211 , & V_685 ) ;
F_143 () ;
goto V_319;
}
F_291 ( & F_233 -> V_255 ) ;
F_424 ( V_479 ) ;
F_134 () ;
F_389 (this_cpu, sd) {
int V_658 = 1 ;
T_2 V_689 , V_690 ;
if ( ! ( V_211 -> V_113 & V_539 ) )
continue;
if ( F_233 -> V_523 < V_688 + V_211 -> V_691 ) {
F_465 ( V_211 , & V_685 ) ;
break;
}
if ( V_211 -> V_113 & V_692 ) {
V_689 = F_284 ( V_479 ) ;
V_687 = F_458 ( V_479 , F_233 ,
V_211 , V_593 ,
& V_658 ) ;
V_690 = F_284 ( V_479 ) - V_689 ;
if ( V_690 > V_211 -> V_691 )
V_211 -> V_691 = V_690 ;
V_688 += V_690 ;
}
F_465 ( V_211 , & V_685 ) ;
if ( V_687 || F_233 -> V_73 > 0 )
break;
}
F_143 () ;
F_289 ( & F_233 -> V_255 ) ;
if ( V_688 > F_233 -> V_693 )
F_233 -> V_693 = V_688 ;
if ( F_233 -> V_40 . V_409 && ! V_687 )
V_687 = 1 ;
V_319:
if ( F_193 ( F_233 -> V_685 , V_685 ) )
F_233 -> V_685 = V_685 ;
if ( F_233 -> V_73 != F_233 -> V_40 . V_409 )
V_687 = - 1 ;
if ( V_687 )
F_233 -> V_505 = 0 ;
return V_687 ;
}
static int V_677 ( void * V_404 )
{
struct V_24 * V_694 = V_404 ;
int V_642 = F_25 ( V_694 ) ;
int V_695 = V_694 -> V_676 ;
struct V_24 * V_696 = F_124 ( V_695 ) ;
struct V_210 * V_211 ;
struct V_26 * V_29 = NULL ;
F_467 ( & V_694 -> V_255 ) ;
if ( F_13 ( V_642 != F_285 () ||
! V_694 -> V_661 ) )
goto V_697;
if ( V_694 -> V_73 <= 1 )
goto V_697;
F_182 ( V_694 == V_696 ) ;
F_134 () ;
F_389 (target_cpu, sd) {
if ( ( V_211 -> V_113 & V_539 ) &&
F_137 ( V_642 , F_377 ( V_211 ) ) )
break;
}
if ( F_11 ( V_211 ) ) {
struct V_562 V_181 = {
. V_211 = V_211 ,
. V_166 = V_695 ,
. V_201 = V_696 ,
. V_200 = V_694 -> V_175 ,
. V_199 = V_694 ,
. V_398 = V_651 ,
} ;
F_83 ( V_211 -> V_698 ) ;
V_29 = F_413 ( & V_181 ) ;
if ( V_29 ) {
F_83 ( V_211 -> V_699 ) ;
V_211 -> V_576 = 0 ;
} else {
F_83 ( V_211 -> V_700 ) ;
}
}
F_143 () ;
V_697:
V_694 -> V_661 = 0 ;
F_291 ( & V_694 -> V_255 ) ;
if ( V_29 )
F_422 ( V_696 , V_29 ) ;
F_142 () ;
return 0 ;
}
static inline int F_468 ( struct V_24 * V_24 )
{
return F_13 ( ! F_469 ( V_24 -> V_211 ) ) ;
}
static inline int F_470 ( void )
{
int V_701 = F_364 ( V_702 . V_703 ) ;
if ( V_701 < V_704 && F_366 ( V_701 ) )
return V_701 ;
return V_704 ;
}
static void F_471 ( void )
{
int V_705 ;
V_702 . V_685 ++ ;
V_705 = F_470 () ;
if ( V_705 >= V_704 )
return;
if ( F_472 ( V_706 , F_473 ( V_705 ) ) )
return;
F_474 ( V_705 ) ;
return;
}
void F_475 ( unsigned int V_175 )
{
if ( F_13 ( F_476 ( V_707 , F_473 ( V_175 ) ) ) ) {
if ( F_11 ( F_137 ( V_175 , V_702 . V_703 ) ) ) {
F_379 ( V_175 , V_702 . V_703 ) ;
F_477 ( & V_702 . V_708 ) ;
}
F_478 ( V_707 , F_473 ( V_175 ) ) ;
}
}
static inline void F_479 ( void )
{
struct V_210 * V_211 ;
int V_175 = F_285 () ;
F_134 () ;
V_211 = F_148 ( F_149 ( V_525 , V_175 ) ) ;
if ( ! V_211 || ! V_211 -> V_709 )
goto V_205;
V_211 -> V_709 = 0 ;
F_480 ( & V_211 -> V_224 -> V_710 ) ;
V_205:
F_143 () ;
}
void F_481 ( void )
{
struct V_210 * V_211 ;
int V_175 = F_285 () ;
F_134 () ;
V_211 = F_148 ( F_149 ( V_525 , V_175 ) ) ;
if ( ! V_211 || V_211 -> V_709 )
goto V_205;
V_211 -> V_709 = 1 ;
F_477 ( & V_211 -> V_224 -> V_710 ) ;
V_205:
F_143 () ;
}
void F_482 ( int V_175 )
{
if ( ! F_483 ( V_175 ) )
return;
if ( F_476 ( V_707 , F_473 ( V_175 ) ) )
return;
if ( F_468 ( F_124 ( V_175 ) ) )
return;
F_484 ( V_175 , V_702 . V_703 ) ;
F_480 ( & V_702 . V_708 ) ;
F_485 ( V_707 , F_473 ( V_175 ) ) ;
}
void F_486 ( void )
{
V_616 = V_220 * F_487 () / 10 ;
}
static void F_488 ( struct V_24 * V_24 , enum V_606 V_398 )
{
int V_658 = 1 ;
int V_175 = V_24 -> V_175 ;
unsigned long V_219 ;
struct V_210 * V_211 ;
unsigned long V_685 = V_222 + 60 * V_220 ;
int F_465 = 0 ;
int V_711 , V_712 = 0 ;
T_2 V_713 = 0 ;
F_424 ( V_175 ) ;
F_134 () ;
F_389 (cpu, sd) {
if ( F_193 ( V_222 , V_211 -> V_714 ) ) {
V_211 -> V_691 =
( V_211 -> V_691 * 253 ) / 256 ;
V_211 -> V_714 = V_222 + V_220 ;
V_712 = 1 ;
}
V_713 += V_211 -> V_691 ;
if ( ! ( V_211 -> V_113 & V_539 ) )
continue;
if ( ! V_658 ) {
if ( V_712 )
continue;
break;
}
V_219 = F_464 ( V_211 , V_398 != V_651 ) ;
V_711 = V_211 -> V_113 & V_715 ;
if ( V_711 ) {
if ( ! F_489 ( & V_716 ) )
goto V_319;
}
if ( F_448 ( V_222 , V_211 -> V_686 + V_219 ) ) {
if ( F_458 ( V_175 , V_24 , V_211 , V_398 , & V_658 ) ) {
V_398 = F_366 ( V_175 ) ? V_651 : V_586 ;
}
V_211 -> V_686 = V_222 ;
V_219 = F_464 ( V_211 , V_398 != V_651 ) ;
}
if ( V_711 )
F_185 ( & V_716 ) ;
V_319:
if ( F_193 ( V_685 , V_211 -> V_686 + V_219 ) ) {
V_685 = V_211 -> V_686 + V_219 ;
F_465 = 1 ;
}
}
if ( V_712 ) {
V_24 -> V_693 =
F_69 ( ( T_2 ) V_564 , V_713 ) ;
}
F_143 () ;
if ( F_11 ( F_465 ) ) {
V_24 -> V_685 = V_685 ;
#ifdef F_342
if ( ( V_398 == V_651 ) && F_193 ( V_702 . V_685 , V_24 -> V_685 ) )
V_702 . V_685 = V_24 -> V_685 ;
#endif
}
}
static void F_490 ( struct V_24 * F_233 , enum V_606 V_398 )
{
int V_479 = F_233 -> V_175 ;
struct V_24 * V_24 ;
int V_657 ;
unsigned long V_685 = V_222 + 60 * V_220 ;
int F_465 = 0 ;
if ( V_398 != V_651 ||
! F_476 ( V_706 , F_473 ( V_479 ) ) )
goto V_299;
F_123 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_657 == V_479 || ! F_366 ( V_657 ) )
continue;
if ( F_491 () )
break;
V_24 = F_124 ( V_657 ) ;
if ( F_448 ( V_222 , V_24 -> V_685 ) ) {
F_467 ( & V_24 -> V_255 ) ;
F_303 ( V_24 ) ;
F_345 ( V_24 ) ;
F_492 ( & V_24 -> V_255 ) ;
F_488 ( V_24 , V_651 ) ;
}
if ( F_193 ( V_685 , V_24 -> V_685 ) ) {
V_685 = V_24 -> V_685 ;
F_465 = 1 ;
}
}
if ( F_11 ( F_465 ) )
V_702 . V_685 = V_685 ;
V_299:
F_478 ( V_706 , F_473 ( V_479 ) ) ;
}
static inline bool F_493 ( struct V_24 * V_24 )
{
unsigned long V_87 = V_222 ;
struct V_511 * V_512 ;
struct V_210 * V_211 ;
int V_717 , V_175 = V_24 -> V_175 ;
bool V_718 = false ;
if ( F_13 ( V_24 -> F_245 ) )
return false ;
F_479 () ;
F_475 ( V_175 ) ;
if ( F_11 ( ! F_494 ( & V_702 . V_708 ) ) )
return false ;
if ( F_197 ( V_87 , V_702 . V_685 ) )
return false ;
if ( V_24 -> V_73 >= 2 )
return true ;
F_134 () ;
V_512 = F_148 ( F_149 ( V_513 , V_175 ) ) ;
if ( V_512 ) {
V_717 = F_494 ( & V_512 -> V_710 ) ;
if ( V_717 > 1 ) {
V_718 = true ;
goto V_205;
}
}
V_211 = F_148 ( V_24 -> V_211 ) ;
if ( V_211 ) {
if ( ( V_24 -> V_40 . V_409 >= 1 ) &&
F_436 ( V_24 , V_211 ) ) {
V_718 = true ;
goto V_205;
}
}
V_211 = F_148 ( F_149 ( V_719 , V_175 ) ) ;
if ( V_211 && ( F_495 ( V_702 . V_703 ,
F_377 ( V_211 ) ) < V_175 ) ) {
V_718 = true ;
goto V_205;
}
V_205:
F_143 () ;
return V_718 ;
}
static void F_490 ( struct V_24 * F_233 , enum V_606 V_398 ) { }
static T_12 void F_496 ( struct V_720 * V_721 )
{
struct V_24 * F_233 = F_233 () ;
enum V_606 V_398 = F_233 -> F_245 ?
V_651 : V_586 ;
F_490 ( F_233 , V_398 ) ;
F_488 ( F_233 , V_398 ) ;
}
void F_497 ( struct V_24 * V_24 )
{
if ( F_13 ( F_468 ( V_24 ) ) )
return;
if ( F_448 ( V_222 , V_24 -> V_685 ) )
F_498 ( V_722 ) ;
#ifdef F_342
if ( F_493 ( V_24 ) )
F_471 () ;
#endif
}
static void F_499 ( struct V_24 * V_24 )
{
F_7 () ;
F_329 ( V_24 ) ;
}
static void F_500 ( struct V_24 * V_24 )
{
F_7 () ;
F_331 ( V_24 ) ;
}
static void F_501 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_380 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_58 (se) {
V_25 = F_22 ( V_28 ) ;
F_272 ( V_25 , V_28 , V_380 ) ;
}
if ( F_502 ( & V_284 ) )
F_208 ( V_24 , V_45 ) ;
}
static void F_503 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
struct V_24 * V_24 = F_233 () ;
F_289 ( & V_24 -> V_255 ) ;
F_303 ( V_24 ) ;
V_25 = F_21 ( V_170 ) ;
V_45 = V_25 -> V_45 ;
if ( V_45 ) {
F_66 ( V_25 ) ;
V_28 -> V_41 = V_45 -> V_41 ;
}
F_248 ( V_25 , V_28 , 1 ) ;
if ( V_723 && V_45 && F_36 ( V_45 , V_28 ) ) {
F_132 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_266 ( V_24 ) ;
}
V_28 -> V_41 -= V_25 -> F_35 ;
F_291 ( & V_24 -> V_255 ) ;
}
static void
F_504 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_724 )
{
if ( ! F_505 ( V_29 ) )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_725 > V_724 )
F_266 ( V_24 ) ;
} else
F_421 ( V_24 , V_29 , 0 ) ;
}
static inline bool F_506 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( V_29 -> V_46 )
return true ;
if ( ! V_28 -> V_94 || V_29 -> V_116 == V_543 )
return true ;
return false ;
}
static void F_507 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_28 ) ;
T_2 V_87 = F_62 ( V_25 ) ;
if ( ! F_506 ( V_29 ) ) {
F_248 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_35 ;
}
F_63 ( V_87 , V_25 , false ) ;
F_238 ( V_25 , V_28 ) ;
F_65 ( V_25 , false ) ;
}
static void F_508 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_22 ( V_28 ) ;
T_2 V_87 = F_62 ( V_25 ) ;
#ifdef F_398
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
#endif
F_63 ( V_87 , V_25 , false ) ;
F_64 ( V_25 , V_28 ) ;
F_65 ( V_25 , false ) ;
if ( ! F_506 ( V_29 ) )
V_28 -> V_41 += V_25 -> F_35 ;
}
static void F_509 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_507 ( V_29 ) ;
}
static void F_510 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
F_508 ( V_29 ) ;
if ( F_505 ( V_29 ) ) {
if ( V_24 -> V_45 == V_29 )
F_266 ( V_24 ) ;
else
F_421 ( V_24 , V_29 , 0 ) ;
}
}
static void F_511 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_58 (se) {
struct V_25 * V_25 = F_22 ( V_28 ) ;
F_267 ( V_25 , V_28 ) ;
F_74 ( V_25 , 0 ) ;
}
}
void F_512 ( struct V_25 * V_25 )
{
V_25 -> V_52 = V_726 ;
V_25 -> F_35 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_39
V_25 -> V_49 = V_25 -> F_35 ;
#endif
#ifdef F_212
F_513 ( & V_25 -> V_358 , 0 ) ;
F_513 ( & V_25 -> V_360 , 0 ) ;
#endif
}
static void F_514 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
F_515 ( V_29 , F_147 ( V_29 ) ) ;
V_28 -> V_39 = V_28 -> V_34 ? V_28 -> V_34 -> V_39 + 1 : 0 ;
}
static void F_516 ( struct V_26 * V_29 )
{
F_507 ( V_29 ) ;
F_515 ( V_29 , F_147 ( V_29 ) ) ;
#ifdef F_212
V_29 -> V_28 . V_77 . V_78 = 0 ;
#endif
F_508 ( V_29 ) ;
}
static void F_517 ( struct V_26 * V_29 , int type )
{
switch ( type ) {
case V_727 :
F_514 ( V_29 ) ;
break;
case V_728 :
F_516 ( V_29 ) ;
break;
}
}
void F_518 ( struct V_323 * V_33 )
{
int V_270 ;
F_327 ( F_287 ( V_33 ) ) ;
F_519 (i) {
if ( V_33 -> V_25 )
F_190 ( V_33 -> V_25 [ V_270 ] ) ;
if ( V_33 -> V_28 )
F_190 ( V_33 -> V_28 [ V_270 ] ) ;
}
F_190 ( V_33 -> V_25 ) ;
F_190 ( V_33 -> V_28 ) ;
}
int F_520 ( struct V_323 * V_33 , struct V_323 * V_34 )
{
struct V_27 * V_28 ;
struct V_25 * V_25 ;
int V_270 ;
V_33 -> V_25 = F_178 ( sizeof( V_25 ) * V_704 , V_272 ) ;
if ( ! V_33 -> V_25 )
goto V_729;
V_33 -> V_28 = F_178 ( sizeof( V_28 ) * V_704 , V_272 ) ;
if ( ! V_33 -> V_28 )
goto V_729;
V_33 -> V_325 = V_72 ;
F_320 ( F_287 ( V_33 ) ) ;
F_519 (i) {
V_25 = F_521 ( sizeof( struct V_25 ) ,
V_272 , F_116 ( V_270 ) ) ;
if ( ! V_25 )
goto V_729;
V_28 = F_521 ( sizeof( struct V_27 ) ,
V_272 , F_116 ( V_270 ) ) ;
if ( ! V_28 )
goto V_730;
F_512 ( V_25 ) ;
F_522 ( V_33 , V_25 , V_28 , V_270 , V_34 -> V_28 [ V_270 ] ) ;
F_60 ( V_28 ) ;
}
return 1 ;
V_730:
F_190 ( V_25 ) ;
V_729:
return 0 ;
}
void F_523 ( struct V_323 * V_33 )
{
struct V_27 * V_28 ;
struct V_24 * V_24 ;
int V_270 ;
F_519 (i) {
V_24 = F_124 ( V_270 ) ;
V_28 = V_33 -> V_28 [ V_270 ] ;
F_467 ( & V_24 -> V_255 ) ;
F_61 ( V_28 ) ;
F_316 ( V_33 , V_270 ) ;
F_492 ( & V_24 -> V_255 ) ;
}
}
void F_524 ( struct V_323 * V_33 )
{
unsigned long V_113 ;
struct V_24 * V_24 ;
int V_175 ;
F_519 (cpu) {
if ( V_33 -> V_28 [ V_175 ] )
F_242 ( V_33 -> V_28 [ V_175 ] ) ;
if ( ! V_33 -> V_25 [ V_175 ] -> V_32 )
continue;
V_24 = F_124 ( V_175 ) ;
F_425 ( & V_24 -> V_255 , V_113 ) ;
F_28 ( V_33 -> V_25 [ V_175 ] ) ;
F_426 ( & V_24 -> V_255 , V_113 ) ;
}
}
void F_522 ( struct V_323 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_175 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_124 ( V_175 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_324 ( V_25 ) ;
V_33 -> V_25 [ V_175 ] = V_25 ;
V_33 -> V_28 [ V_175 ] = V_28 ;
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
F_3 ( & V_28 -> V_71 , V_72 ) ;
V_28 -> V_34 = V_34 ;
}
int F_525 ( struct V_323 * V_33 , unsigned long V_325 )
{
int V_270 ;
unsigned long V_113 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_215 ;
V_325 = F_159 ( V_325 , F_526 ( V_327 ) , F_526 ( V_731 ) ) ;
F_527 ( & V_732 ) ;
if ( V_33 -> V_325 == V_325 )
goto V_733;
V_33 -> V_325 = V_325 ;
F_519 (i) {
struct V_24 * V_24 = F_124 ( V_270 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_270 ] ;
F_425 ( & V_24 -> V_255 , V_113 ) ;
F_303 ( V_24 ) ;
F_58 (se)
F_219 ( F_23 ( V_28 ) ) ;
F_426 ( & V_24 -> V_255 , V_113 ) ;
}
V_733:
F_528 ( & V_732 ) ;
return 0 ;
}
void F_518 ( struct V_323 * V_33 ) { }
int F_520 ( struct V_323 * V_33 , struct V_323 * V_34 )
{
return 1 ;
}
void F_523 ( struct V_323 * V_33 ) { }
void F_524 ( struct V_323 * V_33 ) { }
static unsigned int F_529 ( struct V_24 * V_24 , struct V_26 * V_152 )
{
struct V_27 * V_28 = & V_152 -> V_28 ;
unsigned int V_734 = 0 ;
if ( V_24 -> V_40 . V_71 . V_4 )
V_734 = F_530 ( F_57 ( F_22 ( V_28 ) , V_28 ) ) ;
return V_734 ;
}
void F_531 ( struct V_735 * V_736 , int V_175 )
{
struct V_25 * V_25 ;
F_134 () ;
F_330 (cpu_rq(cpu), cfs_rq)
F_532 ( V_736 , V_175 , V_25 ) ;
F_143 () ;
}
void F_533 ( struct V_26 * V_29 , struct V_735 * V_736 )
{
int V_154 ;
unsigned long V_737 = 0 , V_738 = 0 , V_739 = 0 , V_740 = 0 ;
F_111 (node) {
if ( V_29 -> V_143 ) {
V_737 = V_29 -> V_143 [ F_105 ( V_144 , V_154 , 0 ) ] ;
V_738 = V_29 -> V_143 [ F_105 ( V_144 , V_154 , 1 ) ] ;
}
if ( V_29 -> V_135 ) {
V_739 = V_29 -> V_135 -> V_145 [ F_105 ( V_144 , V_154 , 0 ) ] ,
V_740 = V_29 -> V_135 -> V_145 [ F_105 ( V_144 , V_154 , 1 ) ] ;
}
F_534 ( V_736 , V_154 , V_737 , V_738 , V_739 , V_740 ) ;
}
}
T_13 void F_535 ( void )
{
#ifdef F_212
F_536 ( V_722 , F_496 ) ;
#ifdef F_342
V_702 . V_685 = V_222 ;
F_537 ( & V_702 . V_703 , V_741 ) ;
#endif
#endif
}
