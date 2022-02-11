static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
T_2 V_7 = V_5 -> V_8 ;
T_1 V_9 = V_5 -> V_10 ;
int V_11 ;
V_2 -> V_12 = 0 ;
F_2 ( F_3 ( V_2 ) ,
F_4 ( V_13 ) ,
V_14 ) ;
F_2 ( F_3 ( V_2 ) ,
F_5 ( V_13 ) , V_6 ) ;
F_2 ( F_3 ( V_2 ) ,
F_6 ( V_13 ) ,
V_7 & V_15 ) ;
F_2 ( F_3 ( V_2 ) ,
F_7 ( V_13 ) ,
( F_8 ( V_7 )
<< V_16 ) | V_9 ) ;
F_2 ( F_3 ( V_2 ) ,
F_9 ( V_13 ) ,
1 << V_17 |
1 << V_18 |
V_19 ) ;
F_2 ( F_3 ( V_2 ) ,
F_4 ( V_13 ) ,
V_20 |
V_21 |
V_22 ) ;
F_10 ( V_2 , L_1 , V_3 ) ;
V_11 = F_11 ( V_2 -> V_23 -> V_24 ,
V_2 -> V_12 , 5 * V_25 ) ;
if ( ! V_11 ) {
F_12 ( V_2 , L_2 ,
V_3 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_27 * V_5 )
{
int V_11 = 0 ;
V_11 = F_1 ( V_2 , L_3 , & V_5 -> V_28 ,
V_29 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , L_4 , & V_5 -> V_30 ,
V_31 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
T_3 * V_34 =
( T_3 * ) F_15 ( V_2 , V_35 ) ;
F_16 ( & V_33 . V_36 , V_37 ) ;
V_33 . V_38 = F_17 ( V_34 [ 0 ] ) ;
V_33 . V_39 = F_17 ( V_34 [ 1 ] ) ;
return F_18 ( & V_2 -> V_40 [ V_41 ] ,
( V_42 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_43 V_33 ;
T_3 * V_44 =
( T_3 * ) F_15 ( V_2 , V_45 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_16 ( & V_33 . V_36 , V_46 ) ;
memcpy ( & V_33 . V_47 , V_44 , sizeof( * V_44 ) ) ;
if ( ! ( V_33 . V_47 ) )
V_33 . V_47 = V_48 ;
F_20 ( V_2 , L_5 ,
F_17 ( V_33 . V_47 ) ) ;
return F_18 ( & V_2 -> V_40 [ V_49 ] ,
( V_42 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_50 V_33 ;
T_3 * V_51 = ( T_3 * ) F_15 ( V_2 ,
V_52 ) ;
T_3 * V_53 =
( T_3 * ) F_15 ( V_2 , V_45 ) ;
struct V_54 * V_36 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_16 ( & V_33 . V_36 , V_46 ) ;
V_36 = (struct V_54 * ) F_15 ( V_2 ,
V_55 ) ;
memcpy ( & V_33 . V_56 , V_51 ,
sizeof( * V_51 ) ) ;
memcpy ( & V_33 . V_57 , V_53 ,
sizeof( * V_53 ) ) ;
if ( ! ( V_33 . V_57 ) ) {
F_20 ( V_2 , L_6 ) ;
V_33 . V_57 = V_48 ;
V_33 . V_56 = V_48 ;
}
memcpy ( & V_33 . V_58 , & V_36 -> V_59 ,
sizeof( V_36 -> V_59 ) ) ;
F_20 ( V_2 , L_7 ,
F_17 ( V_33 . V_56 ) ) ;
F_20 ( V_2 , L_8 ,
F_17 ( V_33 . V_57 ) ) ;
F_20 ( V_2 , L_9 ,
F_17 ( V_33 . V_58 ) ) ;
return F_18 ( & V_2 -> V_40 [ V_49 ] ,
( V_42 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_60 V_61 ;
struct V_62 V_33 = {
. V_63 = V_64 ,
. V_10 = { sizeof( struct V_60 ) , } ,
. V_30 = { & V_61 , } ,
} ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_65 . V_66 . V_67 = V_68 ;
V_61 . V_65 . V_66 . V_69 = V_68 ;
V_61 . V_65 . V_66 . V_70 = V_68 ;
V_61 . V_65 . V_71 =
V_72 ;
return F_23 ( F_24 ( V_2 ) , & V_33 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
struct V_75 * V_33 )
{
struct V_76 * V_77 = F_26 ( V_74 ) ;
struct V_78 * V_36 = (struct V_78 * ) V_77 -> V_79 . V_80 ;
int V_10 = F_27 ( V_77 -> V_81 ) & V_82 ;
int V_83 ;
V_10 -= 4 ;
switch ( V_36 -> V_84 ) {
case V_85 :
V_83 = V_86 ;
break;
case V_87 :
V_83 = V_88 ;
break;
case V_89 :
V_83 = V_90 ;
break;
case V_91 :
V_83 = V_92 ;
break;
case V_93 :
V_83 = V_94 ;
break;
default:
F_12 ( V_2 , L_10 ,
V_36 -> V_84 ) ;
return - 1 ;
}
F_18 ( & V_2 -> V_40 [ V_83 ] , V_77 -> V_79 . V_80 , V_10 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_95 -> V_96 &&
V_2 -> V_95 -> V_96 -> V_97 ) {
V_11 = F_29 ( V_2 , V_98 ,
V_99 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_22 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( V_2 -> V_95 -> V_100 ) {
if ( V_2 -> V_95 -> V_101 )
return F_21 ( V_2 ) ;
else
return F_19 ( V_2 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
if ( V_2 -> V_95 -> V_104 -> V_105 ) {
V_103 . V_71 = V_106 ;
V_103 . V_71 |= V_107 ;
memcpy ( V_103 . V_108 , V_109 ,
sizeof( struct V_110 ) *
V_111 ) ;
V_103 . V_71 |= V_112 ;
V_103 . V_71 |= V_113 ;
} else {
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
}
return F_31 ( F_24 ( V_2 ) ,
V_114 , V_115 ,
sizeof( V_103 ) , & V_103 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_116 V_117 ;
memcpy ( V_117 . V_118 , V_119 ,
sizeof( V_119 ) ) ;
if ( F_31 ( F_24 ( V_2 ) ,
V_120 , V_115 ,
sizeof( V_117 ) , & V_117 ) )
F_12 ( V_2 , L_11 ) ;
}
int F_29 ( struct V_1 * V_2 , V_42 V_121 , V_42 type )
{
struct V_122 V_123 ;
int V_11 ;
V_123 . V_121 = V_121 ;
V_123 . type = type ;
V_11 = F_31 ( F_24 ( V_2 ) ,
V_124 , V_115 ,
sizeof( V_123 ) , & V_123 ) ;
if ( V_11 )
F_12 ( V_2 , L_12 ) ;
return V_11 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
int V_11 ;
if ( ! V_2 -> V_127 )
V_2 -> V_127 =
F_34 ( L_13 ,
sizeof( struct V_75 ) ,
sizeof( void * ) , 0 , NULL ) ;
if ( ! V_2 -> V_127 )
return - V_128 ;
F_35 ( F_24 ( V_2 ) ) ;
F_36 (priv, ctx)
V_126 -> V_129 = false ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_14 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_37 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_130 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_131 ;
T_1 V_132 ;
F_10 ( V_2 , L_14 , V_10 ) ;
for ( V_132 = 0 ; V_132 < V_10 ; V_132 += 100 , V_5 += 100 / sizeof( T_1 ) ) {
F_2 ( F_3 ( V_2 ) , V_133 ,
V_132 + V_29 ) ;
V_131 = F_39 ( F_3 ( V_2 ) , V_134 ) ;
if ( V_131 != F_27 ( * V_5 ) )
return - V_135 ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_130 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_131 ;
T_1 V_136 ;
int V_137 = 0 ;
F_10 ( V_2 , L_14 , V_10 ) ;
F_2 ( F_3 ( V_2 ) , V_133 ,
V_29 ) ;
for ( V_136 = 0 ;
V_136 < V_10 && V_137 < 20 ;
V_136 += sizeof( T_1 ) , V_5 ++ ) {
V_131 = F_39 ( F_3 ( V_2 ) , V_134 ) ;
if ( V_131 != F_27 ( * V_5 ) ) {
F_12 ( V_2 , L_15
L_16 ,
V_136 , V_131 , F_27 ( * V_5 ) ) ;
V_137 ++ ;
}
}
}
static int F_41 ( struct V_1 * V_2 , struct V_27 * V_138 )
{
if ( ! F_38 ( V_2 , & V_138 -> V_28 ) ) {
F_10 ( V_2 , L_17 ) ;
return 0 ;
}
F_12 ( V_2 , L_18 ) ;
F_40 ( V_2 , & V_138 -> V_28 ) ;
return - V_135 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
void * V_30 )
{
struct V_139 * V_140 = V_30 ;
struct V_141 * V_142 ;
V_142 = & V_77 -> V_79 . V_143 ;
F_10 ( V_2 , L_19
L_20 ,
V_142 -> V_144 , V_142 -> V_145 ,
V_142 -> V_146 ) ;
V_2 -> V_147 . V_148 =
F_27 ( V_142 -> V_149 ) ;
V_2 -> V_147 . V_150 =
F_27 ( V_142 -> V_151 ) ;
V_140 -> V_152 = V_142 -> V_146 ;
V_140 -> V_153 = V_142 -> V_144 == V_154 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_27 * V_5 ,
enum V_155 V_156 )
{
struct V_157 V_158 ;
struct V_139 V_140 ;
int V_11 ;
enum V_155 V_159 ;
V_11 = F_44 ( F_24 ( V_2 ) ) ;
if ( V_11 )
return V_11 ;
F_45 ( V_2 , & V_158 , V_160 ,
F_42 , & V_140 ) ;
V_159 = V_2 -> V_156 ;
V_2 -> V_156 = V_156 ;
V_11 = F_13 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_156 = V_159 ;
F_46 ( V_2 , & V_158 ) ;
return V_11 ;
}
F_47 ( F_24 ( V_2 ) ) ;
V_11 = F_48 ( V_2 , & V_158 , V_161 ) ;
if ( V_11 ) {
V_2 -> V_156 = V_159 ;
return V_11 ;
}
if ( ! V_140 . V_153 ) {
F_12 ( V_2 , L_21 ) ;
V_2 -> V_156 = V_159 ;
return - V_135 ;
}
if ( V_156 != V_162 ) {
V_11 = F_41 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_156 = V_159 ;
return V_11 ;
}
F_49 ( 5 ) ;
}
V_11 = F_33 ( V_2 ) ;
if ( V_11 ) {
F_50 ( V_2 ,
L_22 , V_11 ) ;
V_2 -> V_156 = V_159 ;
return V_11 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_157 V_163 ;
int V_11 ;
F_52 ( & V_2 -> V_23 -> V_164 ) ;
if ( ! V_2 -> V_165 . V_28 . V_10 )
return 0 ;
if ( V_2 -> V_156 != V_166 )
return 0 ;
F_45 ( V_2 , & V_163 ,
V_167 ,
NULL , NULL ) ;
V_11 = F_43 ( V_2 , & V_2 -> V_165 ,
V_168 ) ;
if ( V_11 )
goto error;
V_11 = F_28 ( V_2 ) ;
if ( V_11 )
goto error;
V_11 = F_48 ( V_2 , & V_163 , V_169 ) ;
goto V_170;
error:
F_46 ( V_2 , & V_163 ) ;
V_170:
F_53 ( F_24 ( V_2 ) ) ;
return V_11 ;
}
