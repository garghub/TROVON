static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
V_7 -> V_11 |= V_12 ;
V_10 = F_4 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
F_5 ( 10000 , 20000 ) ;
V_10 = F_6 ( V_7 , V_13 << 4 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_8 ( V_7 , 0 , V_5 -> V_14 -> V_15 - 1 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_2 , V_10 ) ;
return V_10 ;
}
V_10 = F_9 ( V_7 , 0 , V_5 -> V_14 -> V_16 - 1 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_3 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 (dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY,
(u8[]){ 0x24 }, 1 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_4 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 (dsi, MIPI_DCS_WRITE_POWER_SAVE,
(u8[]){ 0x00 }, 1 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_5 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_7 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_6 , V_10 ) ;
return V_10 ;
}
F_12 ( 120 ) ;
V_10 = F_13 (dsi, (u8[]){0xB0 , 0x00}, 2 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_7 , V_10 ) ;
return V_10 ;
}
F_14 ( 10 ) ;
V_10 = F_13 (dsi, (u8[])
{0xB3 , 0x26 , 0x08 , 0x00 , 0x20 , 0x00}, 6 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_8
, V_10 ) ;
return V_10 ;
}
F_14 ( 20 ) ;
V_10 = F_13 (dsi, (u8[]){0xB0 , 0x03}, 2 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_9
, V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
V_7 -> V_11 |= V_12 ;
V_10 = F_16 ( V_7 ) ;
if ( V_10 < 0 )
F_7 ( V_9 , L_10 , V_10 ) ;
return V_10 ;
}
static void F_17 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
V_7 -> V_11 &= ~ V_12 ;
V_10 = F_18 ( V_7 ) ;
if ( V_10 < 0 )
F_7 ( V_9 , L_11 , V_10 ) ;
V_10 = F_19 ( V_7 ) ;
if ( V_10 < 0 )
F_7 ( V_9 , L_12 , V_10 ) ;
F_12 ( 100 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_17 )
return 0 ;
V_5 -> V_18 -> V_19 . V_20 = V_21 ;
F_21 ( V_5 -> V_18 ) ;
V_5 -> V_17 = false ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
if ( ! V_5 -> V_22 )
return 0 ;
F_17 ( V_5 ) ;
V_10 = F_23 ( F_24 ( V_5 -> V_23 ) , V_5 -> V_23 ) ;
if ( V_10 < 0 )
F_7 ( V_9 , L_13 , V_10 ) ;
F_25 ( V_5 -> V_24 , 0 ) ;
F_25 ( V_5 -> V_25 , 1 ) ;
F_25 ( V_5 -> V_26 , 0 ) ;
V_5 -> V_22 = false ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
if ( V_5 -> V_22 )
return 0 ;
V_10 = F_27 ( F_24 ( V_5 -> V_23 ) , V_5 -> V_23 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_14 , V_10 ) ;
return V_10 ;
}
F_12 ( 20 ) ;
F_25 ( V_5 -> V_26 , 1 ) ;
F_5 ( 10 , 20 ) ;
F_25 ( V_5 -> V_25 , 0 ) ;
F_5 ( 10 , 20 ) ;
F_25 ( V_5 -> V_24 , 1 ) ;
F_5 ( 10 , 20 ) ;
V_10 = F_3 ( V_5 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_15 , V_10 ) ;
goto V_27;
}
V_10 = F_15 ( V_5 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_16 , V_10 ) ;
goto V_27;
}
V_5 -> V_22 = true ;
return 0 ;
V_27:
V_10 = F_23 ( F_24 ( V_5 -> V_23 ) , V_5 -> V_23 ) ;
if ( V_10 < 0 )
F_7 ( V_9 , L_13 , V_10 ) ;
F_25 ( V_5 -> V_24 , 0 ) ;
F_25 ( V_5 -> V_25 , 1 ) ;
F_25 ( V_5 -> V_26 , 0 ) ;
return V_10 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_17 )
return 0 ;
V_5 -> V_18 -> V_19 . V_20 = V_28 ;
F_21 ( V_5 -> V_18 ) ;
V_5 -> V_17 = true ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_29 * V_14 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
V_14 = F_30 ( V_3 -> V_30 , & V_31 ) ;
if ( ! V_14 ) {
F_7 ( V_9 , L_17 ,
V_31 . V_15 , V_31 . V_16 ,
V_31 . V_32 ) ;
return - V_33 ;
}
F_31 ( V_14 ) ;
F_32 ( V_3 -> V_34 , V_14 ) ;
V_3 -> V_34 -> V_35 . V_36 = 95 ;
V_3 -> V_34 -> V_35 . V_37 = 151 ;
return 1 ;
}
static int F_33 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_34 ( V_39 ) ;
int V_10 ;
T_1 V_40 = V_39 -> V_19 . V_40 ;
V_7 -> V_11 &= ~ V_12 ;
V_10 = F_35 ( V_7 , & V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_11 |= V_12 ;
return V_40 & 0xff ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_34 ( V_39 ) ;
int V_10 ;
V_7 -> V_11 &= ~ V_12 ;
V_10 = F_37 ( V_7 , V_39 -> V_19 . V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_11 |= V_12 ;
return 0 ;
}
static struct V_38 *
F_38 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_41 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = V_42 ;
V_19 . V_40 = 255 ;
V_19 . V_43 = 255 ;
return F_39 ( V_9 , F_40 ( V_9 ) , V_9 , V_7 ,
& V_44 , & V_19 ) ;
}
static int F_41 ( struct V_1 * V_5 )
{
struct V_8 * V_9 = & V_5 -> V_7 -> V_9 ;
int V_10 ;
unsigned int V_45 ;
V_5 -> V_14 = & V_31 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_5 -> V_23 ) ; V_45 ++ )
V_5 -> V_23 [ V_45 ] . V_46 = V_47 [ V_45 ] ;
V_10 = F_42 ( V_9 , F_24 ( V_5 -> V_23 ) ,
V_5 -> V_23 ) ;
if ( V_10 < 0 ) {
F_7 ( V_9 , L_18 , V_10 ) ;
return V_10 ;
}
V_5 -> V_24 = F_43 ( V_9 , L_19 , V_48 ) ;
if ( F_44 ( V_5 -> V_24 ) ) {
V_10 = F_45 ( V_5 -> V_24 ) ;
F_7 ( V_9 , L_20 , V_10 ) ;
return V_10 ;
}
V_5 -> V_25 = F_43 ( V_9 , L_21 , V_49 ) ;
if ( F_44 ( V_5 -> V_25 ) ) {
V_10 = F_45 ( V_5 -> V_25 ) ;
F_7 ( V_9 , L_22 , V_10 ) ;
return V_10 ;
}
V_5 -> V_26 = F_43 ( V_9 , L_23 , V_48 ) ;
if ( F_44 ( V_5 -> V_26 ) ) {
V_10 = F_45 ( V_5 -> V_26 ) ;
F_7 ( V_9 , L_24 , V_10 ) ;
return V_10 ;
}
V_5 -> V_18 = F_38 ( V_5 -> V_7 ) ;
if ( F_44 ( V_5 -> V_18 ) ) {
V_10 = F_45 ( V_5 -> V_18 ) ;
F_7 ( V_9 , L_25 , V_10 ) ;
return V_10 ;
}
F_46 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_50 = & V_51 ;
V_5 -> V_4 . V_9 = & V_5 -> V_7 -> V_9 ;
V_10 = F_47 ( & V_5 -> V_4 ) ;
return V_10 ;
}
static void F_48 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_9 )
F_49 ( & V_5 -> V_4 ) ;
}
static int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
int V_10 ;
V_7 -> V_52 = 4 ;
V_7 -> V_53 = V_54 ;
V_7 -> V_11 = V_55 | V_56 |
V_57 ;
V_5 = F_51 ( & V_7 -> V_9 , sizeof( * V_5 ) , V_58 ) ;
if ( ! V_5 )
return - V_33 ;
F_52 ( V_7 , V_5 ) ;
V_5 -> V_7 = V_7 ;
V_10 = F_41 ( V_5 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_53 ( V_7 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_55 ( V_7 ) ;
int V_10 ;
V_10 = F_20 ( & V_5 -> V_4 ) ;
if ( V_10 < 0 )
F_7 ( & V_7 -> V_9 , L_26 , V_10 ) ;
V_10 = F_56 ( V_7 ) ;
if ( V_10 < 0 )
F_7 ( & V_7 -> V_9 , L_27 ,
V_10 ) ;
F_57 ( & V_5 -> V_4 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
static void F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_55 ( V_7 ) ;
F_20 ( & V_5 -> V_4 ) ;
}
