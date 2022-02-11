static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 () ;
F_5 ( V_4 -> V_2 ) ;
F_6 ( V_4 -> V_2 ) ;
return 0 ;
}
static struct V_7 * F_7 ( struct V_3 * V_4 ,
int V_8 )
{
struct V_7 * V_7 ;
F_8 (imx_drm_crtc, &imxdrm->crtc_list, list)
if ( V_7 -> V_9 == V_8 )
return V_7 ;
return NULL ;
}
int F_9 ( struct V_10 * V_11 , T_1 V_12 ,
T_1 V_13 , int V_14 , int V_15 )
{
struct V_3 * V_4 = V_11 -> V_16 -> V_5 ;
struct V_7 * V_17 ;
struct V_18 * V_19 ;
F_10 ( & V_4 -> V_20 ) ;
F_8 (imx_crtc, &imxdrm->crtc_list, list)
if ( V_17 -> V_11 == V_11 )
goto V_21;
F_11 ( & V_4 -> V_20 ) ;
return - V_22 ;
V_21:
F_11 ( & V_4 -> V_20 ) ;
V_19 = & V_17 -> V_23 ;
if ( V_19 -> V_24 )
return V_19 -> V_24 ( V_11 ,
V_12 , V_13 ,
V_14 , V_15 ) ;
return 0 ;
}
int F_12 ( struct V_10 * V_11 , T_1 V_12 ,
T_1 V_13 )
{
return F_9 ( V_11 , V_12 ,
V_13 , 2 , 3 ) ;
}
int F_13 ( struct V_7 * V_7 )
{
return F_14 ( V_7 -> V_4 -> V_2 , V_7 -> V_9 ) ;
}
void F_15 ( struct V_7 * V_7 )
{
F_16 ( V_7 -> V_4 -> V_2 , V_7 -> V_9 ) ;
}
void F_17 ( struct V_7 * V_7 )
{
F_18 ( V_7 -> V_4 -> V_2 , V_7 -> V_9 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_7 ;
int V_25 ;
V_7 = F_7 ( V_4 , V_11 ) ;
if ( ! V_7 )
return - V_22 ;
if ( ! V_7 -> V_23 . V_26 )
return - V_27 ;
V_25 = V_7 -> V_23 . V_26 (
V_7 -> V_11 ) ;
return V_25 ;
}
static void F_20 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_7 ;
V_7 = F_7 ( V_4 , V_11 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_23 . V_28 )
return;
V_7 -> V_23 . V_28 ( V_7 -> V_11 ) ;
}
static struct V_3 * F_21 ( void )
{
return V_3 ;
}
struct V_1 * F_22 ( void )
{
struct V_3 * V_4 = F_21 () ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_7 * V_11 ;
F_8 (enc, &imxdrm->encoder_list, list) {
if ( ! F_23 ( V_30 -> V_33 ) ) {
F_24 ( V_4 -> V_16 , L_1 ,
F_25 ( V_30 -> V_33 ) ) ;
goto V_34;
}
}
F_8 (con, &imxdrm->connector_list, list) {
if ( ! F_23 ( V_32 -> V_33 ) ) {
F_24 ( V_4 -> V_16 , L_1 ,
F_25 ( V_32 -> V_33 ) ) ;
goto V_35;
}
}
F_8 (crtc, &imxdrm->crtc_list, list) {
if ( ! F_23 ( V_11 -> V_33 ) ) {
F_24 ( V_4 -> V_16 , L_1 ,
F_25 ( V_11 -> V_33 ) ) ;
goto V_36;
}
}
return V_4 -> V_2 ;
V_36:
F_26 (crtc, &imxdrm->crtc_list, list)
F_27 ( V_11 -> V_33 ) ;
V_35:
F_26 (con, &imxdrm->connector_list, list)
F_27 ( V_32 -> V_33 ) ;
V_34:
F_26 (enc, &imxdrm->encoder_list, list)
F_27 ( V_30 -> V_33 ) ;
F_11 ( & V_4 -> V_20 ) ;
return NULL ;
}
void F_4 ( void )
{
struct V_3 * V_4 = F_21 () ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_7 * V_11 ;
F_10 ( & V_4 -> V_20 ) ;
F_8 (crtc, &imxdrm->crtc_list, list)
F_27 ( V_11 -> V_33 ) ;
F_8 (con, &imxdrm->connector_list, list)
F_27 ( V_32 -> V_33 ) ;
F_8 (enc, &imxdrm->encoder_list, list)
F_27 ( V_30 -> V_33 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
static int F_28 ( struct V_1 * V_16 )
{
struct V_37 * V_38 = & V_16 -> V_39 -> V_40 ;
T_2 * V_41 = V_38 -> V_41 ;
int V_25 ;
V_25 = F_29 ( V_16 , V_38 ) ;
if ( V_25 < 0 )
return V_25 ;
F_30 ( V_41 ) ;
return 0 ;
}
static int F_31 ( struct V_29 * V_29 )
{
struct V_3 * V_4 = F_21 () ;
F_32 ( & V_29 -> V_42 ) ;
F_33 ( V_4 -> V_2 , V_29 -> V_43 ,
V_29 -> V_43 -> V_44 ,
V_29 -> V_43 -> V_12 ) ;
F_28 ( V_4 -> V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_29
* V_29 )
{
struct V_3 * V_4 = F_21 () ;
F_35 ( V_29 -> V_43 ) ;
F_28 ( V_4 -> V_2 ) ;
}
static int F_36 (
struct V_31 * V_31 )
{
struct V_3 * V_4 = F_21 () ;
F_37 ( V_4 -> V_2 , V_31 -> V_45 ,
V_31 -> V_45 -> V_44 ,
V_31 -> V_45 -> V_46 ) ;
F_28 ( V_4 -> V_2 ) ;
return F_38 ( V_31 -> V_45 ) ;
}
static void F_39 (
struct V_31 * V_31 )
{
struct V_3 * V_4 = F_21 () ;
F_40 ( V_31 -> V_45 ) ;
F_41 ( V_31 -> V_45 ) ;
F_28 ( V_4 -> V_2 ) ;
}
static int F_42 ( struct V_7 * V_7 )
{
struct V_3 * V_4 = F_21 () ;
int V_25 ;
F_43 ( V_4 -> V_2 , V_7 -> V_11 ,
V_7 -> V_23 . V_47 ) ;
V_25 = F_44 ( V_7 -> V_11 , 256 ) ;
if ( V_25 )
return V_25 ;
F_45 ( V_7 -> V_11 ,
V_7 -> V_23 . V_48 ) ;
F_28 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned long V_49 )
{
struct V_3 * V_4 = F_21 () ;
int V_25 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_50 = 1 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_10 ( & V_4 -> V_20 ) ;
F_49 ( V_4 -> V_2 ) ;
V_25 = F_29 ( V_4 -> V_2 ,
& V_4 -> V_2 -> V_39 -> V_40 ) ;
if ( V_25 )
goto V_51;
V_25 = F_50 ( V_4 -> V_2 , V_52 ) ;
if ( V_25 )
goto V_51;
V_4 -> V_2 -> V_53 = 1 ;
if ( ! F_22 () )
V_25 = - V_22 ;
V_25 = 0 ;
V_51:
F_11 ( & V_4 -> V_20 ) ;
return V_25 ;
}
static void F_51 ( void )
{
struct V_3 * V_4 = F_21 () ;
struct V_7 * V_7 ;
struct V_29 * V_30 ;
struct V_54 * V_55 ;
F_8 (enc, &imxdrm->encoder_list, list) {
T_1 V_42 = 0 ;
F_8 (cookie, &enc->possible_crtcs, list) {
F_8 (imx_drm_crtc, &imxdrm->crtc_list, list) {
if ( V_7 -> V_55 . V_55 == V_55 -> V_55 &&
V_7 -> V_55 . V_56 == V_55 -> V_56 ) {
V_42 |= 1 << V_7 -> V_9 ;
}
}
}
V_30 -> V_43 -> V_42 = V_42 ;
V_30 -> V_43 -> V_57 = V_42 ;
}
}
int F_52 ( struct V_10 * V_11 ,
struct V_7 * * V_58 ,
const struct V_18 * V_23 ,
struct V_59 * V_33 , void * V_55 , int V_56 )
{
struct V_3 * V_4 = F_21 () ;
struct V_7 * V_7 ;
int V_25 ;
F_10 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_2 -> V_60 ) {
V_25 = - V_61 ;
goto V_62;
}
V_7 = F_53 ( sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 ) {
V_25 = - V_64 ;
goto V_65;
}
V_7 -> V_23 = * V_23 ;
V_7 -> V_9 = V_4 -> V_66 ++ ;
V_7 -> V_55 . V_55 = V_55 ;
V_7 -> V_55 . V_56 = V_56 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_33 = V_33 ;
F_54 ( & V_7 -> V_67 , & V_4 -> V_68 ) ;
* V_58 = V_7 ;
V_25 = F_42 ( V_7 ) ;
if ( V_25 )
goto V_69;
F_51 () ;
F_11 ( & V_4 -> V_20 ) ;
return 0 ;
V_69:
F_30 ( V_7 ) ;
V_65:
V_62:
F_11 ( & V_4 -> V_20 ) ;
return V_25 ;
}
int F_55 ( struct V_7 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
F_10 ( & V_4 -> V_20 ) ;
F_56 ( V_7 -> V_11 ) ;
F_57 ( & V_7 -> V_67 ) ;
F_28 ( V_4 -> V_2 ) ;
F_11 ( & V_4 -> V_20 ) ;
F_30 ( V_7 ) ;
return 0 ;
}
int F_58 ( struct V_70 * V_43 ,
struct V_29 * * V_71 , struct V_59 * V_33 )
{
struct V_3 * V_4 = F_21 () ;
struct V_29 * V_29 ;
int V_25 ;
F_10 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_2 -> V_60 ) {
V_25 = - V_61 ;
goto V_62;
}
V_29 = F_53 ( sizeof( * V_29 ) , V_63 ) ;
if ( ! V_29 ) {
V_25 = - V_64 ;
goto V_65;
}
V_29 -> V_43 = V_43 ;
V_29 -> V_33 = V_33 ;
V_25 = F_31 ( V_29 ) ;
if ( V_25 ) {
V_25 = - V_64 ;
goto V_69;
}
F_54 ( & V_29 -> V_67 , & V_4 -> V_72 ) ;
* V_71 = V_29 ;
F_11 ( & V_4 -> V_20 ) ;
return 0 ;
V_69:
F_30 ( V_29 ) ;
V_65:
V_62:
F_11 ( & V_4 -> V_20 ) ;
return V_25 ;
}
int F_59 (
struct V_29 * V_29 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = F_21 () ;
struct V_75 args ;
struct V_54 * V_76 ;
int V_25 = 0 ;
int V_77 ;
if ( ! F_60 ( & V_29 -> V_42 ) )
return - V_61 ;
for ( V_77 = 0 ; ! V_25 ; V_77 ++ ) {
V_25 = F_61 ( V_74 , L_2 ,
L_3 , V_77 , & args ) ;
if ( V_25 < 0 )
break;
V_76 = F_53 ( sizeof( * V_76 ) , V_63 ) ;
if ( ! V_76 ) {
F_62 ( args . V_74 ) ;
return - V_64 ;
}
V_76 -> V_55 = args . V_74 ;
V_76 -> V_56 = args . V_78 > 0 ? args . args [ 0 ] : 0 ;
F_62 ( args . V_74 ) ;
F_10 ( & V_4 -> V_20 ) ;
F_54 ( & V_76 -> V_67 , & V_29 -> V_42 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
F_51 () ;
return 0 ;
}
int F_63 ( struct V_29 * V_29 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_21 () ;
struct V_7 * V_17 ;
int V_77 = 0 ;
F_10 ( & V_4 -> V_20 ) ;
F_8 (imx_crtc, &imxdrm->crtc_list, list) {
if ( V_17 -> V_11 == V_11 )
goto V_21;
V_77 ++ ;
}
F_11 ( & V_4 -> V_20 ) ;
return - V_22 ;
V_21:
F_11 ( & V_4 -> V_20 ) ;
return V_77 ;
}
int F_64 ( struct V_29 * V_29 )
{
struct V_3 * V_4 = F_21 () ;
struct V_54 * V_76 , * V_79 ;
F_10 ( & V_4 -> V_20 ) ;
F_34 ( V_29 ) ;
F_57 ( & V_29 -> V_67 ) ;
F_65 (c, tmp, &imx_drm_encoder->possible_crtcs,
list)
F_30 ( V_76 ) ;
F_11 ( & V_4 -> V_20 ) ;
F_30 ( V_29 ) ;
return 0 ;
}
int F_66 ( struct V_80 * V_45 ,
struct V_31 * * V_81 ,
struct V_59 * V_33 )
{
struct V_3 * V_4 = F_21 () ;
struct V_31 * V_31 ;
int V_25 ;
F_10 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_2 -> V_60 ) {
V_25 = - V_61 ;
goto V_62;
}
V_31 = F_53 ( sizeof( * V_31 ) , V_63 ) ;
if ( ! V_31 ) {
V_25 = - V_64 ;
goto V_65;
}
V_31 -> V_45 = V_45 ;
V_31 -> V_33 = V_33 ;
V_25 = F_36 ( V_31 ) ;
if ( V_25 )
goto V_69;
F_54 ( & V_31 -> V_67 , & V_4 -> V_82 ) ;
* V_81 = V_31 ;
F_11 ( & V_4 -> V_20 ) ;
return 0 ;
V_69:
F_30 ( V_31 ) ;
V_65:
V_62:
F_11 ( & V_4 -> V_20 ) ;
return V_25 ;
}
void F_67 ( struct V_83 * V_84 )
{
struct V_3 * V_4 = F_21 () ;
V_4 -> V_6 = V_84 ;
}
int F_68 ( struct V_31 * V_31 )
{
struct V_3 * V_4 = F_21 () ;
F_10 ( & V_4 -> V_20 ) ;
F_39 ( V_31 ) ;
F_57 ( & V_31 -> V_67 ) ;
F_11 ( & V_4 -> V_20 ) ;
F_30 ( V_31 ) ;
return 0 ;
}
static int F_69 ( struct V_85 * V_86 )
{
V_3 -> V_16 = & V_86 -> V_16 ;
return F_70 ( & V_87 , V_86 ) ;
}
static int F_71 ( struct V_85 * V_86 )
{
F_72 ( & V_87 , V_86 ) ;
return 0 ;
}
static int T_3 F_73 ( void )
{
int V_25 ;
V_3 = F_53 ( sizeof( * V_3 ) , V_63 ) ;
if ( ! V_3 )
return - V_64 ;
F_74 ( & V_3 -> V_20 ) ;
F_32 ( & V_3 -> V_68 ) ;
F_32 ( & V_3 -> V_82 ) ;
F_32 ( & V_3 -> V_72 ) ;
V_88 = F_75 ( L_4 , - 1 , NULL , 0 ) ;
if ( ! V_88 ) {
V_25 = - V_22 ;
goto V_89;
}
V_88 -> V_16 . V_90 = F_76 ( 32 ) ,
V_25 = F_77 ( & V_91 ) ;
if ( V_25 )
goto V_92;
return 0 ;
V_92:
F_78 ( V_88 ) ;
V_89:
F_30 ( V_3 ) ;
return V_25 ;
}
static void T_4 F_79 ( void )
{
F_78 ( V_88 ) ;
F_80 ( & V_91 ) ;
F_30 ( V_3 ) ;
}
