struct V_1 * F_1 ( struct V_2 * V_2 ,
unsigned long V_3 )
{
struct V_1 * V_4 ;
F_2 (stt, &kvm->arch.spapr_tce_tables, list)
if ( V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
long F_3 ( struct V_1 * V_4 , unsigned long V_5 )
{
unsigned long V_6 = V_5 & ~ ( V_7 | V_8 ) ;
enum V_9 V_10 = F_4 ( V_5 ) ;
if ( V_10 == V_11 )
return V_12 ;
if ( F_5 ( V_4 -> V_13 , V_6 ) )
return V_14 ;
return V_12 ;
}
static T_1 * F_6 ( struct V_15 * V_15 )
{
#if F_7 ( V_16 ) || F_7 ( V_17 )
#error TODO: fix to avoid page_address() here
#endif
return ( T_1 * ) F_8 ( V_15 ) ;
}
void F_9 ( struct V_1 * V_4 ,
unsigned long V_18 , unsigned long V_5 )
{
struct V_15 * V_15 ;
T_1 * V_19 ;
V_18 -= V_4 -> V_20 ;
V_15 = V_4 -> V_21 [ V_18 / V_22 ] ;
V_19 = F_6 ( V_15 ) ;
V_19 [ V_18 % V_22 ] = V_5 ;
}
long F_10 ( struct V_2 * V_2 , unsigned long V_6 ,
unsigned long * V_23 , unsigned long * * V_24 )
{
unsigned long V_25 = V_6 >> V_26 ;
struct V_27 * V_28 ;
V_28 = F_11 ( F_12 ( V_2 ) , V_25 ) ;
if ( ! V_28 )
return - V_29 ;
* V_23 = F_13 ( V_28 , V_25 ) |
( V_6 & ~ ( V_30 | V_7 | V_8 ) ) ;
#ifdef F_14
if ( V_24 )
* V_24 = & V_28 -> V_31 . V_32 [ V_25 - V_28 -> V_33 ] ;
#endif
return 0 ;
}
static void F_15 ( struct V_34 * V_19 , unsigned long V_35 )
{
unsigned long V_36 = 0 ;
enum V_9 V_10 = V_11 ;
F_16 ( V_19 , V_35 , & V_36 , & V_10 ) ;
}
static long F_17 ( struct V_2 * V_2 ,
struct V_34 * V_19 , unsigned long V_35 )
{
struct V_37 * V_38 = NULL ;
const unsigned long V_39 = 1ULL << V_19 -> V_40 ;
unsigned long * V_41 = F_18 ( V_19 , V_35 ) ;
if ( ! V_41 )
return V_42 ;
V_41 = ( void * ) F_19 ( V_41 ) ;
if ( F_20 ( ! V_41 ) )
return V_43 ;
V_38 = F_21 ( V_2 -> V_44 , * V_41 , V_39 ) ;
if ( ! V_38 )
return V_42 ;
F_22 ( V_38 ) ;
* V_41 = 0 ;
return V_12 ;
}
static long F_23 ( struct V_2 * V_2 ,
struct V_34 * V_19 , unsigned long V_35 )
{
enum V_9 V_10 = V_11 ;
unsigned long V_36 = 0 ;
long V_45 ;
if ( F_16 ( V_19 , V_35 , & V_36 , & V_10 ) )
return V_42 ;
if ( V_10 == V_11 )
return V_12 ;
V_45 = F_17 ( V_2 , V_19 , V_35 ) ;
if ( V_45 )
F_16 ( V_19 , V_35 , & V_36 , & V_10 ) ;
return V_45 ;
}
static long F_24 ( struct V_2 * V_2 , struct V_34 * V_19 ,
unsigned long V_35 , unsigned long V_23 ,
enum V_9 V_10 )
{
long V_45 ;
unsigned long V_36 = 0 ;
unsigned long * V_41 = F_18 ( V_19 , V_35 ) ;
struct V_37 * V_38 ;
if ( ! V_41 )
return V_42 ;
V_38 = F_21 ( V_2 -> V_44 , V_23 , 1ULL << V_19 -> V_40 ) ;
if ( ! V_38 )
return V_42 ;
if ( F_20 ( F_25 ( V_38 , V_23 , & V_36 ) ) )
return V_43 ;
V_41 = ( void * ) F_19 ( V_41 ) ;
if ( F_20 ( ! V_41 ) )
return V_43 ;
if ( F_20 ( F_26 ( V_38 ) ) )
return V_46 ;
V_45 = F_16 ( V_19 , V_35 , & V_36 , & V_10 ) ;
if ( V_45 ) {
F_22 ( V_38 ) ;
return V_42 ;
}
if ( V_10 != V_11 )
F_17 ( V_2 , V_19 , V_35 ) ;
* V_41 = V_23 ;
return 0 ;
}
long F_27 ( struct V_47 * V_48 , unsigned long V_3 ,
unsigned long V_49 , unsigned long V_5 )
{
struct V_1 * V_4 ;
long V_45 ;
struct V_50 * V_51 ;
unsigned long V_35 , V_23 = 0 ;
enum V_9 V_10 ;
if ( F_28 ( V_48 -> V_2 ) )
return V_42 ;
V_4 = F_1 ( V_48 -> V_2 , V_3 ) ;
if ( ! V_4 )
return V_42 ;
V_45 = F_29 ( V_4 , V_49 , 1 ) ;
if ( V_45 != V_12 )
return V_45 ;
V_45 = F_3 ( V_4 , V_5 ) ;
if ( V_45 != V_12 )
return V_45 ;
V_10 = F_4 ( V_5 ) ;
if ( ( V_10 != V_11 ) && F_10 ( V_48 -> V_2 ,
V_5 & ~ ( V_7 | V_8 ) , & V_23 , NULL ) )
return V_14 ;
V_35 = V_49 >> V_4 -> V_13 ;
F_2 (stit, &stt->iommu_tables, next) {
if ( V_10 == V_11 )
V_45 = F_23 ( V_48 -> V_2 ,
V_51 -> V_19 , V_35 ) ;
else
V_45 = F_24 ( V_48 -> V_2 ,
V_51 -> V_19 , V_35 , V_23 , V_10 ) ;
if ( V_45 == V_12 )
continue;
if ( V_45 == V_42 )
return V_45 ;
F_20 ( 1 ) ;
F_15 ( V_51 -> V_19 , V_35 ) ;
}
F_9 ( V_4 , V_35 , V_5 ) ;
return V_12 ;
}
static long F_30 ( struct V_47 * V_48 ,
unsigned long V_23 , unsigned long * V_52 )
{
T_2 * V_53 , V_54 ;
unsigned V_55 = 0 ;
V_53 = F_31 ( V_48 -> V_31 . V_56 , V_23 , NULL , & V_55 ) ;
if ( ! V_53 || ! F_32 ( * V_53 ) )
return - V_57 ;
V_54 = * V_53 ;
if ( ! V_55 )
V_55 = V_26 ;
if ( V_55 > V_26 )
return - V_58 ;
if ( ! F_33 ( V_54 ) )
return - V_58 ;
* V_52 = ( F_34 ( V_54 ) << V_26 ) | ( V_23 & ( ( 1ULL << V_55 ) - 1 ) ) |
( V_23 & ~ V_30 ) ;
return 0 ;
}
long F_35 ( struct V_47 * V_48 ,
unsigned long V_3 , unsigned long V_49 ,
unsigned long V_59 , unsigned long V_60 )
{
struct V_1 * V_4 ;
long V_61 , V_45 = V_12 ;
unsigned long V_62 , V_35 , V_23 = 0 ;
unsigned long * V_32 = NULL ;
bool V_63 = false ;
struct V_50 * V_51 ;
if ( F_28 ( V_48 -> V_2 ) )
return V_42 ;
V_4 = F_1 ( V_48 -> V_2 , V_3 ) ;
if ( ! V_4 )
return V_42 ;
V_35 = V_49 >> V_4 -> V_13 ;
if ( V_60 > 512 )
return V_14 ;
if ( V_59 & ( V_64 - 1 ) )
return V_14 ;
V_45 = F_29 ( V_4 , V_49 , V_60 ) ;
if ( V_45 != V_12 )
return V_45 ;
if ( F_36 ( V_48 -> V_2 -> V_44 ) ) {
struct V_37 * V_38 ;
if ( F_10 ( V_48 -> V_2 , V_59 , & V_23 , NULL ) )
return V_42 ;
V_38 = F_21 ( V_48 -> V_2 -> V_44 , V_23 , V_65 ) ;
if ( V_38 )
V_63 = F_25 ( V_38 , V_23 , & V_62 ) == 0 ;
}
if ( ! V_63 ) {
if ( F_10 ( V_48 -> V_2 , V_59 , & V_23 , & V_32 ) )
return V_42 ;
V_32 = ( void * ) F_19 ( V_32 ) ;
if ( F_20 ( ! V_32 ) )
return V_43 ;
F_37 ( V_32 ) ;
if ( F_30 ( V_48 , V_23 , & V_62 ) ) {
V_45 = V_42 ;
goto V_66;
}
}
for ( V_61 = 0 ; V_61 < V_60 ; ++ V_61 ) {
unsigned long V_5 = F_38 ( ( ( T_1 * ) V_62 ) [ V_61 ] ) ;
V_45 = F_3 ( V_4 , V_5 ) ;
if ( V_45 != V_12 )
goto V_66;
V_23 = 0 ;
if ( F_10 ( V_48 -> V_2 ,
V_5 & ~ ( V_7 | V_8 ) ,
& V_23 , NULL ) )
return V_14 ;
F_2 (stit, &stt->iommu_tables, next) {
V_45 = F_24 ( V_48 -> V_2 ,
V_51 -> V_19 , V_35 + V_61 , V_23 ,
F_4 ( V_5 ) ) ;
if ( V_45 == V_12 )
continue;
if ( V_45 == V_42 )
goto V_66;
F_20 ( 1 ) ;
F_15 ( V_51 -> V_19 , V_35 ) ;
}
F_9 ( V_4 , V_35 + V_61 , V_5 ) ;
}
V_66:
if ( V_32 )
F_39 ( V_32 ) ;
return V_45 ;
}
long F_40 ( struct V_47 * V_48 ,
unsigned long V_3 , unsigned long V_49 ,
unsigned long V_67 , unsigned long V_60 )
{
struct V_1 * V_4 ;
long V_61 , V_45 ;
struct V_50 * V_51 ;
if ( F_28 ( V_48 -> V_2 ) )
return V_42 ;
V_4 = F_1 ( V_48 -> V_2 , V_3 ) ;
if ( ! V_4 )
return V_42 ;
V_45 = F_29 ( V_4 , V_49 , V_60 ) ;
if ( V_45 != V_12 )
return V_45 ;
if ( V_67 & ( V_8 | V_7 ) )
return V_14 ;
F_2 (stit, &stt->iommu_tables, next) {
unsigned long V_35 = V_49 >> V_51 -> V_19 -> V_40 ;
for ( V_61 = 0 ; V_61 < V_60 ; ++ V_61 ) {
V_45 = F_23 ( V_48 -> V_2 ,
V_51 -> V_19 , V_35 + V_61 ) ;
if ( V_45 == V_12 )
continue;
if ( V_45 == V_42 )
return V_45 ;
F_20 ( 1 ) ;
F_15 ( V_51 -> V_19 , V_35 ) ;
}
}
for ( V_61 = 0 ; V_61 < V_60 ; ++ V_61 , V_49 += ( 1ULL << V_4 -> V_13 ) )
F_9 ( V_4 , V_49 >> V_4 -> V_13 , V_67 ) ;
return V_12 ;
}
long F_41 ( struct V_47 * V_48 , unsigned long V_3 ,
unsigned long V_49 )
{
struct V_1 * V_4 ;
long V_45 ;
unsigned long V_18 ;
struct V_15 * V_15 ;
T_1 * V_19 ;
V_4 = F_1 ( V_48 -> V_2 , V_3 ) ;
if ( ! V_4 )
return V_42 ;
V_45 = F_29 ( V_4 , V_49 , 1 ) ;
if ( V_45 != V_12 )
return V_45 ;
V_18 = ( V_49 >> V_4 -> V_13 ) - V_4 -> V_20 ;
V_15 = V_4 -> V_21 [ V_18 / V_22 ] ;
V_19 = ( T_1 * ) F_8 ( V_15 ) ;
V_48 -> V_31 . V_68 [ 4 ] = V_19 [ V_18 % V_22 ] ;
return V_12 ;
}
