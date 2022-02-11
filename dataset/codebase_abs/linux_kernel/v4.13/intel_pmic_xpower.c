static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
if ( V_2 == V_7 )
* V_4 = ( ( V_5 & V_8 ) == V_9 ) ;
else
* V_4 = ( V_5 & F_3 ( V_3 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 ,
int V_3 , bool V_10 )
{
int V_5 ;
if ( V_2 == V_7 )
return F_5 ( V_1 , V_2 , V_8 ,
V_10 ? V_9 : V_11 ) ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
if ( V_10 )
V_5 |= F_3 ( V_3 ) ;
else
V_5 &= ~ F_3 ( V_3 ) ;
if ( F_6 ( V_1 , V_2 , V_5 ) )
return - V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , int V_2 )
{
T_2 V_12 [ 2 ] ;
if ( F_8 ( V_1 , V_13 , V_12 , 2 ) )
return - V_6 ;
return ( V_12 [ 0 ] << 4 ) + ( ( V_12 [ 1 ] >> 4 ) & 0x0F ) ;
}
static T_3 F_9 ( T_4 V_14 ,
T_5 V_15 , T_4 V_16 , T_1 * V_4 ,
void * V_17 , void * V_18 )
{
return V_19 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 . V_23 ;
struct V_25 * V_26 = F_11 ( V_23 ) ;
T_3 V_27 ;
int V_28 ;
V_27 = F_12 ( F_13 ( V_23 ) ,
V_29 , F_9 ,
NULL , NULL ) ;
if ( F_14 ( V_27 ) )
return - V_30 ;
V_28 = F_15 ( & V_21 -> V_24 ,
F_13 ( V_23 ) , V_26 -> V_1 ,
& V_31 ) ;
if ( V_28 )
F_16 ( F_13 ( V_23 ) ,
V_29 ,
F_9 ) ;
return V_28 ;
}
static int T_6 F_17 ( void )
{
return F_18 ( & V_32 ) ;
}
