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
F_8 (entity, mdev) {
if ( ( ( F_9 ( V_24 ) == V_23 ) && ! V_25 ) ||
( ( F_9 ( V_24 ) > V_23 ) && V_25 ) ) {
return V_24 ;
}
}
return NULL ;
}
static long F_10 ( struct V_5 * V_22 ,
struct V_27 T_1 * V_28 )
{
struct V_21 * V_29 ;
struct V_27 V_30 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
if ( F_11 ( & V_30 . V_23 , & V_28 -> V_23 , sizeof( V_30 . V_23 ) ) )
return - V_20 ;
V_29 = F_7 ( V_22 , V_30 . V_23 ) ;
if ( V_29 == NULL )
return - V_31 ;
V_30 . V_23 = F_9 ( V_29 ) ;
if ( V_29 -> V_12 )
F_5 ( V_30 . V_12 , V_29 -> V_12 , sizeof( V_30 . V_12 ) ) ;
V_30 . type = V_29 -> V_32 ;
V_30 . V_33 = 0 ;
V_30 . V_34 = V_29 -> V_34 ;
V_30 . V_35 = 0 ;
V_30 . V_36 = V_29 -> V_37 ;
V_30 . V_38 = V_29 -> V_39 - V_29 -> V_40 ;
if ( V_29 -> V_32 < V_41 ||
V_29 -> V_32 > V_42 ) {
if ( F_12 ( V_29 ) )
V_30 . type = V_43 ;
else if ( V_29 -> V_32 != V_44 )
V_30 . type = V_42 ;
}
memcpy ( & V_30 . V_45 , & V_29 -> V_9 , sizeof( V_29 -> V_9 ) ) ;
if ( F_6 ( V_28 , & V_30 , sizeof( V_30 ) ) )
return - V_20 ;
return 0 ;
}
static void F_13 ( const struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> V_24 = F_9 ( V_47 -> V_24 ) ;
V_49 -> V_50 = V_47 -> V_50 ;
V_49 -> V_34 = V_47 -> V_34 ;
}
static long F_14 ( struct V_5 * V_22 ,
struct V_51 * V_38 )
{
struct V_21 * V_24 ;
V_24 = F_7 ( V_22 , V_38 -> V_24 ) ;
if ( V_24 == NULL )
return - V_31 ;
if ( V_38 -> V_36 ) {
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < V_24 -> V_37 ; V_52 ++ ) {
struct V_48 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_13 ( & V_24 -> V_36 [ V_52 ] , & V_53 ) ;
if ( F_6 ( & V_38 -> V_36 [ V_52 ] , & V_53 , sizeof( V_53 ) ) )
return - V_20 ;
}
}
if ( V_38 -> V_38 ) {
struct V_54 * V_55 ;
struct V_56 T_1 * V_57 = V_38 -> V_38 ;
F_15 (link, &entity->links, list) {
struct V_56 V_58 ;
if ( V_55 -> V_59 -> V_24 != V_24 )
continue;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
F_13 ( V_55 -> V_59 ,
& V_58 . V_59 ) ;
F_13 ( V_55 -> V_60 ,
& V_58 . V_60 ) ;
V_58 . V_34 = V_55 -> V_34 ;
if ( F_6 ( V_57 , & V_58 ,
sizeof( * V_57 ) ) )
return - V_20 ;
V_57 ++ ;
}
}
return 0 ;
}
static long F_16 ( struct V_5 * V_22 ,
struct V_51 T_1 * V_61 )
{
struct V_51 V_38 ;
int V_62 ;
if ( F_11 ( & V_38 , V_61 , sizeof( V_38 ) ) )
return - V_20 ;
V_62 = F_14 ( V_22 , & V_38 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( F_6 ( V_61 , & V_38 , sizeof( * V_61 ) ) )
return - V_20 ;
return 0 ;
}
static long F_17 ( struct V_5 * V_22 ,
struct V_56 T_1 * V_63 )
{
struct V_54 * V_55 = NULL ;
struct V_56 V_64 ;
struct V_21 * V_59 ;
struct V_21 * V_60 ;
int V_65 ;
if ( F_11 ( & V_64 , V_63 , sizeof( V_64 ) ) )
return - V_20 ;
V_59 = F_7 ( V_22 , V_64 . V_59 . V_24 ) ;
V_60 = F_7 ( V_22 , V_64 . V_60 . V_24 ) ;
if ( V_59 == NULL || V_60 == NULL )
return - V_31 ;
if ( V_64 . V_59 . V_50 >= V_59 -> V_37 ||
V_64 . V_60 . V_50 >= V_60 -> V_37 )
return - V_31 ;
V_55 = F_18 ( & V_59 -> V_36 [ V_64 . V_59 . V_50 ] ,
& V_60 -> V_36 [ V_64 . V_60 . V_50 ] ) ;
if ( V_55 == NULL )
return - V_31 ;
V_65 = F_19 ( V_55 , V_64 . V_34 ) ;
if ( F_6 ( V_63 , & V_64 , sizeof( V_64 ) ) )
return - V_20 ;
return V_65 ;
}
static long F_20 ( struct V_5 * V_22 ,
struct V_66 * V_67 )
{
struct V_21 * V_24 ;
struct V_68 * V_69 ;
struct V_46 * V_53 ;
struct V_54 * V_55 ;
struct V_70 V_71 , T_1 * V_72 ;
struct V_73 V_74 , T_1 * V_75 ;
struct V_76 V_47 , T_1 * V_49 ;
struct V_77 V_78 , T_1 * V_64 ;
unsigned int V_79 ;
int V_65 = 0 ;
V_67 -> V_80 = V_22 -> V_80 ;
V_79 = 0 ;
V_72 = F_1 ( V_67 -> V_81 ) ;
F_8 (entity, mdev) {
V_79 ++ ;
if ( V_65 || ! V_72 )
continue;
if ( V_79 > V_67 -> V_82 ) {
V_65 = - V_83 ;
continue;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_23 = V_24 -> V_84 . V_23 ;
V_71 . V_32 = V_24 -> V_32 ;
strncpy ( V_71 . V_12 , V_24 -> V_12 ,
sizeof( V_71 . V_12 ) ) ;
if ( F_6 ( V_72 , & V_71 , sizeof( V_71 ) ) )
V_65 = - V_20 ;
V_72 ++ ;
}
V_67 -> V_82 = V_79 ;
V_79 = 0 ;
V_75 = F_1 ( V_67 -> V_85 ) ;
F_21 (intf, mdev) {
V_79 ++ ;
if ( V_65 || ! V_75 )
continue;
if ( V_79 > V_67 -> V_86 ) {
V_65 = - V_83 ;
continue;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_23 = V_69 -> V_84 . V_23 ;
V_74 . V_87 = V_69 -> type ;
V_74 . V_34 = V_69 -> V_34 ;
if ( F_22 ( & V_69 -> V_84 ) == V_88 ) {
struct V_89 * V_90 ;
V_90 = F_23 ( V_69 ) ;
V_74 . V_90 . V_91 = V_90 -> V_91 ;
V_74 . V_90 . V_92 = V_90 -> V_92 ;
}
if ( F_6 ( V_75 , & V_74 , sizeof( V_74 ) ) )
V_65 = - V_20 ;
V_75 ++ ;
}
V_67 -> V_86 = V_79 ;
V_79 = 0 ;
V_49 = F_1 ( V_67 -> V_93 ) ;
F_24 (pad, mdev) {
V_79 ++ ;
if ( V_65 || ! V_49 )
continue;
if ( V_79 > V_67 -> V_37 ) {
V_65 = - V_83 ;
continue;
}
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_23 = V_53 -> V_84 . V_23 ;
V_47 . V_94 = V_53 -> V_24 -> V_84 . V_23 ;
V_47 . V_34 = V_53 -> V_34 ;
if ( F_6 ( V_49 , & V_47 , sizeof( V_47 ) ) )
V_65 = - V_20 ;
V_49 ++ ;
}
V_67 -> V_37 = V_79 ;
V_79 = 0 ;
V_64 = F_1 ( V_67 -> V_95 ) ;
F_25 (link, mdev) {
if ( V_55 -> V_96 )
continue;
V_79 ++ ;
if ( V_65 || ! V_64 )
continue;
if ( V_79 > V_67 -> V_39 ) {
V_65 = - V_83 ;
continue;
}
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_23 = V_55 -> V_84 . V_23 ;
V_78 . V_97 = V_55 -> V_98 -> V_23 ;
V_78 . V_99 = V_55 -> V_100 -> V_23 ;
V_78 . V_34 = V_55 -> V_34 ;
if ( F_6 ( V_64 , & V_78 , sizeof( V_78 ) ) )
V_65 = - V_20 ;
V_64 ++ ;
}
V_67 -> V_39 = V_79 ;
return V_65 ;
}
static long F_26 ( struct V_5 * V_22 ,
struct V_66 T_1 * V_101 )
{
struct V_66 V_102 ;
int V_65 ;
if ( F_11 ( & V_102 , V_101 , sizeof( V_102 ) ) )
return - V_20 ;
V_65 = F_20 ( V_22 , & V_102 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( F_6 ( V_101 , & V_102 , sizeof( * V_101 ) ) )
return - V_20 ;
return 0 ;
}
static long F_27 ( struct V_3 * V_4 , unsigned int V_103 ,
unsigned long V_1 )
{
struct V_104 * V_90 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_29 ( V_90 ) ;
long V_65 ;
F_30 ( & V_6 -> V_105 ) ;
switch ( V_103 ) {
case V_106 :
V_65 = F_4 ( V_6 ,
(struct V_7 T_1 * ) V_1 ) ;
break;
case V_107 :
V_65 = F_10 ( V_6 ,
(struct V_27 T_1 * ) V_1 ) ;
break;
case V_108 :
V_65 = F_16 ( V_6 ,
(struct V_51 T_1 * ) V_1 ) ;
break;
case V_109 :
V_65 = F_17 ( V_6 ,
(struct V_56 T_1 * ) V_1 ) ;
break;
case V_110 :
V_65 = F_26 ( V_6 ,
(struct V_66 T_1 * ) V_1 ) ;
break;
default:
V_65 = - V_111 ;
}
F_31 ( & V_6 -> V_105 ) ;
return V_65 ;
}
static long F_32 ( struct V_5 * V_22 ,
struct V_112 T_1 * V_61 )
{
struct V_51 V_38 ;
T_4 V_113 , V_114 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
if ( F_33 ( V_38 . V_24 , & V_61 -> V_24 )
|| F_33 ( V_113 , & V_61 -> V_36 )
|| F_33 ( V_114 , & V_61 -> V_38 ) )
return - V_20 ;
V_38 . V_36 = F_34 ( V_113 ) ;
V_38 . V_38 = F_34 ( V_114 ) ;
return F_14 ( V_22 , & V_38 ) ;
}
static long F_35 ( struct V_3 * V_4 , unsigned int V_103 ,
unsigned long V_1 )
{
struct V_104 * V_90 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_29 ( V_90 ) ;
long V_65 ;
switch ( V_103 ) {
case V_115 :
F_30 ( & V_6 -> V_105 ) ;
V_65 = F_32 ( V_6 ,
(struct V_112 T_1 * ) V_1 ) ;
F_31 ( & V_6 -> V_105 ) ;
break;
default:
return F_27 ( V_4 , V_103 , V_1 ) ;
}
return V_65 ;
}
static T_5 F_36 ( struct V_116 * V_117 ,
struct V_118 * V_119 , char * V_120 )
{
struct V_5 * V_22 = F_29 ( F_37 ( V_117 ) ) ;
return sprintf ( V_120 , L_1 , ( int ) sizeof( V_22 -> V_13 ) , V_22 -> V_13 ) ;
}
static void F_38 ( struct V_104 * V_22 )
{
F_39 ( V_22 -> V_121 , L_2 ) ;
}
int T_6 F_40 ( struct V_5 * V_22 ,
struct V_21 * V_24 )
{
struct V_122 * V_123 , * V_25 ;
unsigned int V_79 ;
int V_65 ;
if ( V_24 -> V_32 == V_43 ||
V_24 -> V_32 == V_124 )
F_41 ( V_22 -> V_6 ,
L_3 ,
V_24 -> V_12 ) ;
F_42 ( V_24 -> V_84 . V_22 != NULL ) ;
V_24 -> V_84 . V_22 = V_22 ;
F_43 ( & V_24 -> V_38 ) ;
V_24 -> V_39 = 0 ;
V_24 -> V_40 = 0 ;
if ( ! F_44 ( & V_22 -> V_125 , V_126 ) )
return - V_127 ;
F_30 ( & V_22 -> V_105 ) ;
V_65 = F_45 ( & V_22 -> V_125 , 1 ,
& V_24 -> V_128 ) ;
if ( V_65 < 0 ) {
F_31 ( & V_22 -> V_105 ) ;
return V_65 ;
}
V_22 -> V_129 =
F_46 ( V_22 -> V_129 , V_24 -> V_128 ) ;
F_47 ( V_22 , V_130 , & V_24 -> V_84 ) ;
for ( V_79 = 0 ; V_79 < V_24 -> V_37 ; V_79 ++ )
F_47 ( V_22 , V_131 ,
& V_24 -> V_36 [ V_79 ] . V_84 ) ;
F_48 (notify, next, &mdev->entity_notify, list) {
( V_123 ) -> V_123 ( V_24 , V_123 -> V_132 ) ;
}
if ( V_22 -> V_129
>= V_22 -> V_133 . V_134 . V_135 ) {
struct V_136 V_137 = { . V_138 = 0 } ;
V_65 = F_49 ( & V_137 , V_22 ) ;
if ( V_65 ) {
F_31 ( & V_22 -> V_105 ) ;
return V_65 ;
}
F_50 ( & V_22 -> V_133 ) ;
V_22 -> V_133 = V_137 ;
}
F_31 ( & V_22 -> V_105 ) ;
return 0 ;
}
static void F_51 ( struct V_21 * V_24 )
{
struct V_5 * V_22 = V_24 -> V_84 . V_22 ;
struct V_54 * V_55 , * V_139 ;
struct V_68 * V_69 ;
unsigned int V_79 ;
F_52 ( & V_22 -> V_125 , V_24 -> V_128 ) ;
F_15 (intf, &mdev->interfaces, graph_obj.list) {
F_48 (link, tmp, &intf->links, list) {
if ( V_55 -> V_24 == V_24 )
F_53 ( V_55 ) ;
}
}
F_54 ( V_24 ) ;
for ( V_79 = 0 ; V_79 < V_24 -> V_37 ; V_79 ++ )
F_55 ( & V_24 -> V_36 [ V_79 ] . V_84 ) ;
F_55 ( & V_24 -> V_84 ) ;
V_24 -> V_84 . V_22 = NULL ;
}
void F_56 ( struct V_21 * V_24 )
{
struct V_5 * V_22 = V_24 -> V_84 . V_22 ;
if ( V_22 == NULL )
return;
F_30 ( & V_22 -> V_105 ) ;
F_51 ( V_24 ) ;
F_31 ( & V_22 -> V_105 ) ;
}
void F_57 ( struct V_5 * V_22 )
{
F_43 ( & V_22 -> V_140 ) ;
F_43 ( & V_22 -> V_141 ) ;
F_43 ( & V_22 -> V_36 ) ;
F_43 ( & V_22 -> V_38 ) ;
F_43 ( & V_22 -> V_142 ) ;
F_58 ( & V_22 -> V_105 ) ;
F_59 ( & V_22 -> V_125 ) ;
F_39 ( V_22 -> V_6 , L_4 ) ;
}
void F_60 ( struct V_5 * V_22 )
{
F_61 ( & V_22 -> V_125 ) ;
V_22 -> V_129 = 0 ;
F_50 ( & V_22 -> V_133 ) ;
F_62 ( & V_22 -> V_105 ) ;
}
int T_6 F_63 ( struct V_5 * V_22 ,
struct V_143 * V_144 )
{
int V_65 ;
V_22 -> V_90 . V_145 = & V_146 ;
V_22 -> V_90 . V_121 = V_22 -> V_6 ;
V_22 -> V_90 . V_147 = F_38 ;
V_22 -> V_80 = 0 ;
V_65 = F_64 ( & V_22 -> V_90 , V_144 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_65 ( & V_22 -> V_90 . V_6 , & V_148 ) ;
if ( V_65 < 0 ) {
F_66 ( & V_22 -> V_90 ) ;
return V_65 ;
}
F_39 ( V_22 -> V_6 , L_5 ) ;
return 0 ;
}
int T_6 F_67 ( struct V_5 * V_22 ,
struct V_122 * V_149 )
{
F_30 ( & V_22 -> V_105 ) ;
F_68 ( & V_149 -> V_150 , & V_22 -> V_142 ) ;
F_31 ( & V_22 -> V_105 ) ;
return 0 ;
}
static void F_69 ( struct V_5 * V_22 ,
struct V_122 * V_149 )
{
F_70 ( & V_149 -> V_150 ) ;
}
void F_71 ( struct V_5 * V_22 ,
struct V_122 * V_149 )
{
F_30 ( & V_22 -> V_105 ) ;
F_69 ( V_22 , V_149 ) ;
F_31 ( & V_22 -> V_105 ) ;
}
void F_72 ( struct V_5 * V_22 )
{
struct V_21 * V_24 ;
struct V_21 * V_25 ;
struct V_68 * V_69 , * V_151 ;
struct V_122 * V_123 , * V_152 ;
if ( V_22 == NULL )
return;
F_30 ( & V_22 -> V_105 ) ;
if ( ! F_73 ( & V_22 -> V_90 ) ) {
F_31 ( & V_22 -> V_105 ) ;
return;
}
F_48 (entity, next, &mdev->entities, graph_obj.list)
F_51 ( V_24 ) ;
F_48 (notify, nextp, &mdev->entity_notify, list)
F_69 ( V_22 , V_123 ) ;
F_48 (intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
F_74 ( V_69 ) ;
F_55 ( & V_69 -> V_84 ) ;
F_75 ( V_69 ) ;
}
F_31 ( & V_22 -> V_105 ) ;
F_76 ( & V_22 -> V_90 . V_6 , & V_148 ) ;
F_39 ( V_22 -> V_6 , L_6 ) ;
F_66 ( & V_22 -> V_90 ) ;
}
static void F_77 ( struct V_116 * V_6 , void * V_153 )
{
}
struct V_5 * F_78 ( struct V_116 * V_6 )
{
struct V_5 * V_22 ;
V_22 = F_79 ( V_6 , F_77 , NULL , NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_80 ( F_77 ,
sizeof( struct V_5 ) , V_126 ) ;
if ( ! V_22 )
return NULL ;
return F_81 ( V_6 , V_22 , NULL , NULL ) ;
}
struct V_5 * F_82 ( struct V_116 * V_6 )
{
return F_79 ( V_6 , F_77 , NULL , NULL ) ;
}
void F_83 ( struct V_5 * V_22 ,
struct V_154 * V_154 ,
const char * V_12 )
{
V_22 -> V_6 = & V_154 -> V_6 ;
if ( V_12 )
F_5 ( V_22 -> V_13 , V_12 , sizeof( V_22 -> V_13 ) ) ;
else
F_5 ( V_22 -> V_13 , F_84 ( V_154 ) , sizeof( V_22 -> V_13 ) ) ;
sprintf ( V_22 -> V_15 , L_7 , F_84 ( V_154 ) ) ;
V_22 -> V_18 = ( V_154 -> V_155 << 16 )
| V_154 -> V_156 ;
V_22 -> V_19 = V_157 ;
F_57 ( V_22 ) ;
}
void F_85 ( struct V_5 * V_22 ,
struct V_158 * V_159 ,
const char * V_160 ,
const char * V_10 )
{
V_22 -> V_6 = & V_159 -> V_6 ;
if ( V_10 )
F_5 ( V_22 -> V_10 , V_10 ,
sizeof( V_22 -> V_10 ) ) ;
if ( V_160 )
F_5 ( V_22 -> V_13 , V_160 , sizeof( V_22 -> V_13 ) ) ;
else if ( V_159 -> V_161 )
F_5 ( V_22 -> V_13 , V_159 -> V_161 , sizeof( V_22 -> V_13 ) ) ;
else
F_5 ( V_22 -> V_13 , L_8 , sizeof( V_22 -> V_13 ) ) ;
if ( V_159 -> V_14 )
F_5 ( V_22 -> V_14 , V_159 -> V_14 , sizeof( V_22 -> V_14 ) ) ;
F_86 ( V_159 , V_22 -> V_15 , sizeof( V_22 -> V_15 ) ) ;
V_22 -> V_18 = F_87 ( V_159 -> V_162 . V_163 ) ;
V_22 -> V_19 = V_157 ;
F_57 ( V_22 ) ;
}
