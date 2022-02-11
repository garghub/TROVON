T_1 * F_1 ( int V_1 , int V_2 )
{
return NULL ;
}
int F_2 ( int V_3 )
{
return 0 ;
}
int F_3 ( int V_4 )
{
return 0 ;
}
const T_2 * F_4 ( void )
{
return NULL ;
}
const T_2 * F_4 ( void )
{
return ( & V_5 ) ;
}
T_1 * F_1 ( int V_1 , int V_2 )
{
T_1 * V_6 ;
V_6 = F_5 ( F_4 () ) ;
if ( V_6 == NULL )
return ( NULL ) ;
F_6 ( V_6 , V_1 , V_2 ) ;
return ( V_6 ) ;
}
static int F_7 ( T_1 * V_7 )
{
V_7 -> V_8 = 0 ;
V_7 -> V_9 = - 1 ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = V_12 ;
return ( 1 ) ;
}
static int F_8 ( T_1 * V_13 )
{
if ( V_13 == NULL )
return ( 0 ) ;
if ( V_13 -> V_14 ) {
if ( V_13 -> V_8 ) {
F_9 ( V_13 -> V_9 ) ;
}
V_13 -> V_8 = 0 ;
V_13 -> V_11 = V_12 ;
}
return ( 1 ) ;
}
static int F_10 ( T_1 * V_15 , char * V_16 , int V_17 )
{
int V_6 = 0 ;
if ( V_16 != NULL ) {
F_11 () ;
V_6 = F_12 ( V_15 -> V_9 , V_16 , V_17 ) ;
F_13 ( V_15 ) ;
if ( V_6 <= 0 ) {
if ( F_3 ( V_6 ) )
F_14 ( V_15 ) ;
}
}
return ( V_6 ) ;
}
static int F_15 ( T_1 * V_15 , const char * V_18 , int V_19 )
{
int V_6 ;
F_11 () ;
V_6 = F_16 ( V_15 -> V_9 , V_18 , V_19 ) ;
F_13 ( V_15 ) ;
if ( V_6 <= 0 ) {
if ( F_3 ( V_6 ) )
F_17 ( V_15 ) ;
}
return ( V_6 ) ;
}
static long F_18 ( T_1 * V_15 , int V_20 , long V_9 , void * V_10 )
{
long V_6 = 1 ;
int * V_21 ;
switch ( V_20 ) {
case V_22 :
V_9 = 0 ;
case V_23 :
V_6 = ( long ) F_19 ( V_15 -> V_9 , V_9 , 0 ) ;
break;
case V_24 :
case V_25 :
V_6 = ( long ) F_19 ( V_15 -> V_9 , 0 , 1 ) ;
break;
case V_26 :
F_8 ( V_15 ) ;
V_15 -> V_9 = * ( ( int * ) V_10 ) ;
V_15 -> V_14 = ( int ) V_9 ;
V_15 -> V_8 = 1 ;
break;
case V_27 :
if ( V_15 -> V_8 ) {
V_21 = ( int * ) V_10 ;
if ( V_21 != NULL )
* V_21 = V_15 -> V_9 ;
V_6 = V_15 -> V_9 ;
} else
V_6 = - 1 ;
break;
case V_28 :
V_6 = V_15 -> V_14 ;
break;
case V_29 :
V_15 -> V_14 = ( int ) V_9 ;
break;
case V_30 :
case V_31 :
V_6 = 0 ;
break;
case V_32 :
case V_33 :
V_6 = 1 ;
break;
default:
V_6 = 0 ;
break;
}
return ( V_6 ) ;
}
static int F_20 ( T_1 * V_34 , const char * V_35 )
{
int V_36 , V_6 ;
V_36 = strlen ( V_35 ) ;
V_6 = F_15 ( V_34 , V_35 , V_36 ) ;
return ( V_6 ) ;
}
static int F_21 ( T_1 * V_34 , char * V_37 , int V_38 )
{
int V_6 = 0 ;
char * V_10 = V_37 ;
char * V_39 = V_37 + V_38 - 1 ;
while ( ( V_10 < V_39 ) && ( F_10 ( V_34 , V_10 , 1 ) > 0 ) && ( V_10 [ 0 ] != '\n' ) )
V_10 ++ ;
V_10 [ 0 ] = '\0' ;
if ( V_37 [ 0 ] != '\0' )
V_6 = strlen ( V_37 ) ;
return ( V_6 ) ;
}
int F_3 ( int V_4 )
{
int V_3 ;
if ( ( V_4 == 0 ) || ( V_4 == - 1 ) ) {
V_3 = F_22 () ;
return ( F_2 ( V_3 ) ) ;
}
return ( 0 ) ;
}
int F_2 ( int V_3 )
{
switch ( V_3 ) {
# ifdef F_23
# ifdef F_24
# if F_24 != F_23
case F_23 :
# endif
# else
case F_23 :
# endif
# endif
# if F_25 ( V_40 )
case V_40 :
# endif
# ifdef F_26
case F_26 :
# endif
# ifdef F_27
# if F_23 != F_27
case F_27 :
# endif
# endif
# ifdef F_28
case F_28 :
# endif
# ifdef F_29
case F_29 :
# endif
# ifdef F_30
case F_30 :
# endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
