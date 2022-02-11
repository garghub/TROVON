static struct V_1 * F_1 ( T_1 V_2 ,
bool V_3 )
{
T_2 V_4 ;
if ( V_2 == 0 )
return NULL ;
if ( V_5 . V_6 == NULL ) {
F_2 ( V_7 ,
L_1 ) ;
return NULL ;
}
for ( V_4 = 0 ; V_4 < V_5 . V_8 ; V_4 ++ ) {
if ( ( & V_5 . V_6 [ V_4 ] ) -> V_9 == 0 ) {
if ( V_3 ) {
return & V_5 . V_6 [ V_4 ] ;
}
}
if ( ( & V_5 . V_6 [ V_4 ] ) -> V_9 == V_2 ) {
return & V_5 . V_6 [ V_4 ] ;
}
}
return NULL ;
}
enum V_10 F_3 ( T_2 V_8 )
{
enum V_10 V_11 = V_12 ;
if ( V_8 == 0 ) {
F_2 ( V_13 ,
L_2 ) ;
return V_14 ;
}
if ( V_5 . V_6 != NULL ) {
F_2 ( V_13 ,
L_3 ) ;
return V_15 ;
}
V_5 . V_6 =
F_4 ( sizeof( struct V_1 ) * V_8 ) ;
if ( ! V_5 . V_6 )
V_11 = V_16 ;
if ( V_11 == V_12 ) {
memset ( V_5 . V_6 , 0 ,
sizeof( struct V_1 ) * V_8 ) ;
V_5 . V_8 = V_8 ;
}
return V_11 ;
}
void F_5 ( void )
{
struct V_1 * V_17 ;
T_2 V_4 ;
F_2 ( V_13 ,
L_4 ) ;
for ( V_4 = 0 ; V_4 < V_5 . V_8 ; V_4 ++ ) {
V_17 = V_5 . V_6 + V_4 ;
if ( V_17 -> V_9 != V_18 ) {
F_6 ( V_17 -> V_9 ) ;
V_17 -> V_9 = V_18 ;
V_17 -> V_19 = 0 ;
V_17 -> V_20 = 0 ;
}
}
F_7 ( V_5 . V_6 ) ;
V_5 . V_6 = NULL ;
V_5 . V_8 = 0 ;
F_2 ( V_13 ,
L_5 ) ;
}
T_1 F_8 ( T_3 V_20 , T_1 V_2 )
{
struct V_1 * V_17 ;
if ( V_2 == V_18 )
return V_2 ;
V_17 = F_1 ( V_2 , false ) ;
F_2 ( V_13 ,
L_6 , V_20 , V_2 ) ;
if ( ! V_17 ) {
V_17 = F_1 ( V_2 , true ) ;
assert ( V_17 != NULL ) ;
if ( V_17 == NULL )
return V_18 ;
V_17 -> V_20 = V_20 ;
}
if ( V_17 -> V_20 != V_20 ) {
F_2 ( V_7 ,
L_7 ) ;
return V_18 ;
}
if ( V_17 -> V_9 == V_2 )
V_17 -> V_19 += 1 ;
else if ( V_17 -> V_9 == V_18 ) {
V_17 -> V_9 = V_2 ;
V_17 -> V_19 = 1 ;
} else
return V_18 ;
return V_2 ;
}
bool F_9 ( T_3 V_20 , T_1 V_2 )
{
struct V_1 * V_17 ;
F_2 ( V_13 ,
L_8 , V_20 , V_2 ) ;
if ( V_2 == V_18 )
return false ;
V_17 = F_1 ( V_2 , false ) ;
if ( V_17 ) {
if ( V_17 -> V_20 != V_20 ) {
F_2 ( V_7 ,
L_9 ) ;
return false ;
}
if ( V_17 -> V_19 > 0 ) {
V_17 -> V_19 -= 1 ;
if ( V_17 -> V_19 == 0 ) {
F_6 ( V_2 ) ;
V_17 -> V_9 = V_18 ;
V_17 -> V_20 = 0 ;
}
return true ;
}
}
if ( V_17 )
F_10 ( L_10 ,
V_20 , V_2 , V_17 , V_17 -> V_20 , V_17 -> V_19 ) ;
else
F_10 ( L_11 ) ;
#ifdef F_11
assert ( false ) ;
#endif
return false ;
}
bool F_12 ( T_1 V_2 )
{
struct V_1 * V_17 ;
if ( V_2 == V_18 )
return false ;
V_17 = F_1 ( V_2 , false ) ;
if ( V_17 )
return ( V_17 -> V_19 == 1 ) ;
return true ;
}
void F_13 ( T_3 V_20 , T_4 V_21 )
{
struct V_1 * V_17 ;
T_2 V_4 ;
T_2 V_19 = 0 ;
assert ( V_21 != NULL ) ;
F_2 ( V_13 , L_12 ,
V_20 ) ;
for ( V_4 = 0 ; V_4 < V_5 . V_8 ; V_4 ++ ) {
V_17 = V_5 . V_6 + V_4 ;
if ( ( V_17 -> V_9 != V_18 ) && ( V_17 -> V_20 == V_20 ) ) {
F_2 ( V_13 ,
L_13
L_14 , V_20 , V_17 -> V_9 ) ;
if ( V_21 ) {
V_21 ( V_17 -> V_9 ) ;
} else {
F_2 ( V_13 ,
L_15
L_16
L_17 ) ;
F_6 ( V_17 -> V_9 ) ;
}
#ifndef F_11
#else
assert ( V_17 -> V_19 == 0 ) ;
#endif
if ( V_17 -> V_19 != 0 ) {
F_14 ( L_18 , V_17 -> V_20 ) ;
}
V_17 -> V_9 = V_18 ;
V_17 -> V_19 = 0 ;
V_17 -> V_20 = 0 ;
V_19 ++ ;
}
}
F_2 ( V_13 ,
L_19 , V_20 ,
V_19 ) ;
}
bool F_15 ( T_1 V_2 )
{
struct V_1 * V_17 ;
if ( V_2 == V_18 )
return false ;
V_17 = F_1 ( V_2 , false ) ;
return V_17 != NULL ;
}
