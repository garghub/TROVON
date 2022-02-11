static T_1 T_2
F_1 ( const unsigned char * V_1 , T_2 V_2 ,
unsigned char * V_3 , T_2 * V_4 , void * V_5 )
{
const unsigned char * const V_6 = V_1 + V_2 ;
const unsigned char * const V_7 = V_1 + V_2 - V_8 - 5 ;
const unsigned char * * const V_9 = V_5 ;
const unsigned char * V_10 = V_1 , * V_11 = V_10 ;
const unsigned char * V_12 , * V_13 , * V_14 ;
T_2 V_15 , V_16 , V_17 ;
unsigned char * V_18 = V_3 ;
V_10 += 4 ;
for (; ; ) {
V_17 = ( ( T_2 ) ( 0x21 * F_2 ( V_10 , 5 , 5 , 6 ) ) >> 5 ) & V_19 ;
V_14 = V_9 [ V_17 ] ;
if ( V_14 < V_1 )
goto V_20;
if ( V_10 == V_14 || ( ( T_2 ) ( V_10 - V_14 ) > V_21 ) )
goto V_20;
V_15 = V_10 - V_14 ;
if ( V_15 <= V_22 || V_14 [ 3 ] == V_10 [ 3 ] )
goto V_23;
V_17 = ( V_17 & ( V_19 & 0x7ff ) ) ^ ( V_24 | 0x1f ) ;
V_14 = V_9 [ V_17 ] ;
if ( V_14 < V_1 )
goto V_20;
if ( V_10 == V_14 || ( ( T_2 ) ( V_10 - V_14 ) > V_21 ) )
goto V_20;
V_15 = V_10 - V_14 ;
if ( V_15 <= V_22 || V_14 [ 3 ] == V_10 [ 3 ] )
goto V_23;
goto V_20;
V_23:
if ( F_3 ( ( const unsigned short * ) V_14 )
== F_3 ( ( const unsigned short * ) V_10 ) ) {
if ( F_4 ( V_14 [ 2 ] == V_10 [ 2 ] ) )
goto V_25;
}
V_20:
V_9 [ V_17 ] = V_10 ;
++ V_10 ;
if ( F_5 ( V_10 >= V_7 ) )
break;
continue;
V_25:
V_9 [ V_17 ] = V_10 ;
if ( V_10 != V_11 ) {
T_2 V_26 = V_10 - V_11 ;
if ( V_26 <= 3 ) {
V_18 [ - 2 ] |= V_26 ;
} else if ( V_26 <= 18 ) {
* V_18 ++ = ( V_26 - 3 ) ;
} else {
T_2 V_27 = V_26 - 18 ;
* V_18 ++ = 0 ;
while ( V_27 > 255 ) {
V_27 -= 255 ;
* V_18 ++ = 0 ;
}
* V_18 ++ = V_27 ;
}
do {
* V_18 ++ = * V_11 ++ ;
} while ( -- V_26 > 0 );
}
V_10 += 3 ;
if ( V_14 [ 3 ] != * V_10 ++ || V_14 [ 4 ] != * V_10 ++
|| V_14 [ 5 ] != * V_10 ++ || V_14 [ 6 ] != * V_10 ++
|| V_14 [ 7 ] != * V_10 ++ || V_14 [ 8 ] != * V_10 ++ ) {
-- V_10 ;
V_16 = V_10 - V_11 ;
if ( V_15 <= V_22 ) {
V_15 -= 1 ;
* V_18 ++ = ( ( ( V_16 - 1 ) << 5 )
| ( ( V_15 & 7 ) << 2 ) ) ;
* V_18 ++ = ( V_15 >> 3 ) ;
} else if ( V_15 <= V_28 ) {
V_15 -= 1 ;
* V_18 ++ = ( V_29 | ( V_16 - 2 ) ) ;
goto V_30;
} else {
V_15 -= 0x4000 ;
* V_18 ++ = ( V_31 | ( ( V_15 & 0x4000 ) >> 11 )
| ( V_16 - 2 ) ) ;
goto V_30;
}
} else {
V_12 = V_6 ;
V_13 = V_14 + V_8 + 1 ;
while ( V_10 < V_12 && * V_13 == * V_10 ) {
V_13 ++ ;
V_10 ++ ;
}
V_16 = V_10 - V_11 ;
if ( V_15 <= V_28 ) {
V_15 -= 1 ;
if ( V_16 <= 33 ) {
* V_18 ++ = ( V_29 | ( V_16 - 2 ) ) ;
} else {
V_16 -= 33 ;
* V_18 ++ = V_29 | 0 ;
goto V_32;
}
} else {
V_15 -= 0x4000 ;
if ( V_16 <= V_33 ) {
* V_18 ++ = ( V_31
| ( ( V_15 & 0x4000 ) >> 11 )
| ( V_16 - 2 ) ) ;
} else {
V_16 -= V_33 ;
* V_18 ++ = ( V_31
| ( ( V_15 & 0x4000 ) >> 11 ) ) ;
V_32:
while ( V_16 > 255 ) {
V_16 -= 255 ;
* V_18 ++ = 0 ;
}
* V_18 ++ = ( V_16 ) ;
}
}
V_30:
* V_18 ++ = ( ( V_15 & 63 ) << 2 ) ;
* V_18 ++ = ( V_15 >> 6 ) ;
}
V_11 = V_10 ;
if ( F_5 ( V_10 >= V_7 ) )
break;
}
* V_4 = V_18 - V_3 ;
return V_6 - V_11 ;
}
int F_6 ( const unsigned char * V_1 , T_2 V_2 , unsigned char * V_3 ,
T_2 * V_4 , void * V_5 )
{
const unsigned char * V_11 ;
unsigned char * V_18 = V_3 ;
T_2 V_26 ;
if ( F_5 ( V_2 <= V_8 + 5 ) ) {
V_26 = V_2 ;
} else {
V_26 = F_1 ( V_1 , V_2 , V_18 , V_4 , V_5 ) ;
V_18 += * V_4 ;
}
if ( V_26 > 0 ) {
V_11 = V_1 + V_2 - V_26 ;
if ( V_18 == V_3 && V_26 <= 238 ) {
* V_18 ++ = ( 17 + V_26 ) ;
} else if ( V_26 <= 3 ) {
V_18 [ - 2 ] |= V_26 ;
} else if ( V_26 <= 18 ) {
* V_18 ++ = ( V_26 - 3 ) ;
} else {
T_2 V_27 = V_26 - 18 ;
* V_18 ++ = 0 ;
while ( V_27 > 255 ) {
V_27 -= 255 ;
* V_18 ++ = 0 ;
}
* V_18 ++ = V_27 ;
}
do {
* V_18 ++ = * V_11 ++ ;
} while ( -- V_26 > 0 );
}
* V_18 ++ = V_31 | 1 ;
* V_18 ++ = 0 ;
* V_18 ++ = 0 ;
* V_4 = V_18 - V_3 ;
return V_34 ;
}
