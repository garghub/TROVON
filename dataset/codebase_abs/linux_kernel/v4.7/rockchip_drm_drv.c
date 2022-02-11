int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 . V_6 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_8 = F_2 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
return V_8 ;
F_4 ( V_4 , F_3 ( 32 ) ) ;
return F_5 ( V_4 , V_6 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_9 )
return;
F_7 ( V_4 ) ;
}
int F_8 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
int V_14 = F_9 ( V_11 ) ;
struct V_15 * V_16 = V_11 -> V_4 -> V_17 ;
if ( V_14 > V_18 )
return - V_19 ;
V_16 -> V_13 [ V_14 ] = V_13 ;
return 0 ;
}
void F_10 ( struct V_10 * V_11 )
{
int V_14 = F_9 ( V_11 ) ;
struct V_15 * V_16 = V_11 -> V_4 -> V_17 ;
if ( V_14 > V_18 )
return;
V_16 -> V_13 [ V_14 ] = NULL ;
}
static struct V_10 * F_11 ( struct V_1 * V_20 ,
int V_14 )
{
struct V_10 * V_11 ;
int V_21 = 0 ;
F_12 (crtc, &drm->mode_config.crtc_list, head)
if ( V_21 ++ == V_14 )
return V_11 ;
return NULL ;
}
static int F_13 ( struct V_1 * V_4 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_10 * V_11 = F_11 ( V_4 , V_14 ) ;
if ( V_11 && V_16 -> V_13 [ V_14 ] &&
V_16 -> V_13 [ V_14 ] -> V_22 )
return V_16 -> V_13 [ V_14 ] -> V_22 ( V_11 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_4 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_10 * V_11 = F_11 ( V_4 , V_14 ) ;
if ( V_11 && V_16 -> V_13 [ V_14 ] &&
V_16 -> V_13 [ V_14 ] -> V_22 )
V_16 -> V_13 [ V_14 ] -> F_15 ( V_11 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_23 )
{
struct V_15 * V_24 ;
struct V_5 * V_6 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_26 ;
int V_8 ;
V_24 = F_17 ( V_2 -> V_4 , sizeof( * V_24 ) , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
F_18 ( & V_24 -> V_29 . V_30 ) ;
F_19 ( & V_24 -> V_29 . V_31 , V_32 ) ;
V_2 -> V_17 = V_24 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_4 -> V_33 = F_17 ( V_4 , sizeof( * V_4 -> V_33 ) ,
V_27 ) ;
if ( ! V_4 -> V_33 ) {
V_8 = - V_28 ;
goto V_34;
}
if ( V_9 ) {
V_6 = F_22 ( & V_35 ,
0x00000000 ,
V_36 ) ;
if ( F_23 ( V_6 ) ) {
V_8 = F_24 ( V_6 ) ;
goto V_34;
}
V_8 = F_25 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_37;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_37;
}
V_8 = F_26 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_38;
F_12 (connector, &drm_dev->mode_config.connector_list,
head) {
V_8 = F_27 ( V_26 ) ;
if ( V_8 ) {
F_28 ( V_2 -> V_4 ,
L_1 ,
V_26 -> V_39 . V_40 ,
V_26 -> V_41 , V_8 ) ;
goto V_42;
}
}
F_29 ( V_2 ) ;
V_2 -> V_43 = true ;
V_8 = F_30 ( V_2 , V_18 ) ;
if ( V_8 )
goto V_44;
F_31 ( V_2 ) ;
V_8 = F_32 ( V_2 ) ;
if ( V_8 )
goto V_45;
if ( V_9 )
F_33 ( V_6 ) ;
return 0 ;
V_45:
F_34 ( V_2 ) ;
V_44:
F_35 ( V_2 ) ;
V_42:
F_36 ( V_4 , V_2 ) ;
V_38:
if ( V_9 )
F_7 ( V_4 ) ;
V_37:
if ( V_9 )
F_33 ( V_6 ) ;
V_34:
F_37 ( V_2 ) ;
V_2 -> V_17 = NULL ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_39 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_4 , V_2 ) ;
if ( V_9 )
F_7 ( V_4 ) ;
F_37 ( V_2 ) ;
V_2 -> V_17 = NULL ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 = V_11 -> V_4 -> V_17 ;
int V_14 = F_9 ( V_11 ) ;
if ( V_14 < V_18 &&
V_16 -> V_13 [ V_14 ] &&
V_16 -> V_13 [ V_14 ] -> V_48 )
V_16 -> V_13 [ V_14 ] -> V_48 ( V_11 , V_47 ) ;
}
static void F_41 ( struct V_1 * V_4 ,
struct V_46 * V_47 )
{
struct V_10 * V_11 ;
F_12 (crtc, &dev->mode_config.crtc_list, head)
F_40 ( V_11 , V_47 ) ;
}
void F_42 ( struct V_1 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
F_43 ( & V_16 -> V_49 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_45 ( V_4 ) ;
struct V_25 * V_26 ;
if ( ! V_20 )
return 0 ;
F_46 ( V_20 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_50 = V_26 -> V_51 ;
if ( V_26 -> V_52 -> V_51 )
V_26 -> V_52 -> V_51 ( V_26 , V_53 ) ;
V_26 -> V_51 = V_50 ;
}
F_47 ( V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_45 ( V_4 ) ;
struct V_25 * V_26 ;
enum V_54 V_55 ;
bool V_56 = false ;
if ( ! V_20 )
return 0 ;
F_46 ( V_20 ) ;
F_12 (connector, &drm->mode_config.connector_list, head) {
int V_57 = V_26 -> V_51 ;
V_26 -> V_51 = V_53 ;
if ( V_57 == V_58 ) {
V_55 = V_26 -> V_52 -> V_59 ( V_26 , true ) ;
if ( V_55 == V_60 ) {
V_26 -> V_61 = NULL ;
V_26 -> V_55 = V_55 ;
V_56 = true ;
continue;
}
}
if ( V_26 -> V_52 -> V_51 )
V_26 -> V_52 -> V_51 ( V_26 , V_57 ) ;
}
F_47 ( V_20 ) ;
F_49 ( V_20 ) ;
if ( V_56 )
F_50 ( V_20 ) ;
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
struct V_1 * V_20 ;
int V_8 ;
V_20 = F_60 ( & V_73 , V_4 ) ;
if ( ! V_20 )
return - V_28 ;
V_8 = F_61 ( V_20 , 0 ) ;
if ( V_8 )
goto V_74;
F_62 ( V_4 , V_20 ) ;
return 0 ;
V_74:
F_63 ( V_20 ) ;
return V_8 ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_45 ( V_4 ) ;
F_65 ( V_20 ) ;
F_63 ( V_20 ) ;
F_62 ( V_4 , NULL ) ;
}
static int F_66 ( struct V_75 * V_76 )
{
struct V_3 * V_4 = & V_76 -> V_4 ;
struct V_66 * V_67 = NULL ;
struct V_63 * V_64 = V_4 -> V_65 ;
struct V_63 * V_68 ;
int V_21 ;
if ( ! V_64 )
return - V_77 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
struct V_63 * V_78 ;
V_68 = F_67 ( V_64 , L_3 , V_21 ) ;
if ( ! V_68 )
break;
if ( ! F_55 ( V_68 -> V_71 ) ) {
F_56 ( V_68 ) ;
continue;
}
V_78 = F_67 ( V_68 -> V_71 , L_4 , 0 ) ;
if ( ! V_78 || ! F_55 ( V_78 -> V_71 ) ) {
F_68 ( V_4 , L_5 ,
V_68 -> V_71 -> V_72 ) ;
V_9 = false ;
}
F_58 ( V_4 , & V_67 , F_51 , V_68 -> V_71 ) ;
F_56 ( V_68 ) ;
}
if ( V_21 == 0 ) {
F_28 ( V_4 , L_6 ) ;
return - V_77 ;
}
if ( ! V_67 ) {
F_28 ( V_4 , L_7 ) ;
return - V_77 ;
}
for ( V_21 = 0 ; ; V_21 ++ ) {
V_68 = F_67 ( V_64 , L_3 , V_21 ) ;
if ( ! V_68 )
break;
if ( ! F_55 ( V_68 -> V_71 ) ) {
F_56 ( V_68 ) ;
continue;
}
F_52 ( V_4 , & V_67 , V_68 ) ;
F_56 ( V_68 ) ;
}
return F_69 ( V_4 , & V_79 , V_67 ) ;
}
static int F_70 ( struct V_75 * V_76 )
{
F_71 ( & V_76 -> V_4 , & V_79 ) ;
return 0 ;
}
