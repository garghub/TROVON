int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_9 )
F_3 ( V_7 -> V_9 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_5 () ;
F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static struct V_1 * F_9 ( struct V_6 * V_7 ,
int V_10 )
{
struct V_1 * V_1 ;
F_10 (imx_drm_crtc, &imxdrm->crtc_list, list)
if ( V_1 -> V_3 == V_10 )
return V_1 ;
return NULL ;
}
int F_11 ( struct V_11 * V_2 , T_1 V_12 ,
T_1 V_13 , int V_14 , int V_15 )
{
struct V_6 * V_7 = V_2 -> V_16 -> V_8 ;
struct V_1 * V_17 ;
struct V_18 * V_19 ;
F_10 (imx_crtc, &imxdrm->crtc_list, list)
if ( V_17 -> V_2 == V_2 )
goto V_20;
return - V_21 ;
V_20:
V_19 = & V_17 -> V_22 ;
if ( V_19 -> V_23 )
return V_19 -> V_23 ( V_2 ,
V_12 , V_13 ,
V_14 , V_15 ) ;
return 0 ;
}
int F_12 ( struct V_11 * V_2 , T_1 V_12 ,
T_1 V_13 )
{
return F_11 ( V_2 , V_12 ,
V_13 , 2 , 3 ) ;
}
int F_13 ( struct V_1 * V_1 )
{
return F_14 ( V_1 -> V_2 -> V_16 , V_1 -> V_3 ) ;
}
void F_15 ( struct V_1 * V_1 )
{
F_16 ( V_1 -> V_2 -> V_16 , V_1 -> V_3 ) ;
}
void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_2 -> V_16 , V_1 -> V_3 ) ;
}
static int F_19 ( struct V_4 * V_5 , int V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_1 ;
int V_24 ;
V_1 = F_9 ( V_7 , V_2 ) ;
if ( ! V_1 )
return - V_21 ;
if ( ! V_1 -> V_22 . V_25 )
return - V_26 ;
V_24 = V_1 -> V_22 . V_25 (
V_1 -> V_2 ) ;
return V_24 ;
}
static void F_20 ( struct V_4 * V_5 , int V_2 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_1 ;
V_1 = F_9 ( V_7 , V_2 ) ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_22 . V_27 )
return;
V_1 -> V_22 . V_27 ( V_1 -> V_2 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
struct V_28 * V_29 )
{
int V_30 ;
if ( ! V_29 -> V_31 )
return;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ )
F_20 ( V_5 , V_30 ) ;
}
static struct V_6 * F_22 ( void )
{
return V_6 ;
}
struct V_4 * F_23 ( void )
{
struct V_6 * V_7 = F_22 () ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_2 ;
F_10 (enc, &imxdrm->encoder_list, list) {
if ( ! F_24 ( V_34 -> V_37 ) ) {
F_25 ( V_7 -> V_16 , L_1 ,
F_26 ( V_34 -> V_37 ) ) ;
goto V_38;
}
}
F_10 (con, &imxdrm->connector_list, list) {
if ( ! F_24 ( V_36 -> V_37 ) ) {
F_25 ( V_7 -> V_16 , L_1 ,
F_26 ( V_36 -> V_37 ) ) ;
goto V_39;
}
}
F_10 (crtc, &imxdrm->crtc_list, list) {
if ( ! F_24 ( V_2 -> V_37 ) ) {
F_25 ( V_7 -> V_16 , L_1 ,
F_26 ( V_2 -> V_37 ) ) ;
goto V_40;
}
}
return V_7 -> V_5 ;
V_40:
F_27 (crtc, &imxdrm->crtc_list, list)
F_28 ( V_2 -> V_37 ) ;
V_39:
F_27 (con, &imxdrm->connector_list, list)
F_28 ( V_36 -> V_37 ) ;
V_38:
F_27 (enc, &imxdrm->encoder_list, list)
F_28 ( V_34 -> V_37 ) ;
F_29 ( & V_7 -> V_41 ) ;
return NULL ;
}
void F_5 ( void )
{
struct V_6 * V_7 = F_22 () ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_2 ;
F_30 ( & V_7 -> V_41 ) ;
F_10 (crtc, &imxdrm->crtc_list, list)
F_28 ( V_2 -> V_37 ) ;
F_10 (con, &imxdrm->connector_list, list)
F_28 ( V_36 -> V_37 ) ;
F_10 (enc, &imxdrm->encoder_list, list)
F_28 ( V_34 -> V_37 ) ;
F_29 ( & V_7 -> V_41 ) ;
}
static int F_31 ( struct V_4 * V_16 )
{
struct V_42 * V_43 = & V_16 -> V_44 -> V_45 ;
T_2 * V_46 = V_43 -> V_46 ;
int V_24 ;
V_24 = F_32 ( V_16 , V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
F_33 ( V_46 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_33 )
{
struct V_6 * V_7 = F_22 () ;
F_35 ( & V_33 -> V_47 ) ;
F_36 ( V_7 -> V_5 , V_33 -> V_48 ,
V_33 -> V_48 -> V_49 ,
V_33 -> V_48 -> V_12 ) ;
F_31 ( V_7 -> V_5 ) ;
return 0 ;
}
static void F_37 ( struct V_33
* V_33 )
{
struct V_6 * V_7 = F_22 () ;
F_38 ( V_33 -> V_48 ) ;
F_31 ( V_7 -> V_5 ) ;
}
static int F_39 (
struct V_35 * V_35 )
{
struct V_6 * V_7 = F_22 () ;
F_40 ( V_7 -> V_5 , V_35 -> V_50 ,
V_35 -> V_50 -> V_49 ,
V_35 -> V_50 -> V_51 ) ;
F_31 ( V_7 -> V_5 ) ;
return F_41 ( V_35 -> V_50 ) ;
}
static void F_42 (
struct V_35 * V_35 )
{
struct V_6 * V_7 = F_22 () ;
F_43 ( V_35 -> V_50 ) ;
F_44 ( V_35 -> V_50 ) ;
F_31 ( V_7 -> V_5 ) ;
}
static int F_45 ( struct V_4 * V_5 , unsigned long V_52 )
{
struct V_6 * V_7 = F_22 () ;
int V_24 ;
V_7 -> V_5 = V_5 ;
V_5 -> V_8 = V_7 ;
V_5 -> V_53 = true ;
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
F_30 ( & V_7 -> V_41 ) ;
F_48 ( V_5 ) ;
V_24 = F_32 ( V_5 ,
& V_5 -> V_44 -> V_45 ) ;
if ( V_24 )
goto V_54;
V_24 = F_49 ( V_5 , V_32 ) ;
if ( V_24 )
goto V_54;
V_5 -> V_55 = true ;
if ( ! F_23 () ) {
V_24 = - V_21 ;
goto V_56;
}
F_50 ( V_5 -> V_57 , V_5 ) ;
F_29 ( & V_7 -> V_41 ) ;
return 0 ;
V_56:
F_6 ( V_5 ) ;
V_54:
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_29 ( & V_7 -> V_41 ) ;
return V_24 ;
}
static void F_51 ( void )
{
struct V_6 * V_7 = F_22 () ;
struct V_1 * V_1 ;
struct V_33 * V_34 ;
struct V_58 * V_59 ;
F_10 (enc, &imxdrm->encoder_list, list) {
T_1 V_47 = 0 ;
F_10 (cookie, &enc->possible_crtcs, list) {
F_10 (imx_drm_crtc, &imxdrm->crtc_list, list) {
if ( V_1 -> V_59 . V_59 == V_59 -> V_59 &&
V_1 -> V_59 . V_60 == V_59 -> V_60 ) {
V_47 |= 1 << V_1 -> V_3 ;
}
}
}
V_34 -> V_48 -> V_47 = V_47 ;
V_34 -> V_48 -> V_61 = V_47 ;
}
}
int F_52 ( struct V_11 * V_2 ,
struct V_1 * * V_62 ,
const struct V_18 * V_22 ,
struct V_63 * V_37 , void * V_59 , int V_60 )
{
struct V_6 * V_7 = F_22 () ;
struct V_1 * V_1 ;
int V_24 ;
F_30 ( & V_7 -> V_41 ) ;
if ( V_7 -> V_64 >= V_32 ) {
V_24 = - V_21 ;
goto V_65;
}
if ( V_7 -> V_5 -> V_66 ) {
V_24 = - V_67 ;
goto V_65;
}
V_1 = F_53 ( sizeof( * V_1 ) , V_68 ) ;
if ( ! V_1 ) {
V_24 = - V_69 ;
goto V_70;
}
V_1 -> V_22 = * V_22 ;
V_1 -> V_3 = V_7 -> V_64 ++ ;
V_1 -> V_59 . V_59 = V_59 ;
V_1 -> V_59 . V_60 = V_60 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_37 = V_37 ;
F_54 ( & V_1 -> V_71 , & V_7 -> V_72 ) ;
* V_62 = V_1 ;
V_24 = F_55 ( V_1 -> V_2 , 256 ) ;
if ( V_24 )
goto V_73;
F_56 ( V_2 ,
V_1 -> V_22 . V_74 ) ;
F_57 ( V_7 -> V_5 , V_2 ,
V_1 -> V_22 . V_75 ) ;
F_31 ( V_7 -> V_5 ) ;
F_51 () ;
F_29 ( & V_7 -> V_41 ) ;
return 0 ;
V_73:
F_58 ( & V_1 -> V_71 ) ;
F_33 ( V_1 ) ;
V_70:
V_65:
F_29 ( & V_7 -> V_41 ) ;
return V_24 ;
}
int F_59 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
F_30 ( & V_7 -> V_41 ) ;
F_60 ( V_1 -> V_2 ) ;
F_58 ( & V_1 -> V_71 ) ;
F_31 ( V_7 -> V_5 ) ;
F_29 ( & V_7 -> V_41 ) ;
F_33 ( V_1 ) ;
return 0 ;
}
int F_61 ( struct V_76 * V_48 ,
struct V_33 * * V_77 , struct V_63 * V_37 )
{
struct V_6 * V_7 = F_22 () ;
struct V_33 * V_33 ;
int V_24 ;
F_30 ( & V_7 -> V_41 ) ;
if ( V_7 -> V_5 -> V_66 ) {
V_24 = - V_67 ;
goto V_65;
}
V_33 = F_53 ( sizeof( * V_33 ) , V_68 ) ;
if ( ! V_33 ) {
V_24 = - V_69 ;
goto V_70;
}
V_33 -> V_48 = V_48 ;
V_33 -> V_37 = V_37 ;
V_24 = F_34 ( V_33 ) ;
if ( V_24 ) {
V_24 = - V_69 ;
goto V_73;
}
F_54 ( & V_33 -> V_71 , & V_7 -> V_78 ) ;
* V_77 = V_33 ;
F_29 ( & V_7 -> V_41 ) ;
return 0 ;
V_73:
F_33 ( V_33 ) ;
V_70:
V_65:
F_29 ( & V_7 -> V_41 ) ;
return V_24 ;
}
int F_62 (
struct V_33 * V_33 ,
struct V_79 * V_80 )
{
struct V_6 * V_7 = F_22 () ;
struct V_81 args ;
struct V_58 * V_82 ;
int V_24 = 0 ;
int V_30 ;
if ( ! F_63 ( & V_33 -> V_47 ) )
return - V_67 ;
for ( V_30 = 0 ; ! V_24 ; V_30 ++ ) {
V_24 = F_64 ( V_80 , L_2 ,
L_3 , V_30 , & args ) ;
if ( V_24 < 0 )
break;
V_82 = F_53 ( sizeof( * V_82 ) , V_68 ) ;
if ( ! V_82 ) {
F_65 ( args . V_80 ) ;
return - V_69 ;
}
V_82 -> V_59 = args . V_80 ;
V_82 -> V_60 = args . V_83 > 0 ? args . args [ 0 ] : 0 ;
F_65 ( args . V_80 ) ;
F_30 ( & V_7 -> V_41 ) ;
F_54 ( & V_82 -> V_71 , & V_33 -> V_47 ) ;
F_29 ( & V_7 -> V_41 ) ;
}
F_51 () ;
return 0 ;
}
int F_66 ( struct V_33 * V_33 ,
struct V_11 * V_2 )
{
struct V_6 * V_7 = F_22 () ;
struct V_1 * V_17 ;
int V_30 = 0 ;
F_10 (imx_crtc, &imxdrm->crtc_list, list) {
if ( V_17 -> V_2 == V_2 )
goto V_20;
V_30 ++ ;
}
return - V_21 ;
V_20:
return V_30 ;
}
int F_67 ( struct V_33 * V_33 )
{
struct V_6 * V_7 = F_22 () ;
struct V_58 * V_82 , * V_84 ;
F_30 ( & V_7 -> V_41 ) ;
F_37 ( V_33 ) ;
F_58 ( & V_33 -> V_71 ) ;
F_68 (c, tmp, &imx_drm_encoder->possible_crtcs,
list)
F_33 ( V_82 ) ;
F_29 ( & V_7 -> V_41 ) ;
F_33 ( V_33 ) ;
return 0 ;
}
int F_69 ( struct V_85 * V_50 ,
struct V_35 * * V_86 ,
struct V_63 * V_37 )
{
struct V_6 * V_7 = F_22 () ;
struct V_35 * V_35 ;
int V_24 ;
F_30 ( & V_7 -> V_41 ) ;
if ( V_7 -> V_5 -> V_66 ) {
V_24 = - V_67 ;
goto V_65;
}
V_35 = F_53 ( sizeof( * V_35 ) , V_68 ) ;
if ( ! V_35 ) {
V_24 = - V_69 ;
goto V_70;
}
V_35 -> V_50 = V_50 ;
V_35 -> V_37 = V_37 ;
V_24 = F_39 ( V_35 ) ;
if ( V_24 )
goto V_73;
F_54 ( & V_35 -> V_71 , & V_7 -> V_87 ) ;
* V_86 = V_35 ;
F_29 ( & V_7 -> V_41 ) ;
return 0 ;
V_73:
F_33 ( V_35 ) ;
V_70:
V_65:
F_29 ( & V_7 -> V_41 ) ;
return V_24 ;
}
void F_70 ( struct V_88 * V_89 )
{
struct V_6 * V_7 = F_22 () ;
V_7 -> V_9 = V_89 ;
}
int F_71 ( struct V_35 * V_35 )
{
struct V_6 * V_7 = F_22 () ;
F_30 ( & V_7 -> V_41 ) ;
F_42 ( V_35 ) ;
F_58 ( & V_35 -> V_71 ) ;
F_29 ( & V_7 -> V_41 ) ;
F_33 ( V_35 ) ;
return 0 ;
}
static int F_72 ( struct V_90 * V_91 )
{
int V_24 ;
V_24 = F_73 ( & V_91 -> V_16 , F_74 ( 32 ) ) ;
if ( V_24 )
return V_24 ;
V_6 -> V_16 = & V_91 -> V_16 ;
return F_75 ( & V_92 , V_91 ) ;
}
static int F_76 ( struct V_90 * V_91 )
{
F_77 ( F_78 ( V_91 ) ) ;
return 0 ;
}
static int T_3 F_79 ( void )
{
int V_24 ;
V_6 = F_53 ( sizeof( * V_6 ) , V_68 ) ;
if ( ! V_6 )
return - V_69 ;
F_80 ( & V_6 -> V_41 ) ;
F_35 ( & V_6 -> V_72 ) ;
F_35 ( & V_6 -> V_87 ) ;
F_35 ( & V_6 -> V_78 ) ;
V_93 = F_81 ( L_4 , - 1 , NULL , 0 ) ;
if ( F_82 ( V_93 ) ) {
V_24 = F_83 ( V_93 ) ;
goto V_94;
}
V_24 = F_84 ( & V_95 ) ;
if ( V_24 )
goto V_96;
return 0 ;
V_96:
F_85 ( V_93 ) ;
V_94:
F_33 ( V_6 ) ;
return V_24 ;
}
static void T_4 F_86 ( void )
{
F_85 ( V_93 ) ;
F_87 ( & V_95 ) ;
F_33 ( V_6 ) ;
}
