void F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
}
void F_2 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
}
bool F_3 (
T_1 V_2 ,
T_2 * V_3 )
{
bool V_4 = false ;
T_2 V_5 ;
T_3 * V_6 = NULL ;
T_2 V_7 ;
assert ( V_2 < V_8 ) ;
assert ( V_3 != NULL ) ;
if ( ( V_2 < V_8 ) && ( V_3 != NULL ) ) {
V_5 = V_9 [ V_2 ] ;
V_6 = & V_1 [ V_2 ] ;
if ( V_6 -> V_10 < V_5 ) {
for ( V_7 = V_11 ; V_7 < V_5 ; V_7 ++ ) {
if ( F_4 ( V_6 -> V_12 , V_7 ) == 0 ) {
F_5 ( V_6 -> V_12 , V_7 ) ;
* V_3 = V_7 ;
V_6 -> V_10 ++ ;
V_4 = true ;
break;
}
}
}
}
return V_4 ;
}
void F_6 (
T_1 V_2 ,
T_2 * V_3 )
{
T_2 V_5 ;
T_3 * V_6 = NULL ;
assert ( V_2 < V_8 ) ;
assert ( V_3 != NULL ) ;
if ( ( V_2 < V_8 ) && ( V_3 != NULL ) ) {
V_5 = V_9 [ V_2 ] ;
V_6 = & V_1 [ V_2 ] ;
if ( ( * V_3 < V_5 ) && ( V_6 -> V_10 > 0 ) ) {
if ( F_4 ( V_6 -> V_12 , * V_3 ) == 1 ) {
F_7 ( V_6 -> V_12 , * V_3 ) ;
V_6 -> V_10 -- ;
}
}
}
}
