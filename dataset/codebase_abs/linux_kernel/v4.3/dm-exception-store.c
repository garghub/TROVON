static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * type ;
F_2 (type, &_exception_store_types, list)
if ( ! strcmp ( V_2 , type -> V_2 ) )
return type ;
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * type ;
F_4 ( & V_3 ) ;
type = F_1 ( V_2 ) ;
if ( type && ! F_5 ( type -> V_4 ) )
type = NULL ;
F_6 ( & V_3 ) ;
return type ;
}
static struct V_1 * F_7 ( const char * V_5 )
{
char * V_6 , * V_7 ;
struct V_1 * type ;
type = F_3 ( V_5 ) ;
if ( type )
return type ;
V_7 = F_8 ( V_5 , V_8 ) ;
if ( ! V_7 ) {
F_9 ( L_1 , V_5 ) ;
return NULL ;
}
while ( F_10 ( L_2 , V_7 ) ||
! ( type = F_3 ( V_5 ) ) ) {
V_6 = strrchr ( V_7 , '-' ) ;
if ( ! V_6 )
break;
V_6 [ 0 ] = '\0' ;
}
if ( ! type )
F_11 ( L_3 , V_5 ) ;
F_12 ( V_7 ) ;
return type ;
}
static void F_13 ( struct V_1 * type )
{
F_4 ( & V_3 ) ;
F_14 ( type -> V_4 ) ;
F_6 ( & V_3 ) ;
}
int F_15 ( struct V_1 * type )
{
int V_9 = 0 ;
F_4 ( & V_3 ) ;
if ( ! F_1 ( type -> V_2 ) )
F_16 ( & type -> V_10 , & V_11 ) ;
else
V_9 = - V_12 ;
F_6 ( & V_3 ) ;
return V_9 ;
}
int F_17 ( struct V_1 * type )
{
F_4 ( & V_3 ) ;
if ( ! F_1 ( type -> V_2 ) ) {
F_6 ( & V_3 ) ;
return - V_13 ;
}
F_18 ( & type -> V_10 ) ;
F_6 ( & V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 ,
const char * V_16 , char * * error )
{
unsigned V_17 ;
if ( F_20 ( V_16 , 10 , & V_17 ) ) {
* error = L_4 ;
return - V_13 ;
}
if ( ! V_17 ) {
V_15 -> V_17 = V_15 -> V_18 = V_15 -> V_19 = 0 ;
return 0 ;
}
return F_21 ( V_15 , V_17 , error ) ;
}
int F_21 ( struct V_14 * V_15 ,
unsigned V_17 ,
char * * error )
{
if ( ! F_22 ( V_17 ) ) {
* error = L_5 ;
return - V_13 ;
}
if ( V_17 %
( F_23 ( F_24 ( V_15 -> V_20 ) -> V_21 ) >> 9 ) ||
V_17 %
( F_23 ( F_25 ( V_15 -> V_20 ) -> V_21 ) >> 9 ) ) {
* error = L_6 ;
return - V_13 ;
}
if ( V_17 > V_22 >> V_23 ) {
* error = L_7 ;
return - V_13 ;
}
V_15 -> V_17 = V_17 ;
V_15 -> V_18 = V_17 - 1 ;
V_15 -> V_19 = F_26 ( V_17 ) - 1 ;
return 0 ;
}
int F_27 ( struct V_24 * V_25 , int V_26 , char * * V_27 ,
struct V_28 * V_20 ,
unsigned * V_29 ,
struct V_14 * * V_15 )
{
int V_9 = 0 ;
struct V_1 * type = NULL ;
struct V_14 * V_30 ;
char V_31 ;
if ( V_26 < 2 ) {
V_25 -> error = L_8 ;
return - V_13 ;
}
V_30 = F_28 ( sizeof( * V_30 ) , V_8 ) ;
if ( ! V_30 ) {
V_25 -> error = L_9 ;
return - V_32 ;
}
V_31 = toupper ( * V_27 [ 0 ] ) ;
if ( V_31 == 'P' )
type = F_7 ( L_10 ) ;
else if ( V_31 == 'N' )
type = F_7 ( L_11 ) ;
else {
V_25 -> error = L_12 ;
V_9 = - V_13 ;
goto V_33;
}
if ( ! type ) {
V_25 -> error = L_13 ;
V_9 = - V_13 ;
goto V_33;
}
V_30 -> type = type ;
V_30 -> V_20 = V_20 ;
V_9 = F_19 ( V_30 , V_27 [ 1 ] , & V_25 -> error ) ;
if ( V_9 )
goto V_34;
V_9 = type -> V_35 ( V_30 , ( strlen ( V_27 [ 0 ] ) > 1 ? & V_27 [ 0 ] [ 1 ] : NULL ) ) ;
if ( V_9 ) {
V_25 -> error = L_14 ;
goto V_34;
}
* V_29 = 2 ;
* V_15 = V_30 ;
return 0 ;
V_34:
F_13 ( type ) ;
V_33:
F_12 ( V_30 ) ;
return V_9 ;
}
void F_29 ( struct V_14 * V_15 )
{
V_15 -> type -> V_36 ( V_15 ) ;
F_13 ( V_15 -> type ) ;
F_12 ( V_15 ) ;
}
int F_30 ( void )
{
int V_9 ;
V_9 = F_31 () ;
if ( V_9 ) {
F_9 ( L_15 ) ;
goto V_37;
}
V_9 = F_32 () ;
if ( V_9 ) {
F_9 ( L_16 ) ;
goto V_38;
}
return 0 ;
V_38:
F_33 () ;
V_37:
return V_9 ;
}
void F_34 ( void )
{
F_35 () ;
F_33 () ;
}
