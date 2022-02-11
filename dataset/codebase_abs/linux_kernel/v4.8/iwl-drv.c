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
if ( V_6 < sizeof( * V_44 ) ||
V_6 < sizeof( V_44 -> V_19 ) + V_44 -> V_19 * sizeof( V_44 -> V_47 [ 0 ] ) )
return - V_20 ;
for ( V_9 = 0 , V_42 = 0 ; V_9 < V_48 && V_9 < V_44 -> V_19 ; V_9 ++ ) {
V_46 = & V_44 -> V_47 [ V_42 ] ;
if ( ! V_46 -> V_49 )
continue;
V_12 -> V_47 [ V_42 ++ ] = * V_46 ;
}
return 0 ;
}
static void F_19 ( struct V_41 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_50 * V_51 = ( void * ) V_5 ;
struct V_52 * V_53 = & V_12 -> V_54 ;
V_53 -> V_55 = F_20 ( V_51 -> V_55 ) ;
V_53 -> V_56 = F_20 ( V_51 -> V_56 ) ;
V_53 -> V_57 =
F_20 ( V_51 -> V_57 ) ;
V_53 -> V_58 = F_20 ( V_51 -> V_58 ) ;
V_53 -> V_59 =
F_20 ( V_51 -> V_59 ) ;
V_53 -> V_60 = F_20 ( V_51 -> V_60 ) ;
V_53 -> V_61 =
F_20 ( V_51 -> V_61 ) ;
V_53 -> V_62 =
F_20 ( V_51 -> V_62 ) ;
V_53 -> V_63 = F_20 ( V_51 -> V_63 ) ;
V_53 -> V_64 =
F_20 ( V_51 -> V_64 ) ;
V_53 -> V_65 =
F_20 ( V_51 -> V_65 ) ;
V_53 -> V_66 =
F_20 ( V_51 -> V_66 ) ;
V_53 -> V_67 =
F_20 ( V_51 -> V_67 ) ;
}
static int F_21 ( struct V_38 * V_39 ,
const void * V_5 , enum V_40 type ,
int V_19 )
{
struct V_68 * V_8 ;
struct V_18 * V_11 ;
struct V_69 * V_70 ;
if ( F_22 ( ! V_39 || ! V_5 || type >= V_17 ) )
return - 1 ;
V_70 = (struct V_69 * ) V_5 ;
V_8 = & V_39 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_71 ] ;
V_11 -> V_22 = F_20 ( V_70 -> V_22 ) ;
V_11 -> V_5 = V_70 -> V_5 ;
V_11 -> V_19 = V_19 - sizeof( V_70 -> V_22 ) ;
++ V_8 -> V_71 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_72 * V_73 =
(struct V_72 * ) V_5 ;
T_2 V_74 = F_20 ( V_73 -> V_74 ) ;
if ( V_74 >= V_17 ) {
F_10 ( V_2 , L_5 ,
V_74 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_75 [ V_74 ] . V_76 =
V_73 -> V_77 . V_76 ;
V_2 -> V_12 . V_75 [ V_74 ] . V_78 =
V_73 -> V_77 . V_78 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_79 * V_53 )
{
const struct V_80 * V_81 = ( void * ) V_5 ;
T_2 V_82 = F_20 ( V_81 -> V_82 ) ;
T_2 V_83 = F_20 ( V_81 -> V_83 ) ;
int V_9 ;
if ( V_82 >= F_25 ( V_84 , 32 ) ) {
F_10 ( V_2 ,
L_6 ,
V_82 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_83 & F_26 ( V_9 ) )
F_27 ( V_9 + 32 * V_82 , V_53 -> V_85 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_79 * V_53 )
{
const struct V_86 * V_87 = ( void * ) V_5 ;
T_2 V_82 = F_20 ( V_87 -> V_82 ) ;
T_2 V_83 = F_20 ( V_87 -> V_88 ) ;
int V_9 ;
if ( V_82 >= F_25 ( V_89 , 32 ) ) {
F_10 ( V_2 ,
L_7 ,
V_82 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_83 & F_26 ( V_9 ) )
F_27 ( V_9 + 32 * V_82 , V_53 -> V_90 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_91 * V_92 ,
struct V_38 * V_39 )
{
struct V_93 * V_94 = ( void * ) V_92 -> V_5 ;
T_2 V_95 , V_96 , V_97 ;
char V_98 [ 25 ] ;
const T_3 * V_99 ;
V_2 -> V_12 . V_100 = F_20 ( V_94 -> V_101 ) ;
V_95 = F_30 ( V_2 -> V_12 . V_100 ) ;
switch ( V_95 ) {
default:
V_96 = 28 ;
if ( V_92 -> V_19 < V_96 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_97 = F_20 ( V_94 -> V_102 . V_103 . V_97 ) ;
F_15 ( V_39 , V_104 , V_105 ,
F_20 ( V_94 -> V_102 . V_103 . V_106 ) ) ;
F_15 ( V_39 , V_104 , V_107 ,
F_20 ( V_94 -> V_102 . V_103 . V_108 ) ) ;
F_15 ( V_39 , V_109 , V_105 ,
F_20 ( V_94 -> V_102 . V_103 . V_110 ) ) ;
F_15 ( V_39 , V_109 , V_107 ,
F_20 ( V_94 -> V_102 . V_103 . V_111 ) ) ;
V_99 = V_94 -> V_102 . V_103 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_96 = 24 ;
if ( V_92 -> V_19 < V_96 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_97 = 0 ;
F_15 ( V_39 , V_104 , V_105 ,
F_20 ( V_94 -> V_102 . V_112 . V_106 ) ) ;
F_15 ( V_39 , V_104 , V_107 ,
F_20 ( V_94 -> V_102 . V_112 . V_108 ) ) ;
F_15 ( V_39 , V_109 , V_105 ,
F_20 ( V_94 -> V_102 . V_112 . V_110 ) ) ;
F_15 ( V_39 , V_109 , V_107 ,
F_20 ( V_94 -> V_102 . V_112 . V_111 ) ) ;
V_99 = V_94 -> V_102 . V_112 . V_5 ;
break;
}
if ( V_97 )
sprintf ( V_98 , L_9 , V_97 ) ;
else
V_98 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_113 ,
sizeof( V_2 -> V_12 . V_113 ) ,
L_10 ,
F_31 ( V_2 -> V_12 . V_100 ) ,
F_32 ( V_2 -> V_12 . V_100 ) ,
F_30 ( V_2 -> V_12 . V_100 ) ,
F_33 ( V_2 -> V_12 . V_100 ) ,
V_98 ) ;
if ( V_92 -> V_19 != V_96 +
F_16 ( V_39 , V_104 , V_105 ) +
F_16 ( V_39 , V_104 , V_107 ) +
F_16 ( V_39 , V_109 , V_105 ) +
F_16 ( V_39 , V_109 , V_107 ) ) {
F_10 ( V_2 ,
L_11 ,
( int ) V_92 -> V_19 ) ;
return - V_20 ;
}
F_14 ( V_39 , V_104 , V_105 , V_99 ) ;
V_99 += F_16 ( V_39 , V_104 , V_105 ) ;
F_17 ( V_39 , V_104 , V_105 ,
V_114 ) ;
F_14 ( V_39 , V_104 , V_107 , V_99 ) ;
V_99 += F_16 ( V_39 , V_104 , V_107 ) ;
F_17 ( V_39 , V_104 , V_107 ,
V_115 ) ;
F_14 ( V_39 , V_109 , V_105 , V_99 ) ;
V_99 += F_16 ( V_39 , V_109 , V_105 ) ;
F_17 ( V_39 , V_109 , V_105 ,
V_114 ) ;
F_14 ( V_39 , V_109 , V_107 , V_99 ) ;
V_99 += F_16 ( V_39 , V_109 , V_107 ) ;
F_17 ( V_39 , V_109 , V_107 ,
V_115 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_91 * V_92 ,
struct V_38 * V_39 ,
struct V_79 * V_53 ,
bool * V_116 )
{
struct V_117 * V_94 = ( void * ) V_92 -> V_5 ;
struct V_118 * V_119 ;
T_1 V_6 = V_92 -> V_19 ;
const T_3 * V_5 ;
T_2 V_120 ;
T_2 V_121 ;
enum V_122 V_123 ;
const T_3 * V_124 ;
char V_98 [ 25 ] ;
T_2 V_97 , V_125 ;
int V_126 ;
bool V_127 = false ;
bool V_54 = false ;
if ( V_6 < sizeof( * V_94 ) ) {
F_10 ( V_2 , L_12 , V_6 ) ;
return - V_20 ;
}
if ( V_94 -> V_128 != F_35 ( V_129 ) ) {
F_10 ( V_2 , L_13 ,
F_20 ( V_94 -> V_128 ) ) ;
return - V_20 ;
}
V_2 -> V_12 . V_100 = F_20 ( V_94 -> V_101 ) ;
memcpy ( V_2 -> V_12 . V_130 , V_94 -> V_130 ,
sizeof( V_2 -> V_12 . V_130 ) ) ;
V_97 = F_20 ( V_94 -> V_97 ) ;
if ( V_97 )
sprintf ( V_98 , L_9 , V_97 ) ;
else
V_98 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_113 ,
sizeof( V_2 -> V_12 . V_113 ) ,
L_10 ,
F_31 ( V_2 -> V_12 . V_100 ) ,
F_32 ( V_2 -> V_12 . V_100 ) ,
F_30 ( V_2 -> V_12 . V_100 ) ,
F_33 ( V_2 -> V_12 . V_100 ) ,
V_98 ) ;
V_5 = V_94 -> V_5 ;
V_6 -= sizeof( * V_94 ) ;
while ( V_6 >= sizeof( * V_119 ) ) {
V_6 -= sizeof( * V_119 ) ;
V_119 = ( void * ) V_5 ;
V_120 = F_20 ( V_119 -> V_131 ) ;
V_123 = F_20 ( V_119 -> type ) ;
V_124 = V_119 -> V_5 ;
if ( V_6 < V_120 ) {
F_10 ( V_2 , L_14 ,
V_6 , V_120 ) ;
return - V_20 ;
}
V_6 -= F_36 ( V_120 , 4 ) ;
V_5 += sizeof( * V_119 ) + F_36 ( V_120 , 4 ) ;
switch ( V_123 ) {
case V_132 :
F_14 ( V_39 , V_104 ,
V_105 , V_124 ) ;
F_15 ( V_39 , V_104 ,
V_105 , V_120 ) ;
F_17 ( V_39 , V_104 ,
V_105 ,
V_114 ) ;
break;
case V_133 :
F_14 ( V_39 , V_104 ,
V_107 , V_124 ) ;
F_15 ( V_39 , V_104 ,
V_107 , V_120 ) ;
F_17 ( V_39 , V_104 ,
V_107 ,
V_115 ) ;
break;
case V_134 :
F_14 ( V_39 , V_109 ,
V_105 , V_124 ) ;
F_15 ( V_39 , V_109 ,
V_105 , V_120 ) ;
F_17 ( V_39 , V_109 ,
V_105 ,
V_114 ) ;
break;
case V_135 :
F_14 ( V_39 , V_109 ,
V_107 , V_124 ) ;
F_15 ( V_39 , V_109 ,
V_107 , V_120 ) ;
F_17 ( V_39 , V_109 ,
V_107 ,
V_115 ) ;
break;
case V_136 :
F_10 ( V_2 , L_15 ) ;
break;
case V_137 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_53 -> V_139 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_141 :
if ( V_120 )
goto V_138;
V_53 -> V_142 |= V_143 ;
break;
case V_144 :
if ( V_120 < sizeof( T_2 ) )
goto V_138;
if ( V_120 % sizeof( T_2 ) )
goto V_138;
V_53 -> V_142 = F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_145 :
if ( V_120 != sizeof( struct V_80 ) )
goto V_138;
if ( F_24 ( V_2 , V_124 , V_53 ) )
goto V_146;
break;
case V_147 :
if ( V_120 != sizeof( struct V_86 ) )
goto V_138;
if ( F_28 ( V_2 , V_124 , V_53 ) )
goto V_146;
break;
case V_148 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_149 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_150 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_151 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_152 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_153 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_154 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_155 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_156 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_157 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_158 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_39 -> V_159 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_160 :
if ( V_120 )
goto V_138;
V_2 -> V_12 . V_161 = true ;
break;
case V_162 :
F_14 ( V_39 , V_163 ,
V_105 , V_124 ) ;
F_15 ( V_39 , V_163 ,
V_105 , V_120 ) ;
F_17 ( V_39 , V_163 ,
V_105 ,
V_114 ) ;
break;
case V_164 :
F_14 ( V_39 , V_163 ,
V_107 , V_124 ) ;
F_15 ( V_39 , V_163 ,
V_107 , V_120 ) ;
F_17 ( V_39 , V_163 ,
V_107 ,
V_115 ) ;
break;
case V_165 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_53 -> V_166 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_167 :
F_21 ( V_39 , V_124 , V_104 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_169 :
F_21 ( V_39 , V_124 , V_109 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_170 :
F_21 ( V_39 , V_124 , V_163 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_171 :
if ( V_120 != sizeof( struct V_72 ) )
goto V_138;
if ( F_23 ( V_2 , V_124 ) )
goto V_146;
break;
case V_172 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_2 -> V_12 . V_173 = F_37 ( ( V_140 * ) V_124 ) ;
V_2 -> V_12 . V_174 = ( V_2 -> V_12 . V_173 &
V_175 ) >>
V_176 ;
V_2 -> V_12 . V_177 = ( V_2 -> V_12 . V_173 &
V_178 ) >>
V_179 ;
break;
case V_180 :
F_21 ( V_39 , V_124 , V_104 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_181 :
F_21 ( V_39 , V_124 , V_109 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_182 :
F_21 ( V_39 , V_124 , V_163 ,
V_120 ) ;
V_2 -> V_12 . type = V_168 ;
break;
case V_183 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_126 =
F_37 ( ( V_140 * ) V_124 ) ;
if ( V_126 == 2 ) {
V_2 -> V_12 . V_8 [ V_104 ] . V_184 =
true ;
V_2 -> V_12 . V_8 [ V_109 ] . V_184 =
true ;
V_2 -> V_12 . V_8 [ V_163 ] . V_184 =
true ;
} else if ( ( V_126 > 2 ) || ( V_126 < 1 ) ) {
F_10 ( V_2 , L_16 ) ;
return - V_20 ;
}
break;
case V_185 :
if ( F_18 ( & V_2 -> V_12 , V_124 , V_120 ) )
goto V_138;
break;
case V_186 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_53 -> V_187 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_188 : {
V_140 * V_189 = ( void * ) V_124 ;
T_2 V_190 , V_191 ;
T_3 V_192 ;
if ( V_120 != sizeof( T_2 ) * 3 )
goto V_138;
V_190 = F_37 ( V_189 ++ ) ;
V_191 = F_37 ( V_189 ++ ) ;
V_192 = F_37 ( V_189 ) ;
snprintf ( V_2 -> V_12 . V_113 ,
sizeof( V_2 -> V_12 . V_113 ) , L_17 ,
V_190 , V_191 , V_192 ) ;
break;
}
case V_193 : {
struct V_194 * V_195 = ( void * ) V_124 ;
if ( V_39 -> V_13 ) {
F_10 ( V_2 ,
L_18 ) ;
break;
}
V_39 -> V_13 = V_195 ;
F_38 ( V_2 , L_19 ,
F_39 ( V_195 -> V_196 ) ) ;
V_2 -> V_12 . V_197 =
V_120 - F_40 ( struct V_194 ,
V_198 ) ;
V_2 -> V_12 . V_197 /=
sizeof( V_2 -> V_12 . V_13 -> V_198 [ 0 ] ) ;
break;
}
case V_199 : {
struct V_200 * V_201 = ( void * ) V_124 ;
if ( ! V_39 -> V_13 ) {
F_10 ( V_2 ,
L_20 ,
V_201 -> V_202 ) ;
break;
}
if ( V_201 -> V_202 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_10 ( V_2 ,
L_21 ,
V_201 -> V_202 ) ;
break;
}
if ( V_39 -> V_14 [ V_201 -> V_202 ] ) {
F_10 ( V_2 ,
L_22 ,
V_201 -> V_202 ) ;
break;
}
if ( V_201 -> V_203 )
V_127 = true ;
F_38 ( V_2 , L_23 ,
V_201 -> V_202 ) ;
V_39 -> V_14 [ V_201 -> V_202 ] = V_201 ;
V_39 -> V_204 [ V_201 -> V_202 ] = V_120 ;
break;
}
case V_205 : {
struct V_206 * V_207 =
( void * ) V_124 ;
T_2 V_208 = F_20 ( V_207 -> V_202 ) ;
if ( V_208 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_10 ( V_2 ,
L_24 ,
V_207 -> V_202 ) ;
break;
}
if ( V_39 -> V_15 [ V_208 ] ) {
F_10 ( V_2 ,
L_25 ,
V_207 -> V_202 ) ;
break;
}
F_38 ( V_2 , L_26 , V_207 -> V_202 ) ;
V_39 -> V_15 [ V_208 ] = V_207 ;
V_39 -> V_209 [ V_208 ] = V_120 ;
break;
}
case V_210 :
* V_116 = true ;
F_21 ( V_39 , V_124 ,
V_211 ,
V_120 ) ;
break;
case V_212 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_125 = F_37 ( ( V_140 * ) V_124 ) ;
F_41 ( V_2 ,
L_27 ,
V_125 ) ;
if ( V_125 > V_213 ) {
F_10 ( V_2 ,
L_28 ,
V_213 ) ;
return - V_20 ;
}
if ( V_125 & ( V_214 - 1 ) ) {
F_10 ( V_2 ,
L_29 ,
V_214 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_8 [ V_104 ] . V_125 =
V_125 ;
V_121 = V_211 ;
V_2 -> V_12 . V_8 [ V_121 ] . V_125 =
V_125 ;
break;
case V_215 :
if ( V_120 != sizeof( T_2 ) )
goto V_138;
V_2 -> V_12 . V_216 =
F_37 ( ( V_140 * ) V_124 ) ;
break;
case V_217 :
if ( V_120 < sizeof( struct V_50 ) )
break;
F_19 ( & V_2 -> V_12 , V_124 , V_120 ) ;
V_54 = true ;
break;
case V_218 : {
struct V_219 * V_220 =
( void * ) V_124 ;
T_2 type ;
if ( V_120 != ( sizeof( * V_220 ) ) )
goto V_138;
type = F_20 ( V_220 -> V_221 ) ;
V_2 -> V_12 . V_222 = true ;
if ( type >= F_6 ( V_2 -> V_12 . V_16 ) ) {
F_10 ( V_2 ,
L_30 ,
V_220 -> V_221 ) ;
break;
}
if ( V_39 -> V_16 [ type ] ) {
F_10 ( V_2 ,
L_31 ,
V_220 -> V_221 ) ;
break;
}
F_11 ( V_2 , L_32 ,
V_220 -> V_221 ) ;
V_39 -> V_16 [ type ] = V_220 ;
break;
}
default:
F_11 ( V_2 , L_33 , V_123 ) ;
break;
}
}
if ( ! F_42 ( V_53 , V_223 ) &&
V_127 && ! * V_116 ) {
F_10 ( V_2 ,
L_34 ) ;
return - V_20 ;
}
if ( V_6 ) {
F_10 ( V_2 , L_35 , V_6 ) ;
F_43 ( V_2 , V_224 , ( T_3 * ) V_5 , V_6 ) ;
return - V_20 ;
}
if ( F_42 ( V_53 , V_225 ) &&
! V_54 ) {
F_11 ( V_2 ,
L_36 ) ;
F_44 ( ( V_226 long ) V_225 ,
V_53 -> V_90 ) ;
}
return 0 ;
V_138:
F_10 ( V_2 , L_37 , V_123 , V_120 ) ;
V_146:
F_43 ( V_2 , V_224 , V_124 , V_120 ) ;
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
const struct V_227 * V_25 )
{
F_11 ( V_2 , L_38 ,
F_16 ( V_39 , V_104 ,
V_105 ) ) ;
F_11 ( V_2 , L_39 ,
F_16 ( V_39 , V_104 ,
V_107 ) ) ;
F_11 ( V_2 , L_40 ,
F_16 ( V_39 , V_109 , V_105 ) ) ;
F_11 ( V_2 , L_41 ,
F_16 ( V_39 , V_109 , V_107 ) ) ;
if ( F_16 ( V_39 , V_104 , V_105 ) >
V_25 -> V_228 ) {
F_10 ( V_2 , L_42 ,
F_16 ( V_39 , V_104 ,
V_105 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_104 , V_107 ) >
V_25 -> V_229 ) {
F_10 ( V_2 , L_43 ,
F_16 ( V_39 , V_104 ,
V_107 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_109 , V_105 ) >
V_25 -> V_228 ) {
F_10 ( V_2 , L_44 ,
F_16 ( V_39 , V_109 ,
V_105 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_109 , V_107 ) >
V_25 -> V_229 ) {
F_10 ( V_2 , L_45 ,
F_16 ( V_39 , V_104 ,
V_107 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_230 *
F_47 ( struct V_1 * V_2 , struct V_231 * V_232 )
{
const struct V_233 * V_234 = V_232 -> V_234 ;
struct V_235 * V_236 = NULL ;
struct V_230 * V_237 = NULL ;
#ifdef F_48
V_2 -> V_238 = F_49 ( V_232 -> V_239 ,
V_2 -> V_240 ) ;
if ( ! V_2 -> V_238 ) {
F_10 ( V_2 ,
L_46 ) ;
return V_237 ;
}
V_236 = V_2 -> V_238 ;
#endif
V_237 = V_234 -> V_241 ( V_2 -> V_34 , V_2 -> V_25 , & V_2 -> V_12 , V_236 ) ;
#ifdef F_48
if ( ! V_237 ) {
F_50 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
#endif
return V_237 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_237 ) {
F_52 ( V_2 -> V_237 ) ;
V_2 -> V_237 = NULL ;
#ifdef F_48
F_50 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
#endif
}
}
static void V_37 ( const struct V_91 * V_92 , void * V_242 )
{
struct V_1 * V_2 = V_242 ;
struct V_41 * V_12 = & V_2 -> V_12 ;
struct V_93 * V_94 ;
struct V_231 * V_232 ;
int V_243 ;
struct V_38 * V_39 ;
const unsigned int V_244 = V_2 -> V_25 -> V_29 ;
const unsigned int V_245 = V_2 -> V_25 -> V_30 ;
T_1 V_246 [ V_247 ] ;
T_2 V_95 ;
int V_9 ;
bool V_248 = false ;
bool V_116 = false ;
V_12 -> V_87 . V_139 = V_249 ;
V_12 -> V_87 . V_166 =
V_250 ;
V_12 -> V_87 . V_187 = V_251 ;
V_39 = F_53 ( sizeof( * V_39 ) , V_36 ) ;
if ( ! V_39 )
return;
if ( ! V_92 )
goto V_252;
F_11 ( V_2 , L_47 ,
V_2 -> V_32 , V_92 -> V_19 ) ;
if ( V_92 -> V_19 < 4 ) {
F_10 ( V_2 , L_48 ) ;
goto V_252;
}
V_94 = (struct V_93 * ) V_92 -> V_5 ;
if ( V_94 -> V_101 )
V_243 = F_29 ( V_2 , V_92 , V_39 ) ;
else
V_243 = F_34 ( V_2 , V_92 , V_39 ,
& V_12 -> V_87 , & V_116 ) ;
if ( V_243 )
goto V_252;
if ( F_54 ( & V_2 -> V_12 . V_87 , V_253 ) )
V_95 = V_2 -> V_12 . V_100 ;
else
V_95 = F_30 ( V_2 -> V_12 . V_100 ) ;
if ( V_95 < V_245 || V_95 > V_244 ) {
F_10 ( V_2 ,
L_49
L_50 ,
V_244 , V_95 ) ;
goto V_252;
}
if ( V_12 -> type == V_254 && F_46 ( V_2 , V_39 , V_2 -> V_25 ) )
goto V_252;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
if ( F_45 ( V_2 , V_39 , V_9 ) )
goto V_255;
if ( V_39 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_55 ( V_39 -> V_13 ,
sizeof( * V_39 -> V_13 ) +
sizeof( V_39 -> V_13 -> V_198 [ 0 ] ) *
V_2 -> V_12 . V_197 , V_36 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_255;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_39 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_204 [ V_9 ] =
V_39 -> V_204 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_55 ( V_39 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_204 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_255;
}
}
memset ( & V_246 , 0xff , sizeof( V_246 ) ) ;
V_246 [ V_256 ] =
sizeof( struct V_257 ) ;
V_246 [ V_258 ] = 0 ;
V_246 [ V_259 ] =
sizeof( struct V_260 ) ;
V_246 [ V_261 ] =
sizeof( struct V_262 ) ;
V_246 [ V_263 ] =
sizeof( struct V_264 ) ;
V_246 [ V_265 ] =
sizeof( struct V_266 ) ;
V_246 [ V_267 ] =
sizeof( struct V_268 ) ;
V_246 [ V_269 ] =
sizeof( struct V_270 ) ;
V_246 [ V_271 ] =
sizeof( struct V_272 ) ;
V_246 [ V_273 ] =
sizeof( struct V_274 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_39 -> V_15 [ V_9 ] ) {
if ( F_22 ( V_39 -> V_209 [ V_9 ] <
( V_246 [ V_9 ] +
sizeof( struct V_206 ) ) ) )
goto V_255;
V_2 -> V_12 . V_209 [ V_9 ] =
V_39 -> V_209 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_55 ( V_39 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_209 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_255;
}
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_16 ) ; V_9 ++ ) {
if ( V_39 -> V_16 [ V_9 ] ) {
V_2 -> V_12 . V_16 [ V_9 ] =
F_55 ( V_39 -> V_16 [ V_9 ] ,
sizeof( * V_2 -> V_12 . V_16 [ V_9 ] ) ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_16 [ V_9 ] )
goto V_255;
}
}
V_12 -> V_149 = V_39 -> V_149 ;
if ( V_39 -> V_151 )
V_12 -> V_151 = ( V_39 -> V_151 - 16 ) / 12 ;
else
V_12 -> V_151 =
V_2 -> V_25 -> V_275 -> V_276 ;
V_12 -> V_153 = V_39 -> V_153 ;
V_12 -> V_155 = V_39 -> V_155 ;
if ( V_39 -> V_157 )
V_12 -> V_157 = ( V_39 -> V_157 - 16 ) / 12 ;
else
V_12 -> V_157 =
V_2 -> V_25 -> V_275 -> V_276 ;
V_12 -> V_159 = V_39 -> V_159 ;
if ( V_12 -> V_87 . V_166 >
V_277 )
V_12 -> V_87 . V_166 =
V_278 ;
F_56 ( V_92 ) ;
F_57 ( & V_279 ) ;
switch ( V_12 -> type ) {
case V_254 :
V_232 = & V_231 [ V_280 ] ;
break;
default:
F_58 ( 1 , L_51 , V_12 -> type ) ;
case V_168 :
V_232 = & V_231 [ V_281 ] ;
break;
}
F_38 ( V_2 , L_52 ,
V_2 -> V_12 . V_113 , V_232 -> V_239 ) ;
F_59 ( & V_2 -> V_282 , & V_232 -> V_2 ) ;
if ( V_232 -> V_234 ) {
V_2 -> V_237 = F_47 ( V_2 , V_232 ) ;
if ( ! V_2 -> V_237 ) {
F_60 ( & V_279 ) ;
goto V_283;
}
} else {
V_248 = true ;
}
F_60 ( & V_279 ) ;
F_61 ( & V_2 -> V_284 ) ;
if ( V_248 ) {
V_243 = F_62 ( L_53 , V_232 -> V_239 ) ;
#ifdef F_63
if ( V_243 )
F_10 ( V_2 ,
L_54 ,
V_232 -> V_239 , V_243 ) ;
#endif
}
F_5 ( V_39 ) ;
return;
V_252:
F_56 ( V_92 ) ;
if ( F_9 ( V_2 , false ) )
goto V_283;
F_5 ( V_39 ) ;
return;
V_255:
F_10 ( V_2 , L_55 ) ;
F_4 ( V_2 ) ;
F_56 ( V_92 ) ;
V_283:
F_5 ( V_39 ) ;
F_61 ( & V_2 -> V_284 ) ;
F_64 ( V_2 -> V_34 -> V_35 ) ;
}
struct V_1 * F_65 ( struct V_285 * V_34 ,
const struct V_227 * V_25 )
{
struct V_1 * V_2 ;
int V_286 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 ) {
V_286 = - V_21 ;
goto V_243;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_35 = V_34 -> V_35 ;
V_2 -> V_25 = V_25 ;
F_66 ( & V_2 -> V_284 ) ;
F_67 ( & V_2 -> V_282 ) ;
#ifdef F_48
V_2 -> V_240 = F_49 ( F_68 ( V_34 -> V_35 ) ,
V_287 ) ;
if ( ! V_2 -> V_240 ) {
F_10 ( V_2 , L_56 ) ;
V_286 = - V_21 ;
goto V_288;
}
V_2 -> V_34 -> V_236 = F_49 ( L_57 , V_2 -> V_240 ) ;
if ( ! V_2 -> V_34 -> V_236 ) {
F_10 ( V_2 , L_58 ) ;
V_286 = - V_21 ;
goto V_289;
}
#endif
V_286 = F_9 ( V_2 , true ) ;
if ( V_286 ) {
F_10 ( V_34 , L_59 ) ;
goto V_290;
}
return V_2 ;
V_290:
#ifdef F_48
V_289:
F_50 ( V_2 -> V_240 ) ;
V_288:
#endif
F_5 ( V_2 ) ;
V_243:
return F_69 ( V_286 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_71 ( & V_2 -> V_284 ) ;
F_51 ( V_2 ) ;
F_4 ( V_2 ) ;
F_57 ( & V_279 ) ;
if ( ! F_72 ( & V_2 -> V_282 ) )
F_73 ( & V_2 -> V_282 ) ;
F_60 ( & V_279 ) ;
#ifdef F_48
F_50 ( V_2 -> V_240 ) ;
#endif
F_5 ( V_2 ) ;
}
int F_74 ( const char * V_239 , const struct V_233 * V_234 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_231 * V_232 ;
F_57 ( & V_279 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_231 ) ; V_9 ++ ) {
V_232 = & V_231 [ V_9 ] ;
if ( strcmp ( V_232 -> V_239 , V_239 ) )
continue;
V_232 -> V_234 = V_234 ;
F_75 (drv, &op->drv, list)
V_2 -> V_237 = F_47 ( V_2 , V_232 ) ;
F_60 ( & V_279 ) ;
return 0 ;
}
F_60 ( & V_279 ) ;
return - V_291 ;
}
void F_76 ( const char * V_239 )
{
int V_9 ;
struct V_1 * V_2 ;
F_57 ( & V_279 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_231 ) ; V_9 ++ ) {
if ( strcmp ( V_231 [ V_9 ] . V_239 , V_239 ) )
continue;
V_231 [ V_9 ] . V_234 = NULL ;
F_75 (drv, &iwlwifi_opmode_table[i].drv, list)
F_51 ( V_2 ) ;
F_60 ( & V_279 ) ;
return;
}
F_60 ( & V_279 ) ;
}
static int T_4 F_77 ( void )
{
int V_9 ;
F_78 ( & V_279 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_231 ) ; V_9 ++ )
F_67 ( & V_231 [ V_9 ] . V_2 ) ;
F_79 ( V_292 L_60 ) ;
F_79 ( V_293 L_60 ) ;
#ifdef F_48
V_287 = F_49 ( V_294 , NULL ) ;
if ( ! V_287 )
return - V_295 ;
#endif
return F_80 () ;
}
static void T_5 F_81 ( void )
{
F_82 () ;
#ifdef F_48
F_50 ( V_287 ) ;
#endif
}
