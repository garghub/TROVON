static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = & V_5 -> V_11 [ V_12 ] ;
if ( V_11 -> V_14 && ( V_7 && V_7 -> V_15 ) )
V_7 -> V_15 ( V_5 -> V_8 , V_12 ) ;
}
}
static int F_4 ( struct V_16 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
if ( V_5 -> V_17 )
return - V_18 ;
if ( ! F_5 ( 0 , & V_5 -> V_19 ) )
V_5 -> V_20 = true ;
V_5 -> V_21 = true ;
F_6 ( & V_5 -> V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_16 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
if ( V_5 -> V_17 )
return;
if ( F_8 ( 0 , & V_5 -> V_19 ) )
V_5 -> V_20 = false ;
}
static void F_9 ( struct V_16 * V_8 ,
struct V_23 * V_24 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
struct V_10 * V_11 ;
int V_25 ;
unsigned long V_26 ;
if ( ! V_24 ) {
F_10 ( L_1 ) ;
return;
}
V_25 = V_24 -> V_27 ;
if ( V_25 == V_28 )
V_25 = V_5 -> V_29 ;
if ( V_25 < 0 || V_25 >= V_13 )
return;
V_26 = V_24 -> V_30 * ( V_24 -> V_31 >> 3 ) ;
V_26 += V_24 -> V_32 * V_24 -> V_33 ;
F_11 ( L_2 , V_26 , V_24 -> V_33 ) ;
V_11 = & V_5 -> V_11 [ V_25 ] ;
V_11 -> V_34 = V_24 -> V_35 ;
V_11 -> V_36 = V_24 -> V_37 ;
V_11 -> V_38 = V_24 -> V_39 ;
V_11 -> V_40 = V_24 -> V_41 ;
V_11 -> V_42 = V_24 -> V_42 ;
V_11 -> V_43 = V_24 -> V_43 ;
V_11 -> V_44 = V_24 -> V_44 [ 0 ] + V_26 ;
V_11 -> V_31 = V_24 -> V_31 ;
V_11 -> V_45 = ( V_24 -> V_42 - V_24 -> V_39 ) *
( V_24 -> V_31 >> 3 ) ;
V_11 -> V_46 = V_24 -> V_39 * ( V_24 -> V_31 >> 3 ) ;
F_11 ( L_3 ,
V_11 -> V_34 , V_11 -> V_36 ) ;
F_11 ( L_4 ,
V_11 -> V_38 , V_11 -> V_40 ) ;
F_11 ( L_5 , ( unsigned long ) V_11 -> V_44 ) ;
F_11 ( L_6 ,
V_24 -> V_42 , V_24 -> V_39 ) ;
}
static void F_12 ( struct V_16 * V_8 , int V_27 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
struct V_10 * V_11 ;
int V_25 = V_27 ;
if ( V_5 -> V_17 )
return;
if ( V_25 == V_28 )
V_25 = V_5 -> V_29 ;
if ( V_25 < 0 || V_25 >= V_13 )
return;
V_11 = & V_5 -> V_11 [ V_25 ] ;
V_11 -> V_14 = true ;
F_11 ( L_7 , & V_11 -> V_44 ) ;
if ( V_5 -> V_20 )
F_6 ( & V_5 -> V_22 ) ;
}
static void F_13 ( struct V_16 * V_8 , int V_27 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
struct V_10 * V_11 ;
int V_25 = V_27 ;
if ( V_25 == V_28 )
V_25 = V_5 -> V_29 ;
if ( V_25 < 0 || V_25 >= V_13 )
return;
V_11 = & V_5 -> V_11 [ V_25 ] ;
V_11 -> V_14 = false ;
}
static int F_14 ( struct V_1 * V_5 , bool V_47 )
{
F_11 ( L_8 , __FILE__ ) ;
if ( V_47 != false && V_47 != true )
return - V_48 ;
if ( V_47 ) {
V_5 -> V_17 = false ;
if ( F_8 ( 0 , & V_5 -> V_19 ) )
F_4 ( V_5 -> V_8 ) ;
F_3 ( V_5 ) ;
} else {
V_5 -> V_17 = true ;
}
return 0 ;
}
static void F_15 ( struct V_16 * V_8 , int V_49 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
F_11 ( L_9 , V_49 ) ;
F_16 ( & V_5 -> V_50 ) ;
switch ( V_49 ) {
case V_51 :
F_14 ( V_5 , true ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_14 ( V_5 , false ) ;
break;
default:
F_11 ( L_10 , V_49 ) ;
break;
}
F_17 ( & V_5 -> V_50 ) ;
}
static int F_18 ( struct V_1 * V_5 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_59 ;
V_5 -> V_56 = V_56 ;
V_5 -> V_60 = V_58 -> V_60 ++ ;
return 0 ;
}
static void F_19 ( struct V_61 * V_22 )
{
struct V_1 * V_5 = F_2 ( V_22 , struct V_1 ,
V_22 ) ;
if ( V_5 -> V_60 < 0 )
return;
F_20 ( 16000 , 20000 ) ;
F_16 ( & V_5 -> V_50 ) ;
if ( V_5 -> V_21 ) {
F_21 ( V_5 -> V_56 , V_5 -> V_60 ) ;
V_5 -> V_21 = false ;
F_17 ( & V_5 -> V_50 ) ;
return;
}
F_17 ( & V_5 -> V_50 ) ;
F_22 ( V_5 -> V_56 , V_5 -> V_60 ) ;
}
static int F_23 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_1 * V_5 = F_24 ( V_63 ) ;
int V_67 ;
F_16 ( & V_5 -> V_50 ) ;
V_67 = sprintf ( V_66 , L_9 , V_5 -> V_68 ) ;
F_17 ( & V_5 -> V_50 ) ;
return V_67 ;
}
static int F_25 ( struct V_62 * V_63 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_69 )
{
struct V_1 * V_5 = F_24 ( V_63 ) ;
int V_70 ;
V_70 = F_26 ( V_66 , 0 , & V_5 -> V_68 ) ;
if ( V_70 )
return V_70 ;
if ( V_5 -> V_68 > 1 )
return - V_48 ;
if ( ! V_5 -> V_71 )
V_5 -> V_71 = (struct V_72 * ) V_73 ;
if ( V_5 -> V_71 != (struct V_72 * ) V_73 ) {
F_11 ( L_11 ) ;
return - V_48 ;
}
F_11 ( L_12 ) ;
F_27 ( V_5 -> V_56 ) ;
return V_69 ;
}
int F_28 ( struct V_55 * V_56 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_1 * V_5 = NULL ;
struct V_77 * V_78 ;
struct V_2 * V_4 ;
struct V_79 * V_80 = V_74 ;
if ( ! V_80 ) {
F_11 ( L_13 ) ;
return - V_48 ;
}
if ( V_80 -> V_81 > 1 ) {
F_11 ( L_14 ) ;
return - V_48 ;
}
F_29 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_4 = F_30 ( V_78 ) ;
if ( V_4 -> type == V_82 ) {
V_5 = F_1 ( V_4 ) ;
break;
}
}
if ( ! V_5 ) {
F_11 ( L_15 ) ;
return - V_48 ;
}
if ( V_5 -> V_68 == V_80 -> V_81 ) {
F_11 ( L_16 ) ;
return - V_48 ;
}
if ( V_80 -> V_81 ) {
struct V_72 * V_71 = (struct V_72 * ) ( V_83 ) V_80 -> V_72 ;
if ( ! F_31 ( V_71 ) ) {
F_11 ( L_17 ) ;
return - V_48 ;
}
V_5 -> V_71 = F_32 ( V_71 ) ;
if ( ! V_5 -> V_71 ) {
F_11 ( L_18 ) ;
return - V_84 ;
}
} else {
if ( V_5 -> V_71 && V_5 -> V_71 !=
(struct V_72 * ) V_73 ) {
F_33 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
}
}
V_5 -> V_68 = V_80 -> V_81 ;
F_27 ( V_5 -> V_56 ) ;
return 0 ;
}
static enum V_85 F_34 ( struct V_86 * V_87 ,
bool V_88 )
{
struct V_1 * V_5 = F_35 ( V_87 ) ;
return V_5 -> V_68 ? V_89 :
V_90 ;
}
static void F_36 ( struct V_86 * V_87 )
{
}
static int F_37 ( struct V_86 * V_87 )
{
struct V_1 * V_5 = F_35 ( V_87 ) ;
struct V_72 * V_72 ;
int V_91 ;
if ( ! V_5 -> V_71 ) {
F_11 ( L_19 ) ;
return - V_92 ;
}
V_91 = ( 1 + V_5 -> V_71 -> V_93 ) * V_94 ;
V_72 = F_38 ( V_5 -> V_71 , V_91 , V_95 ) ;
if ( ! V_72 ) {
F_11 ( L_20 ) ;
return - V_84 ;
}
F_39 ( V_87 , V_72 ) ;
return F_40 ( V_87 , V_72 ) ;
}
static struct V_77 * F_41 ( struct V_86 * V_87 )
{
struct V_1 * V_5 = F_35 ( V_87 ) ;
return V_5 -> V_78 ;
}
static int F_42 ( struct V_2 * V_4 ,
struct V_77 * V_78 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_86 * V_87 = & V_5 -> V_87 ;
int V_70 ;
V_5 -> V_78 = V_78 ;
V_87 -> V_96 = V_97 ;
V_70 = F_43 ( V_5 -> V_56 , V_87 ,
& V_98 , V_99 ) ;
if ( V_70 ) {
F_10 ( L_21 ) ;
return V_70 ;
}
F_44 ( V_87 , & V_100 ) ;
F_45 ( V_87 ) ;
F_46 ( V_87 , V_78 ) ;
return 0 ;
}
static int F_47 ( struct V_62 * V_63 , struct V_62 * V_101 , void * V_74 )
{
struct V_1 * V_5 = F_24 ( V_63 ) ;
struct V_55 * V_56 = V_74 ;
int V_70 ;
F_18 ( V_5 , V_56 ) ;
V_5 -> V_8 = F_48 ( V_56 , V_5 -> V_60 ,
V_82 ,
& V_102 , V_5 ) ;
if ( F_49 ( V_5 -> V_8 ) ) {
F_10 ( L_22 ) ;
return F_50 ( V_5 -> V_8 ) ;
}
V_70 = F_51 ( V_56 , & V_5 -> V_4 ) ;
if ( V_70 ) {
V_5 -> V_8 -> V_103 . V_104 -> V_105 ( & V_5 -> V_8 -> V_103 ) ;
return V_70 ;
}
return 0 ;
}
static void F_52 ( struct V_62 * V_63 , struct V_62 * V_101 , void * V_74 )
{
}
static int F_53 ( struct V_106 * V_107 )
{
struct V_1 * V_5 ;
int V_70 ;
V_5 = F_54 ( & V_107 -> V_63 , sizeof( * V_5 ) , V_95 ) ;
if ( ! V_5 )
return - V_84 ;
V_5 -> V_4 . type = V_82 ;
V_5 -> V_4 . V_9 = & V_108 ;
V_5 -> V_29 = 0 ;
V_5 -> V_107 = V_107 ;
V_70 = F_55 ( & V_107 -> V_63 , V_109 ,
V_82 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_55 ( & V_107 -> V_63 , V_110 ,
V_5 -> V_4 . type ) ;
if ( V_70 )
goto V_111;
F_56 ( & V_5 -> V_22 , F_19 ) ;
F_57 ( & V_5 -> V_50 ) ;
F_58 ( V_107 , V_5 ) ;
V_70 = F_59 ( & V_107 -> V_63 , & V_112 ) ;
if ( V_70 < 0 ) {
F_10 ( L_23 ) ;
goto V_113;
}
V_70 = F_60 ( & V_107 -> V_63 , & V_114 ) ;
if ( V_70 )
goto V_115;
return V_70 ;
V_115:
F_61 ( & V_107 -> V_63 , & V_112 ) ;
V_113:
F_62 ( & V_107 -> V_63 , V_110 ) ;
V_111:
F_62 ( & V_107 -> V_63 , V_109 ) ;
return V_70 ;
}
static int F_63 ( struct V_106 * V_107 )
{
struct V_1 * V_5 = F_64 ( V_107 ) ;
if ( V_5 -> V_71 != (struct V_72 * ) V_73 ) {
F_33 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
return - V_48 ;
}
F_65 ( & V_107 -> V_63 , & V_114 ) ;
F_62 ( & V_107 -> V_63 , V_110 ) ;
F_62 ( & V_107 -> V_63 , V_109 ) ;
return 0 ;
}
int F_66 ( void )
{
struct V_106 * V_107 ;
int V_70 ;
V_107 = F_67 ( L_24 , - 1 , NULL , 0 ) ;
if ( F_49 ( V_107 ) )
return F_50 ( V_107 ) ;
V_70 = F_68 ( & V_116 ) ;
if ( V_70 ) {
F_69 ( V_107 ) ;
return V_70 ;
}
return V_70 ;
}
static int F_70 ( struct V_62 * V_63 , void * V_74 )
{
F_69 ( F_71 ( V_63 ) ) ;
return 0 ;
}
void F_72 ( void )
{
int V_70 = F_73 ( & V_116 . V_117 , NULL , NULL ,
F_70 ) ;
( void ) V_70 ;
F_74 ( & V_116 ) ;
}
