static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_18 ] . V_19 ) ;
V_10 = V_8 -> V_10 ;
V_12 = V_10 -> V_12 ;
if ( V_4 -> V_20 != V_10 -> V_20 )
return 0 ;
switch ( V_6 ) {
case V_21 :
if ( V_4 -> V_22 != V_23 )
break;
V_16 = F_3 ( V_12 , V_24 ,
V_25 ,
V_26 ,
V_14 -> V_27 ) ;
if ( V_16 < 0 )
F_4 ( L_1 , V_16 ) ;
if ( V_14 -> V_28 ) {
V_16 = F_3 ( V_12 , V_29 ,
V_30 ,
V_31 ,
V_14 -> V_28 ) ;
if ( V_16 < 0 )
F_4 ( L_1 , V_16 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_18 ] . V_19 ) ;
V_10 = V_8 -> V_10 ;
V_12 = V_10 -> V_12 ;
if ( V_4 -> V_20 != V_10 -> V_20 )
return 0 ;
switch ( V_6 ) {
case V_23 :
V_16 = F_3 ( V_12 , V_24 , 0 , 0 , 0 ) ;
if ( V_16 < 0 ) {
F_4 ( L_2 , V_16 ) ;
return V_16 ;
}
if ( V_14 -> V_28 ) {
V_16 = F_3 ( V_12 , V_29 ,
0 , 0 , 0 ) ;
if ( V_16 < 0 ) {
F_4 ( L_2 , V_16 ) ;
return V_16 ;
}
}
break;
default:
break;
}
V_4 -> V_22 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_7 * V_8 ;
struct V_11 * V_32 ;
struct V_11 * V_12 ;
struct V_9 * V_33 ;
struct V_9 * V_34 ;
struct V_9 * V_35 ;
struct V_9 * V_36 ;
int V_16 ;
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_37 ] . V_19 ) ;
V_32 = V_8 -> V_12 ;
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_18 ] . V_19 ) ;
V_12 = V_8 -> V_12 ;
V_33 = V_8 -> V_10 ;
V_16 = F_7 ( V_12 , V_38 ,
V_39 ,
V_14 -> V_27 ,
V_40 ) ;
if ( V_16 != 0 ) {
F_8 ( V_12 -> V_20 , L_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_32 , 0 , 0 , V_41 , 0 ) ;
if ( V_16 != 0 ) {
F_8 ( V_32 -> V_20 , L_4 , V_16 ) ;
return V_16 ;
}
V_16 = F_9 ( V_33 , V_38 , 0 , 0 ) ;
if ( V_16 != 0 )
F_8 ( V_33 -> V_20 , L_5 , V_16 ) ;
V_16 = F_7 ( V_12 , V_42 , 0 ,
V_41 , V_43 ) ;
if ( V_16 != 0 )
F_8 ( V_12 -> V_20 , L_6 , V_16 ) ;
if ( V_2 -> V_44 == V_45 )
return 0 ;
V_16 = F_7 ( V_12 , V_46 ,
V_47 ,
V_14 -> V_28 ,
V_40 ) ;
if ( V_16 != 0 ) {
F_8 ( V_12 -> V_20 , L_7 , V_16 ) ;
return V_16 ;
}
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_45 ] . V_19 ) ;
V_34 = V_8 -> V_48 ;
V_16 = F_9 ( V_34 , V_46 , 0 , 0 ) ;
if ( V_16 != 0 ) {
F_8 ( V_34 -> V_20 , L_8 , V_16 ) ;
return V_16 ;
}
if ( V_2 -> V_44 == V_49 )
return 0 ;
V_8 = F_2 ( V_2 , V_2 -> V_17 [ V_49 ] . V_19 ) ;
V_35 = V_8 -> V_48 ;
V_36 = V_8 -> V_10 ;
V_16 = F_9 ( V_35 , V_38 , 0 , 0 ) ;
if ( V_16 != 0 ) {
F_8 ( V_33 -> V_20 , L_5 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_36 -> V_12 , V_50 ,
0 , V_41 , 0 ) ;
if ( V_16 != 0 ) {
F_8 ( V_36 -> V_20 , L_9 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_51 * V_52 )
{
int V_16 ;
V_53 [ V_52 -> V_54 ] . V_20 = & V_52 -> V_20 ;
V_16 = F_11 ( & V_52 -> V_20 , & V_53 [ V_52 -> V_54 ] ) ;
if ( V_16 )
F_8 ( & V_52 -> V_20 ,
L_10 ,
V_53 [ V_52 -> V_54 ] . V_19 , V_16 ) ;
return V_16 ;
}
