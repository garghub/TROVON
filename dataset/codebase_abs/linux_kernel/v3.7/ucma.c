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
int V_12 ;
V_5 = F_13 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return NULL ;
F_14 ( & V_5 -> V_10 , 1 ) ;
F_15 ( & V_5 -> V_11 ) ;
F_16 ( & V_5 -> V_14 ) ;
V_5 -> V_4 = V_4 ;
do {
V_12 = F_17 ( & V_6 , V_13 ) ;
if ( ! V_12 )
goto error;
F_5 ( & V_9 ) ;
V_12 = F_18 ( & V_6 , V_5 , & V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
} while ( V_12 == - V_15 );
if ( V_12 )
goto error;
F_19 ( & V_5 -> V_16 , & V_4 -> V_17 ) ;
return V_5 ;
error:
F_20 ( V_5 ) ;
return NULL ;
}
static struct V_18 * F_21 ( struct V_1 * V_5 )
{
struct V_18 * V_19 ;
int V_12 ;
V_19 = F_13 ( sizeof( * V_19 ) , V_13 ) ;
if ( ! V_19 )
return NULL ;
do {
V_12 = F_17 ( & V_20 , V_13 ) ;
if ( ! V_12 )
goto error;
F_5 ( & V_9 ) ;
V_12 = F_18 ( & V_20 , V_19 , & V_19 -> V_2 ) ;
F_8 ( & V_9 ) ;
} while ( V_12 == - V_15 );
if ( V_12 )
goto error;
V_19 -> V_5 = V_5 ;
F_19 ( & V_19 -> V_16 , & V_5 -> V_14 ) ;
return V_19 ;
error:
F_20 ( V_19 ) ;
return NULL ;
}
static void F_22 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
if ( V_24 -> V_25 )
memcpy ( V_22 -> V_26 , V_24 -> V_26 ,
V_24 -> V_25 ) ;
V_22 -> V_25 = V_24 -> V_25 ;
V_22 -> V_27 = V_24 -> V_27 ;
V_22 -> V_28 = V_24 -> V_28 ;
V_22 -> V_29 = V_24 -> V_29 ;
V_22 -> V_30 = V_24 -> V_30 ;
V_22 -> V_31 = V_24 -> V_31 ;
V_22 -> V_32 = V_24 -> V_32 ;
V_22 -> V_33 = V_24 -> V_33 ;
}
static void F_23 ( struct V_34 * V_22 ,
struct V_35 * V_24 )
{
if ( V_24 -> V_25 )
memcpy ( V_22 -> V_26 , V_24 -> V_26 ,
V_24 -> V_25 ) ;
V_22 -> V_25 = V_24 -> V_25 ;
F_24 ( & V_22 -> V_36 , & V_24 -> V_36 ) ;
V_22 -> V_33 = V_24 -> V_33 ;
V_22 -> V_37 = V_24 -> V_37 ;
}
static void F_25 ( struct V_1 * V_5 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
V_41 -> V_5 = V_5 ;
switch ( V_39 -> V_39 ) {
case V_42 :
case V_43 :
V_41 -> V_19 = (struct V_18 * )
V_39 -> V_44 . V_45 . V_26 ;
V_41 -> V_46 . V_47 = V_41 -> V_19 -> V_47 ;
V_41 -> V_46 . V_2 = V_41 -> V_19 -> V_2 ;
break;
default:
V_41 -> V_46 . V_47 = V_5 -> V_47 ;
V_41 -> V_46 . V_2 = V_5 -> V_2 ;
break;
}
}
static int F_26 ( struct V_48 * V_49 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_5 = V_49 -> V_50 ;
int V_12 = 0 ;
V_41 = F_13 ( sizeof( * V_41 ) , V_13 ) ;
if ( ! V_41 )
return V_39 -> V_39 == V_51 ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
V_41 -> V_49 = V_49 ;
F_25 ( V_5 , V_39 , V_41 ) ;
V_41 -> V_46 . V_39 = V_39 -> V_39 ;
V_41 -> V_46 . V_52 = V_39 -> V_52 ;
if ( V_49 -> V_53 == V_54 )
F_23 ( & V_41 -> V_46 . V_44 . V_45 , & V_39 -> V_44 . V_45 ) ;
else
F_22 ( & V_41 -> V_46 . V_44 . V_55 ,
& V_39 -> V_44 . V_55 ) ;
if ( V_39 -> V_39 == V_51 ) {
if ( ! V_5 -> V_56 ) {
V_12 = - V_57 ;
F_20 ( V_41 ) ;
goto V_58;
}
V_5 -> V_56 -- ;
} else if ( ! V_5 -> V_47 ) {
F_20 ( V_41 ) ;
goto V_58;
}
F_19 ( & V_41 -> V_16 , & V_5 -> V_4 -> V_59 ) ;
F_27 ( & V_5 -> V_4 -> V_60 ) ;
V_58:
F_8 ( & V_5 -> V_4 -> V_9 ) ;
return V_12 ;
}
static T_1 F_28 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_1 * V_5 ;
struct V_64 V_65 ;
struct V_40 * V_41 ;
int V_12 = 0 ;
if ( V_63 < sizeof V_41 -> V_46 )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_30 ( & V_4 -> V_59 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_68 -> V_69 & V_70 )
return - V_15 ;
if ( F_31 ( V_4 -> V_60 ,
! F_30 ( & V_4 -> V_59 ) ) )
return - V_71 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_41 = F_32 ( V_4 -> V_59 . V_72 , struct V_40 , V_16 ) ;
if ( V_41 -> V_46 . V_39 == V_51 ) {
V_5 = F_12 ( V_4 ) ;
if ( ! V_5 ) {
V_12 = - V_57 ;
goto V_73;
}
V_41 -> V_5 -> V_56 ++ ;
V_5 -> V_49 = V_41 -> V_49 ;
V_5 -> V_49 -> V_50 = V_5 ;
V_41 -> V_46 . V_2 = V_5 -> V_2 ;
}
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_41 -> V_46 , sizeof V_41 -> V_46 ) ) {
V_12 = - V_67 ;
goto V_73;
}
F_34 ( & V_41 -> V_16 ) ;
V_41 -> V_5 -> V_75 ++ ;
if ( V_41 -> V_19 )
V_41 -> V_19 -> V_75 ++ ;
F_20 ( V_41 ) ;
V_73:
F_8 ( & V_4 -> V_9 ) ;
return V_12 ;
}
static int F_35 ( struct V_76 * V_65 , enum V_77 * V_53 )
{
switch ( V_65 -> V_78 ) {
case V_79 :
* V_53 = V_80 ;
return 0 ;
case V_81 :
case V_82 :
* V_53 = V_54 ;
return 0 ;
case V_83 :
* V_53 = V_65 -> V_53 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_36 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_76 V_65 ;
struct V_84 V_46 ;
struct V_1 * V_5 ;
enum V_77 V_53 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_12 = F_35 ( & V_65 , & V_53 ) ;
if ( V_12 )
return V_12 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_12 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_57 ;
V_5 -> V_47 = V_65 . V_47 ;
V_5 -> V_49 = F_37 ( F_26 , V_5 , V_65 . V_78 , V_53 ) ;
if ( F_6 ( V_5 -> V_49 ) ) {
V_12 = F_38 ( V_5 -> V_49 ) ;
goto V_85;
}
V_46 . V_2 = V_5 -> V_2 ;
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) ) {
V_12 = - V_67 ;
goto V_86;
}
return 0 ;
V_86:
F_39 ( V_5 -> V_49 ) ;
V_85:
F_5 ( & V_9 ) ;
F_40 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_20 ( V_5 ) ;
return V_12 ;
}
static void F_41 ( struct V_1 * V_5 )
{
struct V_18 * V_19 , * V_87 ;
F_5 ( & V_9 ) ;
F_42 (mc, tmp, &ctx->mc_list, list) {
F_34 ( & V_19 -> V_16 ) ;
F_40 ( & V_20 , V_19 -> V_2 ) ;
F_20 ( V_19 ) ;
}
F_8 ( & V_9 ) ;
}
static void F_43 ( struct V_18 * V_19 )
{
struct V_40 * V_41 , * V_87 ;
F_42 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_41 -> V_19 != V_19 )
continue;
F_34 ( & V_41 -> V_16 ) ;
F_20 ( V_41 ) ;
}
}
static int F_44 ( struct V_1 * V_5 )
{
int V_75 ;
struct V_40 * V_41 , * V_87 ;
F_45 ( V_16 ) ;
F_39 ( V_5 -> V_49 ) ;
F_41 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
F_42 (uevent, tmp, &ctx->file->event_list, list) {
if ( V_41 -> V_5 == V_5 )
F_46 ( & V_41 -> V_16 , & V_16 ) ;
}
F_34 ( & V_5 -> V_16 ) ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
F_42 (uevent, tmp, &list, list) {
F_34 ( & V_41 -> V_16 ) ;
if ( V_41 -> V_46 . V_39 == V_51 )
F_39 ( V_41 -> V_49 ) ;
F_20 ( V_41 ) ;
}
V_75 = V_5 -> V_75 ;
F_20 ( V_5 ) ;
return V_75 ;
}
static T_1 F_47 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_88 V_65 ;
struct V_89 V_46 ;
struct V_1 * V_5 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_65 . V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) )
F_40 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
F_9 ( V_5 ) ;
F_48 ( & V_5 -> V_11 ) ;
V_46 . V_75 = F_44 ( V_5 ) ;
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_67 ;
return V_12 ;
}
static T_1 F_49 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_90 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_50 ( V_5 -> V_49 , (struct V_91 * ) & V_65 . V_92 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_51 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_93 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_52 ( V_5 -> V_49 , (struct V_91 * ) & V_65 . V_94 ,
(struct V_91 * ) & V_65 . V_95 ,
V_65 . V_96 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_53 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_97 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_54 ( V_5 -> V_49 , V_65 . V_96 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static void F_55 ( struct V_98 * V_46 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
V_46 -> V_103 = V_100 -> V_103 ;
switch ( V_100 -> V_103 ) {
case 0 :
V_102 = & V_100 -> V_92 . V_102 ;
F_56 ( V_102 ,
(union V_104 * ) & V_46 -> V_105 [ 0 ] . V_106 ) ;
F_57 ( V_102 ,
(union V_104 * ) & V_46 -> V_105 [ 0 ] . V_107 ) ;
V_46 -> V_105 [ 0 ] . V_108 = F_58 ( F_59 ( V_102 ) ) ;
break;
case 2 :
F_60 ( & V_46 -> V_105 [ 1 ] ,
& V_100 -> V_109 [ 1 ] ) ;
case 1 :
F_60 ( & V_46 -> V_105 [ 0 ] ,
& V_100 -> V_109 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_61 ( struct V_98 * V_46 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
struct V_110 * V_111 ;
T_3 V_112 = 0 ;
V_46 -> V_103 = V_100 -> V_103 ;
switch ( V_100 -> V_103 ) {
case 0 :
V_102 = & V_100 -> V_92 . V_102 ;
V_111 = F_62 ( & V_113 , V_102 -> V_114 ) ;
if ( V_111 ) {
V_112 = F_63 ( V_111 ) ;
F_64 ( V_111 ) ;
}
F_65 ( (union V_104 * ) & V_46 -> V_105 [ 0 ] . V_106 ,
V_102 -> V_115 , V_112 ) ;
F_66 ( V_102 ,
(union V_104 * ) & V_46 -> V_105 [ 0 ] . V_107 ) ;
V_46 -> V_105 [ 0 ] . V_108 = F_58 ( 0xffff ) ;
break;
case 2 :
F_60 ( & V_46 -> V_105 [ 1 ] ,
& V_100 -> V_109 [ 1 ] ) ;
case 1 :
F_60 ( & V_46 -> V_105 [ 0 ] ,
& V_100 -> V_109 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_67 ( struct V_98 * V_46 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
V_102 = & V_100 -> V_92 . V_102 ;
F_56 ( V_102 , (union V_104 * ) & V_46 -> V_105 [ 0 ] . V_106 ) ;
F_57 ( V_102 , (union V_104 * ) & V_46 -> V_105 [ 0 ] . V_107 ) ;
}
static T_1 F_68 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_116 V_65 ;
struct V_98 V_46 ;
struct V_1 * V_5 ;
struct V_91 * V_92 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
memset ( & V_46 , 0 , sizeof V_46 ) ;
V_92 = (struct V_91 * ) & V_5 -> V_49 -> V_100 . V_92 . V_94 ;
memcpy ( & V_46 . V_94 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
V_92 = (struct V_91 * ) & V_5 -> V_49 -> V_100 . V_92 . V_95 ;
memcpy ( & V_46 . V_95 , V_92 , V_92 -> V_117 == V_118 ?
sizeof( struct V_119 ) :
sizeof( struct V_120 ) ) ;
if ( ! V_5 -> V_49 -> V_121 )
goto V_58;
V_46 . V_122 = ( V_123 V_124 ) V_5 -> V_49 -> V_121 -> V_122 ;
V_46 . V_125 = V_5 -> V_49 -> V_125 ;
switch ( F_69 ( V_5 -> V_49 -> V_121 -> V_126 ) ) {
case V_127 :
switch ( F_70 ( V_5 -> V_49 -> V_121 ,
V_5 -> V_49 -> V_125 ) ) {
case V_128 :
F_55 ( & V_46 , & V_5 -> V_49 -> V_100 ) ;
break;
case V_129 :
F_61 ( & V_46 , & V_5 -> V_49 -> V_100 ) ;
break;
default:
break;
}
break;
case V_130 :
F_67 ( & V_46 , & V_5 -> V_49 -> V_100 ) ;
break;
default:
break;
}
V_58:
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_67 ;
F_9 ( V_5 ) ;
return V_12 ;
}
static void F_71 ( struct V_23 * V_22 ,
struct V_21 * V_24 )
{
V_22 -> V_26 = V_24 -> V_26 ;
V_22 -> V_25 = V_24 -> V_25 ;
V_22 -> V_27 = V_24 -> V_27 ;
V_22 -> V_28 = V_24 -> V_28 ;
V_22 -> V_29 = V_24 -> V_29 ;
V_22 -> V_30 = V_24 -> V_30 ;
V_22 -> V_31 = V_24 -> V_31 ;
V_22 -> V_32 = V_24 -> V_32 ;
V_22 -> V_33 = V_24 -> V_33 ;
}
static T_1 F_72 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_131 V_65 ;
struct V_23 V_132 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
if ( ! V_65 . V_132 . V_133 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
F_71 ( & V_132 , & V_65 . V_132 ) ;
V_12 = F_73 ( V_5 -> V_49 , & V_132 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_74 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_134 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_5 -> V_56 = V_65 . V_56 > 0 && V_65 . V_56 < V_135 ?
V_65 . V_56 : V_135 ;
V_12 = F_75 ( V_5 -> V_49 , V_5 -> V_56 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_76 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_136 V_65 ;
struct V_23 V_132 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
if ( V_65 . V_132 . V_133 ) {
F_71 ( & V_132 , & V_65 . V_132 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_12 = F_77 ( V_5 -> V_49 , & V_132 ) ;
if ( ! V_12 )
V_5 -> V_47 = V_65 . V_47 ;
F_8 ( & V_4 -> V_9 ) ;
} else
V_12 = F_77 ( V_5 -> V_49 , NULL ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_78 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_137 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_79 ( V_5 -> V_49 , V_65 . V_26 , V_65 . V_25 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_80 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_138 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_81 ( V_5 -> V_49 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_82 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_139 V_65 ;
struct V_140 V_46 ;
struct V_1 * V_5 ;
struct V_141 V_142 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_46 . V_143 = 0 ;
memset ( & V_142 , 0 , sizeof V_142 ) ;
V_142 . V_144 = V_65 . V_144 ;
V_12 = F_83 ( V_5 -> V_49 , & V_142 , & V_46 . V_143 ) ;
if ( V_12 )
goto V_58;
F_84 ( & V_46 , & V_142 ) ;
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_67 ;
V_58:
F_9 ( V_5 ) ;
return V_12 ;
}
static int F_85 ( struct V_1 * V_5 , int V_145 ,
void * V_146 , T_4 V_147 )
{
int V_12 = 0 ;
switch ( V_145 ) {
case V_148 :
if ( V_147 != sizeof( V_149 ) ) {
V_12 = - V_8 ;
break;
}
F_86 ( V_5 -> V_49 , * ( ( V_149 * ) V_146 ) ) ;
break;
case V_150 :
if ( V_147 != sizeof( int ) ) {
V_12 = - V_8 ;
break;
}
V_12 = F_87 ( V_5 -> V_49 , * ( ( int * ) V_146 ) ? 1 : 0 ) ;
break;
case V_151 :
if ( V_147 != sizeof( int ) ) {
V_12 = - V_8 ;
break;
}
V_12 = F_88 ( V_5 -> V_49 , * ( ( int * ) V_146 ) ? 1 : 0 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static int F_89 ( struct V_1 * V_5 ,
struct V_153 * V_154 , T_4 V_147 )
{
struct V_155 V_156 ;
struct V_38 V_39 ;
int V_12 ;
if ( V_147 % sizeof( * V_154 ) )
return - V_8 ;
for (; V_147 ; V_147 -= sizeof( * V_154 ) , V_154 ++ ) {
if ( V_154 -> V_157 == ( V_158 | V_159 |
V_160 ) )
break;
}
if ( ! V_147 )
return - V_8 ;
F_90 ( V_154 -> V_109 , & V_156 ) ;
V_12 = F_91 ( V_5 -> V_49 , & V_156 , 1 ) ;
if ( V_12 )
return V_12 ;
memset ( & V_39 , 0 , sizeof V_39 ) ;
V_39 . V_39 = V_161 ;
return F_26 ( V_5 -> V_49 , & V_39 ) ;
}
static int F_92 ( struct V_1 * V_5 , int V_145 ,
void * V_146 , T_4 V_147 )
{
int V_12 ;
switch ( V_145 ) {
case V_162 :
V_12 = F_89 ( V_5 , V_146 , V_147 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static int F_93 ( struct V_1 * V_5 , int V_163 ,
int V_145 , void * V_146 , T_4 V_147 )
{
int V_12 ;
switch ( V_163 ) {
case V_164 :
V_12 = F_85 ( V_5 , V_145 , V_146 , V_147 ) ;
break;
case V_165 :
V_12 = F_92 ( V_5 , V_145 , V_146 , V_147 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static T_1 F_94 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_166 V_65 ;
struct V_1 * V_5 ;
void * V_146 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_146 = F_95 ( ( void T_2 * ) ( unsigned long ) V_65 . V_146 ,
V_65 . V_147 ) ;
if ( F_6 ( V_146 ) ) {
V_12 = F_38 ( V_146 ) ;
goto V_58;
}
V_12 = F_93 ( V_5 , V_65 . V_163 , V_65 . V_145 , V_146 ,
V_65 . V_147 ) ;
F_20 ( V_146 ) ;
V_58:
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_96 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_167 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
V_12 = F_97 ( V_5 -> V_49 , (enum V_168 ) V_65 . V_39 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_98 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_169 V_65 ;
struct V_84 V_46 ;
struct V_1 * V_5 ;
struct V_18 * V_19 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_38 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_19 = F_21 ( V_5 ) ;
if ( ! V_19 ) {
V_12 = - V_57 ;
goto V_85;
}
V_19 -> V_47 = V_65 . V_47 ;
memcpy ( & V_19 -> V_92 , & V_65 . V_92 , sizeof V_65 . V_92 ) ;
V_12 = F_99 ( V_5 -> V_49 , (struct V_91 * ) & V_19 -> V_92 , V_19 ) ;
if ( V_12 )
goto V_86;
V_46 . V_2 = V_19 -> V_2 ;
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) ) {
V_12 = - V_67 ;
goto V_170;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_170:
F_100 ( V_5 -> V_49 , (struct V_91 * ) & V_19 -> V_92 ) ;
F_43 ( V_19 ) ;
V_86:
F_5 ( & V_9 ) ;
F_40 ( & V_20 , V_19 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_34 ( & V_19 -> V_16 ) ;
F_20 ( V_19 ) ;
V_85:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_101 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_88 V_65 ;
struct V_89 V_46 ;
struct V_18 * V_19 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_66 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
F_5 ( & V_9 ) ;
V_19 = F_2 ( & V_20 , V_65 . V_2 ) ;
if ( ! V_19 )
V_19 = F_3 ( - V_7 ) ;
else if ( V_19 -> V_5 -> V_4 != V_4 )
V_19 = F_3 ( - V_8 ) ;
else {
F_40 ( & V_20 , V_19 -> V_2 ) ;
F_7 ( & V_19 -> V_5 -> V_10 ) ;
}
F_8 ( & V_9 ) ;
if ( F_6 ( V_19 ) ) {
V_12 = F_38 ( V_19 ) ;
goto V_58;
}
F_100 ( V_19 -> V_5 -> V_49 , (struct V_91 * ) & V_19 -> V_92 ) ;
F_5 ( & V_19 -> V_5 -> V_4 -> V_9 ) ;
F_43 ( V_19 ) ;
F_34 ( & V_19 -> V_16 ) ;
F_8 ( & V_19 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_19 -> V_5 ) ;
V_46 . V_75 = V_19 -> V_75 ;
F_20 ( V_19 ) ;
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_67 ;
V_58:
return V_12 ;
}
static void F_102 ( struct V_3 * V_171 , struct V_3 * V_172 )
{
if ( V_171 < V_172 ) {
F_5 ( & V_171 -> V_9 ) ;
F_5 ( & V_172 -> V_9 ) ;
} else {
F_5 ( & V_172 -> V_9 ) ;
F_5 ( & V_171 -> V_9 ) ;
}
}
static void F_103 ( struct V_3 * V_171 , struct V_3 * V_172 )
{
if ( V_171 < V_172 ) {
F_8 ( & V_172 -> V_9 ) ;
F_8 ( & V_171 -> V_9 ) ;
} else {
F_8 ( & V_171 -> V_9 ) ;
F_8 ( & V_172 -> V_9 ) ;
}
}
static void F_104 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_40 * V_41 , * V_87 ;
F_42 (uevent, tmp, &ctx->file->event_list, list)
if ( V_41 -> V_5 == V_5 )
F_46 ( & V_41 -> V_16 , & V_4 -> V_59 ) ;
}
static T_1 F_105 ( struct V_3 * V_173 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_174 V_65 ;
struct V_175 V_46 ;
struct V_1 * V_5 ;
struct V_176 V_177 ;
struct V_3 * V_178 ;
int V_12 = 0 ;
if ( F_29 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_67 ;
V_177 = F_106 ( V_65 . V_176 ) ;
if ( ! V_177 . V_4 )
return - V_7 ;
V_5 = F_4 ( V_177 . V_4 -> V_26 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_12 = F_38 ( V_5 ) ;
goto V_179;
}
V_178 = V_5 -> V_4 ;
if ( V_178 == V_173 ) {
V_46 . V_75 = V_5 -> V_75 ;
goto V_74;
}
F_102 ( V_178 , V_173 ) ;
F_5 ( & V_9 ) ;
F_46 ( & V_5 -> V_16 , & V_173 -> V_17 ) ;
F_104 ( V_5 , V_173 ) ;
V_5 -> V_4 = V_173 ;
V_46 . V_75 = V_5 -> V_75 ;
F_8 ( & V_9 ) ;
F_103 ( V_178 , V_173 ) ;
V_74:
if ( F_33 ( ( void T_2 * ) ( unsigned long ) V_65 . V_74 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_67 ;
F_9 ( V_5 ) ;
V_179:
F_107 ( V_177 ) ;
return V_12 ;
}
static T_1 F_108 ( struct V_4 * V_68 , const char T_2 * V_180 ,
T_4 V_181 , T_5 * V_182 )
{
struct V_3 * V_4 = V_68 -> V_26 ;
struct V_183 V_184 ;
T_1 V_12 ;
if ( V_181 < sizeof( V_184 ) )
return - V_8 ;
if ( F_29 ( & V_184 , V_180 , sizeof( V_184 ) ) )
return - V_67 ;
if ( V_184 . V_65 >= F_109 ( V_185 ) )
return - V_8 ;
if ( V_184 . V_186 + sizeof( V_184 ) > V_181 )
return - V_8 ;
if ( ! V_185 [ V_184 . V_65 ] )
return - V_152 ;
V_12 = V_185 [ V_184 . V_65 ] ( V_4 , V_180 + sizeof( V_184 ) , V_184 . V_186 , V_184 . V_58 ) ;
if ( ! V_12 )
V_12 = V_181 ;
return V_12 ;
}
static unsigned int F_110 ( struct V_4 * V_68 , struct V_187 * V_188 )
{
struct V_3 * V_4 = V_68 -> V_26 ;
unsigned int V_189 = 0 ;
V_60 ( V_68 , & V_4 -> V_60 , V_188 ) ;
if ( ! F_30 ( & V_4 -> V_59 ) )
V_189 = V_190 | V_191 ;
return V_189 ;
}
static int F_111 ( struct V_192 * V_192 , struct V_4 * V_68 )
{
struct V_3 * V_4 ;
V_4 = F_112 ( sizeof *V_4 , V_13 ) ;
if ( ! V_4 )
return - V_57 ;
F_16 ( & V_4 -> V_59 ) ;
F_16 ( & V_4 -> V_17 ) ;
F_113 ( & V_4 -> V_60 ) ;
F_114 ( & V_4 -> V_9 ) ;
V_68 -> V_26 = V_4 ;
V_4 -> V_68 = V_68 ;
return F_115 ( V_192 , V_68 ) ;
}
static int F_116 ( struct V_192 * V_192 , struct V_4 * V_68 )
{
struct V_3 * V_4 = V_68 -> V_26 ;
struct V_1 * V_5 , * V_87 ;
F_5 ( & V_4 -> V_9 ) ;
F_42 (ctx, tmp, &file->ctx_list, list) {
F_8 ( & V_4 -> V_9 ) ;
F_5 ( & V_9 ) ;
F_40 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_44 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_4 -> V_9 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static T_1 F_117 ( struct V_121 * V_111 ,
struct V_193 * V_194 ,
char * V_180 )
{
return sprintf ( V_180 , L_1 , V_195 ) ;
}
static int T_6 F_118 ( void )
{
int V_12 ;
V_12 = F_119 ( & V_196 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_120 ( V_196 . V_197 , & V_198 ) ;
if ( V_12 ) {
F_121 ( V_199 L_2 ) ;
goto V_85;
}
V_200 = F_122 ( & V_113 , L_3 , V_201 ) ;
if ( ! V_200 ) {
F_121 ( V_199 L_4 ) ;
V_12 = - V_57 ;
goto V_86;
}
return 0 ;
V_86:
F_123 ( V_196 . V_197 , & V_198 ) ;
V_85:
F_124 ( & V_196 ) ;
return V_12 ;
}
static void T_7 F_125 ( void )
{
F_126 ( V_200 ) ;
F_123 ( V_196 . V_197 , & V_198 ) ;
F_124 ( & V_196 ) ;
F_127 ( & V_6 ) ;
}
