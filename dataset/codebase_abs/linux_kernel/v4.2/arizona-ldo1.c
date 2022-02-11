static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_4 -> V_5 )
return - V_6 ;
if ( V_3 == V_2 -> V_4 -> V_5 - 1 )
return 1800000 ;
else
return V_2 -> V_4 -> V_7 + ( V_2 -> V_4 -> V_8 * V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_7 , int V_9 )
{
int V_10 ;
V_10 = F_3 ( V_7 - V_2 -> V_4 -> V_7 , V_2 -> V_4 -> V_8 ) ;
if ( V_10 >= V_2 -> V_4 -> V_5 )
V_10 = V_2 -> V_4 -> V_5 - 1 ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_13 * V_13 = V_12 -> V_14 -> V_13 ;
unsigned int V_15 ;
int V_16 ;
if ( V_10 == V_2 -> V_4 -> V_5 - 1 )
V_15 = V_17 ;
else
V_15 = 0 ;
V_16 = F_6 ( V_13 , V_18 ,
V_17 , V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 )
return 0 ;
V_15 = V_10 << V_19 ;
return F_6 ( V_13 , V_20 ,
V_21 , V_15 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_13 * V_13 = V_12 -> V_14 -> V_13 ;
unsigned int V_15 ;
int V_16 ;
V_16 = F_8 ( V_13 , V_18 , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 & V_17 )
return V_2 -> V_4 -> V_5 - 1 ;
V_16 = F_8 ( V_13 , V_20 , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
return ( V_15 & V_21 ) >> V_19 ;
}
static int F_9 ( struct V_14 * V_14 ,
struct V_22 * V_23 ,
const struct V_24 * V_4 )
{
struct V_25 * V_26 = & V_14 -> V_26 ;
struct V_11 * V_27 = V_23 -> V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
V_26 -> V_34 = F_10 ( V_14 , L_1 , true ) ;
V_30 = F_11 ( V_14 -> V_35 -> V_36 , L_2 ) ;
V_31 = F_12 ( V_14 -> V_35 -> V_36 , L_3 , 0 ) ;
if ( V_30 ) {
V_23 -> V_36 = V_30 ;
V_33 = F_13 ( V_14 -> V_35 , V_30 ,
V_4 ) ;
if ( V_33 ) {
V_33 -> V_37 = & V_27 -> V_38 ;
V_33 -> V_39 = 1 ;
if ( V_31 && V_31 != V_30 )
V_14 -> V_40 = true ;
V_26 -> V_27 = V_33 ;
}
} else if ( V_31 ) {
V_14 -> V_40 = true ;
}
F_14 ( V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_42 )
{
struct V_14 * V_14 = F_16 ( V_42 -> V_35 . V_43 ) ;
const struct V_24 * V_4 ;
struct V_22 V_23 = { } ;
struct V_11 * V_27 ;
int V_16 ;
V_14 -> V_40 = false ;
V_27 = F_17 ( & V_42 -> V_35 , sizeof( * V_27 ) , V_44 ) ;
if ( ! V_27 )
return - V_45 ;
V_27 -> V_14 = V_14 ;
switch ( V_14 -> type ) {
case V_46 :
case V_47 :
V_4 = & V_48 ;
V_27 -> V_33 = V_49 ;
break;
case V_50 :
case V_51 :
V_4 = & V_11 ;
V_27 -> V_33 = V_52 ;
break;
default:
V_4 = & V_11 ;
V_27 -> V_33 = V_53 ;
break;
}
V_27 -> V_33 . V_37 = & V_27 -> V_38 ;
V_27 -> V_38 . V_38 = L_4 ;
V_27 -> V_38 . V_54 = V_54 ( V_14 -> V_35 ) ;
V_23 . V_35 = V_14 -> V_35 ;
V_23 . V_28 = V_27 ;
V_23 . V_13 = V_14 -> V_13 ;
if ( F_18 ( V_55 ) ) {
if ( ! F_19 ( V_14 -> V_35 ) ) {
V_16 = F_9 ( V_14 , & V_23 , V_4 ) ;
if ( V_16 < 0 )
return V_16 ;
V_23 . V_56 = true ;
}
}
V_23 . V_57 = V_14 -> V_26 . V_34 ;
if ( V_14 -> V_26 . V_27 )
V_23 . V_33 = V_14 -> V_26 . V_27 ;
else
V_23 . V_33 = & V_27 -> V_33 ;
if ( V_23 . V_33 -> V_39 == 0 )
V_14 -> V_40 = true ;
V_27 -> V_58 = F_20 ( & V_42 -> V_35 , V_4 , & V_23 ) ;
F_14 ( V_23 . V_36 ) ;
if ( F_21 ( V_27 -> V_58 ) ) {
V_16 = F_22 ( V_27 -> V_58 ) ;
F_23 ( V_14 -> V_35 , L_5 ,
V_16 ) ;
return V_16 ;
}
F_24 ( V_42 , V_27 ) ;
return 0 ;
}
