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
struct V_15 *
F_32 ( struct V_1 * V_5 ,
unsigned int V_23 ,
enum V_28 type ,
const char * V_11 )
{
struct V_15 * V_29 ;
struct V_2 * V_24 ;
int V_17 ;
if ( V_23 >= V_5 -> V_12 )
return F_14 ( - V_30 ) ;
V_29 = & V_5 -> V_22 [ V_23 ] ;
if ( V_29 -> V_23 != - 1 )
return F_14 ( - V_30 ) ;
V_29 -> type = type ;
V_29 -> V_23 = V_23 ;
V_24 = & V_29 -> V_24 ;
V_24 -> V_9 = F_6 ( & V_5 -> V_5 ) ;
if ( V_11 && V_11 [ 0 ] )
F_15 ( V_24 , L_1 , V_11 ) ;
else
F_15 ( V_24 , L_4 , V_23 ) ;
V_24 -> V_31 = F_30 ;
V_24 -> V_32 = V_33 ;
V_17 = F_16 ( V_24 ) ;
if ( V_17 ) {
V_29 -> V_23 = - 1 ;
F_4 ( V_24 ) ;
return F_14 ( V_17 ) ;
}
return V_29 ;
}
int F_33 ( struct V_1 * V_5 , int V_22 ,
struct V_2 * V_3 )
{
struct V_15 * V_24 ;
if ( ! V_5 || V_22 >= V_5 -> V_12 )
return - V_30 ;
V_24 = & V_5 -> V_22 [ V_22 ] ;
if ( V_24 -> V_3 == V_3 )
return - V_34 ;
if ( V_24 -> V_3 )
F_24 ( V_24 ) ;
F_4 ( V_24 -> V_3 ) ;
V_24 -> V_3 = F_6 ( V_3 ) ;
return F_26 ( V_24 ) ;
}
int F_34 ( struct V_1 * V_5 , struct V_2 * V_3 )
{
struct V_15 * V_24 ;
int V_18 ;
if ( ! V_5 || ! V_3 )
return - V_30 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_24 = & V_5 -> V_22 [ V_18 ] ;
if ( V_24 -> V_3 == V_3 ) {
F_24 ( V_24 ) ;
F_35 ( & V_24 -> V_24 ) ;
F_4 ( V_3 ) ;
V_24 -> V_3 = NULL ;
return F_36 ( & V_24 -> V_24 ) ;
}
}
return - V_35 ;
}
static T_1 F_37 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_5 = F_29 ( V_24 ) ;
return snprintf ( V_38 , 40 , L_5 , V_5 -> V_12 ) ;
}
static T_1 F_38 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_39 )
V_5 -> V_14 -> V_39 ( V_5 , V_29 ) ;
return snprintf ( V_38 , 40 , L_5 , V_29 -> V_40 ) ;
}
static T_1 F_39 ( struct V_2 * V_24 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_41 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
int V_42 = F_40 ( V_38 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_43 )
V_5 -> V_14 -> V_43 ( V_5 , V_29 , V_42 ) ;
return V_41 ;
}
static T_1 F_41 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_44 )
V_5 -> V_14 -> V_44 ( V_5 , V_29 ) ;
return snprintf ( V_38 , 40 , L_6 , V_45 [ V_29 -> V_46 ] ) ;
}
static T_1 F_42 ( struct V_2 * V_24 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_41 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
int V_18 ;
for ( V_18 = 0 ; V_45 [ V_18 ] ; V_18 ++ ) {
if ( strncmp ( V_38 , V_45 [ V_18 ] ,
strlen ( V_45 [ V_18 ] ) ) == 0 &&
( V_38 [ strlen ( V_45 [ V_18 ] ) ] == '\n' ||
V_38 [ strlen ( V_45 [ V_18 ] ) ] == '\0' ) )
break;
}
if ( V_45 [ V_18 ] && V_5 -> V_14 -> V_47 ) {
V_5 -> V_14 -> V_47 ( V_5 , V_29 , V_18 ) ;
return V_41 ;
} else
return - V_30 ;
}
static T_1 F_43 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_48 )
V_5 -> V_14 -> V_48 ( V_5 , V_29 ) ;
return snprintf ( V_38 , 40 , L_5 , V_29 -> V_49 ) ;
}
static T_1 F_44 ( struct V_2 * V_24 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_41 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
int V_42 = F_40 ( V_38 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_50 )
V_5 -> V_14 -> V_50 ( V_5 , V_29 , V_42 ) ;
return V_41 ;
}
static T_1 F_45 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
if ( V_5 -> V_14 -> V_51 )
V_5 -> V_14 -> V_51 ( V_5 , V_29 ) ;
return snprintf ( V_38 , 40 , L_5 , V_29 -> V_52 ) ;
}
static T_1 F_46 ( struct V_2 * V_24 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_41 )
{
struct V_1 * V_5 = F_29 ( V_24 -> V_9 ) ;
struct V_15 * V_29 = F_31 ( V_24 ) ;
int V_42 = F_40 ( V_38 , NULL , 0 ) ;
if ( V_5 -> V_14 -> V_53 )
V_5 -> V_14 -> V_53 ( V_5 , V_29 , V_42 ) ;
return V_41 ;
}
static T_1 F_47 ( struct V_2 * V_24 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_15 * V_29 = F_31 ( V_24 ) ;
return snprintf ( V_38 , 40 , L_6 , V_54 [ V_29 -> type ] ) ;
}
static int T_3 F_48 ( void )
{
int V_17 ;
V_17 = F_49 ( & V_21 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_21 ) ;
}
