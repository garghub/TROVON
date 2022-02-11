static unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 * sizeof( V_2 ) , V_3 ) / V_3 ;
}
static unsigned long F_3 ( unsigned long V_4 )
{
unsigned long V_5 = sizeof( struct V_6 ) +
( V_4 * sizeof( struct V_7 * ) ) ;
return V_4 + F_2 ( V_5 , V_3 ) / V_3 ;
}
static long F_4 ( unsigned long V_8 , bool V_9 )
{
long V_10 = 0 ;
if ( ! V_11 || ! V_11 -> V_12 )
return V_10 ;
F_5 ( & V_11 -> V_12 -> V_13 ) ;
if ( V_9 ) {
unsigned long V_14 , V_15 ;
V_14 = V_11 -> V_12 -> V_16 + V_8 ;
V_15 = F_6 ( V_17 ) >> V_18 ;
if ( V_14 > V_15 && ! F_7 ( V_19 ) )
V_10 = - V_20 ;
else
V_11 -> V_12 -> V_16 += V_8 ;
} else {
if ( F_8 ( V_8 > V_11 -> V_12 -> V_16 ) )
V_8 = V_11 -> V_12 -> V_16 ;
V_11 -> V_12 -> V_16 -= V_8 ;
}
F_9 ( L_1 , V_11 -> V_21 ,
V_9 ? '+' : '-' ,
V_8 << V_18 ,
V_11 -> V_12 -> V_16 << V_18 ,
F_6 ( V_17 ) ,
V_10 ? L_2 : L_3 ) ;
F_10 ( & V_11 -> V_12 -> V_13 ) ;
return V_10 ;
}
static void F_11 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_12 ( V_23 ,
struct V_24 , V_26 ) ;
F_13 ( V_25 -> V_27 ) ;
F_14 ( V_25 ) ;
}
static void F_15 ( struct V_28 * V_28 )
{
struct V_24 * V_25 = F_12 ( V_28 ,
struct V_24 , V_28 ) ;
F_16 ( & V_25 -> V_29 ) ;
F_17 ( & V_25 -> V_26 , F_11 ) ;
}
extern void F_18 ( struct V_30 * V_30 ,
struct V_31 * V_32 )
{
int V_33 ;
struct V_6 * V_34 ;
struct V_24 * V_25 , * V_35 ;
struct V_36 * V_37 = NULL ;
F_19 (stt, &kvm->arch.spapr_tce_tables, list) {
V_37 = F_20 ( V_32 ) ;
if ( F_21 ( ! V_37 ) )
continue;
F_22 (stit, tmp, &stt->iommu_tables, next) {
for ( V_33 = 0 ; V_33 < V_38 ; ++ V_33 ) {
if ( V_37 -> V_39 [ V_33 ] != V_25 -> V_27 )
continue;
F_23 ( & V_25 -> V_28 , F_15 ) ;
return;
}
}
}
}
extern long F_24 ( struct V_30 * V_30 , int V_40 ,
struct V_31 * V_32 )
{
struct V_6 * V_34 = NULL ;
bool V_41 = false ;
struct V_42 * V_27 = NULL ;
struct V_36 * V_37 ;
long V_33 ;
struct V_24 * V_25 ;
struct V_43 V_44 ;
V_44 = F_25 ( V_40 ) ;
if ( ! V_44 . V_45 )
return - V_46 ;
F_19 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_34 == V_44 . V_45 -> V_47 ) {
V_41 = true ;
break;
}
}
F_26 ( V_44 ) ;
if ( ! V_41 )
return - V_48 ;
V_37 = F_20 ( V_32 ) ;
if ( F_21 ( ! V_37 ) )
return - V_49 ;
for ( V_33 = 0 ; V_33 < V_38 ; ++ V_33 ) {
struct V_42 * V_50 = V_37 -> V_39 [ V_33 ] ;
if ( ! V_50 )
continue;
if ( ( V_50 -> V_51 == V_34 -> V_52 ) &&
( V_50 -> V_53 == V_34 -> V_54 ) &&
( V_50 -> V_55 == V_34 -> V_56 ) ) {
V_27 = F_27 ( V_50 ) ;
break;
}
}
if ( ! V_27 )
return - V_48 ;
F_19 (stit, &stt->iommu_tables, next) {
if ( V_27 != V_25 -> V_27 )
continue;
if ( ! F_28 ( & V_25 -> V_28 ) ) {
F_13 ( V_27 ) ;
return - V_57 ;
}
return 0 ;
}
V_25 = F_29 ( sizeof( * V_25 ) , V_58 ) ;
if ( ! V_25 ) {
F_13 ( V_27 ) ;
return - V_20 ;
}
V_25 -> V_27 = V_27 ;
F_30 ( & V_25 -> V_28 ) ;
F_31 ( & V_25 -> V_29 , & V_34 -> V_59 ) ;
return 0 ;
}
static void F_32 ( struct V_22 * V_23 )
{
struct V_6 * V_34 = F_12 ( V_23 ,
struct V_6 , V_26 ) ;
unsigned long V_33 , V_60 = F_1 ( V_34 -> V_56 ) ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ )
F_33 ( V_34 -> V_61 [ V_33 ] ) ;
F_14 ( V_34 ) ;
}
static int F_34 ( struct V_62 * V_63 )
{
struct V_6 * V_34 = V_63 -> V_64 -> V_65 -> V_47 ;
struct V_7 * V_7 ;
if ( V_63 -> V_66 >= F_1 ( V_34 -> V_56 ) )
return V_67 ;
V_7 = V_34 -> V_61 [ V_63 -> V_66 ] ;
F_35 ( V_7 ) ;
V_63 -> V_7 = V_7 ;
return 0 ;
}
static int F_36 ( struct V_45 * V_45 , struct V_68 * V_64 )
{
V_64 -> V_69 = & V_70 ;
return 0 ;
}
static int F_37 ( struct V_71 * V_71 , struct V_45 * V_72 )
{
struct V_6 * V_34 = V_72 -> V_47 ;
struct V_24 * V_25 , * V_35 ;
F_16 ( & V_34 -> V_73 ) ;
F_22 (stit, tmp, &stt->iommu_tables, next) {
F_21 ( ! F_38 ( & V_25 -> V_28 ) ) ;
while ( 1 ) {
if ( F_23 ( & V_25 -> V_28 , F_15 ) )
break;
}
}
F_39 ( V_34 -> V_30 ) ;
F_4 (
F_3 ( F_1 ( V_34 -> V_56 ) ) , false ) ;
F_17 ( & V_34 -> V_26 , F_32 ) ;
return 0 ;
}
long F_40 ( struct V_30 * V_30 ,
struct V_74 * args )
{
struct V_6 * V_34 = NULL ;
unsigned long V_60 , V_56 ;
int V_10 = - V_20 ;
int V_33 ;
if ( ! args -> V_56 )
return - V_48 ;
F_41 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_34 -> V_75 == args -> V_75 )
return - V_76 ;
}
V_56 = F_42 ( args -> V_56 , V_3 >> 3 ) ;
V_60 = F_1 ( V_56 ) ;
V_10 = F_4 ( F_3 ( V_60 ) , true ) ;
if ( V_10 ) {
V_34 = NULL ;
goto V_77;
}
V_10 = - V_20 ;
V_34 = F_29 ( sizeof( * V_34 ) + V_60 * sizeof( struct V_7 * ) ,
V_58 ) ;
if ( ! V_34 )
goto V_77;
V_34 -> V_75 = args -> V_75 ;
V_34 -> V_52 = args -> V_52 ;
V_34 -> V_54 = args -> V_54 ;
V_34 -> V_56 = V_56 ;
V_34 -> V_30 = V_30 ;
F_43 ( & V_34 -> V_59 ) ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_34 -> V_61 [ V_33 ] = F_44 ( V_58 | V_78 ) ;
if ( ! V_34 -> V_61 [ V_33 ] )
goto V_77;
}
F_45 ( V_30 ) ;
F_46 ( & V_30 -> V_79 ) ;
F_31 ( & V_34 -> V_73 , & V_30 -> V_80 . V_81 ) ;
F_47 ( & V_30 -> V_79 ) ;
return F_48 ( L_4 , & V_82 ,
V_34 , V_83 | V_84 ) ;
V_77:
if ( V_34 ) {
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ )
if ( V_34 -> V_61 [ V_33 ] )
F_33 ( V_34 -> V_61 [ V_33 ] ) ;
F_14 ( V_34 ) ;
}
return V_10 ;
}
static void F_49 ( struct V_42 * V_27 , unsigned long V_85 )
{
unsigned long V_86 = 0 ;
enum V_87 V_88 = V_89 ;
F_50 ( V_27 , V_85 , & V_86 , & V_88 ) ;
}
static long F_51 ( struct V_30 * V_30 ,
struct V_42 * V_27 , unsigned long V_85 )
{
struct V_90 * V_91 = NULL ;
const unsigned long V_92 = 1ULL << V_27 -> V_51 ;
unsigned long * V_93 = F_52 ( V_27 , V_85 ) ;
if ( ! V_93 )
return V_94 ;
V_91 = F_53 ( V_30 -> V_12 , * V_93 , V_92 ) ;
if ( ! V_91 )
return V_94 ;
F_54 ( V_91 ) ;
* V_93 = 0 ;
return V_95 ;
}
static long F_55 ( struct V_30 * V_30 ,
struct V_42 * V_27 , unsigned long V_85 )
{
enum V_87 V_88 = V_89 ;
unsigned long V_86 = 0 ;
long V_10 ;
if ( F_8 ( F_50 ( V_27 , V_85 , & V_86 , & V_88 ) ) )
return V_96 ;
if ( V_88 == V_89 )
return V_95 ;
V_10 = F_51 ( V_30 , V_27 , V_85 ) ;
if ( V_10 != V_95 )
F_50 ( V_27 , V_85 , & V_86 , & V_88 ) ;
return V_10 ;
}
long F_56 ( struct V_30 * V_30 , struct V_42 * V_27 ,
unsigned long V_85 , unsigned long V_97 ,
enum V_87 V_88 )
{
long V_10 ;
unsigned long V_86 , * V_93 = F_52 ( V_27 , V_85 ) ;
struct V_90 * V_91 ;
if ( ! V_93 )
return V_94 ;
V_91 = F_53 ( V_30 -> V_12 , V_97 , 1ULL << V_27 -> V_51 ) ;
if ( ! V_91 )
return V_94 ;
if ( F_8 ( F_57 ( V_91 , V_97 , & V_86 ) ) )
return V_96 ;
if ( F_58 ( V_91 ) )
return V_98 ;
V_10 = F_50 ( V_27 , V_85 , & V_86 , & V_88 ) ;
if ( F_8 ( V_10 ) ) {
F_54 ( V_91 ) ;
return V_96 ;
}
if ( V_88 != V_89 )
F_51 ( V_30 , V_27 , V_85 ) ;
* V_93 = V_97 ;
return 0 ;
}
long F_59 ( struct V_99 * V_100 , unsigned long V_75 ,
unsigned long V_101 , unsigned long V_102 )
{
struct V_6 * V_34 ;
long V_10 , V_103 ;
struct V_24 * V_25 ;
unsigned long V_85 , V_97 = 0 ;
enum V_87 V_88 ;
V_34 = F_60 ( V_100 -> V_30 , V_75 ) ;
if ( ! V_34 )
return V_94 ;
V_10 = F_61 ( V_34 , V_101 , 1 ) ;
if ( V_10 != V_95 )
return V_10 ;
V_10 = F_62 ( V_34 , V_102 ) ;
if ( V_10 != V_95 )
return V_10 ;
V_88 = F_63 ( V_102 ) ;
if ( ( V_88 != V_89 ) && F_64 ( V_100 -> V_30 ,
V_102 & ~ ( V_104 | V_105 ) , & V_97 , NULL ) )
return V_106 ;
V_85 = V_101 >> V_34 -> V_52 ;
F_65 (stit, &stt->iommu_tables, next) {
if ( V_88 == V_89 ) {
V_10 = F_55 ( V_100 -> V_30 ,
V_25 -> V_27 , V_85 ) ;
} else {
V_103 = F_66 ( & V_100 -> V_30 -> V_107 ) ;
V_10 = F_56 ( V_100 -> V_30 , V_25 -> V_27 ,
V_85 , V_97 , V_88 ) ;
F_67 ( & V_100 -> V_30 -> V_107 , V_103 ) ;
}
if ( V_10 == V_95 )
continue;
if ( V_10 == V_94 )
return V_10 ;
F_8 ( 1 ) ;
F_49 ( V_25 -> V_27 , V_85 ) ;
}
F_68 ( V_34 , V_85 , V_102 ) ;
return V_95 ;
}
long F_69 ( struct V_99 * V_100 ,
unsigned long V_75 , unsigned long V_101 ,
unsigned long V_108 , unsigned long V_60 )
{
struct V_6 * V_34 ;
long V_33 , V_10 = V_95 , V_103 ;
unsigned long V_85 , V_97 = 0 ;
V_2 T_1 * V_109 ;
V_2 V_102 ;
struct V_24 * V_25 ;
V_34 = F_60 ( V_100 -> V_30 , V_75 ) ;
if ( ! V_34 )
return V_94 ;
V_85 = V_101 >> V_34 -> V_52 ;
if ( V_60 > 512 )
return V_106 ;
if ( V_108 & ( V_110 - 1 ) )
return V_106 ;
V_10 = F_61 ( V_34 , V_101 , V_60 ) ;
if ( V_10 != V_95 )
return V_10 ;
V_103 = F_66 ( & V_100 -> V_30 -> V_107 ) ;
if ( F_64 ( V_100 -> V_30 , V_108 , & V_97 , NULL ) ) {
V_10 = V_94 ;
goto V_111;
}
V_109 = ( V_2 T_1 * ) V_97 ;
for ( V_33 = 0 ; V_33 < V_60 ; ++ V_33 ) {
if ( F_70 ( V_102 , V_109 + V_33 ) ) {
V_10 = V_94 ;
goto V_111;
}
V_102 = F_71 ( V_102 ) ;
V_10 = F_62 ( V_34 , V_102 ) ;
if ( V_10 != V_95 )
goto V_111;
if ( F_64 ( V_100 -> V_30 ,
V_102 & ~ ( V_104 | V_105 ) ,
& V_97 , NULL ) )
return V_106 ;
F_65 (stit, &stt->iommu_tables, next) {
V_10 = F_56 ( V_100 -> V_30 ,
V_25 -> V_27 , V_85 + V_33 , V_97 ,
F_63 ( V_102 ) ) ;
if ( V_10 == V_95 )
continue;
if ( V_10 == V_94 )
goto V_111;
F_8 ( 1 ) ;
F_49 ( V_25 -> V_27 , V_85 ) ;
}
F_68 ( V_34 , V_85 + V_33 , V_102 ) ;
}
V_111:
F_67 ( & V_100 -> V_30 -> V_107 , V_103 ) ;
return V_10 ;
}
long F_72 ( struct V_99 * V_100 ,
unsigned long V_75 , unsigned long V_101 ,
unsigned long V_112 , unsigned long V_60 )
{
struct V_6 * V_34 ;
long V_33 , V_10 ;
struct V_24 * V_25 ;
V_34 = F_60 ( V_100 -> V_30 , V_75 ) ;
if ( ! V_34 )
return V_94 ;
V_10 = F_61 ( V_34 , V_101 , V_60 ) ;
if ( V_10 != V_95 )
return V_10 ;
if ( V_112 & ( V_105 | V_104 ) )
return V_106 ;
F_65 (stit, &stt->iommu_tables, next) {
unsigned long V_85 = V_101 >> V_25 -> V_27 -> V_51 ;
for ( V_33 = 0 ; V_33 < V_60 ; ++ V_33 ) {
V_10 = F_55 ( V_100 -> V_30 ,
V_25 -> V_27 , V_85 + V_33 ) ;
if ( V_10 == V_95 )
continue;
if ( V_10 == V_94 )
return V_10 ;
F_8 ( 1 ) ;
F_49 ( V_25 -> V_27 , V_85 ) ;
}
}
for ( V_33 = 0 ; V_33 < V_60 ; ++ V_33 , V_101 += ( 1ULL << V_34 -> V_52 ) )
F_68 ( V_34 , V_101 >> V_34 -> V_52 , V_112 ) ;
return V_95 ;
}
