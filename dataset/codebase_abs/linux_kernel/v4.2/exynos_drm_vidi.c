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
F_9 ( L_1 , V_16 -> V_19 ) ;
if ( V_7 -> V_11 )
F_5 ( & V_7 -> V_13 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_11 ( & V_7 -> V_20 ) ;
V_7 -> V_8 = false ;
if ( F_7 ( 0 , & V_7 -> V_10 ) )
F_3 ( V_7 -> V_6 ) ;
F_12 ( & V_7 -> V_20 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_7 ;
F_11 ( & V_7 -> V_20 ) ;
V_7 -> V_8 = true ;
F_12 ( & V_7 -> V_20 ) ;
}
static int F_14 ( struct V_1 * V_7 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 ;
V_7 -> V_22 = V_22 ;
V_7 -> V_26 = V_24 -> V_26 ++ ;
return 0 ;
}
static void F_15 ( struct V_27 * V_13 )
{
struct V_1 * V_7 = F_2 ( V_13 , struct V_1 ,
V_13 ) ;
if ( V_7 -> V_26 < 0 )
return;
F_16 ( 16000 , 20000 ) ;
F_11 ( & V_7 -> V_20 ) ;
if ( V_7 -> V_12 ) {
F_17 ( V_7 -> V_22 , V_7 -> V_26 ) ;
V_7 -> V_12 = false ;
F_12 ( & V_7 -> V_20 ) ;
return;
}
F_12 ( & V_7 -> V_20 ) ;
F_18 ( V_7 -> V_22 , V_7 -> V_26 ) ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
int V_33 ;
F_11 ( & V_7 -> V_20 ) ;
V_33 = sprintf ( V_32 , L_2 , V_7 -> V_34 ) ;
F_12 ( & V_7 -> V_20 ) ;
return V_33 ;
}
static int F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 , T_1 V_35 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
int V_36 ;
V_36 = F_22 ( V_32 , 0 , & V_7 -> V_34 ) ;
if ( V_36 )
return V_36 ;
if ( V_7 -> V_34 > 1 )
return - V_37 ;
if ( ! V_7 -> V_38 )
V_7 -> V_38 = (struct V_39 * ) V_40 ;
if ( V_7 -> V_38 != (struct V_39 * ) V_40 ) {
F_9 ( L_3 ) ;
return - V_37 ;
}
F_9 ( L_4 ) ;
F_23 ( V_7 -> V_22 ) ;
return V_35 ;
}
int F_24 ( struct V_21 * V_22 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_7 = NULL ;
struct V_44 * V_45 ;
struct V_2 * V_4 ;
struct V_46 * V_47 = V_41 ;
if ( ! V_47 ) {
F_9 ( L_5 ) ;
return - V_37 ;
}
if ( V_47 -> V_48 > 1 ) {
F_9 ( L_6 ) ;
return - V_37 ;
}
F_25 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_4 = F_26 ( V_45 ) ;
if ( V_4 -> type == V_49 ) {
V_7 = F_1 ( V_4 ) ;
break;
}
}
if ( ! V_7 ) {
F_9 ( L_7 ) ;
return - V_37 ;
}
if ( V_7 -> V_34 == V_47 -> V_48 ) {
F_9 ( L_8 ) ;
return - V_37 ;
}
if ( V_47 -> V_48 ) {
struct V_39 * V_38 = (struct V_39 * ) ( V_50 ) V_47 -> V_39 ;
if ( ! F_27 ( V_38 ) ) {
F_9 ( L_9 ) ;
return - V_37 ;
}
V_7 -> V_38 = F_28 ( V_38 ) ;
if ( ! V_7 -> V_38 ) {
F_9 ( L_10 ) ;
return - V_51 ;
}
} else {
if ( V_7 -> V_38 && V_7 -> V_38 !=
(struct V_39 * ) V_40 ) {
F_29 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
}
}
V_7 -> V_34 = V_47 -> V_48 ;
F_23 ( V_7 -> V_22 ) ;
return 0 ;
}
static enum V_52 F_30 ( struct V_53 * V_54 ,
bool V_55 )
{
struct V_1 * V_7 = F_31 ( V_54 ) ;
return V_7 -> V_34 ? V_56 :
V_57 ;
}
static void F_32 ( struct V_53 * V_54 )
{
}
static int F_33 ( struct V_53 * V_54 )
{
struct V_1 * V_7 = F_31 ( V_54 ) ;
struct V_39 * V_39 ;
int V_58 ;
if ( ! V_7 -> V_38 ) {
F_9 ( L_11 ) ;
return - V_59 ;
}
V_58 = ( 1 + V_7 -> V_38 -> V_60 ) * V_61 ;
V_39 = F_34 ( V_7 -> V_38 , V_58 , V_62 ) ;
if ( ! V_39 ) {
F_9 ( L_12 ) ;
return - V_51 ;
}
F_35 ( V_54 , V_39 ) ;
return F_36 ( V_54 , V_39 ) ;
}
static struct V_44 * F_37 ( struct V_53 * V_54 )
{
struct V_1 * V_7 = F_31 ( V_54 ) ;
return V_7 -> V_45 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_44 * V_45 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
struct V_53 * V_54 = & V_7 -> V_54 ;
int V_36 ;
V_7 -> V_45 = V_45 ;
V_54 -> V_63 = V_64 ;
V_36 = F_39 ( V_7 -> V_22 , V_54 ,
& V_65 , V_66 ) ;
if ( V_36 ) {
F_40 ( L_13 ) ;
return V_36 ;
}
F_41 ( V_54 , & V_67 ) ;
F_42 ( V_54 ) ;
F_43 ( V_54 , V_45 ) ;
return 0 ;
}
static int F_44 ( struct V_28 * V_29 , struct V_28 * V_68 , void * V_41 )
{
struct V_1 * V_7 = F_20 ( V_29 ) ;
struct V_21 * V_22 = V_41 ;
struct V_15 * V_69 ;
enum V_70 type ;
unsigned int V_71 ;
int V_36 ;
F_14 ( V_7 , V_22 ) ;
for ( V_71 = 0 ; V_71 < V_17 ; V_71 ++ ) {
type = ( V_71 == V_7 -> V_72 ) ? V_73 :
V_74 ;
V_36 = F_45 ( V_22 , & V_7 -> V_18 [ V_71 ] ,
1 << V_7 -> V_26 , type , V_71 ) ;
if ( V_36 )
return V_36 ;
}
V_69 = & V_7 -> V_18 [ V_7 -> V_72 ] ;
V_7 -> V_6 = F_46 ( V_22 , & V_69 -> V_75 ,
V_7 -> V_26 , V_49 ,
& V_76 , V_7 ) ;
if ( F_47 ( V_7 -> V_6 ) ) {
F_40 ( L_14 ) ;
return F_48 ( V_7 -> V_6 ) ;
}
V_36 = F_49 ( V_22 , & V_7 -> V_4 ) ;
if ( V_36 ) {
V_7 -> V_6 -> V_75 . V_77 -> V_78 ( & V_7 -> V_6 -> V_75 ) ;
return V_36 ;
}
return 0 ;
}
static void F_50 ( struct V_28 * V_29 , struct V_28 * V_68 , void * V_41 )
{
}
static int F_51 ( struct V_79 * V_80 )
{
struct V_1 * V_7 ;
int V_36 ;
V_7 = F_52 ( & V_80 -> V_29 , sizeof( * V_7 ) , V_62 ) ;
if ( ! V_7 )
return - V_51 ;
V_7 -> V_4 . type = V_49 ;
V_7 -> V_4 . V_81 = & V_82 ;
V_7 -> V_72 = 0 ;
V_7 -> V_80 = V_80 ;
F_53 ( & V_7 -> V_13 , F_15 ) ;
F_54 ( & V_7 -> V_20 ) ;
F_55 ( V_80 , V_7 ) ;
V_36 = F_56 ( & V_80 -> V_29 , & V_83 ) ;
if ( V_36 < 0 ) {
F_40 ( L_15 ) ;
return V_36 ;
}
V_36 = F_57 ( & V_80 -> V_29 , & V_84 ) ;
if ( V_36 )
goto V_85;
return V_36 ;
V_85:
F_58 ( & V_80 -> V_29 , & V_83 ) ;
return V_36 ;
}
static int F_59 ( struct V_79 * V_80 )
{
struct V_1 * V_7 = F_60 ( V_80 ) ;
if ( V_7 -> V_38 != (struct V_39 * ) V_40 ) {
F_29 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
return - V_37 ;
}
F_61 ( & V_80 -> V_29 , & V_84 ) ;
return 0 ;
}
