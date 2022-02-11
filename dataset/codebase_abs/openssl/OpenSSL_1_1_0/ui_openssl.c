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
#if ! F_13 ( V_20 )
char * V_21 = NULL ;
int V_22 = ! V_14 ;
V_23 = 0 ;
V_7 = 0 ;
V_16 = 0 ;
F_14 () ;
V_16 = 1 ;
if ( ! V_14 && ! F_15 ( V_2 ) )
goto error;
V_16 = 2 ;
V_17 [ 0 ] = '\0' ;
# if F_13 ( V_24 )
if ( V_25 ) {
T_5 V_26 ;
# if F_13 ( V_27 )
if ( F_16 ( L_3 , NULL , 0 ) != 0 ) {
T_6 V_28 [ V_18 ] ;
if ( F_17 ( F_18 ( V_29 ) ,
V_28 , V_19 , & V_26 , NULL ) ) {
if ( V_26 >= 2 &&
V_28 [ V_26 - 2 ] == V_30 '\r' &&
V_28 [ V_26 - 1 ] == V_30 '\n' ) {
V_28 [ V_26 - 2 ] = V_30 '\n' ;
V_26 -- ;
}
V_28 [ V_26 ] = '\0' ;
if ( F_19 ( V_27 , 0 , V_28 , - 1 ,
V_17 , sizeof( V_17 ) , NULL , 0 ) > 0 )
V_21 = V_17 ;
F_20 ( V_28 , sizeof( V_28 ) ) ;
}
} else
# endif
if ( F_21 ( F_18 ( V_29 ) ,
V_17 , V_19 , & V_26 , NULL ) ) {
if ( V_26 >= 2 &&
V_17 [ V_26 - 2 ] == '\r' && V_17 [ V_26 - 1 ] == '\n' ) {
V_17 [ V_26 - 2 ] = '\n' ;
V_26 -- ;
}
V_17 [ V_26 ] = '\0' ;
V_21 = V_17 ;
}
} else
# elif F_13 ( V_31 )
if ( ! V_14 ) {
F_22 ( V_17 , V_19 , V_32 ) ;
V_21 = V_17 ;
} else
# endif
V_21 = fgets ( V_17 , V_19 , V_32 ) ;
if ( ! V_21 )
goto error;
if ( feof ( V_32 ) )
goto error;
if ( ferror ( V_32 ) )
goto error;
if ( ( V_21 = ( char * ) strchr ( V_17 , '\n' ) ) != NULL ) {
if ( V_15 )
* V_21 = '\0' ;
} else if ( ! F_11 ( V_32 ) )
goto error;
if ( F_23 ( V_2 , V_3 , V_17 ) >= 0 )
V_7 = 1 ;
error:
if ( V_23 == V_33 )
V_7 = - 1 ;
if ( V_22 )
fprintf ( V_6 , L_4 ) ;
if ( V_16 >= 2 && ! V_14 && ! F_24 ( V_2 ) )
V_7 = 0 ;
if ( V_16 >= 1 )
F_25 () ;
#else
V_7 = 1 ;
#endif
F_20 ( V_17 , V_18 ) ;
return V_7 ;
}
static int F_26 ( T_2 * V_2 )
{
F_27 ( V_2 -> V_34 ) ;
V_25 = 1 ;
#if F_13 ( V_35 )
V_32 = V_36 ;
V_6 = V_37 ;
#elif F_13 ( V_24 ) && ! F_13 ( V_38 )
if ( ( V_6 = fopen ( L_5 , L_6 ) ) == NULL )
V_6 = V_37 ;
if ( F_28 ( F_18 ( V_29 ) , & V_39 ) ) {
V_32 = V_36 ;
} else {
V_25 = 0 ;
if ( ( V_32 = fopen ( L_7 , L_8 ) ) == NULL )
V_32 = V_36 ;
}
#else
# ifdef V_31
# define F_29 "con"
# else
# define F_29 "/dev/tty"
# endif
if ( ( V_32 = fopen ( F_29 , L_8 ) ) == NULL )
V_32 = V_36 ;
if ( ( V_6 = fopen ( F_29 , L_6 ) ) == NULL )
V_6 = V_37 ;
#endif
#if F_13 ( V_40 ) && ! F_13 ( V_41 )
if ( V_40 ( fileno ( V_32 ) , & V_39 ) == - 1 ) {
# ifdef F_30
if ( V_42 == F_30 )
V_25 = 0 ;
else
# endif
# ifdef F_31
if ( V_42 == F_31 )
V_25 = 0 ;
else
# endif
return 0 ;
}
#endif
#ifdef V_41
V_43 = F_32 ( & V_44 , & V_45 , 0 , 0 ) ;
if ( V_43 != V_46 )
return 0 ;
V_43 =
F_33 ( 0 , V_45 , V_47 , & V_48 , 0 , 0 , V_39 , 12 , 0 , 0 ,
0 , 0 ) ;
if ( ( V_43 != V_46 ) || ( V_48 . V_49 != V_46 ) )
return 0 ;
#endif
return 1 ;
}
static int F_15 ( T_2 * V_2 )
{
#ifdef F_34
memcpy ( & ( V_50 ) , & ( V_39 ) , sizeof( V_39 ) ) ;
V_50 . F_34 &= ~ V_51 ;
#endif
#if F_13 ( V_52 ) && ! F_13 ( V_41 )
if ( V_25 && ( V_52 ( fileno ( V_32 ) , & V_50 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_41
V_50 [ 0 ] = V_39 [ 0 ] ;
V_50 [ 1 ] = V_39 [ 1 ] | V_53 ;
V_50 [ 2 ] = V_39 [ 2 ] ;
V_43 =
F_33 ( 0 , V_45 , V_54 , & V_48 , 0 , 0 , V_50 , 12 , 0 , 0 , 0 ,
0 ) ;
if ( ( V_43 != V_46 ) || ( V_48 . V_49 != V_46 ) )
return 0 ;
#endif
#if F_13 ( V_24 ) && ! F_13 ( V_38 )
if ( V_25 ) {
V_50 = V_39 ;
V_50 &= ~ V_55 ;
F_35 ( F_18 ( V_29 ) , V_50 ) ;
}
#endif
return 1 ;
}
static int F_24 ( T_2 * V_2 )
{
#if F_13 ( V_52 ) && ! F_13 ( V_41 )
memcpy ( & ( V_50 ) , & ( V_39 ) , sizeof( V_39 ) ) ;
V_50 . F_34 |= V_51 ;
#endif
#if F_13 ( V_52 ) && ! F_13 ( V_41 )
if ( V_25 && ( V_52 ( fileno ( V_32 ) , & V_50 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_41
V_50 [ 0 ] = V_39 [ 0 ] ;
V_50 [ 1 ] = V_39 [ 1 ] & ~ V_53 ;
V_50 [ 2 ] = V_39 [ 2 ] ;
V_43 =
F_33 ( 0 , V_45 , V_54 , & V_48 , 0 , 0 , V_50 , 12 , 0 , 0 , 0 ,
0 ) ;
if ( ( V_43 != V_46 ) || ( V_48 . V_49 != V_46 ) )
return 0 ;
#endif
#if F_13 ( V_24 ) && ! F_13 ( V_38 )
if ( V_25 ) {
V_50 = V_39 ;
V_50 |= V_55 ;
F_35 ( F_18 ( V_29 ) , V_50 ) ;
}
#endif
return 1 ;
}
static int F_36 ( T_2 * V_2 )
{
if ( V_32 != V_36 )
fclose ( V_32 ) ;
if ( V_6 != V_37 )
fclose ( V_6 ) ;
#ifdef V_41
V_43 = F_37 ( V_45 ) ;
#endif
F_38 ( V_2 -> V_34 ) ;
return 1 ;
}
static void F_14 ( void )
{
# ifndef F_39
int V_56 ;
# endif
# ifdef F_40
struct V_57 V_58 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_59 = V_60 ;
# endif
# ifdef F_39
V_61 [ V_62 ] = signal ( V_62 , V_60 ) ;
V_61 [ V_63 ] = signal ( V_63 , V_60 ) ;
V_61 [ V_64 ] = signal ( V_64 , V_60 ) ;
V_61 [ V_33 ] = signal ( V_33 , V_60 ) ;
V_61 [ V_65 ] = signal ( V_65 , V_60 ) ;
V_61 [ V_66 ] = signal ( V_66 , V_60 ) ;
# else
for ( V_56 = 1 ; V_56 < V_67 ; V_56 ++ ) {
# ifdef F_41
if ( V_56 == F_41 )
continue;
# endif
# ifdef F_42
if ( V_56 == F_42 )
continue;
# endif
# ifdef F_43
if ( V_56 == F_43 )
continue;
# endif
# ifdef F_40
V_57 ( V_56 , & V_58 , & V_61 [ V_56 ] ) ;
# else
V_61 [ V_56 ] = signal ( V_56 , V_60 ) ;
# endif
}
# endif
# ifdef F_44
signal ( F_44 , V_68 ) ;
# endif
}
static void F_25 ( void )
{
# ifdef F_39
signal ( V_62 , V_61 [ V_62 ] ) ;
signal ( V_63 , V_61 [ V_63 ] ) ;
signal ( V_64 , V_61 [ V_64 ] ) ;
signal ( V_33 , V_61 [ V_33 ] ) ;
signal ( V_65 , V_61 [ V_65 ] ) ;
signal ( V_66 , V_61 [ V_66 ] ) ;
# else
int V_56 ;
for ( V_56 = 1 ; V_56 < V_67 ; V_56 ++ ) {
# ifdef F_41
if ( V_56 == F_41 )
continue;
# endif
# ifdef F_42
if ( V_56 == F_42 )
continue;
# endif
# ifdef F_40
V_57 ( V_56 , & V_61 [ V_56 ] , NULL ) ;
# else
signal ( V_56 , V_61 [ V_56 ] ) ;
# endif
}
# endif
}
static void V_60 ( int V_56 )
{
V_23 = V_56 ;
}
static int F_22 ( char * V_13 , int V_69 , T_4 * V_70 )
{
int V_56 ;
char * V_21 ;
V_21 = V_13 ;
for (; ; ) {
if ( V_69 == 0 ) {
* V_21 = '\0' ;
break;
}
V_69 -- ;
# if F_13 ( V_24 )
V_56 = F_45 () ;
# else
V_56 = F_46 () ;
# endif
if ( V_56 == '\r' )
V_56 = '\n' ;
* ( V_21 ++ ) = V_56 ;
if ( V_56 == '\n' ) {
* V_21 = '\0' ;
break;
}
}
# ifdef F_47
{
T_7 V_71 ;
V_71 = F_18 ( V_29 ) ;
F_48 ( V_71 ) ;
}
# endif
return ( strlen ( V_13 ) ) ;
}
