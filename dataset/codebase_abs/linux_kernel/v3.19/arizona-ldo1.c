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
struct V_24 * V_25 ,
const struct V_26 * V_4 )
{
struct V_27 * V_28 = & V_14 -> V_28 ;
struct V_11 * V_29 = V_25 -> V_30 ;
struct V_31 * V_32 , * V_33 ;
struct V_34 * V_35 ;
V_28 -> V_36 = F_10 ( V_14 , L_1 , true ) ;
V_32 = F_11 ( V_14 -> V_37 -> V_38 , L_2 ) ;
V_33 = F_12 ( V_14 -> V_37 -> V_38 , L_3 , 0 ) ;
if ( V_32 ) {
V_25 -> V_38 = V_32 ;
V_35 = F_13 ( V_14 -> V_37 , V_32 ,
V_4 ) ;
if ( V_35 ) {
V_35 -> V_39 = & V_29 -> V_40 ;
V_35 -> V_41 = 1 ;
if ( V_33 && V_33 != V_32 )
V_14 -> V_42 = true ;
V_28 -> V_29 = V_35 ;
}
} else if ( V_33 ) {
V_14 -> V_42 = true ;
}
F_14 ( V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_43 * V_44 )
{
struct V_14 * V_14 = F_16 ( V_44 -> V_37 . V_45 ) ;
const struct V_26 * V_4 ;
struct V_24 V_25 = { } ;
struct V_11 * V_29 ;
int V_16 ;
V_14 -> V_42 = false ;
V_29 = F_17 ( & V_44 -> V_37 , sizeof( * V_29 ) , V_46 ) ;
if ( ! V_29 )
return - V_47 ;
V_29 -> V_14 = V_14 ;
switch ( V_14 -> type ) {
case V_48 :
case V_49 :
V_4 = & V_50 ;
V_29 -> V_35 = V_51 ;
break;
default:
V_4 = & V_11 ;
V_29 -> V_35 = V_52 ;
break;
}
V_29 -> V_35 . V_39 = & V_29 -> V_40 ;
V_29 -> V_40 . V_40 = L_4 ;
V_29 -> V_40 . V_53 = V_53 ( V_14 -> V_37 ) ;
V_25 . V_37 = V_14 -> V_37 ;
V_25 . V_30 = V_29 ;
V_25 . V_13 = V_14 -> V_13 ;
if ( F_18 ( V_54 ) ) {
if ( ! F_19 ( V_14 -> V_37 ) ) {
V_16 = F_9 ( V_14 , & V_25 , V_4 ) ;
if ( V_16 < 0 )
return V_16 ;
V_25 . V_55 = true ;
}
}
V_25 . V_56 = V_14 -> V_28 . V_36 ;
if ( V_14 -> V_28 . V_29 )
V_25 . V_35 = V_14 -> V_28 . V_29 ;
else
V_25 . V_35 = & V_29 -> V_35 ;
if ( V_25 . V_35 -> V_41 == 0 )
V_14 -> V_42 = true ;
V_29 -> V_57 = F_20 ( & V_44 -> V_37 , V_4 , & V_25 ) ;
if ( F_21 ( V_29 -> V_57 ) ) {
V_16 = F_22 ( V_29 -> V_57 ) ;
F_23 ( V_14 -> V_37 , L_5 ,
V_16 ) ;
return V_16 ;
}
F_14 ( V_25 . V_38 ) ;
F_24 ( V_44 , V_29 ) ;
return 0 ;
}
