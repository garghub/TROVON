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
Free ( V_2 -> V_15 ) ;
V_2 -> V_15 = F_4 ( V_6 ) ;
}
}
if ( V_2 -> V_15 == NULL )
{
F_3 ( V_12 , V_16 ) ;
F_5 ( 2 , L_1 , V_2 -> V_11 ) ;
goto V_14;
}
V_2 -> V_9 = V_17 ;
break;
case V_17 :
if ( F_6 ( V_2 -> V_11 , & ( V_2 -> V_18 [ 0 ] ) ) <= 0 )
goto V_14;
V_2 -> V_9 = V_19 ;
break;
case V_19 :
if ( V_2 -> V_15 == NULL )
{
abort () ;
goto V_14;
}
else if ( F_7 ( V_2 -> V_15 , & V_2 -> V_20 ) <= 0 )
goto V_14;
V_2 -> V_9 = V_21 ;
break;
case V_21 :
memset ( ( char * ) & V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = F_8 ( ( unsigned short ) V_2 -> V_20 ) ;
V_5 = ( unsigned long )
( ( unsigned long ) V_2 -> V_18 [ 0 ] << 24L ) |
( ( unsigned long ) V_2 -> V_18 [ 1 ] << 16L ) |
( ( unsigned long ) V_2 -> V_18 [ 2 ] << 8L ) |
( ( unsigned long ) V_2 -> V_18 [ 3 ] ) ;
V_2 -> V_22 . V_26 . V_27 = F_9 ( V_5 ) ;
V_2 -> V_9 = V_21 ;
V_3 = F_10 ( V_24 , V_28 , V_29 ) ;
if ( V_3 == V_30 )
{
F_11 ( V_31 , F_12 () ) ;
F_5 ( 4 , L_1 , V_2 -> V_11 ,
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
if ( ! F_13 ( V_1 -> V_33 , 1 ) )
{
F_3 ( V_12 , V_36 ) ;
F_5 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
goto V_14;
}
}
V_2 -> V_9 = V_37 ;
#ifdef F_14
V_4 = 1 ;
V_4 = F_15 ( V_1 -> V_33 , V_38 , F_14 , ( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_4 < 0 )
{
F_11 ( V_31 , F_12 () ) ;
F_5 ( 4 , L_1 , V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_39 ) ;
goto V_14;
}
#endif
break;
case V_37 :
F_16 ( V_1 ) ;
V_3 = F_17 ( V_1 -> V_33 ,
(struct V_40 * ) & V_2 -> V_22 ,
sizeof( V_2 -> V_22 ) ) ;
V_1 -> V_41 = 0 ;
if ( V_3 < 0 )
{
if ( F_18 ( V_3 ) )
{
F_19 ( V_1 ) ;
V_2 -> V_9 = V_42 ;
V_1 -> V_41 = V_43 ;
}
else
{
F_11 ( V_44 , F_12 () ) ;
F_5 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_45 ) ;
}
goto V_14;
}
else
V_2 -> V_9 = V_46 ;
break;
case V_42 :
V_4 = F_20 ( V_1 -> V_33 ) ;
if ( V_4 )
{
F_16 ( V_1 ) ;
F_11 ( V_44 , V_4 ) ;
F_5 ( 4 , L_1 ,
V_2 -> V_11 ,
L_2 , V_2 -> V_15 ) ;
F_3 ( V_12 , V_47 ) ;
V_3 = 0 ;
goto V_14;
}
else
V_2 -> V_9 = V_46 ;
break;
case V_46 :
V_3 = 1 ;
goto V_14;
default:
abort () ;
goto V_14;
}
if ( F_2 != NULL )
{
if ( ! ( V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_9 , V_3 ) ) )
goto V_48;
}
}
V_14:
if ( F_2 != NULL )
V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_9 , V_3 ) ;
V_48:
return ( V_3 ) ;
}
T_2 * F_21 ( void )
{
T_2 * V_3 ;
if ( ( V_3 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ) == NULL )
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
void F_22 ( T_2 * V_49 )
{
if( V_49 == NULL )
return;
if ( V_49 -> V_11 != NULL )
Free ( V_49 -> V_11 ) ;
if ( V_49 -> V_15 != NULL )
Free ( V_49 -> V_15 ) ;
Free ( V_49 ) ;
}
T_3 * F_23 ( void )
{
return ( & V_50 ) ;
}
static int F_24 ( T_1 * V_51 )
{
V_51 -> V_52 = 0 ;
V_51 -> V_33 = V_30 ;
V_51 -> V_53 = 0 ;
if ( ( V_51 -> V_54 = ( char * ) F_21 () ) == NULL )
return ( 0 ) ;
else
return ( 1 ) ;
}
static void F_25 ( T_1 * V_55 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) V_55 -> V_54 ;
if ( V_55 -> V_33 != V_30 )
{
if ( V_2 -> V_9 == V_46 )
F_26 ( V_55 -> V_33 , 2 ) ;
F_27 ( V_55 -> V_33 ) ;
V_55 -> V_33 = V_30 ;
}
}
static int F_28 ( T_1 * V_49 )
{
T_2 * V_56 ;
if ( V_49 == NULL ) return ( 0 ) ;
V_56 = ( T_2 * ) V_49 -> V_54 ;
if ( V_49 -> F_26 )
{
F_25 ( V_49 ) ;
F_22 ( V_56 ) ;
V_49 -> V_54 = NULL ;
V_49 -> V_53 = 0 ;
V_49 -> V_52 = 0 ;
}
return ( 1 ) ;
}
static int F_29 ( T_1 * V_1 , char * V_57 , int V_58 )
{
int V_3 = 0 ;
T_2 * V_56 ;
V_56 = ( T_2 * ) V_1 -> V_54 ;
if ( V_56 -> V_9 != V_46 )
{
V_3 = F_1 ( V_1 , V_56 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
}
if ( V_57 != NULL )
{
F_30 () ;
V_3 = F_31 ( V_1 -> V_33 , V_57 , V_58 ) ;
F_16 ( V_1 ) ;
if ( V_3 <= 0 )
{
if ( F_18 ( V_3 ) )
F_32 ( V_1 ) ;
}
}
return ( V_3 ) ;
}
static int F_33 ( T_1 * V_1 , char * V_59 , int V_60 )
{
int V_3 ;
T_2 * V_56 ;
V_56 = ( T_2 * ) V_1 -> V_54 ;
if ( V_56 -> V_9 != V_46 )
{
V_3 = F_1 ( V_1 , V_56 ) ;
if ( V_3 <= 0 ) return ( V_3 ) ;
}
F_30 () ;
V_3 = F_34 ( V_1 -> V_33 , V_59 , V_60 ) ;
F_16 ( V_1 ) ;
if ( V_3 <= 0 )
{
if ( F_18 ( V_3 ) )
F_35 ( V_1 ) ;
}
return ( V_3 ) ;
}
static long F_36 ( T_1 * V_1 , int V_61 , long V_33 , char * V_54 )
{
T_1 * V_62 ;
int * V_18 ;
const char * * V_63 ;
long V_3 = 1 ;
T_2 * V_56 ;
V_56 = ( T_2 * ) V_1 -> V_54 ;
switch ( V_61 )
{
case V_64 :
V_3 = 0 ;
V_56 -> V_9 = V_10 ;
F_25 ( V_1 ) ;
V_1 -> V_53 = 0 ;
break;
case V_65 :
if ( ! V_56 -> V_9 != V_46 )
V_3 = ( long ) F_1 ( V_1 , V_56 ) ;
else
V_3 = 1 ;
break;
case V_66 :
if ( V_54 != NULL )
{
V_63 = ( const char * * ) V_54 ;
if ( V_33 == 0 )
{
* V_63 = V_56 -> V_11 ;
}
else if ( V_33 == 1 )
{
* V_63 = V_56 -> V_15 ;
}
else if ( V_33 == 2 )
{
* V_63 = ( char * ) & ( V_56 -> V_18 [ 0 ] ) ;
}
else if ( V_33 == 3 )
{
* ( ( int * ) V_54 ) = V_56 -> V_20 ;
}
if ( ( ! V_1 -> V_52 ) || ( V_54 == NULL ) )
* V_63 = L_3 ;
V_3 = 1 ;
}
break;
case V_67 :
if ( V_54 != NULL )
{
V_1 -> V_52 = 1 ;
if ( V_33 == 0 )
{
if ( V_56 -> V_11 != NULL )
Free ( V_56 -> V_11 ) ;
V_56 -> V_11 = F_4 ( V_54 ) ;
}
else if ( V_33 == 1 )
{
if ( V_56 -> V_15 != NULL )
Free ( V_56 -> V_15 ) ;
V_56 -> V_15 = F_4 ( V_54 ) ;
}
else if ( V_33 == 2 )
{
char V_68 [ 16 ] ;
sprintf ( V_68 , L_4 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ) ;
if ( V_56 -> V_11 != NULL )
Free ( V_56 -> V_11 ) ;
V_56 -> V_11 = F_4 ( V_68 ) ;
memcpy ( & ( V_56 -> V_18 [ 0 ] ) , V_54 , 4 ) ;
}
else if ( V_33 == 3 )
{
char V_68 [ 16 ] ;
sprintf ( V_68 , L_5 , * ( int * ) V_54 ) ;
if ( V_56 -> V_15 != NULL )
Free ( V_56 -> V_15 ) ;
V_56 -> V_15 = F_4 ( V_68 ) ;
V_56 -> V_20 = * ( int * ) V_54 ;
}
}
break;
case V_69 :
V_56 -> V_35 = ( int ) V_33 ;
break;
case V_70 :
if ( V_1 -> V_52 )
{
V_18 = ( int * ) V_54 ;
if ( V_18 != NULL )
* V_18 = V_1 -> V_33 ;
V_3 = V_1 -> V_33 ;
}
else
V_3 = - 1 ;
break;
case V_71 :
V_3 = V_1 -> F_26 ;
break;
case V_72 :
V_1 -> F_26 = ( int ) V_33 ;
break;
case V_73 :
case V_74 :
V_3 = 0 ;
break;
case V_75 :
break;
case V_76 :
V_62 = ( T_1 * ) V_54 ;
if ( V_56 -> V_15 )
F_37 ( V_62 , V_56 -> V_15 ) ;
if ( V_56 -> V_11 )
F_38 ( V_62 , V_56 -> V_11 ) ;
F_39 ( V_62 , V_56 -> V_35 ) ;
( void ) F_40 ( V_62 , V_56 -> V_8 ) ;
break;
case V_77 :
V_56 -> V_8 = ( int ( * ) () ) V_54 ;
break;
case V_78 :
{
int (* * F_41)();
F_41 = ( int ( * * ) () ) V_54 ;
* F_41 = V_56 -> V_8 ;
}
break;
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int F_42 ( T_1 * V_79 , char * V_80 )
{
int V_81 , V_3 ;
V_81 = strlen ( V_80 ) ;
V_3 = F_33 ( V_79 , V_80 , V_81 ) ;
return ( V_3 ) ;
}
T_1 * F_43 ( char * V_80 )
{
T_1 * V_3 ;
V_3 = F_44 ( F_23 () ) ;
if ( V_3 == NULL ) return ( NULL ) ;
if ( F_38 ( V_3 , V_80 ) )
return ( V_3 ) ;
else
{
F_45 ( V_3 ) ;
return ( NULL ) ;
}
}
