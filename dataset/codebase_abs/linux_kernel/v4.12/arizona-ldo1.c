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
struct V_13 * V_13 = V_12 -> V_13 ;
unsigned int V_14 ;
int V_15 ;
if ( V_10 == V_2 -> V_4 -> V_5 - 1 )
V_14 = V_16 ;
else
V_14 = 0 ;
V_15 = F_6 ( V_13 , V_17 ,
V_16 , V_14 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( V_14 )
return 0 ;
V_14 = V_10 << V_18 ;
return F_6 ( V_13 , V_19 ,
V_20 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_13 * V_13 = V_12 -> V_13 ;
unsigned int V_14 ;
int V_15 ;
V_15 = F_8 ( V_13 , V_17 , & V_14 ) ;
if ( V_15 != 0 )
return V_15 ;
if ( V_14 & V_16 )
return V_2 -> V_4 -> V_5 - 1 ;
V_15 = F_8 ( V_13 , V_19 , & V_14 ) ;
if ( V_15 != 0 )
return V_15 ;
return ( V_14 & V_20 ) >> V_18 ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const struct V_25 * V_4 ,
bool * V_26 )
{
struct V_11 * V_27 = V_24 -> V_28 ;
struct V_29 * V_30 = V_24 -> V_31 -> V_32 ;
struct V_29 * V_33 , * V_34 ;
struct V_35 * V_36 ;
V_22 -> V_37 = F_10 ( V_30 , L_1 , 0 ) ;
if ( V_22 -> V_37 < 0 ) {
F_11 ( V_24 -> V_31 ,
L_2 ,
V_22 -> V_37 ) ;
V_22 -> V_37 = 0 ;
} else {
V_24 -> V_38 = true ;
}
V_33 = F_12 ( V_30 , L_3 ) ;
V_34 = F_13 ( V_30 , L_4 , 0 ) ;
if ( V_33 ) {
V_24 -> V_32 = V_33 ;
V_36 = F_14 ( V_24 -> V_31 , V_33 ,
V_4 ) ;
if ( V_36 ) {
V_36 -> V_39 = & V_27 -> V_40 ;
V_36 -> V_41 = 1 ;
if ( V_34 && V_34 != V_33 )
* V_26 = true ;
V_22 -> V_36 = V_36 ;
}
} else if ( V_34 ) {
* V_26 = true ;
}
F_15 ( V_34 ) ;
return 0 ;
}
static int F_16 ( struct V_42 * V_43 ,
struct V_11 * V_27 ,
const struct V_25 * V_4 ,
struct V_21 * V_22 ,
bool * V_26 )
{
struct V_44 * V_45 = V_43 -> V_31 . V_46 ;
struct V_23 V_24 = { } ;
int V_15 ;
* V_26 = false ;
V_27 -> V_40 . V_40 = L_5 ;
V_27 -> V_36 . V_39 = & V_27 -> V_40 ;
V_27 -> V_40 . V_47 = V_47 ( V_45 ) ;
V_24 . V_31 = V_45 ;
V_24 . V_28 = V_27 ;
V_24 . V_13 = V_27 -> V_13 ;
if ( F_17 ( V_48 ) ) {
if ( ! F_18 ( V_45 ) ) {
V_15 = F_9 ( V_22 ,
& V_24 , V_4 ,
V_26 ) ;
if ( V_15 < 0 )
return V_15 ;
}
}
V_24 . V_49 = V_22 -> V_37 ;
if ( V_22 -> V_36 )
V_24 . V_36 = V_22 -> V_36 ;
else
V_24 . V_36 = & V_27 -> V_36 ;
if ( V_24 . V_36 -> V_41 == 0 )
* V_26 = true ;
V_27 -> V_50 = F_19 ( & V_43 -> V_31 , V_4 , & V_24 ) ;
F_15 ( V_24 . V_32 ) ;
if ( F_20 ( V_27 -> V_50 ) ) {
V_15 = F_21 ( V_27 -> V_50 ) ;
F_22 ( & V_43 -> V_31 , L_6 ,
V_15 ) ;
return V_15 ;
}
F_23 ( V_43 , V_27 ) ;
return 0 ;
}
static int F_24 ( struct V_42 * V_43 )
{
struct V_51 * V_51 = F_25 ( V_43 -> V_31 . V_46 ) ;
struct V_11 * V_27 ;
const struct V_25 * V_4 ;
bool V_26 ;
int V_15 ;
V_27 = F_26 ( & V_43 -> V_31 , sizeof( * V_27 ) , V_52 ) ;
if ( ! V_27 )
return - V_53 ;
V_27 -> V_13 = V_51 -> V_13 ;
switch ( V_51 -> type ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_4 = & V_58 ;
V_27 -> V_36 = V_59 ;
break;
case V_60 :
case V_61 :
V_4 = & V_11 ;
V_27 -> V_36 = V_62 ;
break;
default:
V_4 = & V_11 ;
V_27 -> V_36 = V_63 ;
break;
}
V_15 = F_16 ( V_43 , V_27 , V_4 ,
& V_51 -> V_22 . V_27 ,
& V_26 ) ;
if ( V_15 == 0 )
V_51 -> V_26 = V_26 ;
return V_15 ;
}
