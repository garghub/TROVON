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
int V_14 ;
V_14 = F_2 ( V_2 , V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 |= V_16 ;
return F_3 ( V_2 , V_15 , V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
if ( V_2 -> V_12 == V_13 )
V_14 = F_5 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_17 == V_18 )
V_3 = F_2 ( V_2 , V_19 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_17 == V_18 )
V_3 = F_3 ( V_2 , V_20 ,
( V_2 -> V_21 -> V_22 == V_23 ||
V_2 -> V_21 -> V_22 == V_24 ||
V_2 -> V_21 -> V_22 == V_25 ||
V_2 -> V_21 -> V_22 == V_26 ||
V_2 -> V_21 -> V_22 == V_27 ||
V_2 -> V_21 -> V_22 == V_28 ) ?
V_29 :
V_30 ) ;
else {
V_3 = F_2 ( V_2 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 , V_20 , 0 ) ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_10 ,
V_31 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_32 == V_33 || V_2 -> V_34 > V_35 )
return 0 ;
V_14 = F_3 ( V_2 , V_36 , 0x52b5 ) ;
if ( V_14 >= 0 )
V_14 = F_3 ( V_2 , V_37 , 0x0012 ) ;
if ( V_14 >= 0 )
V_14 = F_3 ( V_2 , V_38 , 0x2803 ) ;
if ( V_14 >= 0 )
V_14 = F_3 ( V_2 , V_39 , 0x87fa ) ;
if ( V_14 >= 0 )
V_14 = F_3 ( V_2 , V_36 , 0x0000 ) ;
else
F_3 ( V_2 , V_36 , 0x0000 ) ;
return V_14 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_32 != V_33 && V_2 -> V_34 <= V_35 ) {
V_14 = F_13 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_11 ( V_2 ) ;
}
return F_14 ( V_2 ) ;
}
