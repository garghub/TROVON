T_1 F_1 ( T_2 * V_1 , T_1 V_2 )
{
T_1 V_3 = V_1 -> V_4 ;
if ( V_1 -> V_4 != V_2 )
V_1 -> V_5 = 0 ;
V_1 -> V_4 = V_2 ;
return V_3 ;
}
T_2 * F_2 ( const T_2 * V_1 )
{
T_2 * V_6 ;
if ( ( V_6 = F_3 ( sizeof( * V_6 ) ) ) == NULL )
return NULL ;
* V_6 = * V_1 ;
if ( ( V_6 -> V_7 = F_3 ( sizeof( * V_6 -> V_7 ) * V_1 -> V_8 ) ) == NULL )
goto V_9;
memcpy ( V_6 -> V_7 , V_1 -> V_7 , sizeof( char * ) * V_1 -> V_10 ) ;
return V_6 ;
V_9:
F_4 ( V_6 ) ;
return NULL ;
}
T_2 * F_5 ( const T_2 * V_1 ,
T_3 V_11 ,
T_4 V_12 )
{
T_2 * V_6 ;
int V_13 ;
if ( ( V_6 = F_3 ( sizeof( * V_6 ) ) ) == NULL )
return NULL ;
* V_6 = * V_1 ;
V_6 -> V_8 = V_1 -> V_10 > V_14 ? V_1 -> V_10 : V_14 ;
V_6 -> V_7 = F_6 ( sizeof( * V_6 -> V_7 ) * V_6 -> V_8 ) ;
if ( V_6 -> V_7 == NULL ) {
F_7 ( V_6 ) ;
return NULL ;
}
for ( V_13 = 0 ; V_13 < V_6 -> V_10 ; ++ V_13 ) {
if ( V_1 -> V_7 [ V_13 ] == NULL )
continue;
if ( ( V_6 -> V_7 [ V_13 ] = V_11 ( V_1 -> V_7 [ V_13 ] ) ) == NULL ) {
while ( -- V_13 >= 0 )
if ( V_6 -> V_7 [ V_13 ] != NULL )
V_12 ( ( void * ) V_6 -> V_7 [ V_13 ] ) ;
F_4 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_2 * F_8 ( void )
{
return F_9 ( ( T_1 ) NULL ) ;
}
T_2 * F_9 ( T_1 V_2 )
{
T_2 * V_6 ;
if ( ( V_6 = F_6 ( sizeof( * V_6 ) ) ) == NULL )
goto V_9;
if ( ( V_6 -> V_7 = F_6 ( sizeof( * V_6 -> V_7 ) * V_14 ) ) == NULL )
goto V_9;
V_6 -> V_4 = V_2 ;
V_6 -> V_8 = V_14 ;
return ( V_6 ) ;
V_9:
F_7 ( V_6 ) ;
return ( NULL ) ;
}
int F_10 ( T_2 * V_15 , const void * V_7 , int V_16 )
{
const char * * V_17 ;
if ( V_15 == NULL )
return 0 ;
if ( V_15 -> V_8 <= V_15 -> V_10 + 1 ) {
V_17 = F_11 ( ( char * ) V_15 -> V_7 ,
( unsigned int ) sizeof( char * ) * V_15 -> V_8 * 2 ) ;
if ( V_17 == NULL )
return ( 0 ) ;
V_15 -> V_7 = V_17 ;
V_15 -> V_8 *= 2 ;
}
if ( ( V_16 >= ( int ) V_15 -> V_10 ) || ( V_16 < 0 ) )
V_15 -> V_7 [ V_15 -> V_10 ] = V_7 ;
else {
memmove ( & V_15 -> V_7 [ V_16 + 1 ] , & V_15 -> V_7 [ V_16 ] ,
sizeof( V_15 -> V_7 [ 0 ] ) * ( V_15 -> V_10 - V_16 ) ) ;
V_15 -> V_7 [ V_16 ] = V_7 ;
}
V_15 -> V_10 ++ ;
V_15 -> V_5 = 0 ;
return ( V_15 -> V_10 ) ;
}
void * F_12 ( T_2 * V_15 , const void * V_18 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_15 -> V_10 ; V_13 ++ )
if ( V_15 -> V_7 [ V_13 ] == V_18 )
return F_13 ( V_15 , V_13 ) ;
return NULL ;
}
void * F_13 ( T_2 * V_15 , int V_16 )
{
const char * V_6 ;
if ( V_15 == NULL || V_16 < 0 || V_16 >= V_15 -> V_10 )
return NULL ;
V_6 = V_15 -> V_7 [ V_16 ] ;
if ( V_16 != V_15 -> V_10 - 1 )
memmove ( & V_15 -> V_7 [ V_16 ] , & V_15 -> V_7 [ V_16 + 1 ] ,
sizeof( V_15 -> V_7 [ 0 ] ) * ( V_15 -> V_10 - V_16 - 1 ) ) ;
V_15 -> V_10 -- ;
return ( void * ) V_6 ;
}
static int F_14 ( T_2 * V_15 , const void * V_7 ,
int V_19 )
{
const void * V_20 ;
int V_13 ;
if ( V_15 == NULL )
return - 1 ;
if ( V_15 -> V_4 == NULL ) {
for ( V_13 = 0 ; V_13 < V_15 -> V_10 ; V_13 ++ )
if ( V_15 -> V_7 [ V_13 ] == V_7 )
return ( V_13 ) ;
return ( - 1 ) ;
}
F_15 ( V_15 ) ;
if ( V_7 == NULL )
return ( - 1 ) ;
V_20 = F_16 ( & V_7 , V_15 -> V_7 , V_15 -> V_10 , sizeof( void * ) , V_15 -> V_4 ,
V_19 ) ;
if ( V_20 == NULL )
return ( - 1 ) ;
return ( int ) ( ( const char * * ) V_20 - V_15 -> V_7 ) ;
}
int F_17 ( T_2 * V_15 , const void * V_7 )
{
return F_14 ( V_15 , V_7 , V_21 ) ;
}
int F_18 ( T_2 * V_15 , const void * V_7 )
{
return F_14 ( V_15 , V_7 , V_22 ) ;
}
int F_19 ( T_2 * V_15 , const void * V_7 )
{
return ( F_10 ( V_15 , V_7 , V_15 -> V_10 ) ) ;
}
int F_20 ( T_2 * V_15 , const void * V_7 )
{
return ( F_10 ( V_15 , V_7 , 0 ) ) ;
}
void * F_21 ( T_2 * V_15 )
{
if ( V_15 == NULL )
return ( NULL ) ;
if ( V_15 -> V_10 <= 0 )
return ( NULL ) ;
return ( F_13 ( V_15 , 0 ) ) ;
}
void * F_22 ( T_2 * V_15 )
{
if ( V_15 == NULL )
return ( NULL ) ;
if ( V_15 -> V_10 <= 0 )
return ( NULL ) ;
return ( F_13 ( V_15 , V_15 -> V_10 - 1 ) ) ;
}
void F_23 ( T_2 * V_15 )
{
if ( V_15 == NULL )
return;
if ( V_15 -> V_10 <= 0 )
return;
memset ( V_15 -> V_7 , 0 , sizeof( * V_15 -> V_7 ) * V_15 -> V_10 ) ;
V_15 -> V_10 = 0 ;
}
void F_24 ( T_2 * V_15 , T_4 V_23 )
{
int V_13 ;
if ( V_15 == NULL )
return;
for ( V_13 = 0 ; V_13 < V_15 -> V_10 ; V_13 ++ )
if ( V_15 -> V_7 [ V_13 ] != NULL )
V_23 ( ( char * ) V_15 -> V_7 [ V_13 ] ) ;
F_4 ( V_15 ) ;
}
void F_4 ( T_2 * V_15 )
{
if ( V_15 == NULL )
return;
F_7 ( V_15 -> V_7 ) ;
F_7 ( V_15 ) ;
}
int F_25 ( const T_2 * V_15 )
{
if ( V_15 == NULL )
return - 1 ;
return V_15 -> V_10 ;
}
void * F_26 ( const T_2 * V_15 , int V_13 )
{
if ( V_15 == NULL || V_13 < 0 || V_13 >= V_15 -> V_10 )
return NULL ;
return ( void * ) V_15 -> V_7 [ V_13 ] ;
}
void * F_27 ( T_2 * V_15 , int V_13 , const void * V_7 )
{
if ( V_15 == NULL || V_13 < 0 || V_13 >= V_15 -> V_10 )
return NULL ;
V_15 -> V_7 [ V_13 ] = V_7 ;
return ( void * ) V_15 -> V_7 [ V_13 ] ;
}
void F_15 ( T_2 * V_15 )
{
if ( V_15 && ! V_15 -> V_5 && V_15 -> V_4 != NULL ) {
qsort ( V_15 -> V_7 , V_15 -> V_10 , sizeof( char * ) , V_15 -> V_4 ) ;
V_15 -> V_5 = 1 ;
}
}
int F_28 ( const T_2 * V_15 )
{
if ( V_15 == NULL )
return 1 ;
return V_15 -> V_5 ;
}
