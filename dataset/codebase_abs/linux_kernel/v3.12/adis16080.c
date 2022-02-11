static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
struct V_10 V_11 [] = {
{
. V_12 = & V_6 -> V_13 ,
. V_14 = 2 ,
. V_15 = 1 ,
} , {
. V_16 = & V_6 -> V_13 ,
. V_14 = 2 ,
} ,
} ;
V_6 -> V_13 = F_3 ( V_3 | V_17 ) ;
F_4 ( & V_8 ) ;
F_5 ( & V_11 [ 0 ] , & V_8 ) ;
F_5 ( & V_11 [ 1 ] , & V_8 ) ;
V_9 = F_6 ( V_6 -> V_18 , & V_8 ) ;
if ( V_9 == 0 )
* V_4 = F_7 ( F_8 ( V_6 -> V_13 ) , 11 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_19 const * V_20 ,
int * V_4 ,
int * V_21 ,
long V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
switch ( V_22 ) {
case V_23 :
F_10 ( & V_2 -> V_24 ) ;
V_9 = F_1 ( V_2 , V_20 -> V_25 , V_4 ) ;
F_11 ( & V_2 -> V_24 ) ;
return V_9 ? V_9 : V_26 ;
case V_27 :
switch ( V_20 -> type ) {
case V_28 :
* V_4 = V_6 -> V_29 -> V_30 ;
* V_21 = V_6 -> V_29 -> V_31 ;
return V_32 ;
case V_33 :
* V_4 = 5000 ;
* V_21 = 12 ;
return V_34 ;
case V_35 :
* V_4 = 85000 - 25000 ;
* V_21 = 585 ;
return V_32 ;
default:
return - V_36 ;
}
case V_37 :
switch ( V_20 -> type ) {
case V_33 :
* V_4 = 2048 ;
return V_26 ;
case V_35 :
* V_4 = F_12 ( 25 * 585 , 85 - 25 ) ;
return V_26 ;
default:
return - V_36 ;
}
default:
break;
}
return - V_36 ;
}
static int F_13 ( struct V_38 * V_39 )
{
const struct V_40 * V_41 = F_14 ( V_39 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_15 ( & V_39 -> V_42 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_43 ;
V_6 = F_2 ( V_2 ) ;
F_16 ( V_39 , V_2 ) ;
V_6 -> V_18 = V_39 ;
V_6 -> V_29 = & V_44 [ V_41 -> V_45 ] ;
V_2 -> V_46 = V_39 -> V_42 . V_47 -> V_46 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = F_17 ( V_49 ) ;
V_2 -> V_42 . V_51 = & V_39 -> V_42 ;
V_2 -> V_29 = & V_52 ;
V_2 -> V_53 = V_54 ;
return F_18 ( V_2 ) ;
}
static int F_19 ( struct V_38 * V_39 )
{
F_20 ( F_21 ( V_39 ) ) ;
return 0 ;
}
