static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ V_10 ] . V_8 ;
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
if ( V_4 -> V_17 != V_8 -> V_17 )
return 0 ;
switch ( V_6 ) {
case V_18 :
if ( V_4 -> V_19 != V_20 )
break;
V_16 = F_2 ( V_12 , V_21 ,
V_22 ,
V_23 ,
V_14 -> V_24 ) ;
if ( V_16 < 0 )
F_3 ( L_1 , V_16 ) ;
if ( V_14 -> V_25 ) {
V_16 = F_2 ( V_12 , V_26 ,
V_27 ,
V_28 ,
V_14 -> V_25 ) ;
if ( V_16 < 0 )
F_3 ( L_1 , V_16 ) ;
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
struct V_7 * V_8 = V_2 -> V_9 [ V_10 ] . V_8 ;
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
if ( V_4 -> V_17 != V_8 -> V_17 )
return 0 ;
switch ( V_6 ) {
case V_20 :
V_16 = F_2 ( V_12 , V_21 , 0 , 0 , 0 ) ;
if ( V_16 < 0 ) {
F_3 ( L_2 , V_16 ) ;
return V_16 ;
}
if ( V_14 -> V_25 ) {
V_16 = F_2 ( V_12 , V_26 ,
0 , 0 , 0 ) ;
if ( V_16 < 0 ) {
F_3 ( L_2 , V_16 ) ;
return V_16 ;
}
}
break;
default:
break;
}
V_4 -> V_19 = V_6 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_11 * V_29 = V_2 -> V_9 [ V_30 ] . V_12 ;
struct V_11 * V_12 = V_2 -> V_9 [ V_10 ] . V_12 ;
struct V_7 * V_31 = V_2 -> V_9 [ V_10 ] . V_8 ;
struct V_7 * V_32 ;
struct V_7 * V_33 ;
struct V_7 * V_34 ;
int V_16 ;
V_16 = F_6 ( V_12 , V_35 ,
V_36 ,
V_14 -> V_24 ,
V_37 ) ;
if ( V_16 != 0 ) {
F_7 ( V_12 -> V_17 , L_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_6 ( V_29 , 0 , 0 , V_38 , 0 ) ;
if ( V_16 != 0 ) {
F_7 ( V_29 -> V_17 , L_4 , V_16 ) ;
return V_16 ;
}
V_16 = F_8 ( V_31 , V_35 , 0 , 0 ) ;
if ( V_16 != 0 )
F_7 ( V_31 -> V_17 , L_5 , V_16 ) ;
V_16 = F_6 ( V_12 , V_39 , 0 ,
V_38 , V_40 ) ;
if ( V_16 != 0 )
F_7 ( V_12 -> V_17 , L_6 , V_16 ) ;
if ( V_2 -> V_41 == V_42 )
return 0 ;
V_16 = F_6 ( V_12 , V_43 ,
V_44 ,
V_14 -> V_25 ,
V_37 ) ;
if ( V_16 != 0 ) {
F_7 ( V_12 -> V_17 , L_7 , V_16 ) ;
return V_16 ;
}
V_32 = V_2 -> V_9 [ V_42 ] . V_45 ;
V_16 = F_8 ( V_32 , V_43 , 0 , 0 ) ;
if ( V_16 != 0 ) {
F_7 ( V_32 -> V_17 , L_8 , V_16 ) ;
return V_16 ;
}
if ( V_2 -> V_41 == V_46 )
return 0 ;
V_33 = V_2 -> V_9 [ V_46 ] . V_45 ;
V_34 = V_2 -> V_9 [ V_46 ] . V_8 ;
V_16 = F_8 ( V_33 , V_35 , 0 , 0 ) ;
if ( V_16 != 0 ) {
F_7 ( V_31 -> V_17 , L_5 , V_16 ) ;
return V_16 ;
}
V_16 = F_6 ( V_34 -> V_12 , V_47 ,
0 , V_38 , 0 ) ;
if ( V_16 != 0 ) {
F_7 ( V_34 -> V_17 , L_9 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_48 * V_49 )
{
int V_16 ;
V_50 [ V_49 -> V_51 ] . V_17 = & V_49 -> V_17 ;
V_16 = F_10 ( & V_50 [ V_49 -> V_51 ] ) ;
if ( V_16 ) {
F_7 ( & V_49 -> V_17 ,
L_10 ,
V_50 [ V_49 -> V_51 ] . V_52 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_48 * V_49 )
{
F_12 ( & V_50 [ V_49 -> V_51 ] ) ;
return 0 ;
}
