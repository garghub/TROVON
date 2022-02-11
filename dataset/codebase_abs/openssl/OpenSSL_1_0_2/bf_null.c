T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = 0 ;
return ( 1 ) ;
}
static int F_3 ( T_2 * V_6 )
{
if ( V_6 == NULL )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_7 , char * V_8 , int V_9 )
{
int V_10 = 0 ;
if ( V_8 == NULL )
return ( 0 ) ;
if ( V_7 -> V_11 == NULL )
return ( 0 ) ;
V_10 = F_5 ( V_7 -> V_11 , V_8 , V_9 ) ;
F_6 ( V_7 ) ;
F_7 ( V_7 ) ;
return ( V_10 ) ;
}
static int F_8 ( T_2 * V_7 , const char * V_12 , int V_13 )
{
int V_10 = 0 ;
if ( ( V_12 == NULL ) || ( V_13 <= 0 ) )
return ( 0 ) ;
if ( V_7 -> V_11 == NULL )
return ( 0 ) ;
V_10 = F_9 ( V_7 -> V_11 , V_12 , V_13 ) ;
F_6 ( V_7 ) ;
F_7 ( V_7 ) ;
return ( V_10 ) ;
}
static long F_10 ( T_2 * V_7 , int V_14 , long V_15 , void * V_4 )
{
long V_10 ;
if ( V_7 -> V_11 == NULL )
return ( 0 ) ;
switch ( V_14 ) {
case V_16 :
F_6 ( V_7 ) ;
V_10 = F_11 ( V_7 -> V_11 , V_14 , V_15 , V_4 ) ;
F_7 ( V_7 ) ;
break;
case V_17 :
V_10 = 0L ;
break;
default:
V_10 = F_11 ( V_7 -> V_11 , V_14 , V_15 , V_4 ) ;
}
return ( V_10 ) ;
}
static long F_12 ( T_2 * V_7 , int V_14 , T_3 * V_18 )
{
long V_10 = 1 ;
if ( V_7 -> V_11 == NULL )
return ( 0 ) ;
switch ( V_14 ) {
default:
V_10 = F_13 ( V_7 -> V_11 , V_14 , V_18 ) ;
break;
}
return ( V_10 ) ;
}
static int F_14 ( T_2 * V_19 , char * V_20 , int V_21 )
{
if ( V_19 -> V_11 == NULL )
return ( 0 ) ;
return ( F_15 ( V_19 -> V_11 , V_20 , V_21 ) ) ;
}
static int F_16 ( T_2 * V_19 , const char * V_22 )
{
if ( V_19 -> V_11 == NULL )
return ( 0 ) ;
return ( F_17 ( V_19 -> V_11 , V_22 ) ) ;
}
