static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = - 1 , V_4 ;
int (* F_2) ( const T_1 * , int , int ) = NULL ;
if ( V_2 -> V_5 != NULL )
F_2 = V_2 -> V_5 ;
for (; ; ) {
switch ( V_2 -> V_6 ) {
case V_7 :
if ( V_2 -> V_8 == NULL && V_2 -> V_9 == NULL ) {
F_3 ( V_10 , V_11 ) ;
F_4 ( 4 ,
L_1 , V_2 -> V_8 ,
L_2 , V_2 -> V_9 ) ;
goto V_12;
}
V_2 -> V_6 = V_13 ;
break;
case V_13 :
{
int V_14 = V_15 ;
switch ( V_2 -> V_16 ) {
case V_17 :
if ( 1 ) {
#ifdef F_5
V_14 = F_5 ;
} else {
#endif
F_3 ( V_10 , V_18 ) ;
goto V_12;
}
break;
case V_19 :
V_14 = V_20 ;
break;
case V_21 :
V_14 = V_15 ;
break;
default:
F_3 ( V_10 , V_22 ) ;
goto V_12;
}
if ( F_6 ( V_2 -> V_8 , V_2 -> V_9 ,
V_23 ,
V_14 , V_24 , & V_2 -> V_25 ) == 0 )
goto V_12;
}
if ( V_2 -> V_25 == NULL ) {
F_3 ( V_10 , V_26 ) ;
goto V_12;
}
V_2 -> V_27 = V_2 -> V_25 ;
V_2 -> V_6 = V_28 ;
break;
case V_28 :
V_3 = F_7 ( F_8 ( V_2 -> V_27 ) ,
F_9 ( V_2 -> V_27 ) ,
F_10 ( V_2 -> V_27 ) , 0 ) ;
if ( V_3 == ( int ) V_29 ) {
F_11 ( V_30 , F_12 () ) ;
F_4 ( 4 ,
L_1 , V_2 -> V_8 ,
L_2 , V_2 -> V_9 ) ;
F_3 ( V_10 , V_31 ) ;
goto V_12;
}
V_1 -> V_32 = V_3 ;
V_2 -> V_6 = V_33 ;
break;
case V_33 :
F_13 ( V_1 ) ;
V_3 = F_14 ( V_1 -> V_32 , F_15 ( V_2 -> V_27 ) ,
V_34 | V_2 -> V_35 ) ;
V_1 -> V_36 = 0 ;
if ( V_3 == 0 ) {
if ( F_16 ( V_3 ) ) {
F_17 ( V_1 ) ;
V_2 -> V_6 = V_37 ;
V_1 -> V_36 = V_38 ;
F_18 () ;
} else if ( ( V_2 -> V_27 = F_19 ( V_2 -> V_27 ) )
!= NULL ) {
F_20 ( V_1 -> V_32 ) ;
V_2 -> V_6 = V_28 ;
F_18 () ;
break;
} else {
F_11 ( V_39 , F_12 () ) ;
F_4 ( 4 ,
L_1 , V_2 -> V_8 ,
L_2 , V_2 -> V_9 ) ;
F_3 ( V_10 , V_40 ) ;
}
goto V_12;
} else {
V_2 -> V_6 = V_41 ;
}
break;
case V_37 :
V_4 = F_21 ( V_1 -> V_32 ) ;
if ( V_4 ) {
F_13 ( V_1 ) ;
F_11 ( V_39 , V_4 ) ;
F_4 ( 4 ,
L_1 , V_2 -> V_8 ,
L_2 , V_2 -> V_9 ) ;
F_3 ( V_10 , V_42 ) ;
V_3 = 0 ;
goto V_12;
} else
V_2 -> V_6 = V_41 ;
break;
case V_41 :
V_3 = 1 ;
goto V_12;
default:
goto V_12;
}
if ( F_2 != NULL ) {
if ( ( V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_6 , V_3 ) ) == 0 )
goto V_43;
}
}
V_12:
if ( F_2 != NULL )
V_3 = F_2 ( ( T_1 * ) V_1 , V_2 -> V_6 , V_3 ) ;
V_43:
return ( V_3 ) ;
}
T_2 * F_22 ( void )
{
T_2 * V_3 ;
if ( ( V_3 = F_23 ( sizeof( * V_3 ) ) ) == NULL )
return ( NULL ) ;
V_3 -> V_6 = V_7 ;
V_3 -> V_16 = V_21 ;
return ( V_3 ) ;
}
void F_24 ( T_2 * V_44 )
{
if ( V_44 == NULL )
return;
F_25 ( V_44 -> V_8 ) ;
F_25 ( V_44 -> V_9 ) ;
F_26 ( V_44 -> V_25 ) ;
F_25 ( V_44 ) ;
}
const T_3 * F_27 ( void )
{
return ( & V_45 ) ;
}
static int F_28 ( T_1 * V_46 )
{
V_46 -> V_47 = 0 ;
V_46 -> V_32 = ( int ) V_29 ;
V_46 -> V_48 = 0 ;
if ( ( V_46 -> V_49 = ( char * ) F_22 () ) == NULL )
return ( 0 ) ;
else
return ( 1 ) ;
}
static void F_29 ( T_1 * V_50 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) V_50 -> V_49 ;
if ( V_50 -> V_32 != ( int ) V_29 ) {
if ( V_2 -> V_6 == V_41 )
F_30 ( V_50 -> V_32 , 2 ) ;
F_20 ( V_50 -> V_32 ) ;
V_50 -> V_32 = ( int ) V_29 ;
}
}
static int F_31 ( T_1 * V_44 )
{
T_2 * V_51 ;
if ( V_44 == NULL )
return ( 0 ) ;
V_51 = ( T_2 * ) V_44 -> V_49 ;
if ( V_44 -> F_30 ) {
F_29 ( V_44 ) ;
F_24 ( V_51 ) ;
V_44 -> V_49 = NULL ;
V_44 -> V_48 = 0 ;
V_44 -> V_47 = 0 ;
}
return ( 1 ) ;
}
static int F_32 ( T_1 * V_1 , char * V_52 , int V_53 )
{
int V_3 = 0 ;
T_2 * V_51 ;
V_51 = ( T_2 * ) V_1 -> V_49 ;
if ( V_51 -> V_6 != V_41 ) {
V_3 = F_1 ( V_1 , V_51 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
}
if ( V_52 != NULL ) {
F_33 () ;
V_3 = F_34 ( V_1 -> V_32 , V_52 , V_53 ) ;
F_13 ( V_1 ) ;
if ( V_3 <= 0 ) {
if ( F_16 ( V_3 ) )
F_35 ( V_1 ) ;
}
}
return ( V_3 ) ;
}
static int F_36 ( T_1 * V_1 , const char * V_54 , int V_55 )
{
int V_3 ;
T_2 * V_51 ;
V_51 = ( T_2 * ) V_1 -> V_49 ;
if ( V_51 -> V_6 != V_41 ) {
V_3 = F_1 ( V_1 , V_51 ) ;
if ( V_3 <= 0 )
return ( V_3 ) ;
}
F_33 () ;
V_3 = F_37 ( V_1 -> V_32 , V_54 , V_55 ) ;
F_13 ( V_1 ) ;
if ( V_3 <= 0 ) {
if ( F_16 ( V_3 ) )
F_38 ( V_1 ) ;
}
return ( V_3 ) ;
}
static long F_39 ( T_1 * V_1 , int V_56 , long V_32 , void * V_49 )
{
T_1 * V_57 ;
int * V_58 ;
const char * * V_59 = NULL ;
long V_3 = 1 ;
T_2 * V_51 ;
V_51 = ( T_2 * ) V_1 -> V_49 ;
switch ( V_56 ) {
case V_60 :
V_3 = 0 ;
V_51 -> V_6 = V_7 ;
F_29 ( V_1 ) ;
F_26 ( V_51 -> V_25 ) ;
V_51 -> V_25 = NULL ;
V_1 -> V_48 = 0 ;
break;
case V_61 :
if ( V_51 -> V_6 != V_41 )
V_3 = ( long ) F_1 ( V_1 , V_51 ) ;
else
V_3 = 1 ;
break;
case V_62 :
if ( V_49 != NULL ) {
V_59 = ( const char * * ) V_49 ;
if ( V_32 == 0 ) {
* V_59 = V_51 -> V_8 ;
} else if ( V_32 == 1 ) {
* V_59 = V_51 -> V_9 ;
} else if ( V_32 == 2 ) {
* V_59 = ( const char * ) F_15 ( V_51 -> V_27 ) ;
} else if ( V_32 == 3 ) {
switch ( F_8 ( V_51 -> V_27 ) ) {
# ifdef F_5
case F_5 :
V_3 = V_17 ;
break;
# endif
case V_20 :
V_3 = V_19 ;
break;
case 0 :
V_3 = V_51 -> V_16 ;
break;
default:
V_3 = - 1 ;
break;
}
} else {
V_3 = 0 ;
}
} else {
V_3 = 0 ;
}
break;
case V_63 :
if ( V_49 != NULL ) {
V_1 -> V_47 = 1 ;
if ( V_32 == 0 ) {
char * V_64 = V_51 -> V_9 ;
F_25 ( V_51 -> V_8 ) ;
V_51 -> V_8 = NULL ;
V_3 = F_40 ( V_49 ,
& V_51 -> V_8 ,
& V_51 -> V_9 ,
V_65 ) ;
if ( V_64 != V_51 -> V_9 )
F_25 ( V_64 ) ;
} else if ( V_32 == 1 ) {
F_25 ( V_51 -> V_9 ) ;
V_51 -> V_9 = F_41 ( V_49 ) ;
} else if ( V_32 == 2 ) {
const T_4 * V_66 = ( const T_4 * ) V_49 ;
if ( V_3 ) {
V_51 -> V_8 = F_42 ( V_66 , 1 ) ;
V_51 -> V_9 = F_43 ( V_66 , 1 ) ;
F_26 ( V_51 -> V_25 ) ;
V_51 -> V_25 = NULL ;
V_51 -> V_27 = NULL ;
}
} else if ( V_32 == 3 ) {
V_51 -> V_16 = * ( int * ) V_49 ;
} else {
V_3 = 0 ;
}
}
break;
case V_67 :
if ( V_32 != 0 )
V_51 -> V_35 |= V_68 ;
else
V_51 -> V_35 &= ~ V_68 ;
break;
case V_69 :
V_51 -> V_35 = ( int ) V_32 ;
break;
case V_70 :
if ( V_1 -> V_47 ) {
V_58 = ( int * ) V_49 ;
if ( V_58 != NULL )
* V_58 = V_1 -> V_32 ;
V_3 = V_1 -> V_32 ;
} else
V_3 = - 1 ;
break;
case V_71 :
V_3 = V_1 -> F_30 ;
break;
case V_72 :
V_1 -> F_30 = ( int ) V_32 ;
break;
case V_73 :
case V_74 :
V_3 = 0 ;
break;
case V_75 :
break;
case V_76 :
{
V_57 = ( T_1 * ) V_49 ;
if ( V_51 -> V_8 )
F_44 ( V_57 , V_51 -> V_8 ) ;
if ( V_51 -> V_9 )
F_45 ( V_57 , V_51 -> V_9 ) ;
F_46 ( V_57 , V_51 -> V_16 ) ;
F_47 ( V_57 , V_51 -> V_35 ) ;
( void ) F_48 ( V_57 ,
( V_77 * ) V_51 -> V_5 ) ;
}
break;
case V_78 :
{
# if 0
BIOerr(BIO_F_CONN_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
ret = -1;
# else
V_3 = 0 ;
# endif
}
break;
case V_79 :
{
int (* * F_49) ( const T_1 * V_50 , int V_6 , int V_80 );
F_49 = ( int (**) ( const T_1 * V_50 , int V_6 , int V_80 ) ) V_49 ;
* F_49 = V_51 -> V_5 ;
}
break;
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static long F_50 ( T_1 * V_1 , int V_56 , V_77 * V_81 )
{
long V_3 = 1 ;
T_2 * V_51 ;
V_51 = ( T_2 * ) V_1 -> V_49 ;
switch ( V_56 ) {
case V_78 :
{
V_51 -> V_5 =
( int ( * ) ( const struct V_82 * , int , int ) ) V_81 ;
}
break;
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int F_51 ( T_1 * V_83 , const char * V_84 )
{
int V_85 , V_3 ;
V_85 = strlen ( V_84 ) ;
V_3 = F_36 ( V_83 , V_84 , V_85 ) ;
return ( V_3 ) ;
}
T_1 * F_52 ( const char * V_84 )
{
T_1 * V_3 ;
V_3 = F_53 ( F_27 () ) ;
if ( V_3 == NULL )
return ( NULL ) ;
if ( F_44 ( V_3 , V_84 ) )
return ( V_3 ) ;
F_54 ( V_3 ) ;
return ( NULL ) ;
}
