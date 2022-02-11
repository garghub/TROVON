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
static int F_23 ( struct V_43 * V_44 ,
const void * V_5 , enum V_45 type ,
int V_18 )
{
struct V_65 * V_8 ;
struct V_17 * V_11 ;
struct V_66 * V_67 ;
if ( F_24 ( ! V_44 || ! V_5 || type >= V_16 ) )
return - 1 ;
V_67 = (struct V_66 * ) V_5 ;
V_8 = & V_44 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_68 ] ;
V_11 -> V_21 = F_21 ( V_67 -> V_21 ) ;
V_11 -> V_5 = V_67 -> V_5 ;
V_11 -> V_18 = V_18 - sizeof( V_67 -> V_21 ) ;
++ V_8 -> V_68 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_69 * V_70 =
(struct V_69 * ) V_5 ;
T_2 V_71 = F_21 ( V_70 -> V_71 ) ;
if ( V_71 >= V_16 ) {
F_11 ( V_2 , L_8 ,
V_71 ) ;
return - V_19 ;
}
V_2 -> V_12 . V_72 [ V_71 ] . V_73 =
V_70 -> V_74 . V_73 ;
V_2 -> V_12 . V_72 [ V_71 ] . V_75 =
V_70 -> V_74 . V_75 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_76 * V_77 )
{
const struct V_78 * V_79 = ( void * ) V_5 ;
T_2 V_80 = F_21 ( V_79 -> V_80 ) ;
if ( V_80 >= V_81 ) {
F_11 ( V_2 , L_9 ) ;
return - V_19 ;
}
V_77 -> V_82 [ V_80 ] = F_21 ( V_79 -> V_83 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_76 * V_77 )
{
const struct V_84 * V_85 = ( void * ) V_5 ;
T_2 V_80 = F_21 ( V_85 -> V_80 ) ;
if ( V_80 >= V_86 ) {
F_11 ( V_2 , L_9 ) ;
return - V_19 ;
}
V_77 -> V_77 [ V_80 ] = F_21 ( V_85 -> V_87 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
struct V_43 * V_44 )
{
struct V_90 * V_91 = ( void * ) V_89 -> V_5 ;
T_2 V_92 , V_93 , V_94 ;
char V_95 [ 25 ] ;
const T_3 * V_96 ;
V_2 -> V_12 . V_97 = F_21 ( V_91 -> V_98 ) ;
V_92 = F_29 ( V_2 -> V_12 . V_97 ) ;
switch ( V_92 ) {
default:
V_93 = 28 ;
if ( V_89 -> V_18 < V_93 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_94 = F_21 ( V_91 -> V_99 . V_100 . V_94 ) ;
F_17 ( V_44 , V_101 , V_102 ,
F_21 ( V_91 -> V_99 . V_100 . V_103 ) ) ;
F_17 ( V_44 , V_101 , V_104 ,
F_21 ( V_91 -> V_99 . V_100 . V_105 ) ) ;
F_17 ( V_44 , V_106 , V_102 ,
F_21 ( V_91 -> V_99 . V_100 . V_107 ) ) ;
F_17 ( V_44 , V_106 , V_104 ,
F_21 ( V_91 -> V_99 . V_100 . V_108 ) ) ;
V_96 = V_91 -> V_99 . V_100 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_93 = 24 ;
if ( V_89 -> V_18 < V_93 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_94 = 0 ;
F_17 ( V_44 , V_101 , V_102 ,
F_21 ( V_91 -> V_99 . V_109 . V_103 ) ) ;
F_17 ( V_44 , V_101 , V_104 ,
F_21 ( V_91 -> V_99 . V_109 . V_105 ) ) ;
F_17 ( V_44 , V_106 , V_102 ,
F_21 ( V_91 -> V_99 . V_109 . V_107 ) ) ;
F_17 ( V_44 , V_106 , V_104 ,
F_21 ( V_91 -> V_99 . V_109 . V_108 ) ) ;
V_96 = V_91 -> V_99 . V_109 . V_5 ;
break;
}
if ( V_94 )
sprintf ( V_95 , L_11 , V_94 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_95 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_110 ,
sizeof( V_2 -> V_12 . V_110 ) ,
L_13 ,
F_30 ( V_2 -> V_12 . V_97 ) ,
F_31 ( V_2 -> V_12 . V_97 ) ,
F_29 ( V_2 -> V_12 . V_97 ) ,
F_32 ( V_2 -> V_12 . V_97 ) ,
V_95 ) ;
if ( V_89 -> V_18 != V_93 +
F_18 ( V_44 , V_101 , V_102 ) +
F_18 ( V_44 , V_101 , V_104 ) +
F_18 ( V_44 , V_106 , V_102 ) +
F_18 ( V_44 , V_106 , V_104 ) ) {
F_11 ( V_2 ,
L_14 ,
( int ) V_89 -> V_18 ) ;
return - V_19 ;
}
F_16 ( V_44 , V_101 , V_102 , V_96 ) ;
V_96 += F_18 ( V_44 , V_101 , V_102 ) ;
F_19 ( V_44 , V_101 , V_102 ,
V_111 ) ;
F_16 ( V_44 , V_101 , V_104 , V_96 ) ;
V_96 += F_18 ( V_44 , V_101 , V_104 ) ;
F_19 ( V_44 , V_101 , V_104 ,
V_112 ) ;
F_16 ( V_44 , V_106 , V_102 , V_96 ) ;
V_96 += F_18 ( V_44 , V_106 , V_102 ) ;
F_19 ( V_44 , V_106 , V_102 ,
V_111 ) ;
F_16 ( V_44 , V_106 , V_104 , V_96 ) ;
V_96 += F_18 ( V_44 , V_106 , V_104 ) ;
F_19 ( V_44 , V_106 , V_104 ,
V_112 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_88 * V_89 ,
struct V_43 * V_44 ,
struct V_76 * V_77 )
{
struct V_113 * V_91 = ( void * ) V_89 -> V_5 ;
struct V_114 * V_115 ;
T_1 V_6 = V_89 -> V_18 ;
const T_3 * V_5 ;
T_2 V_116 ;
enum V_117 V_118 ;
const T_3 * V_119 ;
char V_95 [ 25 ] ;
T_2 V_94 ;
int V_120 ;
bool V_121 = false ;
bool V_122 = false ;
if ( V_6 < sizeof( * V_91 ) ) {
F_11 ( V_2 , L_15 , V_6 ) ;
return - V_19 ;
}
if ( V_91 -> V_123 != F_34 ( V_124 ) ) {
F_11 ( V_2 , L_16 ,
F_21 ( V_91 -> V_123 ) ) ;
return - V_19 ;
}
V_2 -> V_12 . V_97 = F_21 ( V_91 -> V_98 ) ;
memcpy ( V_2 -> V_12 . V_125 , V_91 -> V_125 ,
sizeof( V_2 -> V_12 . V_125 ) ) ;
V_94 = F_21 ( V_91 -> V_94 ) ;
if ( V_94 )
sprintf ( V_95 , L_11 , V_94 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_95 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_110 ,
sizeof( V_2 -> V_12 . V_110 ) ,
L_13 ,
F_30 ( V_2 -> V_12 . V_97 ) ,
F_31 ( V_2 -> V_12 . V_97 ) ,
F_29 ( V_2 -> V_12 . V_97 ) ,
F_32 ( V_2 -> V_12 . V_97 ) ,
V_95 ) ;
V_5 = V_91 -> V_5 ;
V_6 -= sizeof( * V_91 ) ;
while ( V_6 >= sizeof( * V_115 ) ) {
V_6 -= sizeof( * V_115 ) ;
V_115 = ( void * ) V_5 ;
V_116 = F_21 ( V_115 -> V_126 ) ;
V_118 = F_21 ( V_115 -> type ) ;
V_119 = V_115 -> V_5 ;
if ( V_6 < V_116 ) {
F_11 ( V_2 , L_17 ,
V_6 , V_116 ) ;
return - V_19 ;
}
V_6 -= F_35 ( V_116 , 4 ) ;
V_5 += sizeof( * V_115 ) + F_35 ( V_116 , 4 ) ;
switch ( V_118 ) {
case V_127 :
F_16 ( V_44 , V_101 ,
V_102 , V_119 ) ;
F_17 ( V_44 , V_101 ,
V_102 , V_116 ) ;
F_19 ( V_44 , V_101 ,
V_102 ,
V_111 ) ;
break;
case V_128 :
F_16 ( V_44 , V_101 ,
V_104 , V_119 ) ;
F_17 ( V_44 , V_101 ,
V_104 , V_116 ) ;
F_19 ( V_44 , V_101 ,
V_104 ,
V_112 ) ;
break;
case V_129 :
F_16 ( V_44 , V_106 ,
V_102 , V_119 ) ;
F_17 ( V_44 , V_106 ,
V_102 , V_116 ) ;
F_19 ( V_44 , V_106 ,
V_102 ,
V_111 ) ;
break;
case V_130 :
F_16 ( V_44 , V_106 ,
V_104 , V_119 ) ;
F_17 ( V_44 , V_106 ,
V_104 , V_116 ) ;
F_19 ( V_44 , V_106 ,
V_104 ,
V_112 ) ;
break;
case V_131 :
F_11 ( V_2 , L_18 ) ;
break;
case V_132 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_77 -> V_134 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_136 :
if ( V_116 )
goto V_133;
V_77 -> V_137 |= V_138 ;
break;
case V_139 :
if ( V_116 < sizeof( T_2 ) )
goto V_133;
if ( V_116 % sizeof( T_2 ) )
goto V_133;
V_77 -> V_137 = F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_140 :
if ( V_116 != sizeof( struct V_78 ) )
goto V_133;
if ( F_26 ( V_2 , V_119 , V_77 ) )
goto V_141;
break;
case V_142 :
if ( V_116 != sizeof( struct V_84 ) )
goto V_133;
if ( F_27 ( V_2 , V_119 , V_77 ) )
goto V_141;
break;
case V_143 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_144 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_145 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_146 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_147 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_148 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_149 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_150 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_151 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_152 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_153 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_44 -> V_154 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_155 :
if ( V_116 )
goto V_133;
V_2 -> V_12 . V_156 = true ;
break;
case V_157 :
F_16 ( V_44 , V_158 ,
V_102 , V_119 ) ;
F_17 ( V_44 , V_158 ,
V_102 , V_116 ) ;
F_19 ( V_44 , V_158 ,
V_102 ,
V_111 ) ;
break;
case V_159 :
F_16 ( V_44 , V_158 ,
V_104 , V_119 ) ;
F_17 ( V_44 , V_158 ,
V_104 , V_116 ) ;
F_19 ( V_44 , V_158 ,
V_104 ,
V_112 ) ;
break;
case V_160 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_77 -> V_161 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_162 :
F_23 ( V_44 , V_119 , V_101 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_164 :
F_23 ( V_44 , V_119 , V_106 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_165 :
F_23 ( V_44 , V_119 , V_158 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_166 :
if ( V_116 != sizeof( struct V_69 ) )
goto V_133;
if ( F_25 ( V_2 , V_119 ) )
goto V_141;
break;
case V_167 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_2 -> V_12 . V_168 = F_36 ( ( V_135 * ) V_119 ) ;
V_2 -> V_12 . V_169 = ( V_2 -> V_12 . V_168 &
V_170 ) >>
V_171 ;
V_2 -> V_12 . V_172 = ( V_2 -> V_12 . V_168 &
V_173 ) >>
V_174 ;
break;
case V_175 :
F_23 ( V_44 , V_119 , V_101 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_176 :
F_23 ( V_44 , V_119 , V_106 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_177 :
F_23 ( V_44 , V_119 , V_158 ,
V_116 ) ;
V_2 -> V_12 . V_163 = true ;
break;
case V_178 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_120 =
F_36 ( ( V_135 * ) V_119 ) ;
if ( V_120 == 2 ) {
V_2 -> V_12 . V_8 [ V_101 ] . V_179 =
true ;
V_2 -> V_12 . V_8 [ V_106 ] . V_179 =
true ;
V_2 -> V_12 . V_8 [ V_158 ] . V_179 =
true ;
} else if ( ( V_120 > 2 ) || ( V_120 < 1 ) ) {
F_11 ( V_2 , L_19 ) ;
return - V_19 ;
}
break;
case V_180 :
if ( F_20 ( & V_2 -> V_12 , V_119 , V_116 ) )
goto V_133;
break;
case V_181 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_77 -> V_182 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
case V_183 : {
V_135 * V_184 = ( void * ) V_119 ;
T_2 V_185 , V_186 ;
T_3 V_187 ;
if ( V_116 != sizeof( T_2 ) * 3 )
goto V_133;
V_185 = F_36 ( V_184 ++ ) ;
V_186 = F_36 ( V_184 ++ ) ;
V_187 = F_36 ( V_184 ) ;
snprintf ( V_2 -> V_12 . V_110 ,
sizeof( V_2 -> V_12 . V_110 ) , L_20 ,
V_185 , V_186 , V_187 ) ;
break;
}
case V_188 : {
struct V_189 * V_190 = ( void * ) V_119 ;
if ( V_44 -> V_13 ) {
F_11 ( V_2 ,
L_21 ) ;
break;
}
V_44 -> V_13 = V_190 ;
F_37 ( V_2 , L_22 ,
F_38 ( V_190 -> V_191 ) ) ;
V_2 -> V_12 . V_192 =
V_116 - F_39 ( struct V_189 ,
V_193 ) ;
V_2 -> V_12 . V_192 /=
sizeof( V_2 -> V_12 . V_13 -> V_193 [ 0 ] ) ;
break;
}
case V_194 : {
struct V_195 * V_196 = ( void * ) V_119 ;
if ( ! V_44 -> V_13 ) {
F_11 ( V_2 ,
L_23 ,
V_196 -> V_197 ) ;
break;
}
if ( V_196 -> V_197 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_24 ,
V_196 -> V_197 ) ;
break;
}
if ( V_44 -> V_14 [ V_196 -> V_197 ] ) {
F_11 ( V_2 ,
L_25 ,
V_196 -> V_197 ) ;
break;
}
if ( V_196 -> V_198 )
V_122 = true ;
F_37 ( V_2 , L_26 ,
V_196 -> V_197 ) ;
V_44 -> V_14 [ V_196 -> V_197 ] = V_196 ;
V_44 -> V_199 [ V_196 -> V_197 ] = V_116 ;
break;
}
case V_200 : {
struct V_201 * V_202 =
( void * ) V_119 ;
T_2 V_203 = F_21 ( V_202 -> V_197 ) ;
if ( V_203 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_27 ,
V_202 -> V_197 ) ;
break;
}
if ( V_44 -> V_15 [ V_203 ] ) {
F_11 ( V_2 ,
L_28 ,
V_202 -> V_197 ) ;
break;
}
F_37 ( V_2 , L_29 , V_202 -> V_197 ) ;
V_44 -> V_15 [ V_203 ] = V_202 ;
V_44 -> V_204 [ V_203 ] = V_116 ;
break;
}
case V_205 :
V_121 = true ;
F_23 ( V_44 , V_119 ,
V_206 ,
V_116 ) ;
break;
case V_207 :
if ( V_116 != sizeof( T_2 ) )
goto V_133;
V_2 -> V_12 . V_208 =
F_36 ( ( V_135 * ) V_119 ) ;
break;
default:
F_13 ( V_2 , L_30 , V_118 ) ;
break;
}
}
if ( V_122 && ! V_121 ) {
F_11 ( V_2 ,
L_31 ) ;
return - V_19 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_32 , V_6 ) ;
F_40 ( V_2 , V_209 , ( T_3 * ) V_5 , V_6 ) ;
return - V_19 ;
}
return 0 ;
V_133:
F_11 ( V_2 , L_33 , V_118 , V_116 ) ;
V_141:
F_40 ( V_2 , V_209 , V_119 , V_116 ) ;
return - V_19 ;
}
static int F_41 ( struct V_1 * V_2 ,
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
static int F_42 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
const struct V_210 * V_24 )
{
F_13 ( V_2 , L_34 ,
F_18 ( V_44 , V_101 ,
V_102 ) ) ;
F_13 ( V_2 , L_35 ,
F_18 ( V_44 , V_101 ,
V_104 ) ) ;
F_13 ( V_2 , L_36 ,
F_18 ( V_44 , V_106 , V_102 ) ) ;
F_13 ( V_2 , L_37 ,
F_18 ( V_44 , V_106 , V_104 ) ) ;
if ( F_18 ( V_44 , V_101 , V_102 ) >
V_24 -> V_211 ) {
F_11 ( V_2 , L_38 ,
F_18 ( V_44 , V_101 ,
V_102 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_101 , V_104 ) >
V_24 -> V_212 ) {
F_11 ( V_2 , L_39 ,
F_18 ( V_44 , V_101 ,
V_104 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_106 , V_102 ) >
V_24 -> V_211 ) {
F_11 ( V_2 , L_40 ,
F_18 ( V_44 , V_106 ,
V_102 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_106 , V_104 ) >
V_24 -> V_212 ) {
F_11 ( V_2 , L_41 ,
F_18 ( V_44 , V_101 ,
V_104 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_213 *
F_43 ( struct V_1 * V_2 , struct V_214 * V_215 )
{
const struct V_216 * V_217 = V_215 -> V_217 ;
struct V_218 * V_219 = NULL ;
struct V_213 * V_220 = NULL ;
#ifdef F_44
V_2 -> V_221 = F_45 ( V_215 -> V_222 ,
V_2 -> V_223 ) ;
if ( ! V_2 -> V_221 ) {
F_11 ( V_2 ,
L_42 ) ;
return V_220 ;
}
V_219 = V_2 -> V_221 ;
#endif
V_220 = V_217 -> V_224 ( V_2 -> V_34 , V_2 -> V_24 , & V_2 -> V_12 , V_219 ) ;
#ifdef F_44
if ( ! V_220 ) {
F_46 ( V_2 -> V_221 ) ;
V_2 -> V_221 = NULL ;
}
#endif
return V_220 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_220 ) {
F_48 ( V_2 -> V_220 ) ;
V_2 -> V_220 = NULL ;
#ifdef F_44
F_46 ( V_2 -> V_221 ) ;
V_2 -> V_221 = NULL ;
#endif
}
}
static void V_42 ( const struct V_88 * V_89 , void * V_225 )
{
struct V_1 * V_2 = V_225 ;
struct V_46 * V_12 = & V_2 -> V_12 ;
struct V_90 * V_91 ;
struct V_214 * V_215 ;
int V_226 ;
struct V_43 * V_44 ;
const unsigned int V_227 = V_2 -> V_24 -> V_30 ;
unsigned int V_228 = V_2 -> V_24 -> V_229 ;
const unsigned int V_230 = V_2 -> V_24 -> V_31 ;
T_1 V_231 [ V_232 ] ;
T_2 V_92 ;
int V_9 ;
bool V_233 = false ;
V_12 -> V_85 . V_134 = V_234 ;
V_12 -> V_85 . V_161 =
V_235 ;
V_12 -> V_85 . V_182 = V_236 ;
if ( ! V_228 )
V_228 = V_227 ;
V_44 = F_49 ( sizeof( * V_44 ) , V_41 ) ;
if ( ! V_44 )
return;
if ( ! V_89 ) {
if ( V_2 -> V_27 <= V_228 )
F_11 ( V_2 ,
L_43 ,
V_2 -> V_33 ) ;
goto V_237;
}
F_13 ( V_2 , L_44 ,
V_2 -> V_33 , V_89 -> V_18 ) ;
if ( V_89 -> V_18 < 4 ) {
F_11 ( V_2 , L_45 ) ;
goto V_237;
}
V_91 = (struct V_90 * ) V_89 -> V_5 ;
if ( V_91 -> V_98 )
V_226 = F_28 ( V_2 , V_89 , V_44 ) ;
else
V_226 = F_33 ( V_2 , V_89 , V_44 ,
& V_12 -> V_85 ) ;
if ( V_226 )
goto V_237;
if ( V_2 -> V_12 . V_85 . V_82 [ 0 ] & V_238 )
V_92 = V_2 -> V_12 . V_97 ;
else
V_92 = F_29 ( V_2 -> V_12 . V_97 ) ;
if ( V_2 -> V_27 != V_28 ) {
if ( V_92 < V_230 || V_92 > V_227 ) {
F_11 ( V_2 ,
L_46
L_47 ,
V_227 , V_92 ) ;
goto V_237;
}
if ( V_92 < V_228 ) {
if ( V_228 != V_227 )
F_11 ( V_2 , L_48
L_49 ,
V_228 , V_227 , V_92 ) ;
else
F_11 ( V_2 , L_48
L_50 ,
V_227 , V_92 ) ;
F_11 ( V_2 , L_51
L_52 ) ;
}
}
if ( ! V_12 -> V_163 && F_42 ( V_2 , V_44 , V_2 -> V_24 ) )
goto V_237;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( F_41 ( V_2 , V_44 , V_9 ) )
goto V_239;
if ( V_44 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_50 ( V_44 -> V_13 ,
sizeof( * V_44 -> V_13 ) +
sizeof( V_44 -> V_13 -> V_193 [ 0 ] ) *
V_2 -> V_12 . V_192 , V_41 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_239;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_44 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_199 [ V_9 ] =
V_44 -> V_199 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_50 ( V_44 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_199 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_239;
}
}
memset ( & V_231 , 0xff , sizeof( V_231 ) ) ;
V_231 [ V_240 ] =
sizeof( struct V_241 ) ;
V_231 [ V_242 ] = 0 ;
V_231 [ V_243 ] =
sizeof( struct V_244 ) ;
V_231 [ V_245 ] =
sizeof( struct V_246 ) ;
V_231 [ V_247 ] =
sizeof( struct V_248 ) ;
V_231 [ V_249 ] =
sizeof( struct V_250 ) ;
V_231 [ V_251 ] =
sizeof( struct V_252 ) ;
V_231 [ V_253 ] =
sizeof( struct V_254 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_44 -> V_15 [ V_9 ] ) {
if ( F_24 ( V_44 -> V_204 [ V_9 ] <
( V_231 [ V_9 ] +
sizeof( struct V_201 ) ) ) )
goto V_239;
V_2 -> V_12 . V_204 [ V_9 ] =
V_44 -> V_204 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_50 ( V_44 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_204 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_239;
}
}
V_12 -> V_144 = V_44 -> V_144 ;
if ( V_44 -> V_146 )
V_12 -> V_146 = ( V_44 -> V_146 - 16 ) / 12 ;
else
V_12 -> V_146 =
V_2 -> V_24 -> V_255 -> V_256 ;
V_12 -> V_148 = V_44 -> V_148 ;
V_12 -> V_150 = V_44 -> V_150 ;
if ( V_44 -> V_152 )
V_12 -> V_152 = ( V_44 -> V_152 - 16 ) / 12 ;
else
V_12 -> V_152 =
V_2 -> V_24 -> V_255 -> V_256 ;
V_12 -> V_154 = V_44 -> V_154 ;
if ( V_12 -> V_85 . V_161 >
V_257 )
V_12 -> V_85 . V_161 =
V_258 ;
F_51 ( V_89 ) ;
F_52 ( & V_259 ) ;
if ( V_12 -> V_163 )
V_215 = & V_214 [ V_260 ] ;
else
V_215 = & V_214 [ V_261 ] ;
F_37 ( V_2 , L_53 ,
V_2 -> V_12 . V_110 , V_215 -> V_222 ) ;
F_53 ( & V_2 -> V_262 , & V_215 -> V_2 ) ;
if ( V_215 -> V_217 ) {
V_2 -> V_220 = F_43 ( V_2 , V_215 ) ;
if ( ! V_2 -> V_220 ) {
F_54 ( & V_259 ) ;
goto V_263;
}
} else {
V_233 = true ;
}
F_54 ( & V_259 ) ;
F_55 ( & V_2 -> V_264 ) ;
if ( V_233 ) {
V_226 = F_56 ( L_54 , V_215 -> V_222 ) ;
#ifdef F_57
if ( V_226 )
F_11 ( V_2 ,
L_55 ,
V_215 -> V_222 , V_226 ) ;
#endif
}
F_5 ( V_44 ) ;
return;
V_237:
F_51 ( V_89 ) ;
if ( F_9 ( V_2 , false ) )
goto V_263;
F_5 ( V_44 ) ;
return;
V_239:
F_11 ( V_2 , L_56 ) ;
F_4 ( V_2 ) ;
F_51 ( V_89 ) ;
V_263:
F_5 ( V_44 ) ;
F_55 ( & V_2 -> V_264 ) ;
F_58 ( V_2 -> V_34 -> V_40 ) ;
}
struct V_1 * F_59 ( struct V_265 * V_34 ,
const struct V_210 * V_24 )
{
struct V_1 * V_2 ;
int V_266 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 ) {
V_266 = - V_20 ;
goto V_226;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_24 = V_24 ;
F_60 ( & V_2 -> V_264 ) ;
F_61 ( & V_2 -> V_262 ) ;
#ifdef F_44
V_2 -> V_223 = F_45 ( F_62 ( V_34 -> V_40 ) ,
V_267 ) ;
if ( ! V_2 -> V_223 ) {
F_11 ( V_2 , L_57 ) ;
V_266 = - V_20 ;
goto V_268;
}
V_2 -> V_34 -> V_219 = F_45 ( L_58 , V_2 -> V_223 ) ;
if ( ! V_2 -> V_34 -> V_219 ) {
F_11 ( V_2 , L_59 ) ;
V_266 = - V_20 ;
goto V_269;
}
#endif
V_266 = F_9 ( V_2 , true ) ;
if ( V_266 ) {
F_11 ( V_34 , L_60 ) ;
goto V_270;
}
return V_2 ;
V_270:
#ifdef F_44
V_269:
F_46 ( V_2 -> V_223 ) ;
V_268:
#endif
F_5 ( V_2 ) ;
V_226:
return F_63 ( V_266 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_264 ) ;
F_47 ( V_2 ) ;
F_4 ( V_2 ) ;
F_52 ( & V_259 ) ;
if ( ! F_66 ( & V_2 -> V_262 ) )
F_67 ( & V_2 -> V_262 ) ;
F_54 ( & V_259 ) ;
#ifdef F_44
F_46 ( V_2 -> V_223 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_68 ( const char * V_222 , const struct V_216 * V_217 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_214 * V_215 ;
F_52 ( & V_259 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_214 ) ; V_9 ++ ) {
V_215 = & V_214 [ V_9 ] ;
if ( strcmp ( V_215 -> V_222 , V_222 ) )
continue;
V_215 -> V_217 = V_217 ;
F_69 (drv, &op->drv, list)
V_2 -> V_220 = F_43 ( V_2 , V_215 ) ;
F_54 ( & V_259 ) ;
return 0 ;
}
F_54 ( & V_259 ) ;
return - V_271 ;
}
void F_70 ( const char * V_222 )
{
int V_9 ;
struct V_1 * V_2 ;
F_52 ( & V_259 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_214 ) ; V_9 ++ ) {
if ( strcmp ( V_214 [ V_9 ] . V_222 , V_222 ) )
continue;
V_214 [ V_9 ] . V_217 = NULL ;
F_69 (drv, &iwlwifi_opmode_table[i].drv, list)
F_47 ( V_2 ) ;
F_54 ( & V_259 ) ;
return;
}
F_54 ( & V_259 ) ;
}
static int T_4 F_71 ( void )
{
int V_9 ;
F_72 ( & V_259 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_214 ) ; V_9 ++ )
F_61 ( & V_214 [ V_9 ] . V_2 ) ;
F_73 ( V_272 L_61 ) ;
F_73 ( V_273 L_61 ) ;
#ifdef F_44
V_267 = F_45 ( V_274 , NULL ) ;
if ( ! V_267 )
return - V_275 ;
#endif
return F_74 () ;
}
static void T_5 F_75 ( void )
{
F_76 () ;
#ifdef F_44
F_46 ( V_267 ) ;
#endif
}
