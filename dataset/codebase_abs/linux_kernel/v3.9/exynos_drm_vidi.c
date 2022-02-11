static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
return V_4 -> V_5 ? true : false ;
}
static struct V_6 * F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_6 ;
int V_9 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_2 ) ;
return F_5 ( - V_11 ) ;
}
V_9 = ( 1 + V_4 -> V_10 -> V_12 ) * V_13 ;
V_6 = F_6 ( V_4 -> V_10 , V_9 , V_14 ) ;
if ( ! V_6 ) {
F_3 ( L_3 ) ;
return F_5 ( - V_15 ) ;
}
return V_6 ;
}
static void * F_7 ( struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , void * V_16 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_17 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_18 , int V_17 )
{
struct V_3 * V_4 = F_2 ( V_18 ) ;
F_3 ( L_4 , __FILE__ , V_17 ) ;
F_11 ( & V_4 -> V_19 ) ;
switch ( V_17 ) {
case V_20 :
break;
case V_21 :
case V_22 :
case V_23 :
break;
default:
F_3 ( L_5 , V_17 ) ;
break;
}
F_12 ( & V_4 -> V_19 ) ;
}
static void F_13 ( struct V_1 * V_18 )
{
struct V_3 * V_4 = F_2 ( V_18 ) ;
struct V_24 * V_25 = V_4 -> V_26 . V_27 ;
struct V_28 * V_29 = V_25 -> V_30 ;
struct V_31 * V_32 = V_25 -> V_33 ;
struct V_34 * V_35 ;
int V_36 ;
F_3 ( L_1 , __FILE__ ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_35 = & V_4 -> V_35 [ V_36 ] ;
if ( V_35 -> V_38 && ( V_32 && V_32 -> V_39 ) )
V_32 -> V_39 ( V_18 , V_36 ) ;
}
if ( V_29 && V_29 -> V_39 )
V_29 -> V_39 ( V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_40 )
return;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_40 )
return - V_41 ;
if ( ! F_16 ( 0 , & V_4 -> V_42 ) )
V_4 -> V_43 = true ;
V_4 -> V_44 = true ;
F_17 ( & V_4 -> V_45 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_40 )
return;
if ( F_19 ( 0 , & V_4 -> V_42 ) )
V_4 -> V_43 = false ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
int V_48 ;
unsigned long V_49 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_47 ) {
F_21 ( V_2 , L_6 ) ;
return;
}
V_48 = V_47 -> V_50 ;
if ( V_48 == V_51 )
V_48 = V_4 -> V_52 ;
if ( V_48 < 0 || V_48 > V_37 )
return;
V_49 = V_47 -> V_53 * ( V_47 -> V_54 >> 3 ) ;
V_49 += V_47 -> V_55 * V_47 -> V_56 ;
F_3 ( L_7 , V_49 , V_47 -> V_56 ) ;
V_35 = & V_4 -> V_35 [ V_48 ] ;
V_35 -> V_57 = V_47 -> V_58 ;
V_35 -> V_59 = V_47 -> V_60 ;
V_35 -> V_61 = V_47 -> V_62 ;
V_35 -> V_63 = V_47 -> V_64 ;
V_35 -> V_65 = V_47 -> V_65 ;
V_35 -> V_66 = V_47 -> V_66 ;
V_35 -> V_67 = V_47 -> V_67 [ 0 ] + V_49 ;
V_35 -> V_54 = V_47 -> V_54 ;
V_35 -> V_68 = ( V_47 -> V_65 - V_47 -> V_62 ) *
( V_47 -> V_54 >> 3 ) ;
V_35 -> V_69 = V_47 -> V_62 * ( V_47 -> V_54 >> 3 ) ;
F_3 ( L_8 ,
V_35 -> V_57 , V_35 -> V_59 ) ;
F_3 ( L_9 ,
V_35 -> V_61 , V_35 -> V_63 ) ;
F_3 ( L_10 , ( unsigned long ) V_35 -> V_67 ) ;
F_3 ( L_11 ,
V_47 -> V_65 , V_47 -> V_62 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
int V_48 = V_50 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_40 )
return;
if ( V_48 == V_51 )
V_48 = V_4 -> V_52 ;
if ( V_48 < 0 || V_48 > V_37 )
return;
V_35 = & V_4 -> V_35 [ V_48 ] ;
V_35 -> V_38 = true ;
F_3 ( L_12 , V_35 -> V_67 ) ;
if ( V_4 -> V_43 )
F_17 ( & V_4 -> V_45 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
int V_48 = V_50 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_48 == V_51 )
V_48 = V_4 -> V_52 ;
if ( V_48 < 0 || V_48 > V_37 )
return;
V_35 = & V_4 -> V_35 [ V_48 ] ;
V_35 -> V_38 = false ;
}
static void F_24 ( struct V_70 * V_45 )
{
struct V_3 * V_4 = F_25 ( V_45 , struct V_3 ,
V_45 ) ;
struct V_71 * V_26 = & V_4 -> V_26 ;
struct V_24 * V_27 = V_26 -> V_27 ;
if ( V_27 -> V_72 < 0 )
return;
F_26 ( 16000 , 20000 ) ;
F_11 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_44 ) {
F_27 ( V_26 -> V_73 , V_27 -> V_72 ) ;
V_4 -> V_44 = false ;
F_12 ( & V_4 -> V_19 ) ;
return;
}
F_12 ( & V_4 -> V_19 ) ;
F_28 ( V_26 -> V_73 , V_27 -> V_72 ) ;
}
static int F_29 ( struct V_74 * V_73 , struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
V_73 -> V_75 = 1 ;
V_73 -> V_76 = 1 ;
return 0 ;
}
static void F_30 ( struct V_74 * V_73 , struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
}
static int F_31 ( struct V_3 * V_4 , bool V_77 )
{
struct V_71 * V_26 = & V_4 -> V_26 ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_77 != false && V_77 != true )
return - V_78 ;
if ( V_77 ) {
V_4 -> V_40 = false ;
if ( F_19 ( 0 , & V_4 -> V_42 ) )
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
} else {
V_4 -> V_40 = true ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_79 * V_80 , char * V_81 )
{
int V_82 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( & V_4 -> V_19 ) ;
V_82 = sprintf ( V_81 , L_13 , V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_19 ) ;
return V_82 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
const char * V_81 , T_1 V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_84 ;
F_3 ( L_1 , __FILE__ ) ;
V_84 = F_34 ( V_81 , 0 , & V_4 -> V_5 ) ;
if ( V_84 )
return V_84 ;
if ( V_4 -> V_5 > 1 )
return - V_78 ;
if ( ! V_4 -> V_10 )
V_4 -> V_10 = (struct V_6 * ) V_85 ;
if ( V_4 -> V_10 != (struct V_6 * ) V_85 ) {
F_3 ( L_14 ) ;
return - V_78 ;
}
F_3 ( L_15 ) ;
F_35 ( V_4 -> V_26 . V_73 ) ;
return V_83 ;
}
int F_36 ( struct V_74 * V_73 , void * V_86 ,
struct V_87 * V_88 )
{
struct V_3 * V_4 = NULL ;
struct V_89 * V_90 ;
struct V_24 * V_27 ;
struct V_91 * V_92 ;
struct V_93 * V_94 = V_86 ;
int V_9 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_94 ) {
F_3 ( L_16 ) ;
return - V_78 ;
}
if ( V_94 -> V_95 > 1 ) {
F_3 ( L_17 ) ;
return - V_78 ;
}
F_37 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_27 = F_38 ( V_90 ) ;
V_92 = V_27 -> V_92 ;
if ( V_92 -> type == V_96 ) {
V_4 = F_2 ( V_27 -> V_2 ) ;
break;
}
}
if ( ! V_4 ) {
F_3 ( L_18 ) ;
return - V_78 ;
}
if ( V_4 -> V_5 == V_94 -> V_95 ) {
F_3 ( L_19 ) ;
return - V_78 ;
}
if ( V_94 -> V_95 ) {
struct V_6 * V_10 = (struct V_6 * ) ( V_97 ) V_94 -> V_6 ;
if ( ! F_39 ( V_10 ) ) {
F_3 ( L_20 ) ;
return - V_78 ;
}
V_9 = ( 1 + V_10 -> V_12 ) * V_13 ;
V_4 -> V_10 = F_6 ( V_10 , V_9 , V_14 ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_21 ) ;
return - V_15 ;
}
} else {
if ( V_4 -> V_10 && V_4 -> V_10 !=
(struct V_6 * ) V_85 ) {
F_40 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
}
V_4 -> V_5 = V_94 -> V_95 ;
F_35 ( V_4 -> V_26 . V_73 ) ;
return 0 ;
}
static int F_41 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = & V_99 -> V_2 ;
struct V_3 * V_4 ;
struct V_71 * V_26 ;
int V_84 ;
F_3 ( L_1 , __FILE__ ) ;
V_4 = F_42 ( & V_99 -> V_2 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_52 = 0 ;
F_43 ( & V_4 -> V_45 , F_24 ) ;
V_26 = & V_4 -> V_26 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_27 = & V_100 ;
V_26 -> V_101 = F_29 ;
V_26 -> remove = F_30 ;
F_44 ( & V_4 -> V_19 ) ;
F_45 ( V_99 , V_4 ) ;
V_84 = F_46 ( & V_99 -> V_2 , & V_102 ) ;
if ( V_84 < 0 )
F_47 ( L_22 ) ;
F_48 ( V_26 ) ;
return 0 ;
}
static int F_49 ( struct V_98 * V_99 )
{
struct V_3 * V_4 = F_50 ( V_99 ) ;
F_3 ( L_1 , __FILE__ ) ;
F_51 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_10 != (struct V_6 * ) V_85 ) {
F_40 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_31 ( V_4 , false ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_31 ( V_4 , true ) ;
}
