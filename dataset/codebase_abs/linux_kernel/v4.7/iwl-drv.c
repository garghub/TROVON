static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_1 ( V_2 , & V_8 -> V_11 [ V_9 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_9 ;
F_5 ( V_2 -> V_12 . V_13 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ )
F_5 ( V_2 -> V_12 . V_14 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ )
F_5 ( V_2 -> V_12 . V_15 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_16 ) ; V_9 ++ )
F_5 ( V_2 -> V_12 . V_16 [ V_9 ] ) ;
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
const char * V_24 = V_2 -> V_25 -> V_26 ;
char V_27 [ 8 ] ;
if ( V_23 ) {
V_2 -> V_28 = V_2 -> V_25 -> V_29 ;
sprintf ( V_27 , L_1 , V_2 -> V_28 ) ;
} else {
V_2 -> V_28 -- ;
sprintf ( V_27 , L_1 , V_2 -> V_28 ) ;
}
if ( V_2 -> V_28 < V_2 -> V_25 -> V_30 ) {
F_10 ( V_2 , L_2 ) ;
return - V_31 ;
}
snprintf ( V_2 -> V_32 , sizeof( V_2 -> V_32 ) , L_3 ,
V_24 , V_27 ) ;
F_11 ( V_2 , L_4 ,
V_2 -> V_32 ) ;
return F_12 ( V_33 , 1 , V_2 -> V_32 ,
V_2 -> V_34 -> V_35 ,
V_36 , V_2 , V_37 ) ;
}
static struct V_18 * F_13 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 )
{
return & V_39 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_14 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
const void * V_5 )
{
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_15 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
T_1 V_19 )
{
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 = V_19 ;
}
static T_1 F_16 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 )
{
return V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 ;
}
static void F_17 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
T_2 V_22 )
{
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_22 = V_22 ;
}
static int F_18 ( struct V_41 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_42 ;
struct V_43 * V_44 = (struct V_43 * ) V_5 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_2 V_49 ;
if ( V_6 < sizeof( * V_44 ) ||
V_6 < sizeof( V_44 -> V_19 ) + V_44 -> V_19 * sizeof( V_44 -> V_48 [ 0 ] ) )
return - V_20 ;
for ( V_9 = 0 , V_42 = 0 ; V_9 < V_50 && V_9 < V_44 -> V_19 ; V_9 ++ ) {
V_46 = & V_44 -> V_48 [ V_42 ] ;
V_49 = F_19 ( V_46 -> V_49 ) ;
if ( ! V_49 )
continue;
V_48 = & V_12 -> V_48 [ V_42 ++ ] ;
V_48 -> V_49 = V_49 ;
V_48 -> V_51 = F_20 ( V_52 ) ;
V_48 -> V_53 = V_46 -> V_53 ;
V_48 -> V_54 = V_46 -> V_54 ;
V_48 -> V_55 = V_46 -> V_55 ;
V_48 -> V_56 = V_46 -> V_56 ;
V_48 -> V_57 = V_46 -> V_57 ;
V_48 -> V_58 = V_46 -> V_58 ;
V_48 -> V_59 = V_46 -> V_59 ;
}
return 0 ;
}
static void F_21 ( struct V_41 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_60 * V_61 = ( void * ) V_5 ;
struct V_62 * V_63 = & V_12 -> V_64 ;
V_63 -> V_65 = F_19 ( V_61 -> V_65 ) ;
V_63 -> V_66 = F_19 ( V_61 -> V_66 ) ;
V_63 -> V_67 =
F_19 ( V_61 -> V_67 ) ;
V_63 -> V_68 = F_19 ( V_61 -> V_68 ) ;
V_63 -> V_69 =
F_19 ( V_61 -> V_69 ) ;
V_63 -> V_70 = F_19 ( V_61 -> V_70 ) ;
V_63 -> V_71 =
F_19 ( V_61 -> V_71 ) ;
V_63 -> V_72 =
F_19 ( V_61 -> V_72 ) ;
V_63 -> V_73 = F_19 ( V_61 -> V_73 ) ;
V_63 -> V_74 =
F_19 ( V_61 -> V_74 ) ;
V_63 -> V_75 =
F_19 ( V_61 -> V_75 ) ;
V_63 -> V_76 =
F_19 ( V_61 -> V_76 ) ;
V_63 -> V_77 =
F_19 ( V_61 -> V_77 ) ;
}
static int F_22 ( struct V_38 * V_39 ,
const void * V_5 , enum V_40 type ,
int V_19 )
{
struct V_78 * V_8 ;
struct V_18 * V_11 ;
struct V_79 * V_80 ;
if ( F_23 ( ! V_39 || ! V_5 || type >= V_17 ) )
return - 1 ;
V_80 = (struct V_79 * ) V_5 ;
V_8 = & V_39 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_81 ] ;
V_11 -> V_22 = F_19 ( V_80 -> V_22 ) ;
V_11 -> V_5 = V_80 -> V_5 ;
V_11 -> V_19 = V_19 - sizeof( V_80 -> V_22 ) ;
++ V_8 -> V_81 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_82 * V_83 =
(struct V_82 * ) V_5 ;
T_2 V_84 = F_19 ( V_83 -> V_84 ) ;
if ( V_84 >= V_17 ) {
F_10 ( V_2 , L_5 ,
V_84 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_85 [ V_84 ] . V_86 =
V_83 -> V_87 . V_86 ;
V_2 -> V_12 . V_85 [ V_84 ] . V_88 =
V_83 -> V_87 . V_88 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_89 * V_63 )
{
const struct V_90 * V_91 = ( void * ) V_5 ;
T_2 V_92 = F_19 ( V_91 -> V_92 ) ;
T_2 V_93 = F_19 ( V_91 -> V_93 ) ;
int V_9 ;
if ( V_92 >= F_26 ( V_94 , 32 ) ) {
F_10 ( V_2 ,
L_6 ,
V_92 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_20 ( V_9 ) )
F_27 ( V_9 + 32 * V_92 , V_63 -> V_95 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_89 * V_63 )
{
const struct V_96 * V_97 = ( void * ) V_5 ;
T_2 V_92 = F_19 ( V_97 -> V_92 ) ;
T_2 V_93 = F_19 ( V_97 -> V_98 ) ;
int V_9 ;
if ( V_92 >= F_26 ( V_99 , 32 ) ) {
F_10 ( V_2 ,
L_7 ,
V_92 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_20 ( V_9 ) )
F_27 ( V_9 + 32 * V_92 , V_63 -> V_100 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_38 * V_39 )
{
struct V_103 * V_104 = ( void * ) V_102 -> V_5 ;
T_2 V_105 , V_106 , V_107 ;
char V_108 [ 25 ] ;
const T_3 * V_109 ;
V_2 -> V_12 . V_110 = F_19 ( V_104 -> V_111 ) ;
V_105 = F_30 ( V_2 -> V_12 . V_110 ) ;
switch ( V_105 ) {
default:
V_106 = 28 ;
if ( V_102 -> V_19 < V_106 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_107 = F_19 ( V_104 -> V_112 . V_113 . V_107 ) ;
F_15 ( V_39 , V_114 , V_115 ,
F_19 ( V_104 -> V_112 . V_113 . V_116 ) ) ;
F_15 ( V_39 , V_114 , V_117 ,
F_19 ( V_104 -> V_112 . V_113 . V_118 ) ) ;
F_15 ( V_39 , V_119 , V_115 ,
F_19 ( V_104 -> V_112 . V_113 . V_120 ) ) ;
F_15 ( V_39 , V_119 , V_117 ,
F_19 ( V_104 -> V_112 . V_113 . V_121 ) ) ;
V_109 = V_104 -> V_112 . V_113 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_106 = 24 ;
if ( V_102 -> V_19 < V_106 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_107 = 0 ;
F_15 ( V_39 , V_114 , V_115 ,
F_19 ( V_104 -> V_112 . V_122 . V_116 ) ) ;
F_15 ( V_39 , V_114 , V_117 ,
F_19 ( V_104 -> V_112 . V_122 . V_118 ) ) ;
F_15 ( V_39 , V_119 , V_115 ,
F_19 ( V_104 -> V_112 . V_122 . V_120 ) ) ;
F_15 ( V_39 , V_119 , V_117 ,
F_19 ( V_104 -> V_112 . V_122 . V_121 ) ) ;
V_109 = V_104 -> V_112 . V_122 . V_5 ;
break;
}
if ( V_107 )
sprintf ( V_108 , L_9 , V_107 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_10 ,
F_31 ( V_2 -> V_12 . V_110 ) ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_30 ( V_2 -> V_12 . V_110 ) ,
F_33 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
if ( V_102 -> V_19 != V_106 +
F_16 ( V_39 , V_114 , V_115 ) +
F_16 ( V_39 , V_114 , V_117 ) +
F_16 ( V_39 , V_119 , V_115 ) +
F_16 ( V_39 , V_119 , V_117 ) ) {
F_10 ( V_2 ,
L_11 ,
( int ) V_102 -> V_19 ) ;
return - V_20 ;
}
F_14 ( V_39 , V_114 , V_115 , V_109 ) ;
V_109 += F_16 ( V_39 , V_114 , V_115 ) ;
F_17 ( V_39 , V_114 , V_115 ,
V_124 ) ;
F_14 ( V_39 , V_114 , V_117 , V_109 ) ;
V_109 += F_16 ( V_39 , V_114 , V_117 ) ;
F_17 ( V_39 , V_114 , V_117 ,
V_125 ) ;
F_14 ( V_39 , V_119 , V_115 , V_109 ) ;
V_109 += F_16 ( V_39 , V_119 , V_115 ) ;
F_17 ( V_39 , V_119 , V_115 ,
V_124 ) ;
F_14 ( V_39 , V_119 , V_117 , V_109 ) ;
V_109 += F_16 ( V_39 , V_119 , V_117 ) ;
F_17 ( V_39 , V_119 , V_117 ,
V_125 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_38 * V_39 ,
struct V_89 * V_63 ,
bool * V_126 )
{
struct V_127 * V_104 = ( void * ) V_102 -> V_5 ;
struct V_128 * V_129 ;
T_1 V_6 = V_102 -> V_19 ;
const T_3 * V_5 ;
T_2 V_130 ;
T_2 V_131 ;
enum V_132 V_133 ;
const T_3 * V_134 ;
char V_108 [ 25 ] ;
T_2 V_107 , V_135 ;
int V_136 ;
bool V_137 = false ;
bool V_64 = false ;
if ( V_6 < sizeof( * V_104 ) ) {
F_10 ( V_2 , L_12 , V_6 ) ;
return - V_20 ;
}
if ( V_104 -> V_138 != F_35 ( V_139 ) ) {
F_10 ( V_2 , L_13 ,
F_19 ( V_104 -> V_138 ) ) ;
return - V_20 ;
}
V_2 -> V_12 . V_110 = F_19 ( V_104 -> V_111 ) ;
memcpy ( V_2 -> V_12 . V_140 , V_104 -> V_140 ,
sizeof( V_2 -> V_12 . V_140 ) ) ;
V_107 = F_19 ( V_104 -> V_107 ) ;
if ( V_107 )
sprintf ( V_108 , L_9 , V_107 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_10 ,
F_31 ( V_2 -> V_12 . V_110 ) ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_30 ( V_2 -> V_12 . V_110 ) ,
F_33 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
V_5 = V_104 -> V_5 ;
V_6 -= sizeof( * V_104 ) ;
while ( V_6 >= sizeof( * V_129 ) ) {
V_6 -= sizeof( * V_129 ) ;
V_129 = ( void * ) V_5 ;
V_130 = F_19 ( V_129 -> V_141 ) ;
V_133 = F_19 ( V_129 -> type ) ;
V_134 = V_129 -> V_5 ;
if ( V_6 < V_130 ) {
F_10 ( V_2 , L_14 ,
V_6 , V_130 ) ;
return - V_20 ;
}
V_6 -= F_36 ( V_130 , 4 ) ;
V_5 += sizeof( * V_129 ) + F_36 ( V_130 , 4 ) ;
switch ( V_133 ) {
case V_142 :
F_14 ( V_39 , V_114 ,
V_115 , V_134 ) ;
F_15 ( V_39 , V_114 ,
V_115 , V_130 ) ;
F_17 ( V_39 , V_114 ,
V_115 ,
V_124 ) ;
break;
case V_143 :
F_14 ( V_39 , V_114 ,
V_117 , V_134 ) ;
F_15 ( V_39 , V_114 ,
V_117 , V_130 ) ;
F_17 ( V_39 , V_114 ,
V_117 ,
V_125 ) ;
break;
case V_144 :
F_14 ( V_39 , V_119 ,
V_115 , V_134 ) ;
F_15 ( V_39 , V_119 ,
V_115 , V_130 ) ;
F_17 ( V_39 , V_119 ,
V_115 ,
V_124 ) ;
break;
case V_145 :
F_14 ( V_39 , V_119 ,
V_117 , V_134 ) ;
F_15 ( V_39 , V_119 ,
V_117 , V_130 ) ;
F_17 ( V_39 , V_119 ,
V_117 ,
V_125 ) ;
break;
case V_146 :
F_10 ( V_2 , L_15 ) ;
break;
case V_147 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_63 -> V_149 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_151 :
if ( V_130 )
goto V_148;
V_63 -> V_152 |= V_153 ;
break;
case V_154 :
if ( V_130 < sizeof( T_2 ) )
goto V_148;
if ( V_130 % sizeof( T_2 ) )
goto V_148;
V_63 -> V_152 = F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_155 :
if ( V_130 != sizeof( struct V_90 ) )
goto V_148;
if ( F_25 ( V_2 , V_134 , V_63 ) )
goto V_156;
break;
case V_157 :
if ( V_130 != sizeof( struct V_96 ) )
goto V_148;
if ( F_28 ( V_2 , V_134 , V_63 ) )
goto V_156;
break;
case V_158 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_159 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_160 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_161 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_162 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_163 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_164 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_165 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_166 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_167 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_168 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_39 -> V_169 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_170 :
if ( V_130 )
goto V_148;
V_2 -> V_12 . V_171 = true ;
break;
case V_172 :
F_14 ( V_39 , V_173 ,
V_115 , V_134 ) ;
F_15 ( V_39 , V_173 ,
V_115 , V_130 ) ;
F_17 ( V_39 , V_173 ,
V_115 ,
V_124 ) ;
break;
case V_174 :
F_14 ( V_39 , V_173 ,
V_117 , V_134 ) ;
F_15 ( V_39 , V_173 ,
V_117 , V_130 ) ;
F_17 ( V_39 , V_173 ,
V_117 ,
V_125 ) ;
break;
case V_175 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_63 -> V_176 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_177 :
F_22 ( V_39 , V_134 , V_114 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_179 :
F_22 ( V_39 , V_134 , V_119 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_180 :
F_22 ( V_39 , V_134 , V_173 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_181 :
if ( V_130 != sizeof( struct V_82 ) )
goto V_148;
if ( F_24 ( V_2 , V_134 ) )
goto V_156;
break;
case V_182 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_2 -> V_12 . V_183 = F_37 ( ( V_150 * ) V_134 ) ;
V_2 -> V_12 . V_184 = ( V_2 -> V_12 . V_183 &
V_185 ) >>
V_186 ;
V_2 -> V_12 . V_187 = ( V_2 -> V_12 . V_183 &
V_188 ) >>
V_189 ;
break;
case V_190 :
F_22 ( V_39 , V_134 , V_114 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_191 :
F_22 ( V_39 , V_134 , V_119 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_192 :
F_22 ( V_39 , V_134 , V_173 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_193 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_136 =
F_37 ( ( V_150 * ) V_134 ) ;
if ( V_136 == 2 ) {
V_2 -> V_12 . V_8 [ V_114 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_119 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_173 ] . V_194 =
true ;
} else if ( ( V_136 > 2 ) || ( V_136 < 1 ) ) {
F_10 ( V_2 , L_16 ) ;
return - V_20 ;
}
break;
case V_195 :
if ( F_18 ( & V_2 -> V_12 , V_134 , V_130 ) )
goto V_148;
break;
case V_196 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_63 -> V_197 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_198 : {
V_150 * V_199 = ( void * ) V_134 ;
T_2 V_200 , V_201 ;
T_3 V_202 ;
if ( V_130 != sizeof( T_2 ) * 3 )
goto V_148;
V_200 = F_37 ( V_199 ++ ) ;
V_201 = F_37 ( V_199 ++ ) ;
V_202 = F_37 ( V_199 ) ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) , L_17 ,
V_200 , V_201 , V_202 ) ;
break;
}
case V_203 : {
struct V_204 * V_205 = ( void * ) V_134 ;
if ( V_39 -> V_13 ) {
F_10 ( V_2 ,
L_18 ) ;
break;
}
V_39 -> V_13 = V_205 ;
F_38 ( V_2 , L_19 ,
F_39 ( V_205 -> V_206 ) ) ;
V_2 -> V_12 . V_207 =
V_130 - F_40 ( struct V_204 ,
V_208 ) ;
V_2 -> V_12 . V_207 /=
sizeof( V_2 -> V_12 . V_13 -> V_208 [ 0 ] ) ;
break;
}
case V_209 : {
struct V_210 * V_211 = ( void * ) V_134 ;
if ( ! V_39 -> V_13 ) {
F_10 ( V_2 ,
L_20 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_212 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_10 ( V_2 ,
L_21 ,
V_211 -> V_212 ) ;
break;
}
if ( V_39 -> V_14 [ V_211 -> V_212 ] ) {
F_10 ( V_2 ,
L_22 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_213 )
V_137 = true ;
F_38 ( V_2 , L_23 ,
V_211 -> V_212 ) ;
V_39 -> V_14 [ V_211 -> V_212 ] = V_211 ;
V_39 -> V_214 [ V_211 -> V_212 ] = V_130 ;
break;
}
case V_215 : {
struct V_216 * V_217 =
( void * ) V_134 ;
T_2 V_218 = F_19 ( V_217 -> V_212 ) ;
if ( V_218 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_10 ( V_2 ,
L_24 ,
V_217 -> V_212 ) ;
break;
}
if ( V_39 -> V_15 [ V_218 ] ) {
F_10 ( V_2 ,
L_25 ,
V_217 -> V_212 ) ;
break;
}
F_38 ( V_2 , L_26 , V_217 -> V_212 ) ;
V_39 -> V_15 [ V_218 ] = V_217 ;
V_39 -> V_219 [ V_218 ] = V_130 ;
break;
}
case V_220 :
* V_126 = true ;
F_22 ( V_39 , V_134 ,
V_221 ,
V_130 ) ;
break;
case V_222 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_135 = F_37 ( ( V_150 * ) V_134 ) ;
F_41 ( V_2 ,
L_27 ,
V_135 ) ;
if ( V_135 > V_223 ) {
F_10 ( V_2 ,
L_28 ,
V_223 ) ;
return - V_20 ;
}
if ( V_135 & ( V_224 - 1 ) ) {
F_10 ( V_2 ,
L_29 ,
V_224 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_8 [ V_114 ] . V_135 =
V_135 ;
V_131 = V_221 ;
V_2 -> V_12 . V_8 [ V_131 ] . V_135 =
V_135 ;
break;
case V_225 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_2 -> V_12 . V_226 =
F_37 ( ( V_150 * ) V_134 ) ;
break;
case V_227 :
if ( V_130 < sizeof( struct V_60 ) )
break;
F_21 ( & V_2 -> V_12 , V_134 , V_130 ) ;
V_64 = true ;
break;
case V_228 : {
struct V_229 * V_230 =
( void * ) V_134 ;
T_2 type ;
if ( V_130 != ( sizeof( * V_230 ) ) )
goto V_148;
type = F_19 ( V_230 -> V_231 ) ;
V_2 -> V_12 . V_232 = true ;
if ( type >= F_6 ( V_2 -> V_12 . V_16 ) ) {
F_10 ( V_2 ,
L_30 ,
V_230 -> V_231 ) ;
break;
}
if ( V_39 -> V_16 [ type ] ) {
F_10 ( V_2 ,
L_31 ,
V_230 -> V_231 ) ;
break;
}
F_11 ( V_2 , L_32 ,
V_230 -> V_231 ) ;
V_39 -> V_16 [ type ] = V_230 ;
break;
}
default:
F_11 ( V_2 , L_33 , V_133 ) ;
break;
}
}
if ( ! F_42 ( V_63 , V_233 ) &&
V_137 && ! * V_126 ) {
F_10 ( V_2 ,
L_34 ) ;
return - V_20 ;
}
if ( V_6 ) {
F_10 ( V_2 , L_35 , V_6 ) ;
F_43 ( V_2 , V_234 , ( T_3 * ) V_5 , V_6 ) ;
return - V_20 ;
}
if ( F_42 ( V_63 , V_235 ) &&
! V_64 ) {
F_11 ( V_2 ,
L_36 ) ;
F_44 ( ( V_236 long ) V_235 ,
V_63 -> V_100 ) ;
}
return 0 ;
V_148:
F_10 ( V_2 , L_37 , V_133 , V_130 ) ;
V_156:
F_43 ( V_2 , V_234 , V_134 , V_130 ) ;
return - V_20 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
enum V_40 type )
{
int V_9 ;
for ( V_9 = 0 ;
V_9 < V_10 && F_16 ( V_39 , type , V_9 ) ;
V_9 ++ )
if ( F_7 ( V_2 , & ( V_2 -> V_12 . V_8 [ type ] . V_11 [ V_9 ] ) ,
F_13 ( V_39 , type , V_9 ) ) )
return - V_21 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_237 * V_25 )
{
F_11 ( V_2 , L_38 ,
F_16 ( V_39 , V_114 ,
V_115 ) ) ;
F_11 ( V_2 , L_39 ,
F_16 ( V_39 , V_114 ,
V_117 ) ) ;
F_11 ( V_2 , L_40 ,
F_16 ( V_39 , V_119 , V_115 ) ) ;
F_11 ( V_2 , L_41 ,
F_16 ( V_39 , V_119 , V_117 ) ) ;
if ( F_16 ( V_39 , V_114 , V_115 ) >
V_25 -> V_238 ) {
F_10 ( V_2 , L_42 ,
F_16 ( V_39 , V_114 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_114 , V_117 ) >
V_25 -> V_239 ) {
F_10 ( V_2 , L_43 ,
F_16 ( V_39 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_119 , V_115 ) >
V_25 -> V_238 ) {
F_10 ( V_2 , L_44 ,
F_16 ( V_39 , V_119 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_119 , V_117 ) >
V_25 -> V_239 ) {
F_10 ( V_2 , L_45 ,
F_16 ( V_39 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_240 *
F_47 ( struct V_1 * V_2 , struct V_241 * V_242 )
{
const struct V_243 * V_244 = V_242 -> V_244 ;
struct V_245 * V_246 = NULL ;
struct V_240 * V_247 = NULL ;
#ifdef F_48
V_2 -> V_248 = F_49 ( V_242 -> V_249 ,
V_2 -> V_250 ) ;
if ( ! V_2 -> V_248 ) {
F_10 ( V_2 ,
L_46 ) ;
return V_247 ;
}
V_246 = V_2 -> V_248 ;
#endif
V_247 = V_244 -> V_251 ( V_2 -> V_34 , V_2 -> V_25 , & V_2 -> V_12 , V_246 ) ;
#ifdef F_48
if ( ! V_247 ) {
F_50 ( V_2 -> V_248 ) ;
V_2 -> V_248 = NULL ;
}
#endif
return V_247 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_247 ) {
F_52 ( V_2 -> V_247 ) ;
V_2 -> V_247 = NULL ;
#ifdef F_48
F_50 ( V_2 -> V_248 ) ;
V_2 -> V_248 = NULL ;
#endif
}
}
static void V_37 ( const struct V_101 * V_102 , void * V_252 )
{
struct V_1 * V_2 = V_252 ;
struct V_41 * V_12 = & V_2 -> V_12 ;
struct V_103 * V_104 ;
struct V_241 * V_242 ;
int V_253 ;
struct V_38 * V_39 ;
const unsigned int V_254 = V_2 -> V_25 -> V_29 ;
const unsigned int V_255 = V_2 -> V_25 -> V_30 ;
T_1 V_256 [ V_257 ] ;
T_2 V_105 ;
int V_9 ;
bool V_258 = false ;
bool V_126 = false ;
V_12 -> V_97 . V_149 = V_259 ;
V_12 -> V_97 . V_176 =
V_260 ;
V_12 -> V_97 . V_197 = V_261 ;
V_39 = F_53 ( sizeof( * V_39 ) , V_36 ) ;
if ( ! V_39 )
return;
if ( ! V_102 )
goto V_262;
F_11 ( V_2 , L_47 ,
V_2 -> V_32 , V_102 -> V_19 ) ;
if ( V_102 -> V_19 < 4 ) {
F_10 ( V_2 , L_48 ) ;
goto V_262;
}
V_104 = (struct V_103 * ) V_102 -> V_5 ;
if ( V_104 -> V_111 )
V_253 = F_29 ( V_2 , V_102 , V_39 ) ;
else
V_253 = F_34 ( V_2 , V_102 , V_39 ,
& V_12 -> V_97 , & V_126 ) ;
if ( V_253 )
goto V_262;
if ( F_54 ( & V_2 -> V_12 . V_97 , V_263 ) )
V_105 = V_2 -> V_12 . V_110 ;
else
V_105 = F_30 ( V_2 -> V_12 . V_110 ) ;
if ( V_105 < V_255 || V_105 > V_254 ) {
F_10 ( V_2 ,
L_49
L_50 ,
V_254 , V_105 ) ;
goto V_262;
}
if ( ! V_12 -> V_178 && F_46 ( V_2 , V_39 , V_2 -> V_25 ) )
goto V_262;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
if ( F_45 ( V_2 , V_39 , V_9 ) )
goto V_264;
if ( V_39 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_55 ( V_39 -> V_13 ,
sizeof( * V_39 -> V_13 ) +
sizeof( V_39 -> V_13 -> V_208 [ 0 ] ) *
V_2 -> V_12 . V_207 , V_36 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_264;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_39 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_214 [ V_9 ] =
V_39 -> V_214 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_55 ( V_39 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_214 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_264;
}
}
memset ( & V_256 , 0xff , sizeof( V_256 ) ) ;
V_256 [ V_265 ] =
sizeof( struct V_266 ) ;
V_256 [ V_267 ] = 0 ;
V_256 [ V_268 ] =
sizeof( struct V_269 ) ;
V_256 [ V_270 ] =
sizeof( struct V_271 ) ;
V_256 [ V_272 ] =
sizeof( struct V_273 ) ;
V_256 [ V_274 ] =
sizeof( struct V_275 ) ;
V_256 [ V_276 ] =
sizeof( struct V_277 ) ;
V_256 [ V_278 ] =
sizeof( struct V_279 ) ;
V_256 [ V_280 ] =
sizeof( struct V_281 ) ;
V_256 [ V_282 ] =
sizeof( struct V_283 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_39 -> V_15 [ V_9 ] ) {
if ( F_23 ( V_39 -> V_219 [ V_9 ] <
( V_256 [ V_9 ] +
sizeof( struct V_216 ) ) ) )
goto V_264;
V_2 -> V_12 . V_219 [ V_9 ] =
V_39 -> V_219 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_55 ( V_39 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_219 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_264;
}
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_16 ) ; V_9 ++ ) {
if ( V_39 -> V_16 [ V_9 ] ) {
V_2 -> V_12 . V_16 [ V_9 ] =
F_55 ( V_39 -> V_16 [ V_9 ] ,
sizeof( * V_2 -> V_12 . V_16 [ V_9 ] ) ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_16 [ V_9 ] )
goto V_264;
}
}
V_12 -> V_159 = V_39 -> V_159 ;
if ( V_39 -> V_161 )
V_12 -> V_161 = ( V_39 -> V_161 - 16 ) / 12 ;
else
V_12 -> V_161 =
V_2 -> V_25 -> V_284 -> V_285 ;
V_12 -> V_163 = V_39 -> V_163 ;
V_12 -> V_165 = V_39 -> V_165 ;
if ( V_39 -> V_167 )
V_12 -> V_167 = ( V_39 -> V_167 - 16 ) / 12 ;
else
V_12 -> V_167 =
V_2 -> V_25 -> V_284 -> V_285 ;
V_12 -> V_169 = V_39 -> V_169 ;
if ( V_12 -> V_97 . V_176 >
V_286 )
V_12 -> V_97 . V_176 =
V_287 ;
F_56 ( V_102 ) ;
F_57 ( & V_288 ) ;
if ( V_12 -> V_178 )
V_242 = & V_241 [ V_289 ] ;
else
V_242 = & V_241 [ V_290 ] ;
F_38 ( V_2 , L_51 ,
V_2 -> V_12 . V_123 , V_242 -> V_249 ) ;
F_58 ( & V_2 -> V_291 , & V_242 -> V_2 ) ;
if ( V_242 -> V_244 ) {
V_2 -> V_247 = F_47 ( V_2 , V_242 ) ;
if ( ! V_2 -> V_247 ) {
F_59 ( & V_288 ) ;
goto V_292;
}
} else {
V_258 = true ;
}
F_59 ( & V_288 ) ;
F_60 ( & V_2 -> V_293 ) ;
if ( V_258 ) {
V_253 = F_61 ( L_52 , V_242 -> V_249 ) ;
#ifdef F_62
if ( V_253 )
F_10 ( V_2 ,
L_53 ,
V_242 -> V_249 , V_253 ) ;
#endif
}
F_5 ( V_39 ) ;
return;
V_262:
F_56 ( V_102 ) ;
if ( F_9 ( V_2 , false ) )
goto V_292;
F_5 ( V_39 ) ;
return;
V_264:
F_10 ( V_2 , L_54 ) ;
F_4 ( V_2 ) ;
F_56 ( V_102 ) ;
V_292:
F_5 ( V_39 ) ;
F_60 ( & V_2 -> V_293 ) ;
F_63 ( V_2 -> V_34 -> V_35 ) ;
}
struct V_1 * F_64 ( struct V_294 * V_34 ,
const struct V_237 * V_25 )
{
struct V_1 * V_2 ;
int V_295 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 ) {
V_295 = - V_21 ;
goto V_253;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_35 = V_34 -> V_35 ;
V_2 -> V_25 = V_25 ;
F_65 ( & V_2 -> V_293 ) ;
F_66 ( & V_2 -> V_291 ) ;
#ifdef F_48
V_2 -> V_250 = F_49 ( F_67 ( V_34 -> V_35 ) ,
V_296 ) ;
if ( ! V_2 -> V_250 ) {
F_10 ( V_2 , L_55 ) ;
V_295 = - V_21 ;
goto V_297;
}
V_2 -> V_34 -> V_246 = F_49 ( L_56 , V_2 -> V_250 ) ;
if ( ! V_2 -> V_34 -> V_246 ) {
F_10 ( V_2 , L_57 ) ;
V_295 = - V_21 ;
goto V_298;
}
#endif
V_295 = F_9 ( V_2 , true ) ;
if ( V_295 ) {
F_10 ( V_34 , L_58 ) ;
goto V_299;
}
return V_2 ;
V_299:
#ifdef F_48
V_298:
F_50 ( V_2 -> V_250 ) ;
V_297:
#endif
F_5 ( V_2 ) ;
V_253:
return F_68 ( V_295 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_70 ( & V_2 -> V_293 ) ;
F_51 ( V_2 ) ;
F_4 ( V_2 ) ;
F_57 ( & V_288 ) ;
if ( ! F_71 ( & V_2 -> V_291 ) )
F_72 ( & V_2 -> V_291 ) ;
F_59 ( & V_288 ) ;
#ifdef F_48
F_50 ( V_2 -> V_250 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_73 ( const char * V_249 , const struct V_243 * V_244 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_241 * V_242 ;
F_57 ( & V_288 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_241 ) ; V_9 ++ ) {
V_242 = & V_241 [ V_9 ] ;
if ( strcmp ( V_242 -> V_249 , V_249 ) )
continue;
V_242 -> V_244 = V_244 ;
F_74 (drv, &op->drv, list)
V_2 -> V_247 = F_47 ( V_2 , V_242 ) ;
F_59 ( & V_288 ) ;
return 0 ;
}
F_59 ( & V_288 ) ;
return - V_300 ;
}
void F_75 ( const char * V_249 )
{
int V_9 ;
struct V_1 * V_2 ;
F_57 ( & V_288 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_241 ) ; V_9 ++ ) {
if ( strcmp ( V_241 [ V_9 ] . V_249 , V_249 ) )
continue;
V_241 [ V_9 ] . V_244 = NULL ;
F_74 (drv, &iwlwifi_opmode_table[i].drv, list)
F_51 ( V_2 ) ;
F_59 ( & V_288 ) ;
return;
}
F_59 ( & V_288 ) ;
}
static int T_4 F_76 ( void )
{
int V_9 ;
F_77 ( & V_288 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_241 ) ; V_9 ++ )
F_66 ( & V_241 [ V_9 ] . V_2 ) ;
F_78 ( V_301 L_59 ) ;
F_78 ( V_302 L_59 ) ;
#ifdef F_48
V_296 = F_49 ( V_303 , NULL ) ;
if ( ! V_296 )
return - V_304 ;
#endif
return F_79 () ;
}
static void T_5 F_80 ( void )
{
F_81 () ;
#ifdef F_48
F_50 ( V_296 ) ;
#endif
}
