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
if ( ! F_4 ( V_5 -> V_12 ,
! F_5 ( & V_5 -> V_13 ) ,
V_14 / 20 ) )
F_6 ( & V_5 -> V_13 , 0 ) ;
F_7 ( V_2 ) ;
}
if ( V_7 -> V_15 -> V_10 )
V_7 -> V_15 -> V_10 ( V_7 , V_3 ) ;
V_5 -> V_10 = V_3 ;
if ( V_3 == V_11 )
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_1 ( V_2 , V_11 ) ;
F_11 ( V_2 -> V_16 ) ;
if ( V_7 -> V_15 -> V_17 )
V_7 -> V_15 -> V_17 ( V_7 ) ;
F_12 ( V_2 -> V_16 , V_11 ) ;
}
static bool
F_13 ( struct V_1 * V_2 ,
const struct V_18 * V_3 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_7 -> V_15 -> V_20 )
return V_7 -> V_15 -> V_20 ( V_7 , V_3 , V_19 ) ;
return true ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_18 * V_3 ,
struct V_18 * V_19 , int V_21 , int V_22 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_23 * V_25 = V_2 -> V_16 -> V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
memcpy ( & V_2 -> V_3 , V_19 , sizeof( * V_19 ) ) ;
V_26 = V_25 -> V_28 - V_21 ;
V_27 = V_25 -> V_29 - V_22 ;
if ( V_7 -> V_15 -> V_30 )
V_7 -> V_15 -> V_30 ( V_7 , & V_2 -> V_3 ) ;
return F_15 ( V_2 -> V_16 , V_2 , V_25 , 0 , 0 ,
V_26 , V_27 , V_21 , V_22 , V_26 , V_27 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_21 , int V_22 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_23 * V_25 = V_2 -> V_16 -> V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
int V_31 ;
if ( V_5 -> V_10 > V_11 ) {
F_17 ( L_3 ) ;
return - V_32 ;
}
V_26 = V_25 -> V_28 - V_21 ;
V_27 = V_25 -> V_29 - V_22 ;
V_31 = F_15 ( V_2 -> V_16 , V_2 , V_25 , 0 , 0 ,
V_26 , V_27 , V_21 , V_22 , V_26 , V_27 ) ;
if ( V_31 )
return V_31 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_21 , int V_22 ,
struct V_23 * V_24 )
{
return F_16 ( V_2 , V_21 , V_22 , V_24 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_31 ;
F_1 ( V_2 , V_35 ) ;
F_20 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_34 -> V_2 != V_2 )
continue;
V_31 = V_34 -> V_36 -> V_37 ( V_34 ) ;
if ( V_31 )
F_17 ( L_4 , V_31 ) ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_23 * V_25 ,
struct V_38 * V_39 ,
T_1 V_40 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_23 * V_24 = V_2 -> V_16 -> V_25 ;
int V_31 = - V_46 ;
if ( V_5 -> V_10 > V_11 ) {
F_17 ( L_5 ) ;
return - V_46 ;
}
F_22 ( & V_42 -> V_47 ) ;
if ( V_39 ) {
V_39 -> V_48 = V_5 -> V_48 ;
V_31 = F_23 ( V_42 , V_5 -> V_48 ) ;
if ( V_31 ) {
F_24 ( L_6 ) ;
goto V_49;
}
F_25 ( & V_42 -> V_50 ) ;
F_26 ( & V_39 -> V_8 . V_51 ,
& V_44 -> V_52 ) ;
F_6 ( & V_5 -> V_13 , 1 ) ;
F_27 ( & V_42 -> V_50 ) ;
V_2 -> V_16 -> V_25 = V_25 ;
V_31 = F_16 ( V_2 , V_2 -> V_21 , V_2 -> V_22 ,
NULL ) ;
if ( V_31 ) {
V_2 -> V_16 -> V_25 = V_24 ;
F_25 ( & V_42 -> V_50 ) ;
F_28 ( V_42 , V_5 -> V_48 ) ;
F_29 ( & V_39 -> V_8 . V_51 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
F_27 ( & V_42 -> V_50 ) ;
goto V_49;
}
}
V_49:
F_30 ( & V_42 -> V_47 ) ;
return V_31 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_43 * V_53 = V_2 -> V_42 -> V_45 ;
V_53 -> V_2 [ V_5 -> V_48 ] = NULL ;
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
T_2 V_56 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_55 == V_44 -> V_57 ) {
enum V_58 V_3 = V_56 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_59 :
F_10 ( V_2 ) ;
break;
case V_60 :
F_12 ( V_2 -> V_16 , V_35 ) ;
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
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_54 * V_61 ;
V_61 = V_44 -> V_57 ;
if ( ! V_61 ) {
V_61 = F_36 ( V_42 , 0 , L_7 , V_62 ,
F_37 ( V_62 ) ) ;
if ( ! V_61 )
return;
V_44 -> V_57 = V_61 ;
}
F_38 ( & V_2 -> V_8 , V_61 , 0 ) ;
}
int F_39 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_33 * V_34 ;
struct V_43 * V_53 = V_7 -> V_63 -> V_45 ;
struct V_1 * V_2 ;
int V_31 ;
V_5 = F_40 ( sizeof( * V_5 ) , V_64 ) ;
if ( ! V_5 )
return - V_65 ;
F_41 ( & V_5 -> V_12 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
V_5 -> V_10 = V_35 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_48 = V_7 -> V_48 ;
V_34 = F_42 ( V_7 -> V_63 , 1 << V_7 -> V_48 ,
V_66 ) ;
if ( F_43 ( V_34 ) ) {
V_31 = F_44 ( V_34 ) ;
goto V_67;
}
V_7 -> V_2 = & V_5 -> V_1 ;
V_2 = & V_5 -> V_1 ;
V_53 -> V_2 [ V_7 -> V_48 ] = V_2 ;
V_31 = F_45 ( V_7 -> V_63 , V_2 , V_34 , NULL ,
& V_68 ) ;
if ( V_31 < 0 )
goto V_69;
F_46 ( V_2 , & V_70 ) ;
F_35 ( V_2 ) ;
return 0 ;
V_69:
V_34 -> V_36 -> V_71 ( V_34 ) ;
V_67:
F_33 ( V_5 ) ;
return V_31 ;
}
int F_47 ( struct V_41 * V_42 , int V_48 )
{
struct V_43 * V_53 = V_42 -> V_45 ;
struct V_4 * V_5 =
F_2 ( V_53 -> V_2 [ V_48 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return - V_32 ;
if ( V_7 -> V_15 -> V_72 )
V_7 -> V_15 -> V_72 ( V_7 ) ;
return 0 ;
}
void F_48 ( struct V_41 * V_42 , int V_48 )
{
struct V_43 * V_53 = V_42 -> V_45 ;
struct V_4 * V_5 =
F_2 ( V_53 -> V_2 [ V_48 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return;
if ( V_7 -> V_15 -> V_73 )
V_7 -> V_15 -> V_73 ( V_7 ) ;
}
void F_49 ( struct V_41 * V_42 , int V_48 )
{
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_38 * V_74 , * V_75 ;
struct V_1 * V_1 = V_44 -> V_2 [ V_48 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_76 ;
F_50 ( & V_42 -> V_50 , V_76 ) ;
F_51 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_48 != V_74 -> V_48 )
continue;
F_29 ( & V_74 -> V_8 . V_51 ) ;
F_52 ( V_42 , - 1 , V_74 ) ;
F_28 ( V_42 , V_48 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
F_53 ( & V_5 -> V_12 ) ;
}
F_54 ( & V_42 -> V_50 , V_76 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_79 )
V_7 -> V_15 -> V_79 ( V_7 , V_78 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_80 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_81 )
V_7 -> V_15 -> V_81 ( V_7 , V_80 ) ;
}
void F_57 ( struct V_1 * V_2 , int V_80 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_82 )
V_7 -> V_15 -> V_82 ( V_7 , V_80 ) ;
}
void F_58 ( struct V_1 * V_2 , int V_80 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_83 )
V_7 -> V_15 -> V_83 ( V_7 , V_80 ) ;
}
void F_59 ( struct V_23 * V_25 )
{
struct V_6 * V_7 ;
struct V_41 * V_42 = V_25 -> V_42 ;
struct V_1 * V_2 ;
F_60 (crtc, &dev->mode_config.crtc_list, head) {
V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_84 )
V_7 -> V_15 -> V_84 ( V_7 ) ;
}
}
int F_61 ( struct V_41 * V_63 ,
unsigned int V_85 )
{
struct V_1 * V_2 ;
F_60 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_7 -> type == V_85 )
return V_5 -> V_7 -> V_48 ;
}
return - V_32 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_15 -> V_86 )
V_7 -> V_15 -> V_86 ( V_7 ) ;
}
