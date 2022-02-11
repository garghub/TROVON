static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( F_2 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_3 ( V_2 ) ) ) {
F_4 ( V_2 -> V_8 -> V_9 ,
L_1 ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = true ;
V_2 -> V_11 = true ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 =
V_15 | V_16 |
V_17 | V_18 ;
V_2 -> V_19 =
V_17 | V_18 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = false ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_20 = false ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_21 , V_22 ;
V_21 = F_9 ( V_2 -> V_23 -> V_24 ) ;
V_22 = V_15 ;
if ( V_21 & V_25 )
V_22 |= V_16 ;
if ( V_21 & V_26 ) {
if ( V_21 & V_27 )
V_22 |= V_18 ;
else
V_22 |= V_17 ;
}
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_28 ;
int V_29 , V_30 ;
V_2 -> V_31 = false ;
for ( V_30 = V_29 = 0 ; V_30 < 5 ; V_30 ++ ) {
F_11 ( V_2 , V_32 ) ;
if ( F_12 ( V_2 , & V_28 ) < 0 ) {
F_4 ( V_2 -> V_8 -> V_9 ,
L_2 ) ;
return - V_33 ;
}
if ( V_28 == V_34 ) {
if ( ++ V_29 == 3 ) {
V_2 -> V_31 = true ;
return 0 ;
}
}
}
return - V_33 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_31 )
return 0 ;
V_5 = F_14 ( V_2 , V_35 ,
V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_10 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_37 )
{
if ( F_2 ( V_37 < 8000 || V_37 > 50000 ) )
return - V_38 ;
if ( V_2 -> V_39 != V_40 ) {
F_16 ( V_2 -> V_8 -> V_9 ,
L_3 ) ;
V_2 -> V_23 -> V_41 = F_17 ( V_37 ) ;
V_2 -> V_41 = V_37 ;
return 0 ;
}
if ( F_18 ( V_2 ) )
return - V_33 ;
F_19 ( V_2 -> V_8 -> V_9 , L_4 , V_37 ) ;
V_2 -> V_41 = V_37 ;
V_2 -> V_23 -> V_41 = F_17 ( V_37 ) ;
F_20 ( V_2 ) ;
return F_11 ( V_2 , V_42 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_43 )
{
T_1 clock ;
T_2 V_37 ;
V_37 = 0 ;
switch ( V_43 ) {
case V_40 :
V_37 = V_2 -> V_41 ;
clock = V_44 ;
break;
case V_45 :
clock = V_46 ;
break;
case V_47 :
clock = V_48 ;
break;
case V_49 :
clock = V_50 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_5 ,
V_43 ) ;
return - V_38 ;
}
V_2 -> V_39 = V_43 ;
V_2 -> V_23 -> V_39 = F_22 ( clock ) ;
F_20 ( V_2 ) ;
F_11 ( V_2 , V_51 ) ;
if ( V_37 )
F_15 ( V_2 , V_37 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 clock )
{
switch ( clock ) {
case V_49 :
clock = V_52 ;
break;
case V_47 :
clock = V_53 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 , L_6 ) ;
return - V_38 ;
}
if ( F_18 ( V_2 ) )
return - V_33 ;
V_2 -> V_23 -> V_54 = F_22 ( clock ) ;
V_2 -> V_54 = clock ;
F_20 ( V_2 ) ;
return F_11 ( V_2 , V_51 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_55 , int V_56 )
{
if ( F_2 ( V_55 >= F_25 ( V_2 ) ) )
return - V_38 ;
if ( F_18 ( V_2 ) )
return - V_33 ;
V_2 -> V_57 [ V_55 ] = V_56 ;
V_56 += V_58 ;
V_2 -> V_23 -> V_59 [ V_55 ] = V_56 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) )
return - V_33 ;
F_20 ( V_2 ) ;
return F_11 ( V_2 , V_60 ) ;
}
static int F_27 ( struct V_1 * V_2 , char V_61 )
{
if ( V_61 )
V_2 -> V_23 -> V_62 |=
F_17 ( V_63 ) ;
else
V_2 -> V_23 -> V_62 &=
~ F_17 ( V_63 ) ;
V_2 -> V_20 = V_61 ;
return F_26 ( V_2 ) ;
}
