T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 , T_3 * V_3 )
{
switch ( F_3 ( V_3 ) )
{
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
switch ( F_3 ( V_3 ) )
{
case V_8 :
fputs ( F_4 ( V_3 ) , V_6 ) ;
fputs ( F_6 ( V_3 ) , V_6 ) ;
fflush ( V_6 ) ;
return F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) & V_9 , 0 ) ;
case V_10 :
fputs ( F_4 ( V_3 ) , V_6 ) ;
fflush ( V_6 ) ;
return F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) & V_9 , 1 ) ;
case V_11 :
fprintf ( V_6 , L_1 ,
F_4 ( V_3 ) ) ;
fflush ( V_6 ) ;
if ( ( V_7 = F_7 ( V_2 , V_3 ,
F_8 ( V_3 ) & V_9 , 1 ) ) <= 0 )
return V_7 ;
if ( strcmp ( F_9 ( V_3 ) ,
F_10 ( V_3 ) ) != 0 )
{
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
static void F_11 ( T_4 * V_12 )
{
#define F_12 4
char V_13 [ F_12 + 1 ] ;
do {
fgets ( V_13 , F_12 , V_12 ) ;
} while ( strchr ( V_13 , '\n' ) == NULL );
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
#ifdef F_16
if ( ! V_14 )
{
F_17 ( V_17 , V_19 , V_24 ) ;
V_22 = V_17 ;
}
else
V_22 = fgets ( V_17 , V_19 , V_24 ) ;
#else
V_22 = fgets ( V_17 , V_19 , V_24 ) ;
#endif
if( ! V_22 )
goto error;
if ( feof ( V_24 ) ) goto error;
if ( ferror ( V_24 ) ) goto error;
if ( ( V_22 = ( char * ) strchr ( V_17 , '\n' ) ) != NULL )
{
if ( V_15 )
* V_22 = '\0' ;
}
else
F_11 ( V_24 ) ;
if ( F_18 ( V_2 , V_3 , V_17 ) >= 0 )
V_7 = 1 ;
error:
if ( V_23 == V_25 )
V_7 = - 1 ;
if ( ! V_14 ) fprintf ( V_6 , L_3 ) ;
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
#if F_13 ( V_28 ) || F_13 ( V_29 )
V_24 = V_30 ;
V_6 = V_31 ;
#else
# ifdef F_16
# define F_24 "con"
# else
# define F_24 "/dev/tty"
# endif
if ( ( V_24 = fopen ( F_24 , L_4 ) ) == NULL )
V_24 = V_30 ;
if ( ( V_6 = fopen ( F_24 , L_5 ) ) == NULL )
V_6 = V_31 ;
#endif
#if F_13 ( V_32 ) && ! F_13 ( V_33 )
if ( V_32 ( fileno ( V_24 ) , & V_34 ) == - 1 )
{
#ifdef F_25
if ( V_35 == F_25 )
V_27 = 0 ;
else
#endif
#ifdef F_26
if ( V_35 == F_26 )
V_27 = 0 ;
else
#endif
return 0 ;
}
#endif
#ifdef V_33
V_36 = F_27 ( & V_37 , & V_38 , 0 , 0 ) ;
if ( V_36 != V_39 )
return 0 ;
V_36 = F_28 ( 0 , V_38 , V_40 , & V_41 , 0 , 0 , V_34 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_36 != V_39 ) || ( V_41 . V_42 != V_39 ) )
return 0 ;
#endif
return 1 ;
}
static int F_15 ( T_2 * V_2 )
{
#ifdef F_29
memcpy ( & ( V_43 ) , & ( V_34 ) , sizeof( V_34 ) ) ;
V_43 . F_29 &= ~ V_44 ;
#endif
#if F_13 ( V_45 ) && ! F_13 ( V_33 )
if ( V_27 && ( V_45 ( fileno ( V_24 ) , & V_43 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_33
V_43 [ 0 ] = V_34 [ 0 ] ;
V_43 [ 1 ] = V_34 [ 1 ] | V_46 ;
V_43 [ 2 ] = V_34 [ 2 ] ;
V_36 = F_28 ( 0 , V_38 , V_47 , & V_41 , 0 , 0 , V_43 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_36 != V_39 ) || ( V_41 . V_42 != V_39 ) )
return 0 ;
#endif
return 1 ;
}
static int F_19 ( T_2 * V_2 )
{
#if F_13 ( V_45 ) && ! F_13 ( V_33 )
memcpy ( & ( V_43 ) , & ( V_34 ) , sizeof( V_34 ) ) ;
V_43 . F_29 |= V_44 ;
#endif
#if F_13 ( V_45 ) && ! F_13 ( V_33 )
if ( V_27 && ( V_45 ( fileno ( V_24 ) , & V_43 ) == - 1 ) )
return 0 ;
#endif
#ifdef V_33
V_43 [ 0 ] = V_34 [ 0 ] ;
V_43 [ 1 ] = V_34 [ 1 ] & ~ V_46 ;
V_43 [ 2 ] = V_34 [ 2 ] ;
V_36 = F_28 ( 0 , V_38 , V_47 , & V_41 , 0 , 0 , V_43 , 12 , 0 , 0 , 0 , 0 ) ;
if ( ( V_36 != V_39 ) || ( V_41 . V_42 != V_39 ) )
return 0 ;
#endif
return 1 ;
}
static int F_30 ( T_2 * V_2 )
{
if ( V_24 != V_31 ) fclose ( V_24 ) ;
if ( V_6 != V_31 ) fclose ( V_6 ) ;
#ifdef V_33
V_36 = F_31 ( V_38 ) ;
#endif
F_32 ( V_26 ) ;
return 1 ;
}
static void F_14 ( void )
{
int V_48 ;
#ifdef F_33
struct V_49 V_50 ;
memset ( & V_50 , 0 , sizeof V_50 ) ;
V_50 . V_51 = V_52 ;
#endif
for ( V_48 = 1 ; V_48 < V_53 ; V_48 ++ )
{
#ifdef F_34
if ( V_48 == F_34 )
continue;
#endif
#ifdef F_35
if ( V_48 == F_35 )
continue;
#endif
#ifdef F_36
if ( V_48 == F_36 )
continue;
#endif
#ifdef F_33
V_49 ( V_48 , & V_50 , & V_54 [ V_48 ] ) ;
#else
V_54 [ V_48 ] = signal ( V_48 , V_52 ) ;
#endif
}
#ifdef F_37
signal ( F_37 , V_55 ) ;
#endif
}
static void F_20 ( void )
{
int V_48 ;
for ( V_48 = 1 ; V_48 < V_53 ; V_48 ++ )
{
#ifdef F_34
if ( V_48 == F_34 )
continue;
#endif
#ifdef F_35
if ( V_48 == F_35 )
continue;
#endif
#ifdef F_33
V_49 ( V_48 , & V_54 [ V_48 ] , NULL ) ;
#else
signal ( V_48 , V_54 [ V_48 ] ) ;
#endif
}
}
static void V_52 ( int V_48 )
{
V_23 = V_48 ;
}
static int F_17 ( char * V_13 , int V_56 , T_4 * V_57 )
{
int V_48 ;
char * V_22 ;
V_22 = V_13 ;
for (; ; )
{
if ( V_56 == 0 )
{
* V_22 = '\0' ;
break;
}
V_56 -- ;
#ifdef F_38
V_48 = F_39 () ;
#else
V_48 = F_40 () ;
#endif
if ( V_48 == '\r' ) V_48 = '\n' ;
* ( V_22 ++ ) = V_48 ;
if ( V_48 == '\n' )
{
* V_22 = '\0' ;
break;
}
}
#ifdef F_41
{
T_5 V_58 ;
V_58 = F_42 ( V_59 ) ;
F_43 ( V_58 ) ;
}
#endif
return ( strlen ( V_13 ) ) ;
}
