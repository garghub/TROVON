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
T_2 V_3 ,
T_3 * V_4 )
{
bool V_5 = false ;
T_4 V_6 ;
T_4 V_7 ;
T_5 * V_8 = NULL ;
T_6 V_9 ;
assert ( V_2 < V_10 ) ;
assert ( ( V_3 == V_11 ) || ( V_3 == V_12 ) ) ;
assert ( V_4 != NULL ) ;
if ( ( V_2 < V_10 ) && ( V_4 != NULL ) ) {
V_8 = & V_1 [ V_2 ] ;
if ( V_3 == V_11 ) {
V_6 = V_13 [ V_2 ] ;
V_7 = V_8 -> V_14 ;
} else {
V_6 = V_15 [ V_2 ] ;
V_7 = V_8 -> V_16 ;
}
if ( V_7 < V_6 ) {
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ ) {
if ( F_4 ( V_8 -> V_17 , V_9 ) == 0 ) {
F_5 ( V_8 -> V_17 , V_9 ) ;
if ( V_3 == V_11 ) {
V_4 -> V_18 = V_9 ;
V_4 -> V_19 = 0 ;
V_8 -> V_14 ++ ;
} else {
V_4 -> V_18 = 0 ;
V_4 -> V_19 = V_9 ;
V_8 -> V_16 ++ ;
}
V_8 -> V_20 ++ ;
V_5 = true ;
break;
}
}
}
}
return V_5 ;
}
void F_6 (
T_1 V_2 ,
T_2 V_3 ,
T_3 * V_4 )
{
T_4 V_21 ;
T_5 * V_8 = NULL ;
T_4 V_22 = 0 ;
assert ( V_2 < V_10 ) ;
assert ( V_4 != NULL ) ;
assert ( ( V_3 >= V_11 ) || ( V_3 <= V_12 ) ) ;
if ( ( V_2 < V_10 ) && ( V_4 != NULL ) ) {
if ( V_3 == V_11 ) {
V_21 = V_13 [ V_2 ] ;
V_22 = V_4 -> V_18 ;
} else {
V_21 = V_15 [ V_2 ] ;
V_22 = V_4 -> V_19 ;
}
V_8 = & V_1 [ V_2 ] ;
if ( ( V_22 < V_21 ) && ( V_8 -> V_20 > 0 ) ) {
if ( F_4 ( V_8 -> V_17 , V_22 ) == 1 ) {
F_7 ( V_8 -> V_17 , V_22 ) ;
if ( V_3 == V_11 )
V_8 -> V_14 -- ;
else
V_8 -> V_16 -- ;
V_8 -> V_20 -- ;
}
}
}
}
enum V_23 F_8 (
enum V_24 V_25 ,
T_4 V_26 )
{
enum V_23 V_5 = V_27 ;
if ( ( V_25 < V_28 ) &&
( V_26 < V_29 ) ) {
struct V_30 * V_31 ;
V_31 = F_9 () ;
if ( F_4 ( V_31 -> V_32 [ V_25 ] , V_26 ) == 0 ) {
F_5 ( V_31 -> V_32 [ V_25 ] , V_26 ) ;
V_31 -> V_33 [ V_25 ] = 0 ;
V_5 = V_34 ;
}
}
return V_5 ;
}
enum V_23 F_10 (
enum V_24 V_25 ,
T_4 V_26 )
{
enum V_23 V_5 = V_27 ;
if ( ( V_25 < V_28 ) &&
( V_26 < V_29 ) ) {
struct V_30 * V_31 ;
V_31 = F_9 () ;
if ( F_4 ( V_31 -> V_32 [ V_25 ] , V_26 ) == 1 ) {
F_7 ( V_31 -> V_32 [ V_25 ] , V_26 ) ;
V_5 = V_34 ;
}
}
return V_5 ;
}
