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
if ( V_1 -> V_8 == 0 ) * ( V_7 ++ ) = '0' ;
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
char * F_4 ( const T_1 * V_1 )
{
int V_2 = 0 , V_17 ;
char * V_6 = NULL ;
char * V_7 ;
T_1 * V_18 = NULL ;
T_2 * V_19 = NULL , * V_20 ;
V_2 = F_5 ( V_1 ) * 3 ;
V_17 = ( V_2 / 10 + V_2 / 1000 + 3 ) + 1 ;
V_19 = ( T_2 * ) F_2 ( ( V_17 / V_21 + 1 ) * sizeof( T_2 ) ) ;
V_6 = ( char * ) F_2 ( V_17 + 3 ) ;
if ( ( V_6 == NULL ) || ( V_19 == NULL ) )
{
F_3 ( V_22 , V_11 ) ;
goto V_12;
}
if ( ( V_18 = F_6 ( V_1 ) ) == NULL ) goto V_12;
V_7 = V_6 ;
V_20 = V_19 ;
if ( V_18 -> V_13 ) * ( V_7 ++ ) = '-' ;
if ( V_18 -> V_8 == 0 )
{
* ( V_7 ++ ) = '0' ;
* ( V_7 ++ ) = '\0' ;
}
else
{
V_2 = 0 ;
while ( ! F_7 ( V_18 ) )
{
* V_20 = F_8 ( V_18 , V_23 ) ;
V_20 ++ ;
}
V_20 -- ;
sprintf ( V_7 , V_24 , * V_20 ) ;
while ( * V_7 ) V_7 ++ ;
while ( V_20 != V_19 )
{
V_20 -- ;
sprintf ( V_7 , V_25 , * V_20 ) ;
while ( * V_7 ) V_7 ++ ;
}
}
V_12:
if ( V_19 != NULL ) F_9 ( V_19 ) ;
if ( V_18 != NULL ) F_10 ( V_18 ) ;
return ( V_6 ) ;
}
int F_11 ( T_1 * * V_26 , const char * V_1 )
{
T_1 * V_27 = NULL ;
T_2 V_28 = 0 ;
int V_13 = 0 , V_29 , V_30 , V_2 , V_3 , V_31 , V_32 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) ) return ( 0 ) ;
if ( * V_1 == '-' ) { V_13 = 1 ; V_1 ++ ; }
for ( V_2 = 0 ; isxdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
;
V_17 = V_2 + V_13 ;
if ( V_26 == NULL ) return ( V_17 ) ;
if ( * V_26 == NULL )
{
if ( ( V_27 = F_12 () ) == NULL ) return ( 0 ) ;
}
else
{
V_27 = * V_26 ;
F_13 ( V_27 ) ;
}
if ( F_14 ( V_27 , V_2 * 4 ) == NULL ) goto V_12;
V_3 = V_2 ;
V_30 = 0 ;
V_29 = 0 ;
while ( V_3 > 0 )
{
V_30 = ( ( V_9 * 2 ) <= V_3 ) ? ( V_9 * 2 ) : V_3 ;
V_28 = 0 ;
for (; ; )
{
V_32 = V_1 [ V_3 - V_30 ] ;
if ( ( V_32 >= '0' ) && ( V_32 <= '9' ) ) V_31 = V_32 - '0' ;
else if ( ( V_32 >= 'a' ) && ( V_32 <= 'f' ) ) V_31 = V_32 - 'a' + 10 ;
else if ( ( V_32 >= 'A' ) && ( V_32 <= 'F' ) ) V_31 = V_32 - 'A' + 10 ;
else V_31 = 0 ;
V_28 = ( V_28 << 4 ) | V_31 ;
if ( -- V_30 <= 0 )
{
V_27 -> V_15 [ V_29 ++ ] = V_28 ;
break;
}
}
V_3 -= ( V_9 * 2 ) ;
}
V_27 -> V_8 = V_29 ;
F_15 ( V_27 ) ;
V_27 -> V_13 = V_13 ;
* V_26 = V_27 ;
return ( V_17 ) ;
V_12:
if ( * V_26 == NULL ) F_10 ( V_27 ) ;
return ( 0 ) ;
}
int F_16 ( T_1 * * V_26 , const char * V_1 )
{
T_1 * V_27 = NULL ;
T_2 V_28 = 0 ;
int V_13 = 0 , V_2 , V_3 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) ) return ( 0 ) ;
if ( * V_1 == '-' ) { V_13 = 1 ; V_1 ++ ; }
for ( V_2 = 0 ; isdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
;
V_17 = V_2 + V_13 ;
if ( V_26 == NULL ) return ( V_17 ) ;
if ( * V_26 == NULL )
{
if ( ( V_27 = F_12 () ) == NULL ) return ( 0 ) ;
}
else
{
V_27 = * V_26 ;
F_13 ( V_27 ) ;
}
if ( F_14 ( V_27 , V_2 * 4 ) == NULL ) goto V_12;
V_3 = V_21 - ( V_2 % V_21 ) ;
if ( V_3 == V_21 ) V_3 = 0 ;
V_28 = 0 ;
while ( * V_1 )
{
V_28 *= 10 ;
V_28 += * V_1 - '0' ;
V_1 ++ ;
if ( ++ V_3 == V_21 )
{
F_17 ( V_27 , V_23 ) ;
F_18 ( V_27 , V_28 ) ;
V_28 = 0 ;
V_3 = 0 ;
}
}
V_27 -> V_13 = V_13 ;
F_15 ( V_27 ) ;
* V_26 = V_27 ;
return ( V_17 ) ;
V_12:
if ( * V_26 == NULL ) F_10 ( V_27 ) ;
return ( 0 ) ;
}
int F_19 ( T_3 * V_33 , const T_1 * V_1 )
{
T_4 * V_34 ;
int V_27 ;
if ( ( V_34 = F_20 ( F_21 () ) ) == NULL )
return ( 0 ) ;
F_22 ( V_34 , V_33 , V_35 ) ;
V_27 = F_23 ( V_34 , V_1 ) ;
F_24 ( V_34 ) ;
return ( V_27 ) ;
}
int F_23 ( T_4 * V_36 , const T_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 = 0 ;
int V_27 = 0 ;
if ( ( V_1 -> V_13 ) && ( F_25 ( V_36 , L_1 , 1 ) != 1 ) ) goto V_37;
if ( ( V_1 -> V_8 == 0 ) && ( F_25 ( V_36 , L_2 , 1 ) != 1 ) ) goto V_37;
for ( V_2 = V_1 -> V_8 - 1 ; V_2 >= 0 ; V_2 -- )
{
for ( V_3 = V_14 - 4 ; V_3 >= 0 ; V_3 -= 4 )
{
V_4 = ( ( int ) ( V_1 -> V_15 [ V_2 ] >> ( long ) V_3 ) ) & 0x0f ;
if ( V_5 || ( V_4 != 0 ) )
{
if ( F_25 ( V_36 , & ( V_16 [ V_4 ] ) , 1 ) != 1 )
goto V_37;
V_5 = 1 ;
}
}
}
V_27 = 1 ;
V_37:
return ( V_27 ) ;
}
void F_26 ( T_3 * V_38 , const char * V_1 , const T_2 * V_34 , int V_39 )
{
int V_2 ;
fprintf ( V_38 , L_3 , V_1 ) ;
for ( V_2 = V_39 - 1 ; V_2 >= 0 ; V_2 -- )
fprintf ( V_38 , L_4 , V_34 [ V_2 ] ) ;
fprintf ( V_38 , L_5 ) ;
}
