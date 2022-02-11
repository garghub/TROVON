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
static int F_12 ( struct V_1 * V_4 , int V_11 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_17 * V_19 = F_10 ( V_4 , V_11 ) ;
if ( V_19 && V_13 -> V_10 [ V_11 ] &&
V_13 -> V_10 [ V_11 ] -> V_21 )
return V_13 -> V_10 [ V_11 ] -> V_21 ( V_19 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_4 , int V_11 )
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
int V_8 ;
V_23 = F_16 ( V_2 -> V_4 , sizeof( * V_23 ) , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
V_2 -> V_14 = V_23 ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_4 -> V_26 = F_16 ( V_4 , sizeof( * V_4 -> V_26 ) ,
V_24 ) ;
if ( ! V_4 -> V_26 ) {
V_8 = - V_25 ;
goto V_27;
}
V_6 = F_19 ( & V_28 , 0x00000000 ,
V_29 ) ;
if ( F_20 ( V_6 ) ) {
V_8 = F_21 ( V_6 ) ;
goto V_27;
}
V_8 = F_22 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_30;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_30;
V_8 = F_23 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_31;
F_24 ( V_2 ) ;
V_2 -> V_32 = true ;
V_8 = F_25 ( V_2 , V_15 ) ;
if ( V_8 )
goto V_33;
V_2 -> V_34 = true ;
V_8 = F_26 ( V_2 ) ;
if ( V_8 )
goto V_35;
return 0 ;
V_35:
F_27 ( V_2 ) ;
V_33:
F_28 ( V_2 ) ;
F_29 ( V_4 , V_2 ) ;
V_31:
F_7 ( V_4 ) ;
V_30:
F_30 ( V_4 -> V_7 . V_6 ) ;
V_27:
F_31 ( V_2 ) ;
V_2 -> V_14 = NULL ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_33 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
F_30 ( V_4 -> V_7 . V_6 ) ;
F_31 ( V_2 ) ;
V_2 -> V_14 = NULL ;
return 0 ;
}
void F_34 ( struct V_1 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
F_35 ( & V_13 -> V_36 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_37 ( V_4 ) ;
struct V_37 * V_38 ;
if ( ! V_18 )
return 0 ;
F_38 ( V_18 ) ;
F_11 (connector, &drm->mode_config.connector_list, head) {
int V_39 = V_38 -> V_40 ;
if ( V_38 -> V_41 -> V_40 )
V_38 -> V_41 -> V_40 ( V_38 , V_42 ) ;
V_38 -> V_40 = V_39 ;
}
F_39 ( V_18 ) ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_37 ( V_4 ) ;
struct V_37 * V_38 ;
enum V_43 V_44 ;
bool V_45 = false ;
if ( ! V_18 )
return 0 ;
F_38 ( V_18 ) ;
F_11 (connector, &drm->mode_config.connector_list, head) {
int V_46 = V_38 -> V_40 ;
V_38 -> V_40 = V_42 ;
if ( V_46 == V_47 ) {
V_44 = V_38 -> V_41 -> V_48 ( V_38 , true ) ;
if ( V_44 == V_49 ) {
V_38 -> V_50 = NULL ;
V_38 -> V_44 = V_44 ;
V_45 = true ;
continue;
}
}
if ( V_38 -> V_41 -> V_40 )
V_38 -> V_41 -> V_40 ( V_38 , V_46 ) ;
}
F_39 ( V_18 ) ;
F_41 ( V_18 ) ;
if ( V_45 )
F_42 ( V_18 ) ;
return 0 ;
}
int F_43 ( struct V_51 * V_52 ,
struct V_53 * V_50 )
{
struct V_51 * V_54 = NULL ;
struct V_17 * V_19 = V_50 -> V_19 ;
struct V_55 V_56 ;
struct V_51 * V_57 ;
int V_8 ;
if ( ! V_52 || ! V_19 )
return - V_16 ;
do {
V_54 = F_44 ( V_52 , V_54 ) ;
if ( ! V_54 )
break;
V_57 = F_45 ( V_54 ) ;
F_46 ( V_57 ) ;
if ( V_57 == V_19 -> V_57 ) {
V_8 = F_47 ( V_54 , & V_56 ) ;
return V_8 ? : V_56 . V_58 ;
}
} while ( V_54 );
return - V_16 ;
}
static int F_48 ( struct V_3 * V_4 , void * V_59 )
{
struct V_51 * V_60 = V_59 ;
return V_4 -> V_61 == V_60 ;
}
static void F_49 ( struct V_3 * V_4 ,
struct V_62 * * V_63 ,
struct V_51 * V_57 )
{
struct V_51 * V_54 , * V_64 ;
F_50 (port, ep) {
V_64 = F_51 ( V_54 ) ;
if ( ! V_64 || ! F_52 ( V_64 ) ) {
F_46 ( V_64 ) ;
continue;
} else if ( ! F_52 ( V_64 -> V_65 ) ) {
F_53 ( V_4 , L_1 ,
V_64 -> V_66 ) ;
F_46 ( V_64 ) ;
continue;
}
F_54 ( V_4 , V_63 , F_48 , V_64 ) ;
F_46 ( V_64 ) ;
}
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_18 ;
int V_8 ;
V_18 = F_56 ( & V_67 , V_4 ) ;
if ( ! V_18 )
return - V_25 ;
V_8 = F_57 ( V_18 , L_2 , F_58 ( V_4 ) ) ;
if ( V_8 )
goto V_68;
V_8 = F_59 ( V_18 , 0 ) ;
if ( V_8 )
goto V_68;
F_60 ( V_4 , V_18 ) ;
return 0 ;
V_68:
F_61 ( V_18 ) ;
return V_8 ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_18 = F_37 ( V_4 ) ;
F_63 ( V_18 ) ;
F_61 ( V_18 ) ;
F_60 ( V_4 , NULL ) ;
}
static int F_64 ( struct V_69 * V_70 )
{
struct V_3 * V_4 = & V_70 -> V_4 ;
struct V_62 * V_63 = NULL ;
struct V_51 * V_60 = V_4 -> V_61 ;
struct V_51 * V_57 ;
int V_20 ;
if ( ! V_60 )
return - V_71 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_57 = F_65 ( V_60 , L_3 , V_20 ) ;
if ( ! V_57 )
break;
if ( ! F_52 ( V_57 -> V_65 ) ) {
F_46 ( V_57 ) ;
continue;
}
F_54 ( V_4 , & V_63 , F_48 , V_57 -> V_65 ) ;
F_46 ( V_57 ) ;
}
if ( V_20 == 0 ) {
F_66 ( V_4 , L_4 ) ;
return - V_71 ;
}
if ( ! V_63 ) {
F_66 ( V_4 , L_5 ) ;
return - V_71 ;
}
for ( V_20 = 0 ; ; V_20 ++ ) {
V_57 = F_65 ( V_60 , L_3 , V_20 ) ;
if ( ! V_57 )
break;
if ( ! F_52 ( V_57 -> V_65 ) ) {
F_46 ( V_57 ) ;
continue;
}
F_49 ( V_4 , & V_63 , V_57 ) ;
F_46 ( V_57 ) ;
}
return F_67 ( V_4 , & V_72 , V_63 ) ;
}
static int F_68 ( struct V_69 * V_70 )
{
F_69 ( & V_70 -> V_4 , & V_72 ) ;
return 0 ;
}
