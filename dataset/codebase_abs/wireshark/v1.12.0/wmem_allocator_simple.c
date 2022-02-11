static void *
F_1 ( void * V_1 , const T_1 V_2 )
{
T_2 * V_3 ;
V_3 = ( T_2 * ) V_1 ;
if G_UNLIKELY( V_3 -> V_4 == V_3 -> V_2 ) {
V_3 -> V_2 *= 2 ;
V_3 -> V_5 = ( void * * ) F_2 ( NULL , V_3 -> V_5 ,
sizeof( void * ) * V_3 -> V_2 ) ;
}
return V_3 -> V_5 [ V_3 -> V_4 ++ ] = F_3 ( NULL , V_2 ) ;
}
static void
F_4 ( void * V_1 , void * V_6 )
{
int V_7 ;
T_2 * V_3 ;
V_3 = ( T_2 * ) V_1 ;
F_5 ( NULL , V_6 ) ;
V_3 -> V_4 -- ;
for ( V_7 = V_3 -> V_4 ; V_7 >= 0 ; V_7 -- ) {
if ( V_6 == V_3 -> V_5 [ V_7 ] ) {
if ( V_7 < V_3 -> V_4 ) {
V_3 -> V_5 [ V_7 ] = V_3 -> V_5 [ V_3 -> V_4 ] ;
}
return;
}
}
F_6 () ;
}
static void *
F_7 ( void * V_1 , void * V_6 , const T_1 V_2 )
{
int V_7 ;
T_2 * V_3 ;
V_3 = ( T_2 * ) V_1 ;
for ( V_7 = V_3 -> V_4 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_6 == V_3 -> V_5 [ V_7 ] ) {
return V_3 -> V_5 [ V_7 ] = F_2 ( NULL , V_3 -> V_5 [ V_7 ] , V_2 ) ;
}
}
F_6 () ;
return NULL ;
}
static void
F_8 ( void * V_1 )
{
T_2 * V_3 ;
int V_7 ;
V_3 = ( T_2 * ) V_1 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_4 ; V_7 ++ ) {
F_5 ( NULL , V_3 -> V_5 [ V_7 ] ) ;
}
V_3 -> V_4 = 0 ;
}
static void
F_9 ( void * V_1 V_8 )
{
}
static void
F_10 ( void * V_1 )
{
T_2 * V_3 ;
V_3 = ( T_2 * ) V_1 ;
F_5 ( NULL , V_3 -> V_5 ) ;
F_5 ( NULL , V_3 ) ;
}
void
F_11 ( T_3 * V_3 )
{
T_2 * V_9 ;
V_9 = F_12 ( NULL , T_2 ) ;
V_3 -> V_10 = & F_1 ;
V_3 -> realloc = & F_7 ;
V_3 -> free = & F_4 ;
V_3 -> V_11 = & F_8 ;
V_3 -> V_12 = & F_9 ;
V_3 -> V_13 = & F_10 ;
V_3 -> V_1 = ( void * ) V_9 ;
V_9 -> V_4 = 0 ;
V_9 -> V_2 = V_14 ;
V_9 -> V_5 = F_13 ( NULL , void * , V_14 ) ;
}
