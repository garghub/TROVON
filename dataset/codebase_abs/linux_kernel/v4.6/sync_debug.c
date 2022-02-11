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
if ( ( ! V_14 || V_14 -> V_24 -> V_25 ) &&
V_14 -> V_24 -> V_26 ) {
char V_27 [ 64 ] ;
bool V_28 ;
V_14 -> V_24 -> V_26 ( V_14 , V_27 , sizeof( V_27 ) ) ;
V_28 = strlen ( V_27 ) ;
if ( V_28 )
F_13 ( V_13 , L_8 , V_27 ) ;
if ( V_28 && V_14 ) {
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
F_13 ( V_13 , L_11 , V_2 -> V_17 , V_2 -> V_24 -> V_31 ) ;
if ( V_2 -> V_24 -> V_25 ) {
char V_27 [ 64 ] ;
V_2 -> V_24 -> V_25 ( V_2 , V_27 , sizeof( V_27 ) ) ;
F_13 ( V_13 , L_8 , V_27 ) ;
}
F_15 ( V_13 , L_10 ) ;
F_2 ( & V_2 -> V_32 , V_3 ) ;
F_17 (pos, &obj->child_list_head) {
struct V_14 * V_14 =
F_18 ( V_30 , struct V_14 , V_33 ) ;
F_10 ( V_13 , V_14 , false ) ;
}
F_4 ( & V_2 -> V_32 , V_3 ) ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_7 * V_7 )
{
int V_34 ;
F_13 ( V_13 , L_12 , V_7 , V_7 -> V_17 ,
F_9 ( F_20 ( & V_7 -> V_11 ) ) ) ;
for ( V_34 = 0 ; V_34 < V_7 -> V_35 ; ++ V_34 )
F_10 ( V_13 , V_7 -> V_36 [ V_34 ] . V_14 , true ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_37 )
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
static int F_22 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_23 ( V_39 , F_21 , V_38 -> V_40 ) ;
}
static int F_24 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
struct V_41 * V_2 ;
char V_42 [ V_43 ] ;
F_25 ( V_42 , V_44 ) ;
V_2 = F_26 ( V_42 ) ;
if ( ! V_2 )
return - V_45 ;
V_39 -> V_46 = V_2 ;
return 0 ;
}
static int F_27 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
struct V_41 * V_2 = V_39 -> V_46 ;
F_28 ( & V_2 -> V_2 ) ;
return 0 ;
}
static long F_29 ( struct V_41 * V_2 ,
unsigned long V_47 )
{
int V_48 = F_30 ( V_49 ) ;
int V_50 ;
struct V_14 * V_14 ;
struct V_7 * V_7 ;
struct V_51 V_52 ;
if ( V_48 < 0 )
return V_48 ;
if ( F_31 ( & V_52 , ( void V_53 * ) V_47 , sizeof( V_52 ) ) ) {
V_50 = - V_54 ;
goto V_50;
}
V_14 = F_32 ( V_2 , V_52 . V_27 ) ;
if ( ! V_14 ) {
V_50 = - V_45 ;
goto V_50;
}
V_52 . V_17 [ sizeof( V_52 . V_17 ) - 1 ] = '\0' ;
V_7 = F_33 ( V_52 . V_17 , V_14 ) ;
if ( ! V_7 ) {
F_34 ( V_14 ) ;
V_50 = - V_45 ;
goto V_50;
}
V_52 . V_14 = V_48 ;
if ( F_35 ( ( void V_53 * ) V_47 , & V_52 , sizeof( V_52 ) ) ) {
F_36 ( V_7 ) ;
V_50 = - V_54 ;
goto V_50;
}
F_37 ( V_7 , V_48 ) ;
return 0 ;
V_50:
F_38 ( V_48 ) ;
return V_50 ;
}
static long F_39 ( struct V_41 * V_2 , unsigned long V_47 )
{
T_1 V_27 ;
if ( F_31 ( & V_27 , ( void V_53 * ) V_47 , sizeof( V_27 ) ) )
return - V_54 ;
F_40 ( V_2 , V_27 ) ;
return 0 ;
}
static long F_41 ( struct V_39 * V_39 , unsigned int V_55 ,
unsigned long V_47 )
{
struct V_41 * V_2 = V_39 -> V_46 ;
switch ( V_55 ) {
case V_56 :
return F_29 ( V_2 , V_47 ) ;
case V_57 :
return F_39 ( V_2 , V_47 ) ;
default:
return - V_58 ;
}
}
static T_2 int F_42 ( void )
{
V_59 = F_43 ( L_15 , NULL ) ;
F_44 ( L_16 , 0444 , V_59 , NULL , & V_60 ) ;
F_44 ( L_17 , 0644 , V_59 , NULL ,
& V_61 ) ;
return 0 ;
}
void F_45 ( void )
{
struct V_12 V_13 = {
. V_62 = V_63 ,
. V_64 = sizeof( V_63 ) - 1 ,
} ;
int V_34 ;
F_21 ( & V_13 , NULL ) ;
for ( V_34 = 0 ; V_34 < V_13 . V_65 ; V_34 += V_66 ) {
if ( ( V_13 . V_65 - V_34 ) > V_66 ) {
char V_67 = V_13 . V_62 [ V_34 + V_66 ] ;
V_13 . V_62 [ V_34 + V_66 ] = 0 ;
F_46 ( L_18 , V_13 . V_62 + V_34 ) ;
V_13 . V_62 [ V_34 + V_66 ] = V_67 ;
} else {
V_13 . V_62 [ V_13 . V_65 ] = 0 ;
F_46 ( L_18 , V_13 . V_62 + V_34 ) ;
}
}
}
