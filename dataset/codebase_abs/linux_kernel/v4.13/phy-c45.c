int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
if ( V_2 -> V_6 != V_7 )
return - V_8 ;
V_3 = F_2 ( V_2 , V_9 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_2 ( V_2 , V_9 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 &= ~ V_12 ;
V_4 &= ~ ( V_13 | 0x30 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
V_4 |= V_16 ;
break;
case V_17 :
V_3 |= V_18 ;
V_4 |= V_19 ;
break;
case V_20 :
V_3 |= V_21 ;
V_4 |= V_22 ;
break;
case V_23 :
V_3 |= V_24 ;
V_4 |= V_25 ;
break;
default:
return - V_8 ;
}
V_5 = F_3 ( V_2 , V_9 , V_10 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_3 ( V_2 , V_9 , V_11 , V_4 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_2 ( V_2 , V_27 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 &= ~ ( V_28 | V_29 ) ;
return F_3 ( V_2 , V_27 , V_10 , V_26 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_2 ( V_2 , V_27 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 |= V_28 | V_29 ;
return F_3 ( V_2 , V_27 , V_10 , V_26 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_26 = F_2 ( V_2 , V_27 , V_30 ) ;
return V_26 < 0 ? V_26 : V_26 & V_31 ? 1 : 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_32 )
{
int V_26 , V_33 ;
bool V_34 = true ;
while ( V_32 ) {
V_33 = F_8 ( V_32 ) ;
V_32 &= ~ F_9 ( V_33 ) ;
V_26 = F_2 ( V_2 , V_33 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! ( V_26 & V_35 ) )
V_34 = false ;
}
return V_34 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_2 ( V_2 , V_27 , V_36 ) ;
if ( V_26 < 0 )
return V_26 ;
V_2 -> V_37 = F_11 ( V_26 ) ;
V_2 -> V_38 = V_26 & V_39 ? 1 : 0 ;
V_2 -> V_40 = V_26 & V_41 ? 1 : 0 ;
V_26 = F_2 ( V_2 , V_27 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_43 )
V_2 -> V_37 |= V_44 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_2 ( V_2 , V_9 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
switch ( V_26 & V_12 ) {
case 0 :
V_2 -> V_14 = V_15 ;
break;
case V_18 :
V_2 -> V_14 = V_17 ;
break;
case V_21 :
V_2 -> V_14 = V_20 ;
break;
case V_24 :
V_2 -> V_14 = V_23 ;
break;
default:
V_2 -> V_14 = V_45 ;
break;
}
V_2 -> V_6 = V_7 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_32 = V_2 -> V_46 . V_47 ;
int V_5 ;
V_2 -> V_14 = V_23 ;
V_2 -> V_6 = V_7 ;
V_32 &= ~ ( F_9 ( V_48 ) | F_9 ( V_49 ) ) ;
V_5 = F_7 ( V_2 , V_32 ) ;
V_2 -> V_34 = V_5 > 0 ? 1 : 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = V_51 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
