const T_1 *
F_1 ( const T_2 V_1 , const T_3 * V_2 , const char * V_3 )
{
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_3 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_5 ( const T_2 V_1 , const T_3 * V_2 ,
const char * V_5 )
{
const T_1 * V_4 ;
F_2 ( V_5 != NULL ) ;
V_4 = F_3 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return V_5 ;
}
const T_1 *
F_6 ( const T_2 V_1 , const T_3 * V_2 , T_4 * V_6 )
{
T_4 V_7 = 0 ;
F_2 ( V_6 != NULL ) ;
if( V_2 ) {
while ( V_2 [ V_7 ] . V_8 ) {
if ( V_2 [ V_7 ] . V_9 == V_1 ) {
* V_6 = V_7 ;
return ( V_2 [ V_7 ] . V_8 ) ;
}
V_7 ++ ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_3 ( const T_2 V_1 , const T_3 * V_2 )
{
T_4 V_10 ;
return F_6 ( V_1 , V_2 , & V_10 ) ;
}
const T_1 *
F_7 ( const T_5 V_1 , const T_6 * V_2 , const char * V_3 )
{
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_8 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_9 ( const T_5 V_1 , const T_6 * V_2 ,
const char * V_5 )
{
const T_1 * V_4 ;
F_2 ( V_5 != NULL ) ;
V_4 = F_8 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return V_5 ;
}
const T_1 *
F_10 ( const T_5 V_1 , const T_6 * V_2 , T_4 * V_6 )
{
T_4 V_7 = 0 ;
F_2 ( V_6 != NULL ) ;
if( V_2 ) {
while ( V_2 [ V_7 ] . V_8 ) {
if ( V_2 [ V_7 ] . V_9 == V_1 ) {
* V_6 = V_7 ;
return ( V_2 [ V_7 ] . V_8 ) ;
}
V_7 ++ ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_8 ( const T_5 V_1 , const T_6 * V_2 )
{
T_4 V_10 ;
return F_10 ( V_1 , V_2 , & V_10 ) ;
}
T_2
F_11 ( const T_1 * V_1 , const T_3 * V_2 , const T_2 V_11 )
{
T_4 V_7 ;
V_7 = F_12 ( V_1 , V_2 ) ;
if ( V_7 >= 0 ) {
return V_2 [ V_7 ] . V_9 ;
}
return V_11 ;
}
T_4
F_12 ( const T_1 * V_1 , const T_3 * V_2 )
{
T_4 V_7 = 0 ;
if( V_2 ) {
while ( V_2 [ V_7 ] . V_8 ) {
if ( strcmp ( V_2 [ V_7 ] . V_8 , V_1 ) == 0 ) {
return V_7 ;
}
V_7 ++ ;
}
}
return - 1 ;
}
const T_7 *
F_13 ( const T_3 * V_2 , T_8 V_12 ,
const T_1 * V_13 )
{
T_7 * V_14 ;
F_2 ( V_13 != NULL ) ;
F_2 ( V_12 > 0 ) ;
F_2 ( V_2 [ V_12 - 1 ] . V_8 == NULL ) ;
V_14 = F_14 ( F_15 () , T_7 ) ;
V_14 -> V_15 = V_2 ;
V_14 -> V_16 = V_12 - 1 ;
V_14 -> V_17 = 0 ;
V_14 -> V_18 = V_19 ;
V_14 -> V_20 = V_13 ;
return V_14 ;
}
void
F_16 ( const T_7 * V_14 )
{
F_17 ( F_15 () , ( void * ) V_14 ) ;
}
const T_1 *
F_18 ( const T_2 V_1 , const T_7 * V_14 )
{
if ( V_14 ) {
const T_3 * V_2 = V_14 -> V_18 ( V_1 , V_14 ) ;
if ( V_2 ) {
return V_2 -> V_8 ;
}
}
return NULL ;
}
const T_1 *
F_19 ( const T_2 V_1 , const T_7 * V_14 , T_4 * V_6 )
{
if ( V_14 ) {
const T_3 * V_2 = V_14 -> V_18 ( V_1 , V_14 ) ;
if ( V_2 ) {
* V_6 = ( T_4 ) ( V_2 - V_14 -> V_15 ) ;
return V_2 -> V_8 ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_20 ( const T_2 V_1 , const T_7 * V_14 , const char * V_3 )
{
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_18 ( V_1 , V_14 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_21 ( const T_2 V_1 , const T_7 * V_14 ,
const char * V_5 )
{
const T_1 * V_4 ;
F_2 ( V_5 != NULL ) ;
V_4 = F_18 ( V_1 , V_14 ) ;
if ( V_4 != NULL )
return V_4 ;
return V_5 ;
}
static const T_3 *
F_22 ( const T_2 V_1 , const T_7 * V_14 )
{
const T_3 * V_21 = V_14 -> V_15 ;
T_8 V_7 ;
for ( V_7 = 0 ; V_7 < V_14 -> V_16 ; V_7 ++ ) {
if ( V_21 [ V_7 ] . V_9 == V_1 )
return & ( V_21 [ V_7 ] ) ;
}
return NULL ;
}
static const T_3 *
F_23 ( const T_2 V_1 , const T_7 * V_14 )
{
T_8 V_7 ;
V_7 = V_1 - V_14 -> V_17 ;
if ( V_7 < V_14 -> V_16 ) {
F_24 ( V_1 == V_14 -> V_15 [ V_7 ] . V_9 ) ;
return & ( V_14 -> V_15 [ V_7 ] ) ;
}
return NULL ;
}
static const T_3 *
F_25 ( const T_2 V_1 , const T_7 * V_14 )
{
T_8 V_22 , V_7 , V_23 ;
T_2 V_24 ;
for ( V_22 = 0 , V_23 = V_14 -> V_16 ; V_22 < V_23 ; ) {
V_7 = ( V_22 + V_23 ) / 2 ;
V_24 = V_14 -> V_15 [ V_7 ] . V_9 ;
if ( V_1 < V_24 )
V_23 = V_7 ;
else if ( V_1 > V_24 )
V_22 = V_7 + 1 ;
else
return & ( V_14 -> V_15 [ V_7 ] ) ;
}
return NULL ;
}
const T_3 *
V_19 ( const T_2 V_1 , const T_7 * V_25 )
{
T_7 * V_14 = ( T_7 * ) V_25 ;
const T_3 * V_21 = V_14 -> V_15 ;
const T_8 V_26 = V_14 -> V_16 ;
enum { V_27 , V_28 , V_29 } type = V_29 ;
T_2 V_30 ;
T_8 V_31 ;
T_8 V_7 ;
F_2 ( ( V_21 [ V_26 ] . V_9 == 0 ) &&
( V_21 [ V_26 ] . V_8 == NULL ) ) ;
V_14 -> V_17 = V_21 [ 0 ] . V_9 ;
V_31 = V_21 [ 0 ] . V_9 ;
V_30 = V_31 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
F_2 ( V_21 [ V_7 ] . V_8 != NULL ) ;
if ( ( type == V_29 ) && ( V_21 [ V_7 ] . V_9 != ( V_7 + V_31 ) ) ) {
type = V_28 ;
}
if ( type == V_28 ) {
if ( V_30 > V_21 [ V_7 ] . V_9 ) {
F_26 ( L_1
L_2 ,
V_14 -> V_20 , V_7 , V_21 [ V_7 ] . V_9 , V_21 [ V_7 ] . V_9 , V_30 , V_30 ) ;
type = V_27 ;
break;
}
if ( V_31 > V_21 [ V_7 ] . V_9 ) {
F_26 ( L_1
L_3 ,
V_14 -> V_20 , V_7 , V_21 [ V_7 ] . V_9 , V_21 [ V_7 ] . V_9 , V_31 , V_31 ) ;
type = V_27 ;
break;
}
}
V_30 = V_21 [ V_7 ] . V_9 ;
}
switch ( type ) {
case V_27 :
V_14 -> V_18 = F_22 ;
break;
case V_28 :
V_14 -> V_18 = F_25 ;
break;
case V_29 :
V_14 -> V_18 = F_23 ;
break;
default:
F_27 () ;
break;
}
return V_14 -> V_18 ( V_1 , V_14 ) ;
}
const T_1 *
F_28 ( const T_1 * V_1 , const T_9 * V_2 , const char * V_3 )
{
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_29 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_30 ( const T_1 * V_1 , const T_9 * V_2 , T_4 * V_6 )
{
T_4 V_7 = 0 ;
if( V_2 ) {
while ( V_2 [ V_7 ] . V_8 ) {
if ( ! strcmp ( V_2 [ V_7 ] . V_9 , V_1 ) ) {
* V_6 = V_7 ;
return ( V_2 [ V_7 ] . V_8 ) ;
}
V_7 ++ ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_29 ( const T_1 * V_1 , const T_9 * V_2 )
{
T_4 V_10 ;
return F_30 ( V_1 , V_2 , & V_10 ) ;
}
const T_1 *
F_31 ( const T_2 V_1 , const T_10 * V_32 , const char * V_3 )
{
const T_1 * V_4 = NULL ;
F_2 ( V_3 != NULL ) ;
V_4 = F_32 ( V_1 , V_32 ) ;
if( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_33 ( const T_2 V_1 , const T_10 * V_32 ,
const char * V_5 )
{
const T_1 * V_4 = NULL ;
F_2 ( V_5 != NULL ) ;
V_4 = F_32 ( V_1 , V_32 ) ;
if( V_4 != NULL )
return V_4 ;
return V_5 ;
}
const T_1 *
F_34 ( const T_2 V_1 , const T_10 * V_32 , T_4 * V_6 )
{
T_4 V_7 = 0 ;
if( V_32 ) {
while( V_32 [ V_7 ] . V_8 ) {
if( ( V_1 >= V_32 [ V_7 ] . V_33 ) && ( V_1 <= V_32 [ V_7 ] . V_34 ) ) {
* V_6 = V_7 ;
return ( V_32 [ V_7 ] . V_8 ) ;
}
V_7 ++ ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_32 ( const T_2 V_1 , const T_10 * V_32 )
{
T_4 V_10 = 0 ;
return F_34 ( V_1 , V_32 , & V_10 ) ;
}
T_11
F_35 ( const T_7 * V_14 )
{
if ( V_14 == NULL )
return FALSE ;
#ifndef F_36
if ( ( V_14 -> V_18 != V_19 ) &&
( V_14 -> V_18 != F_22 ) &&
( V_14 -> V_18 != F_25 ) &&
( V_14 -> V_18 != F_23 ) )
return FALSE ;
#endif
return TRUE ;
}
const T_1 *
F_37 ( const T_7 * V_14 )
{
if ( V_14 -> V_18 == F_22 )
return L_4 ;
if ( V_14 -> V_18 == F_25 )
return L_5 ;
if ( V_14 -> V_18 == F_23 )
return L_6 ;
return L_7 ;
}
