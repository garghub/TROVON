int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 , V_4 = 0 ;
static const char * V_5 = L_1 ;
char V_6 [ 2 ] ;
if ( V_2 == NULL )
return ( 0 ) ;
if ( V_2 -> type & V_7 ) {
if ( F_2 ( V_1 , L_2 , 1 ) != 1 )
goto V_8;
V_4 = 1 ;
}
if ( V_2 -> V_9 == 0 ) {
if ( F_2 ( V_1 , L_3 , 2 ) != 2 )
goto V_8;
V_4 += 2 ;
} else {
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
if ( ( V_3 != 0 ) && ( V_3 % 35 == 0 ) ) {
if ( F_2 ( V_1 , L_4 , 2 ) != 2 )
goto V_8;
V_4 += 2 ;
}
V_6 [ 0 ] = V_5 [ ( ( unsigned char ) V_2 -> V_10 [ V_3 ] >> 4 ) & 0x0f ] ;
V_6 [ 1 ] = V_5 [ ( ( unsigned char ) V_2 -> V_10 [ V_3 ] ) & 0x0f ] ;
if ( F_2 ( V_1 , V_6 , 2 ) != 2 )
goto V_8;
V_4 += 2 ;
}
}
return ( V_4 ) ;
V_8:
return ( - 1 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_11 , char * V_6 , int V_12 )
{
int V_13 = 0 ;
int V_3 , V_14 , V_15 , V_16 , V_4 , V_17 , V_18 ;
unsigned char * V_19 = NULL , * V_20 ;
unsigned char * V_21 ;
int V_22 = 0 , V_23 = 0 , V_24 = 1 ;
V_11 -> type = V_25 ;
V_18 = F_4 ( V_1 , V_6 , V_12 ) ;
for (; ; ) {
if ( V_18 < 1 )
goto V_26;
V_3 = V_18 ;
if ( V_6 [ V_3 - 1 ] == '\n' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_26;
if ( V_6 [ V_3 - 1 ] == '\r' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_26;
V_17 = ( V_6 [ V_3 - 1 ] == '\\' ) ;
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ ) {
#ifndef F_5
if ( ! ( ( ( V_6 [ V_14 ] >= '0' ) && ( V_6 [ V_14 ] <= '9' ) ) ||
( ( V_6 [ V_14 ] >= 'a' ) && ( V_6 [ V_14 ] <= 'f' ) ) ||
( ( V_6 [ V_14 ] >= 'A' ) && ( V_6 [ V_14 ] <= 'F' ) ) ) )
#else
if ( ! isxdigit ( V_6 [ V_14 ] ) )
#endif
{
V_3 = V_14 ;
break;
}
}
V_6 [ V_3 ] = '\0' ;
if ( V_3 < 2 )
goto V_26;
V_21 = ( unsigned char * ) V_6 ;
if ( V_24 ) {
V_24 = 0 ;
if ( ( V_21 [ 0 ] == '0' ) && ( V_6 [ 1 ] == '0' ) ) {
V_21 += 2 ;
V_3 -= 2 ;
}
}
V_15 = 0 ;
V_3 -= V_17 ;
if ( V_3 % 2 != 0 ) {
F_6 ( V_27 , V_28 ) ;
goto V_8;
}
V_3 /= 2 ;
if ( V_22 + V_3 > V_23 ) {
if ( V_19 == NULL )
V_20 = ( unsigned char * ) F_7 ( ( unsigned int ) V_22 +
V_3 * 2 ) ;
else
V_20 = F_8 ( V_19 , V_23 , V_22 + V_3 * 2 ) ;
if ( V_20 == NULL ) {
F_6 ( V_27 , V_29 ) ;
if ( V_19 != NULL )
F_9 ( V_19 ) ;
goto V_8;
}
V_19 = V_20 ;
V_23 = V_22 + V_3 * 2 ;
}
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ , V_15 += 2 ) {
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_16 = V_21 [ V_15 + V_4 ] ;
if ( ( V_16 >= '0' ) && ( V_16 <= '9' ) )
V_16 -= '0' ;
else if ( ( V_16 >= 'a' ) && ( V_16 <= 'f' ) )
V_16 = V_16 - 'a' + 10 ;
else if ( ( V_16 >= 'A' ) && ( V_16 <= 'F' ) )
V_16 = V_16 - 'A' + 10 ;
else {
F_6 ( V_27 ,
V_30 ) ;
goto V_8;
}
V_19 [ V_22 + V_14 ] <<= 4 ;
V_19 [ V_22 + V_14 ] |= V_16 ;
}
}
V_22 += V_3 ;
if ( V_17 )
V_18 = F_4 ( V_1 , V_6 , V_12 ) ;
else
break;
}
V_11 -> V_9 = V_22 ;
V_11 -> V_10 = V_19 ;
V_13 = 1 ;
V_8:
if ( 0 ) {
V_26:
F_6 ( V_27 , V_31 ) ;
}
return ( V_13 ) ;
}
