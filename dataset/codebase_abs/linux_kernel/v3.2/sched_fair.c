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
static inline void F_10 ( struct V_2 * V_2 )
{
if ( ! V_2 -> V_9 ) {
if ( V_2 -> V_10 -> V_11 &&
V_2 -> V_10 -> V_11 -> V_2 [ F_11 ( F_1 ( V_2 ) ) ] -> V_9 ) {
F_12 ( & V_2 -> V_12 ,
& F_1 ( V_2 ) -> V_12 ) ;
} else {
F_13 ( & V_2 -> V_12 ,
& F_1 ( V_2 ) -> V_12 ) ;
}
V_2 -> V_9 = 1 ;
}
}
static inline void F_14 ( struct V_2 * V_2 )
{
if ( V_2 -> V_9 ) {
F_15 ( & V_2 -> V_12 ) ;
V_2 -> V_9 = 0 ;
}
}
static inline int
F_16 ( struct V_4 * V_5 , struct V_4 * V_13 )
{
if ( V_5 -> V_2 == V_13 -> V_2 )
return 1 ;
return 0 ;
}
static inline struct V_4 * F_17 ( struct V_4 * V_5 )
{
return V_5 -> V_11 ;
}
static inline int F_18 ( struct V_4 * V_5 )
{
int V_14 = 0 ;
F_19 (se)
V_14 ++ ;
return V_14 ;
}
static void
F_20 ( struct V_4 * * V_5 , struct V_4 * * V_13 )
{
int V_15 , V_16 ;
V_15 = F_18 ( * V_5 ) ;
V_16 = F_18 ( * V_13 ) ;
while ( V_15 > V_16 ) {
V_15 -- ;
* V_5 = F_17 ( * V_5 ) ;
}
while ( V_16 > V_15 ) {
V_16 -- ;
* V_13 = F_17 ( * V_13 ) ;
}
while ( ! F_16 ( * V_5 , * V_13 ) ) {
* V_5 = F_17 ( * V_5 ) ;
* V_13 = F_17 ( * V_13 ) ;
}
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , struct V_3 , V_5 ) ;
}
static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_6 ( V_2 , struct V_1 , V_17 ) ;
}
static inline struct V_2 * F_7 ( struct V_3 * V_6 )
{
return & F_21 ( V_6 ) -> V_17 ;
}
static inline struct V_2 * F_8 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_2 ( V_5 ) ;
struct V_1 * V_1 = F_21 ( V_6 ) ;
return & V_1 -> V_17 ;
}
static inline struct V_2 * F_9 ( struct V_4 * V_7 )
{
return NULL ;
}
static inline void F_10 ( struct V_2 * V_2 )
{
}
static inline void F_14 ( struct V_2 * V_2 )
{
}
static inline int
F_16 ( struct V_4 * V_5 , struct V_4 * V_13 )
{
return 1 ;
}
static inline struct V_4 * F_17 ( struct V_4 * V_5 )
{
return NULL ;
}
static inline void
F_20 ( struct V_4 * * V_5 , struct V_4 * * V_13 )
{
}
static inline T_1 F_22 ( T_1 V_18 , T_1 V_19 )
{
T_2 V_20 = ( T_2 ) ( V_19 - V_18 ) ;
if ( V_20 > 0 )
V_18 = V_19 ;
return V_18 ;
}
static inline T_1 V_18 ( T_1 V_18 , T_1 V_19 )
{
T_2 V_20 = ( T_2 ) ( V_19 - V_18 ) ;
if ( V_20 < 0 )
V_18 = V_19 ;
return V_18 ;
}
static inline int F_23 ( struct V_4 * V_21 ,
struct V_4 * V_22 )
{
return ( T_2 ) ( V_21 -> V_19 - V_22 -> V_19 ) < 0 ;
}
static void F_24 ( struct V_2 * V_2 )
{
T_1 V_19 = V_2 -> V_18 ;
if ( V_2 -> V_23 )
V_19 = V_2 -> V_23 -> V_19 ;
if ( V_2 -> V_24 ) {
struct V_4 * V_5 = F_25 ( V_2 -> V_24 ,
struct V_4 ,
V_25 ) ;
if ( ! V_2 -> V_23 )
V_19 = V_5 -> V_19 ;
else
V_19 = V_18 ( V_19 , V_5 -> V_19 ) ;
}
V_2 -> V_18 = F_22 ( V_2 -> V_18 , V_19 ) ;
#ifndef F_26
F_27 () ;
V_2 -> V_26 = V_2 -> V_18 ;
#endif
}
static void F_28 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_27 * * V_28 = & V_2 -> V_29 . V_27 ;
struct V_27 * V_11 = NULL ;
struct V_4 * V_30 ;
int V_31 = 1 ;
while ( * V_28 ) {
V_11 = * V_28 ;
V_30 = F_25 ( V_11 , struct V_4 , V_25 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
V_28 = & V_11 -> V_32 ;
} else {
V_28 = & V_11 -> V_33 ;
V_31 = 0 ;
}
}
if ( V_31 )
V_2 -> V_24 = & V_5 -> V_25 ;
F_29 ( & V_5 -> V_25 , V_11 , V_28 ) ;
F_30 ( & V_5 -> V_25 , & V_2 -> V_29 ) ;
}
static void F_31 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_2 -> V_24 == & V_5 -> V_25 ) {
struct V_27 * V_34 ;
V_34 = F_32 ( & V_5 -> V_25 ) ;
V_2 -> V_24 = V_34 ;
}
F_33 ( & V_5 -> V_25 , & V_2 -> V_29 ) ;
}
static struct V_4 * F_34 ( struct V_2 * V_2 )
{
struct V_27 * V_35 = V_2 -> V_24 ;
if ( ! V_35 )
return NULL ;
return F_25 ( V_35 , struct V_4 , V_25 ) ;
}
static struct V_4 * F_35 ( struct V_4 * V_5 )
{
struct V_27 * V_36 = F_32 ( & V_5 -> V_25 ) ;
if ( ! V_36 )
return NULL ;
return F_25 ( V_36 , struct V_4 , V_25 ) ;
}
static struct V_4 * F_36 ( struct V_2 * V_2 )
{
struct V_27 * V_37 = F_37 ( & V_2 -> V_29 ) ;
if ( ! V_37 )
return NULL ;
return F_25 ( V_37 , struct V_4 , V_25 ) ;
}
int F_38 ( struct V_38 * V_39 , int V_40 ,
void T_3 * V_41 , T_4 * V_42 ,
T_5 * V_43 )
{
int V_44 = F_39 ( V_39 , V_40 , V_41 , V_42 , V_43 ) ;
int V_45 = F_40 () ;
if ( V_44 || ! V_40 )
return V_44 ;
V_46 = F_41 ( V_47 ,
V_48 ) ;
#define F_42 ( T_6 ) \
(normalized_sysctl_##name = sysctl_##name / (factor))
F_42 ( V_49 ) ;
F_42 ( V_50 ) ;
F_42 ( V_51 ) ;
#undef F_42
return 0 ;
}
static inline unsigned long
F_43 ( unsigned long V_20 , struct V_4 * V_5 )
{
if ( F_44 ( V_5 -> V_52 . V_53 != V_54 ) )
V_20 = F_45 ( V_20 , V_54 , & V_5 -> V_52 ) ;
return V_20 ;
}
static T_1 F_46 ( unsigned long V_55 )
{
T_1 V_56 = V_47 ;
unsigned long V_57 = V_46 ;
if ( F_44 ( V_55 > V_57 ) ) {
V_56 = V_48 ;
V_56 *= V_55 ;
}
return V_56 ;
}
static T_1 F_47 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
T_1 V_58 = F_46 ( V_2 -> V_55 + ! V_5 -> V_59 ) ;
F_19 (se) {
struct V_60 * V_52 ;
struct V_60 V_61 ;
V_2 = F_8 ( V_5 ) ;
V_52 = & V_2 -> V_52 ;
if ( F_44 ( ! V_5 -> V_59 ) ) {
V_61 = V_2 -> V_52 ;
F_48 ( & V_61 , V_5 -> V_52 . V_53 ) ;
V_52 = & V_61 ;
}
V_58 = F_45 ( V_58 , V_5 -> V_52 . V_53 , V_52 ) ;
}
return V_58 ;
}
static T_1 F_49 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
return F_43 ( F_47 ( V_2 , V_5 ) , V_5 ) ;
}
static inline void
F_50 ( struct V_2 * V_2 , struct V_4 * V_23 ,
unsigned long V_62 )
{
unsigned long V_63 ;
F_51 ( V_23 -> V_64 . V_65 ,
F_52 ( ( T_1 ) V_62 , V_23 -> V_64 . V_65 ) ) ;
V_23 -> V_66 += V_62 ;
F_53 ( V_2 , V_67 , V_62 ) ;
V_63 = F_43 ( V_62 , V_23 ) ;
V_23 -> V_19 += V_63 ;
F_24 ( V_2 ) ;
#if V_68 V_69 && V_68 V_70
V_2 -> V_71 += V_62 ;
#endif
}
static void F_54 ( struct V_2 * V_2 )
{
struct V_4 * V_23 = V_2 -> V_23 ;
T_1 V_72 = F_1 ( V_2 ) -> V_73 ;
unsigned long V_62 ;
if ( F_44 ( ! V_23 ) )
return;
V_62 = ( unsigned long ) ( V_72 - V_23 -> V_74 ) ;
if ( ! V_62 )
return;
F_50 ( V_2 , V_23 , V_62 ) ;
V_23 -> V_74 = V_72 ;
if ( F_5 ( V_23 ) ) {
struct V_3 * V_75 = F_2 ( V_23 ) ;
F_55 ( V_75 , V_62 , V_23 -> V_19 ) ;
F_56 ( V_75 , V_62 ) ;
F_57 ( V_75 , V_62 ) ;
}
F_58 ( V_2 , V_62 ) ;
}
static inline void
F_59 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_51 ( V_5 -> V_64 . V_76 , F_1 ( V_2 ) -> clock ) ;
}
static void F_60 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_23 )
F_59 ( V_2 , V_5 ) ;
}
static void
F_61 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_51 ( V_5 -> V_64 . V_77 , F_52 ( V_5 -> V_64 . V_77 ,
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ) ;
F_51 ( V_5 -> V_64 . V_78 , V_5 -> V_64 . V_78 + 1 ) ;
F_51 ( V_5 -> V_64 . V_79 , V_5 -> V_64 . V_79 +
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ;
#ifdef F_62
if ( F_5 ( V_5 ) ) {
F_63 ( F_2 ( V_5 ) ,
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ;
}
#endif
F_51 ( V_5 -> V_64 . V_76 , 0 ) ;
}
static inline void
F_64 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_23 )
F_61 ( V_2 , V_5 ) ;
}
static inline void
F_65 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_74 = F_1 ( V_2 ) -> V_73 ;
}
static void
F_66 ( struct V_2 * V_2 , unsigned long V_53 )
{
V_2 -> V_80 += V_53 ;
}
static inline void
F_66 ( struct V_2 * V_2 , unsigned long V_53 )
{
}
static void
F_67 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_48 ( & V_2 -> V_52 , V_5 -> V_52 . V_53 ) ;
if ( ! F_17 ( V_5 ) )
F_68 ( F_1 ( V_2 ) , V_5 -> V_52 . V_53 ) ;
if ( F_5 ( V_5 ) ) {
F_66 ( V_2 , V_5 -> V_52 . V_53 ) ;
F_69 ( & V_5 -> V_81 , & V_2 -> V_82 ) ;
}
V_2 -> V_55 ++ ;
}
static void
F_70 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_71 ( & V_2 -> V_52 , V_5 -> V_52 . V_53 ) ;
if ( ! F_17 ( V_5 ) )
F_72 ( F_1 ( V_2 ) , V_5 -> V_52 . V_53 ) ;
if ( F_5 ( V_5 ) ) {
F_66 ( V_2 , - V_5 -> V_52 . V_53 ) ;
F_73 ( & V_5 -> V_81 ) ;
}
V_2 -> V_55 -- ;
}
static void F_74 ( struct V_2 * V_2 ,
int V_83 )
{
struct V_84 * V_10 = V_2 -> V_10 ;
long V_85 ;
V_85 = F_75 ( V_2 -> V_85 , V_2 -> V_86 + 1 ) ;
V_85 -= V_2 -> V_87 ;
if ( V_83 || abs ( V_85 ) > V_2 -> V_87 / 8 ) {
F_76 ( V_85 , & V_10 -> V_60 ) ;
V_2 -> V_87 += V_85 ;
}
}
static void F_77 ( struct V_2 * V_2 , int V_83 )
{
T_1 V_56 = V_88 ;
T_1 V_72 , V_20 ;
unsigned long V_52 = V_2 -> V_52 . V_53 ;
if ( V_2 -> V_10 == & V_89 || F_78 ( V_2 ) )
return;
V_72 = F_1 ( V_2 ) -> V_73 ;
V_20 = V_72 - V_2 -> V_90 ;
if ( V_2 -> V_90 > V_2 -> V_91 &&
V_72 - V_2 -> V_91 > 4 * V_56 ) {
V_2 -> V_86 = 0 ;
V_2 -> V_85 = 0 ;
V_20 = V_56 - 1 ;
}
V_2 -> V_90 = V_72 ;
V_2 -> V_71 = 0 ;
V_2 -> V_86 += V_20 ;
if ( V_52 ) {
V_2 -> V_91 = V_72 ;
V_2 -> V_85 += V_20 * V_52 ;
}
if ( V_83 || V_2 -> V_86 > V_56
|| ! V_2 -> V_86 )
F_74 ( V_2 , V_83 ) ;
while ( V_2 -> V_86 > V_56 ) {
asm("" : "+rm" (cfs_rq->load_period));
V_2 -> V_86 /= 2 ;
V_2 -> V_85 /= 2 ;
}
if ( ! V_2 -> V_23 && ! V_2 -> V_55 && ! V_2 -> V_85 )
F_14 ( V_2 ) ;
}
static inline long F_79 ( struct V_84 * V_10 , struct V_2 * V_2 )
{
long V_92 ;
V_92 = F_80 ( & V_10 -> V_60 ) ;
V_92 -= V_2 -> V_87 ;
V_92 += V_2 -> V_52 . V_53 ;
return V_92 ;
}
static long F_81 ( struct V_2 * V_2 , struct V_84 * V_10 )
{
long V_92 , V_52 , V_93 ;
V_92 = F_79 ( V_10 , V_2 ) ;
V_52 = V_2 -> V_52 . V_53 ;
V_93 = ( V_10 -> V_93 * V_52 ) ;
if ( V_92 )
V_93 /= V_92 ;
if ( V_93 < V_94 )
V_93 = V_94 ;
if ( V_93 > V_10 -> V_93 )
V_93 = V_10 -> V_93 ;
return V_93 ;
}
static void F_82 ( struct V_2 * V_2 )
{
if ( V_2 -> V_71 > V_88 ) {
F_77 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
}
static void F_77 ( struct V_2 * V_2 , int V_83 )
{
}
static inline long F_81 ( struct V_2 * V_2 , struct V_84 * V_10 )
{
return V_10 -> V_93 ;
}
static inline void F_82 ( struct V_2 * V_2 )
{
}
static void F_84 ( struct V_2 * V_2 , struct V_4 * V_5 ,
unsigned long V_53 )
{
if ( V_5 -> V_59 ) {
if ( V_2 -> V_23 == V_5 )
F_54 ( V_2 ) ;
F_70 ( V_2 , V_5 ) ;
}
F_85 ( & V_5 -> V_52 , V_53 ) ;
if ( V_5 -> V_59 )
F_67 ( V_2 , V_5 ) ;
}
static void F_83 ( struct V_2 * V_2 )
{
struct V_84 * V_10 ;
struct V_4 * V_5 ;
long V_93 ;
V_10 = V_2 -> V_10 ;
V_5 = V_10 -> V_5 [ F_11 ( F_1 ( V_2 ) ) ] ;
if ( ! V_5 || F_78 ( V_2 ) )
return;
#ifndef V_69
if ( F_86 ( V_5 -> V_52 . V_53 == V_10 -> V_93 ) )
return;
#endif
V_93 = F_81 ( V_2 , V_10 ) ;
F_84 ( F_8 ( V_5 ) , V_5 , V_93 ) ;
}
static void F_77 ( struct V_2 * V_2 , int V_83 )
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
#ifdef F_62
struct V_3 * V_95 = NULL ;
if ( F_5 ( V_5 ) )
V_95 = F_2 ( V_5 ) ;
if ( V_5 -> V_64 . V_96 ) {
T_1 V_20 = F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_96 ;
if ( ( T_2 ) V_20 < 0 )
V_20 = 0 ;
if ( F_44 ( V_20 > V_5 -> V_64 . V_97 ) )
V_5 -> V_64 . V_97 = V_20 ;
V_5 -> V_64 . V_96 = 0 ;
V_5 -> V_64 . V_98 += V_20 ;
if ( V_95 ) {
F_88 ( V_95 , V_20 >> 10 , 1 ) ;
F_89 ( V_95 , V_20 ) ;
}
}
if ( V_5 -> V_64 . V_99 ) {
T_1 V_20 = F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_99 ;
if ( ( T_2 ) V_20 < 0 )
V_20 = 0 ;
if ( F_44 ( V_20 > V_5 -> V_64 . V_100 ) )
V_5 -> V_64 . V_100 = V_20 ;
V_5 -> V_64 . V_99 = 0 ;
V_5 -> V_64 . V_98 += V_20 ;
if ( V_95 ) {
if ( V_95 -> V_101 ) {
V_5 -> V_64 . V_102 += V_20 ;
V_5 -> V_64 . V_103 ++ ;
F_90 ( V_95 , V_20 ) ;
}
if ( F_44 ( V_104 == V_105 ) ) {
F_91 ( V_105 ,
( void * ) F_92 ( V_95 ) ,
V_20 >> 20 ) ;
}
F_88 ( V_95 , V_20 >> 10 , 0 ) ;
}
}
#endif
}
static void F_93 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
#ifdef F_3
T_2 V_106 = V_5 -> V_19 - V_2 -> V_18 ;
if ( V_106 < 0 )
V_106 = - V_106 ;
if ( V_106 > 3 * V_47 )
F_94 ( V_2 , V_107 ) ;
#endif
}
static void
F_95 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_108 )
{
T_1 V_19 = V_2 -> V_18 ;
if ( V_108 && F_96 ( V_109 ) )
V_19 += F_49 ( V_2 , V_5 ) ;
if ( ! V_108 ) {
unsigned long V_110 = V_47 ;
if ( F_96 ( V_111 ) )
V_110 >>= 1 ;
V_19 -= V_110 ;
}
V_19 = F_22 ( V_5 -> V_19 , V_19 ) ;
V_5 -> V_19 = V_19 ;
}
static void
F_97 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_112 )
{
if ( ! ( V_112 & V_113 ) || ( V_112 & V_114 ) )
V_5 -> V_19 += V_2 -> V_18 ;
F_54 ( V_2 ) ;
F_77 ( V_2 , 0 ) ;
F_67 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
if ( V_112 & V_113 ) {
F_95 ( V_2 , V_5 , 0 ) ;
F_87 ( V_2 , V_5 ) ;
}
F_60 ( V_2 , V_5 ) ;
F_93 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_23 )
F_28 ( V_2 , V_5 ) ;
V_5 -> V_59 = 1 ;
if ( V_2 -> V_55 == 1 ) {
F_10 ( V_2 ) ;
F_98 ( V_2 ) ;
}
}
static void F_99 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_37 == V_5 )
V_2 -> V_37 = NULL ;
else
break;
}
}
static void F_100 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_36 == V_5 )
V_2 -> V_36 = NULL ;
else
break;
}
}
static void F_101 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_115 == V_5 )
V_2 -> V_115 = NULL ;
else
break;
}
}
static void F_102 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_2 -> V_37 == V_5 )
F_99 ( V_5 ) ;
if ( V_2 -> V_36 == V_5 )
F_100 ( V_5 ) ;
if ( V_2 -> V_115 == V_5 )
F_101 ( V_5 ) ;
}
static void
F_103 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_112 )
{
F_54 ( V_2 ) ;
F_64 ( V_2 , V_5 ) ;
if ( V_112 & V_116 ) {
#ifdef F_62
if ( F_5 ( V_5 ) ) {
struct V_3 * V_95 = F_2 ( V_5 ) ;
if ( V_95 -> V_117 & V_118 )
V_5 -> V_64 . V_96 = F_1 ( V_2 ) -> clock ;
if ( V_95 -> V_117 & V_119 )
V_5 -> V_64 . V_99 = F_1 ( V_2 ) -> clock ;
}
#endif
}
F_102 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_23 )
F_31 ( V_2 , V_5 ) ;
V_5 -> V_59 = 0 ;
F_77 ( V_2 , 0 ) ;
F_70 ( V_2 , V_5 ) ;
if ( ! ( V_112 & V_116 ) )
V_5 -> V_19 -= V_2 -> V_18 ;
F_104 ( V_2 ) ;
F_24 ( V_2 ) ;
F_83 ( V_2 ) ;
}
static void
F_105 ( struct V_2 * V_2 , struct V_4 * V_23 )
{
unsigned long V_120 , V_62 ;
struct V_4 * V_5 ;
T_2 V_20 ;
V_120 = F_47 ( V_2 , V_23 ) ;
V_62 = V_23 -> V_66 - V_23 -> V_121 ;
if ( V_62 > V_120 ) {
F_106 ( F_1 ( V_2 ) -> V_23 ) ;
F_102 ( V_2 , V_23 ) ;
return;
}
if ( V_62 < V_48 )
return;
V_5 = F_34 ( V_2 ) ;
V_20 = V_23 -> V_19 - V_5 -> V_19 ;
if ( V_20 < 0 )
return;
if ( V_20 > V_120 )
F_106 ( F_1 ( V_2 ) -> V_23 ) ;
}
static void
F_107 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_59 ) {
F_61 ( V_2 , V_5 ) ;
F_31 ( V_2 , V_5 ) ;
}
F_65 ( V_2 , V_5 ) ;
V_2 -> V_23 = V_5 ;
#ifdef F_62
if ( F_1 ( V_2 ) -> V_52 . V_53 >= 2 * V_5 -> V_52 . V_53 ) {
V_5 -> V_64 . V_122 = F_52 ( V_5 -> V_64 . V_122 ,
V_5 -> V_66 - V_5 -> V_121 ) ;
}
#endif
V_5 -> V_121 = V_5 -> V_66 ;
}
static struct V_4 * F_108 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_34 ( V_2 ) ;
struct V_4 * V_35 = V_5 ;
if ( V_2 -> V_115 == V_5 ) {
struct V_4 * V_123 = F_35 ( V_5 ) ;
if ( V_123 && F_109 ( V_123 , V_35 ) < 1 )
V_5 = V_123 ;
}
if ( V_2 -> V_37 && F_109 ( V_2 -> V_37 , V_35 ) < 1 )
V_5 = V_2 -> V_37 ;
if ( V_2 -> V_36 && F_109 ( V_2 -> V_36 , V_35 ) < 1 )
V_5 = V_2 -> V_36 ;
F_102 ( V_2 , V_5 ) ;
return V_5 ;
}
static void F_110 ( struct V_2 * V_2 , struct V_4 * V_124 )
{
if ( V_124 -> V_59 )
F_54 ( V_2 ) ;
F_111 ( V_2 ) ;
F_93 ( V_2 , V_124 ) ;
if ( V_124 -> V_59 ) {
F_59 ( V_2 , V_124 ) ;
F_28 ( V_2 , V_124 ) ;
}
V_2 -> V_23 = NULL ;
}
static void
F_112 ( struct V_2 * V_2 , struct V_4 * V_23 , int V_125 )
{
F_54 ( V_2 ) ;
F_82 ( V_2 ) ;
#ifdef F_113
if ( V_125 ) {
F_106 ( F_1 ( V_2 ) -> V_23 ) ;
return;
}
if ( ! F_96 ( V_126 ) &&
F_114 ( & F_1 ( V_2 ) -> V_127 ) )
return;
#endif
if ( V_2 -> V_55 > 1 )
F_105 ( V_2 , V_23 ) ;
}
static inline T_1 F_115 ( void )
{
return 100000000ULL ;
}
static inline T_1 F_116 ( void )
{
return ( T_1 ) V_128 * V_129 ;
}
static void F_117 ( struct V_130 * V_131 )
{
T_1 V_72 ;
if ( V_131 -> V_132 == V_133 )
return;
V_72 = F_118 ( F_119 () ) ;
V_131 -> V_134 = V_131 -> V_132 ;
V_131 -> V_135 = V_72 + F_120 ( V_131 -> V_56 ) ;
}
static int F_121 ( struct V_2 * V_2 )
{
struct V_84 * V_10 = V_2 -> V_10 ;
struct V_130 * V_131 = F_122 ( V_10 ) ;
T_1 V_136 = 0 , V_137 , V_138 ;
V_137 = F_116 () - V_2 -> V_139 ;
F_123 ( & V_131 -> V_140 ) ;
if ( V_131 -> V_132 == V_133 )
V_136 = V_137 ;
else {
if ( ! V_131 -> V_141 ) {
F_117 ( V_131 ) ;
F_124 ( V_131 ) ;
}
if ( V_131 -> V_134 > 0 ) {
V_136 = F_125 ( V_131 -> V_134 , V_137 ) ;
V_131 -> V_134 -= V_136 ;
V_131 -> V_142 = 0 ;
}
}
V_138 = V_131 -> V_135 ;
F_126 ( & V_131 -> V_140 ) ;
V_2 -> V_139 += V_136 ;
if ( ( T_2 ) ( V_138 - V_2 -> V_135 ) > 0 )
V_2 -> V_135 = V_138 ;
return V_2 -> V_139 > 0 ;
}
static void F_127 ( struct V_2 * V_2 )
{
struct V_130 * V_131 = F_122 ( V_2 -> V_10 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( F_86 ( ( T_2 ) ( V_1 -> clock - V_2 -> V_135 ) < 0 ) )
return;
if ( V_2 -> V_139 < 0 )
return;
if ( ( T_2 ) ( V_2 -> V_135 - V_131 -> V_135 ) >= 0 ) {
V_2 -> V_135 += V_143 ;
} else {
V_2 -> V_139 = 0 ;
}
}
static void F_128 ( struct V_2 * V_2 ,
unsigned long V_62 )
{
V_2 -> V_139 -= V_62 ;
F_127 ( V_2 ) ;
if ( F_86 ( V_2 -> V_139 > 0 ) )
return;
if ( ! F_121 ( V_2 ) && F_86 ( V_2 -> V_23 ) )
F_106 ( F_1 ( V_2 ) -> V_23 ) ;
}
static T_7 void F_58 ( struct V_2 * V_2 ,
unsigned long V_62 )
{
if ( ! V_2 -> V_144 )
return;
F_128 ( V_2 , V_62 ) ;
}
static inline int F_129 ( struct V_2 * V_2 )
{
return V_2 -> V_145 ;
}
static inline int F_78 ( struct V_2 * V_2 )
{
return V_2 -> V_146 ;
}
static inline int F_130 ( struct V_84 * V_10 ,
int V_147 , int V_148 )
{
struct V_2 * V_149 , * V_150 ;
V_149 = V_10 -> V_2 [ V_147 ] ;
V_150 = V_10 -> V_2 [ V_148 ] ;
return F_78 ( V_149 ) ||
F_78 ( V_150 ) ;
}
static int F_131 ( struct V_84 * V_10 , void * V_151 )
{
struct V_1 * V_1 = V_151 ;
struct V_2 * V_2 = V_10 -> V_2 [ F_11 ( V_1 ) ] ;
V_2 -> V_146 -- ;
#ifdef V_69
if ( ! V_2 -> V_146 ) {
T_1 V_20 = V_1 -> V_73 - V_2 -> V_90 ;
V_2 -> V_90 += V_20 ;
V_2 -> V_91 += V_20 ;
F_83 ( V_2 ) ;
}
#endif
return 0 ;
}
static int F_132 ( struct V_84 * V_10 , void * V_151 )
{
struct V_1 * V_1 = V_151 ;
struct V_2 * V_2 = V_10 -> V_2 [ F_11 ( V_1 ) ] ;
if ( ! V_2 -> V_146 )
F_77 ( V_2 , 0 ) ;
V_2 -> V_146 ++ ;
return 0 ;
}
static void F_133 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_130 * V_131 = F_122 ( V_2 -> V_10 ) ;
struct V_4 * V_5 ;
long V_152 , V_153 = 1 ;
V_5 = V_2 -> V_10 -> V_5 [ F_11 ( F_1 ( V_2 ) ) ] ;
F_134 () ;
F_135 ( V_2 -> V_10 , F_132 , V_154 , ( void * ) V_1 ) ;
F_136 () ;
V_152 = V_2 -> V_155 ;
F_19 (se) {
struct V_2 * V_156 = F_8 ( V_5 ) ;
if ( ! V_5 -> V_59 )
break;
if ( V_153 )
F_103 ( V_156 , V_5 , V_116 ) ;
V_156 -> V_155 -= V_152 ;
if ( V_156 -> V_52 . V_53 )
V_153 = 0 ;
}
if ( ! V_5 )
V_1 -> V_55 -= V_152 ;
V_2 -> V_145 = 1 ;
V_2 -> V_157 = V_1 -> clock ;
F_123 ( & V_131 -> V_140 ) ;
F_13 ( & V_2 -> V_158 , & V_131 -> V_159 ) ;
F_126 ( & V_131 -> V_140 ) ;
}
static void F_137 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_130 * V_131 = F_122 ( V_2 -> V_10 ) ;
struct V_4 * V_5 ;
int V_160 = 1 ;
long V_152 ;
V_5 = V_2 -> V_10 -> V_5 [ F_11 ( F_1 ( V_2 ) ) ] ;
V_2 -> V_145 = 0 ;
F_123 ( & V_131 -> V_140 ) ;
V_131 -> V_161 += V_1 -> clock - V_2 -> V_157 ;
F_15 ( & V_2 -> V_158 ) ;
F_126 ( & V_131 -> V_140 ) ;
V_2 -> V_157 = 0 ;
F_138 ( V_1 ) ;
F_135 ( V_2 -> V_10 , V_154 , F_131 , ( void * ) V_1 ) ;
if ( ! V_2 -> V_52 . V_53 )
return;
V_152 = V_2 -> V_155 ;
F_19 (se) {
if ( V_5 -> V_59 )
V_160 = 0 ;
V_2 = F_8 ( V_5 ) ;
if ( V_160 )
F_97 ( V_2 , V_5 , V_113 ) ;
V_2 -> V_155 += V_152 ;
if ( F_129 ( V_2 ) )
break;
}
if ( ! V_5 )
V_1 -> V_55 += V_152 ;
if ( V_1 -> V_23 == V_1 -> V_142 && V_1 -> V_17 . V_55 )
F_106 ( V_1 -> V_23 ) ;
}
static T_1 F_139 ( struct V_130 * V_131 ,
T_1 V_162 , T_1 V_138 )
{
struct V_2 * V_2 ;
T_1 V_134 = V_162 ;
F_134 () ;
F_140 (cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_123 ( & V_1 -> V_140 ) ;
if ( ! F_129 ( V_2 ) )
goto V_36;
V_134 = - V_2 -> V_139 + 1 ;
if ( V_134 > V_162 )
V_134 = V_162 ;
V_162 -= V_134 ;
V_2 -> V_139 += V_134 ;
V_2 -> V_135 = V_138 ;
if ( V_2 -> V_139 > 0 )
F_137 ( V_2 ) ;
V_36:
F_126 ( & V_1 -> V_140 ) ;
if ( ! V_162 )
break;
}
F_136 () ;
return V_162 ;
}
static int F_141 ( struct V_130 * V_131 , int V_163 )
{
T_1 V_134 , V_135 ;
int V_142 = 1 , V_145 ;
F_123 ( & V_131 -> V_140 ) ;
if ( V_131 -> V_132 == V_133 )
goto V_164;
V_145 = ! F_142 ( & V_131 -> V_159 ) ;
V_142 = V_131 -> V_142 && ! V_145 ;
V_131 -> V_165 += V_163 ;
if ( V_142 )
goto V_164;
F_117 ( V_131 ) ;
if ( ! V_145 ) {
V_131 -> V_142 = 1 ;
goto V_164;
}
V_131 -> V_166 += V_163 ;
V_134 = V_131 -> V_134 ;
V_135 = V_131 -> V_135 ;
V_131 -> V_134 = 0 ;
while ( V_145 && V_134 > 0 ) {
F_126 ( & V_131 -> V_140 ) ;
V_134 = F_139 ( V_131 , V_134 ,
V_135 ) ;
F_123 ( & V_131 -> V_140 ) ;
V_145 = ! F_142 ( & V_131 -> V_159 ) ;
}
V_131 -> V_134 = V_134 ;
V_131 -> V_142 = 0 ;
V_164:
if ( V_142 )
V_131 -> V_141 = 0 ;
F_126 ( & V_131 -> V_140 ) ;
return V_142 ;
}
static int F_143 ( struct V_130 * V_131 , T_1 V_167 )
{
struct V_168 * V_169 = & V_131 -> V_170 ;
T_1 V_162 ;
if ( F_144 ( V_169 ) )
return 1 ;
V_162 = F_120 ( F_145 ( V_169 ) ) ;
if ( V_162 < V_167 )
return 1 ;
return 0 ;
}
static void F_146 ( struct V_130 * V_131 )
{
T_1 V_171 = V_172 + V_173 ;
if ( F_143 ( V_131 , V_171 ) )
return;
F_147 ( & V_131 -> V_174 ,
F_148 ( V_172 ) ) ;
}
static void F_149 ( struct V_2 * V_2 )
{
struct V_130 * V_131 = F_122 ( V_2 -> V_10 ) ;
T_2 V_175 = V_2 -> V_139 - V_176 ;
if ( V_175 <= 0 )
return;
F_123 ( & V_131 -> V_140 ) ;
if ( V_131 -> V_132 != V_133 &&
V_2 -> V_135 == V_131 -> V_135 ) {
V_131 -> V_134 += V_175 ;
if ( V_131 -> V_134 > F_116 () &&
! F_142 ( & V_131 -> V_159 ) )
F_146 ( V_131 ) ;
}
F_126 ( & V_131 -> V_140 ) ;
V_2 -> V_139 -= V_175 ;
}
static T_7 void F_104 ( struct V_2 * V_2 )
{
if ( ! V_2 -> V_144 || V_2 -> V_55 )
return;
F_149 ( V_2 ) ;
}
static void F_150 ( struct V_130 * V_131 )
{
T_1 V_134 = 0 , V_58 = F_116 () ;
T_1 V_138 ;
if ( F_143 ( V_131 , V_173 ) )
return;
F_123 ( & V_131 -> V_140 ) ;
if ( V_131 -> V_132 != V_133 && V_131 -> V_134 > V_58 ) {
V_134 = V_131 -> V_134 ;
V_131 -> V_134 = 0 ;
}
V_138 = V_131 -> V_135 ;
F_126 ( & V_131 -> V_140 ) ;
if ( ! V_134 )
return;
V_134 = F_139 ( V_131 , V_134 , V_138 ) ;
F_123 ( & V_131 -> V_140 ) ;
if ( V_138 == V_131 -> V_135 )
V_131 -> V_134 = V_134 ;
F_126 ( & V_131 -> V_140 ) ;
}
static void F_98 ( struct V_2 * V_2 )
{
if ( ! V_2 -> V_144 || V_2 -> V_23 )
return;
if ( F_129 ( V_2 ) )
return;
F_58 ( V_2 , 0 ) ;
if ( V_2 -> V_139 <= 0 )
F_133 ( V_2 ) ;
}
static void F_111 ( struct V_2 * V_2 )
{
if ( F_86 ( ! V_2 -> V_144 || V_2 -> V_139 > 0 ) )
return;
if ( F_129 ( V_2 ) )
return;
F_133 ( V_2 ) ;
}
static void F_58 ( struct V_2 * V_2 ,
unsigned long V_62 ) {}
static void F_111 ( struct V_2 * V_2 ) {}
static void F_98 ( struct V_2 * V_2 ) {}
static void F_104 ( struct V_2 * V_2 ) {}
static inline int F_129 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline int F_78 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline int F_130 ( struct V_84 * V_10 ,
int V_147 , int V_148 )
{
return 0 ;
}
static void F_151 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_152 ( F_21 ( V_6 ) != V_1 ) ;
if ( F_153 ( V_1 ) && V_2 -> V_55 > 1 ) {
T_1 V_58 = F_47 ( V_2 , V_5 ) ;
T_1 V_177 = V_5 -> V_66 - V_5 -> V_121 ;
T_2 V_20 = V_58 - V_177 ;
if ( V_20 < 0 ) {
if ( V_1 -> V_23 == V_6 )
F_106 ( V_6 ) ;
return;
}
if ( V_1 -> V_23 != V_6 )
V_20 = F_154 ( T_2 , 10000LL , V_20 ) ;
F_155 ( V_1 , V_20 ) ;
}
}
static void F_156 ( struct V_1 * V_1 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
if ( V_23 -> V_178 != & V_179 )
return;
if ( F_8 ( & V_23 -> V_5 ) -> V_55 < V_46 )
F_151 ( V_1 , V_23 ) ;
}
static inline void
F_151 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
}
static inline void F_156 ( struct V_1 * V_1 )
{
}
static void
F_157 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_112 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
F_19 (se) {
if ( V_5 -> V_59 )
break;
V_2 = F_8 ( V_5 ) ;
F_97 ( V_2 , V_5 , V_112 ) ;
if ( F_129 ( V_2 ) )
break;
V_2 -> V_155 ++ ;
V_112 = V_113 ;
}
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
V_2 -> V_155 ++ ;
if ( F_129 ( V_2 ) )
break;
F_77 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
if ( ! V_5 )
F_158 ( V_1 ) ;
F_156 ( V_1 ) ;
}
static void F_159 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_112 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
int V_180 = V_112 & V_116 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_103 ( V_2 , V_5 , V_112 ) ;
if ( F_129 ( V_2 ) )
break;
V_2 -> V_155 -- ;
if ( V_2 -> V_52 . V_53 ) {
if ( V_180 && F_17 ( V_5 ) )
F_160 ( F_17 ( V_5 ) ) ;
V_5 = F_17 ( V_5 ) ;
break;
}
V_112 |= V_116 ;
}
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
V_2 -> V_155 -- ;
if ( F_129 ( V_2 ) )
break;
F_77 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
if ( ! V_5 )
F_161 ( V_1 ) ;
F_156 ( V_1 ) ;
}
static void F_162 ( struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
T_1 V_18 ;
#ifndef F_26
T_1 V_26 ;
do {
V_26 = V_2 -> V_26 ;
F_163 () ;
V_18 = V_2 -> V_18 ;
} while ( V_18 != V_26 );
#else
V_18 = V_2 -> V_18 ;
#endif
V_5 -> V_19 -= V_18 ;
}
static long F_164 ( struct V_84 * V_10 , int V_181 , long V_182 , long V_183 )
{
struct V_4 * V_5 = V_10 -> V_5 [ V_181 ] ;
if ( ! V_10 -> V_11 )
return V_182 ;
F_19 (se) {
long V_184 , V_185 ;
V_10 = V_5 -> V_8 -> V_10 ;
V_185 = V_183 + F_79 ( V_10 , V_5 -> V_8 ) ;
V_184 = V_5 -> V_8 -> V_52 . V_53 + V_182 ;
if ( V_185 > 0 && V_184 < V_185 )
V_182 = ( V_184 * V_10 -> V_93 ) / V_185 ;
else
V_182 = V_10 -> V_93 ;
if ( V_182 < V_94 )
V_182 = V_94 ;
V_182 -= V_5 -> V_52 . V_53 ;
V_183 = 0 ;
}
return V_182 ;
}
static inline unsigned long F_164 ( struct V_84 * V_10 , int V_181 ,
unsigned long V_182 , unsigned long V_183 )
{
return V_182 ;
}
static int F_165 ( struct V_186 * V_187 , struct V_3 * V_6 , int V_188 )
{
T_2 V_189 , V_52 ;
int V_190 , V_191 , V_192 ;
unsigned long V_193 ;
struct V_84 * V_10 ;
unsigned long V_53 ;
int V_194 ;
V_190 = V_187 -> V_195 ;
V_191 = F_119 () ;
V_192 = F_166 ( V_6 ) ;
V_52 = F_167 ( V_192 , V_190 ) ;
V_189 = F_168 ( V_191 , V_190 ) ;
if ( V_188 ) {
V_10 = V_84 ( V_196 ) ;
V_53 = V_196 -> V_5 . V_52 . V_53 ;
V_189 += F_164 ( V_10 , V_191 , - V_53 , - V_53 ) ;
V_52 += F_164 ( V_10 , V_192 , 0 , - V_53 ) ;
}
V_10 = V_84 ( V_6 ) ;
V_53 = V_6 -> V_5 . V_52 . V_53 ;
if ( V_189 > 0 ) {
T_2 V_197 , V_198 ;
V_197 = 100 ;
V_197 *= F_169 ( V_192 ) ;
V_197 *= V_189 +
F_164 ( V_10 , V_191 , V_53 , V_53 ) ;
V_198 = 100 + ( V_187 -> V_199 - 100 ) / 2 ;
V_198 *= F_169 ( V_191 ) ;
V_198 *= V_52 + F_164 ( V_10 , V_192 , 0 , V_53 ) ;
V_194 = V_197 <= V_198 ;
} else
V_194 = true ;
if ( V_188 && V_194 )
return 1 ;
F_94 ( V_6 , V_5 . V_64 . V_200 ) ;
V_193 = F_170 ( V_191 ) ;
if ( V_194 ||
( V_189 <= V_52 &&
V_189 + F_168 ( V_192 , V_190 ) <= V_193 ) ) {
F_94 ( V_187 , V_201 ) ;
F_94 ( V_6 , V_5 . V_64 . V_202 ) ;
return 1 ;
}
return 0 ;
}
static struct V_203 *
F_171 ( struct V_186 * V_187 , struct V_3 * V_6 ,
int V_191 , int V_204 )
{
struct V_203 * V_205 = NULL , * V_206 = V_187 -> V_207 ;
unsigned long V_208 = V_209 , V_189 = 0 ;
int V_210 = 100 + ( V_187 -> V_199 - 100 ) / 2 ;
do {
unsigned long V_52 , V_211 ;
int V_212 ;
int V_213 ;
if ( ! F_172 ( F_173 ( V_206 ) ,
F_174 ( V_6 ) ) )
continue;
V_212 = F_175 ( V_191 ,
F_173 ( V_206 ) ) ;
V_211 = 0 ;
F_176 (i, sched_group_cpus(group)) {
if ( V_212 )
V_52 = F_167 ( V_213 , V_204 ) ;
else
V_52 = F_168 ( V_213 , V_204 ) ;
V_211 += V_52 ;
}
V_211 = ( V_211 * V_214 ) / V_206 -> V_215 -> V_216 ;
if ( V_212 ) {
V_189 = V_211 ;
} else if ( V_211 < V_208 ) {
V_208 = V_211 ;
V_205 = V_206 ;
}
} while ( V_206 = V_206 -> V_36 , V_206 != V_187 -> V_207 );
if ( ! V_205 || 100 * V_189 < V_210 * V_208 )
return NULL ;
return V_205 ;
}
static int
F_177 ( struct V_203 * V_206 , struct V_3 * V_6 , int V_191 )
{
unsigned long V_52 , V_208 = V_209 ;
int V_205 = - 1 ;
int V_213 ;
F_178 (i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
V_52 = F_179 ( V_213 ) ;
if ( V_52 < V_208 || ( V_52 == V_208 && V_213 == V_191 ) ) {
V_208 = V_52 ;
V_205 = V_213 ;
}
}
return V_205 ;
}
static int F_180 ( struct V_3 * V_6 , int V_217 )
{
int V_181 = F_119 () ;
int V_192 = F_166 ( V_6 ) ;
struct V_186 * V_187 ;
struct V_203 * V_218 ;
int V_213 , V_219 = 0 ;
if ( V_217 == V_181 && F_181 ( V_181 ) )
return V_181 ;
if ( V_217 == V_192 && F_181 ( V_192 ) )
return V_192 ;
F_134 () ;
V_220:
F_182 (target, sd) {
if ( ! V_219 && ( V_187 -> V_112 & V_221 ) )
continue;
if ( V_219 && ! ( V_187 -> V_112 & V_221 ) )
break;
if ( ! ( V_187 -> V_112 & V_222 ) )
break;
V_218 = V_187 -> V_207 ;
do {
if ( ! F_172 ( F_173 ( V_218 ) ,
F_174 ( V_6 ) ) )
goto V_36;
F_176 (i, sched_group_cpus(sg)) {
if ( ! F_181 ( V_213 ) )
goto V_36;
}
V_217 = F_183 ( F_173 ( V_218 ) ,
F_174 ( V_6 ) ) ;
goto V_223;
V_36:
V_218 = V_218 -> V_36 ;
} while ( V_218 != V_187 -> V_207 );
}
if ( ! V_219 ) {
V_219 = 1 ;
goto V_220;
}
V_223:
F_136 () ;
return V_217 ;
}
static int
F_184 ( struct V_3 * V_6 , int V_224 , int V_225 )
{
struct V_186 * V_226 , * V_227 = NULL , * V_187 = NULL ;
int V_181 = F_119 () ;
int V_192 = F_166 ( V_6 ) ;
int V_228 = V_181 ;
int V_229 = 0 ;
int V_230 = 1 ;
int V_188 = V_225 & V_231 ;
if ( V_224 & V_232 ) {
if ( F_175 ( V_181 , F_174 ( V_6 ) ) )
V_229 = 1 ;
V_228 = V_192 ;
}
F_134 () ;
F_182 (cpu, tmp) {
if ( ! ( V_226 -> V_112 & V_233 ) )
continue;
if ( V_226 -> V_112 & ( V_234 | V_235 ) ) {
unsigned long V_216 = 0 ;
unsigned long V_55 = 0 ;
unsigned long V_236 ;
int V_213 ;
F_176 (i, sched_domain_span(tmp)) {
V_216 += F_169 ( V_213 ) ;
V_55 += F_185 ( V_213 ) -> V_17 . V_55 ;
}
V_236 = F_186 ( V_216 , V_214 ) ;
if ( V_226 -> V_112 & V_234 )
V_55 /= 2 ;
if ( V_55 < V_236 )
V_230 = 0 ;
}
if ( V_229 && ( V_226 -> V_112 & V_237 ) &&
F_175 ( V_192 , F_187 ( V_226 ) ) ) {
V_227 = V_226 ;
V_229 = 0 ;
}
if ( ! V_230 && ! V_229 )
break;
if ( ! ( V_226 -> V_112 & V_224 ) )
continue;
if ( V_230 )
V_187 = V_226 ;
}
if ( V_227 ) {
if ( V_181 == V_192 || F_165 ( V_227 , V_6 , V_188 ) )
V_192 = V_181 ;
V_228 = F_180 ( V_6 , V_192 ) ;
goto V_238;
}
while ( V_187 ) {
int V_204 = V_187 -> V_239 ;
struct V_203 * V_206 ;
int V_53 ;
if ( ! ( V_187 -> V_112 & V_224 ) ) {
V_187 = V_187 -> V_240 ;
continue;
}
if ( V_224 & V_232 )
V_204 = V_187 -> V_195 ;
V_206 = F_171 ( V_187 , V_6 , V_181 , V_204 ) ;
if ( ! V_206 ) {
V_187 = V_187 -> V_240 ;
continue;
}
V_228 = F_177 ( V_206 , V_6 , V_181 ) ;
if ( V_228 == - 1 || V_228 == V_181 ) {
V_187 = V_187 -> V_240 ;
continue;
}
V_181 = V_228 ;
V_53 = V_187 -> V_241 ;
V_187 = NULL ;
F_182 (cpu, tmp) {
if ( V_53 <= V_226 -> V_241 )
break;
if ( V_226 -> V_112 & V_224 )
V_187 = V_226 ;
}
}
V_238:
F_136 () ;
return V_228 ;
}
static unsigned long
F_188 ( struct V_4 * V_23 , struct V_4 * V_5 )
{
unsigned long V_242 = V_243 ;
return F_43 ( V_242 , V_5 ) ;
}
static int
F_109 ( struct V_4 * V_23 , struct V_4 * V_5 )
{
T_2 V_242 , V_244 = V_23 -> V_19 - V_5 -> V_19 ;
if ( V_244 <= 0 )
return - 1 ;
V_242 = F_188 ( V_23 , V_5 ) ;
if ( V_244 > V_242 )
return 1 ;
return 0 ;
}
static void F_189 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_44 ( F_2 ( V_5 ) -> V_245 == V_246 ) )
return;
F_19 (se)
F_8 ( V_5 ) -> V_37 = V_5 ;
}
static void F_160 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_44 ( F_2 ( V_5 ) -> V_245 == V_246 ) )
return;
F_19 (se)
F_8 ( V_5 ) -> V_36 = V_5 ;
}
static void F_190 ( struct V_4 * V_5 )
{
F_19 (se)
F_8 ( V_5 ) -> V_115 = V_5 ;
}
static void F_191 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_225 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
struct V_4 * V_5 = & V_23 -> V_5 , * V_13 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_7 ( V_23 ) ;
int V_247 = V_2 -> V_55 >= V_46 ;
int V_248 = 0 ;
if ( F_44 ( V_5 == V_13 ) )
return;
if ( F_44 ( F_78 ( F_8 ( V_13 ) ) ) )
return;
if ( F_96 ( V_249 ) && V_247 && ! ( V_225 & V_250 ) ) {
F_160 ( V_13 ) ;
V_248 = 1 ;
}
if ( F_192 ( V_23 ) )
return;
if ( F_44 ( V_23 -> V_245 == V_246 ) &&
F_86 ( V_6 -> V_245 != V_246 ) )
goto V_251;
if ( F_44 ( V_6 -> V_245 != V_252 ) )
return;
F_20 ( & V_5 , & V_13 ) ;
F_54 ( F_8 ( V_5 ) ) ;
F_193 ( ! V_13 ) ;
if ( F_109 ( V_5 , V_13 ) == 1 ) {
if ( ! V_248 )
F_160 ( V_13 ) ;
goto V_251;
}
return;
V_251:
F_106 ( V_23 ) ;
if ( F_44 ( ! V_5 -> V_59 || V_23 == V_1 -> V_142 ) )
return;
if ( F_96 ( V_253 ) && V_247 && F_5 ( V_5 ) )
F_189 ( V_5 ) ;
}
static struct V_3 * F_194 ( struct V_1 * V_1 )
{
struct V_3 * V_6 ;
struct V_2 * V_2 = & V_1 -> V_17 ;
struct V_4 * V_5 ;
if ( ! V_2 -> V_55 )
return NULL ;
do {
V_5 = F_108 ( V_2 ) ;
F_107 ( V_2 , V_5 ) ;
V_2 = F_9 ( V_5 ) ;
} while ( V_2 );
V_6 = F_2 ( V_5 ) ;
F_151 ( V_1 , V_6 ) ;
return V_6 ;
}
static void F_195 ( struct V_1 * V_1 , struct V_3 * V_124 )
{
struct V_4 * V_5 = & V_124 -> V_5 ;
struct V_2 * V_2 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_110 ( V_2 , V_5 ) ;
}
}
static void F_196 ( struct V_1 * V_1 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
struct V_2 * V_2 = F_7 ( V_23 ) ;
struct V_4 * V_5 = & V_23 -> V_5 ;
if ( F_44 ( V_1 -> V_55 == 1 ) )
return;
F_102 ( V_2 , V_5 ) ;
if ( V_23 -> V_245 != V_254 ) {
F_138 ( V_1 ) ;
F_54 ( V_2 ) ;
}
F_190 ( V_5 ) ;
}
static bool F_197 ( struct V_1 * V_1 , struct V_3 * V_6 , bool V_251 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
if ( ! V_5 -> V_59 || F_78 ( F_8 ( V_5 ) ) )
return false ;
F_160 ( V_5 ) ;
F_196 ( V_1 ) ;
return true ;
}
static void F_198 ( struct V_1 * V_255 , struct V_3 * V_6 ,
struct V_1 * V_256 , int V_191 )
{
F_199 ( V_255 , V_6 , 0 ) ;
F_200 ( V_6 , V_191 ) ;
F_201 ( V_256 , V_6 , 0 ) ;
F_202 ( V_256 , V_6 , 0 ) ;
}
static
int F_203 ( struct V_3 * V_6 , struct V_1 * V_1 , int V_191 ,
struct V_186 * V_187 , enum V_257 V_142 ,
int * V_258 )
{
int V_259 = 0 ;
if ( ! F_175 ( V_191 , F_174 ( V_6 ) ) ) {
F_94 ( V_6 , V_5 . V_64 . V_260 ) ;
return 0 ;
}
* V_258 = 0 ;
if ( F_204 ( V_1 , V_6 ) ) {
F_94 ( V_6 , V_5 . V_64 . V_261 ) ;
return 0 ;
}
V_259 = F_205 ( V_6 , V_1 -> V_73 , V_187 ) ;
if ( ! V_259 ||
V_187 -> V_262 > V_187 -> V_263 ) {
#ifdef F_62
if ( V_259 ) {
F_94 ( V_187 , V_264 [ V_142 ] ) ;
F_94 ( V_6 , V_5 . V_64 . V_265 ) ;
}
#endif
return 1 ;
}
if ( V_259 ) {
F_94 ( V_6 , V_5 . V_64 . V_266 ) ;
return 0 ;
}
return 1 ;
}
static int
F_206 ( struct V_1 * V_256 , int V_191 , struct V_1 * V_267 ,
struct V_186 * V_187 , enum V_257 V_142 )
{
struct V_3 * V_6 , * V_268 ;
struct V_2 * V_2 ;
int V_269 = 0 ;
F_207 (busiest, cfs_rq) {
F_208 (p, n, &cfs_rq->tasks, se.group_node) {
if ( F_130 ( V_84 ( V_6 ) ,
V_267 -> V_181 , V_191 ) )
break;
if ( ! F_203 ( V_6 , V_267 , V_191 ,
V_187 , V_142 , & V_269 ) )
continue;
F_198 ( V_267 , V_6 , V_256 , V_191 ) ;
F_94 ( V_187 , V_270 [ V_142 ] ) ;
return 1 ;
}
}
return 0 ;
}
static unsigned long
F_209 ( struct V_1 * V_256 , int V_191 , struct V_1 * V_267 ,
unsigned long V_271 , struct V_186 * V_187 ,
enum V_257 V_142 , int * V_258 ,
struct V_2 * V_272 )
{
int V_273 = 0 , V_274 = 0 ;
long V_275 = V_271 ;
struct V_3 * V_6 , * V_268 ;
if ( V_271 == 0 )
goto V_276;
F_208 (p, n, &busiest_cfs_rq->tasks, se.group_node) {
if ( V_273 ++ > V_277 )
break;
if ( ( V_6 -> V_5 . V_52 . V_53 >> 1 ) > V_275 ||
! F_203 ( V_6 , V_267 , V_191 , V_187 , V_142 ,
V_258 ) )
continue;
F_198 ( V_267 , V_6 , V_256 , V_191 ) ;
V_274 ++ ;
V_275 -= V_6 -> V_5 . V_52 . V_53 ;
#ifdef F_210
if ( V_142 == V_278 )
break;
#endif
if ( V_275 <= 0 )
break;
}
V_276:
F_53 ( V_187 , V_270 [ V_142 ] , V_274 ) ;
return V_271 - V_275 ;
}
static int F_211 ( struct V_84 * V_10 , int V_181 )
{
struct V_2 * V_2 ;
unsigned long V_112 ;
struct V_1 * V_1 ;
if ( ! V_10 -> V_5 [ V_181 ] )
return 0 ;
V_1 = F_185 ( V_181 ) ;
V_2 = V_10 -> V_2 [ V_181 ] ;
F_212 ( & V_1 -> V_140 , V_112 ) ;
F_138 ( V_1 ) ;
F_77 ( V_2 , 1 ) ;
F_83 ( V_2 ) ;
F_213 ( & V_1 -> V_140 , V_112 ) ;
return 0 ;
}
static void F_214 ( int V_181 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 = F_185 ( V_181 ) ;
F_134 () ;
F_207 (rq, cfs_rq) {
if ( F_78 ( V_2 ) )
continue;
F_211 ( V_2 -> V_10 , V_181 ) ;
}
F_136 () ;
}
static int F_215 ( struct V_84 * V_10 , void * V_151 )
{
unsigned long V_52 ;
long V_181 = ( long ) V_151 ;
if ( ! V_10 -> V_11 ) {
V_52 = F_185 ( V_181 ) -> V_52 . V_53 ;
} else {
V_52 = V_10 -> V_11 -> V_2 [ V_181 ] -> V_279 ;
V_52 *= V_10 -> V_5 [ V_181 ] -> V_52 . V_53 ;
V_52 /= V_10 -> V_11 -> V_2 [ V_181 ] -> V_52 . V_53 + 1 ;
}
V_10 -> V_2 [ V_181 ] -> V_279 = V_52 ;
return 0 ;
}
static void F_216 ( long V_181 )
{
F_217 ( F_215 , V_154 , ( void * ) V_181 ) ;
}
static unsigned long
F_218 ( struct V_1 * V_256 , int V_191 , struct V_1 * V_267 ,
unsigned long V_271 ,
struct V_186 * V_187 , enum V_257 V_142 ,
int * V_258 )
{
long V_275 = V_271 ;
struct V_2 * V_272 ;
F_134 () ;
F_216 ( F_11 ( V_267 ) ) ;
F_207 (busiest, busiest_cfs_rq) {
unsigned long V_280 = V_272 -> V_279 ;
unsigned long V_281 = V_272 -> V_52 . V_53 ;
T_1 V_282 , V_283 ;
if ( ! V_272 -> V_80 ||
F_130 ( V_272 -> V_10 , F_11 ( V_267 ) , V_191 ) )
continue;
V_282 = ( T_1 ) V_275 * V_281 ;
V_282 = F_219 ( V_282 , V_280 + 1 ) ;
V_283 = F_209 ( V_256 , V_191 , V_267 ,
V_282 , V_187 , V_142 , V_258 ,
V_272 ) ;
if ( ! V_283 )
continue;
V_283 *= V_280 ;
V_283 = F_219 ( V_283 , V_281 + 1 ) ;
V_275 -= V_283 ;
if ( V_275 < 0 )
break;
}
F_136 () ;
return V_271 - V_275 ;
}
static inline void F_214 ( int V_181 )
{
}
static unsigned long
F_218 ( struct V_1 * V_256 , int V_191 , struct V_1 * V_267 ,
unsigned long V_271 ,
struct V_186 * V_187 , enum V_257 V_142 ,
int * V_258 )
{
return F_209 ( V_256 , V_191 , V_267 ,
V_271 , V_187 , V_142 , V_258 ,
& V_267 -> V_17 ) ;
}
static int F_220 ( struct V_1 * V_256 , int V_191 , struct V_1 * V_267 ,
unsigned long V_271 ,
struct V_186 * V_187 , enum V_257 V_142 ,
int * V_258 )
{
unsigned long V_284 = 0 , V_285 ;
do {
V_285 = F_218 ( V_256 , V_191 , V_267 ,
V_271 - V_284 ,
V_187 , V_142 , V_258 ) ;
V_284 += V_285 ;
#ifdef F_210
if ( V_142 == V_278 && V_256 -> V_55 )
break;
if ( F_221 ( & V_256 -> V_140 ) ||
F_221 ( & V_267 -> V_140 ) )
break;
#endif
} while ( V_285 && V_271 > V_284 );
return V_284 > 0 ;
}
static inline unsigned int F_222 ( struct V_203 * V_206 )
{
return F_223 ( F_173 ( V_206 ) ) ;
}
static inline int F_224 ( struct V_186 * V_187 ,
enum V_257 V_142 )
{
int V_204 ;
switch ( V_142 ) {
case V_286 :
V_204 = V_187 -> V_287 ;
break;
case V_278 :
V_204 = V_187 -> V_288 ;
break;
default:
V_204 = V_187 -> V_289 ;
break;
}
return V_204 ;
}
static inline void F_225 ( struct V_186 * V_187 ,
struct V_290 * V_291 , enum V_257 V_142 )
{
if ( V_142 == V_286 || ! ( V_187 -> V_112 & V_234 ) )
V_291 -> V_292 = 0 ;
else {
V_291 -> V_292 = 1 ;
V_291 -> V_293 = V_209 ;
V_291 -> V_294 = 0 ;
}
}
static inline void F_226 ( struct V_203 * V_206 ,
struct V_290 * V_291 , int V_212 , struct V_295 * V_296 )
{
if ( ! V_291 -> V_292 )
return;
if ( V_212 && ( V_291 -> V_297 >= V_296 -> V_298 ||
! V_291 -> V_297 ) )
V_291 -> V_292 = 0 ;
if ( ! V_291 -> V_292 ||
V_296 -> V_299 >= V_296 -> V_298 ||
! V_296 -> V_299 )
return;
if ( ( V_296 -> V_299 < V_291 -> V_293 ) ||
( V_296 -> V_299 == V_291 -> V_293 &&
F_222 ( V_206 ) > F_222 ( V_291 -> V_300 ) ) ) {
V_291 -> V_300 = V_206 ;
V_291 -> V_293 = V_296 -> V_299 ;
V_291 -> V_301 = V_296 -> V_302 /
V_296 -> V_299 ;
}
if ( V_296 -> V_299 + 1 > V_296 -> V_298 )
return;
if ( V_296 -> V_299 > V_291 -> V_294 ||
( V_296 -> V_299 == V_291 -> V_294 &&
F_222 ( V_206 ) < F_222 ( V_291 -> V_303 ) ) ) {
V_291 -> V_303 = V_206 ;
V_291 -> V_294 = V_296 -> V_299 ;
}
}
static inline int F_227 ( struct V_290 * V_291 ,
int V_191 , unsigned long * V_210 )
{
if ( ! V_291 -> V_292 )
return 0 ;
if ( V_291 -> V_304 != V_291 -> V_303 ||
V_291 -> V_303 == V_291 -> V_300 )
return 0 ;
* V_210 = V_291 -> V_301 ;
V_291 -> V_267 = V_291 -> V_300 ;
return 1 ;
}
static inline void F_225 ( struct V_186 * V_187 ,
struct V_290 * V_291 , enum V_257 V_142 )
{
return;
}
static inline void F_226 ( struct V_203 * V_206 ,
struct V_290 * V_291 , int V_212 , struct V_295 * V_296 )
{
return;
}
static inline int F_227 ( struct V_290 * V_291 ,
int V_191 , unsigned long * V_210 )
{
return 0 ;
}
unsigned long F_228 ( struct V_186 * V_187 , int V_181 )
{
return V_214 ;
}
unsigned long __weak F_229 ( struct V_186 * V_187 , int V_181 )
{
return F_228 ( V_187 , V_181 ) ;
}
unsigned long F_230 ( struct V_186 * V_187 , int V_181 )
{
unsigned long V_53 = V_187 -> V_241 ;
unsigned long V_305 = V_187 -> V_305 ;
V_305 /= V_53 ;
return V_305 ;
}
unsigned long __weak F_231 ( struct V_186 * V_187 , int V_181 )
{
return F_230 ( V_187 , V_181 ) ;
}
unsigned long F_232 ( int V_181 )
{
struct V_1 * V_1 = F_185 ( V_181 ) ;
T_1 V_306 , V_307 ;
V_306 = F_233 () + ( V_1 -> clock - V_1 -> V_308 ) ;
if ( F_44 ( V_306 < V_1 -> V_309 ) ) {
V_307 = 0 ;
} else {
V_307 = V_306 - V_1 -> V_309 ;
}
if ( F_44 ( ( T_2 ) V_306 < V_214 ) )
V_306 = V_214 ;
V_306 >>= V_310 ;
return F_219 ( V_307 , V_306 ) ;
}
static void F_234 ( struct V_186 * V_187 , int V_181 )
{
unsigned long V_53 = V_187 -> V_241 ;
unsigned long V_216 = V_214 ;
struct V_203 * V_311 = V_187 -> V_207 ;
if ( ( V_187 -> V_112 & V_221 ) && V_53 > 1 ) {
if ( F_96 ( V_312 ) )
V_216 *= F_231 ( V_187 , V_181 ) ;
else
V_216 *= F_230 ( V_187 , V_181 ) ;
V_216 >>= V_310 ;
}
V_311 -> V_215 -> V_313 = V_216 ;
if ( F_96 ( V_312 ) )
V_216 *= F_229 ( V_187 , V_181 ) ;
else
V_216 *= F_228 ( V_187 , V_181 ) ;
V_216 >>= V_310 ;
V_216 *= F_232 ( V_181 ) ;
V_216 >>= V_310 ;
if ( ! V_216 )
V_216 = 1 ;
F_185 ( V_181 ) -> V_314 = V_216 ;
V_311 -> V_215 -> V_216 = V_216 ;
}
static void F_235 ( struct V_186 * V_187 , int V_181 )
{
struct V_186 * V_240 = V_187 -> V_240 ;
struct V_203 * V_206 , * V_311 = V_187 -> V_207 ;
unsigned long V_216 ;
if ( ! V_240 ) {
F_234 ( V_187 , V_181 ) ;
return;
}
V_216 = 0 ;
V_206 = V_240 -> V_207 ;
do {
V_216 += V_206 -> V_215 -> V_216 ;
V_206 = V_206 -> V_36 ;
} while ( V_206 != V_240 -> V_207 );
V_311 -> V_215 -> V_216 = V_216 ;
}
static inline int
F_236 ( struct V_186 * V_187 , struct V_203 * V_206 )
{
if ( ! ( V_187 -> V_112 & V_221 ) )
return 0 ;
if ( V_206 -> V_215 -> V_216 * 32 > V_206 -> V_215 -> V_313 * 29 )
return 1 ;
return 0 ;
}
static inline void F_237 ( struct V_186 * V_187 ,
struct V_203 * V_206 , int V_191 ,
enum V_257 V_142 , int V_204 ,
int V_212 , const struct V_315 * V_316 ,
int * V_317 , struct V_295 * V_296 )
{
unsigned long V_52 , V_318 , V_319 , V_320 ;
int V_213 ;
unsigned int V_321 = - 1 , V_322 = 0 ;
unsigned long V_323 = 0 ;
if ( V_212 )
V_321 = F_222 ( V_206 ) ;
V_318 = 0 ;
V_319 = ~ 0UL ;
V_320 = 0 ;
F_178 (i, sched_group_cpus(group), cpus) {
struct V_1 * V_1 = F_185 ( V_213 ) ;
if ( V_212 ) {
if ( F_181 ( V_213 ) && ! V_322 ) {
V_322 = 1 ;
V_321 = V_213 ;
}
V_52 = F_168 ( V_213 , V_204 ) ;
} else {
V_52 = F_167 ( V_213 , V_204 ) ;
if ( V_52 > V_318 ) {
V_318 = V_52 ;
V_320 = V_1 -> V_55 ;
}
if ( V_319 > V_52 )
V_319 = V_52 ;
}
V_296 -> V_324 += V_52 ;
V_296 -> V_299 += V_1 -> V_55 ;
V_296 -> V_302 += F_179 ( V_213 ) ;
if ( F_181 ( V_213 ) )
V_296 -> V_325 ++ ;
}
if ( V_142 != V_278 && V_212 ) {
if ( V_321 != V_191 ) {
* V_317 = 0 ;
return;
}
F_235 ( V_187 , V_191 ) ;
}
V_296 -> V_211 = ( V_296 -> V_324 * V_214 ) / V_206 -> V_215 -> V_216 ;
if ( V_296 -> V_299 )
V_323 = V_296 -> V_302 / V_296 -> V_299 ;
if ( ( V_318 - V_319 ) >= V_323 && V_320 > 1 )
V_296 -> V_326 = 1 ;
V_296 -> V_298 = F_186 ( V_206 -> V_215 -> V_216 ,
V_214 ) ;
if ( ! V_296 -> V_298 )
V_296 -> V_298 = F_236 ( V_187 , V_206 ) ;
V_296 -> V_327 = V_206 -> V_327 ;
if ( V_296 -> V_298 > V_296 -> V_299 )
V_296 -> V_328 = 1 ;
}
static bool F_238 ( struct V_186 * V_187 ,
struct V_290 * V_291 ,
struct V_203 * V_218 ,
struct V_295 * V_296 ,
int V_191 )
{
if ( V_296 -> V_211 <= V_291 -> V_329 )
return false ;
if ( V_296 -> V_299 > V_296 -> V_298 )
return true ;
if ( V_296 -> V_326 )
return true ;
if ( ( V_187 -> V_112 & V_330 ) && V_296 -> V_299 &&
V_191 < F_222 ( V_218 ) ) {
if ( ! V_291 -> V_267 )
return true ;
if ( F_222 ( V_291 -> V_267 ) > F_222 ( V_218 ) )
return true ;
}
return false ;
}
static inline void F_239 ( struct V_186 * V_187 , int V_191 ,
enum V_257 V_142 , const struct V_315 * V_316 ,
int * V_317 , struct V_290 * V_291 )
{
struct V_186 * V_240 = V_187 -> V_240 ;
struct V_203 * V_218 = V_187 -> V_207 ;
struct V_295 V_296 ;
int V_204 , V_331 = 0 ;
if ( V_240 && V_240 -> V_112 & V_332 )
V_331 = 1 ;
F_225 ( V_187 , V_291 , V_142 ) ;
V_204 = F_224 ( V_187 , V_142 ) ;
do {
int V_212 ;
V_212 = F_175 ( V_191 , F_173 ( V_218 ) ) ;
memset ( & V_296 , 0 , sizeof( V_296 ) ) ;
F_237 ( V_187 , V_218 , V_191 , V_142 , V_204 ,
V_212 , V_316 , V_317 , & V_296 ) ;
if ( V_212 && ! ( * V_317 ) )
return;
V_291 -> V_333 += V_296 . V_324 ;
V_291 -> V_334 += V_218 -> V_215 -> V_216 ;
if ( V_331 && ! V_212 && V_291 -> V_335 )
V_296 . V_298 = F_125 ( V_296 . V_298 , 1UL ) ;
if ( V_212 ) {
V_291 -> V_189 = V_296 . V_211 ;
V_291 -> V_304 = V_218 ;
V_291 -> V_297 = V_296 . V_299 ;
V_291 -> V_336 = V_296 . V_302 ;
V_291 -> V_335 = V_296 . V_328 ;
V_291 -> V_337 = V_296 . V_325 ;
} else if ( F_238 ( V_187 , V_291 , V_218 , & V_296 , V_191 ) ) {
V_291 -> V_329 = V_296 . V_211 ;
V_291 -> V_267 = V_218 ;
V_291 -> V_338 = V_296 . V_299 ;
V_291 -> V_339 = V_296 . V_325 ;
V_291 -> V_340 = V_296 . V_298 ;
V_291 -> V_341 = V_296 . V_302 ;
V_291 -> V_342 = V_296 . V_328 ;
V_291 -> V_343 = V_296 . V_327 ;
V_291 -> V_326 = V_296 . V_326 ;
}
F_226 ( V_218 , V_291 , V_212 , & V_296 ) ;
V_218 = V_218 -> V_36 ;
} while ( V_218 != V_187 -> V_207 );
}
int __weak F_240 ( void )
{
return 0 * V_330 ;
}
static int F_241 ( struct V_186 * V_187 ,
struct V_290 * V_291 ,
int V_191 , unsigned long * V_210 )
{
int V_344 ;
if ( ! ( V_187 -> V_112 & V_330 ) )
return 0 ;
if ( ! V_291 -> V_267 )
return 0 ;
V_344 = F_222 ( V_291 -> V_267 ) ;
if ( V_191 > V_344 )
return 0 ;
* V_210 = F_186 ( V_291 -> V_329 * V_291 -> V_267 -> V_215 -> V_216 ,
V_214 ) ;
return 1 ;
}
static inline void F_242 ( struct V_290 * V_291 ,
int V_191 , unsigned long * V_210 )
{
unsigned long V_226 , V_345 = 0 , V_346 = 0 ;
unsigned int V_347 = 2 ;
unsigned long V_348 ;
if ( V_291 -> V_297 ) {
V_291 -> V_336 /= V_291 -> V_297 ;
if ( V_291 -> V_341 >
V_291 -> V_336 )
V_347 = 1 ;
} else
V_291 -> V_336 =
F_170 ( V_191 ) ;
V_348 = V_291 -> V_341
* V_214 ;
V_348 /= V_291 -> V_267 -> V_215 -> V_216 ;
if ( V_291 -> V_329 - V_291 -> V_189 + V_348 >=
( V_348 * V_347 ) ) {
* V_210 = V_291 -> V_341 ;
return;
}
V_345 += V_291 -> V_267 -> V_215 -> V_216 *
F_125 ( V_291 -> V_341 , V_291 -> V_329 ) ;
V_345 += V_291 -> V_304 -> V_215 -> V_216 *
F_125 ( V_291 -> V_336 , V_291 -> V_189 ) ;
V_345 /= V_214 ;
V_226 = ( V_291 -> V_341 * V_214 ) /
V_291 -> V_267 -> V_215 -> V_216 ;
if ( V_291 -> V_329 > V_226 )
V_346 += V_291 -> V_267 -> V_215 -> V_216 *
F_125 ( V_291 -> V_341 , V_291 -> V_329 - V_226 ) ;
if ( V_291 -> V_329 * V_291 -> V_267 -> V_215 -> V_216 <
V_291 -> V_341 * V_214 )
V_226 = ( V_291 -> V_329 * V_291 -> V_267 -> V_215 -> V_216 ) /
V_291 -> V_304 -> V_215 -> V_216 ;
else
V_226 = ( V_291 -> V_341 * V_214 ) /
V_291 -> V_304 -> V_215 -> V_216 ;
V_346 += V_291 -> V_304 -> V_215 -> V_216 *
F_125 ( V_291 -> V_336 , V_291 -> V_189 + V_226 ) ;
V_346 /= V_214 ;
if ( V_346 > V_345 )
* V_210 = V_291 -> V_341 ;
}
static inline void F_243 ( struct V_290 * V_291 , int V_191 ,
unsigned long * V_210 )
{
unsigned long V_349 , V_350 = ~ 0UL ;
V_291 -> V_341 /= V_291 -> V_338 ;
if ( V_291 -> V_326 ) {
V_291 -> V_341 =
F_125 ( V_291 -> V_341 , V_291 -> V_211 ) ;
}
if ( V_291 -> V_329 < V_291 -> V_211 ) {
* V_210 = 0 ;
return F_242 ( V_291 , V_191 , V_210 ) ;
}
if ( ! V_291 -> V_326 ) {
V_350 = ( V_291 -> V_338 -
V_291 -> V_340 ) ;
V_350 *= ( V_351 * V_214 ) ;
V_350 /= V_291 -> V_267 -> V_215 -> V_216 ;
}
V_349 = F_125 ( V_291 -> V_329 - V_291 -> V_211 , V_350 ) ;
* V_210 = F_125 ( V_349 * V_291 -> V_267 -> V_215 -> V_216 ,
( V_291 -> V_211 - V_291 -> V_189 ) * V_291 -> V_304 -> V_215 -> V_216 )
/ V_214 ;
if ( * V_210 < V_291 -> V_341 )
return F_242 ( V_291 , V_191 , V_210 ) ;
}
static struct V_203 *
F_244 ( struct V_186 * V_187 , int V_191 ,
unsigned long * V_210 , enum V_257 V_142 ,
const struct V_315 * V_316 , int * V_317 )
{
struct V_290 V_291 ;
memset ( & V_291 , 0 , sizeof( V_291 ) ) ;
F_239 ( V_187 , V_191 , V_142 , V_316 , V_317 , & V_291 ) ;
if ( ! ( * V_317 ) )
goto V_44;
if ( ( V_142 == V_352 || V_142 == V_278 ) &&
F_241 ( V_187 , & V_291 , V_191 , V_210 ) )
return V_291 . V_267 ;
if ( ! V_291 . V_267 || V_291 . V_338 == 0 )
goto V_353;
V_291 . V_211 = ( V_214 * V_291 . V_333 ) / V_291 . V_334 ;
if ( V_291 . V_326 )
goto V_354;
if ( V_142 == V_278 && V_291 . V_335 &&
! V_291 . V_342 )
goto V_354;
if ( V_291 . V_189 >= V_291 . V_329 )
goto V_353;
if ( V_291 . V_189 >= V_291 . V_211 )
goto V_353;
if ( V_142 == V_352 ) {
if ( ( V_291 . V_337 <= V_291 . V_339 + 1 ) &&
V_291 . V_338 <= V_291 . V_343 )
goto V_353;
} else {
if ( 100 * V_291 . V_329 <= V_187 -> V_199 * V_291 . V_189 )
goto V_353;
}
V_354:
F_243 ( & V_291 , V_191 , V_210 ) ;
return V_291 . V_267 ;
V_353:
if ( F_227 ( & V_291 , V_191 , V_210 ) )
return V_291 . V_267 ;
V_44:
* V_210 = 0 ;
return NULL ;
}
static struct V_1 *
F_245 ( struct V_186 * V_187 , struct V_203 * V_206 ,
enum V_257 V_142 , unsigned long V_210 ,
const struct V_315 * V_316 )
{
struct V_1 * V_267 = NULL , * V_1 ;
unsigned long V_329 = 0 ;
int V_213 ;
F_176 (i, sched_group_cpus(group)) {
unsigned long V_216 = F_169 ( V_213 ) ;
unsigned long V_236 = F_186 ( V_216 ,
V_214 ) ;
unsigned long V_182 ;
if ( ! V_236 )
V_236 = F_236 ( V_187 , V_206 ) ;
if ( ! F_175 ( V_213 , V_316 ) )
continue;
V_1 = F_185 ( V_213 ) ;
V_182 = F_179 ( V_213 ) ;
if ( V_236 && V_1 -> V_55 == 1 && V_182 > V_210 )
continue;
V_182 = ( V_182 * V_214 ) / V_216 ;
if ( V_182 > V_329 ) {
V_329 = V_182 ;
V_267 = V_1 ;
}
}
return V_267 ;
}
static int F_246 ( struct V_186 * V_187 , int V_142 ,
int V_344 , int V_191 )
{
if ( V_142 == V_278 ) {
if ( ( V_187 -> V_112 & V_330 ) && V_344 > V_191 )
return 1 ;
if ( V_355 < V_356 )
return 0 ;
}
return F_44 ( V_187 -> V_262 > V_187 -> V_263 + 2 ) ;
}
static int F_247 ( int V_191 , struct V_1 * V_256 ,
struct V_186 * V_187 , enum V_257 V_142 ,
int * V_317 )
{
int V_357 , V_258 = 0 , V_358 = 0 ;
struct V_203 * V_206 ;
unsigned long V_210 ;
struct V_1 * V_267 ;
unsigned long V_112 ;
struct V_315 * V_316 = F_248 ( V_359 ) ;
F_249 ( V_316 , V_360 ) ;
F_94 ( V_187 , V_361 [ V_142 ] ) ;
V_362:
V_206 = F_244 ( V_187 , V_191 , & V_210 , V_142 ,
V_316 , V_317 ) ;
if ( * V_317 == 0 )
goto V_353;
if ( ! V_206 ) {
F_94 ( V_187 , V_363 [ V_142 ] ) ;
goto V_353;
}
V_267 = F_245 ( V_187 , V_206 , V_142 , V_210 , V_316 ) ;
if ( ! V_267 ) {
F_94 ( V_187 , V_364 [ V_142 ] ) ;
goto V_353;
}
F_193 ( V_267 == V_256 ) ;
F_53 ( V_187 , V_365 [ V_142 ] , V_210 ) ;
V_357 = 0 ;
if ( V_267 -> V_55 > 1 ) {
V_258 = 1 ;
F_250 ( V_112 ) ;
F_251 ( V_256 , V_267 ) ;
V_357 = F_220 ( V_256 , V_191 , V_267 ,
V_210 , V_187 , V_142 , & V_258 ) ;
F_252 ( V_256 , V_267 ) ;
F_253 ( V_112 ) ;
if ( V_357 && V_191 != F_119 () )
F_254 ( V_191 ) ;
if ( F_44 ( V_258 ) ) {
F_255 ( F_11 ( V_267 ) , V_316 ) ;
if ( ! F_256 ( V_316 ) )
goto V_362;
goto V_353;
}
}
if ( ! V_357 ) {
F_94 ( V_187 , V_366 [ V_142 ] ) ;
if ( V_142 != V_278 )
V_187 -> V_262 ++ ;
if ( F_246 ( V_187 , V_142 , F_11 ( V_267 ) , V_191 ) ) {
F_212 ( & V_267 -> V_140 , V_112 ) ;
if ( ! F_175 ( V_191 ,
F_174 ( V_267 -> V_23 ) ) ) {
F_213 ( & V_267 -> V_140 ,
V_112 ) ;
V_258 = 1 ;
goto V_367;
}
if ( ! V_267 -> V_358 ) {
V_267 -> V_358 = 1 ;
V_267 -> V_368 = V_191 ;
V_358 = 1 ;
}
F_213 ( & V_267 -> V_140 , V_112 ) ;
if ( V_358 )
F_257 ( F_11 ( V_267 ) ,
V_369 , V_267 ,
& V_267 -> V_370 ) ;
V_187 -> V_262 = V_187 -> V_263 + 1 ;
}
} else
V_187 -> V_262 = 0 ;
if ( F_86 ( ! V_358 ) ) {
V_187 -> V_371 = V_187 -> V_372 ;
} else {
if ( V_187 -> V_371 < V_187 -> V_373 )
V_187 -> V_371 *= 2 ;
}
goto V_276;
V_353:
F_94 ( V_187 , V_374 [ V_142 ] ) ;
V_187 -> V_262 = 0 ;
V_367:
if ( ( V_258 && V_187 -> V_371 < V_375 ) ||
( V_187 -> V_371 < V_187 -> V_373 ) )
V_187 -> V_371 *= 2 ;
V_357 = 0 ;
V_276:
return V_357 ;
}
static void F_258 ( int V_191 , struct V_1 * V_256 )
{
struct V_186 * V_187 ;
int V_376 = 0 ;
unsigned long V_377 = V_378 + V_379 ;
V_256 -> V_380 = V_256 -> clock ;
if ( V_256 -> V_381 < V_382 )
return;
F_126 ( & V_256 -> V_140 ) ;
F_214 ( V_191 ) ;
F_134 () ;
F_182 (this_cpu, sd) {
unsigned long V_383 ;
int V_317 = 1 ;
if ( ! ( V_187 -> V_112 & V_233 ) )
continue;
if ( V_187 -> V_112 & V_384 ) {
V_376 = F_247 ( V_191 , V_256 ,
V_187 , V_278 , & V_317 ) ;
}
V_383 = F_259 ( V_187 -> V_371 ) ;
if ( F_260 ( V_377 , V_187 -> V_385 + V_383 ) )
V_377 = V_187 -> V_385 + V_383 ;
if ( V_376 ) {
V_256 -> V_380 = 0 ;
break;
}
}
F_136 () ;
F_123 ( & V_256 -> V_140 ) ;
if ( V_376 || F_260 ( V_378 , V_256 -> V_377 ) ) {
V_256 -> V_377 = V_377 ;
}
}
static int V_369 ( void * V_151 )
{
struct V_1 * V_386 = V_151 ;
int V_344 = F_11 ( V_386 ) ;
int V_387 = V_386 -> V_368 ;
struct V_1 * V_388 = F_185 ( V_387 ) ;
struct V_186 * V_187 ;
F_261 ( & V_386 -> V_140 ) ;
if ( F_44 ( V_344 != F_119 () ||
! V_386 -> V_358 ) )
goto V_164;
if ( V_386 -> V_55 <= 1 )
goto V_164;
F_193 ( V_386 == V_388 ) ;
F_262 ( V_386 , V_388 ) ;
F_134 () ;
F_182 (target_cpu, sd) {
if ( ( V_187 -> V_112 & V_233 ) &&
F_175 ( V_344 , F_187 ( V_187 ) ) )
break;
}
if ( F_86 ( V_187 ) ) {
F_94 ( V_187 , V_389 ) ;
if ( F_206 ( V_388 , V_387 , V_386 ,
V_187 , V_352 ) )
F_94 ( V_187 , V_390 ) ;
else
F_94 ( V_187 , V_391 ) ;
}
F_136 () ;
F_263 ( V_386 , V_388 ) ;
V_164:
V_386 -> V_358 = 0 ;
F_264 ( & V_386 -> V_140 ) ;
return 0 ;
}
int F_265 ( void )
{
return F_80 ( & V_392 . V_393 ) ;
}
static inline struct V_186 * F_266 ( int V_181 , int V_394 )
{
struct V_186 * V_187 ;
F_182 (cpu, sd)
if ( V_187 -> V_112 & V_394 )
break;
return V_187 ;
}
static inline int F_267 ( struct V_203 * V_395 )
{
F_268 ( V_392 . V_396 , V_392 . V_397 ,
F_173 ( V_395 ) ) ;
if ( F_256 ( V_392 . V_396 ) )
return 0 ;
if ( F_269 ( V_392 . V_396 , F_173 ( V_395 ) ) )
return 0 ;
return 1 ;
}
static int F_270 ( int V_181 )
{
struct V_186 * V_187 ;
struct V_203 * V_395 ;
int V_398 = V_399 ;
if ( ! ( V_400 || V_355 ) )
goto V_401;
if ( F_271 ( V_392 . V_397 ) < 2 )
goto V_401;
F_134 () ;
F_272 (cpu, sd, SD_POWERSAVINGS_BALANCE) {
V_395 = V_187 -> V_207 ;
do {
if ( F_267 ( V_395 ) ) {
V_398 = F_223 ( V_392 . V_396 ) ;
goto V_238;
}
V_395 = V_395 -> V_36 ;
} while ( V_395 != V_187 -> V_207 );
}
V_238:
F_136 () ;
V_401:
return V_398 ;
}
static inline int F_270 ( int V_402 )
{
return V_399 ;
}
static void F_273 ( int V_181 )
{
int V_403 ;
V_392 . V_377 ++ ;
V_403 = F_265 () ;
if ( V_403 >= V_399 ) {
V_403 = F_223 ( V_392 . V_397 ) ;
if ( V_403 >= V_399 )
return;
}
if ( ! F_185 ( V_403 ) -> V_404 ) {
F_185 ( V_403 ) -> V_404 = 1 ;
F_274 () ;
F_275 ( V_403 ) ;
}
return;
}
void F_276 ( int V_405 )
{
int V_181 = F_119 () ;
if ( V_405 ) {
if ( ! F_277 ( V_181 ) ) {
if ( F_80 ( & V_392 . V_393 ) != V_181 )
return;
if ( F_278 ( & V_392 . V_393 , V_181 ,
V_399 ) != V_181 )
F_279 () ;
return;
}
F_280 ( V_181 , V_392 . V_397 ) ;
if ( F_80 ( & V_392 . V_406 ) == V_181 )
F_278 ( & V_392 . V_406 , V_181 , V_399 ) ;
if ( F_80 ( & V_392 . V_407 ) == V_181 )
F_278 ( & V_392 . V_407 , V_181 , V_399 ) ;
if ( F_80 ( & V_392 . V_393 ) >= V_399 ) {
int V_408 ;
if ( F_278 ( & V_392 . V_393 , V_399 ,
V_181 ) != V_399 )
return;
V_408 = F_270 ( V_181 ) ;
if ( V_408 < V_399 && V_408 != V_181 ) {
F_281 ( & V_392 . V_393 , V_399 ) ;
F_254 ( V_408 ) ;
return;
}
return;
}
} else {
if ( ! F_175 ( V_181 , V_392 . V_397 ) )
return;
F_255 ( V_181 , V_392 . V_397 ) ;
if ( F_80 ( & V_392 . V_393 ) == V_181 )
if ( F_278 ( & V_392 . V_393 , V_181 ,
V_399 ) != V_181 )
F_279 () ;
}
return;
}
static void F_282 ( void )
{
V_409 = V_379 * F_283 () / 10 ;
}
static void F_284 ( int V_181 , enum V_257 V_142 )
{
int V_317 = 1 ;
struct V_1 * V_1 = F_185 ( V_181 ) ;
unsigned long V_383 ;
struct V_186 * V_187 ;
unsigned long V_377 = V_378 + 60 * V_379 ;
int V_410 = 0 ;
int V_411 ;
F_214 ( V_181 ) ;
F_134 () ;
F_182 (cpu, sd) {
if ( ! ( V_187 -> V_112 & V_233 ) )
continue;
V_383 = V_187 -> V_371 ;
if ( V_142 != V_352 )
V_383 *= V_187 -> V_412 ;
V_383 = F_259 ( V_383 ) ;
V_383 = F_285 ( V_383 , 1UL , V_409 ) ;
V_411 = V_187 -> V_112 & V_413 ;
if ( V_411 ) {
if ( ! F_286 ( & V_414 ) )
goto V_276;
}
if ( F_287 ( V_378 , V_187 -> V_385 + V_383 ) ) {
if ( F_247 ( V_181 , V_1 , V_187 , V_142 , & V_317 ) ) {
V_142 = V_286 ;
}
V_187 -> V_385 = V_378 ;
}
if ( V_411 )
F_288 ( & V_414 ) ;
V_276:
if ( F_260 ( V_377 , V_187 -> V_385 + V_383 ) ) {
V_377 = V_187 -> V_385 + V_383 ;
V_410 = 1 ;
}
if ( ! V_317 )
break;
}
F_136 () ;
if ( F_86 ( V_410 ) )
V_1 -> V_377 = V_377 ;
}
static void F_289 ( int V_191 , enum V_257 V_142 )
{
struct V_1 * V_256 = F_185 ( V_191 ) ;
struct V_1 * V_1 ;
int V_321 ;
if ( V_142 != V_352 || ! V_256 -> V_404 )
return;
F_176 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_321 == V_191 )
continue;
if ( F_290 () ) {
V_256 -> V_404 = 0 ;
break;
}
F_261 ( & V_256 -> V_140 ) ;
F_138 ( V_256 ) ;
F_291 ( V_256 ) ;
F_264 ( & V_256 -> V_140 ) ;
F_284 ( V_321 , V_352 ) ;
V_1 = F_185 ( V_321 ) ;
if ( F_260 ( V_256 -> V_377 , V_1 -> V_377 ) )
V_256 -> V_377 = V_1 -> V_377 ;
}
V_392 . V_377 = V_256 -> V_377 ;
V_256 -> V_404 = 0 ;
}
static inline int F_292 ( struct V_1 * V_1 , int V_181 )
{
unsigned long V_72 = V_378 ;
int V_44 ;
int V_406 , V_407 ;
if ( F_293 ( V_72 , V_392 . V_377 ) )
return 0 ;
if ( F_181 ( V_181 ) )
return 0 ;
V_406 = F_80 ( & V_392 . V_406 ) ;
V_407 = F_80 ( & V_392 . V_407 ) ;
if ( V_406 < V_399 && V_406 != V_181 &&
V_407 < V_399 && V_407 != V_181 )
return 0 ;
V_44 = F_278 ( & V_392 . V_406 , V_399 , V_181 ) ;
if ( V_44 == V_399 || V_44 == V_181 ) {
F_278 ( & V_392 . V_407 , V_181 , V_399 ) ;
if ( V_1 -> V_55 > 1 )
return 1 ;
} else {
V_44 = F_278 ( & V_392 . V_407 , V_399 , V_181 ) ;
if ( V_44 == V_399 || V_44 == V_181 ) {
if ( V_1 -> V_55 )
return 1 ;
}
}
return 0 ;
}
static void F_289 ( int V_191 , enum V_257 V_142 ) { }
static void F_294 ( struct V_415 * V_416 )
{
int V_191 = F_119 () ;
struct V_1 * V_256 = F_185 ( V_191 ) ;
enum V_257 V_142 = V_256 -> F_258 ?
V_352 : V_286 ;
F_284 ( V_191 , V_142 ) ;
F_289 ( V_191 , V_142 ) ;
}
static inline int F_295 ( int V_181 )
{
return ! F_296 ( F_185 ( V_181 ) -> V_187 ) ;
}
static inline void F_297 ( struct V_1 * V_1 , int V_181 )
{
if ( F_287 ( V_378 , V_1 -> V_377 ) &&
F_86 ( ! F_295 ( V_181 ) ) )
F_298 ( V_417 ) ;
#ifdef F_299
else if ( F_292 ( V_1 , V_181 ) && F_86 ( ! F_295 ( V_181 ) ) )
F_273 ( V_181 ) ;
#endif
}
static void F_300 ( struct V_1 * V_1 )
{
F_301 () ;
}
static void F_302 ( struct V_1 * V_1 )
{
F_301 () ;
}
static inline void F_258 ( int V_181 , struct V_1 * V_1 )
{
}
static void F_303 ( struct V_1 * V_1 , struct V_3 * V_23 , int V_125 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_23 -> V_5 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_112 ( V_2 , V_5 , V_125 ) ;
}
}
static void F_304 ( struct V_3 * V_6 )
{
struct V_2 * V_2 = F_7 ( V_196 ) ;
struct V_4 * V_5 = & V_6 -> V_5 , * V_23 = V_2 -> V_23 ;
int V_191 = F_119 () ;
struct V_1 * V_1 = V_256 () ;
unsigned long V_112 ;
F_212 ( & V_1 -> V_140 , V_112 ) ;
F_138 ( V_1 ) ;
if ( F_44 ( F_166 ( V_6 ) != V_191 ) ) {
F_134 () ;
F_305 ( V_6 , V_191 ) ;
F_136 () ;
}
F_54 ( V_2 ) ;
if ( V_23 )
V_5 -> V_19 = V_23 -> V_19 ;
F_95 ( V_2 , V_5 , 1 ) ;
if ( V_418 && V_23 && F_23 ( V_23 , V_5 ) ) {
F_306 ( V_23 -> V_19 , V_5 -> V_19 ) ;
F_106 ( V_1 -> V_23 ) ;
}
V_5 -> V_19 -= V_2 -> V_18 ;
F_213 ( & V_1 -> V_140 , V_112 ) ;
}
static void
F_307 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_419 )
{
if ( ! V_6 -> V_5 . V_59 )
return;
if ( V_1 -> V_23 == V_6 ) {
if ( V_6 -> V_420 > V_419 )
F_106 ( V_1 -> V_23 ) ;
} else
F_202 ( V_1 , V_6 , 0 ) ;
}
static void F_308 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( ! V_5 -> V_59 && V_6 -> V_117 != V_421 ) {
F_95 ( V_2 , V_5 , 0 ) ;
V_5 -> V_19 -= V_2 -> V_18 ;
}
}
static void F_309 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
if ( ! V_6 -> V_5 . V_59 )
return;
if ( V_1 -> V_23 == V_6 )
F_106 ( V_1 -> V_23 ) ;
else
F_202 ( V_1 , V_6 , 0 ) ;
}
static void F_310 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = & V_1 -> V_23 -> V_5 ;
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_107 ( V_2 , V_5 ) ;
F_58 ( V_2 , 0 ) ;
}
}
static void F_311 ( struct V_3 * V_6 , int V_59 )
{
if ( ! V_59 )
V_6 -> V_5 . V_19 -= F_8 ( & V_6 -> V_5 ) -> V_18 ;
F_312 ( V_6 , F_166 ( V_6 ) ) ;
if ( ! V_59 )
V_6 -> V_5 . V_19 += F_8 ( & V_6 -> V_5 ) -> V_18 ;
}
static unsigned int F_313 ( struct V_1 * V_1 , struct V_3 * V_422 )
{
struct V_4 * V_5 = & V_422 -> V_5 ;
unsigned int V_423 = 0 ;
if ( V_1 -> V_17 . V_52 . V_53 )
V_423 = F_314 ( F_47 ( & V_1 -> V_17 , V_5 ) ) ;
return V_423 ;
}
static void F_315 ( struct V_424 * V_425 , int V_181 )
{
struct V_2 * V_2 ;
F_134 () ;
F_207 (cpu_rq(cpu), cfs_rq)
F_316 ( V_425 , V_181 , V_2 ) ;
F_136 () ;
}
