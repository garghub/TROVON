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
static unsigned int
F_42 ( struct V_84 * V_85 )
{
struct V_86 * V_87 ;
unsigned int V_62 ;
V_87 = V_85 -> V_88 -> V_89 ( V_85 ) ;
if ( F_43 ( V_87 == NULL ) ) {
F_44 ( L_1 , V_85 ) ;
return 0 ;
}
V_62 = F_45 ( V_87 ) ;
return V_62 ;
}
static void
F_46 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
unsigned int V_62 = V_2 -> V_81 -> V_14 . V_82 ;
unsigned int V_90 = V_2 -> V_81 -> V_91 . V_90 ;
F_47 ( V_2 -> V_81 ) ;
F_48 ( V_2 -> V_81 , V_62 , V_90 ) ;
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_1 * V_4 ;
unsigned int V_24 ;
do {
V_24 = 0 ;
F_50 (p, &cl->children, siblings) {
if ( V_4 -> V_24 >= V_24 )
V_24 = V_4 -> V_24 + 1 ;
}
V_2 -> V_24 = V_24 ;
} while ( ( V_2 = V_2 -> V_18 ) != NULL );
}
static inline struct V_1 *
F_51 ( T_2 V_92 , struct V_84 * V_85 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_93 * V_94 ;
V_94 = F_53 ( & V_14 -> V_95 , V_92 ) ;
if ( V_94 == NULL )
return NULL ;
return F_54 ( V_94 , struct V_1 , V_96 ) ;
}
static void
F_55 ( struct V_1 * V_2 , struct V_42 * V_97 ,
T_1 V_15 )
{
F_28 ( V_97 , & V_2 -> V_59 ) ;
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , V_15 , V_2 -> V_60 ) ;
V_2 -> V_61 = V_2 -> V_58 ;
if ( V_2 -> V_59 . V_46 <= V_2 -> V_59 . V_50 ) {
V_2 -> V_61 . V_40 = 0 ;
V_2 -> V_61 . V_49 = 0 ;
}
V_2 -> V_75 |= V_98 ;
}
static void
F_56 ( struct V_1 * V_2 , struct V_42 * V_99 )
{
F_28 ( V_99 , & V_2 -> V_72 ) ;
F_29 ( & V_2 -> V_71 , & V_2 -> V_72 , V_2 -> V_21 , V_2 -> V_73 ) ;
V_2 -> V_75 |= V_83 ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_42 * V_100 ,
T_1 V_15 )
{
F_28 ( V_100 , & V_2 -> V_78 ) ;
F_29 ( & V_2 -> V_77 , & V_2 -> V_78 , V_15 , V_2 -> V_73 ) ;
V_2 -> V_75 |= V_76 ;
}
static int
F_58 ( struct V_84 * V_85 , T_2 V_92 , T_2 V_101 ,
struct V_102 * * V_103 , unsigned long * V_104 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_104 ;
struct V_1 * V_7 = NULL ;
struct V_102 * V_105 = V_103 [ V_106 ] ;
struct V_102 * V_107 [ V_108 + 1 ] ;
struct V_42 * V_97 = NULL , * V_99 = NULL , * V_100 = NULL ;
T_1 V_15 ;
int V_109 ;
if ( V_105 == NULL )
return - V_110 ;
V_109 = F_59 ( V_107 , V_108 , V_105 , V_111 , NULL ) ;
if ( V_109 < 0 )
return V_109 ;
if ( V_107 [ V_112 ] ) {
V_97 = F_60 ( V_107 [ V_112 ] ) ;
if ( V_97 -> V_47 == 0 && V_97 -> V_51 == 0 )
V_97 = NULL ;
}
if ( V_107 [ V_113 ] ) {
V_99 = F_60 ( V_107 [ V_113 ] ) ;
if ( V_99 -> V_47 == 0 && V_99 -> V_51 == 0 )
V_99 = NULL ;
}
if ( V_107 [ V_114 ] ) {
V_100 = F_60 ( V_107 [ V_114 ] ) ;
if ( V_100 -> V_47 == 0 && V_100 -> V_51 == 0 )
V_100 = NULL ;
}
if ( V_2 != NULL ) {
int V_115 ;
if ( V_101 ) {
if ( V_2 -> V_18 &&
V_2 -> V_18 -> V_96 . V_92 != V_101 )
return - V_110 ;
if ( V_2 -> V_18 == NULL && V_101 != V_116 )
return - V_110 ;
}
V_15 = F_34 () ;
if ( V_103 [ V_117 ] ) {
V_109 = F_61 ( & V_2 -> V_118 , NULL ,
& V_2 -> V_119 ,
NULL ,
F_62 ( V_85 ) ,
V_103 [ V_117 ] ) ;
if ( V_109 )
return V_109 ;
}
F_63 ( V_85 ) ;
V_115 = V_2 -> V_75 ;
if ( V_97 != NULL )
F_55 ( V_2 , V_97 , V_15 ) ;
if ( V_99 != NULL )
F_56 ( V_2 , V_99 ) ;
if ( V_100 != NULL )
F_57 ( V_2 , V_100 , V_15 ) ;
if ( V_2 -> V_81 -> V_14 . V_82 != 0 ) {
int V_62 = F_42 ( V_2 -> V_81 ) ;
if ( V_2 -> V_75 & V_98 ) {
if ( V_115 & V_98 )
F_35 ( V_2 , V_62 ) ;
else
F_33 ( V_2 , V_62 ) ;
}
if ( V_2 -> V_75 & V_83 ) {
if ( V_115 & V_83 )
F_41 ( V_2 , 0 , V_15 ) ;
else
F_38 ( V_2 , V_62 ) ;
}
}
F_64 ( V_85 ) ;
return 0 ;
}
if ( V_101 == V_116 )
return - V_120 ;
V_7 = & V_14 -> V_121 ;
if ( V_101 ) {
V_7 = F_51 ( V_101 , V_85 ) ;
if ( V_7 == NULL )
return - V_122 ;
}
if ( V_92 == 0 || F_65 ( V_92 ^ V_85 -> V_123 ) != 0 )
return - V_110 ;
if ( F_51 ( V_92 , V_85 ) )
return - V_120 ;
if ( V_97 == NULL && V_99 == NULL )
return - V_110 ;
V_2 = F_66 ( sizeof( struct V_1 ) , V_124 ) ;
if ( V_2 == NULL )
return - V_125 ;
V_109 = F_67 ( & V_2 -> V_126 , & V_2 -> V_127 ) ;
if ( V_109 ) {
F_68 ( V_2 ) ;
return V_109 ;
}
if ( V_103 [ V_117 ] ) {
V_109 = F_69 ( & V_2 -> V_118 , NULL , & V_2 -> V_119 ,
NULL ,
F_62 ( V_85 ) ,
V_103 [ V_117 ] ) ;
if ( V_109 ) {
F_70 ( V_2 -> V_126 ) ;
F_68 ( V_2 ) ;
return V_109 ;
}
}
if ( V_97 != NULL )
F_55 ( V_2 , V_97 , 0 ) ;
if ( V_99 != NULL )
F_56 ( V_2 , V_99 ) ;
if ( V_100 != NULL )
F_57 ( V_2 , V_100 , 0 ) ;
V_2 -> V_96 . V_92 = V_92 ;
V_2 -> V_5 = V_14 ;
V_2 -> V_18 = V_7 ;
V_2 -> V_81 = F_71 ( V_85 -> V_128 ,
& V_129 , V_92 ) ;
if ( V_2 -> V_81 == NULL )
V_2 -> V_81 = & V_130 ;
else
F_72 ( V_2 -> V_81 , true ) ;
F_73 ( & V_2 -> V_131 ) ;
V_2 -> V_19 = V_132 ;
V_2 -> V_26 = V_132 ;
F_63 ( V_85 ) ;
F_74 ( & V_14 -> V_95 , & V_2 -> V_96 ) ;
F_75 ( & V_2 -> V_133 , & V_7 -> V_131 ) ;
if ( V_7 -> V_24 == 0 )
F_46 ( V_85 , V_7 ) ;
F_49 ( V_7 ) ;
F_64 ( V_85 ) ;
F_76 ( V_85 , & V_14 -> V_95 ) ;
* V_104 = ( unsigned long ) V_2 ;
return 0 ;
}
static void
F_77 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
F_70 ( V_2 -> V_126 ) ;
F_78 ( V_2 -> V_81 ) ;
F_79 ( & V_2 -> V_119 ) ;
if ( V_2 != & V_14 -> V_121 )
F_68 ( V_2 ) ;
}
static int
F_80 ( struct V_84 * V_85 , unsigned long V_104 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 > 0 || V_2 -> V_134 > 0 || V_2 == & V_14 -> V_121 )
return - V_135 ;
F_63 ( V_85 ) ;
F_81 ( & V_2 -> V_133 ) ;
F_49 ( V_2 -> V_18 ) ;
F_46 ( V_85 , V_2 ) ;
F_82 ( & V_14 -> V_95 , & V_2 -> V_96 ) ;
F_64 ( V_85 ) ;
F_77 ( V_85 , V_2 ) ;
return 0 ;
}
static struct V_1 *
F_83 ( struct V_86 * V_87 , struct V_84 * V_85 , int * V_136 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_137 , * V_2 ;
struct V_138 V_139 ;
struct V_140 * V_141 ;
int V_142 ;
if ( F_65 ( V_87 -> V_143 ^ V_85 -> V_123 ) == 0 &&
( V_2 = F_51 ( V_87 -> V_143 , V_85 ) ) != NULL )
if ( V_2 -> V_24 == 0 )
return V_2 ;
* V_136 = V_144 | V_145 ;
V_137 = & V_14 -> V_121 ;
V_141 = F_84 ( V_14 -> V_121 . V_127 ) ;
while ( V_141 && ( V_142 = F_85 ( V_87 , V_141 , & V_139 , false ) ) >= 0 ) {
#ifdef F_86
switch ( V_142 ) {
case V_146 :
case V_147 :
case V_148 :
* V_136 = V_144 | V_149 ;
case V_150 :
return NULL ;
}
#endif
V_2 = (struct V_1 * ) V_139 . V_151 ;
if ( ! V_2 ) {
V_2 = F_51 ( V_139 . V_92 , V_85 ) ;
if ( ! V_2 )
break;
if ( V_2 -> V_24 >= V_137 -> V_24 )
break;
}
if ( V_2 -> V_24 == 0 )
return V_2 ;
V_141 = F_84 ( V_2 -> V_127 ) ;
V_137 = V_2 ;
}
V_2 = F_51 ( F_87 ( F_65 ( V_85 -> V_123 ) , V_14 -> V_152 ) , V_85 ) ;
if ( V_2 == NULL || V_2 -> V_24 > 0 )
return NULL ;
return V_2 ;
}
static int
F_88 ( struct V_84 * V_85 , unsigned long V_104 , struct V_84 * V_153 ,
struct V_84 * * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 > 0 )
return - V_110 ;
if ( V_153 == NULL ) {
V_153 = F_71 ( V_85 -> V_128 , & V_129 ,
V_2 -> V_96 . V_92 ) ;
if ( V_153 == NULL )
V_153 = & V_130 ;
}
* V_154 = F_89 ( V_85 , V_153 , & V_2 -> V_81 ) ;
return 0 ;
}
static struct V_84 *
F_90 ( struct V_84 * V_85 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 -> V_24 == 0 )
return V_2 -> V_81 ;
return NULL ;
}
static void
F_91 ( struct V_84 * V_85 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
F_41 ( V_2 , 0 , 0 ) ;
if ( V_2 -> V_75 & V_98 )
F_5 ( V_2 ) ;
}
static unsigned long
F_92 ( struct V_84 * V_85 , T_2 V_92 )
{
return ( unsigned long ) F_51 ( V_92 , V_85 ) ;
}
static unsigned long
F_93 ( struct V_84 * V_85 , unsigned long V_7 , T_2 V_92 )
{
struct V_1 * V_4 = (struct V_1 * ) V_7 ;
struct V_1 * V_2 = F_51 ( V_92 , V_85 ) ;
if ( V_2 != NULL ) {
if ( V_4 != NULL && V_4 -> V_24 <= V_2 -> V_24 )
return 0 ;
V_2 -> V_134 ++ ;
}
return ( unsigned long ) V_2 ;
}
static void
F_94 ( struct V_84 * V_85 , unsigned long V_104 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
V_2 -> V_134 -- ;
}
static struct V_155 * F_95 ( struct V_84 * V_85 , unsigned long V_104 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
if ( V_2 == NULL )
V_2 = & V_14 -> V_121 ;
return V_2 -> V_126 ;
}
static int
F_96 ( struct V_86 * V_87 , int V_156 , struct V_44 * V_43 )
{
struct V_42 V_157 ;
V_157 . V_47 = F_26 ( V_43 -> V_46 ) ;
V_157 . V_39 = F_27 ( V_43 -> V_40 ) ;
V_157 . V_51 = F_26 ( V_43 -> V_50 ) ;
if ( F_97 ( V_87 , V_156 , sizeof( V_157 ) , & V_157 ) )
goto V_158;
return V_87 -> V_62 ;
V_158:
return - 1 ;
}
static int
F_98 ( struct V_86 * V_87 , struct V_1 * V_2 )
{
if ( ( V_2 -> V_75 & V_98 ) &&
( F_96 ( V_87 , V_112 , & V_2 -> V_59 ) < 0 ) )
goto V_158;
if ( ( V_2 -> V_75 & V_83 ) &&
( F_96 ( V_87 , V_113 , & V_2 -> V_72 ) < 0 ) )
goto V_158;
if ( ( V_2 -> V_75 & V_76 ) &&
( F_96 ( V_87 , V_114 , & V_2 -> V_78 ) < 0 ) )
goto V_158;
return V_87 -> V_62 ;
V_158:
return - 1 ;
}
static int
F_99 ( struct V_84 * V_85 , unsigned long V_104 , struct V_86 * V_87 ,
struct V_159 * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
struct V_102 * V_161 ;
V_160 -> V_162 = V_2 -> V_18 ? V_2 -> V_18 -> V_96 . V_92 :
V_116 ;
V_160 -> V_163 = V_2 -> V_96 . V_92 ;
if ( V_2 -> V_24 == 0 )
V_160 -> V_164 = V_2 -> V_81 -> V_123 ;
V_161 = F_100 ( V_87 , V_106 ) ;
if ( V_161 == NULL )
goto V_158;
if ( F_98 ( V_87 , V_2 ) < 0 )
goto V_158;
return F_101 ( V_87 , V_161 ) ;
V_158:
F_102 ( V_87 , V_161 ) ;
return - V_165 ;
}
static int
F_103 ( struct V_84 * V_85 , unsigned long V_104 ,
struct V_166 * V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_104 ;
struct V_167 V_168 ;
V_2 -> V_91 . V_90 = V_2 -> V_81 -> V_91 . V_90 ;
V_168 . V_24 = V_2 -> V_24 ;
V_168 . V_169 = V_2 -> V_68 ;
V_168 . V_170 = V_2 -> V_73 ;
V_168 . V_171 = V_2 -> V_60 ;
if ( F_104 ( F_62 ( V_85 ) , V_39 , NULL , & V_2 -> V_118 ) < 0 ||
F_105 ( V_39 , & V_2 -> V_119 ) < 0 ||
F_106 ( V_39 , NULL , & V_2 -> V_91 , V_2 -> V_81 -> V_14 . V_82 ) < 0 )
return - 1 ;
return F_107 ( V_39 , & V_168 , sizeof( V_168 ) ) ;
}
static void
F_108 ( struct V_84 * V_85 , struct V_172 * V_104 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 ;
unsigned int V_173 ;
if ( V_104 -> V_174 )
return;
for ( V_173 = 0 ; V_173 < V_14 -> V_95 . V_175 ; V_173 ++ ) {
F_109 (cl, &q->clhash.hash[i],
cl_common.hnode) {
if ( V_104 -> V_176 < V_104 -> V_177 ) {
V_104 -> V_176 ++ ;
continue;
}
if ( V_104 -> V_178 ( V_85 , ( unsigned long ) V_2 , V_104 ) < 0 ) {
V_104 -> V_174 = 1 ;
return;
}
V_104 -> V_176 ++ ;
}
}
}
static void
F_110 ( struct V_84 * V_85 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 ;
T_1 V_179 = 0 ;
V_2 = F_11 ( V_14 ) ;
if ( V_2 )
V_179 = V_2 -> V_10 ;
if ( V_14 -> V_121 . V_23 != 0 ) {
if ( V_179 == 0 || V_179 > V_14 -> V_121 . V_23 )
V_179 = V_14 -> V_121 . V_23 ;
}
F_111 ( V_179 == 0 ) ;
F_112 ( & V_14 -> V_180 , V_179 ) ;
}
static int
F_113 ( struct V_84 * V_85 , struct V_102 * V_105 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_181 * V_182 ;
int V_109 ;
F_114 ( & V_14 -> V_180 , V_85 ) ;
if ( V_105 == NULL || F_115 ( V_105 ) < sizeof( * V_182 ) )
return - V_110 ;
V_182 = F_60 ( V_105 ) ;
V_14 -> V_152 = V_182 -> V_152 ;
V_109 = F_116 ( & V_14 -> V_95 ) ;
if ( V_109 < 0 )
return V_109 ;
V_14 -> V_6 = V_132 ;
V_109 = F_67 ( & V_14 -> V_121 . V_126 , & V_14 -> V_121 . V_127 ) ;
if ( V_109 )
return V_109 ;
V_14 -> V_121 . V_96 . V_92 = V_85 -> V_123 ;
V_14 -> V_121 . V_5 = V_14 ;
V_14 -> V_121 . V_81 = F_71 ( V_85 -> V_128 , & V_129 ,
V_85 -> V_123 ) ;
if ( V_14 -> V_121 . V_81 == NULL )
V_14 -> V_121 . V_81 = & V_130 ;
else
F_72 ( V_14 -> V_121 . V_81 , true ) ;
F_73 ( & V_14 -> V_121 . V_131 ) ;
V_14 -> V_121 . V_19 = V_132 ;
V_14 -> V_121 . V_26 = V_132 ;
F_74 ( & V_14 -> V_95 , & V_14 -> V_121 . V_96 ) ;
F_76 ( V_85 , & V_14 -> V_95 ) ;
return 0 ;
}
static int
F_117 ( struct V_84 * V_85 , struct V_102 * V_105 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_181 * V_182 ;
if ( V_105 == NULL || F_115 ( V_105 ) < sizeof( * V_182 ) )
return - V_110 ;
V_182 = F_60 ( V_105 ) ;
F_63 ( V_85 ) ;
V_14 -> V_152 = V_182 -> V_152 ;
F_64 ( V_85 ) ;
return 0 ;
}
static void
F_118 ( struct V_1 * V_2 )
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
V_2 -> V_19 = V_132 ;
V_2 -> V_26 = V_132 ;
F_47 ( V_2 -> V_81 ) ;
if ( V_2 -> V_75 & V_98 )
F_29 ( & V_2 -> V_58 , & V_2 -> V_59 , 0 , 0 ) ;
if ( V_2 -> V_75 & V_83 )
F_29 ( & V_2 -> V_71 , & V_2 -> V_72 , 0 , 0 ) ;
if ( V_2 -> V_75 & V_76 )
F_29 ( & V_2 -> V_77 , & V_2 -> V_78 , 0 , 0 ) ;
}
static void
F_119 ( struct V_84 * V_85 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_14 -> V_95 . V_175 ; V_173 ++ ) {
F_109 (cl, &q->clhash.hash[i], cl_common.hnode)
F_118 ( V_2 ) ;
}
V_14 -> V_6 = V_132 ;
F_120 ( & V_14 -> V_180 ) ;
V_85 -> V_91 . V_90 = 0 ;
V_85 -> V_14 . V_82 = 0 ;
}
static void
F_121 ( struct V_84 * V_85 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_183 * V_184 ;
struct V_1 * V_2 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_14 -> V_95 . V_175 ; V_173 ++ ) {
F_109 (cl, &q->clhash.hash[i], cl_common.hnode) {
F_70 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
}
}
for ( V_173 = 0 ; V_173 < V_14 -> V_95 . V_175 ; V_173 ++ ) {
F_122 (cl, next, &q->clhash.hash[i],
cl_common.hnode)
F_77 ( V_85 , V_2 ) ;
}
F_123 ( & V_14 -> V_95 ) ;
F_120 ( & V_14 -> V_180 ) ;
}
static int
F_124 ( struct V_84 * V_85 , struct V_86 * V_87 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
unsigned char * V_185 = F_125 ( V_87 ) ;
struct V_181 V_182 ;
V_182 . V_152 = V_14 -> V_152 ;
if ( F_97 ( V_87 , V_106 , sizeof( V_182 ) , & V_182 ) )
goto V_158;
return V_87 -> V_62 ;
V_158:
F_126 ( V_87 , V_185 ) ;
return - 1 ;
}
static int
F_127 ( struct V_86 * V_87 , struct V_84 * V_85 , struct V_86 * * V_186 )
{
struct V_1 * V_2 ;
int V_187 ( V_109 ) ;
V_2 = F_83 ( V_87 , V_85 , & V_109 ) ;
if ( V_2 == NULL ) {
if ( V_109 & V_145 )
F_128 ( V_85 ) ;
F_129 ( V_87 , V_186 ) ;
return V_109 ;
}
V_109 = F_130 ( V_87 , V_2 -> V_81 , V_186 ) ;
if ( F_43 ( V_109 != V_144 ) ) {
if ( F_131 ( V_109 ) ) {
V_2 -> V_91 . V_188 ++ ;
F_128 ( V_85 ) ;
}
return V_109 ;
}
if ( V_2 -> V_81 -> V_14 . V_82 == 1 ) {
unsigned int V_62 = F_45 ( V_87 ) ;
if ( V_2 -> V_75 & V_98 )
F_33 ( V_2 , V_62 ) ;
if ( V_2 -> V_75 & V_83 )
F_38 ( V_2 , V_62 ) ;
if ( V_2 -> V_75 & V_98 )
V_2 -> V_81 -> V_88 -> V_89 ( V_2 -> V_81 ) ;
}
F_132 ( V_85 , V_87 ) ;
V_85 -> V_14 . V_82 ++ ;
return V_144 ;
}
static struct V_86 *
F_133 ( struct V_84 * V_85 )
{
struct V_13 * V_14 = F_52 ( V_85 ) ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 V_15 ;
unsigned int V_57 ;
int V_189 = 0 ;
if ( V_85 -> V_14 . V_82 == 0 )
return NULL ;
V_15 = F_34 () ;
V_2 = F_8 ( V_14 , V_15 ) ;
if ( V_2 ) {
V_189 = 1 ;
} else {
V_2 = F_16 ( & V_14 -> V_121 , V_15 ) ;
if ( V_2 == NULL ) {
F_134 ( V_85 ) ;
F_110 ( V_85 ) ;
return NULL ;
}
}
V_87 = F_135 ( V_2 -> V_81 ) ;
if ( V_87 == NULL ) {
F_44 ( L_2 , V_2 -> V_81 ) ;
return NULL ;
}
F_136 ( & V_2 -> V_118 , V_87 ) ;
F_41 ( V_2 , F_45 ( V_87 ) , V_15 ) ;
if ( V_189 )
V_2 -> V_60 += F_45 ( V_87 ) ;
if ( V_2 -> V_75 & V_98 ) {
if ( V_2 -> V_81 -> V_14 . V_82 != 0 ) {
V_57 = F_42 ( V_2 -> V_81 ) ;
if ( V_189 )
F_35 ( V_2 , V_57 ) ;
else
F_36 ( V_2 , V_57 ) ;
} else {
F_5 ( V_2 ) ;
}
}
F_137 ( V_85 , V_87 ) ;
F_138 ( V_85 , V_87 ) ;
V_85 -> V_14 . V_82 -- ;
return V_87 ;
}
static int T_3
F_139 ( void )
{
return F_140 ( & V_190 ) ;
}
static void T_4
F_141 ( void )
{
F_142 ( & V_190 ) ;
}
