const T_1 *
F_1 ( const T_2 V_1 , const T_3 * V_2 , const char * V_3 ) {
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_3 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_5 ( const T_2 V_1 , const T_3 * V_2 , const char * V_5 ) {
const T_1 * V_4 ;
F_2 ( V_5 != NULL ) ;
V_4 = F_3 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return V_5 ;
}
const T_1 *
F_6 ( const T_2 V_1 , const T_3 * V_2 , T_4 * V_6 ) {
T_4 V_7 = 0 ;
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
F_3 ( const T_2 V_1 , const T_3 * V_2 ) {
T_4 V_10 ;
return F_6 ( V_1 , V_2 , & V_10 ) ;
}
T_5 *
F_7 ( T_3 * V_2 , T_6 V_11 , T_1 * V_12 ) {
T_5 * V_13 ;
F_2 ( V_12 != NULL ) ;
F_2 ( V_11 > 0 ) ;
F_2 ( V_2 [ V_11 - 1 ] . V_8 == NULL ) ;
V_13 = F_8 ( sizeof ( T_5 ) ) ;
V_13 -> V_14 = V_2 ;
V_13 -> V_15 = V_11 - 1 ;
V_13 -> V_16 = 0 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 = V_12 ;
return V_13 ;
}
const T_1 *
F_9 ( const T_2 V_1 , const T_5 * V_13 ) {
if ( V_13 ) {
const T_3 * V_2 = V_13 -> V_17 ( V_1 , V_13 ) ;
if ( V_2 )
return V_2 -> V_8 ;
}
return NULL ;
}
const T_1 *
F_10 ( const T_2 V_1 , T_5 * V_13 , T_4 * V_6 ) {
if ( V_13 ) {
const T_3 * V_2 = V_13 -> V_17 ( V_1 , V_13 ) ;
if ( V_2 ) {
* V_6 = ( T_4 ) ( V_2 - V_13 -> V_14 ) ;
return V_2 -> V_8 ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 *
F_11 ( const T_2 V_1 , const T_5 * V_13 , const char * V_3 ) {
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_9 ( V_1 , V_13 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_12 ( const T_2 V_1 , const T_5 * V_13 , const char * V_5 ) {
const T_1 * V_4 ;
F_2 ( V_5 != NULL ) ;
V_4 = F_9 ( V_1 , V_13 ) ;
if ( V_4 != NULL )
return V_4 ;
return V_5 ;
}
static const T_3 *
F_13 ( const T_2 V_1 , const T_5 * V_13 )
{
const T_3 * V_20 = V_13 -> V_14 ;
T_6 V_7 ;
for ( V_7 = 0 ; V_7 < V_13 -> V_15 ; V_7 ++ ) {
if ( V_20 [ V_7 ] . V_9 == V_1 )
return & ( V_20 [ V_7 ] ) ;
}
return NULL ;
}
static const T_3 *
F_14 ( const T_2 V_1 , const T_5 * V_13 )
{
T_6 V_7 ;
V_7 = V_1 - V_13 -> V_16 ;
if ( V_7 < V_13 -> V_15 ) {
F_2 ( V_1 == V_13 -> V_14 [ V_7 ] . V_9 ) ;
return & ( V_13 -> V_14 [ V_7 ] ) ;
}
return NULL ;
}
static const T_3 *
F_15 ( const T_2 V_1 , const T_5 * V_13 )
{
T_6 V_21 , V_7 , V_22 ;
T_2 V_23 ;
for ( V_21 = 0 , V_22 = V_13 -> V_15 ; V_21 < V_22 ; ) {
V_7 = ( V_21 + V_22 ) / 2 ;
V_23 = V_13 -> V_14 [ V_7 ] . V_9 ;
if ( V_1 < V_23 )
V_22 = V_7 ;
else if ( V_1 > V_23 )
V_21 = V_7 + 1 ;
else
return & ( V_13 -> V_14 [ V_7 ] ) ;
}
return NULL ;
}
const T_3 *
V_18 ( const T_2 V_1 , const T_5 * V_24 )
{
T_5 * V_13 = ( T_5 * ) V_24 ;
const T_3 * V_20 = V_13 -> V_14 ;
const T_6 V_25 = V_13 -> V_15 ;
enum { V_26 = 0 , V_27 , V_28 } type = V_28 ;
T_2 V_29 ;
T_6 V_30 ;
T_6 V_7 ;
F_2 ( ( V_20 [ V_25 ] . V_9 == 0 ) && ( V_20 [ V_25 ] . V_8 == NULL ) ) ;
V_13 -> V_16 = V_20 [ 0 ] . V_9 ;
V_30 = V_20 [ 0 ] . V_9 ;
V_29 = V_30 ;
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ ) {
F_2 ( V_20 [ V_7 ] . V_8 != NULL ) ;
if ( ( type == V_28 ) && ( V_20 [ V_7 ] . V_9 != ( V_7 + V_30 ) ) ) {
type = V_27 ;
}
if ( ( type == V_27 ) && ( V_29 > V_20 [ V_7 ] . V_9 ) ) {
type = V_26 ;
break;
}
V_29 = V_20 [ V_7 ] . V_9 ;
}
switch ( type ) {
case V_26 :
V_13 -> V_17 = F_13 ;
break;
case V_27 :
V_13 -> V_17 = F_15 ;
break;
case V_28 :
V_13 -> V_17 = F_14 ;
break;
default:
F_16 () ;
break;
}
return V_13 -> V_17 ( V_1 , V_13 ) ;
}
T_7
F_17 ( const T_5 * V_13 ) {
if ( V_13 == NULL )
return FALSE ;
if ( ( V_13 -> V_17 == V_18 ) ||
( V_13 -> V_17 == F_13 ) ||
( V_13 -> V_17 == F_15 ) ||
( V_13 -> V_17 == F_14 ) )
return TRUE ;
return FALSE ;
}
const T_1 *
F_18 ( const T_5 * V_13 ) {
if ( V_13 -> V_17 == F_13 )
return L_1 ;
if ( V_13 -> V_17 == F_15 )
return L_2 ;
if ( V_13 -> V_17 == F_14 )
return L_3 ;
return L_4 ;
}
const T_1 *
F_19 ( const T_1 * V_1 , const T_8 * V_2 , const char * V_3 ) {
const T_1 * V_4 ;
F_2 ( V_3 != NULL ) ;
V_4 = F_20 ( V_1 , V_2 ) ;
if ( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 *
F_21 ( const T_1 * V_1 , const T_8 * V_2 , T_4 * V_6 ) {
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
F_20 ( const T_1 * V_1 , const T_8 * V_2 ) {
T_4 V_10 ;
return F_21 ( V_1 , V_2 , & V_10 ) ;
}
const char *
F_22 ( const T_2 V_1 , const T_2 V_31 , const int V_32 ,
const T_3 * V_33 , const char * V_3 )
{
static char V_34 [ 1025 ] ;
char * V_35 ;
V_35 = F_23 ( V_34 , V_1 , V_31 , V_32 ) ;
F_24 ( V_35 , ( V_36 ) ( 1024 - ( V_35 - V_34 ) ) , V_3 , F_1 ( V_1 & V_31 , V_33 , L_5 ) ) ;
return V_34 ;
}
const char *
F_25 ( const T_2 V_1 , const T_2 V_31 , const int V_32 ,
const T_3 * V_33 , const char * V_3 )
{
static char V_34 [ 1025 ] ;
char * V_35 ;
int V_37 = 0 ;
while ( ( V_31 & ( 1 << V_37 ) ) == 0 )
V_37 ++ ;
V_35 = F_23 ( V_34 , V_1 , V_31 , V_32 ) ;
F_24 ( V_35 , ( V_36 ) ( 1024 - ( V_35 - V_34 ) ) , V_3 , F_1 ( ( V_1 & V_31 ) >> V_37 , V_33 , L_5 ) ) ;
return V_34 ;
}
const T_1 * F_26 ( const T_2 V_1 , const T_9 * V_38 , const char * V_3 )
{
const T_1 * V_4 = NULL ;
F_2 ( V_3 != NULL ) ;
V_4 = F_27 ( V_1 , V_38 ) ;
if( V_4 != NULL )
return V_4 ;
return F_4 ( V_3 , V_1 ) ;
}
const T_1 * F_28 ( const T_2 V_1 , const T_9 * V_38 , T_4 * V_6 )
{
T_4 V_7 = 0 ;
if( V_38 ) {
while( V_38 [ V_7 ] . V_8 ) {
if( ( V_1 >= V_38 [ V_7 ] . V_39 ) && ( V_1 <= V_38 [ V_7 ] . V_40 ) ) {
* V_6 = V_7 ;
return ( V_38 [ V_7 ] . V_8 ) ;
}
V_7 ++ ;
}
}
* V_6 = - 1 ;
return NULL ;
}
const T_1 * F_27 ( const T_2 V_1 , const T_9 * V_38 )
{
T_4 V_10 = 0 ;
return F_28 ( V_1 , V_38 , & V_10 ) ;
}
