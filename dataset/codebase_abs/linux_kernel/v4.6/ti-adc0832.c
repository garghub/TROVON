static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_4 , & V_2 -> V_6 , 2 ) ;
if ( V_5 )
return V_5 ;
return ( V_2 -> V_6 [ 0 ] << 2 & 0xff ) | ( V_2 -> V_6 [ 1 ] >> 6 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_7 ,
bool V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 V_10 = {
. V_11 = V_2 -> V_11 ,
. V_6 = V_2 -> V_6 ,
. V_12 = 2 ,
} ;
int V_5 ;
if ( ! V_2 -> V_13 )
return F_1 ( V_2 ) ;
V_2 -> V_11 [ 0 ] = 1 << ( V_2 -> V_13 + 1 ) ;
V_2 -> V_11 [ 0 ] |= V_8 ? 0 : ( 1 << V_2 -> V_13 ) ;
V_2 -> V_11 [ 0 ] |= ( V_7 % 2 ) << ( V_2 -> V_13 - 1 ) ;
if ( V_2 -> V_13 > 1 )
V_2 -> V_11 [ 0 ] |= V_7 / 2 ;
V_2 -> V_11 [ 0 ] <<= 1 ;
V_5 = F_4 ( V_4 , & V_10 , 1 ) ;
if ( V_5 )
return V_5 ;
return V_2 -> V_6 [ 1 ] ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 const * V_7 , int * V_17 ,
int * V_18 , long V_19 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
switch ( V_19 ) {
case V_20 :
F_7 ( & V_2 -> V_21 ) ;
* V_17 = F_3 ( V_2 , V_7 -> V_7 ,
V_7 -> V_8 ) ;
F_8 ( & V_2 -> V_21 ) ;
if ( * V_17 < 0 )
return * V_17 ;
return V_22 ;
case V_23 :
* V_17 = F_9 ( V_2 -> V_24 ) ;
if ( * V_17 < 0 )
return * V_17 ;
* V_17 /= 1000 ;
* V_18 = 8 ;
return V_25 ;
}
return - V_26 ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_14 * V_27 ;
struct V_1 * V_2 ;
int V_5 ;
V_27 = F_11 ( & V_4 -> V_28 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_29 ;
V_2 = F_6 ( V_27 ) ;
V_2 -> V_4 = V_4 ;
F_12 ( & V_2 -> V_21 ) ;
V_27 -> V_30 = F_13 ( V_4 ) -> V_30 ;
V_27 -> V_28 . V_31 = & V_4 -> V_28 ;
V_27 -> V_32 = & V_33 ;
V_27 -> V_34 = V_35 ;
switch ( F_13 ( V_4 ) -> V_36 ) {
case V_37 :
V_2 -> V_13 = 0 ;
V_27 -> V_38 = V_39 ;
V_27 -> V_40 = F_14 ( V_39 ) ;
break;
case V_1 :
V_2 -> V_13 = 1 ;
V_27 -> V_38 = V_41 ;
V_27 -> V_40 = F_14 ( V_41 ) ;
break;
case V_42 :
V_2 -> V_13 = 2 ;
V_27 -> V_38 = V_43 ;
V_27 -> V_40 = F_14 ( V_43 ) ;
break;
case V_44 :
V_2 -> V_13 = 3 ;
V_27 -> V_38 = V_45 ;
V_27 -> V_40 = F_14 ( V_45 ) ;
break;
default:
return - V_26 ;
}
V_2 -> V_24 = F_15 ( & V_4 -> V_28 , L_1 ) ;
if ( F_16 ( V_2 -> V_24 ) )
return F_17 ( V_2 -> V_24 ) ;
V_5 = F_18 ( V_2 -> V_24 ) ;
if ( V_5 )
return V_5 ;
F_19 ( V_4 , V_27 ) ;
V_5 = F_20 ( V_27 ) ;
if ( V_5 )
F_21 ( V_2 -> V_24 ) ;
return V_5 ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_14 * V_27 = F_23 ( V_4 ) ;
struct V_1 * V_2 = F_6 ( V_27 ) ;
F_24 ( V_27 ) ;
F_21 ( V_2 -> V_24 ) ;
return 0 ;
}
