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
F_10 ( V_2 -> V_26 -> V_31 ) == V_32 )
V_28 = V_25 -> V_33 ;
else
V_28 = V_25 -> V_34 ;
if ( V_23 ) {
V_2 -> V_35 = V_25 -> V_36 ;
sprintf ( V_27 , L_1 , V_2 -> V_35 ) ;
} else {
V_2 -> V_35 -- ;
sprintf ( V_27 , L_1 , V_2 -> V_35 ) ;
}
if ( V_2 -> V_35 < V_25 -> V_37 ) {
F_11 ( V_2 , L_2 ) ;
if ( V_25 -> V_37 == V_25 -> V_36 ) {
F_11 ( V_2 , L_3 , V_28 ,
V_25 -> V_36 ) ;
} else {
F_11 ( V_2 , L_4 ,
V_28 ,
V_25 -> V_37 ) ;
F_11 ( V_2 , L_5 ,
V_28 ,
V_25 -> V_36 ) ;
}
F_11 ( V_2 ,
L_6 ) ;
return - V_38 ;
}
snprintf ( V_2 -> V_39 , sizeof( V_2 -> V_39 ) , L_7 ,
V_28 , V_27 ) ;
F_12 ( V_2 , L_8 ,
V_2 -> V_39 ) ;
return F_13 ( V_40 , 1 , V_2 -> V_39 ,
V_2 -> V_26 -> V_41 ,
V_42 , V_2 , V_43 ) ;
}
static struct V_18 * F_14 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 )
{
return & V_45 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_15 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 )
{
struct V_47 * V_8 = & V_45 -> V_8 [ type ] ;
struct V_18 * V_48 ;
int V_19 = V_11 + 1 ;
T_1 V_49 = sizeof( * V_8 -> V_11 ) * V_19 ;
if ( V_8 -> V_11 && V_8 -> V_50 >= V_19 )
return;
V_48 = F_16 ( V_8 -> V_11 , V_49 , V_42 ) ;
if ( ! V_48 )
return;
V_8 -> V_11 = V_48 ;
V_8 -> V_50 = V_19 ;
}
static void F_17 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 ,
const void * V_5 )
{
F_15 ( V_45 , type , V_11 ) ;
V_45 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_18 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 ,
T_1 V_19 )
{
F_15 ( V_45 , type , V_11 ) ;
V_45 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 = V_19 ;
}
static T_1 F_19 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 )
{
return V_45 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 ;
}
static void F_20 ( struct V_44 * V_45 ,
enum V_46 type ,
int V_11 ,
T_2 V_22 )
{
F_15 ( V_45 , type , V_11 ) ;
V_45 -> V_8 [ type ] . V_11 [ V_11 ] . V_22 = V_22 ;
}
static int F_21 ( struct V_51 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_52 ;
struct V_53 * V_54 = (struct V_53 * ) V_5 ;
struct V_55 * V_56 ;
if ( V_6 < sizeof( * V_54 ) ||
V_6 < sizeof( V_54 -> V_19 ) + V_54 -> V_19 * sizeof( V_54 -> V_57 [ 0 ] ) )
return - V_20 ;
for ( V_9 = 0 , V_52 = 0 ; V_9 < V_58 && V_9 < V_54 -> V_19 ; V_9 ++ ) {
V_56 = & V_54 -> V_57 [ V_52 ] ;
if ( ! V_56 -> V_59 )
continue;
V_12 -> V_57 [ V_52 ++ ] = * V_56 ;
}
return 0 ;
}
static void F_22 ( struct V_51 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_60 * V_61 = ( void * ) V_5 ;
struct V_62 * V_63 = & V_12 -> V_64 ;
V_63 -> V_65 = F_23 ( V_61 -> V_65 ) ;
V_63 -> V_66 = F_23 ( V_61 -> V_66 ) ;
V_63 -> V_67 =
F_23 ( V_61 -> V_67 ) ;
V_63 -> V_68 = F_23 ( V_61 -> V_68 ) ;
V_63 -> V_69 =
F_23 ( V_61 -> V_69 ) ;
V_63 -> V_70 = F_23 ( V_61 -> V_70 ) ;
V_63 -> V_71 =
F_23 ( V_61 -> V_71 ) ;
V_63 -> V_72 =
F_23 ( V_61 -> V_72 ) ;
V_63 -> V_73 = F_23 ( V_61 -> V_73 ) ;
V_63 -> V_74 =
F_23 ( V_61 -> V_74 ) ;
V_63 -> V_75 =
F_23 ( V_61 -> V_75 ) ;
V_63 -> V_76 =
F_23 ( V_61 -> V_76 ) ;
V_63 -> V_77 =
F_23 ( V_61 -> V_77 ) ;
}
static int F_24 ( struct V_44 * V_45 ,
const void * V_5 , enum V_46 type ,
int V_19 )
{
struct V_47 * V_8 ;
struct V_18 * V_11 ;
struct V_78 * V_79 ;
T_1 V_49 ;
if ( F_25 ( ! V_45 || ! V_5 || type >= V_17 ) )
return - 1 ;
V_79 = (struct V_78 * ) V_5 ;
V_8 = & V_45 -> V_8 [ type ] ;
V_49 = sizeof( * V_8 -> V_11 ) * ( V_8 -> V_50 + 1 ) ;
V_11 = F_16 ( V_8 -> V_11 , V_49 , V_42 ) ;
if ( ! V_11 )
return - V_21 ;
V_8 -> V_11 = V_11 ;
V_11 = & V_8 -> V_11 [ V_8 -> V_50 ] ;
V_11 -> V_22 = F_23 ( V_79 -> V_22 ) ;
V_11 -> V_5 = V_79 -> V_5 ;
V_11 -> V_19 = V_19 - sizeof( V_79 -> V_22 ) ;
++ V_8 -> V_50 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_80 * V_81 =
(struct V_80 * ) V_5 ;
T_2 V_82 = F_23 ( V_81 -> V_82 ) ;
if ( V_82 >= V_17 ) {
F_11 ( V_2 , L_9 ,
V_82 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_83 [ V_82 ] . V_84 =
V_81 -> V_85 . V_84 ;
V_2 -> V_12 . V_83 [ V_82 ] . V_86 =
V_81 -> V_85 . V_86 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_87 * V_63 )
{
const struct V_88 * V_89 = ( void * ) V_5 ;
T_2 V_90 = F_23 ( V_89 -> V_90 ) ;
T_2 V_91 = F_23 ( V_89 -> V_91 ) ;
int V_9 ;
if ( V_90 >= F_28 ( V_92 , 32 ) ) {
F_11 ( V_2 ,
L_10 ,
V_90 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_91 & F_29 ( V_9 ) )
F_30 ( V_9 + 32 * V_90 , V_63 -> V_93 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_87 * V_63 )
{
const struct V_94 * V_95 = ( void * ) V_5 ;
T_2 V_90 = F_23 ( V_95 -> V_90 ) ;
T_2 V_91 = F_23 ( V_95 -> V_96 ) ;
int V_9 ;
if ( V_90 >= F_28 ( V_97 , 32 ) ) {
F_11 ( V_2 ,
L_11 ,
V_90 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_91 & F_29 ( V_9 ) )
F_30 ( V_9 + 32 * V_90 , V_63 -> V_98 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_99 * V_100 ,
struct V_44 * V_45 )
{
struct V_101 * V_102 = ( void * ) V_100 -> V_5 ;
T_2 V_103 , V_104 , V_105 ;
char V_106 [ 25 ] ;
const T_3 * V_107 ;
V_2 -> V_12 . V_108 = F_23 ( V_102 -> V_109 ) ;
V_103 = F_33 ( V_2 -> V_12 . V_108 ) ;
switch ( V_103 ) {
default:
V_104 = 28 ;
if ( V_100 -> V_19 < V_104 ) {
F_11 ( V_2 , L_12 ) ;
return - V_20 ;
}
V_105 = F_23 ( V_102 -> V_110 . V_111 . V_105 ) ;
F_18 ( V_45 , V_112 , V_113 ,
F_23 ( V_102 -> V_110 . V_111 . V_114 ) ) ;
F_18 ( V_45 , V_112 , V_115 ,
F_23 ( V_102 -> V_110 . V_111 . V_116 ) ) ;
F_18 ( V_45 , V_117 , V_113 ,
F_23 ( V_102 -> V_110 . V_111 . V_118 ) ) ;
F_18 ( V_45 , V_117 , V_115 ,
F_23 ( V_102 -> V_110 . V_111 . V_119 ) ) ;
V_107 = V_102 -> V_110 . V_111 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_104 = 24 ;
if ( V_100 -> V_19 < V_104 ) {
F_11 ( V_2 , L_12 ) ;
return - V_20 ;
}
V_105 = 0 ;
F_18 ( V_45 , V_112 , V_113 ,
F_23 ( V_102 -> V_110 . V_120 . V_114 ) ) ;
F_18 ( V_45 , V_112 , V_115 ,
F_23 ( V_102 -> V_110 . V_120 . V_116 ) ) ;
F_18 ( V_45 , V_117 , V_113 ,
F_23 ( V_102 -> V_110 . V_120 . V_118 ) ) ;
F_18 ( V_45 , V_117 , V_115 ,
F_23 ( V_102 -> V_110 . V_120 . V_119 ) ) ;
V_107 = V_102 -> V_110 . V_120 . V_5 ;
break;
}
if ( V_105 )
sprintf ( V_106 , L_13 , V_105 ) ;
else
V_106 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_121 ,
sizeof( V_2 -> V_12 . V_121 ) ,
L_14 ,
F_34 ( V_2 -> V_12 . V_108 ) ,
F_35 ( V_2 -> V_12 . V_108 ) ,
F_33 ( V_2 -> V_12 . V_108 ) ,
F_36 ( V_2 -> V_12 . V_108 ) ,
V_106 ) ;
if ( V_100 -> V_19 != V_104 +
F_19 ( V_45 , V_112 , V_113 ) +
F_19 ( V_45 , V_112 , V_115 ) +
F_19 ( V_45 , V_117 , V_113 ) +
F_19 ( V_45 , V_117 , V_115 ) ) {
F_11 ( V_2 ,
L_15 ,
( int ) V_100 -> V_19 ) ;
return - V_20 ;
}
F_17 ( V_45 , V_112 , V_113 , V_107 ) ;
V_107 += F_19 ( V_45 , V_112 , V_113 ) ;
F_20 ( V_45 , V_112 , V_113 ,
V_122 ) ;
F_17 ( V_45 , V_112 , V_115 , V_107 ) ;
V_107 += F_19 ( V_45 , V_112 , V_115 ) ;
F_20 ( V_45 , V_112 , V_115 ,
V_123 ) ;
F_17 ( V_45 , V_117 , V_113 , V_107 ) ;
V_107 += F_19 ( V_45 , V_117 , V_113 ) ;
F_20 ( V_45 , V_117 , V_113 ,
V_122 ) ;
F_17 ( V_45 , V_117 , V_115 , V_107 ) ;
V_107 += F_19 ( V_45 , V_117 , V_115 ) ;
F_20 ( V_45 , V_117 , V_115 ,
V_123 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_99 * V_100 ,
struct V_44 * V_45 ,
struct V_87 * V_63 ,
bool * V_124 )
{
struct V_125 * V_102 = ( void * ) V_100 -> V_5 ;
struct V_126 * V_127 ;
T_1 V_6 = V_100 -> V_19 ;
const T_3 * V_5 ;
T_2 V_128 ;
T_2 V_129 ;
enum V_130 V_131 ;
const T_3 * V_132 ;
char V_106 [ 25 ] ;
T_2 V_105 , V_133 ;
int V_134 ;
bool V_135 = false ;
bool V_64 = false ;
if ( V_6 < sizeof( * V_102 ) ) {
F_11 ( V_2 , L_16 , V_6 ) ;
return - V_20 ;
}
if ( V_102 -> V_136 != F_38 ( V_137 ) ) {
F_11 ( V_2 , L_17 ,
F_23 ( V_102 -> V_136 ) ) ;
return - V_20 ;
}
V_2 -> V_12 . V_108 = F_23 ( V_102 -> V_109 ) ;
memcpy ( V_2 -> V_12 . V_138 , V_102 -> V_138 ,
sizeof( V_2 -> V_12 . V_138 ) ) ;
V_105 = F_23 ( V_102 -> V_105 ) ;
if ( V_105 )
sprintf ( V_106 , L_13 , V_105 ) ;
else
V_106 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_121 ,
sizeof( V_2 -> V_12 . V_121 ) ,
L_14 ,
F_34 ( V_2 -> V_12 . V_108 ) ,
F_35 ( V_2 -> V_12 . V_108 ) ,
F_33 ( V_2 -> V_12 . V_108 ) ,
F_36 ( V_2 -> V_12 . V_108 ) ,
V_106 ) ;
V_5 = V_102 -> V_5 ;
V_6 -= sizeof( * V_102 ) ;
while ( V_6 >= sizeof( * V_127 ) ) {
V_6 -= sizeof( * V_127 ) ;
V_127 = ( void * ) V_5 ;
V_128 = F_23 ( V_127 -> V_139 ) ;
V_131 = F_23 ( V_127 -> type ) ;
V_132 = V_127 -> V_5 ;
if ( V_6 < V_128 ) {
F_11 ( V_2 , L_18 ,
V_6 , V_128 ) ;
return - V_20 ;
}
V_6 -= F_39 ( V_128 , 4 ) ;
V_5 += sizeof( * V_127 ) + F_39 ( V_128 , 4 ) ;
switch ( V_131 ) {
case V_140 :
F_17 ( V_45 , V_112 ,
V_113 , V_132 ) ;
F_18 ( V_45 , V_112 ,
V_113 , V_128 ) ;
F_20 ( V_45 , V_112 ,
V_113 ,
V_122 ) ;
break;
case V_141 :
F_17 ( V_45 , V_112 ,
V_115 , V_132 ) ;
F_18 ( V_45 , V_112 ,
V_115 , V_128 ) ;
F_20 ( V_45 , V_112 ,
V_115 ,
V_123 ) ;
break;
case V_142 :
F_17 ( V_45 , V_117 ,
V_113 , V_132 ) ;
F_18 ( V_45 , V_117 ,
V_113 , V_128 ) ;
F_20 ( V_45 , V_117 ,
V_113 ,
V_122 ) ;
break;
case V_143 :
F_17 ( V_45 , V_117 ,
V_115 , V_132 ) ;
F_18 ( V_45 , V_117 ,
V_115 , V_128 ) ;
F_20 ( V_45 , V_117 ,
V_115 ,
V_123 ) ;
break;
case V_144 :
F_11 ( V_2 , L_19 ) ;
break;
case V_145 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_63 -> V_147 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_149 :
if ( V_128 )
goto V_146;
V_63 -> V_150 |= V_151 ;
break;
case V_152 :
if ( V_128 < sizeof( T_2 ) )
goto V_146;
if ( V_128 % sizeof( T_2 ) )
goto V_146;
V_63 -> V_150 = F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_153 :
if ( V_128 != sizeof( struct V_88 ) )
goto V_146;
if ( F_27 ( V_2 , V_132 , V_63 ) )
goto V_154;
break;
case V_155 :
if ( V_128 != sizeof( struct V_94 ) )
goto V_146;
if ( F_31 ( V_2 , V_132 , V_63 ) )
goto V_154;
break;
case V_156 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_157 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_158 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_159 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_160 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_161 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_162 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_163 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_164 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_165 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_166 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_45 -> V_167 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_168 :
if ( V_128 )
goto V_146;
V_2 -> V_12 . V_169 = true ;
break;
case V_170 :
F_17 ( V_45 , V_171 ,
V_113 , V_132 ) ;
F_18 ( V_45 , V_171 ,
V_113 , V_128 ) ;
F_20 ( V_45 , V_171 ,
V_113 ,
V_122 ) ;
break;
case V_172 :
F_17 ( V_45 , V_171 ,
V_115 , V_132 ) ;
F_18 ( V_45 , V_171 ,
V_115 , V_128 ) ;
F_20 ( V_45 , V_171 ,
V_115 ,
V_123 ) ;
break;
case V_173 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_63 -> V_174 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_175 :
F_24 ( V_45 , V_132 , V_112 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_177 :
F_24 ( V_45 , V_132 , V_117 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_178 :
F_24 ( V_45 , V_132 , V_171 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_179 :
if ( V_128 != sizeof( struct V_80 ) )
goto V_146;
if ( F_26 ( V_2 , V_132 ) )
goto V_154;
break;
case V_180 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_2 -> V_12 . V_181 = F_40 ( ( V_148 * ) V_132 ) ;
V_2 -> V_12 . V_182 = ( V_2 -> V_12 . V_181 &
V_183 ) >>
V_184 ;
V_2 -> V_12 . V_185 = ( V_2 -> V_12 . V_181 &
V_186 ) >>
V_187 ;
break;
case V_188 :
F_24 ( V_45 , V_132 , V_112 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_189 :
F_24 ( V_45 , V_132 , V_117 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_190 :
F_24 ( V_45 , V_132 , V_171 ,
V_128 ) ;
V_2 -> V_12 . type = V_176 ;
break;
case V_191 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_134 =
F_40 ( ( V_148 * ) V_132 ) ;
if ( V_134 == 2 ) {
V_2 -> V_12 . V_8 [ V_112 ] . V_192 =
true ;
V_2 -> V_12 . V_8 [ V_117 ] . V_192 =
true ;
V_2 -> V_12 . V_8 [ V_171 ] . V_192 =
true ;
} else if ( ( V_134 > 2 ) || ( V_134 < 1 ) ) {
F_11 ( V_2 , L_20 ) ;
return - V_20 ;
}
break;
case V_193 :
if ( F_21 ( & V_2 -> V_12 , V_132 , V_128 ) )
goto V_146;
break;
case V_194 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_63 -> V_195 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_196 : {
V_148 * V_197 = ( void * ) V_132 ;
T_2 V_198 , V_199 ;
T_3 V_200 ;
if ( V_128 != sizeof( T_2 ) * 3 )
goto V_146;
V_198 = F_40 ( V_197 ++ ) ;
V_199 = F_40 ( V_197 ++ ) ;
V_200 = F_40 ( V_197 ) ;
snprintf ( V_2 -> V_12 . V_121 ,
sizeof( V_2 -> V_12 . V_121 ) , L_21 ,
V_198 , V_199 , V_200 ) ;
break;
}
case V_201 : {
struct V_202 * V_203 = ( void * ) V_132 ;
if ( V_45 -> V_13 ) {
F_11 ( V_2 ,
L_22 ) ;
break;
}
V_45 -> V_13 = V_203 ;
F_41 ( V_2 , L_23 ,
F_42 ( V_203 -> V_204 ) ) ;
V_2 -> V_12 . V_205 =
V_128 - F_43 ( struct V_202 ,
V_206 ) ;
V_2 -> V_12 . V_205 /=
sizeof( V_2 -> V_12 . V_13 -> V_206 [ 0 ] ) ;
break;
}
case V_207 : {
struct V_208 * V_209 = ( void * ) V_132 ;
if ( ! V_45 -> V_13 ) {
F_11 ( V_2 ,
L_24 ,
V_209 -> V_210 ) ;
break;
}
if ( V_209 -> V_210 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_11 ( V_2 ,
L_25 ,
V_209 -> V_210 ) ;
break;
}
if ( V_45 -> V_14 [ V_209 -> V_210 ] ) {
F_11 ( V_2 ,
L_26 ,
V_209 -> V_210 ) ;
break;
}
if ( V_209 -> V_211 )
V_135 = true ;
F_41 ( V_2 , L_27 ,
V_209 -> V_210 ) ;
V_45 -> V_14 [ V_209 -> V_210 ] = V_209 ;
V_45 -> V_212 [ V_209 -> V_210 ] = V_128 ;
break;
}
case V_213 : {
struct V_214 * V_215 =
( void * ) V_132 ;
T_2 V_216 = F_23 ( V_215 -> V_210 ) ;
if ( V_216 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_11 ( V_2 ,
L_28 ,
V_215 -> V_210 ) ;
break;
}
if ( V_45 -> V_15 [ V_216 ] ) {
F_11 ( V_2 ,
L_29 ,
V_215 -> V_210 ) ;
break;
}
F_41 ( V_2 , L_30 , V_215 -> V_210 ) ;
V_45 -> V_15 [ V_216 ] = V_215 ;
V_45 -> V_217 [ V_216 ] = V_128 ;
break;
}
case V_218 :
* V_124 = true ;
F_24 ( V_45 , V_132 ,
V_219 ,
V_128 ) ;
break;
case V_220 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_133 = F_40 ( ( V_148 * ) V_132 ) ;
F_44 ( V_2 ,
L_31 ,
V_133 ) ;
if ( V_133 > V_221 ) {
F_11 ( V_2 ,
L_32 ,
V_221 ) ;
return - V_20 ;
}
if ( V_133 & ( V_222 - 1 ) ) {
F_11 ( V_2 ,
L_33 ,
V_222 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_8 [ V_112 ] . V_133 =
V_133 ;
V_129 = V_219 ;
V_2 -> V_12 . V_8 [ V_129 ] . V_133 =
V_133 ;
break;
case V_223 :
if ( V_128 != sizeof( T_2 ) )
goto V_146;
V_2 -> V_12 . V_224 =
F_40 ( ( V_148 * ) V_132 ) ;
break;
case V_225 :
if ( V_128 < sizeof( struct V_60 ) )
break;
F_22 ( & V_2 -> V_12 , V_132 , V_128 ) ;
V_64 = true ;
break;
case V_226 : {
struct V_227 * V_228 =
( void * ) V_132 ;
T_2 type ;
T_1 V_19 ;
struct V_227 * V_229 ;
if ( V_128 != ( sizeof( * V_228 ) ) )
goto V_146;
type = F_23 ( V_228 -> V_230 ) ;
F_12 ( V_2 , L_34 ,
V_228 -> V_230 ) ;
switch ( type & V_231 ) {
case V_232 :
case V_233 :
break;
default:
F_11 ( V_2 ,
L_35 ,
type ) ;
return - V_20 ;
}
V_19 = sizeof( * V_45 -> V_16 ) *
( V_45 -> V_234 + 1 ) ;
V_229 = F_16 ( V_45 -> V_16 , V_19 , V_42 ) ;
if ( ! V_229 )
return - V_21 ;
V_45 -> V_16 = V_229 ;
V_45 -> V_16 [ V_45 -> V_234 ] = * V_228 ;
V_45 -> V_234 ++ ;
break;
}
default:
F_12 ( V_2 , L_36 , V_131 ) ;
break;
}
}
if ( ! F_45 ( V_63 , V_235 ) &&
V_135 && ! * V_124 ) {
F_11 ( V_2 ,
L_37 ) ;
return - V_20 ;
}
if ( V_6 ) {
F_11 ( V_2 , L_38 , V_6 ) ;
F_46 ( V_2 , V_236 , ( T_3 * ) V_5 , V_6 ) ;
return - V_20 ;
}
if ( F_45 ( V_63 , V_237 ) &&
! V_64 ) {
F_12 ( V_2 ,
L_39 ) ;
F_47 ( ( V_238 long ) V_237 ,
V_63 -> V_98 ) ;
}
return 0 ;
V_146:
F_11 ( V_2 , L_40 , V_131 , V_128 ) ;
V_154:
F_46 ( V_2 , V_236 , V_132 , V_128 ) ;
return - V_20 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
enum V_46 type )
{
int V_9 ;
struct V_3 * V_11 ;
V_11 = F_49 ( V_45 -> V_8 [ type ] . V_50 , sizeof( * V_11 ) , V_42 ) ;
if ( ! V_11 )
return - V_21 ;
V_2 -> V_12 . V_8 [ type ] . V_11 = V_11 ;
V_2 -> V_12 . V_8 [ type ] . V_10 = V_45 -> V_8 [ type ] . V_50 ;
for ( V_9 = 0 ; V_9 < V_45 -> V_8 [ type ] . V_50 ; V_9 ++ )
if ( F_7 ( V_2 , & V_11 [ V_9 ] , F_14 ( V_45 , type , V_9 ) ) )
return - V_21 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
const struct V_24 * V_25 )
{
F_12 ( V_2 , L_41 ,
F_19 ( V_45 , V_112 ,
V_113 ) ) ;
F_12 ( V_2 , L_42 ,
F_19 ( V_45 , V_112 ,
V_115 ) ) ;
F_12 ( V_2 , L_43 ,
F_19 ( V_45 , V_117 , V_113 ) ) ;
F_12 ( V_2 , L_44 ,
F_19 ( V_45 , V_117 , V_115 ) ) ;
if ( F_19 ( V_45 , V_112 , V_113 ) >
V_25 -> V_239 ) {
F_11 ( V_2 , L_45 ,
F_19 ( V_45 , V_112 ,
V_113 ) ) ;
return - 1 ;
}
if ( F_19 ( V_45 , V_112 , V_115 ) >
V_25 -> V_240 ) {
F_11 ( V_2 , L_46 ,
F_19 ( V_45 , V_112 ,
V_115 ) ) ;
return - 1 ;
}
if ( F_19 ( V_45 , V_117 , V_113 ) >
V_25 -> V_239 ) {
F_11 ( V_2 , L_47 ,
F_19 ( V_45 , V_117 ,
V_113 ) ) ;
return - 1 ;
}
if ( F_19 ( V_45 , V_117 , V_115 ) >
V_25 -> V_240 ) {
F_11 ( V_2 , L_48 ,
F_19 ( V_45 , V_112 ,
V_115 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_241 *
F_51 ( struct V_1 * V_2 , struct V_242 * V_243 )
{
const struct V_244 * V_245 = V_243 -> V_245 ;
struct V_246 * V_247 = NULL ;
struct V_241 * V_248 = NULL ;
#ifdef F_52
V_2 -> V_249 = F_53 ( V_243 -> V_250 ,
V_2 -> V_251 ) ;
if ( ! V_2 -> V_249 ) {
F_11 ( V_2 ,
L_49 ) ;
return V_248 ;
}
V_247 = V_2 -> V_249 ;
#endif
V_248 = V_245 -> V_252 ( V_2 -> V_26 , V_2 -> V_26 -> V_25 , & V_2 -> V_12 , V_247 ) ;
#ifdef F_52
if ( ! V_248 ) {
F_54 ( V_2 -> V_249 ) ;
V_2 -> V_249 = NULL ;
}
#endif
return V_248 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_248 ) {
F_56 ( V_2 -> V_248 ) ;
V_2 -> V_248 = NULL ;
#ifdef F_52
F_54 ( V_2 -> V_249 ) ;
V_2 -> V_249 = NULL ;
#endif
}
}
static void V_43 ( const struct V_99 * V_100 , void * V_253 )
{
struct V_1 * V_2 = V_253 ;
struct V_51 * V_12 = & V_2 -> V_12 ;
struct V_101 * V_102 ;
struct V_242 * V_243 ;
int V_254 ;
struct V_44 * V_45 ;
const unsigned int V_255 = V_2 -> V_26 -> V_25 -> V_36 ;
const unsigned int V_256 = V_2 -> V_26 -> V_25 -> V_37 ;
T_1 V_257 [ V_258 ] ;
T_2 V_103 ;
int V_9 ;
bool V_259 = false ;
bool V_124 = false ;
V_12 -> V_95 . V_147 = V_260 ;
V_12 -> V_95 . V_174 =
V_261 ;
V_12 -> V_95 . V_195 = V_262 ;
V_45 = F_57 ( sizeof( * V_45 ) , V_42 ) ;
if ( ! V_45 )
goto V_263;
if ( ! V_100 )
goto V_264;
F_12 ( V_2 , L_50 ,
V_2 -> V_39 , V_100 -> V_19 ) ;
if ( V_100 -> V_19 < 4 ) {
F_11 ( V_2 , L_51 ) ;
goto V_264;
}
V_102 = (struct V_101 * ) V_100 -> V_5 ;
if ( V_102 -> V_109 )
V_254 = F_32 ( V_2 , V_100 , V_45 ) ;
else
V_254 = F_37 ( V_2 , V_100 , V_45 ,
& V_12 -> V_95 , & V_124 ) ;
if ( V_254 )
goto V_264;
if ( F_58 ( & V_2 -> V_12 . V_95 , V_265 ) )
V_103 = V_2 -> V_12 . V_108 ;
else
V_103 = F_33 ( V_2 -> V_12 . V_108 ) ;
if ( V_103 < V_256 || V_103 > V_255 ) {
F_11 ( V_2 ,
L_52
L_53 ,
V_255 , V_103 ) ;
goto V_264;
}
if ( V_12 -> type == V_266 && F_50 ( V_2 , V_45 ,
V_2 -> V_26 -> V_25 ) )
goto V_264;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
if ( F_48 ( V_2 , V_45 , V_9 ) )
goto V_263;
if ( V_45 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_59 ( V_45 -> V_13 ,
sizeof( * V_45 -> V_13 ) +
sizeof( V_45 -> V_13 -> V_206 [ 0 ] ) *
V_2 -> V_12 . V_205 , V_42 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_263;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_45 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_212 [ V_9 ] =
V_45 -> V_212 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_59 ( V_45 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_212 [ V_9 ] ,
V_42 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_263;
}
}
memset ( & V_257 , 0xff , sizeof( V_257 ) ) ;
V_257 [ V_267 ] =
sizeof( struct V_268 ) ;
V_257 [ V_269 ] = 0 ;
V_257 [ V_270 ] =
sizeof( struct V_271 ) ;
V_257 [ V_272 ] =
sizeof( struct V_273 ) ;
V_257 [ V_274 ] =
sizeof( struct V_275 ) ;
V_257 [ V_276 ] =
sizeof( struct V_277 ) ;
V_257 [ V_278 ] =
sizeof( struct V_279 ) ;
V_257 [ V_280 ] =
sizeof( struct V_281 ) ;
V_257 [ V_282 ] =
sizeof( struct V_283 ) ;
V_257 [ V_284 ] =
sizeof( struct V_285 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_45 -> V_15 [ V_9 ] ) {
if ( F_25 ( V_45 -> V_217 [ V_9 ] <
( V_257 [ V_9 ] +
sizeof( struct V_214 ) ) ) )
goto V_263;
V_2 -> V_12 . V_217 [ V_9 ] =
V_45 -> V_217 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_59 ( V_45 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_217 [ V_9 ] ,
V_42 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_263;
}
}
V_2 -> V_12 . V_16 = V_45 -> V_16 ;
V_45 -> V_16 = NULL ;
V_2 -> V_12 . V_234 = V_45 -> V_234 ;
V_12 -> V_157 = V_45 -> V_157 ;
if ( V_45 -> V_159 )
V_12 -> V_159 = ( V_45 -> V_159 - 16 ) / 12 ;
else
V_12 -> V_159 =
V_2 -> V_26 -> V_25 -> V_286 -> V_287 ;
V_12 -> V_161 = V_45 -> V_161 ;
V_12 -> V_163 = V_45 -> V_163 ;
if ( V_45 -> V_165 )
V_12 -> V_165 = ( V_45 -> V_165 - 16 ) / 12 ;
else
V_12 -> V_165 =
V_2 -> V_26 -> V_25 -> V_286 -> V_287 ;
V_12 -> V_167 = V_45 -> V_167 ;
if ( V_12 -> V_95 . V_174 >
V_288 )
V_12 -> V_95 . V_174 =
V_289 ;
F_60 ( V_100 ) ;
F_61 ( & V_290 ) ;
switch ( V_12 -> type ) {
case V_266 :
V_243 = & V_242 [ V_291 ] ;
break;
default:
F_62 ( 1 , L_54 , V_12 -> type ) ;
case V_176 :
V_243 = & V_242 [ V_292 ] ;
break;
}
F_41 ( V_2 , L_55 ,
V_2 -> V_12 . V_121 , V_243 -> V_250 ) ;
F_63 ( & V_2 -> V_293 , & V_243 -> V_2 ) ;
if ( V_243 -> V_245 ) {
V_2 -> V_248 = F_51 ( V_2 , V_243 ) ;
if ( ! V_2 -> V_248 ) {
F_64 ( & V_290 ) ;
goto V_294;
}
} else {
V_259 = true ;
}
F_64 ( & V_290 ) ;
F_65 ( & V_2 -> V_295 ) ;
if ( V_259 ) {
F_66 ( L_56 , V_243 -> V_250 ) ;
#ifdef F_67
if ( V_254 )
F_11 ( V_2 ,
L_57 ,
V_243 -> V_250 , V_254 ) ;
#endif
}
goto free;
V_264:
F_60 ( V_100 ) ;
if ( F_9 ( V_2 , false ) )
goto V_294;
goto free;
V_263:
F_5 ( V_2 ) ;
F_60 ( V_100 ) ;
V_294:
F_65 ( & V_2 -> V_295 ) ;
F_68 ( V_2 -> V_26 -> V_41 ) ;
free:
if ( V_45 ) {
for ( V_9 = 0 ; V_9 < F_6 ( V_45 -> V_8 ) ; V_9 ++ )
F_4 ( V_45 -> V_8 [ V_9 ] . V_11 ) ;
F_4 ( V_45 -> V_16 ) ;
F_4 ( V_45 ) ;
}
}
struct V_1 * F_69 ( struct V_296 * V_26 )
{
struct V_1 * V_2 ;
int V_297 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 ) {
V_297 = - V_21 ;
goto V_254;
}
V_2 -> V_26 = V_26 ;
V_2 -> V_41 = V_26 -> V_41 ;
F_70 ( & V_2 -> V_295 ) ;
F_71 ( & V_2 -> V_293 ) ;
#ifdef F_52
V_2 -> V_251 = F_53 ( F_72 ( V_26 -> V_41 ) ,
V_298 ) ;
if ( ! V_2 -> V_251 ) {
F_11 ( V_2 , L_58 ) ;
V_297 = - V_21 ;
goto V_299;
}
V_2 -> V_26 -> V_247 = F_53 ( L_59 , V_2 -> V_251 ) ;
if ( ! V_2 -> V_26 -> V_247 ) {
F_11 ( V_2 , L_60 ) ;
V_297 = - V_21 ;
goto V_300;
}
#endif
V_297 = F_9 ( V_2 , true ) ;
if ( V_297 ) {
F_11 ( V_26 , L_61 ) ;
goto V_301;
}
return V_2 ;
V_301:
#ifdef F_52
V_300:
F_54 ( V_2 -> V_251 ) ;
V_299:
#endif
F_4 ( V_2 ) ;
V_254:
return F_73 ( V_297 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( & V_2 -> V_295 ) ;
F_55 ( V_2 ) ;
F_5 ( V_2 ) ;
F_61 ( & V_290 ) ;
if ( ! F_76 ( & V_2 -> V_293 ) )
F_77 ( & V_2 -> V_293 ) ;
F_64 ( & V_290 ) ;
#ifdef F_52
F_54 ( V_2 -> V_251 ) ;
#endif
F_4 ( V_2 ) ;
}
int F_78 ( const char * V_250 , const struct V_244 * V_245 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_242 * V_243 ;
F_61 ( & V_290 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_242 ) ; V_9 ++ ) {
V_243 = & V_242 [ V_9 ] ;
if ( strcmp ( V_243 -> V_250 , V_250 ) )
continue;
V_243 -> V_245 = V_245 ;
F_79 (drv, &op->drv, list)
V_2 -> V_248 = F_51 ( V_2 , V_243 ) ;
F_64 ( & V_290 ) ;
return 0 ;
}
F_64 ( & V_290 ) ;
return - V_302 ;
}
void F_80 ( const char * V_250 )
{
int V_9 ;
struct V_1 * V_2 ;
F_61 ( & V_290 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_242 ) ; V_9 ++ ) {
if ( strcmp ( V_242 [ V_9 ] . V_250 , V_250 ) )
continue;
V_242 [ V_9 ] . V_245 = NULL ;
F_79 (drv, &iwlwifi_opmode_table[i].drv, list)
F_55 ( V_2 ) ;
F_64 ( & V_290 ) ;
return;
}
F_64 ( & V_290 ) ;
}
static int T_4 F_81 ( void )
{
int V_9 ;
F_82 ( & V_290 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_242 ) ; V_9 ++ )
F_71 ( & V_242 [ V_9 ] . V_2 ) ;
F_83 ( V_303 L_62 ) ;
F_83 ( V_304 L_62 ) ;
#ifdef F_52
V_298 = F_53 ( V_305 , NULL ) ;
if ( ! V_298 )
return - V_306 ;
#endif
return F_84 () ;
}
static void T_5 F_85 ( void )
{
F_86 () ;
#ifdef F_52
F_54 ( V_298 ) ;
#endif
}
