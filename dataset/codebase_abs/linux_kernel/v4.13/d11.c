static T_1 F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
default:
F_2 ( 1 ) ;
}
return 0 ;
}
static T_1 F_3 ( enum V_9 V_10 )
{
switch ( V_10 ) {
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
default:
F_2 ( 1 ) ;
}
return 0 ;
}
static void F_4 ( struct V_15 * V_16 )
{
if ( V_16 -> V_10 == V_11 )
V_16 -> V_2 = V_3 ;
V_16 -> V_17 = 0 ;
F_5 ( & V_16 -> V_17 , V_18 ,
V_19 , V_16 -> V_20 ) ;
F_5 ( & V_16 -> V_17 , V_21 ,
0 , F_1 ( V_16 -> V_2 ) ) ;
F_5 ( & V_16 -> V_17 , V_22 ,
0 , F_3 ( V_16 -> V_10 ) ) ;
if ( V_16 -> V_20 <= V_23 )
V_16 -> V_17 |= V_24 ;
else
V_16 -> V_17 |= V_25 ;
}
static T_1 F_6 ( enum V_9 V_10 )
{
switch ( V_10 ) {
case V_11 :
return V_26 ;
case V_13 :
return V_27 ;
case V_28 :
return V_29 ;
default:
F_2 ( 1 ) ;
}
return 0 ;
}
static void F_7 ( struct V_15 * V_16 )
{
if ( V_16 -> V_10 == V_11 || V_16 -> V_2 == V_3 )
V_16 -> V_2 = V_5 ;
F_5 ( & V_16 -> V_17 , V_18 ,
V_19 , V_16 -> V_20 ) ;
F_5 ( & V_16 -> V_17 , V_30 ,
V_31 , V_16 -> V_2 ) ;
F_5 ( & V_16 -> V_17 , V_32 ,
0 , F_6 ( V_16 -> V_10 ) ) ;
V_16 -> V_17 &= ~ V_33 ;
if ( V_16 -> V_20 <= V_23 )
V_16 -> V_17 |= V_34 ;
else
V_16 -> V_17 |= V_35 ;
}
static void F_8 ( struct V_15 * V_16 )
{
T_1 V_36 ;
V_16 -> V_20 = ( V_37 ) ( V_16 -> V_17 & V_18 ) ;
V_16 -> V_38 = V_16 -> V_20 ;
switch ( V_16 -> V_17 & V_22 ) {
case V_12 :
V_16 -> V_10 = V_11 ;
V_16 -> V_2 = V_3 ;
break;
case V_14 :
V_16 -> V_10 = V_13 ;
V_36 = V_16 -> V_17 & V_21 ;
if ( V_36 == V_6 ) {
V_16 -> V_2 = V_5 ;
V_16 -> V_38 -= V_39 ;
} else {
V_16 -> V_2 = V_7 ;
V_16 -> V_38 += V_39 ;
}
break;
default:
F_9 ( 1 ) ;
break;
}
switch ( V_16 -> V_17 & V_40 ) {
case V_25 :
V_16 -> V_41 = V_42 ;
break;
case V_24 :
V_16 -> V_41 = V_43 ;
break;
default:
F_9 ( 1 ) ;
break;
}
}
static void F_10 ( struct V_15 * V_16 )
{
T_1 V_36 ;
V_16 -> V_20 = ( V_37 ) ( V_16 -> V_17 & V_18 ) ;
V_16 -> V_38 = V_16 -> V_20 ;
switch ( V_16 -> V_17 & V_32 ) {
case V_26 :
V_16 -> V_10 = V_11 ;
V_16 -> V_2 = V_3 ;
break;
case V_27 :
V_16 -> V_10 = V_13 ;
V_36 = V_16 -> V_17 & V_30 ;
if ( V_36 == V_44 ) {
V_16 -> V_2 = V_5 ;
V_16 -> V_38 -= V_39 ;
} else if ( V_36 == V_45 ) {
V_16 -> V_2 = V_7 ;
V_16 -> V_38 += V_39 ;
} else {
F_9 ( 1 ) ;
}
break;
case V_29 :
V_16 -> V_10 = V_28 ;
V_16 -> V_2 = F_11 ( V_16 -> V_17 , V_30 ,
V_31 ) ;
switch ( V_16 -> V_2 ) {
case V_46 :
V_16 -> V_38 -= V_47 ;
break;
case V_48 :
V_16 -> V_38 -= V_39 ;
break;
case V_49 :
V_16 -> V_38 += V_39 ;
break;
case V_50 :
V_16 -> V_38 += V_47 ;
break;
default:
F_9 ( 1 ) ;
break;
}
break;
case V_51 :
case V_52 :
default:
F_9 ( 1 ) ;
break;
}
switch ( V_16 -> V_17 & V_33 ) {
case V_35 :
V_16 -> V_41 = V_42 ;
break;
case V_34 :
V_16 -> V_41 = V_43 ;
break;
default:
F_9 ( 1 ) ;
break;
}
}
void F_12 ( struct V_53 * V_54 )
{
if ( V_54 -> V_55 == V_56 ) {
V_54 -> V_57 = F_4 ;
V_54 -> V_58 = F_8 ;
} else {
V_54 -> V_57 = F_7 ;
V_54 -> V_58 = F_10 ;
}
}
