static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return V_2 -> V_1 ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
#ifdef F_3
F_4 ( ! F_5 ( V_5 ) ) ;
#endif
return F_6 ( V_5 , struct V_3 , V_5 ) ;
}
static inline struct V_2 * F_7 ( struct V_3 * V_6 )
{
return V_6 -> V_5 . V_2 ;
}
static inline struct V_2 * F_8 ( struct V_4 * V_5 )
{
return V_5 -> V_2 ;
}
static inline struct V_2 * F_9 ( struct V_4 * V_7 )
{
return V_7 -> V_8 ;
}
static inline struct V_2 * F_10 ( struct V_2 * V_2 , int V_9 )
{
return V_2 -> V_10 -> V_2 [ V_9 ] ;
}
static inline void F_11 ( struct V_2 * V_2 )
{
if ( ! V_2 -> V_11 ) {
if ( V_2 -> V_10 -> V_12 &&
V_2 -> V_10 -> V_12 -> V_2 [ F_12 ( F_1 ( V_2 ) ) ] -> V_11 ) {
F_13 ( & V_2 -> V_13 ,
& F_1 ( V_2 ) -> V_13 ) ;
} else {
F_14 ( & V_2 -> V_13 ,
& F_1 ( V_2 ) -> V_13 ) ;
}
V_2 -> V_11 = 1 ;
}
}
static inline void F_15 ( struct V_2 * V_2 )
{
if ( V_2 -> V_11 ) {
F_16 ( & V_2 -> V_13 ) ;
V_2 -> V_11 = 0 ;
}
}
static inline int
F_17 ( struct V_4 * V_5 , struct V_4 * V_14 )
{
if ( V_5 -> V_2 == V_14 -> V_2 )
return 1 ;
return 0 ;
}
static inline struct V_4 * F_18 ( struct V_4 * V_5 )
{
return V_5 -> V_12 ;
}
static inline int F_19 ( struct V_4 * V_5 )
{
int V_15 = 0 ;
F_20 (se)
V_15 ++ ;
return V_15 ;
}
static void
F_21 ( struct V_4 * * V_5 , struct V_4 * * V_14 )
{
int V_16 , V_17 ;
V_16 = F_19 ( * V_5 ) ;
V_17 = F_19 ( * V_14 ) ;
while ( V_16 > V_17 ) {
V_16 -- ;
* V_5 = F_18 ( * V_5 ) ;
}
while ( V_17 > V_16 ) {
V_17 -- ;
* V_14 = F_18 ( * V_14 ) ;
}
while ( ! F_17 ( * V_5 , * V_14 ) ) {
* V_5 = F_18 ( * V_5 ) ;
* V_14 = F_18 ( * V_14 ) ;
}
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , struct V_3 , V_5 ) ;
}
static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_6 ( V_2 , struct V_1 , V_18 ) ;
}
static inline struct V_2 * F_7 ( struct V_3 * V_6 )
{
return & F_22 ( V_6 ) -> V_18 ;
}
static inline struct V_2 * F_8 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_2 ( V_5 ) ;
struct V_1 * V_1 = F_22 ( V_6 ) ;
return & V_1 -> V_18 ;
}
static inline struct V_2 * F_9 ( struct V_4 * V_7 )
{
return NULL ;
}
static inline struct V_2 * F_10 ( struct V_2 * V_2 , int V_9 )
{
return & F_23 ( V_9 ) -> V_18 ;
}
static inline void F_11 ( struct V_2 * V_2 )
{
}
static inline void F_15 ( struct V_2 * V_2 )
{
}
static inline int
F_17 ( struct V_4 * V_5 , struct V_4 * V_14 )
{
return 1 ;
}
static inline struct V_4 * F_18 ( struct V_4 * V_5 )
{
return NULL ;
}
static inline void
F_21 ( struct V_4 * * V_5 , struct V_4 * * V_14 )
{
}
static inline T_1 F_24 ( T_1 V_19 , T_1 V_20 )
{
T_2 V_21 = ( T_2 ) ( V_20 - V_19 ) ;
if ( V_21 > 0 )
V_19 = V_20 ;
return V_19 ;
}
static inline T_1 V_19 ( T_1 V_19 , T_1 V_20 )
{
T_2 V_21 = ( T_2 ) ( V_20 - V_19 ) ;
if ( V_21 < 0 )
V_19 = V_20 ;
return V_19 ;
}
static inline int F_25 ( struct V_4 * V_22 ,
struct V_4 * V_23 )
{
return ( T_2 ) ( V_22 -> V_20 - V_23 -> V_20 ) < 0 ;
}
static inline T_2 F_26 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
return V_5 -> V_20 - V_2 -> V_19 ;
}
static void F_27 ( struct V_2 * V_2 )
{
T_1 V_20 = V_2 -> V_19 ;
if ( V_2 -> V_24 )
V_20 = V_2 -> V_24 -> V_20 ;
if ( V_2 -> V_25 ) {
struct V_4 * V_5 = F_28 ( V_2 -> V_25 ,
struct V_4 ,
V_26 ) ;
if ( ! V_2 -> V_24 )
V_20 = V_5 -> V_20 ;
else
V_20 = V_19 ( V_20 , V_5 -> V_20 ) ;
}
V_2 -> V_19 = F_24 ( V_2 -> V_19 , V_20 ) ;
#ifndef F_29
F_30 () ;
V_2 -> V_27 = V_2 -> V_19 ;
#endif
}
static void F_31 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_28 * * V_29 = & V_2 -> V_30 . V_28 ;
struct V_28 * V_12 = NULL ;
struct V_4 * V_31 ;
T_2 V_32 = F_26 ( V_2 , V_5 ) ;
int V_33 = 1 ;
while ( * V_29 ) {
V_12 = * V_29 ;
V_31 = F_28 ( V_12 , struct V_4 , V_26 ) ;
if ( V_32 < F_26 ( V_2 , V_31 ) ) {
V_29 = & V_12 -> V_34 ;
} else {
V_29 = & V_12 -> V_35 ;
V_33 = 0 ;
}
}
if ( V_33 )
V_2 -> V_25 = & V_5 -> V_26 ;
F_32 ( & V_5 -> V_26 , V_12 , V_29 ) ;
F_33 ( & V_5 -> V_26 , & V_2 -> V_30 ) ;
}
static void F_34 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_2 -> V_25 == & V_5 -> V_26 ) {
struct V_28 * V_36 ;
V_36 = F_35 ( & V_5 -> V_26 ) ;
V_2 -> V_25 = V_36 ;
}
F_36 ( & V_5 -> V_26 , & V_2 -> V_30 ) ;
}
static struct V_4 * F_37 ( struct V_2 * V_2 )
{
struct V_28 * V_37 = V_2 -> V_25 ;
if ( ! V_37 )
return NULL ;
return F_28 ( V_37 , struct V_4 , V_26 ) ;
}
static struct V_4 * F_38 ( struct V_4 * V_5 )
{
struct V_28 * V_38 = F_35 ( & V_5 -> V_26 ) ;
if ( ! V_38 )
return NULL ;
return F_28 ( V_38 , struct V_4 , V_26 ) ;
}
static struct V_4 * F_39 ( struct V_2 * V_2 )
{
struct V_28 * V_39 = F_40 ( & V_2 -> V_30 ) ;
if ( ! V_39 )
return NULL ;
return F_28 ( V_39 , struct V_4 , V_26 ) ;
}
int F_41 ( struct V_40 * V_41 , int V_42 ,
void T_3 * V_43 , T_4 * V_44 ,
T_5 * V_45 )
{
int V_46 = F_42 ( V_41 , V_42 , V_43 , V_44 , V_45 ) ;
int V_47 = F_43 () ;
if ( V_46 || ! V_42 )
return V_46 ;
V_48 = F_44 ( V_49 ,
V_50 ) ;
#define F_45 ( T_6 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_45 ( V_51 ) ;
F_45 ( V_52 ) ;
F_45 ( V_53 ) ;
#undef F_45
return 0 ;
}
static inline unsigned long
F_46 ( unsigned long V_21 , struct V_4 * V_5 )
{
if ( F_47 ( V_5 -> V_54 . V_55 != V_56 ) )
V_21 = F_48 ( V_21 , V_56 , & V_5 -> V_54 ) ;
return V_21 ;
}
static T_1 F_49 ( unsigned long V_57 )
{
T_1 V_58 = V_49 ;
unsigned long V_59 = V_48 ;
if ( F_47 ( V_57 > V_59 ) ) {
V_58 = V_50 ;
V_58 *= V_57 ;
}
return V_58 ;
}
static T_1 F_50 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
T_1 V_60 = F_49 ( V_2 -> V_57 + ! V_5 -> V_61 ) ;
F_20 (se) {
struct V_62 * V_54 ;
struct V_62 V_63 ;
V_2 = F_8 ( V_5 ) ;
V_54 = & V_2 -> V_54 ;
if ( F_47 ( ! V_5 -> V_61 ) ) {
V_63 = V_2 -> V_54 ;
F_51 ( & V_63 , V_5 -> V_54 . V_55 ) ;
V_54 = & V_63 ;
}
V_60 = F_48 ( V_60 , V_5 -> V_54 . V_55 , V_54 ) ;
}
return V_60 ;
}
static T_1 F_52 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
return F_46 ( F_50 ( V_2 , V_5 ) , V_5 ) ;
}
static inline void
F_53 ( struct V_2 * V_2 , struct V_4 * V_24 ,
unsigned long V_64 )
{
unsigned long V_65 ;
F_54 ( V_24 -> V_66 . V_67 ,
F_55 ( ( T_1 ) V_64 , V_24 -> V_66 . V_67 ) ) ;
V_24 -> V_68 += V_64 ;
F_56 ( V_2 , V_69 , V_64 ) ;
V_65 = F_46 ( V_64 , V_24 ) ;
V_24 -> V_20 += V_65 ;
F_27 ( V_2 ) ;
#if V_70 V_71 && V_70 V_72
V_2 -> V_73 += V_64 ;
#endif
}
static void F_57 ( struct V_2 * V_2 )
{
struct V_4 * V_24 = V_2 -> V_24 ;
T_1 V_74 = F_1 ( V_2 ) -> V_75 ;
unsigned long V_64 ;
if ( F_47 ( ! V_24 ) )
return;
V_64 = ( unsigned long ) ( V_74 - V_24 -> V_76 ) ;
if ( ! V_64 )
return;
F_53 ( V_2 , V_24 , V_64 ) ;
V_24 -> V_76 = V_74 ;
if ( F_5 ( V_24 ) ) {
struct V_3 * V_77 = F_2 ( V_24 ) ;
F_58 ( V_77 , V_64 , V_24 -> V_20 ) ;
F_59 ( V_77 , V_64 ) ;
F_60 ( V_77 , V_64 ) ;
}
}
static inline void
F_61 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_54 ( V_5 -> V_66 . V_78 , F_1 ( V_2 ) -> clock ) ;
}
static void F_62 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_24 )
F_61 ( V_2 , V_5 ) ;
}
static void
F_63 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_54 ( V_5 -> V_66 . V_79 , F_55 ( V_5 -> V_66 . V_79 ,
F_1 ( V_2 ) -> clock - V_5 -> V_66 . V_78 ) ) ;
F_54 ( V_5 -> V_66 . V_80 , V_5 -> V_66 . V_80 + 1 ) ;
F_54 ( V_5 -> V_66 . V_81 , V_5 -> V_66 . V_81 +
F_1 ( V_2 ) -> clock - V_5 -> V_66 . V_78 ) ;
#ifdef F_64
if ( F_5 ( V_5 ) ) {
F_65 ( F_2 ( V_5 ) ,
F_1 ( V_2 ) -> clock - V_5 -> V_66 . V_78 ) ;
}
#endif
F_54 ( V_5 -> V_66 . V_78 , 0 ) ;
}
static inline void
F_66 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_24 )
F_63 ( V_2 , V_5 ) ;
}
static inline void
F_67 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_76 = F_1 ( V_2 ) -> V_75 ;
}
static void
F_68 ( struct V_2 * V_2 , unsigned long V_55 )
{
V_2 -> V_82 += V_55 ;
}
static inline void
F_68 ( struct V_2 * V_2 , unsigned long V_55 )
{
}
static void
F_69 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_51 ( & V_2 -> V_54 , V_5 -> V_54 . V_55 ) ;
if ( ! F_18 ( V_5 ) )
F_70 ( F_1 ( V_2 ) , V_5 -> V_54 . V_55 ) ;
if ( F_5 ( V_5 ) ) {
F_68 ( V_2 , V_5 -> V_54 . V_55 ) ;
F_71 ( & V_5 -> V_83 , & V_2 -> V_84 ) ;
}
V_2 -> V_57 ++ ;
}
static void
F_72 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_73 ( & V_2 -> V_54 , V_5 -> V_54 . V_55 ) ;
if ( ! F_18 ( V_5 ) )
F_74 ( F_1 ( V_2 ) , V_5 -> V_54 . V_55 ) ;
if ( F_5 ( V_5 ) ) {
F_68 ( V_2 , - V_5 -> V_54 . V_55 ) ;
F_75 ( & V_5 -> V_83 ) ;
}
V_2 -> V_57 -- ;
}
static void F_76 ( struct V_2 * V_2 ,
int V_85 )
{
struct V_86 * V_10 = V_2 -> V_10 ;
long V_87 ;
V_87 = F_77 ( V_2 -> V_87 , V_2 -> V_88 + 1 ) ;
V_87 -= V_2 -> V_89 ;
if ( V_85 || abs ( V_87 ) > V_2 -> V_89 / 8 ) {
F_78 ( V_87 , & V_10 -> V_62 ) ;
V_2 -> V_89 += V_87 ;
}
}
static void F_79 ( struct V_2 * V_2 , int V_85 )
{
T_1 V_58 = V_90 ;
T_1 V_74 , V_21 ;
unsigned long V_54 = V_2 -> V_54 . V_55 ;
if ( V_2 -> V_10 == & V_91 )
return;
V_74 = F_1 ( V_2 ) -> V_75 ;
V_21 = V_74 - V_2 -> V_92 ;
if ( V_2 -> V_92 > V_2 -> V_93 &&
V_74 - V_2 -> V_93 > 4 * V_58 ) {
V_2 -> V_88 = 0 ;
V_2 -> V_87 = 0 ;
V_21 = V_58 - 1 ;
}
V_2 -> V_92 = V_74 ;
V_2 -> V_73 = 0 ;
V_2 -> V_88 += V_21 ;
if ( V_54 ) {
V_2 -> V_93 = V_74 ;
V_2 -> V_87 += V_21 * V_54 ;
}
if ( V_85 || V_2 -> V_88 > V_58
|| ! V_2 -> V_88 )
F_76 ( V_2 , V_85 ) ;
while ( V_2 -> V_88 > V_58 ) {
asm("" : "+rm" (cfs_rq->load_period));
V_2 -> V_88 /= 2 ;
V_2 -> V_87 /= 2 ;
}
if ( ! V_2 -> V_24 && ! V_2 -> V_57 && ! V_2 -> V_87 )
F_15 ( V_2 ) ;
}
static long F_80 ( struct V_2 * V_2 , struct V_86 * V_10 )
{
long V_62 , V_54 , V_94 ;
V_54 = V_2 -> V_54 . V_55 ;
V_62 = F_81 ( & V_10 -> V_62 ) ;
V_62 += V_54 ;
V_62 -= V_2 -> V_89 ;
V_94 = ( V_10 -> V_94 * V_54 ) ;
if ( V_62 )
V_94 /= V_62 ;
if ( V_94 < V_95 )
V_94 = V_95 ;
if ( V_94 > V_10 -> V_94 )
V_94 = V_10 -> V_94 ;
return V_94 ;
}
static void F_82 ( struct V_2 * V_2 )
{
if ( V_2 -> V_73 > V_90 ) {
F_79 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
}
static void F_79 ( struct V_2 * V_2 , int V_85 )
{
}
static inline long F_80 ( struct V_2 * V_2 , struct V_86 * V_10 )
{
return V_10 -> V_94 ;
}
static inline void F_82 ( struct V_2 * V_2 )
{
}
static void F_84 ( struct V_2 * V_2 , struct V_4 * V_5 ,
unsigned long V_55 )
{
if ( V_5 -> V_61 ) {
if ( V_2 -> V_24 == V_5 )
F_57 ( V_2 ) ;
F_72 ( V_2 , V_5 ) ;
}
F_85 ( & V_5 -> V_54 , V_55 ) ;
if ( V_5 -> V_61 )
F_69 ( V_2 , V_5 ) ;
}
static void F_83 ( struct V_2 * V_2 )
{
struct V_86 * V_10 ;
struct V_4 * V_5 ;
long V_94 ;
V_10 = V_2 -> V_10 ;
V_5 = V_10 -> V_5 [ F_12 ( F_1 ( V_2 ) ) ] ;
if ( ! V_5 )
return;
#ifndef V_71
if ( F_86 ( V_5 -> V_54 . V_55 == V_10 -> V_94 ) )
return;
#endif
V_94 = F_80 ( V_2 , V_10 ) ;
F_84 ( F_8 ( V_5 ) , V_5 , V_94 ) ;
}
static void F_79 ( struct V_2 * V_2 , int V_85 )
{
}
static inline void F_83 ( struct V_2 * V_2 )
{
}
static inline void F_82 ( struct V_2 * V_2 )
{
}
static void F_87 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
#ifdef F_64
struct V_3 * V_96 = NULL ;
if ( F_5 ( V_5 ) )
V_96 = F_2 ( V_5 ) ;
if ( V_5 -> V_66 . V_97 ) {
T_1 V_21 = F_1 ( V_2 ) -> clock - V_5 -> V_66 . V_97 ;
if ( ( T_2 ) V_21 < 0 )
V_21 = 0 ;
if ( F_47 ( V_21 > V_5 -> V_66 . V_98 ) )
V_5 -> V_66 . V_98 = V_21 ;
V_5 -> V_66 . V_97 = 0 ;
V_5 -> V_66 . V_99 += V_21 ;
if ( V_96 ) {
F_88 ( V_96 , V_21 >> 10 , 1 ) ;
F_89 ( V_96 , V_21 ) ;
}
}
if ( V_5 -> V_66 . V_100 ) {
T_1 V_21 = F_1 ( V_2 ) -> clock - V_5 -> V_66 . V_100 ;
if ( ( T_2 ) V_21 < 0 )
V_21 = 0 ;
if ( F_47 ( V_21 > V_5 -> V_66 . V_101 ) )
V_5 -> V_66 . V_101 = V_21 ;
V_5 -> V_66 . V_100 = 0 ;
V_5 -> V_66 . V_99 += V_21 ;
if ( V_96 ) {
if ( V_96 -> V_102 ) {
V_5 -> V_66 . V_103 += V_21 ;
V_5 -> V_66 . V_104 ++ ;
F_90 ( V_96 , V_21 ) ;
}
if ( F_47 ( V_105 == V_106 ) ) {
F_91 ( V_106 ,
( void * ) F_92 ( V_96 ) ,
V_21 >> 20 ) ;
}
F_88 ( V_96 , V_21 >> 10 , 0 ) ;
}
}
#endif
}
static void F_93 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
#ifdef F_3
T_2 V_107 = V_5 -> V_20 - V_2 -> V_19 ;
if ( V_107 < 0 )
V_107 = - V_107 ;
if ( V_107 > 3 * V_49 )
F_94 ( V_2 , V_108 ) ;
#endif
}
static void
F_95 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_109 )
{
T_1 V_20 = V_2 -> V_19 ;
if ( V_109 && F_96 ( V_110 ) )
V_20 += F_52 ( V_2 , V_5 ) ;
if ( ! V_109 ) {
unsigned long V_111 = V_49 ;
if ( F_96 ( V_112 ) )
V_111 >>= 1 ;
V_20 -= V_111 ;
}
V_20 = F_24 ( V_5 -> V_20 , V_20 ) ;
V_5 -> V_20 = V_20 ;
}
static void
F_97 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_113 )
{
if ( ! ( V_113 & V_114 ) || ( V_113 & V_115 ) )
V_5 -> V_20 += V_2 -> V_19 ;
F_57 ( V_2 ) ;
F_79 ( V_2 , 0 ) ;
F_69 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
if ( V_113 & V_114 ) {
F_95 ( V_2 , V_5 , 0 ) ;
F_87 ( V_2 , V_5 ) ;
}
F_62 ( V_2 , V_5 ) ;
F_93 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_24 )
F_31 ( V_2 , V_5 ) ;
V_5 -> V_61 = 1 ;
if ( V_2 -> V_57 == 1 )
F_11 ( V_2 ) ;
}
static void F_98 ( struct V_4 * V_5 )
{
F_20 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_39 == V_5 )
V_2 -> V_39 = NULL ;
else
break;
}
}
static void F_99 ( struct V_4 * V_5 )
{
F_20 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_38 == V_5 )
V_2 -> V_38 = NULL ;
else
break;
}
}
static void F_100 ( struct V_4 * V_5 )
{
F_20 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_116 == V_5 )
V_2 -> V_116 = NULL ;
else
break;
}
}
static void F_101 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_2 -> V_39 == V_5 )
F_98 ( V_5 ) ;
if ( V_2 -> V_38 == V_5 )
F_99 ( V_5 ) ;
if ( V_2 -> V_116 == V_5 )
F_100 ( V_5 ) ;
}
static void
F_102 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_113 )
{
F_57 ( V_2 ) ;
F_66 ( V_2 , V_5 ) ;
if ( V_113 & V_117 ) {
#ifdef F_64
if ( F_5 ( V_5 ) ) {
struct V_3 * V_96 = F_2 ( V_5 ) ;
if ( V_96 -> V_118 & V_119 )
V_5 -> V_66 . V_97 = F_1 ( V_2 ) -> clock ;
if ( V_96 -> V_118 & V_120 )
V_5 -> V_66 . V_100 = F_1 ( V_2 ) -> clock ;
}
#endif
}
F_101 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_24 )
F_34 ( V_2 , V_5 ) ;
V_5 -> V_61 = 0 ;
F_79 ( V_2 , 0 ) ;
F_72 ( V_2 , V_5 ) ;
if ( ! ( V_113 & V_117 ) )
V_5 -> V_20 -= V_2 -> V_19 ;
F_27 ( V_2 ) ;
F_83 ( V_2 ) ;
}
static void
F_103 ( struct V_2 * V_2 , struct V_4 * V_24 )
{
unsigned long V_121 , V_64 ;
V_121 = F_50 ( V_2 , V_24 ) ;
V_64 = V_24 -> V_68 - V_24 -> V_122 ;
if ( V_64 > V_121 ) {
F_104 ( F_1 ( V_2 ) -> V_24 ) ;
F_101 ( V_2 , V_24 ) ;
return;
}
if ( ! F_96 ( V_123 ) )
return;
if ( V_64 < V_50 )
return;
if ( V_2 -> V_57 > 1 ) {
struct V_4 * V_5 = F_37 ( V_2 ) ;
T_2 V_21 = V_24 -> V_20 - V_5 -> V_20 ;
if ( V_21 < 0 )
return;
if ( V_21 > V_121 )
F_104 ( F_1 ( V_2 ) -> V_24 ) ;
}
}
static void
F_105 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_61 ) {
F_63 ( V_2 , V_5 ) ;
F_34 ( V_2 , V_5 ) ;
}
F_67 ( V_2 , V_5 ) ;
V_2 -> V_24 = V_5 ;
#ifdef F_64
if ( F_1 ( V_2 ) -> V_54 . V_55 >= 2 * V_5 -> V_54 . V_55 ) {
V_5 -> V_66 . V_124 = F_55 ( V_5 -> V_66 . V_124 ,
V_5 -> V_68 - V_5 -> V_122 ) ;
}
#endif
V_5 -> V_122 = V_5 -> V_68 ;
}
static struct V_4 * F_106 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_37 ( V_2 ) ;
struct V_4 * V_37 = V_5 ;
if ( V_2 -> V_116 == V_5 ) {
struct V_4 * V_125 = F_38 ( V_5 ) ;
if ( V_125 && F_107 ( V_125 , V_37 ) < 1 )
V_5 = V_125 ;
}
if ( V_2 -> V_39 && F_107 ( V_2 -> V_39 , V_37 ) < 1 )
V_5 = V_2 -> V_39 ;
if ( V_2 -> V_38 && F_107 ( V_2 -> V_38 , V_37 ) < 1 )
V_5 = V_2 -> V_38 ;
F_101 ( V_2 , V_5 ) ;
return V_5 ;
}
static void F_108 ( struct V_2 * V_2 , struct V_4 * V_126 )
{
if ( V_126 -> V_61 )
F_57 ( V_2 ) ;
F_93 ( V_2 , V_126 ) ;
if ( V_126 -> V_61 ) {
F_61 ( V_2 , V_126 ) ;
F_31 ( V_2 , V_126 ) ;
}
V_2 -> V_24 = NULL ;
}
static void
F_109 ( struct V_2 * V_2 , struct V_4 * V_24 , int V_127 )
{
F_57 ( V_2 ) ;
F_82 ( V_2 ) ;
#ifdef F_110
if ( V_127 ) {
F_104 ( F_1 ( V_2 ) -> V_24 ) ;
return;
}
if ( ! F_96 ( V_128 ) &&
F_111 ( & F_1 ( V_2 ) -> V_129 ) )
return;
#endif
if ( V_2 -> V_57 > 1 || ! F_96 ( V_123 ) )
F_103 ( V_2 , V_24 ) ;
}
static void F_112 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_113 ( F_22 ( V_6 ) != V_1 ) ;
if ( F_114 ( V_1 ) && V_2 -> V_57 > 1 ) {
T_1 V_60 = F_50 ( V_2 , V_5 ) ;
T_1 V_130 = V_5 -> V_68 - V_5 -> V_122 ;
T_2 V_21 = V_60 - V_130 ;
if ( V_21 < 0 ) {
if ( V_1 -> V_24 == V_6 )
F_104 ( V_6 ) ;
return;
}
if ( V_1 -> V_24 != V_6 )
V_21 = F_115 ( T_2 , 10000LL , V_21 ) ;
F_116 ( V_1 , V_21 ) ;
}
}
static void F_117 ( struct V_1 * V_1 )
{
struct V_3 * V_24 = V_1 -> V_24 ;
if ( V_24 -> V_131 != & V_132 )
return;
if ( F_8 ( & V_24 -> V_5 ) -> V_57 < V_48 )
F_112 ( V_1 , V_24 ) ;
}
static inline void
F_112 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
}
static inline void F_117 ( struct V_1 * V_1 )
{
}
static void
F_118 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_113 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
F_20 (se) {
if ( V_5 -> V_61 )
break;
V_2 = F_8 ( V_5 ) ;
F_97 ( V_2 , V_5 , V_113 ) ;
V_113 = V_114 ;
}
F_20 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_79 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
F_117 ( V_1 ) ;
}
static void F_119 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_113 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
int V_133 = V_113 & V_117 ;
F_20 (se) {
V_2 = F_8 ( V_5 ) ;
F_102 ( V_2 , V_5 , V_113 ) ;
if ( V_2 -> V_54 . V_55 ) {
if ( V_133 && F_18 ( V_5 ) )
F_120 ( F_18 ( V_5 ) ) ;
break;
}
V_113 |= V_117 ;
}
F_20 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_79 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
F_117 ( V_1 ) ;
}
static void F_121 ( struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
T_1 V_19 ;
#ifndef F_29
T_1 V_27 ;
do {
V_27 = V_2 -> V_27 ;
F_122 () ;
V_19 = V_2 -> V_19 ;
} while ( V_19 != V_27 );
#else
V_19 = V_2 -> V_19 ;
#endif
V_5 -> V_20 -= V_19 ;
}
static long F_123 ( struct V_86 * V_10 , int V_134 , long V_135 , long V_136 )
{
struct V_4 * V_5 = V_10 -> V_5 [ V_134 ] ;
if ( ! V_10 -> V_12 )
return V_135 ;
F_20 (se) {
long V_63 , V_137 ;
V_10 = V_5 -> V_8 -> V_10 ;
V_137 = V_5 -> V_8 -> V_54 . V_55 ;
V_63 = F_81 ( & V_10 -> V_62 ) ;
V_63 -= V_5 -> V_8 -> V_89 ;
V_63 += V_137 + V_136 ;
V_135 += V_137 ;
if ( V_63 > 0 && V_135 < V_63 )
V_135 = ( V_135 * V_10 -> V_94 ) / V_63 ;
else
V_135 = V_10 -> V_94 ;
if ( V_135 < V_95 )
V_135 = V_95 ;
V_135 -= V_5 -> V_54 . V_55 ;
V_136 = 0 ;
}
return V_135 ;
}
static inline unsigned long F_123 ( struct V_86 * V_10 , int V_134 ,
unsigned long V_135 , unsigned long V_136 )
{
return V_135 ;
}
static int F_124 ( struct V_138 * V_139 , struct V_3 * V_6 , int V_140 )
{
T_2 V_141 , V_54 ;
int V_142 , V_9 , V_143 ;
unsigned long V_144 ;
struct V_86 * V_10 ;
unsigned long V_55 ;
int V_145 ;
V_142 = V_139 -> V_146 ;
V_9 = F_125 () ;
V_143 = F_126 ( V_6 ) ;
V_54 = F_127 ( V_143 , V_142 ) ;
V_141 = F_128 ( V_9 , V_142 ) ;
F_129 () ;
if ( V_140 ) {
V_10 = V_86 ( V_147 ) ;
V_55 = V_147 -> V_5 . V_54 . V_55 ;
V_141 += F_123 ( V_10 , V_9 , - V_55 , - V_55 ) ;
V_54 += F_123 ( V_10 , V_143 , 0 , - V_55 ) ;
}
V_10 = V_86 ( V_6 ) ;
V_55 = V_6 -> V_5 . V_54 . V_55 ;
if ( V_141 > 0 ) {
T_2 V_148 , V_149 ;
V_148 = 100 ;
V_148 *= F_130 ( V_143 ) ;
V_148 *= V_141 +
F_123 ( V_10 , V_9 , V_55 , V_55 ) ;
V_149 = 100 + ( V_139 -> V_150 - 100 ) / 2 ;
V_149 *= F_130 ( V_9 ) ;
V_149 *= V_54 + F_123 ( V_10 , V_143 , 0 , V_55 ) ;
V_145 = V_148 <= V_149 ;
} else
V_145 = true ;
F_131 () ;
if ( V_140 && V_145 )
return 1 ;
F_94 ( V_6 , V_5 . V_66 . V_151 ) ;
V_144 = F_132 ( V_9 ) ;
if ( V_145 ||
( V_141 <= V_54 &&
V_141 + F_128 ( V_143 , V_142 ) <= V_144 ) ) {
F_94 ( V_139 , V_152 ) ;
F_94 ( V_6 , V_5 . V_66 . V_153 ) ;
return 1 ;
}
return 0 ;
}
static struct V_154 *
F_133 ( struct V_138 * V_139 , struct V_3 * V_6 ,
int V_9 , int V_155 )
{
struct V_154 * V_156 = NULL , * V_157 = V_139 -> V_158 ;
unsigned long V_159 = V_160 , V_141 = 0 ;
int V_161 = 100 + ( V_139 -> V_150 - 100 ) / 2 ;
do {
unsigned long V_54 , V_162 ;
int V_163 ;
int V_164 ;
if ( ! F_134 ( F_135 ( V_157 ) ,
& V_6 -> V_165 ) )
continue;
V_163 = F_136 ( V_9 ,
F_135 ( V_157 ) ) ;
V_162 = 0 ;
F_137 (i, sched_group_cpus(group)) {
if ( V_163 )
V_54 = F_127 ( V_164 , V_155 ) ;
else
V_54 = F_128 ( V_164 , V_155 ) ;
V_162 += V_54 ;
}
V_162 = ( V_162 * V_166 ) / V_157 -> V_167 -> V_168 ;
if ( V_163 ) {
V_141 = V_162 ;
} else if ( V_162 < V_159 ) {
V_159 = V_162 ;
V_156 = V_157 ;
}
} while ( V_157 = V_157 -> V_38 , V_157 != V_139 -> V_158 );
if ( ! V_156 || 100 * V_141 < V_161 * V_159 )
return NULL ;
return V_156 ;
}
static int
F_138 ( struct V_154 * V_157 , struct V_3 * V_6 , int V_9 )
{
unsigned long V_54 , V_159 = V_160 ;
int V_156 = - 1 ;
int V_164 ;
F_139 (i, sched_group_cpus(group), &p->cpus_allowed) {
V_54 = F_140 ( V_164 ) ;
if ( V_54 < V_159 || ( V_54 == V_159 && V_164 == V_9 ) ) {
V_159 = V_54 ;
V_156 = V_164 ;
}
}
return V_156 ;
}
static int F_141 ( struct V_3 * V_6 , int V_169 )
{
int V_134 = F_125 () ;
int V_143 = F_126 ( V_6 ) ;
struct V_138 * V_139 ;
int V_164 ;
if ( V_169 == V_134 && F_142 ( V_134 ) )
return V_134 ;
if ( V_169 == V_143 && F_142 ( V_143 ) )
return V_143 ;
F_129 () ;
F_143 (target, sd) {
if ( ! ( V_139 -> V_113 & V_170 ) )
break;
F_139 (i, sched_domain_span(sd), &p->cpus_allowed) {
if ( F_142 ( V_164 ) ) {
V_169 = V_164 ;
break;
}
}
if ( F_136 ( V_134 , F_144 ( V_139 ) ) &&
F_136 ( V_143 , F_144 ( V_139 ) ) )
break;
}
F_131 () ;
return V_169 ;
}
static int
F_145 ( struct V_3 * V_6 , int V_171 , int V_172 )
{
struct V_138 * V_173 , * V_174 = NULL , * V_139 = NULL ;
int V_134 = F_125 () ;
int V_143 = F_126 ( V_6 ) ;
int V_175 = V_134 ;
int V_176 = 0 ;
int V_177 = 1 ;
int V_140 = V_172 & V_178 ;
if ( V_171 & V_179 ) {
if ( F_136 ( V_134 , & V_6 -> V_165 ) )
V_176 = 1 ;
V_175 = V_143 ;
}
F_129 () ;
F_143 (cpu, tmp) {
if ( ! ( V_173 -> V_113 & V_180 ) )
continue;
if ( V_173 -> V_113 & ( V_181 | V_182 ) ) {
unsigned long V_168 = 0 ;
unsigned long V_57 = 0 ;
unsigned long V_183 ;
int V_164 ;
F_137 (i, sched_domain_span(tmp)) {
V_168 += F_130 ( V_164 ) ;
V_57 += F_23 ( V_164 ) -> V_18 . V_57 ;
}
V_183 = F_146 ( V_168 , V_166 ) ;
if ( V_173 -> V_113 & V_181 )
V_57 /= 2 ;
if ( V_57 < V_183 )
V_177 = 0 ;
}
if ( V_176 && ( V_173 -> V_113 & V_184 ) &&
F_136 ( V_143 , F_144 ( V_173 ) ) ) {
V_174 = V_173 ;
V_176 = 0 ;
}
if ( ! V_177 && ! V_176 )
break;
if ( ! ( V_173 -> V_113 & V_171 ) )
continue;
if ( V_177 )
V_139 = V_173 ;
}
if ( V_174 ) {
if ( V_134 == V_143 || F_124 ( V_174 , V_6 , V_140 ) )
V_143 = V_134 ;
V_175 = F_141 ( V_6 , V_143 ) ;
goto V_185;
}
while ( V_139 ) {
int V_155 = V_139 -> V_186 ;
struct V_154 * V_157 ;
int V_55 ;
if ( ! ( V_139 -> V_113 & V_171 ) ) {
V_139 = V_139 -> V_187 ;
continue;
}
if ( V_171 & V_179 )
V_155 = V_139 -> V_146 ;
V_157 = F_133 ( V_139 , V_6 , V_134 , V_155 ) ;
if ( ! V_157 ) {
V_139 = V_139 -> V_187 ;
continue;
}
V_175 = F_138 ( V_157 , V_6 , V_134 ) ;
if ( V_175 == - 1 || V_175 == V_134 ) {
V_139 = V_139 -> V_187 ;
continue;
}
V_134 = V_175 ;
V_55 = V_139 -> V_188 ;
V_139 = NULL ;
F_143 (cpu, tmp) {
if ( V_55 <= V_173 -> V_188 )
break;
if ( V_173 -> V_113 & V_171 )
V_139 = V_173 ;
}
}
V_185:
F_131 () ;
return V_175 ;
}
static unsigned long
F_147 ( struct V_4 * V_24 , struct V_4 * V_5 )
{
unsigned long V_189 = V_190 ;
return F_46 ( V_189 , V_5 ) ;
}
static int
F_107 ( struct V_4 * V_24 , struct V_4 * V_5 )
{
T_2 V_189 , V_191 = V_24 -> V_20 - V_5 -> V_20 ;
if ( V_191 <= 0 )
return - 1 ;
V_189 = F_147 ( V_24 , V_5 ) ;
if ( V_191 > V_189 )
return 1 ;
return 0 ;
}
static void F_148 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_47 ( F_2 ( V_5 ) -> V_192 == V_193 ) )
return;
F_20 (se)
F_8 ( V_5 ) -> V_39 = V_5 ;
}
static void F_120 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_47 ( F_2 ( V_5 ) -> V_192 == V_193 ) )
return;
F_20 (se)
F_8 ( V_5 ) -> V_38 = V_5 ;
}
static void F_149 ( struct V_4 * V_5 )
{
F_20 (se)
F_8 ( V_5 ) -> V_116 = V_5 ;
}
static void F_150 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_172 )
{
struct V_3 * V_24 = V_1 -> V_24 ;
struct V_4 * V_5 = & V_24 -> V_5 , * V_14 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_7 ( V_24 ) ;
int V_194 = V_2 -> V_57 >= V_48 ;
int V_195 = 0 ;
if ( F_47 ( V_5 == V_14 ) )
return;
if ( F_96 ( V_196 ) && V_194 && ! ( V_172 & V_197 ) ) {
F_120 ( V_14 ) ;
V_195 = 1 ;
}
if ( F_151 ( V_24 ) )
return;
if ( F_47 ( V_24 -> V_192 == V_193 ) &&
F_86 ( V_6 -> V_192 != V_193 ) )
goto V_198;
if ( F_47 ( V_6 -> V_192 != V_199 ) )
return;
if ( ! F_96 ( V_123 ) )
return;
F_57 ( V_2 ) ;
F_21 ( & V_5 , & V_14 ) ;
F_152 ( ! V_14 ) ;
if ( F_107 ( V_5 , V_14 ) == 1 ) {
if ( ! V_195 )
F_120 ( V_14 ) ;
goto V_198;
}
return;
V_198:
F_104 ( V_24 ) ;
if ( F_47 ( ! V_5 -> V_61 || V_24 == V_1 -> V_200 ) )
return;
if ( F_96 ( V_201 ) && V_194 && F_5 ( V_5 ) )
F_148 ( V_5 ) ;
}
static struct V_3 * F_153 ( struct V_1 * V_1 )
{
struct V_3 * V_6 ;
struct V_2 * V_2 = & V_1 -> V_18 ;
struct V_4 * V_5 ;
if ( ! V_2 -> V_57 )
return NULL ;
do {
V_5 = F_106 ( V_2 ) ;
F_105 ( V_2 , V_5 ) ;
V_2 = F_9 ( V_5 ) ;
} while ( V_2 );
V_6 = F_2 ( V_5 ) ;
F_112 ( V_1 , V_6 ) ;
return V_6 ;
}
static void F_154 ( struct V_1 * V_1 , struct V_3 * V_126 )
{
struct V_4 * V_5 = & V_126 -> V_5 ;
struct V_2 * V_2 ;
F_20 (se) {
V_2 = F_8 ( V_5 ) ;
F_108 ( V_2 , V_5 ) ;
}
}
static void F_155 ( struct V_1 * V_1 )
{
struct V_3 * V_24 = V_1 -> V_24 ;
struct V_2 * V_2 = F_7 ( V_24 ) ;
struct V_4 * V_5 = & V_24 -> V_5 ;
if ( F_47 ( V_1 -> V_57 == 1 ) )
return;
F_101 ( V_2 , V_5 ) ;
if ( V_24 -> V_192 != V_202 ) {
F_156 ( V_1 ) ;
F_57 ( V_2 ) ;
}
F_149 ( V_5 ) ;
}
static bool F_157 ( struct V_1 * V_1 , struct V_3 * V_6 , bool V_198 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
if ( ! V_5 -> V_61 )
return false ;
F_120 ( V_5 ) ;
F_155 ( V_1 ) ;
return true ;
}
static void F_158 ( struct V_1 * V_203 , struct V_3 * V_6 ,
struct V_1 * V_204 , int V_9 )
{
F_159 ( V_203 , V_6 , 0 ) ;
F_160 ( V_6 , V_9 ) ;
F_161 ( V_204 , V_6 , 0 ) ;
F_162 ( V_204 , V_6 , 0 ) ;
}
static
int F_163 ( struct V_3 * V_6 , struct V_1 * V_1 , int V_9 ,
struct V_138 * V_139 , enum V_205 V_200 ,
int * V_206 )
{
int V_207 = 0 ;
if ( ! F_136 ( V_9 , & V_6 -> V_165 ) ) {
F_94 ( V_6 , V_5 . V_66 . V_208 ) ;
return 0 ;
}
* V_206 = 0 ;
if ( F_164 ( V_1 , V_6 ) ) {
F_94 ( V_6 , V_5 . V_66 . V_209 ) ;
return 0 ;
}
V_207 = F_165 ( V_6 , V_1 -> V_75 , V_139 ) ;
if ( ! V_207 ||
V_139 -> V_210 > V_139 -> V_211 ) {
#ifdef F_64
if ( V_207 ) {
F_94 ( V_139 , V_212 [ V_200 ] ) ;
F_94 ( V_6 , V_5 . V_66 . V_213 ) ;
}
#endif
return 1 ;
}
if ( V_207 ) {
F_94 ( V_6 , V_5 . V_66 . V_214 ) ;
return 0 ;
}
return 1 ;
}
static int
F_166 ( struct V_1 * V_204 , int V_9 , struct V_1 * V_215 ,
struct V_138 * V_139 , enum V_205 V_200 )
{
struct V_3 * V_6 , * V_216 ;
struct V_2 * V_2 ;
int V_217 = 0 ;
F_167 (busiest, cfs_rq) {
F_168 (p, n, &cfs_rq->tasks, se.group_node) {
if ( ! F_163 ( V_6 , V_215 , V_9 ,
V_139 , V_200 , & V_217 ) )
continue;
F_158 ( V_215 , V_6 , V_204 , V_9 ) ;
F_94 ( V_139 , V_218 [ V_200 ] ) ;
return 1 ;
}
}
return 0 ;
}
static unsigned long
F_169 ( struct V_1 * V_204 , int V_9 , struct V_1 * V_215 ,
unsigned long V_219 , struct V_138 * V_139 ,
enum V_205 V_200 , int * V_206 ,
struct V_2 * V_220 )
{
int V_221 = 0 , V_222 = 0 ;
long V_223 = V_219 ;
struct V_3 * V_6 , * V_216 ;
if ( V_219 == 0 )
goto V_224;
F_168 (p, n, &busiest_cfs_rq->tasks, se.group_node) {
if ( V_221 ++ > V_225 )
break;
if ( ( V_6 -> V_5 . V_54 . V_55 >> 1 ) > V_223 ||
! F_163 ( V_6 , V_215 , V_9 , V_139 , V_200 ,
V_206 ) )
continue;
F_158 ( V_215 , V_6 , V_204 , V_9 ) ;
V_222 ++ ;
V_223 -= V_6 -> V_5 . V_54 . V_55 ;
#ifdef F_170
if ( V_200 == V_226 )
break;
#endif
if ( V_223 <= 0 )
break;
}
V_224:
F_56 ( V_139 , V_218 [ V_200 ] , V_222 ) ;
return V_219 - V_223 ;
}
static int F_171 ( struct V_86 * V_10 , int V_134 )
{
struct V_2 * V_2 ;
unsigned long V_113 ;
struct V_1 * V_1 ;
if ( ! V_10 -> V_5 [ V_134 ] )
return 0 ;
V_1 = F_23 ( V_134 ) ;
V_2 = V_10 -> V_2 [ V_134 ] ;
F_172 ( & V_1 -> V_227 , V_113 ) ;
F_156 ( V_1 ) ;
F_79 ( V_2 , 1 ) ;
F_83 ( V_2 ) ;
F_173 ( & V_1 -> V_227 , V_113 ) ;
return 0 ;
}
static void F_174 ( int V_134 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 = F_23 ( V_134 ) ;
F_129 () ;
F_167 (rq, cfs_rq)
F_171 ( V_2 -> V_10 , V_134 ) ;
F_131 () ;
}
static unsigned long
F_175 ( struct V_1 * V_204 , int V_9 , struct V_1 * V_215 ,
unsigned long V_219 ,
struct V_138 * V_139 , enum V_205 V_200 ,
int * V_206 )
{
long V_223 = V_219 ;
int V_228 = F_12 ( V_215 ) ;
struct V_86 * V_10 ;
F_129 () ;
F_176 ( V_228 ) ;
F_177 (tg, &task_groups, list) {
struct V_2 * V_220 = V_10 -> V_2 [ V_228 ] ;
unsigned long V_229 = V_220 -> V_230 ;
unsigned long V_231 = V_220 -> V_54 . V_55 ;
T_1 V_232 , V_233 ;
if ( ! V_220 -> V_82 )
continue;
V_232 = ( T_1 ) V_223 * V_231 ;
V_232 = F_178 ( V_232 , V_229 + 1 ) ;
V_233 = F_169 ( V_204 , V_9 , V_215 ,
V_232 , V_139 , V_200 , V_206 ,
V_220 ) ;
if ( ! V_233 )
continue;
V_233 *= V_229 ;
V_233 = F_178 ( V_233 , V_231 + 1 ) ;
V_223 -= V_233 ;
if ( V_223 < 0 )
break;
}
F_131 () ;
return V_219 - V_223 ;
}
static inline void F_174 ( int V_134 )
{
}
static unsigned long
F_175 ( struct V_1 * V_204 , int V_9 , struct V_1 * V_215 ,
unsigned long V_219 ,
struct V_138 * V_139 , enum V_205 V_200 ,
int * V_206 )
{
return F_169 ( V_204 , V_9 , V_215 ,
V_219 , V_139 , V_200 , V_206 ,
& V_215 -> V_18 ) ;
}
static int F_179 ( struct V_1 * V_204 , int V_9 , struct V_1 * V_215 ,
unsigned long V_219 ,
struct V_138 * V_139 , enum V_205 V_200 ,
int * V_206 )
{
unsigned long V_234 = 0 , V_235 ;
do {
V_235 = F_175 ( V_204 , V_9 , V_215 ,
V_219 - V_234 ,
V_139 , V_200 , V_206 ) ;
V_234 += V_235 ;
#ifdef F_170
if ( V_200 == V_226 && V_204 -> V_57 )
break;
if ( F_180 ( & V_204 -> V_227 ) ||
F_180 ( & V_215 -> V_227 ) )
break;
#endif
} while ( V_235 && V_219 > V_234 );
return V_234 > 0 ;
}
static inline unsigned int F_181 ( struct V_154 * V_157 )
{
return F_182 ( F_135 ( V_157 ) ) ;
}
static inline int F_183 ( struct V_138 * V_139 ,
enum V_205 V_200 )
{
int V_155 ;
switch ( V_200 ) {
case V_236 :
V_155 = V_139 -> V_237 ;
break;
case V_226 :
V_155 = V_139 -> V_238 ;
break;
default:
V_155 = V_139 -> V_239 ;
break;
}
return V_155 ;
}
static inline void F_184 ( struct V_138 * V_139 ,
struct V_240 * V_241 , enum V_205 V_200 )
{
if ( V_200 == V_236 || ! ( V_139 -> V_113 & V_181 ) )
V_241 -> V_242 = 0 ;
else {
V_241 -> V_242 = 1 ;
V_241 -> V_243 = V_160 ;
V_241 -> V_244 = 0 ;
}
}
static inline void F_185 ( struct V_154 * V_157 ,
struct V_240 * V_241 , int V_163 , struct V_245 * V_246 )
{
if ( ! V_241 -> V_242 )
return;
if ( V_163 && ( V_241 -> V_247 >= V_246 -> V_248 ||
! V_241 -> V_247 ) )
V_241 -> V_242 = 0 ;
if ( ! V_241 -> V_242 ||
V_246 -> V_249 >= V_246 -> V_248 ||
! V_246 -> V_249 )
return;
if ( ( V_246 -> V_249 < V_241 -> V_243 ) ||
( V_246 -> V_249 == V_241 -> V_243 &&
F_181 ( V_157 ) > F_181 ( V_241 -> V_250 ) ) ) {
V_241 -> V_250 = V_157 ;
V_241 -> V_243 = V_246 -> V_249 ;
V_241 -> V_251 = V_246 -> V_252 /
V_246 -> V_249 ;
}
if ( V_246 -> V_249 + 1 > V_246 -> V_248 )
return;
if ( V_246 -> V_249 > V_241 -> V_244 ||
( V_246 -> V_249 == V_241 -> V_244 &&
F_181 ( V_157 ) < F_181 ( V_241 -> V_253 ) ) ) {
V_241 -> V_253 = V_157 ;
V_241 -> V_244 = V_246 -> V_249 ;
}
}
static inline int F_186 ( struct V_240 * V_241 ,
int V_9 , unsigned long * V_161 )
{
if ( ! V_241 -> V_242 )
return 0 ;
if ( V_241 -> V_254 != V_241 -> V_253 ||
V_241 -> V_253 == V_241 -> V_250 )
return 0 ;
* V_161 = V_241 -> V_251 ;
V_241 -> V_215 = V_241 -> V_250 ;
return 1 ;
}
static inline void F_184 ( struct V_138 * V_139 ,
struct V_240 * V_241 , enum V_205 V_200 )
{
return;
}
static inline void F_185 ( struct V_154 * V_157 ,
struct V_240 * V_241 , int V_163 , struct V_245 * V_246 )
{
return;
}
static inline int F_186 ( struct V_240 * V_241 ,
int V_9 , unsigned long * V_161 )
{
return 0 ;
}
unsigned long F_187 ( struct V_138 * V_139 , int V_134 )
{
return V_166 ;
}
unsigned long __weak F_188 ( struct V_138 * V_139 , int V_134 )
{
return F_187 ( V_139 , V_134 ) ;
}
unsigned long F_189 ( struct V_138 * V_139 , int V_134 )
{
unsigned long V_55 = V_139 -> V_188 ;
unsigned long V_255 = V_139 -> V_255 ;
V_255 /= V_55 ;
return V_255 ;
}
unsigned long __weak F_190 ( struct V_138 * V_139 , int V_134 )
{
return F_189 ( V_139 , V_134 ) ;
}
unsigned long F_191 ( int V_134 )
{
struct V_1 * V_1 = F_23 ( V_134 ) ;
T_1 V_256 , V_257 ;
V_256 = F_192 () + ( V_1 -> clock - V_1 -> V_258 ) ;
if ( F_47 ( V_256 < V_1 -> V_259 ) ) {
V_257 = 0 ;
} else {
V_257 = V_256 - V_1 -> V_259 ;
}
if ( F_47 ( ( T_2 ) V_256 < V_166 ) )
V_256 = V_166 ;
V_256 >>= V_260 ;
return F_178 ( V_257 , V_256 ) ;
}
static void F_193 ( struct V_138 * V_139 , int V_134 )
{
unsigned long V_55 = V_139 -> V_188 ;
unsigned long V_168 = V_166 ;
struct V_154 * V_261 = V_139 -> V_158 ;
if ( ( V_139 -> V_113 & V_262 ) && V_55 > 1 ) {
if ( F_96 ( V_263 ) )
V_168 *= F_190 ( V_139 , V_134 ) ;
else
V_168 *= F_189 ( V_139 , V_134 ) ;
V_168 >>= V_260 ;
}
V_261 -> V_167 -> V_264 = V_168 ;
if ( F_96 ( V_263 ) )
V_168 *= F_188 ( V_139 , V_134 ) ;
else
V_168 *= F_187 ( V_139 , V_134 ) ;
V_168 >>= V_260 ;
V_168 *= F_191 ( V_134 ) ;
V_168 >>= V_260 ;
if ( ! V_168 )
V_168 = 1 ;
F_23 ( V_134 ) -> V_265 = V_168 ;
V_261 -> V_167 -> V_168 = V_168 ;
}
static void F_194 ( struct V_138 * V_139 , int V_134 )
{
struct V_138 * V_187 = V_139 -> V_187 ;
struct V_154 * V_157 , * V_261 = V_139 -> V_158 ;
unsigned long V_168 ;
if ( ! V_187 ) {
F_193 ( V_139 , V_134 ) ;
return;
}
V_168 = 0 ;
V_157 = V_187 -> V_158 ;
do {
V_168 += V_157 -> V_167 -> V_168 ;
V_157 = V_157 -> V_38 ;
} while ( V_157 != V_187 -> V_158 );
V_261 -> V_167 -> V_168 = V_168 ;
}
static inline int
F_195 ( struct V_138 * V_139 , struct V_154 * V_157 )
{
if ( ! ( V_139 -> V_113 & V_262 ) )
return 0 ;
if ( V_157 -> V_167 -> V_168 * 32 > V_157 -> V_167 -> V_264 * 29 )
return 1 ;
return 0 ;
}
static inline void F_196 ( struct V_138 * V_139 ,
struct V_154 * V_157 , int V_9 ,
enum V_205 V_200 , int V_155 ,
int V_163 , const struct V_266 * V_267 ,
int * V_268 , struct V_245 * V_246 )
{
unsigned long V_54 , V_269 , V_270 , V_271 ;
int V_164 ;
unsigned int V_272 = - 1 , V_273 = 0 ;
unsigned long V_274 = 0 ;
if ( V_163 )
V_272 = F_181 ( V_157 ) ;
V_269 = 0 ;
V_270 = ~ 0UL ;
V_271 = 0 ;
F_139 (i, sched_group_cpus(group), cpus) {
struct V_1 * V_1 = F_23 ( V_164 ) ;
if ( V_163 ) {
if ( F_142 ( V_164 ) && ! V_273 ) {
V_273 = 1 ;
V_272 = V_164 ;
}
V_54 = F_128 ( V_164 , V_155 ) ;
} else {
V_54 = F_127 ( V_164 , V_155 ) ;
if ( V_54 > V_269 ) {
V_269 = V_54 ;
V_271 = V_1 -> V_57 ;
}
if ( V_270 > V_54 )
V_270 = V_54 ;
}
V_246 -> V_275 += V_54 ;
V_246 -> V_249 += V_1 -> V_57 ;
V_246 -> V_252 += F_140 ( V_164 ) ;
if ( F_142 ( V_164 ) )
V_246 -> V_276 ++ ;
}
if ( V_200 != V_226 && V_163 ) {
if ( V_272 != V_9 ) {
* V_268 = 0 ;
return;
}
F_194 ( V_139 , V_9 ) ;
}
V_246 -> V_162 = ( V_246 -> V_275 * V_166 ) / V_157 -> V_167 -> V_168 ;
if ( V_246 -> V_249 )
V_274 = V_246 -> V_252 / V_246 -> V_249 ;
if ( ( V_269 - V_270 ) >= V_274 && V_271 > 1 )
V_246 -> V_277 = 1 ;
V_246 -> V_248 = F_146 ( V_157 -> V_167 -> V_168 ,
V_166 ) ;
if ( ! V_246 -> V_248 )
V_246 -> V_248 = F_195 ( V_139 , V_157 ) ;
V_246 -> V_278 = V_157 -> V_278 ;
if ( V_246 -> V_248 > V_246 -> V_249 )
V_246 -> V_279 = 1 ;
}
static bool F_197 ( struct V_138 * V_139 ,
struct V_240 * V_241 ,
struct V_154 * V_280 ,
struct V_245 * V_246 ,
int V_9 )
{
if ( V_246 -> V_162 <= V_241 -> V_281 )
return false ;
if ( V_246 -> V_249 > V_246 -> V_248 )
return true ;
if ( V_246 -> V_277 )
return true ;
if ( ( V_139 -> V_113 & V_282 ) && V_246 -> V_249 &&
V_9 < F_181 ( V_280 ) ) {
if ( ! V_241 -> V_215 )
return true ;
if ( F_181 ( V_241 -> V_215 ) > F_181 ( V_280 ) )
return true ;
}
return false ;
}
static inline void F_198 ( struct V_138 * V_139 , int V_9 ,
enum V_205 V_200 , const struct V_266 * V_267 ,
int * V_268 , struct V_240 * V_241 )
{
struct V_138 * V_187 = V_139 -> V_187 ;
struct V_154 * V_280 = V_139 -> V_158 ;
struct V_245 V_246 ;
int V_155 , V_283 = 0 ;
if ( V_187 && V_187 -> V_113 & V_284 )
V_283 = 1 ;
F_184 ( V_139 , V_241 , V_200 ) ;
V_155 = F_183 ( V_139 , V_200 ) ;
do {
int V_163 ;
V_163 = F_136 ( V_9 , F_135 ( V_280 ) ) ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
F_196 ( V_139 , V_280 , V_9 , V_200 , V_155 ,
V_163 , V_267 , V_268 , & V_246 ) ;
if ( V_163 && ! ( * V_268 ) )
return;
V_241 -> V_285 += V_246 . V_275 ;
V_241 -> V_286 += V_280 -> V_167 -> V_168 ;
if ( V_283 && ! V_163 && V_241 -> V_287 )
V_246 . V_248 = F_199 ( V_246 . V_248 , 1UL ) ;
if ( V_163 ) {
V_241 -> V_141 = V_246 . V_162 ;
V_241 -> V_254 = V_280 ;
V_241 -> V_247 = V_246 . V_249 ;
V_241 -> V_288 = V_246 . V_252 ;
V_241 -> V_287 = V_246 . V_279 ;
V_241 -> V_289 = V_246 . V_276 ;
} else if ( F_197 ( V_139 , V_241 , V_280 , & V_246 , V_9 ) ) {
V_241 -> V_281 = V_246 . V_162 ;
V_241 -> V_215 = V_280 ;
V_241 -> V_290 = V_246 . V_249 ;
V_241 -> V_291 = V_246 . V_276 ;
V_241 -> V_292 = V_246 . V_248 ;
V_241 -> V_293 = V_246 . V_252 ;
V_241 -> V_294 = V_246 . V_279 ;
V_241 -> V_295 = V_246 . V_278 ;
V_241 -> V_277 = V_246 . V_277 ;
}
F_185 ( V_280 , V_241 , V_163 , & V_246 ) ;
V_280 = V_280 -> V_38 ;
} while ( V_280 != V_139 -> V_158 );
}
int __weak F_200 ( void )
{
return 0 * V_282 ;
}
static int F_201 ( struct V_138 * V_139 ,
struct V_240 * V_241 ,
int V_9 , unsigned long * V_161 )
{
int V_228 ;
if ( ! ( V_139 -> V_113 & V_282 ) )
return 0 ;
if ( ! V_241 -> V_215 )
return 0 ;
V_228 = F_181 ( V_241 -> V_215 ) ;
if ( V_9 > V_228 )
return 0 ;
* V_161 = F_146 ( V_241 -> V_281 * V_241 -> V_215 -> V_167 -> V_168 ,
V_166 ) ;
return 1 ;
}
static inline void F_202 ( struct V_240 * V_241 ,
int V_9 , unsigned long * V_161 )
{
unsigned long V_173 , V_296 = 0 , V_297 = 0 ;
unsigned int V_298 = 2 ;
unsigned long V_299 ;
if ( V_241 -> V_247 ) {
V_241 -> V_288 /= V_241 -> V_247 ;
if ( V_241 -> V_293 >
V_241 -> V_288 )
V_298 = 1 ;
} else
V_241 -> V_288 =
F_132 ( V_9 ) ;
V_299 = V_241 -> V_293
* V_166 ;
V_299 /= V_241 -> V_215 -> V_167 -> V_168 ;
if ( V_241 -> V_281 - V_241 -> V_141 + V_299 >=
( V_299 * V_298 ) ) {
* V_161 = V_241 -> V_293 ;
return;
}
V_296 += V_241 -> V_215 -> V_167 -> V_168 *
F_199 ( V_241 -> V_293 , V_241 -> V_281 ) ;
V_296 += V_241 -> V_254 -> V_167 -> V_168 *
F_199 ( V_241 -> V_288 , V_241 -> V_141 ) ;
V_296 /= V_166 ;
V_173 = ( V_241 -> V_293 * V_166 ) /
V_241 -> V_215 -> V_167 -> V_168 ;
if ( V_241 -> V_281 > V_173 )
V_297 += V_241 -> V_215 -> V_167 -> V_168 *
F_199 ( V_241 -> V_293 , V_241 -> V_281 - V_173 ) ;
if ( V_241 -> V_281 * V_241 -> V_215 -> V_167 -> V_168 <
V_241 -> V_293 * V_166 )
V_173 = ( V_241 -> V_281 * V_241 -> V_215 -> V_167 -> V_168 ) /
V_241 -> V_254 -> V_167 -> V_168 ;
else
V_173 = ( V_241 -> V_293 * V_166 ) /
V_241 -> V_254 -> V_167 -> V_168 ;
V_297 += V_241 -> V_254 -> V_167 -> V_168 *
F_199 ( V_241 -> V_288 , V_241 -> V_141 + V_173 ) ;
V_297 /= V_166 ;
if ( V_297 > V_296 )
* V_161 = V_241 -> V_293 ;
}
static inline void F_203 ( struct V_240 * V_241 , int V_9 ,
unsigned long * V_161 )
{
unsigned long V_300 , V_301 = ~ 0UL ;
V_241 -> V_293 /= V_241 -> V_290 ;
if ( V_241 -> V_277 ) {
V_241 -> V_293 =
F_199 ( V_241 -> V_293 , V_241 -> V_162 ) ;
}
if ( V_241 -> V_281 < V_241 -> V_162 ) {
* V_161 = 0 ;
return F_202 ( V_241 , V_9 , V_161 ) ;
}
if ( ! V_241 -> V_277 ) {
V_301 = ( V_241 -> V_290 -
V_241 -> V_292 ) ;
V_301 *= ( V_302 * V_166 ) ;
V_301 /= V_241 -> V_215 -> V_167 -> V_168 ;
}
V_300 = F_199 ( V_241 -> V_281 - V_241 -> V_162 , V_301 ) ;
* V_161 = F_199 ( V_300 * V_241 -> V_215 -> V_167 -> V_168 ,
( V_241 -> V_162 - V_241 -> V_141 ) * V_241 -> V_254 -> V_167 -> V_168 )
/ V_166 ;
if ( * V_161 < V_241 -> V_293 )
return F_202 ( V_241 , V_9 , V_161 ) ;
}
static struct V_154 *
F_204 ( struct V_138 * V_139 , int V_9 ,
unsigned long * V_161 , enum V_205 V_200 ,
const struct V_266 * V_267 , int * V_268 )
{
struct V_240 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
F_198 ( V_139 , V_9 , V_200 , V_267 , V_268 , & V_241 ) ;
if ( ! ( * V_268 ) )
goto V_46;
if ( ( V_200 == V_303 || V_200 == V_226 ) &&
F_201 ( V_139 , & V_241 , V_9 , V_161 ) )
return V_241 . V_215 ;
if ( ! V_241 . V_215 || V_241 . V_290 == 0 )
goto V_304;
V_241 . V_162 = ( V_166 * V_241 . V_285 ) / V_241 . V_286 ;
if ( V_241 . V_277 )
goto V_305;
if ( V_200 == V_226 && V_241 . V_287 &&
! V_241 . V_294 )
goto V_305;
if ( V_241 . V_141 >= V_241 . V_281 )
goto V_304;
if ( V_241 . V_141 >= V_241 . V_162 )
goto V_304;
if ( V_200 == V_303 ) {
if ( ( V_241 . V_289 <= V_241 . V_291 + 1 ) &&
V_241 . V_290 <= V_241 . V_295 )
goto V_304;
} else {
if ( 100 * V_241 . V_281 <= V_139 -> V_150 * V_241 . V_141 )
goto V_304;
}
V_305:
F_203 ( & V_241 , V_9 , V_161 ) ;
return V_241 . V_215 ;
V_304:
if ( F_186 ( & V_241 , V_9 , V_161 ) )
return V_241 . V_215 ;
V_46:
* V_161 = 0 ;
return NULL ;
}
static struct V_1 *
F_205 ( struct V_138 * V_139 , struct V_154 * V_157 ,
enum V_205 V_200 , unsigned long V_161 ,
const struct V_266 * V_267 )
{
struct V_1 * V_215 = NULL , * V_1 ;
unsigned long V_281 = 0 ;
int V_164 ;
F_137 (i, sched_group_cpus(group)) {
unsigned long V_168 = F_130 ( V_164 ) ;
unsigned long V_183 = F_146 ( V_168 ,
V_166 ) ;
unsigned long V_135 ;
if ( ! V_183 )
V_183 = F_195 ( V_139 , V_157 ) ;
if ( ! F_136 ( V_164 , V_267 ) )
continue;
V_1 = F_23 ( V_164 ) ;
V_135 = F_140 ( V_164 ) ;
if ( V_183 && V_1 -> V_57 == 1 && V_135 > V_161 )
continue;
V_135 = ( V_135 * V_166 ) / V_168 ;
if ( V_135 > V_281 ) {
V_281 = V_135 ;
V_215 = V_1 ;
}
}
return V_215 ;
}
static int F_206 ( struct V_138 * V_139 , int V_200 ,
int V_228 , int V_9 )
{
if ( V_200 == V_226 ) {
if ( ( V_139 -> V_113 & V_282 ) && V_228 > V_9 )
return 1 ;
if ( V_306 < V_307 )
return 0 ;
}
return F_47 ( V_139 -> V_210 > V_139 -> V_211 + 2 ) ;
}
static int F_207 ( int V_9 , struct V_1 * V_204 ,
struct V_138 * V_139 , enum V_205 V_200 ,
int * V_268 )
{
int V_308 , V_206 = 0 , V_309 = 0 ;
struct V_154 * V_157 ;
unsigned long V_161 ;
struct V_1 * V_215 ;
unsigned long V_113 ;
struct V_266 * V_267 = F_208 ( V_310 ) ;
F_209 ( V_267 , V_311 ) ;
F_94 ( V_139 , V_312 [ V_200 ] ) ;
V_313:
V_157 = F_204 ( V_139 , V_9 , & V_161 , V_200 ,
V_267 , V_268 ) ;
if ( * V_268 == 0 )
goto V_304;
if ( ! V_157 ) {
F_94 ( V_139 , V_314 [ V_200 ] ) ;
goto V_304;
}
V_215 = F_205 ( V_139 , V_157 , V_200 , V_161 , V_267 ) ;
if ( ! V_215 ) {
F_94 ( V_139 , V_315 [ V_200 ] ) ;
goto V_304;
}
F_152 ( V_215 == V_204 ) ;
F_56 ( V_139 , V_316 [ V_200 ] , V_161 ) ;
V_308 = 0 ;
if ( V_215 -> V_57 > 1 ) {
V_206 = 1 ;
F_210 ( V_113 ) ;
F_211 ( V_204 , V_215 ) ;
V_308 = F_179 ( V_204 , V_9 , V_215 ,
V_161 , V_139 , V_200 , & V_206 ) ;
F_212 ( V_204 , V_215 ) ;
F_213 ( V_113 ) ;
if ( V_308 && V_9 != F_125 () )
F_214 ( V_9 ) ;
if ( F_47 ( V_206 ) ) {
F_215 ( F_12 ( V_215 ) , V_267 ) ;
if ( ! F_216 ( V_267 ) )
goto V_313;
goto V_304;
}
}
if ( ! V_308 ) {
F_94 ( V_139 , V_317 [ V_200 ] ) ;
if ( V_200 != V_226 )
V_139 -> V_210 ++ ;
if ( F_206 ( V_139 , V_200 , F_12 ( V_215 ) , V_9 ) ) {
F_172 ( & V_215 -> V_227 , V_113 ) ;
if ( ! F_136 ( V_9 ,
& V_215 -> V_24 -> V_165 ) ) {
F_173 ( & V_215 -> V_227 ,
V_113 ) ;
V_206 = 1 ;
goto V_318;
}
if ( ! V_215 -> V_309 ) {
V_215 -> V_309 = 1 ;
V_215 -> V_319 = V_9 ;
V_309 = 1 ;
}
F_173 ( & V_215 -> V_227 , V_113 ) ;
if ( V_309 )
F_217 ( F_12 ( V_215 ) ,
V_320 , V_215 ,
& V_215 -> V_321 ) ;
V_139 -> V_210 = V_139 -> V_211 + 1 ;
}
} else
V_139 -> V_210 = 0 ;
if ( F_86 ( ! V_309 ) ) {
V_139 -> V_322 = V_139 -> V_323 ;
} else {
if ( V_139 -> V_322 < V_139 -> V_324 )
V_139 -> V_322 *= 2 ;
}
goto V_224;
V_304:
F_94 ( V_139 , V_325 [ V_200 ] ) ;
V_139 -> V_210 = 0 ;
V_318:
if ( ( V_206 && V_139 -> V_322 < V_326 ) ||
( V_139 -> V_322 < V_139 -> V_324 ) )
V_139 -> V_322 *= 2 ;
V_308 = 0 ;
V_224:
return V_308 ;
}
static void F_218 ( int V_9 , struct V_1 * V_204 )
{
struct V_138 * V_139 ;
int V_327 = 0 ;
unsigned long V_328 = V_329 + V_330 ;
V_204 -> V_331 = V_204 -> clock ;
if ( V_204 -> V_332 < V_333 )
return;
F_219 ( & V_204 -> V_227 ) ;
F_174 ( V_9 ) ;
F_129 () ;
F_143 (this_cpu, sd) {
unsigned long V_334 ;
int V_268 = 1 ;
if ( ! ( V_139 -> V_113 & V_180 ) )
continue;
if ( V_139 -> V_113 & V_335 ) {
V_327 = F_207 ( V_9 , V_204 ,
V_139 , V_226 , & V_268 ) ;
}
V_334 = F_220 ( V_139 -> V_322 ) ;
if ( F_221 ( V_328 , V_139 -> V_336 + V_334 ) )
V_328 = V_139 -> V_336 + V_334 ;
if ( V_327 ) {
V_204 -> V_331 = 0 ;
break;
}
}
F_131 () ;
F_222 ( & V_204 -> V_227 ) ;
if ( V_327 || F_221 ( V_329 , V_204 -> V_328 ) ) {
V_204 -> V_328 = V_328 ;
}
}
static int V_320 ( void * V_337 )
{
struct V_1 * V_338 = V_337 ;
int V_228 = F_12 ( V_338 ) ;
int V_339 = V_338 -> V_319 ;
struct V_1 * V_340 = F_23 ( V_339 ) ;
struct V_138 * V_139 ;
F_223 ( & V_338 -> V_227 ) ;
if ( F_47 ( V_228 != F_125 () ||
! V_338 -> V_309 ) )
goto V_341;
if ( V_338 -> V_57 <= 1 )
goto V_341;
F_152 ( V_338 == V_340 ) ;
F_224 ( V_338 , V_340 ) ;
F_129 () ;
F_143 (target_cpu, sd) {
if ( ( V_139 -> V_113 & V_180 ) &&
F_136 ( V_228 , F_144 ( V_139 ) ) )
break;
}
if ( F_86 ( V_139 ) ) {
F_94 ( V_139 , V_342 ) ;
if ( F_166 ( V_340 , V_339 , V_338 ,
V_139 , V_303 ) )
F_94 ( V_139 , V_343 ) ;
else
F_94 ( V_139 , V_344 ) ;
}
F_131 () ;
F_225 ( V_338 , V_340 ) ;
V_341:
V_338 -> V_309 = 0 ;
F_226 ( & V_338 -> V_227 ) ;
return 0 ;
}
static void F_227 ( void * V_337 )
{
F_228 ( V_345 ) ;
}
static inline void F_229 ( struct V_346 * V_347 )
{
V_347 -> V_348 = F_227 ;
V_347 -> V_349 = NULL ;
V_347 -> V_113 = 0 ;
V_347 -> V_350 = 0 ;
}
int F_230 ( void )
{
return F_81 ( & V_351 . V_352 ) ;
}
static inline struct V_138 * F_231 ( int V_134 , int V_353 )
{
struct V_138 * V_139 ;
F_143 (cpu, sd)
if ( V_139 && ( V_139 -> V_113 & V_353 ) )
break;
return V_139 ;
}
static inline int F_232 ( struct V_154 * V_354 )
{
F_233 ( V_351 . V_355 , V_351 . V_356 ,
F_135 ( V_354 ) ) ;
if ( F_216 ( V_351 . V_355 ) )
return 0 ;
if ( F_234 ( V_351 . V_355 , F_135 ( V_354 ) ) )
return 0 ;
return 1 ;
}
static int F_235 ( int V_134 )
{
struct V_138 * V_139 ;
struct V_154 * V_354 ;
int V_357 = V_358 ;
if ( ! ( V_359 || V_306 ) )
goto V_360;
if ( F_236 ( V_351 . V_356 ) < 2 )
goto V_360;
F_129 () ;
F_237 (cpu, sd, SD_POWERSAVINGS_BALANCE) {
V_354 = V_139 -> V_158 ;
do {
if ( F_232 ( V_354 ) ) {
V_357 = F_182 ( V_351 . V_355 ) ;
goto V_185;
}
V_354 = V_354 -> V_38 ;
} while ( V_354 != V_139 -> V_158 );
}
V_185:
F_131 () ;
V_360:
return V_357 ;
}
static inline int F_235 ( int V_361 )
{
return V_358 ;
}
static void F_238 ( int V_134 )
{
int V_362 ;
V_351 . V_328 ++ ;
V_362 = F_230 () ;
if ( V_362 >= V_358 ) {
V_362 = F_182 ( V_351 . V_356 ) ;
if ( V_362 >= V_358 )
return;
}
if ( ! F_23 ( V_362 ) -> V_363 ) {
struct V_346 * V_364 ;
F_23 ( V_362 ) -> V_363 = 1 ;
V_364 = & F_239 ( V_365 , V_134 ) ;
F_240 ( V_362 , V_364 , 0 ) ;
}
return;
}
void F_241 ( int V_366 )
{
int V_134 = F_125 () ;
if ( V_366 ) {
if ( ! F_242 ( V_134 ) ) {
if ( F_81 ( & V_351 . V_352 ) != V_134 )
return;
if ( F_243 ( & V_351 . V_352 , V_134 ,
V_358 ) != V_134 )
F_244 () ;
return;
}
F_245 ( V_134 , V_351 . V_356 ) ;
if ( F_81 ( & V_351 . V_367 ) == V_134 )
F_243 ( & V_351 . V_367 , V_134 , V_358 ) ;
if ( F_81 ( & V_351 . V_368 ) == V_134 )
F_243 ( & V_351 . V_368 , V_134 , V_358 ) ;
if ( F_81 ( & V_351 . V_352 ) >= V_358 ) {
int V_369 ;
if ( F_243 ( & V_351 . V_352 , V_358 ,
V_134 ) != V_358 )
return;
V_369 = F_235 ( V_134 ) ;
if ( V_369 < V_358 && V_369 != V_134 ) {
F_246 ( & V_351 . V_352 , V_358 ) ;
F_214 ( V_369 ) ;
return;
}
return;
}
} else {
if ( ! F_136 ( V_134 , V_351 . V_356 ) )
return;
F_215 ( V_134 , V_351 . V_356 ) ;
if ( F_81 ( & V_351 . V_352 ) == V_134 )
if ( F_243 ( & V_351 . V_352 , V_134 ,
V_358 ) != V_134 )
F_244 () ;
}
return;
}
static void F_247 ( void )
{
V_370 = V_330 * F_248 () / 10 ;
}
static void F_249 ( int V_134 , enum V_205 V_200 )
{
int V_268 = 1 ;
struct V_1 * V_1 = F_23 ( V_134 ) ;
unsigned long V_334 ;
struct V_138 * V_139 ;
unsigned long V_328 = V_329 + 60 * V_330 ;
int V_371 = 0 ;
int V_372 ;
F_174 ( V_134 ) ;
F_129 () ;
F_143 (cpu, sd) {
if ( ! ( V_139 -> V_113 & V_180 ) )
continue;
V_334 = V_139 -> V_322 ;
if ( V_200 != V_303 )
V_334 *= V_139 -> V_373 ;
V_334 = F_220 ( V_334 ) ;
V_334 = F_250 ( V_334 , 1UL , V_370 ) ;
V_372 = V_139 -> V_113 & V_374 ;
if ( V_372 ) {
if ( ! F_251 ( & V_375 ) )
goto V_224;
}
if ( F_252 ( V_329 , V_139 -> V_336 + V_334 ) ) {
if ( F_207 ( V_134 , V_1 , V_139 , V_200 , & V_268 ) ) {
V_200 = V_236 ;
}
V_139 -> V_336 = V_329 ;
}
if ( V_372 )
F_253 ( & V_375 ) ;
V_224:
if ( F_221 ( V_328 , V_139 -> V_336 + V_334 ) ) {
V_328 = V_139 -> V_336 + V_334 ;
V_371 = 1 ;
}
if ( ! V_268 )
break;
}
F_131 () ;
if ( F_86 ( V_371 ) )
V_1 -> V_328 = V_328 ;
}
static void F_254 ( int V_9 , enum V_205 V_200 )
{
struct V_1 * V_204 = F_23 ( V_9 ) ;
struct V_1 * V_1 ;
int V_272 ;
if ( V_200 != V_303 || ! V_204 -> V_363 )
return;
F_137 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_272 == V_9 )
continue;
if ( F_255 () ) {
V_204 -> V_363 = 0 ;
break;
}
F_223 ( & V_204 -> V_227 ) ;
F_156 ( V_204 ) ;
F_256 ( V_204 ) ;
F_226 ( & V_204 -> V_227 ) ;
F_249 ( V_272 , V_303 ) ;
V_1 = F_23 ( V_272 ) ;
if ( F_221 ( V_204 -> V_328 , V_1 -> V_328 ) )
V_204 -> V_328 = V_1 -> V_328 ;
}
V_351 . V_328 = V_204 -> V_328 ;
V_204 -> V_363 = 0 ;
}
static inline int F_257 ( struct V_1 * V_1 , int V_134 )
{
unsigned long V_74 = V_329 ;
int V_46 ;
int V_367 , V_368 ;
if ( F_258 ( V_74 , V_351 . V_328 ) )
return 0 ;
if ( V_1 -> V_376 )
return 0 ;
V_367 = F_81 ( & V_351 . V_367 ) ;
V_368 = F_81 ( & V_351 . V_368 ) ;
if ( V_367 < V_358 && V_367 != V_134 &&
V_368 < V_358 && V_368 != V_134 )
return 0 ;
V_46 = F_243 ( & V_351 . V_367 , V_358 , V_134 ) ;
if ( V_46 == V_358 || V_46 == V_134 ) {
F_243 ( & V_351 . V_368 , V_134 , V_358 ) ;
if ( V_1 -> V_57 > 1 )
return 1 ;
} else {
V_46 = F_243 ( & V_351 . V_368 , V_358 , V_134 ) ;
if ( V_46 == V_358 || V_46 == V_134 ) {
if ( V_1 -> V_57 )
return 1 ;
}
}
return 0 ;
}
static void F_254 ( int V_9 , enum V_205 V_200 ) { }
static void F_259 ( struct V_377 * V_378 )
{
int V_9 = F_125 () ;
struct V_1 * V_204 = F_23 ( V_9 ) ;
enum V_205 V_200 = V_204 -> V_376 ?
V_303 : V_236 ;
F_249 ( V_9 , V_200 ) ;
F_254 ( V_9 , V_200 ) ;
}
static inline int F_260 ( int V_134 )
{
return ! F_261 ( F_23 ( V_134 ) -> V_139 ) ;
}
static inline void F_262 ( struct V_1 * V_1 , int V_134 )
{
if ( F_252 ( V_329 , V_1 -> V_328 ) &&
F_86 ( ! F_260 ( V_134 ) ) )
F_263 ( V_345 ) ;
#ifdef F_264
else if ( F_257 ( V_1 , V_134 ) && F_86 ( ! F_260 ( V_134 ) ) )
F_238 ( V_134 ) ;
#endif
}
static void F_265 ( struct V_1 * V_1 )
{
F_266 () ;
}
static void F_267 ( struct V_1 * V_1 )
{
F_266 () ;
}
static inline void F_218 ( int V_134 , struct V_1 * V_1 )
{
}
static void F_268 ( struct V_1 * V_1 , struct V_3 * V_24 , int V_127 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_24 -> V_5 ;
F_20 (se) {
V_2 = F_8 ( V_5 ) ;
F_109 ( V_2 , V_5 , V_127 ) ;
}
}
static void F_269 ( struct V_3 * V_6 )
{
struct V_2 * V_2 = F_7 ( V_147 ) ;
struct V_4 * V_5 = & V_6 -> V_5 , * V_24 = V_2 -> V_24 ;
int V_9 = F_125 () ;
struct V_1 * V_1 = V_204 () ;
unsigned long V_113 ;
F_172 ( & V_1 -> V_227 , V_113 ) ;
F_156 ( V_1 ) ;
if ( F_47 ( F_126 ( V_6 ) != V_9 ) ) {
F_129 () ;
F_270 ( V_6 , V_9 ) ;
F_131 () ;
}
F_57 ( V_2 ) ;
if ( V_24 )
V_5 -> V_20 = V_24 -> V_20 ;
F_95 ( V_2 , V_5 , 1 ) ;
if ( V_379 && V_24 && F_25 ( V_24 , V_5 ) ) {
F_271 ( V_24 -> V_20 , V_5 -> V_20 ) ;
F_104 ( V_1 -> V_24 ) ;
}
V_5 -> V_20 -= V_2 -> V_19 ;
F_173 ( & V_1 -> V_227 , V_113 ) ;
}
static void
F_272 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_380 )
{
if ( ! V_6 -> V_5 . V_61 )
return;
if ( V_1 -> V_24 == V_6 ) {
if ( V_6 -> V_381 > V_380 )
F_104 ( V_1 -> V_24 ) ;
} else
F_162 ( V_1 , V_6 , 0 ) ;
}
static void F_273 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( ! V_5 -> V_61 && V_6 -> V_118 != V_382 ) {
F_95 ( V_2 , V_5 , 0 ) ;
V_5 -> V_20 -= V_2 -> V_19 ;
}
}
static void F_274 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
if ( ! V_6 -> V_5 . V_61 )
return;
if ( V_1 -> V_24 == V_6 )
F_104 ( V_1 -> V_24 ) ;
else
F_162 ( V_1 , V_6 , 0 ) ;
}
static void F_275 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = & V_1 -> V_24 -> V_5 ;
F_20 (se)
F_105 ( F_8 ( V_5 ) , V_5 ) ;
}
static void F_276 ( struct V_3 * V_6 , int V_61 )
{
if ( ! V_61 )
V_6 -> V_5 . V_20 -= F_8 ( & V_6 -> V_5 ) -> V_19 ;
F_277 ( V_6 , F_126 ( V_6 ) ) ;
if ( ! V_61 )
V_6 -> V_5 . V_20 += F_8 ( & V_6 -> V_5 ) -> V_19 ;
}
static unsigned int F_278 ( struct V_1 * V_1 , struct V_3 * V_383 )
{
struct V_4 * V_5 = & V_383 -> V_5 ;
unsigned int V_384 = 0 ;
if ( V_1 -> V_18 . V_54 . V_55 )
V_384 = F_279 ( F_50 ( & V_1 -> V_18 , V_5 ) ) ;
return V_384 ;
}
static void F_280 ( struct V_385 * V_386 , int V_134 )
{
struct V_2 * V_2 ;
F_129 () ;
F_167 (cpu_rq(cpu), cfs_rq)
F_281 ( V_386 , V_134 , V_2 ) ;
F_131 () ;
}
