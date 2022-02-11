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
void F_7 ( struct V_7 * V_7 )
{
unsigned long V_3 ;
F_2 ( & V_8 , V_3 ) ;
F_3 ( & V_7 -> V_9 , & V_10 ) ;
F_4 ( & V_8 , V_3 ) ;
}
void F_8 ( struct V_7 * V_7 )
{
unsigned long V_3 ;
F_2 ( & V_8 , V_3 ) ;
F_6 ( & V_7 -> V_9 ) ;
F_4 ( & V_8 , V_3 ) ;
}
static const char * F_9 ( int V_11 )
{
if ( V_11 == 0 )
return L_1 ;
if ( V_11 > 0 )
return L_2 ;
return L_3 ;
}
static void F_10 ( struct V_12 * V_13 , struct V_14 * V_14 , bool V_15 )
{
int V_11 = 1 ;
struct V_1 * V_16 = F_11 ( V_14 ) ;
if ( F_12 ( V_14 ) )
V_11 = V_14 -> V_11 ;
F_13 ( V_13 , L_4 ,
V_15 ? V_16 -> V_17 : L_5 ,
V_15 ? L_6 : L_5 ,
F_9 ( V_11 ) ) ;
if ( V_11 <= 0 ) {
struct V_18 V_19 =
F_14 ( V_14 -> V_20 ) ;
F_13 ( V_13 , L_7 , ( V_21 ) V_19 . V_22 , V_19 . V_23 ) ;
}
if ( V_14 -> V_24 -> V_25 &&
V_14 -> V_24 -> V_26 ) {
char V_27 [ 64 ] ;
bool V_28 ;
V_14 -> V_24 -> V_26 ( V_14 , V_27 , sizeof( V_27 ) ) ;
V_28 = strlen ( V_27 ) ;
if ( V_28 ) {
F_13 ( V_13 , L_8 , V_27 ) ;
V_14 -> V_24 -> V_25 ( V_14 , V_27 ,
sizeof( V_27 ) ) ;
if ( strlen ( V_27 ) )
F_13 ( V_13 , L_9 , V_27 ) ;
}
}
F_15 ( V_13 , L_10 ) ;
}
static void F_16 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_29 * V_30 ;
unsigned long V_3 ;
F_13 ( V_13 , L_11 , V_2 -> V_17 , V_2 -> V_27 ) ;
F_2 ( & V_2 -> V_31 , V_3 ) ;
F_17 (pos, &obj->child_list_head) {
struct V_32 * V_33 =
F_18 ( V_30 , struct V_32 , V_34 ) ;
F_10 ( V_13 , & V_33 -> V_35 , false ) ;
}
F_4 ( & V_2 -> V_31 , V_3 ) ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_7 * V_7 )
{
int V_36 ;
F_13 ( V_13 , L_12 , V_7 , V_7 -> V_17 ,
F_9 ( F_20 ( & V_7 -> V_11 ) ) ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_37 ; ++ V_36 )
F_10 ( V_13 , V_7 -> V_38 [ V_36 ] . V_14 , true ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_39 )
{
unsigned long V_3 ;
struct V_29 * V_30 ;
F_15 ( V_13 , L_13 ) ;
F_2 ( & V_4 , V_3 ) ;
F_17 (pos, &sync_timeline_list_head) {
struct V_1 * V_2 =
F_18 ( V_30 , struct V_1 ,
V_5 ) ;
F_16 ( V_13 , V_2 ) ;
F_15 ( V_13 , L_10 ) ;
}
F_4 ( & V_4 , V_3 ) ;
F_15 ( V_13 , L_14 ) ;
F_2 ( & V_8 , V_3 ) ;
F_17 (pos, &sync_file_list_head) {
struct V_7 * V_7 =
F_18 ( V_30 , struct V_7 , V_9 ) ;
F_19 ( V_13 , V_7 ) ;
F_15 ( V_13 , L_10 ) ;
}
F_4 ( & V_8 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
return F_23 ( V_41 , F_21 , V_40 -> V_42 ) ;
}
static T_1 int F_24 ( void )
{
V_43 = F_25 ( L_15 , NULL ) ;
F_26 ( L_16 , 0444 , V_43 , NULL ,
& V_44 ) ;
F_26 ( L_17 , 0644 , V_43 , NULL ,
& V_45 ) ;
return 0 ;
}
void F_27 ( void )
{
struct V_12 V_13 = {
. V_46 = V_47 ,
. V_48 = sizeof( V_47 ) - 1 ,
} ;
int V_36 ;
F_21 ( & V_13 , NULL ) ;
for ( V_36 = 0 ; V_36 < V_13 . V_49 ; V_36 += V_50 ) {
if ( ( V_13 . V_49 - V_36 ) > V_50 ) {
char V_51 = V_13 . V_46 [ V_36 + V_50 ] ;
V_13 . V_46 [ V_36 + V_50 ] = 0 ;
F_28 ( L_18 , V_13 . V_46 + V_36 ) ;
V_13 . V_46 [ V_36 + V_50 ] = V_51 ;
} else {
V_13 . V_46 [ V_13 . V_49 ] = 0 ;
F_28 ( L_18 , V_13 . V_46 + V_36 ) ;
}
}
}
