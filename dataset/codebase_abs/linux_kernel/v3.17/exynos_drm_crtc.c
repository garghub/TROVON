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
F_7 ( V_2 -> V_15 , V_5 -> V_16 ) ;
}
if ( V_7 -> V_17 -> V_10 )
V_7 -> V_17 -> V_10 ( V_7 , V_3 ) ;
V_5 -> V_10 = V_3 ;
}
static void F_8 ( struct V_1 * V_2 )
{
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_1 ( V_2 , V_11 ) ;
F_10 ( V_5 -> V_18 ) ;
if ( V_7 -> V_17 -> V_19 )
V_7 -> V_17 -> V_19 ( V_7 ) ;
F_11 ( V_5 -> V_18 , V_11 ) ;
}
static bool
F_12 ( struct V_1 * V_2 ,
const struct V_20 * V_3 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_7 -> V_17 -> V_22 )
return V_7 -> V_17 -> V_22 ( V_7 , V_3 , V_21 ) ;
return true ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_20 * V_3 ,
struct V_20 * V_21 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_27 * V_18 = V_5 -> V_18 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
memcpy ( & V_2 -> V_3 , V_21 , sizeof( * V_21 ) ) ;
V_28 = V_2 -> V_31 -> V_32 -> V_33 - V_23 ;
V_29 = V_2 -> V_31 -> V_32 -> V_34 - V_24 ;
if ( V_7 -> V_17 -> V_35 )
V_7 -> V_17 -> V_35 ( V_7 , & V_2 -> V_3 ) ;
V_30 = F_14 ( V_18 , V_2 , V_2 -> V_31 -> V_32 , 0 , 0 , V_28 , V_29 ,
V_23 , V_24 , V_28 , V_29 ) ;
if ( V_30 )
return V_30 ;
V_18 -> V_2 = V_2 ;
V_18 -> V_32 = V_2 -> V_31 -> V_32 ;
F_15 ( V_18 -> V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_27 * V_18 = V_5 -> V_18 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
if ( V_5 -> V_10 > V_11 ) {
F_17 ( L_3 ) ;
return - V_36 ;
}
V_28 = V_2 -> V_31 -> V_32 -> V_33 - V_23 ;
V_29 = V_2 -> V_31 -> V_32 -> V_34 - V_24 ;
V_30 = F_14 ( V_18 , V_2 , V_2 -> V_31 -> V_32 , 0 , 0 , V_28 , V_29 ,
V_23 , V_24 , V_28 , V_29 ) ;
if ( V_30 )
return V_30 ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
return F_16 ( V_2 , V_23 , V_24 , V_26 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_27 * V_18 ;
int V_30 ;
F_1 ( V_2 , V_37 ) ;
F_20 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_18 -> V_2 != V_2 )
continue;
V_30 = V_18 -> V_38 -> V_39 ( V_18 ) ;
if ( V_30 )
F_17 ( L_4 , V_30 ) ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_32 ,
struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_43 * V_15 = V_2 -> V_15 ;
struct V_44 * V_45 = V_15 -> V_46 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_26 = V_2 -> V_31 -> V_32 ;
int V_30 = - V_47 ;
if ( V_5 -> V_10 > V_11 ) {
F_17 ( L_5 ) ;
return - V_47 ;
}
F_22 ( & V_15 -> V_48 ) ;
if ( V_41 ) {
V_41 -> V_16 = V_5 -> V_16 ;
V_30 = F_23 ( V_15 , V_5 -> V_16 ) ;
if ( V_30 ) {
F_24 ( L_6 ) ;
goto V_49;
}
F_25 ( & V_15 -> V_50 ) ;
F_26 ( & V_41 -> V_8 . V_51 ,
& V_45 -> V_52 ) ;
F_6 ( & V_5 -> V_13 , 1 ) ;
F_27 ( & V_15 -> V_50 ) ;
V_2 -> V_31 -> V_32 = V_32 ;
V_30 = F_16 ( V_2 , V_2 -> V_23 , V_2 -> V_24 ,
NULL ) ;
if ( V_30 ) {
V_2 -> V_31 -> V_32 = V_26 ;
F_25 ( & V_15 -> V_50 ) ;
F_28 ( V_15 , V_5 -> V_16 ) ;
F_29 ( & V_41 -> V_8 . V_51 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
F_27 ( & V_15 -> V_50 ) ;
goto V_49;
}
}
V_49:
F_30 ( & V_15 -> V_48 ) ;
return V_30 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_44 * V_53 = V_2 -> V_15 -> V_46 ;
V_53 -> V_2 [ V_5 -> V_16 ] = NULL ;
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
T_2 V_56 )
{
struct V_43 * V_15 = V_2 -> V_15 ;
struct V_44 * V_45 = V_15 -> V_46 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_55 == V_45 -> V_57 ) {
enum V_58 V_3 = V_56 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_59 :
F_9 ( V_2 ) ;
break;
case V_60 :
F_11 ( V_5 -> V_18 ,
V_37 ) ;
break;
default:
break;
}
return 0 ;
}
return - V_47 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_15 = V_2 -> V_15 ;
struct V_44 * V_45 = V_15 -> V_46 ;
struct V_54 * V_61 ;
V_61 = V_45 -> V_57 ;
if ( ! V_61 ) {
V_61 = F_36 ( V_15 , 0 , L_7 , V_62 ,
F_37 ( V_62 ) ) ;
if ( ! V_61 )
return;
V_45 -> V_57 = V_61 ;
}
F_38 ( & V_2 -> V_8 , V_61 , 0 ) ;
}
int F_39 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_44 * V_53 = V_7 -> V_63 -> V_46 ;
struct V_1 * V_2 ;
V_5 = F_40 ( sizeof( * V_5 ) , V_64 ) ;
if ( ! V_5 )
return - V_65 ;
F_41 ( & V_5 -> V_12 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
V_5 -> V_10 = V_37 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_16 = V_7 -> V_16 ;
V_5 -> V_18 = F_42 ( V_7 -> V_63 ,
1 << V_7 -> V_16 , true ) ;
if ( ! V_5 -> V_18 ) {
F_33 ( V_5 ) ;
return - V_65 ;
}
V_7 -> V_2 = & V_5 -> V_1 ;
V_2 = & V_5 -> V_1 ;
V_53 -> V_2 [ V_7 -> V_16 ] = V_2 ;
F_43 ( V_7 -> V_63 , V_2 , & V_66 ) ;
F_44 ( V_2 , & V_67 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_43 * V_15 , int V_16 )
{
struct V_44 * V_53 = V_15 -> V_46 ;
struct V_4 * V_5 =
F_2 ( V_53 -> V_2 [ V_16 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return - V_36 ;
if ( V_7 -> V_17 -> V_68 )
V_7 -> V_17 -> V_68 ( V_7 ) ;
return 0 ;
}
void F_46 ( struct V_43 * V_15 , int V_16 )
{
struct V_44 * V_53 = V_15 -> V_46 ;
struct V_4 * V_5 =
F_2 ( V_53 -> V_2 [ V_16 ] ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_10 != V_11 )
return;
if ( V_7 -> V_17 -> V_69 )
V_7 -> V_17 -> V_69 ( V_7 ) ;
}
void F_47 ( struct V_43 * V_15 , int V_16 )
{
struct V_44 * V_45 = V_15 -> V_46 ;
struct V_40 * V_70 , * V_71 ;
struct V_1 * V_1 = V_45 -> V_2 [ V_16 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_72 ;
F_48 ( & V_15 -> V_50 , V_72 ) ;
F_49 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_16 != V_70 -> V_16 )
continue;
F_29 ( & V_70 -> V_8 . V_51 ) ;
F_50 ( V_15 , - 1 , V_70 ) ;
F_28 ( V_15 , V_16 ) ;
F_6 ( & V_5 -> V_13 , 0 ) ;
F_51 ( & V_5 -> V_12 ) ;
}
F_52 ( & V_15 -> V_50 , V_72 ) ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_75 )
V_7 -> V_17 -> V_75 ( V_7 , V_74 ) ;
}
void F_54 ( struct V_1 * V_2 , int V_76 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_77 )
V_7 -> V_17 -> V_77 ( V_7 , V_76 ) ;
}
void F_55 ( struct V_1 * V_2 , int V_76 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_78 )
V_7 -> V_17 -> V_78 ( V_7 , V_76 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_76 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_79 )
V_7 -> V_17 -> V_79 ( V_7 , V_76 ) ;
}
void F_57 ( struct V_25 * V_32 )
{
struct V_6 * V_7 ;
struct V_43 * V_15 = V_32 -> V_15 ;
struct V_1 * V_2 ;
F_58 (crtc, &dev->mode_config.crtc_list, head) {
V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_80 )
V_7 -> V_17 -> V_80 ( V_7 ) ;
}
}
int F_59 ( struct V_43 * V_63 ,
unsigned int V_81 )
{
struct V_1 * V_2 ;
F_58 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_7 -> type == V_81 )
return V_5 -> V_7 -> V_16 ;
}
return - V_36 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
if ( V_7 -> V_17 -> V_82 )
V_7 -> V_17 -> V_82 ( V_7 ) ;
}
