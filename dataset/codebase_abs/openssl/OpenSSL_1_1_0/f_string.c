int F_1 ( T_1 * V_1 , const T_2 * V_2 , int type )
{
int V_3 , V_4 = 0 ;
static const char * V_5 = L_1 ;
char V_6 [ 2 ] ;
if ( V_2 == NULL )
return ( 0 ) ;
if ( V_2 -> V_7 == 0 ) {
if ( F_2 ( V_1 , L_2 , 1 ) != 1 )
goto V_8;
V_4 = 1 ;
} else {
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
if ( ( V_3 != 0 ) && ( V_3 % 35 == 0 ) ) {
if ( F_2 ( V_1 , L_3 , 2 ) != 2 )
goto V_8;
V_4 += 2 ;
}
V_6 [ 0 ] = V_5 [ ( ( unsigned char ) V_2 -> V_9 [ V_3 ] >> 4 ) & 0x0f ] ;
V_6 [ 1 ] = V_5 [ ( ( unsigned char ) V_2 -> V_9 [ V_3 ] ) & 0x0f ] ;
if ( F_2 ( V_1 , V_6 , 2 ) != 2 )
goto V_8;
V_4 += 2 ;
}
}
return ( V_4 ) ;
V_8:
return ( - 1 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_10 , char * V_6 , int V_11 )
{
int V_3 , V_12 , V_13 , V_14 , V_4 , V_15 , V_16 , V_17 ;
unsigned char * V_18 = NULL , * V_19 ;
unsigned char * V_20 ;
int V_21 = 0 , V_22 = 0 , V_23 = 1 ;
V_16 = F_4 ( V_1 , V_6 , V_11 ) ;
for (; ; ) {
if ( V_16 < 1 ) {
if ( V_23 )
break;
else
goto V_8;
}
V_23 = 0 ;
V_3 = V_16 ;
if ( V_6 [ V_3 - 1 ] == '\n' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_8;
if ( V_6 [ V_3 - 1 ] == '\r' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_8;
V_15 = ( V_6 [ V_3 - 1 ] == '\\' ) ;
for ( V_12 = V_3 - 1 ; V_12 > 0 ; V_12 -- ) {
#ifndef F_5
V_17 = ( ! ( ( ( V_6 [ V_12 ] >= '0' ) && ( V_6 [ V_12 ] <= '9' ) ) ||
( ( V_6 [ V_12 ] >= 'a' ) && ( V_6 [ V_12 ] <= 'f' ) ) ||
( ( V_6 [ V_12 ] >= 'A' ) && ( V_6 [ V_12 ] <= 'F' ) ) ) ) ;
#else
V_17 = ( ! isxdigit ( V_6 [ V_12 ] ) ) ;
#endif
if ( V_17 ) {
V_3 = V_12 ;
break;
}
}
V_6 [ V_3 ] = '\0' ;
if ( V_3 < 2 )
goto V_8;
V_20 = ( unsigned char * ) V_6 ;
V_13 = 0 ;
V_3 -= V_15 ;
if ( V_3 % 2 != 0 ) {
F_6 ( V_24 , V_25 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
V_3 /= 2 ;
if ( V_21 + V_3 > V_22 ) {
V_19 = F_8 ( V_18 , ( unsigned int ) V_21 + V_3 * 2 ) ;
if ( V_19 == NULL ) {
F_6 ( V_24 , V_26 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
V_18 = V_19 ;
V_22 = V_21 + V_3 * 2 ;
}
for ( V_12 = 0 ; V_12 < V_3 ; V_12 ++ , V_13 += 2 ) {
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_14 = F_9 ( V_20 [ V_13 + V_4 ] ) ;
if ( V_14 < 0 ) {
F_6 ( V_24 ,
V_27 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
V_18 [ V_21 + V_12 ] <<= 4 ;
V_18 [ V_21 + V_12 ] |= V_14 ;
}
}
V_21 += V_3 ;
if ( V_15 )
V_16 = F_4 ( V_1 , V_6 , V_11 ) ;
else
break;
}
V_10 -> V_7 = V_21 ;
V_10 -> V_9 = V_18 ;
return 1 ;
V_8:
F_6 ( V_24 , V_28 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
