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
F_76 ( struct V_23 * V_23 , unsigned long V_11 )
{
V_23 -> V_93 += V_11 ;
}
static inline void
F_76 ( struct V_23 * V_23 , unsigned long V_11 )
{
}
static void
F_77 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_58 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_30 ( V_26 ) )
F_58 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( F_18 ( V_26 ) ) {
F_76 ( V_23 , V_26 -> V_69 . V_11 ) ;
F_78 ( & V_26 -> V_94 , & V_23 -> V_95 ) ;
}
V_23 -> V_71 ++ ;
}
static void
F_79 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
F_80 ( & V_23 -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( ! F_30 ( V_26 ) )
F_80 ( & F_14 ( V_23 ) -> V_69 , V_26 -> V_69 . V_11 ) ;
if ( F_18 ( V_26 ) ) {
F_76 ( V_23 , - V_26 -> V_69 . V_11 ) ;
F_81 ( & V_26 -> V_94 ) ;
}
V_23 -> V_71 -- ;
}
static void F_82 ( struct V_23 * V_23 ,
int V_96 )
{
struct V_97 * V_31 = V_23 -> V_31 ;
long V_98 ;
V_98 = F_83 ( V_23 -> V_98 , V_23 -> V_99 + 1 ) ;
V_98 -= V_23 -> V_100 ;
if ( V_96 || abs ( V_98 ) > V_23 -> V_100 / 8 ) {
F_84 ( V_98 , & V_31 -> V_12 ) ;
V_23 -> V_100 += V_98 ;
}
}
static void F_85 ( struct V_23 * V_23 , int V_96 )
{
T_2 V_72 = V_101 ;
T_2 V_85 , V_41 ;
unsigned long V_69 = V_23 -> V_69 . V_11 ;
if ( V_23 -> V_31 == & V_102 || F_86 ( V_23 ) )
return;
V_85 = F_14 ( V_23 ) -> V_86 ;
V_41 = V_85 - V_23 -> V_103 ;
if ( V_23 -> V_103 > V_23 -> V_104 &&
V_85 - V_23 -> V_104 > 4 * V_72 ) {
V_23 -> V_99 = 0 ;
V_23 -> V_98 = 0 ;
V_41 = V_72 - 1 ;
}
V_23 -> V_103 = V_85 ;
V_23 -> V_84 = 0 ;
V_23 -> V_99 += V_41 ;
if ( V_69 ) {
V_23 -> V_104 = V_85 ;
V_23 -> V_98 += V_41 * V_69 ;
}
if ( V_96 || V_23 -> V_99 > V_72
|| ! V_23 -> V_99 )
F_82 ( V_23 , V_96 ) ;
while ( V_23 -> V_99 > V_72 ) {
asm("" : "+rm" (cfs_rq->load_period));
V_23 -> V_99 /= 2 ;
V_23 -> V_98 /= 2 ;
}
if ( ! V_23 -> V_44 && ! V_23 -> V_71 && ! V_23 -> V_98 )
F_27 ( V_23 ) ;
}
static inline long F_87 ( struct V_97 * V_31 , struct V_23 * V_23 )
{
long V_105 ;
V_105 = F_88 ( & V_31 -> V_12 ) ;
V_105 -= V_23 -> V_100 ;
V_105 += V_23 -> V_69 . V_11 ;
return V_105 ;
}
static long F_89 ( struct V_23 * V_23 , struct V_97 * V_31 )
{
long V_105 , V_69 , V_106 ;
V_105 = F_87 ( V_31 , V_23 ) ;
V_69 = V_23 -> V_69 . V_11 ;
V_106 = ( V_31 -> V_106 * V_69 ) ;
if ( V_105 )
V_106 /= V_105 ;
if ( V_106 < V_107 )
V_106 = V_107 ;
if ( V_106 > V_31 -> V_106 )
V_106 = V_31 -> V_106 ;
return V_106 ;
}
static void F_90 ( struct V_23 * V_23 )
{
if ( V_23 -> V_84 > V_101 ) {
F_85 ( V_23 , 0 ) ;
F_91 ( V_23 ) ;
}
}
static void F_85 ( struct V_23 * V_23 , int V_96 )
{
}
static inline long F_89 ( struct V_23 * V_23 , struct V_97 * V_31 )
{
return V_31 -> V_106 ;
}
static inline void F_90 ( struct V_23 * V_23 )
{
}
static void F_92 ( struct V_23 * V_23 , struct V_25 * V_26 ,
unsigned long V_11 )
{
if ( V_26 -> V_75 ) {
if ( V_23 -> V_44 == V_26 )
F_64 ( V_23 ) ;
F_79 ( V_23 , V_26 ) ;
}
F_93 ( & V_26 -> V_69 , V_11 ) ;
if ( V_26 -> V_75 )
F_77 ( V_23 , V_26 ) ;
}
static void F_91 ( struct V_23 * V_23 )
{
struct V_97 * V_31 ;
struct V_25 * V_26 ;
long V_106 ;
V_31 = V_23 -> V_31 ;
V_26 = V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
if ( ! V_26 || F_86 ( V_23 ) )
return;
#ifndef V_82
if ( F_9 ( V_26 -> V_69 . V_11 == V_31 -> V_106 ) )
return;
#endif
V_106 = F_89 ( V_23 , V_31 ) ;
F_92 ( F_21 ( V_26 ) , V_26 , V_106 ) ;
}
static void F_85 ( struct V_23 * V_23 , int V_96 )
{
}
static inline void F_91 ( struct V_23 * V_23 )
{
}
static inline void F_90 ( struct V_23 * V_23 )
{
}
static void F_94 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_72
struct V_24 * V_108 = NULL ;
if ( F_18 ( V_26 ) )
V_108 = F_15 ( V_26 ) ;
if ( V_26 -> V_77 . V_109 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_109 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_110 ) )
V_26 -> V_77 . V_110 = V_41 ;
V_26 -> V_77 . V_109 = 0 ;
V_26 -> V_77 . V_111 += V_41 ;
if ( V_108 ) {
F_95 ( V_108 , V_41 >> 10 , 1 ) ;
F_96 ( V_108 , V_41 ) ;
}
}
if ( V_26 -> V_77 . V_112 ) {
T_2 V_41 = F_14 ( V_23 ) -> clock - V_26 -> V_77 . V_112 ;
if ( ( T_3 ) V_41 < 0 )
V_41 = 0 ;
if ( F_11 ( V_41 > V_26 -> V_77 . V_113 ) )
V_26 -> V_77 . V_113 = V_41 ;
V_26 -> V_77 . V_112 = 0 ;
V_26 -> V_77 . V_111 += V_41 ;
if ( V_108 ) {
if ( V_108 -> V_114 ) {
V_26 -> V_77 . V_115 += V_41 ;
V_26 -> V_77 . V_116 ++ ;
F_97 ( V_108 , V_41 ) ;
}
F_98 ( V_108 , V_41 ) ;
if ( F_11 ( V_117 == V_118 ) ) {
F_99 ( V_118 ,
( void * ) F_100 ( V_108 ) ,
V_41 >> 20 ) ;
}
F_95 ( V_108 , V_41 >> 10 , 0 ) ;
}
}
#endif
}
static void F_101 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
#ifdef F_16
T_3 V_119 = V_26 -> V_40 - V_23 -> V_39 ;
if ( V_119 < 0 )
V_119 = - V_119 ;
if ( V_119 > 3 * V_67 )
F_102 ( V_23 , V_120 ) ;
#endif
}
static void
F_103 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_121 )
{
T_2 V_40 = V_23 -> V_39 ;
if ( V_121 && F_104 ( V_122 ) )
V_40 += F_59 ( V_23 , V_26 ) ;
if ( ! V_121 ) {
unsigned long V_123 = V_67 ;
if ( F_104 ( V_124 ) )
V_123 >>= 1 ;
V_40 -= V_123 ;
}
V_40 = F_35 ( V_26 -> V_40 , V_40 ) ;
V_26 -> V_40 = V_40 ;
}
static void
F_105 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_125 )
{
if ( ! ( V_125 & V_126 ) || ( V_125 & V_127 ) )
V_26 -> V_40 += V_23 -> V_39 ;
F_64 ( V_23 ) ;
F_85 ( V_23 , 0 ) ;
F_77 ( V_23 , V_26 ) ;
F_91 ( V_23 ) ;
if ( V_125 & V_126 ) {
F_103 ( V_23 , V_26 , 0 ) ;
F_94 ( V_23 , V_26 ) ;
}
F_70 ( V_23 , V_26 ) ;
F_101 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_41 ( V_23 , V_26 ) ;
V_26 -> V_75 = 1 ;
if ( V_23 -> V_71 == 1 ) {
F_23 ( V_23 ) ;
F_106 ( V_23 ) ;
}
}
static void F_107 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_58 == V_26 )
V_23 -> V_58 = NULL ;
else
break;
}
}
static void F_108 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
V_23 -> V_57 = NULL ;
else
break;
}
}
static void F_109 ( struct V_25 * V_26 )
{
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( V_23 -> V_128 == V_26 )
V_23 -> V_128 = NULL ;
else
break;
}
}
static void F_110 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_23 -> V_58 == V_26 )
F_107 ( V_26 ) ;
if ( V_23 -> V_57 == V_26 )
F_108 ( V_26 ) ;
if ( V_23 -> V_128 == V_26 )
F_109 ( V_26 ) ;
}
static void
F_111 ( struct V_23 * V_23 , struct V_25 * V_26 , int V_125 )
{
F_64 ( V_23 ) ;
F_74 ( V_23 , V_26 ) ;
if ( V_125 & V_129 ) {
#ifdef F_72
if ( F_18 ( V_26 ) ) {
struct V_24 * V_108 = F_15 ( V_26 ) ;
if ( V_108 -> V_130 & V_131 )
V_26 -> V_77 . V_109 = F_14 ( V_23 ) -> clock ;
if ( V_108 -> V_130 & V_132 )
V_26 -> V_77 . V_112 = F_14 ( V_23 ) -> clock ;
}
#endif
}
F_110 ( V_23 , V_26 ) ;
if ( V_26 != V_23 -> V_44 )
F_44 ( V_23 , V_26 ) ;
V_26 -> V_75 = 0 ;
F_85 ( V_23 , 0 ) ;
F_79 ( V_23 , V_26 ) ;
if ( ! ( V_125 & V_129 ) )
V_26 -> V_40 -= V_23 -> V_39 ;
F_112 ( V_23 ) ;
F_37 ( V_23 ) ;
F_91 ( V_23 ) ;
}
static void
F_113 ( struct V_23 * V_23 , struct V_25 * V_44 )
{
unsigned long V_133 , V_10 ;
struct V_25 * V_26 ;
T_3 V_41 ;
V_133 = F_57 ( V_23 , V_44 ) ;
V_10 = V_44 -> V_79 - V_44 -> V_134 ;
if ( V_10 > V_133 ) {
F_114 ( F_14 ( V_23 ) -> V_44 ) ;
F_110 ( V_23 , V_44 ) ;
return;
}
if ( V_10 < V_68 )
return;
V_26 = F_47 ( V_23 ) ;
V_41 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_41 < 0 )
return;
if ( V_41 > V_133 )
F_114 ( F_14 ( V_23 ) -> V_44 ) ;
}
static void
F_115 ( struct V_23 * V_23 , struct V_25 * V_26 )
{
if ( V_26 -> V_75 ) {
F_71 ( V_23 , V_26 ) ;
F_44 ( V_23 , V_26 ) ;
}
F_75 ( V_23 , V_26 ) ;
V_23 -> V_44 = V_26 ;
#ifdef F_72
if ( F_14 ( V_23 ) -> V_69 . V_11 >= 2 * V_26 -> V_69 . V_11 ) {
V_26 -> V_77 . V_135 = F_62 ( V_26 -> V_77 . V_135 ,
V_26 -> V_79 - V_26 -> V_134 ) ;
}
#endif
V_26 -> V_134 = V_26 -> V_79 ;
}
static struct V_25 * F_116 ( struct V_23 * V_23 )
{
struct V_25 * V_26 = F_47 ( V_23 ) ;
struct V_25 * V_56 = V_26 ;
if ( V_23 -> V_128 == V_26 ) {
struct V_25 * V_136 = F_48 ( V_26 ) ;
if ( V_136 && F_117 ( V_136 , V_56 ) < 1 )
V_26 = V_136 ;
}
if ( V_23 -> V_58 && F_117 ( V_23 -> V_58 , V_56 ) < 1 )
V_26 = V_23 -> V_58 ;
if ( V_23 -> V_57 && F_117 ( V_23 -> V_57 , V_56 ) < 1 )
V_26 = V_23 -> V_57 ;
F_110 ( V_23 , V_26 ) ;
return V_26 ;
}
static void F_118 ( struct V_23 * V_23 , struct V_25 * V_137 )
{
if ( V_137 -> V_75 )
F_64 ( V_23 ) ;
F_119 ( V_23 ) ;
F_101 ( V_23 , V_137 ) ;
if ( V_137 -> V_75 ) {
F_69 ( V_23 , V_137 ) ;
F_41 ( V_23 , V_137 ) ;
}
V_23 -> V_44 = NULL ;
}
static void
F_120 ( struct V_23 * V_23 , struct V_25 * V_44 , int V_138 )
{
F_64 ( V_23 ) ;
F_90 ( V_23 ) ;
#ifdef F_121
if ( V_138 ) {
F_114 ( F_14 ( V_23 ) -> V_44 ) ;
return;
}
if ( ! F_104 ( V_139 ) &&
F_122 ( & F_14 ( V_23 ) -> V_140 ) )
return;
#endif
if ( V_23 -> V_71 > 1 )
F_113 ( V_23 , V_44 ) ;
}
static inline bool F_123 ( void )
{
return F_124 ( & V_141 ) ;
}
void F_125 ( int V_142 , int V_143 )
{
if ( V_142 && ! V_143 )
F_126 ( & V_141 ) ;
else if ( ! V_142 && V_143 )
F_127 ( & V_141 ) ;
}
static bool F_123 ( void )
{
return true ;
}
void F_125 ( int V_142 , int V_143 ) {}
static inline T_2 F_128 ( void )
{
return 100000000ULL ;
}
static inline T_2 F_129 ( void )
{
return ( T_2 ) V_144 * V_145 ;
}
void F_130 ( struct V_146 * V_147 )
{
T_2 V_85 ;
if ( V_147 -> V_148 == V_149 )
return;
V_85 = F_131 ( F_132 () ) ;
V_147 -> V_150 = V_147 -> V_148 ;
V_147 -> V_151 = V_85 + F_133 ( V_147 -> V_72 ) ;
}
static inline struct V_146 * F_134 ( struct V_97 * V_31 )
{
return & V_31 -> V_146 ;
}
static int F_135 ( struct V_23 * V_23 )
{
struct V_97 * V_31 = V_23 -> V_31 ;
struct V_146 * V_147 = F_134 ( V_31 ) ;
T_2 V_152 = 0 , V_153 , V_154 ;
V_153 = F_129 () - V_23 -> V_155 ;
F_136 ( & V_147 -> V_156 ) ;
if ( V_147 -> V_148 == V_149 )
V_152 = V_153 ;
else {
if ( ! V_147 -> V_157 ) {
F_130 ( V_147 ) ;
F_137 ( V_147 ) ;
}
if ( V_147 -> V_150 > 0 ) {
V_152 = F_13 ( V_147 -> V_150 , V_153 ) ;
V_147 -> V_150 -= V_152 ;
V_147 -> V_158 = 0 ;
}
}
V_154 = V_147 -> V_151 ;
F_138 ( & V_147 -> V_156 ) ;
V_23 -> V_155 += V_152 ;
if ( ( T_3 ) ( V_154 - V_23 -> V_151 ) > 0 )
V_23 -> V_151 = V_154 ;
return V_23 -> V_155 > 0 ;
}
static void F_139 ( struct V_23 * V_23 )
{
struct V_146 * V_147 = F_134 ( V_23 -> V_31 ) ;
struct V_22 * V_22 = F_14 ( V_23 ) ;
if ( F_9 ( ( T_3 ) ( V_22 -> clock - V_23 -> V_151 ) < 0 ) )
return;
if ( V_23 -> V_155 < 0 )
return;
if ( ( T_3 ) ( V_23 -> V_151 - V_147 -> V_151 ) >= 0 ) {
V_23 -> V_151 += V_159 ;
} else {
V_23 -> V_155 = 0 ;
}
}
static void F_140 ( struct V_23 * V_23 ,
unsigned long V_10 )
{
V_23 -> V_155 -= V_10 ;
F_139 ( V_23 ) ;
if ( F_9 ( V_23 -> V_155 > 0 ) )
return;
if ( ! F_135 ( V_23 ) && F_9 ( V_23 -> V_44 ) )
F_114 ( F_14 ( V_23 ) -> V_44 ) ;
}
static T_7 void F_68 ( struct V_23 * V_23 ,
unsigned long V_10 )
{
if ( ! F_123 () || ! V_23 -> V_160 )
return;
F_140 ( V_23 , V_10 ) ;
}
static inline int F_141 ( struct V_23 * V_23 )
{
return F_123 () && V_23 -> V_161 ;
}
static inline int F_86 ( struct V_23 * V_23 )
{
return F_123 () && V_23 -> V_162 ;
}
static inline int F_142 ( struct V_97 * V_31 ,
int V_163 , int V_164 )
{
struct V_23 * V_165 , * V_166 ;
V_165 = V_31 -> V_23 [ V_163 ] ;
V_166 = V_31 -> V_23 [ V_164 ] ;
return F_86 ( V_165 ) ||
F_86 ( V_166 ) ;
}
static int F_143 ( struct V_97 * V_31 , void * V_167 )
{
struct V_22 * V_22 = V_167 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
V_23 -> V_162 -- ;
#ifdef V_82
if ( ! V_23 -> V_162 ) {
T_2 V_41 = V_22 -> V_86 - V_23 -> V_103 ;
V_23 -> V_103 += V_41 ;
V_23 -> V_104 += V_41 ;
F_91 ( V_23 ) ;
}
#endif
return 0 ;
}
static int F_144 ( struct V_97 * V_31 , void * V_167 )
{
struct V_22 * V_22 = V_167 ;
struct V_23 * V_23 = V_31 -> V_23 [ F_24 ( V_22 ) ] ;
if ( ! V_23 -> V_162 )
F_85 ( V_23 , 0 ) ;
V_23 -> V_162 ++ ;
return 0 ;
}
static void F_145 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_146 * V_147 = F_134 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
long V_168 , V_169 = 1 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
F_146 () ;
F_147 ( V_23 -> V_31 , F_144 , V_170 , ( void * ) V_22 ) ;
F_148 () ;
V_168 = V_23 -> V_171 ;
F_32 (se) {
struct V_23 * V_172 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 )
break;
if ( V_169 )
F_111 ( V_172 , V_26 , V_129 ) ;
V_172 -> V_171 -= V_168 ;
if ( V_172 -> V_69 . V_11 )
V_169 = 0 ;
}
if ( ! V_26 )
V_22 -> V_71 -= V_168 ;
V_23 -> V_161 = 1 ;
V_23 -> V_173 = V_22 -> clock ;
F_136 ( & V_147 -> V_156 ) ;
F_26 ( & V_23 -> V_174 , & V_147 -> V_175 ) ;
F_138 ( & V_147 -> V_156 ) ;
}
void F_149 ( struct V_23 * V_23 )
{
struct V_22 * V_22 = F_14 ( V_23 ) ;
struct V_146 * V_147 = F_134 ( V_23 -> V_31 ) ;
struct V_25 * V_26 ;
int V_176 = 1 ;
long V_168 ;
V_26 = V_23 -> V_31 -> V_26 [ F_24 ( F_14 ( V_23 ) ) ] ;
V_23 -> V_161 = 0 ;
F_136 ( & V_147 -> V_156 ) ;
V_147 -> V_177 += V_22 -> clock - V_23 -> V_173 ;
F_28 ( & V_23 -> V_174 ) ;
F_138 ( & V_147 -> V_156 ) ;
V_23 -> V_173 = 0 ;
F_150 ( V_22 ) ;
F_147 ( V_23 -> V_31 , V_170 , F_143 , ( void * ) V_22 ) ;
if ( ! V_23 -> V_69 . V_11 )
return;
V_168 = V_23 -> V_171 ;
F_32 (se) {
if ( V_26 -> V_75 )
V_176 = 0 ;
V_23 = F_21 ( V_26 ) ;
if ( V_176 )
F_105 ( V_23 , V_26 , V_126 ) ;
V_23 -> V_171 += V_168 ;
if ( F_141 ( V_23 ) )
break;
}
if ( ! V_26 )
V_22 -> V_71 += V_168 ;
if ( V_22 -> V_44 == V_22 -> V_158 && V_22 -> V_38 . V_71 )
F_114 ( V_22 -> V_44 ) ;
}
static T_2 F_151 ( struct V_146 * V_147 ,
T_2 V_178 , T_2 V_154 )
{
struct V_23 * V_23 ;
T_2 V_150 = V_178 ;
F_146 () ;
F_152 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_22 * V_22 = F_14 ( V_23 ) ;
F_136 ( & V_22 -> V_156 ) ;
if ( ! F_141 ( V_23 ) )
goto V_57;
V_150 = - V_23 -> V_155 + 1 ;
if ( V_150 > V_178 )
V_150 = V_178 ;
V_178 -= V_150 ;
V_23 -> V_155 += V_150 ;
V_23 -> V_151 = V_154 ;
if ( V_23 -> V_155 > 0 )
F_149 ( V_23 ) ;
V_57:
F_138 ( & V_22 -> V_156 ) ;
if ( ! V_178 )
break;
}
F_148 () ;
return V_178 ;
}
static int F_153 ( struct V_146 * V_147 , int V_179 )
{
T_2 V_150 , V_151 ;
int V_158 = 1 , V_161 ;
F_136 ( & V_147 -> V_156 ) ;
if ( V_147 -> V_148 == V_149 )
goto V_180;
V_161 = ! F_154 ( & V_147 -> V_175 ) ;
V_158 = V_147 -> V_158 && ! V_161 ;
V_147 -> V_181 += V_179 ;
if ( V_158 )
goto V_180;
F_130 ( V_147 ) ;
if ( ! V_161 ) {
V_147 -> V_158 = 1 ;
goto V_180;
}
V_147 -> V_182 += V_179 ;
V_150 = V_147 -> V_150 ;
V_151 = V_147 -> V_151 ;
V_147 -> V_150 = 0 ;
while ( V_161 && V_150 > 0 ) {
F_138 ( & V_147 -> V_156 ) ;
V_150 = F_151 ( V_147 , V_150 ,
V_151 ) ;
F_136 ( & V_147 -> V_156 ) ;
V_161 = ! F_154 ( & V_147 -> V_175 ) ;
}
V_147 -> V_150 = V_150 ;
V_147 -> V_158 = 0 ;
V_180:
if ( V_158 )
V_147 -> V_157 = 0 ;
F_138 ( & V_147 -> V_156 ) ;
return V_158 ;
}
static int F_155 ( struct V_146 * V_147 , T_2 V_183 )
{
struct V_184 * V_185 = & V_147 -> V_186 ;
T_2 V_178 ;
if ( F_156 ( V_185 ) )
return 1 ;
V_178 = F_133 ( F_157 ( V_185 ) ) ;
if ( V_178 < V_183 )
return 1 ;
return 0 ;
}
static void F_158 ( struct V_146 * V_147 )
{
T_2 V_187 = V_188 + V_189 ;
if ( F_155 ( V_147 , V_187 ) )
return;
F_159 ( & V_147 -> V_190 ,
F_160 ( V_188 ) ) ;
}
static void F_161 ( struct V_23 * V_23 )
{
struct V_146 * V_147 = F_134 ( V_23 -> V_31 ) ;
T_3 V_191 = V_23 -> V_155 - V_192 ;
if ( V_191 <= 0 )
return;
F_136 ( & V_147 -> V_156 ) ;
if ( V_147 -> V_148 != V_149 &&
V_23 -> V_151 == V_147 -> V_151 ) {
V_147 -> V_150 += V_191 ;
if ( V_147 -> V_150 > F_129 () &&
! F_154 ( & V_147 -> V_175 ) )
F_158 ( V_147 ) ;
}
F_138 ( & V_147 -> V_156 ) ;
V_23 -> V_155 -= V_191 ;
}
static T_7 void F_112 ( struct V_23 * V_23 )
{
if ( ! F_123 () )
return;
if ( ! V_23 -> V_160 || V_23 -> V_71 )
return;
F_161 ( V_23 ) ;
}
static void F_162 ( struct V_146 * V_147 )
{
T_2 V_150 = 0 , V_74 = F_129 () ;
T_2 V_154 ;
if ( F_155 ( V_147 , V_189 ) )
return;
F_136 ( & V_147 -> V_156 ) ;
if ( V_147 -> V_148 != V_149 && V_147 -> V_150 > V_74 ) {
V_150 = V_147 -> V_150 ;
V_147 -> V_150 = 0 ;
}
V_154 = V_147 -> V_151 ;
F_138 ( & V_147 -> V_156 ) ;
if ( ! V_150 )
return;
V_150 = F_151 ( V_147 , V_150 , V_154 ) ;
F_136 ( & V_147 -> V_156 ) ;
if ( V_154 == V_147 -> V_151 )
V_147 -> V_150 = V_150 ;
F_138 ( & V_147 -> V_156 ) ;
}
static void F_106 ( struct V_23 * V_23 )
{
if ( ! F_123 () )
return;
if ( ! V_23 -> V_160 || V_23 -> V_44 )
return;
if ( F_141 ( V_23 ) )
return;
F_68 ( V_23 , 0 ) ;
if ( V_23 -> V_155 <= 0 )
F_145 ( V_23 ) ;
}
static void F_119 ( struct V_23 * V_23 )
{
if ( ! F_123 () )
return;
if ( F_9 ( ! V_23 -> V_160 || V_23 -> V_155 > 0 ) )
return;
if ( F_141 ( V_23 ) )
return;
F_145 ( V_23 ) ;
}
static enum V_193 F_163 ( struct V_184 * V_194 )
{
struct V_146 * V_147 =
F_19 ( V_194 , struct V_146 , V_190 ) ;
F_162 ( V_147 ) ;
return V_195 ;
}
static enum V_193 F_164 ( struct V_184 * V_194 )
{
struct V_146 * V_147 =
F_19 ( V_194 , struct V_146 , V_186 ) ;
T_8 V_85 ;
int V_179 ;
int V_158 = 0 ;
for (; ; ) {
V_85 = F_165 ( V_194 ) ;
V_179 = F_166 ( V_194 , V_85 , V_147 -> V_72 ) ;
if ( ! V_179 )
break;
V_158 = F_153 ( V_147 , V_179 ) ;
}
return V_158 ? V_195 : V_196 ;
}
void F_167 ( struct V_146 * V_147 )
{
F_168 ( & V_147 -> V_156 ) ;
V_147 -> V_150 = 0 ;
V_147 -> V_148 = V_149 ;
V_147 -> V_72 = F_160 ( F_128 () ) ;
F_169 ( & V_147 -> V_175 ) ;
F_170 ( & V_147 -> V_186 , V_197 , V_198 ) ;
V_147 -> V_186 . V_199 = F_164 ;
F_170 ( & V_147 -> V_190 , V_197 , V_198 ) ;
V_147 -> V_190 . V_199 = F_163 ;
}
static void F_171 ( struct V_23 * V_23 )
{
V_23 -> V_160 = 0 ;
F_169 ( & V_23 -> V_174 ) ;
}
void F_137 ( struct V_146 * V_147 )
{
while ( F_11 ( F_122 ( & V_147 -> V_186 ) ) ) {
F_138 ( & V_147 -> V_156 ) ;
F_172 ( & V_147 -> V_186 ) ;
F_136 ( & V_147 -> V_156 ) ;
if ( V_147 -> V_157 )
return;
}
V_147 -> V_157 = 1 ;
F_159 ( & V_147 -> V_186 , V_147 -> V_72 ) ;
}
static void F_173 ( struct V_146 * V_147 )
{
F_172 ( & V_147 -> V_186 ) ;
F_172 ( & V_147 -> V_190 ) ;
}
void F_174 ( struct V_22 * V_22 )
{
struct V_23 * V_23 ;
F_175 (rq, cfs_rq) {
struct V_146 * V_147 = F_134 ( V_23 -> V_31 ) ;
if ( ! V_23 -> V_160 )
continue;
V_23 -> V_155 = V_147 -> V_148 ;
if ( F_141 ( V_23 ) )
F_149 ( V_23 ) ;
}
}
static void F_68 ( struct V_23 * V_23 ,
unsigned long V_10 ) {}
static void F_119 ( struct V_23 * V_23 ) {}
static void F_106 ( struct V_23 * V_23 ) {}
static void F_112 ( struct V_23 * V_23 ) {}
static inline int F_141 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_86 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline int F_142 ( struct V_97 * V_31 ,
int V_163 , int V_164 )
{
return 0 ;
}
void F_167 ( struct V_146 * V_147 ) {}
static void F_171 ( struct V_23 * V_23 ) {}
static inline struct V_146 * F_134 ( struct V_97 * V_31 )
{
return NULL ;
}
static inline void F_173 ( struct V_146 * V_147 ) {}
void F_174 ( struct V_22 * V_22 ) {}
static void F_176 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_177 ( F_34 ( V_27 ) != V_22 ) ;
if ( V_23 -> V_71 > 1 ) {
T_2 V_74 = F_57 ( V_23 , V_26 ) ;
T_2 V_200 = V_26 -> V_79 - V_26 -> V_134 ;
T_3 V_41 = V_74 - V_200 ;
if ( V_41 < 0 ) {
if ( V_22 -> V_44 == V_27 )
F_114 ( V_27 ) ;
return;
}
if ( V_22 -> V_44 != V_27 )
V_41 = F_178 ( T_3 , 10000LL , V_41 ) ;
F_179 ( V_22 , V_41 ) ;
}
}
static void F_180 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
if ( ! F_181 ( V_22 ) || V_44 -> V_201 != & V_202 )
return;
if ( F_21 ( & V_44 -> V_26 ) -> V_71 < V_66 )
F_176 ( V_22 , V_44 ) ;
}
static inline void
F_176 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
}
static inline void F_180 ( struct V_22 * V_22 )
{
}
static void
F_182 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_125 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
F_32 (se) {
if ( V_26 -> V_75 )
break;
V_23 = F_21 ( V_26 ) ;
F_105 ( V_23 , V_26 , V_125 ) ;
if ( F_141 ( V_23 ) )
break;
V_23 -> V_171 ++ ;
V_125 = V_126 ;
}
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_171 ++ ;
if ( F_141 ( V_23 ) )
break;
F_85 ( V_23 , 0 ) ;
F_91 ( V_23 ) ;
}
if ( ! V_26 )
F_183 ( V_22 ) ;
F_180 ( V_22 ) ;
}
static void F_184 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_125 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 ;
int V_203 = V_125 & V_129 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_111 ( V_23 , V_26 , V_125 ) ;
if ( F_141 ( V_23 ) )
break;
V_23 -> V_171 -- ;
if ( V_23 -> V_69 . V_11 ) {
if ( V_203 && F_30 ( V_26 ) )
F_185 ( F_30 ( V_26 ) ) ;
V_26 = F_30 ( V_26 ) ;
break;
}
V_125 |= V_129 ;
}
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
V_23 -> V_171 -- ;
if ( F_141 ( V_23 ) )
break;
F_85 ( V_23 , 0 ) ;
F_91 ( V_23 ) ;
}
if ( ! V_26 )
F_186 ( V_22 ) ;
F_180 ( V_22 ) ;
}
static unsigned long F_187 ( const int V_204 )
{
return F_188 ( V_204 ) -> V_69 . V_11 ;
}
static unsigned long F_189 ( int V_204 , int type )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
unsigned long V_205 = F_187 ( V_204 ) ;
if ( type == 0 || ! F_104 ( V_206 ) )
return V_205 ;
return F_13 ( V_22 -> V_207 [ type - 1 ] , V_205 ) ;
}
static unsigned long F_190 ( int V_204 , int type )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
unsigned long V_205 = F_187 ( V_204 ) ;
if ( type == 0 || ! F_104 ( V_206 ) )
return V_205 ;
return F_62 ( V_22 -> V_207 [ type - 1 ] , V_205 ) ;
}
static unsigned long F_191 ( int V_204 )
{
return F_188 ( V_204 ) -> V_208 ;
}
static unsigned long F_192 ( int V_204 )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
unsigned long V_71 = F_193 ( V_22 -> V_71 ) ;
if ( V_71 )
return V_22 -> V_69 . V_11 / V_71 ;
return 0 ;
}
static void F_194 ( struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
T_2 V_39 ;
#ifndef F_39
T_2 V_47 ;
do {
V_47 = V_23 -> V_47 ;
F_195 () ;
V_39 = V_23 -> V_39 ;
} while ( V_39 != V_47 );
#else
V_39 = V_23 -> V_39 ;
#endif
V_26 -> V_40 -= V_39 ;
}
static long F_196 ( struct V_97 * V_31 , int V_204 , long V_209 , long V_210 )
{
struct V_25 * V_26 = V_31 -> V_26 [ V_204 ] ;
if ( ! V_31 -> V_32 )
return V_209 ;
F_32 (se) {
long V_17 , V_211 ;
V_31 = V_26 -> V_29 -> V_31 ;
V_211 = V_210 + F_87 ( V_31 , V_26 -> V_29 ) ;
V_17 = V_26 -> V_29 -> V_69 . V_11 + V_209 ;
if ( V_211 > 0 && V_17 < V_211 )
V_209 = ( V_17 * V_31 -> V_106 ) / V_211 ;
else
V_209 = V_31 -> V_106 ;
if ( V_209 < V_107 )
V_209 = V_107 ;
V_209 -= V_26 -> V_69 . V_11 ;
V_210 = 0 ;
}
return V_209 ;
}
static inline unsigned long F_196 ( struct V_97 * V_31 , int V_204 ,
unsigned long V_209 , unsigned long V_210 )
{
return V_209 ;
}
static int F_197 ( struct V_212 * V_213 , struct V_24 * V_27 , int V_214 )
{
T_3 V_215 , V_69 ;
int V_216 , V_217 , V_218 ;
unsigned long V_219 ;
struct V_97 * V_31 ;
unsigned long V_11 ;
int V_220 ;
V_216 = V_213 -> V_221 ;
V_217 = F_132 () ;
V_218 = F_198 ( V_27 ) ;
V_69 = F_189 ( V_218 , V_216 ) ;
V_215 = F_190 ( V_217 , V_216 ) ;
if ( V_214 ) {
V_31 = V_97 ( V_222 ) ;
V_11 = V_222 -> V_26 . V_69 . V_11 ;
V_215 += F_196 ( V_31 , V_217 , - V_11 , - V_11 ) ;
V_69 += F_196 ( V_31 , V_218 , 0 , - V_11 ) ;
}
V_31 = V_97 ( V_27 ) ;
V_11 = V_27 -> V_26 . V_69 . V_11 ;
if ( V_215 > 0 ) {
T_3 V_223 , V_224 ;
V_223 = 100 ;
V_223 *= F_191 ( V_218 ) ;
V_223 *= V_215 +
F_196 ( V_31 , V_217 , V_11 , V_11 ) ;
V_224 = 100 + ( V_213 -> V_225 - 100 ) / 2 ;
V_224 *= F_191 ( V_217 ) ;
V_224 *= V_69 + F_196 ( V_31 , V_218 , 0 , V_11 ) ;
V_220 = V_223 <= V_224 ;
} else
V_220 = true ;
if ( V_214 && V_220 )
return 1 ;
F_102 ( V_27 , V_26 . V_77 . V_226 ) ;
V_219 = F_192 ( V_217 ) ;
if ( V_220 ||
( V_215 <= V_69 &&
V_215 + F_190 ( V_218 , V_216 ) <= V_219 ) ) {
F_102 ( V_213 , V_227 ) ;
F_102 ( V_27 , V_26 . V_77 . V_228 ) ;
return 1 ;
}
return 0 ;
}
static struct V_229 *
F_199 ( struct V_212 * V_213 , struct V_24 * V_27 ,
int V_217 , int V_230 )
{
struct V_229 * V_231 = NULL , * V_232 = V_213 -> V_233 ;
unsigned long V_234 = V_235 , V_215 = 0 ;
int V_236 = 100 + ( V_213 -> V_225 - 100 ) / 2 ;
do {
unsigned long V_69 , V_237 ;
int V_238 ;
int V_239 ;
if ( ! F_200 ( F_201 ( V_232 ) ,
F_202 ( V_27 ) ) )
continue;
V_238 = F_203 ( V_217 ,
F_201 ( V_232 ) ) ;
V_237 = 0 ;
F_204 (i, sched_group_cpus(group)) {
if ( V_238 )
V_69 = F_189 ( V_239 , V_230 ) ;
else
V_69 = F_190 ( V_239 , V_230 ) ;
V_237 += V_69 ;
}
V_237 = ( V_237 * V_240 ) / V_232 -> V_241 -> V_242 ;
if ( V_238 ) {
V_215 = V_237 ;
} else if ( V_237 < V_234 ) {
V_234 = V_237 ;
V_231 = V_232 ;
}
} while ( V_232 = V_232 -> V_57 , V_232 != V_213 -> V_233 );
if ( ! V_231 || 100 * V_215 < V_236 * V_234 )
return NULL ;
return V_231 ;
}
static int
F_205 ( struct V_229 * V_232 , struct V_24 * V_27 , int V_217 )
{
unsigned long V_69 , V_234 = V_235 ;
int V_231 = - 1 ;
int V_239 ;
F_206 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_69 = F_187 ( V_239 ) ;
if ( V_69 < V_234 || ( V_69 == V_234 && V_239 == V_217 ) ) {
V_234 = V_69 ;
V_231 = V_239 ;
}
}
return V_231 ;
}
static int F_207 ( struct V_24 * V_27 , int V_243 )
{
int V_204 = F_132 () ;
int V_218 = F_198 ( V_27 ) ;
struct V_212 * V_213 ;
struct V_229 * V_244 ;
int V_239 ;
if ( V_243 == V_204 && F_208 ( V_204 ) )
return V_204 ;
if ( V_243 == V_218 && F_208 ( V_218 ) )
return V_218 ;
F_146 () ;
V_213 = F_209 ( F_210 ( V_245 , V_243 ) ) ;
F_211 (sd) {
V_244 = V_213 -> V_233 ;
do {
if ( ! F_200 ( F_201 ( V_244 ) ,
F_202 ( V_27 ) ) )
goto V_57;
F_204 (i, sched_group_cpus(sg)) {
if ( ! F_208 ( V_239 ) )
goto V_57;
}
V_243 = F_212 ( F_201 ( V_244 ) ,
F_202 ( V_27 ) ) ;
goto V_246;
V_57:
V_244 = V_244 -> V_57 ;
} while ( V_244 != V_213 -> V_233 );
}
V_246:
F_148 () ;
return V_243 ;
}
static int
F_213 ( struct V_24 * V_27 , int V_247 , int V_248 )
{
struct V_212 * V_14 , * V_249 = NULL , * V_213 = NULL ;
int V_204 = F_132 () ;
int V_218 = F_198 ( V_27 ) ;
int V_250 = V_204 ;
int V_251 = 0 ;
int V_252 = 1 ;
int V_214 = V_248 & V_253 ;
if ( V_27 -> V_254 . V_255 == 1 )
return V_218 ;
if ( V_247 & V_256 ) {
if ( F_203 ( V_204 , F_202 ( V_27 ) ) )
V_251 = 1 ;
V_250 = V_218 ;
}
F_146 () ;
F_214 (cpu, tmp) {
if ( ! ( V_14 -> V_125 & V_257 ) )
continue;
if ( V_14 -> V_125 & ( V_258 | V_259 ) ) {
unsigned long V_242 = 0 ;
unsigned long V_71 = 0 ;
unsigned long V_260 ;
int V_239 ;
F_204 (i, sched_domain_span(tmp)) {
V_242 += F_191 ( V_239 ) ;
V_71 += F_188 ( V_239 ) -> V_38 . V_71 ;
}
V_260 = F_215 ( V_242 , V_240 ) ;
if ( V_14 -> V_125 & V_258 )
V_71 /= 2 ;
if ( V_71 < V_260 )
V_252 = 0 ;
}
if ( V_251 && ( V_14 -> V_125 & V_261 ) &&
F_203 ( V_218 , F_216 ( V_14 ) ) ) {
V_249 = V_14 ;
V_251 = 0 ;
}
if ( ! V_252 && ! V_251 )
break;
if ( ! ( V_14 -> V_125 & V_247 ) )
continue;
if ( V_252 )
V_213 = V_14 ;
}
if ( V_249 ) {
if ( V_204 == V_218 || F_197 ( V_249 , V_27 , V_214 ) )
V_218 = V_204 ;
V_250 = F_207 ( V_27 , V_218 ) ;
goto V_262;
}
while ( V_213 ) {
int V_230 = V_213 -> V_263 ;
struct V_229 * V_232 ;
int V_11 ;
if ( ! ( V_213 -> V_125 & V_247 ) ) {
V_213 = V_213 -> V_264 ;
continue;
}
if ( V_247 & V_256 )
V_230 = V_213 -> V_221 ;
V_232 = F_199 ( V_213 , V_27 , V_204 , V_230 ) ;
if ( ! V_232 ) {
V_213 = V_213 -> V_264 ;
continue;
}
V_250 = F_205 ( V_232 , V_27 , V_204 ) ;
if ( V_250 == - 1 || V_250 == V_204 ) {
V_213 = V_213 -> V_264 ;
continue;
}
V_204 = V_250 ;
V_11 = V_213 -> V_265 ;
V_213 = NULL ;
F_214 (cpu, tmp) {
if ( V_11 <= V_14 -> V_265 )
break;
if ( V_14 -> V_125 & V_247 )
V_213 = V_14 ;
}
}
V_262:
F_148 () ;
return V_250 ;
}
static unsigned long
F_217 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
unsigned long V_266 = V_267 ;
return F_55 ( V_266 , V_26 ) ;
}
static int
F_117 ( struct V_25 * V_44 , struct V_25 * V_26 )
{
T_3 V_266 , V_268 = V_44 -> V_40 - V_26 -> V_40 ;
if ( V_268 <= 0 )
return - 1 ;
V_266 = F_217 ( V_44 , V_26 ) ;
if ( V_268 > V_266 )
return 1 ;
return 0 ;
}
static void F_218 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_269 == V_270 ) )
return;
F_32 (se)
F_21 ( V_26 ) -> V_58 = V_26 ;
}
static void F_185 ( struct V_25 * V_26 )
{
if ( F_18 ( V_26 ) && F_11 ( F_15 ( V_26 ) -> V_269 == V_270 ) )
return;
F_32 (se)
F_21 ( V_26 ) -> V_57 = V_26 ;
}
static void F_219 ( struct V_25 * V_26 )
{
F_32 (se)
F_21 ( V_26 ) -> V_128 = V_26 ;
}
static void F_220 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_248 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_25 * V_26 = & V_44 -> V_26 , * V_34 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
int V_271 = V_23 -> V_71 >= V_66 ;
int V_272 = 0 ;
if ( F_11 ( V_26 == V_34 ) )
return;
if ( F_11 ( F_86 ( F_21 ( V_34 ) ) ) )
return;
if ( F_104 ( V_273 ) && V_271 && ! ( V_248 & V_274 ) ) {
F_185 ( V_34 ) ;
V_272 = 1 ;
}
if ( F_221 ( V_44 ) )
return;
if ( F_11 ( V_44 -> V_269 == V_270 ) &&
F_9 ( V_27 -> V_269 != V_270 ) )
goto V_275;
if ( F_11 ( V_27 -> V_269 != V_276 ) )
return;
F_33 ( & V_26 , & V_34 ) ;
F_64 ( F_21 ( V_26 ) ) ;
F_222 ( ! V_34 ) ;
if ( F_117 ( V_26 , V_34 ) == 1 ) {
if ( ! V_272 )
F_185 ( V_34 ) ;
goto V_275;
}
return;
V_275:
F_114 ( V_44 ) ;
if ( F_11 ( ! V_26 -> V_75 || V_44 == V_22 -> V_158 ) )
return;
if ( F_104 ( V_277 ) && V_271 && F_18 ( V_26 ) )
F_218 ( V_26 ) ;
}
static struct V_24 * F_223 ( struct V_22 * V_22 )
{
struct V_24 * V_27 ;
struct V_23 * V_23 = & V_22 -> V_38 ;
struct V_25 * V_26 ;
if ( ! V_23 -> V_71 )
return NULL ;
do {
V_26 = F_116 ( V_23 ) ;
F_115 ( V_23 , V_26 ) ;
V_23 = F_22 ( V_26 ) ;
} while ( V_23 );
V_27 = F_15 ( V_26 ) ;
if ( F_181 ( V_22 ) )
F_176 ( V_22 , V_27 ) ;
return V_27 ;
}
static void F_224 ( struct V_22 * V_22 , struct V_24 * V_137 )
{
struct V_25 * V_26 = & V_137 -> V_26 ;
struct V_23 * V_23 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_118 ( V_23 , V_26 ) ;
}
}
static void F_225 ( struct V_22 * V_22 )
{
struct V_24 * V_44 = V_22 -> V_44 ;
struct V_23 * V_23 = F_20 ( V_44 ) ;
struct V_25 * V_26 = & V_44 -> V_26 ;
if ( F_11 ( V_22 -> V_71 == 1 ) )
return;
F_110 ( V_23 , V_26 ) ;
if ( V_44 -> V_269 != V_278 ) {
F_150 ( V_22 ) ;
F_64 ( V_23 ) ;
V_22 -> V_279 = 1 ;
}
F_219 ( V_26 ) ;
}
static bool F_226 ( struct V_22 * V_22 , struct V_24 * V_27 , bool V_275 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
if ( ! V_26 -> V_75 || F_86 ( F_21 ( V_26 ) ) )
return false ;
F_185 ( V_26 ) ;
F_225 ( V_22 ) ;
return true ;
}
static void F_227 ( struct V_22 * V_280 , struct V_24 * V_27 ,
struct V_22 * V_281 , int V_217 )
{
F_228 ( V_280 , V_27 , 0 ) ;
F_229 ( V_27 , V_217 ) ;
F_230 ( V_281 , V_27 , 0 ) ;
F_231 ( V_281 , V_27 , 0 ) ;
}
static int
F_232 ( struct V_24 * V_27 , T_2 V_85 , struct V_212 * V_213 )
{
T_3 V_41 ;
if ( V_27 -> V_201 != & V_202 )
return 0 ;
if ( F_11 ( V_27 -> V_269 == V_270 ) )
return 0 ;
if ( F_104 ( V_282 ) && V_281 () -> V_71 &&
( & V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_57 ||
& V_27 -> V_26 == F_21 ( & V_27 -> V_26 ) -> V_58 ) )
return 1 ;
if ( V_283 == - 1 )
return 1 ;
if ( V_283 == 0 )
return 0 ;
V_41 = V_85 - V_27 -> V_26 . V_87 ;
return V_41 < ( T_3 ) V_283 ;
}
static
int F_233 ( struct V_24 * V_27 , struct V_22 * V_22 , int V_217 ,
struct V_212 * V_213 , enum V_284 V_158 ,
int * V_285 )
{
int V_286 = 0 ;
if ( ! F_203 ( V_217 , F_202 ( V_27 ) ) ) {
F_102 ( V_27 , V_26 . V_77 . V_287 ) ;
return 0 ;
}
* V_285 &= ~ V_288 ;
if ( F_234 ( V_22 , V_27 ) ) {
F_102 ( V_27 , V_26 . V_77 . V_289 ) ;
return 0 ;
}
V_286 = F_232 ( V_27 , V_22 -> V_86 , V_213 ) ;
if ( ! V_286 ||
V_213 -> V_290 > V_213 -> V_291 ) {
#ifdef F_72
if ( V_286 ) {
F_102 ( V_213 , V_292 [ V_158 ] ) ;
F_102 ( V_27 , V_26 . V_77 . V_293 ) ;
}
#endif
return 1 ;
}
if ( V_286 ) {
F_102 ( V_27 , V_26 . V_77 . V_294 ) ;
return 0 ;
}
return 1 ;
}
static int
F_235 ( struct V_22 * V_281 , int V_217 , struct V_22 * V_295 ,
struct V_212 * V_213 , enum V_284 V_158 )
{
struct V_24 * V_27 , * V_296 ;
struct V_23 * V_23 ;
int V_297 = 0 ;
F_175 (busiest, cfs_rq) {
F_236 (p, n, &cfs_rq->tasks, se.group_node) {
if ( F_142 ( V_97 ( V_27 ) ,
V_295 -> V_204 , V_217 ) )
break;
if ( ! F_233 ( V_27 , V_295 , V_217 ,
V_213 , V_158 , & V_297 ) )
continue;
F_227 ( V_295 , V_27 , V_281 , V_217 ) ;
F_102 ( V_213 , V_298 [ V_158 ] ) ;
return 1 ;
}
}
return 0 ;
}
static unsigned long
F_237 ( struct V_22 * V_281 , int V_217 , struct V_22 * V_295 ,
unsigned long V_299 , struct V_212 * V_213 ,
enum V_284 V_158 , int * V_285 ,
struct V_23 * V_300 )
{
int V_301 = 0 , V_302 = 0 ;
long V_303 = V_299 ;
struct V_24 * V_27 , * V_296 ;
if ( V_299 == 0 )
goto V_304;
F_236 (p, n, &busiest_cfs_rq->tasks, se.group_node) {
if ( V_301 ++ > V_305 ) {
* V_285 |= V_306 ;
break;
}
if ( ( V_27 -> V_26 . V_69 . V_11 >> 1 ) > V_303 ||
! F_233 ( V_27 , V_295 , V_217 , V_213 , V_158 ,
V_285 ) )
continue;
F_227 ( V_295 , V_27 , V_281 , V_217 ) ;
V_302 ++ ;
V_303 -= V_27 -> V_26 . V_69 . V_11 ;
#ifdef F_238
if ( V_158 == V_307 ) {
* V_285 |= V_308 ;
break;
}
#endif
if ( V_303 <= 0 )
break;
}
V_304:
F_63 ( V_213 , V_298 [ V_158 ] , V_302 ) ;
return V_299 - V_303 ;
}
static int F_239 ( struct V_97 * V_31 , int V_204 )
{
struct V_23 * V_23 ;
unsigned long V_125 ;
struct V_22 * V_22 ;
if ( ! V_31 -> V_26 [ V_204 ] )
return 0 ;
V_22 = F_188 ( V_204 ) ;
V_23 = V_31 -> V_23 [ V_204 ] ;
F_240 ( & V_22 -> V_156 , V_125 ) ;
F_150 ( V_22 ) ;
F_85 ( V_23 , 1 ) ;
F_91 ( V_23 ) ;
F_241 ( & V_22 -> V_156 , V_125 ) ;
return 0 ;
}
static void F_242 ( int V_204 )
{
struct V_23 * V_23 ;
struct V_22 * V_22 = F_188 ( V_204 ) ;
F_146 () ;
F_175 (rq, cfs_rq) {
if ( F_86 ( V_23 ) )
continue;
F_239 ( V_23 -> V_31 , V_204 ) ;
}
F_148 () ;
}
static int F_243 ( struct V_97 * V_31 , void * V_167 )
{
unsigned long V_69 ;
long V_204 = ( long ) V_167 ;
if ( ! V_31 -> V_32 ) {
V_69 = F_188 ( V_204 ) -> V_69 . V_11 ;
} else {
V_69 = V_31 -> V_32 -> V_23 [ V_204 ] -> V_309 ;
V_69 *= V_31 -> V_26 [ V_204 ] -> V_69 . V_11 ;
V_69 /= V_31 -> V_32 -> V_23 [ V_204 ] -> V_69 . V_11 + 1 ;
}
V_31 -> V_23 [ V_204 ] -> V_309 = V_69 ;
return 0 ;
}
static void F_244 ( long V_204 )
{
F_245 ( F_243 , V_170 , ( void * ) V_204 ) ;
}
static unsigned long
F_246 ( struct V_22 * V_281 , int V_217 , struct V_22 * V_295 ,
unsigned long V_299 ,
struct V_212 * V_213 , enum V_284 V_158 ,
int * V_285 )
{
long V_303 = V_299 ;
struct V_23 * V_300 ;
F_146 () ;
F_244 ( F_24 ( V_295 ) ) ;
F_175 (busiest, busiest_cfs_rq) {
unsigned long V_310 = V_300 -> V_309 ;
unsigned long V_311 = V_300 -> V_69 . V_11 ;
T_2 V_312 , V_313 ;
if ( * V_285 & ( V_306 | V_308 ) )
break;
if ( ! V_300 -> V_93 ||
F_142 ( V_300 -> V_31 , F_24 ( V_295 ) , V_217 ) )
continue;
V_312 = ( T_2 ) V_303 * V_311 ;
V_312 = F_247 ( V_312 , V_310 + 1 ) ;
V_313 = F_237 ( V_281 , V_217 , V_295 ,
V_312 , V_213 , V_158 , V_285 ,
V_300 ) ;
if ( ! V_313 )
continue;
V_313 *= V_310 ;
V_313 = F_247 ( V_313 , V_311 + 1 ) ;
V_303 -= V_313 ;
if ( V_303 < 0 )
break;
}
F_148 () ;
return V_299 - V_303 ;
}
static inline void F_242 ( int V_204 )
{
}
static unsigned long
F_246 ( struct V_22 * V_281 , int V_217 , struct V_22 * V_295 ,
unsigned long V_299 ,
struct V_212 * V_213 , enum V_284 V_158 ,
int * V_285 )
{
return F_237 ( V_281 , V_217 , V_295 ,
V_299 , V_213 , V_158 , V_285 ,
& V_295 -> V_38 ) ;
}
static int F_248 ( struct V_22 * V_281 , int V_217 , struct V_22 * V_295 ,
unsigned long V_299 ,
struct V_212 * V_213 , enum V_284 V_158 ,
int * V_285 )
{
unsigned long V_314 = 0 , V_315 ;
do {
V_315 = F_246 ( V_281 , V_217 , V_295 ,
V_299 - V_314 ,
V_213 , V_158 , V_285 ) ;
V_314 += V_315 ;
if ( * V_285 & ( V_306 | V_308 ) )
break;
#ifdef F_238
if ( V_158 == V_307 && V_281 -> V_71 ) {
* V_285 |= V_308 ;
break;
}
#endif
} while ( V_315 && V_299 > V_314 );
return V_314 > 0 ;
}
static inline int F_249 ( struct V_212 * V_213 ,
enum V_284 V_158 )
{
int V_230 ;
switch ( V_158 ) {
case V_316 :
V_230 = V_213 -> V_317 ;
break;
case V_307 :
V_230 = V_213 -> V_318 ;
break;
default:
V_230 = V_213 -> V_319 ;
break;
}
return V_230 ;
}
static inline void F_250 ( struct V_212 * V_213 ,
struct V_320 * V_321 , enum V_284 V_158 )
{
if ( V_158 == V_316 || ! ( V_213 -> V_125 & V_258 ) )
V_321 -> V_322 = 0 ;
else {
V_321 -> V_322 = 1 ;
V_321 -> V_323 = V_235 ;
V_321 -> V_324 = 0 ;
}
}
static inline void F_251 ( struct V_229 * V_232 ,
struct V_320 * V_321 , int V_238 , struct V_325 * V_326 )
{
if ( ! V_321 -> V_322 )
return;
if ( V_238 && ( V_321 -> V_327 >= V_326 -> V_328 ||
! V_321 -> V_327 ) )
V_321 -> V_322 = 0 ;
if ( ! V_321 -> V_322 ||
V_326 -> V_329 >= V_326 -> V_328 ||
! V_326 -> V_329 )
return;
if ( ( V_326 -> V_329 < V_321 -> V_323 ) ||
( V_326 -> V_329 == V_321 -> V_323 &&
F_252 ( V_232 ) > F_252 ( V_321 -> V_330 ) ) ) {
V_321 -> V_330 = V_232 ;
V_321 -> V_323 = V_326 -> V_329 ;
V_321 -> V_331 = V_326 -> V_332 /
V_326 -> V_329 ;
}
if ( V_326 -> V_329 + 1 > V_326 -> V_328 )
return;
if ( V_326 -> V_329 > V_321 -> V_324 ||
( V_326 -> V_329 == V_321 -> V_324 &&
F_252 ( V_232 ) < F_252 ( V_321 -> V_333 ) ) ) {
V_321 -> V_333 = V_232 ;
V_321 -> V_324 = V_326 -> V_329 ;
}
}
static inline int F_253 ( struct V_320 * V_321 ,
int V_217 , unsigned long * V_236 )
{
if ( ! V_321 -> V_322 )
return 0 ;
if ( V_321 -> V_334 != V_321 -> V_333 ||
V_321 -> V_333 == V_321 -> V_330 )
return 0 ;
* V_236 = V_321 -> V_331 ;
V_321 -> V_295 = V_321 -> V_330 ;
return 1 ;
}
static inline void F_250 ( struct V_212 * V_213 ,
struct V_320 * V_321 , enum V_284 V_158 )
{
return;
}
static inline void F_251 ( struct V_229 * V_232 ,
struct V_320 * V_321 , int V_238 , struct V_325 * V_326 )
{
return;
}
static inline int F_253 ( struct V_320 * V_321 ,
int V_217 , unsigned long * V_236 )
{
return 0 ;
}
unsigned long F_254 ( struct V_212 * V_213 , int V_204 )
{
return V_240 ;
}
unsigned long __weak F_255 ( struct V_212 * V_213 , int V_204 )
{
return F_254 ( V_213 , V_204 ) ;
}
unsigned long F_256 ( struct V_212 * V_213 , int V_204 )
{
unsigned long V_11 = V_213 -> V_265 ;
unsigned long V_335 = V_213 -> V_335 ;
V_335 /= V_11 ;
return V_335 ;
}
unsigned long __weak F_257 ( struct V_212 * V_213 , int V_204 )
{
return F_256 ( V_213 , V_204 ) ;
}
unsigned long F_258 ( int V_204 )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
T_2 V_205 , V_336 ;
V_205 = F_259 () + ( V_22 -> clock - V_22 -> V_337 ) ;
if ( F_11 ( V_205 < V_22 -> V_338 ) ) {
V_336 = 0 ;
} else {
V_336 = V_205 - V_22 -> V_338 ;
}
if ( F_11 ( ( T_3 ) V_205 < V_240 ) )
V_205 = V_240 ;
V_205 >>= V_339 ;
return F_247 ( V_336 , V_205 ) ;
}
static void F_260 ( struct V_212 * V_213 , int V_204 )
{
unsigned long V_11 = V_213 -> V_265 ;
unsigned long V_242 = V_240 ;
struct V_229 * V_340 = V_213 -> V_233 ;
if ( ( V_213 -> V_125 & V_341 ) && V_11 > 1 ) {
if ( F_104 ( V_342 ) )
V_242 *= F_257 ( V_213 , V_204 ) ;
else
V_242 *= F_256 ( V_213 , V_204 ) ;
V_242 >>= V_339 ;
}
V_340 -> V_241 -> V_343 = V_242 ;
if ( F_104 ( V_342 ) )
V_242 *= F_255 ( V_213 , V_204 ) ;
else
V_242 *= F_254 ( V_213 , V_204 ) ;
V_242 >>= V_339 ;
V_242 *= F_258 ( V_204 ) ;
V_242 >>= V_339 ;
if ( ! V_242 )
V_242 = 1 ;
F_188 ( V_204 ) -> V_208 = V_242 ;
V_340 -> V_241 -> V_242 = V_242 ;
}
void F_261 ( struct V_212 * V_213 , int V_204 )
{
struct V_212 * V_264 = V_213 -> V_264 ;
struct V_229 * V_232 , * V_340 = V_213 -> V_233 ;
unsigned long V_242 ;
if ( ! V_264 ) {
F_260 ( V_213 , V_204 ) ;
return;
}
V_242 = 0 ;
V_232 = V_264 -> V_233 ;
do {
V_242 += V_232 -> V_241 -> V_242 ;
V_232 = V_232 -> V_57 ;
} while ( V_232 != V_264 -> V_233 );
V_340 -> V_241 -> V_242 = V_242 ;
}
static inline int
F_262 ( struct V_212 * V_213 , struct V_229 * V_232 )
{
if ( ! ( V_213 -> V_125 & V_341 ) )
return 0 ;
if ( V_232 -> V_241 -> V_242 * 32 > V_232 -> V_241 -> V_343 * 29 )
return 1 ;
return 0 ;
}
static inline void F_263 ( struct V_212 * V_213 ,
struct V_229 * V_232 , int V_217 ,
enum V_284 V_158 , int V_230 ,
int V_238 , const struct V_344 * V_1 ,
int * V_345 , struct V_325 * V_326 )
{
unsigned long V_69 , V_346 , V_347 , V_348 ;
int V_239 ;
unsigned int V_349 = - 1 , V_350 = 0 ;
unsigned long V_351 = 0 ;
if ( V_238 )
V_349 = F_252 ( V_232 ) ;
V_346 = 0 ;
V_347 = ~ 0UL ;
V_348 = 0 ;
F_206 (i, sched_group_cpus(group), cpus) {
struct V_22 * V_22 = F_188 ( V_239 ) ;
if ( V_238 ) {
if ( F_208 ( V_239 ) && ! V_350 ) {
V_350 = 1 ;
V_349 = V_239 ;
}
V_69 = F_190 ( V_239 , V_230 ) ;
} else {
V_69 = F_189 ( V_239 , V_230 ) ;
if ( V_69 > V_346 ) {
V_346 = V_69 ;
V_348 = V_22 -> V_71 ;
}
if ( V_347 > V_69 )
V_347 = V_69 ;
}
V_326 -> V_352 += V_69 ;
V_326 -> V_329 += V_22 -> V_71 ;
V_326 -> V_332 += F_187 ( V_239 ) ;
if ( F_208 ( V_239 ) )
V_326 -> V_353 ++ ;
}
if ( V_158 != V_307 && V_238 ) {
if ( V_349 != V_217 ) {
* V_345 = 0 ;
return;
}
F_261 ( V_213 , V_217 ) ;
}
V_326 -> V_237 = ( V_326 -> V_352 * V_240 ) / V_232 -> V_241 -> V_242 ;
if ( V_326 -> V_329 )
V_351 = V_326 -> V_332 / V_326 -> V_329 ;
if ( ( V_346 - V_347 ) >= V_351 && V_348 > 1 )
V_326 -> V_354 = 1 ;
V_326 -> V_328 = F_215 ( V_232 -> V_241 -> V_242 ,
V_240 ) ;
if ( ! V_326 -> V_328 )
V_326 -> V_328 = F_262 ( V_213 , V_232 ) ;
V_326 -> V_355 = V_232 -> V_355 ;
if ( V_326 -> V_328 > V_326 -> V_329 )
V_326 -> V_356 = 1 ;
}
static bool F_264 ( struct V_212 * V_213 ,
struct V_320 * V_321 ,
struct V_229 * V_244 ,
struct V_325 * V_326 ,
int V_217 )
{
if ( V_326 -> V_237 <= V_321 -> V_357 )
return false ;
if ( V_326 -> V_329 > V_326 -> V_328 )
return true ;
if ( V_326 -> V_354 )
return true ;
if ( ( V_213 -> V_125 & V_358 ) && V_326 -> V_329 &&
V_217 < F_252 ( V_244 ) ) {
if ( ! V_321 -> V_295 )
return true ;
if ( F_252 ( V_321 -> V_295 ) > F_252 ( V_244 ) )
return true ;
}
return false ;
}
static inline void F_265 ( struct V_212 * V_213 , int V_217 ,
enum V_284 V_158 , const struct V_344 * V_1 ,
int * V_345 , struct V_320 * V_321 )
{
struct V_212 * V_264 = V_213 -> V_264 ;
struct V_229 * V_244 = V_213 -> V_233 ;
struct V_325 V_326 ;
int V_230 , V_359 = 0 ;
if ( V_264 && V_264 -> V_125 & V_360 )
V_359 = 1 ;
F_250 ( V_213 , V_321 , V_158 ) ;
V_230 = F_249 ( V_213 , V_158 ) ;
do {
int V_238 ;
V_238 = F_203 ( V_217 , F_201 ( V_244 ) ) ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
F_263 ( V_213 , V_244 , V_217 , V_158 , V_230 ,
V_238 , V_1 , V_345 , & V_326 ) ;
if ( V_238 && ! ( * V_345 ) )
return;
V_321 -> V_361 += V_326 . V_352 ;
V_321 -> V_362 += V_244 -> V_241 -> V_242 ;
if ( V_359 && ! V_238 && V_321 -> V_363 )
V_326 . V_328 = F_13 ( V_326 . V_328 , 1UL ) ;
if ( V_238 ) {
V_321 -> V_215 = V_326 . V_237 ;
V_321 -> V_334 = V_244 ;
V_321 -> V_327 = V_326 . V_329 ;
V_321 -> V_364 = V_326 . V_332 ;
V_321 -> V_363 = V_326 . V_356 ;
V_321 -> V_365 = V_326 . V_353 ;
} else if ( F_264 ( V_213 , V_321 , V_244 , & V_326 , V_217 ) ) {
V_321 -> V_357 = V_326 . V_237 ;
V_321 -> V_295 = V_244 ;
V_321 -> V_366 = V_326 . V_329 ;
V_321 -> V_367 = V_326 . V_353 ;
V_321 -> V_368 = V_326 . V_328 ;
V_321 -> V_369 = V_326 . V_332 ;
V_321 -> V_370 = V_326 . V_356 ;
V_321 -> V_371 = V_326 . V_355 ;
V_321 -> V_354 = V_326 . V_354 ;
}
F_251 ( V_244 , V_321 , V_238 , & V_326 ) ;
V_244 = V_244 -> V_57 ;
} while ( V_244 != V_213 -> V_233 );
}
static int F_266 ( struct V_212 * V_213 ,
struct V_320 * V_321 ,
int V_217 , unsigned long * V_236 )
{
int V_372 ;
if ( ! ( V_213 -> V_125 & V_358 ) )
return 0 ;
if ( ! V_321 -> V_295 )
return 0 ;
V_372 = F_252 ( V_321 -> V_295 ) ;
if ( V_217 > V_372 )
return 0 ;
* V_236 = F_215 ( V_321 -> V_357 * V_321 -> V_295 -> V_241 -> V_242 ,
V_240 ) ;
return 1 ;
}
static inline void F_267 ( struct V_320 * V_321 ,
int V_217 , unsigned long * V_236 )
{
unsigned long V_14 , V_373 = 0 , V_374 = 0 ;
unsigned int V_375 = 2 ;
unsigned long V_376 ;
if ( V_321 -> V_327 ) {
V_321 -> V_364 /= V_321 -> V_327 ;
if ( V_321 -> V_369 >
V_321 -> V_364 )
V_375 = 1 ;
} else
V_321 -> V_364 =
F_192 ( V_217 ) ;
V_376 = V_321 -> V_369
* V_240 ;
V_376 /= V_321 -> V_295 -> V_241 -> V_242 ;
if ( V_321 -> V_357 - V_321 -> V_215 + V_376 >=
( V_376 * V_375 ) ) {
* V_236 = V_321 -> V_369 ;
return;
}
V_373 += V_321 -> V_295 -> V_241 -> V_242 *
F_13 ( V_321 -> V_369 , V_321 -> V_357 ) ;
V_373 += V_321 -> V_334 -> V_241 -> V_242 *
F_13 ( V_321 -> V_364 , V_321 -> V_215 ) ;
V_373 /= V_240 ;
V_14 = ( V_321 -> V_369 * V_240 ) /
V_321 -> V_295 -> V_241 -> V_242 ;
if ( V_321 -> V_357 > V_14 )
V_374 += V_321 -> V_295 -> V_241 -> V_242 *
F_13 ( V_321 -> V_369 , V_321 -> V_357 - V_14 ) ;
if ( V_321 -> V_357 * V_321 -> V_295 -> V_241 -> V_242 <
V_321 -> V_369 * V_240 )
V_14 = ( V_321 -> V_357 * V_321 -> V_295 -> V_241 -> V_242 ) /
V_321 -> V_334 -> V_241 -> V_242 ;
else
V_14 = ( V_321 -> V_369 * V_240 ) /
V_321 -> V_334 -> V_241 -> V_242 ;
V_374 += V_321 -> V_334 -> V_241 -> V_242 *
F_13 ( V_321 -> V_364 , V_321 -> V_215 + V_14 ) ;
V_374 /= V_240 ;
if ( V_374 > V_373 )
* V_236 = V_321 -> V_369 ;
}
static inline void F_268 ( struct V_320 * V_321 , int V_217 ,
unsigned long * V_236 )
{
unsigned long V_377 , V_378 = ~ 0UL ;
V_321 -> V_369 /= V_321 -> V_366 ;
if ( V_321 -> V_354 ) {
V_321 -> V_369 =
F_13 ( V_321 -> V_369 , V_321 -> V_237 ) ;
}
if ( V_321 -> V_357 < V_321 -> V_237 ) {
* V_236 = 0 ;
return F_267 ( V_321 , V_217 , V_236 ) ;
}
if ( ! V_321 -> V_354 ) {
V_378 = ( V_321 -> V_366 -
V_321 -> V_368 ) ;
V_378 *= ( V_379 * V_240 ) ;
V_378 /= V_321 -> V_295 -> V_241 -> V_242 ;
}
V_377 = F_13 ( V_321 -> V_357 - V_321 -> V_237 , V_378 ) ;
* V_236 = F_13 ( V_377 * V_321 -> V_295 -> V_241 -> V_242 ,
( V_321 -> V_237 - V_321 -> V_215 ) * V_321 -> V_334 -> V_241 -> V_242 )
/ V_240 ;
if ( * V_236 < V_321 -> V_369 )
return F_267 ( V_321 , V_217 , V_236 ) ;
}
static struct V_229 *
F_269 ( struct V_212 * V_213 , int V_217 ,
unsigned long * V_236 , enum V_284 V_158 ,
const struct V_344 * V_1 , int * V_345 )
{
struct V_320 V_321 ;
memset ( & V_321 , 0 , sizeof( V_321 ) ) ;
F_265 ( V_213 , V_217 , V_158 , V_1 , V_345 , & V_321 ) ;
if ( ! ( * V_345 ) )
goto V_65;
if ( ( V_158 == V_380 || V_158 == V_307 ) &&
F_266 ( V_213 , & V_321 , V_217 , V_236 ) )
return V_321 . V_295 ;
if ( ! V_321 . V_295 || V_321 . V_366 == 0 )
goto V_381;
V_321 . V_237 = ( V_240 * V_321 . V_361 ) / V_321 . V_362 ;
if ( V_321 . V_354 )
goto V_382;
if ( V_158 == V_307 && V_321 . V_363 &&
! V_321 . V_370 )
goto V_382;
if ( V_321 . V_215 >= V_321 . V_357 )
goto V_381;
if ( V_321 . V_215 >= V_321 . V_237 )
goto V_381;
if ( V_158 == V_380 ) {
if ( ( V_321 . V_365 <= V_321 . V_367 + 1 ) &&
V_321 . V_366 <= V_321 . V_371 )
goto V_381;
} else {
if ( 100 * V_321 . V_357 <= V_213 -> V_225 * V_321 . V_215 )
goto V_381;
}
V_382:
F_268 ( & V_321 , V_217 , V_236 ) ;
return V_321 . V_295 ;
V_381:
if ( F_253 ( & V_321 , V_217 , V_236 ) )
return V_321 . V_295 ;
V_65:
* V_236 = 0 ;
return NULL ;
}
static struct V_22 *
F_270 ( struct V_212 * V_213 , struct V_229 * V_232 ,
enum V_284 V_158 , unsigned long V_236 ,
const struct V_344 * V_1 )
{
struct V_22 * V_295 = NULL , * V_22 ;
unsigned long V_357 = 0 ;
int V_239 ;
F_204 (i, sched_group_cpus(group)) {
unsigned long V_242 = F_191 ( V_239 ) ;
unsigned long V_260 = F_215 ( V_242 ,
V_240 ) ;
unsigned long V_209 ;
if ( ! V_260 )
V_260 = F_262 ( V_213 , V_232 ) ;
if ( ! F_203 ( V_239 , V_1 ) )
continue;
V_22 = F_188 ( V_239 ) ;
V_209 = F_187 ( V_239 ) ;
if ( V_260 && V_22 -> V_71 == 1 && V_209 > V_236 )
continue;
V_209 = ( V_209 * V_240 ) / V_242 ;
if ( V_209 > V_357 ) {
V_357 = V_209 ;
V_295 = V_22 ;
}
}
return V_295 ;
}
static int F_271 ( struct V_212 * V_213 , int V_158 ,
int V_372 , int V_217 )
{
if ( V_158 == V_307 ) {
if ( ( V_213 -> V_125 & V_358 ) && V_372 > V_217 )
return 1 ;
if ( V_383 < V_384 )
return 0 ;
}
return F_11 ( V_213 -> V_290 > V_213 -> V_291 + 2 ) ;
}
static int F_272 ( int V_217 , struct V_22 * V_281 ,
struct V_212 * V_213 , enum V_284 V_158 ,
int * V_345 )
{
int V_385 , V_285 = 0 , V_386 = 0 ;
struct V_229 * V_232 ;
unsigned long V_236 ;
struct V_22 * V_295 ;
unsigned long V_125 ;
struct V_344 * V_1 = F_273 ( V_387 ) ;
F_274 ( V_1 , V_388 ) ;
F_102 ( V_213 , V_389 [ V_158 ] ) ;
V_390:
V_232 = F_269 ( V_213 , V_217 , & V_236 , V_158 ,
V_1 , V_345 ) ;
if ( * V_345 == 0 )
goto V_381;
if ( ! V_232 ) {
F_102 ( V_213 , V_391 [ V_158 ] ) ;
goto V_381;
}
V_295 = F_270 ( V_213 , V_232 , V_158 , V_236 , V_1 ) ;
if ( ! V_295 ) {
F_102 ( V_213 , V_392 [ V_158 ] ) ;
goto V_381;
}
F_222 ( V_295 == V_281 ) ;
F_63 ( V_213 , V_393 [ V_158 ] , V_236 ) ;
V_385 = 0 ;
if ( V_295 -> V_71 > 1 ) {
V_285 |= V_288 ;
F_275 ( V_125 ) ;
F_276 ( V_281 , V_295 ) ;
V_385 = F_248 ( V_281 , V_217 , V_295 ,
V_236 , V_213 , V_158 , & V_285 ) ;
F_277 ( V_281 , V_295 ) ;
F_278 ( V_125 ) ;
if ( V_385 && V_217 != F_132 () )
F_279 ( V_217 ) ;
if ( V_285 & V_308 )
goto V_381;
if ( V_285 & V_306 ) {
V_285 += V_394 - V_306 ;
if ( V_285 & V_308 )
goto V_381;
goto V_390;
}
if ( F_11 ( V_285 & V_288 ) ) {
F_280 ( F_24 ( V_295 ) , V_1 ) ;
if ( ! F_281 ( V_1 ) )
goto V_390;
goto V_381;
}
}
if ( ! V_385 ) {
F_102 ( V_213 , V_395 [ V_158 ] ) ;
if ( V_158 != V_307 )
V_213 -> V_290 ++ ;
if ( F_271 ( V_213 , V_158 , F_24 ( V_295 ) , V_217 ) ) {
F_240 ( & V_295 -> V_156 , V_125 ) ;
if ( ! F_203 ( V_217 ,
F_202 ( V_295 -> V_44 ) ) ) {
F_241 ( & V_295 -> V_156 ,
V_125 ) ;
V_285 |= V_288 ;
goto V_396;
}
if ( ! V_295 -> V_386 ) {
V_295 -> V_386 = 1 ;
V_295 -> V_397 = V_217 ;
V_386 = 1 ;
}
F_241 ( & V_295 -> V_156 , V_125 ) ;
if ( V_386 )
F_282 ( F_24 ( V_295 ) ,
V_398 , V_295 ,
& V_295 -> V_399 ) ;
V_213 -> V_290 = V_213 -> V_291 + 1 ;
}
} else
V_213 -> V_290 = 0 ;
if ( F_9 ( ! V_386 ) ) {
V_213 -> V_400 = V_213 -> V_401 ;
} else {
if ( V_213 -> V_400 < V_213 -> V_402 )
V_213 -> V_400 *= 2 ;
}
goto V_304;
V_381:
F_102 ( V_213 , V_403 [ V_158 ] ) ;
V_213 -> V_290 = 0 ;
V_396:
if ( ( ( V_285 & V_288 ) &&
V_213 -> V_400 < V_404 ) ||
( V_213 -> V_400 < V_213 -> V_402 ) )
V_213 -> V_400 *= 2 ;
V_385 = 0 ;
V_304:
return V_385 ;
}
void F_283 ( int V_217 , struct V_22 * V_281 )
{
struct V_212 * V_213 ;
int V_405 = 0 ;
unsigned long V_406 = V_407 + V_408 ;
V_281 -> V_409 = V_281 -> clock ;
if ( V_281 -> V_410 < V_283 )
return;
F_138 ( & V_281 -> V_156 ) ;
F_242 ( V_217 ) ;
F_146 () ;
F_214 (this_cpu, sd) {
unsigned long V_411 ;
int V_345 = 1 ;
if ( ! ( V_213 -> V_125 & V_257 ) )
continue;
if ( V_213 -> V_125 & V_412 ) {
V_405 = F_272 ( V_217 , V_281 ,
V_213 , V_307 , & V_345 ) ;
}
V_411 = F_284 ( V_213 -> V_400 ) ;
if ( F_285 ( V_406 , V_213 -> V_413 + V_411 ) )
V_406 = V_213 -> V_413 + V_411 ;
if ( V_405 ) {
V_281 -> V_409 = 0 ;
break;
}
}
F_148 () ;
F_136 ( & V_281 -> V_156 ) ;
if ( V_405 || F_285 ( V_407 , V_281 -> V_406 ) ) {
V_281 -> V_406 = V_406 ;
}
}
static int V_398 ( void * V_167 )
{
struct V_22 * V_414 = V_167 ;
int V_372 = F_24 ( V_414 ) ;
int V_415 = V_414 -> V_397 ;
struct V_22 * V_416 = F_188 ( V_415 ) ;
struct V_212 * V_213 ;
F_286 ( & V_414 -> V_156 ) ;
if ( F_11 ( V_372 != F_132 () ||
! V_414 -> V_386 ) )
goto V_180;
if ( V_414 -> V_71 <= 1 )
goto V_180;
F_222 ( V_414 == V_416 ) ;
F_287 ( V_414 , V_416 ) ;
F_146 () ;
F_214 (target_cpu, sd) {
if ( ( V_213 -> V_125 & V_257 ) &&
F_203 ( V_372 , F_216 ( V_213 ) ) )
break;
}
if ( F_9 ( V_213 ) ) {
F_102 ( V_213 , V_417 ) ;
if ( F_235 ( V_416 , V_415 , V_414 ,
V_213 , V_380 ) )
F_102 ( V_213 , V_418 ) ;
else
F_102 ( V_213 , V_419 ) ;
}
F_148 () ;
F_288 ( V_414 , V_416 ) ;
V_180:
V_414 -> V_386 = 0 ;
F_289 ( & V_414 -> V_156 ) ;
return 0 ;
}
static inline struct V_212 * F_290 ( int V_204 , int V_420 )
{
struct V_212 * V_213 ;
F_214 (cpu, sd)
if ( V_213 -> V_125 & V_420 )
break;
return V_213 ;
}
static int F_291 ( int V_204 )
{
int V_421 = F_292 ( V_422 . V_423 ) ;
struct V_229 * V_424 ;
struct V_212 * V_213 ;
if ( ! ( V_425 || V_383 ) )
goto V_426;
if ( F_293 ( V_422 . V_423 ) < 2 )
goto V_426;
F_146 () ;
F_294 (cpu, sd, SD_POWERSAVINGS_BALANCE) {
V_424 = V_213 -> V_233 ;
do {
if ( V_424 -> V_355 !=
F_88 ( & V_424 -> V_241 -> V_427 ) ) {
V_421 = F_212 ( V_422 . V_423 ,
F_201 ( V_424 ) ) ;
goto V_262;
}
V_424 = V_424 -> V_57 ;
} while ( V_424 != V_213 -> V_233 );
}
V_262:
F_148 () ;
V_426:
if ( V_421 < V_428 && F_208 ( V_421 ) )
return V_421 ;
return V_428 ;
}
static inline int F_291 ( int V_429 )
{
return V_428 ;
}
static void F_295 ( int V_204 )
{
int V_430 ;
V_422 . V_406 ++ ;
V_430 = F_291 ( V_204 ) ;
if ( V_430 >= V_428 )
return;
if ( F_296 ( V_431 , F_297 ( V_430 ) ) )
return;
F_298 ( V_430 ) ;
return;
}
static inline void F_299 ( int V_204 )
{
if ( F_11 ( F_300 ( V_432 , F_297 ( V_204 ) ) ) ) {
F_280 ( V_204 , V_422 . V_423 ) ;
F_301 ( & V_422 . V_433 ) ;
F_302 ( V_432 , F_297 ( V_204 ) ) ;
}
}
static inline void F_303 ( void )
{
struct V_212 * V_213 ;
int V_204 = F_132 () ;
if ( ! F_300 ( V_434 , F_297 ( V_204 ) ) )
return;
F_302 ( V_434 , F_297 ( V_204 ) ) ;
F_146 () ;
F_214 (cpu, sd)
F_304 ( & V_213 -> V_233 -> V_241 -> V_427 ) ;
F_148 () ;
}
void F_305 ( void )
{
struct V_212 * V_213 ;
int V_204 = F_132 () ;
if ( F_300 ( V_434 , F_297 ( V_204 ) ) )
return;
F_306 ( V_434 , F_297 ( V_204 ) ) ;
F_146 () ;
F_214 (cpu, sd)
F_301 ( & V_213 -> V_233 -> V_241 -> V_427 ) ;
F_148 () ;
}
void F_307 ( int V_435 )
{
int V_204 = F_132 () ;
if ( ! F_308 ( V_204 ) )
return;
if ( V_435 ) {
if ( F_300 ( V_432 , F_297 ( V_204 ) ) )
return;
F_309 ( V_204 , V_422 . V_423 ) ;
F_304 ( & V_422 . V_433 ) ;
F_306 ( V_432 , F_297 ( V_204 ) ) ;
}
return;
}
static int T_9 F_310 ( struct V_436 * V_437 ,
unsigned long V_438 , void * V_439 )
{
switch ( V_438 & ~ V_440 ) {
case V_441 :
F_299 ( F_132 () ) ;
return V_442 ;
default:
return V_443 ;
}
}
void F_311 ( void )
{
V_444 = V_408 * F_3 () / 10 ;
}
static void F_312 ( int V_204 , enum V_284 V_158 )
{
int V_345 = 1 ;
struct V_22 * V_22 = F_188 ( V_204 ) ;
unsigned long V_411 ;
struct V_212 * V_213 ;
unsigned long V_406 = V_407 + 60 * V_408 ;
int V_445 = 0 ;
int V_446 ;
F_242 ( V_204 ) ;
F_146 () ;
F_214 (cpu, sd) {
if ( ! ( V_213 -> V_125 & V_257 ) )
continue;
V_411 = V_213 -> V_400 ;
if ( V_158 != V_380 )
V_411 *= V_213 -> V_447 ;
V_411 = F_284 ( V_411 ) ;
V_411 = F_313 ( V_411 , 1UL , V_444 ) ;
V_446 = V_213 -> V_125 & V_448 ;
if ( V_446 ) {
if ( ! F_314 ( & V_449 ) )
goto V_304;
}
if ( F_315 ( V_407 , V_213 -> V_413 + V_411 ) ) {
if ( F_272 ( V_204 , V_22 , V_213 , V_158 , & V_345 ) ) {
V_158 = V_316 ;
}
V_213 -> V_413 = V_407 ;
}
if ( V_446 )
F_316 ( & V_449 ) ;
V_304:
if ( F_285 ( V_406 , V_213 -> V_413 + V_411 ) ) {
V_406 = V_213 -> V_413 + V_411 ;
V_445 = 1 ;
}
if ( ! V_345 )
break;
}
F_148 () ;
if ( F_9 ( V_445 ) )
V_22 -> V_406 = V_406 ;
}
static void F_317 ( int V_217 , enum V_284 V_158 )
{
struct V_22 * V_281 = F_188 ( V_217 ) ;
struct V_22 * V_22 ;
int V_349 ;
if ( V_158 != V_380 ||
! F_300 ( V_431 , F_297 ( V_217 ) ) )
goto V_450;
F_204 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_349 == V_217 || ! F_208 ( V_349 ) )
continue;
if ( F_318 () )
break;
F_286 ( & V_281 -> V_156 ) ;
F_150 ( V_281 ) ;
F_319 ( V_281 ) ;
F_289 ( & V_281 -> V_156 ) ;
F_312 ( V_349 , V_380 ) ;
V_22 = F_188 ( V_349 ) ;
if ( F_285 ( V_281 -> V_406 , V_22 -> V_406 ) )
V_281 -> V_406 = V_22 -> V_406 ;
}
V_422 . V_406 = V_281 -> V_406 ;
V_450:
F_302 ( V_431 , F_297 ( V_217 ) ) ;
}
static inline int F_320 ( struct V_22 * V_22 , int V_204 )
{
unsigned long V_85 = V_407 ;
struct V_212 * V_213 ;
if ( F_11 ( F_208 ( V_204 ) ) )
return 0 ;
F_303 () ;
F_299 ( V_204 ) ;
if ( F_9 ( ! F_88 ( & V_422 . V_433 ) ) )
return 0 ;
if ( F_321 ( V_85 , V_422 . V_406 ) )
return 0 ;
if ( V_22 -> V_71 >= 2 )
goto V_451;
F_146 () ;
F_214 (cpu, sd) {
struct V_229 * V_244 = V_213 -> V_233 ;
struct V_452 * V_241 = V_244 -> V_241 ;
int V_453 = F_88 ( & V_241 -> V_427 ) ;
if ( V_213 -> V_125 & V_454 && V_453 > 1 )
goto V_455;
if ( V_213 -> V_125 & V_358 && V_453 != V_244 -> V_355
&& ( F_212 ( V_422 . V_423 ,
F_216 ( V_213 ) ) < V_204 ) )
goto V_455;
if ( ! ( V_213 -> V_125 & ( V_454 | V_358 ) ) )
break;
}
F_148 () ;
return 0 ;
V_455:
F_148 () ;
V_451:
return 1 ;
}
static void F_317 ( int V_217 , enum V_284 V_158 ) { }
static void F_322 ( struct V_456 * V_457 )
{
int V_217 = F_132 () ;
struct V_22 * V_281 = F_188 ( V_217 ) ;
enum V_284 V_158 = V_281 -> F_283 ?
V_380 : V_316 ;
F_312 ( V_217 , V_158 ) ;
F_317 ( V_217 , V_158 ) ;
}
static inline int F_323 ( int V_204 )
{
return ! F_324 ( F_188 ( V_204 ) -> V_213 ) ;
}
void F_325 ( struct V_22 * V_22 , int V_204 )
{
if ( F_315 ( V_407 , V_22 -> V_406 ) &&
F_9 ( ! F_323 ( V_204 ) ) )
F_326 ( V_458 ) ;
#ifdef F_327
if ( F_320 ( V_22 , V_204 ) && F_9 ( ! F_323 ( V_204 ) ) )
F_295 ( V_204 ) ;
#endif
}
static void F_328 ( struct V_22 * V_22 )
{
F_5 () ;
}
static void F_329 ( struct V_22 * V_22 )
{
F_5 () ;
}
static void F_330 ( struct V_22 * V_22 , struct V_24 * V_44 , int V_138 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_44 -> V_26 ;
F_32 (se) {
V_23 = F_21 ( V_26 ) ;
F_120 ( V_23 , V_26 , V_138 ) ;
}
}
static void F_331 ( struct V_24 * V_27 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 = & V_27 -> V_26 , * V_44 ;
int V_217 = F_132 () ;
struct V_22 * V_22 = V_281 () ;
unsigned long V_125 ;
F_240 ( & V_22 -> V_156 , V_125 ) ;
F_150 ( V_22 ) ;
V_23 = F_20 ( V_222 ) ;
V_44 = V_23 -> V_44 ;
if ( F_11 ( F_198 ( V_27 ) != V_217 ) ) {
F_146 () ;
F_332 ( V_27 , V_217 ) ;
F_148 () ;
}
F_64 ( V_23 ) ;
if ( V_44 )
V_26 -> V_40 = V_44 -> V_40 ;
F_103 ( V_23 , V_26 , 1 ) ;
if ( V_459 && V_44 && F_36 ( V_44 , V_26 ) ) {
F_333 ( V_44 -> V_40 , V_26 -> V_40 ) ;
F_114 ( V_22 -> V_44 ) ;
}
V_26 -> V_40 -= V_23 -> V_39 ;
F_241 ( & V_22 -> V_156 , V_125 ) ;
}
static void
F_334 ( struct V_22 * V_22 , struct V_24 * V_27 , int V_460 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 ) {
if ( V_27 -> V_461 > V_460 )
F_114 ( V_22 -> V_44 ) ;
} else
F_231 ( V_22 , V_27 , 0 ) ;
}
static void F_335 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
struct V_25 * V_26 = & V_27 -> V_26 ;
struct V_23 * V_23 = F_21 ( V_26 ) ;
if ( ! V_26 -> V_75 && V_27 -> V_130 != V_462 ) {
F_103 ( V_23 , V_26 , 0 ) ;
V_26 -> V_40 -= V_23 -> V_39 ;
}
}
static void F_336 ( struct V_22 * V_22 , struct V_24 * V_27 )
{
if ( ! V_27 -> V_26 . V_75 )
return;
if ( V_22 -> V_44 == V_27 )
F_114 ( V_22 -> V_44 ) ;
else
F_231 ( V_22 , V_27 , 0 ) ;
}
static void F_337 ( struct V_22 * V_22 )
{
struct V_25 * V_26 = & V_22 -> V_44 -> V_26 ;
F_32 (se) {
struct V_23 * V_23 = F_21 ( V_26 ) ;
F_115 ( V_23 , V_26 ) ;
F_68 ( V_23 , 0 ) ;
}
}
void F_338 ( struct V_23 * V_23 )
{
V_23 -> V_50 = V_463 ;
F_169 ( & V_23 -> V_95 ) ;
V_23 -> V_39 = ( T_2 ) ( - ( 1LL << 20 ) ) ;
#ifndef F_39
V_23 -> V_47 = V_23 -> V_39 ;
#endif
}
static void F_339 ( struct V_24 * V_27 , int V_75 )
{
if ( ! V_75 && ( ! V_27 -> V_26 . V_79 || V_27 -> V_130 == V_464 ) )
V_75 = 1 ;
if ( ! V_75 )
V_27 -> V_26 . V_40 -= F_21 ( & V_27 -> V_26 ) -> V_39 ;
F_340 ( V_27 , F_198 ( V_27 ) ) ;
if ( ! V_75 )
V_27 -> V_26 . V_40 += F_21 ( & V_27 -> V_26 ) -> V_39 ;
}
void F_341 ( struct V_97 * V_31 )
{
int V_239 ;
F_173 ( F_134 ( V_31 ) ) ;
F_342 (i) {
if ( V_31 -> V_23 )
F_343 ( V_31 -> V_23 [ V_239 ] ) ;
if ( V_31 -> V_26 )
F_343 ( V_31 -> V_26 [ V_239 ] ) ;
}
F_343 ( V_31 -> V_23 ) ;
F_343 ( V_31 -> V_26 ) ;
}
int F_344 ( struct V_97 * V_31 , struct V_97 * V_32 )
{
struct V_23 * V_23 ;
struct V_25 * V_26 ;
int V_239 ;
V_31 -> V_23 = F_345 ( sizeof( V_23 ) * V_428 , V_465 ) ;
if ( ! V_31 -> V_23 )
goto V_466;
V_31 -> V_26 = F_345 ( sizeof( V_26 ) * V_428 , V_465 ) ;
if ( ! V_31 -> V_26 )
goto V_466;
V_31 -> V_106 = V_70 ;
F_167 ( F_134 ( V_31 ) ) ;
F_342 (i) {
V_23 = F_346 ( sizeof( struct V_23 ) ,
V_465 , F_347 ( V_239 ) ) ;
if ( ! V_23 )
goto V_466;
V_26 = F_346 ( sizeof( struct V_25 ) ,
V_465 , F_347 ( V_239 ) ) ;
if ( ! V_26 )
goto V_467;
F_338 ( V_23 ) ;
F_348 ( V_31 , V_23 , V_26 , V_239 , V_32 -> V_26 [ V_239 ] ) ;
}
return 1 ;
V_467:
F_343 ( V_23 ) ;
V_466:
return 0 ;
}
void F_349 ( struct V_97 * V_31 , int V_204 )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
unsigned long V_125 ;
if ( ! V_31 -> V_23 [ V_204 ] -> V_30 )
return;
F_240 ( & V_22 -> V_156 , V_125 ) ;
F_27 ( V_31 -> V_23 [ V_204 ] ) ;
F_241 ( & V_22 -> V_156 , V_125 ) ;
}
void F_348 ( struct V_97 * V_31 , struct V_23 * V_23 ,
struct V_25 * V_26 , int V_204 ,
struct V_25 * V_32 )
{
struct V_22 * V_22 = F_188 ( V_204 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_22 = V_22 ;
#ifdef V_82
V_23 -> V_103 = 1 ;
#endif
F_171 ( V_23 ) ;
V_31 -> V_23 [ V_204 ] = V_23 ;
V_31 -> V_26 [ V_204 ] = V_26 ;
if ( ! V_26 )
return;
if ( ! V_32 )
V_26 -> V_23 = & V_22 -> V_38 ;
else
V_26 -> V_23 = V_32 -> V_29 ;
V_26 -> V_29 = V_23 ;
F_93 ( & V_26 -> V_69 , 0 ) ;
V_26 -> V_32 = V_32 ;
}
int F_350 ( struct V_97 * V_31 , unsigned long V_106 )
{
int V_239 ;
unsigned long V_125 ;
if ( ! V_31 -> V_26 [ 0 ] )
return - V_468 ;
V_106 = F_313 ( V_106 , F_351 ( V_107 ) , F_351 ( V_469 ) ) ;
F_352 ( & V_470 ) ;
if ( V_31 -> V_106 == V_106 )
goto V_246;
V_31 -> V_106 = V_106 ;
F_342 (i) {
struct V_22 * V_22 = F_188 ( V_239 ) ;
struct V_25 * V_26 ;
V_26 = V_31 -> V_26 [ V_239 ] ;
F_240 ( & V_22 -> V_156 , V_125 ) ;
F_32 (se)
F_91 ( F_22 ( V_26 ) ) ;
F_241 ( & V_22 -> V_156 , V_125 ) ;
}
V_246:
F_353 ( & V_470 ) ;
return 0 ;
}
void F_341 ( struct V_97 * V_31 ) { }
int F_344 ( struct V_97 * V_31 , struct V_97 * V_32 )
{
return 1 ;
}
void F_349 ( struct V_97 * V_31 , int V_204 ) { }
static unsigned int F_354 ( struct V_22 * V_22 , struct V_24 * V_471 )
{
struct V_25 * V_26 = & V_471 -> V_26 ;
unsigned int V_472 = 0 ;
if ( V_22 -> V_38 . V_69 . V_11 )
V_472 = F_355 ( F_57 ( & V_22 -> V_38 , V_26 ) ) ;
return V_472 ;
}
void F_356 ( struct V_473 * V_474 , int V_204 )
{
struct V_23 * V_23 ;
F_146 () ;
F_175 (cpu_rq(cpu), cfs_rq)
F_357 ( V_474 , V_204 , V_23 ) ;
F_148 () ;
}
T_10 void F_358 ( void )
{
#ifdef V_82
F_359 ( V_458 , F_322 ) ;
#ifdef F_327
F_360 ( & V_422 . V_423 , V_475 ) ;
F_361 ( F_310 , 0 ) ;
#endif
#endif
}
