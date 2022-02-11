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
const char * V_24 = V_2 -> V_25 -> V_26 -> V_27 ;
char V_28 [ 8 ] ;
if ( V_23 ) {
V_2 -> V_29 = V_2 -> V_25 -> V_26 -> V_30 ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
} else {
V_2 -> V_29 -- ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
}
if ( V_2 -> V_29 < V_2 -> V_25 -> V_26 -> V_31 ) {
F_10 ( V_2 , L_2 ) ;
return - V_32 ;
}
snprintf ( V_2 -> V_33 , sizeof( V_2 -> V_33 ) , L_3 ,
V_24 , V_28 ) ;
F_11 ( V_2 , L_4 ,
V_2 -> V_33 ) ;
return F_12 ( V_34 , 1 , V_2 -> V_33 ,
V_2 -> V_25 -> V_35 ,
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
int V_11 )
{
struct V_41 * V_8 = & V_39 -> V_8 [ type ] ;
struct V_18 * V_42 ;
int V_19 = V_11 + 1 ;
T_1 V_43 = sizeof( * V_8 -> V_11 ) * V_19 ;
if ( V_8 -> V_11 && V_8 -> V_44 >= V_19 )
return;
V_42 = F_15 ( V_8 -> V_11 , V_43 , V_36 ) ;
if ( ! V_42 )
return;
V_8 -> V_11 = V_42 ;
V_8 -> V_44 = V_19 ;
}
static void F_16 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
const void * V_5 )
{
F_14 ( V_39 , type , V_11 ) ;
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_17 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
T_1 V_19 )
{
F_14 ( V_39 , type , V_11 ) ;
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 = V_19 ;
}
static T_1 F_18 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 )
{
return V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_19 ;
}
static void F_19 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_11 ,
T_2 V_22 )
{
F_14 ( V_39 , type , V_11 ) ;
V_39 -> V_8 [ type ] . V_11 [ V_11 ] . V_22 = V_22 ;
}
static int F_20 ( struct V_45 * V_12 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_46 ;
struct V_47 * V_48 = (struct V_47 * ) V_5 ;
struct V_49 * V_50 ;
if ( V_6 < sizeof( * V_48 ) ||
V_6 < sizeof( V_48 -> V_19 ) + V_48 -> V_19 * sizeof( V_48 -> V_51 [ 0 ] ) )
return - V_20 ;
for ( V_9 = 0 , V_46 = 0 ; V_9 < V_52 && V_9 < V_48 -> V_19 ; V_9 ++ ) {
V_50 = & V_48 -> V_51 [ V_46 ] ;
if ( ! V_50 -> V_53 )
continue;
V_12 -> V_51 [ V_46 ++ ] = * V_50 ;
}
return 0 ;
}
static void F_21 ( struct V_45 * V_12 , const T_3 * V_5 ,
const T_2 V_6 )
{
struct V_54 * V_55 = ( void * ) V_5 ;
struct V_56 * V_57 = & V_12 -> V_58 ;
V_57 -> V_59 = F_22 ( V_55 -> V_59 ) ;
V_57 -> V_60 = F_22 ( V_55 -> V_60 ) ;
V_57 -> V_61 =
F_22 ( V_55 -> V_61 ) ;
V_57 -> V_62 = F_22 ( V_55 -> V_62 ) ;
V_57 -> V_63 =
F_22 ( V_55 -> V_63 ) ;
V_57 -> V_64 = F_22 ( V_55 -> V_64 ) ;
V_57 -> V_65 =
F_22 ( V_55 -> V_65 ) ;
V_57 -> V_66 =
F_22 ( V_55 -> V_66 ) ;
V_57 -> V_67 = F_22 ( V_55 -> V_67 ) ;
V_57 -> V_68 =
F_22 ( V_55 -> V_68 ) ;
V_57 -> V_69 =
F_22 ( V_55 -> V_69 ) ;
V_57 -> V_70 =
F_22 ( V_55 -> V_70 ) ;
V_57 -> V_71 =
F_22 ( V_55 -> V_71 ) ;
}
static int F_23 ( struct V_38 * V_39 ,
const void * V_5 , enum V_40 type ,
int V_19 )
{
struct V_41 * V_8 ;
struct V_18 * V_11 ;
struct V_72 * V_73 ;
T_1 V_43 ;
if ( F_24 ( ! V_39 || ! V_5 || type >= V_17 ) )
return - 1 ;
V_73 = (struct V_72 * ) V_5 ;
V_8 = & V_39 -> V_8 [ type ] ;
V_43 = sizeof( * V_8 -> V_11 ) * ( V_8 -> V_44 + 1 ) ;
V_11 = F_15 ( V_8 -> V_11 , V_43 , V_36 ) ;
if ( ! V_11 )
return - V_21 ;
V_8 -> V_11 = V_11 ;
V_11 = & V_8 -> V_11 [ V_8 -> V_44 ] ;
V_11 -> V_22 = F_22 ( V_73 -> V_22 ) ;
V_11 -> V_5 = V_73 -> V_5 ;
V_11 -> V_19 = V_19 - sizeof( V_73 -> V_22 ) ;
++ V_8 -> V_44 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_74 * V_75 =
(struct V_74 * ) V_5 ;
T_2 V_76 = F_22 ( V_75 -> V_76 ) ;
if ( V_76 >= V_17 ) {
F_10 ( V_2 , L_5 ,
V_76 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_77 [ V_76 ] . V_78 =
V_75 -> V_79 . V_78 ;
V_2 -> V_12 . V_77 [ V_76 ] . V_80 =
V_75 -> V_79 . V_80 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_81 * V_57 )
{
const struct V_82 * V_83 = ( void * ) V_5 ;
T_2 V_84 = F_22 ( V_83 -> V_84 ) ;
T_2 V_85 = F_22 ( V_83 -> V_85 ) ;
int V_9 ;
if ( V_84 >= F_27 ( V_86 , 32 ) ) {
F_10 ( V_2 ,
L_6 ,
V_84 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_85 & F_28 ( V_9 ) )
F_29 ( V_9 + 32 * V_84 , V_57 -> V_87 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_81 * V_57 )
{
const struct V_88 * V_89 = ( void * ) V_5 ;
T_2 V_84 = F_22 ( V_89 -> V_84 ) ;
T_2 V_85 = F_22 ( V_89 -> V_90 ) ;
int V_9 ;
if ( V_84 >= F_27 ( V_91 , 32 ) ) {
F_10 ( V_2 ,
L_7 ,
V_84 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_85 & F_28 ( V_9 ) )
F_29 ( V_9 + 32 * V_84 , V_57 -> V_92 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_38 * V_39 )
{
struct V_95 * V_96 = ( void * ) V_94 -> V_5 ;
T_2 V_97 , V_98 , V_99 ;
char V_100 [ 25 ] ;
const T_3 * V_101 ;
V_2 -> V_12 . V_102 = F_22 ( V_96 -> V_103 ) ;
V_97 = F_32 ( V_2 -> V_12 . V_102 ) ;
switch ( V_97 ) {
default:
V_98 = 28 ;
if ( V_94 -> V_19 < V_98 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_99 = F_22 ( V_96 -> V_104 . V_105 . V_99 ) ;
F_17 ( V_39 , V_106 , V_107 ,
F_22 ( V_96 -> V_104 . V_105 . V_108 ) ) ;
F_17 ( V_39 , V_106 , V_109 ,
F_22 ( V_96 -> V_104 . V_105 . V_110 ) ) ;
F_17 ( V_39 , V_111 , V_107 ,
F_22 ( V_96 -> V_104 . V_105 . V_112 ) ) ;
F_17 ( V_39 , V_111 , V_109 ,
F_22 ( V_96 -> V_104 . V_105 . V_113 ) ) ;
V_101 = V_96 -> V_104 . V_105 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_98 = 24 ;
if ( V_94 -> V_19 < V_98 ) {
F_10 ( V_2 , L_8 ) ;
return - V_20 ;
}
V_99 = 0 ;
F_17 ( V_39 , V_106 , V_107 ,
F_22 ( V_96 -> V_104 . V_114 . V_108 ) ) ;
F_17 ( V_39 , V_106 , V_109 ,
F_22 ( V_96 -> V_104 . V_114 . V_110 ) ) ;
F_17 ( V_39 , V_111 , V_107 ,
F_22 ( V_96 -> V_104 . V_114 . V_112 ) ) ;
F_17 ( V_39 , V_111 , V_109 ,
F_22 ( V_96 -> V_104 . V_114 . V_113 ) ) ;
V_101 = V_96 -> V_104 . V_114 . V_5 ;
break;
}
if ( V_99 )
sprintf ( V_100 , L_9 , V_99 ) ;
else
V_100 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_115 ,
sizeof( V_2 -> V_12 . V_115 ) ,
L_10 ,
F_33 ( V_2 -> V_12 . V_102 ) ,
F_34 ( V_2 -> V_12 . V_102 ) ,
F_32 ( V_2 -> V_12 . V_102 ) ,
F_35 ( V_2 -> V_12 . V_102 ) ,
V_100 ) ;
if ( V_94 -> V_19 != V_98 +
F_18 ( V_39 , V_106 , V_107 ) +
F_18 ( V_39 , V_106 , V_109 ) +
F_18 ( V_39 , V_111 , V_107 ) +
F_18 ( V_39 , V_111 , V_109 ) ) {
F_10 ( V_2 ,
L_11 ,
( int ) V_94 -> V_19 ) ;
return - V_20 ;
}
F_16 ( V_39 , V_106 , V_107 , V_101 ) ;
V_101 += F_18 ( V_39 , V_106 , V_107 ) ;
F_19 ( V_39 , V_106 , V_107 ,
V_116 ) ;
F_16 ( V_39 , V_106 , V_109 , V_101 ) ;
V_101 += F_18 ( V_39 , V_106 , V_109 ) ;
F_19 ( V_39 , V_106 , V_109 ,
V_117 ) ;
F_16 ( V_39 , V_111 , V_107 , V_101 ) ;
V_101 += F_18 ( V_39 , V_111 , V_107 ) ;
F_19 ( V_39 , V_111 , V_107 ,
V_116 ) ;
F_16 ( V_39 , V_111 , V_109 , V_101 ) ;
V_101 += F_18 ( V_39 , V_111 , V_109 ) ;
F_19 ( V_39 , V_111 , V_109 ,
V_117 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_38 * V_39 ,
struct V_81 * V_57 ,
bool * V_118 )
{
struct V_119 * V_96 = ( void * ) V_94 -> V_5 ;
struct V_120 * V_121 ;
T_1 V_6 = V_94 -> V_19 ;
const T_3 * V_5 ;
T_2 V_122 ;
T_2 V_123 ;
enum V_124 V_125 ;
const T_3 * V_126 ;
char V_100 [ 25 ] ;
T_2 V_99 , V_127 ;
int V_128 ;
bool V_129 = false ;
bool V_58 = false ;
if ( V_6 < sizeof( * V_96 ) ) {
F_10 ( V_2 , L_12 , V_6 ) ;
return - V_20 ;
}
if ( V_96 -> V_130 != F_37 ( V_131 ) ) {
F_10 ( V_2 , L_13 ,
F_22 ( V_96 -> V_130 ) ) ;
return - V_20 ;
}
V_2 -> V_12 . V_102 = F_22 ( V_96 -> V_103 ) ;
memcpy ( V_2 -> V_12 . V_132 , V_96 -> V_132 ,
sizeof( V_2 -> V_12 . V_132 ) ) ;
V_99 = F_22 ( V_96 -> V_99 ) ;
if ( V_99 )
sprintf ( V_100 , L_9 , V_99 ) ;
else
V_100 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_12 . V_115 ,
sizeof( V_2 -> V_12 . V_115 ) ,
L_10 ,
F_33 ( V_2 -> V_12 . V_102 ) ,
F_34 ( V_2 -> V_12 . V_102 ) ,
F_32 ( V_2 -> V_12 . V_102 ) ,
F_35 ( V_2 -> V_12 . V_102 ) ,
V_100 ) ;
V_5 = V_96 -> V_5 ;
V_6 -= sizeof( * V_96 ) ;
while ( V_6 >= sizeof( * V_121 ) ) {
V_6 -= sizeof( * V_121 ) ;
V_121 = ( void * ) V_5 ;
V_122 = F_22 ( V_121 -> V_133 ) ;
V_125 = F_22 ( V_121 -> type ) ;
V_126 = V_121 -> V_5 ;
if ( V_6 < V_122 ) {
F_10 ( V_2 , L_14 ,
V_6 , V_122 ) ;
return - V_20 ;
}
V_6 -= F_38 ( V_122 , 4 ) ;
V_5 += sizeof( * V_121 ) + F_38 ( V_122 , 4 ) ;
switch ( V_125 ) {
case V_134 :
F_16 ( V_39 , V_106 ,
V_107 , V_126 ) ;
F_17 ( V_39 , V_106 ,
V_107 , V_122 ) ;
F_19 ( V_39 , V_106 ,
V_107 ,
V_116 ) ;
break;
case V_135 :
F_16 ( V_39 , V_106 ,
V_109 , V_126 ) ;
F_17 ( V_39 , V_106 ,
V_109 , V_122 ) ;
F_19 ( V_39 , V_106 ,
V_109 ,
V_117 ) ;
break;
case V_136 :
F_16 ( V_39 , V_111 ,
V_107 , V_126 ) ;
F_17 ( V_39 , V_111 ,
V_107 , V_122 ) ;
F_19 ( V_39 , V_111 ,
V_107 ,
V_116 ) ;
break;
case V_137 :
F_16 ( V_39 , V_111 ,
V_109 , V_126 ) ;
F_17 ( V_39 , V_111 ,
V_109 , V_122 ) ;
F_19 ( V_39 , V_111 ,
V_109 ,
V_117 ) ;
break;
case V_138 :
F_10 ( V_2 , L_15 ) ;
break;
case V_139 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_57 -> V_141 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_143 :
if ( V_122 )
goto V_140;
V_57 -> V_144 |= V_145 ;
break;
case V_146 :
if ( V_122 < sizeof( T_2 ) )
goto V_140;
if ( V_122 % sizeof( T_2 ) )
goto V_140;
V_57 -> V_144 = F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_147 :
if ( V_122 != sizeof( struct V_82 ) )
goto V_140;
if ( F_26 ( V_2 , V_126 , V_57 ) )
goto V_148;
break;
case V_149 :
if ( V_122 != sizeof( struct V_88 ) )
goto V_140;
if ( F_30 ( V_2 , V_126 , V_57 ) )
goto V_148;
break;
case V_150 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_151 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_152 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_153 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_154 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_155 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_156 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_157 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_158 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_159 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_160 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_39 -> V_161 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_162 :
if ( V_122 )
goto V_140;
V_2 -> V_12 . V_163 = true ;
break;
case V_164 :
F_16 ( V_39 , V_165 ,
V_107 , V_126 ) ;
F_17 ( V_39 , V_165 ,
V_107 , V_122 ) ;
F_19 ( V_39 , V_165 ,
V_107 ,
V_116 ) ;
break;
case V_166 :
F_16 ( V_39 , V_165 ,
V_109 , V_126 ) ;
F_17 ( V_39 , V_165 ,
V_109 , V_122 ) ;
F_19 ( V_39 , V_165 ,
V_109 ,
V_117 ) ;
break;
case V_167 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_57 -> V_168 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_169 :
F_23 ( V_39 , V_126 , V_106 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_171 :
F_23 ( V_39 , V_126 , V_111 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_172 :
F_23 ( V_39 , V_126 , V_165 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_173 :
if ( V_122 != sizeof( struct V_74 ) )
goto V_140;
if ( F_25 ( V_2 , V_126 ) )
goto V_148;
break;
case V_174 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_2 -> V_12 . V_175 = F_39 ( ( V_142 * ) V_126 ) ;
V_2 -> V_12 . V_176 = ( V_2 -> V_12 . V_175 &
V_177 ) >>
V_178 ;
V_2 -> V_12 . V_179 = ( V_2 -> V_12 . V_175 &
V_180 ) >>
V_181 ;
break;
case V_182 :
F_23 ( V_39 , V_126 , V_106 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_183 :
F_23 ( V_39 , V_126 , V_111 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_184 :
F_23 ( V_39 , V_126 , V_165 ,
V_122 ) ;
V_2 -> V_12 . type = V_170 ;
break;
case V_185 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_128 =
F_39 ( ( V_142 * ) V_126 ) ;
if ( V_128 == 2 ) {
V_2 -> V_12 . V_8 [ V_106 ] . V_186 =
true ;
V_2 -> V_12 . V_8 [ V_111 ] . V_186 =
true ;
V_2 -> V_12 . V_8 [ V_165 ] . V_186 =
true ;
} else if ( ( V_128 > 2 ) || ( V_128 < 1 ) ) {
F_10 ( V_2 , L_16 ) ;
return - V_20 ;
}
break;
case V_187 :
if ( F_20 ( & V_2 -> V_12 , V_126 , V_122 ) )
goto V_140;
break;
case V_188 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_57 -> V_189 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_190 : {
V_142 * V_191 = ( void * ) V_126 ;
T_2 V_192 , V_193 ;
T_3 V_194 ;
if ( V_122 != sizeof( T_2 ) * 3 )
goto V_140;
V_192 = F_39 ( V_191 ++ ) ;
V_193 = F_39 ( V_191 ++ ) ;
V_194 = F_39 ( V_191 ) ;
snprintf ( V_2 -> V_12 . V_115 ,
sizeof( V_2 -> V_12 . V_115 ) , L_17 ,
V_192 , V_193 , V_194 ) ;
break;
}
case V_195 : {
struct V_196 * V_197 = ( void * ) V_126 ;
if ( V_39 -> V_13 ) {
F_10 ( V_2 ,
L_18 ) ;
break;
}
V_39 -> V_13 = V_197 ;
F_40 ( V_2 , L_19 ,
F_41 ( V_197 -> V_198 ) ) ;
V_2 -> V_12 . V_199 =
V_122 - F_42 ( struct V_196 ,
V_200 ) ;
V_2 -> V_12 . V_199 /=
sizeof( V_2 -> V_12 . V_13 -> V_200 [ 0 ] ) ;
break;
}
case V_201 : {
struct V_202 * V_203 = ( void * ) V_126 ;
if ( ! V_39 -> V_13 ) {
F_10 ( V_2 ,
L_20 ,
V_203 -> V_204 ) ;
break;
}
if ( V_203 -> V_204 >= F_6 ( V_2 -> V_12 . V_14 ) ) {
F_10 ( V_2 ,
L_21 ,
V_203 -> V_204 ) ;
break;
}
if ( V_39 -> V_14 [ V_203 -> V_204 ] ) {
F_10 ( V_2 ,
L_22 ,
V_203 -> V_204 ) ;
break;
}
if ( V_203 -> V_205 )
V_129 = true ;
F_40 ( V_2 , L_23 ,
V_203 -> V_204 ) ;
V_39 -> V_14 [ V_203 -> V_204 ] = V_203 ;
V_39 -> V_206 [ V_203 -> V_204 ] = V_122 ;
break;
}
case V_207 : {
struct V_208 * V_209 =
( void * ) V_126 ;
T_2 V_210 = F_22 ( V_209 -> V_204 ) ;
if ( V_210 >= F_6 ( V_2 -> V_12 . V_15 ) ) {
F_10 ( V_2 ,
L_24 ,
V_209 -> V_204 ) ;
break;
}
if ( V_39 -> V_15 [ V_210 ] ) {
F_10 ( V_2 ,
L_25 ,
V_209 -> V_204 ) ;
break;
}
F_40 ( V_2 , L_26 , V_209 -> V_204 ) ;
V_39 -> V_15 [ V_210 ] = V_209 ;
V_39 -> V_211 [ V_210 ] = V_122 ;
break;
}
case V_212 :
* V_118 = true ;
F_23 ( V_39 , V_126 ,
V_213 ,
V_122 ) ;
break;
case V_214 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_127 = F_39 ( ( V_142 * ) V_126 ) ;
F_43 ( V_2 ,
L_27 ,
V_127 ) ;
if ( V_127 > V_215 ) {
F_10 ( V_2 ,
L_28 ,
V_215 ) ;
return - V_20 ;
}
if ( V_127 & ( V_216 - 1 ) ) {
F_10 ( V_2 ,
L_29 ,
V_216 ) ;
return - V_20 ;
}
V_2 -> V_12 . V_8 [ V_106 ] . V_127 =
V_127 ;
V_123 = V_213 ;
V_2 -> V_12 . V_8 [ V_123 ] . V_127 =
V_127 ;
break;
case V_217 :
if ( V_122 != sizeof( T_2 ) )
goto V_140;
V_2 -> V_12 . V_218 =
F_39 ( ( V_142 * ) V_126 ) ;
break;
case V_219 :
if ( V_122 < sizeof( struct V_54 ) )
break;
F_21 ( & V_2 -> V_12 , V_126 , V_122 ) ;
V_58 = true ;
break;
case V_220 : {
struct V_221 * V_222 =
( void * ) V_126 ;
T_2 type ;
T_1 V_19 ;
struct V_221 * V_223 ;
if ( V_122 != ( sizeof( * V_222 ) ) )
goto V_140;
type = F_22 ( V_222 -> V_224 ) ;
F_11 ( V_2 , L_30 ,
V_222 -> V_224 ) ;
switch ( type & V_225 ) {
case V_226 :
case V_227 :
break;
default:
F_10 ( V_2 ,
L_31 ,
type ) ;
return - V_20 ;
}
V_19 = sizeof( * V_39 -> V_16 ) *
( V_39 -> V_228 + 1 ) ;
V_223 = F_15 ( V_39 -> V_16 , V_19 , V_36 ) ;
if ( ! V_223 )
return - V_21 ;
V_39 -> V_16 = V_223 ;
V_39 -> V_16 [ V_39 -> V_228 ] = * V_222 ;
V_39 -> V_228 ++ ;
break;
}
default:
F_11 ( V_2 , L_32 , V_125 ) ;
break;
}
}
if ( ! F_44 ( V_57 , V_229 ) &&
V_129 && ! * V_118 ) {
F_10 ( V_2 ,
L_33 ) ;
return - V_20 ;
}
if ( V_6 ) {
F_10 ( V_2 , L_34 , V_6 ) ;
F_45 ( V_2 , V_230 , ( T_3 * ) V_5 , V_6 ) ;
return - V_20 ;
}
if ( F_44 ( V_57 , V_231 ) &&
! V_58 ) {
F_11 ( V_2 ,
L_35 ) ;
F_46 ( ( V_232 long ) V_231 ,
V_57 -> V_92 ) ;
}
return 0 ;
V_140:
F_10 ( V_2 , L_36 , V_125 , V_122 ) ;
V_148:
F_45 ( V_2 , V_230 , V_126 , V_122 ) ;
return - V_20 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
enum V_40 type )
{
int V_9 ;
struct V_3 * V_11 ;
V_11 = F_48 ( V_39 -> V_8 [ type ] . V_44 , sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return - V_21 ;
V_2 -> V_12 . V_8 [ type ] . V_11 = V_11 ;
V_2 -> V_12 . V_8 [ type ] . V_10 = V_39 -> V_8 [ type ] . V_44 ;
for ( V_9 = 0 ; V_9 < V_39 -> V_8 [ type ] . V_44 ; V_9 ++ )
if ( F_7 ( V_2 , & V_11 [ V_9 ] , F_13 ( V_39 , type , V_9 ) ) )
return - V_21 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_233 * V_26 )
{
F_11 ( V_2 , L_37 ,
F_18 ( V_39 , V_106 ,
V_107 ) ) ;
F_11 ( V_2 , L_38 ,
F_18 ( V_39 , V_106 ,
V_109 ) ) ;
F_11 ( V_2 , L_39 ,
F_18 ( V_39 , V_111 , V_107 ) ) ;
F_11 ( V_2 , L_40 ,
F_18 ( V_39 , V_111 , V_109 ) ) ;
if ( F_18 ( V_39 , V_106 , V_107 ) >
V_26 -> V_234 ) {
F_10 ( V_2 , L_41 ,
F_18 ( V_39 , V_106 ,
V_107 ) ) ;
return - 1 ;
}
if ( F_18 ( V_39 , V_106 , V_109 ) >
V_26 -> V_235 ) {
F_10 ( V_2 , L_42 ,
F_18 ( V_39 , V_106 ,
V_109 ) ) ;
return - 1 ;
}
if ( F_18 ( V_39 , V_111 , V_107 ) >
V_26 -> V_234 ) {
F_10 ( V_2 , L_43 ,
F_18 ( V_39 , V_111 ,
V_107 ) ) ;
return - 1 ;
}
if ( F_18 ( V_39 , V_111 , V_109 ) >
V_26 -> V_235 ) {
F_10 ( V_2 , L_44 ,
F_18 ( V_39 , V_106 ,
V_109 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_236 *
F_50 ( struct V_1 * V_2 , struct V_237 * V_238 )
{
const struct V_239 * V_240 = V_238 -> V_240 ;
struct V_241 * V_242 = NULL ;
struct V_236 * V_243 = NULL ;
#ifdef F_51
V_2 -> V_244 = F_52 ( V_238 -> V_245 ,
V_2 -> V_246 ) ;
if ( ! V_2 -> V_244 ) {
F_10 ( V_2 ,
L_45 ) ;
return V_243 ;
}
V_242 = V_2 -> V_244 ;
#endif
V_243 = V_240 -> V_247 ( V_2 -> V_25 , V_2 -> V_25 -> V_26 , & V_2 -> V_12 , V_242 ) ;
#ifdef F_51
if ( ! V_243 ) {
F_53 ( V_2 -> V_244 ) ;
V_2 -> V_244 = NULL ;
}
#endif
return V_243 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_243 ) {
F_55 ( V_2 -> V_243 ) ;
V_2 -> V_243 = NULL ;
#ifdef F_51
F_53 ( V_2 -> V_244 ) ;
V_2 -> V_244 = NULL ;
#endif
}
}
static void V_37 ( const struct V_93 * V_94 , void * V_248 )
{
struct V_1 * V_2 = V_248 ;
struct V_45 * V_12 = & V_2 -> V_12 ;
struct V_95 * V_96 ;
struct V_237 * V_238 ;
int V_249 ;
struct V_38 * V_39 ;
const unsigned int V_250 = V_2 -> V_25 -> V_26 -> V_30 ;
const unsigned int V_251 = V_2 -> V_25 -> V_26 -> V_31 ;
T_1 V_252 [ V_253 ] ;
T_2 V_97 ;
int V_9 ;
bool V_254 = false ;
bool V_118 = false ;
V_12 -> V_89 . V_141 = V_255 ;
V_12 -> V_89 . V_168 =
V_256 ;
V_12 -> V_89 . V_189 = V_257 ;
V_39 = F_56 ( sizeof( * V_39 ) , V_36 ) ;
if ( ! V_39 )
return;
if ( ! V_94 )
goto V_258;
F_11 ( V_2 , L_46 ,
V_2 -> V_33 , V_94 -> V_19 ) ;
if ( V_94 -> V_19 < 4 ) {
F_10 ( V_2 , L_47 ) ;
goto V_258;
}
V_96 = (struct V_95 * ) V_94 -> V_5 ;
if ( V_96 -> V_103 )
V_249 = F_31 ( V_2 , V_94 , V_39 ) ;
else
V_249 = F_36 ( V_2 , V_94 , V_39 ,
& V_12 -> V_89 , & V_118 ) ;
if ( V_249 )
goto V_258;
if ( F_57 ( & V_2 -> V_12 . V_89 , V_259 ) )
V_97 = V_2 -> V_12 . V_102 ;
else
V_97 = F_32 ( V_2 -> V_12 . V_102 ) ;
if ( V_97 < V_251 || V_97 > V_250 ) {
F_10 ( V_2 ,
L_48
L_49 ,
V_250 , V_97 ) ;
goto V_258;
}
if ( V_12 -> type == V_260 && F_49 ( V_2 , V_39 ,
V_2 -> V_25 -> V_26 ) )
goto V_258;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
if ( F_47 ( V_2 , V_39 , V_9 ) )
goto V_261;
if ( V_39 -> V_13 ) {
V_2 -> V_12 . V_13 =
F_58 ( V_39 -> V_13 ,
sizeof( * V_39 -> V_13 ) +
sizeof( V_39 -> V_13 -> V_200 [ 0 ] ) *
V_2 -> V_12 . V_199 , V_36 ) ;
if ( ! V_2 -> V_12 . V_13 )
goto V_261;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_14 ) ; V_9 ++ ) {
if ( V_39 -> V_14 [ V_9 ] ) {
V_2 -> V_12 . V_206 [ V_9 ] =
V_39 -> V_206 [ V_9 ] ;
V_2 -> V_12 . V_14 [ V_9 ] =
F_58 ( V_39 -> V_14 [ V_9 ] ,
V_2 -> V_12 . V_206 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_14 [ V_9 ] )
goto V_261;
}
}
memset ( & V_252 , 0xff , sizeof( V_252 ) ) ;
V_252 [ V_262 ] =
sizeof( struct V_263 ) ;
V_252 [ V_264 ] = 0 ;
V_252 [ V_265 ] =
sizeof( struct V_266 ) ;
V_252 [ V_267 ] =
sizeof( struct V_268 ) ;
V_252 [ V_269 ] =
sizeof( struct V_270 ) ;
V_252 [ V_271 ] =
sizeof( struct V_272 ) ;
V_252 [ V_273 ] =
sizeof( struct V_274 ) ;
V_252 [ V_275 ] =
sizeof( struct V_276 ) ;
V_252 [ V_277 ] =
sizeof( struct V_278 ) ;
V_252 [ V_279 ] =
sizeof( struct V_280 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_2 -> V_12 . V_15 ) ; V_9 ++ ) {
if ( V_39 -> V_15 [ V_9 ] ) {
if ( F_24 ( V_39 -> V_211 [ V_9 ] <
( V_252 [ V_9 ] +
sizeof( struct V_208 ) ) ) )
goto V_261;
V_2 -> V_12 . V_211 [ V_9 ] =
V_39 -> V_211 [ V_9 ] ;
V_2 -> V_12 . V_15 [ V_9 ] =
F_58 ( V_39 -> V_15 [ V_9 ] ,
V_2 -> V_12 . V_211 [ V_9 ] ,
V_36 ) ;
if ( ! V_2 -> V_12 . V_15 [ V_9 ] )
goto V_261;
}
}
V_2 -> V_12 . V_16 = V_39 -> V_16 ;
V_39 -> V_16 = NULL ;
V_2 -> V_12 . V_228 = V_39 -> V_228 ;
V_12 -> V_151 = V_39 -> V_151 ;
if ( V_39 -> V_153 )
V_12 -> V_153 = ( V_39 -> V_153 - 16 ) / 12 ;
else
V_12 -> V_153 =
V_2 -> V_25 -> V_26 -> V_281 -> V_282 ;
V_12 -> V_155 = V_39 -> V_155 ;
V_12 -> V_157 = V_39 -> V_157 ;
if ( V_39 -> V_159 )
V_12 -> V_159 = ( V_39 -> V_159 - 16 ) / 12 ;
else
V_12 -> V_159 =
V_2 -> V_25 -> V_26 -> V_281 -> V_282 ;
V_12 -> V_161 = V_39 -> V_161 ;
if ( V_12 -> V_89 . V_168 >
V_283 )
V_12 -> V_89 . V_168 =
V_284 ;
F_59 ( V_94 ) ;
F_60 ( & V_285 ) ;
switch ( V_12 -> type ) {
case V_260 :
V_238 = & V_237 [ V_286 ] ;
break;
default:
F_61 ( 1 , L_50 , V_12 -> type ) ;
case V_170 :
V_238 = & V_237 [ V_287 ] ;
break;
}
F_40 ( V_2 , L_51 ,
V_2 -> V_12 . V_115 , V_238 -> V_245 ) ;
F_62 ( & V_2 -> V_288 , & V_238 -> V_2 ) ;
if ( V_238 -> V_240 ) {
V_2 -> V_243 = F_50 ( V_2 , V_238 ) ;
if ( ! V_2 -> V_243 ) {
F_63 ( & V_285 ) ;
goto V_289;
}
} else {
V_254 = true ;
}
F_63 ( & V_285 ) ;
F_64 ( & V_2 -> V_290 ) ;
if ( V_254 ) {
V_249 = F_65 ( L_52 , V_238 -> V_245 ) ;
#ifdef F_66
if ( V_249 )
F_10 ( V_2 ,
L_53 ,
V_238 -> V_245 , V_249 ) ;
#endif
}
goto free;
V_258:
F_59 ( V_94 ) ;
if ( F_9 ( V_2 , false ) )
goto V_289;
goto free;
V_261:
F_10 ( V_2 , L_54 ) ;
F_5 ( V_2 ) ;
F_59 ( V_94 ) ;
V_289:
F_64 ( & V_2 -> V_290 ) ;
F_67 ( V_2 -> V_25 -> V_35 ) ;
free:
for ( V_9 = 0 ; V_9 < F_6 ( V_39 -> V_8 ) ; V_9 ++ )
F_4 ( V_39 -> V_8 [ V_9 ] . V_11 ) ;
F_4 ( V_39 -> V_16 ) ;
F_4 ( V_39 ) ;
}
struct V_1 * F_68 ( struct V_291 * V_25 )
{
struct V_1 * V_2 ;
int V_292 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 ) {
V_292 = - V_21 ;
goto V_249;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_35 = V_25 -> V_35 ;
F_69 ( & V_2 -> V_290 ) ;
F_70 ( & V_2 -> V_288 ) ;
#ifdef F_51
V_2 -> V_246 = F_52 ( F_71 ( V_25 -> V_35 ) ,
V_293 ) ;
if ( ! V_2 -> V_246 ) {
F_10 ( V_2 , L_55 ) ;
V_292 = - V_21 ;
goto V_294;
}
V_2 -> V_25 -> V_242 = F_52 ( L_56 , V_2 -> V_246 ) ;
if ( ! V_2 -> V_25 -> V_242 ) {
F_10 ( V_2 , L_57 ) ;
V_292 = - V_21 ;
goto V_295;
}
#endif
V_292 = F_9 ( V_2 , true ) ;
if ( V_292 ) {
F_10 ( V_25 , L_58 ) ;
goto V_296;
}
return V_2 ;
V_296:
#ifdef F_51
V_295:
F_53 ( V_2 -> V_246 ) ;
V_294:
#endif
F_4 ( V_2 ) ;
V_249:
return F_72 ( V_292 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( & V_2 -> V_290 ) ;
F_54 ( V_2 ) ;
F_5 ( V_2 ) ;
F_60 ( & V_285 ) ;
if ( ! F_75 ( & V_2 -> V_288 ) )
F_76 ( & V_2 -> V_288 ) ;
F_63 ( & V_285 ) ;
#ifdef F_51
F_53 ( V_2 -> V_246 ) ;
#endif
F_4 ( V_2 ) ;
}
int F_77 ( const char * V_245 , const struct V_239 * V_240 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_237 * V_238 ;
F_60 ( & V_285 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ ) {
V_238 = & V_237 [ V_9 ] ;
if ( strcmp ( V_238 -> V_245 , V_245 ) )
continue;
V_238 -> V_240 = V_240 ;
F_78 (drv, &op->drv, list)
V_2 -> V_243 = F_50 ( V_2 , V_238 ) ;
F_63 ( & V_285 ) ;
return 0 ;
}
F_63 ( & V_285 ) ;
return - V_297 ;
}
void F_79 ( const char * V_245 )
{
int V_9 ;
struct V_1 * V_2 ;
F_60 ( & V_285 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ ) {
if ( strcmp ( V_237 [ V_9 ] . V_245 , V_245 ) )
continue;
V_237 [ V_9 ] . V_240 = NULL ;
F_78 (drv, &iwlwifi_opmode_table[i].drv, list)
F_54 ( V_2 ) ;
F_63 ( & V_285 ) ;
return;
}
F_63 ( & V_285 ) ;
}
static int T_4 F_80 ( void )
{
int V_9 ;
F_81 ( & V_285 ) ;
for ( V_9 = 0 ; V_9 < F_6 ( V_237 ) ; V_9 ++ )
F_70 ( & V_237 [ V_9 ] . V_2 ) ;
F_82 ( V_298 L_59 ) ;
F_82 ( V_299 L_59 ) ;
#ifdef F_51
V_293 = F_52 ( V_300 , NULL ) ;
if ( ! V_293 )
return - V_301 ;
#endif
return F_83 () ;
}
static void T_5 F_84 ( void )
{
F_85 () ;
#ifdef F_51
F_53 ( V_293 ) ;
#endif
}
