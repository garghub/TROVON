static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 = {
. V_10 = V_7 -> V_11 ,
. V_12 = V_7 -> V_11 ,
. V_13 = 4 ,
} ;
F_3 ( & V_7 -> V_14 ) ;
V_7 -> V_11 [ 0 ] = V_15 | V_3 ;
V_7 -> V_11 [ 1 ] = V_7 -> V_11 [ 2 ] = V_7 -> V_11 [ 3 ] = 0 ;
V_5 = F_4 ( V_7 -> V_16 , & V_9 , 1 ) ;
if ( V_5 == 0 )
* V_4 = ( V_7 -> V_11 [ 1 ] << 16 ) | ( V_7 -> V_11 [ 2 ] << 8 ) | V_7 -> V_11 [ 3 ] ;
F_5 ( & V_7 -> V_14 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 const * V_18 ,
int * V_4 , int * V_19 ,
long V_20 )
{
int V_5 ;
T_2 V_21 ;
switch ( V_20 ) {
case V_22 :
F_3 ( & V_2 -> V_23 ) ;
V_5 = F_1 ( V_2 , V_18 -> V_24 , & V_21 ) ;
F_5 ( & V_2 -> V_23 ) ;
if ( V_5 )
return V_5 ;
* V_4 = V_21 ;
return V_25 ;
case V_26 :
switch ( V_18 -> type ) {
case V_27 :
* V_4 = 250 ;
* V_19 = 336440817 ;
return V_28 ;
case V_29 :
* V_4 = 105000 ;
* V_19 = 9516048 - 8036283 ;
return V_28 ;
default:
return - V_30 ;
}
case V_31 :
switch ( V_18 -> type ) {
case V_27 :
* V_4 = - 8388608 ;
return V_25 ;
case V_29 :
* V_4 = - 8036283 ;
return V_25 ;
default:
return - V_30 ;
}
}
return - V_30 ;
}
static int F_7 ( struct V_32 * V_33 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_8 ( & V_33 -> V_34 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_35 ;
V_7 = F_2 ( V_2 ) ;
F_9 ( V_33 , V_2 ) ;
V_7 -> V_16 = V_33 ;
F_10 ( & V_7 -> V_14 ) ;
V_2 -> V_36 = V_33 -> V_34 . V_37 -> V_36 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = F_11 ( V_39 ) ;
V_2 -> V_34 . V_41 = & V_33 -> V_34 ;
V_2 -> V_42 = & V_43 ;
V_2 -> V_44 = V_45 ;
return F_12 ( & V_33 -> V_34 , V_2 ) ;
}
