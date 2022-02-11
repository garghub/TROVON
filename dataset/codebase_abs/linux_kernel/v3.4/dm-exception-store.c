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
unsigned long V_17 ;
char * V_18 ;
V_17 = F_20 ( V_16 , & V_18 , 10 ) ;
if ( * V_16 == '\0' || * V_18 != '\0' ||
V_17 > V_19 ) {
* error = L_4 ;
return - V_13 ;
}
if ( ! V_17 ) {
V_15 -> V_20 = V_15 -> V_21 = V_15 -> V_22 = 0 ;
return 0 ;
}
return F_21 ( V_15 ,
( unsigned ) V_17 ,
error ) ;
}
int F_21 ( struct V_14 * V_15 ,
unsigned V_20 ,
char * * error )
{
if ( ! F_22 ( V_20 ) ) {
* error = L_5 ;
return - V_13 ;
}
if ( V_20 %
( F_23 ( F_24 ( V_15 -> V_23 ) -> V_24 ) >> 9 ) ||
V_20 %
( F_23 ( F_25 ( V_15 -> V_23 ) -> V_24 ) >> 9 ) ) {
* error = L_6 ;
return - V_13 ;
}
if ( V_20 > V_25 >> V_26 ) {
* error = L_7 ;
return - V_13 ;
}
V_15 -> V_20 = V_20 ;
V_15 -> V_21 = V_20 - 1 ;
V_15 -> V_22 = F_26 ( V_20 ) - 1 ;
return 0 ;
}
int F_27 ( struct V_27 * V_28 , int V_29 , char * * V_30 ,
struct V_31 * V_23 ,
unsigned * V_32 ,
struct V_14 * * V_15 )
{
int V_9 = 0 ;
struct V_1 * type = NULL ;
struct V_14 * V_33 ;
char V_34 ;
if ( V_29 < 2 ) {
V_28 -> error = L_8 ;
return - V_13 ;
}
V_33 = F_28 ( sizeof( * V_33 ) , V_8 ) ;
if ( ! V_33 ) {
V_28 -> error = L_9 ;
return - V_35 ;
}
V_34 = toupper ( * V_30 [ 0 ] ) ;
if ( V_34 == 'P' )
type = F_7 ( L_10 ) ;
else if ( V_34 == 'N' )
type = F_7 ( L_11 ) ;
else {
V_28 -> error = L_12 ;
V_9 = - V_13 ;
goto V_36;
}
if ( ! type ) {
V_28 -> error = L_13 ;
V_9 = - V_13 ;
goto V_36;
}
V_33 -> type = type ;
V_33 -> V_23 = V_23 ;
V_9 = F_19 ( V_33 , V_30 [ 1 ] , & V_28 -> error ) ;
if ( V_9 )
goto V_37;
V_9 = type -> V_38 ( V_33 , 0 , NULL ) ;
if ( V_9 ) {
V_28 -> error = L_14 ;
goto V_37;
}
* V_32 = 2 ;
* V_15 = V_33 ;
return 0 ;
V_37:
F_13 ( type ) ;
V_36:
F_12 ( V_33 ) ;
return V_9 ;
}
void F_29 ( struct V_14 * V_15 )
{
V_15 -> type -> V_39 ( V_15 ) ;
F_13 ( V_15 -> type ) ;
F_12 ( V_15 ) ;
}
int F_30 ( void )
{
int V_9 ;
V_9 = F_31 () ;
if ( V_9 ) {
F_9 ( L_15 ) ;
goto V_40;
}
V_9 = F_32 () ;
if ( V_9 ) {
F_9 ( L_16 ) ;
goto V_41;
}
return 0 ;
V_41:
F_33 () ;
V_40:
return V_9 ;
}
void F_34 ( void )
{
F_35 () ;
F_33 () ;
}
