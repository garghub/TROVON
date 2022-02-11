static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 ;
if ( V_4 -> V_13 != V_8 -> V_13 )
return 0 ;
switch ( V_6 ) {
case V_14 :
if ( V_4 -> V_15 == V_16 ) {
V_12 = F_2 ( V_11 , V_17 ,
V_18 ,
V_19 ,
V_20 ) ;
if ( V_12 < 0 )
F_3 ( L_1 , V_12 ) ;
V_12 = F_2 ( V_11 , V_21 ,
V_22 ,
V_23 ,
V_24 ) ;
if ( V_12 < 0 )
F_3 ( L_1 , V_12 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 ;
if ( V_4 -> V_13 != V_8 -> V_13 )
return 0 ;
switch ( V_6 ) {
case V_16 :
V_12 = F_2 ( V_11 , V_17 , 0 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_3 ( L_2 , V_12 ) ;
return V_12 ;
}
V_12 = F_2 ( V_11 , V_21 , 0 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_3 ( L_2 , V_12 ) ;
return V_12 ;
}
break;
default:
break;
}
V_4 -> V_15 = V_6 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_9 [ 0 ] . V_11 ;
struct V_7 * V_25 = V_2 -> V_9 [ 0 ] . V_8 ;
struct V_7 * V_26 = V_2 -> V_9 [ 1 ] . V_27 ;
struct V_7 * V_28 = V_2 -> V_9 [ 2 ] . V_27 ;
struct V_7 * V_29 = V_2 -> V_9 [ 2 ] . V_8 ;
int V_12 ;
V_12 = F_6 ( V_25 , V_30 , 0 , 0 ) ;
if ( V_12 != 0 ) {
F_7 ( V_25 -> V_13 , L_3 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_26 , V_31 , 0 , 0 ) ;
if ( V_12 != 0 ) {
F_7 ( V_26 -> V_13 , L_4 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_28 , V_30 , 0 , 0 ) ;
if ( V_12 != 0 ) {
F_7 ( V_25 -> V_13 , L_3 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_11 , V_30 ,
V_32 , V_20 ,
V_33 ) ;
if ( V_12 != 0 ) {
F_7 ( V_11 -> V_13 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_11 , V_34 , 0 ,
V_35 , V_36 ) ;
if ( V_12 != 0 ) {
F_7 ( V_11 -> V_13 , L_6 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_11 , V_31 ,
V_37 , V_24 ,
V_33 ) ;
if ( V_12 != 0 ) {
F_7 ( V_11 -> V_13 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_29 -> V_11 , V_38 ,
0 , V_35 , 0 ) ;
if ( V_12 != 0 ) {
F_7 ( V_29 -> V_13 , L_7 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static T_1 int F_9 ( struct V_39 * V_40 )
{
int V_12 ;
V_41 [ V_40 -> V_42 ] . V_13 = & V_40 -> V_13 ;
V_12 = F_10 ( & V_41 [ V_40 -> V_42 ] ) ;
if ( V_12 ) {
F_7 ( & V_40 -> V_13 ,
L_8 ,
V_41 [ V_40 -> V_42 ] . V_43 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int T_2 F_11 ( struct V_39 * V_40 )
{
F_12 ( & V_41 [ V_40 -> V_42 ] ) ;
return 0 ;
}
