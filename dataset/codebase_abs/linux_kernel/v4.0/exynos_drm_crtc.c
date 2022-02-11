static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_2 -> V_6 . V_7 , V_3 ) ;
if ( V_5 -> V_8 == V_3 ) {
F_3 ( L_2 ) ;
return;
}
if ( V_3 > V_9 ) {
if ( ! F_4 ( V_5 -> V_10 ,
! F_5 ( & V_5 -> V_11 ) ,
V_12 / 20 ) )
F_6 ( & V_5 -> V_11 , 0 ) ;
F_7 ( V_2 ) ;
}
if ( V_5 -> V_13 -> V_8 )
V_5 -> V_13 -> V_8 ( V_5 , V_3 ) ;
V_5 -> V_8 = V_3 ;
if ( V_3 == V_9 )
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_11 ( V_2 -> V_16 ) ;
F_1 ( V_2 , V_9 ) ;
if ( V_5 -> V_13 -> V_17 )
V_5 -> V_13 -> V_17 ( V_5 , V_15 -> V_18 ) ;
if ( V_5 -> V_13 -> V_19 )
V_5 -> V_13 -> V_19 ( V_5 ) ;
}
static bool
F_12 ( struct V_1 * V_2 ,
const struct V_20 * V_3 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_13 -> V_22 )
return V_5 -> V_13 -> V_22 ( V_5 , V_3 ,
V_21 ) ;
return true ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_20 * V_3 ,
struct V_20 * V_21 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_25 * V_27 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
memcpy ( & V_2 -> V_3 , V_21 , sizeof( * V_21 ) ) ;
V_30 = F_14 ( V_2 -> V_16 , V_27 ) ;
if ( V_30 < 0 )
return V_30 ;
V_28 = V_27 -> V_31 - V_23 ;
V_29 = V_27 -> V_32 - V_24 ;
F_15 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_23 , V_24 , V_28 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
if ( V_5 -> V_8 > V_9 ) {
F_17 ( L_3 ) ;
return - V_33 ;
}
V_28 = V_27 -> V_31 - V_23 ;
V_29 = V_27 -> V_32 - V_24 ;
return F_18 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_23 , V_24 , V_28 , V_29 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_30 ;
F_1 ( V_2 , V_36 ) ;
F_20 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_35 -> V_2 != V_2 )
continue;
V_30 = V_35 -> V_37 -> V_38 ( V_35 ) ;
if ( V_30 )
F_17 ( L_4 , V_30 ) ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_27 ,
struct V_39 * V_40 ,
T_1 V_41 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_26 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 , V_29 ;
int V_30 = - V_47 ;
if ( V_5 -> V_8 > V_9 ) {
F_17 ( L_5 ) ;
return - V_47 ;
}
F_22 ( & V_43 -> V_48 ) ;
if ( V_40 ) {
V_40 -> V_49 = V_5 -> V_49 ;
V_30 = F_23 ( V_43 , V_5 -> V_49 ) ;
if ( V_30 ) {
F_24 ( L_6 ) ;
goto V_50;
}
F_25 ( & V_43 -> V_51 ) ;
F_26 ( & V_40 -> V_6 . V_52 ,
& V_45 -> V_53 ) ;
F_6 ( & V_5 -> V_11 , 1 ) ;
F_27 ( & V_43 -> V_51 ) ;
V_2 -> V_16 -> V_27 = V_27 ;
V_28 = V_27 -> V_31 - V_2 -> V_23 ;
V_29 = V_27 -> V_32 - V_2 -> V_24 ;
V_30 = F_18 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_2 -> V_23 , V_2 -> V_24 ,
V_28 , V_29 ) ;
if ( V_30 ) {
V_2 -> V_16 -> V_27 = V_26 ;
F_25 ( & V_43 -> V_51 ) ;
F_28 ( V_43 , V_5 -> V_49 ) ;
F_29 ( & V_40 -> V_6 . V_52 ) ;
F_6 ( & V_5 -> V_11 , 0 ) ;
F_27 ( & V_43 -> V_51 ) ;
goto V_50;
}
}
V_50:
F_30 ( & V_43 -> V_48 ) ;
return V_30 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_44 * V_54 = V_2 -> V_43 -> V_46 ;
V_54 -> V_2 [ V_5 -> V_49 ] = NULL ;
F_32 ( V_2 ) ;
F_33 ( V_5 ) ;
}
struct V_4 * F_34 ( struct V_42 * V_55 ,
int V_49 ,
enum V_56 type ,
struct V_57 * V_13 ,
void * V_58 )
{
struct V_4 * V_5 ;
struct V_34 * V_35 ;
struct V_44 * V_54 = V_55 -> V_46 ;
struct V_1 * V_2 ;
int V_30 ;
V_5 = F_35 ( sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 )
return F_36 ( - V_60 ) ;
F_37 ( & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_11 , 0 ) ;
V_5 -> V_8 = V_36 ;
V_5 -> V_49 = V_49 ;
V_5 -> type = type ;
V_5 -> V_13 = V_13 ;
V_5 -> V_58 = V_58 ;
V_35 = F_38 ( V_55 , 1 << V_49 ,
V_61 ) ;
if ( F_39 ( V_35 ) ) {
V_30 = F_40 ( V_35 ) ;
goto V_62;
}
V_2 = & V_5 -> V_6 ;
V_54 -> V_2 [ V_49 ] = V_2 ;
V_30 = F_41 ( V_55 , V_2 , V_35 , NULL ,
& V_63 ) ;
if ( V_30 < 0 )
goto V_64;
F_42 ( V_2 , & V_65 ) ;
return V_5 ;
V_64:
V_35 -> V_37 -> V_66 ( V_35 ) ;
V_62:
F_33 ( V_5 ) ;
return F_36 ( V_30 ) ;
}
int F_43 ( struct V_42 * V_43 , int V_49 )
{
struct V_44 * V_54 = V_43 -> V_46 ;
struct V_4 * V_5 =
F_2 ( V_54 -> V_2 [ V_49 ] ) ;
if ( V_5 -> V_8 != V_9 )
return - V_33 ;
if ( V_5 -> V_13 -> V_67 )
V_5 -> V_13 -> V_67 ( V_5 ) ;
return 0 ;
}
void F_44 ( struct V_42 * V_43 , int V_49 )
{
struct V_44 * V_54 = V_43 -> V_46 ;
struct V_4 * V_5 =
F_2 ( V_54 -> V_2 [ V_49 ] ) ;
if ( V_5 -> V_8 != V_9 )
return;
if ( V_5 -> V_13 -> V_68 )
V_5 -> V_13 -> V_68 ( V_5 ) ;
}
void F_45 ( struct V_42 * V_43 , int V_49 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_39 * V_69 , * V_70 ;
struct V_1 * V_1 = V_45 -> V_2 [ V_49 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_71 ;
F_46 ( & V_43 -> V_51 , V_71 ) ;
F_47 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_49 != V_69 -> V_49 )
continue;
F_29 ( & V_69 -> V_6 . V_52 ) ;
F_48 ( V_43 , - 1 , V_69 ) ;
F_28 ( V_43 , V_49 ) ;
F_6 ( & V_5 -> V_11 , 0 ) ;
F_49 ( & V_5 -> V_10 ) ;
}
F_50 ( & V_43 -> V_51 , V_71 ) ;
}
void F_51 ( struct V_25 * V_27 )
{
struct V_4 * V_5 ;
struct V_42 * V_43 = V_27 -> V_43 ;
struct V_1 * V_2 ;
F_52 (crtc, &dev->mode_config.crtc_list, head) {
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_13 -> V_72 )
V_5 -> V_13 -> V_72 ( V_5 ) ;
}
}
int F_53 ( struct V_42 * V_55 ,
unsigned int V_73 )
{
struct V_1 * V_2 ;
F_52 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> type == V_73 )
return V_5 -> V_49 ;
}
return - V_33 ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_13 -> V_74 )
V_5 -> V_13 -> V_74 ( V_5 ) ;
}
