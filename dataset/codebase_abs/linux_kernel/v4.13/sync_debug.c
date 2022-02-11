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
if ( F_14 ( V_19 , & V_15 -> V_3 ) ) {
struct V_20 V_21 =
F_15 ( V_15 -> V_22 ) ;
F_13 ( V_13 , L_7 , ( V_23 ) V_21 . V_24 , V_21 . V_25 ) ;
}
if ( V_15 -> V_26 -> V_27 &&
V_15 -> V_26 -> V_28 ) {
char V_29 [ 64 ] ;
bool V_30 ;
V_15 -> V_26 -> V_28 ( V_15 , V_29 , sizeof( V_29 ) ) ;
V_30 = strlen ( V_29 ) ;
if ( V_30 ) {
F_13 ( V_13 , L_8 , V_29 ) ;
V_15 -> V_26 -> V_27 ( V_15 , V_29 ,
sizeof( V_29 ) ) ;
if ( strlen ( V_29 ) )
F_13 ( V_13 , L_9 , V_29 ) ;
}
}
F_16 ( V_13 , '\n' ) ;
}
static void F_17 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_31 * V_32 ;
unsigned long V_3 ;
F_13 ( V_13 , L_10 , V_2 -> V_18 , V_2 -> V_29 ) ;
F_2 ( & V_2 -> V_33 , V_3 ) ;
F_18 (pos, &obj->child_list_head) {
struct V_34 * V_35 =
F_19 ( V_32 , struct V_34 , V_36 ) ;
F_10 ( V_13 , & V_35 -> V_37 , false ) ;
}
F_4 ( & V_2 -> V_33 , V_3 ) ;
}
static void F_20 ( struct V_12 * V_13 ,
struct V_7 * V_7 )
{
char V_38 [ 128 ] ;
int V_39 ;
F_13 ( V_13 , L_11 , V_7 ,
F_21 ( V_7 , V_38 , sizeof( V_38 ) ) ,
F_9 ( F_22 ( V_7 -> V_15 ) ) ) ;
if ( F_23 ( V_7 -> V_15 ) ) {
struct V_40 * V_41 = F_24 ( V_7 -> V_15 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_42 ; ++ V_39 )
F_10 ( V_13 , V_41 -> V_43 [ V_39 ] , true ) ;
} else {
F_10 ( V_13 , V_7 -> V_15 , true ) ;
}
}
static int F_25 ( struct V_12 * V_13 , void * V_44 )
{
unsigned long V_3 ;
struct V_31 * V_32 ;
F_26 ( V_13 , L_12 ) ;
F_2 ( & V_4 , V_3 ) ;
F_18 (pos, &sync_timeline_list_head) {
struct V_1 * V_2 =
F_19 ( V_32 , struct V_1 ,
V_5 ) ;
F_17 ( V_13 , V_2 ) ;
F_16 ( V_13 , '\n' ) ;
}
F_4 ( & V_4 , V_3 ) ;
F_26 ( V_13 , L_13 ) ;
F_2 ( & V_8 , V_3 ) ;
F_18 (pos, &sync_file_list_head) {
struct V_7 * V_7 =
F_19 ( V_32 , struct V_7 , V_9 ) ;
F_20 ( V_13 , V_7 ) ;
F_16 ( V_13 , '\n' ) ;
}
F_4 ( & V_8 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_28 ( V_46 , F_25 , V_45 -> V_47 ) ;
}
static T_1 int F_29 ( void )
{
V_48 = F_30 ( L_14 , NULL ) ;
F_31 ( L_15 , 0444 , V_48 , NULL ,
& V_49 ) ;
F_31 ( L_16 , 0644 , V_48 , NULL ,
& V_50 ) ;
return 0 ;
}
void F_32 ( void )
{
struct V_12 V_13 = {
. V_38 = V_51 ,
. V_52 = sizeof( V_51 ) - 1 ,
} ;
int V_39 ;
F_25 ( & V_13 , NULL ) ;
for ( V_39 = 0 ; V_39 < V_13 . V_53 ; V_39 += V_54 ) {
if ( ( V_13 . V_53 - V_39 ) > V_54 ) {
char V_55 = V_13 . V_38 [ V_39 + V_54 ] ;
V_13 . V_38 [ V_39 + V_54 ] = 0 ;
F_33 ( L_17 , V_13 . V_38 + V_39 ) ;
V_13 . V_38 [ V_39 + V_54 ] = V_55 ;
} else {
V_13 . V_38 [ V_13 . V_53 ] = 0 ;
F_33 ( L_17 , V_13 . V_38 + V_39 ) ;
}
}
}
