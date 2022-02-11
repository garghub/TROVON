static bool F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_1 ,
V_2 -> V_4 ) ;
return false ;
}
return true ;
}
static T_1 F_4 ( T_2 V_6 )
{
T_3 V_7 = 1 ;
int V_8 = V_6 - V_9 ;
if ( V_8 >= V_10 )
return 0xFFFF ;
while ( V_8 < 0 ) {
V_8 += 40 ;
V_7 *= 10 ;
}
return ( V_11 [ V_8 ] + V_7 / 2 ) / V_7 ;
}
static T_2 F_5 ( T_1 V_12 )
{
T_2 V_6 ;
int V_13 ;
T_3 V_14 = V_12 ;
T_3 V_15 ;
if ( V_14 <= 1 )
return 0 ;
V_13 = V_9 ;
while ( V_14 < V_16 ) {
V_14 *= 10 ;
V_13 -= 40 ;
}
for ( V_6 = 0 ; V_6 < V_10 - 1 ; V_6 ++ ) {
V_15 = V_11 [ V_6 ] + ( V_11 [ V_6 + 1 ] -
V_11 [ V_6 ] ) / 2 ;
if ( V_14 < V_15 )
break;
}
V_6 += ( T_2 ) V_13 ;
return V_6 ;
}
T_1 F_6 ( struct V_17 * V_18 )
{
T_1 V_19 ;
V_19 = F_7 ( V_18 -> V_20 ) ;
V_19 &= V_21 ;
if ( V_18 -> V_22 == V_23 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
V_19 |= V_26 ;
V_19 |= V_27 ;
return V_19 ;
}
struct V_28 * F_8 ( void * V_29 , int V_30 , T_3 V_31 )
{
struct V_28 * V_32 ;
int V_33 ;
V_32 = (struct V_28 * ) V_29 ;
V_33 = V_30 ;
while ( V_33 >= V_34 ) {
int V_35 = V_32 -> V_35 ;
if ( ( V_32 -> V_36 == V_31 ) && ( V_33 >= ( V_35 + V_34 ) ) )
return V_32 ;
V_32 = (struct V_28 * ) ( ( T_2 * ) V_32 + ( V_35 + V_34 ) ) ;
V_33 -= ( V_35 + V_34 ) ;
}
return NULL ;
}
static bool
F_9 ( T_2 * V_37 , T_2 * * V_38 , T_4 * V_39 ,
T_2 * V_40 , T_4 V_41 , T_2 type )
{
if ( V_37 [ V_42 ] >= V_41 + 1 &&
! memcmp ( & V_37 [ V_43 ] , V_40 , V_41 ) &&
type == V_37 [ V_43 + V_41 ] ) {
return true ;
}
if ( V_38 == NULL )
return false ;
V_37 += V_37 [ V_42 ] + V_34 ;
* V_39 -= ( int ) ( V_37 - * V_38 ) ;
* V_38 = V_37 ;
return false ;
}
static struct V_44 *
F_10 ( T_2 * V_45 , T_4 V_35 )
{
struct V_28 * V_37 ;
while ( ( V_37 = F_8 ( V_45 , V_35 , V_46 ) ) ) {
if ( F_9 ( ( T_2 * ) V_37 , & V_45 , & V_35 ,
V_47 , V_48 , V_49 ) )
return (struct V_44 * ) V_37 ;
}
return NULL ;
}
static struct V_44 *
F_11 ( T_2 * V_45 , T_4 V_35 )
{
struct V_28 * V_37 ;
while ( ( V_37 = F_8 ( V_45 , V_35 , V_46 ) ) ) {
if ( F_9 ( ( T_2 * ) V_37 , & V_45 , & V_35 ,
V_47 , V_48 , V_50 ) )
return (struct V_44 * ) V_37 ;
}
return NULL ;
}
static void F_12 ( struct V_51 * V_31 ,
struct V_52 * V_53 )
{
V_53 -> V_54 = F_13 ( V_31 -> V_54 ) ;
V_53 -> V_35 = F_13 ( V_31 -> V_35 ) ;
V_53 -> V_55 = F_13 ( V_31 -> V_55 ) ;
V_53 -> V_56 = F_13 ( V_31 -> V_56 ) ;
V_53 -> V_57 . V_58 = F_13 ( V_31 -> V_57 . V_58 ) ;
V_53 -> V_57 . V_59 = F_14 ( V_31 -> V_57 . V_59 ) ;
V_53 -> V_60 = F_13 ( V_31 -> V_60 ) ;
memcpy ( V_53 -> V_61 , V_31 -> V_61 , sizeof( V_31 -> V_61 ) ) ;
memcpy ( V_53 -> V_62 , V_31 -> V_62 , sizeof( V_31 -> V_62 ) ) ;
}
static int
F_15 ( struct V_63 * V_64 , struct V_51 * V_31 )
{
int V_65 ;
struct V_52 V_53 ;
F_12 ( V_31 , & V_53 ) ;
F_16 ( V_64 ) ;
V_65 = F_17 ( F_18 ( V_64 ) , L_2 , & V_53 ,
sizeof( V_53 ) ) ;
if ( V_65 )
F_19 ( L_3 , V_65 ) ;
return V_65 ;
}
static struct V_66 * F_20 ( struct V_67 * V_67 ,
const char * V_68 ,
enum V_69 type ,
T_4 * V_56 ,
struct V_70 * V_71 )
{
F_3 ( V_72 , L_4 , V_68 , type ) ;
switch ( type ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return F_21 ( - V_80 ) ;
case V_81 :
case V_82 :
return F_22 ( V_67 , V_68 , type , V_56 , V_71 ) ;
case V_83 :
case V_84 :
default:
return F_21 ( - V_85 ) ;
}
}
void F_23 ( struct V_63 * V_64 , int V_86 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 = 0 ;
if ( F_1 ( V_88 -> V_2 ) ) {
V_65 = F_24 ( V_88 , L_5 , V_86 ) ;
if ( V_65 ) {
F_19 ( L_6 ) ;
return;
}
F_3 ( V_5 , L_7 , V_86 ) ;
}
}
T_5
F_25 ( struct V_89 * V_90 ,
struct V_63 * V_64 ,
bool V_91 , bool V_92 )
{
struct V_93 V_94 ;
struct V_95 * V_96 ;
T_5 V_65 = 0 ;
F_3 ( V_97 , L_8 ) ;
V_96 = V_90 -> V_96 ;
V_90 -> V_96 = NULL ;
if ( F_26 ( & V_90 -> V_98 ) )
F_27 ( & V_90 -> V_98 ) ;
if ( V_92 ) {
F_3 ( V_97 , L_9 ) ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
memset ( V_94 . V_99 , 0xFF , V_100 ) ;
V_94 . V_101 = V_102 ;
V_94 . V_103 = 0 ;
V_94 . V_104 = F_13 ( 1 ) ;
V_94 . V_105 = F_13 ( 1 ) ;
V_94 . V_106 = F_13 ( - 1 ) ;
V_94 . V_107 = F_13 ( - 1 ) ;
V_94 . V_108 = F_13 ( - 1 ) ;
V_94 . V_109 [ 0 ] = F_14 ( - 1 ) ;
V_65 = F_28 ( F_18 ( V_64 ) , V_110 ,
& V_94 , sizeof( V_94 ) ) ;
if ( V_65 )
F_19 ( L_10 ) ;
}
if ( V_90 -> V_111 ) {
F_3 ( V_97 , L_11 ) ;
V_90 -> V_111 = false ;
if ( ! V_91 )
F_29 ( F_30 ( V_90 ) ) ;
F_23 ( V_64 , 1 ) ;
} else if ( V_96 ) {
F_3 ( V_97 , L_12 ,
V_91 ? L_13 : L_14 ) ;
F_31 ( V_96 , V_91 ) ;
F_23 ( V_64 , 1 ) ;
}
if ( ! F_32 ( V_112 , & V_90 -> V_113 ) )
F_3 ( V_97 , L_15 ) ;
return V_65 ;
}
static
int F_33 ( struct V_67 * V_67 , struct V_66 * V_114 )
{
struct V_89 * V_90 = F_34 ( V_67 ) ;
struct V_63 * V_64 = V_114 -> V_115 ;
if ( F_35 ( V_90 ) )
return - V_116 ;
if ( V_64 ) {
if ( F_2 ( V_112 , & V_90 -> V_113 ) &&
V_90 -> V_117 . V_64 == V_64 )
F_25 ( V_90 , V_64 , true ,
true ) ;
F_24 ( F_18 ( V_64 ) , L_5 , 1 ) ;
}
switch ( V_114 -> V_118 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return - V_80 ;
case V_81 :
case V_82 :
return F_36 ( V_67 , V_114 ) ;
case V_83 :
case V_84 :
default:
return - V_85 ;
}
return - V_80 ;
}
static T_5
F_37 ( struct V_67 * V_67 , struct V_63 * V_64 ,
enum V_69 type , T_4 * V_56 ,
struct V_70 * V_71 )
{
struct V_89 * V_90 = F_34 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
T_5 V_119 = 0 ;
T_5 V_120 = 0 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_16 , V_64 , type ) ;
switch ( type ) {
case V_78 :
case V_77 :
F_19 ( L_17 ,
type ) ;
return - V_80 ;
case V_73 :
V_2 -> V_121 = V_122 ;
V_119 = 0 ;
break;
case V_74 :
if ( ( V_2 -> V_114 . V_118 == V_81 ) ||
( V_2 -> V_114 . V_118 == V_82 ) ) {
F_3 ( V_72 , L_18 ) ;
return 0 ;
}
V_2 -> V_121 = V_123 ;
V_119 = 1 ;
break;
case V_75 :
case V_82 :
V_2 -> V_121 = V_124 ;
V_120 = 1 ;
break;
default:
V_65 = - V_85 ;
goto V_125;
}
if ( V_120 ) {
if ( type == V_82 ) {
F_3 ( V_5 , L_19 ) ;
V_65 = F_38 ( V_90 , V_126 ) ;
}
if ( ! V_65 ) {
F_39 ( V_127 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_20 ) ;
}
} else {
V_65 = F_40 ( V_88 , V_128 , V_119 ) ;
if ( V_65 ) {
F_19 ( L_21 , V_65 ) ;
V_65 = - V_129 ;
goto V_125;
}
F_3 ( V_5 , L_22 , ( V_2 -> V_121 == V_122 ) ?
L_23 : L_24 ) ;
}
V_64 -> V_130 -> V_118 = type ;
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static void F_41 ( struct V_93 * V_94 ,
struct V_95 * V_131 )
{
T_4 V_132 ;
T_4 V_133 ;
T_5 V_134 ;
T_5 V_13 ;
T_1 V_19 ;
char * V_135 ;
struct V_136 V_137 ;
memset ( V_94 -> V_99 , 0xFF , V_100 ) ;
V_94 -> V_101 = V_102 ;
V_94 -> V_103 = 0 ;
V_94 -> V_104 = 0 ;
V_94 -> V_105 = F_13 ( - 1 ) ;
V_94 -> V_106 = F_13 ( - 1 ) ;
V_94 -> V_107 = F_13 ( - 1 ) ;
V_94 -> V_108 = F_13 ( - 1 ) ;
memset ( & V_94 -> V_137 , 0 , sizeof( V_94 -> V_137 ) ) ;
if ( ! V_131 )
return;
V_132 = V_131 -> V_132 ;
V_133 = V_131 -> V_133 ;
F_3 ( V_97 , L_26 ,
V_133 ) ;
if ( V_133 > 0 ) {
for ( V_134 = 0 ; V_134 < V_133 ; V_134 ++ ) {
V_19 = F_6 ( V_131 -> V_138 [ V_134 ] ) ;
F_3 ( V_97 , L_27 ,
V_131 -> V_138 [ V_134 ] -> V_139 , V_19 ) ;
V_94 -> V_109 [ V_134 ] = F_14 ( V_19 ) ;
}
} else {
F_3 ( V_97 , L_28 ) ;
}
F_3 ( V_97 , L_29 , V_132 ) ;
if ( V_132 > 0 ) {
V_13 = F_42 ( struct V_93 , V_109 ) +
V_133 * sizeof( T_1 ) ;
V_13 = F_43 ( V_13 , sizeof( T_4 ) ) ;
V_135 = ( char * ) V_94 + V_13 ;
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_140 =
F_13 ( V_131 -> V_141 [ V_134 ] . V_142 ) ;
memcpy ( V_137 . V_143 , V_131 -> V_141 [ V_134 ] . V_144 ,
V_131 -> V_141 [ V_134 ] . V_142 ) ;
if ( ! V_137 . V_140 )
F_3 ( V_97 , L_30 , V_134 ) ;
else
F_3 ( V_97 , L_31 ,
V_134 , V_137 . V_143 , V_137 . V_140 ) ;
memcpy ( V_135 , & V_137 , sizeof( V_137 ) ) ;
V_135 += sizeof( V_137 ) ;
}
} else {
F_3 ( V_97 , L_32 , V_131 -> V_141 ) ;
if ( ( V_131 -> V_141 ) && V_131 -> V_141 -> V_142 ) {
F_3 ( V_97 , L_33 ,
V_94 -> V_137 . V_143 ,
V_131 -> V_141 -> V_142 ) ;
V_94 -> V_137 . V_140 =
F_13 ( V_131 -> V_141 -> V_142 ) ;
memcpy ( & V_94 -> V_137 . V_143 , V_131 -> V_141 -> V_144 ,
V_131 -> V_141 -> V_142 ) ;
}
}
V_94 -> V_104 =
F_13 ( ( V_132 << V_145 ) |
( V_133 & V_146 ) ) ;
}
static T_5
F_44 ( struct V_89 * V_90 , struct V_63 * V_64 ,
struct V_95 * V_131 , T_1 V_147 )
{
T_5 V_148 = V_149 +
F_42 ( struct V_150 , V_94 ) ;
struct V_150 * V_71 ;
T_5 V_65 = 0 ;
F_3 ( V_97 , L_34 ) ;
if ( V_131 != NULL ) {
V_148 += sizeof( T_4 ) * ( ( V_131 -> V_133 + 1 ) / 2 ) ;
V_148 += sizeof( struct V_151 ) * V_131 -> V_132 ;
}
V_71 = F_45 ( V_148 , V_152 ) ;
if ( ! V_71 ) {
V_65 = - V_153 ;
goto exit;
}
F_46 ( V_148 + sizeof( L_35 ) >= V_154 ) ;
F_41 ( & V_71 -> V_94 , V_131 ) ;
V_71 -> V_155 = F_13 ( V_156 ) ;
V_71 -> V_147 = F_14 ( V_147 ) ;
V_71 -> V_157 = F_14 ( 0x1234 ) ;
V_65 = F_47 ( F_18 ( V_64 ) , L_35 ,
V_71 , V_148 ) ;
if ( V_65 ) {
if ( V_65 == - V_116 )
F_3 ( V_5 , L_36 ) ;
else
F_19 ( L_37 , V_65 ) ;
}
F_48 ( V_71 ) ;
exit:
return V_65 ;
}
static T_5
F_49 ( struct V_89 * V_90 , struct V_67 * V_67 ,
struct V_63 * V_64 , struct V_95 * V_131 )
{
T_5 V_65 ;
T_4 V_158 ;
struct V_159 * V_160 ;
struct V_117 * V_161 = & V_90 -> V_117 ;
F_3 ( V_97 , L_8 ) ;
V_161 -> V_64 = V_64 ;
V_161 -> V_67 = V_67 ;
V_161 -> V_162 = V_163 ;
V_158 = V_90 -> V_164 ? 0 : 1 ;
V_65 = F_40 ( F_18 ( V_64 ) , V_165 ,
V_158 ) ;
if ( V_65 ) {
F_19 ( L_37 , V_65 ) ;
return V_65 ;
}
F_23 ( V_64 , 0 ) ;
V_160 = (struct V_159 * ) V_90 -> V_117 . V_166 ;
V_160 -> V_155 = 0 ;
V_160 -> V_167 = 0 ;
V_160 -> V_30 = V_168 ;
V_65 = V_161 -> V_169 ( V_90 , V_64 , V_131 , V_170 ) ;
if ( V_65 )
F_23 ( V_64 , 1 ) ;
return V_65 ;
}
static T_5
F_50 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_95 * V_131 ,
struct V_171 * V_172 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_89 * V_90 = F_51 ( V_64 ) ;
struct V_171 * V_141 ;
struct V_173 * V_174 = & V_90 -> V_175 ;
T_4 V_158 ;
bool V_176 ;
bool V_177 ;
T_5 V_65 ;
T_4 V_140 ;
F_3 ( V_97 , L_38 ) ;
if ( F_2 ( V_112 , & V_90 -> V_113 ) ) {
F_19 ( L_39 , V_90 -> V_113 ) ;
return - V_129 ;
}
if ( F_2 ( V_178 , & V_90 -> V_113 ) ) {
F_19 ( L_40 ,
V_90 -> V_113 ) ;
return - V_129 ;
}
if ( F_2 ( V_179 , & V_88 -> V_2 -> V_4 ) ) {
F_19 ( L_41 , V_88 -> V_2 -> V_4 ) ;
return - V_129 ;
}
if ( V_88 -> V_2 == V_90 -> V_180 . V_181 [ V_182 ] . V_2 ) {
V_88 = V_90 -> V_180 . V_181 [ V_183 ] . V_2 -> V_88 ;
V_64 = V_88 -> V_64 ;
}
F_52 ( & V_90 -> V_98 , V_184 +
V_185 * V_186 / 1000 ) ;
V_176 = false ;
if ( V_131 ) {
V_141 = V_131 -> V_141 ;
V_176 = true ;
} else {
V_141 = V_172 ;
}
V_90 -> V_96 = V_131 ;
F_39 ( V_112 , & V_90 -> V_113 ) ;
if ( V_176 ) {
V_90 -> V_117 . V_169 = F_44 ;
V_65 = F_53 ( V_67 , V_131 , V_88 -> V_2 ) ;
if ( V_65 )
goto V_187;
V_65 = F_49 ( V_90 , V_67 , V_64 , V_131 ) ;
if ( V_65 )
goto V_187;
} else {
F_3 ( V_97 , L_42 ,
V_141 -> V_144 , V_141 -> V_142 ) ;
memset ( & V_174 -> V_137 , 0 , sizeof( V_174 -> V_137 ) ) ;
V_140 = F_54 ( T_2 , sizeof( V_174 -> V_137 . V_143 ) , V_141 -> V_142 ) ;
V_174 -> V_137 . V_140 = F_13 ( 0 ) ;
V_177 = false ;
if ( V_140 ) {
memcpy ( V_174 -> V_137 . V_143 , V_141 -> V_144 , V_140 ) ;
V_174 -> V_137 . V_140 = F_13 ( V_140 ) ;
V_177 = true ;
} else
F_3 ( V_97 , L_43 ) ;
V_158 = V_90 -> V_164 ? 0 : 1 ;
V_65 = F_40 ( V_88 , V_165 ,
V_158 ) ;
if ( V_65 ) {
F_19 ( L_44 , V_65 ) ;
goto V_187;
}
F_23 ( V_64 , 0 ) ;
V_65 = F_28 ( V_88 , V_110 ,
& V_174 -> V_137 , sizeof( V_174 -> V_137 ) ) ;
if ( V_65 ) {
if ( V_65 == - V_116 )
F_3 ( V_5 , L_45 ,
V_174 -> V_137 . V_143 ) ;
else
F_19 ( L_46 , V_65 ) ;
F_23 ( V_64 , 1 ) ;
goto V_187;
}
}
return 0 ;
V_187:
F_55 ( V_112 , & V_90 -> V_113 ) ;
if ( F_26 ( & V_90 -> V_98 ) )
F_27 ( & V_90 -> V_98 ) ;
V_90 -> V_96 = NULL ;
return V_65 ;
}
static T_5
F_56 ( struct V_67 * V_67 , struct V_95 * V_131 )
{
struct V_63 * V_64 = V_131 -> V_114 -> V_115 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( F_57 ( V_131 -> V_114 ,
struct V_1 , V_114 ) ) )
return - V_188 ;
V_65 = F_50 ( V_67 , V_64 , V_131 , NULL ) ;
if ( V_65 )
F_19 ( L_47 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5 F_58 ( struct V_63 * V_64 , T_4 V_189 )
{
T_5 V_65 = 0 ;
V_65 = F_24 ( F_18 ( V_64 ) , L_48 ,
V_189 ) ;
if ( V_65 )
F_19 ( L_49 , V_65 ) ;
return V_65 ;
}
static T_5 F_59 ( struct V_63 * V_64 , T_4 V_190 )
{
T_5 V_65 = 0 ;
V_65 = F_24 ( F_18 ( V_64 ) , L_50 ,
V_190 ) ;
if ( V_65 )
F_19 ( L_49 , V_65 ) ;
return V_65 ;
}
static T_5 F_60 ( struct V_63 * V_64 , T_4 V_191 , bool V_192 )
{
T_5 V_65 = 0 ;
T_4 V_193 = ( V_192 ? V_194 : V_195 ) ;
V_65 = F_40 ( F_18 ( V_64 ) , V_193 , V_191 ) ;
if ( V_65 ) {
F_19 ( L_51 , V_193 , V_65 ) ;
return V_65 ;
}
return V_65 ;
}
static T_5 F_61 ( struct V_67 * V_67 , T_4 V_196 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_63 * V_64 = F_63 ( V_90 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( V_196 & V_197 &&
( V_90 -> V_198 -> V_189 != V_67 -> V_189 ) ) {
V_90 -> V_198 -> V_189 = V_67 -> V_189 ;
V_65 = F_58 ( V_64 , V_90 -> V_198 -> V_189 ) ;
if ( ! V_65 )
goto V_125;
}
if ( V_196 & V_199 &&
( V_90 -> V_198 -> V_190 != V_67 -> V_190 ) ) {
V_90 -> V_198 -> V_190 = V_67 -> V_190 ;
V_65 = F_59 ( V_64 , V_90 -> V_198 -> V_190 ) ;
if ( ! V_65 )
goto V_125;
}
if ( V_196 & V_200
&& ( V_90 -> V_198 -> V_201 != V_67 -> V_201 ) ) {
V_90 -> V_198 -> V_201 = V_67 -> V_201 ;
V_65 = F_60 ( V_64 , V_90 -> V_198 -> V_201 , true ) ;
if ( ! V_65 )
goto V_125;
}
if ( V_196 & V_202
&& ( V_90 -> V_198 -> V_203 != V_67 -> V_203 ) ) {
V_90 -> V_198 -> V_203 = V_67 -> V_203 ;
V_65 = F_60 ( V_64 , V_90 -> V_198 -> V_203 , false ) ;
if ( ! V_65 )
goto V_125;
}
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static void F_64 ( struct V_204 * V_205 )
{
memset ( V_205 , 0 , sizeof( * V_205 ) ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( F_2 ( V_206 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_52 ) ;
V_65 = F_28 ( V_2 -> V_88 ,
V_207 , NULL , 0 ) ;
if ( V_65 )
F_19 ( L_53 , V_65 ) ;
F_55 ( V_206 , & V_2 -> V_4 ) ;
}
F_55 ( V_179 , & V_2 -> V_4 ) ;
F_3 ( V_72 , L_25 ) ;
}
static T_5
F_66 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_208 * V_71 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_210 V_211 ;
T_6 V_212 = 0 ;
T_5 V_65 = 0 ;
T_5 V_213 = 0 ;
T_5 V_214 ;
T_1 V_19 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( V_71 -> V_144 )
F_3 ( V_215 , L_54 , V_71 -> V_144 ) ;
else {
F_3 ( V_215 , L_55 ) ;
return - V_80 ;
}
F_39 ( V_179 , & V_88 -> V_2 -> V_4 ) ;
if ( V_71 -> V_99 )
F_3 ( V_215 , L_56 , V_71 -> V_99 ) ;
else
F_3 ( V_215 , L_57 ) ;
if ( V_71 -> V_216 . V_217 )
F_3 ( V_215 , L_58 ,
V_71 -> V_216 . V_217 -> V_20 ) ;
else
F_3 ( V_215 , L_59 ) ;
if ( V_71 -> V_218 )
F_3 ( V_215 , L_60 ) ;
else
F_3 ( V_215 , L_61 ) ;
if ( V_71 -> V_37 && V_71 -> V_219 )
F_3 ( V_215 , L_62 , V_71 -> V_219 ) ;
else
F_3 ( V_215 , L_63 ) ;
if ( V_71 -> V_220 )
F_3 ( V_215 , L_64 ,
V_71 -> V_220 ) ;
else
F_3 ( V_215 , L_65 ) ;
if ( V_71 -> V_221 )
F_3 ( V_215 , L_66 , V_71 -> V_221 ) ;
else
F_3 ( V_215 , L_67 ) ;
if ( V_71 -> V_222 )
F_3 ( V_215 , L_68 ) ;
else
F_3 ( V_215 , L_69 ) ;
if ( V_71 -> V_222 )
V_213 |= V_223 ;
V_65 = F_24 ( V_88 , L_70 , V_213 ) ;
if ( V_65 ) {
F_19 ( L_71 , V_65 ) ;
goto V_125;
}
if ( V_71 -> V_220 )
V_214 = V_71 -> V_220 ;
else
V_214 = 100 ;
V_65 = F_40 ( V_88 , V_224 , V_214 ) ;
if ( V_65 ) {
F_19 ( L_72 , V_65 ) ;
goto V_125;
}
memset ( & V_211 , 0 , sizeof( struct V_210 ) ) ;
V_209 -> V_144 . V_140 = F_54 ( T_4 , V_71 -> V_142 , 32 ) ;
memcpy ( V_209 -> V_144 . V_143 , V_71 -> V_144 , V_209 -> V_144 . V_140 ) ;
memcpy ( V_211 . V_137 . V_143 , V_71 -> V_144 , V_209 -> V_144 . V_140 ) ;
V_211 . V_137 . V_140 = F_13 ( V_209 -> V_144 . V_140 ) ;
V_212 = sizeof( V_211 . V_137 ) ;
if ( V_71 -> V_99 ) {
memcpy ( V_211 . V_94 . V_99 , V_71 -> V_99 , V_100 ) ;
V_212 = sizeof( V_211 . V_137 ) +
V_225 ;
memcpy ( V_209 -> V_99 , V_71 -> V_99 , V_100 ) ;
} else {
memset ( V_211 . V_94 . V_99 , 0xFF , V_100 ) ;
memset ( V_209 -> V_99 , 0 , V_100 ) ;
}
if ( V_71 -> V_216 . V_217 ) {
T_4 V_226 ;
V_90 -> V_227 =
F_7 (
V_71 -> V_216 . V_217 -> V_20 ) ;
if ( V_71 -> V_218 ) {
V_19 = F_6 ( V_71 -> V_216 . V_217 ) ;
V_211 . V_94 . V_228 [ 0 ] =
F_14 ( V_19 ) ;
V_211 . V_94 . V_229 = F_13 ( 1 ) ;
V_212 += sizeof( V_211 . V_94 ) ;
}
V_226 = V_90 -> V_227 ;
V_65 = F_40 ( V_88 , V_230 ,
V_226 ) ;
if ( V_65 ) {
F_19 ( L_73 , V_65 ) ;
goto V_125;
}
} else
V_90 -> V_227 = 0 ;
V_90 -> V_231 = false ;
V_65 = F_28 ( V_88 , V_232 ,
& V_211 , V_212 ) ;
if ( V_65 ) {
F_19 ( L_74 , V_65 ) ;
goto V_125;
}
V_125:
if ( V_65 )
F_55 ( V_179 , & V_88 -> V_2 -> V_4 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_67 ( struct V_67 * V_67 , struct V_63 * V_64 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
F_65 ( V_88 -> V_2 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5 F_68 ( struct V_63 * V_64 ,
struct V_233 * V_234 )
{
struct V_204 * V_209 = F_69 ( V_64 ) ;
struct V_235 * V_236 ;
T_5 V_237 = 0 ;
T_5 V_65 = 0 ;
if ( V_234 -> V_238 . V_239 & V_240 )
V_237 = V_241 | V_242 ;
else if ( V_234 -> V_238 . V_239 & V_243 )
V_237 = V_244 | V_245 ;
else
V_237 = V_246 ;
F_3 ( V_215 , L_75 , V_237 ) ;
V_65 = F_70 ( F_18 ( V_64 ) , L_76 , V_237 ) ;
if ( V_65 ) {
F_19 ( L_77 , V_65 ) ;
return V_65 ;
}
V_236 = & V_209 -> V_236 ;
V_236 -> V_239 = V_234 -> V_238 . V_239 ;
return V_65 ;
}
static T_5 F_71 ( struct V_63 * V_64 ,
struct V_233 * V_234 )
{
struct V_204 * V_209 = F_69 ( V_64 ) ;
struct V_235 * V_236 ;
T_5 V_237 = 0 ;
T_5 V_65 = 0 ;
switch ( V_234 -> V_247 ) {
case V_248 :
V_237 = 0 ;
F_3 ( V_215 , L_78 ) ;
break;
case V_249 :
V_237 = 1 ;
F_3 ( V_215 , L_79 ) ;
break;
case V_250 :
V_237 = 2 ;
F_3 ( V_215 , L_80 ) ;
break;
case V_251 :
F_3 ( V_215 , L_81 ) ;
default:
V_237 = 2 ;
F_19 ( L_82 , V_234 -> V_247 ) ;
break;
}
V_65 = F_70 ( F_18 ( V_64 ) , L_83 , V_237 ) ;
if ( V_65 ) {
F_19 ( L_84 , V_65 ) ;
return V_65 ;
}
V_236 = & V_209 -> V_236 ;
V_236 -> V_247 = V_234 -> V_247 ;
return V_65 ;
}
static T_5
F_72 ( struct V_63 * V_64 ,
struct V_233 * V_234 )
{
struct V_204 * V_209 = F_69 ( V_64 ) ;
struct V_235 * V_236 ;
T_5 V_252 = 0 ;
T_5 V_253 = 0 ;
T_5 V_65 = 0 ;
if ( V_234 -> V_238 . V_254 ) {
switch ( V_234 -> V_238 . V_255 [ 0 ] ) {
case V_256 :
case V_257 :
V_252 = V_223 ;
break;
case V_258 :
V_252 = V_259 ;
break;
case V_260 :
V_252 = V_261 ;
break;
case V_262 :
V_252 = V_261 ;
break;
default:
F_19 ( L_85 ,
V_234 -> V_238 . V_255 [ 0 ] ) ;
return - V_85 ;
}
}
if ( V_234 -> V_238 . V_263 ) {
switch ( V_234 -> V_238 . V_263 ) {
case V_256 :
case V_257 :
V_253 = V_223 ;
break;
case V_258 :
V_253 = V_259 ;
break;
case V_260 :
V_253 = V_261 ;
break;
case V_262 :
V_253 = V_261 ;
break;
default:
F_19 ( L_86 ,
V_234 -> V_238 . V_263 ) ;
return - V_85 ;
}
}
F_3 ( V_215 , L_87 , V_252 , V_253 ) ;
if ( F_11 ( V_234 -> V_37 , V_234 -> V_219 ) && ! V_252 && ! V_253 &&
V_234 -> V_222 )
V_252 = V_261 ;
V_65 = F_70 ( F_18 ( V_64 ) , L_70 , V_252 | V_253 ) ;
if ( V_65 ) {
F_19 ( L_37 , V_65 ) ;
return V_65 ;
}
V_236 = & V_209 -> V_236 ;
V_236 -> V_264 = V_234 -> V_238 . V_255 [ 0 ] ;
V_236 -> V_263 = V_234 -> V_238 . V_263 ;
return V_65 ;
}
static T_5
F_73 ( struct V_63 * V_64 , struct V_233 * V_234 )
{
struct V_204 * V_209 = F_69 ( V_64 ) ;
struct V_235 * V_236 ;
T_5 V_237 = 0 ;
T_5 V_65 = 0 ;
if ( V_234 -> V_238 . V_265 ) {
V_65 = F_74 ( F_18 ( V_64 ) ,
L_76 , & V_237 ) ;
if ( V_65 ) {
F_19 ( L_88 , V_65 ) ;
return V_65 ;
}
if ( V_237 & ( V_241 | V_242 ) ) {
switch ( V_234 -> V_238 . V_266 [ 0 ] ) {
case V_267 :
V_237 = V_242 ;
break;
case V_268 :
V_237 = V_241 ;
break;
default:
F_19 ( L_86 ,
V_234 -> V_238 . V_263 ) ;
return - V_85 ;
}
} else if ( V_237 & ( V_244 | V_245 ) ) {
switch ( V_234 -> V_238 . V_266 [ 0 ] ) {
case V_267 :
V_237 = V_245 ;
break;
case V_268 :
V_237 = V_244 ;
break;
default:
F_19 ( L_86 ,
V_234 -> V_238 . V_263 ) ;
return - V_85 ;
}
}
F_3 ( V_215 , L_89 , V_237 ) ;
V_65 = F_70 ( F_18 ( V_64 ) ,
L_76 , V_237 ) ;
if ( V_65 ) {
F_19 ( L_90 , V_65 ) ;
return V_65 ;
}
}
V_236 = & V_209 -> V_236 ;
V_236 -> V_269 = V_234 -> V_238 . V_266 [ 0 ] ;
return V_65 ;
}
static T_5
F_75 ( struct V_63 * V_64 ,
struct V_233 * V_234 )
{
struct V_204 * V_209 = F_69 ( V_64 ) ;
struct V_235 * V_236 ;
struct V_51 V_31 ;
T_5 V_237 ;
T_5 V_65 = 0 ;
F_3 ( V_215 , L_91 , V_234 -> V_270 ) ;
if ( V_234 -> V_270 == 0 )
return 0 ;
V_236 = & V_209 -> V_236 ;
F_3 ( V_215 , L_92 ,
V_236 -> V_239 , V_236 -> V_264 ) ;
if ( V_236 -> V_239 & ( V_240 | V_243 ) )
return 0 ;
if ( ! ( V_236 -> V_264 &
( V_256 | V_257 ) ) )
return 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_234 -> V_270 ;
V_31 . V_54 = ( T_4 ) V_234 -> V_271 ;
if ( V_31 . V_35 > sizeof( V_31 . V_61 ) ) {
F_19 ( L_93 , V_31 . V_35 ) ;
return - V_85 ;
}
memcpy ( V_31 . V_61 , V_234 -> V_31 , V_31 . V_35 ) ;
V_31 . V_56 = V_272 ;
switch ( V_236 -> V_264 ) {
case V_256 :
V_31 . V_55 = V_273 ;
break;
case V_257 :
V_31 . V_55 = V_274 ;
break;
default:
F_19 ( L_94 ,
V_234 -> V_238 . V_255 [ 0 ] ) ;
return - V_85 ;
}
F_3 ( V_215 , L_95 ,
V_31 . V_35 , V_31 . V_54 , V_31 . V_55 ) ;
F_3 ( V_215 , L_96 , V_31 . V_61 ) ;
V_65 = F_15 ( V_64 , & V_31 ) ;
if ( V_65 )
return V_65 ;
if ( V_236 -> V_247 == V_249 ) {
F_3 ( V_215 , L_97 ) ;
V_237 = V_275 ;
V_65 = F_70 ( F_18 ( V_64 ) , L_83 , V_237 ) ;
if ( V_65 )
F_19 ( L_84 , V_65 ) ;
}
return V_65 ;
}
static
enum V_276 F_76 ( struct V_87 * V_88 ,
enum V_276 type )
{
T_4 V_277 ;
if ( type == V_250 ) {
V_277 = F_77 ( V_88 ) >> 4 ;
switch ( V_277 ) {
case 43236 :
F_3 ( V_215 , L_98 ) ;
return V_248 ;
default:
break;
}
}
return type ;
}
static T_5
F_78 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_233 * V_234 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_17 * V_217 = V_234 -> V_227 ;
struct V_210 V_211 ;
T_6 V_212 ;
struct V_28 * V_278 ;
struct V_44 * V_279 ;
void * V_37 ;
T_4 V_219 ;
struct V_280 * V_281 ;
T_1 V_19 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( ! V_234 -> V_144 ) {
F_19 ( L_99 ) ;
return - V_80 ;
}
if ( V_88 -> V_2 == V_90 -> V_180 . V_181 [ V_183 ] . V_2 ) {
V_37 = NULL ;
V_219 = 0 ;
V_279 = F_10 ( ( T_2 * ) V_234 -> V_37 , V_234 -> V_219 ) ;
if ( V_279 ) {
V_37 = V_279 ;
V_219 = V_279 -> V_35 + V_34 ;
} else {
V_278 = F_8 ( ( T_2 * ) V_234 -> V_37 , V_234 -> V_219 ,
V_282 ) ;
if ( V_278 ) {
V_37 = V_278 ;
V_219 = V_278 -> V_35 + V_34 ;
}
}
F_47 ( V_88 , L_100 , V_37 , V_219 ) ;
}
V_65 = F_79 ( V_88 -> V_2 , V_283 ,
V_234 -> V_37 , V_234 -> V_219 ) ;
if ( V_65 )
F_19 ( L_101 ) ;
else
F_3 ( V_72 , L_102 ) ;
F_39 ( V_179 , & V_88 -> V_2 -> V_4 ) ;
if ( V_217 ) {
V_90 -> V_227 =
F_7 ( V_217 -> V_20 ) ;
V_19 = F_6 ( V_217 ) ;
F_3 ( V_215 , L_103 ,
V_90 -> V_227 , V_217 -> V_20 , V_19 ) ;
} else {
V_90 -> V_227 = 0 ;
V_19 = 0 ;
}
F_3 ( V_5 , L_104 , V_234 -> V_37 , V_234 -> V_219 ) ;
V_65 = F_68 ( V_64 , V_234 ) ;
if ( V_65 ) {
F_19 ( L_105 , V_65 ) ;
goto V_125;
}
V_234 -> V_247 = F_76 ( V_88 , V_234 -> V_247 ) ;
V_65 = F_71 ( V_64 , V_234 ) ;
if ( V_65 ) {
F_19 ( L_106 , V_65 ) ;
goto V_125;
}
V_65 = F_72 ( V_64 , V_234 ) ;
if ( V_65 ) {
F_19 ( L_107 , V_65 ) ;
goto V_125;
}
V_65 = F_73 ( V_64 , V_234 ) ;
if ( V_65 ) {
F_19 ( L_108 , V_65 ) ;
goto V_125;
}
V_65 = F_75 ( V_64 , V_234 ) ;
if ( V_65 ) {
F_19 ( L_109 , V_65 ) ;
goto V_125;
}
V_209 -> V_144 . V_140 = F_54 ( T_4 , ( T_4 ) sizeof( V_209 -> V_144 . V_143 ) ,
( T_4 ) V_234 -> V_142 ) ;
memcpy ( & V_209 -> V_144 . V_143 , V_234 -> V_144 , V_209 -> V_144 . V_140 ) ;
if ( V_209 -> V_144 . V_140 < V_284 ) {
V_209 -> V_144 . V_143 [ V_209 -> V_144 . V_140 ] = 0 ;
F_3 ( V_215 , L_110 , V_209 -> V_144 . V_143 ,
V_209 -> V_144 . V_140 ) ;
}
V_212 = F_42 ( struct V_280 , V_285 ) +
F_42 ( struct V_286 , V_228 ) ;
if ( V_90 -> V_227 )
V_212 += sizeof( T_1 ) ;
V_281 = F_45 ( V_212 , V_152 ) ;
if ( V_281 == NULL ) {
V_65 = - V_153 ;
goto V_125;
}
V_281 -> V_137 . V_140 = F_13 ( V_209 -> V_144 . V_140 ) ;
memcpy ( & V_281 -> V_137 . V_143 , V_234 -> V_144 ,
V_209 -> V_144 . V_140 ) ;
V_281 -> V_287 . V_106 =
F_13 ( V_288 ) ;
V_281 -> V_287 . V_107 =
F_13 ( V_289 ) ;
V_281 -> V_287 . V_103 = - 1 ;
V_281 -> V_287 . V_105 =
F_13 ( V_288 /
V_290 ) ;
V_281 -> V_287 . V_108 = F_13 ( - 1 ) ;
if ( V_234 -> V_99 )
memcpy ( & V_281 -> V_285 . V_99 , V_234 -> V_99 , V_100 ) ;
else
memset ( & V_281 -> V_285 . V_99 , 0xFF , V_100 ) ;
if ( V_90 -> V_227 ) {
V_281 -> V_285 . V_229 = F_13 ( 1 ) ;
V_281 -> V_285 . V_228 [ 0 ] =
F_14 ( V_19 ) ;
}
V_65 = F_17 ( V_88 , L_111 , V_281 ,
V_212 ) ;
F_48 ( V_281 ) ;
if ( ! V_65 )
goto V_125;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_212 = sizeof( V_211 . V_137 ) ;
memcpy ( & V_211 . V_137 . V_143 , V_234 -> V_144 , V_209 -> V_144 . V_140 ) ;
V_211 . V_137 . V_140 = F_13 ( V_209 -> V_144 . V_140 ) ;
if ( V_234 -> V_99 )
memcpy ( V_211 . V_94 . V_99 , V_234 -> V_99 , V_100 ) ;
else
memset ( V_211 . V_94 . V_99 , 0xFF , V_100 ) ;
if ( V_90 -> V_227 ) {
V_211 . V_94 . V_228 [ 0 ] = F_14 ( V_19 ) ;
V_211 . V_94 . V_229 = F_13 ( 1 ) ;
V_212 += sizeof( V_211 . V_94 ) ;
}
V_65 = F_28 ( V_88 , V_232 ,
& V_211 , V_212 ) ;
if ( V_65 )
F_19 ( L_112 , V_65 ) ;
V_125:
if ( V_65 )
F_55 ( V_179 , & V_88 -> V_2 -> V_4 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_80 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_1 V_291 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_292 V_293 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_113 , V_291 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
F_55 ( V_206 , & V_88 -> V_2 -> V_4 ) ;
memcpy ( & V_293 . V_62 , & V_209 -> V_99 , V_100 ) ;
V_293 . V_237 = F_13 ( V_291 ) ;
V_65 = F_28 ( V_88 , V_207 ,
& V_293 , sizeof( V_293 ) ) ;
if ( V_65 )
F_19 ( L_37 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_81 ( struct V_67 * V_67 , struct V_66 * V_114 ,
enum V_294 type , T_5 V_295 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_63 * V_64 = F_63 ( V_90 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_1 V_296 ;
T_5 V_65 = 0 ;
T_5 V_297 = 0 ;
T_5 V_298 = F_82 ( V_295 ) ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
switch ( type ) {
case V_299 :
break;
case V_300 :
case V_301 :
if ( V_298 < 0 ) {
F_19 ( L_114 ) ;
V_65 = - V_85 ;
goto V_125;
}
break;
}
V_297 = V_302 << 16 ;
V_65 = F_40 ( V_88 , V_303 , V_297 ) ;
if ( V_65 )
F_19 ( L_115 , V_65 ) ;
if ( V_298 > 0xffff )
V_296 = 0xffff ;
else
V_296 = ( T_1 ) V_298 ;
V_65 = F_24 ( V_88 , L_116 ,
( T_5 ) F_5 ( V_296 ) ) ;
if ( V_65 )
F_19 ( L_117 , V_65 ) ;
V_90 -> V_198 -> V_304 = V_298 ;
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5 F_83 ( struct V_67 * V_67 ,
struct V_66 * V_114 ,
T_5 * V_298 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( F_63 ( V_90 ) ) ;
T_5 V_305 ;
T_2 V_306 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
V_65 = F_84 ( V_88 , L_116 , & V_305 ) ;
if ( V_65 ) {
F_19 ( L_37 , V_65 ) ;
goto V_125;
}
V_306 = ( T_2 ) ( V_305 & ~ V_307 ) ;
* V_298 = ( T_5 ) F_4 ( V_306 ) ;
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_85 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 V_271 , bool V_308 , bool V_309 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_4 V_54 ;
T_4 V_213 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
F_3 ( V_215 , L_118 , V_271 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
V_65 = F_74 ( V_88 , L_70 , & V_213 ) ;
if ( V_65 ) {
F_19 ( L_119 , V_65 ) ;
goto V_125;
}
if ( V_213 & V_223 ) {
V_54 = V_271 ;
V_65 = F_40 ( V_88 ,
V_310 , V_54 ) ;
if ( V_65 )
F_19 ( L_37 , V_65 ) ;
}
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_86 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 V_271 , const T_2 * V_311 , struct V_312 * V_71 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_51 V_31 ;
T_5 V_65 = 0 ;
T_2 V_313 [ 8 ] ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_54 = ( T_4 ) V_271 ;
if ( ! F_87 ( V_311 ) )
memcpy ( ( char * ) & V_31 . V_62 , ( void * ) V_311 , V_100 ) ;
V_31 . V_35 = ( T_4 ) V_71 -> V_270 ;
if ( V_31 . V_35 == 0 ) {
V_65 = F_15 ( V_64 , & V_31 ) ;
if ( V_65 )
F_19 ( L_120 , V_65 ) ;
} else {
if ( V_31 . V_35 > sizeof( V_31 . V_61 ) ) {
F_19 ( L_121 , V_31 . V_35 ) ;
return - V_85 ;
}
F_3 ( V_215 , L_122 , V_31 . V_54 ) ;
memcpy ( V_31 . V_61 , V_71 -> V_31 , V_31 . V_35 ) ;
if ( ( V_88 -> V_2 -> V_121 != V_124 ) &&
( V_71 -> V_314 == V_258 ) ) {
F_3 ( V_215 , L_123 ) ;
memcpy ( V_313 , & V_31 . V_61 [ 24 ] , sizeof( V_313 ) ) ;
memcpy ( & V_31 . V_61 [ 24 ] , & V_31 . V_61 [ 16 ] , sizeof( V_313 ) ) ;
memcpy ( & V_31 . V_61 [ 16 ] , V_313 , sizeof( V_313 ) ) ;
}
if ( V_71 -> V_315 && V_71 -> V_316 == 6 ) {
T_2 * V_317 ;
V_317 = ( T_2 * ) V_71 -> V_315 ;
V_31 . V_57 . V_58 = ( V_317 [ 5 ] << 24 ) | ( V_317 [ 4 ] << 16 ) |
( V_317 [ 3 ] << 8 ) | V_317 [ 2 ] ;
V_31 . V_57 . V_59 = ( V_317 [ 1 ] << 8 ) | V_317 [ 0 ] ;
V_31 . V_60 = true ;
}
switch ( V_71 -> V_314 ) {
case V_256 :
V_31 . V_55 = V_273 ;
F_3 ( V_215 , L_124 ) ;
break;
case V_257 :
V_31 . V_55 = V_274 ;
F_3 ( V_215 , L_125 ) ;
break;
case V_258 :
V_31 . V_55 = V_318 ;
F_3 ( V_215 , L_126 ) ;
break;
case V_262 :
V_31 . V_55 = V_319 ;
F_3 ( V_215 , L_127 ) ;
break;
case V_260 :
V_31 . V_55 = V_319 ;
F_3 ( V_215 , L_128 ) ;
break;
default:
F_19 ( L_129 , V_71 -> V_314 ) ;
return - V_85 ;
}
V_65 = F_15 ( V_64 , & V_31 ) ;
if ( V_65 )
F_19 ( L_3 , V_65 ) ;
}
return V_65 ;
}
static T_5
F_88 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 V_271 , bool V_320 , const T_2 * V_311 ,
struct V_312 * V_71 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_51 V_31 ;
T_5 V_237 ;
T_5 V_213 ;
T_5 V_65 = 0 ;
T_2 V_313 [ 8 ] ;
F_3 ( V_72 , L_8 ) ;
F_3 ( V_215 , L_118 , V_271 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( V_311 ) {
F_3 ( V_72 , L_130 ) ;
return F_86 ( V_67 , V_64 , V_271 , V_311 , V_71 ) ;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_71 -> V_270 ;
V_31 . V_54 = ( T_4 ) V_271 ;
if ( V_31 . V_35 > sizeof( V_31 . V_61 ) ) {
F_19 ( L_93 , V_31 . V_35 ) ;
V_65 = - V_85 ;
goto V_125;
}
memcpy ( V_31 . V_61 , V_71 -> V_31 , V_31 . V_35 ) ;
V_31 . V_56 = V_272 ;
switch ( V_71 -> V_314 ) {
case V_256 :
V_31 . V_55 = V_273 ;
V_237 = V_223 ;
F_3 ( V_215 , L_124 ) ;
break;
case V_257 :
V_31 . V_55 = V_274 ;
V_237 = V_223 ;
F_3 ( V_215 , L_125 ) ;
break;
case V_258 :
if ( V_88 -> V_2 -> V_121 != V_124 ) {
F_3 ( V_215 , L_123 ) ;
memcpy ( V_313 , & V_31 . V_61 [ 24 ] , sizeof( V_313 ) ) ;
memcpy ( & V_31 . V_61 [ 24 ] , & V_31 . V_61 [ 16 ] , sizeof( V_313 ) ) ;
memcpy ( & V_31 . V_61 [ 16 ] , V_313 , sizeof( V_313 ) ) ;
}
V_31 . V_55 = V_318 ;
V_237 = V_259 ;
F_3 ( V_215 , L_126 ) ;
break;
case V_262 :
V_31 . V_55 = V_319 ;
V_237 = V_261 ;
F_3 ( V_215 , L_127 ) ;
break;
case V_260 :
V_31 . V_55 = V_319 ;
V_237 = V_261 ;
F_3 ( V_215 , L_128 ) ;
break;
default:
F_19 ( L_129 , V_71 -> V_314 ) ;
V_65 = - V_85 ;
goto V_125;
}
V_65 = F_15 ( V_64 , & V_31 ) ;
if ( V_65 )
goto V_125;
V_65 = F_74 ( V_88 , L_70 , & V_213 ) ;
if ( V_65 ) {
F_19 ( L_131 , V_65 ) ;
goto V_125;
}
V_213 |= V_237 ;
V_65 = F_70 ( V_88 , L_70 , V_213 ) ;
if ( V_65 ) {
F_19 ( L_132 , V_65 ) ;
goto V_125;
}
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_89 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 V_271 , bool V_320 , const T_2 * V_311 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_51 V_31 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( V_271 >= V_321 ) {
F_19 ( L_133 , V_271 ) ;
return - V_85 ;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_54 = ( T_4 ) V_271 ;
V_31 . V_56 = V_272 ;
V_31 . V_55 = V_322 ;
F_3 ( V_215 , L_118 , V_271 ) ;
V_65 = F_15 ( V_64 , & V_31 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_90 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 V_271 , bool V_320 , const T_2 * V_311 , void * V_323 ,
void (* F_91) ( void * V_323 , struct V_312 * V_71 ) )
{
struct V_312 V_71 ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_235 * V_236 ;
T_5 V_213 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
F_3 ( V_215 , L_118 , V_271 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_65 = F_74 ( V_88 , L_70 , & V_213 ) ;
if ( V_65 ) {
F_19 ( L_119 , V_65 ) ;
V_65 = - V_129 ;
goto V_125;
}
if ( V_213 & V_223 ) {
V_236 = & V_209 -> V_236 ;
if ( V_236 -> V_264 & V_256 ) {
V_71 . V_314 = V_256 ;
F_3 ( V_215 , L_124 ) ;
} else if ( V_236 -> V_264 & V_257 ) {
V_71 . V_314 = V_257 ;
F_3 ( V_215 , L_125 ) ;
}
} else if ( V_213 & V_259 ) {
V_71 . V_314 = V_258 ;
F_3 ( V_215 , L_126 ) ;
} else if ( V_213 & V_261 ) {
V_71 . V_314 = V_262 ;
F_3 ( V_215 , L_127 ) ;
} else {
F_19 ( L_134 , V_213 ) ;
V_65 = - V_85 ;
goto V_125;
}
F_91 ( V_323 , & V_71 ) ;
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_92 ( struct V_67 * V_67 ,
struct V_63 * V_64 , T_2 V_271 )
{
F_3 ( V_5 , L_135 ) ;
return - V_80 ;
}
static T_5
F_93 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 * V_324 , struct V_325 * V_326 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_292 V_327 ;
int V_328 ;
T_5 V_329 ;
T_5 V_65 = 0 ;
T_2 * V_99 = V_209 -> V_99 ;
struct V_330 V_331 ;
F_3 ( V_72 , L_136 , V_324 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
if ( V_88 -> V_2 -> V_121 == V_124 ) {
memcpy ( & V_331 , V_324 , V_100 ) ;
V_65 = F_94 ( V_88 , L_137 ,
& V_331 ,
sizeof( V_331 ) ) ;
if ( V_65 < 0 ) {
F_19 ( L_138 , V_65 ) ;
goto V_125;
}
V_326 -> V_332 = V_333 ;
V_326 -> V_334 = F_95 ( V_331 . V_335 ) * 1000 ;
if ( F_95 ( V_331 . V_56 ) & V_336 ) {
V_326 -> V_332 |= V_337 ;
V_326 -> V_338 = F_95 ( V_331 . V_339 ) ;
}
F_3 ( V_72 , L_139 ,
V_326 -> V_334 , V_326 -> V_338 ) ;
} else if ( V_88 -> V_2 -> V_121 == V_123 ) {
if ( memcmp ( V_324 , V_99 , V_100 ) ) {
F_19 ( L_140 ,
V_324 , V_99 ) ;
V_65 = - V_340 ;
goto V_125;
}
V_65 = F_96 ( V_88 , V_341 , & V_329 ) ;
if ( V_65 ) {
F_19 ( L_141 , V_65 ) ;
goto V_125;
} else {
V_326 -> V_332 |= V_342 ;
V_326 -> V_343 . V_344 = V_329 * 5 ;
F_3 ( V_215 , L_142 , V_329 / 2 ) ;
}
if ( F_2 ( V_206 ,
& V_88 -> V_2 -> V_4 ) ) {
memset ( & V_327 , 0 , sizeof( V_327 ) ) ;
V_65 = F_97 ( V_88 , V_345 ,
& V_327 , sizeof( V_327 ) ) ;
if ( V_65 ) {
F_19 ( L_143 , V_65 ) ;
goto V_125;
} else {
V_328 = F_95 ( V_327 . V_237 ) ;
V_326 -> V_332 |= V_346 ;
V_326 -> signal = V_328 ;
F_3 ( V_215 , L_144 , V_328 ) ;
}
}
} else
V_65 = - V_347 ;
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_98 ( struct V_67 * V_67 , struct V_63 * V_64 ,
bool V_348 , T_5 V_349 )
{
T_5 V_350 ;
T_5 V_65 = 0 ;
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
F_3 ( V_72 , L_8 ) ;
V_90 -> V_351 = V_348 ;
if ( ! F_1 ( V_88 -> V_2 ) ) {
F_3 ( V_5 , L_145 ) ;
goto V_125;
}
V_350 = V_348 ? V_352 : V_353 ;
F_3 ( V_5 , L_146 , ( V_350 ? L_147 : L_148 ) ) ;
V_65 = F_40 ( V_88 , V_354 , V_350 ) ;
if ( V_65 ) {
if ( V_65 == - V_355 )
F_19 ( L_149 ) ;
else
F_19 ( L_37 , V_65 ) ;
}
V_125:
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5 F_99 ( struct V_89 * V_90 ,
struct V_356 * V_357 )
{
struct V_67 * V_67 = F_30 ( V_90 ) ;
struct V_17 * V_358 ;
struct V_359 * V_360 ;
struct V_361 * V_22 ;
T_5 V_65 = 0 ;
T_1 V_227 ;
T_4 V_362 ;
T_1 V_363 ;
T_1 V_364 ;
T_2 * V_365 ;
T_6 V_366 ;
T_5 V_367 ;
if ( F_95 ( V_357 -> V_368 ) > V_369 ) {
F_19 ( L_150 ) ;
return 0 ;
}
V_227 = V_357 -> V_370 ? V_357 -> V_370 :
F_100 ( F_101 ( V_357 -> V_19 ) ) ;
if ( V_227 <= V_371 )
V_22 = V_67 -> V_372 [ V_23 ] ;
else
V_22 = V_67 -> V_372 [ V_373 ] ;
V_362 = F_102 ( V_227 , V_22 -> V_22 ) ;
V_358 = F_103 ( V_67 , V_362 ) ;
V_363 = F_101 ( V_357 -> V_374 ) ;
V_364 = F_101 ( V_357 -> V_375 ) ;
V_365 = ( T_2 * ) V_357 + F_101 ( V_357 -> V_376 ) ;
V_366 = F_95 ( V_357 -> V_377 ) ;
V_367 = ( V_378 ) F_101 ( V_357 -> V_379 ) * 100 ;
F_3 ( V_215 , L_151 , V_357 -> V_380 ) ;
F_3 ( V_215 , L_152 , V_227 , V_362 ) ;
F_3 ( V_215 , L_153 , V_363 ) ;
F_3 ( V_215 , L_154 , V_364 ) ;
F_3 ( V_215 , L_155 , V_367 ) ;
V_360 = F_104 ( V_67 , V_358 , ( const T_2 * ) V_357 -> V_380 ,
0 , V_363 , V_364 , V_365 ,
V_366 , V_367 , V_152 ) ;
if ( ! V_360 )
return - V_153 ;
F_105 ( V_67 , V_360 ) ;
return V_65 ;
}
static struct V_356 *
F_106 ( struct V_159 * V_381 , struct V_356 * V_360 )
{
if ( V_360 == NULL )
return V_381 -> V_382 ;
return (struct V_356 * ) ( ( unsigned long ) V_360 +
F_95 ( V_360 -> V_368 ) ) ;
}
static T_5 F_107 ( struct V_89 * V_90 )
{
struct V_159 * V_383 ;
struct V_356 * V_357 = NULL ;
T_5 V_65 = 0 ;
int V_134 ;
V_383 = V_90 -> V_383 ;
if ( V_383 -> V_167 != 0 &&
V_383 -> V_155 != V_384 ) {
F_19 ( L_156 ,
V_383 -> V_155 ) ;
return - V_80 ;
}
F_3 ( V_97 , L_157 , V_383 -> V_167 ) ;
for ( V_134 = 0 ; V_134 < V_383 -> V_167 ; V_134 ++ ) {
V_357 = F_106 ( V_383 , V_357 ) ;
V_65 = F_99 ( V_90 , V_357 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static T_5 F_108 ( struct V_89 * V_90 ,
struct V_63 * V_64 , const T_2 * V_99 )
{
struct V_67 * V_67 = F_30 ( V_90 ) ;
struct V_17 * V_358 ;
struct V_356 * V_357 = NULL ;
struct V_361 * V_22 ;
struct V_359 * V_360 ;
T_2 * V_29 = NULL ;
T_5 V_65 = 0 ;
T_1 V_227 ;
T_4 V_362 ;
T_1 V_363 ;
T_1 V_364 ;
T_2 * V_365 ;
T_6 V_366 ;
T_5 V_367 ;
F_3 ( V_72 , L_8 ) ;
V_29 = F_45 ( V_369 , V_152 ) ;
if ( V_29 == NULL ) {
V_65 = - V_153 ;
goto V_385;
}
* ( V_386 * ) V_29 = F_13 ( V_369 ) ;
V_65 = F_97 ( F_18 ( V_64 ) , V_387 ,
V_29 , V_369 ) ;
if ( V_65 ) {
F_19 ( L_158 , V_65 ) ;
goto V_385;
}
V_357 = (struct V_356 * ) ( V_29 + 4 ) ;
V_227 = V_357 -> V_370 ? V_357 -> V_370 :
F_100 ( F_101 ( V_357 -> V_19 ) ) ;
if ( V_227 <= V_371 )
V_22 = V_67 -> V_372 [ V_23 ] ;
else
V_22 = V_67 -> V_372 [ V_373 ] ;
V_362 = F_102 ( V_227 , V_22 -> V_22 ) ;
V_358 = F_103 ( V_67 , V_362 ) ;
V_363 = F_101 ( V_357 -> V_374 ) ;
V_364 = F_101 ( V_357 -> V_375 ) ;
V_365 = ( T_2 * ) V_357 + F_101 ( V_357 -> V_376 ) ;
V_366 = F_95 ( V_357 -> V_377 ) ;
V_367 = ( V_378 ) F_101 ( V_357 -> V_379 ) * 100 ;
F_3 ( V_215 , L_159 , V_227 , V_362 ) ;
F_3 ( V_215 , L_160 , V_363 ) ;
F_3 ( V_215 , L_64 , V_364 ) ;
F_3 ( V_215 , L_161 , V_367 ) ;
V_360 = F_104 ( V_67 , V_358 , V_99 ,
0 , V_363 , V_364 ,
V_365 , V_366 , V_367 , V_152 ) ;
if ( ! V_360 ) {
V_65 = - V_153 ;
goto V_385;
}
F_105 ( V_67 , V_360 ) ;
V_385:
F_48 ( V_29 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static bool F_109 ( struct V_1 * V_2 )
{
return V_2 -> V_121 == V_122 ;
}
static T_5 F_110 ( struct V_89 * V_90 ,
struct V_87 * V_88 )
{
struct V_204 * V_209 = F_69 ( V_88 -> V_64 ) ;
struct V_356 * V_357 ;
struct V_151 * V_144 ;
struct V_28 * V_388 ;
T_1 V_220 ;
T_2 V_389 ;
T_6 V_219 ;
T_2 * V_37 ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( F_109 ( V_88 -> V_2 ) )
return V_65 ;
V_144 = & V_209 -> V_144 ;
* ( V_386 * ) V_90 -> V_390 = F_13 ( V_391 ) ;
V_65 = F_97 ( V_88 , V_387 ,
V_90 -> V_390 , V_391 ) ;
if ( V_65 ) {
F_19 ( L_162 , V_65 ) ;
goto V_392;
}
V_357 = (struct V_356 * ) ( V_90 -> V_390 + 4 ) ;
V_65 = F_99 ( V_90 , V_357 ) ;
if ( V_65 )
goto V_392;
V_37 = ( ( T_2 * ) V_357 ) + F_101 ( V_357 -> V_376 ) ;
V_219 = F_95 ( V_357 -> V_377 ) ;
V_220 = F_101 ( V_357 -> V_375 ) ;
V_388 = F_8 ( V_37 , V_219 , V_393 ) ;
if ( V_388 )
V_389 = V_388 -> V_61 [ 1 ] ;
else {
T_4 V_394 ;
V_65 = F_84 ( V_88 , L_163 , & V_394 ) ;
if ( V_65 ) {
F_19 ( L_164 , V_65 ) ;
goto V_392;
}
V_389 = ( T_2 ) V_394 ;
}
V_392:
F_3 ( V_72 , L_130 ) ;
return V_65 ;
}
void F_111 ( struct V_89 * V_90 )
{
struct V_117 * V_161 = & V_90 -> V_117 ;
F_39 ( V_178 , & V_90 -> V_113 ) ;
if ( V_90 -> V_96 ) {
V_161 -> V_162 = V_395 ;
F_25 ( V_90 , V_161 -> V_64 , true , true ) ;
}
F_55 ( V_112 , & V_90 -> V_113 ) ;
F_55 ( V_178 , & V_90 -> V_113 ) ;
}
static void F_112 ( struct V_396 * V_397 )
{
struct V_89 * V_90 =
F_57 ( V_397 , struct V_89 ,
V_398 ) ;
F_25 ( V_90 , V_90 -> V_117 . V_64 , true , true ) ;
}
static void F_113 ( unsigned long V_61 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_61 ;
if ( V_90 -> V_96 ) {
F_19 ( L_165 ) ;
F_114 ( & V_90 -> V_398 ) ;
}
}
static T_5
F_115 ( struct V_356 * V_360 ,
struct V_356 * V_382 )
{
if ( ! memcmp ( & V_382 -> V_380 , & V_360 -> V_380 , V_100 ) &&
( F_116 ( F_101 ( V_382 -> V_19 ) ) ==
F_116 ( F_101 ( V_360 -> V_19 ) ) ) &&
V_382 -> V_140 == V_360 -> V_140 &&
! memcmp ( V_382 -> V_143 , V_360 -> V_143 , V_382 -> V_140 ) ) {
if ( ( V_360 -> V_56 & V_399 ) ==
( V_382 -> V_56 & V_399 ) ) {
V_378 V_400 = F_101 ( V_360 -> V_379 ) ;
V_378 V_401 = F_101 ( V_382 -> V_379 ) ;
if ( V_401 > V_400 )
V_360 -> V_379 = V_382 -> V_379 ;
} else if ( ( V_360 -> V_56 & V_399 ) &&
( V_382 -> V_56 & V_399 ) == 0 ) {
V_360 -> V_379 = V_382 -> V_379 ;
V_360 -> V_56 |= V_399 ;
}
return 1 ;
}
return 0 ;
}
static T_5
F_117 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
struct V_63 * V_64 = V_88 -> V_64 ;
T_5 V_406 ;
T_5 V_65 = 0 ;
struct V_407 * V_408 ;
struct V_356 * V_382 ;
struct V_356 * V_360 = NULL ;
T_4 V_409 ;
struct V_159 * V_381 ;
T_4 V_134 ;
bool V_91 ;
V_406 = V_403 -> V_406 ;
if ( ! V_64 || ! F_2 ( V_112 , & V_90 -> V_113 ) ) {
F_19 ( L_166 , V_64 ,
! F_2 ( V_112 , & V_90 -> V_113 ) ) ;
return - V_347 ;
}
if ( V_406 == V_410 ) {
F_3 ( V_97 , L_167 ) ;
V_408 = (struct V_407 * ) V_61 ;
if ( ! V_408 ) {
F_19 ( L_168 ) ;
goto exit;
}
if ( F_101 ( V_408 -> V_411 ) != 1 ) {
F_19 ( L_169 ,
V_408 -> V_411 ) ;
goto exit;
}
V_382 = & V_408 -> V_382 ;
if ( F_118 ( V_90 , V_382 ) )
goto exit;
if ( ! V_90 -> V_96 ) {
F_3 ( V_97 , L_170 ) ;
goto exit;
}
V_409 = F_95 ( V_382 -> V_368 ) ;
if ( V_409 != ( F_95 ( V_408 -> V_30 ) -
V_168 ) ) {
F_19 ( L_171 ,
V_409 ) ;
goto exit;
}
if ( ! ( F_30 ( V_90 ) -> V_412 &
F_119 ( V_73 ) ) ) {
if ( F_101 ( V_382 -> V_374 ) &
V_413 ) {
F_19 ( L_172 ) ;
goto exit;
}
}
V_381 = (struct V_159 * )
V_90 -> V_117 . V_166 ;
if ( V_409 > V_414 - V_381 -> V_30 ) {
F_19 ( L_173 ) ;
goto exit;
}
for ( V_134 = 0 ; V_134 < V_381 -> V_167 ; V_134 ++ ) {
V_360 = V_360 ? (struct V_356 * )
( ( unsigned char * ) V_360 +
F_95 ( V_360 -> V_368 ) ) : V_381 -> V_382 ;
if ( F_115 ( V_360 , V_382 ) )
goto exit;
}
memcpy ( & ( V_90 -> V_117 . V_166 [ V_381 -> V_30 ] ) ,
V_382 , V_409 ) ;
V_381 -> V_155 = F_95 ( V_382 -> V_155 ) ;
V_381 -> V_30 += V_409 ;
V_381 -> V_167 ++ ;
} else {
V_90 -> V_117 . V_162 = V_395 ;
if ( F_118 ( V_90 , NULL ) )
goto exit;
if ( V_90 -> V_96 ) {
V_90 -> V_383 = (struct V_159 * )
V_90 -> V_117 . V_166 ;
F_107 ( V_90 ) ;
V_91 = V_406 != V_415 ;
F_25 ( V_90 , V_64 , V_91 ,
false ) ;
} else
F_3 ( V_97 , L_174 ,
V_406 ) ;
}
exit:
return V_65 ;
}
static void F_120 ( struct V_89 * V_90 )
{
F_121 ( V_90 -> V_416 , V_417 ,
F_117 ) ;
V_90 -> V_117 . V_162 = V_395 ;
F_122 ( & V_90 -> V_98 ) ;
V_90 -> V_98 . V_61 = ( unsigned long ) V_90 ;
V_90 -> V_98 . V_418 = F_113 ;
F_123 ( & V_90 -> V_398 ,
F_112 ) ;
}
static T_7 void F_124 ( T_4 V_419 )
{
if ( V_419 < 1000 / V_186 ) {
F_125 () ;
F_126 ( V_419 ) ;
} else {
F_127 ( V_419 ) ;
}
}
static T_5 F_128 ( struct V_67 * V_67 )
{
F_3 ( V_72 , L_8 ) ;
return 0 ;
}
static T_5 F_129 ( struct V_67 * V_67 ,
struct V_420 * V_421 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_63 * V_64 = F_63 ( V_90 ) ;
struct V_1 * V_2 ;
F_3 ( V_72 , L_8 ) ;
V_2 = ( (struct V_87 * ) F_18 ( V_64 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_130 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_65 ( V_2 ) ;
F_124 ( 500 ) ;
}
if ( F_2 ( V_112 , & V_90 -> V_113 ) )
F_111 ( V_90 ) ;
F_23 ( V_64 , 1 ) ;
exit:
F_3 ( V_72 , L_25 ) ;
V_90 -> V_113 = 0 ;
return 0 ;
}
static T_8 T_5
F_131 ( struct V_63 * V_64 ,
struct V_422 * V_423 , T_5 V_65 )
{
int V_134 , V_424 ;
int V_425 ;
V_425 = F_95 ( V_423 -> V_426 . V_427 ) ;
F_3 ( V_215 , L_175 , V_425 ) ;
for ( V_134 = 0 ; V_134 < V_425 ; V_134 ++ ) {
F_3 ( V_215 , L_176 , V_134 ,
& V_423 -> V_426 . V_428 [ V_134 ] . V_380 ) ;
for ( V_424 = 0 ; V_424 < V_429 ; V_424 ++ )
F_3 ( V_215 , L_177 ,
V_423 -> V_426 . V_428 [ V_134 ] . V_430 [ V_424 ] ) ;
}
if ( ! V_65 )
F_47 ( F_18 ( V_64 ) , L_178 ,
( char * ) V_423 , sizeof( * V_423 ) ) ;
return V_65 ;
}
static T_5
F_132 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_431 * V_432 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_433 * V_426 = & V_90 -> V_423 -> V_426 ;
T_5 V_65 = 0 ;
int V_134 ;
int V_425 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
V_425 = F_95 ( V_426 -> V_427 ) ;
for ( V_134 = 0 ; V_134 < V_425 ; V_134 ++ )
if ( ! memcmp ( V_432 -> V_99 , V_426 -> V_428 [ V_134 ] . V_380 , V_100 ) )
break;
if ( V_134 < V_434 ) {
memcpy ( V_426 -> V_428 [ V_134 ] . V_380 , V_432 -> V_99 , V_100 ) ;
memcpy ( V_426 -> V_428 [ V_134 ] . V_430 , V_432 -> V_428 , V_429 ) ;
if ( V_134 == V_425 ) {
V_425 ++ ;
V_426 -> V_427 = F_13 ( V_425 ) ;
}
} else
V_65 = - V_85 ;
F_3 ( V_215 , L_179 ,
V_426 -> V_428 [ V_425 ] . V_380 ) ;
for ( V_134 = 0 ; V_134 < V_429 ; V_134 ++ )
F_3 ( V_215 , L_177 , V_426 -> V_428 [ V_425 ] . V_430 [ V_134 ] ) ;
V_65 = F_131 ( V_64 , V_90 -> V_423 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_133 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_431 * V_432 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_433 V_428 ;
T_5 V_65 = 0 ;
int V_134 , V_425 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
memcpy ( & V_428 . V_428 [ 0 ] . V_380 , V_432 -> V_99 , V_100 ) ;
memcpy ( & V_428 . V_428 [ 0 ] . V_430 , V_432 -> V_428 , V_429 ) ;
F_3 ( V_215 , L_180 ,
& V_428 . V_428 [ 0 ] . V_380 ) ;
for ( V_134 = 0 ; V_134 < V_429 ; V_134 ++ )
F_3 ( V_215 , L_177 , V_428 . V_428 [ 0 ] . V_430 [ V_134 ] ) ;
V_425 = F_95 ( V_90 -> V_423 -> V_426 . V_427 ) ;
for ( V_134 = 0 ; V_134 < V_425 ; V_134 ++ )
if ( ! memcmp
( V_432 -> V_99 , & V_90 -> V_423 -> V_426 . V_428 [ V_134 ] . V_380 ,
V_100 ) )
break;
if ( ( V_425 > 0 )
&& ( V_134 < V_425 ) ) {
memset ( & V_90 -> V_423 -> V_426 . V_428 [ V_134 ] , 0 ,
sizeof( struct V_428 ) ) ;
for (; V_134 < ( V_425 - 1 ) ; V_134 ++ ) {
memcpy ( & V_90 -> V_423 -> V_426 . V_428 [ V_134 ] . V_380 ,
& V_90 -> V_423 -> V_426 . V_428 [ V_134 + 1 ] . V_380 ,
V_100 ) ;
memcpy ( & V_90 -> V_423 -> V_426 . V_428 [ V_134 ] . V_430 ,
& V_90 -> V_423 -> V_426 . V_428 [ V_134 + 1 ] . V_430 ,
V_429 ) ;
}
V_90 -> V_423 -> V_426 . V_427 = F_13 ( V_425 - 1 ) ;
} else
V_65 = - V_85 ;
V_65 = F_131 ( V_64 , V_90 -> V_423 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_134 ( struct V_67 * V_67 , struct V_63 * V_64 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
memset ( V_90 -> V_423 , 0 , sizeof( * V_90 -> V_423 ) ) ;
V_65 = F_131 ( V_64 , V_90 -> V_423 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_135 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
struct V_63 * V_64 = V_88 -> V_64 ;
struct V_435 * V_436 , * V_437 ;
struct V_95 * V_131 = NULL ;
struct V_171 * V_144 = NULL ;
struct V_17 * V_227 = NULL ;
struct V_67 * V_67 = F_30 ( V_90 ) ;
int V_65 = 0 ;
int V_438 = 0 ;
int V_22 = 0 ;
struct V_439 * V_440 ;
T_4 V_441 ;
T_4 V_406 ;
F_3 ( V_97 , L_8 ) ;
if ( V_403 -> V_442 == V_443 ) {
F_3 ( V_97 , L_181 ) ;
return 0 ;
}
V_440 = (struct V_439 * ) V_61 ;
V_441 = F_95 ( V_440 -> V_167 ) ;
V_406 = F_95 ( V_440 -> V_406 ) ;
F_136 ( V_406 != V_444 ) ;
F_3 ( V_97 , L_182 , V_441 ) ;
if ( V_441 > 0 ) {
int V_134 ;
V_131 = F_45 ( sizeof( * V_131 ) , V_152 ) ;
V_144 = F_137 ( V_441 , sizeof( * V_144 ) , V_152 ) ;
V_227 = F_137 ( V_441 , sizeof( * V_227 ) , V_152 ) ;
if ( ! V_131 || ! V_144 || ! V_227 ) {
V_65 = - V_153 ;
goto V_445;
}
V_131 -> V_67 = V_67 ;
V_61 += sizeof( struct V_439 ) ;
V_437 = (struct V_435 * ) V_61 ;
for ( V_134 = 0 ; V_134 < V_441 ; V_134 ++ ) {
V_436 = & V_437 [ V_134 ] ;
if ( ! V_436 ) {
F_19 ( L_183 ,
V_134 ) ;
V_65 = - V_85 ;
goto V_445;
}
F_3 ( V_97 , L_184 ,
V_436 -> V_143 , V_436 -> V_227 ) ;
memcpy ( V_144 [ V_134 ] . V_144 , V_436 -> V_143 , V_436 -> V_140 ) ;
V_144 [ V_134 ] . V_142 = V_436 -> V_140 ;
V_131 -> V_132 ++ ;
V_438 = V_436 -> V_227 ;
if ( V_438 <= V_371 )
V_22 = V_446 ;
else
V_22 = V_447 ;
V_227 [ V_134 ] . V_20 =
F_102 ( V_438 ,
V_22 ) ;
V_227 [ V_134 ] . V_22 = V_22 ;
V_227 [ V_134 ] . V_56 |= V_448 ;
V_131 -> V_138 [ V_134 ] = & V_227 [ V_134 ] ;
V_131 -> V_133 ++ ;
}
if ( V_131 -> V_132 )
V_131 -> V_141 = & V_144 [ 0 ] ;
if ( F_2 ( V_112 , & V_90 -> V_113 ) ) {
F_111 ( V_90 ) ;
}
F_39 ( V_112 , & V_90 -> V_113 ) ;
V_65 = F_49 ( V_90 , V_67 , V_64 , V_131 ) ;
if ( V_65 ) {
F_55 ( V_112 , & V_90 -> V_113 ) ;
goto V_445;
}
V_90 -> V_111 = true ;
V_90 -> V_96 = V_131 ;
} else {
F_19 ( L_185 ) ;
goto V_445;
}
F_48 ( V_144 ) ;
F_48 ( V_227 ) ;
F_48 ( V_131 ) ;
return 0 ;
V_445:
F_48 ( V_144 ) ;
F_48 ( V_227 ) ;
F_48 ( V_131 ) ;
F_138 ( V_67 ) ;
return V_65 ;
}
static int F_139 ( struct V_63 * V_64 )
{
int V_449 ;
V_449 = F_24 ( F_18 ( V_64 ) , L_186 , 0 ) ;
if ( V_449 == 0 ) {
V_449 = F_47 ( F_18 ( V_64 ) , L_187 ,
NULL , 0 ) ;
}
if ( V_449 < 0 )
F_19 ( L_188 , V_449 ) ;
return V_449 ;
}
static int F_140 ( struct V_63 * V_64 )
{
struct V_450 V_451 ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
V_451 . V_155 = F_13 ( V_452 ) ;
V_451 . V_56 = F_14 ( 1 << V_453 ) ;
V_451 . V_454 = V_455 ;
V_451 . exp = V_456 ;
V_451 . V_457 = F_13 ( V_458 ) ;
return F_47 ( F_18 ( V_64 ) , L_189 ,
& V_451 , sizeof( V_451 ) ) ;
}
static int
F_141 ( struct V_67 * V_67 ,
struct V_63 * V_64 ,
struct V_459 * V_131 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_89 * V_90 = F_34 ( V_67 ) ;
struct V_460 V_461 ;
int V_134 ;
int V_449 = 0 ;
F_3 ( V_97 , L_190 ,
V_131 -> V_462 , V_131 -> V_132 ) ;
if ( F_2 ( V_112 , & V_90 -> V_113 ) ) {
F_19 ( L_39 , V_90 -> V_113 ) ;
return - V_129 ;
}
if ( ! V_131 || ! V_131 -> V_132 || ! V_131 -> V_462 ) {
F_19 ( L_191 ,
V_131 ? V_131 -> V_132 : 0 ) ;
return - V_85 ;
}
if ( V_131 -> V_132 > 0 ) {
for ( V_134 = 0 ; V_134 < V_131 -> V_132 ; V_134 ++ ) {
F_3 ( V_97 , L_192 ,
V_131 -> V_141 [ V_134 ] . V_144 ) ;
}
}
if ( V_131 -> V_462 > 0 ) {
V_449 = F_139 ( V_64 ) ;
if ( V_449 < 0 ) {
F_19 ( L_193 , V_449 ) ;
return V_449 ;
}
V_449 = F_140 ( V_64 ) ;
if ( V_449 < 0 ) {
F_19 ( L_194 , V_449 ) ;
return - V_85 ;
}
for ( V_134 = 0 ; V_134 < V_131 -> V_462 ; V_134 ++ ) {
struct V_171 * V_144 ;
T_4 V_142 ;
V_144 = & V_131 -> V_463 [ V_134 ] . V_144 ;
V_142 = V_144 -> V_142 ;
if ( ! V_142 ) {
F_19 ( L_195 ) ;
continue;
}
V_461 . V_464 = F_13 ( V_465 ) ;
V_461 . V_269 = F_13 ( V_466 ) ;
V_461 . V_213 = F_13 ( 0 ) ;
V_461 . V_119 = F_13 ( 1 ) ;
V_461 . V_56 = F_13 ( 1 << V_467 ) ;
V_461 . V_144 . V_140 = F_13 ( V_142 ) ;
memcpy ( V_461 . V_144 . V_143 , V_144 -> V_144 , V_142 ) ;
V_449 = F_47 ( V_88 , L_196 , & V_461 ,
sizeof( V_461 ) ) ;
F_3 ( V_97 , L_197 ,
V_449 == 0 ? L_198 : L_199 , V_144 -> V_144 ) ;
}
if ( F_24 ( V_88 , L_186 , 1 ) < 0 ) {
F_19 ( L_200 , V_449 ) ;
return - V_85 ;
}
} else {
return - V_85 ;
}
return 0 ;
}
static int F_142 ( struct V_67 * V_67 ,
struct V_63 * V_64 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
F_3 ( V_97 , L_201 ) ;
F_139 ( V_64 ) ;
if ( V_90 -> V_111 )
F_25 ( V_90 , V_64 , true , true ) ;
return 0 ;
}
static int F_143 ( struct V_67 * V_67 , void * V_61 , int V_35 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_63 * V_64 = F_63 ( V_90 ) ;
struct V_468 * V_469 = V_61 ;
struct V_470 * V_471 ;
int V_449 ;
F_3 ( V_72 , L_202 , V_469 -> V_193 , V_469 -> V_472 ,
V_469 -> V_29 , V_469 -> V_35 ) ;
if ( V_469 -> V_472 )
V_449 = F_28 ( F_18 ( V_64 ) , V_469 -> V_193 ,
V_469 -> V_29 , V_469 -> V_35 ) ;
else
V_449 = F_97 ( F_18 ( V_64 ) , V_469 -> V_193 ,
V_469 -> V_29 , V_469 -> V_35 ) ;
if ( V_449 == 0 ) {
V_471 = F_144 ( V_67 , sizeof( * V_469 ) ) ;
F_145 ( V_471 , V_473 , sizeof( * V_469 ) , V_469 ) ;
V_449 = F_146 ( V_471 ) ;
}
return V_449 ;
}
static T_5 F_147 ( struct V_87 * V_88 )
{
T_5 V_65 ;
V_65 = F_70 ( V_88 , L_83 , 0 ) ;
if ( V_65 < 0 ) {
F_19 ( L_203 , V_65 ) ;
return V_65 ;
}
V_65 = F_70 ( V_88 , L_70 , 0 ) ;
if ( V_65 < 0 ) {
F_19 ( L_204 , V_65 ) ;
return V_65 ;
}
V_65 = F_70 ( V_88 , L_76 , V_474 ) ;
if ( V_65 < 0 ) {
F_19 ( L_205 , V_65 ) ;
return V_65 ;
}
return 0 ;
}
static bool F_148 ( T_2 * V_40 , bool V_475 )
{
if ( V_475 )
return ( memcmp ( V_40 , V_476 , V_48 ) == 0 ) ;
return ( memcmp ( V_40 , V_47 , V_48 ) == 0 ) ;
}
static T_5
F_149 ( struct V_63 * V_64 , struct V_44 * V_279 ,
bool V_475 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_4 V_464 = 0 ;
T_1 V_167 ;
T_5 V_65 = 0 ;
T_5 V_35 = 0 ;
T_4 V_134 ;
T_4 V_213 ;
T_4 V_252 = 0 ;
T_4 V_253 = 0 ;
T_4 V_269 = 0 ;
T_4 V_13 ;
T_2 * V_61 ;
T_1 V_477 ;
T_4 V_478 ;
F_3 ( V_72 , L_8 ) ;
if ( V_279 == NULL )
goto exit;
V_35 = V_279 -> V_35 + V_34 ;
V_61 = ( T_2 * ) V_279 ;
V_13 = V_34 ;
if ( ! V_475 )
V_13 += V_479 ;
else
V_13 += V_480 ;
if ( V_13 + V_481 > V_35 ) {
V_65 = - V_85 ;
F_19 ( L_206 ) ;
goto exit;
}
if ( ! F_148 ( & V_61 [ V_13 ] , V_475 ) ) {
V_65 = - V_85 ;
F_19 ( L_207 ) ;
goto exit;
}
V_13 += V_48 ;
switch ( V_61 [ V_13 ] ) {
case V_482 :
V_253 = 0 ;
break;
case V_483 :
case V_484 :
V_253 = V_223 ;
break;
case V_485 :
V_253 = V_259 ;
break;
case V_486 :
V_253 = V_261 ;
break;
default:
V_65 = - V_85 ;
F_19 ( L_208 ) ;
goto exit;
}
V_13 ++ ;
V_167 = V_61 [ V_13 ] + ( V_61 [ V_13 + 1 ] << 8 ) ;
V_13 += V_487 ;
if ( V_13 + ( V_481 * V_167 ) > V_35 ) {
V_65 = - V_85 ;
F_19 ( L_209 ) ;
goto exit;
}
for ( V_134 = 0 ; V_134 < V_167 ; V_134 ++ ) {
if ( ! F_148 ( & V_61 [ V_13 ] , V_475 ) ) {
V_65 = - V_85 ;
F_19 ( L_207 ) ;
goto exit;
}
V_13 += V_48 ;
switch ( V_61 [ V_13 ] ) {
case V_482 :
break;
case V_483 :
case V_484 :
V_252 |= V_223 ;
break;
case V_485 :
V_252 |= V_259 ;
break;
case V_486 :
V_252 |= V_261 ;
break;
default:
F_19 ( L_210 ) ;
}
V_13 ++ ;
}
V_167 = V_61 [ V_13 ] + ( V_61 [ V_13 + 1 ] << 8 ) ;
V_13 += V_487 ;
if ( V_13 + ( V_481 * V_167 ) > V_35 ) {
V_65 = - V_85 ;
F_19 ( L_211 ) ;
goto exit;
}
for ( V_134 = 0 ; V_134 < V_167 ; V_134 ++ ) {
if ( ! F_148 ( & V_61 [ V_13 ] , V_475 ) ) {
V_65 = - V_85 ;
F_19 ( L_207 ) ;
goto exit;
}
V_13 += V_48 ;
switch ( V_61 [ V_13 ] ) {
case V_488 :
F_3 ( V_72 , L_212 ) ;
V_269 |= V_474 ;
break;
case V_489 :
F_3 ( V_72 , L_213 ) ;
V_475 ? ( V_269 |= V_245 ) :
( V_269 |= V_242 ) ;
break;
case V_490 :
F_3 ( V_72 , L_214 ) ;
V_475 ? ( V_269 |= V_244 ) :
( V_269 |= V_241 ) ;
break;
default:
F_19 ( L_215 ) ;
}
V_13 ++ ;
}
if ( V_475 ) {
V_478 = 1 ;
if ( ( V_13 + V_491 ) <= V_35 ) {
V_477 = V_61 [ V_13 ] + ( V_61 [ V_13 + 1 ] << 8 ) ;
if ( V_477 & V_492 )
V_478 = 0 ;
}
V_65 = F_70 ( V_88 , L_216 ,
V_478 ) ;
if ( V_65 < 0 ) {
F_19 ( L_217 , V_65 ) ;
goto exit;
}
}
V_213 = ( V_252 | V_253 | V_493 ) ;
V_65 = F_70 ( V_88 , L_83 , V_464 ) ;
if ( V_65 < 0 ) {
F_19 ( L_203 , V_65 ) ;
goto exit;
}
V_65 = F_70 ( V_88 , L_70 , V_213 ) ;
if ( V_65 < 0 ) {
F_19 ( L_204 , V_65 ) ;
goto exit;
}
V_65 = F_70 ( V_88 , L_76 , V_269 ) ;
if ( V_65 < 0 ) {
F_19 ( L_205 , V_65 ) ;
goto exit;
}
exit:
return V_65 ;
}
static T_5
F_150 ( const T_2 * V_494 , T_4 V_495 ,
struct V_496 * V_497 )
{
T_5 V_65 = 0 ;
struct V_44 * V_498 ;
struct V_28 * V_37 ;
struct V_499 * V_500 ;
T_5 V_501 ;
V_501 = ( T_5 ) V_495 ;
memset ( V_497 , 0 , sizeof( * V_497 ) ) ;
V_37 = (struct V_28 * ) V_494 ;
while ( V_37 ) {
if ( V_37 -> V_36 != V_46 )
goto V_502;
V_498 = (struct V_44 * ) V_37 ;
if ( V_498 -> V_35 < ( V_479 - V_34 + 1 ) ) {
F_19 ( L_218 ,
V_498 -> V_35 ) ;
goto V_502;
}
if ( ! memcmp ( V_498 -> V_40 , ( T_2 * ) V_47 , V_48 ) &&
( ( V_498 -> V_503 == V_49 ) ||
( V_498 -> V_503 == V_504 ) ) ) {
F_3 ( V_72 , L_219 ) ;
goto V_502;
}
V_500 = & V_497 -> V_505 [ V_497 -> V_167 ] ;
V_500 -> V_506 = ( char * ) V_498 ;
V_500 -> V_219 = V_498 -> V_35 + V_34 ;
memcpy ( & V_500 -> V_498 , V_498 , sizeof( * V_498 ) ) ;
V_497 -> V_167 ++ ;
F_3 ( V_72 , L_220 ,
V_500 -> V_498 . V_40 [ 0 ] ,
V_500 -> V_498 . V_40 [ 1 ] ,
V_500 -> V_498 . V_40 [ 2 ] ,
V_500 -> V_498 . V_503 ) ;
if ( V_497 -> V_167 >= V_507 )
break;
V_502:
V_501 -= ( V_37 -> V_35 + V_34 ) ;
if ( V_501 <= V_34 )
V_37 = NULL ;
else
V_37 = (struct V_28 * ) ( ( ( T_2 * ) V_37 ) + V_37 -> V_35 +
V_34 ) ;
}
return V_65 ;
}
static T_4
F_151 ( T_2 * V_508 , T_5 V_509 , T_2 * V_506 , T_4 V_219 , T_9 * V_510 )
{
V_386 V_511 ;
V_386 V_512 ;
strncpy ( V_508 , V_510 , V_513 - 1 ) ;
V_508 [ V_513 - 1 ] = '\0' ;
V_511 = F_13 ( 1 ) ;
memcpy ( & V_508 [ V_514 ] , & V_511 , sizeof( V_511 ) ) ;
V_512 = F_13 ( V_509 ) ;
memcpy ( & V_508 [ V_515 ] , & V_512 , sizeof( V_512 ) ) ;
memcpy ( & V_508 [ V_516 ] , V_506 , V_219 ) ;
return V_219 + V_517 ;
}
T_5 F_79 ( struct V_1 * V_2 , T_5 V_509 ,
const T_2 * V_494 , T_4 V_495 )
{
struct V_87 * V_88 ;
struct V_518 * V_519 ;
T_5 V_65 = 0 ;
T_2 * V_520 ;
T_2 * V_521 ;
T_2 * V_522 = NULL ;
int V_523 ;
T_4 * V_524 ;
T_4 V_525 = 0 ;
T_4 V_526 = 0 ;
T_4 V_527 = 0 ;
struct V_496 V_528 ;
struct V_496 V_529 ;
struct V_499 * V_530 ;
T_5 V_134 ;
T_2 * V_135 ;
int V_531 ;
if ( ! V_2 )
return - V_355 ;
V_88 = V_2 -> V_88 ;
V_519 = & V_2 -> V_519 ;
F_3 ( V_72 , L_221 , V_88 -> V_532 , V_509 ) ;
V_520 = F_45 ( V_391 , V_152 ) ;
if ( ! V_520 )
return - V_153 ;
V_521 = V_520 ;
switch ( V_509 ) {
case V_533 :
V_522 = V_519 -> V_534 ;
V_524 = & V_519 -> V_535 ;
V_523 = sizeof( V_519 -> V_534 ) ;
break;
case V_536 :
V_522 = V_519 -> V_537 ;
V_524 = & V_519 -> V_538 ;
V_523 = sizeof( V_519 -> V_537 ) ;
break;
case V_539 :
V_522 = V_519 -> V_540 ;
V_524 = & V_519 -> V_541 ;
V_523 = sizeof( V_519 -> V_540 ) ;
break;
case V_283 :
V_522 = V_519 -> V_542 ;
V_524 = & V_519 -> V_543 ;
V_523 = sizeof( V_519 -> V_542 ) ;
break;
default:
V_65 = - V_347 ;
F_19 ( L_222 ) ;
goto exit;
}
if ( V_495 > V_523 ) {
V_65 = - V_153 ;
F_19 ( L_223 ) ;
goto exit;
}
if ( V_494 && V_495 && V_521 ) {
V_135 = V_521 ;
F_150 ( V_494 , V_495 , & V_529 ) ;
for ( V_134 = 0 ; V_134 < V_529 . V_167 ; V_134 ++ ) {
V_530 = & V_529 . V_505 [ V_134 ] ;
memcpy ( V_135 + V_527 , V_530 -> V_506 ,
V_530 -> V_219 ) ;
V_527 += V_530 -> V_219 ;
}
}
if ( V_522 && * V_524 ) {
if ( V_527 && ( V_527 == * V_524 ) &&
( memcmp ( V_522 , V_521 ,
V_527 ) == 0 ) ) {
F_3 ( V_72 , L_224 ) ;
goto exit;
}
F_150 ( V_522 , * V_524 , & V_528 ) ;
for ( V_134 = 0 ; V_134 < V_528 . V_167 ; V_134 ++ ) {
V_530 = & V_528 . V_505 [ V_134 ] ;
F_3 ( V_72 , L_225 ,
V_530 -> V_498 . V_36 ,
V_530 -> V_498 . V_35 ,
V_530 -> V_498 . V_40 [ 0 ] ,
V_530 -> V_498 . V_40 [ 1 ] ,
V_530 -> V_498 . V_40 [ 2 ] ) ;
V_525 = F_151 ( V_521 , V_509 ,
V_530 -> V_506 ,
V_530 -> V_219 ,
L_226 ) ;
V_521 += V_525 ;
V_526 += V_525 ;
}
}
* V_524 = 0 ;
if ( V_522 && V_527 ) {
V_135 = V_522 ;
V_531 = V_523 ;
for ( V_134 = 0 ; V_134 < V_529 . V_167 ; V_134 ++ ) {
V_530 = & V_529 . V_505 [ V_134 ] ;
if ( V_531 < ( V_530 -> V_498 . V_35 +
V_516 ) ) {
F_19 ( L_227 ,
V_531 ) ;
break;
}
V_531 -= ( V_530 -> V_219 +
V_516 ) ;
F_3 ( V_72 , L_228 ,
V_530 -> V_498 . V_36 ,
V_530 -> V_498 . V_35 ,
V_530 -> V_498 . V_40 [ 0 ] ,
V_530 -> V_498 . V_40 [ 1 ] ,
V_530 -> V_498 . V_40 [ 2 ] ) ;
V_525 = F_151 ( V_521 , V_509 ,
V_530 -> V_506 ,
V_530 -> V_219 ,
L_229 ) ;
memcpy ( V_135 + ( * V_524 ) , V_530 -> V_506 ,
V_530 -> V_219 ) ;
* V_524 += V_530 -> V_219 ;
V_521 += V_525 ;
V_526 += V_525 ;
}
}
if ( V_526 ) {
V_65 = F_17 ( V_88 , L_230 , V_520 ,
V_526 ) ;
if ( V_65 )
F_19 ( L_231 , V_65 ) ;
}
exit:
F_48 ( V_520 ) ;
return V_65 ;
}
T_5 F_152 ( struct V_1 * V_2 )
{
T_5 V_544 [] = {
V_533 ,
V_536 ,
V_539
} ;
int V_134 ;
for ( V_134 = 0 ; V_134 < F_153 ( V_544 ) ; V_134 ++ )
F_79 ( V_2 , V_544 [ V_134 ] , NULL , 0 ) ;
memset ( & V_2 -> V_519 , 0 , sizeof( V_2 -> V_519 ) ) ;
return 0 ;
}
static T_5
F_154 ( struct V_1 * V_2 ,
struct V_545 * V_546 )
{
T_5 V_65 ;
V_65 = F_79 ( V_2 , V_539 ,
V_546 -> V_547 , V_546 -> V_548 ) ;
if ( V_65 ) {
F_19 ( L_232 ) ;
return V_65 ;
}
F_3 ( V_72 , L_233 ) ;
V_65 = F_79 ( V_2 , V_536 ,
V_546 -> V_549 ,
V_546 -> V_550 ) ;
if ( V_65 )
F_19 ( L_234 ) ;
else
F_3 ( V_72 , L_235 ) ;
return V_65 ;
}
static T_5
F_155 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_551 * V_552 )
{
T_5 V_376 ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_28 * V_553 ;
struct V_136 V_137 ;
T_5 V_65 = - V_347 ;
struct V_28 * V_278 ;
struct V_44 * V_279 ;
struct V_210 V_211 ;
enum V_69 V_554 ;
struct V_555 V_556 ;
F_3 ( V_72 , L_236 ,
F_156 ( & V_552 -> V_216 ) ,
V_552 -> V_220 ,
V_552 -> V_389 ) ;
F_3 ( V_72 , L_237 ,
V_552 -> V_144 , V_552 -> V_142 , V_552 -> V_247 ,
V_552 -> V_557 ) ;
V_554 = V_88 -> V_2 -> V_114 . V_118 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_552 -> V_144 == NULL || V_552 -> V_142 == 0 ) {
V_376 = V_558 + V_559 ;
V_553 = F_8 (
( T_2 * ) & V_552 -> V_546 . V_560 [ V_376 ] ,
V_552 -> V_546 . V_561 - V_376 ,
V_562 ) ;
if ( ! V_553 )
return - V_85 ;
memcpy ( V_137 . V_143 , V_553 -> V_61 , V_553 -> V_35 ) ;
V_137 . V_140 = F_13 ( V_553 -> V_35 ) ;
F_3 ( V_72 , L_238 , V_137 . V_143 ) ;
} else {
memcpy ( V_137 . V_143 , V_552 -> V_144 , V_552 -> V_142 ) ;
V_137 . V_140 = F_13 ( ( T_4 ) V_552 -> V_142 ) ;
}
F_23 ( V_64 , 0 ) ;
V_278 = F_8 ( ( T_2 * ) V_552 -> V_546 . V_547 ,
V_552 -> V_546 . V_548 , V_282 ) ;
V_279 = F_10 ( ( T_2 * ) V_552 -> V_546 . V_547 ,
V_552 -> V_546 . V_548 ) ;
if ( ( V_279 != NULL || V_278 != NULL ) ) {
F_3 ( V_72 , L_239 ) ;
if ( V_279 != NULL ) {
V_65 = F_149 ( V_64 , V_279 , false ) ;
if ( V_65 < 0 )
goto exit;
} else {
V_65 = F_149 ( V_64 ,
(struct V_44 * ) V_278 , true ) ;
if ( V_65 < 0 )
goto exit;
}
} else {
F_3 ( V_72 , L_240 ) ;
F_147 ( V_88 ) ;
}
F_154 ( V_88 -> V_2 , & V_552 -> V_546 ) ;
if ( V_552 -> V_220 ) {
V_65 = F_40 ( V_88 , V_224 ,
V_552 -> V_220 ) ;
if ( V_65 < 0 ) {
F_19 ( L_241 , V_65 ) ;
goto exit;
}
}
if ( V_552 -> V_389 ) {
V_65 = F_40 ( V_88 , V_563 ,
V_552 -> V_389 ) ;
if ( V_65 < 0 ) {
F_19 ( L_242 , V_65 ) ;
goto exit;
}
}
if ( V_554 == V_75 ) {
V_65 = F_40 ( V_88 , V_564 , 1 ) ;
if ( V_65 < 0 ) {
F_19 ( L_243 , V_65 ) ;
goto exit;
}
F_24 ( V_88 , L_244 , 0 ) ;
}
V_65 = F_40 ( V_88 , V_128 , 1 ) ;
if ( V_65 < 0 ) {
F_19 ( L_245 , V_65 ) ;
goto exit;
}
if ( V_554 == V_75 ) {
V_65 = F_40 ( V_88 , V_565 , 1 ) ;
if ( V_65 < 0 ) {
F_19 ( L_246 , V_65 ) ;
goto exit;
}
V_65 = F_40 ( V_88 , V_566 , 1 ) ;
if ( V_65 < 0 ) {
F_19 ( L_247 , V_65 ) ;
goto exit;
}
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
memcpy ( & V_211 . V_137 , & V_137 , sizeof( V_137 ) ) ;
V_65 = F_28 ( V_88 , V_232 ,
& V_211 , sizeof( V_211 ) ) ;
if ( V_65 < 0 ) {
F_19 ( L_248 , V_65 ) ;
goto exit;
}
F_3 ( V_72 , L_249 ) ;
} else {
V_65 = F_17 ( V_88 , L_250 , & V_137 ,
sizeof( V_137 ) ) ;
if ( V_65 < 0 ) {
F_19 ( L_251 , V_65 ) ;
goto exit;
}
V_556 . V_567 = F_13 ( V_88 -> V_532 ) ;
V_556 . V_568 = F_13 ( 1 ) ;
V_65 = F_47 ( V_88 , L_252 , & V_556 ,
sizeof( V_556 ) ) ;
if ( V_65 < 0 ) {
F_19 ( L_253 , V_65 ) ;
goto exit;
}
F_3 ( V_72 , L_254 ) ;
}
F_55 ( V_127 , & V_88 -> V_2 -> V_4 ) ;
F_39 ( V_569 , & V_88 -> V_2 -> V_4 ) ;
exit:
if ( V_65 )
F_23 ( V_64 , 1 ) ;
return V_65 ;
}
static int F_157 ( struct V_67 * V_67 , struct V_63 * V_64 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 ;
struct V_555 V_556 ;
struct V_210 V_211 ;
F_3 ( V_72 , L_8 ) ;
if ( V_88 -> V_2 -> V_114 . V_118 == V_75 ) {
F_127 ( 400 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_65 = F_28 ( V_88 , V_232 ,
& V_211 , sizeof( V_211 ) ) ;
if ( V_65 < 0 )
F_19 ( L_248 , V_65 ) ;
V_65 = F_40 ( V_88 , V_566 , 0 ) ;
if ( V_65 < 0 )
F_19 ( L_255 , V_65 ) ;
V_65 = F_40 ( V_88 , V_565 , 0 ) ;
if ( V_65 < 0 )
F_19 ( L_246 , V_65 ) ;
V_65 = F_40 ( V_88 , V_128 , 0 ) ;
if ( V_65 < 0 )
F_19 ( L_256 , V_65 ) ;
} else {
V_556 . V_567 = F_13 ( V_88 -> V_532 ) ;
V_556 . V_568 = F_13 ( 0 ) ;
V_65 = F_47 ( V_88 , L_252 , & V_556 ,
sizeof( V_556 ) ) ;
if ( V_65 < 0 )
F_19 ( L_253 , V_65 ) ;
}
F_23 ( V_64 , 1 ) ;
F_39 ( V_127 , & V_88 -> V_2 -> V_4 ) ;
F_55 ( V_569 , & V_88 -> V_2 -> V_4 ) ;
return V_65 ;
}
static T_5
F_158 ( struct V_67 * V_67 , struct V_63 * V_64 ,
struct V_545 * V_570 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 ;
F_3 ( V_72 , L_8 ) ;
V_65 = F_154 ( V_88 -> V_2 , V_570 ) ;
return V_65 ;
}
static int
F_159 ( struct V_67 * V_67 , struct V_63 * V_64 ,
T_2 * V_324 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_292 V_293 ;
struct V_87 * V_88 = F_18 ( V_64 ) ;
T_5 V_65 ;
if ( ! V_324 )
return - V_571 ;
F_3 ( V_72 , L_257 , V_324 ) ;
if ( V_88 -> V_2 == V_90 -> V_180 . V_181 [ V_182 ] . V_2 )
V_88 = V_90 -> V_180 . V_181 [ V_183 ] . V_2 -> V_88 ;
if ( ! F_1 ( V_88 -> V_2 ) )
return - V_188 ;
memcpy ( & V_293 . V_62 , V_324 , V_100 ) ;
V_293 . V_237 = F_13 ( V_572 ) ;
V_65 = F_28 ( V_88 , V_573 ,
& V_293 , sizeof( V_293 ) ) ;
if ( V_65 )
F_19 ( L_258 , V_65 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static void
F_160 ( struct V_67 * V_67 ,
struct V_66 * V_114 ,
T_1 V_574 , bool V_575 )
{
struct V_87 * V_88 = F_18 ( V_114 -> V_115 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
T_1 V_576 ;
F_3 ( V_72 , L_259 , V_574 , V_575 ) ;
V_576 = ( V_574 & V_577 ) >> 4 ;
if ( V_575 )
V_2 -> V_578 |= F_119 ( V_576 ) ;
else
V_2 -> V_578 &= ~ F_119 ( V_576 ) ;
}
static int
F_161 ( struct V_67 * V_67 , struct V_66 * V_114 ,
struct V_17 * V_217 , bool V_579 ,
unsigned int V_580 , const T_2 * V_29 , T_6 V_35 ,
bool V_581 , bool V_582 , T_10 * V_323 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
const struct V_583 * V_584 ;
struct V_87 * V_88 ;
struct V_1 * V_2 ;
T_5 V_65 = 0 ;
T_5 V_376 ;
T_5 V_219 ;
struct V_585 * V_586 ;
struct V_587 * V_588 ;
bool V_589 ;
T_5 V_590 ;
F_3 ( V_72 , L_8 ) ;
* V_323 = 0 ;
V_584 = ( const struct V_583 * ) V_29 ;
if ( ! F_162 ( V_584 -> V_591 ) ) {
F_19 ( L_260 ) ;
return - V_347 ;
}
if ( F_163 ( V_584 -> V_591 ) ) {
V_376 = V_558 +
V_559 ;
V_219 = V_35 - V_376 ;
V_88 = F_18 ( V_114 -> V_115 ) ;
V_2 = V_88 -> V_2 ;
if ( V_2 == V_90 -> V_180 . V_181 [ V_183 ] . V_2 )
V_2 = V_90 -> V_180 . V_181 [ V_182 ] . V_2 ;
V_65 = F_79 ( V_2 ,
V_536 ,
& V_29 [ V_376 ] ,
V_219 ) ;
F_164 ( V_114 , * V_323 , V_29 , V_35 , true ,
V_152 ) ;
} else if ( F_165 ( V_584 -> V_591 ) ) {
V_588 = F_45 ( sizeof( * V_588 ) , V_152 ) ;
if ( V_588 == NULL ) {
F_19 ( L_261 ) ;
V_65 = - V_153 ;
goto exit;
}
V_586 = & V_588 -> V_586 ;
V_586 -> V_592 = F_13 ( * V_323 ) ;
memcpy ( & V_586 -> V_593 [ 0 ] , & V_584 -> V_593 [ 0 ] , V_100 ) ;
memcpy ( & V_588 -> V_99 [ 0 ] , & V_584 -> V_99 [ 0 ] , V_100 ) ;
V_586 -> V_35 = F_14 ( V_35 - V_558 ) ;
V_590 = F_7 ( V_217 -> V_20 ) ;
V_588 -> V_227 = F_13 ( V_590 ) ;
memcpy ( V_586 -> V_61 , & V_29 [ V_558 ] ,
F_101 ( V_586 -> V_35 ) ) ;
F_3 ( V_72 , L_262 ,
* V_323 , F_101 ( V_586 -> V_35 ) ,
V_217 -> V_20 ) ;
V_589 = F_166 ( V_90 , V_114 -> V_115 ,
V_588 ) ;
F_164 ( V_114 , * V_323 , V_29 , V_35 , V_589 ,
V_152 ) ;
F_48 ( V_588 ) ;
} else {
F_3 ( V_72 , L_263 , V_584 -> V_591 ) ;
F_167 ( true , V_29 , V_35 , L_264 , V_35 ) ;
}
exit:
return V_65 ;
}
static int
F_168 ( struct V_67 * V_67 ,
struct V_66 * V_114 ,
T_10 V_323 )
{
struct V_89 * V_90 = F_62 ( V_67 ) ;
struct V_1 * V_2 ;
int V_65 = 0 ;
F_3 ( V_72 , L_265 ) ;
V_2 = V_90 -> V_180 . V_181 [ V_182 ] . V_2 ;
if ( V_2 == NULL ) {
F_19 ( L_266 ) ;
V_65 = - V_355 ;
goto exit;
}
F_169 ( V_2 -> V_88 ) ;
exit:
return V_65 ;
}
static T_5 F_170 ( enum V_69 type )
{
switch ( type ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return - V_594 ;
case V_73 :
return V_122 ;
case V_74 :
case V_81 :
return V_123 ;
case V_75 :
case V_82 :
return V_124 ;
case V_84 :
return V_595 ;
case V_83 :
default:
break;
}
return - V_85 ;
}
static void F_171 ( struct V_67 * V_67 )
{
V_67 -> V_596 = V_597 ;
V_67 -> V_598 = V_597 ;
V_67 -> V_599 = V_600 ;
V_67 -> V_56 |= V_601 ;
}
static struct V_67 * F_172 ( struct V_602 * V_603 )
{
struct V_67 * V_67 ;
T_5 V_65 = 0 ;
V_67 = F_173 ( & V_604 , sizeof( struct V_89 ) ) ;
if ( ! V_67 ) {
F_19 ( L_267 ) ;
return F_21 ( - V_153 ) ;
}
F_174 ( V_67 , V_603 ) ;
V_67 -> V_605 = V_606 ;
V_67 -> V_607 = V_600 ;
V_67 -> V_608 = V_434 ;
V_67 -> V_412 = F_119 ( V_74 ) |
F_119 ( V_73 ) |
F_119 ( V_75 ) |
F_119 ( V_81 ) |
F_119 ( V_82 ) ;
V_67 -> V_609 = V_610 ;
V_67 -> V_611 = F_153 ( V_610 ) ;
V_67 -> V_372 [ V_23 ] = & V_612 ;
V_67 -> V_372 [ V_373 ] = & V_613 ;
V_67 -> V_614 = V_615 ;
V_67 -> V_616 = V_617 ;
V_67 -> V_618 = F_153 ( V_617 ) ;
V_67 -> V_56 |= V_619 |
V_620 |
V_621 ;
V_67 -> V_622 = V_623 ;
V_67 -> V_624 = 5000 ;
F_171 ( V_67 ) ;
V_65 = F_175 ( V_67 ) ;
if ( V_65 < 0 ) {
F_19 ( L_268 , V_65 ) ;
F_176 ( V_67 ) ;
return F_21 ( V_65 ) ;
}
return V_67 ;
}
struct V_1 * F_177 ( struct V_89 * V_90 ,
enum V_69 type ,
bool V_625 )
{
struct V_1 * V_2 ;
if ( V_90 -> V_626 == V_627 )
return F_21 ( - V_628 ) ;
F_3 ( V_72 , L_269 ,
sizeof( * V_2 ) ) ;
V_2 = F_45 ( sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 )
return F_21 ( - V_153 ) ;
V_2 -> V_114 . V_67 = V_90 -> V_67 ;
V_2 -> V_114 . V_118 = type ;
V_2 -> V_121 = F_170 ( type ) ;
V_2 -> V_625 = V_625 ;
V_2 -> V_629 = - 1 ;
F_64 ( & V_2 -> V_209 ) ;
F_178 ( & V_2 -> V_381 , & V_90 -> V_630 ) ;
V_90 -> V_626 ++ ;
return V_2 ;
}
void F_179 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_67 * V_67 ;
V_67 = V_2 -> V_114 . V_67 ;
V_90 = F_34 ( V_67 ) ;
F_180 ( & V_2 -> V_381 ) ;
V_90 -> V_626 -- ;
F_48 ( V_2 ) ;
if ( ! V_90 -> V_626 ) {
F_181 ( V_67 ) ;
F_176 ( V_67 ) ;
}
}
static bool F_182 ( const struct V_402 * V_403 )
{
T_4 V_631 = V_403 -> V_442 ;
T_4 V_406 = V_403 -> V_406 ;
if ( V_631 == V_632 && V_406 == V_415 ) {
F_3 ( V_215 , L_270 ) ;
return true ;
}
return false ;
}
static bool F_183 ( const struct V_402 * V_403 )
{
T_4 V_631 = V_403 -> V_442 ;
T_1 V_56 = V_403 -> V_56 ;
if ( V_631 == V_633 && ( ! ( V_56 & V_634 ) ) ) {
F_3 ( V_215 , L_271 ) ;
return true ;
}
return false ;
}
static bool F_184 ( struct V_89 * V_90 ,
const struct V_402 * V_403 )
{
T_4 V_631 = V_403 -> V_442 ;
T_4 V_406 = V_403 -> V_406 ;
if ( V_631 == V_633 && V_406 == V_635 ) {
F_3 ( V_215 , L_272 ,
V_403 -> V_56 & V_634 ? L_273 : L_274 ) ;
return true ;
}
if ( V_631 == V_632 && V_406 != V_415 ) {
F_3 ( V_215 , L_275 ) ;
return true ;
}
return false ;
}
static void F_185 ( struct V_89 * V_90 )
{
struct V_636 * V_637 = F_186 ( V_90 ) ;
F_48 ( V_637 -> V_638 ) ;
V_637 -> V_638 = NULL ;
V_637 -> V_639 = 0 ;
F_48 ( V_637 -> V_640 ) ;
V_637 -> V_640 = NULL ;
V_637 -> V_641 = 0 ;
}
static T_5 F_187 ( struct V_89 * V_90 ,
struct V_87 * V_88 )
{
struct V_642 * V_643 ;
struct V_636 * V_637 = F_186 ( V_90 ) ;
T_4 V_644 ;
T_4 V_645 ;
T_5 V_65 = 0 ;
F_185 ( V_90 ) ;
V_65 = F_94 ( V_88 , L_276 ,
V_90 -> V_390 , V_646 ) ;
if ( V_65 ) {
F_19 ( L_277 , V_65 ) ;
return V_65 ;
}
V_643 =
(struct V_642 * ) V_90 -> V_390 ;
V_644 = F_95 ( V_643 -> V_644 ) ;
V_645 = F_95 ( V_643 -> V_645 ) ;
if ( V_644 ) {
V_65 = F_94 ( V_88 , L_278 ,
V_90 -> V_390 ,
V_646 ) ;
if ( V_65 ) {
F_19 ( L_279 , V_65 ) ;
return V_65 ;
}
V_637 -> V_639 = V_644 ;
V_637 -> V_638 =
F_188 ( V_90 -> V_390 , V_637 -> V_639 ,
V_152 ) ;
} else {
V_637 -> V_639 = 0 ;
V_637 -> V_638 = NULL ;
}
if ( V_645 ) {
V_65 = F_94 ( V_88 , L_280 ,
V_90 -> V_390 ,
V_646 ) ;
if ( V_65 ) {
F_19 ( L_281 , V_65 ) ;
return V_65 ;
}
V_637 -> V_641 = V_645 ;
V_637 -> V_640 =
F_188 ( V_90 -> V_390 , V_637 -> V_641 ,
V_152 ) ;
} else {
V_637 -> V_641 = 0 ;
V_637 -> V_640 = NULL ;
}
F_3 ( V_215 , L_282 ,
V_637 -> V_639 , V_637 -> V_641 ) ;
return V_65 ;
}
static T_5
F_189 ( struct V_89 * V_90 ,
struct V_63 * V_64 ,
const struct V_402 * V_403 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_636 * V_637 = F_186 ( V_90 ) ;
struct V_67 * V_67 = F_30 ( V_90 ) ;
struct V_17 * V_358 = NULL ;
struct V_361 * V_22 ;
struct V_356 * V_357 ;
T_4 V_362 ;
T_5 V_65 = 0 ;
T_4 V_226 ;
T_2 * V_29 ;
F_3 ( V_72 , L_8 ) ;
F_187 ( V_90 , V_88 ) ;
memcpy ( V_209 -> V_99 , V_403 -> V_647 , V_100 ) ;
F_110 ( V_90 , V_88 ) ;
V_29 = F_45 ( V_369 , V_152 ) ;
if ( V_29 == NULL ) {
V_65 = - V_153 ;
goto V_125;
}
* ( V_386 * ) V_29 = F_13 ( V_369 ) ;
V_65 = F_97 ( V_88 , V_387 ,
V_29 , V_369 ) ;
if ( V_65 )
goto V_125;
V_357 = (struct V_356 * ) ( V_29 + 4 ) ;
V_226 = V_357 -> V_370 ? V_357 -> V_370 :
F_100 ( F_101 ( V_357 -> V_19 ) ) ;
if ( V_226 <= V_371 )
V_22 = V_67 -> V_372 [ V_23 ] ;
else
V_22 = V_67 -> V_372 [ V_373 ] ;
V_362 = F_102 ( V_226 , V_22 -> V_22 ) ;
V_358 = F_103 ( V_67 , V_362 ) ;
V_125:
F_48 ( V_29 ) ;
F_190 ( V_64 , V_358 , ( T_2 * ) V_209 -> V_99 ,
V_637 -> V_638 , V_637 -> V_639 ,
V_637 -> V_640 , V_637 -> V_641 , V_152 ) ;
F_3 ( V_215 , L_283 ) ;
F_39 ( V_206 , & V_88 -> V_2 -> V_4 ) ;
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_191 ( struct V_89 * V_90 ,
struct V_63 * V_64 , const struct V_402 * V_403 ,
bool V_648 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
struct V_636 * V_637 = F_186 ( V_90 ) ;
T_5 V_65 = 0 ;
F_3 ( V_72 , L_8 ) ;
if ( F_32 ( V_179 ,
& V_88 -> V_2 -> V_4 ) ) {
if ( V_648 ) {
F_187 ( V_90 , V_88 ) ;
memcpy ( V_209 -> V_99 , V_403 -> V_647 , V_100 ) ;
F_110 ( V_90 , V_88 ) ;
F_39 ( V_206 ,
& V_88 -> V_2 -> V_4 ) ;
}
F_192 ( V_64 ,
( T_2 * ) V_209 -> V_99 ,
V_637 -> V_638 ,
V_637 -> V_639 ,
V_637 -> V_640 ,
V_637 -> V_641 ,
V_648 ? V_649 :
V_650 ,
V_152 ) ;
F_3 ( V_215 , L_284 ,
V_648 ? L_285 : L_199 ) ;
}
F_3 ( V_72 , L_25 ) ;
return V_65 ;
}
static T_5
F_193 ( struct V_89 * V_90 ,
struct V_63 * V_64 ,
const struct V_402 * V_403 , void * V_61 )
{
static int V_651 ;
T_4 V_631 = V_403 -> V_442 ;
T_4 V_652 = V_403 -> V_652 ;
struct V_325 V_326 ;
F_3 ( V_215 , L_286 , V_631 , V_652 ) ;
if ( V_631 == V_633 && V_652 == V_653 &&
V_64 != F_63 ( V_90 ) ) {
F_3 ( V_215 , L_287 ) ;
F_194 ( & V_90 -> V_654 ) ;
return 0 ;
}
if ( ( ( V_631 == V_655 ) || ( V_631 == V_656 ) ) &&
( V_652 == V_415 ) ) {
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
V_326 . V_332 = V_657 ;
if ( ! V_61 ) {
F_19 ( L_288 ) ;
return - V_85 ;
}
V_326 . V_658 = V_61 ;
V_326 . V_659 = V_403 -> V_660 ;
V_651 ++ ;
V_326 . V_651 = V_651 ;
F_195 ( V_64 , V_403 -> V_647 , & V_326 , V_152 ) ;
} else if ( ( V_631 == V_661 ) ||
( V_631 == V_662 ) ||
( V_631 == V_663 ) ) {
F_196 ( V_64 , V_403 -> V_647 , V_152 ) ;
}
return 0 ;
}
static T_5
F_197 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
struct V_63 * V_64 = V_88 -> V_64 ;
struct V_204 * V_209 = & V_88 -> V_2 -> V_209 ;
T_5 V_65 = 0 ;
if ( V_88 -> V_2 -> V_121 == V_124 ) {
V_65 = F_193 ( V_90 , V_64 , V_403 , V_61 ) ;
} else if ( F_182 ( V_403 ) ) {
F_3 ( V_215 , L_289 ) ;
if ( F_109 ( V_88 -> V_2 ) ) {
memcpy ( V_209 -> V_99 , V_403 -> V_647 , V_100 ) ;
F_108 ( V_90 , V_64 , V_403 -> V_647 ) ;
F_198 ( V_64 , V_403 -> V_647 , V_152 ) ;
F_55 ( V_179 ,
& V_88 -> V_2 -> V_4 ) ;
F_39 ( V_206 ,
& V_88 -> V_2 -> V_4 ) ;
} else
F_191 ( V_90 , V_64 , V_403 , true ) ;
} else if ( F_183 ( V_403 ) ) {
F_3 ( V_215 , L_290 ) ;
if ( ! F_109 ( V_88 -> V_2 ) ) {
F_191 ( V_90 , V_64 , V_403 , false ) ;
if ( F_32 ( V_206 ,
& V_88 -> V_2 -> V_4 ) )
F_199 ( V_64 , 0 , NULL , 0 ,
V_152 ) ;
}
F_65 ( V_88 -> V_2 ) ;
F_64 ( F_69 ( V_64 ) ) ;
if ( V_64 != F_63 ( V_90 ) )
F_194 ( & V_90 -> V_654 ) ;
} else if ( F_184 ( V_90 , V_403 ) ) {
if ( F_109 ( V_88 -> V_2 ) )
F_55 ( V_179 ,
& V_88 -> V_2 -> V_4 ) ;
else
F_191 ( V_90 , V_64 , V_403 , false ) ;
}
return V_65 ;
}
static T_5
F_200 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
T_5 V_65 = 0 ;
T_4 V_631 = V_403 -> V_442 ;
T_4 V_406 = V_403 -> V_406 ;
if ( V_631 == V_664 && V_406 == V_415 ) {
if ( F_2 ( V_206 , & V_88 -> V_2 -> V_4 ) )
F_189 ( V_90 , V_88 -> V_64 , V_403 ) ;
else
F_191 ( V_90 , V_88 -> V_64 , V_403 , true ) ;
}
return V_65 ;
}
static T_5
F_201 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
T_1 V_56 = V_403 -> V_56 ;
enum V_665 V_666 ;
if ( V_56 & V_667 )
V_666 = V_668 ;
else
V_666 = V_669 ;
F_202 ( V_88 -> V_64 , ( T_2 * ) & V_403 -> V_647 , V_666 , - 1 ,
NULL , V_152 ) ;
return 0 ;
}
static T_5 F_203 ( struct V_87 * V_88 ,
const struct V_402 * V_403 , void * V_61 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
struct V_670 * V_671 = (struct V_670 * ) V_61 ;
struct V_672 * V_631 = & V_90 -> V_673 ;
struct V_1 * V_2 ;
F_3 ( V_72 , L_291 ,
V_671 -> V_147 , V_671 -> V_56 , V_671 -> V_674 ,
V_671 -> V_532 ) ;
F_204 ( & V_631 -> V_675 ) ;
V_631 -> V_147 = V_671 -> V_147 ;
V_2 = V_631 -> V_2 ;
switch ( V_671 -> V_147 ) {
case V_676 :
if ( ! V_90 -> V_673 . V_2 ) {
F_205 ( & V_631 -> V_675 ) ;
return - V_677 ;
}
V_88 -> V_2 = V_2 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_114 . V_115 = V_88 -> V_64 ;
V_88 -> V_64 -> V_130 = & V_2 -> V_114 ;
F_206 ( V_88 -> V_64 , F_207 ( V_90 -> V_67 ) ) ;
F_205 ( & V_631 -> V_675 ) ;
F_208 ( & V_631 -> V_678 ) ;
return 0 ;
case V_679 :
V_88 -> V_2 = NULL ;
F_205 ( & V_631 -> V_675 ) ;
if ( F_35 ( V_90 ) )
F_208 ( & V_631 -> V_678 ) ;
return 0 ;
case V_680 :
F_205 ( & V_631 -> V_675 ) ;
F_208 ( & V_631 -> V_678 ) ;
return 0 ;
default:
F_205 ( & V_631 -> V_675 ) ;
break;
}
return - V_85 ;
}
static void F_209 ( struct V_681 * V_198 )
{
V_198 -> V_190 = ( T_4 ) - 1 ;
V_198 -> V_189 = ( T_4 ) - 1 ;
V_198 -> V_203 = ( T_4 ) - 1 ;
V_198 -> V_201 = ( T_4 ) - 1 ;
V_198 -> V_304 = - 1 ;
}
static void F_210 ( struct V_89 * V_90 )
{
F_121 ( V_90 -> V_416 , V_633 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_662 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_663 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_661 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_655 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_656 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_664 ,
F_200 ) ;
F_121 ( V_90 -> V_416 , V_682 ,
F_201 ) ;
F_121 ( V_90 -> V_416 , V_632 ,
F_197 ) ;
F_121 ( V_90 -> V_416 , V_683 ,
F_135 ) ;
F_121 ( V_90 -> V_416 , V_684 ,
F_203 ) ;
F_121 ( V_90 -> V_416 , V_685 ,
V_686 ) ;
F_121 ( V_90 -> V_416 , V_687 ,
V_688 ) ;
F_121 ( V_90 -> V_416 , V_689 ,
V_690 ) ;
F_121 ( V_90 -> V_416 , V_691 ,
V_692 ) ;
F_121 ( V_90 -> V_416 , V_693 ,
V_692 ) ;
}
static void F_211 ( struct V_89 * V_90 )
{
F_48 ( V_90 -> V_198 ) ;
V_90 -> V_198 = NULL ;
F_48 ( V_90 -> V_694 ) ;
V_90 -> V_694 = NULL ;
F_48 ( V_90 -> V_390 ) ;
V_90 -> V_390 = NULL ;
F_48 ( V_90 -> V_423 ) ;
V_90 -> V_423 = NULL ;
}
static T_5 F_212 ( struct V_89 * V_90 )
{
V_90 -> V_198 = F_45 ( sizeof( * V_90 -> V_198 ) , V_152 ) ;
if ( ! V_90 -> V_198 )
goto V_695;
V_90 -> V_694 = F_45 ( V_154 , V_152 ) ;
if ( ! V_90 -> V_694 )
goto V_695;
V_90 -> V_390 = F_45 ( V_391 , V_152 ) ;
if ( ! V_90 -> V_390 )
goto V_695;
V_90 -> V_423 = F_45 ( sizeof( * V_90 -> V_423 ) , V_152 ) ;
if ( ! V_90 -> V_423 )
goto V_695;
return 0 ;
V_695:
F_211 ( V_90 ) ;
return - V_153 ;
}
static T_5 F_213 ( struct V_89 * V_90 )
{
T_5 V_65 = 0 ;
V_90 -> V_96 = NULL ;
V_90 -> V_351 = true ;
V_90 -> V_696 = true ;
V_90 -> V_164 = true ;
V_90 -> V_697 = false ;
V_65 = F_212 ( V_90 ) ;
if ( V_65 )
return V_65 ;
F_210 ( V_90 ) ;
F_214 ( & V_90 -> V_698 ) ;
F_120 ( V_90 ) ;
F_209 ( V_90 -> V_198 ) ;
F_215 ( & V_90 -> V_654 ) ;
return V_65 ;
}
static void F_216 ( struct V_89 * V_90 )
{
V_90 -> V_697 = false ;
F_111 ( V_90 ) ;
F_211 ( V_90 ) ;
}
static void F_217 ( struct V_672 * V_631 )
{
F_218 ( & V_631 -> V_678 ) ;
F_214 ( & V_631 -> V_675 ) ;
}
struct V_89 * F_219 ( struct V_699 * V_404 ,
struct V_602 * V_700 )
{
struct V_63 * V_64 = V_404 -> V_701 [ 0 ] -> V_64 ;
struct V_89 * V_90 ;
struct V_67 * V_67 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
T_5 V_65 = 0 ;
if ( ! V_64 ) {
F_19 ( L_292 ) ;
return NULL ;
}
V_88 = F_18 ( V_64 ) ;
V_67 = F_172 ( V_700 ) ;
if ( F_220 ( V_67 ) )
return NULL ;
V_90 = F_34 ( V_67 ) ;
V_90 -> V_67 = V_67 ;
V_90 -> V_416 = V_404 ;
F_217 ( & V_90 -> V_673 ) ;
F_221 ( & V_90 -> V_630 ) ;
V_2 = F_177 ( V_90 , V_74 , false ) ;
if ( F_220 ( V_2 ) ) {
F_176 ( V_67 ) ;
return NULL ;
}
V_2 -> V_88 = V_88 ;
V_2 -> V_114 . V_115 = V_64 ;
V_64 -> V_130 = & V_2 -> V_114 ;
F_206 ( V_64 , F_207 ( V_90 -> V_67 ) ) ;
V_65 = F_213 ( V_90 ) ;
if ( V_65 ) {
F_19 ( L_293 , V_65 ) ;
goto V_702;
}
V_88 -> V_2 = V_2 ;
V_65 = F_222 ( V_90 ) ;
if ( V_65 ) {
F_19 ( L_294 , V_65 ) ;
goto V_703;
}
return V_90 ;
V_703:
F_216 ( V_90 ) ;
V_702:
F_179 ( V_2 ) ;
F_176 ( V_67 ) ;
return NULL ;
}
void F_223 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
struct V_1 * V_704 ;
F_216 ( V_90 ) ;
F_224 (vif, tmp, &cfg->vif_list, list) {
F_179 ( V_2 ) ;
}
}
static T_5
F_225 ( struct V_87 * V_88 , T_4 V_705 , T_4 V_706 )
{
T_5 V_65 = 0 ;
V_386 V_707 [ 2 ] ;
V_386 V_708 [ 2 ] ;
if ( V_705 ) {
V_65 = F_24 ( V_88 , L_295 , V_706 ) ;
if ( V_65 ) {
F_19 ( L_296 , V_65 ) ;
goto V_709;
}
}
F_3 ( V_5 , L_297 , V_705 ? L_298 : L_299 ) ;
V_65 = F_24 ( V_88 , L_300 , V_705 ) ;
if ( V_65 ) {
F_19 ( L_301 , V_65 ) ;
goto V_709;
}
V_707 [ 0 ] = F_13 ( V_710 ) ;
V_707 [ 1 ] = F_13 ( V_711 ) ;
V_65 = F_28 ( V_88 , V_712 ,
( void * ) V_707 , sizeof( V_707 ) ) ;
if ( V_65 ) {
F_19 ( L_302 , V_65 ) ;
goto V_709;
}
V_708 [ 0 ] = F_13 ( V_713 ) ;
V_708 [ 1 ] = F_13 ( V_711 ) ;
V_65 = F_28 ( V_88 , V_714 ,
( void * ) V_708 , sizeof( V_708 ) ) ;
if ( V_65 ) {
F_19 ( L_303 , V_65 ) ;
goto V_709;
}
V_709:
return V_65 ;
}
static T_5
F_226 ( struct V_87 * V_88 , T_5 V_715 ,
T_5 V_716 , T_5 V_717 )
{
T_5 V_65 = 0 ;
V_65 = F_40 ( V_88 , V_718 ,
V_715 ) ;
if ( V_65 ) {
if ( V_65 == - V_80 )
F_3 ( V_5 , L_304 ) ;
else
F_19 ( L_305 , V_65 ) ;
goto V_719;
}
V_65 = F_40 ( V_88 , V_720 ,
V_716 ) ;
if ( V_65 ) {
if ( V_65 == - V_80 )
F_3 ( V_5 , L_306 ) ;
else
F_19 ( L_307 , V_65 ) ;
goto V_719;
}
V_65 = F_40 ( V_88 , V_721 ,
V_717 ) ;
if ( V_65 ) {
if ( V_65 == - V_80 )
F_3 ( V_5 , L_308 ) ;
else
F_19 ( L_309 , V_65 ) ;
goto V_719;
}
V_719:
return V_65 ;
}
static T_5 F_227 ( struct V_89 * V_90 )
{
struct V_87 * V_88 = F_18 ( F_63 ( V_90 ) ) ;
struct V_67 * V_67 ;
T_5 V_722 ;
T_9 V_723 ;
T_5 V_65 = 0 ;
V_65 = F_97 ( V_88 , V_724 ,
& V_722 , sizeof( V_722 ) ) ;
if ( V_65 ) {
F_19 ( L_37 , V_65 ) ;
return V_65 ;
}
V_723 = ( ( char * ) & V_722 ) [ 0 ] ;
F_3 ( V_5 , L_310 , V_723 ) ;
if ( V_723 == 'n' || V_723 == 'a' ) {
V_67 = F_30 ( V_90 ) ;
V_67 -> V_372 [ V_373 ] = & V_725 ;
}
return V_65 ;
}
static T_5 F_228 ( struct V_89 * V_90 )
{
return F_227 ( V_90 ) ;
}
static T_5 F_229 ( struct V_89 * V_90 )
{
struct V_63 * V_64 ;
struct V_66 * V_114 ;
struct V_87 * V_88 ;
T_5 V_726 ;
T_5 V_65 = 0 ;
if ( V_90 -> V_697 )
return V_65 ;
V_64 = F_63 ( V_90 ) ;
V_114 = V_64 -> V_130 ;
V_88 = F_18 ( V_64 ) ;
F_40 ( V_88 , V_566 , 0 ) ;
F_226 ( V_88 , V_727 ,
V_728 , V_729 ) ;
V_726 = V_90 -> V_351 ? V_352 : V_353 ;
V_65 = F_40 ( V_88 , V_354 , V_726 ) ;
if ( V_65 )
goto V_730;
F_3 ( V_5 , L_311 ,
( V_726 ? L_147 : L_148 ) ) ;
V_65 = F_225 ( V_88 , ( V_90 -> V_696 ? 0 : 1 ) , V_731 ) ;
if ( V_65 )
goto V_730;
V_65 = F_37 ( V_114 -> V_67 , V_64 , V_114 -> V_118 ,
NULL , NULL ) ;
if ( V_65 )
goto V_730;
V_65 = F_228 ( V_90 ) ;
if ( V_65 )
goto V_730;
V_90 -> V_697 = true ;
V_730:
return V_65 ;
}
static T_5 F_230 ( struct V_87 * V_88 )
{
F_39 ( V_3 , & V_88 -> V_2 -> V_4 ) ;
return F_229 ( V_88 -> V_404 -> V_405 ) ;
}
static T_5 F_231 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
if ( F_1 ( V_88 -> V_2 ) ) {
F_65 ( V_88 -> V_2 ) ;
F_124 ( 500 ) ;
}
F_111 ( V_90 ) ;
F_55 ( V_3 , & V_88 -> V_2 -> V_4 ) ;
return 0 ;
}
T_5 F_232 ( struct V_63 * V_64 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
T_5 V_65 = 0 ;
F_204 ( & V_90 -> V_698 ) ;
V_65 = F_230 ( V_88 ) ;
F_205 ( & V_90 -> V_698 ) ;
return V_65 ;
}
T_5 F_233 ( struct V_63 * V_64 )
{
struct V_87 * V_88 = F_18 ( V_64 ) ;
struct V_89 * V_90 = V_88 -> V_404 -> V_405 ;
T_5 V_65 = 0 ;
F_204 ( & V_90 -> V_698 ) ;
V_65 = F_231 ( V_88 ) ;
F_205 ( & V_90 -> V_698 ) ;
return V_65 ;
}
T_4 F_234 ( struct V_89 * V_90 , unsigned long V_732 )
{
struct V_1 * V_2 ;
bool V_306 = 0 ;
F_130 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_732 , & V_2 -> V_4 ) )
V_306 ++ ;
}
return V_306 ;
}
static inline bool F_235 ( struct V_672 * V_631 ,
T_2 V_147 )
{
T_2 V_733 ;
F_204 ( & V_631 -> V_675 ) ;
V_733 = V_631 -> V_147 ;
F_205 ( & V_631 -> V_675 ) ;
return V_733 == V_147 ;
}
void F_236 ( struct V_89 * V_90 ,
struct V_1 * V_2 )
{
struct V_672 * V_631 = & V_90 -> V_673 ;
F_204 ( & V_631 -> V_675 ) ;
V_631 -> V_2 = V_2 ;
V_631 -> V_147 = 0 ;
F_205 ( & V_631 -> V_675 ) ;
}
bool F_35 ( struct V_89 * V_90 )
{
struct V_672 * V_631 = & V_90 -> V_673 ;
bool V_734 ;
F_204 ( & V_631 -> V_675 ) ;
V_734 = V_631 -> V_2 != NULL ;
F_205 ( & V_631 -> V_675 ) ;
return V_734 ;
}
int F_237 ( struct V_89 * V_90 ,
T_2 V_147 , T_11 V_349 )
{
struct V_672 * V_631 = & V_90 -> V_673 ;
return F_238 ( V_631 -> V_678 ,
F_235 ( V_631 , V_147 ) , V_349 ) ;
}
