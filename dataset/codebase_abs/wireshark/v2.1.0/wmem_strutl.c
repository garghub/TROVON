T_1 *
F_1 ( T_2 * V_1 , const T_1 * V_2 )
{
T_3 V_3 ;
if ( ! V_2 ) {
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
T_1 * V_4 ;
int V_9 ;
F_6 ( V_8 , V_7 ) ;
V_4 = ( T_1 * ) F_2 ( V_1 , V_10 ) ;
V_9 = F_7 ( V_4 , ( V_11 ) V_10 , V_6 , V_8 ) + 1 ;
va_end ( V_8 ) ;
if ( V_9 > V_10 ) {
F_8 ( V_1 , V_4 ) ;
V_4 = ( T_1 * ) F_2 ( V_1 , V_9 ) ;
F_6 ( V_8 , V_7 ) ;
F_7 ( V_4 , ( V_11 ) V_9 , V_6 , V_8 ) ;
va_end ( V_8 ) ;
}
return V_4 ;
}
T_1 *
F_5 ( T_2 * V_1 , const T_1 * V_6 , T_5 V_7 )
{
T_5 V_8 ;
T_1 * V_4 ;
int V_9 ;
F_6 ( V_8 , V_7 ) ;
V_9 = F_9 ( V_6 , V_8 ) + 1 ;
V_4 = ( T_1 * ) F_2 ( V_1 , V_9 ) ;
F_10 ( V_4 , V_9 , V_6 , V_8 ) ;
va_end ( V_8 ) ;
return V_4 ;
}
T_1 *
F_11 ( T_2 * V_1 , const T_1 * V_12 , ... )
{
T_6 V_3 ;
T_5 args ;
T_1 * V_13 ;
T_1 * V_14 ;
T_1 * V_15 ;
if ( ! V_12 )
return NULL ;
V_3 = 1 + strlen ( V_12 ) ;
va_start ( args , V_12 ) ;
while ( ( V_13 = va_arg ( args , T_1 * ) ) ) {
V_3 += strlen ( V_13 ) ;
}
va_end ( args ) ;
V_15 = V_14 = ( T_1 * ) F_2 ( V_1 , V_3 ) ;
V_15 = F_12 ( V_15 , V_12 ) ;
va_start ( args , V_12 ) ;
while ( ( V_13 = va_arg ( args , T_1 * ) ) ) {
V_15 = F_12 ( V_15 , V_13 ) ;
}
va_end ( args ) ;
return V_14 ;
}
T_1 * *
F_13 ( T_2 * V_1 , const T_1 * V_2 ,
const T_1 * V_16 , int V_17 )
{
T_1 * V_18 ;
T_1 * V_13 ;
T_4 V_19 ;
T_4 V_20 ;
T_4 V_21 ;
T_4 V_5 ;
T_1 * * V_22 ;
enum { V_23 , V_24 , V_25 } V_26 ;
T_4 V_27 = 0 ;
if ( ! V_2
|| ! V_16
|| ! V_16 [ 0 ] )
return NULL ;
V_13 = V_18 = F_1 ( V_1 , V_2 ) ;
V_20 = ( T_4 ) strlen ( V_18 ) ;
V_21 = ( T_4 ) strlen ( V_16 ) ;
if ( V_17 < 1 ) V_17 = V_28 ;
V_19 = 1 ;
while ( V_19 <= ( T_4 ) V_17 && ( V_13 = strstr ( V_13 , V_16 ) ) ) {
V_19 ++ ;
for( V_5 = 0 ; V_5 < V_21 ; V_5 ++ )
V_13 [ V_5 ] = '\0' ;
V_13 += V_21 ;
}
V_22 = F_14 ( V_1 , T_1 * , V_19 + 1 ) ;
V_26 = V_23 ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
switch( V_26 ) {
case V_23 :
if ( V_18 [ V_5 ] == '\0' ) {
V_26 = V_24 ;
}
else {
V_22 [ V_27 ] = & ( V_18 [ V_5 ] ) ;
V_27 ++ ;
V_26 = V_25 ;
}
break;
case V_25 :
if ( V_18 [ V_5 ] == '\0' ) {
V_26 = V_24 ;
}
break;
case V_24 :
if ( V_18 [ V_5 ] != '\0' ) {
V_22 [ V_27 ] = & ( V_18 [ V_5 ] ) ;
V_27 ++ ;
V_26 = V_25 ;
}
break;
}
}
V_22 [ V_27 ] = NULL ;
return V_22 ;
}
T_1 *
F_15 ( T_2 * V_1 , const T_1 * V_29 , T_7 V_3 )
{
T_1 * V_30 , * V_13 ;
F_16 ( V_29 != NULL , NULL ) ;
if ( V_3 < 0 )
V_3 = strlen ( V_29 ) ;
V_30 = F_3 ( V_1 , V_29 , V_3 ) ;
for ( V_13 = V_30 ; * V_13 ; V_13 ++ )
* V_13 = F_17 ( * V_13 ) ;
return V_30 ;
}
