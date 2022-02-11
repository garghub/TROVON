static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_4 ;
unsigned V_5 [ 5 ] , V_6 ;
switch ( ( unsigned long ) V_3 ) {
case 1 :
F_2 ( V_2 , L_1 ) ;
return 0 ;
case 2 :
F_2 ( V_2 , L_2 ) ;
return 0 ;
default:
V_4 = ( unsigned long ) V_3 - 3 ;
V_5 [ 0 ] = F_3 ( & V_7 [ V_4 ] ) ;
V_5 [ 1 ] = F_3 ( & V_8 [ V_4 ] ) ;
V_5 [ 2 ] = F_3 ( & V_9 [ V_4 ] ) ;
V_5 [ 3 ] = F_3 ( & V_10 [ V_4 ] ) ;
V_5 [ 4 ] = F_3 ( & V_11 [ V_4 ] ) ;
if ( ! ( V_5 [ 0 ] | V_5 [ 1 ] | V_5 [ 2 ] | V_5 [ 3 ] | V_5 [ 4 ] ) )
return 0 ;
V_6 = ( V_4 * 1000 ) / V_12 ;
F_4 ( V_2 , L_3 ,
V_4 , V_6 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_5 [ 4 ] ) ;
return 0 ;
}
}
static void * F_5 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ( unsigned long long ) * V_13 >= V_12 + 2 )
return NULL ;
if ( * V_13 == 0 )
* V_13 = 1 ;
return ( void * ) ( unsigned long ) * V_13 ;
}
static void * F_6 ( struct V_1 * V_2 , void * V_3 , T_1 * V_14 )
{
( * V_14 ) ++ ;
return ( unsigned long long ) * V_14 > V_12 + 2 ?
NULL : ( void * ) ( unsigned long ) * V_14 ;
}
static void F_7 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_8 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_9 ( V_16 , & V_17 ) ;
}
