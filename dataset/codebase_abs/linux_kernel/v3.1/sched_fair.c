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
}
static inline void
F_58 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_51 ( V_5 -> V_64 . V_76 , F_1 ( V_2 ) -> clock ) ;
}
static void F_59 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_23 )
F_58 ( V_2 , V_5 ) ;
}
static void
F_60 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_51 ( V_5 -> V_64 . V_77 , F_52 ( V_5 -> V_64 . V_77 ,
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ) ;
F_51 ( V_5 -> V_64 . V_78 , V_5 -> V_64 . V_78 + 1 ) ;
F_51 ( V_5 -> V_64 . V_79 , V_5 -> V_64 . V_79 +
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ;
#ifdef F_61
if ( F_5 ( V_5 ) ) {
F_62 ( F_2 ( V_5 ) ,
F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_76 ) ;
}
#endif
F_51 ( V_5 -> V_64 . V_76 , 0 ) ;
}
static inline void
F_63 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 != V_2 -> V_23 )
F_60 ( V_2 , V_5 ) ;
}
static inline void
F_64 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_74 = F_1 ( V_2 ) -> V_73 ;
}
static void
F_65 ( struct V_2 * V_2 , unsigned long V_53 )
{
V_2 -> V_80 += V_53 ;
}
static inline void
F_65 ( struct V_2 * V_2 , unsigned long V_53 )
{
}
static void
F_66 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_48 ( & V_2 -> V_52 , V_5 -> V_52 . V_53 ) ;
if ( ! F_17 ( V_5 ) )
F_67 ( F_1 ( V_2 ) , V_5 -> V_52 . V_53 ) ;
if ( F_5 ( V_5 ) ) {
F_65 ( V_2 , V_5 -> V_52 . V_53 ) ;
F_68 ( & V_5 -> V_81 , & V_2 -> V_82 ) ;
}
V_2 -> V_55 ++ ;
}
static void
F_69 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_70 ( & V_2 -> V_52 , V_5 -> V_52 . V_53 ) ;
if ( ! F_17 ( V_5 ) )
F_71 ( F_1 ( V_2 ) , V_5 -> V_52 . V_53 ) ;
if ( F_5 ( V_5 ) ) {
F_65 ( V_2 , - V_5 -> V_52 . V_53 ) ;
F_72 ( & V_5 -> V_81 ) ;
}
V_2 -> V_55 -- ;
}
static void F_73 ( struct V_2 * V_2 ,
int V_83 )
{
struct V_84 * V_10 = V_2 -> V_10 ;
long V_85 ;
V_85 = F_74 ( V_2 -> V_85 , V_2 -> V_86 + 1 ) ;
V_85 -= V_2 -> V_87 ;
if ( V_83 || abs ( V_85 ) > V_2 -> V_87 / 8 ) {
F_75 ( V_85 , & V_10 -> V_60 ) ;
V_2 -> V_87 += V_85 ;
}
}
static void F_76 ( struct V_2 * V_2 , int V_83 )
{
T_1 V_56 = V_88 ;
T_1 V_72 , V_20 ;
unsigned long V_52 = V_2 -> V_52 . V_53 ;
if ( V_2 -> V_10 == & V_89 )
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
F_73 ( V_2 , V_83 ) ;
while ( V_2 -> V_86 > V_56 ) {
asm("" : "+rm" (cfs_rq->load_period));
V_2 -> V_86 /= 2 ;
V_2 -> V_85 /= 2 ;
}
if ( ! V_2 -> V_23 && ! V_2 -> V_55 && ! V_2 -> V_85 )
F_14 ( V_2 ) ;
}
static long F_77 ( struct V_2 * V_2 , struct V_84 * V_10 )
{
long V_60 , V_52 , V_92 ;
V_52 = V_2 -> V_52 . V_53 ;
V_60 = F_78 ( & V_10 -> V_60 ) ;
V_60 += V_52 ;
V_60 -= V_2 -> V_87 ;
V_92 = ( V_10 -> V_92 * V_52 ) ;
if ( V_60 )
V_92 /= V_60 ;
if ( V_92 < V_93 )
V_92 = V_93 ;
if ( V_92 > V_10 -> V_92 )
V_92 = V_10 -> V_92 ;
return V_92 ;
}
static void F_79 ( struct V_2 * V_2 )
{
if ( V_2 -> V_71 > V_88 ) {
F_76 ( V_2 , 0 ) ;
F_80 ( V_2 ) ;
}
}
static void F_76 ( struct V_2 * V_2 , int V_83 )
{
}
static inline long F_77 ( struct V_2 * V_2 , struct V_84 * V_10 )
{
return V_10 -> V_92 ;
}
static inline void F_79 ( struct V_2 * V_2 )
{
}
static void F_81 ( struct V_2 * V_2 , struct V_4 * V_5 ,
unsigned long V_53 )
{
if ( V_5 -> V_59 ) {
if ( V_2 -> V_23 == V_5 )
F_54 ( V_2 ) ;
F_69 ( V_2 , V_5 ) ;
}
F_82 ( & V_5 -> V_52 , V_53 ) ;
if ( V_5 -> V_59 )
F_66 ( V_2 , V_5 ) ;
}
static void F_80 ( struct V_2 * V_2 )
{
struct V_84 * V_10 ;
struct V_4 * V_5 ;
long V_92 ;
V_10 = V_2 -> V_10 ;
V_5 = V_10 -> V_5 [ F_11 ( F_1 ( V_2 ) ) ] ;
if ( ! V_5 )
return;
#ifndef V_69
if ( F_83 ( V_5 -> V_52 . V_53 == V_10 -> V_92 ) )
return;
#endif
V_92 = F_77 ( V_2 , V_10 ) ;
F_81 ( F_8 ( V_5 ) , V_5 , V_92 ) ;
}
static void F_76 ( struct V_2 * V_2 , int V_83 )
{
}
static inline void F_80 ( struct V_2 * V_2 )
{
}
static inline void F_79 ( struct V_2 * V_2 )
{
}
static void F_84 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
#ifdef F_61
struct V_3 * V_94 = NULL ;
if ( F_5 ( V_5 ) )
V_94 = F_2 ( V_5 ) ;
if ( V_5 -> V_64 . V_95 ) {
T_1 V_20 = F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_95 ;
if ( ( T_2 ) V_20 < 0 )
V_20 = 0 ;
if ( F_44 ( V_20 > V_5 -> V_64 . V_96 ) )
V_5 -> V_64 . V_96 = V_20 ;
V_5 -> V_64 . V_95 = 0 ;
V_5 -> V_64 . V_97 += V_20 ;
if ( V_94 ) {
F_85 ( V_94 , V_20 >> 10 , 1 ) ;
F_86 ( V_94 , V_20 ) ;
}
}
if ( V_5 -> V_64 . V_98 ) {
T_1 V_20 = F_1 ( V_2 ) -> clock - V_5 -> V_64 . V_98 ;
if ( ( T_2 ) V_20 < 0 )
V_20 = 0 ;
if ( F_44 ( V_20 > V_5 -> V_64 . V_99 ) )
V_5 -> V_64 . V_99 = V_20 ;
V_5 -> V_64 . V_98 = 0 ;
V_5 -> V_64 . V_97 += V_20 ;
if ( V_94 ) {
if ( V_94 -> V_100 ) {
V_5 -> V_64 . V_101 += V_20 ;
V_5 -> V_64 . V_102 ++ ;
F_87 ( V_94 , V_20 ) ;
}
if ( F_44 ( V_103 == V_104 ) ) {
F_88 ( V_104 ,
( void * ) F_89 ( V_94 ) ,
V_20 >> 20 ) ;
}
F_85 ( V_94 , V_20 >> 10 , 0 ) ;
}
}
#endif
}
static void F_90 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
#ifdef F_3
T_2 V_105 = V_5 -> V_19 - V_2 -> V_18 ;
if ( V_105 < 0 )
V_105 = - V_105 ;
if ( V_105 > 3 * V_47 )
F_91 ( V_2 , V_106 ) ;
#endif
}
static void
F_92 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_107 )
{
T_1 V_19 = V_2 -> V_18 ;
if ( V_107 && F_93 ( V_108 ) )
V_19 += F_49 ( V_2 , V_5 ) ;
if ( ! V_107 ) {
unsigned long V_109 = V_47 ;
if ( F_93 ( V_110 ) )
V_109 >>= 1 ;
V_19 -= V_109 ;
}
V_19 = F_22 ( V_5 -> V_19 , V_19 ) ;
V_5 -> V_19 = V_19 ;
}
static void
F_94 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_111 )
{
if ( ! ( V_111 & V_112 ) || ( V_111 & V_113 ) )
V_5 -> V_19 += V_2 -> V_18 ;
F_54 ( V_2 ) ;
F_76 ( V_2 , 0 ) ;
F_66 ( V_2 , V_5 ) ;
F_80 ( V_2 ) ;
if ( V_111 & V_112 ) {
F_92 ( V_2 , V_5 , 0 ) ;
F_84 ( V_2 , V_5 ) ;
}
F_59 ( V_2 , V_5 ) ;
F_90 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_23 )
F_28 ( V_2 , V_5 ) ;
V_5 -> V_59 = 1 ;
if ( V_2 -> V_55 == 1 )
F_10 ( V_2 ) ;
}
static void F_95 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_37 == V_5 )
V_2 -> V_37 = NULL ;
else
break;
}
}
static void F_96 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_36 == V_5 )
V_2 -> V_36 = NULL ;
else
break;
}
}
static void F_97 ( struct V_4 * V_5 )
{
F_19 (se) {
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( V_2 -> V_114 == V_5 )
V_2 -> V_114 = NULL ;
else
break;
}
}
static void F_98 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_2 -> V_37 == V_5 )
F_95 ( V_5 ) ;
if ( V_2 -> V_36 == V_5 )
F_96 ( V_5 ) ;
if ( V_2 -> V_114 == V_5 )
F_97 ( V_5 ) ;
}
static void
F_99 ( struct V_2 * V_2 , struct V_4 * V_5 , int V_111 )
{
F_54 ( V_2 ) ;
F_63 ( V_2 , V_5 ) ;
if ( V_111 & V_115 ) {
#ifdef F_61
if ( F_5 ( V_5 ) ) {
struct V_3 * V_94 = F_2 ( V_5 ) ;
if ( V_94 -> V_116 & V_117 )
V_5 -> V_64 . V_95 = F_1 ( V_2 ) -> clock ;
if ( V_94 -> V_116 & V_118 )
V_5 -> V_64 . V_98 = F_1 ( V_2 ) -> clock ;
}
#endif
}
F_98 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_23 )
F_31 ( V_2 , V_5 ) ;
V_5 -> V_59 = 0 ;
F_76 ( V_2 , 0 ) ;
F_69 ( V_2 , V_5 ) ;
if ( ! ( V_111 & V_115 ) )
V_5 -> V_19 -= V_2 -> V_18 ;
F_24 ( V_2 ) ;
F_80 ( V_2 ) ;
}
static void
F_100 ( struct V_2 * V_2 , struct V_4 * V_23 )
{
unsigned long V_119 , V_62 ;
V_119 = F_47 ( V_2 , V_23 ) ;
V_62 = V_23 -> V_66 - V_23 -> V_120 ;
if ( V_62 > V_119 ) {
F_101 ( F_1 ( V_2 ) -> V_23 ) ;
F_98 ( V_2 , V_23 ) ;
return;
}
if ( ! F_93 ( V_121 ) )
return;
if ( V_62 < V_48 )
return;
if ( V_2 -> V_55 > 1 ) {
struct V_4 * V_5 = F_34 ( V_2 ) ;
T_2 V_20 = V_23 -> V_19 - V_5 -> V_19 ;
if ( V_20 < 0 )
return;
if ( V_20 > V_119 )
F_101 ( F_1 ( V_2 ) -> V_23 ) ;
}
}
static void
F_102 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_59 ) {
F_60 ( V_2 , V_5 ) ;
F_31 ( V_2 , V_5 ) ;
}
F_64 ( V_2 , V_5 ) ;
V_2 -> V_23 = V_5 ;
#ifdef F_61
if ( F_1 ( V_2 ) -> V_52 . V_53 >= 2 * V_5 -> V_52 . V_53 ) {
V_5 -> V_64 . V_122 = F_52 ( V_5 -> V_64 . V_122 ,
V_5 -> V_66 - V_5 -> V_120 ) ;
}
#endif
V_5 -> V_120 = V_5 -> V_66 ;
}
static struct V_4 * F_103 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_34 ( V_2 ) ;
struct V_4 * V_35 = V_5 ;
if ( V_2 -> V_114 == V_5 ) {
struct V_4 * V_123 = F_35 ( V_5 ) ;
if ( V_123 && F_104 ( V_123 , V_35 ) < 1 )
V_5 = V_123 ;
}
if ( V_2 -> V_37 && F_104 ( V_2 -> V_37 , V_35 ) < 1 )
V_5 = V_2 -> V_37 ;
if ( V_2 -> V_36 && F_104 ( V_2 -> V_36 , V_35 ) < 1 )
V_5 = V_2 -> V_36 ;
F_98 ( V_2 , V_5 ) ;
return V_5 ;
}
static void F_105 ( struct V_2 * V_2 , struct V_4 * V_124 )
{
if ( V_124 -> V_59 )
F_54 ( V_2 ) ;
F_90 ( V_2 , V_124 ) ;
if ( V_124 -> V_59 ) {
F_58 ( V_2 , V_124 ) ;
F_28 ( V_2 , V_124 ) ;
}
V_2 -> V_23 = NULL ;
}
static void
F_106 ( struct V_2 * V_2 , struct V_4 * V_23 , int V_125 )
{
F_54 ( V_2 ) ;
F_79 ( V_2 ) ;
#ifdef F_107
if ( V_125 ) {
F_101 ( F_1 ( V_2 ) -> V_23 ) ;
return;
}
if ( ! F_93 ( V_126 ) &&
F_108 ( & F_1 ( V_2 ) -> V_127 ) )
return;
#endif
if ( V_2 -> V_55 > 1 || ! F_93 ( V_121 ) )
F_100 ( V_2 , V_23 ) ;
}
static void F_109 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
F_110 ( F_21 ( V_6 ) != V_1 ) ;
if ( F_111 ( V_1 ) && V_2 -> V_55 > 1 ) {
T_1 V_58 = F_47 ( V_2 , V_5 ) ;
T_1 V_128 = V_5 -> V_66 - V_5 -> V_120 ;
T_2 V_20 = V_58 - V_128 ;
if ( V_20 < 0 ) {
if ( V_1 -> V_23 == V_6 )
F_101 ( V_6 ) ;
return;
}
if ( V_1 -> V_23 != V_6 )
V_20 = F_112 ( T_2 , 10000LL , V_20 ) ;
F_113 ( V_1 , V_20 ) ;
}
}
static void F_114 ( struct V_1 * V_1 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
if ( V_23 -> V_129 != & V_130 )
return;
if ( F_8 ( & V_23 -> V_5 ) -> V_55 < V_46 )
F_109 ( V_1 , V_23 ) ;
}
static inline void
F_109 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
}
static inline void F_114 ( struct V_1 * V_1 )
{
}
static void
F_115 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_111 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
F_19 (se) {
if ( V_5 -> V_59 )
break;
V_2 = F_8 ( V_5 ) ;
F_94 ( V_2 , V_5 , V_111 ) ;
V_111 = V_112 ;
}
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_76 ( V_2 , 0 ) ;
F_80 ( V_2 ) ;
}
F_114 ( V_1 ) ;
}
static void F_116 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_111 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
int V_131 = V_111 & V_115 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_99 ( V_2 , V_5 , V_111 ) ;
if ( V_2 -> V_52 . V_53 ) {
if ( V_131 && F_17 ( V_5 ) )
F_117 ( F_17 ( V_5 ) ) ;
V_5 = F_17 ( V_5 ) ;
break;
}
V_111 |= V_115 ;
}
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_76 ( V_2 , 0 ) ;
F_80 ( V_2 ) ;
}
F_114 ( V_1 ) ;
}
static void F_118 ( struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
T_1 V_18 ;
#ifndef F_26
T_1 V_26 ;
do {
V_26 = V_2 -> V_26 ;
F_119 () ;
V_18 = V_2 -> V_18 ;
} while ( V_18 != V_26 );
#else
V_18 = V_2 -> V_18 ;
#endif
V_5 -> V_19 -= V_18 ;
}
static long F_120 ( struct V_84 * V_10 , int V_132 , long V_133 , long V_134 )
{
struct V_4 * V_5 = V_10 -> V_5 [ V_132 ] ;
if ( ! V_10 -> V_11 )
return V_133 ;
F_19 (se) {
long V_61 , V_135 ;
V_10 = V_5 -> V_8 -> V_10 ;
V_135 = V_5 -> V_8 -> V_52 . V_53 ;
V_61 = F_78 ( & V_10 -> V_60 ) ;
V_61 -= V_5 -> V_8 -> V_87 ;
V_61 += V_135 + V_134 ;
V_133 += V_135 ;
if ( V_61 > 0 && V_133 < V_61 )
V_133 = ( V_133 * V_10 -> V_92 ) / V_61 ;
else
V_133 = V_10 -> V_92 ;
if ( V_133 < V_93 )
V_133 = V_93 ;
V_133 -= V_5 -> V_52 . V_53 ;
V_134 = 0 ;
}
return V_133 ;
}
static inline unsigned long F_120 ( struct V_84 * V_10 , int V_132 ,
unsigned long V_133 , unsigned long V_134 )
{
return V_133 ;
}
static int F_121 ( struct V_136 * V_137 , struct V_3 * V_6 , int V_138 )
{
T_2 V_139 , V_52 ;
int V_140 , V_141 , V_142 ;
unsigned long V_143 ;
struct V_84 * V_10 ;
unsigned long V_53 ;
int V_144 ;
V_140 = V_137 -> V_145 ;
V_141 = F_122 () ;
V_142 = F_123 ( V_6 ) ;
V_52 = F_124 ( V_142 , V_140 ) ;
V_139 = F_125 ( V_141 , V_140 ) ;
if ( V_138 ) {
V_10 = V_84 ( V_146 ) ;
V_53 = V_146 -> V_5 . V_52 . V_53 ;
V_139 += F_120 ( V_10 , V_141 , - V_53 , - V_53 ) ;
V_52 += F_120 ( V_10 , V_142 , 0 , - V_53 ) ;
}
V_10 = V_84 ( V_6 ) ;
V_53 = V_6 -> V_5 . V_52 . V_53 ;
if ( V_139 > 0 ) {
T_2 V_147 , V_148 ;
V_147 = 100 ;
V_147 *= F_126 ( V_142 ) ;
V_147 *= V_139 +
F_120 ( V_10 , V_141 , V_53 , V_53 ) ;
V_148 = 100 + ( V_137 -> V_149 - 100 ) / 2 ;
V_148 *= F_126 ( V_141 ) ;
V_148 *= V_52 + F_120 ( V_10 , V_142 , 0 , V_53 ) ;
V_144 = V_147 <= V_148 ;
} else
V_144 = true ;
if ( V_138 && V_144 )
return 1 ;
F_91 ( V_6 , V_5 . V_64 . V_150 ) ;
V_143 = F_127 ( V_141 ) ;
if ( V_144 ||
( V_139 <= V_52 &&
V_139 + F_125 ( V_142 , V_140 ) <= V_143 ) ) {
F_91 ( V_137 , V_151 ) ;
F_91 ( V_6 , V_5 . V_64 . V_152 ) ;
return 1 ;
}
return 0 ;
}
static struct V_153 *
F_128 ( struct V_136 * V_137 , struct V_3 * V_6 ,
int V_141 , int V_154 )
{
struct V_153 * V_155 = NULL , * V_156 = V_137 -> V_157 ;
unsigned long V_158 = V_159 , V_139 = 0 ;
int V_160 = 100 + ( V_137 -> V_149 - 100 ) / 2 ;
do {
unsigned long V_52 , V_161 ;
int V_162 ;
int V_163 ;
if ( ! F_129 ( F_130 ( V_156 ) ,
& V_6 -> V_164 ) )
continue;
V_162 = F_131 ( V_141 ,
F_130 ( V_156 ) ) ;
V_161 = 0 ;
F_132 (i, sched_group_cpus(group)) {
if ( V_162 )
V_52 = F_124 ( V_163 , V_154 ) ;
else
V_52 = F_125 ( V_163 , V_154 ) ;
V_161 += V_52 ;
}
V_161 = ( V_161 * V_165 ) / V_156 -> V_166 -> V_167 ;
if ( V_162 ) {
V_139 = V_161 ;
} else if ( V_161 < V_158 ) {
V_158 = V_161 ;
V_155 = V_156 ;
}
} while ( V_156 = V_156 -> V_36 , V_156 != V_137 -> V_157 );
if ( ! V_155 || 100 * V_139 < V_160 * V_158 )
return NULL ;
return V_155 ;
}
static int
F_133 ( struct V_153 * V_156 , struct V_3 * V_6 , int V_141 )
{
unsigned long V_52 , V_158 = V_159 ;
int V_155 = - 1 ;
int V_163 ;
F_134 (i, sched_group_cpus(group), &p->cpus_allowed) {
V_52 = F_135 ( V_163 ) ;
if ( V_52 < V_158 || ( V_52 == V_158 && V_163 == V_141 ) ) {
V_158 = V_52 ;
V_155 = V_163 ;
}
}
return V_155 ;
}
static int F_136 ( struct V_3 * V_6 , int V_168 )
{
int V_132 = F_122 () ;
int V_142 = F_123 ( V_6 ) ;
struct V_136 * V_137 ;
int V_163 ;
if ( V_168 == V_132 && F_137 ( V_132 ) )
return V_132 ;
if ( V_168 == V_142 && F_137 ( V_142 ) )
return V_142 ;
F_138 () ;
F_139 (target, sd) {
if ( ! ( V_137 -> V_111 & V_169 ) )
break;
F_134 (i, sched_domain_span(sd), &p->cpus_allowed) {
if ( F_137 ( V_163 ) ) {
V_168 = V_163 ;
break;
}
}
if ( F_131 ( V_132 , F_140 ( V_137 ) ) &&
F_131 ( V_142 , F_140 ( V_137 ) ) )
break;
}
F_141 () ;
return V_168 ;
}
static int
F_142 ( struct V_3 * V_6 , int V_170 , int V_171 )
{
struct V_136 * V_172 , * V_173 = NULL , * V_137 = NULL ;
int V_132 = F_122 () ;
int V_142 = F_123 ( V_6 ) ;
int V_174 = V_132 ;
int V_175 = 0 ;
int V_176 = 1 ;
int V_138 = V_171 & V_177 ;
if ( V_170 & V_178 ) {
if ( F_131 ( V_132 , & V_6 -> V_164 ) )
V_175 = 1 ;
V_174 = V_142 ;
}
F_138 () ;
F_139 (cpu, tmp) {
if ( ! ( V_172 -> V_111 & V_179 ) )
continue;
if ( V_172 -> V_111 & ( V_180 | V_181 ) ) {
unsigned long V_167 = 0 ;
unsigned long V_55 = 0 ;
unsigned long V_182 ;
int V_163 ;
F_132 (i, sched_domain_span(tmp)) {
V_167 += F_126 ( V_163 ) ;
V_55 += F_143 ( V_163 ) -> V_17 . V_55 ;
}
V_182 = F_144 ( V_167 , V_165 ) ;
if ( V_172 -> V_111 & V_180 )
V_55 /= 2 ;
if ( V_55 < V_182 )
V_176 = 0 ;
}
if ( V_175 && ( V_172 -> V_111 & V_183 ) &&
F_131 ( V_142 , F_140 ( V_172 ) ) ) {
V_173 = V_172 ;
V_175 = 0 ;
}
if ( ! V_176 && ! V_175 )
break;
if ( ! ( V_172 -> V_111 & V_170 ) )
continue;
if ( V_176 )
V_137 = V_172 ;
}
if ( V_173 ) {
if ( V_132 == V_142 || F_121 ( V_173 , V_6 , V_138 ) )
V_142 = V_132 ;
V_174 = F_136 ( V_6 , V_142 ) ;
goto V_184;
}
while ( V_137 ) {
int V_154 = V_137 -> V_185 ;
struct V_153 * V_156 ;
int V_53 ;
if ( ! ( V_137 -> V_111 & V_170 ) ) {
V_137 = V_137 -> V_186 ;
continue;
}
if ( V_170 & V_178 )
V_154 = V_137 -> V_145 ;
V_156 = F_128 ( V_137 , V_6 , V_132 , V_154 ) ;
if ( ! V_156 ) {
V_137 = V_137 -> V_186 ;
continue;
}
V_174 = F_133 ( V_156 , V_6 , V_132 ) ;
if ( V_174 == - 1 || V_174 == V_132 ) {
V_137 = V_137 -> V_186 ;
continue;
}
V_132 = V_174 ;
V_53 = V_137 -> V_187 ;
V_137 = NULL ;
F_139 (cpu, tmp) {
if ( V_53 <= V_172 -> V_187 )
break;
if ( V_172 -> V_111 & V_170 )
V_137 = V_172 ;
}
}
V_184:
F_141 () ;
return V_174 ;
}
static unsigned long
F_145 ( struct V_4 * V_23 , struct V_4 * V_5 )
{
unsigned long V_188 = V_189 ;
return F_43 ( V_188 , V_5 ) ;
}
static int
F_104 ( struct V_4 * V_23 , struct V_4 * V_5 )
{
T_2 V_188 , V_190 = V_23 -> V_19 - V_5 -> V_19 ;
if ( V_190 <= 0 )
return - 1 ;
V_188 = F_145 ( V_23 , V_5 ) ;
if ( V_190 > V_188 )
return 1 ;
return 0 ;
}
static void F_146 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_44 ( F_2 ( V_5 ) -> V_191 == V_192 ) )
return;
F_19 (se)
F_8 ( V_5 ) -> V_37 = V_5 ;
}
static void F_117 ( struct V_4 * V_5 )
{
if ( F_5 ( V_5 ) && F_44 ( F_2 ( V_5 ) -> V_191 == V_192 ) )
return;
F_19 (se)
F_8 ( V_5 ) -> V_36 = V_5 ;
}
static void F_147 ( struct V_4 * V_5 )
{
F_19 (se)
F_8 ( V_5 ) -> V_114 = V_5 ;
}
static void F_148 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_171 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
struct V_4 * V_5 = & V_23 -> V_5 , * V_13 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_7 ( V_23 ) ;
int V_193 = V_2 -> V_55 >= V_46 ;
int V_194 = 0 ;
if ( F_44 ( V_5 == V_13 ) )
return;
if ( F_93 ( V_195 ) && V_193 && ! ( V_171 & V_196 ) ) {
F_117 ( V_13 ) ;
V_194 = 1 ;
}
if ( F_149 ( V_23 ) )
return;
if ( F_44 ( V_23 -> V_191 == V_192 ) &&
F_83 ( V_6 -> V_191 != V_192 ) )
goto V_197;
if ( F_44 ( V_6 -> V_191 != V_198 ) )
return;
if ( ! F_93 ( V_121 ) )
return;
F_20 ( & V_5 , & V_13 ) ;
F_54 ( F_8 ( V_5 ) ) ;
F_150 ( ! V_13 ) ;
if ( F_104 ( V_5 , V_13 ) == 1 ) {
if ( ! V_194 )
F_117 ( V_13 ) ;
goto V_197;
}
return;
V_197:
F_101 ( V_23 ) ;
if ( F_44 ( ! V_5 -> V_59 || V_23 == V_1 -> V_199 ) )
return;
if ( F_93 ( V_200 ) && V_193 && F_5 ( V_5 ) )
F_146 ( V_5 ) ;
}
static struct V_3 * F_151 ( struct V_1 * V_1 )
{
struct V_3 * V_6 ;
struct V_2 * V_2 = & V_1 -> V_17 ;
struct V_4 * V_5 ;
if ( ! V_2 -> V_55 )
return NULL ;
do {
V_5 = F_103 ( V_2 ) ;
F_102 ( V_2 , V_5 ) ;
V_2 = F_9 ( V_5 ) ;
} while ( V_2 );
V_6 = F_2 ( V_5 ) ;
F_109 ( V_1 , V_6 ) ;
return V_6 ;
}
static void F_152 ( struct V_1 * V_1 , struct V_3 * V_124 )
{
struct V_4 * V_5 = & V_124 -> V_5 ;
struct V_2 * V_2 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_105 ( V_2 , V_5 ) ;
}
}
static void F_153 ( struct V_1 * V_1 )
{
struct V_3 * V_23 = V_1 -> V_23 ;
struct V_2 * V_2 = F_7 ( V_23 ) ;
struct V_4 * V_5 = & V_23 -> V_5 ;
if ( F_44 ( V_1 -> V_55 == 1 ) )
return;
F_98 ( V_2 , V_5 ) ;
if ( V_23 -> V_191 != V_201 ) {
F_154 ( V_1 ) ;
F_54 ( V_2 ) ;
}
F_147 ( V_5 ) ;
}
static bool F_155 ( struct V_1 * V_1 , struct V_3 * V_6 , bool V_197 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
if ( ! V_5 -> V_59 )
return false ;
F_117 ( V_5 ) ;
F_153 ( V_1 ) ;
return true ;
}
static void F_156 ( struct V_1 * V_202 , struct V_3 * V_6 ,
struct V_1 * V_203 , int V_141 )
{
F_157 ( V_202 , V_6 , 0 ) ;
F_158 ( V_6 , V_141 ) ;
F_159 ( V_203 , V_6 , 0 ) ;
F_160 ( V_203 , V_6 , 0 ) ;
}
static
int F_161 ( struct V_3 * V_6 , struct V_1 * V_1 , int V_141 ,
struct V_136 * V_137 , enum V_204 V_199 ,
int * V_205 )
{
int V_206 = 0 ;
if ( ! F_131 ( V_141 , & V_6 -> V_164 ) ) {
F_91 ( V_6 , V_5 . V_64 . V_207 ) ;
return 0 ;
}
* V_205 = 0 ;
if ( F_162 ( V_1 , V_6 ) ) {
F_91 ( V_6 , V_5 . V_64 . V_208 ) ;
return 0 ;
}
V_206 = F_163 ( V_6 , V_1 -> V_73 , V_137 ) ;
if ( ! V_206 ||
V_137 -> V_209 > V_137 -> V_210 ) {
#ifdef F_61
if ( V_206 ) {
F_91 ( V_137 , V_211 [ V_199 ] ) ;
F_91 ( V_6 , V_5 . V_64 . V_212 ) ;
}
#endif
return 1 ;
}
if ( V_206 ) {
F_91 ( V_6 , V_5 . V_64 . V_213 ) ;
return 0 ;
}
return 1 ;
}
static int
F_164 ( struct V_1 * V_203 , int V_141 , struct V_1 * V_214 ,
struct V_136 * V_137 , enum V_204 V_199 )
{
struct V_3 * V_6 , * V_215 ;
struct V_2 * V_2 ;
int V_216 = 0 ;
F_165 (busiest, cfs_rq) {
F_166 (p, n, &cfs_rq->tasks, se.group_node) {
if ( ! F_161 ( V_6 , V_214 , V_141 ,
V_137 , V_199 , & V_216 ) )
continue;
F_156 ( V_214 , V_6 , V_203 , V_141 ) ;
F_91 ( V_137 , V_217 [ V_199 ] ) ;
return 1 ;
}
}
return 0 ;
}
static unsigned long
F_167 ( struct V_1 * V_203 , int V_141 , struct V_1 * V_214 ,
unsigned long V_218 , struct V_136 * V_137 ,
enum V_204 V_199 , int * V_205 ,
struct V_2 * V_219 )
{
int V_220 = 0 , V_221 = 0 ;
long V_222 = V_218 ;
struct V_3 * V_6 , * V_215 ;
if ( V_218 == 0 )
goto V_223;
F_166 (p, n, &busiest_cfs_rq->tasks, se.group_node) {
if ( V_220 ++ > V_224 )
break;
if ( ( V_6 -> V_5 . V_52 . V_53 >> 1 ) > V_222 ||
! F_161 ( V_6 , V_214 , V_141 , V_137 , V_199 ,
V_205 ) )
continue;
F_156 ( V_214 , V_6 , V_203 , V_141 ) ;
V_221 ++ ;
V_222 -= V_6 -> V_5 . V_52 . V_53 ;
#ifdef F_168
if ( V_199 == V_225 )
break;
#endif
if ( V_222 <= 0 )
break;
}
V_223:
F_53 ( V_137 , V_217 [ V_199 ] , V_221 ) ;
return V_218 - V_222 ;
}
static int F_169 ( struct V_84 * V_10 , int V_132 )
{
struct V_2 * V_2 ;
unsigned long V_111 ;
struct V_1 * V_1 ;
if ( ! V_10 -> V_5 [ V_132 ] )
return 0 ;
V_1 = F_143 ( V_132 ) ;
V_2 = V_10 -> V_2 [ V_132 ] ;
F_170 ( & V_1 -> V_226 , V_111 ) ;
F_154 ( V_1 ) ;
F_76 ( V_2 , 1 ) ;
F_80 ( V_2 ) ;
F_171 ( & V_1 -> V_226 , V_111 ) ;
return 0 ;
}
static void F_172 ( int V_132 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 = F_143 ( V_132 ) ;
F_138 () ;
F_165 (rq, cfs_rq)
F_169 ( V_2 -> V_10 , V_132 ) ;
F_141 () ;
}
static int F_173 ( struct V_84 * V_10 , void * V_227 )
{
unsigned long V_52 ;
long V_132 = ( long ) V_227 ;
if ( ! V_10 -> V_11 ) {
V_52 = F_143 ( V_132 ) -> V_52 . V_53 ;
} else {
V_52 = V_10 -> V_11 -> V_2 [ V_132 ] -> V_228 ;
V_52 *= V_10 -> V_5 [ V_132 ] -> V_52 . V_53 ;
V_52 /= V_10 -> V_11 -> V_2 [ V_132 ] -> V_52 . V_53 + 1 ;
}
V_10 -> V_2 [ V_132 ] -> V_228 = V_52 ;
return 0 ;
}
static void F_174 ( long V_132 )
{
F_175 ( F_173 , V_229 , ( void * ) V_132 ) ;
}
static unsigned long
F_176 ( struct V_1 * V_203 , int V_141 , struct V_1 * V_214 ,
unsigned long V_218 ,
struct V_136 * V_137 , enum V_204 V_199 ,
int * V_205 )
{
long V_222 = V_218 ;
struct V_2 * V_219 ;
F_138 () ;
F_174 ( F_11 ( V_214 ) ) ;
F_165 (busiest, busiest_cfs_rq) {
unsigned long V_230 = V_219 -> V_228 ;
unsigned long V_231 = V_219 -> V_52 . V_53 ;
T_1 V_232 , V_233 ;
if ( ! V_219 -> V_80 )
continue;
V_232 = ( T_1 ) V_222 * V_231 ;
V_232 = F_177 ( V_232 , V_230 + 1 ) ;
V_233 = F_167 ( V_203 , V_141 , V_214 ,
V_232 , V_137 , V_199 , V_205 ,
V_219 ) ;
if ( ! V_233 )
continue;
V_233 *= V_230 ;
V_233 = F_177 ( V_233 , V_231 + 1 ) ;
V_222 -= V_233 ;
if ( V_222 < 0 )
break;
}
F_141 () ;
return V_218 - V_222 ;
}
static inline void F_172 ( int V_132 )
{
}
static unsigned long
F_176 ( struct V_1 * V_203 , int V_141 , struct V_1 * V_214 ,
unsigned long V_218 ,
struct V_136 * V_137 , enum V_204 V_199 ,
int * V_205 )
{
return F_167 ( V_203 , V_141 , V_214 ,
V_218 , V_137 , V_199 , V_205 ,
& V_214 -> V_17 ) ;
}
static int F_178 ( struct V_1 * V_203 , int V_141 , struct V_1 * V_214 ,
unsigned long V_218 ,
struct V_136 * V_137 , enum V_204 V_199 ,
int * V_205 )
{
unsigned long V_234 = 0 , V_235 ;
do {
V_235 = F_176 ( V_203 , V_141 , V_214 ,
V_218 - V_234 ,
V_137 , V_199 , V_205 ) ;
V_234 += V_235 ;
#ifdef F_168
if ( V_199 == V_225 && V_203 -> V_55 )
break;
if ( F_179 ( & V_203 -> V_226 ) ||
F_179 ( & V_214 -> V_226 ) )
break;
#endif
} while ( V_235 && V_218 > V_234 );
return V_234 > 0 ;
}
static inline unsigned int F_180 ( struct V_153 * V_156 )
{
return F_181 ( F_130 ( V_156 ) ) ;
}
static inline int F_182 ( struct V_136 * V_137 ,
enum V_204 V_199 )
{
int V_154 ;
switch ( V_199 ) {
case V_236 :
V_154 = V_137 -> V_237 ;
break;
case V_225 :
V_154 = V_137 -> V_238 ;
break;
default:
V_154 = V_137 -> V_239 ;
break;
}
return V_154 ;
}
static inline void F_183 ( struct V_136 * V_137 ,
struct V_240 * V_241 , enum V_204 V_199 )
{
if ( V_199 == V_236 || ! ( V_137 -> V_111 & V_180 ) )
V_241 -> V_242 = 0 ;
else {
V_241 -> V_242 = 1 ;
V_241 -> V_243 = V_159 ;
V_241 -> V_244 = 0 ;
}
}
static inline void F_184 ( struct V_153 * V_156 ,
struct V_240 * V_241 , int V_162 , struct V_245 * V_246 )
{
if ( ! V_241 -> V_242 )
return;
if ( V_162 && ( V_241 -> V_247 >= V_246 -> V_248 ||
! V_241 -> V_247 ) )
V_241 -> V_242 = 0 ;
if ( ! V_241 -> V_242 ||
V_246 -> V_249 >= V_246 -> V_248 ||
! V_246 -> V_249 )
return;
if ( ( V_246 -> V_249 < V_241 -> V_243 ) ||
( V_246 -> V_249 == V_241 -> V_243 &&
F_180 ( V_156 ) > F_180 ( V_241 -> V_250 ) ) ) {
V_241 -> V_250 = V_156 ;
V_241 -> V_243 = V_246 -> V_249 ;
V_241 -> V_251 = V_246 -> V_252 /
V_246 -> V_249 ;
}
if ( V_246 -> V_249 + 1 > V_246 -> V_248 )
return;
if ( V_246 -> V_249 > V_241 -> V_244 ||
( V_246 -> V_249 == V_241 -> V_244 &&
F_180 ( V_156 ) < F_180 ( V_241 -> V_253 ) ) ) {
V_241 -> V_253 = V_156 ;
V_241 -> V_244 = V_246 -> V_249 ;
}
}
static inline int F_185 ( struct V_240 * V_241 ,
int V_141 , unsigned long * V_160 )
{
if ( ! V_241 -> V_242 )
return 0 ;
if ( V_241 -> V_254 != V_241 -> V_253 ||
V_241 -> V_253 == V_241 -> V_250 )
return 0 ;
* V_160 = V_241 -> V_251 ;
V_241 -> V_214 = V_241 -> V_250 ;
return 1 ;
}
static inline void F_183 ( struct V_136 * V_137 ,
struct V_240 * V_241 , enum V_204 V_199 )
{
return;
}
static inline void F_184 ( struct V_153 * V_156 ,
struct V_240 * V_241 , int V_162 , struct V_245 * V_246 )
{
return;
}
static inline int F_185 ( struct V_240 * V_241 ,
int V_141 , unsigned long * V_160 )
{
return 0 ;
}
unsigned long F_186 ( struct V_136 * V_137 , int V_132 )
{
return V_165 ;
}
unsigned long __weak F_187 ( struct V_136 * V_137 , int V_132 )
{
return F_186 ( V_137 , V_132 ) ;
}
unsigned long F_188 ( struct V_136 * V_137 , int V_132 )
{
unsigned long V_53 = V_137 -> V_187 ;
unsigned long V_255 = V_137 -> V_255 ;
V_255 /= V_53 ;
return V_255 ;
}
unsigned long __weak F_189 ( struct V_136 * V_137 , int V_132 )
{
return F_188 ( V_137 , V_132 ) ;
}
unsigned long F_190 ( int V_132 )
{
struct V_1 * V_1 = F_143 ( V_132 ) ;
T_1 V_256 , V_257 ;
V_256 = F_191 () + ( V_1 -> clock - V_1 -> V_258 ) ;
if ( F_44 ( V_256 < V_1 -> V_259 ) ) {
V_257 = 0 ;
} else {
V_257 = V_256 - V_1 -> V_259 ;
}
if ( F_44 ( ( T_2 ) V_256 < V_165 ) )
V_256 = V_165 ;
V_256 >>= V_260 ;
return F_177 ( V_257 , V_256 ) ;
}
static void F_192 ( struct V_136 * V_137 , int V_132 )
{
unsigned long V_53 = V_137 -> V_187 ;
unsigned long V_167 = V_165 ;
struct V_153 * V_261 = V_137 -> V_157 ;
if ( ( V_137 -> V_111 & V_262 ) && V_53 > 1 ) {
if ( F_93 ( V_263 ) )
V_167 *= F_189 ( V_137 , V_132 ) ;
else
V_167 *= F_188 ( V_137 , V_132 ) ;
V_167 >>= V_260 ;
}
V_261 -> V_166 -> V_264 = V_167 ;
if ( F_93 ( V_263 ) )
V_167 *= F_187 ( V_137 , V_132 ) ;
else
V_167 *= F_186 ( V_137 , V_132 ) ;
V_167 >>= V_260 ;
V_167 *= F_190 ( V_132 ) ;
V_167 >>= V_260 ;
if ( ! V_167 )
V_167 = 1 ;
F_143 ( V_132 ) -> V_265 = V_167 ;
V_261 -> V_166 -> V_167 = V_167 ;
}
static void F_193 ( struct V_136 * V_137 , int V_132 )
{
struct V_136 * V_186 = V_137 -> V_186 ;
struct V_153 * V_156 , * V_261 = V_137 -> V_157 ;
unsigned long V_167 ;
if ( ! V_186 ) {
F_192 ( V_137 , V_132 ) ;
return;
}
V_167 = 0 ;
V_156 = V_186 -> V_157 ;
do {
V_167 += V_156 -> V_166 -> V_167 ;
V_156 = V_156 -> V_36 ;
} while ( V_156 != V_186 -> V_157 );
V_261 -> V_166 -> V_167 = V_167 ;
}
static inline int
F_194 ( struct V_136 * V_137 , struct V_153 * V_156 )
{
if ( ! ( V_137 -> V_111 & V_262 ) )
return 0 ;
if ( V_156 -> V_166 -> V_167 * 32 > V_156 -> V_166 -> V_264 * 29 )
return 1 ;
return 0 ;
}
static inline void F_195 ( struct V_136 * V_137 ,
struct V_153 * V_156 , int V_141 ,
enum V_204 V_199 , int V_154 ,
int V_162 , const struct V_266 * V_267 ,
int * V_268 , struct V_245 * V_246 )
{
unsigned long V_52 , V_269 , V_270 , V_271 ;
int V_163 ;
unsigned int V_272 = - 1 , V_273 = 0 ;
unsigned long V_274 = 0 ;
if ( V_162 )
V_272 = F_180 ( V_156 ) ;
V_269 = 0 ;
V_270 = ~ 0UL ;
V_271 = 0 ;
F_134 (i, sched_group_cpus(group), cpus) {
struct V_1 * V_1 = F_143 ( V_163 ) ;
if ( V_162 ) {
if ( F_137 ( V_163 ) && ! V_273 ) {
V_273 = 1 ;
V_272 = V_163 ;
}
V_52 = F_125 ( V_163 , V_154 ) ;
} else {
V_52 = F_124 ( V_163 , V_154 ) ;
if ( V_52 > V_269 ) {
V_269 = V_52 ;
V_271 = V_1 -> V_55 ;
}
if ( V_270 > V_52 )
V_270 = V_52 ;
}
V_246 -> V_275 += V_52 ;
V_246 -> V_249 += V_1 -> V_55 ;
V_246 -> V_252 += F_135 ( V_163 ) ;
if ( F_137 ( V_163 ) )
V_246 -> V_276 ++ ;
}
if ( V_199 != V_225 && V_162 ) {
if ( V_272 != V_141 ) {
* V_268 = 0 ;
return;
}
F_193 ( V_137 , V_141 ) ;
}
V_246 -> V_161 = ( V_246 -> V_275 * V_165 ) / V_156 -> V_166 -> V_167 ;
if ( V_246 -> V_249 )
V_274 = V_246 -> V_252 / V_246 -> V_249 ;
if ( ( V_269 - V_270 ) >= V_274 && V_271 > 1 )
V_246 -> V_277 = 1 ;
V_246 -> V_248 = F_144 ( V_156 -> V_166 -> V_167 ,
V_165 ) ;
if ( ! V_246 -> V_248 )
V_246 -> V_248 = F_194 ( V_137 , V_156 ) ;
V_246 -> V_278 = V_156 -> V_278 ;
if ( V_246 -> V_248 > V_246 -> V_249 )
V_246 -> V_279 = 1 ;
}
static bool F_196 ( struct V_136 * V_137 ,
struct V_240 * V_241 ,
struct V_153 * V_280 ,
struct V_245 * V_246 ,
int V_141 )
{
if ( V_246 -> V_161 <= V_241 -> V_281 )
return false ;
if ( V_246 -> V_249 > V_246 -> V_248 )
return true ;
if ( V_246 -> V_277 )
return true ;
if ( ( V_137 -> V_111 & V_282 ) && V_246 -> V_249 &&
V_141 < F_180 ( V_280 ) ) {
if ( ! V_241 -> V_214 )
return true ;
if ( F_180 ( V_241 -> V_214 ) > F_180 ( V_280 ) )
return true ;
}
return false ;
}
static inline void F_197 ( struct V_136 * V_137 , int V_141 ,
enum V_204 V_199 , const struct V_266 * V_267 ,
int * V_268 , struct V_240 * V_241 )
{
struct V_136 * V_186 = V_137 -> V_186 ;
struct V_153 * V_280 = V_137 -> V_157 ;
struct V_245 V_246 ;
int V_154 , V_283 = 0 ;
if ( V_186 && V_186 -> V_111 & V_284 )
V_283 = 1 ;
F_183 ( V_137 , V_241 , V_199 ) ;
V_154 = F_182 ( V_137 , V_199 ) ;
do {
int V_162 ;
V_162 = F_131 ( V_141 , F_130 ( V_280 ) ) ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
F_195 ( V_137 , V_280 , V_141 , V_199 , V_154 ,
V_162 , V_267 , V_268 , & V_246 ) ;
if ( V_162 && ! ( * V_268 ) )
return;
V_241 -> V_285 += V_246 . V_275 ;
V_241 -> V_286 += V_280 -> V_166 -> V_167 ;
if ( V_283 && ! V_162 && V_241 -> V_287 )
V_246 . V_248 = F_198 ( V_246 . V_248 , 1UL ) ;
if ( V_162 ) {
V_241 -> V_139 = V_246 . V_161 ;
V_241 -> V_254 = V_280 ;
V_241 -> V_247 = V_246 . V_249 ;
V_241 -> V_288 = V_246 . V_252 ;
V_241 -> V_287 = V_246 . V_279 ;
V_241 -> V_289 = V_246 . V_276 ;
} else if ( F_196 ( V_137 , V_241 , V_280 , & V_246 , V_141 ) ) {
V_241 -> V_281 = V_246 . V_161 ;
V_241 -> V_214 = V_280 ;
V_241 -> V_290 = V_246 . V_249 ;
V_241 -> V_291 = V_246 . V_276 ;
V_241 -> V_292 = V_246 . V_248 ;
V_241 -> V_293 = V_246 . V_252 ;
V_241 -> V_294 = V_246 . V_279 ;
V_241 -> V_295 = V_246 . V_278 ;
V_241 -> V_277 = V_246 . V_277 ;
}
F_184 ( V_280 , V_241 , V_162 , & V_246 ) ;
V_280 = V_280 -> V_36 ;
} while ( V_280 != V_137 -> V_157 );
}
int __weak F_199 ( void )
{
return 0 * V_282 ;
}
static int F_200 ( struct V_136 * V_137 ,
struct V_240 * V_241 ,
int V_141 , unsigned long * V_160 )
{
int V_296 ;
if ( ! ( V_137 -> V_111 & V_282 ) )
return 0 ;
if ( ! V_241 -> V_214 )
return 0 ;
V_296 = F_180 ( V_241 -> V_214 ) ;
if ( V_141 > V_296 )
return 0 ;
* V_160 = F_144 ( V_241 -> V_281 * V_241 -> V_214 -> V_166 -> V_167 ,
V_165 ) ;
return 1 ;
}
static inline void F_201 ( struct V_240 * V_241 ,
int V_141 , unsigned long * V_160 )
{
unsigned long V_172 , V_297 = 0 , V_298 = 0 ;
unsigned int V_299 = 2 ;
unsigned long V_300 ;
if ( V_241 -> V_247 ) {
V_241 -> V_288 /= V_241 -> V_247 ;
if ( V_241 -> V_293 >
V_241 -> V_288 )
V_299 = 1 ;
} else
V_241 -> V_288 =
F_127 ( V_141 ) ;
V_300 = V_241 -> V_293
* V_165 ;
V_300 /= V_241 -> V_214 -> V_166 -> V_167 ;
if ( V_241 -> V_281 - V_241 -> V_139 + V_300 >=
( V_300 * V_299 ) ) {
* V_160 = V_241 -> V_293 ;
return;
}
V_297 += V_241 -> V_214 -> V_166 -> V_167 *
F_198 ( V_241 -> V_293 , V_241 -> V_281 ) ;
V_297 += V_241 -> V_254 -> V_166 -> V_167 *
F_198 ( V_241 -> V_288 , V_241 -> V_139 ) ;
V_297 /= V_165 ;
V_172 = ( V_241 -> V_293 * V_165 ) /
V_241 -> V_214 -> V_166 -> V_167 ;
if ( V_241 -> V_281 > V_172 )
V_298 += V_241 -> V_214 -> V_166 -> V_167 *
F_198 ( V_241 -> V_293 , V_241 -> V_281 - V_172 ) ;
if ( V_241 -> V_281 * V_241 -> V_214 -> V_166 -> V_167 <
V_241 -> V_293 * V_165 )
V_172 = ( V_241 -> V_281 * V_241 -> V_214 -> V_166 -> V_167 ) /
V_241 -> V_254 -> V_166 -> V_167 ;
else
V_172 = ( V_241 -> V_293 * V_165 ) /
V_241 -> V_254 -> V_166 -> V_167 ;
V_298 += V_241 -> V_254 -> V_166 -> V_167 *
F_198 ( V_241 -> V_288 , V_241 -> V_139 + V_172 ) ;
V_298 /= V_165 ;
if ( V_298 > V_297 )
* V_160 = V_241 -> V_293 ;
}
static inline void F_202 ( struct V_240 * V_241 , int V_141 ,
unsigned long * V_160 )
{
unsigned long V_301 , V_302 = ~ 0UL ;
V_241 -> V_293 /= V_241 -> V_290 ;
if ( V_241 -> V_277 ) {
V_241 -> V_293 =
F_198 ( V_241 -> V_293 , V_241 -> V_161 ) ;
}
if ( V_241 -> V_281 < V_241 -> V_161 ) {
* V_160 = 0 ;
return F_201 ( V_241 , V_141 , V_160 ) ;
}
if ( ! V_241 -> V_277 ) {
V_302 = ( V_241 -> V_290 -
V_241 -> V_292 ) ;
V_302 *= ( V_303 * V_165 ) ;
V_302 /= V_241 -> V_214 -> V_166 -> V_167 ;
}
V_301 = F_198 ( V_241 -> V_281 - V_241 -> V_161 , V_302 ) ;
* V_160 = F_198 ( V_301 * V_241 -> V_214 -> V_166 -> V_167 ,
( V_241 -> V_161 - V_241 -> V_139 ) * V_241 -> V_254 -> V_166 -> V_167 )
/ V_165 ;
if ( * V_160 < V_241 -> V_293 )
return F_201 ( V_241 , V_141 , V_160 ) ;
}
static struct V_153 *
F_203 ( struct V_136 * V_137 , int V_141 ,
unsigned long * V_160 , enum V_204 V_199 ,
const struct V_266 * V_267 , int * V_268 )
{
struct V_240 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
F_197 ( V_137 , V_141 , V_199 , V_267 , V_268 , & V_241 ) ;
if ( ! ( * V_268 ) )
goto V_44;
if ( ( V_199 == V_304 || V_199 == V_225 ) &&
F_200 ( V_137 , & V_241 , V_141 , V_160 ) )
return V_241 . V_214 ;
if ( ! V_241 . V_214 || V_241 . V_290 == 0 )
goto V_305;
V_241 . V_161 = ( V_165 * V_241 . V_285 ) / V_241 . V_286 ;
if ( V_241 . V_277 )
goto V_306;
if ( V_199 == V_225 && V_241 . V_287 &&
! V_241 . V_294 )
goto V_306;
if ( V_241 . V_139 >= V_241 . V_281 )
goto V_305;
if ( V_241 . V_139 >= V_241 . V_161 )
goto V_305;
if ( V_199 == V_304 ) {
if ( ( V_241 . V_289 <= V_241 . V_291 + 1 ) &&
V_241 . V_290 <= V_241 . V_295 )
goto V_305;
} else {
if ( 100 * V_241 . V_281 <= V_137 -> V_149 * V_241 . V_139 )
goto V_305;
}
V_306:
F_202 ( & V_241 , V_141 , V_160 ) ;
return V_241 . V_214 ;
V_305:
if ( F_185 ( & V_241 , V_141 , V_160 ) )
return V_241 . V_214 ;
V_44:
* V_160 = 0 ;
return NULL ;
}
static struct V_1 *
F_204 ( struct V_136 * V_137 , struct V_153 * V_156 ,
enum V_204 V_199 , unsigned long V_160 ,
const struct V_266 * V_267 )
{
struct V_1 * V_214 = NULL , * V_1 ;
unsigned long V_281 = 0 ;
int V_163 ;
F_132 (i, sched_group_cpus(group)) {
unsigned long V_167 = F_126 ( V_163 ) ;
unsigned long V_182 = F_144 ( V_167 ,
V_165 ) ;
unsigned long V_133 ;
if ( ! V_182 )
V_182 = F_194 ( V_137 , V_156 ) ;
if ( ! F_131 ( V_163 , V_267 ) )
continue;
V_1 = F_143 ( V_163 ) ;
V_133 = F_135 ( V_163 ) ;
if ( V_182 && V_1 -> V_55 == 1 && V_133 > V_160 )
continue;
V_133 = ( V_133 * V_165 ) / V_167 ;
if ( V_133 > V_281 ) {
V_281 = V_133 ;
V_214 = V_1 ;
}
}
return V_214 ;
}
static int F_205 ( struct V_136 * V_137 , int V_199 ,
int V_296 , int V_141 )
{
if ( V_199 == V_225 ) {
if ( ( V_137 -> V_111 & V_282 ) && V_296 > V_141 )
return 1 ;
if ( V_307 < V_308 )
return 0 ;
}
return F_44 ( V_137 -> V_209 > V_137 -> V_210 + 2 ) ;
}
static int F_206 ( int V_141 , struct V_1 * V_203 ,
struct V_136 * V_137 , enum V_204 V_199 ,
int * V_268 )
{
int V_309 , V_205 = 0 , V_310 = 0 ;
struct V_153 * V_156 ;
unsigned long V_160 ;
struct V_1 * V_214 ;
unsigned long V_111 ;
struct V_266 * V_267 = F_207 ( V_311 ) ;
F_208 ( V_267 , V_312 ) ;
F_91 ( V_137 , V_313 [ V_199 ] ) ;
V_314:
V_156 = F_203 ( V_137 , V_141 , & V_160 , V_199 ,
V_267 , V_268 ) ;
if ( * V_268 == 0 )
goto V_305;
if ( ! V_156 ) {
F_91 ( V_137 , V_315 [ V_199 ] ) ;
goto V_305;
}
V_214 = F_204 ( V_137 , V_156 , V_199 , V_160 , V_267 ) ;
if ( ! V_214 ) {
F_91 ( V_137 , V_316 [ V_199 ] ) ;
goto V_305;
}
F_150 ( V_214 == V_203 ) ;
F_53 ( V_137 , V_317 [ V_199 ] , V_160 ) ;
V_309 = 0 ;
if ( V_214 -> V_55 > 1 ) {
V_205 = 1 ;
F_209 ( V_111 ) ;
F_210 ( V_203 , V_214 ) ;
V_309 = F_178 ( V_203 , V_141 , V_214 ,
V_160 , V_137 , V_199 , & V_205 ) ;
F_211 ( V_203 , V_214 ) ;
F_212 ( V_111 ) ;
if ( V_309 && V_141 != F_122 () )
F_213 ( V_141 ) ;
if ( F_44 ( V_205 ) ) {
F_214 ( F_11 ( V_214 ) , V_267 ) ;
if ( ! F_215 ( V_267 ) )
goto V_314;
goto V_305;
}
}
if ( ! V_309 ) {
F_91 ( V_137 , V_318 [ V_199 ] ) ;
if ( V_199 != V_225 )
V_137 -> V_209 ++ ;
if ( F_205 ( V_137 , V_199 , F_11 ( V_214 ) , V_141 ) ) {
F_170 ( & V_214 -> V_226 , V_111 ) ;
if ( ! F_131 ( V_141 ,
& V_214 -> V_23 -> V_164 ) ) {
F_171 ( & V_214 -> V_226 ,
V_111 ) ;
V_205 = 1 ;
goto V_319;
}
if ( ! V_214 -> V_310 ) {
V_214 -> V_310 = 1 ;
V_214 -> V_320 = V_141 ;
V_310 = 1 ;
}
F_171 ( & V_214 -> V_226 , V_111 ) ;
if ( V_310 )
F_216 ( F_11 ( V_214 ) ,
V_321 , V_214 ,
& V_214 -> V_322 ) ;
V_137 -> V_209 = V_137 -> V_210 + 1 ;
}
} else
V_137 -> V_209 = 0 ;
if ( F_83 ( ! V_310 ) ) {
V_137 -> V_323 = V_137 -> V_324 ;
} else {
if ( V_137 -> V_323 < V_137 -> V_325 )
V_137 -> V_323 *= 2 ;
}
goto V_223;
V_305:
F_91 ( V_137 , V_326 [ V_199 ] ) ;
V_137 -> V_209 = 0 ;
V_319:
if ( ( V_205 && V_137 -> V_323 < V_327 ) ||
( V_137 -> V_323 < V_137 -> V_325 ) )
V_137 -> V_323 *= 2 ;
V_309 = 0 ;
V_223:
return V_309 ;
}
static void F_217 ( int V_141 , struct V_1 * V_203 )
{
struct V_136 * V_137 ;
int V_328 = 0 ;
unsigned long V_329 = V_330 + V_331 ;
V_203 -> V_332 = V_203 -> clock ;
if ( V_203 -> V_333 < V_334 )
return;
F_218 ( & V_203 -> V_226 ) ;
F_172 ( V_141 ) ;
F_138 () ;
F_139 (this_cpu, sd) {
unsigned long V_335 ;
int V_268 = 1 ;
if ( ! ( V_137 -> V_111 & V_179 ) )
continue;
if ( V_137 -> V_111 & V_336 ) {
V_328 = F_206 ( V_141 , V_203 ,
V_137 , V_225 , & V_268 ) ;
}
V_335 = F_219 ( V_137 -> V_323 ) ;
if ( F_220 ( V_329 , V_137 -> V_337 + V_335 ) )
V_329 = V_137 -> V_337 + V_335 ;
if ( V_328 ) {
V_203 -> V_332 = 0 ;
break;
}
}
F_141 () ;
F_221 ( & V_203 -> V_226 ) ;
if ( V_328 || F_220 ( V_330 , V_203 -> V_329 ) ) {
V_203 -> V_329 = V_329 ;
}
}
static int V_321 ( void * V_227 )
{
struct V_1 * V_338 = V_227 ;
int V_296 = F_11 ( V_338 ) ;
int V_339 = V_338 -> V_320 ;
struct V_1 * V_340 = F_143 ( V_339 ) ;
struct V_136 * V_137 ;
F_222 ( & V_338 -> V_226 ) ;
if ( F_44 ( V_296 != F_122 () ||
! V_338 -> V_310 ) )
goto V_341;
if ( V_338 -> V_55 <= 1 )
goto V_341;
F_150 ( V_338 == V_340 ) ;
F_223 ( V_338 , V_340 ) ;
F_138 () ;
F_139 (target_cpu, sd) {
if ( ( V_137 -> V_111 & V_179 ) &&
F_131 ( V_296 , F_140 ( V_137 ) ) )
break;
}
if ( F_83 ( V_137 ) ) {
F_91 ( V_137 , V_342 ) ;
if ( F_164 ( V_340 , V_339 , V_338 ,
V_137 , V_304 ) )
F_91 ( V_137 , V_343 ) ;
else
F_91 ( V_137 , V_344 ) ;
}
F_141 () ;
F_224 ( V_338 , V_340 ) ;
V_341:
V_338 -> V_310 = 0 ;
F_225 ( & V_338 -> V_226 ) ;
return 0 ;
}
static void F_226 ( void * V_227 )
{
F_227 ( V_345 ) ;
}
static inline void F_228 ( struct V_346 * V_347 )
{
V_347 -> V_348 = F_226 ;
V_347 -> V_349 = NULL ;
V_347 -> V_111 = 0 ;
V_347 -> V_350 = 0 ;
}
int F_229 ( void )
{
return F_78 ( & V_351 . V_352 ) ;
}
static inline struct V_136 * F_230 ( int V_132 , int V_353 )
{
struct V_136 * V_137 ;
F_139 (cpu, sd)
if ( V_137 && ( V_137 -> V_111 & V_353 ) )
break;
return V_137 ;
}
static inline int F_231 ( struct V_153 * V_354 )
{
F_232 ( V_351 . V_355 , V_351 . V_356 ,
F_130 ( V_354 ) ) ;
if ( F_215 ( V_351 . V_355 ) )
return 0 ;
if ( F_233 ( V_351 . V_355 , F_130 ( V_354 ) ) )
return 0 ;
return 1 ;
}
static int F_234 ( int V_132 )
{
struct V_136 * V_137 ;
struct V_153 * V_354 ;
int V_357 = V_358 ;
if ( ! ( V_359 || V_307 ) )
goto V_360;
if ( F_235 ( V_351 . V_356 ) < 2 )
goto V_360;
F_138 () ;
F_236 (cpu, sd, SD_POWERSAVINGS_BALANCE) {
V_354 = V_137 -> V_157 ;
do {
if ( F_231 ( V_354 ) ) {
V_357 = F_181 ( V_351 . V_355 ) ;
goto V_184;
}
V_354 = V_354 -> V_36 ;
} while ( V_354 != V_137 -> V_157 );
}
V_184:
F_141 () ;
V_360:
return V_357 ;
}
static inline int F_234 ( int V_361 )
{
return V_358 ;
}
static void F_237 ( int V_132 )
{
int V_362 ;
V_351 . V_329 ++ ;
V_362 = F_229 () ;
if ( V_362 >= V_358 ) {
V_362 = F_181 ( V_351 . V_356 ) ;
if ( V_362 >= V_358 )
return;
}
if ( ! F_143 ( V_362 ) -> V_363 ) {
struct V_346 * V_364 ;
F_143 ( V_362 ) -> V_363 = 1 ;
V_364 = & F_238 ( V_365 , V_132 ) ;
F_239 ( V_362 , V_364 , 0 ) ;
}
return;
}
void F_240 ( int V_366 )
{
int V_132 = F_122 () ;
if ( V_366 ) {
if ( ! F_241 ( V_132 ) ) {
if ( F_78 ( & V_351 . V_352 ) != V_132 )
return;
if ( F_242 ( & V_351 . V_352 , V_132 ,
V_358 ) != V_132 )
F_243 () ;
return;
}
F_244 ( V_132 , V_351 . V_356 ) ;
if ( F_78 ( & V_351 . V_367 ) == V_132 )
F_242 ( & V_351 . V_367 , V_132 , V_358 ) ;
if ( F_78 ( & V_351 . V_368 ) == V_132 )
F_242 ( & V_351 . V_368 , V_132 , V_358 ) ;
if ( F_78 ( & V_351 . V_352 ) >= V_358 ) {
int V_369 ;
if ( F_242 ( & V_351 . V_352 , V_358 ,
V_132 ) != V_358 )
return;
V_369 = F_234 ( V_132 ) ;
if ( V_369 < V_358 && V_369 != V_132 ) {
F_245 ( & V_351 . V_352 , V_358 ) ;
F_213 ( V_369 ) ;
return;
}
return;
}
} else {
if ( ! F_131 ( V_132 , V_351 . V_356 ) )
return;
F_214 ( V_132 , V_351 . V_356 ) ;
if ( F_78 ( & V_351 . V_352 ) == V_132 )
if ( F_242 ( & V_351 . V_352 , V_132 ,
V_358 ) != V_132 )
F_243 () ;
}
return;
}
static void F_246 ( void )
{
V_370 = V_331 * F_247 () / 10 ;
}
static void F_248 ( int V_132 , enum V_204 V_199 )
{
int V_268 = 1 ;
struct V_1 * V_1 = F_143 ( V_132 ) ;
unsigned long V_335 ;
struct V_136 * V_137 ;
unsigned long V_329 = V_330 + 60 * V_331 ;
int V_371 = 0 ;
int V_372 ;
F_172 ( V_132 ) ;
F_138 () ;
F_139 (cpu, sd) {
if ( ! ( V_137 -> V_111 & V_179 ) )
continue;
V_335 = V_137 -> V_323 ;
if ( V_199 != V_304 )
V_335 *= V_137 -> V_373 ;
V_335 = F_219 ( V_335 ) ;
V_335 = F_249 ( V_335 , 1UL , V_370 ) ;
V_372 = V_137 -> V_111 & V_374 ;
if ( V_372 ) {
if ( ! F_250 ( & V_375 ) )
goto V_223;
}
if ( F_251 ( V_330 , V_137 -> V_337 + V_335 ) ) {
if ( F_206 ( V_132 , V_1 , V_137 , V_199 , & V_268 ) ) {
V_199 = V_236 ;
}
V_137 -> V_337 = V_330 ;
}
if ( V_372 )
F_252 ( & V_375 ) ;
V_223:
if ( F_220 ( V_329 , V_137 -> V_337 + V_335 ) ) {
V_329 = V_137 -> V_337 + V_335 ;
V_371 = 1 ;
}
if ( ! V_268 )
break;
}
F_141 () ;
if ( F_83 ( V_371 ) )
V_1 -> V_329 = V_329 ;
}
static void F_253 ( int V_141 , enum V_204 V_199 )
{
struct V_1 * V_203 = F_143 ( V_141 ) ;
struct V_1 * V_1 ;
int V_272 ;
if ( V_199 != V_304 || ! V_203 -> V_363 )
return;
F_132 (balance_cpu, nohz.idle_cpus_mask) {
if ( V_272 == V_141 )
continue;
if ( F_254 () ) {
V_203 -> V_363 = 0 ;
break;
}
F_222 ( & V_203 -> V_226 ) ;
F_154 ( V_203 ) ;
F_255 ( V_203 ) ;
F_225 ( & V_203 -> V_226 ) ;
F_248 ( V_272 , V_304 ) ;
V_1 = F_143 ( V_272 ) ;
if ( F_220 ( V_203 -> V_329 , V_1 -> V_329 ) )
V_203 -> V_329 = V_1 -> V_329 ;
}
V_351 . V_329 = V_203 -> V_329 ;
V_203 -> V_363 = 0 ;
}
static inline int F_256 ( struct V_1 * V_1 , int V_132 )
{
unsigned long V_72 = V_330 ;
int V_44 ;
int V_367 , V_368 ;
if ( F_257 ( V_72 , V_351 . V_329 ) )
return 0 ;
if ( V_1 -> V_376 )
return 0 ;
V_367 = F_78 ( & V_351 . V_367 ) ;
V_368 = F_78 ( & V_351 . V_368 ) ;
if ( V_367 < V_358 && V_367 != V_132 &&
V_368 < V_358 && V_368 != V_132 )
return 0 ;
V_44 = F_242 ( & V_351 . V_367 , V_358 , V_132 ) ;
if ( V_44 == V_358 || V_44 == V_132 ) {
F_242 ( & V_351 . V_368 , V_132 , V_358 ) ;
if ( V_1 -> V_55 > 1 )
return 1 ;
} else {
V_44 = F_242 ( & V_351 . V_368 , V_358 , V_132 ) ;
if ( V_44 == V_358 || V_44 == V_132 ) {
if ( V_1 -> V_55 )
return 1 ;
}
}
return 0 ;
}
static void F_253 ( int V_141 , enum V_204 V_199 ) { }
static void F_258 ( struct V_377 * V_378 )
{
int V_141 = F_122 () ;
struct V_1 * V_203 = F_143 ( V_141 ) ;
enum V_204 V_199 = V_203 -> V_376 ?
V_304 : V_236 ;
F_248 ( V_141 , V_199 ) ;
F_253 ( V_141 , V_199 ) ;
}
static inline int F_259 ( int V_132 )
{
return ! F_260 ( F_143 ( V_132 ) -> V_137 ) ;
}
static inline void F_261 ( struct V_1 * V_1 , int V_132 )
{
if ( F_251 ( V_330 , V_1 -> V_329 ) &&
F_83 ( ! F_259 ( V_132 ) ) )
F_262 ( V_345 ) ;
#ifdef F_263
else if ( F_256 ( V_1 , V_132 ) && F_83 ( ! F_259 ( V_132 ) ) )
F_237 ( V_132 ) ;
#endif
}
static void F_264 ( struct V_1 * V_1 )
{
F_265 () ;
}
static void F_266 ( struct V_1 * V_1 )
{
F_265 () ;
}
static inline void F_217 ( int V_132 , struct V_1 * V_1 )
{
}
static void F_267 ( struct V_1 * V_1 , struct V_3 * V_23 , int V_125 )
{
struct V_2 * V_2 ;
struct V_4 * V_5 = & V_23 -> V_5 ;
F_19 (se) {
V_2 = F_8 ( V_5 ) ;
F_106 ( V_2 , V_5 , V_125 ) ;
}
}
static void F_268 ( struct V_3 * V_6 )
{
struct V_2 * V_2 = F_7 ( V_146 ) ;
struct V_4 * V_5 = & V_6 -> V_5 , * V_23 = V_2 -> V_23 ;
int V_141 = F_122 () ;
struct V_1 * V_1 = V_203 () ;
unsigned long V_111 ;
F_170 ( & V_1 -> V_226 , V_111 ) ;
F_154 ( V_1 ) ;
if ( F_44 ( F_123 ( V_6 ) != V_141 ) ) {
F_138 () ;
F_269 ( V_6 , V_141 ) ;
F_141 () ;
}
F_54 ( V_2 ) ;
if ( V_23 )
V_5 -> V_19 = V_23 -> V_19 ;
F_92 ( V_2 , V_5 , 1 ) ;
if ( V_379 && V_23 && F_23 ( V_23 , V_5 ) ) {
F_270 ( V_23 -> V_19 , V_5 -> V_19 ) ;
F_101 ( V_1 -> V_23 ) ;
}
V_5 -> V_19 -= V_2 -> V_18 ;
F_171 ( & V_1 -> V_226 , V_111 ) ;
}
static void
F_271 ( struct V_1 * V_1 , struct V_3 * V_6 , int V_380 )
{
if ( ! V_6 -> V_5 . V_59 )
return;
if ( V_1 -> V_23 == V_6 ) {
if ( V_6 -> V_381 > V_380 )
F_101 ( V_1 -> V_23 ) ;
} else
F_160 ( V_1 , V_6 , 0 ) ;
}
static void F_272 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_2 * V_2 = F_8 ( V_5 ) ;
if ( ! V_5 -> V_59 && V_6 -> V_116 != V_382 ) {
F_92 ( V_2 , V_5 , 0 ) ;
V_5 -> V_19 -= V_2 -> V_18 ;
}
}
static void F_273 ( struct V_1 * V_1 , struct V_3 * V_6 )
{
if ( ! V_6 -> V_5 . V_59 )
return;
if ( V_1 -> V_23 == V_6 )
F_101 ( V_1 -> V_23 ) ;
else
F_160 ( V_1 , V_6 , 0 ) ;
}
static void F_274 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = & V_1 -> V_23 -> V_5 ;
F_19 (se)
F_102 ( F_8 ( V_5 ) , V_5 ) ;
}
static void F_275 ( struct V_3 * V_6 , int V_59 )
{
if ( ! V_59 )
V_6 -> V_5 . V_19 -= F_8 ( & V_6 -> V_5 ) -> V_18 ;
F_276 ( V_6 , F_123 ( V_6 ) ) ;
if ( ! V_59 )
V_6 -> V_5 . V_19 += F_8 ( & V_6 -> V_5 ) -> V_18 ;
}
static unsigned int F_277 ( struct V_1 * V_1 , struct V_3 * V_383 )
{
struct V_4 * V_5 = & V_383 -> V_5 ;
unsigned int V_384 = 0 ;
if ( V_1 -> V_17 . V_52 . V_53 )
V_384 = F_278 ( F_47 ( & V_1 -> V_17 , V_5 ) ) ;
return V_384 ;
}
static void F_279 ( struct V_385 * V_386 , int V_132 )
{
struct V_2 * V_2 ;
F_138 () ;
F_165 (cpu_rq(cpu), cfs_rq)
F_280 ( V_386 , V_132 , V_2 ) ;
F_141 () ;
}
