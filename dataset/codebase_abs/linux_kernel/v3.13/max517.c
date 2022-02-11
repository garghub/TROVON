static int F_1 ( struct V_1 * V_2 ,
long V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
if ( V_3 < 0 || V_3 > 255 )
return - V_11 ;
V_9 [ 0 ] = V_4 ;
V_9 [ 1 ] = V_3 ;
V_10 = F_3 ( V_8 , V_9 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 != 2 )
return - V_12 ;
else
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 const * V_14 ,
int * V_3 ,
int * V_15 ,
long V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_16 ) {
case V_17 :
* V_3 = V_6 -> V_18 [ V_14 -> V_4 ] ;
* V_15 = 8 ;
return V_19 ;
default:
break;
}
return - V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 const * V_14 , int V_3 , int V_15 , long V_20 )
{
int V_21 ;
switch ( V_20 ) {
case V_22 :
V_21 = F_1 ( V_2 , V_3 , V_14 -> V_4 ) ;
break;
default:
V_21 = - V_11 ;
break;
}
return V_21 ;
}
static int F_6 ( struct V_23 * V_24 )
{
T_1 V_9 = V_25 ;
return F_3 ( F_7 ( V_24 ) , & V_9 , 1 ) ;
}
static int F_8 ( struct V_23 * V_24 )
{
T_1 V_9 = 0 ;
return F_3 ( F_7 ( V_24 ) , & V_9 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
const struct V_26 * V_27 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_28 * V_29 = V_8 -> V_24 . V_29 ;
V_2 = F_10 ( & V_8 -> V_24 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_30 ;
V_6 = F_2 ( V_2 ) ;
F_11 ( V_8 , V_2 ) ;
V_6 -> V_8 = V_8 ;
V_2 -> V_24 . V_31 = & V_8 -> V_24 ;
if ( V_27 -> V_32 == V_33 )
V_2 -> V_34 = 1 ;
else
V_2 -> V_34 = 2 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = & V_40 ;
if ( V_27 -> V_32 == V_41 || ! V_29 ) {
V_6 -> V_18 [ 0 ] = V_6 -> V_18 [ 1 ] = 5000 ;
} else {
V_6 -> V_18 [ 0 ] = V_29 -> V_18 [ 0 ] ;
V_6 -> V_18 [ 1 ] = V_29 -> V_18 [ 1 ] ;
}
return F_12 ( V_2 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
F_14 ( F_15 ( V_8 ) ) ;
return 0 ;
}
