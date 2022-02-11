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
static inline T_2 F_36 ( T_2 F_36 , T_2 V_39 )
{
T_3 V_40 = ( T_3 ) ( V_39 - F_36 ) ;
if ( V_40 > 0 )
F_36 = V_39 ;
return F_36 ;
}
static inline T_2 F_37 ( T_2 F_37 , T_2 V_39 )
{
T_3 V_40 = ( T_3 ) ( V_39 - F_37 ) ;
if ( V_40 < 0 )
F_37 = V_39 ;
return F_37 ;
}
static inline int F_38 ( struct V_25 * V_41 ,
struct V_25 * V_42 )
{
return ( T_3 ) ( V_41 -> V_39 - V_42 -> V_39 ) < 0 ;
}
static void F_39 ( struct V_23 * V_23 )
{
T_2 V_39 = V_23 -> F_37 ;
if ( V_23 -> V_43 )
V_39 = V_23 -> V_43 -> V_39 ;
if ( V_23 -> V_44 ) {
struct V_25 * V_26 = F_40 ( V_23 -> V_44 ,
struct V_25 ,
V_45 ) ;
if ( ! V_23 -> V_43 )
V_39 = V_26 -> V_39 ;
else
V_39 = F_37 ( V_39 , V_26 -> V_39 ) ;
}
V_23 -> F_37 = F_36 ( V_23 -> F_37 , V_39 ) ;
#ifndef F_41
F_42 () ;
V_23 -> V_46 = V_23 -> F_37 ;
#endif
}
static void F_43 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
struct V_47 * * V_48 = & V_23 -> V_49 . V_47 ;
struct V_47 * V_32 = NULL ;
struct V_25 * V_50 ;
int V_51 = 1 ;
while ( * V_48 ) {
V_32 = * V_48 ;
V_50 = F_40 ( V_32 , struct V_25 , V_45 ) ;
if ( F_38 ( V_26 , V_50 ) ) {
V_48 = & V_32 -> V_52 ;
} else {
V_48 = & V_32 -> V_53 ;
V_51 = 0 ;
}
}
if ( V_51 )
V_23 -> V_44 = & V_26 -> V_45 ;
F_44 ( & V_26 -> V_45 , V_32 , V_48 ) ;
F_45 ( & V_26 -> V_45 , & V_23 -> V_49 ) ;
}
static void F_46 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_44 == & V_26 -> V_45 ) {
struct V_47 * V_54 ;
V_54 = F_47 ( & V_26 -> V_45 ) ;
V_23 -> V_44 = V_54 ;
}
F_48 ( & V_26 -> V_45 , & V_23 -> V_49 ) ;
}
struct V_25 * F_49 ( struct V_23 * V_23 )
{
struct V_47 * V_55 = V_23 -> V_44 ;
if ( ! V_55 )
return NULL ;
return F_40 ( V_55 , struct V_25 , V_45 ) ;
}
static struct V_25 * F_50 ( struct V_25 * V_26 )
{
struct V_47 * V_56 = F_47 ( & V_26 -> V_45 ) ;
if ( ! V_56 )
return NULL ;
return F_40 ( V_56 , struct V_25 , V_45 ) ;
}
struct V_25 * F_51 ( struct V_23 * V_23 )
{
struct V_47 * V_57 = F_52 ( & V_23 -> V_49 ) ;
if ( ! V_57 )
return NULL ;
return F_40 ( V_57 , struct V_25 , V_45 ) ;
}
int F_53 ( struct V_58 * V_59 , int V_60 ,
void T_4 * V_61 , T_5 * V_62 ,
T_6 * V_63 )
{
int V_64 = F_54 ( V_59 , V_60 , V_61 , V_62 , V_63 ) ;
int V_2 = F_1 () ;
if ( V_64 || ! V_60 )
return V_64 ;
V_65 = F_55 ( V_66 ,
V_67 ) ;
#define F_56 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_56 ( V_7 ) ;
F_56 ( V_8 ) ;
F_56 ( V_9 ) ;
#undef F_56
return 0 ;
}
static inline unsigned long
F_57 ( unsigned long V_40 , struct V_25 * V_26 )
{
if ( F_11 ( V_26 -> V_68 . V_11 != V_69 ) )
V_40 = F_8 ( V_40 , V_69 , & V_26 -> V_68 ) ;
return V_40 ;
}
static T_2 F_58 ( unsigned long V_70 )
{
T_2 V_71 = V_66 ;
unsigned long V_72 = V_65 ;
if ( F_11 ( V_70 > V_72 ) ) {
V_71 = V_67 ;
V_71 *= V_70 ;
}
return V_71 ;
}
static T_2 F_59 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
T_2 V_73 = F_58 ( V_23 -> V_70 + ! V_26 -> V_74 ) ;
F_33 (se) {
struct V_12 * V_68 ;
struct V_12 V_13 ;
V_23 = F_21 ( V_26 ) ;
V_68 = & V_23 -> V_68 ;
if ( F_11 ( ! V_26 -> V_74 ) ) {
V_13 = V_23 -> V_68 ;
F_60 ( & V_13 , V_26 -> V_68 . V_11 ) ;
V_68 = & V_13 ;
}
V_73 = F_8 ( V_73 , V_26 -> V_68 . V_11 , V_68 ) ;
}
return V_73 ;
}
static T_2 F_61 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
return F_57 ( F_59 ( V_23 , V_26 ) , V_26 ) ;
}
static inline void
F_62 ( struct V_23 * V_23 , struct V_25 * V_43 ,
unsigned long V_10 )
{
unsigned long V_75 ;
F_63 ( V_43 -> V_76 . V_77 ,
F_64 ( ( T_2 ) V_10 , V_43 -> V_76 . V_77 ) ) ;
V_43 -> V_78 += V_10 ;
F_65 ( V_23 , V_79 , V_10 ) ;
V_75 = F_57 ( V_10 , V_43 ) ;
V_43 -> V_39 += V_75 ;
F_39 ( V_23 ) ;
}
static void F_66 ( struct V_23 * V_23 )
{
struct V_25 * V_43 = V_23 -> V_43 ;
T_2 V_80 = F_14 ( V_23 ) -> V_81 ;
unsigned long V_10 ;
if ( F_11 ( ! V_43 ) )
return;
V_10 = ( unsigned long ) ( V_80 - V_43 -> V_82 ) ;
if ( ! V_10 )
return;
F_62 ( V_23 , V_43 , V_10 ) ;
V_43 -> V_82 = V_80 ;
if ( F_18 ( V_43 ) ) {
struct V_24 * V_83 = F_15 ( V_43 ) ;
F_67 ( V_83 , V_10 , V_43 -> V_39 ) ;
F_68 ( V_83 , V_10 ) ;
F_69 ( V_83 , V_10 ) ;
}
F_70 ( V_23 , V_10 ) ;
}
static inline void
F_71 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_63 ( V_26 -> V_76 . V_84 , F_14 ( V_23 ) -> clock ) ;
}
static void F_72 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_43 )
F_71 ( V_23 , V_26 ) ;
}
static void
F_73 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_63 ( V_26 -> V_76 . V_85 , F_64 ( V_26 -> V_76 . V_85 ,
F_14 ( V_23 ) -> clock - V_26 -> V_76 . V_84 ) ) ;
F_63 ( V_26 -> V_76 . V_86 , V_26 -> V_76 . V_86 + 1 ) ;
F_63 ( V_26 -> V_76 . V_87 , V_26 -> V_76 . V_87 +
F_14 ( V_23 ) -> clock - V_26 -> V_76 . V_84 ) ;
#ifdef F_74
if ( F_18 ( V_26 ) ) {
F_75 ( F_15 ( V_26 ) ,
F_14 ( V_23 ) -> clock - V_26 -> V_76 . V_84 ) ;
}
#endif
F_63 ( V_26 -> V_76 . V_84 , 0 ) ;
}
static inline void
F_76 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_43 )
F_73 ( V_23 , V_26 ) ;
}
static inline void
F_77 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
V_26 -> V_82 = F_14 ( V_23 ) -> V_81 ;
}
static void F_78 ( struct V_24 * V_27 )
{
int V_88 ;
if ( ! V_27 -> V_89 )
return;
V_88 = F_79 ( V_27 -> V_89 -> V_90 ) ;
if ( V_27 -> V_90 == V_88 )
return;
V_27 -> V_90 = V_88 ;
}
void F_80 ( int V_91 , int V_92 , bool V_93 )
{
struct V_24 * V_27 = V_94 ;
if ( ! F_81 ( V_95 ) )
return;
if ( ! V_93 )
V_27 -> V_96 = F_13 ( V_97 ,
V_27 -> V_96 + F_82 ( 10 ) ) ;
F_78 ( V_27 ) ;
}
static void F_83 ( struct V_24 * V_27 )
{
F_79 ( V_27 -> V_89 -> V_90 ) ++ ;
V_27 -> V_89 -> V_98 = 0 ;
}
void F_84 ( struct V_99 * V_100 )
{
unsigned long V_101 , V_102 , V_80 = V_103 ;
struct V_24 * V_27 = V_94 ;
struct V_104 * V_89 = V_27 -> V_89 ;
struct V_105 * V_106 ;
unsigned long V_107 , V_108 ;
long V_92 ;
F_17 ( V_27 != F_19 ( V_100 , struct V_24 , V_109 ) ) ;
V_100 -> V_56 = V_100 ;
if ( V_27 -> V_110 & V_111 )
return;
if ( V_89 -> V_112 == V_113 )
V_89 -> V_112 = F_85 () ;
if ( V_89 -> V_112 != V_114 ) {
if ( F_85 () == V_89 -> V_112 &&
! F_81 ( V_115 ) )
return;
V_89 -> V_112 = V_114 ;
}
V_101 = V_89 -> V_116 ;
if ( F_86 ( V_80 , V_101 ) ) {
V_27 -> V_96 = V_117 ;
V_102 = V_80 + F_87 ( V_118 ) ;
F_88 ( & V_89 -> V_116 , V_102 ) ;
}
V_101 = V_89 -> V_119 ;
if ( F_89 ( V_80 , V_101 ) )
return;
if ( V_27 -> V_96 == 0 )
V_27 -> V_96 = V_117 ;
V_102 = V_80 + F_87 ( V_27 -> V_96 ) ;
if ( F_90 ( & V_89 -> V_119 , V_101 , V_102 ) != V_101 )
return;
if ( F_91 ( F_85 () ) )
return;
V_107 = V_89 -> V_98 ;
V_92 = V_120 ;
V_92 <<= 20 - V_121 ;
if ( ! V_92 )
return;
F_92 ( & V_89 -> V_122 ) ;
V_106 = F_93 ( V_89 , V_107 ) ;
if ( ! V_106 ) {
F_83 ( V_27 ) ;
V_107 = 0 ;
V_106 = V_89 -> V_123 ;
}
for (; V_106 ; V_106 = V_106 -> V_124 ) {
if ( ! F_94 ( V_106 ) )
continue;
if ( V_106 -> V_125 - V_106 -> V_126 < V_127 )
continue;
do {
V_107 = F_64 ( V_107 , V_106 -> V_126 ) ;
V_108 = F_95 ( V_107 + ( V_92 << V_121 ) , V_127 ) ;
V_108 = F_13 ( V_108 , V_106 -> V_125 ) ;
V_92 -= F_96 ( V_106 , V_107 , V_108 ) ;
V_107 = V_108 ;
if ( V_92 <= 0 )
goto V_128;
} while ( V_108 != V_106 -> V_125 );
}
V_128:
if ( V_106 )
V_89 -> V_98 = V_107 ;
else
F_83 ( V_27 ) ;
F_97 ( & V_89 -> V_122 ) ;
}
void F_98 ( struct V_22 * V_22 , struct V_24 * V_43 )
{
struct V_99 * V_100 = & V_43 -> V_109 ;
T_2 V_71 , V_80 ;
if ( ! V_43 -> V_89 || ( V_43 -> V_110 & V_111 ) || V_100 -> V_56 != V_100 )
return;
V_80 = V_43 -> V_26 . V_78 ;
V_71 = ( T_2 ) V_43 -> V_96 * V_129 ;
if ( V_80 - V_43 -> V_130 > V_71 ) {
if ( ! V_43 -> V_130 )
V_43 -> V_96 = V_117 ;
V_43 -> V_130 = V_80 ;
if ( ! F_89 ( V_103 , V_43 -> V_89 -> V_119 ) ) {
F_99 ( V_100 , F_84 ) ;
F_100 ( V_43 , V_100 , true ) ;
}
}
}
static void F_98 ( struct V_22 * V_22 , struct V_24 * V_43 )
{
}
static void
F_101 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_60 ( & V_23 -> V_68 , V_26 -> V_68 . V_11 ) ;
if ( ! F_31 ( V_26 ) )
F_60 ( & F_14 ( V_23 ) -> V_68 , V_26 -> V_68 . V_11 ) ;
#ifdef F_102
if ( F_18 ( V_26 ) )
F_103 ( & V_26 -> V_131 , & F_14 ( V_23 ) -> V_132 ) ;
#endif
V_23 -> V_70 ++ ;
}
static void
F_104 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_105 ( & V_23 -> V_68 , V_26 -> V_68 . V_11 ) ;
if ( ! F_31 ( V_26 ) )
F_105 ( & F_14 ( V_23 ) -> V_68 , V_26 -> V_68 . V_11 ) ;
if ( F_18 ( V_26 ) )
F_106 ( & V_26 -> V_131 ) ;
V_23 -> V_70 -- ;
}
static inline long F_107 ( struct V_133 * V_31 , struct V_23 * V_23 )
{
long V_134 ;
V_134 = F_108 ( & V_31 -> V_135 ) ;
V_134 -= V_23 -> V_136 ;
V_134 += V_23 -> V_68 . V_11 ;
return V_134 ;
}
static long F_109 ( struct V_23 * V_23 , struct V_133 * V_31 )
{
long V_134 , V_68 , V_137 ;
V_134 = F_107 ( V_31 , V_23 ) ;
V_68 = V_23 -> V_68 . V_11 ;
V_137 = ( V_31 -> V_137 * V_68 ) ;
if ( V_134 )
V_137 /= V_134 ;
if ( V_137 < V_138 )
V_137 = V_138 ;
if ( V_137 > V_31 -> V_137 )
V_137 = V_31 -> V_137 ;
return V_137 ;
}
static inline long F_109 ( struct V_23 * V_23 , struct V_133 * V_31 )
{
return V_31 -> V_137 ;
}
static void F_110 ( struct V_23 * V_23 , struct V_25 * V_26 ,
unsigned long V_11 )
{
if ( V_26 -> V_74 ) {
if ( V_23 -> V_43 == V_26 )
F_66 ( V_23 ) ;
F_104 ( V_23 , V_26 ) ;
}
F_111 ( & V_26 -> V_68 , V_11 ) ;
if ( V_26 -> V_74 )
F_101 ( V_23 , V_26 ) ;
}
static void F_112 ( struct V_23 * V_23 )
{
struct V_133 * V_31 ;
struct V_25 * V_26 ;
long V_137 ;
V_31 = V_23 -> V_31 ;
V_26 = V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
if ( ! V_26 || F_113 ( V_23 ) )
return;
#ifndef F_102
if ( F_9 ( V_26 -> V_68 . V_11 == V_31 -> V_137 ) )
return;
#endif
V_137 = F_109 ( V_23 , V_31 ) ;
F_110 ( F_21 ( V_26 ) , V_26 , V_137 ) ;
}
static inline void F_112 ( struct V_23 * V_23 )
{
}
static T_7 T_2 F_114 ( T_2 V_139 , T_2 V_140 )
{
unsigned int V_141 ;
if ( ! V_140 )
return V_139 ;
else if ( F_11 ( V_140 > V_142 * 63 ) )
return 0 ;
V_141 = V_140 ;
if ( F_11 ( V_141 >= V_142 ) ) {
V_139 >>= V_141 / V_142 ;
V_141 %= V_142 ;
}
V_139 *= V_143 [ V_141 ] ;
return V_139 >> 32 ;
}
static T_8 F_115 ( T_2 V_140 )
{
T_8 V_144 = 0 ;
if ( F_9 ( V_140 <= V_142 ) )
return V_145 [ V_140 ] ;
else if ( F_11 ( V_140 >= V_146 ) )
return V_147 ;
do {
V_144 /= 2 ;
V_144 += V_145 [ V_142 ] ;
V_140 -= V_142 ;
} while ( V_140 > V_142 );
V_144 = F_114 ( V_144 , V_140 ) ;
return V_144 + V_145 [ V_140 ] ;
}
static T_7 int F_116 ( T_2 V_80 ,
struct V_148 * V_149 ,
int V_150 )
{
T_2 V_40 , V_151 ;
T_8 V_152 ;
int V_153 , V_154 = 0 ;
V_40 = V_80 - V_149 -> V_155 ;
if ( ( T_3 ) V_40 < 0 ) {
V_149 -> V_155 = V_80 ;
return 0 ;
}
V_40 >>= 10 ;
if ( ! V_40 )
return 0 ;
V_149 -> V_155 = V_80 ;
V_153 = V_149 -> V_156 % 1024 ;
if ( V_40 + V_153 >= 1024 ) {
V_154 = 1 ;
V_153 = 1024 - V_153 ;
if ( V_150 )
V_149 -> V_157 += V_153 ;
V_149 -> V_156 += V_153 ;
V_40 -= V_153 ;
V_151 = V_40 / 1024 ;
V_40 %= 1024 ;
V_149 -> V_157 = F_114 ( V_149 -> V_157 ,
V_151 + 1 ) ;
V_149 -> V_156 = F_114 ( V_149 -> V_156 ,
V_151 + 1 ) ;
V_152 = F_115 ( V_151 ) ;
if ( V_150 )
V_149 -> V_157 += V_152 ;
V_149 -> V_156 += V_152 ;
}
if ( V_150 )
V_149 -> V_157 += V_40 ;
V_149 -> V_156 += V_40 ;
return V_154 ;
}
static inline T_2 F_117 ( struct V_25 * V_26 )
{
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 V_158 = F_108 ( & V_23 -> V_159 ) ;
V_158 -= V_26 -> V_160 . V_161 ;
if ( ! V_158 )
return 0 ;
V_26 -> V_160 . V_162 = F_114 ( V_26 -> V_160 . V_162 , V_158 ) ;
V_26 -> V_160 . V_161 = 0 ;
return V_158 ;
}
static inline void F_118 ( struct V_23 * V_23 ,
int V_163 )
{
struct V_133 * V_31 = V_23 -> V_31 ;
T_3 V_164 ;
V_164 = V_23 -> V_165 + V_23 -> V_166 ;
V_164 -= V_23 -> V_136 ;
if ( V_163 || F_119 ( V_164 ) > V_23 -> V_136 / 8 ) {
F_120 ( V_164 , & V_31 -> V_135 ) ;
V_23 -> V_136 += V_164 ;
}
}
static inline void F_121 ( struct V_148 * V_149 ,
struct V_23 * V_23 )
{
struct V_133 * V_31 = V_23 -> V_31 ;
long V_144 ;
V_144 = F_122 ( V_149 -> V_157 << V_167 ,
V_149 -> V_156 + 1 ) ;
V_144 -= V_23 -> V_168 ;
if ( abs ( V_144 ) > V_23 -> V_168 / 64 ) {
F_123 ( V_144 , & V_31 -> V_169 ) ;
V_23 -> V_168 += V_144 ;
}
}
static inline void F_124 ( struct V_25 * V_26 )
{
struct V_23 * V_23 = F_22 ( V_26 ) ;
struct V_133 * V_31 = V_23 -> V_31 ;
int V_169 ;
T_2 V_144 ;
V_144 = V_23 -> V_136 * V_31 -> V_137 ;
V_26 -> V_160 . V_162 = F_125 ( V_144 ,
F_108 ( & V_31 -> V_135 ) + 1 ) ;
V_169 = F_126 ( & V_31 -> V_169 ) ;
if ( V_169 < V_69 ) {
V_26 -> V_160 . V_162 *= V_169 ;
V_26 -> V_160 . V_162 >>= V_167 ;
}
}
static inline void F_118 ( struct V_23 * V_23 ,
int V_163 ) {}
static inline void F_121 ( struct V_148 * V_149 ,
struct V_23 * V_23 ) {}
static inline void F_124 ( struct V_25 * V_26 ) {}
static inline void F_127 ( struct V_25 * V_26 )
{
T_8 V_144 ;
V_144 = V_26 -> V_160 . V_157 * F_10 ( V_26 -> V_68 . V_11 ) ;
V_144 /= ( V_26 -> V_160 . V_156 + 1 ) ;
V_26 -> V_160 . V_162 = F_128 ( V_144 ) ;
}
static long F_129 ( struct V_25 * V_26 )
{
long V_170 = V_26 -> V_160 . V_162 ;
if ( F_18 ( V_26 ) ) {
F_127 ( V_26 ) ;
} else {
F_121 ( & V_26 -> V_160 , F_22 ( V_26 ) ) ;
F_124 ( V_26 ) ;
}
return V_26 -> V_160 . V_162 - V_170 ;
}
static inline void F_130 ( struct V_23 * V_23 ,
long V_171 )
{
if ( F_9 ( V_171 < V_23 -> V_166 ) )
V_23 -> V_166 -= V_171 ;
else
V_23 -> V_166 = 0 ;
}
static inline void F_131 ( struct V_25 * V_26 ,
int V_172 )
{
struct V_23 * V_23 = F_21 ( V_26 ) ;
long V_173 ;
T_2 V_80 ;
if ( F_18 ( V_26 ) )
V_80 = F_132 ( V_23 ) ;
else
V_80 = F_132 ( F_22 ( V_26 ) ) ;
if ( ! F_116 ( V_80 , & V_26 -> V_160 , V_26 -> V_74 ) )
return;
V_173 = F_129 ( V_26 ) ;
if ( ! V_172 )
return;
if ( V_26 -> V_74 )
V_23 -> V_165 += V_173 ;
else
F_130 ( V_23 , - V_173 ) ;
}
static void F_27 ( struct V_23 * V_23 , int V_163 )
{
T_2 V_80 = F_132 ( V_23 ) >> 20 ;
T_2 V_158 ;
V_158 = V_80 - V_23 -> V_174 ;
if ( ! V_158 && ! V_163 )
return;
if ( F_108 ( & V_23 -> V_175 ) ) {
T_2 V_175 = F_133 ( & V_23 -> V_175 , 0 ) ;
F_130 ( V_23 , V_175 ) ;
}
if ( V_158 ) {
V_23 -> V_166 = F_114 ( V_23 -> V_166 ,
V_158 ) ;
F_120 ( V_158 , & V_23 -> V_159 ) ;
V_23 -> V_174 = V_80 ;
}
F_118 ( V_23 , V_163 ) ;
}
static inline void F_134 ( struct V_22 * V_22 , int V_150 )
{
F_116 ( V_22 -> V_81 , & V_22 -> V_160 , V_150 ) ;
F_121 ( & V_22 -> V_160 , & V_22 -> V_38 ) ;
}
static inline void F_135 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_176 )
{
if ( F_11 ( V_26 -> V_160 . V_161 <= 0 ) ) {
V_26 -> V_160 . V_155 = F_14 ( V_23 ) -> V_81 ;
if ( V_26 -> V_160 . V_161 ) {
V_26 -> V_160 . V_155 -= ( - V_26 -> V_160 . V_161 )
<< 20 ;
F_131 ( V_26 , 0 ) ;
V_26 -> V_160 . V_161 = 0 ;
}
V_176 = 0 ;
} else {
F_117 ( V_26 ) ;
}
if ( V_176 ) {
F_130 ( V_23 , V_26 -> V_160 . V_162 ) ;
F_131 ( V_26 , 0 ) ;
}
V_23 -> V_165 += V_26 -> V_160 . V_162 ;
F_27 ( V_23 , ! V_176 ) ;
}
static inline void F_136 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_177 )
{
F_131 ( V_26 , 1 ) ;
F_27 ( V_23 , ! V_177 ) ;
V_23 -> V_165 -= V_26 -> V_160 . V_162 ;
if ( V_177 ) {
V_23 -> V_166 += V_26 -> V_160 . V_162 ;
V_26 -> V_160 . V_161 = F_108 ( & V_23 -> V_159 ) ;
}
}
void F_137 ( struct V_22 * V_178 )
{
F_134 ( V_178 , 1 ) ;
}
void F_138 ( struct V_22 * V_178 )
{
F_134 ( V_178 , 0 ) ;
}
static inline void F_131 ( struct V_25 * V_26 ,
int V_172 ) {}
static inline void F_134 ( struct V_22 * V_22 , int V_150 ) {}
static inline void F_135 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_176 ) {}
static inline void F_136 ( struct V_23 * V_23 ,
struct V_25 * V_26 ,
int V_177 ) {}
static inline void F_27 ( struct V_23 * V_23 ,
int V_163 ) {}
static void F_139 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_74
struct V_24 * V_179 = NULL ;
if ( F_18 ( V_26 ) )
V_179 = F_15 ( V_26 ) ;
if ( V_26 -> V_76 . V_180 ) {
T_2 V_40 = F_14 ( V_23 ) -> clock - V_26 -> V_76 . V_180 ;
if ( ( T_3 ) V_40 < 0 )
V_40 = 0 ;
if ( F_11 ( V_40 > V_26 -> V_76 . V_181 ) )
V_26 -> V_76 . V_181 = V_40 ;
V_26 -> V_76 . V_180 = 0 ;
V_26 -> V_76 . V_182 += V_40 ;
if ( V_179 ) {
F_140 ( V_179 , V_40 >> 10 , 1 ) ;
F_141 ( V_179 , V_40 ) ;
}
}
if ( V_26 -> V_76 . V_183 ) {
T_2 V_40 = F_14 ( V_23 ) -> clock - V_26 -> V_76 . V_183 ;
if ( ( T_3 ) V_40 < 0 )
V_40 = 0 ;
if ( F_11 ( V_40 > V_26 -> V_76 . V_184 ) )
V_26 -> V_76 . V_184 = V_40 ;
V_26 -> V_76 . V_183 = 0 ;
V_26 -> V_76 . V_182 += V_40 ;
if ( V_179 ) {
if ( V_179 -> V_185 ) {
V_26 -> V_76 . V_186 += V_40 ;
V_26 -> V_76 . V_187 ++ ;
F_142 ( V_179 , V_40 ) ;
}
F_143 ( V_179 , V_40 ) ;
if ( F_11 ( V_188 == V_189 ) ) {
F_144 ( V_189 ,
( void * ) F_145 ( V_179 ) ,
V_40 >> 20 ) ;
}
F_140 ( V_179 , V_40 >> 10 , 0 ) ;
}
}
#endif
}
static void F_146 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_16
T_3 V_190 = V_26 -> V_39 - V_23 -> F_37 ;
if ( V_190 < 0 )
V_190 = - V_190 ;
if ( V_190 > 3 * V_66 )
F_147 ( V_23 , V_191 ) ;
#endif
}
static void
F_148 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_192 )
{
T_2 V_39 = V_23 -> F_37 ;
if ( V_192 && F_149 ( V_193 ) )
V_39 += F_61 ( V_23 , V_26 ) ;
if ( ! V_192 ) {
unsigned long V_194 = V_66 ;
if ( F_149 ( V_195 ) )
V_194 >>= 1 ;
V_39 -= V_194 ;
}
V_26 -> V_39 = F_36 ( V_26 -> V_39 , V_39 ) ;
}
static void
F_150 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_110 )
{
if ( ! ( V_110 & V_196 ) || ( V_110 & V_197 ) )
V_26 -> V_39 += V_23 -> F_37 ;
F_66 ( V_23 ) ;
F_135 ( V_23 , V_26 , V_110 & V_196 ) ;
F_101 ( V_23 , V_26 ) ;
F_112 ( V_23 ) ;
if ( V_110 & V_196 ) {
F_148 ( V_23 , V_26 , 0 ) ;
F_139 ( V_23 , V_26 ) ;
}
F_72 ( V_23 , V_26 ) ;
F_146 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_43 )
F_43 ( V_23 , V_26 ) ;
V_26 -> V_74 = 1 ;
if ( V_23 -> V_70 == 1 ) {
F_23 ( V_23 ) ;
F_151 ( V_23 ) ;
}
}
static void F_152 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
V_23 -> V_57 = NULL ;
else
break;
}
}
static void F_153 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_56 == V_26 )
V_23 -> V_56 = NULL ;
else
break;
}
}
static void F_154 ( struct V_25 * V_26 )
{
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_198 == V_26 )
V_23 -> V_198 = NULL ;
else
break;
}
}
static void F_155 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_57 == V_26 )
F_152 ( V_26 ) ;
if ( V_23 -> V_56 == V_26 )
F_153 ( V_26 ) ;
if ( V_23 -> V_198 == V_26 )
F_154 ( V_26 ) ;
}
static void
F_156 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_110 )
{
F_66 ( V_23 ) ;
F_136 ( V_23 , V_26 , V_110 & V_199 ) ;
F_76 ( V_23 , V_26 ) ;
if ( V_110 & V_199 ) {
#ifdef F_74
if ( F_18 ( V_26 ) ) {
struct V_24 * V_179 = F_15 ( V_26 ) ;
if ( V_179 -> V_200 & V_201 )
V_26 -> V_76 . V_180 = F_14 ( V_23 ) -> clock ;
if ( V_179 -> V_200 & V_202 )
V_26 -> V_76 . V_183 = F_14 ( V_23 ) -> clock ;
}
#endif
}
F_155 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_43 )
F_46 ( V_23 , V_26 ) ;
V_26 -> V_74 = 0 ;
F_104 ( V_23 , V_26 ) ;
if ( ! ( V_110 & V_199 ) )
V_26 -> V_39 -= V_23 -> F_37 ;
F_157 ( V_23 ) ;
F_39 ( V_23 ) ;
F_112 ( V_23 ) ;
}
static void
F_158 ( struct V_23 * V_23 , struct V_25 * V_43 )
{
unsigned long V_203 , V_10 ;
struct V_25 * V_26 ;
T_3 V_40 ;
V_203 = F_59 ( V_23 , V_43 ) ;
V_10 = V_43 -> V_78 - V_43 -> V_204 ;
if ( V_10 > V_203 ) {
F_159 ( F_14 ( V_23 ) -> V_43 ) ;
F_155 ( V_23 , V_43 ) ;
return;
}
if ( V_10 < V_67 )
return;
V_26 = F_49 ( V_23 ) ;
V_40 = V_43 -> V_39 - V_26 -> V_39 ;
if ( V_40 < 0 )
return;
if ( V_40 > V_203 )
F_159 ( F_14 ( V_23 ) -> V_43 ) ;
}
static void
F_160 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 -> V_74 ) {
F_73 ( V_23 , V_26 ) ;
F_46 ( V_23 , V_26 ) ;
}
F_77 ( V_23 , V_26 ) ;
V_23 -> V_43 = V_26 ;
#ifdef F_74
if ( F_14 ( V_23 ) -> V_68 . V_11 >= 2 * V_26 -> V_68 . V_11 ) {
V_26 -> V_76 . V_205 = F_64 ( V_26 -> V_76 . V_205 ,
V_26 -> V_78 - V_26 -> V_204 ) ;
}
#endif
V_26 -> V_204 = V_26 -> V_78 ;
}
static struct V_25 * F_161 ( struct V_23 * V_23 )
{
struct V_25 * V_26 = F_49 ( V_23 ) ;
struct V_25 * V_55 = V_26 ;
if ( V_23 -> V_198 == V_26 ) {
struct V_25 * V_206 = F_50 ( V_26 ) ;
if ( V_206 && F_162 ( V_206 , V_55 ) < 1 )
V_26 = V_206 ;
}
if ( V_23 -> V_57 && F_162 ( V_23 -> V_57 , V_55 ) < 1 )
V_26 = V_23 -> V_57 ;
if ( V_23 -> V_56 && F_162 ( V_23 -> V_56 , V_55 ) < 1 )
V_26 = V_23 -> V_56 ;
F_155 ( V_23 , V_26 ) ;
return V_26 ;
}
static void F_163 ( struct V_23 * V_23 , struct V_25 * V_207 )
{
if ( V_207 -> V_74 )
F_66 ( V_23 ) ;
F_164 ( V_23 ) ;
F_146 ( V_23 , V_207 ) ;
if ( V_207 -> V_74 ) {
F_71 ( V_23 , V_207 ) ;
F_43 ( V_23 , V_207 ) ;
F_131 ( V_207 , 1 ) ;
}
V_23 -> V_43 = NULL ;
}
static void
F_165 ( struct V_23 * V_23 , struct V_25 * V_43 , int V_208 )
{
F_66 ( V_23 ) ;
F_131 ( V_43 , 1 ) ;
F_27 ( V_23 , 1 ) ;
#ifdef F_166
if ( V_208 ) {
F_159 ( F_14 ( V_23 ) -> V_43 ) ;
return;
}
if ( ! F_149 ( V_209 ) &&
F_167 ( & F_14 ( V_23 ) -> V_210 ) )
return;
#endif
if ( V_23 -> V_70 > 1 )
F_158 ( V_23 , V_43 ) ;
}
static inline bool F_168 ( void )
{
return F_169 ( & V_211 ) ;
}
void F_170 ( int V_212 , int V_213 )
{
if ( V_212 && ! V_213 )
F_171 ( & V_211 ) ;
else if ( ! V_212 && V_213 )
F_172 ( & V_211 ) ;
}
static bool F_168 ( void )
{
return true ;
}
void F_170 ( int V_212 , int V_213 ) {}
static inline T_2 F_173 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_174 ( void )
{
return ( T_2 ) V_214 * V_215 ;
}
void F_175 ( struct V_216 * V_217 )
{
T_2 V_80 ;
if ( V_217 -> V_218 == V_219 )
return;
V_80 = F_176 ( F_177 () ) ;
V_217 -> V_220 = V_217 -> V_218 ;
V_217 -> V_221 = V_80 + F_178 ( V_217 -> V_71 ) ;
}
static inline struct V_216 * F_179 ( struct V_133 * V_31 )
{
return & V_31 -> V_216 ;
}
static inline T_2 F_132 ( struct V_23 * V_23 )
{
if ( F_11 ( V_23 -> V_222 ) )
return V_23 -> V_223 ;
return F_14 ( V_23 ) -> V_81 - V_23 -> V_224 ;
}
static int F_180 ( struct V_23 * V_23 )
{
struct V_133 * V_31 = V_23 -> V_31 ;
struct V_216 * V_217 = F_179 ( V_31 ) ;
T_2 V_225 = 0 , V_226 , V_227 ;
V_226 = F_174 () - V_23 -> V_228 ;
F_181 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 == V_219 )
V_225 = V_226 ;
else {
if ( ! V_217 -> V_230 ) {
F_175 ( V_217 ) ;
F_182 ( V_217 ) ;
}
if ( V_217 -> V_220 > 0 ) {
V_225 = F_13 ( V_217 -> V_220 , V_226 ) ;
V_217 -> V_220 -= V_225 ;
V_217 -> V_231 = 0 ;
}
}
V_227 = V_217 -> V_221 ;
F_183 ( & V_217 -> V_229 ) ;
V_23 -> V_228 += V_225 ;
if ( ( T_3 ) ( V_227 - V_23 -> V_221 ) > 0 )
V_23 -> V_221 = V_227 ;
return V_23 -> V_228 > 0 ;
}
static void F_184 ( struct V_23 * V_23 )
{
struct V_216 * V_217 = F_179 ( V_23 -> V_31 ) ;
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
static void F_185 ( struct V_23 * V_23 ,
unsigned long V_10 )
{
V_23 -> V_228 -= V_10 ;
F_184 ( V_23 ) ;
if ( F_9 ( V_23 -> V_228 > 0 ) )
return;
if ( ! F_180 ( V_23 ) && F_9 ( V_23 -> V_43 ) )
F_159 ( F_14 ( V_23 ) -> V_43 ) ;
}
static T_7
void F_70 ( struct V_23 * V_23 , unsigned long V_10 )
{
if ( ! F_168 () || ! V_23 -> V_233 )
return;
F_185 ( V_23 , V_10 ) ;
}
static inline int F_186 ( struct V_23 * V_23 )
{
return F_168 () && V_23 -> V_234 ;
}
static inline int F_113 ( struct V_23 * V_23 )
{
return F_168 () && V_23 -> V_222 ;
}
static inline int F_187 ( struct V_133 * V_31 ,
int V_235 , int V_236 )
{
struct V_23 * V_237 , * V_238 ;
V_237 = V_31 -> V_23 [ V_235 ] ;
V_238 = V_31 -> V_23 [ V_236 ] ;
return F_113 ( V_237 ) ||
F_113 ( V_238 ) ;
}
static int F_188 ( struct V_133 * V_31 , void * V_239 )
{
struct V_22 * V_22 = V_239 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
V_23 -> V_222 -- ;
#ifdef F_102
if ( ! V_23 -> V_222 ) {
V_23 -> V_224 += V_22 -> V_81 -
V_23 -> V_223 ;
}
#endif
return 0 ;
}
static int F_189 ( struct V_133 * V_31 , void * V_239 )
{
struct V_22 * V_22 = V_239 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
if ( ! V_23 -> V_222 )
V_23 -> V_223 = V_22 -> V_81 ;
V_23 -> V_222 ++ ;
return 0 ;
}
static void F_190 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_216 * V_217 = F_179 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
long V_240 , V_241 = 1 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
F_191 () ;
F_192 ( V_23 -> V_31 , F_189 , V_242 , ( void * ) V_22 ) ;
F_193 () ;
V_240 = V_23 -> V_243 ;
F_33 (se) {
struct V_23 * V_244 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_74 )
break;
if ( V_241 )
F_156 ( V_244 , V_26 , V_199 ) ;
V_244 -> V_243 -= V_240 ;
if ( V_244 -> V_68 . V_11 )
V_241 = 0 ;
}
if ( ! V_26 )
V_22 -> V_70 -= V_240 ;
V_23 -> V_234 = 1 ;
V_23 -> V_245 = V_22 -> clock ;
F_181 ( & V_217 -> V_229 ) ;
F_26 ( & V_23 -> V_246 , & V_217 -> V_247 ) ;
F_183 ( & V_217 -> V_229 ) ;
}
void F_194 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_216 * V_217 = F_179 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
int V_248 = 1 ;
long V_240 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
V_23 -> V_234 = 0 ;
F_181 ( & V_217 -> V_229 ) ;
V_217 -> V_249 += V_22 -> clock - V_23 -> V_245 ;
F_29 ( & V_23 -> V_246 ) ;
F_183 ( & V_217 -> V_229 ) ;
F_195 ( V_22 ) ;
F_192 ( V_23 -> V_31 , V_242 , F_188 , ( void * ) V_22 ) ;
if ( ! V_23 -> V_68 . V_11 )
return;
V_240 = V_23 -> V_243 ;
F_33 (se) {
if ( V_26 -> V_74 )
V_248 = 0 ;
V_23 = F_21 ( V_26 ) ;
if ( V_248 )
F_150 ( V_23 , V_26 , V_196 ) ;
V_23 -> V_243 += V_240 ;
if ( F_186 ( V_23 ) )
break;
}
if ( ! V_26 )
V_22 -> V_70 += V_240 ;
if ( V_22 -> V_43 == V_22 -> V_231 && V_22 -> V_38 . V_70 )
F_159 ( V_22 -> V_43 ) ;
}
static T_2 F_196 ( struct V_216 * V_217 ,
T_2 V_250 , T_2 V_227 )
{
struct V_23 * V_23 ;
T_2 V_220 = V_250 ;
F_191 () ;
F_197 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_181 ( & V_22 -> V_229 ) ;
if ( ! F_186 ( V_23 ) )
goto V_56;
V_220 = - V_23 -> V_228 + 1 ;
if ( V_220 > V_250 )
V_220 = V_250 ;
V_250 -= V_220 ;
V_23 -> V_228 += V_220 ;
V_23 -> V_221 = V_227 ;
if ( V_23 -> V_228 > 0 )
F_194 ( V_23 ) ;
V_56:
F_183 ( & V_22 -> V_229 ) ;
if ( ! V_250 )
break;
}
F_193 () ;
return V_250 ;
}
static int F_198 ( struct V_216 * V_217 , int V_251 )
{
T_2 V_220 , V_221 ;
int V_231 = 1 , V_234 ;
F_181 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 == V_219 )
goto V_252;
V_234 = ! F_199 ( & V_217 -> V_247 ) ;
V_231 = V_217 -> V_231 && ! V_234 ;
V_217 -> V_253 += V_251 ;
if ( V_231 )
goto V_252;
F_175 ( V_217 ) ;
if ( ! V_234 ) {
V_217 -> V_231 = 1 ;
goto V_252;
}
V_217 -> V_254 += V_251 ;
V_220 = V_217 -> V_220 ;
V_221 = V_217 -> V_221 ;
V_217 -> V_220 = 0 ;
while ( V_234 && V_220 > 0 ) {
F_183 ( & V_217 -> V_229 ) ;
V_220 = F_196 ( V_217 , V_220 ,
V_221 ) ;
F_181 ( & V_217 -> V_229 ) ;
V_234 = ! F_199 ( & V_217 -> V_247 ) ;
}
V_217 -> V_220 = V_220 ;
V_217 -> V_231 = 0 ;
V_252:
if ( V_231 )
V_217 -> V_230 = 0 ;
F_183 ( & V_217 -> V_229 ) ;
return V_231 ;
}
static int F_200 ( struct V_216 * V_217 , T_2 V_255 )
{
struct V_256 * V_257 = & V_217 -> V_258 ;
T_2 V_250 ;
if ( F_201 ( V_257 ) )
return 1 ;
V_250 = F_178 ( F_202 ( V_257 ) ) ;
if ( V_250 < V_255 )
return 1 ;
return 0 ;
}
static void F_203 ( struct V_216 * V_217 )
{
T_2 V_259 = V_260 + V_261 ;
if ( F_200 ( V_217 , V_259 ) )
return;
F_204 ( & V_217 -> V_262 ,
F_205 ( V_260 ) ) ;
}
static void F_206 ( struct V_23 * V_23 )
{
struct V_216 * V_217 = F_179 ( V_23 -> V_31 ) ;
T_3 V_263 = V_23 -> V_228 - V_264 ;
if ( V_263 <= 0 )
return;
F_181 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 != V_219 &&
V_23 -> V_221 == V_217 -> V_221 ) {
V_217 -> V_220 += V_263 ;
if ( V_217 -> V_220 > F_174 () &&
! F_199 ( & V_217 -> V_247 ) )
F_203 ( V_217 ) ;
}
F_183 ( & V_217 -> V_229 ) ;
V_23 -> V_228 -= V_263 ;
}
static T_7 void F_157 ( struct V_23 * V_23 )
{
if ( ! F_168 () )
return;
if ( ! V_23 -> V_233 || V_23 -> V_70 )
return;
F_206 ( V_23 ) ;
}
static void F_207 ( struct V_216 * V_217 )
{
T_2 V_220 = 0 , V_73 = F_174 () ;
T_2 V_227 ;
if ( F_200 ( V_217 , V_261 ) )
return;
F_181 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_218 != V_219 && V_217 -> V_220 > V_73 ) {
V_220 = V_217 -> V_220 ;
V_217 -> V_220 = 0 ;
}
V_227 = V_217 -> V_221 ;
F_183 ( & V_217 -> V_229 ) ;
if ( ! V_220 )
return;
V_220 = F_196 ( V_217 , V_220 , V_227 ) ;
F_181 ( & V_217 -> V_229 ) ;
if ( V_227 == V_217 -> V_221 )
V_217 -> V_220 = V_220 ;
F_183 ( & V_217 -> V_229 ) ;
}
static void F_151 ( struct V_23 * V_23 )
{
if ( ! F_168 () )
return;
if ( ! V_23 -> V_233 || V_23 -> V_43 )
return;
if ( F_186 ( V_23 ) )
return;
F_70 ( V_23 , 0 ) ;
if ( V_23 -> V_228 <= 0 )
F_190 ( V_23 ) ;
}
static void F_164 ( struct V_23 * V_23 )
{
if ( ! F_168 () )
return;
if ( F_9 ( ! V_23 -> V_233 || V_23 -> V_228 > 0 ) )
return;
if ( F_186 ( V_23 ) )
return;
F_190 ( V_23 ) ;
}
static enum V_265 F_208 ( struct V_256 * V_266 )
{
struct V_216 * V_217 =
F_19 ( V_266 , struct V_216 , V_262 ) ;
F_207 ( V_217 ) ;
return V_267 ;
}
static enum V_265 F_209 ( struct V_256 * V_266 )
{
struct V_216 * V_217 =
F_19 ( V_266 , struct V_216 , V_258 ) ;
T_9 V_80 ;
int V_251 ;
int V_231 = 0 ;
for (; ; ) {
V_80 = F_210 ( V_266 ) ;
V_251 = F_211 ( V_266 , V_80 , V_217 -> V_71 ) ;
if ( ! V_251 )
break;
V_231 = F_198 ( V_217 , V_251 ) ;
}
return V_231 ? V_267 : V_268 ;
}
void F_212 ( struct V_216 * V_217 )
{
F_213 ( & V_217 -> V_229 ) ;
V_217 -> V_220 = 0 ;
V_217 -> V_218 = V_219 ;
V_217 -> V_71 = F_205 ( F_173 () ) ;
F_214 ( & V_217 -> V_247 ) ;
F_215 ( & V_217 -> V_258 , V_269 , V_270 ) ;
V_217 -> V_258 . V_271 = F_209 ;
F_215 ( & V_217 -> V_262 , V_269 , V_270 ) ;
V_217 -> V_262 . V_271 = F_208 ;
}
static void F_216 ( struct V_23 * V_23 )
{
V_23 -> V_233 = 0 ;
F_214 ( & V_23 -> V_246 ) ;
}
void F_182 ( struct V_216 * V_217 )
{
while ( F_11 ( F_167 ( & V_217 -> V_258 ) ) ) {
F_183 ( & V_217 -> V_229 ) ;
F_217 ( & V_217 -> V_258 ) ;
F_181 ( & V_217 -> V_229 ) ;
if ( V_217 -> V_230 )
return;
}
V_217 -> V_230 = 1 ;
F_204 ( & V_217 -> V_258 , V_217 -> V_71 ) ;
}
static void F_218 ( struct V_216 * V_217 )
{
F_217 ( & V_217 -> V_258 ) ;
F_217 ( & V_217 -> V_262 ) ;
}
static void T_10 F_219 ( struct V_22 * V_22 )
{
struct V_23 * V_23 ;
F_220 (rq, cfs_rq) {
struct V_216 * V_217 = F_179 ( V_23 -> V_31 ) ;
if ( ! V_23 -> V_233 )
continue;
V_23 -> V_228 = V_217 -> V_218 ;
if ( F_186 ( V_23 ) )
F_194 ( V_23 ) ;
}
}
static inline T_2 F_132 ( struct V_23 * V_23 )
{
return F_14 ( V_23 ) -> V_81 ;
}
static void F_70 ( struct V_23 * V_23 ,
unsigned long V_10 ) {}
static void F_164 ( struct V_23 * V_23 ) {}
static void F_151 ( struct V_23 * V_23 ) {}
static T_7 void F_157 ( struct V_23 * V_23 ) {}
static inline int F_186 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_113 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_187 ( struct V_133 * V_31 ,
int V_235 , int V_236 )
{
return 0 ;
}
void F_212 ( struct V_216 * V_217 ) {}
static void F_216 ( struct V_23 * V_23 ) {}
static inline struct V_216 * F_179 ( struct V_133 * V_31 )
{
return NULL ;
}
static inline void F_218 ( struct V_216 * V_217 ) {}
static inline void F_219 ( struct V_22 * V_22 ) {}
static void F_221 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_222 ( F_35 ( V_27 ) != V_22 ) ;
if ( V_23 -> V_70 > 1 ) {
T_2 V_73 = F_59 ( V_23 , V_26 ) ;
T_2 V_272 = V_26 -> V_78 - V_26 -> V_204 ;
T_3 V_40 = V_73 - V_272 ;
if ( V_40 < 0 ) {
if ( V_22 -> V_43 == V_27 )
F_159 ( V_27 ) ;
return;
}
if ( V_22 -> V_43 != V_27 )
V_40 = F_223 ( T_3 , 10000LL , V_40 ) ;
F_224 ( V_22 , V_40 ) ;
}
}
static void F_225 ( struct V_22 * V_22 )
{
struct V_24 * V_43 = V_22 -> V_43 ;
if ( ! F_226 ( V_22 ) || V_43 -> V_273 != & V_274 )
return;
if ( F_21 ( & V_43 -> V_26 ) -> V_70 < V_65 )
F_221 ( V_22 , V_43 ) ;
}
static inline void
F_221 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
}
static inline void F_225 ( struct V_22 * V_22 )
{
}
static void
F_227 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_110 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
F_33 (se) {
if ( V_26 -> V_74 )
break;
V_23 = F_21 ( V_26 ) ;
F_150 ( V_23 , V_26 , V_110 ) ;
if ( F_186 ( V_23 ) )
break;
V_23 -> V_243 ++ ;
V_110 = V_196 ;
}
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_243 ++ ;
if ( F_186 ( V_23 ) )
break;
F_112 ( V_23 ) ;
F_131 ( V_26 , 1 ) ;
}
if ( ! V_26 ) {
F_134 ( V_22 , V_22 -> V_70 ) ;
F_228 ( V_22 ) ;
}
F_225 ( V_22 ) ;
}
static void F_229 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_110 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
int V_275 = V_110 & V_199 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_156 ( V_23 , V_26 , V_110 ) ;
if ( F_186 ( V_23 ) )
break;
V_23 -> V_243 -- ;
if ( V_23 -> V_68 . V_11 ) {
if ( V_275 && F_31 ( V_26 ) )
F_230 ( F_31 ( V_26 ) ) ;
V_26 = F_31 ( V_26 ) ;
break;
}
V_110 |= V_199 ;
}
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_243 -- ;
if ( F_186 ( V_23 ) )
break;
F_112 ( V_23 ) ;
F_131 ( V_26 , 1 ) ;
}
if ( ! V_26 ) {
F_231 ( V_22 ) ;
F_134 ( V_22 , 1 ) ;
}
F_225 ( V_22 ) ;
}
static unsigned long F_232 ( const int V_276 )
{
return F_233 ( V_276 ) -> V_68 . V_11 ;
}
static unsigned long F_234 ( int V_276 , int type )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_277 = F_232 ( V_276 ) ;
if ( type == 0 || ! F_149 ( V_278 ) )
return V_277 ;
return F_13 ( V_22 -> V_279 [ type - 1 ] , V_277 ) ;
}
static unsigned long F_235 ( int V_276 , int type )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_277 = F_232 ( V_276 ) ;
if ( type == 0 || ! F_149 ( V_278 ) )
return V_277 ;
return F_64 ( V_22 -> V_279 [ type - 1 ] , V_277 ) ;
}
static unsigned long F_236 ( int V_276 )
{
return F_233 ( V_276 ) -> V_280 ;
}
static unsigned long F_237 ( int V_276 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_70 = F_79 ( V_22 -> V_70 ) ;
if ( V_70 )
return V_22 -> V_68 . V_11 / V_70 ;
return 0 ;
}
static void F_238 ( struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 F_37 ;
#ifndef F_41
T_2 V_46 ;
do {
V_46 = V_23 -> V_46 ;
F_239 () ;
F_37 = V_23 -> F_37 ;
} while ( F_37 != V_46 );
#else
F_37 = V_23 -> F_37 ;
#endif
V_26 -> V_39 -= F_37 ;
}
static long F_240 ( struct V_133 * V_31 , int V_276 , long V_281 , long V_282 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_276 ] ;
if ( ! V_31 -> V_32 )
return V_281 ;
F_33 (se) {
long V_17 , V_283 ;
V_31 = V_26 -> V_29 -> V_31 ;
V_283 = V_282 + F_107 ( V_31 , V_26 -> V_29 ) ;
V_17 = V_26 -> V_29 -> V_68 . V_11 + V_281 ;
if ( V_283 > 0 && V_17 < V_283 )
V_281 = ( V_17 * V_31 -> V_137 ) / V_283 ;
else
V_281 = V_31 -> V_137 ;
if ( V_281 < V_138 )
V_281 = V_138 ;
V_281 -= V_26 -> V_68 . V_11 ;
V_282 = 0 ;
}
return V_281 ;
}
static inline unsigned long F_240 ( struct V_133 * V_31 , int V_276 ,
unsigned long V_281 , unsigned long V_282 )
{
return V_281 ;
}
static int F_241 ( struct V_284 * V_285 , struct V_24 * V_27 , int V_286 )
{
T_3 V_287 , V_68 ;
int V_288 , V_289 , V_290 ;
unsigned long V_291 ;
struct V_133 * V_31 ;
unsigned long V_11 ;
int V_292 ;
V_288 = V_285 -> V_293 ;
V_289 = F_177 () ;
V_290 = F_242 ( V_27 ) ;
V_68 = F_234 ( V_290 , V_288 ) ;
V_287 = F_235 ( V_289 , V_288 ) ;
if ( V_286 ) {
V_31 = V_133 ( V_94 ) ;
V_11 = V_94 -> V_26 . V_68 . V_11 ;
V_287 += F_240 ( V_31 , V_289 , - V_11 , - V_11 ) ;
V_68 += F_240 ( V_31 , V_290 , 0 , - V_11 ) ;
}
V_31 = V_133 ( V_27 ) ;
V_11 = V_27 -> V_26 . V_68 . V_11 ;
if ( V_287 > 0 ) {
T_3 V_294 , V_295 ;
V_294 = 100 ;
V_294 *= F_236 ( V_290 ) ;
V_294 *= V_287 +
F_240 ( V_31 , V_289 , V_11 , V_11 ) ;
V_295 = 100 + ( V_285 -> V_296 - 100 ) / 2 ;
V_295 *= F_236 ( V_289 ) ;
V_295 *= V_68 + F_240 ( V_31 , V_290 , 0 , V_11 ) ;
V_292 = V_294 <= V_295 ;
} else
V_292 = true ;
if ( V_286 && V_292 )
return 1 ;
F_147 ( V_27 , V_26 . V_76 . V_297 ) ;
V_291 = F_237 ( V_289 ) ;
if ( V_292 ||
( V_287 <= V_68 &&
V_287 + F_235 ( V_290 , V_288 ) <= V_291 ) ) {
F_147 ( V_285 , V_298 ) ;
F_147 ( V_27 , V_26 . V_76 . V_299 ) ;
return 1 ;
}
return 0 ;
}
static struct V_300 *
F_243 ( struct V_284 * V_285 , struct V_24 * V_27 ,
int V_289 , int V_301 )
{
struct V_300 * V_302 = NULL , * V_303 = V_285 -> V_304 ;
unsigned long V_305 = V_306 , V_287 = 0 ;
int V_307 = 100 + ( V_285 -> V_296 - 100 ) / 2 ;
do {
unsigned long V_68 , V_308 ;
int V_309 ;
int V_310 ;
if ( ! F_244 ( F_245 ( V_303 ) ,
F_246 ( V_27 ) ) )
continue;
V_309 = F_247 ( V_289 ,
F_245 ( V_303 ) ) ;
V_308 = 0 ;
F_248 (i, sched_group_cpus(group)) {
if ( V_309 )
V_68 = F_234 ( V_310 , V_301 ) ;
else
V_68 = F_235 ( V_310 , V_301 ) ;
V_308 += V_68 ;
}
V_308 = ( V_308 * V_311 ) / V_303 -> V_312 -> V_313 ;
if ( V_309 ) {
V_287 = V_308 ;
} else if ( V_308 < V_305 ) {
V_305 = V_308 ;
V_302 = V_303 ;
}
} while ( V_303 = V_303 -> V_56 , V_303 != V_285 -> V_304 );
if ( ! V_302 || 100 * V_287 < V_307 * V_305 )
return NULL ;
return V_302 ;
}
static int
F_249 ( struct V_300 * V_303 , struct V_24 * V_27 , int V_289 )
{
unsigned long V_68 , V_305 = V_306 ;
int V_302 = - 1 ;
int V_310 ;
F_250 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_68 = F_232 ( V_310 ) ;
if ( V_68 < V_305 || ( V_68 == V_305 && V_310 == V_289 ) ) {
V_305 = V_68 ;
V_302 = V_310 ;
}
}
return V_302 ;
}
static int F_251 ( struct V_24 * V_27 , int V_314 )
{
struct V_284 * V_285 ;
struct V_300 * V_315 ;
int V_310 = F_242 ( V_27 ) ;
if ( F_252 ( V_314 ) )
return V_314 ;
if ( V_310 != V_314 && F_253 ( V_310 , V_314 ) && F_252 ( V_310 ) )
return V_310 ;
V_285 = F_254 ( F_255 ( V_316 , V_314 ) ) ;
F_256 (sd) {
V_315 = V_285 -> V_304 ;
do {
if ( ! F_244 ( F_245 ( V_315 ) ,
F_246 ( V_27 ) ) )
goto V_56;
F_248 (i, sched_group_cpus(sg)) {
if ( V_310 == V_314 || ! F_252 ( V_310 ) )
goto V_56;
}
V_314 = F_257 ( F_245 ( V_315 ) ,
F_246 ( V_27 ) ) ;
goto V_317;
V_56:
V_315 = V_315 -> V_56 ;
} while ( V_315 != V_285 -> V_304 );
}
V_317:
return V_314 ;
}
static int
F_258 ( struct V_24 * V_27 , int V_318 , int V_319 )
{
struct V_284 * V_14 , * V_320 = NULL , * V_285 = NULL ;
int V_276 = F_177 () ;
int V_290 = F_242 ( V_27 ) ;
int V_321 = V_276 ;
int V_322 = 0 ;
int V_286 = V_319 & V_323 ;
if ( V_27 -> V_324 == 1 )
return V_290 ;
if ( V_318 & V_325 ) {
if ( F_247 ( V_276 , F_246 ( V_27 ) ) )
V_322 = 1 ;
V_321 = V_290 ;
}
F_191 () ;
F_259 (cpu, tmp) {
if ( ! ( V_14 -> V_110 & V_326 ) )
continue;
if ( V_322 && ( V_14 -> V_110 & V_327 ) &&
F_247 ( V_290 , F_260 ( V_14 ) ) ) {
V_320 = V_14 ;
break;
}
if ( V_14 -> V_110 & V_318 )
V_285 = V_14 ;
}
if ( V_320 ) {
if ( V_276 != V_290 && F_241 ( V_320 , V_27 , V_286 ) )
V_290 = V_276 ;
V_321 = F_251 ( V_27 , V_290 ) ;
goto V_328;
}
while ( V_285 ) {
int V_301 = V_285 -> V_329 ;
struct V_300 * V_303 ;
int V_11 ;
if ( ! ( V_285 -> V_110 & V_318 ) ) {
V_285 = V_285 -> V_330 ;
continue;
}
if ( V_318 & V_325 )
V_301 = V_285 -> V_293 ;
V_303 = F_243 ( V_285 , V_27 , V_276 , V_301 ) ;
if ( ! V_303 ) {
V_285 = V_285 -> V_330 ;
continue;
}
V_321 = F_249 ( V_303 , V_27 , V_276 ) ;
if ( V_321 == - 1 || V_321 == V_276 ) {
V_285 = V_285 -> V_330 ;
continue;
}
V_276 = V_321 ;
V_11 = V_285 -> V_331 ;
V_285 = NULL ;
F_259 (cpu, tmp) {
if ( V_11 <= V_14 -> V_331 )
break;
if ( V_14 -> V_110 & V_318 )
V_285 = V_14 ;
}
}
V_328:
F_193 () ;
return V_321 ;
}
static void
F_261 ( struct V_24 * V_27 , int V_332 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_26 -> V_160 . V_161 ) {
V_26 -> V_160 . V_161 = - F_117 ( V_26 ) ;
F_120 ( V_26 -> V_160 . V_162 , & V_23 -> V_175 ) ;
}
}
static unsigned long
F_262 ( struct V_25 * V_43 , struct V_25 * V_26 )
{
unsigned long V_333 = V_334 ;
return F_57 ( V_333 , V_26 ) ;
}
static int
F_162 ( struct V_25 * V_43 , struct V_25 * V_26 )
{
T_3 V_333 , V_335 = V_43 -> V_39 - V_26 -> V_39 ;
if ( V_335 <= 0 )
return - 1 ;
V_333 = F_262 ( V_43 , V_26 ) ;
if ( V_335 > V_333 )
return 1 ;
return 0 ;
}
static void F_263 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_336 == V_337 ) )
return;
F_33 (se)
F_21 ( V_26 ) -> V_57 = V_26 ;
}
static void F_230 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_336 == V_337 ) )
return;
F_33 (se)
F_21 ( V_26 ) -> V_56 = V_26 ;
}
static void F_264 ( struct V_25 * V_26 )
{
F_33 (se)
F_21 ( V_26 ) -> V_198 = V_26 ;
}
static void F_265 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_319 )
{
struct V_24 * V_43 = V_22 -> V_43 ;
struct V_25 * V_26 = & V_43 -> V_26 , * V_34 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_20 ( V_43 ) ;
int V_338 = V_23 -> V_70 >= V_65 ;
int V_339 = 0 ;
if ( F_11 ( V_26 == V_34 ) )
return;
if ( F_11 ( F_113 ( F_21 ( V_34 ) ) ) )
return;
if ( F_149 ( V_340 ) && V_338 && ! ( V_319 & V_341 ) ) {
F_230 ( V_34 ) ;
V_339 = 1 ;
}
if ( F_266 ( V_43 ) )
return;
if ( F_11 ( V_43 -> V_336 == V_337 ) &&
F_9 ( V_27 -> V_336 != V_337 ) )
goto V_342;
if ( F_11 ( V_27 -> V_336 != V_343 ) || ! F_149 ( V_344 ) )
return;
F_34 ( & V_26 , & V_34 ) ;
F_66 ( F_21 ( V_26 ) ) ;
F_267 ( ! V_34 ) ;
if ( F_162 ( V_26 , V_34 ) == 1 ) {
if ( ! V_339 )
F_230 ( V_34 ) ;
goto V_342;
}
return;
V_342:
F_159 ( V_43 ) ;
if ( F_11 ( ! V_26 -> V_74 || V_43 == V_22 -> V_231 ) )
return;
if ( F_149 ( V_345 ) && V_338 && F_18 ( V_26 ) )
F_263 ( V_26 ) ;
}
static struct V_24 * F_268 ( struct V_22 * V_22 )
{
struct V_24 * V_27 ;
struct V_23 * V_23 = & V_22 -> V_38 ;
struct V_25 * V_26 ;
if ( ! V_23 -> V_70 )
return NULL ;
do {
V_26 = F_161 ( V_23 ) ;
F_160 ( V_23 , V_26 ) ;
V_23 = F_22 ( V_26 ) ;
} while ( V_23 );
V_27 = F_15 ( V_26 ) ;
if ( F_226 ( V_22 ) )
F_221 ( V_22 , V_27 ) ;
return V_27 ;
}
static void F_269 ( struct V_22 * V_22 , struct V_24 * V_207 )
{
struct V_25 * V_26 = & V_207 -> V_26 ;
struct V_23 * V_23 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_163 ( V_23 , V_26 ) ;
}
}
static void F_270 ( struct V_22 * V_22 )
{
struct V_24 * V_43 = V_22 -> V_43 ;
struct V_23 * V_23 = F_20 ( V_43 ) ;
struct V_25 * V_26 = & V_43 -> V_26 ;
if ( F_11 ( V_22 -> V_70 == 1 ) )
return;
F_155 ( V_23 , V_26 ) ;
if ( V_43 -> V_336 != V_346 ) {
F_195 ( V_22 ) ;
F_66 ( V_23 ) ;
V_22 -> V_347 = 1 ;
}
F_264 ( V_26 ) ;
}
static bool F_271 ( struct V_22 * V_22 , struct V_24 * V_27 , bool V_342 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
if ( ! V_26 -> V_74 || F_113 ( F_21 ( V_26 ) ) )
return false ;
F_230 ( V_26 ) ;
F_270 ( V_22 ) ;
return true ;
}
static void F_272 ( struct V_24 * V_27 , struct V_348 * V_349 )
{
F_273 ( V_349 -> V_350 , V_27 , 0 ) ;
F_274 ( V_27 , V_349 -> V_351 ) ;
F_275 ( V_349 -> V_352 , V_27 , 0 ) ;
F_276 ( V_349 -> V_352 , V_27 , 0 ) ;
}
static int
F_277 ( struct V_24 * V_27 , T_2 V_80 , struct V_284 * V_285 )
{
T_3 V_40 ;
if ( V_27 -> V_273 != & V_274 )
return 0 ;
if ( F_11 ( V_27 -> V_336 == V_337 ) )
return 0 ;
if ( F_149 ( V_353 ) && V_178 () -> V_70 &&
( & V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_56 ||
& V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_57 ) )
return 1 ;
if ( V_354 == - 1 )
return 1 ;
if ( V_354 == 0 )
return 0 ;
V_40 = V_80 - V_27 -> V_26 . V_82 ;
return V_40 < ( T_3 ) V_354 ;
}
static
int F_278 ( struct V_24 * V_27 , struct V_348 * V_349 )
{
int V_355 = 0 ;
if ( F_187 ( V_133 ( V_27 ) , V_349 -> V_235 , V_349 -> V_351 ) )
return 0 ;
if ( ! F_247 ( V_349 -> V_351 , F_246 ( V_27 ) ) ) {
int V_276 ;
F_147 ( V_27 , V_26 . V_76 . V_356 ) ;
if ( ! V_349 -> V_357 || ( V_349 -> V_110 & V_358 ) )
return 0 ;
F_250 (cpu, env->dst_grpmask, env->cpus) {
if ( F_247 ( V_276 , F_246 ( V_27 ) ) ) {
V_349 -> V_110 |= V_358 ;
V_349 -> V_359 = V_276 ;
break;
}
}
return 0 ;
}
V_349 -> V_110 &= ~ V_360 ;
if ( F_279 ( V_349 -> V_350 , V_27 ) ) {
F_147 ( V_27 , V_26 . V_76 . V_361 ) ;
return 0 ;
}
V_355 = F_277 ( V_27 , V_349 -> V_350 -> V_81 , V_349 -> V_285 ) ;
if ( ! V_355 ||
V_349 -> V_285 -> V_362 > V_349 -> V_285 -> V_363 ) {
if ( V_355 ) {
F_147 ( V_349 -> V_285 , V_364 [ V_349 -> V_231 ] ) ;
F_147 ( V_27 , V_26 . V_76 . V_365 ) ;
}
return 1 ;
}
F_147 ( V_27 , V_26 . V_76 . V_366 ) ;
return 0 ;
}
static int F_280 ( struct V_348 * V_349 )
{
struct V_24 * V_27 , * V_140 ;
F_281 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_278 ( V_27 , V_349 ) )
continue;
F_272 ( V_27 , V_349 ) ;
F_147 ( V_349 -> V_285 , V_367 [ V_349 -> V_231 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_282 ( struct V_348 * V_349 )
{
struct V_368 * V_369 = & V_349 -> V_350 -> V_132 ;
struct V_24 * V_27 ;
unsigned long V_68 ;
int V_370 = 0 ;
if ( V_349 -> V_307 <= 0 )
return 0 ;
while ( ! F_199 ( V_369 ) ) {
V_27 = F_283 ( V_369 , struct V_24 , V_26 . V_131 ) ;
V_349 -> V_371 ++ ;
if ( V_349 -> V_371 > V_349 -> V_372 )
break;
if ( V_349 -> V_371 > V_349 -> V_373 ) {
V_349 -> V_373 += V_374 ;
V_349 -> V_110 |= V_375 ;
break;
}
if ( ! F_278 ( V_27 , V_349 ) )
goto V_56;
V_68 = F_284 ( V_27 ) ;
if ( F_149 ( V_376 ) && V_68 < 16 && ! V_349 -> V_285 -> V_362 )
goto V_56;
if ( ( V_68 / 2 ) > V_349 -> V_307 )
goto V_56;
F_272 ( V_27 , V_349 ) ;
V_370 ++ ;
V_349 -> V_307 -= V_68 ;
#ifdef F_285
if ( V_349 -> V_231 == V_377 )
break;
#endif
if ( V_349 -> V_307 <= 0 )
break;
continue;
V_56:
F_286 ( & V_27 -> V_26 . V_131 , V_369 ) ;
}
F_65 ( V_349 -> V_285 , V_367 [ V_349 -> V_231 ] , V_370 ) ;
return V_370 ;
}
static void F_287 ( struct V_133 * V_31 , int V_276 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_276 ] ;
struct V_23 * V_23 = V_31 -> V_23 [ V_276 ] ;
if ( F_113 ( V_23 ) )
return;
F_27 ( V_23 , 1 ) ;
if ( V_26 ) {
F_131 ( V_26 , 1 ) ;
if ( ! V_26 -> V_160 . V_157 && ! V_23 -> V_70 )
F_28 ( V_23 ) ;
} else {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_134 ( V_22 , V_22 -> V_70 ) ;
}
}
static void F_288 ( int V_276 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
struct V_23 * V_23 ;
unsigned long V_110 ;
F_289 ( & V_22 -> V_229 , V_110 ) ;
F_195 ( V_22 ) ;
F_220 (rq, cfs_rq) {
F_287 ( V_23 -> V_31 , V_22 -> V_276 ) ;
}
F_290 ( & V_22 -> V_229 , V_110 ) ;
}
static int F_291 ( struct V_133 * V_31 , void * V_239 )
{
unsigned long V_68 ;
long V_276 = ( long ) V_239 ;
if ( ! V_31 -> V_32 ) {
V_68 = F_233 ( V_276 ) -> V_68 . V_11 ;
} else {
V_68 = V_31 -> V_32 -> V_23 [ V_276 ] -> V_378 ;
V_68 *= V_31 -> V_26 [ V_276 ] -> V_68 . V_11 ;
V_68 /= V_31 -> V_32 -> V_23 [ V_276 ] -> V_68 . V_11 + 1 ;
}
V_31 -> V_23 [ V_276 ] -> V_378 = V_68 ;
return 0 ;
}
static void F_292 ( long V_276 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_80 = V_103 ;
if ( V_22 -> V_379 == V_80 )
return;
V_22 -> V_379 = V_80 ;
F_191 () ;
F_293 ( F_291 , V_242 , ( void * ) V_276 ) ;
F_193 () ;
}
static unsigned long F_284 ( struct V_24 * V_27 )
{
struct V_23 * V_23 = F_20 ( V_27 ) ;
unsigned long V_68 ;
V_68 = V_27 -> V_26 . V_68 . V_11 ;
V_68 = F_122 ( V_68 * V_23 -> V_378 , V_23 -> V_68 . V_11 + 1 ) ;
return V_68 ;
}
static inline void F_288 ( int V_276 )
{
}
static inline void F_292 ( long V_276 )
{
}
static unsigned long F_284 ( struct V_24 * V_27 )
{
return V_27 -> V_26 . V_68 . V_11 ;
}
static inline int F_294 ( struct V_284 * V_285 ,
enum V_380 V_231 )
{
int V_301 ;
switch ( V_231 ) {
case V_381 :
V_301 = V_285 -> V_382 ;
break;
case V_377 :
V_301 = V_285 -> V_383 ;
break;
default:
V_301 = V_285 -> V_384 ;
break;
}
return V_301 ;
}
static unsigned long F_295 ( struct V_284 * V_285 , int V_276 )
{
return V_311 ;
}
unsigned long __weak F_296 ( struct V_284 * V_285 , int V_276 )
{
return F_295 ( V_285 , V_276 ) ;
}
static unsigned long F_297 ( struct V_284 * V_285 , int V_276 )
{
unsigned long V_11 = V_285 -> V_331 ;
unsigned long V_385 = V_285 -> V_385 ;
V_385 /= V_11 ;
return V_385 ;
}
unsigned long __weak F_298 ( struct V_284 * V_285 , int V_276 )
{
return F_297 ( V_285 , V_276 ) ;
}
static unsigned long F_299 ( int V_276 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
T_2 V_277 , V_386 , V_387 , V_160 ;
V_387 = F_79 ( V_22 -> V_387 ) ;
V_160 = F_79 ( V_22 -> V_388 ) ;
V_277 = F_300 () + ( V_22 -> clock - V_387 ) ;
if ( F_11 ( V_277 < V_160 ) ) {
V_386 = 0 ;
} else {
V_386 = V_277 - V_160 ;
}
if ( F_11 ( ( T_3 ) V_277 < V_311 ) )
V_277 = V_311 ;
V_277 >>= V_389 ;
return F_122 ( V_386 , V_277 ) ;
}
static void F_301 ( struct V_284 * V_285 , int V_276 )
{
unsigned long V_11 = V_285 -> V_331 ;
unsigned long V_313 = V_311 ;
struct V_300 * V_390 = V_285 -> V_304 ;
if ( ( V_285 -> V_110 & V_391 ) && V_11 > 1 ) {
if ( F_149 ( V_392 ) )
V_313 *= F_298 ( V_285 , V_276 ) ;
else
V_313 *= F_297 ( V_285 , V_276 ) ;
V_313 >>= V_389 ;
}
V_390 -> V_312 -> V_393 = V_313 ;
if ( F_149 ( V_392 ) )
V_313 *= F_296 ( V_285 , V_276 ) ;
else
V_313 *= F_295 ( V_285 , V_276 ) ;
V_313 >>= V_389 ;
V_313 *= F_299 ( V_276 ) ;
V_313 >>= V_389 ;
if ( ! V_313 )
V_313 = 1 ;
F_233 ( V_276 ) -> V_280 = V_313 ;
V_390 -> V_312 -> V_313 = V_313 ;
}
void F_302 ( struct V_284 * V_285 , int V_276 )
{
struct V_284 * V_330 = V_285 -> V_330 ;
struct V_300 * V_303 , * V_390 = V_285 -> V_304 ;
unsigned long V_313 ;
unsigned long V_394 ;
V_394 = F_87 ( V_285 -> V_395 ) ;
V_394 = F_303 ( V_394 , 1UL , V_396 ) ;
V_390 -> V_312 -> V_397 = V_103 + V_394 ;
if ( ! V_330 ) {
F_301 ( V_285 , V_276 ) ;
return;
}
V_313 = 0 ;
if ( V_330 -> V_110 & V_398 ) {
F_248 (cpu, sched_group_cpus(sdg))
V_313 += F_236 ( V_276 ) ;
} else {
V_303 = V_330 -> V_304 ;
do {
V_313 += V_303 -> V_312 -> V_313 ;
V_303 = V_303 -> V_56 ;
} while ( V_303 != V_330 -> V_304 );
}
V_390 -> V_312 -> V_393 = V_390 -> V_312 -> V_313 = V_313 ;
}
static inline int
F_304 ( struct V_284 * V_285 , struct V_300 * V_303 )
{
if ( ! ( V_285 -> V_110 & V_391 ) )
return 0 ;
if ( V_303 -> V_312 -> V_313 * 32 > V_303 -> V_312 -> V_393 * 29 )
return 1 ;
return 0 ;
}
static inline void F_305 ( struct V_348 * V_349 ,
struct V_300 * V_303 , int V_301 ,
int V_309 , int * V_399 , struct V_400 * V_401 )
{
unsigned long V_70 , V_402 , V_403 ;
unsigned long V_68 , V_404 , V_405 ;
unsigned int V_406 = - 1 , V_407 = 0 ;
unsigned long V_408 = 0 ;
int V_310 ;
if ( V_309 )
V_406 = F_306 ( V_303 ) ;
V_404 = 0 ;
V_405 = ~ 0UL ;
V_402 = 0 ;
V_403 = ~ 0UL ;
F_250 (i, sched_group_cpus(group), env->cpus) {
struct V_22 * V_22 = F_233 ( V_310 ) ;
V_70 = V_22 -> V_70 ;
if ( V_309 ) {
if ( F_252 ( V_310 ) && ! V_407 &&
F_247 ( V_310 , F_307 ( V_303 ) ) ) {
V_407 = 1 ;
V_406 = V_310 ;
}
V_68 = F_235 ( V_310 , V_301 ) ;
} else {
V_68 = F_234 ( V_310 , V_301 ) ;
if ( V_68 > V_404 )
V_404 = V_68 ;
if ( V_405 > V_68 )
V_405 = V_68 ;
if ( V_70 > V_402 )
V_402 = V_70 ;
if ( V_403 > V_70 )
V_403 = V_70 ;
}
V_401 -> V_409 += V_68 ;
V_401 -> V_410 += V_70 ;
V_401 -> V_411 += F_232 ( V_310 ) ;
if ( F_252 ( V_310 ) )
V_401 -> V_412 ++ ;
}
if ( V_309 ) {
if ( V_349 -> V_231 != V_377 ) {
if ( V_406 != V_349 -> V_351 ) {
* V_399 = 0 ;
return;
}
F_302 ( V_349 -> V_285 , V_349 -> V_351 ) ;
} else if ( F_308 ( V_103 , V_303 -> V_312 -> V_397 ) )
F_302 ( V_349 -> V_285 , V_349 -> V_351 ) ;
}
V_401 -> V_308 = ( V_401 -> V_409 * V_311 ) / V_303 -> V_312 -> V_313 ;
if ( V_401 -> V_410 )
V_408 = V_401 -> V_411 / V_401 -> V_410 ;
if ( ( V_404 - V_405 ) >= V_408 &&
( V_402 - V_403 ) > 1 )
V_401 -> V_413 = 1 ;
V_401 -> V_414 = F_309 ( V_303 -> V_312 -> V_313 ,
V_311 ) ;
if ( ! V_401 -> V_414 )
V_401 -> V_414 = F_304 ( V_349 -> V_285 , V_303 ) ;
V_401 -> V_415 = V_303 -> V_415 ;
if ( V_401 -> V_414 > V_401 -> V_410 )
V_401 -> V_416 = 1 ;
}
static bool F_310 ( struct V_348 * V_349 ,
struct V_417 * V_418 ,
struct V_300 * V_315 ,
struct V_400 * V_401 )
{
if ( V_401 -> V_308 <= V_418 -> V_419 )
return false ;
if ( V_401 -> V_410 > V_401 -> V_414 )
return true ;
if ( V_401 -> V_413 )
return true ;
if ( ( V_349 -> V_285 -> V_110 & V_420 ) && V_401 -> V_410 &&
V_349 -> V_351 < F_311 ( V_315 ) ) {
if ( ! V_418 -> V_421 )
return true ;
if ( F_311 ( V_418 -> V_421 ) > F_311 ( V_315 ) )
return true ;
}
return false ;
}
static inline void F_312 ( struct V_348 * V_349 ,
int * V_399 , struct V_417 * V_418 )
{
struct V_284 * V_330 = V_349 -> V_285 -> V_330 ;
struct V_300 * V_315 = V_349 -> V_285 -> V_304 ;
struct V_400 V_401 ;
int V_301 , V_422 = 0 ;
if ( V_330 && V_330 -> V_110 & V_423 )
V_422 = 1 ;
V_301 = F_294 ( V_349 -> V_285 , V_349 -> V_231 ) ;
do {
int V_309 ;
V_309 = F_247 ( V_349 -> V_351 , F_245 ( V_315 ) ) ;
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
F_305 ( V_349 , V_315 , V_301 , V_309 , V_399 , & V_401 ) ;
if ( V_309 && ! ( * V_399 ) )
return;
V_418 -> V_424 += V_401 . V_409 ;
V_418 -> V_425 += V_315 -> V_312 -> V_313 ;
if ( V_422 && ! V_309 && V_418 -> V_426 )
V_401 . V_414 = F_13 ( V_401 . V_414 , 1UL ) ;
if ( V_309 ) {
V_418 -> V_287 = V_401 . V_308 ;
V_418 -> V_427 = V_315 ;
V_418 -> V_428 = V_401 . V_410 ;
V_418 -> V_429 = V_401 . V_411 ;
V_418 -> V_426 = V_401 . V_416 ;
V_418 -> V_430 = V_401 . V_412 ;
} else if ( F_310 ( V_349 , V_418 , V_315 , & V_401 ) ) {
V_418 -> V_419 = V_401 . V_308 ;
V_418 -> V_421 = V_315 ;
V_418 -> V_431 = V_401 . V_410 ;
V_418 -> V_432 = V_401 . V_412 ;
V_418 -> V_433 = V_401 . V_414 ;
V_418 -> V_434 = V_401 . V_411 ;
V_418 -> V_435 = V_401 . V_416 ;
V_418 -> V_436 = V_401 . V_415 ;
V_418 -> V_413 = V_401 . V_413 ;
}
V_315 = V_315 -> V_56 ;
} while ( V_315 != V_349 -> V_285 -> V_304 );
}
static int F_313 ( struct V_348 * V_349 , struct V_417 * V_418 )
{
int V_437 ;
if ( ! ( V_349 -> V_285 -> V_110 & V_420 ) )
return 0 ;
if ( ! V_418 -> V_421 )
return 0 ;
V_437 = F_311 ( V_418 -> V_421 ) ;
if ( V_349 -> V_351 > V_437 )
return 0 ;
V_349 -> V_307 = F_309 (
V_418 -> V_419 * V_418 -> V_421 -> V_312 -> V_313 , V_311 ) ;
return 1 ;
}
static inline
void F_314 ( struct V_348 * V_349 , struct V_417 * V_418 )
{
unsigned long V_14 , V_438 = 0 , V_439 = 0 ;
unsigned int V_440 = 2 ;
unsigned long V_441 ;
if ( V_418 -> V_428 ) {
V_418 -> V_429 /= V_418 -> V_428 ;
if ( V_418 -> V_434 >
V_418 -> V_429 )
V_440 = 1 ;
} else {
V_418 -> V_429 =
F_237 ( V_349 -> V_351 ) ;
}
V_441 = V_418 -> V_434
* V_311 ;
V_441 /= V_418 -> V_421 -> V_312 -> V_313 ;
if ( V_418 -> V_419 - V_418 -> V_287 + V_441 >=
( V_441 * V_440 ) ) {
V_349 -> V_307 = V_418 -> V_434 ;
return;
}
V_438 += V_418 -> V_421 -> V_312 -> V_313 *
F_13 ( V_418 -> V_434 , V_418 -> V_419 ) ;
V_438 += V_418 -> V_427 -> V_312 -> V_313 *
F_13 ( V_418 -> V_429 , V_418 -> V_287 ) ;
V_438 /= V_311 ;
V_14 = ( V_418 -> V_434 * V_311 ) /
V_418 -> V_421 -> V_312 -> V_313 ;
if ( V_418 -> V_419 > V_14 )
V_439 += V_418 -> V_421 -> V_312 -> V_313 *
F_13 ( V_418 -> V_434 , V_418 -> V_419 - V_14 ) ;
if ( V_418 -> V_419 * V_418 -> V_421 -> V_312 -> V_313 <
V_418 -> V_434 * V_311 )
V_14 = ( V_418 -> V_419 * V_418 -> V_421 -> V_312 -> V_313 ) /
V_418 -> V_427 -> V_312 -> V_313 ;
else
V_14 = ( V_418 -> V_434 * V_311 ) /
V_418 -> V_427 -> V_312 -> V_313 ;
V_439 += V_418 -> V_427 -> V_312 -> V_313 *
F_13 ( V_418 -> V_429 , V_418 -> V_287 + V_14 ) ;
V_439 /= V_311 ;
if ( V_439 > V_438 )
V_349 -> V_307 = V_418 -> V_434 ;
}
static inline void F_315 ( struct V_348 * V_349 , struct V_417 * V_418 )
{
unsigned long V_442 , V_443 = ~ 0UL ;
V_418 -> V_434 /= V_418 -> V_431 ;
if ( V_418 -> V_413 ) {
V_418 -> V_434 =
F_13 ( V_418 -> V_434 , V_418 -> V_308 ) ;
}
if ( V_418 -> V_419 < V_418 -> V_308 ) {
V_349 -> V_307 = 0 ;
return F_314 ( V_349 , V_418 ) ;
}
if ( ! V_418 -> V_413 ) {
V_443 = ( V_418 -> V_431 -
V_418 -> V_433 ) ;
V_443 *= ( V_444 * V_311 ) ;
V_443 /= V_418 -> V_421 -> V_312 -> V_313 ;
}
V_442 = F_13 ( V_418 -> V_419 - V_418 -> V_308 , V_443 ) ;
V_349 -> V_307 = F_13 ( V_442 * V_418 -> V_421 -> V_312 -> V_313 ,
( V_418 -> V_308 - V_418 -> V_287 ) * V_418 -> V_427 -> V_312 -> V_313 )
/ V_311 ;
if ( V_349 -> V_307 < V_418 -> V_434 )
return F_314 ( V_349 , V_418 ) ;
}
static struct V_300 *
F_316 ( struct V_348 * V_349 , int * V_399 )
{
struct V_417 V_418 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
F_312 ( V_349 , V_399 , & V_418 ) ;
if ( ! ( * V_399 ) )
goto V_64;
if ( ( V_349 -> V_231 == V_445 || V_349 -> V_231 == V_377 ) &&
F_313 ( V_349 , & V_418 ) )
return V_418 . V_421 ;
if ( ! V_418 . V_421 || V_418 . V_431 == 0 )
goto V_446;
V_418 . V_308 = ( V_311 * V_418 . V_424 ) / V_418 . V_425 ;
if ( V_418 . V_413 )
goto V_447;
if ( V_349 -> V_231 == V_377 && V_418 . V_426 &&
! V_418 . V_435 )
goto V_447;
if ( V_418 . V_287 >= V_418 . V_419 )
goto V_446;
if ( V_418 . V_287 >= V_418 . V_308 )
goto V_446;
if ( V_349 -> V_231 == V_445 ) {
if ( ( V_418 . V_430 <= V_418 . V_432 + 1 ) &&
V_418 . V_431 <= V_418 . V_436 )
goto V_446;
} else {
if ( 100 * V_418 . V_419 <= V_349 -> V_285 -> V_296 * V_418 . V_287 )
goto V_446;
}
V_447:
F_315 ( V_349 , & V_418 ) ;
return V_418 . V_421 ;
V_446:
V_64:
V_349 -> V_307 = 0 ;
return NULL ;
}
static struct V_22 * F_317 ( struct V_348 * V_349 ,
struct V_300 * V_303 )
{
struct V_22 * V_421 = NULL , * V_22 ;
unsigned long V_419 = 0 ;
int V_310 ;
F_248 (i, sched_group_cpus(group)) {
unsigned long V_313 = F_236 ( V_310 ) ;
unsigned long V_448 = F_309 ( V_313 ,
V_311 ) ;
unsigned long V_281 ;
if ( ! V_448 )
V_448 = F_304 ( V_349 -> V_285 , V_303 ) ;
if ( ! F_247 ( V_310 , V_349 -> V_1 ) )
continue;
V_22 = F_233 ( V_310 ) ;
V_281 = F_232 ( V_310 ) ;
if ( V_448 && V_22 -> V_70 == 1 && V_281 > V_349 -> V_307 )
continue;
V_281 = ( V_281 * V_311 ) / V_313 ;
if ( V_281 > V_419 ) {
V_419 = V_281 ;
V_421 = V_22 ;
}
}
return V_421 ;
}
static int F_318 ( struct V_348 * V_349 )
{
struct V_284 * V_285 = V_349 -> V_285 ;
if ( V_349 -> V_231 == V_377 ) {
if ( ( V_285 -> V_110 & V_420 ) && V_349 -> V_235 > V_349 -> V_351 )
return 1 ;
}
return F_11 ( V_285 -> V_362 > V_285 -> V_363 + 2 ) ;
}
static int F_319 ( int V_289 , struct V_22 * V_178 ,
struct V_284 * V_285 , enum V_380 V_231 ,
int * V_399 )
{
int V_449 , V_450 , V_451 = 0 ;
struct V_300 * V_303 ;
struct V_22 * V_421 ;
unsigned long V_110 ;
struct V_452 * V_1 = F_320 ( V_453 ) ;
struct V_348 V_349 = {
. V_285 = V_285 ,
. V_351 = V_289 ,
. V_352 = V_178 ,
. V_357 = F_245 ( V_285 -> V_304 ) ,
. V_231 = V_231 ,
. V_373 = V_374 ,
. V_1 = V_1 ,
} ;
if ( V_231 == V_377 )
V_349 . V_357 = NULL ;
F_321 ( V_1 , V_454 ) ;
F_147 ( V_285 , V_455 [ V_231 ] ) ;
V_456:
V_303 = F_316 ( & V_349 , V_399 ) ;
if ( * V_399 == 0 )
goto V_446;
if ( ! V_303 ) {
F_147 ( V_285 , V_457 [ V_231 ] ) ;
goto V_446;
}
V_421 = F_317 ( & V_349 , V_303 ) ;
if ( ! V_421 ) {
F_147 ( V_285 , V_458 [ V_231 ] ) ;
goto V_446;
}
F_267 ( V_421 == V_349 . V_352 ) ;
F_65 ( V_285 , V_459 [ V_231 ] , V_349 . V_307 ) ;
V_449 = 0 ;
if ( V_421 -> V_70 > 1 ) {
V_349 . V_110 |= V_360 ;
V_349 . V_235 = V_421 -> V_276 ;
V_349 . V_350 = V_421 ;
V_349 . V_372 = F_13 ( V_460 , V_421 -> V_70 ) ;
F_292 ( V_349 . V_235 ) ;
V_461:
F_322 ( V_110 ) ;
F_323 ( V_349 . V_352 , V_421 ) ;
V_450 = F_282 ( & V_349 ) ;
V_449 += V_450 ;
F_324 ( V_349 . V_352 , V_421 ) ;
F_325 ( V_110 ) ;
if ( V_450 && V_349 . V_351 != F_177 () )
F_326 ( V_349 . V_351 ) ;
if ( V_349 . V_110 & V_375 ) {
V_349 . V_110 &= ~ V_375 ;
goto V_461;
}
if ( ( V_349 . V_110 & V_358 ) && V_349 . V_307 > 0 ) {
V_349 . V_352 = F_233 ( V_349 . V_359 ) ;
V_349 . V_351 = V_349 . V_359 ;
V_349 . V_110 &= ~ V_358 ;
V_349 . V_371 = 0 ;
V_349 . V_373 = V_374 ;
F_327 ( V_349 . V_351 , V_349 . V_1 ) ;
goto V_461;
}
if ( F_11 ( V_349 . V_110 & V_360 ) ) {
F_327 ( F_24 ( V_421 ) , V_1 ) ;
if ( ! F_328 ( V_1 ) ) {
V_349 . V_371 = 0 ;
V_349 . V_373 = V_374 ;
goto V_456;
}
goto V_446;
}
}
if ( ! V_449 ) {
F_147 ( V_285 , V_462 [ V_231 ] ) ;
if ( V_231 != V_377 )
V_285 -> V_362 ++ ;
if ( F_318 ( & V_349 ) ) {
F_289 ( & V_421 -> V_229 , V_110 ) ;
if ( ! F_247 ( V_289 ,
F_246 ( V_421 -> V_43 ) ) ) {
F_290 ( & V_421 -> V_229 ,
V_110 ) ;
V_349 . V_110 |= V_360 ;
goto V_463;
}
if ( ! V_421 -> V_451 ) {
V_421 -> V_451 = 1 ;
V_421 -> V_464 = V_289 ;
V_451 = 1 ;
}
F_290 ( & V_421 -> V_229 , V_110 ) ;
if ( V_451 ) {
F_329 ( F_24 ( V_421 ) ,
V_465 , V_421 ,
& V_421 -> V_466 ) ;
}
V_285 -> V_362 = V_285 -> V_363 + 1 ;
}
} else
V_285 -> V_362 = 0 ;
if ( F_9 ( ! V_451 ) ) {
V_285 -> V_395 = V_285 -> V_467 ;
} else {
if ( V_285 -> V_395 < V_285 -> V_468 )
V_285 -> V_395 *= 2 ;
}
goto V_128;
V_446:
F_147 ( V_285 , V_469 [ V_231 ] ) ;
V_285 -> V_362 = 0 ;
V_463:
if ( ( ( V_349 . V_110 & V_360 ) &&
V_285 -> V_395 < V_470 ) ||
( V_285 -> V_395 < V_285 -> V_468 ) )
V_285 -> V_395 *= 2 ;
V_449 = 0 ;
V_128:
return V_449 ;
}
void F_330 ( int V_289 , struct V_22 * V_178 )
{
struct V_284 * V_285 ;
int V_471 = 0 ;
unsigned long V_472 = V_103 + V_473 ;
V_178 -> V_474 = V_178 -> clock ;
if ( V_178 -> V_475 < V_354 )
return;
F_183 ( & V_178 -> V_229 ) ;
F_288 ( V_289 ) ;
F_191 () ;
F_259 (this_cpu, sd) {
unsigned long V_394 ;
int V_399 = 1 ;
if ( ! ( V_285 -> V_110 & V_326 ) )
continue;
if ( V_285 -> V_110 & V_476 ) {
V_471 = F_319 ( V_289 , V_178 ,
V_285 , V_377 , & V_399 ) ;
}
V_394 = F_87 ( V_285 -> V_395 ) ;
if ( F_86 ( V_472 , V_285 -> V_477 + V_394 ) )
V_472 = V_285 -> V_477 + V_394 ;
if ( V_471 ) {
V_178 -> V_474 = 0 ;
break;
}
}
F_193 () ;
F_181 ( & V_178 -> V_229 ) ;
if ( V_471 || F_86 ( V_103 , V_178 -> V_472 ) ) {
V_178 -> V_472 = V_472 ;
}
}
static int V_465 ( void * V_239 )
{
struct V_22 * V_478 = V_239 ;
int V_437 = F_24 ( V_478 ) ;
int V_479 = V_478 -> V_464 ;
struct V_22 * V_480 = F_233 ( V_479 ) ;
struct V_284 * V_285 ;
F_331 ( & V_478 -> V_229 ) ;
if ( F_11 ( V_437 != F_177 () ||
! V_478 -> V_451 ) )
goto V_252;
if ( V_478 -> V_70 <= 1 )
goto V_252;
F_267 ( V_478 == V_480 ) ;
F_332 ( V_478 , V_480 ) ;
F_191 () ;
F_259 (target_cpu, sd) {
if ( ( V_285 -> V_110 & V_326 ) &&
F_247 ( V_437 , F_260 ( V_285 ) ) )
break;
}
if ( F_9 ( V_285 ) ) {
struct V_348 V_349 = {
. V_285 = V_285 ,
. V_351 = V_479 ,
. V_352 = V_480 ,
. V_235 = V_478 -> V_276 ,
. V_350 = V_478 ,
. V_231 = V_445 ,
} ;
F_147 ( V_285 , V_481 ) ;
if ( F_280 ( & V_349 ) )
F_147 ( V_285 , V_482 ) ;
else
F_147 ( V_285 , V_483 ) ;
}
F_193 () ;
F_333 ( V_478 , V_480 ) ;
V_252:
V_478 -> V_451 = 0 ;
F_334 ( & V_478 -> V_229 ) ;
return 0 ;
}
static inline int F_335 ( int V_484 )
{
int V_485 = F_336 ( V_486 . V_487 ) ;
if ( V_485 < V_488 && F_252 ( V_485 ) )
return V_485 ;
return V_488 ;
}
static void F_337 ( int V_276 )
{
int V_489 ;
V_486 . V_472 ++ ;
V_489 = F_335 ( V_276 ) ;
if ( V_489 >= V_488 )
return;
if ( F_338 ( V_490 , F_339 ( V_489 ) ) )
return;
F_340 ( V_489 ) ;
return;
}
static inline void F_341 ( int V_276 )
{
if ( F_11 ( F_342 ( V_491 , F_339 ( V_276 ) ) ) ) {
F_327 ( V_276 , V_486 . V_487 ) ;
F_343 ( & V_486 . V_492 ) ;
F_344 ( V_491 , F_339 ( V_276 ) ) ;
}
}
static inline void F_345 ( void )
{
struct V_284 * V_285 ;
int V_276 = F_177 () ;
F_191 () ;
V_285 = F_346 ( F_233 ( V_276 ) -> V_285 ) ;
if ( ! V_285 || ! V_285 -> V_493 )
goto V_328;
V_285 -> V_493 = 0 ;
for (; V_285 ; V_285 = V_285 -> V_32 )
F_347 ( & V_285 -> V_304 -> V_312 -> V_494 ) ;
V_328:
F_193 () ;
}
void F_348 ( void )
{
struct V_284 * V_285 ;
int V_276 = F_177 () ;
F_191 () ;
V_285 = F_346 ( F_233 ( V_276 ) -> V_285 ) ;
if ( ! V_285 || V_285 -> V_493 )
goto V_328;
V_285 -> V_493 = 1 ;
for (; V_285 ; V_285 = V_285 -> V_32 )
F_343 ( & V_285 -> V_304 -> V_312 -> V_494 ) ;
V_328:
F_193 () ;
}
void F_349 ( int V_276 )
{
if ( ! F_350 ( V_276 ) )
return;
if ( F_342 ( V_491 , F_339 ( V_276 ) ) )
return;
F_351 ( V_276 , V_486 . V_487 ) ;
F_347 ( & V_486 . V_492 ) ;
F_352 ( V_491 , F_339 ( V_276 ) ) ;
}
static int T_11 F_353 ( struct V_495 * V_496 ,
unsigned long V_497 , void * V_498 )
{
switch ( V_497 & ~ V_499 ) {
case V_500 :
F_341 ( F_177 () ) ;
return V_501 ;
default:
return V_502 ;
}
}
void F_354 ( void )
{
V_396 = V_473 * F_3 () / 10 ;
}
static void F_355 ( int V_276 , enum V_380 V_231 )
{
int V_399 = 1 ;
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_394 ;
struct V_284 * V_285 ;
unsigned long V_472 = V_103 + 60 * V_473 ;
int V_503 = 0 ;
int V_504 ;
F_288 ( V_276 ) ;
F_191 () ;
F_259 (cpu, sd) {
if ( ! ( V_285 -> V_110 & V_326 ) )
continue;
V_394 = V_285 -> V_395 ;
if ( V_231 != V_445 )
V_394 *= V_285 -> V_505 ;
V_394 = F_87 ( V_394 ) ;
V_394 = F_303 ( V_394 , 1UL , V_396 ) ;
V_504 = V_285 -> V_110 & V_506 ;
if ( V_504 ) {
if ( ! F_356 ( & V_507 ) )
goto V_128;
}
if ( F_308 ( V_103 , V_285 -> V_477 + V_394 ) ) {
if ( F_319 ( V_276 , V_22 , V_285 , V_231 , & V_399 ) ) {
V_231 = F_252 ( V_276 ) ? V_445 : V_381 ;
}
V_285 -> V_477 = V_103 ;
}
if ( V_504 )
F_357 ( & V_507 ) ;
V_128:
if ( F_86 ( V_472 , V_285 -> V_477 + V_394 ) ) {
V_472 = V_285 -> V_477 + V_394 ;
V_503 = 1 ;
}
if ( ! V_399 )
break;
}
F_193 () ;
if ( F_9 ( V_503 ) )
V_22 -> V_472 = V_472 ;
}
static void F_358 ( int V_289 , enum V_380 V_231 )
{
struct V_22 * V_178 = F_233 ( V_289 ) ;
struct V_22 * V_22 ;
int V_406 ;
if ( V_231 != V_445 ||
! F_342 ( V_490 , F_339 ( V_289 ) ) )
goto V_108;
F_248 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_406 == V_289 || ! F_252 ( V_406 ) )
continue;
if ( F_359 () )
break;
V_22 = F_233 ( V_406 ) ;
F_331 ( & V_22 -> V_229 ) ;
F_195 ( V_22 ) ;
F_360 ( V_22 ) ;
F_334 ( & V_22 -> V_229 ) ;
F_355 ( V_406 , V_445 ) ;
if ( F_86 ( V_178 -> V_472 , V_22 -> V_472 ) )
V_178 -> V_472 = V_22 -> V_472 ;
}
V_486 . V_472 = V_178 -> V_472 ;
V_108:
F_344 ( V_490 , F_339 ( V_289 ) ) ;
}
static inline int F_361 ( struct V_22 * V_22 , int V_276 )
{
unsigned long V_80 = V_103 ;
struct V_284 * V_285 ;
if ( F_11 ( F_252 ( V_276 ) ) )
return 0 ;
F_345 () ;
F_341 ( V_276 ) ;
if ( F_9 ( ! F_126 ( & V_486 . V_492 ) ) )
return 0 ;
if ( F_89 ( V_80 , V_486 . V_472 ) )
return 0 ;
if ( V_22 -> V_70 >= 2 )
goto V_508;
F_191 () ;
F_259 (cpu, sd) {
struct V_300 * V_315 = V_285 -> V_304 ;
struct V_509 * V_312 = V_315 -> V_312 ;
int V_510 = F_126 ( & V_312 -> V_494 ) ;
if ( V_285 -> V_110 & V_511 && V_510 > 1 )
goto V_512;
if ( V_285 -> V_110 & V_420 && V_510 != V_315 -> V_415
&& ( F_257 ( V_486 . V_487 ,
F_260 ( V_285 ) ) < V_276 ) )
goto V_512;
if ( ! ( V_285 -> V_110 & ( V_511 | V_420 ) ) )
break;
}
F_193 () ;
return 0 ;
V_512:
F_193 () ;
V_508:
return 1 ;
}
static void F_358 ( int V_289 , enum V_380 V_231 ) { }
static void F_362 ( struct V_513 * V_514 )
{
int V_289 = F_177 () ;
struct V_22 * V_178 = F_233 ( V_289 ) ;
enum V_380 V_231 = V_178 -> F_330 ?
V_445 : V_381 ;
F_355 ( V_289 , V_231 ) ;
F_358 ( V_289 , V_231 ) ;
}
static inline int F_363 ( int V_276 )
{
return ! F_364 ( F_233 ( V_276 ) -> V_285 ) ;
}
void F_365 ( struct V_22 * V_22 , int V_276 )
{
if ( F_308 ( V_103 , V_22 -> V_472 ) &&
F_9 ( ! F_363 ( V_276 ) ) )
F_366 ( V_515 ) ;
#ifdef F_367
if ( F_361 ( V_22 , V_276 ) && F_9 ( ! F_363 ( V_276 ) ) )
F_337 ( V_276 ) ;
#endif
}
static void F_368 ( struct V_22 * V_22 )
{
F_5 () ;
}
static void F_369 ( struct V_22 * V_22 )
{
F_5 () ;
F_219 ( V_22 ) ;
}
static void F_370 ( struct V_22 * V_22 , struct V_24 * V_43 , int V_208 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_43 -> V_26 ;
F_33 (se) {
V_23 = F_21 ( V_26 ) ;
F_165 ( V_23 , V_26 , V_208 ) ;
}
if ( F_81 ( V_95 ) )
F_98 ( V_22 , V_43 ) ;
F_134 ( V_22 , 1 ) ;
}
static void F_371 ( struct V_24 * V_27 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 , * V_43 ;
int V_289 = F_177 () ;
struct V_22 * V_22 = V_178 () ;
unsigned long V_110 ;
F_289 ( & V_22 -> V_229 , V_110 ) ;
F_195 ( V_22 ) ;
V_23 = F_20 ( V_94 ) ;
V_43 = V_23 -> V_43 ;
if ( F_11 ( F_242 ( V_27 ) != V_289 ) ) {
F_191 () ;
F_372 ( V_27 , V_289 ) ;
F_193 () ;
}
F_66 ( V_23 ) ;
if ( V_43 )
V_26 -> V_39 = V_43 -> V_39 ;
F_148 ( V_23 , V_26 , 1 ) ;
if ( V_516 && V_43 && F_38 ( V_43 , V_26 ) ) {
F_373 ( V_43 -> V_39 , V_26 -> V_39 ) ;
F_159 ( V_22 -> V_43 ) ;
}
V_26 -> V_39 -= V_23 -> F_37 ;
F_290 ( & V_22 -> V_229 , V_110 ) ;
}
static void
F_374 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_517 )
{
if ( ! V_27 -> V_26 . V_74 )
return;
if ( V_22 -> V_43 == V_27 ) {
if ( V_27 -> V_518 > V_517 )
F_159 ( V_22 -> V_43 ) ;
} else
F_276 ( V_22 , V_27 , 0 ) ;
}
static void F_375 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_74 && V_27 -> V_200 != V_519 ) {
F_148 ( V_23 , V_26 , 0 ) ;
V_26 -> V_39 -= V_23 -> F_37 ;
}
#if F_376 ( V_520 ) && F_376 ( F_102 )
if ( V_27 -> V_26 . V_160 . V_161 ) {
struct V_23 * V_23 = F_21 ( & V_27 -> V_26 ) ;
F_117 ( & V_27 -> V_26 ) ;
F_130 ( V_23 ,
V_27 -> V_26 . V_160 . V_162 ) ;
}
#endif
}
static void F_377 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
if ( ! V_27 -> V_26 . V_74 )
return;
if ( V_22 -> V_43 == V_27 )
F_159 ( V_22 -> V_43 ) ;
else
F_276 ( V_22 , V_27 , 0 ) ;
}
static void F_378 ( struct V_22 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_43 -> V_26 ;
F_33 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_160 ( V_23 , V_26 ) ;
F_70 ( V_23 , 0 ) ;
}
}
void F_379 ( struct V_23 * V_23 )
{
V_23 -> V_49 = V_521 ;
V_23 -> F_37 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_41
V_23 -> V_46 = V_23 -> F_37 ;
#endif
#if F_376 ( V_520 ) && F_376 ( F_102 )
F_380 ( & V_23 -> V_159 , 1 ) ;
F_380 ( & V_23 -> V_175 , 0 ) ;
#endif
}
static void F_381 ( struct V_24 * V_27 , int V_74 )
{
struct V_23 * V_23 ;
if ( ! V_74 && ( ! V_27 -> V_26 . V_78 || V_27 -> V_200 == V_522 ) )
V_74 = 1 ;
if ( ! V_74 )
V_27 -> V_26 . V_39 -= F_21 ( & V_27 -> V_26 ) -> F_37 ;
F_382 ( V_27 , F_242 ( V_27 ) ) ;
if ( ! V_74 ) {
V_23 = F_21 ( & V_27 -> V_26 ) ;
V_27 -> V_26 . V_39 += V_23 -> F_37 ;
#ifdef F_102
V_27 -> V_26 . V_160 . V_161 = F_108 ( & V_23 -> V_159 ) ;
V_23 -> V_166 += V_27 -> V_26 . V_160 . V_162 ;
#endif
}
}
void F_383 ( struct V_133 * V_31 )
{
int V_310 ;
F_218 ( F_179 ( V_31 ) ) ;
F_384 (i) {
if ( V_31 -> V_23 )
F_385 ( V_31 -> V_23 [ V_310 ] ) ;
if ( V_31 -> V_26 )
F_385 ( V_31 -> V_26 [ V_310 ] ) ;
}
F_385 ( V_31 -> V_23 ) ;
F_385 ( V_31 -> V_26 ) ;
}
int F_386 ( struct V_133 * V_31 , struct V_133 * V_32 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 ;
int V_310 ;
V_31 -> V_23 = F_387 ( sizeof( V_23 ) * V_488 , V_523 ) ;
if ( ! V_31 -> V_23 )
goto V_524;
V_31 -> V_26 = F_387 ( sizeof( V_26 ) * V_488 , V_523 ) ;
if ( ! V_31 -> V_26 )
goto V_524;
V_31 -> V_137 = V_69 ;
F_212 ( F_179 ( V_31 ) ) ;
F_384 (i) {
V_23 = F_388 ( sizeof( struct V_23 ) ,
V_523 , F_389 ( V_310 ) ) ;
if ( ! V_23 )
goto V_524;
V_26 = F_388 ( sizeof( struct V_25 ) ,
V_523 , F_389 ( V_310 ) ) ;
if ( ! V_26 )
goto V_525;
F_379 ( V_23 ) ;
F_390 ( V_31 , V_23 , V_26 , V_310 , V_32 -> V_26 [ V_310 ] ) ;
}
return 1 ;
V_525:
F_385 ( V_23 ) ;
V_524:
return 0 ;
}
void F_391 ( struct V_133 * V_31 , int V_276 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
unsigned long V_110 ;
if ( ! V_31 -> V_23 [ V_276 ] -> V_30 )
return;
F_289 ( & V_22 -> V_229 , V_110 ) ;
F_28 ( V_31 -> V_23 [ V_276 ] ) ;
F_290 ( & V_22 -> V_229 , V_110 ) ;
}
void F_390 ( struct V_133 * V_31 , struct V_23 * V_23 ,
struct V_25 * V_26 , int V_276 ,
struct V_25 * V_32 )
{
struct V_22 * V_22 = F_233 ( V_276 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_22 = V_22 ;
F_216 ( V_23 ) ;
V_31 -> V_23 [ V_276 ] = V_23 ;
V_31 -> V_26 [ V_276 ] = V_26 ;
if ( ! V_26 )
return;
if ( ! V_32 )
V_26 -> V_23 = & V_22 -> V_38 ;
else
V_26 -> V_23 = V_32 -> V_29 ;
V_26 -> V_29 = V_23 ;
F_111 ( & V_26 -> V_68 , 0 ) ;
V_26 -> V_32 = V_32 ;
}
int F_392 ( struct V_133 * V_31 , unsigned long V_137 )
{
int V_310 ;
unsigned long V_110 ;
if ( ! V_31 -> V_26 [ 0 ] )
return - V_526 ;
V_137 = F_303 ( V_137 , F_128 ( V_138 ) , F_128 ( V_527 ) ) ;
F_393 ( & V_528 ) ;
if ( V_31 -> V_137 == V_137 )
goto V_317;
V_31 -> V_137 = V_137 ;
F_384 (i) {
struct V_22 * V_22 = F_233 ( V_310 ) ;
struct V_25 * V_26 ;
V_26 = V_31 -> V_26 [ V_310 ] ;
F_289 ( & V_22 -> V_229 , V_110 ) ;
F_33 (se)
F_112 ( F_22 ( V_26 ) ) ;
F_290 ( & V_22 -> V_229 , V_110 ) ;
}
V_317:
F_394 ( & V_528 ) ;
return 0 ;
}
void F_383 ( struct V_133 * V_31 ) { }
int F_386 ( struct V_133 * V_31 , struct V_133 * V_32 )
{
return 1 ;
}
void F_391 ( struct V_133 * V_31 , int V_276 ) { }
static unsigned int F_395 ( struct V_22 * V_22 , struct V_24 * V_529 )
{
struct V_25 * V_26 = & V_529 -> V_26 ;
unsigned int V_530 = 0 ;
if ( V_22 -> V_38 . V_68 . V_11 )
V_530 = F_396 ( F_59 ( F_21 ( V_26 ) , V_26 ) ) ;
return V_530 ;
}
void F_397 ( struct V_531 * V_532 , int V_276 )
{
struct V_23 * V_23 ;
F_191 () ;
F_220 (cpu_rq(cpu), cfs_rq)
F_398 ( V_532 , V_276 , V_23 ) ;
F_193 () ;
}
T_12 void F_399 ( void )
{
#ifdef F_102
F_400 ( V_515 , F_362 ) ;
#ifdef F_367
V_486 . V_472 = V_103 ;
F_401 ( & V_486 . V_487 , V_533 ) ;
F_402 ( F_353 , 0 ) ;
#endif
#endif
}
