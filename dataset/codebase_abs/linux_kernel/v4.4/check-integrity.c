static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 . V_11 = 0 ;
V_2 -> V_10 . type = 0 ;
V_2 -> V_10 . V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = NULL ;
V_2 -> V_20 = NULL ;
V_2 -> V_21 . V_22 = NULL ;
F_2 ( & V_2 -> V_23 ) ;
F_2 ( & V_2 -> V_24 ) ;
F_2 ( & V_2 -> V_25 ) ;
F_2 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
}
static struct V_1 * F_3 ( void )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_29 ) ;
if ( NULL != V_2 )
F_1 ( V_2 ) ;
return V_2 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! ( NULL == V_2 || V_4 == V_2 -> V_3 ) ) ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_30 * V_31 )
{
V_31 -> V_3 = V_32 ;
V_31 -> V_33 = 1 ;
F_2 ( & V_31 -> V_34 ) ;
F_2 ( & V_31 -> V_35 ) ;
F_2 ( & V_31 -> V_23 ) ;
V_31 -> V_36 = NULL ;
V_31 -> V_37 = NULL ;
}
static struct V_30 * F_9 ( void )
{
struct V_30 * V_31 ;
V_31 = F_4 ( sizeof( * V_31 ) , V_29 ) ;
if ( NULL != V_31 )
F_8 ( V_31 ) ;
return V_31 ;
}
static void F_10 ( struct V_30 * V_31 )
{
F_6 ( ! ( NULL == V_31 || V_32 == V_31 -> V_3 ) ) ;
F_7 ( V_31 ) ;
}
static void F_11 ( struct V_38 * V_39 )
{
V_39 -> V_3 = V_40 ;
V_39 -> V_41 = NULL ;
V_39 -> V_42 = NULL ;
V_39 -> V_43 [ 0 ] = '\0' ;
F_2 ( & V_39 -> V_23 ) ;
V_39 -> V_44 = 0 ;
F_1 ( & V_39 -> V_45 ) ;
V_39 -> V_45 . V_15 = 1 ;
V_39 -> V_45 . V_5 = V_39 ;
}
static struct V_38 * F_12 ( void )
{
struct V_38 * V_39 ;
V_39 = F_4 ( sizeof( * V_39 ) , V_29 ) ;
if ( NULL != V_39 )
F_11 ( V_39 ) ;
return V_39 ;
}
static void F_13 ( struct V_38 * V_39 )
{
F_6 ( ! ( NULL == V_39 ||
V_40 == V_39 -> V_3 ) ) ;
F_7 ( V_39 ) ;
}
static void F_14 ( struct V_46 * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
F_2 ( V_47 -> V_50 + V_48 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( V_2 -> V_6 >> 16 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_2 -> V_5 -> V_41 ) ) ) &
( V_49 - 1 ) ;
F_16 ( & V_2 -> V_23 , V_47 -> V_50 + V_51 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_23 ) ;
}
static struct V_1 * F_19 (
struct V_53 * V_41 ,
T_1 V_6 ,
struct V_46 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( V_6 >> 16 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_41 ) ) ) &
( V_49 - 1 ) ;
struct V_54 * V_55 ;
F_20 (elem, h->table + hashval) {
struct V_1 * const V_2 =
F_21 ( V_55 , struct V_1 ,
V_23 ) ;
if ( V_2 -> V_5 -> V_41 == V_41 && V_2 -> V_6 == V_6 )
return V_2 ;
}
return NULL ;
}
static void F_22 (
struct V_56 * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 ++ )
F_2 ( V_47 -> V_50 + V_48 ) ;
}
static void F_23 (
struct V_30 * V_31 ,
struct V_56 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( V_31 -> V_36 -> V_6 >> 16 ) ) ^
( ( unsigned int ) ( V_31 -> V_37 -> V_6 >> 16 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_31 -> V_36 -> V_5 -> V_41 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_31 -> V_37 -> V_5 -> V_41 ) ) )
& ( V_57 - 1 ) ;
F_6 ( NULL == V_31 -> V_36 ) ;
F_6 ( NULL == V_31 -> V_37 ) ;
F_16 ( & V_31 -> V_23 , V_47 -> V_50 + V_51 ) ;
}
static void F_24 ( struct V_30 * V_31 )
{
F_18 ( & V_31 -> V_23 ) ;
}
static struct V_30 * F_25 (
struct V_53 * V_58 ,
T_1 V_59 ,
struct V_53 * V_60 ,
T_1 V_61 ,
struct V_56 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( V_59 >> 16 ) ) ^
( ( unsigned int ) ( V_61 >> 16 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_58 ) ) ^
( ( unsigned int ) ( ( V_52 ) V_60 ) ) ) &
( V_57 - 1 ) ;
struct V_54 * V_55 ;
F_20 (elem, h->table + hashval) {
struct V_30 * const V_31 =
F_21 ( V_55 , struct V_30 ,
V_23 ) ;
F_6 ( NULL == V_31 -> V_36 ) ;
F_6 ( NULL == V_31 -> V_37 ) ;
if ( V_31 -> V_36 -> V_5 -> V_41 == V_58 &&
V_31 -> V_36 -> V_6 == V_59 &&
V_31 -> V_37 -> V_5 -> V_41 == V_60 &&
V_31 -> V_37 -> V_6 == V_61 )
return V_31 ;
}
return NULL ;
}
static void F_26 (
struct V_62 * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_63 ; V_48 ++ )
F_2 ( V_47 -> V_50 + V_48 ) ;
}
static void F_27 (
struct V_38 * V_39 ,
struct V_62 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( ( V_52 ) V_39 -> V_41 ) ) &
( V_63 - 1 ) ) ;
F_16 ( & V_39 -> V_23 , V_47 -> V_50 + V_51 ) ;
}
static void F_28 ( struct V_38 * V_39 )
{
F_18 ( & V_39 -> V_23 ) ;
}
static struct V_38 * F_29 (
struct V_53 * V_41 ,
struct V_62 * V_47 )
{
const unsigned int V_51 =
( ( ( unsigned int ) ( ( V_52 ) V_41 ) ) &
( V_63 - 1 ) ) ;
struct V_54 * V_55 ;
F_20 (elem, h->table + hashval) {
struct V_38 * const V_39 =
F_21 ( V_55 , struct V_38 ,
V_23 ) ;
if ( V_39 -> V_41 == V_41 )
return V_39 ;
}
return NULL ;
}
static int F_30 ( struct V_64 * V_42 ,
struct V_65 * V_66 )
{
int V_67 = 0 ;
struct V_68 * V_69 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
struct V_38 * V_74 = NULL ;
int V_75 ;
F_6 ( NULL == V_42 ) ;
V_69 = F_4 ( sizeof( * V_69 ) , V_29 ) ;
if ( NULL == V_69 ) {
F_31 ( V_76 L_1 ) ;
return - V_77 ;
}
F_32 (device, dev_head, dev_list) {
int V_48 ;
struct V_38 * V_5 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_5 = F_33 ( V_73 -> V_41 ) ;
F_6 ( NULL == V_5 ) ;
for ( V_48 = 0 ; V_48 < V_78 ; V_48 ++ ) {
V_67 = F_34 (
V_42 , V_5 , V_73 , V_48 ,
& V_74 , V_69 ) ;
if ( 0 != V_67 && 0 == V_48 ) {
F_7 ( V_69 ) ;
return V_67 ;
}
}
}
if ( NULL == V_42 -> V_79 ) {
F_31 ( V_76 L_2 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_42 -> V_80 = F_35 ( V_69 ) ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_81 ;
int V_18 ;
T_1 V_82 ;
switch ( V_75 ) {
case 0 :
V_82 = F_36 ( V_69 ) ;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_3 , V_82 ) ;
break;
case 1 :
V_82 = F_37 ( V_69 ) ;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_4 , V_82 ) ;
break;
case 2 :
V_82 = F_38 ( V_69 ) ;
if ( 0 == V_82 )
continue;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_5 , V_82 ) ;
break;
}
V_81 =
F_39 ( V_42 -> V_85 -> V_86 ,
V_82 , V_42 -> V_87 ) ;
if ( V_42 -> V_83 & V_88 )
F_31 ( V_76 L_6 ,
V_82 , V_81 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
V_67 = F_40 ( V_42 , V_82 ,
V_42 -> V_87 ,
& V_91 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76 L_7
L_8
L_9 ,
V_82 , V_18 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_89 = F_19 (
V_91 . V_92 -> V_41 ,
V_91 . V_6 ,
& V_42 -> V_93 ) ;
F_6 ( NULL == V_89 ) ;
V_31 = F_25 (
V_91 . V_92 -> V_41 ,
V_91 . V_6 ,
V_42 -> V_79 -> V_5 ->
V_41 ,
V_42 -> V_79 -> V_6 ,
& V_42 -> V_94 ) ;
F_6 ( NULL == V_31 ) ;
V_67 = F_41 ( V_42 , & V_91 ) ;
if ( V_67 < ( int ) V_95 ) {
F_31 ( V_76
L_10 ,
V_91 . V_96 ) ;
F_42 ( & V_91 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_67 = F_43 ( V_42 ,
V_89 ,
& V_91 ,
V_97 + 3 , 1 ) ;
F_42 ( & V_91 ) ;
}
}
F_7 ( V_69 ) ;
return V_67 ;
}
static int F_34 (
struct V_64 * V_42 ,
struct V_38 * V_5 ,
struct V_72 * V_73 ,
int V_98 ,
struct V_38 * * V_74 ,
struct V_68 * V_69 )
{
struct V_68 * V_99 ;
T_1 V_6 ;
struct V_100 * V_101 ;
struct V_1 * V_102 ;
int V_75 ;
struct V_53 * const V_103 = V_73 -> V_41 ;
V_6 = F_44 ( V_98 ) ;
if ( V_6 + V_104 > V_73 -> V_105 )
return - 1 ;
V_101 = F_45 ( V_103 , V_6 / 4096 ,
V_104 ) ;
if ( NULL == V_101 )
return - 1 ;
V_99 = (struct V_68 * )
( V_101 -> V_106 + ( V_6 & 4095 ) ) ;
if ( F_46 ( V_99 ) != V_6 ||
F_47 ( V_99 ) != V_107 ||
memcmp ( V_73 -> V_108 , V_99 -> V_109 . V_108 , V_110 ) ||
F_48 ( V_99 ) != V_42 -> V_87 ||
F_49 ( V_99 ) != V_42 -> V_111 ) {
F_50 ( V_101 ) ;
return 0 ;
}
V_102 =
F_19 ( V_103 ,
V_6 ,
& V_42 -> V_93 ) ;
if ( NULL == V_102 ) {
V_102 = F_3 () ;
if ( NULL == V_102 ) {
F_31 ( V_76 L_1 ) ;
F_50 ( V_101 ) ;
return - 1 ;
}
V_102 -> V_6 = V_6 ;
V_102 -> V_5 = V_5 ;
V_102 -> V_7 = V_6 ;
V_102 -> V_8 = F_51 ( V_99 ) ;
V_102 -> V_13 = 1 ;
V_102 -> V_14 = 1 ;
V_102 -> V_15 = 1 ;
V_102 -> V_17 = 0 ;
V_102 -> V_18 = 1 + V_98 ;
if ( V_42 -> V_83 & V_112 )
F_52 ( V_73 -> V_113 -> V_86 ,
L_11 ,
V_103 ,
F_53 ( V_73 -> V_43 ) , V_6 ,
V_5 -> V_43 , V_6 ,
V_98 ) ;
F_16 ( & V_102 -> V_24 ,
& V_42 -> V_114 ) ;
F_15 ( V_102 ,
& V_42 -> V_93 ) ;
}
if ( F_51 ( V_99 ) >
V_42 -> V_115 ||
0 == V_42 -> V_115 ) {
memcpy ( V_69 , V_99 , sizeof( * V_69 ) ) ;
* V_74 = V_5 ;
V_42 -> V_115 =
F_51 ( V_99 ) ;
V_42 -> V_79 = V_102 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
T_1 V_82 ;
int V_81 ;
int V_18 ;
const char * V_116 = NULL ;
struct V_117 V_118 ;
V_118 . type = V_119 ;
V_118 . V_12 = 0 ;
switch ( V_75 ) {
case 0 :
F_54 ( & V_118 ,
V_120 ) ;
V_116 = L_12 ;
V_82 = F_36 ( V_99 ) ;
break;
case 1 :
F_54 ( & V_118 ,
V_121 ) ;
V_116 = L_13 ;
V_82 = F_37 ( V_99 ) ;
break;
case 2 :
F_54 ( & V_118 ,
V_122 ) ;
V_116 = L_14 ;
V_82 = F_38 ( V_99 ) ;
if ( 0 == V_82 )
continue;
break;
}
V_81 =
F_39 ( V_42 -> V_85 -> V_86 ,
V_82 , V_42 -> V_87 ) ;
if ( V_42 -> V_83 & V_88 )
F_31 ( V_76 L_6 ,
V_82 , V_81 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
if ( F_40 ( V_42 , V_82 ,
V_42 -> V_87 ,
& V_91 ,
V_18 ) ) {
F_31 ( V_76 L_15
L_16 ,
V_82 , V_18 ) ;
F_50 ( V_101 ) ;
return - 1 ;
}
V_89 = F_55 (
V_42 , & V_91 ,
V_116 , 1 , 1 , 0 ,
V_18 , NULL ) ;
if ( NULL == V_89 ) {
F_42 ( & V_91 ) ;
F_50 ( V_101 ) ;
return - 1 ;
}
V_89 -> V_10 = V_118 ;
V_89 -> V_8 = V_9 ;
V_31 = F_56 (
V_42 , & V_91 ,
V_89 , V_102 ,
V_9 ) ;
F_42 ( & V_91 ) ;
if ( NULL == V_31 ) {
F_50 ( V_101 ) ;
return - 1 ;
}
}
}
if ( V_42 -> V_83 & V_123 )
F_57 ( V_42 , V_102 , 0 ) ;
F_50 ( V_101 ) ;
return 0 ;
}
static struct V_124 * F_58 ( void )
{
struct V_124 * V_125 ;
V_125 = F_4 ( sizeof( * V_125 ) , V_29 ) ;
if ( NULL == V_125 )
F_31 ( V_76 L_17 ) ;
else
V_125 -> V_126 = V_127 ;
return V_125 ;
}
static void F_59 ( struct V_124 * V_125 )
{
F_6 ( ! ( NULL == V_125 ||
V_127 == V_125 -> V_126 ) ) ;
F_7 ( V_125 ) ;
}
static int F_43 (
struct V_64 * V_42 ,
struct V_1 * const V_128 ,
struct V_90 * const V_129 ,
int V_130 , int V_131 )
{
struct V_124 V_132 = { 0 } ;
struct V_124 * V_125 ;
struct V_124 * V_133 ;
struct V_134 * const V_135 =
(struct V_134 * ) V_129 -> V_136 [ 0 ] ;
F_6 ( ! V_135 ) ;
V_125 = & V_132 ;
V_125 -> error = 0 ;
V_125 -> V_48 = - 1 ;
V_125 -> V_137 = V_130 ;
V_125 -> V_138 = V_128 ;
V_125 -> V_139 = V_129 ;
V_125 -> V_89 = NULL ;
V_125 -> V_140 = V_135 ;
V_125 -> V_141 = NULL ;
V_142:
V_125 -> V_138 -> V_8 = F_60 ( V_125 -> V_140 -> V_8 ) ;
if ( 0 == V_125 -> V_140 -> V_143 ) {
struct V_144 * const V_145 =
(struct V_144 * ) V_125 -> V_140 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_146 = F_61 ( & V_145 -> V_147 ) ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_18
L_19 ,
V_125 -> V_139 -> V_96 , V_125 -> V_146 ,
F_62 (
& V_145 -> V_147 ) ,
F_63 (
& V_145 -> V_147 ) ) ;
}
V_149:
if ( 0 == V_125 -> V_81 || V_125 -> V_18 > V_125 -> V_81 ) {
V_125 -> V_48 ++ ;
V_125 -> V_81 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_146 ) {
struct V_150 V_151 ;
T_2 V_152 =
( V_52 ) ( V_145 -> V_153 + V_125 -> V_48 ) -
( V_52 ) V_145 ;
struct V_117 * V_10 ;
T_3 type ;
T_2 V_154 ;
T_2 V_155 ;
if ( V_152 + sizeof( struct V_150 ) >
V_125 -> V_139 -> V_156 ) {
V_157:
F_31 ( V_76
L_20 ,
V_125 -> V_139 -> V_96 ,
V_125 -> V_139 -> V_92 -> V_43 ) ;
goto V_158;
}
F_64 ( V_125 -> V_139 ,
& V_151 ,
V_152 ,
sizeof( struct V_150 ) ) ;
V_154 = F_65 ( & V_151 ) ;
V_155 = F_66 ( & V_151 ) ;
V_10 = & V_151 . V_159 ;
type = F_67 ( V_10 ) ;
if ( V_119 == type ) {
struct V_160 V_161 ;
T_2 V_162 ;
T_1 V_82 ;
V_162 = V_154 +
F_68 ( struct V_144 , V_153 ) ;
if ( V_162 + V_155 >
V_125 -> V_139 -> V_156 )
goto V_157;
F_64 (
V_125 -> V_139 , & V_161 ,
V_162 ,
V_155 ) ;
V_82 = F_69 ( & V_161 ) ;
V_125 -> error =
F_70 (
V_42 ,
V_125 -> V_138 ,
V_125 -> V_139 ,
V_82 ,
V_125 -> V_137 ,
& V_125 -> V_163 ,
& V_125 -> V_89 ,
V_131 ,
& V_125 -> V_81 ,
& V_125 -> V_18 ,
V_10 ,
F_71 (
& V_161 ) ) ;
if ( V_125 -> error )
goto V_158;
if ( NULL != V_125 -> V_89 ) {
struct V_134 * const V_164 =
(struct V_134 * )
V_125 -> V_163 . V_136 [ 0 ] ;
V_133 =
F_58 () ;
if ( NULL == V_133 ) {
V_125 -> error = - 1 ;
F_42 (
& V_125 ->
V_163 ) ;
goto V_158;
}
V_133 -> V_48 = - 1 ;
V_133 -> V_138 = V_125 -> V_89 ;
V_133 -> V_139 =
& V_125 -> V_163 ;
V_133 -> V_89 = NULL ;
V_133 -> V_140 = V_164 ;
V_133 -> V_137 =
V_125 -> V_137 - 1 ;
V_133 -> V_141 = V_125 ;
V_125 = V_133 ;
goto V_142;
}
} else if ( V_165 == type &&
V_42 -> V_166 ) {
V_125 -> error = F_72 (
V_42 ,
V_125 -> V_138 ,
V_125 -> V_139 ,
V_154 ,
V_131 ) ;
if ( V_125 -> error )
goto V_158;
}
goto V_149;
}
} else {
struct V_167 * const V_168 = (struct V_167 * ) V_125 -> V_140 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_146 = F_61 ( & V_168 -> V_147 ) ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76 L_21
L_22 ,
V_125 -> V_139 -> V_96 ,
V_168 -> V_147 . V_143 , V_125 -> V_146 ,
F_62 (
& V_168 -> V_147 ) ,
F_63 (
& V_168 -> V_147 ) ) ;
}
V_169:
if ( 0 == V_125 -> V_81 || V_125 -> V_18 > V_125 -> V_81 ) {
V_125 -> V_48 ++ ;
V_125 -> V_81 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_146 ) {
struct V_170 V_171 ;
T_2 V_172 ;
T_1 V_82 ;
V_172 = ( V_52 ) ( V_168 -> V_173 + V_125 -> V_48 ) -
( V_52 ) V_168 ;
if ( V_172 + sizeof( struct V_170 ) >
V_125 -> V_139 -> V_156 ) {
F_31 ( V_76
L_23 ,
V_125 -> V_139 -> V_96 ,
V_125 -> V_139 -> V_92 -> V_43 ) ;
goto V_158;
}
F_64 (
V_125 -> V_139 , & V_171 , V_172 ,
sizeof( struct V_170 ) ) ;
V_82 = F_73 ( & V_171 ) ;
V_125 -> error = F_70 (
V_42 ,
V_125 -> V_138 ,
V_125 -> V_139 ,
V_82 ,
V_125 -> V_137 ,
& V_125 -> V_163 ,
& V_125 -> V_89 ,
V_131 ,
& V_125 -> V_81 ,
& V_125 -> V_18 ,
& V_171 . V_159 ,
F_74 ( & V_171 ) ) ;
if ( V_125 -> error )
goto V_158;
if ( NULL != V_125 -> V_89 ) {
struct V_134 * const V_164 =
(struct V_134 * )
V_125 -> V_163 . V_136 [ 0 ] ;
V_133 = F_58 () ;
if ( NULL == V_133 ) {
V_125 -> error = - 1 ;
goto V_158;
}
V_133 -> V_48 = - 1 ;
V_133 -> V_138 = V_125 -> V_89 ;
V_133 -> V_139 = & V_125 -> V_163 ;
V_133 -> V_89 = NULL ;
V_133 -> V_140 = V_164 ;
V_133 -> V_137 =
V_125 -> V_137 - 1 ;
V_133 -> V_141 = V_125 ;
V_125 = V_133 ;
goto V_142;
}
goto V_169;
}
}
V_158:
if ( NULL != V_125 -> V_141 ) {
struct V_124 * const V_141 = V_125 -> V_141 ;
F_42 ( V_125 -> V_139 ) ;
if ( V_125 -> error ) {
V_141 -> error = V_125 -> error ;
F_59 ( V_125 ) ;
V_125 = V_141 ;
goto V_158;
}
F_59 ( V_125 ) ;
V_125 = V_141 ;
goto V_142;
} else {
F_6 ( & V_132 != V_125 ) ;
}
return V_125 -> error ;
}
static void F_64 (
struct V_90 * V_139 ,
void * V_174 , T_2 V_12 , T_4 V_156 )
{
T_4 V_175 ;
T_4 V_176 ;
char * V_177 ;
char * V_178 = ( char * ) V_174 ;
T_4 V_179 = V_139 -> V_96 & ( ( T_1 ) V_95 - 1 ) ;
unsigned long V_48 = ( V_179 + V_12 ) >> V_180 ;
F_75 ( V_12 + V_156 > V_139 -> V_156 ) ;
V_176 = ( V_179 + V_12 ) & ( V_95 - 1 ) ;
while ( V_156 > 0 ) {
V_175 = F_76 ( V_156 , ( ( T_4 ) V_95 - V_176 ) ) ;
F_6 ( V_48 >= F_77 ( V_139 -> V_156 , V_95 ) ) ;
V_177 = V_139 -> V_136 [ V_48 ] ;
memcpy ( V_178 , V_177 + V_176 , V_175 ) ;
V_178 += V_175 ;
V_156 -= V_175 ;
V_176 = 0 ;
V_48 ++ ;
}
}
static int F_70 (
struct V_64 * V_42 ,
struct V_1 * V_138 ,
struct V_90 * V_139 ,
T_1 V_82 ,
int V_137 ,
struct V_90 * V_163 ,
struct V_1 * * V_181 ,
int V_131 ,
int * V_182 , int * V_183 ,
struct V_117 * V_10 ,
T_1 V_184 )
{
struct V_1 * V_89 = NULL ;
int V_67 ;
struct V_30 * V_31 ;
int V_185 ;
int V_186 ;
* V_181 = NULL ;
if ( 0 == * V_182 ) {
* V_182 =
F_39 ( V_42 -> V_85 -> V_86 ,
V_82 , V_42 -> V_87 ) ;
if ( V_42 -> V_83 & V_88 )
F_31 ( V_76 L_6 ,
V_82 , * V_182 ) ;
* V_183 = 1 ;
}
if ( * V_183 > * V_182 )
return 0 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_24 ,
* V_183 ) ;
V_67 = F_40 ( V_42 , V_82 ,
V_42 -> V_87 ,
V_163 , * V_183 ) ;
if ( V_67 ) {
F_31 ( V_76
L_25 ,
V_82 , * V_183 ) ;
F_42 ( V_163 ) ;
* V_181 = NULL ;
return - 1 ;
}
V_89 = F_55 ( V_42 ,
V_163 , L_26 ,
1 , V_131 ,
! V_131 ,
* V_183 ,
& V_186 ) ;
if ( NULL == V_89 ) {
F_42 ( V_163 ) ;
* V_181 = NULL ;
return - 1 ;
}
if ( V_186 ) {
V_31 = NULL ;
V_89 -> V_8 = V_9 ;
} else {
if ( V_42 -> V_83 & V_148 ) {
if ( V_89 -> V_7 != V_82 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) )
F_31 ( V_76
L_27 ,
V_82 , V_163 -> V_92 -> V_43 ,
V_163 -> V_6 , * V_183 ,
F_78 ( V_42 ,
V_89 ) ,
V_89 -> V_7 ) ;
else
F_31 ( V_76
L_28 ,
V_82 , V_163 -> V_92 -> V_43 ,
V_163 -> V_6 , * V_183 ,
F_78 ( V_42 ,
V_89 ) ) ;
}
V_89 -> V_7 = V_82 ;
V_89 -> V_18 = * V_183 ;
V_31 = F_25 (
V_163 -> V_92 -> V_41 ,
V_163 -> V_6 ,
V_139 -> V_92 -> V_41 ,
V_139 -> V_6 ,
& V_42 -> V_94 ) ;
}
V_89 -> V_10 = * V_10 ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( V_163 ) ;
* V_181 = NULL ;
return - 1 ;
}
V_185 = 1 ;
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_138 ;
V_31 -> V_33 = 1 ;
V_31 -> V_184 = V_184 ;
if ( V_42 -> V_83 & V_148 )
F_79 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_138 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_94 ) ;
} else {
V_185 = 0 ;
if ( 0 == V_137 ) {
V_31 -> V_33 ++ ;
V_31 -> V_184 = V_184 ;
if ( V_42 -> V_83 & V_148 )
F_79 ( V_42 , V_31 ) ;
}
}
if ( V_137 > 0 && V_185 ) {
V_67 = F_41 ( V_42 , V_163 ) ;
if ( V_67 < ( int ) V_163 -> V_156 ) {
F_31 ( V_76
L_29 ,
V_82 ) ;
F_42 ( V_163 ) ;
* V_181 = NULL ;
return - 1 ;
}
* V_181 = V_89 ;
} else {
* V_181 = NULL ;
}
( * V_183 ) ++ ;
return 0 ;
}
static int F_72 (
struct V_64 * V_42 ,
struct V_1 * V_138 ,
struct V_90 * V_139 ,
T_2 V_154 , int V_131 )
{
int V_67 ;
struct V_187 V_188 ;
T_1 V_189 ;
T_1 V_82 ;
T_1 V_190 ;
T_1 V_8 ;
struct V_30 * V_31 ;
V_189 = F_68 ( struct V_144 , V_153 ) +
V_154 ;
if ( V_189 +
F_68 ( struct V_187 , V_191 ) >
V_139 -> V_156 ) {
F_31 ( V_76
L_30 ,
V_139 -> V_96 , V_139 -> V_92 -> V_43 ) ;
return - 1 ;
}
F_64 ( V_139 , & V_188 ,
V_189 ,
F_68 ( struct V_187 , V_191 ) ) ;
if ( V_192 != V_188 . type ||
F_80 ( & V_188 ) == 0 ) {
if ( V_42 -> V_83 & V_193 )
F_31 ( V_76 L_31 ,
V_188 . type ,
F_80 (
& V_188 ) ) ;
return 0 ;
}
if ( V_189 + sizeof( struct V_187 ) >
V_139 -> V_156 ) {
F_31 ( V_76
L_30 ,
V_139 -> V_96 , V_139 -> V_92 -> V_43 ) ;
return - 1 ;
}
F_64 ( V_139 , & V_188 ,
V_189 ,
sizeof( struct V_187 ) ) ;
V_82 = F_80 ( & V_188 ) ;
if ( F_81 ( & V_188 ) ==
V_194 ) {
V_82 += F_82 ( & V_188 ) ;
V_190 = F_83 ( & V_188 ) ;
} else {
V_190 = F_84 ( & V_188 ) ;
}
V_8 = F_85 ( & V_188 ) ;
if ( V_42 -> V_83 & V_193 )
F_31 ( V_76 L_32
L_33 ,
V_188 . type ,
F_80 ( & V_188 ) ,
F_82 ( & V_188 ) ,
V_190 ) ;
while ( V_190 > 0 ) {
T_2 V_195 ;
int V_81 ;
int V_18 ;
if ( V_190 > V_42 -> V_111 )
V_195 = V_42 -> V_111 ;
else
V_195 = V_190 ;
V_81 =
F_39 ( V_42 -> V_85 -> V_86 ,
V_82 , V_42 -> V_111 ) ;
if ( V_42 -> V_83 & V_88 )
F_31 ( V_76 L_6 ,
V_82 , V_81 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
struct V_90 V_163 ;
struct V_1 * V_89 ;
int V_186 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76 L_34
L_35 , V_18 ) ;
if ( V_42 -> V_83 & V_193 )
F_31 ( V_76
L_36 ,
V_82 , V_195 ) ;
V_67 = F_40 ( V_42 , V_82 ,
V_195 , & V_163 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_37
L_38 ,
V_82 , V_18 ) ;
return - 1 ;
}
V_89 = F_55 (
V_42 ,
& V_163 ,
L_26 ,
0 ,
V_131 ,
! V_131 ,
V_18 ,
& V_186 ) ;
if ( NULL == V_89 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_163 ) ;
return - 1 ;
}
if ( ! V_186 ) {
if ( ( V_42 -> V_83 &
V_148 ) &&
V_89 -> V_7 != V_82 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) ) {
F_31 ( V_76
L_39
L_40
L_41
L_42
L_43 ,
V_82 ,
V_163 . V_92 -> V_43 ,
V_163 . V_6 ,
V_18 ,
V_89 -> V_7 ) ;
}
V_89 -> V_7 = V_82 ;
V_89 -> V_18 = V_18 ;
}
V_31 = F_56 ( V_42 ,
& V_163 ,
V_89 , V_138 ,
V_8 ) ;
F_42 ( & V_163 ) ;
if ( NULL == V_31 )
return - 1 ;
}
V_82 += V_195 ;
V_190 -= V_195 ;
}
return 0 ;
}
static int F_40 ( struct V_64 * V_42 , T_1 V_196 , T_2 V_156 ,
struct V_90 * V_197 ,
int V_18 )
{
int V_67 ;
T_1 V_198 ;
struct V_199 * V_200 = NULL ;
struct V_72 * V_73 ;
V_198 = V_156 ;
V_67 = F_86 ( V_42 -> V_85 -> V_86 , V_201 ,
V_196 , & V_198 , & V_200 , V_18 ) ;
if ( V_67 ) {
V_197 -> V_96 = 0 ;
V_197 -> V_6 = 0 ;
V_197 -> V_156 = 0 ;
V_197 -> V_92 = NULL ;
V_197 -> V_136 = NULL ;
V_197 -> V_202 = NULL ;
V_197 -> V_203 = NULL ;
return V_67 ;
}
V_73 = V_200 -> V_204 [ 0 ] . V_92 ;
V_197 -> V_92 = F_33 ( V_73 -> V_41 ) ;
V_197 -> V_6 = V_200 -> V_204 [ 0 ] . V_205 ;
V_197 -> V_96 = V_196 ;
V_197 -> V_156 = V_156 ;
V_197 -> V_136 = NULL ;
V_197 -> V_202 = NULL ;
V_197 -> V_203 = NULL ;
F_7 ( V_200 ) ;
if ( NULL == V_197 -> V_92 ) {
V_67 = - V_206 ;
F_31 ( V_76 L_44 ) ;
}
return V_67 ;
}
static void F_42 ( struct V_90 * V_139 )
{
if ( V_139 -> V_203 ) {
unsigned int V_207 ;
F_6 ( ! V_139 -> V_136 ) ;
F_6 ( ! V_139 -> V_202 ) ;
V_207 = ( V_139 -> V_156 + ( T_1 ) V_95 - 1 ) >>
V_180 ;
while ( V_207 > 0 ) {
V_207 -- ;
if ( V_139 -> V_136 [ V_207 ] ) {
F_87 ( V_139 -> V_202 [ V_207 ] ) ;
V_139 -> V_136 [ V_207 ] = NULL ;
}
if ( V_139 -> V_202 [ V_207 ] ) {
F_88 ( V_139 -> V_202 [ V_207 ] ) ;
V_139 -> V_202 [ V_207 ] = NULL ;
}
}
F_7 ( V_139 -> V_203 ) ;
V_139 -> V_203 = NULL ;
V_139 -> V_202 = NULL ;
V_139 -> V_136 = NULL ;
}
}
static int F_41 ( struct V_64 * V_42 ,
struct V_90 * V_139 )
{
unsigned int V_207 ;
unsigned int V_48 ;
T_1 V_6 ;
int V_67 ;
F_6 ( V_139 -> V_136 ) ;
F_6 ( V_139 -> V_202 ) ;
F_6 ( V_139 -> V_203 ) ;
if ( V_139 -> V_6 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_45 ,
V_139 -> V_6 ) ;
return - 1 ;
}
V_207 = ( V_139 -> V_156 + ( T_1 ) V_95 - 1 ) >>
V_180 ;
V_139 -> V_203 = F_4 ( ( sizeof( * V_139 -> V_136 ) +
sizeof( * V_139 -> V_202 ) ) *
V_207 , V_29 ) ;
if ( ! V_139 -> V_203 )
return - V_77 ;
V_139 -> V_136 = V_139 -> V_203 ;
V_139 -> V_202 = (struct V_208 * * ) ( V_139 -> V_136 + V_207 ) ;
for ( V_48 = 0 ; V_48 < V_207 ; V_48 ++ ) {
V_139 -> V_202 [ V_48 ] = F_89 ( V_29 ) ;
if ( ! V_139 -> V_202 [ V_48 ] )
return - 1 ;
}
V_6 = V_139 -> V_6 ;
for ( V_48 = 0 ; V_48 < V_207 ; ) {
struct V_22 * V_22 ;
unsigned int V_209 ;
V_22 = F_90 ( V_29 , V_207 - V_48 ) ;
if ( ! V_22 ) {
F_31 ( V_76
L_46 ,
V_207 - V_48 ) ;
return - 1 ;
}
V_22 -> V_210 = V_139 -> V_92 -> V_41 ;
V_22 -> V_211 . V_212 = V_6 >> 9 ;
for ( V_209 = V_48 ; V_209 < V_207 ; V_209 ++ ) {
V_67 = F_91 ( V_22 , V_139 -> V_202 [ V_209 ] ,
V_95 , 0 ) ;
if ( V_95 != V_67 )
break;
}
if ( V_209 == V_48 ) {
F_31 ( V_76
L_47 ) ;
return - 1 ;
}
if ( F_92 ( V_201 , V_22 ) ) {
F_31 ( V_76
L_48 ,
V_139 -> V_96 , V_139 -> V_92 -> V_43 ) ;
F_93 ( V_22 ) ;
return - 1 ;
}
F_93 ( V_22 ) ;
V_6 += ( V_209 - V_48 ) * V_95 ;
V_48 = V_209 ;
}
for ( V_48 = 0 ; V_48 < V_207 ; V_48 ++ ) {
V_139 -> V_136 [ V_48 ] = F_94 ( V_139 -> V_202 [ V_48 ] ) ;
if ( ! V_139 -> V_136 [ V_48 ] ) {
F_31 ( V_76 L_49 ,
V_139 -> V_92 -> V_43 ) ;
return - 1 ;
}
}
return V_139 -> V_156 ;
}
static void F_95 ( struct V_64 * V_42 )
{
struct V_54 * V_213 ;
F_6 ( NULL == V_42 ) ;
F_31 ( V_76 L_50 ) ;
F_20 (elem_all, &state->all_blocks_list) {
const struct V_1 * const V_214 =
F_21 ( V_213 , struct V_1 ,
V_24 ) ;
struct V_54 * V_215 ;
struct V_54 * V_216 ;
F_31 ( V_76 L_51 ,
F_78 ( V_42 , V_214 ) ,
V_214 -> V_7 , V_214 -> V_5 -> V_43 ,
V_214 -> V_6 , V_214 -> V_18 ) ;
F_20 (elem_ref_to, &b_all->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_215 ,
struct V_30 ,
V_34 ) ;
F_31 ( V_76 L_52
L_53
L_54 ,
F_78 ( V_42 , V_214 ) ,
V_214 -> V_7 , V_214 -> V_5 -> V_43 ,
V_214 -> V_6 , V_214 -> V_18 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
F_20 (elem_ref_from, &b_all->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_216 ,
struct V_30 ,
V_35 ) ;
F_31 ( V_76 L_52
L_55
L_54 ,
F_78 ( V_42 , V_214 ) ,
V_214 -> V_7 , V_214 -> V_5 -> V_43 ,
V_214 -> V_6 , V_214 -> V_18 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_37 ) ,
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ) ;
}
F_31 ( V_76 L_56 ) ;
}
}
static int F_96 ( struct V_64 * V_42 ,
char * * V_136 , unsigned int V_207 )
{
struct V_134 * V_47 ;
T_3 V_217 [ V_218 ] ;
T_2 V_219 = ~ ( T_2 ) 0 ;
unsigned int V_48 ;
if ( V_207 * V_95 < V_42 -> V_87 )
return 1 ;
V_207 = V_42 -> V_87 >> V_180 ;
V_47 = (struct V_134 * ) V_136 [ 0 ] ;
if ( memcmp ( V_47 -> V_220 , V_42 -> V_85 -> V_86 -> V_220 , V_110 ) )
return 1 ;
for ( V_48 = 0 ; V_48 < V_207 ; V_48 ++ ) {
T_3 * V_221 = V_48 ? V_136 [ V_48 ] : ( V_136 [ V_48 ] + V_218 ) ;
T_4 V_222 = V_48 ? V_95 :
( V_95 - V_218 ) ;
V_219 = F_97 ( V_219 , V_221 , V_222 ) ;
}
F_98 ( V_219 , V_217 ) ;
if ( memcmp ( V_217 , V_47 -> V_217 , V_42 -> V_80 ) )
return 1 ;
return 0 ;
}
static void F_99 ( struct V_38 * V_5 ,
T_1 V_6 , char * * V_223 ,
unsigned int V_207 ,
struct V_22 * V_22 , int * V_224 ,
struct V_100 * V_101 ,
int V_27 )
{
int V_13 ;
struct V_1 * V_138 ;
struct V_90 V_139 ;
int V_67 ;
struct V_64 * V_42 = V_5 -> V_42 ;
struct V_53 * V_41 = V_5 -> V_41 ;
unsigned int V_225 ;
if ( NULL != V_224 )
* V_224 = 0 ;
V_226:
if ( V_207 == 0 )
return;
V_225 = 0 ;
V_13 = ( 0 == F_96 ( V_42 , V_223 ,
V_207 ) ) ;
V_138 = F_19 ( V_41 , V_6 ,
& V_42 -> V_93 ) ;
if ( NULL != V_138 ) {
T_1 V_196 = 0 ;
struct V_54 * V_215 ;
struct V_54 * V_227 ;
if ( V_138 -> V_14 ) {
V_196 = F_46 ( (struct V_68 * )
V_223 [ 0 ] ) ;
if ( V_207 * V_95 <
V_104 ) {
F_31 ( V_76
L_57 ) ;
return;
}
V_13 = 1 ;
F_6 ( V_104 & ( V_95 - 1 ) ) ;
V_225 = V_104 ;
if ( V_42 -> V_83 &
V_228 ) {
F_31 ( V_76
L_58 ) ;
F_57 ( V_42 , V_138 , 0 ) ;
}
}
if ( V_13 ) {
if ( ! V_138 -> V_14 ) {
if ( V_207 * V_95 <
V_42 -> V_87 ) {
F_31 ( V_76
L_57 ) ;
return;
}
V_225 = V_42 -> V_87 ;
V_196 = F_100 (
(struct V_134 * )
V_223 [ 0 ] ) ;
F_101 ( V_42 , V_196 ,
V_5 ,
V_6 ) ;
}
if ( V_42 -> V_83 & V_148 ) {
if ( V_138 -> V_7 != V_196 &&
! ( ! V_138 -> V_13 &&
V_138 -> V_7 == 0 ) )
F_31 ( V_76
L_59 ,
V_196 , V_5 -> V_43 ,
V_6 ,
V_138 -> V_18 ,
F_78 ( V_42 ,
V_138 ) ,
V_138 -> V_7 ) ;
else
F_31 ( V_76
L_60 ,
V_196 , V_5 -> V_43 ,
V_6 , V_138 -> V_18 ,
F_78 ( V_42 ,
V_138 ) ) ;
}
V_138 -> V_7 = V_196 ;
} else {
if ( V_207 * V_95 <
V_42 -> V_111 ) {
F_31 ( V_76
L_57 ) ;
return;
}
V_225 = V_42 -> V_111 ;
V_196 = V_138 -> V_7 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_61
L_62 ,
V_196 , V_5 -> V_43 , V_6 ,
V_138 -> V_18 ,
F_78 ( V_42 , V_138 ) ) ;
}
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_63 ,
F_102 ( & V_138 -> V_25 ) ? ' ' : '!' ,
F_102 ( & V_138 -> V_26 ) ? ' ' : '!' ) ;
if ( F_103 ( V_42 , V_138 , 0 ) ) {
F_31 ( V_76 L_64
L_65
L_66
L_67
L_68
L_69 ,
F_78 ( V_42 , V_138 ) , V_196 ,
V_5 -> V_43 , V_6 , V_138 -> V_18 ,
V_138 -> V_8 ,
F_104 ( & V_138 -> V_10 ) ,
V_138 -> V_10 . type ,
F_105 ( & V_138 -> V_10 ) ,
F_62 (
(struct V_134 * ) V_223 [ 0 ] ) ,
V_42 -> V_115 ) ;
F_106 ( V_42 ) ;
}
if ( ! V_138 -> V_15 && ! V_138 -> V_17 ) {
F_31 ( V_76 L_64
L_70
L_71 ,
F_78 ( V_42 , V_138 ) , V_196 ,
V_5 -> V_43 , V_6 , V_138 -> V_18 ,
V_138 -> V_8 ,
F_62 (
(struct V_134 * )
V_223 [ 0 ] ) ) ;
F_106 ( V_42 ) ;
goto V_229;
}
F_107 (elem_ref_to, tmp_ref_to,
&block->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_215 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_83 & V_148 )
F_108 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 ) {
F_18 ( & V_31 -> V_34 ) ;
F_18 ( & V_31 -> V_35 ) ;
F_24 ( V_31 ) ;
F_10 ( V_31 ) ;
}
}
V_139 . V_92 = V_5 ;
V_139 . V_6 = V_6 ;
V_139 . V_96 = V_196 ;
V_139 . V_156 = V_225 ;
V_139 . V_202 = NULL ;
V_139 . V_203 = NULL ;
V_139 . V_136 = V_223 ;
if ( V_13 || V_42 -> V_166 ) {
V_138 -> V_17 = 0 ;
V_138 -> V_16 = 0 ;
if ( NULL != V_22 ) {
V_138 -> V_15 = 0 ;
F_6 ( NULL == V_224 ) ;
if ( ! * V_224 ) {
V_138 -> V_20 =
V_22 -> V_230 ;
V_138 -> V_21 . V_22 =
V_22 -> V_231 ;
V_138 -> V_19 = NULL ;
V_22 -> V_230 = V_138 ;
V_22 -> V_231 = V_232 ;
* V_224 = 1 ;
} else {
struct V_1 * V_233 =
(struct V_1 * )
V_22 -> V_230 ;
F_6 ( NULL == V_233 ) ;
V_138 -> V_20 =
V_233 -> V_20 ;
V_138 -> V_21 . V_22 =
V_233 -> V_21 .
V_22 ;
V_138 -> V_19 = V_233 ;
V_22 -> V_230 = V_138 ;
}
} else if ( NULL != V_101 ) {
V_138 -> V_15 = 0 ;
V_138 -> V_20 = V_101 -> V_234 ;
V_138 -> V_21 . V_101 = V_101 -> V_235 ;
V_138 -> V_19 = NULL ;
V_101 -> V_234 = V_138 ;
V_101 -> V_235 = V_236 ;
} else {
V_138 -> V_15 = 1 ;
V_138 -> V_20 = NULL ;
V_138 -> V_21 . V_22 = NULL ;
V_138 -> V_19 = NULL ;
}
}
V_138 -> V_28 = V_5 -> V_44 + 1 ;
V_138 -> V_27 = V_27 ;
if ( V_13 ) {
V_138 -> V_7 = V_196 ;
V_138 -> V_13 = 1 ;
if ( V_138 -> V_14 ) {
F_6 ( V_95 !=
V_104 ) ;
V_67 = F_109 (
V_42 ,
V_138 ,
(struct V_68 * )
V_223 [ 0 ] ) ;
if ( V_42 -> V_83 &
V_237 ) {
F_31 ( V_76
L_72 ) ;
F_57 ( V_42 , V_138 , 0 ) ;
}
} else {
V_138 -> V_18 = 0 ;
V_67 = F_43 (
V_42 ,
V_138 ,
& V_139 ,
0 , 0 ) ;
}
if ( V_67 )
F_31 ( V_76
L_73
L_74 ,
V_6 ) ;
} else {
V_138 -> V_13 = 0 ;
V_138 -> V_18 = 0 ;
V_138 -> V_8 = V_9 ;
if ( ! V_42 -> V_166
&& F_102 ( & V_138 -> V_26 ) ) {
F_17 ( V_138 ) ;
F_18 ( & V_138 -> V_24 ) ;
F_5 ( V_138 ) ;
}
}
F_42 ( & V_139 ) ;
} else {
T_1 V_196 ;
if ( ! V_13 ) {
V_225 = V_42 -> V_111 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76 L_75
L_76 ,
V_5 -> V_43 , V_6 ) ;
if ( ! V_42 -> V_166 ) {
goto V_229;
}
V_196 = 0 ;
} else {
V_225 = V_42 -> V_87 ;
V_196 = F_100 (
(struct V_134 * )
V_223 [ 0 ] ) ;
F_101 ( V_42 , V_196 , V_5 ,
V_6 ) ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_77
L_78 ,
V_196 , V_5 -> V_43 , V_6 ) ;
}
V_139 . V_92 = V_5 ;
V_139 . V_6 = V_6 ;
V_139 . V_96 = V_196 ;
V_139 . V_156 = V_225 ;
V_139 . V_202 = NULL ;
V_139 . V_203 = NULL ;
V_139 . V_136 = V_223 ;
V_138 = F_3 () ;
if ( NULL == V_138 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( & V_139 ) ;
goto V_229;
}
V_138 -> V_5 = V_5 ;
V_138 -> V_6 = V_6 ;
V_138 -> V_7 = V_196 ;
V_138 -> V_13 = V_13 ;
V_138 -> V_17 = 0 ;
V_138 -> V_16 = 0 ;
V_138 -> V_18 = 0 ;
V_138 -> V_28 = V_5 -> V_44 + 1 ;
V_138 -> V_27 = V_27 ;
if ( NULL != V_22 ) {
V_138 -> V_15 = 0 ;
F_6 ( NULL == V_224 ) ;
if ( ! * V_224 ) {
V_138 -> V_20 = V_22 -> V_230 ;
V_138 -> V_21 . V_22 = V_22 -> V_231 ;
V_138 -> V_19 = NULL ;
V_22 -> V_230 = V_138 ;
V_22 -> V_231 = V_232 ;
* V_224 = 1 ;
} else {
struct V_1 * V_233 =
(struct V_1 * )
V_22 -> V_230 ;
F_6 ( NULL == V_233 ) ;
V_138 -> V_20 =
V_233 -> V_20 ;
V_138 -> V_21 . V_22 =
V_233 -> V_21 . V_22 ;
V_138 -> V_19 = V_233 ;
V_22 -> V_230 = V_138 ;
}
} else if ( NULL != V_101 ) {
V_138 -> V_15 = 0 ;
V_138 -> V_20 = V_101 -> V_234 ;
V_138 -> V_21 . V_101 = V_101 -> V_235 ;
V_138 -> V_19 = NULL ;
V_101 -> V_234 = V_138 ;
V_101 -> V_235 = V_236 ;
} else {
V_138 -> V_15 = 1 ;
V_138 -> V_20 = NULL ;
V_138 -> V_21 . V_22 = NULL ;
V_138 -> V_19 = NULL ;
}
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_79 ,
V_13 ? 'M' : 'D' ,
V_138 -> V_7 , V_138 -> V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ) ;
F_16 ( & V_138 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_138 , & V_42 -> V_93 ) ;
if ( V_13 ) {
V_67 = F_43 ( V_42 , V_138 ,
& V_139 , 0 , 0 ) ;
if ( V_67 )
F_31 ( V_76
L_80
L_81 ,
V_6 ) ;
}
F_42 ( & V_139 ) ;
}
V_229:
F_6 ( ! V_225 ) ;
V_6 += V_225 ;
V_223 += V_225 >> V_180 ;
V_207 -= V_225 >> V_180 ;
goto V_226;
}
static void V_232 ( struct V_22 * V_238 )
{
struct V_1 * V_138 = (struct V_1 * ) V_238 -> V_230 ;
int V_16 ;
V_16 = 0 ;
if ( V_238 -> V_239 )
V_16 = 1 ;
F_6 ( NULL == V_138 ) ;
V_238 -> V_230 = V_138 -> V_20 ;
V_238 -> V_231 = V_138 -> V_21 . V_22 ;
do {
struct V_1 * V_89 ;
struct V_38 * const V_5 = V_138 -> V_5 ;
if ( ( V_5 -> V_42 -> V_83 &
V_240 ) )
F_31 ( V_76
L_82 ,
V_238 -> V_239 ,
F_78 ( V_5 -> V_42 , V_138 ) ,
V_138 -> V_7 , V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ) ;
V_89 = V_138 -> V_19 ;
V_138 -> V_16 = V_16 ;
if ( V_138 -> V_27 & V_241 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_83 &
V_240 ) )
F_31 ( V_76
L_83 ,
V_5 -> V_43 ,
V_5 -> V_44 ) ;
}
if ( V_138 -> V_27 & V_242 )
V_138 -> V_28 = 0 ;
V_138 -> V_15 = 1 ;
V_138 = V_89 ;
} while ( NULL != V_138 );
V_238 -> V_231 ( V_238 ) ;
}
static void V_236 ( struct V_100 * V_101 , int V_243 )
{
struct V_1 * V_138 = (struct V_1 * ) V_101 -> V_234 ;
int V_16 = ! V_243 ;
struct V_38 * V_5 ;
F_6 ( NULL == V_138 ) ;
V_5 = V_138 -> V_5 ;
if ( ( V_5 -> V_42 -> V_83 & V_240 ) )
F_31 ( V_76
L_84 ,
V_16 ,
F_78 ( V_5 -> V_42 , V_138 ) ,
V_138 -> V_7 , V_138 -> V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ) ;
V_138 -> V_16 = V_16 ;
if ( V_138 -> V_27 & V_241 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_83 &
V_240 ) )
F_31 ( V_76
L_85 ,
V_5 -> V_43 , V_5 -> V_44 ) ;
}
if ( V_138 -> V_27 & V_242 )
V_138 -> V_28 = 0 ;
V_101 -> V_234 = V_138 -> V_20 ;
V_101 -> V_235 = V_138 -> V_21 . V_101 ;
V_138 -> V_15 = 1 ;
V_101 -> V_235 ( V_101 , V_243 ) ;
}
static int F_109 (
struct V_64 * V_42 ,
struct V_1 * const V_244 ,
struct V_68 * const V_245 )
{
int V_75 ;
V_244 -> V_8 = F_51 ( V_245 ) ;
if ( ! ( V_244 -> V_8 > V_42 -> V_115 ||
0 == V_42 -> V_115 ) ) {
if ( V_42 -> V_83 & V_112 )
F_31 ( V_76
L_86
L_87 ,
V_244 -> V_7 ,
V_244 -> V_5 -> V_43 ,
V_244 -> V_6 , V_244 -> V_18 ,
F_51 ( V_245 ) ,
V_42 -> V_115 ) ;
} else {
if ( V_42 -> V_83 & V_112 )
F_31 ( V_76
L_88
L_89 ,
V_244 -> V_7 ,
V_244 -> V_5 -> V_43 ,
V_244 -> V_6 , V_244 -> V_18 ,
F_51 ( V_245 ) ,
V_42 -> V_115 ) ;
V_42 -> V_115 =
F_51 ( V_245 ) ;
V_42 -> V_79 = V_244 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_67 ;
T_1 V_82 ;
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
int V_81 ;
int V_18 ;
const char * V_116 = NULL ;
struct V_117 V_118 = { 0 } ;
F_54 ( & V_118 ,
V_119 ) ;
F_54 ( & V_118 , 0 ) ;
switch ( V_75 ) {
case 0 :
F_54 ( & V_118 ,
V_120 ) ;
V_116 = L_90 ;
V_82 = F_36 ( V_245 ) ;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_3 , V_82 ) ;
break;
case 1 :
F_54 ( & V_118 ,
V_121 ) ;
V_116 = L_91 ;
V_82 = F_37 ( V_245 ) ;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_4 , V_82 ) ;
break;
case 2 :
F_54 ( & V_118 ,
V_122 ) ;
V_116 = L_92 ;
V_82 = F_38 ( V_245 ) ;
if ( 0 == V_82 )
continue;
if ( V_42 -> V_83 &
V_84 )
F_31 ( V_76 L_5 , V_82 ) ;
break;
}
V_81 =
F_39 ( V_42 -> V_85 -> V_86 ,
V_82 , V_104 ) ;
if ( V_42 -> V_83 & V_88 )
F_31 ( V_76 L_6 ,
V_82 , V_81 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
int V_246 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_93
L_35 , V_18 ) ;
V_67 = F_40 ( V_42 , V_82 ,
V_104 ,
& V_91 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_37
L_38 ,
V_82 , V_18 ) ;
return - 1 ;
}
V_89 = F_55 (
V_42 ,
& V_91 ,
V_116 ,
1 , 0 , 1 ,
V_18 ,
& V_246 ) ;
if ( NULL == V_89 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_91 ) ;
return - 1 ;
}
V_89 -> V_10 = V_118 ;
if ( V_246 )
V_89 -> V_8 =
V_9 ;
V_31 = F_56 (
V_42 ,
& V_91 ,
V_89 ,
V_244 ,
V_9 ) ;
F_42 ( & V_91 ) ;
if ( NULL == V_31 )
return - 1 ;
}
}
if ( F_75 ( - 1 == F_110 ( V_42 , V_244 , 0 ) ) )
F_106 ( V_42 ) ;
return 0 ;
}
static int F_110 ( struct V_64 * V_42 ,
struct V_1 * const V_138 ,
int V_247 )
{
struct V_54 * V_215 ;
int V_67 = 0 ;
if ( V_247 >= 3 + V_97 ) {
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_94 ) ;
return V_67 ;
}
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_215 , struct V_30 ,
V_34 ) ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_95
L_96 ,
V_247 ,
F_78 ( V_42 , V_138 ) ,
V_138 -> V_7 , V_138 -> V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
if ( V_31 -> V_36 -> V_17 ) {
F_31 ( V_76 L_97
L_98
L_99 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( ! V_31 -> V_36 -> V_15 ) {
F_31 ( V_76 L_97
L_98
L_71 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_16 ) {
F_31 ( V_76 L_97
L_98
L_100 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_184 !=
V_31 -> V_36 -> V_8 &&
V_9 !=
V_31 -> V_184 &&
V_9 !=
V_31 -> V_36 -> V_8 ) {
F_31 ( V_76 L_97
L_98
L_101
L_102 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
V_31 -> V_36 -> V_8 ,
V_31 -> V_184 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_28 >
V_31 -> V_36 -> V_5 -> V_44 ) {
F_31 ( V_76 L_97
L_98
L_103
L_104
L_105 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 , V_138 -> V_28 ,
V_31 -> V_36 -> V_5 -> V_44 ) ;
V_67 = - 1 ;
} else if ( - 1 == F_110 ( V_42 ,
V_31 -> V_36 ,
V_247 +
1 ) ) {
V_67 = - 1 ;
}
}
return V_67 ;
}
static int F_103 (
const struct V_64 * V_42 ,
const struct V_1 * V_138 ,
int V_247 )
{
struct V_54 * V_216 ;
if ( V_247 >= 3 + V_97 ) {
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_106 ) ;
return 0 ;
}
F_20 (elem_ref_from, &block->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_216 , struct V_30 ,
V_35 ) ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_95
L_107 ,
V_247 ,
F_78 ( V_42 , V_138 ) ,
V_138 -> V_7 , V_138 -> V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_37 ) ,
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ) ;
if ( V_31 -> V_37 -> V_14 &&
V_42 -> V_79 -> V_6 ==
V_31 -> V_37 -> V_6 &&
V_42 -> V_79 -> V_5 -> V_41 ==
V_31 -> V_37 -> V_5 -> V_41 )
return 1 ;
else if ( F_103 ( V_42 ,
V_31 -> V_37 ,
V_247 +
1 ) )
return 1 ;
}
return 0 ;
}
static void F_79 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_31 ( V_76
L_108
L_109 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_37 ) ,
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
V_31 -> V_37 -> V_6 , V_31 -> V_37 -> V_18 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 , V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static void F_108 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_31 ( V_76
L_110
L_109 ,
V_31 -> V_33 ,
F_78 ( V_42 , V_31 -> V_37 ) ,
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
V_31 -> V_37 -> V_6 , V_31 -> V_37 -> V_18 ,
F_78 ( V_42 , V_31 -> V_36 ) ,
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 , V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static char F_78 ( const struct V_64 * V_42 ,
const struct V_1 * V_138 )
{
if ( V_138 -> V_14 &&
V_42 -> V_79 -> V_6 == V_138 -> V_6 &&
V_42 -> V_79 -> V_5 -> V_41 == V_138 -> V_5 -> V_41 )
return 'S' ;
else if ( V_138 -> V_14 )
return 's' ;
else if ( V_138 -> V_13 )
return 'M' ;
else
return 'D' ;
}
static void F_106 ( const struct V_64 * V_42 )
{
F_57 ( V_42 , V_42 -> V_79 , 0 ) ;
}
static void F_57 ( const struct V_64 * V_42 ,
const struct V_1 * V_138 ,
int V_248 )
{
struct V_54 * V_215 ;
int V_249 ;
static char V_250 [ 80 ] ;
int V_251 ;
V_249 = sprintf ( V_250 , L_111 ,
F_78 ( V_42 , V_138 ) ,
V_138 -> V_7 , V_138 -> V_5 -> V_43 ,
V_138 -> V_6 , V_138 -> V_18 ) ;
if ( V_248 + V_249 > V_252 ) {
F_31 ( L_112 ) ;
return;
}
F_31 ( V_250 ) ;
V_248 += V_249 ;
if ( F_102 ( & V_138 -> V_25 ) ) {
F_31 ( L_56 ) ;
return;
}
if ( V_138 -> V_18 > 1 &&
! ( V_42 -> V_83 & V_253 ) ) {
F_31 ( L_113 ) ;
return;
}
V_251 = V_248 ;
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_215 , struct V_30 ,
V_34 ) ;
while ( V_251 < V_248 ) {
F_31 ( L_114 ) ;
V_251 ++ ;
}
if ( V_31 -> V_33 > 1 )
V_249 = sprintf ( V_250 , L_115 , V_31 -> V_33 ) ;
else
V_249 = sprintf ( V_250 , L_116 ) ;
if ( V_248 + V_249 >
V_252 ) {
F_31 ( L_112 ) ;
V_251 = 0 ;
continue;
}
F_31 ( V_250 ) ;
F_57 ( V_42 , V_31 -> V_36 ,
V_248 + V_249 ) ;
V_251 = 0 ;
}
}
static struct V_30 * F_56 (
struct V_64 * V_42 ,
struct V_90 * V_163 ,
struct V_1 * V_89 ,
struct V_1 * V_254 ,
T_1 V_184 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( V_163 -> V_92 -> V_41 ,
V_163 -> V_6 ,
V_254 -> V_5 -> V_41 ,
V_254 -> V_6 ,
& V_42 -> V_94 ) ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76
L_117 L_81 ) ;
return NULL ;
}
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_254 ;
V_31 -> V_33 = 1 ;
V_31 -> V_184 = V_184 ;
if ( V_42 -> V_83 & V_148 )
F_79 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_254 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_94 ) ;
} else {
V_31 -> V_33 ++ ;
V_31 -> V_184 = V_184 ;
if ( V_42 -> V_83 & V_148 )
F_79 ( V_42 , V_31 ) ;
}
return V_31 ;
}
static struct V_1 * F_55 (
struct V_64 * V_42 ,
struct V_90 * V_139 ,
const char * V_116 ,
int V_13 ,
int V_15 ,
int V_17 ,
int V_18 ,
int * V_246 )
{
struct V_1 * V_138 ;
V_138 = F_19 ( V_139 -> V_92 -> V_41 ,
V_139 -> V_6 ,
& V_42 -> V_93 ) ;
if ( NULL == V_138 ) {
struct V_38 * V_5 ;
V_138 = F_3 () ;
if ( NULL == V_138 ) {
F_31 ( V_76 L_1 ) ;
return NULL ;
}
V_5 = F_33 ( V_139 -> V_92 -> V_41 ) ;
if ( NULL == V_5 ) {
F_31 ( V_76
L_118 ) ;
F_5 ( V_138 ) ;
return NULL ;
}
V_138 -> V_5 = V_5 ;
V_138 -> V_6 = V_139 -> V_6 ;
V_138 -> V_7 = V_139 -> V_96 ;
V_138 -> V_13 = V_13 ;
V_138 -> V_15 = V_15 ;
V_138 -> V_17 = V_17 ;
V_138 -> V_18 = V_18 ;
if ( V_42 -> V_83 & V_148 )
F_31 ( V_76
L_119 ,
V_116 ,
F_78 ( V_42 , V_138 ) ,
V_138 -> V_7 , V_5 -> V_43 ,
V_138 -> V_6 , V_18 ) ;
F_16 ( & V_138 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_138 , & V_42 -> V_93 ) ;
if ( NULL != V_246 )
* V_246 = 1 ;
} else {
if ( NULL != V_246 )
* V_246 = 0 ;
}
return V_138 ;
}
static void F_101 ( struct V_64 * V_42 ,
T_1 V_196 ,
struct V_38 * V_5 ,
T_1 V_6 )
{
int V_81 ;
int V_18 ;
int V_67 ;
struct V_90 V_139 ;
int V_255 = 0 ;
V_81 = F_39 ( V_42 -> V_85 -> V_86 ,
V_196 , V_42 -> V_87 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_196 , V_42 -> V_87 ,
& V_139 , V_18 ) ;
if ( V_67 ) {
F_31 ( V_76 L_7
L_120
L_9 ,
V_196 , V_18 ) ;
continue;
}
if ( V_5 -> V_41 == V_139 . V_92 -> V_41 &&
V_6 == V_139 . V_6 ) {
V_255 ++ ;
F_42 ( & V_139 ) ;
break;
}
F_42 ( & V_139 ) ;
}
if ( F_75 ( ! V_255 ) ) {
F_31 ( V_76 L_121
L_122
L_123 ,
V_196 , V_5 -> V_43 , V_6 ) ;
for ( V_18 = 1 ; V_18 <= V_81 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_196 ,
V_42 -> V_87 ,
& V_139 , V_18 ) ;
if ( V_67 )
continue;
F_31 ( V_76 L_124
L_125 ,
V_196 , V_139 . V_92 -> V_43 ,
V_139 . V_6 , V_18 ) ;
}
}
}
static struct V_38 * F_33 (
struct V_53 * V_41 )
{
struct V_38 * V_39 ;
V_39 = F_29 ( V_41 ,
& V_62 ) ;
return V_39 ;
}
int F_111 ( int V_256 , struct V_100 * V_101 )
{
struct V_38 * V_5 ;
if ( ! V_257 )
return F_112 ( V_256 , V_101 ) ;
F_113 ( & V_258 ) ;
V_5 = F_33 ( V_101 -> V_259 ) ;
if ( NULL != V_5 &&
( V_256 & V_260 ) && V_101 -> V_261 > 0 ) {
T_1 V_6 ;
V_6 = 4096 * V_101 -> V_262 ;
if ( V_5 -> V_42 -> V_83 &
V_263 )
F_31 ( V_76
L_126
L_127 ,
V_256 , ( unsigned long long ) V_101 -> V_262 ,
V_6 , V_101 -> V_261 , V_101 -> V_106 , V_101 -> V_259 ) ;
F_99 ( V_5 , V_6 ,
& V_101 -> V_106 , 1 , NULL ,
NULL , V_101 , V_256 ) ;
} else if ( NULL != V_5 && ( V_256 & V_241 ) ) {
if ( V_5 -> V_42 -> V_83 &
V_263 )
F_31 ( V_76
L_128 ,
V_256 , V_101 -> V_259 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_83 &
( V_263 |
V_148 ) ) )
F_31 ( V_76
L_129
L_130
L_131 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_138 =
& V_5 -> V_45 ;
V_138 -> V_15 = 0 ;
V_138 -> V_17 = 0 ;
V_138 -> V_16 = 0 ;
V_138 -> V_28 = V_5 -> V_44 + 1 ;
V_138 -> V_27 = V_256 ;
V_138 -> V_20 = V_101 -> V_234 ;
V_138 -> V_21 . V_101 = V_101 -> V_235 ;
V_138 -> V_19 = NULL ;
V_101 -> V_234 = V_138 ;
V_101 -> V_235 = V_236 ;
}
}
F_114 ( & V_258 ) ;
return F_112 ( V_256 , V_101 ) ;
}
static void F_115 ( int V_256 , struct V_22 * V_22 )
{
struct V_38 * V_5 ;
if ( ! V_257 )
return;
F_113 ( & V_258 ) ;
V_5 = F_33 ( V_22 -> V_210 ) ;
if ( NULL != V_5 &&
( V_256 & V_260 ) && NULL != V_22 -> V_264 ) {
unsigned int V_48 ;
T_1 V_6 ;
T_1 V_265 ;
int V_224 ;
char * * V_223 ;
V_6 = 512 * V_22 -> V_211 . V_212 ;
V_224 = 0 ;
if ( V_5 -> V_42 -> V_83 &
V_263 )
F_31 ( V_76
L_132
L_133 ,
V_256 , V_22 -> V_266 ,
( unsigned long long ) V_22 -> V_211 . V_212 ,
V_6 , V_22 -> V_210 ) ;
V_223 = F_116 ( V_22 -> V_266 ,
sizeof( * V_223 ) , V_29 ) ;
if ( ! V_223 )
goto V_267;
V_265 = V_6 ;
for ( V_48 = 0 ; V_48 < V_22 -> V_266 ; V_48 ++ ) {
F_6 ( V_22 -> V_264 [ V_48 ] . V_268 != V_95 ) ;
V_223 [ V_48 ] = F_94 ( V_22 -> V_264 [ V_48 ] . V_269 ) ;
if ( ! V_223 [ V_48 ] ) {
while ( V_48 > 0 ) {
V_48 -- ;
F_87 ( V_22 -> V_264 [ V_48 ] . V_269 ) ;
}
F_7 ( V_223 ) ;
goto V_267;
}
if ( V_5 -> V_42 -> V_83 &
V_270 )
F_31 ( V_76
L_134 ,
V_48 , V_265 , V_22 -> V_264 [ V_48 ] . V_268 ,
V_22 -> V_264 [ V_48 ] . V_271 ) ;
V_265 += V_22 -> V_264 [ V_48 ] . V_268 ;
}
F_99 ( V_5 , V_6 ,
V_223 , V_22 -> V_266 ,
V_22 , & V_224 ,
NULL , V_256 ) ;
while ( V_48 > 0 ) {
V_48 -- ;
F_87 ( V_22 -> V_264 [ V_48 ] . V_269 ) ;
}
F_7 ( V_223 ) ;
} else if ( NULL != V_5 && ( V_256 & V_241 ) ) {
if ( V_5 -> V_42 -> V_83 &
V_263 )
F_31 ( V_76
L_135 ,
V_256 , V_22 -> V_210 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_83 &
( V_263 |
V_148 ) ) )
F_31 ( V_76
L_136
L_130
L_131 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_138 =
& V_5 -> V_45 ;
V_138 -> V_15 = 0 ;
V_138 -> V_17 = 0 ;
V_138 -> V_16 = 0 ;
V_138 -> V_28 = V_5 -> V_44 + 1 ;
V_138 -> V_27 = V_256 ;
V_138 -> V_20 = V_22 -> V_230 ;
V_138 -> V_21 . V_22 = V_22 -> V_231 ;
V_138 -> V_19 = NULL ;
V_22 -> V_230 = V_138 ;
V_22 -> V_231 = V_232 ;
}
}
V_267:
F_114 ( & V_258 ) ;
}
void F_117 ( int V_256 , struct V_22 * V_22 )
{
F_115 ( V_256 , V_22 ) ;
F_118 ( V_256 , V_22 ) ;
}
int F_119 ( int V_256 , struct V_22 * V_22 )
{
F_115 ( V_256 , V_22 ) ;
return F_92 ( V_256 , V_22 ) ;
}
int F_120 ( struct V_272 * V_85 ,
struct V_65 * V_66 ,
int V_273 , T_2 V_83 )
{
int V_67 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( V_85 -> V_274 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_137 ,
V_85 -> V_274 , V_95 ) ;
return - 1 ;
}
if ( V_85 -> V_275 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_138 ,
V_85 -> V_275 , V_95 ) ;
return - 1 ;
}
V_42 = F_4 ( sizeof( * V_42 ) , V_276 | V_277 | V_278 ) ;
if ( ! V_42 ) {
V_42 = F_121 ( sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
F_31 ( V_76 L_139 ) ;
return - 1 ;
}
}
if ( ! V_257 ) {
F_122 ( & V_258 ) ;
F_26 ( & V_62 ) ;
V_257 = 1 ;
}
F_113 ( & V_258 ) ;
V_42 -> V_85 = V_85 ;
V_42 -> V_83 = V_83 ;
V_42 -> V_166 = V_273 ;
V_42 -> V_80 = 0 ;
V_42 -> V_87 = V_85 -> V_274 ;
V_42 -> V_111 = V_85 -> V_275 ;
F_2 ( & V_42 -> V_114 ) ;
F_14 ( & V_42 -> V_93 ) ;
F_22 ( & V_42 -> V_94 ) ;
V_42 -> V_115 = 0 ;
V_42 -> V_79 = NULL ;
F_32 (device, dev_head, dev_list) {
struct V_38 * V_39 ;
char * V_279 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_39 = F_12 () ;
if ( NULL == V_39 ) {
F_31 ( V_76
L_140 ) ;
F_114 ( & V_258 ) ;
return - 1 ;
}
V_39 -> V_41 = V_73 -> V_41 ;
V_39 -> V_42 = V_42 ;
F_123 ( V_39 -> V_41 , V_39 -> V_43 ) ;
V_39 -> V_43 [ V_280 - 1 ] = '\0' ;
for ( V_279 = V_39 -> V_43 ; * V_279 != '\0' ; V_279 ++ ) ;
while ( V_279 > V_39 -> V_43 && * V_279 != '/' )
V_279 -- ;
if ( * V_279 == '/' )
V_279 ++ ;
F_124 ( V_39 -> V_43 , V_279 , sizeof( V_39 -> V_43 ) ) ;
F_27 ( V_39 ,
& V_62 ) ;
}
V_67 = F_30 ( V_42 , V_66 ) ;
if ( 0 != V_67 ) {
F_114 ( & V_258 ) ;
F_125 ( V_85 , V_66 ) ;
return V_67 ;
}
if ( V_42 -> V_83 & V_281 )
F_95 ( V_42 ) ;
if ( V_42 -> V_83 & V_282 )
F_106 ( V_42 ) ;
F_114 ( & V_258 ) ;
return 0 ;
}
void F_125 ( struct V_272 * V_85 ,
struct V_65 * V_66 )
{
struct V_54 * V_213 ;
struct V_54 * V_283 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( ! V_257 )
return;
F_113 ( & V_258 ) ;
V_42 = NULL ;
F_32 (device, dev_head, dev_list) {
struct V_38 * V_39 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_39 = F_29 (
V_73 -> V_41 ,
& V_62 ) ;
if ( NULL != V_39 ) {
V_42 = V_39 -> V_42 ;
F_28 ( V_39 ) ;
F_13 ( V_39 ) ;
}
}
if ( NULL == V_42 ) {
F_31 ( V_76
L_141
L_142 ) ;
F_114 ( & V_258 ) ;
return;
}
F_107 (elem_all, tmp_all, &state->all_blocks_list) {
struct V_1 * const V_214 =
F_21 ( V_213 , struct V_1 ,
V_24 ) ;
struct V_54 * V_215 ;
struct V_54 * V_227 ;
F_107 (elem_ref_to, tmp_ref_to,
&b_all->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_215 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_83 & V_148 )
F_108 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 )
F_10 ( V_31 ) ;
}
if ( V_214 -> V_15 || V_214 -> V_17 )
F_5 ( V_214 ) ;
else
F_31 ( V_76 L_143
L_144
L_145 ,
F_78 ( V_42 , V_214 ) ,
V_214 -> V_7 , V_214 -> V_5 -> V_43 ,
V_214 -> V_6 , V_214 -> V_18 ) ;
}
F_114 ( & V_258 ) ;
F_126 ( V_42 ) ;
}
