static struct V_1 *
F_1 ( const char * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
if ( V_4 == NULL )
F_3 ( L_1 , V_2 ) ;
return V_4 ;
}
static struct V_1 *
F_4 ( const char * V_2 , struct V_1 * V_3 ,
const struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_4 = F_5 ( V_2 , 0 , V_3 ,
V_7 , V_8 ) ;
if ( V_4 == NULL )
F_3 ( L_2 , V_2 ) ;
return V_4 ;
}
static int F_6 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_7 ( V_10 , V_11 , F_8 ( V_9 ) ) ;
}
T_1 * F_9 ( struct V_1 * V_12 ,
const char * * V_2 ,
const char * * V_13 ,
void (* F_10)( struct V_14 * ,
void * , int ) )
{
int V_15 = 0 ;
T_1 * V_16 = NULL , * type = NULL ;
struct V_1 * V_3 = NULL ;
if ( V_12 == NULL ) {
F_3 ( L_3 ) ;
goto V_17;
}
if ( V_2 == NULL || V_2 [ 0 ] == NULL ) {
F_3 ( L_4 ) ;
goto V_17;
}
type = F_11 ( sizeof( T_1 ) , V_18 | V_19 ) ;
if ( type == NULL ) {
F_3 ( L_5 ) ;
goto V_17;
}
type -> V_2 = V_2 ;
type -> V_13 = V_13 ;
type -> V_20 = 0 ;
type -> V_21 = 0 ;
type -> F_10 = F_10 ;
type -> V_12 = V_12 ;
if ( type -> V_13 != NULL )
while ( type -> V_13 [ type -> V_20 ] != NULL )
type -> V_20 ++ ;
while ( type -> V_2 [ type -> V_21 ] != NULL )
type -> V_21 ++ ;
type -> V_22 = F_11 ( ( type -> V_21 + 1 ) *
sizeof( struct V_1 * ) ,
V_18 | V_19 ) ;
if ( type -> V_22 == NULL ) {
F_3 ( L_5 ) ;
goto V_17;
}
V_3 = V_12 ;
for ( V_15 = 0 ; V_15 < type -> V_21 ; V_15 ++ ) {
type -> V_22 [ V_15 ] = F_1 ( type -> V_2 [ V_15 ] , V_3 ) ;
if ( type -> V_22 [ V_15 ] == NULL ) {
V_16 = NULL ;
goto V_17;
}
V_3 = type -> V_22 [ V_15 ] ;
}
type -> V_23 = type -> V_22 [ type -> V_21 - 1 ] ;
V_16 = type ;
V_17:
if ( V_16 == NULL ) {
if ( type != NULL ) {
F_12 ( type ) ;
type = NULL ;
}
}
return V_16 ;
}
void F_12 ( T_1 * type )
{
if ( type == NULL )
return;
if ( type -> V_22 != NULL ) {
int V_15 = type -> V_21 - 1 ;
while ( V_15 >= 0 ) {
if ( type -> V_22 [ V_15 ] != NULL ) {
struct V_1 * V_3 = NULL ;
if ( V_15 == 0 )
V_3 = type -> V_12 ;
else
V_3 = type -> V_22 [ V_15 - 1 ] ;
F_13 ( type -> V_2 [ V_15 ] , V_3 ) ;
}
V_15 -- ;
}
F_14 ( type -> V_22 ) ;
type -> V_22 = NULL ;
}
F_14 ( type ) ;
}
T_2 * F_15 ( T_1 * type ,
const char * V_2 , void * V_24 )
{
T_2 * V_25 = NULL , * V_16 = NULL ;
int V_15 = 0 ;
if ( type == NULL ) {
F_3 ( L_6 ) ;
goto V_17;
}
V_25 = F_11 ( sizeof( T_2 ) , V_18 | V_19 ) ;
if ( V_25 == NULL ) {
F_3 ( L_5 ) ;
goto V_17;
}
V_25 -> type = type ;
V_25 -> V_24 = V_24 ;
if ( V_2 == NULL ) {
V_25 -> V_2 = NULL ;
V_25 -> V_23 = type -> V_23 ;
} else {
V_25 -> V_26 = strlen ( V_2 ) + 1 ;
V_25 -> V_2 = F_16 ( V_25 -> V_26 , V_18 | V_19 ) ;
if ( V_25 -> V_2 == NULL ) {
V_25 -> V_26 = 0 ;
F_3 ( L_5 ) ;
goto V_17;
}
strcpy ( V_25 -> V_2 , V_2 ) ;
V_25 -> V_23 = F_1 ( V_25 -> V_2 , type -> V_23 ) ;
if ( V_25 -> V_23 == NULL )
goto V_17;
}
V_25 -> V_27 =
F_11 ( ( type -> V_20 + 1 ) *
sizeof( struct V_28 ) ,
V_18 | V_19 ) ;
if ( V_25 -> V_27 == NULL ) {
F_3 ( L_5 ) ;
goto V_17;
}
V_25 -> V_29 = F_11 ( ( type -> V_20 + 1 ) *
sizeof( struct V_1 * ) ,
V_18 | V_19 ) ;
if ( V_25 -> V_29 == NULL ) {
F_3 ( L_5 ) ;
goto V_17;
}
for ( V_15 = 0 ; V_15 < type -> V_20 ; V_15 ++ ) {
V_25 -> V_27 [ V_15 ] . V_30 = V_25 ;
V_25 -> V_27 [ V_15 ] . V_31 = V_15 ;
V_25 -> V_27 [ V_15 ] . F_10 =
type -> F_10 ;
if ( type -> V_13 [ V_15 ] [ 0 ] != '\0' ) {
V_25 -> V_29 [ V_15 ] =
F_4 ( type -> V_13 [ V_15 ] ,
V_25 -> V_23 , & V_32 ,
& V_25 -> V_27 [ V_15 ] ) ;
if ( V_25 -> V_29 [ V_15 ] == NULL ) {
V_16 = NULL ;
goto V_17;
}
}
}
V_16 = V_25 ;
V_17:
if ( V_16 == NULL ) {
if ( V_25 != NULL ) {
F_17 ( V_25 ) ;
V_25 = NULL ;
}
}
return V_16 ;
}
void F_17 ( T_2 * V_25 )
{
T_1 * type = NULL ;
if ( V_25 == NULL )
return;
type = V_25 -> type ;
if ( type == NULL )
return;
if ( V_25 -> V_29 != NULL ) {
int V_15 = 0 ;
for ( V_15 = 0 ; V_15 < type -> V_20 ; V_15 ++ ) {
if ( V_25 -> V_29 [ V_15 ] != NULL ) {
F_13 ( type -> V_13 [ V_15 ] ,
V_25 -> V_23 ) ;
V_25 -> V_29 [ V_15 ] = NULL ;
}
}
F_14 ( V_25 -> V_29 ) ;
V_25 -> V_29 = NULL ;
}
F_14 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
if ( V_25 -> V_23 != NULL ) {
if ( V_25 -> V_2 != NULL )
F_13 ( V_25 -> V_2 , type -> V_23 ) ;
V_25 -> V_23 = NULL ;
}
F_14 ( V_25 -> V_2 ) ;
V_25 -> V_2 = NULL ;
F_14 ( V_25 ) ;
}
static int V_11 ( struct V_14 * V_33 , void * V_34 )
{
struct V_28 * V_35 = V_33 -> V_36 ;
if ( V_35 == NULL ) {
F_3 ( L_7 ) ;
return 0 ;
}
(* V_35 -> F_10 )( V_33 , V_35 -> V_30 -> V_24 ,
V_35 -> V_31 ) ;
return 0 ;
}
