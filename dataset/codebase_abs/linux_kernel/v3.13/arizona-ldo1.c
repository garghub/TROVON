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
static int F_9 ( struct V_24 * V_25 )
{
struct V_14 * V_14 = F_10 ( V_25 -> V_26 . V_27 ) ;
const struct V_28 * V_4 ;
struct V_29 V_30 = { } ;
struct V_11 * V_31 ;
int V_16 ;
V_31 = F_11 ( & V_25 -> V_26 , sizeof( * V_31 ) , V_32 ) ;
if ( V_31 == NULL ) {
F_12 ( & V_25 -> V_26 , L_1 ) ;
return - V_33 ;
}
V_31 -> V_14 = V_14 ;
switch ( V_14 -> type ) {
case V_34 :
V_4 = & V_35 ;
V_31 -> V_36 = V_37 ;
break;
default:
V_4 = & V_11 ;
V_31 -> V_36 = V_38 ;
break;
}
V_31 -> V_36 . V_39 = & V_31 -> V_40 ;
V_31 -> V_40 . V_40 = L_2 ;
V_31 -> V_40 . V_41 = V_41 ( V_14 -> V_26 ) ;
V_30 . V_26 = V_14 -> V_26 ;
V_30 . V_42 = V_31 ;
V_30 . V_13 = V_14 -> V_13 ;
V_30 . V_43 = V_14 -> V_44 . V_45 ;
if ( V_14 -> V_44 . V_31 )
V_30 . V_36 = V_14 -> V_44 . V_31 ;
else
V_30 . V_36 = & V_31 -> V_36 ;
V_31 -> V_46 = F_13 ( & V_25 -> V_26 , V_4 , & V_30 ) ;
if ( F_14 ( V_31 -> V_46 ) ) {
V_16 = F_15 ( V_31 -> V_46 ) ;
F_12 ( V_14 -> V_26 , L_3 ,
V_16 ) ;
return V_16 ;
}
F_16 ( V_25 , V_31 ) ;
return 0 ;
}
