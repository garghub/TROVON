static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
* V_4 = ( V_5 & F_3 ( V_3 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 ,
int V_3 , bool V_7 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
if ( V_7 )
V_5 |= F_3 ( V_3 ) ;
else
V_5 &= ~ F_3 ( V_3 ) ;
if ( F_5 ( V_1 , V_2 , V_5 ) )
return - V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_8 [ 2 ] ;
if ( F_7 ( V_1 , V_9 , V_8 , 2 ) )
return - V_6 ;
return ( V_8 [ 0 ] << 4 ) + ( ( V_8 [ 1 ] >> 4 ) & 0x0F ) ;
}
static T_3 F_8 ( T_4 V_10 ,
T_5 V_11 , T_4 V_12 , T_1 * V_4 ,
void * V_13 , void * V_14 )
{
return V_15 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_19 ;
struct V_21 * V_22 = F_10 ( V_19 ) ;
T_3 V_23 ;
int V_24 ;
V_23 = F_11 ( F_12 ( V_19 ) ,
V_25 , F_8 ,
NULL , NULL ) ;
if ( F_13 ( V_23 ) )
return - V_26 ;
V_24 = F_14 ( & V_17 -> V_20 ,
F_12 ( V_19 ) , V_22 -> V_1 ,
& V_27 ) ;
if ( V_24 )
F_15 ( F_12 ( V_19 ) ,
V_25 ,
F_8 ) ;
return V_24 ;
}
static int T_6 F_16 ( void )
{
return F_17 ( & V_28 ) ;
}
