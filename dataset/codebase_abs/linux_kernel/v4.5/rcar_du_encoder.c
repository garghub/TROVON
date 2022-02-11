struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
if ( V_8 -> V_9 )
F_6 ( V_8 -> V_9 , V_6 -> V_10 , false ) ;
}
static void F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
if ( V_8 -> V_9 )
F_6 ( V_8 -> V_9 , V_6 -> V_10 , true ) ;
}
static int F_8 ( struct V_1 * V_6 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_15 * V_16 = & V_12 -> V_16 ;
const struct V_15 * V_17 = & V_12 -> V_17 ;
const struct V_15 * V_18 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_19 * V_20 = V_6 -> V_20 ;
if ( V_6 -> V_21 == V_22 )
return 0 ;
if ( F_9 ( & V_3 -> V_23 ) ) {
F_10 ( V_20 -> V_20 , L_1 ) ;
return - V_24 ;
}
V_18 = F_11 ( & V_3 -> V_23 ,
struct V_15 , V_25 ) ;
if ( V_17 -> V_26 != V_18 -> V_26 ||
V_17 -> V_27 != V_18 -> V_27 )
return - V_24 ;
F_12 ( V_16 , V_18 ) ;
if ( V_8 -> V_9 )
V_16 -> clock = F_13 ( V_16 -> clock ,
30000 , 150000 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_6 ,
struct V_15 * V_17 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_15 ( V_6 -> V_10 , V_8 -> V_28 ) ;
}
int F_16 ( struct V_29 * V_30 ,
enum V_31 type ,
enum V_32 V_28 ,
struct V_33 * V_34 ,
struct V_33 * V_35 )
{
struct V_7 * V_8 ;
struct V_1 * V_6 ;
unsigned int V_21 ;
int V_36 ;
V_8 = F_17 ( V_30 -> V_20 , sizeof( * V_8 ) , V_37 ) ;
if ( V_8 == NULL )
return - V_38 ;
V_8 -> V_28 = V_28 ;
V_6 = F_3 ( V_8 ) ;
switch ( V_28 ) {
case V_39 :
V_8 -> V_9 = V_30 -> V_9 [ 0 ] ;
break;
case V_40 :
V_8 -> V_9 = V_30 -> V_9 [ 1 ] ;
break;
default:
break;
}
switch ( type ) {
case V_41 :
V_21 = V_22 ;
break;
case V_42 :
V_21 = V_43 ;
break;
case V_44 :
V_21 = V_45 ;
break;
case V_46 :
default:
V_21 = V_30 -> V_47 -> V_48 [ V_28 ] . V_21 ;
break;
}
if ( type == V_44 ) {
V_36 = F_18 ( V_30 , V_8 , V_34 ) ;
if ( V_36 < 0 )
goto V_49;
} else {
V_36 = F_19 ( V_30 -> V_50 , V_6 , & V_51 ,
V_21 , NULL ) ;
if ( V_36 < 0 )
goto V_49;
F_20 ( V_6 , & V_52 ) ;
}
switch ( V_21 ) {
case V_43 :
V_36 = F_21 ( V_30 , V_8 , V_35 ) ;
break;
case V_22 :
V_36 = F_22 ( V_30 , V_8 ) ;
break;
case V_45 :
V_36 = F_23 ( V_30 , V_8 ) ;
break;
default:
V_36 = - V_24 ;
break;
}
V_49:
if ( V_36 < 0 ) {
if ( V_6 -> V_53 )
V_6 -> V_54 -> V_55 ( V_6 ) ;
F_24 ( V_30 -> V_20 , V_8 ) ;
}
return V_36 ;
}
