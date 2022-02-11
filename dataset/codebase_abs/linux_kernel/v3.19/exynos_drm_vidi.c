static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static void F_4 ( struct V_2 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_14 = & V_9 -> V_14 [ V_15 ] ;
if ( V_14 -> V_17 && ( V_11 && V_11 -> V_18 ) )
V_11 -> V_18 ( V_8 , V_15 ) ;
}
if ( V_11 && V_11 -> V_19 )
V_11 -> V_19 ( V_8 ) ;
}
static void F_5 ( struct V_2 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
if ( V_9 -> V_20 )
return;
}
static int F_6 ( struct V_2 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
if ( V_9 -> V_20 )
return - V_21 ;
if ( ! F_7 ( 0 , & V_9 -> V_22 ) )
V_9 -> V_23 = true ;
V_9 -> V_24 = true ;
F_8 ( & V_9 -> V_25 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_8 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
if ( V_9 -> V_20 )
return;
if ( F_10 ( 0 , & V_9 -> V_22 ) )
V_9 -> V_23 = false ;
}
static void F_11 ( struct V_2 * V_8 ,
struct V_26 * V_27 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
struct V_13 * V_14 ;
int V_28 ;
unsigned long V_29 ;
if ( ! V_27 ) {
F_12 ( L_1 ) ;
return;
}
V_28 = V_27 -> V_30 ;
if ( V_28 == V_31 )
V_28 = V_9 -> V_32 ;
if ( V_28 < 0 || V_28 >= V_16 )
return;
V_29 = V_27 -> V_33 * ( V_27 -> V_34 >> 3 ) ;
V_29 += V_27 -> V_35 * V_27 -> V_36 ;
F_13 ( L_2 , V_29 , V_27 -> V_36 ) ;
V_14 = & V_9 -> V_14 [ V_28 ] ;
V_14 -> V_37 = V_27 -> V_38 ;
V_14 -> V_39 = V_27 -> V_40 ;
V_14 -> V_41 = V_27 -> V_42 ;
V_14 -> V_43 = V_27 -> V_44 ;
V_14 -> V_45 = V_27 -> V_45 ;
V_14 -> V_46 = V_27 -> V_46 ;
V_14 -> V_47 = V_27 -> V_47 [ 0 ] + V_29 ;
V_14 -> V_34 = V_27 -> V_34 ;
V_14 -> V_48 = ( V_27 -> V_45 - V_27 -> V_42 ) *
( V_27 -> V_34 >> 3 ) ;
V_14 -> V_49 = V_27 -> V_42 * ( V_27 -> V_34 >> 3 ) ;
F_13 ( L_3 ,
V_14 -> V_37 , V_14 -> V_39 ) ;
F_13 ( L_4 ,
V_14 -> V_41 , V_14 -> V_43 ) ;
F_13 ( L_5 , ( unsigned long ) V_14 -> V_47 ) ;
F_13 ( L_6 ,
V_27 -> V_45 , V_27 -> V_42 ) ;
}
static void F_14 ( struct V_2 * V_8 , int V_30 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
struct V_13 * V_14 ;
int V_28 = V_30 ;
if ( V_9 -> V_20 )
return;
if ( V_28 == V_31 )
V_28 = V_9 -> V_32 ;
if ( V_28 < 0 || V_28 >= V_16 )
return;
V_14 = & V_9 -> V_14 [ V_28 ] ;
V_14 -> V_17 = true ;
F_13 ( L_7 , & V_14 -> V_47 ) ;
if ( V_9 -> V_23 )
F_8 ( & V_9 -> V_25 ) ;
}
static void F_15 ( struct V_2 * V_8 , int V_30 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
struct V_13 * V_14 ;
int V_28 = V_30 ;
if ( V_28 == V_31 )
V_28 = V_9 -> V_32 ;
if ( V_28 < 0 || V_28 >= V_16 )
return;
V_14 = & V_9 -> V_14 [ V_28 ] ;
V_14 -> V_17 = false ;
}
static int F_16 ( struct V_2 * V_8 , bool V_50 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
F_13 ( L_8 , __FILE__ ) ;
if ( V_50 != false && V_50 != true )
return - V_51 ;
if ( V_50 ) {
V_9 -> V_20 = false ;
if ( F_10 ( 0 , & V_9 -> V_22 ) )
F_6 ( V_8 ) ;
F_4 ( V_8 ) ;
} else {
V_9 -> V_20 = true ;
}
return 0 ;
}
static void F_17 ( struct V_2 * V_8 , int V_52 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
F_13 ( L_9 , V_52 ) ;
F_18 ( & V_9 -> V_53 ) ;
switch ( V_52 ) {
case V_54 :
F_16 ( V_8 , true ) ;
break;
case V_55 :
case V_56 :
case V_57 :
F_16 ( V_8 , false ) ;
break;
default:
F_13 ( L_10 , V_52 ) ;
break;
}
F_19 ( & V_9 -> V_53 ) ;
}
static int F_20 ( struct V_2 * V_8 ,
struct V_58 * V_59 )
{
struct V_1 * V_9 = F_1 ( V_8 ) ;
struct V_60 * V_61 = V_59 -> V_62 ;
V_8 -> V_59 = V_9 -> V_59 = V_59 ;
V_8 -> V_63 = V_9 -> V_63 = V_61 -> V_63 ++ ;
return 0 ;
}
static void F_21 ( struct V_64 * V_25 )
{
struct V_1 * V_9 = F_2 ( V_25 , struct V_1 ,
V_25 ) ;
if ( V_9 -> V_63 < 0 )
return;
F_22 ( 16000 , 20000 ) ;
F_18 ( & V_9 -> V_53 ) ;
if ( V_9 -> V_24 ) {
F_23 ( V_9 -> V_59 , V_9 -> V_63 ) ;
V_9 -> V_24 = false ;
F_19 ( & V_9 -> V_53 ) ;
return;
}
F_19 ( & V_9 -> V_53 ) ;
F_24 ( V_9 -> V_59 , V_9 -> V_63 ) ;
}
static int F_25 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_9 = F_26 ( V_66 ) ;
int V_70 ;
F_18 ( & V_9 -> V_53 ) ;
V_70 = sprintf ( V_69 , L_9 , V_9 -> V_71 ) ;
F_19 ( & V_9 -> V_53 ) ;
return V_70 ;
}
static int F_27 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_72 )
{
struct V_1 * V_9 = F_26 ( V_66 ) ;
int V_73 ;
V_73 = F_28 ( V_69 , 0 , & V_9 -> V_71 ) ;
if ( V_73 )
return V_73 ;
if ( V_9 -> V_71 > 1 )
return - V_51 ;
if ( ! V_9 -> V_74 )
V_9 -> V_74 = (struct V_75 * ) V_76 ;
if ( V_9 -> V_74 != (struct V_75 * ) V_76 ) {
F_13 ( L_11 ) ;
return - V_51 ;
}
F_13 ( L_12 ) ;
F_29 ( V_9 -> V_59 ) ;
return V_72 ;
}
int F_30 ( struct V_58 * V_59 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_9 = NULL ;
struct V_80 * V_81 ;
struct V_5 * V_7 ;
struct V_82 * V_83 = V_77 ;
if ( ! V_83 ) {
F_13 ( L_13 ) ;
return - V_51 ;
}
if ( V_83 -> V_84 > 1 ) {
F_13 ( L_14 ) ;
return - V_51 ;
}
F_31 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_7 = F_32 ( V_81 ) ;
if ( V_7 -> type == V_85 ) {
V_9 = F_3 ( V_7 ) ;
break;
}
}
if ( ! V_9 ) {
F_13 ( L_15 ) ;
return - V_51 ;
}
if ( V_9 -> V_71 == V_83 -> V_84 ) {
F_13 ( L_16 ) ;
return - V_51 ;
}
if ( V_83 -> V_84 ) {
struct V_75 * V_74 = (struct V_75 * ) ( V_86 ) V_83 -> V_75 ;
if ( ! F_33 ( V_74 ) ) {
F_13 ( L_17 ) ;
return - V_51 ;
}
V_9 -> V_74 = F_34 ( V_74 ) ;
if ( ! V_9 -> V_74 ) {
F_13 ( L_18 ) ;
return - V_87 ;
}
} else {
if ( V_9 -> V_74 && V_9 -> V_74 !=
(struct V_75 * ) V_76 ) {
F_35 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
}
}
V_9 -> V_71 = V_83 -> V_84 ;
F_29 ( V_9 -> V_59 ) ;
return 0 ;
}
static enum V_88 F_36 ( struct V_89 * V_90 ,
bool V_91 )
{
struct V_1 * V_9 = F_37 ( V_90 ) ;
return V_9 -> V_71 ? V_92 :
V_93 ;
}
static void F_38 ( struct V_89 * V_90 )
{
}
static int F_39 ( struct V_89 * V_90 )
{
struct V_1 * V_9 = F_37 ( V_90 ) ;
struct V_75 * V_75 ;
int V_94 ;
if ( ! V_9 -> V_74 ) {
F_13 ( L_19 ) ;
return - V_95 ;
}
V_94 = ( 1 + V_9 -> V_74 -> V_96 ) * V_97 ;
V_75 = F_40 ( V_9 -> V_74 , V_94 , V_98 ) ;
if ( ! V_75 ) {
F_13 ( L_20 ) ;
return - V_87 ;
}
F_41 ( V_90 , V_75 ) ;
return F_42 ( V_90 , V_75 ) ;
}
static struct V_80 * F_43 ( struct V_89 * V_90 )
{
struct V_1 * V_9 = F_37 ( V_90 ) ;
return V_9 -> V_81 ;
}
static int F_44 ( struct V_5 * V_7 ,
struct V_80 * V_81 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
struct V_89 * V_90 = & V_9 -> V_90 ;
int V_73 ;
V_9 -> V_81 = V_81 ;
V_90 -> V_99 = V_100 ;
V_73 = F_45 ( V_9 -> V_59 , V_90 ,
& V_101 , V_102 ) ;
if ( V_73 ) {
F_12 ( L_21 ) ;
return V_73 ;
}
F_46 ( V_90 , & V_103 ) ;
F_47 ( V_90 ) ;
F_48 ( V_90 , V_81 ) ;
return 0 ;
}
static int F_49 ( struct V_65 * V_66 , struct V_65 * V_104 , void * V_77 )
{
struct V_1 * V_9 = F_26 ( V_66 ) ;
struct V_58 * V_59 = V_77 ;
struct V_105 * V_106 = V_9 -> V_106 ;
int V_73 ;
F_20 ( & V_9 -> V_4 , V_59 ) ;
V_73 = F_50 ( & V_9 -> V_4 ) ;
if ( V_73 ) {
F_12 ( L_22 ) ;
return V_73 ;
}
V_73 = F_51 ( V_59 , & V_9 -> V_7 ) ;
if ( V_73 ) {
V_106 -> V_107 -> V_108 ( V_106 ) ;
F_12 ( L_23 ) ;
return V_73 ;
}
return 0 ;
}
static void F_52 ( struct V_65 * V_66 , struct V_65 * V_104 , void * V_77 )
{
}
static int F_53 ( struct V_109 * V_110 )
{
struct V_1 * V_9 ;
int V_73 ;
V_9 = F_54 ( & V_110 -> V_66 , sizeof( * V_9 ) , V_98 ) ;
if ( ! V_9 )
return - V_87 ;
V_9 -> V_4 . type = V_85 ;
V_9 -> V_4 . V_12 = & V_111 ;
V_9 -> V_7 . type = V_85 ;
V_9 -> V_7 . V_12 = & V_112 ;
V_9 -> V_32 = 0 ;
V_9 -> V_110 = V_110 ;
V_73 = F_55 ( & V_110 -> V_66 , V_113 ,
V_9 -> V_4 . type ) ;
if ( V_73 )
return V_73 ;
V_73 = F_55 ( & V_110 -> V_66 , V_114 ,
V_9 -> V_7 . type ) ;
if ( V_73 )
goto V_115;
F_56 ( & V_9 -> V_25 , F_21 ) ;
F_57 ( & V_9 -> V_53 ) ;
F_58 ( V_110 , V_9 ) ;
V_73 = F_59 ( & V_110 -> V_66 , & V_116 ) ;
if ( V_73 < 0 ) {
F_12 ( L_24 ) ;
goto V_117;
}
V_73 = F_60 ( & V_110 -> V_66 , & V_118 ) ;
if ( V_73 )
goto V_119;
return V_73 ;
V_119:
F_61 ( & V_110 -> V_66 , & V_116 ) ;
V_117:
F_62 ( & V_110 -> V_66 , V_114 ) ;
V_115:
F_62 ( & V_110 -> V_66 , V_113 ) ;
return V_73 ;
}
static int F_63 ( struct V_109 * V_110 )
{
struct V_1 * V_9 = F_64 ( V_110 ) ;
if ( V_9 -> V_74 != (struct V_75 * ) V_76 ) {
F_35 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
return - V_51 ;
}
F_65 ( & V_110 -> V_66 , & V_118 ) ;
F_62 ( & V_110 -> V_66 , V_114 ) ;
F_62 ( & V_110 -> V_66 , V_113 ) ;
return 0 ;
}
int F_66 ( void )
{
struct V_109 * V_110 ;
int V_73 ;
V_110 = F_67 ( L_25 , - 1 , NULL , 0 ) ;
if ( F_68 ( V_110 ) )
return F_69 ( V_110 ) ;
V_73 = F_70 ( & V_120 ) ;
if ( V_73 ) {
F_71 ( V_110 ) ;
return V_73 ;
}
return V_73 ;
}
static int F_72 ( struct V_65 * V_66 , void * V_77 )
{
F_71 ( F_73 ( V_66 ) ) ;
return 0 ;
}
void F_74 ( void )
{
int V_73 = F_75 ( & V_120 . V_121 , NULL , NULL ,
F_72 ) ;
( void ) V_73 ;
F_76 ( & V_120 ) ;
}
