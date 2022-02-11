static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
* V_4 = ( V_5 & V_3 ) ? 1 : 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 ,
int V_3 , bool V_7 )
{
T_2 V_8 , V_9 = V_3 ;
if ( V_7 )
V_8 = 0xFF ;
else
V_8 = 0x0 ;
return F_4 ( V_1 , V_2 , V_9 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_1 , int V_2 )
{
unsigned int V_8 , V_10 , V_11 ;
T_2 V_12 , V_13 , V_14 ;
unsigned long V_15 ;
static const unsigned long V_16 [] = {
0 , 260420 , 130210 , 65100 , 32550 , 16280 ,
8140 , 4070 , 2030 , 0 , 260420 , 130210 } ;
if ( F_2 ( V_1 , V_2 , & V_8 ) )
return - V_6 ;
V_12 = ( T_2 ) V_8 ;
if ( F_2 ( V_1 , ( V_2 - 1 ) , & V_8 ) )
return - V_6 ;
V_13 = ( T_2 ) V_8 ;
V_11 = V_12 | F_6 ( V_13 ) ;
V_14 = F_7 ( V_13 ) ;
V_15 = V_16 [ V_14 ] ;
V_10 = V_11 * V_15 / 1000 ;
return V_10 ;
}
static int
F_8 ( struct V_1 * V_1 , int V_2 , int V_17 )
{
T_3 V_18 ;
T_4 V_19 , V_20 = 0 , V_21 = 0 ;
T_2 V_22 , V_23 , V_24 = 0 ;
V_18 = V_17 ;
V_18 /= ( 1 << 5 ) ;
V_20 = F_9 ( V_18 ) - 1 ;
V_24 = F_10 ( V_25 , ( V_20 - 7 ) , 0 , 7 ) ;
V_21 = V_17 / ( 1 << ( 4 + V_24 ) ) ;
V_19 = ( V_24 << 9 ) | V_21 ;
V_22 = ( V_19 >> 8 ) & V_26 ;
if ( F_4 ( V_1 ,
V_2 - 1 ,
V_26 ,
V_22 ) )
return - V_6 ;
V_23 = ( T_2 ) V_19 ;
return F_11 ( V_1 , V_2 , V_23 ) ;
}
static int
F_12 ( struct V_1 * V_1 , int V_2 , int V_3 , T_1 * V_4 )
{
T_2 V_9 = F_13 ( V_3 ) ;
unsigned int V_8 ;
if ( F_2 ( V_1 , V_2 , & V_8 ) )
return - V_6 ;
* V_4 = ( V_8 & V_9 ) >> V_3 ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_1 ,
int V_2 , int V_3 , int V_27 )
{
T_2 V_9 = F_13 ( V_3 ) , V_8 = V_27 << V_3 ;
return F_4 ( V_1 , V_2 , V_9 , V_8 ) ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_16 ( V_29 -> V_32 . V_33 ) ;
return F_17 ( & V_29 -> V_32 ,
F_18 ( V_29 -> V_32 . V_33 ) ,
V_31 -> V_1 ,
& V_34 ) ;
}
static int T_5 F_19 ( void )
{
return F_20 ( & V_35 ) ;
}
