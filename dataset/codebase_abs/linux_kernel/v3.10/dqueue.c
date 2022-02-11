int
F_1 ( T_1 * V_1 ,
int V_2 , int V_3 )
{
int V_4 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_5 = V_3 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_5 ; V_4 ++ ) {
V_1 -> V_6 [ V_4 ] = NULL ;
V_1 -> V_7 [ V_4 ] = 0 ;
}
V_1 -> V_8 = V_1 -> V_9 = V_1 -> V_10 = V_1 -> V_11 = 0 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_5 ; V_4 ++ ) {
if ( ! ( V_1 -> V_6 [ V_4 ] = F_2 ( 0 , V_1 -> V_2 ) ) ) {
F_3 ( V_1 ) ;
return ( - 1 ) ;
}
}
return ( 0 ) ;
}
int F_3 ( T_1 * V_1 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_5 ; V_4 ++ ) {
if ( V_1 -> V_6 [ V_4 ] ) {
F_4 ( 0 , V_1 -> V_6 [ V_4 ] ) ;
}
V_1 -> V_6 [ V_4 ] = NULL ;
V_1 -> V_7 [ V_4 ] = 0 ;
}
V_1 -> V_8 = V_1 -> V_9 = V_1 -> V_10 = V_1 -> V_11 = 0 ;
return ( 0 ) ;
}
int F_5 ( const T_1 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
void * F_6 ( T_1 * V_1 )
{
if ( ( ! V_1 -> V_11 ) && ( V_1 -> V_10 < V_1 -> V_5 ) ) {
V_1 -> V_11 = 1 ;
return ( V_1 -> V_6 [ V_1 -> V_9 ] ) ;
}
return NULL ;
}
void
F_7 ( T_1 * V_1 , int V_7 )
{
if ( V_1 -> V_11 ) {
V_1 -> V_7 [ V_1 -> V_9 ] = V_7 ;
V_1 -> V_10 ++ ;
V_1 -> V_9 ++ ;
if ( V_1 -> V_9 >= V_1 -> V_5 ) {
V_1 -> V_9 = 0 ;
}
V_1 -> V_11 = 0 ;
}
}
const void * F_8 ( const T_1 *
V_1 )
{
if ( V_1 -> V_10 ) {
return ( V_1 -> V_6 [ V_1 -> V_8 ] ) ;
}
return NULL ;
}
int F_9 ( const T_1 * V_1 )
{
return ( V_1 -> V_7 [ V_1 -> V_8 ] ) ;
}
void F_10 ( T_1 * V_1 )
{
if ( V_1 -> V_10 ) {
V_1 -> V_7 [ V_1 -> V_8 ] = 0 ;
V_1 -> V_10 -- ;
V_1 -> V_8 ++ ;
if ( V_1 -> V_8 >= V_1 -> V_5 ) {
V_1 -> V_8 = 0 ;
}
}
}
