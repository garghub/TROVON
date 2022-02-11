static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 == V_5 ) {
V_3 = F_2 ( V_2 , V_6 , 0x7FFF ) ;
V_3 = F_3 ( V_2 , V_7 ) ;
V_3 = F_2 ( V_2 , V_6 ,
V_8 |
V_9 ) ;
} else {
V_3 = F_2 ( V_2 , V_6 , 0 ) ;
}
return V_3 < 0 ? V_3 : 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = F_3 ( V_2 , V_7 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_11 -> V_12 )
F_6 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
struct V_10 * V_11 ;
V_11 = F_8 ( V_14 , sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_11 -> V_12 = 0 ;
V_11 -> V_18 = F_9 ( V_2 , V_19 , 3 ) ;
V_11 -> V_20 = F_9 ( V_2 , V_21 ,
3 ) ;
V_2 -> V_11 = V_11 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_11 )
F_11 ( V_14 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
V_11 -> V_12 = V_23 -> V_12 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_24 ;
int V_25 ;
switch ( V_2 -> V_26 ) {
case V_27 :
V_25 = V_28 ;
break;
case V_29 :
V_25 = V_30 ;
break;
case V_31 :
V_25 = V_32 ;
break;
default:
return;
}
F_2 ( V_2 , V_33 , V_34 ) ;
V_24 = F_3 ( V_2 , V_35 ) ;
V_24 &= ~ V_36 ;
V_24 |= V_25 ;
F_2 ( V_2 , V_35 , V_24 ) ;
F_2 ( V_2 , V_33 , V_37 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
return F_15 ( V_2 ) ;
}
