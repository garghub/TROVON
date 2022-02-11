static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_3 ( V_4 -> V_6 , V_9 , & V_8 ) ;
return ( V_8 & V_10 ) ? true : false ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_11 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 , V_14 ;
int V_15 ;
T_1 V_5 , V_16 ;
switch ( V_12 ) {
case V_17 :
V_13 = V_18 ;
V_14 = V_19 ;
break;
case V_20 :
V_13 = V_21 ;
V_14 = V_22 ;
break;
case V_23 :
V_13 = V_24 ;
V_14 = V_25 ;
break;
default:
return - V_26 ;
}
F_3 ( V_4 -> V_6 , V_13 , & V_5 ) ;
F_3 ( V_4 -> V_6 , V_14 , & V_16 ) ;
V_15 = ( ( V_5 << 4 ) + ( V_16 >> 4 ) ) * 1250 / 1000 ;
return V_15 ;
}
static int F_6 ( struct V_27 * V_28 ,
enum V_11 V_12 ,
union V_29 * V_8 )
{
struct V_3 * V_4 = F_7 ( V_28 ) ;
switch ( V_12 ) {
case V_17 :
case V_20 :
case V_23 :
V_8 -> V_30 = F_5 ( V_4 -> V_2 ,
V_12 ) ;
break;
case V_31 :
V_8 -> V_30 = F_4 ( V_4 -> V_2 ) ;
break;
case V_32 :
V_8 -> V_30 = F_1 ( V_4 -> V_2 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = F_9 ( V_2 -> V_37 . V_38 ) ;
struct V_39 V_40 = {} ;
struct V_3 * V_4 ;
T_1 V_15 ;
if ( ! F_10 ( V_36 , V_41 ) )
return - V_42 ;
V_4 = F_11 ( & V_2 -> V_37 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_26 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = F_12 ( V_2 ,
& V_44 ) ;
if ( F_13 ( V_4 -> V_6 ) ) {
F_14 ( & V_2 -> V_37 , L_1 ) ;
return - V_26 ;
}
F_15 ( V_2 , V_4 ) ;
V_40 . V_45 = V_4 ;
V_4 -> V_28 = F_16 ( & V_2 -> V_37 ,
& V_46 , & V_40 ) ;
if ( F_13 ( V_4 -> V_28 ) ) {
F_14 ( & V_2 -> V_37 , L_2 ) ;
V_15 = F_17 ( V_4 -> V_28 ) ;
return V_15 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 -> V_28 ) ;
return 0 ;
}
