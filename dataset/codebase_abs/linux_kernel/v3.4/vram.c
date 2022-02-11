static struct V_1 * F_1 ( unsigned long V_2 ,
unsigned V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 ) {
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
}
return V_4 ;
}
static struct V_7 * F_4 ( struct V_1 * V_8 ,
unsigned long V_2 , unsigned V_3 )
{
struct V_7 * V_9 ;
struct V_7 * V_10 ;
V_10 = F_2 ( sizeof( * V_9 ) , V_5 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_3 = V_3 ;
F_5 (va, &vr->alloc_list, list) {
if ( V_9 -> V_2 > V_10 -> V_2 )
break;
}
F_6 ( & V_10 -> V_11 , & V_9 -> V_11 ) ;
return V_10 ;
}
static void F_7 ( struct V_7 * V_9 )
{
F_8 ( & V_9 -> V_11 ) ;
F_9 ( V_9 ) ;
}
int F_10 ( unsigned long V_2 , T_1 V_12 )
{
struct V_1 * V_4 ;
unsigned V_3 ;
if ( V_13 ) {
F_11 ( L_1 ,
V_2 , V_12 ) ;
V_12 &= V_14 ;
V_3 = V_12 >> V_15 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == NULL )
return - V_16 ;
F_12 ( & V_4 -> V_11 , & V_17 ) ;
} else {
if ( V_18 == V_19 )
return - V_16 ;
V_20 [ V_18 ] . V_2 = V_2 ;
V_20 [ V_18 ] . V_12 = V_12 ;
++ V_18 ;
}
return 0 ;
}
int F_13 ( unsigned long V_2 , T_1 V_12 )
{
struct V_1 * V_4 ;
struct V_7 * V_21 ;
unsigned V_22 , V_23 ;
F_11 ( L_2 , V_2 , V_12 ) ;
V_12 = F_14 ( V_12 ) ;
F_15 ( & V_24 ) ;
F_5 (rm, &region_list, list) {
F_5 (alloc, &rm->alloc_list, list) {
V_22 = V_21 -> V_2 ;
V_23 = V_21 -> V_2 + ( V_21 -> V_3 >> V_15 ) ;
if ( V_22 >= V_2 && V_23 < V_2 + V_12 )
goto V_25;
}
}
F_16 ( & V_24 ) ;
return - V_26 ;
V_25:
F_7 ( V_21 ) ;
F_16 ( & V_24 ) ;
return 0 ;
}
static int F_17 ( unsigned long V_2 , unsigned V_3 )
{
struct V_1 * V_4 ;
struct V_7 * V_21 ;
T_1 V_12 ;
V_12 = V_3 << V_15 ;
F_5 (rm, &region_list, list) {
unsigned long V_22 , V_23 ;
F_11 ( L_3 , V_4 -> V_2 , V_4 -> V_3 ) ;
V_22 = V_4 -> V_2 ;
V_23 = V_22 + ( V_4 -> V_3 << V_15 ) - 1 ;
if ( V_22 > V_2 || V_23 < V_2 + V_12 - 1 )
continue;
F_11 ( L_4 ) ;
F_5 (alloc, &rm->alloc_list, list) {
V_23 = V_21 -> V_2 - 1 ;
if ( V_22 <= V_2 && V_23 >= V_2 + V_12 - 1 )
goto V_25;
V_22 = V_21 -> V_2 + ( V_21 -> V_3 << V_15 ) ;
}
V_23 = V_4 -> V_2 + ( V_4 -> V_3 << V_15 ) - 1 ;
if ( ! ( V_22 <= V_2 && V_23 >= V_2 + V_12 - 1 ) )
continue;
V_25:
F_11 ( L_5 , V_22 , V_23 ) ;
if ( F_4 ( V_4 , V_2 , V_3 ) == NULL )
return - V_16 ;
return 0 ;
}
return - V_16 ;
}
int F_18 ( unsigned long V_2 , T_1 V_12 )
{
unsigned V_3 ;
int V_27 ;
F_11 ( L_6 , V_2 , V_12 ) ;
V_12 = F_14 ( V_12 ) ;
V_3 = V_12 >> V_15 ;
F_15 ( & V_24 ) ;
V_27 = F_17 ( V_2 , V_3 ) ;
F_16 ( & V_24 ) ;
return V_27 ;
}
static void F_19 ( int V_28 , T_2 V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
F_20 ( V_32 ) ;
}
static int F_21 ( T_3 V_2 , unsigned V_3 )
{
struct V_31 V_32 ;
unsigned V_33 ;
unsigned V_34 ;
int V_27 ;
int V_28 ;
F_22 ( & V_32 ) ;
V_27 = F_23 ( V_35 , L_7 ,
F_19 ,
& V_32 , & V_28 ) ;
if ( V_27 ) {
F_24 ( L_8 ) ;
return - V_36 ;
}
V_33 = V_3 * V_37 / 4 ;
V_34 = 1 ;
F_25 ( V_28 , V_38 ,
V_33 , V_34 ,
V_39 ,
0 , 0 ) ;
F_26 ( V_28 , 0 , V_40 ,
V_2 , 0 , 0 ) ;
F_27 ( V_28 , V_41 , 0x000000 ) ;
F_28 ( V_28 ) ;
if ( F_29 ( & V_32 , F_30 ( 1000 ) ) == 0 ) {
F_31 ( V_28 ) ;
F_24 ( L_9 ) ;
V_27 = - V_42 ;
goto V_43;
}
V_27 = 0 ;
V_43:
F_32 ( V_28 ) ;
return V_27 ;
}
static int F_33 ( unsigned V_3 , unsigned long * V_2 )
{
struct V_1 * V_4 ;
struct V_7 * V_21 ;
F_5 (rm, &region_list, list) {
unsigned long V_22 , V_23 ;
F_11 ( L_3 , V_4 -> V_2 , V_4 -> V_3 ) ;
V_22 = V_4 -> V_2 ;
F_5 (alloc, &rm->alloc_list, list) {
V_23 = V_21 -> V_2 ;
if ( V_23 - V_22 >= V_3 << V_15 )
goto V_25;
V_22 = V_21 -> V_2 + ( V_21 -> V_3 << V_15 ) ;
}
V_23 = V_4 -> V_2 + ( V_4 -> V_3 << V_15 ) ;
V_25:
if ( V_23 - V_22 < V_3 << V_15 )
continue;
F_11 ( L_10 , V_22 , V_23 ) ;
V_21 = F_4 ( V_4 , V_22 , V_3 ) ;
if ( V_21 == NULL )
return - V_16 ;
* V_2 = V_22 ;
F_21 ( V_22 , V_3 ) ;
return 0 ;
}
return - V_16 ;
}
int F_34 ( T_1 V_12 , unsigned long * V_2 )
{
unsigned V_3 ;
int V_27 ;
F_35 ( ! V_12 ) ;
F_11 ( L_11 , V_12 ) ;
V_12 = F_14 ( V_12 ) ;
V_3 = V_12 >> V_15 ;
F_15 ( & V_24 ) ;
V_27 = F_33 ( V_3 , V_2 ) ;
F_16 ( & V_24 ) ;
return V_27 ;
}
void F_36 ( unsigned long * V_44 ,
unsigned long * V_45 ,
unsigned long * V_46 )
{
struct V_1 * V_8 ;
struct V_7 * V_9 ;
* V_44 = 0 ;
* V_45 = 0 ;
* V_46 = 0 ;
F_15 ( & V_24 ) ;
F_5 (vr, &region_list, list) {
unsigned free ;
unsigned long V_47 ;
V_47 = V_8 -> V_2 ;
* V_44 += V_8 -> V_3 << V_15 ;
F_5 (va, &vr->alloc_list, list) {
free = V_9 -> V_2 - V_47 ;
* V_45 += free ;
if ( free > * V_46 )
* V_46 = free ;
V_47 = V_9 -> V_2 + ( V_9 -> V_3 << V_15 ) ;
}
free = V_8 -> V_2 + ( V_8 -> V_3 << V_15 ) - V_47 ;
* V_45 += free ;
if ( free > * V_46 )
* V_46 = free ;
}
F_16 ( & V_24 ) ;
}
static int F_37 ( struct V_48 * V_49 , void * V_50 )
{
struct V_1 * V_8 ;
struct V_7 * V_9 ;
unsigned V_12 ;
F_15 ( & V_24 ) ;
F_5 (vr, &region_list, list) {
V_12 = V_8 -> V_3 << V_15 ;
F_38 ( V_49 , L_12 ,
V_8 -> V_2 , V_8 -> V_2 + V_12 - 1 ,
V_12 ) ;
F_5 (va, &vr->alloc_list, list) {
V_12 = V_9 -> V_3 << V_15 ;
F_38 ( V_49 , L_13 ,
V_9 -> V_2 , V_9 -> V_2 + V_12 - 1 ,
V_12 ) ;
}
}
F_16 ( & V_24 ) ;
return 0 ;
}
static int F_39 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_40 ( V_52 , F_37 , V_51 -> V_53 ) ;
}
static int T_4 F_41 ( void )
{
struct V_54 * V_55 ;
V_55 = F_42 ( L_14 , V_56 , NULL ,
NULL , & V_57 ) ;
if ( F_43 ( V_55 ) )
return F_44 ( V_55 ) ;
return 0 ;
}
static T_4 int F_45 ( void )
{
int V_58 ;
V_13 = 1 ;
for ( V_58 = 0 ; V_58 < V_18 ; V_58 ++ )
F_10 ( V_20 [ V_58 ] . V_2 ,
V_20 [ V_58 ] . V_12 ) ;
#ifdef F_46
if ( F_41 () )
F_24 ( L_15 ) ;
#endif
return 0 ;
}
static int T_4 F_47 ( char * V_59 )
{
V_60 = F_48 ( V_59 , & V_59 ) ;
if ( * V_59 == ',' )
V_61 = F_49 ( V_59 + 1 , & V_59 , 16 ) ;
return 0 ;
}
void T_4 F_50 ( void )
{
T_3 V_2 ;
T_3 V_12 = 0 ;
if ( V_60 ) {
V_12 = V_60 ;
V_2 = V_61 ;
}
if ( ! V_12 ) {
V_12 = V_62 ;
V_2 = V_63 ;
}
#ifdef F_51
if ( ! V_12 ) {
V_12 = F_51 * 1024 * 1024 ;
V_2 = 0 ;
}
#endif
if ( ! V_12 )
return;
V_12 = F_52 ( V_12 , V_64 ) ;
if ( V_2 ) {
if ( V_2 & ~ V_14 ) {
F_24 ( L_16 ,
V_2 ) ;
return;
}
if ( ! F_53 ( V_2 , V_12 ) ) {
F_24 ( L_17 ,
V_2 , V_2 + V_12 - 1 ) ;
return;
}
if ( F_54 ( V_2 , V_12 ) ) {
F_24 ( L_18 ) ;
return;
}
if ( F_55 ( V_2 , V_12 ) < 0 ) {
F_24 ( L_19 ) ;
return;
}
} else {
V_2 = F_56 ( V_12 , V_64 ) ;
}
F_57 ( V_2 , V_12 ) ;
F_58 ( V_2 , V_12 ) ;
F_10 ( V_2 , V_12 ) ;
F_59 ( L_20 , V_12 ) ;
}
void T_4 F_60 ( T_3 V_12 , T_3 V_22 )
{
V_63 = V_22 ;
V_62 = V_12 ;
}
