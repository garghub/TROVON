static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
F_3 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_9 = ( void * ) V_5 ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 ) {
F_5 ( L_1 ) ;
goto V_10;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_11 , V_2 ) ;
V_6 = F_10 ( V_2 -> V_2 , V_2 ) ;
if ( V_6 )
goto V_12;
V_6 = F_11 ( V_2 , V_2 -> V_13 . V_14 ) ;
if ( V_6 )
goto V_15;
V_6 = F_12 ( V_2 ) ;
if ( V_6 )
goto V_16;
V_2 -> V_17 = true ;
V_2 -> V_18 = true ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
V_16:
F_15 ( V_2 ) ;
V_15:
F_16 ( V_2 -> V_2 , V_2 ) ;
V_12:
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_10:
F_19 ( V_5 ) ;
return V_6 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 -> V_2 , V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_20 * V_21 ;
F_25 ( V_2 ) ;
F_26 (connector, &dev->mode_config.connector_list, head) {
int V_22 = V_21 -> V_23 ;
if ( V_21 -> V_24 -> V_23 )
V_21 -> V_24 -> V_23 ( V_21 , V_25 ) ;
V_21 -> V_23 = V_22 ;
}
F_27 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
F_25 ( V_2 ) ;
F_26 (connector, &dev->mode_config.connector_list, head) {
if ( V_21 -> V_24 -> V_23 ) {
int V_23 = V_21 -> V_23 ;
V_21 -> V_23 = V_25 ;
V_21 -> V_24 -> V_23 ( V_21 , V_23 ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_6 ;
V_29 = F_2 ( sizeof( * V_29 ) , V_7 ) ;
if ( ! V_29 )
return - V_8 ;
V_27 -> V_30 = V_29 ;
V_6 = F_30 ( V_2 , V_27 ) ;
if ( V_6 )
goto V_31;
return V_6 ;
V_31:
F_19 ( V_29 ) ;
V_27 -> V_30 = NULL ;
return V_6 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
F_32 ( V_2 , V_27 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
unsigned long V_3 ;
if ( ! V_27 -> V_30 )
return;
F_34 ( & V_2 -> V_35 , V_3 ) ;
F_35 (e, et, &file->event_list, link) {
F_36 ( & V_33 -> V_36 ) ;
V_33 -> V_37 ( V_33 ) ;
}
F_37 ( & V_2 -> V_35 , V_3 ) ;
F_19 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_38 * V_2 )
{
struct V_1 * V_39 = F_41 ( V_2 ) ;
T_1 V_40 ;
if ( F_42 ( V_2 ) || ! V_39 )
return 0 ;
V_40 . V_41 = V_42 ;
return F_24 ( V_39 , V_40 ) ;
}
static int F_43 ( struct V_38 * V_2 )
{
struct V_1 * V_39 = F_41 ( V_2 ) ;
if ( F_42 ( V_2 ) || ! V_39 )
return 0 ;
return F_28 ( V_39 ) ;
}
int F_44 ( struct V_38 * V_2 ,
enum V_43 V_44 ,
enum V_45 V_46 )
{
struct V_47 * V_48 ;
if ( V_44 != V_49 &&
V_44 != V_50 ) {
F_5 ( L_2 ) ;
return - V_51 ;
}
F_45 ( & V_52 ) ;
F_26 (cdev, &drm_component_list, list) {
if ( V_48 -> V_46 == V_46 ) {
if ( V_48 -> V_53 == ( V_49 |
V_50 ) ) {
F_46 ( & V_52 ) ;
return 0 ;
}
if ( V_44 == V_49 ) {
V_48 -> V_54 = V_2 ;
V_48 -> V_53 |= V_44 ;
}
if ( V_44 == V_50 ) {
V_48 -> V_55 = V_2 ;
V_48 -> V_53 |= V_44 ;
}
F_46 ( & V_52 ) ;
return 0 ;
}
}
F_46 ( & V_52 ) ;
V_48 = F_2 ( sizeof( * V_48 ) , V_7 ) ;
if ( ! V_48 )
return - V_8 ;
if ( V_44 == V_49 )
V_48 -> V_54 = V_2 ;
if ( V_44 == V_50 )
V_48 -> V_55 = V_2 ;
V_48 -> V_46 = V_46 ;
V_48 -> V_53 = V_44 ;
F_45 ( & V_52 ) ;
F_47 ( & V_48 -> V_56 , & V_57 ) ;
F_46 ( & V_52 ) ;
return 0 ;
}
void F_48 ( struct V_38 * V_2 ,
enum V_43 V_44 )
{
struct V_47 * V_48 , * V_58 ;
F_45 ( & V_52 ) ;
F_35 (cdev, next, &drm_component_list, list) {
if ( V_44 == V_49 ) {
if ( V_48 -> V_54 == V_2 ) {
V_48 -> V_54 = NULL ;
V_48 -> V_53 &= ~ V_44 ;
}
}
if ( V_44 == V_50 ) {
if ( V_48 -> V_55 == V_2 ) {
V_48 -> V_55 = NULL ;
V_48 -> V_53 &= ~ V_44 ;
}
}
if ( ! V_48 -> V_54 && ! V_48 -> V_55 ) {
F_36 ( & V_48 -> V_56 ) ;
F_19 ( V_48 ) ;
}
}
F_46 ( & V_52 ) ;
}
static int F_49 ( struct V_38 * V_2 , void * V_59 )
{
return V_2 == (struct V_38 * ) V_59 ;
}
static struct V_60 * F_50 ( struct V_38 * V_2 )
{
struct V_60 * V_61 = NULL ;
struct V_47 * V_48 ;
unsigned int V_62 = 0 ;
F_45 ( & V_52 ) ;
if ( F_51 ( & V_57 ) ) {
F_46 ( & V_52 ) ;
return F_52 ( - V_63 ) ;
}
F_26 (cdev, &drm_component_list, list) {
if ( ! V_48 -> V_54 || ! V_48 -> V_55 )
continue;
V_62 ++ ;
F_46 ( & V_52 ) ;
if ( V_48 -> V_54 == V_48 -> V_55 ) {
F_53 ( V_2 , & V_61 , F_49 ,
V_48 -> V_54 ) ;
goto V_64;
}
F_53 ( V_2 , & V_61 , F_49 , V_48 -> V_54 ) ;
F_53 ( V_2 , & V_61 , F_49 , V_48 -> V_55 ) ;
V_64:
F_45 ( & V_52 ) ;
}
F_46 ( & V_52 ) ;
return V_62 ? V_61 : F_52 ( - V_65 ) ;
}
static int F_54 ( struct V_38 * V_2 )
{
return F_55 ( & V_66 , F_56 ( V_2 ) ) ;
}
static void F_57 ( struct V_38 * V_2 )
{
F_58 ( F_41 ( V_2 ) ) ;
}
static int F_59 ( struct V_67 * V_68 )
{
struct V_60 * V_61 ;
V_68 -> V_2 . V_69 = F_60 ( 32 ) ;
V_66 . V_70 = F_61 ( V_71 ) ;
V_61 = F_50 ( & V_68 -> V_2 ) ;
if ( F_62 ( V_61 ) ) {
return F_63 ( V_61 ) ;
}
return F_64 ( & V_68 -> V_2 , & V_72 ,
V_61 ) ;
}
static int F_65 ( struct V_67 * V_68 )
{
F_66 ( & V_68 -> V_2 , & V_72 ) ;
return 0 ;
}
static int F_67 ( void )
{
bool V_73 = false ;
int V_6 , V_74 , V_75 ;
for ( V_74 = 0 ; V_74 < F_61 ( V_76 ) ; V_74 ++ ) {
if ( F_68 ( V_76 [ V_74 ] ) ) {
V_73 = true ;
break;
}
}
if ( ! V_73 )
return - V_63 ;
V_77 = F_69 ( L_3 , - 1 ,
NULL , 0 ) ;
if ( F_62 ( V_77 ) )
return F_63 ( V_77 ) ;
V_6 = F_70 () ;
if ( V_6 < 0 )
goto V_78;
for ( V_74 = 0 ; V_74 < F_61 ( V_79 ) ; ++ V_74 ) {
V_6 = F_71 ( V_79 [ V_74 ] ) ;
if ( V_6 < 0 )
goto V_80;
}
for ( V_75 = 0 ; V_75 < F_61 ( V_81 ) ; ++ V_75 ) {
V_6 = F_71 ( V_81 [ V_75 ] ) ;
if ( V_6 < 0 )
goto V_82;
}
#ifdef F_72
V_6 = F_73 () ;
if ( V_6 < 0 )
goto V_82;
#endif
V_6 = F_71 ( & V_83 ) ;
if ( V_6 )
goto V_84;
return 0 ;
V_84:
#ifdef F_72
F_74 () ;
#endif
V_82:
while ( -- V_75 >= 0 )
F_75 ( V_81 [ V_75 ] ) ;
V_80:
while ( -- V_74 >= 0 )
F_75 ( V_79 [ V_74 ] ) ;
F_76 () ;
V_78:
F_77 ( V_77 ) ;
return V_6 ;
}
static void F_78 ( void )
{
int V_74 ;
#ifdef F_72
F_74 () ;
#endif
for ( V_74 = F_61 ( V_81 ) - 1 ; V_74 >= 0 ; -- V_74 )
F_75 ( V_81 [ V_74 ] ) ;
for ( V_74 = F_61 ( V_79 ) - 1 ; V_74 >= 0 ; -- V_74 )
F_75 ( V_79 [ V_74 ] ) ;
F_75 ( & V_83 ) ;
F_76 () ;
F_77 ( V_77 ) ;
}
