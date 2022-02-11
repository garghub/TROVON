int F_1 ( T_1 * V_1 , const T_2 * V_2 )
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
int V_3 , V_13 , V_14 , V_15 , V_4 , V_16 , V_17 ;
unsigned char * V_18 = NULL , * V_19 ;
unsigned char * V_20 ;
int V_21 = 0 , V_22 = 0 , V_23 = 1 ;
V_11 -> type = V_24 ;
V_17 = F_4 ( V_1 , V_6 , V_12 ) ;
for (; ; ) {
if ( V_17 < 1 )
goto V_8;
V_3 = V_17 ;
if ( V_6 [ V_3 - 1 ] == '\n' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_8;
if ( V_6 [ V_3 - 1 ] == '\r' )
V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 )
goto V_8;
V_16 = ( V_6 [ V_3 - 1 ] == '\\' ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
#ifndef F_5
if ( ! ( ( ( V_6 [ V_13 ] >= '0' ) && ( V_6 [ V_13 ] <= '9' ) ) ||
( ( V_6 [ V_13 ] >= 'a' ) && ( V_6 [ V_13 ] <= 'f' ) ) ||
( ( V_6 [ V_13 ] >= 'A' ) && ( V_6 [ V_13 ] <= 'F' ) ) ) )
#else
if ( ! isxdigit ( V_6 [ V_13 ] ) )
#endif
{
V_3 = V_13 ;
break;
}
}
V_6 [ V_3 ] = '\0' ;
if ( V_3 < 2 )
goto V_8;
V_20 = ( unsigned char * ) V_6 ;
if ( V_23 ) {
V_23 = 0 ;
if ( ( V_20 [ 0 ] == '0' ) && ( V_6 [ 1 ] == '0' ) ) {
V_20 += 2 ;
V_3 -= 2 ;
}
}
V_14 = 0 ;
V_3 -= V_16 ;
if ( V_3 % 2 != 0 ) {
F_6 ( V_25 , V_26 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
V_3 /= 2 ;
if ( V_21 + V_3 > V_22 ) {
V_19 = F_8 ( V_18 , V_22 , V_21 + V_3 * 2 ) ;
if ( V_19 == NULL ) {
F_6 ( V_25 , V_27 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
V_18 = V_19 ;
V_22 = V_21 + V_3 * 2 ;
}
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ , V_14 += 2 ) {
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_15 = F_9 ( V_20 [ V_14 + V_4 ] ) ;
if ( V_15 < 0 ) {
F_6 ( V_25 ,
V_28 ) ;
goto V_8;
}
V_18 [ V_21 + V_13 ] <<= 4 ;
V_18 [ V_21 + V_13 ] |= V_15 ;
}
}
V_21 += V_3 ;
if ( V_16 )
V_17 = F_4 ( V_1 , V_6 , V_12 ) ;
else
break;
}
V_11 -> V_9 = V_21 ;
V_11 -> V_10 = V_18 ;
return 1 ;
V_8:
F_6 ( V_25 , V_29 ) ;
F_7 ( V_18 ) ;
return 0 ;
}
int F_10 ( T_1 * V_1 , const T_3 * V_2 )
{
return F_1 ( V_1 , V_2 ) ;
}
int F_11 ( T_1 * V_1 , T_3 * V_11 , char * V_6 , int V_12 )
{
int V_30 = F_3 ( V_1 , V_11 , V_6 , V_12 ) ;
if ( V_30 == 1 )
V_11 -> type = V_24 | ( V_11 -> type & V_7 ) ;
return V_30 ;
}
