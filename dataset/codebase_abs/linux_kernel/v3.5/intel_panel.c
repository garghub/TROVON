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
}
void
F_2 ( struct V_12 * V_13 ,
int V_14 ,
struct V_1 * V_15 ,
struct V_1 * V_3 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_19 , V_20 , V_21 , V_22 ;
V_19 = V_20 = V_21 = V_22 = 0 ;
if ( V_3 -> V_4 == V_15 -> V_4 &&
V_3 -> V_8 == V_15 -> V_8 )
goto V_23;
switch ( V_14 ) {
case V_24 :
V_21 = V_15 -> V_4 ;
V_22 = V_15 -> V_8 ;
V_19 = ( V_3 -> V_4 - V_21 + 1 ) / 2 ;
V_20 = ( V_3 -> V_8 - V_22 + 1 ) / 2 ;
break;
case V_25 :
{
T_1 V_26 = V_3 -> V_4 * V_15 -> V_8 ;
T_1 V_27 = V_15 -> V_4 * V_3 -> V_8 ;
if ( V_26 > V_27 ) {
V_21 = V_27 / V_15 -> V_8 ;
if ( V_21 & 1 )
V_21 ++ ;
V_19 = ( V_3 -> V_4 - V_21 + 1 ) / 2 ;
V_20 = 0 ;
V_22 = V_3 -> V_8 ;
} else if ( V_26 < V_27 ) {
V_22 = V_26 / V_15 -> V_4 ;
if ( V_22 & 1 )
V_22 ++ ;
V_20 = ( V_3 -> V_8 - V_22 + 1 ) / 2 ;
V_19 = 0 ;
V_21 = V_3 -> V_4 ;
} else {
V_19 = V_20 = 0 ;
V_21 = V_3 -> V_4 ;
V_22 = V_3 -> V_8 ;
}
}
break;
default:
case V_28 :
V_19 = V_20 = 0 ;
V_21 = V_3 -> V_4 ;
V_22 = V_3 -> V_8 ;
break;
}
V_23:
V_17 -> V_29 = ( V_19 << 16 ) | V_20 ;
V_17 -> V_30 = ( V_21 << 16 ) | V_22 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( F_4 ( V_13 ) -> V_31 >= 4 )
return F_5 ( V_32 ) & V_33 ;
if ( F_6 ( V_13 ) )
return F_5 ( V_34 ) & V_35 ;
return 0 ;
}
static T_1 F_7 ( struct V_16 * V_17 )
{
T_1 V_36 ;
if ( F_8 ( V_17 -> V_13 ) ) {
V_36 = F_5 ( V_37 ) ;
if ( V_17 -> V_38 == 0 ) {
V_17 -> V_38 = V_36 ;
} else if ( V_36 == 0 ) {
F_9 ( V_37 ,
V_17 -> V_38 ) ;
V_36 = V_17 -> V_38 ;
}
} else {
V_36 = F_5 ( V_34 ) ;
if ( V_17 -> V_39 == 0 ) {
V_17 -> V_39 = V_36 ;
V_17 -> V_38 = F_5 ( V_32 ) ;
} else if ( V_36 == 0 ) {
F_9 ( V_34 ,
V_17 -> V_39 ) ;
F_9 ( V_32 ,
V_17 -> V_38 ) ;
V_36 = V_17 -> V_39 ;
}
}
return V_36 ;
}
T_1 F_10 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_40 ;
V_40 = F_7 ( V_17 ) ;
if ( V_40 == 0 ) {
F_11 ( L_1 ) ;
return 1 ;
}
if ( F_8 ( V_13 ) ) {
V_40 >>= 16 ;
} else {
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_40 >>= 17 ;
else
V_40 >>= 16 ;
if ( F_3 ( V_13 ) )
V_40 *= 0xff ;
}
F_12 ( L_2 , V_40 ) ;
return V_40 ;
}
static T_1 F_13 ( struct V_12 * V_13 , T_1 V_36 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_41 < 0 )
return V_36 ;
if ( V_41 > 0 ||
V_17 -> V_42 & V_43 )
return F_10 ( V_13 ) - V_36 ;
return V_36 ;
}
T_1 F_14 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_36 ;
if ( F_8 ( V_13 ) ) {
V_36 = F_5 ( V_44 ) & V_45 ;
} else {
V_36 = F_5 ( V_34 ) & V_45 ;
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_36 >>= 1 ;
if ( F_3 ( V_13 ) ) {
T_2 V_46 ;
F_15 ( V_13 -> V_47 , V_48 , & V_46 ) ;
V_36 *= V_46 ;
}
}
V_36 = F_13 ( V_13 , V_36 ) ;
F_12 ( L_3 , V_36 ) ;
return V_36 ;
}
static void F_16 ( struct V_12 * V_13 , T_1 V_49 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_36 = F_5 ( V_44 ) & ~ V_45 ;
F_9 ( V_44 , V_36 | V_49 ) ;
}
static void F_17 ( struct V_12 * V_13 , T_1 V_49 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_50 ;
F_12 ( L_4 , V_49 ) ;
V_49 = F_13 ( V_13 , V_49 ) ;
if ( F_8 ( V_13 ) )
return F_16 ( V_13 , V_49 ) ;
if ( F_3 ( V_13 ) ) {
T_1 V_40 = F_10 ( V_13 ) ;
T_2 V_46 ;
V_46 = V_49 * 0xfe / V_40 + 1 ;
V_49 /= V_46 ;
F_18 ( V_13 -> V_47 , V_48 , V_46 ) ;
}
V_50 = F_5 ( V_34 ) ;
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_49 <<= 1 ;
V_50 &= ~ V_45 ;
F_9 ( V_34 , V_50 | V_49 ) ;
}
void F_19 ( struct V_12 * V_13 , T_1 V_49 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_51 = V_49 ;
if ( V_17 -> V_52 )
F_17 ( V_13 , V_49 ) ;
}
void F_20 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_52 = false ;
F_17 ( V_13 , 0 ) ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_51 == 0 )
V_17 -> V_51 = F_10 ( V_13 ) ;
V_17 -> V_52 = true ;
F_17 ( V_13 , V_17 -> V_51 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_51 = F_14 ( V_13 ) ;
V_17 -> V_52 = V_17 -> V_51 != 0 ;
}
enum V_53
F_23 ( struct V_12 * V_13 )
{
#if 0
struct drm_i915_private *dev_priv = dev->dev_private;
#endif
if ( V_54 )
return V_54 > 0 ?
V_55 :
V_56 ;
#if 0
if (dev_priv->opregion.lid_state)
return ioread32(dev_priv->opregion.lid_state) & 0x1 ?
connector_status_connected :
connector_status_disconnected;
#endif
return V_57 ;
}
static int F_24 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = F_25 ( V_59 ) ;
F_19 ( V_13 , V_59 -> V_60 . V_61 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = F_25 ( V_59 ) ;
struct V_16 * V_17 = V_13 -> V_18 ;
return V_17 -> V_51 ;
}
int F_27 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_62 V_60 ;
struct V_63 * V_64 ;
F_22 ( V_13 ) ;
if ( V_17 -> V_65 )
V_64 = V_17 -> V_65 ;
else if ( V_17 -> V_66 )
V_64 = V_17 -> V_66 ;
else
return - V_67 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . type = V_68 ;
V_60 . V_69 = F_10 ( V_13 ) ;
V_17 -> V_70 =
F_28 ( L_5 ,
& V_64 -> V_71 , V_13 ,
& V_72 , & V_60 ) ;
if ( F_29 ( V_17 -> V_70 ) ) {
F_30 ( L_6 ,
F_31 ( V_17 -> V_70 ) ) ;
V_17 -> V_70 = NULL ;
return - V_67 ;
}
V_17 -> V_70 -> V_60 . V_61 = F_14 ( V_13 ) ;
return 0 ;
}
void F_32 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_70 )
F_33 ( V_17 -> V_70 ) ;
}
int F_27 ( struct V_12 * V_13 )
{
F_22 ( V_13 ) ;
return 0 ;
}
void F_32 ( struct V_12 * V_13 )
{
return;
}
