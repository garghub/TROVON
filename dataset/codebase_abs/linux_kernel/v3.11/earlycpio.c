struct V_1 F_1 ( const char * V_2 , void * V_3 ,
T_1 V_4 , long * V_5 )
{
const T_1 V_6 = 8 * V_7 - 2 ;
struct V_1 V_8 = { NULL , 0 , L_1 } ;
const char * V_9 , * V_10 , * V_11 ;
unsigned int V_12 [ V_7 ] , * V_13 , V_14 ;
unsigned char V_15 , V_16 ;
T_1 V_17 = strlen ( V_2 ) ;
int V_18 , V_19 ;
V_9 = V_3 ;
while ( V_4 > V_6 ) {
if ( ! * V_9 ) {
V_9 += 4 ;
V_4 -= 4 ;
continue;
}
V_19 = 6 ;
V_13 = V_12 ;
for ( V_18 = V_7 ; V_18 ; V_18 -- ) {
V_14 = 0 ;
while ( V_19 -- ) {
V_14 <<= 4 ;
V_15 = * V_9 ++ ;
V_16 = V_15 - '0' ;
if ( V_16 < 10 ) {
V_14 += V_16 ;
continue;
}
V_16 = ( V_15 | 0x20 ) - 'a' ;
if ( V_16 < 6 ) {
V_14 += V_16 + 10 ;
continue;
}
goto V_20;
}
* V_13 ++ = V_14 ;
V_19 = 8 ;
}
if ( ( V_12 [ V_21 ] - 0x070701 ) > 1 )
goto V_20;
V_4 -= V_6 ;
V_10 = F_2 ( V_9 + V_12 [ V_22 ] , 4 ) ;
V_11 = F_2 ( V_10 + V_12 [ V_23 ] , 4 ) ;
if ( V_11 > V_9 + V_4 || V_10 < V_9 || V_11 < V_10 )
goto V_20;
if ( ( V_12 [ V_24 ] & 0170000 ) == 0100000 &&
V_12 [ V_22 ] >= V_17 &&
! memcmp ( V_9 , V_2 , V_17 ) ) {
* V_5 = ( long ) V_11 - ( long ) V_3 ;
if ( V_12 [ V_22 ] - V_17 >= V_25 ) {
F_3 (
L_2 ,
V_9 , V_25 ) ;
}
F_4 ( V_8 . V_26 , V_9 + V_17 , V_25 ) ;
V_8 . V_3 = ( void * ) V_10 ;
V_8 . V_27 = V_12 [ V_23 ] ;
return V_8 ;
}
V_4 -= ( V_11 - V_9 ) ;
V_9 = V_11 ;
}
V_20:
return V_8 ;
}
