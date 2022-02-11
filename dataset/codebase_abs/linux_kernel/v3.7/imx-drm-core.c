static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 () )
return - V_3 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 )
F_4 ( V_5 -> V_7 ) ;
F_5 () ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_7 ( V_5 -> V_2 ) ;
F_8 ( V_5 -> V_2 ) ;
return 0 ;
}
static struct V_8 * F_9 ( struct V_4 * V_5 ,
int V_9 )
{
struct V_8 * V_8 ;
F_10 (imx_drm_crtc, &imxdrm->crtc_list, list)
if ( V_8 -> V_10 == V_9 )
return V_8 ;
return NULL ;
}
int F_11 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 )
{
struct V_4 * V_5 = V_12 -> V_15 -> V_6 ;
struct V_8 * V_16 ;
struct V_17 * V_18 ;
F_12 ( & V_5 -> V_19 ) ;
F_10 (imx_crtc, &imxdrm->crtc_list, list)
if ( V_16 -> V_12 == V_12 )
goto V_20;
F_13 ( & V_5 -> V_19 ) ;
return - V_3 ;
V_20:
F_13 ( & V_5 -> V_19 ) ;
V_18 = & V_16 -> V_21 ;
if ( V_18 -> V_22 )
return V_18 -> V_22 ( V_12 ,
V_13 , V_14 ) ;
return 0 ;
}
int F_14 ( struct V_8 * V_8 )
{
return F_15 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
void F_16 ( struct V_8 * V_8 )
{
F_17 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
void F_18 ( struct V_8 * V_8 )
{
F_19 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 ;
int V_23 ;
V_8 = F_9 ( V_5 , V_12 ) ;
if ( ! V_8 )
return - V_3 ;
if ( ! V_8 -> V_21 . V_24 )
return - V_25 ;
V_23 = V_8 -> V_21 . V_24 (
V_8 -> V_12 ) ;
return V_23 ;
}
static void F_21 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 ;
V_8 = F_9 ( V_5 , V_12 ) ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_21 . V_26 )
return;
V_8 -> V_21 . V_26 ( V_8 -> V_12 ) ;
}
static struct V_4 * F_22 ( void )
{
return V_4 ;
}
struct V_1 * F_2 ( void )
{
struct V_4 * V_5 = F_22 () ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_8 * V_12 ;
F_12 ( & V_5 -> V_19 ) ;
F_10 (enc, &imxdrm->encoder_list, list) {
if ( ! F_23 ( V_28 -> V_31 ) ) {
F_24 ( V_5 -> V_15 , L_1 ,
F_25 ( V_28 -> V_31 ) ) ;
goto V_32;
}
}
F_10 (con, &imxdrm->connector_list, list) {
if ( ! F_23 ( V_30 -> V_31 ) ) {
F_24 ( V_5 -> V_15 , L_1 ,
F_25 ( V_30 -> V_31 ) ) ;
goto V_33;
}
}
F_10 (crtc, &imxdrm->crtc_list, list) {
if ( ! F_23 ( V_12 -> V_31 ) ) {
F_24 ( V_5 -> V_15 , L_1 ,
F_25 ( V_12 -> V_31 ) ) ;
goto V_34;
}
}
V_5 -> V_35 ++ ;
F_13 ( & V_5 -> V_19 ) ;
return V_5 -> V_2 ;
V_34:
F_26 (crtc, &imxdrm->crtc_list, list)
F_27 ( V_12 -> V_31 ) ;
V_33:
F_26 (con, &imxdrm->connector_list, list)
F_27 ( V_30 -> V_31 ) ;
V_32:
F_26 (enc, &imxdrm->encoder_list, list)
F_27 ( V_28 -> V_31 ) ;
F_13 ( & V_5 -> V_19 ) ;
return NULL ;
}
void F_5 ( void )
{
struct V_4 * V_5 = F_22 () ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_8 * V_12 ;
F_12 ( & V_5 -> V_19 ) ;
F_10 (crtc, &imxdrm->crtc_list, list)
F_27 ( V_12 -> V_31 ) ;
F_10 (con, &imxdrm->connector_list, list)
F_27 ( V_30 -> V_31 ) ;
F_10 (enc, &imxdrm->encoder_list, list)
F_27 ( V_28 -> V_31 ) ;
V_5 -> V_35 -- ;
F_13 ( & V_5 -> V_19 ) ;
}
static int F_28 ( struct V_1 * V_15 )
{
struct V_36 * V_37 = & V_15 -> V_38 -> V_39 ;
T_2 * V_40 = V_37 -> V_40 ;
int V_23 ;
V_23 = F_29 ( V_15 , V_37 ) ;
if ( V_23 < 0 )
return V_23 ;
F_30 ( V_40 ) ;
return 0 ;
}
static int F_31 ( struct V_27 * V_27 )
{
struct V_4 * V_5 = F_22 () ;
F_32 ( & V_27 -> V_41 ) ;
F_33 ( V_5 -> V_2 , V_27 -> V_42 ,
V_27 -> V_42 -> V_43 ,
V_27 -> V_42 -> V_13 ) ;
F_28 ( V_5 -> V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_27
* V_27 )
{
struct V_4 * V_5 = F_22 () ;
F_35 ( V_27 -> V_42 ) ;
F_28 ( V_5 -> V_2 ) ;
}
static int F_36 (
struct V_29 * V_29 )
{
struct V_4 * V_5 = F_22 () ;
F_37 ( V_5 -> V_2 , V_29 -> V_44 ,
V_29 -> V_44 -> V_43 ,
V_29 -> V_44 -> V_45 ) ;
F_28 ( V_5 -> V_2 ) ;
return F_38 ( V_29 -> V_44 ) ;
}
static void F_39 (
struct V_29 * V_29 )
{
struct V_4 * V_5 = F_22 () ;
F_40 ( V_29 -> V_44 ) ;
F_41 ( V_29 -> V_44 ) ;
F_28 ( V_5 -> V_2 ) ;
}
static int F_42 ( struct V_8 * V_8 )
{
struct V_4 * V_5 = F_22 () ;
int V_23 ;
F_43 ( V_5 -> V_2 , V_8 -> V_12 ,
V_8 -> V_21 . V_46 ) ;
V_23 = F_44 ( V_8 -> V_12 , 256 ) ;
if ( V_23 )
return V_23 ;
F_45 ( V_8 -> V_12 ,
V_8 -> V_21 . V_47 ) ;
F_28 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned long V_48 )
{
struct V_4 * V_5 = F_22 () ;
int V_23 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_49 = 1 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_12 ( & V_5 -> V_19 ) ;
F_49 ( V_5 -> V_2 ) ;
V_23 = F_29 ( V_5 -> V_2 ,
& V_5 -> V_2 -> V_38 -> V_39 ) ;
if ( V_23 )
goto V_50;
V_23 = F_50 ( V_5 -> V_2 , V_51 ) ;
if ( V_23 )
goto V_50;
V_5 -> V_2 -> V_52 = 1 ;
V_23 = 0 ;
V_50:
F_13 ( & V_5 -> V_19 ) ;
return V_23 ;
}
static void F_51 ( void )
{
struct V_4 * V_5 = F_22 () ;
struct V_8 * V_8 ;
struct V_27 * V_28 ;
struct V_53 * V_54 ;
F_10 (enc, &imxdrm->encoder_list, list) {
T_1 V_41 = 0 ;
F_10 (cookie, &enc->possible_crtcs, list) {
F_10 (imx_drm_crtc, &imxdrm->crtc_list, list) {
if ( V_8 -> V_54 . V_54 == V_54 -> V_54 &&
V_8 -> V_54 . V_55 == V_54 -> V_55 ) {
V_41 |= 1 << V_8 -> V_10 ;
}
}
}
V_28 -> V_42 -> V_41 = V_41 ;
V_28 -> V_42 -> V_56 = V_41 ;
}
}
int F_52 ( struct V_11 * V_12 ,
struct V_8 * * V_57 ,
const struct V_17 * V_21 ,
struct V_58 * V_31 , void * V_54 , int V_55 )
{
struct V_4 * V_5 = F_22 () ;
struct V_8 * V_8 ;
const struct V_59 * V_46 ;
int V_23 ;
F_12 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_35 ) {
V_23 = - V_60 ;
goto V_61;
}
V_8 = F_53 ( sizeof( * V_8 ) , V_62 ) ;
if ( ! V_8 ) {
V_23 = - V_63 ;
goto V_64;
}
V_8 -> V_21 = * V_21 ;
V_8 -> V_10 = V_5 -> V_65 ++ ;
V_8 -> V_54 . V_54 = V_54 ;
V_8 -> V_54 . V_55 = V_55 ;
V_46 = V_21 -> V_46 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_31 = V_31 ;
F_54 ( & V_8 -> V_66 , & V_5 -> V_67 ) ;
* V_57 = V_8 ;
V_23 = F_42 ( V_8 ) ;
if ( V_23 )
goto V_68;
F_51 () ;
F_13 ( & V_5 -> V_19 ) ;
return 0 ;
V_68:
F_30 ( V_8 ) ;
V_64:
V_61:
F_13 ( & V_5 -> V_19 ) ;
return V_23 ;
}
int F_55 ( struct V_8 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
F_12 ( & V_5 -> V_19 ) ;
F_56 ( V_8 -> V_12 ) ;
F_57 ( & V_8 -> V_66 ) ;
F_28 ( V_5 -> V_2 ) ;
F_13 ( & V_5 -> V_19 ) ;
F_30 ( V_8 ) ;
return 0 ;
}
int F_58 ( struct V_69 * V_42 ,
struct V_27 * * V_70 , struct V_58 * V_31 )
{
struct V_4 * V_5 = F_22 () ;
struct V_27 * V_27 ;
int V_23 ;
F_12 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_35 ) {
V_23 = - V_60 ;
goto V_61;
}
V_27 = F_53 ( sizeof( * V_27 ) , V_62 ) ;
if ( ! V_27 ) {
V_23 = - V_63 ;
goto V_64;
}
V_27 -> V_42 = V_42 ;
V_27 -> V_31 = V_31 ;
V_23 = F_31 ( V_27 ) ;
if ( V_23 ) {
F_30 ( V_27 ) ;
V_23 = - V_63 ;
goto V_68;
}
F_54 ( & V_27 -> V_66 , & V_5 -> V_71 ) ;
* V_70 = V_27 ;
F_13 ( & V_5 -> V_19 ) ;
return 0 ;
V_68:
F_30 ( V_27 ) ;
V_64:
V_61:
F_13 ( & V_5 -> V_19 ) ;
return V_23 ;
}
int F_59 (
struct V_27 * V_27 ,
struct V_72 * V_73 )
{
struct V_4 * V_5 = F_22 () ;
struct V_74 args ;
struct V_53 * V_75 ;
int V_23 = 0 ;
int V_76 ;
if ( ! F_60 ( & V_27 -> V_41 ) )
return - V_60 ;
for ( V_76 = 0 ; ! V_23 ; V_76 ++ ) {
V_23 = F_61 ( V_73 , L_2 ,
L_3 , V_76 , & args ) ;
if ( V_23 < 0 )
break;
V_75 = F_53 ( sizeof( * V_75 ) , V_62 ) ;
if ( ! V_75 ) {
F_62 ( args . V_73 ) ;
return - V_63 ;
}
V_75 -> V_54 = args . V_73 ;
V_75 -> V_55 = args . V_77 > 0 ? args . args [ 0 ] : 0 ;
F_62 ( args . V_73 ) ;
F_12 ( & V_5 -> V_19 ) ;
F_54 ( & V_75 -> V_66 , & V_27 -> V_41 ) ;
F_13 ( & V_5 -> V_19 ) ;
}
F_51 () ;
return 0 ;
}
int F_63 ( struct V_27 * V_27 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = F_22 () ;
struct V_8 * V_16 ;
int V_76 = 0 ;
F_12 ( & V_5 -> V_19 ) ;
F_10 (imx_crtc, &imxdrm->crtc_list, list) {
if ( V_16 -> V_12 == V_12 )
goto V_20;
V_76 ++ ;
}
F_13 ( & V_5 -> V_19 ) ;
return - V_3 ;
V_20:
F_13 ( & V_5 -> V_19 ) ;
return V_76 ;
}
int F_64 ( struct V_27 * V_27 )
{
struct V_4 * V_5 = F_22 () ;
struct V_53 * V_75 , * V_78 ;
F_12 ( & V_5 -> V_19 ) ;
F_34 ( V_27 ) ;
F_57 ( & V_27 -> V_66 ) ;
F_65 (c, tmp, &imx_drm_encoder->possible_crtcs,
list)
F_30 ( V_75 ) ;
F_13 ( & V_5 -> V_19 ) ;
F_30 ( V_27 ) ;
return 0 ;
}
int F_66 ( struct V_79 * V_44 ,
struct V_29 * * V_80 ,
struct V_58 * V_31 )
{
struct V_4 * V_5 = F_22 () ;
struct V_29 * V_29 ;
int V_23 ;
F_12 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_35 ) {
V_23 = - V_60 ;
goto V_61;
}
V_29 = F_53 ( sizeof( * V_29 ) , V_62 ) ;
if ( ! V_29 ) {
V_23 = - V_63 ;
goto V_64;
}
V_29 -> V_44 = V_44 ;
V_29 -> V_31 = V_31 ;
V_23 = F_36 ( V_29 ) ;
if ( V_23 )
goto V_68;
F_54 ( & V_29 -> V_66 , & V_5 -> V_81 ) ;
* V_80 = V_29 ;
F_13 ( & V_5 -> V_19 ) ;
return 0 ;
V_68:
F_30 ( V_29 ) ;
V_64:
V_61:
F_13 ( & V_5 -> V_19 ) ;
return V_23 ;
}
void F_67 ( struct V_82 * V_83 )
{
struct V_4 * V_5 = F_22 () ;
V_5 -> V_7 = V_83 ;
}
int F_68 ( struct V_29 * V_29 )
{
struct V_4 * V_5 = F_22 () ;
F_12 ( & V_5 -> V_19 ) ;
F_39 ( V_29 ) ;
F_57 ( & V_29 -> V_66 ) ;
F_13 ( & V_5 -> V_19 ) ;
F_30 ( V_29 ) ;
return 0 ;
}
static int F_69 ( struct V_84 * V_85 )
{
V_4 -> V_15 = & V_85 -> V_15 ;
return F_70 ( & V_86 , V_85 ) ;
}
static int F_71 ( struct V_84 * V_85 )
{
F_72 ( & V_86 , V_85 ) ;
return 0 ;
}
static int T_3 F_73 ( void )
{
int V_23 ;
V_4 = F_53 ( sizeof( * V_4 ) , V_62 ) ;
if ( ! V_4 )
return - V_63 ;
F_74 ( & V_4 -> V_19 ) ;
F_32 ( & V_4 -> V_67 ) ;
F_32 ( & V_4 -> V_81 ) ;
F_32 ( & V_4 -> V_71 ) ;
V_87 = F_75 ( L_4 , - 1 , NULL , 0 ) ;
if ( ! V_87 ) {
V_23 = - V_3 ;
goto V_88;
}
V_87 -> V_15 . V_89 = F_76 ( 32 ) ,
V_23 = F_77 ( & V_90 ) ;
if ( V_23 )
goto V_91;
return 0 ;
V_91:
F_78 ( V_87 ) ;
V_88:
F_30 ( V_4 ) ;
return V_23 ;
}
static void T_4 F_79 ( void )
{
F_78 ( V_87 ) ;
F_80 ( & V_90 ) ;
F_30 ( V_4 ) ;
}
