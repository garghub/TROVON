static int F_1 ( void )
{
unsigned int V_1 = F_2 ( int , F_3 () , 8 ) ;
unsigned int V_2 ;
switch ( V_3 ) {
case V_4 :
V_2 = 1 ;
break;
case V_5 :
V_2 = V_1 ;
break;
case V_6 :
default:
V_2 = 1 + F_4 ( V_1 ) ;
break;
}
return V_2 ;
}
static void F_5 ( void )
{
unsigned int V_2 = F_1 () ;
#define F_6 ( T_1 ) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
F_6 ( V_7 ) ;
F_6 ( V_8 ) ;
F_6 ( V_9 ) ;
#undef F_6
}
void F_7 ( void )
{
F_5 () ;
}
static unsigned long
F_8 ( unsigned long V_10 , unsigned long V_11 ,
struct V_12 * V_13 )
{
T_2 V_14 ;
if ( F_9 ( V_11 > ( 1UL << V_15 ) ) )
V_14 = ( T_2 ) V_10 * F_10 ( V_11 ) ;
else
V_14 = ( T_2 ) V_10 ;
if ( ! V_13 -> V_16 ) {
unsigned long V_17 = F_10 ( V_13 -> V_11 ) ;
if ( V_18 > 32 && F_11 ( V_17 >= V_19 ) )
V_13 -> V_16 = 1 ;
else if ( F_11 ( ! V_17 ) )
V_13 -> V_16 = V_19 ;
else
V_13 -> V_16 = V_19 / V_17 ;
}
if ( F_11 ( V_14 > V_19 ) )
V_14 = F_12 ( F_12 ( V_14 , V_20 / 2 ) * V_13 -> V_16 ,
V_20 / 2 ) ;
else
V_14 = F_12 ( V_14 * V_13 -> V_16 , V_20 ) ;
return ( unsigned long ) F_13 ( V_14 , ( T_2 ) ( unsigned long ) V_21 ) ;
}
static inline struct V_22 * F_14 ( struct V_23 * V_23 )
{
return V_23 -> V_22 ;
}
static inline struct V_24 * F_15 ( struct V_25 * V_26 )
{
#ifdef F_16
F_17 ( ! F_18 ( V_26 ) ) ;
#endif
return F_19 ( V_26 , struct V_24 , V_26 ) ;
}
static inline struct V_23 * F_20 ( struct V_24 * V_27 )
{
return V_27 -> V_26 . V_23 ;
}
static inline struct V_23 * F_21 ( struct V_25 * V_26 )
{
return V_26 -> V_23 ;
}
static inline struct V_23 * F_22 ( struct V_25 * V_28 )
{
return V_28 -> V_29 ;
}
static inline void F_23 ( struct V_23 * V_23 )
{
if ( ! V_23 -> V_30 ) {
if ( V_23 -> V_31 -> V_32 &&
V_23 -> V_31 -> V_32 -> V_23 [ F_24 ( F_14 ( V_23 ) ) ] -> V_30 ) {
F_25 ( & V_23 -> V_33 ,
& F_14 ( V_23 ) -> V_33 ) ;
} else {
F_26 ( & V_23 -> V_33 ,
& F_14 ( V_23 ) -> V_33 ) ;
}
V_23 -> V_30 = 1 ;
F_27 ( V_23 , 0 ) ;
}
}
static inline void F_28 ( struct V_23 * V_23 )
{
if ( V_23 -> V_30 ) {
F_29 ( & V_23 -> V_33 ) ;
V_23 -> V_30 = 0 ;
}
}
static inline int
F_30 ( struct V_25 * V_26 , struct V_25 * V_34 )
{
if ( V_26 -> V_23 == V_34 -> V_23 )
return 1 ;
return 0 ;
}
static inline struct V_25 * F_31 ( struct V_25 * V_26 )
{
return V_26 -> V_32 ;
}
static inline int F_32 ( struct V_25 * V_26 )
{
int V_35 = 0 ;
F_33 (se)
V_35 ++ ;
return V_35 ;
}
static void
F_34 ( struct V_25 * * V_26 , struct V_25 * * V_34 )
{
int V_36 , V_37 ;
V_36 = F_32 ( * V_26 ) ;
V_37 = F_32 ( * V_34 ) ;
while ( V_36 > V_37 ) {
V_36 -- ;
* V_26 = F_31 ( * V_26 ) ;
}
while ( V_37 > V_36 ) {
V_37 -- ;
* V_34 = F_31 ( * V_34 ) ;
}
while ( ! F_30 ( * V_26 , * V_34 ) ) {
* V_26 = F_31 ( * V_26 ) ;
* V_34 = F_31 ( * V_34 ) ;
}
}
static inline struct V_24 * F_15 ( struct V_25 * V_26 )
{
return F_19 ( V_26 , struct V_24 , V_26 ) ;
}
static inline struct V_22 * F_14 ( struct V_23 * V_23 )
{
return F_19 ( V_23 , struct V_22 , V_38 ) ;
}
static inline struct V_23 * F_20 ( struct V_24 * V_27 )
{
return & F_35 ( V_27 ) -> V_38 ;
}
static inline struct V_23 * F_21 ( struct V_25 * V_26 )
{
struct V_24 * V_27 = F_15 ( V_26 ) ;
struct V_22 * V_22 = F_35 ( V_27 ) ;
return & V_22 -> V_38 ;
}
static inline struct V_23 * F_22 ( struct V_25 * V_28 )
{
return NULL ;
}
static inline void F_23 ( struct V_23 * V_23 )
{
}
static inline void F_28 ( struct V_23 * V_23 )
{
}
static inline int
F_30 ( struct V_25 * V_26 , struct V_25 * V_34 )
{
return 1 ;
}
static inline struct V_25 * F_31 ( struct V_25 * V_26 )
{
return NULL ;
}
static inline void
F_34 ( struct V_25 * * V_26 , struct V_25 * * V_34 )
{
}
static inline T_2 F_36 ( T_2 V_39 , T_2 V_40 )
{
T_3 V_41 = ( T_3 ) ( V_40 - V_39 ) ;
if ( V_41 > 0 )
V_39 = V_40 ;
return V_39 ;
}
static inline T_2 V_39 ( T_2 V_39 , T_2 V_40 )
{
T_3 V_41 = ( T_3 ) ( V_40 - V_39 ) ;
if ( V_41 < 0 )
V_39 = V_40 ;
return V_39 ;
}
static inline int F_37 ( struct V_25 * V_42 ,
struct V_25 * V_43 )
{
return ( T_3 ) ( V_42 -> V_40 - V_43 -> V_40 ) < 0 ;
}
static void F_38 ( struct V_23 * V_23 )
{
T_2 V_40 = V_23 -> V_39 ;
if ( V_23 -> V_44 )
V_40 = V_23 -> V_44 -> V_40 ;
if ( V_23 -> V_45 ) {
struct V_25 * V_26 = F_39 ( V_23 -> V_45 ,
struct V_25 ,
V_46 ) ;
if ( ! V_23 -> V_44 )
V_40 = V_26 -> V_40 ;
else
V_40 = V_39 ( V_40 , V_26 -> V_40 ) ;
}
V_23 -> V_39 = F_36 ( V_23 -> V_39 , V_40 ) ;
#ifndef F_40
F_41 () ;
V_23 -> V_47 = V_23 -> V_39 ;
#endif
}
static void F_42 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
struct V_48 * * V_49 = & V_23 -> V_50 . V_48 ;
struct V_48 * V_32 = NULL ;
struct V_25 * V_51 ;
int V_52 = 1 ;
while ( * V_49 ) {
V_32 = * V_49 ;
V_51 = F_39 ( V_32 , struct V_25 , V_46 ) ;
if ( F_37 ( V_26 , V_51 ) ) {
V_49 = & V_32 -> V_53 ;
} else {
V_49 = & V_32 -> V_54 ;
V_52 = 0 ;
}
}
if ( V_52 )
V_23 -> V_45 = & V_26 -> V_46 ;
F_43 ( & V_26 -> V_46 , V_32 , V_49 ) ;
F_44 ( & V_26 -> V_46 , & V_23 -> V_50 ) ;
}
static void F_45 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_45 == & V_26 -> V_46 ) {
struct V_48 * V_55 ;
V_55 = F_46 ( & V_26 -> V_46 ) ;
V_23 -> V_45 = V_55 ;
}
F_47 ( & V_26 -> V_46 , & V_23 -> V_50 ) ;
}
struct V_25 * F_48 ( struct V_23 * V_23 )
{
struct V_48 * V_56 = V_23 -> V_45 ;
if ( ! V_56 )
return NULL ;
return F_39 ( V_56 , struct V_25 , V_46 ) ;
}
static struct V_25 * F_49 ( struct V_25 * V_26 )
{
struct V_48 * V_57 = F_46 ( & V_26 -> V_46 ) ;
if ( ! V_57 )
return NULL ;
return F_39 ( V_57 , struct V_25 , V_46 ) ;
}
struct V_25 * F_50 ( struct V_23 * V_23 )
{
struct V_48 * V_58 = F_51 ( & V_23 -> V_50 ) ;
if ( ! V_58 )
return NULL ;
return F_39 ( V_58 , struct V_25 , V_46 ) ;
}
int F_52 ( struct V_59 * V_60 , int V_61 ,
void T_4 * V_62 , T_5 * V_63 ,
T_6 * V_64 )
{
int V_65 = F_53 ( V_60 , V_61 , V_62 , V_63 , V_64 ) ;
int V_2 = F_1 () ;
if ( V_65 || ! V_61 )
return V_65 ;
V_66 = F_54 ( V_67 ,
V_68 ) ;
#define F_55 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_55 ( V_7 ) ;
F_55 ( V_8 ) ;
F_55 ( V_9 ) ;
#undef F_55
return 0 ;
}
static inline unsigned long
F_56 ( unsigned long V_41 , struct V_25 * V_26 )
{
if ( F_11 ( V_26 -> V_69 . V_11 != V_70 ) )
V_41 = F_8 ( V_41 , V_70 , & V_26 -> V_69 ) ;
return V_41 ;
}
static T_2 F_57 ( unsigned long V_71 )
{
T_2 V_72 = V_67 ;
unsigned long V_73 = V_66 ;
if ( F_11 ( V_71 > V_73 ) ) {
V_72 = V_68 ;
V_72 *= V_71 ;
}
return V_72 ;
}
static T_2 F_58 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
T_2 V_74 = F_57 ( V_23 -> V_71 + ! V_26 -> V_75 ) ;
F_33 (se) {
struct V_12 * V_69 ;
struct V_12 V_13 ;
V_23 = F_21 ( V_26 ) ;
V_69 = & V_23 -> V_69 ;
if ( F_11 ( ! V_26 -> V_75 ) ) {
V_13 = V_23 -> V_69 ;
F_59 ( & V_13 , V_26 -> V_69 . V_11 ) ;
V_69 = & V_13 ;
}
V_74 = F_8 ( V_74 , V_26 -> V_69 . V_11 , V_69 ) ;
}
return V_74 ;
}
static T_2 F_60 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
return F_56 ( F_58 ( V_23 , V_26 ) , V_26 ) ;
}
static inline void
F_61 ( struct V_23 * V_23 , struct V_25 * V_44 ,
unsigned long V_10 )
{
unsigned long V_76 ;
F_62 ( V_44 -> V_77 . V_78 ,
F_63 ( ( T_2 ) V_10 , V_44 -> V_77 . V_78 ) ) ;
V_44 -> V_79 += V_10 ;
F_64 ( V_23 , V_80 , V_10 ) ;
V_76 = F_56 ( V_10 , V_44 ) ;
V_44 -> V_40 += V_76 ;
F_38 ( V_23 ) ;
}
static void F_65 ( struct V_23 * V_23 )
{
struct V_25 * V_44 = V_23 -> V_44 ;
T_2 V_81 = F_14 ( V_23 ) -> V_82 ;
unsigned long V_10 ;
if ( F_11 ( ! V_44 ) )
return;
V_10 = ( unsigned long ) ( V_81 - V_44 -> V_83 ) ;
if ( ! V_10 )
return;
F_61 ( V_23 , V_44 , V_10 ) ;
V_44 -> V_83 = V_81 ;
if ( F_18 ( V_44 ) ) {
struct V_24 * V_84 = F_15 ( V_44 ) ;
F_66 ( V_84 , V_10 , V_44 -> V_40 ) ;
F_67 ( V_84 , V_10 ) ;
F_68 ( V_84 , V_10 ) ;
}
F_69 ( V_23 , V_10 ) ;
}
static inline void
F_70 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_62 ( V_26 -> V_77 . V_85 , F_14 ( V_23 ) -> clock ) ;
}
static void F_71 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_44 )
F_70 ( V_23 , V_26 ) ;
}
static void
F_72 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_62 ( V_26 -> V_77 . V_86 , F_63 ( V_26 -> V_77 . V_86 ,
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_85 ) ) ;
F_62 ( V_26 -> V_77 . V_87 , V_26 -> V_77 . V_87 + 1 ) ;
F_62 ( V_26 -> V_77 . V_88 , V_26 -> V_77 . V_88 +
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_85 ) ;
#ifdef F_73
if ( F_18 ( V_26 ) ) {
F_74 ( F_15 ( V_26 ) ,
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_85 ) ;
}
#endif
F_62 ( V_26 -> V_77 . V_85 , 0 ) ;
}
static inline void
F_75 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_44 )
F_72 ( V_23 , V_26 ) ;
}
static inline void
F_76 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
V_26 -> V_83 = F_14 ( V_23 ) -> V_82 ;
}
static void F_77 ( struct V_24 * V_27 )
{
int V_89 ;
if ( ! V_27 -> V_90 )
return;
V_89 = F_78 ( V_27 -> V_90 -> V_91 ) ;
if ( V_27 -> V_91 == V_89 )
return;
V_27 -> V_91 = V_89 ;
}
void F_79 ( int V_92 , int V_93 , bool V_94 )
{
struct V_24 * V_27 = V_95 ;
if ( ! F_80 ( V_96 ) )
return;
if ( ! V_94 )
V_27 -> V_97 = F_13 ( V_98 ,
V_27 -> V_97 + F_81 ( 10 ) ) ;
F_77 ( V_27 ) ;
}
static void F_82 ( struct V_24 * V_27 )
{
F_78 ( V_27 -> V_90 -> V_91 ) ++ ;
V_27 -> V_90 -> V_99 = 0 ;
}
void F_83 ( struct V_100 * V_101 )
{
unsigned long V_102 , V_103 , V_81 = V_104 ;
struct V_24 * V_27 = V_95 ;
struct V_105 * V_90 = V_27 -> V_90 ;
struct V_106 * V_107 ;
unsigned long V_108 , V_109 ;
long V_93 ;
F_17 ( V_27 != F_19 ( V_101 , struct V_24 , V_110 ) ) ;
V_101 -> V_57 = V_101 ;
if ( V_27 -> V_111 & V_112 )
return;
if ( V_90 -> V_113 == V_114 )
V_90 -> V_113 = F_84 () ;
if ( V_90 -> V_113 != V_115 ) {
if ( F_84 () == V_90 -> V_113 &&
! F_80 ( V_116 ) )
return;
V_90 -> V_113 = V_115 ;
}
V_102 = V_90 -> V_117 ;
if ( F_85 ( V_81 , V_102 ) ) {
V_27 -> V_97 = V_118 ;
V_103 = V_81 + F_86 ( V_119 ) ;
F_87 ( & V_90 -> V_117 , V_103 ) ;
}
V_102 = V_90 -> V_120 ;
if ( F_88 ( V_81 , V_102 ) )
return;
if ( V_27 -> V_97 == 0 )
V_27 -> V_97 = V_118 ;
V_103 = V_81 + F_86 ( V_27 -> V_97 ) ;
if ( F_89 ( & V_90 -> V_120 , V_102 , V_103 ) != V_102 )
return;
if ( F_90 ( F_84 () ) )
return;
V_108 = V_90 -> V_99 ;
V_93 = V_121 ;
V_93 <<= 20 - V_122 ;
if ( ! V_93 )
return;
F_91 ( & V_90 -> V_123 ) ;
V_107 = F_92 ( V_90 , V_108 ) ;
if ( ! V_107 ) {
F_82 ( V_27 ) ;
V_108 = 0 ;
V_107 = V_90 -> V_124 ;
}
for (; V_107 ; V_107 = V_107 -> V_125 ) {
if ( ! F_93 ( V_107 ) )
continue;
if ( V_107 -> V_126 - V_107 -> V_127 < V_128 )
continue;
do {
V_108 = F_63 ( V_108 , V_107 -> V_127 ) ;
V_109 = F_94 ( V_108 + ( V_93 << V_122 ) , V_128 ) ;
V_109 = F_13 ( V_109 , V_107 -> V_126 ) ;
V_93 -= F_95 ( V_107 , V_108 , V_109 ) ;
V_108 = V_109 ;
if ( V_93 <= 0 )
goto V_129;
} while ( V_109 != V_107 -> V_126 );
}
V_129:
if ( V_107 )
V_90 -> V_99 = V_108 ;
else
F_82 ( V_27 ) ;
F_96 ( & V_90 -> V_123 ) ;
}
void F_97 ( struct V_22 * V_22 , struct V_24 * V_44 )
{
struct V_100 * V_101 = & V_44 -> V_110 ;
T_2 V_72 , V_81 ;
if ( ! V_44 -> V_90 || ( V_44 -> V_111 & V_112 ) || V_101 -> V_57 != V_101 )
return;
V_81 = V_44 -> V_26 . V_79 ;
V_72 = ( T_2 ) V_44 -> V_97 * V_130 ;
if ( V_81 - V_44 -> V_131 > V_72 ) {
if ( ! V_44 -> V_131 )
V_44 -> V_97 = V_118 ;
V_44 -> V_131 = V_81 ;
if ( ! F_88 ( V_104 , V_44 -> V_90 -> V_120 ) ) {
F_98 ( V_101 , F_83 ) ;
F_99 ( V_44 , V_101 , true ) ;
}
}
}
static void F_97 ( struct V_22 * V_22 , struct V_24 * V_44 )
{
}
static void
F_100 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_59 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_31 ( V_26 ) )
F_59 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
#ifdef F_101
if ( F_18 ( V_26 ) )
F_102 ( & V_26 -> V_132 , & F_14 ( V_23 ) -> V_133 ) ;
#endif
V_23 -> V_71 ++ ;
}
static void
F_103 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_104 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_31 ( V_26 ) )
F_104 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( F_18 ( V_26 ) )
F_105 ( & V_26 -> V_132 ) ;
V_23 -> V_71 -- ;
}
static inline long F_106 ( struct V_134 * V_31 , struct V_23 * V_23 )
{
long V_135 ;
V_135 = F_107 ( & V_31 -> V_136 ) ;
V_135 -= V_23 -> V_137 ;
V_135 += V_23 -> V_69 . V_11 ;
return V_135 ;
}
static long F_108 ( struct V_23 * V_23 , struct V_134 * V_31 )
{
long V_135 , V_69 , V_138 ;
V_135 = F_106 ( V_31 , V_23 ) ;
V_69 = V_23 -> V_69 . V_11 ;
V_138 = ( V_31 -> V_138 * V_69 ) ;
if ( V_135 )
V_138 /= V_135 ;
if ( V_138 < V_139 )
V_138 = V_139 ;
if ( V_138 > V_31 -> V_138 )
V_138 = V_31 -> V_138 ;
return V_138 ;
}
static inline long F_108 ( struct V_23 * V_23 , struct V_134 * V_31 )
{
return V_31 -> V_138 ;
}
static void F_109 ( struct V_23 * V_23 , struct V_25 * V_26 ,
unsigned long V_11 )
{
if ( V_26 -> V_75 ) {
if ( V_23 -> V_44 == V_26 )
F_65 ( V_23 ) ;
F_103 ( V_23 , V_26 ) ;
}
F_110 ( & V_26 -> V_69 , V_11 ) ;
if ( V_26 -> V_75 )
F_100 ( V_23 , V_26 ) ;
}
static void F_111 ( struct V_23 * V_23 )
{
struct V_134 * V_31 ;
struct V_25 * V_26 ;
long V_138 ;
V_31 = V_23 -> V_31 ;
V_26 = V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
if ( ! V_26 || F_112 ( V_23 ) )
return;
#ifndef F_101
if ( F_9 ( V_26 -> V_69 . V_11 == V_31 -> V_138 ) )
return;
#endif
V_138 = F_108 ( V_23 , V_31 ) ;
F_109 ( F_21 ( V_26 ) , V_26 , V_138 ) ;
}
static inline void F_111 ( struct V_23 * V_23 )
{
}
static T_7 T_2 F_113 ( T_2 V_140 , T_2 V_141 )
{
unsigned int V_142 ;
if ( ! V_141 )
return V_140 ;
else if ( F_11 ( V_141 > V_143 * 63 ) )
return 0 ;
V_142 = V_141 ;
if ( F_11 ( V_142 >= V_143 ) ) {
V_140 >>= V_142 / V_143 ;
V_142 %= V_143 ;
}
V_140 *= V_144 [ V_142 ] ;
return V_140 >> 32 ;
}
static T_8 F_114 ( T_2 V_141 )
{
T_8 V_145 = 0 ;
if ( F_9 ( V_141 <= V_143 ) )
return V_146 [ V_141 ] ;
else if ( F_11 ( V_141 >= V_147 ) )
return V_148 ;
do {
V_145 /= 2 ;
V_145 += V_146 [ V_143 ] ;
V_141 -= V_143 ;
} while ( V_141 > V_143 );
V_145 = F_113 ( V_145 , V_141 ) ;
return V_145 + V_146 [ V_141 ] ;
}
static T_7 int F_115 ( T_2 V_81 ,
struct V_149 * V_150 ,
int V_151 )
{
T_2 V_41 , V_152 ;
T_8 V_153 ;
int V_154 , V_155 = 0 ;
V_41 = V_81 - V_150 -> V_156 ;
if ( ( T_3 ) V_41 < 0 ) {
V_150 -> V_156 = V_81 ;
return 0 ;
}
V_41 >>= 10 ;
if ( ! V_41 )
return 0 ;
V_150 -> V_156 = V_81 ;
V_154 = V_150 -> V_157 % 1024 ;
if ( V_41 + V_154 >= 1024 ) {
V_155 = 1 ;
V_154 = 1024 - V_154 ;
if ( V_151 )
V_150 -> V_158 += V_154 ;
V_150 -> V_157 += V_154 ;
V_41 -= V_154 ;
V_152 = V_41 / 1024 ;
V_41 %= 1024 ;
V_150 -> V_158 = F_113 ( V_150 -> V_158 ,
V_152 + 1 ) ;
V_150 -> V_157 = F_113 ( V_150 -> V_157 ,
V_152 + 1 ) ;
V_153 = F_114 ( V_152 ) ;
if ( V_151 )
V_150 -> V_158 += V_153 ;
V_150 -> V_157 += V_153 ;
}
if ( V_151 )
V_150 -> V_158 += V_41 ;
V_150 -> V_157 += V_41 ;
return V_155 ;
}
static inline T_2 F_116 ( struct V_25 * V_26 )
{
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 V_159 = F_107 ( & V_23 -> V_160 ) ;
V_159 -= V_26 -> V_161 . V_162 ;
if ( ! V_159 )
return 0 ;
V_26 -> V_161 . V_163 = F_113 ( V_26 -> V_161 . V_163 , V_159 ) ;
V_26 -> V_161 . V_162 = 0 ;
return V_159 ;
}
static inline void F_117 ( struct V_23 * V_23 ,
int V_164 )
{
struct V_134 * V_31 = V_23 -> V_31 ;
T_3 V_165 ;
V_165 = V_23 -> V_166 + V_23 -> V_167 ;
V_165 -= V_23 -> V_137 ;
if ( V_164 || F_118 ( V_165 ) > V_23 -> V_137 / 8 ) {
F_119 ( V_165 , & V_31 -> V_136 ) ;
V_23 -> V_137 += V_165 ;
}
}
static inline void F_120 ( struct V_149 * V_150 ,
struct V_23 * V_23 )
{
struct V_134 * V_31 = V_23 -> V_31 ;
long V_145 ;
V_145 = F_121 ( V_150 -> V_158 << V_168 ,
V_150 -> V_157 + 1 ) ;
V_145 -= V_23 -> V_169 ;
if ( abs ( V_145 ) > V_23 -> V_169 / 64 ) {
F_122 ( V_145 , & V_31 -> V_170 ) ;
V_23 -> V_169 += V_145 ;
}
}
static inline void F_123 ( struct V_25 * V_26 )
{
struct V_23 * V_23 = F_22 ( V_26 ) ;
struct V_134 * V_31 = V_23 -> V_31 ;
int V_170 ;
T_2 V_145 ;
V_145 = V_23 -> V_137 * V_31 -> V_138 ;
V_26 -> V_161 . V_163 = F_124 ( V_145 ,
F_107 ( & V_31 -> V_136 ) + 1 ) ;
V_170 = F_125 ( & V_31 -> V_170 ) ;
if ( V_170 < V_70 ) {
V_26 -> V_161 . V_163 *= V_170 ;
V_26 -> V_161 . V_163 >>= V_168 ;
}
}
static inline void F_117 ( struct V_23 * V_23 ,
int V_164 ) {}
static inline void F_120 ( struct V_149 * V_150 ,
struct V_23 * V_23 ) {}
static inline void F_123 ( struct V_25 * V_26 ) {}
static inline void F_126 ( struct V_25 * V_26 )
{
T_8 V_145 ;
V_145 = V_26 -> V_161 . V_158 * F_10 ( V_26 -> V_69 . V_11 ) ;
V_145 /= ( V_26 -> V_161 . V_157 + 1 ) ;
V_26 -> V_161 . V_163 = F_127 ( V_145 ) ;
}
static long F_128 ( struct V_25 * V_26 )
{
long V_171 = V_26 -> V_161 . V_163 ;
if ( F_18 ( V_26 ) ) {
F_126 ( V_26 ) ;
} else {
F_120 ( & V_26 -> V_161 , F_22 ( V_26 ) ) ;
F_123 ( V_26 ) ;
}
return V_26 -> V_161 . V_163 - V_171 ;
}
static inline void F_129 ( struct V_23 * V_23 ,
long V_172 )
{
if ( F_9 ( V_172 < V_23 -> V_167 ) )
V_23 -> V_167 -= V_172 ;
else
V_23 -> V_167 = 0 ;
}
static inline void F_130 ( struct V_25 * V_26 ,
int V_173 )
{
struct V_23 * V_23 = F_21 ( V_26 ) ;
long V_174 ;
T_2 V_81 ;
if ( F_18 ( V_26 ) )
V_81 = F_131 ( V_23 ) ;
else
V_81 = F_131 ( F_22 ( V_26 ) ) ;
if ( ! F_115 ( V_81 , & V_26 -> V_161 , V_26 -> V_75 ) )
return;
V_174 = F_128 ( V_26 ) ;
if ( ! V_173 )
return;
if ( V_26 -> V_75 )
V_23 -> V_166 += V_174 ;
else
F_129 ( V_23 , - V_174 ) ;
}
static void F_27 ( struct V_23 * V_23 , int V_164 )
{
T_2 V_81 = F_131 ( V_23 ) >> 20 ;
T_2 V_159 ;
V_159 = V_81 - V_23 -> V_175 ;
if ( ! V_159 && ! V_164 )
return;
if ( F_107 ( & V_23 -> V_176 ) ) {
T_2 V_176 = F_132 ( & V_23 -> V_176 , 0 ) ;
F_129 ( V_23 , V_176 ) ;
}
if ( V_159 ) {
V_23 -> V_167 = F_113 ( V_23 -> V_167 ,
V_159 ) ;
F_119 ( V_159 , & V_23 -> V_160 ) ;
V_23 -> V_175 = V_81 ;
}
F_117 ( V_23 , V_164 ) ;
}
static inline void F_133 ( struct V_22 * V_22 , int V_151 )
{
F_115 ( V_22 -> V_82 , & V_22 -> V_161 , V_151 ) ;
F_120 ( & V_22 -> V_161 , & V_22 -> V_38 ) ;
}
static inline void F_134 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_177 )
{
if ( F_11 ( V_26 -> V_161 . V_162 <= 0 ) ) {
V_26 -> V_161 . V_156 = F_14 ( V_23 ) -> V_82 ;
if ( V_26 -> V_161 . V_162 ) {
V_26 -> V_161 . V_156 -= ( - V_26 -> V_161 . V_162 )
<< 20 ;
F_130 ( V_26 , 0 ) ;
V_26 -> V_161 . V_162 = 0 ;
}
V_177 = 0 ;
} else {
F_116 ( V_26 ) ;
}
if ( V_177 ) {
F_129 ( V_23 , V_26 -> V_161 . V_163 ) ;
F_130 ( V_26 , 0 ) ;
}
V_23 -> V_166 += V_26 -> V_161 . V_163 ;
F_27 ( V_23 , ! V_177 ) ;
}
static inline void F_135 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_178 )
{
F_130 ( V_26 , 1 ) ;
F_27 ( V_23 , ! V_178 ) ;
V_23 -> V_166 -= V_26 -> V_161 . V_163 ;
if ( V_178 ) {
V_23 -> V_167 += V_26 -> V_161 . V_163 ;
V_26 -> V_161 . V_162 = F_107 ( & V_23 -> V_160 ) ;
}
}
static inline void F_130 ( struct V_25 * V_26 ,
int V_173 ) {}
static inline void F_133 ( struct V_22 * V_22 , int V_151 ) {}
static inline void F_134 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_177 ) {}
static inline void F_135 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_178 ) {}
static inline void F_27 ( struct V_23 * V_23 ,
int V_164 ) {}
static void F_136 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_73
struct V_24 * V_179 = NULL ;
if ( F_18 ( V_26 ) )
V_179 = F_15 ( V_26 ) ;
if ( V_26 -> V_77 . V_180 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_180 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_181 ) )
V_26 -> V_77 . V_181 = V_41 ;
V_26 -> V_77 . V_180 = 0 ;
V_26 -> V_77 . V_182 += V_41 ;
if ( V_179 ) {
F_137 ( V_179 , V_41 >> 10 , 1 ) ;
F_138 ( V_179 , V_41 ) ;
}
}
if ( V_26 -> V_77 . V_183 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_183 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_184 ) )
V_26 -> V_77 . V_184 = V_41 ;
V_26 -> V_77 . V_183 = 0 ;
V_26 -> V_77 . V_182 += V_41 ;
if ( V_179 ) {
if ( V_179 -> V_185 ) {
V_26 -> V_77 . V_186 += V_41 ;
V_26 -> V_77 . V_187 ++ ;
F_139 ( V_179 , V_41 ) ;
}
F_140 ( V_179 , V_41 ) ;
if ( F_11 ( V_188 == V_189 ) ) {
F_141 ( V_189 ,
( void * ) F_142 ( V_179 ) ,
V_41 >> 20 ) ;
}
F_137 ( V_179 , V_41 >> 10 , 0 ) ;
}
}
#endif
}
static void F_143 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_16
T_3 V_190 = V_26 -> V_40 - V_23 -> V_39 ;
if ( V_190 < 0 )
V_190 = - V_190 ;
if ( V_190 > 3 * V_67 )
F_144 ( V_23 , V_191 ) ;
#endif
}
static void
F_145 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_192 )
{
T_2 V_40 = V_23 -> V_39 ;
if ( V_192 && F_146 ( V_193 ) )
V_40 += F_60 ( V_23 , V_26 ) ;
if ( ! V_192 ) {
unsigned long V_194 = V_67 ;
if ( F_146 ( V_195 ) )
V_194 >>= 1 ;
V_40 -= V_194 ;
}
V_40 = F_36 ( V_26 -> V_40 , V_40 ) ;
V_26 -> V_40 = V_40 ;
}
static void
F_147 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_111 )
{
if ( ! ( V_111 & V_196 ) || ( V_111 & V_197 ) )
V_26 -> V_40 += V_23 -> V_39 ;
F_65 ( V_23 ) ;
F_134 ( V_23 , V_26 , V_111 & V_196 ) ;
F_100 ( V_23 , V_26 ) ;
F_111 ( V_23 ) ;
if ( V_111 & V_196 ) {
F_145 ( V_23 , V_26 , 0 ) ;
F_136 ( V_23 , V_26 ) ;
}
F_71 ( V_23 , V_26 ) ;
F_143 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_42 ( V_23 , V_26 ) ;
V_26 -> V_75 = 1 ;
if ( V_23 -> V_71 == 1 ) {
F_23 ( V_23 ) ;
F_148 ( V_23 ) ;
}
}
static void F_149 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_58 == V_26 )
V_23 -> V_58 = NULL ;
else
break;
}
}
static void F_150 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
V_23 -> V_57 = NULL ;
else
break;
}
}
static void F_151 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_198 == V_26 )
V_23 -> V_198 = NULL ;
else
break;
}
}
static void F_152 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_58 == V_26 )
F_149 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
F_150 ( V_26 ) ;
if ( V_23 -> V_198 == V_26 )
F_151 ( V_26 ) ;
}
static void
F_153 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_111 )
{
F_65 ( V_23 ) ;
F_135 ( V_23 , V_26 , V_111 & V_199 ) ;
F_75 ( V_23 , V_26 ) ;
if ( V_111 & V_199 ) {
#ifdef F_73
if ( F_18 ( V_26 ) ) {
struct V_24 * V_179 = F_15 ( V_26 ) ;
if ( V_179 -> V_200 & V_201 )
V_26 -> V_77 . V_180 = F_14 ( V_23 ) -> clock ;
if ( V_179 -> V_200 & V_202 )
V_26 -> V_77 . V_183 = F_14 ( V_23 ) -> clock ;
}
#endif
}
F_152 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_45 ( V_23 , V_26 ) ;
V_26 -> V_75 = 0 ;
F_103 ( V_23 , V_26 ) ;
if ( ! ( V_111 & V_199 ) )
V_26 -> V_40 -= V_23 -> V_39 ;
F_154 ( V_23 ) ;
F_38 ( V_23 ) ;
F_111 ( V_23 ) ;
}
static void
F_155 ( struct V_23 * V_23 , struct V_25 * V_44 )
{
unsigned long V_203 , V_10 ;
struct V_25 * V_26 ;
T_3 V_41 ;
V_203 = F_58 ( V_23 , V_44 ) ;
V_10 = V_44 -> V_79 - V_44 -> V_204 ;
if ( V_10 > V_203 ) {
F_156 ( F_14 ( V_23 ) -> V_44 ) ;
F_152 ( V_23 , V_44 ) ;
return;
}
if ( V_10 < V_68 )
return;
V_26 = F_48 ( V_23 ) ;
V_41 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_41 < 0 )
return;
if ( V_41 > V_203 )
F_156 ( F_14 ( V_23 ) -> V_44 ) ;
}
static void
F_157 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 -> V_75 ) {
F_72 ( V_23 , V_26 ) ;
F_45 ( V_23 , V_26 ) ;
}
F_76 ( V_23 , V_26 ) ;
V_23 -> V_44 = V_26 ;
#ifdef F_73
if ( F_14 ( V_23 ) -> V_69 . V_11 >= 2 * V_26 -> V_69 . V_11 ) {
V_26 -> V_77 . V_205 = F_63 ( V_26 -> V_77 . V_205 ,
V_26 -> V_79 - V_26 -> V_204 ) ;
}
#endif
V_26 -> V_204 = V_26 -> V_79 ;
}
static struct V_25 * F_158 ( struct V_23 * V_23 )
{
struct V_25 * V_26 = F_48 ( V_23 ) ;
struct V_25 * V_56 = V_26 ;
if ( V_23 -> V_198 == V_26 ) {
struct V_25 * V_206 = F_49 ( V_26 ) ;
if ( V_206 && F_159 ( V_206 , V_56 ) < 1 )
V_26 = V_206 ;
}
if ( V_23 -> V_58 && F_159 ( V_23 -> V_58 , V_56 ) < 1 )
V_26 = V_23 -> V_58 ;
if ( V_23 -> V_57 && F_159 ( V_23 -> V_57 , V_56 ) < 1 )
V_26 = V_23 -> V_57 ;
F_152 ( V_23 , V_26 ) ;
return V_26 ;
}
static void F_160 ( struct V_23 * V_23 , struct V_25 * V_207 )
{
if ( V_207 -> V_75 )
F_65 ( V_23 ) ;
F_161 ( V_23 ) ;
F_143 ( V_23 , V_207 ) ;
if ( V_207 -> V_75 ) {
F_70 ( V_23 , V_207 ) ;
F_42 ( V_23 , V_207 ) ;
F_130 ( V_207 , 1 ) ;
}
V_23 -> V_44 = NULL ;
}
static void
F_162 ( struct V_23 * V_23 , struct V_25 * V_44 , int V_208 )
{
F_65 ( V_23 ) ;
F_130 ( V_44 , 1 ) ;
F_27 ( V_23 , 1 ) ;
#ifdef F_163
if ( V_208 ) {
F_156 ( F_14 ( V_23 ) -> V_44 ) ;
return;
}
if ( ! F_146 ( V_209 ) &&
F_164 ( & F_14 ( V_23 ) -> V_210 ) )
return;
#endif
if ( V_23 -> V_71 > 1 )
F_155 ( V_23 , V_44 ) ;
}
static inline bool F_165 ( void )
{
return F_166 ( & V_211 ) ;
}
void F_167 ( int V_212 , int V_213 )
{
if ( V_212 && ! V_213 )
F_168 ( & V_211 ) ;
else if ( ! V_212 && V_213 )
F_169 ( & V_211 ) ;
}
static bool F_165 ( void )
{
return true ;
}
void F_167 ( int V_212 , int V_213 ) {}
static inline T_2 F_170 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_171 ( void )
{
return ( T_2 ) V_214 * V_215 ;
}
void F_172 ( struct V_216 * V_217 )
{
T_2 V_81 ;
if ( V_217 -> V_218 == V_219 )
return;
V_81 = F_173 ( F_174 () ) ;
V_217 -> V_220 = V_217 -> V_218 ;
V_217 -> V_221 = V_81 + F_175 ( V_217 -> V_72 ) ;
}
static inline struct V_216 * F_176 ( struct V_134 * V_31 )
{
return & V_31 -> V_216 ;
}
static inline T_2 F_131 ( struct V_23 * V_23 )
{
if ( F_11 ( V_23 -> V_222 ) )
return V_23 -> V_223 ;
return F_14 ( V_23 ) -> V_82 - V_23 -> V_224 ;
}
static int F_177 ( struct V_23 * V_23 )
{
struct V_134 * V_31 = V_23 -> V_31 ;
struct V_216 * V_217 = F_176 ( V_31 ) ;
T_2 V_225 = 0 , V_226 , V_227 ;
V_226 = F_171 () - V_23 -> V_228 ;
F_178 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 == V_219 )
V_225 = V_226 ;
else {
if ( ! V_217 -> V_230 ) {
F_172 ( V_217 ) ;
F_179 ( V_217 ) ;
}
if ( V_217 -> V_220 > 0 ) {
V_225 = F_13 ( V_217 -> V_220 , V_226 ) ;
V_217 -> V_220 -= V_225 ;
V_217 -> V_231 = 0 ;
}
}
V_227 = V_217 -> V_221 ;
F_180 ( & V_217 -> V_229 ) ;
V_23 -> V_228 += V_225 ;
if ( ( T_3 ) ( V_227 - V_23 -> V_221 ) > 0 )
V_23 -> V_221 = V_227 ;
return V_23 -> V_228 > 0 ;
}
static void F_181 ( struct V_23 * V_23 )
{
struct V_216 * V_217 = F_176 ( V_23 -> V_31 ) ;
struct V_22 * V_22 = F_14 ( V_23 ) ;
if ( F_9 ( ( T_3 ) ( V_22 -> clock - V_23 -> V_221 ) < 0 ) )
return;
if ( V_23 -> V_228 < 0 )
return;
if ( ( T_3 ) ( V_23 -> V_221 - V_217 -> V_221 ) >= 0 ) {
V_23 -> V_221 += V_232 ;
} else {
V_23 -> V_228 = 0 ;
}
}
static void F_182 ( struct V_23 * V_23 ,
unsigned long V_10 )
{
V_23 -> V_228 -= V_10 ;
F_181 ( V_23 ) ;
if ( F_9 ( V_23 -> V_228 > 0 ) )
return;
if ( ! F_177 ( V_23 ) && F_9 ( V_23 -> V_44 ) )
F_156 ( F_14 ( V_23 ) -> V_44 ) ;
}
static T_7
void F_69 ( struct V_23 * V_23 , unsigned long V_10 )
{
if ( ! F_165 () || ! V_23 -> V_233 )
return;
F_182 ( V_23 , V_10 ) ;
}
static inline int F_183 ( struct V_23 * V_23 )
{
return F_165 () && V_23 -> V_234 ;
}
static inline int F_112 ( struct V_23 * V_23 )
{
return F_165 () && V_23 -> V_222 ;
}
static inline int F_184 ( struct V_134 * V_31 ,
int V_235 , int V_236 )
{
struct V_23 * V_237 , * V_238 ;
V_237 = V_31 -> V_23 [ V_235 ] ;
V_238 = V_31 -> V_23 [ V_236 ] ;
return F_112 ( V_237 ) ||
F_112 ( V_238 ) ;
}
static int F_185 ( struct V_134 * V_31 , void * V_239 )
{
struct V_22 * V_22 = V_239 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
V_23 -> V_222 -- ;
#ifdef F_101
if ( ! V_23 -> V_222 ) {
V_23 -> V_224 += V_22 -> V_82 -
V_23 -> V_223 ;
}
#endif
return 0 ;
}
static int F_186 ( struct V_134 * V_31 , void * V_239 )
{
struct V_22 * V_22 = V_239 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
if ( ! V_23 -> V_222 )
V_23 -> V_223 = V_22 -> V_82 ;
V_23 -> V_222 ++ ;
return 0 ;
}
static void F_187 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_216 * V_217 = F_176 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
long V_240 , V_241 = 1 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
F_188 () ;
F_189 ( V_23 -> V_31 , F_186 , V_242 , ( void * ) V_22 ) ;
F_190 () ;
V_240 = V_23 -> V_243 ;
F_33 (se) {
struct V_23 * V_244 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 )
break;
if ( V_241 )
F_153 ( V_244 , V_26 , V_199 ) ;
V_244 -> V_243 -= V_240 ;
if ( V_244 -> V_69 . V_11 )
V_241 = 0 ;
}
if ( ! V_26 )
V_22 -> V_71 -= V_240 ;
V_23 -> V_234 = 1 ;
V_23 -> V_245 = V_22 -> clock ;
F_178 ( & V_217 -> V_229 ) ;
F_26 ( & V_23 -> V_246 , & V_217 -> V_247 ) ;
F_180 ( & V_217 -> V_229 ) ;
}
void F_191 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_216 * V_217 = F_176 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
int V_248 = 1 ;
long V_240 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
V_23 -> V_234 = 0 ;
F_178 ( & V_217 -> V_229 ) ;
V_217 -> V_249 += V_22 -> clock - V_23 -> V_245 ;
F_29 ( & V_23 -> V_246 ) ;
F_180 ( & V_217 -> V_229 ) ;
F_192 ( V_22 ) ;
F_189 ( V_23 -> V_31 , V_242 , F_185 , ( void * ) V_22 ) ;
if ( ! V_23 -> V_69 . V_11 )
return;
V_240 = V_23 -> V_243 ;
F_33 (se) {
if ( V_26 -> V_75 )
V_248 = 0 ;
V_23 = F_21 ( V_26 ) ;
if ( V_248 )
F_147 ( V_23 , V_26 , V_196 ) ;
V_23 -> V_243 += V_240 ;
if ( F_183 ( V_23 ) )
break;
}
if ( ! V_26 )
V_22 -> V_71 += V_240 ;
if ( V_22 -> V_44 == V_22 -> V_231 && V_22 -> V_38 . V_71 )
F_156 ( V_22 -> V_44 ) ;
}
static T_2 F_193 ( struct V_216 * V_217 ,
T_2 V_250 , T_2 V_227 )
{
struct V_23 * V_23 ;
T_2 V_220 = V_250 ;
F_188 () ;
F_194 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_178 ( & V_22 -> V_229 ) ;
if ( ! F_183 ( V_23 ) )
goto V_57;
V_220 = - V_23 -> V_228 + 1 ;
if ( V_220 > V_250 )
V_220 = V_250 ;
V_250 -= V_220 ;
V_23 -> V_228 += V_220 ;
V_23 -> V_221 = V_227 ;
if ( V_23 -> V_228 > 0 )
F_191 ( V_23 ) ;
V_57:
F_180 ( & V_22 -> V_229 ) ;
if ( ! V_250 )
break;
}
F_190 () ;
return V_250 ;
}
static int F_195 ( struct V_216 * V_217 , int V_251 )
{
T_2 V_220 , V_221 ;
int V_231 = 1 , V_234 ;
F_178 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 == V_219 )
goto V_252;
V_234 = ! F_196 ( & V_217 -> V_247 ) ;
V_231 = V_217 -> V_231 && ! V_234 ;
V_217 -> V_253 += V_251 ;
if ( V_231 )
goto V_252;
F_172 ( V_217 ) ;
if ( ! V_234 ) {
V_217 -> V_231 = 1 ;
goto V_252;
}
V_217 -> V_254 += V_251 ;
V_220 = V_217 -> V_220 ;
V_221 = V_217 -> V_221 ;
V_217 -> V_220 = 0 ;
while ( V_234 && V_220 > 0 ) {
F_180 ( & V_217 -> V_229 ) ;
V_220 = F_193 ( V_217 , V_220 ,
V_221 ) ;
F_178 ( & V_217 -> V_229 ) ;
V_234 = ! F_196 ( & V_217 -> V_247 ) ;
}
V_217 -> V_220 = V_220 ;
V_217 -> V_231 = 0 ;
V_252:
if ( V_231 )
V_217 -> V_230 = 0 ;
F_180 ( & V_217 -> V_229 ) ;
return V_231 ;
}
static int F_197 ( struct V_216 * V_217 , T_2 V_255 )
{
struct V_256 * V_257 = & V_217 -> V_258 ;
T_2 V_250 ;
if ( F_198 ( V_257 ) )
return 1 ;
V_250 = F_175 ( F_199 ( V_257 ) ) ;
if ( V_250 < V_255 )
return 1 ;
return 0 ;
}
static void F_200 ( struct V_216 * V_217 )
{
T_2 V_259 = V_260 + V_261 ;
if ( F_197 ( V_217 , V_259 ) )
return;
F_201 ( & V_217 -> V_262 ,
F_202 ( V_260 ) ) ;
}
static void F_203 ( struct V_23 * V_23 )
{
struct V_216 * V_217 = F_176 ( V_23 -> V_31 ) ;
T_3 V_263 = V_23 -> V_228 - V_264 ;
if ( V_263 <= 0 )
return;
F_178 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 != V_219 &&
V_23 -> V_221 == V_217 -> V_221 ) {
V_217 -> V_220 += V_263 ;
if ( V_217 -> V_220 > F_171 () &&
! F_196 ( & V_217 -> V_247 ) )
F_200 ( V_217 ) ;
}
F_180 ( & V_217 -> V_229 ) ;
V_23 -> V_228 -= V_263 ;
}
static T_7 void F_154 ( struct V_23 * V_23 )
{
if ( ! F_165 () )
return;
if ( ! V_23 -> V_233 || V_23 -> V_71 )
return;
F_203 ( V_23 ) ;
}
static void F_204 ( struct V_216 * V_217 )
{
T_2 V_220 = 0 , V_74 = F_171 () ;
T_2 V_227 ;
if ( F_197 ( V_217 , V_261 ) )
return;
F_178 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 != V_219 && V_217 -> V_220 > V_74 ) {
V_220 = V_217 -> V_220 ;
V_217 -> V_220 = 0 ;
}
V_227 = V_217 -> V_221 ;
F_180 ( & V_217 -> V_229 ) ;
if ( ! V_220 )
return;
V_220 = F_193 ( V_217 , V_220 , V_227 ) ;
F_178 ( & V_217 -> V_229 ) ;
if ( V_227 == V_217 -> V_221 )
V_217 -> V_220 = V_220 ;
F_180 ( & V_217 -> V_229 ) ;
}
static void F_148 ( struct V_23 * V_23 )
{
if ( ! F_165 () )
return;
if ( ! V_23 -> V_233 || V_23 -> V_44 )
return;
if ( F_183 ( V_23 ) )
return;
F_69 ( V_23 , 0 ) ;
if ( V_23 -> V_228 <= 0 )
F_187 ( V_23 ) ;
}
static void F_161 ( struct V_23 * V_23 )
{
if ( ! F_165 () )
return;
if ( F_9 ( ! V_23 -> V_233 || V_23 -> V_228 > 0 ) )
return;
if ( F_183 ( V_23 ) )
return;
F_187 ( V_23 ) ;
}
static enum V_265 F_205 ( struct V_256 * V_266 )
{
struct V_216 * V_217 =
F_19 ( V_266 , struct V_216 , V_262 ) ;
F_204 ( V_217 ) ;
return V_267 ;
}
static enum V_265 F_206 ( struct V_256 * V_266 )
{
struct V_216 * V_217 =
F_19 ( V_266 , struct V_216 , V_258 ) ;
T_9 V_81 ;
int V_251 ;
int V_231 = 0 ;
for (; ; ) {
V_81 = F_207 ( V_266 ) ;
V_251 = F_208 ( V_266 , V_81 , V_217 -> V_72 ) ;
if ( ! V_251 )
break;
V_231 = F_195 ( V_217 , V_251 ) ;
}
return V_231 ? V_267 : V_268 ;
}
void F_209 ( struct V_216 * V_217 )
{
F_210 ( & V_217 -> V_229 ) ;
V_217 -> V_220 = 0 ;
V_217 -> V_218 = V_219 ;
V_217 -> V_72 = F_202 ( F_170 () ) ;
F_211 ( & V_217 -> V_247 ) ;
F_212 ( & V_217 -> V_258 , V_269 , V_270 ) ;
V_217 -> V_258 . V_271 = F_206 ;
F_212 ( & V_217 -> V_262 , V_269 , V_270 ) ;
V_217 -> V_262 . V_271 = F_205 ;
}
static void F_213 ( struct V_23 * V_23 )
{
V_23 -> V_233 = 0 ;
F_211 ( & V_23 -> V_246 ) ;
}
void F_179 ( struct V_216 * V_217 )
{
while ( F_11 ( F_164 ( & V_217 -> V_258 ) ) ) {
F_180 ( & V_217 -> V_229 ) ;
F_214 ( & V_217 -> V_258 ) ;
F_178 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_230 )
return;
}
V_217 -> V_230 = 1 ;
F_201 ( & V_217 -> V_258 , V_217 -> V_72 ) ;
}
static void F_215 ( struct V_216 * V_217 )
{
F_214 ( & V_217 -> V_258 ) ;
F_214 ( & V_217 -> V_262 ) ;
}
static void T_10 F_216 ( struct V_22 * V_22 )
{
struct V_23 * V_23 ;
F_217 (rq, cfs_rq) {
struct V_216 * V_217 = F_176 ( V_23 -> V_31 ) ;
if ( ! V_23 -> V_233 )
continue;
V_23 -> V_228 = V_217 -> V_218 ;
if ( F_183 ( V_23 ) )
F_191 ( V_23 ) ;
}
}
static inline T_2 F_131 ( struct V_23 * V_23 )
{
return F_14 ( V_23 ) -> V_82 ;
}
static void F_69 ( struct V_23 * V_23 ,
unsigned long V_10 ) {}
static void F_161 ( struct V_23 * V_23 ) {}
static void F_148 ( struct V_23 * V_23 ) {}
static T_7 void F_154 ( struct V_23 * V_23 ) {}
static inline int F_183 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_112 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_184 ( struct V_134 * V_31 ,
int V_235 , int V_236 )
{
return 0 ;
}
void F_209 ( struct V_216 * V_217 ) {}
static void F_213 ( struct V_23 * V_23 ) {}
static inline struct V_216 * F_176 ( struct V_134 * V_31 )
{
return NULL ;
}
static inline void F_215 ( struct V_216 * V_217 ) {}
static inline void F_216 ( struct V_22 * V_22 ) {}
static void F_218 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_219 ( F_35 ( V_27 ) != V_22 ) ;
if ( V_23 -> V_71 > 1 ) {
T_2 V_74 = F_58 ( V_23 , V_26 ) ;
T_2 V_272 = V_26 -> V_79 - V_26 -> V_204 ;
T_3 V_41 = V_74 - V_272 ;
if ( V_41 < 0 ) {
if ( V_22 -> V_44 == V_27 )
F_156 ( V_27 ) ;
return;
}
if ( V_22 -> V_44 != V_27 )
V_41 = F_220 ( T_3 , 10000LL , V_41 ) ;
F_221 ( V_22 , V_41 ) ;
}
}
static void F_222 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
if ( ! F_223 ( V_22 ) || V_44 -> V_273 != & V_274 )
return;
if ( F_21 ( & V_44 -> V_26 ) -> V_71 < V_66 )
F_218 ( V_22 , V_44 ) ;
}
static inline void
F_218 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
}
static inline void F_222 ( struct V_22 * V_22 )
{
}
static void
F_224 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_111 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
F_33 (se) {
if ( V_26 -> V_75 )
break;
V_23 = F_21 ( V_26 ) ;
F_147 ( V_23 , V_26 , V_111 ) ;
if ( F_183 ( V_23 ) )
break;
V_23 -> V_243 ++ ;
V_111 = V_196 ;
}
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_243 ++ ;
if ( F_183 ( V_23 ) )
break;
F_111 ( V_23 ) ;
F_130 ( V_26 , 1 ) ;
}
if ( ! V_26 ) {
F_133 ( V_22 , V_22 -> V_71 ) ;
F_225 ( V_22 ) ;
}
F_222 ( V_22 ) ;
}
static void F_226 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_111 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
int V_275 = V_111 & V_199 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_153 ( V_23 , V_26 , V_111 ) ;
if ( F_183 ( V_23 ) )
break;
V_23 -> V_243 -- ;
if ( V_23 -> V_69 . V_11 ) {
if ( V_275 && F_31 ( V_26 ) )
F_227 ( F_31 ( V_26 ) ) ;
V_26 = F_31 ( V_26 ) ;
break;
}
V_111 |= V_199 ;
}
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_243 -- ;
if ( F_183 ( V_23 ) )
break;
F_111 ( V_23 ) ;
F_130 ( V_26 , 1 ) ;
}
if ( ! V_26 ) {
F_228 ( V_22 ) ;
F_133 ( V_22 , 1 ) ;
}
F_222 ( V_22 ) ;
}
static unsigned long F_229 ( const int V_276 )
{
return F_230 ( V_276 ) -> V_69 . V_11 ;
}
static unsigned long F_231 ( int V_276 , int type )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_277 = F_229 ( V_276 ) ;
if ( type == 0 || ! F_146 ( V_278 ) )
return V_277 ;
return F_13 ( V_22 -> V_279 [ type - 1 ] , V_277 ) ;
}
static unsigned long F_232 ( int V_276 , int type )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_277 = F_229 ( V_276 ) ;
if ( type == 0 || ! F_146 ( V_278 ) )
return V_277 ;
return F_63 ( V_22 -> V_279 [ type - 1 ] , V_277 ) ;
}
static unsigned long F_233 ( int V_276 )
{
return F_230 ( V_276 ) -> V_280 ;
}
static unsigned long F_234 ( int V_276 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_71 = F_78 ( V_22 -> V_71 ) ;
if ( V_71 )
return V_22 -> V_69 . V_11 / V_71 ;
return 0 ;
}
static void F_235 ( struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 V_39 ;
#ifndef F_40
T_2 V_47 ;
do {
V_47 = V_23 -> V_47 ;
F_236 () ;
V_39 = V_23 -> V_39 ;
} while ( V_39 != V_47 );
#else
V_39 = V_23 -> V_39 ;
#endif
V_26 -> V_40 -= V_39 ;
}
static long F_237 ( struct V_134 * V_31 , int V_276 , long V_281 , long V_282 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_276 ] ;
if ( ! V_31 -> V_32 )
return V_281 ;
F_33 (se) {
long V_17 , V_283 ;
V_31 = V_26 -> V_29 -> V_31 ;
V_283 = V_282 + F_106 ( V_31 , V_26 -> V_29 ) ;
V_17 = V_26 -> V_29 -> V_69 . V_11 + V_281 ;
if ( V_283 > 0 && V_17 < V_283 )
V_281 = ( V_17 * V_31 -> V_138 ) / V_283 ;
else
V_281 = V_31 -> V_138 ;
if ( V_281 < V_139 )
V_281 = V_139 ;
V_281 -= V_26 -> V_69 . V_11 ;
V_282 = 0 ;
}
return V_281 ;
}
static inline unsigned long F_237 ( struct V_134 * V_31 , int V_276 ,
unsigned long V_281 , unsigned long V_282 )
{
return V_281 ;
}
static int F_238 ( struct V_284 * V_285 , struct V_24 * V_27 , int V_286 )
{
T_3 V_287 , V_69 ;
int V_288 , V_289 , V_290 ;
unsigned long V_291 ;
struct V_134 * V_31 ;
unsigned long V_11 ;
int V_292 ;
V_288 = V_285 -> V_293 ;
V_289 = F_174 () ;
V_290 = F_239 ( V_27 ) ;
V_69 = F_231 ( V_290 , V_288 ) ;
V_287 = F_232 ( V_289 , V_288 ) ;
if ( V_286 ) {
V_31 = V_134 ( V_95 ) ;
V_11 = V_95 -> V_26 . V_69 . V_11 ;
V_287 += F_237 ( V_31 , V_289 , - V_11 , - V_11 ) ;
V_69 += F_237 ( V_31 , V_290 , 0 , - V_11 ) ;
}
V_31 = V_134 ( V_27 ) ;
V_11 = V_27 -> V_26 . V_69 . V_11 ;
if ( V_287 > 0 ) {
T_3 V_294 , V_295 ;
V_294 = 100 ;
V_294 *= F_233 ( V_290 ) ;
V_294 *= V_287 +
F_237 ( V_31 , V_289 , V_11 , V_11 ) ;
V_295 = 100 + ( V_285 -> V_296 - 100 ) / 2 ;
V_295 *= F_233 ( V_289 ) ;
V_295 *= V_69 + F_237 ( V_31 , V_290 , 0 , V_11 ) ;
V_292 = V_294 <= V_295 ;
} else
V_292 = true ;
if ( V_286 && V_292 )
return 1 ;
F_144 ( V_27 , V_26 . V_77 . V_297 ) ;
V_291 = F_234 ( V_289 ) ;
if ( V_292 ||
( V_287 <= V_69 &&
V_287 + F_232 ( V_290 , V_288 ) <= V_291 ) ) {
F_144 ( V_285 , V_298 ) ;
F_144 ( V_27 , V_26 . V_77 . V_299 ) ;
return 1 ;
}
return 0 ;
}
static struct V_300 *
F_240 ( struct V_284 * V_285 , struct V_24 * V_27 ,
int V_289 , int V_301 )
{
struct V_300 * V_302 = NULL , * V_303 = V_285 -> V_304 ;
unsigned long V_305 = V_306 , V_287 = 0 ;
int V_307 = 100 + ( V_285 -> V_296 - 100 ) / 2 ;
do {
unsigned long V_69 , V_308 ;
int V_309 ;
int V_310 ;
if ( ! F_241 ( F_242 ( V_303 ) ,
F_243 ( V_27 ) ) )
continue;
V_309 = F_244 ( V_289 ,
F_242 ( V_303 ) ) ;
V_308 = 0 ;
F_245 (i, sched_group_cpus(group)) {
if ( V_309 )
V_69 = F_231 ( V_310 , V_301 ) ;
else
V_69 = F_232 ( V_310 , V_301 ) ;
V_308 += V_69 ;
}
V_308 = ( V_308 * V_311 ) / V_303 -> V_312 -> V_313 ;
if ( V_309 ) {
V_287 = V_308 ;
} else if ( V_308 < V_305 ) {
V_305 = V_308 ;
V_302 = V_303 ;
}
} while ( V_303 = V_303 -> V_57 , V_303 != V_285 -> V_304 );
if ( ! V_302 || 100 * V_287 < V_307 * V_305 )
return NULL ;
return V_302 ;
}
static int
F_246 ( struct V_300 * V_303 , struct V_24 * V_27 , int V_289 )
{
unsigned long V_69 , V_305 = V_306 ;
int V_302 = - 1 ;
int V_310 ;
F_247 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_69 = F_229 ( V_310 ) ;
if ( V_69 < V_305 || ( V_69 == V_305 && V_310 == V_289 ) ) {
V_305 = V_69 ;
V_302 = V_310 ;
}
}
return V_302 ;
}
static int F_248 ( struct V_24 * V_27 , int V_314 )
{
int V_276 = F_174 () ;
int V_290 = F_239 ( V_27 ) ;
struct V_284 * V_285 ;
struct V_300 * V_315 ;
int V_310 ;
if ( V_314 == V_276 && F_249 ( V_276 ) )
return V_276 ;
if ( V_314 == V_290 && F_249 ( V_290 ) )
return V_290 ;
V_285 = F_250 ( F_251 ( V_316 , V_314 ) ) ;
F_252 (sd) {
V_315 = V_285 -> V_304 ;
do {
if ( ! F_241 ( F_242 ( V_315 ) ,
F_243 ( V_27 ) ) )
goto V_57;
F_245 (i, sched_group_cpus(sg)) {
if ( ! F_249 ( V_310 ) )
goto V_57;
}
V_314 = F_253 ( F_242 ( V_315 ) ,
F_243 ( V_27 ) ) ;
goto V_317;
V_57:
V_315 = V_315 -> V_57 ;
} while ( V_315 != V_285 -> V_304 );
}
V_317:
return V_314 ;
}
static int
F_254 ( struct V_24 * V_27 , int V_318 , int V_319 )
{
struct V_284 * V_14 , * V_320 = NULL , * V_285 = NULL ;
int V_276 = F_174 () ;
int V_290 = F_239 ( V_27 ) ;
int V_321 = V_276 ;
int V_322 = 0 ;
int V_286 = V_319 & V_323 ;
if ( V_27 -> V_324 == 1 )
return V_290 ;
if ( V_318 & V_325 ) {
if ( F_244 ( V_276 , F_243 ( V_27 ) ) )
V_322 = 1 ;
V_321 = V_290 ;
}
F_188 () ;
F_255 (cpu, tmp) {
if ( ! ( V_14 -> V_111 & V_326 ) )
continue;
if ( V_322 && ( V_14 -> V_111 & V_327 ) &&
F_244 ( V_290 , F_256 ( V_14 ) ) ) {
V_320 = V_14 ;
break;
}
if ( V_14 -> V_111 & V_318 )
V_285 = V_14 ;
}
if ( V_320 ) {
if ( V_276 != V_290 && F_238 ( V_320 , V_27 , V_286 ) )
V_290 = V_276 ;
V_321 = F_248 ( V_27 , V_290 ) ;
goto V_328;
}
while ( V_285 ) {
int V_301 = V_285 -> V_329 ;
struct V_300 * V_303 ;
int V_11 ;
if ( ! ( V_285 -> V_111 & V_318 ) ) {
V_285 = V_285 -> V_330 ;
continue;
}
if ( V_318 & V_325 )
V_301 = V_285 -> V_293 ;
V_303 = F_240 ( V_285 , V_27 , V_276 , V_301 ) ;
if ( ! V_303 ) {
V_285 = V_285 -> V_330 ;
continue;
}
V_321 = F_246 ( V_303 , V_27 , V_276 ) ;
if ( V_321 == - 1 || V_321 == V_276 ) {
V_285 = V_285 -> V_330 ;
continue;
}
V_276 = V_321 ;
V_11 = V_285 -> V_331 ;
V_285 = NULL ;
F_255 (cpu, tmp) {
if ( V_11 <= V_14 -> V_331 )
break;
if ( V_14 -> V_111 & V_318 )
V_285 = V_14 ;
}
}
V_328:
F_190 () ;
return V_321 ;
}
static void
F_257 ( struct V_24 * V_27 , int V_332 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_26 -> V_161 . V_162 ) {
V_26 -> V_161 . V_162 = - F_116 ( V_26 ) ;
F_119 ( V_26 -> V_161 . V_163 , & V_23 -> V_176 ) ;
}
}
static unsigned long
F_258 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
unsigned long V_333 = V_334 ;
return F_56 ( V_333 , V_26 ) ;
}
static int
F_159 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
T_3 V_333 , V_335 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_335 <= 0 )
return - 1 ;
V_333 = F_258 ( V_44 , V_26 ) ;
if ( V_335 > V_333 )
return 1 ;
return 0 ;
}
static void F_259 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_336 == V_337 ) )
return;
F_33 (se)
F_21 ( V_26 ) -> V_58 = V_26 ;
}
static void F_227 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_336 == V_337 ) )
return;
F_33 (se)
F_21 ( V_26 ) -> V_57 = V_26 ;
}
static void F_260 ( struct V_25 * V_26 )
{
F_33 (se)
F_21 ( V_26 ) -> V_198 = V_26 ;
}
static void F_261 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_319 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_25 * V_26 = & V_44 -> V_26 , * V_34 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
int V_338 = V_23 -> V_71 >= V_66 ;
int V_339 = 0 ;
if ( F_11 ( V_26 == V_34 ) )
return;
if ( F_11 ( F_112 ( F_21 ( V_34 ) ) ) )
return;
if ( F_146 ( V_340 ) && V_338 && ! ( V_319 & V_341 ) ) {
F_227 ( V_34 ) ;
V_339 = 1 ;
}
if ( F_262 ( V_44 ) )
return;
if ( F_11 ( V_44 -> V_336 == V_337 ) &&
F_9 ( V_27 -> V_336 != V_337 ) )
goto V_342;
if ( F_11 ( V_27 -> V_336 != V_343 ) || ! F_146 ( V_344 ) )
return;
F_34 ( & V_26 , & V_34 ) ;
F_65 ( F_21 ( V_26 ) ) ;
F_263 ( ! V_34 ) ;
if ( F_159 ( V_26 , V_34 ) == 1 ) {
if ( ! V_339 )
F_227 ( V_34 ) ;
goto V_342;
}
return;
V_342:
F_156 ( V_44 ) ;
if ( F_11 ( ! V_26 -> V_75 || V_44 == V_22 -> V_231 ) )
return;
if ( F_146 ( V_345 ) && V_338 && F_18 ( V_26 ) )
F_259 ( V_26 ) ;
}
static struct V_24 * F_264 ( struct V_22 * V_22 )
{
struct V_24 * V_27 ;
struct V_23 * V_23 = & V_22 -> V_38 ;
struct V_25 * V_26 ;
if ( ! V_23 -> V_71 )
return NULL ;
do {
V_26 = F_158 ( V_23 ) ;
F_157 ( V_23 , V_26 ) ;
V_23 = F_22 ( V_26 ) ;
} while ( V_23 );
V_27 = F_15 ( V_26 ) ;
if ( F_223 ( V_22 ) )
F_218 ( V_22 , V_27 ) ;
return V_27 ;
}
static void F_265 ( struct V_22 * V_22 , struct V_24 * V_207 )
{
struct V_25 * V_26 = & V_207 -> V_26 ;
struct V_23 * V_23 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_160 ( V_23 , V_26 ) ;
}
}
static void F_266 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
struct V_25 * V_26 = & V_44 -> V_26 ;
if ( F_11 ( V_22 -> V_71 == 1 ) )
return;
F_152 ( V_23 , V_26 ) ;
if ( V_44 -> V_336 != V_346 ) {
F_192 ( V_22 ) ;
F_65 ( V_23 ) ;
V_22 -> V_347 = 1 ;
}
F_260 ( V_26 ) ;
}
static bool F_267 ( struct V_22 * V_22 , struct V_24 * V_27 , bool V_342 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
if ( ! V_26 -> V_75 || F_112 ( F_21 ( V_26 ) ) )
return false ;
F_227 ( V_26 ) ;
F_266 ( V_22 ) ;
return true ;
}
static void F_268 ( struct V_24 * V_27 , struct V_348 * V_349 )
{
F_269 ( V_349 -> V_350 , V_27 , 0 ) ;
F_270 ( V_27 , V_349 -> V_351 ) ;
F_271 ( V_349 -> V_352 , V_27 , 0 ) ;
F_272 ( V_349 -> V_352 , V_27 , 0 ) ;
}
static int
F_273 ( struct V_24 * V_27 , T_2 V_81 , struct V_284 * V_285 )
{
T_3 V_41 ;
if ( V_27 -> V_273 != & V_274 )
return 0 ;
if ( F_11 ( V_27 -> V_336 == V_337 ) )
return 0 ;
if ( F_146 ( V_353 ) && F_274 () -> V_71 &&
( & V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_57 ||
& V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_58 ) )
return 1 ;
if ( V_354 == - 1 )
return 1 ;
if ( V_354 == 0 )
return 0 ;
V_41 = V_81 - V_27 -> V_26 . V_83 ;
return V_41 < ( T_3 ) V_354 ;
}
static
int F_275 ( struct V_24 * V_27 , struct V_348 * V_349 )
{
int V_355 = 0 ;
if ( ! F_244 ( V_349 -> V_351 , F_243 ( V_27 ) ) ) {
int V_356 ;
F_144 ( V_27 , V_26 . V_77 . V_357 ) ;
if ( ! V_349 -> V_358 || ( V_349 -> V_111 & V_359 ) )
return 0 ;
V_356 = F_253 ( V_349 -> V_358 ,
F_243 ( V_27 ) ) ;
if ( V_356 < V_360 ) {
V_349 -> V_111 |= V_359 ;
V_349 -> V_356 = V_356 ;
}
return 0 ;
}
V_349 -> V_111 &= ~ V_361 ;
if ( F_276 ( V_349 -> V_350 , V_27 ) ) {
F_144 ( V_27 , V_26 . V_77 . V_362 ) ;
return 0 ;
}
V_355 = F_273 ( V_27 , V_349 -> V_350 -> V_82 , V_349 -> V_285 ) ;
if ( ! V_355 ||
V_349 -> V_285 -> V_363 > V_349 -> V_285 -> V_364 ) {
#ifdef F_73
if ( V_355 ) {
F_144 ( V_349 -> V_285 , V_365 [ V_349 -> V_231 ] ) ;
F_144 ( V_27 , V_26 . V_77 . V_366 ) ;
}
#endif
return 1 ;
}
if ( V_355 ) {
F_144 ( V_27 , V_26 . V_77 . V_367 ) ;
return 0 ;
}
return 1 ;
}
static int F_277 ( struct V_348 * V_349 )
{
struct V_24 * V_27 , * V_141 ;
F_278 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( F_184 ( V_134 ( V_27 ) , V_349 -> V_350 -> V_276 , V_349 -> V_351 ) )
continue;
if ( ! F_275 ( V_27 , V_349 ) )
continue;
F_268 ( V_27 , V_349 ) ;
F_144 ( V_349 -> V_285 , V_368 [ V_349 -> V_231 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_279 ( struct V_348 * V_349 )
{
struct V_369 * V_370 = & V_349 -> V_350 -> V_133 ;
struct V_24 * V_27 ;
unsigned long V_69 ;
int V_371 = 0 ;
if ( V_349 -> V_307 <= 0 )
return 0 ;
while ( ! F_196 ( V_370 ) ) {
V_27 = F_280 ( V_370 , struct V_24 , V_26 . V_132 ) ;
V_349 -> V_372 ++ ;
if ( V_349 -> V_372 > V_349 -> V_373 )
break;
if ( V_349 -> V_372 > V_349 -> V_374 ) {
V_349 -> V_374 += V_375 ;
V_349 -> V_111 |= V_376 ;
break;
}
if ( F_184 ( V_134 ( V_27 ) , V_349 -> V_235 , V_349 -> V_351 ) )
goto V_57;
V_69 = F_281 ( V_27 ) ;
if ( F_146 ( V_377 ) && V_69 < 16 && ! V_349 -> V_285 -> V_363 )
goto V_57;
if ( ( V_69 / 2 ) > V_349 -> V_307 )
goto V_57;
if ( ! F_275 ( V_27 , V_349 ) )
goto V_57;
F_268 ( V_27 , V_349 ) ;
V_371 ++ ;
V_349 -> V_307 -= V_69 ;
#ifdef F_282
if ( V_349 -> V_231 == V_378 )
break;
#endif
if ( V_349 -> V_307 <= 0 )
break;
continue;
V_57:
F_283 ( & V_27 -> V_26 . V_132 , V_370 ) ;
}
F_64 ( V_349 -> V_285 , V_368 [ V_349 -> V_231 ] , V_371 ) ;
return V_371 ;
}
static void F_284 ( struct V_134 * V_31 , int V_276 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_276 ] ;
struct V_23 * V_23 = V_31 -> V_23 [ V_276 ] ;
if ( F_112 ( V_23 ) )
return;
F_27 ( V_23 , 1 ) ;
if ( V_26 ) {
F_130 ( V_26 , 1 ) ;
if ( ! V_26 -> V_161 . V_158 && ! V_23 -> V_71 )
F_28 ( V_23 ) ;
} else {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_133 ( V_22 , V_22 -> V_71 ) ;
}
}
static void F_285 ( int V_276 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
struct V_23 * V_23 ;
unsigned long V_111 ;
F_286 ( & V_22 -> V_229 , V_111 ) ;
F_192 ( V_22 ) ;
F_217 (rq, cfs_rq) {
F_284 ( V_23 -> V_31 , V_22 -> V_276 ) ;
}
F_287 ( & V_22 -> V_229 , V_111 ) ;
}
static int F_288 ( struct V_134 * V_31 , void * V_239 )
{
unsigned long V_69 ;
long V_276 = ( long ) V_239 ;
if ( ! V_31 -> V_32 ) {
V_69 = F_230 ( V_276 ) -> V_69 . V_11 ;
} else {
V_69 = V_31 -> V_32 -> V_23 [ V_276 ] -> V_379 ;
V_69 *= V_31 -> V_26 [ V_276 ] -> V_69 . V_11 ;
V_69 /= V_31 -> V_32 -> V_23 [ V_276 ] -> V_69 . V_11 + 1 ;
}
V_31 -> V_23 [ V_276 ] -> V_379 = V_69 ;
return 0 ;
}
static void F_289 ( long V_276 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_81 = V_104 ;
if ( V_22 -> V_380 == V_81 )
return;
V_22 -> V_380 = V_81 ;
F_188 () ;
F_290 ( F_288 , V_242 , ( void * ) V_276 ) ;
F_190 () ;
}
static unsigned long F_281 ( struct V_24 * V_27 )
{
struct V_23 * V_23 = F_20 ( V_27 ) ;
unsigned long V_69 ;
V_69 = V_27 -> V_26 . V_69 . V_11 ;
V_69 = F_121 ( V_69 * V_23 -> V_379 , V_23 -> V_69 . V_11 + 1 ) ;
return V_69 ;
}
static inline void F_285 ( int V_276 )
{
}
static inline void F_289 ( long V_276 )
{
}
static unsigned long F_281 ( struct V_24 * V_27 )
{
return V_27 -> V_26 . V_69 . V_11 ;
}
static inline int F_291 ( struct V_284 * V_285 ,
enum V_381 V_231 )
{
int V_301 ;
switch ( V_231 ) {
case V_382 :
V_301 = V_285 -> V_383 ;
break;
case V_378 :
V_301 = V_285 -> V_384 ;
break;
default:
V_301 = V_285 -> V_385 ;
break;
}
return V_301 ;
}
unsigned long F_292 ( struct V_284 * V_285 , int V_276 )
{
return V_311 ;
}
unsigned long __weak F_293 ( struct V_284 * V_285 , int V_276 )
{
return F_292 ( V_285 , V_276 ) ;
}
unsigned long F_294 ( struct V_284 * V_285 , int V_276 )
{
unsigned long V_11 = V_285 -> V_331 ;
unsigned long V_386 = V_285 -> V_386 ;
V_386 /= V_11 ;
return V_386 ;
}
unsigned long __weak F_295 ( struct V_284 * V_285 , int V_276 )
{
return F_294 ( V_285 , V_276 ) ;
}
unsigned long F_296 ( int V_276 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
T_2 V_277 , V_387 , V_388 , V_161 ;
V_388 = F_78 ( V_22 -> V_388 ) ;
V_161 = F_78 ( V_22 -> V_389 ) ;
V_277 = F_297 () + ( V_22 -> clock - V_388 ) ;
if ( F_11 ( V_277 < V_161 ) ) {
V_387 = 0 ;
} else {
V_387 = V_277 - V_161 ;
}
if ( F_11 ( ( T_3 ) V_277 < V_311 ) )
V_277 = V_311 ;
V_277 >>= V_390 ;
return F_121 ( V_387 , V_277 ) ;
}
static void F_298 ( struct V_284 * V_285 , int V_276 )
{
unsigned long V_11 = V_285 -> V_331 ;
unsigned long V_313 = V_311 ;
struct V_300 * V_391 = V_285 -> V_304 ;
if ( ( V_285 -> V_111 & V_392 ) && V_11 > 1 ) {
if ( F_146 ( V_393 ) )
V_313 *= F_295 ( V_285 , V_276 ) ;
else
V_313 *= F_294 ( V_285 , V_276 ) ;
V_313 >>= V_390 ;
}
V_391 -> V_312 -> V_394 = V_313 ;
if ( F_146 ( V_393 ) )
V_313 *= F_293 ( V_285 , V_276 ) ;
else
V_313 *= F_292 ( V_285 , V_276 ) ;
V_313 >>= V_390 ;
V_313 *= F_296 ( V_276 ) ;
V_313 >>= V_390 ;
if ( ! V_313 )
V_313 = 1 ;
F_230 ( V_276 ) -> V_280 = V_313 ;
V_391 -> V_312 -> V_313 = V_313 ;
}
void F_299 ( struct V_284 * V_285 , int V_276 )
{
struct V_284 * V_330 = V_285 -> V_330 ;
struct V_300 * V_303 , * V_391 = V_285 -> V_304 ;
unsigned long V_313 ;
unsigned long V_395 ;
V_395 = F_86 ( V_285 -> V_396 ) ;
V_395 = F_300 ( V_395 , 1UL , V_397 ) ;
V_391 -> V_312 -> V_398 = V_104 + V_395 ;
if ( ! V_330 ) {
F_298 ( V_285 , V_276 ) ;
return;
}
V_313 = 0 ;
if ( V_330 -> V_111 & V_399 ) {
F_245 (cpu, sched_group_cpus(sdg))
V_313 += F_233 ( V_276 ) ;
} else {
V_303 = V_330 -> V_304 ;
do {
V_313 += V_303 -> V_312 -> V_313 ;
V_303 = V_303 -> V_57 ;
} while ( V_303 != V_330 -> V_304 );
}
V_391 -> V_312 -> V_394 = V_391 -> V_312 -> V_313 = V_313 ;
}
static inline int
F_301 ( struct V_284 * V_285 , struct V_300 * V_303 )
{
if ( ! ( V_285 -> V_111 & V_392 ) )
return 0 ;
if ( V_303 -> V_312 -> V_313 * 32 > V_303 -> V_312 -> V_394 * 29 )
return 1 ;
return 0 ;
}
static inline void F_302 ( struct V_348 * V_349 ,
struct V_300 * V_303 , int V_301 ,
int V_309 , int * V_400 , struct V_401 * V_402 )
{
unsigned long V_71 , V_403 , V_404 ;
unsigned long V_69 , V_405 , V_406 ;
unsigned int V_407 = - 1 , V_408 = 0 ;
unsigned long V_409 = 0 ;
int V_310 ;
if ( V_309 )
V_407 = F_303 ( V_303 ) ;
V_405 = 0 ;
V_406 = ~ 0UL ;
V_403 = 0 ;
V_404 = ~ 0UL ;
F_247 (i, sched_group_cpus(group), env->cpus) {
struct V_22 * V_22 = F_230 ( V_310 ) ;
V_71 = V_22 -> V_71 ;
if ( V_309 ) {
if ( F_249 ( V_310 ) && ! V_408 &&
F_244 ( V_310 , F_304 ( V_303 ) ) ) {
V_408 = 1 ;
V_407 = V_310 ;
}
V_69 = F_232 ( V_310 , V_301 ) ;
} else {
V_69 = F_231 ( V_310 , V_301 ) ;
if ( V_69 > V_405 )
V_405 = V_69 ;
if ( V_406 > V_69 )
V_406 = V_69 ;
if ( V_71 > V_403 )
V_403 = V_71 ;
if ( V_404 > V_71 )
V_404 = V_71 ;
}
V_402 -> V_410 += V_69 ;
V_402 -> V_411 += V_71 ;
V_402 -> V_412 += F_229 ( V_310 ) ;
if ( F_249 ( V_310 ) )
V_402 -> V_413 ++ ;
}
if ( V_309 ) {
if ( V_349 -> V_231 != V_378 ) {
if ( V_407 != V_349 -> V_351 ) {
* V_400 = 0 ;
return;
}
F_299 ( V_349 -> V_285 , V_349 -> V_351 ) ;
} else if ( F_305 ( V_104 , V_303 -> V_312 -> V_398 ) )
F_299 ( V_349 -> V_285 , V_349 -> V_351 ) ;
}
V_402 -> V_308 = ( V_402 -> V_410 * V_311 ) / V_303 -> V_312 -> V_313 ;
if ( V_402 -> V_411 )
V_409 = V_402 -> V_412 / V_402 -> V_411 ;
if ( ( V_405 - V_406 ) >= V_409 &&
( V_403 - V_404 ) > 1 )
V_402 -> V_414 = 1 ;
V_402 -> V_415 = F_306 ( V_303 -> V_312 -> V_313 ,
V_311 ) ;
if ( ! V_402 -> V_415 )
V_402 -> V_415 = F_301 ( V_349 -> V_285 , V_303 ) ;
V_402 -> V_416 = V_303 -> V_416 ;
if ( V_402 -> V_415 > V_402 -> V_411 )
V_402 -> V_417 = 1 ;
}
static bool F_307 ( struct V_348 * V_349 ,
struct V_418 * V_419 ,
struct V_300 * V_315 ,
struct V_401 * V_402 )
{
if ( V_402 -> V_308 <= V_419 -> V_420 )
return false ;
if ( V_402 -> V_411 > V_402 -> V_415 )
return true ;
if ( V_402 -> V_414 )
return true ;
if ( ( V_349 -> V_285 -> V_111 & V_421 ) && V_402 -> V_411 &&
V_349 -> V_351 < F_308 ( V_315 ) ) {
if ( ! V_419 -> V_422 )
return true ;
if ( F_308 ( V_419 -> V_422 ) > F_308 ( V_315 ) )
return true ;
}
return false ;
}
static inline void F_309 ( struct V_348 * V_349 ,
int * V_400 , struct V_418 * V_419 )
{
struct V_284 * V_330 = V_349 -> V_285 -> V_330 ;
struct V_300 * V_315 = V_349 -> V_285 -> V_304 ;
struct V_401 V_402 ;
int V_301 , V_423 = 0 ;
if ( V_330 && V_330 -> V_111 & V_424 )
V_423 = 1 ;
V_301 = F_291 ( V_349 -> V_285 , V_349 -> V_231 ) ;
do {
int V_309 ;
V_309 = F_244 ( V_349 -> V_351 , F_242 ( V_315 ) ) ;
memset ( & V_402 , 0 , sizeof( V_402 ) ) ;
F_302 ( V_349 , V_315 , V_301 , V_309 , V_400 , & V_402 ) ;
if ( V_309 && ! ( * V_400 ) )
return;
V_419 -> V_425 += V_402 . V_410 ;
V_419 -> V_426 += V_315 -> V_312 -> V_313 ;
if ( V_423 && ! V_309 && V_419 -> V_427 )
V_402 . V_415 = F_13 ( V_402 . V_415 , 1UL ) ;
if ( V_309 ) {
V_419 -> V_287 = V_402 . V_308 ;
V_419 -> V_428 = V_315 ;
V_419 -> V_429 = V_402 . V_411 ;
V_419 -> V_430 = V_402 . V_412 ;
V_419 -> V_427 = V_402 . V_417 ;
V_419 -> V_431 = V_402 . V_413 ;
} else if ( F_307 ( V_349 , V_419 , V_315 , & V_402 ) ) {
V_419 -> V_420 = V_402 . V_308 ;
V_419 -> V_422 = V_315 ;
V_419 -> V_432 = V_402 . V_411 ;
V_419 -> V_433 = V_402 . V_413 ;
V_419 -> V_434 = V_402 . V_415 ;
V_419 -> V_435 = V_402 . V_412 ;
V_419 -> V_436 = V_402 . V_417 ;
V_419 -> V_437 = V_402 . V_416 ;
V_419 -> V_414 = V_402 . V_414 ;
}
V_315 = V_315 -> V_57 ;
} while ( V_315 != V_349 -> V_285 -> V_304 );
}
static int F_310 ( struct V_348 * V_349 , struct V_418 * V_419 )
{
int V_438 ;
if ( ! ( V_349 -> V_285 -> V_111 & V_421 ) )
return 0 ;
if ( ! V_419 -> V_422 )
return 0 ;
V_438 = F_308 ( V_419 -> V_422 ) ;
if ( V_349 -> V_351 > V_438 )
return 0 ;
V_349 -> V_307 = F_306 (
V_419 -> V_420 * V_419 -> V_422 -> V_312 -> V_313 , V_311 ) ;
return 1 ;
}
static inline
void F_311 ( struct V_348 * V_349 , struct V_418 * V_419 )
{
unsigned long V_14 , V_439 = 0 , V_440 = 0 ;
unsigned int V_441 = 2 ;
unsigned long V_442 ;
if ( V_419 -> V_429 ) {
V_419 -> V_430 /= V_419 -> V_429 ;
if ( V_419 -> V_435 >
V_419 -> V_430 )
V_441 = 1 ;
} else {
V_419 -> V_430 =
F_234 ( V_349 -> V_351 ) ;
}
V_442 = V_419 -> V_435
* V_311 ;
V_442 /= V_419 -> V_422 -> V_312 -> V_313 ;
if ( V_419 -> V_420 - V_419 -> V_287 + V_442 >=
( V_442 * V_441 ) ) {
V_349 -> V_307 = V_419 -> V_435 ;
return;
}
V_439 += V_419 -> V_422 -> V_312 -> V_313 *
F_13 ( V_419 -> V_435 , V_419 -> V_420 ) ;
V_439 += V_419 -> V_428 -> V_312 -> V_313 *
F_13 ( V_419 -> V_430 , V_419 -> V_287 ) ;
V_439 /= V_311 ;
V_14 = ( V_419 -> V_435 * V_311 ) /
V_419 -> V_422 -> V_312 -> V_313 ;
if ( V_419 -> V_420 > V_14 )
V_440 += V_419 -> V_422 -> V_312 -> V_313 *
F_13 ( V_419 -> V_435 , V_419 -> V_420 - V_14 ) ;
if ( V_419 -> V_420 * V_419 -> V_422 -> V_312 -> V_313 <
V_419 -> V_435 * V_311 )
V_14 = ( V_419 -> V_420 * V_419 -> V_422 -> V_312 -> V_313 ) /
V_419 -> V_428 -> V_312 -> V_313 ;
else
V_14 = ( V_419 -> V_435 * V_311 ) /
V_419 -> V_428 -> V_312 -> V_313 ;
V_440 += V_419 -> V_428 -> V_312 -> V_313 *
F_13 ( V_419 -> V_430 , V_419 -> V_287 + V_14 ) ;
V_440 /= V_311 ;
if ( V_440 > V_439 )
V_349 -> V_307 = V_419 -> V_435 ;
}
static inline void F_312 ( struct V_348 * V_349 , struct V_418 * V_419 )
{
unsigned long V_443 , V_444 = ~ 0UL ;
V_419 -> V_435 /= V_419 -> V_432 ;
if ( V_419 -> V_414 ) {
V_419 -> V_435 =
F_13 ( V_419 -> V_435 , V_419 -> V_308 ) ;
}
if ( V_419 -> V_420 < V_419 -> V_308 ) {
V_349 -> V_307 = 0 ;
return F_311 ( V_349 , V_419 ) ;
}
if ( ! V_419 -> V_414 ) {
V_444 = ( V_419 -> V_432 -
V_419 -> V_434 ) ;
V_444 *= ( V_445 * V_311 ) ;
V_444 /= V_419 -> V_422 -> V_312 -> V_313 ;
}
V_443 = F_13 ( V_419 -> V_420 - V_419 -> V_308 , V_444 ) ;
V_349 -> V_307 = F_13 ( V_443 * V_419 -> V_422 -> V_312 -> V_313 ,
( V_419 -> V_308 - V_419 -> V_287 ) * V_419 -> V_428 -> V_312 -> V_313 )
/ V_311 ;
if ( V_349 -> V_307 < V_419 -> V_435 )
return F_311 ( V_349 , V_419 ) ;
}
static struct V_300 *
F_313 ( struct V_348 * V_349 , int * V_400 )
{
struct V_418 V_419 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
F_309 ( V_349 , V_400 , & V_419 ) ;
if ( ! ( * V_400 ) )
goto V_65;
if ( ( V_349 -> V_231 == V_446 || V_349 -> V_231 == V_378 ) &&
F_310 ( V_349 , & V_419 ) )
return V_419 . V_422 ;
if ( ! V_419 . V_422 || V_419 . V_432 == 0 )
goto V_447;
V_419 . V_308 = ( V_311 * V_419 . V_425 ) / V_419 . V_426 ;
if ( V_419 . V_414 )
goto V_448;
if ( V_349 -> V_231 == V_378 && V_419 . V_427 &&
! V_419 . V_436 )
goto V_448;
if ( V_419 . V_287 >= V_419 . V_420 )
goto V_447;
if ( V_419 . V_287 >= V_419 . V_308 )
goto V_447;
if ( V_349 -> V_231 == V_446 ) {
if ( ( V_419 . V_431 <= V_419 . V_433 + 1 ) &&
V_419 . V_432 <= V_419 . V_437 )
goto V_447;
} else {
if ( 100 * V_419 . V_420 <= V_349 -> V_285 -> V_296 * V_419 . V_287 )
goto V_447;
}
V_448:
F_312 ( V_349 , & V_419 ) ;
return V_419 . V_422 ;
V_447:
V_65:
V_349 -> V_307 = 0 ;
return NULL ;
}
static struct V_22 * F_314 ( struct V_348 * V_349 ,
struct V_300 * V_303 )
{
struct V_22 * V_422 = NULL , * V_22 ;
unsigned long V_420 = 0 ;
int V_310 ;
F_245 (i, sched_group_cpus(group)) {
unsigned long V_313 = F_233 ( V_310 ) ;
unsigned long V_449 = F_306 ( V_313 ,
V_311 ) ;
unsigned long V_281 ;
if ( ! V_449 )
V_449 = F_301 ( V_349 -> V_285 , V_303 ) ;
if ( ! F_244 ( V_310 , V_349 -> V_1 ) )
continue;
V_22 = F_230 ( V_310 ) ;
V_281 = F_229 ( V_310 ) ;
if ( V_449 && V_22 -> V_71 == 1 && V_281 > V_349 -> V_307 )
continue;
V_281 = ( V_281 * V_311 ) / V_313 ;
if ( V_281 > V_420 ) {
V_420 = V_281 ;
V_422 = V_22 ;
}
}
return V_422 ;
}
static int F_315 ( struct V_348 * V_349 )
{
struct V_284 * V_285 = V_349 -> V_285 ;
if ( V_349 -> V_231 == V_378 ) {
if ( ( V_285 -> V_111 & V_421 ) && V_349 -> V_235 > V_349 -> V_351 )
return 1 ;
}
return F_11 ( V_285 -> V_363 > V_285 -> V_364 + 2 ) ;
}
static int F_316 ( int V_289 , struct V_22 * F_274 ,
struct V_284 * V_285 , enum V_381 V_231 ,
int * V_400 )
{
int V_450 , V_451 , V_452 = 0 ;
int V_453 , V_454 ;
struct V_300 * V_303 ;
struct V_22 * V_422 ;
unsigned long V_111 ;
struct V_455 * V_1 = F_317 ( V_456 ) ;
struct V_348 V_349 = {
. V_285 = V_285 ,
. V_351 = V_289 ,
. V_352 = F_274 ,
. V_358 = F_242 ( V_285 -> V_304 ) ,
. V_231 = V_231 ,
. V_374 = V_375 ,
. V_1 = V_1 ,
} ;
F_318 ( V_1 , V_457 ) ;
V_454 = F_319 ( V_349 . V_358 ) ;
F_144 ( V_285 , V_458 [ V_231 ] ) ;
V_459:
V_303 = F_313 ( & V_349 , V_400 ) ;
if ( * V_400 == 0 )
goto V_447;
if ( ! V_303 ) {
F_144 ( V_285 , V_460 [ V_231 ] ) ;
goto V_447;
}
V_422 = F_314 ( & V_349 , V_303 ) ;
if ( ! V_422 ) {
F_144 ( V_285 , V_461 [ V_231 ] ) ;
goto V_447;
}
F_263 ( V_422 == V_349 . V_352 ) ;
F_64 ( V_285 , V_462 [ V_231 ] , V_349 . V_307 ) ;
V_450 = 0 ;
V_453 = 1 ;
if ( V_422 -> V_71 > 1 ) {
V_349 . V_111 |= V_361 ;
V_349 . V_235 = V_422 -> V_276 ;
V_349 . V_350 = V_422 ;
V_349 . V_373 = F_13 ( V_463 , V_422 -> V_71 ) ;
F_289 ( V_349 . V_235 ) ;
V_464:
F_320 ( V_111 ) ;
F_321 ( V_349 . V_352 , V_422 ) ;
V_451 = F_279 ( & V_349 ) ;
V_450 += V_451 ;
F_322 ( V_349 . V_352 , V_422 ) ;
F_323 ( V_111 ) ;
if ( V_349 . V_111 & V_376 ) {
V_349 . V_111 &= ~ V_376 ;
goto V_464;
}
if ( V_451 && V_349 . V_351 != F_174 () )
F_324 ( V_349 . V_351 ) ;
if ( ( V_349 . V_111 & V_359 ) && V_349 . V_307 > 0 &&
V_453 ++ < V_454 ) {
V_349 . V_352 = F_230 ( V_349 . V_356 ) ;
V_349 . V_351 = V_349 . V_356 ;
V_349 . V_111 &= ~ V_359 ;
V_349 . V_372 = 0 ;
V_349 . V_374 = V_375 ;
goto V_464;
}
if ( F_11 ( V_349 . V_111 & V_361 ) ) {
F_325 ( F_24 ( V_422 ) , V_1 ) ;
if ( ! F_326 ( V_1 ) ) {
V_349 . V_372 = 0 ;
V_349 . V_374 = V_375 ;
goto V_459;
}
goto V_447;
}
}
if ( ! V_450 ) {
F_144 ( V_285 , V_465 [ V_231 ] ) ;
if ( V_231 != V_378 )
V_285 -> V_363 ++ ;
if ( F_315 ( & V_349 ) ) {
F_286 ( & V_422 -> V_229 , V_111 ) ;
if ( ! F_244 ( V_289 ,
F_243 ( V_422 -> V_44 ) ) ) {
F_287 ( & V_422 -> V_229 ,
V_111 ) ;
V_349 . V_111 |= V_361 ;
goto V_466;
}
if ( ! V_422 -> V_452 ) {
V_422 -> V_452 = 1 ;
V_422 -> V_467 = V_289 ;
V_452 = 1 ;
}
F_287 ( & V_422 -> V_229 , V_111 ) ;
if ( V_452 ) {
F_327 ( F_24 ( V_422 ) ,
V_468 , V_422 ,
& V_422 -> V_469 ) ;
}
V_285 -> V_363 = V_285 -> V_364 + 1 ;
}
} else
V_285 -> V_363 = 0 ;
if ( F_9 ( ! V_452 ) ) {
V_285 -> V_396 = V_285 -> V_470 ;
} else {
if ( V_285 -> V_396 < V_285 -> V_471 )
V_285 -> V_396 *= 2 ;
}
goto V_129;
V_447:
F_144 ( V_285 , V_472 [ V_231 ] ) ;
V_285 -> V_363 = 0 ;
V_466:
if ( ( ( V_349 . V_111 & V_361 ) &&
V_285 -> V_396 < V_473 ) ||
( V_285 -> V_396 < V_285 -> V_471 ) )
V_285 -> V_396 *= 2 ;
V_450 = 0 ;
V_129:
return V_450 ;
}
void F_328 ( int V_289 , struct V_22 * F_274 )
{
struct V_284 * V_285 ;
int V_474 = 0 ;
unsigned long V_475 = V_104 + V_476 ;
F_274 -> V_477 = F_274 -> clock ;
if ( F_274 -> V_478 < V_354 )
return;
F_133 ( F_274 , 1 ) ;
F_180 ( & F_274 -> V_229 ) ;
F_285 ( V_289 ) ;
F_188 () ;
F_255 (this_cpu, sd) {
unsigned long V_395 ;
int V_400 = 1 ;
if ( ! ( V_285 -> V_111 & V_326 ) )
continue;
if ( V_285 -> V_111 & V_479 ) {
V_474 = F_316 ( V_289 , F_274 ,
V_285 , V_378 , & V_400 ) ;
}
V_395 = F_86 ( V_285 -> V_396 ) ;
if ( F_85 ( V_475 , V_285 -> V_480 + V_395 ) )
V_475 = V_285 -> V_480 + V_395 ;
if ( V_474 ) {
F_274 -> V_477 = 0 ;
break;
}
}
F_190 () ;
F_178 ( & F_274 -> V_229 ) ;
if ( V_474 || F_85 ( V_104 , F_274 -> V_475 ) ) {
F_274 -> V_475 = V_475 ;
}
}
static int V_468 ( void * V_239 )
{
struct V_22 * V_481 = V_239 ;
int V_438 = F_24 ( V_481 ) ;
int V_482 = V_481 -> V_467 ;
struct V_22 * V_483 = F_230 ( V_482 ) ;
struct V_284 * V_285 ;
F_329 ( & V_481 -> V_229 ) ;
if ( F_11 ( V_438 != F_174 () ||
! V_481 -> V_452 ) )
goto V_252;
if ( V_481 -> V_71 <= 1 )
goto V_252;
F_263 ( V_481 == V_483 ) ;
F_330 ( V_481 , V_483 ) ;
F_188 () ;
F_255 (target_cpu, sd) {
if ( ( V_285 -> V_111 & V_326 ) &&
F_244 ( V_438 , F_256 ( V_285 ) ) )
break;
}
if ( F_9 ( V_285 ) ) {
struct V_348 V_349 = {
. V_285 = V_285 ,
. V_351 = V_482 ,
. V_352 = V_483 ,
. V_235 = V_481 -> V_276 ,
. V_350 = V_481 ,
. V_231 = V_446 ,
} ;
F_144 ( V_285 , V_484 ) ;
if ( F_277 ( & V_349 ) )
F_144 ( V_285 , V_485 ) ;
else
F_144 ( V_285 , V_486 ) ;
}
F_190 () ;
F_331 ( V_481 , V_483 ) ;
V_252:
V_481 -> V_452 = 0 ;
F_332 ( & V_481 -> V_229 ) ;
return 0 ;
}
static inline int F_333 ( int V_487 )
{
int V_488 = F_334 ( V_489 . V_490 ) ;
if ( V_488 < V_360 && F_249 ( V_488 ) )
return V_488 ;
return V_360 ;
}
static void F_335 ( int V_276 )
{
int V_491 ;
V_489 . V_475 ++ ;
V_491 = F_333 ( V_276 ) ;
if ( V_491 >= V_360 )
return;
if ( F_336 ( V_492 , F_337 ( V_491 ) ) )
return;
F_338 ( V_491 ) ;
return;
}
static inline void F_339 ( int V_276 )
{
if ( F_11 ( F_340 ( V_493 , F_337 ( V_276 ) ) ) ) {
F_325 ( V_276 , V_489 . V_490 ) ;
F_341 ( & V_489 . V_494 ) ;
F_342 ( V_493 , F_337 ( V_276 ) ) ;
}
}
static inline void F_343 ( void )
{
struct V_284 * V_285 ;
int V_276 = F_174 () ;
if ( ! F_340 ( V_495 , F_337 ( V_276 ) ) )
return;
F_342 ( V_495 , F_337 ( V_276 ) ) ;
F_188 () ;
F_255 (cpu, sd)
F_344 ( & V_285 -> V_304 -> V_312 -> V_496 ) ;
F_190 () ;
}
void F_345 ( void )
{
struct V_284 * V_285 ;
int V_276 = F_174 () ;
if ( F_340 ( V_495 , F_337 ( V_276 ) ) )
return;
F_346 ( V_495 , F_337 ( V_276 ) ) ;
F_188 () ;
F_255 (cpu, sd)
F_341 ( & V_285 -> V_304 -> V_312 -> V_496 ) ;
F_190 () ;
}
void F_347 ( int V_276 )
{
if ( ! F_348 ( V_276 ) )
return;
if ( F_340 ( V_493 , F_337 ( V_276 ) ) )
return;
F_349 ( V_276 , V_489 . V_490 ) ;
F_344 ( & V_489 . V_494 ) ;
F_346 ( V_493 , F_337 ( V_276 ) ) ;
}
static int T_11 F_350 ( struct V_497 * V_498 ,
unsigned long V_499 , void * V_500 )
{
switch ( V_499 & ~ V_501 ) {
case V_502 :
F_339 ( F_174 () ) ;
return V_503 ;
default:
return V_504 ;
}
}
void F_351 ( void )
{
V_397 = V_476 * F_3 () / 10 ;
}
static void F_352 ( int V_276 , enum V_381 V_231 )
{
int V_400 = 1 ;
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_395 ;
struct V_284 * V_285 ;
unsigned long V_475 = V_104 + 60 * V_476 ;
int V_505 = 0 ;
int V_506 ;
F_285 ( V_276 ) ;
F_188 () ;
F_255 (cpu, sd) {
if ( ! ( V_285 -> V_111 & V_326 ) )
continue;
V_395 = V_285 -> V_396 ;
if ( V_231 != V_446 )
V_395 *= V_285 -> V_507 ;
V_395 = F_86 ( V_395 ) ;
V_395 = F_300 ( V_395 , 1UL , V_397 ) ;
V_506 = V_285 -> V_111 & V_508 ;
if ( V_506 ) {
if ( ! F_353 ( & V_509 ) )
goto V_129;
}
if ( F_305 ( V_104 , V_285 -> V_480 + V_395 ) ) {
if ( F_316 ( V_276 , V_22 , V_285 , V_231 , & V_400 ) ) {
V_231 = V_382 ;
}
V_285 -> V_480 = V_104 ;
}
if ( V_506 )
F_354 ( & V_509 ) ;
V_129:
if ( F_85 ( V_475 , V_285 -> V_480 + V_395 ) ) {
V_475 = V_285 -> V_480 + V_395 ;
V_505 = 1 ;
}
if ( ! V_400 )
break;
}
F_190 () ;
if ( F_9 ( V_505 ) )
V_22 -> V_475 = V_475 ;
}
static void F_355 ( int V_289 , enum V_381 V_231 )
{
struct V_22 * F_274 = F_230 ( V_289 ) ;
struct V_22 * V_22 ;
int V_407 ;
if ( V_231 != V_446 ||
! F_340 ( V_492 , F_337 ( V_289 ) ) )
goto V_109;
F_245 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_407 == V_289 || ! F_249 ( V_407 ) )
continue;
if ( F_356 () )
break;
V_22 = F_230 ( V_407 ) ;
F_329 ( & V_22 -> V_229 ) ;
F_192 ( V_22 ) ;
F_357 ( V_22 ) ;
F_332 ( & V_22 -> V_229 ) ;
F_352 ( V_407 , V_446 ) ;
if ( F_85 ( F_274 -> V_475 , V_22 -> V_475 ) )
F_274 -> V_475 = V_22 -> V_475 ;
}
V_489 . V_475 = F_274 -> V_475 ;
V_109:
F_342 ( V_492 , F_337 ( V_289 ) ) ;
}
static inline int F_358 ( struct V_22 * V_22 , int V_276 )
{
unsigned long V_81 = V_104 ;
struct V_284 * V_285 ;
if ( F_11 ( F_249 ( V_276 ) ) )
return 0 ;
F_343 () ;
F_339 ( V_276 ) ;
if ( F_9 ( ! F_125 ( & V_489 . V_494 ) ) )
return 0 ;
if ( F_88 ( V_81 , V_489 . V_475 ) )
return 0 ;
if ( V_22 -> V_71 >= 2 )
goto V_510;
F_188 () ;
F_255 (cpu, sd) {
struct V_300 * V_315 = V_285 -> V_304 ;
struct V_511 * V_312 = V_315 -> V_312 ;
int V_512 = F_125 ( & V_312 -> V_496 ) ;
if ( V_285 -> V_111 & V_513 && V_512 > 1 )
goto V_514;
if ( V_285 -> V_111 & V_421 && V_512 != V_315 -> V_416
&& ( F_253 ( V_489 . V_490 ,
F_256 ( V_285 ) ) < V_276 ) )
goto V_514;
if ( ! ( V_285 -> V_111 & ( V_513 | V_421 ) ) )
break;
}
F_190 () ;
return 0 ;
V_514:
F_190 () ;
V_510:
return 1 ;
}
static void F_355 ( int V_289 , enum V_381 V_231 ) { }
static void F_359 ( struct V_515 * V_516 )
{
int V_289 = F_174 () ;
struct V_22 * F_274 = F_230 ( V_289 ) ;
enum V_381 V_231 = F_274 -> F_328 ?
V_446 : V_382 ;
F_352 ( V_289 , V_231 ) ;
F_355 ( V_289 , V_231 ) ;
}
static inline int F_360 ( int V_276 )
{
return ! F_361 ( F_230 ( V_276 ) -> V_285 ) ;
}
void F_362 ( struct V_22 * V_22 , int V_276 )
{
if ( F_305 ( V_104 , V_22 -> V_475 ) &&
F_9 ( ! F_360 ( V_276 ) ) )
F_363 ( V_517 ) ;
#ifdef F_364
if ( F_358 ( V_22 , V_276 ) && F_9 ( ! F_360 ( V_276 ) ) )
F_335 ( V_276 ) ;
#endif
}
static void F_365 ( struct V_22 * V_22 )
{
F_5 () ;
}
static void F_366 ( struct V_22 * V_22 )
{
F_5 () ;
F_216 ( V_22 ) ;
}
static void F_367 ( struct V_22 * V_22 , struct V_24 * V_44 , int V_208 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_44 -> V_26 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_162 ( V_23 , V_26 , V_208 ) ;
}
if ( F_80 ( V_96 ) )
F_97 ( V_22 , V_44 ) ;
F_133 ( V_22 , 1 ) ;
}
static void F_368 ( struct V_24 * V_27 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 , * V_44 ;
int V_289 = F_174 () ;
struct V_22 * V_22 = F_274 () ;
unsigned long V_111 ;
F_286 ( & V_22 -> V_229 , V_111 ) ;
F_192 ( V_22 ) ;
V_23 = F_20 ( V_95 ) ;
V_44 = V_23 -> V_44 ;
if ( F_11 ( F_239 ( V_27 ) != V_289 ) ) {
F_188 () ;
F_369 ( V_27 , V_289 ) ;
F_190 () ;
}
F_65 ( V_23 ) ;
if ( V_44 )
V_26 -> V_40 = V_44 -> V_40 ;
F_145 ( V_23 , V_26 , 1 ) ;
if ( V_518 && V_44 && F_37 ( V_44 , V_26 ) ) {
F_370 ( V_44 -> V_40 , V_26 -> V_40 ) ;
F_156 ( V_22 -> V_44 ) ;
}
V_26 -> V_40 -= V_23 -> V_39 ;
F_287 ( & V_22 -> V_229 , V_111 ) ;
}
static void
F_371 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_519 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 ) {
if ( V_27 -> V_520 > V_519 )
F_156 ( V_22 -> V_44 ) ;
} else
F_272 ( V_22 , V_27 , 0 ) ;
}
static void F_372 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 && V_27 -> V_200 != V_521 ) {
F_145 ( V_23 , V_26 , 0 ) ;
V_26 -> V_40 -= V_23 -> V_39 ;
}
#if F_373 ( V_522 ) && F_373 ( F_101 )
if ( V_27 -> V_26 . V_161 . V_162 ) {
struct V_23 * V_23 = F_21 ( & V_27 -> V_26 ) ;
F_116 ( & V_27 -> V_26 ) ;
F_129 ( V_23 ,
V_27 -> V_26 . V_161 . V_163 ) ;
}
#endif
}
static void F_374 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 )
F_156 ( V_22 -> V_44 ) ;
else
F_272 ( V_22 , V_27 , 0 ) ;
}
static void F_375 ( struct V_22 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_44 -> V_26 ;
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_157 ( V_23 , V_26 ) ;
F_69 ( V_23 , 0 ) ;
}
}
void F_376 ( struct V_23 * V_23 )
{
V_23 -> V_50 = V_523 ;
V_23 -> V_39 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_40
V_23 -> V_47 = V_23 -> V_39 ;
#endif
#if F_373 ( V_522 ) && F_373 ( F_101 )
F_377 ( & V_23 -> V_160 , 1 ) ;
F_377 ( & V_23 -> V_176 , 0 ) ;
#endif
}
static void F_378 ( struct V_24 * V_27 , int V_75 )
{
struct V_23 * V_23 ;
if ( ! V_75 && ( ! V_27 -> V_26 . V_79 || V_27 -> V_200 == V_524 ) )
V_75 = 1 ;
if ( ! V_75 )
V_27 -> V_26 . V_40 -= F_21 ( & V_27 -> V_26 ) -> V_39 ;
F_379 ( V_27 , F_239 ( V_27 ) ) ;
if ( ! V_75 ) {
V_23 = F_21 ( & V_27 -> V_26 ) ;
V_27 -> V_26 . V_40 += V_23 -> V_39 ;
#ifdef F_101
V_27 -> V_26 . V_161 . V_162 = F_107 ( & V_23 -> V_160 ) ;
V_23 -> V_167 += V_27 -> V_26 . V_161 . V_163 ;
#endif
}
}
void F_380 ( struct V_134 * V_31 )
{
int V_310 ;
F_215 ( F_176 ( V_31 ) ) ;
F_381 (i) {
if ( V_31 -> V_23 )
F_382 ( V_31 -> V_23 [ V_310 ] ) ;
if ( V_31 -> V_26 )
F_382 ( V_31 -> V_26 [ V_310 ] ) ;
}
F_382 ( V_31 -> V_23 ) ;
F_382 ( V_31 -> V_26 ) ;
}
int F_383 ( struct V_134 * V_31 , struct V_134 * V_32 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 ;
int V_310 ;
V_31 -> V_23 = F_384 ( sizeof( V_23 ) * V_360 , V_525 ) ;
if ( ! V_31 -> V_23 )
goto V_526;
V_31 -> V_26 = F_384 ( sizeof( V_26 ) * V_360 , V_525 ) ;
if ( ! V_31 -> V_26 )
goto V_526;
V_31 -> V_138 = V_70 ;
F_209 ( F_176 ( V_31 ) ) ;
F_381 (i) {
V_23 = F_385 ( sizeof( struct V_23 ) ,
V_525 , F_386 ( V_310 ) ) ;
if ( ! V_23 )
goto V_526;
V_26 = F_385 ( sizeof( struct V_25 ) ,
V_525 , F_386 ( V_310 ) ) ;
if ( ! V_26 )
goto V_527;
F_376 ( V_23 ) ;
F_387 ( V_31 , V_23 , V_26 , V_310 , V_32 -> V_26 [ V_310 ] ) ;
}
return 1 ;
V_527:
F_382 ( V_23 ) ;
V_526:
return 0 ;
}
void F_388 ( struct V_134 * V_31 , int V_276 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
unsigned long V_111 ;
if ( ! V_31 -> V_23 [ V_276 ] -> V_30 )
return;
F_286 ( & V_22 -> V_229 , V_111 ) ;
F_28 ( V_31 -> V_23 [ V_276 ] ) ;
F_287 ( & V_22 -> V_229 , V_111 ) ;
}
void F_387 ( struct V_134 * V_31 , struct V_23 * V_23 ,
struct V_25 * V_26 , int V_276 ,
struct V_25 * V_32 )
{
struct V_22 * V_22 = F_230 ( V_276 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_22 = V_22 ;
F_213 ( V_23 ) ;
V_31 -> V_23 [ V_276 ] = V_23 ;
V_31 -> V_26 [ V_276 ] = V_26 ;
if ( ! V_26 )
return;
if ( ! V_32 )
V_26 -> V_23 = & V_22 -> V_38 ;
else
V_26 -> V_23 = V_32 -> V_29 ;
V_26 -> V_29 = V_23 ;
F_110 ( & V_26 -> V_69 , 0 ) ;
V_26 -> V_32 = V_32 ;
}
int F_389 ( struct V_134 * V_31 , unsigned long V_138 )
{
int V_310 ;
unsigned long V_111 ;
if ( ! V_31 -> V_26 [ 0 ] )
return - V_528 ;
V_138 = F_300 ( V_138 , F_127 ( V_139 ) , F_127 ( V_529 ) ) ;
F_390 ( & V_530 ) ;
if ( V_31 -> V_138 == V_138 )
goto V_317;
V_31 -> V_138 = V_138 ;
F_381 (i) {
struct V_22 * V_22 = F_230 ( V_310 ) ;
struct V_25 * V_26 ;
V_26 = V_31 -> V_26 [ V_310 ] ;
F_286 ( & V_22 -> V_229 , V_111 ) ;
F_33 (se)
F_111 ( F_22 ( V_26 ) ) ;
F_287 ( & V_22 -> V_229 , V_111 ) ;
}
V_317:
F_391 ( & V_530 ) ;
return 0 ;
}
void F_380 ( struct V_134 * V_31 ) { }
int F_383 ( struct V_134 * V_31 , struct V_134 * V_32 )
{
return 1 ;
}
void F_388 ( struct V_134 * V_31 , int V_276 ) { }
static unsigned int F_392 ( struct V_22 * V_22 , struct V_24 * V_531 )
{
struct V_25 * V_26 = & V_531 -> V_26 ;
unsigned int V_532 = 0 ;
if ( V_22 -> V_38 . V_69 . V_11 )
V_532 = F_393 ( F_58 ( & V_22 -> V_38 , V_26 ) ) ;
return V_532 ;
}
void F_394 ( struct V_533 * V_534 , int V_276 )
{
struct V_23 * V_23 ;
F_188 () ;
F_217 (cpu_rq(cpu), cfs_rq)
F_395 ( V_534 , V_276 , V_23 ) ;
F_190 () ;
}
T_12 void F_396 ( void )
{
#ifdef F_101
F_397 ( V_517 , F_359 ) ;
#ifdef F_364
V_489 . V_475 = V_104 ;
F_398 ( & V_489 . V_490 , V_535 ) ;
F_399 ( F_350 , 0 ) ;
#endif
#endif
}
