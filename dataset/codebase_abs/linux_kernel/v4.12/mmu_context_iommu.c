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
V_14 ? V_14 -> V_15 : 0 ,
V_4 ? '+' : '-' ,
V_3 << V_11 ,
V_2 -> V_9 << V_11 ,
F_3 ( V_10 ) ) ;
F_7 ( & V_2 -> V_8 ) ;
return V_5 ;
}
bool F_8 ( struct V_1 * V_2 )
{
return ! F_9 ( & V_2 -> V_16 . V_17 ) ;
}
struct V_18 * F_10 ( struct V_18 * V_18 , unsigned long V_19 ,
int * * V_20 )
{
T_1 V_21 = V_22 ;
struct V_18 * V_23 ;
if ( F_11 ( V_18 ) )
return NULL ;
if ( F_12 ( V_18 ) )
V_21 |= V_24 ;
V_23 = F_13 ( V_21 | V_25 | V_26 ) ;
return V_23 ;
}
static int F_14 ( struct V_18 * V_18 )
{
int V_5 = 0 ;
F_15 ( V_27 ) ;
if ( F_11 ( V_18 ) )
return - V_28 ;
F_16 () ;
V_5 = F_17 ( V_18 ) ;
if ( V_5 )
return V_5 ;
F_18 ( & V_18 -> V_29 , & V_27 ) ;
F_19 ( V_18 ) ;
V_5 = F_20 ( & V_27 , F_10 ,
NULL , 0 , V_30 , V_31 ) ;
if ( V_5 ) {
if ( ! F_9 ( & V_27 ) )
F_21 ( & V_27 ) ;
}
return 0 ;
}
long F_22 ( struct V_1 * V_2 , unsigned long V_32 , unsigned long V_33 ,
struct V_34 * * V_35 )
{
struct V_34 * V_36 ;
long V_37 , V_38 , V_5 = 0 , V_39 = 0 ;
struct V_18 * V_18 = NULL ;
F_23 ( & V_40 ) ;
F_24 (mem, &mm->context.iommu_group_mem_list,
next) {
if ( ( V_36 -> V_32 == V_32 ) && ( V_36 -> V_33 == V_33 ) ) {
++ V_36 -> V_41 ;
* V_35 = V_36 ;
goto V_42;
}
if ( ( V_36 -> V_32 < ( V_32 + ( V_33 << V_11 ) ) ) &&
( V_32 < ( V_36 -> V_32 +
( V_36 -> V_33 << V_11 ) ) ) ) {
V_5 = - V_43 ;
goto V_42;
}
}
V_5 = F_1 ( V_2 , V_33 , true ) ;
if ( V_5 )
goto V_42;
V_39 = V_33 ;
V_36 = F_25 ( sizeof( * V_36 ) , V_44 ) ;
if ( ! V_36 ) {
V_5 = - V_13 ;
goto V_42;
}
V_36 -> V_45 = F_26 ( V_33 * sizeof( V_36 -> V_45 [ 0 ] ) ) ;
if ( ! V_36 -> V_45 ) {
F_27 ( V_36 ) ;
V_5 = - V_13 ;
goto V_42;
}
for ( V_37 = 0 ; V_37 < V_33 ; ++ V_37 ) {
if ( 1 != F_28 ( V_32 + ( V_37 << V_11 ) ,
1 , 1 , & V_18 ) ) {
V_5 = - V_46 ;
for ( V_38 = 0 ; V_38 < V_37 ; ++ V_38 )
F_19 ( F_29 ( V_36 -> V_45 [ V_38 ] >>
V_11 ) ) ;
F_30 ( V_36 -> V_45 ) ;
F_27 ( V_36 ) ;
goto V_42;
}
if ( F_31 ( V_18 ) ) {
if ( F_14 ( V_18 ) )
goto V_47;
if ( 1 != F_28 ( V_32 + ( V_37 << V_11 ) ,
1 , 1 ,
& V_18 ) ) {
V_5 = - V_46 ;
for ( V_38 = 0 ; V_38 < V_37 ; ++ V_38 )
F_19 ( F_29 ( V_36 -> V_45 [ V_38 ] >>
V_11 ) ) ;
F_30 ( V_36 -> V_45 ) ;
F_27 ( V_36 ) ;
goto V_42;
}
}
V_47:
V_36 -> V_45 [ V_37 ] = F_32 ( V_18 ) << V_11 ;
}
F_33 ( & V_36 -> V_48 , 1 ) ;
V_36 -> V_41 = 1 ;
V_36 -> V_32 = V_32 ;
V_36 -> V_33 = V_33 ;
* V_35 = V_36 ;
F_34 ( & V_36 -> V_49 , & V_2 -> V_16 . V_17 ) ;
V_42:
if ( V_39 && V_5 )
F_1 ( V_2 , V_39 , false ) ;
F_35 ( & V_40 ) ;
return V_5 ;
}
static void F_36 ( struct V_34 * V_36 )
{
long V_37 ;
struct V_18 * V_18 = NULL ;
for ( V_37 = 0 ; V_37 < V_36 -> V_33 ; ++ V_37 ) {
if ( ! V_36 -> V_45 [ V_37 ] )
continue;
V_18 = F_29 ( V_36 -> V_45 [ V_37 ] >> V_11 ) ;
if ( ! V_18 )
continue;
F_19 ( V_18 ) ;
V_36 -> V_45 [ V_37 ] = 0 ;
}
}
static void F_37 ( struct V_34 * V_36 )
{
F_36 ( V_36 ) ;
F_30 ( V_36 -> V_45 ) ;
F_27 ( V_36 ) ;
}
static void F_38 ( struct V_50 * V_51 )
{
struct V_34 * V_36 = F_39 ( V_51 ,
struct V_34 , V_52 ) ;
F_37 ( V_36 ) ;
}
static void F_40 ( struct V_34 * V_36 )
{
F_41 ( & V_36 -> V_49 ) ;
F_42 ( & V_36 -> V_52 , F_38 ) ;
}
long F_43 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
long V_5 = 0 ;
F_23 ( & V_40 ) ;
if ( V_36 -> V_41 == 0 ) {
V_5 = - V_53 ;
goto V_42;
}
-- V_36 -> V_41 ;
if ( V_36 -> V_41 )
goto V_42;
if ( F_44 ( & V_36 -> V_48 , 1 , 0 ) != 1 ) {
++ V_36 -> V_41 ;
V_5 = - V_28 ;
goto V_42;
}
F_40 ( V_36 ) ;
F_1 ( V_2 , V_36 -> V_33 , false ) ;
V_42:
F_35 ( & V_40 ) ;
return V_5 ;
}
struct V_34 * F_45 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_54 )
{
struct V_34 * V_36 , * V_5 = NULL ;
F_24 (mem, &mm->context.iommu_group_mem_list, next) {
if ( ( V_36 -> V_32 <= V_32 ) &&
( V_32 + V_54 <= V_36 -> V_32 +
( V_36 -> V_33 << V_11 ) ) ) {
V_5 = V_36 ;
break;
}
}
return V_5 ;
}
struct V_34 * F_46 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_54 )
{
struct V_34 * V_36 , * V_5 = NULL ;
F_47 (mem, &mm->context.iommu_group_mem_list,
next) {
if ( ( V_36 -> V_32 <= V_32 ) &&
( V_32 + V_54 <= V_36 -> V_32 +
( V_36 -> V_33 << V_11 ) ) ) {
V_5 = V_36 ;
break;
}
}
return V_5 ;
}
struct V_34 * F_48 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_34 * V_36 , * V_5 = NULL ;
F_24 (mem, &mm->context.iommu_group_mem_list, next) {
if ( ( V_36 -> V_32 == V_32 ) && ( V_36 -> V_33 == V_33 ) ) {
V_5 = V_36 ;
break;
}
}
return V_5 ;
}
long F_49 ( struct V_34 * V_36 ,
unsigned long V_32 , unsigned long * V_55 )
{
const long V_56 = ( V_32 - V_36 -> V_32 ) >> V_11 ;
T_2 * V_57 = & V_36 -> V_45 [ V_56 ] ;
if ( V_56 >= V_36 -> V_33 )
return - V_46 ;
* V_55 = * V_57 | ( V_32 & ~ V_58 ) ;
return 0 ;
}
long F_50 ( struct V_34 * V_36 ,
unsigned long V_32 , unsigned long * V_55 )
{
const long V_56 = ( V_32 - V_36 -> V_32 ) >> V_11 ;
void * V_57 = & V_36 -> V_45 [ V_56 ] ;
unsigned long * V_59 ;
if ( V_56 >= V_36 -> V_33 )
return - V_46 ;
V_59 = ( void * ) F_51 ( V_57 ) ;
if ( ! V_59 )
return - V_46 ;
* V_55 = * V_59 | ( V_32 & ~ V_58 ) ;
return 0 ;
}
long F_52 ( struct V_34 * V_36 )
{
if ( F_53 ( & V_36 -> V_48 ) )
return 0 ;
return - V_60 ;
}
void F_54 ( struct V_34 * V_36 )
{
F_55 ( & V_36 -> V_48 , - 1 , 1 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_16 . V_17 ) ;
}
