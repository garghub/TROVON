int
F_1 ( T_1 , T_2 , T_3 )
int T_1 ;
const char * T_2 ;
void * T_3 ;
{
switch ( T_1 ) {
#ifdef F_2
case F_2 :
return ( F_3 ( T_2 , T_3 ) ) ;
#endif
#ifdef F_4
case F_4 :
return ( F_5 ( T_2 , T_3 ) ) ;
#endif
default:
V_1 = V_2 ;
return ( - 1 ) ;
}
}
static int
F_3 ( T_2 , T_3 )
const char * T_2 ;
T_4 * T_3 ;
{
static const char V_3 [] = L_1 ;
int V_4 , V_5 , V_6 ;
T_4 V_7 [ V_8 ] , * V_9 ;
V_4 = 0 ;
V_5 = 0 ;
* ( V_9 = V_7 ) = 0 ;
while ( ( V_6 = * T_2 ++ ) != '\0' ) {
const char * V_10 ;
if ( ( V_10 = strchr ( V_3 , V_6 ) ) != NULL ) {
T_5 V_11 = * V_9 * 10 + ( V_10 - V_3 ) ;
if ( V_11 > 255 )
return ( 0 ) ;
* V_9 = ( T_4 ) V_11 ;
if ( ! V_4 ) {
if ( ++ V_5 > 4 )
return ( 0 ) ;
V_4 = 1 ;
}
} else if ( V_6 == '.' && V_4 ) {
if ( V_5 == 4 )
return ( 0 ) ;
* ++ V_9 = 0 ;
V_4 = 0 ;
} else
return ( 0 ) ;
}
if ( V_5 < 4 )
return ( 0 ) ;
memcpy ( T_3 , V_7 , V_8 ) ;
return ( 1 ) ;
}
static int
F_5 ( T_2 , T_3 )
const char * T_2 ;
T_4 * T_3 ;
{
static const char V_12 [] = L_2 ,
V_13 [] = L_3 ;
T_4 V_7 [ V_14 ] , * V_9 , * V_15 , * V_16 ;
const char * V_17 , * V_18 ;
int V_6 , V_19 ;
T_6 V_20 ;
memset ( ( V_9 = V_7 ) , '\0' , V_14 ) ;
V_15 = V_9 + V_14 ;
V_16 = NULL ;
if ( * T_2 == ':' )
if ( * ++ T_2 != ':' )
return ( 0 ) ;
V_18 = T_2 ;
V_19 = 0 ;
V_20 = 0 ;
while ( ( V_6 = * T_2 ++ ) != '\0' ) {
const char * V_10 ;
if ( ( V_10 = strchr ( ( V_17 = V_12 ) , V_6 ) ) == NULL )
V_10 = strchr ( ( V_17 = V_13 ) , V_6 ) ;
if ( V_10 != NULL ) {
V_20 <<= 4 ;
V_20 |= ( V_10 - V_17 ) ;
if ( V_20 > 0xffff )
return ( 0 ) ;
V_19 = 1 ;
continue;
}
if ( V_6 == ':' ) {
V_18 = T_2 ;
if ( ! V_19 ) {
if ( V_16 )
return ( 0 ) ;
V_16 = V_9 ;
continue;
} else if ( * T_2 == '\0' ) {
return ( 0 ) ;
}
if ( V_9 + V_21 > V_15 )
return ( 0 ) ;
* V_9 ++ = ( T_4 ) ( V_20 >> 8 ) & 0xff ;
* V_9 ++ = ( T_4 ) V_20 & 0xff ;
V_19 = 0 ;
V_20 = 0 ;
continue;
}
if ( V_6 == '.' && ( ( V_9 + V_8 ) <= V_15 ) &&
F_3 ( V_18 , V_9 ) > 0 ) {
V_9 += V_8 ;
V_19 = 0 ;
break;
}
return ( 0 ) ;
}
if ( V_19 ) {
if ( V_9 + V_21 > V_15 )
return ( 0 ) ;
* V_9 ++ = ( T_4 ) ( V_20 >> 8 ) & 0xff ;
* V_9 ++ = ( T_4 ) V_20 & 0xff ;
}
if ( V_16 != NULL ) {
const int V_22 = ( int ) ( V_9 - V_16 ) ;
int V_23 ;
if ( V_9 == V_15 )
return ( 0 ) ;
for ( V_23 = 1 ; V_23 <= V_22 ; V_23 ++ ) {
V_15 [ - V_23 ] = V_16 [ V_22 - V_23 ] ;
V_16 [ V_22 - V_23 ] = 0 ;
}
V_9 = V_15 ;
}
if ( V_9 != V_15 )
return ( 0 ) ;
memcpy ( T_3 , V_7 , V_14 ) ;
return ( 1 ) ;
}
