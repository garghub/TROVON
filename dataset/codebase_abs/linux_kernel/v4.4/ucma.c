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
F_35 ( V_60 L_1 ) ;
}
static int F_36 ( struct V_53 * V_19 ,
struct V_44 * V_45 )
{
struct V_16 * V_46 ;
struct V_1 * V_5 = V_19 -> V_54 ;
int V_61 = 0 ;
V_46 = F_19 ( sizeof( * V_46 ) , V_20 ) ;
if ( ! V_46 )
return V_45 -> V_45 == V_59 ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_46 -> V_19 = V_19 ;
F_30 ( V_5 , V_45 , V_46 ) ;
V_46 -> V_51 . V_45 = V_45 -> V_45 ;
V_46 -> V_51 . V_62 = V_45 -> V_62 ;
if ( V_19 -> V_63 == V_64 )
F_28 ( & V_46 -> V_51 . V_49 . V_50 , & V_45 -> V_49 . V_50 ) ;
else
F_27 ( & V_46 -> V_51 . V_49 . V_65 ,
& V_45 -> V_49 . V_65 ) ;
if ( V_45 -> V_45 == V_59 ) {
if ( ! V_5 -> V_66 ) {
V_61 = - V_67 ;
F_15 ( V_46 ) ;
goto V_68;
}
V_5 -> V_66 -- ;
} else if ( ! V_5 -> V_52 || V_5 -> V_19 != V_19 ) {
if ( V_45 -> V_45 == V_69 )
F_31 ( V_19 ) ;
F_15 ( V_46 ) ;
goto V_68;
}
F_25 ( & V_46 -> V_22 , & V_5 -> V_4 -> V_70 ) ;
F_37 ( & V_5 -> V_4 -> V_71 ) ;
if ( V_45 -> V_45 == V_69 )
F_31 ( V_19 ) ;
V_68:
F_8 ( & V_5 -> V_4 -> V_9 ) ;
return V_61 ;
}
static T_1 F_38 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_1 * V_5 ;
struct V_75 V_76 ;
struct V_16 * V_46 ;
int V_61 = 0 ;
if ( V_74 < sizeof V_46 -> V_51 )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_40 ( & V_4 -> V_70 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_79 -> V_80 & V_81 )
return - V_82 ;
if ( F_41 ( V_4 -> V_71 ,
! F_40 ( & V_4 -> V_70 ) ) )
return - V_83 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_46 = F_42 ( V_4 -> V_70 . V_84 , struct V_16 , V_22 ) ;
if ( V_46 -> V_51 . V_45 == V_59 ) {
V_5 = F_18 ( V_4 ) ;
if ( ! V_5 ) {
V_61 = - V_67 ;
goto V_85;
}
V_46 -> V_5 -> V_66 ++ ;
V_5 -> V_19 = V_46 -> V_19 ;
V_5 -> V_19 -> V_54 = V_5 ;
V_46 -> V_51 . V_2 = V_5 -> V_2 ;
}
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_46 -> V_51 , sizeof V_46 -> V_51 ) ) {
V_61 = - V_78 ;
goto V_85;
}
F_34 ( & V_46 -> V_22 ) ;
V_46 -> V_5 -> V_87 ++ ;
if ( V_46 -> V_25 )
V_46 -> V_25 -> V_87 ++ ;
F_15 ( V_46 ) ;
V_85:
F_8 ( & V_4 -> V_9 ) ;
return V_61 ;
}
static int F_44 ( struct V_88 * V_76 , enum V_89 * V_63 )
{
switch ( V_76 -> V_90 ) {
case V_91 :
* V_63 = V_92 ;
return 0 ;
case V_93 :
case V_94 :
* V_63 = V_64 ;
return 0 ;
case V_95 :
* V_63 = V_76 -> V_63 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_45 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_88 V_76 ;
struct V_96 V_51 ;
struct V_1 * V_5 ;
enum V_89 V_63 ;
int V_61 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_61 = F_44 ( & V_76 , & V_63 ) ;
if ( V_61 )
return V_61 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_18 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_67 ;
V_5 -> V_52 = V_76 . V_52 ;
V_5 -> V_19 = F_46 ( V_97 -> V_98 -> V_99 ,
F_36 , V_5 , V_76 . V_90 , V_63 ) ;
if ( F_6 ( V_5 -> V_19 ) ) {
V_61 = F_47 ( V_5 -> V_19 ) ;
goto V_100;
}
V_51 . V_2 = V_5 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) ) {
V_61 = - V_78 ;
goto V_101;
}
return 0 ;
V_101:
F_14 ( V_5 -> V_19 ) ;
V_100:
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_15 ( V_5 ) ;
return V_61 ;
}
static void F_49 ( struct V_1 * V_5 )
{
struct V_24 * V_25 , * V_102 ;
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
struct V_16 * V_46 , * V_102 ;
F_50 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_46 -> V_25 != V_25 )
continue;
F_34 ( & V_46 -> V_22 ) ;
F_15 ( V_46 ) ;
}
}
static int F_52 ( struct V_1 * V_5 )
{
int V_87 ;
struct V_16 * V_46 , * V_102 ;
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
V_87 = V_5 -> V_87 ;
F_15 ( V_5 ) ;
return V_87 ;
}
static T_1 F_55 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_103 V_76 ;
struct V_104 V_51 ;
struct V_1 * V_5 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_76 . V_2 , V_4 ) ;
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
V_51 . V_87 = F_52 ( V_5 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
return V_61 ;
}
static T_1 F_57 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_105 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_58 ( V_5 -> V_19 , (struct V_106 * ) & V_76 . V_107 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_59 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_108 V_76 ;
struct V_106 * V_107 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_107 = (struct V_106 * ) & V_76 . V_107 ;
if ( V_76 . V_109 || ! V_76 . V_110 || ( V_76 . V_110 != F_60 ( V_107 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_58 ( V_5 -> V_19 , V_107 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_61 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_111 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_62 ( V_5 -> V_19 , (struct V_106 * ) & V_76 . V_112 ,
(struct V_106 * ) & V_76 . V_113 ,
V_76 . V_114 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_63 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_115 V_76 ;
struct V_106 * V_30 , * V_28 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_30 = (struct V_106 * ) & V_76 . V_112 ;
V_28 = (struct V_106 * ) & V_76 . V_113 ;
if ( V_76 . V_109 || ( V_76 . V_116 && ( V_76 . V_116 != F_60 ( V_30 ) ) ) ||
! V_76 . V_117 || ( V_76 . V_117 != F_60 ( V_28 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_62 ( V_5 -> V_19 , V_30 , V_28 , V_76 . V_114 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_64 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_118 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_65 ( V_5 -> V_19 , V_76 . V_114 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static void F_66 ( struct V_119 * V_51 ,
struct V_120 * V_121 )
{
struct V_122 * V_123 ;
V_51 -> V_124 = V_121 -> V_124 ;
switch ( V_121 -> V_124 ) {
case 0 :
V_123 = & V_121 -> V_107 . V_123 ;
F_67 ( V_123 ,
(union V_125 * ) & V_51 -> V_126 [ 0 ] . V_127 ) ;
F_68 ( V_123 ,
(union V_125 * ) & V_51 -> V_126 [ 0 ] . V_128 ) ;
V_51 -> V_126 [ 0 ] . V_129 = F_69 ( F_70 ( V_123 ) ) ;
break;
case 2 :
F_71 ( & V_51 -> V_126 [ 1 ] ,
& V_121 -> V_130 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_126 [ 0 ] ,
& V_121 -> V_130 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_119 * V_51 ,
struct V_120 * V_121 )
{
V_51 -> V_124 = V_121 -> V_124 ;
switch ( V_121 -> V_124 ) {
case 0 :
F_73 ( (struct V_106 * ) & V_121 -> V_107 . V_113 ,
(union V_125 * ) & V_51 -> V_126 [ 0 ] . V_127 ) ;
F_73 ( (struct V_106 * ) & V_121 -> V_107 . V_112 ,
(union V_125 * ) & V_51 -> V_126 [ 0 ] . V_128 ) ;
V_51 -> V_126 [ 0 ] . V_129 = F_69 ( 0xffff ) ;
break;
case 2 :
F_71 ( & V_51 -> V_126 [ 1 ] ,
& V_121 -> V_130 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_126 [ 0 ] ,
& V_121 -> V_130 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_74 ( struct V_119 * V_51 ,
struct V_120 * V_121 )
{
struct V_122 * V_123 ;
V_123 = & V_121 -> V_107 . V_123 ;
F_67 ( V_123 , (union V_125 * ) & V_51 -> V_126 [ 0 ] . V_127 ) ;
F_68 ( V_123 , (union V_125 * ) & V_51 -> V_126 [ 0 ] . V_128 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_131 V_76 ;
struct V_119 V_51 ;
struct V_1 * V_5 ;
struct V_106 * V_107 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_107 = (struct V_106 * ) & V_5 -> V_19 -> V_121 . V_107 . V_112 ;
memcpy ( & V_51 . V_112 , V_107 , V_107 -> V_132 == V_133 ?
sizeof( struct V_134 ) :
sizeof( struct V_135 ) ) ;
V_107 = (struct V_106 * ) & V_5 -> V_19 -> V_121 . V_107 . V_113 ;
memcpy ( & V_51 . V_113 , V_107 , V_107 -> V_132 == V_133 ?
sizeof( struct V_134 ) :
sizeof( struct V_135 ) ) ;
if ( ! V_5 -> V_19 -> V_136 )
goto V_68;
V_51 . V_137 = ( V_138 V_139 ) V_5 -> V_19 -> V_136 -> V_137 ;
V_51 . V_140 = V_5 -> V_19 -> V_140 ;
if ( F_76 ( V_5 -> V_19 -> V_136 , V_5 -> V_19 -> V_140 ) )
F_66 ( & V_51 , & V_5 -> V_19 -> V_121 ) ;
else if ( F_77 ( V_5 -> V_19 -> V_136 , V_5 -> V_19 -> V_140 ) )
F_72 ( & V_51 , & V_5 -> V_19 -> V_121 ) ;
else if ( F_78 ( V_5 -> V_19 -> V_136 , V_5 -> V_19 -> V_140 ) )
F_74 ( & V_51 , & V_5 -> V_19 -> V_121 ) ;
V_68:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
F_9 ( V_5 ) ;
return V_61 ;
}
static void F_79 ( struct V_53 * V_19 ,
struct V_141 * V_51 )
{
if ( ! V_19 -> V_136 )
return;
V_51 -> V_137 = ( V_138 V_139 ) V_19 -> V_136 -> V_137 ;
V_51 -> V_140 = V_19 -> V_140 ;
V_51 -> V_129 = ( V_138 V_142 ) F_69 (
F_70 ( & V_19 -> V_121 . V_107 . V_123 ) ) ;
}
static T_1 F_80 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_141 V_51 ;
struct V_106 * V_107 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_107 = (struct V_106 * ) & V_5 -> V_19 -> V_121 . V_107 . V_112 ;
V_51 . V_116 = F_60 ( V_107 ) ;
memcpy ( & V_51 . V_112 , V_107 , V_51 . V_116 ) ;
V_107 = (struct V_106 * ) & V_5 -> V_19 -> V_121 . V_107 . V_113 ;
V_51 . V_117 = F_60 ( V_107 ) ;
memcpy ( & V_51 . V_113 , V_107 , V_51 . V_117 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
if ( F_43 ( V_86 , & V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
return V_61 ;
}
static T_1 F_81 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_143 * V_51 ;
int V_144 , V_61 = 0 ;
if ( V_74 < sizeof( * V_51 ) )
return - V_77 ;
V_51 = F_19 ( V_74 , V_20 ) ;
if ( ! V_51 )
return - V_67 ;
V_51 -> V_124 = V_5 -> V_19 -> V_121 . V_124 ;
for ( V_144 = 0 , V_74 -= sizeof( * V_51 ) ;
V_144 < V_51 -> V_124 && V_74 > sizeof( struct V_145 ) ;
V_144 ++ , V_74 -= sizeof( struct V_145 ) ) {
V_51 -> V_146 [ V_144 ] . V_147 = V_148 | V_149 |
V_150 ;
F_82 ( & V_5 -> V_19 -> V_121 . V_130 [ V_144 ] ,
& V_51 -> V_146 [ V_144 ] . V_130 ) ;
}
if ( F_43 ( V_86 , V_51 ,
sizeof( * V_51 ) + ( V_144 * sizeof( struct V_145 ) ) ) )
V_61 = - V_78 ;
F_15 ( V_51 ) ;
return V_61 ;
}
static T_1 F_83 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_141 V_51 ;
struct V_151 * V_107 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
V_107 = (struct V_151 * ) & V_51 . V_112 ;
V_51 . V_116 = sizeof( * V_107 ) ;
if ( V_5 -> V_19 -> V_121 . V_107 . V_112 . V_152 == V_153 ) {
memcpy ( V_107 , & V_5 -> V_19 -> V_121 . V_107 . V_112 , V_51 . V_116 ) ;
} else {
V_107 -> V_154 = V_153 ;
V_107 -> V_155 = ( V_138 V_156 ) V_51 . V_129 ;
F_68 ( & V_5 -> V_19 -> V_121 . V_107 . V_123 ,
(union V_125 * ) & V_107 -> V_157 ) ;
V_107 -> V_158 = F_84 ( V_5 -> V_19 , (struct V_106 * )
& V_5 -> V_19 -> V_121 . V_107 . V_112 ) ;
}
V_107 = (struct V_151 * ) & V_51 . V_113 ;
V_51 . V_117 = sizeof( * V_107 ) ;
if ( V_5 -> V_19 -> V_121 . V_107 . V_113 . V_152 == V_153 ) {
memcpy ( V_107 , & V_5 -> V_19 -> V_121 . V_107 . V_113 , V_51 . V_117 ) ;
} else {
V_107 -> V_154 = V_153 ;
V_107 -> V_155 = ( V_138 V_156 ) V_51 . V_129 ;
F_67 ( & V_5 -> V_19 -> V_121 . V_107 . V_123 ,
(union V_125 * ) & V_107 -> V_157 ) ;
V_107 -> V_158 = F_84 ( V_5 -> V_19 , (struct V_106 * )
& V_5 -> V_19 -> V_121 . V_107 . V_113 ) ;
}
if ( F_43 ( V_86 , & V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
return V_61 ;
}
static T_1 F_85 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_131 V_76 ;
struct V_1 * V_5 ;
void T_2 * V_86 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_86 = ( void T_2 * ) ( unsigned long ) V_76 . V_86 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
switch ( V_76 . V_159 ) {
case V_160 :
V_61 = F_80 ( V_5 , V_86 , V_74 ) ;
break;
case V_161 :
V_61 = F_81 ( V_5 , V_86 , V_74 ) ;
break;
case V_162 :
V_61 = F_83 ( V_5 , V_86 , V_74 ) ;
break;
default:
V_61 = - V_163 ;
break;
}
F_9 ( V_5 ) ;
return V_61 ;
}
static void F_86 ( struct V_53 * V_2 ,
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
V_28 -> V_43 = ( V_2 -> V_121 . V_107 . V_112 . V_152 == V_153 ) ? V_30 -> V_43 : 0 ;
}
static T_1 F_87 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_164 V_76 ;
struct V_29 V_165 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
if ( ! V_76 . V_165 . V_166 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_86 ( V_5 -> V_19 , & V_165 , & V_76 . V_165 ) ;
V_61 = F_88 ( V_5 -> V_19 , & V_165 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_89 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_167 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_5 -> V_66 = V_76 . V_66 > 0 && V_76 . V_66 < V_168 ?
V_76 . V_66 : V_168 ;
V_61 = F_90 ( V_5 -> V_19 , V_5 -> V_66 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_91 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_169 V_76 ;
struct V_29 V_165 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
if ( V_76 . V_165 . V_166 ) {
F_86 ( V_5 -> V_19 , & V_165 , & V_76 . V_165 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_61 = F_92 ( V_5 -> V_19 , & V_165 ) ;
if ( ! V_61 )
V_5 -> V_52 = V_76 . V_52 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_61 = F_92 ( V_5 -> V_19 , NULL ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_93 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_170 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_94 ( V_5 -> V_19 , V_76 . V_32 , V_76 . V_31 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_95 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_171 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_96 ( V_5 -> V_19 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_97 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_172 V_76 ;
struct V_173 V_51 ;
struct V_1 * V_5 ;
struct V_174 V_175 ;
int V_61 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_51 . V_176 = 0 ;
memset ( & V_175 , 0 , sizeof V_175 ) ;
V_175 . V_177 = V_76 . V_177 ;
V_61 = F_98 ( V_5 -> V_19 , & V_175 , & V_51 . V_176 ) ;
if ( V_61 )
goto V_68;
F_99 ( & V_51 , & V_175 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
V_68:
F_9 ( V_5 ) ;
return V_61 ;
}
static int F_100 ( struct V_1 * V_5 , int V_178 ,
void * V_179 , T_3 V_180 )
{
int V_61 = 0 ;
switch ( V_178 ) {
case V_181 :
if ( V_180 != sizeof( V_182 ) ) {
V_61 = - V_8 ;
break;
}
F_101 ( V_5 -> V_19 , * ( ( V_182 * ) V_179 ) ) ;
break;
case V_183 :
if ( V_180 != sizeof( int ) ) {
V_61 = - V_8 ;
break;
}
V_61 = F_102 ( V_5 -> V_19 , * ( ( int * ) V_179 ) ? 1 : 0 ) ;
break;
case V_184 :
if ( V_180 != sizeof( int ) ) {
V_61 = - V_8 ;
break;
}
V_61 = F_103 ( V_5 -> V_19 , * ( ( int * ) V_179 ) ? 1 : 0 ) ;
break;
default:
V_61 = - V_163 ;
}
return V_61 ;
}
static int F_104 ( struct V_1 * V_5 ,
struct V_145 * V_146 , T_3 V_180 )
{
struct V_185 V_186 ;
struct V_44 V_45 ;
int V_61 ;
if ( V_180 % sizeof( * V_146 ) )
return - V_8 ;
for (; V_180 ; V_180 -= sizeof( * V_146 ) , V_146 ++ ) {
if ( V_146 -> V_147 == ( V_148 | V_149 |
V_150 ) )
break;
}
if ( ! V_180 )
return - V_8 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
F_105 ( V_146 -> V_130 , & V_186 ) ;
V_61 = F_106 ( V_5 -> V_19 , & V_186 , 1 ) ;
if ( V_61 )
return V_61 ;
memset ( & V_45 , 0 , sizeof V_45 ) ;
V_45 . V_45 = V_187 ;
return F_36 ( V_5 -> V_19 , & V_45 ) ;
}
static int F_107 ( struct V_1 * V_5 , int V_178 ,
void * V_179 , T_3 V_180 )
{
int V_61 ;
switch ( V_178 ) {
case V_188 :
V_61 = F_104 ( V_5 , V_179 , V_180 ) ;
break;
default:
V_61 = - V_163 ;
}
return V_61 ;
}
static int F_108 ( struct V_1 * V_5 , int V_189 ,
int V_178 , void * V_179 , T_3 V_180 )
{
int V_61 ;
switch ( V_189 ) {
case V_190 :
V_61 = F_100 ( V_5 , V_178 , V_179 , V_180 ) ;
break;
case V_191 :
V_61 = F_107 ( V_5 , V_178 , V_179 , V_180 ) ;
break;
default:
V_61 = - V_163 ;
}
return V_61 ;
}
static T_1 F_109 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_192 V_76 ;
struct V_1 * V_5 ;
void * V_179 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_179 = F_110 ( ( void T_2 * ) ( unsigned long ) V_76 . V_179 ,
V_76 . V_180 ) ;
if ( F_6 ( V_179 ) ) {
V_61 = F_47 ( V_179 ) ;
goto V_68;
}
V_61 = F_108 ( V_5 , V_76 . V_189 , V_76 . V_178 , V_179 ,
V_76 . V_180 ) ;
F_15 ( V_179 ) ;
V_68:
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_111 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_193 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_112 ( V_5 -> V_19 , (enum V_194 ) V_76 . V_45 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_113 ( struct V_3 * V_4 ,
struct V_195 * V_76 , int V_74 )
{
struct V_96 V_51 ;
struct V_1 * V_5 ;
struct V_24 * V_25 ;
struct V_106 * V_107 ;
int V_61 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
V_107 = (struct V_106 * ) & V_76 -> V_107 ;
if ( V_76 -> V_109 || ! V_76 -> V_110 || ( V_76 -> V_110 != F_60 ( V_107 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 -> V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_25 = F_26 ( V_5 ) ;
if ( ! V_25 ) {
V_61 = - V_67 ;
goto V_100;
}
V_25 -> V_52 = V_76 -> V_52 ;
memcpy ( & V_25 -> V_107 , V_107 , V_76 -> V_110 ) ;
V_61 = F_114 ( V_5 -> V_19 , (struct V_106 * ) & V_25 -> V_107 , V_25 ) ;
if ( V_61 )
goto V_101;
V_51 . V_2 = V_25 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 -> V_86 ,
& V_51 , sizeof( V_51 ) ) ) {
V_61 = - V_78 ;
goto V_196;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_196:
F_115 ( V_5 -> V_19 , (struct V_106 * ) & V_25 -> V_107 ) ;
F_51 ( V_25 ) ;
V_101:
F_5 ( & V_9 ) ;
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_15 ( V_25 ) ;
V_100:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_116 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_197 V_76 ;
struct V_195 V_198 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_198 . V_86 = V_76 . V_86 ;
V_198 . V_52 = V_76 . V_52 ;
V_198 . V_2 = V_76 . V_2 ;
V_198 . V_110 = F_60 ( (struct V_106 * ) & V_76 . V_107 ) ;
V_198 . V_109 = 0 ;
memcpy ( & V_198 . V_107 , & V_76 . V_107 , V_198 . V_110 ) ;
return F_113 ( V_4 , & V_198 , V_74 ) ;
}
static T_1 F_117 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_195 V_76 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
return F_113 ( V_4 , & V_76 , V_74 ) ;
}
static T_1 F_118 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_103 V_76 ;
struct V_104 V_51 ;
struct V_24 * V_25 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
F_5 ( & V_9 ) ;
V_25 = F_2 ( & V_26 , V_76 . V_2 ) ;
if ( ! V_25 )
V_25 = F_3 ( - V_7 ) ;
else if ( V_25 -> V_5 -> V_4 != V_4 )
V_25 = F_3 ( - V_8 ) ;
else if ( ! F_119 ( & V_25 -> V_5 -> V_12 ) )
V_25 = F_3 ( - V_199 ) ;
else
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_25 ) ) {
V_61 = F_47 ( V_25 ) ;
goto V_68;
}
F_115 ( V_25 -> V_5 -> V_19 , (struct V_106 * ) & V_25 -> V_107 ) ;
F_5 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_51 ( V_25 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_8 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_25 -> V_5 ) ;
V_51 . V_87 = V_25 -> V_87 ;
F_15 ( V_25 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
V_68:
return V_61 ;
}
static void F_120 ( struct V_3 * V_200 , struct V_3 * V_201 )
{
if ( V_200 < V_201 ) {
F_5 ( & V_200 -> V_9 ) ;
F_121 ( & V_201 -> V_9 , V_202 ) ;
} else {
F_5 ( & V_201 -> V_9 ) ;
F_121 ( & V_200 -> V_9 , V_202 ) ;
}
}
static void F_122 ( struct V_3 * V_200 , struct V_3 * V_201 )
{
if ( V_200 < V_201 ) {
F_8 ( & V_201 -> V_9 ) ;
F_8 ( & V_200 -> V_9 ) ;
} else {
F_8 ( & V_200 -> V_9 ) ;
F_8 ( & V_201 -> V_9 ) ;
}
}
static void F_123 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_16 * V_46 , * V_102 ;
F_50 (uevent, tmp, &ctx->file->event_list, list)
if ( V_46 -> V_5 == V_5 )
F_54 ( & V_46 -> V_22 , & V_4 -> V_70 ) ;
}
static T_1 F_124 ( struct V_3 * V_203 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_204 V_76 ;
struct V_205 V_51 ;
struct V_1 * V_5 ;
struct V_206 V_207 ;
struct V_3 * V_208 ;
int V_61 = 0 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_207 = F_125 ( V_76 . V_206 ) ;
if ( ! V_207 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_207 . V_4 -> V_32 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_61 = F_47 ( V_5 ) ;
goto V_209;
}
V_208 = V_5 -> V_4 ;
if ( V_208 == V_203 ) {
V_51 . V_87 = V_5 -> V_87 ;
goto V_86;
}
F_120 ( V_208 , V_203 ) ;
F_5 ( & V_9 ) ;
F_54 ( & V_5 -> V_22 , & V_203 -> V_23 ) ;
F_123 ( V_5 , V_203 ) ;
V_5 -> V_4 = V_203 ;
V_51 . V_87 = V_5 -> V_87 ;
F_8 ( & V_9 ) ;
F_122 ( V_208 , V_203 ) ;
V_86:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
F_9 ( V_5 ) ;
V_209:
F_126 ( V_207 ) ;
return V_61 ;
}
static T_1 F_127 ( struct V_4 * V_79 , const char T_2 * V_210 ,
T_3 V_211 , T_4 * V_212 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
struct V_213 V_214 ;
T_1 V_61 ;
if ( V_211 < sizeof( V_214 ) )
return - V_8 ;
if ( F_39 ( & V_214 , V_210 , sizeof( V_214 ) ) )
return - V_78 ;
if ( V_214 . V_76 >= F_128 ( V_215 ) )
return - V_8 ;
if ( V_214 . V_216 + sizeof( V_214 ) > V_211 )
return - V_8 ;
if ( ! V_215 [ V_214 . V_76 ] )
return - V_163 ;
V_61 = V_215 [ V_214 . V_76 ] ( V_4 , V_210 + sizeof( V_214 ) , V_214 . V_216 , V_214 . V_68 ) ;
if ( ! V_61 )
V_61 = V_211 ;
return V_61 ;
}
static unsigned int F_129 ( struct V_4 * V_79 , struct V_217 * V_218 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
unsigned int V_219 = 0 ;
V_71 ( V_79 , & V_4 -> V_71 , V_218 ) ;
if ( ! F_40 ( & V_4 -> V_70 ) )
V_219 = V_220 | V_221 ;
return V_219 ;
}
static int F_130 ( struct V_222 * V_222 , struct V_4 * V_79 )
{
struct V_3 * V_4 ;
V_4 = F_131 ( sizeof *V_4 , V_20 ) ;
if ( ! V_4 )
return - V_67 ;
V_4 -> V_58 = F_132 ( L_2 ) ;
if ( ! V_4 -> V_58 ) {
F_15 ( V_4 ) ;
return - V_67 ;
}
F_23 ( & V_4 -> V_70 ) ;
F_23 ( & V_4 -> V_23 ) ;
F_133 ( & V_4 -> V_71 ) ;
F_134 ( & V_4 -> V_9 ) ;
V_79 -> V_32 = V_4 ;
V_4 -> V_79 = V_79 ;
return F_135 ( V_222 , V_79 ) ;
}
static int F_136 ( struct V_222 * V_222 , struct V_4 * V_79 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
struct V_1 * V_5 , * V_102 ;
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
F_137 ( V_4 -> V_58 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
static T_1 F_138 ( struct V_136 * V_223 ,
struct V_224 * V_225 ,
char * V_210 )
{
return sprintf ( V_210 , L_3 , V_226 ) ;
}
static int T_5 F_139 ( void )
{
int V_61 ;
V_61 = F_140 ( & V_227 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_141 ( V_227 . V_228 , & V_229 ) ;
if ( V_61 ) {
F_35 ( V_60 L_4 ) ;
goto V_100;
}
V_230 = F_142 ( & V_231 , L_5 , V_232 ) ;
if ( ! V_230 ) {
F_35 ( V_60 L_6 ) ;
V_61 = - V_67 ;
goto V_101;
}
return 0 ;
V_101:
F_143 ( V_227 . V_228 , & V_229 ) ;
V_100:
F_144 ( & V_227 ) ;
return V_61 ;
}
static void T_6 F_145 ( void )
{
F_146 ( V_230 ) ;
F_143 ( V_227 . V_228 , & V_229 ) ;
F_144 ( & V_227 ) ;
F_147 ( & V_6 ) ;
F_147 ( & V_26 ) ;
}
