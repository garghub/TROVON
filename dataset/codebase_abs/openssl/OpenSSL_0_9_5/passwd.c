int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
char * V_4 = NULL ;
int V_5 = 0 ;
char * V_6 = NULL , * V_7 = NULL , * * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
int V_11 = 0 ;
T_1 * V_12 = NULL , * V_13 = NULL ;
int V_14 , V_15 , V_16 ;
int V_17 = 0 , V_18 = 0 , V_19 = 0 , V_20 = 0 ;
int V_21 = 0 , V_22 = 0 ;
T_2 V_23 = 0 ;
F_1 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_24 , V_25 , V_26 | V_27 ) ;
V_13 = F_2 ( F_3 () ) ;
if ( V_13 == NULL )
goto V_28;
F_4 ( V_13 , stdout , V_26 | V_27 ) ;
V_15 = 0 , V_16 = 0 ;
V_14 = 0 ;
while ( ! V_15 && ! V_16 && V_2 [ ++ V_14 ] != NULL )
{
if ( strcmp ( V_2 [ V_14 ] , L_1 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( V_2 [ V_14 ] , L_2 ) == 0 )
V_22 = 1 ;
else if ( strcmp ( V_2 [ V_14 ] , L_3 ) == 0 )
{
if ( ( V_2 [ V_14 + 1 ] != NULL ) && ( V_6 == NULL ) )
{
V_17 = 1 ;
V_6 = V_2 [ ++ V_14 ] ;
}
else
V_15 = 1 ;
}
else if ( strcmp ( V_2 [ V_14 ] , L_4 ) == 0 )
{
if ( ( V_2 [ V_14 + 1 ] != NULL ) && ! V_11 )
{
V_11 = 1 ;
V_4 = V_2 [ ++ V_14 ] ;
}
else
V_15 = 1 ;
}
else if ( strcmp ( V_2 [ V_14 ] , L_5 ) == 0 )
{
if ( ! V_11 )
{
V_11 = 1 ;
V_5 = 1 ;
}
else
V_15 = 1 ;
}
else if ( strcmp ( V_2 [ V_14 ] , L_6 ) == 0 )
V_18 = 1 ;
else if ( strcmp ( V_2 [ V_14 ] , L_7 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( V_2 [ V_14 ] , L_8 ) == 0 )
V_20 = 1 ;
else if ( V_2 [ V_14 ] [ 0 ] == '-' )
V_15 = 1 ;
else if ( ! V_11 )
{
V_11 = 1 ;
V_8 = & V_2 [ V_14 ] ;
V_16 = 1 ;
}
else
V_15 = 1 ;
}
if ( ! V_21 && ! V_22 )
V_21 = 1 ;
if ( V_21 + V_22 > 1 )
V_15 = 1 ;
#ifdef F_5
if ( V_21 ) V_15 = 1 ;
#endif
#ifdef F_6
if ( V_22 ) V_15 = 1 ;
#endif
if ( V_15 )
{
F_7 ( V_24 , L_9 ) ;
F_7 ( V_24 , L_10 ) ;
#ifndef F_5
F_7 ( V_24 , L_11 ) ;
#endif
#ifndef F_6
F_7 ( V_24 , L_12 ) ;
#endif
F_7 ( V_24 , L_13 ) ;
F_7 ( V_24 , L_14 ) ;
F_7 ( V_24 , L_15 ) ;
F_7 ( V_24 , L_16 ) ;
F_7 ( V_24 , L_17 ) ;
F_7 ( V_24 , L_18 ) ;
goto V_28;
}
if ( ( V_4 != NULL ) || V_5 )
{
V_12 = F_2 ( F_3 () ) ;
if ( V_12 == NULL )
goto V_28;
if ( V_4 != NULL )
{
assert ( V_5 == 0 ) ;
if ( F_8 ( V_12 , V_4 ) <= 0 )
goto V_28;
}
else
{
assert ( V_5 ) ;
F_4 ( V_12 , V_29 , V_26 ) ;
}
}
if ( V_21 )
V_23 = 8 ;
else if ( V_22 )
V_23 = 256 ;
if ( V_8 == NULL )
{
V_7 = V_10 = Malloc ( V_23 + 1 ) ;
if ( V_10 == NULL )
goto V_28;
}
if ( ( V_12 == NULL ) && ( V_8 == NULL ) )
{
static char * V_30 [ 2 ] = { NULL , NULL } ;
V_8 = V_30 ;
if ( V_12 == NULL )
if ( F_9 ( V_10 , V_23 + 1 , L_19 , 0 ) != 0 )
goto V_28;
V_8 [ 0 ] = V_10 ;
}
if ( V_12 == NULL )
{
assert ( V_8 != NULL ) ;
assert ( * V_8 != NULL ) ;
do
{
V_7 = * V_8 ++ ;
if ( ! F_10 ( V_17 , & V_6 , & V_9 , V_7 , V_13 ,
V_18 , V_19 , V_20 , V_23 , V_21 , V_22 ) )
goto V_28;
}
while ( * V_8 != NULL );
}
else
{
int V_31 ;
assert ( V_7 != NULL ) ;
do
{
int V_32 = F_11 ( V_12 , V_7 , V_23 + 1 ) ;
if ( V_32 > 0 )
{
char * V_33 = ( strchr ( V_7 , '\n' ) ) ;
if ( V_33 != NULL )
* V_33 = 0 ;
else
{
char V_34 [ V_35 ] ;
do
V_32 = F_11 ( V_12 , V_34 , sizeof V_34 ) ;
while ( ( V_32 > 0 ) && ( ! strchr ( V_34 , '\n' ) ) );
}
if ( ! F_10 ( V_17 , & V_6 , & V_9 , V_7 , V_13 ,
V_18 , V_19 , V_20 , V_23 , V_21 , V_22 ) )
goto V_28;
}
V_31 = ( V_32 <= 0 ) ;
}
while ( ! V_31 );
}
V_28:
F_12 ( V_24 ) ;
if ( V_9 )
Free ( V_9 ) ;
if ( V_10 )
Free ( V_10 ) ;
if ( V_12 )
F_13 ( V_12 ) ;
if ( V_13 )
F_13 ( V_13 ) ;
EXIT ( V_3 ) ;
}
static char * F_14 ( const char * V_7 , const char * V_6 )
{
static char V_36 [ 6 + 9 + 24 + 2 ] ;
unsigned char V_37 [ V_38 ] ;
char * V_39 ;
int V_40 , V_14 ;
T_3 V_41 ;
T_2 V_42 , V_43 ;
V_42 = strlen ( V_7 ) ;
strcpy ( V_36 , L_20 ) ;
strncat ( V_36 , V_6 , 8 ) ;
assert ( strlen ( V_36 ) <= 6 + 8 ) ;
V_39 = V_36 + 6 ;
V_43 = strlen ( V_39 ) ;
assert ( V_43 <= 8 ) ;
F_15 ( & V_41 ) ;
F_16 ( & V_41 , V_7 , V_42 ) ;
F_16 ( & V_41 , L_20 , 6 ) ;
F_16 ( & V_41 , V_39 , V_43 ) ;
{
T_3 V_44 ;
F_15 ( & V_44 ) ;
F_16 ( & V_44 , V_7 , V_42 ) ;
F_16 ( & V_44 , V_39 , V_43 ) ;
F_16 ( & V_44 , V_7 , V_42 ) ;
F_17 ( V_37 , & V_44 ) ;
}
for ( V_14 = V_42 ; V_14 > sizeof V_37 ; V_14 -= sizeof V_37 )
F_16 ( & V_41 , V_37 , sizeof V_37 ) ;
F_16 ( & V_41 , V_37 , V_14 ) ;
V_40 = V_42 ;
while ( V_40 )
{
F_16 ( & V_41 , ( V_40 & 1 ) ? L_21 : V_7 , 1 ) ;
V_40 >>= 1 ;
}
F_17 ( V_37 , & V_41 ) ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ )
{
T_3 V_44 ;
F_15 ( & V_44 ) ;
F_16 ( & V_44 , ( V_14 & 1 ) ? ( unsigned char * ) V_7 : V_37 ,
( V_14 & 1 ) ? V_42 : sizeof V_37 ) ;
if ( V_14 % 3 )
F_16 ( & V_44 , V_39 , V_43 ) ;
if ( V_14 % 7 )
F_16 ( & V_44 , V_7 , V_42 ) ;
F_16 ( & V_44 , ( V_14 & 1 ) ? V_37 : ( unsigned char * ) V_7 ,
( V_14 & 1 ) ? sizeof V_37 : V_42 ) ;
F_17 ( V_37 , & V_44 ) ;
}
{
unsigned char V_45 [ sizeof V_37 ] ;
int V_46 , V_47 ;
char * V_48 ;
for ( V_46 = 0 , V_47 = 0 ; V_46 < 14 ; V_46 ++ , V_47 = ( V_47 + 6 ) % 17 )
V_45 [ V_46 ] = V_37 [ V_47 ] ;
V_45 [ 14 ] = V_37 [ 5 ] ;
V_45 [ 15 ] = V_37 [ 11 ] ;
#ifndef F_18
assert ( 16 == sizeof V_45 ) ;
#endif
V_48 = V_39 + V_43 ;
assert ( V_48 == V_36 + strlen ( V_36 ) ) ;
* V_48 ++ = '$' ;
for ( V_14 = 0 ; V_14 < 15 ; V_14 += 3 )
{
* V_48 ++ = V_49 [ V_45 [ V_14 + 2 ] & 0x3f ] ;
* V_48 ++ = V_49 [ ( ( V_45 [ V_14 + 1 ] & 0xf ) << 2 ) |
( V_45 [ V_14 + 2 ] >> 6 ) ] ;
* V_48 ++ = V_49 [ ( ( V_45 [ V_14 ] & 3 ) << 4 ) |
( V_45 [ V_14 + 1 ] >> 4 ) ] ;
* V_48 ++ = V_49 [ V_45 [ V_14 ] >> 2 ] ;
}
assert ( V_14 == 15 ) ;
* V_48 ++ = V_49 [ V_45 [ V_14 ] & 0x3f ] ;
* V_48 ++ = V_49 [ V_45 [ V_14 ] >> 6 ] ;
* V_48 = 0 ;
assert ( strlen ( V_36 ) < sizeof( V_36 ) ) ;
}
return V_36 ;
}
static int F_10 ( int V_17 , char * * V_50 , char * * V_51 ,
char * V_7 , T_1 * V_13 , int V_18 , int V_19 , int V_20 ,
T_2 V_23 , int V_21 , int V_22 )
{
char * V_52 = NULL ;
assert ( V_50 != NULL ) ;
assert ( V_51 != NULL ) ;
if ( ! V_17 )
{
#ifndef F_5
if ( V_21 )
{
if ( * V_51 == NULL )
{
* V_50 = * V_51 = Malloc ( 3 ) ;
if ( * V_51 == NULL )
goto V_28;
}
if ( F_19 ( ( unsigned char * ) * V_50 , 2 ) < 0 )
goto V_28;
( * V_50 ) [ 0 ] = V_49 [ ( * V_50 ) [ 0 ] & 0x3f ] ;
( * V_50 ) [ 1 ] = V_49 [ ( * V_50 ) [ 1 ] & 0x3f ] ;
( * V_50 ) [ 2 ] = 0 ;
#ifdef F_20
F_21 ( * V_50 , * V_50 , 2 ) ;
#endif
}
#endif
#ifndef F_6
if ( V_22 )
{
int V_14 ;
if ( * V_51 == NULL )
{
* V_50 = * V_51 = Malloc ( 9 ) ;
if ( * V_51 == NULL )
goto V_28;
}
if ( F_19 ( ( unsigned char * ) * V_50 , 8 ) < 0 )
goto V_28;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ )
( * V_50 ) [ V_14 ] = V_49 [ ( * V_50 ) [ V_14 ] & 0x3f ] ;
( * V_50 ) [ 8 ] = 0 ;
}
#endif
}
assert ( * V_50 != NULL ) ;
if ( ( strlen ( V_7 ) > V_23 ) )
{
if ( ! V_18 )
F_7 ( V_24 , L_22 , V_23 ) ;
V_7 [ V_23 ] = 0 ;
}
assert ( strlen ( V_7 ) <= V_23 ) ;
#ifndef F_5
if ( V_21 )
V_52 = F_22 ( V_7 , * V_50 ) ;
#endif
#ifndef F_6
if ( V_22 )
V_52 = F_14 ( V_7 , * V_50 ) ;
#endif
assert ( V_52 != NULL ) ;
if ( V_19 && ! V_20 )
F_7 ( V_13 , L_23 , V_7 , V_52 ) ;
else if ( V_19 && V_20 )
F_7 ( V_13 , L_23 , V_52 , V_7 ) ;
else
F_7 ( V_13 , L_24 , V_52 ) ;
return 1 ;
V_28:
return 0 ;
}
int MAIN ( int V_1 , char * * V_2 )
{
fputs ( L_25 , stderr)
EXIT ( 1 ) ;
}
