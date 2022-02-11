T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 ;
T_2 V_8 ;
T_2 V_9 ;
V_7 = F_3 ( V_2 , V_10 , & V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_11 , & V_9 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_12 = ( V_13 ) V_8 ;
V_6 -> V_12 = ( ( V_6 -> V_12 << 6 ) | ( ( V_9 & 0xFC00 ) >> 10 ) ) ;
V_6 -> V_14 = ( V_13 ) ( V_9 & 0x000F ) ;
F_4 ( V_4 -> V_15 ,
L_1 ,
V_6 -> V_12 , V_6 -> V_14 ) ;
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 , V_13 V_16 , T_2 * V_17 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( V_16 > V_18 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_15 , L_2 ,
V_16 ) ;
return - V_19 ;
}
* V_17 = F_6 ( V_2 , V_6 -> V_20 , V_21 ,
V_16 , ( T_2 ) 0 ) ;
return 0 ;
}
T_1 F_7 ( struct V_1 * V_2 , V_13 V_16 , T_2 V_17 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( V_16 > V_18 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_15 , L_2 ,
V_16 ) ;
return - V_19 ;
}
F_6 ( V_2 , V_6 -> V_20 , V_22 ,
V_16 , V_17 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_2 V_23 ;
F_3 ( V_2 , V_24 , & V_23 ) ;
V_23 |= V_25 ;
F_7 ( V_2 , V_24 , V_23 ) ;
F_9 ( 1 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_24 , V_26 ) ;
F_7 ( V_2 , V_27 ,
V_28 ) ;
F_7 ( V_2 , V_29 ,
V_30 ) ;
F_7 ( V_2 , V_31 , V_32 ) ;
F_7 ( V_2 , V_33 ,
V_34 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_2 V_35 ;
V_35 = 0 ;
F_3 ( V_2 , V_24 , & V_35 ) ;
V_35 &= ~ V_36 ;
F_7 ( V_2 , V_24 , V_35 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
T_2 V_35 ;
V_35 = 0 ;
F_3 ( V_2 , V_24 , & V_35 ) ;
V_35 |= V_36 ;
F_7 ( V_2 , V_24 , V_35 ) ;
F_13 ( 1 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_35 ;
int V_7 = 0 ;
switch ( V_2 -> V_6 . V_12 ) {
case V_37 :
F_4 ( V_4 -> V_15 ,
L_3 ) ;
F_3 ( V_2 , V_38 , & V_35 ) ;
V_7 = F_7 ( V_2 , V_38 ,
V_39 ) ;
if ( V_7 )
break;
F_3 ( V_2 , V_40 , & V_35 ) ;
V_35 |= V_41 ;
V_7 = F_7 ( V_2 , V_40 ,
V_35 ) ;
break;
default:
F_5 ( V_4 -> V_15 ,
L_4 ,
V_2 -> V_6 . V_12 ) ;
return - V_19 ;
}
if ( V_7 )
F_5 ( V_4 -> V_15 ,
L_5 ) ;
return V_7 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 V_43 = { . V_43 = V_44 } ;
int V_7 ;
T_2 V_35 ;
V_7 = F_17 ( & V_4 -> V_45 , & V_43 ) ;
if ( V_7 )
F_5 ( V_4 -> V_15 , L_6 ) ;
F_18 ( & V_43 , V_2 -> V_46 . V_47 ) ;
V_43 . V_48 = V_2 -> V_46 . V_49 ;
V_43 . V_50 = V_2 -> V_6 . V_51 ;
V_43 . V_52 = V_2 -> V_46 . V_52 ;
F_7 ( V_2 , V_53 , V_54 ) ;
V_7 = F_19 ( & V_4 -> V_45 , & V_43 ) ;
if ( V_7 )
F_5 ( V_4 -> V_15 , L_7 ) ;
F_8 ( V_2 ) ;
F_3 ( V_2 , V_33 , & V_35 ) ;
V_35 |= V_55 ;
F_7 ( V_2 , V_33 , V_35 ) ;
if ( V_4 -> V_56 && V_4 -> V_56 -> V_57 )
F_15 ( V_2 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_35 ;
int V_7 = 0 ;
switch ( V_2 -> V_6 . V_12 ) {
case V_37 :
F_4 ( V_4 -> V_15 ,
L_8 ) ;
V_7 = F_7 ( V_2 , V_38 ,
V_58 ) ;
if ( V_7 )
break;
F_3 ( V_2 , V_40 , & V_35 ) ;
V_35 &= ~ V_59 ;
V_7 = F_7 ( V_2 , V_40 ,
V_35 ) ;
break;
default:
F_5 ( V_4 -> V_15 ,
L_9 ,
V_2 -> V_6 . V_12 ) ;
return - V_19 ;
}
if ( V_7 )
F_5 ( V_4 -> V_15 ,
L_10 ) ;
return V_7 ;
}
