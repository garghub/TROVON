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
if ( V_108 > V_99 -> V_282 + V_283 ) {
V_99 -> V_284 = 0 ;
V_99 -> V_282 = V_108 ;
}
if ( V_99 -> V_285 != V_29 ) {
V_99 -> V_285 = V_29 ;
V_99 -> V_284 ++ ;
}
}
static void F_242 ( struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
T_2 F_40 ;
#ifndef F_44
T_2 V_48 ;
do {
V_48 = V_25 -> V_48 ;
F_243 () ;
F_40 = V_25 -> F_40 ;
} while ( F_40 != V_48 );
#else
F_40 = V_25 -> F_40 ;
#endif
V_28 -> V_41 -= F_40 ;
F_241 ( V_29 ) ;
}
static long F_244 ( struct V_138 * V_33 , int V_277 , long V_286 , long V_287 )
{
struct V_27 * V_28 = V_33 -> V_28 [ V_277 ] ;
if ( ! V_33 -> V_34 )
return V_286 ;
F_36 (se) {
long V_7 , V_288 ;
V_33 = V_28 -> V_31 -> V_33 ;
V_288 = V_287 + F_112 ( V_33 , V_28 -> V_31 ) ;
V_7 = V_28 -> V_31 -> V_70 . V_4 + V_286 ;
if ( V_288 > 0 && V_7 < V_288 )
V_286 = ( V_7 * V_33 -> V_142 ) / V_288 ;
else
V_286 = V_33 -> V_142 ;
if ( V_286 < V_143 )
V_286 = V_143 ;
V_286 -= V_28 -> V_70 . V_4 ;
V_287 = 0 ;
}
return V_286 ;
}
static inline unsigned long F_244 ( struct V_138 * V_33 , int V_277 ,
unsigned long V_286 , unsigned long V_287 )
{
return V_286 ;
}
static int F_245 ( struct V_26 * V_29 )
{
int V_9 = F_246 ( V_289 ) ;
if ( V_29 -> V_284 > V_9 ) {
if ( V_99 -> V_284 > ( V_9 * V_29 -> V_284 ) )
return 1 ;
}
return 0 ;
}
static int F_247 ( struct V_290 * V_291 , struct V_26 * V_29 , int V_292 )
{
T_3 V_293 , V_70 ;
int V_294 , V_295 , V_296 ;
unsigned long V_297 ;
struct V_138 * V_33 ;
unsigned long V_4 ;
int V_298 ;
if ( F_245 ( V_29 ) )
return 0 ;
V_294 = V_291 -> V_299 ;
V_295 = F_180 () ;
V_296 = F_248 ( V_29 ) ;
V_70 = F_237 ( V_296 , V_294 ) ;
V_293 = F_238 ( V_295 , V_294 ) ;
if ( V_292 ) {
V_33 = V_138 ( V_99 ) ;
V_4 = V_99 -> V_28 . V_70 . V_4 ;
V_293 += F_244 ( V_33 , V_295 , - V_4 , - V_4 ) ;
V_70 += F_244 ( V_33 , V_296 , 0 , - V_4 ) ;
}
V_33 = V_138 ( V_29 ) ;
V_4 = V_29 -> V_28 . V_70 . V_4 ;
if ( V_293 > 0 ) {
T_3 V_300 , V_301 ;
V_300 = 100 ;
V_300 *= F_239 ( V_296 ) ;
V_300 *= V_293 +
F_244 ( V_33 , V_295 , V_4 , V_4 ) ;
V_301 = 100 + ( V_291 -> V_302 - 100 ) / 2 ;
V_301 *= F_239 ( V_295 ) ;
V_301 *= V_70 + F_244 ( V_33 , V_296 , 0 , V_4 ) ;
V_298 = V_300 <= V_301 ;
} else
V_298 = true ;
if ( V_292 && V_298 )
return 1 ;
F_150 ( V_29 , V_28 . V_82 . V_303 ) ;
V_297 = F_240 ( V_295 ) ;
if ( V_298 ||
( V_293 <= V_70 &&
V_293 + F_238 ( V_296 , V_294 ) <= V_297 ) ) {
F_150 ( V_291 , V_304 ) ;
F_150 ( V_29 , V_28 . V_82 . V_305 ) ;
return 1 ;
}
return 0 ;
}
static struct V_306 *
F_249 ( struct V_290 * V_291 , struct V_26 * V_29 ,
int V_295 , int V_307 )
{
struct V_306 * V_308 = NULL , * V_309 = V_291 -> V_310 ;
unsigned long V_311 = V_312 , V_293 = 0 ;
int V_313 = 100 + ( V_291 -> V_302 - 100 ) / 2 ;
do {
unsigned long V_70 , V_314 ;
int V_315 ;
int V_316 ;
if ( ! F_250 ( F_251 ( V_309 ) ,
F_252 ( V_29 ) ) )
continue;
V_315 = F_253 ( V_295 ,
F_251 ( V_309 ) ) ;
V_314 = 0 ;
F_254 (i, sched_group_cpus(group)) {
if ( V_315 )
V_70 = F_237 ( V_316 , V_307 ) ;
else
V_70 = F_238 ( V_316 , V_307 ) ;
V_314 += V_70 ;
}
V_314 = ( V_314 * V_317 ) / V_309 -> V_318 -> V_319 ;
if ( V_315 ) {
V_293 = V_314 ;
} else if ( V_314 < V_311 ) {
V_311 = V_314 ;
V_308 = V_309 ;
}
} while ( V_309 = V_309 -> V_58 , V_309 != V_291 -> V_310 );
if ( ! V_308 || 100 * V_293 < V_313 * V_311 )
return NULL ;
return V_308 ;
}
static int
F_255 ( struct V_306 * V_309 , struct V_26 * V_29 , int V_295 )
{
unsigned long V_70 , V_311 = V_312 ;
int V_308 = - 1 ;
int V_316 ;
F_256 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_70 = F_235 ( V_316 ) ;
if ( V_70 < V_311 || ( V_70 == V_311 && V_316 == V_295 ) ) {
V_311 = V_70 ;
V_308 = V_316 ;
}
}
return V_308 ;
}
static int F_257 ( struct V_26 * V_29 , int V_320 )
{
struct V_290 * V_291 ;
struct V_306 * V_321 ;
int V_316 = F_248 ( V_29 ) ;
if ( F_258 ( V_320 ) )
return V_320 ;
if ( V_316 != V_320 && F_259 ( V_316 , V_320 ) && F_258 ( V_316 ) )
return V_316 ;
V_291 = F_260 ( F_261 ( V_322 , V_320 ) ) ;
F_262 (sd) {
V_321 = V_291 -> V_310 ;
do {
if ( ! F_250 ( F_251 ( V_321 ) ,
F_252 ( V_29 ) ) )
goto V_58;
F_254 (i, sched_group_cpus(sg)) {
if ( V_316 == V_320 || ! F_258 ( V_316 ) )
goto V_58;
}
V_320 = F_263 ( F_251 ( V_321 ) ,
F_252 ( V_29 ) ) ;
goto V_323;
V_58:
V_321 = V_321 -> V_58 ;
} while ( V_321 != V_291 -> V_310 );
}
V_323:
return V_320 ;
}
static int
F_264 ( struct V_26 * V_29 , int V_324 , int V_325 )
{
struct V_290 * V_18 , * V_326 = NULL , * V_291 = NULL ;
int V_277 = F_180 () ;
int V_296 = F_248 ( V_29 ) ;
int V_327 = V_277 ;
int V_328 = 0 ;
int V_292 = V_325 & V_329 ;
if ( V_29 -> V_330 == 1 )
return V_296 ;
if ( V_324 & V_331 ) {
if ( F_253 ( V_277 , F_252 ( V_29 ) ) )
V_328 = 1 ;
V_327 = V_296 ;
}
F_194 () ;
F_265 (cpu, tmp) {
if ( ! ( V_18 -> V_115 & V_332 ) )
continue;
if ( V_328 && ( V_18 -> V_115 & V_333 ) &&
F_253 ( V_296 , F_266 ( V_18 ) ) ) {
V_326 = V_18 ;
break;
}
if ( V_18 -> V_115 & V_324 )
V_291 = V_18 ;
}
if ( V_326 ) {
if ( V_277 != V_296 && F_247 ( V_326 , V_29 , V_292 ) )
V_296 = V_277 ;
V_327 = F_257 ( V_29 , V_296 ) ;
goto V_334;
}
while ( V_291 ) {
int V_307 = V_291 -> V_335 ;
struct V_306 * V_309 ;
int V_4 ;
if ( ! ( V_291 -> V_115 & V_324 ) ) {
V_291 = V_291 -> V_336 ;
continue;
}
if ( V_324 & V_331 )
V_307 = V_291 -> V_299 ;
V_309 = F_249 ( V_291 , V_29 , V_277 , V_307 ) ;
if ( ! V_309 ) {
V_291 = V_291 -> V_336 ;
continue;
}
V_327 = F_255 ( V_309 , V_29 , V_277 ) ;
if ( V_327 == - 1 || V_327 == V_277 ) {
V_291 = V_291 -> V_336 ;
continue;
}
V_277 = V_327 ;
V_4 = V_291 -> V_337 ;
V_291 = NULL ;
F_265 (cpu, tmp) {
if ( V_4 <= V_18 -> V_337 )
break;
if ( V_18 -> V_115 & V_324 )
V_291 = V_18 ;
}
}
V_334:
F_196 () ;
return V_327 ;
}
static void
F_267 ( struct V_26 * V_29 , int V_338 )
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
F_268 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
unsigned long V_339 = V_340 ;
return F_60 ( V_339 , V_28 ) ;
}
static int
F_165 ( struct V_27 * V_45 , struct V_27 * V_28 )
{
T_3 V_339 , V_341 = V_45 -> V_41 - V_28 -> V_41 ;
if ( V_341 <= 0 )
return - 1 ;
V_339 = F_268 ( V_45 , V_28 ) ;
if ( V_341 > V_339 )
return 1 ;
return 0 ;
}
static void F_269 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_342 == V_343 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_59 = V_28 ;
}
static void F_233 ( struct V_27 * V_28 )
{
if ( F_21 ( V_28 ) && F_14 ( F_18 ( V_28 ) -> V_342 == V_343 ) )
return;
F_36 (se)
F_24 ( V_28 ) -> V_58 = V_28 ;
}
static void F_270 ( struct V_27 * V_28 )
{
F_36 (se)
F_24 ( V_28 ) -> V_199 = V_28 ;
}
static void F_271 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_325 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_27 * V_28 = & V_45 -> V_28 , * V_36 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
int V_344 = V_25 -> V_72 >= V_67 ;
int V_345 = 0 ;
if ( F_14 ( V_28 == V_36 ) )
return;
if ( F_14 ( F_117 ( F_24 ( V_36 ) ) ) )
return;
if ( F_152 ( V_346 ) && V_344 && ! ( V_325 & V_347 ) ) {
F_233 ( V_36 ) ;
V_345 = 1 ;
}
if ( F_272 ( V_45 ) )
return;
if ( F_14 ( V_45 -> V_342 == V_343 ) &&
F_12 ( V_29 -> V_342 != V_343 ) )
goto V_348;
if ( F_14 ( V_29 -> V_342 != V_349 ) || ! F_152 ( V_350 ) )
return;
F_37 ( & V_28 , & V_36 ) ;
F_70 ( F_24 ( V_28 ) ) ;
F_273 ( ! V_36 ) ;
if ( F_165 ( V_28 , V_36 ) == 1 ) {
if ( ! V_345 )
F_233 ( V_36 ) ;
goto V_348;
}
return;
V_348:
F_162 ( V_45 ) ;
if ( F_14 ( ! V_28 -> V_76 || V_45 == V_24 -> V_232 ) )
return;
if ( F_152 ( V_351 ) && V_344 && F_21 ( V_28 ) )
F_269 ( V_28 ) ;
}
static struct V_26 * F_274 ( struct V_24 * V_24 )
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
static void F_275 ( struct V_24 * V_24 , struct V_26 * V_208 )
{
struct V_27 * V_28 = & V_208 -> V_28 ;
struct V_25 * V_25 ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
F_166 ( V_25 , V_28 ) ;
}
}
static void F_276 ( struct V_24 * V_24 )
{
struct V_26 * V_45 = V_24 -> V_45 ;
struct V_25 * V_25 = F_23 ( V_45 ) ;
struct V_27 * V_28 = & V_45 -> V_28 ;
if ( F_14 ( V_24 -> V_72 == 1 ) )
return;
F_158 ( V_25 , V_28 ) ;
if ( V_45 -> V_342 != V_352 ) {
F_198 ( V_24 ) ;
F_70 ( V_25 ) ;
V_24 -> V_353 = 1 ;
}
F_270 ( V_28 ) ;
}
static bool F_277 ( struct V_24 * V_24 , struct V_26 * V_29 , bool V_348 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
if ( ! V_28 -> V_76 || F_117 ( F_24 ( V_28 ) ) )
return false ;
F_233 ( V_28 ) ;
F_276 ( V_24 ) ;
return true ;
}
static void F_278 ( struct V_26 * V_29 , struct V_354 * V_355 )
{
F_279 ( V_355 -> V_356 , V_29 , 0 ) ;
F_280 ( V_29 , V_355 -> V_357 ) ;
F_281 ( V_355 -> V_358 , V_29 , 0 ) ;
F_282 ( V_355 -> V_358 , V_29 , 0 ) ;
}
static int
F_283 ( struct V_26 * V_29 , T_2 V_86 , struct V_290 * V_291 )
{
T_3 V_42 ;
if ( V_29 -> V_274 != & V_275 )
return 0 ;
if ( F_14 ( V_29 -> V_342 == V_343 ) )
return 0 ;
if ( F_152 ( V_359 ) && V_179 () -> V_72 &&
( & V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_58 ||
& V_29 -> V_28 == F_24 ( & V_29 -> V_28 ) -> V_59 ) )
return 1 ;
if ( V_360 == - 1 )
return 1 ;
if ( V_360 == 0 )
return 0 ;
V_42 = V_86 - V_29 -> V_28 . V_87 ;
return V_42 < ( T_3 ) V_360 ;
}
static
int F_284 ( struct V_26 * V_29 , struct V_354 * V_355 )
{
int V_361 = 0 ;
if ( F_190 ( V_138 ( V_29 ) , V_355 -> V_236 , V_355 -> V_357 ) )
return 0 ;
if ( ! F_253 ( V_355 -> V_357 , F_252 ( V_29 ) ) ) {
int V_277 ;
F_150 ( V_29 , V_28 . V_82 . V_362 ) ;
if ( ! V_355 -> V_363 || ( V_355 -> V_115 & V_364 ) )
return 0 ;
F_256 (cpu, env->dst_grpmask, env->cpus) {
if ( F_253 ( V_277 , F_252 ( V_29 ) ) ) {
V_355 -> V_115 |= V_364 ;
V_355 -> V_365 = V_277 ;
break;
}
}
return 0 ;
}
V_355 -> V_115 &= ~ V_366 ;
if ( F_285 ( V_355 -> V_356 , V_29 ) ) {
F_150 ( V_29 , V_28 . V_82 . V_367 ) ;
return 0 ;
}
V_361 = F_283 ( V_29 , F_71 ( V_355 -> V_356 ) , V_355 -> V_291 ) ;
if ( ! V_361 ||
V_355 -> V_291 -> V_368 > V_355 -> V_291 -> V_369 ) {
if ( V_361 ) {
F_150 ( V_355 -> V_291 , V_370 [ V_355 -> V_232 ] ) ;
F_150 ( V_29 , V_28 . V_82 . V_371 ) ;
}
return 1 ;
}
F_150 ( V_29 , V_28 . V_82 . V_372 ) ;
return 0 ;
}
static int F_286 ( struct V_354 * V_355 )
{
struct V_26 * V_29 , * V_145 ;
F_287 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( ! F_284 ( V_29 , V_355 ) )
continue;
F_278 ( V_29 , V_355 ) ;
F_150 ( V_355 -> V_291 , V_373 [ V_355 -> V_232 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_288 ( struct V_354 * V_355 )
{
struct V_374 * V_375 = & V_355 -> V_356 -> V_137 ;
struct V_26 * V_29 ;
unsigned long V_70 ;
int V_376 = 0 ;
if ( V_355 -> V_313 <= 0 )
return 0 ;
while ( ! F_202 ( V_375 ) ) {
V_29 = F_289 ( V_375 , struct V_26 , V_28 . V_136 ) ;
V_355 -> V_377 ++ ;
if ( V_355 -> V_377 > V_355 -> V_378 )
break;
if ( V_355 -> V_377 > V_355 -> V_379 ) {
V_355 -> V_379 += V_380 ;
V_355 -> V_115 |= V_381 ;
break;
}
if ( ! F_284 ( V_29 , V_355 ) )
goto V_58;
V_70 = F_290 ( V_29 ) ;
if ( F_152 ( V_382 ) && V_70 < 16 && ! V_355 -> V_291 -> V_368 )
goto V_58;
if ( ( V_70 / 2 ) > V_355 -> V_313 )
goto V_58;
F_278 ( V_29 , V_355 ) ;
V_376 ++ ;
V_355 -> V_313 -= V_70 ;
#ifdef F_291
if ( V_355 -> V_232 == V_383 )
break;
#endif
if ( V_355 -> V_313 <= 0 )
break;
continue;
V_58:
F_292 ( & V_29 -> V_28 . V_136 , V_375 ) ;
}
F_69 ( V_355 -> V_291 , V_373 [ V_355 -> V_232 ] , V_376 ) ;
return V_376 ;
}
static void F_293 ( struct V_138 * V_33 , int V_277 )
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
static void F_294 ( int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
struct V_25 * V_25 ;
unsigned long V_115 ;
F_295 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
F_223 (rq, cfs_rq) {
F_293 ( V_25 -> V_33 , V_24 -> V_277 ) ;
}
F_296 ( & V_24 -> V_230 , V_115 ) ;
}
static void F_297 ( struct V_25 * V_25 )
{
struct V_24 * V_24 = F_17 ( V_25 ) ;
struct V_27 * V_28 = V_25 -> V_33 -> V_28 [ F_27 ( V_24 ) ] ;
unsigned long V_86 = V_108 ;
unsigned long V_70 ;
if ( V_25 -> V_384 == V_86 )
return;
V_25 -> V_385 = NULL ;
F_36 (se) {
V_25 = F_24 ( V_28 ) ;
V_25 -> V_385 = V_28 ;
if ( V_25 -> V_384 == V_86 )
break;
}
if ( ! V_28 ) {
V_25 -> V_386 = V_25 -> V_166 ;
V_25 -> V_384 = V_86 ;
}
while ( ( V_28 = V_25 -> V_385 ) != NULL ) {
V_70 = V_25 -> V_386 ;
V_70 = F_298 ( V_70 * V_28 -> V_77 . V_163 ,
V_25 -> V_166 + 1 ) ;
V_25 = F_25 ( V_28 ) ;
V_25 -> V_386 = V_70 ;
V_25 -> V_384 = V_86 ;
}
}
static unsigned long F_290 ( struct V_26 * V_29 )
{
struct V_25 * V_25 = F_23 ( V_29 ) ;
F_297 ( V_25 ) ;
return F_298 ( V_29 -> V_28 . V_77 . V_163 * V_25 -> V_386 ,
V_25 -> V_166 + 1 ) ;
}
static inline void F_294 ( int V_277 )
{
}
static unsigned long F_290 ( struct V_26 * V_29 )
{
return V_29 -> V_28 . V_77 . V_163 ;
}
static inline void F_299 ( struct V_387 * V_388 )
{
* V_388 = (struct V_387 ) {
. V_389 = NULL ,
. V_390 = NULL ,
. V_391 = 0UL ,
. V_392 = 0UL ,
. V_393 = {
. V_314 = 0UL ,
} ,
} ;
}
static inline int F_300 ( struct V_290 * V_291 ,
enum V_394 V_232 )
{
int V_307 ;
switch ( V_232 ) {
case V_395 :
V_307 = V_291 -> V_396 ;
break;
case V_383 :
V_307 = V_291 -> V_397 ;
break;
default:
V_307 = V_291 -> V_398 ;
break;
}
return V_307 ;
}
static unsigned long F_301 ( struct V_290 * V_291 , int V_277 )
{
return V_317 ;
}
unsigned long __weak F_302 ( struct V_290 * V_291 , int V_277 )
{
return F_301 ( V_291 , V_277 ) ;
}
static unsigned long F_303 ( struct V_290 * V_291 , int V_277 )
{
unsigned long V_4 = V_291 -> V_337 ;
unsigned long V_399 = V_291 -> V_399 ;
V_399 /= V_4 ;
return V_399 ;
}
unsigned long __weak F_304 ( struct V_290 * V_291 , int V_277 )
{
return F_303 ( V_291 , V_277 ) ;
}
static unsigned long F_305 ( int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
T_2 V_278 , V_400 , V_401 , V_77 ;
V_401 = F_85 ( V_24 -> V_401 ) ;
V_77 = F_85 ( V_24 -> V_402 ) ;
V_278 = F_306 () + ( F_77 ( V_24 ) - V_401 ) ;
if ( F_14 ( V_278 < V_77 ) ) {
V_400 = 0 ;
} else {
V_400 = V_278 - V_77 ;
}
if ( F_14 ( ( T_3 ) V_278 < V_317 ) )
V_278 = V_317 ;
V_278 >>= V_403 ;
return F_126 ( V_400 , V_278 ) ;
}
static void F_307 ( struct V_290 * V_291 , int V_277 )
{
unsigned long V_4 = V_291 -> V_337 ;
unsigned long V_319 = V_317 ;
struct V_306 * V_404 = V_291 -> V_310 ;
if ( ( V_291 -> V_115 & V_405 ) && V_4 > 1 ) {
if ( F_152 ( V_406 ) )
V_319 *= F_304 ( V_291 , V_277 ) ;
else
V_319 *= F_303 ( V_291 , V_277 ) ;
V_319 >>= V_403 ;
}
V_404 -> V_318 -> V_407 = V_319 ;
if ( F_152 ( V_406 ) )
V_319 *= F_302 ( V_291 , V_277 ) ;
else
V_319 *= F_301 ( V_291 , V_277 ) ;
V_319 >>= V_403 ;
V_319 *= F_305 ( V_277 ) ;
V_319 >>= V_403 ;
if ( ! V_319 )
V_319 = 1 ;
F_236 ( V_277 ) -> V_281 = V_319 ;
V_404 -> V_318 -> V_319 = V_319 ;
}
void F_308 ( struct V_290 * V_291 , int V_277 )
{
struct V_290 * V_336 = V_291 -> V_336 ;
struct V_306 * V_309 , * V_404 = V_291 -> V_310 ;
unsigned long V_319 ;
unsigned long V_408 ;
V_408 = F_93 ( V_291 -> V_409 ) ;
V_408 = F_309 ( V_408 , 1UL , V_410 ) ;
V_404 -> V_318 -> V_411 = V_108 + V_408 ;
if ( ! V_336 ) {
F_307 ( V_291 , V_277 ) ;
return;
}
V_319 = 0 ;
if ( V_336 -> V_115 & V_412 ) {
F_254 (cpu, sched_group_cpus(sdg))
V_319 += F_239 ( V_277 ) ;
} else {
V_309 = V_336 -> V_310 ;
do {
V_319 += V_309 -> V_318 -> V_319 ;
V_309 = V_309 -> V_58 ;
} while ( V_309 != V_336 -> V_310 );
}
V_404 -> V_318 -> V_407 = V_404 -> V_318 -> V_319 = V_319 ;
}
static inline int
F_310 ( struct V_290 * V_291 , struct V_306 * V_309 )
{
if ( ! ( V_291 -> V_115 & V_405 ) )
return 0 ;
if ( V_309 -> V_318 -> V_319 * 32 > V_309 -> V_318 -> V_407 * 29 )
return 1 ;
return 0 ;
}
static inline void F_311 ( struct V_413 * V_414 )
{
V_414 -> V_415 = V_414 -> V_416 = 0UL ;
V_414 -> V_417 = V_414 -> V_418 = ~ 0UL ;
}
static inline void
F_312 ( struct V_413 * V_414 ,
unsigned long V_70 , unsigned long V_72 )
{
if ( V_70 > V_414 -> V_415 )
V_414 -> V_415 = V_70 ;
if ( V_414 -> V_417 > V_70 )
V_414 -> V_417 = V_70 ;
if ( V_72 > V_414 -> V_416 )
V_414 -> V_416 = V_72 ;
if ( V_414 -> V_418 > V_72 )
V_414 -> V_418 = V_72 ;
}
static inline int
F_313 ( struct V_419 * V_420 , struct V_413 * V_414 )
{
if ( ( V_414 -> V_415 - V_414 -> V_417 ) >= V_420 -> V_421 &&
( V_414 -> V_416 - V_414 -> V_418 ) > 1 )
return 1 ;
return 0 ;
}
static inline void F_314 ( struct V_354 * V_355 ,
struct V_306 * V_309 , int V_307 ,
int V_315 , struct V_419 * V_420 )
{
struct V_413 V_414 ;
unsigned long V_72 ;
unsigned long V_70 ;
int V_316 ;
F_311 ( & V_414 ) ;
F_256 (i, sched_group_cpus(group), env->cpus) {
struct V_24 * V_24 = F_236 ( V_316 ) ;
V_72 = V_24 -> V_72 ;
if ( V_315 ) {
V_70 = F_238 ( V_316 , V_307 ) ;
} else {
V_70 = F_237 ( V_316 , V_307 ) ;
F_312 ( & V_414 , V_70 , V_72 ) ;
}
V_420 -> V_422 += V_70 ;
V_420 -> V_423 += V_72 ;
V_420 -> V_424 += F_235 ( V_316 ) ;
if ( F_258 ( V_316 ) )
V_420 -> V_425 ++ ;
}
if ( V_315 && ( V_355 -> V_232 != V_383 ||
F_315 ( V_108 , V_309 -> V_318 -> V_411 ) ) )
F_308 ( V_355 -> V_291 , V_355 -> V_357 ) ;
V_420 -> V_426 = V_309 -> V_318 -> V_319 ;
V_420 -> V_314 = ( V_420 -> V_422 * V_317 ) / V_420 -> V_426 ;
if ( V_420 -> V_423 )
V_420 -> V_421 = V_420 -> V_424 / V_420 -> V_423 ;
V_420 -> V_427 = F_313 ( V_420 , & V_414 ) ;
V_420 -> V_428 =
F_316 ( V_420 -> V_426 , V_317 ) ;
if ( ! V_420 -> V_428 )
V_420 -> V_428 = F_310 ( V_355 -> V_291 , V_309 ) ;
V_420 -> V_429 = V_309 -> V_429 ;
if ( V_420 -> V_428 > V_420 -> V_423 )
V_420 -> V_430 = 1 ;
}
static bool F_317 ( struct V_354 * V_355 ,
struct V_387 * V_388 ,
struct V_306 * V_321 ,
struct V_419 * V_420 )
{
if ( V_420 -> V_314 <= V_388 -> V_393 . V_314 )
return false ;
if ( V_420 -> V_423 > V_420 -> V_428 )
return true ;
if ( V_420 -> V_427 )
return true ;
if ( ( V_355 -> V_291 -> V_115 & V_431 ) && V_420 -> V_423 &&
V_355 -> V_357 < F_318 ( V_321 ) ) {
if ( ! V_388 -> V_389 )
return true ;
if ( F_318 ( V_388 -> V_389 ) > F_318 ( V_321 ) )
return true ;
}
return false ;
}
static inline void F_319 ( struct V_354 * V_355 ,
struct V_387 * V_388 )
{
struct V_290 * V_336 = V_355 -> V_291 -> V_336 ;
struct V_306 * V_321 = V_355 -> V_291 -> V_310 ;
struct V_419 V_432 ;
int V_307 , V_433 = 0 ;
if ( V_336 && V_336 -> V_115 & V_434 )
V_433 = 1 ;
V_307 = F_300 ( V_355 -> V_291 , V_355 -> V_232 ) ;
do {
struct V_419 * V_420 = & V_432 ;
int V_315 ;
V_315 = F_253 ( V_355 -> V_357 , F_251 ( V_321 ) ) ;
if ( V_315 ) {
V_388 -> V_390 = V_321 ;
V_420 = & V_388 -> V_435 ;
}
memset ( V_420 , 0 , sizeof( * V_420 ) ) ;
F_314 ( V_355 , V_321 , V_307 , V_315 , V_420 ) ;
if ( V_433 && ! V_315 &&
V_388 -> V_390 && V_388 -> V_435 . V_430 )
V_420 -> V_428 = F_16 ( V_420 -> V_428 , 1U ) ;
V_388 -> V_391 += V_420 -> V_422 ;
V_388 -> V_392 += V_420 -> V_426 ;
if ( ! V_315 && F_317 ( V_355 , V_388 , V_321 , V_420 ) ) {
V_388 -> V_389 = V_321 ;
V_388 -> V_393 = * V_420 ;
}
V_321 = V_321 -> V_58 ;
} while ( V_321 != V_355 -> V_291 -> V_310 );
}
static int F_320 ( struct V_354 * V_355 , struct V_387 * V_388 )
{
int V_436 ;
if ( ! ( V_355 -> V_291 -> V_115 & V_431 ) )
return 0 ;
if ( ! V_388 -> V_389 )
return 0 ;
V_436 = F_318 ( V_388 -> V_389 ) ;
if ( V_355 -> V_357 > V_436 )
return 0 ;
V_355 -> V_313 = F_316 (
V_388 -> V_393 . V_314 * V_388 -> V_393 . V_426 ,
V_317 ) ;
return 1 ;
}
static inline
void F_321 ( struct V_354 * V_355 , struct V_387 * V_388 )
{
unsigned long V_18 , V_437 = 0 , V_438 = 0 ;
unsigned int V_439 = 2 ;
unsigned long V_440 ;
struct V_419 * V_390 , * V_389 ;
V_390 = & V_388 -> V_435 ;
V_389 = & V_388 -> V_393 ;
if ( ! V_390 -> V_423 )
V_390 -> V_421 = F_240 ( V_355 -> V_357 ) ;
else if ( V_389 -> V_421 > V_390 -> V_421 )
V_439 = 1 ;
V_440 =
( V_389 -> V_421 * V_317 ) /
V_389 -> V_426 ;
if ( V_389 -> V_314 + V_440 >=
V_390 -> V_314 + ( V_440 * V_439 ) ) {
V_355 -> V_313 = V_389 -> V_421 ;
return;
}
V_437 += V_389 -> V_426 *
F_16 ( V_389 -> V_421 , V_389 -> V_314 ) ;
V_437 += V_390 -> V_426 *
F_16 ( V_390 -> V_421 , V_390 -> V_314 ) ;
V_437 /= V_317 ;
V_18 = ( V_389 -> V_421 * V_317 ) /
V_389 -> V_426 ;
if ( V_389 -> V_314 > V_18 ) {
V_438 += V_389 -> V_426 *
F_16 ( V_389 -> V_421 ,
V_389 -> V_314 - V_18 ) ;
}
if ( V_389 -> V_314 * V_389 -> V_426 <
V_389 -> V_421 * V_317 ) {
V_18 = ( V_389 -> V_314 * V_389 -> V_426 ) /
V_390 -> V_426 ;
} else {
V_18 = ( V_389 -> V_421 * V_317 ) /
V_390 -> V_426 ;
}
V_438 += V_390 -> V_426 *
F_16 ( V_390 -> V_421 , V_390 -> V_314 + V_18 ) ;
V_438 /= V_317 ;
if ( V_438 > V_437 )
V_355 -> V_313 = V_389 -> V_421 ;
}
static inline void F_322 ( struct V_354 * V_355 , struct V_387 * V_388 )
{
unsigned long V_441 , V_442 = ~ 0UL ;
struct V_419 * V_390 , * V_389 ;
V_390 = & V_388 -> V_435 ;
V_389 = & V_388 -> V_393 ;
if ( V_389 -> V_427 ) {
V_389 -> V_421 =
F_16 ( V_389 -> V_421 , V_388 -> V_314 ) ;
}
if ( V_389 -> V_314 <= V_388 -> V_314 ||
V_390 -> V_314 >= V_388 -> V_314 ) {
V_355 -> V_313 = 0 ;
return F_321 ( V_355 , V_388 ) ;
}
if ( ! V_389 -> V_427 ) {
V_442 =
( V_389 -> V_423 - V_389 -> V_428 ) ;
V_442 *= ( V_443 * V_317 ) ;
V_442 /= V_389 -> V_426 ;
}
V_441 = F_16 ( V_389 -> V_314 - V_388 -> V_314 , V_442 ) ;
V_355 -> V_313 = F_16 (
V_441 * V_389 -> V_426 ,
( V_388 -> V_314 - V_390 -> V_314 ) * V_390 -> V_426
) / V_317 ;
if ( V_355 -> V_313 < V_389 -> V_421 )
return F_321 ( V_355 , V_388 ) ;
}
static struct V_306 * F_323 ( struct V_354 * V_355 )
{
struct V_419 * V_390 , * V_389 ;
struct V_387 V_388 ;
F_299 ( & V_388 ) ;
F_319 ( V_355 , & V_388 ) ;
V_390 = & V_388 . V_435 ;
V_389 = & V_388 . V_393 ;
if ( ( V_355 -> V_232 == V_444 || V_355 -> V_232 == V_383 ) &&
F_320 ( V_355 , & V_388 ) )
return V_388 . V_389 ;
if ( ! V_388 . V_389 || V_389 -> V_423 == 0 )
goto V_445;
V_388 . V_314 = ( V_317 * V_388 . V_391 ) / V_388 . V_392 ;
if ( V_389 -> V_427 )
goto V_446;
if ( V_355 -> V_232 == V_383 && V_390 -> V_430 &&
! V_389 -> V_430 )
goto V_446;
if ( V_390 -> V_314 >= V_389 -> V_314 )
goto V_445;
if ( V_390 -> V_314 >= V_388 . V_314 )
goto V_445;
if ( V_355 -> V_232 == V_444 ) {
if ( ( V_390 -> V_425 < V_389 -> V_425 ) &&
V_389 -> V_423 <= V_389 -> V_429 )
goto V_445;
} else {
if ( 100 * V_389 -> V_314 <=
V_355 -> V_291 -> V_302 * V_390 -> V_314 )
goto V_445;
}
V_446:
F_322 ( V_355 , & V_388 ) ;
return V_388 . V_389 ;
V_445:
V_355 -> V_313 = 0 ;
return NULL ;
}
static struct V_24 * F_324 ( struct V_354 * V_355 ,
struct V_306 * V_309 )
{
struct V_24 * V_389 = NULL , * V_24 ;
unsigned long V_447 = 0 , V_448 = 1 ;
int V_316 ;
F_256 (i, sched_group_cpus(group), env->cpus) {
unsigned long V_319 = F_239 ( V_316 ) ;
unsigned long V_449 = F_316 ( V_319 ,
V_317 ) ;
unsigned long V_286 ;
if ( ! V_449 )
V_449 = F_310 ( V_355 -> V_291 , V_309 ) ;
V_24 = F_236 ( V_316 ) ;
V_286 = F_235 ( V_316 ) ;
if ( V_449 && V_24 -> V_72 == 1 && V_286 > V_355 -> V_313 )
continue;
if ( V_286 * V_448 > V_447 * V_319 ) {
V_447 = V_286 ;
V_448 = V_319 ;
V_389 = V_24 ;
}
}
return V_389 ;
}
static int F_325 ( struct V_354 * V_355 )
{
struct V_290 * V_291 = V_355 -> V_291 ;
if ( V_355 -> V_232 == V_383 ) {
if ( ( V_291 -> V_115 & V_431 ) && V_355 -> V_236 > V_355 -> V_357 )
return 1 ;
}
return F_14 ( V_291 -> V_368 > V_291 -> V_369 + 2 ) ;
}
static int F_326 ( struct V_354 * V_355 )
{
struct V_306 * V_321 = V_355 -> V_291 -> V_310 ;
struct V_450 * V_451 , * V_452 ;
int V_277 , V_453 = - 1 ;
if ( V_355 -> V_232 == V_383 )
return 1 ;
V_451 = F_251 ( V_321 ) ;
V_452 = F_327 ( V_321 ) ;
F_256 (cpu, sg_cpus, env->cpus) {
if ( ! F_253 ( V_277 , V_452 ) || ! F_258 ( V_277 ) )
continue;
V_453 = V_277 ;
break;
}
if ( V_453 == - 1 )
V_453 = F_328 ( V_321 ) ;
return V_453 == V_355 -> V_357 ;
}
static int F_329 ( int V_295 , struct V_24 * V_179 ,
struct V_290 * V_291 , enum V_394 V_232 ,
int * V_454 )
{
int V_455 , V_456 , V_457 = 0 ;
struct V_306 * V_309 ;
struct V_24 * V_389 ;
unsigned long V_115 ;
struct V_450 * V_8 = F_330 ( V_458 ) ;
struct V_354 V_355 = {
. V_291 = V_291 ,
. V_357 = V_295 ,
. V_358 = V_179 ,
. V_363 = F_251 ( V_291 -> V_310 ) ,
. V_232 = V_232 ,
. V_379 = V_380 ,
. V_8 = V_8 ,
} ;
if ( V_232 == V_383 )
V_355 . V_363 = NULL ;
F_331 ( V_8 , V_459 ) ;
F_150 ( V_291 , V_460 [ V_232 ] ) ;
V_461:
if ( ! F_326 ( & V_355 ) ) {
* V_454 = 0 ;
goto V_445;
}
V_309 = F_323 ( & V_355 ) ;
if ( ! V_309 ) {
F_150 ( V_291 , V_462 [ V_232 ] ) ;
goto V_445;
}
V_389 = F_324 ( & V_355 , V_309 ) ;
if ( ! V_389 ) {
F_150 ( V_291 , V_463 [ V_232 ] ) ;
goto V_445;
}
F_273 ( V_389 == V_355 . V_358 ) ;
F_69 ( V_291 , V_464 [ V_232 ] , V_355 . V_313 ) ;
V_455 = 0 ;
if ( V_389 -> V_72 > 1 ) {
V_355 . V_115 |= V_366 ;
V_355 . V_236 = V_389 -> V_277 ;
V_355 . V_356 = V_389 ;
V_355 . V_378 = F_16 ( V_465 , V_389 -> V_72 ) ;
V_466:
F_332 ( V_115 ) ;
F_333 ( V_355 . V_358 , V_389 ) ;
V_456 = F_288 ( & V_355 ) ;
V_455 += V_456 ;
F_334 ( V_355 . V_358 , V_389 ) ;
F_335 ( V_115 ) ;
if ( V_456 && V_355 . V_357 != F_180 () )
F_336 ( V_355 . V_357 ) ;
if ( V_355 . V_115 & V_381 ) {
V_355 . V_115 &= ~ V_381 ;
goto V_466;
}
if ( ( V_355 . V_115 & V_364 ) && V_355 . V_313 > 0 ) {
V_355 . V_358 = F_236 ( V_355 . V_365 ) ;
V_355 . V_357 = V_355 . V_365 ;
V_355 . V_115 &= ~ V_364 ;
V_355 . V_377 = 0 ;
V_355 . V_379 = V_380 ;
F_337 ( V_355 . V_357 , V_355 . V_8 ) ;
goto V_466;
}
if ( F_14 ( V_355 . V_115 & V_366 ) ) {
F_337 ( F_27 ( V_389 ) , V_8 ) ;
if ( ! F_338 ( V_8 ) ) {
V_355 . V_377 = 0 ;
V_355 . V_379 = V_380 ;
goto V_461;
}
goto V_445;
}
}
if ( ! V_455 ) {
F_150 ( V_291 , V_467 [ V_232 ] ) ;
if ( V_232 != V_383 )
V_291 -> V_368 ++ ;
if ( F_325 ( & V_355 ) ) {
F_295 ( & V_389 -> V_230 , V_115 ) ;
if ( ! F_253 ( V_295 ,
F_252 ( V_389 -> V_45 ) ) ) {
F_296 ( & V_389 -> V_230 ,
V_115 ) ;
V_355 . V_115 |= V_366 ;
goto V_468;
}
if ( ! V_389 -> V_457 ) {
V_389 -> V_457 = 1 ;
V_389 -> V_469 = V_295 ;
V_457 = 1 ;
}
F_296 ( & V_389 -> V_230 , V_115 ) ;
if ( V_457 ) {
F_339 ( F_27 ( V_389 ) ,
V_470 , V_389 ,
& V_389 -> V_471 ) ;
}
V_291 -> V_368 = V_291 -> V_369 + 1 ;
}
} else
V_291 -> V_368 = 0 ;
if ( F_12 ( ! V_457 ) ) {
V_291 -> V_409 = V_291 -> V_472 ;
} else {
if ( V_291 -> V_409 < V_291 -> V_473 )
V_291 -> V_409 *= 2 ;
}
goto V_133;
V_445:
F_150 ( V_291 , V_474 [ V_232 ] ) ;
V_291 -> V_368 = 0 ;
V_468:
if ( ( ( V_355 . V_115 & V_366 ) &&
V_291 -> V_409 < V_475 ) ||
( V_291 -> V_409 < V_291 -> V_473 ) )
V_291 -> V_409 *= 2 ;
V_455 = 0 ;
V_133:
return V_455 ;
}
void F_340 ( int V_295 , struct V_24 * V_179 )
{
struct V_290 * V_291 ;
int V_476 = 0 ;
unsigned long V_477 = V_108 + V_283 ;
V_179 -> V_478 = F_77 ( V_179 ) ;
if ( V_179 -> V_479 < V_360 )
return;
F_186 ( & V_179 -> V_230 ) ;
F_294 ( V_295 ) ;
F_194 () ;
F_265 (this_cpu, sd) {
unsigned long V_408 ;
int V_454 = 1 ;
if ( ! ( V_291 -> V_115 & V_332 ) )
continue;
if ( V_291 -> V_115 & V_480 ) {
V_476 = F_329 ( V_295 , V_179 ,
V_291 , V_383 ,
& V_454 ) ;
}
V_408 = F_93 ( V_291 -> V_409 ) ;
if ( F_92 ( V_477 , V_291 -> V_481 + V_408 ) )
V_477 = V_291 -> V_481 + V_408 ;
if ( V_476 ) {
V_179 -> V_478 = 0 ;
break;
}
}
F_196 () ;
F_184 ( & V_179 -> V_230 ) ;
if ( V_476 || F_92 ( V_108 , V_179 -> V_477 ) ) {
V_179 -> V_477 = V_477 ;
}
}
static int V_470 ( void * V_240 )
{
struct V_24 * V_482 = V_240 ;
int V_436 = F_27 ( V_482 ) ;
int V_483 = V_482 -> V_469 ;
struct V_24 * V_484 = F_236 ( V_483 ) ;
struct V_290 * V_291 ;
F_341 ( & V_482 -> V_230 ) ;
if ( F_14 ( V_436 != F_180 () ||
! V_482 -> V_457 ) )
goto V_253;
if ( V_482 -> V_72 <= 1 )
goto V_253;
F_273 ( V_482 == V_484 ) ;
F_342 ( V_482 , V_484 ) ;
F_194 () ;
F_265 (target_cpu, sd) {
if ( ( V_291 -> V_115 & V_332 ) &&
F_253 ( V_436 , F_266 ( V_291 ) ) )
break;
}
if ( F_12 ( V_291 ) ) {
struct V_354 V_355 = {
. V_291 = V_291 ,
. V_357 = V_483 ,
. V_358 = V_484 ,
. V_236 = V_482 -> V_277 ,
. V_356 = V_482 ,
. V_232 = V_444 ,
} ;
F_150 ( V_291 , V_485 ) ;
if ( F_286 ( & V_355 ) )
F_150 ( V_291 , V_486 ) ;
else
F_150 ( V_291 , V_487 ) ;
}
F_196 () ;
F_343 ( V_482 , V_484 ) ;
V_253:
V_482 -> V_457 = 0 ;
F_344 ( & V_482 -> V_230 ) ;
return 0 ;
}
static inline int F_345 ( int V_488 )
{
int V_489 = F_346 ( V_490 . V_491 ) ;
if ( V_489 < V_492 && F_258 ( V_489 ) )
return V_489 ;
return V_492 ;
}
static void F_347 ( int V_277 )
{
int V_493 ;
V_490 . V_477 ++ ;
V_493 = F_345 ( V_277 ) ;
if ( V_493 >= V_492 )
return;
if ( F_348 ( V_494 , F_349 ( V_493 ) ) )
return;
F_350 ( V_493 ) ;
return;
}
static inline void F_351 ( int V_277 )
{
if ( F_14 ( F_352 ( V_495 , F_349 ( V_277 ) ) ) ) {
F_337 ( V_277 , V_490 . V_491 ) ;
F_353 ( & V_490 . V_496 ) ;
F_354 ( V_495 , F_349 ( V_277 ) ) ;
}
}
static inline void F_355 ( void )
{
struct V_290 * V_291 ;
F_194 () ;
V_291 = F_356 ( V_179 () -> V_291 ) ;
if ( ! V_291 || ! V_291 -> V_497 )
goto V_334;
V_291 -> V_497 = 0 ;
for (; V_291 ; V_291 = V_291 -> V_34 )
F_357 ( & V_291 -> V_310 -> V_318 -> V_498 ) ;
V_334:
F_196 () ;
}
void F_358 ( void )
{
struct V_290 * V_291 ;
F_194 () ;
V_291 = F_356 ( V_179 () -> V_291 ) ;
if ( ! V_291 || V_291 -> V_497 )
goto V_334;
V_291 -> V_497 = 1 ;
for (; V_291 ; V_291 = V_291 -> V_34 )
F_353 ( & V_291 -> V_310 -> V_318 -> V_498 ) ;
V_334:
F_196 () ;
}
void F_359 ( int V_277 )
{
if ( ! F_360 ( V_277 ) )
return;
if ( F_352 ( V_495 , F_349 ( V_277 ) ) )
return;
F_361 ( V_277 , V_490 . V_491 ) ;
F_357 ( & V_490 . V_496 ) ;
F_362 ( V_495 , F_349 ( V_277 ) ) ;
}
static int F_363 ( struct V_499 * V_500 ,
unsigned long V_501 , void * V_502 )
{
switch ( V_501 & ~ V_503 ) {
case V_504 :
F_351 ( F_180 () ) ;
return V_505 ;
default:
return V_506 ;
}
}
void F_364 ( void )
{
V_410 = V_283 * F_6 () / 10 ;
}
static void F_365 ( int V_277 , enum V_394 V_232 )
{
int V_454 = 1 ;
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_408 ;
struct V_290 * V_291 ;
unsigned long V_477 = V_108 + 60 * V_283 ;
int V_507 = 0 ;
int V_508 ;
F_294 ( V_277 ) ;
F_194 () ;
F_265 (cpu, sd) {
if ( ! ( V_291 -> V_115 & V_332 ) )
continue;
V_408 = V_291 -> V_409 ;
if ( V_232 != V_444 )
V_408 *= V_291 -> V_509 ;
V_408 = F_93 ( V_408 ) ;
V_408 = F_309 ( V_408 , 1UL , V_410 ) ;
V_508 = V_291 -> V_115 & V_510 ;
if ( V_508 ) {
if ( ! F_366 ( & V_511 ) )
goto V_133;
}
if ( F_315 ( V_108 , V_291 -> V_481 + V_408 ) ) {
if ( F_329 ( V_277 , V_24 , V_291 , V_232 , & V_454 ) ) {
V_232 = F_258 ( V_277 ) ? V_444 : V_395 ;
}
V_291 -> V_481 = V_108 ;
}
if ( V_508 )
F_367 ( & V_511 ) ;
V_133:
if ( F_92 ( V_477 , V_291 -> V_481 + V_408 ) ) {
V_477 = V_291 -> V_481 + V_408 ;
V_507 = 1 ;
}
if ( ! V_454 )
break;
}
F_196 () ;
if ( F_12 ( V_507 ) )
V_24 -> V_477 = V_477 ;
}
static void F_368 ( int V_295 , enum V_394 V_232 )
{
struct V_24 * V_179 = F_236 ( V_295 ) ;
struct V_24 * V_24 ;
int V_453 ;
if ( V_232 != V_444 ||
! F_352 ( V_494 , F_349 ( V_295 ) ) )
goto V_113;
F_254 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_453 == V_295 || ! F_258 ( V_453 ) )
continue;
if ( F_369 () )
break;
V_24 = F_236 ( V_453 ) ;
F_341 ( & V_24 -> V_230 ) ;
F_198 ( V_24 ) ;
F_370 ( V_24 ) ;
F_344 ( & V_24 -> V_230 ) ;
F_365 ( V_453 , V_444 ) ;
if ( F_92 ( V_179 -> V_477 , V_24 -> V_477 ) )
V_179 -> V_477 = V_24 -> V_477 ;
}
V_490 . V_477 = V_179 -> V_477 ;
V_113:
F_354 ( V_494 , F_349 ( V_295 ) ) ;
}
static inline int F_371 ( struct V_24 * V_24 , int V_277 )
{
unsigned long V_86 = V_108 ;
struct V_290 * V_291 ;
if ( F_14 ( F_258 ( V_277 ) ) )
return 0 ;
F_355 () ;
F_351 ( V_277 ) ;
if ( F_12 ( ! F_129 ( & V_490 . V_496 ) ) )
return 0 ;
if ( F_95 ( V_86 , V_490 . V_477 ) )
return 0 ;
if ( V_24 -> V_72 >= 2 )
goto V_512;
F_194 () ;
F_265 (cpu, sd) {
struct V_306 * V_321 = V_291 -> V_310 ;
struct V_513 * V_318 = V_321 -> V_318 ;
int V_514 = F_129 ( & V_318 -> V_498 ) ;
if ( V_291 -> V_115 & V_515 && V_514 > 1 )
goto V_516;
if ( V_291 -> V_115 & V_431 && V_514 != V_321 -> V_429
&& ( F_263 ( V_490 . V_491 ,
F_266 ( V_291 ) ) < V_277 ) )
goto V_516;
if ( ! ( V_291 -> V_115 & ( V_515 | V_431 ) ) )
break;
}
F_196 () ;
return 0 ;
V_516:
F_196 () ;
V_512:
return 1 ;
}
static void F_368 ( int V_295 , enum V_394 V_232 ) { }
static void F_372 ( struct V_517 * V_518 )
{
int V_295 = F_180 () ;
struct V_24 * V_179 = F_236 ( V_295 ) ;
enum V_394 V_232 = V_179 -> F_340 ?
V_444 : V_395 ;
F_365 ( V_295 , V_232 ) ;
F_368 ( V_295 , V_232 ) ;
}
static inline int F_373 ( int V_277 )
{
return ! F_374 ( F_236 ( V_277 ) -> V_291 ) ;
}
void F_375 ( struct V_24 * V_24 , int V_277 )
{
if ( F_315 ( V_108 , V_24 -> V_477 ) &&
F_12 ( ! F_373 ( V_277 ) ) )
F_376 ( V_519 ) ;
#ifdef F_377
if ( F_371 ( V_24 , V_277 ) && F_12 ( ! F_373 ( V_277 ) ) )
F_347 ( V_277 ) ;
#endif
}
static void F_378 ( struct V_24 * V_24 )
{
F_8 () ;
}
static void F_379 ( struct V_24 * V_24 )
{
F_8 () ;
F_222 ( V_24 ) ;
}
static void F_380 ( struct V_24 * V_24 , struct V_26 * V_45 , int V_209 )
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
static void F_381 ( struct V_26 * V_29 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 = & V_29 -> V_28 , * V_45 ;
int V_295 = F_180 () ;
struct V_24 * V_24 = V_179 () ;
unsigned long V_115 ;
F_295 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
V_25 = F_23 ( V_99 ) ;
V_45 = V_25 -> V_45 ;
F_194 () ;
F_382 ( V_29 , V_295 ) ;
F_196 () ;
F_70 ( V_25 ) ;
if ( V_45 )
V_28 -> V_41 = V_45 -> V_41 ;
F_151 ( V_25 , V_28 , 1 ) ;
if ( V_520 && V_45 && F_41 ( V_45 , V_28 ) ) {
F_383 ( V_45 -> V_41 , V_28 -> V_41 ) ;
F_162 ( V_24 -> V_45 ) ;
}
V_28 -> V_41 -= V_25 -> F_40 ;
F_296 ( & V_24 -> V_230 , V_115 ) ;
}
static void
F_384 ( struct V_24 * V_24 , struct V_26 * V_29 , int V_521 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 ) {
if ( V_29 -> V_522 > V_521 )
F_162 ( V_24 -> V_45 ) ;
} else
F_282 ( V_24 , V_29 , 0 ) ;
}
static void F_385 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
struct V_27 * V_28 = & V_29 -> V_28 ;
struct V_25 * V_25 = F_24 ( V_28 ) ;
if ( ! V_28 -> V_76 && V_29 -> V_201 != V_523 ) {
F_151 ( V_25 , V_28 , 0 ) ;
V_28 -> V_41 -= V_25 -> F_40 ;
}
#ifdef F_108
if ( V_28 -> V_77 . V_78 ) {
F_121 ( V_28 ) ;
F_132 ( V_25 , V_28 -> V_77 . V_163 ) ;
}
#endif
}
static void F_386 ( struct V_24 * V_24 , struct V_26 * V_29 )
{
if ( ! V_29 -> V_28 . V_76 )
return;
if ( V_24 -> V_45 == V_29 )
F_162 ( V_24 -> V_45 ) ;
else
F_282 ( V_24 , V_29 , 0 ) ;
}
static void F_387 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = & V_24 -> V_45 -> V_28 ;
F_36 (se) {
struct V_25 * V_25 = F_24 ( V_28 ) ;
F_163 ( V_25 , V_28 ) ;
F_75 ( V_25 , 0 ) ;
}
}
void F_388 ( struct V_25 * V_25 )
{
V_25 -> V_51 = V_524 ;
V_25 -> F_40 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_44
V_25 -> V_48 = V_25 -> F_40 ;
#endif
#ifdef F_108
F_389 ( & V_25 -> V_162 , 1 ) ;
F_390 ( & V_25 -> V_176 , 0 ) ;
#endif
}
static void F_391 ( struct V_26 * V_29 , int V_76 )
{
struct V_25 * V_25 ;
if ( ! V_76 && ( ! V_29 -> V_28 . V_84 || V_29 -> V_201 == V_525 ) )
V_76 = 1 ;
if ( ! V_76 )
V_29 -> V_28 . V_41 -= F_24 ( & V_29 -> V_28 ) -> F_40 ;
F_392 ( V_29 , F_248 ( V_29 ) ) ;
if ( ! V_76 ) {
V_25 = F_24 ( & V_29 -> V_28 ) ;
V_29 -> V_28 . V_41 += V_25 -> F_40 ;
#ifdef F_108
V_29 -> V_28 . V_77 . V_78 = F_122 ( & V_25 -> V_162 ) ;
V_25 -> V_167 += V_29 -> V_28 . V_77 . V_163 ;
#endif
}
}
void F_393 ( struct V_138 * V_33 )
{
int V_316 ;
F_221 ( F_182 ( V_33 ) ) ;
F_394 (i) {
if ( V_33 -> V_25 )
F_395 ( V_33 -> V_25 [ V_316 ] ) ;
if ( V_33 -> V_28 )
F_395 ( V_33 -> V_28 [ V_316 ] ) ;
}
F_395 ( V_33 -> V_25 ) ;
F_395 ( V_33 -> V_28 ) ;
}
int F_396 ( struct V_138 * V_33 , struct V_138 * V_34 )
{
struct V_25 * V_25 ;
struct V_27 * V_28 ;
int V_316 ;
V_33 -> V_25 = F_397 ( sizeof( V_25 ) * V_492 , V_526 ) ;
if ( ! V_33 -> V_25 )
goto V_527;
V_33 -> V_28 = F_397 ( sizeof( V_28 ) * V_492 , V_526 ) ;
if ( ! V_33 -> V_28 )
goto V_527;
V_33 -> V_142 = V_71 ;
F_215 ( F_182 ( V_33 ) ) ;
F_394 (i) {
V_25 = F_398 ( sizeof( struct V_25 ) ,
V_526 , F_399 ( V_316 ) ) ;
if ( ! V_25 )
goto V_527;
V_28 = F_398 ( sizeof( struct V_27 ) ,
V_526 , F_399 ( V_316 ) ) ;
if ( ! V_28 )
goto V_528;
F_388 ( V_25 ) ;
F_400 ( V_33 , V_25 , V_28 , V_316 , V_34 -> V_28 [ V_316 ] ) ;
}
return 1 ;
V_528:
F_395 ( V_25 ) ;
V_527:
return 0 ;
}
void F_401 ( struct V_138 * V_33 , int V_277 )
{
struct V_24 * V_24 = F_236 ( V_277 ) ;
unsigned long V_115 ;
if ( ! V_33 -> V_25 [ V_277 ] -> V_32 )
return;
F_295 ( & V_24 -> V_230 , V_115 ) ;
F_31 ( V_33 -> V_25 [ V_277 ] ) ;
F_296 ( & V_24 -> V_230 , V_115 ) ;
}
void F_400 ( struct V_138 * V_33 , struct V_25 * V_25 ,
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
int F_402 ( struct V_138 * V_33 , unsigned long V_142 )
{
int V_316 ;
unsigned long V_115 ;
if ( ! V_33 -> V_28 [ 0 ] )
return - V_529 ;
V_142 = F_309 ( V_142 , F_130 ( V_143 ) , F_130 ( V_530 ) ) ;
F_403 ( & V_531 ) ;
if ( V_33 -> V_142 == V_142 )
goto V_323;
V_33 -> V_142 = V_142 ;
F_394 (i) {
struct V_24 * V_24 = F_236 ( V_316 ) ;
struct V_27 * V_28 ;
V_28 = V_33 -> V_28 [ V_316 ] ;
F_295 ( & V_24 -> V_230 , V_115 ) ;
F_198 ( V_24 ) ;
F_36 (se)
F_116 ( F_25 ( V_28 ) ) ;
F_296 ( & V_24 -> V_230 , V_115 ) ;
}
V_323:
F_404 ( & V_531 ) ;
return 0 ;
}
void F_393 ( struct V_138 * V_33 ) { }
int F_396 ( struct V_138 * V_33 , struct V_138 * V_34 )
{
return 1 ;
}
void F_401 ( struct V_138 * V_33 , int V_277 ) { }
static unsigned int F_405 ( struct V_24 * V_24 , struct V_26 * V_532 )
{
struct V_27 * V_28 = & V_532 -> V_28 ;
unsigned int V_533 = 0 ;
if ( V_24 -> V_40 . V_70 . V_4 )
V_533 = F_406 ( F_62 ( F_24 ( V_28 ) , V_28 ) ) ;
return V_533 ;
}
void F_407 ( struct V_534 * V_535 , int V_277 )
{
struct V_25 * V_25 ;
F_194 () ;
F_223 (cpu_rq(cpu), cfs_rq)
F_408 ( V_535 , V_277 , V_25 ) ;
F_196 () ;
}
T_11 void F_409 ( void )
{
#ifdef F_108
F_410 ( V_519 , F_372 ) ;
#ifdef F_377
V_490 . V_477 = V_108 ;
F_411 ( & V_490 . V_491 , V_536 ) ;
F_412 ( F_363 , 0 ) ;
#endif
#endif
}
