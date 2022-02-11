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
if ( ! F_198 ( & V_125 -> V_308 ) )
return;
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
static inline bool F_210 ( struct V_212 * V_213 ,
struct V_27 * V_30 , int V_323 ,
int V_324 , int V_325 )
{
struct V_174 V_326 , V_327 ;
T_3 V_328 , V_329 ;
F_122 ( & V_326 , F_116 ( V_324 ) ) ;
F_122 ( & V_327 , F_116 ( V_323 ) ) ;
if ( V_325 ) {
unsigned long V_330 = F_138 ( V_172 ) ;
if ( V_327 . V_73 > V_330 )
V_327 . V_73 -= V_330 ;
else
V_327 . V_73 = 0 ;
}
if ( V_327 . V_73 > 0 ) {
unsigned long V_331 = F_138 ( V_30 ) ;
V_328 = 100 ;
V_328 *= V_326 . V_178 ;
V_329 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
V_329 *= V_327 . V_178 ;
V_328 *= V_327 . V_73 + V_331 ;
V_329 *= V_326 . V_73 - V_331 ;
return V_328 <= V_329 ;
}
return true ;
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
static inline bool F_210 ( struct V_212 * V_213 ,
struct V_27 * V_30 , int V_323 ,
int V_324 , int V_325 )
{
return true ;
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
F_213 ( & V_29 -> V_332 , & V_25 -> V_333 ) ;
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
F_215 ( & V_29 -> V_332 ) ;
}
#endif
V_26 -> V_75 -- ;
}
static long F_216 ( struct V_26 * V_26 , struct V_334 * V_34 )
{
long V_335 , V_73 , V_336 ;
V_73 = F_13 ( V_26 -> V_73 . V_5 ) ;
V_335 = F_217 ( & V_34 -> V_82 ) ;
V_335 -= V_26 -> V_337 ;
V_335 += V_73 ;
V_336 = ( V_34 -> V_336 * V_73 ) ;
if ( V_335 )
V_336 /= V_335 ;
if ( V_336 < V_338 )
V_336 = V_338 ;
if ( V_336 > V_34 -> V_336 )
V_336 = V_34 -> V_336 ;
return V_336 ;
}
static inline long F_216 ( struct V_26 * V_26 , struct V_334 * V_34 )
{
return V_34 -> V_336 ;
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
static void F_219 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
struct V_334 * V_34 ;
long V_336 ;
if ( ! V_26 )
return;
if ( F_220 ( V_26 ) )
return;
V_34 = V_26 -> V_34 ;
#ifndef F_212
if ( F_12 ( V_29 -> V_73 . V_5 == V_34 -> V_336 ) )
return;
#endif
V_336 = F_216 ( V_26 , V_34 ) ;
F_218 ( F_23 ( V_29 ) , V_29 , V_336 ) ;
}
static inline void F_219 ( struct V_28 * V_29 )
{
}
static T_2 F_221 ( T_2 V_339 , T_2 V_340 )
{
unsigned int V_341 ;
if ( F_14 ( V_340 > V_342 * 63 ) )
return 0 ;
V_341 = V_340 ;
if ( F_14 ( V_341 >= V_342 ) ) {
V_339 >>= V_341 / V_342 ;
V_341 %= V_342 ;
}
V_339 = F_16 ( V_339 , V_343 [ V_341 ] , 32 ) ;
return V_339 ;
}
static V_24 F_222 ( T_2 V_344 , V_24 V_345 , V_24 V_346 )
{
V_24 V_347 , V_348 , V_349 = V_346 ;
V_347 = F_221 ( ( T_2 ) V_345 , V_344 ) ;
V_348 = V_84 - F_221 ( V_84 , V_344 ) - 1024 ;
return V_347 + V_348 + V_349 ;
}
static T_10 V_24
F_223 ( T_2 V_44 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_350 , struct V_26 * V_26 )
{
unsigned long V_351 , V_352 ;
V_24 V_353 = ( V_24 ) V_44 ;
T_2 V_344 ;
V_351 = F_224 ( NULL , V_1 ) ;
V_352 = F_225 ( NULL , V_1 ) ;
V_44 += V_78 -> V_81 ;
V_344 = V_44 / 1024 ;
if ( V_344 ) {
V_78 -> V_83 = F_221 ( V_78 -> V_83 , V_344 ) ;
if ( V_26 ) {
V_26 -> V_354 =
F_221 ( V_26 -> V_354 , V_344 ) ;
}
V_78 -> V_86 = F_221 ( ( T_2 ) ( V_78 -> V_86 ) , V_344 ) ;
V_44 %= 1024 ;
V_353 = F_222 ( V_344 ,
1024 - V_78 -> V_81 , V_44 ) ;
}
V_78 -> V_81 = V_44 ;
V_353 = F_226 ( V_353 , V_351 ) ;
if ( V_5 ) {
V_78 -> V_83 += V_5 * V_353 ;
if ( V_26 )
V_26 -> V_354 += V_5 * V_353 ;
}
if ( V_350 )
V_78 -> V_86 += V_353 * V_352 ;
return V_344 ;
}
static T_10 int
F_227 ( T_2 V_92 , int V_1 , struct V_77 * V_78 ,
unsigned long V_5 , int V_350 , struct V_26 * V_26 )
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
if ( ! F_223 ( V_44 , V_1 , V_78 , V_5 , V_350 , V_26 ) )
return 0 ;
V_78 -> V_82 = F_228 ( V_78 -> V_83 , V_84 - 1024 + V_78 -> V_81 ) ;
if ( V_26 ) {
V_26 -> V_355 =
F_228 ( V_26 -> V_354 , V_84 - 1024 + V_78 -> V_81 ) ;
}
V_78 -> V_85 = V_78 -> V_86 / ( V_84 - 1024 + V_78 -> V_81 ) ;
return 1 ;
}
static int
F_229 ( T_2 V_92 , int V_1 , struct V_28 * V_29 )
{
return F_227 ( V_92 , V_1 , & V_29 -> V_79 , 0 , 0 , NULL ) ;
}
static int
F_230 ( T_2 V_92 , int V_1 , struct V_26 * V_26 , struct V_28 * V_29 )
{
return F_227 ( V_92 , V_1 , & V_29 -> V_79 ,
V_29 -> V_48 * F_13 ( V_29 -> V_73 . V_5 ) ,
V_26 -> V_47 == V_29 , NULL ) ;
}
static int
F_231 ( T_2 V_92 , int V_1 , struct V_26 * V_26 )
{
return F_227 ( V_92 , V_1 , & V_26 -> V_79 ,
F_13 ( V_26 -> V_73 . V_5 ) ,
V_26 -> V_47 != NULL , V_26 ) ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 )
{
long V_44 = V_26 -> V_79 . V_82 - V_26 -> V_337 ;
if ( V_26 -> V_34 == & V_356 )
return;
if ( V_91 || abs ( V_44 ) > V_26 -> V_337 / 64 ) {
F_232 ( V_44 , & V_26 -> V_34 -> V_82 ) ;
V_26 -> V_337 = V_26 -> V_79 . V_82 ;
}
}
void F_233 ( struct V_28 * V_29 ,
struct V_26 * V_357 , struct V_26 * V_61 )
{
T_2 V_358 ;
T_2 V_359 ;
if ( ! F_234 ( V_360 ) )
return;
if ( ! ( V_29 -> V_79 . V_80 && V_357 ) )
return;
#ifndef F_40
{
T_2 V_361 ;
T_2 V_362 ;
do {
V_361 = V_357 -> V_363 ;
V_362 = V_61 -> V_363 ;
F_235 () ;
V_358 = V_357 -> V_79 . V_80 ;
V_359 = V_61 -> V_79 . V_80 ;
} while ( V_358 != V_361 ||
V_359 != V_362 );
}
#else
V_358 = V_357 -> V_79 . V_80 ;
V_359 = V_61 -> V_79 . V_80 ;
#endif
F_229 ( V_358 , F_26 ( F_17 ( V_357 ) ) , V_29 ) ;
V_29 -> V_79 . V_80 = V_359 ;
}
static inline void
F_236 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_364 = F_24 ( V_29 ) ;
long V_44 = V_364 -> V_79 . V_85 - V_29 -> V_79 . V_85 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_85 = V_364 -> V_79 . V_85 ;
V_29 -> V_79 . V_86 = V_29 -> V_79 . V_85 * V_84 ;
F_237 ( & V_26 -> V_79 . V_85 , V_44 ) ;
V_26 -> V_79 . V_86 = V_26 -> V_79 . V_85 * V_84 ;
}
static inline void
F_238 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_26 * V_364 = F_24 ( V_29 ) ;
long V_44 , V_73 = V_364 -> V_79 . V_82 ;
if ( V_73 ) {
long V_365 ;
V_365 = F_217 ( & V_364 -> V_34 -> V_82 ) + 1 ;
V_365 -= V_364 -> V_337 ;
V_365 += V_73 ;
if ( V_365 > F_13 ( V_364 -> V_34 -> V_336 ) ) {
V_73 *= F_13 ( V_364 -> V_34 -> V_336 ) ;
V_73 /= V_365 ;
}
}
V_44 = V_73 - V_29 -> V_79 . V_82 ;
if ( ! V_44 )
return;
V_29 -> V_79 . V_82 = V_73 ;
V_29 -> V_79 . V_83 = V_29 -> V_79 . V_82 * V_84 ;
F_237 ( & V_26 -> V_79 . V_82 , V_44 ) ;
V_26 -> V_79 . V_83 = V_26 -> V_79 . V_82 * V_84 ;
if ( V_29 -> V_48 ) {
F_237 ( & V_26 -> V_355 , V_44 ) ;
V_26 -> V_354 = V_26 -> V_355 * V_84 ;
}
}
static inline void F_239 ( struct V_26 * V_26 )
{
V_26 -> V_366 = 1 ;
}
static inline int F_240 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_24 ( V_29 ) ;
if ( ! V_26 -> V_366 )
return 0 ;
V_26 -> V_366 = 0 ;
return 1 ;
}
static inline int F_241 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
if ( F_20 ( V_29 ) )
return 0 ;
if ( ! F_240 ( V_29 ) )
return 0 ;
V_26 = F_23 ( V_29 ) ;
F_239 ( V_26 ) ;
F_236 ( V_26 , V_29 ) ;
F_238 ( V_26 , V_29 ) ;
return 1 ;
}
static inline bool F_242 ( struct V_28 * V_29 )
{
struct V_26 * V_364 = F_24 ( V_29 ) ;
if ( V_29 -> V_79 . V_82 || V_29 -> V_79 . V_85 )
return false ;
if ( V_364 -> V_366 )
return false ;
return true ;
}
static inline void F_65 ( struct V_26 * V_26 , int V_91 ) {}
static inline int F_241 ( struct V_28 * V_29 )
{
return 0 ;
}
static inline void F_239 ( struct V_26 * V_26 ) {}
static inline void F_243 ( struct V_26 * V_26 )
{
if ( & F_244 () -> V_42 == V_26 ) {
F_245 ( F_17 ( V_26 ) , 0 ) ;
}
}
static inline int
F_246 ( T_2 V_92 , struct V_26 * V_26 , bool V_367 )
{
struct V_77 * V_78 = & V_26 -> V_79 ;
int V_368 , V_369 = 0 , V_370 = 0 ;
if ( F_217 ( & V_26 -> V_371 ) ) {
T_3 V_372 = F_247 ( & V_26 -> V_371 , 0 ) ;
F_248 ( & V_78 -> V_82 , V_372 ) ;
F_248 ( & V_78 -> V_83 , V_372 * V_84 ) ;
V_369 = 1 ;
F_239 ( V_26 ) ;
}
if ( F_217 ( & V_26 -> V_373 ) ) {
long V_372 = F_247 ( & V_26 -> V_373 , 0 ) ;
F_248 ( & V_78 -> V_85 , V_372 ) ;
F_248 ( & V_78 -> V_86 , V_372 * V_84 ) ;
V_370 = 1 ;
F_239 ( V_26 ) ;
}
V_368 = F_231 ( V_92 , F_26 ( F_17 ( V_26 ) ) , V_26 ) ;
#ifndef F_40
F_41 () ;
V_26 -> V_363 = V_78 -> V_80 ;
#endif
if ( V_367 && ( V_368 || V_370 ) )
F_243 ( V_26 ) ;
return V_368 || V_369 ;
}
static inline void F_249 ( struct V_28 * V_29 , int V_115 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_92 = F_63 ( V_26 ) ;
struct V_25 * V_25 = F_17 ( V_26 ) ;
int V_1 = F_26 ( V_25 ) ;
int V_368 ;
if ( V_29 -> V_79 . V_80 && ! ( V_115 & V_374 ) )
F_230 ( V_92 , V_1 , V_26 , V_29 ) ;
V_368 = F_246 ( V_92 , V_26 , true ) ;
V_368 |= F_241 ( V_29 ) ;
if ( V_368 && ( V_115 & V_375 ) )
F_65 ( V_26 , 0 ) ;
}
static void F_250 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_29 -> V_79 . V_80 = V_26 -> V_79 . V_80 ;
V_26 -> V_79 . V_82 += V_29 -> V_79 . V_82 ;
V_26 -> V_79 . V_83 += V_29 -> V_79 . V_83 ;
V_26 -> V_79 . V_85 += V_29 -> V_79 . V_85 ;
V_26 -> V_79 . V_86 += V_29 -> V_79 . V_86 ;
F_239 ( V_26 ) ;
F_243 ( V_26 ) ;
}
static void F_251 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
F_248 ( & V_26 -> V_79 . V_82 , V_29 -> V_79 . V_82 ) ;
F_248 ( & V_26 -> V_79 . V_83 , V_29 -> V_79 . V_83 ) ;
F_248 ( & V_26 -> V_79 . V_85 , V_29 -> V_79 . V_85 ) ;
F_248 ( & V_26 -> V_79 . V_86 , V_29 -> V_79 . V_86 ) ;
F_239 ( V_26 ) ;
F_243 ( V_26 ) ;
}
static inline void
F_252 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
struct V_77 * V_78 = & V_29 -> V_79 ;
V_26 -> V_355 += V_78 -> V_82 ;
V_26 -> V_354 += V_78 -> V_83 ;
if ( ! V_78 -> V_80 ) {
F_250 ( V_26 , V_29 ) ;
F_65 ( V_26 , 0 ) ;
}
}
static inline void
F_253 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
V_26 -> V_355 =
F_99 ( long , V_26 -> V_355 - V_29 -> V_79 . V_82 , 0 ) ;
V_26 -> V_354 =
F_99 ( T_3 , V_26 -> V_354 - V_29 -> V_79 . V_83 , 0 ) ;
}
static inline T_2 F_254 ( struct V_26 * V_26 )
{
T_2 V_376 ;
T_2 V_80 ;
do {
V_376 = V_26 -> V_363 ;
F_235 () ;
V_80 = V_26 -> V_79 . V_80 ;
} while ( V_80 != V_376 );
return V_80 ;
}
static inline T_2 F_254 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_80 ;
}
void F_255 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 V_80 ;
V_80 = F_254 ( V_26 ) ;
F_229 ( V_80 , F_26 ( F_17 ( V_26 ) ) , V_29 ) ;
}
void F_256 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_255 ( V_29 ) ;
F_232 ( V_29 -> V_79 . V_82 , & V_26 -> V_371 ) ;
F_232 ( V_29 -> V_79 . V_85 , & V_26 -> V_373 ) ;
}
static inline unsigned long F_257 ( struct V_26 * V_26 )
{
return V_26 -> V_355 ;
}
static inline unsigned long F_258 ( struct V_26 * V_26 )
{
return V_26 -> V_79 . V_82 ;
}
static inline int
F_246 ( T_2 V_92 , struct V_26 * V_26 , bool V_367 )
{
return 0 ;
}
static inline void F_249 ( struct V_28 * V_29 , int V_377 )
{
F_245 ( F_17 ( F_23 ( V_29 ) ) , 0 ) ;
}
static inline void
F_252 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_253 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void F_256 ( struct V_28 * V_29 ) {}
static inline void
F_250 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline void
F_251 ( struct V_26 * V_26 , struct V_28 * V_29 ) {}
static inline int F_259 ( struct V_25 * V_25 , struct V_378 * V_379 )
{
return 0 ;
}
static void F_260 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
#ifdef F_261
T_3 V_380 = V_29 -> V_43 - V_26 -> F_36 ;
if ( V_380 < 0 )
V_380 = - V_380 ;
if ( V_380 > 3 * V_71 )
F_83 ( V_26 -> V_381 ) ;
#endif
}
static void
F_262 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_382 )
{
T_2 V_43 = V_26 -> F_36 ;
if ( V_382 && F_234 ( V_383 ) )
V_43 += F_60 ( V_26 , V_29 ) ;
if ( ! V_382 ) {
unsigned long V_384 = V_71 ;
if ( F_234 ( V_385 ) )
V_384 >>= 1 ;
V_43 -= V_384 ;
}
V_29 -> V_43 = F_35 ( V_29 -> V_43 , V_43 ) ;
}
static inline void F_263 ( void )
{
#ifdef F_264
if ( F_77 () )
return;
if ( F_265 () ||
F_266 () ||
F_267 () ||
F_268 () ||
F_269 () ) {
F_270 ( L_1
L_2
L_3
L_4 ) ;
}
#endif
}
static void
F_271 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
bool V_386 = ! ( V_115 & V_116 ) || ( V_115 & V_387 ) ;
bool V_47 = V_26 -> V_47 == V_29 ;
if ( V_386 && V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_66 ( V_26 ) ;
if ( V_386 && ! V_47 )
V_29 -> V_43 += V_26 -> F_36 ;
F_249 ( V_29 , V_375 ) ;
F_252 ( V_26 , V_29 ) ;
F_219 ( V_29 ) ;
F_211 ( V_26 , V_29 ) ;
if ( V_115 & V_116 )
F_262 ( V_26 , V_29 , 0 ) ;
F_263 () ;
F_91 ( V_26 , V_29 , V_115 ) ;
F_260 ( V_26 , V_29 ) ;
if ( ! V_47 )
F_42 ( V_26 , V_29 ) ;
V_29 -> V_48 = 1 ;
if ( V_26 -> V_75 == 1 ) {
F_25 ( V_26 ) ;
F_272 ( V_26 ) ;
}
}
static void F_273 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_62 != V_29 )
break;
V_26 -> V_62 = NULL ;
}
}
static void F_274 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_61 != V_29 )
break;
V_26 -> V_61 = NULL ;
}
}
static void F_275 ( struct V_28 * V_29 )
{
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( V_26 -> V_388 != V_29 )
break;
V_26 -> V_388 = NULL ;
}
}
static void F_276 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_26 -> V_62 == V_29 )
F_273 ( V_29 ) ;
if ( V_26 -> V_61 == V_29 )
F_274 ( V_29 ) ;
if ( V_26 -> V_388 == V_29 )
F_275 ( V_29 ) ;
}
static void
F_277 ( struct V_26 * V_26 , struct V_28 * V_29 , int V_115 )
{
F_66 ( V_26 ) ;
F_249 ( V_29 , V_375 ) ;
F_253 ( V_26 , V_29 ) ;
F_92 ( V_26 , V_29 , V_115 ) ;
F_276 ( V_26 , V_29 ) ;
if ( V_29 != V_26 -> V_47 )
F_45 ( V_26 , V_29 ) ;
V_29 -> V_48 = 0 ;
F_214 ( V_26 , V_29 ) ;
if ( ! ( V_115 & V_117 ) )
V_29 -> V_43 -= V_26 -> F_36 ;
F_278 ( V_26 ) ;
F_219 ( V_29 ) ;
if ( ( V_115 & ( V_389 | V_390 ) ) == V_389 )
F_38 ( V_26 ) ;
}
static void
F_279 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
unsigned long V_391 , V_20 ;
struct V_28 * V_29 ;
T_3 V_44 ;
V_391 = F_58 ( V_26 , V_47 ) ;
V_20 = V_47 -> V_96 - V_47 -> V_392 ;
if ( V_20 > V_391 ) {
F_280 ( F_17 ( V_26 ) ) ;
F_276 ( V_26 , V_47 ) ;
return;
}
if ( V_20 < V_72 )
return;
V_29 = F_48 ( V_26 ) ;
V_44 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_44 < 0 )
return;
if ( V_44 > V_391 )
F_280 ( F_17 ( V_26 ) ) ;
}
static void
F_281 ( struct V_26 * V_26 , struct V_28 * V_29 )
{
if ( V_29 -> V_48 ) {
F_81 ( V_26 , V_29 ) ;
F_45 ( V_26 , V_29 ) ;
F_249 ( V_29 , V_375 ) ;
}
F_93 ( V_26 , V_29 ) ;
V_26 -> V_47 = V_29 ;
if ( F_77 () && F_17 ( V_26 ) -> V_73 . V_5 >= 2 * V_29 -> V_73 . V_5 ) {
F_68 ( V_29 -> V_94 . V_393 ,
F_69 ( ( T_2 ) F_79 ( V_29 -> V_94 . V_393 ) ,
V_29 -> V_96 - V_29 -> V_392 ) ) ;
}
V_29 -> V_392 = V_29 -> V_96 ;
}
static struct V_28 *
F_282 ( struct V_26 * V_26 , struct V_28 * V_47 )
{
struct V_28 * V_60 = F_48 ( V_26 ) ;
struct V_28 * V_29 ;
if ( ! V_60 || ( V_47 && F_37 ( V_47 , V_60 ) ) )
V_60 = V_47 ;
V_29 = V_60 ;
if ( V_26 -> V_388 == V_29 ) {
struct V_28 * V_394 ;
if ( V_29 == V_47 ) {
V_394 = F_48 ( V_26 ) ;
} else {
V_394 = F_49 ( V_29 ) ;
if ( ! V_394 || ( V_47 && F_37 ( V_47 , V_394 ) ) )
V_394 = V_47 ;
}
if ( V_394 && F_283 ( V_394 , V_60 ) < 1 )
V_29 = V_394 ;
}
if ( V_26 -> V_62 && F_283 ( V_26 -> V_62 , V_60 ) < 1 )
V_29 = V_26 -> V_62 ;
if ( V_26 -> V_61 && F_283 ( V_26 -> V_61 , V_60 ) < 1 )
V_29 = V_26 -> V_61 ;
F_276 ( V_26 , V_29 ) ;
return V_29 ;
}
static void F_284 ( struct V_26 * V_26 , struct V_28 * V_357 )
{
if ( V_357 -> V_48 )
F_66 ( V_26 ) ;
F_285 ( V_26 ) ;
F_260 ( V_26 , V_357 ) ;
if ( V_357 -> V_48 ) {
F_76 ( V_26 , V_357 ) ;
F_42 ( V_26 , V_357 ) ;
F_249 ( V_357 , 0 ) ;
}
V_26 -> V_47 = NULL ;
}
static void
F_286 ( struct V_26 * V_26 , struct V_28 * V_47 , int V_395 )
{
F_66 ( V_26 ) ;
F_249 ( V_47 , V_375 ) ;
F_219 ( V_47 ) ;
#ifdef F_287
if ( V_395 ) {
F_280 ( F_17 ( V_26 ) ) ;
return;
}
if ( ! F_234 ( V_396 ) &&
F_288 ( & F_17 ( V_26 ) -> V_397 ) )
return;
#endif
if ( V_26 -> V_75 > 1 )
F_279 ( V_26 , V_47 ) ;
}
static inline bool F_289 ( void )
{
return F_290 ( & V_398 ) ;
}
void F_291 ( void )
{
F_292 ( & V_398 ) ;
}
void F_293 ( void )
{
F_294 ( & V_398 ) ;
}
static bool F_289 ( void )
{
return true ;
}
void F_291 ( void ) {}
void F_293 ( void ) {}
static inline T_2 F_295 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_296 ( void )
{
return ( T_2 ) V_399 * V_400 ;
}
void F_297 ( struct V_401 * V_402 )
{
T_2 V_92 ;
if ( V_402 -> V_403 == V_404 )
return;
V_92 = F_298 ( F_299 () ) ;
V_402 -> V_240 = V_402 -> V_403 ;
V_402 -> V_405 = V_92 + F_300 ( V_402 -> V_239 ) ;
}
static inline struct V_401 * F_301 ( struct V_334 * V_34 )
{
return & V_34 -> V_401 ;
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
if ( F_14 ( V_26 -> V_406 ) )
return V_26 -> V_407 - V_26 -> V_408 ;
return F_67 ( F_17 ( V_26 ) ) - V_26 -> V_408 ;
}
static int F_302 ( struct V_26 * V_26 )
{
struct V_334 * V_34 = V_26 -> V_34 ;
struct V_401 * V_402 = F_301 ( V_34 ) ;
T_2 V_409 = 0 , V_410 , V_411 ;
V_410 = F_296 () - V_26 -> V_412 ;
F_303 ( & V_402 -> V_257 ) ;
if ( V_402 -> V_403 == V_404 )
V_409 = V_410 ;
else {
F_304 ( V_402 ) ;
if ( V_402 -> V_240 > 0 ) {
V_409 = F_154 ( V_402 -> V_240 , V_410 ) ;
V_402 -> V_240 -= V_409 ;
V_402 -> V_413 = 0 ;
}
}
V_411 = V_402 -> V_405 ;
F_305 ( & V_402 -> V_257 ) ;
V_26 -> V_412 += V_409 ;
if ( ( T_3 ) ( V_411 - V_26 -> V_405 ) > 0 )
V_26 -> V_405 = V_411 ;
return V_26 -> V_412 > 0 ;
}
static void F_306 ( struct V_26 * V_26 )
{
struct V_401 * V_402 = F_301 ( V_26 -> V_34 ) ;
if ( F_12 ( ( T_3 ) ( F_78 ( F_17 ( V_26 ) ) - V_26 -> V_405 ) < 0 ) )
return;
if ( V_26 -> V_412 < 0 )
return;
if ( V_26 -> V_405 != V_402 -> V_405 ) {
V_26 -> V_405 += V_307 ;
} else {
V_26 -> V_412 = 0 ;
}
}
static void F_307 ( struct V_26 * V_26 , T_2 V_20 )
{
V_26 -> V_412 -= V_20 ;
F_306 ( V_26 ) ;
if ( F_12 ( V_26 -> V_412 > 0 ) )
return;
if ( ! F_302 ( V_26 ) && F_12 ( V_26 -> V_47 ) )
F_280 ( F_17 ( V_26 ) ) ;
}
static T_10
void F_74 ( struct V_26 * V_26 , T_2 V_20 )
{
if ( ! F_289 () || ! V_26 -> V_414 )
return;
F_307 ( V_26 , V_20 ) ;
}
static inline int F_308 ( struct V_26 * V_26 )
{
return F_289 () && V_26 -> V_415 ;
}
static inline int F_220 ( struct V_26 * V_26 )
{
return F_289 () && V_26 -> V_406 ;
}
static inline int F_309 ( struct V_334 * V_34 ,
int V_201 , int V_416 )
{
struct V_26 * V_417 , * V_418 ;
V_417 = V_34 -> V_26 [ V_201 ] ;
V_418 = V_34 -> V_26 [ V_416 ] ;
return F_220 ( V_417 ) ||
F_220 ( V_418 ) ;
}
static int F_310 ( struct V_334 * V_34 , void * V_419 )
{
struct V_25 * V_25 = V_419 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
V_26 -> V_406 -- ;
if ( ! V_26 -> V_406 ) {
V_26 -> V_408 += F_67 ( V_25 ) -
V_26 -> V_407 ;
}
return 0 ;
}
static int F_311 ( struct V_334 * V_34 , void * V_419 )
{
struct V_25 * V_25 = V_419 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_406 )
V_26 -> V_407 = F_67 ( V_25 ) ;
V_26 -> V_406 ++ ;
return 0 ;
}
static void F_312 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_401 * V_402 = F_301 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
long V_420 , V_421 = 1 ;
bool V_422 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( F_17 ( V_26 ) ) ] ;
F_134 () ;
F_313 ( V_26 -> V_34 , F_311 , V_423 , ( void * ) V_25 ) ;
F_142 () ;
V_420 = V_26 -> V_424 ;
F_59 (se) {
struct V_26 * V_425 = F_23 ( V_29 ) ;
if ( ! V_29 -> V_48 )
break;
if ( V_421 )
F_277 ( V_425 , V_29 , V_117 ) ;
V_425 -> V_424 -= V_420 ;
if ( V_425 -> V_73 . V_5 )
V_421 = 0 ;
}
if ( ! V_29 )
F_314 ( V_25 , V_420 ) ;
V_26 -> V_415 = 1 ;
V_26 -> V_426 = F_78 ( V_25 ) ;
F_303 ( & V_402 -> V_257 ) ;
V_422 = F_315 ( & V_402 -> V_427 ) ;
F_28 ( & V_26 -> V_428 , & V_402 -> V_427 ) ;
if ( V_422 )
F_304 ( V_402 ) ;
F_305 ( & V_402 -> V_257 ) ;
}
void F_316 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_401 * V_402 = F_301 ( V_26 -> V_34 ) ;
struct V_28 * V_29 ;
int V_429 = 1 ;
long V_420 ;
V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
V_26 -> V_415 = 0 ;
F_317 ( V_25 ) ;
F_303 ( & V_402 -> V_257 ) ;
V_402 -> V_430 += F_78 ( V_25 ) - V_26 -> V_426 ;
F_30 ( & V_26 -> V_428 ) ;
F_305 ( & V_402 -> V_257 ) ;
F_313 ( V_26 -> V_34 , V_423 , F_310 , ( void * ) V_25 ) ;
if ( ! V_26 -> V_73 . V_5 )
return;
V_420 = V_26 -> V_424 ;
F_59 (se) {
if ( V_29 -> V_48 )
V_429 = 0 ;
V_26 = F_23 ( V_29 ) ;
if ( V_429 )
F_271 ( V_26 , V_29 , V_116 ) ;
V_26 -> V_424 += V_420 ;
if ( F_308 ( V_26 ) )
break;
}
if ( ! V_29 )
F_318 ( V_25 , V_420 ) ;
if ( V_25 -> V_47 == V_25 -> V_413 && V_25 -> V_42 . V_75 )
F_280 ( V_25 ) ;
}
static T_2 F_319 ( struct V_401 * V_402 ,
T_2 V_431 , T_2 V_411 )
{
struct V_26 * V_26 ;
T_2 V_240 ;
T_2 V_432 = V_431 ;
F_134 () ;
F_320 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_378 V_379 ;
F_321 ( V_25 , & V_379 ) ;
if ( ! F_308 ( V_26 ) )
goto V_61;
V_240 = - V_26 -> V_412 + 1 ;
if ( V_240 > V_431 )
V_240 = V_431 ;
V_431 -= V_240 ;
V_26 -> V_412 += V_240 ;
V_26 -> V_405 = V_411 ;
if ( V_26 -> V_412 > 0 )
F_316 ( V_26 ) ;
V_61:
F_322 ( V_25 , & V_379 ) ;
if ( ! V_431 )
break;
}
F_142 () ;
return V_432 - V_431 ;
}
static int F_323 ( struct V_401 * V_402 , int V_433 )
{
T_2 V_240 , V_405 ;
int V_415 ;
if ( V_402 -> V_403 == V_404 )
goto V_434;
V_415 = ! F_315 ( & V_402 -> V_427 ) ;
V_402 -> V_435 += V_433 ;
if ( V_402 -> V_413 && ! V_415 )
goto V_434;
F_297 ( V_402 ) ;
if ( ! V_415 ) {
V_402 -> V_413 = 1 ;
return 0 ;
}
V_402 -> V_436 += V_433 ;
V_405 = V_402 -> V_405 ;
while ( V_415 && V_402 -> V_240 > 0 ) {
V_240 = V_402 -> V_240 ;
F_305 ( & V_402 -> V_257 ) ;
V_240 = F_319 ( V_402 , V_240 ,
V_405 ) ;
F_303 ( & V_402 -> V_257 ) ;
V_415 = ! F_315 ( & V_402 -> V_427 ) ;
V_402 -> V_240 -= F_154 ( V_240 , V_402 -> V_240 ) ;
}
V_402 -> V_413 = 0 ;
return 0 ;
V_434:
return 1 ;
}
static int F_324 ( struct V_401 * V_402 , T_2 V_437 )
{
struct V_438 * V_439 = & V_402 -> V_440 ;
T_2 V_431 ;
if ( F_325 ( V_439 ) )
return 1 ;
V_431 = F_300 ( F_326 ( V_439 ) ) ;
if ( V_431 < V_437 )
return 1 ;
return 0 ;
}
static void F_327 ( struct V_401 * V_402 )
{
T_2 V_441 = V_442 + V_443 ;
if ( F_324 ( V_402 , V_441 ) )
return;
F_328 ( & V_402 -> V_444 ,
F_329 ( V_442 ) ,
V_445 ) ;
}
static void F_330 ( struct V_26 * V_26 )
{
struct V_401 * V_402 = F_301 ( V_26 -> V_34 ) ;
T_3 V_446 = V_26 -> V_412 - V_447 ;
if ( V_446 <= 0 )
return;
F_303 ( & V_402 -> V_257 ) ;
if ( V_402 -> V_403 != V_404 &&
V_26 -> V_405 == V_402 -> V_405 ) {
V_402 -> V_240 += V_446 ;
if ( V_402 -> V_240 > F_296 () &&
! F_315 ( & V_402 -> V_427 ) )
F_327 ( V_402 ) ;
}
F_305 ( & V_402 -> V_257 ) ;
V_26 -> V_412 -= V_446 ;
}
static T_10 void F_278 ( struct V_26 * V_26 )
{
if ( ! F_289 () )
return;
if ( ! V_26 -> V_414 || V_26 -> V_75 )
return;
F_330 ( V_26 ) ;
}
static void F_331 ( struct V_401 * V_402 )
{
T_2 V_240 = 0 , V_76 = F_296 () ;
T_2 V_411 ;
F_303 ( & V_402 -> V_257 ) ;
if ( F_324 ( V_402 , V_443 ) ) {
F_305 ( & V_402 -> V_257 ) ;
return;
}
if ( V_402 -> V_403 != V_404 && V_402 -> V_240 > V_76 )
V_240 = V_402 -> V_240 ;
V_411 = V_402 -> V_405 ;
F_305 ( & V_402 -> V_257 ) ;
if ( ! V_240 )
return;
V_240 = F_319 ( V_402 , V_240 , V_411 ) ;
F_303 ( & V_402 -> V_257 ) ;
if ( V_411 == V_402 -> V_405 )
V_402 -> V_240 -= F_154 ( V_240 , V_402 -> V_240 ) ;
F_305 ( & V_402 -> V_257 ) ;
}
static void F_272 ( struct V_26 * V_26 )
{
if ( ! F_289 () )
return;
if ( ! V_26 -> V_414 || V_26 -> V_47 )
return;
if ( F_308 ( V_26 ) )
return;
F_74 ( V_26 , 0 ) ;
if ( V_26 -> V_412 <= 0 )
F_312 ( V_26 ) ;
}
static void F_332 ( struct V_334 * V_34 , int V_1 )
{
struct V_26 * V_448 , * V_26 ;
if ( ! F_289 () )
return;
if ( ! V_34 -> V_35 )
return;
V_26 = V_34 -> V_26 [ V_1 ] ;
V_448 = V_34 -> V_35 -> V_26 [ V_1 ] ;
V_26 -> V_406 = V_448 -> V_406 ;
V_26 -> V_407 = F_67 ( F_124 ( V_1 ) ) ;
}
static bool F_285 ( struct V_26 * V_26 )
{
if ( ! F_289 () )
return false ;
if ( F_12 ( ! V_26 -> V_414 || V_26 -> V_412 > 0 ) )
return false ;
if ( F_308 ( V_26 ) )
return true ;
F_312 ( V_26 ) ;
return true ;
}
static enum V_449 F_333 ( struct V_438 * V_450 )
{
struct V_401 * V_402 =
F_21 ( V_450 , struct V_401 , V_444 ) ;
F_331 ( V_402 ) ;
return V_451 ;
}
static enum V_449 F_334 ( struct V_438 * V_450 )
{
struct V_401 * V_402 =
F_21 ( V_450 , struct V_401 , V_440 ) ;
int V_433 ;
int V_413 = 0 ;
F_303 ( & V_402 -> V_257 ) ;
for (; ; ) {
V_433 = F_335 ( V_450 , V_402 -> V_239 ) ;
if ( ! V_433 )
break;
V_413 = F_323 ( V_402 , V_433 ) ;
}
if ( V_413 )
V_402 -> V_452 = 0 ;
F_305 ( & V_402 -> V_257 ) ;
return V_413 ? V_451 : V_453 ;
}
void F_336 ( struct V_401 * V_402 )
{
F_337 ( & V_402 -> V_257 ) ;
V_402 -> V_240 = 0 ;
V_402 -> V_403 = V_404 ;
V_402 -> V_239 = F_329 ( F_295 () ) ;
F_338 ( & V_402 -> V_427 ) ;
F_339 ( & V_402 -> V_440 , V_454 , V_455 ) ;
V_402 -> V_440 . V_456 = F_334 ;
F_339 ( & V_402 -> V_444 , V_454 , V_445 ) ;
V_402 -> V_444 . V_456 = F_333 ;
}
static void F_340 ( struct V_26 * V_26 )
{
V_26 -> V_414 = 0 ;
F_338 ( & V_26 -> V_428 ) ;
}
void F_304 ( struct V_401 * V_402 )
{
F_341 ( & V_402 -> V_257 ) ;
if ( ! V_402 -> V_452 ) {
V_402 -> V_452 = 1 ;
F_335 ( & V_402 -> V_440 , V_402 -> V_239 ) ;
F_342 ( & V_402 -> V_440 , V_455 ) ;
}
}
static void F_343 ( struct V_401 * V_402 )
{
if ( ! V_402 -> V_427 . V_61 )
return;
F_344 ( & V_402 -> V_440 ) ;
F_344 ( & V_402 -> V_444 ) ;
}
static void T_11 F_345 ( struct V_25 * V_25 )
{
struct V_334 * V_34 ;
F_341 ( & V_25 -> V_257 ) ;
F_134 () ;
F_320 (tg, &task_groups, list) {
struct V_401 * V_402 = & V_34 -> V_401 ;
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
F_303 ( & V_402 -> V_257 ) ;
V_26 -> V_414 = V_402 -> V_403 != V_404 ;
F_305 ( & V_402 -> V_257 ) ;
}
F_142 () ;
}
static void T_11 F_346 ( struct V_25 * V_25 )
{
struct V_334 * V_34 ;
F_341 ( & V_25 -> V_257 ) ;
F_134 () ;
F_320 (tg, &task_groups, list) {
struct V_26 * V_26 = V_34 -> V_26 [ F_26 ( V_25 ) ] ;
if ( ! V_26 -> V_414 )
continue;
V_26 -> V_412 = 1 ;
V_26 -> V_414 = 0 ;
if ( F_308 ( V_26 ) )
F_316 ( V_26 ) ;
}
F_142 () ;
}
static inline T_2 F_63 ( struct V_26 * V_26 )
{
return F_67 ( F_17 ( V_26 ) ) ;
}
static void F_74 ( struct V_26 * V_26 , T_2 V_20 ) {}
static bool F_285 ( struct V_26 * V_26 ) { return false ; }
static void F_272 ( struct V_26 * V_26 ) {}
static inline void F_332 ( struct V_334 * V_34 , int V_1 ) {}
static T_10 void F_278 ( struct V_26 * V_26 ) {}
static inline int F_308 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_220 ( struct V_26 * V_26 )
{
return 0 ;
}
static inline int F_309 ( struct V_334 * V_34 ,
int V_201 , int V_416 )
{
return 0 ;
}
void F_336 ( struct V_401 * V_402 ) {}
static void F_340 ( struct V_26 * V_26 ) {}
static inline struct V_401 * F_301 ( struct V_334 * V_34 )
{
return NULL ;
}
static inline void F_343 ( struct V_401 * V_402 ) {}
static inline void F_345 ( struct V_25 * V_25 ) {}
static inline void F_346 ( struct V_25 * V_25 ) {}
static void F_347 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_19 ( F_34 ( V_30 ) != V_25 ) ;
if ( V_25 -> V_42 . V_424 > 1 ) {
T_2 V_76 = F_58 ( V_26 , V_29 ) ;
T_2 V_457 = V_29 -> V_96 - V_29 -> V_392 ;
T_3 V_44 = V_76 - V_457 ;
if ( V_44 < 0 ) {
if ( V_25 -> V_47 == V_30 )
F_280 ( V_25 ) ;
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
F_352 ( V_25 , V_458 ) ;
F_59 (se) {
if ( V_29 -> V_48 )
break;
V_26 = F_23 ( V_29 ) ;
F_271 ( V_26 , V_29 , V_115 ) ;
if ( F_308 ( V_26 ) )
break;
V_26 -> V_424 ++ ;
V_115 = V_116 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_424 ++ ;
if ( F_308 ( V_26 ) )
break;
F_249 ( V_29 , V_375 ) ;
F_219 ( V_29 ) ;
}
if ( ! V_29 )
F_318 ( V_25 , 1 ) ;
F_349 ( V_25 ) ;
}
static void F_353 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_115 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 ;
int V_459 = V_115 & V_117 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_277 ( V_26 , V_29 , V_115 ) ;
if ( F_308 ( V_26 ) )
break;
V_26 -> V_424 -- ;
if ( V_26 -> V_73 . V_5 ) {
V_29 = F_32 ( V_29 ) ;
if ( V_459 && V_29 && ! F_220 ( V_26 ) )
F_354 ( V_29 ) ;
break;
}
V_115 |= V_117 ;
}
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_424 -- ;
if ( F_308 ( V_26 ) )
break;
F_249 ( V_29 , V_375 ) ;
F_219 ( V_29 ) ;
}
if ( ! V_29 )
F_314 ( V_25 , 1 ) ;
F_349 ( V_25 ) ;
}
static unsigned long
F_355 ( unsigned long V_73 , unsigned long V_460 , int V_461 )
{
int V_462 = 0 ;
if ( ! V_460 )
return V_73 ;
if ( V_460 >= V_463 [ V_461 ] )
return 0 ;
if ( V_461 == 1 )
return V_73 >> V_460 ;
while ( V_460 ) {
if ( V_460 % 2 )
V_73 = ( V_73 * V_464 [ V_461 ] [ V_462 ] ) >> V_465 ;
V_460 >>= 1 ;
V_462 ++ ;
}
return V_73 ;
}
static void F_356 ( struct V_25 * F_244 , unsigned long V_327 ,
unsigned long V_466 )
{
unsigned long T_11 V_467 = F_244 -> V_468 [ 0 ] ;
int V_272 , V_469 ;
F_244 -> V_470 ++ ;
F_244 -> V_468 [ 0 ] = V_327 ;
for ( V_272 = 1 , V_469 = 2 ; V_272 < V_471 ; V_272 ++ , V_469 += V_469 ) {
unsigned long V_472 , V_473 ;
V_472 = F_244 -> V_468 [ V_272 ] ;
#ifdef F_357
V_472 = F_355 ( V_472 , V_466 - 1 , V_272 ) ;
if ( V_467 ) {
V_472 -= F_355 ( V_467 , V_466 - 1 , V_272 ) ;
V_472 += V_467 ;
}
#endif
V_473 = V_327 ;
if ( V_473 > V_472 )
V_473 += V_469 - 1 ;
F_244 -> V_468 [ V_272 ] = ( V_472 * ( V_469 - 1 ) + V_473 ) >> V_272 ;
}
F_358 ( F_244 ) ;
}
static unsigned long F_125 ( const int V_1 )
{
return F_257 ( & F_124 ( V_1 ) -> V_42 ) ;
}
static void F_359 ( struct V_25 * F_244 ,
unsigned long V_474 ,
unsigned long V_73 )
{
unsigned long V_466 ;
V_466 = V_474 - F_244 -> V_475 ;
if ( V_466 ) {
F_244 -> V_475 = V_474 ;
F_356 ( F_244 , V_73 , V_466 ) ;
}
}
static void F_360 ( struct V_25 * F_244 )
{
if ( F_125 ( F_26 ( F_244 ) ) )
return;
F_359 ( F_244 , F_98 ( V_224 ) , 0 ) ;
}
void F_361 ( void )
{
struct V_25 * F_244 = F_244 () ;
F_244 -> V_468 [ 0 ] = F_125 ( F_26 ( F_244 ) ) ;
}
void F_362 ( void )
{
unsigned long V_474 = F_98 ( V_224 ) ;
struct V_25 * F_244 = F_244 () ;
unsigned long V_73 ;
struct V_378 V_379 ;
if ( V_474 == F_244 -> V_475 )
return;
V_73 = F_125 ( F_26 ( F_244 ) ) ;
F_321 ( F_244 , & V_379 ) ;
F_317 ( F_244 ) ;
F_359 ( F_244 , V_474 , V_73 ) ;
F_322 ( F_244 , & V_379 ) ;
}
static inline void F_359 ( struct V_25 * F_244 ,
unsigned long V_474 ,
unsigned long V_73 ) { }
static void F_363 ( struct V_25 * F_244 , unsigned long V_73 )
{
#ifdef F_357
F_244 -> V_475 = F_98 ( V_224 ) ;
#endif
F_356 ( F_244 , V_73 , 1 ) ;
}
void F_364 ( struct V_25 * F_244 )
{
unsigned long V_73 = F_125 ( F_26 ( F_244 ) ) ;
if ( F_365 () )
F_359 ( F_244 , F_98 ( V_224 ) , V_73 ) ;
else
F_363 ( F_244 , V_73 ) ;
}
static unsigned long F_366 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_476 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_234 ( V_477 ) )
return V_476 ;
return F_154 ( V_25 -> V_468 [ type - 1 ] , V_476 ) ;
}
static unsigned long F_367 ( int V_1 , int type )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_476 = F_125 ( V_1 ) ;
if ( type == 0 || ! F_234 ( V_477 ) )
return V_476 ;
return F_69 ( V_25 -> V_468 [ type - 1 ] , V_476 ) ;
}
static unsigned long F_126 ( int V_1 )
{
return F_124 ( V_1 ) -> V_478 ;
}
static unsigned long F_368 ( int V_1 )
{
return F_124 ( V_1 ) -> V_479 ;
}
static unsigned long F_369 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
unsigned long V_75 = F_98 ( V_25 -> V_42 . V_424 ) ;
unsigned long V_82 = F_125 ( V_1 ) ;
if ( V_75 )
return V_82 / V_75 ;
return 0 ;
}
static void F_370 ( struct V_27 * V_30 )
{
if ( F_192 ( V_224 , V_172 -> V_480 + V_222 ) ) {
V_172 -> V_481 >>= 1 ;
V_172 -> V_480 = V_224 ;
}
if ( V_172 -> V_482 != V_30 ) {
V_172 -> V_482 = V_30 ;
V_172 -> V_481 ++ ;
}
}
static int F_371 ( struct V_27 * V_30 )
{
unsigned int V_483 = V_172 -> V_481 ;
unsigned int V_484 = V_30 -> V_481 ;
int V_10 = F_372 ( V_485 ) ;
if ( V_483 < V_484 )
F_132 ( V_483 , V_484 ) ;
if ( V_484 < V_10 || V_483 < V_484 * V_10 )
return 0 ;
return 1 ;
}
static int F_373 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_324 , int V_325 )
{
int V_323 = F_299 () ;
bool V_486 = false ;
if ( F_374 ( V_324 , V_323 ) )
V_486 = true ;
else
V_486 = F_210 ( V_213 , V_30 , V_323 , V_324 , V_325 ) ;
F_83 ( V_30 -> V_29 . V_94 . V_487 ) ;
if ( V_486 ) {
F_83 ( V_213 -> V_488 ) ;
F_83 ( V_30 -> V_29 . V_94 . V_489 ) ;
}
return V_486 ;
}
static unsigned long F_375 ( int V_1 , struct V_27 * V_30 )
{
return F_368 ( V_1 ) - F_376 ( V_1 , V_30 ) ;
}
static struct V_490 *
F_377 ( struct V_212 * V_213 , struct V_27 * V_30 ,
int V_323 , int V_491 )
{
struct V_490 * V_492 = NULL , * V_148 = V_213 -> V_493 ;
struct V_490 * V_494 = NULL ;
unsigned long V_495 = V_496 , V_497 = 0 ;
unsigned long V_498 = V_496 , V_499 = 0 ;
unsigned long V_500 = 0 , V_501 = 0 ;
int V_502 = V_213 -> V_503 ;
int V_504 = 100 + ( V_213 -> V_197 - 100 ) / 2 ;
unsigned long V_505 = F_13 ( V_74 ) *
( V_213 -> V_197 - 100 ) / 100 ;
if ( V_491 & V_506 )
V_502 = V_213 -> V_507 ;
do {
unsigned long V_73 , V_508 , V_509 ;
unsigned long V_510 , V_511 ;
int V_512 ;
int V_272 ;
if ( ! F_378 ( F_379 ( V_148 ) ,
& V_30 -> V_207 ) )
continue;
V_512 = F_137 ( V_323 ,
F_379 ( V_148 ) ) ;
V_508 = 0 ;
V_509 = 0 ;
V_511 = 0 ;
F_123 (i, sched_group_span(group)) {
if ( V_512 )
V_73 = F_366 ( V_272 , V_502 ) ;
else
V_73 = F_367 ( V_272 , V_502 ) ;
V_509 += V_73 ;
V_508 += F_258 ( & F_124 ( V_272 ) -> V_42 ) ;
V_510 = F_375 ( V_272 , V_30 ) ;
if ( V_510 > V_511 )
V_511 = V_510 ;
}
V_508 = ( V_508 * V_88 ) /
V_148 -> V_513 -> V_177 ;
V_509 = ( V_509 * V_88 ) /
V_148 -> V_513 -> V_177 ;
if ( V_512 ) {
V_497 = V_509 ;
V_499 = V_508 ;
V_501 = V_511 ;
} else {
if ( V_495 > ( V_509 + V_505 ) ) {
V_495 = V_509 ;
V_498 = V_508 ;
V_492 = V_148 ;
} else if ( ( V_509 < ( V_495 + V_505 ) ) &&
( 100 * V_498 > V_504 * V_508 ) ) {
V_498 = V_508 ;
V_492 = V_148 ;
}
if ( V_500 < V_511 ) {
V_500 = V_511 ;
V_494 = V_148 ;
}
}
} while ( V_148 = V_148 -> V_61 , V_148 != V_213 -> V_493 );
if ( V_491 & V_514 )
goto V_515;
if ( V_501 > F_380 ( V_30 ) / 2 &&
V_504 * V_501 > 100 * V_500 )
return NULL ;
if ( V_500 > F_380 ( V_30 ) / 2 )
return V_494 ;
V_515:
if ( ! V_492 )
return NULL ;
if ( V_495 > ( V_497 + V_505 ) )
return NULL ;
if ( ( V_497 < ( V_495 + V_505 ) ) &&
( 100 * V_499 < V_504 * V_498 ) )
return NULL ;
return V_492 ;
}
static int
F_381 ( struct V_490 * V_148 , struct V_27 * V_30 , int V_323 )
{
unsigned long V_73 , V_516 = V_496 ;
unsigned int V_517 = V_518 ;
T_2 V_519 = 0 ;
int V_520 = V_323 ;
int V_521 = - 1 ;
int V_272 ;
if ( V_148 -> F_114 == 1 )
return F_382 ( F_379 ( V_148 ) ) ;
F_383 (i, sched_group_span(group), &p->cpus_allowed) {
if ( F_384 ( V_272 ) ) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_522 * V_413 = F_385 ( V_25 ) ;
if ( V_413 && V_413 -> V_523 < V_517 ) {
V_517 = V_413 -> V_523 ;
V_519 = V_25 -> V_524 ;
V_521 = V_272 ;
} else if ( ( ! V_413 || V_413 -> V_523 == V_517 ) &&
V_25 -> V_524 > V_519 ) {
V_519 = V_25 -> V_524 ;
V_521 = V_272 ;
}
} else if ( V_521 == - 1 ) {
V_73 = F_125 ( V_272 ) ;
if ( V_73 < V_516 || ( V_73 == V_516 && V_272 == V_323 ) ) {
V_516 = V_73 ;
V_520 = V_272 ;
}
}
}
return V_521 != - 1 ? V_521 : V_520 ;
}
static inline void F_386 ( int V_1 , int V_339 )
{
struct V_525 * V_526 ;
V_526 = F_147 ( F_148 ( V_527 , V_1 ) ) ;
if ( V_526 )
F_194 ( V_526 -> V_528 , V_339 ) ;
}
static inline bool F_387 ( int V_1 , bool V_529 )
{
struct V_525 * V_526 ;
V_526 = F_147 ( F_148 ( V_527 , V_1 ) ) ;
if ( V_526 )
return F_98 ( V_526 -> V_528 ) ;
return V_529 ;
}
void F_388 ( struct V_25 * V_25 )
{
int V_530 = F_26 ( V_25 ) ;
int V_1 ;
F_134 () ;
if ( F_387 ( V_530 , true ) )
goto V_206;
F_123 (cpu, cpu_smt_mask(core)) {
if ( V_1 == V_530 )
continue;
if ( ! F_384 ( V_1 ) )
goto V_206;
}
F_386 ( V_530 , 1 ) ;
V_206:
F_142 () ;
}
static int F_389 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_531 )
{
struct V_532 * V_9 = F_390 ( V_533 ) ;
int V_530 , V_1 ;
if ( ! F_191 ( & V_534 ) )
return - 1 ;
if ( ! F_387 ( V_531 , false ) )
return - 1 ;
F_391 ( V_9 , F_392 ( V_213 ) , & V_30 -> V_207 ) ;
F_393 (core, cpus, target) {
bool V_413 = true ;
F_123 (cpu, cpu_smt_mask(core)) {
F_394 ( V_1 , V_9 ) ;
if ( ! F_384 ( V_1 ) )
V_413 = false ;
}
if ( V_413 )
return V_530 ;
}
F_386 ( V_531 , 0 ) ;
return - 1 ;
}
static int F_395 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_531 )
{
int V_1 ;
if ( ! F_191 ( & V_534 ) )
return - 1 ;
F_123 (cpu, cpu_smt_mask(target)) {
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_384 ( V_1 ) )
return V_1 ;
}
return - 1 ;
}
static inline int F_389 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_531 )
{
return - 1 ;
}
static inline int F_395 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_531 )
{
return - 1 ;
}
static int F_396 ( struct V_27 * V_30 , struct V_212 * V_213 , int V_531 )
{
struct V_212 * V_535 ;
T_2 V_536 , V_537 ;
T_2 time , V_538 ;
T_3 V_44 ;
int V_1 , V_539 = V_540 ;
V_535 = F_147 ( * F_397 ( & V_541 ) ) ;
if ( ! V_535 )
return - 1 ;
V_537 = F_244 () -> V_537 / 512 ;
V_536 = V_535 -> V_542 + 1 ;
if ( F_234 ( V_543 ) && V_537 < V_536 )
return - 1 ;
if ( F_234 ( V_544 ) ) {
T_2 V_545 = V_213 -> V_546 * V_537 ;
if ( V_545 > 4 * V_536 )
V_539 = F_228 ( V_545 , V_536 ) ;
else
V_539 = 4 ;
}
time = F_398 () ;
F_393 (cpu, sched_domain_span(sd), target) {
if ( ! -- V_539 )
return - 1 ;
if ( ! F_137 ( V_1 , & V_30 -> V_207 ) )
continue;
if ( F_384 ( V_1 ) )
break;
}
time = F_398 () - time ;
V_538 = V_535 -> V_542 ;
V_44 = ( T_3 ) ( time - V_538 ) / 8 ;
V_535 -> V_542 += V_44 ;
return V_1 ;
}
static int F_140 ( struct V_27 * V_30 , int V_357 , int V_531 )
{
struct V_212 * V_213 ;
int V_272 ;
if ( F_384 ( V_531 ) )
return V_531 ;
if ( V_357 != V_531 && F_374 ( V_357 , V_531 ) && F_384 ( V_357 ) )
return V_357 ;
V_213 = F_147 ( F_148 ( V_541 , V_531 ) ) ;
if ( ! V_213 )
return V_531 ;
V_272 = F_389 ( V_30 , V_213 , V_531 ) ;
if ( ( unsigned ) V_272 < V_547 )
return V_272 ;
V_272 = F_396 ( V_30 , V_213 , V_531 ) ;
if ( ( unsigned ) V_272 < V_547 )
return V_272 ;
V_272 = F_395 ( V_30 , V_213 , V_531 ) ;
if ( ( unsigned ) V_272 < V_547 )
return V_272 ;
return V_531 ;
}
static int F_399 ( int V_1 )
{
unsigned long V_548 = F_124 ( V_1 ) -> V_42 . V_79 . V_85 ;
unsigned long V_177 = F_368 ( V_1 ) ;
return ( V_548 >= V_177 ) ? V_177 : V_548 ;
}
static inline int F_380 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_85 ;
}
static int F_376 ( int V_1 , struct V_27 * V_30 )
{
unsigned long V_548 , V_177 ;
if ( V_1 != F_146 ( V_30 ) || ! V_30 -> V_29 . V_79 . V_80 )
return F_399 ( V_1 ) ;
V_177 = F_368 ( V_1 ) ;
V_548 = F_99 ( long , F_124 ( V_1 ) -> V_42 . V_79 . V_85 - F_380 ( V_30 ) , 0 ) ;
return ( V_548 >= V_177 ) ? V_177 : V_548 ;
}
static int F_400 ( struct V_27 * V_30 , int V_1 , int V_324 )
{
long V_549 , V_550 ;
V_549 = F_154 ( F_368 ( V_324 ) , F_368 ( V_1 ) ) ;
V_550 = F_124 ( V_1 ) -> V_551 -> V_552 ;
if ( V_550 - V_549 < V_550 > > 3 )
return 0 ;
F_255 ( & V_30 -> V_29 ) ;
return V_549 * 1024 < F_380 ( V_30 ) * V_553 ;
}
static int
F_401 ( struct V_27 * V_30 , int V_324 , int V_491 , int V_554 )
{
struct V_212 * V_555 , * V_556 = NULL , * V_213 = NULL ;
int V_1 = F_299 () ;
int V_557 = V_324 ;
int V_558 = 0 ;
int V_325 = V_554 & V_559 ;
if ( V_491 & V_506 ) {
F_370 ( V_30 ) ;
V_558 = ! F_371 ( V_30 ) && ! F_400 ( V_30 , V_1 , V_324 )
&& F_137 ( V_1 , & V_30 -> V_207 ) ;
}
F_134 () ;
F_402 (cpu, tmp) {
if ( ! ( V_555 -> V_115 & V_560 ) )
break;
if ( V_558 && ( V_555 -> V_115 & V_561 ) &&
F_137 ( V_324 , F_392 ( V_555 ) ) ) {
V_556 = V_555 ;
break;
}
if ( V_555 -> V_115 & V_491 )
V_213 = V_555 ;
else if ( ! V_558 )
break;
}
if ( V_556 ) {
V_213 = NULL ;
if ( V_1 == V_324 )
goto V_562;
if ( F_373 ( V_556 , V_30 , V_324 , V_325 ) )
V_557 = V_1 ;
}
if ( ! V_213 ) {
V_562:
if ( V_491 & V_506 )
V_557 = F_140 ( V_30 , V_324 , V_557 ) ;
} else while ( V_213 ) {
struct V_490 * V_148 ;
int V_5 ;
if ( ! ( V_213 -> V_115 & V_491 ) ) {
V_213 = V_213 -> V_563 ;
continue;
}
V_148 = F_377 ( V_213 , V_30 , V_1 , V_491 ) ;
if ( ! V_148 ) {
V_213 = V_213 -> V_563 ;
continue;
}
V_557 = F_381 ( V_148 , V_30 , V_1 ) ;
if ( V_557 == - 1 || V_557 == V_1 ) {
V_213 = V_213 -> V_563 ;
continue;
}
V_1 = V_557 ;
V_5 = V_213 -> V_546 ;
V_213 = NULL ;
F_402 (cpu, tmp) {
if ( V_5 <= V_555 -> V_546 )
break;
if ( V_555 -> V_115 & V_491 )
V_213 = V_555 ;
}
}
F_142 () ;
return V_557 ;
}
static void F_403 ( struct V_27 * V_30 )
{
if ( V_30 -> V_118 == V_564 ) {
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
T_2 F_36 ;
#ifndef F_40
T_2 V_51 ;
do {
V_51 = V_26 -> V_51 ;
F_235 () ;
F_36 = V_26 -> F_36 ;
} while ( F_36 != V_51 );
#else
F_36 = V_26 -> F_36 ;
#endif
V_29 -> V_43 -= F_36 ;
}
F_256 ( & V_30 -> V_29 ) ;
V_30 -> V_29 . V_79 . V_80 = 0 ;
V_30 -> V_29 . V_93 = 0 ;
}
static void F_404 ( struct V_27 * V_30 )
{
F_256 ( & V_30 -> V_29 ) ;
}
static unsigned long
F_405 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
unsigned long V_565 = V_566 ;
return F_56 ( V_565 , V_29 ) ;
}
static int
F_283 ( struct V_28 * V_47 , struct V_28 * V_29 )
{
T_3 V_565 , V_567 = V_47 -> V_43 - V_29 -> V_43 ;
if ( V_567 <= 0 )
return - 1 ;
V_565 = F_405 ( V_47 , V_29 ) ;
if ( V_567 > V_565 )
return 1 ;
return 0 ;
}
static void F_406 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_568 == V_569 ) )
return;
F_59 (se) {
if ( F_19 ( ! V_29 -> V_48 ) )
return;
F_23 ( V_29 ) -> V_62 = V_29 ;
}
}
static void F_354 ( struct V_28 * V_29 )
{
if ( F_20 ( V_29 ) && F_14 ( F_18 ( V_29 ) -> V_568 == V_569 ) )
return;
F_59 (se) {
if ( F_19 ( ! V_29 -> V_48 ) )
return;
F_23 ( V_29 ) -> V_61 = V_29 ;
}
}
static void F_407 ( struct V_28 * V_29 )
{
F_59 (se)
F_23 ( V_29 ) -> V_388 = V_29 ;
}
static void F_408 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_554 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_28 * V_29 = & V_47 -> V_29 , * V_38 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
int V_469 = V_26 -> V_75 >= V_70 ;
int V_570 = 0 ;
if ( F_14 ( V_29 == V_38 ) )
return;
if ( F_14 ( F_220 ( F_23 ( V_38 ) ) ) )
return;
if ( F_234 ( V_571 ) && V_469 && ! ( V_554 & V_572 ) ) {
F_354 ( V_38 ) ;
V_570 = 1 ;
}
if ( F_409 ( V_47 ) )
return;
if ( F_14 ( V_47 -> V_568 == V_569 ) &&
F_12 ( V_30 -> V_568 != V_569 ) )
goto V_573;
if ( F_14 ( V_30 -> V_568 != V_574 ) || ! F_234 ( V_575 ) )
return;
F_33 ( & V_29 , & V_38 ) ;
F_66 ( F_23 ( V_29 ) ) ;
F_181 ( ! V_38 ) ;
if ( F_283 ( V_29 , V_38 ) == 1 ) {
if ( ! V_570 )
F_354 ( V_38 ) ;
goto V_573;
}
return;
V_573:
F_280 ( V_25 ) ;
if ( F_14 ( ! V_29 -> V_48 || V_47 == V_25 -> V_413 ) )
return;
if ( F_234 ( V_576 ) && V_469 && F_20 ( V_29 ) )
F_406 ( V_29 ) ;
}
static struct V_27 *
F_410 ( struct V_25 * V_25 , struct V_27 * V_357 , struct V_378 * V_379 )
{
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_28 * V_29 ;
struct V_27 * V_30 ;
int V_577 ;
V_578:
#ifdef F_411
if ( ! V_26 -> V_75 )
goto V_413;
if ( V_357 -> V_89 != & V_90 )
goto V_579;
do {
struct V_28 * V_47 = V_26 -> V_47 ;
if ( V_47 ) {
if ( V_47 -> V_48 )
F_66 ( V_26 ) ;
else
V_47 = NULL ;
if ( F_14 ( F_285 ( V_26 ) ) )
goto V_579;
}
V_29 = F_282 ( V_26 , V_47 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( V_357 != V_30 ) {
struct V_28 * V_38 = & V_357 -> V_29 ;
while ( ! ( V_26 = F_31 ( V_29 , V_38 ) ) ) {
int V_39 = V_29 -> V_41 ;
int V_40 = V_38 -> V_41 ;
if ( V_39 <= V_40 ) {
F_284 ( F_23 ( V_38 ) , V_38 ) ;
V_38 = F_32 ( V_38 ) ;
}
if ( V_39 >= V_40 ) {
F_281 ( F_23 ( V_29 ) , V_29 ) ;
V_29 = F_32 ( V_29 ) ;
}
}
F_284 ( V_26 , V_38 ) ;
F_281 ( V_26 , V_29 ) ;
}
if ( F_350 ( V_25 ) )
F_347 ( V_25 , V_30 ) ;
return V_30 ;
V_579:
V_26 = & V_25 -> V_42 ;
#endif
if ( ! V_26 -> V_75 )
goto V_413;
F_412 ( V_25 , V_357 ) ;
do {
V_29 = F_282 ( V_26 , NULL ) ;
F_281 ( V_26 , V_29 ) ;
V_26 = F_24 ( V_29 ) ;
} while ( V_26 );
V_30 = F_18 ( V_29 ) ;
if ( F_350 ( V_25 ) )
F_347 ( V_25 , V_30 ) ;
return V_30 ;
V_413:
V_577 = F_259 ( V_25 , V_379 ) ;
if ( V_577 < 0 )
return V_580 ;
if ( V_577 > 0 )
goto V_578;
return NULL ;
}
static void F_413 ( struct V_25 * V_25 , struct V_27 * V_357 )
{
struct V_28 * V_29 = & V_357 -> V_29 ;
struct V_26 * V_26 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_284 ( V_26 , V_29 ) ;
}
}
static void F_414 ( struct V_25 * V_25 )
{
struct V_27 * V_47 = V_25 -> V_47 ;
struct V_26 * V_26 = F_22 ( V_47 ) ;
struct V_28 * V_29 = & V_47 -> V_29 ;
if ( F_14 ( V_25 -> V_75 == 1 ) )
return;
F_276 ( V_26 , V_29 ) ;
if ( V_47 -> V_568 != V_581 ) {
F_317 ( V_25 ) ;
F_66 ( V_26 ) ;
F_415 ( V_25 , true ) ;
}
F_407 ( V_29 ) ;
}
static bool F_416 ( struct V_25 * V_25 , struct V_27 * V_30 , bool V_573 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( ! V_29 -> V_48 || F_220 ( F_23 ( V_29 ) ) )
return false ;
F_354 ( V_29 ) ;
F_414 ( V_25 ) ;
return true ;
}
static int F_417 ( struct V_27 * V_30 , struct V_582 * V_182 )
{
T_3 V_44 ;
F_341 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_30 -> V_89 != & V_90 )
return 0 ;
if ( F_14 ( V_30 -> V_568 == V_569 ) )
return 0 ;
if ( F_234 ( V_583 ) && V_182 -> V_202 -> V_75 &&
( & V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_61 ||
& V_30 -> V_29 == F_23 ( & V_30 -> V_29 ) -> V_62 ) )
return 1 ;
if ( V_584 == - 1 )
return 1 ;
if ( V_584 == 0 )
return 0 ;
V_44 = F_67 ( V_182 -> V_200 ) - V_30 -> V_29 . V_93 ;
return V_44 < ( T_3 ) V_584 ;
}
static int F_418 ( struct V_27 * V_30 , struct V_582 * V_182 )
{
struct V_137 * V_137 = F_147 ( V_30 -> V_137 ) ;
unsigned long V_585 , V_586 ;
int V_167 , V_169 ;
if ( ! F_191 ( & V_286 ) )
return - 1 ;
if ( ! V_30 -> V_145 || ! ( V_182 -> V_213 -> V_115 & V_587 ) )
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
if ( V_182 -> V_413 != V_588 )
return - 1 ;
if ( V_137 ) {
V_585 = F_107 ( V_30 , V_167 ) ;
V_586 = F_107 ( V_30 , V_169 ) ;
} else {
V_585 = F_106 ( V_30 , V_167 ) ;
V_586 = F_106 ( V_30 , V_169 ) ;
}
return V_586 < V_585 ;
}
static inline int F_418 ( struct V_27 * V_30 ,
struct V_582 * V_182 )
{
return - 1 ;
}
static
int F_419 ( struct V_27 * V_30 , struct V_582 * V_182 )
{
int V_589 ;
F_341 ( & V_182 -> V_200 -> V_257 ) ;
if ( F_309 ( V_334 ( V_30 ) , V_182 -> V_201 , V_182 -> V_168 ) )
return 0 ;
if ( ! F_137 ( V_182 -> V_168 , & V_30 -> V_207 ) ) {
int V_1 ;
F_83 ( V_30 -> V_29 . V_94 . V_590 ) ;
V_182 -> V_115 |= V_591 ;
if ( V_182 -> V_413 == V_592 || ( V_182 -> V_115 & V_593 ) )
return 0 ;
F_383 (cpu, env->dst_grpmask, env->cpus) {
if ( F_137 ( V_1 , & V_30 -> V_207 ) ) {
V_182 -> V_115 |= V_593 ;
V_182 -> V_594 = V_1 ;
break;
}
}
return 0 ;
}
V_182 -> V_115 &= ~ V_595 ;
if ( F_420 ( V_182 -> V_200 , V_30 ) ) {
F_83 ( V_30 -> V_29 . V_94 . V_596 ) ;
return 0 ;
}
V_589 = F_418 ( V_30 , V_182 ) ;
if ( V_589 == - 1 )
V_589 = F_417 ( V_30 , V_182 ) ;
if ( V_589 <= 0 ||
V_182 -> V_213 -> V_597 > V_182 -> V_213 -> V_598 ) {
if ( V_589 == 1 ) {
F_83 ( V_182 -> V_213 -> V_599 [ V_182 -> V_413 ] ) ;
F_83 ( V_30 -> V_29 . V_94 . V_600 ) ;
}
return 1 ;
}
F_83 ( V_30 -> V_29 . V_94 . V_601 ) ;
return 0 ;
}
static void F_421 ( struct V_27 * V_30 , struct V_582 * V_182 )
{
F_341 ( & V_182 -> V_200 -> V_257 ) ;
V_30 -> V_48 = V_602 ;
F_422 ( V_182 -> V_200 , V_30 , V_603 ) ;
F_423 ( V_30 , V_182 -> V_168 ) ;
}
static struct V_27 * F_424 ( struct V_582 * V_182 )
{
struct V_27 * V_30 , * V_340 ;
F_341 ( & V_182 -> V_200 -> V_257 ) ;
F_425 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_419 ( V_30 , V_182 ) )
continue;
F_421 ( V_30 , V_182 ) ;
F_83 ( V_182 -> V_213 -> V_604 [ V_182 -> V_413 ] ) ;
return V_30 ;
}
return NULL ;
}
static int F_426 ( struct V_582 * V_182 )
{
struct V_605 * V_606 = & V_182 -> V_200 -> V_333 ;
struct V_27 * V_30 ;
unsigned long V_73 ;
int V_607 = 0 ;
F_341 ( & V_182 -> V_200 -> V_257 ) ;
if ( V_182 -> V_505 <= 0 )
return 0 ;
while ( ! F_315 ( V_606 ) ) {
if ( V_182 -> V_413 != V_588 && V_182 -> V_200 -> V_75 <= 1 )
break;
V_30 = F_427 ( V_606 , struct V_27 , V_29 . V_332 ) ;
V_182 -> V_608 ++ ;
if ( V_182 -> V_608 > V_182 -> V_609 )
break;
if ( V_182 -> V_608 > V_182 -> V_610 ) {
V_182 -> V_610 += V_611 ;
V_182 -> V_115 |= V_612 ;
break;
}
if ( ! F_419 ( V_30 , V_182 ) )
goto V_61;
V_73 = F_138 ( V_30 ) ;
if ( F_234 ( V_613 ) && V_73 < 16 && ! V_182 -> V_213 -> V_597 )
goto V_61;
if ( ( V_73 / 2 ) > V_182 -> V_505 )
goto V_61;
F_421 ( V_30 , V_182 ) ;
F_213 ( & V_30 -> V_29 . V_332 , & V_182 -> V_606 ) ;
V_607 ++ ;
V_182 -> V_505 -= V_73 ;
#ifdef F_428
if ( V_182 -> V_413 == V_592 )
break;
#endif
if ( V_182 -> V_505 <= 0 )
break;
continue;
V_61:
F_429 ( & V_30 -> V_29 . V_332 , V_606 ) ;
}
F_70 ( V_182 -> V_213 -> V_604 [ V_182 -> V_413 ] , V_607 ) ;
return V_607 ;
}
static void F_430 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_341 ( & V_25 -> V_257 ) ;
F_181 ( F_34 ( V_30 ) != V_25 ) ;
F_431 ( V_25 , V_30 , V_614 ) ;
V_30 -> V_48 = V_615 ;
F_432 ( V_25 , V_30 , 0 ) ;
}
static void F_433 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
struct V_378 V_379 ;
F_321 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
F_430 ( V_25 , V_30 ) ;
F_322 ( V_25 , & V_379 ) ;
}
static void F_434 ( struct V_582 * V_182 )
{
struct V_605 * V_606 = & V_182 -> V_606 ;
struct V_27 * V_30 ;
struct V_378 V_379 ;
F_321 ( V_182 -> V_202 , & V_379 ) ;
F_317 ( V_182 -> V_202 ) ;
while ( ! F_315 ( V_606 ) ) {
V_30 = F_427 ( V_606 , struct V_27 , V_29 . V_332 ) ;
F_215 ( & V_30 -> V_29 . V_332 ) ;
F_430 ( V_182 -> V_202 , V_30 ) ;
}
F_322 ( V_182 -> V_202 , & V_379 ) ;
}
static inline bool F_435 ( struct V_26 * V_26 )
{
if ( V_26 -> V_73 . V_5 )
return false ;
if ( V_26 -> V_79 . V_83 )
return false ;
if ( V_26 -> V_79 . V_86 )
return false ;
if ( V_26 -> V_354 )
return false ;
return true ;
}
static void F_436 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 , * V_616 ;
struct V_378 V_379 ;
F_437 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
F_438 (rq, cfs_rq, pos) {
struct V_28 * V_29 ;
if ( F_220 ( V_26 ) )
continue;
if ( F_246 ( F_63 ( V_26 ) , V_26 , true ) )
F_65 ( V_26 , 0 ) ;
V_29 = V_26 -> V_34 -> V_29 [ V_1 ] ;
if ( V_29 && ! F_242 ( V_29 ) )
F_249 ( V_29 , 0 ) ;
if ( F_435 ( V_26 ) )
F_29 ( V_26 ) ;
}
F_439 ( V_25 , & V_379 ) ;
}
static void F_440 ( struct V_26 * V_26 )
{
struct V_25 * V_25 = F_17 ( V_26 ) ;
struct V_28 * V_29 = V_26 -> V_34 -> V_29 [ F_26 ( V_25 ) ] ;
unsigned long V_92 = V_224 ;
unsigned long V_73 ;
if ( V_26 -> V_617 == V_92 )
return;
V_26 -> V_618 = NULL ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
V_26 -> V_618 = V_29 ;
if ( V_26 -> V_617 == V_92 )
break;
}
if ( ! V_29 ) {
V_26 -> V_619 = F_258 ( V_26 ) ;
V_26 -> V_617 = V_92 ;
}
while ( ( V_29 = V_26 -> V_618 ) != NULL ) {
V_73 = V_26 -> V_619 ;
V_73 = F_441 ( V_73 * V_29 -> V_79 . V_82 ,
F_258 ( V_26 ) + 1 ) ;
V_26 = F_24 ( V_29 ) ;
V_26 -> V_619 = V_73 ;
V_26 -> V_617 = V_92 ;
}
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
struct V_26 * V_26 = F_22 ( V_30 ) ;
F_440 ( V_26 ) ;
return F_441 ( V_30 -> V_29 . V_79 . V_82 * V_26 -> V_619 ,
F_258 ( V_26 ) + 1 ) ;
}
static inline void F_436 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
struct V_26 * V_26 = & V_25 -> V_42 ;
struct V_378 V_379 ;
F_437 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
F_246 ( F_63 ( V_26 ) , V_26 , true ) ;
F_439 ( V_25 , & V_379 ) ;
}
static unsigned long F_138 ( struct V_27 * V_30 )
{
return V_30 -> V_29 . V_79 . V_82 ;
}
static inline void F_442 ( struct V_620 * V_526 )
{
* V_526 = (struct V_620 ) {
. V_621 = NULL ,
. V_233 = NULL ,
. V_622 = 0UL ,
. V_623 = 0UL ,
. V_624 = {
. V_508 = 0UL ,
. V_625 = 0 ,
. V_626 = V_627 ,
} ,
} ;
}
static inline int F_443 ( struct V_212 * V_213 ,
enum V_628 V_413 )
{
int V_502 ;
switch ( V_413 ) {
case V_588 :
V_502 = V_213 -> V_629 ;
break;
case V_592 :
V_502 = V_213 -> V_630 ;
break;
default:
V_502 = V_213 -> V_631 ;
break;
}
return V_502 ;
}
static unsigned long F_444 ( int V_1 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
T_2 V_476 , V_632 , V_633 , V_79 ;
T_3 V_44 ;
V_633 = F_98 ( V_25 -> V_633 ) ;
V_79 = F_98 ( V_25 -> V_634 ) ;
V_44 = F_445 ( V_25 ) - V_633 ;
if ( F_14 ( V_44 < 0 ) )
V_44 = 0 ;
V_476 = F_446 () + V_44 ;
V_632 = F_228 ( V_79 , V_476 ) ;
if ( F_12 ( V_632 < V_88 ) )
return V_88 - V_632 ;
return 1 ;
}
static void F_447 ( struct V_212 * V_213 , int V_1 )
{
unsigned long V_177 = F_225 ( V_213 , V_1 ) ;
struct V_490 * V_635 = V_213 -> V_493 ;
F_124 ( V_1 ) -> V_479 = V_177 ;
V_177 *= F_444 ( V_1 ) ;
V_177 >>= V_636 ;
if ( ! V_177 )
V_177 = 1 ;
F_124 ( V_1 ) -> V_478 = V_177 ;
V_635 -> V_513 -> V_177 = V_177 ;
V_635 -> V_513 -> V_637 = V_177 ;
}
void F_448 ( struct V_212 * V_213 , int V_1 )
{
struct V_212 * V_563 = V_213 -> V_563 ;
struct V_490 * V_148 , * V_635 = V_213 -> V_493 ;
unsigned long V_177 , V_637 ;
unsigned long V_221 ;
V_221 = F_155 ( V_213 -> V_638 ) ;
V_221 = F_158 ( V_221 , 1UL , V_639 ) ;
V_635 -> V_513 -> V_640 = V_224 + V_221 ;
if ( ! V_563 ) {
F_447 ( V_213 , V_1 ) ;
return;
}
V_177 = 0 ;
V_637 = V_496 ;
if ( V_563 -> V_115 & V_641 ) {
F_123 (cpu, sched_group_span(sdg)) {
struct V_642 * V_513 ;
struct V_25 * V_25 = F_124 ( V_1 ) ;
if ( F_14 ( ! V_25 -> V_213 ) ) {
V_177 += F_126 ( V_1 ) ;
} else {
V_513 = V_25 -> V_213 -> V_493 -> V_513 ;
V_177 += V_513 -> V_177 ;
}
V_637 = F_154 ( V_177 , V_637 ) ;
}
} else {
V_148 = V_563 -> V_493 ;
do {
struct V_642 * V_513 = V_148 -> V_513 ;
V_177 += V_513 -> V_177 ;
V_637 = F_154 ( V_513 -> V_637 , V_637 ) ;
V_148 = V_148 -> V_61 ;
} while ( V_148 != V_563 -> V_493 );
}
V_635 -> V_513 -> V_177 = V_177 ;
V_635 -> V_513 -> V_637 = V_637 ;
}
static inline int
F_449 ( struct V_25 * V_25 , struct V_212 * V_213 )
{
return ( ( V_25 -> V_478 * V_213 -> V_197 ) <
( V_25 -> V_479 * 100 ) ) ;
}
static inline int F_450 ( struct V_490 * V_148 )
{
return V_148 -> V_513 -> V_505 ;
}
static inline bool
F_451 ( struct V_582 * V_182 , struct V_643 * V_644 )
{
if ( V_644 -> V_625 < V_644 -> F_114 )
return true ;
if ( ( V_644 -> V_645 * 100 ) >
( V_644 -> V_646 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_452 ( struct V_582 * V_182 , struct V_643 * V_644 )
{
if ( V_644 -> V_625 <= V_644 -> F_114 )
return false ;
if ( ( V_644 -> V_645 * 100 ) <
( V_644 -> V_646 * V_182 -> V_213 -> V_197 ) )
return true ;
return false ;
}
static inline bool
F_453 ( struct V_490 * V_647 , struct V_490 * V_648 )
{
return V_647 -> V_513 -> V_637 * V_553 <
V_648 -> V_513 -> V_637 * 1024 ;
}
static inline enum
V_626 F_454 ( struct V_490 * V_148 ,
struct V_643 * V_644 )
{
if ( V_644 -> V_649 )
return V_650 ;
if ( F_450 ( V_148 ) )
return V_651 ;
return V_627 ;
}
static inline void F_455 ( struct V_582 * V_182 ,
struct V_490 * V_148 , int V_502 ,
int V_512 , struct V_643 * V_644 ,
bool * V_652 )
{
unsigned long V_73 ;
int V_272 , V_75 ;
memset ( V_644 , 0 , sizeof( * V_644 ) ) ;
F_383 (i, sched_group_span(group), env->cpus) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
if ( V_512 )
V_73 = F_367 ( V_272 , V_502 ) ;
else
V_73 = F_366 ( V_272 , V_502 ) ;
V_644 -> V_653 += V_73 ;
V_644 -> V_646 += F_399 ( V_272 ) ;
V_644 -> V_625 += V_25 -> V_42 . V_424 ;
V_75 = V_25 -> V_75 ;
if ( V_75 > 1 )
* V_652 = true ;
#ifdef F_456
V_644 -> V_134 += V_25 -> V_134 ;
V_644 -> V_136 += V_25 -> V_136 ;
#endif
V_644 -> V_654 += F_125 ( V_272 ) ;
if ( ! V_75 && F_384 ( V_272 ) )
V_644 -> V_655 ++ ;
}
V_644 -> V_645 = V_148 -> V_513 -> V_177 ;
V_644 -> V_508 = ( V_644 -> V_653 * V_88 ) / V_644 -> V_645 ;
if ( V_644 -> V_625 )
V_644 -> V_656 = V_644 -> V_654 / V_644 -> V_625 ;
V_644 -> F_114 = V_148 -> F_114 ;
V_644 -> V_649 = F_452 ( V_182 , V_644 ) ;
V_644 -> V_626 = F_454 ( V_148 , V_644 ) ;
}
static bool F_457 ( struct V_582 * V_182 ,
struct V_620 * V_526 ,
struct V_490 * V_647 ,
struct V_643 * V_644 )
{
struct V_643 * V_621 = & V_526 -> V_624 ;
if ( V_644 -> V_626 > V_621 -> V_626 )
return true ;
if ( V_644 -> V_626 < V_621 -> V_626 )
return false ;
if ( V_644 -> V_508 <= V_621 -> V_508 )
return false ;
if ( ! ( V_182 -> V_213 -> V_115 & V_657 ) )
goto V_658;
if ( V_644 -> V_625 <= V_644 -> F_114 &&
F_453 ( V_526 -> V_233 , V_647 ) )
return false ;
V_658:
if ( ! ( V_182 -> V_213 -> V_115 & V_659 ) )
return true ;
if ( V_182 -> V_413 == V_588 )
return true ;
if ( V_644 -> V_625 &&
F_458 ( V_182 -> V_168 , V_647 -> V_660 ) ) {
if ( ! V_526 -> V_621 )
return true ;
if ( F_458 ( V_526 -> V_621 -> V_660 ,
V_647 -> V_660 ) )
return true ;
}
return false ;
}
static inline enum V_661 F_459 ( struct V_643 * V_644 )
{
if ( V_644 -> V_625 > V_644 -> V_134 )
return V_662 ;
if ( V_644 -> V_625 > V_644 -> V_136 )
return V_231 ;
return V_663 ;
}
static inline enum V_661 F_460 ( struct V_25 * V_25 )
{
if ( V_25 -> V_75 > V_25 -> V_134 )
return V_662 ;
if ( V_25 -> V_75 > V_25 -> V_136 )
return V_231 ;
return V_663 ;
}
static inline enum V_661 F_459 ( struct V_643 * V_644 )
{
return V_663 ;
}
static inline enum V_661 F_460 ( struct V_25 * V_25 )
{
return V_662 ;
}
static inline void F_461 ( struct V_582 * V_182 , struct V_620 * V_526 )
{
struct V_212 * V_563 = V_182 -> V_213 -> V_563 ;
struct V_490 * V_647 = V_182 -> V_213 -> V_493 ;
struct V_643 * V_233 = & V_526 -> V_664 ;
struct V_643 V_665 ;
int V_502 , V_666 = 0 ;
bool V_652 = false ;
if ( V_563 && V_563 -> V_115 & V_667 )
V_666 = 1 ;
V_502 = F_443 ( V_182 -> V_213 , V_182 -> V_413 ) ;
do {
struct V_643 * V_644 = & V_665 ;
int V_512 ;
V_512 = F_137 ( V_182 -> V_168 , F_379 ( V_647 ) ) ;
if ( V_512 ) {
V_526 -> V_233 = V_647 ;
V_644 = V_233 ;
if ( V_182 -> V_413 != V_592 ||
F_462 ( V_224 , V_647 -> V_513 -> V_640 ) )
F_448 ( V_182 -> V_213 , V_182 -> V_168 ) ;
}
F_455 ( V_182 , V_647 , V_502 , V_512 , V_644 ,
& V_652 ) ;
if ( V_512 )
goto V_668;
if ( V_666 && V_526 -> V_233 &&
F_451 ( V_182 , V_233 ) &&
( V_644 -> V_625 > V_233 -> V_625 + 1 ) ) {
V_644 -> V_649 = 1 ;
V_644 -> V_626 = F_454 ( V_647 , V_644 ) ;
}
if ( F_457 ( V_182 , V_526 , V_647 , V_644 ) ) {
V_526 -> V_621 = V_647 ;
V_526 -> V_624 = * V_644 ;
}
V_668:
V_526 -> V_622 += V_644 -> V_653 ;
V_526 -> V_623 += V_644 -> V_645 ;
V_647 = V_647 -> V_61 ;
} while ( V_647 != V_182 -> V_213 -> V_493 );
if ( V_182 -> V_213 -> V_115 & V_587 )
V_182 -> V_661 = F_459 ( & V_526 -> V_624 ) ;
if ( ! V_182 -> V_213 -> V_35 ) {
if ( V_182 -> V_202 -> V_551 -> V_652 != V_652 )
V_182 -> V_202 -> V_551 -> V_652 = V_652 ;
}
}
static int F_463 ( struct V_582 * V_182 , struct V_620 * V_526 )
{
int V_669 ;
if ( ! ( V_182 -> V_213 -> V_115 & V_659 ) )
return 0 ;
if ( V_182 -> V_413 == V_588 )
return 0 ;
if ( ! V_526 -> V_621 )
return 0 ;
V_669 = V_526 -> V_621 -> V_660 ;
if ( F_458 ( V_669 , V_182 -> V_168 ) )
return 0 ;
V_182 -> V_505 = F_127 (
V_526 -> V_624 . V_508 * V_526 -> V_624 . V_645 ,
V_88 ) ;
return 1 ;
}
static inline
void F_464 ( struct V_582 * V_182 , struct V_620 * V_526 )
{
unsigned long V_555 , V_670 = 0 , V_671 = 0 ;
unsigned int V_672 = 2 ;
unsigned long V_673 ;
struct V_643 * V_233 , * V_621 ;
V_233 = & V_526 -> V_664 ;
V_621 = & V_526 -> V_624 ;
if ( ! V_233 -> V_625 )
V_233 -> V_656 = F_369 ( V_182 -> V_168 ) ;
else if ( V_621 -> V_656 > V_233 -> V_656 )
V_672 = 1 ;
V_673 =
( V_621 -> V_656 * V_88 ) /
V_621 -> V_645 ;
if ( V_621 -> V_508 + V_673 >=
V_233 -> V_508 + ( V_673 * V_672 ) ) {
V_182 -> V_505 = V_621 -> V_656 ;
return;
}
V_670 += V_621 -> V_645 *
F_154 ( V_621 -> V_656 , V_621 -> V_508 ) ;
V_670 += V_233 -> V_645 *
F_154 ( V_233 -> V_656 , V_233 -> V_508 ) ;
V_670 /= V_88 ;
if ( V_621 -> V_508 > V_673 ) {
V_671 += V_621 -> V_645 *
F_154 ( V_621 -> V_656 ,
V_621 -> V_508 - V_673 ) ;
}
if ( V_621 -> V_508 * V_621 -> V_645 <
V_621 -> V_656 * V_88 ) {
V_555 = ( V_621 -> V_508 * V_621 -> V_645 ) /
V_233 -> V_645 ;
} else {
V_555 = ( V_621 -> V_656 * V_88 ) /
V_233 -> V_645 ;
}
V_671 += V_233 -> V_645 *
F_154 ( V_233 -> V_656 , V_233 -> V_508 + V_555 ) ;
V_671 /= V_88 ;
if ( V_671 > V_670 )
V_182 -> V_505 = V_621 -> V_656 ;
}
static inline void F_465 ( struct V_582 * V_182 , struct V_620 * V_526 )
{
unsigned long V_674 , V_675 = ~ 0UL ;
struct V_643 * V_233 , * V_621 ;
V_233 = & V_526 -> V_664 ;
V_621 = & V_526 -> V_624 ;
if ( V_621 -> V_626 == V_651 ) {
V_621 -> V_656 =
F_154 ( V_621 -> V_656 , V_526 -> V_508 ) ;
}
if ( V_621 -> V_508 <= V_526 -> V_508 ||
V_233 -> V_508 >= V_526 -> V_508 ) {
V_182 -> V_505 = 0 ;
return F_464 ( V_182 , V_526 ) ;
}
if ( V_621 -> V_626 == V_650 &&
V_233 -> V_626 == V_650 ) {
V_675 = V_621 -> V_625 * V_88 ;
if ( V_675 > V_621 -> V_645 ) {
V_675 -= V_621 -> V_645 ;
V_675 *= F_13 ( V_74 ) ;
V_675 /= V_621 -> V_645 ;
} else
V_675 = ~ 0UL ;
}
V_674 = F_154 ( V_621 -> V_508 - V_526 -> V_508 , V_675 ) ;
V_182 -> V_505 = F_154 (
V_674 * V_621 -> V_645 ,
( V_526 -> V_508 - V_233 -> V_508 ) * V_233 -> V_645
) / V_88 ;
if ( V_182 -> V_505 < V_621 -> V_656 )
return F_464 ( V_182 , V_526 ) ;
}
static struct V_490 * F_466 ( struct V_582 * V_182 )
{
struct V_643 * V_233 , * V_621 ;
struct V_620 V_526 ;
F_442 ( & V_526 ) ;
F_461 ( V_182 , & V_526 ) ;
V_233 = & V_526 . V_664 ;
V_621 = & V_526 . V_624 ;
if ( F_463 ( V_182 , & V_526 ) )
return V_526 . V_621 ;
if ( ! V_526 . V_621 || V_621 -> V_625 == 0 )
goto V_676;
V_526 . V_508 = ( V_88 * V_526 . V_622 )
/ V_526 . V_623 ;
if ( V_621 -> V_626 == V_651 )
goto V_677;
if ( V_182 -> V_413 == V_592 && F_451 ( V_182 , V_233 ) &&
V_621 -> V_649 )
goto V_677;
if ( V_233 -> V_508 >= V_621 -> V_508 )
goto V_676;
if ( V_233 -> V_508 >= V_526 . V_508 )
goto V_676;
if ( V_182 -> V_413 == V_678 ) {
if ( ( V_621 -> V_626 != V_650 ) &&
( V_233 -> V_655 <= ( V_621 -> V_655 + 1 ) ) )
goto V_676;
} else {
if ( 100 * V_621 -> V_508 <=
V_182 -> V_213 -> V_197 * V_233 -> V_508 )
goto V_676;
}
V_677:
F_465 ( V_182 , & V_526 ) ;
return V_526 . V_621 ;
V_676:
V_182 -> V_505 = 0 ;
return NULL ;
}
static struct V_25 * F_467 ( struct V_582 * V_182 ,
struct V_490 * V_148 )
{
struct V_25 * V_621 = NULL , * V_25 ;
unsigned long V_679 = 0 , V_680 = 1 ;
int V_272 ;
F_383 (i, sched_group_span(group), env->cpus) {
unsigned long V_177 , V_681 ;
enum V_661 V_682 ;
V_25 = F_124 ( V_272 ) ;
V_682 = F_460 ( V_25 ) ;
if ( V_682 > V_182 -> V_661 )
continue;
V_177 = F_126 ( V_272 ) ;
V_681 = F_125 ( V_272 ) ;
if ( V_25 -> V_75 == 1 && V_681 > V_182 -> V_505 &&
! F_449 ( V_25 , V_182 -> V_213 ) )
continue;
if ( V_681 * V_680 > V_679 * V_177 ) {
V_679 = V_681 ;
V_680 = V_177 ;
V_621 = V_25 ;
}
}
return V_621 ;
}
static int F_468 ( struct V_582 * V_182 )
{
struct V_212 * V_213 = V_182 -> V_213 ;
if ( V_182 -> V_413 == V_592 ) {
if ( ( V_213 -> V_115 & V_659 ) &&
F_458 ( V_182 -> V_168 , V_182 -> V_201 ) )
return 1 ;
}
if ( ( V_182 -> V_413 != V_588 ) &&
( V_182 -> V_200 -> V_42 . V_424 == 1 ) ) {
if ( ( F_449 ( V_182 -> V_200 , V_213 ) ) &&
( F_126 ( V_182 -> V_201 ) * V_213 -> V_197 < F_126 ( V_182 -> V_168 ) * 100 ) )
return 1 ;
}
return F_14 ( V_213 -> V_597 > V_213 -> V_598 + 2 ) ;
}
static int F_469 ( struct V_582 * V_182 )
{
struct V_490 * V_647 = V_182 -> V_213 -> V_493 ;
int V_1 , V_683 = - 1 ;
if ( V_182 -> V_413 == V_592 )
return 1 ;
F_383 (cpu, group_balance_mask(sg), env->cpus) {
if ( ! F_384 ( V_1 ) )
continue;
V_683 = V_1 ;
break;
}
if ( V_683 == - 1 )
V_683 = F_470 ( V_647 ) ;
return V_683 == V_182 -> V_168 ;
}
static int F_471 ( int V_323 , struct V_25 * F_244 ,
struct V_212 * V_213 , enum V_628 V_413 ,
int * V_684 )
{
int V_685 , V_686 , V_687 = 0 ;
struct V_212 * V_688 = V_213 -> V_35 ;
struct V_490 * V_148 ;
struct V_25 * V_621 ;
struct V_378 V_379 ;
struct V_532 * V_9 = F_390 ( V_689 ) ;
struct V_582 V_182 = {
. V_213 = V_213 ,
. V_168 = V_323 ,
. V_202 = F_244 ,
. V_690 = F_379 ( V_213 -> V_493 ) ,
. V_413 = V_413 ,
. V_610 = V_611 ,
. V_9 = V_9 ,
. V_661 = V_663 ,
. V_606 = F_472 ( V_182 . V_606 ) ,
} ;
F_391 ( V_9 , F_392 ( V_213 ) , V_691 ) ;
F_83 ( V_213 -> V_692 [ V_413 ] ) ;
V_693:
if ( ! F_469 ( & V_182 ) ) {
* V_684 = 0 ;
goto V_676;
}
V_148 = F_466 ( & V_182 ) ;
if ( ! V_148 ) {
F_83 ( V_213 -> V_694 [ V_413 ] ) ;
goto V_676;
}
V_621 = F_467 ( & V_182 , V_148 ) ;
if ( ! V_621 ) {
F_83 ( V_213 -> V_695 [ V_413 ] ) ;
goto V_676;
}
F_181 ( V_621 == V_182 . V_202 ) ;
F_70 ( V_213 -> V_696 [ V_413 ] , V_182 . V_505 ) ;
V_182 . V_201 = V_621 -> V_1 ;
V_182 . V_200 = V_621 ;
V_685 = 0 ;
if ( V_621 -> V_75 > 1 ) {
V_182 . V_115 |= V_595 ;
V_182 . V_609 = F_154 ( V_697 , V_621 -> V_75 ) ;
V_698:
F_437 ( V_621 , & V_379 ) ;
F_317 ( V_621 ) ;
V_686 = F_426 ( & V_182 ) ;
F_322 ( V_621 , & V_379 ) ;
if ( V_686 ) {
F_434 ( & V_182 ) ;
V_685 += V_686 ;
}
F_473 ( V_379 . V_115 ) ;
if ( V_182 . V_115 & V_612 ) {
V_182 . V_115 &= ~ V_612 ;
goto V_698;
}
if ( ( V_182 . V_115 & V_593 ) && V_182 . V_505 > 0 ) {
F_394 ( V_182 . V_168 , V_182 . V_9 ) ;
V_182 . V_202 = F_124 ( V_182 . V_594 ) ;
V_182 . V_168 = V_182 . V_594 ;
V_182 . V_115 &= ~ V_593 ;
V_182 . V_608 = 0 ;
V_182 . V_610 = V_611 ;
goto V_698;
}
if ( V_688 ) {
int * V_699 = & V_688 -> V_493 -> V_513 -> V_505 ;
if ( ( V_182 . V_115 & V_591 ) && V_182 . V_505 > 0 )
* V_699 = 1 ;
}
if ( F_14 ( V_182 . V_115 & V_595 ) ) {
F_394 ( F_26 ( V_621 ) , V_9 ) ;
if ( ! F_474 ( V_9 , V_182 . V_690 ) ) {
V_182 . V_608 = 0 ;
V_182 . V_610 = V_611 ;
goto V_693;
}
goto V_700;
}
}
if ( ! V_685 ) {
F_83 ( V_213 -> V_701 [ V_413 ] ) ;
if ( V_413 != V_592 )
V_213 -> V_597 ++ ;
if ( F_468 ( & V_182 ) ) {
unsigned long V_115 ;
F_475 ( & V_621 -> V_257 , V_115 ) ;
if ( ! F_137 ( V_323 , & V_621 -> V_47 -> V_207 ) ) {
F_476 ( & V_621 -> V_257 ,
V_115 ) ;
V_182 . V_115 |= V_595 ;
goto V_702;
}
if ( ! V_621 -> V_687 ) {
V_621 -> V_687 = 1 ;
V_621 -> V_703 = V_323 ;
V_687 = 1 ;
}
F_476 ( & V_621 -> V_257 , V_115 ) ;
if ( V_687 ) {
F_477 ( F_26 ( V_621 ) ,
V_704 , V_621 ,
& V_621 -> V_705 ) ;
}
V_213 -> V_597 = V_213 -> V_598 + 1 ;
}
} else
V_213 -> V_597 = 0 ;
if ( F_12 ( ! V_687 ) ) {
V_213 -> V_638 = V_213 -> V_706 ;
} else {
if ( V_213 -> V_638 < V_213 -> V_707 )
V_213 -> V_638 *= 2 ;
}
goto V_321;
V_676:
if ( V_688 ) {
int * V_699 = & V_688 -> V_493 -> V_513 -> V_505 ;
if ( * V_699 )
* V_699 = 0 ;
}
V_700:
F_83 ( V_213 -> V_708 [ V_413 ] ) ;
V_213 -> V_597 = 0 ;
V_702:
if ( ( ( V_182 . V_115 & V_595 ) &&
V_213 -> V_638 < V_709 ) ||
( V_213 -> V_638 < V_213 -> V_707 ) )
V_213 -> V_638 *= 2 ;
V_685 = 0 ;
V_321:
return V_685 ;
}
static inline unsigned long
F_478 ( struct V_212 * V_213 , int V_710 )
{
unsigned long V_221 = V_213 -> V_638 ;
if ( V_710 )
V_221 *= V_213 -> V_711 ;
V_221 = F_155 ( V_221 ) ;
V_221 = F_158 ( V_221 , 1UL , V_639 ) ;
return V_221 ;
}
static inline void
F_479 ( struct V_212 * V_213 , unsigned long * V_712 )
{
unsigned long V_221 , V_61 ;
V_221 = F_478 ( V_213 , 0 ) ;
V_61 = V_213 -> V_713 + V_221 ;
if ( F_192 ( * V_712 , V_61 ) )
* V_712 = V_61 ;
}
static int F_259 ( struct V_25 * F_244 , struct V_378 * V_379 )
{
unsigned long V_712 = V_224 + V_222 ;
int V_323 = F_244 -> V_1 ;
struct V_212 * V_213 ;
int V_714 = 0 ;
T_2 V_715 = 0 ;
F_244 -> V_524 = F_78 ( F_244 ) ;
F_480 ( F_244 , V_379 ) ;
if ( F_244 -> V_537 < V_584 ||
! F_244 -> V_551 -> V_652 ) {
F_134 () ;
V_213 = F_481 ( F_244 -> V_213 ) ;
if ( V_213 )
F_479 ( V_213 , & V_712 ) ;
F_142 () ;
goto V_321;
}
F_305 ( & F_244 -> V_257 ) ;
F_436 ( V_323 ) ;
F_134 () ;
F_402 (this_cpu, sd) {
int V_684 = 1 ;
T_2 V_716 , V_717 ;
if ( ! ( V_213 -> V_115 & V_560 ) )
continue;
if ( F_244 -> V_537 < V_715 + V_213 -> V_718 ) {
F_479 ( V_213 , & V_712 ) ;
break;
}
if ( V_213 -> V_115 & V_719 ) {
V_716 = F_298 ( V_323 ) ;
V_714 = F_471 ( V_323 , F_244 ,
V_213 , V_592 ,
& V_684 ) ;
V_717 = F_298 ( V_323 ) - V_716 ;
if ( V_717 > V_213 -> V_718 )
V_213 -> V_718 = V_717 ;
V_715 += V_717 ;
}
F_479 ( V_213 , & V_712 ) ;
if ( V_714 || F_244 -> V_75 > 0 )
break;
}
F_142 () ;
F_303 ( & F_244 -> V_257 ) ;
if ( V_715 > F_244 -> V_720 )
F_244 -> V_720 = V_715 ;
if ( F_244 -> V_42 . V_424 && ! V_714 )
V_714 = 1 ;
V_321:
if ( F_192 ( F_244 -> V_712 , V_712 ) )
F_244 -> V_712 = V_712 ;
if ( F_244 -> V_75 != F_244 -> V_42 . V_424 )
V_714 = - 1 ;
if ( V_714 )
F_244 -> V_524 = 0 ;
F_482 ( F_244 , V_379 ) ;
return V_714 ;
}
static int V_704 ( void * V_419 )
{
struct V_25 * V_721 = V_419 ;
int V_669 = F_26 ( V_721 ) ;
int V_722 = V_721 -> V_703 ;
struct V_25 * V_723 = F_124 ( V_722 ) ;
struct V_212 * V_213 ;
struct V_27 * V_30 = NULL ;
struct V_378 V_379 ;
F_483 ( V_721 , & V_379 ) ;
if ( F_14 ( V_669 != F_299 () ||
! V_721 -> V_687 ) )
goto V_724;
if ( V_721 -> V_75 <= 1 )
goto V_724;
F_181 ( V_721 == V_723 ) ;
F_134 () ;
F_402 (target_cpu, sd) {
if ( ( V_213 -> V_115 & V_560 ) &&
F_137 ( V_669 , F_392 ( V_213 ) ) )
break;
}
if ( F_12 ( V_213 ) ) {
struct V_582 V_182 = {
. V_213 = V_213 ,
. V_168 = V_722 ,
. V_202 = V_723 ,
. V_201 = V_721 -> V_1 ,
. V_200 = V_721 ,
. V_413 = V_678 ,
. V_115 = V_593 ,
} ;
F_83 ( V_213 -> V_725 ) ;
F_317 ( V_721 ) ;
V_30 = F_424 ( & V_182 ) ;
if ( V_30 ) {
F_83 ( V_213 -> V_726 ) ;
V_213 -> V_597 = 0 ;
} else {
F_83 ( V_213 -> V_727 ) ;
}
}
F_142 () ;
V_724:
V_721 -> V_687 = 0 ;
F_322 ( V_721 , & V_379 ) ;
if ( V_30 )
F_433 ( V_723 , V_30 ) ;
F_141 () ;
return 0 ;
}
static inline int F_484 ( struct V_25 * V_25 )
{
return F_14 ( ! F_485 ( V_25 -> V_213 ) ) ;
}
static inline int F_486 ( void )
{
int V_728 = F_382 ( V_729 . V_730 ) ;
if ( V_728 < V_731 && F_384 ( V_728 ) )
return V_728 ;
return V_731 ;
}
static void F_487 ( void )
{
int V_732 ;
V_729 . V_712 ++ ;
V_732 = F_486 () ;
if ( V_732 >= V_731 )
return;
if ( F_488 ( V_733 , F_489 ( V_732 ) ) )
return;
F_490 ( V_732 ) ;
return;
}
void F_491 ( unsigned int V_1 )
{
if ( F_14 ( F_492 ( V_734 , F_489 ( V_1 ) ) ) ) {
if ( F_12 ( F_137 ( V_1 , V_729 . V_730 ) ) ) {
F_394 ( V_1 , V_729 . V_730 ) ;
F_493 ( & V_729 . V_735 ) ;
}
F_494 ( V_734 , F_489 ( V_1 ) ) ;
}
}
static inline void F_495 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_299 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_541 , V_1 ) ) ;
if ( ! V_213 || ! V_213 -> V_736 )
goto V_206;
V_213 -> V_736 = 0 ;
F_496 ( & V_213 -> V_226 -> V_737 ) ;
V_206:
F_142 () ;
}
void F_497 ( void )
{
struct V_212 * V_213 ;
int V_1 = F_299 () ;
F_134 () ;
V_213 = F_147 ( F_148 ( V_541 , V_1 ) ) ;
if ( ! V_213 || V_213 -> V_736 )
goto V_206;
V_213 -> V_736 = 1 ;
F_493 ( & V_213 -> V_226 -> V_737 ) ;
V_206:
F_142 () ;
}
void F_498 ( int V_1 )
{
if ( ! F_499 ( V_1 ) )
return;
if ( ! F_500 ( V_1 ) )
return;
if ( F_492 ( V_734 , F_489 ( V_1 ) ) )
return;
if ( F_484 ( F_124 ( V_1 ) ) )
return;
F_501 ( V_1 , V_729 . V_730 ) ;
F_496 ( & V_729 . V_735 ) ;
F_502 ( V_734 , F_489 ( V_1 ) ) ;
}
void F_503 ( void )
{
V_639 = V_222 * F_504 () / 10 ;
}
static void F_505 ( struct V_25 * V_25 , enum V_628 V_413 )
{
int V_684 = 1 ;
int V_1 = V_25 -> V_1 ;
unsigned long V_221 ;
struct V_212 * V_213 ;
unsigned long V_712 = V_224 + 60 * V_222 ;
int F_479 = 0 ;
int V_738 , V_739 = 0 ;
T_2 V_740 = 0 ;
F_436 ( V_1 ) ;
F_134 () ;
F_402 (cpu, sd) {
if ( F_192 ( V_224 , V_213 -> V_741 ) ) {
V_213 -> V_718 =
( V_213 -> V_718 * 253 ) / 256 ;
V_213 -> V_741 = V_224 + V_222 ;
V_739 = 1 ;
}
V_740 += V_213 -> V_718 ;
if ( ! ( V_213 -> V_115 & V_560 ) )
continue;
if ( ! V_684 ) {
if ( V_739 )
continue;
break;
}
V_221 = F_478 ( V_213 , V_413 != V_678 ) ;
V_738 = V_213 -> V_115 & V_742 ;
if ( V_738 ) {
if ( ! F_506 ( & V_743 ) )
goto V_321;
}
if ( F_462 ( V_224 , V_213 -> V_713 + V_221 ) ) {
if ( F_471 ( V_1 , V_25 , V_213 , V_413 , & V_684 ) ) {
V_413 = F_384 ( V_1 ) ? V_678 : V_588 ;
}
V_213 -> V_713 = V_224 ;
V_221 = F_478 ( V_213 , V_413 != V_678 ) ;
}
if ( V_738 )
F_184 ( & V_743 ) ;
V_321:
if ( F_192 ( V_712 , V_213 -> V_713 + V_221 ) ) {
V_712 = V_213 -> V_713 + V_221 ;
F_479 = 1 ;
}
}
if ( V_739 ) {
V_25 -> V_720 =
F_69 ( ( T_2 ) V_584 , V_740 ) ;
}
F_142 () ;
if ( F_12 ( F_479 ) ) {
V_25 -> V_712 = V_712 ;
#ifdef F_357
if ( ( V_413 == V_678 ) && F_192 ( V_729 . V_712 , V_25 -> V_712 ) )
V_729 . V_712 = V_25 -> V_712 ;
#endif
}
}
static void F_507 ( struct V_25 * F_244 , enum V_628 V_413 )
{
int V_323 = F_244 -> V_1 ;
struct V_25 * V_25 ;
int V_683 ;
unsigned long V_712 = V_224 + 60 * V_222 ;
int F_479 = 0 ;
if ( V_413 != V_678 ||
! F_492 ( V_733 , F_489 ( V_323 ) ) )
goto V_301;
F_123 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_683 == V_323 || ! F_384 ( V_683 ) )
continue;
if ( F_508 () )
break;
V_25 = F_124 ( V_683 ) ;
if ( F_462 ( V_224 , V_25 -> V_712 ) ) {
struct V_378 V_379 ;
F_483 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
F_360 ( V_25 ) ;
F_509 ( V_25 , & V_379 ) ;
F_505 ( V_25 , V_678 ) ;
}
if ( F_192 ( V_712 , V_25 -> V_712 ) ) {
V_712 = V_25 -> V_712 ;
F_479 = 1 ;
}
}
if ( F_12 ( F_479 ) )
V_729 . V_712 = V_712 ;
V_301:
F_494 ( V_733 , F_489 ( V_323 ) ) ;
}
static inline bool F_510 ( struct V_25 * V_25 )
{
unsigned long V_92 = V_224 ;
struct V_525 * V_526 ;
struct V_212 * V_213 ;
int V_744 , V_272 , V_1 = V_25 -> V_1 ;
bool V_745 = false ;
if ( F_14 ( V_25 -> F_259 ) )
return false ;
F_495 () ;
F_491 ( V_1 ) ;
if ( F_12 ( ! F_511 ( & V_729 . V_735 ) ) )
return false ;
if ( F_196 ( V_92 , V_729 . V_712 ) )
return false ;
if ( V_25 -> V_75 >= 2 )
return true ;
F_134 () ;
V_526 = F_147 ( F_148 ( V_527 , V_1 ) ) ;
if ( V_526 ) {
V_744 = F_511 ( & V_526 -> V_737 ) ;
if ( V_744 > 1 ) {
V_745 = true ;
goto V_206;
}
}
V_213 = F_147 ( V_25 -> V_213 ) ;
if ( V_213 ) {
if ( ( V_25 -> V_42 . V_424 >= 1 ) &&
F_449 ( V_25 , V_213 ) ) {
V_745 = true ;
goto V_206;
}
}
V_213 = F_147 ( F_148 ( V_746 , V_1 ) ) ;
if ( V_213 ) {
F_123 (i, sched_domain_span(sd)) {
if ( V_272 == V_1 ||
! F_137 ( V_272 , V_729 . V_730 ) )
continue;
if ( F_458 ( V_272 , V_1 ) ) {
V_745 = true ;
goto V_206;
}
}
}
V_206:
F_142 () ;
return V_745 ;
}
static void F_507 ( struct V_25 * F_244 , enum V_628 V_413 ) { }
static T_12 void F_512 ( struct V_747 * V_748 )
{
struct V_25 * F_244 = F_244 () ;
enum V_628 V_413 = F_244 -> F_259 ?
V_678 : V_588 ;
F_507 ( F_244 , V_413 ) ;
F_505 ( F_244 , V_413 ) ;
}
void F_513 ( struct V_25 * V_25 )
{
if ( F_14 ( F_484 ( V_25 ) ) )
return;
if ( F_462 ( V_224 , V_25 -> V_712 ) )
F_514 ( V_749 ) ;
#ifdef F_357
if ( F_510 ( V_25 ) )
F_487 () ;
#endif
}
static void F_515 ( struct V_25 * V_25 )
{
F_8 () ;
F_345 ( V_25 ) ;
}
static void F_516 ( struct V_25 * V_25 )
{
F_8 () ;
F_346 ( V_25 ) ;
}
static void F_517 ( struct V_25 * V_25 , struct V_27 * V_47 , int V_395 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_47 -> V_29 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
F_286 ( V_26 , V_29 , V_395 ) ;
}
if ( F_518 ( & V_286 ) )
F_207 ( V_25 , V_47 ) ;
}
static void F_519 ( struct V_27 * V_30 )
{
struct V_26 * V_26 ;
struct V_28 * V_29 = & V_30 -> V_29 , * V_47 ;
struct V_25 * V_25 = F_244 () ;
struct V_378 V_379 ;
F_321 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
V_26 = F_22 ( V_172 ) ;
V_47 = V_26 -> V_47 ;
if ( V_47 ) {
F_66 ( V_26 ) ;
V_29 -> V_43 = V_47 -> V_43 ;
}
F_262 ( V_26 , V_29 , 1 ) ;
if ( V_750 && V_47 && F_37 ( V_47 , V_29 ) ) {
F_132 ( V_47 -> V_43 , V_29 -> V_43 ) ;
F_280 ( V_25 ) ;
}
V_29 -> V_43 -= V_26 -> F_36 ;
F_322 ( V_25 , & V_379 ) ;
}
static void
F_520 ( struct V_25 * V_25 , struct V_27 * V_30 , int V_751 )
{
if ( ! F_521 ( V_30 ) )
return;
if ( V_25 -> V_47 == V_30 ) {
if ( V_30 -> V_752 > V_751 )
F_280 ( V_25 ) ;
} else
F_432 ( V_25 , V_30 , 0 ) ;
}
static inline bool F_522 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
if ( V_30 -> V_48 )
return true ;
if ( ! V_29 -> V_96 || V_30 -> V_118 == V_564 )
return true ;
return false ;
}
static void F_523 ( struct V_28 * V_29 )
{
struct V_26 * V_26 ;
V_29 = V_29 -> V_35 ;
F_59 (se) {
V_26 = F_23 ( V_29 ) ;
if ( F_308 ( V_26 ) )
break;
F_249 ( V_29 , V_375 ) ;
}
}
static void F_523 ( struct V_28 * V_29 ) { }
static void F_524 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_249 ( V_29 , 0 ) ;
F_251 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_523 ( V_29 ) ;
}
static void F_64 ( struct V_28 * V_29 )
{
struct V_26 * V_26 = F_23 ( V_29 ) ;
#ifdef F_411
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
#endif
F_249 ( V_29 , F_234 ( V_360 ) ? 0 : V_374 ) ;
F_250 ( V_26 , V_29 ) ;
F_65 ( V_26 , false ) ;
F_523 ( V_29 ) ;
}
static void F_525 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
if ( ! F_522 ( V_30 ) ) {
F_262 ( V_26 , V_29 , 0 ) ;
V_29 -> V_43 -= V_26 -> F_36 ;
}
F_524 ( V_29 ) ;
}
static void F_526 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_64 ( V_29 ) ;
if ( ! F_522 ( V_30 ) )
V_29 -> V_43 += V_26 -> F_36 ;
}
static void F_527 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_525 ( V_30 ) ;
}
static void F_528 ( struct V_25 * V_25 , struct V_27 * V_30 )
{
F_526 ( V_30 ) ;
if ( F_521 ( V_30 ) ) {
if ( V_25 -> V_47 == V_30 )
F_280 ( V_25 ) ;
else
F_432 ( V_25 , V_30 , 0 ) ;
}
}
static void F_529 ( struct V_25 * V_25 )
{
struct V_28 * V_29 = & V_25 -> V_47 -> V_29 ;
F_59 (se) {
struct V_26 * V_26 = F_23 ( V_29 ) ;
F_281 ( V_26 , V_29 ) ;
F_74 ( V_26 , 0 ) ;
}
}
void F_530 ( struct V_26 * V_26 )
{
V_26 -> V_54 = V_753 ;
V_26 -> F_36 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_26 -> V_51 = V_26 -> F_36 ;
#endif
#ifdef F_212
#ifdef F_411
V_26 -> V_366 = 0 ;
#endif
F_531 ( & V_26 -> V_371 , 0 ) ;
F_531 ( & V_26 -> V_373 , 0 ) ;
#endif
}
static void F_532 ( struct V_27 * V_30 )
{
struct V_28 * V_29 = & V_30 -> V_29 ;
F_533 ( V_30 , F_146 ( V_30 ) ) ;
V_29 -> V_41 = V_29 -> V_35 ? V_29 -> V_35 -> V_41 + 1 : 0 ;
}
static void F_534 ( struct V_27 * V_30 )
{
F_525 ( V_30 ) ;
F_533 ( V_30 , F_146 ( V_30 ) ) ;
#ifdef F_212
V_30 -> V_29 . V_79 . V_80 = 0 ;
#endif
F_526 ( V_30 ) ;
}
static void F_535 ( struct V_27 * V_30 , int type )
{
switch ( type ) {
case V_754 :
F_532 ( V_30 ) ;
break;
case V_755 :
F_534 ( V_30 ) ;
break;
}
}
void F_536 ( struct V_334 * V_34 )
{
int V_272 ;
F_343 ( F_301 ( V_34 ) ) ;
F_537 (i) {
if ( V_34 -> V_26 )
F_189 ( V_34 -> V_26 [ V_272 ] ) ;
if ( V_34 -> V_29 )
F_189 ( V_34 -> V_29 [ V_272 ] ) ;
}
F_189 ( V_34 -> V_26 ) ;
F_189 ( V_34 -> V_29 ) ;
}
int F_538 ( struct V_334 * V_34 , struct V_334 * V_35 )
{
struct V_28 * V_29 ;
struct V_26 * V_26 ;
int V_272 ;
V_34 -> V_26 = F_177 ( sizeof( V_26 ) * V_731 , V_274 ) ;
if ( ! V_34 -> V_26 )
goto V_756;
V_34 -> V_29 = F_177 ( sizeof( V_29 ) * V_731 , V_274 ) ;
if ( ! V_34 -> V_29 )
goto V_756;
V_34 -> V_336 = V_74 ;
F_336 ( F_301 ( V_34 ) ) ;
F_537 (i) {
V_26 = F_539 ( sizeof( struct V_26 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_26 )
goto V_756;
V_29 = F_539 ( sizeof( struct V_28 ) ,
V_274 , F_116 ( V_272 ) ) ;
if ( ! V_29 )
goto V_757;
F_530 ( V_26 ) ;
F_540 ( V_34 , V_26 , V_29 , V_272 , V_35 -> V_29 [ V_272 ] ) ;
F_61 ( V_29 ) ;
}
return 1 ;
V_757:
F_189 ( V_26 ) ;
V_756:
return 0 ;
}
void F_541 ( struct V_334 * V_34 )
{
struct V_28 * V_29 ;
struct V_25 * V_25 ;
int V_272 ;
F_537 (i) {
V_25 = F_124 ( V_272 ) ;
V_29 = V_34 -> V_29 [ V_272 ] ;
F_542 ( & V_25 -> V_257 ) ;
F_317 ( V_25 ) ;
F_64 ( V_29 ) ;
F_332 ( V_34 , V_272 ) ;
F_543 ( & V_25 -> V_257 ) ;
}
}
void F_544 ( struct V_334 * V_34 )
{
unsigned long V_115 ;
struct V_25 * V_25 ;
int V_1 ;
F_537 (cpu) {
if ( V_34 -> V_29 [ V_1 ] )
F_256 ( V_34 -> V_29 [ V_1 ] ) ;
if ( ! V_34 -> V_26 [ V_1 ] -> V_33 )
continue;
V_25 = F_124 ( V_1 ) ;
F_475 ( & V_25 -> V_257 , V_115 ) ;
F_29 ( V_34 -> V_26 [ V_1 ] ) ;
F_476 ( & V_25 -> V_257 , V_115 ) ;
}
}
void F_540 ( struct V_334 * V_34 , struct V_26 * V_26 ,
struct V_28 * V_29 , int V_1 ,
struct V_28 * V_35 )
{
struct V_25 * V_25 = F_124 ( V_1 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_25 = V_25 ;
F_340 ( V_26 ) ;
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
int F_545 ( struct V_334 * V_34 , unsigned long V_336 )
{
int V_272 ;
if ( ! V_34 -> V_29 [ 0 ] )
return - V_217 ;
V_336 = F_158 ( V_336 , F_546 ( V_338 ) , F_546 ( V_758 ) ) ;
F_547 ( & V_759 ) ;
if ( V_34 -> V_336 == V_336 )
goto V_760;
V_34 -> V_336 = V_336 ;
F_537 (i) {
struct V_25 * V_25 = F_124 ( V_272 ) ;
struct V_28 * V_29 = V_34 -> V_29 [ V_272 ] ;
struct V_378 V_379 ;
F_437 ( V_25 , & V_379 ) ;
F_317 ( V_25 ) ;
F_59 (se) {
F_249 ( V_29 , V_375 ) ;
F_219 ( V_29 ) ;
}
F_439 ( V_25 , & V_379 ) ;
}
V_760:
F_548 ( & V_759 ) ;
return 0 ;
}
void F_536 ( struct V_334 * V_34 ) { }
int F_538 ( struct V_334 * V_34 , struct V_334 * V_35 )
{
return 1 ;
}
void F_541 ( struct V_334 * V_34 ) { }
void F_544 ( struct V_334 * V_34 ) { }
static unsigned int F_549 ( struct V_25 * V_25 , struct V_27 * V_154 )
{
struct V_28 * V_29 = & V_154 -> V_29 ;
unsigned int V_761 = 0 ;
if ( V_25 -> V_42 . V_73 . V_5 )
V_761 = F_550 ( F_58 ( F_23 ( V_29 ) , V_29 ) ) ;
return V_761 ;
}
void F_551 ( struct V_762 * V_763 , int V_1 )
{
struct V_26 * V_26 , * V_616 ;
F_134 () ;
F_438 (cpu_rq(cpu), cfs_rq, pos)
F_552 ( V_763 , V_1 , V_26 ) ;
F_142 () ;
}
void F_553 ( struct V_27 * V_30 , struct V_762 * V_763 )
{
int V_156 ;
unsigned long V_764 = 0 , V_765 = 0 , V_766 = 0 , V_767 = 0 ;
F_111 (node) {
if ( V_30 -> V_145 ) {
V_764 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 0 ) ] ;
V_765 = V_30 -> V_145 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
if ( V_30 -> V_137 ) {
V_766 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 0 ) ] ,
V_767 = V_30 -> V_137 -> V_147 [ F_105 ( V_146 , V_156 , 1 ) ] ;
}
F_554 ( V_763 , V_156 , V_764 , V_765 , V_766 , V_767 ) ;
}
}
T_13 void F_555 ( void )
{
#ifdef F_212
F_556 ( V_749 , F_512 ) ;
#ifdef F_357
V_729 . V_712 = V_224 ;
F_557 ( & V_729 . V_730 , V_768 ) ;
#endif
#endif
}
