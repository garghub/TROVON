static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 && V_4 -> V_5 -> V_6 ) {
F_3 ( V_4 -> V_5 -> V_6 ) ;
F_4 ( V_4 -> V_5 -> V_6 ) ;
}
if ( V_4 -> V_7 )
F_5 ( V_4 -> V_7 , V_2 -> V_8 , false ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_7 )
F_5 ( V_4 -> V_7 , V_2 -> V_8 , true ) ;
if ( V_4 -> V_5 && V_4 -> V_5 -> V_6 ) {
F_7 ( V_4 -> V_5 -> V_6 ) ;
F_8 ( V_4 -> V_5 -> V_6 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = & V_10 -> V_14 ;
const struct V_13 * V_15 = & V_10 -> V_15 ;
struct V_16 * V_5 = V_12 -> V_5 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_5 -> V_19 == V_20 ) {
const struct V_13 * V_21 ;
if ( F_10 ( & V_5 -> V_22 ) ) {
F_11 ( V_18 -> V_18 , L_1 ) ;
return - V_23 ;
}
V_21 = F_12 ( & V_5 -> V_22 ,
struct V_13 , V_24 ) ;
if ( V_15 -> V_25 != V_21 -> V_25 ||
V_15 -> V_26 != V_21 -> V_26 )
return - V_23 ;
F_13 ( V_14 , V_21 ) ;
}
if ( V_4 -> V_7 )
F_14 ( V_4 -> V_7 , V_14 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_12 -> V_5 -> V_29 ;
enum V_30 V_15 ;
F_16 ( V_10 -> V_8 , V_4 -> V_31 ) ;
if ( ! V_4 -> V_7 ) {
V_4 -> V_5 = NULL ;
return;
}
V_4 -> V_5 = F_17 ( V_12 -> V_5 ) ;
if ( ! V_28 -> V_32 || ! V_28 -> V_33 ) {
F_18 ( V_2 -> V_18 -> V_18 , L_2 ) ;
return;
}
switch ( V_28 -> V_33 [ 0 ] ) {
case V_34 :
case V_35 :
V_15 = V_36 ;
break;
case V_37 :
V_15 = V_38 ;
break;
default:
F_18 ( V_2 -> V_18 -> V_18 ,
L_3 ,
V_28 -> V_33 [ 0 ] ) ;
return;
}
if ( V_28 -> V_39 & V_40 )
V_15 |= V_41 ;
F_19 ( V_4 -> V_7 , V_15 ) ;
}
int F_20 ( struct V_42 * V_43 ,
enum V_44 V_31 ,
struct V_45 * V_46 ,
struct V_45 * V_47 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_48 * V_49 = NULL ;
int V_50 ;
V_4 = F_21 ( V_43 -> V_18 , sizeof( * V_4 ) , V_51 ) ;
if ( V_4 == NULL )
return - V_52 ;
V_4 -> V_31 = V_31 ;
V_2 = F_22 ( V_4 ) ;
switch ( V_31 ) {
case V_53 :
V_4 -> V_7 = V_43 -> V_7 [ 0 ] ;
break;
case V_54 :
V_4 -> V_7 = V_43 -> V_7 [ 1 ] ;
break;
default:
break;
}
if ( V_46 ) {
F_11 ( V_43 -> V_18 , L_4 ,
F_23 ( V_46 ) , V_31 ) ;
V_49 = F_24 ( V_46 ) ;
if ( ! V_49 ) {
V_50 = - V_55 ;
goto V_56;
}
} else {
F_11 ( V_43 -> V_18 ,
L_5 ,
V_31 ) ;
}
V_50 = F_25 ( V_43 -> V_57 , V_2 , & V_58 ,
V_59 , NULL ) ;
if ( V_50 < 0 )
goto V_56;
F_26 ( V_2 , & V_60 ) ;
if ( V_49 ) {
V_50 = F_27 ( V_2 , V_49 , NULL ) ;
if ( V_50 ) {
F_28 ( V_2 ) ;
return V_50 ;
}
} else {
switch ( V_31 ) {
case V_53 :
case V_54 :
V_50 = F_29 ( V_43 , V_4 , V_47 ) ;
break;
default:
V_50 = - V_23 ;
break;
}
}
V_56:
if ( V_50 < 0 ) {
if ( V_2 -> V_61 )
V_2 -> V_62 -> V_63 ( V_2 ) ;
F_30 ( V_43 -> V_18 , V_4 ) ;
}
return V_50 ;
}
