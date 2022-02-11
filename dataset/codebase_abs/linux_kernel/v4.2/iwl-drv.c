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
T_2 V_81 = F_21 ( V_79 -> V_81 ) ;
int V_9 ;
if ( V_80 >= V_82 / 32 ) {
F_11 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_81 & F_22 ( V_9 ) )
F_27 ( V_9 + 32 * V_80 , V_77 -> V_83 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_76 * V_77 )
{
const struct V_84 * V_85 = ( void * ) V_5 ;
T_2 V_80 = F_21 ( V_85 -> V_80 ) ;
T_2 V_81 = F_21 ( V_85 -> V_86 ) ;
int V_9 ;
if ( V_80 >= V_87 / 32 ) {
F_11 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_81 & F_22 ( V_9 ) )
F_27 ( V_9 + 32 * V_80 , V_77 -> V_88 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_89 * V_90 ,
struct V_43 * V_44 )
{
struct V_91 * V_92 = ( void * ) V_90 -> V_5 ;
T_2 V_93 , V_94 , V_95 ;
char V_96 [ 25 ] ;
const T_3 * V_97 ;
V_2 -> V_12 . V_98 = F_21 ( V_92 -> V_99 ) ;
V_93 = F_30 ( V_2 -> V_12 . V_98 ) ;
switch ( V_93 ) {
default:
V_94 = 28 ;
if ( V_90 -> V_18 < V_94 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_95 = F_21 ( V_92 -> V_100 . V_101 . V_95 ) ;
F_17 ( V_44 , V_102 , V_103 ,
F_21 ( V_92 -> V_100 . V_101 . V_104 ) ) ;
F_17 ( V_44 , V_102 , V_105 ,
F_21 ( V_92 -> V_100 . V_101 . V_106 ) ) ;
F_17 ( V_44 , V_107 , V_103 ,
F_21 ( V_92 -> V_100 . V_101 . V_108 ) ) ;
F_17 ( V_44 , V_107 , V_105 ,
F_21 ( V_92 -> V_100 . V_101 . V_109 ) ) ;
V_97 = V_92 -> V_100 . V_101 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_94 = 24 ;
if ( V_90 -> V_18 < V_94 ) {
F_11 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_95 = 0 ;
F_17 ( V_44 , V_102 , V_103 ,
F_21 ( V_92 -> V_100 . V_110 . V_104 ) ) ;
F_17 ( V_44 , V_102 , V_105 ,
F_21 ( V_92 -> V_100 . V_110 . V_106 ) ) ;
F_17 ( V_44 , V_107 , V_103 ,
F_21 ( V_92 -> V_100 . V_110 . V_108 ) ) ;
F_17 ( V_44 , V_107 , V_105 ,
F_21 ( V_92 -> V_100 . V_110 . V_109 ) ) ;
V_97 = V_92 -> V_100 . V_110 . V_5 ;
break;
}
if ( V_95 )
sprintf ( V_96 , L_11 , V_95 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_96 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_111 ,
sizeof( V_2 -> V_12 . V_111 ) ,
L_13 ,
F_31 ( V_2 -> V_12 . V_98 ) ,
F_32 ( V_2 -> V_12 . V_98 ) ,
F_30 ( V_2 -> V_12 . V_98 ) ,
F_33 ( V_2 -> V_12 . V_98 ) ,
V_96 ) ;
if ( V_90 -> V_18 != V_94 +
F_18 ( V_44 , V_102 , V_103 ) +
F_18 ( V_44 , V_102 , V_105 ) +
F_18 ( V_44 , V_107 , V_103 ) +
F_18 ( V_44 , V_107 , V_105 ) ) {
F_11 ( V_2 ,
L_14 ,
( int ) V_90 -> V_18 ) ;
return - V_19 ;
}
F_16 ( V_44 , V_102 , V_103 , V_97 ) ;
V_97 += F_18 ( V_44 , V_102 , V_103 ) ;
F_19 ( V_44 , V_102 , V_103 ,
V_112 ) ;
F_16 ( V_44 , V_102 , V_105 , V_97 ) ;
V_97 += F_18 ( V_44 , V_102 , V_105 ) ;
F_19 ( V_44 , V_102 , V_105 ,
V_113 ) ;
F_16 ( V_44 , V_107 , V_103 , V_97 ) ;
V_97 += F_18 ( V_44 , V_107 , V_103 ) ;
F_19 ( V_44 , V_107 , V_103 ,
V_112 ) ;
F_16 ( V_44 , V_107 , V_105 , V_97 ) ;
V_97 += F_18 ( V_44 , V_107 , V_105 ) ;
F_19 ( V_44 , V_107 , V_105 ,
V_113 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_89 * V_90 ,
struct V_43 * V_44 ,
struct V_76 * V_77 )
{
struct V_114 * V_92 = ( void * ) V_90 -> V_5 ;
struct V_115 * V_116 ;
T_1 V_6 = V_90 -> V_18 ;
const T_3 * V_5 ;
T_2 V_117 ;
enum V_118 V_119 ;
const T_3 * V_120 ;
char V_96 [ 25 ] ;
T_2 V_95 ;
int V_121 ;
bool V_122 = false ;
bool V_123 = false ;
if ( V_6 < sizeof( * V_92 ) ) {
F_11 ( V_2 , L_15 , V_6 ) ;
return - V_19 ;
}
if ( V_92 -> V_124 != F_35 ( V_125 ) ) {
F_11 ( V_2 , L_16 ,
F_21 ( V_92 -> V_124 ) ) ;
return - V_19 ;
}
V_2 -> V_12 . V_98 = F_21 ( V_92 -> V_99 ) ;
memcpy ( V_2 -> V_12 . V_126 , V_92 -> V_126 ,
sizeof( V_2 -> V_12 . V_126 ) ) ;
V_95 = F_21 ( V_92 -> V_95 ) ;
if ( V_95 )
sprintf ( V_96 , L_11 , V_95 ,
( V_2 -> V_27 == V_28 )
? L_12 : L_7 ) ;
else
V_96 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_111 ,
sizeof( V_2 -> V_12 . V_111 ) ,
L_13 ,
F_31 ( V_2 -> V_12 . V_98 ) ,
F_32 ( V_2 -> V_12 . V_98 ) ,
F_30 ( V_2 -> V_12 . V_98 ) ,
F_33 ( V_2 -> V_12 . V_98 ) ,
V_96 ) ;
V_5 = V_92 -> V_5 ;
V_6 -= sizeof( * V_92 ) ;
while ( V_6 >= sizeof( * V_116 ) ) {
V_6 -= sizeof( * V_116 ) ;
V_116 = ( void * ) V_5 ;
V_117 = F_21 ( V_116 -> V_127 ) ;
V_119 = F_21 ( V_116 -> type ) ;
V_120 = V_116 -> V_5 ;
if ( V_6 < V_117 ) {
F_11 ( V_2 , L_17 ,
V_6 , V_117 ) ;
return - V_19 ;
}
V_6 -= F_36 ( V_117 , 4 ) ;
V_5 += sizeof( * V_116 ) + F_36 ( V_117 , 4 ) ;
switch ( V_119 ) {
case V_128 :
F_16 ( V_44 , V_102 ,
V_103 , V_120 ) ;
F_17 ( V_44 , V_102 ,
V_103 , V_117 ) ;
F_19 ( V_44 , V_102 ,
V_103 ,
V_112 ) ;
break;
case V_129 :
F_16 ( V_44 , V_102 ,
V_105 , V_120 ) ;
F_17 ( V_44 , V_102 ,
V_105 , V_117 ) ;
F_19 ( V_44 , V_102 ,
V_105 ,
V_113 ) ;
break;
case V_130 :
F_16 ( V_44 , V_107 ,
V_103 , V_120 ) ;
F_17 ( V_44 , V_107 ,
V_103 , V_117 ) ;
F_19 ( V_44 , V_107 ,
V_103 ,
V_112 ) ;
break;
case V_131 :
F_16 ( V_44 , V_107 ,
V_105 , V_120 ) ;
F_17 ( V_44 , V_107 ,
V_105 , V_117 ) ;
F_19 ( V_44 , V_107 ,
V_105 ,
V_113 ) ;
break;
case V_132 :
F_11 ( V_2 , L_18 ) ;
break;
case V_133 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_77 -> V_135 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_137 :
if ( V_117 )
goto V_134;
V_77 -> V_138 |= V_139 ;
break;
case V_140 :
if ( V_117 < sizeof( T_2 ) )
goto V_134;
if ( V_117 % sizeof( T_2 ) )
goto V_134;
V_77 -> V_138 = F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_141 :
if ( V_117 != sizeof( struct V_78 ) )
goto V_134;
if ( F_26 ( V_2 , V_120 , V_77 ) )
goto V_142;
break;
case V_143 :
if ( V_117 != sizeof( struct V_84 ) )
goto V_134;
if ( F_28 ( V_2 , V_120 , V_77 ) )
goto V_142;
break;
case V_144 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_145 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_146 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_147 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_148 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_149 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_150 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_151 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_152 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_153 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_154 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_44 -> V_155 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_156 :
if ( V_117 )
goto V_134;
V_2 -> V_12 . V_157 = true ;
break;
case V_158 :
F_16 ( V_44 , V_159 ,
V_103 , V_120 ) ;
F_17 ( V_44 , V_159 ,
V_103 , V_117 ) ;
F_19 ( V_44 , V_159 ,
V_103 ,
V_112 ) ;
break;
case V_160 :
F_16 ( V_44 , V_159 ,
V_105 , V_120 ) ;
F_17 ( V_44 , V_159 ,
V_105 , V_117 ) ;
F_19 ( V_44 , V_159 ,
V_105 ,
V_113 ) ;
break;
case V_161 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_77 -> V_162 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_163 :
F_23 ( V_44 , V_120 , V_102 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_165 :
F_23 ( V_44 , V_120 , V_107 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_166 :
F_23 ( V_44 , V_120 , V_159 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_167 :
if ( V_117 != sizeof( struct V_69 ) )
goto V_134;
if ( F_25 ( V_2 , V_120 ) )
goto V_142;
break;
case V_168 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_2 -> V_12 . V_169 = F_37 ( ( V_136 * ) V_120 ) ;
V_2 -> V_12 . V_170 = ( V_2 -> V_12 . V_169 &
V_171 ) >>
V_172 ;
V_2 -> V_12 . V_173 = ( V_2 -> V_12 . V_169 &
V_174 ) >>
V_175 ;
break;
case V_176 :
F_23 ( V_44 , V_120 , V_102 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_177 :
F_23 ( V_44 , V_120 , V_107 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_178 :
F_23 ( V_44 , V_120 , V_159 ,
V_117 ) ;
V_2 -> V_12 . V_164 = true ;
break;
case V_179 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_121 =
F_37 ( ( V_136 * ) V_120 ) ;
if ( V_121 == 2 ) {
V_2 -> V_12 . V_8 [ V_102 ] . V_180 =
true ;
V_2 -> V_12 . V_8 [ V_107 ] . V_180 =
true ;
V_2 -> V_12 . V_8 [ V_159 ] . V_180 =
true ;
} else if ( ( V_121 > 2 ) || ( V_121 < 1 ) ) {
F_11 ( V_2 , L_19 ) ;
return - V_19 ;
}
break;
case V_181 :
if ( F_20 ( & V_2 -> V_12 , V_120 , V_117 ) )
goto V_134;
break;
case V_182 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_77 -> V_183 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
case V_184 : {
V_136 * V_185 = ( void * ) V_120 ;
T_2 V_186 , V_187 ;
T_3 V_188 ;
if ( V_117 != sizeof( T_2 ) * 3 )
goto V_134;
V_186 = F_37 ( V_185 ++ ) ;
V_187 = F_37 ( V_185 ++ ) ;
V_188 = F_37 ( V_185 ) ;
snprintf ( V_2 -> V_12 . V_111 ,
sizeof( V_2 -> V_12 . V_111 ) , L_20 ,
V_186 , V_187 , V_188 ) ;
break;
}
case V_189 : {
struct V_190 * V_191 = ( void * ) V_120 ;
if ( V_44 -> V_13 ) {
F_11 ( V_2 ,
L_21 ) ;
break;
}
V_44 -> V_13 = V_191 ;
F_38 ( V_2 , L_22 ,
F_39 ( V_191 -> V_192 ) ) ;
V_2 -> V_12 . V_193 =
V_117 - F_40 ( struct V_190 ,
V_194 ) ;
V_2 -> V_12 . V_193 /=
sizeof( V_2 -> V_12 . V_13 -> V_194 [ 0 ] ) ;
break;
}
case V_195 : {
struct V_196 * V_197 = ( void * ) V_120 ;
if ( ! V_44 -> V_13 ) {
F_11 ( V_2 ,
L_23 ,
V_197 -> V_198 ) ;
break;
}
if ( V_197 -> V_198 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_24 ,
V_197 -> V_198 ) ;
break;
}
if ( V_44 -> V_14 [ V_197 -> V_198 ] ) {
F_11 ( V_2 ,
L_25 ,
V_197 -> V_198 ) ;
break;
}
if ( V_197 -> V_199 )
V_123 = true ;
F_38 ( V_2 , L_26 ,
V_197 -> V_198 ) ;
V_44 -> V_14 [ V_197 -> V_198 ] = V_197 ;
V_44 -> V_200 [ V_197 -> V_198 ] = V_117 ;
break;
}
case V_201 : {
struct V_202 * V_203 =
( void * ) V_120 ;
T_2 V_204 = F_21 ( V_203 -> V_198 ) ;
if ( V_204 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_27 ,
V_203 -> V_198 ) ;
break;
}
if ( V_44 -> V_15 [ V_204 ] ) {
F_11 ( V_2 ,
L_28 ,
V_203 -> V_198 ) ;
break;
}
F_38 ( V_2 , L_29 , V_203 -> V_198 ) ;
V_44 -> V_15 [ V_204 ] = V_203 ;
V_44 -> V_205 [ V_204 ] = V_117 ;
break;
}
case V_206 :
V_122 = true ;
F_23 ( V_44 , V_120 ,
V_207 ,
V_117 ) ;
break;
case V_208 :
if ( V_117 != sizeof( T_2 ) )
goto V_134;
V_2 -> V_12 . V_209 =
F_37 ( ( V_136 * ) V_120 ) ;
break;
default:
F_13 ( V_2 , L_30 , V_119 ) ;
break;
}
}
if ( V_123 && ! V_122 ) {
F_11 ( V_2 ,
L_31 ) ;
return - V_19 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_32 , V_6 ) ;
F_41 ( V_2 , V_210 , ( T_3 * ) V_5 , V_6 ) ;
return - V_19 ;
}
return 0 ;
V_134:
F_11 ( V_2 , L_33 , V_119 , V_117 ) ;
V_142:
F_41 ( V_2 , V_210 , V_120 , V_117 ) ;
return - V_19 ;
}
static int F_42 ( struct V_1 * V_2 ,
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
static int F_43 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
const struct V_211 * V_24 )
{
F_13 ( V_2 , L_34 ,
F_18 ( V_44 , V_102 ,
V_103 ) ) ;
F_13 ( V_2 , L_35 ,
F_18 ( V_44 , V_102 ,
V_105 ) ) ;
F_13 ( V_2 , L_36 ,
F_18 ( V_44 , V_107 , V_103 ) ) ;
F_13 ( V_2 , L_37 ,
F_18 ( V_44 , V_107 , V_105 ) ) ;
if ( F_18 ( V_44 , V_102 , V_103 ) >
V_24 -> V_212 ) {
F_11 ( V_2 , L_38 ,
F_18 ( V_44 , V_102 ,
V_103 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_102 , V_105 ) >
V_24 -> V_213 ) {
F_11 ( V_2 , L_39 ,
F_18 ( V_44 , V_102 ,
V_105 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_107 , V_103 ) >
V_24 -> V_212 ) {
F_11 ( V_2 , L_40 ,
F_18 ( V_44 , V_107 ,
V_103 ) ) ;
return - 1 ;
}
if ( F_18 ( V_44 , V_107 , V_105 ) >
V_24 -> V_213 ) {
F_11 ( V_2 , L_41 ,
F_18 ( V_44 , V_102 ,
V_105 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_214 *
F_44 ( struct V_1 * V_2 , struct V_215 * V_216 )
{
const struct V_217 * V_218 = V_216 -> V_218 ;
struct V_219 * V_220 = NULL ;
struct V_214 * V_221 = NULL ;
#ifdef F_45
V_2 -> V_222 = F_46 ( V_216 -> V_223 ,
V_2 -> V_224 ) ;
if ( ! V_2 -> V_222 ) {
F_11 ( V_2 ,
L_42 ) ;
return V_221 ;
}
V_220 = V_2 -> V_222 ;
#endif
V_221 = V_218 -> V_225 ( V_2 -> V_34 , V_2 -> V_24 , & V_2 -> V_12 , V_220 ) ;
#ifdef F_45
if ( ! V_221 ) {
F_47 ( V_2 -> V_222 ) ;
V_2 -> V_222 = NULL ;
}
#endif
return V_221 ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_221 ) {
F_49 ( V_2 -> V_221 ) ;
V_2 -> V_221 = NULL ;
#ifdef F_45
F_47 ( V_2 -> V_222 ) ;
V_2 -> V_222 = NULL ;
#endif
}
}
static void V_42 ( const struct V_89 * V_90 , void * V_226 )
{
struct V_1 * V_2 = V_226 ;
struct V_46 * V_12 = & V_2 -> V_12 ;
struct V_91 * V_92 ;
struct V_215 * V_216 ;
int V_227 ;
struct V_43 * V_44 ;
const unsigned int V_228 = V_2 -> V_24 -> V_30 ;
unsigned int V_229 = V_2 -> V_24 -> V_230 ;
const unsigned int V_231 = V_2 -> V_24 -> V_31 ;
T_1 V_232 [ V_233 ] ;
T_2 V_93 ;
int V_9 ;
bool V_234 = false ;
V_12 -> V_85 . V_135 = V_235 ;
V_12 -> V_85 . V_162 =
V_236 ;
V_12 -> V_85 . V_183 = V_237 ;
if ( ! V_229 )
V_229 = V_228 ;
V_44 = F_50 ( sizeof( * V_44 ) , V_41 ) ;
if ( ! V_44 )
return;
if ( ! V_90 ) {
if ( V_2 -> V_27 <= V_229 )
F_11 ( V_2 ,
L_43 ,
V_2 -> V_33 ) ;
goto V_238;
}
F_13 ( V_2 , L_44 ,
V_2 -> V_33 , V_90 -> V_18 ) ;
if ( V_90 -> V_18 < 4 ) {
F_11 ( V_2 , L_45 ) ;
goto V_238;
}
V_92 = (struct V_91 * ) V_90 -> V_5 ;
if ( V_92 -> V_99 )
V_227 = F_29 ( V_2 , V_90 , V_44 ) ;
else
V_227 = F_34 ( V_2 , V_90 , V_44 ,
& V_12 -> V_85 ) ;
if ( V_227 )
goto V_238;
if ( F_51 ( & V_2 -> V_12 . V_85 , V_239 ) )
V_93 = V_2 -> V_12 . V_98 ;
else
V_93 = F_30 ( V_2 -> V_12 . V_98 ) ;
if ( V_2 -> V_27 != V_28 ) {
if ( V_93 < V_231 || V_93 > V_228 ) {
F_11 ( V_2 ,
L_46
L_47 ,
V_228 , V_93 ) ;
goto V_238;
}
if ( V_93 < V_229 ) {
if ( V_229 != V_228 )
F_11 ( V_2 , L_48
L_49 ,
V_229 , V_228 , V_93 ) ;
else
F_11 ( V_2 , L_48
L_50 ,
V_228 , V_93 ) ;
F_11 ( V_2 , L_51
L_52 ) ;
}
}
if ( ! V_12 -> V_164 && F_43 ( V_2 , V_44 , V_2 -> V_24 ) )
goto V_238;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
if ( F_42 ( V_2 , V_44 , V_9 ) )
goto V_240;
if ( V_44 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_52 ( V_44 -> V_13 ,
sizeof( * V_44 -> V_13 ) +
sizeof( V_44 -> V_13 -> V_194 [ 0 ] ) *
V_2 -> V_12 . V_193 , V_41 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_240;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_44 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_200 [ V_9 ] =
V_44 -> V_200 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_52 ( V_44 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_200 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_240;
}
}
memset ( & V_232 , 0xff , sizeof( V_232 ) ) ;
V_232 [ V_241 ] =
sizeof( struct V_242 ) ;
V_232 [ V_243 ] = 0 ;
V_232 [ V_244 ] =
sizeof( struct V_245 ) ;
V_232 [ V_246 ] =
sizeof( struct V_247 ) ;
V_232 [ V_248 ] =
sizeof( struct V_249 ) ;
V_232 [ V_250 ] =
sizeof( struct V_251 ) ;
V_232 [ V_252 ] =
sizeof( struct V_253 ) ;
V_232 [ V_254 ] =
sizeof( struct V_255 ) ;
V_232 [ V_256 ] =
sizeof( struct V_257 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_44 -> V_15 [ V_9 ] ) {
if ( F_24 ( V_44 -> V_205 [ V_9 ] <
( V_232 [ V_9 ] +
sizeof( struct V_202 ) ) ) )
goto V_240;
V_2 -> V_12 . V_205 [ V_9 ] =
V_44 -> V_205 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_52 ( V_44 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_205 [ V_9 ] ,
V_41 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_240;
}
}
V_12 -> V_145 = V_44 -> V_145 ;
if ( V_44 -> V_147 )
V_12 -> V_147 = ( V_44 -> V_147 - 16 ) / 12 ;
else
V_12 -> V_147 =
V_2 -> V_24 -> V_258 -> V_259 ;
V_12 -> V_149 = V_44 -> V_149 ;
V_12 -> V_151 = V_44 -> V_151 ;
if ( V_44 -> V_153 )
V_12 -> V_153 = ( V_44 -> V_153 - 16 ) / 12 ;
else
V_12 -> V_153 =
V_2 -> V_24 -> V_258 -> V_259 ;
V_12 -> V_155 = V_44 -> V_155 ;
if ( V_12 -> V_85 . V_162 >
V_260 )
V_12 -> V_85 . V_162 =
V_261 ;
F_53 ( V_90 ) ;
F_54 ( & V_262 ) ;
if ( V_12 -> V_164 )
V_216 = & V_215 [ V_263 ] ;
else
V_216 = & V_215 [ V_264 ] ;
F_38 ( V_2 , L_53 ,
V_2 -> V_12 . V_111 , V_216 -> V_223 ) ;
F_55 ( & V_2 -> V_265 , & V_216 -> V_2 ) ;
if ( V_216 -> V_218 ) {
V_2 -> V_221 = F_44 ( V_2 , V_216 ) ;
if ( ! V_2 -> V_221 ) {
F_56 ( & V_262 ) ;
goto V_266;
}
} else {
V_234 = true ;
}
F_56 ( & V_262 ) ;
F_57 ( & V_2 -> V_267 ) ;
if ( V_234 ) {
V_227 = F_58 ( L_54 , V_216 -> V_223 ) ;
#ifdef F_59
if ( V_227 )
F_11 ( V_2 ,
L_55 ,
V_216 -> V_223 , V_227 ) ;
#endif
}
F_5 ( V_44 ) ;
return;
V_238:
F_53 ( V_90 ) ;
if ( F_9 ( V_2 , false ) )
goto V_266;
F_5 ( V_44 ) ;
return;
V_240:
F_11 ( V_2 , L_56 ) ;
F_4 ( V_2 ) ;
F_53 ( V_90 ) ;
V_266:
F_5 ( V_44 ) ;
F_57 ( & V_2 -> V_267 ) ;
F_60 ( V_2 -> V_34 -> V_40 ) ;
}
struct V_1 * F_61 ( struct V_268 * V_34 ,
const struct V_211 * V_24 )
{
struct V_1 * V_2 ;
int V_269 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 ) {
V_269 = - V_20 ;
goto V_227;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_40 = V_34 -> V_40 ;
V_2 -> V_24 = V_24 ;
F_62 ( & V_2 -> V_267 ) ;
F_63 ( & V_2 -> V_265 ) ;
#ifdef F_45
V_2 -> V_224 = F_46 ( F_64 ( V_34 -> V_40 ) ,
V_270 ) ;
if ( ! V_2 -> V_224 ) {
F_11 ( V_2 , L_57 ) ;
V_269 = - V_20 ;
goto V_271;
}
V_2 -> V_34 -> V_220 = F_46 ( L_58 , V_2 -> V_224 ) ;
if ( ! V_2 -> V_34 -> V_220 ) {
F_11 ( V_2 , L_59 ) ;
V_269 = - V_20 ;
goto V_272;
}
#endif
V_269 = F_9 ( V_2 , true ) ;
if ( V_269 ) {
F_11 ( V_34 , L_60 ) ;
goto V_273;
}
return V_2 ;
V_273:
#ifdef F_45
V_272:
F_47 ( V_2 -> V_224 ) ;
V_271:
#endif
F_5 ( V_2 ) ;
V_227:
return F_65 ( V_269 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_67 ( & V_2 -> V_267 ) ;
F_48 ( V_2 ) ;
F_4 ( V_2 ) ;
F_54 ( & V_262 ) ;
if ( ! F_68 ( & V_2 -> V_265 ) )
F_69 ( & V_2 -> V_265 ) ;
F_56 ( & V_262 ) ;
#ifdef F_45
F_47 ( V_2 -> V_224 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_70 ( const char * V_223 , const struct V_217 * V_218 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_215 * V_216 ;
F_54 ( & V_262 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_215 ) ; V_9 ++ ) {
V_216 = & V_215 [ V_9 ] ;
if ( strcmp ( V_216 -> V_223 , V_223 ) )
continue;
V_216 -> V_218 = V_218 ;
F_71 (drv, &op->drv, list)
V_2 -> V_221 = F_44 ( V_2 , V_216 ) ;
F_56 ( & V_262 ) ;
return 0 ;
}
F_56 ( & V_262 ) ;
return - V_274 ;
}
void F_72 ( const char * V_223 )
{
int V_9 ;
struct V_1 * V_2 ;
F_54 ( & V_262 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_215 ) ; V_9 ++ ) {
if ( strcmp ( V_215 [ V_9 ] . V_223 , V_223 ) )
continue;
V_215 [ V_9 ] . V_218 = NULL ;
F_71 (drv, &iwlwifi_opmode_table[i].drv, list)
F_48 ( V_2 ) ;
F_56 ( & V_262 ) ;
return;
}
F_56 ( & V_262 ) ;
}
static int T_4 F_73 ( void )
{
int V_9 ;
F_74 ( & V_262 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_215 ) ; V_9 ++ )
F_63 ( & V_215 [ V_9 ] . V_2 ) ;
F_75 ( V_275 L_61 ) ;
F_75 ( V_276 L_61 ) ;
#ifdef F_45
V_270 = F_46 ( V_277 , NULL ) ;
if ( ! V_270 )
return - V_278 ;
#endif
return F_76 () ;
}
static void T_5 F_77 ( void )
{
F_78 () ;
#ifdef F_45
F_47 ( V_270 ) ;
#endif
}
