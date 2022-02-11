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
F_12 ( V_2 , L_4 ,
( V_2 -> V_27 == V_28 )
? L_5 : L_6 ,
V_2 -> V_33 ) ;
return F_13 ( V_34 , 1 , V_2 -> V_33 ,
V_2 -> V_35 -> V_36 ,
V_37 , V_2 , V_38 ) ;
}
static struct V_17 * F_14 ( struct V_39 * V_40 ,
enum V_41 type ,
int V_11 )
{
return & V_40 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_15 ( struct V_39 * V_40 ,
enum V_41 type ,
int V_11 ,
const void * V_5 )
{
V_40 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_16 ( struct V_39 * V_40 ,
enum V_41 type ,
int V_11 ,
T_1 V_18 )
{
V_40 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 = V_18 ;
}
static T_1 F_17 ( struct V_39 * V_40 ,
enum V_41 type ,
int V_11 )
{
return V_40 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 ;
}
static void F_18 ( struct V_39 * V_40 ,
enum V_41 type ,
int V_11 ,
T_2 V_21 )
{
V_40 -> V_8 [ type ] . V_11 [ V_11 ] . V_21 = V_21 ;
}
static int F_19 ( struct V_42 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_43 ;
struct V_44 * V_45 = (struct V_44 * ) V_5 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
T_2 V_50 ;
if ( V_6 < sizeof( * V_45 ) ||
V_6 < sizeof( V_45 -> V_18 ) + V_45 -> V_18 * sizeof( V_45 -> V_49 [ 0 ] ) )
return - V_19 ;
for ( V_9 = 0 , V_43 = 0 ; V_9 < V_51 && V_9 < V_45 -> V_18 ; V_9 ++ ) {
V_47 = & V_45 -> V_49 [ V_43 ] ;
V_50 = F_20 ( V_47 -> V_50 ) ;
if ( ! V_50 )
continue;
V_49 = & V_12 -> V_49 [ V_43 ++ ] ;
V_49 -> V_50 = V_50 ;
V_49 -> V_52 = F_21 ( V_53 ) ;
V_49 -> V_54 = V_47 -> V_54 ;
V_49 -> V_55 = V_47 -> V_55 ;
V_49 -> V_56 = V_47 -> V_56 ;
V_49 -> V_57 = V_47 -> V_57 ;
V_49 -> V_58 = V_47 -> V_58 ;
V_49 -> V_59 = V_47 -> V_59 ;
V_49 -> V_60 = V_47 -> V_60 ;
}
return 0 ;
}
static void F_22 ( struct V_42 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_61 * V_62 = ( void * ) V_5 ;
struct V_63 * V_64 = & V_12 -> V_65 ;
V_64 -> V_66 = F_20 ( V_62 -> V_66 ) ;
V_64 -> V_67 = F_20 ( V_62 -> V_67 ) ;
V_64 -> V_68 =
F_20 ( V_62 -> V_68 ) ;
V_64 -> V_69 = F_20 ( V_62 -> V_69 ) ;
V_64 -> V_70 =
F_20 ( V_62 -> V_70 ) ;
V_64 -> V_71 = F_20 ( V_62 -> V_71 ) ;
V_64 -> V_72 =
F_20 ( V_62 -> V_72 ) ;
V_64 -> V_73 =
F_20 ( V_62 -> V_73 ) ;
V_64 -> V_74 = F_20 ( V_62 -> V_74 ) ;
V_64 -> V_75 =
F_20 ( V_62 -> V_75 ) ;
V_64 -> V_76 =
F_20 ( V_62 -> V_76 ) ;
V_64 -> V_77 =
F_20 ( V_62 -> V_77 ) ;
V_64 -> V_78 =
F_20 ( V_62 -> V_78 ) ;
}
static int F_23 ( struct V_39 * V_40 ,
const void * V_5 , enum V_41 type ,
int V_18 )
{
struct V_79 * V_8 ;
struct V_17 * V_11 ;
struct V_80 * V_81 ;
if ( F_24 ( ! V_40 || ! V_5 || type >= V_16 ) )
return - 1 ;
V_81 = (struct V_80 * ) V_5 ;
V_8 = & V_40 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_82 ] ;
V_11 -> V_21 = F_20 ( V_81 -> V_21 ) ;
V_11 -> V_5 = V_81 -> V_5 ;
V_11 -> V_18 = V_18 - sizeof( V_81 -> V_21 ) ;
++ V_8 -> V_82 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_5 ;
T_2 V_85 = F_20 ( V_84 -> V_85 ) ;
if ( V_85 >= V_16 ) {
F_11 ( V_2 , L_7 ,
V_85 ) ;
return - V_19 ;
}
V_2 -> V_12 . V_86 [ V_85 ] . V_87 =
V_84 -> V_88 . V_87 ;
V_2 -> V_12 . V_86 [ V_85 ] . V_89 =
V_84 -> V_88 . V_89 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_90 * V_64 )
{
const struct V_91 * V_92 = ( void * ) V_5 ;
T_2 V_93 = F_20 ( V_92 -> V_93 ) ;
T_2 V_94 = F_20 ( V_92 -> V_94 ) ;
int V_9 ;
if ( V_93 >= F_27 ( V_95 , 32 ) ) {
F_11 ( V_2 ,
L_8 ,
V_93 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_94 & F_21 ( V_9 ) )
F_28 ( V_9 + 32 * V_93 , V_64 -> V_96 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_90 * V_64 )
{
const struct V_97 * V_98 = ( void * ) V_5 ;
T_2 V_93 = F_20 ( V_98 -> V_93 ) ;
T_2 V_94 = F_20 ( V_98 -> V_99 ) ;
int V_9 ;
if ( V_93 >= F_27 ( V_100 , 32 ) ) {
F_11 ( V_2 ,
L_9 ,
V_93 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_94 & F_21 ( V_9 ) )
F_28 ( V_9 + 32 * V_93 , V_64 -> V_101 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_102 * V_103 ,
struct V_39 * V_40 )
{
struct V_104 * V_105 = ( void * ) V_103 -> V_5 ;
T_2 V_106 , V_107 , V_108 ;
char V_109 [ 25 ] ;
const T_3 * V_110 ;
V_2 -> V_12 . V_111 = F_20 ( V_105 -> V_112 ) ;
V_106 = F_31 ( V_2 -> V_12 . V_111 ) ;
switch ( V_106 ) {
default:
V_107 = 28 ;
if ( V_103 -> V_18 < V_107 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_108 = F_20 ( V_105 -> V_113 . V_114 . V_108 ) ;
F_16 ( V_40 , V_115 , V_116 ,
F_20 ( V_105 -> V_113 . V_114 . V_117 ) ) ;
F_16 ( V_40 , V_115 , V_118 ,
F_20 ( V_105 -> V_113 . V_114 . V_119 ) ) ;
F_16 ( V_40 , V_120 , V_116 ,
F_20 ( V_105 -> V_113 . V_114 . V_121 ) ) ;
F_16 ( V_40 , V_120 , V_118 ,
F_20 ( V_105 -> V_113 . V_114 . V_122 ) ) ;
V_110 = V_105 -> V_113 . V_114 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_107 = 24 ;
if ( V_103 -> V_18 < V_107 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_108 = 0 ;
F_16 ( V_40 , V_115 , V_116 ,
F_20 ( V_105 -> V_113 . V_123 . V_117 ) ) ;
F_16 ( V_40 , V_115 , V_118 ,
F_20 ( V_105 -> V_113 . V_123 . V_119 ) ) ;
F_16 ( V_40 , V_120 , V_116 ,
F_20 ( V_105 -> V_113 . V_123 . V_121 ) ) ;
F_16 ( V_40 , V_120 , V_118 ,
F_20 ( V_105 -> V_113 . V_123 . V_122 ) ) ;
V_110 = V_105 -> V_113 . V_123 . V_5 ;
break;
}
if ( V_108 )
sprintf ( V_109 , L_11 , V_108 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_6 ) ;
else
V_109 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_124 ,
sizeof( V_2 -> V_12 . V_124 ) ,
L_13 ,
F_32 ( V_2 -> V_12 . V_111 ) ,
F_33 ( V_2 -> V_12 . V_111 ) ,
F_31 ( V_2 -> V_12 . V_111 ) ,
F_34 ( V_2 -> V_12 . V_111 ) ,
V_109 ) ;
if ( V_103 -> V_18 != V_107 +
F_17 ( V_40 , V_115 , V_116 ) +
F_17 ( V_40 , V_115 , V_118 ) +
F_17 ( V_40 , V_120 , V_116 ) +
F_17 ( V_40 , V_120 , V_118 ) ) {
F_11 ( V_2 ,
L_14 ,
( int ) V_103 -> V_18 ) ;
return - V_19 ;
}
F_15 ( V_40 , V_115 , V_116 , V_110 ) ;
V_110 += F_17 ( V_40 , V_115 , V_116 ) ;
F_18 ( V_40 , V_115 , V_116 ,
V_125 ) ;
F_15 ( V_40 , V_115 , V_118 , V_110 ) ;
V_110 += F_17 ( V_40 , V_115 , V_118 ) ;
F_18 ( V_40 , V_115 , V_118 ,
V_126 ) ;
F_15 ( V_40 , V_120 , V_116 , V_110 ) ;
V_110 += F_17 ( V_40 , V_120 , V_116 ) ;
F_18 ( V_40 , V_120 , V_116 ,
V_125 ) ;
F_15 ( V_40 , V_120 , V_118 , V_110 ) ;
V_110 += F_17 ( V_40 , V_120 , V_118 ) ;
F_18 ( V_40 , V_120 , V_118 ,
V_126 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_102 * V_103 ,
struct V_39 * V_40 ,
struct V_90 * V_64 ,
bool * V_127 )
{
struct V_128 * V_105 = ( void * ) V_103 -> V_5 ;
struct V_129 * V_130 ;
T_1 V_6 = V_103 -> V_18 ;
const T_3 * V_5 ;
T_2 V_131 ;
T_2 V_132 ;
enum V_133 V_134 ;
const T_3 * V_135 ;
char V_109 [ 25 ] ;
T_2 V_108 , V_136 ;
int V_137 ;
bool V_138 = false ;
bool V_65 = false ;
if ( V_6 < sizeof( * V_105 ) ) {
F_11 ( V_2 , L_15 , V_6 ) ;
return - V_19 ;
}
if ( V_105 -> V_139 != F_36 ( V_140 ) ) {
F_11 ( V_2 , L_16 ,
F_20 ( V_105 -> V_139 ) ) ;
return - V_19 ;
}
V_2 -> V_12 . V_111 = F_20 ( V_105 -> V_112 ) ;
memcpy ( V_2 -> V_12 . V_141 , V_105 -> V_141 ,
sizeof( V_2 -> V_12 . V_141 ) ) ;
V_108 = F_20 ( V_105 -> V_108 ) ;
if ( V_108 )
sprintf ( V_109 , L_11 , V_108 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_6 ) ;
else
V_109 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_124 ,
sizeof( V_2 -> V_12 . V_124 ) ,
L_13 ,
F_32 ( V_2 -> V_12 . V_111 ) ,
F_33 ( V_2 -> V_12 . V_111 ) ,
F_31 ( V_2 -> V_12 . V_111 ) ,
F_34 ( V_2 -> V_12 . V_111 ) ,
V_109 ) ;
V_5 = V_105 -> V_5 ;
V_6 -= sizeof( * V_105 ) ;
while ( V_6 >= sizeof( * V_130 ) ) {
V_6 -= sizeof( * V_130 ) ;
V_130 = ( void * ) V_5 ;
V_131 = F_20 ( V_130 -> V_142 ) ;
V_134 = F_20 ( V_130 -> type ) ;
V_135 = V_130 -> V_5 ;
if ( V_6 < V_131 ) {
F_11 ( V_2 , L_17 ,
V_6 , V_131 ) ;
return - V_19 ;
}
V_6 -= F_37 ( V_131 , 4 ) ;
V_5 += sizeof( * V_130 ) + F_37 ( V_131 , 4 ) ;
switch ( V_134 ) {
case V_143 :
F_15 ( V_40 , V_115 ,
V_116 , V_135 ) ;
F_16 ( V_40 , V_115 ,
V_116 , V_131 ) ;
F_18 ( V_40 , V_115 ,
V_116 ,
V_125 ) ;
break;
case V_144 :
F_15 ( V_40 , V_115 ,
V_118 , V_135 ) ;
F_16 ( V_40 , V_115 ,
V_118 , V_131 ) ;
F_18 ( V_40 , V_115 ,
V_118 ,
V_126 ) ;
break;
case V_145 :
F_15 ( V_40 , V_120 ,
V_116 , V_135 ) ;
F_16 ( V_40 , V_120 ,
V_116 , V_131 ) ;
F_18 ( V_40 , V_120 ,
V_116 ,
V_125 ) ;
break;
case V_146 :
F_15 ( V_40 , V_120 ,
V_118 , V_135 ) ;
F_16 ( V_40 , V_120 ,
V_118 , V_131 ) ;
F_18 ( V_40 , V_120 ,
V_118 ,
V_126 ) ;
break;
case V_147 :
F_11 ( V_2 , L_18 ) ;
break;
case V_148 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_64 -> V_150 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_152 :
if ( V_131 )
goto V_149;
V_64 -> V_153 |= V_154 ;
break;
case V_155 :
if ( V_131 < sizeof( T_2 ) )
goto V_149;
if ( V_131 % sizeof( T_2 ) )
goto V_149;
V_64 -> V_153 = F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_156 :
if ( V_131 != sizeof( struct V_91 ) )
goto V_149;
if ( F_26 ( V_2 , V_135 , V_64 ) )
goto V_157;
break;
case V_158 :
if ( V_131 != sizeof( struct V_97 ) )
goto V_149;
if ( F_29 ( V_2 , V_135 , V_64 ) )
goto V_157;
break;
case V_159 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_160 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_161 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_162 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_163 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_164 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_165 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_166 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_167 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_168 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_169 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_40 -> V_170 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_171 :
if ( V_131 )
goto V_149;
V_2 -> V_12 . V_172 = true ;
break;
case V_173 :
F_15 ( V_40 , V_174 ,
V_116 , V_135 ) ;
F_16 ( V_40 , V_174 ,
V_116 , V_131 ) ;
F_18 ( V_40 , V_174 ,
V_116 ,
V_125 ) ;
break;
case V_175 :
F_15 ( V_40 , V_174 ,
V_118 , V_135 ) ;
F_16 ( V_40 , V_174 ,
V_118 , V_131 ) ;
F_18 ( V_40 , V_174 ,
V_118 ,
V_126 ) ;
break;
case V_176 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_64 -> V_177 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_178 :
F_23 ( V_40 , V_135 , V_115 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_180 :
F_23 ( V_40 , V_135 , V_120 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_181 :
F_23 ( V_40 , V_135 , V_174 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_182 :
if ( V_131 != sizeof( struct V_83 ) )
goto V_149;
if ( F_25 ( V_2 , V_135 ) )
goto V_157;
break;
case V_183 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_2 -> V_12 . V_184 = F_38 ( ( V_151 * ) V_135 ) ;
V_2 -> V_12 . V_185 = ( V_2 -> V_12 . V_184 &
V_186 ) >>
V_187 ;
V_2 -> V_12 . V_188 = ( V_2 -> V_12 . V_184 &
V_189 ) >>
V_190 ;
break;
case V_191 :
F_23 ( V_40 , V_135 , V_115 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_192 :
F_23 ( V_40 , V_135 , V_120 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_193 :
F_23 ( V_40 , V_135 , V_174 ,
V_131 ) ;
V_2 -> V_12 . V_179 = true ;
break;
case V_194 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_137 =
F_38 ( ( V_151 * ) V_135 ) ;
if ( V_137 == 2 ) {
V_2 -> V_12 . V_8 [ V_115 ] . V_195 =
true ;
V_2 -> V_12 . V_8 [ V_120 ] . V_195 =
true ;
V_2 -> V_12 . V_8 [ V_174 ] . V_195 =
true ;
} else if ( ( V_137 > 2 ) || ( V_137 < 1 ) ) {
F_11 ( V_2 , L_19 ) ;
return - V_19 ;
}
break;
case V_196 :
if ( F_19 ( & V_2 -> V_12 , V_135 , V_131 ) )
goto V_149;
break;
case V_197 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_64 -> V_198 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_199 : {
V_151 * V_200 = ( void * ) V_135 ;
T_2 V_201 , V_202 ;
T_3 V_203 ;
if ( V_131 != sizeof( T_2 ) * 3 )
goto V_149;
V_201 = F_38 ( V_200 ++ ) ;
V_202 = F_38 ( V_200 ++ ) ;
V_203 = F_38 ( V_200 ) ;
snprintf ( V_2 -> V_12 . V_124 ,
sizeof( V_2 -> V_12 . V_124 ) , L_20 ,
V_201 , V_202 , V_203 ) ;
break;
}
case V_204 : {
struct V_205 * V_206 = ( void * ) V_135 ;
if ( V_40 -> V_13 ) {
F_11 ( V_2 ,
L_21 ) ;
break;
}
V_40 -> V_13 = V_206 ;
F_39 ( V_2 , L_22 ,
F_40 ( V_206 -> V_207 ) ) ;
V_2 -> V_12 . V_208 =
V_131 - F_41 ( struct V_205 ,
V_209 ) ;
V_2 -> V_12 . V_208 /=
sizeof( V_2 -> V_12 . V_13 -> V_209 [ 0 ] ) ;
break;
}
case V_210 : {
struct V_211 * V_212 = ( void * ) V_135 ;
if ( ! V_40 -> V_13 ) {
F_11 ( V_2 ,
L_23 ,
V_212 -> V_213 ) ;
break;
}
if ( V_212 -> V_213 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_24 ,
V_212 -> V_213 ) ;
break;
}
if ( V_40 -> V_14 [ V_212 -> V_213 ] ) {
F_11 ( V_2 ,
L_25 ,
V_212 -> V_213 ) ;
break;
}
if ( V_212 -> V_214 )
V_138 = true ;
F_39 ( V_2 , L_26 ,
V_212 -> V_213 ) ;
V_40 -> V_14 [ V_212 -> V_213 ] = V_212 ;
V_40 -> V_215 [ V_212 -> V_213 ] = V_131 ;
break;
}
case V_216 : {
struct V_217 * V_218 =
( void * ) V_135 ;
T_2 V_219 = F_20 ( V_218 -> V_213 ) ;
if ( V_219 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_27 ,
V_218 -> V_213 ) ;
break;
}
if ( V_40 -> V_15 [ V_219 ] ) {
F_11 ( V_2 ,
L_28 ,
V_218 -> V_213 ) ;
break;
}
F_39 ( V_2 , L_29 , V_218 -> V_213 ) ;
V_40 -> V_15 [ V_219 ] = V_218 ;
V_40 -> V_220 [ V_219 ] = V_131 ;
break;
}
case V_221 :
* V_127 = true ;
F_23 ( V_40 , V_135 ,
V_222 ,
V_131 ) ;
break;
case V_223 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_136 = F_38 ( ( V_151 * ) V_135 ) ;
F_42 ( V_2 ,
L_30 ,
V_136 ) ;
if ( V_136 > V_224 ) {
F_11 ( V_2 ,
L_31 ,
V_224 ) ;
return - V_19 ;
}
if ( V_136 & ( V_225 - 1 ) ) {
F_11 ( V_2 ,
L_32 ,
V_225 ) ;
return - V_19 ;
}
V_2 -> V_12 . V_8 [ V_115 ] . V_136 =
V_136 ;
V_132 = V_222 ;
V_2 -> V_12 . V_8 [ V_132 ] . V_136 =
V_136 ;
break;
case V_226 :
if ( V_131 != sizeof( T_2 ) )
goto V_149;
V_2 -> V_12 . V_227 =
F_38 ( ( V_151 * ) V_135 ) ;
break;
case V_228 :
if ( V_131 < sizeof( struct V_61 ) )
break;
F_22 ( & V_2 -> V_12 , V_135 , V_131 ) ;
V_65 = true ;
break;
default:
F_12 ( V_2 , L_33 , V_134 ) ;
break;
}
}
if ( ! F_43 ( V_64 , V_229 ) &&
V_138 && ! * V_127 ) {
F_11 ( V_2 ,
L_34 ) ;
return - V_19 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_35 , V_6 ) ;
F_44 ( V_2 , V_230 , ( T_3 * ) V_5 , V_6 ) ;
return - V_19 ;
}
if ( F_43 ( V_64 , V_231 ) &&
! V_65 ) {
F_12 ( V_2 ,
L_36 ) ;
F_45 ( ( V_232 long ) V_231 ,
V_64 -> V_101 ) ;
}
return 0 ;
V_149:
F_11 ( V_2 , L_37 , V_134 , V_131 ) ;
V_157:
F_44 ( V_2 , V_230 , V_135 , V_131 ) ;
return - V_19 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
enum V_41 type )
{
int V_9 ;
for ( V_9 = 0 ;
V_9 < V_10 && F_17 ( V_40 , type , V_9 ) ;
V_9 ++ )
if ( F_7 ( V_2 , & ( V_2 -> V_12 . V_8 [ type ] . V_11 [ V_9 ] ) ,
F_14 ( V_40 , type , V_9 ) ) )
return - V_20 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_233 * V_24 )
{
F_12 ( V_2 , L_38 ,
F_17 ( V_40 , V_115 ,
V_116 ) ) ;
F_12 ( V_2 , L_39 ,
F_17 ( V_40 , V_115 ,
V_118 ) ) ;
F_12 ( V_2 , L_40 ,
F_17 ( V_40 , V_120 , V_116 ) ) ;
F_12 ( V_2 , L_41 ,
F_17 ( V_40 , V_120 , V_118 ) ) ;
if ( F_17 ( V_40 , V_115 , V_116 ) >
V_24 -> V_234 ) {
F_11 ( V_2 , L_42 ,
F_17 ( V_40 , V_115 ,
V_116 ) ) ;
return - 1 ;
}
if ( F_17 ( V_40 , V_115 , V_118 ) >
V_24 -> V_235 ) {
F_11 ( V_2 , L_43 ,
F_17 ( V_40 , V_115 ,
V_118 ) ) ;
return - 1 ;
}
if ( F_17 ( V_40 , V_120 , V_116 ) >
V_24 -> V_234 ) {
F_11 ( V_2 , L_44 ,
F_17 ( V_40 , V_120 ,
V_116 ) ) ;
return - 1 ;
}
if ( F_17 ( V_40 , V_120 , V_118 ) >
V_24 -> V_235 ) {
F_11 ( V_2 , L_45 ,
F_17 ( V_40 , V_115 ,
V_118 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_236 *
F_48 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
const struct V_239 * V_240 = V_238 -> V_240 ;
struct V_241 * V_242 = NULL ;
struct V_236 * V_243 = NULL ;
#ifdef F_49
V_2 -> V_244 = F_50 ( V_238 -> V_245 ,
V_2 -> V_246 ) ;
if ( ! V_2 -> V_244 ) {
F_11 ( V_2 ,
L_46 ) ;
return V_243 ;
}
V_242 = V_2 -> V_244 ;
#endif
V_243 = V_240 -> V_247 ( V_2 -> V_35 , V_2 -> V_24 , & V_2 -> V_12 , V_242 ) ;
#ifdef F_49
if ( ! V_243 ) {
F_51 ( V_2 -> V_244 ) ;
V_2 -> V_244 = NULL ;
}
#endif
return V_243 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_243 ) {
F_53 ( V_2 -> V_243 ) ;
V_2 -> V_243 = NULL ;
#ifdef F_49
F_51 ( V_2 -> V_244 ) ;
V_2 -> V_244 = NULL ;
#endif
}
}
static void V_38 ( const struct V_102 * V_103 , void * V_248 )
{
struct V_1 * V_2 = V_248 ;
struct V_42 * V_12 = & V_2 -> V_12 ;
struct V_104 * V_105 ;
struct V_237 * V_238 ;
int V_249 ;
struct V_39 * V_40 ;
const unsigned int V_250 = V_2 -> V_24 -> V_30 ;
unsigned int V_251 = V_2 -> V_24 -> V_252 ;
const unsigned int V_253 = V_2 -> V_24 -> V_31 ;
T_1 V_254 [ V_255 ] ;
T_2 V_106 ;
int V_9 ;
bool V_256 = false ;
bool V_127 = false ;
V_12 -> V_98 . V_150 = V_257 ;
V_12 -> V_98 . V_177 =
V_258 ;
V_12 -> V_98 . V_198 = V_259 ;
if ( ! V_251 )
V_251 = V_250 ;
V_40 = F_54 ( sizeof( * V_40 ) , V_37 ) ;
if ( ! V_40 )
return;
if ( ! V_103 ) {
if ( V_2 -> V_27 <= V_251 )
F_11 ( V_2 ,
L_47 ,
V_2 -> V_33 ) ;
goto V_260;
}
F_12 ( V_2 , L_48 ,
V_2 -> V_33 , V_103 -> V_18 ) ;
if ( V_103 -> V_18 < 4 ) {
F_11 ( V_2 , L_49 ) ;
goto V_260;
}
V_105 = (struct V_104 * ) V_103 -> V_5 ;
if ( V_105 -> V_112 )
V_249 = F_30 ( V_2 , V_103 , V_40 ) ;
else
V_249 = F_35 ( V_2 , V_103 , V_40 ,
& V_12 -> V_98 , & V_127 ) ;
if ( V_249 )
goto V_260;
if ( F_55 ( & V_2 -> V_12 . V_98 , V_261 ) )
V_106 = V_2 -> V_12 . V_111 ;
else
V_106 = F_31 ( V_2 -> V_12 . V_111 ) ;
if ( V_2 -> V_27 != V_28 ) {
if ( V_106 < V_253 || V_106 > V_250 ) {
F_11 ( V_2 ,
L_50
L_51 ,
V_250 , V_106 ) ;
goto V_260;
}
if ( V_106 < V_251 ) {
if ( V_251 != V_250 )
F_11 ( V_2 , L_52
L_53 ,
V_251 , V_250 , V_106 ) ;
else
F_11 ( V_2 , L_52
L_54 ,
V_250 , V_106 ) ;
F_11 ( V_2 , L_55
L_56 ) ;
}
}
if ( ! V_12 -> V_179 && F_47 ( V_2 , V_40 , V_2 -> V_24 ) )
goto V_260;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( F_46 ( V_2 , V_40 , V_9 ) )
goto V_262;
if ( V_40 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_56 ( V_40 -> V_13 ,
sizeof( * V_40 -> V_13 ) +
sizeof( V_40 -> V_13 -> V_209 [ 0 ] ) *
V_2 -> V_12 . V_208 , V_37 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_262;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_40 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_215 [ V_9 ] =
V_40 -> V_215 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_56 ( V_40 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_215 [ V_9 ] ,
V_37 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_262;
}
}
memset ( & V_254 , 0xff , sizeof( V_254 ) ) ;
V_254 [ V_263 ] =
sizeof( struct V_264 ) ;
V_254 [ V_265 ] = 0 ;
V_254 [ V_266 ] =
sizeof( struct V_267 ) ;
V_254 [ V_268 ] =
sizeof( struct V_269 ) ;
V_254 [ V_270 ] =
sizeof( struct V_271 ) ;
V_254 [ V_272 ] =
sizeof( struct V_273 ) ;
V_254 [ V_274 ] =
sizeof( struct V_275 ) ;
V_254 [ V_276 ] =
sizeof( struct V_277 ) ;
V_254 [ V_278 ] =
sizeof( struct V_279 ) ;
V_254 [ V_280 ] =
sizeof( struct V_281 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_40 -> V_15 [ V_9 ] ) {
if ( F_24 ( V_40 -> V_220 [ V_9 ] <
( V_254 [ V_9 ] +
sizeof( struct V_217 ) ) ) )
goto V_262;
V_2 -> V_12 . V_220 [ V_9 ] =
V_40 -> V_220 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_56 ( V_40 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_220 [ V_9 ] ,
V_37 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_262;
}
}
V_12 -> V_160 = V_40 -> V_160 ;
if ( V_40 -> V_162 )
V_12 -> V_162 = ( V_40 -> V_162 - 16 ) / 12 ;
else
V_12 -> V_162 =
V_2 -> V_24 -> V_282 -> V_283 ;
V_12 -> V_164 = V_40 -> V_164 ;
V_12 -> V_166 = V_40 -> V_166 ;
if ( V_40 -> V_168 )
V_12 -> V_168 = ( V_40 -> V_168 - 16 ) / 12 ;
else
V_12 -> V_168 =
V_2 -> V_24 -> V_282 -> V_283 ;
V_12 -> V_170 = V_40 -> V_170 ;
if ( V_12 -> V_98 . V_177 >
V_284 )
V_12 -> V_98 . V_177 =
V_285 ;
F_57 ( V_103 ) ;
F_58 ( & V_286 ) ;
if ( V_12 -> V_179 )
V_238 = & V_237 [ V_287 ] ;
else
V_238 = & V_237 [ V_288 ] ;
F_39 ( V_2 , L_57 ,
V_2 -> V_12 . V_124 , V_238 -> V_245 ) ;
F_59 ( & V_2 -> V_289 , & V_238 -> V_2 ) ;
if ( V_238 -> V_240 ) {
V_2 -> V_243 = F_48 ( V_2 , V_238 ) ;
if ( ! V_2 -> V_243 ) {
F_60 ( & V_286 ) ;
goto V_290;
}
} else {
V_256 = true ;
}
F_60 ( & V_286 ) ;
F_61 ( & V_2 -> V_291 ) ;
if ( V_256 ) {
V_249 = F_62 ( L_58 , V_238 -> V_245 ) ;
#ifdef F_63
if ( V_249 )
F_11 ( V_2 ,
L_59 ,
V_238 -> V_245 , V_249 ) ;
#endif
}
F_5 ( V_40 ) ;
return;
V_260:
F_57 ( V_103 ) ;
if ( F_9 ( V_2 , false ) )
goto V_290;
F_5 ( V_40 ) ;
return;
V_262:
F_11 ( V_2 , L_60 ) ;
F_4 ( V_2 ) ;
F_57 ( V_103 ) ;
V_290:
F_5 ( V_40 ) ;
F_61 ( & V_2 -> V_291 ) ;
F_64 ( V_2 -> V_35 -> V_36 ) ;
}
struct V_1 * F_65 ( struct V_292 * V_35 ,
const struct V_233 * V_24 )
{
struct V_1 * V_2 ;
int V_293 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 ) {
V_293 = - V_20 ;
goto V_249;
}
V_2 -> V_35 = V_35 ;
V_2 -> V_36 = V_35 -> V_36 ;
V_2 -> V_24 = V_24 ;
F_66 ( & V_2 -> V_291 ) ;
F_67 ( & V_2 -> V_289 ) ;
#ifdef F_49
V_2 -> V_246 = F_50 ( F_68 ( V_35 -> V_36 ) ,
V_294 ) ;
if ( ! V_2 -> V_246 ) {
F_11 ( V_2 , L_61 ) ;
V_293 = - V_20 ;
goto V_295;
}
V_2 -> V_35 -> V_242 = F_50 ( L_62 , V_2 -> V_246 ) ;
if ( ! V_2 -> V_35 -> V_242 ) {
F_11 ( V_2 , L_63 ) ;
V_293 = - V_20 ;
goto V_296;
}
#endif
V_293 = F_9 ( V_2 , true ) ;
if ( V_293 ) {
F_11 ( V_35 , L_64 ) ;
goto V_297;
}
return V_2 ;
V_297:
#ifdef F_49
V_296:
F_51 ( V_2 -> V_246 ) ;
V_295:
#endif
F_5 ( V_2 ) ;
V_249:
return F_69 ( V_293 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_71 ( & V_2 -> V_291 ) ;
F_52 ( V_2 ) ;
F_4 ( V_2 ) ;
F_58 ( & V_286 ) ;
if ( ! F_72 ( & V_2 -> V_289 ) )
F_73 ( & V_2 -> V_289 ) ;
F_60 ( & V_286 ) ;
#ifdef F_49
F_51 ( V_2 -> V_246 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_74 ( const char * V_245 , const struct V_239 * V_240 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_237 * V_238 ;
F_58 ( & V_286 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ ) {
V_238 = & V_237 [ V_9 ] ;
if ( strcmp ( V_238 -> V_245 , V_245 ) )
continue;
V_238 -> V_240 = V_240 ;
F_75 (drv, &op->drv, list)
V_2 -> V_243 = F_48 ( V_2 , V_238 ) ;
F_60 ( & V_286 ) ;
return 0 ;
}
F_60 ( & V_286 ) ;
return - V_298 ;
}
void F_76 ( const char * V_245 )
{
int V_9 ;
struct V_1 * V_2 ;
F_58 ( & V_286 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ ) {
if ( strcmp ( V_237 [ V_9 ] . V_245 , V_245 ) )
continue;
V_237 [ V_9 ] . V_240 = NULL ;
F_75 (drv, &iwlwifi_opmode_table[i].drv, list)
F_52 ( V_2 ) ;
F_60 ( & V_286 ) ;
return;
}
F_60 ( & V_286 ) ;
}
static int T_4 F_77 ( void )
{
int V_9 ;
F_78 ( & V_286 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ )
F_67 ( & V_237 [ V_9 ] . V_2 ) ;
F_79 ( V_299 L_65 ) ;
F_79 ( V_300 L_65 ) ;
#ifdef F_49
V_294 = F_50 ( V_301 , NULL ) ;
if ( ! V_294 )
return - V_302 ;
#endif
return F_80 () ;
}
static void T_5 F_81 ( void )
{
F_82 () ;
#ifdef F_49
F_51 ( V_294 ) ;
#endif
}
