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
V_41 -> V_49 = V_49 ;
F_25 ( V_5 , V_39 , V_41 ) ;
V_41 -> V_46 . V_39 = V_39 -> V_39 ;
V_41 -> V_46 . V_52 = V_39 -> V_52 ;
if ( V_49 -> V_53 == V_54 )
F_23 ( & V_41 -> V_46 . V_44 . V_45 , & V_39 -> V_44 . V_45 ) ;
else
F_22 ( & V_41 -> V_46 . V_44 . V_55 ,
& V_39 -> V_44 . V_55 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
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
F_29 ( V_66 ) ;
if ( V_63 < sizeof V_41 -> V_46 )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
F_5 ( & V_4 -> V_9 ) ;
while ( F_31 ( & V_4 -> V_59 ) ) {
F_8 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_69 -> V_70 & V_71 )
return - V_15 ;
if ( F_32 ( V_4 -> V_60 ,
! F_31 ( & V_4 -> V_59 ) ) )
return - V_72 ;
F_5 ( & V_4 -> V_9 ) ;
}
V_41 = F_33 ( V_4 -> V_59 . V_73 , struct V_40 , V_16 ) ;
if ( V_41 -> V_46 . V_39 == V_51 ) {
V_5 = F_12 ( V_4 ) ;
if ( ! V_5 ) {
V_12 = - V_57 ;
goto V_74;
}
V_41 -> V_5 -> V_56 ++ ;
V_5 -> V_49 = V_41 -> V_49 ;
V_5 -> V_49 -> V_50 = V_5 ;
V_41 -> V_46 . V_2 = V_5 -> V_2 ;
}
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_41 -> V_46 , sizeof V_41 -> V_46 ) ) {
V_12 = - V_68 ;
goto V_74;
}
F_35 ( & V_41 -> V_16 ) ;
V_41 -> V_5 -> V_76 ++ ;
if ( V_41 -> V_19 )
V_41 -> V_19 -> V_76 ++ ;
F_20 ( V_41 ) ;
V_74:
F_8 ( & V_4 -> V_9 ) ;
return V_12 ;
}
static int F_36 ( struct V_77 * V_65 , enum V_78 * V_53 )
{
switch ( V_65 -> V_79 ) {
case V_80 :
* V_53 = V_81 ;
return 0 ;
case V_82 :
case V_83 :
* V_53 = V_54 ;
return 0 ;
case V_84 :
* V_53 = V_65 -> V_53 ;
return 0 ;
default:
return - V_8 ;
}
}
static T_1 F_37 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_77 V_65 ;
struct V_85 V_46 ;
struct V_1 * V_5 ;
enum V_78 V_53 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_12 = F_36 ( & V_65 , & V_53 ) ;
if ( V_12 )
return V_12 ;
F_5 ( & V_4 -> V_9 ) ;
V_5 = F_12 ( V_4 ) ;
F_8 ( & V_4 -> V_9 ) ;
if ( ! V_5 )
return - V_57 ;
V_5 -> V_47 = V_65 . V_47 ;
V_5 -> V_49 = F_38 ( F_26 , V_5 , V_65 . V_79 , V_53 ) ;
if ( F_6 ( V_5 -> V_49 ) ) {
V_12 = F_39 ( V_5 -> V_49 ) ;
goto V_86;
}
V_46 . V_2 = V_5 -> V_2 ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) ) {
V_12 = - V_68 ;
goto V_87;
}
return 0 ;
V_87:
F_40 ( V_5 -> V_49 ) ;
V_86:
F_5 ( & V_9 ) ;
F_41 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_20 ( V_5 ) ;
return V_12 ;
}
static void F_42 ( struct V_1 * V_5 )
{
struct V_18 * V_19 , * V_88 ;
F_5 ( & V_9 ) ;
F_43 (mc, tmp, &ctx->mc_list, list) {
F_35 ( & V_19 -> V_16 ) ;
F_41 ( & V_20 , V_19 -> V_2 ) ;
F_20 ( V_19 ) ;
}
F_8 ( & V_9 ) ;
}
static void F_44 ( struct V_1 * V_5 )
{
struct V_40 * V_41 , * V_88 ;
F_43 (uevent, tmp, &ctx->file->event_list, list) {
if ( V_41 -> V_5 != V_5 )
continue;
F_35 ( & V_41 -> V_16 ) ;
if ( V_41 -> V_46 . V_39 == V_51 )
F_40 ( V_41 -> V_49 ) ;
F_20 ( V_41 ) ;
}
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_40 * V_41 , * V_88 ;
F_43 (uevent, tmp, &mc->ctx->file->event_list, list) {
if ( V_41 -> V_19 != V_19 )
continue;
F_35 ( & V_41 -> V_16 ) ;
F_20 ( V_41 ) ;
}
}
static int F_46 ( struct V_1 * V_5 )
{
int V_76 ;
F_40 ( V_5 -> V_49 ) ;
F_42 ( V_5 ) ;
F_5 ( & V_5 -> V_4 -> V_9 ) ;
F_44 ( V_5 ) ;
F_35 ( & V_5 -> V_16 ) ;
F_8 ( & V_5 -> V_4 -> V_9 ) ;
V_76 = V_5 -> V_76 ;
F_20 ( V_5 ) ;
return V_76 ;
}
static T_1 F_47 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_89 V_65 ;
struct V_90 V_46 ;
struct V_1 * V_5 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
F_5 ( & V_9 ) ;
V_5 = F_1 ( V_65 . V_2 , V_4 ) ;
if ( ! F_6 ( V_5 ) )
F_41 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
F_9 ( V_5 ) ;
F_48 ( & V_5 -> V_11 ) ;
V_46 . V_76 = F_46 ( V_5 ) ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_68 ;
return V_12 ;
}
static T_1 F_49 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_91 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_50 ( V_5 -> V_49 , (struct V_92 * ) & V_65 . V_93 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_51 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_94 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_52 ( V_5 -> V_49 , (struct V_92 * ) & V_65 . V_95 ,
(struct V_92 * ) & V_65 . V_96 ,
V_65 . V_97 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_53 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_98 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_54 ( V_5 -> V_49 , V_65 . V_97 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static void F_55 ( struct V_99 * V_46 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
V_46 -> V_104 = V_101 -> V_104 ;
switch ( V_101 -> V_104 ) {
case 0 :
V_103 = & V_101 -> V_93 . V_103 ;
F_56 ( V_103 ,
(union V_105 * ) & V_46 -> V_106 [ 0 ] . V_107 ) ;
F_57 ( V_103 ,
(union V_105 * ) & V_46 -> V_106 [ 0 ] . V_108 ) ;
V_46 -> V_106 [ 0 ] . V_109 = F_58 ( F_59 ( V_103 ) ) ;
break;
case 2 :
F_60 ( & V_46 -> V_106 [ 1 ] ,
& V_101 -> V_110 [ 1 ] ) ;
case 1 :
F_60 ( & V_46 -> V_106 [ 0 ] ,
& V_101 -> V_110 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_61 ( struct V_99 * V_46 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
struct V_111 * V_112 ;
T_3 V_113 = 0 ;
V_46 -> V_104 = V_101 -> V_104 ;
switch ( V_101 -> V_104 ) {
case 0 :
V_103 = & V_101 -> V_93 . V_103 ;
V_112 = F_62 ( & V_114 , V_103 -> V_115 ) ;
if ( V_112 ) {
V_113 = F_63 ( V_112 ) ;
F_64 ( V_112 ) ;
}
F_65 ( (union V_105 * ) & V_46 -> V_106 [ 0 ] . V_107 ,
V_103 -> V_116 , V_113 ) ;
F_66 ( V_103 ,
(union V_105 * ) & V_46 -> V_106 [ 0 ] . V_108 ) ;
V_46 -> V_106 [ 0 ] . V_109 = F_58 ( 0xffff ) ;
break;
case 2 :
F_60 ( & V_46 -> V_106 [ 1 ] ,
& V_101 -> V_110 [ 1 ] ) ;
case 1 :
F_60 ( & V_46 -> V_106 [ 0 ] ,
& V_101 -> V_110 [ 0 ] ) ;
break;
default:
break;
}
}
static void F_67 ( struct V_99 * V_46 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
V_103 = & V_101 -> V_93 . V_103 ;
F_56 ( V_103 , (union V_105 * ) & V_46 -> V_106 [ 0 ] . V_107 ) ;
F_57 ( V_103 , (union V_105 * ) & V_46 -> V_106 [ 0 ] . V_108 ) ;
}
static T_1 F_68 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_117 V_65 ;
struct V_99 V_46 ;
struct V_1 * V_5 ;
struct V_92 * V_93 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
memset ( & V_46 , 0 , sizeof V_46 ) ;
V_93 = (struct V_92 * ) & V_5 -> V_49 -> V_101 . V_93 . V_95 ;
memcpy ( & V_46 . V_95 , V_93 , V_93 -> V_118 == V_119 ?
sizeof( struct V_120 ) :
sizeof( struct V_121 ) ) ;
V_93 = (struct V_92 * ) & V_5 -> V_49 -> V_101 . V_93 . V_96 ;
memcpy ( & V_46 . V_96 , V_93 , V_93 -> V_118 == V_119 ?
sizeof( struct V_120 ) :
sizeof( struct V_121 ) ) ;
if ( ! V_5 -> V_49 -> V_122 )
goto V_58;
V_46 . V_123 = ( V_124 V_125 ) V_5 -> V_49 -> V_122 -> V_123 ;
V_46 . V_126 = V_5 -> V_49 -> V_126 ;
switch ( F_69 ( V_5 -> V_49 -> V_122 -> V_127 ) ) {
case V_128 :
switch ( F_70 ( V_5 -> V_49 -> V_122 ,
V_5 -> V_49 -> V_126 ) ) {
case V_129 :
F_55 ( & V_46 , & V_5 -> V_49 -> V_101 ) ;
break;
case V_130 :
F_61 ( & V_46 , & V_5 -> V_49 -> V_101 ) ;
break;
default:
break;
}
break;
case V_131 :
F_67 ( & V_46 , & V_5 -> V_49 -> V_101 ) ;
break;
default:
break;
}
V_58:
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_68 ;
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
struct V_132 V_65 ;
struct V_23 V_133 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
if ( ! V_65 . V_133 . V_134 )
return - V_8 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
F_71 ( & V_133 , & V_65 . V_133 ) ;
V_12 = F_73 ( V_5 -> V_49 , & V_133 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_74 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_135 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_5 -> V_56 = V_65 . V_56 > 0 && V_65 . V_56 < V_136 ?
V_65 . V_56 : V_136 ;
V_12 = F_75 ( V_5 -> V_49 , V_5 -> V_56 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_76 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_137 V_65 ;
struct V_23 V_133 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
if ( V_65 . V_133 . V_134 ) {
F_71 ( & V_133 , & V_65 . V_133 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_12 = F_77 ( V_5 -> V_49 , & V_133 ) ;
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
struct V_138 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_79 ( V_5 -> V_49 , V_65 . V_26 , V_65 . V_25 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_80 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_139 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_81 ( V_5 -> V_49 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_82 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_140 V_65 ;
struct V_141 V_46 ;
struct V_1 * V_5 ;
struct V_142 V_143 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_46 . V_144 = 0 ;
memset ( & V_143 , 0 , sizeof V_143 ) ;
V_143 . V_145 = V_65 . V_145 ;
V_12 = F_83 ( V_5 -> V_49 , & V_143 , & V_46 . V_144 ) ;
if ( V_12 )
goto V_58;
F_84 ( & V_46 , & V_143 ) ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_68 ;
V_58:
F_9 ( V_5 ) ;
return V_12 ;
}
static int F_85 ( struct V_1 * V_5 , int V_146 ,
void * V_147 , T_4 V_148 )
{
int V_12 = 0 ;
switch ( V_146 ) {
case V_149 :
if ( V_148 != sizeof( V_150 ) ) {
V_12 = - V_8 ;
break;
}
F_86 ( V_5 -> V_49 , * ( ( V_150 * ) V_147 ) ) ;
break;
case V_151 :
if ( V_148 != sizeof( int ) ) {
V_12 = - V_8 ;
break;
}
V_12 = F_87 ( V_5 -> V_49 , * ( ( int * ) V_147 ) ? 1 : 0 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static int F_88 ( struct V_1 * V_5 ,
struct V_153 * V_154 , T_4 V_148 )
{
struct V_155 V_156 ;
struct V_38 V_39 ;
int V_12 ;
if ( V_148 % sizeof( * V_154 ) )
return - V_8 ;
for (; V_148 ; V_148 -= sizeof( * V_154 ) , V_154 ++ ) {
if ( V_154 -> V_157 == ( V_158 | V_159 |
V_160 ) )
break;
}
if ( ! V_148 )
return - V_8 ;
F_89 ( V_154 -> V_110 , & V_156 ) ;
V_12 = F_90 ( V_5 -> V_49 , & V_156 , 1 ) ;
if ( V_12 )
return V_12 ;
memset ( & V_39 , 0 , sizeof V_39 ) ;
V_39 . V_39 = V_161 ;
return F_26 ( V_5 -> V_49 , & V_39 ) ;
}
static int F_91 ( struct V_1 * V_5 , int V_146 ,
void * V_147 , T_4 V_148 )
{
int V_12 ;
switch ( V_146 ) {
case V_162 :
V_12 = F_88 ( V_5 , V_147 , V_148 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static int F_92 ( struct V_1 * V_5 , int V_163 ,
int V_146 , void * V_147 , T_4 V_148 )
{
int V_12 ;
switch ( V_163 ) {
case V_164 :
V_12 = F_85 ( V_5 , V_146 , V_147 , V_148 ) ;
break;
case V_165 :
V_12 = F_91 ( V_5 , V_146 , V_147 , V_148 ) ;
break;
default:
V_12 = - V_152 ;
}
return V_12 ;
}
static T_1 F_93 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_166 V_65 ;
struct V_1 * V_5 ;
void * V_147 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_147 = F_94 ( V_65 . V_148 , V_13 ) ;
if ( ! V_147 ) {
V_12 = - V_57 ;
goto V_167;
}
if ( F_30 ( V_147 , ( void T_2 * ) ( unsigned long ) V_65 . V_147 ,
V_65 . V_148 ) ) {
V_12 = - V_68 ;
goto V_168;
}
V_12 = F_92 ( V_5 , V_65 . V_163 , V_65 . V_146 , V_147 ,
V_65 . V_148 ) ;
V_168:
F_20 ( V_147 ) ;
V_167:
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_95 ( struct V_3 * V_4 , const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_169 V_65 ;
struct V_1 * V_5 ;
int V_12 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
V_12 = F_96 ( V_5 -> V_49 , (enum V_170 ) V_65 . V_39 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_97 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_171 V_65 ;
struct V_85 V_46 ;
struct V_1 * V_5 ;
struct V_18 * V_19 ;
int V_12 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_5 = F_4 ( V_4 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) )
return F_39 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_19 = F_21 ( V_5 ) ;
if ( ! V_19 ) {
V_12 = - V_57 ;
goto V_86;
}
V_19 -> V_47 = V_65 . V_47 ;
memcpy ( & V_19 -> V_93 , & V_65 . V_93 , sizeof V_65 . V_93 ) ;
V_12 = F_98 ( V_5 -> V_49 , (struct V_92 * ) & V_19 -> V_93 , V_19 ) ;
if ( V_12 )
goto V_87;
V_46 . V_2 = V_19 -> V_2 ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) ) {
V_12 = - V_68 ;
goto V_172;
}
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return 0 ;
V_172:
F_99 ( V_5 -> V_49 , (struct V_92 * ) & V_19 -> V_93 ) ;
F_45 ( V_19 ) ;
V_87:
F_5 ( & V_9 ) ;
F_41 ( & V_20 , V_19 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_35 ( & V_19 -> V_16 ) ;
F_20 ( V_19 ) ;
V_86:
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_5 ) ;
return V_12 ;
}
static T_1 F_100 ( struct V_3 * V_4 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_89 V_65 ;
struct V_90 V_46 ;
struct V_18 * V_19 ;
int V_12 = 0 ;
if ( V_63 < sizeof( V_46 ) )
return - V_67 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
F_5 ( & V_9 ) ;
V_19 = F_2 ( & V_20 , V_65 . V_2 ) ;
if ( ! V_19 )
V_19 = F_3 ( - V_7 ) ;
else if ( V_19 -> V_5 -> V_4 != V_4 )
V_19 = F_3 ( - V_8 ) ;
else {
F_41 ( & V_20 , V_19 -> V_2 ) ;
F_7 ( & V_19 -> V_5 -> V_10 ) ;
}
F_8 ( & V_9 ) ;
if ( F_6 ( V_19 ) ) {
V_12 = F_39 ( V_19 ) ;
goto V_58;
}
F_99 ( V_19 -> V_5 -> V_49 , (struct V_92 * ) & V_19 -> V_93 ) ;
F_5 ( & V_19 -> V_5 -> V_4 -> V_9 ) ;
F_45 ( V_19 ) ;
F_35 ( & V_19 -> V_16 ) ;
F_8 ( & V_19 -> V_5 -> V_4 -> V_9 ) ;
F_9 ( V_19 -> V_5 ) ;
V_46 . V_76 = V_19 -> V_76 ;
F_20 ( V_19 ) ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_68 ;
V_58:
return V_12 ;
}
static void F_101 ( struct V_3 * V_173 , struct V_3 * V_174 )
{
if ( V_173 < V_174 ) {
F_5 ( & V_173 -> V_9 ) ;
F_5 ( & V_174 -> V_9 ) ;
} else {
F_5 ( & V_174 -> V_9 ) ;
F_5 ( & V_173 -> V_9 ) ;
}
}
static void F_102 ( struct V_3 * V_173 , struct V_3 * V_174 )
{
if ( V_173 < V_174 ) {
F_8 ( & V_174 -> V_9 ) ;
F_8 ( & V_173 -> V_9 ) ;
} else {
F_8 ( & V_173 -> V_9 ) ;
F_8 ( & V_174 -> V_9 ) ;
}
}
static void F_103 ( struct V_1 * V_5 , struct V_3 * V_4 )
{
struct V_40 * V_41 , * V_88 ;
F_43 (uevent, tmp, &ctx->file->event_list, list)
if ( V_41 -> V_5 == V_5 )
F_104 ( & V_41 -> V_16 , & V_4 -> V_59 ) ;
}
static T_1 F_105 ( struct V_3 * V_175 ,
const char T_2 * V_61 ,
int V_62 , int V_63 )
{
struct V_176 V_65 ;
struct V_177 V_46 ;
struct V_1 * V_5 ;
struct V_4 * V_69 ;
struct V_3 * V_178 ;
int V_12 = 0 ;
if ( F_30 ( & V_65 , V_61 , sizeof( V_65 ) ) )
return - V_68 ;
V_69 = F_106 ( V_65 . V_179 ) ;
if ( ! V_69 )
return - V_7 ;
V_5 = F_4 ( V_69 -> V_26 , V_65 . V_2 ) ;
if ( F_6 ( V_5 ) ) {
V_12 = F_39 ( V_5 ) ;
goto V_180;
}
V_178 = V_5 -> V_4 ;
if ( V_178 == V_175 ) {
V_46 . V_76 = V_5 -> V_76 ;
goto V_75;
}
F_101 ( V_178 , V_175 ) ;
F_5 ( & V_9 ) ;
F_104 ( & V_5 -> V_16 , & V_175 -> V_17 ) ;
F_103 ( V_5 , V_175 ) ;
V_5 -> V_4 = V_175 ;
V_46 . V_76 = V_5 -> V_76 ;
F_8 ( & V_9 ) ;
F_102 ( V_178 , V_175 ) ;
V_75:
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_65 . V_75 ,
& V_46 , sizeof( V_46 ) ) )
V_12 = - V_68 ;
F_9 ( V_5 ) ;
V_180:
F_107 ( V_69 ) ;
return V_12 ;
}
static T_1 F_108 ( struct V_4 * V_69 , const char T_2 * V_181 ,
T_4 V_182 , T_5 * V_183 )
{
struct V_3 * V_4 = V_69 -> V_26 ;
struct V_184 V_185 ;
T_1 V_12 ;
if ( V_182 < sizeof( V_185 ) )
return - V_8 ;
if ( F_30 ( & V_185 , V_181 , sizeof( V_185 ) ) )
return - V_68 ;
if ( V_185 . V_65 >= F_109 ( V_186 ) )
return - V_8 ;
if ( V_185 . V_187 + sizeof( V_185 ) > V_182 )
return - V_8 ;
if ( ! V_186 [ V_185 . V_65 ] )
return - V_152 ;
V_12 = V_186 [ V_185 . V_65 ] ( V_4 , V_181 + sizeof( V_185 ) , V_185 . V_187 , V_185 . V_58 ) ;
if ( ! V_12 )
V_12 = V_182 ;
return V_12 ;
}
static unsigned int F_110 ( struct V_4 * V_69 , struct V_188 * V_66 )
{
struct V_3 * V_4 = V_69 -> V_26 ;
unsigned int V_189 = 0 ;
V_60 ( V_69 , & V_4 -> V_60 , V_66 ) ;
if ( ! F_31 ( & V_4 -> V_59 ) )
V_189 = V_190 | V_191 ;
return V_189 ;
}
static int F_111 ( struct V_192 * V_192 , struct V_4 * V_69 )
{
struct V_3 * V_4 ;
V_4 = F_94 ( sizeof *V_4 , V_13 ) ;
if ( ! V_4 )
return - V_57 ;
F_16 ( & V_4 -> V_59 ) ;
F_16 ( & V_4 -> V_17 ) ;
F_112 ( & V_4 -> V_60 ) ;
F_113 ( & V_4 -> V_9 ) ;
V_69 -> V_26 = V_4 ;
V_4 -> V_69 = V_69 ;
return F_114 ( V_192 , V_69 ) ;
}
static int F_115 ( struct V_192 * V_192 , struct V_4 * V_69 )
{
struct V_3 * V_4 = V_69 -> V_26 ;
struct V_1 * V_5 , * V_88 ;
F_5 ( & V_4 -> V_9 ) ;
F_43 (ctx, tmp, &file->ctx_list, list) {
F_8 ( & V_4 -> V_9 ) ;
F_5 ( & V_9 ) ;
F_41 ( & V_6 , V_5 -> V_2 ) ;
F_8 ( & V_9 ) ;
F_46 ( V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
}
F_8 ( & V_4 -> V_9 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static T_1 F_116 ( struct V_122 * V_112 ,
struct V_193 * V_194 ,
char * V_181 )
{
return sprintf ( V_181 , L_1 , V_195 ) ;
}
static int T_6 F_117 ( void )
{
int V_12 ;
V_12 = F_118 ( & V_196 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_119 ( V_196 . V_197 , & V_198 ) ;
if ( V_12 ) {
F_120 ( V_199 L_2 ) ;
goto V_86;
}
V_200 = F_121 ( V_201 , V_202 ) ;
if ( ! V_200 ) {
F_120 ( V_199 L_3 ) ;
V_12 = - V_57 ;
goto V_87;
}
return 0 ;
V_87:
F_122 ( V_196 . V_197 , & V_198 ) ;
V_86:
F_123 ( & V_196 ) ;
return V_12 ;
}
static void T_7 F_124 ( void )
{
F_125 ( V_200 ) ;
F_122 ( V_196 . V_197 , & V_198 ) ;
F_123 ( & V_196 ) ;
F_126 ( & V_6 ) ;
}
