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
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
F_3 ( V_2 , V_2 -> V_12 . V_8 + V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_17 * V_11 )
{
void * V_5 ;
V_4 -> V_5 = NULL ;
if ( ! V_11 || ! V_11 -> V_18 )
return - V_19 ;
V_5 = F_8 ( V_11 -> V_18 ) ;
if ( ! V_5 )
return - V_20 ;
V_4 -> V_6 = V_11 -> V_18 ;
V_4 -> V_21 = V_11 -> V_21 ;
memcpy ( V_5 , V_11 -> V_5 , V_4 -> V_6 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_22 )
{
const char * V_23 = V_2 -> V_24 -> V_25 ;
char V_26 [ 8 ] ;
if ( V_22 ) {
#ifdef F_10
V_2 -> V_27 = V_28 ;
strcpy ( V_26 , V_29 ) ;
} else if ( V_2 -> V_27 == V_28 ) {
#endif
V_2 -> V_27 = V_2 -> V_24 -> V_30 ;
sprintf ( V_26 , L_1 , V_2 -> V_27 ) ;
} else {
V_2 -> V_27 -- ;
sprintf ( V_26 , L_1 , V_2 -> V_27 ) ;
}
if ( V_2 -> V_27 < V_2 -> V_24 -> V_31 ) {
F_11 ( V_2 , L_2 ) ;
return - V_32 ;
}
snprintf ( V_2 -> V_33 , sizeof( V_2 -> V_33 ) , L_3 ,
V_23 , V_26 ) ;
if ( V_2 -> V_34 -> V_24 -> V_35 == V_36 ) {
char V_37 = 'A' + F_12 ( V_2 -> V_34 -> V_38 ) ;
snprintf ( V_2 -> V_33 , sizeof( V_2 -> V_33 ) ,
L_4 , V_23 , V_37 , V_26 ) ;
}
F_13 ( V_2 , L_5 ,
( V_2 -> V_27 == V_28 )
? L_6 : L_7 ,
V_2 -> V_33 ) ;
return F_14 ( V_39 , 1 , V_2 -> V_33 ,
V_2 -> V_34 -> V_40 ,
V_41 , V_2 , V_42 ) ;
}
static struct V_17 * F_15 ( struct V_43 * V_44 ,
enum V_45 type ,
int V_11 )
{
return & V_44 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_16 ( struct V_43 * V_44 ,
enum V_45 type ,
int V_11 ,
const void * V_5 )
{
V_44 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_17 ( struct V_43 * V_44 ,
enum V_45 type ,
int V_11 ,
T_1 V_18 )
{
V_44 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 = V_18 ;
}
static T_1 F_18 ( struct V_43 * V_44 ,
enum V_45 type ,
int V_11 )
{
return V_44 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 ;
}
static void F_19 ( struct V_43 * V_44 ,
enum V_45 type ,
int V_11 ,
T_2 V_21 )
{
V_44 -> V_8 [ type ] . V_11 [ V_11 ] . V_21 = V_21 ;
}
static int F_20 ( struct V_46 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_47 ;
struct V_48 * V_49 = (struct V_48 * ) V_5 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_2 V_54 ;
if ( V_6 < sizeof( * V_49 ) ||
V_6 < sizeof( V_49 -> V_18 ) + V_49 -> V_18 * sizeof( V_49 -> V_53 [ 0 ] ) )
return - V_19 ;
for ( V_9 = 0 , V_47 = 0 ; V_9 < V_55 && V_9 < V_49 -> V_18 ; V_9 ++ ) {
V_51 = & V_49 -> V_53 [ V_47 ] ;
V_54 = F_21 ( V_51 -> V_54 ) ;
if ( ! V_54 )
continue;
V_53 = & V_12 -> V_53 [ V_47 ++ ] ;
V_53 -> V_54 = V_54 ;
V_53 -> V_56 = F_22 ( V_57 ) ;
V_53 -> V_58 = V_51 -> V_58 ;
V_53 -> V_59 = V_51 -> V_59 ;
V_53 -> V_60 = V_51 -> V_60 ;
V_53 -> V_61 = V_51 -> V_61 ;
V_53 -> V_62 = V_51 -> V_62 ;
V_53 -> V_63 = V_51 -> V_63 ;
V_53 -> V_64 = V_51 -> V_64 ;
}
return 0 ;
}
static int F_23 ( struct V_46 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_65 * V_66 = ( void * ) V_5 ;
struct V_67 * V_68 = & V_12 -> V_69 ;
if ( V_6 < sizeof( * V_66 ) )
return - V_19 ;
V_68 -> V_70 = F_21 ( V_66 -> V_70 ) ;
V_68 -> V_71 = F_21 ( V_66 -> V_71 ) ;
V_68 -> V_72 =
F_21 ( V_66 -> V_72 ) ;
V_68 -> V_73 = F_21 ( V_66 -> V_73 ) ;
V_68 -> V_74 =
F_21 ( V_66 -> V_74 ) ;
V_68 -> V_75 = F_21 ( V_66 -> V_75 ) ;
V_68 -> V_76 =
F_21 ( V_66 -> V_76 ) ;
V_68 -> V_77 =
F_21 ( V_66 -> V_77 ) ;
return 0 ;
}
static int F_24 ( struct V_43 * V_44 ,
const void * V_5 , enum V_45 type ,
int V_18 )
{
struct V_78 * V_8 ;
struct V_17 * V_11 ;
struct V_79 * V_80 ;
if ( F_25 ( ! V_44 || ! V_5 || type >= V_16 ) )
return - 1 ;
V_80 = (struct V_79 * ) V_5 ;
V_8 = & V_44 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_81 ] ;
V_11 -> V_21 = F_21 ( V_80 -> V_21 ) ;
V_11 -> V_5 = V_80 -> V_5 ;
V_11 -> V_18 = V_18 - sizeof( V_80 -> V_21 ) ;
++ V_8 -> V_81 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_82 * V_83 =
(struct V_82 * ) V_5 ;
T_2 V_84 = F_21 ( V_83 -> V_84 ) ;
if ( V_84 >= V_16 ) {
F_11 ( V_2 , L_8 ,
V_84 ) ;
return - V_19 ;
}
V_2 -> V_12 . V_85 [ V_84 ] . V_86 =
V_83 -> V_87 . V_86 ;
V_2 -> V_12 . V_85 [ V_84 ] . V_88 =
V_83 -> V_87 . V_88 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_89 * V_68 )
{
const struct V_90 * V_91 = ( void * ) V_5 ;
T_2 V_92 = F_21 ( V_91 -> V_92 ) ;
T_2 V_93 = F_21 ( V_91 -> V_93 ) ;
int V_9 ;
if ( V_92 >= V_94 / 32 ) {
F_11 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_22 ( V_9 ) )
F_28 ( V_9 + 32 * V_92 , V_68 -> V_95 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_89 * V_68 )
{
const struct V_96 * V_97 = ( void * ) V_5 ;
T_2 V_92 = F_21 ( V_97 -> V_92 ) ;
T_2 V_93 = F_21 ( V_97 -> V_98 ) ;
int V_9 ;
if ( V_92 >= V_99 / 32 ) {
F_11 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_22 ( V_9 ) )
F_28 ( V_9 + 32 * V_92 , V_68 -> V_100 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = ( void * ) V_102 -> V_5 ;
T_2 V_105 , V_106 , V_107 ;
char V_108 [ 25 ] ;
const T_3 * V_109 ;
V_2 -> V_12 . V_110 = F_21 ( V_104 -> V_111 ) ;
V_105 = F_31 ( V_2 -> V_12 . V_110 ) ;
switch ( V_105 ) {
default:
V_106 = 28 ;
if ( V_102 -> V_18 < V_106 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_107 = F_21 ( V_104 -> V_112 . V_113 . V_107 ) ;
F_17 ( V_44 , V_114 , V_115 ,
F_21 ( V_104 -> V_112 . V_113 . V_116 ) ) ;
F_17 ( V_44 , V_114 , V_117 ,
F_21 ( V_104 -> V_112 . V_113 . V_118 ) ) ;
F_17 ( V_44 , V_119 , V_115 ,
F_21 ( V_104 -> V_112 . V_113 . V_120 ) ) ;
F_17 ( V_44 , V_119 , V_117 ,
F_21 ( V_104 -> V_112 . V_113 . V_121 ) ) ;
V_109 = V_104 -> V_112 . V_113 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_106 = 24 ;
if ( V_102 -> V_18 < V_106 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_107 = 0 ;
F_17 ( V_44 , V_114 , V_115 ,
F_21 ( V_104 -> V_112 . V_122 . V_116 ) ) ;
F_17 ( V_44 , V_114 , V_117 ,
F_21 ( V_104 -> V_112 . V_122 . V_118 ) ) ;
F_17 ( V_44 , V_119 , V_115 ,
F_21 ( V_104 -> V_112 . V_122 . V_120 ) ) ;
F_17 ( V_44 , V_119 , V_117 ,
F_21 ( V_104 -> V_112 . V_122 . V_121 ) ) ;
V_109 = V_104 -> V_112 . V_122 . V_5 ;
break;
}
if ( V_107 )
sprintf ( V_108 , L_11 , V_107 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_13 ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_33 ( V_2 -> V_12 . V_110 ) ,
F_31 ( V_2 -> V_12 . V_110 ) ,
F_34 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
if ( V_102 -> V_18 != V_106 +
F_18 ( V_44 , V_114 , V_115 ) +
F_18 ( V_44 , V_114 , V_117 ) +
F_18 ( V_44 , V_119 , V_115 ) +
F_18 ( V_44 , V_119 , V_117 ) ) {
F_11 ( V_2 ,
L_14 ,
( int ) V_102 -> V_18 ) ;
return - V_19 ;
}
F_16 ( V_44 , V_114 , V_115 , V_109 ) ;
V_109 += F_18 ( V_44 , V_114 , V_115 ) ;
F_19 ( V_44 , V_114 , V_115 ,
V_124 ) ;
F_16 ( V_44 , V_114 , V_117 , V_109 ) ;
V_109 += F_18 ( V_44 , V_114 , V_117 ) ;
F_19 ( V_44 , V_114 , V_117 ,
V_125 ) ;
F_16 ( V_44 , V_119 , V_115 , V_109 ) ;
V_109 += F_18 ( V_44 , V_119 , V_115 ) ;
F_19 ( V_44 , V_119 , V_115 ,
V_124 ) ;
F_16 ( V_44 , V_119 , V_117 , V_109 ) ;
V_109 += F_18 ( V_44 , V_119 , V_117 ) ;
F_19 ( V_44 , V_119 , V_117 ,
V_125 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_43 * V_44 ,
struct V_89 * V_68 )
{
struct V_126 * V_104 = ( void * ) V_102 -> V_5 ;
struct V_127 * V_128 ;
T_1 V_6 = V_102 -> V_18 ;
const T_3 * V_5 ;
T_2 V_129 ;
T_2 V_130 ;
enum V_131 V_132 ;
const T_3 * V_133 ;
char V_108 [ 25 ] ;
T_2 V_107 , V_134 ;
int V_135 ;
bool V_136 = false ;
bool V_137 = false ;
bool V_69 = false ;
if ( V_6 < sizeof( * V_104 ) ) {
F_11 ( V_2 , L_15 , V_6 ) ;
return - V_19 ;
}
if ( V_104 -> V_138 != F_36 ( V_139 ) ) {
F_11 ( V_2 , L_16 ,
F_21 ( V_104 -> V_138 ) ) ;
return - V_19 ;
}
V_2 -> V_12 . V_110 = F_21 ( V_104 -> V_111 ) ;
memcpy ( V_2 -> V_12 . V_140 , V_104 -> V_140 ,
sizeof( V_2 -> V_12 . V_140 ) ) ;
V_107 = F_21 ( V_104 -> V_107 ) ;
if ( V_107 )
sprintf ( V_108 , L_11 , V_107 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_13 ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_33 ( V_2 -> V_12 . V_110 ) ,
F_31 ( V_2 -> V_12 . V_110 ) ,
F_34 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
V_5 = V_104 -> V_5 ;
V_6 -= sizeof( * V_104 ) ;
while ( V_6 >= sizeof( * V_128 ) ) {
V_6 -= sizeof( * V_128 ) ;
V_128 = ( void * ) V_5 ;
V_129 = F_21 ( V_128 -> V_141 ) ;
V_132 = F_21 ( V_128 -> type ) ;
V_133 = V_128 -> V_5 ;
if ( V_6 < V_129 ) {
F_11 ( V_2 , L_17 ,
V_6 , V_129 ) ;
return - V_19 ;
}
V_6 -= F_37 ( V_129 , 4 ) ;
V_5 += sizeof( * V_128 ) + F_37 ( V_129 , 4 ) ;
switch ( V_132 ) {
case V_142 :
F_16 ( V_44 , V_114 ,
V_115 , V_133 ) ;
F_17 ( V_44 , V_114 ,
V_115 , V_129 ) ;
F_19 ( V_44 , V_114 ,
V_115 ,
V_124 ) ;
break;
case V_143 :
F_16 ( V_44 , V_114 ,
V_117 , V_133 ) ;
F_17 ( V_44 , V_114 ,
V_117 , V_129 ) ;
F_19 ( V_44 , V_114 ,
V_117 ,
V_125 ) ;
break;
case V_144 :
F_16 ( V_44 , V_119 ,
V_115 , V_133 ) ;
F_17 ( V_44 , V_119 ,
V_115 , V_129 ) ;
F_19 ( V_44 , V_119 ,
V_115 ,
V_124 ) ;
break;
case V_145 :
F_16 ( V_44 , V_119 ,
V_117 , V_133 ) ;
F_17 ( V_44 , V_119 ,
V_117 , V_129 ) ;
F_19 ( V_44 , V_119 ,
V_117 ,
V_125 ) ;
break;
case V_146 :
F_11 ( V_2 , L_18 ) ;
break;
case V_147 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_149 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_151 :
if ( V_129 )
goto V_148;
V_68 -> V_152 |= V_153 ;
break;
case V_154 :
if ( V_129 < sizeof( T_2 ) )
goto V_148;
if ( V_129 % sizeof( T_2 ) )
goto V_148;
V_68 -> V_152 = F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_155 :
if ( V_129 != sizeof( struct V_90 ) )
goto V_148;
if ( F_27 ( V_2 , V_133 , V_68 ) )
goto V_156;
break;
case V_157 :
if ( V_129 != sizeof( struct V_96 ) )
goto V_148;
if ( F_29 ( V_2 , V_133 , V_68 ) )
goto V_156;
break;
case V_158 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_159 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_160 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_161 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_162 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_163 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_164 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_165 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_166 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_167 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_168 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_169 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_170 :
if ( V_129 )
goto V_148;
V_2 -> V_12 . V_171 = true ;
break;
case V_172 :
F_16 ( V_44 , V_173 ,
V_115 , V_133 ) ;
F_17 ( V_44 , V_173 ,
V_115 , V_129 ) ;
F_19 ( V_44 , V_173 ,
V_115 ,
V_124 ) ;
break;
case V_174 :
F_16 ( V_44 , V_173 ,
V_117 , V_133 ) ;
F_17 ( V_44 , V_173 ,
V_117 , V_129 ) ;
F_19 ( V_44 , V_173 ,
V_117 ,
V_125 ) ;
break;
case V_175 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_176 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_177 :
F_24 ( V_44 , V_133 , V_114 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_179 :
F_24 ( V_44 , V_133 , V_119 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_180 :
F_24 ( V_44 , V_133 , V_173 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_181 :
if ( V_129 != sizeof( struct V_82 ) )
goto V_148;
if ( F_26 ( V_2 , V_133 ) )
goto V_156;
break;
case V_182 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_2 -> V_12 . V_183 = F_38 ( ( V_150 * ) V_133 ) ;
V_2 -> V_12 . V_184 = ( V_2 -> V_12 . V_183 &
V_185 ) >>
V_186 ;
V_2 -> V_12 . V_187 = ( V_2 -> V_12 . V_183 &
V_188 ) >>
V_189 ;
break;
case V_190 :
F_24 ( V_44 , V_133 , V_114 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_191 :
F_24 ( V_44 , V_133 , V_119 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_192 :
F_24 ( V_44 , V_133 , V_173 ,
V_129 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_193 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_135 =
F_38 ( ( V_150 * ) V_133 ) ;
if ( V_135 == 2 ) {
V_2 -> V_12 . V_8 [ V_114 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_119 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_173 ] . V_194 =
true ;
} else if ( ( V_135 > 2 ) || ( V_135 < 1 ) ) {
F_11 ( V_2 , L_19 ) ;
return - V_19 ;
}
break;
case V_195 :
if ( F_20 ( & V_2 -> V_12 , V_133 , V_129 ) )
goto V_148;
break;
case V_196 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_197 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_198 : {
V_150 * V_199 = ( void * ) V_133 ;
T_2 V_200 , V_201 ;
T_3 V_202 ;
if ( V_129 != sizeof( T_2 ) * 3 )
goto V_148;
V_200 = F_38 ( V_199 ++ ) ;
V_201 = F_38 ( V_199 ++ ) ;
V_202 = F_38 ( V_199 ) ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) , L_20 ,
V_200 , V_201 , V_202 ) ;
break;
}
case V_203 : {
struct V_204 * V_205 = ( void * ) V_133 ;
if ( V_44 -> V_13 ) {
F_11 ( V_2 ,
L_21 ) ;
break;
}
V_44 -> V_13 = V_205 ;
F_39 ( V_2 , L_22 ,
F_40 ( V_205 -> V_206 ) ) ;
V_2 -> V_12 . V_207 =
V_129 - F_41 ( struct V_204 ,
V_208 ) ;
V_2 -> V_12 . V_207 /=
sizeof( V_2 -> V_12 . V_13 -> V_208 [ 0 ] ) ;
break;
}
case V_209 : {
struct V_210 * V_211 = ( void * ) V_133 ;
if ( ! V_44 -> V_13 ) {
F_11 ( V_2 ,
L_23 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_212 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_24 ,
V_211 -> V_212 ) ;
break;
}
if ( V_44 -> V_14 [ V_211 -> V_212 ] ) {
F_11 ( V_2 ,
L_25 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_213 )
V_137 = true ;
F_39 ( V_2 , L_26 ,
V_211 -> V_212 ) ;
V_44 -> V_14 [ V_211 -> V_212 ] = V_211 ;
V_44 -> V_214 [ V_211 -> V_212 ] = V_129 ;
break;
}
case V_215 : {
struct V_216 * V_217 =
( void * ) V_133 ;
T_2 V_218 = F_21 ( V_217 -> V_212 ) ;
if ( V_218 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_27 ,
V_217 -> V_212 ) ;
break;
}
if ( V_44 -> V_15 [ V_218 ] ) {
F_11 ( V_2 ,
L_28 ,
V_217 -> V_212 ) ;
break;
}
F_39 ( V_2 , L_29 , V_217 -> V_212 ) ;
V_44 -> V_15 [ V_218 ] = V_217 ;
V_44 -> V_219 [ V_218 ] = V_129 ;
break;
}
case V_220 :
V_136 = true ;
F_24 ( V_44 , V_133 ,
V_221 ,
V_129 ) ;
break;
case V_222 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_134 = F_38 ( ( V_150 * ) V_133 ) ;
F_42 ( V_2 ,
L_30 ,
V_134 ) ;
if ( V_134 > V_223 ) {
F_11 ( V_2 ,
L_31 ,
V_223 ) ;
return - V_19 ;
}
if ( V_134 & ( V_224 - 1 ) ) {
F_11 ( V_2 ,
L_32 ,
V_224 ) ;
return - V_19 ;
}
V_2 -> V_12 . V_8 [ V_114 ] . V_134 =
V_134 ;
V_130 = V_221 ;
V_2 -> V_12 . V_8 [ V_130 ] . V_134 =
V_134 ;
break;
case V_225 :
if ( V_129 != sizeof( T_2 ) )
goto V_148;
V_2 -> V_12 . V_226 =
F_38 ( ( V_150 * ) V_133 ) ;
break;
case V_227 :
if ( F_23 ( & V_2 -> V_12 , V_133 , V_129 ) )
goto V_148;
V_69 = true ;
break;
default:
F_13 ( V_2 , L_33 , V_132 ) ;
break;
}
}
if ( V_137 && ! V_136 ) {
F_11 ( V_2 ,
L_34 ) ;
return - V_19 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_35 , V_6 ) ;
F_43 ( V_2 , V_228 , ( T_3 * ) V_5 , V_6 ) ;
return - V_19 ;
}
if ( F_44 ( V_68 , V_229 ) &&
F_45 ( ! V_69 ,
L_36 ) )
F_46 ( ( V_230 long ) V_229 ,
V_68 -> V_100 ) ;
return 0 ;
V_148:
F_11 ( V_2 , L_37 , V_132 , V_129 ) ;
V_156:
F_43 ( V_2 , V_228 , V_133 , V_129 ) ;
return - V_19 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
enum V_45 type )
{
int V_9 ;
for ( V_9 = 0 ;
V_9 < V_10 && F_18 ( V_44 , type , V_9 ) ;
V_9 ++ )
if ( F_7 ( V_2 , & ( V_2 -> V_12 . V_8 [ type ] . V_11 [ V_9 ] ) ,
F_15 ( V_44 , type , V_9 ) ) )
return - V_20 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
const struct V_231 * V_24 )
{
F_13 ( V_2 , L_38 ,
F_18 ( V_44 , V_114 ,
V_115 ) ) ;
F_13 ( V_2 , L_39 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
F_13 ( V_2 , L_40 ,
F_18 ( V_44 , V_119 , V_115 ) ) ;
F_13 ( V_2 , L_41 ,
F_18 ( V_44 , V_119 , V_117 ) ) ;
if ( F_18 ( V_44 , V_114 , V_115 ) >
V_24 -> V_232 ) {
F_11 ( V_2 , L_42 ,
F_18 ( V_44 , V_114 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_114 , V_117 ) >
V_24 -> V_233 ) {
F_11 ( V_2 , L_43 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_119 , V_115 ) >
V_24 -> V_232 ) {
F_11 ( V_2 , L_44 ,
F_18 ( V_44 , V_119 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_119 , V_117 ) >
V_24 -> V_233 ) {
F_11 ( V_2 , L_45 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_234 *
F_49 ( struct V_1 * V_2 , struct V_235 * V_236 )
{
const struct V_237 * V_238 = V_236 -> V_238 ;
struct V_239 * V_240 = NULL ;
struct V_234 * V_241 = NULL ;
#ifdef F_50
V_2 -> V_242 = F_51 ( V_236 -> V_243 ,
V_2 -> V_244 ) ;
if ( ! V_2 -> V_242 ) {
F_11 ( V_2 ,
L_46 ) ;
return V_241 ;
}
V_240 = V_2 -> V_242 ;
#endif
V_241 = V_238 -> V_245 ( V_2 -> V_34 , V_2 -> V_24 , & V_2 -> V_12 , V_240 ) ;
#ifdef F_50
if ( ! V_241 ) {
F_52 ( V_2 -> V_242 ) ;
V_2 -> V_242 = NULL ;
}
#endif
return V_241 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_241 ) {
F_54 ( V_2 -> V_241 ) ;
V_2 -> V_241 = NULL ;
#ifdef F_50
F_52 ( V_2 -> V_242 ) ;
V_2 -> V_242 = NULL ;
#endif
}
}
static void V_42 ( const struct V_101 * V_102 , void * V_246 )
{
struct V_1 * V_2 = V_246 ;
struct V_46 * V_12 = & V_2 -> V_12 ;
struct V_103 * V_104 ;
struct V_235 * V_236 ;
int V_247 ;
struct V_43 * V_44 ;
const unsigned int V_248 = V_2 -> V_24 -> V_30 ;
unsigned int V_249 = V_2 -> V_24 -> V_250 ;
const unsigned int V_251 = V_2 -> V_24 -> V_31 ;
T_1 V_252 [ V_253 ] ;
T_2 V_105 ;
int V_9 ;
bool V_254 = false ;
V_12 -> V_97 . V_149 = V_255 ;
V_12 -> V_97 . V_176 =
V_256 ;
V_12 -> V_97 . V_197 = V_257 ;
if ( ! V_249 )
V_249 = V_248 ;
V_44 = F_55 ( sizeof( * V_44 ) , V_41 ) ;
if ( ! V_44 )
return;
if ( ! V_102 ) {
if ( V_2 -> V_27 <= V_249 )
F_11 ( V_2 ,
L_47 ,
V_2 -> V_33 ) ;
goto V_258;
}
F_13 ( V_2 , L_48 ,
V_2 -> V_33 , V_102 -> V_18 ) ;
if ( V_102 -> V_18 < 4 ) {
F_11 ( V_2 , L_49 ) ;
goto V_258;
}
V_104 = (struct V_103 * ) V_102 -> V_5 ;
if ( V_104 -> V_111 )
V_247 = F_30 ( V_2 , V_102 , V_44 ) ;
else
V_247 = F_35 ( V_2 , V_102 , V_44 ,
& V_12 -> V_97 ) ;
if ( V_247 )
goto V_258;
if ( F_56 ( & V_2 -> V_12 . V_97 , V_259 ) )
V_105 = V_2 -> V_12 . V_110 ;
else
V_105 = F_31 ( V_2 -> V_12 . V_110 ) ;
if ( V_2 -> V_27 != V_28 ) {
if ( V_105 < V_251 || V_105 > V_248 ) {
F_11 ( V_2 ,
L_50
L_51 ,
V_248 , V_105 ) ;
goto V_258;
}
if ( V_105 < V_249 ) {
if ( V_249 != V_248 )
F_11 ( V_2 , L_52
L_53 ,
V_249 , V_248 , V_105 ) ;
else
F_11 ( V_2 , L_52
L_54 ,
V_248 , V_105 ) ;
F_11 ( V_2 , L_55
L_56 ) ;
}
}
if ( ! V_12 -> V_178 && F_48 ( V_2 , V_44 , V_2 -> V_24 ) )
goto V_258;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( F_47 ( V_2 , V_44 , V_9 ) )
goto V_260;
if ( V_44 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_57 ( V_44 -> V_13 ,
sizeof( * V_44 -> V_13 ) +
sizeof( V_44 -> V_13 -> V_208 [ 0 ] ) *
V_2 -> V_12 . V_207 , V_41 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_260;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_44 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_214 [ V_9 ] =
V_44 -> V_214 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_57 ( V_44 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_214 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_260;
}
}
memset ( & V_252 , 0xff , sizeof( V_252 ) ) ;
V_252 [ V_261 ] =
sizeof( struct V_262 ) ;
V_252 [ V_263 ] = 0 ;
V_252 [ V_264 ] =
sizeof( struct V_265 ) ;
V_252 [ V_266 ] =
sizeof( struct V_267 ) ;
V_252 [ V_268 ] =
sizeof( struct V_269 ) ;
V_252 [ V_270 ] =
sizeof( struct V_271 ) ;
V_252 [ V_272 ] =
sizeof( struct V_273 ) ;
V_252 [ V_274 ] =
sizeof( struct V_275 ) ;
V_252 [ V_276 ] =
sizeof( struct V_277 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_44 -> V_15 [ V_9 ] ) {
if ( F_25 ( V_44 -> V_219 [ V_9 ] <
( V_252 [ V_9 ] +
sizeof( struct V_216 ) ) ) )
goto V_260;
V_2 -> V_12 . V_219 [ V_9 ] =
V_44 -> V_219 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_57 ( V_44 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_219 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_260;
}
}
V_12 -> V_159 = V_44 -> V_159 ;
if ( V_44 -> V_161 )
V_12 -> V_161 = ( V_44 -> V_161 - 16 ) / 12 ;
else
V_12 -> V_161 =
V_2 -> V_24 -> V_278 -> V_279 ;
V_12 -> V_163 = V_44 -> V_163 ;
V_12 -> V_165 = V_44 -> V_165 ;
if ( V_44 -> V_167 )
V_12 -> V_167 = ( V_44 -> V_167 - 16 ) / 12 ;
else
V_12 -> V_167 =
V_2 -> V_24 -> V_278 -> V_279 ;
V_12 -> V_169 = V_44 -> V_169 ;
if ( V_12 -> V_97 . V_176 >
V_280 )
V_12 -> V_97 . V_176 =
V_281 ;
F_58 ( V_102 ) ;
F_59 ( & V_282 ) ;
if ( V_12 -> V_178 )
V_236 = & V_235 [ V_283 ] ;
else
V_236 = & V_235 [ V_284 ] ;
F_39 ( V_2 , L_57 ,
V_2 -> V_12 . V_123 , V_236 -> V_243 ) ;
F_60 ( & V_2 -> V_285 , & V_236 -> V_2 ) ;
if ( V_236 -> V_238 ) {
V_2 -> V_241 = F_49 ( V_2 , V_236 ) ;
if ( ! V_2 -> V_241 ) {
F_61 ( & V_282 ) ;
goto V_286;
}
} else {
V_254 = true ;
}
F_61 ( & V_282 ) ;
F_62 ( & V_2 -> V_287 ) ;
if ( V_254 ) {
V_247 = F_63 ( L_58 , V_236 -> V_243 ) ;
#ifdef F_64
if ( V_247 )
F_11 ( V_2 ,
L_59 ,
V_236 -> V_243 , V_247 ) ;
#endif
}
F_5 ( V_44 ) ;
return;
V_258:
F_58 ( V_102 ) ;
if ( F_9 ( V_2 , false ) )
goto V_286;
F_5 ( V_44 ) ;
return;
V_260:
F_11 ( V_2 , L_60 ) ;
F_4 ( V_2 ) ;
F_58 ( V_102 ) ;
V_286:
F_5 ( V_44 ) ;
F_62 ( & V_2 -> V_287 ) ;
F_65 ( V_2 -> V_34 -> V_40 ) ;
}
struct V_1 * F_66 ( struct V_288 * V_34 ,
const struct V_231 * V_24 )
{
struct V_1 * V_2 ;
int V_289 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 ) {
V_289 = - V_20 ;
goto V_247;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_24 = V_24 ;
F_67 ( & V_2 -> V_287 ) ;
F_68 ( & V_2 -> V_285 ) ;
#ifdef F_50
V_2 -> V_244 = F_51 ( F_69 ( V_34 -> V_40 ) ,
V_290 ) ;
if ( ! V_2 -> V_244 ) {
F_11 ( V_2 , L_61 ) ;
V_289 = - V_20 ;
goto V_291;
}
V_2 -> V_34 -> V_240 = F_51 ( L_62 , V_2 -> V_244 ) ;
if ( ! V_2 -> V_34 -> V_240 ) {
F_11 ( V_2 , L_63 ) ;
V_289 = - V_20 ;
goto V_292;
}
#endif
V_289 = F_9 ( V_2 , true ) ;
if ( V_289 ) {
F_11 ( V_34 , L_64 ) ;
goto V_293;
}
return V_2 ;
V_293:
#ifdef F_50
V_292:
F_52 ( V_2 -> V_244 ) ;
V_291:
#endif
F_5 ( V_2 ) ;
V_247:
return F_70 ( V_289 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_72 ( & V_2 -> V_287 ) ;
F_53 ( V_2 ) ;
F_4 ( V_2 ) ;
F_59 ( & V_282 ) ;
if ( ! F_73 ( & V_2 -> V_285 ) )
F_74 ( & V_2 -> V_285 ) ;
F_61 ( & V_282 ) ;
#ifdef F_50
F_52 ( V_2 -> V_244 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_75 ( const char * V_243 , const struct V_237 * V_238 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_235 * V_236 ;
F_59 ( & V_282 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ ) {
V_236 = & V_235 [ V_9 ] ;
if ( strcmp ( V_236 -> V_243 , V_243 ) )
continue;
V_236 -> V_238 = V_238 ;
F_76 (drv, &op->drv, list)
V_2 -> V_241 = F_49 ( V_2 , V_236 ) ;
F_61 ( & V_282 ) ;
return 0 ;
}
F_61 ( & V_282 ) ;
return - V_294 ;
}
void F_77 ( const char * V_243 )
{
int V_9 ;
struct V_1 * V_2 ;
F_59 ( & V_282 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ ) {
if ( strcmp ( V_235 [ V_9 ] . V_243 , V_243 ) )
continue;
V_235 [ V_9 ] . V_238 = NULL ;
F_76 (drv, &iwlwifi_opmode_table[i].drv, list)
F_53 ( V_2 ) ;
F_61 ( & V_282 ) ;
return;
}
F_61 ( & V_282 ) ;
}
static int T_4 F_78 ( void )
{
int V_9 ;
F_79 ( & V_282 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ )
F_68 ( & V_235 [ V_9 ] . V_2 ) ;
F_80 ( V_295 L_65 ) ;
F_80 ( V_296 L_65 ) ;
#ifdef F_50
V_290 = F_51 ( V_297 , NULL ) ;
if ( ! V_290 )
return - V_298 ;
#endif
return F_81 () ;
}
static void T_5 F_82 ( void )
{
F_83 () ;
#ifdef F_50
F_52 ( V_290 ) ;
#endif
}
