static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( & V_4 -> V_6 ) ;
struct V_7 * V_8 ;
T_2 V_9 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_13 ,
& V_9 , sizeof( V_9 ) ) ;
break;
}
return V_9 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( & V_4 -> V_6 ) ;
struct V_7 * V_8 ;
T_2 V_9 = V_14 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_15 ,
& V_9 , sizeof( V_9 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( & V_4 -> V_6 ) ;
struct V_7 * V_8 ;
enum V_10 V_10 ;
F_5 ( V_2 , 0 ) ;
F_3 (port, intel_dsi->dcs_cabc_ports) {
T_2 V_16 = V_17 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_18 ,
& V_16 , sizeof( V_16 ) ) ;
}
F_3 (port, intel_dsi->dcs_backlight_ports) {
T_2 V_19 = 0 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_20 ,
& V_19 , sizeof( V_19 ) ) ;
V_19 &= ~ V_21 ;
V_19 &= ~ V_22 ;
V_19 &= ~ V_23 ;
F_6 ( V_8 , V_24 ,
& V_19 , sizeof( V_19 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( & V_4 -> V_6 ) ;
struct V_25 * V_26 = & V_2 -> V_26 ;
struct V_7 * V_8 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
T_2 V_19 = 0 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_20 ,
& V_19 , sizeof( V_19 ) ) ;
V_19 |= V_21 ;
V_19 |= V_22 ;
V_19 |= V_23 ;
F_6 ( V_8 , V_24 ,
& V_19 , sizeof( V_19 ) ) ;
}
F_3 (port, intel_dsi->dcs_cabc_ports) {
T_2 V_16 = V_27 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_18 ,
& V_16 , sizeof( V_16 ) ) ;
}
F_5 ( V_2 , V_26 -> V_28 . V_14 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_29 V_30 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
V_26 -> V_28 . V_31 = V_32 ;
V_26 -> V_28 . V_14 = V_32 ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_33 * V_34 = V_1 -> V_6 . V_34 ;
struct V_35 * V_36 = F_11 ( V_34 ) ;
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_25 * V_26 = & V_1 -> V_26 ;
if ( V_36 -> V_37 . V_28 . type != V_38 )
return - V_39 ;
if ( F_12 ( V_4 -> type != V_40 ) )
return - V_41 ;
V_26 -> V_28 . V_42 = F_9 ;
V_26 -> V_28 . V_43 = F_8 ;
V_26 -> V_28 . V_44 = F_7 ;
V_26 -> V_28 . V_45 = F_5 ;
V_26 -> V_28 . V_46 = F_1 ;
return 0 ;
}
