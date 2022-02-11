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
V_2 -> V_21 = V_2 -> V_18 -> V_70 ;
V_2 -> V_18 -> V_25 = 0 ;
}
F_32 ( & V_2 -> V_71 , & V_2 -> V_72 , V_2 -> V_21 , V_2 -> V_73 ) ;
V_2 -> V_74 = 0 ;
V_2 -> V_68 ++ ;
V_2 -> V_69 = V_2 -> V_18 -> V_68 ;
if ( V_2 -> V_18 -> V_67 == 0 )
V_2 -> V_69 ++ ;
V_2 -> V_22 = 0 ;
F_12 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( V_2 -> V_75 & V_76 ) {
if ( V_15 == 0 )
V_15 = F_34 () ;
F_32 ( & V_2 -> V_77 , & V_2 -> V_78 , V_15 ,
V_2 -> V_73 ) ;
V_2 -> V_79 = F_30 ( & V_2 -> V_77 ,
V_2 -> V_73 ) ;
}
}
V_65 = F_40 ( V_2 -> V_79 , V_2 -> V_23 ) ;
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
int V_80 = 0 ;
if ( V_2 -> V_81 -> V_14 . V_82 == 0 && V_2 -> V_75 & V_83 )
V_80 = 1 ;
for (; V_2 -> V_18 != NULL ; V_2 = V_2 -> V_18 ) {
V_2 -> V_73 += V_62 ;
if ( ! ( V_2 -> V_75 & V_83 ) || V_2 -> V_67 == 0 )
continue;
if ( V_80 && -- V_2 -> V_67 == 0 )
V_80 = 1 ;
else
V_80 = 0 ;
V_2 -> V_21 = F_30 ( & V_2 -> V_71 , V_2 -> V_73 ) + V_2 -> V_74 ;
if ( V_2 -> V_21 < V_2 -> V_18 -> V_25 ) {
V_2 -> V_74 += V_2 -> V_18 -> V_25 - V_2 -> V_21 ;
V_2 -> V_21 = V_2 -> V_18 -> V_25 ;
}
if ( V_80 ) {
if ( V_2 -> V_21 > V_2 -> V_18 -> V_70 )
V_2 -> V_18 -> V_70 = V_2 -> V_21 ;
F_13 ( V_2 ) ;
F_18 ( V_2 ) ;
F_37 ( V_2 -> V_18 ) ;
continue;
}
F_14 ( V_2 ) ;
if ( V_2 -> V_75 & V_76 ) {
V_2 -> V_79 = F_30 ( & V_2 -> V_77 , V_2 -> V_73 ) ;
#if 0
cl->cl_myf = cl->cl_myfadj + rtsc_y2x(&cl->cl_ulimit,
cl->cl_total);
myf_bound = cur_time - PSCHED_JIFFIE2US(1);
if (cl->cl_myf < myf_bound) {
delta = cur_time - cl->cl_myf;
cl->cl_myfadj += delta;
cl->cl_myf += delta;
}
#endif
}
V_65 = F_40 ( V_2 -> V_79 , V_2 -> V_23 ) ;
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
if ( V_2 -> V_75 & V_84 )
F_33 ( V_2 , V_62 ) ;
if ( V_2 -> V_75 & V_83 )
F_38 ( V_2 , V_62 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 & V_84 )
F_5 ( V_2 ) ;
}
static unsigned int
F_44 ( struct V_85 * V_86 )
{
struct V_87 * V_88 ;
unsigned int V_62 ;
V_88 = V_86 -> V_89 -> V_90 ( V_86 ) ;
if ( F_45 ( V_88 == NULL ) ) {
F_46 ( L_1 , V_86 ) ;
return 0 ;
}
V_62 = F_47 ( V_88 ) ;
return V_62 ;
}
static void
F_48 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
unsigned int V_62 = V_2 -> V_81 -> V_14 . V_82 ;
unsigned int V_91 = V_2 -> V_81 -> V_92 . V_91 ;
F_49 ( V_2 -> V_81 ) ;
F_50 ( V_2 -> V_81 , V_62 , V_91 ) ;
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
F_53 ( T_2 V_93 , struct V_85 * V_86 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_94 * V_95 ;
V_95 = F_55 ( & V_14 -> V_96 , V_93 ) ;
if ( V_95 == NULL )
return NULL ;
return F_56 ( V_95 , struct V_1 , V_97 ) ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_42 * V_98 ,
T_1 V_15 )
{
F_28 ( V_98 , & V_2 -> V_59 ) ;
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , V_15 , V_2 -> V_60 ) ;
V_2 -> V_61 = V_2 -> V_58 ;
if ( V_2 -> V_59 . V_46 <= V_2 -> V_59 . V_50 ) {
V_2 -> V_61 . V_40 = 0 ;
V_2 -> V_61 . V_49 = 0 ;
}
V_2 -> V_75 |= V_84 ;
}
static void
F_58 ( struct V_1 * V_2 , struct V_42 * V_99 )
{
F_28 ( V_99 , & V_2 -> V_72 ) ;
F_29 ( & V_2 -> V_71 , & V_2 -> V_72 , V_2 -> V_21 , V_2 -> V_73 ) ;
V_2 -> V_75 |= V_83 ;
}
static void
F_59 ( struct V_1 * V_2 , struct V_42 * V_100 ,
T_1 V_15 )
{
F_28 ( V_100 , & V_2 -> V_78 ) ;
F_29 ( & V_2 -> V_77 , & V_2 -> V_78 , V_15 , V_2 -> V_73 ) ;
V_2 -> V_75 |= V_76 ;
}
static int
F_60 ( struct V_85 * V_86 , T_2 V_93 , T_2 V_101 ,
struct V_102 * * V_103 , unsigned long * V_104 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_104 ;
struct V_1 * V_7 = NULL ;
struct V_102 * V_105 = V_103 [ V_106 ] ;
struct V_102 * V_107 [ V_108 + 1 ] ;
struct V_42 * V_98 = NULL , * V_99 = NULL , * V_100 = NULL ;
T_1 V_15 ;
int V_109 ;
if ( V_105 == NULL )
return - V_110 ;
V_109 = F_61 ( V_107 , V_108 , V_105 , V_111 , NULL ) ;
if ( V_109 < 0 )
return V_109 ;
if ( V_107 [ V_112 ] ) {
V_98 = F_62 ( V_107 [ V_112 ] ) ;
if ( V_98 -> V_47 == 0 && V_98 -> V_51 == 0 )
V_98 = NULL ;
}
if ( V_107 [ V_113 ] ) {
V_99 = F_62 ( V_107 [ V_113 ] ) ;
if ( V_99 -> V_47 == 0 && V_99 -> V_51 == 0 )
V_99 = NULL ;
}
if ( V_107 [ V_114 ] ) {
V_100 = F_62 ( V_107 [ V_114 ] ) ;
if ( V_100 -> V_47 == 0 && V_100 -> V_51 == 0 )
V_100 = NULL ;
}
if ( V_2 != NULL ) {
if ( V_101 ) {
if ( V_2 -> V_18 &&
V_2 -> V_18 -> V_97 . V_93 != V_101 )
return - V_110 ;
if ( V_2 -> V_18 == NULL && V_101 != V_115 )
return - V_110 ;
}
V_15 = F_34 () ;
if ( V_103 [ V_116 ] ) {
V_109 = F_63 ( & V_2 -> V_117 , NULL ,
& V_2 -> V_118 ,
NULL ,
F_64 ( V_86 ) ,
V_103 [ V_116 ] ) ;
if ( V_109 )
return V_109 ;
}
F_65 ( V_86 ) ;
if ( V_98 != NULL )
F_57 ( V_2 , V_98 , V_15 ) ;
if ( V_99 != NULL )
F_58 ( V_2 , V_99 ) ;
if ( V_100 != NULL )
F_59 ( V_2 , V_100 , V_15 ) ;
if ( V_2 -> V_81 -> V_14 . V_82 != 0 ) {
if ( V_2 -> V_75 & V_84 )
F_35 ( V_2 , F_44 ( V_2 -> V_81 ) ) ;
if ( V_2 -> V_75 & V_83 )
F_41 ( V_2 , 0 , V_15 ) ;
}
F_66 ( V_86 ) ;
return 0 ;
}
if ( V_101 == V_115 )
return - V_119 ;
V_7 = & V_14 -> V_120 ;
if ( V_101 ) {
V_7 = F_53 ( V_101 , V_86 ) ;
if ( V_7 == NULL )
return - V_121 ;
}
if ( V_93 == 0 || F_67 ( V_93 ^ V_86 -> V_122 ) != 0 )
return - V_110 ;
if ( F_53 ( V_93 , V_86 ) )
return - V_119 ;
if ( V_98 == NULL && V_99 == NULL )
return - V_110 ;
V_2 = F_68 ( sizeof( struct V_1 ) , V_123 ) ;
if ( V_2 == NULL )
return - V_124 ;
if ( V_103 [ V_116 ] ) {
V_109 = F_69 ( & V_2 -> V_117 , NULL , & V_2 -> V_118 ,
NULL ,
F_64 ( V_86 ) ,
V_103 [ V_116 ] ) ;
if ( V_109 ) {
F_70 ( V_2 ) ;
return V_109 ;
}
}
if ( V_98 != NULL )
F_57 ( V_2 , V_98 , 0 ) ;
if ( V_99 != NULL )
F_58 ( V_2 , V_99 ) ;
if ( V_100 != NULL )
F_59 ( V_2 , V_100 , 0 ) ;
V_2 -> V_97 . V_93 = V_93 ;
V_2 -> V_125 = 1 ;
V_2 -> V_5 = V_14 ;
V_2 -> V_18 = V_7 ;
V_2 -> V_81 = F_71 ( V_86 -> V_126 ,
& V_127 , V_93 ) ;
if ( V_2 -> V_81 == NULL )
V_2 -> V_81 = & V_128 ;
else
F_72 ( V_2 -> V_81 , true ) ;
F_73 ( & V_2 -> V_129 ) ;
V_2 -> V_19 = V_130 ;
V_2 -> V_26 = V_130 ;
F_65 ( V_86 ) ;
F_74 ( & V_14 -> V_96 , & V_2 -> V_97 ) ;
F_75 ( & V_2 -> V_131 , & V_7 -> V_129 ) ;
if ( V_7 -> V_24 == 0 )
F_48 ( V_86 , V_7 ) ;
F_51 ( V_7 ) ;
F_66 ( V_86 ) ;
F_76 ( V_86 , & V_14 -> V_96 ) ;
* V_104 = ( unsigned long ) V_2 ;
return 0 ;
}
static void
F_77 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
F_78 ( & V_2 -> V_132 ) ;
F_79 ( V_2 -> V_81 ) ;
F_80 ( & V_2 -> V_118 ) ;
if ( V_2 != & V_14 -> V_120 )
F_70 ( V_2 ) ;
}
static int
F_81 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 > 0 || V_2 -> V_133 > 0 || V_2 == & V_14 -> V_120 )
return - V_134 ;
F_65 ( V_86 ) ;
F_82 ( & V_2 -> V_131 ) ;
F_51 ( V_2 -> V_18 ) ;
F_48 ( V_86 , V_2 ) ;
F_83 ( & V_14 -> V_96 , & V_2 -> V_97 ) ;
F_84 ( -- V_2 -> V_125 == 0 ) ;
F_66 ( V_86 ) ;
return 0 ;
}
static struct V_1 *
F_85 ( struct V_87 * V_88 , struct V_85 * V_86 , int * V_135 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_136 , * V_2 ;
struct V_137 V_138 ;
struct V_139 * V_140 ;
int V_141 ;
if ( F_67 ( V_88 -> V_142 ^ V_86 -> V_122 ) == 0 &&
( V_2 = F_53 ( V_88 -> V_142 , V_86 ) ) != NULL )
if ( V_2 -> V_24 == 0 )
return V_2 ;
* V_135 = V_143 | V_144 ;
V_136 = & V_14 -> V_120 ;
V_140 = F_86 ( V_14 -> V_120 . V_132 ) ;
while ( V_140 && ( V_141 = F_87 ( V_88 , V_140 , & V_138 , false ) ) >= 0 ) {
#ifdef F_88
switch ( V_141 ) {
case V_145 :
case V_146 :
* V_135 = V_143 | V_147 ;
case V_148 :
return NULL ;
}
#endif
V_2 = (struct V_1 * ) V_138 . V_149 ;
if ( ! V_2 ) {
V_2 = F_53 ( V_138 . V_93 , V_86 ) ;
if ( ! V_2 )
break;
if ( V_2 -> V_24 >= V_136 -> V_24 )
break;
}
if ( V_2 -> V_24 == 0 )
return V_2 ;
V_140 = F_86 ( V_2 -> V_132 ) ;
V_136 = V_2 ;
}
V_2 = F_53 ( F_89 ( F_67 ( V_86 -> V_122 ) , V_14 -> V_150 ) , V_86 ) ;
if ( V_2 == NULL || V_2 -> V_24 > 0 )
return NULL ;
return V_2 ;
}
static int
F_90 ( struct V_85 * V_86 , unsigned long V_104 , struct V_85 * V_151 ,
struct V_85 * * V_152 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 > 0 )
return - V_110 ;
if ( V_151 == NULL ) {
V_151 = F_71 ( V_86 -> V_126 , & V_127 ,
V_2 -> V_97 . V_93 ) ;
if ( V_151 == NULL )
V_151 = & V_128 ;
}
* V_152 = F_91 ( V_86 , V_151 , & V_2 -> V_81 ) ;
return 0 ;
}
static struct V_85 *
F_92 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 == 0 )
return V_2 -> V_81 ;
return NULL ;
}
static void
F_93 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_81 -> V_14 . V_82 == 0 ) {
F_41 ( V_2 , 0 , 0 ) ;
F_43 ( V_2 ) ;
}
}
static unsigned long
F_94 ( struct V_85 * V_86 , T_2 V_93 )
{
struct V_1 * V_2 = F_53 ( V_93 , V_86 ) ;
if ( V_2 != NULL )
V_2 -> V_125 ++ ;
return ( unsigned long ) V_2 ;
}
static void
F_95 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( -- V_2 -> V_125 == 0 )
F_77 ( V_86 , V_2 ) ;
}
static unsigned long
F_96 ( struct V_85 * V_86 , unsigned long V_7 , T_2 V_93 )
{
struct V_1 * V_4 = (struct V_1 * ) V_7 ;
struct V_1 * V_2 = F_53 ( V_93 , V_86 ) ;
if ( V_2 != NULL ) {
if ( V_4 != NULL && V_4 -> V_24 <= V_2 -> V_24 )
return 0 ;
V_2 -> V_133 ++ ;
}
return ( unsigned long ) V_2 ;
}
static void
F_97 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
V_2 -> V_133 -- ;
}
static struct V_139 T_3 * *
F_98 ( struct V_85 * V_86 , unsigned long V_104 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 == NULL )
V_2 = & V_14 -> V_120 ;
return & V_2 -> V_132 ;
}
static int
F_99 ( struct V_87 * V_88 , int V_153 , struct V_44 * V_43 )
{
struct V_42 V_154 ;
V_154 . V_47 = F_26 ( V_43 -> V_46 ) ;
V_154 . V_39 = F_27 ( V_43 -> V_40 ) ;
V_154 . V_51 = F_26 ( V_43 -> V_50 ) ;
if ( F_100 ( V_88 , V_153 , sizeof( V_154 ) , & V_154 ) )
goto V_155;
return V_88 -> V_62 ;
V_155:
return - 1 ;
}
static int
F_101 ( struct V_87 * V_88 , struct V_1 * V_2 )
{
if ( ( V_2 -> V_75 & V_84 ) &&
( F_99 ( V_88 , V_112 , & V_2 -> V_59 ) < 0 ) )
goto V_155;
if ( ( V_2 -> V_75 & V_83 ) &&
( F_99 ( V_88 , V_113 , & V_2 -> V_72 ) < 0 ) )
goto V_155;
if ( ( V_2 -> V_75 & V_76 ) &&
( F_99 ( V_88 , V_114 , & V_2 -> V_78 ) < 0 ) )
goto V_155;
return V_88 -> V_62 ;
V_155:
return - 1 ;
}
static int
F_102 ( struct V_85 * V_86 , unsigned long V_104 , struct V_87 * V_88 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
struct V_102 * V_158 ;
V_157 -> V_159 = V_2 -> V_18 ? V_2 -> V_18 -> V_97 . V_93 :
V_115 ;
V_157 -> V_160 = V_2 -> V_97 . V_93 ;
if ( V_2 -> V_24 == 0 )
V_157 -> V_161 = V_2 -> V_81 -> V_122 ;
V_158 = F_103 ( V_88 , V_106 ) ;
if ( V_158 == NULL )
goto V_155;
if ( F_101 ( V_88 , V_2 ) < 0 )
goto V_155;
return F_104 ( V_88 , V_158 ) ;
V_155:
F_105 ( V_88 , V_158 ) ;
return - V_162 ;
}
static int
F_106 ( struct V_85 * V_86 , unsigned long V_104 ,
struct V_163 * V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
struct V_164 V_165 ;
V_2 -> V_92 . V_91 = V_2 -> V_81 -> V_92 . V_91 ;
V_165 . V_24 = V_2 -> V_24 ;
V_165 . V_166 = V_2 -> V_68 ;
V_165 . V_167 = V_2 -> V_73 ;
V_165 . V_168 = V_2 -> V_60 ;
if ( F_107 ( F_64 ( V_86 ) , V_39 , NULL , & V_2 -> V_117 ) < 0 ||
F_108 ( V_39 , & V_2 -> V_118 ) < 0 ||
F_109 ( V_39 , NULL , & V_2 -> V_92 , V_2 -> V_81 -> V_14 . V_82 ) < 0 )
return - 1 ;
return F_110 ( V_39 , & V_165 , sizeof( V_165 ) ) ;
}
static void
F_111 ( struct V_85 * V_86 , struct V_169 * V_104 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 ;
unsigned int V_170 ;
if ( V_104 -> V_171 )
return;
for ( V_170 = 0 ; V_170 < V_14 -> V_96 . V_172 ; V_170 ++ ) {
F_112 (cl, &q->clhash.hash[i],
cl_common.hnode) {
if ( V_104 -> V_173 < V_104 -> V_174 ) {
V_104 -> V_173 ++ ;
continue;
}
if ( V_104 -> V_175 ( V_86 , ( unsigned long ) V_2 , V_104 ) < 0 ) {
V_104 -> V_171 = 1 ;
return;
}
V_104 -> V_173 ++ ;
}
}
}
static void
F_113 ( struct V_85 * V_86 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 ;
T_1 V_176 = 0 ;
V_2 = F_11 ( V_14 ) ;
if ( V_2 )
V_176 = V_2 -> V_10 ;
if ( V_14 -> V_120 . V_23 != 0 ) {
if ( V_176 == 0 || V_176 > V_14 -> V_120 . V_23 )
V_176 = V_14 -> V_120 . V_23 ;
}
F_114 ( V_176 == 0 ) ;
F_115 ( & V_14 -> V_177 , V_176 ) ;
}
static int
F_116 ( struct V_85 * V_86 , struct V_102 * V_105 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_178 * V_179 ;
int V_109 ;
if ( V_105 == NULL || F_117 ( V_105 ) < sizeof( * V_179 ) )
return - V_110 ;
V_179 = F_62 ( V_105 ) ;
V_14 -> V_150 = V_179 -> V_150 ;
V_109 = F_118 ( & V_14 -> V_96 ) ;
if ( V_109 < 0 )
return V_109 ;
V_14 -> V_6 = V_130 ;
V_14 -> V_120 . V_97 . V_93 = V_86 -> V_122 ;
V_14 -> V_120 . V_125 = 1 ;
V_14 -> V_120 . V_5 = V_14 ;
V_14 -> V_120 . V_81 = F_71 ( V_86 -> V_126 , & V_127 ,
V_86 -> V_122 ) ;
if ( V_14 -> V_120 . V_81 == NULL )
V_14 -> V_120 . V_81 = & V_128 ;
else
F_72 ( V_14 -> V_120 . V_81 , true ) ;
F_73 ( & V_14 -> V_120 . V_129 ) ;
V_14 -> V_120 . V_19 = V_130 ;
V_14 -> V_120 . V_26 = V_130 ;
F_74 ( & V_14 -> V_96 , & V_14 -> V_120 . V_97 ) ;
F_76 ( V_86 , & V_14 -> V_96 ) ;
F_119 ( & V_14 -> V_177 , V_86 ) ;
return 0 ;
}
static int
F_120 ( struct V_85 * V_86 , struct V_102 * V_105 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_178 * V_179 ;
if ( V_105 == NULL || F_117 ( V_105 ) < sizeof( * V_179 ) )
return - V_110 ;
V_179 = F_62 ( V_105 ) ;
F_65 ( V_86 ) ;
V_14 -> V_150 = V_179 -> V_150 ;
F_66 ( V_86 ) ;
return 0 ;
}
static void
F_121 ( struct V_1 * V_2 )
{
V_2 -> V_73 = 0 ;
V_2 -> V_60 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_68 = 0 ;
V_2 -> V_69 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_67 = 0 ;
V_2 -> V_19 = V_130 ;
V_2 -> V_26 = V_130 ;
F_49 ( V_2 -> V_81 ) ;
if ( V_2 -> V_75 & V_84 )
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , 0 , 0 ) ;
if ( V_2 -> V_75 & V_83 )
F_29 ( & V_2 -> V_71 , & V_2 -> V_72 , 0 , 0 ) ;
if ( V_2 -> V_75 & V_76 )
F_29 ( & V_2 -> V_77 , & V_2 -> V_78 , 0 , 0 ) ;
}
static void
F_122 ( struct V_85 * V_86 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 ;
unsigned int V_170 ;
for ( V_170 = 0 ; V_170 < V_14 -> V_96 . V_172 ; V_170 ++ ) {
F_112 (cl, &q->clhash.hash[i], cl_common.hnode)
F_121 ( V_2 ) ;
}
V_14 -> V_6 = V_130 ;
F_123 ( & V_14 -> V_177 ) ;
V_86 -> V_92 . V_91 = 0 ;
V_86 -> V_14 . V_82 = 0 ;
}
static void
F_124 ( struct V_85 * V_86 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_180 * V_181 ;
struct V_1 * V_2 ;
unsigned int V_170 ;
for ( V_170 = 0 ; V_170 < V_14 -> V_96 . V_172 ; V_170 ++ ) {
F_112 (cl, &q->clhash.hash[i], cl_common.hnode)
F_78 ( & V_2 -> V_132 ) ;
}
for ( V_170 = 0 ; V_170 < V_14 -> V_96 . V_172 ; V_170 ++ ) {
F_125 (cl, next, &q->clhash.hash[i],
cl_common.hnode)
F_77 ( V_86 , V_2 ) ;
}
F_126 ( & V_14 -> V_96 ) ;
F_123 ( & V_14 -> V_177 ) ;
}
static int
F_127 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
unsigned char * V_182 = F_128 ( V_88 ) ;
struct V_178 V_179 ;
V_179 . V_150 = V_14 -> V_150 ;
if ( F_100 ( V_88 , V_106 , sizeof( V_179 ) , & V_179 ) )
goto V_155;
return V_88 -> V_62 ;
V_155:
F_129 ( V_88 , V_182 ) ;
return - 1 ;
}
static int
F_130 ( struct V_87 * V_88 , struct V_85 * V_86 , struct V_87 * * V_183 )
{
struct V_1 * V_2 ;
int V_184 ( V_109 ) ;
V_2 = F_85 ( V_88 , V_86 , & V_109 ) ;
if ( V_2 == NULL ) {
if ( V_109 & V_144 )
F_131 ( V_86 ) ;
F_132 ( V_88 , V_183 ) ;
return V_109 ;
}
V_109 = F_133 ( V_88 , V_2 -> V_81 , V_183 ) ;
if ( F_45 ( V_109 != V_143 ) ) {
if ( F_134 ( V_109 ) ) {
V_2 -> V_92 . V_185 ++ ;
F_131 ( V_86 ) ;
}
return V_109 ;
}
if ( V_2 -> V_81 -> V_14 . V_82 == 1 ) {
F_42 ( V_2 , F_47 ( V_88 ) ) ;
if ( V_2 -> V_75 & V_84 )
V_2 -> V_81 -> V_89 -> V_90 ( V_2 -> V_81 ) ;
}
F_135 ( V_86 , V_88 ) ;
V_86 -> V_14 . V_82 ++ ;
return V_143 ;
}
static struct V_87 *
F_136 ( struct V_85 * V_86 )
{
struct V_13 * V_14 = F_54 ( V_86 ) ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
T_1 V_15 ;
unsigned int V_57 ;
int V_186 = 0 ;
if ( V_86 -> V_14 . V_82 == 0 )
return NULL ;
V_15 = F_34 () ;
V_2 = F_8 ( V_14 , V_15 ) ;
if ( V_2 ) {
V_186 = 1 ;
} else {
V_2 = F_16 ( & V_14 -> V_120 , V_15 ) ;
if ( V_2 == NULL ) {
F_137 ( V_86 ) ;
F_113 ( V_86 ) ;
return NULL ;
}
}
V_88 = F_138 ( V_2 -> V_81 ) ;
if ( V_88 == NULL ) {
F_46 ( L_2 , V_2 -> V_81 ) ;
return NULL ;
}
F_139 ( & V_2 -> V_117 , V_88 ) ;
F_41 ( V_2 , F_47 ( V_88 ) , V_15 ) ;
if ( V_186 )
V_2 -> V_60 += F_47 ( V_88 ) ;
if ( V_2 -> V_81 -> V_14 . V_82 != 0 ) {
if ( V_2 -> V_75 & V_84 ) {
V_57 = F_44 ( V_2 -> V_81 ) ;
if ( V_186 )
F_35 ( V_2 , V_57 ) ;
else
F_36 ( V_2 , V_57 ) ;
}
} else {
F_43 ( V_2 ) ;
}
F_140 ( V_86 , V_88 ) ;
F_141 ( V_86 , V_88 ) ;
V_86 -> V_14 . V_82 -- ;
return V_88 ;
}
static int T_4
F_142 ( void )
{
return F_143 ( & V_187 ) ;
}
static void T_5
F_144 ( void )
{
F_145 ( & V_187 ) ;
}
