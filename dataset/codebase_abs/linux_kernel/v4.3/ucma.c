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
V_5 -> V_19 = F_46 ( F_36 , V_5 , V_76 . V_90 , V_63 ) ;
if ( F_6 ( V_5 -> V_19 ) ) {
V_61 = F_47 ( V_5 -> V_19 ) ;
goto V_97;
}
V_51 . V_2 = V_5 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) ) {
V_61 = - V_78 ;
goto V_98;
}
return 0 ;
V_98:
F_14 ( V_5 -> V_19 ) ;
V_97:
F_5 ( & V_9 ) ;
F_48 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_15 ( V_5 ) ;
return V_61 ;
}
static void F_49 ( struct V_1 * V_5 )
{
struct V_24 * V_25 , * V_99 ;
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
struct V_16 * V_46 , * V_99 ;
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
struct V_16 * V_46 , * V_99 ;
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
struct V_100 V_76 ;
struct V_101 V_51 ;
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
struct V_102 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_58 ( V_5 -> V_19 , (struct V_103 * ) & V_76 . V_104 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_59 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_105 V_76 ;
struct V_103 * V_104 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_104 = (struct V_103 * ) & V_76 . V_104 ;
if ( V_76 . V_106 || ! V_76 . V_107 || ( V_76 . V_107 != F_60 ( V_104 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_58 ( V_5 -> V_19 , V_104 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_61 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_108 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_62 ( V_5 -> V_19 , (struct V_103 * ) & V_76 . V_109 ,
(struct V_103 * ) & V_76 . V_110 ,
V_76 . V_111 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_63 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_112 V_76 ;
struct V_103 * V_30 , * V_28 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_30 = (struct V_103 * ) & V_76 . V_109 ;
V_28 = (struct V_103 * ) & V_76 . V_110 ;
if ( V_76 . V_106 || ( V_76 . V_113 && ( V_76 . V_113 != F_60 ( V_30 ) ) ) ||
! V_76 . V_114 || ( V_76 . V_114 != F_60 ( V_28 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_62 ( V_5 -> V_19 , V_30 , V_28 , V_76 . V_111 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_64 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_115 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_65 ( V_5 -> V_19 , V_76 . V_111 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static void F_66 ( struct V_116 * V_51 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 ;
V_51 -> V_121 = V_118 -> V_121 ;
switch ( V_118 -> V_121 ) {
case 0 :
V_120 = & V_118 -> V_104 . V_120 ;
F_67 ( V_120 ,
(union V_122 * ) & V_51 -> V_123 [ 0 ] . V_124 ) ;
F_68 ( V_120 ,
(union V_122 * ) & V_51 -> V_123 [ 0 ] . V_125 ) ;
V_51 -> V_123 [ 0 ] . V_126 = F_69 ( F_70 ( V_120 ) ) ;
break;
case 2 :
F_71 ( & V_51 -> V_123 [ 1 ] ,
& V_118 -> V_127 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_123 [ 0 ] ,
& V_118 -> V_127 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_116 * V_51 ,
struct V_117 * V_118 )
{
V_51 -> V_121 = V_118 -> V_121 ;
switch ( V_118 -> V_121 ) {
case 0 :
F_73 ( (struct V_103 * ) & V_118 -> V_104 . V_110 ,
(union V_122 * ) & V_51 -> V_123 [ 0 ] . V_124 ) ;
F_73 ( (struct V_103 * ) & V_118 -> V_104 . V_109 ,
(union V_122 * ) & V_51 -> V_123 [ 0 ] . V_125 ) ;
V_51 -> V_123 [ 0 ] . V_126 = F_69 ( 0xffff ) ;
break;
case 2 :
F_71 ( & V_51 -> V_123 [ 1 ] ,
& V_118 -> V_127 [ 1 ] ) ;
case 1 :
F_71 ( & V_51 -> V_123 [ 0 ] ,
& V_118 -> V_127 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_74 ( struct V_116 * V_51 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 ;
V_120 = & V_118 -> V_104 . V_120 ;
F_67 ( V_120 , (union V_122 * ) & V_51 -> V_123 [ 0 ] . V_124 ) ;
F_68 ( V_120 , (union V_122 * ) & V_51 -> V_123 [ 0 ] . V_125 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_128 V_76 ;
struct V_116 V_51 ;
struct V_1 * V_5 ;
struct V_103 * V_104 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_104 = (struct V_103 * ) & V_5 -> V_19 -> V_118 . V_104 . V_109 ;
memcpy ( & V_51 . V_109 , V_104 , V_104 -> V_129 == V_130 ?
sizeof( struct V_131 ) :
sizeof( struct V_132 ) ) ;
V_104 = (struct V_103 * ) & V_5 -> V_19 -> V_118 . V_104 . V_110 ;
memcpy ( & V_51 . V_110 , V_104 , V_104 -> V_129 == V_130 ?
sizeof( struct V_131 ) :
sizeof( struct V_132 ) ) ;
if ( ! V_5 -> V_19 -> V_133 )
goto V_68;
V_51 . V_134 = ( V_135 V_136 ) V_5 -> V_19 -> V_133 -> V_134 ;
V_51 . V_137 = V_5 -> V_19 -> V_137 ;
if ( F_76 ( V_5 -> V_19 -> V_133 , V_5 -> V_19 -> V_137 ) )
F_66 ( & V_51 , & V_5 -> V_19 -> V_118 ) ;
else if ( F_77 ( V_5 -> V_19 -> V_133 , V_5 -> V_19 -> V_137 ) )
F_72 ( & V_51 , & V_5 -> V_19 -> V_118 ) ;
else if ( F_78 ( V_5 -> V_19 -> V_133 , V_5 -> V_19 -> V_137 ) )
F_74 ( & V_51 , & V_5 -> V_19 -> V_118 ) ;
V_68:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
F_9 ( V_5 ) ;
return V_61 ;
}
static void F_79 ( struct V_53 * V_19 ,
struct V_138 * V_51 )
{
if ( ! V_19 -> V_133 )
return;
V_51 -> V_134 = ( V_135 V_136 ) V_19 -> V_133 -> V_134 ;
V_51 -> V_137 = V_19 -> V_137 ;
V_51 -> V_126 = ( V_135 V_139 ) F_69 (
F_70 ( & V_19 -> V_118 . V_104 . V_120 ) ) ;
}
static T_1 F_80 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_138 V_51 ;
struct V_103 * V_104 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_104 = (struct V_103 * ) & V_5 -> V_19 -> V_118 . V_104 . V_109 ;
V_51 . V_113 = F_60 ( V_104 ) ;
memcpy ( & V_51 . V_109 , V_104 , V_51 . V_113 ) ;
V_104 = (struct V_103 * ) & V_5 -> V_19 -> V_118 . V_104 . V_110 ;
V_51 . V_114 = F_60 ( V_104 ) ;
memcpy ( & V_51 . V_110 , V_104 , V_51 . V_114 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
if ( F_43 ( V_86 , & V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
return V_61 ;
}
static T_1 F_81 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_140 * V_51 ;
int V_141 , V_61 = 0 ;
if ( V_74 < sizeof( * V_51 ) )
return - V_77 ;
V_51 = F_19 ( V_74 , V_20 ) ;
if ( ! V_51 )
return - V_67 ;
V_51 -> V_121 = V_5 -> V_19 -> V_118 . V_121 ;
for ( V_141 = 0 , V_74 -= sizeof( * V_51 ) ;
V_141 < V_51 -> V_121 && V_74 > sizeof( struct V_142 ) ;
V_141 ++ , V_74 -= sizeof( struct V_142 ) ) {
V_51 -> V_143 [ V_141 ] . V_144 = V_145 | V_146 |
V_147 ;
F_82 ( & V_5 -> V_19 -> V_118 . V_127 [ V_141 ] ,
& V_51 -> V_143 [ V_141 ] . V_127 ) ;
}
if ( F_43 ( V_86 , V_51 ,
sizeof( * V_51 ) + ( V_141 * sizeof( struct V_142 ) ) ) )
V_61 = - V_78 ;
F_15 ( V_51 ) ;
return V_61 ;
}
static T_1 F_83 ( struct V_1 * V_5 ,
void T_2 * V_86 , int V_74 )
{
struct V_138 V_51 ;
struct V_148 * V_104 ;
int V_61 = 0 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
F_79 ( V_5 -> V_19 , & V_51 ) ;
V_104 = (struct V_148 * ) & V_51 . V_109 ;
V_51 . V_113 = sizeof( * V_104 ) ;
if ( V_5 -> V_19 -> V_118 . V_104 . V_109 . V_149 == V_150 ) {
memcpy ( V_104 , & V_5 -> V_19 -> V_118 . V_104 . V_109 , V_51 . V_113 ) ;
} else {
V_104 -> V_151 = V_150 ;
V_104 -> V_152 = ( V_135 V_153 ) V_51 . V_126 ;
F_68 ( & V_5 -> V_19 -> V_118 . V_104 . V_120 ,
(union V_122 * ) & V_104 -> V_154 ) ;
V_104 -> V_155 = F_84 ( V_5 -> V_19 , (struct V_103 * )
& V_5 -> V_19 -> V_118 . V_104 . V_109 ) ;
}
V_104 = (struct V_148 * ) & V_51 . V_110 ;
V_51 . V_114 = sizeof( * V_104 ) ;
if ( V_5 -> V_19 -> V_118 . V_104 . V_110 . V_149 == V_150 ) {
memcpy ( V_104 , & V_5 -> V_19 -> V_118 . V_104 . V_110 , V_51 . V_114 ) ;
} else {
V_104 -> V_151 = V_150 ;
V_104 -> V_152 = ( V_135 V_153 ) V_51 . V_126 ;
F_67 ( & V_5 -> V_19 -> V_118 . V_104 . V_120 ,
(union V_122 * ) & V_104 -> V_154 ) ;
V_104 -> V_155 = F_84 ( V_5 -> V_19 , (struct V_103 * )
& V_5 -> V_19 -> V_118 . V_104 . V_110 ) ;
}
if ( F_43 ( V_86 , & V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
return V_61 ;
}
static T_1 F_85 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_128 V_76 ;
struct V_1 * V_5 ;
void T_2 * V_86 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_86 = ( void T_2 * ) ( unsigned long ) V_76 . V_86 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
switch ( V_76 . V_156 ) {
case V_157 :
V_61 = F_80 ( V_5 , V_86 , V_74 ) ;
break;
case V_158 :
V_61 = F_81 ( V_5 , V_86 , V_74 ) ;
break;
case V_159 :
V_61 = F_83 ( V_5 , V_86 , V_74 ) ;
break;
default:
V_61 = - V_160 ;
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
V_28 -> V_43 = ( V_2 -> V_118 . V_104 . V_109 . V_149 == V_150 ) ? V_30 -> V_43 : 0 ;
}
static T_1 F_87 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_161 V_76 ;
struct V_29 V_162 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
if ( ! V_76 . V_162 . V_163 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_86 ( V_5 -> V_19 , & V_162 , & V_76 . V_162 ) ;
V_61 = F_88 ( V_5 -> V_19 , & V_162 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_89 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_164 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_5 -> V_66 = V_76 . V_66 > 0 && V_76 . V_66 < V_165 ?
V_76 . V_66 : V_165 ;
V_61 = F_90 ( V_5 -> V_19 , V_5 -> V_66 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_91 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_166 V_76 ;
struct V_29 V_162 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
if ( V_76 . V_162 . V_163 ) {
F_86 ( V_5 -> V_19 , & V_162 , & V_76 . V_162 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_61 = F_92 ( V_5 -> V_19 , & V_162 ) ;
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
struct V_167 V_76 ;
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
struct V_168 V_76 ;
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
struct V_169 V_76 ;
struct V_170 V_51 ;
struct V_1 * V_5 ;
struct V_171 V_172 ;
int V_61 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_51 . V_173 = 0 ;
memset ( & V_172 , 0 , sizeof V_172 ) ;
V_172 . V_174 = V_76 . V_174 ;
V_61 = F_98 ( V_5 -> V_19 , & V_172 , & V_51 . V_173 ) ;
if ( V_61 )
goto V_68;
F_99 ( & V_51 , & V_172 ) ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
V_68:
F_9 ( V_5 ) ;
return V_61 ;
}
static int F_100 ( struct V_1 * V_5 , int V_175 ,
void * V_176 , T_3 V_177 )
{
int V_61 = 0 ;
switch ( V_175 ) {
case V_178 :
if ( V_177 != sizeof( V_179 ) ) {
V_61 = - V_8 ;
break;
}
F_101 ( V_5 -> V_19 , * ( ( V_179 * ) V_176 ) ) ;
break;
case V_180 :
if ( V_177 != sizeof( int ) ) {
V_61 = - V_8 ;
break;
}
V_61 = F_102 ( V_5 -> V_19 , * ( ( int * ) V_176 ) ? 1 : 0 ) ;
break;
case V_181 :
if ( V_177 != sizeof( int ) ) {
V_61 = - V_8 ;
break;
}
V_61 = F_103 ( V_5 -> V_19 , * ( ( int * ) V_176 ) ? 1 : 0 ) ;
break;
default:
V_61 = - V_160 ;
}
return V_61 ;
}
static int F_104 ( struct V_1 * V_5 ,
struct V_142 * V_143 , T_3 V_177 )
{
struct V_182 V_183 ;
struct V_44 V_45 ;
int V_61 ;
if ( V_177 % sizeof( * V_143 ) )
return - V_8 ;
for (; V_177 ; V_177 -= sizeof( * V_143 ) , V_143 ++ ) {
if ( V_143 -> V_144 == ( V_145 | V_146 |
V_147 ) )
break;
}
if ( ! V_177 )
return - V_8 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_184 = 0xffff ;
F_105 ( V_143 -> V_127 , & V_183 ) ;
V_61 = F_106 ( V_5 -> V_19 , & V_183 , 1 ) ;
if ( V_61 )
return V_61 ;
memset ( & V_45 , 0 , sizeof V_45 ) ;
V_45 . V_45 = V_185 ;
return F_36 ( V_5 -> V_19 , & V_45 ) ;
}
static int F_107 ( struct V_1 * V_5 , int V_175 ,
void * V_176 , T_3 V_177 )
{
int V_61 ;
switch ( V_175 ) {
case V_186 :
V_61 = F_104 ( V_5 , V_176 , V_177 ) ;
break;
default:
V_61 = - V_160 ;
}
return V_61 ;
}
static int F_108 ( struct V_1 * V_5 , int V_187 ,
int V_175 , void * V_176 , T_3 V_177 )
{
int V_61 ;
switch ( V_187 ) {
case V_188 :
V_61 = F_100 ( V_5 , V_175 , V_176 , V_177 ) ;
break;
case V_189 :
V_61 = F_107 ( V_5 , V_175 , V_176 , V_177 ) ;
break;
default:
V_61 = - V_160 ;
}
return V_61 ;
}
static T_1 F_109 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_190 V_76 ;
struct V_1 * V_5 ;
void * V_176 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_176 = F_110 ( ( void T_2 * ) ( unsigned long ) V_76 . V_176 ,
V_76 . V_177 ) ;
if ( F_6 ( V_176 ) ) {
V_61 = F_47 ( V_176 ) ;
goto V_68;
}
V_61 = F_108 ( V_5 , V_76 . V_187 , V_76 . V_175 , V_176 ,
V_76 . V_177 ) ;
F_15 ( V_176 ) ;
V_68:
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_111 ( struct V_3 * V_4 , const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_191 V_76 ;
struct V_1 * V_5 ;
int V_61 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_5 = F_4 ( V_4 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
V_61 = F_112 ( V_5 -> V_19 , (enum V_192 ) V_76 . V_45 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_113 ( struct V_3 * V_4 ,
struct V_193 * V_76 , int V_74 )
{
struct V_96 V_51 ;
struct V_1 * V_5 ;
struct V_24 * V_25 ;
struct V_103 * V_104 ;
int V_61 ;
if ( V_74 < sizeof( V_51 ) )
return - V_77 ;
V_104 = (struct V_103 * ) & V_76 -> V_104 ;
if ( V_76 -> V_106 || ! V_76 -> V_107 || ( V_76 -> V_107 != F_60 ( V_104 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_76 -> V_2 ) ;
if ( F_6 ( V_5 ) )
return F_47 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_25 = F_26 ( V_5 ) ;
if ( ! V_25 ) {
V_61 = - V_67 ;
goto V_97;
}
V_25 -> V_52 = V_76 -> V_52 ;
memcpy ( & V_25 -> V_104 , V_104 , V_76 -> V_107 ) ;
V_61 = F_114 ( V_5 -> V_19 , (struct V_103 * ) & V_25 -> V_104 , V_25 ) ;
if ( V_61 )
goto V_98;
V_51 . V_2 = V_25 -> V_2 ;
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 -> V_86 ,
& V_51 , sizeof( V_51 ) ) ) {
V_61 = - V_78 ;
goto V_194;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_194:
F_115 ( V_5 -> V_19 , (struct V_103 * ) & V_25 -> V_104 ) ;
F_51 ( V_25 ) ;
V_98:
F_5 ( & V_9 ) ;
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_34 ( & V_25 -> V_22 ) ;
F_15 ( V_25 ) ;
V_97:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_61 ;
}
static T_1 F_116 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_195 V_76 ;
struct V_193 V_196 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_196 . V_86 = V_76 . V_86 ;
V_196 . V_52 = V_76 . V_52 ;
V_196 . V_2 = V_76 . V_2 ;
V_196 . V_107 = F_60 ( (struct V_103 * ) & V_76 . V_104 ) ;
V_196 . V_106 = 0 ;
memcpy ( & V_196 . V_104 , & V_76 . V_104 , V_196 . V_107 ) ;
return F_113 ( V_4 , & V_196 , V_74 ) ;
}
static T_1 F_117 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_193 V_76 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
return F_113 ( V_4 , & V_76 , V_74 ) ;
}
static T_1 F_118 ( struct V_3 * V_4 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_100 V_76 ;
struct V_101 V_51 ;
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
V_25 = F_3 ( - V_197 ) ;
else
F_48 ( & V_26 , V_25 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_25 ) ) {
V_61 = F_47 ( V_25 ) ;
goto V_68;
}
F_115 ( V_25 -> V_5 -> V_19 , (struct V_103 * ) & V_25 -> V_104 ) ;
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
static void F_120 ( struct V_3 * V_198 , struct V_3 * V_199 )
{
if ( V_198 < V_199 ) {
F_5 ( & V_198 -> V_9 ) ;
F_121 ( & V_199 -> V_9 , V_200 ) ;
} else {
F_5 ( & V_199 -> V_9 ) ;
F_121 ( & V_198 -> V_9 , V_200 ) ;
}
}
static void F_122 ( struct V_3 * V_198 , struct V_3 * V_199 )
{
if ( V_198 < V_199 ) {
F_8 ( & V_199 -> V_9 ) ;
F_8 ( & V_198 -> V_9 ) ;
} else {
F_8 ( & V_198 -> V_9 ) ;
F_8 ( & V_199 -> V_9 ) ;
}
}
static void F_123 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_16 * V_46 , * V_99 ;
F_50 (uevent, tmp, &ctx->file->event_list, list)
if ( V_46 -> V_5 == V_5 )
F_54 ( & V_46 -> V_22 , & V_4 -> V_70 ) ;
}
static T_1 F_124 ( struct V_3 * V_201 ,
const char T_2 * V_72 ,
int V_73 , int V_74 )
{
struct V_202 V_76 ;
struct V_203 V_51 ;
struct V_1 * V_5 ;
struct V_204 V_205 ;
struct V_3 * V_206 ;
int V_61 = 0 ;
if ( F_39 ( & V_76 , V_72 , sizeof( V_76 ) ) )
return - V_78 ;
V_205 = F_125 ( V_76 . V_204 ) ;
if ( ! V_205 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_205 . V_4 -> V_32 , V_76 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_61 = F_47 ( V_5 ) ;
goto V_207;
}
V_206 = V_5 -> V_4 ;
if ( V_206 == V_201 ) {
V_51 . V_87 = V_5 -> V_87 ;
goto V_86;
}
F_120 ( V_206 , V_201 ) ;
F_5 ( & V_9 ) ;
F_54 ( & V_5 -> V_22 , & V_201 -> V_23 ) ;
F_123 ( V_5 , V_201 ) ;
V_5 -> V_4 = V_201 ;
V_51 . V_87 = V_5 -> V_87 ;
F_8 ( & V_9 ) ;
F_122 ( V_206 , V_201 ) ;
V_86:
if ( F_43 ( ( void T_2 * ) ( unsigned long ) V_76 . V_86 ,
& V_51 , sizeof( V_51 ) ) )
V_61 = - V_78 ;
F_9 ( V_5 ) ;
V_207:
F_126 ( V_205 ) ;
return V_61 ;
}
static T_1 F_127 ( struct V_4 * V_79 , const char T_2 * V_208 ,
T_3 V_209 , T_4 * V_210 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
struct V_211 V_212 ;
T_1 V_61 ;
if ( V_209 < sizeof( V_212 ) )
return - V_8 ;
if ( F_39 ( & V_212 , V_208 , sizeof( V_212 ) ) )
return - V_78 ;
if ( V_212 . V_76 >= F_128 ( V_213 ) )
return - V_8 ;
if ( V_212 . V_214 + sizeof( V_212 ) > V_209 )
return - V_8 ;
if ( ! V_213 [ V_212 . V_76 ] )
return - V_160 ;
V_61 = V_213 [ V_212 . V_76 ] ( V_4 , V_208 + sizeof( V_212 ) , V_212 . V_214 , V_212 . V_68 ) ;
if ( ! V_61 )
V_61 = V_209 ;
return V_61 ;
}
static unsigned int F_129 ( struct V_4 * V_79 , struct V_215 * V_216 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
unsigned int V_217 = 0 ;
V_71 ( V_79 , & V_4 -> V_71 , V_216 ) ;
if ( ! F_40 ( & V_4 -> V_70 ) )
V_217 = V_218 | V_219 ;
return V_217 ;
}
static int F_130 ( struct V_220 * V_220 , struct V_4 * V_79 )
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
return F_135 ( V_220 , V_79 ) ;
}
static int F_136 ( struct V_220 * V_220 , struct V_4 * V_79 )
{
struct V_3 * V_4 = V_79 -> V_32 ;
struct V_1 * V_5 , * V_99 ;
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
static T_1 F_138 ( struct V_133 * V_221 ,
struct V_222 * V_223 ,
char * V_208 )
{
return sprintf ( V_208 , L_3 , V_224 ) ;
}
static int T_5 F_139 ( void )
{
int V_61 ;
V_61 = F_140 ( & V_225 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_141 ( V_225 . V_226 , & V_227 ) ;
if ( V_61 ) {
F_35 ( V_60 L_4 ) ;
goto V_97;
}
V_228 = F_142 ( & V_229 , L_5 , V_230 ) ;
if ( ! V_228 ) {
F_35 ( V_60 L_6 ) ;
V_61 = - V_67 ;
goto V_98;
}
return 0 ;
V_98:
F_143 ( V_225 . V_226 , & V_227 ) ;
V_97:
F_144 ( & V_225 ) ;
return V_61 ;
}
static void T_6 F_145 ( void )
{
F_146 ( V_228 ) ;
F_143 ( V_225 . V_226 , & V_227 ) ;
F_144 ( & V_225 ) ;
F_147 ( & V_6 ) ;
F_147 ( & V_26 ) ;
}
