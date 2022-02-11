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
V_5 -> V_7 = 0 ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_10 )
{
if ( V_10 == NULL ) return ( 0 ) ;
if ( V_10 -> V_11 )
{
if ( V_10 -> V_6 )
{
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
if ( V_13 != NULL )
{
F_9 () ;
V_4 = F_10 ( V_12 -> V_7 , V_13 , V_14 ) ;
F_11 ( V_12 ) ;
if ( V_4 <= 0 )
{
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
if ( V_4 <= 0 )
{
if ( F_12 ( V_4 ) )
F_16 ( V_12 ) ;
}
return ( V_4 ) ;
}
static long F_17 ( T_2 * V_12 , int V_17 , long V_7 , void * V_8 )
{
long V_4 = 1 ;
int * V_18 ;
switch ( V_17 )
{
case V_19 :
V_7 = 0 ;
case V_20 :
V_4 = ( long ) F_18 ( V_12 -> V_7 , V_7 , 0 ) ;
break;
case V_21 :
case V_22 :
V_4 = ( long ) F_18 ( V_12 -> V_7 , 0 , 1 ) ;
break;
case V_23 :
F_6 ( V_12 ) ;
V_12 -> V_7 = * ( ( int * ) V_8 ) ;
V_12 -> V_11 = ( int ) V_7 ;
V_12 -> V_6 = 1 ;
break;
case V_24 :
if ( V_12 -> V_6 )
{
V_18 = ( int * ) V_8 ;
if ( V_18 != NULL ) * V_18 = V_12 -> V_7 ;
V_4 = V_12 -> V_7 ;
}
else
V_4 = - 1 ;
break;
case V_25 :
V_4 = V_12 -> V_11 ;
break;
case V_26 :
V_12 -> V_11 = ( int ) V_7 ;
break;
case V_27 :
case V_28 :
V_4 = 0 ;
break;
case V_29 :
case V_30 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_19 ( T_2 * V_31 , const char * V_32 )
{
int V_33 , V_4 ;
V_33 = strlen ( V_32 ) ;
V_4 = F_14 ( V_31 , V_32 , V_33 ) ;
return ( V_4 ) ;
}
int F_12 ( int V_34 )
{
int V_35 ;
if ( ( V_34 == 0 ) || ( V_34 == - 1 ) )
{
V_35 = F_20 () ;
#if F_21 ( V_36 ) && 0
if ( ( V_34 == - 1 ) && ( V_35 == 0 ) )
return ( 1 ) ;
#endif
return ( F_22 ( V_35 ) ) ;
}
return ( 0 ) ;
}
int F_22 ( int V_35 )
{
switch ( V_35 )
{
#ifdef F_23
# ifdef F_24
# if F_24 != F_23
case F_23 :
# endif
# else
case F_23 :
# endif
#endif
#if F_21 ( V_37 )
case V_37 :
#endif
#ifdef F_25
case F_25 :
#endif
#ifdef F_26
#if F_23 != F_26
case F_26 :
# endif
#endif
#ifdef F_27
case F_27 :
#endif
#ifdef F_28
case F_28 :
#endif
#ifdef F_29
case F_29 :
#endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
