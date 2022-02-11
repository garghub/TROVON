static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_2 , & V_5 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_6 ( V_2 ) ;
F_4 ( & V_4 , V_3 ) ;
}
static struct V_6 *
F_7 ( char * V_7 , int V_8 )
{
struct V_6 * V_9 = (struct V_6 * )
( F_8 ( V_10 ,
FALSE ,
V_7 , V_8 ) ) ;
if ( ! V_9 )
return NULL ;
memset ( V_9 , 0 , sizeof( struct V_6 ) + V_11 ) ;
F_1 ( & V_9 -> V_12 ) ;
return V_9 ;
}
static void
F_9 ( struct V_6 * V_9 , char * V_7 , int V_8 )
{
F_5 ( & V_9 -> V_12 ) ;
F_10 ( V_10 , V_9 , V_7 , V_8 ) ;
}
int
F_11 ( T_1 V_13 )
{
int V_14 = - 1 ;
V_11 = V_13 ;
V_10 =
F_12 ( V_15 ,
sizeof( struct V_6 ) +
V_11 ,
0 , V_16 , NULL ) ;
if ( ! V_10 ) {
F_13 ( L_1 ) ;
V_14 = - V_17 ;
goto V_18;
}
V_14 = 0 ;
V_18:
if ( V_14 < 0 ) {
if ( V_10 ) {
F_14 ( V_10 ) ;
V_10 = NULL ;
}
}
return V_14 ;
}
void
F_15 ( void )
{
if ( V_10 ) {
F_14 ( V_10 ) ;
V_10 = NULL ;
}
}
static void *
F_16 ( void * V_19 ,
T_2 V_20 , T_2 V_21 ,
T_2 * V_22 )
{
void * V_23 ;
struct V_6 * V_9 = (struct V_6 * ) V_19 ;
if ( ! V_9 -> V_24 ) {
F_13 ( L_2 , V_25 ) ;
return NULL ;
}
V_23 = (* V_9 -> V_26 . V_27 )
( V_20 , V_21 , V_22 ) ;
if ( V_23 != NULL ) {
F_17 ( & V_9 -> V_26 . V_28 ) ;
F_18 ( L_3 , V_25 , * V_22 ) ;
}
return V_23 ;
}
static int
F_19 ( void * V_19 , void * V_23 ,
T_2 V_29 , T_2 V_30 )
{
struct V_6 * V_9 = (struct V_6 * ) V_19 ;
if ( ! V_9 -> V_24 ) {
F_13 ( L_2 , V_25 ) ;
return 0 ;
}
F_18 ( L_4 ,
V_30 , V_29 ) ;
if ( ! (* V_9 -> V_26 . V_31 )
( & V_9 -> V_26 . V_32 ,
V_9 -> V_33 ,
V_9 -> V_34 ++ ,
0 , V_23 , V_29 , V_30 , TRUE ) )
F_20 ( & V_9 -> V_26 . V_28 ) ;
return 0 ;
}
static void
F_21 ( void * V_19 , int V_35 )
{
struct V_6 * V_9 = (struct V_6 * ) V_19 ;
if ( ! V_9 -> V_24 ) {
F_13 ( L_2 , V_25 ) ;
return;
}
F_22 ( L_5 , V_35 ) ;
(* V_9 -> V_26 . V_31 )
( & V_9 -> V_26 . V_32 ,
V_9 -> V_33 ,
V_9 -> V_34 ++ , V_35 , NULL , 0 , 0 , FALSE ) ;
F_9 ( V_9 , __FILE__ , __LINE__ ) ;
F_23 ( V_36 ) ;
}
static int
F_24 ( void * V_19 , void * V_37 , T_1 V_38 ,
BOOL V_39 , T_1 * V_40 )
{
struct V_6 * V_9 = (struct V_6 * ) V_19 ;
if ( V_9 -> V_24 ) {
F_13 ( L_2 , V_25 ) ;
return - 1 ;
}
return (* V_9 -> V_41 . V_42 ) ( & V_9 -> V_43 [ 0 ] ,
V_37 , V_38 ,
V_39 ,
V_40 ) ;
}
static void
F_25 ( void * V_19 , int V_35 )
{
struct V_6 * V_9 = (struct V_6 * ) V_19 ;
if ( V_9 -> V_24 ) {
F_13 ( L_2 , V_25 ) ;
return;
}
(* V_9 -> V_41 . V_44 ) ( & V_9 -> V_43 [ 0 ] ,
V_35 ) ;
F_9 ( V_9 , __FILE__ , __LINE__ ) ;
F_23 ( V_36 ) ;
}
BOOL
F_26 ( T_3 * V_45 ,
T_4 V_33 ,
T_5 V_46 ,
T_5 V_47 ,
char * V_48 ,
T_6
V_27 ,
T_7
V_31 ,
T_8 V_49 )
{
BOOL V_50 = FALSE ;
BOOL V_51 = TRUE ;
struct V_6 * V_9 = F_7 ( __FILE__ , __LINE__ ) ;
if ( ! V_9 ) {
F_13 ( L_6 ) ;
goto V_18;
}
F_27 ( V_36 ) ;
V_50 = TRUE ;
V_9 -> V_24 = TRUE ;
V_9 -> V_33 = V_33 ;
V_9 -> V_34 = 0 ;
V_9 -> V_49 = V_49 ;
V_9 -> V_26 . V_32 = * V_45 ;
F_28 ( & V_9 -> V_26 . V_28 , 0 ) ;
V_9 -> V_26 . V_27 =
V_27 ;
V_9 -> V_26 . V_31 =
V_31 ;
if ( F_29 ( V_9 ,
V_48 ,
V_33 ,
V_46 ,
V_47 ,
F_16 ,
F_19 ,
F_21 ) < 0 ) {
F_13 ( L_7 ) ;
goto V_18;
}
V_51 = FALSE ;
V_18:
if ( V_51 ) {
if ( V_50 ) {
F_23 ( V_36 ) ;
V_50 = FALSE ;
}
if ( V_9 ) {
F_9 ( V_9 , __FILE__ , __LINE__ ) ;
V_9 = NULL ;
}
return FALSE ;
} else {
return TRUE ;
}
}
void *
F_30 ( T_3 * V_45 ,
T_4 V_33 ,
T_5 V_46 ,
T_5 V_47 ,
char * V_48 ,
T_9 V_52 ,
T_10 V_42 ,
T_11 V_44 ,
T_8 V_49 )
{
BOOL V_50 = FALSE ;
BOOL V_51 = TRUE ;
struct V_6 * V_9 = F_7 ( __FILE__ , __LINE__ ) ;
void * V_53 = NULL ;
if ( ! V_9 ) {
F_13 ( L_6 ) ;
goto V_18;
}
V_53 = ( void * ) ( & ( V_9 -> V_43 [ 0 ] ) ) ;
F_27 ( V_36 ) ;
V_50 = TRUE ;
V_9 -> V_24 = FALSE ;
V_9 -> V_33 = V_33 ;
V_9 -> V_34 = 0 ;
V_9 -> V_49 = V_49 ;
V_9 -> V_41 . V_42 = V_42 ;
V_9 -> V_41 . V_44 = V_44 ;
(* V_52) ( V_53 , V_45 , V_33 ) ;
if ( F_31 ( V_9 ,
V_48 ,
V_33 ,
V_46 ,
V_47 ,
F_24 , F_25 ) < 0 ) {
F_13 ( L_8 ) ;
goto V_18;
}
V_51 = FALSE ;
V_18:
if ( V_51 ) {
if ( V_50 ) {
F_23 ( V_36 ) ;
V_50 = FALSE ;
}
if ( V_9 ) {
F_9 ( V_9 , __FILE__ , __LINE__ ) ;
V_9 = NULL ;
}
return NULL ;
} else {
return V_53 ;
}
}
static void
F_32 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
F_33 ( V_55 , L_9 ,
F_34 ( & V_57 -> V_28 ) ) ;
}
static void
F_35 ( struct V_54 * V_55 , struct V_58 * V_59 )
{
}
static void
F_36 ( struct V_54 * V_55 , struct V_6 * V_9 )
{
F_33 ( V_55 , L_10 ,
( ( V_9 -> V_24 ) ? L_11 : L_12 ) ,
V_9 -> V_33 , V_9 -> V_34 ) ;
if ( V_9 -> V_24 )
F_32 ( V_55 , & V_9 -> V_26 ) ;
else
F_35 ( V_55 , & V_9 -> V_41 ) ;
if ( V_9 -> V_49 )
(* V_9 -> V_49 ) ( V_55 , & ( V_9 -> V_43 [ 0 ] ) , L_13 ) ;
}
void
F_37 ( struct V_54 * V_55 )
{
T_2 V_3 ;
struct V_1 * V_60 ;
F_38 ( V_55 , L_14 ) ;
F_2 ( & V_4 , V_3 ) ;
F_39 (entry, &Request_list) {
struct V_6 * V_9 ;
V_9 = F_40 ( V_60 , struct V_6 , V_12 ) ;
F_36 ( V_55 , V_9 ) ;
}
F_4 ( & V_4 , V_3 ) ;
}
int
F_11 ( T_1 V_13 )
{
return 0 ;
}
void
F_15 ( void )
{
}
BOOL
F_26 ( T_3 * V_45 ,
T_12 V_33 ,
T_5 V_46 ,
T_5 V_47 ,
char * V_48 ,
T_6
V_27 ,
T_7
V_31 ,
T_8 V_49 )
{
return FALSE ;
}
void *
F_30 ( T_3 * V_45 ,
T_12 V_33 ,
T_5 V_46 ,
T_5 V_47 ,
char * V_48 ,
T_9 V_52 ,
T_10 V_42 ,
T_11 V_44 ,
T_8 V_49 )
{
return NULL ;
}
void
F_37 ( struct V_54 * V_55 )
{
}
