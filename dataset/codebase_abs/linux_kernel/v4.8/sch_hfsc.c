static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_2 -> V_5 -> V_6 . V_3 ;
struct V_3 * V_7 = NULL ;
struct V_1 * V_8 ;
while ( * V_4 != NULL ) {
V_7 = * V_4 ;
V_8 = F_2 ( V_7 , struct V_1 , V_9 ) ;
if ( V_2 -> V_10 >= V_8 -> V_10 )
V_4 = & V_7 -> V_11 ;
else
V_4 = & V_7 -> V_12 ;
}
F_3 ( & V_2 -> V_9 , V_7 , V_4 ) ;
F_4 ( & V_2 -> V_9 , & V_2 -> V_5 -> V_6 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_9 , & V_2 -> V_5 -> V_6 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static inline struct V_1 *
F_8 ( struct V_13 * V_14 , T_1 V_15 )
{
struct V_1 * V_4 , * V_2 = NULL ;
struct V_3 * V_16 ;
for ( V_16 = F_9 ( & V_14 -> V_6 ) ; V_16 != NULL ; V_16 = F_10 ( V_16 ) ) {
V_4 = F_2 ( V_16 , struct V_1 , V_9 ) ;
if ( V_4 -> V_10 > V_15 )
break;
if ( V_2 == NULL || V_4 -> V_17 < V_2 -> V_17 )
V_2 = V_4 ;
}
return V_2 ;
}
static inline struct V_1 *
F_11 ( struct V_13 * V_14 )
{
struct V_3 * V_16 ;
V_16 = F_9 ( & V_14 -> V_6 ) ;
if ( V_16 == NULL )
return NULL ;
return F_2 ( V_16 , struct V_1 , V_9 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_2 -> V_18 -> V_19 . V_3 ;
struct V_3 * V_7 = NULL ;
struct V_1 * V_8 ;
while ( * V_4 != NULL ) {
V_7 = * V_4 ;
V_8 = F_2 ( V_7 , struct V_1 , V_20 ) ;
if ( V_2 -> V_21 >= V_8 -> V_21 )
V_4 = & V_7 -> V_11 ;
else
V_4 = & V_7 -> V_12 ;
}
F_3 ( & V_2 -> V_20 , V_7 , V_4 ) ;
F_4 ( & V_2 -> V_20 , & V_2 -> V_18 -> V_19 ) ;
}
static inline void
F_13 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_20 , & V_2 -> V_18 -> V_19 ) ;
}
static inline void
F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static inline struct V_1 *
F_15 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_1 * V_4 ;
struct V_3 * V_16 ;
for ( V_16 = F_9 ( & V_2 -> V_19 ) ; V_16 != NULL ; V_16 = F_10 ( V_16 ) ) {
V_4 = F_2 ( V_16 , struct V_1 , V_20 ) ;
if ( V_4 -> V_22 <= V_15 )
return V_4 ;
}
return NULL ;
}
static struct V_1 *
F_16 ( struct V_1 * V_2 , T_1 V_15 )
{
if ( V_2 -> V_23 > V_15 )
return NULL ;
while ( V_2 -> V_24 > 0 ) {
V_2 = F_15 ( V_2 , V_15 ) ;
if ( V_2 == NULL )
return NULL ;
if ( V_2 -> V_18 -> V_25 < V_2 -> V_21 )
V_2 -> V_18 -> V_25 = V_2 -> V_21 ;
}
return V_2 ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_2 -> V_18 -> V_26 . V_3 ;
struct V_3 * V_7 = NULL ;
struct V_1 * V_8 ;
while ( * V_4 != NULL ) {
V_7 = * V_4 ;
V_8 = F_2 ( V_7 , struct V_1 , V_27 ) ;
if ( V_2 -> V_22 >= V_8 -> V_22 )
V_4 = & V_7 -> V_11 ;
else
V_4 = & V_7 -> V_12 ;
}
F_3 ( & V_2 -> V_27 , V_7 , V_4 ) ;
F_4 ( & V_2 -> V_27 , & V_2 -> V_18 -> V_26 ) ;
}
static inline void
F_18 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_27 , & V_2 -> V_18 -> V_26 ) ;
}
static inline void
F_19 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static inline T_1
F_20 ( T_1 V_28 , T_1 V_29 )
{
T_1 V_30 ;
V_30 = ( V_28 >> V_31 ) * V_29 + ( ( ( V_28 & V_32 ) * V_29 ) >> V_31 ) ;
return V_30 ;
}
static inline T_1
F_21 ( T_1 V_30 , T_1 V_33 )
{
T_1 V_28 ;
if ( V_30 == 0 )
V_28 = 0 ;
else if ( V_33 == V_34 )
V_28 = V_34 ;
else {
V_28 = ( V_30 >> V_35 ) * V_33
+ ( ( ( V_30 & V_36 ) * V_33 ) >> V_35 ) ;
}
return V_28 ;
}
static T_1
F_22 ( T_2 V_37 )
{
T_1 V_29 ;
V_29 = ( ( T_1 ) V_37 << V_31 ) ;
V_29 += V_38 - 1 ;
F_23 ( V_29 , V_38 ) ;
return V_29 ;
}
static T_1
F_24 ( T_2 V_37 )
{
T_1 V_33 ;
if ( V_37 == 0 )
V_33 = V_34 ;
else {
V_33 = ( ( T_1 ) V_38 << V_35 ) ;
V_33 += V_37 - 1 ;
F_23 ( V_33 , V_37 ) ;
}
return V_33 ;
}
static T_1
F_25 ( T_2 V_39 )
{
T_1 V_40 ;
V_40 = ( ( T_1 ) V_39 * V_38 ) ;
V_40 += V_41 - 1 ;
F_23 ( V_40 , V_41 ) ;
return V_40 ;
}
static T_2
F_26 ( T_1 V_29 )
{
T_1 V_37 ;
V_37 = ( V_29 * V_38 ) >> V_31 ;
return ( T_2 ) V_37 ;
}
static T_2
F_27 ( T_1 V_40 )
{
T_1 V_39 ;
V_39 = V_40 * V_41 ;
F_23 ( V_39 , V_38 ) ;
return ( T_2 ) V_39 ;
}
static void
F_28 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
V_45 -> V_46 = F_22 ( V_43 -> V_47 ) ;
V_45 -> V_48 = F_24 ( V_43 -> V_47 ) ;
V_45 -> V_40 = F_25 ( V_43 -> V_39 ) ;
V_45 -> V_49 = F_20 ( V_45 -> V_40 , V_45 -> V_46 ) ;
V_45 -> V_50 = F_22 ( V_43 -> V_51 ) ;
V_45 -> V_52 = F_24 ( V_43 -> V_51 ) ;
}
static void
F_29 ( struct V_53 * V_54 , struct V_44 * V_45 , T_1 V_28 , T_1 V_30 )
{
V_54 -> V_28 = V_28 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_46 = V_45 -> V_46 ;
V_54 -> V_48 = V_45 -> V_48 ;
V_54 -> V_40 = V_45 -> V_40 ;
V_54 -> V_49 = V_45 -> V_49 ;
V_54 -> V_50 = V_45 -> V_50 ;
V_54 -> V_52 = V_45 -> V_52 ;
}
static T_1
F_30 ( struct V_53 * V_54 , T_1 V_30 )
{
T_1 V_28 ;
if ( V_30 < V_54 -> V_30 )
V_28 = V_54 -> V_28 ;
else if ( V_30 <= V_54 -> V_30 + V_54 -> V_49 ) {
if ( V_54 -> V_49 == 0 )
V_28 = V_54 -> V_28 + V_54 -> V_40 ;
else
V_28 = V_54 -> V_28 + F_21 ( V_30 - V_54 -> V_30 , V_54 -> V_48 ) ;
} else {
V_28 = V_54 -> V_28 + V_54 -> V_40
+ F_21 ( V_30 - V_54 -> V_30 - V_54 -> V_49 , V_54 -> V_52 ) ;
}
return V_28 ;
}
static T_1
F_31 ( struct V_53 * V_54 , T_1 V_28 )
{
T_1 V_30 ;
if ( V_28 <= V_54 -> V_28 )
V_30 = V_54 -> V_30 ;
else if ( V_28 <= V_54 -> V_28 + V_54 -> V_40 )
V_30 = V_54 -> V_30 + F_20 ( V_28 - V_54 -> V_28 , V_54 -> V_46 ) ;
else
V_30 = V_54 -> V_30 + V_54 -> V_49
+ F_20 ( V_28 - V_54 -> V_28 - V_54 -> V_40 , V_54 -> V_50 ) ;
return V_30 ;
}
static void
F_32 ( struct V_53 * V_54 , struct V_44 * V_45 , T_1 V_28 , T_1 V_30 )
{
T_1 y1 , V_55 , V_40 , V_49 ;
T_2 V_56 ;
if ( V_45 -> V_46 <= V_45 -> V_50 ) {
y1 = F_31 ( V_54 , V_28 ) ;
if ( y1 < V_30 )
return;
V_54 -> V_28 = V_28 ;
V_54 -> V_30 = V_30 ;
return;
}
y1 = F_31 ( V_54 , V_28 ) ;
if ( y1 <= V_30 ) {
return;
}
V_55 = F_31 ( V_54 , V_28 + V_45 -> V_40 ) ;
if ( V_55 >= V_30 + V_45 -> V_49 ) {
V_54 -> V_28 = V_28 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_40 = V_45 -> V_40 ;
V_54 -> V_49 = V_45 -> V_49 ;
return;
}
V_40 = ( y1 - V_30 ) << V_31 ;
V_56 = V_45 -> V_46 - V_45 -> V_50 ;
F_23 ( V_40 , V_56 ) ;
if ( V_54 -> V_28 + V_54 -> V_40 > V_28 )
V_40 += V_54 -> V_28 + V_54 -> V_40 - V_28 ;
V_49 = F_20 ( V_40 , V_45 -> V_46 ) ;
V_54 -> V_28 = V_28 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_40 = V_40 ;
V_54 -> V_49 = V_49 ;
}
static void
F_33 ( struct V_1 * V_2 , unsigned int V_57 )
{
T_1 V_15 = F_34 () ;
F_32 ( & V_2 -> V_58 , & V_2 -> V_59 , V_15 , V_2 -> V_60 ) ;
V_2 -> V_61 = V_2 -> V_58 ;
if ( V_2 -> V_59 . V_46 <= V_2 -> V_59 . V_50 ) {
V_2 -> V_61 . V_40 = 0 ;
V_2 -> V_61 . V_49 = 0 ;
}
V_2 -> V_10 = F_30 ( & V_2 -> V_61 , V_2 -> V_60 ) ;
V_2 -> V_17 = F_30 ( & V_2 -> V_58 , V_2 -> V_60 + V_57 ) ;
F_1 ( V_2 ) ;
}
static void
F_35 ( struct V_1 * V_2 , unsigned int V_57 )
{
V_2 -> V_10 = F_30 ( & V_2 -> V_61 , V_2 -> V_60 ) ;
V_2 -> V_17 = F_30 ( & V_2 -> V_58 , V_2 -> V_60 + V_57 ) ;
F_7 ( V_2 ) ;
}
static inline void
F_36 ( struct V_1 * V_2 , unsigned int V_57 )
{
V_2 -> V_17 = F_30 ( & V_2 -> V_58 , V_2 -> V_60 + V_57 ) ;
}
static inline void
F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_16 = F_9 ( & V_2 -> V_26 ) ;
struct V_1 * V_4 ;
if ( V_16 == NULL ) {
V_2 -> V_23 = 0 ;
return;
}
V_4 = F_2 ( V_16 , struct V_1 , V_27 ) ;
V_2 -> V_23 = V_4 -> V_22 ;
}
static void
F_38 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_1 * V_63 ;
struct V_3 * V_16 ;
T_1 V_64 , V_65 , V_15 ;
int V_66 ;
V_15 = 0 ;
V_66 = 1 ;
for (; V_2 -> V_18 != NULL ; V_2 = V_2 -> V_18 ) {
if ( V_66 && V_2 -> V_67 ++ == 0 )
V_66 = 1 ;
else
V_66 = 0 ;
if ( V_66 ) {
V_16 = F_39 ( & V_2 -> V_18 -> V_19 ) ;
if ( V_16 != NULL ) {
V_63 = F_2 ( V_16 , struct V_1 , V_20 ) ;
V_64 = V_63 -> V_21 ;
if ( V_2 -> V_18 -> V_25 != 0 )
V_64 = ( V_2 -> V_18 -> V_25 + V_64 ) / 2 ;
if ( V_2 -> V_18 -> V_68 !=
V_2 -> V_69 || V_64 > V_2 -> V_21 )
V_2 -> V_21 = V_64 ;
} else {
V_64 = V_2 -> V_18 -> V_70 ;
V_2 -> V_18 -> V_71 += V_64 ;
V_2 -> V_18 -> V_70 = 0 ;
V_2 -> V_18 -> V_25 = 0 ;
V_2 -> V_21 = 0 ;
}
V_2 -> V_72 = V_2 -> V_18 -> V_71 -
V_2 -> V_73 ;
V_64 = V_2 -> V_21 + V_2 -> V_72 ;
F_32 ( & V_2 -> V_74 , & V_2 -> V_75 , V_64 ,
V_2 -> V_76 ) ;
if ( V_2 -> V_74 . V_28 == V_64 ) {
V_2 -> V_74 . V_28 -= V_2 -> V_72 ;
V_2 -> V_72 = 0 ;
}
V_2 -> V_77 = 0 ;
V_2 -> V_68 ++ ;
V_2 -> V_69 = V_2 -> V_18 -> V_68 ;
if ( V_2 -> V_18 -> V_67 == 0 )
V_2 -> V_69 ++ ;
V_2 -> V_22 = 0 ;
F_12 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( V_2 -> V_78 & V_79 ) {
if ( V_15 == 0 )
V_15 = F_34 () ;
F_32 ( & V_2 -> V_80 , & V_2 -> V_81 , V_15 ,
V_2 -> V_76 ) ;
V_2 -> V_82 = F_30 ( & V_2 -> V_80 ,
V_2 -> V_76 ) ;
V_2 -> V_83 = 0 ;
}
}
V_65 = F_40 ( V_2 -> V_82 , V_2 -> V_23 ) ;
if ( V_65 != V_2 -> V_22 ) {
V_2 -> V_22 = V_65 ;
F_19 ( V_2 ) ;
}
F_37 ( V_2 -> V_18 ) ;
}
}
static void
F_41 ( struct V_1 * V_2 , unsigned int V_62 , T_1 V_15 )
{
T_1 V_65 ;
int V_84 = 0 ;
if ( V_2 -> V_85 -> V_14 . V_86 == 0 && V_2 -> V_78 & V_87 )
V_84 = 1 ;
for (; V_2 -> V_18 != NULL ; V_2 = V_2 -> V_18 ) {
V_2 -> V_76 += V_62 ;
if ( ! ( V_2 -> V_78 & V_87 ) || V_2 -> V_67 == 0 )
continue;
if ( V_84 && -- V_2 -> V_67 == 0 )
V_84 = 1 ;
else
V_84 = 0 ;
V_2 -> V_21 = F_30 ( & V_2 -> V_74 , V_2 -> V_76 )
- V_2 -> V_72 + V_2 -> V_77 ;
if ( V_2 -> V_21 < V_2 -> V_18 -> V_25 ) {
V_2 -> V_77 += V_2 -> V_18 -> V_25 - V_2 -> V_21 ;
V_2 -> V_21 = V_2 -> V_18 -> V_25 ;
}
if ( V_84 ) {
if ( V_2 -> V_21 > V_2 -> V_18 -> V_70 )
V_2 -> V_18 -> V_70 = V_2 -> V_21 ;
F_13 ( V_2 ) ;
F_18 ( V_2 ) ;
F_37 ( V_2 -> V_18 ) ;
continue;
}
F_14 ( V_2 ) ;
if ( V_2 -> V_78 & V_79 ) {
V_2 -> V_82 = V_2 -> V_83 + F_30 ( & V_2 -> V_80 ,
V_2 -> V_76 ) ;
#if 0
myf_bound = cur_time - PSCHED_JIFFIE2US(1);
if (cl->cl_myf < myf_bound) {
delta = cur_time - cl->cl_myf;
cl->cl_myfadj += delta;
cl->cl_myf += delta;
}
#endif
}
V_65 = F_40 ( V_2 -> V_82 , V_2 -> V_23 ) ;
if ( V_65 != V_2 -> V_22 ) {
V_2 -> V_22 = V_65 ;
F_19 ( V_2 ) ;
F_37 ( V_2 -> V_18 ) ;
}
}
}
static void
F_42 ( struct V_1 * V_2 , unsigned int V_62 )
{
if ( V_2 -> V_78 & V_88 )
F_33 ( V_2 , V_62 ) ;
if ( V_2 -> V_78 & V_87 )
F_38 ( V_2 , V_62 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 & V_88 )
F_5 ( V_2 ) ;
}
static unsigned int
F_44 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
unsigned int V_62 ;
V_92 = V_90 -> V_93 -> V_94 ( V_90 ) ;
if ( F_45 ( V_92 == NULL ) ) {
F_46 ( L_1 , V_90 ) ;
return 0 ;
}
V_62 = F_47 ( V_92 ) ;
return V_62 ;
}
static void
F_48 ( struct V_89 * V_90 , struct V_1 * V_2 )
{
unsigned int V_62 = V_2 -> V_85 -> V_14 . V_86 ;
unsigned int V_95 = V_2 -> V_85 -> V_96 . V_95 ;
F_49 ( V_2 -> V_85 ) ;
F_50 ( V_2 -> V_85 , V_62 , V_95 ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
struct V_1 * V_4 ;
unsigned int V_24 ;
do {
V_24 = 0 ;
F_52 (p, &cl->children, siblings) {
if ( V_4 -> V_24 >= V_24 )
V_24 = V_4 -> V_24 + 1 ;
}
V_2 -> V_24 = V_24 ;
} while ( ( V_2 = V_2 -> V_18 ) != NULL );
}
static inline struct V_1 *
F_53 ( T_2 V_97 , struct V_89 * V_90 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_98 * V_99 ;
V_99 = F_55 ( & V_14 -> V_100 , V_97 ) ;
if ( V_99 == NULL )
return NULL ;
return F_56 ( V_99 , struct V_1 , V_101 ) ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_42 * V_102 ,
T_1 V_15 )
{
F_28 ( V_102 , & V_2 -> V_59 ) ;
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , V_15 , V_2 -> V_60 ) ;
V_2 -> V_61 = V_2 -> V_58 ;
if ( V_2 -> V_59 . V_46 <= V_2 -> V_59 . V_50 ) {
V_2 -> V_61 . V_40 = 0 ;
V_2 -> V_61 . V_49 = 0 ;
}
V_2 -> V_78 |= V_88 ;
}
static void
F_58 ( struct V_1 * V_2 , struct V_42 * V_103 )
{
F_28 ( V_103 , & V_2 -> V_75 ) ;
F_29 ( & V_2 -> V_74 , & V_2 -> V_75 , V_2 -> V_72 + V_2 -> V_21 , V_2 -> V_76 ) ;
V_2 -> V_78 |= V_87 ;
}
static void
F_59 ( struct V_1 * V_2 , struct V_42 * V_104 ,
T_1 V_15 )
{
F_28 ( V_104 , & V_2 -> V_81 ) ;
F_29 ( & V_2 -> V_80 , & V_2 -> V_81 , V_15 , V_2 -> V_76 ) ;
V_2 -> V_78 |= V_79 ;
}
static int
F_60 ( struct V_89 * V_90 , T_2 V_97 , T_2 V_105 ,
struct V_106 * * V_107 , unsigned long * V_108 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_108 ;
struct V_1 * V_7 = NULL ;
struct V_106 * V_109 = V_107 [ V_110 ] ;
struct V_106 * V_111 [ V_112 + 1 ] ;
struct V_42 * V_102 = NULL , * V_103 = NULL , * V_104 = NULL ;
T_1 V_15 ;
int V_113 ;
if ( V_109 == NULL )
return - V_114 ;
V_113 = F_61 ( V_111 , V_112 , V_109 , V_115 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_111 [ V_116 ] ) {
V_102 = F_62 ( V_111 [ V_116 ] ) ;
if ( V_102 -> V_47 == 0 && V_102 -> V_51 == 0 )
V_102 = NULL ;
}
if ( V_111 [ V_117 ] ) {
V_103 = F_62 ( V_111 [ V_117 ] ) ;
if ( V_103 -> V_47 == 0 && V_103 -> V_51 == 0 )
V_103 = NULL ;
}
if ( V_111 [ V_118 ] ) {
V_104 = F_62 ( V_111 [ V_118 ] ) ;
if ( V_104 -> V_47 == 0 && V_104 -> V_51 == 0 )
V_104 = NULL ;
}
if ( V_2 != NULL ) {
if ( V_105 ) {
if ( V_2 -> V_18 &&
V_2 -> V_18 -> V_101 . V_97 != V_105 )
return - V_114 ;
if ( V_2 -> V_18 == NULL && V_105 != V_119 )
return - V_114 ;
}
V_15 = F_34 () ;
if ( V_107 [ V_120 ] ) {
V_113 = F_63 ( & V_2 -> V_121 , NULL ,
& V_2 -> V_122 ,
NULL ,
F_64 ( V_90 ) ,
V_107 [ V_120 ] ) ;
if ( V_113 )
return V_113 ;
}
F_65 ( V_90 ) ;
if ( V_102 != NULL )
F_57 ( V_2 , V_102 , V_15 ) ;
if ( V_103 != NULL )
F_58 ( V_2 , V_103 ) ;
if ( V_104 != NULL )
F_59 ( V_2 , V_104 , V_15 ) ;
if ( V_2 -> V_85 -> V_14 . V_86 != 0 ) {
if ( V_2 -> V_78 & V_88 )
F_35 ( V_2 , F_44 ( V_2 -> V_85 ) ) ;
if ( V_2 -> V_78 & V_87 )
F_41 ( V_2 , 0 , V_15 ) ;
}
F_66 ( V_90 ) ;
return 0 ;
}
if ( V_105 == V_119 )
return - V_123 ;
V_7 = & V_14 -> V_124 ;
if ( V_105 ) {
V_7 = F_53 ( V_105 , V_90 ) ;
if ( V_7 == NULL )
return - V_125 ;
}
if ( V_97 == 0 || F_67 ( V_97 ^ V_90 -> V_126 ) != 0 )
return - V_114 ;
if ( F_53 ( V_97 , V_90 ) )
return - V_123 ;
if ( V_102 == NULL && V_103 == NULL )
return - V_114 ;
V_2 = F_68 ( sizeof( struct V_1 ) , V_127 ) ;
if ( V_2 == NULL )
return - V_128 ;
if ( V_107 [ V_120 ] ) {
V_113 = F_69 ( & V_2 -> V_121 , NULL , & V_2 -> V_122 ,
NULL ,
F_64 ( V_90 ) ,
V_107 [ V_120 ] ) ;
if ( V_113 ) {
F_70 ( V_2 ) ;
return V_113 ;
}
}
if ( V_102 != NULL )
F_57 ( V_2 , V_102 , 0 ) ;
if ( V_103 != NULL )
F_58 ( V_2 , V_103 ) ;
if ( V_104 != NULL )
F_59 ( V_2 , V_104 , 0 ) ;
V_2 -> V_101 . V_97 = V_97 ;
V_2 -> V_129 = 1 ;
V_2 -> V_5 = V_14 ;
V_2 -> V_18 = V_7 ;
V_2 -> V_85 = F_71 ( V_90 -> V_130 ,
& V_131 , V_97 ) ;
if ( V_2 -> V_85 == NULL )
V_2 -> V_85 = & V_132 ;
F_72 ( & V_2 -> V_133 ) ;
V_2 -> V_19 = V_134 ;
V_2 -> V_26 = V_134 ;
F_65 ( V_90 ) ;
F_73 ( & V_14 -> V_100 , & V_2 -> V_101 ) ;
F_74 ( & V_2 -> V_135 , & V_7 -> V_133 ) ;
if ( V_7 -> V_24 == 0 )
F_48 ( V_90 , V_7 ) ;
F_51 ( V_7 ) ;
V_2 -> V_73 = V_7 -> V_71 ;
F_66 ( V_90 ) ;
F_75 ( V_90 , & V_14 -> V_100 ) ;
* V_108 = ( unsigned long ) V_2 ;
return 0 ;
}
static void
F_76 ( struct V_89 * V_90 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
F_77 ( & V_2 -> V_136 ) ;
F_78 ( V_2 -> V_85 ) ;
F_79 ( & V_2 -> V_121 , & V_2 -> V_122 ) ;
if ( V_2 != & V_14 -> V_124 )
F_70 ( V_2 ) ;
}
static int
F_80 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( V_2 -> V_24 > 0 || V_2 -> V_137 > 0 || V_2 == & V_14 -> V_124 )
return - V_138 ;
F_65 ( V_90 ) ;
F_81 ( & V_2 -> V_135 ) ;
F_51 ( V_2 -> V_18 ) ;
F_48 ( V_90 , V_2 ) ;
F_82 ( & V_14 -> V_100 , & V_2 -> V_101 ) ;
F_83 ( -- V_2 -> V_129 == 0 ) ;
F_66 ( V_90 ) ;
return 0 ;
}
static struct V_1 *
F_84 ( struct V_91 * V_92 , struct V_89 * V_90 , int * V_139 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_140 , * V_2 ;
struct V_141 V_142 ;
struct V_143 * V_144 ;
int V_145 ;
if ( F_67 ( V_92 -> V_146 ^ V_90 -> V_126 ) == 0 &&
( V_2 = F_53 ( V_92 -> V_146 , V_90 ) ) != NULL )
if ( V_2 -> V_24 == 0 )
return V_2 ;
* V_139 = V_147 | V_148 ;
V_140 = & V_14 -> V_124 ;
V_144 = F_85 ( V_14 -> V_124 . V_136 ) ;
while ( V_144 && ( V_145 = F_86 ( V_92 , V_144 , & V_142 , false ) ) >= 0 ) {
#ifdef F_87
switch ( V_145 ) {
case V_149 :
case V_150 :
* V_139 = V_147 | V_151 ;
case V_152 :
return NULL ;
}
#endif
V_2 = (struct V_1 * ) V_142 . V_153 ;
if ( ! V_2 ) {
V_2 = F_53 ( V_142 . V_97 , V_90 ) ;
if ( ! V_2 )
break;
if ( V_2 -> V_24 >= V_140 -> V_24 )
break;
}
if ( V_2 -> V_24 == 0 )
return V_2 ;
V_144 = F_85 ( V_2 -> V_136 ) ;
V_140 = V_2 ;
}
V_2 = F_53 ( F_88 ( F_67 ( V_90 -> V_126 ) , V_14 -> V_154 ) , V_90 ) ;
if ( V_2 == NULL || V_2 -> V_24 > 0 )
return NULL ;
return V_2 ;
}
static int
F_89 ( struct V_89 * V_90 , unsigned long V_108 , struct V_89 * V_155 ,
struct V_89 * * V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( V_2 -> V_24 > 0 )
return - V_114 ;
if ( V_155 == NULL ) {
V_155 = F_71 ( V_90 -> V_130 , & V_131 ,
V_2 -> V_101 . V_97 ) ;
if ( V_155 == NULL )
V_155 = & V_132 ;
}
* V_156 = F_90 ( V_90 , V_155 , & V_2 -> V_85 ) ;
return 0 ;
}
static struct V_89 *
F_91 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( V_2 -> V_24 == 0 )
return V_2 -> V_85 ;
return NULL ;
}
static void
F_92 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( V_2 -> V_85 -> V_14 . V_86 == 0 ) {
F_41 ( V_2 , 0 , 0 ) ;
F_43 ( V_2 ) ;
}
}
static unsigned long
F_93 ( struct V_89 * V_90 , T_2 V_97 )
{
struct V_1 * V_2 = F_53 ( V_97 , V_90 ) ;
if ( V_2 != NULL )
V_2 -> V_129 ++ ;
return ( unsigned long ) V_2 ;
}
static void
F_94 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( -- V_2 -> V_129 == 0 )
F_76 ( V_90 , V_2 ) ;
}
static unsigned long
F_95 ( struct V_89 * V_90 , unsigned long V_7 , T_2 V_97 )
{
struct V_1 * V_4 = (struct V_1 * ) V_7 ;
struct V_1 * V_2 = F_53 ( V_97 , V_90 ) ;
if ( V_2 != NULL ) {
if ( V_4 != NULL && V_4 -> V_24 <= V_2 -> V_24 )
return 0 ;
V_2 -> V_137 ++ ;
}
return ( unsigned long ) V_2 ;
}
static void
F_96 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
V_2 -> V_137 -- ;
}
static struct V_143 T_3 * *
F_97 ( struct V_89 * V_90 , unsigned long V_108 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
if ( V_2 == NULL )
V_2 = & V_14 -> V_124 ;
return & V_2 -> V_136 ;
}
static int
F_98 ( struct V_91 * V_92 , int V_157 , struct V_44 * V_43 )
{
struct V_42 V_158 ;
V_158 . V_47 = F_26 ( V_43 -> V_46 ) ;
V_158 . V_39 = F_27 ( V_43 -> V_40 ) ;
V_158 . V_51 = F_26 ( V_43 -> V_50 ) ;
if ( F_99 ( V_92 , V_157 , sizeof( V_158 ) , & V_158 ) )
goto V_159;
return V_92 -> V_62 ;
V_159:
return - 1 ;
}
static int
F_100 ( struct V_91 * V_92 , struct V_1 * V_2 )
{
if ( ( V_2 -> V_78 & V_88 ) &&
( F_98 ( V_92 , V_116 , & V_2 -> V_59 ) < 0 ) )
goto V_159;
if ( ( V_2 -> V_78 & V_87 ) &&
( F_98 ( V_92 , V_117 , & V_2 -> V_75 ) < 0 ) )
goto V_159;
if ( ( V_2 -> V_78 & V_79 ) &&
( F_98 ( V_92 , V_118 , & V_2 -> V_81 ) < 0 ) )
goto V_159;
return V_92 -> V_62 ;
V_159:
return - 1 ;
}
static int
F_101 ( struct V_89 * V_90 , unsigned long V_108 , struct V_91 * V_92 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
struct V_106 * V_162 ;
V_161 -> V_163 = V_2 -> V_18 ? V_2 -> V_18 -> V_101 . V_97 :
V_119 ;
V_161 -> V_164 = V_2 -> V_101 . V_97 ;
if ( V_2 -> V_24 == 0 )
V_161 -> V_165 = V_2 -> V_85 -> V_126 ;
V_162 = F_102 ( V_92 , V_110 ) ;
if ( V_162 == NULL )
goto V_159;
if ( F_100 ( V_92 , V_2 ) < 0 )
goto V_159;
return F_103 ( V_92 , V_162 ) ;
V_159:
F_104 ( V_92 , V_162 ) ;
return - V_166 ;
}
static int
F_105 ( struct V_89 * V_90 , unsigned long V_108 ,
struct V_167 * V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
struct V_168 V_169 ;
V_2 -> V_96 . V_95 = V_2 -> V_85 -> V_96 . V_95 ;
V_169 . V_24 = V_2 -> V_24 ;
V_169 . V_170 = V_2 -> V_68 ;
V_169 . V_171 = V_2 -> V_76 ;
V_169 . V_172 = V_2 -> V_60 ;
if ( F_106 ( F_64 ( V_90 ) , V_39 , NULL , & V_2 -> V_121 ) < 0 ||
F_107 ( V_39 , & V_2 -> V_121 , & V_2 -> V_122 ) < 0 ||
F_108 ( V_39 , NULL , & V_2 -> V_96 , V_2 -> V_85 -> V_14 . V_86 ) < 0 )
return - 1 ;
return F_109 ( V_39 , & V_169 , sizeof( V_169 ) ) ;
}
static void
F_110 ( struct V_89 * V_90 , struct V_173 * V_108 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 ;
unsigned int V_174 ;
if ( V_108 -> V_175 )
return;
for ( V_174 = 0 ; V_174 < V_14 -> V_100 . V_176 ; V_174 ++ ) {
F_111 (cl, &q->clhash.hash[i],
cl_common.hnode) {
if ( V_108 -> V_177 < V_108 -> V_178 ) {
V_108 -> V_177 ++ ;
continue;
}
if ( V_108 -> V_179 ( V_90 , ( unsigned long ) V_2 , V_108 ) < 0 ) {
V_108 -> V_175 = 1 ;
return;
}
V_108 -> V_177 ++ ;
}
}
}
static void
F_112 ( struct V_89 * V_90 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 ;
T_1 V_180 = 0 ;
V_2 = F_11 ( V_14 ) ;
if ( V_2 )
V_180 = V_2 -> V_10 ;
if ( V_14 -> V_124 . V_23 != 0 ) {
if ( V_180 == 0 || V_180 > V_14 -> V_124 . V_23 )
V_180 = V_14 -> V_124 . V_23 ;
}
F_113 ( V_180 == 0 ) ;
F_114 ( & V_14 -> V_181 , V_180 ) ;
}
static int
F_115 ( struct V_89 * V_90 , struct V_106 * V_109 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_182 * V_183 ;
int V_113 ;
if ( V_109 == NULL || F_116 ( V_109 ) < sizeof( * V_183 ) )
return - V_114 ;
V_183 = F_62 ( V_109 ) ;
V_14 -> V_154 = V_183 -> V_154 ;
V_113 = F_117 ( & V_14 -> V_100 ) ;
if ( V_113 < 0 )
return V_113 ;
V_14 -> V_6 = V_134 ;
V_14 -> V_124 . V_101 . V_97 = V_90 -> V_126 ;
V_14 -> V_124 . V_129 = 1 ;
V_14 -> V_124 . V_5 = V_14 ;
V_14 -> V_124 . V_85 = F_71 ( V_90 -> V_130 , & V_131 ,
V_90 -> V_126 ) ;
if ( V_14 -> V_124 . V_85 == NULL )
V_14 -> V_124 . V_85 = & V_132 ;
F_72 ( & V_14 -> V_124 . V_133 ) ;
V_14 -> V_124 . V_19 = V_134 ;
V_14 -> V_124 . V_26 = V_134 ;
F_73 ( & V_14 -> V_100 , & V_14 -> V_124 . V_101 ) ;
F_75 ( V_90 , & V_14 -> V_100 ) ;
F_118 ( & V_14 -> V_181 , V_90 ) ;
return 0 ;
}
static int
F_119 ( struct V_89 * V_90 , struct V_106 * V_109 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_182 * V_183 ;
if ( V_109 == NULL || F_116 ( V_109 ) < sizeof( * V_183 ) )
return - V_114 ;
V_183 = F_62 ( V_109 ) ;
F_65 ( V_90 ) ;
V_14 -> V_154 = V_183 -> V_154 ;
F_66 ( V_90 ) ;
return 0 ;
}
static void
F_120 ( struct V_1 * V_2 )
{
V_2 -> V_76 = 0 ;
V_2 -> V_60 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_68 = 0 ;
V_2 -> V_69 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_82 = 0 ;
V_2 -> V_83 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_67 = 0 ;
V_2 -> V_19 = V_134 ;
V_2 -> V_26 = V_134 ;
F_49 ( V_2 -> V_85 ) ;
if ( V_2 -> V_78 & V_88 )
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , 0 , 0 ) ;
if ( V_2 -> V_78 & V_87 )
F_29 ( & V_2 -> V_74 , & V_2 -> V_75 , 0 , 0 ) ;
if ( V_2 -> V_78 & V_79 )
F_29 ( & V_2 -> V_80 , & V_2 -> V_81 , 0 , 0 ) ;
}
static void
F_121 ( struct V_89 * V_90 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 ;
unsigned int V_174 ;
for ( V_174 = 0 ; V_174 < V_14 -> V_100 . V_176 ; V_174 ++ ) {
F_111 (cl, &q->clhash.hash[i], cl_common.hnode)
F_120 ( V_2 ) ;
}
V_14 -> V_6 = V_134 ;
F_122 ( & V_14 -> V_181 ) ;
V_90 -> V_96 . V_95 = 0 ;
V_90 -> V_14 . V_86 = 0 ;
}
static void
F_123 ( struct V_89 * V_90 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_184 * V_185 ;
struct V_1 * V_2 ;
unsigned int V_174 ;
for ( V_174 = 0 ; V_174 < V_14 -> V_100 . V_176 ; V_174 ++ ) {
F_111 (cl, &q->clhash.hash[i], cl_common.hnode)
F_77 ( & V_2 -> V_136 ) ;
}
for ( V_174 = 0 ; V_174 < V_14 -> V_100 . V_176 ; V_174 ++ ) {
F_124 (cl, next, &q->clhash.hash[i],
cl_common.hnode)
F_76 ( V_90 , V_2 ) ;
}
F_125 ( & V_14 -> V_100 ) ;
F_122 ( & V_14 -> V_181 ) ;
}
static int
F_126 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
unsigned char * V_186 = F_127 ( V_92 ) ;
struct V_182 V_183 ;
V_183 . V_154 = V_14 -> V_154 ;
if ( F_99 ( V_92 , V_110 , sizeof( V_183 ) , & V_183 ) )
goto V_159;
return V_92 -> V_62 ;
V_159:
F_128 ( V_92 , V_186 ) ;
return - 1 ;
}
static int
F_129 ( struct V_91 * V_92 , struct V_89 * V_90 , struct V_91 * * V_187 )
{
struct V_1 * V_2 ;
int V_188 ( V_113 ) ;
V_2 = F_84 ( V_92 , V_90 , & V_113 ) ;
if ( V_2 == NULL ) {
if ( V_113 & V_148 )
F_130 ( V_90 ) ;
F_131 ( V_92 , V_187 ) ;
return V_113 ;
}
V_113 = F_132 ( V_92 , V_2 -> V_85 , V_187 ) ;
if ( F_45 ( V_113 != V_147 ) ) {
if ( F_133 ( V_113 ) ) {
V_2 -> V_96 . V_189 ++ ;
F_130 ( V_90 ) ;
}
return V_113 ;
}
if ( V_2 -> V_85 -> V_14 . V_86 == 1 ) {
F_42 ( V_2 , F_47 ( V_92 ) ) ;
if ( V_2 -> V_78 & V_88 )
V_2 -> V_85 -> V_93 -> V_94 ( V_2 -> V_85 ) ;
}
F_134 ( V_90 , V_92 ) ;
V_90 -> V_14 . V_86 ++ ;
return V_147 ;
}
static struct V_91 *
F_135 ( struct V_89 * V_90 )
{
struct V_13 * V_14 = F_54 ( V_90 ) ;
struct V_1 * V_2 ;
struct V_91 * V_92 ;
T_1 V_15 ;
unsigned int V_57 ;
int V_190 = 0 ;
if ( V_90 -> V_14 . V_86 == 0 )
return NULL ;
V_15 = F_34 () ;
V_2 = F_8 ( V_14 , V_15 ) ;
if ( V_2 ) {
V_190 = 1 ;
} else {
V_2 = F_16 ( & V_14 -> V_124 , V_15 ) ;
if ( V_2 == NULL ) {
F_136 ( V_90 ) ;
F_112 ( V_90 ) ;
return NULL ;
}
}
V_92 = F_137 ( V_2 -> V_85 ) ;
if ( V_92 == NULL ) {
F_46 ( L_2 , V_2 -> V_85 ) ;
return NULL ;
}
F_138 ( & V_2 -> V_121 , V_92 ) ;
F_41 ( V_2 , F_47 ( V_92 ) , V_15 ) ;
if ( V_190 )
V_2 -> V_60 += F_47 ( V_92 ) ;
if ( V_2 -> V_85 -> V_14 . V_86 != 0 ) {
if ( V_2 -> V_78 & V_88 ) {
V_57 = F_44 ( V_2 -> V_85 ) ;
if ( V_190 )
F_35 ( V_2 , V_57 ) ;
else
F_36 ( V_2 , V_57 ) ;
}
} else {
F_43 ( V_2 ) ;
}
F_139 ( V_90 , V_92 ) ;
F_140 ( V_90 , V_92 ) ;
V_90 -> V_14 . V_86 -- ;
return V_92 ;
}
static int T_4
F_141 ( void )
{
return F_142 ( & V_191 ) ;
}
static void T_5
F_143 ( void )
{
F_144 ( & V_191 ) ;
}
