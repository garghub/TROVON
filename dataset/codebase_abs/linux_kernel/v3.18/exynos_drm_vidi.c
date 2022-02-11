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
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_56 = V_54 -> V_57 ;
V_2 -> V_54 = V_4 -> V_54 = V_54 ;
V_2 -> V_58 = V_4 -> V_58 = V_56 -> V_58 ++ ;
return 0 ;
}
static void F_18 ( struct V_59 * V_20 )
{
struct V_3 * V_4 = F_19 ( V_20 , struct V_3 ,
V_20 ) ;
if ( V_4 -> V_58 < 0 )
return;
F_20 ( 16000 , 20000 ) ;
F_15 ( & V_4 -> V_48 ) ;
if ( V_4 -> V_19 ) {
F_21 ( V_4 -> V_54 , V_4 -> V_58 ) ;
V_4 -> V_19 = false ;
F_16 ( & V_4 -> V_48 ) ;
return;
}
F_16 ( & V_4 -> V_48 ) ;
F_22 ( V_4 -> V_54 , V_4 -> V_58 ) ;
}
static int F_23 ( struct V_60 * V_61 ,
struct V_62 * V_63 , char * V_64 )
{
int V_65 ;
struct V_1 * V_2 = F_24 ( V_61 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_15 ( & V_4 -> V_48 ) ;
V_65 = sprintf ( V_64 , L_9 , V_4 -> V_66 ) ;
F_16 ( & V_4 -> V_48 ) ;
return V_65 ;
}
static int F_25 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
const char * V_64 , T_1 V_67 )
{
struct V_1 * V_2 = F_24 ( V_61 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_68 ;
V_68 = F_26 ( V_64 , 0 , & V_4 -> V_66 ) ;
if ( V_68 )
return V_68 ;
if ( V_4 -> V_66 > 1 )
return - V_46 ;
if ( ! V_4 -> V_69 )
V_4 -> V_69 = (struct V_70 * ) V_71 ;
if ( V_4 -> V_69 != (struct V_70 * ) V_71 ) {
F_10 ( L_11 ) ;
return - V_46 ;
}
F_10 ( L_12 ) ;
F_27 ( V_4 -> V_54 ) ;
return V_67 ;
}
int F_28 ( struct V_53 * V_54 , void * V_72 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = NULL ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 = V_72 ;
if ( ! V_80 ) {
F_10 ( L_13 ) ;
return - V_46 ;
}
if ( V_80 -> V_81 > 1 ) {
F_10 ( L_14 ) ;
return - V_46 ;
}
F_29 (encoder, &drm_dev->mode_config.encoder_list,
head) {
V_78 = F_30 ( V_76 ) ;
if ( V_78 -> type == V_82 ) {
V_4 = V_78 -> V_4 ;
break;
}
}
if ( ! V_4 ) {
F_10 ( L_15 ) ;
return - V_46 ;
}
if ( V_4 -> V_66 == V_80 -> V_81 ) {
F_10 ( L_16 ) ;
return - V_46 ;
}
if ( V_80 -> V_81 ) {
struct V_70 * V_69 = (struct V_70 * ) ( V_83 ) V_80 -> V_70 ;
if ( ! F_31 ( V_69 ) ) {
F_10 ( L_17 ) ;
return - V_46 ;
}
V_4 -> V_69 = F_32 ( V_69 ) ;
if ( ! V_4 -> V_69 ) {
F_10 ( L_18 ) ;
return - V_84 ;
}
} else {
if ( V_4 -> V_69 && V_4 -> V_69 !=
(struct V_70 * ) V_71 ) {
F_33 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
}
}
V_4 -> V_66 = V_80 -> V_81 ;
F_27 ( V_4 -> V_54 ) ;
return 0 ;
}
static enum V_85 F_34 ( struct V_86 * V_87 ,
bool V_88 )
{
struct V_3 * V_4 = F_35 ( V_87 ) ;
return V_4 -> V_66 ? V_89 :
V_90 ;
}
static void F_36 ( struct V_86 * V_87 )
{
}
static int F_37 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = F_35 ( V_87 ) ;
struct V_70 * V_70 ;
int V_91 ;
if ( ! V_4 -> V_69 ) {
F_10 ( L_19 ) ;
return - V_92 ;
}
V_91 = ( 1 + V_4 -> V_69 -> V_93 ) * V_94 ;
V_70 = F_38 ( V_4 -> V_69 , V_91 , V_95 ) ;
if ( ! V_70 ) {
F_10 ( L_20 ) ;
return - V_84 ;
}
F_39 ( V_87 , V_70 ) ;
return F_40 ( V_87 , V_70 ) ;
}
static struct V_75 * F_41 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = F_35 ( V_87 ) ;
return V_4 -> V_76 ;
}
static int F_42 ( struct V_77 * V_78 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_78 -> V_4 ;
struct V_86 * V_87 = & V_4 -> V_87 ;
int V_68 ;
V_4 -> V_76 = V_76 ;
V_87 -> V_96 = V_97 ;
V_68 = F_43 ( V_4 -> V_54 , V_87 ,
& V_98 , V_99 ) ;
if ( V_68 ) {
F_9 ( L_21 ) ;
return V_68 ;
}
F_44 ( V_87 , & V_100 ) ;
F_45 ( V_87 ) ;
F_46 ( V_87 , V_76 ) ;
return 0 ;
}
static int F_47 ( struct V_53 * V_54 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_24 ( V_61 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_101 * V_102 = V_4 -> V_102 ;
int V_68 ;
F_17 ( V_2 , V_54 ) ;
V_68 = F_48 ( & V_103 ) ;
if ( V_68 ) {
F_9 ( L_22 ) ;
return V_68 ;
}
V_68 = F_49 ( V_54 , & V_104 ) ;
if ( V_68 ) {
V_102 -> V_105 -> V_106 ( V_102 ) ;
F_9 ( L_23 ) ;
return V_68 ;
}
return 0 ;
}
static int F_50 ( struct V_107 * V_108 )
{
struct V_109 * V_110 ;
struct V_3 * V_4 ;
int V_68 ;
V_4 = F_51 ( & V_108 -> V_61 , sizeof( * V_4 ) , V_95 ) ;
if ( ! V_4 )
return - V_84 ;
V_4 -> V_27 = 0 ;
F_52 ( & V_4 -> V_20 , F_18 ) ;
V_103 . V_4 = V_4 ;
V_104 . V_4 = V_4 ;
F_53 ( & V_4 -> V_48 ) ;
F_54 ( V_108 , & V_103 ) ;
V_110 = & V_4 -> V_110 ;
V_110 -> V_61 = & V_108 -> V_61 ;
V_110 -> V_111 = F_47 ;
V_68 = F_55 ( V_110 ) ;
if ( V_68 < 0 ) {
F_56 ( & V_108 -> V_61 , L_24 ) ;
return V_68 ;
}
V_68 = F_57 ( & V_108 -> V_61 , & V_112 ) ;
if ( V_68 < 0 ) {
F_58 ( V_110 ) ;
F_59 ( L_25 ) ;
}
return 0 ;
}
static int F_60 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_61 ( V_108 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_69 != (struct V_70 * ) V_71 ) {
F_33 ( V_4 -> V_69 ) ;
V_4 -> V_69 = NULL ;
return - V_46 ;
}
return 0 ;
}
int F_62 ( void )
{
struct V_107 * V_108 ;
int V_68 ;
V_108 = F_63 ( L_26 , - 1 , NULL , 0 ) ;
if ( F_64 ( V_108 ) )
return F_65 ( V_108 ) ;
V_68 = F_66 ( & V_113 ) ;
if ( V_68 ) {
F_67 ( V_108 ) ;
return V_68 ;
}
return V_68 ;
}
void F_68 ( void )
{
struct V_3 * V_4 = V_103 . V_4 ;
struct V_109 * V_110 = & V_4 -> V_110 ;
struct V_107 * V_108 = F_69 ( V_110 -> V_61 ) ;
F_70 ( & V_113 ) ;
F_67 ( V_108 ) ;
}
