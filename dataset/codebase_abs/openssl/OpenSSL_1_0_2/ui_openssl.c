T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 , T_3 * V_3 )
{
switch ( F_3 ( V_3 ) ) {
case V_4 :
case V_5 :
fputs ( F_4 ( V_3 ) , V_6 ) ;
fflush ( V_6 ) ;
break;
default:
break;
}
return 1 ;
}
static int F_5 ( T_2 * V_2 , T_3 * V_3 )
{
int V_7 = 0 ;
switch ( F_3 ( V_3 ) ) {
case V_8 :
fputs ( F_4 ( V_3 ) , V_6 ) ;
fputs ( F_6 ( V_3 ) , V_6 ) ;
fflush ( V_6 ) ;
return F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) & V_9 ,
0 ) ;
case V_10 :
fputs ( F_4 ( V_3 ) , V_6 ) ;
fflush ( V_6 ) ;
return F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) & V_9 ,
1 ) ;
case V_11 :
fprintf ( V_6 , L_1 , F_4 ( V_3 ) ) ;
fflush ( V_6 ) ;
if ( ( V_7 = F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) &
V_9 , 1 ) ) <= 0 )
return V_7 ;
if ( strcmp ( F_9 ( V_3 ) , F_10 ( V_3 ) ) != 0 ) {
fprintf ( V_6 , L_2 ) ;
fflush ( V_6 ) ;
return 0 ;
}
break;
default:
break;
}
return 1 ;
}
static int F_11 ( T_4 * V_12 )
{
# define F_12 4
char V_13 [ F_12 + 1 ] ;
do {
if ( ! fgets ( V_13 , F_12 , V_12 ) )
return 0 ;
} while ( strchr ( V_13 , '\n' ) == NULL );
return 1 ;
}
static int F_7 ( T_2 * V_2 , T_3 * V_3 , int V_14 , int V_15 )
{
static int V_16 ;
int V_7 ;
char V_17 [ V_18 ] ;
int V_19 = V_18 - 1 ;
#if ! F_13 ( V_20 ) && ! F_13 ( V_21 )
char * V_22 ;
V_23 = 0 ;
V_7 = 0 ;
V_16 = 0 ;
F_14 () ;
V_16 = 1 ;
if ( ! V_14 && ! F_15 ( V_2 ) )
goto error;
V_16 = 2 ;
V_17 [ 0 ] = '\0' ;
# ifdef F_16
if ( ! V_14 ) {
F_17 ( V_17 , V_19 , V_24 ) ;
V_22 = V_17 ;
} else
V_22 = fgets ( V_17 , V_19 , V_24 ) ;
# else
V_22 = fgets ( V_17 , V_19 , V_24 ) ;
# endif
if ( ! V_22 )
goto error;
if ( feof ( V_24 ) )
goto error;
if ( ferror ( V_24 ) )
goto error;
if ( ( V_22 = ( char * ) strchr ( V_17 , '\n' ) ) != NULL ) {
if ( V_15 )
* V_22 = '\0' ;
} else if ( ! F_11 ( V_24 ) )
goto error;
if ( F_18 ( V_2 , V_3 , V_17 ) >= 0 )
V_7 = 1 ;
error:
if ( V_23 == V_25 )
V_7 = - 1 ;
if ( ! V_14 )
fprintf ( V_6 , L_3 ) ;
if ( V_16 >= 2 && ! V_14 && ! F_19 ( V_2 ) )
V_7 = 0 ;
if ( V_16 >= 1 )
F_20 () ;
#else
V_7 = 1 ;
#endif
F_21 ( V_17 , V_18 ) ;
return V_7 ;
}
static int F_22 ( T_2 * V_2 )
{
F_23 ( V_26 ) ;
V_27 = 1 ;
#if F_13 ( V_28 ) || F_13 ( V_29 ) || F_13 ( V_30 ) || F_13 ( V_31 )
V_24 = V_32 ;
V_6 = V_33 ;
#else
# ifdef F_16
# define F_24 "con"
# else
# define F_24 "/dev/tty"
# endif
if ( ( V_24 = fopen ( F_24 , L_4 ) ) == NULL )
V_24 = V_32 ;
if ( ( V_6 = fopen ( F_24 , L_5 ) ) == NULL )
V_6 = V_33 ;
#endif
#if F_13 ( V_34 ) && ! F_13 ( V_35 )
if ( V_34 ( fileno ( V_24 ) , & V_36 ) == - 1 ) {
# ifdef F_25
if ( V_37 == F_25 )
V_27 = 0 ;
else
# endif
# ifdef F_26
if ( V_37 == F_26 )
V_27 = 0 ;
else
# endif
return 0 ;
}
#endif
#ifdef V_35
V_38 = F_27 ( & V_39 , & V_40 , 0 , 0 ) ;
if ( V_38 != V_41 )
return 0 ;
V_38 =
F_28 ( 0 , V_40 , V_42 , & V_43 , 0 , 0 , V_36 , 12 , 0 , 0 ,
0 , 0 ) ;
if ( ( V_38 != V_41 ) || ( V_43 . V_44 != V_41 ) )
return 0 ;
#endif
return 1 ;
}
static int F_15 ( T_2 * V_2 )
{
#ifdef F_29
memcpy ( & ( V_45 ) , & ( V_36 ) , sizeof( V_36 ) ) ;
V_45 . F_29 &= ~ V_46 ;
#endif
#if F_13 ( V_47 ) && ! F_13 ( V_35 )
if ( V_27 && ( V_47 ( fileno ( V_24 ) , & V_45 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_35
V_45 [ 0 ] = V_36 [ 0 ] ;
V_45 [ 1 ] = V_36 [ 1 ] | V_48 ;
V_45 [ 2 ] = V_36 [ 2 ] ;
V_38 =
F_28 ( 0 , V_40 , V_49 , & V_43 , 0 , 0 , V_45 , 12 , 0 , 0 , 0 ,
0 ) ;
if ( ( V_38 != V_41 ) || ( V_43 . V_44 != V_41 ) )
return 0 ;
#endif
return 1 ;
}
static int F_19 ( T_2 * V_2 )
{
#if F_13 ( V_47 ) && ! F_13 ( V_35 )
memcpy ( & ( V_45 ) , & ( V_36 ) , sizeof( V_36 ) ) ;
V_45 . F_29 |= V_46 ;
#endif
#if F_13 ( V_47 ) && ! F_13 ( V_35 )
if ( V_27 && ( V_47 ( fileno ( V_24 ) , & V_45 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_35
V_45 [ 0 ] = V_36 [ 0 ] ;
V_45 [ 1 ] = V_36 [ 1 ] & ~ V_48 ;
V_45 [ 2 ] = V_36 [ 2 ] ;
V_38 =
F_28 ( 0 , V_40 , V_49 , & V_43 , 0 , 0 , V_45 , 12 , 0 , 0 , 0 ,
0 ) ;
if ( ( V_38 != V_41 ) || ( V_43 . V_44 != V_41 ) )
return 0 ;
#endif
return 1 ;
}
static int F_30 ( T_2 * V_2 )
{
if ( V_24 != V_32 )
fclose ( V_24 ) ;
if ( V_6 != V_33 )
fclose ( V_6 ) ;
#ifdef V_35
V_38 = F_31 ( V_40 ) ;
#endif
F_32 ( V_26 ) ;
return 1 ;
}
static void F_14 ( void )
{
# ifndef F_33
int V_50 ;
# endif
# ifdef F_34
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof V_52 ) ;
V_52 . V_53 = V_54 ;
# endif
# ifdef F_33
V_55 [ V_56 ] = signal ( V_56 , V_54 ) ;
V_55 [ V_57 ] = signal ( V_57 , V_54 ) ;
V_55 [ V_58 ] = signal ( V_58 , V_54 ) ;
V_55 [ V_25 ] = signal ( V_25 , V_54 ) ;
V_55 [ V_59 ] = signal ( V_59 , V_54 ) ;
V_55 [ V_60 ] = signal ( V_60 , V_54 ) ;
# else
for ( V_50 = 1 ; V_50 < V_61 ; V_50 ++ ) {
# ifdef F_35
if ( V_50 == F_35 )
continue;
# endif
# ifdef F_36
if ( V_50 == F_36 )
continue;
# endif
# ifdef F_37
if ( V_50 == F_37 )
continue;
# endif
# ifdef F_34
V_51 ( V_50 , & V_52 , & V_55 [ V_50 ] ) ;
# else
V_55 [ V_50 ] = signal ( V_50 , V_54 ) ;
# endif
}
# endif
# ifdef F_38
signal ( F_38 , V_62 ) ;
# endif
}
static void F_20 ( void )
{
# ifdef F_33
signal ( V_56 , V_55 [ V_56 ] ) ;
signal ( V_57 , V_55 [ V_57 ] ) ;
signal ( V_58 , V_55 [ V_58 ] ) ;
signal ( V_25 , V_55 [ V_25 ] ) ;
signal ( V_59 , V_55 [ V_59 ] ) ;
signal ( V_60 , V_55 [ V_60 ] ) ;
# else
int V_50 ;
for ( V_50 = 1 ; V_50 < V_61 ; V_50 ++ ) {
# ifdef F_35
if ( V_50 == F_35 )
continue;
# endif
# ifdef F_36
if ( V_50 == F_36 )
continue;
# endif
# ifdef F_34
V_51 ( V_50 , & V_55 [ V_50 ] , NULL ) ;
# else
signal ( V_50 , V_55 [ V_50 ] ) ;
# endif
}
# endif
}
static void V_54 ( int V_50 )
{
V_23 = V_50 ;
}
static int F_17 ( char * V_13 , int V_63 , T_4 * V_64 )
{
int V_50 ;
char * V_22 ;
V_22 = V_13 ;
for (; ; ) {
if ( V_63 == 0 ) {
* V_22 = '\0' ;
break;
}
V_63 -- ;
# ifdef F_39
V_50 = F_40 () ;
# elif F_13 ( V_65 )
V_50 = F_41 () ;
# else
V_50 = F_42 () ;
# endif
if ( V_50 == '\r' )
V_50 = '\n' ;
* ( V_22 ++ ) = V_50 ;
if ( V_50 == '\n' ) {
* V_22 = '\0' ;
break;
}
}
# ifdef F_43
{
T_5 V_66 ;
V_66 = F_44 ( V_67 ) ;
F_45 ( V_66 ) ;
}
# endif
return ( strlen ( V_13 ) ) ;
}
