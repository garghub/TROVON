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
( V_5 -> V_11 == NULL ) , V_12 / 20 ) )
V_5 -> V_11 = NULL ;
F_5 ( V_2 ) ;
}
if ( V_5 -> V_13 -> V_8 )
V_5 -> V_13 -> V_8 ( V_5 , V_3 ) ;
V_5 -> V_8 = V_3 ;
if ( V_3 == V_9 )
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_9 ( V_2 -> V_16 ) ;
F_1 ( V_2 , V_9 ) ;
if ( V_5 -> V_13 -> V_17 )
V_5 -> V_13 -> V_17 ( V_5 , V_15 -> V_18 ) ;
if ( V_5 -> V_13 -> V_19 )
V_5 -> V_13 -> V_19 ( V_5 ) ;
}
static bool
F_10 ( struct V_1 * V_2 ,
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
F_11 ( struct V_1 * V_2 , struct V_20 * V_3 ,
struct V_20 * V_21 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_25 * V_27 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
memcpy ( & V_2 -> V_3 , V_21 , sizeof( * V_21 ) ) ;
V_30 = F_12 ( V_2 -> V_16 , V_27 ) ;
if ( V_30 < 0 )
return V_30 ;
V_28 = V_27 -> V_31 - V_23 ;
V_29 = V_27 -> V_32 - V_24 ;
F_13 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_23 , V_24 , V_28 , V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
if ( V_5 -> V_8 > V_9 ) {
F_15 ( L_3 ) ;
return - V_33 ;
}
V_28 = V_27 -> V_31 - V_23 ;
V_29 = V_27 -> V_32 - V_24 ;
return F_16 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_23 , V_24 , V_28 , V_29 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_30 ;
F_1 ( V_2 , V_36 ) ;
F_18 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_35 -> V_2 != V_2 )
continue;
V_30 = V_35 -> V_37 -> V_38 ( V_35 ) ;
if ( V_30 )
F_15 ( L_4 , V_30 ) ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_27 ,
struct V_39 * V_11 ,
T_1 V_40 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_26 = V_2 -> V_16 -> V_27 ;
unsigned int V_28 , V_29 ;
int V_30 ;
if ( V_5 -> V_8 > V_9 ) {
F_15 ( L_5 ) ;
return - V_43 ;
}
if ( ! V_11 )
return - V_43 ;
F_20 ( & V_42 -> V_44 ) ;
if ( V_5 -> V_11 ) {
V_30 = - V_45 ;
goto V_46;
}
V_30 = F_21 ( V_42 , V_5 -> V_47 ) ;
if ( V_30 ) {
F_22 ( L_6 ) ;
goto V_46;
}
V_5 -> V_11 = V_11 ;
F_23 ( & V_42 -> V_44 ) ;
V_11 -> V_47 = V_5 -> V_47 ;
V_2 -> V_16 -> V_27 = V_27 ;
V_28 = V_27 -> V_31 - V_2 -> V_23 ;
V_29 = V_27 -> V_32 - V_2 -> V_24 ;
V_30 = F_16 ( V_2 -> V_16 , V_2 , V_27 , 0 , 0 ,
V_28 , V_29 , V_2 -> V_23 , V_2 -> V_24 ,
V_28 , V_29 ) ;
if ( V_30 ) {
V_2 -> V_16 -> V_27 = V_26 ;
F_20 ( & V_42 -> V_44 ) ;
V_5 -> V_11 = NULL ;
F_24 ( V_42 , V_5 -> V_47 ) ;
F_23 ( & V_42 -> V_44 ) ;
return V_30 ;
}
return 0 ;
V_46:
F_23 ( & V_42 -> V_44 ) ;
return V_30 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_48 * V_49 = V_2 -> V_42 -> V_50 ;
V_49 -> V_2 [ V_5 -> V_47 ] = NULL ;
F_26 ( V_2 ) ;
F_27 ( V_5 ) ;
}
struct V_4 * F_28 ( struct V_41 * V_51 ,
struct V_34 * V_35 ,
int V_47 ,
enum V_52 type ,
const struct V_53 * V_13 ,
void * V_54 )
{
struct V_4 * V_5 ;
struct V_48 * V_49 = V_51 -> V_50 ;
struct V_1 * V_2 ;
int V_30 ;
V_5 = F_29 ( sizeof( * V_5 ) , V_55 ) ;
if ( ! V_5 )
return F_30 ( - V_56 ) ;
F_31 ( & V_5 -> V_10 ) ;
V_5 -> V_8 = V_36 ;
V_5 -> V_47 = V_47 ;
V_5 -> type = type ;
V_5 -> V_13 = V_13 ;
V_5 -> V_54 = V_54 ;
V_2 = & V_5 -> V_6 ;
V_49 -> V_2 [ V_47 ] = V_2 ;
V_30 = F_32 ( V_51 , V_2 , V_35 , NULL ,
& V_57 ) ;
if ( V_30 < 0 )
goto V_58;
F_33 ( V_2 , & V_59 ) ;
return V_5 ;
V_58:
V_35 -> V_37 -> V_60 ( V_35 ) ;
F_27 ( V_5 ) ;
return F_30 ( V_30 ) ;
}
int F_34 ( struct V_41 * V_42 , int V_47 )
{
struct V_48 * V_49 = V_42 -> V_50 ;
struct V_4 * V_5 =
F_2 ( V_49 -> V_2 [ V_47 ] ) ;
if ( V_5 -> V_8 != V_9 )
return - V_33 ;
if ( V_5 -> V_13 -> V_61 )
V_5 -> V_13 -> V_61 ( V_5 ) ;
return 0 ;
}
void F_35 ( struct V_41 * V_42 , int V_47 )
{
struct V_48 * V_49 = V_42 -> V_50 ;
struct V_4 * V_5 =
F_2 ( V_49 -> V_2 [ V_47 ] ) ;
if ( V_5 -> V_8 != V_9 )
return;
if ( V_5 -> V_13 -> V_62 )
V_5 -> V_13 -> V_62 ( V_5 ) ;
}
void F_36 ( struct V_41 * V_42 , int V_47 )
{
struct V_48 * V_63 = V_42 -> V_50 ;
struct V_1 * V_1 = V_63 -> V_2 [ V_47 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_64 ;
F_37 ( & V_42 -> V_44 , V_64 ) ;
if ( V_5 -> V_11 ) {
F_38 ( V_42 , - 1 , V_5 -> V_11 ) ;
F_24 ( V_42 , V_47 ) ;
F_39 ( & V_5 -> V_10 ) ;
}
V_5 -> V_11 = NULL ;
F_40 ( & V_42 -> V_44 , V_64 ) ;
}
void F_41 ( struct V_25 * V_27 )
{
struct V_4 * V_5 ;
struct V_41 * V_42 = V_27 -> V_42 ;
struct V_1 * V_2 ;
F_42 (crtc, &dev->mode_config.crtc_list, head) {
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_13 -> V_65 )
V_5 -> V_13 -> V_65 ( V_5 ) ;
}
}
int F_43 ( struct V_41 * V_51 ,
unsigned int V_66 )
{
struct V_1 * V_2 ;
F_42 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 -> type == V_66 )
return V_5 -> V_47 ;
}
return - V_33 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_13 -> V_67 )
V_5 -> V_13 -> V_67 ( V_5 ) ;
}
