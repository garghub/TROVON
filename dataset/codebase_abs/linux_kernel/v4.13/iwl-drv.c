static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ )
F_1 ( V_2 , & V_8 -> V_11 [ V_9 ] ) ;
F_4 ( V_8 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_9 ;
F_4 ( V_2 -> V_12 . V_13 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ )
F_4 ( V_2 -> V_12 . V_14 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ )
F_4 ( V_2 -> V_12 . V_15 [ V_9 ] ) ;
F_4 ( V_2 -> V_12 . V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
F_3 ( V_2 , V_2 -> V_12 . V_8 + V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_18 * V_11 )
{
void * V_5 ;
V_4 -> V_5 = NULL ;
if ( ! V_11 || ! V_11 -> V_19 )
return - V_20 ;
V_5 = F_8 ( V_11 -> V_19 ) ;
if ( ! V_5 )
return - V_21 ;
V_4 -> V_6 = V_11 -> V_19 ;
V_4 -> V_22 = V_11 -> V_22 ;
memcpy ( V_5 , V_11 -> V_5 , V_4 -> V_6 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_23 )
{
const struct V_24 * V_25 = V_2 -> V_26 -> V_25 ;
char V_27 [ 8 ] ;
const char * V_28 ;
if ( V_2 -> V_26 -> V_25 -> V_29 == V_30 &&
( F_10 ( V_2 -> V_26 -> V_31 ) == V_32 ||
F_10 ( V_2 -> V_26 -> V_31 ) == V_33 ) )
V_28 = V_25 -> V_34 ;
else if ( V_2 -> V_26 -> V_25 -> V_35 &&
F_11 ( V_2 -> V_26 -> V_36 ) == V_32 &&
V_25 -> V_37 )
V_28 = V_25 -> V_37 ;
else
V_28 = V_25 -> V_38 ;
if ( V_23 ) {
V_2 -> V_39 = V_25 -> V_40 ;
sprintf ( V_27 , L_1 , V_2 -> V_39 ) ;
} else {
V_2 -> V_39 -- ;
sprintf ( V_27 , L_1 , V_2 -> V_39 ) ;
}
if ( V_2 -> V_39 < V_25 -> V_41 ) {
F_12 ( V_2 , L_2 ) ;
if ( V_25 -> V_41 == V_25 -> V_40 ) {
F_12 ( V_2 , L_3 , V_28 ,
V_25 -> V_40 ) ;
} else {
F_12 ( V_2 , L_4 ,
V_28 ,
V_25 -> V_41 ) ;
F_12 ( V_2 , L_5 ,
V_28 ,
V_25 -> V_40 ) ;
}
F_12 ( V_2 ,
L_6 ) ;
return - V_42 ;
}
snprintf ( V_2 -> V_43 , sizeof( V_2 -> V_43 ) , L_7 ,
V_28 , V_27 ) ;
F_13 ( V_2 , L_8 ,
V_2 -> V_43 ) ;
return F_14 ( V_44 , 1 , V_2 -> V_43 ,
V_2 -> V_26 -> V_45 ,
V_46 , V_2 , V_47 ) ;
}
static struct V_18 * F_15 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 )
{
return & V_49 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_16 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 )
{
struct V_51 * V_8 = & V_49 -> V_8 [ type ] ;
struct V_18 * V_52 ;
int V_19 = V_11 + 1 ;
T_1 V_53 = sizeof( * V_8 -> V_11 ) * V_19 ;
if ( V_8 -> V_11 && V_8 -> V_54 >= V_19 )
return;
V_52 = F_17 ( V_8 -> V_11 , V_53 , V_46 ) ;
if ( ! V_52 )
return;
V_8 -> V_11 = V_52 ;
V_8 -> V_54 = V_19 ;
}
static void F_18 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 ,
const void * V_5 )
{
F_16 ( V_49 , type , V_11 ) ;
V_49 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_19 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 ,
T_1 V_19 )
{
F_16 ( V_49 , type , V_11 ) ;
V_49 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 = V_19 ;
}
static T_1 F_20 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 )
{
return V_49 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 ;
}
static void F_21 ( struct V_48 * V_49 ,
enum V_50 type ,
int V_11 ,
T_2 V_22 )
{
F_16 ( V_49 , type , V_11 ) ;
V_49 -> V_8 [ type ] . V_11 [ V_11 ] . V_22 = V_22 ;
}
static int F_22 ( struct V_55 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_56 ;
struct V_57 * V_58 = (struct V_57 * ) V_5 ;
struct V_59 * V_60 ;
if ( V_6 < sizeof( * V_58 ) ||
V_6 < sizeof( V_58 -> V_19 ) + V_58 -> V_19 * sizeof( V_58 -> V_61 [ 0 ] ) )
return - V_20 ;
for ( V_9 = 0 , V_56 = 0 ; V_9 < V_62 && V_9 < V_58 -> V_19 ; V_9 ++ ) {
V_60 = & V_58 -> V_61 [ V_56 ] ;
if ( ! V_60 -> V_63 )
continue;
V_12 -> V_61 [ V_56 ++ ] = * V_60 ;
}
return 0 ;
}
static void F_23 ( struct V_55 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_64 * V_65 = ( void * ) V_5 ;
struct V_66 * V_67 = & V_12 -> V_68 ;
V_67 -> V_69 = F_24 ( V_65 -> V_69 ) ;
V_67 -> V_70 = F_24 ( V_65 -> V_70 ) ;
V_67 -> V_71 =
F_24 ( V_65 -> V_71 ) ;
V_67 -> V_72 = F_24 ( V_65 -> V_72 ) ;
V_67 -> V_73 =
F_24 ( V_65 -> V_73 ) ;
V_67 -> V_74 = F_24 ( V_65 -> V_74 ) ;
V_67 -> V_75 =
F_24 ( V_65 -> V_75 ) ;
V_67 -> V_76 =
F_24 ( V_65 -> V_76 ) ;
V_67 -> V_77 = F_24 ( V_65 -> V_77 ) ;
V_67 -> V_78 =
F_24 ( V_65 -> V_78 ) ;
V_67 -> V_79 =
F_24 ( V_65 -> V_79 ) ;
V_67 -> V_80 =
F_24 ( V_65 -> V_80 ) ;
V_67 -> V_81 =
F_24 ( V_65 -> V_81 ) ;
}
static int F_25 ( struct V_48 * V_49 ,
const void * V_5 , enum V_50 type ,
int V_19 )
{
struct V_51 * V_8 ;
struct V_18 * V_11 ;
struct V_82 * V_83 ;
T_1 V_53 ;
if ( F_26 ( ! V_49 || ! V_5 || type >= V_17 ) )
return - 1 ;
V_83 = (struct V_82 * ) V_5 ;
V_8 = & V_49 -> V_8 [ type ] ;
V_53 = sizeof( * V_8 -> V_11 ) * ( V_8 -> V_54 + 1 ) ;
V_11 = F_17 ( V_8 -> V_11 , V_53 , V_46 ) ;
if ( ! V_11 )
return - V_21 ;
V_8 -> V_11 = V_11 ;
V_11 = & V_8 -> V_11 [ V_8 -> V_54 ] ;
V_11 -> V_22 = F_24 ( V_83 -> V_22 ) ;
V_11 -> V_5 = V_83 -> V_5 ;
V_11 -> V_19 = V_19 - sizeof( V_83 -> V_22 ) ;
++ V_8 -> V_54 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_5 ;
T_2 V_86 = F_24 ( V_85 -> V_86 ) ;
if ( V_86 >= V_17 ) {
F_12 ( V_2 , L_9 ,
V_86 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_87 [ V_86 ] . V_88 =
V_85 -> V_89 . V_88 ;
V_2 -> V_12 . V_87 [ V_86 ] . V_90 =
V_85 -> V_89 . V_90 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_91 * V_67 )
{
const struct V_92 * V_93 = ( void * ) V_5 ;
T_2 V_94 = F_24 ( V_93 -> V_94 ) ;
T_2 V_95 = F_24 ( V_93 -> V_95 ) ;
int V_9 ;
if ( V_94 >= F_29 ( V_96 , 32 ) ) {
F_12 ( V_2 ,
L_10 ,
V_94 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_95 & F_30 ( V_9 ) )
F_31 ( V_9 + 32 * V_94 , V_67 -> V_97 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_91 * V_67 )
{
const struct V_98 * V_99 = ( void * ) V_5 ;
T_2 V_94 = F_24 ( V_99 -> V_94 ) ;
T_2 V_95 = F_24 ( V_99 -> V_100 ) ;
int V_9 ;
if ( V_94 >= F_29 ( V_101 , 32 ) ) {
F_12 ( V_2 ,
L_11 ,
V_94 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_95 & F_30 ( V_9 ) )
F_31 ( V_9 + 32 * V_94 , V_67 -> V_102 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_103 * V_104 ,
struct V_48 * V_49 )
{
struct V_105 * V_106 = ( void * ) V_104 -> V_5 ;
T_2 V_107 , V_108 , V_109 ;
char V_110 [ 25 ] ;
const T_3 * V_111 ;
V_2 -> V_12 . V_112 = F_24 ( V_106 -> V_113 ) ;
V_107 = F_34 ( V_2 -> V_12 . V_112 ) ;
switch ( V_107 ) {
default:
V_108 = 28 ;
if ( V_104 -> V_19 < V_108 ) {
F_12 ( V_2 , L_12 ) ;
return - V_20 ;
}
V_109 = F_24 ( V_106 -> V_114 . V_115 . V_109 ) ;
F_19 ( V_49 , V_116 , V_117 ,
F_24 ( V_106 -> V_114 . V_115 . V_118 ) ) ;
F_19 ( V_49 , V_116 , V_119 ,
F_24 ( V_106 -> V_114 . V_115 . V_120 ) ) ;
F_19 ( V_49 , V_121 , V_117 ,
F_24 ( V_106 -> V_114 . V_115 . V_122 ) ) ;
F_19 ( V_49 , V_121 , V_119 ,
F_24 ( V_106 -> V_114 . V_115 . V_123 ) ) ;
V_111 = V_106 -> V_114 . V_115 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_108 = 24 ;
if ( V_104 -> V_19 < V_108 ) {
F_12 ( V_2 , L_12 ) ;
return - V_20 ;
}
V_109 = 0 ;
F_19 ( V_49 , V_116 , V_117 ,
F_24 ( V_106 -> V_114 . V_124 . V_118 ) ) ;
F_19 ( V_49 , V_116 , V_119 ,
F_24 ( V_106 -> V_114 . V_124 . V_120 ) ) ;
F_19 ( V_49 , V_121 , V_117 ,
F_24 ( V_106 -> V_114 . V_124 . V_122 ) ) ;
F_19 ( V_49 , V_121 , V_119 ,
F_24 ( V_106 -> V_114 . V_124 . V_123 ) ) ;
V_111 = V_106 -> V_114 . V_124 . V_5 ;
break;
}
if ( V_109 )
sprintf ( V_110 , L_13 , V_109 ) ;
else
V_110 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_125 ,
sizeof( V_2 -> V_12 . V_125 ) ,
L_14 ,
F_35 ( V_2 -> V_12 . V_112 ) ,
F_36 ( V_2 -> V_12 . V_112 ) ,
F_34 ( V_2 -> V_12 . V_112 ) ,
F_37 ( V_2 -> V_12 . V_112 ) ,
V_110 ) ;
if ( V_104 -> V_19 != V_108 +
F_20 ( V_49 , V_116 , V_117 ) +
F_20 ( V_49 , V_116 , V_119 ) +
F_20 ( V_49 , V_121 , V_117 ) +
F_20 ( V_49 , V_121 , V_119 ) ) {
F_12 ( V_2 ,
L_15 ,
( int ) V_104 -> V_19 ) ;
return - V_20 ;
}
F_18 ( V_49 , V_116 , V_117 , V_111 ) ;
V_111 += F_20 ( V_49 , V_116 , V_117 ) ;
F_21 ( V_49 , V_116 , V_117 ,
V_126 ) ;
F_18 ( V_49 , V_116 , V_119 , V_111 ) ;
V_111 += F_20 ( V_49 , V_116 , V_119 ) ;
F_21 ( V_49 , V_116 , V_119 ,
V_127 ) ;
F_18 ( V_49 , V_121 , V_117 , V_111 ) ;
V_111 += F_20 ( V_49 , V_121 , V_117 ) ;
F_21 ( V_49 , V_121 , V_117 ,
V_126 ) ;
F_18 ( V_49 , V_121 , V_119 , V_111 ) ;
V_111 += F_20 ( V_49 , V_121 , V_119 ) ;
F_21 ( V_49 , V_121 , V_119 ,
V_127 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_103 * V_104 ,
struct V_48 * V_49 ,
struct V_91 * V_67 ,
bool * V_128 )
{
struct V_129 * V_106 = ( void * ) V_104 -> V_5 ;
struct V_130 * V_131 ;
T_1 V_6 = V_104 -> V_19 ;
const T_3 * V_5 ;
T_2 V_132 ;
T_2 V_133 ;
enum V_134 V_135 ;
const T_3 * V_136 ;
char V_110 [ 25 ] ;
T_2 V_109 , V_137 ;
int V_138 ;
bool V_139 = false ;
bool V_68 = false ;
if ( V_6 < sizeof( * V_106 ) ) {
F_12 ( V_2 , L_16 , V_6 ) ;
return - V_20 ;
}
if ( V_106 -> V_140 != F_39 ( V_141 ) ) {
F_12 ( V_2 , L_17 ,
F_24 ( V_106 -> V_140 ) ) ;
return - V_20 ;
}
V_2 -> V_12 . V_112 = F_24 ( V_106 -> V_113 ) ;
memcpy ( V_2 -> V_12 . V_142 , V_106 -> V_142 ,
sizeof( V_2 -> V_12 . V_142 ) ) ;
V_109 = F_24 ( V_106 -> V_109 ) ;
if ( V_109 )
sprintf ( V_110 , L_13 , V_109 ) ;
else
V_110 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_125 ,
sizeof( V_2 -> V_12 . V_125 ) ,
L_14 ,
F_35 ( V_2 -> V_12 . V_112 ) ,
F_36 ( V_2 -> V_12 . V_112 ) ,
F_34 ( V_2 -> V_12 . V_112 ) ,
F_37 ( V_2 -> V_12 . V_112 ) ,
V_110 ) ;
V_5 = V_106 -> V_5 ;
V_6 -= sizeof( * V_106 ) ;
while ( V_6 >= sizeof( * V_131 ) ) {
V_6 -= sizeof( * V_131 ) ;
V_131 = ( void * ) V_5 ;
V_132 = F_24 ( V_131 -> V_143 ) ;
V_135 = F_24 ( V_131 -> type ) ;
V_136 = V_131 -> V_5 ;
if ( V_6 < V_132 ) {
F_12 ( V_2 , L_18 ,
V_6 , V_132 ) ;
return - V_20 ;
}
V_6 -= F_40 ( V_132 , 4 ) ;
V_5 += sizeof( * V_131 ) + F_40 ( V_132 , 4 ) ;
switch ( V_135 ) {
case V_144 :
F_18 ( V_49 , V_116 ,
V_117 , V_136 ) ;
F_19 ( V_49 , V_116 ,
V_117 , V_132 ) ;
F_21 ( V_49 , V_116 ,
V_117 ,
V_126 ) ;
break;
case V_145 :
F_18 ( V_49 , V_116 ,
V_119 , V_136 ) ;
F_19 ( V_49 , V_116 ,
V_119 , V_132 ) ;
F_21 ( V_49 , V_116 ,
V_119 ,
V_127 ) ;
break;
case V_146 :
F_18 ( V_49 , V_121 ,
V_117 , V_136 ) ;
F_19 ( V_49 , V_121 ,
V_117 , V_132 ) ;
F_21 ( V_49 , V_121 ,
V_117 ,
V_126 ) ;
break;
case V_147 :
F_18 ( V_49 , V_121 ,
V_119 , V_136 ) ;
F_19 ( V_49 , V_121 ,
V_119 , V_132 ) ;
F_21 ( V_49 , V_121 ,
V_119 ,
V_127 ) ;
break;
case V_148 :
F_12 ( V_2 , L_19 ) ;
break;
case V_149 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_67 -> V_151 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_153 :
if ( V_132 )
goto V_150;
V_67 -> V_154 |= V_155 ;
break;
case V_156 :
if ( V_132 < sizeof( T_2 ) )
goto V_150;
if ( V_132 % sizeof( T_2 ) )
goto V_150;
V_67 -> V_154 = F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_157 :
if ( V_132 != sizeof( struct V_92 ) )
goto V_150;
if ( F_28 ( V_2 , V_136 , V_67 ) )
goto V_158;
break;
case V_159 :
if ( V_132 != sizeof( struct V_98 ) )
goto V_150;
if ( F_32 ( V_2 , V_136 , V_67 ) )
goto V_158;
break;
case V_160 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_161 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_162 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_163 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_164 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_165 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_166 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_167 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_168 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_169 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_170 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_49 -> V_171 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_172 :
if ( V_132 )
goto V_150;
V_2 -> V_12 . V_173 = true ;
break;
case V_174 :
F_18 ( V_49 , V_175 ,
V_117 , V_136 ) ;
F_19 ( V_49 , V_175 ,
V_117 , V_132 ) ;
F_21 ( V_49 , V_175 ,
V_117 ,
V_126 ) ;
break;
case V_176 :
F_18 ( V_49 , V_175 ,
V_119 , V_136 ) ;
F_19 ( V_49 , V_175 ,
V_119 , V_132 ) ;
F_21 ( V_49 , V_175 ,
V_119 ,
V_127 ) ;
break;
case V_177 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_67 -> V_178 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_179 :
F_25 ( V_49 , V_136 , V_116 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_181 :
F_25 ( V_49 , V_136 , V_121 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_182 :
F_25 ( V_49 , V_136 , V_175 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_183 :
if ( V_132 != sizeof( struct V_84 ) )
goto V_150;
if ( F_27 ( V_2 , V_136 ) )
goto V_158;
break;
case V_184 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_2 -> V_12 . V_185 = F_41 ( ( V_152 * ) V_136 ) ;
V_2 -> V_12 . V_186 = ( V_2 -> V_12 . V_185 &
V_187 ) >>
V_188 ;
V_2 -> V_12 . V_189 = ( V_2 -> V_12 . V_185 &
V_190 ) >>
V_191 ;
break;
case V_192 :
F_25 ( V_49 , V_136 , V_116 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_193 :
F_25 ( V_49 , V_136 , V_121 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_194 :
F_25 ( V_49 , V_136 , V_175 ,
V_132 ) ;
V_2 -> V_12 . type = V_180 ;
break;
case V_195 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_138 =
F_41 ( ( V_152 * ) V_136 ) ;
if ( V_138 == 2 ) {
V_2 -> V_12 . V_8 [ V_116 ] . V_196 =
true ;
V_2 -> V_12 . V_8 [ V_121 ] . V_196 =
true ;
V_2 -> V_12 . V_8 [ V_175 ] . V_196 =
true ;
} else if ( ( V_138 > 2 ) || ( V_138 < 1 ) ) {
F_12 ( V_2 , L_20 ) ;
return - V_20 ;
}
break;
case V_197 :
if ( F_22 ( & V_2 -> V_12 , V_136 , V_132 ) )
goto V_150;
break;
case V_198 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_67 -> V_199 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_200 : {
V_152 * V_201 = ( void * ) V_136 ;
T_2 V_202 , V_203 ;
T_3 V_204 ;
if ( V_132 != sizeof( T_2 ) * 3 )
goto V_150;
V_202 = F_41 ( V_201 ++ ) ;
V_203 = F_41 ( V_201 ++ ) ;
V_204 = F_41 ( V_201 ) ;
snprintf ( V_2 -> V_12 . V_125 ,
sizeof( V_2 -> V_12 . V_125 ) , L_21 ,
V_202 , V_203 , V_204 ) ;
break;
}
case V_205 : {
struct V_206 * V_207 = ( void * ) V_136 ;
if ( V_49 -> V_13 ) {
F_12 ( V_2 ,
L_22 ) ;
break;
}
V_49 -> V_13 = V_207 ;
F_42 ( V_2 , L_23 ,
F_43 ( V_207 -> V_208 ) ) ;
V_2 -> V_12 . V_209 =
V_132 - F_44 ( struct V_206 ,
V_210 ) ;
V_2 -> V_12 . V_209 /=
sizeof( V_2 -> V_12 . V_13 -> V_210 [ 0 ] ) ;
break;
}
case V_211 : {
struct V_212 * V_213 = ( void * ) V_136 ;
if ( ! V_49 -> V_13 ) {
F_12 ( V_2 ,
L_24 ,
V_213 -> V_214 ) ;
break;
}
if ( V_213 -> V_214 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_12 ( V_2 ,
L_25 ,
V_213 -> V_214 ) ;
break;
}
if ( V_49 -> V_14 [ V_213 -> V_214 ] ) {
F_12 ( V_2 ,
L_26 ,
V_213 -> V_214 ) ;
break;
}
if ( V_213 -> V_215 )
V_139 = true ;
F_42 ( V_2 , L_27 ,
V_213 -> V_214 ) ;
V_49 -> V_14 [ V_213 -> V_214 ] = V_213 ;
V_49 -> V_216 [ V_213 -> V_214 ] = V_132 ;
break;
}
case V_217 : {
struct V_218 * V_219 =
( void * ) V_136 ;
T_2 V_220 = F_24 ( V_219 -> V_214 ) ;
if ( V_220 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_12 ( V_2 ,
L_28 ,
V_219 -> V_214 ) ;
break;
}
if ( V_49 -> V_15 [ V_220 ] ) {
F_12 ( V_2 ,
L_29 ,
V_219 -> V_214 ) ;
break;
}
F_42 ( V_2 , L_30 , V_219 -> V_214 ) ;
V_49 -> V_15 [ V_220 ] = V_219 ;
V_49 -> V_221 [ V_220 ] = V_132 ;
break;
}
case V_222 :
* V_128 = true ;
F_25 ( V_49 , V_136 ,
V_223 ,
V_132 ) ;
break;
case V_224 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_137 = F_41 ( ( V_152 * ) V_136 ) ;
F_45 ( V_2 ,
L_31 ,
V_137 ) ;
if ( V_137 > V_225 ) {
F_12 ( V_2 ,
L_32 ,
V_225 ) ;
return - V_20 ;
}
if ( V_137 & ( V_226 - 1 ) ) {
F_12 ( V_2 ,
L_33 ,
V_226 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_8 [ V_116 ] . V_137 =
V_137 ;
V_133 = V_223 ;
V_2 -> V_12 . V_8 [ V_133 ] . V_137 =
V_137 ;
break;
case V_227 :
if ( V_132 != sizeof( T_2 ) )
goto V_150;
V_2 -> V_12 . V_228 =
F_41 ( ( V_152 * ) V_136 ) ;
break;
case V_229 :
if ( V_132 < sizeof( struct V_64 ) )
break;
F_23 ( & V_2 -> V_12 , V_136 , V_132 ) ;
V_68 = true ;
break;
case V_230 : {
struct V_231 * V_232 =
( void * ) V_136 ;
T_2 type ;
T_1 V_19 ;
struct V_231 * V_233 ;
if ( V_132 != ( sizeof( * V_232 ) ) )
goto V_150;
type = F_24 ( V_232 -> V_234 ) ;
F_13 ( V_2 , L_34 ,
V_232 -> V_234 ) ;
switch ( type & V_235 ) {
case V_236 :
case V_237 :
break;
default:
F_12 ( V_2 ,
L_35 ,
type ) ;
return - V_20 ;
}
V_19 = sizeof( * V_49 -> V_16 ) *
( V_49 -> V_238 + 1 ) ;
V_233 = F_17 ( V_49 -> V_16 , V_19 , V_46 ) ;
if ( ! V_233 )
return - V_21 ;
V_49 -> V_16 = V_233 ;
V_49 -> V_16 [ V_49 -> V_238 ] = * V_232 ;
V_49 -> V_238 ++ ;
break;
}
default:
F_13 ( V_2 , L_36 , V_135 ) ;
break;
}
}
if ( ! F_46 ( V_67 , V_239 ) &&
V_139 && ! * V_128 ) {
F_12 ( V_2 ,
L_37 ) ;
return - V_20 ;
}
if ( V_6 ) {
F_12 ( V_2 , L_38 , V_6 ) ;
F_47 ( V_2 , V_240 , ( T_3 * ) V_5 , V_6 ) ;
return - V_20 ;
}
if ( F_46 ( V_67 , V_241 ) &&
! V_68 ) {
F_13 ( V_2 ,
L_39 ) ;
F_48 ( ( V_242 long ) V_241 ,
V_67 -> V_102 ) ;
}
return 0 ;
V_150:
F_12 ( V_2 , L_40 , V_135 , V_132 ) ;
V_158:
F_47 ( V_2 , V_240 , V_136 , V_132 ) ;
return - V_20 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
enum V_50 type )
{
int V_9 ;
struct V_3 * V_11 ;
V_11 = F_50 ( V_49 -> V_8 [ type ] . V_54 , sizeof( * V_11 ) , V_46 ) ;
if ( ! V_11 )
return - V_21 ;
V_2 -> V_12 . V_8 [ type ] . V_11 = V_11 ;
V_2 -> V_12 . V_8 [ type ] . V_10 = V_49 -> V_8 [ type ] . V_54 ;
for ( V_9 = 0 ; V_9 < V_49 -> V_8 [ type ] . V_54 ; V_9 ++ )
if ( F_7 ( V_2 , & V_11 [ V_9 ] , F_15 ( V_49 , type , V_9 ) ) )
return - V_21 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
const struct V_24 * V_25 )
{
F_13 ( V_2 , L_41 ,
F_20 ( V_49 , V_116 ,
V_117 ) ) ;
F_13 ( V_2 , L_42 ,
F_20 ( V_49 , V_116 ,
V_119 ) ) ;
F_13 ( V_2 , L_43 ,
F_20 ( V_49 , V_121 , V_117 ) ) ;
F_13 ( V_2 , L_44 ,
F_20 ( V_49 , V_121 , V_119 ) ) ;
if ( F_20 ( V_49 , V_116 , V_117 ) >
V_25 -> V_243 ) {
F_12 ( V_2 , L_45 ,
F_20 ( V_49 , V_116 ,
V_117 ) ) ;
return - 1 ;
}
if ( F_20 ( V_49 , V_116 , V_119 ) >
V_25 -> V_244 ) {
F_12 ( V_2 , L_46 ,
F_20 ( V_49 , V_116 ,
V_119 ) ) ;
return - 1 ;
}
if ( F_20 ( V_49 , V_121 , V_117 ) >
V_25 -> V_243 ) {
F_12 ( V_2 , L_47 ,
F_20 ( V_49 , V_121 ,
V_117 ) ) ;
return - 1 ;
}
if ( F_20 ( V_49 , V_121 , V_119 ) >
V_25 -> V_244 ) {
F_12 ( V_2 , L_48 ,
F_20 ( V_49 , V_116 ,
V_119 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_245 *
F_52 ( struct V_1 * V_2 , struct V_246 * V_247 )
{
const struct V_248 * V_249 = V_247 -> V_249 ;
struct V_250 * V_251 = NULL ;
struct V_245 * V_252 = NULL ;
#ifdef F_53
V_2 -> V_253 = F_54 ( V_247 -> V_254 ,
V_2 -> V_255 ) ;
if ( ! V_2 -> V_253 ) {
F_12 ( V_2 ,
L_49 ) ;
return V_252 ;
}
V_251 = V_2 -> V_253 ;
#endif
V_252 = V_249 -> V_256 ( V_2 -> V_26 , V_2 -> V_26 -> V_25 , & V_2 -> V_12 , V_251 ) ;
#ifdef F_53
if ( ! V_252 ) {
F_55 ( V_2 -> V_253 ) ;
V_2 -> V_253 = NULL ;
}
#endif
return V_252 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_252 ) {
F_57 ( V_2 -> V_252 ) ;
V_2 -> V_252 = NULL ;
#ifdef F_53
F_55 ( V_2 -> V_253 ) ;
V_2 -> V_253 = NULL ;
#endif
}
}
static void V_47 ( const struct V_103 * V_104 , void * V_257 )
{
struct V_1 * V_2 = V_257 ;
struct V_55 * V_12 = & V_2 -> V_12 ;
struct V_105 * V_106 ;
struct V_246 * V_247 ;
int V_258 ;
struct V_48 * V_49 ;
const unsigned int V_259 = V_2 -> V_26 -> V_25 -> V_40 ;
const unsigned int V_260 = V_2 -> V_26 -> V_25 -> V_41 ;
T_1 V_261 [ V_262 ] ;
T_2 V_107 ;
int V_9 ;
bool V_263 = false ;
bool V_128 = false ;
V_12 -> V_99 . V_151 = V_264 ;
V_12 -> V_99 . V_178 =
V_265 ;
V_12 -> V_99 . V_199 = V_266 ;
V_49 = F_58 ( sizeof( * V_49 ) , V_46 ) ;
if ( ! V_49 )
goto V_267;
if ( ! V_104 )
goto V_268;
F_13 ( V_2 , L_50 ,
V_2 -> V_43 , V_104 -> V_19 ) ;
if ( V_104 -> V_19 < 4 ) {
F_12 ( V_2 , L_51 ) ;
goto V_268;
}
V_106 = (struct V_105 * ) V_104 -> V_5 ;
if ( V_106 -> V_113 )
V_258 = F_33 ( V_2 , V_104 , V_49 ) ;
else
V_258 = F_38 ( V_2 , V_104 , V_49 ,
& V_12 -> V_99 , & V_128 ) ;
if ( V_258 )
goto V_268;
if ( F_59 ( & V_2 -> V_12 . V_99 , V_269 ) )
V_107 = V_2 -> V_12 . V_112 ;
else
V_107 = F_34 ( V_2 -> V_12 . V_112 ) ;
if ( V_107 < V_260 || V_107 > V_259 ) {
F_12 ( V_2 ,
L_52
L_53 ,
V_259 , V_107 ) ;
goto V_268;
}
if ( V_12 -> type == V_270 && F_51 ( V_2 , V_49 ,
V_2 -> V_26 -> V_25 ) )
goto V_268;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
if ( F_49 ( V_2 , V_49 , V_9 ) )
goto V_267;
if ( V_49 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_60 ( V_49 -> V_13 ,
sizeof( * V_49 -> V_13 ) +
sizeof( V_49 -> V_13 -> V_210 [ 0 ] ) *
V_2 -> V_12 . V_209 , V_46 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_267;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_49 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_216 [ V_9 ] =
V_49 -> V_216 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_60 ( V_49 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_216 [ V_9 ] ,
V_46 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_267;
}
}
memset ( & V_261 , 0xff , sizeof( V_261 ) ) ;
V_261 [ V_271 ] =
sizeof( struct V_272 ) ;
V_261 [ V_273 ] = 0 ;
V_261 [ V_274 ] =
sizeof( struct V_275 ) ;
V_261 [ V_276 ] =
sizeof( struct V_277 ) ;
V_261 [ V_278 ] =
sizeof( struct V_279 ) ;
V_261 [ V_280 ] =
sizeof( struct V_281 ) ;
V_261 [ V_282 ] =
sizeof( struct V_283 ) ;
V_261 [ V_284 ] =
sizeof( struct V_285 ) ;
V_261 [ V_286 ] =
sizeof( struct V_287 ) ;
V_261 [ V_288 ] =
sizeof( struct V_289 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_49 -> V_15 [ V_9 ] ) {
if ( F_26 ( V_49 -> V_221 [ V_9 ] <
( V_261 [ V_9 ] +
sizeof( struct V_218 ) ) ) )
goto V_267;
V_2 -> V_12 . V_221 [ V_9 ] =
V_49 -> V_221 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_60 ( V_49 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_221 [ V_9 ] ,
V_46 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_267;
}
}
V_2 -> V_12 . V_16 = V_49 -> V_16 ;
V_49 -> V_16 = NULL ;
V_2 -> V_12 . V_238 = V_49 -> V_238 ;
V_12 -> V_161 = V_49 -> V_161 ;
if ( V_49 -> V_163 )
V_12 -> V_163 = ( V_49 -> V_163 - 16 ) / 12 ;
else
V_12 -> V_163 =
V_2 -> V_26 -> V_25 -> V_290 -> V_291 ;
V_12 -> V_165 = V_49 -> V_165 ;
V_12 -> V_167 = V_49 -> V_167 ;
if ( V_49 -> V_169 )
V_12 -> V_169 = ( V_49 -> V_169 - 16 ) / 12 ;
else
V_12 -> V_169 =
V_2 -> V_26 -> V_25 -> V_290 -> V_291 ;
V_12 -> V_171 = V_49 -> V_171 ;
if ( V_12 -> V_99 . V_178 >
V_292 )
V_12 -> V_99 . V_178 =
V_293 ;
F_61 ( V_104 ) ;
F_62 ( & V_294 ) ;
switch ( V_12 -> type ) {
case V_270 :
V_247 = & V_246 [ V_295 ] ;
break;
default:
F_63 ( 1 , L_54 , V_12 -> type ) ;
case V_180 :
V_247 = & V_246 [ V_296 ] ;
break;
}
F_42 ( V_2 , L_55 ,
V_2 -> V_12 . V_125 , V_247 -> V_254 ) ;
F_64 ( & V_2 -> V_297 , & V_247 -> V_2 ) ;
if ( V_247 -> V_249 ) {
V_2 -> V_252 = F_52 ( V_2 , V_247 ) ;
if ( ! V_2 -> V_252 ) {
F_65 ( & V_294 ) ;
goto V_298;
}
} else {
V_263 = true ;
}
F_65 ( & V_294 ) ;
F_66 ( & V_2 -> V_299 ) ;
if ( V_263 ) {
F_67 ( L_56 , V_247 -> V_254 ) ;
#ifdef F_68
if ( V_258 )
F_12 ( V_2 ,
L_57 ,
V_247 -> V_254 , V_258 ) ;
#endif
}
goto free;
V_268:
F_61 ( V_104 ) ;
if ( F_9 ( V_2 , false ) )
goto V_298;
goto free;
V_267:
F_5 ( V_2 ) ;
F_61 ( V_104 ) ;
V_298:
F_66 ( & V_2 -> V_299 ) ;
F_69 ( V_2 -> V_26 -> V_45 ) ;
free:
if ( V_49 ) {
for ( V_9 = 0 ; V_9 < F_6 ( V_49 -> V_8 ) ; V_9 ++ )
F_4 ( V_49 -> V_8 [ V_9 ] . V_11 ) ;
F_4 ( V_49 -> V_16 ) ;
F_4 ( V_49 ) ;
}
}
struct V_1 * F_70 ( struct V_300 * V_26 )
{
struct V_1 * V_2 ;
int V_301 ;
V_2 = F_58 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 ) {
V_301 = - V_21 ;
goto V_258;
}
V_2 -> V_26 = V_26 ;
V_2 -> V_45 = V_26 -> V_45 ;
F_71 ( & V_2 -> V_299 ) ;
F_72 ( & V_2 -> V_297 ) ;
#ifdef F_53
V_2 -> V_255 = F_54 ( F_73 ( V_26 -> V_45 ) ,
V_302 ) ;
if ( ! V_2 -> V_255 ) {
F_12 ( V_2 , L_58 ) ;
V_301 = - V_21 ;
goto V_303;
}
V_2 -> V_26 -> V_251 = F_54 ( L_59 , V_2 -> V_255 ) ;
if ( ! V_2 -> V_26 -> V_251 ) {
F_12 ( V_2 , L_60 ) ;
V_301 = - V_21 ;
goto V_304;
}
#endif
V_301 = F_9 ( V_2 , true ) ;
if ( V_301 ) {
F_12 ( V_26 , L_61 ) ;
goto V_305;
}
return V_2 ;
V_305:
#ifdef F_53
V_304:
F_55 ( V_2 -> V_255 ) ;
V_303:
#endif
F_4 ( V_2 ) ;
V_258:
return F_74 ( V_301 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_76 ( & V_2 -> V_299 ) ;
F_56 ( V_2 ) ;
F_5 ( V_2 ) ;
F_62 ( & V_294 ) ;
if ( ! F_77 ( & V_2 -> V_297 ) )
F_78 ( & V_2 -> V_297 ) ;
F_65 ( & V_294 ) ;
#ifdef F_53
F_55 ( V_2 -> V_255 ) ;
#endif
F_4 ( V_2 ) ;
}
int F_79 ( const char * V_254 , const struct V_248 * V_249 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_246 * V_247 ;
F_62 ( & V_294 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_246 ) ; V_9 ++ ) {
V_247 = & V_246 [ V_9 ] ;
if ( strcmp ( V_247 -> V_254 , V_254 ) )
continue;
V_247 -> V_249 = V_249 ;
F_80 (drv, &op->drv, list)
V_2 -> V_252 = F_52 ( V_2 , V_247 ) ;
F_65 ( & V_294 ) ;
return 0 ;
}
F_65 ( & V_294 ) ;
return - V_306 ;
}
void F_81 ( const char * V_254 )
{
int V_9 ;
struct V_1 * V_2 ;
F_62 ( & V_294 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_246 ) ; V_9 ++ ) {
if ( strcmp ( V_246 [ V_9 ] . V_254 , V_254 ) )
continue;
V_246 [ V_9 ] . V_249 = NULL ;
F_80 (drv, &iwlwifi_opmode_table[i].drv, list)
F_56 ( V_2 ) ;
F_65 ( & V_294 ) ;
return;
}
F_65 ( & V_294 ) ;
}
static int T_4 F_82 ( void )
{
int V_9 ;
F_83 ( & V_294 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_246 ) ; V_9 ++ )
F_72 ( & V_246 [ V_9 ] . V_2 ) ;
F_84 ( V_307 L_62 ) ;
F_84 ( V_308 L_62 ) ;
#ifdef F_53
V_302 = F_54 ( V_309 , NULL ) ;
if ( ! V_302 )
return - V_310 ;
#endif
return F_85 () ;
}
static void T_5 F_86 ( void )
{
F_87 () ;
#ifdef F_53
F_55 ( V_302 ) ;
#endif
}
