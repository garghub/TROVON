static inline struct V_1 * F_1 ( int V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( & V_6 , V_2 ) ;
if ( ! V_5 )
V_5 = F_3 ( - V_7 ) ;
else if ( V_5 -> V_4 != V_4 )
V_5 = F_3 ( - V_8 ) ;
return V_5 ;
}
static struct V_1 * F_4 ( struct V_3 * V_4 , int V_2 )
{
struct V_1 * V_5 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) ) {
if ( V_5 -> V_10 )
V_5 = F_3 ( - V_11 ) ;
else
F_7 ( & V_5 -> V_12 ) ;
}
F_8 ( & V_9 ) ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_5 )
{
if ( F_10 ( & V_5 -> V_12 ) )
F_11 ( & V_5 -> V_13 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_13 ( V_15 , struct V_16 , V_18 ) ;
F_14 ( V_17 -> V_19 ) ;
F_15 ( V_17 ) ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_5 = F_13 ( V_15 , struct V_1 , V_18 ) ;
F_9 ( V_5 ) ;
F_17 ( & V_5 -> V_13 ) ;
F_14 ( V_5 -> V_19 ) ;
}
static struct V_1 * F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_19 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return NULL ;
F_20 ( & V_5 -> V_18 , F_16 ) ;
F_21 ( & V_5 -> V_12 , 1 ) ;
F_22 ( & V_5 -> V_13 ) ;
F_23 ( & V_5 -> V_21 ) ;
V_5 -> V_4 = V_4 ;
F_5 ( & V_9 ) ;
V_5 -> V_2 = F_24 ( & V_6 , V_5 , 0 , 0 , V_20 ) ;
F_8 ( & V_9 ) ;
if ( V_5 -> V_2 < 0 )
goto error;
F_25 ( & V_5 -> V_22 , & V_4 -> V_23 ) ;
return V_5 ;
error:
F_15 ( V_5 ) ;
return NULL ;
}
static struct V_24 * F_26 ( struct V_1 * V_5 )
{
struct V_24 * V_25 ;
V_25 = F_19 ( sizeof( * V_25 ) , V_20 ) ;
if ( ! V_25 )
return NULL ;
F_5 ( & V_9 ) ;
V_25 -> V_2 = F_24 ( & V_26 , V_25 , 0 , 0 , V_20 ) ;
F_8 ( & V_9 ) ;
if ( V_25 -> V_2 < 0 )
goto error;
V_25 -> V_5 = V_5 ;
F_25 ( & V_25 -> V_22 , & V_5 -> V_21 ) ;
return V_25 ;
error:
F_15 ( V_25 ) ;
return NULL ;
}
static void F_27 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_31 )
memcpy ( V_28 -> V_32 , V_30 -> V_32 ,
V_30 -> V_31 ) ;
V_28 -> V_31 = V_30 -> V_31 ;
V_28 -> V_33 = V_30 -> V_33 ;
V_28 -> V_34 = V_30 -> V_34 ;
V_28 -> V_35 = V_30 -> V_35 ;
V_28 -> V_36 = V_30 -> V_36 ;
V_28 -> V_37 = V_30 -> V_37 ;
V_28 -> V_38 = V_30 -> V_38 ;
V_28 -> V_39 = V_30 -> V_39 ;
}
static void F_28 ( struct V_40 * V_28 ,
struct V_41 * V_30 )
{
if ( V_30 -> V_31 )
memcpy ( V_28 -> V_32 , V_30 -> V_32 ,
V_30 -> V_31 ) ;
V_28 -> V_31 = V_30 -> V_31 ;
F_29 ( & V_28 -> V_42 , & V_30 -> V_42 ) ;
V_28 -> V_39 = V_30 -> V_39 ;
V_28 -> V_43 = V_30 -> V_43 ;
}
static void F_30 ( struct V_1 * V_5 ,
struct V_44 * V_45 ,
struct V_16 * V_46 )
{
V_46 -> V_5 = V_5 ;
switch ( V_45 -> V_45 ) {
case V_47 :
case V_48 :
V_46 -> V_25 = (struct V_24 * )
V_45 -> V_49 . V_50 . V_32 ;
V_46 -> V_51 . V_52 = V_46 -> V_25 -> V_52 ;
V_46 -> V_51 . V_2 = V_46 -> V_25 -> V_2 ;
break;
default:
V_46 -> V_51 . V_52 = V_5 -> V_52 ;
V_46 -> V_51 . V_2 = V_5 -> V_2 ;
break;
}
}
static void F_31 ( struct V_53 * V_19 )
{
struct V_1 * V_5 = V_19 -> V_54 ;
struct V_16 * V_55 ;
int V_56 = 0 ;
if ( V_5 -> V_57 )
return;
if ( V_5 -> V_19 == V_19 ) {
F_5 ( & V_9 ) ;
V_5 -> V_10 = 1 ;
F_8 ( & V_9 ) ;
F_32 ( V_5 -> V_4 -> V_58 , & V_5 -> V_18 ) ;
return;
}
F_33 (con_req_eve, &ctx->file->event_list, list) {
if ( V_55 -> V_19 == V_19 &&
V_55 -> V_51 . V_45 == V_59 ) {
F_34 ( & V_55 -> V_22 ) ;
F_20 ( & V_55 -> V_18 , F_12 ) ;
F_32 ( V_5 -> V_4 -> V_58 , & V_55 -> V_18 ) ;
V_56 = 1 ;
break;
}
}
if ( ! V_56 )
F_35 ( L_1 ) ;
}
static int F_36 ( struct V_53 * V_19 ,
struct V_44 * V_45 )
{
struct V_16 * V_46 ;
struct V_1 * V_5 = V_19 -> V_54 ;
int V_60 = 0 ;
V_46 = F_19 ( sizeof( * V_46 ) , V_20 ) ;
if ( ! V_46 )
return V_45 -> V_45 == V_59 ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_46 -> V_19 = V_19 ;
F_30 ( V_5 , V_45 , V_46 ) ;
V_46 -> V_51 . V_45 = V_45 -> V_45 ;
V_46 -> V_51 . V_61 = V_45 -> V_61 ;
if ( V_19 -> V_62 == V_63 )
F_28 ( & V_46 -> V_51 . V_49 . V_50 , & V_45 -> V_49 . V_50 ) ;
else
F_27 ( & V_46 -> V_51 . V_49 . V_64 ,
& V_45 -> V_49 . V_64 ) ;
if ( V_45 -> V_45 == V_59 ) {
if ( ! V_5 -> V_65 ) {
V_60 = - V_66 ;
F_15 ( V_46 ) ;
goto V_67;
}
V_5 -> V_65 -- ;
} else if ( ! V_5 -> V_52 || V_5 -> V_19 != V_19 ) {
if ( V_45 -> V_45 == V_68 )
F_31 ( V_19 ) ;
F_15 ( V_46 ) ;
goto V_67;
}
F_25 ( & V_46 -> V_22 , & V_5 -> V_4 -> V_69 ) ;
F_37 ( & V_5 -> V_4 -> V_70 ) ;
if ( V_45 -> V_45 == V_68 )
F_31 ( V_19 ) ;
V_67:
F_8 ( & V_5 -> V_4 -> V_9 ) ;
return V_60 ;
}
static T_1 F_38 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_1 * V_5 ;
struct V_74 V_75 ;
struct V_16 * V_46 ;
int V_60 = 0 ;
if ( V_73 < sizeof V_46 -> V_51 )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_40 ( & V_4 -> V_69 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_78 -> V_79 & V_80 )
return - V_81 ;
if ( F_41 ( V_4 -> V_70 ,
! F_40 ( & V_4 -> V_69 ) ) )
return - V_82 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_46 = F_42 ( V_4 -> V_69 . V_83 , struct V_16 , V_22 ) ;
if ( V_46 -> V_51 . V_45 == V_59 ) {
V_5 = F_18 ( V_4 ) ;
if ( ! V_5 ) {
V_60 = - V_66 ;
goto V_84;
}
V_46 -> V_5 -> V_65 ++ ;
V_5 -> V_19 = V_46 -> V_19 ;
V_5 -> V_19 -> V_54 = V_5 ;
V_46 -> V_51 . V_2 = V_5 -> V_2 ;
}
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_46 -> V_51 , sizeof V_46 -> V_51 ) ) {
V_60 = - V_77 ;
goto V_84;
}
F_34 ( & V_46 -> V_22 ) ;
V_46 -> V_5 -> V_86 ++ ;
if ( V_46 -> V_25 )
V_46 -> V_25 -> V_86 ++ ;
F_15 ( V_46 ) ;
V_84:
F_8 ( & V_4 -> V_9 ) ;
return V_60 ;
}
static int F_44 ( struct V_87 * V_75 , enum V_88 * V_62 )
{
switch ( V_75 -> V_89 ) {
case V_90 :
* V_62 = V_91 ;
return 0 ;
case V_92 :
case V_93 :
* V_62 = V_63 ;
return 0 ;
case V_94 :
* V_62 = V_75 -> V_62 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_45 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_87 V_75 ;
struct V_95 V_51 ;
struct V_1 * V_5 ;
enum V_88 V_62 ;
int V_60 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_60 = F_44 ( & V_75 , & V_62 ) ;
if ( V_60 )
return V_60 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_18 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_66 ;
V_5 -> V_52 = V_75 . V_52 ;
V_5 -> V_19 = F_46 ( V_96 -> V_97 -> V_98 ,
F_36 , V_5 , V_75 . V_89 , V_62 ) ;
if ( F_6 ( V_5 -> V_19 ) ) {
V_60 = F_47 ( V_5 -> V_19 ) ;
goto V_99;
}
V_51 . V_2 = V_5 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) ) {
V_60 = - V_77 ;
goto V_100;
}
return 0 ;
V_100:
F_14 ( V_5 -> V_19 ) ;
V_99:
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_15 ( V_5 ) ;
return V_60 ;
}
static void F_49 ( struct V_1 * V_5 )
{
struct V_24 * V_25 , * V_101 ;
F_5 ( & V_9 ) ;
F_50 (mc, tmp, &ctx->mc_list, list) {
F_34 ( & V_25 -> V_22 ) ;
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_15 ( V_25 ) ;
}
F_8 ( & V_9 ) ;
}
static void F_51 ( struct V_24 * V_25 )
{
struct V_16 * V_46 , * V_101 ;
F_50 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_46 -> V_25 != V_25 )
continue;
F_34 ( & V_46 -> V_22 ) ;
F_15 ( V_46 ) ;
}
}
static int F_52 ( struct V_1 * V_5 )
{
int V_86 ;
struct V_16 * V_46 , * V_101 ;
F_53 ( V_22 ) ;
F_49 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
F_50 (uevent, tmp, &ctx->file->event_list, list) {
if ( V_46 -> V_5 == V_5 )
F_54 ( & V_46 -> V_22 , & V_22 ) ;
}
F_34 ( & V_5 -> V_22 ) ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_50 (uevent, tmp, &list, list) {
F_34 ( & V_46 -> V_22 ) ;
if ( V_46 -> V_51 . V_45 == V_59 )
F_14 ( V_46 -> V_19 ) ;
F_15 ( V_46 ) ;
}
V_86 = V_5 -> V_86 ;
F_15 ( V_5 ) ;
return V_86 ;
}
static T_1 F_55 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_102 V_75 ;
struct V_103 V_51 ;
struct V_1 * V_5 ;
int V_60 = 0 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_75 . V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) )
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_5 -> V_57 = 1 ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_56 ( V_5 -> V_4 -> V_58 ) ;
F_5 ( & V_9 ) ;
if ( ! V_5 -> V_10 ) {
F_8 ( & V_9 ) ;
F_9 ( V_5 ) ;
F_17 ( & V_5 -> V_13 ) ;
F_14 ( V_5 -> V_19 ) ;
} else {
F_8 ( & V_9 ) ;
}
V_51 . V_86 = F_52 ( V_5 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
return V_60 ;
}
static T_1 F_57 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_104 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_58 ( V_5 -> V_19 , (struct V_105 * ) & V_75 . V_106 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_59 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_107 V_75 ;
struct V_105 * V_106 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_106 = (struct V_105 * ) & V_75 . V_106 ;
if ( V_75 . V_108 || ! V_75 . V_109 || ( V_75 . V_109 != F_60 ( V_106 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_58 ( V_5 -> V_19 , V_106 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_61 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_110 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_62 ( V_5 -> V_19 , (struct V_105 * ) & V_75 . V_111 ,
(struct V_105 * ) & V_75 . V_112 ,
V_75 . V_113 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_63 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_114 V_75 ;
struct V_105 * V_30 , * V_28 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_30 = (struct V_105 * ) & V_75 . V_111 ;
V_28 = (struct V_105 * ) & V_75 . V_112 ;
if ( V_75 . V_108 || ( V_75 . V_115 && ( V_75 . V_115 != F_60 ( V_30 ) ) ) ||
! V_75 . V_116 || ( V_75 . V_116 != F_60 ( V_28 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_62 ( V_5 -> V_19 , V_30 , V_28 , V_75 . V_113 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_64 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_117 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_65 ( V_5 -> V_19 , V_75 . V_113 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static void F_66 ( struct V_118 * V_51 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 ;
V_51 -> V_123 = V_120 -> V_123 ;
switch ( V_120 -> V_123 ) {
case 0 :
V_122 = & V_120 -> V_106 . V_122 ;
F_67 ( V_122 ,
(union V_124 * ) & V_51 -> V_125 [ 0 ] . V_126 ) ;
F_68 ( V_122 ,
(union V_124 * ) & V_51 -> V_125 [ 0 ] . V_127 ) ;
V_51 -> V_125 [ 0 ] . V_128 = F_69 ( F_70 ( V_122 ) ) ;
break;
case 2 :
F_71 ( & V_51 -> V_125 [ 1 ] ,
& V_120 -> V_129 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_125 [ 0 ] ,
& V_120 -> V_129 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_118 * V_51 ,
struct V_119 * V_120 )
{
V_51 -> V_123 = V_120 -> V_123 ;
switch ( V_120 -> V_123 ) {
case 0 :
F_73 ( (struct V_105 * ) & V_120 -> V_106 . V_112 ,
(union V_124 * ) & V_51 -> V_125 [ 0 ] . V_126 ) ;
F_73 ( (struct V_105 * ) & V_120 -> V_106 . V_111 ,
(union V_124 * ) & V_51 -> V_125 [ 0 ] . V_127 ) ;
V_51 -> V_125 [ 0 ] . V_128 = F_69 ( 0xffff ) ;
break;
case 2 :
F_71 ( & V_51 -> V_125 [ 1 ] ,
& V_120 -> V_129 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_125 [ 0 ] ,
& V_120 -> V_129 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_74 ( struct V_118 * V_51 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 ;
V_122 = & V_120 -> V_106 . V_122 ;
F_67 ( V_122 , (union V_124 * ) & V_51 -> V_125 [ 0 ] . V_126 ) ;
F_68 ( V_122 , (union V_124 * ) & V_51 -> V_125 [ 0 ] . V_127 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_130 V_75 ;
struct V_118 V_51 ;
struct V_1 * V_5 ;
struct V_105 * V_106 ;
int V_60 = 0 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_106 = (struct V_105 * ) & V_5 -> V_19 -> V_120 . V_106 . V_111 ;
memcpy ( & V_51 . V_111 , V_106 , V_106 -> V_131 == V_132 ?
sizeof( struct V_133 ) :
sizeof( struct V_134 ) ) ;
V_106 = (struct V_105 * ) & V_5 -> V_19 -> V_120 . V_106 . V_112 ;
memcpy ( & V_51 . V_112 , V_106 , V_106 -> V_131 == V_132 ?
sizeof( struct V_133 ) :
sizeof( struct V_134 ) ) ;
if ( ! V_5 -> V_19 -> V_135 )
goto V_67;
V_51 . V_136 = ( V_137 V_138 ) V_5 -> V_19 -> V_135 -> V_136 ;
V_51 . V_139 = V_5 -> V_19 -> V_139 ;
if ( F_76 ( V_5 -> V_19 -> V_135 , V_5 -> V_19 -> V_139 ) )
F_66 ( & V_51 , & V_5 -> V_19 -> V_120 ) ;
else if ( F_77 ( V_5 -> V_19 -> V_135 , V_5 -> V_19 -> V_139 ) )
F_72 ( & V_51 , & V_5 -> V_19 -> V_120 ) ;
else if ( F_78 ( V_5 -> V_19 -> V_135 , V_5 -> V_19 -> V_139 ) )
F_74 ( & V_51 , & V_5 -> V_19 -> V_120 ) ;
V_67:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
F_9 ( V_5 ) ;
return V_60 ;
}
static void F_79 ( struct V_53 * V_19 ,
struct V_140 * V_51 )
{
if ( ! V_19 -> V_135 )
return;
V_51 -> V_136 = ( V_137 V_138 ) V_19 -> V_135 -> V_136 ;
V_51 -> V_139 = V_19 -> V_139 ;
V_51 -> V_128 = ( V_137 V_141 ) F_69 (
F_70 ( & V_19 -> V_120 . V_106 . V_122 ) ) ;
}
static T_1 F_80 ( struct V_1 * V_5 ,
void T_2 * V_85 , int V_73 )
{
struct V_140 V_51 ;
struct V_105 * V_106 ;
int V_60 = 0 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_106 = (struct V_105 * ) & V_5 -> V_19 -> V_120 . V_106 . V_111 ;
V_51 . V_115 = F_60 ( V_106 ) ;
memcpy ( & V_51 . V_111 , V_106 , V_51 . V_115 ) ;
V_106 = (struct V_105 * ) & V_5 -> V_19 -> V_120 . V_106 . V_112 ;
V_51 . V_116 = F_60 ( V_106 ) ;
memcpy ( & V_51 . V_112 , V_106 , V_51 . V_116 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
if ( F_43 ( V_85 , & V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
return V_60 ;
}
static T_1 F_81 ( struct V_1 * V_5 ,
void T_2 * V_85 , int V_73 )
{
struct V_142 * V_51 ;
int V_143 , V_60 = 0 ;
if ( V_73 < sizeof( * V_51 ) )
return - V_76 ;
V_51 = F_19 ( V_73 , V_20 ) ;
if ( ! V_51 )
return - V_66 ;
V_51 -> V_123 = V_5 -> V_19 -> V_120 . V_123 ;
for ( V_143 = 0 , V_73 -= sizeof( * V_51 ) ;
V_143 < V_51 -> V_123 && V_73 > sizeof( struct V_144 ) ;
V_143 ++ , V_73 -= sizeof( struct V_144 ) ) {
struct V_145 * V_146 = & V_5 -> V_19 -> V_120 . V_129 [ V_143 ] ;
V_51 -> V_147 [ V_143 ] . V_148 = V_149 | V_150 |
V_151 ;
if ( V_146 -> V_152 == V_153 ) {
F_82 ( V_146 , & V_51 -> V_147 [ V_143 ] . V_129 ) ;
} else {
struct V_145 V_154 ;
F_83 ( & V_154 , V_146 ) ;
F_82 ( & V_154 , & V_51 -> V_147 [ V_143 ] . V_129 ) ;
}
}
if ( F_43 ( V_85 , V_51 ,
sizeof( * V_51 ) + ( V_143 * sizeof( struct V_144 ) ) ) )
V_60 = - V_77 ;
F_15 ( V_51 ) ;
return V_60 ;
}
static T_1 F_84 ( struct V_1 * V_5 ,
void T_2 * V_85 , int V_73 )
{
struct V_140 V_51 ;
struct V_155 * V_106 ;
int V_60 = 0 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
V_106 = (struct V_155 * ) & V_51 . V_111 ;
V_51 . V_115 = sizeof( * V_106 ) ;
if ( V_5 -> V_19 -> V_120 . V_106 . V_111 . V_156 == V_157 ) {
memcpy ( V_106 , & V_5 -> V_19 -> V_120 . V_106 . V_111 , V_51 . V_115 ) ;
} else {
V_106 -> V_158 = V_157 ;
V_106 -> V_159 = ( V_137 V_160 ) V_51 . V_128 ;
F_68 ( & V_5 -> V_19 -> V_120 . V_106 . V_122 ,
(union V_124 * ) & V_106 -> V_161 ) ;
V_106 -> V_162 = F_85 ( V_5 -> V_19 , (struct V_105 * )
& V_5 -> V_19 -> V_120 . V_106 . V_111 ) ;
}
V_106 = (struct V_155 * ) & V_51 . V_112 ;
V_51 . V_116 = sizeof( * V_106 ) ;
if ( V_5 -> V_19 -> V_120 . V_106 . V_112 . V_156 == V_157 ) {
memcpy ( V_106 , & V_5 -> V_19 -> V_120 . V_106 . V_112 , V_51 . V_116 ) ;
} else {
V_106 -> V_158 = V_157 ;
V_106 -> V_159 = ( V_137 V_160 ) V_51 . V_128 ;
F_67 ( & V_5 -> V_19 -> V_120 . V_106 . V_122 ,
(union V_124 * ) & V_106 -> V_161 ) ;
V_106 -> V_162 = F_85 ( V_5 -> V_19 , (struct V_105 * )
& V_5 -> V_19 -> V_120 . V_106 . V_112 ) ;
}
if ( F_43 ( V_85 , & V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
return V_60 ;
}
static T_1 F_86 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_130 V_75 ;
struct V_1 * V_5 ;
void T_2 * V_85 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_85 = ( void T_2 * ) ( unsigned long ) V_75 . V_85 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
switch ( V_75 . V_163 ) {
case V_164 :
V_60 = F_80 ( V_5 , V_85 , V_73 ) ;
break;
case V_165 :
V_60 = F_81 ( V_5 , V_85 , V_73 ) ;
break;
case V_166 :
V_60 = F_84 ( V_5 , V_85 , V_73 ) ;
break;
default:
V_60 = - V_167 ;
break;
}
F_9 ( V_5 ) ;
return V_60 ;
}
static void F_87 ( struct V_53 * V_2 ,
struct V_29 * V_28 ,
struct V_27 * V_30 )
{
V_28 -> V_32 = V_30 -> V_32 ;
V_28 -> V_31 = V_30 -> V_31 ;
V_28 -> V_33 = V_30 -> V_33 ;
V_28 -> V_34 = V_30 -> V_34 ;
V_28 -> V_35 = V_30 -> V_35 ;
V_28 -> V_36 = V_30 -> V_36 ;
V_28 -> V_37 = V_30 -> V_37 ;
V_28 -> V_38 = V_30 -> V_38 ;
V_28 -> V_39 = V_30 -> V_39 ;
V_28 -> V_43 = ( V_2 -> V_120 . V_106 . V_111 . V_156 == V_157 ) ? V_30 -> V_43 : 0 ;
}
static T_1 F_88 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_168 V_75 ;
struct V_29 V_169 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
if ( ! V_75 . V_169 . V_170 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_87 ( V_5 -> V_19 , & V_169 , & V_75 . V_169 ) ;
V_60 = F_89 ( V_5 -> V_19 , & V_169 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_90 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_171 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_5 -> V_65 = V_75 . V_65 > 0 && V_75 . V_65 < V_172 ?
V_75 . V_65 : V_172 ;
V_60 = F_91 ( V_5 -> V_19 , V_5 -> V_65 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_92 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_173 V_75 ;
struct V_29 V_169 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
if ( V_75 . V_169 . V_170 ) {
F_87 ( V_5 -> V_19 , & V_169 , & V_75 . V_169 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_60 = F_93 ( V_5 -> V_19 , & V_169 ) ;
if ( ! V_60 )
V_5 -> V_52 = V_75 . V_52 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_60 = F_93 ( V_5 -> V_19 , NULL ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_94 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_174 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_95 ( V_5 -> V_19 , V_75 . V_32 , V_75 . V_31 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_96 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_175 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_97 ( V_5 -> V_19 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_98 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_176 V_75 ;
struct V_177 V_51 ;
struct V_1 * V_5 ;
struct V_178 V_179 ;
int V_60 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_51 . V_180 = 0 ;
memset ( & V_179 , 0 , sizeof V_179 ) ;
V_179 . V_181 = V_75 . V_181 ;
V_60 = F_99 ( V_5 -> V_19 , & V_179 , & V_51 . V_180 ) ;
if ( V_60 )
goto V_67;
F_100 ( & V_51 , & V_179 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
V_67:
F_9 ( V_5 ) ;
return V_60 ;
}
static int F_101 ( struct V_1 * V_5 , int V_182 ,
void * V_183 , T_3 V_184 )
{
int V_60 = 0 ;
switch ( V_182 ) {
case V_185 :
if ( V_184 != sizeof( V_186 ) ) {
V_60 = - V_8 ;
break;
}
F_102 ( V_5 -> V_19 , * ( ( V_186 * ) V_183 ) ) ;
break;
case V_187 :
if ( V_184 != sizeof( int ) ) {
V_60 = - V_8 ;
break;
}
V_60 = F_103 ( V_5 -> V_19 , * ( ( int * ) V_183 ) ? 1 : 0 ) ;
break;
case V_188 :
if ( V_184 != sizeof( int ) ) {
V_60 = - V_8 ;
break;
}
V_60 = F_104 ( V_5 -> V_19 , * ( ( int * ) V_183 ) ? 1 : 0 ) ;
break;
default:
V_60 = - V_167 ;
}
return V_60 ;
}
static int F_105 ( struct V_1 * V_5 ,
struct V_144 * V_147 , T_3 V_184 )
{
struct V_145 V_189 ;
struct V_44 V_45 ;
int V_60 ;
if ( V_184 % sizeof( * V_147 ) )
return - V_8 ;
for (; V_184 ; V_184 -= sizeof( * V_147 ) , V_147 ++ ) {
if ( V_147 -> V_148 == ( V_149 | V_150 |
V_151 ) )
break;
}
if ( ! V_184 )
return - V_8 ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_152 = V_153 ;
F_106 ( V_147 -> V_129 , & V_189 ) ;
if ( F_107 ( V_5 -> V_19 -> V_135 , V_5 -> V_19 -> V_139 ) ) {
struct V_145 V_190 ;
F_108 ( & V_190 , & V_189 ) ;
V_60 = F_109 ( V_5 -> V_19 , & V_190 , 1 ) ;
} else {
V_60 = F_109 ( V_5 -> V_19 , & V_189 , 1 ) ;
}
if ( V_60 )
return V_60 ;
memset ( & V_45 , 0 , sizeof V_45 ) ;
V_45 . V_45 = V_191 ;
return F_36 ( V_5 -> V_19 , & V_45 ) ;
}
static int F_110 ( struct V_1 * V_5 , int V_182 ,
void * V_183 , T_3 V_184 )
{
int V_60 ;
switch ( V_182 ) {
case V_192 :
V_60 = F_105 ( V_5 , V_183 , V_184 ) ;
break;
default:
V_60 = - V_167 ;
}
return V_60 ;
}
static int F_111 ( struct V_1 * V_5 , int V_193 ,
int V_182 , void * V_183 , T_3 V_184 )
{
int V_60 ;
switch ( V_193 ) {
case V_194 :
V_60 = F_101 ( V_5 , V_182 , V_183 , V_184 ) ;
break;
case V_195 :
V_60 = F_110 ( V_5 , V_182 , V_183 , V_184 ) ;
break;
default:
V_60 = - V_167 ;
}
return V_60 ;
}
static T_1 F_112 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_196 V_75 ;
struct V_1 * V_5 ;
void * V_183 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_183 = F_113 ( ( void T_2 * ) ( unsigned long ) V_75 . V_183 ,
V_75 . V_184 ) ;
if ( F_6 ( V_183 ) ) {
V_60 = F_47 ( V_183 ) ;
goto V_67;
}
V_60 = F_111 ( V_5 , V_75 . V_193 , V_75 . V_182 , V_183 ,
V_75 . V_184 ) ;
F_15 ( V_183 ) ;
V_67:
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_114 ( struct V_3 * V_4 , const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_197 V_75 ;
struct V_1 * V_5 ;
int V_60 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_5 = F_4 ( V_4 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_60 = F_115 ( V_5 -> V_19 , (enum V_198 ) V_75 . V_45 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_116 ( struct V_3 * V_4 ,
struct V_199 * V_75 , int V_73 )
{
struct V_95 V_51 ;
struct V_1 * V_5 ;
struct V_24 * V_25 ;
struct V_105 * V_106 ;
int V_60 ;
V_186 V_200 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
V_106 = (struct V_105 * ) & V_75 -> V_106 ;
if ( ! V_75 -> V_109 || ( V_75 -> V_109 != F_60 ( V_106 ) ) )
return - V_8 ;
if ( V_75 -> V_201 == V_202 )
V_200 = F_117 ( V_203 ) ;
else if ( V_75 -> V_201 == V_204 )
V_200 = F_117 ( V_205 ) ;
else
return - V_8 ;
V_5 = F_4 ( V_4 , V_75 -> V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_25 = F_26 ( V_5 ) ;
if ( ! V_25 ) {
V_60 = - V_66 ;
goto V_99;
}
V_25 -> V_200 = V_200 ;
V_25 -> V_52 = V_75 -> V_52 ;
memcpy ( & V_25 -> V_106 , V_106 , V_75 -> V_109 ) ;
V_60 = F_118 ( V_5 -> V_19 , (struct V_105 * ) & V_25 -> V_106 ,
V_200 , V_25 ) ;
if ( V_60 )
goto V_100;
V_51 . V_2 = V_25 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 -> V_85 ,
& V_51 , sizeof( V_51 ) ) ) {
V_60 = - V_77 ;
goto V_206;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_206:
F_119 ( V_5 -> V_19 , (struct V_105 * ) & V_25 -> V_106 ) ;
F_51 ( V_25 ) ;
V_100:
F_5 ( & V_9 ) ;
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_15 ( V_25 ) ;
V_99:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_60 ;
}
static T_1 F_120 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_207 V_75 ;
struct V_199 V_208 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_208 . V_85 = V_75 . V_85 ;
V_208 . V_52 = V_75 . V_52 ;
V_208 . V_2 = V_75 . V_2 ;
V_208 . V_109 = F_60 ( (struct V_105 * ) & V_75 . V_106 ) ;
V_208 . V_201 = V_202 ;
memcpy ( & V_208 . V_106 , & V_75 . V_106 , V_208 . V_109 ) ;
return F_116 ( V_4 , & V_208 , V_73 ) ;
}
static T_1 F_121 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_199 V_75 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
return F_116 ( V_4 , & V_75 , V_73 ) ;
}
static T_1 F_122 ( struct V_3 * V_4 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_102 V_75 ;
struct V_103 V_51 ;
struct V_24 * V_25 ;
int V_60 = 0 ;
if ( V_73 < sizeof( V_51 ) )
return - V_76 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
F_5 ( & V_9 ) ;
V_25 = F_2 ( & V_26 , V_75 . V_2 ) ;
if ( ! V_25 )
V_25 = F_3 ( - V_7 ) ;
else if ( V_25 -> V_5 -> V_4 != V_4 )
V_25 = F_3 ( - V_8 ) ;
else if ( ! F_123 ( & V_25 -> V_5 -> V_12 ) )
V_25 = F_3 ( - V_209 ) ;
else
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_25 ) ) {
V_60 = F_47 ( V_25 ) ;
goto V_67;
}
F_119 ( V_25 -> V_5 -> V_19 , (struct V_105 * ) & V_25 -> V_106 ) ;
F_5 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_51 ( V_25 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_8 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_25 -> V_5 ) ;
V_51 . V_86 = V_25 -> V_86 ;
F_15 ( V_25 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
V_67:
return V_60 ;
}
static void F_124 ( struct V_3 * V_210 , struct V_3 * V_211 )
{
if ( V_210 < V_211 ) {
F_5 ( & V_210 -> V_9 ) ;
F_125 ( & V_211 -> V_9 , V_212 ) ;
} else {
F_5 ( & V_211 -> V_9 ) ;
F_125 ( & V_210 -> V_9 , V_212 ) ;
}
}
static void F_126 ( struct V_3 * V_210 , struct V_3 * V_211 )
{
if ( V_210 < V_211 ) {
F_8 ( & V_211 -> V_9 ) ;
F_8 ( & V_210 -> V_9 ) ;
} else {
F_8 ( & V_210 -> V_9 ) ;
F_8 ( & V_211 -> V_9 ) ;
}
}
static void F_127 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_16 * V_46 , * V_101 ;
F_50 (uevent, tmp, &ctx->file->event_list, list)
if ( V_46 -> V_5 == V_5 )
F_54 ( & V_46 -> V_22 , & V_4 -> V_69 ) ;
}
static T_1 F_128 ( struct V_3 * V_213 ,
const char T_2 * V_71 ,
int V_72 , int V_73 )
{
struct V_214 V_75 ;
struct V_215 V_51 ;
struct V_1 * V_5 ;
struct V_216 V_217 ;
struct V_3 * V_218 ;
int V_60 = 0 ;
if ( F_39 ( & V_75 , V_71 , sizeof( V_75 ) ) )
return - V_77 ;
V_217 = F_129 ( V_75 . V_216 ) ;
if ( ! V_217 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_217 . V_4 -> V_32 , V_75 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_60 = F_47 ( V_5 ) ;
goto V_219;
}
V_218 = V_5 -> V_4 ;
if ( V_218 == V_213 ) {
V_51 . V_86 = V_5 -> V_86 ;
goto V_85;
}
F_124 ( V_218 , V_213 ) ;
F_5 ( & V_9 ) ;
F_54 ( & V_5 -> V_22 , & V_213 -> V_23 ) ;
F_127 ( V_5 , V_213 ) ;
V_5 -> V_4 = V_213 ;
V_51 . V_86 = V_5 -> V_86 ;
F_8 ( & V_9 ) ;
F_126 ( V_218 , V_213 ) ;
V_85:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_75 . V_85 ,
& V_51 , sizeof( V_51 ) ) )
V_60 = - V_77 ;
F_9 ( V_5 ) ;
V_219:
F_130 ( V_217 ) ;
return V_60 ;
}
static T_1 F_131 ( struct V_4 * V_78 , const char T_2 * V_220 ,
T_3 V_221 , T_4 * V_222 )
{
struct V_3 * V_4 = V_78 -> V_32 ;
struct V_223 V_224 ;
T_1 V_60 ;
if ( ! F_132 ( V_78 ) ) {
F_133 ( L_2 ,
F_134 ( V_96 ) , V_96 -> V_225 ) ;
return - V_226 ;
}
if ( V_221 < sizeof( V_224 ) )
return - V_8 ;
if ( F_39 ( & V_224 , V_220 , sizeof( V_224 ) ) )
return - V_77 ;
if ( V_224 . V_75 >= F_135 ( V_227 ) )
return - V_8 ;
if ( V_224 . V_228 + sizeof( V_224 ) > V_221 )
return - V_8 ;
if ( ! V_227 [ V_224 . V_75 ] )
return - V_167 ;
V_60 = V_227 [ V_224 . V_75 ] ( V_4 , V_220 + sizeof( V_224 ) , V_224 . V_228 , V_224 . V_67 ) ;
if ( ! V_60 )
V_60 = V_221 ;
return V_60 ;
}
static unsigned int F_136 ( struct V_4 * V_78 , struct V_229 * V_230 )
{
struct V_3 * V_4 = V_78 -> V_32 ;
unsigned int V_231 = 0 ;
V_70 ( V_78 , & V_4 -> V_70 , V_230 ) ;
if ( ! F_40 ( & V_4 -> V_69 ) )
V_231 = V_232 | V_233 ;
return V_231 ;
}
static int F_137 ( struct V_234 * V_234 , struct V_4 * V_78 )
{
struct V_3 * V_4 ;
V_4 = F_138 ( sizeof *V_4 , V_20 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 -> V_58 = F_139 ( L_3 ,
V_235 ) ;
if ( ! V_4 -> V_58 ) {
F_15 ( V_4 ) ;
return - V_66 ;
}
F_23 ( & V_4 -> V_69 ) ;
F_23 ( & V_4 -> V_23 ) ;
F_140 ( & V_4 -> V_70 ) ;
F_141 ( & V_4 -> V_9 ) ;
V_78 -> V_32 = V_4 ;
V_4 -> V_78 = V_78 ;
return F_142 ( V_234 , V_78 ) ;
}
static int F_143 ( struct V_234 * V_234 , struct V_4 * V_78 )
{
struct V_3 * V_4 = V_78 -> V_32 ;
struct V_1 * V_5 , * V_101 ;
F_5 ( & V_4 -> V_9 ) ;
F_50 (ctx, tmp, &file->ctx_list, list) {
V_5 -> V_57 = 1 ;
F_8 ( & V_4 -> V_9 ) ;
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_56 ( V_4 -> V_58 ) ;
F_5 ( & V_9 ) ;
if ( ! V_5 -> V_10 ) {
F_8 ( & V_9 ) ;
F_14 ( V_5 -> V_19 ) ;
} else {
F_8 ( & V_9 ) ;
}
F_52 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_4 -> V_9 ) ;
F_144 ( V_4 -> V_58 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
static T_1 F_145 ( struct V_135 * V_236 ,
struct V_237 * V_238 ,
char * V_220 )
{
return sprintf ( V_220 , L_4 , V_239 ) ;
}
static int T_5 F_146 ( void )
{
int V_60 ;
V_60 = F_147 ( & V_240 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_148 ( V_240 . V_241 , & V_242 ) ;
if ( V_60 ) {
F_35 ( L_5 ) ;
goto V_99;
}
V_243 = F_149 ( & V_244 , L_6 , V_245 ) ;
if ( ! V_243 ) {
F_35 ( L_7 ) ;
V_60 = - V_66 ;
goto V_100;
}
return 0 ;
V_100:
F_150 ( V_240 . V_241 , & V_242 ) ;
V_99:
F_151 ( & V_240 ) ;
return V_60 ;
}
static void T_6 F_152 ( void )
{
F_153 ( V_243 ) ;
F_150 ( V_240 . V_241 , & V_242 ) ;
F_151 ( & V_240 ) ;
F_154 ( & V_6 ) ;
F_154 ( & V_26 ) ;
}
