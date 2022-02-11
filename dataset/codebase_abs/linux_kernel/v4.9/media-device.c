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
struct V_7 * V_8 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
if ( V_6 -> V_9 [ 0 ] )
F_5 ( V_8 -> V_10 , V_6 -> V_9 , sizeof( V_8 -> V_10 ) ) ;
else
F_5 ( V_8 -> V_10 , V_6 -> V_6 -> V_10 -> V_11 ,
sizeof( V_8 -> V_10 ) ) ;
F_5 ( V_8 -> V_12 , V_6 -> V_12 , sizeof( V_8 -> V_12 ) ) ;
F_5 ( V_8 -> V_13 , V_6 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
F_5 ( V_8 -> V_14 , V_6 -> V_14 , sizeof( V_8 -> V_14 ) ) ;
V_8 -> V_15 = V_16 ;
V_8 -> V_17 = V_6 -> V_17 ;
V_8 -> V_18 = V_6 -> V_18 ;
return 0 ;
}
static struct V_19 * F_6 ( struct V_5 * V_20 , T_3 V_21 )
{
struct V_19 * V_22 ;
int V_23 = V_21 & V_24 ;
V_21 &= ~ V_24 ;
F_7 (entity, mdev) {
if ( ( ( F_8 ( V_22 ) == V_21 ) && ! V_23 ) ||
( ( F_8 ( V_22 ) > V_21 ) && V_23 ) ) {
return V_22 ;
}
}
return NULL ;
}
static long F_9 ( struct V_5 * V_20 ,
struct V_25 * V_26 )
{
struct V_19 * V_27 ;
V_27 = F_6 ( V_20 , V_26 -> V_21 ) ;
if ( V_27 == NULL )
return - V_28 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_21 = F_8 ( V_27 ) ;
if ( V_27 -> V_11 )
F_5 ( V_26 -> V_11 , V_27 -> V_11 , sizeof( V_26 -> V_11 ) ) ;
V_26 -> type = V_27 -> V_29 ;
V_26 -> V_30 = 0 ;
V_26 -> V_31 = V_27 -> V_31 ;
V_26 -> V_32 = 0 ;
V_26 -> V_33 = V_27 -> V_34 ;
V_26 -> V_35 = V_27 -> V_36 - V_27 -> V_37 ;
if ( V_27 -> V_29 < V_38 ||
V_27 -> V_29 > V_39 ) {
if ( F_10 ( V_27 ) )
V_26 -> type = V_40 ;
else if ( V_27 -> V_29 != V_41 )
V_26 -> type = V_39 ;
}
memcpy ( & V_26 -> V_42 , & V_27 -> V_8 , sizeof( V_27 -> V_8 ) ) ;
return 0 ;
}
static void F_11 ( const struct V_43 * V_44 ,
struct V_45 * V_46 )
{
V_46 -> V_22 = F_8 ( V_44 -> V_22 ) ;
V_46 -> V_47 = V_44 -> V_47 ;
V_46 -> V_31 = V_44 -> V_31 ;
}
static long F_12 ( struct V_5 * V_20 ,
struct V_48 * V_35 )
{
struct V_19 * V_22 ;
V_22 = F_6 ( V_20 , V_35 -> V_22 ) ;
if ( V_22 == NULL )
return - V_28 ;
if ( V_35 -> V_33 ) {
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_22 -> V_34 ; V_49 ++ ) {
struct V_45 V_50 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
F_11 ( & V_22 -> V_33 [ V_49 ] , & V_50 ) ;
if ( F_13 ( & V_35 -> V_33 [ V_49 ] , & V_50 , sizeof( V_50 ) ) )
return - V_51 ;
}
}
if ( V_35 -> V_35 ) {
struct V_52 * V_53 ;
struct V_54 T_1 * V_55 = V_35 -> V_35 ;
F_14 (link, &entity->links, list) {
struct V_54 V_56 ;
if ( V_53 -> V_57 -> V_22 != V_22 )
continue;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_11 ( V_53 -> V_57 ,
& V_56 . V_57 ) ;
F_11 ( V_53 -> V_58 ,
& V_56 . V_58 ) ;
V_56 . V_31 = V_53 -> V_31 ;
if ( F_13 ( V_55 , & V_56 ,
sizeof( * V_55 ) ) )
return - V_51 ;
V_55 ++ ;
}
}
return 0 ;
}
static long F_15 ( struct V_5 * V_20 ,
struct V_54 * V_59 )
{
struct V_52 * V_53 = NULL ;
struct V_19 * V_57 ;
struct V_19 * V_58 ;
V_57 = F_6 ( V_20 , V_59 -> V_57 . V_22 ) ;
V_58 = F_6 ( V_20 , V_59 -> V_58 . V_22 ) ;
if ( V_57 == NULL || V_58 == NULL )
return - V_28 ;
if ( V_59 -> V_57 . V_47 >= V_57 -> V_34 ||
V_59 -> V_58 . V_47 >= V_58 -> V_34 )
return - V_28 ;
V_53 = F_16 ( & V_57 -> V_33 [ V_59 -> V_57 . V_47 ] ,
& V_58 -> V_33 [ V_59 -> V_58 . V_47 ] ) ;
if ( V_53 == NULL )
return - V_28 ;
return F_17 ( V_53 , V_59 -> V_31 ) ;
}
static long F_18 ( struct V_5 * V_20 ,
struct V_60 * V_61 )
{
struct V_19 * V_22 ;
struct V_62 * V_63 ;
struct V_43 * V_50 ;
struct V_52 * V_53 ;
struct V_64 V_65 , T_1 * V_66 ;
struct V_67 V_68 , T_1 * V_69 ;
struct V_70 V_44 , T_1 * V_46 ;
struct V_71 V_72 , T_1 * V_73 ;
unsigned int V_74 ;
int V_75 = 0 ;
V_61 -> V_76 = V_20 -> V_76 ;
V_74 = 0 ;
V_66 = F_1 ( V_61 -> V_77 ) ;
F_7 (entity, mdev) {
V_74 ++ ;
if ( V_75 || ! V_66 )
continue;
if ( V_74 > V_61 -> V_78 ) {
V_75 = - V_79 ;
continue;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_21 = V_22 -> V_80 . V_21 ;
V_65 . V_29 = V_22 -> V_29 ;
strncpy ( V_65 . V_11 , V_22 -> V_11 ,
sizeof( V_65 . V_11 ) ) ;
if ( F_13 ( V_66 , & V_65 , sizeof( V_65 ) ) )
V_75 = - V_51 ;
V_66 ++ ;
}
V_61 -> V_78 = V_74 ;
V_74 = 0 ;
V_69 = F_1 ( V_61 -> V_81 ) ;
F_19 (intf, mdev) {
V_74 ++ ;
if ( V_75 || ! V_69 )
continue;
if ( V_74 > V_61 -> V_82 ) {
V_75 = - V_79 ;
continue;
}
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_21 = V_63 -> V_80 . V_21 ;
V_68 . V_83 = V_63 -> type ;
V_68 . V_31 = V_63 -> V_31 ;
if ( F_20 ( & V_63 -> V_80 ) == V_84 ) {
struct V_85 * V_86 ;
V_86 = F_21 ( V_63 ) ;
V_68 . V_86 . V_87 = V_86 -> V_87 ;
V_68 . V_86 . V_88 = V_86 -> V_88 ;
}
if ( F_13 ( V_69 , & V_68 , sizeof( V_68 ) ) )
V_75 = - V_51 ;
V_69 ++ ;
}
V_61 -> V_82 = V_74 ;
V_74 = 0 ;
V_46 = F_1 ( V_61 -> V_89 ) ;
F_22 (pad, mdev) {
V_74 ++ ;
if ( V_75 || ! V_46 )
continue;
if ( V_74 > V_61 -> V_34 ) {
V_75 = - V_79 ;
continue;
}
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_21 = V_50 -> V_80 . V_21 ;
V_44 . V_90 = V_50 -> V_22 -> V_80 . V_21 ;
V_44 . V_31 = V_50 -> V_31 ;
if ( F_13 ( V_46 , & V_44 , sizeof( V_44 ) ) )
V_75 = - V_51 ;
V_46 ++ ;
}
V_61 -> V_34 = V_74 ;
V_74 = 0 ;
V_73 = F_1 ( V_61 -> V_91 ) ;
F_23 (link, mdev) {
if ( V_53 -> V_92 )
continue;
V_74 ++ ;
if ( V_75 || ! V_73 )
continue;
if ( V_74 > V_61 -> V_36 ) {
V_75 = - V_79 ;
continue;
}
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_21 = V_53 -> V_80 . V_21 ;
V_72 . V_93 = V_53 -> V_94 -> V_21 ;
V_72 . V_95 = V_53 -> V_96 -> V_21 ;
V_72 . V_31 = V_53 -> V_31 ;
if ( F_13 ( V_73 , & V_72 , sizeof( V_72 ) ) )
V_75 = - V_51 ;
V_73 ++ ;
}
V_61 -> V_36 = V_74 ;
return V_75 ;
}
static long F_24 ( void * V_97 , void T_1 * V_98 , unsigned int V_99 )
{
if ( F_25 ( V_97 , V_98 , F_26 ( V_99 ) ) )
return - V_51 ;
return 0 ;
}
static long F_27 ( void T_1 * V_98 , void * V_97 , unsigned int V_99 )
{
if ( F_13 ( V_98 , V_97 , F_26 ( V_99 ) ) )
return - V_51 ;
return 0 ;
}
static long F_28 ( struct V_3 * V_4 , unsigned int V_99 ,
unsigned long V_100 )
{
struct V_101 * V_86 = F_29 ( V_4 ) ;
struct V_5 * V_6 = V_86 -> V_102 ;
const struct V_103 * V_8 ;
void T_1 * V_1 = ( void T_1 * ) V_100 ;
char V_104 [ 256 ] , * V_97 = V_104 ;
long V_75 ;
if ( F_30 ( V_99 ) >= F_31 ( V_105 )
|| V_105 [ F_30 ( V_99 ) ] . V_99 != V_99 )
return - V_106 ;
V_8 = & V_105 [ F_30 ( V_99 ) ] ;
if ( F_26 ( V_8 -> V_99 ) > sizeof( V_104 ) ) {
V_97 = F_32 ( F_26 ( V_8 -> V_99 ) , V_107 ) ;
if ( ! V_97 )
return - V_108 ;
}
if ( V_8 -> V_109 ) {
V_75 = V_8 -> V_109 ( V_97 , V_1 , V_99 ) ;
if ( V_75 )
goto V_110;
}
if ( V_8 -> V_31 & V_111 )
F_33 ( & V_6 -> V_112 ) ;
V_75 = V_8 -> V_113 ( V_6 , V_97 ) ;
if ( V_8 -> V_31 & V_111 )
F_34 ( & V_6 -> V_112 ) ;
if ( ! V_75 && V_8 -> V_114 )
V_75 = V_8 -> V_114 ( V_1 , V_97 , V_99 ) ;
V_110:
if ( V_97 != V_104 )
F_35 ( V_97 ) ;
return V_75 ;
}
static long F_36 ( struct V_5 * V_20 ,
struct V_115 T_1 * V_116 )
{
struct V_48 V_35 ;
T_4 V_117 , V_118 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
if ( F_37 ( V_35 . V_22 , & V_116 -> V_22 )
|| F_37 ( V_117 , & V_116 -> V_33 )
|| F_37 ( V_118 , & V_116 -> V_35 ) )
return - V_51 ;
V_35 . V_33 = F_38 ( V_117 ) ;
V_35 . V_35 = F_38 ( V_118 ) ;
return F_12 ( V_20 , & V_35 ) ;
}
static long F_39 ( struct V_3 * V_4 , unsigned int V_99 ,
unsigned long V_1 )
{
struct V_101 * V_86 = F_29 ( V_4 ) ;
struct V_5 * V_6 = V_86 -> V_102 ;
long V_75 ;
switch ( V_99 ) {
case V_119 :
F_33 ( & V_6 -> V_112 ) ;
V_75 = F_36 ( V_6 ,
(struct V_115 T_1 * ) V_1 ) ;
F_34 ( & V_6 -> V_112 ) ;
break;
default:
return F_28 ( V_4 , V_99 , V_1 ) ;
}
return V_75 ;
}
static T_5 F_40 ( struct V_120 * V_121 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_101 * V_86 = F_41 ( V_121 ) ;
struct V_5 * V_20 = V_86 -> V_102 ;
return sprintf ( V_124 , L_1 , ( int ) sizeof( V_20 -> V_12 ) , V_20 -> V_12 ) ;
}
static void F_42 ( struct V_101 * V_20 )
{
F_43 ( V_20 -> V_125 , L_2 ) ;
}
int T_6 F_44 ( struct V_5 * V_20 ,
struct V_19 * V_22 )
{
struct V_126 * V_127 , * V_23 ;
unsigned int V_74 ;
int V_75 ;
if ( V_22 -> V_29 == V_40 ||
V_22 -> V_29 == V_128 )
F_45 ( V_20 -> V_6 ,
L_3 ,
V_22 -> V_11 ) ;
F_46 ( V_22 -> V_80 . V_20 != NULL ) ;
V_22 -> V_80 . V_20 = V_20 ;
F_47 ( & V_22 -> V_35 ) ;
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
if ( ! F_48 ( & V_20 -> V_129 , V_107 ) )
return - V_108 ;
F_33 ( & V_20 -> V_112 ) ;
V_75 = F_49 ( & V_20 -> V_129 , 1 ,
& V_22 -> V_130 ) ;
if ( V_75 < 0 ) {
F_34 ( & V_20 -> V_112 ) ;
return V_75 ;
}
V_20 -> V_131 =
F_50 ( V_20 -> V_131 , V_22 -> V_130 ) ;
F_51 ( V_20 , V_132 , & V_22 -> V_80 ) ;
for ( V_74 = 0 ; V_74 < V_22 -> V_34 ; V_74 ++ )
F_51 ( V_20 , V_133 ,
& V_22 -> V_33 [ V_74 ] . V_80 ) ;
F_52 (notify, next, &mdev->entity_notify, list) {
( V_127 ) -> V_127 ( V_22 , V_127 -> V_134 ) ;
}
if ( V_20 -> V_131
>= V_20 -> V_135 . V_136 . V_137 ) {
struct V_138 V_139 = { . V_140 = 0 } ;
V_75 = F_53 ( & V_139 , V_20 ) ;
if ( V_75 ) {
F_34 ( & V_20 -> V_112 ) ;
return V_75 ;
}
F_54 ( & V_20 -> V_135 ) ;
V_20 -> V_135 = V_139 ;
}
F_34 ( & V_20 -> V_112 ) ;
return 0 ;
}
static void F_55 ( struct V_19 * V_22 )
{
struct V_5 * V_20 = V_22 -> V_80 . V_20 ;
struct V_52 * V_53 , * V_141 ;
struct V_62 * V_63 ;
unsigned int V_74 ;
F_56 ( & V_20 -> V_129 , V_22 -> V_130 ) ;
F_14 (intf, &mdev->interfaces, graph_obj.list) {
F_52 (link, tmp, &intf->links, list) {
if ( V_53 -> V_22 == V_22 )
F_57 ( V_53 ) ;
}
}
F_58 ( V_22 ) ;
for ( V_74 = 0 ; V_74 < V_22 -> V_34 ; V_74 ++ )
F_59 ( & V_22 -> V_33 [ V_74 ] . V_80 ) ;
F_59 ( & V_22 -> V_80 ) ;
V_22 -> V_80 . V_20 = NULL ;
}
void F_60 ( struct V_19 * V_22 )
{
struct V_5 * V_20 = V_22 -> V_80 . V_20 ;
if ( V_20 == NULL )
return;
F_33 ( & V_20 -> V_112 ) ;
F_55 ( V_22 ) ;
F_34 ( & V_20 -> V_112 ) ;
}
void F_61 ( struct V_5 * V_20 )
{
F_47 ( & V_20 -> V_142 ) ;
F_47 ( & V_20 -> V_143 ) ;
F_47 ( & V_20 -> V_33 ) ;
F_47 ( & V_20 -> V_35 ) ;
F_47 ( & V_20 -> V_144 ) ;
F_62 ( & V_20 -> V_112 ) ;
F_63 ( & V_20 -> V_129 ) ;
F_43 ( V_20 -> V_6 , L_4 ) ;
}
void F_64 ( struct V_5 * V_20 )
{
F_65 ( & V_20 -> V_129 ) ;
V_20 -> V_131 = 0 ;
F_54 ( & V_20 -> V_135 ) ;
F_66 ( & V_20 -> V_112 ) ;
}
int T_6 F_67 ( struct V_5 * V_20 ,
struct V_145 * V_146 )
{
struct V_101 * V_86 ;
int V_75 ;
V_86 = F_68 ( sizeof( * V_86 ) , V_107 ) ;
if ( ! V_86 )
return - V_108 ;
V_20 -> V_86 = V_86 ;
V_86 -> V_147 = & V_148 ;
V_86 -> V_125 = V_20 -> V_6 ;
V_86 -> V_149 = F_42 ;
V_20 -> V_76 = 0 ;
V_75 = F_69 ( V_20 , V_86 , V_146 ) ;
if ( V_75 < 0 ) {
V_20 -> V_86 = NULL ;
return V_75 ;
}
V_75 = F_70 ( & V_86 -> V_6 , & V_150 ) ;
if ( V_75 < 0 ) {
V_20 -> V_86 = NULL ;
F_71 ( V_86 ) ;
F_72 ( V_86 ) ;
return V_75 ;
}
F_43 ( V_20 -> V_6 , L_5 ) ;
return 0 ;
}
int T_6 F_73 ( struct V_5 * V_20 ,
struct V_126 * V_151 )
{
F_33 ( & V_20 -> V_112 ) ;
F_74 ( & V_151 -> V_152 , & V_20 -> V_144 ) ;
F_34 ( & V_20 -> V_112 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_20 ,
struct V_126 * V_151 )
{
F_76 ( & V_151 -> V_152 ) ;
}
void F_77 ( struct V_5 * V_20 ,
struct V_126 * V_151 )
{
F_33 ( & V_20 -> V_112 ) ;
F_75 ( V_20 , V_151 ) ;
F_34 ( & V_20 -> V_112 ) ;
}
void F_78 ( struct V_5 * V_20 )
{
struct V_19 * V_22 ;
struct V_19 * V_23 ;
struct V_62 * V_63 , * V_153 ;
struct V_126 * V_127 , * V_154 ;
if ( V_20 == NULL )
return;
F_33 ( & V_20 -> V_112 ) ;
if ( ! F_79 ( V_20 -> V_86 ) ) {
F_34 ( & V_20 -> V_112 ) ;
return;
}
F_71 ( V_20 -> V_86 ) ;
F_52 (entity, next, &mdev->entities, graph_obj.list)
F_55 ( V_22 ) ;
F_52 (notify, nextp, &mdev->entity_notify, list)
F_75 ( V_20 , V_127 ) ;
F_52 (intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
F_80 ( V_63 ) ;
F_59 ( & V_63 -> V_80 ) ;
F_35 ( V_63 ) ;
}
F_34 ( & V_20 -> V_112 ) ;
F_43 ( V_20 -> V_6 , L_6 ) ;
F_81 ( & V_20 -> V_86 -> V_6 , & V_150 ) ;
F_72 ( V_20 -> V_86 ) ;
V_20 -> V_86 = NULL ;
}
static void F_82 ( struct V_120 * V_6 , void * V_155 )
{
}
struct V_5 * F_83 ( struct V_120 * V_6 )
{
struct V_5 * V_20 ;
V_20 = F_84 ( V_6 , F_82 , NULL , NULL ) ;
if ( V_20 )
return V_20 ;
V_20 = F_85 ( F_82 ,
sizeof( struct V_5 ) , V_107 ) ;
if ( ! V_20 )
return NULL ;
return F_86 ( V_6 , V_20 , NULL , NULL ) ;
}
struct V_5 * F_87 ( struct V_120 * V_6 )
{
return F_84 ( V_6 , F_82 , NULL , NULL ) ;
}
void F_88 ( struct V_5 * V_20 ,
struct V_156 * V_156 ,
const char * V_11 )
{
V_20 -> V_6 = & V_156 -> V_6 ;
if ( V_11 )
F_5 ( V_20 -> V_12 , V_11 , sizeof( V_20 -> V_12 ) ) ;
else
F_5 ( V_20 -> V_12 , F_89 ( V_156 ) , sizeof( V_20 -> V_12 ) ) ;
sprintf ( V_20 -> V_14 , L_7 , F_89 ( V_156 ) ) ;
V_20 -> V_17 = ( V_156 -> V_157 << 16 )
| V_156 -> V_158 ;
V_20 -> V_18 = V_159 ;
F_61 ( V_20 ) ;
}
void F_90 ( struct V_5 * V_20 ,
struct V_160 * V_161 ,
const char * V_162 ,
const char * V_9 )
{
V_20 -> V_6 = & V_161 -> V_6 ;
if ( V_9 )
F_5 ( V_20 -> V_9 , V_9 ,
sizeof( V_20 -> V_9 ) ) ;
if ( V_162 )
F_5 ( V_20 -> V_12 , V_162 , sizeof( V_20 -> V_12 ) ) ;
else if ( V_161 -> V_163 )
F_5 ( V_20 -> V_12 , V_161 -> V_163 , sizeof( V_20 -> V_12 ) ) ;
else
F_5 ( V_20 -> V_12 , L_8 , sizeof( V_20 -> V_12 ) ) ;
if ( V_161 -> V_13 )
F_5 ( V_20 -> V_13 , V_161 -> V_13 , sizeof( V_20 -> V_13 ) ) ;
F_91 ( V_161 , V_20 -> V_14 , sizeof( V_20 -> V_14 ) ) ;
V_20 -> V_17 = F_92 ( V_161 -> V_164 . V_165 ) ;
V_20 -> V_18 = V_159 ;
F_61 ( V_20 ) ;
}
