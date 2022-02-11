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
static unsigned long
F_11 ( unsigned long V_17 , unsigned long V_4 ,
struct V_1 * V_2 )
{
T_2 V_18 ;
if ( F_12 ( V_4 > ( 1UL << V_19 ) ) )
V_18 = ( T_2 ) V_17 * F_13 ( V_4 ) ;
else
V_18 = ( T_2 ) V_17 ;
if ( ! V_2 -> V_5 ) {
unsigned long V_7 = F_13 ( V_2 -> V_4 ) ;
if ( V_20 > 32 && F_14 ( V_7 >= V_21 ) )
V_2 -> V_5 = 1 ;
else if ( F_14 ( ! V_7 ) )
V_2 -> V_5 = V_21 ;
else
V_2 -> V_5 = V_21 / V_7 ;
}
if ( F_14 ( V_18 > V_21 ) )
V_18 = F_15 ( F_15 ( V_18 , V_22 / 2 ) * V_2 -> V_5 ,
V_22 / 2 ) ;
else
V_18 = F_15 ( V_18 * V_2 -> V_5 , V_22 ) ;
return ( unsigned long ) F_16 ( V_18 , ( T_2 ) ( unsigned long ) V_23 ) ;
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
static inline unsigned long
F_60 ( unsigned long V_42 , struct V_27 * V_28 )
{
if ( F_14 ( V_28 -> V_70 . V_4 != V_71 ) )
V_42 = F_11 ( V_42 , V_71 , & V_28 -> V_70 ) ;
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
V_75 = F_11 ( V_75 , V_28 -> V_70 . V_4 , V_70 ) ;
}
return V_75 ;
}
static T_2 F_63 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
return F_60 ( F_62 ( V_25 , V_28 ) , V_28 ) ;
}
void F_64 ( struct V_26 * V_29 )
{
T_7 V_75 ;
V_29 -> V_28 . V_77 . V_78 = 0 ;
V_75 = F_62 ( F_23 ( V_29 ) , & V_29 -> V_28 ) >> 10 ;
V_29 -> V_28 . V_77 . V_79 = V_75 ;
V_29 -> V_28 . V_77 . V_80 = V_75 ;
F_65 ( & V_29 -> V_28 ) ;
}
void F_64 ( struct V_26 * V_29 )
{
}
static inline void
F_66 ( struct V_25 * V_25 , struct V_27 * V_45 ,
unsigned long V_17 )
{
unsigned long V_81 ;
F_67 ( V_45 -> V_82 . V_83 ,
F_68 ( ( T_2 ) V_17 , V_45 -> V_82 . V_83 ) ) ;
V_45 -> V_84 += V_17 ;
F_69 ( V_25 , V_85 , V_17 ) ;
V_81 = F_60 ( V_17 , V_45 ) ;
V_45 -> V_41 += V_81 ;
F_42 ( V_25 ) ;
}
static void F_70 ( struct V_25 * V_25 )
{
struct V_27 * V_45 = V_25 -> V_45 ;
T_2 V_86 = F_71 ( F_17 ( V_25 ) ) ;
unsigned long V_17 ;
if ( F_14 ( ! V_45 ) )
return;
V_17 = ( unsigned long ) ( V_86 - V_45 -> V_87 ) ;
if ( ! V_17 )
return;
F_66 ( V_25 , V_45 , V_17 ) ;
V_45 -> V_87 = V_86 ;
if ( F_21 ( V_45 ) ) {
struct V_26 * V_88 = F_18 ( V_45 ) ;
F_72 ( V_88 , V_17 , V_45 -> V_41 ) ;
F_73 ( V_88 , V_17 ) ;
F_74 ( V_88 , V_17 ) ;
}
F_75 ( V_25 , V_17 ) ;
}
static inline void
F_76 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_82 . V_89 , F_77 ( F_17 ( V_25 ) ) ) ;
}
static void F_78 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_76 ( V_25 , V_28 ) ;
}
static void
F_79 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_67 ( V_28 -> V_82 . V_90 , F_68 ( V_28 -> V_82 . V_90 ,
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_89 ) ) ;
F_67 ( V_28 -> V_82 . V_91 , V_28 -> V_82 . V_91 + 1 ) ;
F_67 ( V_28 -> V_82 . V_92 , V_28 -> V_82 . V_92 +
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_89 ) ;
#ifdef F_80
if ( F_21 ( V_28 ) ) {
F_81 ( F_18 ( V_28 ) ,
F_77 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_89 ) ;
}
#endif
F_67 ( V_28 -> V_82 . V_89 , 0 ) ;
}
static inline void
F_82 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 != V_25 -> V_45 )
F_79 ( V_25 , V_28 ) ;
}
static inline void
F_83 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_28 -> V_87 = F_71 ( F_17 ( V_25 ) ) ;
}
static void F_84 ( struct V_26 * V_29 )
{
int V_93 ;
if ( ! V_29 -> V_94 )
return;
V_93 = F_85 ( V_29 -> V_94 -> V_95 ) ;
if ( V_29 -> V_95 == V_93 )
return;
V_29 -> V_95 = V_93 ;
}
void F_86 ( int V_96 , int V_97 , bool V_98 )
{
struct V_26 * V_29 = V_99 ;
if ( ! V_100 )
return;
if ( ! V_98 )
V_29 -> V_101 = F_16 ( V_102 ,
V_29 -> V_101 + F_87 ( 10 ) ) ;
F_84 ( V_29 ) ;
}
static void F_88 ( struct V_26 * V_29 )
{
F_85 ( V_29 -> V_94 -> V_95 ) ++ ;
V_29 -> V_94 -> V_103 = 0 ;
}
void F_89 ( struct V_104 * V_105 )
{
unsigned long V_106 , V_107 , V_86 = V_108 ;
struct V_26 * V_29 = V_99 ;
struct V_109 * V_94 = V_29 -> V_94 ;
struct V_110 * V_111 ;
unsigned long V_112 , V_113 ;
long V_97 ;
F_20 ( V_29 != F_22 ( V_105 , struct V_26 , V_114 ) ) ;
V_105 -> V_58 = V_105 ;
if ( V_29 -> V_115 & V_116 )
return;
if ( V_94 -> V_117 == V_118 )
V_94 -> V_117 = F_90 () ;
if ( V_94 -> V_117 != V_119 ) {
if ( F_90 () == V_94 -> V_117 &&
! F_91 ( V_120 ) )
return;
V_94 -> V_117 = V_119 ;
}
V_106 = V_94 -> V_121 ;
if ( F_92 ( V_86 , V_106 ) ) {
V_29 -> V_101 = V_122 ;
V_107 = V_86 + F_93 ( V_123 ) ;
F_94 ( & V_94 -> V_121 , V_107 ) ;
}
V_106 = V_94 -> V_124 ;
if ( F_95 ( V_86 , V_106 ) )
return;
if ( V_29 -> V_101 == 0 )
V_29 -> V_101 = V_122 ;
V_107 = V_86 + F_93 ( V_29 -> V_101 ) ;
if ( F_96 ( & V_94 -> V_124 , V_106 , V_107 ) != V_106 )
return;
if ( F_97 ( F_90 () ) )
return;
V_112 = V_94 -> V_103 ;
V_97 = V_125 ;
V_97 <<= 20 - V_126 ;
if ( ! V_97 )
return;
F_98 ( & V_94 -> V_127 ) ;
V_111 = F_99 ( V_94 , V_112 ) ;
if ( ! V_111 ) {
F_88 ( V_29 ) ;
V_112 = 0 ;
V_111 = V_94 -> V_128 ;
}
for (; V_111 ; V_111 = V_111 -> V_129 ) {
if ( ! F_100 ( V_111 ) )
continue;
if ( V_111 -> V_130 - V_111 -> V_131 < V_132 )
continue;
do {
V_112 = F_68 ( V_112 , V_111 -> V_131 ) ;
V_113 = F_101 ( V_112 + ( V_97 << V_126 ) , V_132 ) ;
V_113 = F_16 ( V_113 , V_111 -> V_130 ) ;
V_97 -= F_102 ( V_111 , V_112 , V_113 ) ;
V_112 = V_113 ;
if ( V_97 <= 0 )
goto V_133;
} while ( V_113 != V_111 -> V_130 );
}
V_133:
if ( V_111 )
V_94 -> V_103 = V_112 ;
else
F_88 ( V_29 ) ;
F_103 ( & V_94 -> V_127 ) ;
}
void F_104 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
struct V_104 * V_105 = & V_45 -> V_114 ;
T_2 V_73 , V_86 ;
if ( ! V_45 -> V_94 || ( V_45 -> V_115 & V_116 ) || V_105 -> V_58 != V_105 )
return;
V_86 = V_45 -> V_28 . V_84 ;
V_73 = ( T_2 ) V_45 -> V_101 * V_134 ;
if ( V_86 - V_45 -> V_135 > V_73 ) {
if ( ! V_45 -> V_135 )
V_45 -> V_101 = V_122 ;
V_45 -> V_135 = V_86 ;
if ( ! F_95 ( V_108 , V_45 -> V_94 -> V_124 ) ) {
F_105 ( V_105 , F_89 ) ;
F_106 ( V_45 , V_105 , true ) ;
}
}
}
static void F_104 ( struct V_24 * V_24 , struct V_26 * V_45 )
{
}
static void
F_107 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_1 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_1 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
#ifdef F_108
if ( F_21 ( V_28 ) )
F_109 ( & V_28 -> V_136 , & F_17 ( V_25 ) -> V_137 ) ;
#endif
V_25 -> V_72 ++ ;
}
static void
F_110 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
F_2 ( & V_25 -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( ! F_34 ( V_28 ) )
F_2 ( & F_17 ( V_25 ) -> V_70 , V_28 -> V_70 . V_4 ) ;
if ( F_21 ( V_28 ) )
F_111 ( & V_28 -> V_136 ) ;
V_25 -> V_72 -- ;
}
static inline long F_112 ( struct V_138 * V_33 , struct V_25 * V_25 )
{
long V_139 ;
V_139 = F_113 ( & V_33 -> V_140 ) ;
V_139 -= V_25 -> V_141 ;
V_139 += V_25 -> V_70 . V_4 ;
return V_139 ;
}
static long F_114 ( struct V_25 * V_25 , struct V_138 * V_33 )
{
long V_139 , V_70 , V_142 ;
V_139 = F_112 ( V_33 , V_25 ) ;
V_70 = V_25 -> V_70 . V_4 ;
V_142 = ( V_33 -> V_142 * V_70 ) ;
if ( V_139 )
V_142 /= V_139 ;
if ( V_142 < V_143 )
V_142 = V_143 ;
if ( V_142 > V_33 -> V_142 )
V_142 = V_33 -> V_142 ;
return V_142 ;
}
static inline long F_114 ( struct V_25 * V_25 , struct V_138 * V_33 )
{
return V_33 -> V_142 ;
}
static void F_115 ( struct V_25 * V_25 , struct V_27 * V_28 ,
unsigned long V_4 )
{
if ( V_28 -> V_76 ) {
if ( V_25 -> V_45 == V_28 )
F_70 ( V_25 ) ;
F_110 ( V_25 , V_28 ) ;
}
F_3 ( & V_28 -> V_70 , V_4 ) ;
if ( V_28 -> V_76 )
F_107 ( V_25 , V_28 ) ;
}
static void F_116 ( struct V_25 * V_25 )
{
struct V_138 * V_33 ;
struct V_27 * V_28 ;
long V_142 ;
V_33 = V_25 -> V_33 ;
V_28 = V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
if ( ! V_28 || F_117 ( V_25 ) )
return;
#ifndef F_108
if ( F_12 ( V_28 -> V_70 . V_4 == V_33 -> V_142 ) )
return;
#endif
V_142 = F_114 ( V_25 , V_33 ) ;
F_115 ( F_24 ( V_28 ) , V_28 , V_142 ) ;
}
static inline void F_116 ( struct V_25 * V_25 )
{
}
static T_8 T_2 F_118 ( T_2 V_144 , T_2 V_145 )
{
unsigned int V_146 ;
if ( ! V_145 )
return V_144 ;
else if ( F_14 ( V_145 > V_147 * 63 ) )
return 0 ;
V_146 = V_145 ;
if ( F_14 ( V_146 >= V_147 ) ) {
V_144 >>= V_146 / V_147 ;
V_146 %= V_147 ;
}
V_144 *= V_148 [ V_146 ] ;
return V_144 >> 32 ;
}
static T_7 F_119 ( T_2 V_145 )
{
T_7 V_149 = 0 ;
if ( F_12 ( V_145 <= V_147 ) )
return V_150 [ V_145 ] ;
else if ( F_14 ( V_145 >= V_151 ) )
return V_152 ;
do {
V_149 /= 2 ;
V_149 += V_150 [ V_147 ] ;
V_145 -= V_147 ;
} while ( V_145 > V_147 );
V_149 = F_118 ( V_149 , V_145 ) ;
return V_149 + V_150 [ V_145 ] ;
}
static T_8 int F_120 ( T_2 V_86 ,
struct V_153 * V_154 ,
int V_155 )
{
T_2 V_42 , V_156 ;
T_7 V_157 ;
int V_158 , V_159 = 0 ;
V_42 = V_86 - V_154 -> V_160 ;
if ( ( T_3 ) V_42 < 0 ) {
V_154 -> V_160 = V_86 ;
return 0 ;
}
V_42 >>= 10 ;
if ( ! V_42 )
return 0 ;
V_154 -> V_160 = V_86 ;
V_158 = V_154 -> V_80 % 1024 ;
if ( V_42 + V_158 >= 1024 ) {
V_159 = 1 ;
V_158 = 1024 - V_158 ;
if ( V_155 )
V_154 -> V_79 += V_158 ;
V_154 -> V_80 += V_158 ;
V_42 -= V_158 ;
V_156 = V_42 / 1024 ;
V_42 %= 1024 ;
V_154 -> V_79 = F_118 ( V_154 -> V_79 ,
V_156 + 1 ) ;
V_154 -> V_80 = F_118 ( V_154 -> V_80 ,
V_156 + 1 ) ;
V_157 = F_119 ( V_156 ) ;
if ( V_155 )
V_154 -> V_79 += V_157 ;
V_154 -> V_80 += V_157 ;
}
if ( V_155 )
V_154 -> V_79 += V_42 ;
V_154 -> V_80 += V_42 ;
return V_159 ;
}
static inline T_2 F_121 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 V_161 = F_122 ( & V_25 -> V_162 ) ;
V_161 -= V_28 -> V_77 . V_78 ;
if ( ! V_161 )
return 0 ;
V_28 -> V_77 . V_163 = F_118 ( V_28 -> V_77 . V_163 , V_161 ) ;
V_28 -> V_77 . V_78 = 0 ;
return V_161 ;
}
static inline void F_123 ( struct V_25 * V_25 ,
int V_164 )
{
struct V_138 * V_33 = V_25 -> V_33 ;
long V_165 ;
V_165 = V_25 -> V_166 + V_25 -> V_167 ;
V_165 -= V_25 -> V_141 ;
if ( V_164 || abs ( V_165 ) > V_25 -> V_141 / 8 ) {
F_124 ( V_165 , & V_33 -> V_140 ) ;
V_25 -> V_141 += V_165 ;
}
}
static inline void F_125 ( struct V_153 * V_154 ,
struct V_25 * V_25 )
{
struct V_138 * V_33 = V_25 -> V_33 ;
long V_149 ;
V_149 = F_126 ( V_154 -> V_79 << V_168 ,
V_154 -> V_80 + 1 ) ;
V_149 -= V_25 -> V_169 ;
if ( abs ( V_149 ) > V_25 -> V_169 / 64 ) {
F_127 ( V_149 , & V_33 -> V_170 ) ;
V_25 -> V_169 += V_149 ;
}
}
static inline void F_128 ( struct V_27 * V_28 )
{
struct V_25 * V_25 = F_25 ( V_28 ) ;
struct V_138 * V_33 = V_25 -> V_33 ;
int V_170 ;
T_2 V_149 ;
V_149 = V_25 -> V_141 * V_33 -> V_142 ;
V_28 -> V_77 . V_163 = F_126 ( V_149 ,
F_113 ( & V_33 -> V_140 ) + 1 ) ;
V_170 = F_129 ( & V_33 -> V_170 ) ;
if ( V_170 < V_71 ) {
V_28 -> V_77 . V_163 *= V_170 ;
V_28 -> V_77 . V_163 >>= V_168 ;
}
}
static inline void F_123 ( struct V_25 * V_25 ,
int V_164 ) {}
static inline void F_125 ( struct V_153 * V_154 ,
struct V_25 * V_25 ) {}
static inline void F_128 ( struct V_27 * V_28 ) {}
static inline void F_65 ( struct V_27 * V_28 )
{
T_7 V_149 ;
V_149 = V_28 -> V_77 . V_79 * F_13 ( V_28 -> V_70 . V_4 ) ;
V_149 /= ( V_28 -> V_77 . V_80 + 1 ) ;
V_28 -> V_77 . V_163 = F_130 ( V_149 ) ;
}
static long F_131 ( struct V_27 * V_28 )
{
long V_171 = V_28 -> V_77 . V_163 ;
if ( F_21 ( V_28 ) ) {
F_65 ( V_28 ) ;
} else {
F_125 ( & V_28 -> V_77 , F_25 ( V_28 ) ) ;
F_128 ( V_28 ) ;
}
return V_28 -> V_77 . V_163 - V_171 ;
}
static inline void F_132 ( struct V_25 * V_25 ,
long V_172 )
{
if ( F_12 ( V_172 < V_25 -> V_167 ) )
V_25 -> V_167 -= V_172 ;
else
V_25 -> V_167 = 0 ;
}
static inline void F_133 ( struct V_27 * V_28 ,
int V_173 )
{
struct V_25 * V_25 = F_24 ( V_28 ) ;
long V_174 ;
T_2 V_86 ;
if ( F_21 ( V_28 ) )
V_86 = F_134 ( V_25 ) ;
else
V_86 = F_134 ( F_25 ( V_28 ) ) ;
if ( ! F_120 ( V_86 , & V_28 -> V_77 , V_28 -> V_76 ) )
return;
V_174 = F_131 ( V_28 ) ;
if ( ! V_173 )
return;
if ( V_28 -> V_76 )
V_25 -> V_166 += V_174 ;
else
F_132 ( V_25 , - V_174 ) ;
}
static void F_30 ( struct V_25 * V_25 , int V_164 )
{
T_2 V_86 = F_134 ( V_25 ) >> 20 ;
T_2 V_161 ;
V_161 = V_86 - V_25 -> V_175 ;
if ( ! V_161 && ! V_164 )
return;
if ( F_113 ( & V_25 -> V_176 ) ) {
unsigned long V_176 ;
V_176 = F_135 ( & V_25 -> V_176 , 0 ) ;
F_132 ( V_25 , V_176 ) ;
}
if ( V_161 ) {
V_25 -> V_167 = F_118 ( V_25 -> V_167 ,
V_161 ) ;
F_136 ( V_161 , & V_25 -> V_162 ) ;
V_25 -> V_175 = V_86 ;
}
F_123 ( V_25 , V_164 ) ;
}
static inline void F_137 ( struct V_24 * V_24 , int V_155 )
{
F_120 ( F_71 ( V_24 ) , & V_24 -> V_77 , V_155 ) ;
F_125 ( & V_24 -> V_77 , & V_24 -> V_40 ) ;
}
static inline void F_138 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_177 )
{
if ( F_14 ( V_28 -> V_77 . V_78 <= 0 ) ) {
V_28 -> V_77 . V_160 = F_71 ( F_17 ( V_25 ) ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_160 -= ( - V_28 -> V_77 . V_78 )
<< 20 ;
F_133 ( V_28 , 0 ) ;
V_28 -> V_77 . V_78 = 0 ;
}
V_177 = 0 ;
} else {
V_28 -> V_77 . V_160 += F_121 ( V_28 )
<< 20 ;
}
if ( V_177 ) {
F_132 ( V_25 , V_28 -> V_77 . V_163 ) ;
F_133 ( V_28 , 0 ) ;
}
V_25 -> V_166 += V_28 -> V_77 . V_163 ;
F_30 ( V_25 , ! V_177 ) ;
}
static inline void F_139 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_178 )
{
F_133 ( V_28 , 1 ) ;
F_30 ( V_25 , ! V_178 ) ;
V_25 -> V_166 -= V_28 -> V_77 . V_163 ;
if ( V_178 ) {
V_25 -> V_167 += V_28 -> V_77 . V_163 ;
V_28 -> V_77 . V_78 = F_122 ( & V_25 -> V_162 ) ;
}
}
void F_140 ( struct V_24 * V_179 )
{
F_137 ( V_179 , 1 ) ;
}
void F_141 ( struct V_24 * V_179 )
{
F_137 ( V_179 , 0 ) ;
}
static inline void F_133 ( struct V_27 * V_28 ,
int V_173 ) {}
static inline void F_137 ( struct V_24 * V_24 , int V_155 ) {}
static inline void F_138 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_177 ) {}
static inline void F_139 ( struct V_25 * V_25 ,
struct V_27 * V_28 ,
int V_178 ) {}
static inline void F_30 ( struct V_25 * V_25 ,
int V_164 ) {}
static void F_142 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_80
struct V_26 * V_180 = NULL ;
if ( F_21 ( V_28 ) )
V_180 = F_18 ( V_28 ) ;
if ( V_28 -> V_82 . V_181 ) {
T_2 V_42 = F_77 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_181 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_82 . V_182 ) )
V_28 -> V_82 . V_182 = V_42 ;
V_28 -> V_82 . V_181 = 0 ;
V_28 -> V_82 . V_183 += V_42 ;
if ( V_180 ) {
F_143 ( V_180 , V_42 >> 10 , 1 ) ;
F_144 ( V_180 , V_42 ) ;
}
}
if ( V_28 -> V_82 . V_184 ) {
T_2 V_42 = F_77 ( F_17 ( V_25 ) ) - V_28 -> V_82 . V_184 ;
if ( ( T_3 ) V_42 < 0 )
V_42 = 0 ;
if ( F_14 ( V_42 > V_28 -> V_82 . V_185 ) )
V_28 -> V_82 . V_185 = V_42 ;
V_28 -> V_82 . V_184 = 0 ;
V_28 -> V_82 . V_183 += V_42 ;
if ( V_180 ) {
if ( V_180 -> V_186 ) {
V_28 -> V_82 . V_187 += V_42 ;
V_28 -> V_82 . V_188 ++ ;
F_145 ( V_180 , V_42 ) ;
}
F_146 ( V_180 , V_42 ) ;
if ( F_14 ( V_189 == V_190 ) ) {
F_147 ( V_190 ,
( void * ) F_148 ( V_180 ) ,
V_42 >> 20 ) ;
}
F_143 ( V_180 , V_42 >> 10 , 0 ) ;
}
}
#endif
}
static void F_149 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
#ifdef F_19
T_3 V_191 = V_28 -> V_41 - V_25 -> F_40 ;
if ( V_191 < 0 )
V_191 = - V_191 ;
if ( V_191 > 3 * V_68 )
F_150 ( V_25 , V_192 ) ;
#endif
}
static void
F_151 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_193 )
{
T_2 V_41 = V_25 -> F_40 ;
if ( V_193 && F_152 ( V_194 ) )
V_41 += F_63 ( V_25 , V_28 ) ;
if ( ! V_193 ) {
unsigned long V_195 = V_68 ;
if ( F_152 ( V_196 ) )
V_195 >>= 1 ;
V_41 -= V_195 ;
}
V_28 -> V_41 = F_39 ( V_28 -> V_41 , V_41 ) ;
}
static void
F_153 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_115 )
{
if ( ! ( V_115 & V_197 ) || ( V_115 & V_198 ) )
V_28 -> V_41 += V_25 -> F_40 ;
F_70 ( V_25 ) ;
F_138 ( V_25 , V_28 , V_115 & V_197 ) ;
F_107 ( V_25 , V_28 ) ;
F_116 ( V_25 ) ;
if ( V_115 & V_197 ) {
F_151 ( V_25 , V_28 , 0 ) ;
F_142 ( V_25 , V_28 ) ;
}
F_78 ( V_25 , V_28 ) ;
F_149 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_46 ( V_25 , V_28 ) ;
V_28 -> V_76 = 1 ;
if ( V_25 -> V_72 == 1 ) {
F_26 ( V_25 ) ;
F_154 ( V_25 ) ;
}
}
static void F_155 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_59 == V_28 )
V_25 -> V_59 = NULL ;
else
break;
}
}
static void F_156 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
V_25 -> V_58 = NULL ;
else
break;
}
}
static void F_157 ( struct V_27 * V_28 )
{
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_25 -> V_199 == V_28 )
V_25 -> V_199 = NULL ;
else
break;
}
}
static void F_158 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_25 -> V_59 == V_28 )
F_155 ( V_28 ) ;
if ( V_25 -> V_58 == V_28 )
F_156 ( V_28 ) ;
if ( V_25 -> V_199 == V_28 )
F_157 ( V_28 ) ;
}
static void
F_159 ( struct V_25 * V_25 , struct V_27 * V_28 , int V_115 )
{
F_70 ( V_25 ) ;
F_139 ( V_25 , V_28 , V_115 & V_200 ) ;
F_82 ( V_25 , V_28 ) ;
if ( V_115 & V_200 ) {
#ifdef F_80
if ( F_21 ( V_28 ) ) {
struct V_26 * V_180 = F_18 ( V_28 ) ;
if ( V_180 -> V_201 & V_202 )
V_28 -> V_82 . V_181 = F_77 ( F_17 ( V_25 ) ) ;
if ( V_180 -> V_201 & V_203 )
V_28 -> V_82 . V_184 = F_77 ( F_17 ( V_25 ) ) ;
}
#endif
}
F_158 ( V_25 , V_28 ) ;
if ( V_28 != V_25 -> V_45 )
F_49 ( V_25 , V_28 ) ;
V_28 -> V_76 = 0 ;
F_110 ( V_25 , V_28 ) ;
if ( ! ( V_115 & V_200 ) )
V_28 -> V_41 -= V_25 -> F_40 ;
F_160 ( V_25 ) ;
F_42 ( V_25 ) ;
F_116 ( V_25 ) ;
}
static void
F_161 ( struct V_25 * V_25 , struct V_27 * V_45 )
{
unsigned long V_204 , V_17 ;
struct V_27 * V_28 ;
T_3 V_42 ;
V_204 = F_62 ( V_25 , V_45 ) ;
V_17 = V_45 -> V_84 - V_45 -> V_205 ;
if ( V_17 > V_204 ) {
F_162 ( F_17 ( V_25 ) -> V_45 ) ;
F_158 ( V_25 , V_45 ) ;
return;
}
if ( V_17 < V_69 )
return;
V_28 = F_52 ( V_25 ) ;
V_42 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_42 < 0 )
return;
if ( V_42 > V_204 )
F_162 ( F_17 ( V_25 ) -> V_45 ) ;
}
static void
F_163 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
if ( V_28 -> V_76 ) {
F_79 ( V_25 , V_28 ) ;
F_49 ( V_25 , V_28 ) ;
}
F_83 ( V_25 , V_28 ) ;
V_25 -> V_45 = V_28 ;
#ifdef F_80
if ( F_17 ( V_25 ) -> V_70 . V_4 >= 2 * V_28 -> V_70 . V_4 ) {
V_28 -> V_82 . V_206 = F_68 ( V_28 -> V_82 . V_206 ,
V_28 -> V_84 - V_28 -> V_205 ) ;
}
#endif
V_28 -> V_205 = V_28 -> V_84 ;
}
static struct V_27 * F_164 ( struct V_25 * V_25 )
{
struct V_27 * V_28 = F_52 ( V_25 ) ;
struct V_27 * V_57 = V_28 ;
if ( V_25 -> V_199 == V_28 ) {
struct V_27 * V_207 = F_53 ( V_28 ) ;
if ( V_207 && F_165 ( V_207 , V_57 ) < 1 )
V_28 = V_207 ;
}
if ( V_25 -> V_59 && F_165 ( V_25 -> V_59 , V_57 ) < 1 )
V_28 = V_25 -> V_59 ;
if ( V_25 -> V_58 && F_165 ( V_25 -> V_58 , V_57 ) < 1 )
V_28 = V_25 -> V_58 ;
F_158 ( V_25 , V_28 ) ;
return V_28 ;
}
static void F_166 ( struct V_25 * V_25 , struct V_27 * V_208 )
{
if ( V_208 -> V_76 )
F_70 ( V_25 ) ;
F_167 ( V_25 ) ;
F_149 ( V_25 , V_208 ) ;
if ( V_208 -> V_76 ) {
F_76 ( V_25 , V_208 ) ;
F_46 ( V_25 , V_208 ) ;
F_133 ( V_208 , 1 ) ;
}
V_25 -> V_45 = NULL ;
}
static void
F_168 ( struct V_25 * V_25 , struct V_27 * V_45 , int V_209 )
{
F_70 ( V_25 ) ;
F_133 ( V_45 , 1 ) ;
F_30 ( V_25 , 1 ) ;
F_116 ( V_25 ) ;
#ifdef F_169
if ( V_209 ) {
F_162 ( F_17 ( V_25 ) -> V_45 ) ;
return;
}
if ( ! F_152 ( V_210 ) &&
F_170 ( & F_17 ( V_25 ) -> V_211 ) )
return;
#endif
if ( V_25 -> V_72 > 1 )
F_161 ( V_25 , V_45 ) ;
}
static inline bool F_171 ( void )
{
return F_172 ( & V_212 ) ;
}
void F_173 ( int V_213 , int V_214 )
{
if ( V_213 && ! V_214 )
F_174 ( & V_212 ) ;
else if ( ! V_213 && V_214 )
F_175 ( & V_212 ) ;
}
static bool F_171 ( void )
{
return true ;
}
void F_173 ( int V_213 , int V_214 ) {}
static inline T_2 F_176 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_177 ( void )
{
return ( T_2 ) V_215 * V_216 ;
}
void F_178 ( struct V_217 * V_218 )
{
T_2 V_86 ;
if ( V_218 -> V_219 == V_220 )
return;
V_86 = F_179 ( F_180 () ) ;
V_218 -> V_221 = V_218 -> V_219 ;
V_218 -> V_222 = V_86 + F_181 ( V_218 -> V_73 ) ;
}
static inline struct V_217 * F_182 ( struct V_138 * V_33 )
{
return & V_33 -> V_217 ;
}
static inline T_2 F_134 ( struct V_25 * V_25 )
{
if ( F_14 ( V_25 -> V_223 ) )
return V_25 -> V_224 ;
return F_71 ( F_17 ( V_25 ) ) - V_25 -> V_225 ;
}
static int F_183 ( struct V_25 * V_25 )
{
struct V_138 * V_33 = V_25 -> V_33 ;
struct V_217 * V_218 = F_182 ( V_33 ) ;
T_2 V_226 = 0 , V_227 , V_228 ;
V_227 = F_177 () - V_25 -> V_229 ;
F_184 ( & V_218 -> V_230 ) ;
if ( V_218 -> V_219 == V_220 )
V_226 = V_227 ;
else {
if ( ! V_218 -> V_231 ) {
F_178 ( V_218 ) ;
F_185 ( V_218 ) ;
}
if ( V_218 -> V_221 > 0 ) {
V_226 = F_16 ( V_218 -> V_221 , V_227 ) ;
V_218 -> V_221 -= V_226 ;
V_218 -> V_232 = 0 ;
}
}
V_228 = V_218 -> V_222 ;
F_186 ( & V_218 -> V_230 ) ;
V_25 -> V_229 += V_226 ;
if ( ( T_3 ) ( V_228 - V_25 -> V_222 ) > 0 )
V_25 -> V_222 = V_228 ;
return V_25 -> V_229 > 0 ;
}
static void F_187 ( struct V_25 * V_25 )
{
struct V_217 * V_218 = F_182 ( V_25 -> V_33 ) ;
if ( F_12 ( ( T_3 ) ( F_77 ( F_17 ( V_25 ) ) - V_25 -> V_222 ) < 0 ) )
return;
if ( V_25 -> V_229 < 0 )
return;
if ( ( T_3 ) ( V_25 -> V_222 - V_218 -> V_222 ) >= 0 ) {
V_25 -> V_222 += V_233 ;
} else {
V_25 -> V_229 = 0 ;
}
}
static void F_188 ( struct V_25 * V_25 ,
unsigned long V_17 )
{
V_25 -> V_229 -= V_17 ;
F_187 ( V_25 ) ;
if ( F_12 ( V_25 -> V_229 > 0 ) )
return;
if ( ! F_183 ( V_25 ) && F_12 ( V_25 -> V_45 ) )
F_162 ( F_17 ( V_25 ) -> V_45 ) ;
}
static T_8
void F_75 ( struct V_25 * V_25 , unsigned long V_17 )
{
if ( ! F_171 () || ! V_25 -> V_234 )
return;
F_188 ( V_25 , V_17 ) ;
}
static inline int F_189 ( struct V_25 * V_25 )
{
return F_171 () && V_25 -> V_235 ;
}
static inline int F_117 ( struct V_25 * V_25 )
{
return F_171 () && V_25 -> V_223 ;
}
static inline int F_190 ( struct V_138 * V_33 ,
int V_236 , int V_237 )
{
struct V_25 * V_238 , * V_239 ;
V_238 = V_33 -> V_25 [ V_236 ] ;
V_239 = V_33 -> V_25 [ V_237 ] ;
return F_117 ( V_238 ) ||
F_117 ( V_239 ) ;
}
static int F_191 ( struct V_138 * V_33 , void * V_240 )
{
struct V_24 * V_24 = V_240 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
V_25 -> V_223 -- ;
#ifdef F_108
if ( ! V_25 -> V_223 ) {
V_25 -> V_225 += F_71 ( V_24 ) -
V_25 -> V_224 ;
}
#endif
return 0 ;
}
static int F_192 ( struct V_138 * V_33 , void * V_240 )
{
struct V_24 * V_24 = V_240 ;
struct V_25 * V_25 = V_33 -> V_25 [ F_27 ( V_24 ) ] ;
if ( ! V_25 -> V_223 )
V_25 -> V_224 = F_71 ( V_24 ) ;
V_25 -> V_223 ++ ;
return 0 ;
}
static void F_193 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_217 * V_218 = F_182 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
long V_241 , V_242 = 1 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( F_17 ( V_25 ) ) ] ;
F_194 () ;
F_195 ( V_25 -> V_33 , F_192 , V_243 , ( void * ) V_24 ) ;
F_196 () ;
V_241 = V_25 -> V_244 ;
F_36 (se) {
struct V_25 * V_245 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 )
break;
if ( V_242 )
F_159 ( V_245 , V_28 , V_200 ) ;
V_245 -> V_244 -= V_241 ;
if ( V_245 -> V_70 . V_4 )
V_242 = 0 ;
}
if ( ! V_28 )
V_24 -> V_72 -= V_241 ;
V_25 -> V_235 = 1 ;
V_25 -> V_246 = F_77 ( V_24 ) ;
F_184 ( & V_218 -> V_230 ) ;
F_29 ( & V_25 -> V_247 , & V_218 -> V_248 ) ;
F_186 ( & V_218 -> V_230 ) ;
}
void F_197 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_217 * V_218 = F_182 ( V_25 -> V_33 ) ;
struct V_27 * V_28 ;
int V_249 = 1 ;
long V_241 ;
V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
V_25 -> V_235 = 0 ;
F_198 ( V_24 ) ;
F_184 ( & V_218 -> V_230 ) ;
V_218 -> V_250 += F_77 ( V_24 ) - V_25 -> V_246 ;
F_32 ( & V_25 -> V_247 ) ;
F_186 ( & V_218 -> V_230 ) ;
F_195 ( V_25 -> V_33 , V_243 , F_191 , ( void * ) V_24 ) ;
if ( ! V_25 -> V_70 . V_4 )
return;
V_241 = V_25 -> V_244 ;
F_36 (se) {
if ( V_28 -> V_76 )
V_249 = 0 ;
V_25 = F_24 ( V_28 ) ;
if ( V_249 )
F_153 ( V_25 , V_28 , V_197 ) ;
V_25 -> V_244 += V_241 ;
if ( F_189 ( V_25 ) )
break;
}
if ( ! V_28 )
V_24 -> V_72 += V_241 ;
if ( V_24 -> V_45 == V_24 -> V_232 && V_24 -> V_40 . V_72 )
F_162 ( V_24 -> V_45 ) ;
}
static T_2 F_199 ( struct V_217 * V_218 ,
T_2 V_251 , T_2 V_228 )
{
struct V_25 * V_25 ;
T_2 V_221 = V_251 ;
F_194 () ;
F_200 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_184 ( & V_24 -> V_230 ) ;
if ( ! F_189 ( V_25 ) )
goto V_58;
V_221 = - V_25 -> V_229 + 1 ;
if ( V_221 > V_251 )
V_221 = V_251 ;
V_251 -= V_221 ;
V_25 -> V_229 += V_221 ;
V_25 -> V_222 = V_228 ;
if ( V_25 -> V_229 > 0 )
F_197 ( V_25 ) ;
V_58:
F_186 ( & V_24 -> V_230 ) ;
if ( ! V_251 )
break;
}
F_196 () ;
return V_251 ;
}
static int F_201 ( struct V_217 * V_218 , int V_252 )
{
T_2 V_221 , V_222 ;
int V_232 = 1 , V_235 ;
F_184 ( & V_218 -> V_230 ) ;
if ( V_218 -> V_219 == V_220 )
goto V_253;
V_235 = ! F_202 ( & V_218 -> V_248 ) ;
V_232 = V_218 -> V_232 && ! V_235 ;
V_218 -> V_254 += V_252 ;
if ( V_232 )
goto V_253;
F_178 ( V_218 ) ;
if ( ! V_235 ) {
V_218 -> V_232 = 1 ;
goto V_253;
}
V_218 -> V_255 += V_252 ;
V_221 = V_218 -> V_221 ;
V_222 = V_218 -> V_222 ;
V_218 -> V_221 = 0 ;
while ( V_235 && V_221 > 0 ) {
F_186 ( & V_218 -> V_230 ) ;
V_221 = F_199 ( V_218 , V_221 ,
V_222 ) ;
F_184 ( & V_218 -> V_230 ) ;
V_235 = ! F_202 ( & V_218 -> V_248 ) ;
}
V_218 -> V_221 = V_221 ;
V_218 -> V_232 = 0 ;
V_253:
if ( V_232 )
V_218 -> V_231 = 0 ;
F_186 ( & V_218 -> V_230 ) ;
return V_232 ;
}
static int F_203 ( struct V_217 * V_218 , T_2 V_256 )
{
struct V_257 * V_258 = & V_218 -> V_259 ;
T_2 V_251 ;
if ( F_204 ( V_258 ) )
return 1 ;
V_251 = F_181 ( F_205 ( V_258 ) ) ;
if ( V_251 < V_256 )
return 1 ;
return 0 ;
}
static void F_206 ( struct V_217 * V_218 )
{
T_2 V_260 = V_261 + V_262 ;
if ( F_203 ( V_218 , V_260 ) )
return;
F_207 ( & V_218 -> V_263 ,
F_208 ( V_261 ) ) ;
}
static void F_209 ( struct V_25 * V_25 )
{
struct V_217 * V_218 = F_182 ( V_25 -> V_33 ) ;
T_3 V_264 = V_25 -> V_229 - V_265 ;
if ( V_264 <= 0 )
return;
F_184 ( & V_218 -> V_230 ) ;
if ( V_218 -> V_219 != V_220 &&
V_25 -> V_222 == V_218 -> V_222 ) {
V_218 -> V_221 += V_264 ;
if ( V_218 -> V_221 > F_177 () &&
! F_202 ( & V_218 -> V_248 ) )
F_206 ( V_218 ) ;
}
F_186 ( & V_218 -> V_230 ) ;
V_25 -> V_229 -= V_264 ;
}
static T_8 void F_160 ( struct V_25 * V_25 )
{
if ( ! F_171 () )
return;
if ( ! V_25 -> V_234 || V_25 -> V_72 )
return;
F_209 ( V_25 ) ;
}
static void F_210 ( struct V_217 * V_218 )
{
T_2 V_221 = 0 , V_75 = F_177 () ;
T_2 V_228 ;
if ( F_203 ( V_218 , V_262 ) )
return;
F_184 ( & V_218 -> V_230 ) ;
if ( V_218 -> V_219 != V_220 && V_218 -> V_221 > V_75 ) {
V_221 = V_218 -> V_221 ;
V_218 -> V_221 = 0 ;
}
V_228 = V_218 -> V_222 ;
F_186 ( & V_218 -> V_230 ) ;
if ( ! V_221 )
return;
V_221 = F_199 ( V_218 , V_221 , V_228 ) ;
F_184 ( & V_218 -> V_230 ) ;
if ( V_228 == V_218 -> V_222 )
V_218 -> V_221 = V_221 ;
F_186 ( & V_218 -> V_230 ) ;
}
static void F_154 ( struct V_25 * V_25 )
{
if ( ! F_171 () )
return;
if ( ! V_25 -> V_234 || V_25 -> V_45 )
return;
if ( F_189 ( V_25 ) )
return;
F_75 ( V_25 , 0 ) ;
if ( V_25 -> V_229 <= 0 )
F_193 ( V_25 ) ;
}
static void F_167 ( struct V_25 * V_25 )
{
if ( ! F_171 () )
return;
if ( F_12 ( ! V_25 -> V_234 || V_25 -> V_229 > 0 ) )
return;
if ( F_189 ( V_25 ) )
return;
F_193 ( V_25 ) ;
}
static enum V_266 F_211 ( struct V_257 * V_267 )
{
struct V_217 * V_218 =
F_22 ( V_267 , struct V_217 , V_263 ) ;
F_210 ( V_218 ) ;
return V_268 ;
}
static enum V_266 F_212 ( struct V_257 * V_267 )
{
struct V_217 * V_218 =
F_22 ( V_267 , struct V_217 , V_259 ) ;
T_9 V_86 ;
int V_252 ;
int V_232 = 0 ;
for (; ; ) {
V_86 = F_213 ( V_267 ) ;
V_252 = F_214 ( V_267 , V_86 , V_218 -> V_73 ) ;
if ( ! V_252 )
break;
V_232 = F_201 ( V_218 , V_252 ) ;
}
return V_232 ? V_268 : V_269 ;
}
void F_215 ( struct V_217 * V_218 )
{
F_216 ( & V_218 -> V_230 ) ;
V_218 -> V_221 = 0 ;
V_218 -> V_219 = V_220 ;
V_218 -> V_73 = F_208 ( F_176 () ) ;
F_217 ( & V_218 -> V_248 ) ;
F_218 ( & V_218 -> V_259 , V_270 , V_271 ) ;
V_218 -> V_259 . V_272 = F_212 ;
F_218 ( & V_218 -> V_263 , V_270 , V_271 ) ;
V_218 -> V_263 . V_272 = F_211 ;
}
static void F_219 ( struct V_25 * V_25 )
{
V_25 -> V_234 = 0 ;
F_217 ( & V_25 -> V_247 ) ;
}
void F_185 ( struct V_217 * V_218 )
{
while ( F_14 ( F_170 ( & V_218 -> V_259 ) ) ) {
F_186 ( & V_218 -> V_230 ) ;
F_220 ( & V_218 -> V_259 ) ;
F_184 ( & V_218 -> V_230 ) ;
if ( V_218 -> V_231 )
return;
}
V_218 -> V_231 = 1 ;
F_207 ( & V_218 -> V_259 , V_218 -> V_73 ) ;
}
static void F_221 ( struct V_217 * V_218 )
{
F_220 ( & V_218 -> V_259 ) ;
F_220 ( & V_218 -> V_263 ) ;
}
static void T_10 F_222 ( struct V_24 * V_24 )
{
struct V_25 * V_25 ;
F_223 (rq, cfs_rq) {
struct V_217 * V_218 = F_182 ( V_25 -> V_33 ) ;
if ( ! V_25 -> V_234 )
continue;
V_25 -> V_229 = V_218 -> V_219 ;
if ( F_189 ( V_25 ) )
F_197 ( V_25 ) ;
}
}
static inline T_2 F_134 ( struct V_25 * V_25 )
{
return F_71 ( F_17 ( V_25 ) ) ;
}
static void F_75 ( struct V_25 * V_25 ,
unsigned long V_17 ) {}
static void F_167 ( struct V_25 * V_25 ) {}
static void F_154 ( struct V_25 * V_25 ) {}
static T_8 void F_160 ( struct V_25 * V_25 ) {}
static inline int F_189 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_117 ( struct V_25 * V_25 )
{
return 0 ;
}
static inline int F_190 ( struct V_138 * V_33 ,
int V_236 , int V_237 )
{
return 0 ;
}
void F_215 ( struct V_217 * V_218 ) {}
static void F_219 ( struct V_25 * V_25 ) {}
static inline struct V_217 * F_182 ( struct V_138 * V_33 )
{
return NULL ;
}
static inline void F_221 ( struct V_217 * V_218 ) {}
static inline void F_222 ( struct V_24 * V_24 ) {}
static void F_224 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_225 ( F_38 ( V_29 ) != V_24 ) ;
if ( V_25 -> V_72 > 1 ) {
T_2 V_75 = F_62 ( V_25 , V_28 ) ;
T_2 V_273 = V_28 -> V_84 - V_28 -> V_205 ;
T_3 V_42 = V_75 - V_273 ;
if ( V_42 < 0 ) {
if ( V_24 -> V_45 == V_29 )
F_162 ( V_29 ) ;
return;
}
if ( V_24 -> V_45 != V_29 )
V_42 = F_226 ( T_3 , 10000LL , V_42 ) ;
F_227 ( V_24 , V_42 ) ;
}
}
static void F_228 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
if ( ! F_229 ( V_24 ) || V_45 -> V_274 != & V_275 )
return;
if ( F_24 ( & V_45 -> V_28 ) -> V_72 < V_67 )
F_224 ( V_24 , V_45 ) ;
}
static inline void
F_224 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
}
static inline void F_228 ( struct V_24 * V_24 )
{
}
static void
F_230 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_115 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
F_36 (se) {
if ( V_28 -> V_76 )
break;
V_25 = F_24 ( V_28 ) ;
F_153 ( V_25 , V_28 , V_115 ) ;
if ( F_189 ( V_25 ) )
break;
V_25 -> V_244 ++ ;
V_115 = V_197 ;
}
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_244 ++ ;
if ( F_189 ( V_25 ) )
break;
F_116 ( V_25 ) ;
F_133 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_137 ( V_24 , V_24 -> V_72 ) ;
F_231 ( V_24 ) ;
}
F_228 ( V_24 ) ;
}
static void F_232 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_115 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 ;
int V_276 = V_115 & V_200 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_159 ( V_25 , V_28 , V_115 ) ;
if ( F_189 ( V_25 ) )
break;
V_25 -> V_244 -- ;
if ( V_25 -> V_70 . V_4 ) {
if ( V_276 && F_34 ( V_28 ) )
F_233 ( F_34 ( V_28 ) ) ;
V_28 = F_34 ( V_28 ) ;
break;
}
V_115 |= V_200 ;
}
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_244 -- ;
if ( F_189 ( V_25 ) )
break;
F_116 ( V_25 ) ;
F_133 ( V_28 , 1 ) ;
}
if ( ! V_28 ) {
F_234 ( V_24 ) ;
F_137 ( V_24 , 1 ) ;
}
F_228 ( V_24 ) ;
}
static unsigned long F_235 ( const int V_277 )
{
return F_236 ( V_277 ) -> V_40 . V_166 ;
}
static unsigned long F_237 ( int V_277 , int type )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_278 = F_235 ( V_277 ) ;
if ( type == 0 || ! F_152 ( V_279 ) )
return V_278 ;
return F_16 ( V_24 -> V_280 [ type - 1 ] , V_278 ) ;
}
static unsigned long F_238 ( int V_277 , int type )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_278 = F_235 ( V_277 ) ;
if ( type == 0 || ! F_152 ( V_279 ) )
return V_278 ;
return F_68 ( V_24 -> V_280 [ type - 1 ] , V_278 ) ;
}
static unsigned long F_239 ( int V_277 )
{
return F_236 ( V_277 ) -> V_281 ;
}
static unsigned long F_240 ( int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_72 = F_85 ( V_24 -> V_72 ) ;
unsigned long V_140 = V_24 -> V_40 . V_166 ;
if ( V_72 )
return V_140 / V_72 ;
return 0 ;
}
static void F_241 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_40 ;
#ifndef F_44
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_242 () ;
F_40 = V_25 -> F_40 ;
} while ( F_40 != V_48 );
#else
F_40 = V_25 -> F_40 ;
#endif
V_28 -> V_41 -= F_40 ;
}
static long F_243 ( struct V_138 * V_33 , int V_277 , long V_282 , long V_283 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_277 ] ;
if ( ! V_33 -> V_34 )
return V_282 ;
F_36 (se) {
long V_7 , V_284 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_284 = V_283 + F_112 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_282 ;
if ( V_284 > 0 && V_7 < V_284 )
V_282 = ( V_7 * V_33 -> V_142 ) / V_284 ;
else
V_282 = V_33 -> V_142 ;
if ( V_282 < V_143 )
V_282 = V_143 ;
V_282 -= V_28 -> V_70 . V_4 ;
V_283 = 0 ;
}
return V_282 ;
}
static inline unsigned long F_243 ( struct V_138 * V_33 , int V_277 ,
unsigned long V_282 , unsigned long V_283 )
{
return V_282 ;
}
static int F_244 ( struct V_285 * V_286 , struct V_26 * V_29 , int V_287 )
{
T_3 V_288 , V_70 ;
int V_289 , V_290 , V_291 ;
unsigned long V_292 ;
struct V_138 * V_33 ;
unsigned long V_4 ;
int V_293 ;
V_289 = V_286 -> V_294 ;
V_290 = F_180 () ;
V_291 = F_245 ( V_29 ) ;
V_70 = F_237 ( V_291 , V_289 ) ;
V_288 = F_238 ( V_290 , V_289 ) ;
if ( V_287 ) {
V_33 = V_138 ( V_99 ) ;
V_4 = V_99 -> V_28 . V_70 . V_4 ;
V_288 += F_243 ( V_33 , V_290 , - V_4 , - V_4 ) ;
V_70 += F_243 ( V_33 , V_291 , 0 , - V_4 ) ;
}
V_33 = V_138 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_288 > 0 ) {
T_3 V_295 , V_296 ;
V_295 = 100 ;
V_295 *= F_239 ( V_291 ) ;
V_295 *= V_288 +
F_243 ( V_33 , V_290 , V_4 , V_4 ) ;
V_296 = 100 + ( V_286 -> V_297 - 100 ) / 2 ;
V_296 *= F_239 ( V_290 ) ;
V_296 *= V_70 + F_243 ( V_33 , V_291 , 0 , V_4 ) ;
V_293 = V_295 <= V_296 ;
} else
V_293 = true ;
if ( V_287 && V_293 )
return 1 ;
F_150 ( V_29 , V_28 . V_82 . V_298 ) ;
V_292 = F_240 ( V_290 ) ;
if ( V_293 ||
( V_288 <= V_70 &&
V_288 + F_238 ( V_291 , V_289 ) <= V_292 ) ) {
F_150 ( V_286 , V_299 ) ;
F_150 ( V_29 , V_28 . V_82 . V_300 ) ;
return 1 ;
}
return 0 ;
}
static struct V_301 *
F_246 ( struct V_285 * V_286 , struct V_26 * V_29 ,
int V_290 , int V_302 )
{
struct V_301 * V_303 = NULL , * V_304 = V_286 -> V_305 ;
unsigned long V_306 = V_307 , V_288 = 0 ;
int V_308 = 100 + ( V_286 -> V_297 - 100 ) / 2 ;
do {
unsigned long V_70 , V_309 ;
int V_310 ;
int V_311 ;
if ( ! F_247 ( F_248 ( V_304 ) ,
F_249 ( V_29 ) ) )
continue;
V_310 = F_250 ( V_290 ,
F_248 ( V_304 ) ) ;
V_309 = 0 ;
F_251 (i, sched_group_cpus(group)) {
if ( V_310 )
V_70 = F_237 ( V_311 , V_302 ) ;
else
V_70 = F_238 ( V_311 , V_302 ) ;
V_309 += V_70 ;
}
V_309 = ( V_309 * V_312 ) / V_304 -> V_313 -> V_314 ;
if ( V_310 ) {
V_288 = V_309 ;
} else if ( V_309 < V_306 ) {
V_306 = V_309 ;
V_303 = V_304 ;
}
} while ( V_304 = V_304 -> V_58 , V_304 != V_286 -> V_305 );
if ( ! V_303 || 100 * V_288 < V_308 * V_306 )
return NULL ;
return V_303 ;
}
static int
F_252 ( struct V_301 * V_304 , struct V_26 * V_29 , int V_290 )
{
unsigned long V_70 , V_306 = V_307 ;
int V_303 = - 1 ;
int V_311 ;
F_253 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_235 ( V_311 ) ;
if ( V_70 < V_306 || ( V_70 == V_306 && V_311 == V_290 ) ) {
V_306 = V_70 ;
V_303 = V_311 ;
}
}
return V_303 ;
}
static int F_254 ( struct V_26 * V_29 , int V_315 )
{
struct V_285 * V_286 ;
struct V_301 * V_316 ;
int V_311 = F_245 ( V_29 ) ;
if ( F_255 ( V_315 ) )
return V_315 ;
if ( V_311 != V_315 && F_256 ( V_311 , V_315 ) && F_255 ( V_311 ) )
return V_311 ;
V_286 = F_257 ( F_258 ( V_317 , V_315 ) ) ;
F_259 (sd) {
V_316 = V_286 -> V_305 ;
do {
if ( ! F_247 ( F_248 ( V_316 ) ,
F_249 ( V_29 ) ) )
goto V_58;
F_251 (i, sched_group_cpus(sg)) {
if ( V_311 == V_315 || ! F_255 ( V_311 ) )
goto V_58;
}
V_315 = F_260 ( F_248 ( V_316 ) ,
F_249 ( V_29 ) ) ;
goto V_318;
V_58:
V_316 = V_316 -> V_58 ;
} while ( V_316 != V_286 -> V_305 );
}
V_318:
return V_315 ;
}
static int
F_261 ( struct V_26 * V_29 , int V_319 , int V_320 )
{
struct V_285 * V_18 , * V_321 = NULL , * V_286 = NULL ;
int V_277 = F_180 () ;
int V_291 = F_245 ( V_29 ) ;
int V_322 = V_277 ;
int V_323 = 0 ;
int V_287 = V_320 & V_324 ;
if ( V_29 -> V_325 == 1 )
return V_291 ;
if ( V_319 & V_326 ) {
if ( F_250 ( V_277 , F_249 ( V_29 ) ) )
V_323 = 1 ;
V_322 = V_291 ;
}
F_194 () ;
F_262 (cpu, tmp) {
if ( ! ( V_18 -> V_115 & V_327 ) )
continue;
if ( V_323 && ( V_18 -> V_115 & V_328 ) &&
F_250 ( V_291 , F_263 ( V_18 ) ) ) {
V_321 = V_18 ;
break;
}
if ( V_18 -> V_115 & V_319 )
V_286 = V_18 ;
}
if ( V_321 ) {
if ( V_277 != V_291 && F_244 ( V_321 , V_29 , V_287 ) )
V_291 = V_277 ;
V_322 = F_254 ( V_29 , V_291 ) ;
goto V_329;
}
while ( V_286 ) {
int V_302 = V_286 -> V_330 ;
struct V_301 * V_304 ;
int V_4 ;
if ( ! ( V_286 -> V_115 & V_319 ) ) {
V_286 = V_286 -> V_331 ;
continue;
}
if ( V_319 & V_326 )
V_302 = V_286 -> V_294 ;
V_304 = F_246 ( V_286 , V_29 , V_277 , V_302 ) ;
if ( ! V_304 ) {
V_286 = V_286 -> V_331 ;
continue;
}
V_322 = F_252 ( V_304 , V_29 , V_277 ) ;
if ( V_322 == - 1 || V_322 == V_277 ) {
V_286 = V_286 -> V_331 ;
continue;
}
V_277 = V_322 ;
V_4 = V_286 -> V_332 ;
V_286 = NULL ;
F_262 (cpu, tmp) {
if ( V_4 <= V_18 -> V_332 )
break;
if ( V_18 -> V_115 & V_319 )
V_286 = V_18 ;
}
}
V_329:
F_196 () ;
return V_322 ;
}
static void
F_264 ( struct V_26 * V_29 , int V_333 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( V_28 -> V_77 . V_78 ) {
V_28 -> V_77 . V_78 = - F_121 ( V_28 ) ;
F_124 ( V_28 -> V_77 . V_163 ,
& V_25 -> V_176 ) ;
}
}
static unsigned long
F_265 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_334 = V_335 ;
return F_60 ( V_334 , V_28 ) ;
}
static int
F_165 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_334 , V_336 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_336 <= 0 )
return - 1 ;
V_334 = F_265 ( V_45 , V_28 ) ;
if ( V_336 > V_334 )
return 1 ;
return 0 ;
}
static void F_266 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_337 == V_338 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_233 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_337 == V_338 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_267 ( struct V_27 * V_28 )
{
F_36 (se)
F_24 ( V_28 ) -> V_199 = V_28 ;
}
static void F_268 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_320 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_339 = V_25 -> V_72 >= V_67 ;
int V_340 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_117 ( F_24 ( V_36 ) ) ) )
return;
if ( F_152 ( V_341 ) && V_339 && ! ( V_320 & V_342 ) ) {
F_233 ( V_36 ) ;
V_340 = 1 ;
}
if ( F_269 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_337 == V_338 ) &&
F_12 ( V_29 -> V_337 != V_338 ) )
goto V_343;
if ( F_14 ( V_29 -> V_337 != V_344 ) || ! F_152 ( V_345 ) )
return;
F_37 ( & V_28 , & V_36 ) ;
F_70 ( F_24 ( V_28 ) ) ;
F_270 ( ! V_36 ) ;
if ( F_165 ( V_28 , V_36 ) == 1 ) {
if ( ! V_340 )
F_233 ( V_36 ) ;
goto V_343;
}
return;
V_343:
F_162 ( V_45 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_232 ) )
return;
if ( F_152 ( V_346 ) && V_339 && F_21 ( V_28 ) )
F_266 ( V_28 ) ;
}
static struct V_26 * F_271 ( struct V_24 * V_24 )
{
struct V_26 * V_29 ;
struct V_25 * V_25 = & V_24 -> V_40 ;
struct V_27 * V_28 ;
if ( ! V_25 -> V_72 )
return NULL ;
do {
V_28 = F_164 ( V_25 ) ;
F_163 ( V_25 , V_28 ) ;
V_25 = F_25 ( V_28 ) ;
} while ( V_25 );
V_29 = F_18 ( V_28 ) ;
if ( F_229 ( V_24 ) )
F_224 ( V_24 , V_29 ) ;
return V_29 ;
}
static void F_272 ( struct V_24 * V_24 , struct V_26 * V_208 )
{
struct V_27 * V_28 = & V_208 -> V_28 ;
struct V_25 * V_25 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_166 ( V_25 , V_28 ) ;
}
}
static void F_273 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_158 ( V_25 , V_28 ) ;
if ( V_45 -> V_337 != V_347 ) {
F_198 ( V_24 ) ;
F_70 ( V_25 ) ;
V_24 -> V_348 = 1 ;
}
F_267 ( V_28 ) ;
}
static bool F_274 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_343 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_117 ( F_24 ( V_28 ) ) )
return false ;
F_233 ( V_28 ) ;
F_273 ( V_24 ) ;
return true ;
}
static void F_275 ( struct V_26 * V_29 , struct V_349 * V_350 )
{
F_276 ( V_350 -> V_351 , V_29 , 0 ) ;
F_277 ( V_29 , V_350 -> V_352 ) ;
F_278 ( V_350 -> V_353 , V_29 , 0 ) ;
F_279 ( V_350 -> V_353 , V_29 , 0 ) ;
}
static int
F_280 ( struct V_26 * V_29 , T_2 V_86 , struct V_285 * V_286 )
{
T_3 V_42 ;
if ( V_29 -> V_274 != & V_275 )
return 0 ;
if ( F_14 ( V_29 -> V_337 == V_338 ) )
return 0 ;
if ( F_152 ( V_354 ) && V_179 () -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_355 == - 1 )
return 1 ;
if ( V_355 == 0 )
return 0 ;
V_42 = V_86 - V_29 -> V_28 . V_87 ;
return V_42 < ( T_3 ) V_355 ;
}
static
int F_281 ( struct V_26 * V_29 , struct V_349 * V_350 )
{
int V_356 = 0 ;
if ( F_190 ( V_138 ( V_29 ) , V_350 -> V_236 , V_350 -> V_352 ) )
return 0 ;
if ( ! F_250 ( V_350 -> V_352 , F_249 ( V_29 ) ) ) {
int V_277 ;
F_150 ( V_29 , V_28 . V_82 . V_357 ) ;
if ( ! V_350 -> V_358 || ( V_350 -> V_115 & V_359 ) )
return 0 ;
F_253 (cpu, env->dst_grpmask, env->cpus) {
if ( F_250 ( V_277 , F_249 ( V_29 ) ) ) {
V_350 -> V_115 |= V_359 ;
V_350 -> V_360 = V_277 ;
break;
}
}
return 0 ;
}
V_350 -> V_115 &= ~ V_361 ;
if ( F_282 ( V_350 -> V_351 , V_29 ) ) {
F_150 ( V_29 , V_28 . V_82 . V_362 ) ;
return 0 ;
}
V_356 = F_280 ( V_29 , F_71 ( V_350 -> V_351 ) , V_350 -> V_286 ) ;
if ( ! V_356 ||
V_350 -> V_286 -> V_363 > V_350 -> V_286 -> V_364 ) {
if ( V_356 ) {
F_150 ( V_350 -> V_286 , V_365 [ V_350 -> V_232 ] ) ;
F_150 ( V_29 , V_28 . V_82 . V_366 ) ;
}
return 1 ;
}
F_150 ( V_29 , V_28 . V_82 . V_367 ) ;
return 0 ;
}
static int F_283 ( struct V_349 * V_350 )
{
struct V_26 * V_29 , * V_145 ;
F_284 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_281 ( V_29 , V_350 ) )
continue;
F_275 ( V_29 , V_350 ) ;
F_150 ( V_350 -> V_286 , V_368 [ V_350 -> V_232 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_285 ( struct V_349 * V_350 )
{
struct V_369 * V_370 = & V_350 -> V_351 -> V_137 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_371 = 0 ;
if ( V_350 -> V_308 <= 0 )
return 0 ;
while ( ! F_202 ( V_370 ) ) {
V_29 = F_286 ( V_370 , struct V_26 , V_28 . V_136 ) ;
V_350 -> V_372 ++ ;
if ( V_350 -> V_372 > V_350 -> V_373 )
break;
if ( V_350 -> V_372 > V_350 -> V_374 ) {
V_350 -> V_374 += V_375 ;
V_350 -> V_115 |= V_376 ;
break;
}
if ( ! F_281 ( V_29 , V_350 ) )
goto V_58;
V_70 = F_287 ( V_29 ) ;
if ( F_152 ( V_377 ) && V_70 < 16 && ! V_350 -> V_286 -> V_363 )
goto V_58;
if ( ( V_70 / 2 ) > V_350 -> V_308 )
goto V_58;
F_275 ( V_29 , V_350 ) ;
V_371 ++ ;
V_350 -> V_308 -= V_70 ;
#ifdef F_288
if ( V_350 -> V_232 == V_378 )
break;
#endif
if ( V_350 -> V_308 <= 0 )
break;
continue;
V_58:
F_289 ( & V_29 -> V_28 . V_136 , V_370 ) ;
}
F_69 ( V_350 -> V_286 , V_368 [ V_350 -> V_232 ] , V_371 ) ;
return V_371 ;
}
static void F_290 ( struct V_138 * V_33 , int V_277 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_277 ] ;
struct V_25 * V_25 = V_33 -> V_25 [ V_277 ] ;
if ( F_117 ( V_25 ) )
return;
F_30 ( V_25 , 1 ) ;
if ( V_28 ) {
F_133 ( V_28 , 1 ) ;
if ( ! V_28 -> V_77 . V_79 && ! V_25 -> V_72 )
F_31 ( V_25 ) ;
} else {
struct V_24 * V_24 = F_17 ( V_25 ) ;
F_137 ( V_24 , V_24 -> V_72 ) ;
}
}
static void F_291 ( int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
struct V_25 * V_25 ;
unsigned long V_115 ;
F_292 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
F_223 (rq, cfs_rq) {
F_290 ( V_25 -> V_33 , V_24 -> V_277 ) ;
}
F_293 ( & V_24 -> V_230 , V_115 ) ;
}
static int F_294 ( struct V_138 * V_33 , void * V_240 )
{
unsigned long V_70 ;
long V_277 = ( long ) V_240 ;
if ( ! V_33 -> V_34 ) {
V_70 = F_236 ( V_277 ) -> V_77 . V_163 ;
} else {
V_70 = V_33 -> V_34 -> V_25 [ V_277 ] -> V_379 ;
V_70 = F_295 ( V_70 * V_33 -> V_28 [ V_277 ] -> V_77 . V_163 ,
V_33 -> V_34 -> V_25 [ V_277 ] -> V_166 + 1 ) ;
}
V_33 -> V_25 [ V_277 ] -> V_379 = V_70 ;
return 0 ;
}
static void F_296 ( long V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_86 = V_108 ;
if ( V_24 -> V_380 == V_86 )
return;
V_24 -> V_380 = V_86 ;
F_194 () ;
F_297 ( F_294 , V_243 , ( void * ) V_277 ) ;
F_196 () ;
}
static unsigned long F_287 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
return F_295 ( V_29 -> V_28 . V_77 . V_163 * V_25 -> V_379 ,
V_25 -> V_166 + 1 ) ;
}
static inline void F_291 ( int V_277 )
{
}
static inline void F_296 ( long V_277 )
{
}
static unsigned long F_287 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_163 ;
}
static inline int F_298 ( struct V_285 * V_286 ,
enum V_381 V_232 )
{
int V_302 ;
switch ( V_232 ) {
case V_382 :
V_302 = V_286 -> V_383 ;
break;
case V_378 :
V_302 = V_286 -> V_384 ;
break;
default:
V_302 = V_286 -> V_385 ;
break;
}
return V_302 ;
}
static unsigned long F_299 ( struct V_285 * V_286 , int V_277 )
{
return V_312 ;
}
unsigned long __weak F_300 ( struct V_285 * V_286 , int V_277 )
{
return F_299 ( V_286 , V_277 ) ;
}
static unsigned long F_301 ( struct V_285 * V_286 , int V_277 )
{
unsigned long V_4 = V_286 -> V_332 ;
unsigned long V_386 = V_286 -> V_386 ;
V_386 /= V_4 ;
return V_386 ;
}
unsigned long __weak F_302 ( struct V_285 * V_286 , int V_277 )
{
return F_301 ( V_286 , V_277 ) ;
}
static unsigned long F_303 ( int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
T_2 V_278 , V_387 , V_388 , V_77 ;
V_388 = F_85 ( V_24 -> V_388 ) ;
V_77 = F_85 ( V_24 -> V_389 ) ;
V_278 = F_304 () + ( F_77 ( V_24 ) - V_388 ) ;
if ( F_14 ( V_278 < V_77 ) ) {
V_387 = 0 ;
} else {
V_387 = V_278 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_278 < V_312 ) )
V_278 = V_312 ;
V_278 >>= V_390 ;
return F_126 ( V_387 , V_278 ) ;
}
static void F_305 ( struct V_285 * V_286 , int V_277 )
{
unsigned long V_4 = V_286 -> V_332 ;
unsigned long V_314 = V_312 ;
struct V_301 * V_391 = V_286 -> V_305 ;
if ( ( V_286 -> V_115 & V_392 ) && V_4 > 1 ) {
if ( F_152 ( V_393 ) )
V_314 *= F_302 ( V_286 , V_277 ) ;
else
V_314 *= F_301 ( V_286 , V_277 ) ;
V_314 >>= V_390 ;
}
V_391 -> V_313 -> V_394 = V_314 ;
if ( F_152 ( V_393 ) )
V_314 *= F_300 ( V_286 , V_277 ) ;
else
V_314 *= F_299 ( V_286 , V_277 ) ;
V_314 >>= V_390 ;
V_314 *= F_303 ( V_277 ) ;
V_314 >>= V_390 ;
if ( ! V_314 )
V_314 = 1 ;
F_236 ( V_277 ) -> V_281 = V_314 ;
V_391 -> V_313 -> V_314 = V_314 ;
}
void F_306 ( struct V_285 * V_286 , int V_277 )
{
struct V_285 * V_331 = V_286 -> V_331 ;
struct V_301 * V_304 , * V_391 = V_286 -> V_305 ;
unsigned long V_314 ;
unsigned long V_395 ;
V_395 = F_93 ( V_286 -> V_396 ) ;
V_395 = F_307 ( V_395 , 1UL , V_397 ) ;
V_391 -> V_313 -> V_398 = V_108 + V_395 ;
if ( ! V_331 ) {
F_305 ( V_286 , V_277 ) ;
return;
}
V_314 = 0 ;
if ( V_331 -> V_115 & V_399 ) {
F_251 (cpu, sched_group_cpus(sdg))
V_314 += F_239 ( V_277 ) ;
} else {
V_304 = V_331 -> V_305 ;
do {
V_314 += V_304 -> V_313 -> V_314 ;
V_304 = V_304 -> V_58 ;
} while ( V_304 != V_331 -> V_305 );
}
V_391 -> V_313 -> V_394 = V_391 -> V_313 -> V_314 = V_314 ;
}
static inline int
F_308 ( struct V_285 * V_286 , struct V_301 * V_304 )
{
if ( ! ( V_286 -> V_115 & V_392 ) )
return 0 ;
if ( V_304 -> V_313 -> V_314 * 32 > V_304 -> V_313 -> V_394 * 29 )
return 1 ;
return 0 ;
}
static inline void F_309 ( struct V_349 * V_350 ,
struct V_301 * V_304 , int V_302 ,
int V_310 , int * V_400 , struct V_401 * V_402 )
{
unsigned long V_72 , V_403 , V_404 ;
unsigned long V_70 , V_405 , V_406 ;
unsigned int V_407 = - 1 , V_408 = 0 ;
unsigned long V_409 = 0 ;
int V_311 ;
if ( V_310 )
V_407 = F_310 ( V_304 ) ;
V_405 = 0 ;
V_406 = ~ 0UL ;
V_403 = 0 ;
V_404 = ~ 0UL ;
F_253 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_236 ( V_311 ) ;
V_72 = V_24 -> V_72 ;
if ( V_310 ) {
if ( F_255 ( V_311 ) && ! V_408 &&
F_250 ( V_311 , F_311 ( V_304 ) ) ) {
V_408 = 1 ;
V_407 = V_311 ;
}
V_70 = F_238 ( V_311 , V_302 ) ;
} else {
V_70 = F_237 ( V_311 , V_302 ) ;
if ( V_70 > V_405 )
V_405 = V_70 ;
if ( V_406 > V_70 )
V_406 = V_70 ;
if ( V_72 > V_403 )
V_403 = V_72 ;
if ( V_404 > V_72 )
V_404 = V_72 ;
}
V_402 -> V_410 += V_70 ;
V_402 -> V_411 += V_72 ;
V_402 -> V_412 += F_235 ( V_311 ) ;
if ( F_255 ( V_311 ) )
V_402 -> V_413 ++ ;
}
if ( V_310 ) {
if ( V_350 -> V_232 != V_378 ) {
if ( V_407 != V_350 -> V_352 ) {
* V_400 = 0 ;
return;
}
F_306 ( V_350 -> V_286 , V_350 -> V_352 ) ;
} else if ( F_312 ( V_108 , V_304 -> V_313 -> V_398 ) )
F_306 ( V_350 -> V_286 , V_350 -> V_352 ) ;
}
V_402 -> V_309 = ( V_402 -> V_410 * V_312 ) / V_304 -> V_313 -> V_314 ;
if ( V_402 -> V_411 )
V_409 = V_402 -> V_412 / V_402 -> V_411 ;
if ( ( V_405 - V_406 ) >= V_409 &&
( V_403 - V_404 ) > 1 )
V_402 -> V_414 = 1 ;
V_402 -> V_415 = F_313 ( V_304 -> V_313 -> V_314 ,
V_312 ) ;
if ( ! V_402 -> V_415 )
V_402 -> V_415 = F_308 ( V_350 -> V_286 , V_304 ) ;
V_402 -> V_416 = V_304 -> V_416 ;
if ( V_402 -> V_415 > V_402 -> V_411 )
V_402 -> V_417 = 1 ;
}
static bool F_314 ( struct V_349 * V_350 ,
struct V_418 * V_419 ,
struct V_301 * V_316 ,
struct V_401 * V_402 )
{
if ( V_402 -> V_309 <= V_419 -> V_420 )
return false ;
if ( V_402 -> V_411 > V_402 -> V_415 )
return true ;
if ( V_402 -> V_414 )
return true ;
if ( ( V_350 -> V_286 -> V_115 & V_421 ) && V_402 -> V_411 &&
V_350 -> V_352 < F_315 ( V_316 ) ) {
if ( ! V_419 -> V_422 )
return true ;
if ( F_315 ( V_419 -> V_422 ) > F_315 ( V_316 ) )
return true ;
}
return false ;
}
static inline void F_316 ( struct V_349 * V_350 ,
int * V_400 , struct V_418 * V_419 )
{
struct V_285 * V_331 = V_350 -> V_286 -> V_331 ;
struct V_301 * V_316 = V_350 -> V_286 -> V_305 ;
struct V_401 V_402 ;
int V_302 , V_423 = 0 ;
if ( V_331 && V_331 -> V_115 & V_424 )
V_423 = 1 ;
V_302 = F_298 ( V_350 -> V_286 , V_350 -> V_232 ) ;
do {
int V_310 ;
V_310 = F_250 ( V_350 -> V_352 , F_248 ( V_316 ) ) ;
memset ( & V_402 , 0 , sizeof( V_402 ) ) ;
F_309 ( V_350 , V_316 , V_302 , V_310 , V_400 , & V_402 ) ;
if ( V_310 && ! ( * V_400 ) )
return;
V_419 -> V_425 += V_402 . V_410 ;
V_419 -> V_426 += V_316 -> V_313 -> V_314 ;
if ( V_423 && ! V_310 && V_419 -> V_427 )
V_402 . V_415 = F_16 ( V_402 . V_415 , 1UL ) ;
if ( V_310 ) {
V_419 -> V_288 = V_402 . V_309 ;
V_419 -> V_428 = V_316 ;
V_419 -> V_429 = V_402 . V_411 ;
V_419 -> V_430 = V_402 . V_412 ;
V_419 -> V_427 = V_402 . V_417 ;
V_419 -> V_431 = V_402 . V_413 ;
} else if ( F_314 ( V_350 , V_419 , V_316 , & V_402 ) ) {
V_419 -> V_420 = V_402 . V_309 ;
V_419 -> V_422 = V_316 ;
V_419 -> V_432 = V_402 . V_411 ;
V_419 -> V_433 = V_402 . V_413 ;
V_419 -> V_434 = V_402 . V_415 ;
V_419 -> V_435 = V_402 . V_412 ;
V_419 -> V_436 = V_402 . V_417 ;
V_419 -> V_437 = V_402 . V_416 ;
V_419 -> V_414 = V_402 . V_414 ;
}
V_316 = V_316 -> V_58 ;
} while ( V_316 != V_350 -> V_286 -> V_305 );
}
static int F_317 ( struct V_349 * V_350 , struct V_418 * V_419 )
{
int V_438 ;
if ( ! ( V_350 -> V_286 -> V_115 & V_421 ) )
return 0 ;
if ( ! V_419 -> V_422 )
return 0 ;
V_438 = F_315 ( V_419 -> V_422 ) ;
if ( V_350 -> V_352 > V_438 )
return 0 ;
V_350 -> V_308 = F_313 (
V_419 -> V_420 * V_419 -> V_422 -> V_313 -> V_314 , V_312 ) ;
return 1 ;
}
static inline
void F_318 ( struct V_349 * V_350 , struct V_418 * V_419 )
{
unsigned long V_18 , V_439 = 0 , V_440 = 0 ;
unsigned int V_441 = 2 ;
unsigned long V_442 ;
if ( V_419 -> V_429 ) {
V_419 -> V_430 /= V_419 -> V_429 ;
if ( V_419 -> V_435 >
V_419 -> V_430 )
V_441 = 1 ;
} else {
V_419 -> V_430 =
F_240 ( V_350 -> V_352 ) ;
}
V_442 = V_419 -> V_435
* V_312 ;
V_442 /= V_419 -> V_422 -> V_313 -> V_314 ;
if ( V_419 -> V_420 - V_419 -> V_288 + V_442 >=
( V_442 * V_441 ) ) {
V_350 -> V_308 = V_419 -> V_435 ;
return;
}
V_439 += V_419 -> V_422 -> V_313 -> V_314 *
F_16 ( V_419 -> V_435 , V_419 -> V_420 ) ;
V_439 += V_419 -> V_428 -> V_313 -> V_314 *
F_16 ( V_419 -> V_430 , V_419 -> V_288 ) ;
V_439 /= V_312 ;
V_18 = ( V_419 -> V_435 * V_312 ) /
V_419 -> V_422 -> V_313 -> V_314 ;
if ( V_419 -> V_420 > V_18 )
V_440 += V_419 -> V_422 -> V_313 -> V_314 *
F_16 ( V_419 -> V_435 , V_419 -> V_420 - V_18 ) ;
if ( V_419 -> V_420 * V_419 -> V_422 -> V_313 -> V_314 <
V_419 -> V_435 * V_312 )
V_18 = ( V_419 -> V_420 * V_419 -> V_422 -> V_313 -> V_314 ) /
V_419 -> V_428 -> V_313 -> V_314 ;
else
V_18 = ( V_419 -> V_435 * V_312 ) /
V_419 -> V_428 -> V_313 -> V_314 ;
V_440 += V_419 -> V_428 -> V_313 -> V_314 *
F_16 ( V_419 -> V_430 , V_419 -> V_288 + V_18 ) ;
V_440 /= V_312 ;
if ( V_440 > V_439 )
V_350 -> V_308 = V_419 -> V_435 ;
}
static inline void F_319 ( struct V_349 * V_350 , struct V_418 * V_419 )
{
unsigned long V_443 , V_444 = ~ 0UL ;
V_419 -> V_435 /= V_419 -> V_432 ;
if ( V_419 -> V_414 ) {
V_419 -> V_435 =
F_16 ( V_419 -> V_435 , V_419 -> V_309 ) ;
}
if ( V_419 -> V_420 < V_419 -> V_309 ) {
V_350 -> V_308 = 0 ;
return F_318 ( V_350 , V_419 ) ;
}
if ( ! V_419 -> V_414 ) {
V_444 = ( V_419 -> V_432 -
V_419 -> V_434 ) ;
V_444 *= ( V_445 * V_312 ) ;
V_444 /= V_419 -> V_422 -> V_313 -> V_314 ;
}
V_443 = F_16 ( V_419 -> V_420 - V_419 -> V_309 , V_444 ) ;
V_350 -> V_308 = F_16 ( V_443 * V_419 -> V_422 -> V_313 -> V_314 ,
( V_419 -> V_309 - V_419 -> V_288 ) * V_419 -> V_428 -> V_313 -> V_314 )
/ V_312 ;
if ( V_350 -> V_308 < V_419 -> V_435 )
return F_318 ( V_350 , V_419 ) ;
}
static struct V_301 *
F_320 ( struct V_349 * V_350 , int * V_400 )
{
struct V_418 V_419 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
F_316 ( V_350 , V_400 , & V_419 ) ;
if ( ! ( * V_400 ) )
goto V_66;
if ( ( V_350 -> V_232 == V_446 || V_350 -> V_232 == V_378 ) &&
F_317 ( V_350 , & V_419 ) )
return V_419 . V_422 ;
if ( ! V_419 . V_422 || V_419 . V_432 == 0 )
goto V_447;
V_419 . V_309 = ( V_312 * V_419 . V_425 ) / V_419 . V_426 ;
if ( V_419 . V_414 )
goto V_448;
if ( V_350 -> V_232 == V_378 && V_419 . V_427 &&
! V_419 . V_436 )
goto V_448;
if ( V_419 . V_288 >= V_419 . V_420 )
goto V_447;
if ( V_419 . V_288 >= V_419 . V_309 )
goto V_447;
if ( V_350 -> V_232 == V_446 ) {
if ( ( V_419 . V_431 <= V_419 . V_433 + 1 ) &&
V_419 . V_432 <= V_419 . V_437 )
goto V_447;
} else {
if ( 100 * V_419 . V_420 <= V_350 -> V_286 -> V_297 * V_419 . V_288 )
goto V_447;
}
V_448:
F_319 ( V_350 , & V_419 ) ;
return V_419 . V_422 ;
V_447:
V_66:
V_350 -> V_308 = 0 ;
return NULL ;
}
static struct V_24 * F_321 ( struct V_349 * V_350 ,
struct V_301 * V_304 )
{
struct V_24 * V_422 = NULL , * V_24 ;
unsigned long V_420 = 0 ;
int V_311 ;
F_251 (i, sched_group_cpus(group)) {
unsigned long V_314 = F_239 ( V_311 ) ;
unsigned long V_449 = F_313 ( V_314 ,
V_312 ) ;
unsigned long V_282 ;
if ( ! V_449 )
V_449 = F_308 ( V_350 -> V_286 , V_304 ) ;
if ( ! F_250 ( V_311 , V_350 -> V_8 ) )
continue;
V_24 = F_236 ( V_311 ) ;
V_282 = F_235 ( V_311 ) ;
if ( V_449 && V_24 -> V_72 == 1 && V_282 > V_350 -> V_308 )
continue;
V_282 = ( V_282 * V_312 ) / V_314 ;
if ( V_282 > V_420 ) {
V_420 = V_282 ;
V_422 = V_24 ;
}
}
return V_422 ;
}
static int F_322 ( struct V_349 * V_350 )
{
struct V_285 * V_286 = V_350 -> V_286 ;
if ( V_350 -> V_232 == V_378 ) {
if ( ( V_286 -> V_115 & V_421 ) && V_350 -> V_236 > V_350 -> V_352 )
return 1 ;
}
return F_14 ( V_286 -> V_363 > V_286 -> V_364 + 2 ) ;
}
static int F_323 ( int V_290 , struct V_24 * V_179 ,
struct V_285 * V_286 , enum V_381 V_232 ,
int * V_400 )
{
int V_450 , V_451 , V_452 = 0 ;
struct V_301 * V_304 ;
struct V_24 * V_422 ;
unsigned long V_115 ;
struct V_453 * V_8 = F_324 ( V_454 ) ;
struct V_349 V_350 = {
. V_286 = V_286 ,
. V_352 = V_290 ,
. V_353 = V_179 ,
. V_358 = F_248 ( V_286 -> V_305 ) ,
. V_232 = V_232 ,
. V_374 = V_375 ,
. V_8 = V_8 ,
} ;
if ( V_232 == V_378 )
V_350 . V_358 = NULL ;
F_325 ( V_8 , V_455 ) ;
F_150 ( V_286 , V_456 [ V_232 ] ) ;
V_457:
V_304 = F_320 ( & V_350 , V_400 ) ;
if ( * V_400 == 0 )
goto V_447;
if ( ! V_304 ) {
F_150 ( V_286 , V_458 [ V_232 ] ) ;
goto V_447;
}
V_422 = F_321 ( & V_350 , V_304 ) ;
if ( ! V_422 ) {
F_150 ( V_286 , V_459 [ V_232 ] ) ;
goto V_447;
}
F_270 ( V_422 == V_350 . V_353 ) ;
F_69 ( V_286 , V_460 [ V_232 ] , V_350 . V_308 ) ;
V_450 = 0 ;
if ( V_422 -> V_72 > 1 ) {
V_350 . V_115 |= V_361 ;
V_350 . V_236 = V_422 -> V_277 ;
V_350 . V_351 = V_422 ;
V_350 . V_373 = F_16 ( V_461 , V_422 -> V_72 ) ;
F_296 ( V_350 . V_236 ) ;
V_462:
F_326 ( V_115 ) ;
F_327 ( V_350 . V_353 , V_422 ) ;
V_451 = F_285 ( & V_350 ) ;
V_450 += V_451 ;
F_328 ( V_350 . V_353 , V_422 ) ;
F_329 ( V_115 ) ;
if ( V_451 && V_350 . V_352 != F_180 () )
F_330 ( V_350 . V_352 ) ;
if ( V_350 . V_115 & V_376 ) {
V_350 . V_115 &= ~ V_376 ;
goto V_462;
}
if ( ( V_350 . V_115 & V_359 ) && V_350 . V_308 > 0 ) {
V_350 . V_353 = F_236 ( V_350 . V_360 ) ;
V_350 . V_352 = V_350 . V_360 ;
V_350 . V_115 &= ~ V_359 ;
V_350 . V_372 = 0 ;
V_350 . V_374 = V_375 ;
F_331 ( V_350 . V_352 , V_350 . V_8 ) ;
goto V_462;
}
if ( F_14 ( V_350 . V_115 & V_361 ) ) {
F_331 ( F_27 ( V_422 ) , V_8 ) ;
if ( ! F_332 ( V_8 ) ) {
V_350 . V_372 = 0 ;
V_350 . V_374 = V_375 ;
goto V_457;
}
goto V_447;
}
}
if ( ! V_450 ) {
F_150 ( V_286 , V_463 [ V_232 ] ) ;
if ( V_232 != V_378 )
V_286 -> V_363 ++ ;
if ( F_322 ( & V_350 ) ) {
F_292 ( & V_422 -> V_230 , V_115 ) ;
if ( ! F_250 ( V_290 ,
F_249 ( V_422 -> V_45 ) ) ) {
F_293 ( & V_422 -> V_230 ,
V_115 ) ;
V_350 . V_115 |= V_361 ;
goto V_464;
}
if ( ! V_422 -> V_452 ) {
V_422 -> V_452 = 1 ;
V_422 -> V_465 = V_290 ;
V_452 = 1 ;
}
F_293 ( & V_422 -> V_230 , V_115 ) ;
if ( V_452 ) {
F_333 ( F_27 ( V_422 ) ,
V_466 , V_422 ,
& V_422 -> V_467 ) ;
}
V_286 -> V_363 = V_286 -> V_364 + 1 ;
}
} else
V_286 -> V_363 = 0 ;
if ( F_12 ( ! V_452 ) ) {
V_286 -> V_396 = V_286 -> V_468 ;
} else {
if ( V_286 -> V_396 < V_286 -> V_469 )
V_286 -> V_396 *= 2 ;
}
goto V_133;
V_447:
F_150 ( V_286 , V_470 [ V_232 ] ) ;
V_286 -> V_363 = 0 ;
V_464:
if ( ( ( V_350 . V_115 & V_361 ) &&
V_286 -> V_396 < V_471 ) ||
( V_286 -> V_396 < V_286 -> V_469 ) )
V_286 -> V_396 *= 2 ;
V_450 = 0 ;
V_133:
return V_450 ;
}
void F_334 ( int V_290 , struct V_24 * V_179 )
{
struct V_285 * V_286 ;
int V_472 = 0 ;
unsigned long V_473 = V_108 + V_474 ;
V_179 -> V_475 = F_77 ( V_179 ) ;
if ( V_179 -> V_476 < V_355 )
return;
F_186 ( & V_179 -> V_230 ) ;
F_291 ( V_290 ) ;
F_194 () ;
F_262 (this_cpu, sd) {
unsigned long V_395 ;
int V_400 = 1 ;
if ( ! ( V_286 -> V_115 & V_327 ) )
continue;
if ( V_286 -> V_115 & V_477 ) {
V_472 = F_323 ( V_290 , V_179 ,
V_286 , V_378 , & V_400 ) ;
}
V_395 = F_93 ( V_286 -> V_396 ) ;
if ( F_92 ( V_473 , V_286 -> V_478 + V_395 ) )
V_473 = V_286 -> V_478 + V_395 ;
if ( V_472 ) {
V_179 -> V_475 = 0 ;
break;
}
}
F_196 () ;
F_184 ( & V_179 -> V_230 ) ;
if ( V_472 || F_92 ( V_108 , V_179 -> V_473 ) ) {
V_179 -> V_473 = V_473 ;
}
}
static int V_466 ( void * V_240 )
{
struct V_24 * V_479 = V_240 ;
int V_438 = F_27 ( V_479 ) ;
int V_480 = V_479 -> V_465 ;
struct V_24 * V_481 = F_236 ( V_480 ) ;
struct V_285 * V_286 ;
F_335 ( & V_479 -> V_230 ) ;
if ( F_14 ( V_438 != F_180 () ||
! V_479 -> V_452 ) )
goto V_253;
if ( V_479 -> V_72 <= 1 )
goto V_253;
F_270 ( V_479 == V_481 ) ;
F_336 ( V_479 , V_481 ) ;
F_194 () ;
F_262 (target_cpu, sd) {
if ( ( V_286 -> V_115 & V_327 ) &&
F_250 ( V_438 , F_263 ( V_286 ) ) )
break;
}
if ( F_12 ( V_286 ) ) {
struct V_349 V_350 = {
. V_286 = V_286 ,
. V_352 = V_480 ,
. V_353 = V_481 ,
. V_236 = V_479 -> V_277 ,
. V_351 = V_479 ,
. V_232 = V_446 ,
} ;
F_150 ( V_286 , V_482 ) ;
if ( F_283 ( & V_350 ) )
F_150 ( V_286 , V_483 ) ;
else
F_150 ( V_286 , V_484 ) ;
}
F_196 () ;
F_337 ( V_479 , V_481 ) ;
V_253:
V_479 -> V_452 = 0 ;
F_338 ( & V_479 -> V_230 ) ;
return 0 ;
}
static inline int F_339 ( int V_485 )
{
int V_486 = F_340 ( V_487 . V_488 ) ;
if ( V_486 < V_489 && F_255 ( V_486 ) )
return V_486 ;
return V_489 ;
}
static void F_341 ( int V_277 )
{
int V_490 ;
V_487 . V_473 ++ ;
V_490 = F_339 ( V_277 ) ;
if ( V_490 >= V_489 )
return;
if ( F_342 ( V_491 , F_343 ( V_490 ) ) )
return;
F_344 ( V_490 ) ;
return;
}
static inline void F_345 ( int V_277 )
{
if ( F_14 ( F_346 ( V_492 , F_343 ( V_277 ) ) ) ) {
F_331 ( V_277 , V_487 . V_488 ) ;
F_347 ( & V_487 . V_493 ) ;
F_348 ( V_492 , F_343 ( V_277 ) ) ;
}
}
static inline void F_349 ( void )
{
struct V_285 * V_286 ;
F_194 () ;
V_286 = F_350 ( V_179 () -> V_286 ) ;
if ( ! V_286 || ! V_286 -> V_494 )
goto V_329;
V_286 -> V_494 = 0 ;
for (; V_286 ; V_286 = V_286 -> V_34 )
F_351 ( & V_286 -> V_305 -> V_313 -> V_495 ) ;
V_329:
F_196 () ;
}
void F_352 ( void )
{
struct V_285 * V_286 ;
F_194 () ;
V_286 = F_350 ( V_179 () -> V_286 ) ;
if ( ! V_286 || V_286 -> V_494 )
goto V_329;
V_286 -> V_494 = 1 ;
for (; V_286 ; V_286 = V_286 -> V_34 )
F_347 ( & V_286 -> V_305 -> V_313 -> V_495 ) ;
V_329:
F_196 () ;
}
void F_353 ( int V_277 )
{
if ( ! F_354 ( V_277 ) )
return;
if ( F_346 ( V_492 , F_343 ( V_277 ) ) )
return;
F_355 ( V_277 , V_487 . V_488 ) ;
F_351 ( & V_487 . V_493 ) ;
F_356 ( V_492 , F_343 ( V_277 ) ) ;
}
static int F_357 ( struct V_496 * V_497 ,
unsigned long V_498 , void * V_499 )
{
switch ( V_498 & ~ V_500 ) {
case V_501 :
F_345 ( F_180 () ) ;
return V_502 ;
default:
return V_503 ;
}
}
void F_358 ( void )
{
V_397 = V_474 * F_6 () / 10 ;
}
static void F_359 ( int V_277 , enum V_381 V_232 )
{
int V_400 = 1 ;
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_395 ;
struct V_285 * V_286 ;
unsigned long V_473 = V_108 + 60 * V_474 ;
int V_504 = 0 ;
int V_505 ;
F_291 ( V_277 ) ;
F_194 () ;
F_262 (cpu, sd) {
if ( ! ( V_286 -> V_115 & V_327 ) )
continue;
V_395 = V_286 -> V_396 ;
if ( V_232 != V_446 )
V_395 *= V_286 -> V_506 ;
V_395 = F_93 ( V_395 ) ;
V_395 = F_307 ( V_395 , 1UL , V_397 ) ;
V_505 = V_286 -> V_115 & V_507 ;
if ( V_505 ) {
if ( ! F_360 ( & V_508 ) )
goto V_133;
}
if ( F_312 ( V_108 , V_286 -> V_478 + V_395 ) ) {
if ( F_323 ( V_277 , V_24 , V_286 , V_232 , & V_400 ) ) {
V_232 = F_255 ( V_277 ) ? V_446 : V_382 ;
}
V_286 -> V_478 = V_108 ;
}
if ( V_505 )
F_361 ( & V_508 ) ;
V_133:
if ( F_92 ( V_473 , V_286 -> V_478 + V_395 ) ) {
V_473 = V_286 -> V_478 + V_395 ;
V_504 = 1 ;
}
if ( ! V_400 )
break;
}
F_196 () ;
if ( F_12 ( V_504 ) )
V_24 -> V_473 = V_473 ;
}
static void F_362 ( int V_290 , enum V_381 V_232 )
{
struct V_24 * V_179 = F_236 ( V_290 ) ;
struct V_24 * V_24 ;
int V_407 ;
if ( V_232 != V_446 ||
! F_346 ( V_491 , F_343 ( V_290 ) ) )
goto V_113;
F_251 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_407 == V_290 || ! F_255 ( V_407 ) )
continue;
if ( F_363 () )
break;
V_24 = F_236 ( V_407 ) ;
F_335 ( & V_24 -> V_230 ) ;
F_198 ( V_24 ) ;
F_364 ( V_24 ) ;
F_338 ( & V_24 -> V_230 ) ;
F_359 ( V_407 , V_446 ) ;
if ( F_92 ( V_179 -> V_473 , V_24 -> V_473 ) )
V_179 -> V_473 = V_24 -> V_473 ;
}
V_487 . V_473 = V_179 -> V_473 ;
V_113:
F_348 ( V_491 , F_343 ( V_290 ) ) ;
}
static inline int F_365 ( struct V_24 * V_24 , int V_277 )
{
unsigned long V_86 = V_108 ;
struct V_285 * V_286 ;
if ( F_14 ( F_255 ( V_277 ) ) )
return 0 ;
F_349 () ;
F_345 ( V_277 ) ;
if ( F_12 ( ! F_129 ( & V_487 . V_493 ) ) )
return 0 ;
if ( F_95 ( V_86 , V_487 . V_473 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_509;
F_194 () ;
F_262 (cpu, sd) {
struct V_301 * V_316 = V_286 -> V_305 ;
struct V_510 * V_313 = V_316 -> V_313 ;
int V_511 = F_129 ( & V_313 -> V_495 ) ;
if ( V_286 -> V_115 & V_512 && V_511 > 1 )
goto V_513;
if ( V_286 -> V_115 & V_421 && V_511 != V_316 -> V_416
&& ( F_260 ( V_487 . V_488 ,
F_263 ( V_286 ) ) < V_277 ) )
goto V_513;
if ( ! ( V_286 -> V_115 & ( V_512 | V_421 ) ) )
break;
}
F_196 () ;
return 0 ;
V_513:
F_196 () ;
V_509:
return 1 ;
}
static void F_362 ( int V_290 , enum V_381 V_232 ) { }
static void F_366 ( struct V_514 * V_515 )
{
int V_290 = F_180 () ;
struct V_24 * V_179 = F_236 ( V_290 ) ;
enum V_381 V_232 = V_179 -> F_334 ?
V_446 : V_382 ;
F_359 ( V_290 , V_232 ) ;
F_362 ( V_290 , V_232 ) ;
}
static inline int F_367 ( int V_277 )
{
return ! F_368 ( F_236 ( V_277 ) -> V_286 ) ;
}
void F_369 ( struct V_24 * V_24 , int V_277 )
{
if ( F_312 ( V_108 , V_24 -> V_473 ) &&
F_12 ( ! F_367 ( V_277 ) ) )
F_370 ( V_516 ) ;
#ifdef F_371
if ( F_365 ( V_24 , V_277 ) && F_12 ( ! F_367 ( V_277 ) ) )
F_341 ( V_277 ) ;
#endif
}
static void F_372 ( struct V_24 * V_24 )
{
F_8 () ;
}
static void F_373 ( struct V_24 * V_24 )
{
F_8 () ;
F_222 ( V_24 ) ;
}
static void F_374 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_209 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_45 -> V_28 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_168 ( V_25 , V_28 , V_209 ) ;
}
if ( V_100 )
F_104 ( V_24 , V_45 ) ;
F_137 ( V_24 , 1 ) ;
}
static void F_375 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_290 = F_180 () ;
struct V_24 * V_24 = V_179 () ;
unsigned long V_115 ;
F_292 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
V_25 = F_23 ( V_99 ) ;
V_45 = V_25 -> V_45 ;
if ( F_14 ( F_245 ( V_29 ) != V_290 ) ) {
F_194 () ;
F_376 ( V_29 , V_290 ) ;
F_196 () ;
}
F_70 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_151 ( V_25 , V_28 , 1 ) ;
if ( V_517 && V_45 && F_41 ( V_45 , V_28 ) ) {
F_377 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_162 ( V_24 -> V_45 ) ;
}
V_28 -> V_41 -= V_25 -> F_40 ;
F_293 ( & V_24 -> V_230 , V_115 ) ;
}
static void
F_378 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_518 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_519 > V_518 )
F_162 ( V_24 -> V_45 ) ;
} else
F_279 ( V_24 , V_29 , 0 ) ;
}
static void F_379 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 && V_29 -> V_201 != V_520 ) {
F_151 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_40 ;
}
#ifdef F_108
if ( V_29 -> V_28 . V_77 . V_78 ) {
struct V_25 * V_25 = F_24 ( & V_29 -> V_28 ) ;
F_121 ( & V_29 -> V_28 ) ;
F_132 ( V_25 ,
V_29 -> V_28 . V_77 . V_163 ) ;
}
#endif
}
static void F_380 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_162 ( V_24 -> V_45 ) ;
else
F_279 ( V_24 , V_29 , 0 ) ;
}
static void F_381 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_163 ( V_25 , V_28 ) ;
F_75 ( V_25 , 0 ) ;
}
}
void F_382 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_521 ;
V_25 -> F_40 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_44
V_25 -> V_48 = V_25 -> F_40 ;
#endif
#ifdef F_108
F_383 ( & V_25 -> V_162 , 1 ) ;
F_384 ( & V_25 -> V_176 , 0 ) ;
#endif
}
static void F_385 ( struct V_26 * V_29 , int V_76 )
{
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_29 -> V_28 . V_84 || V_29 -> V_201 == V_522 ) )
V_76 = 1 ;
if ( ! V_76 )
V_29 -> V_28 . V_41 -= F_24 ( & V_29 -> V_28 ) -> F_40 ;
F_386 ( V_29 , F_245 ( V_29 ) ) ;
if ( ! V_76 ) {
V_25 = F_24 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_41 += V_25 -> F_40 ;
#ifdef F_108
V_29 -> V_28 . V_77 . V_78 = F_122 ( & V_25 -> V_162 ) ;
V_25 -> V_167 += V_29 -> V_28 . V_77 . V_163 ;
#endif
}
}
void F_387 ( struct V_138 * V_33 )
{
int V_311 ;
F_221 ( F_182 ( V_33 ) ) ;
F_388 (i) {
if ( V_33 -> V_25 )
F_389 ( V_33 -> V_25 [ V_311 ] ) ;
if ( V_33 -> V_28 )
F_389 ( V_33 -> V_28 [ V_311 ] ) ;
}
F_389 ( V_33 -> V_25 ) ;
F_389 ( V_33 -> V_28 ) ;
}
int F_390 ( struct V_138 * V_33 , struct V_138 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_311 ;
V_33 -> V_25 = F_391 ( sizeof( V_25 ) * V_489 , V_523 ) ;
if ( ! V_33 -> V_25 )
goto V_524;
V_33 -> V_28 = F_391 ( sizeof( V_28 ) * V_489 , V_523 ) ;
if ( ! V_33 -> V_28 )
goto V_524;
V_33 -> V_142 = V_71 ;
F_215 ( F_182 ( V_33 ) ) ;
F_388 (i) {
V_25 = F_392 ( sizeof( struct V_25 ) ,
V_523 , F_393 ( V_311 ) ) ;
if ( ! V_25 )
goto V_524;
V_28 = F_392 ( sizeof( struct V_27 ) ,
V_523 , F_393 ( V_311 ) ) ;
if ( ! V_28 )
goto V_525;
F_382 ( V_25 ) ;
F_394 ( V_33 , V_25 , V_28 , V_311 , V_34 -> V_28 [ V_311 ] ) ;
}
return 1 ;
V_525:
F_389 ( V_25 ) ;
V_524:
return 0 ;
}
void F_395 ( struct V_138 * V_33 , int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_115 ;
if ( ! V_33 -> V_25 [ V_277 ] -> V_32 )
return;
F_292 ( & V_24 -> V_230 , V_115 ) ;
F_31 ( V_33 -> V_25 [ V_277 ] ) ;
F_293 ( & V_24 -> V_230 , V_115 ) ;
}
void F_394 ( struct V_138 * V_33 , struct V_25 * V_25 ,
struct V_27 * V_28 , int V_277 ,
struct V_27 * V_34 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_24 = V_24 ;
F_219 ( V_25 ) ;
V_33 -> V_25 [ V_277 ] = V_25 ;
V_33 -> V_28 [ V_277 ] = V_28 ;
if ( ! V_28 )
return;
if ( ! V_34 )
V_28 -> V_25 = & V_24 -> V_40 ;
else
V_28 -> V_25 = V_34 -> V_31 ;
V_28 -> V_31 = V_25 ;
F_3 ( & V_28 -> V_70 , 0 ) ;
V_28 -> V_34 = V_34 ;
}
int F_396 ( struct V_138 * V_33 , unsigned long V_142 )
{
int V_311 ;
unsigned long V_115 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_526 ;
V_142 = F_307 ( V_142 , F_130 ( V_143 ) , F_130 ( V_527 ) ) ;
F_397 ( & V_528 ) ;
if ( V_33 -> V_142 == V_142 )
goto V_318;
V_33 -> V_142 = V_142 ;
F_388 (i) {
struct V_24 * V_24 = F_236 ( V_311 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_311 ] ;
F_292 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
F_36 (se)
F_116 ( F_25 ( V_28 ) ) ;
F_293 ( & V_24 -> V_230 , V_115 ) ;
}
V_318:
F_398 ( & V_528 ) ;
return 0 ;
}
void F_387 ( struct V_138 * V_33 ) { }
int F_390 ( struct V_138 * V_33 , struct V_138 * V_34 )
{
return 1 ;
}
void F_395 ( struct V_138 * V_33 , int V_277 ) { }
static unsigned int F_399 ( struct V_24 * V_24 , struct V_26 * V_529 )
{
struct V_27 * V_28 = & V_529 -> V_28 ;
unsigned int V_530 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_530 = F_400 ( F_62 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_530 ;
}
void F_401 ( struct V_531 * V_532 , int V_277 )
{
struct V_25 * V_25 ;
F_194 () ;
F_223 (cpu_rq(cpu), cfs_rq)
F_402 ( V_532 , V_277 , V_25 ) ;
F_196 () ;
}
T_11 void F_403 ( void )
{
#ifdef F_108
F_404 ( V_516 , F_366 ) ;
#ifdef F_371
V_487 . V_473 = V_108 ;
F_405 ( & V_487 . V_488 , V_533 ) ;
F_406 ( F_357 , 0 ) ;
#endif
#endif
}
