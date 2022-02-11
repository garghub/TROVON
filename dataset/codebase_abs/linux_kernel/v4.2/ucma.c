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
if ( F_67 ( V_5 -> V_47 -> V_121 , V_5 -> V_47 -> V_125 ) )
F_57 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
else if ( F_68 ( V_5 -> V_47 -> V_121 , V_5 -> V_47 -> V_125 ) )
F_63 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
else if ( F_69 ( V_5 -> V_47 -> V_121 , V_5 -> V_47 -> V_125 ) )
F_65 ( & V_44 , & V_5 -> V_47 -> V_106 ) ;
V_57:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_70 ( struct V_46 * V_47 ,
struct V_126 * V_44 )
{
if ( ! V_47 -> V_121 )
return;
V_44 -> V_122 = ( V_123 V_124 ) V_47 -> V_121 -> V_122 ;
V_44 -> V_125 = V_47 -> V_125 ;
V_44 -> V_114 = ( V_123 V_127 ) F_60 (
F_61 ( & V_47 -> V_106 . V_92 . V_108 ) ) ;
}
static T_1 F_71 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_126 V_44 ;
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
F_70 ( V_5 -> V_47 , & V_44 ) ;
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_72 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_128 * V_44 ;
int V_129 , V_49 = 0 ;
if ( V_62 < sizeof( * V_44 ) )
return - V_65 ;
V_44 = F_13 ( V_62 , V_12 ) ;
if ( ! V_44 )
return - V_56 ;
V_44 -> V_109 = V_5 -> V_47 -> V_106 . V_109 ;
for ( V_129 = 0 , V_62 -= sizeof( * V_44 ) ;
V_129 < V_44 -> V_109 && V_62 > sizeof( struct V_130 ) ;
V_129 ++ , V_62 -= sizeof( struct V_130 ) ) {
V_44 -> V_131 [ V_129 ] . V_132 = V_133 | V_134 |
V_135 ;
F_73 ( & V_5 -> V_47 -> V_106 . V_115 [ V_129 ] ,
& V_44 -> V_131 [ V_129 ] . V_115 ) ;
}
if ( F_32 ( V_74 , V_44 ,
sizeof( * V_44 ) + ( V_129 * sizeof( struct V_130 ) ) ) )
V_49 = - V_66 ;
F_19 ( V_44 ) ;
return V_49 ;
}
static T_1 F_74 ( struct V_1 * V_5 ,
void T_2 * V_74 , int V_62 )
{
struct V_126 V_44 ;
struct V_136 * V_92 ;
int V_49 = 0 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
memset ( & V_44 , 0 , sizeof V_44 ) ;
F_70 ( V_5 -> V_47 , & V_44 ) ;
V_92 = (struct V_136 * ) & V_44 . V_97 ;
V_44 . V_101 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_97 . V_137 == V_138 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_97 , V_44 . V_101 ) ;
} else {
V_92 -> V_139 = V_138 ;
V_92 -> V_140 = ( V_123 V_141 ) V_44 . V_114 ;
F_59 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_142 ) ;
V_92 -> V_143 = F_75 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_97 ) ;
}
V_92 = (struct V_136 * ) & V_44 . V_98 ;
V_44 . V_102 = sizeof( * V_92 ) ;
if ( V_5 -> V_47 -> V_106 . V_92 . V_98 . V_137 == V_138 ) {
memcpy ( V_92 , & V_5 -> V_47 -> V_106 . V_92 . V_98 , V_44 . V_102 ) ;
} else {
V_92 -> V_139 = V_138 ;
V_92 -> V_140 = ( V_123 V_141 ) V_44 . V_114 ;
F_58 ( & V_5 -> V_47 -> V_106 . V_92 . V_108 ,
(union V_110 * ) & V_92 -> V_142 ) ;
V_92 -> V_143 = F_75 ( V_5 -> V_47 , (struct V_91 * )
& V_5 -> V_47 -> V_106 . V_92 . V_98 ) ;
}
if ( F_32 ( V_74 , & V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
return V_49 ;
}
static T_1 F_76 ( struct V_3 * V_4 ,
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
switch ( V_64 . V_144 ) {
case V_145 :
V_49 = F_71 ( V_5 , V_74 , V_62 ) ;
break;
case V_146 :
V_49 = F_72 ( V_5 , V_74 , V_62 ) ;
break;
case V_147 :
V_49 = F_74 ( V_5 , V_74 , V_62 ) ;
break;
default:
V_49 = - V_148 ;
break;
}
F_9 ( V_5 ) ;
return V_49 ;
}
static void F_77 ( struct V_46 * V_2 ,
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
V_20 -> V_35 = ( V_2 -> V_106 . V_92 . V_97 . V_137 == V_138 ) ? V_22 -> V_35 : 0 ;
}
static T_1 F_78 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_149 V_64 ;
struct V_21 V_150 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
if ( ! V_64 . V_150 . V_151 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
F_77 ( V_5 -> V_47 , & V_150 , & V_64 . V_150 ) ;
V_49 = F_79 ( V_5 -> V_47 , & V_150 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_80 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_152 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_5 -> V_55 = V_64 . V_55 > 0 && V_64 . V_55 < V_153 ?
V_64 . V_55 : V_153 ;
V_49 = F_81 ( V_5 -> V_47 , V_5 -> V_55 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_82 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_154 V_64 ;
struct V_21 V_150 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
if ( V_64 . V_150 . V_151 ) {
F_77 ( V_5 -> V_47 , & V_150 , & V_64 . V_150 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_49 = F_83 ( V_5 -> V_47 , & V_150 ) ;
if ( ! V_49 )
V_5 -> V_45 = V_64 . V_45 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_49 = F_83 ( V_5 -> V_47 , NULL ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_84 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_155 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_85 ( V_5 -> V_47 , V_64 . V_24 , V_64 . V_23 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_86 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_156 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_87 ( V_5 -> V_47 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_88 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_157 V_64 ;
struct V_158 V_44 ;
struct V_1 * V_5 ;
struct V_159 V_160 ;
int V_49 ;
if ( V_62 < sizeof( V_44 ) )
return - V_65 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_44 . V_161 = 0 ;
memset ( & V_160 , 0 , sizeof V_160 ) ;
V_160 . V_162 = V_64 . V_162 ;
V_49 = F_89 ( V_5 -> V_47 , & V_160 , & V_44 . V_161 ) ;
if ( V_49 )
goto V_57;
F_90 ( & V_44 , & V_160 ) ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static int F_91 ( struct V_1 * V_5 , int V_163 ,
void * V_164 , T_3 V_165 )
{
int V_49 = 0 ;
switch ( V_163 ) {
case V_166 :
if ( V_165 != sizeof( V_167 ) ) {
V_49 = - V_8 ;
break;
}
F_92 ( V_5 -> V_47 , * ( ( V_167 * ) V_164 ) ) ;
break;
case V_168 :
if ( V_165 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_93 ( V_5 -> V_47 , * ( ( int * ) V_164 ) ? 1 : 0 ) ;
break;
case V_169 :
if ( V_165 != sizeof( int ) ) {
V_49 = - V_8 ;
break;
}
V_49 = F_94 ( V_5 -> V_47 , * ( ( int * ) V_164 ) ? 1 : 0 ) ;
break;
default:
V_49 = - V_148 ;
}
return V_49 ;
}
static int F_95 ( struct V_1 * V_5 ,
struct V_130 * V_131 , T_3 V_165 )
{
struct V_170 V_171 ;
struct V_36 V_37 ;
int V_49 ;
if ( V_165 % sizeof( * V_131 ) )
return - V_8 ;
for (; V_165 ; V_165 -= sizeof( * V_131 ) , V_131 ++ ) {
if ( V_131 -> V_132 == ( V_133 | V_134 |
V_135 ) )
break;
}
if ( ! V_165 )
return - V_8 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_172 = 0xffff ;
F_96 ( V_131 -> V_115 , & V_171 ) ;
V_49 = F_97 ( V_5 -> V_47 , & V_171 , 1 ) ;
if ( V_49 )
return V_49 ;
memset ( & V_37 , 0 , sizeof V_37 ) ;
V_37 . V_37 = V_173 ;
return F_25 ( V_5 -> V_47 , & V_37 ) ;
}
static int F_98 ( struct V_1 * V_5 , int V_163 ,
void * V_164 , T_3 V_165 )
{
int V_49 ;
switch ( V_163 ) {
case V_174 :
V_49 = F_95 ( V_5 , V_164 , V_165 ) ;
break;
default:
V_49 = - V_148 ;
}
return V_49 ;
}
static int F_99 ( struct V_1 * V_5 , int V_175 ,
int V_163 , void * V_164 , T_3 V_165 )
{
int V_49 ;
switch ( V_175 ) {
case V_176 :
V_49 = F_91 ( V_5 , V_163 , V_164 , V_165 ) ;
break;
case V_177 :
V_49 = F_98 ( V_5 , V_163 , V_164 , V_165 ) ;
break;
default:
V_49 = - V_148 ;
}
return V_49 ;
}
static T_1 F_100 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_178 V_64 ;
struct V_1 * V_5 ;
void * V_164 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_164 = F_101 ( ( void T_2 * ) ( unsigned long ) V_64 . V_164 ,
V_64 . V_165 ) ;
if ( F_6 ( V_164 ) ) {
V_49 = F_37 ( V_164 ) ;
goto V_57;
}
V_49 = F_99 ( V_5 , V_64 . V_175 , V_64 . V_163 , V_164 ,
V_64 . V_165 ) ;
F_19 ( V_164 ) ;
V_57:
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_102 ( struct V_3 * V_4 , const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_179 V_64 ;
struct V_1 * V_5 ;
int V_49 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_5 = F_4 ( V_4 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_37 ( V_5 ) ;
V_49 = F_103 ( V_5 -> V_47 , (enum V_180 ) V_64 . V_37 ) ;
F_9 ( V_5 ) ;
return V_49 ;
}
static T_1 F_104 ( struct V_3 * V_4 ,
struct V_181 * V_64 , int V_62 )
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
V_49 = F_105 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 , V_17 ) ;
if ( V_49 )
goto V_86;
V_44 . V_2 = V_17 -> V_2 ;
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 -> V_74 ,
& V_44 , sizeof( V_44 ) ) ) {
V_49 = - V_66 ;
goto V_182;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_182:
F_106 ( V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static T_1 F_107 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_183 V_64 ;
struct V_181 V_184 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_184 . V_74 = V_64 . V_74 ;
V_184 . V_45 = V_64 . V_45 ;
V_184 . V_2 = V_64 . V_2 ;
V_184 . V_95 = F_51 ( (struct V_91 * ) & V_64 . V_92 ) ;
V_184 . V_94 = 0 ;
memcpy ( & V_184 . V_92 , & V_64 . V_92 , V_184 . V_95 ) ;
return F_104 ( V_4 , & V_184 , V_62 ) ;
}
static T_1 F_108 ( struct V_3 * V_4 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_181 V_64 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
return F_104 ( V_4 , & V_64 , V_62 ) ;
}
static T_1 F_109 ( struct V_3 * V_4 ,
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
F_106 ( V_17 -> V_5 -> V_47 , (struct V_91 * ) & V_17 -> V_92 ) ;
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
static void F_110 ( struct V_3 * V_185 , struct V_3 * V_186 )
{
if ( V_185 < V_186 ) {
F_5 ( & V_185 -> V_9 ) ;
F_111 ( & V_186 -> V_9 , V_187 ) ;
} else {
F_5 ( & V_186 -> V_9 ) ;
F_111 ( & V_185 -> V_9 , V_187 ) ;
}
}
static void F_112 ( struct V_3 * V_185 , struct V_3 * V_186 )
{
if ( V_185 < V_186 ) {
F_8 ( & V_186 -> V_9 ) ;
F_8 ( & V_185 -> V_9 ) ;
} else {
F_8 ( & V_185 -> V_9 ) ;
F_8 ( & V_186 -> V_9 ) ;
}
}
static void F_113 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_38 * V_39 , * V_87 ;
F_41 (uevent, tmp, &ctx->file->event_list, list)
if ( V_39 -> V_5 == V_5 )
F_45 ( & V_39 -> V_14 , & V_4 -> V_58 ) ;
}
static T_1 F_114 ( struct V_3 * V_188 ,
const char T_2 * V_60 ,
int V_61 , int V_62 )
{
struct V_189 V_64 ;
struct V_190 V_44 ;
struct V_1 * V_5 ;
struct V_191 V_192 ;
struct V_3 * V_193 ;
int V_49 = 0 ;
if ( F_28 ( & V_64 , V_60 , sizeof( V_64 ) ) )
return - V_66 ;
V_192 = F_115 ( V_64 . V_191 ) ;
if ( ! V_192 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_192 . V_4 -> V_24 , V_64 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_49 = F_37 ( V_5 ) ;
goto V_194;
}
V_193 = V_5 -> V_4 ;
if ( V_193 == V_188 ) {
V_44 . V_75 = V_5 -> V_75 ;
goto V_74;
}
F_110 ( V_193 , V_188 ) ;
F_5 ( & V_9 ) ;
F_45 ( & V_5 -> V_14 , & V_188 -> V_15 ) ;
F_113 ( V_5 , V_188 ) ;
V_5 -> V_4 = V_188 ;
V_44 . V_75 = V_5 -> V_75 ;
F_8 ( & V_9 ) ;
F_112 ( V_193 , V_188 ) ;
V_74:
if ( F_32 ( ( void T_2 * ) ( unsigned long ) V_64 . V_74 ,
& V_44 , sizeof( V_44 ) ) )
V_49 = - V_66 ;
F_9 ( V_5 ) ;
V_194:
F_116 ( V_192 ) ;
return V_49 ;
}
static T_1 F_117 ( struct V_4 * V_67 , const char T_2 * V_195 ,
T_3 V_196 , T_4 * V_197 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
struct V_198 V_199 ;
T_1 V_49 ;
if ( V_196 < sizeof( V_199 ) )
return - V_8 ;
if ( F_28 ( & V_199 , V_195 , sizeof( V_199 ) ) )
return - V_66 ;
if ( V_199 . V_64 >= F_118 ( V_200 ) )
return - V_8 ;
if ( V_199 . V_201 + sizeof( V_199 ) > V_196 )
return - V_8 ;
if ( ! V_200 [ V_199 . V_64 ] )
return - V_148 ;
V_49 = V_200 [ V_199 . V_64 ] ( V_4 , V_195 + sizeof( V_199 ) , V_199 . V_201 , V_199 . V_57 ) ;
if ( ! V_49 )
V_49 = V_196 ;
return V_49 ;
}
static unsigned int F_119 ( struct V_4 * V_67 , struct V_202 * V_203 )
{
struct V_3 * V_4 = V_67 -> V_24 ;
unsigned int V_204 = 0 ;
V_59 ( V_67 , & V_4 -> V_59 , V_203 ) ;
if ( ! F_29 ( & V_4 -> V_58 ) )
V_204 = V_205 | V_206 ;
return V_204 ;
}
static int F_120 ( struct V_207 * V_207 , struct V_4 * V_67 )
{
struct V_3 * V_4 ;
V_4 = F_121 ( sizeof *V_4 , V_12 ) ;
if ( ! V_4 )
return - V_56 ;
F_16 ( & V_4 -> V_58 ) ;
F_16 ( & V_4 -> V_15 ) ;
F_122 ( & V_4 -> V_59 ) ;
F_123 ( & V_4 -> V_9 ) ;
V_67 -> V_24 = V_4 ;
V_4 -> V_67 = V_67 ;
return F_124 ( V_207 , V_67 ) ;
}
static int F_125 ( struct V_207 * V_207 , struct V_4 * V_67 )
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
static T_1 F_126 ( struct V_121 * V_208 ,
struct V_209 * V_210 ,
char * V_195 )
{
return sprintf ( V_195 , L_1 , V_211 ) ;
}
static int T_5 F_127 ( void )
{
int V_49 ;
V_49 = F_128 ( & V_212 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_129 ( V_212 . V_213 , & V_214 ) ;
if ( V_49 ) {
F_130 ( V_215 L_2 ) ;
goto V_85;
}
V_216 = F_131 ( & V_217 , L_3 , V_218 ) ;
if ( ! V_216 ) {
F_130 ( V_215 L_4 ) ;
V_49 = - V_56 ;
goto V_86;
}
return 0 ;
V_86:
F_132 ( V_212 . V_213 , & V_214 ) ;
V_85:
F_133 ( & V_212 ) ;
return V_49 ;
}
static void T_6 F_134 ( void )
{
F_135 ( V_216 ) ;
F_132 ( V_212 . V_213 , & V_214 ) ;
F_133 ( & V_212 ) ;
F_136 ( & V_6 ) ;
F_136 ( & V_18 ) ;
}
