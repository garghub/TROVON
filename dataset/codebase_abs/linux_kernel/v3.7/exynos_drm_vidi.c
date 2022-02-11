static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
return V_4 -> V_5 ? true : false ;
}
static int F_4 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 * V_8 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_2 ) ;
return - V_11 ;
}
memcpy ( V_8 , V_4 -> V_10 , F_5 ( ( 1 + V_4 -> V_10 -> V_12 )
* V_13 , V_9 ) ) ;
return 0 ;
}
static void * F_6 ( struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
return NULL ;
}
static int F_7 ( struct V_1 * V_2 , void * V_14 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_15 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_16 , int V_15 )
{
struct V_3 * V_4 = F_2 ( V_16 ) ;
F_3 ( L_3 , __FILE__ , V_15 ) ;
F_10 ( & V_4 -> V_17 ) ;
switch ( V_15 ) {
case V_18 :
break;
case V_19 :
case V_20 :
case V_21 :
break;
default:
F_3 ( L_4 , V_15 ) ;
break;
}
F_11 ( & V_4 -> V_17 ) ;
}
static void F_12 ( struct V_1 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_16 ) ;
struct V_22 * V_23 = V_4 -> V_24 . V_25 ;
struct V_26 * V_27 = V_23 -> V_28 ;
struct V_29 * V_30 = V_23 -> V_31 ;
struct V_32 * V_33 ;
int V_34 ;
F_3 ( L_1 , __FILE__ ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_33 = & V_4 -> V_33 [ V_34 ] ;
if ( V_33 -> V_36 && ( V_30 && V_30 -> V_37 ) )
V_30 -> V_37 ( V_16 , V_34 ) ;
}
if ( V_27 && V_27 -> V_37 )
V_27 -> V_37 ( V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_38 )
return;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_38 )
return - V_39 ;
if ( ! F_15 ( 0 , & V_4 -> V_40 ) )
V_4 -> V_41 = true ;
V_4 -> V_42 = true ;
F_16 ( & V_4 -> V_43 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_38 )
return;
if ( F_18 ( 0 , & V_4 -> V_40 ) )
V_4 -> V_41 = false ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 ;
int V_46 ;
unsigned long V_47 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_45 ) {
F_20 ( V_2 , L_5 ) ;
return;
}
V_46 = V_45 -> V_48 ;
if ( V_46 == V_49 )
V_46 = V_4 -> V_50 ;
if ( V_46 < 0 || V_46 > V_35 )
return;
V_47 = V_45 -> V_51 * ( V_45 -> V_52 >> 3 ) ;
V_47 += V_45 -> V_53 * V_45 -> V_54 ;
F_3 ( L_6 , V_47 , V_45 -> V_54 ) ;
V_33 = & V_4 -> V_33 [ V_46 ] ;
V_33 -> V_55 = V_45 -> V_56 ;
V_33 -> V_57 = V_45 -> V_58 ;
V_33 -> V_59 = V_45 -> V_60 ;
V_33 -> V_61 = V_45 -> V_62 ;
V_33 -> V_63 = V_45 -> V_63 ;
V_33 -> V_64 = V_45 -> V_64 ;
V_33 -> V_65 = V_45 -> V_65 [ 0 ] + V_47 ;
V_33 -> V_66 = V_45 -> V_66 [ 0 ] + V_47 ;
V_33 -> V_52 = V_45 -> V_52 ;
V_33 -> V_67 = ( V_45 -> V_63 - V_45 -> V_60 ) *
( V_45 -> V_52 >> 3 ) ;
V_33 -> V_68 = V_45 -> V_60 * ( V_45 -> V_52 >> 3 ) ;
F_3 ( L_7 ,
V_33 -> V_55 , V_33 -> V_57 ) ;
F_3 ( L_8 ,
V_33 -> V_59 , V_33 -> V_61 ) ;
F_3 ( L_9 ,
( unsigned long ) V_33 -> V_65 ,
( unsigned long ) V_33 -> V_66 ) ;
F_3 ( L_10 ,
V_45 -> V_63 , V_45 -> V_60 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 ;
int V_46 = V_48 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_38 )
return;
if ( V_46 == V_49 )
V_46 = V_4 -> V_50 ;
if ( V_46 < 0 || V_46 > V_35 )
return;
V_33 = & V_4 -> V_33 [ V_46 ] ;
V_33 -> V_36 = true ;
F_3 ( L_11 , V_33 -> V_65 ) ;
if ( V_4 -> V_41 )
F_16 ( & V_4 -> V_43 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 ;
int V_46 = V_48 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_46 == V_49 )
V_46 = V_4 -> V_50 ;
if ( V_46 < 0 || V_46 > V_35 )
return;
V_33 = & V_4 -> V_33 [ V_46 ] ;
V_33 -> V_36 = false ;
}
static void F_23 ( struct V_69 * V_70 , int V_71 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_75 * V_76 , * V_77 ;
struct V_78 V_79 ;
unsigned long V_80 ;
bool V_81 = false ;
F_24 ( & V_70 -> V_82 , V_80 ) ;
F_25 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_71 != V_76 -> V_83 )
continue;
V_81 = true ;
F_26 ( & V_79 ) ;
V_76 -> V_84 . V_85 = 0 ;
V_76 -> V_84 . V_86 = V_79 . V_86 ;
V_76 -> V_84 . V_87 = V_79 . V_87 ;
F_27 ( & V_76 -> V_88 . V_89 , & V_76 -> V_88 . V_90 -> V_91 ) ;
F_28 ( & V_76 -> V_88 . V_90 -> V_92 ) ;
}
if ( V_81 ) {
if ( F_29 ( & V_70 -> V_93 [ V_71 ] ) > 0 )
F_30 ( V_70 , V_71 ) ;
if ( ! V_70 -> V_94 )
F_31 ( V_70 , V_71 ) ;
}
F_32 ( & V_70 -> V_82 , V_80 ) ;
}
static void F_33 ( struct V_95 * V_43 )
{
struct V_3 * V_4 = F_34 ( V_43 , struct V_3 ,
V_43 ) ;
struct V_96 * V_24 = & V_4 -> V_24 ;
struct V_22 * V_25 = V_24 -> V_25 ;
if ( V_25 -> V_83 < 0 )
return;
F_35 ( 16000 , 20000 ) ;
F_10 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_42 ) {
F_36 ( V_24 -> V_70 , V_25 -> V_83 ) ;
V_4 -> V_42 = false ;
F_11 ( & V_4 -> V_17 ) ;
return;
}
F_11 ( & V_4 -> V_17 ) ;
F_23 ( V_24 -> V_70 , V_25 -> V_83 ) ;
}
static int F_37 ( struct V_69 * V_70 , struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
V_70 -> V_97 = 1 ;
V_70 -> V_94 = 1 ;
return 0 ;
}
static void F_38 ( struct V_69 * V_70 , struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
}
static int F_39 ( struct V_3 * V_4 , bool V_98 )
{
struct V_96 * V_24 = & V_4 -> V_24 ;
struct V_1 * V_2 = V_24 -> V_2 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_98 != false && V_98 != true )
return - V_99 ;
if ( V_98 ) {
V_4 -> V_38 = false ;
if ( F_18 ( 0 , & V_4 -> V_40 ) )
F_14 ( V_2 ) ;
F_12 ( V_2 ) ;
} else {
V_4 -> V_38 = true ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_100 * V_101 , char * V_102 )
{
int V_103 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( & V_4 -> V_17 ) ;
V_103 = sprintf ( V_102 , L_12 , V_4 -> V_5 ) ;
F_11 ( & V_4 -> V_17 ) ;
return V_103 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
const char * V_102 , T_2 V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_104 ;
F_3 ( L_1 , __FILE__ ) ;
V_104 = F_42 ( V_102 , 0 , & V_4 -> V_5 ) ;
if ( V_104 )
return V_104 ;
if ( V_4 -> V_5 > 1 )
return - V_99 ;
if ( ! V_4 -> V_10 )
V_4 -> V_10 = (struct V_8 * ) V_105 ;
if ( V_4 -> V_10 != (struct V_8 * ) V_105 ) {
F_3 ( L_13 ) ;
return - V_99 ;
}
F_3 ( L_14 ) ;
F_43 ( V_4 -> V_24 . V_70 ) ;
return V_9 ;
}
int F_44 ( struct V_69 * V_70 , void * V_106 ,
struct V_107 * V_90 )
{
struct V_3 * V_4 = NULL ;
struct V_108 * V_109 ;
struct V_22 * V_25 ;
struct V_110 * V_111 ;
struct V_112 * V_113 = V_106 ;
struct V_8 * V_10 ;
int V_114 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_113 ) {
F_3 ( L_15 ) ;
return - V_99 ;
}
if ( V_113 -> V_115 > 1 ) {
F_3 ( L_16 ) ;
return - V_99 ;
}
F_45 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_25 = F_46 ( V_109 ) ;
V_111 = V_25 -> V_111 ;
if ( V_111 -> type == V_116 ) {
V_4 = F_2 ( V_25 -> V_2 ) ;
break;
}
}
if ( ! V_4 ) {
F_3 ( L_17 ) ;
return - V_99 ;
}
if ( V_4 -> V_5 == V_113 -> V_115 ) {
F_3 ( L_18 ) ;
return - V_99 ;
}
if ( V_113 -> V_115 ) {
if ( ! V_113 -> V_8 ) {
F_3 ( L_19 ) ;
return - V_99 ;
}
V_10 = (struct V_8 * ) ( V_117 ) V_113 -> V_8 ;
V_114 = ( 1 + V_10 -> V_12 ) * V_13 ;
V_4 -> V_10 = F_47 ( V_114 , V_118 ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_20 ) ;
return - V_119 ;
}
memcpy ( V_4 -> V_10 , V_10 , V_114 ) ;
} else {
if ( V_4 -> V_10 && V_4 -> V_10 !=
(struct V_8 * ) V_105 ) {
F_48 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
}
V_4 -> V_5 = V_113 -> V_115 ;
F_43 ( V_4 -> V_24 . V_70 ) ;
return 0 ;
}
static int T_3 F_49 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = & V_121 -> V_2 ;
struct V_3 * V_4 ;
struct V_96 * V_24 ;
int V_104 ;
F_3 ( L_1 , __FILE__ ) ;
V_4 = F_50 ( & V_121 -> V_2 , sizeof( * V_4 ) , V_118 ) ;
if ( ! V_4 )
return - V_119 ;
V_4 -> V_50 = 0 ;
F_51 ( & V_4 -> V_43 , F_33 ) ;
V_24 = & V_4 -> V_24 ;
V_24 -> V_2 = V_2 ;
V_24 -> V_25 = & V_122 ;
V_24 -> V_123 = F_37 ;
V_24 -> remove = F_38 ;
F_52 ( & V_4 -> V_17 ) ;
F_53 ( V_121 , V_4 ) ;
V_104 = F_54 ( & V_121 -> V_2 , & V_124 ) ;
if ( V_104 < 0 )
F_55 ( L_21 ) ;
F_56 ( V_24 ) ;
return 0 ;
}
static int T_4 F_57 ( struct V_120 * V_121 )
{
struct V_3 * V_4 = F_58 ( V_121 ) ;
F_3 ( L_1 , __FILE__ ) ;
F_59 ( & V_4 -> V_24 ) ;
if ( V_4 -> V_10 != (struct V_8 * ) V_105 ) {
F_48 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_39 ( V_4 , false ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_39 ( V_4 , true ) ;
}
