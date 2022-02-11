static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( ( L_1 ) ) ;
if ( F_3 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_4 ( V_2 ) ) ) {
F_2 ( ( L_2 ) ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = TRUE ;
V_2 -> V_9 = TRUE ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 =
V_13 | V_14 |
V_15 | V_16 ;
V_2 -> V_17 =
V_15 | V_16 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
F_2 ( ( L_3 ) ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_18 = FALSE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_19 , V_20 ;
V_19 = F_9 ( V_2 -> V_21 -> V_22 ) ;
V_20 = V_13 ;
if ( V_19 & V_23 )
V_20 |= V_14 ;
if ( V_19 & V_24 ) {
if ( V_19 & V_25 )
V_20 |= V_16 ;
else
V_20 |= V_15 ;
}
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_26 ;
int V_27 , V_28 ;
V_2 -> V_29 = FALSE ;
for ( V_28 = V_27 = 0 ; V_28 < 5 ; V_28 ++ ) {
F_11 ( V_2 , V_30 ) ;
if ( F_12 ( V_2 , & V_26 ) < 0 ) {
F_13 ( ( L_4 ) ) ;
return - V_31 ;
}
if ( V_26 == V_32 ) {
if ( ++ V_27 == 3 ) {
V_2 -> V_29 = TRUE ;
return 0 ;
}
}
}
return - V_31 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_29 )
return 0 ;
V_5 = F_15 ( V_2 , V_33 ,
V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_10 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( F_3 ( V_35 < 8000 || V_35 > 50000 ) )
return - V_36 ;
if ( V_2 -> V_37 != V_38 ) {
F_13 ( ( L_5
L_6 ) ) ;
V_2 -> V_21 -> V_39 = F_17 ( V_35 ) ;
V_2 -> V_39 = V_35 ;
return 0 ;
}
if ( F_18 ( V_2 ) )
return - V_31 ;
F_13 ( ( L_7 , V_35 ) ) ;
V_2 -> V_39 = V_35 ;
V_2 -> V_21 -> V_39 = F_17 ( V_35 ) ;
F_19 ( V_2 ) ;
return F_11 ( V_2 , V_40 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_41 )
{
T_1 clock ;
T_2 V_35 ;
F_13 ( ( L_8 ) ) ;
V_35 = 0 ;
switch ( V_41 ) {
case V_38 :
F_13 ( ( L_9 ) ) ;
V_35 = V_2 -> V_39 ;
clock = V_42 ;
break;
case V_43 :
F_13 ( ( L_10 ) ) ;
clock = V_44 ;
break;
case V_45 :
F_13 ( ( L_11 ) ) ;
clock = V_46 ;
break;
case V_47 :
F_13 ( ( L_12 ) ) ;
clock = V_48 ;
break;
default:
F_13 ( ( L_13 ,
V_41 ) ) ;
return - V_36 ;
}
V_2 -> V_37 = V_41 ;
V_2 -> V_21 -> V_37 = F_21 ( clock ) ;
F_19 ( V_2 ) ;
F_11 ( V_2 , V_49 ) ;
if ( V_35 )
F_16 ( V_2 , V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 clock )
{
F_13 ( ( L_14 , clock ) ) ;
switch ( clock ) {
case V_47 :
clock = V_50 ;
break;
case V_45 :
clock = V_51 ;
break;
default:
F_13 ( ( L_15 ) ) ;
return - V_36 ;
}
if ( F_18 ( V_2 ) )
return - V_31 ;
V_2 -> V_21 -> V_52 = F_21 ( clock ) ;
V_2 -> V_52 = clock ;
F_19 ( V_2 ) ;
return F_11 ( V_2 , V_49 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_53 , int V_54 )
{
if ( F_3 ( V_53 >= F_24 ( V_2 ) ) )
return - V_36 ;
if ( F_18 ( V_2 ) )
return - V_31 ;
V_2 -> V_55 [ V_53 ] = V_54 ;
V_54 += V_56 ;
V_2 -> V_21 -> V_57 [ V_53 ] = V_54 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 ) )
return - V_31 ;
F_19 ( V_2 ) ;
return F_11 ( V_2 , V_58 ) ;
}
static int F_26 ( struct V_1 * V_2 , char V_59 )
{
F_13 ( ( L_16 , V_59 ) ) ;
if ( V_59 )
V_2 -> V_21 -> V_60 |=
F_17 ( V_61 ) ;
else
V_2 -> V_21 -> V_60 &=
~ F_17 ( V_61 ) ;
V_2 -> V_18 = V_59 ;
return F_25 ( V_2 ) ;
}
