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
F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_42 -> V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
V_67 = F_40 ( V_42 , V_81 ,
V_42 -> V_87 ,
& V_91 ,
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
V_89 = F_19 (
V_91 . V_92 -> V_41 ,
V_91 . V_6 ,
& V_42 -> V_93 ) ;
F_6 ( NULL == V_89 ) ;
V_31 = F_25 (
V_91 . V_92 -> V_41 ,
V_91 . V_6 ,
V_42 -> V_78 -> V_5 ->
V_41 ,
V_42 -> V_78 -> V_6 ,
& V_42 -> V_94 ) ;
F_6 ( NULL == V_31 ) ;
V_67 = F_41 ( V_42 , & V_91 ) ;
if ( V_67 < ( int ) V_95 ) {
F_31 ( V_76
L_10 ,
( unsigned long long )
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
strncmp ( ( char * ) ( & ( V_99 -> V_107 ) ) , V_108 ,
sizeof( V_99 -> V_107 ) ) ||
memcmp ( V_73 -> V_109 , V_99 -> V_110 . V_109 , V_111 ) ||
F_47 ( V_99 ) != V_42 -> V_87 ||
F_48 ( V_99 ) != V_42 -> V_87 ||
F_49 ( V_99 ) != V_42 -> V_112 ) {
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
if ( V_42 -> V_82 & V_113 )
F_52 ( V_76 L_11
L_12 ,
V_103 ,
F_53 ( V_73 -> V_43 ) ,
( unsigned long long ) V_6 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
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
V_42 -> V_78 = V_102 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
T_1 V_81 ;
int V_80 ;
int V_18 ;
const char * V_116 = NULL ;
struct V_117 V_118 ;
V_118 . type = V_119 ;
V_118 . V_12 = 0 ;
switch ( V_75 ) {
case 0 :
V_118 . V_11 =
F_54 ( V_120 ) ;
V_116 = L_13 ;
V_81 = F_36 ( V_99 ) ;
break;
case 1 :
V_118 . V_11 =
F_54 ( V_121 ) ;
V_116 = L_14 ;
V_81 = F_37 ( V_99 ) ;
break;
case 2 :
V_118 . V_11 =
F_54 ( V_122 ) ;
V_116 = L_15 ;
V_81 = F_38 ( V_99 ) ;
if ( 0 == V_81 )
continue;
break;
}
V_80 =
F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_42 -> V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
if ( F_40 ( V_42 , V_81 ,
V_42 -> V_87 ,
& V_91 ,
V_18 ) ) {
F_31 ( V_76 L_16
L_17 ,
( unsigned long long ) V_81 ,
V_18 ) ;
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
if ( V_42 -> V_82 & V_123 )
F_57 ( V_42 , V_102 , 0 ) ;
F_50 ( V_101 ) ;
return 0 ;
}
static struct V_124 * F_58 ( void )
{
struct V_124 * V_125 ;
V_125 = F_4 ( sizeof( * V_125 ) , V_29 ) ;
if ( NULL == V_125 )
F_31 ( V_76 L_18 ) ;
else
V_125 -> V_107 = V_126 ;
return V_125 ;
}
static void F_59 ( struct V_124 * V_125 )
{
F_6 ( ! ( NULL == V_125 ||
V_126 == V_125 -> V_107 ) ) ;
F_7 ( V_125 ) ;
}
static int F_43 (
struct V_64 * V_42 ,
struct V_1 * const V_127 ,
struct V_90 * const V_128 ,
int V_129 , int V_130 )
{
struct V_124 V_131 = { 0 } ;
struct V_124 * V_125 ;
struct V_124 * V_132 ;
struct V_133 * const V_134 =
(struct V_133 * ) V_128 -> V_135 [ 0 ] ;
F_6 ( ! V_134 ) ;
V_125 = & V_131 ;
V_125 -> error = 0 ;
V_125 -> V_48 = - 1 ;
V_125 -> V_136 = V_129 ;
V_125 -> V_137 = V_127 ;
V_125 -> V_138 = V_128 ;
V_125 -> V_89 = NULL ;
V_125 -> V_139 = V_134 ;
V_125 -> V_140 = NULL ;
V_141:
V_125 -> V_137 -> V_8 = F_60 ( V_125 -> V_139 -> V_8 ) ;
if ( 0 == V_125 -> V_139 -> V_142 ) {
struct V_143 * const V_144 =
(struct V_143 * ) V_125 -> V_139 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_145 = F_61 ( V_144 -> V_146 . V_147 ) ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_19
L_20 ,
( unsigned long long )
V_125 -> V_138 -> V_96 ,
V_125 -> V_145 ,
( unsigned long long )
F_60 ( V_144 -> V_146 . V_8 ) ,
( unsigned long long )
F_60 ( V_144 -> V_146 . V_149 ) ) ;
}
V_150:
if ( 0 == V_125 -> V_80 || V_125 -> V_18 > V_125 -> V_80 ) {
V_125 -> V_48 ++ ;
V_125 -> V_80 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_145 ) {
struct V_151 V_152 ;
T_2 V_153 =
( V_52 ) ( V_144 -> V_154 + V_125 -> V_48 ) -
( V_52 ) V_144 ;
struct V_117 * V_10 ;
T_3 type ;
T_2 V_155 ;
T_2 V_156 ;
if ( V_153 + sizeof( struct V_151 ) >
V_125 -> V_138 -> V_157 ) {
V_158:
F_31 ( V_76
L_21 ,
V_125 -> V_138 -> V_96 ,
V_125 -> V_138 -> V_92 -> V_43 ) ;
goto V_159;
}
F_62 ( V_125 -> V_138 ,
& V_152 ,
V_153 ,
sizeof( struct V_151 ) ) ;
V_155 = F_61 ( V_152 . V_12 ) ;
V_156 = F_61 ( V_152 . V_160 ) ;
V_10 = & V_152 . V_161 ;
type = V_10 -> type ;
if ( V_119 == type ) {
struct V_162 V_163 ;
T_2 V_164 ;
T_1 V_81 ;
V_164 = V_155 +
F_63 ( struct V_143 , V_154 ) ;
if ( V_164 + V_156 >
V_125 -> V_138 -> V_157 )
goto V_158;
F_62 (
V_125 -> V_138 , & V_163 ,
V_164 ,
V_156 ) ;
V_81 = F_60 ( V_163 . V_165 ) ;
V_125 -> error =
F_64 (
V_42 ,
V_125 -> V_137 ,
V_125 -> V_138 ,
V_81 ,
V_125 -> V_136 ,
& V_125 -> V_166 ,
& V_125 -> V_89 ,
V_130 ,
& V_125 -> V_80 ,
& V_125 -> V_18 ,
V_10 ,
F_60 ( V_163 .
V_8 ) ) ;
if ( V_125 -> error )
goto V_159;
if ( NULL != V_125 -> V_89 ) {
struct V_133 * const V_167 =
(struct V_133 * )
V_125 -> V_166 . V_135 [ 0 ] ;
V_132 =
F_58 () ;
if ( NULL == V_132 ) {
F_42 (
& V_125 ->
V_166 ) ;
goto V_159;
}
V_132 -> V_48 = - 1 ;
V_132 -> V_137 = V_125 -> V_89 ;
V_132 -> V_138 =
& V_125 -> V_166 ;
V_132 -> V_89 = NULL ;
V_132 -> V_139 = V_167 ;
V_132 -> V_136 =
V_125 -> V_136 - 1 ;
V_132 -> V_140 = V_125 ;
V_125 = V_132 ;
goto V_141;
}
} else if ( V_168 == type &&
V_42 -> V_169 ) {
V_125 -> error = F_65 (
V_42 ,
V_125 -> V_137 ,
V_125 -> V_138 ,
V_155 ,
V_130 ) ;
if ( V_125 -> error )
goto V_159;
}
goto V_150;
}
} else {
struct V_170 * const V_171 = (struct V_170 * ) V_125 -> V_139 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_145 = F_61 ( V_171 -> V_146 . V_147 ) ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76 L_22
L_23 ,
( unsigned long long )
V_125 -> V_138 -> V_96 ,
V_171 -> V_146 . V_142 , V_125 -> V_145 ,
( unsigned long long )
F_60 ( V_171 -> V_146 . V_8 ) ,
( unsigned long long )
F_60 ( V_171 -> V_146 . V_149 ) ) ;
}
V_172:
if ( 0 == V_125 -> V_80 || V_125 -> V_18 > V_125 -> V_80 ) {
V_125 -> V_48 ++ ;
V_125 -> V_80 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_145 ) {
struct V_173 V_174 ;
T_2 V_175 ;
T_1 V_81 ;
V_175 = ( V_52 ) ( V_171 -> V_176 + V_125 -> V_48 ) -
( V_52 ) V_171 ;
if ( V_175 + sizeof( struct V_173 ) >
V_125 -> V_138 -> V_157 ) {
F_31 ( V_76
L_24 ,
V_125 -> V_138 -> V_96 ,
V_125 -> V_138 -> V_92 -> V_43 ) ;
goto V_159;
}
F_62 (
V_125 -> V_138 , & V_174 , V_175 ,
sizeof( struct V_173 ) ) ;
V_81 = F_60 ( V_174 . V_177 ) ;
V_125 -> error = F_64 (
V_42 ,
V_125 -> V_137 ,
V_125 -> V_138 ,
V_81 ,
V_125 -> V_136 ,
& V_125 -> V_166 ,
& V_125 -> V_89 ,
V_130 ,
& V_125 -> V_80 ,
& V_125 -> V_18 ,
& V_174 . V_161 ,
F_60 ( V_174 . V_8 ) ) ;
if ( V_125 -> error )
goto V_159;
if ( NULL != V_125 -> V_89 ) {
struct V_133 * const V_167 =
(struct V_133 * )
V_125 -> V_166 . V_135 [ 0 ] ;
V_132 = F_58 () ;
if ( NULL == V_132 )
goto V_159;
V_132 -> V_48 = - 1 ;
V_132 -> V_137 = V_125 -> V_89 ;
V_132 -> V_138 = & V_125 -> V_166 ;
V_132 -> V_89 = NULL ;
V_132 -> V_139 = V_167 ;
V_132 -> V_136 =
V_125 -> V_136 - 1 ;
V_132 -> V_140 = V_125 ;
V_125 = V_132 ;
goto V_141;
}
goto V_172;
}
}
V_159:
if ( NULL != V_125 -> V_140 ) {
struct V_124 * const V_140 = V_125 -> V_140 ;
F_42 ( V_125 -> V_138 ) ;
if ( V_125 -> error ) {
V_140 -> error = V_125 -> error ;
F_59 ( V_125 ) ;
V_125 = V_140 ;
goto V_159;
}
F_59 ( V_125 ) ;
V_125 = V_140 ;
goto V_141;
} else {
F_6 ( & V_131 != V_125 ) ;
}
return V_125 -> error ;
}
static void F_62 (
struct V_90 * V_138 ,
void * V_178 , T_2 V_12 , T_4 V_157 )
{
T_4 V_179 ;
T_4 V_180 ;
char * V_181 ;
char * V_182 = ( char * ) V_178 ;
T_4 V_183 = V_138 -> V_96 & ( ( T_1 ) V_95 - 1 ) ;
unsigned long V_48 = ( V_183 + V_12 ) >> V_184 ;
F_66 ( V_12 + V_157 > V_138 -> V_157 ) ;
V_180 = ( V_183 + V_12 ) &
( ( unsigned long ) V_95 - 1 ) ;
while ( V_157 > 0 ) {
V_179 = F_67 ( V_157 , ( ( T_4 ) V_95 - V_180 ) ) ;
F_6 ( V_48 >= ( V_138 -> V_157 + V_95 - 1 ) >>
V_184 ) ;
V_181 = V_138 -> V_135 [ V_48 ] ;
memcpy ( V_182 , V_181 + V_180 , V_179 ) ;
V_182 += V_179 ;
V_157 -= V_179 ;
V_180 = 0 ;
V_48 ++ ;
}
}
static int F_64 (
struct V_64 * V_42 ,
struct V_1 * V_137 ,
struct V_90 * V_138 ,
T_1 V_81 ,
int V_136 ,
struct V_90 * V_166 ,
struct V_1 * * V_185 ,
int V_130 ,
int * V_186 , int * V_187 ,
struct V_117 * V_10 ,
T_1 V_188 )
{
struct V_1 * V_89 = NULL ;
int V_67 ;
struct V_30 * V_31 ;
int V_189 ;
int V_190 ;
* V_185 = NULL ;
if ( 0 == * V_186 ) {
* V_186 =
F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_42 -> V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , * V_186 ) ;
* V_187 = 1 ;
}
if ( * V_187 > * V_186 )
return 0 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_25 ,
* V_187 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_42 -> V_87 ,
V_166 , * V_187 ) ;
if ( V_67 ) {
F_31 ( V_76
L_26 ,
( unsigned long long ) V_81 , * V_187 ) ;
F_42 ( V_166 ) ;
* V_185 = NULL ;
return - 1 ;
}
V_89 = F_55 ( V_42 ,
V_166 , L_27 ,
1 , V_130 ,
! V_130 ,
* V_187 ,
& V_190 ) ;
if ( NULL == V_89 ) {
F_42 ( V_166 ) ;
* V_185 = NULL ;
return - 1 ;
}
if ( V_190 ) {
V_31 = NULL ;
V_89 -> V_8 = V_9 ;
} else {
if ( V_89 -> V_7 != V_81 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) ) {
F_31 ( V_76
L_28
L_29
L_30 ,
( unsigned long long ) V_81 ,
V_166 -> V_92 -> V_43 ,
( unsigned long long ) V_166 -> V_6 ,
* V_187 ,
F_68 ( V_42 , V_89 ) ,
( unsigned long long ) V_89 -> V_7 ) ;
} else if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_28
L_31 ,
( unsigned long long ) V_81 ,
V_166 -> V_92 -> V_43 ,
( unsigned long long ) V_166 -> V_6 ,
* V_187 ,
F_68 ( V_42 , V_89 ) ) ;
V_89 -> V_7 = V_81 ;
V_89 -> V_18 = * V_187 ;
V_31 = F_25 (
V_166 -> V_92 -> V_41 ,
V_166 -> V_6 ,
V_138 -> V_92 -> V_41 ,
V_138 -> V_6 ,
& V_42 -> V_94 ) ;
}
V_89 -> V_10 = * V_10 ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( V_166 ) ;
* V_185 = NULL ;
return - 1 ;
}
V_189 = 1 ;
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_137 ;
V_31 -> V_33 = 1 ;
V_31 -> V_188 = V_188 ;
if ( V_42 -> V_82 & V_148 )
F_69 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_137 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_94 ) ;
} else {
V_189 = 0 ;
if ( 0 == V_136 ) {
V_31 -> V_33 ++ ;
V_31 -> V_188 = V_188 ;
if ( V_42 -> V_82 & V_148 )
F_69 ( V_42 , V_31 ) ;
}
}
if ( V_136 > 0 && V_189 ) {
V_67 = F_41 ( V_42 , V_166 ) ;
if ( V_67 < ( int ) V_166 -> V_157 ) {
F_31 ( V_76
L_32 ,
( unsigned long long ) V_81 ) ;
F_42 ( V_166 ) ;
* V_185 = NULL ;
return - 1 ;
}
* V_185 = V_89 ;
} else {
* V_185 = NULL ;
}
( * V_187 ) ++ ;
return 0 ;
}
static int F_65 (
struct V_64 * V_42 ,
struct V_1 * V_137 ,
struct V_90 * V_138 ,
T_2 V_155 , int V_130 )
{
int V_67 ;
struct V_191 V_192 ;
T_1 V_193 ;
T_1 V_81 ;
T_1 V_194 ;
T_1 V_8 ;
struct V_30 * V_31 ;
V_193 = F_63 ( struct V_143 , V_154 ) +
V_155 ;
if ( V_193 +
F_63 ( struct V_191 , V_195 ) >
V_138 -> V_157 ) {
F_31 ( V_76
L_33 ,
V_138 -> V_96 , V_138 -> V_92 -> V_43 ) ;
return - 1 ;
}
F_62 ( V_138 , & V_192 ,
V_193 ,
F_63 ( struct V_191 , V_195 ) ) ;
if ( V_196 != V_192 . type ||
( ( T_1 ) 0 ) == F_60 ( V_192 . V_197 ) ) {
if ( V_42 -> V_82 & V_198 )
F_31 ( V_76 L_34 ,
V_192 . type ,
( unsigned long long )
F_60 ( V_192 . V_197 ) ) ;
return 0 ;
}
if ( V_193 + sizeof( struct V_191 ) >
V_138 -> V_157 ) {
F_31 ( V_76
L_33 ,
V_138 -> V_96 , V_138 -> V_92 -> V_43 ) ;
return - 1 ;
}
F_62 ( V_138 , & V_192 ,
V_193 ,
sizeof( struct V_191 ) ) ;
V_81 = F_60 ( V_192 . V_197 ) +
F_60 ( V_192 . V_12 ) ;
V_8 = F_60 ( V_192 . V_8 ) ;
V_194 = F_60 ( V_192 . V_194 ) ;
V_8 = F_60 ( V_192 . V_8 ) ;
if ( V_42 -> V_82 & V_198 )
F_31 ( V_76 L_35
L_36 ,
V_192 . type ,
( unsigned long long )
F_60 ( V_192 . V_197 ) ,
( unsigned long long ) F_60 ( V_192 . V_12 ) ,
( unsigned long long ) V_194 ) ;
while ( V_194 > 0 ) {
T_2 V_199 ;
int V_80 ;
int V_18 ;
if ( V_194 > V_42 -> V_112 )
V_199 = V_42 -> V_112 ;
else
V_199 = V_194 ;
V_80 =
F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_42 -> V_112 ) ;
if ( V_42 -> V_82 & V_88 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_90 V_166 ;
struct V_1 * V_89 ;
int V_190 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76 L_37
L_38 , V_18 ) ;
if ( V_42 -> V_82 & V_198 )
F_31 ( V_76
L_39 ,
( unsigned long long ) V_81 ,
V_199 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_199 , & V_166 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_40
L_41 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_89 = F_55 (
V_42 ,
& V_166 ,
L_27 ,
0 ,
V_130 ,
! V_130 ,
V_18 ,
& V_190 ) ;
if ( NULL == V_89 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_166 ) ;
return - 1 ;
}
if ( ! V_190 ) {
if ( V_89 -> V_7 != V_81 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) ) {
F_31 ( V_76
L_42
L_43
L_44
L_45
L_46 ,
( unsigned long long ) V_81 ,
V_166 . V_92 -> V_43 ,
( unsigned long long )
V_166 . V_6 ,
V_18 ,
( unsigned long long )
V_89 -> V_7 ) ;
}
V_89 -> V_7 = V_81 ;
V_89 -> V_18 = V_18 ;
}
V_31 = F_56 ( V_42 ,
& V_166 ,
V_89 , V_137 ,
V_8 ) ;
F_42 ( & V_166 ) ;
if ( NULL == V_31 )
return - 1 ;
}
V_81 += V_199 ;
V_194 -= V_199 ;
}
return 0 ;
}
static int F_40 ( struct V_64 * V_42 , T_1 V_165 , T_2 V_157 ,
struct V_90 * V_200 ,
int V_18 )
{
int V_67 ;
T_1 V_201 ;
struct V_202 * V_203 = NULL ;
struct V_72 * V_73 ;
V_201 = V_157 ;
V_67 = F_70 ( & V_42 -> V_84 -> V_85 -> V_86 , V_204 ,
V_165 , & V_201 , & V_203 , V_18 ) ;
V_73 = V_203 -> V_205 [ 0 ] . V_92 ;
V_200 -> V_92 = F_33 ( V_73 -> V_41 ) ;
V_200 -> V_6 = V_203 -> V_205 [ 0 ] . V_206 ;
V_200 -> V_96 = V_165 ;
V_200 -> V_157 = V_157 ;
V_200 -> V_135 = NULL ;
V_200 -> V_207 = NULL ;
V_200 -> V_208 = NULL ;
if ( 0 == V_67 )
F_7 ( V_203 ) ;
if ( NULL == V_200 -> V_92 ) {
V_67 = - V_209 ;
F_31 ( V_76 L_47 ) ;
}
return V_67 ;
}
static int F_71 ( struct V_64 * V_42 , T_1 V_165 ,
T_2 V_157 , struct V_53 * V_41 ,
struct V_90 * V_200 )
{
V_200 -> V_92 = F_33 ( V_41 ) ;
V_200 -> V_6 = V_165 ;
V_200 -> V_96 = V_165 ;
V_200 -> V_157 = V_157 ;
V_200 -> V_135 = NULL ;
V_200 -> V_207 = NULL ;
V_200 -> V_208 = NULL ;
if ( NULL != V_200 -> V_92 ) {
return 0 ;
} else {
F_31 ( V_76 L_48 ) ;
return - V_209 ;
}
}
static void F_42 ( struct V_90 * V_138 )
{
if ( V_138 -> V_208 ) {
unsigned int V_210 ;
F_6 ( ! V_138 -> V_135 ) ;
F_6 ( ! V_138 -> V_207 ) ;
V_210 = ( V_138 -> V_157 + ( T_1 ) V_95 - 1 ) >>
V_184 ;
while ( V_210 > 0 ) {
V_210 -- ;
if ( V_138 -> V_135 [ V_210 ] ) {
F_72 ( V_138 -> V_207 [ V_210 ] ) ;
V_138 -> V_135 [ V_210 ] = NULL ;
}
if ( V_138 -> V_207 [ V_210 ] ) {
F_73 ( V_138 -> V_207 [ V_210 ] ) ;
V_138 -> V_207 [ V_210 ] = NULL ;
}
}
F_7 ( V_138 -> V_208 ) ;
V_138 -> V_208 = NULL ;
V_138 -> V_207 = NULL ;
V_138 -> V_135 = NULL ;
}
}
static int F_41 ( struct V_64 * V_42 ,
struct V_90 * V_138 )
{
unsigned int V_210 ;
unsigned int V_48 ;
T_1 V_6 ;
int V_67 ;
F_6 ( V_138 -> V_135 ) ;
F_6 ( V_138 -> V_207 ) ;
F_6 ( V_138 -> V_208 ) ;
if ( V_138 -> V_6 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_49 ,
( unsigned long long ) V_138 -> V_6 ) ;
return - 1 ;
}
V_210 = ( V_138 -> V_157 + ( T_1 ) V_95 - 1 ) >>
V_184 ;
V_138 -> V_208 = F_4 ( ( sizeof( * V_138 -> V_135 ) +
sizeof( * V_138 -> V_207 ) ) *
V_210 , V_29 ) ;
if ( ! V_138 -> V_208 )
return - 1 ;
V_138 -> V_135 = V_138 -> V_208 ;
V_138 -> V_207 = (struct V_211 * * ) ( V_138 -> V_135 + V_210 ) ;
for ( V_48 = 0 ; V_48 < V_210 ; V_48 ++ ) {
V_138 -> V_207 [ V_48 ] = F_74 ( V_29 ) ;
if ( ! V_138 -> V_207 [ V_48 ] )
return - 1 ;
}
V_6 = V_138 -> V_6 ;
for ( V_48 = 0 ; V_48 < V_210 ; ) {
struct V_22 * V_22 ;
unsigned int V_212 ;
F_75 ( V_213 ) ;
V_22 = F_76 ( V_29 , V_210 - V_48 ) ;
if ( ! V_22 ) {
F_31 ( V_76
L_50 ,
V_210 - V_48 ) ;
return - 1 ;
}
V_22 -> V_214 = V_138 -> V_92 -> V_41 ;
V_22 -> V_215 = V_6 >> 9 ;
V_22 -> V_216 = V_217 ;
V_22 -> V_218 = & V_213 ;
for ( V_212 = V_48 ; V_212 < V_210 ; V_212 ++ ) {
V_67 = F_77 ( V_22 , V_138 -> V_207 [ V_212 ] ,
V_95 , 0 ) ;
if ( V_95 != V_67 )
break;
}
if ( V_212 == V_48 ) {
F_31 ( V_76
L_51 ) ;
return - 1 ;
}
F_78 ( V_204 , V_22 ) ;
F_79 ( & V_213 ) ;
if ( ! F_80 ( V_219 , & V_22 -> V_220 ) ) {
F_31 ( V_76
L_52 ,
V_138 -> V_96 , V_138 -> V_92 -> V_43 ) ;
F_81 ( V_22 ) ;
return - 1 ;
}
F_81 ( V_22 ) ;
V_6 += ( V_212 - V_48 ) * V_95 ;
V_48 = V_212 ;
}
for ( V_48 = 0 ; V_48 < V_210 ; V_48 ++ ) {
V_138 -> V_135 [ V_48 ] = F_82 ( V_138 -> V_207 [ V_48 ] ) ;
if ( ! V_138 -> V_135 [ V_48 ] ) {
F_31 ( V_76 L_53 ,
V_138 -> V_92 -> V_43 ) ;
return - 1 ;
}
}
return V_138 -> V_157 ;
}
static void V_217 ( struct V_22 * V_22 , int V_221 )
{
V_213 ( (struct V_222 * ) V_22 -> V_218 ) ;
}
static void F_83 ( struct V_64 * V_42 )
{
struct V_54 * V_223 ;
F_6 ( NULL == V_42 ) ;
F_31 ( V_76 L_54 ) ;
F_20 (elem_all, &state->all_blocks_list) {
const struct V_1 * const V_224 =
F_21 ( V_223 , struct V_1 ,
V_24 ) ;
struct V_54 * V_225 ;
struct V_54 * V_226 ;
F_31 ( V_76 L_55 ,
F_68 ( V_42 , V_224 ) ,
( unsigned long long ) V_224 -> V_7 ,
V_224 -> V_5 -> V_43 ,
( unsigned long long ) V_224 -> V_6 ,
V_224 -> V_18 ) ;
F_20 (elem_ref_to, &b_all->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_225 ,
struct V_30 ,
V_34 ) ;
F_31 ( V_76 L_56
L_57
L_58 ,
F_68 ( V_42 , V_224 ) ,
( unsigned long long ) V_224 -> V_7 ,
V_224 -> V_5 -> V_43 ,
( unsigned long long ) V_224 -> V_6 ,
V_224 -> V_18 ,
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
F_21 ( V_226 ,
struct V_30 ,
V_35 ) ;
F_31 ( V_76 L_56
L_59
L_58 ,
F_68 ( V_42 , V_224 ) ,
( unsigned long long ) V_224 -> V_7 ,
V_224 -> V_5 -> V_43 ,
( unsigned long long ) V_224 -> V_6 ,
V_224 -> V_18 ,
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
char * * V_135 , unsigned int V_210 )
{
struct V_133 * V_47 ;
T_3 V_227 [ V_228 ] ;
T_2 V_229 = ~ ( T_2 ) 0 ;
unsigned int V_48 ;
if ( V_210 * V_95 < V_42 -> V_87 )
return 1 ;
V_210 = V_42 -> V_87 >> V_184 ;
V_47 = (struct V_133 * ) V_135 [ 0 ] ;
if ( memcmp ( V_47 -> V_230 , V_42 -> V_84 -> V_85 -> V_230 , V_111 ) )
return 1 ;
for ( V_48 = 0 ; V_48 < V_210 ; V_48 ++ ) {
T_3 * V_231 = V_48 ? V_135 [ V_48 ] : ( V_135 [ V_48 ] + V_228 ) ;
T_4 V_232 = V_48 ? V_95 :
( V_95 - V_228 ) ;
V_229 = F_85 ( V_229 , V_231 , V_232 ) ;
}
F_86 ( V_229 , V_227 ) ;
if ( memcmp ( V_227 , V_47 -> V_227 , V_42 -> V_79 ) )
return 1 ;
return 0 ;
}
static void F_87 ( struct V_38 * V_5 ,
T_1 V_6 , char * * V_233 ,
unsigned int V_210 ,
struct V_22 * V_22 , int * V_234 ,
struct V_100 * V_101 ,
int V_27 )
{
int V_13 ;
struct V_1 * V_137 ;
struct V_90 V_138 ;
int V_67 ;
struct V_64 * V_42 = V_5 -> V_42 ;
struct V_53 * V_41 = V_5 -> V_41 ;
unsigned int V_235 ;
if ( NULL != V_234 )
* V_234 = 0 ;
V_236:
if ( V_210 == 0 )
return;
V_235 = 0 ;
V_13 = ( 0 == F_84 ( V_42 , V_233 ,
V_210 ) ) ;
V_137 = F_19 ( V_41 , V_6 ,
& V_42 -> V_93 ) ;
if ( NULL != V_137 ) {
T_1 V_165 = 0 ;
struct V_54 * V_225 ;
struct V_54 * V_237 ;
if ( V_137 -> V_14 ) {
V_165 = F_60 ( ( (struct V_68 * )
V_233 [ 0 ] ) -> V_165 ) ;
if ( V_210 * V_95 <
V_104 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_13 = 1 ;
F_6 ( V_104 & ( V_95 - 1 ) ) ;
V_235 = V_104 ;
if ( V_42 -> V_82 &
V_238 ) {
F_31 ( V_76
L_62 ) ;
F_57 ( V_42 , V_137 , 0 ) ;
}
}
if ( V_13 ) {
if ( ! V_137 -> V_14 ) {
if ( V_210 * V_95 <
V_42 -> V_87 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_235 = V_42 -> V_87 ;
V_165 = F_60 ( ( (struct V_133 * )
V_233 [ 0 ] ) -> V_165 ) ;
F_88 ( V_42 , V_165 ,
V_5 ,
V_6 ) ;
}
if ( V_137 -> V_7 != V_165 ) {
F_31 ( V_76
L_63
L_29
L_45
L_46 ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_137 -> V_18 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long )
V_137 -> V_7 ) ;
V_137 -> V_7 = V_165 ;
} else if ( V_42 -> V_82 &
V_148 )
F_31 ( V_76
L_63
L_31 ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_137 -> V_18 ,
F_68 ( V_42 , V_137 ) ) ;
} else {
if ( V_210 * V_95 <
V_42 -> V_112 ) {
F_31 ( V_76
L_61 ) ;
return;
}
V_235 = V_42 -> V_112 ;
V_165 = V_137 -> V_7 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_63
L_31 ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_137 -> V_18 ,
F_68 ( V_42 , V_137 ) ) ;
}
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_64 ,
F_89 ( & V_137 -> V_25 ) ? ' ' : '!' ,
F_89 ( & V_137 -> V_26 ) ? ' ' : '!' ) ;
if ( F_90 ( V_42 , V_137 , 0 ) ) {
F_31 ( V_76 L_65
L_66
L_67
L_68
L_69
L_70 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_137 -> V_18 ,
( unsigned long long ) V_137 -> V_8 ,
( unsigned long long )
F_60 ( V_137 -> V_10 . V_11 ) ,
V_137 -> V_10 . type ,
( unsigned long long )
F_60 ( V_137 -> V_10 . V_12 ) ,
( unsigned long long )
F_60 ( ( (struct V_133 * )
V_233 [ 0 ] ) -> V_8 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
F_91 ( V_42 ) ;
}
if ( ! V_137 -> V_15 && ! V_137 -> V_17 ) {
F_31 ( V_76 L_65
L_71
L_72 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_137 -> V_18 ,
( unsigned long long ) V_137 -> V_8 ,
( unsigned long long )
F_60 ( ( (struct V_133 * )
V_233 [ 0 ] ) -> V_8 ) ) ;
F_91 ( V_42 ) ;
goto V_239;
}
F_92 (elem_ref_to, tmp_ref_to,
&block->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_225 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_148 )
F_93 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 ) {
F_18 ( & V_31 -> V_34 ) ;
F_18 ( & V_31 -> V_35 ) ;
F_24 ( V_31 ) ;
F_10 ( V_31 ) ;
}
}
if ( V_137 -> V_14 )
V_67 = F_71 ( V_42 , V_165 ,
V_235 ,
V_41 , & V_138 ) ;
else
V_67 = F_40 ( V_42 , V_165 , V_235 ,
& V_138 , 0 ) ;
if ( V_67 ) {
F_31 ( V_76
L_73
L_74 , ( unsigned long long ) V_165 ) ;
goto V_239;
}
V_138 . V_135 = V_233 ;
V_138 . V_92 = V_5 ;
V_138 . V_6 = V_6 ;
if ( V_13 || V_42 -> V_169 ) {
V_137 -> V_17 = 0 ;
V_137 -> V_16 = 0 ;
if ( NULL != V_22 ) {
V_137 -> V_15 = 0 ;
F_6 ( NULL == V_234 ) ;
if ( ! * V_234 ) {
V_137 -> V_20 =
V_22 -> V_218 ;
V_137 -> V_21 . V_22 =
V_22 -> V_216 ;
V_137 -> V_19 = NULL ;
V_22 -> V_218 = V_137 ;
V_22 -> V_216 = V_240 ;
* V_234 = 1 ;
} else {
struct V_1 * V_241 =
(struct V_1 * )
V_22 -> V_218 ;
F_6 ( NULL == V_241 ) ;
V_137 -> V_20 =
V_241 -> V_20 ;
V_137 -> V_21 . V_22 =
V_241 -> V_21 .
V_22 ;
V_137 -> V_19 = V_241 ;
V_22 -> V_218 = V_137 ;
}
} else if ( NULL != V_101 ) {
V_137 -> V_15 = 0 ;
V_137 -> V_20 = V_101 -> V_242 ;
V_137 -> V_21 . V_101 = V_101 -> V_243 ;
V_137 -> V_19 = NULL ;
V_101 -> V_242 = V_137 ;
V_101 -> V_243 = V_244 ;
} else {
V_137 -> V_15 = 1 ;
V_137 -> V_20 = NULL ;
V_137 -> V_21 . V_22 = NULL ;
V_137 -> V_19 = NULL ;
}
}
V_137 -> V_28 = V_5 -> V_44 + 1 ;
V_137 -> V_27 = V_27 ;
if ( V_13 ) {
V_137 -> V_7 = V_165 ;
V_137 -> V_13 = 1 ;
if ( V_137 -> V_14 ) {
F_6 ( V_95 !=
V_104 ) ;
V_67 = F_94 (
V_42 ,
V_137 ,
(struct V_68 * )
V_233 [ 0 ] ) ;
if ( V_42 -> V_82 &
V_245 ) {
F_31 ( V_76
L_75 ) ;
F_57 ( V_42 , V_137 , 0 ) ;
}
} else {
V_137 -> V_18 = 0 ;
V_67 = F_43 (
V_42 ,
V_137 ,
& V_138 ,
0 , 0 ) ;
}
if ( V_67 )
F_31 ( V_76
L_76
L_77 ,
( unsigned long long ) V_6 ) ;
} else {
V_137 -> V_13 = 0 ;
V_137 -> V_18 = 0 ;
V_137 -> V_8 = V_9 ;
if ( ! V_42 -> V_169
&& F_89 ( & V_137 -> V_26 ) ) {
F_17 ( V_137 ) ;
F_18 ( & V_137 -> V_24 ) ;
F_5 ( V_137 ) ;
}
}
F_42 ( & V_138 ) ;
} else {
T_1 V_165 ;
if ( ! V_13 ) {
V_235 = V_42 -> V_112 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76 L_78
L_79 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
if ( ! V_42 -> V_169 ) {
goto V_239;
}
V_165 = 0 ;
V_138 . V_96 = V_165 ;
V_138 . V_157 = V_235 ;
V_138 . V_208 = NULL ;
V_138 . V_207 = NULL ;
} else {
V_235 = V_42 -> V_87 ;
V_165 = F_60 ( ( (struct V_133 * )
V_233 [ 0 ] ) -> V_165 ) ;
F_88 ( V_42 , V_165 , V_5 ,
V_6 ) ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_80
L_81 ,
( unsigned long long ) V_165 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
V_67 = F_40 ( V_42 , V_165 , V_235 ,
& V_138 , 0 ) ;
if ( V_67 ) {
F_31 ( V_76
L_73
L_74 ,
( unsigned long long ) V_6 ) ;
goto V_239;
}
}
V_138 . V_135 = V_233 ;
V_138 . V_92 = V_5 ;
V_138 . V_6 = V_6 ;
V_137 = F_3 () ;
if ( NULL == V_137 ) {
F_31 ( V_76 L_1 ) ;
F_42 ( & V_138 ) ;
goto V_239;
}
V_137 -> V_5 = V_5 ;
V_137 -> V_6 = V_6 ;
V_137 -> V_7 = V_165 ;
V_137 -> V_13 = V_13 ;
V_137 -> V_17 = 0 ;
V_137 -> V_16 = 0 ;
V_137 -> V_18 = 0 ;
V_137 -> V_28 = V_5 -> V_44 + 1 ;
V_137 -> V_27 = V_27 ;
if ( NULL != V_22 ) {
V_137 -> V_15 = 0 ;
F_6 ( NULL == V_234 ) ;
if ( ! * V_234 ) {
V_137 -> V_20 = V_22 -> V_218 ;
V_137 -> V_21 . V_22 = V_22 -> V_216 ;
V_137 -> V_19 = NULL ;
V_22 -> V_218 = V_137 ;
V_22 -> V_216 = V_240 ;
* V_234 = 1 ;
} else {
struct V_1 * V_241 =
(struct V_1 * )
V_22 -> V_218 ;
F_6 ( NULL == V_241 ) ;
V_137 -> V_20 =
V_241 -> V_20 ;
V_137 -> V_21 . V_22 =
V_241 -> V_21 . V_22 ;
V_137 -> V_19 = V_241 ;
V_22 -> V_218 = V_137 ;
}
} else if ( NULL != V_101 ) {
V_137 -> V_15 = 0 ;
V_137 -> V_20 = V_101 -> V_242 ;
V_137 -> V_21 . V_101 = V_101 -> V_243 ;
V_137 -> V_19 = NULL ;
V_101 -> V_242 = V_137 ;
V_101 -> V_243 = V_244 ;
} else {
V_137 -> V_15 = 1 ;
V_137 -> V_20 = NULL ;
V_137 -> V_21 . V_22 = NULL ;
V_137 -> V_19 = NULL ;
}
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_82 ,
V_13 ? 'M' : 'D' ,
( unsigned long long ) V_137 -> V_7 ,
V_137 -> V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ) ;
F_16 ( & V_137 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_137 , & V_42 -> V_93 ) ;
if ( V_13 ) {
V_67 = F_43 ( V_42 , V_137 ,
& V_138 , 0 , 0 ) ;
if ( V_67 )
F_31 ( V_76
L_83
L_74 ,
( unsigned long long ) V_6 ) ;
}
F_42 ( & V_138 ) ;
}
V_239:
F_6 ( ! V_235 ) ;
V_6 += V_235 ;
V_233 += V_235 >> V_184 ;
V_210 -= V_235 >> V_184 ;
goto V_236;
}
static void V_240 ( struct V_22 * V_246 , int V_247 )
{
struct V_1 * V_137 = (struct V_1 * ) V_246 -> V_218 ;
int V_16 ;
V_16 = 0 ;
if ( V_247 )
V_16 = 1 ;
F_6 ( NULL == V_137 ) ;
V_246 -> V_218 = V_137 -> V_20 ;
V_246 -> V_216 = V_137 -> V_21 . V_22 ;
do {
struct V_1 * V_89 ;
struct V_38 * const V_5 = V_137 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 &
V_248 ) )
F_31 ( V_76
L_84 ,
V_247 ,
F_68 ( V_5 -> V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ) ;
V_89 = V_137 -> V_19 ;
V_137 -> V_16 = V_16 ;
if ( V_137 -> V_27 & V_249 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_248 ) )
F_31 ( V_76
L_85 ,
V_5 -> V_43 ,
( unsigned long long )
V_5 -> V_44 ) ;
}
if ( V_137 -> V_27 & V_250 )
V_137 -> V_28 = 0 ;
V_137 -> V_15 = 1 ;
V_137 = V_89 ;
} while ( NULL != V_137 );
V_246 -> V_216 ( V_246 , V_247 ) ;
}
static void V_244 ( struct V_100 * V_101 , int V_251 )
{
struct V_1 * V_137 = (struct V_1 * ) V_101 -> V_242 ;
int V_16 = ! V_251 ;
struct V_38 * V_5 ;
F_6 ( NULL == V_137 ) ;
V_5 = V_137 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 & V_248 ) )
F_31 ( V_76
L_86 ,
V_16 ,
F_68 ( V_5 -> V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_137 -> V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ) ;
V_137 -> V_16 = V_16 ;
if ( V_137 -> V_27 & V_249 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_248 ) )
F_31 ( V_76
L_87 ,
V_5 -> V_43 ,
( unsigned long long ) V_5 -> V_44 ) ;
}
if ( V_137 -> V_27 & V_250 )
V_137 -> V_28 = 0 ;
V_101 -> V_242 = V_137 -> V_20 ;
V_101 -> V_243 = V_137 -> V_21 . V_101 ;
V_137 -> V_15 = 1 ;
V_101 -> V_243 ( V_101 , V_251 ) ;
}
static int F_94 (
struct V_64 * V_42 ,
struct V_1 * const V_252 ,
struct V_68 * const V_253 )
{
int V_75 ;
V_252 -> V_8 = F_51 ( V_253 ) ;
if ( ! ( V_252 -> V_8 > V_42 -> V_115 ||
0 == V_42 -> V_115 ) ) {
if ( V_42 -> V_82 & V_113 )
F_31 ( V_76
L_88
L_89 ,
( unsigned long long ) V_252 -> V_7 ,
V_252 -> V_5 -> V_43 ,
( unsigned long long ) V_252 -> V_6 ,
V_252 -> V_18 ,
( unsigned long long )
F_51 ( V_253 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
} else {
if ( V_42 -> V_82 & V_113 )
F_31 ( V_76
L_90
L_91 ,
( unsigned long long ) V_252 -> V_7 ,
V_252 -> V_5 -> V_43 ,
( unsigned long long ) V_252 -> V_6 ,
V_252 -> V_18 ,
( unsigned long long )
F_51 ( V_253 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
V_42 -> V_115 =
F_51 ( V_253 ) ;
V_42 -> V_78 = V_252 ;
}
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_67 ;
T_1 V_81 ;
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
int V_80 ;
int V_18 ;
const char * V_116 = NULL ;
struct V_117 V_118 ;
V_118 . type = V_119 ;
V_118 . V_12 = 0 ;
switch ( V_75 ) {
case 0 :
V_118 . V_11 =
F_54 ( V_120 ) ;
V_116 = L_92 ;
V_81 = F_36 ( V_253 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_3 ,
( unsigned long long ) V_81 ) ;
break;
case 1 :
V_118 . V_11 =
F_54 ( V_121 ) ;
V_116 = L_93 ;
V_81 = F_37 ( V_253 ) ;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_4 ,
( unsigned long long ) V_81 ) ;
break;
case 2 :
V_118 . V_11 =
F_54 ( V_122 ) ;
V_116 = L_94 ;
V_81 = F_38 ( V_253 ) ;
if ( 0 == V_81 )
continue;
if ( V_42 -> V_82 &
V_83 )
F_31 ( V_76 L_5 ,
( unsigned long long ) V_81 ) ;
break;
}
V_80 =
F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_104 ) ;
if ( V_42 -> V_82 & V_88 )
F_31 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
int V_254 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_95
L_38 , V_18 ) ;
V_67 = F_40 ( V_42 , V_81 ,
V_104 ,
& V_91 ,
V_18 ) ;
if ( V_67 ) {
F_31 ( V_76
L_40
L_41 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_89 = F_55 (
V_42 ,
& V_91 ,
V_116 ,
1 , 0 , 1 ,
V_18 ,
& V_254 ) ;
if ( NULL == V_89 ) {
F_31 ( V_76
L_1 ) ;
F_42 ( & V_91 ) ;
return - 1 ;
}
V_89 -> V_10 = V_118 ;
if ( V_254 )
V_89 -> V_8 =
V_9 ;
V_31 = F_56 (
V_42 ,
& V_91 ,
V_89 ,
V_252 ,
V_9 ) ;
F_42 ( & V_91 ) ;
if ( NULL == V_31 )
return - 1 ;
}
}
if ( - 1 == F_95 ( V_42 , V_252 , 0 ) ) {
F_66 ( 1 ) ;
F_91 ( V_42 ) ;
}
return 0 ;
}
static int F_95 ( struct V_64 * V_42 ,
struct V_1 * const V_137 ,
int V_255 )
{
struct V_54 * V_225 ;
int V_67 = 0 ;
if ( V_255 >= 3 + V_97 ) {
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_96 ) ;
return V_67 ;
}
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_225 , struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_97
L_98 ,
V_255 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_137 -> V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ,
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
} else if ( V_31 -> V_188 !=
V_31 -> V_36 -> V_8 &&
V_9 !=
V_31 -> V_188 &&
V_9 !=
V_31 -> V_36 -> V_8 ) {
F_31 ( V_76 L_99
L_100
L_102
L_103 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_31 -> V_36 -> V_8 ,
( unsigned long long ) V_31 -> V_188 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_28 >
V_31 -> V_36 -> V_5 -> V_44 ) {
F_31 ( V_76 L_99
L_100
L_104
L_105
L_106 ,
F_68 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_137 -> V_28 ,
( unsigned long long )
V_31 -> V_36 -> V_5 -> V_44 ) ;
V_67 = - 1 ;
} else if ( - 1 == F_95 ( V_42 ,
V_31 -> V_36 ,
V_255 +
1 ) ) {
V_67 = - 1 ;
}
}
return V_67 ;
}
static int F_90 (
const struct V_64 * V_42 ,
const struct V_1 * V_137 ,
int V_255 )
{
struct V_54 * V_226 ;
if ( V_255 >= 3 + V_97 ) {
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_107 ) ;
return 0 ;
}
F_20 (elem_ref_from, &block->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_226 , struct V_30 ,
V_35 ) ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_97
L_108 ,
V_255 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_137 -> V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ,
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
V_255 +
1 ) )
return 1 ;
}
return 0 ;
}
static void F_69 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_31 ( V_76
L_109
L_110 ,
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
L_111
L_110 ,
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
const struct V_1 * V_137 )
{
if ( V_137 -> V_14 &&
V_42 -> V_78 -> V_6 == V_137 -> V_6 &&
V_42 -> V_78 -> V_5 -> V_41 == V_137 -> V_5 -> V_41 )
return 'S' ;
else if ( V_137 -> V_14 )
return 's' ;
else if ( V_137 -> V_13 )
return 'M' ;
else
return 'D' ;
}
static void F_91 ( const struct V_64 * V_42 )
{
F_57 ( V_42 , V_42 -> V_78 , 0 ) ;
}
static void F_57 ( const struct V_64 * V_42 ,
const struct V_1 * V_137 ,
int V_256 )
{
struct V_54 * V_225 ;
int V_257 ;
static char V_258 [ 80 ] ;
int V_259 ;
V_257 = sprintf ( V_258 , L_112 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_137 -> V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_137 -> V_18 ) ;
if ( V_256 + V_257 > V_260 ) {
F_31 ( L_113 ) ;
return;
}
F_31 ( V_258 ) ;
V_256 += V_257 ;
if ( F_89 ( & V_137 -> V_25 ) ) {
F_31 ( L_60 ) ;
return;
}
if ( V_137 -> V_18 > 1 &&
! ( V_42 -> V_82 & V_261 ) ) {
F_31 ( L_114 ) ;
return;
}
V_259 = V_256 ;
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_225 , struct V_30 ,
V_34 ) ;
while ( V_259 < V_256 ) {
F_31 ( L_115 ) ;
V_259 ++ ;
}
if ( V_31 -> V_33 > 1 )
V_257 = sprintf ( V_258 , L_116 , V_31 -> V_33 ) ;
else
V_257 = sprintf ( V_258 , L_117 ) ;
if ( V_256 + V_257 >
V_260 ) {
F_31 ( L_113 ) ;
V_259 = 0 ;
continue;
}
F_31 ( V_258 ) ;
F_57 ( V_42 , V_31 -> V_36 ,
V_256 + V_257 ) ;
V_259 = 0 ;
}
}
static struct V_30 * F_56 (
struct V_64 * V_42 ,
struct V_90 * V_166 ,
struct V_1 * V_89 ,
struct V_1 * V_262 ,
T_1 V_188 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( V_166 -> V_92 -> V_41 ,
V_166 -> V_6 ,
V_262 -> V_5 -> V_41 ,
V_262 -> V_6 ,
& V_42 -> V_94 ) ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_31 ( V_76
L_118 L_74 ) ;
return NULL ;
}
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_262 ;
V_31 -> V_33 = 1 ;
V_31 -> V_188 = V_188 ;
if ( V_42 -> V_82 & V_148 )
F_69 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_262 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_94 ) ;
} else {
V_31 -> V_33 ++ ;
V_31 -> V_188 = V_188 ;
if ( V_42 -> V_82 & V_148 )
F_69 ( V_42 , V_31 ) ;
}
return V_31 ;
}
static struct V_1 * F_55 (
struct V_64 * V_42 ,
struct V_90 * V_138 ,
const char * V_116 ,
int V_13 ,
int V_15 ,
int V_17 ,
int V_18 ,
int * V_254 )
{
struct V_1 * V_137 ;
V_137 = F_19 ( V_138 -> V_92 -> V_41 ,
V_138 -> V_6 ,
& V_42 -> V_93 ) ;
if ( NULL == V_137 ) {
struct V_38 * V_5 ;
V_137 = F_3 () ;
if ( NULL == V_137 ) {
F_31 ( V_76 L_1 ) ;
return NULL ;
}
V_5 = F_33 ( V_138 -> V_92 -> V_41 ) ;
if ( NULL == V_5 ) {
F_31 ( V_76
L_119 ) ;
F_5 ( V_137 ) ;
return NULL ;
}
V_137 -> V_5 = V_5 ;
V_137 -> V_6 = V_138 -> V_6 ;
V_137 -> V_7 = V_138 -> V_96 ;
V_137 -> V_13 = V_13 ;
V_137 -> V_15 = V_15 ;
V_137 -> V_17 = V_17 ;
V_137 -> V_18 = V_18 ;
if ( V_42 -> V_82 & V_148 )
F_31 ( V_76
L_120 ,
V_116 ,
F_68 ( V_42 , V_137 ) ,
( unsigned long long ) V_137 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_137 -> V_6 ,
V_18 ) ;
F_16 ( & V_137 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_137 , & V_42 -> V_93 ) ;
if ( NULL != V_254 )
* V_254 = 1 ;
} else {
if ( NULL != V_254 )
* V_254 = 0 ;
}
return V_137 ;
}
static void F_88 ( struct V_64 * V_42 ,
T_1 V_165 ,
struct V_38 * V_5 ,
T_1 V_6 )
{
int V_80 ;
int V_18 ;
int V_67 ;
struct V_90 V_138 ;
int V_263 = 0 ;
V_80 = F_39 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_165 , V_42 -> V_87 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_165 , V_42 -> V_87 ,
& V_138 , V_18 ) ;
if ( V_67 ) {
F_31 ( V_76 L_7
L_121
L_9 ,
( unsigned long long ) V_165 , V_18 ) ;
continue;
}
if ( V_5 -> V_41 == V_138 . V_92 -> V_41 &&
V_6 == V_138 . V_6 ) {
V_263 ++ ;
F_42 ( & V_138 ) ;
break;
}
F_42 ( & V_138 ) ;
}
if ( ! V_263 ) {
F_31 ( V_76 L_122
L_123
L_124 ,
( unsigned long long ) V_165 , V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_40 ( V_42 , V_165 ,
V_42 -> V_87 ,
& V_138 , V_18 ) ;
if ( V_67 )
continue;
F_31 ( V_76 L_125
L_126 ,
( unsigned long long ) V_165 ,
V_138 . V_92 -> V_43 ,
( unsigned long long ) V_138 . V_6 ,
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
int F_96 ( int V_264 , struct V_100 * V_101 )
{
struct V_38 * V_5 ;
if ( ! V_265 )
return F_97 ( V_264 , V_101 ) ;
F_98 ( & V_266 ) ;
V_5 = F_33 ( V_101 -> V_267 ) ;
if ( NULL != V_5 &&
( V_264 & V_268 ) && V_101 -> V_269 > 0 ) {
T_1 V_6 ;
V_6 = 4096 * V_101 -> V_270 ;
if ( V_5 -> V_42 -> V_82 &
V_271 )
F_31 ( V_76
L_127
L_128 ,
V_264 , ( unsigned long ) V_101 -> V_270 ,
( unsigned long long ) V_6 ,
( unsigned long ) V_101 -> V_269 , V_101 -> V_106 ,
V_101 -> V_267 ) ;
F_87 ( V_5 , V_6 ,
& V_101 -> V_106 , 1 , NULL ,
NULL , V_101 , V_264 ) ;
} else if ( NULL != V_5 && ( V_264 & V_249 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_271 )
F_31 ( V_76
L_129 ,
V_264 , V_101 -> V_267 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_271 |
V_148 ) ) )
F_31 ( V_76
L_130
L_131
L_132 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_137 =
& V_5 -> V_45 ;
V_137 -> V_15 = 0 ;
V_137 -> V_17 = 0 ;
V_137 -> V_16 = 0 ;
V_137 -> V_28 = V_5 -> V_44 + 1 ;
V_137 -> V_27 = V_264 ;
V_137 -> V_20 = V_101 -> V_242 ;
V_137 -> V_21 . V_101 = V_101 -> V_243 ;
V_137 -> V_19 = NULL ;
V_101 -> V_242 = V_137 ;
V_101 -> V_243 = V_244 ;
}
}
F_99 ( & V_266 ) ;
return F_97 ( V_264 , V_101 ) ;
}
void F_100 ( int V_264 , struct V_22 * V_22 )
{
struct V_38 * V_5 ;
if ( ! V_265 ) {
F_78 ( V_264 , V_22 ) ;
return;
}
F_98 ( & V_266 ) ;
V_5 = F_33 ( V_22 -> V_214 ) ;
if ( NULL != V_5 &&
( V_264 & V_268 ) && NULL != V_22 -> V_272 ) {
unsigned int V_48 ;
T_1 V_6 ;
int V_234 ;
char * * V_233 ;
V_6 = 512 * V_22 -> V_215 ;
V_234 = 0 ;
if ( V_5 -> V_42 -> V_82 &
V_271 )
F_31 ( V_76
L_133
L_134 ,
V_264 , V_22 -> V_273 , ( unsigned long ) V_22 -> V_215 ,
( unsigned long long ) V_6 ,
V_22 -> V_214 ) ;
V_233 = F_101 ( sizeof( * V_233 ) * V_22 -> V_273 ,
V_29 ) ;
if ( ! V_233 )
goto V_274;
for ( V_48 = 0 ; V_48 < V_22 -> V_273 ; V_48 ++ ) {
F_6 ( V_22 -> V_272 [ V_48 ] . V_275 != V_95 ) ;
V_233 [ V_48 ] = F_82 ( V_22 -> V_272 [ V_48 ] . V_276 ) ;
if ( ! V_233 [ V_48 ] ) {
while ( V_48 > 0 ) {
V_48 -- ;
F_72 ( V_22 -> V_272 [ V_48 ] . V_276 ) ;
}
F_7 ( V_233 ) ;
goto V_274;
}
if ( ( V_271 |
V_148 ) ==
( V_5 -> V_42 -> V_82 &
( V_271 |
V_148 ) ) )
F_31 ( V_76
L_135 ,
V_48 , V_22 -> V_272 [ V_48 ] . V_276 ,
V_22 -> V_272 [ V_48 ] . V_275 ,
V_22 -> V_272 [ V_48 ] . V_277 ) ;
}
F_87 ( V_5 , V_6 ,
V_233 , V_22 -> V_273 ,
V_22 , & V_234 ,
NULL , V_264 ) ;
while ( V_48 > 0 ) {
V_48 -- ;
F_72 ( V_22 -> V_272 [ V_48 ] . V_276 ) ;
}
F_7 ( V_233 ) ;
} else if ( NULL != V_5 && ( V_264 & V_249 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_271 )
F_31 ( V_76
L_136 ,
V_264 , V_22 -> V_214 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_271 |
V_148 ) ) )
F_31 ( V_76
L_137
L_131
L_132 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_137 =
& V_5 -> V_45 ;
V_137 -> V_15 = 0 ;
V_137 -> V_17 = 0 ;
V_137 -> V_16 = 0 ;
V_137 -> V_28 = V_5 -> V_44 + 1 ;
V_137 -> V_27 = V_264 ;
V_137 -> V_20 = V_22 -> V_218 ;
V_137 -> V_21 . V_22 = V_22 -> V_216 ;
V_137 -> V_19 = NULL ;
V_22 -> V_218 = V_137 ;
V_22 -> V_216 = V_240 ;
}
}
V_274:
F_99 ( & V_266 ) ;
F_78 ( V_264 , V_22 ) ;
}
int F_102 ( struct V_278 * V_84 ,
struct V_65 * V_66 ,
int V_279 , T_2 V_82 )
{
int V_67 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( V_84 -> V_280 != V_84 -> V_281 ) {
F_31 ( V_76
L_138 ,
V_84 -> V_280 , V_84 -> V_281 ) ;
return - 1 ;
}
if ( V_84 -> V_280 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_139 ,
V_84 -> V_280 , ( unsigned long ) V_95 ) ;
return - 1 ;
}
if ( V_84 -> V_281 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_140 ,
V_84 -> V_281 , ( unsigned long ) V_95 ) ;
return - 1 ;
}
if ( V_84 -> V_282 & ( ( T_1 ) V_95 - 1 ) ) {
F_31 ( V_76
L_141 ,
V_84 -> V_282 , ( unsigned long ) V_95 ) ;
return - 1 ;
}
V_42 = F_4 ( sizeof( * V_42 ) , V_29 ) ;
if ( NULL == V_42 ) {
F_31 ( V_76 L_142 ) ;
return - 1 ;
}
if ( ! V_265 ) {
F_103 ( & V_266 ) ;
F_26 ( & V_62 ) ;
V_265 = 1 ;
}
F_98 ( & V_266 ) ;
V_42 -> V_84 = V_84 ;
V_42 -> V_82 = V_82 ;
V_42 -> V_169 = V_279 ;
V_42 -> V_79 = 0 ;
V_42 -> V_87 = V_84 -> V_280 ;
V_42 -> V_112 = V_84 -> V_282 ;
F_2 ( & V_42 -> V_114 ) ;
F_14 ( & V_42 -> V_93 ) ;
F_22 ( & V_42 -> V_94 ) ;
V_42 -> V_115 = 0 ;
V_42 -> V_78 = NULL ;
F_32 (device, dev_head, dev_list) {
struct V_38 * V_39 ;
char * V_283 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_39 = F_12 () ;
if ( NULL == V_39 ) {
F_31 ( V_76
L_142 ) ;
F_99 ( & V_266 ) ;
return - 1 ;
}
V_39 -> V_41 = V_73 -> V_41 ;
V_39 -> V_42 = V_42 ;
F_104 ( V_39 -> V_41 , V_39 -> V_43 ) ;
V_39 -> V_43 [ V_284 - 1 ] = '\0' ;
for ( V_283 = V_39 -> V_43 ; * V_283 != '\0' ; V_283 ++ ) ;
while ( V_283 > V_39 -> V_43 && * V_283 != '/' )
V_283 -- ;
if ( * V_283 == '/' )
V_283 ++ ;
F_105 ( V_39 -> V_43 , V_283 , sizeof( V_39 -> V_43 ) ) ;
F_27 ( V_39 ,
& V_62 ) ;
}
V_67 = F_30 ( V_42 , V_66 ) ;
if ( 0 != V_67 ) {
F_99 ( & V_266 ) ;
F_106 ( V_84 , V_66 ) ;
return V_67 ;
}
if ( V_42 -> V_82 & V_285 )
F_83 ( V_42 ) ;
if ( V_42 -> V_82 & V_286 )
F_91 ( V_42 ) ;
F_99 ( & V_266 ) ;
return 0 ;
}
void F_106 ( struct V_278 * V_84 ,
struct V_65 * V_66 )
{
struct V_54 * V_223 ;
struct V_54 * V_287 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( ! V_265 )
return;
F_98 ( & V_266 ) ;
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
L_143
L_144 ) ;
F_99 ( & V_266 ) ;
return;
}
F_92 (elem_all, tmp_all, &state->all_blocks_list) {
struct V_1 * const V_224 =
F_21 ( V_223 , struct V_1 ,
V_24 ) ;
struct V_54 * V_225 ;
struct V_54 * V_237 ;
F_92 (elem_ref_to, tmp_ref_to,
&b_all->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_225 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_148 )
F_93 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 )
F_10 ( V_31 ) ;
}
if ( V_224 -> V_15 || V_224 -> V_17 )
F_5 ( V_224 ) ;
else
F_31 ( V_76 L_145
L_146
L_147 ,
F_68 ( V_42 , V_224 ) ,
( unsigned long long ) V_224 -> V_7 ,
V_224 -> V_5 -> V_43 ,
( unsigned long long ) V_224 -> V_6 ,
V_224 -> V_18 ) ;
}
F_99 ( & V_266 ) ;
F_7 ( V_42 ) ;
}
