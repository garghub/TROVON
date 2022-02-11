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
return - 1 ;
}
F_32 (device, dev_head, dev_list) {
int V_48 ;
struct V_38 * V_5 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_5 = F_33 ( V_73 -> V_41 ) ;
F_6 ( NULL == V_5 ) ;
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ ) {
V_67 = F_34 (
V_42 , V_5 , V_73 , V_48 ,
& V_74 , V_69 ) ;
if ( 0 != V_67 && 0 == V_48 ) {
F_7 ( V_69 ) ;
return V_67 ;
}
}
}
if ( NULL == V_42 -> V_78 ) {
F_31 ( V_76 L_2 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_42 -> V_79 = F_35 ( V_69 ) ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_80 ;
int V_18 ;
T_1 V_81 ;
switch ( V_75 ) {
case 0 :
V_81 = F_36 ( V_69 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_3 ,
( unsigned long long ) V_81 ) ;
break;
case 1 :
V_81 = F_37 ( V_69 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_4 ,
( unsigned long long ) V_81 ) ;
break;
case 2 :
V_81 = F_38 ( V_69 ) ;
if ( 0 == V_81 )
continue;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_5 ,
( unsigned long long ) V_81 ) ;
break;
}
V_80 =
F_39 ( V_42 -> V_84 -> V_85 ,
V_81 , V_42 -> V_86 ) ;
if ( V_42 -> V_82 & V_87 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_88 ;
struct V_89 V_90 ;
struct V_30 * V_31 ;
V_67 = F_40 ( V_42 , V_81 ,
V_42 -> V_86 ,
& V_90 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76 L_7
L_8
L_9 ,
( unsigned long long ) V_81 ,
V_18 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_88 = F_19 (
V_90 . V_91 -> V_41 ,
V_90 . V_6 ,
& V_42 -> V_92 ) ;
F_6 ( NULL == V_88 ) ;
V_31 = F_25 (
V_90 . V_91 -> V_41 ,
V_90 . V_6 ,
V_42 -> V_78 -> V_5 ->
V_41 ,
V_42 -> V_78 -> V_6 ,
& V_42 -> V_93 ) ;
F_6 ( NULL == V_31 ) ;
V_67 = F_41 ( V_42 , & V_90 ) ;
if ( V_67 < ( int ) V_94 ) {
F_31 ( V_76
L_10 ,
( unsigned long long )
V_90 . V_95 ) ;
F_42 ( & V_90 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_67 = F_43 ( V_42 ,
V_88 ,
& V_90 ,
V_96 + 3 , 1 ) ;
F_42 ( & V_90 ) ;
}
}
F_7 ( V_69 ) ;
return V_67 ;
}
static int F_34 (
struct V_64 * V_42 ,
struct V_38 * V_5 ,
struct V_72 * V_73 ,
int V_97 ,
struct V_38 * * V_74 ,
struct V_68 * V_69 )
{
struct V_68 * V_98 ;
T_1 V_6 ;
struct V_99 * V_100 ;
struct V_1 * V_101 ;
int V_75 ;
struct V_53 * const V_102 = V_73 -> V_41 ;
V_6 = F_44 ( V_97 ) ;
if ( V_6 + V_103 > V_73 -> V_104 )
return - 1 ;
V_100 = F_45 ( V_102 , V_6 / 4096 ,
V_103 ) ;
if ( NULL == V_100 )
return - 1 ;
V_98 = (struct V_68 * )
( V_100 -> V_105 + ( V_6 & 4095 ) ) ;
if ( F_46 ( V_98 ) != V_6 ||
strncmp ( ( char * ) ( & ( V_98 -> V_106 ) ) , V_107 ,
sizeof( V_98 -> V_106 ) ) ||
memcmp ( V_73 -> V_108 , V_98 -> V_109 . V_108 , V_110 ) ||
F_47 ( V_98 ) != V_42 -> V_86 ||
F_48 ( V_98 ) != V_42 -> V_86 ||
F_49 ( V_98 ) != V_42 -> V_111 ) {
F_50 ( V_100 ) ;
return 0 ;
}
V_101 =
F_19 ( V_102 ,
V_6 ,
& V_42 -> V_92 ) ;
if ( NULL == V_101 ) {
V_101 = F_3 () ;
if ( NULL == V_101 ) {
F_31 ( V_76 L_1 ) ;
F_50 ( V_100 ) ;
return - 1 ;
}
V_101 -> V_6 = V_6 ;
V_101 -> V_5 = V_5 ;
V_101 -> V_7 = V_6 ;
V_101 -> V_8 = F_51 ( V_98 ) ;
V_101 -> V_13 = 1 ;
V_101 -> V_14 = 1 ;
V_101 -> V_15 = 1 ;
V_101 -> V_17 = 0 ;
V_101 -> V_18 = 1 + V_97 ;
if ( V_42 -> V_82 & V_112 )
F_52 ( V_76 L_11
L_12 ,
V_102 ,
F_53 ( V_73 -> V_43 ) ,
( unsigned long long ) V_6 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_97 ) ;
F_16 ( & V_101 -> V_24 ,
& V_42 -> V_113 ) ;
F_15 ( V_101 ,
& V_42 -> V_92 ) ;
}
if ( F_51 ( V_98 ) >
V_42 -> V_114 ||
0 == V_42 -> V_114 ) {
memcpy ( V_69 , V_98 , sizeof( * V_69 ) ) ;
* V_74 = V_5 ;
V_42 -> V_114 =
F_51 ( V_98 ) ;
V_42 -> V_78 = V_101 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
T_1 V_81 ;
int V_80 ;
int V_18 ;
const char * V_115 = NULL ;
struct V_116 V_117 ;
V_117 . type = V_118 ;
V_117 . V_12 = 0 ;
switch ( V_75 ) {
case 0 :
V_117 . V_11 =
F_54 ( V_119 ) ;
V_115 = L_13 ;
V_81 = F_36 ( V_98 ) ;
break;
case 1 :
V_117 . V_11 =
F_54 ( V_120 ) ;
V_115 = L_14 ;
V_81 = F_37 ( V_98 ) ;
break;
case 2 :
V_117 . V_11 =
F_54 ( V_121 ) ;
V_115 = L_15 ;
V_81 = F_38 ( V_98 ) ;
if ( 0 == V_81 )
continue;
break;
}
V_80 =
F_39 ( V_42 -> V_84 -> V_85 ,
V_81 , V_42 -> V_86 ) ;
if ( V_42 -> V_82 & V_87 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_88 ;
struct V_89 V_90 ;
struct V_30 * V_31 ;
if ( F_40 ( V_42 , V_81 ,
V_42 -> V_86 ,
& V_90 ,
V_18 ) ) {
F_31 ( V_76 L_16
L_17 ,
( unsigned long long ) V_81 ,
V_18 ) ;
F_50 ( V_100 ) ;
return - 1 ;
}
V_88 = F_55 (
V_42 , & V_90 ,
V_115 , 1 , 1 , 0 ,
V_18 , NULL ) ;
if ( NULL == V_88 ) {
F_42 ( & V_90 ) ;
F_50 ( V_100 ) ;
return - 1 ;
}
V_88 -> V_10 = V_117 ;
V_88 -> V_8 = V_9 ;
V_31 = F_56 (
V_42 , & V_90 ,
V_88 , V_101 ,
V_9 ) ;
F_42 ( & V_90 ) ;
if ( NULL == V_31 ) {
F_50 ( V_100 ) ;
return - 1 ;
}
}
}
if ( V_42 -> V_82 & V_122 )
F_57 ( V_42 , V_101 , 0 ) ;
F_50 ( V_100 ) ;
return 0 ;
}
static struct V_123 * F_58 ( void )
{
struct V_123 * V_124 ;
V_124 = F_4 ( sizeof( * V_124 ) , V_29 ) ;
if ( NULL == V_124 )
F_31 ( V_76 L_18 ) ;
else
V_124 -> V_106 = V_125 ;
return V_124 ;
}
static void F_59 ( struct V_123 * V_124 )
{
F_6 ( ! ( NULL == V_124 ||
V_125 == V_124 -> V_106 ) ) ;
F_7 ( V_124 ) ;
}
static int F_43 (
struct V_64 * V_42 ,
struct V_1 * const V_126 ,
struct V_89 * const V_127 ,
int V_128 , int V_129 )
{
struct V_123 V_130 = { 0 } ;
struct V_123 * V_124 ;
struct V_123 * V_131 ;
struct V_132 * const V_133 =
(struct V_132 * ) V_127 -> V_134 [ 0 ] ;
F_6 ( ! V_133 ) ;
V_124 = & V_130 ;
V_124 -> error = 0 ;
V_124 -> V_48 = - 1 ;
V_124 -> V_135 = V_128 ;
V_124 -> V_136 = V_126 ;
V_124 -> V_137 = V_127 ;
V_124 -> V_88 = NULL ;
V_124 -> V_138 = V_133 ;
V_124 -> V_139 = NULL ;
V_140:
V_124 -> V_136 -> V_8 = F_60 ( V_124 -> V_138 -> V_8 ) ;
if ( 0 == V_124 -> V_138 -> V_141 ) {
struct V_142 * const V_143 =
(struct V_142 * ) V_124 -> V_138 ;
if ( - 1 == V_124 -> V_48 ) {
V_124 -> V_144 = F_61 ( V_143 -> V_145 . V_146 ) ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_19
L_20 ,
( unsigned long long )
V_124 -> V_137 -> V_95 ,
V_124 -> V_144 ,
( unsigned long long )
F_60 ( V_143 -> V_145 . V_8 ) ,
( unsigned long long )
F_60 ( V_143 -> V_145 . V_148 ) ) ;
}
V_149:
if ( 0 == V_124 -> V_80 || V_124 -> V_18 > V_124 -> V_80 ) {
V_124 -> V_48 ++ ;
V_124 -> V_80 = 0 ;
}
if ( V_124 -> V_48 < V_124 -> V_144 ) {
struct V_150 V_151 ;
T_2 V_152 =
( V_52 ) ( V_143 -> V_153 + V_124 -> V_48 ) -
( V_52 ) V_143 ;
struct V_116 * V_10 ;
T_3 type ;
T_2 V_154 ;
T_2 V_155 ;
if ( V_152 + sizeof( struct V_150 ) >
V_124 -> V_137 -> V_156 ) {
V_157:
F_31 ( V_76
L_21 ,
V_124 -> V_137 -> V_95 ,
V_124 -> V_137 -> V_91 -> V_43 ) ;
goto V_158;
}
F_62 ( V_124 -> V_137 ,
& V_151 ,
V_152 ,
sizeof( struct V_150 ) ) ;
V_154 = F_61 ( V_151 . V_12 ) ;
V_155 = F_61 ( V_151 . V_159 ) ;
V_10 = & V_151 . V_160 ;
type = V_10 -> type ;
if ( V_118 == type ) {
struct V_161 V_162 ;
T_2 V_163 ;
T_1 V_81 ;
V_163 = V_154 +
F_63 ( struct V_142 , V_153 ) ;
if ( V_163 + V_155 >
V_124 -> V_137 -> V_156 )
goto V_157;
F_62 (
V_124 -> V_137 , & V_162 ,
V_163 ,
V_155 ) ;
V_81 = F_60 ( V_162 . V_164 ) ;
V_124 -> error =
F_64 (
V_42 ,
V_124 -> V_136 ,
V_124 -> V_137 ,
V_81 ,
V_124 -> V_135 ,
& V_124 -> V_165 ,
& V_124 -> V_88 ,
V_129 ,
& V_124 -> V_80 ,
& V_124 -> V_18 ,
V_10 ,
F_60 ( V_162 .
V_8 ) ) ;
if ( V_124 -> error )
goto V_158;
if ( NULL != V_124 -> V_88 ) {
struct V_132 * const V_166 =
(struct V_132 * )
V_124 -> V_165 . V_134 [ 0 ] ;
V_131 =
F_58 () ;
if ( NULL == V_131 ) {
F_42 (
& V_124 ->
V_165 ) ;
goto V_158;
}
V_131 -> V_48 = - 1 ;
V_131 -> V_136 = V_124 -> V_88 ;
V_131 -> V_137 =
& V_124 -> V_165 ;
V_131 -> V_88 = NULL ;
V_131 -> V_138 = V_166 ;
V_131 -> V_135 =
V_124 -> V_135 - 1 ;
V_131 -> V_139 = V_124 ;
V_124 = V_131 ;
goto V_140;
}
} else if ( V_167 == type &&
V_42 -> V_168 ) {
V_124 -> error = F_65 (
V_42 ,
V_124 -> V_136 ,
V_124 -> V_137 ,
V_154 ,
V_129 ) ;
if ( V_124 -> error )
goto V_158;
}
goto V_149;
}
} else {
struct V_169 * const V_170 = (struct V_169 * ) V_124 -> V_138 ;
if ( - 1 == V_124 -> V_48 ) {
V_124 -> V_144 = F_61 ( V_170 -> V_145 . V_146 ) ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76 L_22
L_23 ,
( unsigned long long )
V_124 -> V_137 -> V_95 ,
V_170 -> V_145 . V_141 , V_124 -> V_144 ,
( unsigned long long )
F_60 ( V_170 -> V_145 . V_8 ) ,
( unsigned long long )
F_60 ( V_170 -> V_145 . V_148 ) ) ;
}
V_171:
if ( 0 == V_124 -> V_80 || V_124 -> V_18 > V_124 -> V_80 ) {
V_124 -> V_48 ++ ;
V_124 -> V_80 = 0 ;
}
if ( V_124 -> V_48 < V_124 -> V_144 ) {
struct V_172 V_173 ;
T_2 V_174 ;
T_1 V_81 ;
V_174 = ( V_52 ) ( V_170 -> V_175 + V_124 -> V_48 ) -
( V_52 ) V_170 ;
if ( V_174 + sizeof( struct V_172 ) >
V_124 -> V_137 -> V_156 ) {
F_31 ( V_76
L_24 ,
V_124 -> V_137 -> V_95 ,
V_124 -> V_137 -> V_91 -> V_43 ) ;
goto V_158;
}
F_62 (
V_124 -> V_137 , & V_173 , V_174 ,
sizeof( struct V_172 ) ) ;
V_81 = F_60 ( V_173 . V_176 ) ;
V_124 -> error = F_64 (
V_42 ,
V_124 -> V_136 ,
V_124 -> V_137 ,
V_81 ,
V_124 -> V_135 ,
& V_124 -> V_165 ,
& V_124 -> V_88 ,
V_129 ,
& V_124 -> V_80 ,
& V_124 -> V_18 ,
& V_173 . V_160 ,
F_60 ( V_173 . V_8 ) ) ;
if ( V_124 -> error )
goto V_158;
if ( NULL != V_124 -> V_88 ) {
struct V_132 * const V_166 =
(struct V_132 * )
V_124 -> V_165 . V_134 [ 0 ] ;
V_131 = F_58 () ;
if ( NULL == V_131 )
goto V_158;
V_131 -> V_48 = - 1 ;
V_131 -> V_136 = V_124 -> V_88 ;
V_131 -> V_137 = & V_124 -> V_165 ;
V_131 -> V_88 = NULL ;
V_131 -> V_138 = V_166 ;
V_131 -> V_135 =
V_124 -> V_135 - 1 ;
V_131 -> V_139 = V_124 ;
V_124 = V_131 ;
goto V_140;
}
goto V_171;
}
}
V_158:
if ( NULL != V_124 -> V_139 ) {
struct V_123 * const V_139 = V_124 -> V_139 ;
F_42 ( V_124 -> V_137 ) ;
if ( V_124 -> error ) {
V_139 -> error = V_124 -> error ;
F_59 ( V_124 ) ;
V_124 = V_139 ;
goto V_158;
}
F_59 ( V_124 ) ;
V_124 = V_139 ;
goto V_140;
} else {
F_6 ( & V_130 != V_124 ) ;
}
return V_124 -> error ;
}
static void F_62 (
struct V_89 * V_137 ,
void * V_177 , T_2 V_12 , T_4 V_156 )
{
T_4 V_178 ;
T_4 V_179 ;
char * V_180 ;
char * V_181 = ( char * ) V_177 ;
T_4 V_182 = V_137 -> V_95 & ( ( T_1 ) V_94 - 1 ) ;
unsigned long V_48 = ( V_182 + V_12 ) >> V_183 ;
F_66 ( V_12 + V_156 > V_137 -> V_156 ) ;
V_179 = ( V_182 + V_12 ) &
( ( unsigned long ) V_94 - 1 ) ;
while ( V_156 > 0 ) {
V_178 = F_67 ( V_156 , ( ( T_4 ) V_94 - V_179 ) ) ;
F_6 ( V_48 >= ( V_137 -> V_156 + V_94 - 1 ) >>
V_183 ) ;
V_180 = V_137 -> V_134 [ V_48 ] ;
memcpy ( V_181 , V_180 + V_179 , V_178 ) ;
V_181 += V_178 ;
V_156 -= V_178 ;
V_179 = 0 ;
V_48 ++ ;
}
}
static int F_64 (
struct V_64 * V_42 ,
struct V_1 * V_136 ,
struct V_89 * V_137 ,
T_1 V_81 ,
int V_135 ,
struct V_89 * V_165 ,
struct V_1 * * V_184 ,
int V_129 ,
int * V_185 , int * V_186 ,
struct V_116 * V_10 ,
T_1 V_187 )
{
struct V_1 * V_88 = NULL ;
int V_67 ;
struct V_30 * V_31 ;
int V_188 ;
int V_189 ;
* V_184 = NULL ;
if ( 0 == * V_185 ) {
* V_185 =
F_39 ( V_42 -> V_84 -> V_85 ,
V_81 , V_42 -> V_86 ) ;
if ( V_42 -> V_82 & V_87 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , * V_185 ) ;
* V_186 = 1 ;
}
if ( * V_186 > * V_185 )
return 0 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_25 ,
* V_186 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_42 -> V_86 ,
V_165 , * V_186 ) ;
if ( V_67 ) {
F_31 ( V_76
L_26 ,
( unsigned long long ) V_81 , * V_186 ) ;
F_42 ( V_165 ) ;
* V_184 = NULL ;
return - 1 ;
}
V_88 = F_55 ( V_42 ,
V_165 , L_27 ,
1 , V_129 ,
! V_129 ,
* V_186 ,
& V_189 ) ;
if ( NULL == V_88 ) {
F_42 ( V_165 ) ;
* V_184 = NULL ;
return - 1 ;
}
if ( V_189 ) {
V_31 = NULL ;
V_88 -> V_8 = V_9 ;
} else {
if ( V_88 -> V_7 != V_81 &&
! ( ! V_88 -> V_13 &&
0 == V_88 -> V_7 ) ) {
F_31 ( V_76
L_28
L_29
L_30 ,
( unsigned long long ) V_81 ,
V_165 -> V_91 -> V_43 ,
( unsigned long long ) V_165 -> V_6 ,
* V_186 ,
F_68 ( V_42 , V_88 ) ,
( unsigned long long ) V_88 -> V_7 ) ;
} else if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_28
L_31 ,
( unsigned long long ) V_81 ,
V_165 -> V_91 -> V_43 ,
( unsigned long long ) V_165 -> V_6 ,
* V_186 ,
F_68 ( V_42 , V_88 ) ) ;
V_88 -> V_7 = V_81 ;
V_88 -> V_18 = * V_186 ;
V_31 = F_25 (
V_165 -> V_91 -> V_41 ,
V_165 -> V_6 ,
V_137 -> V_91 -> V_41 ,
V_137 -> V_6 ,
& V_42 -> V_93 ) ;
}
V_88 -> V_10 = * V_10 ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( V_165 ) ;
* V_184 = NULL ;
return - 1 ;
}
V_188 = 1 ;
V_31 -> V_36 = V_88 ;
V_31 -> V_37 = V_136 ;
V_31 -> V_33 = 1 ;
V_31 -> V_187 = V_187 ;
if ( V_42 -> V_82 & V_147 )
F_69 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_136 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_88 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_93 ) ;
} else {
V_188 = 0 ;
if ( 0 == V_135 ) {
V_31 -> V_33 ++ ;
V_31 -> V_187 = V_187 ;
if ( V_42 -> V_82 & V_147 )
F_69 ( V_42 , V_31 ) ;
}
}
if ( V_135 > 0 && V_188 ) {
V_67 = F_41 ( V_42 , V_165 ) ;
if ( V_67 < ( int ) V_165 -> V_156 ) {
F_31 ( V_76
L_32 ,
( unsigned long long ) V_81 ) ;
F_42 ( V_165 ) ;
* V_184 = NULL ;
return - 1 ;
}
* V_184 = V_88 ;
} else {
* V_184 = NULL ;
}
( * V_186 ) ++ ;
return 0 ;
}
static int F_65 (
struct V_64 * V_42 ,
struct V_1 * V_136 ,
struct V_89 * V_137 ,
T_2 V_154 , int V_129 )
{
int V_67 ;
struct V_190 V_191 ;
T_1 V_192 ;
T_1 V_81 ;
T_1 V_193 ;
T_1 V_8 ;
struct V_30 * V_31 ;
V_192 = F_63 ( struct V_142 , V_153 ) +
V_154 ;
if ( V_192 +
F_63 ( struct V_190 , V_194 ) >
V_137 -> V_156 ) {
F_31 ( V_76
L_33 ,
V_137 -> V_95 , V_137 -> V_91 -> V_43 ) ;
return - 1 ;
}
F_62 ( V_137 , & V_191 ,
V_192 ,
F_63 ( struct V_190 , V_194 ) ) ;
if ( V_195 != V_191 . type ||
( ( T_1 ) 0 ) == F_60 ( V_191 . V_196 ) ) {
if ( V_42 -> V_82 & V_197 )
F_31 ( V_76 L_34 ,
V_191 . type ,
( unsigned long long )
F_60 ( V_191 . V_196 ) ) ;
return 0 ;
}
if ( V_192 + sizeof( struct V_190 ) >
V_137 -> V_156 ) {
F_31 ( V_76
L_33 ,
V_137 -> V_95 , V_137 -> V_91 -> V_43 ) ;
return - 1 ;
}
F_62 ( V_137 , & V_191 ,
V_192 ,
sizeof( struct V_190 ) ) ;
V_81 = F_60 ( V_191 . V_196 ) +
F_60 ( V_191 . V_12 ) ;
V_8 = F_60 ( V_191 . V_8 ) ;
V_193 = F_60 ( V_191 . V_193 ) ;
V_8 = F_60 ( V_191 . V_8 ) ;
if ( V_42 -> V_82 & V_197 )
F_31 ( V_76 L_35
L_36 ,
V_191 . type ,
( unsigned long long )
F_60 ( V_191 . V_196 ) ,
( unsigned long long ) F_60 ( V_191 . V_12 ) ,
( unsigned long long ) V_193 ) ;
while ( V_193 > 0 ) {
T_2 V_198 ;
int V_80 ;
int V_18 ;
if ( V_193 > V_42 -> V_111 )
V_198 = V_42 -> V_111 ;
else
V_198 = V_193 ;
V_80 =
F_39 ( V_42 -> V_84 -> V_85 ,
V_81 , V_42 -> V_111 ) ;
if ( V_42 -> V_82 & V_87 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_89 V_165 ;
struct V_1 * V_88 ;
int V_189 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76 L_37
L_38 , V_18 ) ;
if ( V_42 -> V_82 & V_197 )
F_31 ( V_76
L_39 ,
( unsigned long long ) V_81 ,
V_198 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_198 , & V_165 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_40
L_41 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_88 = F_55 (
V_42 ,
& V_165 ,
L_27 ,
0 ,
V_129 ,
! V_129 ,
V_18 ,
& V_189 ) ;
if ( NULL == V_88 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_165 ) ;
return - 1 ;
}
if ( ! V_189 ) {
if ( V_88 -> V_7 != V_81 &&
! ( ! V_88 -> V_13 &&
0 == V_88 -> V_7 ) ) {
F_31 ( V_76
L_42
L_43
L_44
L_45
L_46 ,
( unsigned long long ) V_81 ,
V_165 . V_91 -> V_43 ,
( unsigned long long )
V_165 . V_6 ,
V_18 ,
( unsigned long long )
V_88 -> V_7 ) ;
}
V_88 -> V_7 = V_81 ;
V_88 -> V_18 = V_18 ;
}
V_31 = F_56 ( V_42 ,
& V_165 ,
V_88 , V_136 ,
V_8 ) ;
F_42 ( & V_165 ) ;
if ( NULL == V_31 )
return - 1 ;
}
V_81 += V_198 ;
V_193 -= V_198 ;
}
return 0 ;
}
static int F_40 ( struct V_64 * V_42 , T_1 V_164 , T_2 V_156 ,
struct V_89 * V_199 ,
int V_18 )
{
int V_67 ;
T_1 V_200 ;
struct V_201 * V_202 = NULL ;
struct V_72 * V_73 ;
V_200 = V_156 ;
V_67 = F_70 ( V_42 -> V_84 -> V_85 , V_203 ,
V_164 , & V_200 , & V_202 , V_18 ) ;
if ( V_67 ) {
V_199 -> V_95 = 0 ;
V_199 -> V_6 = 0 ;
V_199 -> V_156 = 0 ;
V_199 -> V_91 = NULL ;
V_199 -> V_134 = NULL ;
V_199 -> V_204 = NULL ;
V_199 -> V_205 = NULL ;
return V_67 ;
}
V_73 = V_202 -> V_206 [ 0 ] . V_91 ;
V_199 -> V_91 = F_33 ( V_73 -> V_41 ) ;
V_199 -> V_6 = V_202 -> V_206 [ 0 ] . V_207 ;
V_199 -> V_95 = V_164 ;
V_199 -> V_156 = V_156 ;
V_199 -> V_134 = NULL ;
V_199 -> V_204 = NULL ;
V_199 -> V_205 = NULL ;
F_7 ( V_202 ) ;
if ( NULL == V_199 -> V_91 ) {
V_67 = - V_208 ;
F_31 ( V_76 L_47 ) ;
}
return V_67 ;
}
static int F_71 ( struct V_64 * V_42 , T_1 V_164 ,
T_2 V_156 , struct V_53 * V_41 ,
struct V_89 * V_199 )
{
V_199 -> V_91 = F_33 ( V_41 ) ;
V_199 -> V_6 = V_164 ;
V_199 -> V_95 = V_164 ;
V_199 -> V_156 = V_156 ;
V_199 -> V_134 = NULL ;
V_199 -> V_204 = NULL ;
V_199 -> V_205 = NULL ;
if ( NULL != V_199 -> V_91 ) {
return 0 ;
} else {
F_31 ( V_76 L_48 ) ;
return - V_208 ;
}
}
static void F_42 ( struct V_89 * V_137 )
{
if ( V_137 -> V_205 ) {
unsigned int V_209 ;
F_6 ( ! V_137 -> V_134 ) ;
F_6 ( ! V_137 -> V_204 ) ;
V_209 = ( V_137 -> V_156 + ( T_1 ) V_94 - 1 ) >>
V_183 ;
while ( V_209 > 0 ) {
V_209 -- ;
if ( V_137 -> V_134 [ V_209 ] ) {
F_72 ( V_137 -> V_204 [ V_209 ] ) ;
V_137 -> V_134 [ V_209 ] = NULL ;
}
if ( V_137 -> V_204 [ V_209 ] ) {
F_73 ( V_137 -> V_204 [ V_209 ] ) ;
V_137 -> V_204 [ V_209 ] = NULL ;
}
}
F_7 ( V_137 -> V_205 ) ;
V_137 -> V_205 = NULL ;
V_137 -> V_204 = NULL ;
V_137 -> V_134 = NULL ;
}
}
static int F_41 ( struct V_64 * V_42 ,
struct V_89 * V_137 )
{
unsigned int V_209 ;
unsigned int V_48 ;
T_1 V_6 ;
int V_67 ;
F_6 ( V_137 -> V_134 ) ;
F_6 ( V_137 -> V_204 ) ;
F_6 ( V_137 -> V_205 ) ;
if ( V_137 -> V_6 & ( ( T_1 ) V_94 - 1 ) ) {
F_31 ( V_76
L_49 ,
( unsigned long long ) V_137 -> V_6 ) ;
return - 1 ;
}
V_209 = ( V_137 -> V_156 + ( T_1 ) V_94 - 1 ) >>
V_183 ;
V_137 -> V_205 = F_4 ( ( sizeof( * V_137 -> V_134 ) +
sizeof( * V_137 -> V_204 ) ) *
V_209 , V_29 ) ;
if ( ! V_137 -> V_205 )
return - 1 ;
V_137 -> V_134 = V_137 -> V_205 ;
V_137 -> V_204 = (struct V_210 * * ) ( V_137 -> V_134 + V_209 ) ;
for ( V_48 = 0 ; V_48 < V_209 ; V_48 ++ ) {
V_137 -> V_204 [ V_48 ] = F_74 ( V_29 ) ;
if ( ! V_137 -> V_204 [ V_48 ] )
return - 1 ;
}
V_6 = V_137 -> V_6 ;
for ( V_48 = 0 ; V_48 < V_209 ; ) {
struct V_22 * V_22 ;
unsigned int V_211 ;
F_75 ( V_212 ) ;
V_22 = F_76 ( V_29 , V_209 - V_48 ) ;
if ( ! V_22 ) {
F_31 ( V_76
L_50 ,
V_209 - V_48 ) ;
return - 1 ;
}
V_22 -> V_213 = V_137 -> V_91 -> V_41 ;
V_22 -> V_214 = V_6 >> 9 ;
V_22 -> V_215 = V_216 ;
V_22 -> V_217 = & V_212 ;
for ( V_211 = V_48 ; V_211 < V_209 ; V_211 ++ ) {
V_67 = F_77 ( V_22 , V_137 -> V_204 [ V_211 ] ,
V_94 , 0 ) ;
if ( V_94 != V_67 )
break;
}
if ( V_211 == V_48 ) {
F_31 ( V_76
L_51 ) ;
return - 1 ;
}
F_78 ( V_203 , V_22 ) ;
F_79 ( & V_212 ) ;
if ( ! F_80 ( V_218 , & V_22 -> V_219 ) ) {
F_31 ( V_76
L_52 ,
V_137 -> V_95 , V_137 -> V_91 -> V_43 ) ;
F_81 ( V_22 ) ;
return - 1 ;
}
F_81 ( V_22 ) ;
V_6 += ( V_211 - V_48 ) * V_94 ;
V_48 = V_211 ;
}
for ( V_48 = 0 ; V_48 < V_209 ; V_48 ++ ) {
V_137 -> V_134 [ V_48 ] = F_82 ( V_137 -> V_204 [ V_48 ] ) ;
if ( ! V_137 -> V_134 [ V_48 ] ) {
F_31 ( V_76 L_53 ,
V_137 -> V_91 -> V_43 ) ;
return - 1 ;
}
}
return V_137 -> V_156 ;
}
static void V_216 ( struct V_22 * V_22 , int V_220 )
{
V_212 ( (struct V_221 * ) V_22 -> V_217 ) ;
}
static void F_83 ( struct V_64 * V_42 )
{
struct V_54 * V_222 ;
F_6 ( NULL == V_42 ) ;
F_31 ( V_76 L_54 ) ;
F_20 (elem_all, &state->all_blocks_list) {
const struct V_1 * const V_223 =
F_21 ( V_222 , struct V_1 ,
V_24 ) ;
struct V_54 * V_224 ;
struct V_54 * V_225 ;
F_31 ( V_76 L_55 ,
F_68 ( V_42 , V_223 ) ,
( unsigned long long ) V_223 -> V_7 ,
V_223 -> V_5 -> V_43 ,
( unsigned long long ) V_223 -> V_6 ,
V_223 -> V_18 ) ;
F_20 (elem_ref_to, &b_all->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_224 ,
struct V_30 ,
V_34 ) ;
F_31 ( V_76 L_56
L_57
L_58 ,
F_68 ( V_42 , V_223 ) ,
( unsigned long long ) V_223 -> V_7 ,
V_223 -> V_5 -> V_43 ,
( unsigned long long ) V_223 -> V_6 ,
V_223 -> V_18 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
F_20 (elem_ref_from, &b_all->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_225 ,
struct V_30 ,
V_35 ) ;
F_31 ( V_76 L_56
L_59
L_58 ,
F_68 ( V_42 , V_223 ) ,
( unsigned long long ) V_223 -> V_7 ,
V_223 -> V_5 -> V_43 ,
( unsigned long long ) V_223 -> V_6 ,
V_223 -> V_18 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long )
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long )
V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ) ;
}
F_31 ( V_76 L_60 ) ;
}
}
static int F_84 ( struct V_64 * V_42 ,
char * * V_134 , unsigned int V_209 )
{
struct V_132 * V_47 ;
T_3 V_226 [ V_227 ] ;
T_2 V_228 = ~ ( T_2 ) 0 ;
unsigned int V_48 ;
if ( V_209 * V_94 < V_42 -> V_86 )
return 1 ;
V_209 = V_42 -> V_86 >> V_183 ;
V_47 = (struct V_132 * ) V_134 [ 0 ] ;
if ( memcmp ( V_47 -> V_229 , V_42 -> V_84 -> V_85 -> V_229 , V_110 ) )
return 1 ;
for ( V_48 = 0 ; V_48 < V_209 ; V_48 ++ ) {
T_3 * V_230 = V_48 ? V_134 [ V_48 ] : ( V_134 [ V_48 ] + V_227 ) ;
T_4 V_231 = V_48 ? V_94 :
( V_94 - V_227 ) ;
V_228 = F_85 ( V_228 , V_230 , V_231 ) ;
}
F_86 ( V_228 , V_226 ) ;
if ( memcmp ( V_226 , V_47 -> V_226 , V_42 -> V_79 ) )
return 1 ;
return 0 ;
}
static void F_87 ( struct V_38 * V_5 ,
T_1 V_6 , char * * V_232 ,
unsigned int V_209 ,
struct V_22 * V_22 , int * V_233 ,
struct V_99 * V_100 ,
int V_27 )
{
int V_13 ;
struct V_1 * V_136 ;
struct V_89 V_137 ;
int V_67 ;
struct V_64 * V_42 = V_5 -> V_42 ;
struct V_53 * V_41 = V_5 -> V_41 ;
unsigned int V_234 ;
if ( NULL != V_233 )
* V_233 = 0 ;
V_235:
if ( V_209 == 0 )
return;
V_234 = 0 ;
V_13 = ( 0 == F_84 ( V_42 , V_232 ,
V_209 ) ) ;
V_136 = F_19 ( V_41 , V_6 ,
& V_42 -> V_92 ) ;
if ( NULL != V_136 ) {
T_1 V_164 = 0 ;
struct V_54 * V_224 ;
struct V_54 * V_236 ;
if ( V_136 -> V_14 ) {
V_164 = F_60 ( ( (struct V_68 * )
V_232 [ 0 ] ) -> V_164 ) ;
if ( V_209 * V_94 <
V_103 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_13 = 1 ;
F_6 ( V_103 & ( V_94 - 1 ) ) ;
V_234 = V_103 ;
if ( V_42 -> V_82 &
V_237 ) {
F_31 ( V_76
L_62 ) ;
F_57 ( V_42 , V_136 , 0 ) ;
}
}
if ( V_13 ) {
if ( ! V_136 -> V_14 ) {
if ( V_209 * V_94 <
V_42 -> V_86 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_234 = V_42 -> V_86 ;
V_164 = F_60 ( ( (struct V_132 * )
V_232 [ 0 ] ) -> V_164 ) ;
F_88 ( V_42 , V_164 ,
V_5 ,
V_6 ) ;
}
if ( V_136 -> V_7 != V_164 ) {
F_31 ( V_76
L_63
L_29
L_45
L_46 ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_136 -> V_18 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long )
V_136 -> V_7 ) ;
V_136 -> V_7 = V_164 ;
} else if ( V_42 -> V_82 &
V_147 )
F_31 ( V_76
L_63
L_31 ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_136 -> V_18 ,
F_68 ( V_42 , V_136 ) ) ;
} else {
if ( V_209 * V_94 <
V_42 -> V_111 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_234 = V_42 -> V_111 ;
V_164 = V_136 -> V_7 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_63
L_31 ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_136 -> V_18 ,
F_68 ( V_42 , V_136 ) ) ;
}
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_64 ,
F_89 ( & V_136 -> V_25 ) ? ' ' : '!' ,
F_89 ( & V_136 -> V_26 ) ? ' ' : '!' ) ;
if ( F_90 ( V_42 , V_136 , 0 ) ) {
F_31 ( V_76 L_65
L_66
L_67
L_68
L_69
L_70 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_136 -> V_18 ,
( unsigned long long ) V_136 -> V_8 ,
( unsigned long long )
F_60 ( V_136 -> V_10 . V_11 ) ,
V_136 -> V_10 . type ,
( unsigned long long )
F_60 ( V_136 -> V_10 . V_12 ) ,
( unsigned long long )
F_60 ( ( (struct V_132 * )
V_232 [ 0 ] ) -> V_8 ) ,
( unsigned long long )
V_42 -> V_114 ) ;
F_91 ( V_42 ) ;
}
if ( ! V_136 -> V_15 && ! V_136 -> V_17 ) {
F_31 ( V_76 L_65
L_71
L_72 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_136 -> V_18 ,
( unsigned long long ) V_136 -> V_8 ,
( unsigned long long )
F_60 ( ( (struct V_132 * )
V_232 [ 0 ] ) -> V_8 ) ) ;
F_91 ( V_42 ) ;
goto V_238;
}
F_92 (elem_ref_to, tmp_ref_to,
&block->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_224 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_147 )
F_93 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 ) {
F_18 ( & V_31 -> V_34 ) ;
F_18 ( & V_31 -> V_35 ) ;
F_24 ( V_31 ) ;
F_10 ( V_31 ) ;
}
}
if ( V_136 -> V_14 )
V_67 = F_71 ( V_42 , V_164 ,
V_234 ,
V_41 , & V_137 ) ;
else
V_67 = F_40 ( V_42 , V_164 , V_234 ,
& V_137 , 0 ) ;
if ( V_67 ) {
F_31 ( V_76
L_73
L_74 , ( unsigned long long ) V_164 ) ;
goto V_238;
}
V_137 . V_134 = V_232 ;
V_137 . V_91 = V_5 ;
V_137 . V_6 = V_6 ;
if ( V_13 || V_42 -> V_168 ) {
V_136 -> V_17 = 0 ;
V_136 -> V_16 = 0 ;
if ( NULL != V_22 ) {
V_136 -> V_15 = 0 ;
F_6 ( NULL == V_233 ) ;
if ( ! * V_233 ) {
V_136 -> V_20 =
V_22 -> V_217 ;
V_136 -> V_21 . V_22 =
V_22 -> V_215 ;
V_136 -> V_19 = NULL ;
V_22 -> V_217 = V_136 ;
V_22 -> V_215 = V_239 ;
* V_233 = 1 ;
} else {
struct V_1 * V_240 =
(struct V_1 * )
V_22 -> V_217 ;
F_6 ( NULL == V_240 ) ;
V_136 -> V_20 =
V_240 -> V_20 ;
V_136 -> V_21 . V_22 =
V_240 -> V_21 .
V_22 ;
V_136 -> V_19 = V_240 ;
V_22 -> V_217 = V_136 ;
}
} else if ( NULL != V_100 ) {
V_136 -> V_15 = 0 ;
V_136 -> V_20 = V_100 -> V_241 ;
V_136 -> V_21 . V_100 = V_100 -> V_242 ;
V_136 -> V_19 = NULL ;
V_100 -> V_241 = V_136 ;
V_100 -> V_242 = V_243 ;
} else {
V_136 -> V_15 = 1 ;
V_136 -> V_20 = NULL ;
V_136 -> V_21 . V_22 = NULL ;
V_136 -> V_19 = NULL ;
}
}
V_136 -> V_28 = V_5 -> V_44 + 1 ;
V_136 -> V_27 = V_27 ;
if ( V_13 ) {
V_136 -> V_7 = V_164 ;
V_136 -> V_13 = 1 ;
if ( V_136 -> V_14 ) {
F_6 ( V_94 !=
V_103 ) ;
V_67 = F_94 (
V_42 ,
V_136 ,
(struct V_68 * )
V_232 [ 0 ] ) ;
if ( V_42 -> V_82 &
V_244 ) {
F_31 ( V_76
L_75 ) ;
F_57 ( V_42 , V_136 , 0 ) ;
}
} else {
V_136 -> V_18 = 0 ;
V_67 = F_43 (
V_42 ,
V_136 ,
& V_137 ,
0 , 0 ) ;
}
if ( V_67 )
F_31 ( V_76
L_76
L_77 ,
( unsigned long long ) V_6 ) ;
} else {
V_136 -> V_13 = 0 ;
V_136 -> V_18 = 0 ;
V_136 -> V_8 = V_9 ;
if ( ! V_42 -> V_168
&& F_89 ( & V_136 -> V_26 ) ) {
F_17 ( V_136 ) ;
F_18 ( & V_136 -> V_24 ) ;
F_5 ( V_136 ) ;
}
}
F_42 ( & V_137 ) ;
} else {
T_1 V_164 ;
if ( ! V_13 ) {
V_234 = V_42 -> V_111 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76 L_78
L_79 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
if ( ! V_42 -> V_168 ) {
goto V_238;
}
V_164 = 0 ;
V_137 . V_95 = V_164 ;
V_137 . V_156 = V_234 ;
V_137 . V_205 = NULL ;
V_137 . V_204 = NULL ;
} else {
V_234 = V_42 -> V_86 ;
V_164 = F_60 ( ( (struct V_132 * )
V_232 [ 0 ] ) -> V_164 ) ;
F_88 ( V_42 , V_164 , V_5 ,
V_6 ) ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_80
L_81 ,
( unsigned long long ) V_164 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
V_67 = F_40 ( V_42 , V_164 , V_234 ,
& V_137 , 0 ) ;
if ( V_67 ) {
F_31 ( V_76
L_73
L_74 ,
( unsigned long long ) V_6 ) ;
goto V_238;
}
}
V_137 . V_134 = V_232 ;
V_137 . V_91 = V_5 ;
V_137 . V_6 = V_6 ;
V_136 = F_3 () ;
if ( NULL == V_136 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( & V_137 ) ;
goto V_238;
}
V_136 -> V_5 = V_5 ;
V_136 -> V_6 = V_6 ;
V_136 -> V_7 = V_164 ;
V_136 -> V_13 = V_13 ;
V_136 -> V_17 = 0 ;
V_136 -> V_16 = 0 ;
V_136 -> V_18 = 0 ;
V_136 -> V_28 = V_5 -> V_44 + 1 ;
V_136 -> V_27 = V_27 ;
if ( NULL != V_22 ) {
V_136 -> V_15 = 0 ;
F_6 ( NULL == V_233 ) ;
if ( ! * V_233 ) {
V_136 -> V_20 = V_22 -> V_217 ;
V_136 -> V_21 . V_22 = V_22 -> V_215 ;
V_136 -> V_19 = NULL ;
V_22 -> V_217 = V_136 ;
V_22 -> V_215 = V_239 ;
* V_233 = 1 ;
} else {
struct V_1 * V_240 =
(struct V_1 * )
V_22 -> V_217 ;
F_6 ( NULL == V_240 ) ;
V_136 -> V_20 =
V_240 -> V_20 ;
V_136 -> V_21 . V_22 =
V_240 -> V_21 . V_22 ;
V_136 -> V_19 = V_240 ;
V_22 -> V_217 = V_136 ;
}
} else if ( NULL != V_100 ) {
V_136 -> V_15 = 0 ;
V_136 -> V_20 = V_100 -> V_241 ;
V_136 -> V_21 . V_100 = V_100 -> V_242 ;
V_136 -> V_19 = NULL ;
V_100 -> V_241 = V_136 ;
V_100 -> V_242 = V_243 ;
} else {
V_136 -> V_15 = 1 ;
V_136 -> V_20 = NULL ;
V_136 -> V_21 . V_22 = NULL ;
V_136 -> V_19 = NULL ;
}
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_82 ,
V_13 ? 'M' : 'D' ,
( unsigned long long ) V_136 -> V_7 ,
V_136 -> V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ) ;
F_16 ( & V_136 -> V_24 , & V_42 -> V_113 ) ;
F_15 ( V_136 , & V_42 -> V_92 ) ;
if ( V_13 ) {
V_67 = F_43 ( V_42 , V_136 ,
& V_137 , 0 , 0 ) ;
if ( V_67 )
F_31 ( V_76
L_83
L_74 ,
( unsigned long long ) V_6 ) ;
}
F_42 ( & V_137 ) ;
}
V_238:
F_6 ( ! V_234 ) ;
V_6 += V_234 ;
V_232 += V_234 >> V_183 ;
V_209 -= V_234 >> V_183 ;
goto V_235;
}
static void V_239 ( struct V_22 * V_245 , int V_246 )
{
struct V_1 * V_136 = (struct V_1 * ) V_245 -> V_217 ;
int V_16 ;
V_16 = 0 ;
if ( V_246 )
V_16 = 1 ;
F_6 ( NULL == V_136 ) ;
V_245 -> V_217 = V_136 -> V_20 ;
V_245 -> V_215 = V_136 -> V_21 . V_22 ;
do {
struct V_1 * V_88 ;
struct V_38 * const V_5 = V_136 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 &
V_247 ) )
F_31 ( V_76
L_84 ,
V_246 ,
F_68 ( V_5 -> V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ) ;
V_88 = V_136 -> V_19 ;
V_136 -> V_16 = V_16 ;
if ( V_136 -> V_27 & V_248 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_247 ) )
F_31 ( V_76
L_85 ,
V_5 -> V_43 ,
( unsigned long long )
V_5 -> V_44 ) ;
}
if ( V_136 -> V_27 & V_249 )
V_136 -> V_28 = 0 ;
V_136 -> V_15 = 1 ;
V_136 = V_88 ;
} while ( NULL != V_136 );
V_245 -> V_215 ( V_245 , V_246 ) ;
}
static void V_243 ( struct V_99 * V_100 , int V_250 )
{
struct V_1 * V_136 = (struct V_1 * ) V_100 -> V_241 ;
int V_16 = ! V_250 ;
struct V_38 * V_5 ;
F_6 ( NULL == V_136 ) ;
V_5 = V_136 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 & V_247 ) )
F_31 ( V_76
L_86 ,
V_16 ,
F_68 ( V_5 -> V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_136 -> V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ) ;
V_136 -> V_16 = V_16 ;
if ( V_136 -> V_27 & V_248 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_247 ) )
F_31 ( V_76
L_87 ,
V_5 -> V_43 ,
( unsigned long long ) V_5 -> V_44 ) ;
}
if ( V_136 -> V_27 & V_249 )
V_136 -> V_28 = 0 ;
V_100 -> V_241 = V_136 -> V_20 ;
V_100 -> V_242 = V_136 -> V_21 . V_100 ;
V_136 -> V_15 = 1 ;
V_100 -> V_242 ( V_100 , V_250 ) ;
}
static int F_94 (
struct V_64 * V_42 ,
struct V_1 * const V_251 ,
struct V_68 * const V_252 )
{
int V_75 ;
V_251 -> V_8 = F_51 ( V_252 ) ;
if ( ! ( V_251 -> V_8 > V_42 -> V_114 ||
0 == V_42 -> V_114 ) ) {
if ( V_42 -> V_82 & V_112 )
F_31 ( V_76
L_88
L_89 ,
( unsigned long long ) V_251 -> V_7 ,
V_251 -> V_5 -> V_43 ,
( unsigned long long ) V_251 -> V_6 ,
V_251 -> V_18 ,
( unsigned long long )
F_51 ( V_252 ) ,
( unsigned long long )
V_42 -> V_114 ) ;
} else {
if ( V_42 -> V_82 & V_112 )
F_31 ( V_76
L_90
L_91 ,
( unsigned long long ) V_251 -> V_7 ,
V_251 -> V_5 -> V_43 ,
( unsigned long long ) V_251 -> V_6 ,
V_251 -> V_18 ,
( unsigned long long )
F_51 ( V_252 ) ,
( unsigned long long )
V_42 -> V_114 ) ;
V_42 -> V_114 =
F_51 ( V_252 ) ;
V_42 -> V_78 = V_251 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_67 ;
T_1 V_81 ;
struct V_1 * V_88 ;
struct V_89 V_90 ;
struct V_30 * V_31 ;
int V_80 ;
int V_18 ;
const char * V_115 = NULL ;
struct V_116 V_117 ;
V_117 . type = V_118 ;
V_117 . V_12 = 0 ;
switch ( V_75 ) {
case 0 :
V_117 . V_11 =
F_54 ( V_119 ) ;
V_115 = L_92 ;
V_81 = F_36 ( V_252 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_3 ,
( unsigned long long ) V_81 ) ;
break;
case 1 :
V_117 . V_11 =
F_54 ( V_120 ) ;
V_115 = L_93 ;
V_81 = F_37 ( V_252 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_4 ,
( unsigned long long ) V_81 ) ;
break;
case 2 :
V_117 . V_11 =
F_54 ( V_121 ) ;
V_115 = L_94 ;
V_81 = F_38 ( V_252 ) ;
if ( 0 == V_81 )
continue;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_5 ,
( unsigned long long ) V_81 ) ;
break;
}
V_80 =
F_39 ( V_42 -> V_84 -> V_85 ,
V_81 , V_103 ) ;
if ( V_42 -> V_82 & V_87 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
int V_253 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_95
L_38 , V_18 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_103 ,
& V_90 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_40
L_41 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_88 = F_55 (
V_42 ,
& V_90 ,
V_115 ,
1 , 0 , 1 ,
V_18 ,
& V_253 ) ;
if ( NULL == V_88 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_90 ) ;
return - 1 ;
}
V_88 -> V_10 = V_117 ;
if ( V_253 )
V_88 -> V_8 =
V_9 ;
V_31 = F_56 (
V_42 ,
& V_90 ,
V_88 ,
V_251 ,
V_9 ) ;
F_42 ( & V_90 ) ;
if ( NULL == V_31 )
return - 1 ;
}
}
if ( - 1 == F_95 ( V_42 , V_251 , 0 ) ) {
F_66 ( 1 ) ;
F_91 ( V_42 ) ;
}
return 0 ;
}
static int F_95 ( struct V_64 * V_42 ,
struct V_1 * const V_136 ,
int V_254 )
{
struct V_54 * V_224 ;
int V_67 = 0 ;
if ( V_254 >= 3 + V_96 ) {
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_96 ) ;
return V_67 ;
}
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_224 , struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_97
L_98 ,
V_254 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_136 -> V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
if ( V_31 -> V_36 -> V_17 ) {
F_31 ( V_76 L_99
L_100
L_101 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( ! V_31 -> V_36 -> V_15 ) {
F_31 ( V_76 L_99
L_100
L_72 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_16 ) {
F_31 ( V_76 L_99
L_100
L_102 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_187 !=
V_31 -> V_36 -> V_8 &&
V_9 !=
V_31 -> V_187 &&
V_9 !=
V_31 -> V_36 -> V_8 ) {
F_31 ( V_76 L_99
L_100
L_103
L_104 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_31 -> V_36 -> V_8 ,
( unsigned long long ) V_31 -> V_187 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_28 >
V_31 -> V_36 -> V_5 -> V_44 ) {
F_31 ( V_76 L_99
L_100
L_105
L_106
L_107 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_136 -> V_28 ,
( unsigned long long )
V_31 -> V_36 -> V_5 -> V_44 ) ;
V_67 = - 1 ;
} else if ( - 1 == F_95 ( V_42 ,
V_31 -> V_36 ,
V_254 +
1 ) ) {
V_67 = - 1 ;
}
}
return V_67 ;
}
static int F_90 (
const struct V_64 * V_42 ,
const struct V_1 * V_136 ,
int V_254 )
{
struct V_54 * V_225 ;
if ( V_254 >= 3 + V_96 ) {
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_108 ) ;
return 0 ;
}
F_20 (elem_ref_from, &block->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_225 , struct V_30 ,
V_35 ) ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_97
L_109 ,
V_254 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_136 -> V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long )
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long )
V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ) ;
if ( V_31 -> V_37 -> V_14 &&
V_42 -> V_78 -> V_6 ==
V_31 -> V_37 -> V_6 &&
V_42 -> V_78 -> V_5 -> V_41 ==
V_31 -> V_37 -> V_5 -> V_41 )
return 1 ;
else if ( F_90 ( V_42 ,
V_31 -> V_37 ,
V_254 +
1 ) )
return 1 ;
}
return 0 ;
}
static void F_69 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_31 ( V_76
L_110
L_111 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long ) V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long ) V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static void F_93 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_31 ( V_76
L_112
L_111 ,
V_31 -> V_33 ,
F_68 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long ) V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long ) V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static char F_68 ( const struct V_64 * V_42 ,
const struct V_1 * V_136 )
{
if ( V_136 -> V_14 &&
V_42 -> V_78 -> V_6 == V_136 -> V_6 &&
V_42 -> V_78 -> V_5 -> V_41 == V_136 -> V_5 -> V_41 )
return 'S' ;
else if ( V_136 -> V_14 )
return 's' ;
else if ( V_136 -> V_13 )
return 'M' ;
else
return 'D' ;
}
static void F_91 ( const struct V_64 * V_42 )
{
F_57 ( V_42 , V_42 -> V_78 , 0 ) ;
}
static void F_57 ( const struct V_64 * V_42 ,
const struct V_1 * V_136 ,
int V_255 )
{
struct V_54 * V_224 ;
int V_256 ;
static char V_257 [ 80 ] ;
int V_258 ;
V_256 = sprintf ( V_257 , L_113 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_136 -> V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_136 -> V_18 ) ;
if ( V_255 + V_256 > V_259 ) {
F_31 ( L_114 ) ;
return;
}
F_31 ( V_257 ) ;
V_255 += V_256 ;
if ( F_89 ( & V_136 -> V_25 ) ) {
F_31 ( L_60 ) ;
return;
}
if ( V_136 -> V_18 > 1 &&
! ( V_42 -> V_82 & V_260 ) ) {
F_31 ( L_115 ) ;
return;
}
V_258 = V_255 ;
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_224 , struct V_30 ,
V_34 ) ;
while ( V_258 < V_255 ) {
F_31 ( L_116 ) ;
V_258 ++ ;
}
if ( V_31 -> V_33 > 1 )
V_256 = sprintf ( V_257 , L_117 , V_31 -> V_33 ) ;
else
V_256 = sprintf ( V_257 , L_118 ) ;
if ( V_255 + V_256 >
V_259 ) {
F_31 ( L_114 ) ;
V_258 = 0 ;
continue;
}
F_31 ( V_257 ) ;
F_57 ( V_42 , V_31 -> V_36 ,
V_255 + V_256 ) ;
V_258 = 0 ;
}
}
static struct V_30 * F_56 (
struct V_64 * V_42 ,
struct V_89 * V_165 ,
struct V_1 * V_88 ,
struct V_1 * V_261 ,
T_1 V_187 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( V_165 -> V_91 -> V_41 ,
V_165 -> V_6 ,
V_261 -> V_5 -> V_41 ,
V_261 -> V_6 ,
& V_42 -> V_93 ) ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76
L_119 L_74 ) ;
return NULL ;
}
V_31 -> V_36 = V_88 ;
V_31 -> V_37 = V_261 ;
V_31 -> V_33 = 1 ;
V_31 -> V_187 = V_187 ;
if ( V_42 -> V_82 & V_147 )
F_69 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_261 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_88 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_93 ) ;
} else {
V_31 -> V_33 ++ ;
V_31 -> V_187 = V_187 ;
if ( V_42 -> V_82 & V_147 )
F_69 ( V_42 , V_31 ) ;
}
return V_31 ;
}
static struct V_1 * F_55 (
struct V_64 * V_42 ,
struct V_89 * V_137 ,
const char * V_115 ,
int V_13 ,
int V_15 ,
int V_17 ,
int V_18 ,
int * V_253 )
{
struct V_1 * V_136 ;
V_136 = F_19 ( V_137 -> V_91 -> V_41 ,
V_137 -> V_6 ,
& V_42 -> V_92 ) ;
if ( NULL == V_136 ) {
struct V_38 * V_5 ;
V_136 = F_3 () ;
if ( NULL == V_136 ) {
F_31 ( V_76 L_1 ) ;
return NULL ;
}
V_5 = F_33 ( V_137 -> V_91 -> V_41 ) ;
if ( NULL == V_5 ) {
F_31 ( V_76
L_120 ) ;
F_5 ( V_136 ) ;
return NULL ;
}
V_136 -> V_5 = V_5 ;
V_136 -> V_6 = V_137 -> V_6 ;
V_136 -> V_7 = V_137 -> V_95 ;
V_136 -> V_13 = V_13 ;
V_136 -> V_15 = V_15 ;
V_136 -> V_17 = V_17 ;
V_136 -> V_18 = V_18 ;
if ( V_42 -> V_82 & V_147 )
F_31 ( V_76
L_121 ,
V_115 ,
F_68 ( V_42 , V_136 ) ,
( unsigned long long ) V_136 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_136 -> V_6 ,
V_18 ) ;
F_16 ( & V_136 -> V_24 , & V_42 -> V_113 ) ;
F_15 ( V_136 , & V_42 -> V_92 ) ;
if ( NULL != V_253 )
* V_253 = 1 ;
} else {
if ( NULL != V_253 )
* V_253 = 0 ;
}
return V_136 ;
}
static void F_88 ( struct V_64 * V_42 ,
T_1 V_164 ,
struct V_38 * V_5 ,
T_1 V_6 )
{
int V_80 ;
int V_18 ;
int V_67 ;
struct V_89 V_137 ;
int V_262 = 0 ;
V_80 = F_39 ( V_42 -> V_84 -> V_85 ,
V_164 , V_42 -> V_86 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_164 , V_42 -> V_86 ,
& V_137 , V_18 ) ;
if ( V_67 ) {
F_31 ( V_76 L_7
L_122
L_9 ,
( unsigned long long ) V_164 , V_18 ) ;
continue;
}
if ( V_5 -> V_41 == V_137 . V_91 -> V_41 &&
V_6 == V_137 . V_6 ) {
V_262 ++ ;
F_42 ( & V_137 ) ;
break;
}
F_42 ( & V_137 ) ;
}
if ( ! V_262 ) {
F_31 ( V_76 L_123
L_124
L_125 ,
( unsigned long long ) V_164 , V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_164 ,
V_42 -> V_86 ,
& V_137 , V_18 ) ;
if ( V_67 )
continue;
F_31 ( V_76 L_126
L_127 ,
( unsigned long long ) V_164 ,
V_137 . V_91 -> V_43 ,
( unsigned long long ) V_137 . V_6 ,
V_18 ) ;
}
F_66 ( 1 ) ;
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
int F_96 ( int V_263 , struct V_99 * V_100 )
{
struct V_38 * V_5 ;
if ( ! V_264 )
return F_97 ( V_263 , V_100 ) ;
F_98 ( & V_265 ) ;
V_5 = F_33 ( V_100 -> V_266 ) ;
if ( NULL != V_5 &&
( V_263 & V_267 ) && V_100 -> V_268 > 0 ) {
T_1 V_6 ;
V_6 = 4096 * V_100 -> V_269 ;
if ( V_5 -> V_42 -> V_82 &
V_270 )
F_31 ( V_76
L_128
L_129 ,
V_263 , ( unsigned long ) V_100 -> V_269 ,
( unsigned long long ) V_6 ,
( unsigned long ) V_100 -> V_268 , V_100 -> V_105 ,
V_100 -> V_266 ) ;
F_87 ( V_5 , V_6 ,
& V_100 -> V_105 , 1 , NULL ,
NULL , V_100 , V_263 ) ;
} else if ( NULL != V_5 && ( V_263 & V_248 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_270 )
F_31 ( V_76
L_130 ,
V_263 , V_100 -> V_266 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_270 |
V_147 ) ) )
F_31 ( V_76
L_131
L_132
L_133 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_136 =
& V_5 -> V_45 ;
V_136 -> V_15 = 0 ;
V_136 -> V_17 = 0 ;
V_136 -> V_16 = 0 ;
V_136 -> V_28 = V_5 -> V_44 + 1 ;
V_136 -> V_27 = V_263 ;
V_136 -> V_20 = V_100 -> V_241 ;
V_136 -> V_21 . V_100 = V_100 -> V_242 ;
V_136 -> V_19 = NULL ;
V_100 -> V_241 = V_136 ;
V_100 -> V_242 = V_243 ;
}
}
F_99 ( & V_265 ) ;
return F_97 ( V_263 , V_100 ) ;
}
void F_100 ( int V_263 , struct V_22 * V_22 )
{
struct V_38 * V_5 ;
if ( ! V_264 ) {
F_78 ( V_263 , V_22 ) ;
return;
}
F_98 ( & V_265 ) ;
V_5 = F_33 ( V_22 -> V_213 ) ;
if ( NULL != V_5 &&
( V_263 & V_267 ) && NULL != V_22 -> V_271 ) {
unsigned int V_48 ;
T_1 V_6 ;
int V_233 ;
char * * V_232 ;
V_6 = 512 * V_22 -> V_214 ;
V_233 = 0 ;
if ( V_5 -> V_42 -> V_82 &
V_270 )
F_31 ( V_76
L_134
L_135 ,
V_263 , V_22 -> V_272 , ( unsigned long ) V_22 -> V_214 ,
( unsigned long long ) V_6 ,
V_22 -> V_213 ) ;
V_232 = F_101 ( sizeof( * V_232 ) * V_22 -> V_272 ,
V_29 ) ;
if ( ! V_232 )
goto V_273;
for ( V_48 = 0 ; V_48 < V_22 -> V_272 ; V_48 ++ ) {
F_6 ( V_22 -> V_271 [ V_48 ] . V_274 != V_94 ) ;
V_232 [ V_48 ] = F_82 ( V_22 -> V_271 [ V_48 ] . V_275 ) ;
if ( ! V_232 [ V_48 ] ) {
while ( V_48 > 0 ) {
V_48 -- ;
F_72 ( V_22 -> V_271 [ V_48 ] . V_275 ) ;
}
F_7 ( V_232 ) ;
goto V_273;
}
if ( ( V_270 |
V_147 ) ==
( V_5 -> V_42 -> V_82 &
( V_270 |
V_147 ) ) )
F_31 ( V_76
L_136 ,
V_48 , V_22 -> V_271 [ V_48 ] . V_275 ,
V_22 -> V_271 [ V_48 ] . V_274 ,
V_22 -> V_271 [ V_48 ] . V_276 ) ;
}
F_87 ( V_5 , V_6 ,
V_232 , V_22 -> V_272 ,
V_22 , & V_233 ,
NULL , V_263 ) ;
while ( V_48 > 0 ) {
V_48 -- ;
F_72 ( V_22 -> V_271 [ V_48 ] . V_275 ) ;
}
F_7 ( V_232 ) ;
} else if ( NULL != V_5 && ( V_263 & V_248 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_270 )
F_31 ( V_76
L_137 ,
V_263 , V_22 -> V_213 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_270 |
V_147 ) ) )
F_31 ( V_76
L_138
L_132
L_133 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_136 =
& V_5 -> V_45 ;
V_136 -> V_15 = 0 ;
V_136 -> V_17 = 0 ;
V_136 -> V_16 = 0 ;
V_136 -> V_28 = V_5 -> V_44 + 1 ;
V_136 -> V_27 = V_263 ;
V_136 -> V_20 = V_22 -> V_217 ;
V_136 -> V_21 . V_22 = V_22 -> V_215 ;
V_136 -> V_19 = NULL ;
V_22 -> V_217 = V_136 ;
V_22 -> V_215 = V_239 ;
}
}
V_273:
F_99 ( & V_265 ) ;
F_78 ( V_263 , V_22 ) ;
}
int F_102 ( struct V_277 * V_84 ,
struct V_65 * V_66 ,
int V_278 , T_2 V_82 )
{
int V_67 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( V_84 -> V_279 != V_84 -> V_280 ) {
F_31 ( V_76
L_139 ,
V_84 -> V_279 , V_84 -> V_280 ) ;
return - 1 ;
}
if ( V_84 -> V_279 & ( ( T_1 ) V_94 - 1 ) ) {
F_31 ( V_76
L_140 ,
V_84 -> V_279 , ( unsigned long ) V_94 ) ;
return - 1 ;
}
if ( V_84 -> V_280 & ( ( T_1 ) V_94 - 1 ) ) {
F_31 ( V_76
L_141 ,
V_84 -> V_280 , ( unsigned long ) V_94 ) ;
return - 1 ;
}
if ( V_84 -> V_281 & ( ( T_1 ) V_94 - 1 ) ) {
F_31 ( V_76
L_142 ,
V_84 -> V_281 , ( unsigned long ) V_94 ) ;
return - 1 ;
}
V_42 = F_4 ( sizeof( * V_42 ) , V_29 ) ;
if ( NULL == V_42 ) {
F_31 ( V_76 L_143 ) ;
return - 1 ;
}
if ( ! V_264 ) {
F_103 ( & V_265 ) ;
F_26 ( & V_62 ) ;
V_264 = 1 ;
}
F_98 ( & V_265 ) ;
V_42 -> V_84 = V_84 ;
V_42 -> V_82 = V_82 ;
V_42 -> V_168 = V_278 ;
V_42 -> V_79 = 0 ;
V_42 -> V_86 = V_84 -> V_279 ;
V_42 -> V_111 = V_84 -> V_281 ;
F_2 ( & V_42 -> V_113 ) ;
F_14 ( & V_42 -> V_92 ) ;
F_22 ( & V_42 -> V_93 ) ;
V_42 -> V_114 = 0 ;
V_42 -> V_78 = NULL ;
F_32 (device, dev_head, dev_list) {
struct V_38 * V_39 ;
char * V_282 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_39 = F_12 () ;
if ( NULL == V_39 ) {
F_31 ( V_76
L_143 ) ;
F_99 ( & V_265 ) ;
return - 1 ;
}
V_39 -> V_41 = V_73 -> V_41 ;
V_39 -> V_42 = V_42 ;
F_104 ( V_39 -> V_41 , V_39 -> V_43 ) ;
V_39 -> V_43 [ V_283 - 1 ] = '\0' ;
for ( V_282 = V_39 -> V_43 ; * V_282 != '\0' ; V_282 ++ ) ;
while ( V_282 > V_39 -> V_43 && * V_282 != '/' )
V_282 -- ;
if ( * V_282 == '/' )
V_282 ++ ;
F_105 ( V_39 -> V_43 , V_282 , sizeof( V_39 -> V_43 ) ) ;
F_27 ( V_39 ,
& V_62 ) ;
}
V_67 = F_30 ( V_42 , V_66 ) ;
if ( 0 != V_67 ) {
F_99 ( & V_265 ) ;
F_106 ( V_84 , V_66 ) ;
return V_67 ;
}
if ( V_42 -> V_82 & V_284 )
F_83 ( V_42 ) ;
if ( V_42 -> V_82 & V_285 )
F_91 ( V_42 ) ;
F_99 ( & V_265 ) ;
return 0 ;
}
void F_106 ( struct V_277 * V_84 ,
struct V_65 * V_66 )
{
struct V_54 * V_222 ;
struct V_54 * V_286 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( ! V_264 )
return;
F_98 ( & V_265 ) ;
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
L_144
L_145 ) ;
F_99 ( & V_265 ) ;
return;
}
F_92 (elem_all, tmp_all, &state->all_blocks_list) {
struct V_1 * const V_223 =
F_21 ( V_222 , struct V_1 ,
V_24 ) ;
struct V_54 * V_224 ;
struct V_54 * V_236 ;
F_92 (elem_ref_to, tmp_ref_to,
&b_all->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_224 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_147 )
F_93 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 )
F_10 ( V_31 ) ;
}
if ( V_223 -> V_15 || V_223 -> V_17 )
F_5 ( V_223 ) ;
else
F_31 ( V_76 L_146
L_147
L_148 ,
F_68 ( V_42 , V_223 ) ,
( unsigned long long ) V_223 -> V_7 ,
V_223 -> V_5 -> V_43 ,
( unsigned long long ) V_223 -> V_6 ,
V_223 -> V_18 ) ;
}
F_99 ( & V_265 ) ;
F_7 ( V_42 ) ;
}
