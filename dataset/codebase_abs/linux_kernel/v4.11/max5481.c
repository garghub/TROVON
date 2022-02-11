static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_7 [ 0 ] = V_3 ;
switch ( V_3 ) {
case V_8 :
V_2 -> V_7 [ 1 ] = V_4 >> 2 ;
V_2 -> V_7 [ 2 ] = ( V_4 & 0x3 ) << 6 ;
return F_2 ( V_6 , V_2 -> V_7 , 3 ) ;
case V_9 :
case V_10 :
return F_2 ( V_6 , V_2 -> V_7 , 1 ) ;
default:
return - V_11 ;
}
}
static int F_3 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_4 , int * V_16 , long V_17 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_17 != V_18 )
return - V_19 ;
* V_4 = 1000 * V_2 -> V_20 -> V_21 ;
* V_16 = V_22 ;
return V_23 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int V_4 , int V_16 , long V_17 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
if ( V_17 != V_24 )
return - V_19 ;
if ( V_4 < 0 || V_4 > V_22 )
return - V_19 ;
return F_1 ( V_2 , V_8 , V_4 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
const struct V_25 * V_26 = F_7 ( V_6 ) ;
const struct V_27 * V_28 ;
int V_29 ;
V_13 = F_8 ( & V_6 -> V_30 , sizeof( * V_2 ) ) ;
if ( ! V_13 )
return - V_31 ;
F_9 ( & V_6 -> V_30 , V_13 ) ;
V_2 = F_4 ( V_13 ) ;
V_2 -> V_6 = V_6 ;
V_28 = F_10 ( F_11 ( V_32 ) , & V_6 -> V_30 ) ;
if ( V_28 )
V_2 -> V_20 = F_12 ( & V_6 -> V_30 ) ;
else
V_2 -> V_20 = & V_33 [ V_26 -> V_34 ] ;
V_13 -> V_35 = V_26 -> V_35 ;
V_13 -> V_30 . V_36 = & V_6 -> V_30 ;
V_13 -> V_37 = V_38 ;
V_13 -> V_39 = & V_40 ;
V_13 -> V_41 = V_42 ;
V_13 -> V_43 = F_13 ( V_42 ) ;
V_29 = F_1 ( V_2 , V_10 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_14 ( V_13 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_16 ( & V_6 -> V_30 ) ;
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_17 ( V_13 ) ;
return F_1 ( V_2 , V_9 , 0 ) ;
}
