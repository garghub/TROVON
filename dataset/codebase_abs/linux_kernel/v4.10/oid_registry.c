enum V_1 F_1 ( const void * V_2 , T_1 V_3 )
{
const unsigned char * V_4 = V_2 ;
enum V_1 V_5 ;
unsigned char V_6 ;
unsigned V_7 , V_8 , V_9 , V_10 ;
T_1 V_11 ;
V_10 = V_3 - 1 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ )
V_10 += V_4 [ V_7 ] * 33 ;
V_10 = ( V_10 >> 24 ) ^ ( V_10 >> 16 ) ^ ( V_10 >> 8 ) ^ V_10 ;
V_10 &= 0xff ;
V_7 = 0 ;
V_9 = V_12 ;
while ( V_7 < V_9 ) {
V_8 = ( V_7 + V_9 ) / 2 ;
V_6 = V_13 [ V_8 ] . V_10 ;
if ( V_6 > V_10 ) {
V_9 = V_8 ;
continue;
}
if ( V_6 < V_10 ) {
V_7 = V_8 + 1 ;
continue;
}
V_5 = V_13 [ V_8 ] . V_5 ;
V_11 = V_14 [ V_5 + 1 ] - V_14 [ V_5 ] ;
if ( V_11 > V_3 ) {
V_9 = V_8 ;
continue;
}
if ( V_11 < V_3 ) {
V_7 = V_8 + 1 ;
continue;
}
while ( V_11 > 0 ) {
unsigned char V_15 = V_16 [ V_14 [ V_5 ] + -- V_11 ] ;
unsigned char V_17 = V_4 [ V_11 ] ;
if ( V_15 > V_17 ) {
V_9 = V_8 ;
goto V_18;
}
if ( V_15 < V_17 ) {
V_7 = V_8 + 1 ;
goto V_18;
}
}
return V_5 ;
V_18:
;
}
return V_12 ;
}
int F_2 ( const void * V_2 , T_1 V_3 , char * V_19 , T_1 V_20 )
{
const unsigned char * V_21 = V_2 , * V_22 = V_21 + V_3 ;
unsigned long V_23 ;
unsigned char V_24 ;
T_1 V_25 ;
int V_26 ;
if ( V_21 >= V_22 )
return - V_27 ;
V_24 = * V_21 ++ ;
V_25 = V_26 = snprintf ( V_19 , V_20 , L_1 , V_24 / 40 , V_24 % 40 ) ;
V_19 += V_26 ;
V_20 -= V_26 ;
if ( V_20 == 0 )
return - V_28 ;
while ( V_21 < V_22 ) {
V_23 = 0 ;
V_24 = * V_21 ++ ;
if ( ! ( V_24 & 0x80 ) ) {
V_23 = V_24 ;
} else {
V_23 = V_24 & 0x7f ;
do {
if ( V_21 >= V_22 )
return - V_27 ;
V_24 = * V_21 ++ ;
V_23 <<= 7 ;
V_23 |= V_24 & 0x7f ;
} while ( V_24 & 0x80 );
}
V_25 += V_26 = snprintf ( V_19 , V_20 , L_2 , V_23 ) ;
V_19 += V_26 ;
V_20 -= V_26 ;
if ( V_20 == 0 )
return - V_28 ;
}
return V_25 ;
}
int F_3 ( enum V_1 V_5 , char * V_19 , T_1 V_20 )
{
int V_25 ;
F_4 ( V_5 >= V_12 ) ;
V_25 = F_2 ( V_16 + V_14 [ V_5 ] ,
V_14 [ V_5 + 1 ] - V_14 [ V_5 ] ,
V_19 , V_20 ) ;
F_4 ( V_25 == - V_27 ) ;
return V_25 ;
}
