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
static T_2 F_220 ( T_2 V_330 , T_2 V_331 )
{
unsigned int V_332 ;
if ( F_14 ( V_331 > V_333 * 63 ) )
return 0 ;
V_332 = V_331 ;
if ( F_14 ( V_332 >= V_333 ) ) {
V_330 >>= V_332 / V_333 ;
V_332 %= V_333 ;
}
V_330 = F_16 ( V_330 , V_334 [ V_332 ] , 32 ) ;
return V_330 ;
}
static V_24 F_221 ( T_2 V_335 , V_24 V_336 , V_24 V_337 )
{
V_24 V_338 , V_339 , V_340 = V_337 ;
V_338 = F_220 ( ( T_2 ) V_336 , V_335 ) ;
V_339 = V_84 - F_220 ( V_84 , V_335 ) - 1024 ;
return V_338 + V_339 + V_340 ;
}
static T_10 V_24
F_222 ( T_2 V_44 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_341 , struct V_26 * V_26 )
{
unsigned long V_342 , V_343 ;
V_24 V_344 = ( V_24 ) V_44 ;
T_2 V_335 ;
V_342 = F_223 ( NULL , V_1 ) ;
V_343 = F_224 ( NULL , V_1 ) ;
V_44 += V_78 -> V_81 ;
V_335 = V_44 / 1024 ;
if ( V_335 ) {
V_78 -> V_83 = F_220 ( V_78 -> V_83 , V_335 ) ;
if ( V_26 ) {
V_26 -> V_345 =
F_220 ( V_26 -> V_345 , V_335 ) ;
}
V_78 -> V_86 = F_220 ( ( T_2 ) ( V_78 -> V_86 ) , V_335 ) ;
V_44 %= 1024 ;
V_344 = F_221 ( V_335 ,
1024 - V_78 -> V_81 , V_44 ) ;
}
V_78 -> V_81 = V_44 ;
V_344 = F_225 ( V_344 , V_342 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_344 ;
if ( V_26 )
V_26 -> V_345 += V_5 * V_344 ;
}
if ( V_341 )
V_78 -> V_86 += V_344 * V_343 ;
return V_335 ;
}
static T_10 int
F_226 ( T_2 V_92 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_341 , struct V_26 * V_26 )
{
T_2 V_44 ;
V_44 = V_92 - V_78 -> V_80 ;
if ( ( T_3 ) V_44 < 0 ) {
V_78 -> V_80 = V_92 ;
return 0 ;
}
V_44 >>= 10 ;
if ( ! V_44 )
return 0 ;
V_78 -> V_80 += V_44 << 10 ;
if ( ! F_222 ( V_44 , V_1 , V_78 , V_5 , V_341 , V_26 ) )
return 0 ;
V_78 -> V_82 = F_227 ( V_78 -> V_83 , V_84 ) ;
if ( V_26 ) {
V_26 -> V_346 =
F_227 ( V_26 -> V_345 , V_84 ) ;
}
V_78 -> V_85 = V_78 -> V_86 / V_84 ;
return 1 ;
}
static int
F_228 ( T_2 V_92 , int V_1 , struct V_28 * V_29 )
{
return F_226 ( V_92 , V_1 , & V_29 -> V_79 , 0 , 0 , NULL ) ;
}
static int
F_229 ( T_2 V_92 , int V_1 , struct V_26 * V_26 , struct V_28 * V_29 )
{
return F_226 ( V_92 , V_1 , & V_29 -> V_79 ,
V_29 -> V_48 * F_13 ( V_29 -> V_73 . V_5 ) ,
V_26 -> V_47 == V_29 , NULL ) ;
}
static int
F_230 ( T_2 V_92 , int V_1 , struct V_26 * V_26 )
{
return F_226 ( V_92 , V_1 , & V_26 -> V_79 ,
F_13 ( V_26 -> V_73 . V_5 ) ,
V_26 -> V_47 != NULL , V_26 ) ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 )
{
long V_44 = V_26 -> V_79 . V_82 - V_26 -> V_328 ;
if ( V_26 -> V_34 == & V_347 )
return;
if ( V_91 || abs ( V_44 ) > V_26 -> V_328 / 64 ) {
F_231 ( V_44 , & V_26 -> V_34 -> V_82 ) ;
V_26 -> V_328 = V_26 -> V_79 . V_82 ;
}
}
void F_232 ( struct V_28 * V_29 ,
struct V_26 * V_348 , struct V_26 * V_61 )
{
T_2 V_349 ;
T_2 V_350 ;
if ( ! F_233 ( V_351 ) )
return;
if ( ! ( V_29 -> V_79 . V_80 && V_348 ) )
return;
#ifndef F_40
{
T_2 V_352 ;
T_2 V_353 ;
do {
V_352 = V_348 -> V_354 ;
V_353 = V_61 -> V_354 ;
F_234 () ;
V_349 = V_348 -> V_79 . V_80 ;
V_350 = V_61 -> V_79 . V_80 ;
} while ( V_349 != V_352 ||
V_350 != V_353 );
}
#else
V_349 = V_348 -> V_79 . V_80 ;
V_350 = V_61 -> V_79 . V_80 ;
#endif
F_228 ( V_349 , F_26 ( F_17 ( V_348 ) ) , V_29 ) ;
V_29 -> V_79 . V_80 = V_350 ;
}
static inline void
F_235 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_355 = F_24 ( V_29 ) ;
long V_44 = V_355 -> V_79 . V_85 - V_29 -> V_79 . V_85 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_85 = V_355 -> V_79 . V_85 ;
V_29 -> V_79 . V_86 = V_29 -> V_79 . V_85 * V_84 ;
F_236 ( & V_26 -> V_79 . V_85 , V_44 ) ;
V_26 -> V_79 . V_86 = V_26 -> V_79 . V_85 * V_84 ;
}
static inline void
F_237 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_355 = F_24 ( V_29 ) ;
long V_44 , V_73 = V_355 -> V_79 . V_82 ;
if ( V_73 ) {
long V_356 ;
V_356 = F_216 ( & V_355 -> V_34 -> V_82 ) + 1 ;
V_356 -= V_355 -> V_328 ;
V_356 += V_73 ;
if ( V_356 > F_13 ( V_355 -> V_34 -> V_327 ) ) {
V_73 *= F_13 ( V_355 -> V_34 -> V_327 ) ;
V_73 /= V_356 ;
}
}
V_44 = V_73 - V_29 -> V_79 . V_82 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_82 = V_73 ;
V_29 -> V_79 . V_83 = V_29 -> V_79 . V_82 * V_84 ;
F_236 ( & V_26 -> V_79 . V_82 , V_44 ) ;
V_26 -> V_79 . V_83 = V_26 -> V_79 . V_82 * V_84 ;
if ( V_29 -> V_48 ) {
F_236 ( & V_26 -> V_346 , V_44 ) ;
V_26 -> V_345 = V_26 -> V_346 * V_84 ;
}
}
static inline void F_238 ( struct V_26 * V_26 )
{
V_26 -> V_357 = 1 ;
}
static inline int F_239 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
if ( ! V_26 -> V_357 )
return 0 ;
V_26 -> V_357 = 0 ;
return 1 ;
}
static inline int F_240 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
if ( F_20 ( V_29 ) )
return 0 ;
if ( ! F_239 ( V_29 ) )
return 0 ;
V_26 = F_23 ( V_29 ) ;
F_238 ( V_26 ) ;
F_235 ( V_26 , V_29 ) ;
F_237 ( V_26 , V_29 ) ;
return 1 ;
}
static inline bool F_241 ( struct V_28 * V_29 )
{
struct V_26 * V_355 = F_24 ( V_29 ) ;
if ( V_29 -> V_79 . V_82 || V_29 -> V_79 . V_85 )
return false ;
if ( V_355 -> V_357 )
return false ;
return true ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 ) {}
static inline int F_240 ( struct V_28 * V_29 )
{
return 0 ;
}
static inline void F_238 ( struct V_26 * V_26 ) {}
static inline void F_242 ( struct V_26 * V_26 )
{
if ( & F_243 () -> V_42 == V_26 ) {
F_244 ( F_17 ( V_26 ) , 0 ) ;
}
}
static inline int
F_245 ( T_2 V_92 , struct V_26 * V_26 , bool V_358 )
{
struct V_77 * V_78 = & V_26 -> V_79 ;
int V_359 , V_360 = 0 , V_361 = 0 ;
if ( F_216 ( & V_26 -> V_362 ) ) {
T_3 V_363 = F_246 ( & V_26 -> V_362 , 0 ) ;
F_247 ( & V_78 -> V_82 , V_363 ) ;
F_247 ( & V_78 -> V_83 , V_363 * V_84 ) ;
V_360 = 1 ;
F_238 ( V_26 ) ;
}
if ( F_216 ( & V_26 -> V_364 ) ) {
long V_363 = F_246 ( & V_26 -> V_364 , 0 ) ;
F_247 ( & V_78 -> V_85 , V_363 ) ;
F_247 ( & V_78 -> V_86 , V_363 * V_84 ) ;
V_361 = 1 ;
F_238 ( V_26 ) ;
}
V_359 = F_230 ( V_92 , F_26 ( F_17 ( V_26 ) ) , V_26 ) ;
#ifndef F_40
F_41 () ;
V_26 -> V_354 = V_78 -> V_80 ;
#endif
if ( V_358 && ( V_359 || V_361 ) )
F_242 ( V_26 ) ;
return V_359 || V_360 ;
}
static inline void F_248 ( struct V_28 * V_29 , int V_115 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_92 = F_63 ( V_26 ) ;
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
int V_359 ;
if ( V_29 -> V_79 . V_80 && ! ( V_115 & V_365 ) )
F_229 ( V_92 , V_1 , V_26 , V_29 ) ;
V_359 = F_245 ( V_92 , V_26 , true ) ;
V_359 |= F_240 ( V_29 ) ;
if ( V_359 && ( V_115 & V_366 ) )
F_65 ( V_26 , 0 ) ;
}
static void F_249 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_79 . V_80 = V_26 -> V_79 . V_80 ;
V_26 -> V_79 . V_82 += V_29 -> V_79 . V_82 ;
V_26 -> V_79 . V_83 += V_29 -> V_79 . V_83 ;
V_26 -> V_79 . V_85 += V_29 -> V_79 . V_85 ;
V_26 -> V_79 . V_86 += V_29 -> V_79 . V_86 ;
F_238 ( V_26 ) ;
F_242 ( V_26 ) ;
}
static void F_250 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_247 ( & V_26 -> V_79 . V_82 , V_29 -> V_79 . V_82 ) ;
F_247 ( & V_26 -> V_79 . V_83 , V_29 -> V_79 . V_83 ) ;
F_247 ( & V_26 -> V_79 . V_85 , V_29 -> V_79 . V_85 ) ;
F_247 ( & V_26 -> V_79 . V_86 , V_29 -> V_79 . V_86 ) ;
F_238 ( V_26 ) ;
F_242 ( V_26 ) ;
}
static inline void
F_251 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_77 * V_78 = & V_29 -> V_79 ;
V_26 -> V_346 += V_78 -> V_82 ;
V_26 -> V_345 += V_78 -> V_83 ;
if ( ! V_78 -> V_80 ) {
F_249 ( V_26 , V_29 ) ;
F_65 ( V_26 , 0 ) ;
}
}
static inline void
F_252 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_26 -> V_346 =
F_99 ( long , V_26 -> V_346 - V_29 -> V_79 . V_82 , 0 ) ;
V_26 -> V_345 =
F_99 ( T_3 , V_26 -> V_345 - V_29 -> V_79 . V_83 , 0 ) ;
}
static inline T_2 F_253 ( struct V_26 * V_26 )
{
T_2 V_367 ;
T_2 V_80 ;
do {
V_367 = V_26 -> V_354 ;
F_234 () ;
V_80 = V_26 -> V_79 . V_80 ;
} while ( V_80 != V_367 );
return V_80 ;
}
static inline T_2 F_253 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_80 ;
}
void F_254 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_80 ;
V_80 = F_253 ( V_26 ) ;
F_228 ( V_80 , F_26 ( F_17 ( V_26 ) ) , V_29 ) ;
}
void F_255 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_254 ( V_29 ) ;
F_231 ( V_29 -> V_79 . V_82 , & V_26 -> V_362 ) ;
F_231 ( V_29 -> V_79 . V_85 , & V_26 -> V_364 ) ;
}
static inline unsigned long F_256 ( struct V_26 * V_26 )
{
return V_26 -> V_346 ;
}
static inline unsigned long F_257 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_82 ;
}
static inline int
F_245 ( T_2 V_92 , struct V_26 * V_26 , bool V_358 )
{
return 0 ;
}
static inline void F_248 ( struct V_28 * V_29 , int V_368 )
{
F_244 ( F_17 ( F_23 ( V_29 ) ) , 0 ) ;
}
static inline void
F_251 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_252 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void F_255 ( struct V_28 * V_29 ) {}
static inline void
F_249 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_250 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline int F_258 ( struct V_25 * V_25 , struct V_369 * V_370 )
{
return 0 ;
}
static void F_259 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
#ifdef F_260
T_3 V_371 = V_29 -> V_43 - V_26 -> F_36 ;
if ( V_371 < 0 )
V_371 = - V_371 ;
if ( V_371 > 3 * V_71 )
F_83 ( V_26 -> V_372 ) ;
#endif
}
static void
F_261 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_373 )
{
T_2 V_43 = V_26 -> F_36 ;
if ( V_373 && F_233 ( V_374 ) )
V_43 += F_60 ( V_26 , V_29 ) ;
if ( ! V_373 ) {
unsigned long V_375 = V_71 ;
if ( F_233 ( V_376 ) )
V_375 >>= 1 ;
V_43 -= V_375 ;
}
V_29 -> V_43 = F_35 ( V_29 -> V_43 , V_43 ) ;
}
static inline void F_262 ( void )
{
#ifdef F_263
if ( F_77 () )
return;
if ( F_264 () ||
F_265 () ||
F_266 () ||
F_267 () ||
F_268 () ) {
F_269 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_270 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
bool V_377 = ! ( V_115 & V_116 ) || ( V_115 & V_378 ) ;
bool V_47 = V_26 -> V_47 == V_29 ;
if ( V_377 && V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_66 ( V_26 ) ;
if ( V_377 && ! V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_248 ( V_29 , V_366 ) ;
F_251 ( V_26 , V_29 ) ;
F_218 ( V_29 ) ;
F_210 ( V_26 , V_29 ) ;
if ( V_115 & V_116 )
F_261 ( V_26 , V_29 , 0 ) ;
F_262 () ;
F_91 ( V_26 , V_29 , V_115 ) ;
F_259 ( V_26 , V_29 ) ;
if ( ! V_47 )
F_42 ( V_26 , V_29 ) ;
V_29 -> V_48 = 1 ;
if ( V_26 -> V_75 == 1 ) {
F_25 ( V_26 ) ;
F_271 ( V_26 ) ;
}
}
static void F_272 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_62 != V_29 )
break;
V_26 -> V_62 = NULL ;
}
}
static void F_273 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_61 != V_29 )
break;
V_26 -> V_61 = NULL ;
}
}
static void F_274 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_379 != V_29 )
break;
V_26 -> V_379 = NULL ;
}
}
static void F_275 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_62 == V_29 )
F_272 ( V_29 ) ;
if ( V_26 -> V_61 == V_29 )
F_273 ( V_29 ) ;
if ( V_26 -> V_379 == V_29 )
F_274 ( V_29 ) ;
}
static void
F_276 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
F_66 ( V_26 ) ;
F_248 ( V_29 , V_366 ) ;
F_252 ( V_26 , V_29 ) ;
F_92 ( V_26 , V_29 , V_115 ) ;
F_275 ( V_26 , V_29 ) ;
if ( V_29 != V_26 -> V_47 )
F_45 ( V_26 , V_29 ) ;
V_29 -> V_48 = 0 ;
F_213 ( V_26 , V_29 ) ;
if ( ! ( V_115 & V_117 ) )
V_29 -> V_43 -= V_26 -> F_36 ;
F_277 ( V_26 ) ;
F_218 ( V_29 ) ;
if ( ( V_115 & ( V_380 | V_381 ) ) == V_380 )
F_38 ( V_26 ) ;
}
static void
F_278 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
unsigned long V_382 , V_20 ;
struct V_28 * V_29 ;
T_3 V_44 ;
V_382 = F_58 ( V_26 , V_47 ) ;
V_20 = V_47 -> V_96 - V_47 -> V_383 ;
if ( V_20 > V_382 ) {
F_279 ( F_17 ( V_26 ) ) ;
F_275 ( V_26 , V_47 ) ;
return;
}
if ( V_20 < V_72 )
return;
V_29 = F_48 ( V_26 ) ;
V_44 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_44 < 0 )
return;
if ( V_44 > V_382 )
F_279 ( F_17 ( V_26 ) ) ;
}
static void
F_280 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_29 -> V_48 ) {
F_81 ( V_26 , V_29 ) ;
F_45 ( V_26 , V_29 ) ;
F_248 ( V_29 , V_366 ) ;
}
F_93 ( V_26 , V_29 ) ;
V_26 -> V_47 = V_29 ;
if ( F_77 () && F_17 ( V_26 ) -> V_73 . V_5 >= 2 * V_29 -> V_73 . V_5 ) {
F_68 ( V_29 -> V_94 . V_384 ,
F_69 ( ( T_2 ) F_79 ( V_29 -> V_94 . V_384 ) ,
V_29 -> V_96 - V_29 -> V_383 ) ) ;
}
V_29 -> V_383 = V_29 -> V_96 ;
}
static struct V_28 *
F_281 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
struct V_28 * V_60 = F_48 ( V_26 ) ;
struct V_28 * V_29 ;
if ( ! V_60 || ( V_47 && F_37 ( V_47 , V_60 ) ) )
V_60 = V_47 ;
V_29 = V_60 ;
if ( V_26 -> V_379 == V_29 ) {
struct V_28 * V_385 ;
if ( V_29 == V_47 ) {
V_385 = F_48 ( V_26 ) ;
} else {
V_385 = F_49 ( V_29 ) ;
if ( ! V_385 || ( V_47 && F_37 ( V_47 , V_385 ) ) )
V_385 = V_47 ;
}
if ( V_385 && F_282 ( V_385 , V_60 ) < 1 )
V_29 = V_385 ;
}
if ( V_26 -> V_62 && F_282 ( V_26 -> V_62 , V_60 ) < 1 )
V_29 = V_26 -> V_62 ;
if ( V_26 -> V_61 && F_282 ( V_26 -> V_61 , V_60 ) < 1 )
V_29 = V_26 -> V_61 ;
F_275 ( V_26 , V_29 ) ;
return V_29 ;
}
static void F_283 ( struct V_26 * V_26 , struct V_28 * V_348 )
{
if ( V_348 -> V_48 )
F_66 ( V_26 ) ;
F_284 ( V_26 ) ;
F_259 ( V_26 , V_348 ) ;
if ( V_348 -> V_48 ) {
F_76 ( V_26 , V_348 ) ;
F_42 ( V_26 , V_348 ) ;
F_248 ( V_348 , 0 ) ;
}
V_26 -> V_47 = NULL ;
}
static void
F_285 ( struct V_26 * V_26 , struct V_28 * V_47 , int V_386 )
{
F_66 ( V_26 ) ;
F_248 ( V_47 , V_366 ) ;
F_218 ( V_47 ) ;
#ifdef F_286
if ( V_386 ) {
F_279 ( F_17 ( V_26 ) ) ;
return;
}
if ( ! F_233 ( V_387 ) &&
F_287 ( & F_17 ( V_26 ) -> V_388 ) )
return;
#endif
if ( V_26 -> V_75 > 1 )
F_278 ( V_26 , V_47 ) ;
}
static inline bool F_288 ( void )
{
return F_289 ( & V_389 ) ;
}
void F_290 ( void )
{
F_291 ( & V_389 ) ;
}
void F_292 ( void )
{
F_293 ( & V_389 ) ;
}
static bool F_288 ( void )
{
return true ;
}
void F_290 ( void ) {}
void F_292 ( void ) {}
static inline T_2 F_294 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_295 ( void )
{
return ( T_2 ) V_390 * V_391 ;
}
void F_296 ( struct V_392 * V_393 )
{
T_2 V_92 ;
if ( V_393 -> V_394 == V_395 )
return;
V_92 = F_297 ( F_298 () ) ;
V_393 -> V_240 = V_393 -> V_394 ;
V_393 -> V_396 = V_92 + F_299 ( V_393 -> V_239 ) ;
}
static inline struct V_392 * F_300 ( struct V_325 * V_34 )
{
return & V_34 -> V_392 ;
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
if ( F_14 ( V_26 -> V_397 ) )
return V_26 -> V_398 - V_26 -> V_399 ;
return F_67 ( F_17 ( V_26 ) ) - V_26 -> V_399 ;
}
static int F_301 ( struct V_26 * V_26 )
{
struct V_325 * V_34 = V_26 -> V_34 ;
struct V_392 * V_393 = F_300 ( V_34 ) ;
T_2 V_400 = 0 , V_401 , V_402 ;
V_401 = F_295 () - V_26 -> V_403 ;
F_302 ( & V_393 -> V_257 ) ;
if ( V_393 -> V_394 == V_395 )
V_400 = V_401 ;
else {
F_303 ( V_393 ) ;
if ( V_393 -> V_240 > 0 ) {
V_400 = F_154 ( V_393 -> V_240 , V_401 ) ;
V_393 -> V_240 -= V_400 ;
V_393 -> V_404 = 0 ;
}
}
V_402 = V_393 -> V_396 ;
F_304 ( & V_393 -> V_257 ) ;
V_26 -> V_403 += V_400 ;
if ( ( T_3 ) ( V_402 - V_26 -> V_396 ) > 0 )
V_26 -> V_396 = V_402 ;
return V_26 -> V_403 > 0 ;
}
static void F_305 ( struct V_26 * V_26 )
{
struct V_392 * V_393 = F_300 ( V_26 -> V_34 ) ;
if ( F_12 ( ( T_3 ) ( F_78 ( F_17 ( V_26 ) ) - V_26 -> V_396 ) < 0 ) )
return;
if ( V_26 -> V_403 < 0 )
return;
if ( V_26 -> V_396 != V_393 -> V_396 ) {
V_26 -> V_396 += V_307 ;
} else {
V_26 -> V_403 = 0 ;
}
}
static void F_306 ( struct V_26 * V_26 , T_2 V_20 )
{
V_26 -> V_403 -= V_20 ;
F_305 ( V_26 ) ;
if ( F_12 ( V_26 -> V_403 > 0 ) )
return;
if ( ! F_301 ( V_26 ) && F_12 ( V_26 -> V_47 ) )
F_279 ( F_17 ( V_26 ) ) ;
}
static T_10
void F_74 ( struct V_26 * V_26 , T_2 V_20 )
{
if ( ! F_288 () || ! V_26 -> V_405 )
return;
F_306 ( V_26 , V_20 ) ;
}
static inline int F_307 ( struct V_26 * V_26 )
{
return F_288 () && V_26 -> V_406 ;
}
static inline int F_219 ( struct V_26 * V_26 )
{
return F_288 () && V_26 -> V_397 ;
}
static inline int F_308 ( struct V_325 * V_34 ,
int V_201 , int V_407 )
{
struct V_26 * V_408 , * V_409 ;
V_408 = V_34 -> V_26 [ V_201 ] ;
V_409 = V_34 -> V_26 [ V_407 ] ;
return F_219 ( V_408 ) ||
F_219 ( V_409 ) ;
}
static int F_309 ( struct V_325 * V_34 , void * V_410 )
{
struct V_25 * V_25 = V_410 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
V_26 -> V_397 -- ;
if ( ! V_26 -> V_397 ) {
V_26 -> V_399 += F_67 ( V_25 ) -
V_26 -> V_398 ;
}
return 0 ;
}
static int F_310 ( struct V_325 * V_34 , void * V_410 )
{
struct V_25 * V_25 = V_410 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_397 )
V_26 -> V_398 = F_67 ( V_25 ) ;
V_26 -> V_397 ++ ;
return 0 ;
}
static void F_311 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_392 * V_393 = F_300 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
long V_411 , V_412 = 1 ;
bool V_413 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
F_134 () ;
F_312 ( V_26 -> V_34 , F_310 , V_414 , ( void * ) V_25 ) ;
F_142 () ;
V_411 = V_26 -> V_415 ;
F_59 (se) {
struct V_26 * V_416 = F_23 ( V_29 ) ;
if ( ! V_29 -> V_48 )
break;
if ( V_412 )
F_276 ( V_416 , V_29 , V_117 ) ;
V_416 -> V_415 -= V_411 ;
if ( V_416 -> V_73 . V_5 )
V_412 = 0 ;
}
if ( ! V_29 )
F_313 ( V_25 , V_411 ) ;
V_26 -> V_406 = 1 ;
V_26 -> V_417 = F_78 ( V_25 ) ;
F_302 ( & V_393 -> V_257 ) ;
V_413 = F_314 ( & V_393 -> V_418 ) ;
F_28 ( & V_26 -> V_419 , & V_393 -> V_418 ) ;
if ( V_413 )
F_303 ( V_393 ) ;
F_304 ( & V_393 -> V_257 ) ;
}
void F_315 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_392 * V_393 = F_300 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
int V_420 = 1 ;
long V_411 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
V_26 -> V_406 = 0 ;
F_316 ( V_25 ) ;
F_302 ( & V_393 -> V_257 ) ;
V_393 -> V_421 += F_78 ( V_25 ) - V_26 -> V_417 ;
F_30 ( & V_26 -> V_419 ) ;
F_304 ( & V_393 -> V_257 ) ;
F_312 ( V_26 -> V_34 , V_414 , F_309 , ( void * ) V_25 ) ;
if ( ! V_26 -> V_73 . V_5 )
return;
V_411 = V_26 -> V_415 ;
F_59 (se) {
if ( V_29 -> V_48 )
V_420 = 0 ;
V_26 = F_23 ( V_29 ) ;
if ( V_420 )
F_270 ( V_26 , V_29 , V_116 ) ;
V_26 -> V_415 += V_411 ;
if ( F_307 ( V_26 ) )
break;
}
if ( ! V_29 )
F_317 ( V_25 , V_411 ) ;
if ( V_25 -> V_47 == V_25 -> V_404 && V_25 -> V_42 . V_75 )
F_279 ( V_25 ) ;
}
static T_2 F_318 ( struct V_392 * V_393 ,
T_2 V_422 , T_2 V_402 )
{
struct V_26 * V_26 ;
T_2 V_240 ;
T_2 V_423 = V_422 ;
F_134 () ;
F_319 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_369 V_370 ;
F_320 ( V_25 , & V_370 ) ;
if ( ! F_307 ( V_26 ) )
goto V_61;
V_240 = - V_26 -> V_403 + 1 ;
if ( V_240 > V_422 )
V_240 = V_422 ;
V_422 -= V_240 ;
V_26 -> V_403 += V_240 ;
V_26 -> V_396 = V_402 ;
if ( V_26 -> V_403 > 0 )
F_315 ( V_26 ) ;
V_61:
F_321 ( V_25 , & V_370 ) ;
if ( ! V_422 )
break;
}
F_142 () ;
return V_423 - V_422 ;
}
static int F_322 ( struct V_392 * V_393 , int V_424 )
{
T_2 V_240 , V_396 ;
int V_406 ;
if ( V_393 -> V_394 == V_395 )
goto V_425;
V_406 = ! F_314 ( & V_393 -> V_418 ) ;
V_393 -> V_426 += V_424 ;
if ( V_393 -> V_404 && ! V_406 )
goto V_425;
F_296 ( V_393 ) ;
if ( ! V_406 ) {
V_393 -> V_404 = 1 ;
return 0 ;
}
V_393 -> V_427 += V_424 ;
V_396 = V_393 -> V_396 ;
while ( V_406 && V_393 -> V_240 > 0 ) {
V_240 = V_393 -> V_240 ;
F_304 ( & V_393 -> V_257 ) ;
V_240 = F_318 ( V_393 , V_240 ,
V_396 ) ;
F_302 ( & V_393 -> V_257 ) ;
V_406 = ! F_314 ( & V_393 -> V_418 ) ;
V_393 -> V_240 -= F_154 ( V_240 , V_393 -> V_240 ) ;
}
V_393 -> V_404 = 0 ;
return 0 ;
V_425:
return 1 ;
}
static int F_323 ( struct V_392 * V_393 , T_2 V_428 )
{
struct V_429 * V_430 = & V_393 -> V_431 ;
T_2 V_422 ;
if ( F_324 ( V_430 ) )
return 1 ;
V_422 = F_299 ( F_325 ( V_430 ) ) ;
if ( V_422 < V_428 )
return 1 ;
return 0 ;
}
static void F_326 ( struct V_392 * V_393 )
{
T_2 V_432 = V_433 + V_434 ;
if ( F_323 ( V_393 , V_432 ) )
return;
F_327 ( & V_393 -> V_435 ,
F_328 ( V_433 ) ,
V_436 ) ;
}
static void F_329 ( struct V_26 * V_26 )
{
struct V_392 * V_393 = F_300 ( V_26 -> V_34 ) ;
T_3 V_437 = V_26 -> V_403 - V_438 ;
if ( V_437 <= 0 )
return;
F_302 ( & V_393 -> V_257 ) ;
if ( V_393 -> V_394 != V_395 &&
V_26 -> V_396 == V_393 -> V_396 ) {
V_393 -> V_240 += V_437 ;
if ( V_393 -> V_240 > F_295 () &&
! F_314 ( & V_393 -> V_418 ) )
F_326 ( V_393 ) ;
}
F_304 ( & V_393 -> V_257 ) ;
V_26 -> V_403 -= V_437 ;
}
static T_10 void F_277 ( struct V_26 * V_26 )
{
if ( ! F_288 () )
return;
if ( ! V_26 -> V_405 || V_26 -> V_75 )
return;
F_329 ( V_26 ) ;
}
static void F_330 ( struct V_392 * V_393 )
{
T_2 V_240 = 0 , V_76 = F_295 () ;
T_2 V_402 ;
F_302 ( & V_393 -> V_257 ) ;
if ( F_323 ( V_393 , V_434 ) ) {
F_304 ( & V_393 -> V_257 ) ;
return;
}
if ( V_393 -> V_394 != V_395 && V_393 -> V_240 > V_76 )
V_240 = V_393 -> V_240 ;
V_402 = V_393 -> V_396 ;
F_304 ( & V_393 -> V_257 ) ;
if ( ! V_240 )
return;
V_240 = F_318 ( V_393 , V_240 , V_402 ) ;
F_302 ( & V_393 -> V_257 ) ;
if ( V_402 == V_393 -> V_396 )
V_393 -> V_240 -= F_154 ( V_240 , V_393 -> V_240 ) ;
F_304 ( & V_393 -> V_257 ) ;
}
static void F_271 ( struct V_26 * V_26 )
{
if ( ! F_288 () )
return;
if ( ! V_26 -> V_405 || V_26 -> V_47 )
return;
if ( F_307 ( V_26 ) )
return;
F_74 ( V_26 , 0 ) ;
if ( V_26 -> V_403 <= 0 )
F_311 ( V_26 ) ;
}
static void F_331 ( struct V_325 * V_34 , int V_1 )
{
struct V_26 * V_439 , * V_26 ;
if ( ! F_288 () )
return;
if ( ! V_34 -> V_35 )
return;
V_26 = V_34 -> V_26 [ V_1 ] ;
V_439 = V_34 -> V_35 -> V_26 [ V_1 ] ;
V_26 -> V_397 = V_439 -> V_397 ;
V_26 -> V_398 = F_67 ( F_124 ( V_1 ) ) ;
}
static bool F_284 ( struct V_26 * V_26 )
{
if ( ! F_288 () )
return false ;
if ( F_12 ( ! V_26 -> V_405 || V_26 -> V_403 > 0 ) )
return false ;
if ( F_307 ( V_26 ) )
return true ;
F_311 ( V_26 ) ;
return true ;
}
static enum V_440 F_332 ( struct V_429 * V_441 )
{
struct V_392 * V_393 =
F_21 ( V_441 , struct V_392 , V_435 ) ;
F_330 ( V_393 ) ;
return V_442 ;
}
static enum V_440 F_333 ( struct V_429 * V_441 )
{
struct V_392 * V_393 =
F_21 ( V_441 , struct V_392 , V_431 ) ;
int V_424 ;
int V_404 = 0 ;
F_302 ( & V_393 -> V_257 ) ;
for (; ; ) {
V_424 = F_334 ( V_441 , V_393 -> V_239 ) ;
if ( ! V_424 )
break;
V_404 = F_322 ( V_393 , V_424 ) ;
}
if ( V_404 )
V_393 -> V_443 = 0 ;
F_304 ( & V_393 -> V_257 ) ;
return V_404 ? V_442 : V_444 ;
}
void F_335 ( struct V_392 * V_393 )
{
F_336 ( & V_393 -> V_257 ) ;
V_393 -> V_240 = 0 ;
V_393 -> V_394 = V_395 ;
V_393 -> V_239 = F_328 ( F_294 () ) ;
F_337 ( & V_393 -> V_418 ) ;
F_338 ( & V_393 -> V_431 , V_445 , V_446 ) ;
V_393 -> V_431 . V_447 = F_333 ;
F_338 ( & V_393 -> V_435 , V_445 , V_436 ) ;
V_393 -> V_435 . V_447 = F_332 ;
}
static void F_339 ( struct V_26 * V_26 )
{
V_26 -> V_405 = 0 ;
F_337 ( & V_26 -> V_419 ) ;
}
void F_303 ( struct V_392 * V_393 )
{
F_340 ( & V_393 -> V_257 ) ;
if ( ! V_393 -> V_443 ) {
V_393 -> V_443 = 1 ;
F_334 ( & V_393 -> V_431 , V_393 -> V_239 ) ;
F_341 ( & V_393 -> V_431 , V_446 ) ;
}
}
static void F_342 ( struct V_392 * V_393 )
{
if ( ! V_393 -> V_418 . V_61 )
return;
F_343 ( & V_393 -> V_431 ) ;
F_343 ( & V_393 -> V_435 ) ;
}
static void T_11 F_344 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_345 (rq, cfs_rq) {
struct V_392 * V_393 = & V_26 -> V_34 -> V_392 ;
F_302 ( & V_393 -> V_257 ) ;
V_26 -> V_405 = V_393 -> V_394 != V_395 ;
F_304 ( & V_393 -> V_257 ) ;
}
}
static void T_11 F_346 ( struct V_25 * V_25 )
{
struct V_26 * V_26 ;
F_345 (rq, cfs_rq) {
if ( ! V_26 -> V_405 )
continue;
V_26 -> V_403 = 1 ;
V_26 -> V_405 = 0 ;
if ( F_307 ( V_26 ) )
F_315 ( V_26 ) ;
}
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
return F_67 ( F_17 ( V_26 ) ) ;
}
static void F_74 ( struct V_26 * V_26 , T_2 V_20 ) {}
static bool F_284 ( struct V_26 * V_26 ) { return false ; }
static void F_271 ( struct V_26 * V_26 ) {}
static inline void F_331 ( struct V_325 * V_34 , int V_1 ) {}
static T_10 void F_277 ( struct V_26 * V_26 ) {}
static inline int F_307 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_219 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_308 ( struct V_325 * V_34 ,
int V_201 , int V_407 )
{
return 0 ;
}
void F_335 ( struct V_392 * V_393 ) {}
static void F_339 ( struct V_26 * V_26 ) {}
static inline struct V_392 * F_300 ( struct V_325 * V_34 )
{
return NULL ;
}
static inline void F_342 ( struct V_392 * V_393 ) {}
static inline void F_344 ( struct V_25 * V_25 ) {}
static inline void F_346 ( struct V_25 * V_25 ) {}
static void F_347 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_19 ( F_34 ( V_30 ) != V_25 ) ;
if ( V_25 -> V_42 . V_415 > 1 ) {
T_2 V_76 = F_58 ( V_26 , V_29 ) ;
T_2 V_448 = V_29 -> V_96 - V_29 -> V_383 ;
T_3 V_44 = V_76 - V_448 ;
if ( V_44 < 0 ) {
if ( V_25 -> V_47 == V_30 )
F_279 ( V_25 ) ;
return;
}
F_348 ( V_25 , V_44 ) ;
}
}
static void F_349 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
if ( ! F_350 ( V_25 ) || V_47 -> V_89 != & V_90 )
return;
if ( F_23 ( & V_47 -> V_29 ) -> V_75 < V_70 )
F_347 ( V_25 , V_47 ) ;
}
static inline void
F_347 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
}
static inline void F_349 ( struct V_25 * V_25 )
{
}
static void
F_351 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_110 )
F_352 ( V_25 , V_449 ) ;
F_59 (se) {
if ( V_29 -> V_48 )
break;
V_26 = F_23 ( V_29 ) ;
F_270 ( V_26 , V_29 , V_115 ) ;
if ( F_307 ( V_26 ) )
break;
V_26 -> V_415 ++ ;
V_115 = V_116 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_415 ++ ;
if ( F_307 ( V_26 ) )
break;
F_248 ( V_29 , V_366 ) ;
F_218 ( V_29 ) ;
}
if ( ! V_29 )
F_317 ( V_25 , 1 ) ;
F_349 ( V_25 ) ;
}
static void F_353 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
int V_450 = V_115 & V_117 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_276 ( V_26 , V_29 , V_115 ) ;
if ( F_307 ( V_26 ) )
break;
V_26 -> V_415 -- ;
if ( V_26 -> V_73 . V_5 ) {
V_29 = F_32 ( V_29 ) ;
if ( V_450 && V_29 && ! F_219 ( V_26 ) )
F_354 ( V_29 ) ;
break;
}
V_115 |= V_117 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_415 -- ;
if ( F_307 ( V_26 ) )
break;
F_248 ( V_29 , V_366 ) ;
F_218 ( V_29 ) ;
}
if ( ! V_29 )
F_313 ( V_25 , 1 ) ;
F_349 ( V_25 ) ;
}
static unsigned long
F_355 ( unsigned long V_73 , unsigned long V_451 , int V_452 )
{
int V_453 = 0 ;
if ( ! V_451 )
return V_73 ;
if ( V_451 >= V_454 [ V_452 ] )
return 0 ;
if ( V_452 == 1 )
return V_73 >> V_451 ;
while ( V_451 ) {
if ( V_451 % 2 )
V_73 = ( V_73 * V_455 [ V_452 ] [ V_453 ] ) >> V_456 ;
V_451 >>= 1 ;
V_453 ++ ;
}
return V_73 ;
}
static void F_356 ( struct V_25 * F_243 , unsigned long V_457 ,
unsigned long V_458 )
{
unsigned long T_11 V_459 = F_243 -> V_460 [ 0 ] ;
int V_272 , V_461 ;
F_243 -> V_462 ++ ;
F_243 -> V_460 [ 0 ] = V_457 ;
for ( V_272 = 1 , V_461 = 2 ; V_272 < V_463 ; V_272 ++ , V_461 += V_461 ) {
unsigned long V_464 , V_465 ;
V_464 = F_243 -> V_460 [ V_272 ] ;
#ifdef F_357
V_464 = F_355 ( V_464 , V_458 - 1 , V_272 ) ;
if ( V_459 ) {
V_464 -= F_355 ( V_459 , V_458 - 1 , V_272 ) ;
V_464 += V_459 ;
}
#endif
V_465 = V_457 ;
if ( V_465 > V_464 )
V_465 += V_461 - 1 ;
F_243 -> V_460 [ V_272 ] = ( V_464 * ( V_461 - 1 ) + V_465 ) >> V_272 ;
}
F_358 ( F_243 ) ;
}
static unsigned long F_125 ( const int V_1 )
{
return F_256 ( & F_124 ( V_1 ) -> V_42 ) ;
}
static void F_359 ( struct V_25 * F_243 ,
unsigned long V_466 ,
unsigned long V_73 )
{
unsigned long V_458 ;
V_458 = V_466 - F_243 -> V_467 ;
if ( V_458 ) {
F_243 -> V_467 = V_466 ;
F_356 ( F_243 , V_73 , V_458 ) ;
}
}
static void F_360 ( struct V_25 * F_243 )
{
if ( F_125 ( F_26 ( F_243 ) ) )
return;
F_359 ( F_243 , F_98 ( V_224 ) , 0 ) ;
}
void F_361 ( void )
{
struct V_25 * F_243 = F_243 () ;
F_243 -> V_460 [ 0 ] = F_125 ( F_26 ( F_243 ) ) ;
}
void F_362 ( void )
{
unsigned long V_466 = F_98 ( V_224 ) ;
struct V_25 * F_243 = F_243 () ;
unsigned long V_73 ;
struct V_369 V_370 ;
if ( V_466 == F_243 -> V_467 )
return;
V_73 = F_125 ( F_26 ( F_243 ) ) ;
F_320 ( F_243 , & V_370 ) ;
F_316 ( F_243 ) ;
F_359 ( F_243 , V_466 , V_73 ) ;
F_321 ( F_243 , & V_370 ) ;
}
static inline void F_359 ( struct V_25 * F_243 ,
unsigned long V_466 ,
unsigned long V_73 ) { }
static void F_363 ( struct V_25 * F_243 , unsigned long V_73 )
{
#ifdef F_357
F_243 -> V_467 = F_98 ( V_224 ) ;
#endif
F_356 ( F_243 , V_73 , 1 ) ;
}
void F_364 ( struct V_25 * F_243 )
{
unsigned long V_73 = F_125 ( F_26 ( F_243 ) ) ;
if ( F_365 () )
F_359 ( F_243 , F_98 ( V_224 ) , V_73 ) ;
else
F_363 ( F_243 , V_73 ) ;
}
static unsigned long F_366 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_468 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_233 ( V_469 ) )
return V_468 ;
return F_154 ( V_25 -> V_460 [ type - 1 ] , V_468 ) ;
}
static unsigned long F_367 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_468 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_233 ( V_469 ) )
return V_468 ;
return F_69 ( V_25 -> V_460 [ type - 1 ] , V_468 ) ;
}
static unsigned long F_126 ( int V_1 )
{
return F_124 ( V_1 ) -> V_470 ;
}
static unsigned long F_368 ( int V_1 )
{
return F_124 ( V_1 ) -> V_471 ;
}
static unsigned long F_369 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_75 = F_98 ( V_25 -> V_42 . V_415 ) ;
unsigned long V_82 = F_125 ( V_1 ) ;
if ( V_75 )
return V_82 / V_75 ;
return 0 ;
}
static long F_370 ( struct V_325 * V_34 , int V_1 , long V_472 , long V_473 )
{
struct V_28 * V_29 = V_34 -> V_29 [ V_1 ] ;
if ( ! V_34 -> V_35 )
return V_472 ;
F_59 (se) {
struct V_26 * V_26 = V_29 -> V_32 ;
long V_474 , V_8 = F_257 ( V_26 ) ;
V_34 = V_26 -> V_34 ;
V_474 = V_473 + F_216 ( & V_34 -> V_82 ) ;
V_474 -= V_26 -> V_328 ;
V_474 += V_8 ;
V_8 += V_472 ;
if ( V_474 > 0 && V_8 < V_474 )
V_472 = ( V_8 * ( long ) F_13 ( V_34 -> V_327 ) ) / V_474 ;
else
V_472 = F_13 ( V_34 -> V_327 ) ;
if ( V_472 < V_329 )
V_472 = V_329 ;
V_472 -= V_29 -> V_79 . V_82 ;
V_473 = 0 ;
}
return V_472 ;
}
static long F_370 ( struct V_325 * V_34 , int V_1 , long V_472 , long V_473 )
{
return V_472 ;
}
static void F_371 ( struct V_27 * V_30 )
{
if ( F_192 ( V_224 , V_172 -> V_475 + V_222 ) ) {
V_172 -> V_476 >>= 1 ;
V_172 -> V_475 = V_224 ;
}
if ( V_172 -> V_477 != V_30 ) {
V_172 -> V_477 = V_30 ;
V_172 -> V_476 ++ ;
}
}
static int F_372 ( struct V_27 * V_30 )
{
unsigned int V_478 = V_172 -> V_476 ;
unsigned int V_479 = V_30 -> V_476 ;
int V_10 = F_373 ( V_480 ) ;
if ( V_478 < V_479 )
F_132 ( V_478 , V_479 ) ;
if ( V_479 < V_10 || V_478 < V_479 * V_10 )
return 0 ;
return 1 ;
}
static int F_374 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_481 , int V_482 )
{
T_3 V_457 , V_73 ;
T_3 V_483 , V_484 ;
int V_452 , V_485 ;
struct V_325 * V_34 ;
unsigned long V_5 ;
int V_486 ;
V_452 = V_213 -> V_487 ;
V_485 = F_298 () ;
V_73 = F_366 ( V_481 , V_452 ) ;
V_457 = F_367 ( V_485 , V_452 ) ;
if ( V_482 ) {
V_34 = V_325 ( V_172 ) ;
V_5 = V_172 -> V_29 . V_79 . V_82 ;
V_457 += F_370 ( V_34 , V_485 , - V_5 , - V_5 ) ;
V_73 += F_370 ( V_34 , V_481 , 0 , - V_5 ) ;
}
V_34 = V_325 ( V_30 ) ;
V_5 = V_30 -> V_29 . V_79 . V_82 ;
V_483 = 100 ;
V_483 *= F_126 ( V_481 ) ;
V_484 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
V_484 *= F_126 ( V_485 ) ;
if ( V_457 > 0 ) {
V_483 *= V_457 +
F_370 ( V_34 , V_485 , V_5 , V_5 ) ;
V_484 *= V_73 + F_370 ( V_34 , V_481 , 0 , V_5 ) ;
}
V_486 = V_483 <= V_484 ;
F_83 ( V_30 -> V_29 . V_94 . V_488 ) ;
if ( ! V_486 )
return 0 ;
F_83 ( V_213 -> V_489 ) ;
F_83 ( V_30 -> V_29 . V_94 . V_490 ) ;
return 1 ;
}
static unsigned long F_375 ( int V_1 , struct V_27 * V_30 )
{
return F_368 ( V_1 ) - F_376 ( V_1 , V_30 ) ;
}
static struct V_491 *
F_377 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_485 , int V_492 )
{
struct V_491 * V_493 = NULL , * V_148 = V_213 -> V_494 ;
struct V_491 * V_495 = NULL ;
unsigned long V_496 = V_497 , V_498 = 0 ;
unsigned long V_499 = V_497 , V_500 = 0 ;
unsigned long V_501 = 0 , V_502 = 0 ;
int V_503 = V_213 -> V_504 ;
int V_505 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
unsigned long V_506 = F_13 ( V_74 ) *
( V_213 -> V_197 - 100 ) / 100 ;
if ( V_492 & V_507 )
V_503 = V_213 -> V_487 ;
do {
unsigned long V_73 , V_508 , V_509 ;
unsigned long V_510 , V_511 ;
int V_512 ;
int V_272 ;
if ( ! F_378 ( F_379 ( V_148 ) ,
& V_30 -> V_207 ) )
continue;
V_512 = F_137 ( V_485 ,
F_379 ( V_148 ) ) ;
V_508 = 0 ;
V_509 = 0 ;
V_511 = 0 ;
F_123 (i, sched_group_cpus(group)) {
if ( V_512 )
V_73 = F_366 ( V_272 , V_503 ) ;
else
V_73 = F_367 ( V_272 , V_503 ) ;
V_509 += V_73 ;
V_508 += F_257 ( & F_124 ( V_272 ) -> V_42 ) ;
V_510 = F_375 ( V_272 , V_30 ) ;
if ( V_510 > V_511 )
V_511 = V_510 ;
}
V_508 = ( V_508 * V_88 ) /
V_148 -> V_513 -> V_177 ;
V_509 = ( V_509 * V_88 ) /
V_148 -> V_513 -> V_177 ;
if ( V_512 ) {
V_498 = V_509 ;
V_500 = V_508 ;
V_502 = V_511 ;
} else {
if ( V_496 > ( V_509 + V_506 ) ) {
V_496 = V_509 ;
V_499 = V_508 ;
V_493 = V_148 ;
} else if ( ( V_509 < ( V_496 + V_506 ) ) &&
( 100 * V_499 > V_505 * V_508 ) ) {
V_499 = V_508 ;
V_493 = V_148 ;
}
if ( V_501 < V_511 ) {
V_501 = V_511 ;
V_495 = V_148 ;
}
}
} while ( V_148 = V_148 -> V_61 , V_148 != V_213 -> V_494 );
if ( V_492 & V_514 )
goto V_515;
if ( V_502 > F_380 ( V_30 ) / 2 &&
V_505 * V_502 > 100 * V_501 )
return NULL ;
if ( V_501 > F_380 ( V_30 ) / 2 )
return V_495 ;
V_515:
if ( ! V_493 )
return NULL ;
if ( V_496 > ( V_498 + V_506 ) )
return NULL ;
if ( ( V_498 < ( V_496 + V_506 ) ) &&
( 100 * V_500 < V_505 * V_499 ) )
return NULL ;
return V_493 ;
}
static int
F_381 ( struct V_491 * V_148 , struct V_27 * V_30 , int V_485 )
{
unsigned long V_73 , V_516 = V_497 ;
unsigned int V_517 = V_518 ;
T_2 V_519 = 0 ;
int V_520 = V_485 ;
int V_521 = - 1 ;
int V_272 ;
if ( V_148 -> F_114 == 1 )
return F_382 ( F_379 ( V_148 ) ) ;
F_383 (i, sched_group_cpus(group), &p->cpus_allowed) {
if ( F_384 ( V_272 ) ) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_522 * V_404 = F_385 ( V_25 ) ;
if ( V_404 && V_404 -> V_523 < V_517 ) {
V_517 = V_404 -> V_523 ;
V_519 = V_25 -> V_524 ;
V_521 = V_272 ;
} else if ( ( ! V_404 || V_404 -> V_523 == V_517 ) &&
V_25 -> V_524 > V_519 ) {
V_519 = V_25 -> V_524 ;
V_521 = V_272 ;
}
} else if ( V_521 == - 1 ) {
V_73 = F_125 ( V_272 ) ;
if ( V_73 < V_516 || ( V_73 == V_516 && V_272 == V_485 ) ) {
V_516 = V_73 ;
V_520 = V_272 ;
}
}
}
return V_521 != - 1 ? V_521 : V_520 ;
}
static int F_386 ( int V_331 , const struct V_525 * V_526 , int V_300 , int * V_527 )
{
int V_61 ;
V_528:
V_61 = F_387 ( F_388 ( V_526 ) , V_529 , V_331 + 1 ) ;
if ( * V_527 ) {
if ( V_61 >= V_300 )
return V_529 ;
} else {
if ( V_61 >= V_529 ) {
* V_527 = 1 ;
V_331 = - 1 ;
goto V_528;
}
}
return V_61 ;
}
static inline void F_389 ( int V_1 , int V_330 )
{
struct V_530 * V_531 ;
V_531 = F_147 ( F_148 ( V_532 , V_1 ) ) ;
if ( V_531 )
F_194 ( V_531 -> V_533 , V_330 ) ;
}
static inline bool F_390 ( int V_1 , bool V_534 )
{
struct V_530 * V_531 ;
V_531 = F_147 ( F_148 ( V_532 , V_1 ) ) ;
if ( V_531 )
return F_98 ( V_531 -> V_533 ) ;
return V_534 ;
}
void F_391 ( struct V_25 * V_25 )
{
int V_535 = F_26 ( V_25 ) ;
int V_1 ;
F_134 () ;
if ( F_390 ( V_535 , true ) )
goto V_206;
F_123 (cpu, cpu_smt_mask(core)) {
if ( V_1 == V_535 )
continue;
if ( ! F_384 ( V_1 ) )
goto V_206;
}
F_389 ( V_535 , 1 ) ;
V_206:
F_142 () ;
}
static int F_392 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_536 )
{
struct V_525 * V_9 = F_393 ( V_537 ) ;
int V_535 , V_1 , V_538 ;
if ( ! F_191 ( & V_539 ) )
return - 1 ;
if ( ! F_390 ( V_536 , false ) )
return - 1 ;
F_394 ( V_9 , F_395 ( V_213 ) , & V_30 -> V_207 ) ;
F_396 (core, cpus, target, wrap) {
bool V_404 = true ;
F_123 (cpu, cpu_smt_mask(core)) {
F_397 ( V_1 , V_9 ) ;
if ( ! F_384 ( V_1 ) )
V_404 = false ;
}
if ( V_404 )
return V_535 ;
}
F_389 ( V_536 , 0 ) ;
return - 1 ;
}
static int F_398 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_536 )
{
int V_1 ;
if ( ! F_191 ( & V_539 ) )
return - 1 ;
F_123 (cpu, cpu_smt_mask(target)) {
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_384 ( V_1 ) )
return V_1 ;
}
return - 1 ;
}
static inline int F_392 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_536 )
{
return - 1 ;
}
static inline int F_398 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_536 )
{
return - 1 ;
}
static int F_399 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_536 )
{
struct V_212 * V_540 ;
T_2 V_541 , V_542 = F_243 () -> V_542 ;
T_2 time , V_543 ;
T_3 V_44 ;
int V_1 , V_538 ;
V_540 = F_147 ( * F_400 ( & V_544 ) ) ;
if ( ! V_540 )
return - 1 ;
V_541 = V_540 -> V_545 ;
if ( F_233 ( V_546 ) && ( V_542 / 512 ) < V_541 )
return - 1 ;
time = F_401 () ;
F_396 (cpu, sched_domain_span(sd), target, wrap) {
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_384 ( V_1 ) )
break;
}
time = F_401 () - time ;
V_543 = V_540 -> V_545 ;
V_44 = ( T_3 ) ( time - V_543 ) / 8 ;
V_540 -> V_545 += V_44 ;
return V_1 ;
}
static int F_140 ( struct V_27 * V_30 , int V_348 , int V_536 )
{
struct V_212 * V_213 ;
int V_272 ;
if ( F_384 ( V_536 ) )
return V_536 ;
if ( V_348 != V_536 && F_402 ( V_348 , V_536 ) && F_384 ( V_348 ) )
return V_348 ;
V_213 = F_147 ( F_148 ( V_544 , V_536 ) ) ;
if ( ! V_213 )
return V_536 ;
V_272 = F_392 ( V_30 , V_213 , V_536 ) ;
if ( ( unsigned ) V_272 < V_529 )
return V_272 ;
V_272 = F_399 ( V_30 , V_213 , V_536 ) ;
if ( ( unsigned ) V_272 < V_529 )
return V_272 ;
V_272 = F_398 ( V_30 , V_213 , V_536 ) ;
if ( ( unsigned ) V_272 < V_529 )
return V_272 ;
return V_536 ;
}
static int F_403 ( int V_1 )
{
unsigned long V_547 = F_124 ( V_1 ) -> V_42 . V_79 . V_85 ;
unsigned long V_177 = F_368 ( V_1 ) ;
return ( V_547 >= V_177 ) ? V_177 : V_547 ;
}
static inline int F_380 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_85 ;
}
static int F_376 ( int V_1 , struct V_27 * V_30 )
{
unsigned long V_547 , V_177 ;
if ( V_1 != F_146 ( V_30 ) || ! V_30 -> V_29 . V_79 . V_80 )
return F_403 ( V_1 ) ;
V_177 = F_368 ( V_1 ) ;
V_547 = F_99 ( long , F_124 ( V_1 ) -> V_42 . V_79 . V_85 - F_380 ( V_30 ) , 0 ) ;
return ( V_547 >= V_177 ) ? V_177 : V_547 ;
}
static int F_404 ( struct V_27 * V_30 , int V_1 , int V_481 )
{
long V_548 , V_549 ;
V_548 = F_154 ( F_368 ( V_481 ) , F_368 ( V_1 ) ) ;
V_549 = F_124 ( V_1 ) -> V_550 -> V_551 ;
if ( V_549 - V_548 < V_549 > > 3 )
return 0 ;
F_254 ( & V_30 -> V_29 ) ;
return V_548 * 1024 < F_380 ( V_30 ) * V_552 ;
}
static int
F_405 ( struct V_27 * V_30 , int V_481 , int V_492 , int V_553 )
{
struct V_212 * V_554 , * V_555 = NULL , * V_213 = NULL ;
int V_1 = F_298 () ;
int V_556 = V_481 ;
int V_557 = 0 ;
int V_482 = V_553 & V_558 ;
if ( V_492 & V_507 ) {
F_371 ( V_30 ) ;
V_557 = ! F_372 ( V_30 ) && ! F_404 ( V_30 , V_1 , V_481 )
&& F_137 ( V_1 , & V_30 -> V_207 ) ;
}
F_134 () ;
F_406 (cpu, tmp) {
if ( ! ( V_554 -> V_115 & V_559 ) )
break;
if ( V_557 && ( V_554 -> V_115 & V_560 ) &&
F_137 ( V_481 , F_395 ( V_554 ) ) ) {
V_555 = V_554 ;
break;
}
if ( V_554 -> V_115 & V_492 )
V_213 = V_554 ;
else if ( ! V_557 )
break;
}
if ( V_555 ) {
V_213 = NULL ;
if ( V_1 != V_481 && F_374 ( V_555 , V_30 , V_481 , V_482 ) )
V_556 = V_1 ;
}
if ( ! V_213 ) {
if ( V_492 & V_507 )
V_556 = F_140 ( V_30 , V_481 , V_556 ) ;
} else while ( V_213 ) {
struct V_491 * V_148 ;
int V_5 ;
if ( ! ( V_213 -> V_115 & V_492 ) ) {
V_213 = V_213 -> V_561 ;
continue;
}
V_148 = F_377 ( V_213 , V_30 , V_1 , V_492 ) ;
if ( ! V_148 ) {
V_213 = V_213 -> V_561 ;
continue;
}
V_556 = F_381 ( V_148 , V_30 , V_1 ) ;
if ( V_556 == - 1 || V_556 == V_1 ) {
V_213 = V_213 -> V_561 ;
continue;
}
V_1 = V_556 ;
V_5 = V_213 -> V_562 ;
V_213 = NULL ;
F_406 (cpu, tmp) {
if ( V_5 <= V_554 -> V_562 )
break;
if ( V_554 -> V_115 & V_492 )
V_213 = V_554 ;
}
}
F_142 () ;
return V_556 ;
}
static void F_407 ( struct V_27 * V_30 )
{
if ( V_30 -> V_118 == V_563 ) {
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_51 ;
do {
V_51 = V_26 -> V_51 ;
F_234 () ;
F_36 = V_26 -> F_36 ;
} while ( F_36 != V_51 );
#else
F_36 = V_26 -> F_36 ;
#endif
V_29 -> V_43 -= F_36 ;
}
F_255 ( & V_30 -> V_29 ) ;
V_30 -> V_29 . V_79 . V_80 = 0 ;
V_30 -> V_29 . V_93 = 0 ;
}
static void F_408 ( struct V_27 * V_30 )
{
F_255 ( & V_30 -> V_29 ) ;
}
static unsigned long
F_409 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
unsigned long V_564 = V_565 ;
return F_56 ( V_564 , V_29 ) ;
}
static int
F_282 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
T_3 V_564 , V_566 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_566 <= 0 )
return - 1 ;
V_564 = F_409 ( V_47 , V_29 ) ;
if ( V_566 > V_564 )
return 1 ;
return 0 ;
}
static void F_410 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_567 == V_568 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_62 = V_29 ;
}
static void F_354 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_567 == V_568 ) )
return;
F_59 (se)
F_23 ( V_29 ) -> V_61 = V_29 ;
}
static void F_411 ( struct V_28 * V_29 )
{
F_59 (se)
F_23 ( V_29 ) -> V_379 = V_29 ;
}
static void F_412 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_553 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_28 * V_29 = & V_47 -> V_29 , * V_38 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
int V_461 = V_26 -> V_75 >= V_70 ;
int V_569 = 0 ;
if ( F_14 ( V_29 == V_38 ) )
return;
if ( F_14 ( F_219 ( F_23 ( V_38 ) ) ) )
return;
if ( F_233 ( V_570 ) && V_461 && ! ( V_553 & V_571 ) ) {
F_354 ( V_38 ) ;
V_569 = 1 ;
}
if ( F_413 ( V_47 ) )
return;
if ( F_14 ( V_47 -> V_567 == V_568 ) &&
F_12 ( V_30 -> V_567 != V_568 ) )
goto V_572;
if ( F_14 ( V_30 -> V_567 != V_573 ) || ! F_233 ( V_574 ) )
return;
F_33 ( & V_29 , & V_38 ) ;
F_66 ( F_23 ( V_29 ) ) ;
F_181 ( ! V_38 ) ;
if ( F_282 ( V_29 , V_38 ) == 1 ) {
if ( ! V_569 )
F_354 ( V_38 ) ;
goto V_572;
}
return;
V_572:
F_279 ( V_25 ) ;
if ( F_14 ( ! V_29 -> V_48 || V_47 == V_25 -> V_404 ) )
return;
if ( F_233 ( V_575 ) && V_461 && F_20 ( V_29 ) )
F_410 ( V_29 ) ;
}
static struct V_27 *
F_414 ( struct V_25 * V_25 , struct V_27 * V_348 , struct V_369 * V_370 )
{
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_28 * V_29 ;
struct V_27 * V_30 ;
int V_576 ;
V_528:
#ifdef F_415
if ( ! V_26 -> V_75 )
goto V_404;
if ( V_348 -> V_89 != & V_90 )
goto V_577;
do {
struct V_28 * V_47 = V_26 -> V_47 ;
if ( V_47 ) {
if ( V_47 -> V_48 )
F_66 ( V_26 ) ;
else
V_47 = NULL ;
if ( F_14 ( F_284 ( V_26 ) ) )
goto V_577;
}
V_29 = F_281 ( V_26 , V_47 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( V_348 != V_30 ) {
struct V_28 * V_38 = & V_348 -> V_29 ;
while ( ! ( V_26 = F_31 ( V_29 , V_38 ) ) ) {
int V_39 = V_29 -> V_41 ;
int V_40 = V_38 -> V_41 ;
if ( V_39 <= V_40 ) {
F_283 ( F_23 ( V_38 ) , V_38 ) ;
V_38 = F_32 ( V_38 ) ;
}
if ( V_39 >= V_40 ) {
F_280 ( F_23 ( V_29 ) , V_29 ) ;
V_29 = F_32 ( V_29 ) ;
}
}
F_283 ( V_26 , V_38 ) ;
F_280 ( V_26 , V_29 ) ;
}
if ( F_350 ( V_25 ) )
F_347 ( V_25 , V_30 ) ;
return V_30 ;
V_577:
V_26 = & V_25 -> V_42 ;
#endif
if ( ! V_26 -> V_75 )
goto V_404;
F_416 ( V_25 , V_348 ) ;
do {
V_29 = F_281 ( V_26 , NULL ) ;
F_280 ( V_26 , V_29 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( F_350 ( V_25 ) )
F_347 ( V_25 , V_30 ) ;
return V_30 ;
V_404:
V_576 = F_258 ( V_25 , V_370 ) ;
if ( V_576 < 0 )
return V_578 ;
if ( V_576 > 0 )
goto V_528;
return NULL ;
}
static void F_417 ( struct V_25 * V_25 , struct V_27 * V_348 )
{
struct V_28 * V_29 = & V_348 -> V_29 ;
struct V_26 * V_26 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_283 ( V_26 , V_29 ) ;
}
}
static void F_418 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
struct V_28 * V_29 = & V_47 -> V_29 ;
if ( F_14 ( V_25 -> V_75 == 1 ) )
return;
F_275 ( V_26 , V_29 ) ;
if ( V_47 -> V_567 != V_579 ) {
F_316 ( V_25 ) ;
F_66 ( V_26 ) ;
F_419 ( V_25 , true ) ;
}
F_411 ( V_29 ) ;
}
static bool F_420 ( struct V_25 * V_25 , struct V_27 * V_30 , bool V_572 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( ! V_29 -> V_48 || F_219 ( F_23 ( V_29 ) ) )
return false ;
F_354 ( V_29 ) ;
F_418 ( V_25 ) ;
return true ;
}
static int F_421 ( struct V_27 * V_30 , struct V_580 * V_182 )
{
T_3 V_44 ;
F_340 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_30 -> V_89 != & V_90 )
return 0 ;
if ( F_14 ( V_30 -> V_567 == V_568 ) )
return 0 ;
if ( F_233 ( V_581 ) && V_182 -> V_202 -> V_75 &&
( & V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_61 ||
& V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_62 ) )
return 1 ;
if ( V_582 == - 1 )
return 1 ;
if ( V_582 == 0 )
return 0 ;
V_44 = F_67 ( V_182 -> V_200 ) - V_30 -> V_29 . V_93 ;
return V_44 < ( T_3 ) V_582 ;
}
static int F_422 ( struct V_27 * V_30 , struct V_580 * V_182 )
{
struct V_137 * V_137 = F_147 ( V_30 -> V_137 ) ;
unsigned long V_583 , V_584 ;
int V_167 , V_169 ;
if ( ! F_191 ( & V_286 ) )
return - 1 ;
if ( ! V_30 -> V_145 || ! ( V_182 -> V_213 -> V_115 & V_585 ) )
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
V_583 = F_107 ( V_30 , V_167 ) ;
V_584 = F_107 ( V_30 , V_169 ) ;
} else {
V_583 = F_106 ( V_30 , V_167 ) ;
V_584 = F_106 ( V_30 , V_169 ) ;
}
return V_584 < V_583 ;
}
static inline int F_422 ( struct V_27 * V_30 ,
struct V_580 * V_182 )
{
return - 1 ;
}
static
int F_423 ( struct V_27 * V_30 , struct V_580 * V_182 )
{
int V_586 ;
F_340 ( & V_182 -> V_200 -> V_257 ) ;
if ( F_308 ( V_325 ( V_30 ) , V_182 -> V_201 , V_182 -> V_168 ) )
return 0 ;
if ( ! F_137 ( V_182 -> V_168 , & V_30 -> V_207 ) ) {
int V_1 ;
F_83 ( V_30 -> V_29 . V_94 . V_587 ) ;
V_182 -> V_115 |= V_588 ;
if ( ! V_182 -> V_589 || ( V_182 -> V_115 & V_590 ) )
return 0 ;
F_383 (cpu, env->dst_grpmask, env->cpus) {
if ( F_137 ( V_1 , & V_30 -> V_207 ) ) {
V_182 -> V_115 |= V_590 ;
V_182 -> V_591 = V_1 ;
break;
}
}
return 0 ;
}
V_182 -> V_115 &= ~ V_592 ;
if ( F_424 ( V_182 -> V_200 , V_30 ) ) {
F_83 ( V_30 -> V_29 . V_94 . V_593 ) ;
return 0 ;
}
V_586 = F_422 ( V_30 , V_182 ) ;
if ( V_586 == - 1 )
V_586 = F_421 ( V_30 , V_182 ) ;
if ( V_586 <= 0 ||
V_182 -> V_213 -> V_594 > V_182 -> V_213 -> V_595 ) {
if ( V_586 == 1 ) {
F_83 ( V_182 -> V_213 -> V_596 [ V_182 -> V_404 ] ) ;
F_83 ( V_30 -> V_29 . V_94 . V_597 ) ;
}
return 1 ;
}
F_83 ( V_30 -> V_29 . V_94 . V_598 ) ;
return 0 ;
}
static void F_425 ( struct V_27 * V_30 , struct V_580 * V_182 )
{
F_340 ( & V_182 -> V_200 -> V_257 ) ;
V_30 -> V_48 = V_599 ;
F_426 ( V_182 -> V_200 , V_30 , V_600 ) ;
F_427 ( V_30 , V_182 -> V_168 ) ;
}
static struct V_27 * F_428 ( struct V_580 * V_182 )
{
struct V_27 * V_30 , * V_331 ;
F_340 ( & V_182 -> V_200 -> V_257 ) ;
F_429 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_423 ( V_30 , V_182 ) )
continue;
F_425 ( V_30 , V_182 ) ;
F_83 ( V_182 -> V_213 -> V_601 [ V_182 -> V_404 ] ) ;
return V_30 ;
}
return NULL ;
}
static int F_430 ( struct V_580 * V_182 )
{
struct V_602 * V_603 = & V_182 -> V_200 -> V_324 ;
struct V_27 * V_30 ;
unsigned long V_73 ;
int V_604 = 0 ;
F_340 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_182 -> V_506 <= 0 )
return 0 ;
while ( ! F_314 ( V_603 ) ) {
if ( V_182 -> V_404 != V_605 && V_182 -> V_200 -> V_75 <= 1 )
break;
V_30 = F_431 ( V_603 , struct V_27 , V_29 . V_323 ) ;
V_182 -> V_606 ++ ;
if ( V_182 -> V_606 > V_182 -> V_607 )
break;
if ( V_182 -> V_606 > V_182 -> V_608 ) {
V_182 -> V_608 += V_609 ;
V_182 -> V_115 |= V_610 ;
break;
}
if ( ! F_423 ( V_30 , V_182 ) )
goto V_61;
V_73 = F_138 ( V_30 ) ;
if ( F_233 ( V_611 ) && V_73 < 16 && ! V_182 -> V_213 -> V_594 )
goto V_61;
if ( ( V_73 / 2 ) > V_182 -> V_506 )
goto V_61;
F_425 ( V_30 , V_182 ) ;
F_212 ( & V_30 -> V_29 . V_323 , & V_182 -> V_603 ) ;
V_604 ++ ;
V_182 -> V_506 -= V_73 ;
#ifdef F_432
if ( V_182 -> V_404 == V_612 )
break;
#endif
if ( V_182 -> V_506 <= 0 )
break;
continue;
V_61:
F_433 ( & V_30 -> V_29 . V_323 , V_603 ) ;
}
F_70 ( V_182 -> V_213 -> V_601 [ V_182 -> V_404 ] , V_604 ) ;
return V_604 ;
}
static void F_434 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_340 ( & V_25 -> V_257 ) ;
F_181 ( F_34 ( V_30 ) != V_25 ) ;
F_435 ( V_25 , V_30 , V_613 ) ;
V_30 -> V_48 = V_614 ;
F_436 ( V_25 , V_30 , 0 ) ;
}
static void F_437 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_369 V_370 ;
F_320 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
F_434 ( V_25 , V_30 ) ;
F_321 ( V_25 , & V_370 ) ;
}
static void F_438 ( struct V_580 * V_182 )
{
struct V_602 * V_603 = & V_182 -> V_603 ;
struct V_27 * V_30 ;
struct V_369 V_370 ;
F_320 ( V_182 -> V_202 , & V_370 ) ;
F_316 ( V_182 -> V_202 ) ;
while ( ! F_314 ( V_603 ) ) {
V_30 = F_431 ( V_603 , struct V_27 , V_29 . V_323 ) ;
F_214 ( & V_30 -> V_29 . V_323 ) ;
F_434 ( V_182 -> V_202 , V_30 ) ;
}
F_321 ( V_182 -> V_202 , & V_370 ) ;
}
static void F_439 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 ;
struct V_369 V_370 ;
F_440 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
F_345 (rq, cfs_rq) {
struct V_28 * V_29 ;
if ( F_219 ( V_26 ) )
continue;
if ( F_245 ( F_63 ( V_26 ) , V_26 , true ) )
F_65 ( V_26 , 0 ) ;
V_29 = V_26 -> V_34 -> V_29 [ V_1 ] ;
if ( V_29 && ! F_241 ( V_29 ) )
F_248 ( V_29 , 0 ) ;
}
F_441 ( V_25 , & V_370 ) ;
}
static void F_442 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_28 * V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
unsigned long V_92 = V_224 ;
unsigned long V_73 ;
if ( V_26 -> V_615 == V_92 )
return;
V_26 -> V_616 = NULL ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_616 = V_29 ;
if ( V_26 -> V_615 == V_92 )
break;
}
if ( ! V_29 ) {
V_26 -> V_617 = F_257 ( V_26 ) ;
V_26 -> V_615 = V_92 ;
}
while ( ( V_29 = V_26 -> V_616 ) != NULL ) {
V_73 = V_26 -> V_617 ;
V_73 = F_443 ( V_73 * V_29 -> V_79 . V_82 ,
F_257 ( V_26 ) + 1 ) ;
V_26 = F_24 ( V_29 ) ;
V_26 -> V_617 = V_73 ;
V_26 -> V_615 = V_92 ;
}
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
struct V_26 * V_26 = F_22 ( V_30 ) ;
F_442 ( V_26 ) ;
return F_443 ( V_30 -> V_29 . V_79 . V_82 * V_26 -> V_617 ,
F_257 ( V_26 ) + 1 ) ;
}
static inline void F_439 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_369 V_370 ;
F_440 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
F_245 ( F_63 ( V_26 ) , V_26 , true ) ;
F_441 ( V_25 , & V_370 ) ;
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_82 ;
}
static inline void F_444 ( struct V_618 * V_531 )
{
* V_531 = (struct V_618 ) {
. V_619 = NULL ,
. V_233 = NULL ,
. V_620 = 0UL ,
. V_621 = 0UL ,
. V_622 = {
. V_508 = 0UL ,
. V_623 = 0 ,
. V_624 = V_625 ,
} ,
} ;
}
static inline int F_445 ( struct V_212 * V_213 ,
enum V_626 V_404 )
{
int V_503 ;
switch ( V_404 ) {
case V_605 :
V_503 = V_213 -> V_627 ;
break;
case V_612 :
V_503 = V_213 -> V_628 ;
break;
default:
V_503 = V_213 -> V_629 ;
break;
}
return V_503 ;
}
static unsigned long F_446 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
T_2 V_468 , V_630 , V_631 , V_79 ;
T_3 V_44 ;
V_631 = F_98 ( V_25 -> V_631 ) ;
V_79 = F_98 ( V_25 -> V_632 ) ;
V_44 = F_447 ( V_25 ) - V_631 ;
if ( F_14 ( V_44 < 0 ) )
V_44 = 0 ;
V_468 = F_448 () + V_44 ;
V_630 = F_227 ( V_79 , V_468 ) ;
if ( F_12 ( V_630 < V_88 ) )
return V_88 - V_630 ;
return 1 ;
}
static void F_449 ( struct V_212 * V_213 , int V_1 )
{
unsigned long V_177 = F_224 ( V_213 , V_1 ) ;
struct V_491 * V_633 = V_213 -> V_494 ;
F_124 ( V_1 ) -> V_471 = V_177 ;
V_177 *= F_446 ( V_1 ) ;
V_177 >>= V_634 ;
if ( ! V_177 )
V_177 = 1 ;
F_124 ( V_1 ) -> V_470 = V_177 ;
V_633 -> V_513 -> V_177 = V_177 ;
V_633 -> V_513 -> V_635 = V_177 ;
}
void F_450 ( struct V_212 * V_213 , int V_1 )
{
struct V_212 * V_561 = V_213 -> V_561 ;
struct V_491 * V_148 , * V_633 = V_213 -> V_494 ;
unsigned long V_177 , V_635 ;
unsigned long V_221 ;
V_221 = F_155 ( V_213 -> V_636 ) ;
V_221 = F_158 ( V_221 , 1UL , V_637 ) ;
V_633 -> V_513 -> V_638 = V_224 + V_221 ;
if ( ! V_561 ) {
F_449 ( V_213 , V_1 ) ;
return;
}
V_177 = 0 ;
V_635 = V_497 ;
if ( V_561 -> V_115 & V_639 ) {
F_123 (cpu, sched_group_cpus(sdg)) {
struct V_640 * V_513 ;
struct V_25 * V_25 = F_124 ( V_1 ) ;
if ( F_14 ( ! V_25 -> V_213 ) ) {
V_177 += F_126 ( V_1 ) ;
} else {
V_513 = V_25 -> V_213 -> V_494 -> V_513 ;
V_177 += V_513 -> V_177 ;
}
V_635 = F_154 ( V_177 , V_635 ) ;
}
} else {
V_148 = V_561 -> V_494 ;
do {
struct V_640 * V_513 = V_148 -> V_513 ;
V_177 += V_513 -> V_177 ;
V_635 = F_154 ( V_513 -> V_635 , V_635 ) ;
V_148 = V_148 -> V_61 ;
} while ( V_148 != V_561 -> V_494 );
}
V_633 -> V_513 -> V_177 = V_177 ;
V_633 -> V_513 -> V_635 = V_635 ;
}
static inline int
F_451 ( struct V_25 * V_25 , struct V_212 * V_213 )
{
return ( ( V_25 -> V_470 * V_213 -> V_197 ) <
( V_25 -> V_471 * 100 ) ) ;
}
static inline int F_452 ( struct V_491 * V_148 )
{
return V_148 -> V_513 -> V_506 ;
}
static inline bool
F_453 ( struct V_580 * V_182 , struct V_641 * V_642 )
{
if ( V_642 -> V_623 < V_642 -> F_114 )
return true ;
if ( ( V_642 -> V_643 * 100 ) >
( V_642 -> V_644 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_454 ( struct V_580 * V_182 , struct V_641 * V_642 )
{
if ( V_642 -> V_623 <= V_642 -> F_114 )
return false ;
if ( ( V_642 -> V_643 * 100 ) <
( V_642 -> V_644 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_455 ( struct V_491 * V_645 , struct V_491 * V_646 )
{
return V_645 -> V_513 -> V_635 * V_552 <
V_646 -> V_513 -> V_635 * 1024 ;
}
static inline enum
V_624 F_456 ( struct V_491 * V_148 ,
struct V_641 * V_642 )
{
if ( V_642 -> V_647 )
return V_648 ;
if ( F_452 ( V_148 ) )
return V_649 ;
return V_625 ;
}
static inline void F_457 ( struct V_580 * V_182 ,
struct V_491 * V_148 , int V_503 ,
int V_512 , struct V_641 * V_642 ,
bool * V_650 )
{
unsigned long V_73 ;
int V_272 , V_75 ;
memset ( V_642 , 0 , sizeof( * V_642 ) ) ;
F_383 (i, sched_group_cpus(group), env->cpus) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
if ( V_512 )
V_73 = F_367 ( V_272 , V_503 ) ;
else
V_73 = F_366 ( V_272 , V_503 ) ;
V_642 -> V_651 += V_73 ;
V_642 -> V_644 += F_403 ( V_272 ) ;
V_642 -> V_623 += V_25 -> V_42 . V_415 ;
V_75 = V_25 -> V_75 ;
if ( V_75 > 1 )
* V_650 = true ;
#ifdef F_458
V_642 -> V_134 += V_25 -> V_134 ;
V_642 -> V_136 += V_25 -> V_136 ;
#endif
V_642 -> V_652 += F_125 ( V_272 ) ;
if ( ! V_75 && F_384 ( V_272 ) )
V_642 -> V_653 ++ ;
}
V_642 -> V_643 = V_148 -> V_513 -> V_177 ;
V_642 -> V_508 = ( V_642 -> V_651 * V_88 ) / V_642 -> V_643 ;
if ( V_642 -> V_623 )
V_642 -> V_654 = V_642 -> V_652 / V_642 -> V_623 ;
V_642 -> F_114 = V_148 -> F_114 ;
V_642 -> V_647 = F_454 ( V_182 , V_642 ) ;
V_642 -> V_624 = F_456 ( V_148 , V_642 ) ;
}
static bool F_459 ( struct V_580 * V_182 ,
struct V_618 * V_531 ,
struct V_491 * V_645 ,
struct V_641 * V_642 )
{
struct V_641 * V_619 = & V_531 -> V_622 ;
if ( V_642 -> V_624 > V_619 -> V_624 )
return true ;
if ( V_642 -> V_624 < V_619 -> V_624 )
return false ;
if ( V_642 -> V_508 <= V_619 -> V_508 )
return false ;
if ( ! ( V_182 -> V_213 -> V_115 & V_655 ) )
goto V_656;
if ( V_642 -> V_623 <= V_642 -> F_114 &&
F_455 ( V_531 -> V_233 , V_645 ) )
return false ;
V_656:
if ( ! ( V_182 -> V_213 -> V_115 & V_657 ) )
return true ;
if ( V_182 -> V_404 == V_605 )
return true ;
if ( V_642 -> V_623 &&
F_460 ( V_182 -> V_168 , V_645 -> V_658 ) ) {
if ( ! V_531 -> V_619 )
return true ;
if ( F_460 ( V_531 -> V_619 -> V_658 ,
V_645 -> V_658 ) )
return true ;
}
return false ;
}
static inline enum V_659 F_461 ( struct V_641 * V_642 )
{
if ( V_642 -> V_623 > V_642 -> V_134 )
return V_660 ;
if ( V_642 -> V_623 > V_642 -> V_136 )
return V_231 ;
return V_661 ;
}
static inline enum V_659 F_462 ( struct V_25 * V_25 )
{
if ( V_25 -> V_75 > V_25 -> V_134 )
return V_660 ;
if ( V_25 -> V_75 > V_25 -> V_136 )
return V_231 ;
return V_661 ;
}
static inline enum V_659 F_461 ( struct V_641 * V_642 )
{
return V_661 ;
}
static inline enum V_659 F_462 ( struct V_25 * V_25 )
{
return V_660 ;
}
static inline void F_463 ( struct V_580 * V_182 , struct V_618 * V_531 )
{
struct V_212 * V_561 = V_182 -> V_213 -> V_561 ;
struct V_491 * V_645 = V_182 -> V_213 -> V_494 ;
struct V_641 * V_233 = & V_531 -> V_662 ;
struct V_641 V_663 ;
int V_503 , V_664 = 0 ;
bool V_650 = false ;
if ( V_561 && V_561 -> V_115 & V_665 )
V_664 = 1 ;
V_503 = F_445 ( V_182 -> V_213 , V_182 -> V_404 ) ;
do {
struct V_641 * V_642 = & V_663 ;
int V_512 ;
V_512 = F_137 ( V_182 -> V_168 , F_379 ( V_645 ) ) ;
if ( V_512 ) {
V_531 -> V_233 = V_645 ;
V_642 = V_233 ;
if ( V_182 -> V_404 != V_612 ||
F_464 ( V_224 , V_645 -> V_513 -> V_638 ) )
F_450 ( V_182 -> V_213 , V_182 -> V_168 ) ;
}
F_457 ( V_182 , V_645 , V_503 , V_512 , V_642 ,
& V_650 ) ;
if ( V_512 )
goto V_666;
if ( V_664 && V_531 -> V_233 &&
F_453 ( V_182 , V_233 ) &&
( V_642 -> V_623 > V_233 -> V_623 + 1 ) ) {
V_642 -> V_647 = 1 ;
V_642 -> V_624 = F_456 ( V_645 , V_642 ) ;
}
if ( F_459 ( V_182 , V_531 , V_645 , V_642 ) ) {
V_531 -> V_619 = V_645 ;
V_531 -> V_622 = * V_642 ;
}
V_666:
V_531 -> V_620 += V_642 -> V_651 ;
V_531 -> V_621 += V_642 -> V_643 ;
V_645 = V_645 -> V_61 ;
} while ( V_645 != V_182 -> V_213 -> V_494 );
if ( V_182 -> V_213 -> V_115 & V_585 )
V_182 -> V_659 = F_461 ( & V_531 -> V_622 ) ;
if ( ! V_182 -> V_213 -> V_35 ) {
if ( V_182 -> V_202 -> V_550 -> V_650 != V_650 )
V_182 -> V_202 -> V_550 -> V_650 = V_650 ;
}
}
static int F_465 ( struct V_580 * V_182 , struct V_618 * V_531 )
{
int V_667 ;
if ( ! ( V_182 -> V_213 -> V_115 & V_657 ) )
return 0 ;
if ( V_182 -> V_404 == V_605 )
return 0 ;
if ( ! V_531 -> V_619 )
return 0 ;
V_667 = V_531 -> V_619 -> V_658 ;
if ( F_460 ( V_667 , V_182 -> V_168 ) )
return 0 ;
V_182 -> V_506 = F_127 (
V_531 -> V_622 . V_508 * V_531 -> V_622 . V_643 ,
V_88 ) ;
return 1 ;
}
static inline
void F_466 ( struct V_580 * V_182 , struct V_618 * V_531 )
{
unsigned long V_554 , V_668 = 0 , V_669 = 0 ;
unsigned int V_670 = 2 ;
unsigned long V_671 ;
struct V_641 * V_233 , * V_619 ;
V_233 = & V_531 -> V_662 ;
V_619 = & V_531 -> V_622 ;
if ( ! V_233 -> V_623 )
V_233 -> V_654 = F_369 ( V_182 -> V_168 ) ;
else if ( V_619 -> V_654 > V_233 -> V_654 )
V_670 = 1 ;
V_671 =
( V_619 -> V_654 * V_88 ) /
V_619 -> V_643 ;
if ( V_619 -> V_508 + V_671 >=
V_233 -> V_508 + ( V_671 * V_670 ) ) {
V_182 -> V_506 = V_619 -> V_654 ;
return;
}
V_668 += V_619 -> V_643 *
F_154 ( V_619 -> V_654 , V_619 -> V_508 ) ;
V_668 += V_233 -> V_643 *
F_154 ( V_233 -> V_654 , V_233 -> V_508 ) ;
V_668 /= V_88 ;
if ( V_619 -> V_508 > V_671 ) {
V_669 += V_619 -> V_643 *
F_154 ( V_619 -> V_654 ,
V_619 -> V_508 - V_671 ) ;
}
if ( V_619 -> V_508 * V_619 -> V_643 <
V_619 -> V_654 * V_88 ) {
V_554 = ( V_619 -> V_508 * V_619 -> V_643 ) /
V_233 -> V_643 ;
} else {
V_554 = ( V_619 -> V_654 * V_88 ) /
V_233 -> V_643 ;
}
V_669 += V_233 -> V_643 *
F_154 ( V_233 -> V_654 , V_233 -> V_508 + V_554 ) ;
V_669 /= V_88 ;
if ( V_669 > V_668 )
V_182 -> V_506 = V_619 -> V_654 ;
}
static inline void F_467 ( struct V_580 * V_182 , struct V_618 * V_531 )
{
unsigned long V_672 , V_673 = ~ 0UL ;
struct V_641 * V_233 , * V_619 ;
V_233 = & V_531 -> V_662 ;
V_619 = & V_531 -> V_622 ;
if ( V_619 -> V_624 == V_649 ) {
V_619 -> V_654 =
F_154 ( V_619 -> V_654 , V_531 -> V_508 ) ;
}
if ( V_619 -> V_508 <= V_531 -> V_508 ||
V_233 -> V_508 >= V_531 -> V_508 ) {
V_182 -> V_506 = 0 ;
return F_466 ( V_182 , V_531 ) ;
}
if ( V_619 -> V_624 == V_648 &&
V_233 -> V_624 == V_648 ) {
V_673 = V_619 -> V_623 * V_88 ;
if ( V_673 > V_619 -> V_643 ) {
V_673 -= V_619 -> V_643 ;
V_673 *= F_13 ( V_74 ) ;
V_673 /= V_619 -> V_643 ;
} else
V_673 = ~ 0UL ;
}
V_672 = F_154 ( V_619 -> V_508 - V_531 -> V_508 , V_673 ) ;
V_182 -> V_506 = F_154 (
V_672 * V_619 -> V_643 ,
( V_531 -> V_508 - V_233 -> V_508 ) * V_233 -> V_643
) / V_88 ;
if ( V_182 -> V_506 < V_619 -> V_654 )
return F_466 ( V_182 , V_531 ) ;
}
static struct V_491 * F_468 ( struct V_580 * V_182 )
{
struct V_641 * V_233 , * V_619 ;
struct V_618 V_531 ;
F_444 ( & V_531 ) ;
F_463 ( V_182 , & V_531 ) ;
V_233 = & V_531 . V_662 ;
V_619 = & V_531 . V_622 ;
if ( F_465 ( V_182 , & V_531 ) )
return V_531 . V_619 ;
if ( ! V_531 . V_619 || V_619 -> V_623 == 0 )
goto V_674;
V_531 . V_508 = ( V_88 * V_531 . V_620 )
/ V_531 . V_621 ;
if ( V_619 -> V_624 == V_649 )
goto V_675;
if ( V_182 -> V_404 == V_612 && F_453 ( V_182 , V_233 ) &&
V_619 -> V_647 )
goto V_675;
if ( V_233 -> V_508 >= V_619 -> V_508 )
goto V_674;
if ( V_233 -> V_508 >= V_531 . V_508 )
goto V_674;
if ( V_182 -> V_404 == V_676 ) {
if ( ( V_619 -> V_624 != V_648 ) &&
( V_233 -> V_653 <= ( V_619 -> V_653 + 1 ) ) )
goto V_674;
} else {
if ( 100 * V_619 -> V_508 <=
V_182 -> V_213 -> V_197 * V_233 -> V_508 )
goto V_674;
}
V_675:
F_467 ( V_182 , & V_531 ) ;
return V_531 . V_619 ;
V_674:
V_182 -> V_506 = 0 ;
return NULL ;
}
static struct V_25 * F_469 ( struct V_580 * V_182 ,
struct V_491 * V_148 )
{
struct V_25 * V_619 = NULL , * V_25 ;
unsigned long V_677 = 0 , V_678 = 1 ;
int V_272 ;
F_383 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_177 , V_472 ;
enum V_659 V_679 ;
V_25 = F_124 ( V_272 ) ;
V_679 = F_462 ( V_25 ) ;
if ( V_679 > V_182 -> V_659 )
continue;
V_177 = F_126 ( V_272 ) ;
V_472 = F_125 ( V_272 ) ;
if ( V_25 -> V_75 == 1 && V_472 > V_182 -> V_506 &&
! F_451 ( V_25 , V_182 -> V_213 ) )
continue;
if ( V_472 * V_678 > V_677 * V_177 ) {
V_677 = V_472 ;
V_678 = V_177 ;
V_619 = V_25 ;
}
}
return V_619 ;
}
static int F_470 ( struct V_580 * V_182 )
{
struct V_212 * V_213 = V_182 -> V_213 ;
if ( V_182 -> V_404 == V_612 ) {
if ( ( V_213 -> V_115 & V_657 ) &&
F_460 ( V_182 -> V_168 , V_182 -> V_201 ) )
return 1 ;
}
if ( ( V_182 -> V_404 != V_605 ) &&
( V_182 -> V_200 -> V_42 . V_415 == 1 ) ) {
if ( ( F_451 ( V_182 -> V_200 , V_213 ) ) &&
( F_126 ( V_182 -> V_201 ) * V_213 -> V_197 < F_126 ( V_182 -> V_168 ) * 100 ) )
return 1 ;
}
return F_14 ( V_213 -> V_594 > V_213 -> V_595 + 2 ) ;
}
static int F_471 ( struct V_580 * V_182 )
{
struct V_491 * V_645 = V_182 -> V_213 -> V_494 ;
struct V_525 * V_680 , * V_681 ;
int V_1 , V_682 = - 1 ;
if ( V_182 -> V_404 == V_612 )
return 1 ;
V_680 = F_379 ( V_645 ) ;
V_681 = F_472 ( V_645 ) ;
F_383 (cpu, sg_cpus, env->cpus) {
if ( ! F_137 ( V_1 , V_681 ) || ! F_384 ( V_1 ) )
continue;
V_682 = V_1 ;
break;
}
if ( V_682 == - 1 )
V_682 = F_473 ( V_645 ) ;
return V_682 == V_182 -> V_168 ;
}
static int F_474 ( int V_485 , struct V_25 * F_243 ,
struct V_212 * V_213 , enum V_626 V_404 ,
int * V_683 )
{
int V_684 , V_685 , V_686 = 0 ;
struct V_212 * V_687 = V_213 -> V_35 ;
struct V_491 * V_148 ;
struct V_25 * V_619 ;
struct V_369 V_370 ;
struct V_525 * V_9 = F_393 ( V_688 ) ;
struct V_580 V_182 = {
. V_213 = V_213 ,
. V_168 = V_485 ,
. V_202 = F_243 ,
. V_589 = F_379 ( V_213 -> V_494 ) ,
. V_404 = V_404 ,
. V_608 = V_609 ,
. V_9 = V_9 ,
. V_659 = V_661 ,
. V_603 = F_475 ( V_182 . V_603 ) ,
} ;
if ( V_404 == V_612 )
V_182 . V_589 = NULL ;
F_476 ( V_9 , V_689 ) ;
F_83 ( V_213 -> V_690 [ V_404 ] ) ;
V_691:
if ( ! F_471 ( & V_182 ) ) {
* V_683 = 0 ;
goto V_674;
}
V_148 = F_468 ( & V_182 ) ;
if ( ! V_148 ) {
F_83 ( V_213 -> V_692 [ V_404 ] ) ;
goto V_674;
}
V_619 = F_469 ( & V_182 , V_148 ) ;
if ( ! V_619 ) {
F_83 ( V_213 -> V_693 [ V_404 ] ) ;
goto V_674;
}
F_181 ( V_619 == V_182 . V_202 ) ;
F_70 ( V_213 -> V_694 [ V_404 ] , V_182 . V_506 ) ;
V_182 . V_201 = V_619 -> V_1 ;
V_182 . V_200 = V_619 ;
V_684 = 0 ;
if ( V_619 -> V_75 > 1 ) {
V_182 . V_115 |= V_592 ;
V_182 . V_607 = F_154 ( V_695 , V_619 -> V_75 ) ;
V_696:
F_440 ( V_619 , & V_370 ) ;
F_316 ( V_619 ) ;
V_685 = F_430 ( & V_182 ) ;
F_321 ( V_619 , & V_370 ) ;
if ( V_685 ) {
F_438 ( & V_182 ) ;
V_684 += V_685 ;
}
F_477 ( V_370 . V_115 ) ;
if ( V_182 . V_115 & V_610 ) {
V_182 . V_115 &= ~ V_610 ;
goto V_696;
}
if ( ( V_182 . V_115 & V_590 ) && V_182 . V_506 > 0 ) {
F_397 ( V_182 . V_168 , V_182 . V_9 ) ;
V_182 . V_202 = F_124 ( V_182 . V_591 ) ;
V_182 . V_168 = V_182 . V_591 ;
V_182 . V_115 &= ~ V_590 ;
V_182 . V_606 = 0 ;
V_182 . V_608 = V_609 ;
goto V_696;
}
if ( V_687 ) {
int * V_697 = & V_687 -> V_494 -> V_513 -> V_506 ;
if ( ( V_182 . V_115 & V_588 ) && V_182 . V_506 > 0 )
* V_697 = 1 ;
}
if ( F_14 ( V_182 . V_115 & V_592 ) ) {
F_397 ( F_26 ( V_619 ) , V_9 ) ;
if ( ! F_478 ( V_9 ) ) {
V_182 . V_606 = 0 ;
V_182 . V_608 = V_609 ;
goto V_691;
}
goto V_698;
}
}
if ( ! V_684 ) {
F_83 ( V_213 -> V_699 [ V_404 ] ) ;
if ( V_404 != V_612 )
V_213 -> V_594 ++ ;
if ( F_470 ( & V_182 ) ) {
unsigned long V_115 ;
F_479 ( & V_619 -> V_257 , V_115 ) ;
if ( ! F_137 ( V_485 , & V_619 -> V_47 -> V_207 ) ) {
F_480 ( & V_619 -> V_257 ,
V_115 ) ;
V_182 . V_115 |= V_592 ;
goto V_700;
}
if ( ! V_619 -> V_686 ) {
V_619 -> V_686 = 1 ;
V_619 -> V_701 = V_485 ;
V_686 = 1 ;
}
F_480 ( & V_619 -> V_257 , V_115 ) ;
if ( V_686 ) {
F_481 ( F_26 ( V_619 ) ,
V_702 , V_619 ,
& V_619 -> V_703 ) ;
}
V_213 -> V_594 = V_213 -> V_595 + 1 ;
}
} else
V_213 -> V_594 = 0 ;
if ( F_12 ( ! V_686 ) ) {
V_213 -> V_636 = V_213 -> V_704 ;
} else {
if ( V_213 -> V_636 < V_213 -> V_705 )
V_213 -> V_636 *= 2 ;
}
goto V_321;
V_674:
if ( V_687 ) {
int * V_697 = & V_687 -> V_494 -> V_513 -> V_506 ;
if ( * V_697 )
* V_697 = 0 ;
}
V_698:
F_83 ( V_213 -> V_706 [ V_404 ] ) ;
V_213 -> V_594 = 0 ;
V_700:
if ( ( ( V_182 . V_115 & V_592 ) &&
V_213 -> V_636 < V_707 ) ||
( V_213 -> V_636 < V_213 -> V_705 ) )
V_213 -> V_636 *= 2 ;
V_684 = 0 ;
V_321:
return V_684 ;
}
static inline unsigned long
F_482 ( struct V_212 * V_213 , int V_708 )
{
unsigned long V_221 = V_213 -> V_636 ;
if ( V_708 )
V_221 *= V_213 -> V_709 ;
V_221 = F_155 ( V_221 ) ;
V_221 = F_158 ( V_221 , 1UL , V_637 ) ;
return V_221 ;
}
static inline void
F_483 ( struct V_212 * V_213 , unsigned long * V_710 )
{
unsigned long V_221 , V_61 ;
V_221 = F_482 ( V_213 , 0 ) ;
V_61 = V_213 -> V_711 + V_221 ;
if ( F_192 ( * V_710 , V_61 ) )
* V_710 = V_61 ;
}
static int F_258 ( struct V_25 * F_243 , struct V_369 * V_370 )
{
unsigned long V_710 = V_224 + V_222 ;
int V_485 = F_243 -> V_1 ;
struct V_212 * V_213 ;
int V_712 = 0 ;
T_2 V_713 = 0 ;
F_243 -> V_524 = F_78 ( F_243 ) ;
F_484 ( F_243 , V_370 ) ;
if ( F_243 -> V_542 < V_582 ||
! F_243 -> V_550 -> V_650 ) {
F_134 () ;
V_213 = F_485 ( F_243 -> V_213 ) ;
if ( V_213 )
F_483 ( V_213 , & V_710 ) ;
F_142 () ;
goto V_321;
}
F_304 ( & F_243 -> V_257 ) ;
F_439 ( V_485 ) ;
F_134 () ;
F_406 (this_cpu, sd) {
int V_683 = 1 ;
T_2 V_714 , V_715 ;
if ( ! ( V_213 -> V_115 & V_559 ) )
continue;
if ( F_243 -> V_542 < V_713 + V_213 -> V_716 ) {
F_483 ( V_213 , & V_710 ) ;
break;
}
if ( V_213 -> V_115 & V_717 ) {
V_714 = F_297 ( V_485 ) ;
V_712 = F_474 ( V_485 , F_243 ,
V_213 , V_612 ,
& V_683 ) ;
V_715 = F_297 ( V_485 ) - V_714 ;
if ( V_715 > V_213 -> V_716 )
V_213 -> V_716 = V_715 ;
V_713 += V_715 ;
}
F_483 ( V_213 , & V_710 ) ;
if ( V_712 || F_243 -> V_75 > 0 )
break;
}
F_142 () ;
F_302 ( & F_243 -> V_257 ) ;
if ( V_713 > F_243 -> V_718 )
F_243 -> V_718 = V_713 ;
if ( F_243 -> V_42 . V_415 && ! V_712 )
V_712 = 1 ;
V_321:
if ( F_192 ( F_243 -> V_710 , V_710 ) )
F_243 -> V_710 = V_710 ;
if ( F_243 -> V_75 != F_243 -> V_42 . V_415 )
V_712 = - 1 ;
if ( V_712 )
F_243 -> V_524 = 0 ;
F_486 ( F_243 , V_370 ) ;
return V_712 ;
}
static int V_702 ( void * V_410 )
{
struct V_25 * V_719 = V_410 ;
int V_667 = F_26 ( V_719 ) ;
int V_720 = V_719 -> V_701 ;
struct V_25 * V_721 = F_124 ( V_720 ) ;
struct V_212 * V_213 ;
struct V_27 * V_30 = NULL ;
struct V_369 V_370 ;
F_487 ( V_719 , & V_370 ) ;
if ( F_14 ( V_667 != F_298 () ||
! V_719 -> V_686 ) )
goto V_722;
if ( V_719 -> V_75 <= 1 )
goto V_722;
F_181 ( V_719 == V_721 ) ;
F_134 () ;
F_406 (target_cpu, sd) {
if ( ( V_213 -> V_115 & V_559 ) &&
F_137 ( V_667 , F_395 ( V_213 ) ) )
break;
}
if ( F_12 ( V_213 ) ) {
struct V_580 V_182 = {
. V_213 = V_213 ,
. V_168 = V_720 ,
. V_202 = V_721 ,
. V_201 = V_719 -> V_1 ,
. V_200 = V_719 ,
. V_404 = V_676 ,
} ;
F_83 ( V_213 -> V_723 ) ;
F_316 ( V_719 ) ;
V_30 = F_428 ( & V_182 ) ;
if ( V_30 ) {
F_83 ( V_213 -> V_724 ) ;
V_213 -> V_594 = 0 ;
} else {
F_83 ( V_213 -> V_725 ) ;
}
}
F_142 () ;
V_722:
V_719 -> V_686 = 0 ;
F_321 ( V_719 , & V_370 ) ;
if ( V_30 )
F_437 ( V_721 , V_30 ) ;
F_141 () ;
return 0 ;
}
static inline int F_488 ( struct V_25 * V_25 )
{
return F_14 ( ! F_489 ( V_25 -> V_213 ) ) ;
}
static inline int F_490 ( void )
{
int V_726 = F_382 ( V_727 . V_728 ) ;
if ( V_726 < V_729 && F_384 ( V_726 ) )
return V_726 ;
return V_729 ;
}
static void F_491 ( void )
{
int V_730 ;
V_727 . V_710 ++ ;
V_730 = F_490 () ;
if ( V_730 >= V_729 )
return;
if ( F_492 ( V_731 , F_493 ( V_730 ) ) )
return;
F_494 ( V_730 ) ;
return;
}
void F_495 ( unsigned int V_1 )
{
if ( F_14 ( F_496 ( V_732 , F_493 ( V_1 ) ) ) ) {
if ( F_12 ( F_137 ( V_1 , V_727 . V_728 ) ) ) {
F_397 ( V_1 , V_727 . V_728 ) ;
F_497 ( & V_727 . V_733 ) ;
}
F_498 ( V_732 , F_493 ( V_1 ) ) ;
}
}
static inline void F_499 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_298 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_544 , V_1 ) ) ;
if ( ! V_213 || ! V_213 -> V_734 )
goto V_206;
V_213 -> V_734 = 0 ;
F_500 ( & V_213 -> V_226 -> V_735 ) ;
V_206:
F_142 () ;
}
void F_501 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_298 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_544 , V_1 ) ) ;
if ( ! V_213 || V_213 -> V_734 )
goto V_206;
V_213 -> V_734 = 1 ;
F_497 ( & V_213 -> V_226 -> V_735 ) ;
V_206:
F_142 () ;
}
void F_502 ( int V_1 )
{
if ( ! F_503 ( V_1 ) )
return;
if ( F_496 ( V_732 , F_493 ( V_1 ) ) )
return;
if ( F_488 ( F_124 ( V_1 ) ) )
return;
F_504 ( V_1 , V_727 . V_728 ) ;
F_500 ( & V_727 . V_733 ) ;
F_505 ( V_732 , F_493 ( V_1 ) ) ;
}
void F_506 ( void )
{
V_637 = V_222 * F_507 () / 10 ;
}
static void F_508 ( struct V_25 * V_25 , enum V_626 V_404 )
{
int V_683 = 1 ;
int V_1 = V_25 -> V_1 ;
unsigned long V_221 ;
struct V_212 * V_213 ;
unsigned long V_710 = V_224 + 60 * V_222 ;
int F_483 = 0 ;
int V_736 , V_737 = 0 ;
T_2 V_738 = 0 ;
F_439 ( V_1 ) ;
F_134 () ;
F_406 (cpu, sd) {
if ( F_192 ( V_224 , V_213 -> V_739 ) ) {
V_213 -> V_716 =
( V_213 -> V_716 * 253 ) / 256 ;
V_213 -> V_739 = V_224 + V_222 ;
V_737 = 1 ;
}
V_738 += V_213 -> V_716 ;
if ( ! ( V_213 -> V_115 & V_559 ) )
continue;
if ( ! V_683 ) {
if ( V_737 )
continue;
break;
}
V_221 = F_482 ( V_213 , V_404 != V_676 ) ;
V_736 = V_213 -> V_115 & V_740 ;
if ( V_736 ) {
if ( ! F_509 ( & V_741 ) )
goto V_321;
}
if ( F_464 ( V_224 , V_213 -> V_711 + V_221 ) ) {
if ( F_474 ( V_1 , V_25 , V_213 , V_404 , & V_683 ) ) {
V_404 = F_384 ( V_1 ) ? V_676 : V_605 ;
}
V_213 -> V_711 = V_224 ;
V_221 = F_482 ( V_213 , V_404 != V_676 ) ;
}
if ( V_736 )
F_184 ( & V_741 ) ;
V_321:
if ( F_192 ( V_710 , V_213 -> V_711 + V_221 ) ) {
V_710 = V_213 -> V_711 + V_221 ;
F_483 = 1 ;
}
}
if ( V_737 ) {
V_25 -> V_718 =
F_69 ( ( T_2 ) V_582 , V_738 ) ;
}
F_142 () ;
if ( F_12 ( F_483 ) ) {
V_25 -> V_710 = V_710 ;
#ifdef F_357
if ( ( V_404 == V_676 ) && F_192 ( V_727 . V_710 , V_25 -> V_710 ) )
V_727 . V_710 = V_25 -> V_710 ;
#endif
}
}
static void F_510 ( struct V_25 * F_243 , enum V_626 V_404 )
{
int V_485 = F_243 -> V_1 ;
struct V_25 * V_25 ;
int V_682 ;
unsigned long V_710 = V_224 + 60 * V_222 ;
int F_483 = 0 ;
if ( V_404 != V_676 ||
! F_496 ( V_731 , F_493 ( V_485 ) ) )
goto V_301;
F_123 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_682 == V_485 || ! F_384 ( V_682 ) )
continue;
if ( F_511 () )
break;
V_25 = F_124 ( V_682 ) ;
if ( F_464 ( V_224 , V_25 -> V_710 ) ) {
struct V_369 V_370 ;
F_487 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
F_360 ( V_25 ) ;
F_512 ( V_25 , & V_370 ) ;
F_508 ( V_25 , V_676 ) ;
}
if ( F_192 ( V_710 , V_25 -> V_710 ) ) {
V_710 = V_25 -> V_710 ;
F_483 = 1 ;
}
}
if ( F_12 ( F_483 ) )
V_727 . V_710 = V_710 ;
V_301:
F_498 ( V_731 , F_493 ( V_485 ) ) ;
}
static inline bool F_513 ( struct V_25 * V_25 )
{
unsigned long V_92 = V_224 ;
struct V_530 * V_531 ;
struct V_212 * V_213 ;
int V_742 , V_272 , V_1 = V_25 -> V_1 ;
bool V_743 = false ;
if ( F_14 ( V_25 -> F_258 ) )
return false ;
F_499 () ;
F_495 ( V_1 ) ;
if ( F_12 ( ! F_514 ( & V_727 . V_733 ) ) )
return false ;
if ( F_196 ( V_92 , V_727 . V_710 ) )
return false ;
if ( V_25 -> V_75 >= 2 )
return true ;
F_134 () ;
V_531 = F_147 ( F_148 ( V_532 , V_1 ) ) ;
if ( V_531 ) {
V_742 = F_514 ( & V_531 -> V_735 ) ;
if ( V_742 > 1 ) {
V_743 = true ;
goto V_206;
}
}
V_213 = F_147 ( V_25 -> V_213 ) ;
if ( V_213 ) {
if ( ( V_25 -> V_42 . V_415 >= 1 ) &&
F_451 ( V_25 , V_213 ) ) {
V_743 = true ;
goto V_206;
}
}
V_213 = F_147 ( F_148 ( V_744 , V_1 ) ) ;
if ( V_213 ) {
F_123 (i, sched_domain_span(sd)) {
if ( V_272 == V_1 ||
! F_137 ( V_272 , V_727 . V_728 ) )
continue;
if ( F_460 ( V_272 , V_1 ) ) {
V_743 = true ;
goto V_206;
}
}
}
V_206:
F_142 () ;
return V_743 ;
}
static void F_510 ( struct V_25 * F_243 , enum V_626 V_404 ) { }
static T_12 void F_515 ( struct V_745 * V_746 )
{
struct V_25 * F_243 = F_243 () ;
enum V_626 V_404 = F_243 -> F_258 ?
V_676 : V_605 ;
F_510 ( F_243 , V_404 ) ;
F_508 ( F_243 , V_404 ) ;
}
void F_516 ( struct V_25 * V_25 )
{
if ( F_14 ( F_488 ( V_25 ) ) )
return;
if ( F_464 ( V_224 , V_25 -> V_710 ) )
F_517 ( V_747 ) ;
#ifdef F_357
if ( F_513 ( V_25 ) )
F_491 () ;
#endif
}
static void F_518 ( struct V_25 * V_25 )
{
F_8 () ;
F_344 ( V_25 ) ;
}
static void F_519 ( struct V_25 * V_25 )
{
F_8 () ;
F_346 ( V_25 ) ;
}
static void F_520 ( struct V_25 * V_25 , struct V_27 * V_47 , int V_386 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_47 -> V_29 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_285 ( V_26 , V_29 , V_386 ) ;
}
if ( F_521 ( & V_286 ) )
F_207 ( V_25 , V_47 ) ;
}
static void F_522 ( struct V_27 * V_30 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 , * V_47 ;
struct V_25 * V_25 = F_243 () ;
struct V_369 V_370 ;
F_320 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
V_26 = F_22 ( V_172 ) ;
V_47 = V_26 -> V_47 ;
if ( V_47 ) {
F_66 ( V_26 ) ;
V_29 -> V_43 = V_47 -> V_43 ;
}
F_261 ( V_26 , V_29 , 1 ) ;
if ( V_748 && V_47 && F_37 ( V_47 , V_29 ) ) {
F_132 ( V_47 -> V_43 , V_29 -> V_43 ) ;
F_279 ( V_25 ) ;
}
V_29 -> V_43 -= V_26 -> F_36 ;
F_321 ( V_25 , & V_370 ) ;
}
static void
F_523 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_749 )
{
if ( ! F_524 ( V_30 ) )
return;
if ( V_25 -> V_47 == V_30 ) {
if ( V_30 -> V_750 > V_749 )
F_279 ( V_25 ) ;
} else
F_436 ( V_25 , V_30 , 0 ) ;
}
static inline bool F_525 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_48 )
return true ;
if ( ! V_29 -> V_96 || V_30 -> V_118 == V_563 )
return true ;
return false ;
}
static void F_526 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
V_29 = V_29 -> V_35 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
if ( F_307 ( V_26 ) )
break;
F_248 ( V_29 , V_366 ) ;
}
}
static void F_526 ( struct V_28 * V_29 ) { }
static void F_527 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_248 ( V_29 , 0 ) ;
F_250 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_526 ( V_29 ) ;
}
static void F_64 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
#ifdef F_415
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
#endif
F_248 ( V_29 , F_233 ( V_351 ) ? 0 : V_365 ) ;
F_249 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_526 ( V_29 ) ;
}
static void F_528 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( ! F_525 ( V_30 ) ) {
F_261 ( V_26 , V_29 , 0 ) ;
V_29 -> V_43 -= V_26 -> F_36 ;
}
F_527 ( V_29 ) ;
}
static void F_529 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_64 ( V_29 ) ;
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
F_279 ( V_25 ) ;
else
F_436 ( V_25 , V_30 , 0 ) ;
}
}
static void F_532 ( struct V_25 * V_25 )
{
struct V_28 * V_29 = & V_25 -> V_47 -> V_29 ;
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_280 ( V_26 , V_29 ) ;
F_74 ( V_26 , 0 ) ;
}
}
void F_533 ( struct V_26 * V_26 )
{
V_26 -> V_54 = V_751 ;
V_26 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_26 -> V_51 = V_26 -> F_36 ;
#endif
#ifdef F_211
#ifdef F_415
V_26 -> V_357 = 0 ;
#endif
F_534 ( & V_26 -> V_362 , 0 ) ;
F_534 ( & V_26 -> V_364 , 0 ) ;
#endif
}
static void F_535 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
F_536 ( V_30 , F_146 ( V_30 ) ) ;
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
}
static void F_537 ( struct V_27 * V_30 )
{
F_528 ( V_30 ) ;
F_536 ( V_30 , F_146 ( V_30 ) ) ;
#ifdef F_211
V_30 -> V_29 . V_79 . V_80 = 0 ;
#endif
F_529 ( V_30 ) ;
}
static void F_538 ( struct V_27 * V_30 , int type )
{
switch ( type ) {
case V_752 :
F_535 ( V_30 ) ;
break;
case V_753 :
F_537 ( V_30 ) ;
break;
}
}
void F_539 ( struct V_325 * V_34 )
{
int V_272 ;
F_342 ( F_300 ( V_34 ) ) ;
F_540 (i) {
if ( V_34 -> V_26 )
F_189 ( V_34 -> V_26 [ V_272 ] ) ;
if ( V_34 -> V_29 )
F_189 ( V_34 -> V_29 [ V_272 ] ) ;
}
F_189 ( V_34 -> V_26 ) ;
F_189 ( V_34 -> V_29 ) ;
}
int F_541 ( struct V_325 * V_34 , struct V_325 * V_35 )
{
struct V_28 * V_29 ;
struct V_26 * V_26 ;
int V_272 ;
V_34 -> V_26 = F_177 ( sizeof( V_26 ) * V_729 , V_274 ) ;
if ( ! V_34 -> V_26 )
goto V_754;
V_34 -> V_29 = F_177 ( sizeof( V_29 ) * V_729 , V_274 ) ;
if ( ! V_34 -> V_29 )
goto V_754;
V_34 -> V_327 = V_74 ;
F_335 ( F_300 ( V_34 ) ) ;
F_540 (i) {
V_26 = F_542 ( sizeof( struct V_26 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_26 )
goto V_754;
V_29 = F_542 ( sizeof( struct V_28 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_29 )
goto V_755;
F_533 ( V_26 ) ;
F_543 ( V_34 , V_26 , V_29 , V_272 , V_35 -> V_29 [ V_272 ] ) ;
F_61 ( V_29 ) ;
}
return 1 ;
V_755:
F_189 ( V_26 ) ;
V_754:
return 0 ;
}
void F_544 ( struct V_325 * V_34 )
{
struct V_28 * V_29 ;
struct V_25 * V_25 ;
int V_272 ;
F_540 (i) {
V_25 = F_124 ( V_272 ) ;
V_29 = V_34 -> V_29 [ V_272 ] ;
F_545 ( & V_25 -> V_257 ) ;
F_316 ( V_25 ) ;
F_64 ( V_29 ) ;
F_331 ( V_34 , V_272 ) ;
F_546 ( & V_25 -> V_257 ) ;
}
}
void F_547 ( struct V_325 * V_34 )
{
unsigned long V_115 ;
struct V_25 * V_25 ;
int V_1 ;
F_540 (cpu) {
if ( V_34 -> V_29 [ V_1 ] )
F_255 ( V_34 -> V_29 [ V_1 ] ) ;
if ( ! V_34 -> V_26 [ V_1 ] -> V_33 )
continue;
V_25 = F_124 ( V_1 ) ;
F_479 ( & V_25 -> V_257 , V_115 ) ;
F_29 ( V_34 -> V_26 [ V_1 ] ) ;
F_480 ( & V_25 -> V_257 , V_115 ) ;
}
}
void F_543 ( struct V_325 * V_34 , struct V_26 * V_26 ,
struct V_28 * V_29 , int V_1 ,
struct V_28 * V_35 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_25 = V_25 ;
F_339 ( V_26 ) ;
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
int F_548 ( struct V_325 * V_34 , unsigned long V_327 )
{
int V_272 ;
if ( ! V_34 -> V_29 [ 0 ] )
return - V_217 ;
V_327 = F_158 ( V_327 , F_549 ( V_329 ) , F_549 ( V_756 ) ) ;
F_550 ( & V_757 ) ;
if ( V_34 -> V_327 == V_327 )
goto V_758;
V_34 -> V_327 = V_327 ;
F_540 (i) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_28 * V_29 = V_34 -> V_29 [ V_272 ] ;
struct V_369 V_370 ;
F_440 ( V_25 , & V_370 ) ;
F_316 ( V_25 ) ;
F_59 (se) {
F_248 ( V_29 , V_366 ) ;
F_218 ( V_29 ) ;
}
F_441 ( V_25 , & V_370 ) ;
}
V_758:
F_551 ( & V_757 ) ;
return 0 ;
}
void F_539 ( struct V_325 * V_34 ) { }
int F_541 ( struct V_325 * V_34 , struct V_325 * V_35 )
{
return 1 ;
}
void F_544 ( struct V_325 * V_34 ) { }
void F_547 ( struct V_325 * V_34 ) { }
static unsigned int F_552 ( struct V_25 * V_25 , struct V_27 * V_154 )
{
struct V_28 * V_29 = & V_154 -> V_29 ;
unsigned int V_759 = 0 ;
if ( V_25 -> V_42 . V_73 . V_5 )
V_759 = F_553 ( F_58 ( F_23 ( V_29 ) , V_29 ) ) ;
return V_759 ;
}
void F_554 ( struct V_760 * V_761 , int V_1 )
{
struct V_26 * V_26 ;
F_134 () ;
F_345 (cpu_rq(cpu), cfs_rq)
F_555 ( V_761 , V_1 , V_26 ) ;
F_142 () ;
}
void F_556 ( struct V_27 * V_30 , struct V_760 * V_761 )
{
int V_156 ;
unsigned long V_762 = 0 , V_763 = 0 , V_764 = 0 , V_765 = 0 ;
F_111 (node) {
if ( V_30 -> V_145 ) {
V_762 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 0 ) ] ;
V_763 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
if ( V_30 -> V_137 ) {
V_764 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 0 ) ] ,
V_765 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
F_557 ( V_761 , V_156 , V_762 , V_763 , V_764 , V_765 ) ;
}
}
T_13 void F_558 ( void )
{
#ifdef F_211
F_559 ( V_747 , F_515 ) ;
#ifdef F_357
V_727 . V_710 = V_224 ;
F_560 ( & V_727 . V_728 , V_766 ) ;
#endif
#endif
}
