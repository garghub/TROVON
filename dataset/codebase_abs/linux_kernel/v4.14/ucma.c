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
static void F_28 ( struct V_40 * V_41 ,
struct V_42 * V_28 ,
struct V_43 * V_30 )
{
if ( V_30 -> V_31 )
memcpy ( V_28 -> V_32 , V_30 -> V_32 ,
V_30 -> V_31 ) ;
V_28 -> V_31 = V_30 -> V_31 ;
F_29 ( V_41 , & V_28 -> V_44 , & V_30 -> V_44 ) ;
V_28 -> V_39 = V_30 -> V_39 ;
V_28 -> V_45 = V_30 -> V_45 ;
}
static void F_30 ( struct V_1 * V_5 ,
struct V_46 * V_47 ,
struct V_16 * V_48 )
{
V_48 -> V_5 = V_5 ;
switch ( V_47 -> V_47 ) {
case V_49 :
case V_50 :
V_48 -> V_25 = (struct V_24 * )
V_47 -> V_51 . V_52 . V_32 ;
V_48 -> V_53 . V_54 = V_48 -> V_25 -> V_54 ;
V_48 -> V_53 . V_2 = V_48 -> V_25 -> V_2 ;
break;
default:
V_48 -> V_53 . V_54 = V_5 -> V_54 ;
V_48 -> V_53 . V_2 = V_5 -> V_2 ;
break;
}
}
static void F_31 ( struct V_55 * V_19 )
{
struct V_1 * V_5 = V_19 -> V_56 ;
struct V_16 * V_57 ;
int V_58 = 0 ;
if ( V_5 -> V_59 )
return;
if ( V_5 -> V_19 == V_19 ) {
F_5 ( & V_9 ) ;
V_5 -> V_10 = 1 ;
F_8 ( & V_9 ) ;
F_32 ( V_5 -> V_4 -> V_60 , & V_5 -> V_18 ) ;
return;
}
F_33 (con_req_eve, &ctx->file->event_list, list) {
if ( V_57 -> V_19 == V_19 &&
V_57 -> V_53 . V_47 == V_61 ) {
F_34 ( & V_57 -> V_22 ) ;
F_20 ( & V_57 -> V_18 , F_12 ) ;
F_32 ( V_5 -> V_4 -> V_60 , & V_57 -> V_18 ) ;
V_58 = 1 ;
break;
}
}
if ( ! V_58 )
F_35 ( L_1 ) ;
}
static int F_36 ( struct V_55 * V_19 ,
struct V_46 * V_47 )
{
struct V_16 * V_48 ;
struct V_1 * V_5 = V_19 -> V_56 ;
int V_62 = 0 ;
V_48 = F_19 ( sizeof( * V_48 ) , V_20 ) ;
if ( ! V_48 )
return V_47 -> V_47 == V_61 ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_48 -> V_19 = V_19 ;
F_30 ( V_5 , V_47 , V_48 ) ;
V_48 -> V_53 . V_47 = V_47 -> V_47 ;
V_48 -> V_53 . V_63 = V_47 -> V_63 ;
if ( V_19 -> V_64 == V_65 )
F_28 ( V_19 -> V_41 , & V_48 -> V_53 . V_51 . V_52 ,
& V_47 -> V_51 . V_52 ) ;
else
F_27 ( & V_48 -> V_53 . V_51 . V_66 ,
& V_47 -> V_51 . V_66 ) ;
if ( V_47 -> V_47 == V_61 ) {
if ( ! V_5 -> V_67 ) {
V_62 = - V_68 ;
F_15 ( V_48 ) ;
goto V_69;
}
V_5 -> V_67 -- ;
} else if ( ! V_5 -> V_54 || V_5 -> V_19 != V_19 ) {
if ( V_47 -> V_47 == V_70 )
F_31 ( V_19 ) ;
F_15 ( V_48 ) ;
goto V_69;
}
F_25 ( & V_48 -> V_22 , & V_5 -> V_4 -> V_71 ) ;
F_37 ( & V_5 -> V_4 -> V_72 ) ;
if ( V_47 -> V_47 == V_70 )
F_31 ( V_19 ) ;
V_69:
F_8 ( & V_5 -> V_4 -> V_9 ) ;
return V_62 ;
}
static T_1 F_38 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_1 * V_5 ;
struct V_76 V_77 ;
struct V_16 * V_48 ;
int V_62 = 0 ;
if ( V_75 < sizeof V_48 -> V_53 )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_40 ( & V_4 -> V_71 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_80 -> V_81 & V_82 )
return - V_83 ;
if ( F_41 ( V_4 -> V_72 ,
! F_40 ( & V_4 -> V_71 ) ) )
return - V_84 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_48 = F_42 ( V_4 -> V_71 . V_85 , struct V_16 , V_22 ) ;
if ( V_48 -> V_53 . V_47 == V_61 ) {
V_5 = F_18 ( V_4 ) ;
if ( ! V_5 ) {
V_62 = - V_68 ;
goto V_86;
}
V_48 -> V_5 -> V_67 ++ ;
V_5 -> V_19 = V_48 -> V_19 ;
V_5 -> V_19 -> V_56 = V_5 ;
V_48 -> V_53 . V_2 = V_5 -> V_2 ;
}
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_48 -> V_53 , sizeof V_48 -> V_53 ) ) {
V_62 = - V_79 ;
goto V_86;
}
F_34 ( & V_48 -> V_22 ) ;
V_48 -> V_5 -> V_88 ++ ;
if ( V_48 -> V_25 )
V_48 -> V_25 -> V_88 ++ ;
F_15 ( V_48 ) ;
V_86:
F_8 ( & V_4 -> V_9 ) ;
return V_62 ;
}
static int F_44 ( struct V_89 * V_77 , enum V_90 * V_64 )
{
switch ( V_77 -> V_91 ) {
case V_92 :
* V_64 = V_93 ;
return 0 ;
case V_94 :
case V_95 :
* V_64 = V_65 ;
return 0 ;
case V_96 :
* V_64 = V_77 -> V_64 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_45 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_89 V_77 ;
struct V_97 V_53 ;
struct V_1 * V_5 ;
enum V_90 V_64 ;
int V_62 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_62 = F_44 ( & V_77 , & V_64 ) ;
if ( V_62 )
return V_62 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_18 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_68 ;
V_5 -> V_54 = V_77 . V_54 ;
V_5 -> V_19 = F_46 ( V_98 -> V_99 -> V_100 ,
F_36 , V_5 , V_77 . V_91 , V_64 ) ;
if ( F_6 ( V_5 -> V_19 ) ) {
V_62 = F_47 ( V_5 -> V_19 ) ;
goto V_101;
}
V_53 . V_2 = V_5 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) ) {
V_62 = - V_79 ;
goto V_102;
}
return 0 ;
V_102:
F_14 ( V_5 -> V_19 ) ;
V_101:
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_15 ( V_5 ) ;
return V_62 ;
}
static void F_49 ( struct V_1 * V_5 )
{
struct V_24 * V_25 , * V_103 ;
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
struct V_16 * V_48 , * V_103 ;
F_50 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_48 -> V_25 != V_25 )
continue;
F_34 ( & V_48 -> V_22 ) ;
F_15 ( V_48 ) ;
}
}
static int F_52 ( struct V_1 * V_5 )
{
int V_88 ;
struct V_16 * V_48 , * V_103 ;
F_53 ( V_22 ) ;
F_49 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
F_50 (uevent, tmp, &ctx->file->event_list, list) {
if ( V_48 -> V_5 == V_5 )
F_54 ( & V_48 -> V_22 , & V_22 ) ;
}
F_34 ( & V_5 -> V_22 ) ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_50 (uevent, tmp, &list, list) {
F_34 ( & V_48 -> V_22 ) ;
if ( V_48 -> V_53 . V_47 == V_61 )
F_14 ( V_48 -> V_19 ) ;
F_15 ( V_48 ) ;
}
V_88 = V_5 -> V_88 ;
F_15 ( V_5 ) ;
return V_88 ;
}
static T_1 F_55 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_104 V_77 ;
struct V_105 V_53 ;
struct V_1 * V_5 ;
int V_62 = 0 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_77 . V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) )
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_5 -> V_59 = 1 ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_56 ( V_5 -> V_4 -> V_60 ) ;
F_5 ( & V_9 ) ;
if ( ! V_5 -> V_10 ) {
F_8 ( & V_9 ) ;
F_9 ( V_5 ) ;
F_17 ( & V_5 -> V_13 ) ;
F_14 ( V_5 -> V_19 ) ;
} else {
F_8 ( & V_9 ) ;
}
V_53 . V_88 = F_52 ( V_5 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
return V_62 ;
}
static T_1 F_57 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_106 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_58 ( V_5 -> V_19 , (struct V_107 * ) & V_77 . V_108 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_59 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_109 V_77 ;
struct V_107 * V_108 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_108 = (struct V_107 * ) & V_77 . V_108 ;
if ( V_77 . V_110 || ! V_77 . V_111 || ( V_77 . V_111 != F_60 ( V_108 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_58 ( V_5 -> V_19 , V_108 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_61 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_112 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_62 ( V_5 -> V_19 , (struct V_107 * ) & V_77 . V_113 ,
(struct V_107 * ) & V_77 . V_114 ,
V_77 . V_115 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_63 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_116 V_77 ;
struct V_107 * V_30 , * V_28 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_30 = (struct V_107 * ) & V_77 . V_113 ;
V_28 = (struct V_107 * ) & V_77 . V_114 ;
if ( V_77 . V_110 || ( V_77 . V_117 && ( V_77 . V_117 != F_60 ( V_30 ) ) ) ||
! V_77 . V_118 || ( V_77 . V_118 != F_60 ( V_28 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_62 ( V_5 -> V_19 , V_30 , V_28 , V_77 . V_115 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_64 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_119 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_65 ( V_5 -> V_19 , V_77 . V_115 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static void F_66 ( struct V_120 * V_53 ,
struct V_121 * V_122 )
{
struct V_123 * V_124 ;
V_53 -> V_125 = V_122 -> V_125 ;
switch ( V_122 -> V_125 ) {
case 0 :
V_124 = & V_122 -> V_108 . V_124 ;
F_67 ( V_124 ,
(union V_126 * ) & V_53 -> V_127 [ 0 ] . V_128 ) ;
F_68 ( V_124 ,
(union V_126 * ) & V_53 -> V_127 [ 0 ] . V_129 ) ;
V_53 -> V_127 [ 0 ] . V_130 = F_69 ( F_70 ( V_124 ) ) ;
break;
case 2 :
F_71 ( & V_53 -> V_127 [ 1 ] ,
& V_122 -> V_131 [ 1 ] ) ;
case 1 :
F_71 ( & V_53 -> V_127 [ 0 ] ,
& V_122 -> V_131 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_120 * V_53 ,
struct V_121 * V_122 )
{
V_53 -> V_125 = V_122 -> V_125 ;
switch ( V_122 -> V_125 ) {
case 0 :
F_73 ( (struct V_107 * ) & V_122 -> V_108 . V_114 ,
(union V_126 * ) & V_53 -> V_127 [ 0 ] . V_128 ) ;
F_73 ( (struct V_107 * ) & V_122 -> V_108 . V_113 ,
(union V_126 * ) & V_53 -> V_127 [ 0 ] . V_129 ) ;
V_53 -> V_127 [ 0 ] . V_130 = F_69 ( 0xffff ) ;
break;
case 2 :
F_71 ( & V_53 -> V_127 [ 1 ] ,
& V_122 -> V_131 [ 1 ] ) ;
case 1 :
F_71 ( & V_53 -> V_127 [ 0 ] ,
& V_122 -> V_131 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_74 ( struct V_120 * V_53 ,
struct V_121 * V_122 )
{
struct V_123 * V_124 ;
V_124 = & V_122 -> V_108 . V_124 ;
F_67 ( V_124 , (union V_126 * ) & V_53 -> V_127 [ 0 ] . V_128 ) ;
F_68 ( V_124 , (union V_126 * ) & V_53 -> V_127 [ 0 ] . V_129 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_132 V_77 ;
struct V_120 V_53 ;
struct V_1 * V_5 ;
struct V_107 * V_108 ;
int V_62 = 0 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
memset ( & V_53 , 0 , sizeof V_53 ) ;
V_108 = (struct V_107 * ) & V_5 -> V_19 -> V_122 . V_108 . V_113 ;
memcpy ( & V_53 . V_113 , V_108 , V_108 -> V_133 == V_134 ?
sizeof( struct V_135 ) :
sizeof( struct V_136 ) ) ;
V_108 = (struct V_107 * ) & V_5 -> V_19 -> V_122 . V_108 . V_114 ;
memcpy ( & V_53 . V_114 , V_108 , V_108 -> V_133 == V_134 ?
sizeof( struct V_135 ) :
sizeof( struct V_136 ) ) ;
if ( ! V_5 -> V_19 -> V_41 )
goto V_69;
V_53 . V_137 = ( V_138 V_139 ) V_5 -> V_19 -> V_41 -> V_137 ;
V_53 . V_140 = V_5 -> V_19 -> V_140 ;
if ( F_76 ( V_5 -> V_19 -> V_41 , V_5 -> V_19 -> V_140 ) )
F_66 ( & V_53 , & V_5 -> V_19 -> V_122 ) ;
else if ( F_77 ( V_5 -> V_19 -> V_41 , V_5 -> V_19 -> V_140 ) )
F_72 ( & V_53 , & V_5 -> V_19 -> V_122 ) ;
else if ( F_78 ( V_5 -> V_19 -> V_41 , V_5 -> V_19 -> V_140 ) )
F_74 ( & V_53 , & V_5 -> V_19 -> V_122 ) ;
V_69:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
F_9 ( V_5 ) ;
return V_62 ;
}
static void F_79 ( struct V_55 * V_19 ,
struct V_141 * V_53 )
{
if ( ! V_19 -> V_41 )
return;
V_53 -> V_137 = ( V_138 V_139 ) V_19 -> V_41 -> V_137 ;
V_53 -> V_140 = V_19 -> V_140 ;
V_53 -> V_130 = ( V_138 V_142 ) F_69 (
F_70 ( & V_19 -> V_122 . V_108 . V_124 ) ) ;
}
static T_1 F_80 ( struct V_1 * V_5 ,
void T_2 * V_87 , int V_75 )
{
struct V_141 V_53 ;
struct V_107 * V_108 ;
int V_62 = 0 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
memset ( & V_53 , 0 , sizeof V_53 ) ;
V_108 = (struct V_107 * ) & V_5 -> V_19 -> V_122 . V_108 . V_113 ;
V_53 . V_117 = F_60 ( V_108 ) ;
memcpy ( & V_53 . V_113 , V_108 , V_53 . V_117 ) ;
V_108 = (struct V_107 * ) & V_5 -> V_19 -> V_122 . V_108 . V_114 ;
V_53 . V_118 = F_60 ( V_108 ) ;
memcpy ( & V_53 . V_114 , V_108 , V_53 . V_118 ) ;
F_79 ( V_5 -> V_19 , & V_53 ) ;
if ( F_43 ( V_87 , & V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
return V_62 ;
}
static T_1 F_81 ( struct V_1 * V_5 ,
void T_2 * V_87 , int V_75 )
{
struct V_143 * V_53 ;
int V_144 , V_62 = 0 ;
if ( V_75 < sizeof( * V_53 ) )
return - V_78 ;
V_53 = F_19 ( V_75 , V_20 ) ;
if ( ! V_53 )
return - V_68 ;
V_53 -> V_125 = V_5 -> V_19 -> V_122 . V_125 ;
for ( V_144 = 0 , V_75 -= sizeof( * V_53 ) ;
V_144 < V_53 -> V_125 && V_75 > sizeof( struct V_145 ) ;
V_144 ++ , V_75 -= sizeof( struct V_145 ) ) {
struct V_146 * V_147 = & V_5 -> V_19 -> V_122 . V_131 [ V_144 ] ;
V_53 -> V_148 [ V_144 ] . V_149 = V_150 | V_151 |
V_152 ;
if ( V_147 -> V_153 == V_154 ) {
F_82 ( V_147 , & V_53 -> V_148 [ V_144 ] . V_131 ) ;
} else {
struct V_146 V_155 ;
F_83 ( & V_155 , V_147 ) ;
F_82 ( & V_155 , & V_53 -> V_148 [ V_144 ] . V_131 ) ;
}
}
if ( F_43 ( V_87 , V_53 ,
sizeof( * V_53 ) + ( V_144 * sizeof( struct V_145 ) ) ) )
V_62 = - V_79 ;
F_15 ( V_53 ) ;
return V_62 ;
}
static T_1 F_84 ( struct V_1 * V_5 ,
void T_2 * V_87 , int V_75 )
{
struct V_141 V_53 ;
struct V_156 * V_108 ;
int V_62 = 0 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
memset ( & V_53 , 0 , sizeof V_53 ) ;
F_79 ( V_5 -> V_19 , & V_53 ) ;
V_108 = (struct V_156 * ) & V_53 . V_113 ;
V_53 . V_117 = sizeof( * V_108 ) ;
if ( V_5 -> V_19 -> V_122 . V_108 . V_113 . V_157 == V_158 ) {
memcpy ( V_108 , & V_5 -> V_19 -> V_122 . V_108 . V_113 , V_53 . V_117 ) ;
} else {
V_108 -> V_159 = V_158 ;
V_108 -> V_160 = ( V_138 V_161 ) V_53 . V_130 ;
F_68 ( & V_5 -> V_19 -> V_122 . V_108 . V_124 ,
(union V_126 * ) & V_108 -> V_162 ) ;
V_108 -> V_163 = F_85 ( V_5 -> V_19 , (struct V_107 * )
& V_5 -> V_19 -> V_122 . V_108 . V_113 ) ;
}
V_108 = (struct V_156 * ) & V_53 . V_114 ;
V_53 . V_118 = sizeof( * V_108 ) ;
if ( V_5 -> V_19 -> V_122 . V_108 . V_114 . V_157 == V_158 ) {
memcpy ( V_108 , & V_5 -> V_19 -> V_122 . V_108 . V_114 , V_53 . V_118 ) ;
} else {
V_108 -> V_159 = V_158 ;
V_108 -> V_160 = ( V_138 V_161 ) V_53 . V_130 ;
F_67 ( & V_5 -> V_19 -> V_122 . V_108 . V_124 ,
(union V_126 * ) & V_108 -> V_162 ) ;
V_108 -> V_163 = F_85 ( V_5 -> V_19 , (struct V_107 * )
& V_5 -> V_19 -> V_122 . V_108 . V_114 ) ;
}
if ( F_43 ( V_87 , & V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
return V_62 ;
}
static T_1 F_86 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_132 V_77 ;
struct V_1 * V_5 ;
void T_2 * V_87 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_87 = ( void T_2 * ) ( unsigned long ) V_77 . V_87 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
switch ( V_77 . V_164 ) {
case V_165 :
V_62 = F_80 ( V_5 , V_87 , V_75 ) ;
break;
case V_166 :
V_62 = F_81 ( V_5 , V_87 , V_75 ) ;
break;
case V_167 :
V_62 = F_84 ( V_5 , V_87 , V_75 ) ;
break;
default:
V_62 = - V_168 ;
break;
}
F_9 ( V_5 ) ;
return V_62 ;
}
static void F_87 ( struct V_55 * V_2 ,
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
V_28 -> V_45 = ( V_2 -> V_122 . V_108 . V_113 . V_157 == V_158 ) ? V_30 -> V_45 : 0 ;
}
static T_1 F_88 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_169 V_77 ;
struct V_29 V_170 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
if ( ! V_77 . V_170 . V_171 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_87 ( V_5 -> V_19 , & V_170 , & V_77 . V_170 ) ;
V_62 = F_89 ( V_5 -> V_19 , & V_170 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_90 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_172 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_5 -> V_67 = V_77 . V_67 > 0 && V_77 . V_67 < V_173 ?
V_77 . V_67 : V_173 ;
V_62 = F_91 ( V_5 -> V_19 , V_5 -> V_67 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_92 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_174 V_77 ;
struct V_29 V_170 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
if ( V_77 . V_170 . V_171 ) {
F_87 ( V_5 -> V_19 , & V_170 , & V_77 . V_170 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_62 = F_93 ( V_5 -> V_19 , & V_170 ) ;
if ( ! V_62 )
V_5 -> V_54 = V_77 . V_54 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_62 = F_93 ( V_5 -> V_19 , NULL ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_94 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_175 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_95 ( V_5 -> V_19 , V_77 . V_32 , V_77 . V_31 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_96 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_176 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_97 ( V_5 -> V_19 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_98 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_177 V_77 ;
struct V_178 V_53 ;
struct V_1 * V_5 ;
struct V_179 V_180 ;
int V_62 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_53 . V_181 = 0 ;
memset ( & V_180 , 0 , sizeof V_180 ) ;
V_180 . V_182 = V_77 . V_182 ;
V_62 = F_99 ( V_5 -> V_19 , & V_180 , & V_53 . V_181 ) ;
if ( V_62 )
goto V_69;
F_100 ( V_5 -> V_19 -> V_41 , & V_53 , & V_180 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
V_69:
F_9 ( V_5 ) ;
return V_62 ;
}
static int F_101 ( struct V_1 * V_5 , int V_183 ,
void * V_184 , T_3 V_185 )
{
int V_62 = 0 ;
switch ( V_183 ) {
case V_186 :
if ( V_185 != sizeof( V_187 ) ) {
V_62 = - V_8 ;
break;
}
F_102 ( V_5 -> V_19 , * ( ( V_187 * ) V_184 ) ) ;
break;
case V_188 :
if ( V_185 != sizeof( int ) ) {
V_62 = - V_8 ;
break;
}
V_62 = F_103 ( V_5 -> V_19 , * ( ( int * ) V_184 ) ? 1 : 0 ) ;
break;
case V_189 :
if ( V_185 != sizeof( int ) ) {
V_62 = - V_8 ;
break;
}
V_62 = F_104 ( V_5 -> V_19 , * ( ( int * ) V_184 ) ? 1 : 0 ) ;
break;
default:
V_62 = - V_168 ;
}
return V_62 ;
}
static int F_105 ( struct V_1 * V_5 ,
struct V_145 * V_148 , T_3 V_185 )
{
struct V_146 V_190 ;
struct V_46 V_47 ;
int V_62 ;
if ( V_185 % sizeof( * V_148 ) )
return - V_8 ;
for (; V_185 ; V_185 -= sizeof( * V_148 ) , V_148 ++ ) {
if ( V_148 -> V_149 == ( V_150 | V_151 |
V_152 ) )
break;
}
if ( ! V_185 )
return - V_8 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_153 = V_154 ;
F_106 ( V_148 -> V_131 , & V_190 ) ;
if ( F_107 ( V_5 -> V_19 -> V_41 , V_5 -> V_19 -> V_140 ) ) {
struct V_146 V_191 ;
F_108 ( & V_191 , & V_190 ) ;
V_62 = F_109 ( V_5 -> V_19 , & V_191 , 1 ) ;
} else {
V_62 = F_109 ( V_5 -> V_19 , & V_190 , 1 ) ;
}
if ( V_62 )
return V_62 ;
memset ( & V_47 , 0 , sizeof V_47 ) ;
V_47 . V_47 = V_192 ;
return F_36 ( V_5 -> V_19 , & V_47 ) ;
}
static int F_110 ( struct V_1 * V_5 , int V_183 ,
void * V_184 , T_3 V_185 )
{
int V_62 ;
switch ( V_183 ) {
case V_193 :
V_62 = F_105 ( V_5 , V_184 , V_185 ) ;
break;
default:
V_62 = - V_168 ;
}
return V_62 ;
}
static int F_111 ( struct V_1 * V_5 , int V_194 ,
int V_183 , void * V_184 , T_3 V_185 )
{
int V_62 ;
switch ( V_194 ) {
case V_195 :
V_62 = F_101 ( V_5 , V_183 , V_184 , V_185 ) ;
break;
case V_196 :
V_62 = F_110 ( V_5 , V_183 , V_184 , V_185 ) ;
break;
default:
V_62 = - V_168 ;
}
return V_62 ;
}
static T_1 F_112 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_197 V_77 ;
struct V_1 * V_5 ;
void * V_184 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_184 = F_113 ( ( void T_2 * ) ( unsigned long ) V_77 . V_184 ,
V_77 . V_185 ) ;
if ( F_6 ( V_184 ) ) {
V_62 = F_47 ( V_184 ) ;
goto V_69;
}
V_62 = F_111 ( V_5 , V_77 . V_194 , V_77 . V_183 , V_184 ,
V_77 . V_185 ) ;
F_15 ( V_184 ) ;
V_69:
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_114 ( struct V_3 * V_4 , const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_198 V_77 ;
struct V_1 * V_5 ;
int V_62 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_5 = F_4 ( V_4 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_62 = F_115 ( V_5 -> V_19 , (enum V_199 ) V_77 . V_47 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_116 ( struct V_3 * V_4 ,
struct V_200 * V_77 , int V_75 )
{
struct V_97 V_53 ;
struct V_1 * V_5 ;
struct V_24 * V_25 ;
struct V_107 * V_108 ;
int V_62 ;
V_187 V_201 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
V_108 = (struct V_107 * ) & V_77 -> V_108 ;
if ( ! V_77 -> V_111 || ( V_77 -> V_111 != F_60 ( V_108 ) ) )
return - V_8 ;
if ( V_77 -> V_202 == V_203 )
V_201 = F_117 ( V_204 ) ;
else if ( V_77 -> V_202 == V_205 )
V_201 = F_117 ( V_206 ) ;
else
return - V_8 ;
V_5 = F_4 ( V_4 , V_77 -> V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_25 = F_26 ( V_5 ) ;
if ( ! V_25 ) {
V_62 = - V_68 ;
goto V_101;
}
V_25 -> V_201 = V_201 ;
V_25 -> V_54 = V_77 -> V_54 ;
memcpy ( & V_25 -> V_108 , V_108 , V_77 -> V_111 ) ;
V_62 = F_118 ( V_5 -> V_19 , (struct V_107 * ) & V_25 -> V_108 ,
V_201 , V_25 ) ;
if ( V_62 )
goto V_102;
V_53 . V_2 = V_25 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 -> V_87 ,
& V_53 , sizeof( V_53 ) ) ) {
V_62 = - V_79 ;
goto V_207;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_207:
F_119 ( V_5 -> V_19 , (struct V_107 * ) & V_25 -> V_108 ) ;
F_51 ( V_25 ) ;
V_102:
F_5 ( & V_9 ) ;
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_15 ( V_25 ) ;
V_101:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_62 ;
}
static T_1 F_120 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_208 V_77 ;
struct V_200 V_209 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_209 . V_87 = V_77 . V_87 ;
V_209 . V_54 = V_77 . V_54 ;
V_209 . V_2 = V_77 . V_2 ;
V_209 . V_111 = F_60 ( (struct V_107 * ) & V_77 . V_108 ) ;
V_209 . V_202 = V_203 ;
memcpy ( & V_209 . V_108 , & V_77 . V_108 , V_209 . V_111 ) ;
return F_116 ( V_4 , & V_209 , V_75 ) ;
}
static T_1 F_121 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_200 V_77 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
return F_116 ( V_4 , & V_77 , V_75 ) ;
}
static T_1 F_122 ( struct V_3 * V_4 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_104 V_77 ;
struct V_105 V_53 ;
struct V_24 * V_25 ;
int V_62 = 0 ;
if ( V_75 < sizeof( V_53 ) )
return - V_78 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
F_5 ( & V_9 ) ;
V_25 = F_2 ( & V_26 , V_77 . V_2 ) ;
if ( ! V_25 )
V_25 = F_3 ( - V_7 ) ;
else if ( V_25 -> V_5 -> V_4 != V_4 )
V_25 = F_3 ( - V_8 ) ;
else if ( ! F_123 ( & V_25 -> V_5 -> V_12 ) )
V_25 = F_3 ( - V_210 ) ;
else
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_25 ) ) {
V_62 = F_47 ( V_25 ) ;
goto V_69;
}
F_119 ( V_25 -> V_5 -> V_19 , (struct V_107 * ) & V_25 -> V_108 ) ;
F_5 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_51 ( V_25 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_8 ( & V_25 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_25 -> V_5 ) ;
V_53 . V_88 = V_25 -> V_88 ;
F_15 ( V_25 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
V_69:
return V_62 ;
}
static void F_124 ( struct V_3 * V_211 , struct V_3 * V_212 )
{
if ( V_211 < V_212 ) {
F_5 ( & V_211 -> V_9 ) ;
F_125 ( & V_212 -> V_9 , V_213 ) ;
} else {
F_5 ( & V_212 -> V_9 ) ;
F_125 ( & V_211 -> V_9 , V_213 ) ;
}
}
static void F_126 ( struct V_3 * V_211 , struct V_3 * V_212 )
{
if ( V_211 < V_212 ) {
F_8 ( & V_212 -> V_9 ) ;
F_8 ( & V_211 -> V_9 ) ;
} else {
F_8 ( & V_211 -> V_9 ) ;
F_8 ( & V_212 -> V_9 ) ;
}
}
static void F_127 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_16 * V_48 , * V_103 ;
F_50 (uevent, tmp, &ctx->file->event_list, list)
if ( V_48 -> V_5 == V_5 )
F_54 ( & V_48 -> V_22 , & V_4 -> V_71 ) ;
}
static T_1 F_128 ( struct V_3 * V_214 ,
const char T_2 * V_73 ,
int V_74 , int V_75 )
{
struct V_215 V_77 ;
struct V_216 V_53 ;
struct V_1 * V_5 ;
struct V_217 V_218 ;
struct V_3 * V_219 ;
int V_62 = 0 ;
if ( F_39 ( & V_77 , V_73 , sizeof( V_77 ) ) )
return - V_79 ;
V_218 = F_129 ( V_77 . V_217 ) ;
if ( ! V_218 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_218 . V_4 -> V_32 , V_77 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_62 = F_47 ( V_5 ) ;
goto V_220;
}
V_219 = V_5 -> V_4 ;
if ( V_219 == V_214 ) {
V_53 . V_88 = V_5 -> V_88 ;
goto V_87;
}
F_124 ( V_219 , V_214 ) ;
F_5 ( & V_9 ) ;
F_54 ( & V_5 -> V_22 , & V_214 -> V_23 ) ;
F_127 ( V_5 , V_214 ) ;
V_5 -> V_4 = V_214 ;
V_53 . V_88 = V_5 -> V_88 ;
F_8 ( & V_9 ) ;
F_126 ( V_219 , V_214 ) ;
V_87:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_77 . V_87 ,
& V_53 , sizeof( V_53 ) ) )
V_62 = - V_79 ;
F_9 ( V_5 ) ;
V_220:
F_130 ( V_218 ) ;
return V_62 ;
}
static T_1 F_131 ( struct V_4 * V_80 , const char T_2 * V_221 ,
T_3 V_222 , T_4 * V_223 )
{
struct V_3 * V_4 = V_80 -> V_32 ;
struct V_224 V_225 ;
T_1 V_62 ;
if ( ! F_132 ( V_80 ) ) {
F_133 ( L_2 ,
F_134 ( V_98 ) , V_98 -> V_226 ) ;
return - V_227 ;
}
if ( V_222 < sizeof( V_225 ) )
return - V_8 ;
if ( F_39 ( & V_225 , V_221 , sizeof( V_225 ) ) )
return - V_79 ;
if ( V_225 . V_77 >= F_135 ( V_228 ) )
return - V_8 ;
if ( V_225 . V_229 + sizeof( V_225 ) > V_222 )
return - V_8 ;
if ( ! V_228 [ V_225 . V_77 ] )
return - V_168 ;
V_62 = V_228 [ V_225 . V_77 ] ( V_4 , V_221 + sizeof( V_225 ) , V_225 . V_229 , V_225 . V_69 ) ;
if ( ! V_62 )
V_62 = V_222 ;
return V_62 ;
}
static unsigned int F_136 ( struct V_4 * V_80 , struct V_230 * V_231 )
{
struct V_3 * V_4 = V_80 -> V_32 ;
unsigned int V_232 = 0 ;
V_72 ( V_80 , & V_4 -> V_72 , V_231 ) ;
if ( ! F_40 ( & V_4 -> V_71 ) )
V_232 = V_233 | V_234 ;
return V_232 ;
}
static int F_137 ( struct V_235 * V_235 , struct V_4 * V_80 )
{
struct V_3 * V_4 ;
V_4 = F_138 ( sizeof *V_4 , V_20 ) ;
if ( ! V_4 )
return - V_68 ;
V_4 -> V_60 = F_139 ( L_3 ,
V_236 ) ;
if ( ! V_4 -> V_60 ) {
F_15 ( V_4 ) ;
return - V_68 ;
}
F_23 ( & V_4 -> V_71 ) ;
F_23 ( & V_4 -> V_23 ) ;
F_140 ( & V_4 -> V_72 ) ;
F_141 ( & V_4 -> V_9 ) ;
V_80 -> V_32 = V_4 ;
V_4 -> V_80 = V_80 ;
return F_142 ( V_235 , V_80 ) ;
}
static int F_143 ( struct V_235 * V_235 , struct V_4 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_32 ;
struct V_1 * V_5 , * V_103 ;
F_5 ( & V_4 -> V_9 ) ;
F_50 (ctx, tmp, &file->ctx_list, list) {
V_5 -> V_59 = 1 ;
F_8 ( & V_4 -> V_9 ) ;
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_56 ( V_4 -> V_60 ) ;
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
F_144 ( V_4 -> V_60 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
static T_1 F_145 ( struct V_41 * V_237 ,
struct V_238 * V_239 ,
char * V_221 )
{
return sprintf ( V_221 , L_4 , V_240 ) ;
}
static int T_5 F_146 ( void )
{
int V_62 ;
V_62 = F_147 ( & V_241 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_148 ( V_241 . V_242 , & V_243 ) ;
if ( V_62 ) {
F_35 ( L_5 ) ;
goto V_101;
}
V_244 = F_149 ( & V_245 , L_6 , V_246 ) ;
if ( ! V_244 ) {
F_35 ( L_7 ) ;
V_62 = - V_68 ;
goto V_102;
}
return 0 ;
V_102:
F_150 ( V_241 . V_242 , & V_243 ) ;
V_101:
F_151 ( & V_241 ) ;
return V_62 ;
}
static void T_6 F_152 ( void )
{
F_153 ( V_244 ) ;
F_150 ( V_241 . V_242 , & V_243 ) ;
F_151 ( & V_241 ) ;
F_154 ( & V_6 ) ;
F_154 ( & V_26 ) ;
}
