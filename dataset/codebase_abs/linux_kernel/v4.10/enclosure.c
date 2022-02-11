struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( V_4 , & V_7 , V_8 ) ;
if ( V_4 )
F_4 ( & V_4 -> V_5 ) ;
F_5 (edev, &container_list, node) {
struct V_2 * V_9 = V_5 -> V_5 . V_9 ;
while ( V_9 ) {
if ( V_9 == V_3 ) {
F_6 ( & V_5 -> V_5 ) ;
F_7 ( & V_6 ) ;
return V_5 ;
}
V_9 = V_9 -> V_9 ;
}
}
F_7 ( & V_6 ) ;
return NULL ;
}
int F_8 ( int (* F_9)( struct V_1 * , void * ) ,
void * V_10 )
{
int error = 0 ;
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
F_10 (edev, &container_list, node) {
error = F_9 ( V_5 , V_10 ) ;
if ( error )
break;
}
F_7 ( & V_6 ) ;
return error ;
}
struct V_1 *
F_11 ( struct V_2 * V_3 , const char * V_11 , int V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_5 =
F_12 ( sizeof( struct V_1 ) +
sizeof( struct V_15 ) * V_12 ,
V_16 ) ;
int V_17 , V_18 ;
F_13 ( ! V_14 ) ;
if ( ! V_5 )
return F_14 ( - V_19 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_5 . V_20 = & V_21 ;
V_5 -> V_5 . V_9 = F_6 ( V_3 ) ;
V_5 -> V_14 = V_14 ;
F_15 ( & V_5 -> V_5 , L_1 , V_11 ) ;
V_17 = F_16 ( & V_5 -> V_5 ) ;
if ( V_17 )
goto V_17;
for ( V_18 = 0 ; V_18 < V_12 ; V_18 ++ ) {
V_5 -> V_22 [ V_18 ] . V_23 = - 1 ;
V_5 -> V_22 [ V_18 ] . V_24 = - 1 ;
V_5 -> V_22 [ V_18 ] . V_25 = 1 ;
}
F_2 ( & V_6 ) ;
F_17 ( & V_5 -> V_8 , & V_7 ) ;
F_7 ( & V_6 ) ;
return V_5 ;
V_17:
F_4 ( V_5 -> V_5 . V_9 ) ;
F_18 ( V_5 ) ;
return F_14 ( V_17 ) ;
}
void F_19 ( struct V_1 * V_5 )
{
int V_18 ;
F_2 ( & V_6 ) ;
F_20 ( & V_5 -> V_8 ) ;
F_7 ( & V_6 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ )
if ( V_5 -> V_22 [ V_18 ] . V_23 != - 1 )
F_21 ( & V_5 -> V_22 [ V_18 ] . V_26 ) ;
V_5 -> V_14 = & V_27 ;
F_21 ( & V_5 -> V_5 ) ;
}
static void F_22 ( struct V_15 * V_26 , char * V_11 )
{
strcpy ( V_11 , L_2 ) ;
strcat ( V_11 , F_23 ( & V_26 -> V_26 ) ) ;
}
static void F_24 ( struct V_15 * V_26 )
{
char V_11 [ V_28 ] ;
F_22 ( V_26 , V_11 ) ;
if ( V_26 -> V_3 -> V_29 . V_30 )
F_25 ( & V_26 -> V_3 -> V_29 , V_11 ) ;
if ( V_26 -> V_26 . V_29 . V_30 )
F_25 ( & V_26 -> V_26 . V_29 , L_3 ) ;
}
static int F_26 ( struct V_15 * V_26 )
{
int error ;
char V_11 [ V_28 ] ;
error = F_27 ( & V_26 -> V_26 . V_29 , & V_26 -> V_3 -> V_29 , L_3 ) ;
if ( error )
return error ;
F_22 ( V_26 , V_11 ) ;
error = F_27 ( & V_26 -> V_3 -> V_29 , & V_26 -> V_26 . V_29 , V_11 ) ;
if ( error )
F_25 ( & V_26 -> V_26 . V_29 , L_3 ) ;
return error ;
}
static void F_28 ( struct V_2 * V_26 )
{
struct V_1 * V_5 = F_29 ( V_26 ) ;
F_4 ( V_26 -> V_9 ) ;
F_18 ( V_5 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_15 * V_26 = F_31 ( V_3 ) ;
if ( V_26 -> V_3 ) {
F_24 ( V_26 ) ;
F_4 ( V_26 -> V_3 ) ;
}
F_4 ( V_3 -> V_9 ) ;
}
static struct V_15 *
F_32 ( struct V_1 * V_5 ,
const char * V_11 )
{
int V_18 ;
const char * V_31 ;
struct V_15 * V_32 ;
if ( ! V_5 || ! V_11 || ! V_11 [ 0 ] )
return NULL ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_32 = & V_5 -> V_22 [ V_18 ] ;
V_31 = F_23 ( & V_32 -> V_26 ) ;
if ( V_32 -> V_23 != - 1 &&
V_31 && V_31 [ 0 ] &&
! strcmp ( V_31 , V_11 ) )
return V_32 ;
}
return NULL ;
}
struct V_15 *
F_33 ( struct V_1 * V_5 ,
unsigned int V_23 ,
enum V_33 type ,
const char * V_11 )
{
struct V_15 * V_32 ;
struct V_2 * V_26 ;
int V_18 ;
char V_34 [ V_35 ] ;
if ( V_23 >= V_5 -> V_12 )
return F_14 ( - V_36 ) ;
V_32 = & V_5 -> V_22 [ V_23 ] ;
if ( V_32 -> V_23 != - 1 )
return F_14 ( - V_36 ) ;
V_32 -> type = type ;
V_32 -> V_23 = V_23 ;
V_26 = & V_32 -> V_26 ;
V_26 -> V_9 = F_6 ( & V_5 -> V_5 ) ;
if ( V_11 && V_11 [ 0 ] ) {
V_18 = 1 ;
snprintf ( V_34 , V_35 ,
L_1 , V_11 ) ;
while ( F_32 ( V_5 , V_34 ) )
snprintf ( V_34 , V_35 ,
L_4 , V_11 , V_18 ++ ) ;
F_15 ( V_26 , L_1 , V_34 ) ;
} else
F_15 ( V_26 , L_5 , V_23 ) ;
V_26 -> V_37 = F_30 ;
V_26 -> V_38 = V_39 ;
return V_32 ;
}
int F_34 ( struct V_15 * V_32 )
{
struct V_2 * V_26 ;
int V_17 ;
V_26 = & V_32 -> V_26 ;
V_17 = F_16 ( V_26 ) ;
if ( V_17 ) {
V_32 -> V_23 = - 1 ;
F_4 ( V_26 ) ;
return V_17 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_5 , int V_22 ,
struct V_2 * V_3 )
{
struct V_15 * V_26 ;
if ( ! V_5 || V_22 >= V_5 -> V_12 )
return - V_36 ;
V_26 = & V_5 -> V_22 [ V_22 ] ;
if ( V_26 -> V_3 == V_3 )
return - V_40 ;
if ( V_26 -> V_3 )
F_24 ( V_26 ) ;
F_4 ( V_26 -> V_3 ) ;
V_26 -> V_3 = F_6 ( V_3 ) ;
return F_26 ( V_26 ) ;
}
int F_36 ( struct V_1 * V_5 , struct V_2 * V_3 )
{
struct V_15 * V_26 ;
int V_18 ;
if ( ! V_5 || ! V_3 )
return - V_36 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_26 = & V_5 -> V_22 [ V_18 ] ;
if ( V_26 -> V_3 == V_3 ) {
F_24 ( V_26 ) ;
F_37 ( & V_26 -> V_26 ) ;
F_4 ( V_3 ) ;
V_26 -> V_3 = NULL ;
return F_38 ( & V_26 -> V_26 ) ;
}
}
return - V_41 ;
}
static T_1 F_39 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 ) ;
return snprintf ( V_44 , 40 , L_6 , V_5 -> V_12 ) ;
}
static T_1 F_40 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 ) ;
if ( V_5 -> V_14 -> V_45 )
return V_5 -> V_14 -> V_45 ( V_5 , V_44 ) ;
return - V_36 ;
}
static T_1 F_41 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
if ( V_5 -> V_14 -> V_46 )
V_5 -> V_14 -> V_46 ( V_5 , V_32 ) ;
return snprintf ( V_44 , 40 , L_6 , V_32 -> V_47 ) ;
}
static T_1 F_42 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
const char * V_44 , T_2 V_48 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_49 = F_43 ( V_44 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_50 )
V_5 -> V_14 -> V_50 ( V_5 , V_32 , V_49 ) ;
return V_48 ;
}
static T_1 F_44 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
if ( V_5 -> V_14 -> V_51 )
V_5 -> V_14 -> V_51 ( V_5 , V_32 ) ;
return snprintf ( V_44 , 40 , L_7 , V_52 [ V_32 -> V_53 ] ) ;
}
static T_1 F_45 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
const char * V_44 , T_2 V_48 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_18 ;
for ( V_18 = 0 ; V_52 [ V_18 ] ; V_18 ++ ) {
if ( strncmp ( V_44 , V_52 [ V_18 ] ,
strlen ( V_52 [ V_18 ] ) ) == 0 &&
( V_44 [ strlen ( V_52 [ V_18 ] ) ] == '\n' ||
V_44 [ strlen ( V_52 [ V_18 ] ) ] == '\0' ) )
break;
}
if ( V_52 [ V_18 ] && V_5 -> V_14 -> V_54 ) {
V_5 -> V_14 -> V_54 ( V_5 , V_32 , V_18 ) ;
return V_48 ;
} else
return - V_36 ;
}
static T_1 F_46 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
if ( V_5 -> V_14 -> V_55 )
V_5 -> V_14 -> V_55 ( V_5 , V_32 ) ;
return snprintf ( V_44 , 40 , L_6 , V_32 -> V_56 ) ;
}
static T_1 F_47 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
const char * V_44 , T_2 V_48 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_49 = F_43 ( V_44 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_57 )
V_5 -> V_14 -> V_57 ( V_5 , V_32 , V_49 ) ;
return V_48 ;
}
static T_1 F_48 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
if ( V_5 -> V_14 -> V_58 )
V_5 -> V_14 -> V_58 ( V_5 , V_32 ) ;
return snprintf ( V_44 , 40 , L_6 , V_32 -> V_59 ) ;
}
static T_1 F_49 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
const char * V_44 , T_2 V_48 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_49 = F_43 ( V_44 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_60 )
V_5 -> V_14 -> V_60 ( V_5 , V_32 , V_49 ) ;
return V_48 ;
}
static T_1 F_50 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
if ( V_5 -> V_14 -> V_61 )
V_5 -> V_14 -> V_61 ( V_5 , V_32 ) ;
return snprintf ( V_44 , 40 , L_7 , V_32 -> V_25 ? L_8 : L_9 ) ;
}
static T_1 F_51 ( struct V_2 * V_26 ,
struct V_42 * V_43 ,
const char * V_44 , T_2 V_48 )
{
struct V_1 * V_5 = F_29 ( V_26 -> V_9 ) ;
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_49 ;
if ( strncmp ( V_44 , L_8 , 2 ) == 0 &&
( V_44 [ 2 ] == '\n' || V_44 [ 2 ] == '\0' ) )
V_49 = 1 ;
else if ( strncmp ( V_44 , L_9 , 3 ) == 0 &&
( V_44 [ 3 ] == '\n' || V_44 [ 3 ] == '\0' ) )
V_49 = 0 ;
else
return - V_36 ;
if ( V_5 -> V_14 -> V_62 )
V_5 -> V_14 -> V_62 ( V_5 , V_32 , V_49 ) ;
return V_48 ;
}
static T_1 F_52 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_15 * V_32 = F_31 ( V_26 ) ;
return snprintf ( V_44 , 40 , L_7 , V_63 [ V_32 -> type ] ) ;
}
static T_1 F_53 ( struct V_2 * V_26 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_15 * V_32 = F_31 ( V_26 ) ;
int V_24 ;
if ( V_32 -> V_24 >= 0 )
V_24 = V_32 -> V_24 ;
else
V_24 = V_32 -> V_23 ;
return snprintf ( V_44 , 40 , L_6 , V_24 ) ;
}
static int T_3 F_54 ( void )
{
int V_17 ;
V_17 = F_55 ( & V_21 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_21 ) ;
}
