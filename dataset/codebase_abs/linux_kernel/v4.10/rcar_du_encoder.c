static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 , V_2 -> V_6 , false ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 , V_2 -> V_6 , true ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_8 -> V_12 ;
const struct V_11 * V_13 = & V_8 -> V_13 ;
const struct V_11 * V_14 ;
struct V_15 * V_16 = V_10 -> V_16 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_19 == V_20 )
return 0 ;
if ( F_6 ( & V_16 -> V_21 ) ) {
F_7 ( V_18 -> V_18 , L_1 ) ;
return - V_22 ;
}
V_14 = F_8 ( & V_16 -> V_21 ,
struct V_11 , V_23 ) ;
if ( V_13 -> V_24 != V_14 -> V_24 ||
V_13 -> V_25 != V_14 -> V_25 )
return - V_22 ;
F_9 ( V_12 , V_14 ) ;
if ( V_4 -> V_5 )
F_10 ( V_4 -> V_5 , V_12 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_13 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_2 -> V_6 , V_4 -> V_26 ) ;
}
int F_13 ( struct V_27 * V_28 ,
enum V_29 type ,
enum V_30 V_26 ,
struct V_31 * V_32 ,
struct V_31 * V_33 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_19 ;
int V_34 ;
V_4 = F_14 ( V_28 -> V_18 , sizeof( * V_4 ) , V_35 ) ;
if ( V_4 == NULL )
return - V_36 ;
V_4 -> V_26 = V_26 ;
V_2 = F_15 ( V_4 ) ;
switch ( V_26 ) {
case V_37 :
V_4 -> V_5 = V_28 -> V_5 [ 0 ] ;
break;
case V_38 :
V_4 -> V_5 = V_28 -> V_5 [ 1 ] ;
break;
default:
break;
}
switch ( type ) {
case V_39 :
V_19 = V_20 ;
break;
case V_40 :
V_19 = V_41 ;
break;
case V_42 :
V_19 = V_43 ;
break;
case V_44 :
default:
V_19 = V_28 -> V_45 -> V_46 [ V_26 ] . V_19 ;
break;
}
if ( type == V_42 ) {
V_34 = F_16 ( V_28 , V_4 , V_32 ) ;
if ( V_34 < 0 )
goto V_47;
} else {
V_34 = F_17 ( V_28 -> V_48 , V_2 , & V_49 ,
V_19 , NULL ) ;
if ( V_34 < 0 )
goto V_47;
F_18 ( V_2 , & V_50 ) ;
}
switch ( V_19 ) {
case V_41 :
V_34 = F_19 ( V_28 , V_4 , V_33 ) ;
break;
case V_20 :
V_34 = F_20 ( V_28 , V_4 ) ;
break;
case V_43 :
break;
default:
V_34 = - V_22 ;
break;
}
V_47:
if ( V_34 < 0 ) {
if ( V_2 -> V_51 )
V_2 -> V_52 -> V_53 ( V_2 ) ;
F_21 ( V_28 -> V_18 , V_4 ) ;
}
return V_34 ;
}
