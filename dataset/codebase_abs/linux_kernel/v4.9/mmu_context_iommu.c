static long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool V_4 )
{
long V_5 = 0 , V_6 , V_7 ;
if ( ! V_3 )
return 0 ;
F_2 ( & V_2 -> V_8 ) ;
if ( V_4 ) {
V_6 = V_2 -> V_9 + V_3 ;
V_7 = F_3 ( V_10 ) >> V_11 ;
if ( V_6 > V_7 && ! F_4 ( V_12 ) )
V_5 = - V_13 ;
else
V_2 -> V_9 += V_3 ;
} else {
if ( F_5 ( V_3 > V_2 -> V_9 ) )
V_3 = V_2 -> V_9 ;
V_2 -> V_9 -= V_3 ;
}
F_6 ( L_1 ,
V_14 -> V_15 ,
V_4 ? '+' : '-' ,
V_3 << V_11 ,
V_2 -> V_9 << V_11 ,
F_3 ( V_10 ) ) ;
F_7 ( & V_2 -> V_8 ) ;
return V_5 ;
}
bool F_8 ( void )
{
if ( ! V_14 || ! V_14 -> V_2 )
return false ;
return ! F_9 ( & V_14 -> V_2 -> V_16 . V_17 ) ;
}
struct V_18 * F_10 ( struct V_18 * V_18 , unsigned long V_19 ,
int * * V_20 )
{
T_1 V_21 = V_22 ;
struct V_18 * V_23 ;
if ( F_11 ( V_18 ) || F_12 ( V_18 ) || F_13 ( V_18 ) )
return NULL ;
if ( F_14 ( V_18 ) )
V_21 |= V_24 ;
V_23 = F_15 ( V_21 | V_25 | V_26 ) ;
return V_23 ;
}
static int F_16 ( struct V_18 * V_18 )
{
int V_5 = 0 ;
F_17 ( V_27 ) ;
if ( F_11 ( V_18 ) || F_12 ( V_18 ) || F_13 ( V_18 ) )
return - V_28 ;
F_18 () ;
V_5 = F_19 ( V_18 ) ;
if ( V_5 )
return V_5 ;
F_20 ( & V_18 -> V_29 , & V_27 ) ;
F_21 ( V_18 ) ;
V_5 = F_22 ( & V_27 , F_10 ,
NULL , 0 , V_30 , V_31 ) ;
if ( V_5 ) {
if ( ! F_9 ( & V_27 ) )
F_23 ( & V_27 ) ;
}
return 0 ;
}
long F_24 ( unsigned long V_32 , unsigned long V_33 ,
struct V_34 * * V_35 )
{
struct V_34 * V_36 ;
long V_37 , V_38 , V_5 = 0 , V_39 = 0 ;
struct V_18 * V_18 = NULL ;
if ( ! V_14 || ! V_14 -> V_2 )
return - V_40 ;
F_25 ( & V_41 ) ;
F_26 (mem, &current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_36 -> V_32 == V_32 ) && ( V_36 -> V_33 == V_33 ) ) {
++ V_36 -> V_42 ;
* V_35 = V_36 ;
goto V_43;
}
if ( ( V_36 -> V_32 < ( V_32 + ( V_33 << V_11 ) ) ) &&
( V_32 < ( V_36 -> V_32 +
( V_36 -> V_33 << V_11 ) ) ) ) {
V_5 = - V_44 ;
goto V_43;
}
}
V_5 = F_1 ( V_14 -> V_2 , V_33 , true ) ;
if ( V_5 )
goto V_43;
V_39 = V_33 ;
V_36 = F_27 ( sizeof( * V_36 ) , V_45 ) ;
if ( ! V_36 ) {
V_5 = - V_13 ;
goto V_43;
}
V_36 -> V_46 = F_28 ( V_33 * sizeof( V_36 -> V_46 [ 0 ] ) ) ;
if ( ! V_36 -> V_46 ) {
F_29 ( V_36 ) ;
V_5 = - V_13 ;
goto V_43;
}
for ( V_37 = 0 ; V_37 < V_33 ; ++ V_37 ) {
if ( 1 != F_30 ( V_32 + ( V_37 << V_11 ) ,
1 , 1 , & V_18 ) ) {
V_5 = - V_47 ;
for ( V_38 = 0 ; V_38 < V_37 ; ++ V_38 )
F_21 ( F_31 ( V_36 -> V_46 [ V_38 ] >>
V_11 ) ) ;
F_32 ( V_36 -> V_46 ) ;
F_29 ( V_36 ) ;
goto V_43;
}
if ( F_33 ( V_18 ) == V_48 ) {
if ( F_16 ( V_18 ) )
goto V_49;
if ( 1 != F_30 ( V_32 + ( V_37 << V_11 ) ,
1 , 1 ,
& V_18 ) ) {
V_5 = - V_47 ;
for ( V_38 = 0 ; V_38 < V_37 ; ++ V_38 )
F_21 ( F_31 ( V_36 -> V_46 [ V_38 ] >>
V_11 ) ) ;
F_32 ( V_36 -> V_46 ) ;
F_29 ( V_36 ) ;
goto V_43;
}
}
V_49:
V_36 -> V_46 [ V_37 ] = F_34 ( V_18 ) << V_11 ;
}
F_35 ( & V_36 -> V_50 , 1 ) ;
V_36 -> V_42 = 1 ;
V_36 -> V_32 = V_32 ;
V_36 -> V_33 = V_33 ;
* V_35 = V_36 ;
F_36 ( & V_36 -> V_51 , & V_14 -> V_2 -> V_16 . V_17 ) ;
V_43:
if ( V_39 && V_5 )
F_1 ( V_14 -> V_2 , V_39 , false ) ;
F_37 ( & V_41 ) ;
return V_5 ;
}
static void F_38 ( struct V_34 * V_36 )
{
long V_37 ;
struct V_18 * V_18 = NULL ;
for ( V_37 = 0 ; V_37 < V_36 -> V_33 ; ++ V_37 ) {
if ( ! V_36 -> V_46 [ V_37 ] )
continue;
V_18 = F_31 ( V_36 -> V_46 [ V_37 ] >> V_11 ) ;
if ( ! V_18 )
continue;
F_21 ( V_18 ) ;
V_36 -> V_46 [ V_37 ] = 0 ;
}
}
static void F_39 ( struct V_34 * V_36 )
{
F_38 ( V_36 ) ;
F_32 ( V_36 -> V_46 ) ;
F_29 ( V_36 ) ;
}
static void F_40 ( struct V_52 * V_53 )
{
struct V_34 * V_36 = F_41 ( V_53 ,
struct V_34 , V_54 ) ;
F_39 ( V_36 ) ;
}
static void F_42 ( struct V_34 * V_36 )
{
F_43 ( & V_36 -> V_51 ) ;
F_1 ( V_14 -> V_2 , V_36 -> V_33 , false ) ;
F_44 ( & V_36 -> V_54 , F_40 ) ;
}
long F_45 ( struct V_34 * V_36 )
{
long V_5 = 0 ;
if ( ! V_14 || ! V_14 -> V_2 )
return - V_40 ;
F_25 ( & V_41 ) ;
if ( V_36 -> V_42 == 0 ) {
V_5 = - V_55 ;
goto V_43;
}
-- V_36 -> V_42 ;
if ( V_36 -> V_42 )
goto V_43;
if ( F_46 ( & V_36 -> V_50 , 1 , 0 ) != 1 ) {
++ V_36 -> V_42 ;
V_5 = - V_28 ;
goto V_43;
}
F_42 ( V_36 ) ;
V_43:
F_37 ( & V_41 ) ;
return V_5 ;
}
struct V_34 * F_47 ( unsigned long V_32 ,
unsigned long V_56 )
{
struct V_34 * V_36 , * V_5 = NULL ;
F_26 (mem,
&current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_36 -> V_32 <= V_32 ) &&
( V_32 + V_56 <= V_36 -> V_32 +
( V_36 -> V_33 << V_11 ) ) ) {
V_5 = V_36 ;
break;
}
}
return V_5 ;
}
struct V_34 * F_48 ( unsigned long V_32 ,
unsigned long V_33 )
{
struct V_34 * V_36 , * V_5 = NULL ;
F_26 (mem,
&current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_36 -> V_32 == V_32 ) && ( V_36 -> V_33 == V_33 ) ) {
V_5 = V_36 ;
break;
}
}
return V_5 ;
}
long F_49 ( struct V_34 * V_36 ,
unsigned long V_32 , unsigned long * V_57 )
{
const long V_58 = ( V_32 - V_36 -> V_32 ) >> V_11 ;
T_2 * V_59 = & V_36 -> V_46 [ V_58 ] ;
if ( V_58 >= V_36 -> V_33 )
return - V_47 ;
* V_57 = * V_59 | ( V_32 & ~ V_60 ) ;
return 0 ;
}
long F_50 ( struct V_34 * V_36 )
{
if ( F_51 ( & V_36 -> V_50 ) )
return 0 ;
return - V_61 ;
}
void F_52 ( struct V_34 * V_36 )
{
F_53 ( & V_36 -> V_50 , - 1 , 1 ) ;
}
void F_54 ( T_3 * V_62 )
{
F_55 ( & V_62 -> V_17 ) ;
}
void F_56 ( T_3 * V_62 )
{
struct V_34 * V_36 , * V_63 ;
F_57 (mem, tmp, &ctx->iommu_group_mem_list, next) {
F_43 ( & V_36 -> V_51 ) ;
F_39 ( V_36 ) ;
}
}
