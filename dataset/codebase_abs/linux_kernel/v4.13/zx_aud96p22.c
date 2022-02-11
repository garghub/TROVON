static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
if ( V_5 != V_12 )
return - V_13 ;
F_4 ( V_11 , V_14 , V_15 , 0 ) ;
F_4 ( V_11 , V_14 , V_15 , V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
if ( V_5 != V_12 )
return - V_13 ;
F_4 ( V_11 , V_14 , V_16 , 0 ) ;
F_4 ( V_11 , V_14 , V_16 , V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , unsigned int V_19 )
{
struct V_9 * V_10 = F_3 ( V_18 -> V_7 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
unsigned int V_20 ;
switch ( V_19 & V_21 ) {
case V_22 :
V_20 = 0 ;
break;
case V_23 :
V_20 = V_24 ;
break;
default:
return - V_13 ;
}
F_4 ( V_11 , V_25 , V_24 , V_20 ) ;
switch ( V_19 & V_26 ) {
case V_27 :
V_20 = V_28 ;
break;
case V_29 :
V_20 = V_30 ;
break;
case V_31 :
V_20 = V_32 ;
break;
default:
return - V_13 ;
}
F_4 ( V_11 , V_25 , V_33 , V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_35 -> V_39 ;
struct V_9 * V_10 ;
int V_40 ;
V_10 = F_8 ( V_39 , sizeof( * V_10 ) , V_41 ) ;
if ( V_10 == NULL )
return - V_42 ;
V_10 -> V_11 = F_9 ( V_35 , & V_43 ) ;
if ( F_10 ( V_10 -> V_11 ) ) {
V_40 = F_11 ( V_10 -> V_11 ) ;
F_12 ( V_39 , L_1 , V_40 ) ;
return V_40 ;
}
F_13 ( V_35 , V_10 ) ;
V_40 = F_14 ( V_39 , & V_44 , & V_45 , 1 ) ;
if ( V_40 ) {
F_12 ( V_39 , L_2 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_15 ( struct V_34 * V_35 )
{
F_16 ( & V_35 -> V_39 ) ;
return 0 ;
}
