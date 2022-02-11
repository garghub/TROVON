static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_4 * V_5 ;
V_5 = V_3 -> V_5 ;
F_3 ( & V_5 -> V_6 ) ;
V_5 -> V_7 += V_3 -> V_8 ;
F_4 ( & V_5 -> V_6 ) ;
F_5 ( V_5 ) ;
F_6 ( V_3 ) ;
}
static void F_7 ( long V_8 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
if ( ! V_9 -> V_5 )
return;
if ( F_8 ( & V_9 -> V_5 -> V_6 ) ) {
V_9 -> V_5 -> V_7 += V_8 ;
F_4 ( & V_9 -> V_5 -> V_6 ) ;
return;
}
V_3 = F_9 ( sizeof( struct V_3 ) , V_10 ) ;
if ( ! V_3 )
return;
V_5 = F_10 ( V_9 ) ;
if ( ! V_5 ) {
F_6 ( V_3 ) ;
return;
}
F_11 ( & V_3 -> V_2 , F_1 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_8 = V_8 ;
F_12 ( & V_3 -> V_2 ) ;
}
static bool F_13 ( unsigned long V_11 )
{
if ( F_14 ( V_11 ) ) {
bool V_12 ;
struct V_13 * V_14 = F_15 ( V_11 ) ;
struct V_13 * V_15 = F_16 ( V_14 ) ;
V_12 = ! ! ( F_17 ( V_15 ) ) ;
if ( V_15 != V_14 ) {
F_18 () ;
if ( F_19 ( V_14 ) )
return V_12 ;
}
return F_17 ( V_14 ) ;
}
return true ;
}
static int F_20 ( unsigned long V_11 , int V_16 )
{
if ( ! F_13 ( V_11 ) ) {
struct V_13 * V_13 = F_15 ( V_11 ) ;
if ( V_16 & V_17 )
F_21 ( V_13 ) ;
F_22 ( V_13 ) ;
return 1 ;
}
return 0 ;
}
static long F_23 ( struct V_18 * V_19 , T_1 V_20 ,
long V_8 , int V_16 )
{
long V_21 , V_22 = 0 ;
for ( V_21 = 0 ; V_21 < V_8 ; V_21 ++ , V_20 += V_23 ) {
unsigned long V_11 ;
V_11 = F_24 ( V_19 -> V_24 , V_20 ) >> V_25 ;
if ( V_11 ) {
F_25 ( V_19 -> V_24 , V_20 , V_23 ) ;
V_22 += F_20 ( V_11 , V_16 ) ;
}
}
return V_22 ;
}
static void F_26 ( struct V_18 * V_19 , T_1 V_20 ,
long V_8 , int V_16 )
{
long V_22 ;
V_22 = F_23 ( V_19 , V_20 , V_8 , V_16 ) ;
F_7 ( - V_22 ) ;
}
static int F_27 ( unsigned long V_26 , int V_16 , unsigned long * V_11 )
{
struct V_13 * V_13 [ 1 ] ;
struct V_27 * V_28 ;
int V_29 = - V_30 ;
if ( F_28 ( V_26 , 1 , ! ! ( V_16 & V_17 ) , V_13 ) == 1 ) {
* V_11 = F_29 ( V_13 [ 0 ] ) ;
return 0 ;
}
F_30 ( & V_9 -> V_5 -> V_6 ) ;
V_28 = F_31 ( V_9 -> V_5 , V_26 , V_26 + 1 ) ;
if ( V_28 && V_28 -> V_31 & V_32 ) {
* V_11 = ( ( V_26 - V_28 -> V_33 ) >> V_25 ) + V_28 -> V_34 ;
if ( F_13 ( * V_11 ) )
V_29 = 0 ;
}
F_32 ( & V_9 -> V_5 -> V_6 ) ;
return V_29 ;
}
static int F_33 ( struct V_18 * V_19 , T_1 V_20 ,
unsigned long V_26 , long V_8 , int V_16 )
{
T_1 V_35 = V_20 ;
long V_21 , V_36 = 0 ;
int V_29 ;
for ( V_21 = 0 ; V_21 < V_8 ; V_21 ++ , V_20 += V_23 )
if ( F_24 ( V_19 -> V_24 , V_20 ) )
return - V_37 ;
V_20 = V_35 ;
if ( V_19 -> V_38 )
V_16 |= V_39 ;
for ( V_21 = 0 ; V_21 < V_8 ; V_21 ++ , V_20 += V_23 , V_26 += V_23 ) {
unsigned long V_11 = 0 ;
V_29 = F_27 ( V_26 , V_16 , & V_11 ) ;
if ( V_29 ) {
F_23 ( V_19 , V_35 , V_21 , V_16 ) ;
return V_29 ;
}
if ( ! F_13 ( V_11 ) )
V_36 ++ ;
V_29 = F_34 ( V_19 -> V_24 , V_20 ,
( V_40 ) V_11 << V_25 ,
V_23 , V_16 ) ;
if ( V_29 ) {
F_20 ( V_11 , V_16 ) ;
F_23 ( V_19 , V_35 , V_21 , V_16 ) ;
return V_29 ;
}
}
F_7 ( V_36 ) ;
return 0 ;
}
static inline bool F_35 ( T_1 V_41 , T_2 V_42 ,
T_1 V_43 , T_2 V_44 )
{
if ( V_41 < V_43 )
return ( V_43 - V_41 < V_42 ) ;
else if ( V_43 < V_41 )
return ( V_41 - V_43 < V_44 ) ;
return ( V_42 > 0 && V_44 > 0 ) ;
}
static struct V_45 * F_36 ( struct V_18 * V_19 ,
T_1 V_35 , T_2 V_46 )
{
struct V_45 * V_47 ;
F_37 (dma, &iommu->dma_list, next) {
if ( F_35 ( V_47 -> V_20 , F_38 ( V_47 -> V_8 ) ,
V_35 , V_46 ) )
return V_47 ;
}
return NULL ;
}
static long F_39 ( struct V_18 * V_19 , T_1 V_35 ,
T_2 V_46 , struct V_45 * V_47 )
{
struct V_45 * V_48 ;
long V_49 , V_50 ;
if ( V_35 <= V_47 -> V_20 &&
V_35 + V_46 >= V_47 -> V_20 + F_38 ( V_47 -> V_8 ) ) {
F_26 ( V_19 , V_47 -> V_20 , V_47 -> V_8 , V_47 -> V_16 ) ;
F_40 ( & V_47 -> V_51 ) ;
V_49 = V_47 -> V_8 ;
F_6 ( V_47 ) ;
return V_49 ;
}
if ( V_35 <= V_47 -> V_20 ) {
T_2 V_52 ;
V_52 = V_35 + V_46 - V_47 -> V_20 ;
V_49 = V_52 >> V_25 ;
F_26 ( V_19 , V_47 -> V_20 , V_49 , V_47 -> V_16 ) ;
V_47 -> V_20 += V_52 ;
V_47 -> V_26 += V_52 ;
V_47 -> V_8 -= V_49 ;
return V_49 ;
}
if ( V_35 + V_46 >= V_47 -> V_20 + F_38 ( V_47 -> V_8 ) ) {
T_2 V_52 ;
V_52 = V_47 -> V_20 + F_38 ( V_47 -> V_8 ) - V_35 ;
V_50 = V_52 >> V_25 ;
F_26 ( V_19 , V_35 , V_50 , V_47 -> V_16 ) ;
V_47 -> V_8 -= V_50 ;
return V_50 ;
}
V_49 = ( V_35 - V_47 -> V_20 ) >> V_25 ;
V_50 = V_47 -> V_8 - ( V_46 >> V_25 ) - V_49 ;
V_48 = F_41 ( sizeof *V_48 , V_10 ) ;
if ( ! V_48 )
return - V_53 ;
F_26 ( V_19 , V_35 , V_46 >> V_25 , V_47 -> V_16 ) ;
V_47 -> V_8 = V_49 ;
V_48 -> V_8 = V_50 ;
V_48 -> V_20 = V_35 + V_46 ;
V_48 -> V_26 = V_47 -> V_26 + F_38 ( V_49 ) + V_46 ;
V_48 -> V_16 = V_47 -> V_16 ;
F_42 ( & V_48 -> V_51 , & V_19 -> V_54 ) ;
return V_46 >> V_25 ;
}
static int F_43 ( struct V_18 * V_19 ,
struct V_55 * V_56 )
{
long V_29 = 0 , V_8 = V_56 -> V_46 >> V_25 ;
struct V_45 * V_47 , * V_57 ;
T_3 V_58 ;
V_58 = ( ( T_3 ) 1 << F_44 ( V_19 -> V_24 -> V_59 -> V_60 ) ) - 1 ;
if ( V_56 -> V_20 & V_58 )
return - V_61 ;
if ( V_56 -> V_46 & V_58 )
return - V_61 ;
F_45 ( V_58 & V_62 ) ;
F_46 ( & V_19 -> V_63 ) ;
F_47 (dma, tmp, &iommu->dma_list, next) {
if ( F_35 ( V_47 -> V_20 , F_38 ( V_47 -> V_8 ) ,
V_56 -> V_20 , V_56 -> V_46 ) ) {
V_29 = F_39 ( V_19 , V_56 -> V_20 ,
V_56 -> V_46 , V_47 ) ;
if ( V_29 > 0 )
V_8 -= V_29 ;
if ( V_29 < 0 || V_8 == 0 )
break;
}
}
F_48 ( & V_19 -> V_63 ) ;
return V_29 > 0 ? 0 : ( int ) V_29 ;
}
static int F_49 ( struct V_18 * V_19 ,
struct V_64 * V_65 )
{
struct V_45 * V_47 , * V_66 = NULL ;
T_1 V_20 = V_65 -> V_20 ;
unsigned long V_36 , V_67 , V_26 = V_65 -> V_26 ;
T_2 V_46 = V_65 -> V_46 ;
int V_29 = 0 , V_16 = 0 ;
T_3 V_58 ;
long V_8 ;
V_58 = ( ( T_3 ) 1 << F_44 ( V_19 -> V_24 -> V_59 -> V_60 ) ) - 1 ;
if ( V_65 -> V_68 & V_69 )
V_16 |= V_17 ;
if ( V_65 -> V_68 & V_70 )
V_16 |= V_71 ;
if ( ! V_16 )
return - V_61 ;
if ( V_26 & V_58 )
return - V_61 ;
if ( V_20 & V_58 )
return - V_61 ;
if ( V_46 & V_58 )
return - V_61 ;
F_45 ( V_58 & V_62 ) ;
if ( V_20 + V_46 && V_20 + V_46 < V_20 )
return - V_61 ;
if ( V_26 + V_46 && V_26 + V_46 < V_26 )
return - V_61 ;
V_8 = V_46 >> V_25 ;
if ( ! V_8 )
return - V_61 ;
F_46 ( & V_19 -> V_63 ) ;
if ( F_36 ( V_19 , V_20 , V_46 ) ) {
V_29 = - V_37 ;
goto V_72;
}
V_36 = V_9 -> V_5 -> V_7 + V_8 ;
V_67 = F_50 ( V_73 ) >> V_25 ;
if ( V_36 > V_67 && ! F_51 ( V_74 ) ) {
F_52 ( L_1 ,
V_75 , F_50 ( V_73 ) ) ;
V_29 = - V_53 ;
goto V_72;
}
V_29 = F_33 ( V_19 , V_20 , V_26 , V_8 , V_16 ) ;
if ( V_29 )
goto V_72;
if ( V_20 ) {
V_47 = F_36 ( V_19 , V_20 - 1 , 1 ) ;
if ( V_47 && V_47 -> V_16 == V_16 &&
V_47 -> V_26 + F_38 ( V_47 -> V_8 ) == V_26 ) {
V_47 -> V_8 += V_8 ;
V_20 = V_47 -> V_20 ;
V_26 = V_47 -> V_26 ;
V_8 = V_47 -> V_8 ;
V_46 = F_38 ( V_8 ) ;
V_66 = V_47 ;
}
}
if ( V_20 + V_46 ) {
V_47 = F_36 ( V_19 , V_20 + V_46 , 1 ) ;
if ( V_47 && V_47 -> V_16 == V_16 &&
V_47 -> V_26 == V_26 + V_46 ) {
V_47 -> V_8 += V_8 ;
V_47 -> V_20 = V_20 ;
V_47 -> V_26 = V_26 ;
if ( V_66 ) {
F_40 ( & V_66 -> V_51 ) ;
F_6 ( V_66 ) ;
}
V_66 = V_47 ;
}
}
if ( ! V_66 ) {
V_47 = F_41 ( sizeof *V_47 , V_10 ) ;
if ( ! V_47 ) {
V_29 = - V_53 ;
F_26 ( V_19 , V_20 , V_8 , V_16 ) ;
goto V_72;
}
V_47 -> V_8 = V_8 ;
V_47 -> V_20 = V_20 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_16 = V_16 ;
F_42 ( & V_47 -> V_51 , & V_19 -> V_54 ) ;
}
V_72:
F_48 ( & V_19 -> V_63 ) ;
return V_29 ;
}
static int F_53 ( void * V_76 ,
struct V_77 * V_77 )
{
struct V_18 * V_19 = V_76 ;
struct V_78 * V_79 , * V_57 ;
int V_29 ;
V_79 = F_41 ( sizeof( * V_79 ) , V_10 ) ;
if ( ! V_79 )
return - V_53 ;
F_46 ( & V_19 -> V_63 ) ;
F_37 (tmp, &iommu->group_list, next) {
if ( V_57 -> V_77 == V_77 ) {
F_48 ( & V_19 -> V_63 ) ;
F_6 ( V_79 ) ;
return - V_61 ;
}
}
V_29 = F_54 ( V_19 -> V_24 , V_77 ) ;
if ( V_29 ) {
F_48 ( & V_19 -> V_63 ) ;
F_6 ( V_79 ) ;
return V_29 ;
}
V_79 -> V_77 = V_77 ;
F_42 ( & V_79 -> V_51 , & V_19 -> V_80 ) ;
F_48 ( & V_19 -> V_63 ) ;
return 0 ;
}
static void F_55 ( void * V_76 ,
struct V_77 * V_77 )
{
struct V_18 * V_19 = V_76 ;
struct V_78 * V_79 ;
F_46 ( & V_19 -> V_63 ) ;
F_37 (group, &iommu->group_list, next) {
if ( V_79 -> V_77 == V_77 ) {
F_56 ( V_19 -> V_24 , V_77 ) ;
F_40 ( & V_79 -> V_51 ) ;
F_6 ( V_79 ) ;
break;
}
}
F_48 ( & V_19 -> V_63 ) ;
}
static void * F_57 ( unsigned long V_81 )
{
struct V_18 * V_19 ;
if ( V_81 != V_82 )
return F_58 ( - V_61 ) ;
V_19 = F_41 ( sizeof( * V_19 ) , V_10 ) ;
if ( ! V_19 )
return F_58 ( - V_53 ) ;
F_59 ( & V_19 -> V_80 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_63 ) ;
V_19 -> V_24 = F_61 ( & V_83 ) ;
if ( ! V_19 -> V_24 ) {
F_6 ( V_19 ) ;
return F_58 ( - V_84 ) ;
}
if ( ! V_85 &&
! F_62 ( V_19 -> V_24 , V_86 ) ) {
F_52 ( L_2 ,
V_75 ) ;
F_63 ( V_19 -> V_24 ) ;
F_6 ( V_19 ) ;
return F_58 ( - V_87 ) ;
}
return V_19 ;
}
static void F_64 ( void * V_76 )
{
struct V_18 * V_19 = V_76 ;
struct V_78 * V_79 , * V_88 ;
struct V_45 * V_47 , * V_89 ;
F_47 (group, group_tmp, &iommu->group_list, next) {
F_56 ( V_19 -> V_24 , V_79 -> V_77 ) ;
F_40 ( & V_79 -> V_51 ) ;
F_6 ( V_79 ) ;
}
F_47 (dma, dma_tmp, &iommu->dma_list, next) {
F_26 ( V_19 , V_47 -> V_20 , V_47 -> V_8 , V_47 -> V_16 ) ;
F_40 ( & V_47 -> V_51 ) ;
F_6 ( V_47 ) ;
}
F_63 ( V_19 -> V_24 ) ;
V_19 -> V_24 = NULL ;
F_6 ( V_19 ) ;
}
static long F_65 ( void * V_76 ,
unsigned int V_90 , unsigned long V_81 )
{
struct V_18 * V_19 = V_76 ;
unsigned long V_91 ;
if ( V_90 == V_92 ) {
switch ( V_81 ) {
case V_82 :
return 1 ;
default:
return 0 ;
}
} else if ( V_90 == V_93 ) {
struct V_94 V_95 ;
V_91 = F_66 ( struct V_94 , V_96 ) ;
if ( F_67 ( & V_95 , ( void V_97 * ) V_81 , V_91 ) )
return - V_30 ;
if ( V_95 . V_98 < V_91 )
return - V_61 ;
V_95 . V_68 = 0 ;
V_95 . V_96 = V_19 -> V_24 -> V_59 -> V_60 ;
return F_68 ( ( void V_97 * ) V_81 , & V_95 , V_91 ) ;
} else if ( V_90 == V_99 ) {
struct V_64 V_65 ;
T_4 V_58 = V_70 |
V_69 ;
V_91 = F_66 ( struct V_64 , V_46 ) ;
if ( F_67 ( & V_65 , ( void V_97 * ) V_81 , V_91 ) )
return - V_30 ;
if ( V_65 . V_98 < V_91 || V_65 . V_68 & ~ V_58 )
return - V_61 ;
return F_49 ( V_19 , & V_65 ) ;
} else if ( V_90 == V_100 ) {
struct V_55 V_56 ;
V_91 = F_66 ( struct V_55 , V_46 ) ;
if ( F_67 ( & V_56 , ( void V_97 * ) V_81 , V_91 ) )
return - V_30 ;
if ( V_56 . V_98 < V_91 || V_56 . V_68 )
return - V_61 ;
return F_43 ( V_19 , & V_56 ) ;
}
return - V_101 ;
}
static int T_5 F_69 ( void )
{
if ( ! F_70 ( & V_83 ) )
return - V_102 ;
return F_71 ( & V_103 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_103 ) ;
}
