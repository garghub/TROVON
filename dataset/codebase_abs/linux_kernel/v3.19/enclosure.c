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
for ( V_18 = 0 ; V_18 < V_12 ; V_18 ++ )
V_5 -> V_22 [ V_18 ] . V_23 = - 1 ;
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
F_21 ( & V_5 -> V_22 [ V_18 ] . V_24 ) ;
V_5 -> V_14 = & V_25 ;
F_21 ( & V_5 -> V_5 ) ;
}
static void F_22 ( struct V_15 * V_24 , char * V_11 )
{
strcpy ( V_11 , L_2 ) ;
strcat ( V_11 , F_23 ( & V_24 -> V_24 ) ) ;
}
static void F_24 ( struct V_15 * V_24 )
{
char V_11 [ V_26 ] ;
if ( ! V_24 -> V_3 -> V_27 . V_28 )
return;
F_22 ( V_24 , V_11 ) ;
F_25 ( & V_24 -> V_3 -> V_27 , V_11 ) ;
F_25 ( & V_24 -> V_24 . V_27 , L_3 ) ;
}
static int F_26 ( struct V_15 * V_24 )
{
int error ;
char V_11 [ V_26 ] ;
error = F_27 ( & V_24 -> V_24 . V_27 , & V_24 -> V_3 -> V_27 , L_3 ) ;
if ( error )
return error ;
F_22 ( V_24 , V_11 ) ;
error = F_27 ( & V_24 -> V_3 -> V_27 , & V_24 -> V_24 . V_27 , V_11 ) ;
if ( error )
F_25 ( & V_24 -> V_24 . V_27 , L_3 ) ;
return error ;
}
static void F_28 ( struct V_2 * V_24 )
{
struct V_1 * V_5 = F_29 ( V_24 ) ;
F_4 ( V_24 -> V_9 ) ;
F_18 ( V_5 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_15 * V_24 = F_31 ( V_3 ) ;
if ( V_24 -> V_3 ) {
F_24 ( V_24 ) ;
F_4 ( V_24 -> V_3 ) ;
}
F_4 ( V_3 -> V_9 ) ;
}
static struct V_15 *
F_32 ( struct V_1 * V_5 ,
const char * V_11 )
{
int V_18 ;
const char * V_29 ;
struct V_15 * V_30 ;
if ( ! V_5 || ! V_11 || ! V_11 [ 0 ] )
return NULL ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_30 = & V_5 -> V_22 [ V_18 ] ;
V_29 = F_23 ( & V_30 -> V_24 ) ;
if ( V_30 -> V_23 != - 1 &&
V_29 && V_29 [ 0 ] &&
! strcmp ( V_29 , V_11 ) )
return V_30 ;
}
return NULL ;
}
struct V_15 *
F_33 ( struct V_1 * V_5 ,
unsigned int V_23 ,
enum V_31 type ,
const char * V_11 )
{
struct V_15 * V_30 ;
struct V_2 * V_24 ;
int V_17 , V_18 ;
char V_32 [ V_33 ] ;
if ( V_23 >= V_5 -> V_12 )
return F_14 ( - V_34 ) ;
V_30 = & V_5 -> V_22 [ V_23 ] ;
if ( V_30 -> V_23 != - 1 )
return F_14 ( - V_34 ) ;
V_30 -> type = type ;
V_30 -> V_23 = V_23 ;
V_24 = & V_30 -> V_24 ;
V_24 -> V_9 = F_6 ( & V_5 -> V_5 ) ;
if ( V_11 && V_11 [ 0 ] ) {
V_18 = 1 ;
snprintf ( V_32 , V_33 ,
L_1 , V_11 ) ;
while ( F_32 ( V_5 , V_32 ) )
snprintf ( V_32 , V_33 ,
L_4 , V_11 , V_18 ++ ) ;
F_15 ( V_24 , L_1 , V_32 ) ;
} else
F_15 ( V_24 , L_5 , V_23 ) ;
V_24 -> V_35 = F_30 ;
V_24 -> V_36 = V_37 ;
V_17 = F_16 ( V_24 ) ;
if ( V_17 ) {
V_30 -> V_23 = - 1 ;
F_4 ( V_24 ) ;
return F_14 ( V_17 ) ;
}
return V_30 ;
}
int F_34 ( struct V_1 * V_5 , int V_22 ,
struct V_2 * V_3 )
{
struct V_15 * V_24 ;
if ( ! V_5 || V_22 >= V_5 -> V_12 )
return - V_34 ;
V_24 = & V_5 -> V_22 [ V_22 ] ;
if ( V_24 -> V_3 == V_3 )
return - V_38 ;
if ( V_24 -> V_3 )
F_24 ( V_24 ) ;
F_4 ( V_24 -> V_3 ) ;
V_24 -> V_3 = F_6 ( V_3 ) ;
return F_26 ( V_24 ) ;
}
int F_35 ( struct V_1 * V_5 , struct V_2 * V_3 )
{
struct V_15 * V_24 ;
int V_18 ;
if ( ! V_5 || ! V_3 )
return - V_34 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_24 = & V_5 -> V_22 [ V_18 ] ;
if ( V_24 -> V_3 == V_3 ) {
F_24 ( V_24 ) ;
F_36 ( & V_24 -> V_24 ) ;
F_4 ( V_3 ) ;
V_24 -> V_3 = NULL ;
return F_37 ( & V_24 -> V_24 ) ;
}
}
return - V_39 ;
}
static T_1 F_38 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_1 * V_5 = F_29 ( V_24 ) ;
return snprintf ( V_42 , 40 , L_6 , V_5 -> V_12 ) ;
}
static T_1 F_39 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_43 )
V_5 -> V_14 -> V_43 ( V_5 , V_30 ) ;
return snprintf ( V_42 , 40 , L_6 , V_30 -> V_44 ) ;
}
static T_1 F_40 ( struct V_2 * V_24 ,
struct V_40 * V_41 ,
const char * V_42 , T_2 V_45 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
int V_46 = F_41 ( V_42 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_47 )
V_5 -> V_14 -> V_47 ( V_5 , V_30 , V_46 ) ;
return V_45 ;
}
static T_1 F_42 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_48 )
V_5 -> V_14 -> V_48 ( V_5 , V_30 ) ;
return snprintf ( V_42 , 40 , L_7 , V_49 [ V_30 -> V_50 ] ) ;
}
static T_1 F_43 ( struct V_2 * V_24 ,
struct V_40 * V_41 ,
const char * V_42 , T_2 V_45 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
int V_18 ;
for ( V_18 = 0 ; V_49 [ V_18 ] ; V_18 ++ ) {
if ( strncmp ( V_42 , V_49 [ V_18 ] ,
strlen ( V_49 [ V_18 ] ) ) == 0 &&
( V_42 [ strlen ( V_49 [ V_18 ] ) ] == '\n' ||
V_42 [ strlen ( V_49 [ V_18 ] ) ] == '\0' ) )
break;
}
if ( V_49 [ V_18 ] && V_5 -> V_14 -> V_51 ) {
V_5 -> V_14 -> V_51 ( V_5 , V_30 , V_18 ) ;
return V_45 ;
} else
return - V_34 ;
}
static T_1 F_44 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_52 )
V_5 -> V_14 -> V_52 ( V_5 , V_30 ) ;
return snprintf ( V_42 , 40 , L_6 , V_30 -> V_53 ) ;
}
static T_1 F_45 ( struct V_2 * V_24 ,
struct V_40 * V_41 ,
const char * V_42 , T_2 V_45 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
int V_46 = F_41 ( V_42 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_54 )
V_5 -> V_14 -> V_54 ( V_5 , V_30 , V_46 ) ;
return V_45 ;
}
static T_1 F_46 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_55 )
V_5 -> V_14 -> V_55 ( V_5 , V_30 ) ;
return snprintf ( V_42 , 40 , L_6 , V_30 -> V_56 ) ;
}
static T_1 F_47 ( struct V_2 * V_24 ,
struct V_40 * V_41 ,
const char * V_42 , T_2 V_45 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_30 = F_31 ( V_24 ) ;
int V_46 = F_41 ( V_42 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_57 )
V_5 -> V_14 -> V_57 ( V_5 , V_30 , V_46 ) ;
return V_45 ;
}
static T_1 F_48 ( struct V_2 * V_24 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_15 * V_30 = F_31 ( V_24 ) ;
return snprintf ( V_42 , 40 , L_7 , V_58 [ V_30 -> type ] ) ;
}
static int T_3 F_49 ( void )
{
int V_17 ;
V_17 = F_50 ( & V_21 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_21 ) ;
}
