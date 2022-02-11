void
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
V_3 -> V_4 = V_2 -> V_4 ;
V_3 -> V_5 = V_2 -> V_5 ;
V_3 -> V_6 = V_2 -> V_6 ;
V_3 -> V_7 = V_2 -> V_7 ;
V_3 -> V_8 = V_2 -> V_8 ;
V_3 -> V_9 = V_2 -> V_9 ;
V_3 -> V_10 = V_2 -> V_10 ;
V_3 -> V_11 = V_2 -> V_11 ;
V_3 -> clock = V_2 -> clock ;
F_2 ( V_3 , V_12 ) ;
}
void
F_3 ( struct V_13 * V_14 ,
int V_15 ,
struct V_1 * V_16 ,
struct V_1 * V_3 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_20 , V_21 , V_22 , V_23 ;
V_20 = V_21 = V_22 = V_23 = 0 ;
if ( V_3 -> V_4 == V_16 -> V_4 &&
V_3 -> V_8 == V_16 -> V_8 )
goto V_24;
switch ( V_15 ) {
case V_25 :
V_22 = V_16 -> V_4 ;
V_23 = V_16 -> V_8 ;
V_20 = ( V_3 -> V_4 - V_22 + 1 ) / 2 ;
V_21 = ( V_3 -> V_8 - V_23 + 1 ) / 2 ;
break;
case V_26 :
{
T_1 V_27 = V_3 -> V_4 * V_16 -> V_8 ;
T_1 V_28 = V_16 -> V_4 * V_3 -> V_8 ;
if ( V_27 > V_28 ) {
V_22 = V_28 / V_16 -> V_8 ;
if ( V_22 & 1 )
V_22 ++ ;
V_20 = ( V_3 -> V_4 - V_22 + 1 ) / 2 ;
V_21 = 0 ;
V_23 = V_3 -> V_8 ;
} else if ( V_27 < V_28 ) {
V_23 = V_27 / V_16 -> V_4 ;
if ( V_23 & 1 )
V_23 ++ ;
V_21 = ( V_3 -> V_8 - V_23 + 1 ) / 2 ;
V_20 = 0 ;
V_22 = V_3 -> V_4 ;
} else {
V_20 = V_21 = 0 ;
V_22 = V_3 -> V_4 ;
V_23 = V_3 -> V_8 ;
}
}
break;
default:
case V_29 :
V_20 = V_21 = 0 ;
V_22 = V_3 -> V_4 ;
V_23 = V_3 -> V_8 ;
break;
}
V_24:
V_18 -> V_30 = ( V_20 << 16 ) | V_21 ;
V_18 -> V_31 = ( V_22 << 16 ) | V_23 ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( F_5 ( V_14 ) -> V_32 >= 4 )
return F_6 ( V_33 ) & V_34 ;
if ( F_7 ( V_14 ) )
return F_6 ( V_35 ) & V_36 ;
return 0 ;
}
static T_1 F_8 ( struct V_17 * V_18 )
{
T_1 V_37 ;
if ( F_9 ( V_18 -> V_14 ) ) {
V_37 = F_6 ( V_38 ) ;
if ( V_18 -> V_39 == 0 ) {
V_18 -> V_39 = V_37 ;
} else if ( V_37 == 0 ) {
F_10 ( V_38 ,
V_18 -> V_40 ) ;
V_37 = V_18 -> V_40 ;
}
} else {
V_37 = F_6 ( V_35 ) ;
if ( V_18 -> V_40 == 0 ) {
V_18 -> V_40 = V_37 ;
V_18 -> V_39 = F_6 ( V_33 ) ;
} else if ( V_37 == 0 ) {
F_10 ( V_35 ,
V_18 -> V_40 ) ;
F_10 ( V_33 ,
V_18 -> V_39 ) ;
V_37 = V_18 -> V_40 ;
}
}
return V_37 ;
}
T_1 F_11 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
T_1 V_41 ;
V_41 = F_8 ( V_18 ) ;
if ( V_41 == 0 ) {
F_12 ( V_42 L_1 ) ;
return 1 ;
}
if ( F_9 ( V_14 ) ) {
V_41 >>= 16 ;
} else {
if ( F_13 ( V_14 ) ) {
V_41 >>= 17 ;
} else {
V_41 >>= 16 ;
if ( F_5 ( V_14 ) -> V_32 < 4 )
V_41 &= ~ 1 ;
}
if ( F_4 ( V_14 ) )
V_41 *= 0xff ;
}
F_14 ( L_2 , V_41 ) ;
return V_41 ;
}
T_1 F_15 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
T_1 V_37 ;
if ( F_9 ( V_14 ) ) {
V_37 = F_6 ( V_43 ) & V_44 ;
} else {
V_37 = F_6 ( V_35 ) & V_44 ;
if ( F_13 ( V_14 ) )
V_37 >>= 1 ;
if ( F_4 ( V_14 ) ) {
T_2 V_45 ;
V_37 &= ~ 1 ;
F_16 ( V_14 -> V_46 , V_47 , & V_45 ) ;
V_37 *= V_45 ;
}
}
F_14 ( L_3 , V_37 ) ;
return V_37 ;
}
static void F_17 ( struct V_13 * V_14 , T_1 V_48 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
T_1 V_37 = F_6 ( V_43 ) & ~ V_44 ;
F_10 ( V_43 , V_37 | V_48 ) ;
}
void F_18 ( struct V_13 * V_14 , T_1 V_48 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
T_1 V_49 ;
F_14 ( L_4 , V_48 ) ;
if ( F_9 ( V_14 ) )
return F_17 ( V_14 , V_48 ) ;
if ( F_4 ( V_14 ) ) {
T_1 V_41 = F_11 ( V_14 ) ;
T_2 V_45 ;
V_45 = V_48 * 0xfe / V_41 + 1 ;
V_48 /= V_45 ;
F_19 ( V_14 -> V_46 , V_47 , V_45 ) ;
}
V_49 = F_6 ( V_35 ) ;
if ( F_13 ( V_14 ) ) {
V_49 &= ~ ( V_44 - 1 ) ;
V_48 <<= 1 ;
} else
V_49 &= ~ V_44 ;
F_10 ( V_35 , V_49 | V_48 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( V_18 -> V_50 ) {
V_18 -> V_51 = F_15 ( V_14 ) ;
V_18 -> V_50 = false ;
}
F_18 ( V_14 , 0 ) ;
}
void F_21 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( V_18 -> V_51 == 0 )
V_18 -> V_51 = F_11 ( V_14 ) ;
F_18 ( V_14 , V_18 -> V_51 ) ;
V_18 -> V_50 = true ;
}
static void F_22 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_51 = F_15 ( V_14 ) ;
V_18 -> V_50 = V_18 -> V_51 != 0 ;
}
enum V_52
F_23 ( struct V_13 * V_14 )
{
#if 0
struct drm_i915_private *dev_priv = dev->dev_private;
#endif
if ( V_53 )
return V_53 > 0 ?
V_54 :
V_55 ;
#if 0
if (dev_priv->opregion.lid_state)
return ioread32(dev_priv->opregion.lid_state) & 0x1 ?
connector_status_connected :
connector_status_disconnected;
#endif
return V_56 ;
}
static int F_24 ( struct V_57 * V_58 )
{
struct V_13 * V_14 = F_25 ( V_58 ) ;
F_18 ( V_14 , V_58 -> V_59 . V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_57 * V_58 )
{
struct V_13 * V_14 = F_25 ( V_58 ) ;
return F_15 ( V_14 ) ;
}
int F_27 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_61 V_59 ;
struct V_62 * V_63 ;
F_22 ( V_14 ) ;
if ( V_18 -> V_64 )
V_63 = V_18 -> V_64 ;
else if ( V_18 -> V_65 )
V_63 = V_18 -> V_65 ;
else
return - V_66 ;
V_59 . type = V_67 ;
V_59 . V_68 = F_11 ( V_14 ) ;
V_18 -> V_69 =
F_28 ( L_5 ,
& V_63 -> V_70 , V_14 ,
& V_71 , & V_59 ) ;
if ( F_29 ( V_18 -> V_69 ) ) {
F_30 ( L_6 ,
F_31 ( V_18 -> V_69 ) ) ;
V_18 -> V_69 = NULL ;
return - V_66 ;
}
V_18 -> V_69 -> V_59 . V_60 = F_15 ( V_14 ) ;
return 0 ;
}
void F_32 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( V_18 -> V_69 )
F_33 ( V_18 -> V_69 ) ;
}
int F_27 ( struct V_13 * V_14 )
{
F_22 ( V_14 ) ;
return 0 ;
}
void F_32 ( struct V_13 * V_14 )
{
return;
}
