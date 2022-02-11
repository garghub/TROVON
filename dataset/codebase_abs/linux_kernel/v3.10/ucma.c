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
} else if ( ! V_5 -> V_45 ) {
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
static T_1 F_50 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_93 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_51 ( V_5 -> V_47 , (struct V_91 * ) & V_64 . V_94 ,
(struct V_91 * ) & V_64 . V_95 ,
V_64 . V_96 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_52 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_97 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_53 ( V_5 -> V_47 , V_64 . V_96 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_54 ( struct V_98 * V_44 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
V_44 -> V_103 = V_100 -> V_103 ;
switch ( V_100 -> V_103 ) {
case 0 :
V_102 = & V_100 -> V_92 . V_102 ;
F_55 ( V_102 ,
(union V_104 * ) & V_44 -> V_105 [ 0 ] . V_106 ) ;
F_56 ( V_102 ,
(union V_104 * ) & V_44 -> V_105 [ 0 ] . V_107 ) ;
V_44 -> V_105 [ 0 ] . V_108 = F_57 ( F_58 ( V_102 ) ) ;
break;
case 2 :
F_59 ( & V_44 -> V_105 [ 1 ] ,
& V_100 -> V_109 [ 1 ] ) ;
case 1 :
F_59 ( & V_44 -> V_105 [ 0 ] ,
& V_100 -> V_109 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_60 ( struct V_98 * V_44 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
struct V_110 * V_111 ;
T_3 V_112 = 0 ;
V_44 -> V_103 = V_100 -> V_103 ;
switch ( V_100 -> V_103 ) {
case 0 :
V_102 = & V_100 -> V_92 . V_102 ;
V_111 = F_61 ( & V_113 , V_102 -> V_114 ) ;
if ( V_111 ) {
V_112 = F_62 ( V_111 ) ;
F_63 ( V_111 ) ;
}
F_64 ( (union V_104 * ) & V_44 -> V_105 [ 0 ] . V_106 ,
V_102 -> V_115 , V_112 ) ;
F_65 ( V_102 ,
(union V_104 * ) & V_44 -> V_105 [ 0 ] . V_107 ) ;
V_44 -> V_105 [ 0 ] . V_108 = F_57 ( 0xffff ) ;
break;
case 2 :
F_59 ( & V_44 -> V_105 [ 1 ] ,
& V_100 -> V_109 [ 1 ] ) ;
case 1 :
F_59 ( & V_44 -> V_105 [ 0 ] ,
& V_100 -> V_109 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_66 ( struct V_98 * V_44 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
V_102 = & V_100 -> V_92 . V_102 ;
F_55 ( V_102 , (union V_104 * ) & V_44 -> V_105 [ 0 ] . V_106 ) ;
F_56 ( V_102 , (union V_104 * ) & V_44 -> V_105 [ 0 ] . V_107 ) ;
}
static T_1 F_67 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_116 V_64 ;
struct V_98 V_44 ;
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
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_100 . V_92 . V_94 ;
memcpy ( & V_44 . V_94 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
V_92 = (struct V_91 * ) & V_5 -> V_47 -> V_100 . V_92 . V_95 ;
memcpy ( & V_44 . V_95 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
if ( ! V_5 -> V_47 -> V_121 )
goto V_57;
V_44 . V_122 = ( V_123 V_124 ) V_5 -> V_47 -> V_121 -> V_122 ;
V_44 . V_125 = V_5 -> V_47 -> V_125 ;
switch ( F_68 ( V_5 -> V_47 -> V_121 -> V_126 ) ) {
case V_127 :
switch ( F_69 ( V_5 -> V_47 -> V_121 ,
V_5 -> V_47 -> V_125 ) ) {
case V_128 :
F_54 ( & V_44 , & V_5 -> V_47 -> V_100 ) ;
break;
case V_129 :
F_60 ( & V_44 , & V_5 -> V_47 -> V_100 ) ;
break;
default:
break;
}
break;
case V_130 :
F_66 ( & V_44 , & V_5 -> V_47 -> V_100 ) ;
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
static void F_70 ( struct V_21 * V_20 ,
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
}
static T_1 F_71 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_131 V_64 ;
struct V_21 V_132 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
if ( ! V_64 . V_132 . V_133 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_70 ( & V_132 , & V_64 . V_132 ) ;
V_49 = F_72 ( V_5 -> V_47 , & V_132 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_73 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_134 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_5 -> V_55 = V_64 . V_55 > 0 && V_64 . V_55 < V_135 ?
V_64 . V_55 : V_135 ;
V_49 = F_74 ( V_5 -> V_47 , V_5 -> V_55 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_75 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_136 V_64 ;
struct V_21 V_132 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
if ( V_64 . V_132 . V_133 ) {
F_70 ( & V_132 , & V_64 . V_132 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_49 = F_76 ( V_5 -> V_47 , & V_132 ) ;
if ( ! V_49 )
V_5 -> V_45 = V_64 . V_45 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_49 = F_76 ( V_5 -> V_47 , NULL ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_77 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_137 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_78 ( V_5 -> V_47 , V_64 . V_24 , V_64 . V_23 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_79 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_138 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_80 ( V_5 -> V_47 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_81 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_139 V_64 ;
struct V_140 V_44 ;
struct V_1 * V_5 ;
struct V_141 V_142 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_44 . V_143 = 0 ;
memset ( & V_142 , 0 , sizeof V_142 ) ;
V_142 . V_144 = V_64 . V_144 ;
V_49 = F_82 ( V_5 -> V_47 , & V_142 , & V_44 . V_143 ) ;
if ( V_49 )
goto V_57;
F_83 ( & V_44 , & V_142 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static int F_84 ( struct V_1 * V_5 , int V_145 ,
void * V_146 , T_4 V_147 )
{
int V_49 = 0 ;
switch ( V_145 ) {
case V_148 :
if ( V_147 != sizeof( V_149 ) ) {
V_49 = - V_8 ;
break;
}
F_85 ( V_5 -> V_47 , * ( ( V_149 * ) V_146 ) ) ;
break;
case V_150 :
if ( V_147 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_86 ( V_5 -> V_47 , * ( ( int * ) V_146 ) ? 1 : 0 ) ;
break;
case V_151 :
if ( V_147 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_87 ( V_5 -> V_47 , * ( ( int * ) V_146 ) ? 1 : 0 ) ;
break;
default:
V_49 = - V_152 ;
}
return V_49 ;
}
static int F_88 ( struct V_1 * V_5 ,
struct V_153 * V_154 , T_4 V_147 )
{
struct V_155 V_156 ;
struct V_36 V_37 ;
int V_49 ;
if ( V_147 % sizeof( * V_154 ) )
return - V_8 ;
for (; V_147 ; V_147 -= sizeof( * V_154 ) , V_154 ++ ) {
if ( V_154 -> V_157 == ( V_158 | V_159 |
V_160 ) )
break;
}
if ( ! V_147 )
return - V_8 ;
F_89 ( V_154 -> V_109 , & V_156 ) ;
V_49 = F_90 ( V_5 -> V_47 , & V_156 , 1 ) ;
if ( V_49 )
return V_49 ;
memset ( & V_37 , 0 , sizeof V_37 ) ;
V_37 . V_37 = V_161 ;
return F_25 ( V_5 -> V_47 , & V_37 ) ;
}
static int F_91 ( struct V_1 * V_5 , int V_145 ,
void * V_146 , T_4 V_147 )
{
int V_49 ;
switch ( V_145 ) {
case V_162 :
V_49 = F_88 ( V_5 , V_146 , V_147 ) ;
break;
default:
V_49 = - V_152 ;
}
return V_49 ;
}
static int F_92 ( struct V_1 * V_5 , int V_163 ,
int V_145 , void * V_146 , T_4 V_147 )
{
int V_49 ;
switch ( V_163 ) {
case V_164 :
V_49 = F_84 ( V_5 , V_145 , V_146 , V_147 ) ;
break;
case V_165 :
V_49 = F_91 ( V_5 , V_145 , V_146 , V_147 ) ;
break;
default:
V_49 = - V_152 ;
}
return V_49 ;
}
static T_1 F_93 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_166 V_64 ;
struct V_1 * V_5 ;
void * V_146 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_146 = F_94 ( ( void T_2 * ) ( unsigned long ) V_64 . V_146 ,
V_64 . V_147 ) ;
if ( F_6 ( V_146 ) ) {
V_49 = F_37 ( V_146 ) ;
goto V_57;
}
V_49 = F_92 ( V_5 , V_64 . V_163 , V_64 . V_145 , V_146 ,
V_64 . V_147 ) ;
F_19 ( V_146 ) ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_95 ( struct V_3 * V_4 , const char T_2 * V_60 ,
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
V_49 = F_96 ( V_5 -> V_47 , (enum V_168 ) V_64 . V_37 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_97 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_169 V_64 ;
struct V_84 V_44 ;
struct V_1 * V_5 ;
struct V_16 * V_17 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_17 = F_20 ( V_5 ) ;
if ( ! V_17 ) {
V_49 = - V_56 ;
goto V_85;
}
V_17 -> V_45 = V_64 . V_45 ;
memcpy ( & V_17 -> V_92 , & V_64 . V_92 , sizeof V_64 . V_92 ) ;
V_49 = F_98 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 , V_17 ) ;
if ( V_49 )
goto V_86;
V_44 . V_2 = V_17 -> V_2 ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) ) {
V_49 = - V_66 ;
goto V_170;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_170:
F_99 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static T_1 F_100 ( struct V_3 * V_4 ,
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
F_99 ( V_17 -> V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static void F_101 ( struct V_3 * V_171 , struct V_3 * V_172 )
{
if ( V_171 < V_172 ) {
F_5 ( & V_171 -> V_9 ) ;
F_5 ( & V_172 -> V_9 ) ;
} else {
F_5 ( & V_172 -> V_9 ) ;
F_5 ( & V_171 -> V_9 ) ;
}
}
static void F_102 ( struct V_3 * V_171 , struct V_3 * V_172 )
{
if ( V_171 < V_172 ) {
F_8 ( & V_172 -> V_9 ) ;
F_8 ( & V_171 -> V_9 ) ;
} else {
F_8 ( & V_171 -> V_9 ) ;
F_8 ( & V_172 -> V_9 ) ;
}
}
static void F_103 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_38 * V_39 , * V_87 ;
F_41 (uevent, tmp, &ctx->file->event_list, list)
if ( V_39 -> V_5 == V_5 )
F_45 ( & V_39 -> V_14 , & V_4 -> V_58 ) ;
}
static T_1 F_104 ( struct V_3 * V_173 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_174 V_64 ;
struct V_175 V_44 ;
struct V_1 * V_5 ;
struct V_176 V_177 ;
struct V_3 * V_178 ;
int V_49 = 0 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_177 = F_105 ( V_64 . V_176 ) ;
if ( ! V_177 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_177 . V_4 -> V_24 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_49 = F_37 ( V_5 ) ;
goto V_179;
}
V_178 = V_5 -> V_4 ;
if ( V_178 == V_173 ) {
V_44 . V_75 = V_5 -> V_75 ;
goto V_74;
}
F_101 ( V_178 , V_173 ) ;
F_5 ( & V_9 ) ;
F_45 ( & V_5 -> V_14 , & V_173 -> V_15 ) ;
F_103 ( V_5 , V_173 ) ;
V_5 -> V_4 = V_173 ;
V_44 . V_75 = V_5 -> V_75 ;
F_8 ( & V_9 ) ;
F_102 ( V_178 , V_173 ) ;
V_74:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
V_179:
F_106 ( V_177 ) ;
return V_49 ;
}
static T_1 F_107 ( struct V_4 * V_67 , const char T_2 * V_180 ,
T_4 V_181 , T_5 * V_182 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
struct V_183 V_184 ;
T_1 V_49 ;
if ( V_181 < sizeof( V_184 ) )
return - V_8 ;
if ( F_28 ( & V_184 , V_180 , sizeof( V_184 ) ) )
return - V_66 ;
if ( V_184 . V_64 >= F_108 ( V_185 ) )
return - V_8 ;
if ( V_184 . V_186 + sizeof( V_184 ) > V_181 )
return - V_8 ;
if ( ! V_185 [ V_184 . V_64 ] )
return - V_152 ;
V_49 = V_185 [ V_184 . V_64 ] ( V_4 , V_180 + sizeof( V_184 ) , V_184 . V_186 , V_184 . V_57 ) ;
if ( ! V_49 )
V_49 = V_181 ;
return V_49 ;
}
static unsigned int F_109 ( struct V_4 * V_67 , struct V_187 * V_188 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
unsigned int V_189 = 0 ;
V_59 ( V_67 , & V_4 -> V_59 , V_188 ) ;
if ( ! F_29 ( & V_4 -> V_58 ) )
V_189 = V_190 | V_191 ;
return V_189 ;
}
static int F_110 ( struct V_192 * V_192 , struct V_4 * V_67 )
{
struct V_3 * V_4 ;
V_4 = F_111 ( sizeof *V_4 , V_12 ) ;
if ( ! V_4 )
return - V_56 ;
F_16 ( & V_4 -> V_58 ) ;
F_16 ( & V_4 -> V_15 ) ;
F_112 ( & V_4 -> V_59 ) ;
F_113 ( & V_4 -> V_9 ) ;
V_67 -> V_24 = V_4 ;
V_4 -> V_67 = V_67 ;
return F_114 ( V_192 , V_67 ) ;
}
static int F_115 ( struct V_192 * V_192 , struct V_4 * V_67 )
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
static T_1 F_116 ( struct V_121 * V_111 ,
struct V_193 * V_194 ,
char * V_180 )
{
return sprintf ( V_180 , L_1 , V_195 ) ;
}
static int T_6 F_117 ( void )
{
int V_49 ;
V_49 = F_118 ( & V_196 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_119 ( V_196 . V_197 , & V_198 ) ;
if ( V_49 ) {
F_120 ( V_199 L_2 ) ;
goto V_85;
}
V_200 = F_121 ( & V_113 , L_3 , V_201 ) ;
if ( ! V_200 ) {
F_120 ( V_199 L_4 ) ;
V_49 = - V_56 ;
goto V_86;
}
return 0 ;
V_86:
F_122 ( V_196 . V_197 , & V_198 ) ;
V_85:
F_123 ( & V_196 ) ;
return V_49 ;
}
static void T_7 F_124 ( void )
{
F_125 ( V_200 ) ;
F_122 ( V_196 . V_197 , & V_198 ) ;
F_123 ( & V_196 ) ;
F_126 ( & V_6 ) ;
}
