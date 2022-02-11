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
V_44 -> V_109 = V_106 -> V_109 ;
switch ( V_106 -> V_109 ) {
case 0 :
F_64 ( (struct V_91 * ) & V_106 -> V_92 . V_98 ,
(union V_110 * ) & V_44 -> V_111 [ 0 ] . V_112 ) ;
F_64 ( (struct V_91 * ) & V_106 -> V_92 . V_97 ,
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
static void F_65 ( struct V_104 * V_44 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
V_108 = & V_106 -> V_92 . V_108 ;
F_58 ( V_108 , (union V_110 * ) & V_44 -> V_111 [ 0 ] . V_112 ) ;
F_59 ( V_108 , (union V_110 * ) & V_44 -> V_111 [ 0 ] . V_113 ) ;
}
static T_1 F_66 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_116 V_64 ;
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
memcpy ( & V_44 . V_97 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_106 . V_92 . V_98 ;
memcpy ( & V_44 . V_98 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
if ( ! V_5 -> V_47 -> V_121 )
goto V_57;
V_44 . V_122 = ( V_123 V_124 ) V_5 -> V_47 -> V_121 -> V_122 ;
V_44 . V_125 = V_5 -> V_47 -> V_125 ;
switch ( F_67 ( V_5 -> V_47 -> V_121 -> V_126 ) ) {
case V_127 :
switch ( F_68 ( V_5 -> V_47 -> V_121 ,
V_5 -> V_47 -> V_125 ) ) {
case V_128 :
F_57 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
break;
case V_129 :
F_63 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
break;
default:
break;
}
break;
case V_130 :
F_65 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
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
static void F_69 ( struct V_46 * V_47 ,
struct V_131 * V_44 )
{
if ( ! V_47 -> V_121 )
return;
V_44 -> V_122 = ( V_123 V_124 ) V_47 -> V_121 -> V_122 ;
V_44 -> V_125 = V_47 -> V_125 ;
V_44 -> V_114 = ( V_123 V_132 ) F_60 (
F_61 ( & V_47 -> V_106 . V_92 . V_108 ) ) ;
}
static T_1 F_70 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_131 V_44 ;
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
F_69 ( V_5 -> V_47 , & V_44 ) ;
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_71 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_133 * V_44 ;
int V_134 , V_49 = 0 ;
if ( V_62 < sizeof( * V_44 ) )
return - V_65 ;
V_44 = F_13 ( V_62 , V_12 ) ;
if ( ! V_44 )
return - V_56 ;
V_44 -> V_109 = V_5 -> V_47 -> V_106 . V_109 ;
for ( V_134 = 0 , V_62 -= sizeof( * V_44 ) ;
V_134 < V_44 -> V_109 && V_62 > sizeof( struct V_135 ) ;
V_134 ++ , V_62 -= sizeof( struct V_135 ) ) {
V_44 -> V_136 [ V_134 ] . V_137 = V_138 | V_139 |
V_140 ;
F_72 ( & V_5 -> V_47 -> V_106 . V_115 [ V_134 ] ,
& V_44 -> V_136 [ V_134 ] . V_115 ) ;
}
if ( F_32 ( V_74 , V_44 ,
sizeof( * V_44 ) + ( V_134 * sizeof( struct V_135 ) ) ) )
V_49 = - V_66 ;
F_19 ( V_44 ) ;
return V_49 ;
}
static T_1 F_73 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_131 V_44 ;
struct V_141 * V_92 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
memset ( & V_44 , 0 , sizeof V_44 ) ;
F_69 ( V_5 -> V_47 , & V_44 ) ;
V_92 = (struct V_141 * ) & V_44 . V_97 ;
V_44 . V_101 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_97 . V_142 == V_143 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_97 , V_44 . V_101 ) ;
} else {
V_92 -> V_144 = V_143 ;
V_92 -> V_145 = ( V_123 V_146 ) V_44 . V_114 ;
F_59 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_147 ) ;
V_92 -> V_148 = F_74 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_97 ) ;
}
V_92 = (struct V_141 * ) & V_44 . V_98 ;
V_44 . V_102 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_98 . V_142 == V_143 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_98 , V_44 . V_102 ) ;
} else {
V_92 -> V_144 = V_143 ;
V_92 -> V_145 = ( V_123 V_146 ) V_44 . V_114 ;
F_58 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_147 ) ;
V_92 -> V_148 = F_74 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_98 ) ;
}
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_116 V_64 ;
struct V_1 * V_5 ;
void T_2 * V_74 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_74 = ( void T_2 * ) ( unsigned long ) V_64 . V_74 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
switch ( V_64 . V_149 ) {
case V_150 :
V_49 = F_70 ( V_5 , V_74 , V_62 ) ;
break;
case V_151 :
V_49 = F_71 ( V_5 , V_74 , V_62 ) ;
break;
case V_152 :
V_49 = F_73 ( V_5 , V_74 , V_62 ) ;
break;
default:
V_49 = - V_153 ;
break;
}
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_76 ( struct V_46 * V_2 ,
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
V_20 -> V_35 = ( V_2 -> V_106 . V_92 . V_97 . V_142 == V_143 ) ? V_22 -> V_35 : 0 ;
}
static T_1 F_77 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_154 V_64 ;
struct V_21 V_155 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
if ( ! V_64 . V_155 . V_156 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_76 ( V_5 -> V_47 , & V_155 , & V_64 . V_155 ) ;
V_49 = F_78 ( V_5 -> V_47 , & V_155 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_79 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_157 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_5 -> V_55 = V_64 . V_55 > 0 && V_64 . V_55 < V_158 ?
V_64 . V_55 : V_158 ;
V_49 = F_80 ( V_5 -> V_47 , V_5 -> V_55 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_81 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_159 V_64 ;
struct V_21 V_155 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
if ( V_64 . V_155 . V_156 ) {
F_76 ( V_5 -> V_47 , & V_155 , & V_64 . V_155 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_49 = F_82 ( V_5 -> V_47 , & V_155 ) ;
if ( ! V_49 )
V_5 -> V_45 = V_64 . V_45 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_49 = F_82 ( V_5 -> V_47 , NULL ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_83 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_160 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_84 ( V_5 -> V_47 , V_64 . V_24 , V_64 . V_23 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_85 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_161 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_86 ( V_5 -> V_47 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_87 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_162 V_64 ;
struct V_163 V_44 ;
struct V_1 * V_5 ;
struct V_164 V_165 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_44 . V_166 = 0 ;
memset ( & V_165 , 0 , sizeof V_165 ) ;
V_165 . V_167 = V_64 . V_167 ;
V_49 = F_88 ( V_5 -> V_47 , & V_165 , & V_44 . V_166 ) ;
if ( V_49 )
goto V_57;
F_89 ( & V_44 , & V_165 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static int F_90 ( struct V_1 * V_5 , int V_168 ,
void * V_169 , T_3 V_170 )
{
int V_49 = 0 ;
switch ( V_168 ) {
case V_171 :
if ( V_170 != sizeof( V_172 ) ) {
V_49 = - V_8 ;
break;
}
F_91 ( V_5 -> V_47 , * ( ( V_172 * ) V_169 ) ) ;
break;
case V_173 :
if ( V_170 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_92 ( V_5 -> V_47 , * ( ( int * ) V_169 ) ? 1 : 0 ) ;
break;
case V_174 :
if ( V_170 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_93 ( V_5 -> V_47 , * ( ( int * ) V_169 ) ? 1 : 0 ) ;
break;
default:
V_49 = - V_153 ;
}
return V_49 ;
}
static int F_94 ( struct V_1 * V_5 ,
struct V_135 * V_136 , T_3 V_170 )
{
struct V_175 V_176 ;
struct V_36 V_37 ;
int V_49 ;
if ( V_170 % sizeof( * V_136 ) )
return - V_8 ;
for (; V_170 ; V_170 -= sizeof( * V_136 ) , V_136 ++ ) {
if ( V_136 -> V_137 == ( V_138 | V_139 |
V_140 ) )
break;
}
if ( ! V_170 )
return - V_8 ;
F_95 ( V_136 -> V_115 , & V_176 ) ;
V_49 = F_96 ( V_5 -> V_47 , & V_176 , 1 ) ;
if ( V_49 )
return V_49 ;
memset ( & V_37 , 0 , sizeof V_37 ) ;
V_37 . V_37 = V_177 ;
return F_25 ( V_5 -> V_47 , & V_37 ) ;
}
static int F_97 ( struct V_1 * V_5 , int V_168 ,
void * V_169 , T_3 V_170 )
{
int V_49 ;
switch ( V_168 ) {
case V_178 :
V_49 = F_94 ( V_5 , V_169 , V_170 ) ;
break;
default:
V_49 = - V_153 ;
}
return V_49 ;
}
static int F_98 ( struct V_1 * V_5 , int V_179 ,
int V_168 , void * V_169 , T_3 V_170 )
{
int V_49 ;
switch ( V_179 ) {
case V_180 :
V_49 = F_90 ( V_5 , V_168 , V_169 , V_170 ) ;
break;
case V_181 :
V_49 = F_97 ( V_5 , V_168 , V_169 , V_170 ) ;
break;
default:
V_49 = - V_153 ;
}
return V_49 ;
}
static T_1 F_99 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_182 V_64 ;
struct V_1 * V_5 ;
void * V_169 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_169 = F_100 ( ( void T_2 * ) ( unsigned long ) V_64 . V_169 ,
V_64 . V_170 ) ;
if ( F_6 ( V_169 ) ) {
V_49 = F_37 ( V_169 ) ;
goto V_57;
}
V_49 = F_98 ( V_5 , V_64 . V_179 , V_64 . V_168 , V_169 ,
V_64 . V_170 ) ;
F_19 ( V_169 ) ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_101 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_183 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_102 ( V_5 -> V_47 , (enum V_184 ) V_64 . V_37 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_103 ( struct V_3 * V_4 ,
struct V_185 * V_64 , int V_62 )
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
V_49 = F_104 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 , V_17 ) ;
if ( V_49 )
goto V_86;
V_44 . V_2 = V_17 -> V_2 ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 -> V_74 ,
& V_44 , sizeof( V_44 ) ) ) {
V_49 = - V_66 ;
goto V_186;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_186:
F_105 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static T_1 F_106 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_187 V_64 ;
struct V_185 V_188 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_188 . V_74 = V_64 . V_74 ;
V_188 . V_45 = V_64 . V_45 ;
V_188 . V_2 = V_64 . V_2 ;
V_188 . V_95 = F_51 ( (struct V_91 * ) & V_64 . V_92 ) ;
V_188 . V_94 = 0 ;
memcpy ( & V_188 . V_92 , & V_64 . V_92 , V_188 . V_95 ) ;
return F_103 ( V_4 , & V_188 , V_62 ) ;
}
static T_1 F_107 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_185 V_64 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
return F_103 ( V_4 , & V_64 , V_62 ) ;
}
static T_1 F_108 ( struct V_3 * V_4 ,
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
F_105 ( V_17 -> V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static void F_109 ( struct V_3 * V_189 , struct V_3 * V_190 )
{
if ( V_189 < V_190 ) {
F_5 ( & V_189 -> V_9 ) ;
F_5 ( & V_190 -> V_9 ) ;
} else {
F_5 ( & V_190 -> V_9 ) ;
F_5 ( & V_189 -> V_9 ) ;
}
}
static void F_110 ( struct V_3 * V_189 , struct V_3 * V_190 )
{
if ( V_189 < V_190 ) {
F_8 ( & V_190 -> V_9 ) ;
F_8 ( & V_189 -> V_9 ) ;
} else {
F_8 ( & V_189 -> V_9 ) ;
F_8 ( & V_190 -> V_9 ) ;
}
}
static void F_111 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_38 * V_39 , * V_87 ;
F_41 (uevent, tmp, &ctx->file->event_list, list)
if ( V_39 -> V_5 == V_5 )
F_45 ( & V_39 -> V_14 , & V_4 -> V_58 ) ;
}
static T_1 F_112 ( struct V_3 * V_191 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_192 V_64 ;
struct V_193 V_44 ;
struct V_1 * V_5 ;
struct V_194 V_195 ;
struct V_3 * V_196 ;
int V_49 = 0 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_195 = F_113 ( V_64 . V_194 ) ;
if ( ! V_195 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_195 . V_4 -> V_24 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_49 = F_37 ( V_5 ) ;
goto V_197;
}
V_196 = V_5 -> V_4 ;
if ( V_196 == V_191 ) {
V_44 . V_75 = V_5 -> V_75 ;
goto V_74;
}
F_109 ( V_196 , V_191 ) ;
F_5 ( & V_9 ) ;
F_45 ( & V_5 -> V_14 , & V_191 -> V_15 ) ;
F_111 ( V_5 , V_191 ) ;
V_5 -> V_4 = V_191 ;
V_44 . V_75 = V_5 -> V_75 ;
F_8 ( & V_9 ) ;
F_110 ( V_196 , V_191 ) ;
V_74:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
V_197:
F_114 ( V_195 ) ;
return V_49 ;
}
static T_1 F_115 ( struct V_4 * V_67 , const char T_2 * V_198 ,
T_3 V_199 , T_4 * V_200 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
struct V_201 V_202 ;
T_1 V_49 ;
if ( V_199 < sizeof( V_202 ) )
return - V_8 ;
if ( F_28 ( & V_202 , V_198 , sizeof( V_202 ) ) )
return - V_66 ;
if ( V_202 . V_64 >= F_116 ( V_203 ) )
return - V_8 ;
if ( V_202 . V_204 + sizeof( V_202 ) > V_199 )
return - V_8 ;
if ( ! V_203 [ V_202 . V_64 ] )
return - V_153 ;
V_49 = V_203 [ V_202 . V_64 ] ( V_4 , V_198 + sizeof( V_202 ) , V_202 . V_204 , V_202 . V_57 ) ;
if ( ! V_49 )
V_49 = V_199 ;
return V_49 ;
}
static unsigned int F_117 ( struct V_4 * V_67 , struct V_205 * V_206 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
unsigned int V_207 = 0 ;
V_59 ( V_67 , & V_4 -> V_59 , V_206 ) ;
if ( ! F_29 ( & V_4 -> V_58 ) )
V_207 = V_208 | V_209 ;
return V_207 ;
}
static int F_118 ( struct V_210 * V_210 , struct V_4 * V_67 )
{
struct V_3 * V_4 ;
V_4 = F_119 ( sizeof *V_4 , V_12 ) ;
if ( ! V_4 )
return - V_56 ;
F_16 ( & V_4 -> V_58 ) ;
F_16 ( & V_4 -> V_15 ) ;
F_120 ( & V_4 -> V_59 ) ;
F_121 ( & V_4 -> V_9 ) ;
V_67 -> V_24 = V_4 ;
V_4 -> V_67 = V_67 ;
return F_122 ( V_210 , V_67 ) ;
}
static int F_123 ( struct V_210 * V_210 , struct V_4 * V_67 )
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
static T_1 F_124 ( struct V_121 * V_211 ,
struct V_212 * V_213 ,
char * V_198 )
{
return sprintf ( V_198 , L_1 , V_214 ) ;
}
static int T_5 F_125 ( void )
{
int V_49 ;
V_49 = F_126 ( & V_215 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_127 ( V_215 . V_216 , & V_217 ) ;
if ( V_49 ) {
F_128 ( V_218 L_2 ) ;
goto V_85;
}
V_219 = F_129 ( & V_220 , L_3 , V_221 ) ;
if ( ! V_219 ) {
F_128 ( V_218 L_4 ) ;
V_49 = - V_56 ;
goto V_86;
}
return 0 ;
V_86:
F_130 ( V_215 . V_216 , & V_217 ) ;
V_85:
F_131 ( & V_215 ) ;
return V_49 ;
}
static void T_6 F_132 ( void )
{
F_133 ( V_219 ) ;
F_130 ( V_215 . V_216 , & V_217 ) ;
F_131 ( & V_215 ) ;
F_134 ( & V_6 ) ;
}
