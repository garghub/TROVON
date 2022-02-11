static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
T_1 V_9 , V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_14 = F_2 ( V_7 , V_5 ) ;
V_12 = V_14 -> V_12 ;
V_10 = V_15 ;
switch ( V_14 -> V_16 ) {
case 32 :
V_9 = V_17 ;
break;
case 16 :
V_9 = V_15 ;
break;
case 8 :
V_9 = V_18 ;
break;
default:
V_9 = V_17 ;
}
if ( V_5 -> V_19 == V_20 ) {
V_12 -> V_21 . V_22 = V_10 ;
V_12 -> V_23 . V_22 = V_9 ;
} else {
V_12 -> V_21 . V_22 = V_9 ;
V_12 -> V_23 . V_22 = V_10 ;
}
return F_3 ( V_24 , V_12 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_2 * V_3 = V_5 -> V_29 ;
struct V_30 * V_31 = V_3 -> V_8 -> V_32 -> V_33 ;
struct V_34 * V_35 ;
struct V_13 * V_36 ;
T_2 V_37 ;
int V_38 ;
if ( V_31 ) {
V_36 =
F_2 ( V_3 -> V_8 , V_5 ) ;
V_37 = V_36 -> V_39 ;
} else {
V_35 =
F_2 ( V_3 -> V_8 , V_5 ) ;
V_37 = V_35 -> V_40 ;
}
V_38 = F_5 ( V_5 , V_26 , V_28 ) ;
if ( V_38 )
return V_38 ;
V_28 -> V_41 = 4 ;
V_28 -> V_42 = 4 ;
V_28 -> V_43 = V_15 ;
V_28 -> V_44 = V_15 ;
if ( V_5 -> V_19 == V_20 )
V_28 -> V_45 = V_37 ;
else
V_28 -> V_46 = V_37 ;
return 0 ;
}
int F_6 ( struct V_47 * V_48 )
{
const struct V_49 * V_50 ;
struct V_51 * V_52 = V_48 -> V_32 . V_53 ;
int V_38 ;
if ( V_52 )
V_50 = & V_54 ;
else
V_50 = & V_55 ;
V_38 = F_7 ( & V_48 -> V_32 , V_50 ,
V_56 ) ;
if ( V_38 < 0 ) {
F_8 ( & V_48 -> V_32 ,
L_1 ,
V_57 , V_48 -> V_58 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
int F_9 ( struct V_47 * V_48 )
{
F_10 ( & V_48 -> V_32 ) ;
return 0 ;
}
