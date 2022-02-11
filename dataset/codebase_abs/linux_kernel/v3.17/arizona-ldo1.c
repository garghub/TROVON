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
V_16 = F_6 ( V_13 , V_19 ,
V_20 , V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 )
return 0 ;
V_15 = V_10 << V_21 ;
return F_6 ( V_13 , V_22 ,
V_23 , V_15 ) ;
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
V_16 = F_8 ( V_13 , V_22 , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
return ( V_15 & V_23 ) >> V_21 ;
}
static int F_9 ( struct V_14 * V_14 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_14 -> V_27 ;
struct V_11 * V_28 = V_25 -> V_29 ;
struct V_30 * V_31 , * V_32 ;
struct V_33 * V_34 ;
V_27 -> V_35 = F_10 ( V_14 , L_1 , true ) ;
V_31 = F_11 ( V_14 -> V_36 -> V_37 , L_2 ) ;
V_32 = F_12 ( V_14 -> V_36 -> V_37 , L_3 , 0 ) ;
if ( V_31 ) {
V_25 -> V_37 = V_31 ;
V_34 = F_13 ( V_14 -> V_36 , V_31 ) ;
if ( V_34 ) {
V_34 -> V_38 = & V_28 -> V_39 ;
V_34 -> V_40 = 1 ;
if ( V_32 && V_32 != V_31 )
V_14 -> V_41 = true ;
V_27 -> V_28 = V_34 ;
}
} else if ( V_32 ) {
V_14 -> V_41 = true ;
}
F_14 ( V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_14 * V_14 = F_16 ( V_43 -> V_36 . V_44 ) ;
const struct V_45 * V_4 ;
struct V_24 V_25 = { } ;
struct V_11 * V_28 ;
int V_16 ;
V_14 -> V_41 = false ;
V_28 = F_17 ( & V_43 -> V_36 , sizeof( * V_28 ) , V_46 ) ;
if ( ! V_28 )
return - V_47 ;
V_28 -> V_14 = V_14 ;
switch ( V_14 -> type ) {
case V_48 :
case V_49 :
V_4 = & V_50 ;
V_28 -> V_34 = V_51 ;
break;
default:
V_4 = & V_11 ;
V_28 -> V_34 = V_52 ;
break;
}
V_28 -> V_34 . V_38 = & V_28 -> V_39 ;
V_28 -> V_39 . V_39 = L_4 ;
V_28 -> V_39 . V_53 = V_53 ( V_14 -> V_36 ) ;
V_25 . V_36 = V_14 -> V_36 ;
V_25 . V_29 = V_28 ;
V_25 . V_13 = V_14 -> V_13 ;
if ( F_18 ( V_54 ) ) {
if ( ! F_19 ( V_14 -> V_36 ) ) {
V_16 = F_9 ( V_14 , & V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
}
}
V_25 . V_55 = V_14 -> V_27 . V_35 ;
if ( V_14 -> V_27 . V_28 )
V_25 . V_34 = V_14 -> V_27 . V_28 ;
else
V_25 . V_34 = & V_28 -> V_34 ;
if ( V_25 . V_34 -> V_40 == 0 )
V_14 -> V_41 = true ;
V_28 -> V_56 = F_20 ( & V_43 -> V_36 , V_4 , & V_25 ) ;
if ( F_21 ( V_28 -> V_56 ) ) {
V_16 = F_22 ( V_28 -> V_56 ) ;
F_23 ( V_14 -> V_36 , L_5 ,
V_16 ) ;
return V_16 ;
}
F_14 ( V_25 . V_37 ) ;
F_24 ( V_43 , V_28 ) ;
return 0 ;
}
