static T_1 * F_1 ( T_2 V_1 )
{
T_1 * V_2 = NULL ;
if ( V_1 < V_3 )
V_2 = & V_4 . V_5 [ V_1 ] ;
return V_2 ;
}
void F_2 ( void )
{
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_6 = V_7 ;
}
void F_3 ( void )
{
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_6 = V_7 ;
}
bool F_4 (
T_3 V_8 ,
T_3 * V_9 )
{
bool V_10 = false ;
bool V_11 = false ;
T_3 V_12 ;
T_1 * V_2 = NULL ;
T_2 V_13 ;
assert ( V_9 != NULL ) ;
assert ( V_8 > 0 ) ;
V_12 = ( V_8 + ( V_14 - 1 ) ) & ~ ( V_14 - 1 ) ;
if ( V_4 . V_15 < V_4 . V_16 ) {
for ( V_13 = 0 ; V_13 < V_4 . V_16 ; V_13 ++ ) {
V_2 = F_1 ( V_13 ) ;
if ( ! V_2 -> V_17 ) {
if ( V_2 -> V_8 >= V_12 ) {
V_2 -> V_17 = true ;
V_11 = true ;
V_4 . V_15 ++ ;
break;
}
}
}
}
if ( ! V_11 ) {
if ( ( V_4 . V_16 < V_3 ) &&
( V_4 . V_6 >= V_12 ) ) {
V_2 = F_1 ( V_4 . V_16 ) ;
V_2 -> V_9 = V_4 . V_18 ;
V_2 -> V_8 = V_12 ;
V_2 -> V_17 = true ;
V_4 . V_18 += V_12 ;
V_4 . V_6 -= V_12 ;
V_4 . V_15 ++ ;
V_4 . V_16 ++ ;
V_11 = true ;
}
}
if ( V_11 && V_2 ) {
* V_9 = V_2 -> V_9 ;
V_10 = true ;
}
return V_10 ;
}
void F_5 (
T_3 * V_9 )
{
T_2 V_13 ;
T_1 * V_2 = NULL ;
assert ( V_9 != NULL ) ;
for ( V_13 = 0 ; V_13 < V_4 . V_16 ; V_13 ++ ) {
V_2 = F_1 ( V_13 ) ;
if ( V_2 -> V_17 && V_2 -> V_9 == * V_9 ) {
V_2 -> V_17 = false ;
V_4 . V_15 -- ;
break;
}
}
}
