static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 =
F_2 ( V_4 -> V_7 ) ;
struct V_8 * V_8 = V_6 -> V_8 ;
T_1 V_9 ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
if ( V_2 -> V_12 == V_13 )
F_4 ( V_9 , V_14 , 0 ) ;
else
F_4 ( V_9 , V_15 , 0 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 =
F_2 ( V_4 -> V_7 ) ;
struct V_8 * V_8 = V_6 -> V_8 ;
T_1 V_9 ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
if ( V_2 -> V_12 == V_13 )
F_4 ( V_9 , V_14 , 1 ) ;
else
F_4 ( V_9 , V_15 , 1 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_6 * V_6 = F_2 ( V_19 ) ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_20 * V_21 =
& V_6 -> V_21 [ V_2 -> V_12 ] ;
T_1 V_9 ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_5 ( V_22 , V_8 -> V_10 + V_11 ) ;
F_5 ( V_23 , V_8 -> V_10 + V_24 ) ;
F_5 ( V_23 , V_8 -> V_10 + V_25 ) ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
switch ( F_8 ( V_17 ) ) {
case V_26 :
V_21 -> V_27 = 0 ;
F_4 ( V_9 , V_28 |
V_29 |
V_30 |
V_31 , 1 ) ;
break;
case V_32 :
V_21 -> V_27 = 1 ;
F_4 ( V_9 , V_28 |
V_30 , 1 ) ;
F_4 ( V_9 , V_29 |
V_31 , 0 ) ;
break;
case V_33 :
V_21 -> V_27 = 2 ;
F_4 ( V_9 , V_28 |
V_29 |
V_30 |
V_31 , 0 ) ;
break;
default:
F_9 ( V_34 L_1 ) ;
return - V_35 ;
}
V_21 -> V_36 = V_21 -> V_27 ;
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_37 ,
struct V_18 * V_19 )
{
int V_38 = 0 ;
switch ( V_37 ) {
case V_39 :
case V_40 :
case V_41 :
F_1 ( V_2 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
F_6 ( V_2 ) ;
break;
default:
V_38 = - V_35 ;
}
return V_38 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_6 * V_45 = F_2 ( V_19 ) ;
F_12 ( V_19 , V_2 , V_45 -> V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_46 * V_47 )
{
struct V_8 * V_8 = V_47 -> V_45 . V_48 ;
struct V_6 * V_6 ;
int V_38 ;
V_6 = F_14 ( & V_47 -> V_45 ,
sizeof( struct V_6 ) ,
V_49 ) ;
if ( ! V_6 ) {
F_15 ( & V_47 -> V_45 ,
L_2 ) ;
return - V_50 ;
}
V_6 -> V_8 = V_8 ;
V_6 -> V_21 [ V_13 ] . V_51 =
V_8 -> V_52 . V_53 ;
V_6 -> V_21 [ V_13 ] . V_54 =
V_8 -> V_52 . V_55 ;
V_6 -> V_21 [ V_56 ] . V_51 =
V_8 -> V_52 . V_57 ;
V_6 -> V_21 [ V_56 ] . V_54 =
V_8 -> V_52 . V_58 ;
F_16 ( & V_47 -> V_45 , V_6 ) ;
V_38 = F_17 ( & V_47 -> V_45 , & V_59 ) ;
if ( V_38 != 0 ) {
F_18 ( & V_47 -> V_45 , L_3 ) ;
return V_38 ;
}
V_38 = F_19 ( & V_47 -> V_45 ) ;
if ( V_38 ) {
F_18 ( & V_47 -> V_45 , L_4 , V_38 ) ;
F_20 ( & V_47 -> V_45 ) ;
return V_38 ;
}
return 0 ;
}
static int F_21 ( struct V_46 * V_47 )
{
F_20 ( & V_47 -> V_45 ) ;
F_22 ( & V_47 -> V_45 ) ;
return 0 ;
}
