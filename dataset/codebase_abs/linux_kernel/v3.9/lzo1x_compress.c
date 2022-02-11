static T_1 T_2
F_1 ( const unsigned char * V_1 , T_2 V_2 ,
unsigned char * V_3 , T_2 * V_4 ,
T_2 V_5 , void * V_6 )
{
const unsigned char * V_7 ;
unsigned char * V_8 ;
const unsigned char * const V_9 = V_1 + V_2 ;
const unsigned char * const V_10 = V_1 + V_2 - 20 ;
const unsigned char * V_11 ;
T_3 * const V_12 = ( T_3 * ) V_6 ;
V_8 = V_3 ;
V_7 = V_1 ;
V_11 = V_7 ;
V_7 += V_5 < 4 ? 4 - V_5 : 0 ;
for (; ; ) {
const unsigned char * V_13 ;
T_2 V_14 , V_15 , V_16 ;
T_4 V_17 ;
V_18:
V_7 += 1 + ( ( V_7 - V_11 ) >> 5 ) ;
V_19:
if ( F_2 ( V_7 >= V_10 ) )
break;
V_17 = F_3 ( V_7 ) ;
V_14 = ( ( V_17 * 0x1824429d ) >> ( 32 - V_20 ) ) & V_21 ;
V_13 = V_1 + V_12 [ V_14 ] ;
V_12 [ V_14 ] = ( T_3 ) ( V_7 - V_1 ) ;
if ( F_2 ( V_17 != F_3 ( V_13 ) ) )
goto V_18;
V_11 -= V_5 ;
V_5 = 0 ;
V_14 = V_7 - V_11 ;
if ( V_14 != 0 ) {
if ( V_14 <= 3 ) {
V_8 [ - 2 ] |= V_14 ;
F_4 ( V_8 , V_11 ) ;
V_8 += V_14 ;
} else if ( V_14 <= 16 ) {
* V_8 ++ = ( V_14 - 3 ) ;
F_5 ( V_8 , V_11 ) ;
F_5 ( V_8 + 8 , V_11 + 8 ) ;
V_8 += V_14 ;
} else {
if ( V_14 <= 18 ) {
* V_8 ++ = ( V_14 - 3 ) ;
} else {
T_2 V_22 = V_14 - 18 ;
* V_8 ++ = 0 ;
while ( F_2 ( V_22 > 255 ) ) {
V_22 -= 255 ;
* V_8 ++ = 0 ;
}
* V_8 ++ = V_22 ;
}
do {
F_5 ( V_8 , V_11 ) ;
F_5 ( V_8 + 8 , V_11 + 8 ) ;
V_8 += 16 ;
V_11 += 16 ;
V_14 -= 16 ;
} while ( V_14 >= 16 );
if ( V_14 > 0 ) do {
* V_8 ++ = * V_11 ++ ;
} while ( -- V_14 > 0 );
}
}
V_15 = 4 ;
{
#if F_6 ( V_23 ) && F_6 ( V_24 )
T_5 V_25 ;
V_25 = F_7 ( ( const T_5 * ) ( V_7 + V_15 ) ) ^
F_7 ( ( const T_5 * ) ( V_13 + V_15 ) ) ;
if ( F_2 ( V_25 == 0 ) ) {
do {
V_15 += 8 ;
V_25 = F_7 ( ( const T_5 * ) ( V_7 + V_15 ) ) ^
F_7 ( ( const T_5 * ) ( V_13 + V_15 ) ) ;
if ( F_2 ( V_7 + V_15 >= V_10 ) )
goto V_26;
} while ( V_25 == 0 );
}
# if F_6 ( V_27 )
V_15 += ( unsigned ) F_8 ( V_25 ) / 8 ;
# elif F_6 ( V_28 )
V_15 += ( unsigned ) F_9 ( V_25 ) / 8 ;
# else
# error "missing endian definition"
# endif
#elif F_6 ( V_23 ) && F_6 ( V_29 )
T_4 V_25 ;
V_25 = F_7 ( ( const T_4 * ) ( V_7 + V_15 ) ) ^
F_7 ( ( const T_4 * ) ( V_13 + V_15 ) ) ;
if ( F_2 ( V_25 == 0 ) ) {
do {
V_15 += 4 ;
V_25 = F_7 ( ( const T_4 * ) ( V_7 + V_15 ) ) ^
F_7 ( ( const T_4 * ) ( V_13 + V_15 ) ) ;
if ( V_25 != 0 )
break;
V_15 += 4 ;
V_25 = F_7 ( ( const T_4 * ) ( V_7 + V_15 ) ) ^
F_7 ( ( const T_4 * ) ( V_13 + V_15 ) ) ;
if ( F_2 ( V_7 + V_15 >= V_10 ) )
goto V_26;
} while ( V_25 == 0 );
}
# if F_6 ( V_27 )
V_15 += ( unsigned ) F_10 ( V_25 ) / 8 ;
# elif F_6 ( V_28 )
V_15 += ( unsigned ) F_11 ( V_25 ) / 8 ;
# else
# error "missing endian definition"
# endif
#else
if ( F_2 ( V_7 [ V_15 ] == V_13 [ V_15 ] ) ) {
do {
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( V_7 [ V_15 ] != V_13 [ V_15 ] )
break;
V_15 += 1 ;
if ( F_2 ( V_7 + V_15 >= V_10 ) )
goto V_26;
} while ( V_7 [ V_15 ] == V_13 [ V_15 ] );
}
#endif
}
V_26:
V_16 = V_7 - V_13 ;
V_7 += V_15 ;
V_11 = V_7 ;
if ( V_15 <= V_30 && V_16 <= V_31 ) {
V_16 -= 1 ;
* V_8 ++ = ( ( ( V_15 - 1 ) << 5 ) | ( ( V_16 & 7 ) << 2 ) ) ;
* V_8 ++ = ( V_16 >> 3 ) ;
} else if ( V_16 <= V_32 ) {
V_16 -= 1 ;
if ( V_15 <= V_33 )
* V_8 ++ = ( V_34 | ( V_15 - 2 ) ) ;
else {
V_15 -= V_33 ;
* V_8 ++ = V_34 | 0 ;
while ( F_2 ( V_15 > 255 ) ) {
V_15 -= 255 ;
* V_8 ++ = 0 ;
}
* V_8 ++ = ( V_15 ) ;
}
* V_8 ++ = ( V_16 << 2 ) ;
* V_8 ++ = ( V_16 >> 6 ) ;
} else {
V_16 -= 0x4000 ;
if ( V_15 <= V_35 )
* V_8 ++ = ( V_36 | ( ( V_16 >> 11 ) & 8 )
| ( V_15 - 2 ) ) ;
else {
V_15 -= V_35 ;
* V_8 ++ = ( V_36 | ( ( V_16 >> 11 ) & 8 ) ) ;
while ( F_2 ( V_15 > 255 ) ) {
V_15 -= 255 ;
* V_8 ++ = 0 ;
}
* V_8 ++ = ( V_15 ) ;
}
* V_8 ++ = ( V_16 << 2 ) ;
* V_8 ++ = ( V_16 >> 6 ) ;
}
goto V_19;
}
* V_4 = V_8 - V_3 ;
return V_9 - ( V_11 - V_5 ) ;
}
int F_12 ( const unsigned char * V_1 , T_2 V_2 ,
unsigned char * V_3 , T_2 * V_4 ,
void * V_6 )
{
const unsigned char * V_7 = V_1 ;
unsigned char * V_8 = V_3 ;
T_2 V_37 = V_2 ;
T_2 V_14 = 0 ;
while ( V_37 > 20 ) {
T_2 V_38 = V_37 <= ( V_39 + 1 ) ? V_37 : ( V_39 + 1 ) ;
T_6 V_40 = ( T_6 ) V_7 + V_38 ;
if ( ( V_40 + ( ( V_14 + V_38 ) >> 5 ) ) <= V_40 )
break;
F_13 ( V_41 * sizeof( T_3 ) > V_42 ) ;
memset ( V_6 , 0 , V_41 * sizeof( T_3 ) ) ;
V_14 = F_1 ( V_7 , V_38 , V_8 , V_4 , V_14 , V_6 ) ;
V_7 += V_38 ;
V_8 += * V_4 ;
V_37 -= V_38 ;
}
V_14 += V_37 ;
if ( V_14 > 0 ) {
const unsigned char * V_11 = V_1 + V_2 - V_14 ;
if ( V_8 == V_3 && V_14 <= 238 ) {
* V_8 ++ = ( 17 + V_14 ) ;
} else if ( V_14 <= 3 ) {
V_8 [ - 2 ] |= V_14 ;
} else if ( V_14 <= 18 ) {
* V_8 ++ = ( V_14 - 3 ) ;
} else {
T_2 V_22 = V_14 - 18 ;
* V_8 ++ = 0 ;
while ( V_22 > 255 ) {
V_22 -= 255 ;
* V_8 ++ = 0 ;
}
* V_8 ++ = V_22 ;
}
if ( V_14 >= 16 ) do {
F_5 ( V_8 , V_11 ) ;
F_5 ( V_8 + 8 , V_11 + 8 ) ;
V_8 += 16 ;
V_11 += 16 ;
V_14 -= 16 ;
} while ( V_14 >= 16 );
if ( V_14 > 0 ) do {
* V_8 ++ = * V_11 ++ ;
} while ( -- V_14 > 0 );
}
* V_8 ++ = V_36 | 1 ;
* V_8 ++ = 0 ;
* V_8 ++ = 0 ;
* V_4 = V_8 - V_3 ;
return V_43 ;
}
