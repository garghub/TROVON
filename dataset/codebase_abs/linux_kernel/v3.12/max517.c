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
unsigned int V_17 ;
switch ( V_16 ) {
case V_18 :
V_17 = ( V_6 -> V_19 [ V_14 -> V_4 ] * 1000 ) >> 8 ;
* V_3 = V_17 / 1000000 ;
* V_15 = V_17 % 1000000 ;
return V_20 ;
default:
break;
}
return - V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 const * V_14 , int V_3 , int V_15 , long V_21 )
{
int V_22 ;
switch ( V_21 ) {
case V_23 :
V_22 = F_1 ( V_2 , V_3 , V_14 -> V_4 ) ;
break;
default:
V_22 = - V_11 ;
break;
}
return V_22 ;
}
static int F_6 ( struct V_24 * V_25 )
{
T_1 V_9 = V_26 ;
return F_3 ( F_7 ( V_25 ) , & V_9 , 1 ) ;
}
static int F_8 ( struct V_24 * V_25 )
{
T_1 V_9 = 0 ;
return F_3 ( F_7 ( V_25 ) , & V_9 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
const struct V_27 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_29 * V_30 = V_8 -> V_25 . V_30 ;
int V_31 ;
V_2 = F_10 ( & V_8 -> V_25 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_6 = F_2 ( V_2 ) ;
F_11 ( V_8 , V_2 ) ;
V_6 -> V_8 = V_8 ;
V_2 -> V_25 . V_33 = & V_8 -> V_25 ;
if ( V_28 -> V_34 == V_35 )
V_2 -> V_36 = 1 ;
else
V_2 -> V_36 = 2 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = & V_42 ;
if ( V_28 -> V_34 == V_43 || ! V_30 ) {
V_6 -> V_19 [ 0 ] = V_6 -> V_19 [ 1 ] = 5000 ;
} else {
V_6 -> V_19 [ 0 ] = V_30 -> V_19 [ 0 ] ;
V_6 -> V_19 [ 1 ] = V_30 -> V_19 [ 1 ] ;
}
V_31 = F_12 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_13 ( & V_8 -> V_25 , L_1 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 )
{
F_15 ( F_16 ( V_8 ) ) ;
return 0 ;
}
