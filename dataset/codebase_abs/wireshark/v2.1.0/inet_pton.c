int
F_1 ( int V_1 , const char * V_2 , void * V_3 )
{
switch ( V_1 ) {
#ifdef F_2
case F_2 :
return ( F_3 ( V_2 , V_3 ) ) ;
#endif
#ifdef F_4
case F_4 :
return ( F_5 ( V_2 , V_3 ) ) ;
#endif
default:
V_4 = V_5 ;
return ( - 1 ) ;
}
}
static int
F_3 ( const char * V_2 , T_1 * V_3 )
{
static const char V_6 [] = L_1 ;
int V_7 , V_8 , V_9 ;
T_1 V_10 [ V_11 ] , * V_12 ;
V_7 = 0 ;
V_8 = 0 ;
* ( V_12 = V_10 ) = 0 ;
while ( ( V_9 = * V_2 ++ ) != '\0' ) {
const char * V_13 ;
if ( ( V_13 = strchr ( V_6 , V_9 ) ) != NULL ) {
T_2 V_14 = * V_12 * 10 + ( V_13 - V_6 ) ;
if ( V_14 > 255 )
return ( 0 ) ;
* V_12 = ( T_1 ) V_14 ;
if ( ! V_7 ) {
if ( ++ V_8 > 4 )
return ( 0 ) ;
V_7 = 1 ;
}
} else if ( V_9 == '.' && V_7 ) {
if ( V_8 == 4 )
return ( 0 ) ;
* ++ V_12 = 0 ;
V_7 = 0 ;
} else
return ( 0 ) ;
}
if ( V_8 < 4 )
return ( 0 ) ;
memcpy ( V_3 , V_10 , V_11 ) ;
return ( 1 ) ;
}
static int
F_5 ( const char * V_2 , T_1 * V_3 )
{
static const char V_15 [] = L_2 ,
V_16 [] = L_3 ;
T_1 V_10 [ V_17 ] , * V_12 , * V_18 , * V_19 ;
const char * V_20 , * V_21 ;
int V_9 , V_22 ;
T_3 V_23 ;
memset ( ( V_12 = V_10 ) , '\0' , V_17 ) ;
V_18 = V_12 + V_17 ;
V_19 = NULL ;
if ( * V_2 == ':' )
if ( * ++ V_2 != ':' )
return ( 0 ) ;
V_21 = V_2 ;
V_22 = 0 ;
V_23 = 0 ;
while ( ( V_9 = * V_2 ++ ) != '\0' ) {
const char * V_13 ;
if ( ( V_13 = strchr ( ( V_20 = V_15 ) , V_9 ) ) == NULL )
V_13 = strchr ( ( V_20 = V_16 ) , V_9 ) ;
if ( V_13 != NULL ) {
V_23 <<= 4 ;
V_23 |= ( V_13 - V_20 ) ;
if ( V_23 > 0xffff )
return ( 0 ) ;
V_22 = 1 ;
continue;
}
if ( V_9 == ':' ) {
V_21 = V_2 ;
if ( ! V_22 ) {
if ( V_19 )
return ( 0 ) ;
V_19 = V_12 ;
continue;
} else if ( * V_2 == '\0' ) {
return ( 0 ) ;
}
if ( V_12 + V_24 > V_18 )
return ( 0 ) ;
* V_12 ++ = ( T_1 ) ( V_23 >> 8 ) & 0xff ;
* V_12 ++ = ( T_1 ) V_23 & 0xff ;
V_22 = 0 ;
V_23 = 0 ;
continue;
}
if ( V_9 == '.' && ( ( V_12 + V_11 ) <= V_18 ) &&
F_3 ( V_21 , V_12 ) > 0 ) {
V_12 += V_11 ;
V_22 = 0 ;
break;
}
return ( 0 ) ;
}
if ( V_22 ) {
if ( V_12 + V_24 > V_18 )
return ( 0 ) ;
* V_12 ++ = ( T_1 ) ( V_23 >> 8 ) & 0xff ;
* V_12 ++ = ( T_1 ) V_23 & 0xff ;
}
if ( V_19 != NULL ) {
const int V_25 = ( int ) ( V_12 - V_19 ) ;
int V_26 ;
if ( V_12 == V_18 )
return ( 0 ) ;
for ( V_26 = 1 ; V_26 <= V_25 ; V_26 ++ ) {
V_18 [ - V_26 ] = V_19 [ V_25 - V_26 ] ;
V_19 [ V_25 - V_26 ] = 0 ;
}
V_12 = V_18 ;
}
if ( V_12 != V_18 )
return ( 0 ) ;
memcpy ( V_3 , V_10 , V_17 ) ;
return ( 1 ) ;
}
