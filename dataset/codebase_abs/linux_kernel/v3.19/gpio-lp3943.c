static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
if ( F_4 ( V_5 , & V_6 -> V_7 ) )
return - V_8 ;
return 0 ;
}
static void F_5 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
F_6 ( V_5 , & V_6 -> V_7 ) ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_5 ,
T_1 V_9 )
{
struct V_6 * V_6 = V_1 -> V_6 ;
const struct V_10 * V_11 = V_6 -> V_12 ;
return F_8 ( V_6 , V_11 [ V_5 ] . V_13 , V_11 [ V_5 ] . V_14 ,
V_9 << V_11 [ V_5 ] . V_15 ) ;
}
static int F_9 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_1 -> V_16 |= F_10 ( V_5 ) ;
return F_7 ( V_1 , V_5 , V_17 ) ;
}
static int F_11 ( struct V_1 * V_1 ,
struct V_2 * V_4 , unsigned V_5 )
{
T_1 V_18 , V_19 ;
int V_20 ;
switch ( V_5 ) {
case V_21 ... V_22 :
V_18 = V_23 ;
break;
case V_24 ... V_25 :
V_18 = V_26 ;
V_5 = V_5 - 8 ;
break;
default:
return - V_27 ;
}
V_20 = F_12 ( V_1 -> V_6 , V_18 , & V_19 ) ;
if ( V_20 )
return V_20 ;
return ! ! ( V_19 & F_10 ( V_5 ) ) ;
}
static int F_13 ( struct V_1 * V_1 ,
struct V_2 * V_4 , unsigned V_5 )
{
struct V_6 * V_6 = V_1 -> V_6 ;
const struct V_10 * V_11 = V_6 -> V_12 ;
T_1 V_19 ;
int V_20 ;
V_20 = F_12 ( V_6 , V_11 [ V_5 ] . V_13 , & V_19 ) ;
if ( V_20 )
return V_20 ;
V_19 = ( V_19 & V_11 [ V_5 ] . V_14 ) >> V_11 [ V_5 ] . V_15 ;
if ( V_19 == V_28 )
return 1 ;
else if ( V_19 == V_29 )
return 0 ;
else
return - V_27 ;
}
static int F_14 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_1 -> V_16 & F_10 ( V_5 ) )
return F_11 ( V_1 , V_4 , V_5 ) ;
else
return F_13 ( V_1 , V_4 , V_5 ) ;
}
static void F_15 ( struct V_2 * V_4 , unsigned V_5 , int V_30 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_1 V_31 ;
if ( V_30 )
V_31 = V_28 ;
else
V_31 = V_29 ;
F_7 ( V_1 , V_5 , V_31 ) ;
}
static int F_16 ( struct V_2 * V_4 , unsigned V_5 ,
int V_30 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_15 ( V_4 , V_5 , V_30 ) ;
V_1 -> V_16 &= ~ F_10 ( V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 )
{
struct V_6 * V_6 = F_18 ( V_33 -> V_34 . V_35 ) ;
struct V_1 * V_1 ;
V_1 = F_19 ( & V_33 -> V_34 , sizeof( * V_1 ) ,
V_36 ) ;
if ( ! V_1 )
return - V_37 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_4 = V_38 ;
V_1 -> V_4 . V_34 = & V_33 -> V_34 ;
F_20 ( V_33 , V_1 ) ;
return F_21 ( & V_1 -> V_4 ) ;
}
static int F_22 ( struct V_32 * V_33 )
{
struct V_1 * V_1 = F_23 ( V_33 ) ;
F_24 ( & V_1 -> V_4 ) ;
return 0 ;
}
