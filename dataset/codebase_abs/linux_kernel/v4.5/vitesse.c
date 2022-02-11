static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 &= ~ ( V_6 |
V_7 ) ;
V_4 |= ( V_8 |
V_9 ) ;
V_3 = F_3 ( V_2 , V_5 , V_4 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_10 ,
V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_12 == V_13 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_14 == V_15 )
V_3 = F_2 ( V_2 , V_16 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_14 == V_15 )
V_3 = F_3 ( V_2 , V_17 ,
( V_2 -> V_18 -> V_19 == V_20 ||
V_2 -> V_18 -> V_19 == V_21 ||
V_2 -> V_18 -> V_19 == V_22 ||
V_2 -> V_18 -> V_19 == V_23 ||
V_2 -> V_18 -> V_19 == V_24 ) ?
V_25 :
V_26 ) ;
else {
V_3 = F_2 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 , V_17 , 0 ) ;
}
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_10 ,
V_27 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_29 == V_30 || V_2 -> V_31 > V_32 )
return 0 ;
V_28 = F_3 ( V_2 , V_33 , 0x52b5 ) ;
if ( V_28 >= 0 )
V_28 = F_3 ( V_2 , V_34 , 0x0012 ) ;
if ( V_28 >= 0 )
V_28 = F_3 ( V_2 , V_35 , 0x2803 ) ;
if ( V_28 >= 0 )
V_28 = F_3 ( V_2 , V_36 , 0x87fa ) ;
if ( V_28 >= 0 )
V_28 = F_3 ( V_2 , V_33 , 0x0000 ) ;
else
F_3 ( V_2 , V_33 , 0x0000 ) ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_29 != V_30 && V_2 -> V_31 <= V_32 ) {
V_28 = F_10 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_8 ( V_2 ) ;
}
return F_11 ( V_2 ) ;
}
