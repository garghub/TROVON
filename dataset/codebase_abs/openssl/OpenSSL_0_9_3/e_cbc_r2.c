T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
T_1 * F_3 ( void )
{
return ( & V_3 ) ;
}
static void F_4 ( T_2 * V_4 , unsigned char * V_5 ,
unsigned char * V_6 , int V_7 )
{
if ( V_6 != NULL )
memcpy ( & ( V_4 -> V_8 [ 0 ] ) , V_6 , 8 ) ;
memcpy ( & ( V_4 -> V_6 [ 0 ] ) , & ( V_4 -> V_8 [ 0 ] ) , 8 ) ;
if ( V_5 != NULL )
F_5 ( & ( V_4 -> V_9 . V_10 ) , F_6 ( V_4 ) ,
V_5 , F_6 ( V_4 ) * 8 ) ;
}
static void F_7 ( T_2 * V_4 , unsigned char * V_11 ,
unsigned char * V_12 , unsigned int V_13 )
{
F_8 (
V_12 , V_11 , ( long ) V_13 ,
& ( V_4 -> V_9 . V_10 ) , & ( V_4 -> V_6 [ 0 ] ) ,
V_4 -> V_14 ) ;
}
static int F_9 ( const T_1 * V_15 )
{
int V_16 ;
V_16 = F_10 ( V_15 ) ;
if ( V_16 == 16 ) return ( V_17 ) ;
else if ( V_16 == 8 ) return ( V_18 ) ;
else if ( V_16 == 5 ) return ( V_19 ) ;
else return ( 0 ) ;
}
static T_1 * F_11 ( int V_16 )
{
if ( V_16 == V_17 ) return ( F_1 () ) ;
else if ( V_16 == V_18 ) return ( F_2 () ) ;
else if ( V_16 == V_19 ) return ( F_3 () ) ;
else
{
F_12 ( V_20 , V_21 ) ;
return ( NULL ) ;
}
}
static int F_13 ( T_2 * V_9 , T_3 * type )
{
long V_22 = 0 ;
int V_16 = 0 , V_23 ;
T_1 * V_15 ;
if ( type != NULL )
{
V_23 = F_14 ( V_9 ) ;
V_16 = F_15 ( type , & V_22 , V_9 -> V_8 , V_23 ) ;
if ( V_16 != V_23 )
return ( - 1 ) ;
else if ( V_16 > 0 )
memcpy ( V_9 -> V_6 , V_9 -> V_8 , V_23 ) ;
V_15 = F_11 ( ( int ) V_22 ) ;
if ( V_15 == NULL )
return ( - 1 ) ;
if ( V_15 != F_16 ( V_9 ) )
{
F_16 ( V_9 ) = V_15 ;
F_4 ( V_9 , NULL , NULL , 1 ) ;
}
}
return ( V_16 ) ;
}
static int F_17 ( T_2 * V_9 , T_3 * type )
{
long V_22 ;
int V_16 = 0 , V_24 ;
if ( type != NULL )
{
V_22 = F_9 ( F_16 ( V_9 ) ) ;
V_24 = F_14 ( V_9 ) ;
V_16 = F_18 ( type , V_22 , V_9 -> V_8 , V_24 ) ;
}
return ( V_16 ) ;
}
