static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_9 = & V_4 -> V_9 [ V_10 ] ;
if ( V_9 -> V_12 && ( V_6 && V_6 -> V_13 ) )
V_6 -> V_13 ( V_2 , V_10 ) ;
}
if ( V_6 && V_6 -> V_14 )
V_6 -> V_14 ( V_2 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_15 )
return;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_15 )
return - V_16 ;
if ( ! F_4 ( 0 , & V_4 -> V_17 ) )
V_4 -> V_18 = true ;
V_4 -> V_19 = true ;
F_5 ( & V_4 -> V_20 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_15 )
return;
if ( F_7 ( 0 , & V_4 -> V_17 ) )
V_4 -> V_18 = false ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
int V_23 ;
unsigned long V_24 ;
if ( ! V_22 ) {
F_9 ( L_1 ) ;
return;
}
V_23 = V_22 -> V_25 ;
if ( V_23 == V_26 )
V_23 = V_4 -> V_27 ;
if ( V_23 < 0 || V_23 >= V_11 )
return;
V_24 = V_22 -> V_28 * ( V_22 -> V_29 >> 3 ) ;
V_24 += V_22 -> V_30 * V_22 -> V_31 ;
F_10 ( L_2 , V_24 , V_22 -> V_31 ) ;
V_9 = & V_4 -> V_9 [ V_23 ] ;
V_9 -> V_32 = V_22 -> V_33 ;
V_9 -> V_34 = V_22 -> V_35 ;
V_9 -> V_36 = V_22 -> V_37 ;
V_9 -> V_38 = V_22 -> V_39 ;
V_9 -> V_40 = V_22 -> V_40 ;
V_9 -> V_41 = V_22 -> V_41 ;
V_9 -> V_42 = V_22 -> V_42 [ 0 ] + V_24 ;
V_9 -> V_29 = V_22 -> V_29 ;
V_9 -> V_43 = ( V_22 -> V_40 - V_22 -> V_37 ) *
( V_22 -> V_29 >> 3 ) ;
V_9 -> V_44 = V_22 -> V_37 * ( V_22 -> V_29 >> 3 ) ;
F_10 ( L_3 ,
V_9 -> V_32 , V_9 -> V_34 ) ;
F_10 ( L_4 ,
V_9 -> V_36 , V_9 -> V_38 ) ;
F_10 ( L_5 , ( unsigned long ) V_9 -> V_42 ) ;
F_10 ( L_6 ,
V_22 -> V_40 , V_22 -> V_37 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
int V_23 = V_25 ;
if ( V_4 -> V_15 )
return;
if ( V_23 == V_26 )
V_23 = V_4 -> V_27 ;
if ( V_23 < 0 || V_23 >= V_11 )
return;
V_9 = & V_4 -> V_9 [ V_23 ] ;
V_9 -> V_12 = true ;
F_10 ( L_7 , & V_9 -> V_42 ) ;
if ( V_4 -> V_18 )
F_5 ( & V_4 -> V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
int V_23 = V_25 ;
if ( V_23 == V_26 )
V_23 = V_4 -> V_27 ;
if ( V_23 < 0 || V_23 >= V_11 )
return;
V_9 = & V_4 -> V_9 [ V_23 ] ;
V_9 -> V_12 = false ;
}
static int F_13 ( struct V_1 * V_2 , bool V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_10 ( L_8 , __FILE__ ) ;
if ( V_45 != false && V_45 != true )
return - V_46 ;
if ( V_45 ) {
V_4 -> V_15 = false ;
if ( F_7 ( 0 , & V_4 -> V_17 ) )
F_3 ( V_2 ) ;
F_1 ( V_2 ) ;
} else {
V_4 -> V_15 = true ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_47 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_10 ( L_9 , V_47 ) ;
F_15 ( & V_4 -> V_48 ) ;
switch ( V_47 ) {
case V_49 :
F_13 ( V_2 , true ) ;
break;
case V_50 :
case V_51 :
case V_52 :
F_13 ( V_2 , false ) ;
break;
default:
F_10 ( L_10 , V_47 ) ;
break;
}
F_16 ( & V_4 -> V_48 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_53 * V_54 , int V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_9 ( L_11 , V_4 , V_54 , V_55 ) ;
V_4 -> V_54 = V_54 ;
V_4 -> V_55 = V_55 ;
V_54 -> V_56 = 1 ;
V_54 -> V_57 = 1 ;
return 0 ;
}
static void F_18 ( struct V_58 * V_20 )
{
struct V_3 * V_4 = F_19 ( V_20 , struct V_3 ,
V_20 ) ;
if ( V_4 -> V_55 < 0 )
return;
F_20 ( 16000 , 20000 ) ;
F_15 ( & V_4 -> V_48 ) ;
if ( V_4 -> V_19 ) {
F_21 ( V_4 -> V_54 , V_4 -> V_55 ) ;
V_4 -> V_19 = false ;
F_16 ( & V_4 -> V_48 ) ;
return;
}
F_16 ( & V_4 -> V_48 ) ;
F_22 ( V_4 -> V_54 , V_4 -> V_55 ) ;
}
static int F_23 ( struct V_59 * V_60 ,
struct V_61 * V_62 , char * V_63 )
{
int V_64 ;
struct V_1 * V_2 = F_24 ( V_60 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_15 ( & V_4 -> V_48 ) ;
V_64 = sprintf ( V_63 , L_9 , V_4 -> V_65 ) ;
F_16 ( & V_4 -> V_48 ) ;
return V_64 ;
}
static int F_25 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
const char * V_63 , T_1 V_66 )
{
struct V_1 * V_2 = F_24 ( V_60 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_67 ;
V_67 = F_26 ( V_63 , 0 , & V_4 -> V_65 ) ;
if ( V_67 )
return V_67 ;
if ( V_4 -> V_65 > 1 )
return - V_46 ;
if ( ! V_4 -> V_68 )
V_4 -> V_68 = (struct V_69 * ) V_70 ;
if ( V_4 -> V_68 != (struct V_69 * ) V_70 ) {
F_10 ( L_12 ) ;
return - V_46 ;
}
F_10 ( L_13 ) ;
F_27 ( V_4 -> V_54 ) ;
return V_66 ;
}
int F_28 ( struct V_53 * V_54 , void * V_71 ,
struct V_72 * V_73 )
{
struct V_3 * V_4 = NULL ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 = V_71 ;
if ( ! V_79 ) {
F_10 ( L_14 ) ;
return - V_46 ;
}
if ( V_79 -> V_80 > 1 ) {
F_10 ( L_15 ) ;
return - V_46 ;
}
F_29 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_77 = F_30 ( V_75 ) ;
if ( V_77 -> type == V_81 ) {
V_4 = V_77 -> V_4 ;
break;
}
}
if ( ! V_4 ) {
F_10 ( L_16 ) ;
return - V_46 ;
}
if ( V_4 -> V_65 == V_79 -> V_80 ) {
F_10 ( L_17 ) ;
return - V_46 ;
}
if ( V_79 -> V_80 ) {
struct V_69 * V_68 = (struct V_69 * ) ( V_82 ) V_79 -> V_69 ;
if ( ! F_31 ( V_68 ) ) {
F_10 ( L_18 ) ;
return - V_46 ;
}
V_4 -> V_68 = F_32 ( V_68 ) ;
if ( ! V_4 -> V_68 ) {
F_10 ( L_19 ) ;
return - V_83 ;
}
} else {
if ( V_4 -> V_68 && V_4 -> V_68 !=
(struct V_69 * ) V_70 ) {
F_33 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
}
}
V_4 -> V_65 = V_79 -> V_80 ;
F_27 ( V_4 -> V_54 ) ;
return 0 ;
}
static enum V_84 F_34 ( struct V_85 * V_86 ,
bool V_87 )
{
struct V_3 * V_4 = F_35 ( V_86 ) ;
return V_4 -> V_65 ? V_88 :
V_89 ;
}
static void F_36 ( struct V_85 * V_86 )
{
}
static int F_37 ( struct V_85 * V_86 )
{
struct V_3 * V_4 = F_35 ( V_86 ) ;
struct V_69 * V_69 ;
int V_90 ;
if ( ! V_4 -> V_68 ) {
F_10 ( L_20 ) ;
return - V_91 ;
}
V_90 = ( 1 + V_4 -> V_68 -> V_92 ) * V_93 ;
V_69 = F_38 ( V_4 -> V_68 , V_90 , V_94 ) ;
if ( ! V_69 ) {
F_10 ( L_21 ) ;
return - V_83 ;
}
F_39 ( V_86 , V_69 ) ;
return F_40 ( V_86 , V_69 ) ;
}
static int F_41 ( struct V_85 * V_86 ,
struct V_95 * V_47 )
{
return V_96 ;
}
static struct V_74 * F_42 ( struct V_85 * V_86 )
{
struct V_3 * V_4 = F_35 ( V_86 ) ;
return V_4 -> V_75 ;
}
static int F_43 ( struct V_76 * V_77 ,
struct V_74 * V_75 )
{
struct V_3 * V_4 = V_77 -> V_4 ;
struct V_85 * V_86 = & V_4 -> V_86 ;
int V_67 ;
V_4 -> V_75 = V_75 ;
V_86 -> V_97 = V_98 ;
V_67 = F_44 ( V_4 -> V_54 , V_86 ,
& V_99 , V_100 ) ;
if ( V_67 ) {
F_9 ( L_22 ) ;
return V_67 ;
}
F_45 ( V_86 , & V_101 ) ;
F_46 ( V_86 ) ;
F_47 ( V_86 , V_75 ) ;
return 0 ;
}
static int F_48 ( struct V_102 * V_103 )
{
struct V_59 * V_60 = & V_103 -> V_60 ;
struct V_3 * V_4 ;
int V_67 ;
V_4 = F_49 ( V_60 , sizeof( * V_4 ) , V_94 ) ;
if ( ! V_4 )
return - V_83 ;
V_4 -> V_27 = 0 ;
F_50 ( & V_4 -> V_20 , F_18 ) ;
V_104 . V_4 = V_4 ;
V_105 . V_4 = V_4 ;
F_51 ( & V_4 -> V_48 ) ;
F_52 ( V_103 , & V_104 ) ;
V_67 = F_53 ( V_60 , & V_106 ) ;
if ( V_67 < 0 )
F_54 ( L_23 ) ;
F_55 ( & V_104 ) ;
F_56 ( & V_105 ) ;
return 0 ;
}
static int F_57 ( struct V_102 * V_103 )
{
struct V_3 * V_4 = F_58 ( V_103 ) ;
F_59 ( & V_105 ) ;
F_60 ( & V_104 ) ;
if ( V_4 -> V_68 != (struct V_69 * ) V_70 ) {
F_33 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
}
return 0 ;
}
