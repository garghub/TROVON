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
static void F_40 ( struct V_9 * V_10 ,
struct V_46 * V_47 )
{
struct V_14 * V_15 = V_10 -> V_4 -> V_16 ;
int V_13 = F_9 ( V_10 ) ;
if ( V_13 < V_17 &&
V_15 -> V_12 [ V_13 ] &&
V_15 -> V_12 [ V_13 ] -> V_48 )
V_15 -> V_12 [ V_13 ] -> V_48 ( V_10 , V_47 ) ;
}
static void F_41 ( struct V_1 * V_4 ,
struct V_46 * V_47 )
{
struct V_9 * V_10 ;
F_12 (crtc, &dev->mode_config.crtc_list, head)
F_40 ( V_10 , V_47 ) ;
}
void F_42 ( struct V_1 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_16 ;
F_43 ( & V_15 -> V_49 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_45 ( V_4 ) ;
struct V_24 * V_25 ;
if ( ! V_19 )
return 0 ;
F_46 ( V_19 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_50 = V_25 -> V_51 ;
if ( V_25 -> V_52 -> V_51 )
V_25 -> V_52 -> V_51 ( V_25 , V_53 ) ;
V_25 -> V_51 = V_50 ;
}
F_47 ( V_19 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_45 ( V_4 ) ;
struct V_24 * V_25 ;
enum V_54 V_55 ;
bool V_56 = false ;
if ( ! V_19 )
return 0 ;
F_46 ( V_19 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_57 = V_25 -> V_51 ;
V_25 -> V_51 = V_53 ;
if ( V_57 == V_58 ) {
V_55 = V_25 -> V_52 -> V_59 ( V_25 , true ) ;
if ( V_55 == V_60 ) {
V_25 -> V_61 = NULL ;
V_25 -> V_55 = V_55 ;
V_56 = true ;
continue;
}
}
if ( V_25 -> V_52 -> V_51 )
V_25 -> V_52 -> V_51 ( V_25 , V_57 ) ;
}
F_47 ( V_19 ) ;
F_49 ( V_19 ) ;
if ( V_56 )
F_50 ( V_19 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
return V_4 -> V_65 == V_64 ;
}
static void F_52 ( struct V_3 * V_4 ,
struct V_66 * * V_67 ,
struct V_63 * V_68 )
{
struct V_63 * V_69 , * V_70 ;
F_53 (port, ep) {
V_70 = F_54 ( V_69 ) ;
if ( ! V_70 || ! F_55 ( V_70 ) ) {
F_56 ( V_70 ) ;
continue;
} else if ( ! F_55 ( V_70 -> V_71 ) ) {
F_57 ( V_4 , L_2 ,
V_70 -> V_72 ) ;
F_56 ( V_70 ) ;
continue;
}
F_58 ( V_4 , V_67 , F_51 , V_70 ) ;
F_56 ( V_70 ) ;
}
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_19 ;
int V_8 ;
V_19 = F_60 ( & V_73 , V_4 ) ;
if ( ! V_19 )
return - V_27 ;
V_8 = F_61 ( V_19 , 0 ) ;
if ( V_8 )
goto V_74;
F_62 ( V_4 , V_19 ) ;
return 0 ;
V_74:
F_63 ( V_19 ) ;
return V_8 ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_19 = F_45 ( V_4 ) ;
F_65 ( V_19 ) ;
F_63 ( V_19 ) ;
F_62 ( V_4 , NULL ) ;
}
static int F_66 ( struct V_75 * V_76 )
{
struct V_3 * V_4 = & V_76 -> V_4 ;
struct V_66 * V_67 = NULL ;
struct V_63 * V_64 = V_4 -> V_65 ;
struct V_63 * V_68 ;
int V_20 ;
if ( ! V_64 )
return - V_77 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_68 = F_67 ( V_64 , L_3 , V_20 ) ;
if ( ! V_68 )
break;
if ( ! F_55 ( V_68 -> V_71 ) ) {
F_56 ( V_68 ) ;
continue;
}
F_58 ( V_4 , & V_67 , F_51 , V_68 -> V_71 ) ;
F_56 ( V_68 ) ;
}
if ( V_20 == 0 ) {
F_28 ( V_4 , L_4 ) ;
return - V_77 ;
}
if ( ! V_67 ) {
F_28 ( V_4 , L_5 ) ;
return - V_77 ;
}
for ( V_20 = 0 ; ; V_20 ++ ) {
V_68 = F_67 ( V_64 , L_3 , V_20 ) ;
if ( ! V_68 )
break;
if ( ! F_55 ( V_68 -> V_71 ) ) {
F_56 ( V_68 ) ;
continue;
}
F_52 ( V_4 , & V_67 , V_68 ) ;
F_56 ( V_68 ) ;
}
return F_68 ( V_4 , & V_78 , V_67 ) ;
}
static int F_69 ( struct V_75 * V_76 )
{
F_70 ( & V_76 -> V_4 , & V_78 ) ;
return 0 ;
}
