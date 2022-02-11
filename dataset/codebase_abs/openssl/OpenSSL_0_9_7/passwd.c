int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
char * V_4 = NULL ;
int V_5 = 0 ;
int V_6 = 0 ;
char * V_7 = NULL , * V_8 = NULL , * * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
T_1 V_12 = 0 ;
int V_13 = 0 ;
T_2 * V_14 = NULL , * V_15 = NULL ;
int V_16 , V_17 , V_18 ;
int V_19 = 0 , V_20 = 0 , V_21 = 0 , V_22 = 0 ;
int V_23 = 0 , V_24 = 0 , V_25 = 0 ;
T_1 V_26 = 0 ;
F_1 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_27 , V_28 , V_29 | V_30 ) ;
if ( ! F_5 ( V_27 , NULL ) )
goto V_31;
V_15 = F_2 ( F_3 () ) ;
if ( V_15 == NULL )
goto V_31;
F_4 ( V_15 , stdout , V_29 | V_30 ) ;
#ifdef F_6
{
T_2 * V_32 = F_2 ( F_7 () ) ;
V_15 = F_8 ( V_32 , V_15 ) ;
}
#endif
V_17 = 0 , V_18 = 0 ;
V_16 = 0 ;
while ( ! V_17 && ! V_18 && V_2 [ ++ V_16 ] != NULL )
{
if ( strcmp ( V_2 [ V_16 ] , L_1 ) == 0 )
V_23 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_2 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_3 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_4 ) == 0 )
{
if ( ( V_2 [ V_16 + 1 ] != NULL ) && ( V_7 == NULL ) )
{
V_19 = 1 ;
V_7 = V_2 [ ++ V_16 ] ;
}
else
V_17 = 1 ;
}
else if ( strcmp ( V_2 [ V_16 ] , L_5 ) == 0 )
{
if ( ( V_2 [ V_16 + 1 ] != NULL ) && ! V_13 )
{
V_13 = 1 ;
V_4 = V_2 [ ++ V_16 ] ;
}
else
V_17 = 1 ;
}
else if ( strcmp ( V_2 [ V_16 ] , L_6 ) == 0 )
{
if ( ! V_13 )
{
V_13 = 1 ;
V_5 = 1 ;
}
else
V_17 = 1 ;
}
else if ( strcmp ( V_2 [ V_16 ] , L_7 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_8 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_9 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( V_2 [ V_16 ] , L_10 ) == 0 )
V_22 = 1 ;
else if ( V_2 [ V_16 ] [ 0 ] == '-' )
V_17 = 1 ;
else if ( ! V_13 )
{
V_13 = 1 ;
V_9 = & V_2 [ V_16 ] ;
V_18 = 1 ;
}
else
V_17 = 1 ;
}
if ( ! V_23 && ! V_24 && ! V_25 )
V_23 = 1 ;
if ( V_23 + V_24 + V_25 > 1 )
V_17 = 1 ;
#ifdef F_9
if ( V_23 ) V_17 = 1 ;
#endif
#ifdef F_10
if ( V_24 || V_25 ) V_17 = 1 ;
#endif
if ( V_17 )
{
F_11 ( V_27 , L_11 ) ;
F_11 ( V_27 , L_12 ) ;
#ifndef F_9
F_11 ( V_27 , L_13 ) ;
#endif
#ifndef F_10
F_11 ( V_27 , L_14 ) ;
F_11 ( V_27 , L_15 ) ;
#endif
F_11 ( V_27 , L_16 ) ;
F_11 ( V_27 , L_17 ) ;
F_11 ( V_27 , L_18 ) ;
F_11 ( V_27 , L_19 ) ;
F_11 ( V_27 , L_20 ) ;
F_11 ( V_27 , L_21 ) ;
F_11 ( V_27 , L_22 ) ;
goto V_31;
}
if ( ( V_4 != NULL ) || V_5 )
{
V_14 = F_2 ( F_3 () ) ;
if ( V_14 == NULL )
goto V_31;
if ( V_4 != NULL )
{
assert ( V_5 == 0 ) ;
if ( F_12 ( V_14 , V_4 ) <= 0 )
goto V_31;
}
else
{
assert ( V_5 ) ;
F_4 ( V_14 , V_33 , V_29 ) ;
}
}
if ( V_23 )
V_26 = 8 ;
else if ( V_24 || V_25 )
V_26 = 256 ;
if ( V_9 == NULL )
{
V_12 = V_26 + 2 ;
V_8 = V_11 = F_13 ( V_12 ) ;
if ( V_11 == NULL )
goto V_31;
}
if ( ( V_14 == NULL ) && ( V_9 == NULL ) )
{
static char * V_34 [ 2 ] = { NULL , NULL } ;
V_9 = V_34 ;
if ( V_14 == NULL )
if ( F_14 ( V_11 , V_12 , L_23 , ! ( V_19 || V_6 ) ) != 0 )
goto V_31;
V_9 [ 0 ] = V_11 ;
}
if ( V_14 == NULL )
{
assert ( V_9 != NULL ) ;
assert ( * V_9 != NULL ) ;
do
{
V_8 = * V_9 ++ ;
if ( ! F_15 ( V_19 , & V_7 , & V_10 , V_8 , V_15 ,
V_20 , V_21 , V_22 , V_26 , V_23 , V_24 , V_25 ) )
goto V_31;
}
while ( * V_9 != NULL );
}
else
{
int V_35 ;
assert ( V_8 != NULL ) ;
do
{
int V_36 = F_16 ( V_14 , V_8 , V_26 + 1 ) ;
if ( V_36 > 0 )
{
char * V_37 = ( strchr ( V_8 , '\n' ) ) ;
if ( V_37 != NULL )
* V_37 = 0 ;
else
{
char V_38 [ V_39 ] ;
do
V_36 = F_16 ( V_14 , V_38 , sizeof V_38 ) ;
while ( ( V_36 > 0 ) && ( ! strchr ( V_38 , '\n' ) ) );
}
if ( ! F_15 ( V_19 , & V_7 , & V_10 , V_8 , V_15 ,
V_20 , V_21 , V_22 , V_26 , V_23 , V_24 , V_25 ) )
goto V_31;
}
V_35 = ( V_36 <= 0 ) ;
}
while ( ! V_35 );
}
V_3 = 0 ;
V_31:
F_17 ( V_27 ) ;
if ( V_10 )
F_18 ( V_10 ) ;
if ( V_11 )
F_18 ( V_11 ) ;
if ( V_14 )
F_19 ( V_14 ) ;
if ( V_15 )
F_20 ( V_15 ) ;
F_21 () ;
F_22 ( V_3 ) ;
}
static char * F_23 ( const char * V_8 , const char * V_40 , const char * V_7 )
{
static char V_41 [ 6 + 9 + 24 + 2 ] ;
unsigned char V_42 [ V_43 ] ;
char * V_44 ;
int V_45 , V_16 ;
T_3 V_46 , V_47 ;
T_1 V_48 , V_49 ;
V_48 = strlen ( V_8 ) ;
V_41 [ 0 ] = '$' ;
V_41 [ 1 ] = 0 ;
assert ( strlen ( V_40 ) <= 4 ) ;
strncat ( V_41 , V_40 , 4 ) ;
strncat ( V_41 , L_24 , 1 ) ;
strncat ( V_41 , V_7 , 8 ) ;
assert ( strlen ( V_41 ) <= 6 + 8 ) ;
V_44 = V_41 + 2 + strlen ( V_40 ) ;
V_49 = strlen ( V_44 ) ;
assert ( V_49 <= 8 ) ;
F_24 ( & V_46 ) ;
F_25 ( & V_46 , F_26 () , NULL ) ;
F_27 ( & V_46 , V_8 , V_48 ) ;
F_27 ( & V_46 , L_24 , 1 ) ;
F_27 ( & V_46 , V_40 , strlen ( V_40 ) ) ;
F_27 ( & V_46 , L_24 , 1 ) ;
F_27 ( & V_46 , V_44 , V_49 ) ;
F_24 ( & V_47 ) ;
F_25 ( & V_47 , F_26 () , NULL ) ;
F_27 ( & V_47 , V_8 , V_48 ) ;
F_27 ( & V_47 , V_44 , V_49 ) ;
F_27 ( & V_47 , V_8 , V_48 ) ;
F_28 ( & V_47 , V_42 , NULL ) ;
for ( V_16 = V_48 ; V_16 > sizeof V_42 ; V_16 -= sizeof V_42 )
F_27 ( & V_46 , V_42 , sizeof V_42 ) ;
F_27 ( & V_46 , V_42 , V_16 ) ;
V_45 = V_48 ;
while ( V_45 )
{
F_27 ( & V_46 , ( V_45 & 1 ) ? L_25 : V_8 , 1 ) ;
V_45 >>= 1 ;
}
F_28 ( & V_46 , V_42 , NULL ) ;
for ( V_16 = 0 ; V_16 < 1000 ; V_16 ++ )
{
F_25 ( & V_47 , F_26 () , NULL ) ;
F_27 ( & V_47 , ( V_16 & 1 ) ? ( unsigned char * ) V_8 : V_42 ,
( V_16 & 1 ) ? V_48 : sizeof V_42 ) ;
if ( V_16 % 3 )
F_27 ( & V_47 , V_44 , V_49 ) ;
if ( V_16 % 7 )
F_27 ( & V_47 , V_8 , V_48 ) ;
F_27 ( & V_47 , ( V_16 & 1 ) ? V_42 : ( unsigned char * ) V_8 ,
( V_16 & 1 ) ? sizeof V_42 : V_48 ) ;
F_28 ( & V_47 , V_42 , NULL ) ;
}
F_29 ( & V_47 ) ;
{
unsigned char V_50 [ sizeof V_42 ] ;
int V_51 , V_52 ;
char * V_53 ;
for ( V_51 = 0 , V_52 = 0 ; V_51 < 14 ; V_51 ++ , V_52 = ( V_52 + 6 ) % 17 )
V_50 [ V_51 ] = V_42 [ V_52 ] ;
V_50 [ 14 ] = V_42 [ 5 ] ;
V_50 [ 15 ] = V_42 [ 11 ] ;
#ifndef F_30
assert ( 16 == sizeof V_50 ) ;
#endif
V_53 = V_44 + V_49 ;
assert ( V_53 == V_41 + strlen ( V_41 ) ) ;
* V_53 ++ = '$' ;
for ( V_16 = 0 ; V_16 < 15 ; V_16 += 3 )
{
* V_53 ++ = V_54 [ V_50 [ V_16 + 2 ] & 0x3f ] ;
* V_53 ++ = V_54 [ ( ( V_50 [ V_16 + 1 ] & 0xf ) << 2 ) |
( V_50 [ V_16 + 2 ] >> 6 ) ] ;
* V_53 ++ = V_54 [ ( ( V_50 [ V_16 ] & 3 ) << 4 ) |
( V_50 [ V_16 + 1 ] >> 4 ) ] ;
* V_53 ++ = V_54 [ V_50 [ V_16 ] >> 2 ] ;
}
assert ( V_16 == 15 ) ;
* V_53 ++ = V_54 [ V_50 [ V_16 ] & 0x3f ] ;
* V_53 ++ = V_54 [ V_50 [ V_16 ] >> 6 ] ;
* V_53 = 0 ;
assert ( strlen ( V_41 ) < sizeof( V_41 ) ) ;
}
F_29 ( & V_46 ) ;
return V_41 ;
}
static int F_15 ( int V_19 , char * * V_55 , char * * V_56 ,
char * V_8 , T_2 * V_15 , int V_20 , int V_21 , int V_22 ,
T_1 V_26 , int V_23 , int V_24 , int V_25 )
{
char * V_57 = NULL ;
assert ( V_55 != NULL ) ;
assert ( V_56 != NULL ) ;
if ( ! V_19 )
{
#ifndef F_9
if ( V_23 )
{
if ( * V_56 == NULL )
{
* V_55 = * V_56 = F_13 ( 3 ) ;
if ( * V_56 == NULL )
goto V_31;
}
if ( F_31 ( ( unsigned char * ) * V_55 , 2 ) < 0 )
goto V_31;
( * V_55 ) [ 0 ] = V_54 [ ( * V_55 ) [ 0 ] & 0x3f ] ;
( * V_55 ) [ 1 ] = V_54 [ ( * V_55 ) [ 1 ] & 0x3f ] ;
( * V_55 ) [ 2 ] = 0 ;
#ifdef F_32
F_33 ( * V_55 , * V_55 , 2 ) ;
#endif
}
#endif
#ifndef F_10
if ( V_24 || V_25 )
{
int V_16 ;
if ( * V_56 == NULL )
{
* V_55 = * V_56 = F_13 ( 9 ) ;
if ( * V_56 == NULL )
goto V_31;
}
if ( F_31 ( ( unsigned char * ) * V_55 , 8 ) < 0 )
goto V_31;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
( * V_55 ) [ V_16 ] = V_54 [ ( * V_55 ) [ V_16 ] & 0x3f ] ;
( * V_55 ) [ 8 ] = 0 ;
}
#endif
}
assert ( * V_55 != NULL ) ;
if ( ( strlen ( V_8 ) > V_26 ) )
{
if ( ! V_20 )
F_11 ( V_27 , L_26 , V_26 ) ;
V_8 [ V_26 ] = 0 ;
}
assert ( strlen ( V_8 ) <= V_26 ) ;
#ifndef F_9
if ( V_23 )
V_57 = F_34 ( V_8 , * V_55 ) ;
#endif
#ifndef F_10
if ( V_24 || V_25 )
V_57 = F_23 ( V_8 , ( V_24 ? L_27 : L_28 ) , * V_55 ) ;
#endif
assert ( V_57 != NULL ) ;
if ( V_21 && ! V_22 )
F_11 ( V_15 , L_29 , V_8 , V_57 ) ;
else if ( V_21 && V_22 )
F_11 ( V_15 , L_29 , V_57 , V_8 ) ;
else
F_11 ( V_15 , L_30 , V_57 ) ;
return 1 ;
V_31:
return 0 ;
}
int MAIN ( int V_1 , char * * V_2 )
{
fputs ( L_31 , stderr)
F_22 ( 1 ) ;
}
