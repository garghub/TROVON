T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( int V_2 , int V_3 )
{
T_2 * V_4 ;
V_4 = F_3 ( F_1 () ) ;
if ( V_4 == NULL )
return ( NULL ) ;
F_4 ( V_4 , V_2 , V_3 ) ;
return ( V_4 ) ;
}
static int F_5 ( T_2 * V_5 )
{
V_5 -> V_6 = 0 ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_10 )
{
if ( V_10 == NULL )
return ( 0 ) ;
if ( V_10 -> V_11 ) {
if ( V_10 -> V_6 ) {
F_7 ( V_10 -> V_7 ) ;
}
V_10 -> V_6 = 0 ;
V_10 -> V_9 = 0 ;
}
return ( 1 ) ;
}
static int F_8 ( T_2 * V_12 , char * V_13 , int V_14 )
{
int V_4 = 0 ;
if ( V_13 != NULL ) {
F_9 () ;
V_4 = F_10 ( V_12 -> V_7 , V_13 , V_14 ) ;
F_11 ( V_12 ) ;
if ( V_4 <= 0 ) {
if ( F_12 ( V_4 ) )
F_13 ( V_12 ) ;
}
}
return ( V_4 ) ;
}
static int F_14 ( T_2 * V_12 , const char * V_15 , int V_16 )
{
int V_4 ;
F_9 () ;
V_4 = F_15 ( V_12 -> V_7 , V_15 , V_16 ) ;
F_11 ( V_12 ) ;
if ( V_4 <= 0 ) {
if ( F_12 ( V_4 ) )
F_16 ( V_12 ) ;
}
return ( V_4 ) ;
}
static long F_17 ( T_2 * V_12 , int V_17 , long V_7 , void * V_8 )
{
long V_4 = 1 ;
int * V_18 ;
switch ( V_17 ) {
case V_19 :
F_6 ( V_12 ) ;
V_12 -> V_7 = * ( ( int * ) V_8 ) ;
V_12 -> V_11 = ( int ) V_7 ;
V_12 -> V_6 = 1 ;
break;
case V_20 :
if ( V_12 -> V_6 ) {
V_18 = ( int * ) V_8 ;
if ( V_18 != NULL )
* V_18 = V_12 -> V_7 ;
V_4 = V_12 -> V_7 ;
} else
V_4 = - 1 ;
break;
case V_21 :
V_4 = V_12 -> V_11 ;
break;
case V_22 :
V_12 -> V_11 = ( int ) V_7 ;
break;
case V_23 :
case V_24 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_18 ( T_2 * V_25 , const char * V_26 )
{
int V_27 , V_4 ;
V_27 = strlen ( V_26 ) ;
V_4 = F_14 ( V_25 , V_26 , V_27 ) ;
return ( V_4 ) ;
}
int F_12 ( int V_28 )
{
int V_29 ;
if ( ( V_28 == 0 ) || ( V_28 == - 1 ) ) {
V_29 = F_19 () ;
# if F_20 ( V_30 ) && 0
if ( ( V_28 == - 1 ) && ( V_29 == 0 ) )
return ( 1 ) ;
# endif
return ( F_21 ( V_29 ) ) ;
}
return ( 0 ) ;
}
int F_21 ( int V_29 )
{
switch ( V_29 ) {
# if F_20 ( V_30 ) || F_20 ( V_31 )
# if F_20 ( V_32 )
case V_32 :
# endif
# if 0
# if F_20 ( V_33 )
case WSAENOTCONN:
# endif
# endif
# endif
# ifdef F_22
# ifdef V_32
# if V_32 != F_22
case F_22 :
# endif
# else
case F_22 :
# endif
# endif
# if F_20 ( V_34 )
case V_34 :
# endif
# ifdef F_23
case F_23 :
# endif
# ifdef F_24
# if F_22 != F_24
case F_24 :
# endif
# endif
# ifdef F_25
case F_25 :
# endif
# ifdef F_26
case F_26 :
# endif
# ifdef F_27
case F_27 :
# endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
