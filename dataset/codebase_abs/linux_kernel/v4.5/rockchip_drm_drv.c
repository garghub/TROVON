int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 . V_6 ;
int V_8 ;
V_8 = F_2 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
return V_8 ;
F_4 ( V_4 , F_3 ( 32 ) ) ;
return F_5 ( V_4 , V_6 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_7 ( V_4 ) ;
}
int F_8 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
int V_13 = F_9 ( V_10 ) ;
struct V_14 * V_15 = V_10 -> V_4 -> V_16 ;
if ( V_13 > V_17 )
return - V_18 ;
V_15 -> V_12 [ V_13 ] = V_12 ;
return 0 ;
}
void F_10 ( struct V_9 * V_10 )
{
int V_13 = F_9 ( V_10 ) ;
struct V_14 * V_15 = V_10 -> V_4 -> V_16 ;
if ( V_13 > V_17 )
return;
V_15 -> V_12 [ V_13 ] = NULL ;
}
static struct V_9 * F_11 ( struct V_1 * V_19 ,
int V_13 )
{
struct V_9 * V_10 ;
int V_20 = 0 ;
F_12 (crtc, &drm->mode_config.crtc_list, head)
if ( V_20 ++ == V_13 )
return V_10 ;
return NULL ;
}
static int F_13 ( struct V_1 * V_4 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_4 -> V_16 ;
struct V_9 * V_10 = F_11 ( V_4 , V_13 ) ;
if ( V_10 && V_15 -> V_12 [ V_13 ] &&
V_15 -> V_12 [ V_13 ] -> V_21 )
return V_15 -> V_12 [ V_13 ] -> V_21 ( V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_4 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_4 -> V_16 ;
struct V_9 * V_10 = F_11 ( V_4 , V_13 ) ;
if ( V_10 && V_15 -> V_12 [ V_13 ] &&
V_15 -> V_12 [ V_13 ] -> V_21 )
V_15 -> V_12 [ V_13 ] -> F_15 ( V_10 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_22 )
{
struct V_14 * V_23 ;
struct V_5 * V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 ;
int V_8 ;
V_23 = F_17 ( V_2 -> V_4 , sizeof( * V_23 ) , V_26 ) ;
if ( ! V_23 )
return - V_27 ;
F_18 ( & V_23 -> V_28 . V_29 ) ;
F_19 ( & V_23 -> V_28 . V_30 , V_31 ) ;
V_2 -> V_16 = V_23 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_4 -> V_32 = F_17 ( V_4 , sizeof( * V_4 -> V_32 ) ,
V_26 ) ;
if ( ! V_4 -> V_32 ) {
V_8 = - V_27 ;
goto V_33;
}
V_6 = F_22 ( & V_34 , 0x00000000 ,
V_35 ) ;
if ( F_23 ( V_6 ) ) {
V_8 = F_24 ( V_6 ) ;
goto V_33;
}
V_8 = F_25 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_36;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_36;
V_8 = F_26 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_37;
F_12 (connector, &drm_dev->mode_config.connector_list,
head) {
V_8 = F_27 ( V_25 ) ;
if ( V_8 ) {
F_28 ( V_2 -> V_4 ,
L_1 ,
V_25 -> V_38 . V_39 ,
V_25 -> V_40 , V_8 ) ;
goto V_41;
}
}
F_29 ( V_2 ) ;
V_2 -> V_42 = true ;
V_8 = F_30 ( V_2 , V_17 ) ;
if ( V_8 )
goto V_43;
V_2 -> V_44 = true ;
F_31 ( V_2 ) ;
V_8 = F_32 ( V_2 ) ;
if ( V_8 )
goto V_45;
return 0 ;
V_45:
F_33 ( V_2 ) ;
V_43:
F_34 ( V_2 ) ;
V_41:
F_35 ( V_4 , V_2 ) ;
V_37:
F_7 ( V_4 ) ;
V_36:
F_36 ( V_4 -> V_7 . V_6 ) ;
V_33:
F_37 ( V_2 ) ;
V_2 -> V_16 = NULL ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_39 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
F_36 ( V_4 -> V_7 . V_6 ) ;
F_37 ( V_2 ) ;
V_2 -> V_16 = NULL ;
return 0 ;
}
void F_40 ( struct V_1 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_16 ;
F_41 ( & V_15 -> V_46 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_43 ( V_4 ) ;
struct V_24 * V_25 ;
if ( ! V_19 )
return 0 ;
F_44 ( V_19 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_47 = V_25 -> V_48 ;
if ( V_25 -> V_49 -> V_48 )
V_25 -> V_49 -> V_48 ( V_25 , V_50 ) ;
V_25 -> V_48 = V_47 ;
}
F_45 ( V_19 ) ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_43 ( V_4 ) ;
struct V_24 * V_25 ;
enum V_51 V_52 ;
bool V_53 = false ;
if ( ! V_19 )
return 0 ;
F_44 ( V_19 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_54 = V_25 -> V_48 ;
V_25 -> V_48 = V_50 ;
if ( V_54 == V_55 ) {
V_52 = V_25 -> V_49 -> V_56 ( V_25 , true ) ;
if ( V_52 == V_57 ) {
V_25 -> V_58 = NULL ;
V_25 -> V_52 = V_52 ;
V_53 = true ;
continue;
}
}
if ( V_25 -> V_49 -> V_48 )
V_25 -> V_49 -> V_48 ( V_25 , V_54 ) ;
}
F_45 ( V_19 ) ;
F_47 ( V_19 ) ;
if ( V_53 )
F_48 ( V_19 ) ;
return 0 ;
}
int F_49 ( struct V_59 * V_60 ,
struct V_61 * V_58 )
{
struct V_59 * V_62 ;
struct V_9 * V_10 = V_58 -> V_10 ;
struct V_63 V_64 ;
struct V_59 * V_65 ;
int V_8 ;
if ( ! V_60 || ! V_10 )
return - V_18 ;
F_50 (node, ep) {
V_65 = F_51 ( V_62 ) ;
F_52 ( V_65 ) ;
if ( V_65 == V_10 -> V_65 ) {
V_8 = F_53 ( V_62 , & V_64 ) ;
F_52 ( V_62 ) ;
return V_8 ? : V_64 . V_39 ;
}
}
return - V_18 ;
}
static int F_54 ( struct V_3 * V_4 , void * V_66 )
{
struct V_59 * V_67 = V_66 ;
return V_4 -> V_68 == V_67 ;
}
static void F_55 ( struct V_3 * V_4 ,
struct V_69 * * V_70 ,
struct V_59 * V_65 )
{
struct V_59 * V_62 , * V_71 ;
F_56 (port, ep) {
V_71 = F_57 ( V_62 ) ;
if ( ! V_71 || ! F_58 ( V_71 ) ) {
F_52 ( V_71 ) ;
continue;
} else if ( ! F_58 ( V_71 -> V_72 ) ) {
F_59 ( V_4 , L_2 ,
V_71 -> V_73 ) ;
F_52 ( V_71 ) ;
continue;
}
F_60 ( V_4 , V_70 , F_54 , V_71 ) ;
F_52 ( V_71 ) ;
}
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_1 * V_19 ;
int V_8 ;
V_19 = F_62 ( & V_74 , V_4 ) ;
if ( ! V_19 )
return - V_27 ;
V_8 = F_63 ( V_19 , 0 ) ;
if ( V_8 )
goto V_75;
F_64 ( V_4 , V_19 ) ;
return 0 ;
V_75:
F_65 ( V_19 ) ;
return V_8 ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_43 ( V_4 ) ;
F_67 ( V_19 ) ;
F_65 ( V_19 ) ;
F_64 ( V_4 , NULL ) ;
}
static int F_68 ( struct V_76 * V_77 )
{
struct V_3 * V_4 = & V_77 -> V_4 ;
struct V_69 * V_70 = NULL ;
struct V_59 * V_67 = V_4 -> V_68 ;
struct V_59 * V_65 ;
int V_20 ;
if ( ! V_67 )
return - V_78 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_65 = F_69 ( V_67 , L_3 , V_20 ) ;
if ( ! V_65 )
break;
if ( ! F_58 ( V_65 -> V_72 ) ) {
F_52 ( V_65 ) ;
continue;
}
F_60 ( V_4 , & V_70 , F_54 , V_65 -> V_72 ) ;
F_52 ( V_65 ) ;
}
if ( V_20 == 0 ) {
F_28 ( V_4 , L_4 ) ;
return - V_78 ;
}
if ( ! V_70 ) {
F_28 ( V_4 , L_5 ) ;
return - V_78 ;
}
for ( V_20 = 0 ; ; V_20 ++ ) {
V_65 = F_69 ( V_67 , L_3 , V_20 ) ;
if ( ! V_65 )
break;
if ( ! F_58 ( V_65 -> V_72 ) ) {
F_52 ( V_65 ) ;
continue;
}
F_55 ( V_4 , & V_70 , V_65 ) ;
F_52 ( V_65 ) ;
}
return F_70 ( V_4 , & V_79 , V_70 ) ;
}
static int F_71 ( struct V_76 * V_77 )
{
F_72 ( & V_77 -> V_4 , & V_79 ) ;
return 0 ;
}
