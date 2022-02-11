char * F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 = 0 ;
char * V_6 ;
char * V_7 ;
V_6 = ( char * ) F_2 ( V_1 -> V_8 * V_9 * 2 + 2 ) ;
if ( V_6 == NULL )
{
F_3 ( V_10 , V_11 ) ;
goto V_12;
}
V_7 = V_6 ;
if ( V_1 -> V_13 ) * ( V_7 ++ ) = '-' ;
if ( F_4 ( V_1 ) ) * ( V_7 ++ ) = '0' ;
for ( V_2 = V_1 -> V_8 - 1 ; V_2 >= 0 ; V_2 -- )
{
for ( V_3 = V_14 - 8 ; V_3 >= 0 ; V_3 -= 8 )
{
V_4 = ( ( int ) ( V_1 -> V_15 [ V_2 ] >> ( long ) V_3 ) ) & 0xff ;
if ( V_5 || ( V_4 != 0 ) )
{
* ( V_7 ++ ) = V_16 [ V_4 >> 4 ] ;
* ( V_7 ++ ) = V_16 [ V_4 & 0x0f ] ;
V_5 = 1 ;
}
}
}
* V_7 = '\0' ;
V_12:
return ( V_6 ) ;
}
char * F_5 ( const T_1 * V_1 )
{
int V_2 = 0 , V_17 , V_18 = 0 ;
char * V_6 = NULL ;
char * V_7 ;
T_1 * V_19 = NULL ;
T_2 * V_20 = NULL , * V_21 ;
V_2 = F_6 ( V_1 ) * 3 ;
V_17 = ( V_2 / 10 + V_2 / 1000 + 1 ) + 1 ;
V_20 = ( T_2 * ) F_2 ( ( V_17 / V_22 + 1 ) * sizeof( T_2 ) ) ;
V_6 = ( char * ) F_2 ( V_17 + 3 ) ;
if ( ( V_6 == NULL ) || ( V_20 == NULL ) )
{
F_3 ( V_23 , V_11 ) ;
goto V_12;
}
if ( ( V_19 = F_7 ( V_1 ) ) == NULL ) goto V_12;
#define F_8 (num+3 - (size_t)(p - buf))
V_7 = V_6 ;
V_21 = V_20 ;
if ( F_4 ( V_19 ) )
{
* ( V_7 ++ ) = '0' ;
* ( V_7 ++ ) = '\0' ;
}
else
{
if ( F_9 ( V_19 ) )
* V_7 ++ = '-' ;
V_2 = 0 ;
while ( ! F_4 ( V_19 ) )
{
* V_21 = F_10 ( V_19 , V_24 ) ;
V_21 ++ ;
}
V_21 -- ;
F_11 ( V_7 , F_8 , V_25 , * V_21 ) ;
while ( * V_7 ) V_7 ++ ;
while ( V_21 != V_20 )
{
V_21 -- ;
F_11 ( V_7 , F_8 , V_26 , * V_21 ) ;
while ( * V_7 ) V_7 ++ ;
}
}
V_18 = 1 ;
V_12:
if ( V_20 != NULL ) F_12 ( V_20 ) ;
if ( V_19 != NULL ) F_13 ( V_19 ) ;
if ( ! V_18 && V_6 )
{
F_12 ( V_6 ) ;
V_6 = NULL ;
}
return ( V_6 ) ;
}
int F_14 ( T_1 * * V_27 , const char * V_1 )
{
T_1 * V_28 = NULL ;
T_2 V_29 = 0 ;
int V_13 = 0 , V_30 , V_31 , V_2 , V_3 , V_32 , V_33 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) ) return ( 0 ) ;
if ( * V_1 == '-' ) { V_13 = 1 ; V_1 ++ ; }
for ( V_2 = 0 ; isxdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
;
V_17 = V_2 + V_13 ;
if ( V_27 == NULL ) return ( V_17 ) ;
if ( * V_27 == NULL )
{
if ( ( V_28 = F_15 () ) == NULL ) return ( 0 ) ;
}
else
{
V_28 = * V_27 ;
F_16 ( V_28 ) ;
}
if ( F_17 ( V_28 , V_2 * 4 ) == NULL ) goto V_12;
V_3 = V_2 ;
V_31 = 0 ;
V_30 = 0 ;
while ( V_3 > 0 )
{
V_31 = ( ( V_9 * 2 ) <= V_3 ) ? ( V_9 * 2 ) : V_3 ;
V_29 = 0 ;
for (; ; )
{
V_33 = V_1 [ V_3 - V_31 ] ;
if ( ( V_33 >= '0' ) && ( V_33 <= '9' ) ) V_32 = V_33 - '0' ;
else if ( ( V_33 >= 'a' ) && ( V_33 <= 'f' ) ) V_32 = V_33 - 'a' + 10 ;
else if ( ( V_33 >= 'A' ) && ( V_33 <= 'F' ) ) V_32 = V_33 - 'A' + 10 ;
else V_32 = 0 ;
V_29 = ( V_29 << 4 ) | V_32 ;
if ( -- V_31 <= 0 )
{
V_28 -> V_15 [ V_30 ++ ] = V_29 ;
break;
}
}
V_3 -= ( V_9 * 2 ) ;
}
V_28 -> V_8 = V_30 ;
F_18 ( V_28 ) ;
V_28 -> V_13 = V_13 ;
* V_27 = V_28 ;
F_19 ( V_28 ) ;
return ( V_17 ) ;
V_12:
if ( * V_27 == NULL ) F_13 ( V_28 ) ;
return ( 0 ) ;
}
int F_20 ( T_1 * * V_27 , const char * V_1 )
{
T_1 * V_28 = NULL ;
T_2 V_29 = 0 ;
int V_13 = 0 , V_2 , V_3 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) ) return ( 0 ) ;
if ( * V_1 == '-' ) { V_13 = 1 ; V_1 ++ ; }
for ( V_2 = 0 ; isdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
;
V_17 = V_2 + V_13 ;
if ( V_27 == NULL ) return ( V_17 ) ;
if ( * V_27 == NULL )
{
if ( ( V_28 = F_15 () ) == NULL ) return ( 0 ) ;
}
else
{
V_28 = * V_27 ;
F_16 ( V_28 ) ;
}
if ( F_17 ( V_28 , V_2 * 4 ) == NULL ) goto V_12;
V_3 = V_22 - ( V_2 % V_22 ) ;
if ( V_3 == V_22 ) V_3 = 0 ;
V_29 = 0 ;
while ( * V_1 )
{
V_29 *= 10 ;
V_29 += * V_1 - '0' ;
V_1 ++ ;
if ( ++ V_3 == V_22 )
{
F_21 ( V_28 , V_24 ) ;
F_22 ( V_28 , V_29 ) ;
V_29 = 0 ;
V_3 = 0 ;
}
}
V_28 -> V_13 = V_13 ;
F_18 ( V_28 ) ;
* V_27 = V_28 ;
F_19 ( V_28 ) ;
return ( V_17 ) ;
V_12:
if ( * V_27 == NULL ) F_13 ( V_28 ) ;
return ( 0 ) ;
}
int F_23 ( T_3 * V_34 , const T_1 * V_1 )
{
T_4 * V_35 ;
int V_28 ;
if ( ( V_35 = F_24 ( F_25 () ) ) == NULL )
return ( 0 ) ;
F_26 ( V_35 , V_34 , V_36 ) ;
V_28 = F_27 ( V_35 , V_1 ) ;
F_28 ( V_35 ) ;
return ( V_28 ) ;
}
int F_27 ( T_4 * V_37 , const T_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 = 0 ;
int V_28 = 0 ;
if ( ( V_1 -> V_13 ) && ( F_29 ( V_37 , L_1 , 1 ) != 1 ) ) goto V_38;
if ( F_4 ( V_1 ) && ( F_29 ( V_37 , L_2 , 1 ) != 1 ) ) goto V_38;
for ( V_2 = V_1 -> V_8 - 1 ; V_2 >= 0 ; V_2 -- )
{
for ( V_3 = V_14 - 4 ; V_3 >= 0 ; V_3 -= 4 )
{
V_4 = ( ( int ) ( V_1 -> V_15 [ V_2 ] >> ( long ) V_3 ) ) & 0x0f ;
if ( V_5 || ( V_4 != 0 ) )
{
if ( F_29 ( V_37 , & ( V_16 [ V_4 ] ) , 1 ) != 1 )
goto V_38;
V_5 = 1 ;
}
}
}
V_28 = 1 ;
V_38:
return ( V_28 ) ;
}
