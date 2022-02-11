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
int F_8 ( struct V_1 * V_4 ,
const struct V_9 * V_10 ,
int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
if ( V_11 > V_15 )
return - V_16 ;
V_13 -> V_10 [ V_11 ] = V_10 ;
return 0 ;
}
void F_9 ( struct V_1 * V_4 , int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
if ( V_11 > V_15 )
return;
V_13 -> V_10 [ V_11 ] = NULL ;
}
static struct V_17 * F_10 ( struct V_1 * V_18 ,
int V_11 )
{
struct V_17 * V_19 ;
int V_20 = 0 ;
F_11 (crtc, &drm->mode_config.crtc_list, head)
if ( V_20 ++ == V_11 )
return V_19 ;
return NULL ;
}
static int F_12 ( struct V_1 * V_4 ,
unsigned int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_17 * V_19 = F_10 ( V_4 , V_11 ) ;
if ( V_19 && V_13 -> V_10 [ V_11 ] &&
V_13 -> V_10 [ V_11 ] -> V_21 )
return V_13 -> V_10 [ V_11 ] -> V_21 ( V_19 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_4 ,
unsigned int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_17 * V_19 = F_10 ( V_4 , V_11 ) ;
if ( V_19 && V_13 -> V_10 [ V_11 ] &&
V_13 -> V_10 [ V_11 ] -> V_21 )
V_13 -> V_10 [ V_11 ] -> F_14 ( V_19 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_22 )
{
struct V_12 * V_23 ;
struct V_5 * V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 ;
int V_8 ;
V_23 = F_16 ( V_2 -> V_4 , sizeof( * V_23 ) , V_26 ) ;
if ( ! V_23 )
return - V_27 ;
V_2 -> V_14 = V_23 ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_4 -> V_28 = F_16 ( V_4 , sizeof( * V_4 -> V_28 ) ,
V_26 ) ;
if ( ! V_4 -> V_28 ) {
V_8 = - V_27 ;
goto V_29;
}
V_6 = F_19 ( & V_30 , 0x00000000 ,
V_31 ) ;
if ( F_20 ( V_6 ) ) {
V_8 = F_21 ( V_6 ) ;
goto V_29;
}
V_8 = F_22 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_32;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_32;
V_8 = F_23 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_33;
F_11 (connector, &drm_dev->mode_config.connector_list,
head) {
V_8 = F_24 ( V_25 ) ;
if ( V_8 ) {
F_25 ( V_2 -> V_4 ,
L_1 ,
V_25 -> V_34 . V_35 ,
V_25 -> V_36 , V_8 ) ;
goto V_37;
}
}
F_26 ( V_2 ) ;
V_2 -> V_38 = true ;
V_8 = F_27 ( V_2 , V_15 ) ;
if ( V_8 )
goto V_39;
V_2 -> V_40 = true ;
V_8 = F_28 ( V_2 ) ;
if ( V_8 )
goto V_41;
return 0 ;
V_41:
F_29 ( V_2 ) ;
V_39:
F_30 ( V_2 ) ;
V_37:
F_31 ( V_4 , V_2 ) ;
V_33:
F_7 ( V_4 ) ;
V_32:
F_32 ( V_4 -> V_7 . V_6 ) ;
V_29:
F_33 ( V_2 ) ;
V_2 -> V_14 = NULL ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_35 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
F_32 ( V_4 -> V_7 . V_6 ) ;
F_33 ( V_2 ) ;
V_2 -> V_14 = NULL ;
return 0 ;
}
void F_36 ( struct V_1 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
F_37 ( & V_13 -> V_42 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_39 ( V_4 ) ;
struct V_24 * V_25 ;
if ( ! V_18 )
return 0 ;
F_40 ( V_18 ) ;
F_11 (connector, &drm->mode_config.connector_list, head) {
int V_43 = V_25 -> V_44 ;
if ( V_25 -> V_45 -> V_44 )
V_25 -> V_45 -> V_44 ( V_25 , V_46 ) ;
V_25 -> V_44 = V_43 ;
}
F_41 ( V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_39 ( V_4 ) ;
struct V_24 * V_25 ;
enum V_47 V_48 ;
bool V_49 = false ;
if ( ! V_18 )
return 0 ;
F_40 ( V_18 ) ;
F_11 (connector, &drm->mode_config.connector_list, head) {
int V_50 = V_25 -> V_44 ;
V_25 -> V_44 = V_46 ;
if ( V_50 == V_51 ) {
V_48 = V_25 -> V_45 -> V_52 ( V_25 , true ) ;
if ( V_48 == V_53 ) {
V_25 -> V_54 = NULL ;
V_25 -> V_48 = V_48 ;
V_49 = true ;
continue;
}
}
if ( V_25 -> V_45 -> V_44 )
V_25 -> V_45 -> V_44 ( V_25 , V_50 ) ;
}
F_41 ( V_18 ) ;
F_43 ( V_18 ) ;
if ( V_49 )
F_44 ( V_18 ) ;
return 0 ;
}
int F_45 ( struct V_55 * V_56 ,
struct V_57 * V_54 )
{
struct V_55 * V_58 ;
struct V_17 * V_19 = V_54 -> V_19 ;
struct V_59 V_60 ;
struct V_55 * V_61 ;
int V_8 ;
if ( ! V_56 || ! V_19 )
return - V_16 ;
F_46 (node, ep) {
V_61 = F_47 ( V_58 ) ;
F_48 ( V_61 ) ;
if ( V_61 == V_19 -> V_61 ) {
V_8 = F_49 ( V_58 , & V_60 ) ;
F_48 ( V_58 ) ;
return V_8 ? : V_60 . V_35 ;
}
}
return - V_16 ;
}
static int F_50 ( struct V_3 * V_4 , void * V_62 )
{
struct V_55 * V_63 = V_62 ;
return V_4 -> V_64 == V_63 ;
}
static void F_51 ( struct V_3 * V_4 ,
struct V_65 * * V_66 ,
struct V_55 * V_61 )
{
struct V_55 * V_58 , * V_67 ;
F_52 (port, ep) {
V_67 = F_53 ( V_58 ) ;
if ( ! V_67 || ! F_54 ( V_67 ) ) {
F_48 ( V_67 ) ;
continue;
} else if ( ! F_54 ( V_67 -> V_68 ) ) {
F_55 ( V_4 , L_2 ,
V_67 -> V_69 ) ;
F_48 ( V_67 ) ;
continue;
}
F_56 ( V_4 , V_66 , F_50 , V_67 ) ;
F_48 ( V_67 ) ;
}
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_18 ;
int V_8 ;
V_18 = F_58 ( & V_70 , V_4 ) ;
if ( ! V_18 )
return - V_27 ;
V_8 = F_59 ( V_18 , L_3 , F_60 ( V_4 ) ) ;
if ( V_8 )
goto V_71;
V_8 = F_61 ( V_18 , 0 ) ;
if ( V_8 )
goto V_71;
F_62 ( V_4 , V_18 ) ;
return 0 ;
V_71:
F_63 ( V_18 ) ;
return V_8 ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_39 ( V_4 ) ;
F_65 ( V_18 ) ;
F_63 ( V_18 ) ;
F_62 ( V_4 , NULL ) ;
}
static int F_66 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = & V_73 -> V_4 ;
struct V_65 * V_66 = NULL ;
struct V_55 * V_63 = V_4 -> V_64 ;
struct V_55 * V_61 ;
int V_20 ;
if ( ! V_63 )
return - V_74 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_61 = F_67 ( V_63 , L_4 , V_20 ) ;
if ( ! V_61 )
break;
if ( ! F_54 ( V_61 -> V_68 ) ) {
F_48 ( V_61 ) ;
continue;
}
F_56 ( V_4 , & V_66 , F_50 , V_61 -> V_68 ) ;
F_48 ( V_61 ) ;
}
if ( V_20 == 0 ) {
F_25 ( V_4 , L_5 ) ;
return - V_74 ;
}
if ( ! V_66 ) {
F_25 ( V_4 , L_6 ) ;
return - V_74 ;
}
for ( V_20 = 0 ; ; V_20 ++ ) {
V_61 = F_67 ( V_63 , L_4 , V_20 ) ;
if ( ! V_61 )
break;
if ( ! F_54 ( V_61 -> V_68 ) ) {
F_48 ( V_61 ) ;
continue;
}
F_51 ( V_4 , & V_66 , V_61 ) ;
F_48 ( V_61 ) ;
}
return F_68 ( V_4 , & V_75 , V_66 ) ;
}
static int F_69 ( struct V_72 * V_73 )
{
F_70 ( & V_73 -> V_4 , & V_75 ) ;
return 0 ;
}
