static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 & V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_2 -> V_3 |= V_8 | V_9 ;
break;
case V_10 :
default:
F_2 ( 1 ) ;
break;
}
if ( V_2 -> V_4 <= V_11 )
V_2 -> V_3 |= V_12 ;
else
V_2 -> V_3 |= V_13 ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 & V_5 ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_2 -> V_3 |= V_14 ;
break;
case V_10 :
case V_15 :
case V_16 :
case V_17 :
default:
F_2 ( 1 ) ;
break;
}
if ( V_2 -> V_4 <= V_11 )
V_2 -> V_3 |= V_18 ;
else
V_2 -> V_3 |= V_19 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_2 -> V_4 = ( V_21 ) ( V_2 -> V_3 & V_5 ) ;
switch ( V_2 -> V_3 & V_22 ) {
case V_8 :
V_2 -> V_6 = V_7 ;
break;
case V_23 :
V_2 -> V_6 = V_10 ;
V_20 = V_2 -> V_3 & V_24 ;
if ( V_20 == V_25 ) {
V_2 -> V_26 = V_27 ;
V_2 -> V_4 -= V_28 ;
} else {
V_2 -> V_26 = V_29 ;
V_2 -> V_4 += V_28 ;
}
break;
default:
F_2 ( 1 ) ;
break;
}
switch ( V_2 -> V_3 & V_30 ) {
case V_13 :
V_2 -> V_31 = V_32 ;
break;
case V_12 :
V_2 -> V_31 = V_33 ;
break;
default:
F_2 ( 1 ) ;
break;
}
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_2 -> V_4 = ( V_21 ) ( V_2 -> V_3 & V_5 ) ;
switch ( V_2 -> V_3 & V_34 ) {
case V_14 :
V_2 -> V_6 = V_7 ;
break;
case V_35 :
V_2 -> V_6 = V_10 ;
V_20 = V_2 -> V_3 & V_36 ;
if ( V_20 == V_37 ) {
V_2 -> V_26 = V_27 ;
V_2 -> V_4 -= V_28 ;
} else if ( V_20 == V_38 ) {
V_2 -> V_26 = V_29 ;
V_2 -> V_4 += V_28 ;
} else {
F_2 ( 1 ) ;
}
break;
case V_39 :
V_2 -> V_6 = V_15 ;
break;
case V_40 :
case V_41 :
default:
F_2 ( 1 ) ;
break;
}
switch ( V_2 -> V_3 & V_42 ) {
case V_19 :
V_2 -> V_31 = V_32 ;
break;
case V_18 :
V_2 -> V_31 = V_33 ;
break;
default:
F_2 ( 1 ) ;
break;
}
}
void F_6 ( struct V_43 * V_44 )
{
if ( V_44 -> V_45 == V_46 ) {
V_44 -> V_47 = F_1 ;
V_44 -> V_48 = F_4 ;
} else {
V_44 -> V_47 = F_3 ;
V_44 -> V_48 = F_5 ;
}
}
