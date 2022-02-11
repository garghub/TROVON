int __weak F_1 ( int V_1 )
{
return - V_1 ;
}
static inline void F_2 ( struct V_2 * V_3 , unsigned long V_4 )
{
V_3 -> V_5 += V_4 ;
V_3 -> V_6 = 0 ;
}
static inline void F_3 ( struct V_2 * V_3 , unsigned long V_7 )
{
V_3 -> V_5 -= V_7 ;
V_3 -> V_6 = 0 ;
}
static inline void F_4 ( struct V_2 * V_3 , unsigned long V_8 )
{
V_3 -> V_5 = V_8 ;
V_3 -> V_6 = 0 ;
}
static unsigned int F_5 ( void )
{
unsigned int V_9 = F_6 (unsigned int, num_online_cpus(), 8 ) ;
unsigned int V_10 ;
switch ( V_11 ) {
case V_12 :
V_10 = 1 ;
break;
case V_13 :
V_10 = V_9 ;
break;
case V_14 :
default:
V_10 = 1 + F_7 ( V_9 ) ;
break;
}
return V_10 ;
}
static void F_8 ( void )
{
unsigned int V_10 = F_5 () ;
#define F_9 ( T_1 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_9 ( V_15 ) ;
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
#undef F_9
}
void F_10 ( void )
{
F_8 () ;
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned long V_8 ;
if ( F_12 ( V_3 -> V_6 ) )
return;
V_8 = F_13 ( V_3 -> V_5 ) ;
if ( V_18 > 32 && F_14 ( V_8 >= V_19 ) )
V_3 -> V_6 = 1 ;
else if ( F_14 ( ! V_8 ) )
V_3 -> V_6 = V_19 ;
else
V_3 -> V_6 = V_19 / V_8 ;
}
static T_2 F_15 ( T_2 V_20 , unsigned long V_5 , struct V_2 * V_3 )
{
T_2 V_21 = F_13 ( V_5 ) ;
int V_22 = V_23 ;
F_11 ( V_3 ) ;
if ( F_14 ( V_21 >> 32 ) ) {
while ( V_21 >> 32 ) {
V_21 >>= 1 ;
V_22 -- ;
}
}
V_21 = ( T_2 ) ( V_24 ) V_21 * V_3 -> V_6 ;
while ( V_21 >> 32 ) {
V_21 >>= 1 ;
V_22 -- ;
}
return F_16 ( V_20 , V_21 , V_22 ) ;
}
static inline struct V_25 * F_17 ( struct V_26 * V_26 )
{
return V_26 -> V_25 ;
}
static inline struct V_27 * F_18 ( struct V_28 * V_29 )
{
F_19 ( ! F_20 ( V_29 ) ) ;
return F_21 ( V_29 , struct V_27 , V_29 ) ;
}
static inline struct V_26 * F_22 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_26 ;
}
static inline struct V_26 * F_23 ( struct V_28 * V_29 )
{
return V_29 -> V_26 ;
}
static inline struct V_26 * F_24 ( struct V_28 * V_31 )
{
return V_31 -> V_32 ;
}
static inline void F_25 ( struct V_26 * V_26 )
{
if ( ! V_26 -> V_33 ) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
if ( V_26 -> V_34 -> V_35 &&
V_26 -> V_34 -> V_35 -> V_26 [ V_1 ] -> V_33 ) {
F_27 ( & V_26 -> V_36 ,
& ( V_26 -> V_34 -> V_35 -> V_26 [ V_1 ] -> V_36 ) ) ;
V_25 -> V_37 = & V_25 -> V_36 ;
} else if ( ! V_26 -> V_34 -> V_35 ) {
F_27 ( & V_26 -> V_36 ,
& V_25 -> V_36 ) ;
V_25 -> V_37 = & V_25 -> V_36 ;
} else {
F_28 ( & V_26 -> V_36 ,
V_25 -> V_37 ) ;
V_25 -> V_37 = & V_26 -> V_36 ;
}
V_26 -> V_33 = 1 ;
}
}
static inline void F_29 ( struct V_26 * V_26 )
{
if ( V_26 -> V_33 ) {
F_30 ( & V_26 -> V_36 ) ;
V_26 -> V_33 = 0 ;
}
}
static inline struct V_26 *
F_31 ( struct V_28 * V_29 , struct V_28 * V_38 )
{
if ( V_29 -> V_26 == V_38 -> V_26 )
return V_29 -> V_26 ;
return NULL ;
}
static inline struct V_28 * F_32 ( struct V_28 * V_29 )
{
return V_29 -> V_35 ;
}
static void
F_33 ( struct V_28 * * V_29 , struct V_28 * * V_38 )
{
int V_39 , V_40 ;
V_39 = ( * V_29 ) -> V_41 ;
V_40 = ( * V_38 ) -> V_41 ;
while ( V_39 > V_40 ) {
V_39 -- ;
* V_29 = F_32 ( * V_29 ) ;
}
while ( V_40 > V_39 ) {
V_40 -- ;
* V_38 = F_32 ( * V_38 ) ;
}
while ( ! F_31 ( * V_29 , * V_38 ) ) {
* V_29 = F_32 ( * V_29 ) ;
* V_38 = F_32 ( * V_38 ) ;
}
}
static inline struct V_27 * F_18 ( struct V_28 * V_29 )
{
return F_21 ( V_29 , struct V_27 , V_29 ) ;
}
static inline struct V_25 * F_17 ( struct V_26 * V_26 )
{
return F_21 ( V_26 , struct V_25 , V_42 ) ;
}
static inline struct V_26 * F_22 ( struct V_27 * V_30 )
{
return & F_34 ( V_30 ) -> V_42 ;
}
static inline struct V_26 * F_23 ( struct V_28 * V_29 )
{
struct V_27 * V_30 = F_18 ( V_29 ) ;
struct V_25 * V_25 = F_34 ( V_30 ) ;
return & V_25 -> V_42 ;
}
static inline struct V_26 * F_24 ( struct V_28 * V_31 )
{
return NULL ;
}
static inline void F_25 ( struct V_26 * V_26 )
{
}
static inline void F_29 ( struct V_26 * V_26 )
{
}
static inline struct V_28 * F_32 ( struct V_28 * V_29 )
{
return NULL ;
}
static inline void
F_33 ( struct V_28 * * V_29 , struct V_28 * * V_38 )
{
}
static inline T_2 F_35 ( T_2 F_35 , T_2 V_43 )
{
T_3 V_44 = ( T_3 ) ( V_43 - F_35 ) ;
if ( V_44 > 0 )
F_35 = V_43 ;
return F_35 ;
}
static inline T_2 F_36 ( T_2 F_36 , T_2 V_43 )
{
T_3 V_44 = ( T_3 ) ( V_43 - F_36 ) ;
if ( V_44 < 0 )
F_36 = V_43 ;
return F_36 ;
}
static inline int F_37 ( struct V_28 * V_45 ,
struct V_28 * V_46 )
{
return ( T_3 ) ( V_45 -> V_43 - V_46 -> V_43 ) < 0 ;
}
static void F_38 ( struct V_26 * V_26 )
{
struct V_28 * V_47 = V_26 -> V_47 ;
struct V_48 * V_49 = F_39 ( & V_26 -> V_50 ) ;
T_2 V_43 = V_26 -> F_36 ;
if ( V_47 ) {
if ( V_47 -> V_51 )
V_43 = V_47 -> V_43 ;
else
V_47 = NULL ;
}
if ( V_49 ) {
struct V_28 * V_29 ;
V_29 = F_40 ( V_49 , struct V_28 , V_52 ) ;
if ( ! V_47 )
V_43 = V_29 -> V_43 ;
else
V_43 = F_36 ( V_43 , V_29 -> V_43 ) ;
}
V_26 -> F_36 = F_35 ( V_26 -> F_36 , V_43 ) ;
#ifndef F_41
F_42 () ;
V_26 -> V_53 = V_26 -> F_36 ;
#endif
}
static void F_43 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_48 * * V_54 = & V_26 -> V_50 . V_55 . V_48 ;
struct V_48 * V_35 = NULL ;
struct V_28 * V_56 ;
bool V_49 = true ;
while ( * V_54 ) {
V_35 = * V_54 ;
V_56 = F_40 ( V_35 , struct V_28 , V_52 ) ;
if ( F_37 ( V_29 , V_56 ) ) {
V_54 = & V_35 -> V_57 ;
} else {
V_54 = & V_35 -> V_58 ;
V_49 = false ;
}
}
F_44 ( & V_29 -> V_52 , V_35 , V_54 ) ;
F_45 ( & V_29 -> V_52 ,
& V_26 -> V_50 , V_49 ) ;
}
static void F_46 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_47 ( & V_29 -> V_52 , & V_26 -> V_50 ) ;
}
struct V_28 * F_48 ( struct V_26 * V_26 )
{
struct V_48 * V_59 = F_39 ( & V_26 -> V_50 ) ;
if ( ! V_59 )
return NULL ;
return F_40 ( V_59 , struct V_28 , V_52 ) ;
}
static struct V_28 * F_49 ( struct V_28 * V_29 )
{
struct V_48 * V_60 = F_50 ( & V_29 -> V_52 ) ;
if ( ! V_60 )
return NULL ;
return F_40 ( V_60 , struct V_28 , V_52 ) ;
}
struct V_28 * F_51 ( struct V_26 * V_26 )
{
struct V_48 * V_61 = F_52 ( & V_26 -> V_50 . V_55 ) ;
if ( ! V_61 )
return NULL ;
return F_40 ( V_61 , struct V_28 , V_52 ) ;
}
int F_53 ( struct V_62 * V_63 , int V_64 ,
void T_4 * V_65 , T_5 * V_66 ,
T_6 * V_67 )
{
int V_68 = F_54 ( V_63 , V_64 , V_65 , V_66 , V_67 ) ;
unsigned int V_10 = F_5 () ;
if ( V_68 || ! V_64 )
return V_68 ;
V_69 = F_55 ( V_70 ,
V_71 ) ;
#define F_56 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_56 ( V_15 ) ;
F_56 ( V_16 ) ;
F_56 ( V_17 ) ;
#undef F_56
return 0 ;
}
static inline T_2 F_57 ( T_2 V_44 , struct V_28 * V_29 )
{
if ( F_14 ( V_29 -> V_72 . V_5 != V_73 ) )
V_44 = F_15 ( V_44 , V_73 , & V_29 -> V_72 ) ;
return V_44 ;
}
static T_2 F_58 ( unsigned long V_74 )
{
if ( F_14 ( V_74 > V_69 ) )
return V_74 * V_71 ;
else
return V_70 ;
}
static T_2 F_59 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
T_2 V_75 = F_58 ( V_26 -> V_74 + ! V_29 -> V_51 ) ;
F_60 (se) {
struct V_2 * V_72 ;
struct V_2 V_3 ;
V_26 = F_23 ( V_29 ) ;
V_72 = & V_26 -> V_72 ;
if ( F_14 ( ! V_29 -> V_51 ) ) {
V_3 = V_26 -> V_72 ;
F_2 ( & V_3 , V_29 -> V_72 . V_5 ) ;
V_72 = & V_3 ;
}
V_75 = F_15 ( V_75 , V_29 -> V_72 . V_5 , V_72 ) ;
}
return V_75 ;
}
static T_2 F_61 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
return F_57 ( F_59 ( V_26 , V_29 ) , V_29 ) ;
}
void F_62 ( struct V_28 * V_29 )
{
struct V_76 * V_77 = & V_29 -> V_78 ;
V_77 -> V_79 = 0 ;
V_77 -> V_80 = 1023 ;
if ( F_20 ( V_29 ) )
V_77 -> V_81 = F_13 ( V_29 -> V_72 . V_5 ) ;
V_77 -> V_82 = V_77 -> V_81 * V_83 ;
V_77 -> V_84 = 0 ;
V_77 -> V_85 = 0 ;
}
void F_63 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
struct V_76 * V_77 = & V_29 -> V_78 ;
long V_86 = ( long ) ( V_87 - V_26 -> V_78 . V_84 ) / 2 ;
if ( V_86 > 0 ) {
if ( V_26 -> V_78 . V_84 != 0 ) {
V_77 -> V_84 = V_26 -> V_78 . V_84 * V_29 -> V_72 . V_5 ;
V_77 -> V_84 /= ( V_26 -> V_78 . V_81 + 1 ) ;
if ( V_77 -> V_84 > V_86 )
V_77 -> V_84 = V_86 ;
} else {
V_77 -> V_84 = V_86 ;
}
V_77 -> V_85 = V_77 -> V_84 * V_83 ;
}
if ( F_20 ( V_29 ) ) {
struct V_27 * V_30 = F_18 ( V_29 ) ;
if ( V_30 -> V_88 != & V_89 ) {
V_29 -> V_78 . V_79 = F_64 ( V_26 ) ;
return;
}
}
F_65 ( V_29 ) ;
}
void F_62 ( struct V_28 * V_29 )
{
}
void F_63 ( struct V_28 * V_29 )
{
}
static void F_66 ( struct V_26 * V_26 , int V_90 )
{
}
static void F_67 ( struct V_26 * V_26 )
{
struct V_28 * V_47 = V_26 -> V_47 ;
T_2 V_91 = F_68 ( F_17 ( V_26 ) ) ;
T_2 V_20 ;
if ( F_14 ( ! V_47 ) )
return;
V_20 = V_91 - V_47 -> V_92 ;
if ( F_14 ( ( T_3 ) V_20 <= 0 ) )
return;
V_47 -> V_92 = V_91 ;
F_69 ( V_47 -> V_93 . V_94 ,
F_70 ( V_20 , V_47 -> V_93 . V_94 ) ) ;
V_47 -> V_95 += V_20 ;
F_71 ( V_26 -> V_96 , V_20 ) ;
V_47 -> V_43 += F_57 ( V_20 , V_47 ) ;
F_38 ( V_26 ) ;
if ( F_20 ( V_47 ) ) {
struct V_27 * V_97 = F_18 ( V_47 ) ;
F_72 ( V_97 , V_20 , V_47 -> V_43 ) ;
F_73 ( V_97 , V_20 ) ;
F_74 ( V_97 , V_20 ) ;
}
F_75 ( V_26 , V_20 ) ;
}
static void F_76 ( struct V_25 * V_25 )
{
F_67 ( F_23 ( & V_25 -> V_47 -> V_29 ) ) ;
}
static inline void
F_77 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
T_2 V_98 , V_99 ;
if ( ! F_78 () )
return;
V_98 = F_79 ( F_17 ( V_26 ) ) ;
V_99 = F_80 ( V_29 -> V_93 . V_98 ) ;
if ( F_20 ( V_29 ) && F_81 ( F_18 ( V_29 ) ) &&
F_12 ( V_98 > V_99 ) )
V_98 -= V_99 ;
F_69 ( V_29 -> V_93 . V_98 , V_98 ) ;
}
static inline void
F_82 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_27 * V_30 ;
T_2 V_44 ;
if ( ! F_78 () )
return;
V_44 = F_79 ( F_17 ( V_26 ) ) - F_80 ( V_29 -> V_93 . V_98 ) ;
if ( F_20 ( V_29 ) ) {
V_30 = F_18 ( V_29 ) ;
if ( F_81 ( V_30 ) ) {
F_69 ( V_29 -> V_93 . V_98 , V_44 ) ;
return;
}
F_83 ( V_30 , V_44 ) ;
}
F_69 ( V_29 -> V_93 . V_100 ,
F_70 ( F_80 ( V_29 -> V_93 . V_100 ) , V_44 ) ) ;
F_84 ( V_29 -> V_93 . V_101 ) ;
F_71 ( V_29 -> V_93 . V_102 , V_44 ) ;
F_69 ( V_29 -> V_93 . V_98 , 0 ) ;
}
static inline void
F_85 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_27 * V_103 = NULL ;
T_2 V_104 , V_105 ;
if ( ! F_78 () )
return;
V_104 = F_80 ( V_29 -> V_93 . V_104 ) ;
V_105 = F_80 ( V_29 -> V_93 . V_105 ) ;
if ( F_20 ( V_29 ) )
V_103 = F_18 ( V_29 ) ;
if ( V_104 ) {
T_2 V_44 = F_79 ( F_17 ( V_26 ) ) - V_104 ;
if ( ( T_3 ) V_44 < 0 )
V_44 = 0 ;
if ( F_14 ( V_44 > F_80 ( V_29 -> V_93 . V_106 ) ) )
F_69 ( V_29 -> V_93 . V_106 , V_44 ) ;
F_69 ( V_29 -> V_93 . V_104 , 0 ) ;
F_71 ( V_29 -> V_93 . V_107 , V_44 ) ;
if ( V_103 ) {
F_86 ( V_103 , V_44 >> 10 , 1 ) ;
F_87 ( V_103 , V_44 ) ;
}
}
if ( V_105 ) {
T_2 V_44 = F_79 ( F_17 ( V_26 ) ) - V_105 ;
if ( ( T_3 ) V_44 < 0 )
V_44 = 0 ;
if ( F_14 ( V_44 > F_80 ( V_29 -> V_93 . V_108 ) ) )
F_69 ( V_29 -> V_93 . V_108 , V_44 ) ;
F_69 ( V_29 -> V_93 . V_105 , 0 ) ;
F_71 ( V_29 -> V_93 . V_107 , V_44 ) ;
if ( V_103 ) {
if ( V_103 -> V_109 ) {
F_71 ( V_29 -> V_93 . V_110 , V_44 ) ;
F_84 ( V_29 -> V_93 . V_111 ) ;
F_88 ( V_103 , V_44 ) ;
}
F_89 ( V_103 , V_44 ) ;
if ( F_14 ( V_112 == V_113 ) ) {
F_90 ( V_113 ,
( void * ) F_91 ( V_103 ) ,
V_44 >> 20 ) ;
}
F_86 ( V_103 , V_44 >> 10 , 0 ) ;
}
}
}
static inline void
F_92 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_114 )
{
if ( ! F_78 () )
return;
if ( V_29 != V_26 -> V_47 )
F_77 ( V_26 , V_29 ) ;
if ( V_114 & V_115 )
F_85 ( V_26 , V_29 ) ;
}
static inline void
F_93 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_114 )
{
if ( ! F_78 () )
return;
if ( V_29 != V_26 -> V_47 )
F_82 ( V_26 , V_29 ) ;
if ( ( V_114 & V_116 ) && F_20 ( V_29 ) ) {
struct V_27 * V_103 = F_18 ( V_29 ) ;
if ( V_103 -> V_117 & V_118 )
F_69 ( V_29 -> V_93 . V_104 ,
F_79 ( F_17 ( V_26 ) ) ) ;
if ( V_103 -> V_117 & V_119 )
F_69 ( V_29 -> V_93 . V_105 ,
F_79 ( F_17 ( V_26 ) ) ) ;
}
}
static inline void
F_94 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_92 = F_68 ( F_17 ( V_26 ) ) ;
}
static unsigned int F_95 ( struct V_27 * V_30 )
{
unsigned long V_120 = 0 ;
unsigned long V_121 ;
V_121 = V_122 << ( 20 - V_123 ) ;
V_120 = F_96 ( V_30 -> V_124 ) ;
if ( ! V_120 )
V_120 = V_121 ;
V_120 = F_97 ( V_120 , V_121 ) ;
return V_120 / V_121 ;
}
static unsigned int F_98 ( struct V_27 * V_30 )
{
unsigned int V_125 = F_99 ( V_122 ) ;
unsigned int V_126 , floor ;
unsigned int V_127 = 1 ;
if ( V_125 < V_128 )
V_127 = V_128 / V_125 ;
floor = 1000 / V_127 ;
V_126 = V_129 / F_95 ( V_30 ) ;
return F_100 (unsigned int, floor, scan) ;
}
static unsigned int F_101 ( struct V_27 * V_30 )
{
unsigned long V_130 = F_98 ( V_30 ) ;
unsigned long V_131 = V_130 ;
if ( V_30 -> V_132 ) {
struct V_132 * V_133 = V_30 -> V_132 ;
unsigned long V_134 = F_102 ( V_133 ) ;
unsigned long V_135 = F_103 ( V_133 ) ;
V_131 *= F_104 ( & V_133 -> V_136 ) ;
V_131 *= V_134 + 1 ;
V_131 /= V_135 + V_134 + 1 ;
}
return F_70 ( V_130 , V_131 ) ;
}
static unsigned int F_105 ( struct V_27 * V_30 )
{
unsigned long V_130 = F_98 ( V_30 ) ;
unsigned long V_137 ;
V_137 = V_138 / F_95 ( V_30 ) ;
if ( V_30 -> V_132 ) {
struct V_132 * V_133 = V_30 -> V_132 ;
unsigned long V_134 = F_102 ( V_133 ) ;
unsigned long V_135 = F_103 ( V_133 ) ;
unsigned long V_131 = V_137 ;
V_131 *= F_104 ( & V_133 -> V_136 ) ;
V_131 *= V_134 + 1 ;
V_131 /= V_135 + V_134 + 1 ;
V_137 = F_70 ( V_137 , V_131 ) ;
}
return F_70 ( V_130 , V_137 ) ;
}
static void F_106 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
V_25 -> V_139 += ( V_30 -> V_140 != - 1 ) ;
V_25 -> V_141 += ( V_30 -> V_140 == F_107 ( V_30 ) ) ;
}
static void F_108 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
V_25 -> V_139 -= ( V_30 -> V_140 != - 1 ) ;
V_25 -> V_141 -= ( V_30 -> V_140 == F_107 ( V_30 ) ) ;
}
T_7 F_109 ( struct V_27 * V_30 )
{
return V_30 -> V_132 ? V_30 -> V_132 -> V_142 : 0 ;
}
static inline int F_110 ( enum V_143 V_144 , int V_145 , int V_146 )
{
return V_147 * ( V_144 * V_148 + V_145 ) + V_146 ;
}
static inline unsigned long F_111 ( struct V_27 * V_30 , int V_145 )
{
if ( ! V_30 -> V_149 )
return 0 ;
return V_30 -> V_149 [ F_110 ( V_150 , V_145 , 0 ) ] +
V_30 -> V_149 [ F_110 ( V_150 , V_145 , 1 ) ] ;
}
static inline unsigned long F_112 ( struct V_27 * V_30 , int V_145 )
{
if ( ! V_30 -> V_132 )
return 0 ;
return V_30 -> V_132 -> V_151 [ F_110 ( V_150 , V_145 , 0 ) ] +
V_30 -> V_132 -> V_151 [ F_110 ( V_150 , V_145 , 1 ) ] ;
}
static inline unsigned long F_113 ( struct V_132 * V_152 , int V_145 )
{
return V_152 -> V_153 [ F_110 ( V_150 , V_145 , 0 ) ] +
V_152 -> V_153 [ F_110 ( V_150 , V_145 , 1 ) ] ;
}
static inline unsigned long F_103 ( struct V_132 * V_133 )
{
unsigned long V_151 = 0 ;
int V_154 ;
F_114 (node) {
V_151 += V_133 -> V_151 [ F_110 ( V_150 , V_154 , 1 ) ] ;
}
return V_151 ;
}
static inline unsigned long F_102 ( struct V_132 * V_133 )
{
unsigned long V_151 = 0 ;
int V_154 ;
F_114 (node) {
V_151 += V_133 -> V_151 [ F_110 ( V_150 , V_154 , 0 ) ] ;
}
return V_151 ;
}
static bool F_115 ( int V_145 , struct V_132 * V_133 )
{
return F_113 ( V_133 , V_145 ) * V_155 > V_133 -> V_156 ;
}
static unsigned long F_116 ( struct V_27 * V_30 , int V_145 ,
int V_157 , bool V_158 )
{
unsigned long V_159 = 0 ;
int V_154 ;
if ( V_160 == V_161 )
return 0 ;
F_114 (node) {
unsigned long V_151 ;
int V_162 = F_117 ( V_145 , V_154 ) ;
if ( V_162 == V_163 || V_154 == V_145 )
continue;
if ( V_160 == V_164 &&
V_162 > V_157 )
continue;
if ( V_158 )
V_151 = F_111 ( V_30 , V_154 ) ;
else
V_151 = F_112 ( V_30 , V_154 ) ;
if ( V_160 == V_165 ) {
V_151 *= ( V_163 - V_162 ) ;
V_151 /= ( V_163 - V_166 ) ;
}
V_159 += V_151 ;
}
return V_159 ;
}
static inline unsigned long F_118 ( struct V_27 * V_30 , int V_145 ,
int V_162 )
{
unsigned long V_151 , V_167 ;
if ( ! V_30 -> V_149 )
return 0 ;
V_167 = V_30 -> V_168 ;
if ( ! V_167 )
return 0 ;
V_151 = F_111 ( V_30 , V_145 ) ;
V_151 += F_116 ( V_30 , V_145 , V_162 , true ) ;
return 1000 * V_151 / V_167 ;
}
static inline unsigned long F_119 ( struct V_27 * V_30 , int V_145 ,
int V_162 )
{
unsigned long V_151 , V_167 ;
if ( ! V_30 -> V_132 )
return 0 ;
V_167 = V_30 -> V_132 -> V_167 ;
if ( ! V_167 )
return 0 ;
V_151 = F_112 ( V_30 , V_145 ) ;
V_151 += F_116 ( V_30 , V_145 , V_162 , false ) ;
return 1000 * V_151 / V_167 ;
}
bool F_120 ( struct V_27 * V_30 , struct V_169 * V_169 ,
int V_170 , int V_171 )
{
struct V_132 * V_133 = V_30 -> V_132 ;
int V_172 = F_121 ( V_171 ) ;
int V_173 , V_174 ;
V_174 = F_122 ( V_171 , V_175 -> V_176 ) ;
V_173 = F_123 ( V_169 , V_174 ) ;
if ( ! F_124 ( V_173 ) &&
F_125 ( V_173 ) != V_172 )
return false ;
if ( F_126 ( V_30 , V_173 ) )
return true ;
if ( ! V_133 )
return true ;
if ( F_113 ( V_133 , V_172 ) > F_113 ( V_133 , V_170 ) *
V_155 )
return true ;
return F_113 ( V_133 , V_172 ) * F_112 ( V_30 , V_170 ) * 3 >
F_113 ( V_133 , V_170 ) * F_112 ( V_30 , V_172 ) * 4 ;
}
static void F_127 ( struct V_177 * V_178 , int V_145 )
{
int V_179 , V_1 , V_9 = 0 ;
unsigned long V_180 ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
F_128 (cpu, cpumask_of_node(nid)) {
struct V_25 * V_25 = F_129 ( V_1 ) ;
V_178 -> V_74 += V_25 -> V_74 ;
V_178 -> V_72 += F_130 ( V_25 ) ;
V_178 -> V_181 += F_131 ( V_1 ) ;
V_9 ++ ;
}
if ( ! V_9 )
return;
V_179 = F_55 ( V_87 * V_9 , V_178 -> V_181 ) ;
V_180 = V_9 / V_179 ;
V_178 -> V_182 = F_6 ( unsigned , V_180 ,
F_132 ( V_178 -> V_181 , V_87 ) ) ;
V_178 -> V_183 = ( V_178 -> V_74 < V_178 -> V_182 ) ;
}
static void F_133 ( struct V_184 * V_185 ,
struct V_27 * V_30 , long V_186 )
{
if ( V_185 -> V_187 )
F_134 ( V_185 -> V_187 ) ;
if ( V_30 )
F_135 ( V_30 ) ;
V_185 -> V_187 = V_30 ;
V_185 -> V_188 = V_186 ;
V_185 -> V_189 = V_185 -> V_171 ;
}
static bool F_136 ( long V_190 , long V_191 ,
struct V_184 * V_185 )
{
long V_192 , V_193 ;
long V_194 , V_195 ;
long V_196 , V_197 ;
V_196 = V_185 -> V_198 . V_181 ;
V_197 = V_185 -> V_199 . V_181 ;
if ( V_191 < V_190 )
F_137 ( V_191 , V_190 ) ;
V_192 = V_191 * V_196 * 100 -
V_190 * V_197 * V_185 -> V_200 ;
if ( V_192 <= 0 )
return false ;
V_194 = V_185 -> V_198 . V_72 ;
V_195 = V_185 -> V_199 . V_72 ;
if ( V_195 < V_194 )
F_137 ( V_195 , V_194 ) ;
V_193 = V_195 * V_196 * 100 -
V_194 * V_197 * V_185 -> V_200 ;
return ( V_192 > V_193 ) ;
}
static void F_138 ( struct V_184 * V_185 ,
long V_201 , long V_202 )
{
struct V_25 * V_203 = F_129 ( V_185 -> V_204 ) ;
struct V_25 * V_205 = F_129 ( V_185 -> V_171 ) ;
struct V_27 * V_206 ;
long V_190 , V_191 ;
long V_72 ;
long V_186 = V_185 -> V_30 -> V_132 ? V_202 : V_201 ;
long V_207 = V_186 ;
int V_162 = V_185 -> V_162 ;
F_139 () ;
V_206 = F_140 ( & V_205 -> V_47 ) ;
if ( V_206 && ( ( V_206 -> V_114 & V_208 ) || F_141 ( V_206 ) ) )
V_206 = NULL ;
if ( V_206 == V_185 -> V_30 )
goto V_209;
if ( V_206 ) {
if ( ! F_142 ( V_185 -> V_204 , & V_206 -> V_210 ) )
goto V_209;
if ( V_206 -> V_132 == V_185 -> V_30 -> V_132 ) {
V_186 = V_201 + F_118 ( V_206 , V_185 -> V_170 , V_162 ) -
F_118 ( V_206 , V_185 -> V_172 , V_162 ) ;
if ( V_206 -> V_132 )
V_186 -= V_186 / 16 ;
} else {
if ( V_206 -> V_132 )
V_186 += F_119 ( V_206 , V_185 -> V_170 , V_162 ) -
F_119 ( V_206 , V_185 -> V_172 , V_162 ) ;
else
V_186 += F_118 ( V_206 , V_185 -> V_170 , V_162 ) -
F_118 ( V_206 , V_185 -> V_172 , V_162 ) ;
}
}
if ( V_186 <= V_185 -> V_188 && V_207 <= V_185 -> V_188 )
goto V_209;
if ( ! V_206 ) {
if ( V_185 -> V_198 . V_74 <= V_185 -> V_198 . V_182 &&
! V_185 -> V_199 . V_183 )
goto V_209;
goto V_211;
}
if ( V_186 > V_185 -> V_188 && V_203 -> V_74 == 1 &&
V_205 -> V_74 == 1 )
goto V_212;
V_211:
V_72 = F_143 ( V_185 -> V_30 ) ;
V_191 = V_185 -> V_199 . V_72 + V_72 ;
V_190 = V_185 -> V_198 . V_72 - V_72 ;
if ( V_207 > V_186 && V_207 > V_185 -> V_188 ) {
if ( ! F_136 ( V_190 , V_191 , V_185 ) ) {
V_186 = V_207 - 1 ;
V_206 = NULL ;
goto V_212;
}
}
if ( V_186 <= V_185 -> V_188 )
goto V_209;
if ( V_206 ) {
V_72 = F_143 ( V_206 ) ;
V_191 -= V_72 ;
V_190 += V_72 ;
}
if ( F_136 ( V_190 , V_191 , V_185 ) )
goto V_209;
if ( ! V_206 ) {
F_144 () ;
V_185 -> V_171 = F_145 ( V_185 -> V_30 , V_185 -> V_204 ,
V_185 -> V_171 ) ;
F_146 () ;
}
V_212:
F_133 ( V_185 , V_206 , V_186 ) ;
V_209:
F_147 () ;
}
static void F_148 ( struct V_184 * V_185 ,
long V_201 , long V_202 )
{
int V_1 ;
F_128 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_142 ( V_1 , & V_185 -> V_30 -> V_210 ) )
continue;
V_185 -> V_171 = V_1 ;
F_138 ( V_185 , V_201 , V_202 ) ;
}
}
static bool F_149 ( struct V_184 * V_185 )
{
struct V_177 * V_213 = & V_185 -> V_198 ;
struct V_177 * V_214 = & V_185 -> V_199 ;
if ( V_213 -> V_183 && ! V_214 -> V_183 )
return false ;
if ( V_213 -> V_72 * V_214 -> V_181 * V_185 -> V_200 >
V_214 -> V_72 * V_213 -> V_181 * 100 )
return true ;
return false ;
}
static int F_150 ( struct V_27 * V_30 )
{
struct V_184 V_185 = {
. V_30 = V_30 ,
. V_204 = F_151 ( V_30 ) ,
. V_170 = F_107 ( V_30 ) ,
. V_200 = 112 ,
. V_187 = NULL ,
. V_188 = 0 ,
. V_189 = - 1 ,
} ;
struct V_215 * V_216 ;
unsigned long V_217 , V_218 ;
int V_145 , V_68 , V_162 ;
long V_201 , V_202 ;
F_139 () ;
V_216 = F_152 ( F_153 ( V_219 , V_185 . V_204 ) ) ;
if ( V_216 )
V_185 . V_200 = 100 + ( V_216 -> V_200 - 100 ) / 2 ;
F_147 () ;
if ( F_14 ( ! V_216 ) ) {
V_30 -> V_140 = F_107 ( V_30 ) ;
return - V_220 ;
}
V_185 . V_172 = V_30 -> V_140 ;
V_162 = V_185 . V_162 = F_117 ( V_185 . V_170 , V_185 . V_172 ) ;
V_217 = F_118 ( V_30 , V_185 . V_170 , V_162 ) ;
V_218 = F_119 ( V_30 , V_185 . V_170 , V_162 ) ;
F_127 ( & V_185 . V_198 , V_185 . V_170 ) ;
V_201 = F_118 ( V_30 , V_185 . V_172 , V_162 ) - V_217 ;
V_202 = F_119 ( V_30 , V_185 . V_172 , V_162 ) - V_218 ;
F_127 ( & V_185 . V_199 , V_185 . V_172 ) ;
if ( F_149 ( & V_185 ) )
F_148 ( & V_185 , V_201 , V_202 ) ;
if ( V_185 . V_189 == - 1 || ( V_30 -> V_132 && V_30 -> V_132 -> V_221 > 1 ) ) {
F_114 (nid) {
if ( V_145 == V_185 . V_170 || V_145 == V_30 -> V_140 )
continue;
V_162 = F_117 ( V_185 . V_170 , V_185 . V_172 ) ;
if ( V_160 == V_164 &&
V_162 != V_185 . V_162 ) {
V_217 = F_118 ( V_30 , V_185 . V_170 , V_162 ) ;
V_218 = F_119 ( V_30 , V_185 . V_170 , V_162 ) ;
}
V_201 = F_118 ( V_30 , V_145 , V_162 ) - V_217 ;
V_202 = F_119 ( V_30 , V_145 , V_162 ) - V_218 ;
if ( V_201 < 0 && V_202 < 0 )
continue;
V_185 . V_162 = V_162 ;
V_185 . V_172 = V_145 ;
F_127 ( & V_185 . V_199 , V_185 . V_172 ) ;
if ( F_149 ( & V_185 ) )
F_148 ( & V_185 , V_201 , V_202 ) ;
}
}
if ( V_30 -> V_132 ) {
struct V_132 * V_133 = V_30 -> V_132 ;
if ( V_185 . V_189 == - 1 )
V_145 = V_185 . V_170 ;
else
V_145 = V_185 . V_172 ;
if ( V_133 -> V_221 > 1 && F_115 ( V_185 . V_172 , V_133 ) )
F_154 ( V_30 , V_185 . V_172 ) ;
}
if ( V_185 . V_189 == - 1 )
return - V_222 ;
V_30 -> V_223 = F_101 ( V_30 ) ;
if ( V_185 . V_187 == NULL ) {
V_68 = F_155 ( V_30 , V_185 . V_189 ) ;
if ( V_68 != 0 )
F_156 ( V_30 , V_185 . V_204 , V_185 . V_189 ) ;
return V_68 ;
}
V_68 = F_157 ( V_30 , V_185 . V_187 ) ;
if ( V_68 != 0 )
F_156 ( V_30 , V_185 . V_204 , F_151 ( V_185 . V_187 ) ) ;
F_134 ( V_185 . V_187 ) ;
return V_68 ;
}
static void F_158 ( struct V_27 * V_30 )
{
unsigned long V_224 = V_225 ;
if ( F_14 ( V_30 -> V_140 == - 1 || ! V_30 -> V_149 ) )
return;
V_224 = F_159 ( V_224 , F_160 ( V_30 -> V_223 ) / 16 ) ;
V_30 -> V_226 = V_227 + V_224 ;
if ( F_107 ( V_30 ) == V_30 -> V_140 )
return;
F_150 ( V_30 ) ;
}
static void F_161 ( struct V_132 * V_132 )
{
unsigned long V_151 , V_228 = 0 ;
int V_145 , V_221 = 0 ;
F_114 (nid) {
V_151 = F_113 ( V_132 , V_145 ) ;
if ( V_151 > V_228 )
V_228 = V_151 ;
}
F_114 (nid) {
V_151 = F_113 ( V_132 , V_145 ) ;
if ( V_151 * V_155 > V_228 )
V_221 ++ ;
}
V_132 -> V_156 = V_228 ;
V_132 -> V_221 = V_221 ;
}
static void F_162 ( struct V_27 * V_30 ,
unsigned long V_134 , unsigned long V_135 )
{
unsigned int V_229 ;
int V_230 , V_231 ;
int V_232 ;
unsigned long V_233 = V_30 -> V_234 [ 0 ] ;
unsigned long V_235 = V_30 -> V_234 [ 1 ] ;
if ( V_235 + V_134 == 0 || V_30 -> V_234 [ 2 ] ) {
V_30 -> V_223 = F_159 ( V_30 -> V_236 ,
V_30 -> V_223 << 1 ) ;
V_30 -> V_124 -> V_237 = V_227 +
F_160 ( V_30 -> V_223 ) ;
return;
}
V_229 = F_55 ( V_30 -> V_223 , V_238 ) ;
V_230 = ( V_235 * V_238 ) / ( V_235 + V_233 ) ;
V_231 = ( V_135 * V_238 ) / ( V_135 + V_134 ) ;
if ( V_231 >= V_239 ) {
int V_240 = V_231 - V_239 ;
if ( ! V_240 )
V_240 = 1 ;
V_232 = V_240 * V_229 ;
} else if ( V_230 >= V_239 ) {
int V_240 = V_230 - V_239 ;
if ( ! V_240 )
V_240 = 1 ;
V_232 = V_240 * V_229 ;
} else {
int V_241 = F_70 ( V_230 , V_231 ) ;
V_232 = - ( V_239 - V_241 ) * V_229 ;
}
V_30 -> V_223 = F_163 ( V_30 -> V_223 + V_232 ,
F_98 ( V_30 ) , F_105 ( V_30 ) ) ;
memset ( V_30 -> V_234 , 0 , sizeof( V_30 -> V_234 ) ) ;
}
static T_2 F_164 ( struct V_27 * V_30 , T_2 * V_131 )
{
T_2 V_242 , V_44 , V_91 ;
V_91 = V_30 -> V_29 . V_92 ;
V_242 = V_30 -> V_29 . V_95 ;
if ( V_30 -> V_243 ) {
V_44 = V_242 - V_30 -> V_244 ;
* V_131 = V_91 - V_30 -> V_243 ;
} else {
V_44 = V_30 -> V_29 . V_78 . V_82 / V_30 -> V_29 . V_72 . V_5 ;
* V_131 = V_83 ;
}
V_30 -> V_244 = V_242 ;
V_30 -> V_243 = V_91 ;
return V_44 ;
}
static int F_165 ( struct V_27 * V_30 , int V_145 )
{
T_8 V_245 ;
int V_162 ;
if ( V_160 == V_161 )
return V_145 ;
if ( V_160 == V_165 ) {
unsigned long V_159 , V_246 = 0 ;
int V_154 , V_247 = V_145 ;
V_162 = V_163 ;
F_114 (node) {
V_159 = F_119 ( V_30 , V_154 , V_162 ) ;
if ( V_159 > V_246 ) {
V_246 = V_159 ;
V_247 = V_154 ;
}
}
return V_247 ;
}
V_245 = V_248 ;
for ( V_162 = V_163 ; V_162 > V_166 ; V_162 -- ) {
unsigned long V_228 = 0 ;
T_8 V_249 = V_250 ;
int V_45 , V_46 ;
if ( ! F_166 ( V_162 ) )
continue;
F_167 (a, nodes) {
unsigned long V_151 = 0 ;
T_8 V_251 ;
F_168 ( V_251 ) ;
F_167 (b, nodes) {
if ( F_117 ( V_45 , V_46 ) < V_162 ) {
V_151 += F_112 ( V_30 , V_46 ) ;
F_169 ( V_46 , V_251 ) ;
F_170 ( V_46 , V_245 ) ;
}
}
if ( V_151 > V_228 ) {
V_228 = V_151 ;
V_249 = V_251 ;
V_145 = V_45 ;
}
}
if ( ! V_228 )
break;
V_245 = V_249 ;
}
return V_145 ;
}
static void F_171 ( struct V_27 * V_30 )
{
int V_252 , V_145 , V_253 = - 1 , V_254 = - 1 ;
unsigned long V_228 = 0 , V_255 = 0 ;
unsigned long V_256 [ 2 ] = { 0 , 0 } ;
unsigned long V_167 ;
T_2 V_242 , V_131 ;
T_9 * V_257 = NULL ;
V_252 = F_99 ( V_30 -> V_124 -> V_258 ) ;
if ( V_30 -> V_258 == V_252 )
return;
V_30 -> V_258 = V_252 ;
V_30 -> V_236 = F_105 ( V_30 ) ;
V_167 = V_30 -> V_234 [ 0 ] +
V_30 -> V_234 [ 1 ] ;
V_242 = F_164 ( V_30 , & V_131 ) ;
if ( V_30 -> V_132 ) {
V_257 = & V_30 -> V_132 -> V_259 ;
F_172 ( V_257 ) ;
}
F_114 (nid) {
int V_260 , V_261 , V_262 , V_263 ;
unsigned long V_151 = 0 , F_112 = 0 ;
int V_146 ;
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
long V_232 , V_264 , V_265 ;
V_260 = F_110 ( V_150 , V_145 , V_146 ) ;
V_261 = F_110 ( V_266 , V_145 , V_146 ) ;
V_262 = F_110 ( V_267 , V_145 , V_146 ) ;
V_263 = F_110 ( V_268 , V_145 , V_146 ) ;
V_232 = V_30 -> V_149 [ V_261 ] - V_30 -> V_149 [ V_260 ] / 2 ;
V_256 [ V_146 ] += V_30 -> V_149 [ V_261 ] ;
V_30 -> V_149 [ V_261 ] = 0 ;
V_265 = F_173 ( V_242 << 16 , V_131 + 1 ) ;
V_265 = ( V_265 * V_30 -> V_149 [ V_263 ] ) /
( V_167 + 1 ) ;
V_264 = V_265 - V_30 -> V_149 [ V_262 ] / 2 ;
V_30 -> V_149 [ V_263 ] = 0 ;
V_30 -> V_149 [ V_260 ] += V_232 ;
V_30 -> V_149 [ V_262 ] += V_264 ;
V_151 += V_30 -> V_149 [ V_260 ] ;
V_30 -> V_168 += V_232 ;
if ( V_30 -> V_132 ) {
V_30 -> V_132 -> V_151 [ V_260 ] += V_232 ;
V_30 -> V_132 -> V_153 [ V_260 ] += V_264 ;
V_30 -> V_132 -> V_167 += V_232 ;
F_112 += V_30 -> V_132 -> V_151 [ V_260 ] ;
}
}
if ( V_151 > V_228 ) {
V_228 = V_151 ;
V_253 = V_145 ;
}
if ( F_112 > V_255 ) {
V_255 = F_112 ;
V_254 = V_145 ;
}
}
F_162 ( V_30 , V_256 [ 0 ] , V_256 [ 1 ] ) ;
if ( V_30 -> V_132 ) {
F_161 ( V_30 -> V_132 ) ;
F_174 ( V_257 ) ;
V_253 = F_165 ( V_30 , V_254 ) ;
}
if ( V_228 ) {
if ( V_253 != V_30 -> V_140 )
F_154 ( V_30 , V_253 ) ;
if ( F_107 ( V_30 ) != V_30 -> V_140 )
F_158 ( V_30 ) ;
}
}
static inline int F_175 ( struct V_132 * V_31 )
{
return F_176 ( & V_31 -> V_136 ) ;
}
static inline void F_177 ( struct V_132 * V_31 )
{
if ( F_178 ( & V_31 -> V_136 ) )
F_179 ( V_31 , V_269 ) ;
}
static void F_180 ( struct V_27 * V_30 , int V_270 , int V_114 ,
int * V_146 )
{
struct V_132 * V_31 , * V_271 ;
struct V_27 * V_103 ;
bool V_272 = false ;
int V_1 = F_181 ( V_270 ) ;
int V_273 ;
if ( F_14 ( ! V_30 -> V_132 ) ) {
unsigned int V_274 = sizeof( struct V_132 ) +
4 * V_148 *sizeof( unsigned long ) ;
V_31 = F_182 ( V_274 , V_275 | V_276 ) ;
if ( ! V_31 )
return;
F_183 ( & V_31 -> V_136 , 1 ) ;
V_31 -> V_221 = 1 ;
V_31 -> V_156 = 0 ;
F_184 ( & V_31 -> V_259 ) ;
V_31 -> V_142 = V_30 -> V_176 ;
V_31 -> V_153 = V_31 -> V_151 + V_147 *
V_148 ;
for ( V_273 = 0 ; V_273 < V_277 * V_148 ; V_273 ++ )
V_31 -> V_151 [ V_273 ] = V_30 -> V_149 [ V_273 ] ;
V_31 -> V_167 = V_30 -> V_168 ;
V_31 -> V_278 ++ ;
F_185 ( V_30 -> V_132 , V_31 ) ;
}
F_139 () ;
V_103 = F_99 ( F_129 ( V_1 ) -> V_47 ) ;
if ( ! F_126 ( V_103 , V_270 ) )
goto V_279;
V_31 = F_152 ( V_103 -> V_132 ) ;
if ( ! V_31 )
goto V_279;
V_271 = V_30 -> V_132 ;
if ( V_31 == V_271 )
goto V_279;
if ( V_271 -> V_278 > V_31 -> V_278 )
goto V_279;
if ( V_271 -> V_278 == V_31 -> V_278 && V_271 > V_31 )
goto V_279;
if ( V_103 -> V_124 == V_175 -> V_124 )
V_272 = true ;
if ( V_114 & V_280 )
V_272 = true ;
* V_146 = ! V_272 ;
if ( V_272 && ! F_175 ( V_31 ) )
goto V_279;
F_147 () ;
if ( ! V_272 )
return;
F_186 ( F_187 () ) ;
F_188 ( & V_271 -> V_259 , & V_31 -> V_259 ) ;
for ( V_273 = 0 ; V_273 < V_277 * V_148 ; V_273 ++ ) {
V_271 -> V_151 [ V_273 ] -= V_30 -> V_149 [ V_273 ] ;
V_31 -> V_151 [ V_273 ] += V_30 -> V_149 [ V_273 ] ;
}
V_271 -> V_167 -= V_30 -> V_168 ;
V_31 -> V_167 += V_30 -> V_168 ;
V_271 -> V_278 -- ;
V_31 -> V_278 ++ ;
F_189 ( & V_271 -> V_259 ) ;
F_174 ( & V_31 -> V_259 ) ;
F_185 ( V_30 -> V_132 , V_31 ) ;
F_177 ( V_271 ) ;
return;
V_279:
F_147 () ;
return;
}
void F_190 ( struct V_27 * V_30 )
{
struct V_132 * V_31 = V_30 -> V_132 ;
void * V_149 = V_30 -> V_149 ;
unsigned long V_114 ;
int V_273 ;
if ( V_31 ) {
F_191 ( & V_31 -> V_259 , V_114 ) ;
for ( V_273 = 0 ; V_273 < V_277 * V_148 ; V_273 ++ )
V_31 -> V_151 [ V_273 ] -= V_30 -> V_149 [ V_273 ] ;
V_31 -> V_167 -= V_30 -> V_168 ;
V_31 -> V_278 -- ;
F_192 ( & V_31 -> V_259 , V_114 ) ;
F_193 ( V_30 -> V_132 , NULL ) ;
F_177 ( V_31 ) ;
}
V_30 -> V_149 = NULL ;
F_194 ( V_149 ) ;
}
void F_195 ( int V_173 , int V_281 , int V_282 , int V_114 )
{
struct V_27 * V_30 = V_175 ;
bool V_283 = V_114 & V_284 ;
int V_285 = F_107 ( V_175 ) ;
int V_235 = ! ! ( V_114 & V_286 ) ;
struct V_132 * V_133 ;
int V_146 ;
if ( ! F_196 ( & V_287 ) )
return;
if ( ! V_30 -> V_124 )
return;
if ( F_14 ( ! V_30 -> V_149 ) ) {
int V_274 = sizeof( * V_30 -> V_149 ) *
V_288 * V_148 ;
V_30 -> V_149 = F_182 ( V_274 , V_275 | V_276 ) ;
if ( ! V_30 -> V_149 )
return;
V_30 -> V_168 = 0 ;
memset ( V_30 -> V_234 , 0 , sizeof( V_30 -> V_234 ) ) ;
}
if ( F_14 ( V_173 == ( - 1 & V_289 ) ) ) {
V_146 = 1 ;
} else {
V_146 = F_126 ( V_30 , V_173 ) ;
if ( ! V_146 && ! ( V_114 & V_290 ) )
F_180 ( V_30 , V_173 , V_114 , & V_146 ) ;
}
V_133 = V_30 -> V_132 ;
if ( ! V_146 && ! V_235 && V_133 && V_133 -> V_221 > 1 &&
F_115 ( V_285 , V_133 ) &&
F_115 ( V_281 , V_133 ) )
V_235 = 1 ;
F_171 ( V_30 ) ;
if ( F_197 ( V_227 , V_30 -> V_226 ) )
F_158 ( V_30 ) ;
if ( V_283 )
V_30 -> V_291 += V_282 ;
if ( V_114 & V_292 )
V_30 -> V_234 [ 2 ] += V_282 ;
V_30 -> V_149 [ F_110 ( V_266 , V_281 , V_146 ) ] += V_282 ;
V_30 -> V_149 [ F_110 ( V_268 , V_285 , V_146 ) ] += V_282 ;
V_30 -> V_234 [ V_235 ] += V_282 ;
}
static void F_198 ( struct V_27 * V_30 )
{
F_199 ( V_30 -> V_124 -> V_258 , F_99 ( V_30 -> V_124 -> V_258 ) + 1 ) ;
V_30 -> V_124 -> V_293 = 0 ;
}
void F_200 ( struct V_294 * V_295 )
{
unsigned long V_296 , V_297 , V_91 = V_227 ;
struct V_27 * V_30 = V_175 ;
struct V_298 * V_124 = V_30 -> V_124 ;
T_2 V_242 = V_30 -> V_29 . V_95 ;
struct V_299 * V_300 ;
unsigned long V_301 , V_302 ;
unsigned long V_303 = 0 ;
long V_282 , V_304 ;
F_19 ( V_30 != F_21 ( V_295 , struct V_27 , V_305 ) ) ;
V_295 -> V_60 = V_295 ;
if ( V_30 -> V_114 & V_208 )
return;
if ( ! V_124 -> V_237 ) {
V_124 -> V_237 = V_91 +
F_160 ( V_306 ) ;
}
V_296 = V_124 -> V_237 ;
if ( F_201 ( V_91 , V_296 ) )
return;
if ( V_30 -> V_223 == 0 ) {
V_30 -> V_236 = F_105 ( V_30 ) ;
V_30 -> V_223 = F_101 ( V_30 ) ;
}
V_297 = V_91 + F_160 ( V_30 -> V_223 ) ;
if ( F_202 ( & V_124 -> V_237 , V_296 , V_297 ) != V_296 )
return;
V_30 -> V_307 += 2 * V_308 ;
V_301 = V_124 -> V_293 ;
V_282 = V_122 ;
V_282 <<= 20 - V_123 ;
V_304 = V_282 * 8 ;
if ( ! V_282 )
return;
if ( ! F_203 ( & V_124 -> V_309 ) )
return;
V_300 = F_204 ( V_124 , V_301 ) ;
if ( ! V_300 ) {
F_198 ( V_30 ) ;
V_301 = 0 ;
V_300 = V_124 -> V_310 ;
}
for (; V_300 ; V_300 = V_300 -> V_311 ) {
if ( ! F_205 ( V_300 ) || ! F_206 ( V_300 ) ||
F_207 ( V_300 ) || ( V_300 -> V_312 & V_313 ) ) {
continue;
}
if ( ! V_300 -> V_314 ||
( V_300 -> V_315 && ( V_300 -> V_312 & ( V_316 | V_317 ) ) == ( V_316 ) ) )
continue;
if ( ! ( V_300 -> V_312 & ( V_316 | V_318 | V_317 ) ) )
continue;
do {
V_301 = F_70 ( V_301 , V_300 -> V_319 ) ;
V_302 = F_208 ( V_301 + ( V_282 << V_123 ) , V_320 ) ;
V_302 = F_159 ( V_302 , V_300 -> V_321 ) ;
V_303 = F_209 ( V_300 , V_301 , V_302 ) ;
if ( V_303 )
V_282 -= ( V_302 - V_301 ) >> V_123 ;
V_304 -= ( V_302 - V_301 ) >> V_123 ;
V_301 = V_302 ;
if ( V_282 <= 0 || V_304 <= 0 )
goto V_322;
F_210 () ;
} while ( V_302 != V_300 -> V_321 );
}
V_322:
if ( V_300 )
V_124 -> V_293 = V_301 ;
else
F_198 ( V_30 ) ;
F_211 ( & V_124 -> V_309 ) ;
if ( F_14 ( V_30 -> V_29 . V_95 != V_242 ) ) {
T_2 V_232 = V_30 -> V_29 . V_95 - V_242 ;
V_30 -> V_307 += 32 * V_232 ;
}
}
void F_212 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
struct V_294 * V_295 = & V_47 -> V_305 ;
T_2 V_131 , V_91 ;
if ( ! V_47 -> V_124 || ( V_47 -> V_114 & V_208 ) || V_295 -> V_60 != V_295 )
return;
V_91 = V_47 -> V_29 . V_95 ;
V_131 = ( T_2 ) V_47 -> V_223 * V_323 ;
if ( V_91 > V_47 -> V_307 + V_131 ) {
if ( ! V_47 -> V_307 )
V_47 -> V_223 = F_101 ( V_47 ) ;
V_47 -> V_307 += V_131 ;
if ( ! F_201 ( V_227 , V_47 -> V_124 -> V_237 ) ) {
F_213 ( V_295 , F_200 ) ;
F_214 ( V_47 , V_295 , true ) ;
}
}
}
static void F_212 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
}
static inline void F_106 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_108 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static void
F_215 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_2 ( & V_26 -> V_72 , V_29 -> V_72 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_2 ( & F_17 ( V_26 ) -> V_72 , V_29 -> V_72 . V_5 ) ;
#ifdef F_216
if ( F_20 ( V_29 ) ) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
F_106 ( V_25 , F_18 ( V_29 ) ) ;
F_217 ( & V_29 -> V_324 , & V_25 -> V_325 ) ;
}
#endif
V_26 -> V_74 ++ ;
}
static void
F_218 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_3 ( & V_26 -> V_72 , V_29 -> V_72 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_3 ( & F_17 ( V_26 ) -> V_72 , V_29 -> V_72 . V_5 ) ;
#ifdef F_216
if ( F_20 ( V_29 ) ) {
F_108 ( F_17 ( V_26 ) , F_18 ( V_29 ) ) ;
F_219 ( & V_29 -> V_324 ) ;
}
#endif
V_26 -> V_74 -- ;
}
static long F_220 ( struct V_26 * V_26 , struct V_326 * V_34 )
{
long V_327 , V_72 , V_328 ;
V_72 = F_13 ( V_26 -> V_72 . V_5 ) ;
V_327 = F_221 ( & V_34 -> V_81 ) ;
V_327 -= V_26 -> V_329 ;
V_327 += V_72 ;
V_328 = ( V_34 -> V_328 * V_72 ) ;
if ( V_327 )
V_328 /= V_327 ;
if ( V_328 < V_330 )
V_328 = V_330 ;
if ( V_328 > V_34 -> V_328 )
V_328 = V_34 -> V_328 ;
return V_328 ;
}
static inline long F_220 ( struct V_26 * V_26 , struct V_326 * V_34 )
{
return V_34 -> V_328 ;
}
static void F_222 ( struct V_26 * V_26 , struct V_28 * V_29 ,
unsigned long V_5 )
{
if ( V_29 -> V_51 ) {
if ( V_26 -> V_47 == V_29 )
F_67 ( V_26 ) ;
F_218 ( V_26 , V_29 ) ;
}
F_4 ( & V_29 -> V_72 , V_5 ) ;
if ( V_29 -> V_51 )
F_215 ( V_26 , V_29 ) ;
}
static void F_223 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
struct V_326 * V_34 ;
long V_328 ;
if ( ! V_26 )
return;
if ( F_224 ( V_26 ) )
return;
V_34 = V_26 -> V_34 ;
#ifndef F_216
if ( F_12 ( V_29 -> V_72 . V_5 == V_34 -> V_328 ) )
return;
#endif
V_328 = F_220 ( V_26 , V_34 ) ;
F_222 ( F_23 ( V_29 ) , V_29 , V_328 ) ;
}
static inline void F_223 ( struct V_28 * V_29 )
{
}
static inline void F_225 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
if ( & V_25 -> V_42 == V_26 ) {
F_226 ( V_25 , 0 ) ;
}
}
static T_2 F_227 ( T_2 V_331 , T_2 V_332 )
{
unsigned int V_333 ;
if ( F_14 ( V_332 > V_334 * 63 ) )
return 0 ;
V_333 = V_332 ;
if ( F_14 ( V_333 >= V_334 ) ) {
V_331 >>= V_333 / V_334 ;
V_333 %= V_334 ;
}
V_331 = F_16 ( V_331 , V_335 [ V_333 ] , 32 ) ;
return V_331 ;
}
static V_24 F_228 ( T_2 V_336 , V_24 V_337 , V_24 V_338 )
{
V_24 V_339 , V_340 , V_341 = V_338 ;
V_339 = F_227 ( ( T_2 ) V_337 , V_336 ) ;
V_340 = V_83 - F_227 ( V_83 , V_336 ) - 1024 ;
return V_339 + V_340 + V_341 ;
}
static T_10 V_24
F_229 ( T_2 V_44 , int V_1 , struct V_76 * V_77 ,
unsigned long V_5 , int V_342 , struct V_26 * V_26 )
{
unsigned long V_343 , V_344 ;
V_24 V_345 = ( V_24 ) V_44 ;
T_2 V_336 ;
V_343 = F_230 ( NULL , V_1 ) ;
V_344 = F_231 ( NULL , V_1 ) ;
V_44 += V_77 -> V_80 ;
V_336 = V_44 / 1024 ;
if ( V_336 ) {
V_77 -> V_82 = F_227 ( V_77 -> V_82 , V_336 ) ;
if ( V_26 ) {
V_26 -> V_346 =
F_227 ( V_26 -> V_346 , V_336 ) ;
}
V_77 -> V_85 = F_227 ( ( T_2 ) ( V_77 -> V_85 ) , V_336 ) ;
V_44 %= 1024 ;
V_345 = F_228 ( V_336 ,
1024 - V_77 -> V_80 , V_44 ) ;
}
V_77 -> V_80 = V_44 ;
V_345 = F_232 ( V_345 , V_343 ) ;
if ( V_5 ) {
V_77 -> V_82 += V_5 * V_345 ;
if ( V_26 )
V_26 -> V_346 += V_5 * V_345 ;
}
if ( V_342 )
V_77 -> V_85 += V_345 * V_344 ;
return V_336 ;
}
static T_10 int
F_233 ( T_2 V_91 , int V_1 , struct V_76 * V_77 ,
unsigned long V_5 , int V_342 , struct V_26 * V_26 )
{
T_2 V_44 ;
V_44 = V_91 - V_77 -> V_79 ;
if ( ( T_3 ) V_44 < 0 ) {
V_77 -> V_79 = V_91 ;
return 0 ;
}
V_44 >>= 10 ;
if ( ! V_44 )
return 0 ;
V_77 -> V_79 += V_44 << 10 ;
if ( ! V_5 )
V_342 = 0 ;
if ( ! F_229 ( V_44 , V_1 , V_77 , V_5 , V_342 , V_26 ) )
return 0 ;
V_77 -> V_81 = F_234 ( V_77 -> V_82 , V_83 - 1024 + V_77 -> V_80 ) ;
if ( V_26 ) {
V_26 -> V_347 =
F_234 ( V_26 -> V_346 , V_83 - 1024 + V_77 -> V_80 ) ;
}
V_77 -> V_84 = V_77 -> V_85 / ( V_83 - 1024 + V_77 -> V_80 ) ;
return 1 ;
}
static int
F_235 ( T_2 V_91 , int V_1 , struct V_28 * V_29 )
{
return F_233 ( V_91 , V_1 , & V_29 -> V_78 , 0 , 0 , NULL ) ;
}
static int
F_236 ( T_2 V_91 , int V_1 , struct V_26 * V_26 , struct V_28 * V_29 )
{
return F_233 ( V_91 , V_1 , & V_29 -> V_78 ,
V_29 -> V_51 * F_13 ( V_29 -> V_72 . V_5 ) ,
V_26 -> V_47 == V_29 , NULL ) ;
}
static int
F_237 ( T_2 V_91 , int V_1 , struct V_26 * V_26 )
{
return F_233 ( V_91 , V_1 , & V_26 -> V_78 ,
F_13 ( V_26 -> V_72 . V_5 ) ,
V_26 -> V_47 != NULL , V_26 ) ;
}
static inline void F_66 ( struct V_26 * V_26 , int V_90 )
{
long V_44 = V_26 -> V_78 . V_81 - V_26 -> V_329 ;
if ( V_26 -> V_34 == & V_348 )
return;
if ( V_90 || abs ( V_44 ) > V_26 -> V_329 / 64 ) {
F_238 ( V_44 , & V_26 -> V_34 -> V_81 ) ;
V_26 -> V_329 = V_26 -> V_78 . V_81 ;
}
}
void F_239 ( struct V_28 * V_29 ,
struct V_26 * V_349 , struct V_26 * V_60 )
{
T_2 V_350 ;
T_2 V_351 ;
if ( ! F_240 ( V_352 ) )
return;
if ( ! ( V_29 -> V_78 . V_79 && V_349 ) )
return;
#ifndef F_41
{
T_2 V_353 ;
T_2 V_354 ;
do {
V_353 = V_349 -> V_355 ;
V_354 = V_60 -> V_355 ;
F_241 () ;
V_350 = V_349 -> V_78 . V_79 ;
V_351 = V_60 -> V_78 . V_79 ;
} while ( V_350 != V_353 ||
V_351 != V_354 );
}
#else
V_350 = V_349 -> V_78 . V_79 ;
V_351 = V_60 -> V_78 . V_79 ;
#endif
F_235 ( V_350 , F_26 ( F_17 ( V_349 ) ) , V_29 ) ;
V_29 -> V_78 . V_79 = V_351 ;
}
static inline void
F_242 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_356 = F_24 ( V_29 ) ;
long V_44 = V_356 -> V_78 . V_84 - V_29 -> V_78 . V_84 ;
if ( ! V_44 )
return;
V_29 -> V_78 . V_84 = V_356 -> V_78 . V_84 ;
V_29 -> V_78 . V_85 = V_29 -> V_78 . V_84 * V_83 ;
F_243 ( & V_26 -> V_78 . V_84 , V_44 ) ;
V_26 -> V_78 . V_85 = V_26 -> V_78 . V_84 * V_83 ;
}
static inline void
F_244 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_356 = F_24 ( V_29 ) ;
long V_44 , V_72 = V_356 -> V_78 . V_81 ;
if ( V_72 ) {
long V_357 ;
V_357 = F_221 ( & V_356 -> V_34 -> V_81 ) + 1 ;
V_357 -= V_356 -> V_329 ;
V_357 += V_72 ;
if ( V_357 > F_13 ( V_356 -> V_34 -> V_328 ) ) {
V_72 *= F_13 ( V_356 -> V_34 -> V_328 ) ;
V_72 /= V_357 ;
}
}
V_44 = V_72 - V_29 -> V_78 . V_81 ;
if ( ! V_44 )
return;
V_29 -> V_78 . V_81 = V_72 ;
V_29 -> V_78 . V_82 = V_29 -> V_78 . V_81 * V_83 ;
F_243 ( & V_26 -> V_78 . V_81 , V_44 ) ;
V_26 -> V_78 . V_82 = V_26 -> V_78 . V_81 * V_83 ;
if ( V_29 -> V_51 ) {
F_243 ( & V_26 -> V_347 , V_44 ) ;
V_26 -> V_346 = V_26 -> V_347 * V_83 ;
}
}
static inline void F_245 ( struct V_26 * V_26 )
{
V_26 -> V_358 = 1 ;
}
static inline int F_246 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
if ( ! V_26 -> V_358 )
return 0 ;
V_26 -> V_358 = 0 ;
return 1 ;
}
static inline int F_247 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
if ( F_20 ( V_29 ) )
return 0 ;
if ( ! F_246 ( V_29 ) )
return 0 ;
V_26 = F_23 ( V_29 ) ;
F_245 ( V_26 ) ;
F_242 ( V_26 , V_29 ) ;
F_244 ( V_26 , V_29 ) ;
return 1 ;
}
static inline bool F_248 ( struct V_28 * V_29 )
{
struct V_26 * V_356 = F_24 ( V_29 ) ;
if ( V_29 -> V_78 . V_81 || V_29 -> V_78 . V_84 )
return false ;
if ( V_356 -> V_358 )
return false ;
return true ;
}
static inline void F_66 ( struct V_26 * V_26 , int V_90 ) {}
static inline int F_247 ( struct V_28 * V_29 )
{
return 0 ;
}
static inline void F_245 ( struct V_26 * V_26 ) {}
static inline int
F_249 ( T_2 V_91 , struct V_26 * V_26 )
{
struct V_76 * V_77 = & V_26 -> V_78 ;
int V_359 , V_360 = 0 , V_361 = 0 ;
if ( F_221 ( & V_26 -> V_362 ) ) {
T_3 V_363 = F_250 ( & V_26 -> V_362 , 0 ) ;
F_251 ( & V_77 -> V_81 , V_363 ) ;
F_251 ( & V_77 -> V_82 , V_363 * V_83 ) ;
V_360 = 1 ;
F_245 ( V_26 ) ;
}
if ( F_221 ( & V_26 -> V_364 ) ) {
long V_363 = F_250 ( & V_26 -> V_364 , 0 ) ;
F_251 ( & V_77 -> V_84 , V_363 ) ;
F_251 ( & V_77 -> V_85 , V_363 * V_83 ) ;
V_361 = 1 ;
F_245 ( V_26 ) ;
}
V_359 = F_237 ( V_91 , F_26 ( F_17 ( V_26 ) ) , V_26 ) ;
#ifndef F_41
F_42 () ;
V_26 -> V_355 = V_77 -> V_79 ;
#endif
if ( V_359 || V_361 )
F_225 ( V_26 ) ;
return V_359 || V_360 ;
}
static inline void F_252 ( struct V_28 * V_29 , int V_114 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_91 = F_64 ( V_26 ) ;
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
int V_359 ;
if ( V_29 -> V_78 . V_79 && ! ( V_114 & V_365 ) )
F_236 ( V_91 , V_1 , V_26 , V_29 ) ;
V_359 = F_249 ( V_91 , V_26 ) ;
V_359 |= F_247 ( V_29 ) ;
if ( V_359 && ( V_114 & V_366 ) )
F_66 ( V_26 , 0 ) ;
}
static void F_253 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_78 . V_79 = V_26 -> V_78 . V_79 ;
V_26 -> V_78 . V_81 += V_29 -> V_78 . V_81 ;
V_26 -> V_78 . V_82 += V_29 -> V_78 . V_82 ;
V_26 -> V_78 . V_84 += V_29 -> V_78 . V_84 ;
V_26 -> V_78 . V_85 += V_29 -> V_78 . V_85 ;
F_245 ( V_26 ) ;
F_225 ( V_26 ) ;
}
static void F_254 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_251 ( & V_26 -> V_78 . V_81 , V_29 -> V_78 . V_81 ) ;
F_251 ( & V_26 -> V_78 . V_82 , V_29 -> V_78 . V_82 ) ;
F_251 ( & V_26 -> V_78 . V_84 , V_29 -> V_78 . V_84 ) ;
F_251 ( & V_26 -> V_78 . V_85 , V_29 -> V_78 . V_85 ) ;
F_245 ( V_26 ) ;
F_225 ( V_26 ) ;
}
static inline void
F_255 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_76 * V_77 = & V_29 -> V_78 ;
V_26 -> V_347 += V_77 -> V_81 ;
V_26 -> V_346 += V_77 -> V_82 ;
if ( ! V_77 -> V_79 ) {
F_253 ( V_26 , V_29 ) ;
F_66 ( V_26 , 0 ) ;
}
}
static inline void
F_256 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_26 -> V_347 =
F_100 ( long , V_26 -> V_347 - V_29 -> V_78 . V_81 , 0 ) ;
V_26 -> V_346 =
F_100 ( T_3 , V_26 -> V_346 - V_29 -> V_78 . V_82 , 0 ) ;
}
static inline T_2 F_257 ( struct V_26 * V_26 )
{
T_2 V_367 ;
T_2 V_79 ;
do {
V_367 = V_26 -> V_355 ;
F_241 () ;
V_79 = V_26 -> V_78 . V_79 ;
} while ( V_79 != V_367 );
return V_79 ;
}
static inline T_2 F_257 ( struct V_26 * V_26 )
{
return V_26 -> V_78 . V_79 ;
}
void F_258 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_79 ;
V_79 = F_257 ( V_26 ) ;
F_235 ( V_79 , F_26 ( F_17 ( V_26 ) ) , V_29 ) ;
}
void F_259 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_258 ( V_29 ) ;
F_238 ( V_29 -> V_78 . V_81 , & V_26 -> V_362 ) ;
F_238 ( V_29 -> V_78 . V_84 , & V_26 -> V_364 ) ;
}
static inline unsigned long F_260 ( struct V_26 * V_26 )
{
return V_26 -> V_347 ;
}
static inline unsigned long F_261 ( struct V_26 * V_26 )
{
return V_26 -> V_78 . V_81 ;
}
static inline int
F_249 ( T_2 V_91 , struct V_26 * V_26 )
{
return 0 ;
}
static inline void F_252 ( struct V_28 * V_29 , int V_368 )
{
F_225 ( F_23 ( V_29 ) ) ;
}
static inline void
F_255 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_256 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void F_259 ( struct V_28 * V_29 ) {}
static inline void
F_253 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_254 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline int F_262 ( struct V_25 * V_25 , struct V_369 * V_370 )
{
return 0 ;
}
static void F_263 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
#ifdef F_264
T_3 V_371 = V_29 -> V_43 - V_26 -> F_36 ;
if ( V_371 < 0 )
V_371 = - V_371 ;
if ( V_371 > 3 * V_70 )
F_84 ( V_26 -> V_372 ) ;
#endif
}
static void
F_265 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_373 )
{
T_2 V_43 = V_26 -> F_36 ;
if ( V_373 && F_240 ( V_374 ) )
V_43 += F_61 ( V_26 , V_29 ) ;
if ( ! V_373 ) {
unsigned long V_375 = V_70 ;
if ( F_240 ( V_376 ) )
V_375 >>= 1 ;
V_43 -= V_375 ;
}
V_29 -> V_43 = F_35 ( V_29 -> V_43 , V_43 ) ;
}
static inline void F_266 ( void )
{
#ifdef F_267
if ( F_78 () )
return;
if ( F_268 () ||
F_269 () ||
F_270 () ||
F_271 () ||
F_272 () ) {
F_273 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_274 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_114 )
{
bool V_377 = ! ( V_114 & V_115 ) || ( V_114 & V_378 ) ;
bool V_47 = V_26 -> V_47 == V_29 ;
if ( V_377 && V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_67 ( V_26 ) ;
if ( V_377 && ! V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_252 ( V_29 , V_366 ) ;
F_255 ( V_26 , V_29 ) ;
F_223 ( V_29 ) ;
F_215 ( V_26 , V_29 ) ;
if ( V_114 & V_115 )
F_265 ( V_26 , V_29 , 0 ) ;
F_266 () ;
F_92 ( V_26 , V_29 , V_114 ) ;
F_263 ( V_26 , V_29 ) ;
if ( ! V_47 )
F_43 ( V_26 , V_29 ) ;
V_29 -> V_51 = 1 ;
if ( V_26 -> V_74 == 1 ) {
F_25 ( V_26 ) ;
F_275 ( V_26 ) ;
}
}
static void F_276 ( struct V_28 * V_29 )
{
F_60 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_61 != V_29 )
break;
V_26 -> V_61 = NULL ;
}
}
static void F_277 ( struct V_28 * V_29 )
{
F_60 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_60 != V_29 )
break;
V_26 -> V_60 = NULL ;
}
}
static void F_278 ( struct V_28 * V_29 )
{
F_60 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_379 != V_29 )
break;
V_26 -> V_379 = NULL ;
}
}
static void F_279 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_61 == V_29 )
F_276 ( V_29 ) ;
if ( V_26 -> V_60 == V_29 )
F_277 ( V_29 ) ;
if ( V_26 -> V_379 == V_29 )
F_278 ( V_29 ) ;
}
static void
F_280 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_114 )
{
F_67 ( V_26 ) ;
F_252 ( V_29 , V_366 ) ;
F_256 ( V_26 , V_29 ) ;
F_93 ( V_26 , V_29 , V_114 ) ;
F_279 ( V_26 , V_29 ) ;
if ( V_29 != V_26 -> V_47 )
F_46 ( V_26 , V_29 ) ;
V_29 -> V_51 = 0 ;
F_218 ( V_26 , V_29 ) ;
if ( ! ( V_114 & V_116 ) )
V_29 -> V_43 -= V_26 -> F_36 ;
F_281 ( V_26 ) ;
F_223 ( V_29 ) ;
if ( ( V_114 & ( V_380 | V_381 ) ) == V_380 )
F_38 ( V_26 ) ;
}
static void
F_282 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
unsigned long V_382 , V_20 ;
struct V_28 * V_29 ;
T_3 V_44 ;
V_382 = F_59 ( V_26 , V_47 ) ;
V_20 = V_47 -> V_95 - V_47 -> V_383 ;
if ( V_20 > V_382 ) {
F_283 ( F_17 ( V_26 ) ) ;
F_279 ( V_26 , V_47 ) ;
return;
}
if ( V_20 < V_71 )
return;
V_29 = F_48 ( V_26 ) ;
V_44 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_44 < 0 )
return;
if ( V_44 > V_382 )
F_283 ( F_17 ( V_26 ) ) ;
}
static void
F_284 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_29 -> V_51 ) {
F_82 ( V_26 , V_29 ) ;
F_46 ( V_26 , V_29 ) ;
F_252 ( V_29 , V_366 ) ;
}
F_94 ( V_26 , V_29 ) ;
V_26 -> V_47 = V_29 ;
if ( F_78 () && F_17 ( V_26 ) -> V_72 . V_5 >= 2 * V_29 -> V_72 . V_5 ) {
F_69 ( V_29 -> V_93 . V_384 ,
F_70 ( ( T_2 ) F_80 ( V_29 -> V_93 . V_384 ) ,
V_29 -> V_95 - V_29 -> V_383 ) ) ;
}
V_29 -> V_383 = V_29 -> V_95 ;
}
static struct V_28 *
F_285 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
struct V_28 * V_59 = F_48 ( V_26 ) ;
struct V_28 * V_29 ;
if ( ! V_59 || ( V_47 && F_37 ( V_47 , V_59 ) ) )
V_59 = V_47 ;
V_29 = V_59 ;
if ( V_26 -> V_379 == V_29 ) {
struct V_28 * V_385 ;
if ( V_29 == V_47 ) {
V_385 = F_48 ( V_26 ) ;
} else {
V_385 = F_49 ( V_29 ) ;
if ( ! V_385 || ( V_47 && F_37 ( V_47 , V_385 ) ) )
V_385 = V_47 ;
}
if ( V_385 && F_286 ( V_385 , V_59 ) < 1 )
V_29 = V_385 ;
}
if ( V_26 -> V_61 && F_286 ( V_26 -> V_61 , V_59 ) < 1 )
V_29 = V_26 -> V_61 ;
if ( V_26 -> V_60 && F_286 ( V_26 -> V_60 , V_59 ) < 1 )
V_29 = V_26 -> V_60 ;
F_279 ( V_26 , V_29 ) ;
return V_29 ;
}
static void F_287 ( struct V_26 * V_26 , struct V_28 * V_349 )
{
if ( V_349 -> V_51 )
F_67 ( V_26 ) ;
F_288 ( V_26 ) ;
F_263 ( V_26 , V_349 ) ;
if ( V_349 -> V_51 ) {
F_77 ( V_26 , V_349 ) ;
F_43 ( V_26 , V_349 ) ;
F_252 ( V_349 , 0 ) ;
}
V_26 -> V_47 = NULL ;
}
static void
F_289 ( struct V_26 * V_26 , struct V_28 * V_47 , int V_386 )
{
F_67 ( V_26 ) ;
F_252 ( V_47 , V_366 ) ;
F_223 ( V_47 ) ;
#ifdef F_290
if ( V_386 ) {
F_283 ( F_17 ( V_26 ) ) ;
return;
}
if ( ! F_240 ( V_387 ) &&
F_291 ( & F_17 ( V_26 ) -> V_388 ) )
return;
#endif
if ( V_26 -> V_74 > 1 )
F_282 ( V_26 , V_47 ) ;
}
static inline bool F_292 ( void )
{
return F_293 ( & V_389 ) ;
}
void F_294 ( void )
{
F_295 ( & V_389 ) ;
}
void F_296 ( void )
{
F_297 ( & V_389 ) ;
}
static bool F_292 ( void )
{
return true ;
}
void F_294 ( void ) {}
void F_296 ( void ) {}
static inline T_2 F_298 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_299 ( void )
{
return ( T_2 ) V_390 * V_391 ;
}
void F_300 ( struct V_392 * V_393 )
{
T_2 V_91 ;
if ( V_393 -> V_394 == V_395 )
return;
V_91 = F_301 ( F_302 () ) ;
V_393 -> V_242 = V_393 -> V_394 ;
V_393 -> V_396 = V_91 + F_303 ( V_393 -> V_131 ) ;
}
static inline struct V_392 * F_304 ( struct V_326 * V_34 )
{
return & V_34 -> V_392 ;
}
static inline T_2 F_64 ( struct V_26 * V_26 )
{
if ( F_14 ( V_26 -> V_397 ) )
return V_26 -> V_398 - V_26 -> V_399 ;
return F_68 ( F_17 ( V_26 ) ) - V_26 -> V_399 ;
}
static int F_305 ( struct V_26 * V_26 )
{
struct V_326 * V_34 = V_26 -> V_34 ;
struct V_392 * V_393 = F_304 ( V_34 ) ;
T_2 V_400 = 0 , V_401 , V_402 ;
V_401 = F_299 () - V_26 -> V_403 ;
F_306 ( & V_393 -> V_259 ) ;
if ( V_393 -> V_394 == V_395 )
V_400 = V_401 ;
else {
F_307 ( V_393 ) ;
if ( V_393 -> V_242 > 0 ) {
V_400 = F_159 ( V_393 -> V_242 , V_401 ) ;
V_393 -> V_242 -= V_400 ;
V_393 -> V_404 = 0 ;
}
}
V_402 = V_393 -> V_396 ;
F_308 ( & V_393 -> V_259 ) ;
V_26 -> V_403 += V_400 ;
if ( ( T_3 ) ( V_402 - V_26 -> V_396 ) > 0 )
V_26 -> V_396 = V_402 ;
return V_26 -> V_403 > 0 ;
}
static void F_309 ( struct V_26 * V_26 )
{
struct V_392 * V_393 = F_304 ( V_26 -> V_34 ) ;
if ( F_12 ( ( T_3 ) ( F_79 ( F_17 ( V_26 ) ) - V_26 -> V_396 ) < 0 ) )
return;
if ( V_26 -> V_403 < 0 )
return;
if ( V_26 -> V_396 != V_393 -> V_396 ) {
V_26 -> V_396 += V_308 ;
} else {
V_26 -> V_403 = 0 ;
}
}
static void F_310 ( struct V_26 * V_26 , T_2 V_20 )
{
V_26 -> V_403 -= V_20 ;
F_309 ( V_26 ) ;
if ( F_12 ( V_26 -> V_403 > 0 ) )
return;
if ( ! F_305 ( V_26 ) && F_12 ( V_26 -> V_47 ) )
F_283 ( F_17 ( V_26 ) ) ;
}
static T_10
void F_75 ( struct V_26 * V_26 , T_2 V_20 )
{
if ( ! F_292 () || ! V_26 -> V_405 )
return;
F_310 ( V_26 , V_20 ) ;
}
static inline int F_311 ( struct V_26 * V_26 )
{
return F_292 () && V_26 -> V_406 ;
}
static inline int F_224 ( struct V_26 * V_26 )
{
return F_292 () && V_26 -> V_397 ;
}
static inline int F_312 ( struct V_326 * V_34 ,
int V_204 , int V_407 )
{
struct V_26 * V_408 , * V_409 ;
V_408 = V_34 -> V_26 [ V_204 ] ;
V_409 = V_34 -> V_26 [ V_407 ] ;
return F_224 ( V_408 ) ||
F_224 ( V_409 ) ;
}
static int F_313 ( struct V_326 * V_34 , void * V_410 )
{
struct V_25 * V_25 = V_410 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
V_26 -> V_397 -- ;
if ( ! V_26 -> V_397 ) {
V_26 -> V_399 += F_68 ( V_25 ) -
V_26 -> V_398 ;
}
return 0 ;
}
static int F_314 ( struct V_326 * V_34 , void * V_410 )
{
struct V_25 * V_25 = V_410 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_397 )
V_26 -> V_398 = F_68 ( V_25 ) ;
V_26 -> V_397 ++ ;
return 0 ;
}
static void F_315 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_392 * V_393 = F_304 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
long V_411 , V_412 = 1 ;
bool V_413 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
F_139 () ;
F_316 ( V_26 -> V_34 , F_314 , V_414 , ( void * ) V_25 ) ;
F_147 () ;
V_411 = V_26 -> V_415 ;
F_60 (se) {
struct V_26 * V_416 = F_23 ( V_29 ) ;
if ( ! V_29 -> V_51 )
break;
if ( V_412 )
F_280 ( V_416 , V_29 , V_116 ) ;
V_416 -> V_415 -= V_411 ;
if ( V_416 -> V_72 . V_5 )
V_412 = 0 ;
}
if ( ! V_29 )
F_317 ( V_25 , V_411 ) ;
V_26 -> V_406 = 1 ;
V_26 -> V_417 = F_79 ( V_25 ) ;
F_306 ( & V_393 -> V_259 ) ;
V_413 = F_318 ( & V_393 -> V_418 ) ;
F_28 ( & V_26 -> V_419 , & V_393 -> V_418 ) ;
if ( V_413 )
F_307 ( V_393 ) ;
F_308 ( & V_393 -> V_259 ) ;
}
void F_319 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_392 * V_393 = F_304 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
int V_420 = 1 ;
long V_411 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
V_26 -> V_406 = 0 ;
F_320 ( V_25 ) ;
F_306 ( & V_393 -> V_259 ) ;
V_393 -> V_421 += F_79 ( V_25 ) - V_26 -> V_417 ;
F_30 ( & V_26 -> V_419 ) ;
F_308 ( & V_393 -> V_259 ) ;
F_316 ( V_26 -> V_34 , V_414 , F_313 , ( void * ) V_25 ) ;
if ( ! V_26 -> V_72 . V_5 )
return;
V_411 = V_26 -> V_415 ;
F_60 (se) {
if ( V_29 -> V_51 )
V_420 = 0 ;
V_26 = F_23 ( V_29 ) ;
if ( V_420 )
F_274 ( V_26 , V_29 , V_115 ) ;
V_26 -> V_415 += V_411 ;
if ( F_311 ( V_26 ) )
break;
}
if ( ! V_29 )
F_321 ( V_25 , V_411 ) ;
if ( V_25 -> V_47 == V_25 -> V_404 && V_25 -> V_42 . V_74 )
F_283 ( V_25 ) ;
}
static T_2 F_322 ( struct V_392 * V_393 ,
T_2 V_422 , T_2 V_402 )
{
struct V_26 * V_26 ;
T_2 V_242 ;
T_2 V_423 = V_422 ;
F_139 () ;
F_323 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_369 V_370 ;
F_324 ( V_25 , & V_370 ) ;
if ( ! F_311 ( V_26 ) )
goto V_60;
V_242 = - V_26 -> V_403 + 1 ;
if ( V_242 > V_422 )
V_242 = V_422 ;
V_422 -= V_242 ;
V_26 -> V_403 += V_242 ;
V_26 -> V_396 = V_402 ;
if ( V_26 -> V_403 > 0 )
F_319 ( V_26 ) ;
V_60:
F_325 ( V_25 , & V_370 ) ;
if ( ! V_422 )
break;
}
F_147 () ;
return V_423 - V_422 ;
}
static int F_326 ( struct V_392 * V_393 , int V_424 )
{
T_2 V_242 , V_396 ;
int V_406 ;
if ( V_393 -> V_394 == V_395 )
goto V_425;
V_406 = ! F_318 ( & V_393 -> V_418 ) ;
V_393 -> V_426 += V_424 ;
if ( V_393 -> V_404 && ! V_406 )
goto V_425;
F_300 ( V_393 ) ;
if ( ! V_406 ) {
V_393 -> V_404 = 1 ;
return 0 ;
}
V_393 -> V_427 += V_424 ;
V_396 = V_393 -> V_396 ;
while ( V_406 && V_393 -> V_242 > 0 ) {
V_242 = V_393 -> V_242 ;
F_308 ( & V_393 -> V_259 ) ;
V_242 = F_322 ( V_393 , V_242 ,
V_396 ) ;
F_306 ( & V_393 -> V_259 ) ;
V_406 = ! F_318 ( & V_393 -> V_418 ) ;
V_393 -> V_242 -= F_159 ( V_242 , V_393 -> V_242 ) ;
}
V_393 -> V_404 = 0 ;
return 0 ;
V_425:
return 1 ;
}
static int F_327 ( struct V_392 * V_393 , T_2 V_428 )
{
struct V_429 * V_430 = & V_393 -> V_431 ;
T_2 V_422 ;
if ( F_328 ( V_430 ) )
return 1 ;
V_422 = F_303 ( F_329 ( V_430 ) ) ;
if ( V_422 < V_428 )
return 1 ;
return 0 ;
}
static void F_330 ( struct V_392 * V_393 )
{
T_2 V_432 = V_433 + V_434 ;
if ( F_327 ( V_393 , V_432 ) )
return;
F_331 ( & V_393 -> V_435 ,
F_332 ( V_433 ) ,
V_436 ) ;
}
static void F_333 ( struct V_26 * V_26 )
{
struct V_392 * V_393 = F_304 ( V_26 -> V_34 ) ;
T_3 V_437 = V_26 -> V_403 - V_438 ;
if ( V_437 <= 0 )
return;
F_306 ( & V_393 -> V_259 ) ;
if ( V_393 -> V_394 != V_395 &&
V_26 -> V_396 == V_393 -> V_396 ) {
V_393 -> V_242 += V_437 ;
if ( V_393 -> V_242 > F_299 () &&
! F_318 ( & V_393 -> V_418 ) )
F_330 ( V_393 ) ;
}
F_308 ( & V_393 -> V_259 ) ;
V_26 -> V_403 -= V_437 ;
}
static T_10 void F_281 ( struct V_26 * V_26 )
{
if ( ! F_292 () )
return;
if ( ! V_26 -> V_405 || V_26 -> V_74 )
return;
F_333 ( V_26 ) ;
}
static void F_334 ( struct V_392 * V_393 )
{
T_2 V_242 = 0 , V_75 = F_299 () ;
T_2 V_402 ;
F_306 ( & V_393 -> V_259 ) ;
if ( F_327 ( V_393 , V_434 ) ) {
F_308 ( & V_393 -> V_259 ) ;
return;
}
if ( V_393 -> V_394 != V_395 && V_393 -> V_242 > V_75 )
V_242 = V_393 -> V_242 ;
V_402 = V_393 -> V_396 ;
F_308 ( & V_393 -> V_259 ) ;
if ( ! V_242 )
return;
V_242 = F_322 ( V_393 , V_242 , V_402 ) ;
F_306 ( & V_393 -> V_259 ) ;
if ( V_402 == V_393 -> V_396 )
V_393 -> V_242 -= F_159 ( V_242 , V_393 -> V_242 ) ;
F_308 ( & V_393 -> V_259 ) ;
}
static void F_275 ( struct V_26 * V_26 )
{
if ( ! F_292 () )
return;
if ( ! V_26 -> V_405 || V_26 -> V_47 )
return;
if ( F_311 ( V_26 ) )
return;
F_75 ( V_26 , 0 ) ;
if ( V_26 -> V_403 <= 0 )
F_315 ( V_26 ) ;
}
static void F_335 ( struct V_326 * V_34 , int V_1 )
{
struct V_26 * V_439 , * V_26 ;
if ( ! F_292 () )
return;
if ( ! V_34 -> V_35 )
return;
V_26 = V_34 -> V_26 [ V_1 ] ;
V_439 = V_34 -> V_35 -> V_26 [ V_1 ] ;
V_26 -> V_397 = V_439 -> V_397 ;
V_26 -> V_398 = F_68 ( F_129 ( V_1 ) ) ;
}
static bool F_288 ( struct V_26 * V_26 )
{
if ( ! F_292 () )
return false ;
if ( F_12 ( ! V_26 -> V_405 || V_26 -> V_403 > 0 ) )
return false ;
if ( F_311 ( V_26 ) )
return true ;
F_315 ( V_26 ) ;
return true ;
}
static enum V_440 F_336 ( struct V_429 * V_441 )
{
struct V_392 * V_393 =
F_21 ( V_441 , struct V_392 , V_435 ) ;
F_334 ( V_393 ) ;
return V_442 ;
}
static enum V_440 F_337 ( struct V_429 * V_441 )
{
struct V_392 * V_393 =
F_21 ( V_441 , struct V_392 , V_431 ) ;
int V_424 ;
int V_404 = 0 ;
F_306 ( & V_393 -> V_259 ) ;
for (; ; ) {
V_424 = F_338 ( V_441 , V_393 -> V_131 ) ;
if ( ! V_424 )
break;
V_404 = F_326 ( V_393 , V_424 ) ;
}
if ( V_404 )
V_393 -> V_443 = 0 ;
F_308 ( & V_393 -> V_259 ) ;
return V_404 ? V_442 : V_444 ;
}
void F_339 ( struct V_392 * V_393 )
{
F_340 ( & V_393 -> V_259 ) ;
V_393 -> V_242 = 0 ;
V_393 -> V_394 = V_395 ;
V_393 -> V_131 = F_332 ( F_298 () ) ;
F_341 ( & V_393 -> V_418 ) ;
F_342 ( & V_393 -> V_431 , V_445 , V_446 ) ;
V_393 -> V_431 . V_447 = F_337 ;
F_342 ( & V_393 -> V_435 , V_445 , V_436 ) ;
V_393 -> V_435 . V_447 = F_336 ;
}
static void F_343 ( struct V_26 * V_26 )
{
V_26 -> V_405 = 0 ;
F_341 ( & V_26 -> V_419 ) ;
}
void F_307 ( struct V_392 * V_393 )
{
F_344 ( & V_393 -> V_259 ) ;
if ( ! V_393 -> V_443 ) {
V_393 -> V_443 = 1 ;
F_338 ( & V_393 -> V_431 , V_393 -> V_131 ) ;
F_345 ( & V_393 -> V_431 , V_446 ) ;
}
}
static void F_346 ( struct V_392 * V_393 )
{
if ( ! V_393 -> V_418 . V_60 )
return;
F_347 ( & V_393 -> V_431 ) ;
F_347 ( & V_393 -> V_435 ) ;
}
static void T_11 F_348 ( struct V_25 * V_25 )
{
struct V_326 * V_34 ;
F_344 ( & V_25 -> V_259 ) ;
F_139 () ;
F_323 (tg, &task_groups, list) {
struct V_392 * V_393 = & V_34 -> V_392 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
F_306 ( & V_393 -> V_259 ) ;
V_26 -> V_405 = V_393 -> V_394 != V_395 ;
F_308 ( & V_393 -> V_259 ) ;
}
F_147 () ;
}
static void T_11 F_349 ( struct V_25 * V_25 )
{
struct V_326 * V_34 ;
F_344 ( & V_25 -> V_259 ) ;
F_139 () ;
F_323 (tg, &task_groups, list) {
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_405 )
continue;
V_26 -> V_403 = 1 ;
V_26 -> V_405 = 0 ;
if ( F_311 ( V_26 ) )
F_319 ( V_26 ) ;
}
F_147 () ;
}
static inline T_2 F_64 ( struct V_26 * V_26 )
{
return F_68 ( F_17 ( V_26 ) ) ;
}
static void F_75 ( struct V_26 * V_26 , T_2 V_20 ) {}
static bool F_288 ( struct V_26 * V_26 ) { return false ; }
static void F_275 ( struct V_26 * V_26 ) {}
static inline void F_335 ( struct V_326 * V_34 , int V_1 ) {}
static T_10 void F_281 ( struct V_26 * V_26 ) {}
static inline int F_311 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_224 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_312 ( struct V_326 * V_34 ,
int V_204 , int V_407 )
{
return 0 ;
}
void F_339 ( struct V_392 * V_393 ) {}
static void F_343 ( struct V_26 * V_26 ) {}
static inline struct V_392 * F_304 ( struct V_326 * V_34 )
{
return NULL ;
}
static inline void F_346 ( struct V_392 * V_393 ) {}
static inline void F_348 ( struct V_25 * V_25 ) {}
static inline void F_349 ( struct V_25 * V_25 ) {}
static void F_350 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_19 ( F_34 ( V_30 ) != V_25 ) ;
if ( V_25 -> V_42 . V_415 > 1 ) {
T_2 V_75 = F_59 ( V_26 , V_29 ) ;
T_2 V_448 = V_29 -> V_95 - V_29 -> V_383 ;
T_3 V_44 = V_75 - V_448 ;
if ( V_44 < 0 ) {
if ( V_25 -> V_47 == V_30 )
F_283 ( V_25 ) ;
return;
}
F_351 ( V_25 , V_44 ) ;
}
}
static void F_352 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
if ( ! F_353 ( V_25 ) || V_47 -> V_88 != & V_89 )
return;
if ( F_23 ( & V_47 -> V_29 ) -> V_74 < V_69 )
F_350 ( V_25 , V_47 ) ;
}
static inline void
F_350 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_352 ( struct V_25 * V_25 )
{
}
static void
F_354 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_114 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_109 )
F_226 ( V_25 , V_449 ) ;
F_60 (se) {
if ( V_29 -> V_51 )
break;
V_26 = F_23 ( V_29 ) ;
F_274 ( V_26 , V_29 , V_114 ) ;
if ( F_311 ( V_26 ) )
break;
V_26 -> V_415 ++ ;
V_114 = V_115 ;
}
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_415 ++ ;
if ( F_311 ( V_26 ) )
break;
F_252 ( V_29 , V_366 ) ;
F_223 ( V_29 ) ;
}
if ( ! V_29 )
F_321 ( V_25 , 1 ) ;
F_352 ( V_25 ) ;
}
static void F_355 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_114 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
int V_450 = V_114 & V_116 ;
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
F_280 ( V_26 , V_29 , V_114 ) ;
if ( F_311 ( V_26 ) )
break;
V_26 -> V_415 -- ;
if ( V_26 -> V_72 . V_5 ) {
V_29 = F_32 ( V_29 ) ;
if ( V_450 && V_29 && ! F_224 ( V_26 ) )
F_356 ( V_29 ) ;
break;
}
V_114 |= V_116 ;
}
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_415 -- ;
if ( F_311 ( V_26 ) )
break;
F_252 ( V_29 , V_366 ) ;
F_223 ( V_29 ) ;
}
if ( ! V_29 )
F_317 ( V_25 , 1 ) ;
F_352 ( V_25 ) ;
}
static unsigned long
F_357 ( unsigned long V_72 , unsigned long V_451 , int V_452 )
{
int V_453 = 0 ;
if ( ! V_451 )
return V_72 ;
if ( V_451 >= V_454 [ V_452 ] )
return 0 ;
if ( V_452 == 1 )
return V_72 >> V_451 ;
while ( V_451 ) {
if ( V_451 % 2 )
V_72 = ( V_72 * V_455 [ V_452 ] [ V_453 ] ) >> V_456 ;
V_451 >>= 1 ;
V_453 ++ ;
}
return V_72 ;
}
static void F_358 ( struct V_25 * V_457 , unsigned long V_458 ,
unsigned long V_459 )
{
unsigned long T_11 V_460 = V_457 -> V_461 [ 0 ] ;
int V_273 , V_462 ;
V_457 -> V_463 ++ ;
V_457 -> V_461 [ 0 ] = V_458 ;
for ( V_273 = 1 , V_462 = 2 ; V_273 < V_464 ; V_273 ++ , V_462 += V_462 ) {
unsigned long V_465 , V_466 ;
V_465 = V_457 -> V_461 [ V_273 ] ;
#ifdef F_359
V_465 = F_357 ( V_465 , V_459 - 1 , V_273 ) ;
if ( V_460 ) {
V_465 -= F_357 ( V_460 , V_459 - 1 , V_273 ) ;
V_465 += V_460 ;
}
#endif
V_466 = V_458 ;
if ( V_466 > V_465 )
V_466 += V_462 - 1 ;
V_457 -> V_461 [ V_273 ] = ( V_465 * ( V_462 - 1 ) + V_466 ) >> V_273 ;
}
F_360 ( V_457 ) ;
}
static unsigned long F_130 ( struct V_25 * V_25 )
{
return F_260 ( & V_25 -> V_42 ) ;
}
static void F_361 ( struct V_25 * V_457 ,
unsigned long V_467 ,
unsigned long V_72 )
{
unsigned long V_459 ;
V_459 = V_467 - V_457 -> V_468 ;
if ( V_459 ) {
V_457 -> V_468 = V_467 ;
F_358 ( V_457 , V_72 , V_459 ) ;
}
}
static void F_362 ( struct V_25 * V_457 )
{
if ( F_130 ( V_457 ) )
return;
F_361 ( V_457 , F_99 ( V_227 ) , 0 ) ;
}
void F_363 ( void )
{
struct V_25 * V_457 = V_457 () ;
V_457 -> V_461 [ 0 ] = F_130 ( V_457 ) ;
}
void F_364 ( void )
{
unsigned long V_467 = F_99 ( V_227 ) ;
struct V_25 * V_457 = V_457 () ;
unsigned long V_72 ;
struct V_369 V_370 ;
if ( V_467 == V_457 -> V_468 )
return;
V_72 = F_130 ( V_457 ) ;
F_324 ( V_457 , & V_370 ) ;
F_320 ( V_457 ) ;
F_361 ( V_457 , V_467 , V_72 ) ;
F_325 ( V_457 , & V_370 ) ;
}
static inline void F_361 ( struct V_25 * V_457 ,
unsigned long V_467 ,
unsigned long V_72 ) { }
static void F_365 ( struct V_25 * V_457 , unsigned long V_72 )
{
#ifdef F_359
V_457 -> V_468 = F_99 ( V_227 ) ;
#endif
F_358 ( V_457 , V_72 , 1 ) ;
}
void F_366 ( struct V_25 * V_457 )
{
unsigned long V_72 = F_130 ( V_457 ) ;
if ( F_367 () )
F_361 ( V_457 , F_99 ( V_227 ) , V_72 ) ;
else
F_365 ( V_457 , V_72 ) ;
}
static unsigned long F_368 ( int V_1 , int type )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
unsigned long V_469 = F_130 ( V_25 ) ;
if ( type == 0 || ! F_240 ( V_470 ) )
return V_469 ;
return F_159 ( V_25 -> V_461 [ type - 1 ] , V_469 ) ;
}
static unsigned long F_369 ( int V_1 , int type )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
unsigned long V_469 = F_130 ( V_25 ) ;
if ( type == 0 || ! F_240 ( V_470 ) )
return V_469 ;
return F_70 ( V_25 -> V_461 [ type - 1 ] , V_469 ) ;
}
static unsigned long F_131 ( int V_1 )
{
return F_129 ( V_1 ) -> V_471 ;
}
static unsigned long F_370 ( int V_1 )
{
return F_129 ( V_1 ) -> V_472 ;
}
static unsigned long F_371 ( int V_1 )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
unsigned long V_74 = F_99 ( V_25 -> V_42 . V_415 ) ;
unsigned long V_81 = F_130 ( V_25 ) ;
if ( V_74 )
return V_81 / V_74 ;
return 0 ;
}
static void F_372 ( struct V_27 * V_30 )
{
if ( F_197 ( V_227 , V_175 -> V_473 + V_225 ) ) {
V_175 -> V_474 >>= 1 ;
V_175 -> V_473 = V_227 ;
}
if ( V_175 -> V_475 != V_30 ) {
V_175 -> V_475 = V_30 ;
V_175 -> V_474 ++ ;
}
}
static int F_373 ( struct V_27 * V_30 )
{
unsigned int V_476 = V_175 -> V_474 ;
unsigned int V_477 = V_30 -> V_474 ;
int V_10 = F_374 ( V_478 ) ;
if ( V_476 < V_477 )
F_137 ( V_476 , V_477 ) ;
if ( V_477 < V_10 || V_476 < V_477 * V_10 )
return 0 ;
return 1 ;
}
static bool
F_375 ( struct V_215 * V_216 , struct V_27 * V_30 ,
int V_479 , int V_480 , int V_481 )
{
if ( F_376 ( V_479 ) )
return true ;
if ( V_481 && F_129 ( V_479 ) -> V_74 == 1 )
return true ;
return false ;
}
static bool
F_377 ( struct V_215 * V_216 , struct V_27 * V_30 ,
int V_479 , int V_480 , int V_481 )
{
T_3 V_482 , V_483 ;
unsigned long V_484 ;
V_482 = F_369 ( V_479 , V_216 -> V_485 ) ;
V_483 = F_368 ( V_480 , V_216 -> V_485 ) ;
if ( V_481 ) {
unsigned long V_486 = F_143 ( V_175 ) ;
if ( V_486 > V_482 )
return true ;
V_482 -= V_486 ;
}
V_484 = F_143 ( V_30 ) ;
V_482 += V_484 ;
if ( F_240 ( V_487 ) )
V_482 *= 100 ;
V_482 *= F_131 ( V_480 ) ;
V_483 -= V_484 ;
if ( F_240 ( V_487 ) )
V_483 *= 100 + ( V_216 -> V_200 - 100 ) / 2 ;
V_483 *= F_131 ( V_479 ) ;
return V_482 <= V_483 ;
}
static int F_378 ( struct V_215 * V_216 , struct V_27 * V_30 ,
int V_480 , int V_481 )
{
int V_479 = F_302 () ;
bool V_488 = false ;
if ( F_240 ( V_489 ) && ! V_488 )
V_488 = F_375 ( V_216 , V_30 , V_479 , V_480 , V_481 ) ;
if ( F_240 ( V_490 ) && ! V_488 )
V_488 = F_377 ( V_216 , V_30 , V_479 , V_480 , V_481 ) ;
F_84 ( V_30 -> V_29 . V_93 . V_491 ) ;
if ( V_488 ) {
F_84 ( V_216 -> V_492 ) ;
F_84 ( V_30 -> V_29 . V_93 . V_493 ) ;
}
return V_488 ;
}
static unsigned long F_379 ( int V_1 , struct V_27 * V_30 )
{
return F_370 ( V_1 ) - F_380 ( V_1 , V_30 ) ;
}
static struct V_494 *
F_381 ( struct V_215 * V_216 , struct V_27 * V_30 ,
int V_479 , int V_495 )
{
struct V_494 * V_496 = NULL , * V_152 = V_216 -> V_497 ;
struct V_494 * V_498 = NULL ;
unsigned long V_499 = V_500 , V_501 = 0 ;
unsigned long V_502 = V_500 , V_503 = 0 ;
unsigned long V_504 = 0 , V_505 = 0 ;
int V_506 = V_216 -> V_507 ;
int V_508 = 100 + ( V_216 -> V_200 - 100 ) / 2 ;
unsigned long V_509 = F_13 ( V_73 ) *
( V_216 -> V_200 - 100 ) / 100 ;
if ( V_495 & V_510 )
V_506 = V_216 -> V_485 ;
do {
unsigned long V_72 , V_511 , V_512 ;
unsigned long V_513 , V_514 ;
int V_515 ;
int V_273 ;
if ( ! F_382 ( F_383 ( V_152 ) ,
& V_30 -> V_210 ) )
continue;
V_515 = F_142 ( V_479 ,
F_383 ( V_152 ) ) ;
V_511 = 0 ;
V_512 = 0 ;
V_514 = 0 ;
F_128 (i, sched_group_span(group)) {
if ( V_515 )
V_72 = F_368 ( V_273 , V_506 ) ;
else
V_72 = F_369 ( V_273 , V_506 ) ;
V_512 += V_72 ;
V_511 += F_261 ( & F_129 ( V_273 ) -> V_42 ) ;
V_513 = F_379 ( V_273 , V_30 ) ;
if ( V_513 > V_514 )
V_514 = V_513 ;
}
V_511 = ( V_511 * V_87 ) /
V_152 -> V_516 -> V_180 ;
V_512 = ( V_512 * V_87 ) /
V_152 -> V_516 -> V_180 ;
if ( V_515 ) {
V_501 = V_512 ;
V_503 = V_511 ;
V_505 = V_514 ;
} else {
if ( V_499 > ( V_512 + V_509 ) ) {
V_499 = V_512 ;
V_502 = V_511 ;
V_496 = V_152 ;
} else if ( ( V_512 < ( V_499 + V_509 ) ) &&
( 100 * V_502 > V_508 * V_511 ) ) {
V_502 = V_511 ;
V_496 = V_152 ;
}
if ( V_504 < V_514 ) {
V_504 = V_514 ;
V_498 = V_152 ;
}
}
} while ( V_152 = V_152 -> V_60 , V_152 != V_216 -> V_497 );
if ( V_495 & V_517 )
goto V_518;
if ( V_505 > F_384 ( V_30 ) / 2 &&
V_508 * V_505 > 100 * V_504 )
return NULL ;
if ( V_504 > F_384 ( V_30 ) / 2 )
return V_498 ;
V_518:
if ( ! V_496 )
return NULL ;
if ( V_499 > ( V_501 + V_509 ) )
return NULL ;
if ( ( V_501 < ( V_499 + V_509 ) ) &&
( 100 * V_503 < V_508 * V_502 ) )
return NULL ;
return V_496 ;
}
static int
F_385 ( struct V_494 * V_152 , struct V_27 * V_30 , int V_479 )
{
unsigned long V_72 , V_519 = V_500 ;
unsigned int V_520 = V_521 ;
T_2 V_522 = 0 ;
int V_523 = V_479 ;
int V_524 = - 1 ;
int V_273 ;
if ( V_152 -> F_119 == 1 )
return F_386 ( F_383 ( V_152 ) ) ;
F_387 (i, sched_group_span(group), &p->cpus_allowed) {
if ( F_376 ( V_273 ) ) {
struct V_25 * V_25 = F_129 ( V_273 ) ;
struct V_525 * V_404 = F_388 ( V_25 ) ;
if ( V_404 && V_404 -> V_526 < V_520 ) {
V_520 = V_404 -> V_526 ;
V_522 = V_25 -> V_527 ;
V_524 = V_273 ;
} else if ( ( ! V_404 || V_404 -> V_526 == V_520 ) &&
V_25 -> V_527 > V_522 ) {
V_522 = V_25 -> V_527 ;
V_524 = V_273 ;
}
} else if ( V_524 == - 1 ) {
V_72 = F_130 ( F_129 ( V_273 ) ) ;
if ( V_72 < V_519 || ( V_72 == V_519 && V_273 == V_479 ) ) {
V_519 = V_72 ;
V_523 = V_273 ;
}
}
}
return V_524 != - 1 ? V_524 : V_523 ;
}
static inline void F_389 ( int V_1 , int V_331 )
{
struct V_528 * V_529 ;
V_529 = F_152 ( F_153 ( V_530 , V_1 ) ) ;
if ( V_529 )
F_199 ( V_529 -> V_531 , V_331 ) ;
}
static inline bool F_390 ( int V_1 , bool V_532 )
{
struct V_528 * V_529 ;
V_529 = F_152 ( F_153 ( V_530 , V_1 ) ) ;
if ( V_529 )
return F_99 ( V_529 -> V_531 ) ;
return V_532 ;
}
void F_391 ( struct V_25 * V_25 )
{
int V_533 = F_26 ( V_25 ) ;
int V_1 ;
F_139 () ;
if ( F_390 ( V_533 , true ) )
goto V_209;
F_128 (cpu, cpu_smt_mask(core)) {
if ( V_1 == V_533 )
continue;
if ( ! F_376 ( V_1 ) )
goto V_209;
}
F_389 ( V_533 , 1 ) ;
V_209:
F_147 () ;
}
static int F_392 ( struct V_27 * V_30 , struct V_215 * V_216 , int V_534 )
{
struct V_535 * V_9 = F_393 ( V_536 ) ;
int V_533 , V_1 ;
if ( ! F_196 ( & V_537 ) )
return - 1 ;
if ( ! F_390 ( V_534 , false ) )
return - 1 ;
F_394 ( V_9 , F_395 ( V_216 ) , & V_30 -> V_210 ) ;
F_396 (core, cpus, target) {
bool V_404 = true ;
F_128 (cpu, cpu_smt_mask(core)) {
F_397 ( V_1 , V_9 ) ;
if ( ! F_376 ( V_1 ) )
V_404 = false ;
}
if ( V_404 )
return V_533 ;
}
F_389 ( V_534 , 0 ) ;
return - 1 ;
}
static int F_398 ( struct V_27 * V_30 , struct V_215 * V_216 , int V_534 )
{
int V_1 ;
if ( ! F_196 ( & V_537 ) )
return - 1 ;
F_128 (cpu, cpu_smt_mask(target)) {
if ( ! F_142 ( V_1 , & V_30 -> V_210 ) )
continue;
if ( F_376 ( V_1 ) )
return V_1 ;
}
return - 1 ;
}
static inline int F_392 ( struct V_27 * V_30 , struct V_215 * V_216 , int V_534 )
{
return - 1 ;
}
static inline int F_398 ( struct V_27 * V_30 , struct V_215 * V_216 , int V_534 )
{
return - 1 ;
}
static int F_399 ( struct V_27 * V_30 , struct V_215 * V_216 , int V_534 )
{
struct V_215 * V_538 ;
T_2 V_539 , V_540 ;
T_2 time , V_541 ;
T_3 V_44 ;
int V_1 , V_542 = V_543 ;
V_538 = F_152 ( * F_400 ( & V_544 ) ) ;
if ( ! V_538 )
return - 1 ;
V_540 = V_457 () -> V_540 / 512 ;
V_539 = V_538 -> V_545 + 1 ;
if ( F_240 ( V_546 ) && V_540 < V_539 )
return - 1 ;
if ( F_240 ( V_547 ) ) {
T_2 V_548 = V_216 -> V_549 * V_540 ;
if ( V_548 > 4 * V_539 )
V_542 = F_234 ( V_548 , V_539 ) ;
else
V_542 = 4 ;
}
time = F_401 () ;
F_396 (cpu, sched_domain_span(sd), target) {
if ( ! -- V_542 )
return - 1 ;
if ( ! F_142 ( V_1 , & V_30 -> V_210 ) )
continue;
if ( F_376 ( V_1 ) )
break;
}
time = F_401 () - time ;
V_541 = V_538 -> V_545 ;
V_44 = ( T_3 ) ( time - V_541 ) / 8 ;
V_538 -> V_545 += V_44 ;
return V_1 ;
}
static int F_145 ( struct V_27 * V_30 , int V_349 , int V_534 )
{
struct V_215 * V_216 ;
int V_273 ;
if ( F_376 ( V_534 ) )
return V_534 ;
if ( V_349 != V_534 && F_402 ( V_349 , V_534 ) && F_376 ( V_349 ) )
return V_349 ;
V_216 = F_152 ( F_153 ( V_544 , V_534 ) ) ;
if ( ! V_216 )
return V_534 ;
V_273 = F_392 ( V_30 , V_216 , V_534 ) ;
if ( ( unsigned ) V_273 < V_550 )
return V_273 ;
V_273 = F_399 ( V_30 , V_216 , V_534 ) ;
if ( ( unsigned ) V_273 < V_550 )
return V_273 ;
V_273 = F_398 ( V_30 , V_216 , V_534 ) ;
if ( ( unsigned ) V_273 < V_550 )
return V_273 ;
return V_534 ;
}
static int F_403 ( int V_1 )
{
unsigned long V_551 = F_129 ( V_1 ) -> V_42 . V_78 . V_84 ;
unsigned long V_180 = F_370 ( V_1 ) ;
return ( V_551 >= V_180 ) ? V_180 : V_551 ;
}
static inline int F_384 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_78 . V_84 ;
}
static int F_380 ( int V_1 , struct V_27 * V_30 )
{
unsigned long V_551 , V_180 ;
if ( V_1 != F_151 ( V_30 ) || ! V_30 -> V_29 . V_78 . V_79 )
return F_403 ( V_1 ) ;
V_180 = F_370 ( V_1 ) ;
V_551 = F_100 ( long , F_129 ( V_1 ) -> V_42 . V_78 . V_84 - F_384 ( V_30 ) , 0 ) ;
return ( V_551 >= V_180 ) ? V_180 : V_551 ;
}
static int F_404 ( struct V_27 * V_30 , int V_1 , int V_480 )
{
long V_552 , V_553 ;
V_552 = F_159 ( F_370 ( V_480 ) , F_370 ( V_1 ) ) ;
V_553 = F_129 ( V_1 ) -> V_554 -> V_555 ;
if ( V_553 - V_552 < V_553 > > 3 )
return 0 ;
F_258 ( & V_30 -> V_29 ) ;
return V_552 * 1024 < F_384 ( V_30 ) * V_556 ;
}
static int
F_405 ( struct V_27 * V_30 , int V_480 , int V_495 , int V_557 )
{
struct V_215 * V_558 , * V_559 = NULL , * V_216 = NULL ;
int V_1 = F_302 () ;
int V_560 = V_480 ;
int V_561 = 0 ;
int V_481 = V_557 & V_562 ;
if ( V_495 & V_510 ) {
F_372 ( V_30 ) ;
V_561 = ! F_373 ( V_30 ) && ! F_404 ( V_30 , V_1 , V_480 )
&& F_142 ( V_1 , & V_30 -> V_210 ) ;
}
F_139 () ;
F_406 (cpu, tmp) {
if ( ! ( V_558 -> V_114 & V_563 ) )
break;
if ( V_561 && ( V_558 -> V_114 & V_564 ) &&
F_142 ( V_480 , F_395 ( V_558 ) ) ) {
V_559 = V_558 ;
break;
}
if ( V_558 -> V_114 & V_495 )
V_216 = V_558 ;
else if ( ! V_561 )
break;
}
if ( V_559 ) {
V_216 = NULL ;
if ( V_1 == V_480 )
goto V_565;
if ( F_378 ( V_559 , V_30 , V_480 , V_481 ) )
V_560 = V_1 ;
}
if ( ! V_216 ) {
V_565:
if ( V_495 & V_510 )
V_560 = F_145 ( V_30 , V_480 , V_560 ) ;
} else while ( V_216 ) {
struct V_494 * V_152 ;
int V_5 ;
if ( ! ( V_216 -> V_114 & V_495 ) ) {
V_216 = V_216 -> V_566 ;
continue;
}
V_152 = F_381 ( V_216 , V_30 , V_1 , V_495 ) ;
if ( ! V_152 ) {
V_216 = V_216 -> V_566 ;
continue;
}
V_560 = F_385 ( V_152 , V_30 , V_1 ) ;
if ( V_560 == - 1 || V_560 == V_1 ) {
V_216 = V_216 -> V_566 ;
continue;
}
V_1 = V_560 ;
V_5 = V_216 -> V_549 ;
V_216 = NULL ;
F_406 (cpu, tmp) {
if ( V_5 <= V_558 -> V_549 )
break;
if ( V_558 -> V_114 & V_495 )
V_216 = V_558 ;
}
}
F_147 () ;
return V_560 ;
}
static void F_407 ( struct V_27 * V_30 )
{
if ( V_30 -> V_117 == V_567 ) {
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 F_36 ;
#ifndef F_41
T_2 V_53 ;
do {
V_53 = V_26 -> V_53 ;
F_241 () ;
F_36 = V_26 -> F_36 ;
} while ( F_36 != V_53 );
#else
F_36 = V_26 -> F_36 ;
#endif
V_29 -> V_43 -= F_36 ;
}
F_259 ( & V_30 -> V_29 ) ;
V_30 -> V_29 . V_78 . V_79 = 0 ;
V_30 -> V_29 . V_92 = 0 ;
}
static void F_408 ( struct V_27 * V_30 )
{
F_259 ( & V_30 -> V_29 ) ;
}
static unsigned long
F_409 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
unsigned long V_568 = V_569 ;
return F_57 ( V_568 , V_29 ) ;
}
static int
F_286 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
T_3 V_568 , V_570 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_570 <= 0 )
return - 1 ;
V_568 = F_409 ( V_47 , V_29 ) ;
if ( V_570 > V_568 )
return 1 ;
return 0 ;
}
static void F_410 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_571 == V_572 ) )
return;
F_60 (se) {
if ( F_19 ( ! V_29 -> V_51 ) )
return;
F_23 ( V_29 ) -> V_61 = V_29 ;
}
}
static void F_356 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_571 == V_572 ) )
return;
F_60 (se) {
if ( F_19 ( ! V_29 -> V_51 ) )
return;
F_23 ( V_29 ) -> V_60 = V_29 ;
}
}
static void F_411 ( struct V_28 * V_29 )
{
F_60 (se)
F_23 ( V_29 ) -> V_379 = V_29 ;
}
static void F_412 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_557 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_28 * V_29 = & V_47 -> V_29 , * V_38 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
int V_462 = V_26 -> V_74 >= V_69 ;
int V_573 = 0 ;
if ( F_14 ( V_29 == V_38 ) )
return;
if ( F_14 ( F_224 ( F_23 ( V_38 ) ) ) )
return;
if ( F_240 ( V_574 ) && V_462 && ! ( V_557 & V_575 ) ) {
F_356 ( V_38 ) ;
V_573 = 1 ;
}
if ( F_413 ( V_47 ) )
return;
if ( F_14 ( V_47 -> V_571 == V_572 ) &&
F_12 ( V_30 -> V_571 != V_572 ) )
goto V_576;
if ( F_14 ( V_30 -> V_571 != V_577 ) || ! F_240 ( V_578 ) )
return;
F_33 ( & V_29 , & V_38 ) ;
F_67 ( F_23 ( V_29 ) ) ;
F_186 ( ! V_38 ) ;
if ( F_286 ( V_29 , V_38 ) == 1 ) {
if ( ! V_573 )
F_356 ( V_38 ) ;
goto V_576;
}
return;
V_576:
F_283 ( V_25 ) ;
if ( F_14 ( ! V_29 -> V_51 || V_47 == V_25 -> V_404 ) )
return;
if ( F_240 ( V_579 ) && V_462 && F_20 ( V_29 ) )
F_410 ( V_29 ) ;
}
static struct V_27 *
F_414 ( struct V_25 * V_25 , struct V_27 * V_349 , struct V_369 * V_370 )
{
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_28 * V_29 ;
struct V_27 * V_30 ;
int V_580 ;
V_581:
if ( ! V_26 -> V_74 )
goto V_404;
#ifdef F_415
if ( V_349 -> V_88 != & V_89 )
goto V_582;
do {
struct V_28 * V_47 = V_26 -> V_47 ;
if ( V_47 ) {
if ( V_47 -> V_51 )
F_67 ( V_26 ) ;
else
V_47 = NULL ;
if ( F_14 ( F_288 ( V_26 ) ) ) {
V_26 = & V_25 -> V_42 ;
if ( ! V_26 -> V_74 )
goto V_404;
goto V_582;
}
}
V_29 = F_285 ( V_26 , V_47 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( V_349 != V_30 ) {
struct V_28 * V_38 = & V_349 -> V_29 ;
while ( ! ( V_26 = F_31 ( V_29 , V_38 ) ) ) {
int V_39 = V_29 -> V_41 ;
int V_40 = V_38 -> V_41 ;
if ( V_39 <= V_40 ) {
F_287 ( F_23 ( V_38 ) , V_38 ) ;
V_38 = F_32 ( V_38 ) ;
}
if ( V_39 >= V_40 ) {
F_284 ( F_23 ( V_29 ) , V_29 ) ;
V_29 = F_32 ( V_29 ) ;
}
}
F_287 ( V_26 , V_38 ) ;
F_284 ( V_26 , V_29 ) ;
}
if ( F_353 ( V_25 ) )
F_350 ( V_25 , V_30 ) ;
return V_30 ;
V_582:
#endif
F_416 ( V_25 , V_349 ) ;
do {
V_29 = F_285 ( V_26 , NULL ) ;
F_284 ( V_26 , V_29 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( F_353 ( V_25 ) )
F_350 ( V_25 , V_30 ) ;
return V_30 ;
V_404:
V_580 = F_262 ( V_25 , V_370 ) ;
if ( V_580 < 0 )
return V_583 ;
if ( V_580 > 0 )
goto V_581;
return NULL ;
}
static void F_417 ( struct V_25 * V_25 , struct V_27 * V_349 )
{
struct V_28 * V_29 = & V_349 -> V_29 ;
struct V_26 * V_26 ;
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
F_287 ( V_26 , V_29 ) ;
}
}
static void F_418 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
struct V_28 * V_29 = & V_47 -> V_29 ;
if ( F_14 ( V_25 -> V_74 == 1 ) )
return;
F_279 ( V_26 , V_29 ) ;
if ( V_47 -> V_571 != V_584 ) {
F_320 ( V_25 ) ;
F_67 ( V_26 ) ;
F_419 ( V_25 , true ) ;
}
F_411 ( V_29 ) ;
}
static bool F_420 ( struct V_25 * V_25 , struct V_27 * V_30 , bool V_576 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( ! V_29 -> V_51 || F_224 ( F_23 ( V_29 ) ) )
return false ;
F_356 ( V_29 ) ;
F_418 ( V_25 ) ;
return true ;
}
static int F_421 ( struct V_27 * V_30 , struct V_585 * V_185 )
{
T_3 V_44 ;
F_344 ( & V_185 -> V_203 -> V_259 ) ;
if ( V_30 -> V_88 != & V_89 )
return 0 ;
if ( F_14 ( V_30 -> V_571 == V_572 ) )
return 0 ;
if ( F_240 ( V_586 ) && V_185 -> V_205 -> V_74 &&
( & V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_60 ||
& V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_61 ) )
return 1 ;
if ( V_587 == - 1 )
return 1 ;
if ( V_587 == 0 )
return 0 ;
V_44 = F_68 ( V_185 -> V_203 ) - V_30 -> V_29 . V_92 ;
return V_44 < ( T_3 ) V_587 ;
}
static int F_422 ( struct V_27 * V_30 , struct V_585 * V_185 )
{
struct V_132 * V_132 = F_152 ( V_30 -> V_132 ) ;
unsigned long V_588 , V_589 ;
int V_170 , V_172 ;
if ( ! F_196 ( & V_287 ) )
return - 1 ;
if ( ! V_30 -> V_149 || ! ( V_185 -> V_216 -> V_114 & V_590 ) )
return - 1 ;
V_170 = F_121 ( V_185 -> V_204 ) ;
V_172 = F_121 ( V_185 -> V_171 ) ;
if ( V_170 == V_172 )
return - 1 ;
if ( V_170 == V_30 -> V_140 ) {
if ( V_185 -> V_203 -> V_74 > V_185 -> V_203 -> V_141 )
return 1 ;
else
return - 1 ;
}
if ( V_172 == V_30 -> V_140 )
return 0 ;
if ( V_185 -> V_404 != V_591 )
return - 1 ;
if ( V_132 ) {
V_588 = F_112 ( V_30 , V_170 ) ;
V_589 = F_112 ( V_30 , V_172 ) ;
} else {
V_588 = F_111 ( V_30 , V_170 ) ;
V_589 = F_111 ( V_30 , V_172 ) ;
}
return V_589 < V_588 ;
}
static inline int F_422 ( struct V_27 * V_30 ,
struct V_585 * V_185 )
{
return - 1 ;
}
static
int F_423 ( struct V_27 * V_30 , struct V_585 * V_185 )
{
int V_592 ;
F_344 ( & V_185 -> V_203 -> V_259 ) ;
if ( F_312 ( V_326 ( V_30 ) , V_185 -> V_204 , V_185 -> V_171 ) )
return 0 ;
if ( ! F_142 ( V_185 -> V_171 , & V_30 -> V_210 ) ) {
int V_1 ;
F_84 ( V_30 -> V_29 . V_93 . V_593 ) ;
V_185 -> V_114 |= V_594 ;
if ( V_185 -> V_404 == V_595 || ( V_185 -> V_114 & V_596 ) )
return 0 ;
F_387 (cpu, env->dst_grpmask, env->cpus) {
if ( F_142 ( V_1 , & V_30 -> V_210 ) ) {
V_185 -> V_114 |= V_596 ;
V_185 -> V_597 = V_1 ;
break;
}
}
return 0 ;
}
V_185 -> V_114 &= ~ V_598 ;
if ( F_424 ( V_185 -> V_203 , V_30 ) ) {
F_84 ( V_30 -> V_29 . V_93 . V_599 ) ;
return 0 ;
}
V_592 = F_422 ( V_30 , V_185 ) ;
if ( V_592 == - 1 )
V_592 = F_421 ( V_30 , V_185 ) ;
if ( V_592 <= 0 ||
V_185 -> V_216 -> V_600 > V_185 -> V_216 -> V_601 ) {
if ( V_592 == 1 ) {
F_84 ( V_185 -> V_216 -> V_602 [ V_185 -> V_404 ] ) ;
F_84 ( V_30 -> V_29 . V_93 . V_603 ) ;
}
return 1 ;
}
F_84 ( V_30 -> V_29 . V_93 . V_604 ) ;
return 0 ;
}
static void F_425 ( struct V_27 * V_30 , struct V_585 * V_185 )
{
F_344 ( & V_185 -> V_203 -> V_259 ) ;
V_30 -> V_51 = V_605 ;
F_426 ( V_185 -> V_203 , V_30 , V_606 ) ;
F_427 ( V_30 , V_185 -> V_171 ) ;
}
static struct V_27 * F_428 ( struct V_585 * V_185 )
{
struct V_27 * V_30 , * V_332 ;
F_344 ( & V_185 -> V_203 -> V_259 ) ;
F_429 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_423 ( V_30 , V_185 ) )
continue;
F_425 ( V_30 , V_185 ) ;
F_84 ( V_185 -> V_216 -> V_607 [ V_185 -> V_404 ] ) ;
return V_30 ;
}
return NULL ;
}
static int F_430 ( struct V_585 * V_185 )
{
struct V_608 * V_609 = & V_185 -> V_203 -> V_325 ;
struct V_27 * V_30 ;
unsigned long V_72 ;
int V_610 = 0 ;
F_344 ( & V_185 -> V_203 -> V_259 ) ;
if ( V_185 -> V_509 <= 0 )
return 0 ;
while ( ! F_318 ( V_609 ) ) {
if ( V_185 -> V_404 != V_591 && V_185 -> V_203 -> V_74 <= 1 )
break;
V_30 = F_431 ( V_609 , struct V_27 , V_29 . V_324 ) ;
V_185 -> V_611 ++ ;
if ( V_185 -> V_611 > V_185 -> V_612 )
break;
if ( V_185 -> V_611 > V_185 -> V_613 ) {
V_185 -> V_613 += V_614 ;
V_185 -> V_114 |= V_615 ;
break;
}
if ( ! F_423 ( V_30 , V_185 ) )
goto V_60;
V_72 = F_143 ( V_30 ) ;
if ( F_240 ( V_616 ) && V_72 < 16 && ! V_185 -> V_216 -> V_600 )
goto V_60;
if ( ( V_72 / 2 ) > V_185 -> V_509 )
goto V_60;
F_425 ( V_30 , V_185 ) ;
F_217 ( & V_30 -> V_29 . V_324 , & V_185 -> V_609 ) ;
V_610 ++ ;
V_185 -> V_509 -= V_72 ;
#ifdef F_432
if ( V_185 -> V_404 == V_595 )
break;
#endif
if ( V_185 -> V_509 <= 0 )
break;
continue;
V_60:
F_433 ( & V_30 -> V_29 . V_324 , V_609 ) ;
}
F_71 ( V_185 -> V_216 -> V_607 [ V_185 -> V_404 ] , V_610 ) ;
return V_610 ;
}
static void F_434 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_344 ( & V_25 -> V_259 ) ;
F_186 ( F_34 ( V_30 ) != V_25 ) ;
F_435 ( V_25 , V_30 , V_617 ) ;
V_30 -> V_51 = V_618 ;
F_436 ( V_25 , V_30 , 0 ) ;
}
static void F_437 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_369 V_370 ;
F_324 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
F_434 ( V_25 , V_30 ) ;
F_325 ( V_25 , & V_370 ) ;
}
static void F_438 ( struct V_585 * V_185 )
{
struct V_608 * V_609 = & V_185 -> V_609 ;
struct V_27 * V_30 ;
struct V_369 V_370 ;
F_324 ( V_185 -> V_205 , & V_370 ) ;
F_320 ( V_185 -> V_205 ) ;
while ( ! F_318 ( V_609 ) ) {
V_30 = F_431 ( V_609 , struct V_27 , V_29 . V_324 ) ;
F_219 ( & V_30 -> V_29 . V_324 ) ;
F_434 ( V_185 -> V_205 , V_30 ) ;
}
F_325 ( V_185 -> V_205 , & V_370 ) ;
}
static inline bool F_439 ( struct V_26 * V_26 )
{
if ( V_26 -> V_72 . V_5 )
return false ;
if ( V_26 -> V_78 . V_82 )
return false ;
if ( V_26 -> V_78 . V_85 )
return false ;
if ( V_26 -> V_346 )
return false ;
return true ;
}
static void F_440 ( int V_1 )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
struct V_26 * V_26 , * V_619 ;
struct V_369 V_370 ;
F_441 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
F_442 (rq, cfs_rq, pos) {
struct V_28 * V_29 ;
if ( F_224 ( V_26 ) )
continue;
if ( F_249 ( F_64 ( V_26 ) , V_26 ) )
F_66 ( V_26 , 0 ) ;
V_29 = V_26 -> V_34 -> V_29 [ V_1 ] ;
if ( V_29 && ! F_248 ( V_29 ) )
F_252 ( V_29 , 0 ) ;
if ( F_439 ( V_26 ) )
F_29 ( V_26 ) ;
}
F_443 ( V_25 , & V_370 ) ;
}
static void F_444 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_28 * V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
unsigned long V_91 = V_227 ;
unsigned long V_72 ;
if ( V_26 -> V_620 == V_91 )
return;
V_26 -> V_621 = NULL ;
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_621 = V_29 ;
if ( V_26 -> V_620 == V_91 )
break;
}
if ( ! V_29 ) {
V_26 -> V_622 = F_261 ( V_26 ) ;
V_26 -> V_620 = V_91 ;
}
while ( ( V_29 = V_26 -> V_621 ) != NULL ) {
V_72 = V_26 -> V_622 ;
V_72 = F_445 ( V_72 * V_29 -> V_78 . V_81 ,
F_261 ( V_26 ) + 1 ) ;
V_26 = F_24 ( V_29 ) ;
V_26 -> V_622 = V_72 ;
V_26 -> V_620 = V_91 ;
}
}
static unsigned long F_143 ( struct V_27 * V_30 )
{
struct V_26 * V_26 = F_22 ( V_30 ) ;
F_444 ( V_26 ) ;
return F_445 ( V_30 -> V_29 . V_78 . V_81 * V_26 -> V_622 ,
F_261 ( V_26 ) + 1 ) ;
}
static inline void F_440 ( int V_1 )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_369 V_370 ;
F_441 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
F_249 ( F_64 ( V_26 ) , V_26 ) ;
F_443 ( V_25 , & V_370 ) ;
}
static unsigned long F_143 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_78 . V_81 ;
}
static inline void F_446 ( struct V_623 * V_529 )
{
* V_529 = (struct V_623 ) {
. V_624 = NULL ,
. V_235 = NULL ,
. V_625 = 0UL ,
. V_626 = 0UL ,
. V_627 = 0UL ,
. V_628 = {
. V_511 = 0UL ,
. V_629 = 0 ,
. V_630 = V_631 ,
} ,
} ;
}
static inline int F_447 ( struct V_215 * V_216 ,
enum V_632 V_404 )
{
int V_506 ;
switch ( V_404 ) {
case V_591 :
V_506 = V_216 -> V_633 ;
break;
case V_595 :
V_506 = V_216 -> V_634 ;
break;
default:
V_506 = V_216 -> V_635 ;
break;
}
return V_506 ;
}
static unsigned long F_448 ( int V_1 )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
T_2 V_469 , V_636 , V_637 , V_78 ;
T_3 V_44 ;
V_637 = F_99 ( V_25 -> V_637 ) ;
V_78 = F_99 ( V_25 -> V_638 ) ;
V_44 = F_449 ( V_25 ) - V_637 ;
if ( F_14 ( V_44 < 0 ) )
V_44 = 0 ;
V_469 = F_450 () + V_44 ;
V_636 = F_234 ( V_78 , V_469 ) ;
if ( F_12 ( V_636 < V_87 ) )
return V_87 - V_636 ;
return 1 ;
}
static void F_451 ( struct V_215 * V_216 , int V_1 )
{
unsigned long V_180 = F_231 ( V_216 , V_1 ) ;
struct V_494 * V_639 = V_216 -> V_497 ;
F_129 ( V_1 ) -> V_472 = V_180 ;
V_180 *= F_448 ( V_1 ) ;
V_180 >>= V_640 ;
if ( ! V_180 )
V_180 = 1 ;
F_129 ( V_1 ) -> V_471 = V_180 ;
V_639 -> V_516 -> V_180 = V_180 ;
V_639 -> V_516 -> V_641 = V_180 ;
}
void F_452 ( struct V_215 * V_216 , int V_1 )
{
struct V_215 * V_566 = V_216 -> V_566 ;
struct V_494 * V_152 , * V_639 = V_216 -> V_497 ;
unsigned long V_180 , V_641 ;
unsigned long V_224 ;
V_224 = F_160 ( V_216 -> V_642 ) ;
V_224 = F_163 ( V_224 , 1UL , V_643 ) ;
V_639 -> V_516 -> V_644 = V_227 + V_224 ;
if ( ! V_566 ) {
F_451 ( V_216 , V_1 ) ;
return;
}
V_180 = 0 ;
V_641 = V_500 ;
if ( V_566 -> V_114 & V_645 ) {
F_128 (cpu, sched_group_span(sdg)) {
struct V_646 * V_516 ;
struct V_25 * V_25 = F_129 ( V_1 ) ;
if ( F_14 ( ! V_25 -> V_216 ) ) {
V_180 += F_131 ( V_1 ) ;
} else {
V_516 = V_25 -> V_216 -> V_497 -> V_516 ;
V_180 += V_516 -> V_180 ;
}
V_641 = F_159 ( V_180 , V_641 ) ;
}
} else {
V_152 = V_566 -> V_497 ;
do {
struct V_646 * V_516 = V_152 -> V_516 ;
V_180 += V_516 -> V_180 ;
V_641 = F_159 ( V_516 -> V_641 , V_641 ) ;
V_152 = V_152 -> V_60 ;
} while ( V_152 != V_566 -> V_497 );
}
V_639 -> V_516 -> V_180 = V_180 ;
V_639 -> V_516 -> V_641 = V_641 ;
}
static inline int
F_453 ( struct V_25 * V_25 , struct V_215 * V_216 )
{
return ( ( V_25 -> V_471 * V_216 -> V_200 ) <
( V_25 -> V_472 * 100 ) ) ;
}
static inline int F_454 ( struct V_494 * V_152 )
{
return V_152 -> V_516 -> V_509 ;
}
static inline bool
F_455 ( struct V_585 * V_185 , struct V_647 * V_648 )
{
if ( V_648 -> V_629 < V_648 -> F_119 )
return true ;
if ( ( V_648 -> V_649 * 100 ) >
( V_648 -> V_650 * V_185 -> V_216 -> V_200 ) )
return true ;
return false ;
}
static inline bool
F_456 ( struct V_585 * V_185 , struct V_647 * V_648 )
{
if ( V_648 -> V_629 <= V_648 -> F_119 )
return false ;
if ( ( V_648 -> V_649 * 100 ) <
( V_648 -> V_650 * V_185 -> V_216 -> V_200 ) )
return true ;
return false ;
}
static inline bool
F_457 ( struct V_494 * V_651 , struct V_494 * V_652 )
{
return V_651 -> V_516 -> V_641 * V_556 <
V_652 -> V_516 -> V_641 * 1024 ;
}
static inline enum
V_630 F_458 ( struct V_494 * V_152 ,
struct V_647 * V_648 )
{
if ( V_648 -> V_653 )
return V_654 ;
if ( F_454 ( V_152 ) )
return V_655 ;
return V_631 ;
}
static inline void F_459 ( struct V_585 * V_185 ,
struct V_494 * V_152 , int V_506 ,
int V_515 , struct V_647 * V_648 ,
bool * V_656 )
{
unsigned long V_72 ;
int V_273 , V_74 ;
memset ( V_648 , 0 , sizeof( * V_648 ) ) ;
F_387 (i, sched_group_span(group), env->cpus) {
struct V_25 * V_25 = F_129 ( V_273 ) ;
if ( V_515 )
V_72 = F_369 ( V_273 , V_506 ) ;
else
V_72 = F_368 ( V_273 , V_506 ) ;
V_648 -> V_657 += V_72 ;
V_648 -> V_650 += F_403 ( V_273 ) ;
V_648 -> V_629 += V_25 -> V_42 . V_415 ;
V_74 = V_25 -> V_74 ;
if ( V_74 > 1 )
* V_656 = true ;
#ifdef F_460
V_648 -> V_139 += V_25 -> V_139 ;
V_648 -> V_141 += V_25 -> V_141 ;
#endif
V_648 -> V_658 += F_130 ( V_25 ) ;
if ( ! V_74 && F_376 ( V_273 ) )
V_648 -> V_659 ++ ;
}
V_648 -> V_649 = V_152 -> V_516 -> V_180 ;
V_648 -> V_511 = ( V_648 -> V_657 * V_87 ) / V_648 -> V_649 ;
if ( V_648 -> V_629 )
V_648 -> V_660 = V_648 -> V_658 / V_648 -> V_629 ;
V_648 -> F_119 = V_152 -> F_119 ;
V_648 -> V_653 = F_456 ( V_185 , V_648 ) ;
V_648 -> V_630 = F_458 ( V_152 , V_648 ) ;
}
static bool F_461 ( struct V_585 * V_185 ,
struct V_623 * V_529 ,
struct V_494 * V_651 ,
struct V_647 * V_648 )
{
struct V_647 * V_624 = & V_529 -> V_628 ;
if ( V_648 -> V_630 > V_624 -> V_630 )
return true ;
if ( V_648 -> V_630 < V_624 -> V_630 )
return false ;
if ( V_648 -> V_511 <= V_624 -> V_511 )
return false ;
if ( ! ( V_185 -> V_216 -> V_114 & V_661 ) )
goto V_662;
if ( V_648 -> V_629 <= V_648 -> F_119 &&
F_457 ( V_529 -> V_235 , V_651 ) )
return false ;
V_662:
if ( ! ( V_185 -> V_216 -> V_114 & V_663 ) )
return true ;
if ( V_185 -> V_404 == V_591 )
return true ;
if ( V_648 -> V_629 &&
F_462 ( V_185 -> V_171 , V_651 -> V_664 ) ) {
if ( ! V_529 -> V_624 )
return true ;
if ( F_462 ( V_529 -> V_624 -> V_664 ,
V_651 -> V_664 ) )
return true ;
}
return false ;
}
static inline enum V_665 F_463 ( struct V_647 * V_648 )
{
if ( V_648 -> V_629 > V_648 -> V_139 )
return V_666 ;
if ( V_648 -> V_629 > V_648 -> V_141 )
return V_233 ;
return V_667 ;
}
static inline enum V_665 F_464 ( struct V_25 * V_25 )
{
if ( V_25 -> V_74 > V_25 -> V_139 )
return V_666 ;
if ( V_25 -> V_74 > V_25 -> V_141 )
return V_233 ;
return V_667 ;
}
static inline enum V_665 F_463 ( struct V_647 * V_648 )
{
return V_667 ;
}
static inline enum V_665 F_464 ( struct V_25 * V_25 )
{
return V_666 ;
}
static inline void F_465 ( struct V_585 * V_185 , struct V_623 * V_529 )
{
struct V_215 * V_566 = V_185 -> V_216 -> V_566 ;
struct V_494 * V_651 = V_185 -> V_216 -> V_497 ;
struct V_647 * V_235 = & V_529 -> V_668 ;
struct V_647 V_669 ;
int V_506 , V_670 = 0 ;
bool V_656 = false ;
if ( V_566 && V_566 -> V_114 & V_671 )
V_670 = 1 ;
V_506 = F_447 ( V_185 -> V_216 , V_185 -> V_404 ) ;
do {
struct V_647 * V_648 = & V_669 ;
int V_515 ;
V_515 = F_142 ( V_185 -> V_171 , F_383 ( V_651 ) ) ;
if ( V_515 ) {
V_529 -> V_235 = V_651 ;
V_648 = V_235 ;
if ( V_185 -> V_404 != V_595 ||
F_466 ( V_227 , V_651 -> V_516 -> V_644 ) )
F_452 ( V_185 -> V_216 , V_185 -> V_171 ) ;
}
F_459 ( V_185 , V_651 , V_506 , V_515 , V_648 ,
& V_656 ) ;
if ( V_515 )
goto V_672;
if ( V_670 && V_529 -> V_235 &&
F_455 ( V_185 , V_235 ) &&
( V_648 -> V_629 > V_235 -> V_629 + 1 ) ) {
V_648 -> V_653 = 1 ;
V_648 -> V_630 = F_458 ( V_651 , V_648 ) ;
}
if ( F_461 ( V_185 , V_529 , V_651 , V_648 ) ) {
V_529 -> V_624 = V_651 ;
V_529 -> V_628 = * V_648 ;
}
V_672:
V_529 -> V_625 += V_648 -> V_629 ;
V_529 -> V_626 += V_648 -> V_657 ;
V_529 -> V_627 += V_648 -> V_649 ;
V_651 = V_651 -> V_60 ;
} while ( V_651 != V_185 -> V_216 -> V_497 );
if ( V_185 -> V_216 -> V_114 & V_590 )
V_185 -> V_665 = F_463 ( & V_529 -> V_628 ) ;
if ( ! V_185 -> V_216 -> V_35 ) {
if ( V_185 -> V_205 -> V_554 -> V_656 != V_656 )
V_185 -> V_205 -> V_554 -> V_656 = V_656 ;
}
}
static int F_467 ( struct V_585 * V_185 , struct V_623 * V_529 )
{
int V_673 ;
if ( ! ( V_185 -> V_216 -> V_114 & V_663 ) )
return 0 ;
if ( V_185 -> V_404 == V_591 )
return 0 ;
if ( ! V_529 -> V_624 )
return 0 ;
V_673 = V_529 -> V_624 -> V_664 ;
if ( F_462 ( V_673 , V_185 -> V_171 ) )
return 0 ;
V_185 -> V_509 = F_132 (
V_529 -> V_628 . V_511 * V_529 -> V_628 . V_649 ,
V_87 ) ;
return 1 ;
}
static inline
void F_468 ( struct V_585 * V_185 , struct V_623 * V_529 )
{
unsigned long V_558 , V_674 = 0 , V_675 = 0 ;
unsigned int V_676 = 2 ;
unsigned long V_677 ;
struct V_647 * V_235 , * V_624 ;
V_235 = & V_529 -> V_668 ;
V_624 = & V_529 -> V_628 ;
if ( ! V_235 -> V_629 )
V_235 -> V_660 = F_371 ( V_185 -> V_171 ) ;
else if ( V_624 -> V_660 > V_235 -> V_660 )
V_676 = 1 ;
V_677 =
( V_624 -> V_660 * V_87 ) /
V_624 -> V_649 ;
if ( V_624 -> V_511 + V_677 >=
V_235 -> V_511 + ( V_677 * V_676 ) ) {
V_185 -> V_509 = V_624 -> V_660 ;
return;
}
V_674 += V_624 -> V_649 *
F_159 ( V_624 -> V_660 , V_624 -> V_511 ) ;
V_674 += V_235 -> V_649 *
F_159 ( V_235 -> V_660 , V_235 -> V_511 ) ;
V_674 /= V_87 ;
if ( V_624 -> V_511 > V_677 ) {
V_675 += V_624 -> V_649 *
F_159 ( V_624 -> V_660 ,
V_624 -> V_511 - V_677 ) ;
}
if ( V_624 -> V_511 * V_624 -> V_649 <
V_624 -> V_660 * V_87 ) {
V_558 = ( V_624 -> V_511 * V_624 -> V_649 ) /
V_235 -> V_649 ;
} else {
V_558 = ( V_624 -> V_660 * V_87 ) /
V_235 -> V_649 ;
}
V_675 += V_235 -> V_649 *
F_159 ( V_235 -> V_660 , V_235 -> V_511 + V_558 ) ;
V_675 /= V_87 ;
if ( V_675 > V_674 )
V_185 -> V_509 = V_624 -> V_660 ;
}
static inline void F_469 ( struct V_585 * V_185 , struct V_623 * V_529 )
{
unsigned long V_678 , V_679 = ~ 0UL ;
struct V_647 * V_235 , * V_624 ;
V_235 = & V_529 -> V_668 ;
V_624 = & V_529 -> V_628 ;
if ( V_624 -> V_630 == V_655 ) {
V_624 -> V_660 =
F_159 ( V_624 -> V_660 , V_529 -> V_511 ) ;
}
if ( V_624 -> V_511 <= V_529 -> V_511 ||
V_235 -> V_511 >= V_529 -> V_511 ) {
V_185 -> V_509 = 0 ;
return F_468 ( V_185 , V_529 ) ;
}
if ( V_624 -> V_630 == V_654 &&
V_235 -> V_630 == V_654 ) {
V_679 = V_624 -> V_629 * V_87 ;
if ( V_679 > V_624 -> V_649 ) {
V_679 -= V_624 -> V_649 ;
V_679 *= F_13 ( V_73 ) ;
V_679 /= V_624 -> V_649 ;
} else
V_679 = ~ 0UL ;
}
V_678 = F_159 ( V_624 -> V_511 - V_529 -> V_511 , V_679 ) ;
V_185 -> V_509 = F_159 (
V_678 * V_624 -> V_649 ,
( V_529 -> V_511 - V_235 -> V_511 ) * V_235 -> V_649
) / V_87 ;
if ( V_185 -> V_509 < V_624 -> V_660 )
return F_468 ( V_185 , V_529 ) ;
}
static struct V_494 * F_470 ( struct V_585 * V_185 )
{
struct V_647 * V_235 , * V_624 ;
struct V_623 V_529 ;
F_446 ( & V_529 ) ;
F_465 ( V_185 , & V_529 ) ;
V_235 = & V_529 . V_668 ;
V_624 = & V_529 . V_628 ;
if ( F_467 ( V_185 , & V_529 ) )
return V_529 . V_624 ;
if ( ! V_529 . V_624 || V_624 -> V_629 == 0 )
goto V_680;
V_529 . V_511 = ( V_87 * V_529 . V_626 )
/ V_529 . V_627 ;
if ( V_624 -> V_630 == V_655 )
goto V_681;
if ( V_185 -> V_404 == V_595 && F_455 ( V_185 , V_235 ) &&
V_624 -> V_653 )
goto V_681;
if ( V_235 -> V_511 >= V_624 -> V_511 )
goto V_680;
if ( V_235 -> V_511 >= V_529 . V_511 )
goto V_680;
if ( V_185 -> V_404 == V_682 ) {
if ( ( V_624 -> V_630 != V_654 ) &&
( V_235 -> V_659 <= ( V_624 -> V_659 + 1 ) ) )
goto V_680;
} else {
if ( 100 * V_624 -> V_511 <=
V_185 -> V_216 -> V_200 * V_235 -> V_511 )
goto V_680;
}
V_681:
F_469 ( V_185 , & V_529 ) ;
return V_529 . V_624 ;
V_680:
V_185 -> V_509 = 0 ;
return NULL ;
}
static struct V_25 * F_471 ( struct V_585 * V_185 ,
struct V_494 * V_152 )
{
struct V_25 * V_624 = NULL , * V_25 ;
unsigned long V_683 = 0 , V_684 = 1 ;
int V_273 ;
F_387 (i, sched_group_span(group), env->cpus) {
unsigned long V_180 , V_685 ;
enum V_665 V_686 ;
V_25 = F_129 ( V_273 ) ;
V_686 = F_464 ( V_25 ) ;
if ( V_686 > V_185 -> V_665 )
continue;
V_180 = F_131 ( V_273 ) ;
V_685 = F_130 ( V_25 ) ;
if ( V_25 -> V_74 == 1 && V_685 > V_185 -> V_509 &&
! F_453 ( V_25 , V_185 -> V_216 ) )
continue;
if ( V_685 * V_684 > V_683 * V_180 ) {
V_683 = V_685 ;
V_684 = V_180 ;
V_624 = V_25 ;
}
}
return V_624 ;
}
static int F_472 ( struct V_585 * V_185 )
{
struct V_215 * V_216 = V_185 -> V_216 ;
if ( V_185 -> V_404 == V_595 ) {
if ( ( V_216 -> V_114 & V_663 ) &&
F_462 ( V_185 -> V_171 , V_185 -> V_204 ) )
return 1 ;
}
if ( ( V_185 -> V_404 != V_591 ) &&
( V_185 -> V_203 -> V_42 . V_415 == 1 ) ) {
if ( ( F_453 ( V_185 -> V_203 , V_216 ) ) &&
( F_131 ( V_185 -> V_204 ) * V_216 -> V_200 < F_131 ( V_185 -> V_171 ) * 100 ) )
return 1 ;
}
return F_14 ( V_216 -> V_600 > V_216 -> V_601 + 2 ) ;
}
static int F_473 ( struct V_585 * V_185 )
{
struct V_494 * V_651 = V_185 -> V_216 -> V_497 ;
int V_1 , V_687 = - 1 ;
if ( ! F_142 ( V_185 -> V_171 , V_185 -> V_9 ) )
return 0 ;
if ( V_185 -> V_404 == V_595 )
return 1 ;
F_387 (cpu, group_balance_mask(sg), env->cpus) {
if ( ! F_376 ( V_1 ) )
continue;
V_687 = V_1 ;
break;
}
if ( V_687 == - 1 )
V_687 = F_474 ( V_651 ) ;
return V_687 == V_185 -> V_171 ;
}
static int F_475 ( int V_479 , struct V_25 * V_457 ,
struct V_215 * V_216 , enum V_632 V_404 ,
int * V_688 )
{
int V_689 , V_690 , V_691 = 0 ;
struct V_215 * V_692 = V_216 -> V_35 ;
struct V_494 * V_152 ;
struct V_25 * V_624 ;
struct V_369 V_370 ;
struct V_535 * V_9 = F_393 ( V_693 ) ;
struct V_585 V_185 = {
. V_216 = V_216 ,
. V_171 = V_479 ,
. V_205 = V_457 ,
. V_694 = F_383 ( V_216 -> V_497 ) ,
. V_404 = V_404 ,
. V_613 = V_614 ,
. V_9 = V_9 ,
. V_665 = V_667 ,
. V_609 = F_476 ( V_185 . V_609 ) ,
} ;
F_394 ( V_9 , F_395 ( V_216 ) , V_695 ) ;
F_84 ( V_216 -> V_696 [ V_404 ] ) ;
V_697:
if ( ! F_473 ( & V_185 ) ) {
* V_688 = 0 ;
goto V_680;
}
V_152 = F_470 ( & V_185 ) ;
if ( ! V_152 ) {
F_84 ( V_216 -> V_698 [ V_404 ] ) ;
goto V_680;
}
V_624 = F_471 ( & V_185 , V_152 ) ;
if ( ! V_624 ) {
F_84 ( V_216 -> V_699 [ V_404 ] ) ;
goto V_680;
}
F_186 ( V_624 == V_185 . V_205 ) ;
F_71 ( V_216 -> V_700 [ V_404 ] , V_185 . V_509 ) ;
V_185 . V_204 = V_624 -> V_1 ;
V_185 . V_203 = V_624 ;
V_689 = 0 ;
if ( V_624 -> V_74 > 1 ) {
V_185 . V_114 |= V_598 ;
V_185 . V_612 = F_159 ( V_701 , V_624 -> V_74 ) ;
V_702:
F_441 ( V_624 , & V_370 ) ;
F_320 ( V_624 ) ;
V_690 = F_430 ( & V_185 ) ;
F_325 ( V_624 , & V_370 ) ;
if ( V_690 ) {
F_438 ( & V_185 ) ;
V_689 += V_690 ;
}
F_477 ( V_370 . V_114 ) ;
if ( V_185 . V_114 & V_615 ) {
V_185 . V_114 &= ~ V_615 ;
goto V_702;
}
if ( ( V_185 . V_114 & V_596 ) && V_185 . V_509 > 0 ) {
F_397 ( V_185 . V_171 , V_185 . V_9 ) ;
V_185 . V_205 = F_129 ( V_185 . V_597 ) ;
V_185 . V_171 = V_185 . V_597 ;
V_185 . V_114 &= ~ V_596 ;
V_185 . V_611 = 0 ;
V_185 . V_613 = V_614 ;
goto V_702;
}
if ( V_692 ) {
int * V_703 = & V_692 -> V_497 -> V_516 -> V_509 ;
if ( ( V_185 . V_114 & V_594 ) && V_185 . V_509 > 0 )
* V_703 = 1 ;
}
if ( F_14 ( V_185 . V_114 & V_598 ) ) {
F_397 ( F_26 ( V_624 ) , V_9 ) ;
if ( ! F_478 ( V_9 , V_185 . V_694 ) ) {
V_185 . V_611 = 0 ;
V_185 . V_613 = V_614 ;
goto V_697;
}
goto V_704;
}
}
if ( ! V_689 ) {
F_84 ( V_216 -> V_705 [ V_404 ] ) ;
if ( V_404 != V_595 )
V_216 -> V_600 ++ ;
if ( F_472 ( & V_185 ) ) {
unsigned long V_114 ;
F_479 ( & V_624 -> V_259 , V_114 ) ;
if ( ! F_142 ( V_479 , & V_624 -> V_47 -> V_210 ) ) {
F_480 ( & V_624 -> V_259 ,
V_114 ) ;
V_185 . V_114 |= V_598 ;
goto V_706;
}
if ( ! V_624 -> V_691 ) {
V_624 -> V_691 = 1 ;
V_624 -> V_707 = V_479 ;
V_691 = 1 ;
}
F_480 ( & V_624 -> V_259 , V_114 ) ;
if ( V_691 ) {
F_481 ( F_26 ( V_624 ) ,
V_708 , V_624 ,
& V_624 -> V_709 ) ;
}
V_216 -> V_600 = V_216 -> V_601 + 1 ;
}
} else
V_216 -> V_600 = 0 ;
if ( F_12 ( ! V_691 ) ) {
V_216 -> V_642 = V_216 -> V_710 ;
} else {
if ( V_216 -> V_642 < V_216 -> V_711 )
V_216 -> V_642 *= 2 ;
}
goto V_322;
V_680:
if ( V_692 ) {
int * V_703 = & V_692 -> V_497 -> V_516 -> V_509 ;
if ( * V_703 )
* V_703 = 0 ;
}
V_704:
F_84 ( V_216 -> V_712 [ V_404 ] ) ;
V_216 -> V_600 = 0 ;
V_706:
if ( ( ( V_185 . V_114 & V_598 ) &&
V_216 -> V_642 < V_713 ) ||
( V_216 -> V_642 < V_216 -> V_711 ) )
V_216 -> V_642 *= 2 ;
V_689 = 0 ;
V_322:
return V_689 ;
}
static inline unsigned long
F_482 ( struct V_215 * V_216 , int V_714 )
{
unsigned long V_224 = V_216 -> V_642 ;
if ( V_714 )
V_224 *= V_216 -> V_715 ;
V_224 = F_160 ( V_224 ) ;
V_224 = F_163 ( V_224 , 1UL , V_643 ) ;
return V_224 ;
}
static inline void
F_483 ( struct V_215 * V_216 , unsigned long * V_716 )
{
unsigned long V_224 , V_60 ;
V_224 = F_482 ( V_216 , 0 ) ;
V_60 = V_216 -> V_717 + V_224 ;
if ( F_197 ( * V_716 , V_60 ) )
* V_716 = V_60 ;
}
static int F_262 ( struct V_25 * V_457 , struct V_369 * V_370 )
{
unsigned long V_716 = V_227 + V_225 ;
int V_479 = V_457 -> V_1 ;
struct V_215 * V_216 ;
int V_718 = 0 ;
T_2 V_719 = 0 ;
V_457 -> V_527 = F_79 ( V_457 ) ;
if ( ! F_484 ( V_479 ) )
return 0 ;
F_485 ( V_457 , V_370 ) ;
if ( V_457 -> V_540 < V_587 ||
! V_457 -> V_554 -> V_656 ) {
F_139 () ;
V_216 = F_486 ( V_457 -> V_216 ) ;
if ( V_216 )
F_483 ( V_216 , & V_716 ) ;
F_147 () ;
goto V_322;
}
F_308 ( & V_457 -> V_259 ) ;
F_440 ( V_479 ) ;
F_139 () ;
F_406 (this_cpu, sd) {
int V_688 = 1 ;
T_2 V_720 , V_721 ;
if ( ! ( V_216 -> V_114 & V_563 ) )
continue;
if ( V_457 -> V_540 < V_719 + V_216 -> V_722 ) {
F_483 ( V_216 , & V_716 ) ;
break;
}
if ( V_216 -> V_114 & V_723 ) {
V_720 = F_301 ( V_479 ) ;
V_718 = F_475 ( V_479 , V_457 ,
V_216 , V_595 ,
& V_688 ) ;
V_721 = F_301 ( V_479 ) - V_720 ;
if ( V_721 > V_216 -> V_722 )
V_216 -> V_722 = V_721 ;
V_719 += V_721 ;
}
F_483 ( V_216 , & V_716 ) ;
if ( V_718 || V_457 -> V_74 > 0 )
break;
}
F_147 () ;
F_306 ( & V_457 -> V_259 ) ;
if ( V_719 > V_457 -> V_724 )
V_457 -> V_724 = V_719 ;
if ( V_457 -> V_42 . V_415 && ! V_718 )
V_718 = 1 ;
V_322:
if ( F_197 ( V_457 -> V_716 , V_716 ) )
V_457 -> V_716 = V_716 ;
if ( V_457 -> V_74 != V_457 -> V_42 . V_415 )
V_718 = - 1 ;
if ( V_718 )
V_457 -> V_527 = 0 ;
F_487 ( V_457 , V_370 ) ;
return V_718 ;
}
static int V_708 ( void * V_410 )
{
struct V_25 * V_725 = V_410 ;
int V_673 = F_26 ( V_725 ) ;
int V_726 = V_725 -> V_707 ;
struct V_25 * V_727 = F_129 ( V_726 ) ;
struct V_215 * V_216 ;
struct V_27 * V_30 = NULL ;
struct V_369 V_370 ;
F_488 ( V_725 , & V_370 ) ;
if ( ! F_484 ( V_673 ) || ! F_484 ( V_726 ) )
goto V_728;
if ( F_14 ( V_673 != F_302 () ||
! V_725 -> V_691 ) )
goto V_728;
if ( V_725 -> V_74 <= 1 )
goto V_728;
F_186 ( V_725 == V_727 ) ;
F_139 () ;
F_406 (target_cpu, sd) {
if ( ( V_216 -> V_114 & V_563 ) &&
F_142 ( V_673 , F_395 ( V_216 ) ) )
break;
}
if ( F_12 ( V_216 ) ) {
struct V_585 V_185 = {
. V_216 = V_216 ,
. V_171 = V_726 ,
. V_205 = V_727 ,
. V_204 = V_725 -> V_1 ,
. V_203 = V_725 ,
. V_404 = V_682 ,
. V_114 = V_596 ,
} ;
F_84 ( V_216 -> V_729 ) ;
F_320 ( V_725 ) ;
V_30 = F_428 ( & V_185 ) ;
if ( V_30 ) {
F_84 ( V_216 -> V_730 ) ;
V_216 -> V_600 = 0 ;
} else {
F_84 ( V_216 -> V_731 ) ;
}
}
F_147 () ;
V_728:
V_725 -> V_691 = 0 ;
F_325 ( V_725 , & V_370 ) ;
if ( V_30 )
F_437 ( V_727 , V_30 ) ;
F_146 () ;
return 0 ;
}
static inline int F_489 ( struct V_25 * V_25 )
{
return F_14 ( ! F_490 ( V_25 -> V_216 ) ) ;
}
static inline int F_491 ( void )
{
int V_732 = F_386 ( V_733 . V_734 ) ;
if ( V_732 < V_735 && F_376 ( V_732 ) )
return V_732 ;
return V_735 ;
}
static void F_492 ( void )
{
int V_736 ;
V_733 . V_716 ++ ;
V_736 = F_491 () ;
if ( V_736 >= V_735 )
return;
if ( F_493 ( V_737 , F_494 ( V_736 ) ) )
return;
F_495 ( V_736 ) ;
return;
}
void F_496 ( unsigned int V_1 )
{
if ( F_14 ( F_497 ( V_738 , F_494 ( V_1 ) ) ) ) {
if ( F_12 ( F_142 ( V_1 , V_733 . V_734 ) ) ) {
F_397 ( V_1 , V_733 . V_734 ) ;
F_498 ( & V_733 . V_739 ) ;
}
F_499 ( V_738 , F_494 ( V_1 ) ) ;
}
}
static inline void F_500 ( void )
{
struct V_215 * V_216 ;
int V_1 = F_302 () ;
F_139 () ;
V_216 = F_152 ( F_153 ( V_544 , V_1 ) ) ;
if ( ! V_216 || ! V_216 -> V_740 )
goto V_209;
V_216 -> V_740 = 0 ;
F_501 ( & V_216 -> V_134 -> V_741 ) ;
V_209:
F_147 () ;
}
void F_502 ( void )
{
struct V_215 * V_216 ;
int V_1 = F_302 () ;
F_139 () ;
V_216 = F_152 ( F_153 ( V_544 , V_1 ) ) ;
if ( ! V_216 || V_216 -> V_740 )
goto V_209;
V_216 -> V_740 = 1 ;
F_498 ( & V_216 -> V_134 -> V_741 ) ;
V_209:
F_147 () ;
}
void F_503 ( int V_1 )
{
if ( ! F_484 ( V_1 ) )
return;
if ( ! F_504 ( V_1 ) )
return;
if ( F_497 ( V_738 , F_494 ( V_1 ) ) )
return;
if ( F_489 ( F_129 ( V_1 ) ) )
return;
F_505 ( V_1 , V_733 . V_734 ) ;
F_501 ( & V_733 . V_739 ) ;
F_506 ( V_738 , F_494 ( V_1 ) ) ;
}
void F_507 ( void )
{
V_643 = V_225 * F_508 () / 10 ;
}
static void F_509 ( struct V_25 * V_25 , enum V_632 V_404 )
{
int V_688 = 1 ;
int V_1 = V_25 -> V_1 ;
unsigned long V_224 ;
struct V_215 * V_216 ;
unsigned long V_716 = V_227 + 60 * V_225 ;
int F_483 = 0 ;
int V_742 , V_743 = 0 ;
T_2 V_744 = 0 ;
F_440 ( V_1 ) ;
F_139 () ;
F_406 (cpu, sd) {
if ( F_197 ( V_227 , V_216 -> V_745 ) ) {
V_216 -> V_722 =
( V_216 -> V_722 * 253 ) / 256 ;
V_216 -> V_745 = V_227 + V_225 ;
V_743 = 1 ;
}
V_744 += V_216 -> V_722 ;
if ( ! ( V_216 -> V_114 & V_563 ) )
continue;
if ( ! V_688 ) {
if ( V_743 )
continue;
break;
}
V_224 = F_482 ( V_216 , V_404 != V_682 ) ;
V_742 = V_216 -> V_114 & V_746 ;
if ( V_742 ) {
if ( ! F_510 ( & V_747 ) )
goto V_322;
}
if ( F_466 ( V_227 , V_216 -> V_717 + V_224 ) ) {
if ( F_475 ( V_1 , V_25 , V_216 , V_404 , & V_688 ) ) {
V_404 = F_376 ( V_1 ) ? V_682 : V_591 ;
}
V_216 -> V_717 = V_227 ;
V_224 = F_482 ( V_216 , V_404 != V_682 ) ;
}
if ( V_742 )
F_189 ( & V_747 ) ;
V_322:
if ( F_197 ( V_716 , V_216 -> V_717 + V_224 ) ) {
V_716 = V_216 -> V_717 + V_224 ;
F_483 = 1 ;
}
}
if ( V_743 ) {
V_25 -> V_724 =
F_70 ( ( T_2 ) V_587 , V_744 ) ;
}
F_147 () ;
if ( F_12 ( F_483 ) ) {
V_25 -> V_716 = V_716 ;
#ifdef F_359
if ( ( V_404 == V_682 ) && F_197 ( V_733 . V_716 , V_25 -> V_716 ) )
V_733 . V_716 = V_25 -> V_716 ;
#endif
}
}
static void F_511 ( struct V_25 * V_457 , enum V_632 V_404 )
{
int V_479 = V_457 -> V_1 ;
struct V_25 * V_25 ;
int V_687 ;
unsigned long V_716 = V_227 + 60 * V_225 ;
int F_483 = 0 ;
if ( V_404 != V_682 ||
! F_497 ( V_737 , F_494 ( V_479 ) ) )
goto V_302;
F_128 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_687 == V_479 || ! F_376 ( V_687 ) )
continue;
if ( F_512 () )
break;
V_25 = F_129 ( V_687 ) ;
if ( F_466 ( V_227 , V_25 -> V_716 ) ) {
struct V_369 V_370 ;
F_488 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
F_362 ( V_25 ) ;
F_513 ( V_25 , & V_370 ) ;
F_509 ( V_25 , V_682 ) ;
}
if ( F_197 ( V_716 , V_25 -> V_716 ) ) {
V_716 = V_25 -> V_716 ;
F_483 = 1 ;
}
}
if ( F_12 ( F_483 ) )
V_733 . V_716 = V_716 ;
V_302:
F_499 ( V_737 , F_494 ( V_479 ) ) ;
}
static inline bool F_514 ( struct V_25 * V_25 )
{
unsigned long V_91 = V_227 ;
struct V_528 * V_529 ;
struct V_215 * V_216 ;
int V_748 , V_273 , V_1 = V_25 -> V_1 ;
bool V_749 = false ;
if ( F_14 ( V_25 -> F_262 ) )
return false ;
F_500 () ;
F_496 ( V_1 ) ;
if ( F_12 ( ! F_104 ( & V_733 . V_739 ) ) )
return false ;
if ( F_201 ( V_91 , V_733 . V_716 ) )
return false ;
if ( V_25 -> V_74 >= 2 )
return true ;
F_139 () ;
V_529 = F_152 ( F_153 ( V_530 , V_1 ) ) ;
if ( V_529 ) {
V_748 = F_104 ( & V_529 -> V_741 ) ;
if ( V_748 > 1 ) {
V_749 = true ;
goto V_209;
}
}
V_216 = F_152 ( V_25 -> V_216 ) ;
if ( V_216 ) {
if ( ( V_25 -> V_42 . V_415 >= 1 ) &&
F_453 ( V_25 , V_216 ) ) {
V_749 = true ;
goto V_209;
}
}
V_216 = F_152 ( F_153 ( V_750 , V_1 ) ) ;
if ( V_216 ) {
F_128 (i, sched_domain_span(sd)) {
if ( V_273 == V_1 ||
! F_142 ( V_273 , V_733 . V_734 ) )
continue;
if ( F_462 ( V_273 , V_1 ) ) {
V_749 = true ;
goto V_209;
}
}
}
V_209:
F_147 () ;
return V_749 ;
}
static void F_511 ( struct V_25 * V_457 , enum V_632 V_404 ) { }
static T_12 void F_515 ( struct V_751 * V_752 )
{
struct V_25 * V_457 = V_457 () ;
enum V_632 V_404 = V_457 -> F_262 ?
V_682 : V_591 ;
F_511 ( V_457 , V_404 ) ;
F_509 ( V_457 , V_404 ) ;
}
void F_516 ( struct V_25 * V_25 )
{
if ( F_14 ( F_489 ( V_25 ) ) )
return;
if ( F_466 ( V_227 , V_25 -> V_716 ) )
F_517 ( V_753 ) ;
#ifdef F_359
if ( F_514 ( V_25 ) )
F_492 () ;
#endif
}
static void F_518 ( struct V_25 * V_25 )
{
F_8 () ;
F_348 ( V_25 ) ;
}
static void F_519 ( struct V_25 * V_25 )
{
F_8 () ;
F_349 ( V_25 ) ;
}
static void F_520 ( struct V_25 * V_25 , struct V_27 * V_47 , int V_386 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_47 -> V_29 ;
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
F_289 ( V_26 , V_29 , V_386 ) ;
}
if ( F_521 ( & V_287 ) )
F_212 ( V_25 , V_47 ) ;
}
static void F_522 ( struct V_27 * V_30 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 , * V_47 ;
struct V_25 * V_25 = V_457 () ;
struct V_369 V_370 ;
F_324 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
V_26 = F_22 ( V_175 ) ;
V_47 = V_26 -> V_47 ;
if ( V_47 ) {
F_67 ( V_26 ) ;
V_29 -> V_43 = V_47 -> V_43 ;
}
F_265 ( V_26 , V_29 , 1 ) ;
if ( V_754 && V_47 && F_37 ( V_47 , V_29 ) ) {
F_137 ( V_47 -> V_43 , V_29 -> V_43 ) ;
F_283 ( V_25 ) ;
}
V_29 -> V_43 -= V_26 -> F_36 ;
F_325 ( V_25 , & V_370 ) ;
}
static void
F_523 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_755 )
{
if ( ! F_524 ( V_30 ) )
return;
if ( V_25 -> V_47 == V_30 ) {
if ( V_30 -> V_756 > V_755 )
F_283 ( V_25 ) ;
} else
F_436 ( V_25 , V_30 , 0 ) ;
}
static inline bool F_525 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_51 )
return true ;
if ( ! V_29 -> V_95 || V_30 -> V_117 == V_567 )
return true ;
return false ;
}
static void F_526 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
V_29 = V_29 -> V_35 ;
F_60 (se) {
V_26 = F_23 ( V_29 ) ;
if ( F_311 ( V_26 ) )
break;
F_252 ( V_29 , V_366 ) ;
}
}
static void F_526 ( struct V_28 * V_29 ) { }
static void F_527 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_252 ( V_29 , 0 ) ;
F_254 ( V_26 , V_29 ) ;
F_66 ( V_26 , false ) ;
F_526 ( V_29 ) ;
}
static void F_65 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
#ifdef F_415
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
#endif
F_252 ( V_29 , F_240 ( V_352 ) ? 0 : V_365 ) ;
F_253 ( V_26 , V_29 ) ;
F_66 ( V_26 , false ) ;
F_526 ( V_29 ) ;
}
static void F_528 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( ! F_525 ( V_30 ) ) {
F_265 ( V_26 , V_29 , 0 ) ;
V_29 -> V_43 -= V_26 -> F_36 ;
}
F_527 ( V_29 ) ;
}
static void F_529 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_65 ( V_29 ) ;
if ( ! F_525 ( V_30 ) )
V_29 -> V_43 += V_26 -> F_36 ;
}
static void F_530 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_528 ( V_30 ) ;
}
static void F_531 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_529 ( V_30 ) ;
if ( F_524 ( V_30 ) ) {
if ( V_25 -> V_47 == V_30 )
F_283 ( V_25 ) ;
else
F_436 ( V_25 , V_30 , 0 ) ;
}
}
static void F_532 ( struct V_25 * V_25 )
{
struct V_28 * V_29 = & V_25 -> V_47 -> V_29 ;
F_60 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_284 ( V_26 , V_29 ) ;
F_75 ( V_26 , 0 ) ;
}
}
void F_533 ( struct V_26 * V_26 )
{
V_26 -> V_50 = V_757 ;
V_26 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_41
V_26 -> V_53 = V_26 -> F_36 ;
#endif
#ifdef F_216
#ifdef F_415
V_26 -> V_358 = 0 ;
#endif
F_534 ( & V_26 -> V_362 , 0 ) ;
F_534 ( & V_26 -> V_364 , 0 ) ;
#endif
}
static void F_535 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
F_536 ( V_30 , F_151 ( V_30 ) ) ;
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
}
static void F_537 ( struct V_27 * V_30 )
{
F_528 ( V_30 ) ;
F_536 ( V_30 , F_151 ( V_30 ) ) ;
#ifdef F_216
V_30 -> V_29 . V_78 . V_79 = 0 ;
#endif
F_529 ( V_30 ) ;
}
static void F_538 ( struct V_27 * V_30 , int type )
{
switch ( type ) {
case V_758 :
F_535 ( V_30 ) ;
break;
case V_759 :
F_537 ( V_30 ) ;
break;
}
}
void F_539 ( struct V_326 * V_34 )
{
int V_273 ;
F_346 ( F_304 ( V_34 ) ) ;
F_540 (i) {
if ( V_34 -> V_26 )
F_194 ( V_34 -> V_26 [ V_273 ] ) ;
if ( V_34 -> V_29 )
F_194 ( V_34 -> V_29 [ V_273 ] ) ;
}
F_194 ( V_34 -> V_26 ) ;
F_194 ( V_34 -> V_29 ) ;
}
int F_541 ( struct V_326 * V_34 , struct V_326 * V_35 )
{
struct V_28 * V_29 ;
struct V_26 * V_26 ;
int V_273 ;
V_34 -> V_26 = F_182 ( sizeof( V_26 ) * V_735 , V_275 ) ;
if ( ! V_34 -> V_26 )
goto V_760;
V_34 -> V_29 = F_182 ( sizeof( V_29 ) * V_735 , V_275 ) ;
if ( ! V_34 -> V_29 )
goto V_760;
V_34 -> V_328 = V_73 ;
F_339 ( F_304 ( V_34 ) ) ;
F_540 (i) {
V_26 = F_542 ( sizeof( struct V_26 ) ,
V_275 , F_121 ( V_273 ) ) ;
if ( ! V_26 )
goto V_760;
V_29 = F_542 ( sizeof( struct V_28 ) ,
V_275 , F_121 ( V_273 ) ) ;
if ( ! V_29 )
goto V_761;
F_533 ( V_26 ) ;
F_543 ( V_34 , V_26 , V_29 , V_273 , V_35 -> V_29 [ V_273 ] ) ;
F_62 ( V_29 ) ;
}
return 1 ;
V_761:
F_194 ( V_26 ) ;
V_760:
return 0 ;
}
void F_544 ( struct V_326 * V_34 )
{
struct V_28 * V_29 ;
struct V_25 * V_25 ;
int V_273 ;
F_540 (i) {
V_25 = F_129 ( V_273 ) ;
V_29 = V_34 -> V_29 [ V_273 ] ;
F_545 ( & V_25 -> V_259 ) ;
F_320 ( V_25 ) ;
F_65 ( V_29 ) ;
F_335 ( V_34 , V_273 ) ;
F_546 ( & V_25 -> V_259 ) ;
}
}
void F_547 ( struct V_326 * V_34 )
{
unsigned long V_114 ;
struct V_25 * V_25 ;
int V_1 ;
F_540 (cpu) {
if ( V_34 -> V_29 [ V_1 ] )
F_259 ( V_34 -> V_29 [ V_1 ] ) ;
if ( ! V_34 -> V_26 [ V_1 ] -> V_33 )
continue;
V_25 = F_129 ( V_1 ) ;
F_479 ( & V_25 -> V_259 , V_114 ) ;
F_29 ( V_34 -> V_26 [ V_1 ] ) ;
F_480 ( & V_25 -> V_259 , V_114 ) ;
}
}
void F_543 ( struct V_326 * V_34 , struct V_26 * V_26 ,
struct V_28 * V_29 , int V_1 ,
struct V_28 * V_35 )
{
struct V_25 * V_25 = F_129 ( V_1 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_25 = V_25 ;
F_343 ( V_26 ) ;
V_34 -> V_26 [ V_1 ] = V_26 ;
V_34 -> V_29 [ V_1 ] = V_29 ;
if ( ! V_29 )
return;
if ( ! V_35 ) {
V_29 -> V_26 = & V_25 -> V_42 ;
V_29 -> V_41 = 0 ;
} else {
V_29 -> V_26 = V_35 -> V_32 ;
V_29 -> V_41 = V_35 -> V_41 + 1 ;
}
V_29 -> V_32 = V_26 ;
F_4 ( & V_29 -> V_72 , V_73 ) ;
V_29 -> V_35 = V_35 ;
}
int F_548 ( struct V_326 * V_34 , unsigned long V_328 )
{
int V_273 ;
if ( ! V_34 -> V_29 [ 0 ] )
return - V_220 ;
V_328 = F_163 ( V_328 , F_549 ( V_330 ) , F_549 ( V_762 ) ) ;
F_550 ( & V_763 ) ;
if ( V_34 -> V_328 == V_328 )
goto V_764;
V_34 -> V_328 = V_328 ;
F_540 (i) {
struct V_25 * V_25 = F_129 ( V_273 ) ;
struct V_28 * V_29 = V_34 -> V_29 [ V_273 ] ;
struct V_369 V_370 ;
F_441 ( V_25 , & V_370 ) ;
F_320 ( V_25 ) ;
F_60 (se) {
F_252 ( V_29 , V_366 ) ;
F_223 ( V_29 ) ;
}
F_443 ( V_25 , & V_370 ) ;
}
V_764:
F_551 ( & V_763 ) ;
return 0 ;
}
void F_539 ( struct V_326 * V_34 ) { }
int F_541 ( struct V_326 * V_34 , struct V_326 * V_35 )
{
return 1 ;
}
void F_544 ( struct V_326 * V_34 ) { }
void F_547 ( struct V_326 * V_34 ) { }
static unsigned int F_552 ( struct V_25 * V_25 , struct V_27 * V_158 )
{
struct V_28 * V_29 = & V_158 -> V_29 ;
unsigned int V_765 = 0 ;
if ( V_25 -> V_42 . V_72 . V_5 )
V_765 = F_553 ( F_59 ( F_23 ( V_29 ) , V_29 ) ) ;
return V_765 ;
}
void F_554 ( struct V_766 * V_767 , int V_1 )
{
struct V_26 * V_26 , * V_619 ;
F_139 () ;
F_442 (cpu_rq(cpu), cfs_rq, pos)
F_555 ( V_767 , V_1 , V_26 ) ;
F_147 () ;
}
void F_556 ( struct V_27 * V_30 , struct V_766 * V_767 )
{
int V_154 ;
unsigned long V_768 = 0 , V_769 = 0 , V_770 = 0 , V_771 = 0 ;
F_114 (node) {
if ( V_30 -> V_149 ) {
V_768 = V_30 -> V_149 [ F_110 ( V_150 , V_154 , 0 ) ] ;
V_769 = V_30 -> V_149 [ F_110 ( V_150 , V_154 , 1 ) ] ;
}
if ( V_30 -> V_132 ) {
V_770 = V_30 -> V_132 -> V_151 [ F_110 ( V_150 , V_154 , 0 ) ] ,
V_771 = V_30 -> V_132 -> V_151 [ F_110 ( V_150 , V_154 , 1 ) ] ;
}
F_557 ( V_767 , V_154 , V_768 , V_769 , V_770 , V_771 ) ;
}
}
T_13 void F_558 ( void )
{
#ifdef F_216
F_559 ( V_753 , F_515 ) ;
#ifdef F_359
V_733 . V_716 = V_227 ;
F_560 ( & V_733 . V_734 , V_772 ) ;
#endif
#endif
}
