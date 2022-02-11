static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( F_3 ( V_3 , & V_5 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_5 ( V_3 , & V_5 -> V_6 ) ;
}
static int F_6 ( struct V_4 * V_4 , T_1 V_3 ,
T_1 V_8 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_5 -> V_11 ;
return F_7 ( V_5 , V_10 [ V_3 ] . V_12 , V_10 [ V_3 ] . V_13 ,
V_8 << V_10 [ V_3 ] . V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_15 |= F_9 ( V_3 ) ;
return F_6 ( V_4 , V_3 , V_16 ) ;
}
static int F_10 ( struct V_4 * V_4 ,
struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_17 , V_18 ;
int V_19 ;
switch ( V_3 ) {
case V_20 ... V_21 :
V_17 = V_22 ;
break;
case V_23 ... V_24 :
V_17 = V_25 ;
V_3 = V_3 - 8 ;
break;
default:
return - V_26 ;
}
V_19 = F_11 ( V_4 -> V_5 , V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return ! ! ( V_18 & F_9 ( V_3 ) ) ;
}
static int F_12 ( struct V_4 * V_4 ,
struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
const struct V_9 * V_10 = V_5 -> V_11 ;
T_1 V_18 ;
int V_19 ;
V_19 = F_11 ( V_5 , V_10 [ V_3 ] . V_12 , & V_18 ) ;
if ( V_19 )
return V_19 ;
V_18 = ( V_18 & V_10 [ V_3 ] . V_13 ) >> V_10 [ V_3 ] . V_14 ;
if ( V_18 == V_27 )
return 1 ;
else if ( V_18 == V_28 )
return 0 ;
else
return - V_26 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_15 & F_9 ( V_3 ) )
return F_10 ( V_4 , V_2 , V_3 ) ;
else
return F_12 ( V_4 , V_2 , V_3 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_3 , int V_29 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_30 ;
if ( V_29 )
V_30 = V_27 ;
else
V_30 = V_28 ;
F_6 ( V_4 , V_3 , V_30 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 ,
int V_29 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_14 ( V_2 , V_3 , V_29 ) ;
V_4 -> V_15 &= ~ F_9 ( V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 )
{
struct V_5 * V_5 = F_17 ( V_32 -> V_33 . V_34 ) ;
struct V_4 * V_4 ;
V_4 = F_18 ( & V_32 -> V_33 , sizeof( * V_4 ) ,
V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_37 ;
V_4 -> V_2 . V_34 = & V_32 -> V_33 ;
F_19 ( V_32 , V_4 ) ;
return F_20 ( & V_32 -> V_33 , & V_4 -> V_2 ,
V_4 ) ;
}
