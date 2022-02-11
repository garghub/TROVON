int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 , V_4 = 0 ;
static const char * V_5 = L_1 ;
char V_6 [ 2 ] ;
if ( V_2 == NULL ) return ( 0 ) ;
if ( V_2 -> V_7 == 0 )
{
if ( F_2 ( V_1 , L_2 , 2 ) != 2 ) goto V_8;
V_4 = 2 ;
}
else
{
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ )
{
if ( ( V_3 != 0 ) && ( V_3 % 35 == 0 ) )
{
if ( F_2 ( V_1 , L_3 , 2 ) != 2 ) goto V_8;
V_4 += 2 ;
}
V_6 [ 0 ] = V_5 [ ( ( unsigned char ) V_2 -> V_9 [ V_3 ] >> 4 ) & 0x0f ] ;
V_6 [ 1 ] = V_5 [ ( ( unsigned char ) V_2 -> V_9 [ V_3 ] ) & 0x0f ] ;
if ( F_2 ( V_1 , V_6 , 2 ) != 2 ) goto V_8;
V_4 += 2 ;
}
}
return ( V_4 ) ;
V_8:
return ( - 1 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_10 , char * V_6 , int V_11 )
{
int V_12 = 0 ;
int V_3 , V_13 , V_14 , V_15 , V_4 , V_16 , V_17 ;
unsigned char * V_18 = NULL , * V_19 ;
unsigned char * V_20 ;
int V_21 = 0 , V_22 = 0 , V_23 = 1 ;
V_10 -> type = V_24 ;
V_17 = F_4 ( V_1 , V_6 , V_11 ) ;
for (; ; )
{
if ( V_17 < 1 ) goto V_25;
V_3 = V_17 ;
if ( V_6 [ V_3 - 1 ] == '\n' ) V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 ) goto V_25;
if ( V_6 [ V_3 - 1 ] == '\r' ) V_6 [ -- V_3 ] = '\0' ;
if ( V_3 == 0 ) goto V_25;
V_16 = ( V_6 [ V_3 - 1 ] == '\\' ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ )
{
if ( ! ( ( ( V_6 [ V_13 ] >= '0' ) && ( V_6 [ V_13 ] <= '9' ) ) ||
( ( V_6 [ V_13 ] >= 'a' ) && ( V_6 [ V_13 ] <= 'f' ) ) ||
( ( V_6 [ V_13 ] >= 'A' ) && ( V_6 [ V_13 ] <= 'F' ) ) ) )
{
V_3 = V_13 ;
break;
}
}
V_6 [ V_3 ] = '\0' ;
if ( V_3 < 2 ) goto V_25;
V_20 = ( unsigned char * ) V_6 ;
if ( V_23 )
{
V_23 = 0 ;
if ( ( V_20 [ 0 ] == '0' ) && ( V_6 [ 1 ] == '0' ) )
{
V_20 += 2 ;
V_3 -= 2 ;
}
}
V_14 = 0 ;
V_3 -= V_16 ;
if ( V_3 % 2 != 0 )
{
F_5 ( V_26 , V_27 ) ;
goto V_8;
}
V_3 /= 2 ;
if ( V_21 + V_3 > V_22 )
{
if ( V_18 == NULL )
V_19 = ( unsigned char * ) F_6 (
( unsigned int ) V_21 + V_3 * 2 ) ;
else
V_19 = ( unsigned char * ) F_7 ( V_18 ,
( unsigned int ) V_21 + V_3 * 2 ) ;
if ( V_19 == NULL )
{
F_5 ( V_26 , V_28 ) ;
if ( V_18 != NULL ) F_8 ( V_18 ) ;
goto V_8;
}
V_18 = V_19 ;
V_22 = V_21 + V_3 * 2 ;
}
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ , V_14 += 2 )
{
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ )
{
V_15 = V_20 [ V_14 + V_4 ] ;
if ( ( V_15 >= '0' ) && ( V_15 <= '9' ) )
V_15 -= '0' ;
else if ( ( V_15 >= 'a' ) && ( V_15 <= 'f' ) )
V_15 = V_15 - 'a' + 10 ;
else if ( ( V_15 >= 'A' ) && ( V_15 <= 'F' ) )
V_15 = V_15 - 'A' + 10 ;
else
{
F_5 ( V_26 , V_29 ) ;
goto V_8;
}
V_18 [ V_21 + V_13 ] <<= 4 ;
V_18 [ V_21 + V_13 ] |= V_15 ;
}
}
V_21 += V_3 ;
if ( V_16 )
V_17 = F_4 ( V_1 , V_6 , V_11 ) ;
else
break;
}
V_10 -> V_7 = V_21 ;
V_10 -> V_9 = V_18 ;
V_12 = 1 ;
V_8:
if ( 0 )
{
V_25:
F_5 ( V_26 , V_30 ) ;
}
return ( V_12 ) ;
}
