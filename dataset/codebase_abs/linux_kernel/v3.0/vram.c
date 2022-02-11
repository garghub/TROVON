static inline int F_1 ( unsigned long V_1 )
{
if ( V_1 >= V_2 &&
V_1 < V_2 + V_3 )
return V_4 ;
else
return V_5 ;
}
static struct V_6 * F_2 ( unsigned long V_1 ,
unsigned V_7 )
{
struct V_6 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 ) {
F_4 ( & V_8 -> V_10 ) ;
V_8 -> V_1 = V_1 ;
V_8 -> V_7 = V_7 ;
}
return V_8 ;
}
static struct V_11 * F_5 ( struct V_6 * V_12 ,
unsigned long V_1 , unsigned V_7 )
{
struct V_11 * V_13 ;
struct V_11 * V_14 ;
V_14 = F_3 ( sizeof( * V_13 ) , V_9 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_1 = V_1 ;
V_14 -> V_7 = V_7 ;
F_6 (va, &vr->alloc_list, list) {
if ( V_13 -> V_1 > V_14 -> V_1 )
break;
}
F_7 ( & V_14 -> V_15 , & V_13 -> V_15 ) ;
return V_14 ;
}
static void F_8 ( struct V_11 * V_13 )
{
F_9 ( & V_13 -> V_15 ) ;
F_10 ( V_13 ) ;
}
int F_11 ( unsigned long V_1 , T_1 V_16 )
{
struct V_6 * V_8 ;
unsigned V_7 ;
if ( V_17 ) {
F_12 ( L_1 ,
V_1 , V_16 ) ;
V_16 &= V_18 ;
V_7 = V_16 >> V_19 ;
V_8 = F_2 ( V_1 , V_7 ) ;
if ( V_8 == NULL )
return - V_20 ;
F_13 ( & V_8 -> V_15 , & V_21 ) ;
} else {
if ( V_22 == V_23 )
return - V_20 ;
V_24 [ V_22 ] . V_1 = V_1 ;
V_24 [ V_22 ] . V_16 = V_16 ;
++ V_22 ;
}
return 0 ;
}
int F_14 ( unsigned long V_1 , T_1 V_16 )
{
struct V_6 * V_8 ;
struct V_11 * V_25 ;
unsigned V_26 , V_27 ;
F_12 ( L_2 , V_1 , V_16 ) ;
V_16 = F_15 ( V_16 ) ;
F_16 ( & V_28 ) ;
F_6 (rm, &region_list, list) {
F_6 (alloc, &rm->alloc_list, list) {
V_26 = V_25 -> V_1 ;
V_27 = V_25 -> V_1 + ( V_25 -> V_7 >> V_19 ) ;
if ( V_26 >= V_1 && V_27 < V_1 + V_16 )
goto V_29;
}
}
F_17 ( & V_28 ) ;
return - V_30 ;
V_29:
F_8 ( V_25 ) ;
F_17 ( & V_28 ) ;
return 0 ;
}
static int F_18 ( unsigned long V_1 , unsigned V_7 )
{
struct V_6 * V_8 ;
struct V_11 * V_25 ;
T_1 V_16 ;
V_16 = V_7 << V_19 ;
F_6 (rm, &region_list, list) {
unsigned long V_26 , V_27 ;
F_12 ( L_3 , V_8 -> V_1 , V_8 -> V_7 ) ;
if ( F_1 ( V_8 -> V_1 ) != F_1 ( V_1 ) )
continue;
V_26 = V_8 -> V_1 ;
V_27 = V_26 + ( V_8 -> V_7 << V_19 ) - 1 ;
if ( V_26 > V_1 || V_27 < V_1 + V_16 - 1 )
continue;
F_12 ( L_4 ) ;
F_6 (alloc, &rm->alloc_list, list) {
V_27 = V_25 -> V_1 - 1 ;
if ( V_26 <= V_1 && V_27 >= V_1 + V_16 - 1 )
goto V_29;
V_26 = V_25 -> V_1 + ( V_25 -> V_7 << V_19 ) ;
}
V_27 = V_8 -> V_1 + ( V_8 -> V_7 << V_19 ) - 1 ;
if ( ! ( V_26 <= V_1 && V_27 >= V_1 + V_16 - 1 ) )
continue;
V_29:
F_12 ( L_5 , V_26 , V_27 ) ;
if ( F_5 ( V_8 , V_1 , V_7 ) == NULL )
return - V_20 ;
return 0 ;
}
return - V_20 ;
}
int F_19 ( unsigned long V_1 , T_1 V_16 )
{
unsigned V_7 ;
int V_31 ;
F_12 ( L_6 , V_1 , V_16 ) ;
V_16 = F_15 ( V_16 ) ;
V_7 = V_16 >> V_19 ;
F_16 ( & V_28 ) ;
V_31 = F_18 ( V_1 , V_7 ) ;
F_17 ( & V_28 ) ;
return V_31 ;
}
static void F_20 ( int V_32 , T_2 V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
F_21 ( V_36 ) ;
}
static int F_22 ( T_3 V_1 , unsigned V_7 )
{
struct V_35 V_36 ;
unsigned V_37 ;
unsigned V_38 ;
int V_31 ;
int V_32 ;
F_23 ( & V_36 ) ;
V_31 = F_24 ( V_39 , L_7 ,
F_20 ,
& V_36 , & V_32 ) ;
if ( V_31 ) {
F_25 ( L_8 ) ;
return - V_40 ;
}
V_37 = V_7 * V_41 / 4 ;
V_38 = 1 ;
F_26 ( V_32 , V_42 ,
V_37 , V_38 ,
V_43 ,
0 , 0 ) ;
F_27 ( V_32 , 0 , V_44 ,
V_1 , 0 , 0 ) ;
F_28 ( V_32 , V_45 , 0x000000 ) ;
F_29 ( V_32 ) ;
if ( F_30 ( & V_36 , F_31 ( 1000 ) ) == 0 ) {
F_32 ( V_32 ) ;
F_25 ( L_9 ) ;
V_31 = - V_46 ;
goto V_47;
}
V_31 = 0 ;
V_47:
F_33 ( V_32 ) ;
return V_31 ;
}
static int F_34 ( int V_48 , unsigned V_7 , unsigned long * V_1 )
{
struct V_6 * V_8 ;
struct V_11 * V_25 ;
F_6 (rm, &region_list, list) {
unsigned long V_26 , V_27 ;
F_12 ( L_3 , V_8 -> V_1 , V_8 -> V_7 ) ;
if ( F_1 ( V_8 -> V_1 ) != V_48 )
continue;
V_26 = V_8 -> V_1 ;
F_6 (alloc, &rm->alloc_list, list) {
V_27 = V_25 -> V_1 ;
if ( V_27 - V_26 >= V_7 << V_19 )
goto V_29;
V_26 = V_25 -> V_1 + ( V_25 -> V_7 << V_19 ) ;
}
V_27 = V_8 -> V_1 + ( V_8 -> V_7 << V_19 ) ;
V_29:
if ( V_27 - V_26 < V_7 << V_19 )
continue;
F_12 ( L_10 , V_26 , V_27 ) ;
V_25 = F_5 ( V_8 , V_26 , V_7 ) ;
if ( V_25 == NULL )
return - V_20 ;
* V_1 = V_26 ;
F_22 ( V_26 , V_7 ) ;
return 0 ;
}
return - V_20 ;
}
int F_35 ( int V_48 , T_1 V_16 , unsigned long * V_1 )
{
unsigned V_7 ;
int V_31 ;
F_36 ( V_48 > V_49 || ! V_16 ) ;
F_12 ( L_11 , V_48 , V_16 ) ;
V_16 = F_15 ( V_16 ) ;
V_7 = V_16 >> V_19 ;
F_16 ( & V_28 ) ;
V_31 = F_34 ( V_48 , V_7 , V_1 ) ;
F_17 ( & V_28 ) ;
return V_31 ;
}
void F_37 ( unsigned long * V_50 ,
unsigned long * V_51 ,
unsigned long * V_52 )
{
struct V_6 * V_12 ;
struct V_11 * V_13 ;
* V_50 = 0 ;
* V_51 = 0 ;
* V_52 = 0 ;
F_16 ( & V_28 ) ;
F_6 (vr, &region_list, list) {
unsigned free ;
unsigned long V_53 ;
V_53 = V_12 -> V_1 ;
* V_50 += V_12 -> V_7 << V_19 ;
F_6 (va, &vr->alloc_list, list) {
free = V_13 -> V_1 - V_53 ;
* V_51 += free ;
if ( free > * V_52 )
* V_52 = free ;
V_53 = V_13 -> V_1 + ( V_13 -> V_7 << V_19 ) ;
}
free = V_12 -> V_1 + ( V_12 -> V_7 << V_19 ) - V_53 ;
* V_51 += free ;
if ( free > * V_52 )
* V_52 = free ;
}
F_17 ( & V_28 ) ;
}
static int F_38 ( struct V_54 * V_55 , void * V_56 )
{
struct V_6 * V_12 ;
struct V_11 * V_13 ;
unsigned V_16 ;
F_16 ( & V_28 ) ;
F_6 (vr, &region_list, list) {
V_16 = V_12 -> V_7 << V_19 ;
F_39 ( V_55 , L_12 ,
V_12 -> V_1 , V_12 -> V_1 + V_16 - 1 ,
V_16 ) ;
F_6 (va, &vr->alloc_list, list) {
V_16 = V_13 -> V_7 << V_19 ;
F_39 ( V_55 , L_13 ,
V_13 -> V_1 , V_13 -> V_1 + V_16 - 1 ,
V_16 ) ;
}
}
F_17 ( & V_28 ) ;
return 0 ;
}
static int F_40 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_41 ( V_58 , F_38 , V_57 -> V_59 ) ;
}
static int T_4 F_42 ( void )
{
struct V_60 * V_61 ;
V_61 = F_43 ( L_14 , V_62 , NULL ,
NULL , & V_63 ) ;
if ( F_44 ( V_61 ) )
return F_45 ( V_61 ) ;
return 0 ;
}
static T_4 int F_46 ( void )
{
int V_64 ;
V_17 = 1 ;
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ )
F_11 ( V_24 [ V_64 ] . V_1 ,
V_24 [ V_64 ] . V_16 ) ;
#ifdef F_47
if ( F_42 () )
F_25 ( L_15 ) ;
#endif
return 0 ;
}
static int T_4 F_48 ( char * V_65 )
{
V_66 = F_49 ( V_65 , & V_65 ) ;
if ( * V_65 == ',' )
V_67 = F_50 ( V_65 + 1 , & V_65 , 16 ) ;
return 0 ;
}
void T_4 F_51 ( void )
{
T_3 V_1 ;
T_3 V_16 = 0 ;
if ( V_66 ) {
V_16 = V_66 ;
V_1 = V_67 ;
}
if ( ! V_16 ) {
V_16 = V_68 ;
V_1 = V_69 ;
}
#ifdef F_52
if ( ! V_16 ) {
V_16 = F_52 * 1024 * 1024 ;
V_1 = 0 ;
}
#endif
if ( ! V_16 )
return;
V_16 = F_53 ( V_16 , V_70 ) ;
if ( V_1 ) {
if ( V_1 & ~ V_18 ) {
F_25 ( L_16 ,
V_1 ) ;
return;
}
if ( ! F_54 ( V_1 , V_16 ) ) {
F_25 ( L_17 ,
V_1 , V_1 + V_16 - 1 ) ;
return;
}
if ( F_55 ( V_1 , V_16 ) ) {
F_25 ( L_18 ) ;
return;
}
if ( F_56 ( V_1 , V_16 ) < 0 ) {
F_25 ( L_19 ) ;
return;
}
} else {
V_1 = F_57 ( V_16 , V_70 ) ;
}
F_58 ( V_1 , V_16 ) ;
F_59 ( V_1 , V_16 ) ;
F_11 ( V_1 , V_16 ) ;
F_60 ( L_20 , V_16 ) ;
}
unsigned long T_4 F_61 ( unsigned long V_71 ,
unsigned long V_72 ,
unsigned long V_73 ,
unsigned long V_74 ,
unsigned long V_75 )
{
unsigned long V_76 ;
unsigned long V_77 ;
T_3 V_1 ;
T_3 V_16 ;
V_1 = V_78 ;
V_16 = V_79 ;
if ( ! V_16 )
return 0 ;
V_77 = 0 ;
V_76 = V_74 + V_75 ;
if ( ! V_1 ) {
if ( ( V_75 & V_18 ) < V_16 ) {
F_25 ( L_21 ) ;
return 0 ;
}
V_75 = ( V_75 - V_16 ) & V_18 ;
V_1 = V_74 + V_75 ;
}
if ( V_1 < V_71 ||
V_1 + V_16 > V_71 + V_73 ) {
F_25 ( L_22 ) ;
return 0 ;
}
if ( V_76 - V_1 > V_77 )
V_77 = V_76 - V_1 ;
V_75 = V_76 - V_77 - V_74 ;
F_11 ( V_1 , V_16 ) ;
if ( V_77 )
F_60 ( L_23 , V_77 ) ;
return V_77 ;
}
void T_4 F_62 ( T_3 V_16 , T_3 V_26 )
{
V_69 = V_26 ;
V_68 = V_16 ;
}
void T_4 F_63 ( T_3 V_16 , T_3 V_26 )
{
V_78 = V_26 ;
V_79 = V_16 ;
}
