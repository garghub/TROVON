T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( int V_2 , int V_3 )
{
T_2 * V_4 ;
V_4 = F_3 ( F_1 () ) ;
if ( V_4 == NULL ) return ( NULL ) ;
F_4 ( V_4 , V_2 , V_3 ) ;
return ( V_4 ) ;
}
static int F_5 ( T_2 * V_5 )
{
V_5 -> V_6 = 0 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = V_10 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_11 )
{
if ( V_11 == NULL ) return ( 0 ) ;
if ( V_11 -> V_12 )
{
if ( V_11 -> V_6 )
{
F_7 ( V_11 -> V_7 ) ;
}
V_11 -> V_6 = 0 ;
V_11 -> V_9 = V_10 ;
}
return ( 1 ) ;
}
static int F_8 ( T_2 * V_13 , char * V_14 , int V_15 )
{
int V_4 = 0 ;
if ( V_14 != NULL )
{
F_9 () ;
V_4 = F_10 ( V_13 -> V_7 , V_14 , V_15 ) ;
F_11 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_12 ( V_4 ) )
F_13 ( V_13 ) ;
}
}
return ( V_4 ) ;
}
static int F_14 ( T_2 * V_13 , const char * V_16 , int V_17 )
{
int V_4 ;
F_9 () ;
V_4 = F_15 ( V_13 -> V_7 , V_16 , V_17 ) ;
F_11 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_12 ( V_4 ) )
F_16 ( V_13 ) ;
}
return ( V_4 ) ;
}
static long F_17 ( T_2 * V_13 , int V_18 , long V_7 , void * V_8 )
{
long V_4 = 1 ;
int * V_19 ;
switch ( V_18 )
{
case V_20 :
V_7 = 0 ;
case V_21 :
V_4 = ( long ) F_18 ( V_13 -> V_7 , V_7 , 0 ) ;
break;
case V_22 :
case V_23 :
V_4 = ( long ) F_18 ( V_13 -> V_7 , 0 , 1 ) ;
break;
case V_24 :
F_6 ( V_13 ) ;
V_13 -> V_7 = * ( ( int * ) V_8 ) ;
V_13 -> V_12 = ( int ) V_7 ;
V_13 -> V_6 = 1 ;
break;
case V_25 :
if ( V_13 -> V_6 )
{
V_19 = ( int * ) V_8 ;
if ( V_19 != NULL ) * V_19 = V_13 -> V_7 ;
V_4 = V_13 -> V_7 ;
}
else
V_4 = - 1 ;
break;
case V_26 :
V_4 = V_13 -> V_12 ;
break;
case V_27 :
V_13 -> V_12 = ( int ) V_7 ;
break;
case V_28 :
case V_29 :
V_4 = 0 ;
break;
case V_30 :
case V_31 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_19 ( T_2 * V_32 , const char * V_33 )
{
int V_34 , V_4 ;
V_34 = strlen ( V_33 ) ;
V_4 = F_14 ( V_32 , V_33 , V_34 ) ;
return ( V_4 ) ;
}
static int F_20 ( T_2 * V_32 , char * V_35 , int V_36 )
{
int V_4 = 0 ;
char * V_8 = V_35 ;
char * V_37 = V_35 + V_36 - 1 ;
while ( ( V_8 < V_37 ) && ( F_8 ( V_32 , V_8 , 1 ) > 0 ) && ( V_8 [ 0 ] != '\n' ) )
V_8 ++ ;
V_8 [ 0 ] = '\0' ;
if ( V_35 [ 0 ] != '\0' )
V_4 = strlen ( V_35 ) ;
return ( V_4 ) ;
}
int F_12 ( int V_38 )
{
int V_39 ;
if ( ( V_38 == 0 ) || ( V_38 == - 1 ) )
{
V_39 = F_21 () ;
#if F_22 ( V_40 ) && 0
if ( ( V_38 == - 1 ) && ( V_39 == 0 ) )
return ( 1 ) ;
#endif
return ( F_23 ( V_39 ) ) ;
}
return ( 0 ) ;
}
int F_23 ( int V_39 )
{
switch ( V_39 )
{
#ifdef F_24
# ifdef F_25
# if F_25 != F_24
case F_24 :
# endif
# else
case F_24 :
# endif
#endif
#if F_22 ( V_41 )
case V_41 :
#endif
#ifdef F_26
case F_26 :
#endif
#ifdef F_27
#if F_24 != F_27
case F_27 :
# endif
#endif
#ifdef F_28
case F_28 :
#endif
#ifdef F_29
case F_29 :
#endif
#ifdef F_30
case F_30 :
#endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
