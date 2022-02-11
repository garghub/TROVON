static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return - V_9 ;
if ( ! F_4 ( 0 , & V_7 -> V_10 ) )
V_7 -> V_11 = true ;
V_7 -> V_12 = true ;
F_5 ( & V_7 -> V_13 ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_8 )
return;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
V_7 -> V_11 = false ;
}
static void F_8 ( struct V_5 * V_6 , unsigned int V_14 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_15 * V_16 ;
if ( V_7 -> V_8 )
return;
if ( V_14 < 0 || V_14 >= V_17 )
return;
V_16 = & V_7 -> V_18 [ V_14 ] ;
V_16 -> V_19 = true ;
F_9 ( L_1 , V_16 -> V_20 ) ;
if ( V_7 -> V_11 )
F_5 ( & V_7 -> V_13 ) ;
}
static void F_10 ( struct V_5 * V_6 , unsigned int V_14 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_15 * V_16 ;
if ( V_14 < 0 || V_14 >= V_17 )
return;
V_16 = & V_7 -> V_18 [ V_14 ] ;
V_16 -> V_19 = false ;
}
static int F_11 ( struct V_1 * V_7 , bool V_21 )
{
struct V_15 * V_16 ;
int V_22 ;
F_9 ( L_2 , __FILE__ ) ;
if ( V_21 != false && V_21 != true )
return - V_23 ;
if ( V_21 ) {
V_7 -> V_8 = false ;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
F_3 ( V_7 -> V_6 ) ;
for ( V_22 = 0 ; V_22 < V_17 ; V_22 ++ ) {
V_16 = & V_7 -> V_18 [ V_22 ] ;
if ( V_16 -> V_19 )
F_8 ( V_7 -> V_6 , V_22 ) ;
}
} else {
V_7 -> V_8 = true ;
}
return 0 ;
}
static void F_12 ( struct V_5 * V_6 , int V_24 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_9 ( L_3 , V_24 ) ;
F_13 ( & V_7 -> V_25 ) ;
switch ( V_24 ) {
case V_26 :
F_11 ( V_7 , true ) ;
break;
case V_27 :
case V_28 :
case V_29 :
F_11 ( V_7 , false ) ;
break;
default:
F_9 ( L_4 , V_24 ) ;
break;
}
F_14 ( & V_7 -> V_25 ) ;
}
static int F_15 ( struct V_1 * V_7 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_34 ;
V_7 -> V_31 = V_31 ;
V_7 -> V_35 = V_33 -> V_35 ++ ;
return 0 ;
}
static void F_16 ( struct V_36 * V_13 )
{
struct V_1 * V_7 = F_2 ( V_13 , struct V_1 ,
V_13 ) ;
if ( V_7 -> V_35 < 0 )
return;
F_17 ( 16000 , 20000 ) ;
F_13 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_12 ) {
F_18 ( V_7 -> V_31 , V_7 -> V_35 ) ;
V_7 -> V_12 = false ;
F_14 ( & V_7 -> V_25 ) ;
return;
}
F_14 ( & V_7 -> V_25 ) ;
F_19 ( V_7 -> V_31 , V_7 -> V_35 ) ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_1 * V_7 = F_21 ( V_38 ) ;
int V_42 ;
F_13 ( & V_7 -> V_25 ) ;
V_42 = sprintf ( V_41 , L_3 , V_7 -> V_43 ) ;
F_14 ( & V_7 -> V_25 ) ;
return V_42 ;
}
static int F_22 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_41 , T_1 V_44 )
{
struct V_1 * V_7 = F_21 ( V_38 ) ;
int V_45 ;
V_45 = F_23 ( V_41 , 0 , & V_7 -> V_43 ) ;
if ( V_45 )
return V_45 ;
if ( V_7 -> V_43 > 1 )
return - V_23 ;
if ( ! V_7 -> V_46 )
V_7 -> V_46 = (struct V_47 * ) V_48 ;
if ( V_7 -> V_46 != (struct V_47 * ) V_48 ) {
F_9 ( L_5 ) ;
return - V_23 ;
}
F_9 ( L_6 ) ;
F_24 ( V_7 -> V_31 ) ;
return V_44 ;
}
int F_25 ( struct V_30 * V_31 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_1 * V_7 = NULL ;
struct V_52 * V_53 ;
struct V_2 * V_4 ;
struct V_54 * V_55 = V_49 ;
if ( ! V_55 ) {
F_9 ( L_7 ) ;
return - V_23 ;
}
if ( V_55 -> V_56 > 1 ) {
F_9 ( L_8 ) ;
return - V_23 ;
}
F_26 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_4 = F_27 ( V_53 ) ;
if ( V_4 -> type == V_57 ) {
V_7 = F_1 ( V_4 ) ;
break;
}
}
if ( ! V_7 ) {
F_9 ( L_9 ) ;
return - V_23 ;
}
if ( V_7 -> V_43 == V_55 -> V_56 ) {
F_9 ( L_10 ) ;
return - V_23 ;
}
if ( V_55 -> V_56 ) {
struct V_47 * V_46 = (struct V_47 * ) ( V_58 ) V_55 -> V_47 ;
if ( ! F_28 ( V_46 ) ) {
F_9 ( L_11 ) ;
return - V_23 ;
}
V_7 -> V_46 = F_29 ( V_46 ) ;
if ( ! V_7 -> V_46 ) {
F_9 ( L_12 ) ;
return - V_59 ;
}
} else {
if ( V_7 -> V_46 && V_7 -> V_46 !=
(struct V_47 * ) V_48 ) {
F_30 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
}
V_7 -> V_43 = V_55 -> V_56 ;
F_24 ( V_7 -> V_31 ) ;
return 0 ;
}
static enum V_60 F_31 ( struct V_61 * V_62 ,
bool V_63 )
{
struct V_1 * V_7 = F_32 ( V_62 ) ;
return V_7 -> V_43 ? V_64 :
V_65 ;
}
static void F_33 ( struct V_61 * V_62 )
{
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_1 * V_7 = F_32 ( V_62 ) ;
struct V_47 * V_47 ;
int V_66 ;
if ( ! V_7 -> V_46 ) {
F_9 ( L_13 ) ;
return - V_67 ;
}
V_66 = ( 1 + V_7 -> V_46 -> V_68 ) * V_69 ;
V_47 = F_35 ( V_7 -> V_46 , V_66 , V_70 ) ;
if ( ! V_47 ) {
F_9 ( L_14 ) ;
return - V_59 ;
}
F_36 ( V_62 , V_47 ) ;
return F_37 ( V_62 , V_47 ) ;
}
static struct V_52 * F_38 ( struct V_61 * V_62 )
{
struct V_1 * V_7 = F_32 ( V_62 ) ;
return V_7 -> V_53 ;
}
static int F_39 ( struct V_2 * V_4 ,
struct V_52 * V_53 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_61 * V_62 = & V_7 -> V_62 ;
int V_45 ;
V_7 -> V_53 = V_53 ;
V_62 -> V_71 = V_72 ;
V_45 = F_40 ( V_7 -> V_31 , V_62 ,
& V_73 , V_74 ) ;
if ( V_45 ) {
F_41 ( L_15 ) ;
return V_45 ;
}
F_42 ( V_62 , & V_75 ) ;
F_43 ( V_62 ) ;
F_44 ( V_62 , V_53 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_38 , struct V_37 * V_76 , void * V_49 )
{
struct V_1 * V_7 = F_21 ( V_38 ) ;
struct V_30 * V_31 = V_49 ;
struct V_15 * V_77 ;
enum V_78 type ;
unsigned int V_79 ;
int V_45 ;
F_15 ( V_7 , V_31 ) ;
for ( V_79 = 0 ; V_79 < V_17 ; V_79 ++ ) {
type = ( V_79 == V_7 -> V_80 ) ? V_81 :
V_82 ;
V_45 = F_46 ( V_31 , & V_7 -> V_18 [ V_79 ] ,
1 << V_7 -> V_35 , type , V_79 ) ;
if ( V_45 )
return V_45 ;
}
V_77 = & V_7 -> V_18 [ V_7 -> V_80 ] ;
V_7 -> V_6 = F_47 ( V_31 , & V_77 -> V_83 ,
V_7 -> V_35 , V_57 ,
& V_84 , V_7 ) ;
if ( F_48 ( V_7 -> V_6 ) ) {
F_41 ( L_16 ) ;
return F_49 ( V_7 -> V_6 ) ;
}
V_45 = F_50 ( V_31 , & V_7 -> V_4 ) ;
if ( V_45 ) {
V_7 -> V_6 -> V_83 . V_85 -> V_86 ( & V_7 -> V_6 -> V_83 ) ;
return V_45 ;
}
return 0 ;
}
static void F_51 ( struct V_37 * V_38 , struct V_37 * V_76 , void * V_49 )
{
}
static int F_52 ( struct V_87 * V_88 )
{
struct V_1 * V_7 ;
int V_45 ;
V_7 = F_53 ( & V_88 -> V_38 , sizeof( * V_7 ) , V_70 ) ;
if ( ! V_7 )
return - V_59 ;
V_7 -> V_4 . type = V_57 ;
V_7 -> V_4 . V_89 = & V_90 ;
V_7 -> V_80 = 0 ;
V_7 -> V_88 = V_88 ;
V_45 = F_54 ( & V_88 -> V_38 , V_91 ,
V_57 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_54 ( & V_88 -> V_38 , V_92 ,
V_7 -> V_4 . type ) ;
if ( V_45 )
goto V_93;
F_55 ( & V_7 -> V_13 , F_16 ) ;
F_56 ( & V_7 -> V_25 ) ;
F_57 ( V_88 , V_7 ) ;
V_45 = F_58 ( & V_88 -> V_38 , & V_94 ) ;
if ( V_45 < 0 ) {
F_41 ( L_17 ) ;
goto V_95;
}
V_45 = F_59 ( & V_88 -> V_38 , & V_96 ) ;
if ( V_45 )
goto V_97;
return V_45 ;
V_97:
F_60 ( & V_88 -> V_38 , & V_94 ) ;
V_95:
F_61 ( & V_88 -> V_38 , V_92 ) ;
V_93:
F_61 ( & V_88 -> V_38 , V_91 ) ;
return V_45 ;
}
static int F_62 ( struct V_87 * V_88 )
{
struct V_1 * V_7 = F_63 ( V_88 ) ;
if ( V_7 -> V_46 != (struct V_47 * ) V_48 ) {
F_30 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
return - V_23 ;
}
F_64 ( & V_88 -> V_38 , & V_96 ) ;
F_61 ( & V_88 -> V_38 , V_92 ) ;
F_61 ( & V_88 -> V_38 , V_91 ) ;
return 0 ;
}
int F_65 ( void )
{
struct V_87 * V_88 ;
int V_45 ;
V_88 = F_66 ( L_18 , - 1 , NULL , 0 ) ;
if ( F_48 ( V_88 ) )
return F_49 ( V_88 ) ;
V_45 = F_67 ( & V_98 ) ;
if ( V_45 ) {
F_68 ( V_88 ) ;
return V_45 ;
}
return V_45 ;
}
static int F_69 ( struct V_37 * V_38 , void * V_49 )
{
F_68 ( F_70 ( V_38 ) ) ;
return 0 ;
}
void F_71 ( void )
{
int V_45 = F_72 ( & V_98 . V_99 , NULL , NULL ,
F_69 ) ;
( void ) V_45 ;
F_73 ( & V_98 ) ;
}
