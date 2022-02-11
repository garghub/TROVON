static inline void T_1 * F_1 ( T_2 V_1 )
{
return ( void T_1 * ) ( V_2 ) V_1 ;
}
static int F_2 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_3 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 T_1 * V_8 )
{
struct V_7 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( V_6 -> V_10 [ 0 ] )
F_5 ( V_9 . V_11 , V_6 -> V_10 , sizeof( V_9 . V_11 ) ) ;
else
F_5 ( V_9 . V_11 , V_6 -> V_6 -> V_11 -> V_12 , sizeof( V_9 . V_11 ) ) ;
F_5 ( V_9 . V_13 , V_6 -> V_13 , sizeof( V_9 . V_13 ) ) ;
F_5 ( V_9 . V_14 , V_6 -> V_14 , sizeof( V_9 . V_14 ) ) ;
F_5 ( V_9 . V_15 , V_6 -> V_15 , sizeof( V_9 . V_15 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_6 -> V_18 ;
V_9 . V_19 = V_6 -> V_19 ;
if ( F_6 ( V_8 , & V_9 , sizeof( * V_8 ) ) )
return - V_20 ;
return 0 ;
}
static struct V_21 * F_7 ( struct V_5 * V_22 , T_3 V_23 )
{
struct V_21 * V_24 ;
int V_25 = V_23 & V_26 ;
V_23 &= ~ V_26 ;
F_8 ( & V_22 -> V_27 ) ;
F_9 (entity, mdev) {
if ( ( ( F_10 ( V_24 ) == V_23 ) && ! V_25 ) ||
( ( F_10 ( V_24 ) > V_23 ) && V_25 ) ) {
F_11 ( & V_22 -> V_27 ) ;
return V_24 ;
}
}
F_11 ( & V_22 -> V_27 ) ;
return NULL ;
}
static long F_12 ( struct V_5 * V_22 ,
struct V_28 T_1 * V_29 )
{
struct V_21 * V_30 ;
struct V_28 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_13 ( & V_31 . V_23 , & V_29 -> V_23 , sizeof( V_31 . V_23 ) ) )
return - V_20 ;
V_30 = F_7 ( V_22 , V_31 . V_23 ) ;
if ( V_30 == NULL )
return - V_32 ;
V_31 . V_23 = F_10 ( V_30 ) ;
if ( V_30 -> V_12 )
F_5 ( V_31 . V_12 , V_30 -> V_12 , sizeof( V_31 . V_12 ) ) ;
V_31 . type = V_30 -> V_33 ;
V_31 . V_34 = 0 ;
V_31 . V_35 = V_30 -> V_35 ;
V_31 . V_36 = 0 ;
V_31 . V_37 = V_30 -> V_38 ;
V_31 . V_39 = V_30 -> V_40 - V_30 -> V_41 ;
if ( V_30 -> V_33 < V_42 ||
V_30 -> V_33 > V_43 ) {
if ( F_14 ( V_30 ) )
V_31 . type = V_44 ;
else if ( V_30 -> V_33 != V_45 )
V_31 . type = V_43 ;
}
memcpy ( & V_31 . V_46 , & V_30 -> V_9 , sizeof( V_30 -> V_9 ) ) ;
if ( F_6 ( V_29 , & V_31 , sizeof( V_31 ) ) )
return - V_20 ;
return 0 ;
}
static void F_15 ( const struct V_47 * V_48 ,
struct V_49 * V_50 )
{
V_50 -> V_24 = F_10 ( V_48 -> V_24 ) ;
V_50 -> V_51 = V_48 -> V_51 ;
V_50 -> V_35 = V_48 -> V_35 ;
}
static long F_16 ( struct V_5 * V_22 ,
struct V_52 * V_39 )
{
struct V_21 * V_24 ;
V_24 = F_7 ( V_22 , V_39 -> V_24 ) ;
if ( V_24 == NULL )
return - V_32 ;
if ( V_39 -> V_37 ) {
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_24 -> V_38 ; V_53 ++ ) {
struct V_49 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_15 ( & V_24 -> V_37 [ V_53 ] , & V_54 ) ;
if ( F_6 ( & V_39 -> V_37 [ V_53 ] , & V_54 , sizeof( V_54 ) ) )
return - V_20 ;
}
}
if ( V_39 -> V_39 ) {
struct V_55 * V_56 ;
struct V_57 T_1 * V_58 = V_39 -> V_39 ;
F_17 (link, &entity->links, list) {
struct V_57 V_59 ;
if ( V_56 -> V_60 -> V_24 != V_24 )
continue;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_15 ( V_56 -> V_60 ,
& V_59 . V_60 ) ;
F_15 ( V_56 -> V_61 ,
& V_59 . V_61 ) ;
V_59 . V_35 = V_56 -> V_35 ;
if ( F_6 ( V_58 , & V_59 ,
sizeof( * V_58 ) ) )
return - V_20 ;
V_58 ++ ;
}
}
return 0 ;
}
static long F_18 ( struct V_5 * V_22 ,
struct V_52 T_1 * V_62 )
{
struct V_52 V_39 ;
int V_63 ;
if ( F_13 ( & V_39 , V_62 , sizeof( V_39 ) ) )
return - V_20 ;
V_63 = F_16 ( V_22 , & V_39 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( F_6 ( V_62 , & V_39 , sizeof( * V_62 ) ) )
return - V_20 ;
return 0 ;
}
static long F_19 ( struct V_5 * V_22 ,
struct V_57 T_1 * V_64 )
{
struct V_55 * V_56 = NULL ;
struct V_57 V_65 ;
struct V_21 * V_60 ;
struct V_21 * V_61 ;
int V_66 ;
if ( F_13 ( & V_65 , V_64 , sizeof( V_65 ) ) )
return - V_20 ;
V_60 = F_7 ( V_22 , V_65 . V_60 . V_24 ) ;
V_61 = F_7 ( V_22 , V_65 . V_61 . V_24 ) ;
if ( V_60 == NULL || V_61 == NULL )
return - V_32 ;
if ( V_65 . V_60 . V_51 >= V_60 -> V_38 ||
V_65 . V_61 . V_51 >= V_61 -> V_38 )
return - V_32 ;
V_56 = F_20 ( & V_60 -> V_37 [ V_65 . V_60 . V_51 ] ,
& V_61 -> V_37 [ V_65 . V_61 . V_51 ] ) ;
if ( V_56 == NULL )
return - V_32 ;
V_66 = F_21 ( V_56 , V_65 . V_35 ) ;
if ( F_6 ( V_64 , & V_65 , sizeof( V_65 ) ) )
return - V_20 ;
return V_66 ;
}
static long F_22 ( struct V_5 * V_22 ,
struct V_67 * V_68 )
{
struct V_21 * V_24 ;
struct V_69 * V_70 ;
struct V_47 * V_54 ;
struct V_55 * V_56 ;
struct V_71 V_72 , T_1 * V_73 ;
struct V_74 V_75 , T_1 * V_76 ;
struct V_77 V_48 , T_1 * V_50 ;
struct V_78 V_79 , T_1 * V_65 ;
unsigned int V_80 ;
int V_66 = 0 ;
V_68 -> V_81 = V_22 -> V_81 ;
V_80 = 0 ;
V_73 = F_1 ( V_68 -> V_82 ) ;
F_9 (entity, mdev) {
V_80 ++ ;
if ( V_66 || ! V_73 )
continue;
if ( V_80 > V_68 -> V_83 ) {
V_66 = - V_84 ;
continue;
}
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_23 = V_24 -> V_85 . V_23 ;
V_72 . V_33 = V_24 -> V_33 ;
strncpy ( V_72 . V_12 , V_24 -> V_12 ,
sizeof( V_72 . V_12 ) ) ;
if ( F_6 ( V_73 , & V_72 , sizeof( V_72 ) ) )
V_66 = - V_20 ;
V_73 ++ ;
}
V_68 -> V_83 = V_80 ;
V_80 = 0 ;
V_76 = F_1 ( V_68 -> V_86 ) ;
F_23 (intf, mdev) {
V_80 ++ ;
if ( V_66 || ! V_76 )
continue;
if ( V_80 > V_68 -> V_87 ) {
V_66 = - V_84 ;
continue;
}
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_23 = V_70 -> V_85 . V_23 ;
V_75 . V_88 = V_70 -> type ;
V_75 . V_35 = V_70 -> V_35 ;
if ( F_24 ( & V_70 -> V_85 ) == V_89 ) {
struct V_90 * V_91 ;
V_91 = F_25 ( V_70 ) ;
V_75 . V_91 . V_92 = V_91 -> V_92 ;
V_75 . V_91 . V_93 = V_91 -> V_93 ;
}
if ( F_6 ( V_76 , & V_75 , sizeof( V_75 ) ) )
V_66 = - V_20 ;
V_76 ++ ;
}
V_68 -> V_87 = V_80 ;
V_80 = 0 ;
V_50 = F_1 ( V_68 -> V_94 ) ;
F_26 (pad, mdev) {
V_80 ++ ;
if ( V_66 || ! V_50 )
continue;
if ( V_80 > V_68 -> V_38 ) {
V_66 = - V_84 ;
continue;
}
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_23 = V_54 -> V_85 . V_23 ;
V_48 . V_95 = V_54 -> V_24 -> V_85 . V_23 ;
V_48 . V_35 = V_54 -> V_35 ;
if ( F_6 ( V_50 , & V_48 , sizeof( V_48 ) ) )
V_66 = - V_20 ;
V_50 ++ ;
}
V_68 -> V_38 = V_80 ;
V_80 = 0 ;
V_65 = F_1 ( V_68 -> V_96 ) ;
F_27 (link, mdev) {
if ( V_56 -> V_97 )
continue;
V_80 ++ ;
if ( V_66 || ! V_65 )
continue;
if ( V_80 > V_68 -> V_40 ) {
V_66 = - V_84 ;
continue;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_23 = V_56 -> V_85 . V_23 ;
V_79 . V_98 = V_56 -> V_99 -> V_23 ;
V_79 . V_100 = V_56 -> V_101 -> V_23 ;
V_79 . V_35 = V_56 -> V_35 ;
if ( F_6 ( V_65 , & V_79 , sizeof( V_79 ) ) )
V_66 = - V_20 ;
V_65 ++ ;
}
V_68 -> V_40 = V_80 ;
return V_66 ;
}
static long F_28 ( struct V_5 * V_22 ,
struct V_67 T_1 * V_102 )
{
struct V_67 V_103 ;
int V_66 ;
if ( F_13 ( & V_103 , V_102 , sizeof( V_103 ) ) )
return - V_20 ;
V_66 = F_22 ( V_22 , & V_103 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( F_6 ( V_102 , & V_103 , sizeof( * V_102 ) ) )
return - V_20 ;
return 0 ;
}
static long F_29 ( struct V_3 * V_4 , unsigned int V_104 ,
unsigned long V_1 )
{
struct V_105 * V_91 = F_30 ( V_4 ) ;
struct V_5 * V_6 = F_31 ( V_91 ) ;
long V_66 ;
switch ( V_104 ) {
case V_106 :
V_66 = F_4 ( V_6 ,
(struct V_7 T_1 * ) V_1 ) ;
break;
case V_107 :
V_66 = F_12 ( V_6 ,
(struct V_28 T_1 * ) V_1 ) ;
break;
case V_108 :
F_32 ( & V_6 -> V_109 ) ;
V_66 = F_18 ( V_6 ,
(struct V_52 T_1 * ) V_1 ) ;
F_33 ( & V_6 -> V_109 ) ;
break;
case V_110 :
F_32 ( & V_6 -> V_109 ) ;
V_66 = F_19 ( V_6 ,
(struct V_57 T_1 * ) V_1 ) ;
F_33 ( & V_6 -> V_109 ) ;
break;
case V_111 :
F_32 ( & V_6 -> V_109 ) ;
V_66 = F_28 ( V_6 ,
(struct V_67 T_1 * ) V_1 ) ;
F_33 ( & V_6 -> V_109 ) ;
break;
default:
V_66 = - V_112 ;
}
return V_66 ;
}
static long F_34 ( struct V_5 * V_22 ,
struct V_113 T_1 * V_62 )
{
struct V_52 V_39 ;
T_4 V_114 , V_115 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( F_35 ( V_39 . V_24 , & V_62 -> V_24 )
|| F_35 ( V_114 , & V_62 -> V_37 )
|| F_35 ( V_115 , & V_62 -> V_39 ) )
return - V_20 ;
V_39 . V_37 = F_36 ( V_114 ) ;
V_39 . V_39 = F_36 ( V_115 ) ;
return F_16 ( V_22 , & V_39 ) ;
}
static long F_37 ( struct V_3 * V_4 , unsigned int V_104 ,
unsigned long V_1 )
{
struct V_105 * V_91 = F_30 ( V_4 ) ;
struct V_5 * V_6 = F_31 ( V_91 ) ;
long V_66 ;
switch ( V_104 ) {
case V_106 :
case V_107 :
case V_110 :
case V_111 :
return F_29 ( V_4 , V_104 , V_1 ) ;
case V_116 :
F_32 ( & V_6 -> V_109 ) ;
V_66 = F_34 ( V_6 ,
(struct V_113 T_1 * ) V_1 ) ;
F_33 ( & V_6 -> V_109 ) ;
break;
default:
V_66 = - V_112 ;
}
return V_66 ;
}
static T_5 F_38 ( struct V_117 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_5 * V_22 = F_31 ( F_39 ( V_118 ) ) ;
return sprintf ( V_121 , L_1 , ( int ) sizeof( V_22 -> V_13 ) , V_22 -> V_13 ) ;
}
static void F_40 ( struct V_105 * V_22 )
{
F_41 ( V_22 -> V_122 , L_2 ) ;
}
int T_6 F_42 ( struct V_5 * V_22 ,
struct V_21 * V_24 )
{
struct V_123 * V_124 , * V_25 ;
unsigned int V_80 ;
int V_66 ;
if ( V_24 -> V_33 == V_44 ||
V_24 -> V_33 == V_125 )
F_43 ( V_22 -> V_6 ,
L_3 ,
V_24 -> V_12 ) ;
F_44 ( V_24 -> V_85 . V_22 != NULL ) ;
V_24 -> V_85 . V_22 = V_22 ;
F_45 ( & V_24 -> V_39 ) ;
V_24 -> V_40 = 0 ;
V_24 -> V_41 = 0 ;
if ( ! F_46 ( & V_22 -> V_126 , V_127 ) )
return - V_128 ;
F_8 ( & V_22 -> V_27 ) ;
V_66 = F_47 ( & V_22 -> V_126 , 1 ,
& V_24 -> V_129 ) ;
if ( V_66 < 0 ) {
F_11 ( & V_22 -> V_27 ) ;
return V_66 ;
}
V_22 -> V_130 =
F_48 ( V_22 -> V_130 , V_24 -> V_129 ) ;
F_49 ( V_22 , V_131 , & V_24 -> V_85 ) ;
for ( V_80 = 0 ; V_80 < V_24 -> V_38 ; V_80 ++ )
F_49 ( V_22 , V_132 ,
& V_24 -> V_37 [ V_80 ] . V_85 ) ;
F_50 (notify, next, &mdev->entity_notify, list) {
( V_124 ) -> V_124 ( V_24 , V_124 -> V_133 ) ;
}
F_11 ( & V_22 -> V_27 ) ;
F_32 ( & V_22 -> V_109 ) ;
if ( V_22 -> V_130
>= V_22 -> V_134 . V_135 . V_136 ) {
struct V_137 V_138 = { . V_139 = 0 } ;
V_66 = F_51 ( & V_138 , V_22 ) ;
if ( V_66 ) {
F_33 ( & V_22 -> V_109 ) ;
return V_66 ;
}
F_52 ( & V_22 -> V_134 ) ;
V_22 -> V_134 = V_138 ;
}
F_33 ( & V_22 -> V_109 ) ;
return 0 ;
}
static void F_53 ( struct V_21 * V_24 )
{
struct V_5 * V_22 = V_24 -> V_85 . V_22 ;
struct V_55 * V_56 , * V_140 ;
struct V_69 * V_70 ;
unsigned int V_80 ;
F_54 ( & V_22 -> V_126 , V_24 -> V_129 ) ;
F_17 (intf, &mdev->interfaces, graph_obj.list) {
F_50 (link, tmp, &intf->links, list) {
if ( V_56 -> V_24 == V_24 )
F_55 ( V_56 ) ;
}
}
F_56 ( V_24 ) ;
for ( V_80 = 0 ; V_80 < V_24 -> V_38 ; V_80 ++ )
F_57 ( & V_24 -> V_37 [ V_80 ] . V_85 ) ;
F_57 ( & V_24 -> V_85 ) ;
V_24 -> V_85 . V_22 = NULL ;
}
void F_58 ( struct V_21 * V_24 )
{
struct V_5 * V_22 = V_24 -> V_85 . V_22 ;
if ( V_22 == NULL )
return;
F_8 ( & V_22 -> V_27 ) ;
F_53 ( V_24 ) ;
F_11 ( & V_22 -> V_27 ) ;
}
void F_59 ( struct V_5 * V_22 )
{
F_45 ( & V_22 -> V_141 ) ;
F_45 ( & V_22 -> V_142 ) ;
F_45 ( & V_22 -> V_37 ) ;
F_45 ( & V_22 -> V_39 ) ;
F_45 ( & V_22 -> V_143 ) ;
F_60 ( & V_22 -> V_27 ) ;
F_61 ( & V_22 -> V_109 ) ;
F_62 ( & V_22 -> V_126 ) ;
F_41 ( V_22 -> V_6 , L_4 ) ;
}
void F_63 ( struct V_5 * V_22 )
{
F_64 ( & V_22 -> V_126 ) ;
V_22 -> V_130 = 0 ;
F_52 ( & V_22 -> V_134 ) ;
F_65 ( & V_22 -> V_109 ) ;
}
int T_6 F_66 ( struct V_5 * V_22 ,
struct V_144 * V_145 )
{
int V_66 ;
V_22 -> V_91 . V_146 = & V_147 ;
V_22 -> V_91 . V_122 = V_22 -> V_6 ;
V_22 -> V_91 . V_148 = F_40 ;
V_22 -> V_81 = 0 ;
V_66 = F_67 ( & V_22 -> V_91 , V_145 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_68 ( & V_22 -> V_91 . V_6 , & V_149 ) ;
if ( V_66 < 0 ) {
F_69 ( & V_22 -> V_91 ) ;
return V_66 ;
}
F_41 ( V_22 -> V_6 , L_5 ) ;
return 0 ;
}
int T_6 F_70 ( struct V_5 * V_22 ,
struct V_123 * V_150 )
{
F_8 ( & V_22 -> V_27 ) ;
F_71 ( & V_150 -> V_151 , & V_22 -> V_143 ) ;
F_11 ( & V_22 -> V_27 ) ;
return 0 ;
}
static void F_72 ( struct V_5 * V_22 ,
struct V_123 * V_150 )
{
F_73 ( & V_150 -> V_151 ) ;
}
void F_74 ( struct V_5 * V_22 ,
struct V_123 * V_150 )
{
F_8 ( & V_22 -> V_27 ) ;
F_72 ( V_22 , V_150 ) ;
F_11 ( & V_22 -> V_27 ) ;
}
void F_75 ( struct V_5 * V_22 )
{
struct V_21 * V_24 ;
struct V_21 * V_25 ;
struct V_69 * V_70 , * V_152 ;
struct V_123 * V_124 , * V_153 ;
if ( V_22 == NULL )
return;
F_8 ( & V_22 -> V_27 ) ;
if ( ! F_76 ( & V_22 -> V_91 ) ) {
F_11 ( & V_22 -> V_27 ) ;
return;
}
F_50 (entity, next, &mdev->entities, graph_obj.list)
F_53 ( V_24 ) ;
F_50 (notify, nextp, &mdev->entity_notify, list)
F_72 ( V_22 , V_124 ) ;
F_50 (intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
F_77 ( V_70 ) ;
F_57 ( & V_70 -> V_85 ) ;
F_78 ( V_70 ) ;
}
F_11 ( & V_22 -> V_27 ) ;
F_79 ( & V_22 -> V_91 . V_6 , & V_149 ) ;
F_69 ( & V_22 -> V_91 ) ;
F_41 ( V_22 -> V_6 , L_6 ) ;
}
static void F_80 ( struct V_117 * V_6 , void * V_154 )
{
}
struct V_5 * F_81 ( struct V_117 * V_6 )
{
struct V_5 * V_22 ;
V_22 = F_82 ( V_6 , F_80 , NULL , NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_83 ( F_80 ,
sizeof( struct V_5 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
return F_84 ( V_6 , V_22 , NULL , NULL ) ;
}
struct V_5 * F_85 ( struct V_117 * V_6 )
{
return F_82 ( V_6 , F_80 , NULL , NULL ) ;
}
void F_86 ( struct V_5 * V_22 ,
struct V_155 * V_155 ,
const char * V_12 )
{
V_22 -> V_6 = & V_155 -> V_6 ;
if ( V_12 )
F_5 ( V_22 -> V_13 , V_12 , sizeof( V_22 -> V_13 ) ) ;
else
F_5 ( V_22 -> V_13 , F_87 ( V_155 ) , sizeof( V_22 -> V_13 ) ) ;
sprintf ( V_22 -> V_15 , L_7 , F_87 ( V_155 ) ) ;
V_22 -> V_18 = ( V_155 -> V_156 << 16 )
| V_155 -> V_157 ;
V_22 -> V_19 = V_158 ;
F_59 ( V_22 ) ;
}
void F_88 ( struct V_5 * V_22 ,
struct V_159 * V_160 ,
const char * V_161 ,
const char * V_10 )
{
V_22 -> V_6 = & V_160 -> V_6 ;
if ( V_10 )
F_5 ( V_22 -> V_10 , V_10 ,
sizeof( V_22 -> V_10 ) ) ;
if ( V_161 )
F_5 ( V_22 -> V_13 , V_161 , sizeof( V_22 -> V_13 ) ) ;
else if ( V_160 -> V_162 )
F_5 ( V_22 -> V_13 , V_160 -> V_162 , sizeof( V_22 -> V_13 ) ) ;
else
F_5 ( V_22 -> V_13 , L_8 , sizeof( V_22 -> V_13 ) ) ;
if ( V_160 -> V_14 )
F_5 ( V_22 -> V_14 , V_160 -> V_14 , sizeof( V_22 -> V_14 ) ) ;
F_89 ( V_160 , V_22 -> V_15 , sizeof( V_22 -> V_15 ) ) ;
V_22 -> V_18 = F_90 ( V_160 -> V_163 . V_164 ) ;
V_22 -> V_19 = V_158 ;
F_59 ( V_22 ) ;
}
