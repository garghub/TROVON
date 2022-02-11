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
static int F_19 ( unsigned V_3 , unsigned long * V_2 )
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
F_11 ( L_7 , V_22 , V_23 ) ;
V_21 = F_4 ( V_4 , V_22 , V_3 ) ;
if ( V_21 == NULL )
return - V_16 ;
* V_2 = V_22 ;
return 0 ;
}
return - V_16 ;
}
int F_20 ( T_1 V_12 , unsigned long * V_2 )
{
unsigned V_3 ;
int V_27 ;
F_21 ( ! V_12 ) ;
F_11 ( L_8 , V_12 ) ;
V_12 = F_14 ( V_12 ) ;
V_3 = V_12 >> V_15 ;
F_15 ( & V_24 ) ;
V_27 = F_19 ( V_3 , V_2 ) ;
F_16 ( & V_24 ) ;
return V_27 ;
}
void F_22 ( unsigned long * V_28 ,
unsigned long * V_29 ,
unsigned long * V_30 )
{
struct V_1 * V_8 ;
struct V_7 * V_9 ;
* V_28 = 0 ;
* V_29 = 0 ;
* V_30 = 0 ;
F_15 ( & V_24 ) ;
F_5 (vr, &region_list, list) {
unsigned free ;
unsigned long V_31 ;
V_31 = V_8 -> V_2 ;
* V_28 += V_8 -> V_3 << V_15 ;
F_5 (va, &vr->alloc_list, list) {
free = V_9 -> V_2 - V_31 ;
* V_29 += free ;
if ( free > * V_30 )
* V_30 = free ;
V_31 = V_9 -> V_2 + ( V_9 -> V_3 << V_15 ) ;
}
free = V_8 -> V_2 + ( V_8 -> V_3 << V_15 ) - V_31 ;
* V_29 += free ;
if ( free > * V_30 )
* V_30 = free ;
}
F_16 ( & V_24 ) ;
}
static int F_23 ( struct V_32 * V_33 , void * V_34 )
{
struct V_1 * V_8 ;
struct V_7 * V_9 ;
unsigned V_12 ;
F_15 ( & V_24 ) ;
F_5 (vr, &region_list, list) {
V_12 = V_8 -> V_3 << V_15 ;
F_24 ( V_33 , L_9 ,
V_8 -> V_2 , V_8 -> V_2 + V_12 - 1 ,
V_12 ) ;
F_5 (va, &vr->alloc_list, list) {
V_12 = V_9 -> V_3 << V_15 ;
F_24 ( V_33 , L_10 ,
V_9 -> V_2 , V_9 -> V_2 + V_12 - 1 ,
V_12 ) ;
}
}
F_16 ( & V_24 ) ;
return 0 ;
}
static int F_25 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_26 ( V_36 , F_23 , V_35 -> V_37 ) ;
}
static int T_2 F_27 ( void )
{
struct V_38 * V_39 ;
V_39 = F_28 ( L_11 , V_40 , NULL ,
NULL , & V_41 ) ;
if ( F_29 ( V_39 ) )
return F_30 ( V_39 ) ;
return 0 ;
}
static T_2 int F_31 ( void )
{
int V_42 ;
V_13 = 1 ;
for ( V_42 = 0 ; V_42 < V_18 ; V_42 ++ )
F_10 ( V_20 [ V_42 ] . V_2 ,
V_20 [ V_42 ] . V_12 ) ;
#ifdef F_32
if ( F_27 () )
F_33 ( L_12 ) ;
#endif
return 0 ;
}
static int T_2 F_34 ( char * V_43 )
{
V_44 = F_35 ( V_43 , & V_43 ) ;
if ( * V_43 == ',' )
V_45 = F_36 ( V_43 + 1 , & V_43 , 16 ) ;
return 0 ;
}
void T_2 F_37 ( void )
{
T_3 V_2 ;
T_3 V_12 = 0 ;
if ( V_44 ) {
V_12 = V_44 ;
V_2 = V_45 ;
}
if ( ! V_12 ) {
V_12 = V_46 ;
V_2 = V_47 ;
}
#ifdef F_38
if ( ! V_12 ) {
V_12 = F_38 * 1024 * 1024 ;
V_2 = 0 ;
}
#endif
if ( ! V_12 )
return;
V_12 = F_39 ( V_12 , V_48 ) ;
if ( V_2 ) {
if ( V_2 & ~ V_14 ) {
F_33 ( L_13 ,
V_2 ) ;
return;
}
if ( ! F_40 ( V_2 , V_12 ) ) {
F_33 ( L_14 ,
V_2 , V_2 + V_12 - 1 ) ;
return;
}
if ( F_41 ( V_2 , V_12 ) ) {
F_33 ( L_15 ) ;
return;
}
if ( F_42 ( V_2 , V_12 ) < 0 ) {
F_33 ( L_16 ) ;
return;
}
} else {
V_2 = F_43 ( V_12 , V_48 ) ;
}
F_44 ( V_2 , V_12 ) ;
F_45 ( V_2 , V_12 ) ;
F_10 ( V_2 , V_12 ) ;
F_46 ( L_17 , V_12 ) ;
}
void T_2 F_47 ( T_3 V_12 , T_3 V_22 )
{
V_47 = V_22 ;
V_46 = V_12 ;
}
