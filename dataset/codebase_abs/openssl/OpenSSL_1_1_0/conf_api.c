T_1 * F_1 ( const T_2 * V_1 , const char * V_2 )
{
T_1 * V_3 , V_4 ;
if ( ( V_1 == NULL ) || ( V_2 == NULL ) )
return ( NULL ) ;
V_4 . V_5 = NULL ;
V_4 . V_2 = ( char * ) V_2 ;
V_3 = F_2 ( V_1 -> V_6 , & V_4 ) ;
return ( V_3 ) ;
}
int F_3 ( T_2 * V_1 , T_1 * V_2 , T_1 * V_7 )
{
T_1 * V_3 = NULL ;
F_4 ( T_1 ) * V_8 ;
V_8 = ( F_4 ( T_1 ) * ) V_2 -> V_7 ;
V_7 -> V_2 = V_2 -> V_2 ;
if ( ! F_5 ( V_8 , V_7 ) ) {
return 0 ;
}
V_3 = F_6 ( V_1 -> V_6 , V_7 ) ;
if ( V_3 != NULL ) {
( void ) F_7 ( V_8 , V_3 ) ;
F_8 ( V_3 -> V_5 ) ;
F_8 ( V_3 -> V_7 ) ;
F_8 ( V_3 ) ;
}
return 1 ;
}
char * F_9 ( const T_2 * V_1 , const char * V_2 ,
const char * V_5 )
{
T_1 * V_3 , V_4 ;
char * V_9 ;
if ( V_5 == NULL )
return ( NULL ) ;
if ( V_1 != NULL ) {
if ( V_2 != NULL ) {
V_4 . V_5 = ( char * ) V_5 ;
V_4 . V_2 = ( char * ) V_2 ;
V_3 = F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL )
return ( V_3 -> V_7 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 ) {
V_9 = getenv ( V_5 ) ;
if ( V_9 != NULL )
return ( V_9 ) ;
}
}
V_4 . V_2 = L_2 ;
V_4 . V_5 = ( char * ) V_5 ;
V_3 = F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL )
return ( V_3 -> V_7 ) ;
else
return ( NULL ) ;
} else
return ( getenv ( V_5 ) ) ;
}
static unsigned long F_10 ( const T_1 * V_3 )
{
return ( F_11 ( V_3 -> V_2 ) << 2 ) ^ F_11 ( V_3 -> V_5 ) ;
}
static int F_12 ( const T_1 * V_10 , const T_1 * V_11 )
{
int V_12 ;
if ( V_10 -> V_2 != V_11 -> V_2 ) {
V_12 = strcmp ( V_10 -> V_2 , V_11 -> V_2 ) ;
if ( V_12 )
return ( V_12 ) ;
}
if ( ( V_10 -> V_5 != NULL ) && ( V_11 -> V_5 != NULL ) ) {
V_12 = strcmp ( V_10 -> V_5 , V_11 -> V_5 ) ;
return ( V_12 ) ;
} else if ( V_10 -> V_5 == V_11 -> V_5 )
return ( 0 ) ;
else
return ( ( V_10 -> V_5 == NULL ) ? - 1 : 1 ) ;
}
int F_13 ( T_2 * V_1 )
{
if ( V_1 == NULL ) {
return 0 ;
}
if ( V_1 -> V_6 == NULL ) {
V_1 -> V_6 = F_14 ( F_10 , F_12 ) ;
if ( V_1 -> V_6 == NULL )
return 0 ;
}
return 1 ;
}
void F_15 ( T_2 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_6 == NULL )
return;
F_16 ( V_1 -> V_6 , 0 ) ;
F_17 ( V_1 -> V_6 , V_13 , V_1 -> V_6 ) ;
F_18 ( V_1 -> V_6 , V_14 ) ;
F_19 ( V_1 -> V_6 ) ;
}
static void V_14 ( T_1 * V_10 )
{
T_1 * V_4 ;
F_4 ( T_1 ) * V_15 ;
int V_12 ;
if ( V_10 -> V_5 != NULL )
return;
V_15 = ( F_4 ( T_1 ) * ) V_10 -> V_7 ;
for ( V_12 = F_20 ( V_15 ) - 1 ; V_12 >= 0 ; V_12 -- ) {
V_4 = F_21 ( V_15 , V_12 ) ;
F_8 ( V_4 -> V_7 ) ;
F_8 ( V_4 -> V_5 ) ;
F_8 ( V_4 ) ;
}
F_22 ( V_15 ) ;
F_8 ( V_10 -> V_2 ) ;
F_8 ( V_10 ) ;
}
T_1 * F_23 ( T_2 * V_1 , const char * V_2 )
{
F_4 ( T_1 ) * V_15 = NULL ;
int V_12 ;
T_1 * V_3 = NULL , * V_4 ;
if ( ( V_15 = F_24 () ) == NULL )
goto V_16;
if ( ( V_3 = F_25 ( sizeof( * V_3 ) ) ) == NULL )
goto V_16;
V_12 = strlen ( V_2 ) + 1 ;
if ( ( V_3 -> V_2 = F_25 ( V_12 ) ) == NULL )
goto V_16;
memcpy ( V_3 -> V_2 , V_2 , V_12 ) ;
V_3 -> V_5 = NULL ;
V_3 -> V_7 = ( char * ) V_15 ;
V_4 = F_6 ( V_1 -> V_6 , V_3 ) ;
F_26 ( V_4 == NULL ) ;
return V_3 ;
V_16:
F_22 ( V_15 ) ;
F_8 ( V_3 ) ;
return NULL ;
}
