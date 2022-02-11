static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = - 1 , V_4 ;
unsigned long V_5 ;
char * V_6 , * V_7 ;
int (* F_2)() = NULL ;
if ( V_2 -> V_8 != NULL )
F_2 = V_2 -> V_8 ;
for (; ; )
{
switch ( V_2 -> V_9 )
{
case V_10 :
V_6 = V_2 -> V_11 ;
if ( V_6 == NULL )
{
F_3 ( V_12 , V_13 ) ;
goto V_14;
}
for ( ; * V_6 != '\0' ; V_6 ++ )
{
if ( ( * V_6 == ':' ) || ( * V_6 == '/' ) ) break;
}
V_4 = * V_6 ;
if ( ( V_4 == ':' ) || ( V_4 == '/' ) )
{
* ( V_6 ++ ) = '\0' ;
if ( V_4 == ':' )
{
for ( V_7 = V_6 ; * V_7 ; V_7 ++ )
if ( * V_7 == '/' )
{
* V_7 = '\0' ;
break;
}
if ( V_2 -> V_15 != NULL )
F_4 ( V_2 -> V_15 ) ;
V_2 -> V_15 = F_5 ( V_6 ) ;
}
}
if ( V_2 -> V_15 == NULL )
{
F_3 ( V_12 , V_16 ) ;
F_6 ( 2 , L_1 , V_2 -> V_11 ) ;
goto V_14;
}
V_2 -> V_9 = V_17 ;
break;
case V_17 :
if ( F_7 ( V_2 -> V_11 , & ( V_2 -> V_18 [ 0 ] ) ) <= 0 )
goto V_14;
V_2 -> V_9 = V_19 ;
break;
case V_19 :
if ( V_2 -> V_15 == NULL )
{
goto V_14;
}
else if ( F_8 ( V_2 -> V_15 , & V_2 -> V_20 ) <= 0 )
goto V_14;
V_2 -> V_9 = V_21 ;
break;
case V_21 :
memset ( ( char * ) & V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = F_9 ( ( unsigned short ) V_2 -> V_20 ) ;
V_5 = ( unsigned long )
( ( unsigned long ) V_2 -> V_18 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 -> V_18 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 -> V_18 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 -> V_18 [ 3 ] ) ;
V_2 -> V_22 . V_26 . V_27 = F_10 ( V_5 ) ;
V_2 -> V_9 = V_21 ;
V_3 = F_11 ( V_24 , V_28 , V_29 ) ;
if ( V_3 == V_30 )
{
F_12 ( V_31 , F_13 () ) ;
F_6 ( 4 , L_1 , V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_32 ) ;
goto V_14;
}
V_1 -> V_33 = V_3 ;
V_2 -> V_9 = V_34 ;
break;
case V_34 :
if ( V_2 -> V_35 )
{
if ( ! F_14 ( V_1 -> V_33 , 1 ) )
{
F_3 ( V_12 , V_36 ) ;
F_6 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
goto V_14;
}
}
V_2 -> V_9 = V_37 ;
#if F_15 ( V_38 ) && ! F_15 ( V_39 )
V_4 = 1 ;
V_4 = F_16 ( V_1 -> V_33 , V_40 , V_38 , ( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_4 < 0 )
{
F_12 ( V_31 , F_13 () ) ;
F_6 ( 4 , L_1 , V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_41 ) ;
goto V_14;
}
#endif
break;
case V_37 :
F_17 ( V_1 ) ;
V_3 = F_18 ( V_1 -> V_33 ,
(struct V_42 * ) & V_2 -> V_22 ,
sizeof( V_2 -> V_22 ) ) ;
V_1 -> V_43 = 0 ;
if ( V_3 < 0 )
{
if ( F_19 ( V_3 ) )
{
F_20 ( V_1 ) ;
V_2 -> V_9 = V_44 ;
V_1 -> V_43 = V_45 ;
}
else
{
F_12 ( V_46 , F_13 () ) ;
F_6 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_47 ) ;
}
goto V_14;
}
else
V_2 -> V_9 = V_48 ;
break;
case V_44 :
V_4 = F_21 ( V_1 -> V_33 ) ;
if ( V_4 )
{
F_17 ( V_1 ) ;
F_12 ( V_46 , V_4 ) ;
F_6 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_49 ) ;
V_3 = 0 ;
goto V_14;
}
else
V_2 -> V_9 = V_48 ;
break;
case V_48 :
V_3 = 1 ;
goto V_14;
default:
goto V_14;
}
if ( F_2 != NULL )
{
if ( ! ( V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_9 , V_3 ) ) )
goto V_50;
}
}
V_14:
if ( F_2 != NULL )
V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_9 , V_3 ) ;
V_50:
return ( V_3 ) ;
}
T_2 * F_22 ( void )
{
T_2 * V_3 ;
if ( ( V_3 = ( T_2 * ) F_23 ( sizeof( T_2 ) ) ) == NULL )
return ( NULL ) ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_8 = NULL ;
V_3 -> V_35 = 0 ;
V_3 -> V_18 [ 0 ] = 0 ;
V_3 -> V_18 [ 1 ] = 0 ;
V_3 -> V_18 [ 2 ] = 0 ;
V_3 -> V_18 [ 3 ] = 0 ;
V_3 -> V_20 = 0 ;
memset ( ( char * ) & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
return ( V_3 ) ;
}
void F_24 ( T_2 * V_51 )
{
if( V_51 == NULL )
return;
if ( V_51 -> V_11 != NULL )
F_4 ( V_51 -> V_11 ) ;
if ( V_51 -> V_15 != NULL )
F_4 ( V_51 -> V_15 ) ;
F_4 ( V_51 ) ;
}
T_3 * F_25 ( void )
{
return ( & V_52 ) ;
}
static int F_26 ( T_1 * V_53 )
{
V_53 -> V_54 = 0 ;
V_53 -> V_33 = V_30 ;
V_53 -> V_55 = 0 ;
if ( ( V_53 -> V_56 = ( char * ) F_22 () ) == NULL )
return ( 0 ) ;
else
return ( 1 ) ;
}
static void F_27 ( T_1 * V_57 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) V_57 -> V_56 ;
if ( V_57 -> V_33 != V_30 )
{
if ( V_2 -> V_9 == V_48 )
F_28 ( V_57 -> V_33 , 2 ) ;
F_29 ( V_57 -> V_33 ) ;
V_57 -> V_33 = V_30 ;
}
}
static int F_30 ( T_1 * V_51 )
{
T_2 * V_58 ;
if ( V_51 == NULL ) return ( 0 ) ;
V_58 = ( T_2 * ) V_51 -> V_56 ;
if ( V_51 -> F_28 )
{
F_27 ( V_51 ) ;
F_24 ( V_58 ) ;
V_51 -> V_56 = NULL ;
V_51 -> V_55 = 0 ;
V_51 -> V_54 = 0 ;
}
return ( 1 ) ;
}
static int F_31 ( T_1 * V_1 , char * V_59 , int V_60 )
{
int V_3 = 0 ;
T_2 * V_58 ;
V_58 = ( T_2 * ) V_1 -> V_56 ;
if ( V_58 -> V_9 != V_48 )
{
V_3 = F_1 ( V_1 , V_58 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
}
if ( V_59 != NULL )
{
F_32 () ;
V_3 = F_33 ( V_1 -> V_33 , V_59 , V_60 ) ;
F_17 ( V_1 ) ;
if ( V_3 <= 0 )
{
if ( F_19 ( V_3 ) )
F_34 ( V_1 ) ;
}
}
return ( V_3 ) ;
}
static int F_35 ( T_1 * V_1 , const char * V_61 , int V_62 )
{
int V_3 ;
T_2 * V_58 ;
V_58 = ( T_2 * ) V_1 -> V_56 ;
if ( V_58 -> V_9 != V_48 )
{
V_3 = F_1 ( V_1 , V_58 ) ;
if ( V_3 <= 0 ) return ( V_3 ) ;
}
F_32 () ;
V_3 = F_36 ( V_1 -> V_33 , V_61 , V_62 ) ;
F_17 ( V_1 ) ;
if ( V_3 <= 0 )
{
if ( F_19 ( V_3 ) )
F_37 ( V_1 ) ;
}
return ( V_3 ) ;
}
static long F_38 ( T_1 * V_1 , int V_63 , long V_33 , void * V_56 )
{
T_1 * V_64 ;
int * V_18 ;
const char * * V_65 ;
long V_3 = 1 ;
T_2 * V_58 ;
V_58 = ( T_2 * ) V_1 -> V_56 ;
switch ( V_63 )
{
case V_66 :
V_3 = 0 ;
V_58 -> V_9 = V_10 ;
F_27 ( V_1 ) ;
V_1 -> V_55 = 0 ;
break;
case V_67 :
if ( ! V_58 -> V_9 != V_48 )
V_3 = ( long ) F_1 ( V_1 , V_58 ) ;
else
V_3 = 1 ;
break;
case V_68 :
if ( V_56 != NULL )
{
V_65 = ( const char * * ) V_56 ;
if ( V_33 == 0 )
{
* V_65 = V_58 -> V_11 ;
}
else if ( V_33 == 1 )
{
* V_65 = V_58 -> V_15 ;
}
else if ( V_33 == 2 )
{
* V_65 = ( char * ) & ( V_58 -> V_18 [ 0 ] ) ;
}
else if ( V_33 == 3 )
{
* ( ( int * ) V_56 ) = V_58 -> V_20 ;
}
if ( ( ! V_1 -> V_54 ) || ( V_56 == NULL ) )
* V_65 = L_3 ;
V_3 = 1 ;
}
break;
case V_69 :
if ( V_56 != NULL )
{
V_1 -> V_54 = 1 ;
if ( V_33 == 0 )
{
if ( V_58 -> V_11 != NULL )
F_4 ( V_58 -> V_11 ) ;
V_58 -> V_11 = F_5 ( V_56 ) ;
}
else if ( V_33 == 1 )
{
if ( V_58 -> V_15 != NULL )
F_4 ( V_58 -> V_15 ) ;
V_58 -> V_15 = F_5 ( V_56 ) ;
}
else if ( V_33 == 2 )
{
char V_70 [ 16 ] ;
char * V_6 = V_56 ;
sprintf ( V_70 , L_4 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] , V_6 [ 3 ] ) ;
if ( V_58 -> V_11 != NULL )
F_4 ( V_58 -> V_11 ) ;
V_58 -> V_11 = F_5 ( V_70 ) ;
memcpy ( & ( V_58 -> V_18 [ 0 ] ) , V_56 , 4 ) ;
}
else if ( V_33 == 3 )
{
char V_70 [ 16 ] ;
sprintf ( V_70 , L_5 , * ( int * ) V_56 ) ;
if ( V_58 -> V_15 != NULL )
F_4 ( V_58 -> V_15 ) ;
V_58 -> V_15 = F_5 ( V_70 ) ;
V_58 -> V_20 = * ( int * ) V_56 ;
}
}
break;
case V_71 :
V_58 -> V_35 = ( int ) V_33 ;
break;
case V_72 :
if ( V_1 -> V_54 )
{
V_18 = ( int * ) V_56 ;
if ( V_18 != NULL )
* V_18 = V_1 -> V_33 ;
V_3 = V_1 -> V_33 ;
}
else
V_3 = - 1 ;
break;
case V_73 :
V_3 = V_1 -> F_28 ;
break;
case V_74 :
V_1 -> F_28 = ( int ) V_33 ;
break;
case V_75 :
case V_76 :
V_3 = 0 ;
break;
case V_77 :
break;
case V_78 :
{
V_64 = ( T_1 * ) V_56 ;
if ( V_58 -> V_15 )
F_39 ( V_64 , V_58 -> V_15 ) ;
if ( V_58 -> V_11 )
F_40 ( V_64 , V_58 -> V_11 ) ;
F_41 ( V_64 , V_58 -> V_35 ) ;
( void ) F_42 ( V_64 , V_58 -> V_8 ) ;
}
break;
case V_79 :
{
#if 0
BIOerr(BIO_F_CONN_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
ret = -1;
#else
V_3 = 0 ;
#endif
}
break;
case V_80 :
{
int (* * F_43)();
F_43 = ( int ( * * ) () ) V_56 ;
* F_43 = V_58 -> V_8 ;
}
break;
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static long F_44 ( T_1 * V_1 , int V_63 , T_4 * V_81 )
{
long V_3 = 1 ;
T_2 * V_58 ;
V_58 = ( T_2 * ) V_1 -> V_56 ;
switch ( V_63 )
{
case V_79 :
{
V_58 -> V_8 = ( int ( * ) () ) V_81 ;
}
break;
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int F_45 ( T_1 * V_82 , const char * V_83 )
{
int V_84 , V_3 ;
V_84 = strlen ( V_83 ) ;
V_3 = F_35 ( V_82 , V_83 , V_84 ) ;
return ( V_3 ) ;
}
T_1 * F_46 ( char * V_83 )
{
T_1 * V_3 ;
V_3 = F_47 ( F_25 () ) ;
if ( V_3 == NULL ) return ( NULL ) ;
if ( F_40 ( V_3 , V_83 ) )
return ( V_3 ) ;
else
{
F_48 ( V_3 ) ;
return ( NULL ) ;
}
}
