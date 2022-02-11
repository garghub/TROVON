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
struct V_8 * V_10 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_2 ) ;
return - V_11 ;
}
V_10 = F_5 ( V_9 , V_12 ) ;
if ( ! V_10 ) {
F_3 ( L_3 ) ;
return - V_13 ;
}
memcpy ( V_10 , V_4 -> V_10 , F_6 ( ( 1 + V_4 -> V_10 -> V_14 )
* V_15 , V_9 ) ) ;
V_7 -> V_16 . V_10 = ( char * ) V_10 ;
memcpy ( V_8 , V_4 -> V_10 , F_6 ( ( 1 + V_4 -> V_10 -> V_14 )
* V_15 , V_9 ) ) ;
return 0 ;
}
static void * F_7 ( struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , void * V_17 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_18 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_19 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_3 ( L_4 , __FILE__ , V_18 ) ;
F_11 ( & V_4 -> V_20 ) ;
switch ( V_18 ) {
case V_21 :
break;
case V_22 :
case V_23 :
case V_24 :
break;
default:
F_3 ( L_5 , V_18 ) ;
break;
}
F_12 ( & V_4 -> V_20 ) ;
}
static void F_13 ( struct V_1 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
struct V_25 * V_26 = V_4 -> V_27 . V_28 ;
struct V_29 * V_30 = V_26 -> V_31 ;
struct V_32 * V_33 = V_26 -> V_34 ;
struct V_35 * V_36 ;
int V_37 ;
F_3 ( L_1 , __FILE__ ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_36 = & V_4 -> V_36 [ V_37 ] ;
if ( V_36 -> V_39 && ( V_33 && V_33 -> V_40 ) )
V_33 -> V_40 ( V_19 , V_37 ) ;
}
if ( V_30 && V_30 -> V_40 )
V_30 -> V_40 ( V_19 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_41 )
return;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_41 )
return - V_42 ;
if ( ! F_16 ( 0 , & V_4 -> V_43 ) )
V_4 -> V_44 = true ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_41 )
return;
if ( F_18 ( 0 , & V_4 -> V_43 ) )
V_4 -> V_44 = false ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 ;
int V_47 ;
unsigned long V_48 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_46 ) {
F_20 ( V_2 , L_6 ) ;
return;
}
V_47 = V_46 -> V_49 ;
if ( V_47 == V_50 )
V_47 = V_4 -> V_51 ;
if ( V_47 < 0 || V_47 > V_38 )
return;
V_48 = V_46 -> V_52 * ( V_46 -> V_53 >> 3 ) ;
V_48 += V_46 -> V_54 * V_46 -> V_55 ;
F_3 ( L_7 , V_48 , V_46 -> V_55 ) ;
V_36 = & V_4 -> V_36 [ V_47 ] ;
V_36 -> V_56 = V_46 -> V_57 ;
V_36 -> V_58 = V_46 -> V_59 ;
V_36 -> V_60 = V_46 -> V_61 ;
V_36 -> V_62 = V_46 -> V_63 ;
V_36 -> V_64 = V_46 -> V_64 ;
V_36 -> V_65 = V_46 -> V_65 ;
V_36 -> V_66 = V_46 -> V_66 [ 0 ] + V_48 ;
V_36 -> V_67 = V_46 -> V_67 [ 0 ] + V_48 ;
V_36 -> V_53 = V_46 -> V_53 ;
V_36 -> V_68 = ( V_46 -> V_64 - V_46 -> V_61 ) *
( V_46 -> V_53 >> 3 ) ;
V_36 -> V_69 = V_46 -> V_61 * ( V_46 -> V_53 >> 3 ) ;
F_3 ( L_8 ,
V_36 -> V_56 , V_36 -> V_58 ) ;
F_3 ( L_9 ,
V_36 -> V_60 , V_36 -> V_62 ) ;
F_3 ( L_10 ,
( unsigned long ) V_36 -> V_66 ,
( unsigned long ) V_36 -> V_67 ) ;
F_3 ( L_11 ,
V_46 -> V_64 , V_46 -> V_61 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 ;
int V_47 = V_49 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_41 )
return;
if ( V_47 == V_50 )
V_47 = V_4 -> V_51 ;
if ( V_47 < 0 || V_47 > V_38 )
return;
V_36 = & V_4 -> V_36 [ V_47 ] ;
V_36 -> V_39 = true ;
F_3 ( L_12 , V_36 -> V_66 ) ;
if ( V_4 -> V_44 )
F_22 ( & V_4 -> V_70 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_36 ;
int V_47 = V_49 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_47 == V_50 )
V_47 = V_4 -> V_51 ;
if ( V_47 < 0 || V_47 > V_38 )
return;
V_36 = & V_4 -> V_36 [ V_47 ] ;
V_36 -> V_39 = false ;
}
static void F_24 ( struct V_71 * V_72 , int V_73 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_77 * V_78 , * V_79 ;
struct V_80 V_81 ;
unsigned long V_82 ;
bool V_83 = false ;
F_25 ( & V_72 -> V_84 , V_82 ) ;
F_26 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_73 != V_78 -> V_85 )
continue;
V_83 = true ;
F_27 ( & V_81 ) ;
V_78 -> V_86 . V_87 = 0 ;
V_78 -> V_86 . V_88 = V_81 . V_88 ;
V_78 -> V_86 . V_89 = V_81 . V_89 ;
F_28 ( & V_78 -> V_90 . V_91 , & V_78 -> V_90 . V_92 -> V_93 ) ;
F_29 ( & V_78 -> V_90 . V_92 -> V_94 ) ;
}
if ( V_83 ) {
if ( F_30 ( & V_72 -> V_95 [ V_73 ] ) > 0 )
F_31 ( V_72 , V_73 ) ;
if ( ! V_72 -> V_96 )
F_32 ( V_72 , V_73 ) ;
}
F_33 ( & V_72 -> V_84 , V_82 ) ;
}
static void F_34 ( struct V_97 * V_70 )
{
struct V_3 * V_4 = F_35 ( V_70 , struct V_3 ,
V_70 ) ;
struct V_98 * V_27 = & V_4 -> V_27 ;
struct V_25 * V_28 = V_27 -> V_28 ;
if ( V_28 -> V_85 < 0 )
return;
F_36 ( 16000 , 20000 ) ;
F_37 ( V_27 -> V_72 , V_28 -> V_85 ) ;
F_24 ( V_27 -> V_72 , V_28 -> V_85 ) ;
}
static int F_38 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
F_3 ( L_1 , __FILE__ ) ;
V_72 -> V_99 = 1 ;
V_72 -> V_96 = 1 ;
return 0 ;
}
static void F_39 ( struct V_71 * V_72 )
{
F_3 ( L_1 , __FILE__ ) ;
}
static int F_40 ( struct V_3 * V_4 , bool V_100 )
{
struct V_98 * V_27 = & V_4 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_100 != false && V_100 != true )
return - V_101 ;
if ( V_100 ) {
V_4 -> V_41 = false ;
if ( F_18 ( 0 , & V_4 -> V_43 ) )
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
} else {
V_4 -> V_41 = true ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_102 * V_103 , char * V_104 )
{
int V_105 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( & V_4 -> V_20 ) ;
V_105 = sprintf ( V_104 , L_13 , V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_20 ) ;
return V_105 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
const char * V_104 , T_2 V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_106 ;
F_3 ( L_1 , __FILE__ ) ;
V_106 = F_43 ( V_104 , 0 , & V_4 -> V_5 ) ;
if ( V_106 )
return V_106 ;
if ( V_4 -> V_5 > 1 )
return - V_101 ;
F_3 ( L_14 ) ;
F_44 ( V_4 -> V_27 . V_72 ) ;
return V_9 ;
}
int F_45 ( struct V_71 * V_72 , void * V_107 ,
struct V_108 * V_92 )
{
struct V_3 * V_4 = NULL ;
struct V_109 * V_110 ;
struct V_25 * V_28 ;
struct V_111 * V_112 ;
struct V_113 * V_114 = V_107 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! V_114 ) {
F_3 ( L_15 ) ;
return - V_101 ;
}
if ( ! V_114 -> V_8 ) {
F_3 ( L_16 ) ;
return - V_101 ;
}
if ( V_114 -> V_115 > 1 ) {
F_3 ( L_17 ) ;
return - V_101 ;
}
F_46 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_28 = F_47 ( V_110 ) ;
V_112 = V_28 -> V_112 ;
if ( V_112 -> type == V_116 ) {
V_4 = F_2 ( V_28 -> V_2 ) ;
break;
}
}
if ( ! V_4 ) {
F_3 ( L_18 ) ;
return - V_101 ;
}
if ( V_4 -> V_5 == V_114 -> V_115 ) {
F_3 ( L_19 ) ;
return - V_101 ;
}
if ( V_114 -> V_115 )
V_4 -> V_10 = (struct V_8 * ) V_114 -> V_8 ;
V_4 -> V_5 = V_114 -> V_115 ;
F_44 ( V_4 -> V_27 . V_72 ) ;
return 0 ;
}
static int T_3 F_48 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = & V_118 -> V_2 ;
struct V_3 * V_4 ;
struct V_98 * V_27 ;
int V_106 ;
F_3 ( L_1 , __FILE__ ) ;
V_4 = F_5 ( sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_4 -> V_51 = 0 ;
F_49 ( & V_4 -> V_70 , F_34 ) ;
V_4 -> V_10 = (struct V_8 * ) V_119 ;
V_27 = & V_4 -> V_27 ;
V_27 -> V_2 = V_2 ;
V_27 -> V_28 = & V_120 ;
V_27 -> V_121 = F_38 ;
V_27 -> remove = F_39 ;
F_50 ( & V_4 -> V_20 ) ;
F_51 ( V_118 , V_4 ) ;
V_106 = F_52 ( & V_118 -> V_2 , & V_122 ) ;
if ( V_106 < 0 )
F_53 ( L_20 ) ;
F_54 ( V_27 ) ;
return 0 ;
}
static int T_4 F_55 ( struct V_117 * V_118 )
{
struct V_3 * V_4 = F_56 ( V_118 ) ;
F_3 ( L_1 , __FILE__ ) ;
F_57 ( & V_4 -> V_27 ) ;
F_58 ( V_4 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_40 ( V_4 , false ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_40 ( V_4 , true ) ;
}
