struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_7 != V_10 )
V_7 = V_11 ;
if ( V_9 -> V_12 )
F_6 ( V_9 -> V_12 , V_6 -> V_13 , V_7 ) ;
}
static bool F_7 ( struct V_1 * V_6 ,
const struct V_14 * V_7 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
const struct V_14 * V_16 ;
struct V_17 * V_18 = V_6 -> V_18 ;
struct V_2 * V_3 ;
bool V_19 = false ;
if ( V_6 -> V_20 == V_21 )
return true ;
F_8 (connector, &dev->mode_config.connector_list, head) {
if ( V_3 -> V_6 == V_6 ) {
V_19 = true ;
break;
}
}
if ( ! V_19 ) {
F_9 ( V_18 -> V_18 , L_1 ) ;
return false ;
}
if ( F_10 ( & V_3 -> V_22 ) ) {
F_9 ( V_18 -> V_18 , L_2 ) ;
return false ;
}
V_16 = F_11 ( & V_3 -> V_22 ,
struct V_14 , V_23 ) ;
if ( V_7 -> V_24 != V_16 -> V_24 ||
V_7 -> V_25 != V_16 -> V_25 )
return false ;
F_12 ( V_15 , V_16 ) ;
if ( V_9 -> V_12 )
V_15 -> clock = F_13 ( V_15 -> clock ,
30000 , 150000 ) ;
return true ;
}
static void F_14 ( struct V_1 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_9 -> V_12 )
F_6 ( V_9 -> V_12 , V_6 -> V_13 ,
V_11 ) ;
}
static void F_15 ( struct V_1 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_9 -> V_12 )
F_6 ( V_9 -> V_12 , V_6 -> V_13 ,
V_10 ) ;
}
static void F_16 ( struct V_1 * V_6 ,
struct V_14 * V_7 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
F_17 ( V_6 -> V_13 , V_9 -> V_26 ) ;
}
int F_18 ( struct V_27 * V_28 ,
enum V_29 type ,
enum V_30 V_26 ,
struct V_31 * V_32 ,
struct V_31 * V_33 )
{
struct V_8 * V_9 ;
struct V_1 * V_6 ;
unsigned int V_20 ;
int V_34 ;
V_9 = F_19 ( V_28 -> V_18 , sizeof( * V_9 ) , V_35 ) ;
if ( V_9 == NULL )
return - V_36 ;
V_9 -> V_26 = V_26 ;
V_6 = F_3 ( V_9 ) ;
switch ( V_26 ) {
case V_37 :
V_9 -> V_12 = V_28 -> V_12 [ 0 ] ;
break;
case V_38 :
V_9 -> V_12 = V_28 -> V_12 [ 1 ] ;
break;
default:
break;
}
switch ( type ) {
case V_39 :
V_20 = V_21 ;
break;
case V_40 :
V_20 = V_41 ;
break;
case V_42 :
V_20 = V_43 ;
break;
case V_44 :
default:
V_20 = V_28 -> V_45 -> V_46 [ V_26 ] . V_20 ;
break;
}
if ( type == V_42 ) {
V_34 = F_20 ( V_28 , V_9 , V_32 ) ;
if ( V_34 < 0 )
goto V_47;
} else {
V_34 = F_21 ( V_28 -> V_48 , V_6 , & V_49 ,
V_20 ) ;
if ( V_34 < 0 )
goto V_47;
F_22 ( V_6 , & V_50 ) ;
}
switch ( V_20 ) {
case V_41 :
V_34 = F_23 ( V_28 , V_9 , V_33 ) ;
break;
case V_21 :
V_34 = F_24 ( V_28 , V_9 ) ;
break;
case V_43 :
V_34 = F_25 ( V_28 , V_9 ) ;
break;
default:
V_34 = - V_51 ;
break;
}
V_47:
if ( V_34 < 0 ) {
if ( V_6 -> V_52 )
V_6 -> V_53 -> V_54 ( V_6 ) ;
F_26 ( V_28 -> V_18 , V_9 ) ;
}
return V_34 ;
}
