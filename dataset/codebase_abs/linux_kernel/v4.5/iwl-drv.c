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
if ( V_37 != 'A' )
snprintf ( V_2 -> V_33 ,
sizeof( V_2 -> V_33 ) , L_4 ,
V_23 , V_37 , V_26 ) ;
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
if ( V_92 >= F_28 ( V_94 , 32 ) ) {
F_11 ( V_2 ,
L_9 ,
V_92 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_22 ( V_9 ) )
F_29 ( V_9 + 32 * V_92 , V_68 -> V_95 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_89 * V_68 )
{
const struct V_96 * V_97 = ( void * ) V_5 ;
T_2 V_92 = F_21 ( V_97 -> V_92 ) ;
T_2 V_93 = F_21 ( V_97 -> V_98 ) ;
int V_9 ;
if ( V_92 >= F_28 ( V_99 , 32 ) ) {
F_11 ( V_2 ,
L_10 ,
V_92 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_93 & F_22 ( V_9 ) )
F_29 ( V_9 + 32 * V_92 , V_68 -> V_100 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = ( void * ) V_102 -> V_5 ;
T_2 V_105 , V_106 , V_107 ;
char V_108 [ 25 ] ;
const T_3 * V_109 ;
V_2 -> V_12 . V_110 = F_21 ( V_104 -> V_111 ) ;
V_105 = F_32 ( V_2 -> V_12 . V_110 ) ;
switch ( V_105 ) {
default:
V_106 = 28 ;
if ( V_102 -> V_18 < V_106 ) {
F_11 ( V_2 , L_11 ) ;
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
F_11 ( V_2 , L_11 ) ;
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
sprintf ( V_108 , L_12 , V_107 ,
( V_2 -> V_27 == V_28 )
? L_13 : L_7 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_14 ,
F_33 ( V_2 -> V_12 . V_110 ) ,
F_34 ( V_2 -> V_12 . V_110 ) ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_35 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
if ( V_102 -> V_18 != V_106 +
F_18 ( V_44 , V_114 , V_115 ) +
F_18 ( V_44 , V_114 , V_117 ) +
F_18 ( V_44 , V_119 , V_115 ) +
F_18 ( V_44 , V_119 , V_117 ) ) {
F_11 ( V_2 ,
L_15 ,
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
static int F_36 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
struct V_43 * V_44 ,
struct V_89 * V_68 ,
bool * V_126 )
{
struct V_127 * V_104 = ( void * ) V_102 -> V_5 ;
struct V_128 * V_129 ;
T_1 V_6 = V_102 -> V_18 ;
const T_3 * V_5 ;
T_2 V_130 ;
T_2 V_131 ;
enum V_132 V_133 ;
const T_3 * V_134 ;
char V_108 [ 25 ] ;
T_2 V_107 , V_135 ;
int V_136 ;
bool V_137 = false ;
bool V_69 = false ;
if ( V_6 < sizeof( * V_104 ) ) {
F_11 ( V_2 , L_16 , V_6 ) ;
return - V_19 ;
}
if ( V_104 -> V_138 != F_37 ( V_139 ) ) {
F_11 ( V_2 , L_17 ,
F_21 ( V_104 -> V_138 ) ) ;
return - V_19 ;
}
V_2 -> V_12 . V_110 = F_21 ( V_104 -> V_111 ) ;
memcpy ( V_2 -> V_12 . V_140 , V_104 -> V_140 ,
sizeof( V_2 -> V_12 . V_140 ) ) ;
V_107 = F_21 ( V_104 -> V_107 ) ;
if ( V_107 )
sprintf ( V_108 , L_12 , V_107 ,
( V_2 -> V_27 == V_28 )
? L_13 : L_7 ) ;
else
V_108 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) ,
L_14 ,
F_33 ( V_2 -> V_12 . V_110 ) ,
F_34 ( V_2 -> V_12 . V_110 ) ,
F_32 ( V_2 -> V_12 . V_110 ) ,
F_35 ( V_2 -> V_12 . V_110 ) ,
V_108 ) ;
V_5 = V_104 -> V_5 ;
V_6 -= sizeof( * V_104 ) ;
while ( V_6 >= sizeof( * V_129 ) ) {
V_6 -= sizeof( * V_129 ) ;
V_129 = ( void * ) V_5 ;
V_130 = F_21 ( V_129 -> V_141 ) ;
V_133 = F_21 ( V_129 -> type ) ;
V_134 = V_129 -> V_5 ;
if ( V_6 < V_130 ) {
F_11 ( V_2 , L_18 ,
V_6 , V_130 ) ;
return - V_19 ;
}
V_6 -= F_38 ( V_130 , 4 ) ;
V_5 += sizeof( * V_129 ) + F_38 ( V_130 , 4 ) ;
switch ( V_133 ) {
case V_142 :
F_16 ( V_44 , V_114 ,
V_115 , V_134 ) ;
F_17 ( V_44 , V_114 ,
V_115 , V_130 ) ;
F_19 ( V_44 , V_114 ,
V_115 ,
V_124 ) ;
break;
case V_143 :
F_16 ( V_44 , V_114 ,
V_117 , V_134 ) ;
F_17 ( V_44 , V_114 ,
V_117 , V_130 ) ;
F_19 ( V_44 , V_114 ,
V_117 ,
V_125 ) ;
break;
case V_144 :
F_16 ( V_44 , V_119 ,
V_115 , V_134 ) ;
F_17 ( V_44 , V_119 ,
V_115 , V_130 ) ;
F_19 ( V_44 , V_119 ,
V_115 ,
V_124 ) ;
break;
case V_145 :
F_16 ( V_44 , V_119 ,
V_117 , V_134 ) ;
F_17 ( V_44 , V_119 ,
V_117 , V_130 ) ;
F_19 ( V_44 , V_119 ,
V_117 ,
V_125 ) ;
break;
case V_146 :
F_11 ( V_2 , L_19 ) ;
break;
case V_147 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_149 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_151 :
if ( V_130 )
goto V_148;
V_68 -> V_152 |= V_153 ;
break;
case V_154 :
if ( V_130 < sizeof( T_2 ) )
goto V_148;
if ( V_130 % sizeof( T_2 ) )
goto V_148;
V_68 -> V_152 = F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_155 :
if ( V_130 != sizeof( struct V_90 ) )
goto V_148;
if ( F_27 ( V_2 , V_134 , V_68 ) )
goto V_156;
break;
case V_157 :
if ( V_130 != sizeof( struct V_96 ) )
goto V_148;
if ( F_30 ( V_2 , V_134 , V_68 ) )
goto V_156;
break;
case V_158 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_159 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_160 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_161 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_162 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_163 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_164 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_165 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_166 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_167 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_168 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_44 -> V_169 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_170 :
if ( V_130 )
goto V_148;
V_2 -> V_12 . V_171 = true ;
break;
case V_172 :
F_16 ( V_44 , V_173 ,
V_115 , V_134 ) ;
F_17 ( V_44 , V_173 ,
V_115 , V_130 ) ;
F_19 ( V_44 , V_173 ,
V_115 ,
V_124 ) ;
break;
case V_174 :
F_16 ( V_44 , V_173 ,
V_117 , V_134 ) ;
F_17 ( V_44 , V_173 ,
V_117 , V_130 ) ;
F_19 ( V_44 , V_173 ,
V_117 ,
V_125 ) ;
break;
case V_175 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_176 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_177 :
F_24 ( V_44 , V_134 , V_114 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_179 :
F_24 ( V_44 , V_134 , V_119 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_180 :
F_24 ( V_44 , V_134 , V_173 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_181 :
if ( V_130 != sizeof( struct V_82 ) )
goto V_148;
if ( F_26 ( V_2 , V_134 ) )
goto V_156;
break;
case V_182 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_2 -> V_12 . V_183 = F_39 ( ( V_150 * ) V_134 ) ;
V_2 -> V_12 . V_184 = ( V_2 -> V_12 . V_183 &
V_185 ) >>
V_186 ;
V_2 -> V_12 . V_187 = ( V_2 -> V_12 . V_183 &
V_188 ) >>
V_189 ;
break;
case V_190 :
F_24 ( V_44 , V_134 , V_114 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_191 :
F_24 ( V_44 , V_134 , V_119 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_192 :
F_24 ( V_44 , V_134 , V_173 ,
V_130 ) ;
V_2 -> V_12 . V_178 = true ;
break;
case V_193 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_136 =
F_39 ( ( V_150 * ) V_134 ) ;
if ( V_136 == 2 ) {
V_2 -> V_12 . V_8 [ V_114 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_119 ] . V_194 =
true ;
V_2 -> V_12 . V_8 [ V_173 ] . V_194 =
true ;
} else if ( ( V_136 > 2 ) || ( V_136 < 1 ) ) {
F_11 ( V_2 , L_20 ) ;
return - V_19 ;
}
break;
case V_195 :
if ( F_20 ( & V_2 -> V_12 , V_134 , V_130 ) )
goto V_148;
break;
case V_196 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_68 -> V_197 =
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_198 : {
V_150 * V_199 = ( void * ) V_134 ;
T_2 V_200 , V_201 ;
T_3 V_202 ;
if ( V_130 != sizeof( T_2 ) * 3 )
goto V_148;
V_200 = F_39 ( V_199 ++ ) ;
V_201 = F_39 ( V_199 ++ ) ;
V_202 = F_39 ( V_199 ) ;
snprintf ( V_2 -> V_12 . V_123 ,
sizeof( V_2 -> V_12 . V_123 ) , L_21 ,
V_200 , V_201 , V_202 ) ;
break;
}
case V_203 : {
struct V_204 * V_205 = ( void * ) V_134 ;
if ( V_44 -> V_13 ) {
F_11 ( V_2 ,
L_22 ) ;
break;
}
V_44 -> V_13 = V_205 ;
F_40 ( V_2 , L_23 ,
F_41 ( V_205 -> V_206 ) ) ;
V_2 -> V_12 . V_207 =
V_130 - F_42 ( struct V_204 ,
V_208 ) ;
V_2 -> V_12 . V_207 /=
sizeof( V_2 -> V_12 . V_13 -> V_208 [ 0 ] ) ;
break;
}
case V_209 : {
struct V_210 * V_211 = ( void * ) V_134 ;
if ( ! V_44 -> V_13 ) {
F_11 ( V_2 ,
L_24 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_212 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_25 ,
V_211 -> V_212 ) ;
break;
}
if ( V_44 -> V_14 [ V_211 -> V_212 ] ) {
F_11 ( V_2 ,
L_26 ,
V_211 -> V_212 ) ;
break;
}
if ( V_211 -> V_213 )
V_137 = true ;
F_40 ( V_2 , L_27 ,
V_211 -> V_212 ) ;
V_44 -> V_14 [ V_211 -> V_212 ] = V_211 ;
V_44 -> V_214 [ V_211 -> V_212 ] = V_130 ;
break;
}
case V_215 : {
struct V_216 * V_217 =
( void * ) V_134 ;
T_2 V_218 = F_21 ( V_217 -> V_212 ) ;
if ( V_218 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_28 ,
V_217 -> V_212 ) ;
break;
}
if ( V_44 -> V_15 [ V_218 ] ) {
F_11 ( V_2 ,
L_29 ,
V_217 -> V_212 ) ;
break;
}
F_40 ( V_2 , L_30 , V_217 -> V_212 ) ;
V_44 -> V_15 [ V_218 ] = V_217 ;
V_44 -> V_219 [ V_218 ] = V_130 ;
break;
}
case V_220 :
* V_126 = true ;
F_24 ( V_44 , V_134 ,
V_221 ,
V_130 ) ;
break;
case V_222 :
if ( V_130 != sizeof( T_2 ) )
goto V_148;
V_135 = F_39 ( ( V_150 * ) V_134 ) ;
F_43 ( V_2 ,
L_31 ,
V_135 ) ;
if ( V_135 > V_223 ) {
F_11 ( V_2 ,
L_32 ,
V_223 ) ;
return - V_19 ;
}
if ( V_135 & ( V_224 - 1 ) ) {
F_11 ( V_2 ,
L_33 ,
V_224 ) ;
return - V_19 ;
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
F_39 ( ( V_150 * ) V_134 ) ;
break;
case V_227 :
if ( F_23 ( & V_2 -> V_12 , V_134 , V_130 ) )
goto V_148;
V_69 = true ;
break;
default:
F_13 ( V_2 , L_34 , V_133 ) ;
break;
}
}
if ( V_137 && ! * V_126 ) {
F_11 ( V_2 ,
L_35 ) ;
return - V_19 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_36 , V_6 ) ;
F_44 ( V_2 , V_228 , ( T_3 * ) V_5 , V_6 ) ;
return - V_19 ;
}
if ( F_45 ( V_68 , V_229 ) &&
F_46 ( ! V_69 ,
L_37 ) )
F_47 ( ( V_230 long ) V_229 ,
V_68 -> V_100 ) ;
return 0 ;
V_148:
F_11 ( V_2 , L_38 , V_133 , V_130 ) ;
V_156:
F_44 ( V_2 , V_228 , V_134 , V_130 ) ;
return - V_19 ;
}
static int F_48 ( struct V_1 * V_2 ,
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
static int F_49 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
const struct V_231 * V_24 )
{
F_13 ( V_2 , L_39 ,
F_18 ( V_44 , V_114 ,
V_115 ) ) ;
F_13 ( V_2 , L_40 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
F_13 ( V_2 , L_41 ,
F_18 ( V_44 , V_119 , V_115 ) ) ;
F_13 ( V_2 , L_42 ,
F_18 ( V_44 , V_119 , V_117 ) ) ;
if ( F_18 ( V_44 , V_114 , V_115 ) >
V_24 -> V_232 ) {
F_11 ( V_2 , L_43 ,
F_18 ( V_44 , V_114 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_114 , V_117 ) >
V_24 -> V_233 ) {
F_11 ( V_2 , L_44 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_119 , V_115 ) >
V_24 -> V_232 ) {
F_11 ( V_2 , L_45 ,
F_18 ( V_44 , V_119 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_119 , V_117 ) >
V_24 -> V_233 ) {
F_11 ( V_2 , L_46 ,
F_18 ( V_44 , V_114 ,
V_117 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_234 *
F_50 ( struct V_1 * V_2 , struct V_235 * V_236 )
{
const struct V_237 * V_238 = V_236 -> V_238 ;
struct V_239 * V_240 = NULL ;
struct V_234 * V_241 = NULL ;
#ifdef F_51
V_2 -> V_242 = F_52 ( V_236 -> V_243 ,
V_2 -> V_244 ) ;
if ( ! V_2 -> V_242 ) {
F_11 ( V_2 ,
L_47 ) ;
return V_241 ;
}
V_240 = V_2 -> V_242 ;
#endif
V_241 = V_238 -> V_245 ( V_2 -> V_34 , V_2 -> V_24 , & V_2 -> V_12 , V_240 ) ;
#ifdef F_51
if ( ! V_241 ) {
F_53 ( V_2 -> V_242 ) ;
V_2 -> V_242 = NULL ;
}
#endif
return V_241 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_241 ) {
F_55 ( V_2 -> V_241 ) ;
V_2 -> V_241 = NULL ;
#ifdef F_51
F_53 ( V_2 -> V_242 ) ;
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
bool V_126 = false ;
V_12 -> V_97 . V_149 = V_255 ;
V_12 -> V_97 . V_176 =
V_256 ;
V_12 -> V_97 . V_197 = V_257 ;
if ( ! V_249 )
V_249 = V_248 ;
V_44 = F_56 ( sizeof( * V_44 ) , V_41 ) ;
if ( ! V_44 )
return;
if ( ! V_102 ) {
if ( V_2 -> V_27 <= V_249 )
F_11 ( V_2 ,
L_48 ,
V_2 -> V_33 ) ;
goto V_258;
}
F_13 ( V_2 , L_49 ,
V_2 -> V_33 , V_102 -> V_18 ) ;
if ( V_102 -> V_18 < 4 ) {
F_11 ( V_2 , L_50 ) ;
goto V_258;
}
V_104 = (struct V_103 * ) V_102 -> V_5 ;
if ( V_104 -> V_111 )
V_247 = F_31 ( V_2 , V_102 , V_44 ) ;
else
V_247 = F_36 ( V_2 , V_102 , V_44 ,
& V_12 -> V_97 , & V_126 ) ;
if ( V_247 )
goto V_258;
if ( F_57 ( & V_2 -> V_12 . V_97 , V_259 ) )
V_105 = V_2 -> V_12 . V_110 ;
else
V_105 = F_32 ( V_2 -> V_12 . V_110 ) ;
if ( V_2 -> V_27 != V_28 ) {
if ( V_105 < V_251 || V_105 > V_248 ) {
F_11 ( V_2 ,
L_51
L_52 ,
V_248 , V_105 ) ;
goto V_258;
}
if ( V_105 < V_249 ) {
if ( V_249 != V_248 )
F_11 ( V_2 , L_53
L_54 ,
V_249 , V_248 , V_105 ) ;
else
F_11 ( V_2 , L_53
L_55 ,
V_248 , V_105 ) ;
F_11 ( V_2 , L_56
L_57 ) ;
}
}
if ( ! V_12 -> V_178 && F_49 ( V_2 , V_44 , V_2 -> V_24 ) )
goto V_258;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( F_48 ( V_2 , V_44 , V_9 ) )
goto V_260;
if ( V_44 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_58 ( V_44 -> V_13 ,
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
F_58 ( V_44 -> V_14 [ V_9 ] ,
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
V_252 [ V_278 ] =
sizeof( struct V_279 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_44 -> V_15 [ V_9 ] ) {
if ( F_25 ( V_44 -> V_219 [ V_9 ] <
( V_252 [ V_9 ] +
sizeof( struct V_216 ) ) ) )
goto V_260;
V_2 -> V_12 . V_219 [ V_9 ] =
V_44 -> V_219 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_58 ( V_44 -> V_15 [ V_9 ] ,
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
V_2 -> V_24 -> V_280 -> V_281 ;
V_12 -> V_163 = V_44 -> V_163 ;
V_12 -> V_165 = V_44 -> V_165 ;
if ( V_44 -> V_167 )
V_12 -> V_167 = ( V_44 -> V_167 - 16 ) / 12 ;
else
V_12 -> V_167 =
V_2 -> V_24 -> V_280 -> V_281 ;
V_12 -> V_169 = V_44 -> V_169 ;
if ( V_12 -> V_97 . V_176 >
V_282 )
V_12 -> V_97 . V_176 =
V_283 ;
F_59 ( V_102 ) ;
F_60 ( & V_284 ) ;
if ( V_12 -> V_178 )
V_236 = & V_235 [ V_285 ] ;
else
V_236 = & V_235 [ V_286 ] ;
F_40 ( V_2 , L_58 ,
V_2 -> V_12 . V_123 , V_236 -> V_243 ) ;
F_61 ( & V_2 -> V_287 , & V_236 -> V_2 ) ;
if ( V_236 -> V_238 ) {
V_2 -> V_241 = F_50 ( V_2 , V_236 ) ;
if ( ! V_2 -> V_241 ) {
F_62 ( & V_284 ) ;
goto V_288;
}
} else {
V_254 = true ;
}
F_62 ( & V_284 ) ;
F_63 ( & V_2 -> V_289 ) ;
if ( V_254 ) {
V_247 = F_64 ( L_59 , V_236 -> V_243 ) ;
#ifdef F_65
if ( V_247 )
F_11 ( V_2 ,
L_60 ,
V_236 -> V_243 , V_247 ) ;
#endif
}
F_5 ( V_44 ) ;
return;
V_258:
F_59 ( V_102 ) ;
if ( F_9 ( V_2 , false ) )
goto V_288;
F_5 ( V_44 ) ;
return;
V_260:
F_11 ( V_2 , L_61 ) ;
F_4 ( V_2 ) ;
F_59 ( V_102 ) ;
V_288:
F_5 ( V_44 ) ;
F_63 ( & V_2 -> V_289 ) ;
F_66 ( V_2 -> V_34 -> V_40 ) ;
}
struct V_1 * F_67 ( struct V_290 * V_34 ,
const struct V_231 * V_24 )
{
struct V_1 * V_2 ;
int V_291 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 ) {
V_291 = - V_20 ;
goto V_247;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_24 = V_24 ;
F_68 ( & V_2 -> V_289 ) ;
F_69 ( & V_2 -> V_287 ) ;
#ifdef F_51
V_2 -> V_244 = F_52 ( F_70 ( V_34 -> V_40 ) ,
V_292 ) ;
if ( ! V_2 -> V_244 ) {
F_11 ( V_2 , L_62 ) ;
V_291 = - V_20 ;
goto V_293;
}
V_2 -> V_34 -> V_240 = F_52 ( L_63 , V_2 -> V_244 ) ;
if ( ! V_2 -> V_34 -> V_240 ) {
F_11 ( V_2 , L_64 ) ;
V_291 = - V_20 ;
goto V_294;
}
#endif
V_291 = F_9 ( V_2 , true ) ;
if ( V_291 ) {
F_11 ( V_34 , L_65 ) ;
goto V_295;
}
return V_2 ;
V_295:
#ifdef F_51
V_294:
F_53 ( V_2 -> V_244 ) ;
V_293:
#endif
F_5 ( V_2 ) ;
V_247:
return F_71 ( V_291 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_289 ) ;
F_54 ( V_2 ) ;
F_4 ( V_2 ) ;
F_60 ( & V_284 ) ;
if ( ! F_74 ( & V_2 -> V_287 ) )
F_75 ( & V_2 -> V_287 ) ;
F_62 ( & V_284 ) ;
#ifdef F_51
F_53 ( V_2 -> V_244 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_76 ( const char * V_243 , const struct V_237 * V_238 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_235 * V_236 ;
F_60 ( & V_284 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ ) {
V_236 = & V_235 [ V_9 ] ;
if ( strcmp ( V_236 -> V_243 , V_243 ) )
continue;
V_236 -> V_238 = V_238 ;
F_77 (drv, &op->drv, list)
V_2 -> V_241 = F_50 ( V_2 , V_236 ) ;
F_62 ( & V_284 ) ;
return 0 ;
}
F_62 ( & V_284 ) ;
return - V_296 ;
}
void F_78 ( const char * V_243 )
{
int V_9 ;
struct V_1 * V_2 ;
F_60 ( & V_284 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ ) {
if ( strcmp ( V_235 [ V_9 ] . V_243 , V_243 ) )
continue;
V_235 [ V_9 ] . V_238 = NULL ;
F_77 (drv, &iwlwifi_opmode_table[i].drv, list)
F_54 ( V_2 ) ;
F_62 ( & V_284 ) ;
return;
}
F_62 ( & V_284 ) ;
}
static int T_4 F_79 ( void )
{
int V_9 ;
F_80 ( & V_284 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_235 ) ; V_9 ++ )
F_69 ( & V_235 [ V_9 ] . V_2 ) ;
F_81 ( V_297 L_66 ) ;
F_81 ( V_298 L_66 ) ;
#ifdef F_51
V_292 = F_52 ( V_299 , NULL ) ;
if ( ! V_292 )
return - V_300 ;
#endif
return F_82 () ;
}
static void T_5 F_83 ( void )
{
F_84 () ;
#ifdef F_51
F_53 ( V_292 ) ;
#endif
}
