int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
char * V_4 = NULL ;
int V_5 = 0 ;
char * V_6 = NULL , * V_7 = NULL , * * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
T_1 V_11 = 0 ;
int V_12 = 0 ;
T_2 * V_13 = NULL , * V_14 = NULL ;
int V_15 , V_16 , V_17 ;
int V_18 = 0 , V_19 = 0 , V_20 = 0 , V_21 = 0 ;
int V_22 = 0 , V_23 = 0 , V_24 = 0 ;
T_1 V_25 = 0 ;
F_1 () ;
if ( V_26 == NULL )
if ( ( V_26 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_26 , V_27 , V_28 | V_29 ) ;
V_14 = F_2 ( F_3 () ) ;
if ( V_14 == NULL )
goto V_30;
F_4 ( V_14 , stdout , V_28 | V_29 ) ;
#ifdef F_5
{
T_2 * V_31 = F_2 ( F_6 () ) ;
V_14 = F_7 ( V_31 , V_14 ) ;
}
#endif
V_16 = 0 , V_17 = 0 ;
V_15 = 0 ;
while ( ! V_16 && ! V_17 && V_2 [ ++ V_15 ] != NULL )
{
if ( strcmp ( V_2 [ V_15 ] , L_1 ) == 0 )
V_22 = 1 ;
else if ( strcmp ( V_2 [ V_15 ] , L_2 ) == 0 )
V_23 = 1 ;
else if ( strcmp ( V_2 [ V_15 ] , L_3 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( V_2 [ V_15 ] , L_4 ) == 0 )
{
if ( ( V_2 [ V_15 + 1 ] != NULL ) && ( V_6 == NULL ) )
{
V_18 = 1 ;
V_6 = V_2 [ ++ V_15 ] ;
}
else
V_16 = 1 ;
}
else if ( strcmp ( V_2 [ V_15 ] , L_5 ) == 0 )
{
if ( ( V_2 [ V_15 + 1 ] != NULL ) && ! V_12 )
{
V_12 = 1 ;
V_4 = V_2 [ ++ V_15 ] ;
}
else
V_16 = 1 ;
}
else if ( strcmp ( V_2 [ V_15 ] , L_6 ) == 0 )
{
if ( ! V_12 )
{
V_12 = 1 ;
V_5 = 1 ;
}
else
V_16 = 1 ;
}
else if ( strcmp ( V_2 [ V_15 ] , L_7 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( V_2 [ V_15 ] , L_8 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( V_2 [ V_15 ] , L_9 ) == 0 )
V_21 = 1 ;
else if ( V_2 [ V_15 ] [ 0 ] == '-' )
V_16 = 1 ;
else if ( ! V_12 )
{
V_12 = 1 ;
V_8 = & V_2 [ V_15 ] ;
V_17 = 1 ;
}
else
V_16 = 1 ;
}
if ( ! V_22 && ! V_23 && ! V_24 )
V_22 = 1 ;
if ( V_22 + V_23 + V_24 > 1 )
V_16 = 1 ;
#ifdef F_8
if ( V_22 ) V_16 = 1 ;
#endif
#ifdef F_9
if ( V_23 || V_24 ) V_16 = 1 ;
#endif
if ( V_16 )
{
F_10 ( V_26 , L_10 ) ;
F_10 ( V_26 , L_11 ) ;
#ifndef F_8
F_10 ( V_26 , L_12 ) ;
#endif
#ifndef F_9
F_10 ( V_26 , L_13 ) ;
F_10 ( V_26 , L_14 ) ;
#endif
F_10 ( V_26 , L_15 ) ;
F_10 ( V_26 , L_16 ) ;
F_10 ( V_26 , L_17 ) ;
F_10 ( V_26 , L_18 ) ;
F_10 ( V_26 , L_19 ) ;
F_10 ( V_26 , L_20 ) ;
goto V_30;
}
if ( ( V_4 != NULL ) || V_5 )
{
V_13 = F_2 ( F_3 () ) ;
if ( V_13 == NULL )
goto V_30;
if ( V_4 != NULL )
{
assert ( V_5 == 0 ) ;
if ( F_11 ( V_13 , V_4 ) <= 0 )
goto V_30;
}
else
{
assert ( V_5 ) ;
F_4 ( V_13 , V_32 , V_28 ) ;
}
}
if ( V_22 )
V_25 = 8 ;
else if ( V_23 || V_24 )
V_25 = 256 ;
if ( V_8 == NULL )
{
V_11 = V_25 + 2 ;
V_7 = V_10 = F_12 ( V_11 ) ;
if ( V_10 == NULL )
goto V_30;
}
if ( ( V_13 == NULL ) && ( V_8 == NULL ) )
{
static char * V_33 [ 2 ] = { NULL , NULL } ;
V_8 = V_33 ;
if ( V_13 == NULL )
if ( F_13 ( V_10 , V_11 , L_21 , 0 ) != 0 )
goto V_30;
V_8 [ 0 ] = V_10 ;
}
if ( V_13 == NULL )
{
assert ( V_8 != NULL ) ;
assert ( * V_8 != NULL ) ;
do
{
V_7 = * V_8 ++ ;
if ( ! F_14 ( V_18 , & V_6 , & V_9 , V_7 , V_14 ,
V_19 , V_20 , V_21 , V_25 , V_22 , V_23 , V_24 ) )
goto V_30;
}
while ( * V_8 != NULL );
}
else
{
int V_34 ;
assert ( V_7 != NULL ) ;
do
{
int V_35 = F_15 ( V_13 , V_7 , V_25 + 1 ) ;
if ( V_35 > 0 )
{
char * V_36 = ( strchr ( V_7 , '\n' ) ) ;
if ( V_36 != NULL )
* V_36 = 0 ;
else
{
char V_37 [ V_38 ] ;
do
V_35 = F_15 ( V_13 , V_37 , sizeof V_37 ) ;
while ( ( V_35 > 0 ) && ( ! strchr ( V_37 , '\n' ) ) );
}
if ( ! F_14 ( V_18 , & V_6 , & V_9 , V_7 , V_14 ,
V_19 , V_20 , V_21 , V_25 , V_22 , V_23 , V_24 ) )
goto V_30;
}
V_34 = ( V_35 <= 0 ) ;
}
while ( ! V_34 );
}
V_30:
F_16 ( V_26 ) ;
if ( V_9 )
F_17 ( V_9 ) ;
if ( V_10 )
F_17 ( V_10 ) ;
if ( V_13 )
F_18 ( V_13 ) ;
if ( V_14 )
F_19 ( V_14 ) ;
EXIT ( V_3 ) ;
}
static char * F_20 ( const char * V_7 , const char * V_39 , const char * V_6 )
{
static char V_40 [ 6 + 9 + 24 + 2 ] ;
unsigned char V_41 [ V_42 ] ;
char * V_43 ;
int V_44 , V_15 ;
T_3 V_45 ;
T_1 V_46 , V_47 ;
V_46 = strlen ( V_7 ) ;
V_40 [ 0 ] = '$' ;
V_40 [ 1 ] = 0 ;
assert ( strlen ( V_39 ) <= 4 ) ;
strncat ( V_40 , V_39 , 4 ) ;
strncat ( V_40 , L_22 , 1 ) ;
strncat ( V_40 , V_6 , 8 ) ;
assert ( strlen ( V_40 ) <= 6 + 8 ) ;
V_43 = V_40 + 6 ;
V_47 = strlen ( V_43 ) ;
assert ( V_47 <= 8 ) ;
F_21 ( & V_45 ) ;
F_22 ( & V_45 , V_7 , V_46 ) ;
F_22 ( & V_45 , L_22 , 1 ) ;
F_22 ( & V_45 , V_39 , strlen ( V_39 ) ) ;
F_22 ( & V_45 , L_22 , 1 ) ;
F_22 ( & V_45 , V_43 , V_47 ) ;
{
T_3 V_48 ;
F_21 ( & V_48 ) ;
F_22 ( & V_48 , V_7 , V_46 ) ;
F_22 ( & V_48 , V_43 , V_47 ) ;
F_22 ( & V_48 , V_7 , V_46 ) ;
F_23 ( V_41 , & V_48 ) ;
}
for ( V_15 = V_46 ; V_15 > sizeof V_41 ; V_15 -= sizeof V_41 )
F_22 ( & V_45 , V_41 , sizeof V_41 ) ;
F_22 ( & V_45 , V_41 , V_15 ) ;
V_44 = V_46 ;
while ( V_44 )
{
F_22 ( & V_45 , ( V_44 & 1 ) ? L_23 : V_7 , 1 ) ;
V_44 >>= 1 ;
}
F_23 ( V_41 , & V_45 ) ;
for ( V_15 = 0 ; V_15 < 1000 ; V_15 ++ )
{
T_3 V_48 ;
F_21 ( & V_48 ) ;
F_22 ( & V_48 , ( V_15 & 1 ) ? ( unsigned char * ) V_7 : V_41 ,
( V_15 & 1 ) ? V_46 : sizeof V_41 ) ;
if ( V_15 % 3 )
F_22 ( & V_48 , V_43 , V_47 ) ;
if ( V_15 % 7 )
F_22 ( & V_48 , V_7 , V_46 ) ;
F_22 ( & V_48 , ( V_15 & 1 ) ? V_41 : ( unsigned char * ) V_7 ,
( V_15 & 1 ) ? sizeof V_41 : V_46 ) ;
F_23 ( V_41 , & V_48 ) ;
}
{
unsigned char V_49 [ sizeof V_41 ] ;
int V_50 , V_51 ;
char * V_52 ;
for ( V_50 = 0 , V_51 = 0 ; V_50 < 14 ; V_50 ++ , V_51 = ( V_51 + 6 ) % 17 )
V_49 [ V_50 ] = V_41 [ V_51 ] ;
V_49 [ 14 ] = V_41 [ 5 ] ;
V_49 [ 15 ] = V_41 [ 11 ] ;
#ifndef F_24
assert ( 16 == sizeof V_49 ) ;
#endif
V_52 = V_43 + V_47 ;
assert ( V_52 == V_40 + strlen ( V_40 ) ) ;
* V_52 ++ = '$' ;
for ( V_15 = 0 ; V_15 < 15 ; V_15 += 3 )
{
* V_52 ++ = V_53 [ V_49 [ V_15 + 2 ] & 0x3f ] ;
* V_52 ++ = V_53 [ ( ( V_49 [ V_15 + 1 ] & 0xf ) << 2 ) |
( V_49 [ V_15 + 2 ] >> 6 ) ] ;
* V_52 ++ = V_53 [ ( ( V_49 [ V_15 ] & 3 ) << 4 ) |
( V_49 [ V_15 + 1 ] >> 4 ) ] ;
* V_52 ++ = V_53 [ V_49 [ V_15 ] >> 2 ] ;
}
assert ( V_15 == 15 ) ;
* V_52 ++ = V_53 [ V_49 [ V_15 ] & 0x3f ] ;
* V_52 ++ = V_53 [ V_49 [ V_15 ] >> 6 ] ;
* V_52 = 0 ;
assert ( strlen ( V_40 ) < sizeof( V_40 ) ) ;
}
return V_40 ;
}
static int F_14 ( int V_18 , char * * V_54 , char * * V_55 ,
char * V_7 , T_2 * V_14 , int V_19 , int V_20 , int V_21 ,
T_1 V_25 , int V_22 , int V_23 , int V_24 )
{
char * V_56 = NULL ;
assert ( V_54 != NULL ) ;
assert ( V_55 != NULL ) ;
if ( ! V_18 )
{
#ifndef F_8
if ( V_22 )
{
if ( * V_55 == NULL )
{
* V_54 = * V_55 = F_12 ( 3 ) ;
if ( * V_55 == NULL )
goto V_30;
}
if ( F_25 ( ( unsigned char * ) * V_54 , 2 ) < 0 )
goto V_30;
( * V_54 ) [ 0 ] = V_53 [ ( * V_54 ) [ 0 ] & 0x3f ] ;
( * V_54 ) [ 1 ] = V_53 [ ( * V_54 ) [ 1 ] & 0x3f ] ;
( * V_54 ) [ 2 ] = 0 ;
#ifdef F_26
F_27 ( * V_54 , * V_54 , 2 ) ;
#endif
}
#endif
#ifndef F_9
if ( V_23 || V_24 )
{
int V_15 ;
if ( * V_55 == NULL )
{
* V_54 = * V_55 = F_12 ( 9 ) ;
if ( * V_55 == NULL )
goto V_30;
}
if ( F_25 ( ( unsigned char * ) * V_54 , 8 ) < 0 )
goto V_30;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ )
( * V_54 ) [ V_15 ] = V_53 [ ( * V_54 ) [ V_15 ] & 0x3f ] ;
( * V_54 ) [ 8 ] = 0 ;
}
#endif
}
assert ( * V_54 != NULL ) ;
if ( ( strlen ( V_7 ) > V_25 ) )
{
if ( ! V_19 )
F_10 ( V_26 , L_24 , V_25 ) ;
V_7 [ V_25 ] = 0 ;
}
assert ( strlen ( V_7 ) <= V_25 ) ;
#ifndef F_8
if ( V_22 )
V_56 = F_28 ( V_7 , * V_54 ) ;
#endif
#ifndef F_9
if ( V_23 || V_24 )
V_56 = F_20 ( V_7 , ( V_23 ? L_25 : L_26 ) , * V_54 ) ;
#endif
assert ( V_56 != NULL ) ;
if ( V_20 && ! V_21 )
F_10 ( V_14 , L_27 , V_7 , V_56 ) ;
else if ( V_20 && V_21 )
F_10 ( V_14 , L_27 , V_56 , V_7 ) ;
else
F_10 ( V_14 , L_28 , V_56 ) ;
return 1 ;
V_30:
return 0 ;
}
int MAIN ( int V_1 , char * * V_2 )
{
fputs ( L_29 , stderr)
EXIT ( 1 ) ;
}
