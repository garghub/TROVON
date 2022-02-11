void *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
F_3 ( V_1 , 0L ) ;
return V_1 ;
}
void
F_4 ( void * V_2 )
{
T_1 * V_1 = ( T_1 * ) V_2 ;
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
}
unsigned
F_7 ( void * V_2 )
{
T_1 * V_1 = ( T_1 * ) V_2 ;
if ( V_1 -> V_3 == V_4 )
return 1 ;
return 2 ;
}
unsigned
F_8 ( void * V_2 )
{
T_1 * V_1 = ( T_1 * ) V_2 ;
int V_5 ;
switch ( V_1 -> V_5 ) {
case V_6 :
V_5 = 16000 ;
break;
case V_7 :
V_5 = 32000 ;
break;
case V_8 :
V_5 = 44100 ;
break;
case V_9 :
V_5 = 48000 ;
break;
default:
V_5 = 0 ;
}
return V_5 ;
}
T_2
F_9 ( void * V_2 , const void * V_10 , T_2 V_11 , void * V_12 ,
T_2 * V_13 )
{
T_2 V_14 = ( T_2 ) V_11 ;
T_2 V_15 = V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_2 V_19 = 0 ;
const T_3 * V_20 = ( const T_3 * ) V_10 ;
T_3 * V_21 = ( T_3 * ) V_12 ;
T_1 * V_1 = ( T_1 * ) V_2 ;
T_3 * V_22 ;
T_3 V_23 ;
if ( ! V_12 || ! V_13 ) {
return V_15 ;
}
V_1 -> V_24 = V_25 ;
* V_13 = 0 ;
while ( V_19 < V_11 ) {
V_18 = F_10 ( V_1 , V_20 , V_14 , V_21 , V_15 , & V_17 ) ;
V_19 += V_18 ;
V_20 += V_18 ;
* V_13 += V_17 ;
for ( V_22 = V_21 ; V_22 < V_21 + V_17 ; V_22 += 2 ) {
V_23 = V_22 [ 0 ] ;
V_22 [ 0 ] = V_22 [ 1 ] ;
V_22 [ 1 ] = V_23 ;
}
V_21 += V_17 ;
}
return * V_13 ;
}
