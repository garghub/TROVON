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
int V_13 ;
V_13 = F_6 ( V_1 , V_14 ,
V_15 ) ;
if ( V_13 )
return V_13 ;
F_8 ( 6000 , 10000 ) ;
V_13 = F_9 ( V_1 , V_16 , V_12 , 2 ) ;
if ( V_13 == 0 )
V_13 = ( V_12 [ 0 ] << 4 ) + ( ( V_12 [ 1 ] >> 4 ) & 0x0f ) ;
F_6 ( V_1 , V_14 , V_17 ) ;
return V_13 ;
}
static T_3 F_10 ( T_4 V_18 ,
T_5 V_19 , T_4 V_20 , T_1 * V_4 ,
void * V_21 , void * V_22 )
{
return V_23 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 . V_27 ;
struct V_29 * V_30 = F_12 ( V_27 ) ;
T_3 V_31 ;
int V_32 ;
V_31 = F_13 ( F_14 ( V_27 ) ,
V_33 , F_10 ,
NULL , NULL ) ;
if ( F_15 ( V_31 ) )
return - V_34 ;
V_32 = F_16 ( & V_25 -> V_28 ,
F_14 ( V_27 ) , V_30 -> V_1 ,
& V_35 ) ;
if ( V_32 )
F_17 ( F_14 ( V_27 ) ,
V_33 ,
F_10 ) ;
return V_32 ;
}
static int T_6 F_18 ( void )
{
return F_19 ( & V_36 ) ;
}
