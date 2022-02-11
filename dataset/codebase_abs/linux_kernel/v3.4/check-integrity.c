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
V_69 = F_31 ( sizeof( * V_69 ) , V_29 ) ;
if ( NULL == V_69 ) {
F_32 ( V_76 L_1 ) ;
return - 1 ;
}
F_33 (device, dev_head, dev_list) {
int V_48 ;
struct V_38 * V_5 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_5 = F_34 ( V_73 -> V_41 ) ;
F_6 ( NULL == V_5 ) ;
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ ) {
V_67 = F_35 (
V_42 , V_5 , V_73 , V_48 ,
& V_74 , V_69 ) ;
if ( 0 != V_67 && 0 == V_48 ) {
F_7 ( V_69 ) ;
return V_67 ;
}
}
}
if ( NULL == V_42 -> V_78 ) {
F_32 ( V_76 L_2 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_42 -> V_79 = F_36 ( V_69 ) ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
int V_80 ;
int V_18 ;
T_1 V_81 ;
switch ( V_75 ) {
case 0 :
V_81 = F_37 ( V_69 ) ;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_3 ,
( unsigned long long ) V_81 ) ;
break;
case 1 :
V_81 = F_38 ( V_69 ) ;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_4 ,
( unsigned long long ) V_81 ) ;
break;
case 2 :
V_81 = F_39 ( V_69 ) ;
if ( 0 == V_81 )
continue;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_5 ,
( unsigned long long ) V_81 ) ;
break;
}
V_80 =
F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_32 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
struct V_92 * V_93 ;
V_67 = F_41 ( V_42 , V_81 , V_87 ,
& V_91 ,
V_18 ) ;
if ( V_67 ) {
F_32 ( V_76 L_7
L_8
L_9 ,
( unsigned long long ) V_81 ,
V_18 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_89 = F_19 (
V_91 . V_94 -> V_41 ,
V_91 . V_6 ,
& V_42 -> V_95 ) ;
F_6 ( NULL == V_89 ) ;
V_31 = F_25 (
V_91 . V_94 -> V_41 ,
V_91 . V_6 ,
V_42 -> V_78 -> V_5 ->
V_41 ,
V_42 -> V_78 -> V_6 ,
& V_42 -> V_96 ) ;
F_6 ( NULL == V_31 ) ;
V_67 = F_42 ( V_42 , & V_91 ) ;
if ( V_67 < ( int ) V_97 ) {
F_32 ( V_76
L_10 ,
( unsigned long long )
V_91 . V_98 ) ;
F_43 ( & V_91 ) ;
F_7 ( V_69 ) ;
return - 1 ;
}
V_93 = (struct V_92 * ) V_91 . V_99 ;
V_67 = F_44 ( V_42 ,
V_89 ,
& V_91 ,
V_93 ,
V_100 + 3 , 1 ) ;
F_43 ( & V_91 ) ;
}
}
F_7 ( V_69 ) ;
return V_67 ;
}
static int F_35 (
struct V_64 * V_42 ,
struct V_38 * V_5 ,
struct V_72 * V_73 ,
int V_101 ,
struct V_38 * * V_74 ,
struct V_68 * V_69 )
{
struct V_68 * V_102 ;
T_1 V_6 ;
struct V_103 * V_104 ;
struct V_1 * V_105 ;
int V_75 ;
struct V_53 * const V_106 = V_73 -> V_41 ;
V_6 = F_45 ( V_101 ) ;
V_104 = F_46 ( V_106 , V_6 / 4096 , 4096 ) ;
if ( NULL == V_104 )
return - 1 ;
V_102 = (struct V_68 * )
( V_104 -> V_107 + ( V_6 & 4095 ) ) ;
if ( F_47 ( V_102 ) != V_6 ||
strncmp ( ( char * ) ( & ( V_102 -> V_108 ) ) , V_109 ,
sizeof( V_102 -> V_108 ) ) ||
memcmp ( V_73 -> V_110 , V_102 -> V_111 . V_110 , V_112 ) ) {
F_48 ( V_104 ) ;
return 0 ;
}
V_105 =
F_19 ( V_106 ,
V_6 ,
& V_42 -> V_95 ) ;
if ( NULL == V_105 ) {
V_105 = F_3 () ;
if ( NULL == V_105 ) {
F_32 ( V_76 L_1 ) ;
F_48 ( V_104 ) ;
return - 1 ;
}
V_105 -> V_6 = V_6 ;
V_105 -> V_5 = V_5 ;
V_105 -> V_7 = V_6 ;
V_105 -> V_8 = F_49 ( V_102 ) ;
V_105 -> V_13 = 1 ;
V_105 -> V_14 = 1 ;
V_105 -> V_15 = 1 ;
V_105 -> V_17 = 0 ;
V_105 -> V_18 = 1 + V_101 ;
if ( V_42 -> V_82 & V_113 )
F_32 ( V_76 L_11
L_12 ,
V_106 , V_73 -> V_43 ,
( unsigned long long ) V_6 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_101 ) ;
F_16 ( & V_105 -> V_24 ,
& V_42 -> V_114 ) ;
F_15 ( V_105 ,
& V_42 -> V_95 ) ;
}
if ( F_49 ( V_102 ) >
V_42 -> V_115 ||
0 == V_42 -> V_115 ) {
memcpy ( V_69 , V_102 , sizeof( * V_69 ) ) ;
* V_74 = V_5 ;
V_42 -> V_115 =
F_49 ( V_102 ) ;
V_42 -> V_78 = V_105 ;
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
F_50 ( V_120 ) ;
V_116 = L_13 ;
V_81 = F_37 ( V_102 ) ;
break;
case 1 :
V_118 . V_11 =
F_50 ( V_121 ) ;
V_116 = L_14 ;
V_81 = F_38 ( V_102 ) ;
break;
case 2 :
V_118 . V_11 =
F_50 ( V_122 ) ;
V_116 = L_15 ;
V_81 = F_39 ( V_102 ) ;
if ( 0 == V_81 )
continue;
break;
}
V_80 =
F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_32 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_1 * V_89 ;
struct V_90 V_91 ;
struct V_30 * V_31 ;
if ( F_41 ( V_42 , V_81 , V_87 ,
& V_91 ,
V_18 ) ) {
F_32 ( V_76 L_16
L_17 ,
( unsigned long long ) V_81 ,
V_18 ) ;
F_48 ( V_104 ) ;
return - 1 ;
}
V_89 = F_51 (
V_42 , & V_91 ,
V_116 , 1 , 1 , 0 ,
V_18 , NULL ) ;
if ( NULL == V_89 ) {
F_43 ( & V_91 ) ;
F_48 ( V_104 ) ;
return - 1 ;
}
V_89 -> V_10 = V_118 ;
V_89 -> V_8 = V_9 ;
V_31 = F_52 (
V_42 , & V_91 ,
V_89 , V_105 ,
V_9 ) ;
F_43 ( & V_91 ) ;
if ( NULL == V_31 ) {
F_48 ( V_104 ) ;
return - 1 ;
}
}
}
if ( V_42 -> V_82 & V_123 )
F_53 ( V_42 , V_105 , 0 ) ;
F_48 ( V_104 ) ;
return 0 ;
}
static struct V_124 * F_54 ( void )
{
struct V_124 * V_125 ;
V_125 = F_4 ( sizeof( * V_125 ) , V_29 ) ;
if ( NULL == V_125 )
F_32 ( V_76 L_18 ) ;
else
V_125 -> V_108 = V_126 ;
return V_125 ;
}
static void F_55 ( struct V_124 * V_125 )
{
F_6 ( ! ( NULL == V_125 ||
V_126 == V_125 -> V_108 ) ) ;
F_7 ( V_125 ) ;
}
static int F_44 (
struct V_64 * V_42 ,
struct V_1 * const V_127 ,
struct V_90 * const V_128 ,
struct V_92 * const V_129 ,
int V_130 , int V_131 )
{
struct V_124 V_132 = { 0 } ;
struct V_124 * V_125 ;
struct V_124 * V_133 ;
V_125 = & V_132 ;
V_125 -> error = 0 ;
V_125 -> V_48 = - 1 ;
V_125 -> V_134 = V_130 ;
V_125 -> V_135 = V_127 ;
V_125 -> V_136 = V_128 ;
V_125 -> V_89 = NULL ;
V_125 -> V_93 = V_129 ;
V_125 -> V_137 = NULL ;
V_138:
V_125 -> V_135 -> V_8 = F_56 ( V_125 -> V_93 -> V_8 ) ;
if ( 0 == V_125 -> V_93 -> V_139 ) {
struct V_140 * const V_141 =
(struct V_140 * ) V_125 -> V_93 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_142 = F_57 ( V_141 -> V_143 . V_144 ) ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_19
L_20 ,
( unsigned long long )
V_125 -> V_136 -> V_98 ,
V_125 -> V_142 ,
( unsigned long long )
F_56 ( V_141 -> V_143 . V_8 ) ,
( unsigned long long )
F_56 ( V_141 -> V_143 . V_146 ) ) ;
}
V_147:
if ( 0 == V_125 -> V_80 || V_125 -> V_18 > V_125 -> V_80 ) {
V_125 -> V_48 ++ ;
V_125 -> V_80 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_142 ) {
struct V_148 * V_149 = V_141 -> V_150 + V_125 -> V_48 ;
struct V_117 * V_10 = & V_149 -> V_151 ;
T_2 type ;
const T_3 V_152 = F_57 ( V_149 -> V_12 ) ;
type = V_10 -> type ;
if ( V_119 == type ) {
const struct V_153 * const V_154 =
(struct V_153 * )
( V_125 -> V_136 -> V_99 +
F_58 ( struct V_140 , V_150 ) +
V_152 ) ;
const T_1 V_81 =
F_56 ( V_154 -> V_155 ) ;
V_125 -> error =
F_59 (
V_42 ,
V_125 -> V_135 ,
V_125 -> V_136 ,
V_81 ,
V_125 -> V_134 ,
& V_125 -> V_156 ,
& V_125 -> V_89 ,
V_131 ,
& V_125 -> V_80 ,
& V_125 -> V_18 ,
V_10 ,
F_56 ( V_154 ->
V_8 ) ) ;
if ( V_125 -> error )
goto V_157;
if ( NULL != V_125 -> V_89 ) {
struct V_92 * const V_158 =
(struct V_92 * )
V_125 -> V_156 . V_99 ;
V_133 =
F_54 () ;
if ( NULL == V_133 ) {
F_43 (
& V_125 ->
V_156 ) ;
goto V_157;
}
V_133 -> V_48 = - 1 ;
V_133 -> V_135 = V_125 -> V_89 ;
V_133 -> V_136 =
& V_125 -> V_156 ;
V_133 -> V_89 = NULL ;
V_133 -> V_93 = V_158 ;
V_133 -> V_134 =
V_125 -> V_134 - 1 ;
V_133 -> V_137 = V_125 ;
V_125 = V_133 ;
goto V_138;
}
} else if ( V_159 == type &&
V_42 -> V_160 ) {
V_125 -> error = F_60 (
V_42 ,
V_125 -> V_135 ,
V_125 -> V_136 ,
V_152 ,
V_131 ) ;
if ( V_125 -> error )
goto V_157;
}
goto V_147;
}
} else {
struct V_161 * const V_162 = (struct V_161 * ) V_125 -> V_93 ;
if ( - 1 == V_125 -> V_48 ) {
V_125 -> V_142 = F_57 ( V_162 -> V_143 . V_144 ) ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76 L_21
L_22 ,
( unsigned long long )
V_125 -> V_136 -> V_98 ,
V_162 -> V_143 . V_139 , V_125 -> V_142 ,
( unsigned long long )
F_56 ( V_162 -> V_143 . V_8 ) ,
( unsigned long long )
F_56 ( V_162 -> V_143 . V_146 ) ) ;
}
V_163:
if ( 0 == V_125 -> V_80 || V_125 -> V_18 > V_125 -> V_80 ) {
V_125 -> V_48 ++ ;
V_125 -> V_80 = 0 ;
}
if ( V_125 -> V_48 < V_125 -> V_142 ) {
struct V_164 * V_165 =
V_162 -> V_166 + V_125 -> V_48 ;
const T_1 V_81 =
F_56 ( V_165 -> V_167 ) ;
V_125 -> error = F_59 (
V_42 ,
V_125 -> V_135 ,
V_125 -> V_136 ,
V_81 ,
V_125 -> V_134 ,
& V_125 -> V_156 ,
& V_125 -> V_89 ,
V_131 ,
& V_125 -> V_80 ,
& V_125 -> V_18 ,
& V_165 -> V_151 ,
F_56 ( V_165 -> V_8 ) ) ;
if ( V_125 -> error )
goto V_157;
if ( NULL != V_125 -> V_89 ) {
struct V_92 * const V_158 =
(struct V_92 * )
V_125 -> V_156 . V_99 ;
V_133 = F_54 () ;
if ( NULL == V_133 )
goto V_157;
V_133 -> V_48 = - 1 ;
V_133 -> V_135 = V_125 -> V_89 ;
V_133 -> V_136 = & V_125 -> V_156 ;
V_133 -> V_89 = NULL ;
V_133 -> V_93 = V_158 ;
V_133 -> V_134 =
V_125 -> V_134 - 1 ;
V_133 -> V_137 = V_125 ;
V_125 = V_133 ;
goto V_138;
}
goto V_163;
}
}
V_157:
if ( NULL != V_125 -> V_137 ) {
struct V_124 * const V_137 = V_125 -> V_137 ;
F_43 ( V_125 -> V_136 ) ;
if ( V_125 -> error ) {
V_137 -> error = V_125 -> error ;
F_55 ( V_125 ) ;
V_125 = V_137 ;
goto V_157;
}
F_55 ( V_125 ) ;
V_125 = V_137 ;
goto V_138;
} else {
F_6 ( & V_132 != V_125 ) ;
}
return V_125 -> error ;
}
static int F_59 (
struct V_64 * V_42 ,
struct V_1 * V_135 ,
struct V_90 * V_136 ,
T_1 V_81 ,
int V_134 ,
struct V_90 * V_156 ,
struct V_1 * * V_168 ,
int V_131 ,
int * V_169 , int * V_170 ,
struct V_117 * V_10 ,
T_1 V_171 )
{
struct V_1 * V_89 = NULL ;
int V_67 ;
struct V_30 * V_31 ;
int V_172 ;
int V_173 ;
* V_168 = NULL ;
if ( 0 == * V_169 ) {
* V_169 =
F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_32 ( V_76 L_6 ,
( unsigned long long ) V_81 , * V_169 ) ;
* V_170 = 1 ;
}
if ( * V_170 > * V_169 )
return 0 ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_23 ,
* V_170 ) ;
V_67 = F_41 ( V_42 , V_81 ,
V_97 ,
V_156 , * V_170 ) ;
if ( V_67 ) {
F_32 ( V_76
L_24 ,
( unsigned long long ) V_81 , * V_170 ) ;
F_43 ( V_156 ) ;
* V_168 = NULL ;
return - 1 ;
}
V_89 = F_51 ( V_42 ,
V_156 , L_25 ,
1 , V_131 ,
! V_131 ,
* V_170 ,
& V_173 ) ;
if ( NULL == V_89 ) {
F_43 ( V_156 ) ;
* V_168 = NULL ;
return - 1 ;
}
if ( V_173 ) {
V_31 = NULL ;
V_89 -> V_8 = V_9 ;
} else {
if ( V_89 -> V_7 != V_81 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) ) {
F_32 ( V_76
L_26
L_27
L_28 ,
( unsigned long long ) V_81 ,
V_156 -> V_94 -> V_43 ,
( unsigned long long ) V_156 -> V_6 ,
* V_170 ,
F_61 ( V_42 , V_89 ) ,
( unsigned long long ) V_89 -> V_7 ) ;
} else if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_26
L_29 ,
( unsigned long long ) V_81 ,
V_156 -> V_94 -> V_43 ,
( unsigned long long ) V_156 -> V_6 ,
* V_170 ,
F_61 ( V_42 , V_89 ) ) ;
V_89 -> V_7 = V_81 ;
V_89 -> V_18 = * V_170 ;
V_31 = F_25 (
V_156 -> V_94 -> V_41 ,
V_156 -> V_6 ,
V_136 -> V_94 -> V_41 ,
V_136 -> V_6 ,
& V_42 -> V_96 ) ;
}
V_89 -> V_10 = * V_10 ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_32 ( V_76 L_1 ) ;
F_43 ( V_156 ) ;
* V_168 = NULL ;
return - 1 ;
}
V_172 = 1 ;
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_135 ;
V_31 -> V_33 = 1 ;
V_31 -> V_171 = V_171 ;
if ( V_42 -> V_82 & V_145 )
F_62 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_135 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_96 ) ;
} else {
V_172 = 0 ;
if ( 0 == V_134 ) {
V_31 -> V_33 ++ ;
V_31 -> V_171 = V_171 ;
if ( V_42 -> V_82 & V_145 )
F_62 ( V_42 , V_31 ) ;
}
}
if ( V_134 > 0 && V_172 ) {
V_67 = F_42 ( V_42 , V_156 ) ;
if ( V_67 < ( int ) V_97 ) {
F_32 ( V_76
L_30 ,
( unsigned long long ) V_81 ) ;
F_43 ( V_156 ) ;
* V_168 = NULL ;
return - 1 ;
}
* V_168 = V_89 ;
} else {
* V_168 = NULL ;
}
( * V_170 ) ++ ;
return 0 ;
}
static int F_60 (
struct V_64 * V_42 ,
struct V_1 * V_135 ,
struct V_90 * V_136 ,
T_3 V_152 , int V_131 )
{
int V_67 ;
struct V_174 * V_175 =
(struct V_174 * ) ( V_136 -> V_99 +
F_58 ( struct V_140 ,
V_150 ) + V_152 ) ;
T_1 V_81 =
F_56 ( V_175 -> V_176 ) +
F_56 ( V_175 -> V_12 ) ;
T_1 V_177 = F_56 ( V_175 -> V_177 ) ;
T_1 V_8 = F_56 ( V_175 -> V_8 ) ;
struct V_30 * V_31 ;
if ( V_42 -> V_82 & V_178 )
F_32 ( V_76 L_31
L_32 ,
V_175 -> type ,
( unsigned long long )
F_56 ( V_175 -> V_176 ) ,
( unsigned long long )
F_56 ( V_175 -> V_12 ) ,
( unsigned long long )
F_56 ( V_175 -> V_177 ) ) ;
if ( V_179 != V_175 -> type ||
( ( T_1 ) 0 ) == F_56 ( V_175 -> V_176 ) )
return 0 ;
while ( V_177 > 0 ) {
T_3 V_180 ;
int V_80 ;
int V_18 ;
if ( V_177 > V_97 )
V_180 = V_97 ;
else
V_180 = V_177 ;
V_80 =
F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_32 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
struct V_90 V_156 ;
struct V_1 * V_89 ;
int V_173 ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76 L_33
L_34 , V_18 ) ;
if ( V_42 -> V_82 & V_178 )
F_32 ( V_76
L_35 ,
( unsigned long long ) V_81 ,
V_180 ) ;
V_67 = F_41 ( V_42 , V_81 ,
V_180 , & V_156 ,
V_18 ) ;
if ( V_67 ) {
F_32 ( V_76
L_36
L_37 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_89 = F_51 (
V_42 ,
& V_156 ,
L_25 ,
0 ,
V_131 ,
! V_131 ,
V_18 ,
& V_173 ) ;
if ( NULL == V_89 ) {
F_32 ( V_76
L_1 ) ;
F_43 ( & V_156 ) ;
return - 1 ;
}
if ( ! V_173 ) {
if ( V_89 -> V_7 != V_81 &&
! ( ! V_89 -> V_13 &&
0 == V_89 -> V_7 ) ) {
F_32 ( V_76
L_38
L_39
L_40
L_41
L_42 ,
( unsigned long long ) V_81 ,
V_156 . V_94 -> V_43 ,
( unsigned long long )
V_156 . V_6 ,
V_18 ,
( unsigned long long )
V_89 -> V_7 ) ;
}
V_89 -> V_7 = V_81 ;
V_89 -> V_18 = V_18 ;
}
V_31 = F_52 ( V_42 ,
& V_156 ,
V_89 , V_135 ,
V_8 ) ;
F_43 ( & V_156 ) ;
if ( NULL == V_31 )
return - 1 ;
}
V_81 += V_180 ;
V_177 -= V_180 ;
}
return 0 ;
}
static int F_41 ( struct V_64 * V_42 , T_1 V_155 , T_3 V_181 ,
struct V_90 * V_182 ,
int V_18 )
{
int V_67 ;
T_1 V_183 ;
struct V_184 * V_185 = NULL ;
struct V_72 * V_73 ;
V_183 = V_181 ;
V_67 = F_63 ( & V_42 -> V_84 -> V_85 -> V_86 , V_186 ,
V_155 , & V_183 , & V_185 , V_18 ) ;
V_73 = V_185 -> V_187 [ 0 ] . V_94 ;
V_182 -> V_94 = F_34 ( V_73 -> V_41 ) ;
V_182 -> V_6 = V_185 -> V_187 [ 0 ] . V_188 ;
V_182 -> V_98 = V_155 ;
V_182 -> V_181 = V_181 ;
V_182 -> V_99 = NULL ;
V_182 -> V_104 = NULL ;
if ( 0 == V_67 )
F_7 ( V_185 ) ;
if ( NULL == V_182 -> V_94 ) {
V_67 = - V_189 ;
F_32 ( V_76 L_43 ) ;
}
return V_67 ;
}
static int F_64 ( struct V_64 * V_42 , T_1 V_155 ,
T_3 V_181 , struct V_53 * V_41 ,
struct V_90 * V_182 )
{
V_182 -> V_94 = F_34 ( V_41 ) ;
V_182 -> V_6 = V_155 ;
V_182 -> V_98 = V_155 ;
V_182 -> V_181 = V_181 ;
V_182 -> V_99 = NULL ;
V_182 -> V_104 = NULL ;
if ( NULL != V_182 -> V_94 ) {
return 0 ;
} else {
F_32 ( V_76 L_44 ) ;
return - V_189 ;
}
}
static void F_43 ( struct V_90 * V_136 )
{
if ( NULL != V_136 -> V_104 ) {
F_48 ( V_136 -> V_104 ) ;
V_136 -> V_104 = NULL ;
}
}
static int F_42 ( struct V_64 * V_42 ,
struct V_90 * V_136 )
{
V_136 -> V_104 = NULL ;
if ( V_136 -> V_6 & 4095 ) {
F_32 ( V_76
L_45 ,
( unsigned long long ) V_136 -> V_6 ) ;
return - 1 ;
}
if ( V_136 -> V_181 > 4096 ) {
F_32 ( V_76
L_46 ,
V_136 -> V_181 ) ;
return - 1 ;
}
V_136 -> V_104 = F_46 ( V_136 -> V_94 -> V_41 ,
V_136 -> V_6 >> 12 , 4096 ) ;
if ( NULL == V_136 -> V_104 )
return - 1 ;
V_136 -> V_99 = V_136 -> V_104 -> V_107 ;
return V_136 -> V_181 ;
}
static void F_65 ( struct V_64 * V_42 )
{
struct V_54 * V_190 ;
F_6 ( NULL == V_42 ) ;
F_32 ( V_76 L_47 ) ;
F_20 (elem_all, &state->all_blocks_list) {
const struct V_1 * const V_191 =
F_21 ( V_190 , struct V_1 ,
V_24 ) ;
struct V_54 * V_192 ;
struct V_54 * V_193 ;
F_32 ( V_76 L_48 ,
F_61 ( V_42 , V_191 ) ,
( unsigned long long ) V_191 -> V_7 ,
V_191 -> V_5 -> V_43 ,
( unsigned long long ) V_191 -> V_6 ,
V_191 -> V_18 ) ;
F_20 (elem_ref_to, &b_all->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_192 ,
struct V_30 ,
V_34 ) ;
F_32 ( V_76 L_49
L_50
L_51 ,
F_61 ( V_42 , V_191 ) ,
( unsigned long long ) V_191 -> V_7 ,
V_191 -> V_5 -> V_43 ,
( unsigned long long ) V_191 -> V_6 ,
V_191 -> V_18 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
F_20 (elem_ref_from, &b_all->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_193 ,
struct V_30 ,
V_35 ) ;
F_32 ( V_76 L_49
L_52
L_51 ,
F_61 ( V_42 , V_191 ) ,
( unsigned long long ) V_191 -> V_7 ,
V_191 -> V_5 -> V_43 ,
( unsigned long long ) V_191 -> V_6 ,
V_191 -> V_18 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long )
V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long )
V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ) ;
}
F_32 ( V_76 L_53 ) ;
}
}
static int F_66 ( struct V_64 * V_42 ,
const T_2 * V_99 , unsigned int V_194 )
{
struct V_92 * V_47 ;
T_2 V_195 [ V_196 ] ;
T_3 V_197 = ~ ( T_3 ) 0 ;
int V_198 = 0 ;
int V_199 = 0 ;
V_47 = (struct V_92 * ) V_99 ;
if ( memcmp ( V_47 -> V_200 , V_42 -> V_84 -> V_85 -> V_200 , V_112 ) )
V_198 ++ ;
V_197 = F_67 ( V_197 , V_99 + V_196 , V_87 - V_196 ) ;
F_68 ( V_197 , V_195 ) ;
if ( memcmp ( V_195 , V_47 -> V_195 , V_42 -> V_79 ) )
V_199 ++ ;
return V_198 || V_199 ;
}
static void F_69 ( struct V_38 * V_5 ,
T_1 V_6 ,
T_2 * V_201 , unsigned int V_181 ,
struct V_22 * V_22 ,
int * V_202 ,
struct V_103 * V_104 ,
int V_27 )
{
int V_13 ;
struct V_1 * V_135 ;
struct V_90 V_136 ;
int V_67 ;
struct V_64 * V_42 = V_5 -> V_42 ;
struct V_53 * V_41 = V_5 -> V_41 ;
F_70 ( V_181 > V_87 ) ;
V_13 = ( 0 == F_66 ( V_42 , V_201 , V_181 ) ) ;
if ( NULL != V_202 )
* V_202 = 0 ;
V_135 = F_19 ( V_41 , V_6 ,
& V_42 -> V_95 ) ;
if ( NULL != V_135 ) {
T_1 V_155 = 0 ;
struct V_54 * V_192 ;
struct V_54 * V_203 ;
if ( V_135 -> V_14 ) {
V_155 = F_56 ( ( (struct V_68 * )
V_201 ) -> V_155 ) ;
V_13 = 1 ;
if ( V_42 -> V_82 &
V_204 ) {
F_32 ( V_76
L_54 ) ;
F_53 ( V_42 , V_135 , 0 ) ;
}
}
if ( V_13 ) {
if ( ! V_135 -> V_14 ) {
V_155 = F_56 ( ( (struct V_92 * )
V_201 ) -> V_155 ) ;
F_71 ( V_42 , V_155 ,
V_5 ,
V_6 ,
V_201 ) ;
}
if ( V_135 -> V_7 != V_155 ) {
F_32 ( V_76
L_55
L_27
L_41
L_42 ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_135 -> V_18 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long )
V_135 -> V_7 ) ;
V_135 -> V_7 = V_155 ;
} else if ( V_42 -> V_82 &
V_145 )
F_32 ( V_76
L_55
L_29 ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_135 -> V_18 ,
F_61 ( V_42 , V_135 ) ) ;
} else {
V_155 = V_135 -> V_7 ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_55
L_29 ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_135 -> V_18 ,
F_61 ( V_42 , V_135 ) ) ;
}
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_56 ,
F_72 ( & V_135 -> V_25 ) ? ' ' : '!' ,
F_72 ( & V_135 -> V_26 ) ? ' ' : '!' ) ;
if ( F_73 ( V_42 , V_135 , 0 ) ) {
F_32 ( V_76 L_57
L_58
L_59
L_60
L_61
L_62 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_135 -> V_18 ,
( unsigned long long ) V_135 -> V_8 ,
( unsigned long long )
F_56 ( V_135 -> V_10 . V_11 ) ,
V_135 -> V_10 . type ,
( unsigned long long )
F_56 ( V_135 -> V_10 . V_12 ) ,
( unsigned long long )
F_56 ( ( (struct V_92 * )
V_201 ) -> V_8 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
F_74 ( V_42 ) ;
}
if ( ! V_135 -> V_15 && ! V_135 -> V_17 ) {
F_32 ( V_76 L_57
L_63
L_64 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ,
V_135 -> V_18 ,
( unsigned long long ) V_135 -> V_8 ,
( unsigned long long )
F_56 ( ( (struct V_92 * )
V_201 ) -> V_8 ) ) ;
F_74 ( V_42 ) ;
return;
}
F_75 (elem_ref_to, tmp_ref_to,
&block->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_192 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_145 )
F_76 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 ) {
F_18 ( & V_31 -> V_34 ) ;
F_18 ( & V_31 -> V_35 ) ;
F_24 ( V_31 ) ;
F_10 ( V_31 ) ;
}
}
if ( V_135 -> V_14 )
V_67 = F_64 ( V_42 , V_155 , V_181 ,
V_41 , & V_136 ) ;
else
V_67 = F_41 ( V_42 , V_155 , V_181 ,
& V_136 , 0 ) ;
if ( V_67 ) {
F_32 ( V_76
L_65
L_66 , ( unsigned long long ) V_155 ) ;
return;
}
V_136 . V_99 = V_201 ;
V_136 . V_94 = V_5 ;
V_136 . V_6 = V_6 ;
if ( V_13 || V_42 -> V_160 ) {
V_135 -> V_17 = 0 ;
V_135 -> V_16 = 0 ;
if ( NULL != V_22 ) {
V_135 -> V_15 = 0 ;
F_6 ( NULL == V_202 ) ;
if ( ! * V_202 ) {
V_135 -> V_20 =
V_22 -> V_205 ;
V_135 -> V_21 . V_22 =
V_22 -> V_206 ;
V_135 -> V_19 = NULL ;
V_22 -> V_205 = V_135 ;
V_22 -> V_206 = V_207 ;
* V_202 = 1 ;
} else {
struct V_1 * V_208 =
(struct V_1 * )
V_22 -> V_205 ;
F_6 ( NULL == V_208 ) ;
V_135 -> V_20 =
V_208 -> V_20 ;
V_135 -> V_21 . V_22 =
V_208 -> V_21 .
V_22 ;
V_135 -> V_19 = V_208 ;
V_22 -> V_205 = V_135 ;
}
} else if ( NULL != V_104 ) {
V_135 -> V_15 = 0 ;
V_135 -> V_20 = V_104 -> V_209 ;
V_135 -> V_21 . V_104 = V_104 -> V_210 ;
V_135 -> V_19 = NULL ;
V_104 -> V_209 = V_135 ;
V_104 -> V_210 = V_211 ;
} else {
V_135 -> V_15 = 1 ;
V_135 -> V_20 = NULL ;
V_135 -> V_21 . V_22 = NULL ;
V_135 -> V_19 = NULL ;
}
}
V_135 -> V_28 = V_5 -> V_44 + 1 ;
V_135 -> V_27 = V_27 ;
if ( V_13 ) {
V_135 -> V_7 = V_155 ;
V_135 -> V_13 = 1 ;
if ( V_135 -> V_14 ) {
V_67 = F_77 (
V_42 ,
V_135 ,
(struct V_68 * )
V_201 ) ;
if ( V_42 -> V_82 &
V_212 ) {
F_32 ( V_76
L_67 ) ;
F_53 ( V_42 , V_135 , 0 ) ;
}
} else {
V_135 -> V_18 = 0 ;
V_67 = F_44 (
V_42 ,
V_135 ,
& V_136 ,
(struct V_92 * )
V_136 . V_99 ,
0 , 0 ) ;
}
if ( V_67 )
F_32 ( V_76
L_68
L_69 ,
( unsigned long long ) V_6 ) ;
} else {
V_135 -> V_13 = 0 ;
V_135 -> V_18 = 0 ;
V_135 -> V_8 = V_9 ;
if ( ! V_42 -> V_160
&& F_72 ( & V_135 -> V_26 ) ) {
F_17 ( V_135 ) ;
F_18 ( & V_135 -> V_24 ) ;
F_5 ( V_135 ) ;
}
}
F_43 ( & V_136 ) ;
} else {
T_1 V_155 ;
if ( ! V_13 ) {
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76 L_70
L_71 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
if ( ! V_42 -> V_160 )
return;
V_155 = 0 ;
V_136 . V_98 = V_155 ;
V_136 . V_181 = V_181 ;
V_136 . V_104 = NULL ;
} else {
V_155 = F_56 ( ( (struct V_92 * )
V_201 ) -> V_155 ) ;
F_71 ( V_42 , V_155 , V_5 ,
V_6 ,
V_201 ) ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_72
L_73 ,
( unsigned long long ) V_155 ,
V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
V_67 = F_41 ( V_42 , V_155 , V_181 , & V_136 ,
0 ) ;
if ( V_67 ) {
F_32 ( V_76
L_65
L_66 ,
( unsigned long long ) V_6 ) ;
return;
}
}
V_136 . V_99 = V_201 ;
V_136 . V_94 = V_5 ;
V_136 . V_6 = V_6 ;
V_135 = F_3 () ;
if ( NULL == V_135 ) {
F_32 ( V_76 L_1 ) ;
F_43 ( & V_136 ) ;
return;
}
V_135 -> V_5 = V_5 ;
V_135 -> V_6 = V_6 ;
V_135 -> V_7 = V_155 ;
V_135 -> V_13 = V_13 ;
V_135 -> V_17 = 0 ;
V_135 -> V_16 = 0 ;
V_135 -> V_18 = 0 ;
V_135 -> V_28 = V_5 -> V_44 + 1 ;
V_135 -> V_27 = V_27 ;
if ( NULL != V_22 ) {
V_135 -> V_15 = 0 ;
F_6 ( NULL == V_202 ) ;
if ( ! * V_202 ) {
V_135 -> V_20 = V_22 -> V_205 ;
V_135 -> V_21 . V_22 = V_22 -> V_206 ;
V_135 -> V_19 = NULL ;
V_22 -> V_205 = V_135 ;
V_22 -> V_206 = V_207 ;
* V_202 = 1 ;
} else {
struct V_1 * V_208 =
(struct V_1 * )
V_22 -> V_205 ;
F_6 ( NULL == V_208 ) ;
V_135 -> V_20 =
V_208 -> V_20 ;
V_135 -> V_21 . V_22 =
V_208 -> V_21 . V_22 ;
V_135 -> V_19 = V_208 ;
V_22 -> V_205 = V_135 ;
}
} else if ( NULL != V_104 ) {
V_135 -> V_15 = 0 ;
V_135 -> V_20 = V_104 -> V_209 ;
V_135 -> V_21 . V_104 = V_104 -> V_210 ;
V_135 -> V_19 = NULL ;
V_104 -> V_209 = V_135 ;
V_104 -> V_210 = V_211 ;
} else {
V_135 -> V_15 = 1 ;
V_135 -> V_20 = NULL ;
V_135 -> V_21 . V_22 = NULL ;
V_135 -> V_19 = NULL ;
}
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_74 ,
V_13 ? 'M' : 'D' ,
( unsigned long long ) V_135 -> V_7 ,
V_135 -> V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ) ;
F_16 ( & V_135 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_135 , & V_42 -> V_95 ) ;
if ( V_13 ) {
V_67 = F_44 ( V_42 , V_135 ,
& V_136 ,
(struct V_92 * )
V_136 . V_99 , 0 , 0 ) ;
if ( V_67 )
F_32 ( V_76
L_75
L_66 ,
( unsigned long long ) V_6 ) ;
}
F_43 ( & V_136 ) ;
}
}
static void V_207 ( struct V_22 * V_213 , int V_214 )
{
struct V_1 * V_135 = (struct V_1 * ) V_213 -> V_205 ;
int V_16 ;
V_16 = 0 ;
if ( V_214 )
V_16 = 1 ;
F_6 ( NULL == V_135 ) ;
V_213 -> V_205 = V_135 -> V_20 ;
V_213 -> V_206 = V_135 -> V_21 . V_22 ;
do {
struct V_1 * V_89 ;
struct V_38 * const V_5 = V_135 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 &
V_215 ) )
F_32 ( V_76
L_76 ,
V_214 ,
F_61 ( V_5 -> V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ) ;
V_89 = V_135 -> V_19 ;
V_135 -> V_16 = V_16 ;
if ( V_135 -> V_27 & V_216 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_215 ) )
F_32 ( V_76
L_77 ,
V_5 -> V_43 ,
( unsigned long long )
V_5 -> V_44 ) ;
}
if ( V_135 -> V_27 & V_217 )
V_135 -> V_28 = 0 ;
V_135 -> V_15 = 1 ;
V_135 = V_89 ;
} while ( NULL != V_135 );
V_213 -> V_206 ( V_213 , V_214 ) ;
}
static void V_211 ( struct V_103 * V_104 , int V_218 )
{
struct V_1 * V_135 = (struct V_1 * ) V_104 -> V_209 ;
int V_16 = ! V_218 ;
struct V_38 * V_5 ;
F_6 ( NULL == V_135 ) ;
V_5 = V_135 -> V_5 ;
if ( ( V_5 -> V_42 -> V_82 & V_215 ) )
F_32 ( V_76
L_78 ,
V_16 ,
F_61 ( V_5 -> V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_135 -> V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ) ;
V_135 -> V_16 = V_16 ;
if ( V_135 -> V_27 & V_216 ) {
V_5 -> V_44 ++ ;
if ( ( V_5 -> V_42 -> V_82 &
V_215 ) )
F_32 ( V_76
L_79 ,
V_5 -> V_43 ,
( unsigned long long ) V_5 -> V_44 ) ;
}
if ( V_135 -> V_27 & V_217 )
V_135 -> V_28 = 0 ;
V_104 -> V_209 = V_135 -> V_20 ;
V_104 -> V_210 = V_135 -> V_21 . V_104 ;
V_135 -> V_15 = 1 ;
V_104 -> V_210 ( V_104 , V_218 ) ;
}
static int F_77 (
struct V_64 * V_42 ,
struct V_1 * const V_219 ,
struct V_68 * const V_220 )
{
int V_75 ;
V_219 -> V_8 = F_49 ( V_220 ) ;
if ( ! ( V_219 -> V_8 > V_42 -> V_115 ||
0 == V_42 -> V_115 ) ) {
if ( V_42 -> V_82 & V_113 )
F_32 ( V_76
L_80
L_81 ,
( unsigned long long ) V_219 -> V_7 ,
V_219 -> V_5 -> V_43 ,
( unsigned long long ) V_219 -> V_6 ,
V_219 -> V_18 ,
( unsigned long long )
F_49 ( V_220 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
} else {
if ( V_42 -> V_82 & V_113 )
F_32 ( V_76
L_82
L_83 ,
( unsigned long long ) V_219 -> V_7 ,
V_219 -> V_5 -> V_43 ,
( unsigned long long ) V_219 -> V_6 ,
V_219 -> V_18 ,
( unsigned long long )
F_49 ( V_220 ) ,
( unsigned long long )
V_42 -> V_115 ) ;
V_42 -> V_115 =
F_49 ( V_220 ) ;
V_42 -> V_78 = V_219 ;
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
F_50 ( V_120 ) ;
V_116 = L_84 ;
V_81 = F_37 ( V_220 ) ;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_3 ,
( unsigned long long ) V_81 ) ;
break;
case 1 :
V_118 . V_11 =
F_50 ( V_121 ) ;
V_116 = L_85 ;
V_81 = F_38 ( V_220 ) ;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_4 ,
( unsigned long long ) V_81 ) ;
break;
case 2 :
V_118 . V_11 =
F_50 ( V_122 ) ;
V_116 = L_86 ;
V_81 = F_39 ( V_220 ) ;
if ( 0 == V_81 )
continue;
if ( V_42 -> V_82 &
V_83 )
F_32 ( V_76 L_5 ,
( unsigned long long ) V_81 ) ;
break;
}
V_80 =
F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_81 , V_87 ) ;
if ( V_42 -> V_82 & V_88 )
F_32 ( V_76 L_6 ,
( unsigned long long ) V_81 , V_80 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
int V_221 ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_87
L_34 , V_18 ) ;
V_67 = F_41 ( V_42 , V_81 , V_87 ,
& V_91 ,
V_18 ) ;
if ( V_67 ) {
F_32 ( V_76
L_36
L_37 ,
( unsigned long long ) V_81 ,
V_18 ) ;
return - 1 ;
}
V_89 = F_51 (
V_42 ,
& V_91 ,
V_116 ,
1 , 0 , 1 ,
V_18 ,
& V_221 ) ;
if ( NULL == V_89 ) {
F_32 ( V_76
L_1 ) ;
F_43 ( & V_91 ) ;
return - 1 ;
}
V_89 -> V_10 = V_118 ;
if ( V_221 )
V_89 -> V_8 =
V_9 ;
V_31 = F_52 (
V_42 ,
& V_91 ,
V_89 ,
V_219 ,
V_9 ) ;
F_43 ( & V_91 ) ;
if ( NULL == V_31 )
return - 1 ;
}
}
if ( - 1 == F_78 ( V_42 , V_219 , 0 ) ) {
F_70 ( 1 ) ;
F_74 ( V_42 ) ;
}
return 0 ;
}
static int F_78 ( struct V_64 * V_42 ,
struct V_1 * const V_135 ,
int V_222 )
{
struct V_54 * V_192 ;
int V_67 = 0 ;
if ( V_222 >= 3 + V_100 ) {
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_88 ) ;
return V_67 ;
}
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_192 , struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_89
L_90 ,
V_222 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_135 -> V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
if ( V_31 -> V_36 -> V_17 ) {
F_32 ( V_76 L_91
L_92
L_93 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( ! V_31 -> V_36 -> V_15 ) {
F_32 ( V_76 L_91
L_92
L_64 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_171 !=
V_31 -> V_36 -> V_8 &&
V_9 !=
V_31 -> V_171 &&
V_9 !=
V_31 -> V_36 -> V_8 ) {
F_32 ( V_76 L_91
L_92
L_94
L_95 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_31 -> V_36 -> V_8 ,
( unsigned long long ) V_31 -> V_171 ) ;
V_67 = - 1 ;
} else if ( V_31 -> V_36 -> V_28 >
V_31 -> V_36 -> V_5 -> V_44 ) {
F_32 ( V_76 L_91
L_92
L_96
L_97
L_98 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long )
V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ,
( unsigned long long ) V_135 -> V_28 ,
( unsigned long long )
V_31 -> V_36 -> V_5 -> V_44 ) ;
V_67 = - 1 ;
} else if ( - 1 == F_78 ( V_42 ,
V_31 -> V_36 ,
V_222 +
1 ) ) {
V_67 = - 1 ;
}
}
return V_67 ;
}
static int F_73 (
const struct V_64 * V_42 ,
const struct V_1 * V_135 ,
int V_222 )
{
struct V_54 * V_193 ;
if ( V_222 >= 3 + V_100 ) {
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_99 ) ;
return 0 ;
}
F_20 (elem_ref_from, &block->ref_from_list) {
const struct V_30 * const V_31 =
F_21 ( V_193 , struct V_30 ,
V_35 ) ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_89
L_100 ,
V_222 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_135 -> V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_37 ) ,
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
else if ( F_73 ( V_42 ,
V_31 -> V_37 ,
V_222 +
1 ) )
return 1 ;
}
return 0 ;
}
static void F_62 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_32 ( V_76
L_101
L_102 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long ) V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long ) V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static void F_76 ( const struct V_64 * V_42 ,
const struct V_30 * V_31 )
{
F_32 ( V_76
L_103
L_102 ,
V_31 -> V_33 ,
F_61 ( V_42 , V_31 -> V_37 ) ,
( unsigned long long ) V_31 -> V_37 -> V_7 ,
V_31 -> V_37 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_37 -> V_6 ,
V_31 -> V_37 -> V_18 ,
F_61 ( V_42 , V_31 -> V_36 ) ,
( unsigned long long ) V_31 -> V_36 -> V_7 ,
V_31 -> V_36 -> V_5 -> V_43 ,
( unsigned long long ) V_31 -> V_36 -> V_6 ,
V_31 -> V_36 -> V_18 ) ;
}
static char F_61 ( const struct V_64 * V_42 ,
const struct V_1 * V_135 )
{
if ( V_135 -> V_14 &&
V_42 -> V_78 -> V_6 == V_135 -> V_6 &&
V_42 -> V_78 -> V_5 -> V_41 == V_135 -> V_5 -> V_41 )
return 'S' ;
else if ( V_135 -> V_14 )
return 's' ;
else if ( V_135 -> V_13 )
return 'M' ;
else
return 'D' ;
}
static void F_74 ( const struct V_64 * V_42 )
{
F_53 ( V_42 , V_42 -> V_78 , 0 ) ;
}
static void F_53 ( const struct V_64 * V_42 ,
const struct V_1 * V_135 ,
int V_223 )
{
struct V_54 * V_192 ;
int V_224 ;
static char V_225 [ 80 ] ;
int V_226 ;
V_224 = sprintf ( V_225 , L_104 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_135 -> V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_135 -> V_18 ) ;
if ( V_223 + V_224 > V_227 ) {
F_32 ( L_105 ) ;
return;
}
F_32 ( V_225 ) ;
V_223 += V_224 ;
if ( F_72 ( & V_135 -> V_25 ) ) {
F_32 ( L_53 ) ;
return;
}
if ( V_135 -> V_18 > 1 &&
! ( V_42 -> V_82 & V_228 ) ) {
F_32 ( L_106 ) ;
return;
}
V_226 = V_223 ;
F_20 (elem_ref_to, &block->ref_to_list) {
const struct V_30 * const V_31 =
F_21 ( V_192 , struct V_30 ,
V_34 ) ;
while ( V_226 < V_223 ) {
F_32 ( L_107 ) ;
V_226 ++ ;
}
if ( V_31 -> V_33 > 1 )
V_224 = sprintf ( V_225 , L_108 , V_31 -> V_33 ) ;
else
V_224 = sprintf ( V_225 , L_109 ) ;
if ( V_223 + V_224 >
V_227 ) {
F_32 ( L_105 ) ;
V_226 = 0 ;
continue;
}
F_32 ( V_225 ) ;
F_53 ( V_42 , V_31 -> V_36 ,
V_223 + V_224 ) ;
V_226 = 0 ;
}
}
static struct V_30 * F_52 (
struct V_64 * V_42 ,
struct V_90 * V_156 ,
struct V_1 * V_89 ,
struct V_1 * V_229 ,
T_1 V_171 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( V_156 -> V_94 -> V_41 ,
V_156 -> V_6 ,
V_229 -> V_5 -> V_41 ,
V_229 -> V_6 ,
& V_42 -> V_96 ) ;
if ( NULL == V_31 ) {
V_31 = F_9 () ;
if ( NULL == V_31 ) {
F_32 ( V_76
L_110 L_66 ) ;
return NULL ;
}
V_31 -> V_36 = V_89 ;
V_31 -> V_37 = V_229 ;
V_31 -> V_33 = 1 ;
V_31 -> V_171 = V_171 ;
if ( V_42 -> V_82 & V_145 )
F_62 ( V_42 , V_31 ) ;
F_16 ( & V_31 -> V_34 , & V_229 -> V_25 ) ;
F_16 ( & V_31 -> V_35 , & V_89 -> V_26 ) ;
F_23 ( V_31 ,
& V_42 -> V_96 ) ;
} else {
V_31 -> V_33 ++ ;
V_31 -> V_171 = V_171 ;
if ( V_42 -> V_82 & V_145 )
F_62 ( V_42 , V_31 ) ;
}
return V_31 ;
}
static struct V_1 * F_51 (
struct V_64 * V_42 ,
struct V_90 * V_136 ,
const char * V_116 ,
int V_13 ,
int V_15 ,
int V_17 ,
int V_18 ,
int * V_221 )
{
struct V_1 * V_135 ;
V_135 = F_19 ( V_136 -> V_94 -> V_41 ,
V_136 -> V_6 ,
& V_42 -> V_95 ) ;
if ( NULL == V_135 ) {
struct V_38 * V_5 ;
V_135 = F_3 () ;
if ( NULL == V_135 ) {
F_32 ( V_76 L_1 ) ;
return NULL ;
}
V_5 = F_34 ( V_136 -> V_94 -> V_41 ) ;
if ( NULL == V_5 ) {
F_32 ( V_76
L_111 ) ;
F_5 ( V_135 ) ;
return NULL ;
}
V_135 -> V_5 = V_5 ;
V_135 -> V_6 = V_136 -> V_6 ;
V_135 -> V_7 = V_136 -> V_98 ;
V_135 -> V_13 = V_13 ;
V_135 -> V_15 = V_15 ;
V_135 -> V_17 = V_17 ;
V_135 -> V_18 = V_18 ;
if ( V_42 -> V_82 & V_145 )
F_32 ( V_76
L_112 ,
V_116 ,
F_61 ( V_42 , V_135 ) ,
( unsigned long long ) V_135 -> V_7 ,
V_5 -> V_43 ,
( unsigned long long ) V_135 -> V_6 ,
V_18 ) ;
F_16 ( & V_135 -> V_24 , & V_42 -> V_114 ) ;
F_15 ( V_135 , & V_42 -> V_95 ) ;
if ( NULL != V_221 )
* V_221 = 1 ;
} else {
if ( NULL != V_221 )
* V_221 = 0 ;
}
return V_135 ;
}
static void F_71 ( struct V_64 * V_42 ,
T_1 V_155 ,
struct V_38 * V_5 ,
T_1 V_6 , char * V_99 )
{
int V_80 ;
int V_18 ;
int V_67 ;
struct V_90 V_136 ;
int V_230 = 0 ;
V_80 = F_40 ( & V_42 -> V_84 -> V_85 -> V_86 ,
V_155 , V_87 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_41 ( V_42 , V_155 , V_87 ,
& V_136 , V_18 ) ;
if ( V_67 ) {
F_32 ( V_76 L_7
L_113
L_9 ,
( unsigned long long ) V_155 , V_18 ) ;
continue;
}
if ( V_5 -> V_41 == V_136 . V_94 -> V_41 &&
V_6 == V_136 . V_6 ) {
V_230 ++ ;
F_43 ( & V_136 ) ;
break;
}
F_43 ( & V_136 ) ;
}
if ( ! V_230 ) {
F_32 ( V_76 L_114
L_115
L_116 ,
( unsigned long long ) V_155 , V_5 -> V_43 ,
( unsigned long long ) V_6 ) ;
for ( V_18 = 1 ; V_18 <= V_80 ; V_18 ++ ) {
V_67 = F_41 ( V_42 , V_155 , V_87 ,
& V_136 , V_18 ) ;
if ( V_67 )
continue;
F_32 ( V_76 L_117
L_118 ,
( unsigned long long ) V_155 ,
V_136 . V_94 -> V_43 ,
( unsigned long long ) V_136 . V_6 ,
V_18 ) ;
}
F_70 ( 1 ) ;
}
}
static struct V_38 * F_34 (
struct V_53 * V_41 )
{
struct V_38 * V_39 ;
V_39 = F_29 ( V_41 ,
& V_62 ) ;
return V_39 ;
}
int F_79 ( int V_231 , struct V_103 * V_104 )
{
struct V_38 * V_5 ;
if ( ! V_232 )
return F_80 ( V_231 , V_104 ) ;
F_81 ( & V_233 ) ;
V_5 = F_34 ( V_104 -> V_234 ) ;
if ( NULL != V_5 &&
( V_231 & V_235 ) && V_104 -> V_236 > 0 ) {
T_1 V_6 ;
V_6 = 4096 * V_104 -> V_237 ;
if ( V_5 -> V_42 -> V_82 &
V_238 )
F_32 ( V_76
L_119
L_120 ,
V_231 , ( unsigned long ) V_104 -> V_237 ,
( unsigned long long ) V_6 ,
( unsigned long ) V_104 -> V_236 , V_104 -> V_107 ,
V_104 -> V_234 ) ;
F_69 ( V_5 , V_6 ,
V_104 -> V_107 , V_104 -> V_236 , NULL ,
NULL , V_104 , V_231 ) ;
} else if ( NULL != V_5 && ( V_231 & V_216 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_238 )
F_32 ( V_76
L_121 ,
V_231 , V_104 -> V_234 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_238 |
V_145 ) ) )
F_32 ( V_76
L_122
L_123
L_124 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_135 =
& V_5 -> V_45 ;
V_135 -> V_15 = 0 ;
V_135 -> V_17 = 0 ;
V_135 -> V_16 = 0 ;
V_135 -> V_28 = V_5 -> V_44 + 1 ;
V_135 -> V_27 = V_231 ;
V_135 -> V_20 = V_104 -> V_209 ;
V_135 -> V_21 . V_104 = V_104 -> V_210 ;
V_135 -> V_19 = NULL ;
V_104 -> V_209 = V_135 ;
V_104 -> V_210 = V_211 ;
}
}
F_82 ( & V_233 ) ;
return F_80 ( V_231 , V_104 ) ;
}
void F_83 ( int V_231 , struct V_22 * V_22 )
{
struct V_38 * V_5 ;
if ( ! V_232 ) {
F_84 ( V_231 , V_22 ) ;
return;
}
F_81 ( & V_233 ) ;
V_5 = F_34 ( V_22 -> V_239 ) ;
if ( NULL != V_5 &&
( V_231 & V_235 ) && NULL != V_22 -> V_240 ) {
unsigned int V_48 ;
T_1 V_6 ;
int V_202 ;
V_6 = 512 * V_22 -> V_241 ;
V_202 = 0 ;
if ( V_5 -> V_42 -> V_82 &
V_238 )
F_32 ( V_76
L_125
L_126 ,
V_231 , V_22 -> V_242 , ( unsigned long ) V_22 -> V_241 ,
( unsigned long long ) V_6 ,
V_22 -> V_239 ) ;
for ( V_48 = 0 ; V_48 < V_22 -> V_242 ; V_48 ++ ) {
T_2 * V_201 ;
V_201 = F_85 ( V_22 -> V_240 [ V_48 ] . V_243 ) ;
if ( ( V_238 |
V_145 ) ==
( V_5 -> V_42 -> V_82 &
( V_238 |
V_145 ) ) )
F_32 ( V_76
L_127
L_128 ,
V_48 , V_22 -> V_240 [ V_48 ] . V_243 ,
V_201 ,
V_22 -> V_240 [ V_48 ] . V_244 ,
V_22 -> V_240 [ V_48 ] . V_245 ) ;
F_69 ( V_5 , V_6 ,
V_201 ,
V_22 -> V_240 [ V_48 ] . V_244 ,
V_22 , & V_202 ,
NULL , V_231 ) ;
F_86 ( V_22 -> V_240 [ V_48 ] . V_243 ) ;
V_6 += V_22 -> V_240 [ V_48 ] . V_244 ;
}
} else if ( NULL != V_5 && ( V_231 & V_216 ) ) {
if ( V_5 -> V_42 -> V_82 &
V_238 )
F_32 ( V_76
L_129 ,
V_231 , V_22 -> V_239 ) ;
if ( ! V_5 -> V_45 . V_15 ) {
if ( ( V_5 -> V_42 -> V_82 &
( V_238 |
V_145 ) ) )
F_32 ( V_76
L_130
L_123
L_124 ,
V_5 -> V_43 ) ;
} else {
struct V_1 * const V_135 =
& V_5 -> V_45 ;
V_135 -> V_15 = 0 ;
V_135 -> V_17 = 0 ;
V_135 -> V_16 = 0 ;
V_135 -> V_28 = V_5 -> V_44 + 1 ;
V_135 -> V_27 = V_231 ;
V_135 -> V_20 = V_22 -> V_205 ;
V_135 -> V_21 . V_22 = V_22 -> V_206 ;
V_135 -> V_19 = NULL ;
V_22 -> V_205 = V_135 ;
V_22 -> V_206 = V_207 ;
}
}
F_82 ( & V_233 ) ;
F_84 ( V_231 , V_22 ) ;
}
int F_87 ( struct V_246 * V_84 ,
struct V_65 * V_66 ,
int V_247 , T_3 V_82 )
{
int V_67 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
V_42 = F_4 ( sizeof( * V_42 ) , V_29 ) ;
if ( NULL == V_42 ) {
F_32 ( V_76 L_131 ) ;
return - 1 ;
}
if ( ! V_232 ) {
F_88 ( & V_233 ) ;
F_26 ( & V_62 ) ;
V_232 = 1 ;
}
F_81 ( & V_233 ) ;
V_42 -> V_84 = V_84 ;
V_42 -> V_82 = V_82 ;
V_42 -> V_160 = V_247 ;
V_42 -> V_79 = 0 ;
F_2 ( & V_42 -> V_114 ) ;
F_14 ( & V_42 -> V_95 ) ;
F_22 ( & V_42 -> V_96 ) ;
V_42 -> V_115 = 0 ;
V_42 -> V_78 = NULL ;
F_33 (device, dev_head, dev_list) {
struct V_38 * V_39 ;
char * V_248 ;
if ( ! V_73 -> V_41 || ! V_73 -> V_43 )
continue;
V_39 = F_12 () ;
if ( NULL == V_39 ) {
F_32 ( V_76
L_131 ) ;
F_82 ( & V_233 ) ;
return - 1 ;
}
V_39 -> V_41 = V_73 -> V_41 ;
V_39 -> V_42 = V_42 ;
F_89 ( V_39 -> V_41 , V_39 -> V_43 ) ;
V_39 -> V_43 [ V_249 - 1 ] = '\0' ;
for ( V_248 = V_39 -> V_43 ; * V_248 != '\0' ; V_248 ++ ) ;
while ( V_248 > V_39 -> V_43 && * V_248 != '/' )
V_248 -- ;
if ( * V_248 == '/' )
V_248 ++ ;
F_90 ( V_39 -> V_43 , V_248 , sizeof( V_39 -> V_43 ) ) ;
F_27 ( V_39 ,
& V_62 ) ;
}
V_67 = F_30 ( V_42 , V_66 ) ;
if ( 0 != V_67 ) {
F_82 ( & V_233 ) ;
F_91 ( V_84 , V_66 ) ;
return V_67 ;
}
if ( V_42 -> V_82 & V_250 )
F_65 ( V_42 ) ;
if ( V_42 -> V_82 & V_251 )
F_74 ( V_42 ) ;
F_82 ( & V_233 ) ;
return 0 ;
}
void F_91 ( struct V_246 * V_84 ,
struct V_65 * V_66 )
{
struct V_54 * V_190 ;
struct V_54 * V_252 ;
struct V_64 * V_42 ;
struct V_54 * V_70 = & V_66 -> V_71 ;
struct V_72 * V_73 ;
if ( ! V_232 )
return;
F_81 ( & V_233 ) ;
V_42 = NULL ;
F_33 (device, dev_head, dev_list) {
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
F_32 ( V_76
L_132
L_133 ) ;
F_82 ( & V_233 ) ;
return;
}
F_75 (elem_all, tmp_all, &state->all_blocks_list) {
struct V_1 * const V_191 =
F_21 ( V_190 , struct V_1 ,
V_24 ) ;
struct V_54 * V_192 ;
struct V_54 * V_203 ;
F_75 (elem_ref_to, tmp_ref_to,
&b_all->ref_to_list) {
struct V_30 * const V_31 =
F_21 ( V_192 ,
struct V_30 ,
V_34 ) ;
if ( V_42 -> V_82 & V_145 )
F_76 ( V_42 , V_31 ) ;
V_31 -> V_33 -- ;
if ( 0 == V_31 -> V_33 )
F_10 ( V_31 ) ;
}
if ( V_191 -> V_15 )
F_5 ( V_191 ) ;
else
F_32 ( V_76 L_134
L_135
L_136 ,
F_61 ( V_42 , V_191 ) ,
( unsigned long long ) V_191 -> V_7 ,
V_191 -> V_5 -> V_43 ,
( unsigned long long ) V_191 -> V_6 ,
V_191 -> V_18 ) ;
}
F_82 ( & V_233 ) ;
F_7 ( V_42 ) ;
}
