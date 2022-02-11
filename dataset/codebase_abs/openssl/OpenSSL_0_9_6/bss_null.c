T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = ( NULL ) ;
return ( 1 ) ;
}
static int F_3 ( T_2 * V_6 )
{
if ( V_6 == NULL ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_7 , char * V_8 , int V_9 )
{
return ( 0 ) ;
}
static int F_5 ( T_2 * V_7 , const char * V_10 , int V_11 )
{
return ( V_11 ) ;
}
static long F_6 ( T_2 * V_7 , int V_12 , long V_4 , void * V_5 )
{
long V_13 = 1 ;
switch ( V_12 )
{
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_13 = 1 ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
default:
V_13 = 0 ;
break;
}
return ( V_13 ) ;
}
static int F_7 ( T_2 * V_25 , char * V_26 , int V_27 )
{
return ( 0 ) ;
}
static int F_8 ( T_2 * V_25 , const char * V_28 )
{
if ( V_28 == NULL ) return ( 0 ) ;
return ( strlen ( V_28 ) ) ;
}
