void * F_1 ( void ) {
struct V_1 * V_2 = 0 ;
V_2 = (struct V_1 * ) F_2 ( sizeof( struct V_1 ) ) ;
V_2 -> V_3 = - 1 ;
return V_2 ;
}
void F_3 ( void * V_4 ) {
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! V_2 ) return;
F_4 ( V_2 -> V_3 ) ;
F_5 ( V_2 ) ;
}
int F_6 ( void * V_4 , const void * V_5 , int V_6 , void * V_7 , int * V_8 ) {
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
const unsigned char * V_9 = ( const unsigned char * ) V_5 ;
short * V_10 = ( short * ) V_7 ;
int V_11 = 0 ;
if ( ! V_2 ) return 0 ;
if ( V_2 -> V_3 == - 1 ) {
if ( V_9 [ 0 ] & 0x03 ) {
V_2 -> V_3 = F_7 ( FALSE ) ;
V_2 -> V_12 = V_13 ;
} else {
V_2 -> V_3 = F_7 ( TRUE ) ;
V_2 -> V_12 = V_14 ;
}
}
if ( ( V_6 % V_2 -> V_12 ) != 0 )
return 0 ;
if ( ! V_7 )
return ( V_6 / V_2 -> V_12 ) * V_15 * sizeof( short ) ;
while ( ( V_6 >= V_2 -> V_12 ) &&
( ( * V_8 - V_11 ) >= V_15 * sizeof( short ) ) ) {
if ( F_8 ( V_2 -> V_3 , ( unsigned char * ) V_9 , V_2 -> V_16 ) ) {
memcpy ( V_10 , V_2 -> V_16 , V_15 * sizeof( short ) ) ;
V_10 += V_15 ;
V_11 += V_15 * sizeof( short ) ;
}
V_9 += V_2 -> V_12 ;
V_6 -= V_2 -> V_12 ;
}
return V_11 ;
}
