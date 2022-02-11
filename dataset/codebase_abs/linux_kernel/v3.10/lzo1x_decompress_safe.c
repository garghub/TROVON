int F_1 ( const unsigned char * V_1 , T_1 V_2 ,
unsigned char * V_3 , T_1 * V_4 )
{
unsigned char * V_5 ;
const unsigned char * V_6 ;
T_1 V_7 , V_8 ;
T_1 V_9 = 0 ;
const unsigned char * V_10 ;
const unsigned char * const V_11 = V_1 + V_2 ;
unsigned char * const V_12 = V_3 + * V_4 ;
V_5 = V_3 ;
V_6 = V_1 ;
if ( F_2 ( V_2 < 3 ) )
goto V_13;
if ( * V_6 > 17 ) {
V_7 = * V_6 ++ - 17 ;
if ( V_7 < 4 ) {
V_8 = V_7 ;
goto V_14;
}
goto V_15;
}
for (; ; ) {
V_7 = * V_6 ++ ;
if ( V_7 < 16 ) {
if ( F_3 ( V_9 == 0 ) ) {
if ( F_2 ( V_7 == 0 ) ) {
while ( F_2 ( * V_6 == 0 ) ) {
V_7 += 255 ;
V_6 ++ ;
F_4 ( 1 ) ;
}
V_7 += 15 + * V_6 ++ ;
}
V_7 += 3 ;
V_15:
#if F_5 ( V_16 )
if ( F_3 ( F_6 ( V_7 + 15 ) && F_7 ( V_7 + 15 ) ) ) {
const unsigned char * V_17 = V_6 + V_7 ;
unsigned char * V_18 = V_5 + V_7 ;
do {
F_8 ( V_5 , V_6 ) ;
V_5 += 8 ;
V_6 += 8 ;
F_8 ( V_5 , V_6 ) ;
V_5 += 8 ;
V_6 += 8 ;
} while ( V_6 < V_17 );
V_6 = V_17 ;
V_5 = V_18 ;
} else
#endif
{
F_9 ( V_7 ) ;
F_4 ( V_7 + 3 ) ;
do {
* V_5 ++ = * V_6 ++ ;
} while ( -- V_7 > 0 );
}
V_9 = 4 ;
continue;
} else if ( V_9 != 4 ) {
V_8 = V_7 & 3 ;
V_10 = V_5 - 1 ;
V_10 -= V_7 >> 2 ;
V_10 -= * V_6 ++ << 2 ;
F_10 ( V_10 ) ;
F_9 ( 2 ) ;
V_5 [ 0 ] = V_10 [ 0 ] ;
V_5 [ 1 ] = V_10 [ 1 ] ;
V_5 += 2 ;
goto V_14;
} else {
V_8 = V_7 & 3 ;
V_10 = V_5 - ( 1 + V_19 ) ;
V_10 -= V_7 >> 2 ;
V_10 -= * V_6 ++ << 2 ;
V_7 = 3 ;
}
} else if ( V_7 >= 64 ) {
V_8 = V_7 & 3 ;
V_10 = V_5 - 1 ;
V_10 -= ( V_7 >> 2 ) & 7 ;
V_10 -= * V_6 ++ << 3 ;
V_7 = ( V_7 >> 5 ) - 1 + ( 3 - 1 ) ;
} else if ( V_7 >= 32 ) {
V_7 = ( V_7 & 31 ) + ( 3 - 1 ) ;
if ( F_2 ( V_7 == 2 ) ) {
while ( F_2 ( * V_6 == 0 ) ) {
V_7 += 255 ;
V_6 ++ ;
F_4 ( 1 ) ;
}
V_7 += 31 + * V_6 ++ ;
F_4 ( 2 ) ;
}
V_10 = V_5 - 1 ;
V_8 = F_11 ( V_6 ) ;
V_6 += 2 ;
V_10 -= V_8 >> 2 ;
V_8 &= 3 ;
} else {
V_10 = V_5 ;
V_10 -= ( V_7 & 8 ) << 11 ;
V_7 = ( V_7 & 7 ) + ( 3 - 1 ) ;
if ( F_2 ( V_7 == 2 ) ) {
while ( F_2 ( * V_6 == 0 ) ) {
V_7 += 255 ;
V_6 ++ ;
F_4 ( 1 ) ;
}
V_7 += 7 + * V_6 ++ ;
F_4 ( 2 ) ;
}
V_8 = F_11 ( V_6 ) ;
V_6 += 2 ;
V_10 -= V_8 >> 2 ;
V_8 &= 3 ;
if ( V_10 == V_5 )
goto V_20;
V_10 -= 0x4000 ;
}
F_10 ( V_10 ) ;
#if F_5 ( V_16 )
if ( V_5 - V_10 >= 8 ) {
unsigned char * V_18 = V_5 + V_7 ;
if ( F_3 ( F_7 ( V_7 + 15 ) ) ) {
do {
F_8 ( V_5 , V_10 ) ;
V_5 += 8 ;
V_10 += 8 ;
F_8 ( V_5 , V_10 ) ;
V_5 += 8 ;
V_10 += 8 ;
} while ( V_5 < V_18 );
V_5 = V_18 ;
if ( F_6 ( 6 ) ) {
V_9 = V_8 ;
F_12 ( V_5 , V_6 ) ;
V_5 += V_8 ;
V_6 += V_8 ;
continue;
}
} else {
F_9 ( V_7 ) ;
do {
* V_5 ++ = * V_10 ++ ;
} while ( V_5 < V_18 );
}
} else
#endif
{
unsigned char * V_18 = V_5 + V_7 ;
F_9 ( V_7 ) ;
V_5 [ 0 ] = V_10 [ 0 ] ;
V_5 [ 1 ] = V_10 [ 1 ] ;
V_5 += 2 ;
V_10 += 2 ;
do {
* V_5 ++ = * V_10 ++ ;
} while ( V_5 < V_18 );
}
V_14:
V_9 = V_8 ;
V_7 = V_8 ;
#if F_5 ( V_16 )
if ( F_3 ( F_6 ( 6 ) && F_7 ( 4 ) ) ) {
F_12 ( V_5 , V_6 ) ;
V_5 += V_7 ;
V_6 += V_7 ;
} else
#endif
{
F_4 ( V_7 + 3 ) ;
F_9 ( V_7 ) ;
while ( V_7 > 0 ) {
* V_5 ++ = * V_6 ++ ;
V_7 -- ;
}
}
}
V_20:
* V_4 = V_5 - V_3 ;
return ( V_7 != 3 ? V_21 :
V_6 == V_11 ? V_22 :
V_6 < V_11 ? V_23 : V_24 ) ;
V_13:
* V_4 = V_5 - V_3 ;
return V_24 ;
V_25:
* V_4 = V_5 - V_3 ;
return V_26 ;
V_27:
* V_4 = V_5 - V_3 ;
return V_28 ;
}
