T_1 *
F_1 ( T_2 * V_1 , const T_1 * V_2 )
{
T_3 V_3 ;
if( ! V_2 ) {
V_2 = L_1 ;
}
V_3 = strlen ( V_2 ) + 1 ;
return ( T_1 * ) memcpy ( F_2 ( V_1 , V_3 ) , V_2 , V_3 ) ;
}
T_1 *
F_3 ( T_2 * V_1 , const T_1 * V_2 , const T_3 V_3 )
{
T_1 * V_4 ;
T_4 V_5 ;
V_4 = ( T_1 * ) F_2 ( V_1 , V_3 + 1 ) ;
for ( V_5 = 0 ; ( V_5 < V_3 ) && V_2 [ V_5 ] ; V_5 ++ ) {
V_4 [ V_5 ] = V_2 [ V_5 ] ;
}
V_4 [ V_5 ] = '\0' ;
return V_4 ;
}
T_1 *
F_4 ( T_2 * V_1 , const T_1 * V_6 , ... )
{
T_5 V_7 ;
T_1 * V_4 ;
va_start ( V_7 , V_6 ) ;
V_4 = F_5 ( V_1 , V_6 , V_7 ) ;
va_end ( V_7 ) ;
return V_4 ;
}
T_1 *
F_5 ( T_2 * V_1 , const T_1 * V_6 , T_5 V_7 )
{
T_5 V_8 ;
T_6 V_3 ;
T_1 * V_4 ;
F_6 ( V_8 , V_7 ) ;
V_3 = F_7 ( V_6 , V_7 ) ;
V_4 = ( T_1 * ) F_2 ( V_1 , V_3 + 1 ) ;
F_8 ( V_4 , ( V_9 ) V_3 , V_6 , V_8 ) ;
va_end ( V_8 ) ;
return V_4 ;
}
T_1 *
F_9 ( T_2 * V_1 , const T_1 * V_10 , ... )
{
T_6 V_3 ;
T_5 args ;
T_1 * V_11 ;
T_1 * V_12 ;
T_1 * V_13 ;
if ( ! V_10 )
return NULL ;
V_3 = 1 + strlen ( V_10 ) ;
va_start ( args , V_10 ) ;
while ( ( V_11 = va_arg ( args , T_1 * ) ) ) {
V_3 += strlen ( V_11 ) ;
}
va_end ( args ) ;
V_13 = V_12 = ( T_1 * ) F_2 ( V_1 , V_3 ) ;
V_13 = F_10 ( V_13 , V_10 ) ;
va_start ( args , V_10 ) ;
while ( ( V_11 = va_arg ( args , T_1 * ) ) ) {
V_13 = F_10 ( V_13 , V_11 ) ;
}
va_end ( args ) ;
return V_12 ;
}
T_1 * *
F_11 ( T_2 * V_1 , const T_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
T_1 * V_16 ;
T_1 * V_11 ;
T_4 V_17 ;
T_4 V_18 ;
T_4 V_19 ;
T_4 V_5 ;
T_1 * * V_20 ;
enum { V_21 , V_22 , V_23 } V_24 ;
T_4 V_25 = 0 ;
if ( ! V_2
|| ! V_14
|| ! V_14 [ 0 ] )
return NULL ;
V_11 = V_16 = F_1 ( V_1 , V_2 ) ;
V_18 = ( T_4 ) strlen ( V_16 ) ;
V_19 = ( T_4 ) strlen ( V_14 ) ;
if ( V_15 < 1 ) V_15 = V_26 ;
V_17 = 1 ;
while ( V_17 <= ( T_4 ) V_15 && ( V_11 = strstr ( V_11 , V_14 ) ) ) {
V_17 ++ ;
for( V_5 = 0 ; V_5 < V_19 ; V_5 ++ )
V_11 [ V_5 ] = '\0' ;
V_11 += V_19 ;
}
V_20 = F_12 ( V_1 , T_1 * , V_17 + 1 ) ;
V_24 = V_21 ;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ ) {
switch( V_24 ) {
case V_21 :
if ( V_16 [ V_5 ] == '\0' ) {
V_24 = V_22 ;
}
else {
V_20 [ V_25 ] = & ( V_16 [ V_5 ] ) ;
V_25 ++ ;
V_24 = V_23 ;
}
break;
case V_23 :
if ( V_16 [ V_5 ] == '\0' ) {
V_24 = V_22 ;
}
break;
case V_22 :
if ( V_16 [ V_5 ] != '\0' ) {
V_20 [ V_25 ] = & ( V_16 [ V_5 ] ) ;
V_25 ++ ;
V_24 = V_23 ;
}
break;
}
}
V_20 [ V_25 ] = NULL ;
return V_20 ;
}
