void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( & V_2 -> V_5 , & V_6 ) ;
F_4 ( & V_4 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_6 ( & V_2 -> V_5 ) ;
F_4 ( & V_4 , V_3 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
unsigned long V_3 ;
F_2 ( & V_9 , V_3 ) ;
F_3 ( & V_8 -> V_10 , & V_11 ) ;
F_4 ( & V_9 , V_3 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
unsigned long V_3 ;
F_2 ( & V_9 , V_3 ) ;
F_6 ( & V_8 -> V_10 ) ;
F_4 ( & V_9 , V_3 ) ;
}
static const char * F_9 ( int V_12 )
{
if ( V_12 == 0 )
return L_1 ;
if ( V_12 > 0 )
return L_2 ;
return L_3 ;
}
static void F_10 ( struct V_13 * V_14 , struct V_8 * V_15 , bool V_8 )
{
int V_12 = 1 ;
if ( F_11 ( V_15 ) )
V_12 = V_15 -> V_12 ;
F_12 ( V_14 , L_4 ,
V_8 && V_15 -> V_16 -> V_17 ?
V_15 -> V_16 -> V_17 ( V_15 ) : L_5 ,
V_8 ? L_6 : L_5 ,
F_9 ( V_12 ) ) ;
if ( V_12 <= 0 ) {
struct V_18 V_19 =
F_13 ( V_15 -> V_20 ) ;
F_12 ( V_14 , L_7 , ( V_21 ) V_19 . V_22 , V_19 . V_23 ) ;
}
if ( ( ! V_8 || V_15 -> V_16 -> V_24 ) &&
V_15 -> V_16 -> V_25 ) {
char V_26 [ 64 ] ;
bool V_27 ;
V_15 -> V_16 -> V_25 ( V_15 , V_26 , sizeof( V_26 ) ) ;
V_27 = strlen ( V_26 ) ;
if ( V_27 )
F_12 ( V_14 , L_8 , V_26 ) ;
if ( V_27 && V_8 ) {
V_15 -> V_16 -> V_24 ( V_15 , V_26 , sizeof( V_26 ) ) ;
if ( strlen ( V_26 ) )
F_12 ( V_14 , L_9 , V_26 ) ;
}
}
F_14 ( V_14 , L_10 ) ;
}
static void F_15 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_28 * V_29 ;
unsigned long V_3 ;
F_12 ( V_14 , L_11 , V_2 -> V_30 , V_2 -> V_16 -> V_31 ) ;
if ( V_2 -> V_16 -> V_24 ) {
char V_26 [ 64 ] ;
V_2 -> V_16 -> V_24 ( V_2 , V_26 , sizeof( V_26 ) ) ;
F_12 ( V_14 , L_8 , V_26 ) ;
}
F_14 ( V_14 , L_10 ) ;
F_2 ( & V_2 -> V_32 , V_3 ) ;
F_16 (pos, &obj->child_list_head) {
struct V_33 * V_15 =
F_17 ( V_29 , struct V_33 , V_34 ) ;
F_10 ( V_14 , & V_15 -> V_35 , false ) ;
}
F_4 ( & V_2 -> V_32 , V_3 ) ;
}
static void F_18 ( struct V_13 * V_14 , struct V_7 * V_8 )
{
T_1 * V_29 ;
unsigned long V_3 ;
int V_36 ;
F_12 ( V_14 , L_12 , V_8 , V_8 -> V_30 ,
F_9 ( F_19 ( & V_8 -> V_12 ) ) ) ;
for ( V_36 = 0 ; V_36 < V_8 -> V_37 ; ++ V_36 ) {
F_10 ( V_14 , V_8 -> V_38 [ V_36 ] . V_33 , true ) ;
}
F_2 ( & V_8 -> V_39 . V_40 , V_3 ) ;
F_20 (pos, &fence->wq.task_list, task_list) {
struct V_41 * V_42 ;
if ( V_29 -> V_43 != & V_44 )
continue;
V_42 = F_17 ( V_29 , struct V_41 , V_45 ) ;
F_12 ( V_14 , L_13 , V_42 -> V_46 ) ;
}
F_4 ( & V_8 -> V_39 . V_40 , V_3 ) ;
}
static int F_21 ( struct V_13 * V_14 , void * V_47 )
{
unsigned long V_3 ;
struct V_28 * V_29 ;
F_14 ( V_14 , L_14 ) ;
F_2 ( & V_4 , V_3 ) ;
F_16 (pos, &sync_timeline_list_head) {
struct V_1 * V_2 =
F_17 ( V_29 , struct V_1 ,
V_5 ) ;
F_15 ( V_14 , V_2 ) ;
F_14 ( V_14 , L_10 ) ;
}
F_4 ( & V_4 , V_3 ) ;
F_14 ( V_14 , L_15 ) ;
F_2 ( & V_9 , V_3 ) ;
F_16 (pos, &sync_fence_list_head) {
struct V_7 * V_8 =
F_17 ( V_29 , struct V_7 , V_10 ) ;
F_18 ( V_14 , V_8 ) ;
F_14 ( V_14 , L_10 ) ;
}
F_4 ( & V_9 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_23 ( V_49 , F_21 , V_48 -> V_50 ) ;
}
static T_2 int F_24 ( void )
{
F_25 ( L_16 , V_51 , NULL , NULL , & V_52 ) ;
return 0 ;
}
void F_26 ( void )
{
struct V_13 V_14 = {
. V_53 = V_54 ,
. V_55 = sizeof( V_54 ) - 1 ,
} ;
int V_36 ;
F_21 ( & V_14 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_14 . V_56 ; V_36 += V_57 ) {
if ( ( V_14 . V_56 - V_36 ) > V_57 ) {
char V_58 = V_14 . V_53 [ V_36 + V_57 ] ;
V_14 . V_53 [ V_36 + V_57 ] = 0 ;
F_27 ( L_17 , V_14 . V_53 + V_36 ) ;
V_14 . V_53 [ V_36 + V_57 ] = V_58 ;
} else {
V_14 . V_53 [ V_14 . V_56 ] = 0 ;
F_27 ( L_17 , V_14 . V_53 + V_36 ) ;
}
}
}
