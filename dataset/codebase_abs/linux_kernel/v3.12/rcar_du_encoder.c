struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return & V_5 -> V_6 -> V_6 ;
}
static void F_3 ( struct V_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
if ( V_9 -> V_10 )
F_5 ( V_9 -> V_10 , V_6 -> V_11 , V_7 ) ;
}
static bool F_6 ( struct V_1 * V_6 ,
const struct V_12 * V_7 ,
struct V_12 * V_13 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
const struct V_12 * V_14 ;
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_2 * V_3 ;
bool V_17 = false ;
if ( V_6 -> V_18 == V_19 )
return true ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_3 -> V_6 == V_6 ) {
V_17 = true ;
break;
}
}
if ( ! V_17 ) {
F_8 ( V_16 -> V_16 , L_1 ) ;
return false ;
}
if ( F_9 ( & V_3 -> V_20 ) ) {
F_8 ( V_16 -> V_16 , L_2 ) ;
return false ;
}
V_14 = F_10 ( & V_3 -> V_20 ,
struct V_12 , V_21 ) ;
if ( V_7 -> V_22 != V_14 -> V_22 ||
V_7 -> V_23 != V_14 -> V_23 )
return false ;
F_11 ( V_13 , V_14 ) ;
if ( V_9 -> V_10 )
V_13 -> clock = F_12 ( V_13 -> clock ,
30000 , 150000 ) ;
return true ;
}
static void F_13 ( struct V_1 * V_6 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
if ( V_9 -> V_10 )
F_5 ( V_9 -> V_10 , V_6 -> V_11 ,
V_24 ) ;
}
static void F_14 ( struct V_1 * V_6 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
if ( V_9 -> V_10 )
F_5 ( V_9 -> V_10 , V_6 -> V_11 ,
V_25 ) ;
}
static void F_15 ( struct V_1 * V_6 ,
struct V_12 * V_7 ,
struct V_12 * V_13 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
F_16 ( V_6 -> V_11 , V_9 -> V_26 ) ;
}
int F_17 ( struct V_27 * V_28 ,
enum V_29 type ,
enum V_30 V_26 ,
const struct V_31 * V_32 )
{
struct V_8 * V_9 ;
unsigned int V_18 ;
int V_33 ;
V_9 = F_18 ( V_28 -> V_16 , sizeof( * V_9 ) , V_34 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_26 = V_26 ;
switch ( V_26 ) {
case V_36 :
V_9 -> V_10 = V_28 -> V_10 [ 0 ] ;
break;
case V_37 :
V_9 -> V_10 = V_28 -> V_10 [ 1 ] ;
break;
default:
break;
}
switch ( type ) {
case V_38 :
V_18 = V_19 ;
break;
case V_39 :
V_18 = V_40 ;
break;
case V_41 :
default:
V_18 = V_28 -> V_42 -> V_43 [ V_26 ] . V_18 ;
break;
}
V_33 = F_19 ( V_28 -> V_44 , & V_9 -> V_6 , & V_45 ,
V_18 ) ;
if ( V_33 < 0 )
return V_33 ;
F_20 ( & V_9 -> V_6 , & V_46 ) ;
switch ( V_18 ) {
case V_40 :
return F_21 ( V_28 , V_9 ,
& V_32 -> V_3 . V_10 . V_47 ) ;
case V_19 :
return F_22 ( V_28 , V_9 ) ;
default:
return - V_48 ;
}
}
