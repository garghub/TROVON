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
T_1 V_14 , int V_15 , int V_16 )
{
struct V_4 * V_5 = V_12 -> V_17 -> V_6 ;
struct V_8 * V_18 ;
struct V_19 * V_20 ;
F_12 ( & V_5 -> V_21 ) ;
F_10 (imx_crtc, &imxdrm->crtc_list, list)
if ( V_18 -> V_12 == V_12 )
goto V_22;
F_13 ( & V_5 -> V_21 ) ;
return - V_3 ;
V_22:
F_13 ( & V_5 -> V_21 ) ;
V_20 = & V_18 -> V_23 ;
if ( V_20 -> V_24 )
return V_20 -> V_24 ( V_12 ,
V_13 , V_14 ,
V_15 , V_16 ) ;
return 0 ;
}
int F_14 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 )
{
return F_11 ( V_12 , V_13 ,
V_14 , 2 , 3 ) ;
}
int F_15 ( struct V_8 * V_8 )
{
return F_16 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
void F_17 ( struct V_8 * V_8 )
{
F_18 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
void F_19 ( struct V_8 * V_8 )
{
F_20 ( V_8 -> V_5 -> V_2 , V_8 -> V_10 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 ;
int V_25 ;
V_8 = F_9 ( V_5 , V_12 ) ;
if ( ! V_8 )
return - V_3 ;
if ( ! V_8 -> V_23 . V_26 )
return - V_27 ;
V_25 = V_8 -> V_23 . V_26 (
V_8 -> V_12 ) ;
return V_25 ;
}
static void F_22 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_8 * V_8 ;
V_8 = F_9 ( V_5 , V_12 ) ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_23 . V_28 )
return;
V_8 -> V_23 . V_28 ( V_8 -> V_12 ) ;
}
static struct V_4 * F_23 ( void )
{
return V_4 ;
}
struct V_1 * F_2 ( void )
{
struct V_4 * V_5 = F_23 () ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_8 * V_12 ;
F_12 ( & V_5 -> V_21 ) ;
F_10 (enc, &imxdrm->encoder_list, list) {
if ( ! F_24 ( V_30 -> V_33 ) ) {
F_25 ( V_5 -> V_17 , L_1 ,
F_26 ( V_30 -> V_33 ) ) ;
goto V_34;
}
}
F_10 (con, &imxdrm->connector_list, list) {
if ( ! F_24 ( V_32 -> V_33 ) ) {
F_25 ( V_5 -> V_17 , L_1 ,
F_26 ( V_32 -> V_33 ) ) ;
goto V_35;
}
}
F_10 (crtc, &imxdrm->crtc_list, list) {
if ( ! F_24 ( V_12 -> V_33 ) ) {
F_25 ( V_5 -> V_17 , L_1 ,
F_26 ( V_12 -> V_33 ) ) ;
goto V_36;
}
}
V_5 -> V_37 ++ ;
F_13 ( & V_5 -> V_21 ) ;
return V_5 -> V_2 ;
V_36:
F_27 (crtc, &imxdrm->crtc_list, list)
F_28 ( V_12 -> V_33 ) ;
V_35:
F_27 (con, &imxdrm->connector_list, list)
F_28 ( V_32 -> V_33 ) ;
V_34:
F_27 (enc, &imxdrm->encoder_list, list)
F_28 ( V_30 -> V_33 ) ;
F_13 ( & V_5 -> V_21 ) ;
return NULL ;
}
void F_5 ( void )
{
struct V_4 * V_5 = F_23 () ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_8 * V_12 ;
F_12 ( & V_5 -> V_21 ) ;
F_10 (crtc, &imxdrm->crtc_list, list)
F_28 ( V_12 -> V_33 ) ;
F_10 (con, &imxdrm->connector_list, list)
F_28 ( V_32 -> V_33 ) ;
F_10 (enc, &imxdrm->encoder_list, list)
F_28 ( V_30 -> V_33 ) ;
V_5 -> V_37 -- ;
F_13 ( & V_5 -> V_21 ) ;
}
static int F_29 ( struct V_1 * V_17 )
{
struct V_38 * V_39 = & V_17 -> V_40 -> V_41 ;
T_2 * V_42 = V_39 -> V_42 ;
int V_25 ;
V_25 = F_30 ( V_17 , V_39 ) ;
if ( V_25 < 0 )
return V_25 ;
F_31 ( V_42 ) ;
return 0 ;
}
static int F_32 ( struct V_29 * V_29 )
{
struct V_4 * V_5 = F_23 () ;
F_33 ( & V_29 -> V_43 ) ;
F_34 ( V_5 -> V_2 , V_29 -> V_44 ,
V_29 -> V_44 -> V_45 ,
V_29 -> V_44 -> V_13 ) ;
F_29 ( V_5 -> V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_29
* V_29 )
{
struct V_4 * V_5 = F_23 () ;
F_36 ( V_29 -> V_44 ) ;
F_29 ( V_5 -> V_2 ) ;
}
static int F_37 (
struct V_31 * V_31 )
{
struct V_4 * V_5 = F_23 () ;
F_38 ( V_5 -> V_2 , V_31 -> V_46 ,
V_31 -> V_46 -> V_45 ,
V_31 -> V_46 -> V_47 ) ;
F_29 ( V_5 -> V_2 ) ;
return F_39 ( V_31 -> V_46 ) ;
}
static void F_40 (
struct V_31 * V_31 )
{
struct V_4 * V_5 = F_23 () ;
F_41 ( V_31 -> V_46 ) ;
F_42 ( V_31 -> V_46 ) ;
F_29 ( V_5 -> V_2 ) ;
}
static int F_43 ( struct V_8 * V_8 )
{
struct V_4 * V_5 = F_23 () ;
int V_25 ;
F_44 ( V_5 -> V_2 , V_8 -> V_12 ,
V_8 -> V_23 . V_48 ) ;
V_25 = F_45 ( V_8 -> V_12 , 256 ) ;
if ( V_25 )
return V_25 ;
F_46 ( V_8 -> V_12 ,
V_8 -> V_23 . V_49 ) ;
F_29 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , unsigned long V_50 )
{
struct V_4 * V_5 = F_23 () ;
int V_25 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_51 = 1 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_12 ( & V_5 -> V_21 ) ;
F_50 ( V_5 -> V_2 ) ;
V_25 = F_30 ( V_5 -> V_2 ,
& V_5 -> V_2 -> V_40 -> V_41 ) ;
if ( V_25 )
goto V_52;
V_25 = F_51 ( V_5 -> V_2 , V_53 ) ;
if ( V_25 )
goto V_52;
V_5 -> V_2 -> V_54 = 1 ;
V_25 = 0 ;
V_52:
F_13 ( & V_5 -> V_21 ) ;
return V_25 ;
}
static void F_52 ( void )
{
struct V_4 * V_5 = F_23 () ;
struct V_8 * V_8 ;
struct V_29 * V_30 ;
struct V_55 * V_56 ;
F_10 (enc, &imxdrm->encoder_list, list) {
T_1 V_43 = 0 ;
F_10 (cookie, &enc->possible_crtcs, list) {
F_10 (imx_drm_crtc, &imxdrm->crtc_list, list) {
if ( V_8 -> V_56 . V_56 == V_56 -> V_56 &&
V_8 -> V_56 . V_57 == V_56 -> V_57 ) {
V_43 |= 1 << V_8 -> V_10 ;
}
}
}
V_30 -> V_44 -> V_43 = V_43 ;
V_30 -> V_44 -> V_58 = V_43 ;
}
}
int F_53 ( struct V_11 * V_12 ,
struct V_8 * * V_59 ,
const struct V_19 * V_23 ,
struct V_60 * V_33 , void * V_56 , int V_57 )
{
struct V_4 * V_5 = F_23 () ;
struct V_8 * V_8 ;
int V_25 ;
F_12 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_37 ) {
V_25 = - V_61 ;
goto V_62;
}
V_8 = F_54 ( sizeof( * V_8 ) , V_63 ) ;
if ( ! V_8 ) {
V_25 = - V_64 ;
goto V_65;
}
V_8 -> V_23 = * V_23 ;
V_8 -> V_10 = V_5 -> V_66 ++ ;
V_8 -> V_56 . V_56 = V_56 ;
V_8 -> V_56 . V_57 = V_57 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_33 = V_33 ;
F_55 ( & V_8 -> V_67 , & V_5 -> V_68 ) ;
* V_59 = V_8 ;
V_25 = F_43 ( V_8 ) ;
if ( V_25 )
goto V_69;
F_52 () ;
F_13 ( & V_5 -> V_21 ) ;
return 0 ;
V_69:
F_31 ( V_8 ) ;
V_65:
V_62:
F_13 ( & V_5 -> V_21 ) ;
return V_25 ;
}
int F_56 ( struct V_8 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
F_12 ( & V_5 -> V_21 ) ;
F_57 ( V_8 -> V_12 ) ;
F_58 ( & V_8 -> V_67 ) ;
F_29 ( V_5 -> V_2 ) ;
F_13 ( & V_5 -> V_21 ) ;
F_31 ( V_8 ) ;
return 0 ;
}
int F_59 ( struct V_70 * V_44 ,
struct V_29 * * V_71 , struct V_60 * V_33 )
{
struct V_4 * V_5 = F_23 () ;
struct V_29 * V_29 ;
int V_25 ;
F_12 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_37 ) {
V_25 = - V_61 ;
goto V_62;
}
V_29 = F_54 ( sizeof( * V_29 ) , V_63 ) ;
if ( ! V_29 ) {
V_25 = - V_64 ;
goto V_65;
}
V_29 -> V_44 = V_44 ;
V_29 -> V_33 = V_33 ;
V_25 = F_32 ( V_29 ) ;
if ( V_25 ) {
V_25 = - V_64 ;
goto V_69;
}
F_55 ( & V_29 -> V_67 , & V_5 -> V_72 ) ;
* V_71 = V_29 ;
F_13 ( & V_5 -> V_21 ) ;
return 0 ;
V_69:
F_31 ( V_29 ) ;
V_65:
V_62:
F_13 ( & V_5 -> V_21 ) ;
return V_25 ;
}
int F_60 (
struct V_29 * V_29 ,
struct V_73 * V_74 )
{
struct V_4 * V_5 = F_23 () ;
struct V_75 args ;
struct V_55 * V_76 ;
int V_25 = 0 ;
int V_77 ;
if ( ! F_61 ( & V_29 -> V_43 ) )
return - V_61 ;
for ( V_77 = 0 ; ! V_25 ; V_77 ++ ) {
V_25 = F_62 ( V_74 , L_2 ,
L_3 , V_77 , & args ) ;
if ( V_25 < 0 )
break;
V_76 = F_54 ( sizeof( * V_76 ) , V_63 ) ;
if ( ! V_76 ) {
F_63 ( args . V_74 ) ;
return - V_64 ;
}
V_76 -> V_56 = args . V_74 ;
V_76 -> V_57 = args . V_78 > 0 ? args . args [ 0 ] : 0 ;
F_63 ( args . V_74 ) ;
F_12 ( & V_5 -> V_21 ) ;
F_55 ( & V_76 -> V_67 , & V_29 -> V_43 ) ;
F_13 ( & V_5 -> V_21 ) ;
}
F_52 () ;
return 0 ;
}
int F_64 ( struct V_29 * V_29 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = F_23 () ;
struct V_8 * V_18 ;
int V_77 = 0 ;
F_12 ( & V_5 -> V_21 ) ;
F_10 (imx_crtc, &imxdrm->crtc_list, list) {
if ( V_18 -> V_12 == V_12 )
goto V_22;
V_77 ++ ;
}
F_13 ( & V_5 -> V_21 ) ;
return - V_3 ;
V_22:
F_13 ( & V_5 -> V_21 ) ;
return V_77 ;
}
int F_65 ( struct V_29 * V_29 )
{
struct V_4 * V_5 = F_23 () ;
struct V_55 * V_76 , * V_79 ;
F_12 ( & V_5 -> V_21 ) ;
F_35 ( V_29 ) ;
F_58 ( & V_29 -> V_67 ) ;
F_66 (c, tmp, &imx_drm_encoder->possible_crtcs,
list)
F_31 ( V_76 ) ;
F_13 ( & V_5 -> V_21 ) ;
F_31 ( V_29 ) ;
return 0 ;
}
int F_67 ( struct V_80 * V_46 ,
struct V_31 * * V_81 ,
struct V_60 * V_33 )
{
struct V_4 * V_5 = F_23 () ;
struct V_31 * V_31 ;
int V_25 ;
F_12 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_37 ) {
V_25 = - V_61 ;
goto V_62;
}
V_31 = F_54 ( sizeof( * V_31 ) , V_63 ) ;
if ( ! V_31 ) {
V_25 = - V_64 ;
goto V_65;
}
V_31 -> V_46 = V_46 ;
V_31 -> V_33 = V_33 ;
V_25 = F_37 ( V_31 ) ;
if ( V_25 )
goto V_69;
F_55 ( & V_31 -> V_67 , & V_5 -> V_82 ) ;
* V_81 = V_31 ;
F_13 ( & V_5 -> V_21 ) ;
return 0 ;
V_69:
F_31 ( V_31 ) ;
V_65:
V_62:
F_13 ( & V_5 -> V_21 ) ;
return V_25 ;
}
void F_68 ( struct V_83 * V_84 )
{
struct V_4 * V_5 = F_23 () ;
V_5 -> V_7 = V_84 ;
}
int F_69 ( struct V_31 * V_31 )
{
struct V_4 * V_5 = F_23 () ;
F_12 ( & V_5 -> V_21 ) ;
F_40 ( V_31 ) ;
F_58 ( & V_31 -> V_67 ) ;
F_13 ( & V_5 -> V_21 ) ;
F_31 ( V_31 ) ;
return 0 ;
}
static int F_70 ( struct V_85 * V_86 )
{
V_4 -> V_17 = & V_86 -> V_17 ;
return F_71 ( & V_87 , V_86 ) ;
}
static int F_72 ( struct V_85 * V_86 )
{
F_73 ( & V_87 , V_86 ) ;
return 0 ;
}
static int T_3 F_74 ( void )
{
int V_25 ;
V_4 = F_54 ( sizeof( * V_4 ) , V_63 ) ;
if ( ! V_4 )
return - V_64 ;
F_75 ( & V_4 -> V_21 ) ;
F_33 ( & V_4 -> V_68 ) ;
F_33 ( & V_4 -> V_82 ) ;
F_33 ( & V_4 -> V_72 ) ;
V_88 = F_76 ( L_4 , - 1 , NULL , 0 ) ;
if ( ! V_88 ) {
V_25 = - V_3 ;
goto V_89;
}
V_88 -> V_17 . V_90 = F_77 ( 32 ) ,
V_25 = F_78 ( & V_91 ) ;
if ( V_25 )
goto V_92;
return 0 ;
V_92:
F_79 ( V_88 ) ;
V_89:
F_31 ( V_4 ) ;
return V_25 ;
}
static void T_4 F_80 ( void )
{
F_79 ( V_88 ) ;
F_81 ( & V_91 ) ;
F_31 ( V_4 ) ;
}
