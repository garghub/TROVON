static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( & V_4 -> V_6 ) ;
struct V_7 * V_8 ;
T_2 V_9 = 0 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_13 ,
& V_9 , sizeof( V_9 ) ) ;
break;
}
return V_9 ;
}
static void F_5 ( const struct V_14 * V_15 , T_1 V_16 )
{
struct V_5 * V_5 = F_2 ( V_15 -> V_17 ) ;
struct V_7 * V_8 ;
T_2 V_9 = V_16 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_18 ,
& V_9 , sizeof( V_9 ) ) ;
}
}
static void F_7 ( const struct V_14 * V_15 )
{
struct V_5 * V_5 = F_2 ( V_15 -> V_17 ) ;
struct V_7 * V_8 ;
enum V_10 V_10 ;
F_5 ( V_15 , 0 ) ;
F_3 (port, intel_dsi->dcs_cabc_ports) {
T_2 V_19 = V_20 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_21 ,
& V_19 , sizeof( V_19 ) ) ;
}
F_3 (port, intel_dsi->dcs_backlight_ports) {
T_2 V_22 = 0 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_23 ,
& V_22 , sizeof( V_22 ) ) ;
V_22 &= ~ V_24 ;
V_22 &= ~ V_25 ;
V_22 &= ~ V_26 ;
F_6 ( V_8 , V_27 ,
& V_22 , sizeof( V_22 ) ) ;
}
}
static void F_8 ( const struct V_28 * V_29 ,
const struct V_14 * V_15 )
{
struct V_5 * V_5 = F_2 ( V_15 -> V_17 ) ;
struct V_30 * V_31 = & F_9 ( V_15 -> V_2 ) -> V_31 ;
struct V_7 * V_8 ;
enum V_10 V_10 ;
F_3 (port, intel_dsi->dcs_backlight_ports) {
T_2 V_22 = 0 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_4 ( V_8 , V_23 ,
& V_22 , sizeof( V_22 ) ) ;
V_22 |= V_24 ;
V_22 |= V_25 ;
V_22 |= V_26 ;
F_6 ( V_8 , V_27 ,
& V_22 , sizeof( V_22 ) ) ;
}
F_3 (port, intel_dsi->dcs_cabc_ports) {
T_2 V_19 = V_32 ;
V_8 = V_5 -> V_11 [ V_10 ] -> V_12 ;
F_6 ( V_8 , V_21 ,
& V_19 , sizeof( V_19 ) ) ;
}
F_5 ( V_15 , V_31 -> V_33 . V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
V_31 -> V_33 . V_36 = V_37 ;
V_31 -> V_33 . V_16 = V_37 ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 )
{
struct V_38 * V_39 = V_1 -> V_6 . V_39 ;
struct V_40 * V_41 = F_12 ( V_39 ) ;
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_30 * V_31 = & V_1 -> V_31 ;
if ( V_41 -> V_42 . V_33 . type != V_43 )
return - V_44 ;
if ( F_13 ( V_4 -> type != V_45 ) )
return - V_46 ;
V_31 -> V_33 . V_47 = F_10 ;
V_31 -> V_33 . V_48 = F_8 ;
V_31 -> V_33 . V_49 = F_7 ;
V_31 -> V_33 . V_50 = F_5 ;
V_31 -> V_33 . V_51 = F_1 ;
return 0 ;
}
