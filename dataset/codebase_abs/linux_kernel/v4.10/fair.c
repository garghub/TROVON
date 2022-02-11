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
T_2 V_43 = V_26 -> F_36 ;
if ( V_47 ) {
if ( V_47 -> V_48 )
V_43 = V_47 -> V_43 ;
else
V_47 = NULL ;
}
if ( V_26 -> V_49 ) {
struct V_28 * V_29 = F_39 ( V_26 -> V_49 ,
struct V_28 ,
V_50 ) ;
if ( ! V_47 )
V_43 = V_29 -> V_43 ;
else
V_43 = F_36 ( V_43 , V_29 -> V_43 ) ;
}
V_26 -> F_36 = F_35 ( V_26 -> F_36 , V_43 ) ;
#ifndef F_40
F_41 () ;
V_26 -> V_51 = V_26 -> F_36 ;
#endif
}
static void F_42 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_52 * * V_53 = & V_26 -> V_54 . V_52 ;
struct V_52 * V_35 = NULL ;
struct V_28 * V_55 ;
int V_56 = 1 ;
while ( * V_53 ) {
V_35 = * V_53 ;
V_55 = F_39 ( V_35 , struct V_28 , V_50 ) ;
if ( F_37 ( V_29 , V_55 ) ) {
V_53 = & V_35 -> V_57 ;
} else {
V_53 = & V_35 -> V_58 ;
V_56 = 0 ;
}
}
if ( V_56 )
V_26 -> V_49 = & V_29 -> V_50 ;
F_43 ( & V_29 -> V_50 , V_35 , V_53 ) ;
F_44 ( & V_29 -> V_50 , & V_26 -> V_54 ) ;
}
static void F_45 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_49 == & V_29 -> V_50 ) {
struct V_52 * V_59 ;
V_59 = F_46 ( & V_29 -> V_50 ) ;
V_26 -> V_49 = V_59 ;
}
F_47 ( & V_29 -> V_50 , & V_26 -> V_54 ) ;
}
struct V_28 * F_48 ( struct V_26 * V_26 )
{
struct V_52 * V_60 = V_26 -> V_49 ;
if ( ! V_60 )
return NULL ;
return F_39 ( V_60 , struct V_28 , V_50 ) ;
}
static struct V_28 * F_49 ( struct V_28 * V_29 )
{
struct V_52 * V_61 = F_46 ( & V_29 -> V_50 ) ;
if ( ! V_61 )
return NULL ;
return F_39 ( V_61 , struct V_28 , V_50 ) ;
}
struct V_28 * F_50 ( struct V_26 * V_26 )
{
struct V_52 * V_62 = F_51 ( & V_26 -> V_54 ) ;
if ( ! V_62 )
return NULL ;
return F_39 ( V_62 , struct V_28 , V_50 ) ;
}
int F_52 ( struct V_63 * V_64 , int V_65 ,
void T_4 * V_66 , T_5 * V_67 ,
T_6 * V_68 )
{
int V_69 = F_53 ( V_64 , V_65 , V_66 , V_67 , V_68 ) ;
unsigned int V_10 = F_5 () ;
if ( V_69 || ! V_65 )
return V_69 ;
V_70 = F_54 ( V_71 ,
V_72 ) ;
#define F_55 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_55 ( V_15 ) ;
F_55 ( V_16 ) ;
F_55 ( V_17 ) ;
#undef F_55
return 0 ;
}
static inline T_2 F_56 ( T_2 V_44 , struct V_28 * V_29 )
{
if ( F_14 ( V_29 -> V_73 . V_5 != V_74 ) )
V_44 = F_15 ( V_44 , V_74 , & V_29 -> V_73 ) ;
return V_44 ;
}
static T_2 F_57 ( unsigned long V_75 )
{
if ( F_14 ( V_75 > V_70 ) )
return V_75 * V_72 ;
else
return V_71 ;
}
static T_2 F_58 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
T_2 V_76 = F_57 ( V_26 -> V_75 + ! V_29 -> V_48 ) ;
F_59 (se) {
struct V_2 * V_73 ;
struct V_2 V_3 ;
V_26 = F_23 ( V_29 ) ;
V_73 = & V_26 -> V_73 ;
if ( F_14 ( ! V_29 -> V_48 ) ) {
V_3 = V_26 -> V_73 ;
F_2 ( & V_3 , V_29 -> V_73 . V_5 ) ;
V_73 = & V_3 ;
}
V_76 = F_15 ( V_76 , V_29 -> V_73 . V_5 , V_73 ) ;
}
return V_76 ;
}
static T_2 F_60 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
return F_56 ( F_58 ( V_26 , V_29 ) , V_29 ) ;
}
void F_61 ( struct V_28 * V_29 )
{
struct V_77 * V_78 = & V_29 -> V_79 ;
V_78 -> V_80 = 0 ;
V_78 -> V_81 = 1023 ;
if ( F_20 ( V_29 ) )
V_78 -> V_82 = F_13 ( V_29 -> V_73 . V_5 ) ;
V_78 -> V_83 = V_78 -> V_82 * V_84 ;
V_78 -> V_85 = 0 ;
V_78 -> V_86 = 0 ;
}
void F_62 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
struct V_77 * V_78 = & V_29 -> V_79 ;
long V_87 = ( long ) ( V_88 - V_26 -> V_79 . V_85 ) / 2 ;
if ( V_87 > 0 ) {
if ( V_26 -> V_79 . V_85 != 0 ) {
V_78 -> V_85 = V_26 -> V_79 . V_85 * V_29 -> V_73 . V_5 ;
V_78 -> V_85 /= ( V_26 -> V_79 . V_82 + 1 ) ;
if ( V_78 -> V_85 > V_87 )
V_78 -> V_85 = V_87 ;
} else {
V_78 -> V_85 = V_87 ;
}
V_78 -> V_86 = V_78 -> V_85 * V_84 ;
}
if ( F_20 ( V_29 ) ) {
struct V_27 * V_30 = F_18 ( V_29 ) ;
if ( V_30 -> V_89 != & V_90 ) {
V_29 -> V_79 . V_80 = F_63 ( V_26 ) ;
return;
}
}
F_64 ( V_29 ) ;
}
void F_61 ( struct V_28 * V_29 )
{
}
void F_62 ( struct V_28 * V_29 )
{
}
static void F_65 ( struct V_26 * V_26 , int V_91 )
{
}
static void F_66 ( struct V_26 * V_26 )
{
struct V_28 * V_47 = V_26 -> V_47 ;
T_2 V_92 = F_67 ( F_17 ( V_26 ) ) ;
T_2 V_20 ;
if ( F_14 ( ! V_47 ) )
return;
V_20 = V_92 - V_47 -> V_93 ;
if ( F_14 ( ( T_3 ) V_20 <= 0 ) )
return;
V_47 -> V_93 = V_92 ;
F_68 ( V_47 -> V_94 . V_95 ,
F_69 ( V_20 , V_47 -> V_94 . V_95 ) ) ;
V_47 -> V_96 += V_20 ;
F_70 ( V_26 -> V_97 , V_20 ) ;
V_47 -> V_43 += F_56 ( V_20 , V_47 ) ;
F_38 ( V_26 ) ;
if ( F_20 ( V_47 ) ) {
struct V_27 * V_98 = F_18 ( V_47 ) ;
F_71 ( V_98 , V_20 , V_47 -> V_43 ) ;
F_72 ( V_98 , V_20 ) ;
F_73 ( V_98 , V_20 ) ;
}
F_74 ( V_26 , V_20 ) ;
}
static void F_75 ( struct V_25 * V_25 )
{
F_66 ( F_23 ( & V_25 -> V_47 -> V_29 ) ) ;
}
static inline void
F_76 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
T_2 V_99 , V_100 ;
if ( ! F_77 () )
return;
V_99 = F_78 ( F_17 ( V_26 ) ) ;
V_100 = F_79 ( V_29 -> V_94 . V_99 ) ;
if ( F_20 ( V_29 ) && F_80 ( F_18 ( V_29 ) ) &&
F_12 ( V_99 > V_100 ) )
V_99 -= V_100 ;
F_68 ( V_29 -> V_94 . V_99 , V_99 ) ;
}
static inline void
F_81 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_27 * V_30 ;
T_2 V_44 ;
if ( ! F_77 () )
return;
V_44 = F_78 ( F_17 ( V_26 ) ) - F_79 ( V_29 -> V_94 . V_99 ) ;
if ( F_20 ( V_29 ) ) {
V_30 = F_18 ( V_29 ) ;
if ( F_80 ( V_30 ) ) {
F_68 ( V_29 -> V_94 . V_99 , V_44 ) ;
return;
}
F_82 ( V_30 , V_44 ) ;
}
F_68 ( V_29 -> V_94 . V_101 ,
F_69 ( F_79 ( V_29 -> V_94 . V_101 ) , V_44 ) ) ;
F_83 ( V_29 -> V_94 . V_102 ) ;
F_70 ( V_29 -> V_94 . V_103 , V_44 ) ;
F_68 ( V_29 -> V_94 . V_99 , 0 ) ;
}
static inline void
F_84 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_27 * V_104 = NULL ;
T_2 V_105 , V_106 ;
if ( ! F_77 () )
return;
V_105 = F_79 ( V_29 -> V_94 . V_105 ) ;
V_106 = F_79 ( V_29 -> V_94 . V_106 ) ;
if ( F_20 ( V_29 ) )
V_104 = F_18 ( V_29 ) ;
if ( V_105 ) {
T_2 V_44 = F_78 ( F_17 ( V_26 ) ) - V_105 ;
if ( ( T_3 ) V_44 < 0 )
V_44 = 0 ;
if ( F_14 ( V_44 > F_79 ( V_29 -> V_94 . V_107 ) ) )
F_68 ( V_29 -> V_94 . V_107 , V_44 ) ;
F_68 ( V_29 -> V_94 . V_105 , 0 ) ;
F_70 ( V_29 -> V_94 . V_108 , V_44 ) ;
if ( V_104 ) {
F_85 ( V_104 , V_44 >> 10 , 1 ) ;
F_86 ( V_104 , V_44 ) ;
}
}
if ( V_106 ) {
T_2 V_44 = F_78 ( F_17 ( V_26 ) ) - V_106 ;
if ( ( T_3 ) V_44 < 0 )
V_44 = 0 ;
if ( F_14 ( V_44 > F_79 ( V_29 -> V_94 . V_109 ) ) )
F_68 ( V_29 -> V_94 . V_109 , V_44 ) ;
F_68 ( V_29 -> V_94 . V_106 , 0 ) ;
F_70 ( V_29 -> V_94 . V_108 , V_44 ) ;
if ( V_104 ) {
if ( V_104 -> V_110 ) {
F_70 ( V_29 -> V_94 . V_111 , V_44 ) ;
F_83 ( V_29 -> V_94 . V_112 ) ;
F_87 ( V_104 , V_44 ) ;
}
F_88 ( V_104 , V_44 ) ;
if ( F_14 ( V_113 == V_114 ) ) {
F_89 ( V_114 ,
( void * ) F_90 ( V_104 ) ,
V_44 >> 20 ) ;
}
F_85 ( V_104 , V_44 >> 10 , 0 ) ;
}
}
}
static inline void
F_91 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
if ( ! F_77 () )
return;
if ( V_29 != V_26 -> V_47 )
F_76 ( V_26 , V_29 ) ;
if ( V_115 & V_116 )
F_84 ( V_26 , V_29 ) ;
}
static inline void
F_92 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
if ( ! F_77 () )
return;
if ( V_29 != V_26 -> V_47 )
F_81 ( V_26 , V_29 ) ;
if ( ( V_115 & V_117 ) && F_20 ( V_29 ) ) {
struct V_27 * V_104 = F_18 ( V_29 ) ;
if ( V_104 -> V_118 & V_119 )
F_68 ( V_29 -> V_94 . V_105 ,
F_78 ( F_17 ( V_26 ) ) ) ;
if ( V_104 -> V_118 & V_120 )
F_68 ( V_29 -> V_94 . V_106 ,
F_78 ( F_17 ( V_26 ) ) ) ;
}
}
static inline void
F_93 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_93 = F_67 ( F_17 ( V_26 ) ) ;
}
static unsigned int F_94 ( struct V_27 * V_30 )
{
unsigned long V_121 = 0 ;
unsigned long V_122 ;
V_122 = V_123 << ( 20 - V_124 ) ;
V_121 = F_95 ( V_30 -> V_125 ) ;
if ( ! V_121 )
V_121 = V_122 ;
V_121 = F_96 ( V_121 , V_122 ) ;
return V_121 / V_122 ;
}
static unsigned int F_97 ( struct V_27 * V_30 )
{
unsigned int V_126 = F_98 ( V_123 ) ;
unsigned int V_127 , floor ;
unsigned int V_128 = 1 ;
if ( V_126 < V_129 )
V_128 = V_129 / V_126 ;
floor = 1000 / V_128 ;
V_127 = V_130 / F_94 ( V_30 ) ;
return F_99 (unsigned int, floor, scan) ;
}
static unsigned int F_100 ( struct V_27 * V_30 )
{
unsigned int V_131 = F_97 ( V_30 ) ;
unsigned int V_132 ;
V_132 = V_133 / F_94 ( V_30 ) ;
return F_69 ( V_131 , V_132 ) ;
}
static void F_101 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
V_25 -> V_134 += ( V_30 -> V_135 != - 1 ) ;
V_25 -> V_136 += ( V_30 -> V_135 == F_102 ( V_30 ) ) ;
}
static void F_103 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
V_25 -> V_134 -= ( V_30 -> V_135 != - 1 ) ;
V_25 -> V_136 -= ( V_30 -> V_135 == F_102 ( V_30 ) ) ;
}
T_7 F_104 ( struct V_27 * V_30 )
{
return V_30 -> V_137 ? V_30 -> V_137 -> V_138 : 0 ;
}
static inline int F_105 ( enum V_139 V_140 , int V_141 , int V_142 )
{
return V_143 * ( V_140 * V_144 + V_141 ) + V_142 ;
}
static inline unsigned long F_106 ( struct V_27 * V_30 , int V_141 )
{
if ( ! V_30 -> V_145 )
return 0 ;
return V_30 -> V_145 [ F_105 ( V_146 , V_141 , 0 ) ] +
V_30 -> V_145 [ F_105 ( V_146 , V_141 , 1 ) ] ;
}
static inline unsigned long F_107 ( struct V_27 * V_30 , int V_141 )
{
if ( ! V_30 -> V_137 )
return 0 ;
return V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_141 , 0 ) ] +
V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_141 , 1 ) ] ;
}
static inline unsigned long F_108 ( struct V_137 * V_148 , int V_141 )
{
return V_148 -> V_149 [ F_105 ( V_146 , V_141 , 0 ) ] +
V_148 -> V_149 [ F_105 ( V_146 , V_141 , 1 ) ] ;
}
static bool F_109 ( int V_141 , struct V_137 * V_150 )
{
return F_108 ( V_150 , V_141 ) * V_151 > V_150 -> V_152 ;
}
static unsigned long F_110 ( struct V_27 * V_30 , int V_141 ,
int V_153 , bool V_154 )
{
unsigned long V_155 = 0 ;
int V_156 ;
if ( V_157 == V_158 )
return 0 ;
F_111 (node) {
unsigned long V_147 ;
int V_159 = F_112 ( V_141 , V_156 ) ;
if ( V_159 == V_160 || V_156 == V_141 )
continue;
if ( V_157 == V_161 &&
V_159 > V_153 )
continue;
if ( V_154 )
V_147 = F_106 ( V_30 , V_156 ) ;
else
V_147 = F_107 ( V_30 , V_156 ) ;
if ( V_157 == V_162 ) {
V_147 *= ( V_160 - V_159 ) ;
V_147 /= ( V_160 - V_163 ) ;
}
V_155 += V_147 ;
}
return V_155 ;
}
static inline unsigned long F_113 ( struct V_27 * V_30 , int V_141 ,
int V_159 )
{
unsigned long V_147 , V_164 ;
if ( ! V_30 -> V_145 )
return 0 ;
V_164 = V_30 -> V_165 ;
if ( ! V_164 )
return 0 ;
V_147 = F_106 ( V_30 , V_141 ) ;
V_147 += F_110 ( V_30 , V_141 , V_159 , true ) ;
return 1000 * V_147 / V_164 ;
}
static inline unsigned long F_114 ( struct V_27 * V_30 , int V_141 ,
int V_159 )
{
unsigned long V_147 , V_164 ;
if ( ! V_30 -> V_137 )
return 0 ;
V_164 = V_30 -> V_137 -> V_164 ;
if ( ! V_164 )
return 0 ;
V_147 = F_107 ( V_30 , V_141 ) ;
V_147 += F_110 ( V_30 , V_141 , V_159 , false ) ;
return 1000 * V_147 / V_164 ;
}
bool F_115 ( struct V_27 * V_30 , struct V_166 * V_166 ,
int V_167 , int V_168 )
{
struct V_137 * V_150 = V_30 -> V_137 ;
int V_169 = F_116 ( V_168 ) ;
int V_170 , V_171 ;
V_171 = F_117 ( V_168 , V_172 -> V_173 ) ;
V_170 = F_118 ( V_166 , V_171 ) ;
if ( ! F_119 ( V_170 ) &&
F_120 ( V_170 ) != V_169 )
return false ;
if ( F_121 ( V_30 , V_170 ) )
return true ;
if ( ! V_150 )
return true ;
if ( F_108 ( V_150 , V_169 ) > F_108 ( V_150 , V_167 ) *
V_151 )
return true ;
return F_108 ( V_150 , V_169 ) * F_107 ( V_30 , V_167 ) * 3 >
F_108 ( V_150 , V_167 ) * F_107 ( V_30 , V_169 ) * 4 ;
}
static void F_122 ( struct V_174 * V_175 , int V_141 )
{
int V_176 , V_1 , V_9 = 0 ;
unsigned long V_177 ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
F_123 (cpu, cpumask_of_node(nid)) {
struct V_25 * V_25 = F_124 ( V_1 ) ;
V_175 -> V_75 += V_25 -> V_75 ;
V_175 -> V_73 += F_125 ( V_1 ) ;
V_175 -> V_178 += F_126 ( V_1 ) ;
V_9 ++ ;
}
if ( ! V_9 )
return;
V_176 = F_54 ( V_88 * V_9 , V_175 -> V_178 ) ;
V_177 = V_9 / V_176 ;
V_175 -> V_179 = F_6 ( unsigned , V_177 ,
F_127 ( V_175 -> V_178 , V_88 ) ) ;
V_175 -> V_180 = ( V_175 -> V_75 < V_175 -> V_179 ) ;
}
static void F_128 ( struct V_181 * V_182 ,
struct V_27 * V_30 , long V_183 )
{
if ( V_182 -> V_184 )
F_129 ( V_182 -> V_184 ) ;
if ( V_30 )
F_130 ( V_30 ) ;
V_182 -> V_184 = V_30 ;
V_182 -> V_185 = V_183 ;
V_182 -> V_186 = V_182 -> V_168 ;
}
static bool F_131 ( long V_187 , long V_188 ,
struct V_181 * V_182 )
{
long V_189 , V_190 ;
long V_191 , V_192 ;
long V_193 , V_194 ;
V_193 = V_182 -> V_195 . V_178 ;
V_194 = V_182 -> V_196 . V_178 ;
if ( V_188 < V_187 )
F_132 ( V_188 , V_187 ) ;
V_189 = V_188 * V_193 * 100 -
V_187 * V_194 * V_182 -> V_197 ;
if ( V_189 <= 0 )
return false ;
V_191 = V_182 -> V_195 . V_73 ;
V_192 = V_182 -> V_196 . V_73 ;
if ( V_192 < V_191 )
F_132 ( V_192 , V_191 ) ;
V_190 = V_192 * V_193 * 100 -
V_191 * V_194 * V_182 -> V_197 ;
return ( V_189 > V_190 ) ;
}
static void F_133 ( struct V_181 * V_182 ,
long V_198 , long V_199 )
{
struct V_25 * V_200 = F_124 ( V_182 -> V_201 ) ;
struct V_25 * V_202 = F_124 ( V_182 -> V_168 ) ;
struct V_27 * V_203 ;
long V_187 , V_188 ;
long V_73 ;
long V_183 = V_182 -> V_30 -> V_137 ? V_199 : V_198 ;
long V_204 = V_183 ;
int V_159 = V_182 -> V_159 ;
F_134 () ;
V_203 = F_135 ( & V_202 -> V_47 ) ;
if ( V_203 && ( ( V_203 -> V_115 & V_205 ) || F_136 ( V_203 ) ) )
V_203 = NULL ;
if ( V_203 == V_182 -> V_30 )
goto V_206;
if ( V_203 ) {
if ( ! F_137 ( V_182 -> V_201 , F_138 ( V_203 ) ) )
goto V_206;
if ( V_203 -> V_137 == V_182 -> V_30 -> V_137 ) {
V_183 = V_198 + F_113 ( V_203 , V_182 -> V_167 , V_159 ) -
F_113 ( V_203 , V_182 -> V_169 , V_159 ) ;
if ( V_203 -> V_137 )
V_183 -= V_183 / 16 ;
} else {
if ( V_203 -> V_137 )
V_183 += F_114 ( V_203 , V_182 -> V_167 , V_159 ) -
F_114 ( V_203 , V_182 -> V_169 , V_159 ) ;
else
V_183 += F_113 ( V_203 , V_182 -> V_167 , V_159 ) -
F_113 ( V_203 , V_182 -> V_169 , V_159 ) ;
}
}
if ( V_183 <= V_182 -> V_185 && V_204 <= V_182 -> V_185 )
goto V_206;
if ( ! V_203 ) {
if ( V_182 -> V_195 . V_75 <= V_182 -> V_195 . V_179 &&
! V_182 -> V_196 . V_180 )
goto V_206;
goto V_207;
}
if ( V_183 > V_182 -> V_185 && V_200 -> V_75 == 1 &&
V_202 -> V_75 == 1 )
goto V_208;
V_207:
V_73 = F_139 ( V_182 -> V_30 ) ;
V_188 = V_182 -> V_196 . V_73 + V_73 ;
V_187 = V_182 -> V_195 . V_73 - V_73 ;
if ( V_204 > V_183 && V_204 > V_182 -> V_185 ) {
if ( ! F_131 ( V_187 , V_188 , V_182 ) ) {
V_183 = V_204 - 1 ;
V_203 = NULL ;
goto V_208;
}
}
if ( V_183 <= V_182 -> V_185 )
goto V_206;
if ( V_203 ) {
V_73 = F_139 ( V_203 ) ;
V_188 -= V_73 ;
V_187 += V_73 ;
}
if ( F_131 ( V_187 , V_188 , V_182 ) )
goto V_206;
if ( ! V_203 ) {
F_140 () ;
V_182 -> V_168 = F_141 ( V_182 -> V_30 , V_182 -> V_201 ,
V_182 -> V_168 ) ;
F_142 () ;
}
V_208:
F_128 ( V_182 , V_203 , V_183 ) ;
V_206:
F_143 () ;
}
static void F_144 ( struct V_181 * V_182 ,
long V_198 , long V_199 )
{
int V_1 ;
F_123 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_137 ( V_1 , F_138 ( V_182 -> V_30 ) ) )
continue;
V_182 -> V_168 = V_1 ;
F_133 ( V_182 , V_198 , V_199 ) ;
}
}
static bool F_145 ( struct V_181 * V_182 )
{
struct V_174 * V_209 = & V_182 -> V_195 ;
struct V_174 * V_210 = & V_182 -> V_196 ;
if ( V_209 -> V_180 && ! V_210 -> V_180 )
return false ;
if ( V_209 -> V_73 * V_210 -> V_178 * V_182 -> V_197 >
V_210 -> V_73 * V_209 -> V_178 * 100 )
return true ;
return false ;
}
static int F_146 ( struct V_27 * V_30 )
{
struct V_181 V_182 = {
. V_30 = V_30 ,
. V_201 = F_147 ( V_30 ) ,
. V_167 = F_102 ( V_30 ) ,
. V_197 = 112 ,
. V_184 = NULL ,
. V_185 = 0 ,
. V_186 = - 1 ,
} ;
struct V_211 * V_212 ;
unsigned long V_213 , V_214 ;
int V_141 , V_69 , V_159 ;
long V_198 , V_199 ;
F_134 () ;
V_212 = F_148 ( F_149 ( V_215 , V_182 . V_201 ) ) ;
if ( V_212 )
V_182 . V_197 = 100 + ( V_212 -> V_197 - 100 ) / 2 ;
F_143 () ;
if ( F_14 ( ! V_212 ) ) {
V_30 -> V_135 = F_102 ( V_30 ) ;
return - V_216 ;
}
V_182 . V_169 = V_30 -> V_135 ;
V_159 = V_182 . V_159 = F_112 ( V_182 . V_167 , V_182 . V_169 ) ;
V_213 = F_113 ( V_30 , V_182 . V_167 , V_159 ) ;
V_214 = F_114 ( V_30 , V_182 . V_167 , V_159 ) ;
F_122 ( & V_182 . V_195 , V_182 . V_167 ) ;
V_198 = F_113 ( V_30 , V_182 . V_169 , V_159 ) - V_213 ;
V_199 = F_114 ( V_30 , V_182 . V_169 , V_159 ) - V_214 ;
F_122 ( & V_182 . V_196 , V_182 . V_169 ) ;
if ( F_145 ( & V_182 ) )
F_144 ( & V_182 , V_198 , V_199 ) ;
if ( V_182 . V_186 == - 1 || ( V_30 -> V_137 && V_30 -> V_137 -> V_217 > 1 ) ) {
F_111 (nid) {
if ( V_141 == V_182 . V_167 || V_141 == V_30 -> V_135 )
continue;
V_159 = F_112 ( V_182 . V_167 , V_182 . V_169 ) ;
if ( V_157 == V_161 &&
V_159 != V_182 . V_159 ) {
V_213 = F_113 ( V_30 , V_182 . V_167 , V_159 ) ;
V_214 = F_114 ( V_30 , V_182 . V_167 , V_159 ) ;
}
V_198 = F_113 ( V_30 , V_141 , V_159 ) - V_213 ;
V_199 = F_114 ( V_30 , V_141 , V_159 ) - V_214 ;
if ( V_198 < 0 && V_199 < 0 )
continue;
V_182 . V_159 = V_159 ;
V_182 . V_169 = V_141 ;
F_122 ( & V_182 . V_196 , V_182 . V_169 ) ;
if ( F_145 ( & V_182 ) )
F_144 ( & V_182 , V_198 , V_199 ) ;
}
}
if ( V_30 -> V_137 ) {
struct V_137 * V_150 = V_30 -> V_137 ;
if ( V_182 . V_186 == - 1 )
V_141 = V_182 . V_167 ;
else
V_141 = V_182 . V_169 ;
if ( V_150 -> V_217 > 1 && F_109 ( V_182 . V_169 , V_150 ) )
F_150 ( V_30 , V_182 . V_169 ) ;
}
if ( V_182 . V_186 == - 1 )
return - V_218 ;
V_30 -> V_219 = F_97 ( V_30 ) ;
if ( V_182 . V_184 == NULL ) {
V_69 = F_151 ( V_30 , V_182 . V_186 ) ;
if ( V_69 != 0 )
F_152 ( V_30 , V_182 . V_201 , V_182 . V_186 ) ;
return V_69 ;
}
V_69 = F_153 ( V_30 , V_182 . V_184 ) ;
if ( V_69 != 0 )
F_152 ( V_30 , V_182 . V_201 , F_147 ( V_182 . V_184 ) ) ;
F_129 ( V_182 . V_184 ) ;
return V_69 ;
}
static void F_154 ( struct V_27 * V_30 )
{
unsigned long V_220 = V_221 ;
if ( F_14 ( V_30 -> V_135 == - 1 || ! V_30 -> V_145 ) )
return;
V_220 = F_155 ( V_220 , F_156 ( V_30 -> V_219 ) / 16 ) ;
V_30 -> V_222 = V_223 + V_220 ;
if ( F_102 ( V_30 ) == V_30 -> V_135 )
return;
F_146 ( V_30 ) ;
}
static void F_157 ( struct V_137 * V_137 )
{
unsigned long V_147 , V_224 = 0 ;
int V_141 , V_217 = 0 ;
F_111 (nid) {
V_147 = F_108 ( V_137 , V_141 ) ;
if ( V_147 > V_224 )
V_224 = V_147 ;
}
F_111 (nid) {
V_147 = F_108 ( V_137 , V_141 ) ;
if ( V_147 * V_151 > V_224 )
V_217 ++ ;
}
V_137 -> V_152 = V_224 ;
V_137 -> V_217 = V_217 ;
}
static void F_158 ( struct V_27 * V_30 ,
unsigned long V_225 , unsigned long V_226 )
{
unsigned int V_227 ;
int V_228 ;
int V_229 ;
unsigned long V_230 = V_30 -> V_231 [ 0 ] ;
unsigned long V_232 = V_30 -> V_231 [ 1 ] ;
if ( V_232 + V_225 == 0 || V_30 -> V_231 [ 2 ] ) {
V_30 -> V_219 = F_155 ( V_30 -> V_233 ,
V_30 -> V_219 << 1 ) ;
V_30 -> V_125 -> V_234 = V_223 +
F_156 ( V_30 -> V_219 ) ;
return;
}
V_227 = F_54 ( V_30 -> V_219 , V_235 ) ;
V_228 = ( V_232 * V_235 ) / ( V_232 + V_230 ) ;
if ( V_228 >= V_236 ) {
int V_237 = V_228 - V_236 ;
if ( ! V_237 )
V_237 = 1 ;
V_229 = V_237 * V_227 ;
} else {
V_229 = - ( V_236 - V_228 ) * V_227 ;
V_228 = F_54 ( V_226 * V_235 , ( V_226 + V_225 + 1 ) ) ;
V_229 = ( V_229 * V_228 ) / V_235 ;
}
V_30 -> V_219 = F_159 ( V_30 -> V_219 + V_229 ,
F_97 ( V_30 ) , F_100 ( V_30 ) ) ;
memset ( V_30 -> V_231 , 0 , sizeof( V_30 -> V_231 ) ) ;
}
static T_2 F_160 ( struct V_27 * V_30 , T_2 * V_238 )
{
T_2 V_239 , V_44 , V_92 ;
V_92 = V_30 -> V_29 . V_93 ;
V_239 = V_30 -> V_29 . V_96 ;
if ( V_30 -> V_240 ) {
V_44 = V_239 - V_30 -> V_241 ;
* V_238 = V_92 - V_30 -> V_240 ;
} else {
V_44 = V_30 -> V_29 . V_79 . V_83 / V_30 -> V_29 . V_73 . V_5 ;
* V_238 = V_84 ;
}
V_30 -> V_241 = V_239 ;
V_30 -> V_240 = V_92 ;
return V_44 ;
}
static int F_161 ( struct V_27 * V_30 , int V_141 )
{
T_8 V_242 ;
int V_159 ;
if ( V_157 == V_158 )
return V_141 ;
if ( V_157 == V_162 ) {
unsigned long V_155 , V_243 = 0 ;
int V_156 , V_244 = V_141 ;
V_159 = V_160 ;
F_111 (node) {
V_155 = F_114 ( V_30 , V_156 , V_159 ) ;
if ( V_155 > V_243 ) {
V_243 = V_155 ;
V_244 = V_156 ;
}
}
return V_244 ;
}
V_242 = V_245 ;
for ( V_159 = V_160 ; V_159 > V_163 ; V_159 -- ) {
unsigned long V_224 = 0 ;
T_8 V_246 = V_247 ;
int V_45 , V_46 ;
if ( ! F_162 ( V_159 ) )
continue;
F_163 (a, nodes) {
unsigned long V_147 = 0 ;
T_8 V_248 ;
F_164 ( V_248 ) ;
F_163 (b, nodes) {
if ( F_112 ( V_45 , V_46 ) < V_159 ) {
V_147 += F_107 ( V_30 , V_46 ) ;
F_165 ( V_46 , V_248 ) ;
F_166 ( V_46 , V_242 ) ;
}
}
if ( V_147 > V_224 ) {
V_224 = V_147 ;
V_246 = V_248 ;
V_141 = V_45 ;
}
}
if ( ! V_224 )
break;
V_242 = V_246 ;
}
return V_141 ;
}
static void F_167 ( struct V_27 * V_30 )
{
int V_249 , V_141 , V_250 = - 1 , V_251 = - 1 ;
unsigned long V_224 = 0 , V_252 = 0 ;
unsigned long V_253 [ 2 ] = { 0 , 0 } ;
unsigned long V_164 ;
T_2 V_239 , V_238 ;
T_9 * V_254 = NULL ;
V_249 = F_98 ( V_30 -> V_125 -> V_255 ) ;
if ( V_30 -> V_255 == V_249 )
return;
V_30 -> V_255 = V_249 ;
V_30 -> V_233 = F_100 ( V_30 ) ;
V_164 = V_30 -> V_231 [ 0 ] +
V_30 -> V_231 [ 1 ] ;
V_239 = F_160 ( V_30 , & V_238 ) ;
if ( V_30 -> V_137 ) {
V_254 = & V_30 -> V_137 -> V_256 ;
F_168 ( V_254 ) ;
}
F_111 (nid) {
int V_257 , V_258 , V_259 , V_260 ;
unsigned long V_147 = 0 , F_107 = 0 ;
int V_142 ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ ) {
long V_229 , V_261 , V_262 ;
V_257 = F_105 ( V_146 , V_141 , V_142 ) ;
V_258 = F_105 ( V_263 , V_141 , V_142 ) ;
V_259 = F_105 ( V_264 , V_141 , V_142 ) ;
V_260 = F_105 ( V_265 , V_141 , V_142 ) ;
V_229 = V_30 -> V_145 [ V_258 ] - V_30 -> V_145 [ V_257 ] / 2 ;
V_253 [ V_142 ] += V_30 -> V_145 [ V_258 ] ;
V_30 -> V_145 [ V_258 ] = 0 ;
V_262 = F_169 ( V_239 << 16 , V_238 + 1 ) ;
V_262 = ( V_262 * V_30 -> V_145 [ V_260 ] ) /
( V_164 + 1 ) ;
V_261 = V_262 - V_30 -> V_145 [ V_259 ] / 2 ;
V_30 -> V_145 [ V_260 ] = 0 ;
V_30 -> V_145 [ V_257 ] += V_229 ;
V_30 -> V_145 [ V_259 ] += V_261 ;
V_147 += V_30 -> V_145 [ V_257 ] ;
V_30 -> V_165 += V_229 ;
if ( V_30 -> V_137 ) {
V_30 -> V_137 -> V_147 [ V_257 ] += V_229 ;
V_30 -> V_137 -> V_149 [ V_257 ] += V_261 ;
V_30 -> V_137 -> V_164 += V_229 ;
F_107 += V_30 -> V_137 -> V_147 [ V_257 ] ;
}
}
if ( V_147 > V_224 ) {
V_224 = V_147 ;
V_250 = V_141 ;
}
if ( F_107 > V_252 ) {
V_252 = F_107 ;
V_251 = V_141 ;
}
}
F_158 ( V_30 , V_253 [ 0 ] , V_253 [ 1 ] ) ;
if ( V_30 -> V_137 ) {
F_157 ( V_30 -> V_137 ) ;
F_170 ( V_254 ) ;
V_250 = F_161 ( V_30 , V_251 ) ;
}
if ( V_224 ) {
if ( V_250 != V_30 -> V_135 )
F_150 ( V_30 , V_250 ) ;
if ( F_102 ( V_30 ) != V_30 -> V_135 )
F_154 ( V_30 ) ;
}
}
static inline int F_171 ( struct V_137 * V_31 )
{
return F_172 ( & V_31 -> V_266 ) ;
}
static inline void F_173 ( struct V_137 * V_31 )
{
if ( F_174 ( & V_31 -> V_266 ) )
F_175 ( V_31 , V_267 ) ;
}
static void F_176 ( struct V_27 * V_30 , int V_268 , int V_115 ,
int * V_142 )
{
struct V_137 * V_31 , * V_269 ;
struct V_27 * V_104 ;
bool V_270 = false ;
int V_1 = F_177 ( V_268 ) ;
int V_271 ;
if ( F_14 ( ! V_30 -> V_137 ) ) {
unsigned int V_272 = sizeof( struct V_137 ) +
4 * V_144 *sizeof( unsigned long ) ;
V_31 = F_178 ( V_272 , V_273 | V_274 ) ;
if ( ! V_31 )
return;
F_179 ( & V_31 -> V_266 , 1 ) ;
V_31 -> V_217 = 1 ;
V_31 -> V_152 = 0 ;
F_180 ( & V_31 -> V_256 ) ;
V_31 -> V_138 = V_30 -> V_173 ;
V_31 -> V_149 = V_31 -> V_147 + V_143 *
V_144 ;
for ( V_271 = 0 ; V_271 < V_275 * V_144 ; V_271 ++ )
V_31 -> V_147 [ V_271 ] = V_30 -> V_145 [ V_271 ] ;
V_31 -> V_164 = V_30 -> V_165 ;
V_31 -> V_276 ++ ;
F_181 ( V_30 -> V_137 , V_31 ) ;
}
F_134 () ;
V_104 = F_98 ( F_124 ( V_1 ) -> V_47 ) ;
if ( ! F_121 ( V_104 , V_268 ) )
goto V_277;
V_31 = F_148 ( V_104 -> V_137 ) ;
if ( ! V_31 )
goto V_277;
V_269 = V_30 -> V_137 ;
if ( V_31 == V_269 )
goto V_277;
if ( V_269 -> V_276 > V_31 -> V_276 )
goto V_277;
if ( V_269 -> V_276 == V_31 -> V_276 && V_269 > V_31 )
goto V_277;
if ( V_104 -> V_125 == V_172 -> V_125 )
V_270 = true ;
if ( V_115 & V_278 )
V_270 = true ;
* V_142 = ! V_270 ;
if ( V_270 && ! F_171 ( V_31 ) )
goto V_277;
F_143 () ;
if ( ! V_270 )
return;
F_182 ( F_183 () ) ;
F_184 ( & V_269 -> V_256 , & V_31 -> V_256 ) ;
for ( V_271 = 0 ; V_271 < V_275 * V_144 ; V_271 ++ ) {
V_269 -> V_147 [ V_271 ] -= V_30 -> V_145 [ V_271 ] ;
V_31 -> V_147 [ V_271 ] += V_30 -> V_145 [ V_271 ] ;
}
V_269 -> V_164 -= V_30 -> V_165 ;
V_31 -> V_164 += V_30 -> V_165 ;
V_269 -> V_276 -- ;
V_31 -> V_276 ++ ;
F_185 ( & V_269 -> V_256 ) ;
F_170 ( & V_31 -> V_256 ) ;
F_181 ( V_30 -> V_137 , V_31 ) ;
F_173 ( V_269 ) ;
return;
V_277:
F_143 () ;
return;
}
void F_186 ( struct V_27 * V_30 )
{
struct V_137 * V_31 = V_30 -> V_137 ;
void * V_145 = V_30 -> V_145 ;
unsigned long V_115 ;
int V_271 ;
if ( V_31 ) {
F_187 ( & V_31 -> V_256 , V_115 ) ;
for ( V_271 = 0 ; V_271 < V_275 * V_144 ; V_271 ++ )
V_31 -> V_147 [ V_271 ] -= V_30 -> V_145 [ V_271 ] ;
V_31 -> V_164 -= V_30 -> V_165 ;
V_31 -> V_276 -- ;
F_188 ( & V_31 -> V_256 , V_115 ) ;
F_189 ( V_30 -> V_137 , NULL ) ;
F_173 ( V_31 ) ;
}
V_30 -> V_145 = NULL ;
F_190 ( V_145 ) ;
}
void F_191 ( int V_170 , int V_279 , int V_280 , int V_115 )
{
struct V_27 * V_30 = V_172 ;
bool V_281 = V_115 & V_282 ;
int V_283 = F_102 ( V_172 ) ;
int V_232 = ! ! ( V_115 & V_284 ) ;
struct V_137 * V_150 ;
int V_142 ;
if ( ! F_192 ( & V_285 ) )
return;
if ( ! V_30 -> V_125 )
return;
if ( F_14 ( ! V_30 -> V_145 ) ) {
int V_272 = sizeof( * V_30 -> V_145 ) *
V_286 * V_144 ;
V_30 -> V_145 = F_178 ( V_272 , V_273 | V_274 ) ;
if ( ! V_30 -> V_145 )
return;
V_30 -> V_165 = 0 ;
memset ( V_30 -> V_231 , 0 , sizeof( V_30 -> V_231 ) ) ;
}
if ( F_14 ( V_170 == ( - 1 & V_287 ) ) ) {
V_142 = 1 ;
} else {
V_142 = F_121 ( V_30 , V_170 ) ;
if ( ! V_142 && ! ( V_115 & V_288 ) )
F_176 ( V_30 , V_170 , V_115 , & V_142 ) ;
}
V_150 = V_30 -> V_137 ;
if ( ! V_142 && ! V_232 && V_150 && V_150 -> V_217 > 1 &&
F_109 ( V_283 , V_150 ) &&
F_109 ( V_279 , V_150 ) )
V_232 = 1 ;
F_167 ( V_30 ) ;
if ( F_193 ( V_223 , V_30 -> V_222 ) )
F_154 ( V_30 ) ;
if ( V_281 )
V_30 -> V_289 += V_280 ;
if ( V_115 & V_290 )
V_30 -> V_231 [ 2 ] += V_280 ;
V_30 -> V_145 [ F_105 ( V_263 , V_279 , V_142 ) ] += V_280 ;
V_30 -> V_145 [ F_105 ( V_265 , V_283 , V_142 ) ] += V_280 ;
V_30 -> V_231 [ V_232 ] += V_280 ;
}
static void F_194 ( struct V_27 * V_30 )
{
F_195 ( V_30 -> V_125 -> V_255 , F_98 ( V_30 -> V_125 -> V_255 ) + 1 ) ;
V_30 -> V_125 -> V_291 = 0 ;
}
void F_196 ( struct V_292 * V_293 )
{
unsigned long V_294 , V_295 , V_92 = V_223 ;
struct V_27 * V_30 = V_172 ;
struct V_296 * V_125 = V_30 -> V_125 ;
T_2 V_239 = V_30 -> V_29 . V_96 ;
struct V_297 * V_298 ;
unsigned long V_299 , V_300 ;
unsigned long V_301 = 0 ;
long V_280 , V_302 ;
F_19 ( V_30 != F_21 ( V_293 , struct V_27 , V_303 ) ) ;
V_293 -> V_61 = V_293 ;
if ( V_30 -> V_115 & V_205 )
return;
if ( ! V_125 -> V_234 ) {
V_125 -> V_234 = V_92 +
F_156 ( V_304 ) ;
}
V_294 = V_125 -> V_234 ;
if ( F_197 ( V_92 , V_294 ) )
return;
if ( V_30 -> V_219 == 0 ) {
V_30 -> V_233 = F_100 ( V_30 ) ;
V_30 -> V_219 = F_97 ( V_30 ) ;
}
V_295 = V_92 + F_156 ( V_30 -> V_219 ) ;
if ( F_198 ( & V_125 -> V_234 , V_294 , V_295 ) != V_294 )
return;
V_30 -> V_305 += 2 * V_306 ;
V_299 = V_125 -> V_291 ;
V_280 = V_123 ;
V_280 <<= 20 - V_124 ;
V_302 = V_280 * 8 ;
if ( ! V_280 )
return;
F_199 ( & V_125 -> V_307 ) ;
V_298 = F_200 ( V_125 , V_299 ) ;
if ( ! V_298 ) {
F_194 ( V_30 ) ;
V_299 = 0 ;
V_298 = V_125 -> V_308 ;
}
for (; V_298 ; V_298 = V_298 -> V_309 ) {
if ( ! F_201 ( V_298 ) || ! F_202 ( V_298 ) ||
F_203 ( V_298 ) || ( V_298 -> V_310 & V_311 ) ) {
continue;
}
if ( ! V_298 -> V_312 ||
( V_298 -> V_313 && ( V_298 -> V_310 & ( V_314 | V_315 ) ) == ( V_314 ) ) )
continue;
if ( ! ( V_298 -> V_310 & ( V_314 | V_316 | V_315 ) ) )
continue;
do {
V_299 = F_69 ( V_299 , V_298 -> V_317 ) ;
V_300 = F_204 ( V_299 + ( V_280 << V_124 ) , V_318 ) ;
V_300 = F_155 ( V_300 , V_298 -> V_319 ) ;
V_301 = F_205 ( V_298 , V_299 , V_300 ) ;
if ( V_301 )
V_280 -= ( V_300 - V_299 ) >> V_124 ;
V_302 -= ( V_300 - V_299 ) >> V_124 ;
V_299 = V_300 ;
if ( V_280 <= 0 || V_302 <= 0 )
goto V_320;
F_206 () ;
} while ( V_300 != V_298 -> V_319 );
}
V_320:
if ( V_298 )
V_125 -> V_291 = V_299 ;
else
F_194 ( V_30 ) ;
F_207 ( & V_125 -> V_307 ) ;
if ( F_14 ( V_30 -> V_29 . V_96 != V_239 ) ) {
T_2 V_229 = V_30 -> V_29 . V_96 - V_239 ;
V_30 -> V_305 += 32 * V_229 ;
}
}
void F_208 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
struct V_292 * V_293 = & V_47 -> V_303 ;
T_2 V_238 , V_92 ;
if ( ! V_47 -> V_125 || ( V_47 -> V_115 & V_205 ) || V_293 -> V_61 != V_293 )
return;
V_92 = V_47 -> V_29 . V_96 ;
V_238 = ( T_2 ) V_47 -> V_219 * V_321 ;
if ( V_92 > V_47 -> V_305 + V_238 ) {
if ( ! V_47 -> V_305 )
V_47 -> V_219 = F_97 ( V_47 ) ;
V_47 -> V_305 += V_238 ;
if ( ! F_197 ( V_223 , V_47 -> V_125 -> V_234 ) ) {
F_209 ( V_293 , F_196 ) ;
F_210 ( V_47 , V_293 , true ) ;
}
}
}
static void F_208 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
}
static inline void F_101 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_103 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static void
F_211 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_2 ( & V_26 -> V_73 , V_29 -> V_73 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_2 ( & F_17 ( V_26 ) -> V_73 , V_29 -> V_73 . V_5 ) ;
#ifdef F_212
if ( F_20 ( V_29 ) ) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
F_101 ( V_25 , F_18 ( V_29 ) ) ;
F_213 ( & V_29 -> V_322 , & V_25 -> V_323 ) ;
}
#endif
V_26 -> V_75 ++ ;
}
static void
F_214 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_3 ( & V_26 -> V_73 , V_29 -> V_73 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_3 ( & F_17 ( V_26 ) -> V_73 , V_29 -> V_73 . V_5 ) ;
#ifdef F_212
if ( F_20 ( V_29 ) ) {
F_103 ( F_17 ( V_26 ) , F_18 ( V_29 ) ) ;
F_215 ( & V_29 -> V_322 ) ;
}
#endif
V_26 -> V_75 -- ;
}
static long F_216 ( struct V_26 * V_26 , struct V_324 * V_34 )
{
long V_325 , V_73 , V_326 ;
V_73 = F_13 ( V_26 -> V_73 . V_5 ) ;
V_325 = F_217 ( & V_34 -> V_82 ) ;
V_325 -= V_26 -> V_327 ;
V_325 += V_73 ;
V_326 = ( V_34 -> V_326 * V_73 ) ;
if ( V_325 )
V_326 /= V_325 ;
if ( V_326 < V_328 )
V_326 = V_328 ;
if ( V_326 > V_34 -> V_326 )
V_326 = V_34 -> V_326 ;
return V_326 ;
}
static inline long F_216 ( struct V_26 * V_26 , struct V_324 * V_34 )
{
return V_34 -> V_326 ;
}
static void F_218 ( struct V_26 * V_26 , struct V_28 * V_29 ,
unsigned long V_5 )
{
if ( V_29 -> V_48 ) {
if ( V_26 -> V_47 == V_29 )
F_66 ( V_26 ) ;
F_214 ( V_26 , V_29 ) ;
}
F_4 ( & V_29 -> V_73 , V_5 ) ;
if ( V_29 -> V_48 )
F_211 ( V_26 , V_29 ) ;
}
static void F_219 ( struct V_26 * V_26 )
{
struct V_324 * V_34 ;
struct V_28 * V_29 ;
long V_326 ;
V_34 = V_26 -> V_34 ;
V_29 = V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
if ( ! V_29 || F_220 ( V_26 ) )
return;
#ifndef F_212
if ( F_12 ( V_29 -> V_73 . V_5 == V_34 -> V_326 ) )
return;
#endif
V_326 = F_216 ( V_26 , V_34 ) ;
F_218 ( F_23 ( V_29 ) , V_29 , V_326 ) ;
}
static inline void F_219 ( struct V_26 * V_26 )
{
}
static T_10 T_2 F_221 ( T_2 V_329 , T_2 V_330 )
{
unsigned int V_331 ;
if ( ! V_330 )
return V_329 ;
else if ( F_14 ( V_330 > V_332 * 63 ) )
return 0 ;
V_331 = V_330 ;
if ( F_14 ( V_331 >= V_332 ) ) {
V_329 >>= V_331 / V_332 ;
V_331 %= V_332 ;
}
V_329 = F_16 ( V_329 , V_333 [ V_331 ] , 32 ) ;
return V_329 ;
}
static V_24 F_222 ( T_2 V_330 )
{
V_24 V_334 = 0 ;
if ( F_12 ( V_330 <= V_332 ) )
return V_335 [ V_330 ] ;
else if ( F_14 ( V_330 >= V_336 ) )
return V_84 ;
V_334 = V_337 [ V_330 / V_332 ] ;
V_330 %= V_332 ;
V_334 = F_221 ( V_334 , V_330 ) ;
return V_334 + V_335 [ V_330 ] ;
}
static T_10 int
F_223 ( T_2 V_92 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_338 , struct V_26 * V_26 )
{
T_2 V_44 , V_339 , V_340 ;
V_24 V_334 ;
unsigned int V_341 , V_342 , V_343 = 0 ;
unsigned long V_344 , V_345 ;
V_44 = V_92 - V_78 -> V_80 ;
if ( ( T_3 ) V_44 < 0 ) {
V_78 -> V_80 = V_92 ;
return 0 ;
}
V_44 >>= 10 ;
if ( ! V_44 )
return 0 ;
V_78 -> V_80 = V_92 ;
V_344 = F_224 ( NULL , V_1 ) ;
V_345 = F_225 ( NULL , V_1 ) ;
V_341 = V_78 -> V_81 ;
if ( V_44 + V_341 >= 1024 ) {
V_343 = 1 ;
V_78 -> V_81 = 0 ;
V_341 = 1024 - V_341 ;
V_342 = F_226 ( V_341 , V_344 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_342 ;
if ( V_26 ) {
V_26 -> V_346 +=
V_5 * V_342 ;
}
}
if ( V_338 )
V_78 -> V_86 += V_342 * V_345 ;
V_44 -= V_341 ;
V_340 = V_44 / 1024 ;
V_44 %= 1024 ;
V_78 -> V_83 = F_221 ( V_78 -> V_83 , V_340 + 1 ) ;
if ( V_26 ) {
V_26 -> V_346 =
F_221 ( V_26 -> V_346 , V_340 + 1 ) ;
}
V_78 -> V_86 = F_221 ( ( T_2 ) ( V_78 -> V_86 ) , V_340 + 1 ) ;
V_334 = F_222 ( V_340 ) ;
V_334 = F_226 ( V_334 , V_344 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_334 ;
if ( V_26 )
V_26 -> V_346 += V_5 * V_334 ;
}
if ( V_338 )
V_78 -> V_86 += V_334 * V_345 ;
}
V_339 = F_226 ( V_44 , V_344 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_339 ;
if ( V_26 )
V_26 -> V_346 += V_5 * V_339 ;
}
if ( V_338 )
V_78 -> V_86 += V_339 * V_345 ;
V_78 -> V_81 += V_44 ;
if ( V_343 ) {
V_78 -> V_82 = F_227 ( V_78 -> V_83 , V_84 ) ;
if ( V_26 ) {
V_26 -> V_347 =
F_227 ( V_26 -> V_346 , V_84 ) ;
}
V_78 -> V_85 = V_78 -> V_86 / V_84 ;
}
return V_343 ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 )
{
long V_44 = V_26 -> V_79 . V_82 - V_26 -> V_327 ;
if ( V_26 -> V_34 == & V_348 )
return;
if ( V_91 || abs ( V_44 ) > V_26 -> V_327 / 64 ) {
F_228 ( V_44 , & V_26 -> V_34 -> V_82 ) ;
V_26 -> V_327 = V_26 -> V_79 . V_82 ;
}
}
void F_229 ( struct V_28 * V_29 ,
struct V_26 * V_349 , struct V_26 * V_61 )
{
if ( ! F_230 ( V_350 ) )
return;
if ( V_29 -> V_79 . V_80 && V_349 ) {
T_2 V_351 ;
T_2 V_352 ;
#ifndef F_40
T_2 V_353 ;
T_2 V_354 ;
do {
V_353 = V_349 -> V_355 ;
V_354 = V_61 -> V_355 ;
F_231 () ;
V_351 = V_349 -> V_79 . V_80 ;
V_352 = V_61 -> V_79 . V_80 ;
} while ( V_351 != V_353 ||
V_352 != V_354 );
#else
V_351 = V_349 -> V_79 . V_80 ;
V_352 = V_61 -> V_79 . V_80 ;
#endif
F_223 ( V_351 , F_26 ( F_17 ( V_349 ) ) ,
& V_29 -> V_79 , 0 , 0 , NULL ) ;
V_29 -> V_79 . V_80 = V_352 ;
}
}
static inline void
F_232 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_356 = F_24 ( V_29 ) ;
long V_44 = V_356 -> V_79 . V_85 - V_29 -> V_79 . V_85 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_85 = V_356 -> V_79 . V_85 ;
V_29 -> V_79 . V_86 = V_29 -> V_79 . V_85 * V_84 ;
F_233 ( & V_26 -> V_79 . V_85 , V_44 ) ;
V_26 -> V_79 . V_86 = V_26 -> V_79 . V_85 * V_84 ;
}
static inline void
F_234 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_356 = F_24 ( V_29 ) ;
long V_44 , V_73 = V_356 -> V_79 . V_82 ;
if ( V_73 ) {
long V_357 ;
V_357 = F_217 ( & V_356 -> V_34 -> V_82 ) + 1 ;
V_357 -= V_356 -> V_327 ;
V_357 += V_73 ;
if ( V_357 > F_13 ( V_356 -> V_34 -> V_326 ) ) {
V_73 *= F_13 ( V_356 -> V_34 -> V_326 ) ;
V_73 /= V_357 ;
}
}
V_44 = V_73 - V_29 -> V_79 . V_82 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_82 = V_73 ;
V_29 -> V_79 . V_83 = V_29 -> V_79 . V_82 * V_84 ;
F_233 ( & V_26 -> V_79 . V_82 , V_44 ) ;
V_26 -> V_79 . V_83 = V_26 -> V_79 . V_82 * V_84 ;
if ( V_29 -> V_48 ) {
F_233 ( & V_26 -> V_347 , V_44 ) ;
V_26 -> V_346 = V_26 -> V_347 * V_84 ;
}
}
static inline void F_235 ( struct V_26 * V_26 )
{
V_26 -> V_358 = 1 ;
}
static inline int F_236 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
if ( ! V_26 -> V_358 )
return 0 ;
V_26 -> V_358 = 0 ;
return 1 ;
}
static inline int F_237 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
if ( F_20 ( V_29 ) )
return 0 ;
if ( ! F_236 ( V_29 ) )
return 0 ;
V_26 = F_23 ( V_29 ) ;
F_235 ( V_26 ) ;
F_232 ( V_26 , V_29 ) ;
F_234 ( V_26 , V_29 ) ;
return 1 ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 ) {}
static inline int F_237 ( struct V_28 * V_29 )
{
return 0 ;
}
static inline void F_235 ( struct V_26 * V_26 ) {}
static inline void F_238 ( struct V_26 * V_26 )
{
if ( & F_239 () -> V_42 == V_26 ) {
F_240 ( F_17 ( V_26 ) , 0 ) ;
}
}
static inline int
F_241 ( T_2 V_92 , struct V_26 * V_26 , bool V_359 )
{
struct V_77 * V_78 = & V_26 -> V_79 ;
int V_343 , V_360 = 0 , V_361 = 0 ;
if ( F_217 ( & V_26 -> V_362 ) ) {
T_3 V_363 = F_242 ( & V_26 -> V_362 , 0 ) ;
F_243 ( & V_78 -> V_82 , V_363 ) ;
F_243 ( & V_78 -> V_83 , V_363 * V_84 ) ;
V_360 = 1 ;
F_235 ( V_26 ) ;
}
if ( F_217 ( & V_26 -> V_364 ) ) {
long V_363 = F_242 ( & V_26 -> V_364 , 0 ) ;
F_243 ( & V_78 -> V_85 , V_363 ) ;
F_243 ( & V_78 -> V_86 , V_363 * V_84 ) ;
V_361 = 1 ;
F_235 ( V_26 ) ;
}
V_343 = F_223 ( V_92 , F_26 ( F_17 ( V_26 ) ) , V_78 ,
F_13 ( V_26 -> V_73 . V_5 ) , V_26 -> V_47 != NULL , V_26 ) ;
#ifndef F_40
F_41 () ;
V_26 -> V_355 = V_78 -> V_80 ;
#endif
if ( V_359 && ( V_343 || V_361 ) )
F_238 ( V_26 ) ;
return V_343 || V_360 ;
}
static inline void F_244 ( struct V_28 * V_29 , int V_115 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_92 = F_63 ( V_26 ) ;
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
int V_343 ;
if ( V_29 -> V_79 . V_80 && ! ( V_115 & V_365 ) ) {
F_223 ( V_92 , V_1 , & V_29 -> V_79 ,
V_29 -> V_48 * F_13 ( V_29 -> V_73 . V_5 ) ,
V_26 -> V_47 == V_29 , NULL ) ;
}
V_343 = F_241 ( V_92 , V_26 , true ) ;
V_343 |= F_237 ( V_29 ) ;
if ( V_343 && ( V_115 & V_366 ) )
F_65 ( V_26 , 0 ) ;
}
static void F_245 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_79 . V_80 = V_26 -> V_79 . V_80 ;
V_26 -> V_79 . V_82 += V_29 -> V_79 . V_82 ;
V_26 -> V_79 . V_83 += V_29 -> V_79 . V_83 ;
V_26 -> V_79 . V_85 += V_29 -> V_79 . V_85 ;
V_26 -> V_79 . V_86 += V_29 -> V_79 . V_86 ;
F_235 ( V_26 ) ;
F_238 ( V_26 ) ;
}
static void F_246 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_243 ( & V_26 -> V_79 . V_82 , V_29 -> V_79 . V_82 ) ;
F_243 ( & V_26 -> V_79 . V_83 , V_29 -> V_79 . V_83 ) ;
F_243 ( & V_26 -> V_79 . V_85 , V_29 -> V_79 . V_85 ) ;
F_243 ( & V_26 -> V_79 . V_86 , V_29 -> V_79 . V_86 ) ;
F_235 ( V_26 ) ;
F_238 ( V_26 ) ;
}
static inline void
F_247 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_77 * V_78 = & V_29 -> V_79 ;
V_26 -> V_347 += V_78 -> V_82 ;
V_26 -> V_346 += V_78 -> V_83 ;
if ( ! V_78 -> V_80 ) {
F_245 ( V_26 , V_29 ) ;
F_65 ( V_26 , 0 ) ;
}
}
static inline void
F_248 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_26 -> V_347 =
F_99 ( long , V_26 -> V_347 - V_29 -> V_79 . V_82 , 0 ) ;
V_26 -> V_346 =
F_99 ( T_3 , V_26 -> V_346 - V_29 -> V_79 . V_83 , 0 ) ;
}
static inline T_2 F_249 ( struct V_26 * V_26 )
{
T_2 V_367 ;
T_2 V_80 ;
do {
V_367 = V_26 -> V_355 ;
F_231 () ;
V_80 = V_26 -> V_79 . V_80 ;
} while ( V_80 != V_367 );
return V_80 ;
}
static inline T_2 F_249 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_80 ;
}
void F_250 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_80 ;
V_80 = F_249 ( V_26 ) ;
F_223 ( V_80 , F_26 ( F_17 ( V_26 ) ) , & V_29 -> V_79 , 0 , 0 , NULL ) ;
}
void F_251 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_250 ( V_29 ) ;
F_228 ( V_29 -> V_79 . V_82 , & V_26 -> V_362 ) ;
F_228 ( V_29 -> V_79 . V_85 , & V_26 -> V_364 ) ;
}
static inline unsigned long F_252 ( struct V_26 * V_26 )
{
return V_26 -> V_347 ;
}
static inline unsigned long F_253 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_82 ;
}
static inline int
F_241 ( T_2 V_92 , struct V_26 * V_26 , bool V_359 )
{
return 0 ;
}
static inline void F_244 ( struct V_28 * V_29 , int V_368 )
{
F_240 ( F_17 ( F_23 ( V_29 ) ) , 0 ) ;
}
static inline void
F_247 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_248 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void F_251 ( struct V_28 * V_29 ) {}
static inline void
F_245 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_246 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline int F_254 ( struct V_25 * V_25 )
{
return 0 ;
}
static void F_255 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
#ifdef F_256
T_3 V_369 = V_29 -> V_43 - V_26 -> F_36 ;
if ( V_369 < 0 )
V_369 = - V_369 ;
if ( V_369 > 3 * V_71 )
F_83 ( V_26 -> V_370 ) ;
#endif
}
static void
F_257 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_371 )
{
T_2 V_43 = V_26 -> F_36 ;
if ( V_371 && F_230 ( V_372 ) )
V_43 += F_60 ( V_26 , V_29 ) ;
if ( ! V_371 ) {
unsigned long V_373 = V_71 ;
if ( F_230 ( V_374 ) )
V_373 >>= 1 ;
V_43 -= V_373 ;
}
V_29 -> V_43 = F_35 ( V_29 -> V_43 , V_43 ) ;
}
static inline void F_258 ( void )
{
#ifdef F_259
if ( F_77 () )
return;
if ( F_260 () ||
F_261 () ||
F_262 () ||
F_263 () ||
F_264 () ) {
F_265 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_266 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
bool V_375 = ! ( V_115 & V_116 ) || ( V_115 & V_376 ) ;
bool V_47 = V_26 -> V_47 == V_29 ;
if ( V_375 && V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_66 ( V_26 ) ;
if ( V_375 && ! V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_244 ( V_29 , V_366 ) ;
F_247 ( V_26 , V_29 ) ;
F_211 ( V_26 , V_29 ) ;
F_219 ( V_26 ) ;
if ( V_115 & V_116 )
F_257 ( V_26 , V_29 , 0 ) ;
F_258 () ;
F_91 ( V_26 , V_29 , V_115 ) ;
F_255 ( V_26 , V_29 ) ;
if ( ! V_47 )
F_42 ( V_26 , V_29 ) ;
V_29 -> V_48 = 1 ;
if ( V_26 -> V_75 == 1 ) {
F_25 ( V_26 ) ;
F_267 ( V_26 ) ;
}
}
static void F_268 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_62 != V_29 )
break;
V_26 -> V_62 = NULL ;
}
}
static void F_269 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_61 != V_29 )
break;
V_26 -> V_61 = NULL ;
}
}
static void F_270 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_377 != V_29 )
break;
V_26 -> V_377 = NULL ;
}
}
static void F_271 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_62 == V_29 )
F_268 ( V_29 ) ;
if ( V_26 -> V_61 == V_29 )
F_269 ( V_29 ) ;
if ( V_26 -> V_377 == V_29 )
F_270 ( V_29 ) ;
}
static void
F_272 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
F_66 ( V_26 ) ;
F_244 ( V_29 , V_366 ) ;
F_248 ( V_26 , V_29 ) ;
F_92 ( V_26 , V_29 , V_115 ) ;
F_271 ( V_26 , V_29 ) ;
if ( V_29 != V_26 -> V_47 )
F_45 ( V_26 , V_29 ) ;
V_29 -> V_48 = 0 ;
F_214 ( V_26 , V_29 ) ;
if ( ! ( V_115 & V_117 ) )
V_29 -> V_43 -= V_26 -> F_36 ;
F_273 ( V_26 ) ;
F_219 ( V_26 ) ;
if ( ( V_115 & ( V_378 | V_379 ) ) == V_378 )
F_38 ( V_26 ) ;
}
static void
F_274 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
unsigned long V_380 , V_20 ;
struct V_28 * V_29 ;
T_3 V_44 ;
V_380 = F_58 ( V_26 , V_47 ) ;
V_20 = V_47 -> V_96 - V_47 -> V_381 ;
if ( V_20 > V_380 ) {
F_275 ( F_17 ( V_26 ) ) ;
F_271 ( V_26 , V_47 ) ;
return;
}
if ( V_20 < V_72 )
return;
V_29 = F_48 ( V_26 ) ;
V_44 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_44 < 0 )
return;
if ( V_44 > V_380 )
F_275 ( F_17 ( V_26 ) ) ;
}
static void
F_276 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_29 -> V_48 ) {
F_81 ( V_26 , V_29 ) ;
F_45 ( V_26 , V_29 ) ;
F_244 ( V_29 , V_366 ) ;
}
F_93 ( V_26 , V_29 ) ;
V_26 -> V_47 = V_29 ;
if ( F_77 () && F_17 ( V_26 ) -> V_73 . V_5 >= 2 * V_29 -> V_73 . V_5 ) {
F_68 ( V_29 -> V_94 . V_382 ,
F_69 ( ( T_2 ) F_79 ( V_29 -> V_94 . V_382 ) ,
V_29 -> V_96 - V_29 -> V_381 ) ) ;
}
V_29 -> V_381 = V_29 -> V_96 ;
}
static struct V_28 *
F_277 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
struct V_28 * V_60 = F_48 ( V_26 ) ;
struct V_28 * V_29 ;
if ( ! V_60 || ( V_47 && F_37 ( V_47 , V_60 ) ) )
V_60 = V_47 ;
V_29 = V_60 ;
if ( V_26 -> V_377 == V_29 ) {
struct V_28 * V_383 ;
if ( V_29 == V_47 ) {
V_383 = F_48 ( V_26 ) ;
} else {
V_383 = F_49 ( V_29 ) ;
if ( ! V_383 || ( V_47 && F_37 ( V_47 , V_383 ) ) )
V_383 = V_47 ;
}
if ( V_383 && F_278 ( V_383 , V_60 ) < 1 )
V_29 = V_383 ;
}
if ( V_26 -> V_62 && F_278 ( V_26 -> V_62 , V_60 ) < 1 )
V_29 = V_26 -> V_62 ;
if ( V_26 -> V_61 && F_278 ( V_26 -> V_61 , V_60 ) < 1 )
V_29 = V_26 -> V_61 ;
F_271 ( V_26 , V_29 ) ;
return V_29 ;
}
static void F_279 ( struct V_26 * V_26 , struct V_28 * V_349 )
{
if ( V_349 -> V_48 )
F_66 ( V_26 ) ;
F_280 ( V_26 ) ;
F_255 ( V_26 , V_349 ) ;
if ( V_349 -> V_48 ) {
F_76 ( V_26 , V_349 ) ;
F_42 ( V_26 , V_349 ) ;
F_244 ( V_349 , 0 ) ;
}
V_26 -> V_47 = NULL ;
}
static void
F_281 ( struct V_26 * V_26 , struct V_28 * V_47 , int V_384 )
{
F_66 ( V_26 ) ;
F_244 ( V_47 , V_366 ) ;
F_219 ( V_26 ) ;
#ifdef F_282
if ( V_384 ) {
F_275 ( F_17 ( V_26 ) ) ;
return;
}
if ( ! F_230 ( V_385 ) &&
F_283 ( & F_17 ( V_26 ) -> V_386 ) )
return;
#endif
if ( V_26 -> V_75 > 1 )
F_274 ( V_26 , V_47 ) ;
}
static inline bool F_284 ( void )
{
return F_285 ( & V_387 ) ;
}
void F_286 ( void )
{
F_287 ( & V_387 ) ;
}
void F_288 ( void )
{
F_289 ( & V_387 ) ;
}
static bool F_284 ( void )
{
return true ;
}
void F_286 ( void ) {}
void F_288 ( void ) {}
static inline T_2 F_290 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_291 ( void )
{
return ( T_2 ) V_388 * V_389 ;
}
void F_292 ( struct V_390 * V_391 )
{
T_2 V_92 ;
if ( V_391 -> V_392 == V_393 )
return;
V_92 = F_293 ( F_294 () ) ;
V_391 -> V_239 = V_391 -> V_392 ;
V_391 -> V_394 = V_92 + F_295 ( V_391 -> V_238 ) ;
}
static inline struct V_390 * F_296 ( struct V_324 * V_34 )
{
return & V_34 -> V_390 ;
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
if ( F_14 ( V_26 -> V_395 ) )
return V_26 -> V_396 - V_26 -> V_397 ;
return F_67 ( F_17 ( V_26 ) ) - V_26 -> V_397 ;
}
static int F_297 ( struct V_26 * V_26 )
{
struct V_324 * V_34 = V_26 -> V_34 ;
struct V_390 * V_391 = F_296 ( V_34 ) ;
T_2 V_398 = 0 , V_399 , V_400 ;
V_399 = F_291 () - V_26 -> V_401 ;
F_298 ( & V_391 -> V_256 ) ;
if ( V_391 -> V_392 == V_393 )
V_398 = V_399 ;
else {
F_299 ( V_391 ) ;
if ( V_391 -> V_239 > 0 ) {
V_398 = F_155 ( V_391 -> V_239 , V_399 ) ;
V_391 -> V_239 -= V_398 ;
V_391 -> V_402 = 0 ;
}
}
V_400 = V_391 -> V_394 ;
F_300 ( & V_391 -> V_256 ) ;
V_26 -> V_401 += V_398 ;
if ( ( T_3 ) ( V_400 - V_26 -> V_394 ) > 0 )
V_26 -> V_394 = V_400 ;
return V_26 -> V_401 > 0 ;
}
static void F_301 ( struct V_26 * V_26 )
{
struct V_390 * V_391 = F_296 ( V_26 -> V_34 ) ;
if ( F_12 ( ( T_3 ) ( F_78 ( F_17 ( V_26 ) ) - V_26 -> V_394 ) < 0 ) )
return;
if ( V_26 -> V_401 < 0 )
return;
if ( V_26 -> V_394 != V_391 -> V_394 ) {
V_26 -> V_394 += V_306 ;
} else {
V_26 -> V_401 = 0 ;
}
}
static void F_302 ( struct V_26 * V_26 , T_2 V_20 )
{
V_26 -> V_401 -= V_20 ;
F_301 ( V_26 ) ;
if ( F_12 ( V_26 -> V_401 > 0 ) )
return;
if ( ! F_297 ( V_26 ) && F_12 ( V_26 -> V_47 ) )
F_275 ( F_17 ( V_26 ) ) ;
}
static T_10
void F_74 ( struct V_26 * V_26 , T_2 V_20 )
{
if ( ! F_284 () || ! V_26 -> V_403 )
return;
F_302 ( V_26 , V_20 ) ;
}
static inline int F_303 ( struct V_26 * V_26 )
{
return F_284 () && V_26 -> V_404 ;
}
static inline int F_220 ( struct V_26 * V_26 )
{
return F_284 () && V_26 -> V_395 ;
}
static inline int F_304 ( struct V_324 * V_34 ,
int V_201 , int V_405 )
{
struct V_26 * V_406 , * V_407 ;
V_406 = V_34 -> V_26 [ V_201 ] ;
V_407 = V_34 -> V_26 [ V_405 ] ;
return F_220 ( V_406 ) ||
F_220 ( V_407 ) ;
}
static int F_305 ( struct V_324 * V_34 , void * V_408 )
{
struct V_25 * V_25 = V_408 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
V_26 -> V_395 -- ;
if ( ! V_26 -> V_395 ) {
V_26 -> V_397 += F_67 ( V_25 ) -
V_26 -> V_396 ;
}
return 0 ;
}
static int F_306 ( struct V_324 * V_34 , void * V_408 )
{
struct V_25 * V_25 = V_408 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_395 )
V_26 -> V_396 = F_67 ( V_25 ) ;
V_26 -> V_395 ++ ;
return 0 ;
}
static void F_307 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_390 * V_391 = F_296 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
long V_409 , V_410 = 1 ;
bool V_411 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
F_134 () ;
F_308 ( V_26 -> V_34 , F_306 , V_412 , ( void * ) V_25 ) ;
F_143 () ;
V_409 = V_26 -> V_413 ;
F_59 (se) {
struct V_26 * V_414 = F_23 ( V_29 ) ;
if ( ! V_29 -> V_48 )
break;
if ( V_410 )
F_272 ( V_414 , V_29 , V_117 ) ;
V_414 -> V_413 -= V_409 ;
if ( V_414 -> V_73 . V_5 )
V_410 = 0 ;
}
if ( ! V_29 )
F_309 ( V_25 , V_409 ) ;
V_26 -> V_404 = 1 ;
V_26 -> V_415 = F_78 ( V_25 ) ;
F_298 ( & V_391 -> V_256 ) ;
V_411 = F_310 ( & V_391 -> V_416 ) ;
F_28 ( & V_26 -> V_417 , & V_391 -> V_416 ) ;
if ( V_411 )
F_299 ( V_391 ) ;
F_300 ( & V_391 -> V_256 ) ;
}
void F_311 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_390 * V_391 = F_296 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
int V_418 = 1 ;
long V_409 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
V_26 -> V_404 = 0 ;
F_312 ( V_25 ) ;
F_298 ( & V_391 -> V_256 ) ;
V_391 -> V_419 += F_78 ( V_25 ) - V_26 -> V_415 ;
F_30 ( & V_26 -> V_417 ) ;
F_300 ( & V_391 -> V_256 ) ;
F_308 ( V_26 -> V_34 , V_412 , F_305 , ( void * ) V_25 ) ;
if ( ! V_26 -> V_73 . V_5 )
return;
V_409 = V_26 -> V_413 ;
F_59 (se) {
if ( V_29 -> V_48 )
V_418 = 0 ;
V_26 = F_23 ( V_29 ) ;
if ( V_418 )
F_266 ( V_26 , V_29 , V_116 ) ;
V_26 -> V_413 += V_409 ;
if ( F_303 ( V_26 ) )
break;
}
if ( ! V_29 )
F_313 ( V_25 , V_409 ) ;
if ( V_25 -> V_47 == V_25 -> V_402 && V_25 -> V_42 . V_75 )
F_275 ( V_25 ) ;
}
static T_2 F_314 ( struct V_390 * V_391 ,
T_2 V_420 , T_2 V_400 )
{
struct V_26 * V_26 ;
T_2 V_239 ;
T_2 V_421 = V_420 ;
F_134 () ;
F_315 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
F_298 ( & V_25 -> V_256 ) ;
if ( ! F_303 ( V_26 ) )
goto V_61;
V_239 = - V_26 -> V_401 + 1 ;
if ( V_239 > V_420 )
V_239 = V_420 ;
V_420 -= V_239 ;
V_26 -> V_401 += V_239 ;
V_26 -> V_394 = V_400 ;
if ( V_26 -> V_401 > 0 )
F_311 ( V_26 ) ;
V_61:
F_300 ( & V_25 -> V_256 ) ;
if ( ! V_420 )
break;
}
F_143 () ;
return V_421 - V_420 ;
}
static int F_316 ( struct V_390 * V_391 , int V_422 )
{
T_2 V_239 , V_394 ;
int V_404 ;
if ( V_391 -> V_392 == V_393 )
goto V_423;
V_404 = ! F_310 ( & V_391 -> V_416 ) ;
V_391 -> V_424 += V_422 ;
if ( V_391 -> V_402 && ! V_404 )
goto V_423;
F_292 ( V_391 ) ;
if ( ! V_404 ) {
V_391 -> V_402 = 1 ;
return 0 ;
}
V_391 -> V_425 += V_422 ;
V_394 = V_391 -> V_394 ;
while ( V_404 && V_391 -> V_239 > 0 ) {
V_239 = V_391 -> V_239 ;
F_300 ( & V_391 -> V_256 ) ;
V_239 = F_314 ( V_391 , V_239 ,
V_394 ) ;
F_298 ( & V_391 -> V_256 ) ;
V_404 = ! F_310 ( & V_391 -> V_416 ) ;
V_391 -> V_239 -= F_155 ( V_239 , V_391 -> V_239 ) ;
}
V_391 -> V_402 = 0 ;
return 0 ;
V_423:
return 1 ;
}
static int F_317 ( struct V_390 * V_391 , T_2 V_426 )
{
struct V_427 * V_428 = & V_391 -> V_429 ;
T_2 V_420 ;
if ( F_318 ( V_428 ) )
return 1 ;
V_420 = F_295 ( F_319 ( V_428 ) ) ;
if ( V_420 < V_426 )
return 1 ;
return 0 ;
}
static void F_320 ( struct V_390 * V_391 )
{
T_2 V_430 = V_431 + V_432 ;
if ( F_317 ( V_391 , V_430 ) )
return;
F_321 ( & V_391 -> V_433 ,
F_322 ( V_431 ) ,
V_434 ) ;
}
static void F_323 ( struct V_26 * V_26 )
{
struct V_390 * V_391 = F_296 ( V_26 -> V_34 ) ;
T_3 V_435 = V_26 -> V_401 - V_436 ;
if ( V_435 <= 0 )
return;
F_298 ( & V_391 -> V_256 ) ;
if ( V_391 -> V_392 != V_393 &&
V_26 -> V_394 == V_391 -> V_394 ) {
V_391 -> V_239 += V_435 ;
if ( V_391 -> V_239 > F_291 () &&
! F_310 ( & V_391 -> V_416 ) )
F_320 ( V_391 ) ;
}
F_300 ( & V_391 -> V_256 ) ;
V_26 -> V_401 -= V_435 ;
}
static T_10 void F_273 ( struct V_26 * V_26 )
{
if ( ! F_284 () )
return;
if ( ! V_26 -> V_403 || V_26 -> V_75 )
return;
F_323 ( V_26 ) ;
}
static void F_324 ( struct V_390 * V_391 )
{
T_2 V_239 = 0 , V_76 = F_291 () ;
T_2 V_400 ;
F_298 ( & V_391 -> V_256 ) ;
if ( F_317 ( V_391 , V_432 ) ) {
F_300 ( & V_391 -> V_256 ) ;
return;
}
if ( V_391 -> V_392 != V_393 && V_391 -> V_239 > V_76 )
V_239 = V_391 -> V_239 ;
V_400 = V_391 -> V_394 ;
F_300 ( & V_391 -> V_256 ) ;
if ( ! V_239 )
return;
V_239 = F_314 ( V_391 , V_239 , V_400 ) ;
F_298 ( & V_391 -> V_256 ) ;
if ( V_400 == V_391 -> V_394 )
V_391 -> V_239 -= F_155 ( V_239 , V_391 -> V_239 ) ;
F_300 ( & V_391 -> V_256 ) ;
}
static void F_267 ( struct V_26 * V_26 )
{
if ( ! F_284 () )
return;
if ( ! V_26 -> V_403 || V_26 -> V_47 )
return;
if ( F_303 ( V_26 ) )
return;
F_74 ( V_26 , 0 ) ;
if ( V_26 -> V_401 <= 0 )
F_307 ( V_26 ) ;
}
static void F_325 ( struct V_324 * V_34 , int V_1 )
{
struct V_26 * V_437 , * V_26 ;
if ( ! F_284 () )
return;
if ( ! V_34 -> V_35 )
return;
V_26 = V_34 -> V_26 [ V_1 ] ;
V_437 = V_34 -> V_35 -> V_26 [ V_1 ] ;
V_26 -> V_395 = V_437 -> V_395 ;
V_26 -> V_396 = F_67 ( F_124 ( V_1 ) ) ;
}
static bool F_280 ( struct V_26 * V_26 )
{
if ( ! F_284 () )
return false ;
if ( F_12 ( ! V_26 -> V_403 || V_26 -> V_401 > 0 ) )
return false ;
if ( F_303 ( V_26 ) )
return true ;
F_307 ( V_26 ) ;
return true ;
}
static enum V_438 F_326 ( struct V_427 * V_439 )
{
struct V_390 * V_391 =
F_21 ( V_439 , struct V_390 , V_433 ) ;
F_324 ( V_391 ) ;
return V_440 ;
}
static enum V_438 F_327 ( struct V_427 * V_439 )
{
struct V_390 * V_391 =
F_21 ( V_439 , struct V_390 , V_429 ) ;
int V_422 ;
int V_402 = 0 ;
F_298 ( & V_391 -> V_256 ) ;
for (; ; ) {
V_422 = F_328 ( V_439 , V_391 -> V_238 ) ;
if ( ! V_422 )
break;
V_402 = F_316 ( V_391 , V_422 ) ;
}
if ( V_402 )
V_391 -> V_441 = 0 ;
F_300 ( & V_391 -> V_256 ) ;
return V_402 ? V_440 : V_442 ;
}
void F_329 ( struct V_390 * V_391 )
{
F_330 ( & V_391 -> V_256 ) ;
V_391 -> V_239 = 0 ;
V_391 -> V_392 = V_393 ;
V_391 -> V_238 = F_322 ( F_290 () ) ;
F_331 ( & V_391 -> V_416 ) ;
F_332 ( & V_391 -> V_429 , V_443 , V_444 ) ;
V_391 -> V_429 . V_445 = F_327 ;
F_332 ( & V_391 -> V_433 , V_443 , V_434 ) ;
V_391 -> V_433 . V_445 = F_326 ;
}
static void F_333 ( struct V_26 * V_26 )
{
V_26 -> V_403 = 0 ;
F_331 ( & V_26 -> V_417 ) ;
}
void F_299 ( struct V_390 * V_391 )
{
F_334 ( & V_391 -> V_256 ) ;
if ( ! V_391 -> V_441 ) {
V_391 -> V_441 = 1 ;
F_328 ( & V_391 -> V_429 , V_391 -> V_238 ) ;
F_335 ( & V_391 -> V_429 , V_444 ) ;
}
}
static void F_336 ( struct V_390 * V_391 )
{
if ( ! V_391 -> V_416 . V_61 )
return;
F_337 ( & V_391 -> V_429 ) ;
F_337 ( & V_391 -> V_433 ) ;
}
static void T_11 F_338 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_339 (rq, cfs_rq) {
struct V_390 * V_391 = & V_26 -> V_34 -> V_390 ;
F_298 ( & V_391 -> V_256 ) ;
V_26 -> V_403 = V_391 -> V_392 != V_393 ;
F_300 ( & V_391 -> V_256 ) ;
}
}
static void T_11 F_340 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_339 (rq, cfs_rq) {
if ( ! V_26 -> V_403 )
continue;
V_26 -> V_401 = 1 ;
V_26 -> V_403 = 0 ;
if ( F_303 ( V_26 ) )
F_311 ( V_26 ) ;
}
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
return F_67 ( F_17 ( V_26 ) ) ;
}
static void F_74 ( struct V_26 * V_26 , T_2 V_20 ) {}
static bool F_280 ( struct V_26 * V_26 ) { return false ; }
static void F_267 ( struct V_26 * V_26 ) {}
static inline void F_325 ( struct V_324 * V_34 , int V_1 ) {}
static T_10 void F_273 ( struct V_26 * V_26 ) {}
static inline int F_303 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_220 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_304 ( struct V_324 * V_34 ,
int V_201 , int V_405 )
{
return 0 ;
}
void F_329 ( struct V_390 * V_391 ) {}
static void F_333 ( struct V_26 * V_26 ) {}
static inline struct V_390 * F_296 ( struct V_324 * V_34 )
{
return NULL ;
}
static inline void F_336 ( struct V_390 * V_391 ) {}
static inline void F_338 ( struct V_25 * V_25 ) {}
static inline void F_340 ( struct V_25 * V_25 ) {}
static void F_341 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_19 ( F_34 ( V_30 ) != V_25 ) ;
if ( V_25 -> V_42 . V_413 > 1 ) {
T_2 V_76 = F_58 ( V_26 , V_29 ) ;
T_2 V_446 = V_29 -> V_96 - V_29 -> V_381 ;
T_3 V_44 = V_76 - V_446 ;
if ( V_44 < 0 ) {
if ( V_25 -> V_47 == V_30 )
F_275 ( V_25 ) ;
return;
}
F_342 ( V_25 , V_44 ) ;
}
}
static void F_343 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
if ( ! F_344 ( V_25 ) || V_47 -> V_89 != & V_90 )
return;
if ( F_23 ( & V_47 -> V_29 ) -> V_75 < V_70 )
F_341 ( V_25 , V_47 ) ;
}
static inline void
F_341 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_343 ( struct V_25 * V_25 )
{
}
static void
F_345 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_110 )
F_346 ( V_25 , V_447 ) ;
F_59 (se) {
if ( V_29 -> V_48 )
break;
V_26 = F_23 ( V_29 ) ;
F_266 ( V_26 , V_29 , V_115 ) ;
if ( F_303 ( V_26 ) )
break;
V_26 -> V_413 ++ ;
V_115 = V_116 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_413 ++ ;
if ( F_303 ( V_26 ) )
break;
F_244 ( V_29 , V_366 ) ;
F_219 ( V_26 ) ;
}
if ( ! V_29 )
F_313 ( V_25 , 1 ) ;
F_343 ( V_25 ) ;
}
static void F_347 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
int V_448 = V_115 & V_117 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_272 ( V_26 , V_29 , V_115 ) ;
if ( F_303 ( V_26 ) )
break;
V_26 -> V_413 -- ;
if ( V_26 -> V_73 . V_5 ) {
V_29 = F_32 ( V_29 ) ;
if ( V_448 && V_29 && ! F_220 ( V_26 ) )
F_348 ( V_29 ) ;
break;
}
V_115 |= V_117 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_413 -- ;
if ( F_303 ( V_26 ) )
break;
F_244 ( V_29 , V_366 ) ;
F_219 ( V_26 ) ;
}
if ( ! V_29 )
F_309 ( V_25 , 1 ) ;
F_343 ( V_25 ) ;
}
static unsigned long
F_349 ( unsigned long V_73 , unsigned long V_449 , int V_450 )
{
int V_451 = 0 ;
if ( ! V_449 )
return V_73 ;
if ( V_449 >= V_452 [ V_450 ] )
return 0 ;
if ( V_450 == 1 )
return V_73 >> V_449 ;
while ( V_449 ) {
if ( V_449 % 2 )
V_73 = ( V_73 * V_453 [ V_450 ] [ V_451 ] ) >> V_454 ;
V_449 >>= 1 ;
V_451 ++ ;
}
return V_73 ;
}
static void F_350 ( struct V_25 * F_239 , unsigned long V_455 ,
unsigned long V_456 )
{
unsigned long T_11 V_457 = F_239 -> V_458 [ 0 ] ;
int V_271 , V_459 ;
F_239 -> V_460 ++ ;
F_239 -> V_458 [ 0 ] = V_455 ;
for ( V_271 = 1 , V_459 = 2 ; V_271 < V_461 ; V_271 ++ , V_459 += V_459 ) {
unsigned long V_462 , V_463 ;
V_462 = F_239 -> V_458 [ V_271 ] ;
#ifdef F_351
V_462 = F_349 ( V_462 , V_456 - 1 , V_271 ) ;
if ( V_457 ) {
V_462 -= F_349 ( V_457 , V_456 - 1 , V_271 ) ;
V_462 += V_457 ;
}
#endif
V_463 = V_455 ;
if ( V_463 > V_462 )
V_463 += V_459 - 1 ;
F_239 -> V_458 [ V_271 ] = ( V_462 * ( V_459 - 1 ) + V_463 ) >> V_271 ;
}
F_352 ( F_239 ) ;
}
static unsigned long F_125 ( const int V_1 )
{
return F_252 ( & F_124 ( V_1 ) -> V_42 ) ;
}
static void F_353 ( struct V_25 * F_239 ,
unsigned long V_464 ,
unsigned long V_73 )
{
unsigned long V_456 ;
V_456 = V_464 - F_239 -> V_465 ;
if ( V_456 ) {
F_239 -> V_465 = V_464 ;
F_350 ( F_239 , V_73 , V_456 ) ;
}
}
static void F_354 ( struct V_25 * F_239 )
{
if ( F_125 ( F_26 ( F_239 ) ) )
return;
F_353 ( F_239 , F_98 ( V_223 ) , 0 ) ;
}
void F_355 ( void )
{
struct V_25 * F_239 = F_239 () ;
F_239 -> V_458 [ 0 ] = F_125 ( F_26 ( F_239 ) ) ;
}
void F_356 ( void )
{
unsigned long V_464 = F_98 ( V_223 ) ;
struct V_25 * F_239 = F_239 () ;
unsigned long V_73 ;
if ( V_464 == F_239 -> V_465 )
return;
V_73 = F_125 ( F_26 ( F_239 ) ) ;
F_298 ( & F_239 -> V_256 ) ;
F_312 ( F_239 ) ;
F_353 ( F_239 , V_464 , V_73 ) ;
F_300 ( & F_239 -> V_256 ) ;
}
static inline void F_353 ( struct V_25 * F_239 ,
unsigned long V_464 ,
unsigned long V_73 ) { }
static void F_357 ( struct V_25 * F_239 , unsigned long V_73 )
{
#ifdef F_351
F_239 -> V_465 = F_98 ( V_223 ) ;
#endif
F_350 ( F_239 , V_73 , 1 ) ;
}
void F_358 ( struct V_25 * F_239 )
{
unsigned long V_73 = F_125 ( F_26 ( F_239 ) ) ;
if ( F_359 () )
F_353 ( F_239 , F_98 ( V_223 ) , V_73 ) ;
else
F_357 ( F_239 , V_73 ) ;
}
static unsigned long F_360 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_466 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_230 ( V_467 ) )
return V_466 ;
return F_155 ( V_25 -> V_458 [ type - 1 ] , V_466 ) ;
}
static unsigned long F_361 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_466 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_230 ( V_467 ) )
return V_466 ;
return F_69 ( V_25 -> V_458 [ type - 1 ] , V_466 ) ;
}
static unsigned long F_126 ( int V_1 )
{
return F_124 ( V_1 ) -> V_468 ;
}
static unsigned long F_362 ( int V_1 )
{
return F_124 ( V_1 ) -> V_469 ;
}
static unsigned long F_363 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_75 = F_98 ( V_25 -> V_42 . V_413 ) ;
unsigned long V_82 = F_125 ( V_1 ) ;
if ( V_75 )
return V_82 / V_75 ;
return 0 ;
}
static long F_364 ( struct V_324 * V_34 , int V_1 , long V_470 , long V_471 )
{
struct V_28 * V_29 = V_34 -> V_29 [ V_1 ] ;
if ( ! V_34 -> V_35 )
return V_470 ;
F_59 (se) {
struct V_26 * V_26 = V_29 -> V_32 ;
long V_472 , V_8 = F_253 ( V_26 ) ;
V_34 = V_26 -> V_34 ;
V_472 = V_471 + F_217 ( & V_34 -> V_82 ) ;
V_472 -= V_26 -> V_327 ;
V_472 += V_8 ;
V_8 += V_470 ;
if ( V_472 > 0 && V_8 < V_472 )
V_470 = ( V_8 * ( long ) F_13 ( V_34 -> V_326 ) ) / V_472 ;
else
V_470 = F_13 ( V_34 -> V_326 ) ;
if ( V_470 < V_328 )
V_470 = V_328 ;
V_470 -= V_29 -> V_79 . V_82 ;
V_471 = 0 ;
}
return V_470 ;
}
static long F_364 ( struct V_324 * V_34 , int V_1 , long V_470 , long V_471 )
{
return V_470 ;
}
static void F_365 ( struct V_27 * V_30 )
{
if ( F_193 ( V_223 , V_172 -> V_473 + V_221 ) ) {
V_172 -> V_474 >>= 1 ;
V_172 -> V_473 = V_223 ;
}
if ( V_172 -> V_475 != V_30 ) {
V_172 -> V_475 = V_30 ;
V_172 -> V_474 ++ ;
}
}
static int F_366 ( struct V_27 * V_30 )
{
unsigned int V_476 = V_172 -> V_474 ;
unsigned int V_477 = V_30 -> V_474 ;
int V_10 = F_367 ( V_478 ) ;
if ( V_476 < V_477 )
F_132 ( V_476 , V_477 ) ;
if ( V_477 < V_10 || V_476 < V_477 * V_10 )
return 0 ;
return 1 ;
}
static int F_368 ( struct V_211 * V_212 , struct V_27 * V_30 ,
int V_479 , int V_480 )
{
T_3 V_455 , V_73 ;
T_3 V_481 , V_482 ;
int V_450 , V_483 ;
struct V_324 * V_34 ;
unsigned long V_5 ;
int V_484 ;
V_450 = V_212 -> V_485 ;
V_483 = F_294 () ;
V_73 = F_360 ( V_479 , V_450 ) ;
V_455 = F_361 ( V_483 , V_450 ) ;
if ( V_480 ) {
V_34 = V_324 ( V_172 ) ;
V_5 = V_172 -> V_29 . V_79 . V_82 ;
V_455 += F_364 ( V_34 , V_483 , - V_5 , - V_5 ) ;
V_73 += F_364 ( V_34 , V_479 , 0 , - V_5 ) ;
}
V_34 = V_324 ( V_30 ) ;
V_5 = V_30 -> V_29 . V_79 . V_82 ;
V_481 = 100 ;
V_481 *= F_126 ( V_479 ) ;
V_482 = 100 + ( V_212 -> V_197 - 100 ) / 2 ;
V_482 *= F_126 ( V_483 ) ;
if ( V_455 > 0 ) {
V_481 *= V_455 +
F_364 ( V_34 , V_483 , V_5 , V_5 ) ;
V_482 *= V_73 + F_364 ( V_34 , V_479 , 0 , V_5 ) ;
}
V_484 = V_481 <= V_482 ;
F_83 ( V_30 -> V_29 . V_94 . V_486 ) ;
if ( ! V_484 )
return 0 ;
F_83 ( V_212 -> V_487 ) ;
F_83 ( V_30 -> V_29 . V_94 . V_488 ) ;
return 1 ;
}
static unsigned long F_369 ( int V_1 , struct V_27 * V_30 )
{
return F_362 ( V_1 ) - F_370 ( V_1 , V_30 ) ;
}
static struct V_489 *
F_371 ( struct V_211 * V_212 , struct V_27 * V_30 ,
int V_483 , int V_490 )
{
struct V_489 * V_491 = NULL , * V_148 = V_212 -> V_492 ;
struct V_489 * V_493 = NULL ;
unsigned long V_494 = V_495 , V_496 = 0 ;
unsigned long V_497 = V_495 , V_498 = 0 ;
unsigned long V_499 = 0 , V_500 = 0 ;
int V_501 = V_212 -> V_502 ;
int V_503 = 100 + ( V_212 -> V_197 - 100 ) / 2 ;
unsigned long V_504 = F_13 ( V_74 ) *
( V_212 -> V_197 - 100 ) / 100 ;
if ( V_490 & V_505 )
V_501 = V_212 -> V_485 ;
do {
unsigned long V_73 , V_506 , V_507 ;
unsigned long V_508 , V_509 ;
int V_510 ;
int V_271 ;
if ( ! F_372 ( F_373 ( V_148 ) ,
F_138 ( V_30 ) ) )
continue;
V_510 = F_137 ( V_483 ,
F_373 ( V_148 ) ) ;
V_506 = 0 ;
V_507 = 0 ;
V_509 = 0 ;
F_123 (i, sched_group_cpus(group)) {
if ( V_510 )
V_73 = F_360 ( V_271 , V_501 ) ;
else
V_73 = F_361 ( V_271 , V_501 ) ;
V_507 += V_73 ;
V_506 += F_253 ( & F_124 ( V_271 ) -> V_42 ) ;
V_508 = F_369 ( V_271 , V_30 ) ;
if ( V_508 > V_509 )
V_509 = V_508 ;
}
V_506 = ( V_506 * V_88 ) /
V_148 -> V_511 -> V_177 ;
V_507 = ( V_507 * V_88 ) /
V_148 -> V_511 -> V_177 ;
if ( V_510 ) {
V_496 = V_507 ;
V_498 = V_506 ;
V_500 = V_509 ;
} else {
if ( V_494 > ( V_507 + V_504 ) ) {
V_494 = V_507 ;
V_497 = V_506 ;
V_491 = V_148 ;
} else if ( ( V_507 < ( V_494 + V_504 ) ) &&
( 100 * V_497 > V_503 * V_506 ) ) {
V_497 = V_506 ;
V_491 = V_148 ;
}
if ( V_499 < V_509 ) {
V_499 = V_509 ;
V_493 = V_148 ;
}
}
} while ( V_148 = V_148 -> V_61 , V_148 != V_212 -> V_492 );
if ( V_490 & V_512 )
goto V_513;
if ( V_500 > F_374 ( V_30 ) / 2 &&
V_503 * V_500 > 100 * V_499 )
return NULL ;
if ( V_499 > F_374 ( V_30 ) / 2 )
return V_493 ;
V_513:
if ( ! V_491 )
return NULL ;
if ( V_494 > ( V_496 + V_504 ) )
return NULL ;
if ( ( V_496 < ( V_494 + V_504 ) ) &&
( 100 * V_498 < V_503 * V_497 ) )
return NULL ;
return V_491 ;
}
static int
F_375 ( struct V_489 * V_148 , struct V_27 * V_30 , int V_483 )
{
unsigned long V_73 , V_514 = V_495 ;
unsigned int V_515 = V_516 ;
T_2 V_517 = 0 ;
int V_518 = V_483 ;
int V_519 = - 1 ;
int V_271 ;
if ( V_148 -> F_114 == 1 )
return F_376 ( F_373 ( V_148 ) ) ;
F_377 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if ( F_378 ( V_271 ) ) {
struct V_25 * V_25 = F_124 ( V_271 ) ;
struct V_520 * V_402 = F_379 ( V_25 ) ;
if ( V_402 && V_402 -> V_521 < V_515 ) {
V_515 = V_402 -> V_521 ;
V_517 = V_25 -> V_522 ;
V_519 = V_271 ;
} else if ( ( ! V_402 || V_402 -> V_521 == V_515 ) &&
V_25 -> V_522 > V_517 ) {
V_517 = V_25 -> V_522 ;
V_519 = V_271 ;
}
} else if ( V_519 == - 1 ) {
V_73 = F_125 ( V_271 ) ;
if ( V_73 < V_514 || ( V_73 == V_514 && V_271 == V_483 ) ) {
V_514 = V_73 ;
V_518 = V_271 ;
}
}
}
return V_519 != - 1 ? V_519 : V_518 ;
}
static int F_380 ( int V_330 , const struct V_523 * V_524 , int V_299 , int * V_525 )
{
int V_61 ;
V_526:
V_61 = F_381 ( F_382 ( V_524 ) , V_527 , V_330 + 1 ) ;
if ( * V_525 ) {
if ( V_61 >= V_299 )
return V_527 ;
} else {
if ( V_61 >= V_527 ) {
* V_525 = 1 ;
V_330 = - 1 ;
goto V_526;
}
}
return V_61 ;
}
static inline void F_383 ( int V_1 , int V_329 )
{
struct V_528 * V_529 ;
V_529 = F_148 ( F_149 ( V_530 , V_1 ) ) ;
if ( V_529 )
F_195 ( V_529 -> V_531 , V_329 ) ;
}
static inline bool F_384 ( int V_1 , bool V_532 )
{
struct V_528 * V_529 ;
V_529 = F_148 ( F_149 ( V_530 , V_1 ) ) ;
if ( V_529 )
return F_98 ( V_529 -> V_531 ) ;
return V_532 ;
}
void F_385 ( struct V_25 * V_25 )
{
int V_533 = F_26 ( V_25 ) ;
int V_1 ;
F_134 () ;
if ( F_384 ( V_533 , true ) )
goto V_206;
F_123 (cpu, cpu_smt_mask(core)) {
if ( V_1 == V_533 )
continue;
if ( ! F_378 ( V_1 ) )
goto V_206;
}
F_383 ( V_533 , 1 ) ;
V_206:
F_143 () ;
}
static int F_386 ( struct V_27 * V_30 , struct V_211 * V_212 , int V_534 )
{
struct V_523 * V_9 = F_387 ( V_535 ) ;
int V_533 , V_1 , V_536 ;
if ( ! F_192 ( & V_537 ) )
return - 1 ;
if ( ! F_384 ( V_534 , false ) )
return - 1 ;
F_388 ( V_9 , F_389 ( V_212 ) , F_138 ( V_30 ) ) ;
F_390 (core, cpus, target, wrap) {
bool V_402 = true ;
F_123 (cpu, cpu_smt_mask(core)) {
F_391 ( V_1 , V_9 ) ;
if ( ! F_378 ( V_1 ) )
V_402 = false ;
}
if ( V_402 )
return V_533 ;
}
F_383 ( V_534 , 0 ) ;
return - 1 ;
}
static int F_392 ( struct V_27 * V_30 , struct V_211 * V_212 , int V_534 )
{
int V_1 ;
if ( ! F_192 ( & V_537 ) )
return - 1 ;
F_123 (cpu, cpu_smt_mask(target)) {
if ( ! F_137 ( V_1 , F_138 ( V_30 ) ) )
continue;
if ( F_378 ( V_1 ) )
return V_1 ;
}
return - 1 ;
}
static inline int F_386 ( struct V_27 * V_30 , struct V_211 * V_212 , int V_534 )
{
return - 1 ;
}
static inline int F_392 ( struct V_27 * V_30 , struct V_211 * V_212 , int V_534 )
{
return - 1 ;
}
static int F_393 ( struct V_27 * V_30 , struct V_211 * V_212 , int V_534 )
{
struct V_211 * V_538 ;
T_2 V_539 , V_540 = F_239 () -> V_540 ;
T_2 time , V_541 ;
T_3 V_44 ;
int V_1 , V_536 ;
V_538 = F_148 ( * F_394 ( & V_542 ) ) ;
if ( ! V_538 )
return - 1 ;
V_539 = V_538 -> V_543 ;
if ( ( V_540 / 512 ) < V_539 )
return - 1 ;
time = F_395 () ;
F_390 (cpu, sched_domain_span(sd), target, wrap) {
if ( ! F_137 ( V_1 , F_138 ( V_30 ) ) )
continue;
if ( F_378 ( V_1 ) )
break;
}
time = F_395 () - time ;
V_541 = V_538 -> V_543 ;
V_44 = ( T_3 ) ( time - V_541 ) / 8 ;
V_538 -> V_543 += V_44 ;
return V_1 ;
}
static int F_141 ( struct V_27 * V_30 , int V_349 , int V_534 )
{
struct V_211 * V_212 ;
int V_271 ;
if ( F_378 ( V_534 ) )
return V_534 ;
if ( V_349 != V_534 && F_396 ( V_349 , V_534 ) && F_378 ( V_349 ) )
return V_349 ;
V_212 = F_148 ( F_149 ( V_542 , V_534 ) ) ;
if ( ! V_212 )
return V_534 ;
V_271 = F_386 ( V_30 , V_212 , V_534 ) ;
if ( ( unsigned ) V_271 < V_527 )
return V_271 ;
V_271 = F_393 ( V_30 , V_212 , V_534 ) ;
if ( ( unsigned ) V_271 < V_527 )
return V_271 ;
V_271 = F_392 ( V_30 , V_212 , V_534 ) ;
if ( ( unsigned ) V_271 < V_527 )
return V_271 ;
return V_534 ;
}
static int F_397 ( int V_1 )
{
unsigned long V_544 = F_124 ( V_1 ) -> V_42 . V_79 . V_85 ;
unsigned long V_177 = F_362 ( V_1 ) ;
return ( V_544 >= V_177 ) ? V_177 : V_544 ;
}
static inline int F_374 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_85 ;
}
static int F_370 ( int V_1 , struct V_27 * V_30 )
{
unsigned long V_544 , V_177 ;
if ( V_1 != F_147 ( V_30 ) || ! V_30 -> V_29 . V_79 . V_80 )
return F_397 ( V_1 ) ;
V_177 = F_362 ( V_1 ) ;
V_544 = F_99 ( long , F_124 ( V_1 ) -> V_42 . V_79 . V_85 - F_374 ( V_30 ) , 0 ) ;
return ( V_544 >= V_177 ) ? V_177 : V_544 ;
}
static int F_398 ( struct V_27 * V_30 , int V_1 , int V_479 )
{
long V_545 , V_546 ;
V_545 = F_155 ( F_362 ( V_479 ) , F_362 ( V_1 ) ) ;
V_546 = F_124 ( V_1 ) -> V_547 -> V_548 ;
if ( V_546 - V_545 < V_546 > > 3 )
return 0 ;
F_250 ( & V_30 -> V_29 ) ;
return V_545 * 1024 < F_374 ( V_30 ) * V_549 ;
}
static int
F_399 ( struct V_27 * V_30 , int V_479 , int V_490 , int V_550 )
{
struct V_211 * V_551 , * V_552 = NULL , * V_212 = NULL ;
int V_1 = F_294 () ;
int V_553 = V_479 ;
int V_554 = 0 ;
int V_480 = V_550 & V_555 ;
if ( V_490 & V_505 ) {
F_365 ( V_30 ) ;
V_554 = ! F_366 ( V_30 ) && ! F_398 ( V_30 , V_1 , V_479 )
&& F_137 ( V_1 , F_138 ( V_30 ) ) ;
}
F_134 () ;
F_400 (cpu, tmp) {
if ( ! ( V_551 -> V_115 & V_556 ) )
break;
if ( V_554 && ( V_551 -> V_115 & V_557 ) &&
F_137 ( V_479 , F_389 ( V_551 ) ) ) {
V_552 = V_551 ;
break;
}
if ( V_551 -> V_115 & V_490 )
V_212 = V_551 ;
else if ( ! V_554 )
break;
}
if ( V_552 ) {
V_212 = NULL ;
if ( V_1 != V_479 && F_368 ( V_552 , V_30 , V_479 , V_480 ) )
V_553 = V_1 ;
}
if ( ! V_212 ) {
if ( V_490 & V_505 )
V_553 = F_141 ( V_30 , V_479 , V_553 ) ;
} else while ( V_212 ) {
struct V_489 * V_148 ;
int V_5 ;
if ( ! ( V_212 -> V_115 & V_490 ) ) {
V_212 = V_212 -> V_558 ;
continue;
}
V_148 = F_371 ( V_212 , V_30 , V_1 , V_490 ) ;
if ( ! V_148 ) {
V_212 = V_212 -> V_558 ;
continue;
}
V_553 = F_375 ( V_148 , V_30 , V_1 ) ;
if ( V_553 == - 1 || V_553 == V_1 ) {
V_212 = V_212 -> V_558 ;
continue;
}
V_1 = V_553 ;
V_5 = V_212 -> V_559 ;
V_212 = NULL ;
F_400 (cpu, tmp) {
if ( V_5 <= V_551 -> V_559 )
break;
if ( V_551 -> V_115 & V_490 )
V_212 = V_551 ;
}
}
F_143 () ;
return V_553 ;
}
static void F_401 ( struct V_27 * V_30 )
{
if ( V_30 -> V_118 == V_560 ) {
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_51 ;
do {
V_51 = V_26 -> V_51 ;
F_231 () ;
F_36 = V_26 -> F_36 ;
} while ( F_36 != V_51 );
#else
F_36 = V_26 -> F_36 ;
#endif
V_29 -> V_43 -= F_36 ;
}
F_251 ( & V_30 -> V_29 ) ;
V_30 -> V_29 . V_79 . V_80 = 0 ;
V_30 -> V_29 . V_93 = 0 ;
}
static void F_402 ( struct V_27 * V_30 )
{
F_251 ( & V_30 -> V_29 ) ;
}
static unsigned long
F_403 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
unsigned long V_561 = V_562 ;
return F_56 ( V_561 , V_29 ) ;
}
static int
F_278 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
T_3 V_561 , V_563 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_563 <= 0 )
return - 1 ;
V_561 = F_403 ( V_47 , V_29 ) ;
if ( V_563 > V_561 )
return 1 ;
return 0 ;
}
static void F_404 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_564 == V_565 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_62 = V_29 ;
}
static void F_348 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_564 == V_565 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_61 = V_29 ;
}
static void F_405 ( struct V_28 * V_29 )
{
F_59 (se)
F_23 ( V_29 ) -> V_377 = V_29 ;
}
static void F_406 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_550 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_28 * V_29 = & V_47 -> V_29 , * V_38 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
int V_459 = V_26 -> V_75 >= V_70 ;
int V_566 = 0 ;
if ( F_14 ( V_29 == V_38 ) )
return;
if ( F_14 ( F_220 ( F_23 ( V_38 ) ) ) )
return;
if ( F_230 ( V_567 ) && V_459 && ! ( V_550 & V_568 ) ) {
F_348 ( V_38 ) ;
V_566 = 1 ;
}
if ( F_407 ( V_47 ) )
return;
if ( F_14 ( V_47 -> V_564 == V_565 ) &&
F_12 ( V_30 -> V_564 != V_565 ) )
goto V_569;
if ( F_14 ( V_30 -> V_564 != V_570 ) || ! F_230 ( V_571 ) )
return;
F_33 ( & V_29 , & V_38 ) ;
F_66 ( F_23 ( V_29 ) ) ;
F_182 ( ! V_38 ) ;
if ( F_278 ( V_29 , V_38 ) == 1 ) {
if ( ! V_566 )
F_348 ( V_38 ) ;
goto V_569;
}
return;
V_569:
F_275 ( V_25 ) ;
if ( F_14 ( ! V_29 -> V_48 || V_47 == V_25 -> V_402 ) )
return;
if ( F_230 ( V_572 ) && V_459 && F_20 ( V_29 ) )
F_404 ( V_29 ) ;
}
static struct V_27 *
F_408 ( struct V_25 * V_25 , struct V_27 * V_349 , struct V_573 V_574 )
{
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_28 * V_29 ;
struct V_27 * V_30 ;
int V_575 ;
V_526:
#ifdef F_409
if ( ! V_26 -> V_75 )
goto V_402;
if ( V_349 -> V_89 != & V_90 )
goto V_576;
do {
struct V_28 * V_47 = V_26 -> V_47 ;
if ( V_47 ) {
if ( V_47 -> V_48 )
F_66 ( V_26 ) ;
else
V_47 = NULL ;
if ( F_14 ( F_280 ( V_26 ) ) )
goto V_576;
}
V_29 = F_277 ( V_26 , V_47 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( V_349 != V_30 ) {
struct V_28 * V_38 = & V_349 -> V_29 ;
while ( ! ( V_26 = F_31 ( V_29 , V_38 ) ) ) {
int V_39 = V_29 -> V_41 ;
int V_40 = V_38 -> V_41 ;
if ( V_39 <= V_40 ) {
F_279 ( F_23 ( V_38 ) , V_38 ) ;
V_38 = F_32 ( V_38 ) ;
}
if ( V_39 >= V_40 ) {
F_276 ( F_23 ( V_29 ) , V_29 ) ;
V_29 = F_32 ( V_29 ) ;
}
}
F_279 ( V_26 , V_38 ) ;
F_276 ( V_26 , V_29 ) ;
}
if ( F_344 ( V_25 ) )
F_341 ( V_25 , V_30 ) ;
return V_30 ;
V_576:
V_26 = & V_25 -> V_42 ;
#endif
if ( ! V_26 -> V_75 )
goto V_402;
F_410 ( V_25 , V_349 ) ;
do {
V_29 = F_277 ( V_26 , NULL ) ;
F_276 ( V_26 , V_29 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( F_344 ( V_25 ) )
F_341 ( V_25 , V_30 ) ;
return V_30 ;
V_402:
F_411 ( & V_25 -> V_256 , V_574 ) ;
V_575 = F_254 ( V_25 ) ;
F_412 ( & V_25 -> V_256 , V_574 ) ;
if ( V_575 < 0 )
return V_577 ;
if ( V_575 > 0 )
goto V_526;
return NULL ;
}
static void F_413 ( struct V_25 * V_25 , struct V_27 * V_349 )
{
struct V_28 * V_29 = & V_349 -> V_29 ;
struct V_26 * V_26 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_279 ( V_26 , V_29 ) ;
}
}
static void F_414 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
struct V_28 * V_29 = & V_47 -> V_29 ;
if ( F_14 ( V_25 -> V_75 == 1 ) )
return;
F_271 ( V_26 , V_29 ) ;
if ( V_47 -> V_564 != V_578 ) {
F_312 ( V_25 ) ;
F_66 ( V_26 ) ;
F_415 ( V_25 , true ) ;
}
F_405 ( V_29 ) ;
}
static bool F_416 ( struct V_25 * V_25 , struct V_27 * V_30 , bool V_569 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( ! V_29 -> V_48 || F_220 ( F_23 ( V_29 ) ) )
return false ;
F_348 ( V_29 ) ;
F_414 ( V_25 ) ;
return true ;
}
static int F_417 ( struct V_27 * V_30 , struct V_579 * V_182 )
{
T_3 V_44 ;
F_334 ( & V_182 -> V_200 -> V_256 ) ;
if ( V_30 -> V_89 != & V_90 )
return 0 ;
if ( F_14 ( V_30 -> V_564 == V_565 ) )
return 0 ;
if ( F_230 ( V_580 ) && V_182 -> V_202 -> V_75 &&
( & V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_61 ||
& V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_62 ) )
return 1 ;
if ( V_581 == - 1 )
return 1 ;
if ( V_581 == 0 )
return 0 ;
V_44 = F_67 ( V_182 -> V_200 ) - V_30 -> V_29 . V_93 ;
return V_44 < ( T_3 ) V_581 ;
}
static int F_418 ( struct V_27 * V_30 , struct V_579 * V_182 )
{
struct V_137 * V_137 = F_148 ( V_30 -> V_137 ) ;
unsigned long V_582 , V_583 ;
int V_167 , V_169 ;
if ( ! F_192 ( & V_285 ) )
return - 1 ;
if ( ! V_30 -> V_145 || ! ( V_182 -> V_212 -> V_115 & V_584 ) )
return - 1 ;
V_167 = F_116 ( V_182 -> V_201 ) ;
V_169 = F_116 ( V_182 -> V_168 ) ;
if ( V_167 == V_169 )
return - 1 ;
if ( V_167 == V_30 -> V_135 ) {
if ( V_182 -> V_200 -> V_75 > V_182 -> V_200 -> V_136 )
return 1 ;
else
return - 1 ;
}
if ( V_169 == V_30 -> V_135 )
return 0 ;
if ( V_137 ) {
V_582 = F_107 ( V_30 , V_167 ) ;
V_583 = F_107 ( V_30 , V_169 ) ;
} else {
V_582 = F_106 ( V_30 , V_167 ) ;
V_583 = F_106 ( V_30 , V_169 ) ;
}
return V_583 < V_582 ;
}
static inline int F_418 ( struct V_27 * V_30 ,
struct V_579 * V_182 )
{
return - 1 ;
}
static
int F_419 ( struct V_27 * V_30 , struct V_579 * V_182 )
{
int V_585 ;
F_334 ( & V_182 -> V_200 -> V_256 ) ;
if ( F_304 ( V_324 ( V_30 ) , V_182 -> V_201 , V_182 -> V_168 ) )
return 0 ;
if ( ! F_137 ( V_182 -> V_168 , F_138 ( V_30 ) ) ) {
int V_1 ;
F_83 ( V_30 -> V_29 . V_94 . V_586 ) ;
V_182 -> V_115 |= V_587 ;
if ( ! V_182 -> V_588 || ( V_182 -> V_115 & V_589 ) )
return 0 ;
F_377 (cpu, env->dst_grpmask, env->cpus) {
if ( F_137 ( V_1 , F_138 ( V_30 ) ) ) {
V_182 -> V_115 |= V_589 ;
V_182 -> V_590 = V_1 ;
break;
}
}
return 0 ;
}
V_182 -> V_115 &= ~ V_591 ;
if ( F_420 ( V_182 -> V_200 , V_30 ) ) {
F_83 ( V_30 -> V_29 . V_94 . V_592 ) ;
return 0 ;
}
V_585 = F_418 ( V_30 , V_182 ) ;
if ( V_585 == - 1 )
V_585 = F_417 ( V_30 , V_182 ) ;
if ( V_585 <= 0 ||
V_182 -> V_212 -> V_593 > V_182 -> V_212 -> V_594 ) {
if ( V_585 == 1 ) {
F_83 ( V_182 -> V_212 -> V_595 [ V_182 -> V_402 ] ) ;
F_83 ( V_30 -> V_29 . V_94 . V_596 ) ;
}
return 1 ;
}
F_83 ( V_30 -> V_29 . V_94 . V_597 ) ;
return 0 ;
}
static void F_421 ( struct V_27 * V_30 , struct V_579 * V_182 )
{
F_334 ( & V_182 -> V_200 -> V_256 ) ;
V_30 -> V_48 = V_598 ;
F_422 ( V_182 -> V_200 , V_30 , 0 ) ;
F_423 ( V_30 , V_182 -> V_168 ) ;
}
static struct V_27 * F_424 ( struct V_579 * V_182 )
{
struct V_27 * V_30 , * V_330 ;
F_334 ( & V_182 -> V_200 -> V_256 ) ;
F_425 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_419 ( V_30 , V_182 ) )
continue;
F_421 ( V_30 , V_182 ) ;
F_83 ( V_182 -> V_212 -> V_599 [ V_182 -> V_402 ] ) ;
return V_30 ;
}
return NULL ;
}
static int F_426 ( struct V_579 * V_182 )
{
struct V_600 * V_601 = & V_182 -> V_200 -> V_323 ;
struct V_27 * V_30 ;
unsigned long V_73 ;
int V_602 = 0 ;
F_334 ( & V_182 -> V_200 -> V_256 ) ;
if ( V_182 -> V_504 <= 0 )
return 0 ;
while ( ! F_310 ( V_601 ) ) {
if ( V_182 -> V_402 != V_603 && V_182 -> V_200 -> V_75 <= 1 )
break;
V_30 = F_427 ( V_601 , struct V_27 , V_29 . V_322 ) ;
V_182 -> V_604 ++ ;
if ( V_182 -> V_604 > V_182 -> V_605 )
break;
if ( V_182 -> V_604 > V_182 -> V_606 ) {
V_182 -> V_606 += V_607 ;
V_182 -> V_115 |= V_608 ;
break;
}
if ( ! F_419 ( V_30 , V_182 ) )
goto V_61;
V_73 = F_139 ( V_30 ) ;
if ( F_230 ( V_609 ) && V_73 < 16 && ! V_182 -> V_212 -> V_593 )
goto V_61;
if ( ( V_73 / 2 ) > V_182 -> V_504 )
goto V_61;
F_421 ( V_30 , V_182 ) ;
F_213 ( & V_30 -> V_29 . V_322 , & V_182 -> V_601 ) ;
V_602 ++ ;
V_182 -> V_504 -= V_73 ;
#ifdef F_428
if ( V_182 -> V_402 == V_610 )
break;
#endif
if ( V_182 -> V_504 <= 0 )
break;
continue;
V_61:
F_429 ( & V_30 -> V_29 . V_322 , V_601 ) ;
}
F_70 ( V_182 -> V_212 -> V_599 [ V_182 -> V_402 ] , V_602 ) ;
return V_602 ;
}
static void F_430 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_334 ( & V_25 -> V_256 ) ;
F_182 ( F_34 ( V_30 ) != V_25 ) ;
F_431 ( V_25 , V_30 , 0 ) ;
V_30 -> V_48 = V_611 ;
F_432 ( V_25 , V_30 , 0 ) ;
}
static void F_433 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_298 ( & V_25 -> V_256 ) ;
F_430 ( V_25 , V_30 ) ;
F_300 ( & V_25 -> V_256 ) ;
}
static void F_434 ( struct V_579 * V_182 )
{
struct V_600 * V_601 = & V_182 -> V_601 ;
struct V_27 * V_30 ;
F_298 ( & V_182 -> V_202 -> V_256 ) ;
while ( ! F_310 ( V_601 ) ) {
V_30 = F_427 ( V_601 , struct V_27 , V_29 . V_322 ) ;
F_215 ( & V_30 -> V_29 . V_322 ) ;
F_430 ( V_182 -> V_202 , V_30 ) ;
}
F_300 ( & V_182 -> V_202 -> V_256 ) ;
}
static void F_435 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 ;
unsigned long V_115 ;
F_436 ( & V_25 -> V_256 , V_115 ) ;
F_312 ( V_25 ) ;
F_339 (rq, cfs_rq) {
if ( F_220 ( V_26 ) )
continue;
if ( F_241 ( F_63 ( V_26 ) , V_26 , true ) )
F_65 ( V_26 , 0 ) ;
if ( V_26 -> V_34 -> V_29 [ V_1 ] )
F_244 ( V_26 -> V_34 -> V_29 [ V_1 ] , 0 ) ;
}
F_437 ( & V_25 -> V_256 , V_115 ) ;
}
static void F_438 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_28 * V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
unsigned long V_92 = V_223 ;
unsigned long V_73 ;
if ( V_26 -> V_612 == V_92 )
return;
V_26 -> V_613 = NULL ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_613 = V_29 ;
if ( V_26 -> V_612 == V_92 )
break;
}
if ( ! V_29 ) {
V_26 -> V_614 = F_253 ( V_26 ) ;
V_26 -> V_612 = V_92 ;
}
while ( ( V_29 = V_26 -> V_613 ) != NULL ) {
V_73 = V_26 -> V_614 ;
V_73 = F_439 ( V_73 * V_29 -> V_79 . V_82 ,
F_253 ( V_26 ) + 1 ) ;
V_26 = F_24 ( V_29 ) ;
V_26 -> V_614 = V_73 ;
V_26 -> V_612 = V_92 ;
}
}
static unsigned long F_139 ( struct V_27 * V_30 )
{
struct V_26 * V_26 = F_22 ( V_30 ) ;
F_438 ( V_26 ) ;
return F_439 ( V_30 -> V_29 . V_79 . V_82 * V_26 -> V_614 ,
F_253 ( V_26 ) + 1 ) ;
}
static inline void F_435 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 = & V_25 -> V_42 ;
unsigned long V_115 ;
F_436 ( & V_25 -> V_256 , V_115 ) ;
F_312 ( V_25 ) ;
F_241 ( F_63 ( V_26 ) , V_26 , true ) ;
F_437 ( & V_25 -> V_256 , V_115 ) ;
}
static unsigned long F_139 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_82 ;
}
static inline void F_440 ( struct V_615 * V_529 )
{
* V_529 = (struct V_615 ) {
. V_616 = NULL ,
. V_232 = NULL ,
. V_617 = 0UL ,
. V_618 = 0UL ,
. V_619 = {
. V_506 = 0UL ,
. V_620 = 0 ,
. V_621 = V_622 ,
} ,
} ;
}
static inline int F_441 ( struct V_211 * V_212 ,
enum V_623 V_402 )
{
int V_501 ;
switch ( V_402 ) {
case V_603 :
V_501 = V_212 -> V_624 ;
break;
case V_610 :
V_501 = V_212 -> V_625 ;
break;
default:
V_501 = V_212 -> V_626 ;
break;
}
return V_501 ;
}
static unsigned long F_442 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
T_2 V_466 , V_627 , V_628 , V_79 ;
T_3 V_44 ;
V_628 = F_98 ( V_25 -> V_628 ) ;
V_79 = F_98 ( V_25 -> V_629 ) ;
V_44 = F_443 ( V_25 ) - V_628 ;
if ( F_14 ( V_44 < 0 ) )
V_44 = 0 ;
V_466 = F_444 () + V_44 ;
V_627 = F_227 ( V_79 , V_466 ) ;
if ( F_12 ( V_627 < V_88 ) )
return V_88 - V_627 ;
return 1 ;
}
static void F_445 ( struct V_211 * V_212 , int V_1 )
{
unsigned long V_177 = F_225 ( V_212 , V_1 ) ;
struct V_489 * V_630 = V_212 -> V_492 ;
F_124 ( V_1 ) -> V_469 = V_177 ;
V_177 *= F_442 ( V_1 ) ;
V_177 >>= V_631 ;
if ( ! V_177 )
V_177 = 1 ;
F_124 ( V_1 ) -> V_468 = V_177 ;
V_630 -> V_511 -> V_177 = V_177 ;
V_630 -> V_511 -> V_632 = V_177 ;
}
void F_446 ( struct V_211 * V_212 , int V_1 )
{
struct V_211 * V_558 = V_212 -> V_558 ;
struct V_489 * V_148 , * V_630 = V_212 -> V_492 ;
unsigned long V_177 , V_632 ;
unsigned long V_220 ;
V_220 = F_156 ( V_212 -> V_633 ) ;
V_220 = F_159 ( V_220 , 1UL , V_634 ) ;
V_630 -> V_511 -> V_635 = V_223 + V_220 ;
if ( ! V_558 ) {
F_445 ( V_212 , V_1 ) ;
return;
}
V_177 = 0 ;
V_632 = V_495 ;
if ( V_558 -> V_115 & V_636 ) {
F_123 (cpu, sched_group_cpus(sdg)) {
struct V_637 * V_511 ;
struct V_25 * V_25 = F_124 ( V_1 ) ;
if ( F_14 ( ! V_25 -> V_212 ) ) {
V_177 += F_126 ( V_1 ) ;
} else {
V_511 = V_25 -> V_212 -> V_492 -> V_511 ;
V_177 += V_511 -> V_177 ;
}
V_632 = F_155 ( V_177 , V_632 ) ;
}
} else {
V_148 = V_558 -> V_492 ;
do {
struct V_637 * V_511 = V_148 -> V_511 ;
V_177 += V_511 -> V_177 ;
V_632 = F_155 ( V_511 -> V_632 , V_632 ) ;
V_148 = V_148 -> V_61 ;
} while ( V_148 != V_558 -> V_492 );
}
V_630 -> V_511 -> V_177 = V_177 ;
V_630 -> V_511 -> V_632 = V_632 ;
}
static inline int
F_447 ( struct V_25 * V_25 , struct V_211 * V_212 )
{
return ( ( V_25 -> V_468 * V_212 -> V_197 ) <
( V_25 -> V_469 * 100 ) ) ;
}
static inline int F_448 ( struct V_489 * V_148 )
{
return V_148 -> V_511 -> V_504 ;
}
static inline bool
F_449 ( struct V_579 * V_182 , struct V_638 * V_639 )
{
if ( V_639 -> V_620 < V_639 -> F_114 )
return true ;
if ( ( V_639 -> V_640 * 100 ) >
( V_639 -> V_641 * V_182 -> V_212 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_450 ( struct V_579 * V_182 , struct V_638 * V_639 )
{
if ( V_639 -> V_620 <= V_639 -> F_114 )
return false ;
if ( ( V_639 -> V_640 * 100 ) <
( V_639 -> V_641 * V_182 -> V_212 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_451 ( struct V_489 * V_642 , struct V_489 * V_643 )
{
return V_642 -> V_511 -> V_632 * V_549 <
V_643 -> V_511 -> V_632 * 1024 ;
}
static inline enum
V_621 F_452 ( struct V_489 * V_148 ,
struct V_638 * V_639 )
{
if ( V_639 -> V_644 )
return V_645 ;
if ( F_448 ( V_148 ) )
return V_646 ;
return V_622 ;
}
static inline void F_453 ( struct V_579 * V_182 ,
struct V_489 * V_148 , int V_501 ,
int V_510 , struct V_638 * V_639 ,
bool * V_647 )
{
unsigned long V_73 ;
int V_271 , V_75 ;
memset ( V_639 , 0 , sizeof( * V_639 ) ) ;
F_377 (i, sched_group_cpus(group), env->cpus) {
struct V_25 * V_25 = F_124 ( V_271 ) ;
if ( V_510 )
V_73 = F_361 ( V_271 , V_501 ) ;
else
V_73 = F_360 ( V_271 , V_501 ) ;
V_639 -> V_648 += V_73 ;
V_639 -> V_641 += F_397 ( V_271 ) ;
V_639 -> V_620 += V_25 -> V_42 . V_413 ;
V_75 = V_25 -> V_75 ;
if ( V_75 > 1 )
* V_647 = true ;
#ifdef F_454
V_639 -> V_134 += V_25 -> V_134 ;
V_639 -> V_136 += V_25 -> V_136 ;
#endif
V_639 -> V_649 += F_125 ( V_271 ) ;
if ( ! V_75 && F_378 ( V_271 ) )
V_639 -> V_650 ++ ;
}
V_639 -> V_640 = V_148 -> V_511 -> V_177 ;
V_639 -> V_506 = ( V_639 -> V_648 * V_88 ) / V_639 -> V_640 ;
if ( V_639 -> V_620 )
V_639 -> V_651 = V_639 -> V_649 / V_639 -> V_620 ;
V_639 -> F_114 = V_148 -> F_114 ;
V_639 -> V_644 = F_450 ( V_182 , V_639 ) ;
V_639 -> V_621 = F_452 ( V_148 , V_639 ) ;
}
static bool F_455 ( struct V_579 * V_182 ,
struct V_615 * V_529 ,
struct V_489 * V_642 ,
struct V_638 * V_639 )
{
struct V_638 * V_616 = & V_529 -> V_619 ;
if ( V_639 -> V_621 > V_616 -> V_621 )
return true ;
if ( V_639 -> V_621 < V_616 -> V_621 )
return false ;
if ( V_639 -> V_506 <= V_616 -> V_506 )
return false ;
if ( ! ( V_182 -> V_212 -> V_115 & V_652 ) )
goto V_653;
if ( V_639 -> V_620 <= V_639 -> F_114 &&
F_451 ( V_529 -> V_232 , V_642 ) )
return false ;
V_653:
if ( ! ( V_182 -> V_212 -> V_115 & V_654 ) )
return true ;
if ( V_182 -> V_402 == V_603 )
return true ;
if ( V_639 -> V_620 &&
F_456 ( V_182 -> V_168 , V_642 -> V_655 ) ) {
if ( ! V_529 -> V_616 )
return true ;
if ( F_456 ( V_529 -> V_616 -> V_655 ,
V_642 -> V_655 ) )
return true ;
}
return false ;
}
static inline enum V_656 F_457 ( struct V_638 * V_639 )
{
if ( V_639 -> V_620 > V_639 -> V_134 )
return V_657 ;
if ( V_639 -> V_620 > V_639 -> V_136 )
return V_230 ;
return V_658 ;
}
static inline enum V_656 F_458 ( struct V_25 * V_25 )
{
if ( V_25 -> V_75 > V_25 -> V_134 )
return V_657 ;
if ( V_25 -> V_75 > V_25 -> V_136 )
return V_230 ;
return V_658 ;
}
static inline enum V_656 F_457 ( struct V_638 * V_639 )
{
return V_658 ;
}
static inline enum V_656 F_458 ( struct V_25 * V_25 )
{
return V_657 ;
}
static inline void F_459 ( struct V_579 * V_182 , struct V_615 * V_529 )
{
struct V_211 * V_558 = V_182 -> V_212 -> V_558 ;
struct V_489 * V_642 = V_182 -> V_212 -> V_492 ;
struct V_638 V_659 ;
int V_501 , V_660 = 0 ;
bool V_647 = false ;
if ( V_558 && V_558 -> V_115 & V_661 )
V_660 = 1 ;
V_501 = F_441 ( V_182 -> V_212 , V_182 -> V_402 ) ;
do {
struct V_638 * V_639 = & V_659 ;
int V_510 ;
V_510 = F_137 ( V_182 -> V_168 , F_373 ( V_642 ) ) ;
if ( V_510 ) {
V_529 -> V_232 = V_642 ;
V_639 = & V_529 -> V_662 ;
if ( V_182 -> V_402 != V_610 ||
F_460 ( V_223 , V_642 -> V_511 -> V_635 ) )
F_446 ( V_182 -> V_212 , V_182 -> V_168 ) ;
}
F_453 ( V_182 , V_642 , V_501 , V_510 , V_639 ,
& V_647 ) ;
if ( V_510 )
goto V_663;
if ( V_660 && V_529 -> V_232 &&
F_449 ( V_182 , & V_529 -> V_662 ) &&
( V_639 -> V_620 > 1 ) ) {
V_639 -> V_644 = 1 ;
V_639 -> V_621 = F_452 ( V_642 , V_639 ) ;
}
if ( F_455 ( V_182 , V_529 , V_642 , V_639 ) ) {
V_529 -> V_616 = V_642 ;
V_529 -> V_619 = * V_639 ;
}
V_663:
V_529 -> V_617 += V_639 -> V_648 ;
V_529 -> V_618 += V_639 -> V_640 ;
V_642 = V_642 -> V_61 ;
} while ( V_642 != V_182 -> V_212 -> V_492 );
if ( V_182 -> V_212 -> V_115 & V_584 )
V_182 -> V_656 = F_457 ( & V_529 -> V_619 ) ;
if ( ! V_182 -> V_212 -> V_35 ) {
if ( V_182 -> V_202 -> V_547 -> V_647 != V_647 )
V_182 -> V_202 -> V_547 -> V_647 = V_647 ;
}
}
static int F_461 ( struct V_579 * V_182 , struct V_615 * V_529 )
{
int V_664 ;
if ( ! ( V_182 -> V_212 -> V_115 & V_654 ) )
return 0 ;
if ( V_182 -> V_402 == V_603 )
return 0 ;
if ( ! V_529 -> V_616 )
return 0 ;
V_664 = V_529 -> V_616 -> V_655 ;
if ( F_456 ( V_664 , V_182 -> V_168 ) )
return 0 ;
V_182 -> V_504 = F_127 (
V_529 -> V_619 . V_506 * V_529 -> V_619 . V_640 ,
V_88 ) ;
return 1 ;
}
static inline
void F_462 ( struct V_579 * V_182 , struct V_615 * V_529 )
{
unsigned long V_551 , V_665 = 0 , V_666 = 0 ;
unsigned int V_667 = 2 ;
unsigned long V_668 ;
struct V_638 * V_232 , * V_616 ;
V_232 = & V_529 -> V_662 ;
V_616 = & V_529 -> V_619 ;
if ( ! V_232 -> V_620 )
V_232 -> V_651 = F_363 ( V_182 -> V_168 ) ;
else if ( V_616 -> V_651 > V_232 -> V_651 )
V_667 = 1 ;
V_668 =
( V_616 -> V_651 * V_88 ) /
V_616 -> V_640 ;
if ( V_616 -> V_506 + V_668 >=
V_232 -> V_506 + ( V_668 * V_667 ) ) {
V_182 -> V_504 = V_616 -> V_651 ;
return;
}
V_665 += V_616 -> V_640 *
F_155 ( V_616 -> V_651 , V_616 -> V_506 ) ;
V_665 += V_232 -> V_640 *
F_155 ( V_232 -> V_651 , V_232 -> V_506 ) ;
V_665 /= V_88 ;
if ( V_616 -> V_506 > V_668 ) {
V_666 += V_616 -> V_640 *
F_155 ( V_616 -> V_651 ,
V_616 -> V_506 - V_668 ) ;
}
if ( V_616 -> V_506 * V_616 -> V_640 <
V_616 -> V_651 * V_88 ) {
V_551 = ( V_616 -> V_506 * V_616 -> V_640 ) /
V_232 -> V_640 ;
} else {
V_551 = ( V_616 -> V_651 * V_88 ) /
V_232 -> V_640 ;
}
V_666 += V_232 -> V_640 *
F_155 ( V_232 -> V_651 , V_232 -> V_506 + V_551 ) ;
V_666 /= V_88 ;
if ( V_666 > V_665 )
V_182 -> V_504 = V_616 -> V_651 ;
}
static inline void F_463 ( struct V_579 * V_182 , struct V_615 * V_529 )
{
unsigned long V_669 , V_670 = ~ 0UL ;
struct V_638 * V_232 , * V_616 ;
V_232 = & V_529 -> V_662 ;
V_616 = & V_529 -> V_619 ;
if ( V_616 -> V_621 == V_646 ) {
V_616 -> V_651 =
F_155 ( V_616 -> V_651 , V_529 -> V_506 ) ;
}
if ( V_616 -> V_506 <= V_529 -> V_506 ||
V_232 -> V_506 >= V_529 -> V_506 ) {
V_182 -> V_504 = 0 ;
return F_462 ( V_182 , V_529 ) ;
}
if ( V_616 -> V_621 == V_645 &&
V_232 -> V_621 == V_645 ) {
V_670 = V_616 -> V_620 * V_88 ;
if ( V_670 > V_616 -> V_640 ) {
V_670 -= V_616 -> V_640 ;
V_670 *= F_13 ( V_74 ) ;
V_670 /= V_616 -> V_640 ;
} else
V_670 = ~ 0UL ;
}
V_669 = F_155 ( V_616 -> V_506 - V_529 -> V_506 , V_670 ) ;
V_182 -> V_504 = F_155 (
V_669 * V_616 -> V_640 ,
( V_529 -> V_506 - V_232 -> V_506 ) * V_232 -> V_640
) / V_88 ;
if ( V_182 -> V_504 < V_616 -> V_651 )
return F_462 ( V_182 , V_529 ) ;
}
static struct V_489 * F_464 ( struct V_579 * V_182 )
{
struct V_638 * V_232 , * V_616 ;
struct V_615 V_529 ;
F_440 ( & V_529 ) ;
F_459 ( V_182 , & V_529 ) ;
V_232 = & V_529 . V_662 ;
V_616 = & V_529 . V_619 ;
if ( F_461 ( V_182 , & V_529 ) )
return V_529 . V_616 ;
if ( ! V_529 . V_616 || V_616 -> V_620 == 0 )
goto V_671;
V_529 . V_506 = ( V_88 * V_529 . V_617 )
/ V_529 . V_618 ;
if ( V_616 -> V_621 == V_646 )
goto V_672;
if ( V_182 -> V_402 == V_610 && F_449 ( V_182 , V_232 ) &&
V_616 -> V_644 )
goto V_672;
if ( V_232 -> V_506 >= V_616 -> V_506 )
goto V_671;
if ( V_232 -> V_506 >= V_529 . V_506 )
goto V_671;
if ( V_182 -> V_402 == V_673 ) {
if ( ( V_616 -> V_621 != V_645 ) &&
( V_232 -> V_650 <= ( V_616 -> V_650 + 1 ) ) )
goto V_671;
} else {
if ( 100 * V_616 -> V_506 <=
V_182 -> V_212 -> V_197 * V_232 -> V_506 )
goto V_671;
}
V_672:
F_463 ( V_182 , & V_529 ) ;
return V_529 . V_616 ;
V_671:
V_182 -> V_504 = 0 ;
return NULL ;
}
static struct V_25 * F_465 ( struct V_579 * V_182 ,
struct V_489 * V_148 )
{
struct V_25 * V_616 = NULL , * V_25 ;
unsigned long V_674 = 0 , V_675 = 1 ;
int V_271 ;
F_377 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_177 , V_470 ;
enum V_656 V_676 ;
V_25 = F_124 ( V_271 ) ;
V_676 = F_458 ( V_25 ) ;
if ( V_676 > V_182 -> V_656 )
continue;
V_177 = F_126 ( V_271 ) ;
V_470 = F_125 ( V_271 ) ;
if ( V_25 -> V_75 == 1 && V_470 > V_182 -> V_504 &&
! F_447 ( V_25 , V_182 -> V_212 ) )
continue;
if ( V_470 * V_675 > V_674 * V_177 ) {
V_674 = V_470 ;
V_675 = V_177 ;
V_616 = V_25 ;
}
}
return V_616 ;
}
static int F_466 ( struct V_579 * V_182 )
{
struct V_211 * V_212 = V_182 -> V_212 ;
if ( V_182 -> V_402 == V_610 ) {
if ( ( V_212 -> V_115 & V_654 ) &&
F_456 ( V_182 -> V_168 , V_182 -> V_201 ) )
return 1 ;
}
if ( ( V_182 -> V_402 != V_603 ) &&
( V_182 -> V_200 -> V_42 . V_413 == 1 ) ) {
if ( ( F_447 ( V_182 -> V_200 , V_212 ) ) &&
( F_126 ( V_182 -> V_201 ) * V_212 -> V_197 < F_126 ( V_182 -> V_168 ) * 100 ) )
return 1 ;
}
return F_14 ( V_212 -> V_593 > V_212 -> V_594 + 2 ) ;
}
static int F_467 ( struct V_579 * V_182 )
{
struct V_489 * V_642 = V_182 -> V_212 -> V_492 ;
struct V_523 * V_677 , * V_678 ;
int V_1 , V_679 = - 1 ;
if ( V_182 -> V_402 == V_610 )
return 1 ;
V_677 = F_373 ( V_642 ) ;
V_678 = F_468 ( V_642 ) ;
F_377 (cpu, sg_cpus, env->cpus) {
if ( ! F_137 ( V_1 , V_678 ) || ! F_378 ( V_1 ) )
continue;
V_679 = V_1 ;
break;
}
if ( V_679 == - 1 )
V_679 = F_469 ( V_642 ) ;
return V_679 == V_182 -> V_168 ;
}
static int F_470 ( int V_483 , struct V_25 * F_239 ,
struct V_211 * V_212 , enum V_623 V_402 ,
int * V_680 )
{
int V_681 , V_682 , V_683 = 0 ;
struct V_211 * V_684 = V_212 -> V_35 ;
struct V_489 * V_148 ;
struct V_25 * V_616 ;
unsigned long V_115 ;
struct V_523 * V_9 = F_387 ( V_685 ) ;
struct V_579 V_182 = {
. V_212 = V_212 ,
. V_168 = V_483 ,
. V_202 = F_239 ,
. V_588 = F_373 ( V_212 -> V_492 ) ,
. V_402 = V_402 ,
. V_606 = V_607 ,
. V_9 = V_9 ,
. V_656 = V_658 ,
. V_601 = F_471 ( V_182 . V_601 ) ,
} ;
if ( V_402 == V_610 )
V_182 . V_588 = NULL ;
F_472 ( V_9 , V_686 ) ;
F_83 ( V_212 -> V_687 [ V_402 ] ) ;
V_688:
if ( ! F_467 ( & V_182 ) ) {
* V_680 = 0 ;
goto V_671;
}
V_148 = F_464 ( & V_182 ) ;
if ( ! V_148 ) {
F_83 ( V_212 -> V_689 [ V_402 ] ) ;
goto V_671;
}
V_616 = F_465 ( & V_182 , V_148 ) ;
if ( ! V_616 ) {
F_83 ( V_212 -> V_690 [ V_402 ] ) ;
goto V_671;
}
F_182 ( V_616 == V_182 . V_202 ) ;
F_70 ( V_212 -> V_691 [ V_402 ] , V_182 . V_504 ) ;
V_182 . V_201 = V_616 -> V_1 ;
V_182 . V_200 = V_616 ;
V_681 = 0 ;
if ( V_616 -> V_75 > 1 ) {
V_182 . V_115 |= V_591 ;
V_182 . V_605 = F_155 ( V_692 , V_616 -> V_75 ) ;
V_693:
F_436 ( & V_616 -> V_256 , V_115 ) ;
V_682 = F_426 ( & V_182 ) ;
F_300 ( & V_616 -> V_256 ) ;
if ( V_682 ) {
F_434 ( & V_182 ) ;
V_681 += V_682 ;
}
F_473 ( V_115 ) ;
if ( V_182 . V_115 & V_608 ) {
V_182 . V_115 &= ~ V_608 ;
goto V_693;
}
if ( ( V_182 . V_115 & V_589 ) && V_182 . V_504 > 0 ) {
F_391 ( V_182 . V_168 , V_182 . V_9 ) ;
V_182 . V_202 = F_124 ( V_182 . V_590 ) ;
V_182 . V_168 = V_182 . V_590 ;
V_182 . V_115 &= ~ V_589 ;
V_182 . V_604 = 0 ;
V_182 . V_606 = V_607 ;
goto V_693;
}
if ( V_684 ) {
int * V_694 = & V_684 -> V_492 -> V_511 -> V_504 ;
if ( ( V_182 . V_115 & V_587 ) && V_182 . V_504 > 0 )
* V_694 = 1 ;
}
if ( F_14 ( V_182 . V_115 & V_591 ) ) {
F_391 ( F_26 ( V_616 ) , V_9 ) ;
if ( ! F_474 ( V_9 ) ) {
V_182 . V_604 = 0 ;
V_182 . V_606 = V_607 ;
goto V_688;
}
goto V_695;
}
}
if ( ! V_681 ) {
F_83 ( V_212 -> V_696 [ V_402 ] ) ;
if ( V_402 != V_610 )
V_212 -> V_593 ++ ;
if ( F_466 ( & V_182 ) ) {
F_436 ( & V_616 -> V_256 , V_115 ) ;
if ( ! F_137 ( V_483 ,
F_138 ( V_616 -> V_47 ) ) ) {
F_437 ( & V_616 -> V_256 ,
V_115 ) ;
V_182 . V_115 |= V_591 ;
goto V_697;
}
if ( ! V_616 -> V_683 ) {
V_616 -> V_683 = 1 ;
V_616 -> V_698 = V_483 ;
V_683 = 1 ;
}
F_437 ( & V_616 -> V_256 , V_115 ) ;
if ( V_683 ) {
F_475 ( F_26 ( V_616 ) ,
V_699 , V_616 ,
& V_616 -> V_700 ) ;
}
V_212 -> V_593 = V_212 -> V_594 + 1 ;
}
} else
V_212 -> V_593 = 0 ;
if ( F_12 ( ! V_683 ) ) {
V_212 -> V_633 = V_212 -> V_701 ;
} else {
if ( V_212 -> V_633 < V_212 -> V_702 )
V_212 -> V_633 *= 2 ;
}
goto V_320;
V_671:
if ( V_684 ) {
int * V_694 = & V_684 -> V_492 -> V_511 -> V_504 ;
if ( * V_694 )
* V_694 = 0 ;
}
V_695:
F_83 ( V_212 -> V_703 [ V_402 ] ) ;
V_212 -> V_593 = 0 ;
V_697:
if ( ( ( V_182 . V_115 & V_591 ) &&
V_212 -> V_633 < V_704 ) ||
( V_212 -> V_633 < V_212 -> V_702 ) )
V_212 -> V_633 *= 2 ;
V_681 = 0 ;
V_320:
return V_681 ;
}
static inline unsigned long
F_476 ( struct V_211 * V_212 , int V_705 )
{
unsigned long V_220 = V_212 -> V_633 ;
if ( V_705 )
V_220 *= V_212 -> V_706 ;
V_220 = F_156 ( V_220 ) ;
V_220 = F_159 ( V_220 , 1UL , V_634 ) ;
return V_220 ;
}
static inline void
F_477 ( struct V_211 * V_212 , unsigned long * V_707 )
{
unsigned long V_220 , V_61 ;
V_220 = F_476 ( V_212 , 0 ) ;
V_61 = V_212 -> V_708 + V_220 ;
if ( F_193 ( * V_707 , V_61 ) )
* V_707 = V_61 ;
}
static int F_254 ( struct V_25 * F_239 )
{
unsigned long V_707 = V_223 + V_221 ;
int V_483 = F_239 -> V_1 ;
struct V_211 * V_212 ;
int V_709 = 0 ;
T_2 V_710 = 0 ;
F_239 -> V_522 = F_78 ( F_239 ) ;
if ( F_239 -> V_540 < V_581 ||
! F_239 -> V_547 -> V_647 ) {
F_134 () ;
V_212 = F_478 ( F_239 -> V_212 ) ;
if ( V_212 )
F_477 ( V_212 , & V_707 ) ;
F_143 () ;
goto V_320;
}
F_300 ( & F_239 -> V_256 ) ;
F_435 ( V_483 ) ;
F_134 () ;
F_400 (this_cpu, sd) {
int V_680 = 1 ;
T_2 V_711 , V_712 ;
if ( ! ( V_212 -> V_115 & V_556 ) )
continue;
if ( F_239 -> V_540 < V_710 + V_212 -> V_713 ) {
F_477 ( V_212 , & V_707 ) ;
break;
}
if ( V_212 -> V_115 & V_714 ) {
V_711 = F_293 ( V_483 ) ;
V_709 = F_470 ( V_483 , F_239 ,
V_212 , V_610 ,
& V_680 ) ;
V_712 = F_293 ( V_483 ) - V_711 ;
if ( V_712 > V_212 -> V_713 )
V_212 -> V_713 = V_712 ;
V_710 += V_712 ;
}
F_477 ( V_212 , & V_707 ) ;
if ( V_709 || F_239 -> V_75 > 0 )
break;
}
F_143 () ;
F_298 ( & F_239 -> V_256 ) ;
if ( V_710 > F_239 -> V_715 )
F_239 -> V_715 = V_710 ;
if ( F_239 -> V_42 . V_413 && ! V_709 )
V_709 = 1 ;
V_320:
if ( F_193 ( F_239 -> V_707 , V_707 ) )
F_239 -> V_707 = V_707 ;
if ( F_239 -> V_75 != F_239 -> V_42 . V_413 )
V_709 = - 1 ;
if ( V_709 )
F_239 -> V_522 = 0 ;
return V_709 ;
}
static int V_699 ( void * V_408 )
{
struct V_25 * V_716 = V_408 ;
int V_664 = F_26 ( V_716 ) ;
int V_717 = V_716 -> V_698 ;
struct V_25 * V_718 = F_124 ( V_717 ) ;
struct V_211 * V_212 ;
struct V_27 * V_30 = NULL ;
F_479 ( & V_716 -> V_256 ) ;
if ( F_14 ( V_664 != F_294 () ||
! V_716 -> V_683 ) )
goto V_719;
if ( V_716 -> V_75 <= 1 )
goto V_719;
F_182 ( V_716 == V_718 ) ;
F_134 () ;
F_400 (target_cpu, sd) {
if ( ( V_212 -> V_115 & V_556 ) &&
F_137 ( V_664 , F_389 ( V_212 ) ) )
break;
}
if ( F_12 ( V_212 ) ) {
struct V_579 V_182 = {
. V_212 = V_212 ,
. V_168 = V_717 ,
. V_202 = V_718 ,
. V_201 = V_716 -> V_1 ,
. V_200 = V_716 ,
. V_402 = V_673 ,
} ;
F_83 ( V_212 -> V_720 ) ;
V_30 = F_424 ( & V_182 ) ;
if ( V_30 ) {
F_83 ( V_212 -> V_721 ) ;
V_212 -> V_593 = 0 ;
} else {
F_83 ( V_212 -> V_722 ) ;
}
}
F_143 () ;
V_719:
V_716 -> V_683 = 0 ;
F_300 ( & V_716 -> V_256 ) ;
if ( V_30 )
F_433 ( V_718 , V_30 ) ;
F_142 () ;
return 0 ;
}
static inline int F_480 ( struct V_25 * V_25 )
{
return F_14 ( ! F_481 ( V_25 -> V_212 ) ) ;
}
static inline int F_482 ( void )
{
int V_723 = F_376 ( V_724 . V_725 ) ;
if ( V_723 < V_726 && F_378 ( V_723 ) )
return V_723 ;
return V_726 ;
}
static void F_483 ( void )
{
int V_727 ;
V_724 . V_707 ++ ;
V_727 = F_482 () ;
if ( V_727 >= V_726 )
return;
if ( F_484 ( V_728 , F_485 ( V_727 ) ) )
return;
F_486 ( V_727 ) ;
return;
}
void F_487 ( unsigned int V_1 )
{
if ( F_14 ( F_488 ( V_729 , F_485 ( V_1 ) ) ) ) {
if ( F_12 ( F_137 ( V_1 , V_724 . V_725 ) ) ) {
F_391 ( V_1 , V_724 . V_725 ) ;
F_489 ( & V_724 . V_730 ) ;
}
F_490 ( V_729 , F_485 ( V_1 ) ) ;
}
}
static inline void F_491 ( void )
{
struct V_211 * V_212 ;
int V_1 = F_294 () ;
F_134 () ;
V_212 = F_148 ( F_149 ( V_542 , V_1 ) ) ;
if ( ! V_212 || ! V_212 -> V_731 )
goto V_206;
V_212 -> V_731 = 0 ;
F_492 ( & V_212 -> V_225 -> V_732 ) ;
V_206:
F_143 () ;
}
void F_493 ( void )
{
struct V_211 * V_212 ;
int V_1 = F_294 () ;
F_134 () ;
V_212 = F_148 ( F_149 ( V_542 , V_1 ) ) ;
if ( ! V_212 || V_212 -> V_731 )
goto V_206;
V_212 -> V_731 = 1 ;
F_489 ( & V_212 -> V_225 -> V_732 ) ;
V_206:
F_143 () ;
}
void F_494 ( int V_1 )
{
if ( ! F_495 ( V_1 ) )
return;
if ( F_488 ( V_729 , F_485 ( V_1 ) ) )
return;
if ( F_480 ( F_124 ( V_1 ) ) )
return;
F_496 ( V_1 , V_724 . V_725 ) ;
F_492 ( & V_724 . V_730 ) ;
F_497 ( V_729 , F_485 ( V_1 ) ) ;
}
void F_498 ( void )
{
V_634 = V_221 * F_499 () / 10 ;
}
static void F_500 ( struct V_25 * V_25 , enum V_623 V_402 )
{
int V_680 = 1 ;
int V_1 = V_25 -> V_1 ;
unsigned long V_220 ;
struct V_211 * V_212 ;
unsigned long V_707 = V_223 + 60 * V_221 ;
int F_477 = 0 ;
int V_733 , V_734 = 0 ;
T_2 V_735 = 0 ;
F_435 ( V_1 ) ;
F_134 () ;
F_400 (cpu, sd) {
if ( F_193 ( V_223 , V_212 -> V_736 ) ) {
V_212 -> V_713 =
( V_212 -> V_713 * 253 ) / 256 ;
V_212 -> V_736 = V_223 + V_221 ;
V_734 = 1 ;
}
V_735 += V_212 -> V_713 ;
if ( ! ( V_212 -> V_115 & V_556 ) )
continue;
if ( ! V_680 ) {
if ( V_734 )
continue;
break;
}
V_220 = F_476 ( V_212 , V_402 != V_673 ) ;
V_733 = V_212 -> V_115 & V_737 ;
if ( V_733 ) {
if ( ! F_501 ( & V_738 ) )
goto V_320;
}
if ( F_460 ( V_223 , V_212 -> V_708 + V_220 ) ) {
if ( F_470 ( V_1 , V_25 , V_212 , V_402 , & V_680 ) ) {
V_402 = F_378 ( V_1 ) ? V_673 : V_603 ;
}
V_212 -> V_708 = V_223 ;
V_220 = F_476 ( V_212 , V_402 != V_673 ) ;
}
if ( V_733 )
F_185 ( & V_738 ) ;
V_320:
if ( F_193 ( V_707 , V_212 -> V_708 + V_220 ) ) {
V_707 = V_212 -> V_708 + V_220 ;
F_477 = 1 ;
}
}
if ( V_734 ) {
V_25 -> V_715 =
F_69 ( ( T_2 ) V_581 , V_735 ) ;
}
F_143 () ;
if ( F_12 ( F_477 ) ) {
V_25 -> V_707 = V_707 ;
#ifdef F_351
if ( ( V_402 == V_673 ) && F_193 ( V_724 . V_707 , V_25 -> V_707 ) )
V_724 . V_707 = V_25 -> V_707 ;
#endif
}
}
static void F_502 ( struct V_25 * F_239 , enum V_623 V_402 )
{
int V_483 = F_239 -> V_1 ;
struct V_25 * V_25 ;
int V_679 ;
unsigned long V_707 = V_223 + 60 * V_221 ;
int F_477 = 0 ;
if ( V_402 != V_673 ||
! F_488 ( V_728 , F_485 ( V_483 ) ) )
goto V_300;
F_123 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_679 == V_483 || ! F_378 ( V_679 ) )
continue;
if ( F_503 () )
break;
V_25 = F_124 ( V_679 ) ;
if ( F_460 ( V_223 , V_25 -> V_707 ) ) {
F_479 ( & V_25 -> V_256 ) ;
F_312 ( V_25 ) ;
F_354 ( V_25 ) ;
F_504 ( & V_25 -> V_256 ) ;
F_500 ( V_25 , V_673 ) ;
}
if ( F_193 ( V_707 , V_25 -> V_707 ) ) {
V_707 = V_25 -> V_707 ;
F_477 = 1 ;
}
}
if ( F_12 ( F_477 ) )
V_724 . V_707 = V_707 ;
V_300:
F_490 ( V_728 , F_485 ( V_483 ) ) ;
}
static inline bool F_505 ( struct V_25 * V_25 )
{
unsigned long V_92 = V_223 ;
struct V_528 * V_529 ;
struct V_211 * V_212 ;
int V_739 , V_271 , V_1 = V_25 -> V_1 ;
bool V_740 = false ;
if ( F_14 ( V_25 -> F_254 ) )
return false ;
F_491 () ;
F_487 ( V_1 ) ;
if ( F_12 ( ! F_506 ( & V_724 . V_730 ) ) )
return false ;
if ( F_197 ( V_92 , V_724 . V_707 ) )
return false ;
if ( V_25 -> V_75 >= 2 )
return true ;
F_134 () ;
V_529 = F_148 ( F_149 ( V_530 , V_1 ) ) ;
if ( V_529 ) {
V_739 = F_506 ( & V_529 -> V_732 ) ;
if ( V_739 > 1 ) {
V_740 = true ;
goto V_206;
}
}
V_212 = F_148 ( V_25 -> V_212 ) ;
if ( V_212 ) {
if ( ( V_25 -> V_42 . V_413 >= 1 ) &&
F_447 ( V_25 , V_212 ) ) {
V_740 = true ;
goto V_206;
}
}
V_212 = F_148 ( F_149 ( V_741 , V_1 ) ) ;
if ( V_212 ) {
F_123 (i, sched_domain_span(sd)) {
if ( V_271 == V_1 ||
! F_137 ( V_271 , V_724 . V_725 ) )
continue;
if ( F_456 ( V_271 , V_1 ) ) {
V_740 = true ;
goto V_206;
}
}
}
V_206:
F_143 () ;
return V_740 ;
}
static void F_502 ( struct V_25 * F_239 , enum V_623 V_402 ) { }
static T_12 void F_507 ( struct V_742 * V_743 )
{
struct V_25 * F_239 = F_239 () ;
enum V_623 V_402 = F_239 -> F_254 ?
V_673 : V_603 ;
F_502 ( F_239 , V_402 ) ;
F_500 ( F_239 , V_402 ) ;
}
void F_508 ( struct V_25 * V_25 )
{
if ( F_14 ( F_480 ( V_25 ) ) )
return;
if ( F_460 ( V_223 , V_25 -> V_707 ) )
F_509 ( V_744 ) ;
#ifdef F_351
if ( F_505 ( V_25 ) )
F_483 () ;
#endif
}
static void F_510 ( struct V_25 * V_25 )
{
F_8 () ;
F_338 ( V_25 ) ;
}
static void F_511 ( struct V_25 * V_25 )
{
F_8 () ;
F_340 ( V_25 ) ;
}
static void F_512 ( struct V_25 * V_25 , struct V_27 * V_47 , int V_384 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_47 -> V_29 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_281 ( V_26 , V_29 , V_384 ) ;
}
if ( F_513 ( & V_285 ) )
F_208 ( V_25 , V_47 ) ;
}
static void F_514 ( struct V_27 * V_30 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 , * V_47 ;
struct V_25 * V_25 = F_239 () ;
F_298 ( & V_25 -> V_256 ) ;
F_312 ( V_25 ) ;
V_26 = F_22 ( V_172 ) ;
V_47 = V_26 -> V_47 ;
if ( V_47 ) {
F_66 ( V_26 ) ;
V_29 -> V_43 = V_47 -> V_43 ;
}
F_257 ( V_26 , V_29 , 1 ) ;
if ( V_745 && V_47 && F_37 ( V_47 , V_29 ) ) {
F_132 ( V_47 -> V_43 , V_29 -> V_43 ) ;
F_275 ( V_25 ) ;
}
V_29 -> V_43 -= V_26 -> F_36 ;
F_300 ( & V_25 -> V_256 ) ;
}
static void
F_515 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_746 )
{
if ( ! F_516 ( V_30 ) )
return;
if ( V_25 -> V_47 == V_30 ) {
if ( V_30 -> V_747 > V_746 )
F_275 ( V_25 ) ;
} else
F_432 ( V_25 , V_30 , 0 ) ;
}
static inline bool F_517 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_48 )
return true ;
if ( ! V_29 -> V_96 || V_30 -> V_118 == V_560 )
return true ;
return false ;
}
static void F_518 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
V_29 = V_29 -> V_35 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
if ( F_303 ( V_26 ) )
break;
F_244 ( V_29 , V_366 ) ;
}
}
static void F_518 ( struct V_28 * V_29 ) { }
static void F_519 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_244 ( V_29 , 0 ) ;
F_246 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_518 ( V_29 ) ;
}
static void F_64 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
#ifdef F_409
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
#endif
F_244 ( V_29 , F_230 ( V_350 ) ? 0 : V_365 ) ;
F_245 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_518 ( V_29 ) ;
}
static void F_520 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( ! F_517 ( V_30 ) ) {
F_257 ( V_26 , V_29 , 0 ) ;
V_29 -> V_43 -= V_26 -> F_36 ;
}
F_519 ( V_29 ) ;
}
static void F_521 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_64 ( V_29 ) ;
if ( ! F_517 ( V_30 ) )
V_29 -> V_43 += V_26 -> F_36 ;
}
static void F_522 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_520 ( V_30 ) ;
}
static void F_523 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_521 ( V_30 ) ;
if ( F_516 ( V_30 ) ) {
if ( V_25 -> V_47 == V_30 )
F_275 ( V_25 ) ;
else
F_432 ( V_25 , V_30 , 0 ) ;
}
}
static void F_524 ( struct V_25 * V_25 )
{
struct V_28 * V_29 = & V_25 -> V_47 -> V_29 ;
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_276 ( V_26 , V_29 ) ;
F_74 ( V_26 , 0 ) ;
}
}
void F_525 ( struct V_26 * V_26 )
{
V_26 -> V_54 = V_748 ;
V_26 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_26 -> V_51 = V_26 -> F_36 ;
#endif
#ifdef F_212
#ifdef F_409
V_26 -> V_358 = 0 ;
#endif
F_526 ( & V_26 -> V_362 , 0 ) ;
F_526 ( & V_26 -> V_364 , 0 ) ;
#endif
}
static void F_527 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
F_528 ( V_30 , F_147 ( V_30 ) ) ;
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
}
static void F_529 ( struct V_27 * V_30 )
{
F_520 ( V_30 ) ;
F_528 ( V_30 , F_147 ( V_30 ) ) ;
#ifdef F_212
V_30 -> V_29 . V_79 . V_80 = 0 ;
#endif
F_521 ( V_30 ) ;
}
static void F_530 ( struct V_27 * V_30 , int type )
{
switch ( type ) {
case V_749 :
F_527 ( V_30 ) ;
break;
case V_750 :
F_529 ( V_30 ) ;
break;
}
}
void F_531 ( struct V_324 * V_34 )
{
int V_271 ;
F_336 ( F_296 ( V_34 ) ) ;
F_532 (i) {
if ( V_34 -> V_26 )
F_190 ( V_34 -> V_26 [ V_271 ] ) ;
if ( V_34 -> V_29 )
F_190 ( V_34 -> V_29 [ V_271 ] ) ;
}
F_190 ( V_34 -> V_26 ) ;
F_190 ( V_34 -> V_29 ) ;
}
int F_533 ( struct V_324 * V_34 , struct V_324 * V_35 )
{
struct V_28 * V_29 ;
struct V_26 * V_26 ;
int V_271 ;
V_34 -> V_26 = F_178 ( sizeof( V_26 ) * V_726 , V_273 ) ;
if ( ! V_34 -> V_26 )
goto V_751;
V_34 -> V_29 = F_178 ( sizeof( V_29 ) * V_726 , V_273 ) ;
if ( ! V_34 -> V_29 )
goto V_751;
V_34 -> V_326 = V_74 ;
F_329 ( F_296 ( V_34 ) ) ;
F_532 (i) {
V_26 = F_534 ( sizeof( struct V_26 ) ,
V_273 , F_116 ( V_271 ) ) ;
if ( ! V_26 )
goto V_751;
V_29 = F_534 ( sizeof( struct V_28 ) ,
V_273 , F_116 ( V_271 ) ) ;
if ( ! V_29 )
goto V_752;
F_525 ( V_26 ) ;
F_535 ( V_34 , V_26 , V_29 , V_271 , V_35 -> V_29 [ V_271 ] ) ;
F_61 ( V_29 ) ;
}
return 1 ;
V_752:
F_190 ( V_26 ) ;
V_751:
return 0 ;
}
void F_536 ( struct V_324 * V_34 )
{
struct V_28 * V_29 ;
struct V_25 * V_25 ;
int V_271 ;
F_532 (i) {
V_25 = F_124 ( V_271 ) ;
V_29 = V_34 -> V_29 [ V_271 ] ;
F_479 ( & V_25 -> V_256 ) ;
F_64 ( V_29 ) ;
F_325 ( V_34 , V_271 ) ;
F_504 ( & V_25 -> V_256 ) ;
}
}
void F_537 ( struct V_324 * V_34 )
{
unsigned long V_115 ;
struct V_25 * V_25 ;
int V_1 ;
F_532 (cpu) {
if ( V_34 -> V_29 [ V_1 ] )
F_251 ( V_34 -> V_29 [ V_1 ] ) ;
if ( ! V_34 -> V_26 [ V_1 ] -> V_33 )
continue;
V_25 = F_124 ( V_1 ) ;
F_436 ( & V_25 -> V_256 , V_115 ) ;
F_29 ( V_34 -> V_26 [ V_1 ] ) ;
F_437 ( & V_25 -> V_256 , V_115 ) ;
}
}
void F_535 ( struct V_324 * V_34 , struct V_26 * V_26 ,
struct V_28 * V_29 , int V_1 ,
struct V_28 * V_35 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_25 = V_25 ;
F_333 ( V_26 ) ;
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
F_4 ( & V_29 -> V_73 , V_74 ) ;
V_29 -> V_35 = V_35 ;
}
int F_538 ( struct V_324 * V_34 , unsigned long V_326 )
{
int V_271 ;
unsigned long V_115 ;
if ( ! V_34 -> V_29 [ 0 ] )
return - V_216 ;
V_326 = F_159 ( V_326 , F_539 ( V_328 ) , F_539 ( V_753 ) ) ;
F_540 ( & V_754 ) ;
if ( V_34 -> V_326 == V_326 )
goto V_755;
V_34 -> V_326 = V_326 ;
F_532 (i) {
struct V_25 * V_25 = F_124 ( V_271 ) ;
struct V_28 * V_29 ;
V_29 = V_34 -> V_29 [ V_271 ] ;
F_436 ( & V_25 -> V_256 , V_115 ) ;
F_312 ( V_25 ) ;
F_59 (se)
F_219 ( F_24 ( V_29 ) ) ;
F_437 ( & V_25 -> V_256 , V_115 ) ;
}
V_755:
F_541 ( & V_754 ) ;
return 0 ;
}
void F_531 ( struct V_324 * V_34 ) { }
int F_533 ( struct V_324 * V_34 , struct V_324 * V_35 )
{
return 1 ;
}
void F_536 ( struct V_324 * V_34 ) { }
void F_537 ( struct V_324 * V_34 ) { }
static unsigned int F_542 ( struct V_25 * V_25 , struct V_27 * V_154 )
{
struct V_28 * V_29 = & V_154 -> V_29 ;
unsigned int V_756 = 0 ;
if ( V_25 -> V_42 . V_73 . V_5 )
V_756 = F_543 ( F_58 ( F_23 ( V_29 ) , V_29 ) ) ;
return V_756 ;
}
void F_544 ( struct V_757 * V_758 , int V_1 )
{
struct V_26 * V_26 ;
F_134 () ;
F_339 (cpu_rq(cpu), cfs_rq)
F_545 ( V_758 , V_1 , V_26 ) ;
F_143 () ;
}
void F_546 ( struct V_27 * V_30 , struct V_757 * V_758 )
{
int V_156 ;
unsigned long V_759 = 0 , V_760 = 0 , V_761 = 0 , V_762 = 0 ;
F_111 (node) {
if ( V_30 -> V_145 ) {
V_759 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 0 ) ] ;
V_760 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
if ( V_30 -> V_137 ) {
V_761 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 0 ) ] ,
V_762 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
F_547 ( V_758 , V_156 , V_759 , V_760 , V_761 , V_762 ) ;
}
}
T_13 void F_548 ( void )
{
#ifdef F_212
F_549 ( V_744 , F_507 ) ;
#ifdef F_351
V_724 . V_707 = V_223 ;
F_550 ( & V_724 . V_725 , V_763 ) ;
#endif
#endif
}
