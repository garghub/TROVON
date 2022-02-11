int F_1 ( T_1 * V_1 , T_2 * V_2 , T_2 * V_3 )
{
T_2 * V_4 = NULL ;
F_2 ( T_2 ) * V_5 ;
V_5 = ( F_2 ( T_2 ) * ) V_2 -> V_3 ;
V_3 -> V_2 = V_2 -> V_2 ;
if ( ! F_3 ( V_5 , V_3 ) ) {
return 0 ;
}
V_4 = F_4 ( V_1 -> V_6 , V_3 ) ;
if ( V_4 != NULL ) {
( void ) F_5 ( V_5 , V_4 ) ;
F_6 ( V_4 -> V_7 ) ;
F_6 ( V_4 -> V_3 ) ;
F_6 ( V_4 ) ;
}
return 1 ;
}
char * F_7 ( const T_1 * V_1 , const char * V_2 ,
const char * V_7 )
{
T_2 * V_4 , V_8 ;
char * V_9 ;
if ( V_7 == NULL )
return ( NULL ) ;
if ( V_1 != NULL ) {
if ( V_2 != NULL ) {
V_8 . V_7 = ( char * ) V_7 ;
V_8 . V_2 = ( char * ) V_2 ;
V_4 = F_8 ( V_1 -> V_6 , & V_8 ) ;
if ( V_4 != NULL )
return ( V_4 -> V_3 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 ) {
V_9 = getenv ( V_7 ) ;
if ( V_9 != NULL )
return ( V_9 ) ;
}
}
V_8 . V_2 = L_2 ;
V_8 . V_7 = ( char * ) V_7 ;
V_4 = F_8 ( V_1 -> V_6 , & V_8 ) ;
if ( V_4 != NULL )
return ( V_4 -> V_3 ) ;
else
return ( NULL ) ;
} else
return ( getenv ( V_7 ) ) ;
}
static unsigned long F_9 ( const T_2 * V_4 )
{
return ( F_10 ( V_4 -> V_2 ) << 2 ) ^ F_10 ( V_4 -> V_7 ) ;
}
int F_11 ( T_1 * V_1 )
{
if ( V_1 == NULL ) {
return 0 ;
}
if ( V_1 -> V_6 == NULL )
if ( ( V_1 -> V_6 = F_12 () ) == NULL ) {
return 0 ;
}
return 1 ;
}
void F_13 ( T_1 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_6 == NULL )
return;
F_14 ( V_1 -> V_6 ) = 0 ;
F_15 ( V_1 -> V_6 ,
F_16 ( V_10 ) ,
F_17 ( T_2 ) , V_1 -> V_6 ) ;
F_18 ( V_1 -> V_6 , F_19 ( V_11 ) ) ;
F_20 ( V_1 -> V_6 ) ;
}
static void F_21 ( T_2 * V_12 )
{
T_2 * V_8 ;
F_2 ( T_2 ) * V_13 ;
int V_14 ;
if ( V_12 -> V_7 != NULL )
return;
V_13 = ( F_2 ( T_2 ) * ) V_12 -> V_3 ;
for ( V_14 = F_22 ( V_13 ) - 1 ; V_14 >= 0 ; V_14 -- ) {
V_8 = F_23 ( V_13 , V_14 ) ;
F_6 ( V_8 -> V_3 ) ;
F_6 ( V_8 -> V_7 ) ;
F_6 ( V_8 ) ;
}
if ( V_13 != NULL )
F_24 ( V_13 ) ;
F_6 ( V_12 -> V_2 ) ;
F_6 ( V_12 ) ;
}
T_2 * F_25 ( T_1 * V_1 , const char * V_2 )
{
F_2 ( T_2 ) * V_13 = NULL ;
int V_15 = 0 , V_14 ;
T_2 * V_4 = NULL , * V_8 ;
if ( ( V_13 = F_26 () ) == NULL )
goto V_16;
if ( ( V_4 = F_27 ( sizeof( T_2 ) ) ) == NULL )
goto V_16;
V_14 = strlen ( V_2 ) + 1 ;
if ( ( V_4 -> V_2 = F_27 ( V_14 ) ) == NULL )
goto V_16;
memcpy ( V_4 -> V_2 , V_2 , V_14 ) ;
V_4 -> V_7 = NULL ;
V_4 -> V_3 = ( char * ) V_13 ;
V_8 = F_4 ( V_1 -> V_6 , V_4 ) ;
F_28 ( V_8 == NULL ) ;
V_15 = 1 ;
V_16:
if ( ! V_15 ) {
if ( V_13 != NULL )
F_24 ( V_13 ) ;
if ( V_4 != NULL )
F_6 ( V_4 ) ;
V_4 = NULL ;
}
return ( V_4 ) ;
}
