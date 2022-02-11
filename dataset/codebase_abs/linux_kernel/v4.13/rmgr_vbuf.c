static void F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
}
void F_2 ( struct V_2 * * V_3 )
{
int V_4 ;
struct V_2 * V_5 ;
if ( ( V_3 == NULL ) || ( * V_3 == NULL ) ) {
F_3 ( L_1 ) ;
return;
}
if ( ( * V_3 ) -> V_6 == 0 ) {
V_5 = * V_3 ;
* V_3 = NULL ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( V_1 [ V_4 ] . V_6 == 0 ) {
* V_3 = & V_1 [ V_4 ] ;
break;
}
}
if ( * V_3 == NULL ) {
F_4 ( V_8 ,
L_2 ) ;
return;
}
( * V_3 ) -> V_9 = V_5 -> V_9 ;
( * V_3 ) -> V_10 = V_5 -> V_10 ;
}
( * V_3 ) -> V_6 ++ ;
}
void F_5 ( struct V_2 * * V_3 )
{
if ( ( V_3 == NULL ) || ( ( * V_3 ) == NULL ) || ( ( ( * V_3 ) -> V_6 ) == 0 ) ) {
F_4 ( V_8 ,
L_3 ) ;
return;
}
( * V_3 ) -> V_6 -- ;
if ( ( * V_3 ) -> V_6 == 0 ) {
( * V_3 ) -> V_9 = 0x0 ;
( * V_3 ) -> V_10 = 0 ;
* V_3 = NULL ;
}
}
enum V_11 F_6 ( struct V_12 * V_13 )
{
enum V_11 V_14 = V_15 ;
T_1 V_16 ;
F_1 () ;
assert ( V_13 != NULL ) ;
if ( V_13 == NULL )
return V_17 ;
if ( V_13 -> V_18 && V_13 -> V_10 ) {
V_16 =
sizeof( void * ) *
V_13 -> V_10 ;
V_13 -> V_19 = F_7 ( V_16 ) ;
if ( V_13 -> V_19 != NULL )
memset ( V_13 -> V_19 , 0 , V_16 ) ;
else
V_14 = V_20 ;
} else {
V_13 -> V_10 = 0 ;
V_13 -> V_19 = NULL ;
}
return V_14 ;
}
void F_8 ( struct V_12 * V_13 )
{
T_2 V_4 ;
F_4 ( V_21 , L_4 ) ;
if ( V_13 == NULL ) {
F_4 ( V_8 , L_5 ) ;
return;
}
if ( V_13 -> V_19 != NULL ) {
for ( V_4 = 0 ; V_4 < V_13 -> V_10 ; V_4 ++ ) {
if ( V_13 -> V_19 [ V_4 ] != NULL ) {
F_4 ( V_21 ,
L_6 ,
V_13 -> V_19 [ V_4 ] -> V_9 ,
V_13 -> V_19 [ V_4 ] -> V_6 ) ;
F_9 ( V_13 -> V_19 [ V_4 ] -> V_9 ) ;
F_5 (
& V_13 -> V_19 [ V_4 ] ) ;
}
}
F_10 ( V_13 -> V_19 ) ;
V_13 -> V_19 = NULL ;
}
}
static
void F_11 ( struct V_12 * V_13 ,
struct V_2 * * V_3 )
{
T_2 V_4 ;
bool V_22 = false ;
assert ( V_13 != NULL ) ;
assert ( V_13 -> V_18 ) ;
assert ( V_13 -> V_19 != NULL ) ;
assert ( V_3 != NULL ) ;
for ( V_4 = 0 ; V_4 < V_13 -> V_10 ; V_4 ++ ) {
if ( V_13 -> V_19 [ V_4 ] == NULL ) {
F_2 ( V_3 ) ;
V_13 -> V_19 [ V_4 ] = * V_3 ;
V_22 = true ;
break;
}
}
assert ( V_22 ) ;
}
static
void F_12 ( struct V_12 * V_13 ,
struct V_2 * * V_3 )
{
T_2 V_4 ;
bool V_22 = false ;
assert ( V_13 != NULL ) ;
assert ( V_13 -> V_18 ) ;
assert ( V_13 -> V_19 != NULL ) ;
assert ( V_3 != NULL ) ;
assert ( * V_3 != NULL ) ;
for ( V_4 = 0 ; V_4 < V_13 -> V_10 ; V_4 ++ ) {
if ( ( V_13 -> V_19 [ V_4 ] != NULL ) &&
( V_13 -> V_19 [ V_4 ] -> V_10 == ( * V_3 ) -> V_10 ) ) {
* V_3 = V_13 -> V_19 [ V_4 ] ;
V_13 -> V_19 [ V_4 ] = NULL ;
V_22 = true ;
break;
}
}
}
void F_13 ( struct V_12 * V_13 ,
struct V_2 * * V_3 )
{
struct V_2 V_5 ;
if ( ( V_13 == NULL ) || ( V_3 == NULL ) || ( * V_3 == NULL ) ) {
F_3 ( L_1 ) ;
return;
}
if ( V_13 -> V_23 ) {
if ( ( * V_3 ) -> V_6 == 1 )
return;
if ( ( * V_3 ) -> V_6 > 1 ) {
V_5 . V_9 = 0x0 ;
V_5 . V_10 = ( * V_3 ) -> V_10 ;
F_5 ( V_3 ) ;
* V_3 = & V_5 ;
}
if ( ( * V_3 ) -> V_9 == 0x0 ) {
if ( V_13 -> V_18 ) {
F_12 ( V_13 , V_3 ) ;
}
if ( ( * V_3 ) -> V_9 == 0x0 ) {
( * V_3 ) -> V_9 = F_14 ( ( * V_3 ) -> V_10 ) ;
} else {
return;
}
}
}
F_2 ( V_3 ) ;
}
void F_15 ( struct V_12 * V_13 ,
struct V_2 * * V_3 )
{
if ( ( V_13 == NULL ) || ( V_3 == NULL ) || ( * V_3 == NULL ) ) {
F_3 ( L_1 ) ;
return;
}
if ( ( * V_3 ) -> V_6 == 1 ) {
if ( ! V_13 -> V_18 ) {
F_9 ( ( * V_3 ) -> V_9 ) ;
} else {
F_11 ( V_13 , V_3 ) ;
}
}
F_5 ( V_3 ) ;
* V_3 = NULL ;
}
