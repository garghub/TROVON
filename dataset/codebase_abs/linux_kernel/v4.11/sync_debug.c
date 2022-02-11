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
if ( V_11 < 0 )
return L_1 ;
if ( V_11 > 0 )
return L_2 ;
return L_3 ;
}
static void F_10 ( struct V_12 * V_13 ,
struct V_14 * V_15 , bool V_16 )
{
struct V_1 * V_17 = F_11 ( V_15 ) ;
int V_11 ;
V_11 = F_12 ( V_15 ) ;
F_13 ( V_13 , L_4 ,
V_16 ? V_17 -> V_18 : L_5 ,
V_16 ? L_6 : L_5 ,
F_9 ( V_11 ) ) ;
if ( V_11 ) {
struct V_19 V_20 =
F_14 ( V_15 -> V_21 ) ;
F_13 ( V_13 , L_7 , ( V_22 ) V_20 . V_23 , V_20 . V_24 ) ;
}
if ( V_15 -> V_25 -> V_26 &&
V_15 -> V_25 -> V_27 ) {
char V_28 [ 64 ] ;
bool V_29 ;
V_15 -> V_25 -> V_27 ( V_15 , V_28 , sizeof( V_28 ) ) ;
V_29 = strlen ( V_28 ) ;
if ( V_29 ) {
F_13 ( V_13 , L_8 , V_28 ) ;
V_15 -> V_25 -> V_26 ( V_15 , V_28 ,
sizeof( V_28 ) ) ;
if ( strlen ( V_28 ) )
F_13 ( V_13 , L_9 , V_28 ) ;
}
}
F_15 ( V_13 , L_10 ) ;
}
static void F_16 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 ;
unsigned long V_3 ;
F_13 ( V_13 , L_11 , V_2 -> V_18 , V_2 -> V_28 ) ;
F_2 ( & V_2 -> V_32 , V_3 ) ;
F_17 (pos, &obj->child_list_head) {
struct V_33 * V_34 =
F_18 ( V_31 , struct V_33 , V_35 ) ;
F_10 ( V_13 , & V_34 -> V_36 , false ) ;
}
F_4 ( & V_2 -> V_32 , V_3 ) ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_7 * V_7 )
{
int V_37 ;
F_13 ( V_13 , L_12 , V_7 , V_7 -> V_18 ,
F_9 ( F_20 ( V_7 -> V_15 ) ) ) ;
if ( F_21 ( V_7 -> V_15 ) ) {
struct V_38 * V_39 = F_22 ( V_7 -> V_15 ) ;
for ( V_37 = 0 ; V_37 < V_39 -> V_40 ; ++ V_37 )
F_10 ( V_13 , V_39 -> V_41 [ V_37 ] , true ) ;
} else {
F_10 ( V_13 , V_7 -> V_15 , true ) ;
}
}
static int F_23 ( struct V_12 * V_13 , void * V_42 )
{
unsigned long V_3 ;
struct V_30 * V_31 ;
F_15 ( V_13 , L_13 ) ;
F_2 ( & V_4 , V_3 ) ;
F_17 (pos, &sync_timeline_list_head) {
struct V_1 * V_2 =
F_18 ( V_31 , struct V_1 ,
V_5 ) ;
F_16 ( V_13 , V_2 ) ;
F_15 ( V_13 , L_10 ) ;
}
F_4 ( & V_4 , V_3 ) ;
F_15 ( V_13 , L_14 ) ;
F_2 ( & V_8 , V_3 ) ;
F_17 (pos, &sync_file_list_head) {
struct V_7 * V_7 =
F_18 ( V_31 , struct V_7 , V_9 ) ;
F_19 ( V_13 , V_7 ) ;
F_15 ( V_13 , L_10 ) ;
}
F_4 ( & V_8 , V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_43 * V_43 , struct V_44 * V_44 )
{
return F_25 ( V_44 , F_23 , V_43 -> V_45 ) ;
}
static T_1 int F_26 ( void )
{
V_46 = F_27 ( L_15 , NULL ) ;
F_28 ( L_16 , 0444 , V_46 , NULL ,
& V_47 ) ;
F_28 ( L_17 , 0644 , V_46 , NULL ,
& V_48 ) ;
return 0 ;
}
void F_29 ( void )
{
struct V_12 V_13 = {
. V_49 = V_50 ,
. V_51 = sizeof( V_50 ) - 1 ,
} ;
int V_37 ;
F_23 ( & V_13 , NULL ) ;
for ( V_37 = 0 ; V_37 < V_13 . V_52 ; V_37 += V_53 ) {
if ( ( V_13 . V_52 - V_37 ) > V_53 ) {
char V_54 = V_13 . V_49 [ V_37 + V_53 ] ;
V_13 . V_49 [ V_37 + V_53 ] = 0 ;
F_30 ( L_18 , V_13 . V_49 + V_37 ) ;
V_13 . V_49 [ V_37 + V_53 ] = V_54 ;
} else {
V_13 . V_49 [ V_13 . V_52 ] = 0 ;
F_30 ( L_18 , V_13 . V_49 + V_37 ) ;
}
}
}
