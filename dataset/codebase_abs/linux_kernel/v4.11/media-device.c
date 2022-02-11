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
V_26 -> type = V_42 ;
}
memcpy ( & V_26 -> V_43 , & V_27 -> V_8 , sizeof( V_27 -> V_8 ) ) ;
return 0 ;
}
static void F_11 ( const struct V_44 * V_45 ,
struct V_46 * V_47 )
{
V_47 -> V_22 = F_8 ( V_45 -> V_22 ) ;
V_47 -> V_48 = V_45 -> V_48 ;
V_47 -> V_31 = V_45 -> V_31 ;
}
static long F_12 ( struct V_5 * V_20 ,
struct V_49 * V_35 )
{
struct V_19 * V_22 ;
V_22 = F_6 ( V_20 , V_35 -> V_22 ) ;
if ( V_22 == NULL )
return - V_28 ;
if ( V_35 -> V_33 ) {
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_22 -> V_34 ; V_50 ++ ) {
struct V_46 V_51 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_11 ( & V_22 -> V_33 [ V_50 ] , & V_51 ) ;
if ( F_13 ( & V_35 -> V_33 [ V_50 ] , & V_51 , sizeof( V_51 ) ) )
return - V_52 ;
}
}
if ( V_35 -> V_35 ) {
struct V_53 * V_54 ;
struct V_55 T_1 * V_56 = V_35 -> V_35 ;
F_14 (link, &entity->links, list) {
struct V_55 V_57 ;
if ( V_54 -> V_58 -> V_22 != V_22 )
continue;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
F_11 ( V_54 -> V_58 ,
& V_57 . V_58 ) ;
F_11 ( V_54 -> V_59 ,
& V_57 . V_59 ) ;
V_57 . V_31 = V_54 -> V_31 ;
if ( F_13 ( V_56 , & V_57 ,
sizeof( * V_56 ) ) )
return - V_52 ;
V_56 ++ ;
}
}
return 0 ;
}
static long F_15 ( struct V_5 * V_20 ,
struct V_55 * V_60 )
{
struct V_53 * V_54 = NULL ;
struct V_19 * V_58 ;
struct V_19 * V_59 ;
V_58 = F_6 ( V_20 , V_60 -> V_58 . V_22 ) ;
V_59 = F_6 ( V_20 , V_60 -> V_59 . V_22 ) ;
if ( V_58 == NULL || V_59 == NULL )
return - V_28 ;
if ( V_60 -> V_58 . V_48 >= V_58 -> V_34 ||
V_60 -> V_59 . V_48 >= V_59 -> V_34 )
return - V_28 ;
V_54 = F_16 ( & V_58 -> V_33 [ V_60 -> V_58 . V_48 ] ,
& V_59 -> V_33 [ V_60 -> V_59 . V_48 ] ) ;
if ( V_54 == NULL )
return - V_28 ;
return F_17 ( V_54 , V_60 -> V_31 ) ;
}
static long F_18 ( struct V_5 * V_20 ,
struct V_61 * V_62 )
{
struct V_19 * V_22 ;
struct V_63 * V_64 ;
struct V_44 * V_51 ;
struct V_53 * V_54 ;
struct V_65 V_66 , T_1 * V_67 ;
struct V_68 V_69 , T_1 * V_70 ;
struct V_71 V_45 , T_1 * V_47 ;
struct V_72 V_73 , T_1 * V_74 ;
unsigned int V_75 ;
int V_76 = 0 ;
V_62 -> V_77 = V_20 -> V_77 ;
V_75 = 0 ;
V_67 = F_1 ( V_62 -> V_78 ) ;
F_7 (entity, mdev) {
V_75 ++ ;
if ( V_76 || ! V_67 )
continue;
if ( V_75 > V_62 -> V_79 ) {
V_76 = - V_80 ;
continue;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_21 = V_22 -> V_81 . V_21 ;
V_66 . V_29 = V_22 -> V_29 ;
strncpy ( V_66 . V_11 , V_22 -> V_11 ,
sizeof( V_66 . V_11 ) ) ;
if ( F_13 ( V_67 , & V_66 , sizeof( V_66 ) ) )
V_76 = - V_52 ;
V_67 ++ ;
}
V_62 -> V_79 = V_75 ;
V_75 = 0 ;
V_70 = F_1 ( V_62 -> V_82 ) ;
F_19 (intf, mdev) {
V_75 ++ ;
if ( V_76 || ! V_70 )
continue;
if ( V_75 > V_62 -> V_83 ) {
V_76 = - V_80 ;
continue;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_21 = V_64 -> V_81 . V_21 ;
V_69 . V_84 = V_64 -> type ;
V_69 . V_31 = V_64 -> V_31 ;
if ( F_20 ( & V_64 -> V_81 ) == V_85 ) {
struct V_86 * V_87 ;
V_87 = F_21 ( V_64 ) ;
V_69 . V_87 . V_88 = V_87 -> V_88 ;
V_69 . V_87 . V_89 = V_87 -> V_89 ;
}
if ( F_13 ( V_70 , & V_69 , sizeof( V_69 ) ) )
V_76 = - V_52 ;
V_70 ++ ;
}
V_62 -> V_83 = V_75 ;
V_75 = 0 ;
V_47 = F_1 ( V_62 -> V_90 ) ;
F_22 (pad, mdev) {
V_75 ++ ;
if ( V_76 || ! V_47 )
continue;
if ( V_75 > V_62 -> V_34 ) {
V_76 = - V_80 ;
continue;
}
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_21 = V_51 -> V_81 . V_21 ;
V_45 . V_91 = V_51 -> V_22 -> V_81 . V_21 ;
V_45 . V_31 = V_51 -> V_31 ;
if ( F_13 ( V_47 , & V_45 , sizeof( V_45 ) ) )
V_76 = - V_52 ;
V_47 ++ ;
}
V_62 -> V_34 = V_75 ;
V_75 = 0 ;
V_74 = F_1 ( V_62 -> V_92 ) ;
F_23 (link, mdev) {
if ( V_54 -> V_93 )
continue;
V_75 ++ ;
if ( V_76 || ! V_74 )
continue;
if ( V_75 > V_62 -> V_36 ) {
V_76 = - V_80 ;
continue;
}
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_21 = V_54 -> V_81 . V_21 ;
V_73 . V_94 = V_54 -> V_95 -> V_21 ;
V_73 . V_96 = V_54 -> V_97 -> V_21 ;
V_73 . V_31 = V_54 -> V_31 ;
if ( F_13 ( V_74 , & V_73 , sizeof( V_73 ) ) )
V_76 = - V_52 ;
V_74 ++ ;
}
V_62 -> V_36 = V_75 ;
return V_76 ;
}
static long F_24 ( void * V_98 , void T_1 * V_99 , unsigned int V_100 )
{
if ( F_25 ( V_98 , V_99 , F_26 ( V_100 ) ) )
return - V_52 ;
return 0 ;
}
static long F_27 ( void T_1 * V_99 , void * V_98 , unsigned int V_100 )
{
if ( F_13 ( V_99 , V_98 , F_26 ( V_100 ) ) )
return - V_52 ;
return 0 ;
}
static long F_28 ( struct V_3 * V_4 , unsigned int V_100 ,
unsigned long V_101 )
{
struct V_102 * V_87 = F_29 ( V_4 ) ;
struct V_5 * V_6 = V_87 -> V_103 ;
const struct V_104 * V_8 ;
void T_1 * V_1 = ( void T_1 * ) V_101 ;
char V_105 [ 256 ] , * V_98 = V_105 ;
long V_76 ;
if ( F_30 ( V_100 ) >= F_31 ( V_106 )
|| V_106 [ F_30 ( V_100 ) ] . V_100 != V_100 )
return - V_107 ;
V_8 = & V_106 [ F_30 ( V_100 ) ] ;
if ( F_26 ( V_8 -> V_100 ) > sizeof( V_105 ) ) {
V_98 = F_32 ( F_26 ( V_8 -> V_100 ) , V_108 ) ;
if ( ! V_98 )
return - V_109 ;
}
if ( V_8 -> V_110 ) {
V_76 = V_8 -> V_110 ( V_98 , V_1 , V_100 ) ;
if ( V_76 )
goto V_111;
}
if ( V_8 -> V_31 & V_112 )
F_33 ( & V_6 -> V_113 ) ;
V_76 = V_8 -> V_114 ( V_6 , V_98 ) ;
if ( V_8 -> V_31 & V_112 )
F_34 ( & V_6 -> V_113 ) ;
if ( ! V_76 && V_8 -> V_115 )
V_76 = V_8 -> V_115 ( V_1 , V_98 , V_100 ) ;
V_111:
if ( V_98 != V_105 )
F_35 ( V_98 ) ;
return V_76 ;
}
static long F_36 ( struct V_5 * V_20 ,
struct V_116 T_1 * V_117 )
{
struct V_49 V_35 ;
T_4 V_118 , V_119 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
if ( F_37 ( V_35 . V_22 , & V_117 -> V_22 )
|| F_37 ( V_118 , & V_117 -> V_33 )
|| F_37 ( V_119 , & V_117 -> V_35 ) )
return - V_52 ;
V_35 . V_33 = F_38 ( V_118 ) ;
V_35 . V_35 = F_38 ( V_119 ) ;
return F_12 ( V_20 , & V_35 ) ;
}
static long F_39 ( struct V_3 * V_4 , unsigned int V_100 ,
unsigned long V_1 )
{
struct V_102 * V_87 = F_29 ( V_4 ) ;
struct V_5 * V_6 = V_87 -> V_103 ;
long V_76 ;
switch ( V_100 ) {
case V_120 :
F_33 ( & V_6 -> V_113 ) ;
V_76 = F_36 ( V_6 ,
(struct V_116 T_1 * ) V_1 ) ;
F_34 ( & V_6 -> V_113 ) ;
break;
default:
return F_28 ( V_4 , V_100 , V_1 ) ;
}
return V_76 ;
}
static T_5 F_40 ( struct V_121 * V_122 ,
struct V_123 * V_124 , char * V_125 )
{
struct V_102 * V_87 = F_41 ( V_122 ) ;
struct V_5 * V_20 = V_87 -> V_103 ;
return sprintf ( V_125 , L_1 , ( int ) sizeof( V_20 -> V_12 ) , V_20 -> V_12 ) ;
}
static void F_42 ( struct V_102 * V_20 )
{
F_43 ( V_20 -> V_126 , L_2 ) ;
}
int T_6 F_44 ( struct V_5 * V_20 ,
struct V_19 * V_22 )
{
struct V_127 * V_128 , * V_23 ;
unsigned int V_75 ;
int V_76 ;
if ( V_22 -> V_29 == V_40 ||
V_22 -> V_29 == V_129 )
F_45 ( V_20 -> V_6 ,
L_3 ,
V_22 -> V_11 ) ;
F_46 ( V_22 -> V_81 . V_20 != NULL ) ;
V_22 -> V_81 . V_20 = V_20 ;
F_47 ( & V_22 -> V_35 ) ;
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
if ( ! F_48 ( & V_20 -> V_130 , V_108 ) )
return - V_109 ;
F_33 ( & V_20 -> V_113 ) ;
V_76 = F_49 ( & V_20 -> V_130 , 1 ,
& V_22 -> V_131 ) ;
if ( V_76 < 0 ) {
F_34 ( & V_20 -> V_113 ) ;
return V_76 ;
}
V_20 -> V_132 =
F_50 ( V_20 -> V_132 , V_22 -> V_131 ) ;
F_51 ( V_20 , V_133 , & V_22 -> V_81 ) ;
for ( V_75 = 0 ; V_75 < V_22 -> V_34 ; V_75 ++ )
F_51 ( V_20 , V_134 ,
& V_22 -> V_33 [ V_75 ] . V_81 ) ;
F_52 (notify, next, &mdev->entity_notify, list) {
( V_128 ) -> V_128 ( V_22 , V_128 -> V_135 ) ;
}
if ( V_20 -> V_132
>= V_20 -> V_136 . V_137 . V_138 ) {
struct V_139 V_140 = { . V_141 = 0 } ;
V_76 = F_53 ( & V_140 , V_20 ) ;
if ( V_76 ) {
F_34 ( & V_20 -> V_113 ) ;
return V_76 ;
}
F_54 ( & V_20 -> V_136 ) ;
V_20 -> V_136 = V_140 ;
}
F_34 ( & V_20 -> V_113 ) ;
return 0 ;
}
static void F_55 ( struct V_19 * V_22 )
{
struct V_5 * V_20 = V_22 -> V_81 . V_20 ;
struct V_53 * V_54 , * V_142 ;
struct V_63 * V_64 ;
unsigned int V_75 ;
F_56 ( & V_20 -> V_130 , V_22 -> V_131 ) ;
F_14 (intf, &mdev->interfaces, graph_obj.list) {
F_52 (link, tmp, &intf->links, list) {
if ( V_54 -> V_22 == V_22 )
F_57 ( V_54 ) ;
}
}
F_58 ( V_22 ) ;
for ( V_75 = 0 ; V_75 < V_22 -> V_34 ; V_75 ++ )
F_59 ( & V_22 -> V_33 [ V_75 ] . V_81 ) ;
F_59 ( & V_22 -> V_81 ) ;
V_22 -> V_81 . V_20 = NULL ;
}
void F_60 ( struct V_19 * V_22 )
{
struct V_5 * V_20 = V_22 -> V_81 . V_20 ;
if ( V_20 == NULL )
return;
F_33 ( & V_20 -> V_113 ) ;
F_55 ( V_22 ) ;
F_34 ( & V_20 -> V_113 ) ;
}
void F_61 ( struct V_5 * V_20 )
{
F_47 ( & V_20 -> V_143 ) ;
F_47 ( & V_20 -> V_144 ) ;
F_47 ( & V_20 -> V_33 ) ;
F_47 ( & V_20 -> V_35 ) ;
F_47 ( & V_20 -> V_145 ) ;
F_62 ( & V_20 -> V_113 ) ;
F_63 ( & V_20 -> V_130 ) ;
F_43 ( V_20 -> V_6 , L_4 ) ;
}
void F_64 ( struct V_5 * V_20 )
{
F_65 ( & V_20 -> V_130 ) ;
V_20 -> V_132 = 0 ;
F_54 ( & V_20 -> V_136 ) ;
F_66 ( & V_20 -> V_113 ) ;
}
int T_6 F_67 ( struct V_5 * V_20 ,
struct V_146 * V_147 )
{
struct V_102 * V_87 ;
int V_76 ;
V_87 = F_68 ( sizeof( * V_87 ) , V_108 ) ;
if ( ! V_87 )
return - V_109 ;
V_20 -> V_87 = V_87 ;
V_87 -> V_148 = & V_149 ;
V_87 -> V_126 = V_20 -> V_6 ;
V_87 -> V_150 = F_42 ;
V_20 -> V_77 = 0 ;
V_76 = F_69 ( V_20 , V_87 , V_147 ) ;
if ( V_76 < 0 ) {
V_20 -> V_87 = NULL ;
return V_76 ;
}
V_76 = F_70 ( & V_87 -> V_6 , & V_151 ) ;
if ( V_76 < 0 ) {
V_20 -> V_87 = NULL ;
F_71 ( V_87 ) ;
F_72 ( V_87 ) ;
return V_76 ;
}
F_43 ( V_20 -> V_6 , L_5 ) ;
return 0 ;
}
int T_6 F_73 ( struct V_5 * V_20 ,
struct V_127 * V_152 )
{
F_33 ( & V_20 -> V_113 ) ;
F_74 ( & V_152 -> V_153 , & V_20 -> V_145 ) ;
F_34 ( & V_20 -> V_113 ) ;
return 0 ;
}
static void F_75 ( struct V_5 * V_20 ,
struct V_127 * V_152 )
{
F_76 ( & V_152 -> V_153 ) ;
}
void F_77 ( struct V_5 * V_20 ,
struct V_127 * V_152 )
{
F_33 ( & V_20 -> V_113 ) ;
F_75 ( V_20 , V_152 ) ;
F_34 ( & V_20 -> V_113 ) ;
}
void F_78 ( struct V_5 * V_20 )
{
struct V_19 * V_22 ;
struct V_19 * V_23 ;
struct V_63 * V_64 , * V_154 ;
struct V_127 * V_128 , * V_155 ;
if ( V_20 == NULL )
return;
F_33 ( & V_20 -> V_113 ) ;
if ( ! F_79 ( V_20 -> V_87 ) ) {
F_34 ( & V_20 -> V_113 ) ;
return;
}
F_71 ( V_20 -> V_87 ) ;
F_52 (entity, next, &mdev->entities, graph_obj.list)
F_55 ( V_22 ) ;
F_52 (notify, nextp, &mdev->entity_notify, list)
F_75 ( V_20 , V_128 ) ;
F_52 (intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
F_80 ( V_64 ) ;
F_59 ( & V_64 -> V_81 ) ;
}
F_34 ( & V_20 -> V_113 ) ;
F_43 ( V_20 -> V_6 , L_6 ) ;
F_81 ( & V_20 -> V_87 -> V_6 , & V_151 ) ;
F_72 ( V_20 -> V_87 ) ;
V_20 -> V_87 = NULL ;
}
void F_82 ( struct V_5 * V_20 ,
struct V_156 * V_156 ,
const char * V_11 )
{
V_20 -> V_6 = & V_156 -> V_6 ;
if ( V_11 )
F_5 ( V_20 -> V_12 , V_11 , sizeof( V_20 -> V_12 ) ) ;
else
F_5 ( V_20 -> V_12 , F_83 ( V_156 ) , sizeof( V_20 -> V_12 ) ) ;
sprintf ( V_20 -> V_14 , L_7 , F_83 ( V_156 ) ) ;
V_20 -> V_17 = ( V_156 -> V_157 << 16 )
| V_156 -> V_158 ;
V_20 -> V_18 = V_159 ;
F_61 ( V_20 ) ;
}
void F_84 ( struct V_5 * V_20 ,
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
F_85 ( V_161 , V_20 -> V_14 , sizeof( V_20 -> V_14 ) ) ;
V_20 -> V_17 = F_86 ( V_161 -> V_164 . V_165 ) ;
V_20 -> V_18 = V_159 ;
F_61 ( V_20 ) ;
}
