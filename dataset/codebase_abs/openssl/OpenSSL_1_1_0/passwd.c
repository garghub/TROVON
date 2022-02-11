int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL , * V_6 = NULL , * * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL , * V_10 ;
T_2 V_11 ;
int V_12 = 0 , V_13 = 0 ;
#ifndef F_2
int V_14 = 0 ;
#endif
int V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
int V_19 = 1 , V_20 = 0 , V_21 = 0 , V_22 = 0 ;
T_3 V_23 = 0 , V_24 = 256 ;
V_10 = F_3 ( V_1 , V_2 , V_25 ) ;
while ( ( V_11 = F_4 () ) != V_26 ) {
switch ( V_11 ) {
case V_26 :
case V_27 :
V_28:
F_5 ( V_29 , L_1 , V_10 ) ;
goto V_30;
case V_31 :
F_6 ( V_25 ) ;
V_19 = 0 ;
goto V_30;
case V_32 :
if ( V_13 )
goto V_28;
V_4 = F_7 () ;
V_13 = 1 ;
break;
case V_33 :
#ifndef F_2
V_14 = 1 ;
#endif
break;
case V_34 :
V_16 = 1 ;
break;
case V_35 :
V_17 = 1 ;
break;
case V_36 :
V_18 = 1 ;
break;
case V_37 :
V_21 = 1 ;
break;
case V_38 :
V_22 = 1 ;
break;
case V_39 :
V_20 = 1 ;
break;
case V_40 :
V_15 = 1 ;
V_5 = F_7 () ;
break;
case V_41 :
if ( V_13 )
goto V_28;
V_12 = 1 ;
V_13 = 1 ;
break;
}
}
V_1 = F_8 () ;
V_2 = F_9 () ;
if ( * V_2 ) {
if ( V_13 )
goto V_28;
V_13 = 1 ;
V_7 = V_2 ;
}
if ( ! V_20 && ! V_21 && ! V_22 ) {
V_20 = 1 ;
}
if ( V_20 + V_21 + V_22 > 1 ) {
goto V_28;
}
# ifdef F_10
if ( V_20 )
goto V_28;
# endif
# ifdef F_11
if ( V_21 || V_22 )
goto V_28;
# endif
if ( V_4 != NULL && V_12 ) {
F_5 ( V_29 , L_2 , V_10 ) ;
goto V_30;
}
if ( V_4 != NULL || V_12 ) {
V_3 = F_12 ( V_4 , 'r' , V_42 ) ;
if ( V_3 == NULL )
goto V_30;
}
if ( V_20 )
V_24 = 8 ;
else if ( V_21 || V_22 )
V_24 = 256 ;
if ( V_7 == NULL ) {
V_23 = V_24 + 2 ;
V_6 = V_9 =
F_13 ( V_23 , L_3 ) ;
}
if ( ( V_3 == NULL ) && ( V_7 == NULL ) ) {
if ( 1 ) {
#ifndef F_2
static char * V_43 [ 2 ] = { NULL , NULL } ;
V_7 = V_43 ;
if ( V_3 == NULL )
if ( F_14
( V_9 , V_23 , L_4 ,
! ( V_15 || V_14 ) ) != 0 )
goto V_30;
V_7 [ 0 ] = V_9 ;
} else {
#endif
F_5 ( V_29 , L_5 ) ;
goto V_30;
}
}
if ( V_3 == NULL ) {
assert ( V_7 != NULL ) ;
assert ( * V_7 != NULL ) ;
do {
V_6 = * V_7 ++ ;
if ( ! F_15 ( V_15 , & V_5 , & V_8 , V_6 , V_44 ,
V_16 , V_17 , V_18 , V_24 , V_20 , V_21 ,
V_22 ) )
goto V_30;
}
while ( * V_7 != NULL );
} else
{
int V_45 ;
assert ( V_6 != NULL ) ;
do {
int V_46 = F_16 ( V_3 , V_6 , V_24 + 1 ) ;
if ( V_46 > 0 ) {
char * V_47 = ( strchr ( V_6 , '\n' ) ) ;
if ( V_47 != NULL )
* V_47 = 0 ;
else {
char V_48 [ V_49 ] ;
do
V_46 = F_16 ( V_3 , V_48 , sizeof V_48 ) ;
while ( ( V_46 > 0 ) && ( ! strchr ( V_48 , '\n' ) ) );
}
if ( ! F_15
( V_15 , & V_5 , & V_8 , V_6 , V_44 , V_16 ,
V_17 , V_18 , V_24 , V_20 , V_21 , V_22 ) )
goto V_30;
}
V_45 = ( V_46 <= 0 ) ;
}
while ( ! V_45 );
}
V_19 = 0 ;
V_30:
F_17 ( V_29 ) ;
F_18 ( V_8 ) ;
F_18 ( V_9 ) ;
F_19 ( V_3 ) ;
return ( V_19 ) ;
}
static char * F_20 ( const char * V_6 , const char * V_50 , const char * V_5 )
{
static char V_51 [ 6 + 9 + 24 + 2 ] ;
unsigned char V_52 [ V_53 ] ;
char * V_54 ;
int V_55 ;
unsigned int V_56 ;
T_4 * V_57 = NULL , * V_58 = NULL ;
T_3 V_59 , V_60 , V_61 ;
V_59 = strlen ( V_6 ) ;
V_51 [ 0 ] = '$' ;
V_51 [ 1 ] = 0 ;
V_61 = strlen ( V_50 ) ;
if ( V_61 > 4 )
return NULL ;
F_21 ( V_51 , V_50 , sizeof V_51 ) ;
F_21 ( V_51 , L_6 , sizeof V_51 ) ;
F_21 ( V_51 , V_5 , sizeof V_51 ) ;
if ( strlen ( V_51 ) > 6 + 8 )
return NULL ;
V_54 = V_51 + 2 + V_61 ;
V_60 = strlen ( V_54 ) ;
if ( V_60 > 8 )
return NULL ;
V_57 = F_22 () ;
if ( V_57 == NULL
|| ! F_23 ( V_57 , F_24 () , NULL )
|| ! F_25 ( V_57 , V_6 , V_59 )
|| ! F_25 ( V_57 , L_6 , 1 )
|| ! F_25 ( V_57 , V_50 , V_61 )
|| ! F_25 ( V_57 , L_6 , 1 )
|| ! F_25 ( V_57 , V_54 , V_60 ) )
V_58 = F_22 () ;
if ( V_58 == NULL
|| ! F_23 ( V_58 , F_24 () , NULL )
|| ! F_25 ( V_58 , V_6 , V_59 )
|| ! F_25 ( V_58 , V_54 , V_60 )
|| ! F_25 ( V_58 , V_6 , V_59 )
|| ! F_26 ( V_58 , V_52 , NULL ) )
goto V_62;
for ( V_56 = V_59 ; V_56 > sizeof V_52 ; V_56 -= sizeof V_52 ) {
if ( ! F_25 ( V_57 , V_52 , sizeof V_52 ) )
goto V_62;
}
if ( ! F_25 ( V_57 , V_52 , V_56 ) )
goto V_62;
V_55 = V_59 ;
while ( V_55 ) {
if ( ! F_25 ( V_57 , ( V_55 & 1 ) ? L_7 : V_6 , 1 ) )
goto V_62;
V_55 >>= 1 ;
}
if ( ! F_26 ( V_57 , V_52 , NULL ) )
return NULL ;
for ( V_56 = 0 ; V_56 < 1000 ; V_56 ++ ) {
if ( ! F_23 ( V_58 , F_24 () , NULL ) )
goto V_62;
if ( ! F_25 ( V_58 ,
( V_56 & 1 ) ? ( unsigned const char * ) V_6 : V_52 ,
( V_56 & 1 ) ? V_59 : sizeof V_52 ) )
goto V_62;
if ( V_56 % 3 ) {
if ( ! F_25 ( V_58 , V_54 , V_60 ) )
goto V_62;
}
if ( V_56 % 7 ) {
if ( ! F_25 ( V_58 , V_6 , V_59 ) )
goto V_62;
}
if ( ! F_25 ( V_58 ,
( V_56 & 1 ) ? V_52 : ( unsigned const char * ) V_6 ,
( V_56 & 1 ) ? sizeof V_52 : V_59 ) )
goto V_62;
if ( ! F_26 ( V_58 , V_52 , NULL ) )
goto V_62;
}
F_27 ( V_58 ) ;
F_27 ( V_57 ) ;
V_58 = NULL ;
V_57 = NULL ;
{
unsigned char V_63 [ sizeof V_52 ] ;
int V_64 , V_65 ;
char * V_66 ;
for ( V_64 = 0 , V_65 = 0 ; V_64 < 14 ;
V_64 ++ , V_65 = ( V_65 + 6 ) % 17 )
V_63 [ V_64 ] = V_52 [ V_65 ] ;
V_63 [ 14 ] = V_52 [ 5 ] ;
V_63 [ 15 ] = V_52 [ 11 ] ;
# ifndef F_28
assert ( 16 == sizeof V_63 ) ;
# endif
V_66 = V_54 + V_60 ;
assert ( V_66 == V_51 + strlen ( V_51 ) ) ;
* V_66 ++ = '$' ;
for ( V_56 = 0 ; V_56 < 15 ; V_56 += 3 ) {
* V_66 ++ = V_67 [ V_63 [ V_56 + 2 ] & 0x3f ] ;
* V_66 ++ = V_67 [ ( ( V_63 [ V_56 + 1 ] & 0xf ) << 2 ) |
( V_63 [ V_56 + 2 ] >> 6 ) ] ;
* V_66 ++ = V_67 [ ( ( V_63 [ V_56 ] & 3 ) << 4 ) |
( V_63 [ V_56 + 1 ] >> 4 ) ] ;
* V_66 ++ = V_67 [ V_63 [ V_56 ] >> 2 ] ;
}
assert ( V_56 == 15 ) ;
* V_66 ++ = V_67 [ V_63 [ V_56 ] & 0x3f ] ;
* V_66 ++ = V_67 [ V_63 [ V_56 ] >> 6 ] ;
* V_66 = 0 ;
assert ( strlen ( V_51 ) < sizeof( V_51 ) ) ;
}
return V_51 ;
V_62:
F_27 ( V_58 ) ;
F_27 ( V_57 ) ;
return NULL ;
}
static int F_15 ( int V_15 , char * * V_68 , char * * V_69 ,
char * V_6 , T_1 * V_70 , int V_16 , int V_17 ,
int V_18 , T_3 V_24 , int V_20 , int V_21 ,
int V_22 )
{
char * V_71 = NULL ;
assert ( V_68 != NULL ) ;
assert ( V_69 != NULL ) ;
if ( ! V_15 ) {
# ifndef F_10
if ( V_20 ) {
if ( * V_69 == NULL ) {
* V_68 = * V_69 = F_13 ( 3 , L_8 ) ;
}
if ( F_29 ( ( unsigned char * ) * V_68 , 2 ) <= 0 )
goto V_30;
( * V_68 ) [ 0 ] = V_67 [ ( * V_68 ) [ 0 ] & 0x3f ] ;
( * V_68 ) [ 1 ] = V_67 [ ( * V_68 ) [ 1 ] & 0x3f ] ;
( * V_68 ) [ 2 ] = 0 ;
# ifdef F_30
F_31 ( * V_68 , * V_68 , 2 ) ;
# endif
}
# endif
# ifndef F_11
if ( V_21 || V_22 ) {
int V_56 ;
if ( * V_69 == NULL ) {
* V_68 = * V_69 = F_13 ( 9 , L_8 ) ;
}
if ( F_29 ( ( unsigned char * ) * V_68 , 8 ) <= 0 )
goto V_30;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
( * V_68 ) [ V_56 ] = V_67 [ ( * V_68 ) [ V_56 ] & 0x3f ] ;
( * V_68 ) [ 8 ] = 0 ;
}
# endif
}
assert ( * V_68 != NULL ) ;
if ( ( strlen ( V_6 ) > V_24 ) ) {
if ( ! V_16 )
F_5 ( V_29 ,
L_9 ,
( unsigned ) V_24 ) ;
V_6 [ V_24 ] = 0 ;
}
assert ( strlen ( V_6 ) <= V_24 ) ;
# ifndef F_10
if ( V_20 )
V_71 = F_32 ( V_6 , * V_68 ) ;
# endif
# ifndef F_11
if ( V_21 || V_22 )
V_71 = F_20 ( V_6 , ( V_21 ? L_10 : L_11 ) , * V_68 ) ;
# endif
assert ( V_71 != NULL ) ;
if ( V_17 && ! V_18 )
F_5 ( V_70 , L_12 , V_6 , V_71 ) ;
else if ( V_17 && V_18 )
F_5 ( V_70 , L_12 , V_71 , V_6 ) ;
else
F_5 ( V_70 , L_13 , V_71 ) ;
return 1 ;
V_30:
return 0 ;
}
int F_1 ( int V_1 , char * * V_2 )
{
F_5 ( V_29 , L_14 ) ;
return ( 1 ) ;
}
