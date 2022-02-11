static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_1 V_10 ;
T_1 V_11 ;
int V_12 = 1 << ( 4 * V_5 -> V_13 ) ;
int V_14 = V_5 -> V_13 ;
T_2 V_15 [ 2 ] ;
F_3 ( V_7 , 0x40 , & V_10 ) ;
if ( ( V_10 & V_12 ) == 0 )
return - V_16 ;
if ( V_10 & ( 1 << 23 ) ) {
V_15 [ 0 ] = V_17 ;
V_15 [ 1 ] = V_18 ;
} else {
V_15 [ 0 ] = V_17 ;
V_15 [ 1 ] = V_17 ;
}
F_3 ( V_7 , 0x80 , & V_11 ) ;
if ( V_11 & ( 1 << 24 ) )
V_15 [ 0 ] = V_19 ;
if ( V_10 & ( 1 << 22 ) )
V_14 = V_14 ^ 1 ;
switch ( V_15 [ V_14 ] ) {
case V_18 :
if ( ( V_10 & ( 1 << 5 ) ) == 0 )
return - V_16 ;
if ( V_10 & ( 1 << 3 ) )
V_5 -> V_20 = V_21 ;
else
V_5 -> V_20 = V_22 ;
break;
case V_19 :
if ( ( V_11 & ( 1 << 21 ) ) == 0 )
return - V_16 ;
if ( V_11 & ( 1 << 19 ) )
V_5 -> V_20 = V_21 ;
else
V_5 -> V_20 = V_22 ;
break;
case V_17 :
V_5 -> V_20 = V_23 ;
break;
}
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , const struct V_24 * V_25 )
{
static const struct V_26 V_27 = {
. V_28 = V_29 ,
. V_30 = V_31 ,
. V_32 = V_33 ,
. V_34 = V_35 ,
. V_36 = & V_37 ,
} ;
const struct V_26 * V_38 [] = { & V_27 , NULL } ;
if ( V_7 -> V_39 == V_40 &&
( V_7 -> V_41 == V_42 ||
V_7 -> V_41 == V_43 ) )
F_6 ( & V_7 -> V_9 ) ;
return F_7 ( V_7 , V_38 , & V_44 , NULL , 0 ) ;
}
