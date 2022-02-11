static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ? true : false ;
}
static struct V_6 * F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_6 ;
if ( ! V_4 -> V_9 ) {
F_4 ( L_1 ) ;
return F_5 ( - V_10 ) ;
}
V_6 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
return F_5 ( - V_11 ) ;
}
return V_6 ;
}
static void * F_7 ( struct V_1 * V_2 )
{
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_13 )
{
return 0 ;
}
static void F_10 ( struct V_1 * V_14 , int V_13 )
{
struct V_3 * V_4 = F_2 ( V_14 ) ;
F_4 ( L_3 , V_13 ) ;
F_11 ( & V_4 -> V_15 ) ;
switch ( V_13 ) {
case V_16 :
break;
case V_17 :
case V_18 :
case V_19 :
break;
default:
F_4 ( L_4 , V_13 ) ;
break;
}
F_12 ( & V_4 -> V_15 ) ;
}
static void F_13 ( struct V_1 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_14 ) ;
struct V_20 * V_21 = V_4 -> V_22 . V_23 ;
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_27 * V_28 = V_21 -> V_29 ;
struct V_30 * V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 = & V_4 -> V_31 [ V_32 ] ;
if ( V_31 -> V_34 && ( V_28 && V_28 -> V_35 ) )
V_28 -> V_35 ( V_14 , V_32 ) ;
}
if ( V_25 && V_25 -> V_35 )
V_25 -> V_35 ( V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 )
return;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 )
return - V_37 ;
if ( ! F_16 ( 0 , & V_4 -> V_38 ) )
V_4 -> V_39 = true ;
V_4 -> V_40 = true ;
F_17 ( & V_4 -> V_41 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 )
return;
if ( F_19 ( 0 , & V_4 -> V_38 ) )
V_4 -> V_39 = false ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
int V_44 ;
unsigned long V_45 ;
if ( ! V_43 ) {
F_21 ( V_2 , L_5 ) ;
return;
}
V_44 = V_43 -> V_46 ;
if ( V_44 == V_47 )
V_44 = V_4 -> V_48 ;
if ( V_44 < 0 || V_44 >= V_33 )
return;
V_45 = V_43 -> V_49 * ( V_43 -> V_50 >> 3 ) ;
V_45 += V_43 -> V_51 * V_43 -> V_52 ;
F_4 ( L_6 , V_45 , V_43 -> V_52 ) ;
V_31 = & V_4 -> V_31 [ V_44 ] ;
V_31 -> V_53 = V_43 -> V_54 ;
V_31 -> V_55 = V_43 -> V_56 ;
V_31 -> V_57 = V_43 -> V_58 ;
V_31 -> V_59 = V_43 -> V_60 ;
V_31 -> V_61 = V_43 -> V_61 ;
V_31 -> V_62 = V_43 -> V_62 ;
V_31 -> V_63 = V_43 -> V_63 [ 0 ] + V_45 ;
V_31 -> V_50 = V_43 -> V_50 ;
V_31 -> V_64 = ( V_43 -> V_61 - V_43 -> V_58 ) *
( V_43 -> V_50 >> 3 ) ;
V_31 -> V_65 = V_43 -> V_58 * ( V_43 -> V_50 >> 3 ) ;
F_4 ( L_7 ,
V_31 -> V_53 , V_31 -> V_55 ) ;
F_4 ( L_8 ,
V_31 -> V_57 , V_31 -> V_59 ) ;
F_4 ( L_9 , ( unsigned long ) V_31 -> V_63 ) ;
F_4 ( L_10 ,
V_43 -> V_61 , V_43 -> V_58 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
int V_44 = V_46 ;
if ( V_4 -> V_36 )
return;
if ( V_44 == V_47 )
V_44 = V_4 -> V_48 ;
if ( V_44 < 0 || V_44 >= V_33 )
return;
V_31 = & V_4 -> V_31 [ V_44 ] ;
V_31 -> V_34 = true ;
F_4 ( L_11 , V_31 -> V_63 ) ;
if ( V_4 -> V_39 )
F_17 ( & V_4 -> V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
int V_44 = V_46 ;
if ( V_44 == V_47 )
V_44 = V_4 -> V_48 ;
if ( V_44 < 0 || V_44 >= V_33 )
return;
V_31 = & V_4 -> V_31 [ V_44 ] ;
V_31 -> V_34 = false ;
}
static void F_24 ( struct V_66 * V_41 )
{
struct V_3 * V_4 = F_25 ( V_41 , struct V_3 ,
V_41 ) ;
struct V_67 * V_22 = & V_4 -> V_22 ;
struct V_20 * V_23 = V_22 -> V_23 ;
if ( V_23 -> V_68 < 0 )
return;
F_26 ( 16000 , 20000 ) ;
F_11 ( & V_4 -> V_15 ) ;
if ( V_4 -> V_40 ) {
F_27 ( V_22 -> V_69 , V_23 -> V_68 ) ;
V_4 -> V_40 = false ;
F_12 ( & V_4 -> V_15 ) ;
return;
}
F_12 ( & V_4 -> V_15 ) ;
F_28 ( V_22 -> V_69 , V_23 -> V_68 ) ;
}
static int F_29 ( struct V_70 * V_69 , struct V_1 * V_2 )
{
V_69 -> V_71 = true ;
V_69 -> V_72 = true ;
return 0 ;
}
static void F_30 ( struct V_70 * V_69 , struct V_1 * V_2 )
{
}
static int F_31 ( struct V_3 * V_4 , bool V_73 )
{
struct V_67 * V_22 = & V_4 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_2 ;
if ( V_73 ) {
V_4 -> V_36 = false ;
if ( F_19 ( 0 , & V_4 -> V_38 ) )
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
} else {
V_4 -> V_36 = true ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_74 * V_75 , char * V_76 )
{
int V_77 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( & V_4 -> V_15 ) ;
V_77 = sprintf ( V_76 , L_3 , V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_15 ) ;
return V_77 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
const char * V_76 , T_1 V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_79 ;
V_79 = F_34 ( V_76 , 0 , & V_4 -> V_5 ) ;
if ( V_79 )
return V_79 ;
if ( V_4 -> V_5 > 1 )
return - V_80 ;
if ( ! V_4 -> V_9 )
V_4 -> V_9 = (struct V_6 * ) V_81 ;
if ( V_4 -> V_9 != (struct V_6 * ) V_81 ) {
F_4 ( L_12 ) ;
return - V_80 ;
}
F_4 ( L_13 ) ;
F_35 ( V_4 -> V_22 . V_69 ) ;
return V_78 ;
}
int F_36 ( struct V_70 * V_69 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_3 * V_4 = NULL ;
struct V_85 * V_86 ;
struct V_20 * V_23 ;
struct V_87 * V_88 ;
struct V_89 * V_90 = V_82 ;
if ( ! V_90 ) {
F_4 ( L_14 ) ;
return - V_80 ;
}
if ( V_90 -> V_91 > 1 ) {
F_4 ( L_15 ) ;
return - V_80 ;
}
F_37 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_23 = F_38 ( V_86 ) ;
V_88 = V_23 -> V_88 ;
if ( V_88 -> type == V_92 ) {
V_4 = F_2 ( V_23 -> V_2 ) ;
break;
}
}
if ( ! V_4 ) {
F_4 ( L_16 ) ;
return - V_80 ;
}
if ( V_4 -> V_5 == V_90 -> V_91 ) {
F_4 ( L_17 ) ;
return - V_80 ;
}
if ( V_90 -> V_91 ) {
struct V_6 * V_9 = (struct V_6 * ) ( V_93 ) V_90 -> V_6 ;
if ( ! F_39 ( V_9 ) ) {
F_4 ( L_18 ) ;
return - V_80 ;
}
V_4 -> V_9 = F_6 ( V_9 ) ;
if ( ! V_4 -> V_9 ) {
F_4 ( L_19 ) ;
return - V_11 ;
}
} else {
if ( V_4 -> V_9 && V_4 -> V_9 !=
(struct V_6 * ) V_81 ) {
F_40 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
}
V_4 -> V_5 = V_90 -> V_91 ;
F_35 ( V_4 -> V_22 . V_69 ) ;
return 0 ;
}
static int F_41 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = & V_95 -> V_2 ;
struct V_3 * V_4 ;
struct V_67 * V_22 ;
int V_79 ;
V_4 = F_42 ( V_2 , sizeof( * V_4 ) , V_96 ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_48 = 0 ;
F_43 ( & V_4 -> V_41 , F_24 ) ;
V_22 = & V_4 -> V_22 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_23 = & V_97 ;
V_22 -> V_98 = F_29 ;
V_22 -> remove = F_30 ;
F_44 ( & V_4 -> V_15 ) ;
F_45 ( V_95 , V_4 ) ;
V_79 = F_46 ( V_2 , & V_99 ) ;
if ( V_79 < 0 )
F_47 ( L_20 ) ;
F_48 ( V_22 ) ;
return 0 ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_50 ( V_95 ) ;
F_51 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_9 != (struct V_6 * ) V_81 ) {
F_40 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
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
