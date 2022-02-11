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
T_1 V_9 ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_5 ( V_20 , V_8 -> V_10 + V_11 ) ;
F_5 ( V_21 , V_8 -> V_10 + V_22 ) ;
F_5 ( V_21 , V_8 -> V_10 + V_23 ) ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
switch ( F_8 ( V_17 ) ) {
case V_24 :
F_4 ( V_9 , V_25 |
V_26 |
V_27 |
V_28 , 1 ) ;
break;
case V_29 :
F_4 ( V_9 , V_25 |
V_27 , 1 ) ;
F_4 ( V_9 , V_26 |
V_28 , 0 ) ;
break;
case V_30 :
F_4 ( V_9 , V_25 |
V_26 |
V_27 |
V_28 , 0 ) ;
break;
default:
F_9 ( V_31 L_1 ) ;
return - V_32 ;
}
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_33 ,
struct V_18 * V_19 )
{
int V_34 = 0 ;
switch ( V_33 ) {
case V_35 :
case V_36 :
case V_37 :
F_1 ( V_2 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_6 ( V_2 ) ;
break;
default:
V_34 = - V_32 ;
}
return V_34 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_6 * V_41 = F_2 ( V_19 ) ;
V_19 -> V_42 = & V_41 -> V_43 [ V_13 ] ;
V_19 -> V_44 = & V_41 -> V_43 [ V_45 ] ;
return 0 ;
}
static int F_12 ( struct V_46 * V_47 )
{
struct V_8 * V_8 = V_47 -> V_41 . V_48 ;
struct V_6 * V_6 ;
int V_34 ;
V_6 = F_13 ( & V_47 -> V_41 ,
sizeof( struct V_6 ) ,
V_49 ) ;
if ( ! V_6 ) {
F_14 ( & V_47 -> V_41 ,
L_2 ) ;
return - V_50 ;
}
V_6 -> V_8 = V_8 ;
V_6 -> V_43 [ V_13 ] . V_51 =
& V_8 -> V_52 . V_53 ;
V_6 -> V_43 [ V_13 ] . V_54 =
V_8 -> V_52 . V_55 ;
V_6 -> V_43 [ V_45 ] . V_51 =
& V_8 -> V_52 . V_56 ;
V_6 -> V_43 [ V_45 ] . V_54 =
V_8 -> V_52 . V_57 ;
F_15 ( & V_47 -> V_41 , V_6 ) ;
V_34 = F_16 ( & V_47 -> V_41 ,
& V_58 ,
& V_59 , 1 ) ;
if ( V_34 != 0 ) {
F_17 ( & V_47 -> V_41 , L_3 ) ;
return V_34 ;
}
V_34 = F_18 ( & V_47 -> V_41 ) ;
if ( V_34 ) {
F_17 ( & V_47 -> V_41 , L_4 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
