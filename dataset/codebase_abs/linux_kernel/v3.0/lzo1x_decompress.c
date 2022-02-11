int F_1 ( const unsigned char * V_1 , T_1 V_2 ,
unsigned char * V_3 , T_1 * V_4 )
{
const unsigned char * const V_5 = V_1 + V_2 ;
unsigned char * const V_6 = V_3 + * V_4 ;
const unsigned char * V_7 = V_1 , * V_8 ;
unsigned char * V_9 = V_3 ;
T_1 V_10 ;
* V_4 = 0 ;
if ( * V_7 > 17 ) {
V_10 = * V_7 ++ - 17 ;
if ( V_10 < 4 )
goto V_11;
if ( F_2 ( V_10 , V_6 , V_9 ) )
goto V_12;
if ( F_3 ( V_10 + 1 , V_5 , V_7 ) )
goto V_13;
do {
* V_9 ++ = * V_7 ++ ;
} while ( -- V_10 > 0 );
goto V_14;
}
while ( ( V_7 < V_5 ) ) {
V_10 = * V_7 ++ ;
if ( V_10 >= 16 )
goto V_15;
if ( V_10 == 0 ) {
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
while ( * V_7 == 0 ) {
V_10 += 255 ;
V_7 ++ ;
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
}
V_10 += 15 + * V_7 ++ ;
}
if ( F_2 ( V_10 + 3 , V_6 , V_9 ) )
goto V_12;
if ( F_3 ( V_10 + 4 , V_5 , V_7 ) )
goto V_13;
F_4 ( V_9 , V_7 ) ;
V_9 += 4 ;
V_7 += 4 ;
if ( -- V_10 > 0 ) {
if ( V_10 >= 4 ) {
do {
F_4 ( V_9 , V_7 ) ;
V_9 += 4 ;
V_7 += 4 ;
V_10 -= 4 ;
} while ( V_10 >= 4 );
if ( V_10 > 0 ) {
do {
* V_9 ++ = * V_7 ++ ;
} while ( -- V_10 > 0 );
}
} else {
do {
* V_9 ++ = * V_7 ++ ;
} while ( -- V_10 > 0 );
}
}
V_14:
V_10 = * V_7 ++ ;
if ( V_10 >= 16 )
goto V_15;
V_8 = V_9 - ( 1 + V_16 ) ;
V_8 -= V_10 >> 2 ;
V_8 -= * V_7 ++ << 2 ;
if ( F_5 ( V_8 , V_3 , V_9 ) )
goto V_17;
if ( F_2 ( 3 , V_6 , V_9 ) )
goto V_12;
* V_9 ++ = * V_8 ++ ;
* V_9 ++ = * V_8 ++ ;
* V_9 ++ = * V_8 ;
goto V_18;
do {
V_15:
if ( V_10 >= 64 ) {
V_8 = V_9 - 1 ;
V_8 -= ( V_10 >> 2 ) & 7 ;
V_8 -= * V_7 ++ << 3 ;
V_10 = ( V_10 >> 5 ) - 1 ;
if ( F_5 ( V_8 , V_3 , V_9 ) )
goto V_17;
if ( F_2 ( V_10 + 3 - 1 , V_6 , V_9 ) )
goto V_12;
goto V_19;
} else if ( V_10 >= 32 ) {
V_10 &= 31 ;
if ( V_10 == 0 ) {
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
while ( * V_7 == 0 ) {
V_10 += 255 ;
V_7 ++ ;
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
}
V_10 += 31 + * V_7 ++ ;
}
V_8 = V_9 - 1 ;
V_8 -= F_6 ( V_7 ) >> 2 ;
V_7 += 2 ;
} else if ( V_10 >= 16 ) {
V_8 = V_9 ;
V_8 -= ( V_10 & 8 ) << 11 ;
V_10 &= 7 ;
if ( V_10 == 0 ) {
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
while ( * V_7 == 0 ) {
V_10 += 255 ;
V_7 ++ ;
if ( F_3 ( 1 , V_5 , V_7 ) )
goto V_13;
}
V_10 += 7 + * V_7 ++ ;
}
V_8 -= F_6 ( V_7 ) >> 2 ;
V_7 += 2 ;
if ( V_8 == V_9 )
goto V_20;
V_8 -= 0x4000 ;
} else {
V_8 = V_9 - 1 ;
V_8 -= V_10 >> 2 ;
V_8 -= * V_7 ++ << 2 ;
if ( F_5 ( V_8 , V_3 , V_9 ) )
goto V_17;
if ( F_2 ( 2 , V_6 , V_9 ) )
goto V_12;
* V_9 ++ = * V_8 ++ ;
* V_9 ++ = * V_8 ;
goto V_18;
}
if ( F_5 ( V_8 , V_3 , V_9 ) )
goto V_17;
if ( F_2 ( V_10 + 3 - 1 , V_6 , V_9 ) )
goto V_12;
if ( V_10 >= 2 * 4 - ( 3 - 1 ) && ( V_9 - V_8 ) >= 4 ) {
F_4 ( V_9 , V_8 ) ;
V_9 += 4 ;
V_8 += 4 ;
V_10 -= 4 - ( 3 - 1 ) ;
do {
F_4 ( V_9 , V_8 ) ;
V_9 += 4 ;
V_8 += 4 ;
V_10 -= 4 ;
} while ( V_10 >= 4 );
if ( V_10 > 0 )
do {
* V_9 ++ = * V_8 ++ ;
} while ( -- V_10 > 0 );
} else {
V_19:
* V_9 ++ = * V_8 ++ ;
* V_9 ++ = * V_8 ++ ;
do {
* V_9 ++ = * V_8 ++ ;
} while ( -- V_10 > 0 );
}
V_18:
V_10 = V_7 [ - 2 ] & 3 ;
if ( V_10 == 0 )
break;
V_11:
if ( F_2 ( V_10 , V_6 , V_9 ) )
goto V_12;
if ( F_3 ( V_10 + 1 , V_5 , V_7 ) )
goto V_13;
* V_9 ++ = * V_7 ++ ;
if ( V_10 > 1 ) {
* V_9 ++ = * V_7 ++ ;
if ( V_10 > 2 )
* V_9 ++ = * V_7 ++ ;
}
V_10 = * V_7 ++ ;
} while ( V_7 < V_5 );
}
* V_4 = V_9 - V_3 ;
return V_21 ;
V_20:
* V_4 = V_9 - V_3 ;
return ( V_7 == V_5 ? V_22 :
( V_7 < V_5 ? V_23 : V_24 ) ) ;
V_13:
* V_4 = V_9 - V_3 ;
return V_24 ;
V_12:
* V_4 = V_9 - V_3 ;
return V_25 ;
V_17:
* V_4 = V_9 - V_3 ;
return V_26 ;
}
