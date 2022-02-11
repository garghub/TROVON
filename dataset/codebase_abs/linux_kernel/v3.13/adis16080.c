static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
struct V_8 V_9 [] = {
{
. V_10 = & V_6 -> V_11 ,
. V_12 = 2 ,
. V_13 = 1 ,
} , {
. V_14 = & V_6 -> V_11 ,
. V_12 = 2 ,
} ,
} ;
V_6 -> V_11 = F_3 ( V_3 | V_15 ) ;
V_7 = F_4 ( V_6 -> V_16 , V_9 , F_5 ( V_9 ) ) ;
if ( V_7 == 0 )
* V_4 = F_6 ( F_7 ( V_6 -> V_11 ) , 11 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 const * V_18 ,
int * V_4 ,
int * V_19 ,
long V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_20 ) {
case V_21 :
F_9 ( & V_2 -> V_22 ) ;
V_7 = F_1 ( V_2 , V_18 -> V_23 , V_4 ) ;
F_10 ( & V_2 -> V_22 ) ;
return V_7 ? V_7 : V_24 ;
case V_25 :
switch ( V_18 -> type ) {
case V_26 :
* V_4 = V_6 -> V_27 -> V_28 ;
* V_19 = V_6 -> V_27 -> V_29 ;
return V_30 ;
case V_31 :
* V_4 = 5000 ;
* V_19 = 12 ;
return V_32 ;
case V_33 :
* V_4 = 85000 - 25000 ;
* V_19 = 585 ;
return V_30 ;
default:
return - V_34 ;
}
case V_35 :
switch ( V_18 -> type ) {
case V_31 :
* V_4 = 2048 ;
return V_24 ;
case V_33 :
* V_4 = F_11 ( 25 * 585 , 85 - 25 ) ;
return V_24 ;
default:
return - V_34 ;
}
default:
break;
}
return - V_34 ;
}
static int F_12 ( struct V_36 * V_37 )
{
const struct V_38 * V_39 = F_13 ( V_37 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_14 ( & V_37 -> V_40 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_41 ;
V_6 = F_2 ( V_2 ) ;
F_15 ( V_37 , V_2 ) ;
V_6 -> V_16 = V_37 ;
V_6 -> V_27 = & V_42 [ V_39 -> V_43 ] ;
V_2 -> V_44 = V_37 -> V_40 . V_45 -> V_44 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = F_5 ( V_47 ) ;
V_2 -> V_40 . V_49 = & V_37 -> V_40 ;
V_2 -> V_27 = & V_50 ;
V_2 -> V_51 = V_52 ;
return F_16 ( V_2 ) ;
}
static int F_17 ( struct V_36 * V_37 )
{
F_18 ( F_19 ( V_37 ) ) ;
return 0 ;
}
