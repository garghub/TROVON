static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_3 ( L_1 , V_2 -> V_8 . V_9 , V_3 ) ;
if ( V_5 -> V_10 == V_3 ) {
F_3 ( L_2 ) ;
return;
}
if ( V_3 > V_11 ) {
F_4 ( V_5 -> V_12 ,
F_5 ( & V_5 -> V_13 ) == 0 ) ;
F_6 ( V_2 -> V_14 , V_5 -> V_15 ) ;
}
if ( V_7 -> V_16 -> V_10 )
V_7 -> V_16 -> V_10 ( V_7 , V_3 ) ;
V_5 -> V_10 = V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_1 ( V_2 , V_11 ) ;
F_9 ( V_5 -> V_17 ) ;
if ( V_7 -> V_16 -> V_18 )
V_7 -> V_16 -> V_18 ( V_7 ) ;
F_10 ( V_5 -> V_17 , V_11 ) ;
}
static bool
F_11 ( struct V_1 * V_2 ,
const struct V_19 * V_3 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_7 -> V_16 -> V_21 )
return V_7 -> V_16 -> V_21 ( V_7 , V_3 , V_20 ) ;
return true ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_19 * V_3 ,
struct V_19 * V_20 , int V_22 , int V_23 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_26 * V_17 = V_5 -> V_17 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_29 ;
memcpy ( & V_2 -> V_3 , V_20 , sizeof( * V_20 ) ) ;
V_27 = V_2 -> V_30 -> V_31 -> V_32 - V_22 ;
V_28 = V_2 -> V_30 -> V_31 -> V_33 - V_23 ;
if ( V_7 -> V_16 -> V_34 )
V_7 -> V_16 -> V_34 ( V_7 , & V_2 -> V_3 ) ;
V_29 = F_13 ( V_17 , V_2 , V_2 -> V_30 -> V_31 , 0 , 0 , V_27 , V_28 ,
V_22 , V_23 , V_27 , V_28 ) ;
if ( V_29 )
return V_29 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_31 = V_2 -> V_30 -> V_31 ;
F_14 ( V_17 -> V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_22 , int V_23 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_17 = V_5 -> V_17 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_29 ;
if ( V_5 -> V_10 > V_11 ) {
F_16 ( L_3 ) ;
return - V_35 ;
}
V_27 = V_2 -> V_30 -> V_31 -> V_32 - V_22 ;
V_28 = V_2 -> V_30 -> V_31 -> V_33 - V_23 ;
V_29 = F_13 ( V_17 , V_2 , V_2 -> V_30 -> V_31 , 0 , 0 , V_27 , V_28 ,
V_22 , V_23 , V_27 , V_28 ) ;
if ( V_29 )
return V_29 ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_22 , int V_23 ,
struct V_24 * V_25 )
{
return F_15 ( V_2 , V_22 , V_23 , V_25 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_17 ;
int V_29 ;
F_1 ( V_2 , V_36 ) ;
F_19 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_17 -> V_2 != V_2 )
continue;
V_29 = V_17 -> V_37 -> V_38 ( V_17 ) ;
if ( V_29 )
F_16 ( L_4 , V_29 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_24 * V_31 ,
struct V_39 * V_40 ,
T_1 V_41 )
{
struct V_42 * V_14 = V_2 -> V_14 ;
struct V_43 * V_44 = V_14 -> V_45 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_30 -> V_31 ;
int V_29 = - V_46 ;
if ( V_5 -> V_10 > V_11 ) {
F_16 ( L_5 ) ;
return - V_46 ;
}
F_21 ( & V_14 -> V_47 ) ;
if ( V_40 ) {
V_40 -> V_15 = V_5 -> V_15 ;
V_29 = F_22 ( V_14 , V_5 -> V_15 ) ;
if ( V_29 ) {
F_23 ( L_6 ) ;
goto V_48;
}
F_24 ( & V_14 -> V_49 ) ;
F_25 ( & V_40 -> V_8 . V_50 ,
& V_44 -> V_51 ) ;
F_26 ( & V_5 -> V_13 , 1 ) ;
F_27 ( & V_14 -> V_49 ) ;
V_2 -> V_30 -> V_31 = V_31 ;
V_29 = F_15 ( V_2 , V_2 -> V_22 , V_2 -> V_23 ,
NULL ) ;
if ( V_29 ) {
V_2 -> V_30 -> V_31 = V_25 ;
F_24 ( & V_14 -> V_49 ) ;
F_28 ( V_14 , V_5 -> V_15 ) ;
F_29 ( & V_40 -> V_8 . V_50 ) ;
F_27 ( & V_14 -> V_49 ) ;
goto V_48;
}
}
V_48:
F_30 ( & V_14 -> V_47 ) ;
return V_29 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_43 * V_52 = V_2 -> V_14 -> V_45 ;
V_52 -> V_2 [ V_5 -> V_15 ] = NULL ;
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
T_2 V_55 )
{
struct V_42 * V_14 = V_2 -> V_14 ;
struct V_43 * V_44 = V_14 -> V_45 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_54 == V_44 -> V_56 ) {
enum V_57 V_3 = V_55 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_58 :
F_8 ( V_2 ) ;
break;
case V_59 :
F_10 ( V_5 -> V_17 ,
V_36 ) ;
break;
default:
break;
}
return 0 ;
}
return - V_46 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_42 * V_14 = V_2 -> V_14 ;
struct V_43 * V_44 = V_14 -> V_45 ;
struct V_53 * V_60 ;
V_60 = V_44 -> V_56 ;
if ( ! V_60 ) {
V_60 = F_36 ( V_14 , 0 , L_7 , V_61 ,
F_37 ( V_61 ) ) ;
if ( ! V_60 )
return;
V_44 -> V_56 = V_60 ;
}
F_38 ( & V_2 -> V_8 , V_60 , 0 ) ;
}
int F_39 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_43 * V_52 = V_7 -> V_62 -> V_45 ;
struct V_1 * V_2 ;
V_5 = F_40 ( sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 )
return - V_64 ;
F_41 ( & V_5 -> V_12 ) ;
F_26 ( & V_5 -> V_13 , 0 ) ;
V_5 -> V_10 = V_36 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_15 = V_7 -> V_15 ;
V_5 -> V_17 = F_42 ( V_7 -> V_62 ,
1 << V_7 -> V_15 , true ) ;
if ( ! V_5 -> V_17 ) {
F_33 ( V_5 ) ;
return - V_64 ;
}
V_7 -> V_2 = & V_5 -> V_1 ;
V_2 = & V_5 -> V_1 ;
V_52 -> V_2 [ V_7 -> V_15 ] = V_2 ;
F_43 ( V_7 -> V_62 , V_2 , & V_65 ) ;
F_44 ( V_2 , & V_66 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_42 * V_14 , int V_15 )
{
struct V_43 * V_52 = V_14 -> V_45 ;
struct V_4 * V_5 =
F_2 ( V_52 -> V_2 [ V_15 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return - V_35 ;
if ( V_7 -> V_16 -> V_67 )
V_7 -> V_16 -> V_67 ( V_7 ) ;
return 0 ;
}
void F_46 ( struct V_42 * V_14 , int V_15 )
{
struct V_43 * V_52 = V_14 -> V_45 ;
struct V_4 * V_5 =
F_2 ( V_52 -> V_2 [ V_15 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return;
if ( V_7 -> V_16 -> V_68 )
V_7 -> V_16 -> V_68 ( V_7 ) ;
}
void F_47 ( struct V_42 * V_14 , int V_15 )
{
struct V_43 * V_44 = V_14 -> V_45 ;
struct V_39 * V_69 , * V_70 ;
struct V_1 * V_1 = V_44 -> V_2 [ V_15 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_71 ;
F_48 ( & V_14 -> V_49 , V_71 ) ;
F_49 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_15 != V_69 -> V_15 )
continue;
F_29 ( & V_69 -> V_8 . V_50 ) ;
F_50 ( V_14 , - 1 , V_69 ) ;
F_28 ( V_14 , V_15 ) ;
F_26 ( & V_5 -> V_13 , 0 ) ;
F_51 ( & V_5 -> V_12 ) ;
}
F_52 ( & V_14 -> V_49 , V_71 ) ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_16 -> V_74 )
V_7 -> V_16 -> V_74 ( V_7 , V_73 ) ;
}
void F_54 ( struct V_1 * V_2 , int V_75 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_16 -> V_76 )
V_7 -> V_16 -> V_76 ( V_7 , V_75 ) ;
}
void F_55 ( struct V_1 * V_2 , int V_75 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_16 -> V_77 )
V_7 -> V_16 -> V_77 ( V_7 , V_75 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_75 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_16 -> V_78 )
V_7 -> V_16 -> V_78 ( V_7 , V_75 ) ;
}
void F_57 ( struct V_24 * V_31 )
{
struct V_6 * V_7 ;
struct V_42 * V_14 = V_31 -> V_14 ;
struct V_1 * V_2 ;
F_58 (crtc, &dev->mode_config.crtc_list, head) {
V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_16 -> V_79 )
V_7 -> V_16 -> V_79 ( V_7 ) ;
}
}
int F_59 ( struct V_42 * V_62 ,
unsigned int V_80 )
{
struct V_1 * V_2 ;
F_58 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_7 -> type == V_80 )
return V_5 -> V_7 -> V_15 ;
}
return - V_35 ;
}
