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
long F_10 ( unsigned long V_18 , unsigned long V_19 ,
struct V_20 * * V_21 )
{
struct V_20 * V_22 ;
long V_23 , V_24 , V_5 = 0 , V_25 = 0 ;
struct V_26 * V_26 = NULL ;
if ( ! V_14 || ! V_14 -> V_2 )
return - V_27 ;
F_11 ( & V_28 ) ;
F_12 (mem, &current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_22 -> V_18 == V_18 ) && ( V_22 -> V_19 == V_19 ) ) {
++ V_22 -> V_29 ;
* V_21 = V_22 ;
goto V_30;
}
if ( ( V_22 -> V_18 < ( V_18 + ( V_19 << V_11 ) ) ) &&
( V_18 < ( V_22 -> V_18 +
( V_22 -> V_19 << V_11 ) ) ) ) {
V_5 = - V_31 ;
goto V_30;
}
}
V_5 = F_1 ( V_14 -> V_2 , V_19 , true ) ;
if ( V_5 )
goto V_30;
V_25 = V_19 ;
V_22 = F_13 ( sizeof( * V_22 ) , V_32 ) ;
if ( ! V_22 ) {
V_5 = - V_13 ;
goto V_30;
}
V_22 -> V_33 = F_14 ( V_19 * sizeof( V_22 -> V_33 [ 0 ] ) ) ;
if ( ! V_22 -> V_33 ) {
F_15 ( V_22 ) ;
V_5 = - V_13 ;
goto V_30;
}
for ( V_23 = 0 ; V_23 < V_19 ; ++ V_23 ) {
if ( 1 != F_16 ( V_18 + ( V_23 << V_11 ) ,
1 , 1 , & V_26 ) ) {
for ( V_24 = 0 ; V_24 < V_23 ; ++ V_24 )
F_17 ( F_18 (
V_22 -> V_33 [ V_24 ] >> V_11 ) ) ;
F_19 ( V_22 -> V_33 ) ;
F_15 ( V_22 ) ;
V_5 = - V_34 ;
goto V_30;
}
V_22 -> V_33 [ V_23 ] = F_20 ( V_26 ) << V_11 ;
}
F_21 ( & V_22 -> V_35 , 1 ) ;
V_22 -> V_29 = 1 ;
V_22 -> V_18 = V_18 ;
V_22 -> V_19 = V_19 ;
* V_21 = V_22 ;
F_22 ( & V_22 -> V_36 , & V_14 -> V_2 -> V_16 . V_17 ) ;
V_30:
if ( V_25 && V_5 )
F_1 ( V_14 -> V_2 , V_25 , false ) ;
F_23 ( & V_28 ) ;
return V_5 ;
}
static void F_24 ( struct V_20 * V_22 )
{
long V_23 ;
struct V_26 * V_26 = NULL ;
for ( V_23 = 0 ; V_23 < V_22 -> V_19 ; ++ V_23 ) {
if ( ! V_22 -> V_33 [ V_23 ] )
continue;
V_26 = F_18 ( V_22 -> V_33 [ V_23 ] >> V_11 ) ;
if ( ! V_26 )
continue;
F_17 ( V_26 ) ;
V_22 -> V_33 [ V_23 ] = 0 ;
}
}
static void F_25 ( struct V_20 * V_22 )
{
F_24 ( V_22 ) ;
F_19 ( V_22 -> V_33 ) ;
F_15 ( V_22 ) ;
}
static void F_26 ( struct V_37 * V_38 )
{
struct V_20 * V_22 = F_27 ( V_38 ,
struct V_20 , V_39 ) ;
F_25 ( V_22 ) ;
}
static void F_28 ( struct V_20 * V_22 )
{
F_29 ( & V_22 -> V_36 ) ;
F_1 ( V_14 -> V_2 , V_22 -> V_19 , false ) ;
F_30 ( & V_22 -> V_39 , F_26 ) ;
}
long F_31 ( struct V_20 * V_22 )
{
long V_5 = 0 ;
if ( ! V_14 || ! V_14 -> V_2 )
return - V_27 ;
F_11 ( & V_28 ) ;
if ( V_22 -> V_29 == 0 ) {
V_5 = - V_40 ;
goto V_30;
}
-- V_22 -> V_29 ;
if ( V_22 -> V_29 )
goto V_30;
if ( F_32 ( & V_22 -> V_35 , 1 , 0 ) != 1 ) {
++ V_22 -> V_29 ;
V_5 = - V_41 ;
goto V_30;
}
F_28 ( V_22 ) ;
V_30:
F_23 ( & V_28 ) ;
return V_5 ;
}
struct V_20 * F_33 ( unsigned long V_18 ,
unsigned long V_42 )
{
struct V_20 * V_22 , * V_5 = NULL ;
F_12 (mem,
&current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_22 -> V_18 <= V_18 ) &&
( V_18 + V_42 <= V_22 -> V_18 +
( V_22 -> V_19 << V_11 ) ) ) {
V_5 = V_22 ;
break;
}
}
return V_5 ;
}
struct V_20 * F_34 ( unsigned long V_18 ,
unsigned long V_19 )
{
struct V_20 * V_22 , * V_5 = NULL ;
F_12 (mem,
&current->mm->context.iommu_group_mem_list,
next) {
if ( ( V_22 -> V_18 == V_18 ) && ( V_22 -> V_19 == V_19 ) ) {
V_5 = V_22 ;
break;
}
}
return V_5 ;
}
long F_35 ( struct V_20 * V_22 ,
unsigned long V_18 , unsigned long * V_43 )
{
const long V_44 = ( V_18 - V_22 -> V_18 ) >> V_11 ;
T_1 * V_45 = & V_22 -> V_33 [ V_44 ] ;
if ( V_44 >= V_22 -> V_19 )
return - V_34 ;
* V_43 = * V_45 | ( V_18 & ~ V_46 ) ;
return 0 ;
}
long F_36 ( struct V_20 * V_22 )
{
if ( F_37 ( & V_22 -> V_35 ) )
return 0 ;
return - V_47 ;
}
void F_38 ( struct V_20 * V_22 )
{
F_39 ( & V_22 -> V_35 , - 1 , 1 ) ;
}
void F_40 ( T_2 * V_48 )
{
F_41 ( & V_48 -> V_17 ) ;
}
void F_42 ( T_2 * V_48 )
{
struct V_20 * V_22 , * V_49 ;
F_43 (mem, tmp, &ctx->iommu_group_mem_list, next) {
F_29 ( & V_22 -> V_36 ) ;
F_25 ( V_22 ) ;
}
}
