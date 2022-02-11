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
static void F_10 ( struct V_13 * V_14 , struct V_15 * V_16 , bool V_8 )
{
int V_12 = 1 ;
struct V_1 * V_17 = F_11 ( V_16 ) ;
if ( F_12 ( & V_16 -> V_18 ) )
V_12 = V_16 -> V_18 . V_12 ;
F_13 ( V_14 , L_4 ,
V_8 ? V_17 -> V_19 : L_5 ,
V_8 ? L_6 : L_5 ,
F_9 ( V_12 ) ) ;
if ( V_12 <= 0 ) {
struct V_20 V_21 =
F_14 ( V_16 -> V_18 . V_22 ) ;
F_13 ( V_14 , L_7 , ( V_23 ) V_21 . V_24 , V_21 . V_25 ) ;
}
if ( V_17 -> V_26 -> V_27 &&
V_17 -> V_26 -> V_28 ) {
char V_29 [ 64 ] ;
V_17 -> V_26 -> V_28 ( V_16 , V_29 , sizeof( V_29 ) ) ;
F_13 ( V_14 , L_8 , V_29 ) ;
if ( V_8 ) {
V_17 -> V_26 -> V_27 ( V_17 , V_29 ,
sizeof( V_29 ) ) ;
F_13 ( V_14 , L_9 , V_29 ) ;
}
}
F_15 ( V_14 , L_10 ) ;
}
static void F_16 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_30 * V_31 ;
unsigned long V_3 ;
F_13 ( V_14 , L_11 , V_2 -> V_19 , V_2 -> V_26 -> V_32 ) ;
if ( V_2 -> V_26 -> V_27 ) {
char V_29 [ 64 ] ;
V_2 -> V_26 -> V_27 ( V_2 , V_29 , sizeof( V_29 ) ) ;
F_13 ( V_14 , L_8 , V_29 ) ;
}
F_15 ( V_14 , L_10 ) ;
F_2 ( & V_2 -> V_33 , V_3 ) ;
F_17 (pos, &obj->child_list_head) {
struct V_15 * V_16 =
F_18 ( V_31 , struct V_15 , V_34 ) ;
F_10 ( V_14 , V_16 , false ) ;
}
F_4 ( & V_2 -> V_33 , V_3 ) ;
}
static void F_19 ( struct V_13 * V_14 , struct V_7 * V_8 )
{
T_1 * V_31 ;
unsigned long V_3 ;
int V_35 ;
F_13 ( V_14 , L_12 , V_8 , V_8 -> V_19 ,
F_9 ( F_20 ( & V_8 -> V_12 ) ) ) ;
for ( V_35 = 0 ; V_35 < V_8 -> V_36 ; ++ V_35 ) {
struct V_15 * V_16 =
F_18 ( V_8 -> V_37 [ V_35 ] . V_15 ,
struct V_15 , V_18 ) ;
F_10 ( V_14 , V_16 , true ) ;
}
F_2 ( & V_8 -> V_38 . V_39 , V_3 ) ;
F_21 (pos, &fence->wq.task_list, task_list) {
struct V_40 * V_41 ;
if ( V_31 -> V_42 != & V_43 )
continue;
V_41 = F_18 ( V_31 , struct V_40 , V_44 ) ;
F_13 ( V_14 , L_13 , V_41 -> V_45 ) ;
}
F_4 ( & V_8 -> V_38 . V_39 , V_3 ) ;
}
static int F_22 ( struct V_13 * V_14 , void * V_46 )
{
unsigned long V_3 ;
struct V_30 * V_31 ;
F_15 ( V_14 , L_14 ) ;
F_2 ( & V_4 , V_3 ) ;
F_17 (pos, &sync_timeline_list_head) {
struct V_1 * V_2 =
F_18 ( V_31 , struct V_1 ,
V_5 ) ;
F_16 ( V_14 , V_2 ) ;
F_15 ( V_14 , L_10 ) ;
}
F_4 ( & V_4 , V_3 ) ;
F_15 ( V_14 , L_15 ) ;
F_2 ( & V_9 , V_3 ) ;
F_17 (pos, &sync_fence_list_head) {
struct V_7 * V_8 =
F_18 ( V_31 , struct V_7 , V_10 ) ;
F_19 ( V_14 , V_8 ) ;
F_15 ( V_14 , L_10 ) ;
}
F_4 ( & V_9 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
return F_24 ( V_48 , F_22 , V_47 -> V_49 ) ;
}
static T_2 int F_25 ( void )
{
F_26 ( L_16 , V_50 , NULL , NULL , & V_51 ) ;
return 0 ;
}
void F_27 ( void )
{
struct V_13 V_14 = {
. V_52 = V_53 ,
. V_54 = sizeof( V_53 ) - 1 ,
} ;
int V_35 ;
F_22 ( & V_14 , NULL ) ;
for ( V_35 = 0 ; V_35 < V_14 . V_55 ; V_35 += V_56 ) {
if ( ( V_14 . V_55 - V_35 ) > V_56 ) {
char V_57 = V_14 . V_52 [ V_35 + V_56 ] ;
V_14 . V_52 [ V_35 + V_56 ] = 0 ;
F_28 ( L_17 , V_14 . V_52 + V_35 ) ;
V_14 . V_52 [ V_35 + V_56 ] = V_57 ;
} else {
V_14 . V_52 [ V_14 . V_55 ] = 0 ;
F_28 ( L_17 , V_14 . V_52 + V_35 ) ;
}
}
}
