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
if ( ! F_6 ( V_5 ) )
F_7 ( & V_5 -> V_10 ) ;
F_8 ( & V_9 ) ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_5 )
{
if ( F_10 ( & V_5 -> V_10 ) )
F_11 ( & V_5 -> V_11 ) ;
}
static struct V_1 * F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_13 ( sizeof( * V_5 ) , V_12 ) ;
if ( ! V_5 )
return NULL ;
F_14 ( & V_5 -> V_10 , 1 ) ;
F_15 ( & V_5 -> V_11 ) ;
F_16 ( & V_5 -> V_13 ) ;
V_5 -> V_4 = V_4 ;
F_5 ( & V_9 ) ;
V_5 -> V_2 = F_17 ( & V_6 , V_5 , 0 , 0 , V_12 ) ;
F_8 ( & V_9 ) ;
if ( V_5 -> V_2 < 0 )
goto error;
F_18 ( & V_5 -> V_14 , & V_4 -> V_15 ) ;
return V_5 ;
error:
F_19 ( V_5 ) ;
return NULL ;
}
static struct V_16 * F_20 ( struct V_1 * V_5 )
{
struct V_16 * V_17 ;
V_17 = F_13 ( sizeof( * V_17 ) , V_12 ) ;
if ( ! V_17 )
return NULL ;
F_5 ( & V_9 ) ;
V_17 -> V_2 = F_17 ( & V_18 , V_17 , 0 , 0 , V_12 ) ;
F_8 ( & V_9 ) ;
if ( V_17 -> V_2 < 0 )
goto error;
V_17 -> V_5 = V_5 ;
F_18 ( & V_17 -> V_14 , & V_5 -> V_13 ) ;
return V_17 ;
error:
F_19 ( V_17 ) ;
return NULL ;
}
static void F_21 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_23 )
memcpy ( V_20 -> V_24 , V_22 -> V_24 ,
V_22 -> V_23 ) ;
V_20 -> V_23 = V_22 -> V_23 ;
V_20 -> V_25 = V_22 -> V_25 ;
V_20 -> V_26 = V_22 -> V_26 ;
V_20 -> V_27 = V_22 -> V_27 ;
V_20 -> V_28 = V_22 -> V_28 ;
V_20 -> V_29 = V_22 -> V_29 ;
V_20 -> V_30 = V_22 -> V_30 ;
V_20 -> V_31 = V_22 -> V_31 ;
}
static void F_22 ( struct V_32 * V_20 ,
struct V_33 * V_22 )
{
if ( V_22 -> V_23 )
memcpy ( V_20 -> V_24 , V_22 -> V_24 ,
V_22 -> V_23 ) ;
V_20 -> V_23 = V_22 -> V_23 ;
F_23 ( & V_20 -> V_34 , & V_22 -> V_34 ) ;
V_20 -> V_31 = V_22 -> V_31 ;
V_20 -> V_35 = V_22 -> V_35 ;
}
static void F_24 ( struct V_1 * V_5 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
V_39 -> V_5 = V_5 ;
switch ( V_37 -> V_37 ) {
case V_40 :
case V_41 :
V_39 -> V_17 = (struct V_16 * )
V_37 -> V_42 . V_43 . V_24 ;
V_39 -> V_44 . V_45 = V_39 -> V_17 -> V_45 ;
V_39 -> V_44 . V_2 = V_39 -> V_17 -> V_2 ;
break;
default:
V_39 -> V_44 . V_45 = V_5 -> V_45 ;
V_39 -> V_44 . V_2 = V_5 -> V_2 ;
break;
}
}
static int F_25 ( struct V_46 * V_47 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_1 * V_5 = V_47 -> V_48 ;
int V_49 = 0 ;
V_39 = F_13 ( sizeof( * V_39 ) , V_12 ) ;
if ( ! V_39 )
return V_37 -> V_37 == V_50 ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_39 -> V_47 = V_47 ;
F_24 ( V_5 , V_37 , V_39 ) ;
V_39 -> V_44 . V_37 = V_37 -> V_37 ;
V_39 -> V_44 . V_51 = V_37 -> V_51 ;
if ( V_47 -> V_52 == V_53 )
F_22 ( & V_39 -> V_44 . V_42 . V_43 , & V_37 -> V_42 . V_43 ) ;
else
F_21 ( & V_39 -> V_44 . V_42 . V_54 ,
& V_37 -> V_42 . V_54 ) ;
if ( V_37 -> V_37 == V_50 ) {
if ( ! V_5 -> V_55 ) {
V_49 = - V_56 ;
F_19 ( V_39 ) ;
goto V_57;
}
V_5 -> V_55 -- ;
} else if ( ! V_5 -> V_45 || V_5 -> V_47 != V_47 ) {
F_19 ( V_39 ) ;
goto V_57;
}
F_18 ( & V_39 -> V_14 , & V_5 -> V_4 -> V_58 ) ;
F_26 ( & V_5 -> V_4 -> V_59 ) ;
V_57:
F_8 ( & V_5 -> V_4 -> V_9 ) ;
return V_49 ;
}
static T_1 F_27 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_1 * V_5 ;
struct V_63 V_64 ;
struct V_38 * V_39 ;
int V_49 = 0 ;
if ( V_62 < sizeof V_39 -> V_44 )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_29 ( & V_4 -> V_58 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_67 -> V_68 & V_69 )
return - V_70 ;
if ( F_30 ( V_4 -> V_59 ,
! F_29 ( & V_4 -> V_58 ) ) )
return - V_71 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_39 = F_31 ( V_4 -> V_58 . V_72 , struct V_38 , V_14 ) ;
if ( V_39 -> V_44 . V_37 == V_50 ) {
V_5 = F_12 ( V_4 ) ;
if ( ! V_5 ) {
V_49 = - V_56 ;
goto V_73;
}
V_39 -> V_5 -> V_55 ++ ;
V_5 -> V_47 = V_39 -> V_47 ;
V_5 -> V_47 -> V_48 = V_5 ;
V_39 -> V_44 . V_2 = V_5 -> V_2 ;
}
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_39 -> V_44 , sizeof V_39 -> V_44 ) ) {
V_49 = - V_66 ;
goto V_73;
}
F_33 ( & V_39 -> V_14 ) ;
V_39 -> V_5 -> V_75 ++ ;
if ( V_39 -> V_17 )
V_39 -> V_17 -> V_75 ++ ;
F_19 ( V_39 ) ;
V_73:
F_8 ( & V_4 -> V_9 ) ;
return V_49 ;
}
static int F_34 ( struct V_76 * V_64 , enum V_77 * V_52 )
{
switch ( V_64 -> V_78 ) {
case V_79 :
* V_52 = V_80 ;
return 0 ;
case V_81 :
case V_82 :
* V_52 = V_53 ;
return 0 ;
case V_83 :
* V_52 = V_64 -> V_52 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_35 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_76 V_64 ;
struct V_84 V_44 ;
struct V_1 * V_5 ;
enum V_77 V_52 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_49 = F_34 ( & V_64 , & V_52 ) ;
if ( V_49 )
return V_49 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_12 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_56 ;
V_5 -> V_45 = V_64 . V_45 ;
V_5 -> V_47 = F_36 ( F_25 , V_5 , V_64 . V_78 , V_52 ) ;
if ( F_6 ( V_5 -> V_47 ) ) {
V_49 = F_37 ( V_5 -> V_47 ) ;
goto V_85;
}
V_44 . V_2 = V_5 -> V_2 ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) ) {
V_49 = - V_66 ;
goto V_86;
}
return 0 ;
V_86:
F_38 ( V_5 -> V_47 ) ;
V_85:
F_5 ( & V_9 ) ;
F_39 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_19 ( V_5 ) ;
return V_49 ;
}
static void F_40 ( struct V_1 * V_5 )
{
struct V_16 * V_17 , * V_87 ;
F_5 ( & V_9 ) ;
F_41 (mc, tmp, &ctx->mc_list, list) {
F_33 ( & V_17 -> V_14 ) ;
F_39 ( & V_18 , V_17 -> V_2 ) ;
F_19 ( V_17 ) ;
}
F_8 ( & V_9 ) ;
}
static void F_42 ( struct V_16 * V_17 )
{
struct V_38 * V_39 , * V_87 ;
F_41 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_39 -> V_17 != V_17 )
continue;
F_33 ( & V_39 -> V_14 ) ;
F_19 ( V_39 ) ;
}
}
static int F_43 ( struct V_1 * V_5 )
{
int V_75 ;
struct V_38 * V_39 , * V_87 ;
F_44 ( V_14 ) ;
F_38 ( V_5 -> V_47 ) ;
F_40 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
F_41 (uevent, tmp, &ctx->file->event_list, list) {
if ( V_39 -> V_5 == V_5 )
F_45 ( & V_39 -> V_14 , & V_14 ) ;
}
F_33 ( & V_5 -> V_14 ) ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_41 (uevent, tmp, &list, list) {
F_33 ( & V_39 -> V_14 ) ;
if ( V_39 -> V_44 . V_37 == V_50 )
F_38 ( V_39 -> V_47 ) ;
F_19 ( V_39 ) ;
}
V_75 = V_5 -> V_75 ;
F_19 ( V_5 ) ;
return V_75 ;
}
static T_1 F_46 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_88 V_64 ;
struct V_89 V_44 ;
struct V_1 * V_5 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_64 . V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) )
F_39 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_9 ( V_5 ) ;
F_47 ( & V_5 -> V_11 ) ;
V_44 . V_75 = F_43 ( V_5 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_48 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_90 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_49 ( V_5 -> V_47 , (struct V_91 * ) & V_64 . V_92 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_50 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_93 V_64 ;
struct V_91 * V_92 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_92 = (struct V_91 * ) & V_64 . V_92 ;
if ( V_64 . V_94 || ! V_64 . V_95 || ( V_64 . V_95 != F_51 ( V_92 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_49 ( V_5 -> V_47 , V_92 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_52 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_96 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_53 ( V_5 -> V_47 , (struct V_91 * ) & V_64 . V_97 ,
(struct V_91 * ) & V_64 . V_98 ,
V_64 . V_99 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_54 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_100 V_64 ;
struct V_91 * V_22 , * V_20 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_22 = (struct V_91 * ) & V_64 . V_97 ;
V_20 = (struct V_91 * ) & V_64 . V_98 ;
if ( V_64 . V_94 || ( V_64 . V_101 && ( V_64 . V_101 != F_51 ( V_22 ) ) ) ||
! V_64 . V_102 || ( V_64 . V_102 != F_51 ( V_20 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_53 ( V_5 -> V_47 , V_22 , V_20 , V_64 . V_99 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_55 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_103 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_56 ( V_5 -> V_47 , V_64 . V_99 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_57 ( struct V_104 * V_44 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
V_44 -> V_109 = V_106 -> V_109 ;
switch ( V_106 -> V_109 ) {
case 0 :
V_108 = & V_106 -> V_92 . V_108 ;
F_58 ( V_108 ,
(union V_110 * ) & V_44 -> V_111 [ 0 ] . V_112 ) ;
F_59 ( V_108 ,
(union V_110 * ) & V_44 -> V_111 [ 0 ] . V_113 ) ;
V_44 -> V_111 [ 0 ] . V_114 = F_60 ( F_61 ( V_108 ) ) ;
break;
case 2 :
F_62 ( & V_44 -> V_111 [ 1 ] ,
& V_106 -> V_115 [ 1 ] ) ;
case 1 :
F_62 ( & V_44 -> V_111 [ 0 ] ,
& V_106 -> V_115 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_63 ( struct V_104 * V_44 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
struct V_116 * V_117 ;
T_3 V_118 = 0 ;
V_44 -> V_109 = V_106 -> V_109 ;
switch ( V_106 -> V_109 ) {
case 0 :
V_108 = & V_106 -> V_92 . V_108 ;
V_117 = F_64 ( & V_119 , V_108 -> V_120 ) ;
if ( V_117 ) {
V_118 = F_65 ( V_117 ) ;
F_66 ( V_117 ) ;
}
F_67 ( (union V_110 * ) & V_44 -> V_111 [ 0 ] . V_112 ,
V_108 -> V_121 , V_118 ) ;
F_68 ( V_108 ,
(union V_110 * ) & V_44 -> V_111 [ 0 ] . V_113 ) ;
V_44 -> V_111 [ 0 ] . V_114 = F_60 ( 0xffff ) ;
break;
case 2 :
F_62 ( & V_44 -> V_111 [ 1 ] ,
& V_106 -> V_115 [ 1 ] ) ;
case 1 :
F_62 ( & V_44 -> V_111 [ 0 ] ,
& V_106 -> V_115 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_69 ( struct V_104 * V_44 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
V_108 = & V_106 -> V_92 . V_108 ;
F_58 ( V_108 , (union V_110 * ) & V_44 -> V_111 [ 0 ] . V_112 ) ;
F_59 ( V_108 , (union V_110 * ) & V_44 -> V_111 [ 0 ] . V_113 ) ;
}
static T_1 F_70 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_122 V_64 ;
struct V_104 V_44 ;
struct V_1 * V_5 ;
struct V_91 * V_92 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
memset ( & V_44 , 0 , sizeof V_44 ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_106 . V_92 . V_97 ;
memcpy ( & V_44 . V_97 , V_92 , V_92 -> V_123 == V_124 ?
sizeof( struct V_125 ) :
sizeof( struct V_126 ) ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_106 . V_92 . V_98 ;
memcpy ( & V_44 . V_98 , V_92 , V_92 -> V_123 == V_124 ?
sizeof( struct V_125 ) :
sizeof( struct V_126 ) ) ;
if ( ! V_5 -> V_47 -> V_127 )
goto V_57;
V_44 . V_128 = ( V_129 V_130 ) V_5 -> V_47 -> V_127 -> V_128 ;
V_44 . V_131 = V_5 -> V_47 -> V_131 ;
switch ( F_71 ( V_5 -> V_47 -> V_127 -> V_132 ) ) {
case V_133 :
switch ( F_72 ( V_5 -> V_47 -> V_127 ,
V_5 -> V_47 -> V_131 ) ) {
case V_134 :
F_57 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
break;
case V_135 :
F_63 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
break;
default:
break;
}
break;
case V_136 :
F_69 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
break;
default:
break;
}
V_57:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_73 ( struct V_46 * V_47 ,
struct V_137 * V_44 )
{
if ( ! V_47 -> V_127 )
return;
V_44 -> V_128 = ( V_129 V_130 ) V_47 -> V_127 -> V_128 ;
V_44 -> V_131 = V_47 -> V_131 ;
V_44 -> V_114 = ( V_129 V_138 ) F_60 (
F_61 ( & V_47 -> V_106 . V_92 . V_108 ) ) ;
}
static T_1 F_74 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_137 V_44 ;
struct V_91 * V_92 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
memset ( & V_44 , 0 , sizeof V_44 ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_106 . V_92 . V_97 ;
V_44 . V_101 = F_51 ( V_92 ) ;
memcpy ( & V_44 . V_97 , V_92 , V_44 . V_101 ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_106 . V_92 . V_98 ;
V_44 . V_102 = F_51 ( V_92 ) ;
memcpy ( & V_44 . V_98 , V_92 , V_44 . V_102 ) ;
F_73 ( V_5 -> V_47 , & V_44 ) ;
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_75 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_139 * V_44 ;
int V_140 , V_49 = 0 ;
if ( V_62 < sizeof( * V_44 ) )
return - V_65 ;
V_44 = F_13 ( V_62 , V_12 ) ;
if ( ! V_44 )
return - V_56 ;
V_44 -> V_109 = V_5 -> V_47 -> V_106 . V_109 ;
for ( V_140 = 0 , V_62 -= sizeof( * V_44 ) ;
V_140 < V_44 -> V_109 && V_62 > sizeof( struct V_141 ) ;
V_140 ++ , V_62 -= sizeof( struct V_141 ) ) {
V_44 -> V_142 [ V_140 ] . V_143 = V_144 | V_145 |
V_146 ;
F_76 ( & V_5 -> V_47 -> V_106 . V_115 [ V_140 ] ,
& V_44 -> V_142 [ V_140 ] . V_115 ) ;
}
if ( F_32 ( V_74 , V_44 ,
sizeof( * V_44 ) + ( V_140 * sizeof( struct V_141 ) ) ) )
V_49 = - V_66 ;
F_19 ( V_44 ) ;
return V_49 ;
}
static T_1 F_77 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_137 V_44 ;
struct V_147 * V_92 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
memset ( & V_44 , 0 , sizeof V_44 ) ;
F_73 ( V_5 -> V_47 , & V_44 ) ;
V_92 = (struct V_147 * ) & V_44 . V_97 ;
V_44 . V_101 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_97 . V_148 == V_149 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_97 , V_44 . V_101 ) ;
} else {
V_92 -> V_150 = V_149 ;
V_92 -> V_151 = ( V_129 V_152 ) V_44 . V_114 ;
F_59 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_153 ) ;
V_92 -> V_154 = F_78 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_97 ) ;
}
V_92 = (struct V_147 * ) & V_44 . V_98 ;
V_44 . V_102 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_98 . V_148 == V_149 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_98 , V_44 . V_102 ) ;
} else {
V_92 -> V_150 = V_149 ;
V_92 -> V_151 = ( V_129 V_152 ) V_44 . V_114 ;
F_58 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_153 ) ;
V_92 -> V_154 = F_78 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_98 ) ;
}
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_79 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_122 V_64 ;
struct V_1 * V_5 ;
void T_2 * V_74 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_74 = ( void T_2 * ) ( unsigned long ) V_64 . V_74 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
switch ( V_64 . V_155 ) {
case V_156 :
V_49 = F_74 ( V_5 , V_74 , V_62 ) ;
break;
case V_157 :
V_49 = F_75 ( V_5 , V_74 , V_62 ) ;
break;
case V_158 :
V_49 = F_77 ( V_5 , V_74 , V_62 ) ;
break;
default:
V_49 = - V_159 ;
break;
}
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_80 ( struct V_46 * V_2 ,
struct V_21 * V_20 ,
struct V_19 * V_22 )
{
V_20 -> V_24 = V_22 -> V_24 ;
V_20 -> V_23 = V_22 -> V_23 ;
V_20 -> V_25 = V_22 -> V_25 ;
V_20 -> V_26 = V_22 -> V_26 ;
V_20 -> V_27 = V_22 -> V_27 ;
V_20 -> V_28 = V_22 -> V_28 ;
V_20 -> V_29 = V_22 -> V_29 ;
V_20 -> V_30 = V_22 -> V_30 ;
V_20 -> V_31 = V_22 -> V_31 ;
V_20 -> V_35 = ( V_2 -> V_106 . V_92 . V_97 . V_148 == V_149 ) ? V_22 -> V_35 : 0 ;
}
static T_1 F_81 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_160 V_64 ;
struct V_21 V_161 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
if ( ! V_64 . V_161 . V_162 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_80 ( V_5 -> V_47 , & V_161 , & V_64 . V_161 ) ;
V_49 = F_82 ( V_5 -> V_47 , & V_161 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_83 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_163 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_5 -> V_55 = V_64 . V_55 > 0 && V_64 . V_55 < V_164 ?
V_64 . V_55 : V_164 ;
V_49 = F_84 ( V_5 -> V_47 , V_5 -> V_55 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_85 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_165 V_64 ;
struct V_21 V_161 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
if ( V_64 . V_161 . V_162 ) {
F_80 ( V_5 -> V_47 , & V_161 , & V_64 . V_161 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_49 = F_86 ( V_5 -> V_47 , & V_161 ) ;
if ( ! V_49 )
V_5 -> V_45 = V_64 . V_45 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_49 = F_86 ( V_5 -> V_47 , NULL ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_87 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_166 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_88 ( V_5 -> V_47 , V_64 . V_24 , V_64 . V_23 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_89 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_167 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_90 ( V_5 -> V_47 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_91 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_168 V_64 ;
struct V_169 V_44 ;
struct V_1 * V_5 ;
struct V_170 V_171 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_44 . V_172 = 0 ;
memset ( & V_171 , 0 , sizeof V_171 ) ;
V_171 . V_173 = V_64 . V_173 ;
V_49 = F_92 ( V_5 -> V_47 , & V_171 , & V_44 . V_172 ) ;
if ( V_49 )
goto V_57;
F_93 ( & V_44 , & V_171 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static int F_94 ( struct V_1 * V_5 , int V_174 ,
void * V_175 , T_4 V_176 )
{
int V_49 = 0 ;
switch ( V_174 ) {
case V_177 :
if ( V_176 != sizeof( V_178 ) ) {
V_49 = - V_8 ;
break;
}
F_95 ( V_5 -> V_47 , * ( ( V_178 * ) V_175 ) ) ;
break;
case V_179 :
if ( V_176 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_96 ( V_5 -> V_47 , * ( ( int * ) V_175 ) ? 1 : 0 ) ;
break;
case V_180 :
if ( V_176 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_97 ( V_5 -> V_47 , * ( ( int * ) V_175 ) ? 1 : 0 ) ;
break;
default:
V_49 = - V_159 ;
}
return V_49 ;
}
static int F_98 ( struct V_1 * V_5 ,
struct V_141 * V_142 , T_4 V_176 )
{
struct V_181 V_182 ;
struct V_36 V_37 ;
int V_49 ;
if ( V_176 % sizeof( * V_142 ) )
return - V_8 ;
for (; V_176 ; V_176 -= sizeof( * V_142 ) , V_142 ++ ) {
if ( V_142 -> V_143 == ( V_144 | V_145 |
V_146 ) )
break;
}
if ( ! V_176 )
return - V_8 ;
F_99 ( V_142 -> V_115 , & V_182 ) ;
V_49 = F_100 ( V_5 -> V_47 , & V_182 , 1 ) ;
if ( V_49 )
return V_49 ;
memset ( & V_37 , 0 , sizeof V_37 ) ;
V_37 . V_37 = V_183 ;
return F_25 ( V_5 -> V_47 , & V_37 ) ;
}
static int F_101 ( struct V_1 * V_5 , int V_174 ,
void * V_175 , T_4 V_176 )
{
int V_49 ;
switch ( V_174 ) {
case V_184 :
V_49 = F_98 ( V_5 , V_175 , V_176 ) ;
break;
default:
V_49 = - V_159 ;
}
return V_49 ;
}
static int F_102 ( struct V_1 * V_5 , int V_185 ,
int V_174 , void * V_175 , T_4 V_176 )
{
int V_49 ;
switch ( V_185 ) {
case V_186 :
V_49 = F_94 ( V_5 , V_174 , V_175 , V_176 ) ;
break;
case V_187 :
V_49 = F_101 ( V_5 , V_174 , V_175 , V_176 ) ;
break;
default:
V_49 = - V_159 ;
}
return V_49 ;
}
static T_1 F_103 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_188 V_64 ;
struct V_1 * V_5 ;
void * V_175 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_175 = F_104 ( ( void T_2 * ) ( unsigned long ) V_64 . V_175 ,
V_64 . V_176 ) ;
if ( F_6 ( V_175 ) ) {
V_49 = F_37 ( V_175 ) ;
goto V_57;
}
V_49 = F_102 ( V_5 , V_64 . V_185 , V_64 . V_174 , V_175 ,
V_64 . V_176 ) ;
F_19 ( V_175 ) ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_105 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_189 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_106 ( V_5 -> V_47 , (enum V_190 ) V_64 . V_37 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_107 ( struct V_3 * V_4 ,
struct V_191 * V_64 , int V_62 )
{
struct V_84 V_44 ;
struct V_1 * V_5 ;
struct V_16 * V_17 ;
struct V_91 * V_92 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
V_92 = (struct V_91 * ) & V_64 -> V_92 ;
if ( V_64 -> V_94 || ! V_64 -> V_95 || ( V_64 -> V_95 != F_51 ( V_92 ) ) )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 -> V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_17 = F_20 ( V_5 ) ;
if ( ! V_17 ) {
V_49 = - V_56 ;
goto V_85;
}
V_17 -> V_45 = V_64 -> V_45 ;
memcpy ( & V_17 -> V_92 , V_92 , V_64 -> V_95 ) ;
V_49 = F_108 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 , V_17 ) ;
if ( V_49 )
goto V_86;
V_44 . V_2 = V_17 -> V_2 ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 -> V_74 ,
& V_44 , sizeof( V_44 ) ) ) {
V_49 = - V_66 ;
goto V_192;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_192:
F_109 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
F_42 ( V_17 ) ;
V_86:
F_5 ( & V_9 ) ;
F_39 ( & V_18 , V_17 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_33 ( & V_17 -> V_14 ) ;
F_19 ( V_17 ) ;
V_85:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_110 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_193 V_64 ;
struct V_191 V_194 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_194 . V_74 = V_64 . V_74 ;
V_194 . V_45 = V_64 . V_45 ;
V_194 . V_2 = V_64 . V_2 ;
V_194 . V_95 = F_51 ( (struct V_91 * ) & V_64 . V_92 ) ;
V_194 . V_94 = 0 ;
memcpy ( & V_194 . V_92 , & V_64 . V_92 , V_194 . V_95 ) ;
return F_107 ( V_4 , & V_194 , V_62 ) ;
}
static T_1 F_111 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_191 V_64 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
return F_107 ( V_4 , & V_64 , V_62 ) ;
}
static T_1 F_112 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_88 V_64 ;
struct V_89 V_44 ;
struct V_16 * V_17 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
F_5 ( & V_9 ) ;
V_17 = F_2 ( & V_18 , V_64 . V_2 ) ;
if ( ! V_17 )
V_17 = F_3 ( - V_7 ) ;
else if ( V_17 -> V_5 -> V_4 != V_4 )
V_17 = F_3 ( - V_8 ) ;
else {
F_39 ( & V_18 , V_17 -> V_2 ) ;
F_7 ( & V_17 -> V_5 -> V_10 ) ;
}
F_8 ( & V_9 ) ;
if ( F_6 ( V_17 ) ) {
V_49 = F_37 ( V_17 ) ;
goto V_57;
}
F_109 ( V_17 -> V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
F_5 ( & V_17 -> V_5 -> V_4 -> V_9 ) ;
F_42 ( V_17 ) ;
F_33 ( & V_17 -> V_14 ) ;
F_8 ( & V_17 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_17 -> V_5 ) ;
V_44 . V_75 = V_17 -> V_75 ;
F_19 ( V_17 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
V_57:
return V_49 ;
}
static void F_113 ( struct V_3 * V_195 , struct V_3 * V_196 )
{
if ( V_195 < V_196 ) {
F_5 ( & V_195 -> V_9 ) ;
F_5 ( & V_196 -> V_9 ) ;
} else {
F_5 ( & V_196 -> V_9 ) ;
F_5 ( & V_195 -> V_9 ) ;
}
}
static void F_114 ( struct V_3 * V_195 , struct V_3 * V_196 )
{
if ( V_195 < V_196 ) {
F_8 ( & V_196 -> V_9 ) ;
F_8 ( & V_195 -> V_9 ) ;
} else {
F_8 ( & V_195 -> V_9 ) ;
F_8 ( & V_196 -> V_9 ) ;
}
}
static void F_115 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_38 * V_39 , * V_87 ;
F_41 (uevent, tmp, &ctx->file->event_list, list)
if ( V_39 -> V_5 == V_5 )
F_45 ( & V_39 -> V_14 , & V_4 -> V_58 ) ;
}
static T_1 F_116 ( struct V_3 * V_197 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_198 V_64 ;
struct V_199 V_44 ;
struct V_1 * V_5 ;
struct V_200 V_201 ;
struct V_3 * V_202 ;
int V_49 = 0 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_201 = F_117 ( V_64 . V_200 ) ;
if ( ! V_201 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_201 . V_4 -> V_24 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_49 = F_37 ( V_5 ) ;
goto V_203;
}
V_202 = V_5 -> V_4 ;
if ( V_202 == V_197 ) {
V_44 . V_75 = V_5 -> V_75 ;
goto V_74;
}
F_113 ( V_202 , V_197 ) ;
F_5 ( & V_9 ) ;
F_45 ( & V_5 -> V_14 , & V_197 -> V_15 ) ;
F_115 ( V_5 , V_197 ) ;
V_5 -> V_4 = V_197 ;
V_44 . V_75 = V_5 -> V_75 ;
F_8 ( & V_9 ) ;
F_114 ( V_202 , V_197 ) ;
V_74:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
V_203:
F_118 ( V_201 ) ;
return V_49 ;
}
static T_1 F_119 ( struct V_4 * V_67 , const char T_2 * V_204 ,
T_4 V_205 , T_5 * V_206 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
struct V_207 V_208 ;
T_1 V_49 ;
if ( V_205 < sizeof( V_208 ) )
return - V_8 ;
if ( F_28 ( & V_208 , V_204 , sizeof( V_208 ) ) )
return - V_66 ;
if ( V_208 . V_64 >= F_120 ( V_209 ) )
return - V_8 ;
if ( V_208 . V_210 + sizeof( V_208 ) > V_205 )
return - V_8 ;
if ( ! V_209 [ V_208 . V_64 ] )
return - V_159 ;
V_49 = V_209 [ V_208 . V_64 ] ( V_4 , V_204 + sizeof( V_208 ) , V_208 . V_210 , V_208 . V_57 ) ;
if ( ! V_49 )
V_49 = V_205 ;
return V_49 ;
}
static unsigned int F_121 ( struct V_4 * V_67 , struct V_211 * V_212 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
unsigned int V_213 = 0 ;
V_59 ( V_67 , & V_4 -> V_59 , V_212 ) ;
if ( ! F_29 ( & V_4 -> V_58 ) )
V_213 = V_214 | V_215 ;
return V_213 ;
}
static int F_122 ( struct V_216 * V_216 , struct V_4 * V_67 )
{
struct V_3 * V_4 ;
V_4 = F_123 ( sizeof *V_4 , V_12 ) ;
if ( ! V_4 )
return - V_56 ;
F_16 ( & V_4 -> V_58 ) ;
F_16 ( & V_4 -> V_15 ) ;
F_124 ( & V_4 -> V_59 ) ;
F_125 ( & V_4 -> V_9 ) ;
V_67 -> V_24 = V_4 ;
V_4 -> V_67 = V_67 ;
return F_126 ( V_216 , V_67 ) ;
}
static int F_127 ( struct V_216 * V_216 , struct V_4 * V_67 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
struct V_1 * V_5 , * V_87 ;
F_5 ( & V_4 -> V_9 ) ;
F_41 (ctx, tmp, &file->ctx_list, list) {
F_8 ( & V_4 -> V_9 ) ;
F_5 ( & V_9 ) ;
F_39 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_43 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_4 -> V_9 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static T_1 F_128 ( struct V_127 * V_117 ,
struct V_217 * V_218 ,
char * V_204 )
{
return sprintf ( V_204 , L_1 , V_219 ) ;
}
static int T_6 F_129 ( void )
{
int V_49 ;
V_49 = F_130 ( & V_220 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_131 ( V_220 . V_221 , & V_222 ) ;
if ( V_49 ) {
F_132 ( V_223 L_2 ) ;
goto V_85;
}
V_224 = F_133 ( & V_119 , L_3 , V_225 ) ;
if ( ! V_224 ) {
F_132 ( V_223 L_4 ) ;
V_49 = - V_56 ;
goto V_86;
}
return 0 ;
V_86:
F_134 ( V_220 . V_221 , & V_222 ) ;
V_85:
F_135 ( & V_220 ) ;
return V_49 ;
}
static void T_7 F_136 ( void )
{
F_137 ( V_224 ) ;
F_134 ( V_220 . V_221 , & V_222 ) ;
F_135 ( & V_220 ) ;
F_138 ( & V_6 ) ;
}
