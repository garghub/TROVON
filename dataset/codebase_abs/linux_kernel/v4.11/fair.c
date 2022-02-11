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
if ( ! F_137 ( V_182 -> V_201 , & V_203 -> V_207 ) )
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
goto V_208;
}
if ( V_183 > V_182 -> V_185 && V_200 -> V_75 == 1 &&
V_202 -> V_75 == 1 )
goto V_209;
V_208:
V_73 = F_138 ( V_182 -> V_30 ) ;
V_188 = V_182 -> V_196 . V_73 + V_73 ;
V_187 = V_182 -> V_195 . V_73 - V_73 ;
if ( V_204 > V_183 && V_204 > V_182 -> V_185 ) {
if ( ! F_131 ( V_187 , V_188 , V_182 ) ) {
V_183 = V_204 - 1 ;
V_203 = NULL ;
goto V_209;
}
}
if ( V_183 <= V_182 -> V_185 )
goto V_206;
if ( V_203 ) {
V_73 = F_138 ( V_203 ) ;
V_188 -= V_73 ;
V_187 += V_73 ;
}
if ( F_131 ( V_187 , V_188 , V_182 ) )
goto V_206;
if ( ! V_203 ) {
F_139 () ;
V_182 -> V_168 = F_140 ( V_182 -> V_30 , V_182 -> V_201 ,
V_182 -> V_168 ) ;
F_141 () ;
}
V_209:
F_128 ( V_182 , V_203 , V_183 ) ;
V_206:
F_142 () ;
}
static void F_143 ( struct V_181 * V_182 ,
long V_198 , long V_199 )
{
int V_1 ;
F_123 (cpu, cpumask_of_node(env->dst_nid)) {
if ( ! F_137 ( V_1 , & V_182 -> V_30 -> V_207 ) )
continue;
V_182 -> V_168 = V_1 ;
F_133 ( V_182 , V_198 , V_199 ) ;
}
}
static bool F_144 ( struct V_181 * V_182 )
{
struct V_174 * V_210 = & V_182 -> V_195 ;
struct V_174 * V_211 = & V_182 -> V_196 ;
if ( V_210 -> V_180 && ! V_211 -> V_180 )
return false ;
if ( V_210 -> V_73 * V_211 -> V_178 * V_182 -> V_197 >
V_211 -> V_73 * V_210 -> V_178 * 100 )
return true ;
return false ;
}
static int F_145 ( struct V_27 * V_30 )
{
struct V_181 V_182 = {
. V_30 = V_30 ,
. V_201 = F_146 ( V_30 ) ,
. V_167 = F_102 ( V_30 ) ,
. V_197 = 112 ,
. V_184 = NULL ,
. V_185 = 0 ,
. V_186 = - 1 ,
} ;
struct V_212 * V_213 ;
unsigned long V_214 , V_215 ;
int V_141 , V_69 , V_159 ;
long V_198 , V_199 ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_216 , V_182 . V_201 ) ) ;
if ( V_213 )
V_182 . V_197 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
F_142 () ;
if ( F_14 ( ! V_213 ) ) {
V_30 -> V_135 = F_102 ( V_30 ) ;
return - V_217 ;
}
V_182 . V_169 = V_30 -> V_135 ;
V_159 = V_182 . V_159 = F_112 ( V_182 . V_167 , V_182 . V_169 ) ;
V_214 = F_113 ( V_30 , V_182 . V_167 , V_159 ) ;
V_215 = F_114 ( V_30 , V_182 . V_167 , V_159 ) ;
F_122 ( & V_182 . V_195 , V_182 . V_167 ) ;
V_198 = F_113 ( V_30 , V_182 . V_169 , V_159 ) - V_214 ;
V_199 = F_114 ( V_30 , V_182 . V_169 , V_159 ) - V_215 ;
F_122 ( & V_182 . V_196 , V_182 . V_169 ) ;
if ( F_144 ( & V_182 ) )
F_143 ( & V_182 , V_198 , V_199 ) ;
if ( V_182 . V_186 == - 1 || ( V_30 -> V_137 && V_30 -> V_137 -> V_218 > 1 ) ) {
F_111 (nid) {
if ( V_141 == V_182 . V_167 || V_141 == V_30 -> V_135 )
continue;
V_159 = F_112 ( V_182 . V_167 , V_182 . V_169 ) ;
if ( V_157 == V_161 &&
V_159 != V_182 . V_159 ) {
V_214 = F_113 ( V_30 , V_182 . V_167 , V_159 ) ;
V_215 = F_114 ( V_30 , V_182 . V_167 , V_159 ) ;
}
V_198 = F_113 ( V_30 , V_141 , V_159 ) - V_214 ;
V_199 = F_114 ( V_30 , V_141 , V_159 ) - V_215 ;
if ( V_198 < 0 && V_199 < 0 )
continue;
V_182 . V_159 = V_159 ;
V_182 . V_169 = V_141 ;
F_122 ( & V_182 . V_196 , V_182 . V_169 ) ;
if ( F_144 ( & V_182 ) )
F_143 ( & V_182 , V_198 , V_199 ) ;
}
}
if ( V_30 -> V_137 ) {
struct V_137 * V_150 = V_30 -> V_137 ;
if ( V_182 . V_186 == - 1 )
V_141 = V_182 . V_167 ;
else
V_141 = V_182 . V_169 ;
if ( V_150 -> V_218 > 1 && F_109 ( V_182 . V_169 , V_150 ) )
F_149 ( V_30 , V_182 . V_169 ) ;
}
if ( V_182 . V_186 == - 1 )
return - V_219 ;
V_30 -> V_220 = F_97 ( V_30 ) ;
if ( V_182 . V_184 == NULL ) {
V_69 = F_150 ( V_30 , V_182 . V_186 ) ;
if ( V_69 != 0 )
F_151 ( V_30 , V_182 . V_201 , V_182 . V_186 ) ;
return V_69 ;
}
V_69 = F_152 ( V_30 , V_182 . V_184 ) ;
if ( V_69 != 0 )
F_151 ( V_30 , V_182 . V_201 , F_146 ( V_182 . V_184 ) ) ;
F_129 ( V_182 . V_184 ) ;
return V_69 ;
}
static void F_153 ( struct V_27 * V_30 )
{
unsigned long V_221 = V_222 ;
if ( F_14 ( V_30 -> V_135 == - 1 || ! V_30 -> V_145 ) )
return;
V_221 = F_154 ( V_221 , F_155 ( V_30 -> V_220 ) / 16 ) ;
V_30 -> V_223 = V_224 + V_221 ;
if ( F_102 ( V_30 ) == V_30 -> V_135 )
return;
F_145 ( V_30 ) ;
}
static void F_156 ( struct V_137 * V_137 )
{
unsigned long V_147 , V_225 = 0 ;
int V_141 , V_218 = 0 ;
F_111 (nid) {
V_147 = F_108 ( V_137 , V_141 ) ;
if ( V_147 > V_225 )
V_225 = V_147 ;
}
F_111 (nid) {
V_147 = F_108 ( V_137 , V_141 ) ;
if ( V_147 * V_151 > V_225 )
V_218 ++ ;
}
V_137 -> V_152 = V_225 ;
V_137 -> V_218 = V_218 ;
}
static void F_157 ( struct V_27 * V_30 ,
unsigned long V_226 , unsigned long V_227 )
{
unsigned int V_228 ;
int V_229 ;
int V_230 ;
unsigned long V_231 = V_30 -> V_232 [ 0 ] ;
unsigned long V_233 = V_30 -> V_232 [ 1 ] ;
if ( V_233 + V_226 == 0 || V_30 -> V_232 [ 2 ] ) {
V_30 -> V_220 = F_154 ( V_30 -> V_234 ,
V_30 -> V_220 << 1 ) ;
V_30 -> V_125 -> V_235 = V_224 +
F_155 ( V_30 -> V_220 ) ;
return;
}
V_228 = F_54 ( V_30 -> V_220 , V_236 ) ;
V_229 = ( V_233 * V_236 ) / ( V_233 + V_231 ) ;
if ( V_229 >= V_237 ) {
int V_238 = V_229 - V_237 ;
if ( ! V_238 )
V_238 = 1 ;
V_230 = V_238 * V_228 ;
} else {
V_230 = - ( V_237 - V_229 ) * V_228 ;
V_229 = F_54 ( V_227 * V_236 , ( V_227 + V_226 + 1 ) ) ;
V_230 = ( V_230 * V_229 ) / V_236 ;
}
V_30 -> V_220 = F_158 ( V_30 -> V_220 + V_230 ,
F_97 ( V_30 ) , F_100 ( V_30 ) ) ;
memset ( V_30 -> V_232 , 0 , sizeof( V_30 -> V_232 ) ) ;
}
static T_2 F_159 ( struct V_27 * V_30 , T_2 * V_239 )
{
T_2 V_240 , V_44 , V_92 ;
V_92 = V_30 -> V_29 . V_93 ;
V_240 = V_30 -> V_29 . V_96 ;
if ( V_30 -> V_241 ) {
V_44 = V_240 - V_30 -> V_242 ;
* V_239 = V_92 - V_30 -> V_241 ;
} else {
V_44 = V_30 -> V_29 . V_79 . V_83 / V_30 -> V_29 . V_73 . V_5 ;
* V_239 = V_84 ;
}
V_30 -> V_242 = V_240 ;
V_30 -> V_241 = V_92 ;
return V_44 ;
}
static int F_160 ( struct V_27 * V_30 , int V_141 )
{
T_8 V_243 ;
int V_159 ;
if ( V_157 == V_158 )
return V_141 ;
if ( V_157 == V_162 ) {
unsigned long V_155 , V_244 = 0 ;
int V_156 , V_245 = V_141 ;
V_159 = V_160 ;
F_111 (node) {
V_155 = F_114 ( V_30 , V_156 , V_159 ) ;
if ( V_155 > V_244 ) {
V_244 = V_155 ;
V_245 = V_156 ;
}
}
return V_245 ;
}
V_243 = V_246 ;
for ( V_159 = V_160 ; V_159 > V_163 ; V_159 -- ) {
unsigned long V_225 = 0 ;
T_8 V_247 = V_248 ;
int V_45 , V_46 ;
if ( ! F_161 ( V_159 ) )
continue;
F_162 (a, nodes) {
unsigned long V_147 = 0 ;
T_8 V_249 ;
F_163 ( V_249 ) ;
F_162 (b, nodes) {
if ( F_112 ( V_45 , V_46 ) < V_159 ) {
V_147 += F_107 ( V_30 , V_46 ) ;
F_164 ( V_46 , V_249 ) ;
F_165 ( V_46 , V_243 ) ;
}
}
if ( V_147 > V_225 ) {
V_225 = V_147 ;
V_247 = V_249 ;
V_141 = V_45 ;
}
}
if ( ! V_225 )
break;
V_243 = V_247 ;
}
return V_141 ;
}
static void F_166 ( struct V_27 * V_30 )
{
int V_250 , V_141 , V_251 = - 1 , V_252 = - 1 ;
unsigned long V_225 = 0 , V_253 = 0 ;
unsigned long V_254 [ 2 ] = { 0 , 0 } ;
unsigned long V_164 ;
T_2 V_240 , V_239 ;
T_9 * V_255 = NULL ;
V_250 = F_98 ( V_30 -> V_125 -> V_256 ) ;
if ( V_30 -> V_256 == V_250 )
return;
V_30 -> V_256 = V_250 ;
V_30 -> V_234 = F_100 ( V_30 ) ;
V_164 = V_30 -> V_232 [ 0 ] +
V_30 -> V_232 [ 1 ] ;
V_240 = F_159 ( V_30 , & V_239 ) ;
if ( V_30 -> V_137 ) {
V_255 = & V_30 -> V_137 -> V_257 ;
F_167 ( V_255 ) ;
}
F_111 (nid) {
int V_258 , V_259 , V_260 , V_261 ;
unsigned long V_147 = 0 , F_107 = 0 ;
int V_142 ;
for ( V_142 = 0 ; V_142 < V_143 ; V_142 ++ ) {
long V_230 , V_262 , V_263 ;
V_258 = F_105 ( V_146 , V_141 , V_142 ) ;
V_259 = F_105 ( V_264 , V_141 , V_142 ) ;
V_260 = F_105 ( V_265 , V_141 , V_142 ) ;
V_261 = F_105 ( V_266 , V_141 , V_142 ) ;
V_230 = V_30 -> V_145 [ V_259 ] - V_30 -> V_145 [ V_258 ] / 2 ;
V_254 [ V_142 ] += V_30 -> V_145 [ V_259 ] ;
V_30 -> V_145 [ V_259 ] = 0 ;
V_263 = F_168 ( V_240 << 16 , V_239 + 1 ) ;
V_263 = ( V_263 * V_30 -> V_145 [ V_261 ] ) /
( V_164 + 1 ) ;
V_262 = V_263 - V_30 -> V_145 [ V_260 ] / 2 ;
V_30 -> V_145 [ V_261 ] = 0 ;
V_30 -> V_145 [ V_258 ] += V_230 ;
V_30 -> V_145 [ V_260 ] += V_262 ;
V_147 += V_30 -> V_145 [ V_258 ] ;
V_30 -> V_165 += V_230 ;
if ( V_30 -> V_137 ) {
V_30 -> V_137 -> V_147 [ V_258 ] += V_230 ;
V_30 -> V_137 -> V_149 [ V_258 ] += V_262 ;
V_30 -> V_137 -> V_164 += V_230 ;
F_107 += V_30 -> V_137 -> V_147 [ V_258 ] ;
}
}
if ( V_147 > V_225 ) {
V_225 = V_147 ;
V_251 = V_141 ;
}
if ( F_107 > V_253 ) {
V_253 = F_107 ;
V_252 = V_141 ;
}
}
F_157 ( V_30 , V_254 [ 0 ] , V_254 [ 1 ] ) ;
if ( V_30 -> V_137 ) {
F_156 ( V_30 -> V_137 ) ;
F_169 ( V_255 ) ;
V_251 = F_160 ( V_30 , V_252 ) ;
}
if ( V_225 ) {
if ( V_251 != V_30 -> V_135 )
F_149 ( V_30 , V_251 ) ;
if ( F_102 ( V_30 ) != V_30 -> V_135 )
F_153 ( V_30 ) ;
}
}
static inline int F_170 ( struct V_137 * V_31 )
{
return F_171 ( & V_31 -> V_267 ) ;
}
static inline void F_172 ( struct V_137 * V_31 )
{
if ( F_173 ( & V_31 -> V_267 ) )
F_174 ( V_31 , V_268 ) ;
}
static void F_175 ( struct V_27 * V_30 , int V_269 , int V_115 ,
int * V_142 )
{
struct V_137 * V_31 , * V_270 ;
struct V_27 * V_104 ;
bool V_271 = false ;
int V_1 = F_176 ( V_269 ) ;
int V_272 ;
if ( F_14 ( ! V_30 -> V_137 ) ) {
unsigned int V_273 = sizeof( struct V_137 ) +
4 * V_144 *sizeof( unsigned long ) ;
V_31 = F_177 ( V_273 , V_274 | V_275 ) ;
if ( ! V_31 )
return;
F_178 ( & V_31 -> V_267 , 1 ) ;
V_31 -> V_218 = 1 ;
V_31 -> V_152 = 0 ;
F_179 ( & V_31 -> V_257 ) ;
V_31 -> V_138 = V_30 -> V_173 ;
V_31 -> V_149 = V_31 -> V_147 + V_143 *
V_144 ;
for ( V_272 = 0 ; V_272 < V_276 * V_144 ; V_272 ++ )
V_31 -> V_147 [ V_272 ] = V_30 -> V_145 [ V_272 ] ;
V_31 -> V_164 = V_30 -> V_165 ;
V_31 -> V_277 ++ ;
F_180 ( V_30 -> V_137 , V_31 ) ;
}
F_134 () ;
V_104 = F_98 ( F_124 ( V_1 ) -> V_47 ) ;
if ( ! F_121 ( V_104 , V_269 ) )
goto V_278;
V_31 = F_147 ( V_104 -> V_137 ) ;
if ( ! V_31 )
goto V_278;
V_270 = V_30 -> V_137 ;
if ( V_31 == V_270 )
goto V_278;
if ( V_270 -> V_277 > V_31 -> V_277 )
goto V_278;
if ( V_270 -> V_277 == V_31 -> V_277 && V_270 > V_31 )
goto V_278;
if ( V_104 -> V_125 == V_172 -> V_125 )
V_271 = true ;
if ( V_115 & V_279 )
V_271 = true ;
* V_142 = ! V_271 ;
if ( V_271 && ! F_170 ( V_31 ) )
goto V_278;
F_142 () ;
if ( ! V_271 )
return;
F_181 ( F_182 () ) ;
F_183 ( & V_270 -> V_257 , & V_31 -> V_257 ) ;
for ( V_272 = 0 ; V_272 < V_276 * V_144 ; V_272 ++ ) {
V_270 -> V_147 [ V_272 ] -= V_30 -> V_145 [ V_272 ] ;
V_31 -> V_147 [ V_272 ] += V_30 -> V_145 [ V_272 ] ;
}
V_270 -> V_164 -= V_30 -> V_165 ;
V_31 -> V_164 += V_30 -> V_165 ;
V_270 -> V_277 -- ;
V_31 -> V_277 ++ ;
F_184 ( & V_270 -> V_257 ) ;
F_169 ( & V_31 -> V_257 ) ;
F_180 ( V_30 -> V_137 , V_31 ) ;
F_172 ( V_270 ) ;
return;
V_278:
F_142 () ;
return;
}
void F_185 ( struct V_27 * V_30 )
{
struct V_137 * V_31 = V_30 -> V_137 ;
void * V_145 = V_30 -> V_145 ;
unsigned long V_115 ;
int V_272 ;
if ( V_31 ) {
F_186 ( & V_31 -> V_257 , V_115 ) ;
for ( V_272 = 0 ; V_272 < V_276 * V_144 ; V_272 ++ )
V_31 -> V_147 [ V_272 ] -= V_30 -> V_145 [ V_272 ] ;
V_31 -> V_164 -= V_30 -> V_165 ;
V_31 -> V_277 -- ;
F_187 ( & V_31 -> V_257 , V_115 ) ;
F_188 ( V_30 -> V_137 , NULL ) ;
F_172 ( V_31 ) ;
}
V_30 -> V_145 = NULL ;
F_189 ( V_145 ) ;
}
void F_190 ( int V_170 , int V_280 , int V_281 , int V_115 )
{
struct V_27 * V_30 = V_172 ;
bool V_282 = V_115 & V_283 ;
int V_284 = F_102 ( V_172 ) ;
int V_233 = ! ! ( V_115 & V_285 ) ;
struct V_137 * V_150 ;
int V_142 ;
if ( ! F_191 ( & V_286 ) )
return;
if ( ! V_30 -> V_125 )
return;
if ( F_14 ( ! V_30 -> V_145 ) ) {
int V_273 = sizeof( * V_30 -> V_145 ) *
V_287 * V_144 ;
V_30 -> V_145 = F_177 ( V_273 , V_274 | V_275 ) ;
if ( ! V_30 -> V_145 )
return;
V_30 -> V_165 = 0 ;
memset ( V_30 -> V_232 , 0 , sizeof( V_30 -> V_232 ) ) ;
}
if ( F_14 ( V_170 == ( - 1 & V_288 ) ) ) {
V_142 = 1 ;
} else {
V_142 = F_121 ( V_30 , V_170 ) ;
if ( ! V_142 && ! ( V_115 & V_289 ) )
F_175 ( V_30 , V_170 , V_115 , & V_142 ) ;
}
V_150 = V_30 -> V_137 ;
if ( ! V_142 && ! V_233 && V_150 && V_150 -> V_218 > 1 &&
F_109 ( V_284 , V_150 ) &&
F_109 ( V_280 , V_150 ) )
V_233 = 1 ;
F_166 ( V_30 ) ;
if ( F_192 ( V_224 , V_30 -> V_223 ) )
F_153 ( V_30 ) ;
if ( V_282 )
V_30 -> V_290 += V_281 ;
if ( V_115 & V_291 )
V_30 -> V_232 [ 2 ] += V_281 ;
V_30 -> V_145 [ F_105 ( V_264 , V_280 , V_142 ) ] += V_281 ;
V_30 -> V_145 [ F_105 ( V_266 , V_284 , V_142 ) ] += V_281 ;
V_30 -> V_232 [ V_233 ] += V_281 ;
}
static void F_193 ( struct V_27 * V_30 )
{
F_194 ( V_30 -> V_125 -> V_256 , F_98 ( V_30 -> V_125 -> V_256 ) + 1 ) ;
V_30 -> V_125 -> V_292 = 0 ;
}
void F_195 ( struct V_293 * V_294 )
{
unsigned long V_295 , V_296 , V_92 = V_224 ;
struct V_27 * V_30 = V_172 ;
struct V_297 * V_125 = V_30 -> V_125 ;
T_2 V_240 = V_30 -> V_29 . V_96 ;
struct V_298 * V_299 ;
unsigned long V_300 , V_301 ;
unsigned long V_302 = 0 ;
long V_281 , V_303 ;
F_19 ( V_30 != F_21 ( V_294 , struct V_27 , V_304 ) ) ;
V_294 -> V_61 = V_294 ;
if ( V_30 -> V_115 & V_205 )
return;
if ( ! V_125 -> V_235 ) {
V_125 -> V_235 = V_92 +
F_155 ( V_305 ) ;
}
V_295 = V_125 -> V_235 ;
if ( F_196 ( V_92 , V_295 ) )
return;
if ( V_30 -> V_220 == 0 ) {
V_30 -> V_234 = F_100 ( V_30 ) ;
V_30 -> V_220 = F_97 ( V_30 ) ;
}
V_296 = V_92 + F_155 ( V_30 -> V_220 ) ;
if ( F_197 ( & V_125 -> V_235 , V_295 , V_296 ) != V_295 )
return;
V_30 -> V_306 += 2 * V_307 ;
V_300 = V_125 -> V_292 ;
V_281 = V_123 ;
V_281 <<= 20 - V_124 ;
V_303 = V_281 * 8 ;
if ( ! V_281 )
return;
F_198 ( & V_125 -> V_308 ) ;
V_299 = F_199 ( V_125 , V_300 ) ;
if ( ! V_299 ) {
F_193 ( V_30 ) ;
V_300 = 0 ;
V_299 = V_125 -> V_309 ;
}
for (; V_299 ; V_299 = V_299 -> V_310 ) {
if ( ! F_200 ( V_299 ) || ! F_201 ( V_299 ) ||
F_202 ( V_299 ) || ( V_299 -> V_311 & V_312 ) ) {
continue;
}
if ( ! V_299 -> V_313 ||
( V_299 -> V_314 && ( V_299 -> V_311 & ( V_315 | V_316 ) ) == ( V_315 ) ) )
continue;
if ( ! ( V_299 -> V_311 & ( V_315 | V_317 | V_316 ) ) )
continue;
do {
V_300 = F_69 ( V_300 , V_299 -> V_318 ) ;
V_301 = F_203 ( V_300 + ( V_281 << V_124 ) , V_319 ) ;
V_301 = F_154 ( V_301 , V_299 -> V_320 ) ;
V_302 = F_204 ( V_299 , V_300 , V_301 ) ;
if ( V_302 )
V_281 -= ( V_301 - V_300 ) >> V_124 ;
V_303 -= ( V_301 - V_300 ) >> V_124 ;
V_300 = V_301 ;
if ( V_281 <= 0 || V_303 <= 0 )
goto V_321;
F_205 () ;
} while ( V_301 != V_299 -> V_320 );
}
V_321:
if ( V_299 )
V_125 -> V_292 = V_300 ;
else
F_193 ( V_30 ) ;
F_206 ( & V_125 -> V_308 ) ;
if ( F_14 ( V_30 -> V_29 . V_96 != V_240 ) ) {
T_2 V_230 = V_30 -> V_29 . V_96 - V_240 ;
V_30 -> V_306 += 32 * V_230 ;
}
}
void F_207 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
struct V_293 * V_294 = & V_47 -> V_304 ;
T_2 V_239 , V_92 ;
if ( ! V_47 -> V_125 || ( V_47 -> V_115 & V_205 ) || V_294 -> V_61 != V_294 )
return;
V_92 = V_47 -> V_29 . V_96 ;
V_239 = ( T_2 ) V_47 -> V_220 * V_322 ;
if ( V_92 > V_47 -> V_306 + V_239 ) {
if ( ! V_47 -> V_306 )
V_47 -> V_220 = F_97 ( V_47 ) ;
V_47 -> V_306 += V_239 ;
if ( ! F_196 ( V_224 , V_47 -> V_125 -> V_235 ) ) {
F_208 ( V_294 , F_195 ) ;
F_209 ( V_47 , V_294 , true ) ;
}
}
}
static void F_207 ( struct V_25 * V_25 , struct V_27 * V_47 )
{
}
static inline void F_101 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_103 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static void
F_210 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_2 ( & V_26 -> V_73 , V_29 -> V_73 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_2 ( & F_17 ( V_26 ) -> V_73 , V_29 -> V_73 . V_5 ) ;
#ifdef F_211
if ( F_20 ( V_29 ) ) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
F_101 ( V_25 , F_18 ( V_29 ) ) ;
F_212 ( & V_29 -> V_323 , & V_25 -> V_324 ) ;
}
#endif
V_26 -> V_75 ++ ;
}
static void
F_213 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_3 ( & V_26 -> V_73 , V_29 -> V_73 . V_5 ) ;
if ( ! F_32 ( V_29 ) )
F_3 ( & F_17 ( V_26 ) -> V_73 , V_29 -> V_73 . V_5 ) ;
#ifdef F_211
if ( F_20 ( V_29 ) ) {
F_103 ( F_17 ( V_26 ) , F_18 ( V_29 ) ) ;
F_214 ( & V_29 -> V_323 ) ;
}
#endif
V_26 -> V_75 -- ;
}
static long F_215 ( struct V_26 * V_26 , struct V_325 * V_34 )
{
long V_326 , V_73 , V_327 ;
V_73 = F_13 ( V_26 -> V_73 . V_5 ) ;
V_326 = F_216 ( & V_34 -> V_82 ) ;
V_326 -= V_26 -> V_328 ;
V_326 += V_73 ;
V_327 = ( V_34 -> V_327 * V_73 ) ;
if ( V_326 )
V_327 /= V_326 ;
if ( V_327 < V_329 )
V_327 = V_329 ;
if ( V_327 > V_34 -> V_327 )
V_327 = V_34 -> V_327 ;
return V_327 ;
}
static inline long F_215 ( struct V_26 * V_26 , struct V_325 * V_34 )
{
return V_34 -> V_327 ;
}
static void F_217 ( struct V_26 * V_26 , struct V_28 * V_29 ,
unsigned long V_5 )
{
if ( V_29 -> V_48 ) {
if ( V_26 -> V_47 == V_29 )
F_66 ( V_26 ) ;
F_213 ( V_26 , V_29 ) ;
}
F_4 ( & V_29 -> V_73 , V_5 ) ;
if ( V_29 -> V_48 )
F_210 ( V_26 , V_29 ) ;
}
static void F_218 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
struct V_325 * V_34 ;
long V_327 ;
if ( ! V_26 )
return;
if ( F_219 ( V_26 ) )
return;
V_34 = V_26 -> V_34 ;
#ifndef F_211
if ( F_12 ( V_29 -> V_73 . V_5 == V_34 -> V_327 ) )
return;
#endif
V_327 = F_215 ( V_26 , V_34 ) ;
F_217 ( F_23 ( V_29 ) , V_29 , V_327 ) ;
}
static inline void F_218 ( struct V_28 * V_29 )
{
}
static T_10 T_2 F_220 ( T_2 V_330 , T_2 V_331 )
{
unsigned int V_332 ;
if ( ! V_331 )
return V_330 ;
else if ( F_14 ( V_331 > V_333 * 63 ) )
return 0 ;
V_332 = V_331 ;
if ( F_14 ( V_332 >= V_333 ) ) {
V_330 >>= V_332 / V_333 ;
V_332 %= V_333 ;
}
V_330 = F_16 ( V_330 , V_334 [ V_332 ] , 32 ) ;
return V_330 ;
}
static V_24 F_221 ( T_2 V_331 )
{
V_24 V_335 = 0 ;
if ( F_12 ( V_331 <= V_333 ) )
return V_336 [ V_331 ] ;
else if ( F_14 ( V_331 >= V_337 ) )
return V_84 ;
V_335 = V_338 [ V_331 / V_333 ] ;
V_331 %= V_333 ;
V_335 = F_220 ( V_335 , V_331 ) ;
return V_335 + V_336 [ V_331 ] ;
}
static T_10 int
F_222 ( T_2 V_92 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_339 , struct V_26 * V_26 )
{
T_2 V_44 , V_340 , V_341 ;
V_24 V_335 ;
unsigned int V_342 , V_343 , V_344 = 0 ;
unsigned long V_345 , V_346 ;
V_44 = V_92 - V_78 -> V_80 ;
if ( ( T_3 ) V_44 < 0 ) {
V_78 -> V_80 = V_92 ;
return 0 ;
}
V_44 >>= 10 ;
if ( ! V_44 )
return 0 ;
V_78 -> V_80 = V_92 ;
V_345 = F_223 ( NULL , V_1 ) ;
V_346 = F_224 ( NULL , V_1 ) ;
V_342 = V_78 -> V_81 ;
if ( V_44 + V_342 >= 1024 ) {
V_344 = 1 ;
V_78 -> V_81 = 0 ;
V_342 = 1024 - V_342 ;
V_343 = F_225 ( V_342 , V_345 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_343 ;
if ( V_26 ) {
V_26 -> V_347 +=
V_5 * V_343 ;
}
}
if ( V_339 )
V_78 -> V_86 += V_343 * V_346 ;
V_44 -= V_342 ;
V_341 = V_44 / 1024 ;
V_44 %= 1024 ;
V_78 -> V_83 = F_220 ( V_78 -> V_83 , V_341 + 1 ) ;
if ( V_26 ) {
V_26 -> V_347 =
F_220 ( V_26 -> V_347 , V_341 + 1 ) ;
}
V_78 -> V_86 = F_220 ( ( T_2 ) ( V_78 -> V_86 ) , V_341 + 1 ) ;
V_335 = F_221 ( V_341 ) ;
V_335 = F_225 ( V_335 , V_345 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_335 ;
if ( V_26 )
V_26 -> V_347 += V_5 * V_335 ;
}
if ( V_339 )
V_78 -> V_86 += V_335 * V_346 ;
}
V_340 = F_225 ( V_44 , V_345 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_340 ;
if ( V_26 )
V_26 -> V_347 += V_5 * V_340 ;
}
if ( V_339 )
V_78 -> V_86 += V_340 * V_346 ;
V_78 -> V_81 += V_44 ;
if ( V_344 ) {
V_78 -> V_82 = F_226 ( V_78 -> V_83 , V_84 ) ;
if ( V_26 ) {
V_26 -> V_348 =
F_226 ( V_26 -> V_347 , V_84 ) ;
}
V_78 -> V_85 = V_78 -> V_86 / V_84 ;
}
return V_344 ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 )
{
long V_44 = V_26 -> V_79 . V_82 - V_26 -> V_328 ;
if ( V_26 -> V_34 == & V_349 )
return;
if ( V_91 || abs ( V_44 ) > V_26 -> V_328 / 64 ) {
F_227 ( V_44 , & V_26 -> V_34 -> V_82 ) ;
V_26 -> V_328 = V_26 -> V_79 . V_82 ;
}
}
void F_228 ( struct V_28 * V_29 ,
struct V_26 * V_350 , struct V_26 * V_61 )
{
if ( ! F_229 ( V_351 ) )
return;
if ( V_29 -> V_79 . V_80 && V_350 ) {
T_2 V_352 ;
T_2 V_353 ;
#ifndef F_40
T_2 V_354 ;
T_2 V_355 ;
do {
V_354 = V_350 -> V_356 ;
V_355 = V_61 -> V_356 ;
F_230 () ;
V_352 = V_350 -> V_79 . V_80 ;
V_353 = V_61 -> V_79 . V_80 ;
} while ( V_352 != V_354 ||
V_353 != V_355 );
#else
V_352 = V_350 -> V_79 . V_80 ;
V_353 = V_61 -> V_79 . V_80 ;
#endif
F_222 ( V_352 , F_26 ( F_17 ( V_350 ) ) ,
& V_29 -> V_79 , 0 , 0 , NULL ) ;
V_29 -> V_79 . V_80 = V_353 ;
}
}
static inline void
F_231 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_357 = F_24 ( V_29 ) ;
long V_44 = V_357 -> V_79 . V_85 - V_29 -> V_79 . V_85 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_85 = V_357 -> V_79 . V_85 ;
V_29 -> V_79 . V_86 = V_29 -> V_79 . V_85 * V_84 ;
F_232 ( & V_26 -> V_79 . V_85 , V_44 ) ;
V_26 -> V_79 . V_86 = V_26 -> V_79 . V_85 * V_84 ;
}
static inline void
F_233 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_357 = F_24 ( V_29 ) ;
long V_44 , V_73 = V_357 -> V_79 . V_82 ;
if ( V_73 ) {
long V_358 ;
V_358 = F_216 ( & V_357 -> V_34 -> V_82 ) + 1 ;
V_358 -= V_357 -> V_328 ;
V_358 += V_73 ;
if ( V_358 > F_13 ( V_357 -> V_34 -> V_327 ) ) {
V_73 *= F_13 ( V_357 -> V_34 -> V_327 ) ;
V_73 /= V_358 ;
}
}
V_44 = V_73 - V_29 -> V_79 . V_82 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_82 = V_73 ;
V_29 -> V_79 . V_83 = V_29 -> V_79 . V_82 * V_84 ;
F_232 ( & V_26 -> V_79 . V_82 , V_44 ) ;
V_26 -> V_79 . V_83 = V_26 -> V_79 . V_82 * V_84 ;
if ( V_29 -> V_48 ) {
F_232 ( & V_26 -> V_348 , V_44 ) ;
V_26 -> V_347 = V_26 -> V_348 * V_84 ;
}
}
static inline void F_234 ( struct V_26 * V_26 )
{
V_26 -> V_359 = 1 ;
}
static inline int F_235 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
if ( ! V_26 -> V_359 )
return 0 ;
V_26 -> V_359 = 0 ;
return 1 ;
}
static inline int F_236 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
if ( F_20 ( V_29 ) )
return 0 ;
if ( ! F_235 ( V_29 ) )
return 0 ;
V_26 = F_23 ( V_29 ) ;
F_234 ( V_26 ) ;
F_231 ( V_26 , V_29 ) ;
F_233 ( V_26 , V_29 ) ;
return 1 ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 ) {}
static inline int F_236 ( struct V_28 * V_29 )
{
return 0 ;
}
static inline void F_234 ( struct V_26 * V_26 ) {}
static inline void F_237 ( struct V_26 * V_26 )
{
if ( & F_238 () -> V_42 == V_26 ) {
F_239 ( F_17 ( V_26 ) , 0 ) ;
}
}
static inline int
F_240 ( T_2 V_92 , struct V_26 * V_26 , bool V_360 )
{
struct V_77 * V_78 = & V_26 -> V_79 ;
int V_344 , V_361 = 0 , V_362 = 0 ;
if ( F_216 ( & V_26 -> V_363 ) ) {
T_3 V_364 = F_241 ( & V_26 -> V_363 , 0 ) ;
F_242 ( & V_78 -> V_82 , V_364 ) ;
F_242 ( & V_78 -> V_83 , V_364 * V_84 ) ;
V_361 = 1 ;
F_234 ( V_26 ) ;
}
if ( F_216 ( & V_26 -> V_365 ) ) {
long V_364 = F_241 ( & V_26 -> V_365 , 0 ) ;
F_242 ( & V_78 -> V_85 , V_364 ) ;
F_242 ( & V_78 -> V_86 , V_364 * V_84 ) ;
V_362 = 1 ;
F_234 ( V_26 ) ;
}
V_344 = F_222 ( V_92 , F_26 ( F_17 ( V_26 ) ) , V_78 ,
F_13 ( V_26 -> V_73 . V_5 ) , V_26 -> V_47 != NULL , V_26 ) ;
#ifndef F_40
F_41 () ;
V_26 -> V_356 = V_78 -> V_80 ;
#endif
if ( V_360 && ( V_344 || V_362 ) )
F_237 ( V_26 ) ;
return V_344 || V_361 ;
}
static inline void F_243 ( struct V_28 * V_29 , int V_115 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_92 = F_63 ( V_26 ) ;
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
int V_344 ;
if ( V_29 -> V_79 . V_80 && ! ( V_115 & V_366 ) ) {
F_222 ( V_92 , V_1 , & V_29 -> V_79 ,
V_29 -> V_48 * F_13 ( V_29 -> V_73 . V_5 ) ,
V_26 -> V_47 == V_29 , NULL ) ;
}
V_344 = F_240 ( V_92 , V_26 , true ) ;
V_344 |= F_236 ( V_29 ) ;
if ( V_344 && ( V_115 & V_367 ) )
F_65 ( V_26 , 0 ) ;
}
static void F_244 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_79 . V_80 = V_26 -> V_79 . V_80 ;
V_26 -> V_79 . V_82 += V_29 -> V_79 . V_82 ;
V_26 -> V_79 . V_83 += V_29 -> V_79 . V_83 ;
V_26 -> V_79 . V_85 += V_29 -> V_79 . V_85 ;
V_26 -> V_79 . V_86 += V_29 -> V_79 . V_86 ;
F_234 ( V_26 ) ;
F_237 ( V_26 ) ;
}
static void F_245 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_242 ( & V_26 -> V_79 . V_82 , V_29 -> V_79 . V_82 ) ;
F_242 ( & V_26 -> V_79 . V_83 , V_29 -> V_79 . V_83 ) ;
F_242 ( & V_26 -> V_79 . V_85 , V_29 -> V_79 . V_85 ) ;
F_242 ( & V_26 -> V_79 . V_86 , V_29 -> V_79 . V_86 ) ;
F_234 ( V_26 ) ;
F_237 ( V_26 ) ;
}
static inline void
F_246 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_77 * V_78 = & V_29 -> V_79 ;
V_26 -> V_348 += V_78 -> V_82 ;
V_26 -> V_347 += V_78 -> V_83 ;
if ( ! V_78 -> V_80 ) {
F_244 ( V_26 , V_29 ) ;
F_65 ( V_26 , 0 ) ;
}
}
static inline void
F_247 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_26 -> V_348 =
F_99 ( long , V_26 -> V_348 - V_29 -> V_79 . V_82 , 0 ) ;
V_26 -> V_347 =
F_99 ( T_3 , V_26 -> V_347 - V_29 -> V_79 . V_83 , 0 ) ;
}
static inline T_2 F_248 ( struct V_26 * V_26 )
{
T_2 V_368 ;
T_2 V_80 ;
do {
V_368 = V_26 -> V_356 ;
F_230 () ;
V_80 = V_26 -> V_79 . V_80 ;
} while ( V_80 != V_368 );
return V_80 ;
}
static inline T_2 F_248 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_80 ;
}
void F_249 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_80 ;
V_80 = F_248 ( V_26 ) ;
F_222 ( V_80 , F_26 ( F_17 ( V_26 ) ) , & V_29 -> V_79 , 0 , 0 , NULL ) ;
}
void F_250 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_249 ( V_29 ) ;
F_227 ( V_29 -> V_79 . V_82 , & V_26 -> V_363 ) ;
F_227 ( V_29 -> V_79 . V_85 , & V_26 -> V_365 ) ;
}
static inline unsigned long F_251 ( struct V_26 * V_26 )
{
return V_26 -> V_348 ;
}
static inline unsigned long F_252 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_82 ;
}
static inline int
F_240 ( T_2 V_92 , struct V_26 * V_26 , bool V_360 )
{
return 0 ;
}
static inline void F_243 ( struct V_28 * V_29 , int V_369 )
{
F_239 ( F_17 ( F_23 ( V_29 ) ) , 0 ) ;
}
static inline void
F_246 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_247 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void F_250 ( struct V_28 * V_29 ) {}
static inline void
F_244 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_245 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline int F_253 ( struct V_25 * V_25 , struct V_370 * V_371 )
{
return 0 ;
}
static void F_254 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
#ifdef F_255
T_3 V_372 = V_29 -> V_43 - V_26 -> F_36 ;
if ( V_372 < 0 )
V_372 = - V_372 ;
if ( V_372 > 3 * V_71 )
F_83 ( V_26 -> V_373 ) ;
#endif
}
static void
F_256 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_374 )
{
T_2 V_43 = V_26 -> F_36 ;
if ( V_374 && F_229 ( V_375 ) )
V_43 += F_60 ( V_26 , V_29 ) ;
if ( ! V_374 ) {
unsigned long V_376 = V_71 ;
if ( F_229 ( V_377 ) )
V_376 >>= 1 ;
V_43 -= V_376 ;
}
V_29 -> V_43 = F_35 ( V_29 -> V_43 , V_43 ) ;
}
static inline void F_257 ( void )
{
#ifdef F_258
if ( F_77 () )
return;
if ( F_259 () ||
F_260 () ||
F_261 () ||
F_262 () ||
F_263 () ) {
F_264 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_265 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
bool V_378 = ! ( V_115 & V_116 ) || ( V_115 & V_379 ) ;
bool V_47 = V_26 -> V_47 == V_29 ;
if ( V_378 && V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_66 ( V_26 ) ;
if ( V_378 && ! V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_243 ( V_29 , V_367 ) ;
F_246 ( V_26 , V_29 ) ;
F_218 ( V_29 ) ;
F_210 ( V_26 , V_29 ) ;
if ( V_115 & V_116 )
F_256 ( V_26 , V_29 , 0 ) ;
F_257 () ;
F_91 ( V_26 , V_29 , V_115 ) ;
F_254 ( V_26 , V_29 ) ;
if ( ! V_47 )
F_42 ( V_26 , V_29 ) ;
V_29 -> V_48 = 1 ;
if ( V_26 -> V_75 == 1 ) {
F_25 ( V_26 ) ;
F_266 ( V_26 ) ;
}
}
static void F_267 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_62 != V_29 )
break;
V_26 -> V_62 = NULL ;
}
}
static void F_268 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_61 != V_29 )
break;
V_26 -> V_61 = NULL ;
}
}
static void F_269 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_380 != V_29 )
break;
V_26 -> V_380 = NULL ;
}
}
static void F_270 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_62 == V_29 )
F_267 ( V_29 ) ;
if ( V_26 -> V_61 == V_29 )
F_268 ( V_29 ) ;
if ( V_26 -> V_380 == V_29 )
F_269 ( V_29 ) ;
}
static void
F_271 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
F_66 ( V_26 ) ;
F_243 ( V_29 , V_367 ) ;
F_247 ( V_26 , V_29 ) ;
F_92 ( V_26 , V_29 , V_115 ) ;
F_270 ( V_26 , V_29 ) ;
if ( V_29 != V_26 -> V_47 )
F_45 ( V_26 , V_29 ) ;
V_29 -> V_48 = 0 ;
F_213 ( V_26 , V_29 ) ;
if ( ! ( V_115 & V_117 ) )
V_29 -> V_43 -= V_26 -> F_36 ;
F_272 ( V_26 ) ;
F_218 ( V_29 ) ;
if ( ( V_115 & ( V_381 | V_382 ) ) == V_381 )
F_38 ( V_26 ) ;
}
static void
F_273 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
unsigned long V_383 , V_20 ;
struct V_28 * V_29 ;
T_3 V_44 ;
V_383 = F_58 ( V_26 , V_47 ) ;
V_20 = V_47 -> V_96 - V_47 -> V_384 ;
if ( V_20 > V_383 ) {
F_274 ( F_17 ( V_26 ) ) ;
F_270 ( V_26 , V_47 ) ;
return;
}
if ( V_20 < V_72 )
return;
V_29 = F_48 ( V_26 ) ;
V_44 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_44 < 0 )
return;
if ( V_44 > V_383 )
F_274 ( F_17 ( V_26 ) ) ;
}
static void
F_275 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_29 -> V_48 ) {
F_81 ( V_26 , V_29 ) ;
F_45 ( V_26 , V_29 ) ;
F_243 ( V_29 , V_367 ) ;
}
F_93 ( V_26 , V_29 ) ;
V_26 -> V_47 = V_29 ;
if ( F_77 () && F_17 ( V_26 ) -> V_73 . V_5 >= 2 * V_29 -> V_73 . V_5 ) {
F_68 ( V_29 -> V_94 . V_385 ,
F_69 ( ( T_2 ) F_79 ( V_29 -> V_94 . V_385 ) ,
V_29 -> V_96 - V_29 -> V_384 ) ) ;
}
V_29 -> V_384 = V_29 -> V_96 ;
}
static struct V_28 *
F_276 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
struct V_28 * V_60 = F_48 ( V_26 ) ;
struct V_28 * V_29 ;
if ( ! V_60 || ( V_47 && F_37 ( V_47 , V_60 ) ) )
V_60 = V_47 ;
V_29 = V_60 ;
if ( V_26 -> V_380 == V_29 ) {
struct V_28 * V_386 ;
if ( V_29 == V_47 ) {
V_386 = F_48 ( V_26 ) ;
} else {
V_386 = F_49 ( V_29 ) ;
if ( ! V_386 || ( V_47 && F_37 ( V_47 , V_386 ) ) )
V_386 = V_47 ;
}
if ( V_386 && F_277 ( V_386 , V_60 ) < 1 )
V_29 = V_386 ;
}
if ( V_26 -> V_62 && F_277 ( V_26 -> V_62 , V_60 ) < 1 )
V_29 = V_26 -> V_62 ;
if ( V_26 -> V_61 && F_277 ( V_26 -> V_61 , V_60 ) < 1 )
V_29 = V_26 -> V_61 ;
F_270 ( V_26 , V_29 ) ;
return V_29 ;
}
static void F_278 ( struct V_26 * V_26 , struct V_28 * V_350 )
{
if ( V_350 -> V_48 )
F_66 ( V_26 ) ;
F_279 ( V_26 ) ;
F_254 ( V_26 , V_350 ) ;
if ( V_350 -> V_48 ) {
F_76 ( V_26 , V_350 ) ;
F_42 ( V_26 , V_350 ) ;
F_243 ( V_350 , 0 ) ;
}
V_26 -> V_47 = NULL ;
}
static void
F_280 ( struct V_26 * V_26 , struct V_28 * V_47 , int V_387 )
{
F_66 ( V_26 ) ;
F_243 ( V_47 , V_367 ) ;
F_218 ( V_47 ) ;
#ifdef F_281
if ( V_387 ) {
F_274 ( F_17 ( V_26 ) ) ;
return;
}
if ( ! F_229 ( V_388 ) &&
F_282 ( & F_17 ( V_26 ) -> V_389 ) )
return;
#endif
if ( V_26 -> V_75 > 1 )
F_273 ( V_26 , V_47 ) ;
}
static inline bool F_283 ( void )
{
return F_284 ( & V_390 ) ;
}
void F_285 ( void )
{
F_286 ( & V_390 ) ;
}
void F_287 ( void )
{
F_288 ( & V_390 ) ;
}
static bool F_283 ( void )
{
return true ;
}
void F_285 ( void ) {}
void F_287 ( void ) {}
static inline T_2 F_289 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_290 ( void )
{
return ( T_2 ) V_391 * V_392 ;
}
void F_291 ( struct V_393 * V_394 )
{
T_2 V_92 ;
if ( V_394 -> V_395 == V_396 )
return;
V_92 = F_292 ( F_293 () ) ;
V_394 -> V_240 = V_394 -> V_395 ;
V_394 -> V_397 = V_92 + F_294 ( V_394 -> V_239 ) ;
}
static inline struct V_393 * F_295 ( struct V_325 * V_34 )
{
return & V_34 -> V_393 ;
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
if ( F_14 ( V_26 -> V_398 ) )
return V_26 -> V_399 - V_26 -> V_400 ;
return F_67 ( F_17 ( V_26 ) ) - V_26 -> V_400 ;
}
static int F_296 ( struct V_26 * V_26 )
{
struct V_325 * V_34 = V_26 -> V_34 ;
struct V_393 * V_394 = F_295 ( V_34 ) ;
T_2 V_401 = 0 , V_402 , V_403 ;
V_402 = F_290 () - V_26 -> V_404 ;
F_297 ( & V_394 -> V_257 ) ;
if ( V_394 -> V_395 == V_396 )
V_401 = V_402 ;
else {
F_298 ( V_394 ) ;
if ( V_394 -> V_240 > 0 ) {
V_401 = F_154 ( V_394 -> V_240 , V_402 ) ;
V_394 -> V_240 -= V_401 ;
V_394 -> V_405 = 0 ;
}
}
V_403 = V_394 -> V_397 ;
F_299 ( & V_394 -> V_257 ) ;
V_26 -> V_404 += V_401 ;
if ( ( T_3 ) ( V_403 - V_26 -> V_397 ) > 0 )
V_26 -> V_397 = V_403 ;
return V_26 -> V_404 > 0 ;
}
static void F_300 ( struct V_26 * V_26 )
{
struct V_393 * V_394 = F_295 ( V_26 -> V_34 ) ;
if ( F_12 ( ( T_3 ) ( F_78 ( F_17 ( V_26 ) ) - V_26 -> V_397 ) < 0 ) )
return;
if ( V_26 -> V_404 < 0 )
return;
if ( V_26 -> V_397 != V_394 -> V_397 ) {
V_26 -> V_397 += V_307 ;
} else {
V_26 -> V_404 = 0 ;
}
}
static void F_301 ( struct V_26 * V_26 , T_2 V_20 )
{
V_26 -> V_404 -= V_20 ;
F_300 ( V_26 ) ;
if ( F_12 ( V_26 -> V_404 > 0 ) )
return;
if ( ! F_296 ( V_26 ) && F_12 ( V_26 -> V_47 ) )
F_274 ( F_17 ( V_26 ) ) ;
}
static T_10
void F_74 ( struct V_26 * V_26 , T_2 V_20 )
{
if ( ! F_283 () || ! V_26 -> V_406 )
return;
F_301 ( V_26 , V_20 ) ;
}
static inline int F_302 ( struct V_26 * V_26 )
{
return F_283 () && V_26 -> V_407 ;
}
static inline int F_219 ( struct V_26 * V_26 )
{
return F_283 () && V_26 -> V_398 ;
}
static inline int F_303 ( struct V_325 * V_34 ,
int V_201 , int V_408 )
{
struct V_26 * V_409 , * V_410 ;
V_409 = V_34 -> V_26 [ V_201 ] ;
V_410 = V_34 -> V_26 [ V_408 ] ;
return F_219 ( V_409 ) ||
F_219 ( V_410 ) ;
}
static int F_304 ( struct V_325 * V_34 , void * V_411 )
{
struct V_25 * V_25 = V_411 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
V_26 -> V_398 -- ;
if ( ! V_26 -> V_398 ) {
V_26 -> V_400 += F_67 ( V_25 ) -
V_26 -> V_399 ;
}
return 0 ;
}
static int F_305 ( struct V_325 * V_34 , void * V_411 )
{
struct V_25 * V_25 = V_411 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_398 )
V_26 -> V_399 = F_67 ( V_25 ) ;
V_26 -> V_398 ++ ;
return 0 ;
}
static void F_306 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_393 * V_394 = F_295 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
long V_412 , V_413 = 1 ;
bool V_414 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
F_134 () ;
F_307 ( V_26 -> V_34 , F_305 , V_415 , ( void * ) V_25 ) ;
F_142 () ;
V_412 = V_26 -> V_416 ;
F_59 (se) {
struct V_26 * V_417 = F_23 ( V_29 ) ;
if ( ! V_29 -> V_48 )
break;
if ( V_413 )
F_271 ( V_417 , V_29 , V_117 ) ;
V_417 -> V_416 -= V_412 ;
if ( V_417 -> V_73 . V_5 )
V_413 = 0 ;
}
if ( ! V_29 )
F_308 ( V_25 , V_412 ) ;
V_26 -> V_407 = 1 ;
V_26 -> V_418 = F_78 ( V_25 ) ;
F_297 ( & V_394 -> V_257 ) ;
V_414 = F_309 ( & V_394 -> V_419 ) ;
F_28 ( & V_26 -> V_420 , & V_394 -> V_419 ) ;
if ( V_414 )
F_298 ( V_394 ) ;
F_299 ( & V_394 -> V_257 ) ;
}
void F_310 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_393 * V_394 = F_295 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
int V_421 = 1 ;
long V_412 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
V_26 -> V_407 = 0 ;
F_311 ( V_25 ) ;
F_297 ( & V_394 -> V_257 ) ;
V_394 -> V_422 += F_78 ( V_25 ) - V_26 -> V_418 ;
F_30 ( & V_26 -> V_420 ) ;
F_299 ( & V_394 -> V_257 ) ;
F_307 ( V_26 -> V_34 , V_415 , F_304 , ( void * ) V_25 ) ;
if ( ! V_26 -> V_73 . V_5 )
return;
V_412 = V_26 -> V_416 ;
F_59 (se) {
if ( V_29 -> V_48 )
V_421 = 0 ;
V_26 = F_23 ( V_29 ) ;
if ( V_421 )
F_265 ( V_26 , V_29 , V_116 ) ;
V_26 -> V_416 += V_412 ;
if ( F_302 ( V_26 ) )
break;
}
if ( ! V_29 )
F_312 ( V_25 , V_412 ) ;
if ( V_25 -> V_47 == V_25 -> V_405 && V_25 -> V_42 . V_75 )
F_274 ( V_25 ) ;
}
static T_2 F_313 ( struct V_393 * V_394 ,
T_2 V_423 , T_2 V_403 )
{
struct V_26 * V_26 ;
T_2 V_240 ;
T_2 V_424 = V_423 ;
F_134 () ;
F_314 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
F_297 ( & V_25 -> V_257 ) ;
if ( ! F_302 ( V_26 ) )
goto V_61;
V_240 = - V_26 -> V_404 + 1 ;
if ( V_240 > V_423 )
V_240 = V_423 ;
V_423 -= V_240 ;
V_26 -> V_404 += V_240 ;
V_26 -> V_397 = V_403 ;
if ( V_26 -> V_404 > 0 )
F_310 ( V_26 ) ;
V_61:
F_299 ( & V_25 -> V_257 ) ;
if ( ! V_423 )
break;
}
F_142 () ;
return V_424 - V_423 ;
}
static int F_315 ( struct V_393 * V_394 , int V_425 )
{
T_2 V_240 , V_397 ;
int V_407 ;
if ( V_394 -> V_395 == V_396 )
goto V_426;
V_407 = ! F_309 ( & V_394 -> V_419 ) ;
V_394 -> V_427 += V_425 ;
if ( V_394 -> V_405 && ! V_407 )
goto V_426;
F_291 ( V_394 ) ;
if ( ! V_407 ) {
V_394 -> V_405 = 1 ;
return 0 ;
}
V_394 -> V_428 += V_425 ;
V_397 = V_394 -> V_397 ;
while ( V_407 && V_394 -> V_240 > 0 ) {
V_240 = V_394 -> V_240 ;
F_299 ( & V_394 -> V_257 ) ;
V_240 = F_313 ( V_394 , V_240 ,
V_397 ) ;
F_297 ( & V_394 -> V_257 ) ;
V_407 = ! F_309 ( & V_394 -> V_419 ) ;
V_394 -> V_240 -= F_154 ( V_240 , V_394 -> V_240 ) ;
}
V_394 -> V_405 = 0 ;
return 0 ;
V_426:
return 1 ;
}
static int F_316 ( struct V_393 * V_394 , T_2 V_429 )
{
struct V_430 * V_431 = & V_394 -> V_432 ;
T_2 V_423 ;
if ( F_317 ( V_431 ) )
return 1 ;
V_423 = F_294 ( F_318 ( V_431 ) ) ;
if ( V_423 < V_429 )
return 1 ;
return 0 ;
}
static void F_319 ( struct V_393 * V_394 )
{
T_2 V_433 = V_434 + V_435 ;
if ( F_316 ( V_394 , V_433 ) )
return;
F_320 ( & V_394 -> V_436 ,
F_321 ( V_434 ) ,
V_437 ) ;
}
static void F_322 ( struct V_26 * V_26 )
{
struct V_393 * V_394 = F_295 ( V_26 -> V_34 ) ;
T_3 V_438 = V_26 -> V_404 - V_439 ;
if ( V_438 <= 0 )
return;
F_297 ( & V_394 -> V_257 ) ;
if ( V_394 -> V_395 != V_396 &&
V_26 -> V_397 == V_394 -> V_397 ) {
V_394 -> V_240 += V_438 ;
if ( V_394 -> V_240 > F_290 () &&
! F_309 ( & V_394 -> V_419 ) )
F_319 ( V_394 ) ;
}
F_299 ( & V_394 -> V_257 ) ;
V_26 -> V_404 -= V_438 ;
}
static T_10 void F_272 ( struct V_26 * V_26 )
{
if ( ! F_283 () )
return;
if ( ! V_26 -> V_406 || V_26 -> V_75 )
return;
F_322 ( V_26 ) ;
}
static void F_323 ( struct V_393 * V_394 )
{
T_2 V_240 = 0 , V_76 = F_290 () ;
T_2 V_403 ;
F_297 ( & V_394 -> V_257 ) ;
if ( F_316 ( V_394 , V_435 ) ) {
F_299 ( & V_394 -> V_257 ) ;
return;
}
if ( V_394 -> V_395 != V_396 && V_394 -> V_240 > V_76 )
V_240 = V_394 -> V_240 ;
V_403 = V_394 -> V_397 ;
F_299 ( & V_394 -> V_257 ) ;
if ( ! V_240 )
return;
V_240 = F_313 ( V_394 , V_240 , V_403 ) ;
F_297 ( & V_394 -> V_257 ) ;
if ( V_403 == V_394 -> V_397 )
V_394 -> V_240 -= F_154 ( V_240 , V_394 -> V_240 ) ;
F_299 ( & V_394 -> V_257 ) ;
}
static void F_266 ( struct V_26 * V_26 )
{
if ( ! F_283 () )
return;
if ( ! V_26 -> V_406 || V_26 -> V_47 )
return;
if ( F_302 ( V_26 ) )
return;
F_74 ( V_26 , 0 ) ;
if ( V_26 -> V_404 <= 0 )
F_306 ( V_26 ) ;
}
static void F_324 ( struct V_325 * V_34 , int V_1 )
{
struct V_26 * V_440 , * V_26 ;
if ( ! F_283 () )
return;
if ( ! V_34 -> V_35 )
return;
V_26 = V_34 -> V_26 [ V_1 ] ;
V_440 = V_34 -> V_35 -> V_26 [ V_1 ] ;
V_26 -> V_398 = V_440 -> V_398 ;
V_26 -> V_399 = F_67 ( F_124 ( V_1 ) ) ;
}
static bool F_279 ( struct V_26 * V_26 )
{
if ( ! F_283 () )
return false ;
if ( F_12 ( ! V_26 -> V_406 || V_26 -> V_404 > 0 ) )
return false ;
if ( F_302 ( V_26 ) )
return true ;
F_306 ( V_26 ) ;
return true ;
}
static enum V_441 F_325 ( struct V_430 * V_442 )
{
struct V_393 * V_394 =
F_21 ( V_442 , struct V_393 , V_436 ) ;
F_323 ( V_394 ) ;
return V_443 ;
}
static enum V_441 F_326 ( struct V_430 * V_442 )
{
struct V_393 * V_394 =
F_21 ( V_442 , struct V_393 , V_432 ) ;
int V_425 ;
int V_405 = 0 ;
F_297 ( & V_394 -> V_257 ) ;
for (; ; ) {
V_425 = F_327 ( V_442 , V_394 -> V_239 ) ;
if ( ! V_425 )
break;
V_405 = F_315 ( V_394 , V_425 ) ;
}
if ( V_405 )
V_394 -> V_444 = 0 ;
F_299 ( & V_394 -> V_257 ) ;
return V_405 ? V_443 : V_445 ;
}
void F_328 ( struct V_393 * V_394 )
{
F_329 ( & V_394 -> V_257 ) ;
V_394 -> V_240 = 0 ;
V_394 -> V_395 = V_396 ;
V_394 -> V_239 = F_321 ( F_289 () ) ;
F_330 ( & V_394 -> V_419 ) ;
F_331 ( & V_394 -> V_432 , V_446 , V_447 ) ;
V_394 -> V_432 . V_448 = F_326 ;
F_331 ( & V_394 -> V_436 , V_446 , V_437 ) ;
V_394 -> V_436 . V_448 = F_325 ;
}
static void F_332 ( struct V_26 * V_26 )
{
V_26 -> V_406 = 0 ;
F_330 ( & V_26 -> V_420 ) ;
}
void F_298 ( struct V_393 * V_394 )
{
F_333 ( & V_394 -> V_257 ) ;
if ( ! V_394 -> V_444 ) {
V_394 -> V_444 = 1 ;
F_327 ( & V_394 -> V_432 , V_394 -> V_239 ) ;
F_334 ( & V_394 -> V_432 , V_447 ) ;
}
}
static void F_335 ( struct V_393 * V_394 )
{
if ( ! V_394 -> V_419 . V_61 )
return;
F_336 ( & V_394 -> V_432 ) ;
F_336 ( & V_394 -> V_436 ) ;
}
static void T_11 F_337 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_338 (rq, cfs_rq) {
struct V_393 * V_394 = & V_26 -> V_34 -> V_393 ;
F_297 ( & V_394 -> V_257 ) ;
V_26 -> V_406 = V_394 -> V_395 != V_396 ;
F_299 ( & V_394 -> V_257 ) ;
}
}
static void T_11 F_339 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_338 (rq, cfs_rq) {
if ( ! V_26 -> V_406 )
continue;
V_26 -> V_404 = 1 ;
V_26 -> V_406 = 0 ;
if ( F_302 ( V_26 ) )
F_310 ( V_26 ) ;
}
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
return F_67 ( F_17 ( V_26 ) ) ;
}
static void F_74 ( struct V_26 * V_26 , T_2 V_20 ) {}
static bool F_279 ( struct V_26 * V_26 ) { return false ; }
static void F_266 ( struct V_26 * V_26 ) {}
static inline void F_324 ( struct V_325 * V_34 , int V_1 ) {}
static T_10 void F_272 ( struct V_26 * V_26 ) {}
static inline int F_302 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_219 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_303 ( struct V_325 * V_34 ,
int V_201 , int V_408 )
{
return 0 ;
}
void F_328 ( struct V_393 * V_394 ) {}
static void F_332 ( struct V_26 * V_26 ) {}
static inline struct V_393 * F_295 ( struct V_325 * V_34 )
{
return NULL ;
}
static inline void F_335 ( struct V_393 * V_394 ) {}
static inline void F_337 ( struct V_25 * V_25 ) {}
static inline void F_339 ( struct V_25 * V_25 ) {}
static void F_340 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_19 ( F_34 ( V_30 ) != V_25 ) ;
if ( V_25 -> V_42 . V_416 > 1 ) {
T_2 V_76 = F_58 ( V_26 , V_29 ) ;
T_2 V_449 = V_29 -> V_96 - V_29 -> V_384 ;
T_3 V_44 = V_76 - V_449 ;
if ( V_44 < 0 ) {
if ( V_25 -> V_47 == V_30 )
F_274 ( V_25 ) ;
return;
}
F_341 ( V_25 , V_44 ) ;
}
}
static void F_342 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
if ( ! F_343 ( V_25 ) || V_47 -> V_89 != & V_90 )
return;
if ( F_23 ( & V_47 -> V_29 ) -> V_75 < V_70 )
F_340 ( V_25 , V_47 ) ;
}
static inline void
F_340 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_342 ( struct V_25 * V_25 )
{
}
static void
F_344 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_110 )
F_345 ( V_25 , V_450 ) ;
F_59 (se) {
if ( V_29 -> V_48 )
break;
V_26 = F_23 ( V_29 ) ;
F_265 ( V_26 , V_29 , V_115 ) ;
if ( F_302 ( V_26 ) )
break;
V_26 -> V_416 ++ ;
V_115 = V_116 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_416 ++ ;
if ( F_302 ( V_26 ) )
break;
F_243 ( V_29 , V_367 ) ;
F_218 ( V_29 ) ;
}
if ( ! V_29 )
F_312 ( V_25 , 1 ) ;
F_342 ( V_25 ) ;
}
static void F_346 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
int V_451 = V_115 & V_117 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_271 ( V_26 , V_29 , V_115 ) ;
if ( F_302 ( V_26 ) )
break;
V_26 -> V_416 -- ;
if ( V_26 -> V_73 . V_5 ) {
V_29 = F_32 ( V_29 ) ;
if ( V_451 && V_29 && ! F_219 ( V_26 ) )
F_347 ( V_29 ) ;
break;
}
V_115 |= V_117 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_416 -- ;
if ( F_302 ( V_26 ) )
break;
F_243 ( V_29 , V_367 ) ;
F_218 ( V_29 ) ;
}
if ( ! V_29 )
F_308 ( V_25 , 1 ) ;
F_342 ( V_25 ) ;
}
static unsigned long
F_348 ( unsigned long V_73 , unsigned long V_452 , int V_453 )
{
int V_454 = 0 ;
if ( ! V_452 )
return V_73 ;
if ( V_452 >= V_455 [ V_453 ] )
return 0 ;
if ( V_453 == 1 )
return V_73 >> V_452 ;
while ( V_452 ) {
if ( V_452 % 2 )
V_73 = ( V_73 * V_456 [ V_453 ] [ V_454 ] ) >> V_457 ;
V_452 >>= 1 ;
V_454 ++ ;
}
return V_73 ;
}
static void F_349 ( struct V_25 * F_238 , unsigned long V_458 ,
unsigned long V_459 )
{
unsigned long T_11 V_460 = F_238 -> V_461 [ 0 ] ;
int V_272 , V_462 ;
F_238 -> V_463 ++ ;
F_238 -> V_461 [ 0 ] = V_458 ;
for ( V_272 = 1 , V_462 = 2 ; V_272 < V_464 ; V_272 ++ , V_462 += V_462 ) {
unsigned long V_465 , V_466 ;
V_465 = F_238 -> V_461 [ V_272 ] ;
#ifdef F_350
V_465 = F_348 ( V_465 , V_459 - 1 , V_272 ) ;
if ( V_460 ) {
V_465 -= F_348 ( V_460 , V_459 - 1 , V_272 ) ;
V_465 += V_460 ;
}
#endif
V_466 = V_458 ;
if ( V_466 > V_465 )
V_466 += V_462 - 1 ;
F_238 -> V_461 [ V_272 ] = ( V_465 * ( V_462 - 1 ) + V_466 ) >> V_272 ;
}
F_351 ( F_238 ) ;
}
static unsigned long F_125 ( const int V_1 )
{
return F_251 ( & F_124 ( V_1 ) -> V_42 ) ;
}
static void F_352 ( struct V_25 * F_238 ,
unsigned long V_467 ,
unsigned long V_73 )
{
unsigned long V_459 ;
V_459 = V_467 - F_238 -> V_468 ;
if ( V_459 ) {
F_238 -> V_468 = V_467 ;
F_349 ( F_238 , V_73 , V_459 ) ;
}
}
static void F_353 ( struct V_25 * F_238 )
{
if ( F_125 ( F_26 ( F_238 ) ) )
return;
F_352 ( F_238 , F_98 ( V_224 ) , 0 ) ;
}
void F_354 ( void )
{
struct V_25 * F_238 = F_238 () ;
F_238 -> V_461 [ 0 ] = F_125 ( F_26 ( F_238 ) ) ;
}
void F_355 ( void )
{
unsigned long V_467 = F_98 ( V_224 ) ;
struct V_25 * F_238 = F_238 () ;
unsigned long V_73 ;
if ( V_467 == F_238 -> V_468 )
return;
V_73 = F_125 ( F_26 ( F_238 ) ) ;
F_297 ( & F_238 -> V_257 ) ;
F_311 ( F_238 ) ;
F_352 ( F_238 , V_467 , V_73 ) ;
F_299 ( & F_238 -> V_257 ) ;
}
static inline void F_352 ( struct V_25 * F_238 ,
unsigned long V_467 ,
unsigned long V_73 ) { }
static void F_356 ( struct V_25 * F_238 , unsigned long V_73 )
{
#ifdef F_350
F_238 -> V_468 = F_98 ( V_224 ) ;
#endif
F_349 ( F_238 , V_73 , 1 ) ;
}
void F_357 ( struct V_25 * F_238 )
{
unsigned long V_73 = F_125 ( F_26 ( F_238 ) ) ;
if ( F_358 () )
F_352 ( F_238 , F_98 ( V_224 ) , V_73 ) ;
else
F_356 ( F_238 , V_73 ) ;
}
static unsigned long F_359 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_469 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_229 ( V_470 ) )
return V_469 ;
return F_154 ( V_25 -> V_461 [ type - 1 ] , V_469 ) ;
}
static unsigned long F_360 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_469 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_229 ( V_470 ) )
return V_469 ;
return F_69 ( V_25 -> V_461 [ type - 1 ] , V_469 ) ;
}
static unsigned long F_126 ( int V_1 )
{
return F_124 ( V_1 ) -> V_471 ;
}
static unsigned long F_361 ( int V_1 )
{
return F_124 ( V_1 ) -> V_472 ;
}
static unsigned long F_362 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_75 = F_98 ( V_25 -> V_42 . V_416 ) ;
unsigned long V_82 = F_125 ( V_1 ) ;
if ( V_75 )
return V_82 / V_75 ;
return 0 ;
}
static long F_363 ( struct V_325 * V_34 , int V_1 , long V_473 , long V_474 )
{
struct V_28 * V_29 = V_34 -> V_29 [ V_1 ] ;
if ( ! V_34 -> V_35 )
return V_473 ;
F_59 (se) {
struct V_26 * V_26 = V_29 -> V_32 ;
long V_475 , V_8 = F_252 ( V_26 ) ;
V_34 = V_26 -> V_34 ;
V_475 = V_474 + F_216 ( & V_34 -> V_82 ) ;
V_475 -= V_26 -> V_328 ;
V_475 += V_8 ;
V_8 += V_473 ;
if ( V_475 > 0 && V_8 < V_475 )
V_473 = ( V_8 * ( long ) F_13 ( V_34 -> V_327 ) ) / V_475 ;
else
V_473 = F_13 ( V_34 -> V_327 ) ;
if ( V_473 < V_329 )
V_473 = V_329 ;
V_473 -= V_29 -> V_79 . V_82 ;
V_474 = 0 ;
}
return V_473 ;
}
static long F_363 ( struct V_325 * V_34 , int V_1 , long V_473 , long V_474 )
{
return V_473 ;
}
static void F_364 ( struct V_27 * V_30 )
{
if ( F_192 ( V_224 , V_172 -> V_476 + V_222 ) ) {
V_172 -> V_477 >>= 1 ;
V_172 -> V_476 = V_224 ;
}
if ( V_172 -> V_478 != V_30 ) {
V_172 -> V_478 = V_30 ;
V_172 -> V_477 ++ ;
}
}
static int F_365 ( struct V_27 * V_30 )
{
unsigned int V_479 = V_172 -> V_477 ;
unsigned int V_480 = V_30 -> V_477 ;
int V_10 = F_366 ( V_481 ) ;
if ( V_479 < V_480 )
F_132 ( V_479 , V_480 ) ;
if ( V_480 < V_10 || V_479 < V_480 * V_10 )
return 0 ;
return 1 ;
}
static int F_367 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_482 , int V_483 )
{
T_3 V_458 , V_73 ;
T_3 V_484 , V_485 ;
int V_453 , V_486 ;
struct V_325 * V_34 ;
unsigned long V_5 ;
int V_487 ;
V_453 = V_213 -> V_488 ;
V_486 = F_293 () ;
V_73 = F_359 ( V_482 , V_453 ) ;
V_458 = F_360 ( V_486 , V_453 ) ;
if ( V_483 ) {
V_34 = V_325 ( V_172 ) ;
V_5 = V_172 -> V_29 . V_79 . V_82 ;
V_458 += F_363 ( V_34 , V_486 , - V_5 , - V_5 ) ;
V_73 += F_363 ( V_34 , V_482 , 0 , - V_5 ) ;
}
V_34 = V_325 ( V_30 ) ;
V_5 = V_30 -> V_29 . V_79 . V_82 ;
V_484 = 100 ;
V_484 *= F_126 ( V_482 ) ;
V_485 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
V_485 *= F_126 ( V_486 ) ;
if ( V_458 > 0 ) {
V_484 *= V_458 +
F_363 ( V_34 , V_486 , V_5 , V_5 ) ;
V_485 *= V_73 + F_363 ( V_34 , V_482 , 0 , V_5 ) ;
}
V_487 = V_484 <= V_485 ;
F_83 ( V_30 -> V_29 . V_94 . V_489 ) ;
if ( ! V_487 )
return 0 ;
F_83 ( V_213 -> V_490 ) ;
F_83 ( V_30 -> V_29 . V_94 . V_491 ) ;
return 1 ;
}
static unsigned long F_368 ( int V_1 , struct V_27 * V_30 )
{
return F_361 ( V_1 ) - F_369 ( V_1 , V_30 ) ;
}
static struct V_492 *
F_370 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_486 , int V_493 )
{
struct V_492 * V_494 = NULL , * V_148 = V_213 -> V_495 ;
struct V_492 * V_496 = NULL ;
unsigned long V_497 = V_498 , V_499 = 0 ;
unsigned long V_500 = V_498 , V_501 = 0 ;
unsigned long V_502 = 0 , V_503 = 0 ;
int V_504 = V_213 -> V_505 ;
int V_506 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
unsigned long V_507 = F_13 ( V_74 ) *
( V_213 -> V_197 - 100 ) / 100 ;
if ( V_493 & V_508 )
V_504 = V_213 -> V_488 ;
do {
unsigned long V_73 , V_509 , V_510 ;
unsigned long V_511 , V_512 ;
int V_513 ;
int V_272 ;
if ( ! F_371 ( F_372 ( V_148 ) ,
& V_30 -> V_207 ) )
continue;
V_513 = F_137 ( V_486 ,
F_372 ( V_148 ) ) ;
V_509 = 0 ;
V_510 = 0 ;
V_512 = 0 ;
F_123 (i, sched_group_cpus(group)) {
if ( V_513 )
V_73 = F_359 ( V_272 , V_504 ) ;
else
V_73 = F_360 ( V_272 , V_504 ) ;
V_510 += V_73 ;
V_509 += F_252 ( & F_124 ( V_272 ) -> V_42 ) ;
V_511 = F_368 ( V_272 , V_30 ) ;
if ( V_511 > V_512 )
V_512 = V_511 ;
}
V_509 = ( V_509 * V_88 ) /
V_148 -> V_514 -> V_177 ;
V_510 = ( V_510 * V_88 ) /
V_148 -> V_514 -> V_177 ;
if ( V_513 ) {
V_499 = V_510 ;
V_501 = V_509 ;
V_503 = V_512 ;
} else {
if ( V_497 > ( V_510 + V_507 ) ) {
V_497 = V_510 ;
V_500 = V_509 ;
V_494 = V_148 ;
} else if ( ( V_510 < ( V_497 + V_507 ) ) &&
( 100 * V_500 > V_506 * V_509 ) ) {
V_500 = V_509 ;
V_494 = V_148 ;
}
if ( V_502 < V_512 ) {
V_502 = V_512 ;
V_496 = V_148 ;
}
}
} while ( V_148 = V_148 -> V_61 , V_148 != V_213 -> V_495 );
if ( V_493 & V_515 )
goto V_516;
if ( V_503 > F_373 ( V_30 ) / 2 &&
V_506 * V_503 > 100 * V_502 )
return NULL ;
if ( V_502 > F_373 ( V_30 ) / 2 )
return V_496 ;
V_516:
if ( ! V_494 )
return NULL ;
if ( V_497 > ( V_499 + V_507 ) )
return NULL ;
if ( ( V_499 < ( V_497 + V_507 ) ) &&
( 100 * V_501 < V_506 * V_500 ) )
return NULL ;
return V_494 ;
}
static int
F_374 ( struct V_492 * V_148 , struct V_27 * V_30 , int V_486 )
{
unsigned long V_73 , V_517 = V_498 ;
unsigned int V_518 = V_519 ;
T_2 V_520 = 0 ;
int V_521 = V_486 ;
int V_522 = - 1 ;
int V_272 ;
if ( V_148 -> F_114 == 1 )
return F_375 ( F_372 ( V_148 ) ) ;
F_376 (i, sched_group_cpus(group), &p->cpus_allowed) {
if ( F_377 ( V_272 ) ) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_523 * V_405 = F_378 ( V_25 ) ;
if ( V_405 && V_405 -> V_524 < V_518 ) {
V_518 = V_405 -> V_524 ;
V_520 = V_25 -> V_525 ;
V_522 = V_272 ;
} else if ( ( ! V_405 || V_405 -> V_524 == V_518 ) &&
V_25 -> V_525 > V_520 ) {
V_520 = V_25 -> V_525 ;
V_522 = V_272 ;
}
} else if ( V_522 == - 1 ) {
V_73 = F_125 ( V_272 ) ;
if ( V_73 < V_517 || ( V_73 == V_517 && V_272 == V_486 ) ) {
V_517 = V_73 ;
V_521 = V_272 ;
}
}
}
return V_522 != - 1 ? V_522 : V_521 ;
}
static int F_379 ( int V_331 , const struct V_526 * V_527 , int V_300 , int * V_528 )
{
int V_61 ;
V_529:
V_61 = F_380 ( F_381 ( V_527 ) , V_530 , V_331 + 1 ) ;
if ( * V_528 ) {
if ( V_61 >= V_300 )
return V_530 ;
} else {
if ( V_61 >= V_530 ) {
* V_528 = 1 ;
V_331 = - 1 ;
goto V_529;
}
}
return V_61 ;
}
static inline void F_382 ( int V_1 , int V_330 )
{
struct V_531 * V_532 ;
V_532 = F_147 ( F_148 ( V_533 , V_1 ) ) ;
if ( V_532 )
F_194 ( V_532 -> V_534 , V_330 ) ;
}
static inline bool F_383 ( int V_1 , bool V_535 )
{
struct V_531 * V_532 ;
V_532 = F_147 ( F_148 ( V_533 , V_1 ) ) ;
if ( V_532 )
return F_98 ( V_532 -> V_534 ) ;
return V_535 ;
}
void F_384 ( struct V_25 * V_25 )
{
int V_536 = F_26 ( V_25 ) ;
int V_1 ;
F_134 () ;
if ( F_383 ( V_536 , true ) )
goto V_206;
F_123 (cpu, cpu_smt_mask(core)) {
if ( V_1 == V_536 )
continue;
if ( ! F_377 ( V_1 ) )
goto V_206;
}
F_382 ( V_536 , 1 ) ;
V_206:
F_142 () ;
}
static int F_385 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_537 )
{
struct V_526 * V_9 = F_386 ( V_538 ) ;
int V_536 , V_1 , V_539 ;
if ( ! F_191 ( & V_540 ) )
return - 1 ;
if ( ! F_383 ( V_537 , false ) )
return - 1 ;
F_387 ( V_9 , F_388 ( V_213 ) , & V_30 -> V_207 ) ;
F_389 (core, cpus, target, wrap) {
bool V_405 = true ;
F_123 (cpu, cpu_smt_mask(core)) {
F_390 ( V_1 , V_9 ) ;
if ( ! F_377 ( V_1 ) )
V_405 = false ;
}
if ( V_405 )
return V_536 ;
}
F_382 ( V_537 , 0 ) ;
return - 1 ;
}
static int F_391 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_537 )
{
int V_1 ;
if ( ! F_191 ( & V_540 ) )
return - 1 ;
F_123 (cpu, cpu_smt_mask(target)) {
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_377 ( V_1 ) )
return V_1 ;
}
return - 1 ;
}
static inline int F_385 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_537 )
{
return - 1 ;
}
static inline int F_391 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_537 )
{
return - 1 ;
}
static int F_392 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_537 )
{
struct V_212 * V_541 ;
T_2 V_542 , V_543 = F_238 () -> V_543 ;
T_2 time , V_544 ;
T_3 V_44 ;
int V_1 , V_539 ;
V_541 = F_147 ( * F_393 ( & V_545 ) ) ;
if ( ! V_541 )
return - 1 ;
V_542 = V_541 -> V_546 ;
if ( F_229 ( V_547 ) && ( V_543 / 512 ) < V_542 )
return - 1 ;
time = F_394 () ;
F_389 (cpu, sched_domain_span(sd), target, wrap) {
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_377 ( V_1 ) )
break;
}
time = F_394 () - time ;
V_544 = V_541 -> V_546 ;
V_44 = ( T_3 ) ( time - V_544 ) / 8 ;
V_541 -> V_546 += V_44 ;
return V_1 ;
}
static int F_140 ( struct V_27 * V_30 , int V_350 , int V_537 )
{
struct V_212 * V_213 ;
int V_272 ;
if ( F_377 ( V_537 ) )
return V_537 ;
if ( V_350 != V_537 && F_395 ( V_350 , V_537 ) && F_377 ( V_350 ) )
return V_350 ;
V_213 = F_147 ( F_148 ( V_545 , V_537 ) ) ;
if ( ! V_213 )
return V_537 ;
V_272 = F_385 ( V_30 , V_213 , V_537 ) ;
if ( ( unsigned ) V_272 < V_530 )
return V_272 ;
V_272 = F_392 ( V_30 , V_213 , V_537 ) ;
if ( ( unsigned ) V_272 < V_530 )
return V_272 ;
V_272 = F_391 ( V_30 , V_213 , V_537 ) ;
if ( ( unsigned ) V_272 < V_530 )
return V_272 ;
return V_537 ;
}
static int F_396 ( int V_1 )
{
unsigned long V_548 = F_124 ( V_1 ) -> V_42 . V_79 . V_85 ;
unsigned long V_177 = F_361 ( V_1 ) ;
return ( V_548 >= V_177 ) ? V_177 : V_548 ;
}
static inline int F_373 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_85 ;
}
static int F_369 ( int V_1 , struct V_27 * V_30 )
{
unsigned long V_548 , V_177 ;
if ( V_1 != F_146 ( V_30 ) || ! V_30 -> V_29 . V_79 . V_80 )
return F_396 ( V_1 ) ;
V_177 = F_361 ( V_1 ) ;
V_548 = F_99 ( long , F_124 ( V_1 ) -> V_42 . V_79 . V_85 - F_373 ( V_30 ) , 0 ) ;
return ( V_548 >= V_177 ) ? V_177 : V_548 ;
}
static int F_397 ( struct V_27 * V_30 , int V_1 , int V_482 )
{
long V_549 , V_550 ;
V_549 = F_154 ( F_361 ( V_482 ) , F_361 ( V_1 ) ) ;
V_550 = F_124 ( V_1 ) -> V_551 -> V_552 ;
if ( V_550 - V_549 < V_550 > > 3 )
return 0 ;
F_249 ( & V_30 -> V_29 ) ;
return V_549 * 1024 < F_373 ( V_30 ) * V_553 ;
}
static int
F_398 ( struct V_27 * V_30 , int V_482 , int V_493 , int V_554 )
{
struct V_212 * V_555 , * V_556 = NULL , * V_213 = NULL ;
int V_1 = F_293 () ;
int V_557 = V_482 ;
int V_558 = 0 ;
int V_483 = V_554 & V_559 ;
if ( V_493 & V_508 ) {
F_364 ( V_30 ) ;
V_558 = ! F_365 ( V_30 ) && ! F_397 ( V_30 , V_1 , V_482 )
&& F_137 ( V_1 , & V_30 -> V_207 ) ;
}
F_134 () ;
F_399 (cpu, tmp) {
if ( ! ( V_555 -> V_115 & V_560 ) )
break;
if ( V_558 && ( V_555 -> V_115 & V_561 ) &&
F_137 ( V_482 , F_388 ( V_555 ) ) ) {
V_556 = V_555 ;
break;
}
if ( V_555 -> V_115 & V_493 )
V_213 = V_555 ;
else if ( ! V_558 )
break;
}
if ( V_556 ) {
V_213 = NULL ;
if ( V_1 != V_482 && F_367 ( V_556 , V_30 , V_482 , V_483 ) )
V_557 = V_1 ;
}
if ( ! V_213 ) {
if ( V_493 & V_508 )
V_557 = F_140 ( V_30 , V_482 , V_557 ) ;
} else while ( V_213 ) {
struct V_492 * V_148 ;
int V_5 ;
if ( ! ( V_213 -> V_115 & V_493 ) ) {
V_213 = V_213 -> V_562 ;
continue;
}
V_148 = F_370 ( V_213 , V_30 , V_1 , V_493 ) ;
if ( ! V_148 ) {
V_213 = V_213 -> V_562 ;
continue;
}
V_557 = F_374 ( V_148 , V_30 , V_1 ) ;
if ( V_557 == - 1 || V_557 == V_1 ) {
V_213 = V_213 -> V_562 ;
continue;
}
V_1 = V_557 ;
V_5 = V_213 -> V_563 ;
V_213 = NULL ;
F_399 (cpu, tmp) {
if ( V_5 <= V_555 -> V_563 )
break;
if ( V_555 -> V_115 & V_493 )
V_213 = V_555 ;
}
}
F_142 () ;
return V_557 ;
}
static void F_400 ( struct V_27 * V_30 )
{
if ( V_30 -> V_118 == V_564 ) {
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_51 ;
do {
V_51 = V_26 -> V_51 ;
F_230 () ;
F_36 = V_26 -> F_36 ;
} while ( F_36 != V_51 );
#else
F_36 = V_26 -> F_36 ;
#endif
V_29 -> V_43 -= F_36 ;
}
F_250 ( & V_30 -> V_29 ) ;
V_30 -> V_29 . V_79 . V_80 = 0 ;
V_30 -> V_29 . V_93 = 0 ;
}
static void F_401 ( struct V_27 * V_30 )
{
F_250 ( & V_30 -> V_29 ) ;
}
static unsigned long
F_402 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
unsigned long V_565 = V_566 ;
return F_56 ( V_565 , V_29 ) ;
}
static int
F_277 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
T_3 V_565 , V_567 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_567 <= 0 )
return - 1 ;
V_565 = F_402 ( V_47 , V_29 ) ;
if ( V_567 > V_565 )
return 1 ;
return 0 ;
}
static void F_403 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_568 == V_569 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_62 = V_29 ;
}
static void F_347 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_568 == V_569 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_61 = V_29 ;
}
static void F_404 ( struct V_28 * V_29 )
{
F_59 (se)
F_23 ( V_29 ) -> V_380 = V_29 ;
}
static void F_405 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_554 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_28 * V_29 = & V_47 -> V_29 , * V_38 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
int V_462 = V_26 -> V_75 >= V_70 ;
int V_570 = 0 ;
if ( F_14 ( V_29 == V_38 ) )
return;
if ( F_14 ( F_219 ( F_23 ( V_38 ) ) ) )
return;
if ( F_229 ( V_571 ) && V_462 && ! ( V_554 & V_572 ) ) {
F_347 ( V_38 ) ;
V_570 = 1 ;
}
if ( F_406 ( V_47 ) )
return;
if ( F_14 ( V_47 -> V_568 == V_569 ) &&
F_12 ( V_30 -> V_568 != V_569 ) )
goto V_573;
if ( F_14 ( V_30 -> V_568 != V_574 ) || ! F_229 ( V_575 ) )
return;
F_33 ( & V_29 , & V_38 ) ;
F_66 ( F_23 ( V_29 ) ) ;
F_181 ( ! V_38 ) ;
if ( F_277 ( V_29 , V_38 ) == 1 ) {
if ( ! V_570 )
F_347 ( V_38 ) ;
goto V_573;
}
return;
V_573:
F_274 ( V_25 ) ;
if ( F_14 ( ! V_29 -> V_48 || V_47 == V_25 -> V_405 ) )
return;
if ( F_229 ( V_576 ) && V_462 && F_20 ( V_29 ) )
F_403 ( V_29 ) ;
}
static struct V_27 *
F_407 ( struct V_25 * V_25 , struct V_27 * V_350 , struct V_370 * V_371 )
{
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_28 * V_29 ;
struct V_27 * V_30 ;
int V_577 ;
V_529:
#ifdef F_408
if ( ! V_26 -> V_75 )
goto V_405;
if ( V_350 -> V_89 != & V_90 )
goto V_578;
do {
struct V_28 * V_47 = V_26 -> V_47 ;
if ( V_47 ) {
if ( V_47 -> V_48 )
F_66 ( V_26 ) ;
else
V_47 = NULL ;
if ( F_14 ( F_279 ( V_26 ) ) )
goto V_578;
}
V_29 = F_276 ( V_26 , V_47 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( V_350 != V_30 ) {
struct V_28 * V_38 = & V_350 -> V_29 ;
while ( ! ( V_26 = F_31 ( V_29 , V_38 ) ) ) {
int V_39 = V_29 -> V_41 ;
int V_40 = V_38 -> V_41 ;
if ( V_39 <= V_40 ) {
F_278 ( F_23 ( V_38 ) , V_38 ) ;
V_38 = F_32 ( V_38 ) ;
}
if ( V_39 >= V_40 ) {
F_275 ( F_23 ( V_29 ) , V_29 ) ;
V_29 = F_32 ( V_29 ) ;
}
}
F_278 ( V_26 , V_38 ) ;
F_275 ( V_26 , V_29 ) ;
}
if ( F_343 ( V_25 ) )
F_340 ( V_25 , V_30 ) ;
return V_30 ;
V_578:
V_26 = & V_25 -> V_42 ;
#endif
if ( ! V_26 -> V_75 )
goto V_405;
F_409 ( V_25 , V_350 ) ;
do {
V_29 = F_276 ( V_26 , NULL ) ;
F_275 ( V_26 , V_29 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( F_343 ( V_25 ) )
F_340 ( V_25 , V_30 ) ;
return V_30 ;
V_405:
V_577 = F_253 ( V_25 , V_371 ) ;
if ( V_577 < 0 )
return V_579 ;
if ( V_577 > 0 )
goto V_529;
return NULL ;
}
static void F_410 ( struct V_25 * V_25 , struct V_27 * V_350 )
{
struct V_28 * V_29 = & V_350 -> V_29 ;
struct V_26 * V_26 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_278 ( V_26 , V_29 ) ;
}
}
static void F_411 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
struct V_28 * V_29 = & V_47 -> V_29 ;
if ( F_14 ( V_25 -> V_75 == 1 ) )
return;
F_270 ( V_26 , V_29 ) ;
if ( V_47 -> V_568 != V_580 ) {
F_311 ( V_25 ) ;
F_66 ( V_26 ) ;
F_412 ( V_25 , true ) ;
}
F_404 ( V_29 ) ;
}
static bool F_413 ( struct V_25 * V_25 , struct V_27 * V_30 , bool V_573 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( ! V_29 -> V_48 || F_219 ( F_23 ( V_29 ) ) )
return false ;
F_347 ( V_29 ) ;
F_411 ( V_25 ) ;
return true ;
}
static int F_414 ( struct V_27 * V_30 , struct V_581 * V_182 )
{
T_3 V_44 ;
F_333 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_30 -> V_89 != & V_90 )
return 0 ;
if ( F_14 ( V_30 -> V_568 == V_569 ) )
return 0 ;
if ( F_229 ( V_582 ) && V_182 -> V_202 -> V_75 &&
( & V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_61 ||
& V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_62 ) )
return 1 ;
if ( V_583 == - 1 )
return 1 ;
if ( V_583 == 0 )
return 0 ;
V_44 = F_67 ( V_182 -> V_200 ) - V_30 -> V_29 . V_93 ;
return V_44 < ( T_3 ) V_583 ;
}
static int F_415 ( struct V_27 * V_30 , struct V_581 * V_182 )
{
struct V_137 * V_137 = F_147 ( V_30 -> V_137 ) ;
unsigned long V_584 , V_585 ;
int V_167 , V_169 ;
if ( ! F_191 ( & V_286 ) )
return - 1 ;
if ( ! V_30 -> V_145 || ! ( V_182 -> V_213 -> V_115 & V_586 ) )
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
V_584 = F_107 ( V_30 , V_167 ) ;
V_585 = F_107 ( V_30 , V_169 ) ;
} else {
V_584 = F_106 ( V_30 , V_167 ) ;
V_585 = F_106 ( V_30 , V_169 ) ;
}
return V_585 < V_584 ;
}
static inline int F_415 ( struct V_27 * V_30 ,
struct V_581 * V_182 )
{
return - 1 ;
}
static
int F_416 ( struct V_27 * V_30 , struct V_581 * V_182 )
{
int V_587 ;
F_333 ( & V_182 -> V_200 -> V_257 ) ;
if ( F_303 ( V_325 ( V_30 ) , V_182 -> V_201 , V_182 -> V_168 ) )
return 0 ;
if ( ! F_137 ( V_182 -> V_168 , & V_30 -> V_207 ) ) {
int V_1 ;
F_83 ( V_30 -> V_29 . V_94 . V_588 ) ;
V_182 -> V_115 |= V_589 ;
if ( ! V_182 -> V_590 || ( V_182 -> V_115 & V_591 ) )
return 0 ;
F_376 (cpu, env->dst_grpmask, env->cpus) {
if ( F_137 ( V_1 , & V_30 -> V_207 ) ) {
V_182 -> V_115 |= V_591 ;
V_182 -> V_592 = V_1 ;
break;
}
}
return 0 ;
}
V_182 -> V_115 &= ~ V_593 ;
if ( F_417 ( V_182 -> V_200 , V_30 ) ) {
F_83 ( V_30 -> V_29 . V_94 . V_594 ) ;
return 0 ;
}
V_587 = F_415 ( V_30 , V_182 ) ;
if ( V_587 == - 1 )
V_587 = F_414 ( V_30 , V_182 ) ;
if ( V_587 <= 0 ||
V_182 -> V_213 -> V_595 > V_182 -> V_213 -> V_596 ) {
if ( V_587 == 1 ) {
F_83 ( V_182 -> V_213 -> V_597 [ V_182 -> V_405 ] ) ;
F_83 ( V_30 -> V_29 . V_94 . V_598 ) ;
}
return 1 ;
}
F_83 ( V_30 -> V_29 . V_94 . V_599 ) ;
return 0 ;
}
static void F_418 ( struct V_27 * V_30 , struct V_581 * V_182 )
{
F_333 ( & V_182 -> V_200 -> V_257 ) ;
V_30 -> V_48 = V_600 ;
F_419 ( V_182 -> V_200 , V_30 , 0 ) ;
F_420 ( V_30 , V_182 -> V_168 ) ;
}
static struct V_27 * F_421 ( struct V_581 * V_182 )
{
struct V_27 * V_30 , * V_331 ;
F_333 ( & V_182 -> V_200 -> V_257 ) ;
F_422 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_416 ( V_30 , V_182 ) )
continue;
F_418 ( V_30 , V_182 ) ;
F_83 ( V_182 -> V_213 -> V_601 [ V_182 -> V_405 ] ) ;
return V_30 ;
}
return NULL ;
}
static int F_423 ( struct V_581 * V_182 )
{
struct V_602 * V_603 = & V_182 -> V_200 -> V_324 ;
struct V_27 * V_30 ;
unsigned long V_73 ;
int V_604 = 0 ;
F_333 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_182 -> V_507 <= 0 )
return 0 ;
while ( ! F_309 ( V_603 ) ) {
if ( V_182 -> V_405 != V_605 && V_182 -> V_200 -> V_75 <= 1 )
break;
V_30 = F_424 ( V_603 , struct V_27 , V_29 . V_323 ) ;
V_182 -> V_606 ++ ;
if ( V_182 -> V_606 > V_182 -> V_607 )
break;
if ( V_182 -> V_606 > V_182 -> V_608 ) {
V_182 -> V_608 += V_609 ;
V_182 -> V_115 |= V_610 ;
break;
}
if ( ! F_416 ( V_30 , V_182 ) )
goto V_61;
V_73 = F_138 ( V_30 ) ;
if ( F_229 ( V_611 ) && V_73 < 16 && ! V_182 -> V_213 -> V_595 )
goto V_61;
if ( ( V_73 / 2 ) > V_182 -> V_507 )
goto V_61;
F_418 ( V_30 , V_182 ) ;
F_212 ( & V_30 -> V_29 . V_323 , & V_182 -> V_603 ) ;
V_604 ++ ;
V_182 -> V_507 -= V_73 ;
#ifdef F_425
if ( V_182 -> V_405 == V_612 )
break;
#endif
if ( V_182 -> V_507 <= 0 )
break;
continue;
V_61:
F_426 ( & V_30 -> V_29 . V_323 , V_603 ) ;
}
F_70 ( V_182 -> V_213 -> V_601 [ V_182 -> V_405 ] , V_604 ) ;
return V_604 ;
}
static void F_427 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_333 ( & V_25 -> V_257 ) ;
F_181 ( F_34 ( V_30 ) != V_25 ) ;
F_428 ( V_25 , V_30 , 0 ) ;
V_30 -> V_48 = V_613 ;
F_429 ( V_25 , V_30 , 0 ) ;
}
static void F_430 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_297 ( & V_25 -> V_257 ) ;
F_427 ( V_25 , V_30 ) ;
F_299 ( & V_25 -> V_257 ) ;
}
static void F_431 ( struct V_581 * V_182 )
{
struct V_602 * V_603 = & V_182 -> V_603 ;
struct V_27 * V_30 ;
F_297 ( & V_182 -> V_202 -> V_257 ) ;
while ( ! F_309 ( V_603 ) ) {
V_30 = F_424 ( V_603 , struct V_27 , V_29 . V_323 ) ;
F_214 ( & V_30 -> V_29 . V_323 ) ;
F_427 ( V_182 -> V_202 , V_30 ) ;
}
F_299 ( & V_182 -> V_202 -> V_257 ) ;
}
static void F_432 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 ;
unsigned long V_115 ;
F_433 ( & V_25 -> V_257 , V_115 ) ;
F_311 ( V_25 ) ;
F_338 (rq, cfs_rq) {
if ( F_219 ( V_26 ) )
continue;
if ( F_240 ( F_63 ( V_26 ) , V_26 , true ) )
F_65 ( V_26 , 0 ) ;
if ( V_26 -> V_34 -> V_29 [ V_1 ] )
F_243 ( V_26 -> V_34 -> V_29 [ V_1 ] , 0 ) ;
}
F_434 ( & V_25 -> V_257 , V_115 ) ;
}
static void F_435 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_28 * V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
unsigned long V_92 = V_224 ;
unsigned long V_73 ;
if ( V_26 -> V_614 == V_92 )
return;
V_26 -> V_615 = NULL ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_615 = V_29 ;
if ( V_26 -> V_614 == V_92 )
break;
}
if ( ! V_29 ) {
V_26 -> V_616 = F_252 ( V_26 ) ;
V_26 -> V_614 = V_92 ;
}
while ( ( V_29 = V_26 -> V_615 ) != NULL ) {
V_73 = V_26 -> V_616 ;
V_73 = F_436 ( V_73 * V_29 -> V_79 . V_82 ,
F_252 ( V_26 ) + 1 ) ;
V_26 = F_24 ( V_29 ) ;
V_26 -> V_616 = V_73 ;
V_26 -> V_614 = V_92 ;
}
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
struct V_26 * V_26 = F_22 ( V_30 ) ;
F_435 ( V_26 ) ;
return F_436 ( V_30 -> V_29 . V_79 . V_82 * V_26 -> V_616 ,
F_252 ( V_26 ) + 1 ) ;
}
static inline void F_432 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 = & V_25 -> V_42 ;
unsigned long V_115 ;
F_433 ( & V_25 -> V_257 , V_115 ) ;
F_311 ( V_25 ) ;
F_240 ( F_63 ( V_26 ) , V_26 , true ) ;
F_434 ( & V_25 -> V_257 , V_115 ) ;
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_82 ;
}
static inline void F_437 ( struct V_617 * V_532 )
{
* V_532 = (struct V_617 ) {
. V_618 = NULL ,
. V_233 = NULL ,
. V_619 = 0UL ,
. V_620 = 0UL ,
. V_621 = {
. V_509 = 0UL ,
. V_622 = 0 ,
. V_623 = V_624 ,
} ,
} ;
}
static inline int F_438 ( struct V_212 * V_213 ,
enum V_625 V_405 )
{
int V_504 ;
switch ( V_405 ) {
case V_605 :
V_504 = V_213 -> V_626 ;
break;
case V_612 :
V_504 = V_213 -> V_627 ;
break;
default:
V_504 = V_213 -> V_628 ;
break;
}
return V_504 ;
}
static unsigned long F_439 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
T_2 V_469 , V_629 , V_630 , V_79 ;
T_3 V_44 ;
V_630 = F_98 ( V_25 -> V_630 ) ;
V_79 = F_98 ( V_25 -> V_631 ) ;
V_44 = F_440 ( V_25 ) - V_630 ;
if ( F_14 ( V_44 < 0 ) )
V_44 = 0 ;
V_469 = F_441 () + V_44 ;
V_629 = F_226 ( V_79 , V_469 ) ;
if ( F_12 ( V_629 < V_88 ) )
return V_88 - V_629 ;
return 1 ;
}
static void F_442 ( struct V_212 * V_213 , int V_1 )
{
unsigned long V_177 = F_224 ( V_213 , V_1 ) ;
struct V_492 * V_632 = V_213 -> V_495 ;
F_124 ( V_1 ) -> V_472 = V_177 ;
V_177 *= F_439 ( V_1 ) ;
V_177 >>= V_633 ;
if ( ! V_177 )
V_177 = 1 ;
F_124 ( V_1 ) -> V_471 = V_177 ;
V_632 -> V_514 -> V_177 = V_177 ;
V_632 -> V_514 -> V_634 = V_177 ;
}
void F_443 ( struct V_212 * V_213 , int V_1 )
{
struct V_212 * V_562 = V_213 -> V_562 ;
struct V_492 * V_148 , * V_632 = V_213 -> V_495 ;
unsigned long V_177 , V_634 ;
unsigned long V_221 ;
V_221 = F_155 ( V_213 -> V_635 ) ;
V_221 = F_158 ( V_221 , 1UL , V_636 ) ;
V_632 -> V_514 -> V_637 = V_224 + V_221 ;
if ( ! V_562 ) {
F_442 ( V_213 , V_1 ) ;
return;
}
V_177 = 0 ;
V_634 = V_498 ;
if ( V_562 -> V_115 & V_638 ) {
F_123 (cpu, sched_group_cpus(sdg)) {
struct V_639 * V_514 ;
struct V_25 * V_25 = F_124 ( V_1 ) ;
if ( F_14 ( ! V_25 -> V_213 ) ) {
V_177 += F_126 ( V_1 ) ;
} else {
V_514 = V_25 -> V_213 -> V_495 -> V_514 ;
V_177 += V_514 -> V_177 ;
}
V_634 = F_154 ( V_177 , V_634 ) ;
}
} else {
V_148 = V_562 -> V_495 ;
do {
struct V_639 * V_514 = V_148 -> V_514 ;
V_177 += V_514 -> V_177 ;
V_634 = F_154 ( V_514 -> V_634 , V_634 ) ;
V_148 = V_148 -> V_61 ;
} while ( V_148 != V_562 -> V_495 );
}
V_632 -> V_514 -> V_177 = V_177 ;
V_632 -> V_514 -> V_634 = V_634 ;
}
static inline int
F_444 ( struct V_25 * V_25 , struct V_212 * V_213 )
{
return ( ( V_25 -> V_471 * V_213 -> V_197 ) <
( V_25 -> V_472 * 100 ) ) ;
}
static inline int F_445 ( struct V_492 * V_148 )
{
return V_148 -> V_514 -> V_507 ;
}
static inline bool
F_446 ( struct V_581 * V_182 , struct V_640 * V_641 )
{
if ( V_641 -> V_622 < V_641 -> F_114 )
return true ;
if ( ( V_641 -> V_642 * 100 ) >
( V_641 -> V_643 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_447 ( struct V_581 * V_182 , struct V_640 * V_641 )
{
if ( V_641 -> V_622 <= V_641 -> F_114 )
return false ;
if ( ( V_641 -> V_642 * 100 ) <
( V_641 -> V_643 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_448 ( struct V_492 * V_644 , struct V_492 * V_645 )
{
return V_644 -> V_514 -> V_634 * V_553 <
V_645 -> V_514 -> V_634 * 1024 ;
}
static inline enum
V_623 F_449 ( struct V_492 * V_148 ,
struct V_640 * V_641 )
{
if ( V_641 -> V_646 )
return V_647 ;
if ( F_445 ( V_148 ) )
return V_648 ;
return V_624 ;
}
static inline void F_450 ( struct V_581 * V_182 ,
struct V_492 * V_148 , int V_504 ,
int V_513 , struct V_640 * V_641 ,
bool * V_649 )
{
unsigned long V_73 ;
int V_272 , V_75 ;
memset ( V_641 , 0 , sizeof( * V_641 ) ) ;
F_376 (i, sched_group_cpus(group), env->cpus) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
if ( V_513 )
V_73 = F_360 ( V_272 , V_504 ) ;
else
V_73 = F_359 ( V_272 , V_504 ) ;
V_641 -> V_650 += V_73 ;
V_641 -> V_643 += F_396 ( V_272 ) ;
V_641 -> V_622 += V_25 -> V_42 . V_416 ;
V_75 = V_25 -> V_75 ;
if ( V_75 > 1 )
* V_649 = true ;
#ifdef F_451
V_641 -> V_134 += V_25 -> V_134 ;
V_641 -> V_136 += V_25 -> V_136 ;
#endif
V_641 -> V_651 += F_125 ( V_272 ) ;
if ( ! V_75 && F_377 ( V_272 ) )
V_641 -> V_652 ++ ;
}
V_641 -> V_642 = V_148 -> V_514 -> V_177 ;
V_641 -> V_509 = ( V_641 -> V_650 * V_88 ) / V_641 -> V_642 ;
if ( V_641 -> V_622 )
V_641 -> V_653 = V_641 -> V_651 / V_641 -> V_622 ;
V_641 -> F_114 = V_148 -> F_114 ;
V_641 -> V_646 = F_447 ( V_182 , V_641 ) ;
V_641 -> V_623 = F_449 ( V_148 , V_641 ) ;
}
static bool F_452 ( struct V_581 * V_182 ,
struct V_617 * V_532 ,
struct V_492 * V_644 ,
struct V_640 * V_641 )
{
struct V_640 * V_618 = & V_532 -> V_621 ;
if ( V_641 -> V_623 > V_618 -> V_623 )
return true ;
if ( V_641 -> V_623 < V_618 -> V_623 )
return false ;
if ( V_641 -> V_509 <= V_618 -> V_509 )
return false ;
if ( ! ( V_182 -> V_213 -> V_115 & V_654 ) )
goto V_655;
if ( V_641 -> V_622 <= V_641 -> F_114 &&
F_448 ( V_532 -> V_233 , V_644 ) )
return false ;
V_655:
if ( ! ( V_182 -> V_213 -> V_115 & V_656 ) )
return true ;
if ( V_182 -> V_405 == V_605 )
return true ;
if ( V_641 -> V_622 &&
F_453 ( V_182 -> V_168 , V_644 -> V_657 ) ) {
if ( ! V_532 -> V_618 )
return true ;
if ( F_453 ( V_532 -> V_618 -> V_657 ,
V_644 -> V_657 ) )
return true ;
}
return false ;
}
static inline enum V_658 F_454 ( struct V_640 * V_641 )
{
if ( V_641 -> V_622 > V_641 -> V_134 )
return V_659 ;
if ( V_641 -> V_622 > V_641 -> V_136 )
return V_231 ;
return V_660 ;
}
static inline enum V_658 F_455 ( struct V_25 * V_25 )
{
if ( V_25 -> V_75 > V_25 -> V_134 )
return V_659 ;
if ( V_25 -> V_75 > V_25 -> V_136 )
return V_231 ;
return V_660 ;
}
static inline enum V_658 F_454 ( struct V_640 * V_641 )
{
return V_660 ;
}
static inline enum V_658 F_455 ( struct V_25 * V_25 )
{
return V_659 ;
}
static inline void F_456 ( struct V_581 * V_182 , struct V_617 * V_532 )
{
struct V_212 * V_562 = V_182 -> V_213 -> V_562 ;
struct V_492 * V_644 = V_182 -> V_213 -> V_495 ;
struct V_640 V_661 ;
int V_504 , V_662 = 0 ;
bool V_649 = false ;
if ( V_562 && V_562 -> V_115 & V_663 )
V_662 = 1 ;
V_504 = F_438 ( V_182 -> V_213 , V_182 -> V_405 ) ;
do {
struct V_640 * V_641 = & V_661 ;
int V_513 ;
V_513 = F_137 ( V_182 -> V_168 , F_372 ( V_644 ) ) ;
if ( V_513 ) {
V_532 -> V_233 = V_644 ;
V_641 = & V_532 -> V_664 ;
if ( V_182 -> V_405 != V_612 ||
F_457 ( V_224 , V_644 -> V_514 -> V_637 ) )
F_443 ( V_182 -> V_213 , V_182 -> V_168 ) ;
}
F_450 ( V_182 , V_644 , V_504 , V_513 , V_641 ,
& V_649 ) ;
if ( V_513 )
goto V_665;
if ( V_662 && V_532 -> V_233 &&
F_446 ( V_182 , & V_532 -> V_664 ) &&
( V_641 -> V_622 > 1 ) ) {
V_641 -> V_646 = 1 ;
V_641 -> V_623 = F_449 ( V_644 , V_641 ) ;
}
if ( F_452 ( V_182 , V_532 , V_644 , V_641 ) ) {
V_532 -> V_618 = V_644 ;
V_532 -> V_621 = * V_641 ;
}
V_665:
V_532 -> V_619 += V_641 -> V_650 ;
V_532 -> V_620 += V_641 -> V_642 ;
V_644 = V_644 -> V_61 ;
} while ( V_644 != V_182 -> V_213 -> V_495 );
if ( V_182 -> V_213 -> V_115 & V_586 )
V_182 -> V_658 = F_454 ( & V_532 -> V_621 ) ;
if ( ! V_182 -> V_213 -> V_35 ) {
if ( V_182 -> V_202 -> V_551 -> V_649 != V_649 )
V_182 -> V_202 -> V_551 -> V_649 = V_649 ;
}
}
static int F_458 ( struct V_581 * V_182 , struct V_617 * V_532 )
{
int V_666 ;
if ( ! ( V_182 -> V_213 -> V_115 & V_656 ) )
return 0 ;
if ( V_182 -> V_405 == V_605 )
return 0 ;
if ( ! V_532 -> V_618 )
return 0 ;
V_666 = V_532 -> V_618 -> V_657 ;
if ( F_453 ( V_666 , V_182 -> V_168 ) )
return 0 ;
V_182 -> V_507 = F_127 (
V_532 -> V_621 . V_509 * V_532 -> V_621 . V_642 ,
V_88 ) ;
return 1 ;
}
static inline
void F_459 ( struct V_581 * V_182 , struct V_617 * V_532 )
{
unsigned long V_555 , V_667 = 0 , V_668 = 0 ;
unsigned int V_669 = 2 ;
unsigned long V_670 ;
struct V_640 * V_233 , * V_618 ;
V_233 = & V_532 -> V_664 ;
V_618 = & V_532 -> V_621 ;
if ( ! V_233 -> V_622 )
V_233 -> V_653 = F_362 ( V_182 -> V_168 ) ;
else if ( V_618 -> V_653 > V_233 -> V_653 )
V_669 = 1 ;
V_670 =
( V_618 -> V_653 * V_88 ) /
V_618 -> V_642 ;
if ( V_618 -> V_509 + V_670 >=
V_233 -> V_509 + ( V_670 * V_669 ) ) {
V_182 -> V_507 = V_618 -> V_653 ;
return;
}
V_667 += V_618 -> V_642 *
F_154 ( V_618 -> V_653 , V_618 -> V_509 ) ;
V_667 += V_233 -> V_642 *
F_154 ( V_233 -> V_653 , V_233 -> V_509 ) ;
V_667 /= V_88 ;
if ( V_618 -> V_509 > V_670 ) {
V_668 += V_618 -> V_642 *
F_154 ( V_618 -> V_653 ,
V_618 -> V_509 - V_670 ) ;
}
if ( V_618 -> V_509 * V_618 -> V_642 <
V_618 -> V_653 * V_88 ) {
V_555 = ( V_618 -> V_509 * V_618 -> V_642 ) /
V_233 -> V_642 ;
} else {
V_555 = ( V_618 -> V_653 * V_88 ) /
V_233 -> V_642 ;
}
V_668 += V_233 -> V_642 *
F_154 ( V_233 -> V_653 , V_233 -> V_509 + V_555 ) ;
V_668 /= V_88 ;
if ( V_668 > V_667 )
V_182 -> V_507 = V_618 -> V_653 ;
}
static inline void F_460 ( struct V_581 * V_182 , struct V_617 * V_532 )
{
unsigned long V_671 , V_672 = ~ 0UL ;
struct V_640 * V_233 , * V_618 ;
V_233 = & V_532 -> V_664 ;
V_618 = & V_532 -> V_621 ;
if ( V_618 -> V_623 == V_648 ) {
V_618 -> V_653 =
F_154 ( V_618 -> V_653 , V_532 -> V_509 ) ;
}
if ( V_618 -> V_509 <= V_532 -> V_509 ||
V_233 -> V_509 >= V_532 -> V_509 ) {
V_182 -> V_507 = 0 ;
return F_459 ( V_182 , V_532 ) ;
}
if ( V_618 -> V_623 == V_647 &&
V_233 -> V_623 == V_647 ) {
V_672 = V_618 -> V_622 * V_88 ;
if ( V_672 > V_618 -> V_642 ) {
V_672 -= V_618 -> V_642 ;
V_672 *= F_13 ( V_74 ) ;
V_672 /= V_618 -> V_642 ;
} else
V_672 = ~ 0UL ;
}
V_671 = F_154 ( V_618 -> V_509 - V_532 -> V_509 , V_672 ) ;
V_182 -> V_507 = F_154 (
V_671 * V_618 -> V_642 ,
( V_532 -> V_509 - V_233 -> V_509 ) * V_233 -> V_642
) / V_88 ;
if ( V_182 -> V_507 < V_618 -> V_653 )
return F_459 ( V_182 , V_532 ) ;
}
static struct V_492 * F_461 ( struct V_581 * V_182 )
{
struct V_640 * V_233 , * V_618 ;
struct V_617 V_532 ;
F_437 ( & V_532 ) ;
F_456 ( V_182 , & V_532 ) ;
V_233 = & V_532 . V_664 ;
V_618 = & V_532 . V_621 ;
if ( F_458 ( V_182 , & V_532 ) )
return V_532 . V_618 ;
if ( ! V_532 . V_618 || V_618 -> V_622 == 0 )
goto V_673;
V_532 . V_509 = ( V_88 * V_532 . V_619 )
/ V_532 . V_620 ;
if ( V_618 -> V_623 == V_648 )
goto V_674;
if ( V_182 -> V_405 == V_612 && F_446 ( V_182 , V_233 ) &&
V_618 -> V_646 )
goto V_674;
if ( V_233 -> V_509 >= V_618 -> V_509 )
goto V_673;
if ( V_233 -> V_509 >= V_532 . V_509 )
goto V_673;
if ( V_182 -> V_405 == V_675 ) {
if ( ( V_618 -> V_623 != V_647 ) &&
( V_233 -> V_652 <= ( V_618 -> V_652 + 1 ) ) )
goto V_673;
} else {
if ( 100 * V_618 -> V_509 <=
V_182 -> V_213 -> V_197 * V_233 -> V_509 )
goto V_673;
}
V_674:
F_460 ( V_182 , & V_532 ) ;
return V_532 . V_618 ;
V_673:
V_182 -> V_507 = 0 ;
return NULL ;
}
static struct V_25 * F_462 ( struct V_581 * V_182 ,
struct V_492 * V_148 )
{
struct V_25 * V_618 = NULL , * V_25 ;
unsigned long V_676 = 0 , V_677 = 1 ;
int V_272 ;
F_376 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_177 , V_473 ;
enum V_658 V_678 ;
V_25 = F_124 ( V_272 ) ;
V_678 = F_455 ( V_25 ) ;
if ( V_678 > V_182 -> V_658 )
continue;
V_177 = F_126 ( V_272 ) ;
V_473 = F_125 ( V_272 ) ;
if ( V_25 -> V_75 == 1 && V_473 > V_182 -> V_507 &&
! F_444 ( V_25 , V_182 -> V_213 ) )
continue;
if ( V_473 * V_677 > V_676 * V_177 ) {
V_676 = V_473 ;
V_677 = V_177 ;
V_618 = V_25 ;
}
}
return V_618 ;
}
static int F_463 ( struct V_581 * V_182 )
{
struct V_212 * V_213 = V_182 -> V_213 ;
if ( V_182 -> V_405 == V_612 ) {
if ( ( V_213 -> V_115 & V_656 ) &&
F_453 ( V_182 -> V_168 , V_182 -> V_201 ) )
return 1 ;
}
if ( ( V_182 -> V_405 != V_605 ) &&
( V_182 -> V_200 -> V_42 . V_416 == 1 ) ) {
if ( ( F_444 ( V_182 -> V_200 , V_213 ) ) &&
( F_126 ( V_182 -> V_201 ) * V_213 -> V_197 < F_126 ( V_182 -> V_168 ) * 100 ) )
return 1 ;
}
return F_14 ( V_213 -> V_595 > V_213 -> V_596 + 2 ) ;
}
static int F_464 ( struct V_581 * V_182 )
{
struct V_492 * V_644 = V_182 -> V_213 -> V_495 ;
struct V_526 * V_679 , * V_680 ;
int V_1 , V_681 = - 1 ;
if ( V_182 -> V_405 == V_612 )
return 1 ;
V_679 = F_372 ( V_644 ) ;
V_680 = F_465 ( V_644 ) ;
F_376 (cpu, sg_cpus, env->cpus) {
if ( ! F_137 ( V_1 , V_680 ) || ! F_377 ( V_1 ) )
continue;
V_681 = V_1 ;
break;
}
if ( V_681 == - 1 )
V_681 = F_466 ( V_644 ) ;
return V_681 == V_182 -> V_168 ;
}
static int F_467 ( int V_486 , struct V_25 * F_238 ,
struct V_212 * V_213 , enum V_625 V_405 ,
int * V_682 )
{
int V_683 , V_684 , V_685 = 0 ;
struct V_212 * V_686 = V_213 -> V_35 ;
struct V_492 * V_148 ;
struct V_25 * V_618 ;
unsigned long V_115 ;
struct V_526 * V_9 = F_386 ( V_687 ) ;
struct V_581 V_182 = {
. V_213 = V_213 ,
. V_168 = V_486 ,
. V_202 = F_238 ,
. V_590 = F_372 ( V_213 -> V_495 ) ,
. V_405 = V_405 ,
. V_608 = V_609 ,
. V_9 = V_9 ,
. V_658 = V_660 ,
. V_603 = F_468 ( V_182 . V_603 ) ,
} ;
if ( V_405 == V_612 )
V_182 . V_590 = NULL ;
F_469 ( V_9 , V_688 ) ;
F_83 ( V_213 -> V_689 [ V_405 ] ) ;
V_690:
if ( ! F_464 ( & V_182 ) ) {
* V_682 = 0 ;
goto V_673;
}
V_148 = F_461 ( & V_182 ) ;
if ( ! V_148 ) {
F_83 ( V_213 -> V_691 [ V_405 ] ) ;
goto V_673;
}
V_618 = F_462 ( & V_182 , V_148 ) ;
if ( ! V_618 ) {
F_83 ( V_213 -> V_692 [ V_405 ] ) ;
goto V_673;
}
F_181 ( V_618 == V_182 . V_202 ) ;
F_70 ( V_213 -> V_693 [ V_405 ] , V_182 . V_507 ) ;
V_182 . V_201 = V_618 -> V_1 ;
V_182 . V_200 = V_618 ;
V_683 = 0 ;
if ( V_618 -> V_75 > 1 ) {
V_182 . V_115 |= V_593 ;
V_182 . V_607 = F_154 ( V_694 , V_618 -> V_75 ) ;
V_695:
F_433 ( & V_618 -> V_257 , V_115 ) ;
F_311 ( V_618 ) ;
V_684 = F_423 ( & V_182 ) ;
F_299 ( & V_618 -> V_257 ) ;
if ( V_684 ) {
F_431 ( & V_182 ) ;
V_683 += V_684 ;
}
F_470 ( V_115 ) ;
if ( V_182 . V_115 & V_610 ) {
V_182 . V_115 &= ~ V_610 ;
goto V_695;
}
if ( ( V_182 . V_115 & V_591 ) && V_182 . V_507 > 0 ) {
F_390 ( V_182 . V_168 , V_182 . V_9 ) ;
V_182 . V_202 = F_124 ( V_182 . V_592 ) ;
V_182 . V_168 = V_182 . V_592 ;
V_182 . V_115 &= ~ V_591 ;
V_182 . V_606 = 0 ;
V_182 . V_608 = V_609 ;
goto V_695;
}
if ( V_686 ) {
int * V_696 = & V_686 -> V_495 -> V_514 -> V_507 ;
if ( ( V_182 . V_115 & V_589 ) && V_182 . V_507 > 0 )
* V_696 = 1 ;
}
if ( F_14 ( V_182 . V_115 & V_593 ) ) {
F_390 ( F_26 ( V_618 ) , V_9 ) ;
if ( ! F_471 ( V_9 ) ) {
V_182 . V_606 = 0 ;
V_182 . V_608 = V_609 ;
goto V_690;
}
goto V_697;
}
}
if ( ! V_683 ) {
F_83 ( V_213 -> V_698 [ V_405 ] ) ;
if ( V_405 != V_612 )
V_213 -> V_595 ++ ;
if ( F_463 ( & V_182 ) ) {
F_433 ( & V_618 -> V_257 , V_115 ) ;
if ( ! F_137 ( V_486 , & V_618 -> V_47 -> V_207 ) ) {
F_434 ( & V_618 -> V_257 ,
V_115 ) ;
V_182 . V_115 |= V_593 ;
goto V_699;
}
if ( ! V_618 -> V_685 ) {
V_618 -> V_685 = 1 ;
V_618 -> V_700 = V_486 ;
V_685 = 1 ;
}
F_434 ( & V_618 -> V_257 , V_115 ) ;
if ( V_685 ) {
F_472 ( F_26 ( V_618 ) ,
V_701 , V_618 ,
& V_618 -> V_702 ) ;
}
V_213 -> V_595 = V_213 -> V_596 + 1 ;
}
} else
V_213 -> V_595 = 0 ;
if ( F_12 ( ! V_685 ) ) {
V_213 -> V_635 = V_213 -> V_703 ;
} else {
if ( V_213 -> V_635 < V_213 -> V_704 )
V_213 -> V_635 *= 2 ;
}
goto V_321;
V_673:
if ( V_686 ) {
int * V_696 = & V_686 -> V_495 -> V_514 -> V_507 ;
if ( * V_696 )
* V_696 = 0 ;
}
V_697:
F_83 ( V_213 -> V_705 [ V_405 ] ) ;
V_213 -> V_595 = 0 ;
V_699:
if ( ( ( V_182 . V_115 & V_593 ) &&
V_213 -> V_635 < V_706 ) ||
( V_213 -> V_635 < V_213 -> V_704 ) )
V_213 -> V_635 *= 2 ;
V_683 = 0 ;
V_321:
return V_683 ;
}
static inline unsigned long
F_473 ( struct V_212 * V_213 , int V_707 )
{
unsigned long V_221 = V_213 -> V_635 ;
if ( V_707 )
V_221 *= V_213 -> V_708 ;
V_221 = F_155 ( V_221 ) ;
V_221 = F_158 ( V_221 , 1UL , V_636 ) ;
return V_221 ;
}
static inline void
F_474 ( struct V_212 * V_213 , unsigned long * V_709 )
{
unsigned long V_221 , V_61 ;
V_221 = F_473 ( V_213 , 0 ) ;
V_61 = V_213 -> V_710 + V_221 ;
if ( F_192 ( * V_709 , V_61 ) )
* V_709 = V_61 ;
}
static int F_253 ( struct V_25 * F_238 , struct V_370 * V_371 )
{
unsigned long V_709 = V_224 + V_222 ;
int V_486 = F_238 -> V_1 ;
struct V_212 * V_213 ;
int V_711 = 0 ;
T_2 V_712 = 0 ;
F_238 -> V_525 = F_78 ( F_238 ) ;
F_475 ( F_238 , V_371 ) ;
if ( F_238 -> V_543 < V_583 ||
! F_238 -> V_551 -> V_649 ) {
F_134 () ;
V_213 = F_476 ( F_238 -> V_213 ) ;
if ( V_213 )
F_474 ( V_213 , & V_709 ) ;
F_142 () ;
goto V_321;
}
F_299 ( & F_238 -> V_257 ) ;
F_432 ( V_486 ) ;
F_134 () ;
F_399 (this_cpu, sd) {
int V_682 = 1 ;
T_2 V_713 , V_714 ;
if ( ! ( V_213 -> V_115 & V_560 ) )
continue;
if ( F_238 -> V_543 < V_712 + V_213 -> V_715 ) {
F_474 ( V_213 , & V_709 ) ;
break;
}
if ( V_213 -> V_115 & V_716 ) {
V_713 = F_292 ( V_486 ) ;
V_711 = F_467 ( V_486 , F_238 ,
V_213 , V_612 ,
& V_682 ) ;
V_714 = F_292 ( V_486 ) - V_713 ;
if ( V_714 > V_213 -> V_715 )
V_213 -> V_715 = V_714 ;
V_712 += V_714 ;
}
F_474 ( V_213 , & V_709 ) ;
if ( V_711 || F_238 -> V_75 > 0 )
break;
}
F_142 () ;
F_297 ( & F_238 -> V_257 ) ;
if ( V_712 > F_238 -> V_717 )
F_238 -> V_717 = V_712 ;
if ( F_238 -> V_42 . V_416 && ! V_711 )
V_711 = 1 ;
V_321:
if ( F_192 ( F_238 -> V_709 , V_709 ) )
F_238 -> V_709 = V_709 ;
if ( F_238 -> V_75 != F_238 -> V_42 . V_416 )
V_711 = - 1 ;
if ( V_711 )
F_238 -> V_525 = 0 ;
F_477 ( F_238 , V_371 ) ;
return V_711 ;
}
static int V_701 ( void * V_411 )
{
struct V_25 * V_718 = V_411 ;
int V_666 = F_26 ( V_718 ) ;
int V_719 = V_718 -> V_700 ;
struct V_25 * V_720 = F_124 ( V_719 ) ;
struct V_212 * V_213 ;
struct V_27 * V_30 = NULL ;
F_478 ( & V_718 -> V_257 ) ;
if ( F_14 ( V_666 != F_293 () ||
! V_718 -> V_685 ) )
goto V_721;
if ( V_718 -> V_75 <= 1 )
goto V_721;
F_181 ( V_718 == V_720 ) ;
F_134 () ;
F_399 (target_cpu, sd) {
if ( ( V_213 -> V_115 & V_560 ) &&
F_137 ( V_666 , F_388 ( V_213 ) ) )
break;
}
if ( F_12 ( V_213 ) ) {
struct V_581 V_182 = {
. V_213 = V_213 ,
. V_168 = V_719 ,
. V_202 = V_720 ,
. V_201 = V_718 -> V_1 ,
. V_200 = V_718 ,
. V_405 = V_675 ,
} ;
F_83 ( V_213 -> V_722 ) ;
F_311 ( V_718 ) ;
V_30 = F_421 ( & V_182 ) ;
if ( V_30 ) {
F_83 ( V_213 -> V_723 ) ;
V_213 -> V_595 = 0 ;
} else {
F_83 ( V_213 -> V_724 ) ;
}
}
F_142 () ;
V_721:
V_718 -> V_685 = 0 ;
F_299 ( & V_718 -> V_257 ) ;
if ( V_30 )
F_430 ( V_720 , V_30 ) ;
F_141 () ;
return 0 ;
}
static inline int F_479 ( struct V_25 * V_25 )
{
return F_14 ( ! F_480 ( V_25 -> V_213 ) ) ;
}
static inline int F_481 ( void )
{
int V_725 = F_375 ( V_726 . V_727 ) ;
if ( V_725 < V_728 && F_377 ( V_725 ) )
return V_725 ;
return V_728 ;
}
static void F_482 ( void )
{
int V_729 ;
V_726 . V_709 ++ ;
V_729 = F_481 () ;
if ( V_729 >= V_728 )
return;
if ( F_483 ( V_730 , F_484 ( V_729 ) ) )
return;
F_485 ( V_729 ) ;
return;
}
void F_486 ( unsigned int V_1 )
{
if ( F_14 ( F_487 ( V_731 , F_484 ( V_1 ) ) ) ) {
if ( F_12 ( F_137 ( V_1 , V_726 . V_727 ) ) ) {
F_390 ( V_1 , V_726 . V_727 ) ;
F_488 ( & V_726 . V_732 ) ;
}
F_489 ( V_731 , F_484 ( V_1 ) ) ;
}
}
static inline void F_490 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_293 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_545 , V_1 ) ) ;
if ( ! V_213 || ! V_213 -> V_733 )
goto V_206;
V_213 -> V_733 = 0 ;
F_491 ( & V_213 -> V_226 -> V_734 ) ;
V_206:
F_142 () ;
}
void F_492 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_293 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_545 , V_1 ) ) ;
if ( ! V_213 || V_213 -> V_733 )
goto V_206;
V_213 -> V_733 = 1 ;
F_488 ( & V_213 -> V_226 -> V_734 ) ;
V_206:
F_142 () ;
}
void F_493 ( int V_1 )
{
if ( ! F_494 ( V_1 ) )
return;
if ( F_487 ( V_731 , F_484 ( V_1 ) ) )
return;
if ( F_479 ( F_124 ( V_1 ) ) )
return;
F_495 ( V_1 , V_726 . V_727 ) ;
F_491 ( & V_726 . V_732 ) ;
F_496 ( V_731 , F_484 ( V_1 ) ) ;
}
void F_497 ( void )
{
V_636 = V_222 * F_498 () / 10 ;
}
static void F_499 ( struct V_25 * V_25 , enum V_625 V_405 )
{
int V_682 = 1 ;
int V_1 = V_25 -> V_1 ;
unsigned long V_221 ;
struct V_212 * V_213 ;
unsigned long V_709 = V_224 + 60 * V_222 ;
int F_474 = 0 ;
int V_735 , V_736 = 0 ;
T_2 V_737 = 0 ;
F_432 ( V_1 ) ;
F_134 () ;
F_399 (cpu, sd) {
if ( F_192 ( V_224 , V_213 -> V_738 ) ) {
V_213 -> V_715 =
( V_213 -> V_715 * 253 ) / 256 ;
V_213 -> V_738 = V_224 + V_222 ;
V_736 = 1 ;
}
V_737 += V_213 -> V_715 ;
if ( ! ( V_213 -> V_115 & V_560 ) )
continue;
if ( ! V_682 ) {
if ( V_736 )
continue;
break;
}
V_221 = F_473 ( V_213 , V_405 != V_675 ) ;
V_735 = V_213 -> V_115 & V_739 ;
if ( V_735 ) {
if ( ! F_500 ( & V_740 ) )
goto V_321;
}
if ( F_457 ( V_224 , V_213 -> V_710 + V_221 ) ) {
if ( F_467 ( V_1 , V_25 , V_213 , V_405 , & V_682 ) ) {
V_405 = F_377 ( V_1 ) ? V_675 : V_605 ;
}
V_213 -> V_710 = V_224 ;
V_221 = F_473 ( V_213 , V_405 != V_675 ) ;
}
if ( V_735 )
F_184 ( & V_740 ) ;
V_321:
if ( F_192 ( V_709 , V_213 -> V_710 + V_221 ) ) {
V_709 = V_213 -> V_710 + V_221 ;
F_474 = 1 ;
}
}
if ( V_736 ) {
V_25 -> V_717 =
F_69 ( ( T_2 ) V_583 , V_737 ) ;
}
F_142 () ;
if ( F_12 ( F_474 ) ) {
V_25 -> V_709 = V_709 ;
#ifdef F_350
if ( ( V_405 == V_675 ) && F_192 ( V_726 . V_709 , V_25 -> V_709 ) )
V_726 . V_709 = V_25 -> V_709 ;
#endif
}
}
static void F_501 ( struct V_25 * F_238 , enum V_625 V_405 )
{
int V_486 = F_238 -> V_1 ;
struct V_25 * V_25 ;
int V_681 ;
unsigned long V_709 = V_224 + 60 * V_222 ;
int F_474 = 0 ;
if ( V_405 != V_675 ||
! F_487 ( V_730 , F_484 ( V_486 ) ) )
goto V_301;
F_123 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_681 == V_486 || ! F_377 ( V_681 ) )
continue;
if ( F_502 () )
break;
V_25 = F_124 ( V_681 ) ;
if ( F_457 ( V_224 , V_25 -> V_709 ) ) {
F_478 ( & V_25 -> V_257 ) ;
F_311 ( V_25 ) ;
F_353 ( V_25 ) ;
F_503 ( & V_25 -> V_257 ) ;
F_499 ( V_25 , V_675 ) ;
}
if ( F_192 ( V_709 , V_25 -> V_709 ) ) {
V_709 = V_25 -> V_709 ;
F_474 = 1 ;
}
}
if ( F_12 ( F_474 ) )
V_726 . V_709 = V_709 ;
V_301:
F_489 ( V_730 , F_484 ( V_486 ) ) ;
}
static inline bool F_504 ( struct V_25 * V_25 )
{
unsigned long V_92 = V_224 ;
struct V_531 * V_532 ;
struct V_212 * V_213 ;
int V_741 , V_272 , V_1 = V_25 -> V_1 ;
bool V_742 = false ;
if ( F_14 ( V_25 -> F_253 ) )
return false ;
F_490 () ;
F_486 ( V_1 ) ;
if ( F_12 ( ! F_505 ( & V_726 . V_732 ) ) )
return false ;
if ( F_196 ( V_92 , V_726 . V_709 ) )
return false ;
if ( V_25 -> V_75 >= 2 )
return true ;
F_134 () ;
V_532 = F_147 ( F_148 ( V_533 , V_1 ) ) ;
if ( V_532 ) {
V_741 = F_505 ( & V_532 -> V_734 ) ;
if ( V_741 > 1 ) {
V_742 = true ;
goto V_206;
}
}
V_213 = F_147 ( V_25 -> V_213 ) ;
if ( V_213 ) {
if ( ( V_25 -> V_42 . V_416 >= 1 ) &&
F_444 ( V_25 , V_213 ) ) {
V_742 = true ;
goto V_206;
}
}
V_213 = F_147 ( F_148 ( V_743 , V_1 ) ) ;
if ( V_213 ) {
F_123 (i, sched_domain_span(sd)) {
if ( V_272 == V_1 ||
! F_137 ( V_272 , V_726 . V_727 ) )
continue;
if ( F_453 ( V_272 , V_1 ) ) {
V_742 = true ;
goto V_206;
}
}
}
V_206:
F_142 () ;
return V_742 ;
}
static void F_501 ( struct V_25 * F_238 , enum V_625 V_405 ) { }
static T_12 void F_506 ( struct V_744 * V_745 )
{
struct V_25 * F_238 = F_238 () ;
enum V_625 V_405 = F_238 -> F_253 ?
V_675 : V_605 ;
F_501 ( F_238 , V_405 ) ;
F_499 ( F_238 , V_405 ) ;
}
void F_507 ( struct V_25 * V_25 )
{
if ( F_14 ( F_479 ( V_25 ) ) )
return;
if ( F_457 ( V_224 , V_25 -> V_709 ) )
F_508 ( V_746 ) ;
#ifdef F_350
if ( F_504 ( V_25 ) )
F_482 () ;
#endif
}
static void F_509 ( struct V_25 * V_25 )
{
F_8 () ;
F_337 ( V_25 ) ;
}
static void F_510 ( struct V_25 * V_25 )
{
F_8 () ;
F_339 ( V_25 ) ;
}
static void F_511 ( struct V_25 * V_25 , struct V_27 * V_47 , int V_387 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_47 -> V_29 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_280 ( V_26 , V_29 , V_387 ) ;
}
if ( F_512 ( & V_286 ) )
F_207 ( V_25 , V_47 ) ;
}
static void F_513 ( struct V_27 * V_30 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 , * V_47 ;
struct V_25 * V_25 = F_238 () ;
F_297 ( & V_25 -> V_257 ) ;
F_311 ( V_25 ) ;
V_26 = F_22 ( V_172 ) ;
V_47 = V_26 -> V_47 ;
if ( V_47 ) {
F_66 ( V_26 ) ;
V_29 -> V_43 = V_47 -> V_43 ;
}
F_256 ( V_26 , V_29 , 1 ) ;
if ( V_747 && V_47 && F_37 ( V_47 , V_29 ) ) {
F_132 ( V_47 -> V_43 , V_29 -> V_43 ) ;
F_274 ( V_25 ) ;
}
V_29 -> V_43 -= V_26 -> F_36 ;
F_299 ( & V_25 -> V_257 ) ;
}
static void
F_514 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_748 )
{
if ( ! F_515 ( V_30 ) )
return;
if ( V_25 -> V_47 == V_30 ) {
if ( V_30 -> V_749 > V_748 )
F_274 ( V_25 ) ;
} else
F_429 ( V_25 , V_30 , 0 ) ;
}
static inline bool F_516 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_48 )
return true ;
if ( ! V_29 -> V_96 || V_30 -> V_118 == V_564 )
return true ;
return false ;
}
static void F_517 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
V_29 = V_29 -> V_35 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
if ( F_302 ( V_26 ) )
break;
F_243 ( V_29 , V_367 ) ;
}
}
static void F_517 ( struct V_28 * V_29 ) { }
static void F_518 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_243 ( V_29 , 0 ) ;
F_245 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_517 ( V_29 ) ;
}
static void F_64 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
#ifdef F_408
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
#endif
F_243 ( V_29 , F_229 ( V_351 ) ? 0 : V_366 ) ;
F_244 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_517 ( V_29 ) ;
}
static void F_519 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( ! F_516 ( V_30 ) ) {
F_256 ( V_26 , V_29 , 0 ) ;
V_29 -> V_43 -= V_26 -> F_36 ;
}
F_518 ( V_29 ) ;
}
static void F_520 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_64 ( V_29 ) ;
if ( ! F_516 ( V_30 ) )
V_29 -> V_43 += V_26 -> F_36 ;
}
static void F_521 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_519 ( V_30 ) ;
}
static void F_522 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_520 ( V_30 ) ;
if ( F_515 ( V_30 ) ) {
if ( V_25 -> V_47 == V_30 )
F_274 ( V_25 ) ;
else
F_429 ( V_25 , V_30 , 0 ) ;
}
}
static void F_523 ( struct V_25 * V_25 )
{
struct V_28 * V_29 = & V_25 -> V_47 -> V_29 ;
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_275 ( V_26 , V_29 ) ;
F_74 ( V_26 , 0 ) ;
}
}
void F_524 ( struct V_26 * V_26 )
{
V_26 -> V_54 = V_750 ;
V_26 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_26 -> V_51 = V_26 -> F_36 ;
#endif
#ifdef F_211
#ifdef F_408
V_26 -> V_359 = 0 ;
#endif
F_525 ( & V_26 -> V_363 , 0 ) ;
F_525 ( & V_26 -> V_365 , 0 ) ;
#endif
}
static void F_526 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
F_527 ( V_30 , F_146 ( V_30 ) ) ;
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
}
static void F_528 ( struct V_27 * V_30 )
{
F_519 ( V_30 ) ;
F_527 ( V_30 , F_146 ( V_30 ) ) ;
#ifdef F_211
V_30 -> V_29 . V_79 . V_80 = 0 ;
#endif
F_520 ( V_30 ) ;
}
static void F_529 ( struct V_27 * V_30 , int type )
{
switch ( type ) {
case V_751 :
F_526 ( V_30 ) ;
break;
case V_752 :
F_528 ( V_30 ) ;
break;
}
}
void F_530 ( struct V_325 * V_34 )
{
int V_272 ;
F_335 ( F_295 ( V_34 ) ) ;
F_531 (i) {
if ( V_34 -> V_26 )
F_189 ( V_34 -> V_26 [ V_272 ] ) ;
if ( V_34 -> V_29 )
F_189 ( V_34 -> V_29 [ V_272 ] ) ;
}
F_189 ( V_34 -> V_26 ) ;
F_189 ( V_34 -> V_29 ) ;
}
int F_532 ( struct V_325 * V_34 , struct V_325 * V_35 )
{
struct V_28 * V_29 ;
struct V_26 * V_26 ;
int V_272 ;
V_34 -> V_26 = F_177 ( sizeof( V_26 ) * V_728 , V_274 ) ;
if ( ! V_34 -> V_26 )
goto V_753;
V_34 -> V_29 = F_177 ( sizeof( V_29 ) * V_728 , V_274 ) ;
if ( ! V_34 -> V_29 )
goto V_753;
V_34 -> V_327 = V_74 ;
F_328 ( F_295 ( V_34 ) ) ;
F_531 (i) {
V_26 = F_533 ( sizeof( struct V_26 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_26 )
goto V_753;
V_29 = F_533 ( sizeof( struct V_28 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_29 )
goto V_754;
F_524 ( V_26 ) ;
F_534 ( V_34 , V_26 , V_29 , V_272 , V_35 -> V_29 [ V_272 ] ) ;
F_61 ( V_29 ) ;
}
return 1 ;
V_754:
F_189 ( V_26 ) ;
V_753:
return 0 ;
}
void F_535 ( struct V_325 * V_34 )
{
struct V_28 * V_29 ;
struct V_25 * V_25 ;
int V_272 ;
F_531 (i) {
V_25 = F_124 ( V_272 ) ;
V_29 = V_34 -> V_29 [ V_272 ] ;
F_478 ( & V_25 -> V_257 ) ;
F_311 ( V_25 ) ;
F_64 ( V_29 ) ;
F_324 ( V_34 , V_272 ) ;
F_503 ( & V_25 -> V_257 ) ;
}
}
void F_536 ( struct V_325 * V_34 )
{
unsigned long V_115 ;
struct V_25 * V_25 ;
int V_1 ;
F_531 (cpu) {
if ( V_34 -> V_29 [ V_1 ] )
F_250 ( V_34 -> V_29 [ V_1 ] ) ;
if ( ! V_34 -> V_26 [ V_1 ] -> V_33 )
continue;
V_25 = F_124 ( V_1 ) ;
F_433 ( & V_25 -> V_257 , V_115 ) ;
F_29 ( V_34 -> V_26 [ V_1 ] ) ;
F_434 ( & V_25 -> V_257 , V_115 ) ;
}
}
void F_534 ( struct V_325 * V_34 , struct V_26 * V_26 ,
struct V_28 * V_29 , int V_1 ,
struct V_28 * V_35 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_25 = V_25 ;
F_332 ( V_26 ) ;
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
int F_537 ( struct V_325 * V_34 , unsigned long V_327 )
{
int V_272 ;
unsigned long V_115 ;
if ( ! V_34 -> V_29 [ 0 ] )
return - V_217 ;
V_327 = F_158 ( V_327 , F_538 ( V_329 ) , F_538 ( V_755 ) ) ;
F_539 ( & V_756 ) ;
if ( V_34 -> V_327 == V_327 )
goto V_757;
V_34 -> V_327 = V_327 ;
F_531 (i) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_28 * V_29 ;
V_29 = V_34 -> V_29 [ V_272 ] ;
F_433 ( & V_25 -> V_257 , V_115 ) ;
F_311 ( V_25 ) ;
F_59 (se) {
F_243 ( V_29 , V_367 ) ;
F_218 ( V_29 ) ;
}
F_434 ( & V_25 -> V_257 , V_115 ) ;
}
V_757:
F_540 ( & V_756 ) ;
return 0 ;
}
void F_530 ( struct V_325 * V_34 ) { }
int F_532 ( struct V_325 * V_34 , struct V_325 * V_35 )
{
return 1 ;
}
void F_535 ( struct V_325 * V_34 ) { }
void F_536 ( struct V_325 * V_34 ) { }
static unsigned int F_541 ( struct V_25 * V_25 , struct V_27 * V_154 )
{
struct V_28 * V_29 = & V_154 -> V_29 ;
unsigned int V_758 = 0 ;
if ( V_25 -> V_42 . V_73 . V_5 )
V_758 = F_542 ( F_58 ( F_23 ( V_29 ) , V_29 ) ) ;
return V_758 ;
}
void F_543 ( struct V_759 * V_760 , int V_1 )
{
struct V_26 * V_26 ;
F_134 () ;
F_338 (cpu_rq(cpu), cfs_rq)
F_544 ( V_760 , V_1 , V_26 ) ;
F_142 () ;
}
void F_545 ( struct V_27 * V_30 , struct V_759 * V_760 )
{
int V_156 ;
unsigned long V_761 = 0 , V_762 = 0 , V_763 = 0 , V_764 = 0 ;
F_111 (node) {
if ( V_30 -> V_145 ) {
V_761 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 0 ) ] ;
V_762 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
if ( V_30 -> V_137 ) {
V_763 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 0 ) ] ,
V_764 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
F_546 ( V_760 , V_156 , V_761 , V_762 , V_763 , V_764 ) ;
}
}
T_13 void F_547 ( void )
{
#ifdef F_211
F_548 ( V_746 , F_506 ) ;
#ifdef F_350
V_726 . V_709 = V_224 ;
F_549 ( & V_726 . V_727 , V_765 ) ;
#endif
#endif
}
