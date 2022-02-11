void F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( V_2 ) ) ;
}
void F_2 ( void )
{
memset ( & V_1 , 0 , sizeof( V_2 ) ) ;
}
bool F_3 (
T_1 V_3 ,
T_2 * V_4 )
{
bool V_5 = false ;
T_2 V_6 ;
T_2 V_7 ;
V_2 * V_8 = NULL ;
assert ( V_3 < V_9 ) ;
assert ( V_4 != NULL ) ;
V_7 = V_10 [ V_3 ] ;
V_8 = & V_1 [ V_3 ] ;
if ( V_8 -> V_11 < V_7 ) {
for ( V_6 = V_12 ; V_6 < V_13 ; V_6 ++ ) {
if ( F_4 ( V_8 -> V_14 , V_6 ) == 0 ) {
F_5 ( V_8 -> V_14 , V_6 ) ;
* V_4 = V_6 ;
V_8 -> V_11 ++ ;
V_5 = true ;
break;
}
}
}
return V_5 ;
}
void F_6 (
T_1 V_3 ,
T_2 * V_4 )
{
T_2 V_7 ;
V_2 * V_8 = NULL ;
assert ( V_3 < V_9 ) ;
assert ( V_4 != NULL ) ;
V_7 = V_10 [ V_3 ] ;
V_8 = & V_1 [ V_3 ] ;
if ( ( * V_4 < V_7 ) && ( V_8 -> V_11 > 0 ) ) {
if ( F_4 ( V_8 -> V_14 , * V_4 ) == 1 ) {
F_7 ( V_8 -> V_14 , * V_4 ) ;
V_8 -> V_11 -- ;
}
}
}
