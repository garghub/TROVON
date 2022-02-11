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
}
}
static inline void F_27 ( struct V_23 * V_23 )
{
if ( V_23 -> V_30 ) {
F_28 ( & V_23 -> V_33 ) ;
V_23 -> V_30 = 0 ;
}
}
static inline int
F_29 ( struct V_25 * V_26 , struct V_25 * V_34 )
{
if ( V_26 -> V_23 == V_34 -> V_23 )
return 1 ;
return 0 ;
}
static inline struct V_25 * F_30 ( struct V_25 * V_26 )
{
return V_26 -> V_32 ;
}
static inline int F_31 ( struct V_25 * V_26 )
{
int V_35 = 0 ;
F_32 (se)
V_35 ++ ;
return V_35 ;
}
static void
F_33 ( struct V_25 * * V_26 , struct V_25 * * V_34 )
{
int V_36 , V_37 ;
V_36 = F_31 ( * V_26 ) ;
V_37 = F_31 ( * V_34 ) ;
while ( V_36 > V_37 ) {
V_36 -- ;
* V_26 = F_30 ( * V_26 ) ;
}
while ( V_37 > V_36 ) {
V_37 -- ;
* V_34 = F_30 ( * V_34 ) ;
}
while ( ! F_29 ( * V_26 , * V_34 ) ) {
* V_26 = F_30 ( * V_26 ) ;
* V_34 = F_30 ( * V_34 ) ;
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
return & F_34 ( V_27 ) -> V_38 ;
}
static inline struct V_23 * F_21 ( struct V_25 * V_26 )
{
struct V_24 * V_27 = F_15 ( V_26 ) ;
struct V_22 * V_22 = F_34 ( V_27 ) ;
return & V_22 -> V_38 ;
}
static inline struct V_23 * F_22 ( struct V_25 * V_28 )
{
return NULL ;
}
static inline void F_23 ( struct V_23 * V_23 )
{
}
static inline void F_27 ( struct V_23 * V_23 )
{
}
static inline int
F_29 ( struct V_25 * V_26 , struct V_25 * V_34 )
{
return 1 ;
}
static inline struct V_25 * F_30 ( struct V_25 * V_26 )
{
return NULL ;
}
static inline void
F_33 ( struct V_25 * * V_26 , struct V_25 * * V_34 )
{
}
static inline T_2 F_35 ( T_2 V_39 , T_2 V_40 )
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
static inline int F_36 ( struct V_25 * V_42 ,
struct V_25 * V_43 )
{
return ( T_3 ) ( V_42 -> V_40 - V_43 -> V_40 ) < 0 ;
}
static void F_37 ( struct V_23 * V_23 )
{
T_2 V_40 = V_23 -> V_39 ;
if ( V_23 -> V_44 )
V_40 = V_23 -> V_44 -> V_40 ;
if ( V_23 -> V_45 ) {
struct V_25 * V_26 = F_38 ( V_23 -> V_45 ,
struct V_25 ,
V_46 ) ;
if ( ! V_23 -> V_44 )
V_40 = V_26 -> V_40 ;
else
V_40 = V_39 ( V_40 , V_26 -> V_40 ) ;
}
V_23 -> V_39 = F_35 ( V_23 -> V_39 , V_40 ) ;
#ifndef F_39
F_40 () ;
V_23 -> V_47 = V_23 -> V_39 ;
#endif
}
static void F_41 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
struct V_48 * * V_49 = & V_23 -> V_50 . V_48 ;
struct V_48 * V_32 = NULL ;
struct V_25 * V_51 ;
int V_52 = 1 ;
while ( * V_49 ) {
V_32 = * V_49 ;
V_51 = F_38 ( V_32 , struct V_25 , V_46 ) ;
if ( F_36 ( V_26 , V_51 ) ) {
V_49 = & V_32 -> V_53 ;
} else {
V_49 = & V_32 -> V_54 ;
V_52 = 0 ;
}
}
if ( V_52 )
V_23 -> V_45 = & V_26 -> V_46 ;
F_42 ( & V_26 -> V_46 , V_32 , V_49 ) ;
F_43 ( & V_26 -> V_46 , & V_23 -> V_50 ) ;
}
static void F_44 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_45 == & V_26 -> V_46 ) {
struct V_48 * V_55 ;
V_55 = F_45 ( & V_26 -> V_46 ) ;
V_23 -> V_45 = V_55 ;
}
F_46 ( & V_26 -> V_46 , & V_23 -> V_50 ) ;
}
struct V_25 * F_47 ( struct V_23 * V_23 )
{
struct V_48 * V_56 = V_23 -> V_45 ;
if ( ! V_56 )
return NULL ;
return F_38 ( V_56 , struct V_25 , V_46 ) ;
}
static struct V_25 * F_48 ( struct V_25 * V_26 )
{
struct V_48 * V_57 = F_45 ( & V_26 -> V_46 ) ;
if ( ! V_57 )
return NULL ;
return F_38 ( V_57 , struct V_25 , V_46 ) ;
}
struct V_25 * F_49 ( struct V_23 * V_23 )
{
struct V_48 * V_58 = F_50 ( & V_23 -> V_50 ) ;
if ( ! V_58 )
return NULL ;
return F_38 ( V_58 , struct V_25 , V_46 ) ;
}
int F_51 ( struct V_59 * V_60 , int V_61 ,
void T_4 * V_62 , T_5 * V_63 ,
T_6 * V_64 )
{
int V_65 = F_52 ( V_60 , V_61 , V_62 , V_63 , V_64 ) ;
int V_2 = F_1 () ;
if ( V_65 || ! V_61 )
return V_65 ;
V_66 = F_53 ( V_67 ,
V_68 ) ;
#define F_54 ( T_1 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_54 ( V_7 ) ;
F_54 ( V_8 ) ;
F_54 ( V_9 ) ;
#undef F_54
return 0 ;
}
static inline unsigned long
F_55 ( unsigned long V_41 , struct V_25 * V_26 )
{
if ( F_11 ( V_26 -> V_69 . V_11 != V_70 ) )
V_41 = F_8 ( V_41 , V_70 , & V_26 -> V_69 ) ;
return V_41 ;
}
static T_2 F_56 ( unsigned long V_71 )
{
T_2 V_72 = V_67 ;
unsigned long V_73 = V_66 ;
if ( F_11 ( V_71 > V_73 ) ) {
V_72 = V_68 ;
V_72 *= V_71 ;
}
return V_72 ;
}
static T_2 F_57 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
T_2 V_74 = F_56 ( V_23 -> V_71 + ! V_26 -> V_75 ) ;
F_32 (se) {
struct V_12 * V_69 ;
struct V_12 V_13 ;
V_23 = F_21 ( V_26 ) ;
V_69 = & V_23 -> V_69 ;
if ( F_11 ( ! V_26 -> V_75 ) ) {
V_13 = V_23 -> V_69 ;
F_58 ( & V_13 , V_26 -> V_69 . V_11 ) ;
V_69 = & V_13 ;
}
V_74 = F_8 ( V_74 , V_26 -> V_69 . V_11 , V_69 ) ;
}
return V_74 ;
}
static T_2 F_59 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
return F_55 ( F_57 ( V_23 , V_26 ) , V_26 ) ;
}
static inline void
F_60 ( struct V_23 * V_23 , struct V_25 * V_44 ,
unsigned long V_10 )
{
unsigned long V_76 ;
F_61 ( V_44 -> V_77 . V_78 ,
F_62 ( ( T_2 ) V_10 , V_44 -> V_77 . V_78 ) ) ;
V_44 -> V_79 += V_10 ;
F_63 ( V_23 , V_80 , V_10 ) ;
V_76 = F_55 ( V_10 , V_44 ) ;
V_44 -> V_40 += V_76 ;
F_37 ( V_23 ) ;
#if V_81 V_82 && V_81 V_83
V_23 -> V_84 += V_10 ;
#endif
}
static void F_64 ( struct V_23 * V_23 )
{
struct V_25 * V_44 = V_23 -> V_44 ;
T_2 V_85 = F_14 ( V_23 ) -> V_86 ;
unsigned long V_10 ;
if ( F_11 ( ! V_44 ) )
return;
V_10 = ( unsigned long ) ( V_85 - V_44 -> V_87 ) ;
if ( ! V_10 )
return;
F_60 ( V_23 , V_44 , V_10 ) ;
V_44 -> V_87 = V_85 ;
if ( F_18 ( V_44 ) ) {
struct V_24 * V_88 = F_15 ( V_44 ) ;
F_65 ( V_88 , V_10 , V_44 -> V_40 ) ;
F_66 ( V_88 , V_10 ) ;
F_67 ( V_88 , V_10 ) ;
}
F_68 ( V_23 , V_10 ) ;
}
static inline void
F_69 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_61 ( V_26 -> V_77 . V_89 , F_14 ( V_23 ) -> clock ) ;
}
static void F_70 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_44 )
F_69 ( V_23 , V_26 ) ;
}
static void
F_71 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_61 ( V_26 -> V_77 . V_90 , F_62 ( V_26 -> V_77 . V_90 ,
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_89 ) ) ;
F_61 ( V_26 -> V_77 . V_91 , V_26 -> V_77 . V_91 + 1 ) ;
F_61 ( V_26 -> V_77 . V_92 , V_26 -> V_77 . V_92 +
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_89 ) ;
#ifdef F_72
if ( F_18 ( V_26 ) ) {
F_73 ( F_15 ( V_26 ) ,
F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_89 ) ;
}
#endif
F_61 ( V_26 -> V_77 . V_89 , 0 ) ;
}
static inline void
F_74 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 != V_23 -> V_44 )
F_71 ( V_23 , V_26 ) ;
}
static inline void
F_75 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
V_26 -> V_87 = F_14 ( V_23 ) -> V_86 ;
}
static void
F_76 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_58 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_30 ( V_26 ) )
F_58 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
#ifdef V_82
if ( F_18 ( V_26 ) )
F_77 ( & V_26 -> V_93 , & F_14 ( V_23 ) -> V_94 ) ;
#endif
V_23 -> V_71 ++ ;
}
static void
F_78 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_79 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_30 ( V_26 ) )
F_79 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( F_18 ( V_26 ) )
F_80 ( & V_26 -> V_93 ) ;
V_23 -> V_71 -- ;
}
static void F_81 ( struct V_23 * V_23 ,
int V_95 )
{
struct V_96 * V_31 = V_23 -> V_31 ;
long V_97 ;
V_97 = F_82 ( V_23 -> V_97 , V_23 -> V_98 + 1 ) ;
V_97 -= V_23 -> V_99 ;
if ( V_95 || abs ( V_97 ) > V_23 -> V_99 / 8 ) {
F_83 ( V_97 , & V_31 -> V_12 ) ;
V_23 -> V_99 += V_97 ;
}
}
static void F_84 ( struct V_23 * V_23 , int V_95 )
{
T_2 V_72 = V_100 ;
T_2 V_85 , V_41 ;
unsigned long V_69 = V_23 -> V_69 . V_11 ;
if ( V_23 -> V_31 == & V_101 || F_85 ( V_23 ) )
return;
V_85 = F_14 ( V_23 ) -> V_86 ;
V_41 = V_85 - V_23 -> V_102 ;
if ( V_23 -> V_102 > V_23 -> V_103 &&
V_85 - V_23 -> V_103 > 4 * V_72 ) {
V_23 -> V_98 = 0 ;
V_23 -> V_97 = 0 ;
V_41 = V_72 - 1 ;
}
V_23 -> V_102 = V_85 ;
V_23 -> V_84 = 0 ;
V_23 -> V_98 += V_41 ;
if ( V_69 ) {
V_23 -> V_103 = V_85 ;
V_23 -> V_97 += V_41 * V_69 ;
}
if ( V_95 || V_23 -> V_98 > V_72
|| ! V_23 -> V_98 )
F_81 ( V_23 , V_95 ) ;
while ( V_23 -> V_98 > V_72 ) {
asm("" : "+rm" (cfs_rq->load_period));
V_23 -> V_98 /= 2 ;
V_23 -> V_97 /= 2 ;
}
if ( ! V_23 -> V_44 && ! V_23 -> V_71 && ! V_23 -> V_97 )
F_27 ( V_23 ) ;
}
static inline long F_86 ( struct V_96 * V_31 , struct V_23 * V_23 )
{
long V_104 ;
V_104 = F_87 ( & V_31 -> V_12 ) ;
V_104 -= V_23 -> V_99 ;
V_104 += V_23 -> V_69 . V_11 ;
return V_104 ;
}
static long F_88 ( struct V_23 * V_23 , struct V_96 * V_31 )
{
long V_104 , V_69 , V_105 ;
V_104 = F_86 ( V_31 , V_23 ) ;
V_69 = V_23 -> V_69 . V_11 ;
V_105 = ( V_31 -> V_105 * V_69 ) ;
if ( V_104 )
V_105 /= V_104 ;
if ( V_105 < V_106 )
V_105 = V_106 ;
if ( V_105 > V_31 -> V_105 )
V_105 = V_31 -> V_105 ;
return V_105 ;
}
static void F_89 ( struct V_23 * V_23 )
{
if ( V_23 -> V_84 > V_100 ) {
F_84 ( V_23 , 0 ) ;
F_90 ( V_23 ) ;
}
}
static void F_84 ( struct V_23 * V_23 , int V_95 )
{
}
static inline long F_88 ( struct V_23 * V_23 , struct V_96 * V_31 )
{
return V_31 -> V_105 ;
}
static inline void F_89 ( struct V_23 * V_23 )
{
}
static void F_91 ( struct V_23 * V_23 , struct V_25 * V_26 ,
unsigned long V_11 )
{
if ( V_26 -> V_75 ) {
if ( V_23 -> V_44 == V_26 )
F_64 ( V_23 ) ;
F_78 ( V_23 , V_26 ) ;
}
F_92 ( & V_26 -> V_69 , V_11 ) ;
if ( V_26 -> V_75 )
F_76 ( V_23 , V_26 ) ;
}
static void F_90 ( struct V_23 * V_23 )
{
struct V_96 * V_31 ;
struct V_25 * V_26 ;
long V_105 ;
V_31 = V_23 -> V_31 ;
V_26 = V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
if ( ! V_26 || F_85 ( V_23 ) )
return;
#ifndef V_82
if ( F_9 ( V_26 -> V_69 . V_11 == V_31 -> V_105 ) )
return;
#endif
V_105 = F_88 ( V_23 , V_31 ) ;
F_91 ( F_21 ( V_26 ) , V_26 , V_105 ) ;
}
static void F_84 ( struct V_23 * V_23 , int V_95 )
{
}
static inline void F_90 ( struct V_23 * V_23 )
{
}
static inline void F_89 ( struct V_23 * V_23 )
{
}
static void F_93 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_72
struct V_24 * V_107 = NULL ;
if ( F_18 ( V_26 ) )
V_107 = F_15 ( V_26 ) ;
if ( V_26 -> V_77 . V_108 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_108 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_109 ) )
V_26 -> V_77 . V_109 = V_41 ;
V_26 -> V_77 . V_108 = 0 ;
V_26 -> V_77 . V_110 += V_41 ;
if ( V_107 ) {
F_94 ( V_107 , V_41 >> 10 , 1 ) ;
F_95 ( V_107 , V_41 ) ;
}
}
if ( V_26 -> V_77 . V_111 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_111 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_112 ) )
V_26 -> V_77 . V_112 = V_41 ;
V_26 -> V_77 . V_111 = 0 ;
V_26 -> V_77 . V_110 += V_41 ;
if ( V_107 ) {
if ( V_107 -> V_113 ) {
V_26 -> V_77 . V_114 += V_41 ;
V_26 -> V_77 . V_115 ++ ;
F_96 ( V_107 , V_41 ) ;
}
F_97 ( V_107 , V_41 ) ;
if ( F_11 ( V_116 == V_117 ) ) {
F_98 ( V_117 ,
( void * ) F_99 ( V_107 ) ,
V_41 >> 20 ) ;
}
F_94 ( V_107 , V_41 >> 10 , 0 ) ;
}
}
#endif
}
static void F_100 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_16
T_3 V_118 = V_26 -> V_40 - V_23 -> V_39 ;
if ( V_118 < 0 )
V_118 = - V_118 ;
if ( V_118 > 3 * V_67 )
F_101 ( V_23 , V_119 ) ;
#endif
}
static void
F_102 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_120 )
{
T_2 V_40 = V_23 -> V_39 ;
if ( V_120 && F_103 ( V_121 ) )
V_40 += F_59 ( V_23 , V_26 ) ;
if ( ! V_120 ) {
unsigned long V_122 = V_67 ;
if ( F_103 ( V_123 ) )
V_122 >>= 1 ;
V_40 -= V_122 ;
}
V_40 = F_35 ( V_26 -> V_40 , V_40 ) ;
V_26 -> V_40 = V_40 ;
}
static void
F_104 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_124 )
{
if ( ! ( V_124 & V_125 ) || ( V_124 & V_126 ) )
V_26 -> V_40 += V_23 -> V_39 ;
F_64 ( V_23 ) ;
F_84 ( V_23 , 0 ) ;
F_76 ( V_23 , V_26 ) ;
F_90 ( V_23 ) ;
if ( V_124 & V_125 ) {
F_102 ( V_23 , V_26 , 0 ) ;
F_93 ( V_23 , V_26 ) ;
}
F_70 ( V_23 , V_26 ) ;
F_100 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_41 ( V_23 , V_26 ) ;
V_26 -> V_75 = 1 ;
if ( V_23 -> V_71 == 1 ) {
F_23 ( V_23 ) ;
F_105 ( V_23 ) ;
}
}
static void F_106 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_58 == V_26 )
V_23 -> V_58 = NULL ;
else
break;
}
}
static void F_107 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
V_23 -> V_57 = NULL ;
else
break;
}
}
static void F_108 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_127 == V_26 )
V_23 -> V_127 = NULL ;
else
break;
}
}
static void F_109 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_58 == V_26 )
F_106 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
F_107 ( V_26 ) ;
if ( V_23 -> V_127 == V_26 )
F_108 ( V_26 ) ;
}
static void
F_110 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_124 )
{
F_64 ( V_23 ) ;
F_74 ( V_23 , V_26 ) ;
if ( V_124 & V_128 ) {
#ifdef F_72
if ( F_18 ( V_26 ) ) {
struct V_24 * V_107 = F_15 ( V_26 ) ;
if ( V_107 -> V_129 & V_130 )
V_26 -> V_77 . V_108 = F_14 ( V_23 ) -> clock ;
if ( V_107 -> V_129 & V_131 )
V_26 -> V_77 . V_111 = F_14 ( V_23 ) -> clock ;
}
#endif
}
F_109 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_44 ( V_23 , V_26 ) ;
V_26 -> V_75 = 0 ;
F_84 ( V_23 , 0 ) ;
F_78 ( V_23 , V_26 ) ;
if ( ! ( V_124 & V_128 ) )
V_26 -> V_40 -= V_23 -> V_39 ;
F_111 ( V_23 ) ;
F_37 ( V_23 ) ;
F_90 ( V_23 ) ;
}
static void
F_112 ( struct V_23 * V_23 , struct V_25 * V_44 )
{
unsigned long V_132 , V_10 ;
struct V_25 * V_26 ;
T_3 V_41 ;
V_132 = F_57 ( V_23 , V_44 ) ;
V_10 = V_44 -> V_79 - V_44 -> V_133 ;
if ( V_10 > V_132 ) {
F_113 ( F_14 ( V_23 ) -> V_44 ) ;
F_109 ( V_23 , V_44 ) ;
return;
}
if ( V_10 < V_68 )
return;
V_26 = F_47 ( V_23 ) ;
V_41 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_41 < 0 )
return;
if ( V_41 > V_132 )
F_113 ( F_14 ( V_23 ) -> V_44 ) ;
}
static void
F_114 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 -> V_75 ) {
F_71 ( V_23 , V_26 ) ;
F_44 ( V_23 , V_26 ) ;
}
F_75 ( V_23 , V_26 ) ;
V_23 -> V_44 = V_26 ;
#ifdef F_72
if ( F_14 ( V_23 ) -> V_69 . V_11 >= 2 * V_26 -> V_69 . V_11 ) {
V_26 -> V_77 . V_134 = F_62 ( V_26 -> V_77 . V_134 ,
V_26 -> V_79 - V_26 -> V_133 ) ;
}
#endif
V_26 -> V_133 = V_26 -> V_79 ;
}
static struct V_25 * F_115 ( struct V_23 * V_23 )
{
struct V_25 * V_26 = F_47 ( V_23 ) ;
struct V_25 * V_56 = V_26 ;
if ( V_23 -> V_127 == V_26 ) {
struct V_25 * V_135 = F_48 ( V_26 ) ;
if ( V_135 && F_116 ( V_135 , V_56 ) < 1 )
V_26 = V_135 ;
}
if ( V_23 -> V_58 && F_116 ( V_23 -> V_58 , V_56 ) < 1 )
V_26 = V_23 -> V_58 ;
if ( V_23 -> V_57 && F_116 ( V_23 -> V_57 , V_56 ) < 1 )
V_26 = V_23 -> V_57 ;
F_109 ( V_23 , V_26 ) ;
return V_26 ;
}
static void F_117 ( struct V_23 * V_23 , struct V_25 * V_136 )
{
if ( V_136 -> V_75 )
F_64 ( V_23 ) ;
F_118 ( V_23 ) ;
F_100 ( V_23 , V_136 ) ;
if ( V_136 -> V_75 ) {
F_69 ( V_23 , V_136 ) ;
F_41 ( V_23 , V_136 ) ;
}
V_23 -> V_44 = NULL ;
}
static void
F_119 ( struct V_23 * V_23 , struct V_25 * V_44 , int V_137 )
{
F_64 ( V_23 ) ;
F_89 ( V_23 ) ;
#ifdef F_120
if ( V_137 ) {
F_113 ( F_14 ( V_23 ) -> V_44 ) ;
return;
}
if ( ! F_103 ( V_138 ) &&
F_121 ( & F_14 ( V_23 ) -> V_139 ) )
return;
#endif
if ( V_23 -> V_71 > 1 )
F_112 ( V_23 , V_44 ) ;
}
static inline bool F_122 ( void )
{
return F_123 ( & V_140 ) ;
}
void F_124 ( int V_141 , int V_142 )
{
if ( V_141 && ! V_142 )
F_125 ( & V_140 ) ;
else if ( ! V_141 && V_142 )
F_126 ( & V_140 ) ;
}
static bool F_122 ( void )
{
return true ;
}
void F_124 ( int V_141 , int V_142 ) {}
static inline T_2 F_127 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_128 ( void )
{
return ( T_2 ) V_143 * V_144 ;
}
void F_129 ( struct V_145 * V_146 )
{
T_2 V_85 ;
if ( V_146 -> V_147 == V_148 )
return;
V_85 = F_130 ( F_131 () ) ;
V_146 -> V_149 = V_146 -> V_147 ;
V_146 -> V_150 = V_85 + F_132 ( V_146 -> V_72 ) ;
}
static inline struct V_145 * F_133 ( struct V_96 * V_31 )
{
return & V_31 -> V_145 ;
}
static int F_134 ( struct V_23 * V_23 )
{
struct V_96 * V_31 = V_23 -> V_31 ;
struct V_145 * V_146 = F_133 ( V_31 ) ;
T_2 V_151 = 0 , V_152 , V_153 ;
V_152 = F_128 () - V_23 -> V_154 ;
F_135 ( & V_146 -> V_155 ) ;
if ( V_146 -> V_147 == V_148 )
V_151 = V_152 ;
else {
if ( ! V_146 -> V_156 ) {
F_129 ( V_146 ) ;
F_136 ( V_146 ) ;
}
if ( V_146 -> V_149 > 0 ) {
V_151 = F_13 ( V_146 -> V_149 , V_152 ) ;
V_146 -> V_149 -= V_151 ;
V_146 -> V_157 = 0 ;
}
}
V_153 = V_146 -> V_150 ;
F_137 ( & V_146 -> V_155 ) ;
V_23 -> V_154 += V_151 ;
if ( ( T_3 ) ( V_153 - V_23 -> V_150 ) > 0 )
V_23 -> V_150 = V_153 ;
return V_23 -> V_154 > 0 ;
}
static void F_138 ( struct V_23 * V_23 )
{
struct V_145 * V_146 = F_133 ( V_23 -> V_31 ) ;
struct V_22 * V_22 = F_14 ( V_23 ) ;
if ( F_9 ( ( T_3 ) ( V_22 -> clock - V_23 -> V_150 ) < 0 ) )
return;
if ( V_23 -> V_154 < 0 )
return;
if ( ( T_3 ) ( V_23 -> V_150 - V_146 -> V_150 ) >= 0 ) {
V_23 -> V_150 += V_158 ;
} else {
V_23 -> V_154 = 0 ;
}
}
static void F_139 ( struct V_23 * V_23 ,
unsigned long V_10 )
{
V_23 -> V_154 -= V_10 ;
F_138 ( V_23 ) ;
if ( F_9 ( V_23 -> V_154 > 0 ) )
return;
if ( ! F_134 ( V_23 ) && F_9 ( V_23 -> V_44 ) )
F_113 ( F_14 ( V_23 ) -> V_44 ) ;
}
static T_7
void F_68 ( struct V_23 * V_23 , unsigned long V_10 )
{
if ( ! F_122 () || ! V_23 -> V_159 )
return;
F_139 ( V_23 , V_10 ) ;
}
static inline int F_140 ( struct V_23 * V_23 )
{
return F_122 () && V_23 -> V_160 ;
}
static inline int F_85 ( struct V_23 * V_23 )
{
return F_122 () && V_23 -> V_161 ;
}
static inline int F_141 ( struct V_96 * V_31 ,
int V_162 , int V_163 )
{
struct V_23 * V_164 , * V_165 ;
V_164 = V_31 -> V_23 [ V_162 ] ;
V_165 = V_31 -> V_23 [ V_163 ] ;
return F_85 ( V_164 ) ||
F_85 ( V_165 ) ;
}
static int F_142 ( struct V_96 * V_31 , void * V_166 )
{
struct V_22 * V_22 = V_166 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
V_23 -> V_161 -- ;
#ifdef V_82
if ( ! V_23 -> V_161 ) {
T_2 V_41 = V_22 -> V_86 - V_23 -> V_102 ;
V_23 -> V_102 += V_41 ;
V_23 -> V_103 += V_41 ;
F_90 ( V_23 ) ;
}
#endif
return 0 ;
}
static int F_143 ( struct V_96 * V_31 , void * V_166 )
{
struct V_22 * V_22 = V_166 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
if ( ! V_23 -> V_161 )
F_84 ( V_23 , 0 ) ;
V_23 -> V_161 ++ ;
return 0 ;
}
static void F_144 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_145 * V_146 = F_133 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
long V_167 , V_168 = 1 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
F_145 () ;
F_146 ( V_23 -> V_31 , F_143 , V_169 , ( void * ) V_22 ) ;
F_147 () ;
V_167 = V_23 -> V_170 ;
F_32 (se) {
struct V_23 * V_171 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 )
break;
if ( V_168 )
F_110 ( V_171 , V_26 , V_128 ) ;
V_171 -> V_170 -= V_167 ;
if ( V_171 -> V_69 . V_11 )
V_168 = 0 ;
}
if ( ! V_26 )
V_22 -> V_71 -= V_167 ;
V_23 -> V_160 = 1 ;
V_23 -> V_172 = V_22 -> clock ;
F_135 ( & V_146 -> V_155 ) ;
F_26 ( & V_23 -> V_173 , & V_146 -> V_174 ) ;
F_137 ( & V_146 -> V_155 ) ;
}
void F_148 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_145 * V_146 = F_133 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
int V_175 = 1 ;
long V_167 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
V_23 -> V_160 = 0 ;
F_135 ( & V_146 -> V_155 ) ;
V_146 -> V_176 += V_22 -> clock - V_23 -> V_172 ;
F_28 ( & V_23 -> V_173 ) ;
F_137 ( & V_146 -> V_155 ) ;
V_23 -> V_172 = 0 ;
F_149 ( V_22 ) ;
F_146 ( V_23 -> V_31 , V_169 , F_142 , ( void * ) V_22 ) ;
if ( ! V_23 -> V_69 . V_11 )
return;
V_167 = V_23 -> V_170 ;
F_32 (se) {
if ( V_26 -> V_75 )
V_175 = 0 ;
V_23 = F_21 ( V_26 ) ;
if ( V_175 )
F_104 ( V_23 , V_26 , V_125 ) ;
V_23 -> V_170 += V_167 ;
if ( F_140 ( V_23 ) )
break;
}
if ( ! V_26 )
V_22 -> V_71 += V_167 ;
if ( V_22 -> V_44 == V_22 -> V_157 && V_22 -> V_38 . V_71 )
F_113 ( V_22 -> V_44 ) ;
}
static T_2 F_150 ( struct V_145 * V_146 ,
T_2 V_177 , T_2 V_153 )
{
struct V_23 * V_23 ;
T_2 V_149 = V_177 ;
F_145 () ;
F_151 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_135 ( & V_22 -> V_155 ) ;
if ( ! F_140 ( V_23 ) )
goto V_57;
V_149 = - V_23 -> V_154 + 1 ;
if ( V_149 > V_177 )
V_149 = V_177 ;
V_177 -= V_149 ;
V_23 -> V_154 += V_149 ;
V_23 -> V_150 = V_153 ;
if ( V_23 -> V_154 > 0 )
F_148 ( V_23 ) ;
V_57:
F_137 ( & V_22 -> V_155 ) ;
if ( ! V_177 )
break;
}
F_147 () ;
return V_177 ;
}
static int F_152 ( struct V_145 * V_146 , int V_178 )
{
T_2 V_149 , V_150 ;
int V_157 = 1 , V_160 ;
F_135 ( & V_146 -> V_155 ) ;
if ( V_146 -> V_147 == V_148 )
goto V_179;
V_160 = ! F_153 ( & V_146 -> V_174 ) ;
V_157 = V_146 -> V_157 && ! V_160 ;
V_146 -> V_180 += V_178 ;
if ( V_157 )
goto V_179;
F_129 ( V_146 ) ;
if ( ! V_160 ) {
V_146 -> V_157 = 1 ;
goto V_179;
}
V_146 -> V_181 += V_178 ;
V_149 = V_146 -> V_149 ;
V_150 = V_146 -> V_150 ;
V_146 -> V_149 = 0 ;
while ( V_160 && V_149 > 0 ) {
F_137 ( & V_146 -> V_155 ) ;
V_149 = F_150 ( V_146 , V_149 ,
V_150 ) ;
F_135 ( & V_146 -> V_155 ) ;
V_160 = ! F_153 ( & V_146 -> V_174 ) ;
}
V_146 -> V_149 = V_149 ;
V_146 -> V_157 = 0 ;
V_179:
if ( V_157 )
V_146 -> V_156 = 0 ;
F_137 ( & V_146 -> V_155 ) ;
return V_157 ;
}
static int F_154 ( struct V_145 * V_146 , T_2 V_182 )
{
struct V_183 * V_184 = & V_146 -> V_185 ;
T_2 V_177 ;
if ( F_155 ( V_184 ) )
return 1 ;
V_177 = F_132 ( F_156 ( V_184 ) ) ;
if ( V_177 < V_182 )
return 1 ;
return 0 ;
}
static void F_157 ( struct V_145 * V_146 )
{
T_2 V_186 = V_187 + V_188 ;
if ( F_154 ( V_146 , V_186 ) )
return;
F_158 ( & V_146 -> V_189 ,
F_159 ( V_187 ) ) ;
}
static void F_160 ( struct V_23 * V_23 )
{
struct V_145 * V_146 = F_133 ( V_23 -> V_31 ) ;
T_3 V_190 = V_23 -> V_154 - V_191 ;
if ( V_190 <= 0 )
return;
F_135 ( & V_146 -> V_155 ) ;
if ( V_146 -> V_147 != V_148 &&
V_23 -> V_150 == V_146 -> V_150 ) {
V_146 -> V_149 += V_190 ;
if ( V_146 -> V_149 > F_128 () &&
! F_153 ( & V_146 -> V_174 ) )
F_157 ( V_146 ) ;
}
F_137 ( & V_146 -> V_155 ) ;
V_23 -> V_154 -= V_190 ;
}
static T_7 void F_111 ( struct V_23 * V_23 )
{
if ( ! F_122 () )
return;
if ( ! V_23 -> V_159 || V_23 -> V_71 )
return;
F_160 ( V_23 ) ;
}
static void F_161 ( struct V_145 * V_146 )
{
T_2 V_149 = 0 , V_74 = F_128 () ;
T_2 V_153 ;
if ( F_154 ( V_146 , V_188 ) )
return;
F_135 ( & V_146 -> V_155 ) ;
if ( V_146 -> V_147 != V_148 && V_146 -> V_149 > V_74 ) {
V_149 = V_146 -> V_149 ;
V_146 -> V_149 = 0 ;
}
V_153 = V_146 -> V_150 ;
F_137 ( & V_146 -> V_155 ) ;
if ( ! V_149 )
return;
V_149 = F_150 ( V_146 , V_149 , V_153 ) ;
F_135 ( & V_146 -> V_155 ) ;
if ( V_153 == V_146 -> V_150 )
V_146 -> V_149 = V_149 ;
F_137 ( & V_146 -> V_155 ) ;
}
static void F_105 ( struct V_23 * V_23 )
{
if ( ! F_122 () )
return;
if ( ! V_23 -> V_159 || V_23 -> V_44 )
return;
if ( F_140 ( V_23 ) )
return;
F_68 ( V_23 , 0 ) ;
if ( V_23 -> V_154 <= 0 )
F_144 ( V_23 ) ;
}
static void F_118 ( struct V_23 * V_23 )
{
if ( ! F_122 () )
return;
if ( F_9 ( ! V_23 -> V_159 || V_23 -> V_154 > 0 ) )
return;
if ( F_140 ( V_23 ) )
return;
F_144 ( V_23 ) ;
}
static enum V_192 F_162 ( struct V_183 * V_193 )
{
struct V_145 * V_146 =
F_19 ( V_193 , struct V_145 , V_189 ) ;
F_161 ( V_146 ) ;
return V_194 ;
}
static enum V_192 F_163 ( struct V_183 * V_193 )
{
struct V_145 * V_146 =
F_19 ( V_193 , struct V_145 , V_185 ) ;
T_8 V_85 ;
int V_178 ;
int V_157 = 0 ;
for (; ; ) {
V_85 = F_164 ( V_193 ) ;
V_178 = F_165 ( V_193 , V_85 , V_146 -> V_72 ) ;
if ( ! V_178 )
break;
V_157 = F_152 ( V_146 , V_178 ) ;
}
return V_157 ? V_194 : V_195 ;
}
void F_166 ( struct V_145 * V_146 )
{
F_167 ( & V_146 -> V_155 ) ;
V_146 -> V_149 = 0 ;
V_146 -> V_147 = V_148 ;
V_146 -> V_72 = F_159 ( F_127 () ) ;
F_168 ( & V_146 -> V_174 ) ;
F_169 ( & V_146 -> V_185 , V_196 , V_197 ) ;
V_146 -> V_185 . V_198 = F_163 ;
F_169 ( & V_146 -> V_189 , V_196 , V_197 ) ;
V_146 -> V_189 . V_198 = F_162 ;
}
static void F_170 ( struct V_23 * V_23 )
{
V_23 -> V_159 = 0 ;
F_168 ( & V_23 -> V_173 ) ;
}
void F_136 ( struct V_145 * V_146 )
{
while ( F_11 ( F_121 ( & V_146 -> V_185 ) ) ) {
F_137 ( & V_146 -> V_155 ) ;
F_171 ( & V_146 -> V_185 ) ;
F_135 ( & V_146 -> V_155 ) ;
if ( V_146 -> V_156 )
return;
}
V_146 -> V_156 = 1 ;
F_158 ( & V_146 -> V_185 , V_146 -> V_72 ) ;
}
static void F_172 ( struct V_145 * V_146 )
{
F_171 ( & V_146 -> V_185 ) ;
F_171 ( & V_146 -> V_189 ) ;
}
static void F_173 ( struct V_22 * V_22 )
{
struct V_23 * V_23 ;
F_174 (rq, cfs_rq) {
struct V_145 * V_146 = F_133 ( V_23 -> V_31 ) ;
if ( ! V_23 -> V_159 )
continue;
V_23 -> V_154 = V_146 -> V_147 ;
if ( F_140 ( V_23 ) )
F_148 ( V_23 ) ;
}
}
static T_7
void F_68 ( struct V_23 * V_23 , unsigned long V_10 ) {}
static void F_118 ( struct V_23 * V_23 ) {}
static void F_105 ( struct V_23 * V_23 ) {}
static T_7 void F_111 ( struct V_23 * V_23 ) {}
static inline int F_140 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_85 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_141 ( struct V_96 * V_31 ,
int V_162 , int V_163 )
{
return 0 ;
}
void F_166 ( struct V_145 * V_146 ) {}
static void F_170 ( struct V_23 * V_23 ) {}
static inline struct V_145 * F_133 ( struct V_96 * V_31 )
{
return NULL ;
}
static inline void F_172 ( struct V_145 * V_146 ) {}
static inline void F_173 ( struct V_22 * V_22 ) {}
static void F_175 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_176 ( F_34 ( V_27 ) != V_22 ) ;
if ( V_23 -> V_71 > 1 ) {
T_2 V_74 = F_57 ( V_23 , V_26 ) ;
T_2 V_199 = V_26 -> V_79 - V_26 -> V_133 ;
T_3 V_41 = V_74 - V_199 ;
if ( V_41 < 0 ) {
if ( V_22 -> V_44 == V_27 )
F_113 ( V_27 ) ;
return;
}
if ( V_22 -> V_44 != V_27 )
V_41 = F_177 ( T_3 , 10000LL , V_41 ) ;
F_178 ( V_22 , V_41 ) ;
}
}
static void F_179 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
if ( ! F_180 ( V_22 ) || V_44 -> V_200 != & V_201 )
return;
if ( F_21 ( & V_44 -> V_26 ) -> V_71 < V_66 )
F_175 ( V_22 , V_44 ) ;
}
static inline void
F_175 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
}
static inline void F_179 ( struct V_22 * V_22 )
{
}
static void
F_181 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_124 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
F_32 (se) {
if ( V_26 -> V_75 )
break;
V_23 = F_21 ( V_26 ) ;
F_104 ( V_23 , V_26 , V_124 ) ;
if ( F_140 ( V_23 ) )
break;
V_23 -> V_170 ++ ;
V_124 = V_125 ;
}
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_170 ++ ;
if ( F_140 ( V_23 ) )
break;
F_84 ( V_23 , 0 ) ;
F_90 ( V_23 ) ;
}
if ( ! V_26 )
F_182 ( V_22 ) ;
F_179 ( V_22 ) ;
}
static void F_183 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_124 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
int V_202 = V_124 & V_128 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_110 ( V_23 , V_26 , V_124 ) ;
if ( F_140 ( V_23 ) )
break;
V_23 -> V_170 -- ;
if ( V_23 -> V_69 . V_11 ) {
if ( V_202 && F_30 ( V_26 ) )
F_184 ( F_30 ( V_26 ) ) ;
V_26 = F_30 ( V_26 ) ;
break;
}
V_124 |= V_128 ;
}
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_170 -- ;
if ( F_140 ( V_23 ) )
break;
F_84 ( V_23 , 0 ) ;
F_90 ( V_23 ) ;
}
if ( ! V_26 )
F_185 ( V_22 ) ;
F_179 ( V_22 ) ;
}
static unsigned long F_186 ( const int V_203 )
{
return F_187 ( V_203 ) -> V_69 . V_11 ;
}
static unsigned long F_188 ( int V_203 , int type )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_204 = F_186 ( V_203 ) ;
if ( type == 0 || ! F_103 ( V_205 ) )
return V_204 ;
return F_13 ( V_22 -> V_206 [ type - 1 ] , V_204 ) ;
}
static unsigned long F_189 ( int V_203 , int type )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_204 = F_186 ( V_203 ) ;
if ( type == 0 || ! F_103 ( V_205 ) )
return V_204 ;
return F_62 ( V_22 -> V_206 [ type - 1 ] , V_204 ) ;
}
static unsigned long F_190 ( int V_203 )
{
return F_187 ( V_203 ) -> V_207 ;
}
static unsigned long F_191 ( int V_203 )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_71 = F_192 ( V_22 -> V_71 ) ;
if ( V_71 )
return V_22 -> V_69 . V_11 / V_71 ;
return 0 ;
}
static void F_193 ( struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 V_39 ;
#ifndef F_39
T_2 V_47 ;
do {
V_47 = V_23 -> V_47 ;
F_194 () ;
V_39 = V_23 -> V_39 ;
} while ( V_39 != V_47 );
#else
V_39 = V_23 -> V_39 ;
#endif
V_26 -> V_40 -= V_39 ;
}
static long F_195 ( struct V_96 * V_31 , int V_203 , long V_208 , long V_209 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_203 ] ;
if ( ! V_31 -> V_32 )
return V_208 ;
F_32 (se) {
long V_17 , V_210 ;
V_31 = V_26 -> V_29 -> V_31 ;
V_210 = V_209 + F_86 ( V_31 , V_26 -> V_29 ) ;
V_17 = V_26 -> V_29 -> V_69 . V_11 + V_208 ;
if ( V_210 > 0 && V_17 < V_210 )
V_208 = ( V_17 * V_31 -> V_105 ) / V_210 ;
else
V_208 = V_31 -> V_105 ;
if ( V_208 < V_106 )
V_208 = V_106 ;
V_208 -= V_26 -> V_69 . V_11 ;
V_209 = 0 ;
}
return V_208 ;
}
static inline unsigned long F_195 ( struct V_96 * V_31 , int V_203 ,
unsigned long V_208 , unsigned long V_209 )
{
return V_208 ;
}
static int F_196 ( struct V_211 * V_212 , struct V_24 * V_27 , int V_213 )
{
T_3 V_214 , V_69 ;
int V_215 , V_216 , V_217 ;
unsigned long V_218 ;
struct V_96 * V_31 ;
unsigned long V_11 ;
int V_219 ;
V_215 = V_212 -> V_220 ;
V_216 = F_131 () ;
V_217 = F_197 ( V_27 ) ;
V_69 = F_188 ( V_217 , V_215 ) ;
V_214 = F_189 ( V_216 , V_215 ) ;
if ( V_213 ) {
V_31 = V_96 ( V_221 ) ;
V_11 = V_221 -> V_26 . V_69 . V_11 ;
V_214 += F_195 ( V_31 , V_216 , - V_11 , - V_11 ) ;
V_69 += F_195 ( V_31 , V_217 , 0 , - V_11 ) ;
}
V_31 = V_96 ( V_27 ) ;
V_11 = V_27 -> V_26 . V_69 . V_11 ;
if ( V_214 > 0 ) {
T_3 V_222 , V_223 ;
V_222 = 100 ;
V_222 *= F_190 ( V_217 ) ;
V_222 *= V_214 +
F_195 ( V_31 , V_216 , V_11 , V_11 ) ;
V_223 = 100 + ( V_212 -> V_224 - 100 ) / 2 ;
V_223 *= F_190 ( V_216 ) ;
V_223 *= V_69 + F_195 ( V_31 , V_217 , 0 , V_11 ) ;
V_219 = V_222 <= V_223 ;
} else
V_219 = true ;
if ( V_213 && V_219 )
return 1 ;
F_101 ( V_27 , V_26 . V_77 . V_225 ) ;
V_218 = F_191 ( V_216 ) ;
if ( V_219 ||
( V_214 <= V_69 &&
V_214 + F_189 ( V_217 , V_215 ) <= V_218 ) ) {
F_101 ( V_212 , V_226 ) ;
F_101 ( V_27 , V_26 . V_77 . V_227 ) ;
return 1 ;
}
return 0 ;
}
static struct V_228 *
F_198 ( struct V_211 * V_212 , struct V_24 * V_27 ,
int V_216 , int V_229 )
{
struct V_228 * V_230 = NULL , * V_231 = V_212 -> V_232 ;
unsigned long V_233 = V_234 , V_214 = 0 ;
int V_235 = 100 + ( V_212 -> V_224 - 100 ) / 2 ;
do {
unsigned long V_69 , V_236 ;
int V_237 ;
int V_238 ;
if ( ! F_199 ( F_200 ( V_231 ) ,
F_201 ( V_27 ) ) )
continue;
V_237 = F_202 ( V_216 ,
F_200 ( V_231 ) ) ;
V_236 = 0 ;
F_203 (i, sched_group_cpus(group)) {
if ( V_237 )
V_69 = F_188 ( V_238 , V_229 ) ;
else
V_69 = F_189 ( V_238 , V_229 ) ;
V_236 += V_69 ;
}
V_236 = ( V_236 * V_239 ) / V_231 -> V_240 -> V_241 ;
if ( V_237 ) {
V_214 = V_236 ;
} else if ( V_236 < V_233 ) {
V_233 = V_236 ;
V_230 = V_231 ;
}
} while ( V_231 = V_231 -> V_57 , V_231 != V_212 -> V_232 );
if ( ! V_230 || 100 * V_214 < V_235 * V_233 )
return NULL ;
return V_230 ;
}
static int
F_204 ( struct V_228 * V_231 , struct V_24 * V_27 , int V_216 )
{
unsigned long V_69 , V_233 = V_234 ;
int V_230 = - 1 ;
int V_238 ;
F_205 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_69 = F_186 ( V_238 ) ;
if ( V_69 < V_233 || ( V_69 == V_233 && V_238 == V_216 ) ) {
V_233 = V_69 ;
V_230 = V_238 ;
}
}
return V_230 ;
}
static int F_206 ( struct V_24 * V_27 , int V_242 )
{
int V_203 = F_131 () ;
int V_217 = F_197 ( V_27 ) ;
struct V_211 * V_212 ;
struct V_228 * V_243 ;
int V_238 ;
if ( V_242 == V_203 && F_207 ( V_203 ) )
return V_203 ;
if ( V_242 == V_217 && F_207 ( V_217 ) )
return V_217 ;
V_212 = F_208 ( F_209 ( V_244 , V_242 ) ) ;
F_210 (sd) {
V_243 = V_212 -> V_232 ;
do {
if ( ! F_199 ( F_200 ( V_243 ) ,
F_201 ( V_27 ) ) )
goto V_57;
F_203 (i, sched_group_cpus(sg)) {
if ( ! F_207 ( V_238 ) )
goto V_57;
}
V_242 = F_211 ( F_200 ( V_243 ) ,
F_201 ( V_27 ) ) ;
goto V_245;
V_57:
V_243 = V_243 -> V_57 ;
} while ( V_243 != V_212 -> V_232 );
}
V_245:
return V_242 ;
}
static int
F_212 ( struct V_24 * V_27 , int V_246 , int V_247 )
{
struct V_211 * V_14 , * V_248 = NULL , * V_212 = NULL ;
int V_203 = F_131 () ;
int V_217 = F_197 ( V_27 ) ;
int V_249 = V_203 ;
int V_250 = 0 ;
int V_213 = V_247 & V_251 ;
if ( V_27 -> V_252 == 1 )
return V_217 ;
if ( V_246 & V_253 ) {
if ( F_202 ( V_203 , F_201 ( V_27 ) ) )
V_250 = 1 ;
V_249 = V_217 ;
}
F_145 () ;
F_213 (cpu, tmp) {
if ( ! ( V_14 -> V_124 & V_254 ) )
continue;
if ( V_250 && ( V_14 -> V_124 & V_255 ) &&
F_202 ( V_217 , F_214 ( V_14 ) ) ) {
V_248 = V_14 ;
break;
}
if ( V_14 -> V_124 & V_246 )
V_212 = V_14 ;
}
if ( V_248 ) {
if ( V_203 != V_217 && F_196 ( V_248 , V_27 , V_213 ) )
V_217 = V_203 ;
V_249 = F_206 ( V_27 , V_217 ) ;
goto V_256;
}
while ( V_212 ) {
int V_229 = V_212 -> V_257 ;
struct V_228 * V_231 ;
int V_11 ;
if ( ! ( V_212 -> V_124 & V_246 ) ) {
V_212 = V_212 -> V_258 ;
continue;
}
if ( V_246 & V_253 )
V_229 = V_212 -> V_220 ;
V_231 = F_198 ( V_212 , V_27 , V_203 , V_229 ) ;
if ( ! V_231 ) {
V_212 = V_212 -> V_258 ;
continue;
}
V_249 = F_204 ( V_231 , V_27 , V_203 ) ;
if ( V_249 == - 1 || V_249 == V_203 ) {
V_212 = V_212 -> V_258 ;
continue;
}
V_203 = V_249 ;
V_11 = V_212 -> V_259 ;
V_212 = NULL ;
F_213 (cpu, tmp) {
if ( V_11 <= V_14 -> V_259 )
break;
if ( V_14 -> V_124 & V_246 )
V_212 = V_14 ;
}
}
V_256:
F_147 () ;
return V_249 ;
}
static unsigned long
F_215 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
unsigned long V_260 = V_261 ;
return F_55 ( V_260 , V_26 ) ;
}
static int
F_116 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
T_3 V_260 , V_262 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_262 <= 0 )
return - 1 ;
V_260 = F_215 ( V_44 , V_26 ) ;
if ( V_262 > V_260 )
return 1 ;
return 0 ;
}
static void F_216 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_263 == V_264 ) )
return;
F_32 (se)
F_21 ( V_26 ) -> V_58 = V_26 ;
}
static void F_184 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_263 == V_264 ) )
return;
F_32 (se)
F_21 ( V_26 ) -> V_57 = V_26 ;
}
static void F_217 ( struct V_25 * V_26 )
{
F_32 (se)
F_21 ( V_26 ) -> V_127 = V_26 ;
}
static void F_218 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_247 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_25 * V_26 = & V_44 -> V_26 , * V_34 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
int V_265 = V_23 -> V_71 >= V_66 ;
int V_266 = 0 ;
if ( F_11 ( V_26 == V_34 ) )
return;
if ( F_11 ( F_85 ( F_21 ( V_34 ) ) ) )
return;
if ( F_103 ( V_267 ) && V_265 && ! ( V_247 & V_268 ) ) {
F_184 ( V_34 ) ;
V_266 = 1 ;
}
if ( F_219 ( V_44 ) )
return;
if ( F_11 ( V_44 -> V_263 == V_264 ) &&
F_9 ( V_27 -> V_263 != V_264 ) )
goto V_269;
if ( F_11 ( V_27 -> V_263 != V_270 ) )
return;
F_33 ( & V_26 , & V_34 ) ;
F_64 ( F_21 ( V_26 ) ) ;
F_220 ( ! V_34 ) ;
if ( F_116 ( V_26 , V_34 ) == 1 ) {
if ( ! V_266 )
F_184 ( V_34 ) ;
goto V_269;
}
return;
V_269:
F_113 ( V_44 ) ;
if ( F_11 ( ! V_26 -> V_75 || V_44 == V_22 -> V_157 ) )
return;
if ( F_103 ( V_271 ) && V_265 && F_18 ( V_26 ) )
F_216 ( V_26 ) ;
}
static struct V_24 * F_221 ( struct V_22 * V_22 )
{
struct V_24 * V_27 ;
struct V_23 * V_23 = & V_22 -> V_38 ;
struct V_25 * V_26 ;
if ( ! V_23 -> V_71 )
return NULL ;
do {
V_26 = F_115 ( V_23 ) ;
F_114 ( V_23 , V_26 ) ;
V_23 = F_22 ( V_26 ) ;
} while ( V_23 );
V_27 = F_15 ( V_26 ) ;
if ( F_180 ( V_22 ) )
F_175 ( V_22 , V_27 ) ;
return V_27 ;
}
static void F_222 ( struct V_22 * V_22 , struct V_24 * V_136 )
{
struct V_25 * V_26 = & V_136 -> V_26 ;
struct V_23 * V_23 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_117 ( V_23 , V_26 ) ;
}
}
static void F_223 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
struct V_25 * V_26 = & V_44 -> V_26 ;
if ( F_11 ( V_22 -> V_71 == 1 ) )
return;
F_109 ( V_23 , V_26 ) ;
if ( V_44 -> V_263 != V_272 ) {
F_149 ( V_22 ) ;
F_64 ( V_23 ) ;
V_22 -> V_273 = 1 ;
}
F_217 ( V_26 ) ;
}
static bool F_224 ( struct V_22 * V_22 , struct V_24 * V_27 , bool V_269 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
if ( ! V_26 -> V_75 || F_85 ( F_21 ( V_26 ) ) )
return false ;
F_184 ( V_26 ) ;
F_223 ( V_22 ) ;
return true ;
}
static void F_225 ( struct V_24 * V_27 , struct V_274 * V_275 )
{
F_226 ( V_275 -> V_276 , V_27 , 0 ) ;
F_227 ( V_27 , V_275 -> V_277 ) ;
F_228 ( V_275 -> V_278 , V_27 , 0 ) ;
F_229 ( V_275 -> V_278 , V_27 , 0 ) ;
}
static int
F_230 ( struct V_24 * V_27 , T_2 V_85 , struct V_211 * V_212 )
{
T_3 V_41 ;
if ( V_27 -> V_200 != & V_201 )
return 0 ;
if ( F_11 ( V_27 -> V_263 == V_264 ) )
return 0 ;
if ( F_103 ( V_279 ) && F_231 () -> V_71 &&
( & V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_57 ||
& V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_58 ) )
return 1 ;
if ( V_280 == - 1 )
return 1 ;
if ( V_280 == 0 )
return 0 ;
V_41 = V_85 - V_27 -> V_26 . V_87 ;
return V_41 < ( T_3 ) V_280 ;
}
static
int F_232 ( struct V_24 * V_27 , struct V_274 * V_275 )
{
int V_281 = 0 ;
if ( ! F_202 ( V_275 -> V_277 , F_201 ( V_27 ) ) ) {
int V_282 ;
F_101 ( V_27 , V_26 . V_77 . V_283 ) ;
if ( ! V_275 -> V_284 || ( V_275 -> V_124 & V_285 ) )
return 0 ;
V_282 = F_211 ( V_275 -> V_284 ,
F_201 ( V_27 ) ) ;
if ( V_282 < V_286 ) {
V_275 -> V_124 |= V_285 ;
V_275 -> V_282 = V_282 ;
}
return 0 ;
}
V_275 -> V_124 &= ~ V_287 ;
if ( F_233 ( V_275 -> V_276 , V_27 ) ) {
F_101 ( V_27 , V_26 . V_77 . V_288 ) ;
return 0 ;
}
V_281 = F_230 ( V_27 , V_275 -> V_276 -> V_86 , V_275 -> V_212 ) ;
if ( ! V_281 ||
V_275 -> V_212 -> V_289 > V_275 -> V_212 -> V_290 ) {
#ifdef F_72
if ( V_281 ) {
F_101 ( V_275 -> V_212 , V_291 [ V_275 -> V_157 ] ) ;
F_101 ( V_27 , V_26 . V_77 . V_292 ) ;
}
#endif
return 1 ;
}
if ( V_281 ) {
F_101 ( V_27 , V_26 . V_77 . V_293 ) ;
return 0 ;
}
return 1 ;
}
static int F_234 ( struct V_274 * V_275 )
{
struct V_24 * V_27 , * V_294 ;
F_235 (p, n, &env->src_rq->cfs_tasks, se.group_node) {
if ( F_141 ( V_96 ( V_27 ) , V_275 -> V_276 -> V_203 , V_275 -> V_277 ) )
continue;
if ( ! F_232 ( V_27 , V_275 ) )
continue;
F_225 ( V_27 , V_275 ) ;
F_101 ( V_275 -> V_212 , V_295 [ V_275 -> V_157 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_236 ( struct V_274 * V_275 )
{
struct V_296 * V_297 = & V_275 -> V_276 -> V_94 ;
struct V_24 * V_27 ;
unsigned long V_69 ;
int V_298 = 0 ;
if ( V_275 -> V_235 <= 0 )
return 0 ;
while ( ! F_153 ( V_297 ) ) {
V_27 = F_237 ( V_297 , struct V_24 , V_26 . V_93 ) ;
V_275 -> V_299 ++ ;
if ( V_275 -> V_299 > V_275 -> V_300 )
break;
if ( V_275 -> V_299 > V_275 -> V_301 ) {
V_275 -> V_301 += V_302 ;
V_275 -> V_124 |= V_303 ;
break;
}
if ( F_141 ( V_96 ( V_27 ) , V_275 -> V_162 , V_275 -> V_277 ) )
goto V_57;
V_69 = F_238 ( V_27 ) ;
if ( F_103 ( V_304 ) && V_69 < 16 && ! V_275 -> V_212 -> V_289 )
goto V_57;
if ( ( V_69 / 2 ) > V_275 -> V_235 )
goto V_57;
if ( ! F_232 ( V_27 , V_275 ) )
goto V_57;
F_225 ( V_27 , V_275 ) ;
V_298 ++ ;
V_275 -> V_235 -= V_69 ;
#ifdef F_239
if ( V_275 -> V_157 == V_305 )
break;
#endif
if ( V_275 -> V_235 <= 0 )
break;
continue;
V_57:
F_240 ( & V_27 -> V_26 . V_93 , V_297 ) ;
}
F_63 ( V_275 -> V_212 , V_295 [ V_275 -> V_157 ] , V_298 ) ;
return V_298 ;
}
static int F_241 ( struct V_96 * V_31 , int V_203 )
{
struct V_23 * V_23 ;
unsigned long V_124 ;
struct V_22 * V_22 ;
if ( ! V_31 -> V_26 [ V_203 ] )
return 0 ;
V_22 = F_187 ( V_203 ) ;
V_23 = V_31 -> V_23 [ V_203 ] ;
F_242 ( & V_22 -> V_155 , V_124 ) ;
F_149 ( V_22 ) ;
F_84 ( V_23 , 1 ) ;
F_90 ( V_23 ) ;
F_243 ( & V_22 -> V_155 , V_124 ) ;
return 0 ;
}
static void F_244 ( int V_203 )
{
struct V_23 * V_23 ;
struct V_22 * V_22 = F_187 ( V_203 ) ;
F_145 () ;
F_174 (rq, cfs_rq) {
if ( F_85 ( V_23 ) )
continue;
F_241 ( V_23 -> V_31 , V_203 ) ;
}
F_147 () ;
}
static int F_245 ( struct V_96 * V_31 , void * V_166 )
{
unsigned long V_69 ;
long V_203 = ( long ) V_166 ;
if ( ! V_31 -> V_32 ) {
V_69 = F_187 ( V_203 ) -> V_69 . V_11 ;
} else {
V_69 = V_31 -> V_32 -> V_23 [ V_203 ] -> V_306 ;
V_69 *= V_31 -> V_26 [ V_203 ] -> V_69 . V_11 ;
V_69 /= V_31 -> V_32 -> V_23 [ V_203 ] -> V_69 . V_11 + 1 ;
}
V_31 -> V_23 [ V_203 ] -> V_306 = V_69 ;
return 0 ;
}
static void F_246 ( long V_203 )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_85 = V_307 ;
if ( V_22 -> V_308 == V_85 )
return;
V_22 -> V_308 = V_85 ;
F_145 () ;
F_247 ( F_245 , V_169 , ( void * ) V_203 ) ;
F_147 () ;
}
static unsigned long F_238 ( struct V_24 * V_27 )
{
struct V_23 * V_23 = F_20 ( V_27 ) ;
unsigned long V_69 ;
V_69 = V_27 -> V_26 . V_69 . V_11 ;
V_69 = F_248 ( V_69 * V_23 -> V_306 , V_23 -> V_69 . V_11 + 1 ) ;
return V_69 ;
}
static inline void F_244 ( int V_203 )
{
}
static inline void F_246 ( long V_203 )
{
}
static unsigned long F_238 ( struct V_24 * V_27 )
{
return V_27 -> V_26 . V_69 . V_11 ;
}
static inline int F_249 ( struct V_211 * V_212 ,
enum V_309 V_157 )
{
int V_229 ;
switch ( V_157 ) {
case V_310 :
V_229 = V_212 -> V_311 ;
break;
case V_305 :
V_229 = V_212 -> V_312 ;
break;
default:
V_229 = V_212 -> V_313 ;
break;
}
return V_229 ;
}
unsigned long F_250 ( struct V_211 * V_212 , int V_203 )
{
return V_239 ;
}
unsigned long __weak F_251 ( struct V_211 * V_212 , int V_203 )
{
return F_250 ( V_212 , V_203 ) ;
}
unsigned long F_252 ( struct V_211 * V_212 , int V_203 )
{
unsigned long V_11 = V_212 -> V_259 ;
unsigned long V_314 = V_212 -> V_314 ;
V_314 /= V_11 ;
return V_314 ;
}
unsigned long __weak F_253 ( struct V_211 * V_212 , int V_203 )
{
return F_252 ( V_212 , V_203 ) ;
}
unsigned long F_254 ( int V_203 )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
T_2 V_204 , V_315 , V_316 , V_317 ;
V_316 = F_192 ( V_22 -> V_316 ) ;
V_317 = F_192 ( V_22 -> V_318 ) ;
V_204 = F_255 () + ( V_22 -> clock - V_316 ) ;
if ( F_11 ( V_204 < V_317 ) ) {
V_315 = 0 ;
} else {
V_315 = V_204 - V_317 ;
}
if ( F_11 ( ( T_3 ) V_204 < V_239 ) )
V_204 = V_239 ;
V_204 >>= V_319 ;
return F_248 ( V_315 , V_204 ) ;
}
static void F_256 ( struct V_211 * V_212 , int V_203 )
{
unsigned long V_11 = V_212 -> V_259 ;
unsigned long V_241 = V_239 ;
struct V_228 * V_320 = V_212 -> V_232 ;
if ( ( V_212 -> V_124 & V_321 ) && V_11 > 1 ) {
if ( F_103 ( V_322 ) )
V_241 *= F_253 ( V_212 , V_203 ) ;
else
V_241 *= F_252 ( V_212 , V_203 ) ;
V_241 >>= V_319 ;
}
V_320 -> V_240 -> V_323 = V_241 ;
if ( F_103 ( V_322 ) )
V_241 *= F_251 ( V_212 , V_203 ) ;
else
V_241 *= F_250 ( V_212 , V_203 ) ;
V_241 >>= V_319 ;
V_241 *= F_254 ( V_203 ) ;
V_241 >>= V_319 ;
if ( ! V_241 )
V_241 = 1 ;
F_187 ( V_203 ) -> V_207 = V_241 ;
V_320 -> V_240 -> V_241 = V_241 ;
}
void F_257 ( struct V_211 * V_212 , int V_203 )
{
struct V_211 * V_258 = V_212 -> V_258 ;
struct V_228 * V_231 , * V_320 = V_212 -> V_232 ;
unsigned long V_241 ;
unsigned long V_324 ;
V_324 = F_258 ( V_212 -> V_325 ) ;
V_324 = F_259 ( V_324 , 1UL , V_326 ) ;
V_320 -> V_240 -> V_327 = V_307 + V_324 ;
if ( ! V_258 ) {
F_256 ( V_212 , V_203 ) ;
return;
}
V_241 = 0 ;
if ( V_258 -> V_124 & V_328 ) {
F_203 (cpu, sched_group_cpus(sdg))
V_241 += F_190 ( V_203 ) ;
} else {
V_231 = V_258 -> V_232 ;
do {
V_241 += V_231 -> V_240 -> V_241 ;
V_231 = V_231 -> V_57 ;
} while ( V_231 != V_258 -> V_232 );
}
V_320 -> V_240 -> V_323 = V_320 -> V_240 -> V_241 = V_241 ;
}
static inline int
F_260 ( struct V_211 * V_212 , struct V_228 * V_231 )
{
if ( ! ( V_212 -> V_124 & V_321 ) )
return 0 ;
if ( V_231 -> V_240 -> V_241 * 32 > V_231 -> V_240 -> V_323 * 29 )
return 1 ;
return 0 ;
}
static inline void F_261 ( struct V_274 * V_275 ,
struct V_228 * V_231 , int V_229 ,
int V_237 , int * V_329 , struct V_330 * V_331 )
{
unsigned long V_71 , V_332 , V_333 ;
unsigned long V_69 , V_334 , V_335 ;
unsigned int V_336 = - 1 , V_337 = 0 ;
unsigned long V_338 = 0 ;
int V_238 ;
if ( V_237 )
V_336 = F_262 ( V_231 ) ;
V_334 = 0 ;
V_335 = ~ 0UL ;
V_332 = 0 ;
V_333 = ~ 0UL ;
F_205 (i, sched_group_cpus(group), env->cpus) {
struct V_22 * V_22 = F_187 ( V_238 ) ;
V_71 = V_22 -> V_71 ;
if ( V_237 ) {
if ( F_207 ( V_238 ) && ! V_337 &&
F_202 ( V_238 , F_263 ( V_231 ) ) ) {
V_337 = 1 ;
V_336 = V_238 ;
}
V_69 = F_189 ( V_238 , V_229 ) ;
} else {
V_69 = F_188 ( V_238 , V_229 ) ;
if ( V_69 > V_334 )
V_334 = V_69 ;
if ( V_335 > V_69 )
V_335 = V_69 ;
if ( V_71 > V_332 )
V_332 = V_71 ;
if ( V_333 > V_71 )
V_333 = V_71 ;
}
V_331 -> V_339 += V_69 ;
V_331 -> V_340 += V_71 ;
V_331 -> V_341 += F_186 ( V_238 ) ;
if ( F_207 ( V_238 ) )
V_331 -> V_342 ++ ;
}
if ( V_237 ) {
if ( V_275 -> V_157 != V_305 ) {
if ( V_336 != V_275 -> V_277 ) {
* V_329 = 0 ;
return;
}
F_257 ( V_275 -> V_212 , V_275 -> V_277 ) ;
} else if ( F_264 ( V_307 , V_231 -> V_240 -> V_327 ) )
F_257 ( V_275 -> V_212 , V_275 -> V_277 ) ;
}
V_331 -> V_236 = ( V_331 -> V_339 * V_239 ) / V_231 -> V_240 -> V_241 ;
if ( V_331 -> V_340 )
V_338 = V_331 -> V_341 / V_331 -> V_340 ;
if ( ( V_334 - V_335 ) >= V_338 &&
( V_332 - V_333 ) > 1 )
V_331 -> V_343 = 1 ;
V_331 -> V_344 = F_265 ( V_231 -> V_240 -> V_241 ,
V_239 ) ;
if ( ! V_331 -> V_344 )
V_331 -> V_344 = F_260 ( V_275 -> V_212 , V_231 ) ;
V_331 -> V_345 = V_231 -> V_345 ;
if ( V_331 -> V_344 > V_331 -> V_340 )
V_331 -> V_346 = 1 ;
}
static bool F_266 ( struct V_274 * V_275 ,
struct V_347 * V_348 ,
struct V_228 * V_243 ,
struct V_330 * V_331 )
{
if ( V_331 -> V_236 <= V_348 -> V_349 )
return false ;
if ( V_331 -> V_340 > V_331 -> V_344 )
return true ;
if ( V_331 -> V_343 )
return true ;
if ( ( V_275 -> V_212 -> V_124 & V_350 ) && V_331 -> V_340 &&
V_275 -> V_277 < F_267 ( V_243 ) ) {
if ( ! V_348 -> V_351 )
return true ;
if ( F_267 ( V_348 -> V_351 ) > F_267 ( V_243 ) )
return true ;
}
return false ;
}
static inline void F_268 ( struct V_274 * V_275 ,
int * V_329 , struct V_347 * V_348 )
{
struct V_211 * V_258 = V_275 -> V_212 -> V_258 ;
struct V_228 * V_243 = V_275 -> V_212 -> V_232 ;
struct V_330 V_331 ;
int V_229 , V_352 = 0 ;
if ( V_258 && V_258 -> V_124 & V_353 )
V_352 = 1 ;
V_229 = F_249 ( V_275 -> V_212 , V_275 -> V_157 ) ;
do {
int V_237 ;
V_237 = F_202 ( V_275 -> V_277 , F_200 ( V_243 ) ) ;
memset ( & V_331 , 0 , sizeof( V_331 ) ) ;
F_261 ( V_275 , V_243 , V_229 , V_237 , V_329 , & V_331 ) ;
if ( V_237 && ! ( * V_329 ) )
return;
V_348 -> V_354 += V_331 . V_339 ;
V_348 -> V_355 += V_243 -> V_240 -> V_241 ;
if ( V_352 && ! V_237 && V_348 -> V_356 )
V_331 . V_344 = F_13 ( V_331 . V_344 , 1UL ) ;
if ( V_237 ) {
V_348 -> V_214 = V_331 . V_236 ;
V_348 -> V_357 = V_243 ;
V_348 -> V_358 = V_331 . V_340 ;
V_348 -> V_359 = V_331 . V_341 ;
V_348 -> V_356 = V_331 . V_346 ;
V_348 -> V_360 = V_331 . V_342 ;
} else if ( F_266 ( V_275 , V_348 , V_243 , & V_331 ) ) {
V_348 -> V_349 = V_331 . V_236 ;
V_348 -> V_351 = V_243 ;
V_348 -> V_361 = V_331 . V_340 ;
V_348 -> V_362 = V_331 . V_342 ;
V_348 -> V_363 = V_331 . V_344 ;
V_348 -> V_364 = V_331 . V_341 ;
V_348 -> V_365 = V_331 . V_346 ;
V_348 -> V_366 = V_331 . V_345 ;
V_348 -> V_343 = V_331 . V_343 ;
}
V_243 = V_243 -> V_57 ;
} while ( V_243 != V_275 -> V_212 -> V_232 );
}
static int F_269 ( struct V_274 * V_275 , struct V_347 * V_348 )
{
int V_367 ;
if ( ! ( V_275 -> V_212 -> V_124 & V_350 ) )
return 0 ;
if ( ! V_348 -> V_351 )
return 0 ;
V_367 = F_267 ( V_348 -> V_351 ) ;
if ( V_275 -> V_277 > V_367 )
return 0 ;
V_275 -> V_235 = F_265 (
V_348 -> V_349 * V_348 -> V_351 -> V_240 -> V_241 , V_239 ) ;
return 1 ;
}
static inline
void F_270 ( struct V_274 * V_275 , struct V_347 * V_348 )
{
unsigned long V_14 , V_368 = 0 , V_369 = 0 ;
unsigned int V_370 = 2 ;
unsigned long V_371 ;
if ( V_348 -> V_358 ) {
V_348 -> V_359 /= V_348 -> V_358 ;
if ( V_348 -> V_364 >
V_348 -> V_359 )
V_370 = 1 ;
} else {
V_348 -> V_359 =
F_191 ( V_275 -> V_277 ) ;
}
V_371 = V_348 -> V_364
* V_239 ;
V_371 /= V_348 -> V_351 -> V_240 -> V_241 ;
if ( V_348 -> V_349 - V_348 -> V_214 + V_371 >=
( V_371 * V_370 ) ) {
V_275 -> V_235 = V_348 -> V_364 ;
return;
}
V_368 += V_348 -> V_351 -> V_240 -> V_241 *
F_13 ( V_348 -> V_364 , V_348 -> V_349 ) ;
V_368 += V_348 -> V_357 -> V_240 -> V_241 *
F_13 ( V_348 -> V_359 , V_348 -> V_214 ) ;
V_368 /= V_239 ;
V_14 = ( V_348 -> V_364 * V_239 ) /
V_348 -> V_351 -> V_240 -> V_241 ;
if ( V_348 -> V_349 > V_14 )
V_369 += V_348 -> V_351 -> V_240 -> V_241 *
F_13 ( V_348 -> V_364 , V_348 -> V_349 - V_14 ) ;
if ( V_348 -> V_349 * V_348 -> V_351 -> V_240 -> V_241 <
V_348 -> V_364 * V_239 )
V_14 = ( V_348 -> V_349 * V_348 -> V_351 -> V_240 -> V_241 ) /
V_348 -> V_357 -> V_240 -> V_241 ;
else
V_14 = ( V_348 -> V_364 * V_239 ) /
V_348 -> V_357 -> V_240 -> V_241 ;
V_369 += V_348 -> V_357 -> V_240 -> V_241 *
F_13 ( V_348 -> V_359 , V_348 -> V_214 + V_14 ) ;
V_369 /= V_239 ;
if ( V_369 > V_368 )
V_275 -> V_235 = V_348 -> V_364 ;
}
static inline void F_271 ( struct V_274 * V_275 , struct V_347 * V_348 )
{
unsigned long V_372 , V_373 = ~ 0UL ;
V_348 -> V_364 /= V_348 -> V_361 ;
if ( V_348 -> V_343 ) {
V_348 -> V_364 =
F_13 ( V_348 -> V_364 , V_348 -> V_236 ) ;
}
if ( V_348 -> V_349 < V_348 -> V_236 ) {
V_275 -> V_235 = 0 ;
return F_270 ( V_275 , V_348 ) ;
}
if ( ! V_348 -> V_343 ) {
V_373 = ( V_348 -> V_361 -
V_348 -> V_363 ) ;
V_373 *= ( V_374 * V_239 ) ;
V_373 /= V_348 -> V_351 -> V_240 -> V_241 ;
}
V_372 = F_13 ( V_348 -> V_349 - V_348 -> V_236 , V_373 ) ;
V_275 -> V_235 = F_13 ( V_372 * V_348 -> V_351 -> V_240 -> V_241 ,
( V_348 -> V_236 - V_348 -> V_214 ) * V_348 -> V_357 -> V_240 -> V_241 )
/ V_239 ;
if ( V_275 -> V_235 < V_348 -> V_364 )
return F_270 ( V_275 , V_348 ) ;
}
static struct V_228 *
F_272 ( struct V_274 * V_275 , int * V_329 )
{
struct V_347 V_348 ;
memset ( & V_348 , 0 , sizeof( V_348 ) ) ;
F_268 ( V_275 , V_329 , & V_348 ) ;
if ( ! ( * V_329 ) )
goto V_65;
if ( ( V_275 -> V_157 == V_375 || V_275 -> V_157 == V_305 ) &&
F_269 ( V_275 , & V_348 ) )
return V_348 . V_351 ;
if ( ! V_348 . V_351 || V_348 . V_361 == 0 )
goto V_376;
V_348 . V_236 = ( V_239 * V_348 . V_354 ) / V_348 . V_355 ;
if ( V_348 . V_343 )
goto V_377;
if ( V_275 -> V_157 == V_305 && V_348 . V_356 &&
! V_348 . V_365 )
goto V_377;
if ( V_348 . V_214 >= V_348 . V_349 )
goto V_376;
if ( V_348 . V_214 >= V_348 . V_236 )
goto V_376;
if ( V_275 -> V_157 == V_375 ) {
if ( ( V_348 . V_360 <= V_348 . V_362 + 1 ) &&
V_348 . V_361 <= V_348 . V_366 )
goto V_376;
} else {
if ( 100 * V_348 . V_349 <= V_275 -> V_212 -> V_224 * V_348 . V_214 )
goto V_376;
}
V_377:
F_271 ( V_275 , & V_348 ) ;
return V_348 . V_351 ;
V_376:
V_65:
V_275 -> V_235 = 0 ;
return NULL ;
}
static struct V_22 * F_273 ( struct V_274 * V_275 ,
struct V_228 * V_231 )
{
struct V_22 * V_351 = NULL , * V_22 ;
unsigned long V_349 = 0 ;
int V_238 ;
F_203 (i, sched_group_cpus(group)) {
unsigned long V_241 = F_190 ( V_238 ) ;
unsigned long V_378 = F_265 ( V_241 ,
V_239 ) ;
unsigned long V_208 ;
if ( ! V_378 )
V_378 = F_260 ( V_275 -> V_212 , V_231 ) ;
if ( ! F_202 ( V_238 , V_275 -> V_1 ) )
continue;
V_22 = F_187 ( V_238 ) ;
V_208 = F_186 ( V_238 ) ;
if ( V_378 && V_22 -> V_71 == 1 && V_208 > V_275 -> V_235 )
continue;
V_208 = ( V_208 * V_239 ) / V_241 ;
if ( V_208 > V_349 ) {
V_349 = V_208 ;
V_351 = V_22 ;
}
}
return V_351 ;
}
static int F_274 ( struct V_274 * V_275 )
{
struct V_211 * V_212 = V_275 -> V_212 ;
if ( V_275 -> V_157 == V_305 ) {
if ( ( V_212 -> V_124 & V_350 ) && V_275 -> V_162 > V_275 -> V_277 )
return 1 ;
}
return F_11 ( V_212 -> V_289 > V_212 -> V_290 + 2 ) ;
}
static int F_275 ( int V_216 , struct V_22 * F_231 ,
struct V_211 * V_212 , enum V_309 V_157 ,
int * V_329 )
{
int V_379 , V_380 , V_381 = 0 ;
int V_382 , V_383 ;
struct V_228 * V_231 ;
struct V_22 * V_351 ;
unsigned long V_124 ;
struct V_384 * V_1 = F_276 ( V_385 ) ;
struct V_274 V_275 = {
. V_212 = V_212 ,
. V_277 = V_216 ,
. V_278 = F_231 ,
. V_284 = F_200 ( V_212 -> V_232 ) ,
. V_157 = V_157 ,
. V_301 = V_302 ,
. V_1 = V_1 ,
} ;
F_277 ( V_1 , V_386 ) ;
V_383 = F_278 ( V_275 . V_284 ) ;
F_101 ( V_212 , V_387 [ V_157 ] ) ;
V_388:
V_231 = F_272 ( & V_275 , V_329 ) ;
if ( * V_329 == 0 )
goto V_376;
if ( ! V_231 ) {
F_101 ( V_212 , V_389 [ V_157 ] ) ;
goto V_376;
}
V_351 = F_273 ( & V_275 , V_231 ) ;
if ( ! V_351 ) {
F_101 ( V_212 , V_390 [ V_157 ] ) ;
goto V_376;
}
F_220 ( V_351 == V_275 . V_278 ) ;
F_63 ( V_212 , V_391 [ V_157 ] , V_275 . V_235 ) ;
V_379 = 0 ;
V_382 = 1 ;
if ( V_351 -> V_71 > 1 ) {
V_275 . V_124 |= V_287 ;
V_275 . V_162 = V_351 -> V_203 ;
V_275 . V_276 = V_351 ;
V_275 . V_300 = F_13 ( V_392 , V_351 -> V_71 ) ;
F_246 ( V_275 . V_162 ) ;
V_393:
F_279 ( V_124 ) ;
F_280 ( V_275 . V_278 , V_351 ) ;
V_380 = F_236 ( & V_275 ) ;
V_379 += V_380 ;
F_281 ( V_275 . V_278 , V_351 ) ;
F_282 ( V_124 ) ;
if ( V_275 . V_124 & V_303 ) {
V_275 . V_124 &= ~ V_303 ;
goto V_393;
}
if ( V_380 && V_275 . V_277 != F_131 () )
F_283 ( V_275 . V_277 ) ;
if ( ( V_275 . V_124 & V_285 ) && V_275 . V_235 > 0 &&
V_382 ++ < V_383 ) {
V_275 . V_278 = F_187 ( V_275 . V_282 ) ;
V_275 . V_277 = V_275 . V_282 ;
V_275 . V_124 &= ~ V_285 ;
V_275 . V_299 = 0 ;
V_275 . V_301 = V_302 ;
goto V_393;
}
if ( F_11 ( V_275 . V_124 & V_287 ) ) {
F_284 ( F_24 ( V_351 ) , V_1 ) ;
if ( ! F_285 ( V_1 ) ) {
V_275 . V_299 = 0 ;
V_275 . V_301 = V_302 ;
goto V_388;
}
goto V_376;
}
}
if ( ! V_379 ) {
F_101 ( V_212 , V_394 [ V_157 ] ) ;
if ( V_157 != V_305 )
V_212 -> V_289 ++ ;
if ( F_274 ( & V_275 ) ) {
F_242 ( & V_351 -> V_155 , V_124 ) ;
if ( ! F_202 ( V_216 ,
F_201 ( V_351 -> V_44 ) ) ) {
F_243 ( & V_351 -> V_155 ,
V_124 ) ;
V_275 . V_124 |= V_287 ;
goto V_395;
}
if ( ! V_351 -> V_381 ) {
V_351 -> V_381 = 1 ;
V_351 -> V_396 = V_216 ;
V_381 = 1 ;
}
F_243 ( & V_351 -> V_155 , V_124 ) ;
if ( V_381 ) {
F_286 ( F_24 ( V_351 ) ,
V_397 , V_351 ,
& V_351 -> V_398 ) ;
}
V_212 -> V_289 = V_212 -> V_290 + 1 ;
}
} else
V_212 -> V_289 = 0 ;
if ( F_9 ( ! V_381 ) ) {
V_212 -> V_325 = V_212 -> V_399 ;
} else {
if ( V_212 -> V_325 < V_212 -> V_400 )
V_212 -> V_325 *= 2 ;
}
goto V_401;
V_376:
F_101 ( V_212 , V_402 [ V_157 ] ) ;
V_212 -> V_289 = 0 ;
V_395:
if ( ( ( V_275 . V_124 & V_287 ) &&
V_212 -> V_325 < V_403 ) ||
( V_212 -> V_325 < V_212 -> V_400 ) )
V_212 -> V_325 *= 2 ;
V_379 = 0 ;
V_401:
return V_379 ;
}
void F_287 ( int V_216 , struct V_22 * F_231 )
{
struct V_211 * V_212 ;
int V_404 = 0 ;
unsigned long V_405 = V_307 + V_406 ;
F_231 -> V_407 = F_231 -> clock ;
if ( F_231 -> V_408 < V_280 )
return;
F_137 ( & F_231 -> V_155 ) ;
F_244 ( V_216 ) ;
F_145 () ;
F_213 (this_cpu, sd) {
unsigned long V_324 ;
int V_329 = 1 ;
if ( ! ( V_212 -> V_124 & V_254 ) )
continue;
if ( V_212 -> V_124 & V_409 ) {
V_404 = F_275 ( V_216 , F_231 ,
V_212 , V_305 , & V_329 ) ;
}
V_324 = F_258 ( V_212 -> V_325 ) ;
if ( F_288 ( V_405 , V_212 -> V_410 + V_324 ) )
V_405 = V_212 -> V_410 + V_324 ;
if ( V_404 ) {
F_231 -> V_407 = 0 ;
break;
}
}
F_147 () ;
F_135 ( & F_231 -> V_155 ) ;
if ( V_404 || F_288 ( V_307 , F_231 -> V_405 ) ) {
F_231 -> V_405 = V_405 ;
}
}
static int V_397 ( void * V_166 )
{
struct V_22 * V_411 = V_166 ;
int V_367 = F_24 ( V_411 ) ;
int V_412 = V_411 -> V_396 ;
struct V_22 * V_413 = F_187 ( V_412 ) ;
struct V_211 * V_212 ;
F_289 ( & V_411 -> V_155 ) ;
if ( F_11 ( V_367 != F_131 () ||
! V_411 -> V_381 ) )
goto V_179;
if ( V_411 -> V_71 <= 1 )
goto V_179;
F_220 ( V_411 == V_413 ) ;
F_290 ( V_411 , V_413 ) ;
F_145 () ;
F_213 (target_cpu, sd) {
if ( ( V_212 -> V_124 & V_254 ) &&
F_202 ( V_367 , F_214 ( V_212 ) ) )
break;
}
if ( F_9 ( V_212 ) ) {
struct V_274 V_275 = {
. V_212 = V_212 ,
. V_277 = V_412 ,
. V_278 = V_413 ,
. V_162 = V_411 -> V_203 ,
. V_276 = V_411 ,
. V_157 = V_375 ,
} ;
F_101 ( V_212 , V_414 ) ;
if ( F_234 ( & V_275 ) )
F_101 ( V_212 , V_415 ) ;
else
F_101 ( V_212 , V_416 ) ;
}
F_147 () ;
F_291 ( V_411 , V_413 ) ;
V_179:
V_411 -> V_381 = 0 ;
F_292 ( & V_411 -> V_155 ) ;
return 0 ;
}
static inline int F_293 ( int V_417 )
{
int V_418 = F_294 ( V_419 . V_420 ) ;
if ( V_418 < V_286 && F_207 ( V_418 ) )
return V_418 ;
return V_286 ;
}
static void F_295 ( int V_203 )
{
int V_421 ;
V_419 . V_405 ++ ;
V_421 = F_293 ( V_203 ) ;
if ( V_421 >= V_286 )
return;
if ( F_296 ( V_422 , F_297 ( V_421 ) ) )
return;
F_298 ( V_421 ) ;
return;
}
static inline void F_299 ( int V_203 )
{
if ( F_11 ( F_300 ( V_423 , F_297 ( V_203 ) ) ) ) {
F_284 ( V_203 , V_419 . V_420 ) ;
F_301 ( & V_419 . V_424 ) ;
F_302 ( V_423 , F_297 ( V_203 ) ) ;
}
}
static inline void F_303 ( void )
{
struct V_211 * V_212 ;
int V_203 = F_131 () ;
if ( ! F_300 ( V_425 , F_297 ( V_203 ) ) )
return;
F_302 ( V_425 , F_297 ( V_203 ) ) ;
F_145 () ;
F_213 (cpu, sd)
F_304 ( & V_212 -> V_232 -> V_240 -> V_426 ) ;
F_147 () ;
}
void F_305 ( void )
{
struct V_211 * V_212 ;
int V_203 = F_131 () ;
if ( F_300 ( V_425 , F_297 ( V_203 ) ) )
return;
F_306 ( V_425 , F_297 ( V_203 ) ) ;
F_145 () ;
F_213 (cpu, sd)
F_301 ( & V_212 -> V_232 -> V_240 -> V_426 ) ;
F_147 () ;
}
void F_307 ( int V_203 )
{
if ( ! F_308 ( V_203 ) )
return;
if ( F_300 ( V_423 , F_297 ( V_203 ) ) )
return;
F_309 ( V_203 , V_419 . V_420 ) ;
F_304 ( & V_419 . V_424 ) ;
F_306 ( V_423 , F_297 ( V_203 ) ) ;
}
static int T_9 F_310 ( struct V_427 * V_428 ,
unsigned long V_429 , void * V_430 )
{
switch ( V_429 & ~ V_431 ) {
case V_432 :
F_299 ( F_131 () ) ;
return V_433 ;
default:
return V_434 ;
}
}
void F_311 ( void )
{
V_326 = V_406 * F_3 () / 10 ;
}
static void F_312 ( int V_203 , enum V_309 V_157 )
{
int V_329 = 1 ;
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_324 ;
struct V_211 * V_212 ;
unsigned long V_405 = V_307 + 60 * V_406 ;
int V_435 = 0 ;
int V_436 ;
F_244 ( V_203 ) ;
F_145 () ;
F_213 (cpu, sd) {
if ( ! ( V_212 -> V_124 & V_254 ) )
continue;
V_324 = V_212 -> V_325 ;
if ( V_157 != V_375 )
V_324 *= V_212 -> V_437 ;
V_324 = F_258 ( V_324 ) ;
V_324 = F_259 ( V_324 , 1UL , V_326 ) ;
V_436 = V_212 -> V_124 & V_438 ;
if ( V_436 ) {
if ( ! F_313 ( & V_439 ) )
goto V_401;
}
if ( F_264 ( V_307 , V_212 -> V_410 + V_324 ) ) {
if ( F_275 ( V_203 , V_22 , V_212 , V_157 , & V_329 ) ) {
V_157 = V_310 ;
}
V_212 -> V_410 = V_307 ;
}
if ( V_436 )
F_314 ( & V_439 ) ;
V_401:
if ( F_288 ( V_405 , V_212 -> V_410 + V_324 ) ) {
V_405 = V_212 -> V_410 + V_324 ;
V_435 = 1 ;
}
if ( ! V_329 )
break;
}
F_147 () ;
if ( F_9 ( V_435 ) )
V_22 -> V_405 = V_405 ;
}
static void F_315 ( int V_216 , enum V_309 V_157 )
{
struct V_22 * F_231 = F_187 ( V_216 ) ;
struct V_22 * V_22 ;
int V_336 ;
if ( V_157 != V_375 ||
! F_300 ( V_422 , F_297 ( V_216 ) ) )
goto V_440;
F_203 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_336 == V_216 || ! F_207 ( V_336 ) )
continue;
if ( F_316 () )
break;
V_22 = F_187 ( V_336 ) ;
F_289 ( & V_22 -> V_155 ) ;
F_149 ( V_22 ) ;
F_317 ( V_22 ) ;
F_292 ( & V_22 -> V_155 ) ;
F_312 ( V_336 , V_375 ) ;
if ( F_288 ( F_231 -> V_405 , V_22 -> V_405 ) )
F_231 -> V_405 = V_22 -> V_405 ;
}
V_419 . V_405 = F_231 -> V_405 ;
V_440:
F_302 ( V_422 , F_297 ( V_216 ) ) ;
}
static inline int F_318 ( struct V_22 * V_22 , int V_203 )
{
unsigned long V_85 = V_307 ;
struct V_211 * V_212 ;
if ( F_11 ( F_207 ( V_203 ) ) )
return 0 ;
F_303 () ;
F_299 ( V_203 ) ;
if ( F_9 ( ! F_87 ( & V_419 . V_424 ) ) )
return 0 ;
if ( F_319 ( V_85 , V_419 . V_405 ) )
return 0 ;
if ( V_22 -> V_71 >= 2 )
goto V_441;
F_145 () ;
F_213 (cpu, sd) {
struct V_228 * V_243 = V_212 -> V_232 ;
struct V_442 * V_240 = V_243 -> V_240 ;
int V_443 = F_87 ( & V_240 -> V_426 ) ;
if ( V_212 -> V_124 & V_444 && V_443 > 1 )
goto V_445;
if ( V_212 -> V_124 & V_350 && V_443 != V_243 -> V_345
&& ( F_211 ( V_419 . V_420 ,
F_214 ( V_212 ) ) < V_203 ) )
goto V_445;
if ( ! ( V_212 -> V_124 & ( V_444 | V_350 ) ) )
break;
}
F_147 () ;
return 0 ;
V_445:
F_147 () ;
V_441:
return 1 ;
}
static void F_315 ( int V_216 , enum V_309 V_157 ) { }
static void F_320 ( struct V_446 * V_447 )
{
int V_216 = F_131 () ;
struct V_22 * F_231 = F_187 ( V_216 ) ;
enum V_309 V_157 = F_231 -> F_287 ?
V_375 : V_310 ;
F_312 ( V_216 , V_157 ) ;
F_315 ( V_216 , V_157 ) ;
}
static inline int F_321 ( int V_203 )
{
return ! F_322 ( F_187 ( V_203 ) -> V_212 ) ;
}
void F_323 ( struct V_22 * V_22 , int V_203 )
{
if ( F_264 ( V_307 , V_22 -> V_405 ) &&
F_9 ( ! F_321 ( V_203 ) ) )
F_324 ( V_448 ) ;
#ifdef F_325
if ( F_318 ( V_22 , V_203 ) && F_9 ( ! F_321 ( V_203 ) ) )
F_295 ( V_203 ) ;
#endif
}
static void F_326 ( struct V_22 * V_22 )
{
F_5 () ;
}
static void F_327 ( struct V_22 * V_22 )
{
F_5 () ;
F_173 ( V_22 ) ;
}
static void F_328 ( struct V_22 * V_22 , struct V_24 * V_44 , int V_137 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_44 -> V_26 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_119 ( V_23 , V_26 , V_137 ) ;
}
}
static void F_329 ( struct V_24 * V_27 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 , * V_44 ;
int V_216 = F_131 () ;
struct V_22 * V_22 = F_231 () ;
unsigned long V_124 ;
F_242 ( & V_22 -> V_155 , V_124 ) ;
F_149 ( V_22 ) ;
V_23 = F_20 ( V_221 ) ;
V_44 = V_23 -> V_44 ;
if ( F_11 ( F_197 ( V_27 ) != V_216 ) ) {
F_145 () ;
F_330 ( V_27 , V_216 ) ;
F_147 () ;
}
F_64 ( V_23 ) ;
if ( V_44 )
V_26 -> V_40 = V_44 -> V_40 ;
F_102 ( V_23 , V_26 , 1 ) ;
if ( V_449 && V_44 && F_36 ( V_44 , V_26 ) ) {
F_331 ( V_44 -> V_40 , V_26 -> V_40 ) ;
F_113 ( V_22 -> V_44 ) ;
}
V_26 -> V_40 -= V_23 -> V_39 ;
F_243 ( & V_22 -> V_155 , V_124 ) ;
}
static void
F_332 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_450 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 ) {
if ( V_27 -> V_451 > V_450 )
F_113 ( V_22 -> V_44 ) ;
} else
F_229 ( V_22 , V_27 , 0 ) ;
}
static void F_333 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 && V_27 -> V_129 != V_452 ) {
F_102 ( V_23 , V_26 , 0 ) ;
V_26 -> V_40 -= V_23 -> V_39 ;
}
}
static void F_334 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 )
F_113 ( V_22 -> V_44 ) ;
else
F_229 ( V_22 , V_27 , 0 ) ;
}
static void F_335 ( struct V_22 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_44 -> V_26 ;
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_114 ( V_23 , V_26 ) ;
F_68 ( V_23 , 0 ) ;
}
}
void F_336 ( struct V_23 * V_23 )
{
V_23 -> V_50 = V_453 ;
V_23 -> V_39 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_39
V_23 -> V_47 = V_23 -> V_39 ;
#endif
}
static void F_337 ( struct V_24 * V_27 , int V_75 )
{
if ( ! V_75 && ( ! V_27 -> V_26 . V_79 || V_27 -> V_129 == V_454 ) )
V_75 = 1 ;
if ( ! V_75 )
V_27 -> V_26 . V_40 -= F_21 ( & V_27 -> V_26 ) -> V_39 ;
F_338 ( V_27 , F_197 ( V_27 ) ) ;
if ( ! V_75 )
V_27 -> V_26 . V_40 += F_21 ( & V_27 -> V_26 ) -> V_39 ;
}
void F_339 ( struct V_96 * V_31 )
{
int V_238 ;
F_172 ( F_133 ( V_31 ) ) ;
F_340 (i) {
if ( V_31 -> V_23 )
F_341 ( V_31 -> V_23 [ V_238 ] ) ;
if ( V_31 -> V_26 )
F_341 ( V_31 -> V_26 [ V_238 ] ) ;
}
F_341 ( V_31 -> V_23 ) ;
F_341 ( V_31 -> V_26 ) ;
}
int F_342 ( struct V_96 * V_31 , struct V_96 * V_32 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 ;
int V_238 ;
V_31 -> V_23 = F_343 ( sizeof( V_23 ) * V_286 , V_455 ) ;
if ( ! V_31 -> V_23 )
goto V_456;
V_31 -> V_26 = F_343 ( sizeof( V_26 ) * V_286 , V_455 ) ;
if ( ! V_31 -> V_26 )
goto V_456;
V_31 -> V_105 = V_70 ;
F_166 ( F_133 ( V_31 ) ) ;
F_340 (i) {
V_23 = F_344 ( sizeof( struct V_23 ) ,
V_455 , F_345 ( V_238 ) ) ;
if ( ! V_23 )
goto V_456;
V_26 = F_344 ( sizeof( struct V_25 ) ,
V_455 , F_345 ( V_238 ) ) ;
if ( ! V_26 )
goto V_457;
F_336 ( V_23 ) ;
F_346 ( V_31 , V_23 , V_26 , V_238 , V_32 -> V_26 [ V_238 ] ) ;
}
return 1 ;
V_457:
F_341 ( V_23 ) ;
V_456:
return 0 ;
}
void F_347 ( struct V_96 * V_31 , int V_203 )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
unsigned long V_124 ;
if ( ! V_31 -> V_23 [ V_203 ] -> V_30 )
return;
F_242 ( & V_22 -> V_155 , V_124 ) ;
F_27 ( V_31 -> V_23 [ V_203 ] ) ;
F_243 ( & V_22 -> V_155 , V_124 ) ;
}
void F_346 ( struct V_96 * V_31 , struct V_23 * V_23 ,
struct V_25 * V_26 , int V_203 ,
struct V_25 * V_32 )
{
struct V_22 * V_22 = F_187 ( V_203 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_22 = V_22 ;
#ifdef V_82
V_23 -> V_102 = 1 ;
#endif
F_170 ( V_23 ) ;
V_31 -> V_23 [ V_203 ] = V_23 ;
V_31 -> V_26 [ V_203 ] = V_26 ;
if ( ! V_26 )
return;
if ( ! V_32 )
V_26 -> V_23 = & V_22 -> V_38 ;
else
V_26 -> V_23 = V_32 -> V_29 ;
V_26 -> V_29 = V_23 ;
F_92 ( & V_26 -> V_69 , 0 ) ;
V_26 -> V_32 = V_32 ;
}
int F_348 ( struct V_96 * V_31 , unsigned long V_105 )
{
int V_238 ;
unsigned long V_124 ;
if ( ! V_31 -> V_26 [ 0 ] )
return - V_458 ;
V_105 = F_259 ( V_105 , F_349 ( V_106 ) , F_349 ( V_459 ) ) ;
F_350 ( & V_460 ) ;
if ( V_31 -> V_105 == V_105 )
goto V_245;
V_31 -> V_105 = V_105 ;
F_340 (i) {
struct V_22 * V_22 = F_187 ( V_238 ) ;
struct V_25 * V_26 ;
V_26 = V_31 -> V_26 [ V_238 ] ;
F_242 ( & V_22 -> V_155 , V_124 ) ;
F_32 (se)
F_90 ( F_22 ( V_26 ) ) ;
F_243 ( & V_22 -> V_155 , V_124 ) ;
}
V_245:
F_351 ( & V_460 ) ;
return 0 ;
}
void F_339 ( struct V_96 * V_31 ) { }
int F_342 ( struct V_96 * V_31 , struct V_96 * V_32 )
{
return 1 ;
}
void F_347 ( struct V_96 * V_31 , int V_203 ) { }
static unsigned int F_352 ( struct V_22 * V_22 , struct V_24 * V_461 )
{
struct V_25 * V_26 = & V_461 -> V_26 ;
unsigned int V_462 = 0 ;
if ( V_22 -> V_38 . V_69 . V_11 )
V_462 = F_353 ( F_57 ( & V_22 -> V_38 , V_26 ) ) ;
return V_462 ;
}
void F_354 ( struct V_463 * V_464 , int V_203 )
{
struct V_23 * V_23 ;
F_145 () ;
F_174 (cpu_rq(cpu), cfs_rq)
F_355 ( V_464 , V_203 , V_23 ) ;
F_147 () ;
}
T_10 void F_356 ( void )
{
#ifdef V_82
F_357 ( V_448 , F_320 ) ;
#ifdef F_325
V_419 . V_405 = V_307 ;
F_358 ( & V_419 . V_420 , V_465 ) ;
F_359 ( F_310 , 0 ) ;
#endif
#endif
}
