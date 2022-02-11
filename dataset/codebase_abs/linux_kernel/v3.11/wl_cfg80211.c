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
T_1 F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 V_22 ;
V_22 . V_23 = F_7 ( V_20 -> V_24 ) ;
V_22 . V_25 = V_26 ;
V_18 -> V_27 ( & V_22 ) ;
return V_22 . V_28 ;
}
struct V_29 * F_8 ( void * V_30 , int V_31 , T_3 V_32 )
{
struct V_29 * V_33 ;
int V_34 ;
V_33 = (struct V_29 * ) V_30 ;
V_34 = V_31 ;
while ( V_34 >= V_35 ) {
int V_36 = V_33 -> V_36 ;
if ( ( V_33 -> V_37 == V_32 ) && ( V_34 >= ( V_36 + V_35 ) ) )
return V_33 ;
V_33 = (struct V_29 * ) ( ( T_2 * ) V_33 + ( V_36 + V_35 ) ) ;
V_34 -= ( V_36 + V_35 ) ;
}
return NULL ;
}
static bool
F_9 ( T_2 * V_38 , T_2 * * V_39 , T_4 * V_40 ,
T_2 * V_41 , T_4 V_42 , T_2 type )
{
if ( V_38 [ V_43 ] >= V_42 + 1 &&
! memcmp ( & V_38 [ V_44 ] , V_41 , V_42 ) &&
type == V_38 [ V_44 + V_42 ] ) {
return true ;
}
if ( V_39 == NULL )
return false ;
V_38 += V_38 [ V_43 ] + V_35 ;
* V_40 -= ( int ) ( V_38 - * V_39 ) ;
* V_39 = V_38 ;
return false ;
}
static struct V_45 *
F_10 ( T_2 * V_46 , T_4 V_36 )
{
struct V_29 * V_38 ;
while ( ( V_38 = F_8 ( V_46 , V_36 , V_47 ) ) ) {
if ( F_9 ( ( T_2 * ) V_38 , & V_46 , & V_36 ,
V_48 , V_49 , V_50 ) )
return (struct V_45 * ) V_38 ;
}
return NULL ;
}
static struct V_45 *
F_11 ( T_2 * V_46 , T_4 V_36 )
{
struct V_29 * V_38 ;
while ( ( V_38 = F_8 ( V_46 , V_36 , V_47 ) ) ) {
if ( F_9 ( ( T_2 * ) V_38 , & V_46 , & V_36 ,
V_48 , V_49 , V_51 ) )
return (struct V_45 * ) V_38 ;
}
return NULL ;
}
static void F_12 ( struct V_52 * V_32 ,
struct V_53 * V_54 )
{
V_54 -> V_55 = F_13 ( V_32 -> V_55 ) ;
V_54 -> V_36 = F_13 ( V_32 -> V_36 ) ;
V_54 -> V_56 = F_13 ( V_32 -> V_56 ) ;
V_54 -> V_57 = F_13 ( V_32 -> V_57 ) ;
V_54 -> V_58 . V_59 = F_13 ( V_32 -> V_58 . V_59 ) ;
V_54 -> V_58 . V_60 = F_14 ( V_32 -> V_58 . V_60 ) ;
V_54 -> V_61 = F_13 ( V_32 -> V_61 ) ;
memcpy ( V_54 -> V_62 , V_32 -> V_62 , sizeof( V_32 -> V_62 ) ) ;
memcpy ( V_54 -> V_63 , V_32 -> V_63 , sizeof( V_32 -> V_63 ) ) ;
}
static int
F_15 ( struct V_64 * V_65 , struct V_52 * V_32 )
{
int V_66 ;
struct V_53 V_54 ;
F_12 ( V_32 , & V_54 ) ;
F_16 ( V_65 ) ;
V_66 = F_17 ( F_18 ( V_65 ) , L_2 , & V_54 ,
sizeof( V_54 ) ) ;
if ( V_66 )
F_19 ( L_3 , V_66 ) ;
return V_66 ;
}
static T_5
F_20 ( struct V_67 * V_68 , bool V_69 )
{
T_5 V_66 ;
T_4 V_70 ;
if ( V_69 )
V_70 = V_71 | V_72 ;
else
V_70 = 0 ;
V_66 = F_21 ( V_68 , L_4 , V_70 ) ;
if ( V_66 ) {
F_3 ( V_73 , L_5 ,
V_70 , V_66 ) ;
V_66 = 0 ;
} else {
V_66 = F_21 ( V_68 , L_6 , V_69 ) ;
if ( V_66 ) {
F_3 ( V_73 , L_7 ,
V_69 , V_66 ) ;
V_66 = 0 ;
} else
F_3 ( V_73 , L_8 ,
V_69 , V_70 ) ;
}
return V_66 ;
}
static struct V_74 * F_22 ( struct V_75 * V_75 ,
const char * V_76 ,
enum V_77 type ,
T_4 * V_57 ,
struct V_78 * V_79 )
{
F_3 ( V_73 , L_9 , V_76 , type ) ;
switch ( type ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
return F_23 ( - V_87 ) ;
case V_88 :
case V_89 :
case V_90 :
return F_24 ( V_75 , V_76 , type , V_57 , V_79 ) ;
case V_91 :
default:
return F_23 ( - V_92 ) ;
}
}
void F_25 ( struct V_67 * V_68 , int V_93 )
{
T_5 V_66 = 0 ;
if ( F_1 ( V_68 -> V_2 ) ) {
V_66 = F_21 ( V_68 , L_10 , V_93 ) ;
if ( V_66 ) {
F_19 ( L_11 ) ;
return;
}
F_3 ( V_5 , L_12 , V_93 ) ;
}
}
T_5 F_26 ( struct V_94 * V_95 ,
struct V_67 * V_68 , bool V_96 ,
bool V_97 )
{
struct V_98 V_99 ;
struct V_100 * V_101 ;
T_5 V_66 = 0 ;
F_3 ( V_102 , L_13 ) ;
V_101 = V_95 -> V_101 ;
V_95 -> V_101 = NULL ;
if ( F_27 ( & V_95 -> V_103 ) )
F_28 ( & V_95 -> V_103 ) ;
if ( V_97 ) {
F_3 ( V_102 , L_14 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
memset ( V_99 . V_104 , 0xFF , V_105 ) ;
V_99 . V_106 = V_107 ;
V_99 . V_108 = 0 ;
V_99 . V_109 = F_13 ( 1 ) ;
V_99 . V_110 = F_13 ( 1 ) ;
V_99 . V_111 = F_13 ( - 1 ) ;
V_99 . V_112 = F_13 ( - 1 ) ;
V_99 . V_113 = F_13 ( - 1 ) ;
V_99 . V_114 [ 0 ] = F_14 ( - 1 ) ;
V_66 = F_29 ( V_68 , V_115 ,
& V_99 , sizeof( V_99 ) ) ;
if ( V_66 )
F_19 ( L_15 ) ;
}
if ( V_95 -> V_116 ) {
F_3 ( V_102 , L_16 ) ;
V_95 -> V_116 = false ;
if ( ! V_96 )
F_30 ( F_31 ( V_95 ) ) ;
F_25 ( V_68 , 1 ) ;
} else if ( V_101 ) {
F_3 ( V_102 , L_17 ,
V_96 ? L_18 : L_19 ) ;
F_32 ( V_101 , V_96 ) ;
F_25 ( V_68 , 1 ) ;
}
if ( ! F_33 ( V_117 , & V_95 -> V_118 ) )
F_3 ( V_102 , L_20 ) ;
return V_66 ;
}
static
int F_34 ( struct V_75 * V_75 , struct V_74 * V_119 )
{
struct V_94 * V_95 = F_35 ( V_75 ) ;
struct V_64 * V_65 = V_119 -> V_120 ;
if ( F_36 ( V_95 ) )
return - V_121 ;
if ( V_65 ) {
if ( F_2 ( V_117 , & V_95 -> V_118 ) &&
V_95 -> V_122 . V_68 == F_18 ( V_65 ) )
F_26 ( V_95 , F_18 ( V_65 ) ,
true , true ) ;
F_21 ( F_18 ( V_65 ) , L_10 , 1 ) ;
}
switch ( V_119 -> V_123 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
return - V_87 ;
case V_88 :
case V_89 :
case V_90 :
return F_37 ( V_75 , V_119 ) ;
case V_91 :
default:
return - V_92 ;
}
return - V_87 ;
}
static T_5
F_38 ( struct V_75 * V_75 , struct V_64 * V_65 ,
enum V_77 type , T_4 * V_57 ,
struct V_78 * V_79 )
{
struct V_94 * V_95 = F_35 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_1 * V_2 = V_68 -> V_2 ;
T_5 V_124 = 0 ;
T_5 V_125 = 0 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_21 , V_65 , type ) ;
switch ( type ) {
case V_85 :
case V_84 :
F_19 ( L_22 ,
type ) ;
return - V_87 ;
case V_80 :
V_2 -> V_70 = V_126 ;
V_124 = 0 ;
break;
case V_81 :
if ( ( V_2 -> V_119 . V_123 == V_88 ) ||
( V_2 -> V_119 . V_123 == V_89 ) ) {
F_3 ( V_73 , L_23 ) ;
return 0 ;
}
V_2 -> V_70 = V_127 ;
V_124 = 1 ;
break;
case V_82 :
case V_89 :
V_2 -> V_70 = V_128 ;
V_125 = 1 ;
break;
default:
V_66 = - V_92 ;
goto V_129;
}
if ( V_125 ) {
if ( type == V_89 ) {
F_3 ( V_5 , L_24 ) ;
V_66 = F_39 ( V_95 , V_130 ) ;
}
if ( ! V_66 ) {
F_40 ( V_131 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_25 ) ;
}
} else {
V_66 = F_41 ( V_68 , V_132 , V_124 ) ;
if ( V_66 ) {
F_19 ( L_26 , V_66 ) ;
V_66 = - V_133 ;
goto V_129;
}
F_3 ( V_5 , L_27 , ( V_2 -> V_70 == V_126 ) ?
L_28 : L_29 ) ;
}
V_65 -> V_134 -> V_123 = type ;
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void F_42 ( struct V_94 * V_95 ,
struct V_98 * V_99 ,
struct V_100 * V_135 )
{
T_4 V_136 ;
T_4 V_137 ;
T_5 V_138 ;
T_5 V_13 ;
T_1 V_139 ;
char * V_140 ;
struct V_141 V_142 ;
memset ( V_99 -> V_104 , 0xFF , V_105 ) ;
V_99 -> V_106 = V_107 ;
V_99 -> V_108 = 0 ;
V_99 -> V_109 = 0 ;
V_99 -> V_110 = F_13 ( - 1 ) ;
V_99 -> V_111 = F_13 ( - 1 ) ;
V_99 -> V_112 = F_13 ( - 1 ) ;
V_99 -> V_113 = F_13 ( - 1 ) ;
memset ( & V_99 -> V_142 , 0 , sizeof( V_99 -> V_142 ) ) ;
if ( ! V_135 )
return;
V_136 = V_135 -> V_136 ;
V_137 = V_135 -> V_137 ;
F_3 ( V_102 , L_31 ,
V_137 ) ;
if ( V_137 > 0 ) {
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ ) {
V_139 = F_6 ( & V_95 -> V_18 ,
V_135 -> V_143 [ V_138 ] ) ;
F_3 ( V_102 , L_32 ,
V_135 -> V_143 [ V_138 ] -> V_144 , V_139 ) ;
V_99 -> V_114 [ V_138 ] = F_14 ( V_139 ) ;
}
} else {
F_3 ( V_102 , L_33 ) ;
}
F_3 ( V_102 , L_34 , V_136 ) ;
if ( V_136 > 0 ) {
V_13 = F_43 ( struct V_98 , V_114 ) +
V_137 * sizeof( T_1 ) ;
V_13 = F_44 ( V_13 , sizeof( T_4 ) ) ;
V_140 = ( char * ) V_99 + V_13 ;
for ( V_138 = 0 ; V_138 < V_136 ; V_138 ++ ) {
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_145 =
F_13 ( V_135 -> V_146 [ V_138 ] . V_147 ) ;
memcpy ( V_142 . V_148 , V_135 -> V_146 [ V_138 ] . V_149 ,
V_135 -> V_146 [ V_138 ] . V_147 ) ;
if ( ! V_142 . V_145 )
F_3 ( V_102 , L_35 , V_138 ) ;
else
F_3 ( V_102 , L_36 ,
V_138 , V_142 . V_148 , V_142 . V_145 ) ;
memcpy ( V_140 , & V_142 , sizeof( V_142 ) ) ;
V_140 += sizeof( V_142 ) ;
}
} else {
F_3 ( V_102 , L_37 , V_135 -> V_146 ) ;
if ( ( V_135 -> V_146 ) && V_135 -> V_146 -> V_147 ) {
F_3 ( V_102 , L_38 ,
V_99 -> V_142 . V_148 ,
V_135 -> V_146 -> V_147 ) ;
V_99 -> V_142 . V_145 =
F_13 ( V_135 -> V_146 -> V_147 ) ;
memcpy ( & V_99 -> V_142 . V_148 , V_135 -> V_146 -> V_149 ,
V_135 -> V_146 -> V_147 ) ;
}
}
V_99 -> V_109 =
F_13 ( ( V_136 << V_150 ) |
( V_137 & V_151 ) ) ;
}
static T_5
F_45 ( struct V_94 * V_95 , struct V_67 * V_68 ,
struct V_100 * V_135 , T_1 V_152 )
{
T_5 V_153 = V_154 +
F_43 ( struct V_155 , V_99 ) ;
struct V_155 * V_79 ;
T_5 V_66 = 0 ;
F_3 ( V_102 , L_39 ) ;
if ( V_135 != NULL ) {
V_153 += sizeof( T_4 ) * ( ( V_135 -> V_137 + 1 ) / 2 ) ;
V_153 += sizeof( struct V_156 ) * V_135 -> V_136 ;
}
V_79 = F_46 ( V_153 , V_157 ) ;
if ( ! V_79 ) {
V_66 = - V_158 ;
goto exit;
}
F_47 ( V_153 + sizeof( L_40 ) >= V_159 ) ;
F_42 ( V_95 , & V_79 -> V_99 , V_135 ) ;
V_79 -> V_160 = F_13 ( V_161 ) ;
V_79 -> V_152 = F_14 ( V_152 ) ;
V_79 -> V_162 = F_14 ( 0x1234 ) ;
V_66 = F_48 ( V_68 , L_40 , V_79 , V_153 ) ;
if ( V_66 ) {
if ( V_66 == - V_121 )
F_3 ( V_5 , L_41 ) ;
else
F_19 ( L_42 , V_66 ) ;
}
F_49 ( V_79 ) ;
exit:
return V_66 ;
}
static T_5
F_50 ( struct V_94 * V_95 , struct V_75 * V_75 ,
struct V_67 * V_68 , struct V_100 * V_135 )
{
T_5 V_66 ;
T_4 V_163 ;
struct V_164 * V_165 ;
struct V_122 * V_166 = & V_95 -> V_122 ;
F_3 ( V_102 , L_13 ) ;
V_166 -> V_68 = V_68 ;
V_166 -> V_75 = V_75 ;
V_166 -> V_167 = V_168 ;
V_163 = V_95 -> V_169 ? 0 : 1 ;
V_66 = F_41 ( V_68 , V_170 ,
V_163 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
return V_66 ;
}
F_25 ( V_68 , 0 ) ;
V_165 = (struct V_164 * ) V_95 -> V_122 . V_171 ;
V_165 -> V_160 = 0 ;
V_165 -> V_172 = 0 ;
V_165 -> V_31 = V_173 ;
V_66 = V_166 -> V_174 ( V_95 , V_68 , V_135 , V_175 ) ;
if ( V_66 )
F_25 ( V_68 , 1 ) ;
return V_66 ;
}
static T_5
F_51 ( struct V_75 * V_75 , struct V_1 * V_2 ,
struct V_100 * V_135 ,
struct V_176 * V_177 )
{
struct V_67 * V_68 = V_2 -> V_68 ;
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_176 * V_146 ;
struct V_178 * V_179 = & V_95 -> V_180 ;
T_4 V_163 ;
bool V_181 ;
bool V_182 ;
T_5 V_66 ;
T_4 V_145 ;
F_3 ( V_102 , L_43 ) ;
if ( F_2 ( V_117 , & V_95 -> V_118 ) ) {
F_19 ( L_44 , V_95 -> V_118 ) ;
return - V_133 ;
}
if ( F_2 ( V_183 , & V_95 -> V_118 ) ) {
F_19 ( L_45 ,
V_95 -> V_118 ) ;
return - V_133 ;
}
if ( F_2 ( V_184 , & V_95 -> V_118 ) ) {
F_19 ( L_46 ,
V_95 -> V_118 ) ;
return - V_133 ;
}
if ( F_2 ( V_185 , & V_68 -> V_2 -> V_4 ) ) {
F_19 ( L_47 , V_68 -> V_2 -> V_4 ) ;
return - V_133 ;
}
if ( V_2 == V_95 -> V_186 . V_187 [ V_188 ] . V_2 )
V_2 = V_95 -> V_186 . V_187 [ V_189 ] . V_2 ;
F_53 ( & V_95 -> V_103 , V_190 +
V_191 * V_192 / 1000 ) ;
V_181 = false ;
if ( V_135 ) {
V_146 = V_135 -> V_146 ;
V_181 = true ;
} else {
V_146 = V_177 ;
}
V_95 -> V_101 = V_135 ;
F_40 ( V_117 , & V_95 -> V_118 ) ;
if ( V_181 ) {
V_95 -> V_122 . V_174 = F_45 ;
V_66 = F_54 ( V_75 , V_135 , V_2 ) ;
if ( V_66 )
goto V_193;
V_66 = F_50 ( V_95 , V_75 , V_2 -> V_68 , V_135 ) ;
if ( V_66 )
goto V_193;
} else {
F_3 ( V_102 , L_48 ,
V_146 -> V_149 , V_146 -> V_147 ) ;
memset ( & V_179 -> V_142 , 0 , sizeof( V_179 -> V_142 ) ) ;
V_145 = F_55 ( T_2 , sizeof( V_179 -> V_142 . V_148 ) , V_146 -> V_147 ) ;
V_179 -> V_142 . V_145 = F_13 ( 0 ) ;
V_182 = false ;
if ( V_145 ) {
memcpy ( V_179 -> V_142 . V_148 , V_146 -> V_149 , V_145 ) ;
V_179 -> V_142 . V_145 = F_13 ( V_145 ) ;
V_182 = true ;
} else
F_3 ( V_102 , L_49 ) ;
V_163 = V_95 -> V_169 ? 0 : 1 ;
V_66 = F_41 ( V_68 , V_170 ,
V_163 ) ;
if ( V_66 ) {
F_19 ( L_50 , V_66 ) ;
goto V_193;
}
F_25 ( V_68 , 0 ) ;
V_66 = F_29 ( V_68 , V_115 ,
& V_179 -> V_142 , sizeof( V_179 -> V_142 ) ) ;
if ( V_66 ) {
if ( V_66 == - V_121 )
F_3 ( V_5 , L_51 ,
V_179 -> V_142 . V_148 ) ;
else
F_19 ( L_52 , V_66 ) ;
F_25 ( V_68 , 1 ) ;
goto V_193;
}
}
return 0 ;
V_193:
F_56 ( V_117 , & V_95 -> V_118 ) ;
if ( F_27 ( & V_95 -> V_103 ) )
F_28 ( & V_95 -> V_103 ) ;
V_95 -> V_101 = NULL ;
return V_66 ;
}
static T_5
F_57 ( struct V_75 * V_75 , struct V_100 * V_135 )
{
struct V_1 * V_2 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
V_2 = F_58 ( V_135 -> V_119 , struct V_1 , V_119 ) ;
if ( ! F_1 ( V_2 ) )
return - V_194 ;
V_66 = F_51 ( V_75 , V_2 , V_135 , NULL ) ;
if ( V_66 )
F_19 ( L_53 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_59 ( struct V_64 * V_65 , T_4 V_195 )
{
T_5 V_66 = 0 ;
V_66 = F_21 ( F_18 ( V_65 ) , L_54 ,
V_195 ) ;
if ( V_66 )
F_19 ( L_55 , V_66 ) ;
return V_66 ;
}
static T_5 F_60 ( struct V_64 * V_65 , T_4 V_196 )
{
T_5 V_66 = 0 ;
V_66 = F_21 ( F_18 ( V_65 ) , L_56 ,
V_196 ) ;
if ( V_66 )
F_19 ( L_55 , V_66 ) ;
return V_66 ;
}
static T_5 F_61 ( struct V_64 * V_65 , T_4 V_197 , bool V_198 )
{
T_5 V_66 = 0 ;
T_4 V_199 = ( V_198 ? V_200 : V_201 ) ;
V_66 = F_41 ( F_18 ( V_65 ) , V_199 , V_197 ) ;
if ( V_66 ) {
F_19 ( L_57 , V_199 , V_66 ) ;
return V_66 ;
}
return V_66 ;
}
static T_5 F_62 ( struct V_75 * V_75 , T_4 V_202 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_64 * V_65 = F_63 ( V_95 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( V_202 & V_203 &&
( V_95 -> V_204 -> V_195 != V_75 -> V_195 ) ) {
V_95 -> V_204 -> V_195 = V_75 -> V_195 ;
V_66 = F_59 ( V_65 , V_95 -> V_204 -> V_195 ) ;
if ( ! V_66 )
goto V_129;
}
if ( V_202 & V_205 &&
( V_95 -> V_204 -> V_196 != V_75 -> V_196 ) ) {
V_95 -> V_204 -> V_196 = V_75 -> V_196 ;
V_66 = F_60 ( V_65 , V_95 -> V_204 -> V_196 ) ;
if ( ! V_66 )
goto V_129;
}
if ( V_202 & V_206
&& ( V_95 -> V_204 -> V_207 != V_75 -> V_207 ) ) {
V_95 -> V_204 -> V_207 = V_75 -> V_207 ;
V_66 = F_61 ( V_65 , V_95 -> V_204 -> V_207 , true ) ;
if ( ! V_66 )
goto V_129;
}
if ( V_202 & V_208
&& ( V_95 -> V_204 -> V_209 != V_75 -> V_209 ) ) {
V_95 -> V_204 -> V_209 = V_75 -> V_209 ;
V_66 = F_61 ( V_65 , V_95 -> V_204 -> V_209 , false ) ;
if ( ! V_66 )
goto V_129;
}
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void F_64 ( struct V_210 * V_211 )
{
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_52 ( V_2 -> V_119 . V_75 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_2 ( V_212 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_58 ) ;
V_66 = F_29 ( V_2 -> V_68 ,
V_213 , NULL , 0 ) ;
if ( V_66 ) {
F_19 ( L_59 , V_66 ) ;
F_66 ( V_2 -> V_119 . V_120 , 0 ,
NULL , 0 , V_157 ) ;
}
F_56 ( V_212 , & V_2 -> V_4 ) ;
}
F_56 ( V_185 , & V_2 -> V_4 ) ;
F_56 ( V_184 , & V_95 -> V_118 ) ;
F_67 ( V_2 , V_214 , 0 ) ;
F_3 ( V_73 , L_30 ) ;
}
static T_5
F_68 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_215 * V_79 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_217 V_218 ;
T_6 V_219 = 0 ;
T_5 V_66 = 0 ;
T_5 V_220 = 0 ;
T_5 V_221 ;
T_1 V_139 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( V_79 -> V_149 )
F_3 ( V_222 , L_60 , V_79 -> V_149 ) ;
else {
F_3 ( V_222 , L_61 ) ;
return - V_87 ;
}
F_40 ( V_185 , & V_68 -> V_2 -> V_4 ) ;
if ( V_79 -> V_104 )
F_3 ( V_222 , L_62 , V_79 -> V_104 ) ;
else
F_3 ( V_222 , L_63 ) ;
if ( V_79 -> V_223 . V_224 )
F_3 ( V_222 , L_64 ,
V_79 -> V_223 . V_224 -> V_24 ) ;
else
F_3 ( V_222 , L_65 ) ;
if ( V_79 -> V_225 )
F_3 ( V_222 , L_66 ) ;
else
F_3 ( V_222 , L_67 ) ;
if ( V_79 -> V_38 && V_79 -> V_226 )
F_3 ( V_222 , L_68 , V_79 -> V_226 ) ;
else
F_3 ( V_222 , L_69 ) ;
if ( V_79 -> V_227 )
F_3 ( V_222 , L_70 ,
V_79 -> V_227 ) ;
else
F_3 ( V_222 , L_71 ) ;
if ( V_79 -> V_228 )
F_3 ( V_222 , L_72 , V_79 -> V_228 ) ;
else
F_3 ( V_222 , L_73 ) ;
if ( V_79 -> V_229 )
F_3 ( V_222 , L_74 ) ;
else
F_3 ( V_222 , L_75 ) ;
if ( V_79 -> V_229 )
V_220 |= V_230 ;
V_66 = F_21 ( V_68 , L_76 , V_220 ) ;
if ( V_66 ) {
F_19 ( L_77 , V_66 ) ;
goto V_129;
}
if ( V_79 -> V_227 )
V_221 = V_79 -> V_227 ;
else
V_221 = 100 ;
V_66 = F_41 ( V_68 , V_231 , V_221 ) ;
if ( V_66 ) {
F_19 ( L_78 , V_66 ) ;
goto V_129;
}
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
V_216 -> V_149 . V_145 = F_55 ( T_4 , V_79 -> V_147 , 32 ) ;
memcpy ( V_216 -> V_149 . V_148 , V_79 -> V_149 , V_216 -> V_149 . V_145 ) ;
memcpy ( V_218 . V_142 . V_148 , V_79 -> V_149 , V_216 -> V_149 . V_145 ) ;
V_218 . V_142 . V_145 = F_13 ( V_216 -> V_149 . V_145 ) ;
V_219 = sizeof( V_218 . V_142 ) ;
if ( V_79 -> V_104 ) {
memcpy ( V_218 . V_99 . V_104 , V_79 -> V_104 , V_105 ) ;
V_219 = sizeof( V_218 . V_142 ) +
V_232 ;
memcpy ( V_216 -> V_104 , V_79 -> V_104 , V_105 ) ;
} else {
memset ( V_218 . V_99 . V_104 , 0xFF , V_105 ) ;
memset ( V_216 -> V_104 , 0 , V_105 ) ;
}
if ( V_79 -> V_223 . V_224 ) {
T_4 V_233 ;
V_95 -> V_234 =
F_7 (
V_79 -> V_223 . V_224 -> V_24 ) ;
if ( V_79 -> V_225 ) {
V_139 = F_6 ( & V_95 -> V_18 ,
V_79 -> V_223 . V_224 ) ;
V_218 . V_99 . V_235 [ 0 ] =
F_14 ( V_139 ) ;
V_218 . V_99 . V_236 = F_13 ( 1 ) ;
V_219 += sizeof( V_218 . V_99 ) ;
}
V_233 = V_95 -> V_234 ;
V_66 = F_41 ( V_68 , V_237 ,
V_233 ) ;
if ( V_66 ) {
F_19 ( L_79 , V_66 ) ;
goto V_129;
}
} else
V_95 -> V_234 = 0 ;
V_95 -> V_238 = false ;
V_66 = F_29 ( V_68 , V_239 ,
& V_218 , V_219 ) ;
if ( V_66 ) {
F_19 ( L_80 , V_66 ) ;
goto V_129;
}
V_129:
if ( V_66 )
F_56 ( V_185 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_69 ( struct V_75 * V_75 , struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
F_65 ( V_68 -> V_2 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_70 ( struct V_64 * V_65 ,
struct V_240 * V_241 )
{
struct V_210 * V_216 = F_71 ( V_65 ) ;
struct V_242 * V_243 ;
T_5 V_244 = 0 ;
T_5 V_66 = 0 ;
if ( V_241 -> V_245 . V_246 & V_247 )
V_244 = V_248 | V_249 ;
else if ( V_241 -> V_245 . V_246 & V_250 )
V_244 = V_251 | V_252 ;
else
V_244 = V_253 ;
F_3 ( V_222 , L_81 , V_244 ) ;
V_66 = F_72 ( F_18 ( V_65 ) , L_82 , V_244 ) ;
if ( V_66 ) {
F_19 ( L_83 , V_66 ) ;
return V_66 ;
}
V_243 = & V_216 -> V_243 ;
V_243 -> V_246 = V_241 -> V_245 . V_246 ;
return V_66 ;
}
static T_5 F_73 ( struct V_64 * V_65 ,
struct V_240 * V_241 )
{
struct V_210 * V_216 = F_71 ( V_65 ) ;
struct V_242 * V_243 ;
T_5 V_244 = 0 ;
T_5 V_66 = 0 ;
switch ( V_241 -> V_254 ) {
case V_255 :
V_244 = 0 ;
F_3 ( V_222 , L_84 ) ;
break;
case V_256 :
V_244 = 1 ;
F_3 ( V_222 , L_85 ) ;
break;
case V_257 :
V_244 = 2 ;
F_3 ( V_222 , L_86 ) ;
break;
case V_258 :
F_3 ( V_222 , L_87 ) ;
default:
V_244 = 2 ;
F_19 ( L_88 , V_241 -> V_254 ) ;
break;
}
V_66 = F_72 ( F_18 ( V_65 ) , L_89 , V_244 ) ;
if ( V_66 ) {
F_19 ( L_90 , V_66 ) ;
return V_66 ;
}
V_243 = & V_216 -> V_243 ;
V_243 -> V_254 = V_241 -> V_254 ;
return V_66 ;
}
static T_5
F_74 ( struct V_64 * V_65 ,
struct V_240 * V_241 )
{
struct V_210 * V_216 = F_71 ( V_65 ) ;
struct V_242 * V_243 ;
T_5 V_259 = 0 ;
T_5 V_260 = 0 ;
T_5 V_66 = 0 ;
if ( V_241 -> V_245 . V_261 ) {
switch ( V_241 -> V_245 . V_262 [ 0 ] ) {
case V_263 :
case V_264 :
V_259 = V_230 ;
break;
case V_265 :
V_259 = V_266 ;
break;
case V_267 :
V_259 = V_268 ;
break;
case V_269 :
V_259 = V_268 ;
break;
default:
F_19 ( L_91 ,
V_241 -> V_245 . V_262 [ 0 ] ) ;
return - V_92 ;
}
}
if ( V_241 -> V_245 . V_270 ) {
switch ( V_241 -> V_245 . V_270 ) {
case V_263 :
case V_264 :
V_260 = V_230 ;
break;
case V_265 :
V_260 = V_266 ;
break;
case V_267 :
V_260 = V_268 ;
break;
case V_269 :
V_260 = V_268 ;
break;
default:
F_19 ( L_92 ,
V_241 -> V_245 . V_270 ) ;
return - V_92 ;
}
}
F_3 ( V_222 , L_93 , V_259 , V_260 ) ;
if ( F_11 ( V_241 -> V_38 , V_241 -> V_226 ) && ! V_259 && ! V_260 &&
V_241 -> V_229 )
V_259 = V_268 ;
V_66 = F_72 ( F_18 ( V_65 ) , L_76 , V_259 | V_260 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
return V_66 ;
}
V_243 = & V_216 -> V_243 ;
V_243 -> V_271 = V_241 -> V_245 . V_262 [ 0 ] ;
V_243 -> V_270 = V_241 -> V_245 . V_270 ;
return V_66 ;
}
static T_5
F_75 ( struct V_64 * V_65 , struct V_240 * V_241 )
{
struct V_210 * V_216 = F_71 ( V_65 ) ;
struct V_242 * V_243 ;
T_5 V_244 = 0 ;
T_5 V_66 = 0 ;
if ( V_241 -> V_245 . V_272 ) {
V_66 = F_76 ( F_18 ( V_65 ) ,
L_82 , & V_244 ) ;
if ( V_66 ) {
F_19 ( L_94 , V_66 ) ;
return V_66 ;
}
if ( V_244 & ( V_248 | V_249 ) ) {
switch ( V_241 -> V_245 . V_273 [ 0 ] ) {
case V_274 :
V_244 = V_249 ;
break;
case V_275 :
V_244 = V_248 ;
break;
default:
F_19 ( L_92 ,
V_241 -> V_245 . V_270 ) ;
return - V_92 ;
}
} else if ( V_244 & ( V_251 | V_252 ) ) {
switch ( V_241 -> V_245 . V_273 [ 0 ] ) {
case V_274 :
V_244 = V_252 ;
break;
case V_275 :
V_244 = V_251 ;
break;
default:
F_19 ( L_92 ,
V_241 -> V_245 . V_270 ) ;
return - V_92 ;
}
}
F_3 ( V_222 , L_95 , V_244 ) ;
V_66 = F_72 ( F_18 ( V_65 ) ,
L_82 , V_244 ) ;
if ( V_66 ) {
F_19 ( L_96 , V_66 ) ;
return V_66 ;
}
}
V_243 = & V_216 -> V_243 ;
V_243 -> V_276 = V_241 -> V_245 . V_273 [ 0 ] ;
return V_66 ;
}
static T_5
F_77 ( struct V_64 * V_65 ,
struct V_240 * V_241 )
{
struct V_210 * V_216 = F_71 ( V_65 ) ;
struct V_242 * V_243 ;
struct V_52 V_32 ;
T_5 V_244 ;
T_5 V_66 = 0 ;
F_3 ( V_222 , L_97 , V_241 -> V_277 ) ;
if ( V_241 -> V_277 == 0 )
return 0 ;
V_243 = & V_216 -> V_243 ;
F_3 ( V_222 , L_98 ,
V_243 -> V_246 , V_243 -> V_271 ) ;
if ( V_243 -> V_246 & ( V_247 | V_250 ) )
return 0 ;
if ( ! ( V_243 -> V_271 &
( V_263 | V_264 ) ) )
return 0 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_36 = ( T_4 ) V_241 -> V_277 ;
V_32 . V_55 = ( T_4 ) V_241 -> V_278 ;
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_99 , V_32 . V_36 ) ;
return - V_92 ;
}
memcpy ( V_32 . V_62 , V_241 -> V_32 , V_32 . V_36 ) ;
V_32 . V_57 = V_279 ;
switch ( V_243 -> V_271 ) {
case V_263 :
V_32 . V_56 = V_280 ;
break;
case V_264 :
V_32 . V_56 = V_281 ;
break;
default:
F_19 ( L_100 ,
V_241 -> V_245 . V_262 [ 0 ] ) ;
return - V_92 ;
}
F_3 ( V_222 , L_101 ,
V_32 . V_36 , V_32 . V_55 , V_32 . V_56 ) ;
F_3 ( V_222 , L_102 , V_32 . V_62 ) ;
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
return V_66 ;
if ( V_243 -> V_254 == V_256 ) {
F_3 ( V_222 , L_103 ) ;
V_244 = V_282 ;
V_66 = F_72 ( F_18 ( V_65 ) , L_89 , V_244 ) ;
if ( V_66 )
F_19 ( L_90 , V_66 ) ;
}
return V_66 ;
}
static
enum V_283 F_78 ( struct V_67 * V_68 ,
enum V_283 type )
{
T_4 V_284 ;
if ( type == V_257 ) {
V_284 = F_79 ( V_68 ) >> 4 ;
switch ( V_284 ) {
case 43236 :
F_3 ( V_222 , L_104 ) ;
return V_255 ;
default:
break;
}
}
return type ;
}
static T_5
F_80 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_240 * V_241 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_19 * V_224 = V_241 -> V_234 ;
struct V_217 V_218 ;
T_6 V_219 ;
struct V_29 * V_285 ;
struct V_45 * V_286 ;
void * V_38 ;
T_4 V_226 ;
struct V_287 * V_288 ;
T_1 V_139 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( ! V_241 -> V_149 ) {
F_19 ( L_105 ) ;
return - V_87 ;
}
if ( V_68 -> V_2 == V_95 -> V_186 . V_187 [ V_189 ] . V_2 ) {
V_38 = NULL ;
V_226 = 0 ;
V_286 = F_10 ( ( T_2 * ) V_241 -> V_38 , V_241 -> V_226 ) ;
if ( V_286 ) {
V_38 = V_286 ;
V_226 = V_286 -> V_36 + V_35 ;
} else {
V_285 = F_8 ( ( T_2 * ) V_241 -> V_38 , V_241 -> V_226 ,
V_289 ) ;
if ( V_285 ) {
V_38 = V_285 ;
V_226 = V_285 -> V_36 + V_35 ;
}
}
F_48 ( V_68 , L_106 , V_38 , V_226 ) ;
}
V_66 = F_81 ( V_68 -> V_2 , V_290 ,
V_241 -> V_38 , V_241 -> V_226 ) ;
if ( V_66 )
F_19 ( L_107 ) ;
else
F_3 ( V_73 , L_108 ) ;
F_40 ( V_185 , & V_68 -> V_2 -> V_4 ) ;
if ( V_224 ) {
V_95 -> V_234 =
F_7 ( V_224 -> V_24 ) ;
V_139 = F_6 ( & V_95 -> V_18 , V_224 ) ;
F_3 ( V_222 , L_109 ,
V_95 -> V_234 , V_224 -> V_24 , V_139 ) ;
} else {
V_95 -> V_234 = 0 ;
V_139 = 0 ;
}
F_3 ( V_5 , L_110 , V_241 -> V_38 , V_241 -> V_226 ) ;
V_66 = F_70 ( V_65 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_111 , V_66 ) ;
goto V_129;
}
V_241 -> V_254 = F_78 ( V_68 , V_241 -> V_254 ) ;
V_66 = F_73 ( V_65 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_112 , V_66 ) ;
goto V_129;
}
V_66 = F_74 ( V_65 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_113 , V_66 ) ;
goto V_129;
}
V_66 = F_75 ( V_65 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_114 , V_66 ) ;
goto V_129;
}
V_66 = F_77 ( V_65 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_115 , V_66 ) ;
goto V_129;
}
V_216 -> V_149 . V_145 = F_55 ( T_4 , ( T_4 ) sizeof( V_216 -> V_149 . V_148 ) ,
( T_4 ) V_241 -> V_147 ) ;
memcpy ( & V_216 -> V_149 . V_148 , V_241 -> V_149 , V_216 -> V_149 . V_145 ) ;
if ( V_216 -> V_149 . V_145 < V_291 ) {
V_216 -> V_149 . V_148 [ V_216 -> V_149 . V_145 ] = 0 ;
F_3 ( V_222 , L_116 , V_216 -> V_149 . V_148 ,
V_216 -> V_149 . V_145 ) ;
}
V_219 = F_43 ( struct V_287 , V_292 ) +
F_43 ( struct V_293 , V_235 ) ;
if ( V_95 -> V_234 )
V_219 += sizeof( T_1 ) ;
V_288 = F_46 ( V_219 , V_157 ) ;
if ( V_288 == NULL ) {
V_66 = - V_158 ;
goto V_129;
}
V_288 -> V_142 . V_145 = F_13 ( V_216 -> V_149 . V_145 ) ;
memcpy ( & V_288 -> V_142 . V_148 , V_241 -> V_149 ,
V_216 -> V_149 . V_145 ) ;
V_288 -> V_294 . V_111 =
F_13 ( V_295 ) ;
V_288 -> V_294 . V_112 =
F_13 ( V_296 ) ;
V_288 -> V_294 . V_108 = - 1 ;
V_288 -> V_294 . V_110 =
F_13 ( V_295 /
V_297 ) ;
V_288 -> V_294 . V_113 = F_13 ( - 1 ) ;
if ( V_241 -> V_104 )
memcpy ( & V_288 -> V_292 . V_104 , V_241 -> V_104 , V_105 ) ;
else
memset ( & V_288 -> V_292 . V_104 , 0xFF , V_105 ) ;
if ( V_95 -> V_234 ) {
V_288 -> V_292 . V_236 = F_13 ( 1 ) ;
V_288 -> V_292 . V_235 [ 0 ] =
F_14 ( V_139 ) ;
}
V_66 = F_17 ( V_68 , L_117 , V_288 ,
V_219 ) ;
F_49 ( V_288 ) ;
if ( ! V_66 )
goto V_129;
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
V_219 = sizeof( V_218 . V_142 ) ;
memcpy ( & V_218 . V_142 . V_148 , V_241 -> V_149 , V_216 -> V_149 . V_145 ) ;
V_218 . V_142 . V_145 = F_13 ( V_216 -> V_149 . V_145 ) ;
if ( V_241 -> V_104 )
memcpy ( V_218 . V_99 . V_104 , V_241 -> V_104 , V_105 ) ;
else
memset ( V_218 . V_99 . V_104 , 0xFF , V_105 ) ;
if ( V_95 -> V_234 ) {
V_218 . V_99 . V_235 [ 0 ] = F_14 ( V_139 ) ;
V_218 . V_99 . V_236 = F_13 ( 1 ) ;
V_219 += sizeof( V_218 . V_99 ) ;
}
V_66 = F_29 ( V_68 , V_239 ,
& V_218 , V_219 ) ;
if ( V_66 )
F_19 ( L_118 , V_66 ) ;
V_129:
if ( V_66 )
F_56 ( V_185 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_82 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_1 V_298 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_299 V_300 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_119 , V_298 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
F_56 ( V_212 , & V_68 -> V_2 -> V_4 ) ;
memcpy ( & V_300 . V_63 , & V_216 -> V_104 , V_105 ) ;
V_300 . V_244 = F_13 ( V_298 ) ;
V_66 = F_29 ( V_68 , V_213 ,
& V_300 , sizeof( V_300 ) ) ;
if ( V_66 )
F_19 ( L_42 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_83 ( struct V_75 * V_75 , struct V_74 * V_119 ,
enum V_301 type , T_5 V_302 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_64 * V_65 = F_63 ( V_95 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_1 V_303 ;
T_5 V_66 = 0 ;
T_5 V_304 = 0 ;
T_5 V_305 = F_84 ( V_302 ) ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
switch ( type ) {
case V_306 :
break;
case V_307 :
case V_308 :
if ( V_305 < 0 ) {
F_19 ( L_120 ) ;
V_66 = - V_92 ;
goto V_129;
}
break;
}
V_304 = V_309 << 16 ;
V_66 = F_41 ( V_68 , V_310 , V_304 ) ;
if ( V_66 )
F_19 ( L_121 , V_66 ) ;
if ( V_305 > 0xffff )
V_303 = 0xffff ;
else
V_303 = ( T_1 ) V_305 ;
V_66 = F_21 ( V_68 , L_122 ,
( T_5 ) F_5 ( V_303 ) ) ;
if ( V_66 )
F_19 ( L_123 , V_66 ) ;
V_95 -> V_204 -> V_311 = V_305 ;
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_85 ( struct V_75 * V_75 ,
struct V_74 * V_119 ,
T_5 * V_305 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( F_63 ( V_95 ) ) ;
T_5 V_312 ;
T_2 V_313 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
V_66 = F_86 ( V_68 , L_122 , & V_312 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
goto V_129;
}
V_313 = ( T_2 ) ( V_312 & ~ V_314 ) ;
* V_305 = ( T_5 ) F_4 ( V_313 ) ;
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_87 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 V_278 , bool V_315 , bool V_316 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_4 V_55 ;
T_4 V_220 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_222 , L_124 , V_278 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
V_66 = F_76 ( V_68 , L_76 , & V_220 ) ;
if ( V_66 ) {
F_19 ( L_125 , V_66 ) ;
goto V_129;
}
if ( V_220 & V_230 ) {
V_55 = V_278 ;
V_66 = F_41 ( V_68 ,
V_317 , V_55 ) ;
if ( V_66 )
F_19 ( L_42 , V_66 ) ;
}
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_88 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 V_278 , const T_2 * V_318 , struct V_319 * V_79 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_66 = 0 ;
T_2 V_320 [ 8 ] ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_55 = ( T_4 ) V_278 ;
if ( ! F_89 ( V_318 ) )
memcpy ( ( char * ) & V_32 . V_63 , ( void * ) V_318 , V_105 ) ;
V_32 . V_36 = ( T_4 ) V_79 -> V_277 ;
if ( V_32 . V_36 == 0 ) {
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
F_19 ( L_126 , V_66 ) ;
} else {
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_127 , V_32 . V_36 ) ;
return - V_92 ;
}
F_3 ( V_222 , L_128 , V_32 . V_55 ) ;
memcpy ( V_32 . V_62 , V_79 -> V_32 , V_32 . V_36 ) ;
if ( ( V_68 -> V_2 -> V_70 != V_128 ) &&
( V_79 -> V_321 == V_265 ) ) {
F_3 ( V_222 , L_129 ) ;
memcpy ( V_320 , & V_32 . V_62 [ 24 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 24 ] , & V_32 . V_62 [ 16 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 16 ] , V_320 , sizeof( V_320 ) ) ;
}
if ( V_79 -> V_322 && V_79 -> V_323 == 6 ) {
T_2 * V_324 ;
V_324 = ( T_2 * ) V_79 -> V_322 ;
V_32 . V_58 . V_59 = ( V_324 [ 5 ] << 24 ) | ( V_324 [ 4 ] << 16 ) |
( V_324 [ 3 ] << 8 ) | V_324 [ 2 ] ;
V_32 . V_58 . V_60 = ( V_324 [ 1 ] << 8 ) | V_324 [ 0 ] ;
V_32 . V_61 = true ;
}
switch ( V_79 -> V_321 ) {
case V_263 :
V_32 . V_56 = V_280 ;
F_3 ( V_222 , L_130 ) ;
break;
case V_264 :
V_32 . V_56 = V_281 ;
F_3 ( V_222 , L_131 ) ;
break;
case V_265 :
V_32 . V_56 = V_325 ;
F_3 ( V_222 , L_132 ) ;
break;
case V_269 :
V_32 . V_56 = V_326 ;
F_3 ( V_222 , L_133 ) ;
break;
case V_267 :
V_32 . V_56 = V_326 ;
F_3 ( V_222 , L_134 ) ;
break;
default:
F_19 ( L_135 , V_79 -> V_321 ) ;
return - V_92 ;
}
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
F_19 ( L_3 , V_66 ) ;
}
return V_66 ;
}
static T_5
F_90 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 V_278 , bool V_327 , const T_2 * V_318 ,
struct V_319 * V_79 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_244 ;
T_5 V_220 ;
T_5 V_66 = 0 ;
T_2 V_320 [ 8 ] ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_222 , L_124 , V_278 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( V_318 ) {
F_3 ( V_73 , L_136 ) ;
return F_88 ( V_75 , V_65 , V_278 , V_318 , V_79 ) ;
}
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_36 = ( T_4 ) V_79 -> V_277 ;
V_32 . V_55 = ( T_4 ) V_278 ;
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_99 , V_32 . V_36 ) ;
V_66 = - V_92 ;
goto V_129;
}
memcpy ( V_32 . V_62 , V_79 -> V_32 , V_32 . V_36 ) ;
V_32 . V_57 = V_279 ;
switch ( V_79 -> V_321 ) {
case V_263 :
V_32 . V_56 = V_280 ;
V_244 = V_230 ;
F_3 ( V_222 , L_130 ) ;
break;
case V_264 :
V_32 . V_56 = V_281 ;
V_244 = V_230 ;
F_3 ( V_222 , L_131 ) ;
break;
case V_265 :
if ( V_68 -> V_2 -> V_70 != V_128 ) {
F_3 ( V_222 , L_129 ) ;
memcpy ( V_320 , & V_32 . V_62 [ 24 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 24 ] , & V_32 . V_62 [ 16 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 16 ] , V_320 , sizeof( V_320 ) ) ;
}
V_32 . V_56 = V_325 ;
V_244 = V_266 ;
F_3 ( V_222 , L_132 ) ;
break;
case V_269 :
V_32 . V_56 = V_326 ;
V_244 = V_268 ;
F_3 ( V_222 , L_133 ) ;
break;
case V_267 :
V_32 . V_56 = V_326 ;
V_244 = V_268 ;
F_3 ( V_222 , L_134 ) ;
break;
default:
F_19 ( L_135 , V_79 -> V_321 ) ;
V_66 = - V_92 ;
goto V_129;
}
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
goto V_129;
V_66 = F_76 ( V_68 , L_76 , & V_220 ) ;
if ( V_66 ) {
F_19 ( L_137 , V_66 ) ;
goto V_129;
}
V_220 |= V_244 ;
V_66 = F_72 ( V_68 , L_76 , V_220 ) ;
if ( V_66 ) {
F_19 ( L_138 , V_66 ) ;
goto V_129;
}
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_91 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 V_278 , bool V_327 , const T_2 * V_318 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( V_278 >= V_328 ) {
F_19 ( L_139 , V_278 ) ;
return - V_92 ;
}
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_55 = ( T_4 ) V_278 ;
V_32 . V_57 = V_279 ;
V_32 . V_56 = V_329 ;
F_3 ( V_222 , L_124 , V_278 ) ;
V_66 = F_15 ( V_65 , & V_32 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_92 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 V_278 , bool V_327 , const T_2 * V_318 , void * V_330 ,
void (* F_93) ( void * V_330 , struct V_319 * V_79 ) )
{
struct V_319 V_79 ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_242 * V_243 ;
T_5 V_220 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_222 , L_124 , V_278 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_66 = F_76 ( V_68 , L_76 , & V_220 ) ;
if ( V_66 ) {
F_19 ( L_125 , V_66 ) ;
V_66 = - V_133 ;
goto V_129;
}
if ( V_220 & V_230 ) {
V_243 = & V_216 -> V_243 ;
if ( V_243 -> V_271 & V_263 ) {
V_79 . V_321 = V_263 ;
F_3 ( V_222 , L_130 ) ;
} else if ( V_243 -> V_271 & V_264 ) {
V_79 . V_321 = V_264 ;
F_3 ( V_222 , L_131 ) ;
}
} else if ( V_220 & V_266 ) {
V_79 . V_321 = V_265 ;
F_3 ( V_222 , L_132 ) ;
} else if ( V_220 & V_268 ) {
V_79 . V_321 = V_269 ;
F_3 ( V_222 , L_133 ) ;
} else {
F_19 ( L_140 , V_220 ) ;
V_66 = - V_92 ;
goto V_129;
}
F_93 ( V_330 , & V_79 ) ;
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_94 ( struct V_75 * V_75 ,
struct V_64 * V_65 , T_2 V_278 )
{
F_3 ( V_5 , L_141 ) ;
return - V_87 ;
}
static T_5
F_95 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 * V_331 , struct V_332 * V_333 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_299 V_334 ;
int V_335 ;
T_5 V_336 ;
T_5 V_66 = 0 ;
T_2 * V_104 = V_216 -> V_104 ;
struct V_337 V_338 ;
F_3 ( V_73 , L_142 , V_331 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
if ( V_68 -> V_2 -> V_70 == V_128 ) {
memcpy ( & V_338 , V_331 , V_105 ) ;
V_66 = F_96 ( V_68 , L_143 ,
& V_338 ,
sizeof( V_338 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_144 , V_66 ) ;
goto V_129;
}
V_333 -> V_339 = V_340 ;
V_333 -> V_341 = F_97 ( V_338 . V_342 ) * 1000 ;
if ( F_97 ( V_338 . V_57 ) & V_343 ) {
V_333 -> V_339 |= V_344 ;
V_333 -> V_345 = F_97 ( V_338 . V_346 ) ;
}
F_3 ( V_73 , L_145 ,
V_333 -> V_341 , V_333 -> V_345 ) ;
} else if ( V_68 -> V_2 -> V_70 == V_127 ) {
if ( memcmp ( V_331 , V_104 , V_105 ) ) {
F_19 ( L_146 ,
V_331 , V_104 ) ;
V_66 = - V_347 ;
goto V_129;
}
V_66 = F_98 ( V_68 , V_348 , & V_336 ) ;
if ( V_66 ) {
F_19 ( L_147 , V_66 ) ;
goto V_129;
} else {
V_333 -> V_339 |= V_349 ;
V_333 -> V_350 . V_351 = V_336 * 5 ;
F_3 ( V_222 , L_148 , V_336 / 2 ) ;
}
if ( F_2 ( V_212 ,
& V_68 -> V_2 -> V_4 ) ) {
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_66 = F_99 ( V_68 , V_352 ,
& V_334 , sizeof( V_334 ) ) ;
if ( V_66 ) {
F_19 ( L_149 , V_66 ) ;
goto V_129;
} else {
V_335 = F_97 ( V_334 . V_244 ) ;
V_333 -> V_339 |= V_353 ;
V_333 -> signal = V_335 ;
F_3 ( V_222 , L_150 , V_335 ) ;
}
}
} else
V_66 = - V_354 ;
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_100 ( struct V_75 * V_75 , struct V_64 * V_65 ,
bool V_355 , T_5 V_356 )
{
T_5 V_357 ;
T_5 V_66 = 0 ;
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
F_3 ( V_73 , L_13 ) ;
V_95 -> V_358 = V_355 ;
if ( ! F_1 ( V_68 -> V_2 ) ) {
F_3 ( V_5 , L_151 ) ;
goto V_129;
}
V_357 = V_355 ? V_359 : V_360 ;
if ( V_68 -> V_2 -> V_119 . V_123 == V_88 ) {
F_3 ( V_5 , L_152 ) ;
V_357 = V_360 ;
}
F_3 ( V_5 , L_153 , ( V_357 ? L_154 : L_155 ) ) ;
V_66 = F_41 ( V_68 , V_361 , V_357 ) ;
if ( V_66 ) {
if ( V_66 == - V_362 )
F_19 ( L_156 ) ;
else
F_19 ( L_42 , V_66 ) ;
}
V_129:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_101 ( struct V_94 * V_95 ,
struct V_363 * V_364 )
{
struct V_75 * V_75 = F_31 ( V_95 ) ;
struct V_19 * V_365 ;
struct V_366 * V_367 ;
struct V_368 * V_369 ;
struct V_21 V_20 ;
T_5 V_66 = 0 ;
T_1 V_234 ;
T_4 V_370 ;
T_1 V_371 ;
T_1 V_372 ;
T_2 * V_373 ;
T_6 V_374 ;
T_5 V_375 ;
if ( F_97 ( V_364 -> V_376 ) > V_377 ) {
F_19 ( L_157 ) ;
return 0 ;
}
if ( ! V_364 -> V_378 ) {
V_20 . V_28 = F_102 ( V_364 -> V_139 ) ;
V_95 -> V_18 . V_379 ( & V_20 ) ;
V_364 -> V_378 = V_20 . V_23 ;
}
V_234 = V_364 -> V_378 ;
if ( V_234 <= V_380 )
V_369 = V_75 -> V_381 [ V_382 ] ;
else
V_369 = V_75 -> V_381 [ V_383 ] ;
V_370 = F_103 ( V_234 , V_369 -> V_369 ) ;
V_365 = F_104 ( V_75 , V_370 ) ;
V_371 = F_102 ( V_364 -> V_384 ) ;
V_372 = F_102 ( V_364 -> V_385 ) ;
V_373 = ( T_2 * ) V_364 + F_102 ( V_364 -> V_386 ) ;
V_374 = F_97 ( V_364 -> V_387 ) ;
V_375 = ( V_388 ) F_102 ( V_364 -> V_389 ) * 100 ;
F_3 ( V_222 , L_158 , V_364 -> V_390 ) ;
F_3 ( V_222 , L_159 , V_234 , V_370 ) ;
F_3 ( V_222 , L_160 , V_371 ) ;
F_3 ( V_222 , L_161 , V_372 ) ;
F_3 ( V_222 , L_162 , V_375 ) ;
V_367 = F_105 ( V_75 , V_365 , ( const T_2 * ) V_364 -> V_390 ,
0 , V_371 , V_372 , V_373 ,
V_374 , V_375 , V_157 ) ;
if ( ! V_367 )
return - V_158 ;
F_106 ( V_75 , V_367 ) ;
return V_66 ;
}
static struct V_363 *
F_107 ( struct V_164 * V_391 , struct V_363 * V_367 )
{
if ( V_367 == NULL )
return V_391 -> V_392 ;
return (struct V_363 * ) ( ( unsigned long ) V_367 +
F_97 ( V_367 -> V_376 ) ) ;
}
static T_5 F_108 ( struct V_94 * V_95 )
{
struct V_164 * V_393 ;
struct V_363 * V_364 = NULL ;
T_5 V_66 = 0 ;
int V_138 ;
V_393 = V_95 -> V_393 ;
if ( V_393 -> V_172 != 0 &&
V_393 -> V_160 != V_394 ) {
F_19 ( L_163 ,
V_393 -> V_160 ) ;
return - V_87 ;
}
F_3 ( V_102 , L_164 , V_393 -> V_172 ) ;
for ( V_138 = 0 ; V_138 < V_393 -> V_172 ; V_138 ++ ) {
V_364 = F_107 ( V_393 , V_364 ) ;
V_66 = F_101 ( V_95 , V_364 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static T_5 F_109 ( struct V_94 * V_95 ,
struct V_64 * V_65 , const T_2 * V_104 )
{
struct V_75 * V_75 = F_31 ( V_95 ) ;
struct V_19 * V_365 ;
struct V_363 * V_364 = NULL ;
struct V_368 * V_369 ;
struct V_366 * V_367 ;
struct V_21 V_20 ;
T_2 * V_30 = NULL ;
T_5 V_66 = 0 ;
T_4 V_370 ;
T_1 V_371 ;
T_1 V_372 ;
T_2 * V_373 ;
T_6 V_374 ;
T_5 V_375 ;
F_3 ( V_73 , L_13 ) ;
V_30 = F_46 ( V_377 , V_157 ) ;
if ( V_30 == NULL ) {
V_66 = - V_158 ;
goto V_395;
}
* ( V_396 * ) V_30 = F_13 ( V_377 ) ;
V_66 = F_99 ( F_18 ( V_65 ) , V_397 ,
V_30 , V_377 ) ;
if ( V_66 ) {
F_19 ( L_165 , V_66 ) ;
goto V_395;
}
V_364 = (struct V_363 * ) ( V_30 + 4 ) ;
V_20 . V_28 = F_102 ( V_364 -> V_139 ) ;
V_95 -> V_18 . V_379 ( & V_20 ) ;
if ( V_20 . V_369 == V_398 )
V_369 = V_75 -> V_381 [ V_382 ] ;
else
V_369 = V_75 -> V_381 [ V_383 ] ;
V_370 = F_103 ( V_20 . V_23 , V_369 -> V_369 ) ;
V_365 = F_104 ( V_75 , V_370 ) ;
V_371 = F_102 ( V_364 -> V_384 ) ;
V_372 = F_102 ( V_364 -> V_385 ) ;
V_373 = ( T_2 * ) V_364 + F_102 ( V_364 -> V_386 ) ;
V_374 = F_97 ( V_364 -> V_387 ) ;
V_375 = ( V_388 ) F_102 ( V_364 -> V_389 ) * 100 ;
F_3 ( V_222 , L_166 , V_20 . V_23 , V_370 ) ;
F_3 ( V_222 , L_167 , V_371 ) ;
F_3 ( V_222 , L_70 , V_372 ) ;
F_3 ( V_222 , L_168 , V_375 ) ;
V_367 = F_105 ( V_75 , V_365 , V_104 ,
0 , V_371 , V_372 ,
V_373 , V_374 , V_375 , V_157 ) ;
if ( ! V_367 ) {
V_66 = - V_158 ;
goto V_395;
}
F_106 ( V_75 , V_367 ) ;
V_395:
F_49 ( V_30 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static bool F_110 ( struct V_1 * V_2 )
{
return V_2 -> V_70 == V_126 ;
}
static T_5 F_111 ( struct V_94 * V_95 ,
struct V_67 * V_68 )
{
struct V_210 * V_216 = F_71 ( V_68 -> V_65 ) ;
struct V_363 * V_364 ;
struct V_156 * V_149 ;
struct V_29 * V_399 ;
T_1 V_227 ;
T_2 V_400 ;
T_6 V_226 ;
T_2 * V_38 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_110 ( V_68 -> V_2 ) )
return V_66 ;
V_149 = & V_216 -> V_149 ;
* ( V_396 * ) V_95 -> V_401 = F_13 ( V_402 ) ;
V_66 = F_99 ( V_68 , V_397 ,
V_95 -> V_401 , V_402 ) ;
if ( V_66 ) {
F_19 ( L_169 , V_66 ) ;
goto V_403;
}
V_364 = (struct V_363 * ) ( V_95 -> V_401 + 4 ) ;
V_66 = F_101 ( V_95 , V_364 ) ;
if ( V_66 )
goto V_403;
V_38 = ( ( T_2 * ) V_364 ) + F_102 ( V_364 -> V_386 ) ;
V_226 = F_97 ( V_364 -> V_387 ) ;
V_227 = F_102 ( V_364 -> V_385 ) ;
V_399 = F_8 ( V_38 , V_226 , V_404 ) ;
if ( V_399 )
V_400 = V_399 -> V_62 [ 1 ] ;
else {
T_4 V_405 ;
V_66 = F_86 ( V_68 , L_170 , & V_405 ) ;
if ( V_66 ) {
F_19 ( L_171 , V_66 ) ;
goto V_403;
}
V_400 = ( T_2 ) V_405 ;
}
V_403:
F_3 ( V_73 , L_136 ) ;
return V_66 ;
}
void F_112 ( struct V_94 * V_95 )
{
struct V_122 * V_166 = & V_95 -> V_122 ;
F_40 ( V_183 , & V_95 -> V_118 ) ;
if ( V_95 -> V_101 ) {
V_166 -> V_167 = V_406 ;
F_26 ( V_95 , V_166 -> V_68 , true , true ) ;
}
F_56 ( V_117 , & V_95 -> V_118 ) ;
F_56 ( V_183 , & V_95 -> V_118 ) ;
}
static void F_113 ( struct V_407 * V_408 )
{
struct V_94 * V_95 =
F_58 ( V_408 , struct V_94 ,
V_409 ) ;
F_26 ( V_95 , V_95 -> V_122 . V_68 , true , true ) ;
}
static void F_114 ( unsigned long V_62 )
{
struct V_94 * V_95 =
(struct V_94 * ) V_62 ;
if ( V_95 -> V_101 ) {
F_19 ( L_172 ) ;
F_115 ( & V_95 -> V_409 ) ;
}
}
static T_5
F_116 ( struct V_94 * V_95 ,
struct V_363 * V_367 ,
struct V_363 * V_392 )
{
struct V_21 V_410 , V_411 ;
V_410 . V_28 = F_102 ( V_367 -> V_139 ) ;
V_95 -> V_18 . V_379 ( & V_410 ) ;
V_411 . V_28 = F_102 ( V_392 -> V_139 ) ;
V_95 -> V_18 . V_379 ( & V_411 ) ;
if ( ! memcmp ( & V_392 -> V_390 , & V_367 -> V_390 , V_105 ) &&
V_410 . V_369 == V_411 . V_369 &&
V_392 -> V_145 == V_367 -> V_145 &&
! memcmp ( V_392 -> V_148 , V_367 -> V_148 , V_392 -> V_145 ) ) {
if ( ( V_367 -> V_57 & V_412 ) ==
( V_392 -> V_57 & V_412 ) ) {
V_388 V_413 = F_102 ( V_367 -> V_389 ) ;
V_388 V_414 = F_102 ( V_392 -> V_389 ) ;
if ( V_414 > V_413 )
V_367 -> V_389 = V_392 -> V_389 ;
} else if ( ( V_367 -> V_57 & V_412 ) &&
( V_392 -> V_57 & V_412 ) == 0 ) {
V_367 -> V_389 = V_392 -> V_389 ;
V_367 -> V_57 |= V_412 ;
}
return 1 ;
}
return 0 ;
}
static T_5
F_117 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
T_5 V_419 ;
T_5 V_66 = 0 ;
struct V_420 * V_421 ;
struct V_363 * V_392 ;
struct V_363 * V_367 = NULL ;
T_4 V_422 ;
struct V_164 * V_391 ;
T_4 V_138 ;
bool V_96 ;
V_419 = V_416 -> V_419 ;
if ( ! F_2 ( V_117 , & V_95 -> V_118 ) ) {
F_19 ( L_173 , V_68 -> V_423 ) ;
return - V_354 ;
}
if ( V_419 == V_424 ) {
F_3 ( V_102 , L_174 ) ;
V_421 = (struct V_420 * ) V_62 ;
if ( ! V_421 ) {
F_19 ( L_175 ) ;
goto exit;
}
if ( F_102 ( V_421 -> V_425 ) != 1 ) {
F_19 ( L_176 ,
V_421 -> V_425 ) ;
goto exit;
}
V_392 = & V_421 -> V_392 ;
if ( F_118 ( V_95 , V_392 ) )
goto exit;
if ( ! V_95 -> V_101 ) {
F_3 ( V_102 , L_177 ) ;
goto exit;
}
V_422 = F_97 ( V_392 -> V_376 ) ;
if ( V_422 != ( F_97 ( V_421 -> V_31 ) -
V_173 ) ) {
F_19 ( L_178 ,
V_422 ) ;
goto exit;
}
if ( ! ( F_31 ( V_95 ) -> V_426 &
F_119 ( V_80 ) ) ) {
if ( F_102 ( V_392 -> V_384 ) &
V_427 ) {
F_19 ( L_179 ) ;
goto exit;
}
}
V_391 = (struct V_164 * )
V_95 -> V_122 . V_171 ;
if ( V_422 > V_428 - V_391 -> V_31 ) {
F_19 ( L_180 ) ;
goto exit;
}
for ( V_138 = 0 ; V_138 < V_391 -> V_172 ; V_138 ++ ) {
V_367 = V_367 ? (struct V_363 * )
( ( unsigned char * ) V_367 +
F_97 ( V_367 -> V_376 ) ) : V_391 -> V_392 ;
if ( F_116 ( V_95 , V_367 ,
V_392 ) )
goto exit;
}
memcpy ( & ( V_95 -> V_122 . V_171 [ V_391 -> V_31 ] ) ,
V_392 , V_422 ) ;
V_391 -> V_160 = F_97 ( V_392 -> V_160 ) ;
V_391 -> V_31 += V_422 ;
V_391 -> V_172 ++ ;
} else {
V_95 -> V_122 . V_167 = V_406 ;
if ( F_118 ( V_95 , NULL ) )
goto exit;
if ( V_95 -> V_101 ) {
V_95 -> V_393 = (struct V_164 * )
V_95 -> V_122 . V_171 ;
F_108 ( V_95 ) ;
V_96 = V_419 != V_429 ;
F_26 ( V_95 , V_68 , V_96 ,
false ) ;
} else
F_3 ( V_102 , L_181 ,
V_419 ) ;
}
exit:
return V_66 ;
}
static void F_120 ( struct V_94 * V_95 )
{
F_121 ( V_95 -> V_430 , V_431 ,
F_117 ) ;
V_95 -> V_122 . V_167 = V_406 ;
F_122 ( & V_95 -> V_103 ) ;
V_95 -> V_103 . V_62 = ( unsigned long ) V_95 ;
V_95 -> V_103 . V_432 = F_114 ;
F_123 ( & V_95 -> V_409 ,
F_113 ) ;
}
static T_7 void F_124 ( T_4 V_433 )
{
if ( V_433 < 1000 / V_192 ) {
F_125 () ;
F_126 ( V_433 ) ;
} else {
F_127 ( V_433 ) ;
}
}
static T_5 F_128 ( struct V_75 * V_75 )
{
F_3 ( V_73 , L_13 ) ;
return 0 ;
}
static T_5 F_129 ( struct V_75 * V_75 ,
struct V_434 * V_435 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_64 * V_65 = F_63 ( V_95 ) ;
struct V_1 * V_2 ;
F_3 ( V_73 , L_13 ) ;
V_2 = ( (struct V_67 * ) F_18 ( V_65 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_130 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_65 ( V_2 ) ;
F_124 ( 500 ) ;
}
if ( F_2 ( V_117 , & V_95 -> V_118 ) )
F_112 ( V_95 ) ;
F_25 ( F_18 ( V_65 ) , 1 ) ;
exit:
F_3 ( V_73 , L_30 ) ;
V_95 -> V_118 = 0 ;
return 0 ;
}
static T_8 T_5
F_131 ( struct V_64 * V_65 ,
struct V_436 * V_437 , T_5 V_66 )
{
int V_138 , V_438 ;
int V_439 ;
V_439 = F_97 ( V_437 -> V_440 . V_441 ) ;
F_3 ( V_222 , L_182 , V_439 ) ;
for ( V_138 = 0 ; V_138 < V_439 ; V_138 ++ ) {
F_3 ( V_222 , L_183 , V_138 ,
& V_437 -> V_440 . V_442 [ V_138 ] . V_390 ) ;
for ( V_438 = 0 ; V_438 < V_443 ; V_438 ++ )
F_3 ( V_222 , L_184 ,
V_437 -> V_440 . V_442 [ V_138 ] . V_444 [ V_438 ] ) ;
}
if ( ! V_66 )
F_48 ( F_18 ( V_65 ) , L_185 ,
( char * ) V_437 , sizeof( * V_437 ) ) ;
return V_66 ;
}
static T_5
F_132 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_445 * V_446 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_447 * V_440 = & V_95 -> V_437 -> V_440 ;
T_5 V_66 = 0 ;
int V_138 ;
int V_439 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
V_439 = F_97 ( V_440 -> V_441 ) ;
for ( V_138 = 0 ; V_138 < V_439 ; V_138 ++ )
if ( ! memcmp ( V_446 -> V_104 , V_440 -> V_442 [ V_138 ] . V_390 , V_105 ) )
break;
if ( V_138 < V_448 ) {
memcpy ( V_440 -> V_442 [ V_138 ] . V_390 , V_446 -> V_104 , V_105 ) ;
memcpy ( V_440 -> V_442 [ V_138 ] . V_444 , V_446 -> V_442 , V_443 ) ;
if ( V_138 == V_439 ) {
V_439 ++ ;
V_440 -> V_441 = F_13 ( V_439 ) ;
}
} else
V_66 = - V_92 ;
F_3 ( V_222 , L_186 ,
V_440 -> V_442 [ V_439 ] . V_390 ) ;
for ( V_138 = 0 ; V_138 < V_443 ; V_138 ++ )
F_3 ( V_222 , L_184 , V_440 -> V_442 [ V_439 ] . V_444 [ V_138 ] ) ;
V_66 = F_131 ( V_65 , V_95 -> V_437 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_133 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_445 * V_446 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_447 V_442 ;
T_5 V_66 = 0 ;
int V_138 , V_439 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
memcpy ( & V_442 . V_442 [ 0 ] . V_390 , V_446 -> V_104 , V_105 ) ;
memcpy ( & V_442 . V_442 [ 0 ] . V_444 , V_446 -> V_442 , V_443 ) ;
F_3 ( V_222 , L_187 ,
& V_442 . V_442 [ 0 ] . V_390 ) ;
for ( V_138 = 0 ; V_138 < V_443 ; V_138 ++ )
F_3 ( V_222 , L_184 , V_442 . V_442 [ 0 ] . V_444 [ V_138 ] ) ;
V_439 = F_97 ( V_95 -> V_437 -> V_440 . V_441 ) ;
for ( V_138 = 0 ; V_138 < V_439 ; V_138 ++ )
if ( ! memcmp
( V_446 -> V_104 , & V_95 -> V_437 -> V_440 . V_442 [ V_138 ] . V_390 ,
V_105 ) )
break;
if ( ( V_439 > 0 )
&& ( V_138 < V_439 ) ) {
memset ( & V_95 -> V_437 -> V_440 . V_442 [ V_138 ] , 0 ,
sizeof( struct V_442 ) ) ;
for (; V_138 < ( V_439 - 1 ) ; V_138 ++ ) {
memcpy ( & V_95 -> V_437 -> V_440 . V_442 [ V_138 ] . V_390 ,
& V_95 -> V_437 -> V_440 . V_442 [ V_138 + 1 ] . V_390 ,
V_105 ) ;
memcpy ( & V_95 -> V_437 -> V_440 . V_442 [ V_138 ] . V_444 ,
& V_95 -> V_437 -> V_440 . V_442 [ V_138 + 1 ] . V_444 ,
V_443 ) ;
}
V_95 -> V_437 -> V_440 . V_441 = F_13 ( V_439 - 1 ) ;
} else
V_66 = - V_92 ;
V_66 = F_131 ( V_65 , V_95 -> V_437 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_134 ( struct V_75 * V_75 , struct V_64 * V_65 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
memset ( V_95 -> V_437 , 0 , sizeof( * V_95 -> V_437 ) ) ;
V_66 = F_131 ( V_65 , V_95 -> V_437 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_135 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
struct V_449 * V_450 , * V_451 ;
struct V_100 * V_135 = NULL ;
struct V_176 * V_149 = NULL ;
struct V_19 * V_234 = NULL ;
struct V_75 * V_75 = F_31 ( V_95 ) ;
int V_66 = 0 ;
int V_452 = 0 ;
int V_369 = 0 ;
struct V_453 * V_454 ;
T_4 V_455 ;
T_4 V_419 ;
F_3 ( V_102 , L_13 ) ;
if ( V_416 -> V_456 == V_457 ) {
F_3 ( V_102 , L_188 ) ;
return 0 ;
}
V_454 = (struct V_453 * ) V_62 ;
V_455 = F_97 ( V_454 -> V_172 ) ;
V_419 = F_97 ( V_454 -> V_419 ) ;
F_136 ( V_419 != V_458 ) ;
F_3 ( V_102 , L_189 , V_455 ) ;
if ( V_455 > 0 ) {
int V_138 ;
V_135 = F_46 ( sizeof( * V_135 ) , V_157 ) ;
V_149 = F_137 ( V_455 , sizeof( * V_149 ) , V_157 ) ;
V_234 = F_137 ( V_455 , sizeof( * V_234 ) , V_157 ) ;
if ( ! V_135 || ! V_149 || ! V_234 ) {
V_66 = - V_158 ;
goto V_459;
}
V_135 -> V_75 = V_75 ;
V_62 += sizeof( struct V_453 ) ;
V_451 = (struct V_449 * ) V_62 ;
for ( V_138 = 0 ; V_138 < V_455 ; V_138 ++ ) {
V_450 = & V_451 [ V_138 ] ;
if ( ! V_450 ) {
F_19 ( L_190 ,
V_138 ) ;
V_66 = - V_92 ;
goto V_459;
}
F_3 ( V_102 , L_191 ,
V_450 -> V_148 , V_450 -> V_234 ) ;
memcpy ( V_149 [ V_138 ] . V_149 , V_450 -> V_148 , V_450 -> V_145 ) ;
V_149 [ V_138 ] . V_147 = V_450 -> V_145 ;
V_135 -> V_136 ++ ;
V_452 = V_450 -> V_234 ;
if ( V_452 <= V_380 )
V_369 = V_460 ;
else
V_369 = V_461 ;
V_234 [ V_138 ] . V_24 =
F_103 ( V_452 ,
V_369 ) ;
V_234 [ V_138 ] . V_369 = V_369 ;
V_234 [ V_138 ] . V_57 |= V_462 ;
V_135 -> V_143 [ V_138 ] = & V_234 [ V_138 ] ;
V_135 -> V_137 ++ ;
}
if ( V_135 -> V_136 )
V_135 -> V_146 = & V_149 [ 0 ] ;
if ( F_2 ( V_117 , & V_95 -> V_118 ) ) {
F_112 ( V_95 ) ;
}
F_40 ( V_117 , & V_95 -> V_118 ) ;
V_66 = F_50 ( V_95 , V_75 , V_68 , V_135 ) ;
if ( V_66 ) {
F_56 ( V_117 , & V_95 -> V_118 ) ;
goto V_459;
}
V_95 -> V_116 = true ;
V_95 -> V_101 = V_135 ;
} else {
F_19 ( L_192 ) ;
goto V_459;
}
F_49 ( V_149 ) ;
F_49 ( V_234 ) ;
F_49 ( V_135 ) ;
return 0 ;
V_459:
F_49 ( V_149 ) ;
F_49 ( V_234 ) ;
F_49 ( V_135 ) ;
F_138 ( V_75 ) ;
return V_66 ;
}
static int F_139 ( struct V_64 * V_65 )
{
int V_463 ;
V_463 = F_21 ( F_18 ( V_65 ) , L_193 , 0 ) ;
if ( V_463 == 0 ) {
V_463 = F_48 ( F_18 ( V_65 ) , L_194 ,
NULL , 0 ) ;
}
if ( V_463 < 0 )
F_19 ( L_195 , V_463 ) ;
return V_463 ;
}
static int F_140 ( struct V_64 * V_65 )
{
struct V_464 V_465 ;
memset ( & V_465 , 0 , sizeof( V_465 ) ) ;
V_465 . V_160 = F_13 ( V_466 ) ;
V_465 . V_57 = F_14 ( 1 << V_467 ) ;
V_465 . V_468 = V_469 ;
V_465 . exp = V_470 ;
V_465 . V_471 = F_13 ( V_472 ) ;
return F_48 ( F_18 ( V_65 ) , L_196 ,
& V_465 , sizeof( V_465 ) ) ;
}
static int
F_141 ( struct V_75 * V_75 ,
struct V_64 * V_65 ,
struct V_473 * V_135 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_94 * V_95 = F_35 ( V_75 ) ;
struct V_474 V_475 ;
int V_138 ;
int V_463 = 0 ;
F_3 ( V_102 , L_197 ,
V_135 -> V_476 , V_135 -> V_136 ) ;
if ( F_2 ( V_117 , & V_95 -> V_118 ) ) {
F_19 ( L_44 , V_95 -> V_118 ) ;
return - V_133 ;
}
if ( F_2 ( V_184 , & V_95 -> V_118 ) ) {
F_19 ( L_46 ,
V_95 -> V_118 ) ;
return - V_133 ;
}
if ( ! V_135 -> V_136 || ! V_135 -> V_476 ) {
F_19 ( L_198 ,
V_135 -> V_136 ) ;
return - V_92 ;
}
if ( V_135 -> V_136 > 0 ) {
for ( V_138 = 0 ; V_138 < V_135 -> V_136 ; V_138 ++ ) {
F_3 ( V_102 , L_199 ,
V_135 -> V_146 [ V_138 ] . V_149 ) ;
}
}
if ( V_135 -> V_476 > 0 ) {
V_463 = F_139 ( V_65 ) ;
if ( V_463 < 0 ) {
F_19 ( L_200 , V_463 ) ;
return V_463 ;
}
V_463 = F_140 ( V_65 ) ;
if ( V_463 < 0 ) {
F_19 ( L_201 , V_463 ) ;
return - V_92 ;
}
for ( V_138 = 0 ; V_138 < V_135 -> V_476 ; V_138 ++ ) {
struct V_176 * V_149 ;
T_4 V_147 ;
V_149 = & V_135 -> V_477 [ V_138 ] . V_149 ;
V_147 = V_149 -> V_147 ;
if ( ! V_147 ) {
F_19 ( L_202 ) ;
continue;
}
V_475 . V_478 = F_13 ( V_479 ) ;
V_475 . V_276 = F_13 ( V_480 ) ;
V_475 . V_220 = F_13 ( 0 ) ;
V_475 . V_124 = F_13 ( 1 ) ;
V_475 . V_57 = F_13 ( 1 << V_481 ) ;
V_475 . V_149 . V_145 = F_13 ( V_147 ) ;
memcpy ( V_475 . V_149 . V_148 , V_149 -> V_149 , V_147 ) ;
V_463 = F_48 ( V_68 , L_203 , & V_475 ,
sizeof( V_475 ) ) ;
F_3 ( V_102 , L_204 ,
V_463 == 0 ? L_205 : L_206 , V_149 -> V_149 ) ;
}
if ( F_21 ( V_68 , L_193 , 1 ) < 0 ) {
F_19 ( L_207 , V_463 ) ;
return - V_92 ;
}
} else {
return - V_92 ;
}
return 0 ;
}
static int F_142 ( struct V_75 * V_75 ,
struct V_64 * V_65 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
F_3 ( V_102 , L_208 ) ;
F_139 ( V_65 ) ;
if ( V_95 -> V_116 )
F_26 ( V_95 , F_18 ( V_65 ) , true , true ) ;
return 0 ;
}
static int F_143 ( struct V_75 * V_75 , void * V_62 , int V_36 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_64 * V_65 = F_63 ( V_95 ) ;
struct V_482 * V_483 = V_62 ;
struct V_484 * V_485 ;
int V_463 ;
F_3 ( V_73 , L_209 , V_483 -> V_199 , V_483 -> V_486 ,
V_483 -> V_30 , V_483 -> V_36 ) ;
if ( V_483 -> V_486 )
V_463 = F_29 ( F_18 ( V_65 ) , V_483 -> V_199 ,
V_483 -> V_30 , V_483 -> V_36 ) ;
else
V_463 = F_99 ( F_18 ( V_65 ) , V_483 -> V_199 ,
V_483 -> V_30 , V_483 -> V_36 ) ;
if ( V_463 == 0 ) {
V_485 = F_144 ( V_75 , sizeof( * V_483 ) ) ;
F_145 ( V_485 , V_487 , sizeof( * V_483 ) , V_483 ) ;
V_463 = F_146 ( V_485 ) ;
}
return V_463 ;
}
static T_5 F_147 ( struct V_67 * V_68 )
{
T_5 V_66 ;
V_66 = F_72 ( V_68 , L_89 , 0 ) ;
if ( V_66 < 0 ) {
F_19 ( L_210 , V_66 ) ;
return V_66 ;
}
V_66 = F_72 ( V_68 , L_76 , 0 ) ;
if ( V_66 < 0 ) {
F_19 ( L_211 , V_66 ) ;
return V_66 ;
}
V_66 = F_72 ( V_68 , L_82 , V_488 ) ;
if ( V_66 < 0 ) {
F_19 ( L_212 , V_66 ) ;
return V_66 ;
}
return 0 ;
}
static bool F_148 ( T_2 * V_41 , bool V_489 )
{
if ( V_489 )
return ( memcmp ( V_41 , V_490 , V_49 ) == 0 ) ;
return ( memcmp ( V_41 , V_48 , V_49 ) == 0 ) ;
}
static T_5
F_149 ( struct V_64 * V_65 , struct V_45 * V_286 ,
bool V_489 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_4 V_478 = 0 ;
T_1 V_172 ;
T_5 V_66 = 0 ;
T_5 V_36 = 0 ;
T_4 V_138 ;
T_4 V_220 ;
T_4 V_259 = 0 ;
T_4 V_260 = 0 ;
T_4 V_276 = 0 ;
T_4 V_13 ;
T_2 * V_62 ;
T_1 V_491 ;
T_4 V_492 ;
F_3 ( V_73 , L_13 ) ;
if ( V_286 == NULL )
goto exit;
V_36 = V_286 -> V_36 + V_35 ;
V_62 = ( T_2 * ) V_286 ;
V_13 = V_35 ;
if ( ! V_489 )
V_13 += V_493 ;
else
V_13 += V_494 ;
if ( V_13 + V_495 > V_36 ) {
V_66 = - V_92 ;
F_19 ( L_213 ) ;
goto exit;
}
if ( ! F_148 ( & V_62 [ V_13 ] , V_489 ) ) {
V_66 = - V_92 ;
F_19 ( L_214 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_496 :
V_260 = 0 ;
break;
case V_497 :
case V_498 :
V_260 = V_230 ;
break;
case V_499 :
V_260 = V_266 ;
break;
case V_500 :
V_260 = V_268 ;
break;
default:
V_66 = - V_92 ;
F_19 ( L_215 ) ;
goto exit;
}
V_13 ++ ;
V_172 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
V_13 += V_501 ;
if ( V_13 + ( V_495 * V_172 ) > V_36 ) {
V_66 = - V_92 ;
F_19 ( L_216 ) ;
goto exit;
}
for ( V_138 = 0 ; V_138 < V_172 ; V_138 ++ ) {
if ( ! F_148 ( & V_62 [ V_13 ] , V_489 ) ) {
V_66 = - V_92 ;
F_19 ( L_214 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_496 :
break;
case V_497 :
case V_498 :
V_259 |= V_230 ;
break;
case V_499 :
V_259 |= V_266 ;
break;
case V_500 :
V_259 |= V_268 ;
break;
default:
F_19 ( L_217 ) ;
}
V_13 ++ ;
}
V_172 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
V_13 += V_501 ;
if ( V_13 + ( V_495 * V_172 ) > V_36 ) {
V_66 = - V_92 ;
F_19 ( L_218 ) ;
goto exit;
}
for ( V_138 = 0 ; V_138 < V_172 ; V_138 ++ ) {
if ( ! F_148 ( & V_62 [ V_13 ] , V_489 ) ) {
V_66 = - V_92 ;
F_19 ( L_214 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_502 :
F_3 ( V_73 , L_219 ) ;
V_276 |= V_488 ;
break;
case V_503 :
F_3 ( V_73 , L_220 ) ;
V_489 ? ( V_276 |= V_252 ) :
( V_276 |= V_249 ) ;
break;
case V_504 :
F_3 ( V_73 , L_221 ) ;
V_489 ? ( V_276 |= V_251 ) :
( V_276 |= V_248 ) ;
break;
default:
F_19 ( L_222 ) ;
}
V_13 ++ ;
}
if ( V_489 ) {
V_492 = 1 ;
if ( ( V_13 + V_505 ) <= V_36 ) {
V_491 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
if ( V_491 & V_506 )
V_492 = 0 ;
}
V_66 = F_72 ( V_68 , L_223 ,
V_492 ) ;
if ( V_66 < 0 ) {
F_19 ( L_224 , V_66 ) ;
goto exit;
}
}
V_220 = ( V_259 | V_260 | V_507 ) ;
V_66 = F_72 ( V_68 , L_89 , V_478 ) ;
if ( V_66 < 0 ) {
F_19 ( L_210 , V_66 ) ;
goto exit;
}
V_66 = F_72 ( V_68 , L_76 , V_220 ) ;
if ( V_66 < 0 ) {
F_19 ( L_211 , V_66 ) ;
goto exit;
}
V_66 = F_72 ( V_68 , L_82 , V_276 ) ;
if ( V_66 < 0 ) {
F_19 ( L_212 , V_66 ) ;
goto exit;
}
exit:
return V_66 ;
}
static T_5
F_150 ( const T_2 * V_508 , T_4 V_509 ,
struct V_510 * V_511 )
{
T_5 V_66 = 0 ;
struct V_45 * V_512 ;
struct V_29 * V_38 ;
struct V_513 * V_514 ;
T_5 V_515 ;
V_515 = ( T_5 ) V_509 ;
memset ( V_511 , 0 , sizeof( * V_511 ) ) ;
V_38 = (struct V_29 * ) V_508 ;
while ( V_38 ) {
if ( V_38 -> V_37 != V_47 )
goto V_516;
V_512 = (struct V_45 * ) V_38 ;
if ( V_512 -> V_36 < ( V_493 - V_35 + 1 ) ) {
F_19 ( L_225 ,
V_512 -> V_36 ) ;
goto V_516;
}
if ( ! memcmp ( V_512 -> V_41 , ( T_2 * ) V_48 , V_49 ) &&
( ( V_512 -> V_517 == V_50 ) ||
( V_512 -> V_517 == V_518 ) ) ) {
F_3 ( V_73 , L_226 ) ;
goto V_516;
}
V_514 = & V_511 -> V_519 [ V_511 -> V_172 ] ;
V_514 -> V_520 = ( char * ) V_512 ;
V_514 -> V_226 = V_512 -> V_36 + V_35 ;
memcpy ( & V_514 -> V_512 , V_512 , sizeof( * V_512 ) ) ;
V_511 -> V_172 ++ ;
F_3 ( V_73 , L_227 ,
V_514 -> V_512 . V_41 [ 0 ] ,
V_514 -> V_512 . V_41 [ 1 ] ,
V_514 -> V_512 . V_41 [ 2 ] ,
V_514 -> V_512 . V_517 ) ;
if ( V_511 -> V_172 >= V_521 )
break;
V_516:
V_515 -= ( V_38 -> V_36 + V_35 ) ;
if ( V_515 <= V_35 )
V_38 = NULL ;
else
V_38 = (struct V_29 * ) ( ( ( T_2 * ) V_38 ) + V_38 -> V_36 +
V_35 ) ;
}
return V_66 ;
}
static T_4
F_151 ( T_2 * V_522 , T_5 V_523 , T_2 * V_520 , T_4 V_226 , T_9 * V_524 )
{
V_396 V_525 ;
V_396 V_526 ;
strncpy ( V_522 , V_524 , V_527 - 1 ) ;
V_522 [ V_527 - 1 ] = '\0' ;
V_525 = F_13 ( 1 ) ;
memcpy ( & V_522 [ V_528 ] , & V_525 , sizeof( V_525 ) ) ;
V_526 = F_13 ( V_523 ) ;
memcpy ( & V_522 [ V_529 ] , & V_526 , sizeof( V_526 ) ) ;
memcpy ( & V_522 [ V_530 ] , V_520 , V_226 ) ;
return V_226 + V_531 ;
}
T_5 F_81 ( struct V_1 * V_2 , T_5 V_523 ,
const T_2 * V_508 , T_4 V_509 )
{
struct V_67 * V_68 ;
struct V_532 * V_533 ;
T_5 V_66 = 0 ;
T_2 * V_534 ;
T_2 * V_535 ;
T_2 * V_536 = NULL ;
int V_537 ;
T_4 * V_538 ;
T_4 V_539 = 0 ;
T_4 V_540 = 0 ;
T_4 V_541 = 0 ;
struct V_510 V_542 ;
struct V_510 V_543 ;
struct V_513 * V_544 ;
T_5 V_138 ;
T_2 * V_140 ;
int V_545 ;
if ( ! V_2 )
return - V_362 ;
V_68 = V_2 -> V_68 ;
V_533 = & V_2 -> V_533 ;
F_3 ( V_73 , L_228 , V_68 -> V_423 , V_523 ) ;
V_534 = F_46 ( V_402 , V_157 ) ;
if ( ! V_534 )
return - V_158 ;
V_535 = V_534 ;
switch ( V_523 ) {
case V_546 :
V_536 = V_533 -> V_547 ;
V_538 = & V_533 -> V_548 ;
V_537 = sizeof( V_533 -> V_547 ) ;
break;
case V_549 :
V_536 = V_533 -> V_550 ;
V_538 = & V_533 -> V_551 ;
V_537 = sizeof( V_533 -> V_550 ) ;
break;
case V_552 :
V_536 = V_533 -> V_553 ;
V_538 = & V_533 -> V_554 ;
V_537 = sizeof( V_533 -> V_553 ) ;
break;
case V_290 :
V_536 = V_533 -> V_555 ;
V_538 = & V_533 -> V_556 ;
V_537 = sizeof( V_533 -> V_555 ) ;
break;
default:
V_66 = - V_354 ;
F_19 ( L_229 ) ;
goto exit;
}
if ( V_509 > V_537 ) {
V_66 = - V_158 ;
F_19 ( L_230 ) ;
goto exit;
}
if ( V_508 && V_509 && V_535 ) {
V_140 = V_535 ;
F_150 ( V_508 , V_509 , & V_543 ) ;
for ( V_138 = 0 ; V_138 < V_543 . V_172 ; V_138 ++ ) {
V_544 = & V_543 . V_519 [ V_138 ] ;
memcpy ( V_140 + V_541 , V_544 -> V_520 ,
V_544 -> V_226 ) ;
V_541 += V_544 -> V_226 ;
}
}
if ( V_536 && * V_538 ) {
if ( V_541 && ( V_541 == * V_538 ) &&
( memcmp ( V_536 , V_535 ,
V_541 ) == 0 ) ) {
F_3 ( V_73 , L_231 ) ;
goto exit;
}
F_150 ( V_536 , * V_538 , & V_542 ) ;
for ( V_138 = 0 ; V_138 < V_542 . V_172 ; V_138 ++ ) {
V_544 = & V_542 . V_519 [ V_138 ] ;
F_3 ( V_73 , L_232 ,
V_544 -> V_512 . V_37 ,
V_544 -> V_512 . V_36 ,
V_544 -> V_512 . V_41 [ 0 ] ,
V_544 -> V_512 . V_41 [ 1 ] ,
V_544 -> V_512 . V_41 [ 2 ] ) ;
V_539 = F_151 ( V_535 , V_523 ,
V_544 -> V_520 ,
V_544 -> V_226 ,
L_233 ) ;
V_535 += V_539 ;
V_540 += V_539 ;
}
}
* V_538 = 0 ;
if ( V_536 && V_541 ) {
V_140 = V_536 ;
V_545 = V_537 ;
for ( V_138 = 0 ; V_138 < V_543 . V_172 ; V_138 ++ ) {
V_544 = & V_543 . V_519 [ V_138 ] ;
if ( V_545 < ( V_544 -> V_512 . V_36 +
V_530 ) ) {
F_19 ( L_234 ,
V_545 ) ;
break;
}
V_545 -= ( V_544 -> V_226 +
V_530 ) ;
F_3 ( V_73 , L_235 ,
V_544 -> V_512 . V_37 ,
V_544 -> V_512 . V_36 ,
V_544 -> V_512 . V_41 [ 0 ] ,
V_544 -> V_512 . V_41 [ 1 ] ,
V_544 -> V_512 . V_41 [ 2 ] ) ;
V_539 = F_151 ( V_535 , V_523 ,
V_544 -> V_520 ,
V_544 -> V_226 ,
L_236 ) ;
memcpy ( V_140 + ( * V_538 ) , V_544 -> V_520 ,
V_544 -> V_226 ) ;
* V_538 += V_544 -> V_226 ;
V_535 += V_539 ;
V_540 += V_539 ;
}
}
if ( V_540 ) {
V_66 = F_17 ( V_68 , L_237 , V_534 ,
V_540 ) ;
if ( V_66 )
F_19 ( L_238 , V_66 ) ;
}
exit:
F_49 ( V_534 ) ;
return V_66 ;
}
T_5 F_152 ( struct V_1 * V_2 )
{
T_5 V_557 [] = {
V_546 ,
V_549 ,
V_552
} ;
int V_138 ;
for ( V_138 = 0 ; V_138 < F_153 ( V_557 ) ; V_138 ++ )
F_81 ( V_2 , V_557 [ V_138 ] , NULL , 0 ) ;
memset ( & V_2 -> V_533 , 0 , sizeof( V_2 -> V_533 ) ) ;
return 0 ;
}
static T_5
F_154 ( struct V_1 * V_2 ,
struct V_558 * V_559 )
{
T_5 V_66 ;
V_66 = F_81 ( V_2 , V_552 ,
V_559 -> V_560 , V_559 -> V_561 ) ;
if ( V_66 ) {
F_19 ( L_239 ) ;
return V_66 ;
}
F_3 ( V_73 , L_240 ) ;
V_66 = F_81 ( V_2 , V_549 ,
V_559 -> V_562 ,
V_559 -> V_563 ) ;
if ( V_66 )
F_19 ( L_241 ) ;
else
F_3 ( V_73 , L_242 ) ;
return V_66 ;
}
static T_5
F_155 ( struct V_94 * V_95 ,
struct V_67 * V_68 ,
struct V_19 * V_234 )
{
T_1 V_139 ;
T_5 V_66 ;
F_3 ( V_73 , L_243 , V_234 -> V_369 ,
V_234 -> V_24 ) ;
V_139 = F_6 ( & V_95 -> V_18 , V_234 ) ;
V_66 = F_21 ( V_68 , L_244 , V_139 ) ;
return V_66 ;
}
static T_5
F_156 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_564 * V_565 )
{
T_5 V_386 ;
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_29 * V_566 ;
struct V_141 V_142 ;
T_5 V_66 = - V_354 ;
struct V_29 * V_285 ;
struct V_45 * V_286 ;
struct V_217 V_218 ;
enum V_77 V_567 ;
struct V_568 V_569 ;
F_3 ( V_73 , L_245 ,
F_157 ( & V_565 -> V_223 ) ,
V_565 -> V_227 ,
V_565 -> V_400 ) ;
F_3 ( V_73 , L_246 ,
V_565 -> V_149 , V_565 -> V_147 , V_565 -> V_254 ,
V_565 -> V_570 ) ;
V_567 = V_68 -> V_2 -> V_119 . V_123 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
if ( V_565 -> V_149 == NULL || V_565 -> V_147 == 0 ) {
V_386 = V_571 + V_572 ;
V_566 = F_8 (
( T_2 * ) & V_565 -> V_559 . V_573 [ V_386 ] ,
V_565 -> V_559 . V_574 - V_386 ,
V_575 ) ;
if ( ! V_566 )
return - V_92 ;
memcpy ( V_142 . V_148 , V_566 -> V_62 , V_566 -> V_36 ) ;
V_142 . V_145 = F_13 ( V_566 -> V_36 ) ;
F_3 ( V_73 , L_247 , V_142 . V_148 ) ;
} else {
memcpy ( V_142 . V_148 , V_565 -> V_149 , V_565 -> V_147 ) ;
V_142 . V_145 = F_13 ( ( T_4 ) V_565 -> V_147 ) ;
}
F_25 ( V_68 , 0 ) ;
F_20 ( V_68 , false ) ;
V_285 = F_8 ( ( T_2 * ) V_565 -> V_559 . V_560 ,
V_565 -> V_559 . V_561 , V_289 ) ;
V_286 = F_10 ( ( T_2 * ) V_565 -> V_559 . V_560 ,
V_565 -> V_559 . V_561 ) ;
if ( ( V_286 != NULL || V_285 != NULL ) ) {
F_3 ( V_73 , L_248 ) ;
if ( V_286 != NULL ) {
V_66 = F_149 ( V_65 , V_286 , false ) ;
if ( V_66 < 0 )
goto exit;
} else {
V_66 = F_149 ( V_65 ,
(struct V_45 * ) V_285 , true ) ;
if ( V_66 < 0 )
goto exit;
}
} else {
F_3 ( V_73 , L_249 ) ;
F_147 ( V_68 ) ;
}
F_154 ( V_68 -> V_2 , & V_565 -> V_559 ) ;
V_66 = F_155 ( V_95 , V_68 , V_565 -> V_223 . V_224 ) ;
if ( V_66 < 0 ) {
F_19 ( L_250 , V_66 ) ;
goto exit;
}
if ( V_565 -> V_227 ) {
V_66 = F_41 ( V_68 , V_231 ,
V_565 -> V_227 ) ;
if ( V_66 < 0 ) {
F_19 ( L_251 , V_66 ) ;
goto exit;
}
}
if ( V_565 -> V_400 ) {
V_66 = F_41 ( V_68 , V_576 ,
V_565 -> V_400 ) ;
if ( V_66 < 0 ) {
F_19 ( L_252 , V_66 ) ;
goto exit;
}
}
if ( V_567 == V_82 ) {
V_66 = F_41 ( V_68 , V_577 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_253 , V_66 ) ;
goto exit;
}
F_21 ( V_68 , L_254 , 0 ) ;
}
V_66 = F_41 ( V_68 , V_132 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_255 , V_66 ) ;
goto exit;
}
if ( V_567 == V_82 ) {
V_66 = F_41 ( V_68 , V_578 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_256 , V_66 ) ;
goto exit;
}
V_66 = F_41 ( V_68 , V_579 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_257 , V_66 ) ;
goto exit;
}
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
memcpy ( & V_218 . V_142 , & V_142 , sizeof( V_142 ) ) ;
V_66 = F_29 ( V_68 , V_239 ,
& V_218 , sizeof( V_218 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_258 , V_66 ) ;
goto exit;
}
F_3 ( V_73 , L_259 ) ;
} else {
V_66 = F_17 ( V_68 , L_260 , & V_142 ,
sizeof( V_142 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_261 , V_66 ) ;
goto exit;
}
V_569 . V_580 = F_13 ( V_68 -> V_423 ) ;
V_569 . V_69 = F_13 ( 1 ) ;
V_66 = F_48 ( V_68 , L_262 , & V_569 ,
sizeof( V_569 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_263 , V_66 ) ;
goto exit;
}
F_3 ( V_73 , L_264 ) ;
}
F_56 ( V_131 , & V_68 -> V_2 -> V_4 ) ;
F_40 ( V_581 , & V_68 -> V_2 -> V_4 ) ;
exit:
if ( V_66 ) {
F_25 ( V_68 , 1 ) ;
F_20 ( V_68 , true ) ;
}
return V_66 ;
}
static int F_158 ( struct V_75 * V_75 , struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
struct V_568 V_569 ;
struct V_217 V_218 ;
F_3 ( V_73 , L_13 ) ;
if ( V_68 -> V_2 -> V_119 . V_123 == V_82 ) {
F_127 ( 400 ) ;
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
V_66 = F_29 ( V_68 , V_239 ,
& V_218 , sizeof( V_218 ) ) ;
if ( V_66 < 0 )
F_19 ( L_258 , V_66 ) ;
V_66 = F_41 ( V_68 , V_579 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_265 , V_66 ) ;
V_66 = F_41 ( V_68 , V_578 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_256 , V_66 ) ;
V_66 = F_41 ( V_68 , V_132 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_266 , V_66 ) ;
} else {
V_569 . V_580 = F_13 ( V_68 -> V_423 ) ;
V_569 . V_69 = F_13 ( 0 ) ;
V_66 = F_48 ( V_68 , L_262 , & V_569 ,
sizeof( V_569 ) ) ;
if ( V_66 < 0 )
F_19 ( L_263 , V_66 ) ;
}
F_25 ( V_68 , 1 ) ;
F_20 ( V_68 , true ) ;
F_40 ( V_131 , & V_68 -> V_2 -> V_4 ) ;
F_56 ( V_581 , & V_68 -> V_2 -> V_4 ) ;
return V_66 ;
}
static T_5
F_159 ( struct V_75 * V_75 , struct V_64 * V_65 ,
struct V_558 * V_582 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
F_3 ( V_73 , L_13 ) ;
V_66 = F_154 ( V_68 -> V_2 , V_582 ) ;
return V_66 ;
}
static int
F_160 ( struct V_75 * V_75 , struct V_64 * V_65 ,
T_2 * V_331 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_299 V_300 ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
if ( ! V_331 )
return - V_583 ;
F_3 ( V_73 , L_267 , V_331 ) ;
if ( V_68 -> V_2 == V_95 -> V_186 . V_187 [ V_188 ] . V_2 )
V_68 = V_95 -> V_186 . V_187 [ V_189 ] . V_2 -> V_68 ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_194 ;
memcpy ( & V_300 . V_63 , V_331 , V_105 ) ;
V_300 . V_244 = F_13 ( V_584 ) ;
V_66 = F_29 ( V_68 , V_585 ,
& V_300 , sizeof( V_300 ) ) ;
if ( V_66 )
F_19 ( L_268 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void
F_161 ( struct V_75 * V_75 ,
struct V_74 * V_119 ,
T_1 V_586 , bool V_587 )
{
struct V_1 * V_2 ;
T_1 V_588 ;
F_3 ( V_73 , L_269 , V_586 , V_587 ) ;
V_588 = ( V_586 & V_589 ) >> 4 ;
V_2 = F_58 ( V_119 , struct V_1 , V_119 ) ;
if ( V_587 )
V_2 -> V_590 |= F_119 ( V_588 ) ;
else
V_2 -> V_590 &= ~ F_119 ( V_588 ) ;
}
static int
F_162 ( struct V_75 * V_75 , struct V_74 * V_119 ,
struct V_19 * V_224 , bool V_591 ,
unsigned int V_592 , const T_2 * V_30 , T_6 V_36 ,
bool V_593 , bool V_594 , T_10 * V_330 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
const struct V_595 * V_596 ;
struct V_1 * V_2 ;
T_5 V_66 = 0 ;
T_5 V_386 ;
T_5 V_226 ;
struct V_597 * V_598 ;
struct V_599 * V_600 ;
bool V_601 ;
T_5 V_602 ;
T_4 V_370 ;
F_3 ( V_73 , L_13 ) ;
* V_330 = 0 ;
V_596 = ( const struct V_595 * ) V_30 ;
if ( ! F_163 ( V_596 -> V_603 ) ) {
F_19 ( L_270 ) ;
return - V_354 ;
}
V_2 = F_58 ( V_119 , struct V_1 , V_119 ) ;
if ( F_164 ( V_596 -> V_603 ) ) {
V_386 = V_571 +
V_572 ;
V_226 = V_36 - V_386 ;
if ( V_2 == V_95 -> V_186 . V_187 [ V_189 ] . V_2 )
V_2 = V_95 -> V_186 . V_187 [ V_188 ] . V_2 ;
V_66 = F_81 ( V_2 ,
V_549 ,
& V_30 [ V_386 ] ,
V_226 ) ;
F_165 ( V_119 , * V_330 , V_30 , V_36 , true ,
V_157 ) ;
} else if ( F_166 ( V_596 -> V_603 ) ) {
V_600 = F_46 ( sizeof( * V_600 ) , V_157 ) ;
if ( V_600 == NULL ) {
F_19 ( L_271 ) ;
V_66 = - V_158 ;
goto exit;
}
V_598 = & V_600 -> V_598 ;
V_598 -> V_604 = F_13 ( * V_330 ) ;
memcpy ( & V_598 -> V_605 [ 0 ] , & V_596 -> V_605 [ 0 ] , V_105 ) ;
memcpy ( & V_600 -> V_104 [ 0 ] , & V_596 -> V_104 [ 0 ] , V_105 ) ;
V_598 -> V_36 = F_14 ( V_36 - V_571 ) ;
if ( V_224 )
V_370 = V_224 -> V_24 ;
else
F_98 ( V_2 -> V_68 , V_606 ,
& V_370 ) ;
V_602 = F_7 ( V_370 ) ;
V_600 -> V_234 = F_13 ( V_602 ) ;
memcpy ( V_598 -> V_62 , & V_30 [ V_571 ] ,
F_102 ( V_598 -> V_36 ) ) ;
F_3 ( V_73 , L_272 ,
* V_330 , F_102 ( V_598 -> V_36 ) , V_370 ) ;
V_601 = F_167 ( V_95 , F_63 ( V_95 ) ,
V_600 ) ;
F_165 ( V_119 , * V_330 , V_30 , V_36 , V_601 ,
V_157 ) ;
F_49 ( V_600 ) ;
} else {
F_3 ( V_73 , L_273 , V_596 -> V_603 ) ;
F_168 ( true , V_30 , V_36 , L_274 , V_36 ) ;
}
exit:
return V_66 ;
}
static int
F_169 ( struct V_75 * V_75 ,
struct V_74 * V_119 ,
T_10 V_330 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_1 * V_2 ;
int V_66 = 0 ;
F_3 ( V_73 , L_275 ) ;
V_2 = V_95 -> V_186 . V_187 [ V_188 ] . V_2 ;
if ( V_2 == NULL ) {
F_19 ( L_276 ) ;
V_66 = - V_362 ;
goto exit;
}
F_170 ( V_2 -> V_68 ) ;
exit:
return V_66 ;
}
static int F_171 ( struct V_75 * V_75 ,
struct V_74 * V_119 ,
enum V_607 V_608 ,
T_1 V_609 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_119 , struct V_1 , V_119 ) ;
if ( V_608 != V_610 )
return - V_92 ;
F_40 ( V_184 , & V_95 -> V_118 ) ;
F_112 ( V_95 ) ;
return F_67 ( V_2 , V_611 , V_609 ) ;
}
static void F_172 ( struct V_75 * V_75 ,
struct V_74 * V_119 )
{
struct V_94 * V_95 = F_52 ( V_75 ) ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_119 , struct V_1 , V_119 ) ;
F_67 ( V_2 , V_214 , 0 ) ;
F_56 ( V_184 , & V_95 -> V_118 ) ;
}
static T_5 F_173 ( enum V_77 type )
{
switch ( type ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
return - V_612 ;
case V_80 :
return V_126 ;
case V_81 :
case V_88 :
return V_127 ;
case V_82 :
case V_89 :
return V_128 ;
case V_90 :
return V_613 ;
case V_91 :
default:
break;
}
return - V_92 ;
}
static void F_174 ( struct V_75 * V_75 )
{
V_75 -> V_614 = V_615 ;
V_75 -> V_616 = V_615 ;
V_75 -> V_617 = V_618 ;
V_75 -> V_57 |= V_619 ;
}
static struct V_75 * F_175 ( struct V_620 * V_621 )
{
struct V_75 * V_75 ;
T_5 V_66 = 0 ;
V_75 = F_176 ( & V_622 , sizeof( struct V_94 ) ) ;
if ( ! V_75 ) {
F_19 ( L_277 ) ;
return F_23 ( - V_158 ) ;
}
F_177 ( V_75 , V_621 ) ;
V_75 -> V_623 = V_624 ;
V_75 -> V_625 = V_618 ;
V_75 -> V_626 = V_448 ;
V_75 -> V_426 = F_119 ( V_81 ) |
F_119 ( V_80 ) |
F_119 ( V_82 ) |
F_119 ( V_88 ) |
F_119 ( V_89 ) |
F_119 ( V_90 ) ;
V_75 -> V_627 = V_628 ;
V_75 -> V_629 = F_153 ( V_628 ) ;
V_75 -> V_381 [ V_382 ] = & V_630 ;
V_75 -> V_631 = V_632 ;
V_75 -> V_633 = V_634 ;
V_75 -> V_635 = F_153 ( V_634 ) ;
V_75 -> V_57 |= V_636 |
V_637 |
V_638 ;
V_75 -> V_639 = V_640 ;
V_75 -> V_641 = 5000 ;
F_174 ( V_75 ) ;
F_3 ( V_5 , L_278 ) ;
V_75 -> V_57 |= V_642 ;
F_178 ( V_75 , & V_643 ) ;
V_66 = F_179 ( V_75 ) ;
if ( V_66 < 0 ) {
F_19 ( L_279 , V_66 ) ;
F_180 ( V_75 ) ;
return F_23 ( V_66 ) ;
}
return V_75 ;
}
struct V_1 * F_181 ( struct V_94 * V_95 ,
enum V_77 type ,
bool V_644 )
{
struct V_1 * V_2 ;
if ( V_95 -> V_645 == V_646 )
return F_23 ( - V_647 ) ;
F_3 ( V_73 , L_280 ,
sizeof( * V_2 ) ) ;
V_2 = F_46 ( sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 )
return F_23 ( - V_158 ) ;
V_2 -> V_119 . V_75 = V_95 -> V_75 ;
V_2 -> V_119 . V_123 = type ;
V_2 -> V_70 = F_173 ( type ) ;
V_2 -> V_644 = V_644 ;
V_2 -> V_648 = - 1 ;
F_64 ( & V_2 -> V_216 ) ;
F_182 ( & V_2 -> V_391 , & V_95 -> V_649 ) ;
V_95 -> V_645 ++ ;
return V_2 ;
}
void F_183 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
F_184 ( & V_2 -> V_391 ) ;
V_95 -> V_645 -- ;
F_49 ( V_2 ) ;
if ( ! V_95 -> V_645 ) {
F_185 ( V_95 -> V_75 ) ;
F_180 ( V_95 -> V_75 ) ;
}
}
static bool F_186 ( const struct V_415 * V_416 )
{
T_4 V_650 = V_416 -> V_456 ;
T_4 V_419 = V_416 -> V_419 ;
if ( V_650 == V_651 && V_419 == V_429 ) {
F_3 ( V_222 , L_281 ) ;
return true ;
}
return false ;
}
static bool F_187 ( const struct V_415 * V_416 )
{
T_4 V_650 = V_416 -> V_456 ;
T_1 V_57 = V_416 -> V_57 ;
if ( V_650 == V_652 && ( ! ( V_57 & V_653 ) ) ) {
F_3 ( V_222 , L_282 ) ;
return true ;
}
return false ;
}
static bool F_188 ( struct V_94 * V_95 ,
const struct V_415 * V_416 )
{
T_4 V_650 = V_416 -> V_456 ;
T_4 V_419 = V_416 -> V_419 ;
if ( V_650 == V_652 && V_419 == V_654 ) {
F_3 ( V_222 , L_283 ,
V_416 -> V_57 & V_653 ? L_284 : L_285 ) ;
return true ;
}
if ( V_650 == V_651 && V_419 != V_429 ) {
F_3 ( V_222 , L_286 ) ;
return true ;
}
return false ;
}
static void F_189 ( struct V_94 * V_95 )
{
struct V_655 * V_656 = F_190 ( V_95 ) ;
F_49 ( V_656 -> V_657 ) ;
V_656 -> V_657 = NULL ;
V_656 -> V_658 = 0 ;
F_49 ( V_656 -> V_659 ) ;
V_656 -> V_659 = NULL ;
V_656 -> V_660 = 0 ;
}
static T_5 F_191 ( struct V_94 * V_95 ,
struct V_67 * V_68 )
{
struct V_661 * V_662 ;
struct V_655 * V_656 = F_190 ( V_95 ) ;
T_4 V_663 ;
T_4 V_664 ;
T_5 V_66 = 0 ;
F_189 ( V_95 ) ;
V_66 = F_96 ( V_68 , L_287 ,
V_95 -> V_401 , V_665 ) ;
if ( V_66 ) {
F_19 ( L_288 , V_66 ) ;
return V_66 ;
}
V_662 =
(struct V_661 * ) V_95 -> V_401 ;
V_663 = F_97 ( V_662 -> V_663 ) ;
V_664 = F_97 ( V_662 -> V_664 ) ;
if ( V_663 ) {
V_66 = F_96 ( V_68 , L_289 ,
V_95 -> V_401 ,
V_665 ) ;
if ( V_66 ) {
F_19 ( L_290 , V_66 ) ;
return V_66 ;
}
V_656 -> V_658 = V_663 ;
V_656 -> V_657 =
F_192 ( V_95 -> V_401 , V_656 -> V_658 ,
V_157 ) ;
} else {
V_656 -> V_658 = 0 ;
V_656 -> V_657 = NULL ;
}
if ( V_664 ) {
V_66 = F_96 ( V_68 , L_291 ,
V_95 -> V_401 ,
V_665 ) ;
if ( V_66 ) {
F_19 ( L_292 , V_66 ) ;
return V_66 ;
}
V_656 -> V_660 = V_664 ;
V_656 -> V_659 =
F_192 ( V_95 -> V_401 , V_656 -> V_660 ,
V_157 ) ;
} else {
V_656 -> V_660 = 0 ;
V_656 -> V_659 = NULL ;
}
F_3 ( V_222 , L_293 ,
V_656 -> V_658 , V_656 -> V_660 ) ;
return V_66 ;
}
static T_5
F_193 ( struct V_94 * V_95 ,
struct V_64 * V_65 ,
const struct V_415 * V_416 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_655 * V_656 = F_190 ( V_95 ) ;
struct V_75 * V_75 = F_31 ( V_95 ) ;
struct V_19 * V_365 = NULL ;
struct V_368 * V_369 ;
struct V_363 * V_364 ;
struct V_21 V_20 ;
T_4 V_370 ;
T_5 V_66 = 0 ;
T_2 * V_30 ;
F_3 ( V_73 , L_13 ) ;
F_191 ( V_95 , V_68 ) ;
memcpy ( V_216 -> V_104 , V_416 -> V_666 , V_105 ) ;
F_111 ( V_95 , V_68 ) ;
V_30 = F_46 ( V_377 , V_157 ) ;
if ( V_30 == NULL ) {
V_66 = - V_158 ;
goto V_129;
}
* ( V_396 * ) V_30 = F_13 ( V_377 ) ;
V_66 = F_99 ( V_68 , V_397 ,
V_30 , V_377 ) ;
if ( V_66 )
goto V_129;
V_364 = (struct V_363 * ) ( V_30 + 4 ) ;
V_20 . V_28 = F_102 ( V_364 -> V_139 ) ;
V_95 -> V_18 . V_379 ( & V_20 ) ;
if ( V_20 . V_369 == V_398 )
V_369 = V_75 -> V_381 [ V_382 ] ;
else
V_369 = V_75 -> V_381 [ V_383 ] ;
V_370 = F_103 ( V_20 . V_23 , V_369 -> V_369 ) ;
V_365 = F_104 ( V_75 , V_370 ) ;
V_129:
F_49 ( V_30 ) ;
F_194 ( V_65 , V_365 , ( T_2 * ) V_216 -> V_104 ,
V_656 -> V_657 , V_656 -> V_658 ,
V_656 -> V_659 , V_656 -> V_660 , V_157 ) ;
F_3 ( V_222 , L_294 ) ;
F_40 ( V_212 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_195 ( struct V_94 * V_95 ,
struct V_64 * V_65 , const struct V_415 * V_416 ,
bool V_667 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
struct V_655 * V_656 = F_190 ( V_95 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_33 ( V_185 ,
& V_68 -> V_2 -> V_4 ) ) {
if ( V_667 ) {
F_191 ( V_95 , V_68 ) ;
memcpy ( V_216 -> V_104 , V_416 -> V_666 , V_105 ) ;
F_111 ( V_95 , V_68 ) ;
F_40 ( V_212 ,
& V_68 -> V_2 -> V_4 ) ;
}
F_196 ( V_65 ,
( T_2 * ) V_216 -> V_104 ,
V_656 -> V_657 ,
V_656 -> V_658 ,
V_656 -> V_659 ,
V_656 -> V_660 ,
V_667 ? V_668 :
V_669 ,
V_157 ) ;
F_3 ( V_222 , L_295 ,
V_667 ? L_296 : L_206 ) ;
}
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_197 ( struct V_94 * V_95 ,
struct V_64 * V_65 ,
const struct V_415 * V_416 , void * V_62 )
{
static int V_670 ;
T_4 V_650 = V_416 -> V_456 ;
T_4 V_671 = V_416 -> V_671 ;
struct V_332 V_333 ;
F_3 ( V_222 , L_297 , V_650 , V_671 ) ;
if ( V_650 == V_652 && V_671 == V_672 &&
V_65 != F_63 ( V_95 ) ) {
F_3 ( V_222 , L_298 ) ;
F_198 ( & V_95 -> V_673 ) ;
return 0 ;
}
if ( ( ( V_650 == V_674 ) || ( V_650 == V_675 ) ) &&
( V_671 == V_429 ) ) {
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
V_333 . V_339 = V_676 ;
if ( ! V_62 ) {
F_19 ( L_299 ) ;
return - V_92 ;
}
V_333 . V_677 = V_62 ;
V_333 . V_678 = V_416 -> V_679 ;
V_670 ++ ;
V_333 . V_670 = V_670 ;
F_199 ( V_65 , V_416 -> V_666 , & V_333 , V_157 ) ;
} else if ( ( V_650 == V_680 ) ||
( V_650 == V_681 ) ||
( V_650 == V_682 ) ) {
F_200 ( V_65 , V_416 -> V_666 , V_157 ) ;
}
return 0 ;
}
static T_5
F_201 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
struct V_64 * V_65 = V_68 -> V_65 ;
struct V_210 * V_216 = & V_68 -> V_2 -> V_216 ;
T_5 V_66 = 0 ;
if ( V_68 -> V_2 -> V_70 == V_128 ) {
V_66 = F_197 ( V_95 , V_65 , V_416 , V_62 ) ;
} else if ( F_186 ( V_416 ) ) {
F_3 ( V_222 , L_300 ) ;
if ( F_110 ( V_68 -> V_2 ) ) {
memcpy ( V_216 -> V_104 , V_416 -> V_666 , V_105 ) ;
F_109 ( V_95 , V_65 , V_416 -> V_666 ) ;
F_202 ( V_65 , V_416 -> V_666 , V_157 ) ;
F_56 ( V_185 ,
& V_68 -> V_2 -> V_4 ) ;
F_40 ( V_212 ,
& V_68 -> V_2 -> V_4 ) ;
} else
F_195 ( V_95 , V_65 , V_416 , true ) ;
} else if ( F_187 ( V_416 ) ) {
F_3 ( V_222 , L_301 ) ;
if ( ! F_110 ( V_68 -> V_2 ) ) {
F_195 ( V_95 , V_65 , V_416 , false ) ;
if ( F_33 ( V_212 ,
& V_68 -> V_2 -> V_4 ) )
F_66 ( V_65 , 0 , NULL , 0 ,
V_157 ) ;
}
F_65 ( V_68 -> V_2 ) ;
F_64 ( F_71 ( V_65 ) ) ;
if ( V_65 != F_63 ( V_95 ) )
F_198 ( & V_95 -> V_673 ) ;
} else if ( F_188 ( V_95 , V_416 ) ) {
if ( F_110 ( V_68 -> V_2 ) )
F_56 ( V_185 ,
& V_68 -> V_2 -> V_4 ) ;
else
F_195 ( V_95 , V_65 , V_416 , false ) ;
}
return V_66 ;
}
static T_5
F_203 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
T_5 V_66 = 0 ;
T_4 V_650 = V_416 -> V_456 ;
T_4 V_419 = V_416 -> V_419 ;
if ( V_650 == V_683 && V_419 == V_429 ) {
if ( F_2 ( V_212 , & V_68 -> V_2 -> V_4 ) )
F_193 ( V_95 , V_68 -> V_65 , V_416 ) ;
else
F_195 ( V_95 , V_68 -> V_65 , V_416 , true ) ;
}
return V_66 ;
}
static T_5
F_204 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
T_1 V_57 = V_416 -> V_57 ;
enum V_684 V_685 ;
if ( V_57 & V_686 )
V_685 = V_687 ;
else
V_685 = V_688 ;
F_205 ( V_68 -> V_65 , ( T_2 * ) & V_416 -> V_666 , V_685 , - 1 ,
NULL , V_157 ) ;
return 0 ;
}
static T_5 F_206 ( struct V_67 * V_68 ,
const struct V_415 * V_416 , void * V_62 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
struct V_689 * V_690 = (struct V_689 * ) V_62 ;
struct V_691 * V_650 = & V_95 -> V_692 ;
struct V_1 * V_2 ;
F_3 ( V_73 , L_302 ,
V_690 -> V_152 , V_690 -> V_57 , V_690 -> V_693 ,
V_690 -> V_423 ) ;
F_207 ( & V_650 -> V_694 ) ;
V_650 -> V_152 = V_690 -> V_152 ;
V_2 = V_650 -> V_2 ;
switch ( V_690 -> V_152 ) {
case V_695 :
if ( ! V_95 -> V_692 . V_2 ) {
F_208 ( & V_650 -> V_694 ) ;
return - V_696 ;
}
V_68 -> V_2 = V_2 ;
V_2 -> V_68 = V_68 ;
if ( V_68 -> V_65 ) {
V_2 -> V_119 . V_120 = V_68 -> V_65 ;
V_68 -> V_65 -> V_134 = & V_2 -> V_119 ;
F_209 ( V_68 -> V_65 , F_210 ( V_95 -> V_75 ) ) ;
}
F_208 ( & V_650 -> V_694 ) ;
F_211 ( & V_650 -> V_697 ) ;
return 0 ;
case V_698 :
F_208 ( & V_650 -> V_694 ) ;
if ( F_36 ( V_95 ) )
F_211 ( & V_650 -> V_697 ) ;
return 0 ;
case V_699 :
F_208 ( & V_650 -> V_694 ) ;
F_211 ( & V_650 -> V_697 ) ;
return 0 ;
default:
F_208 ( & V_650 -> V_694 ) ;
break;
}
return - V_92 ;
}
static void F_212 ( struct V_700 * V_204 )
{
V_204 -> V_196 = ( T_4 ) - 1 ;
V_204 -> V_195 = ( T_4 ) - 1 ;
V_204 -> V_209 = ( T_4 ) - 1 ;
V_204 -> V_207 = ( T_4 ) - 1 ;
V_204 -> V_311 = - 1 ;
}
static void F_213 ( struct V_94 * V_95 )
{
F_121 ( V_95 -> V_430 , V_652 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_681 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_682 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_680 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_674 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_675 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_683 ,
F_203 ) ;
F_121 ( V_95 -> V_430 , V_701 ,
F_204 ) ;
F_121 ( V_95 -> V_430 , V_651 ,
F_201 ) ;
F_121 ( V_95 -> V_430 , V_702 ,
F_135 ) ;
F_121 ( V_95 -> V_430 , V_703 ,
F_206 ) ;
F_121 ( V_95 -> V_430 , V_704 ,
V_705 ) ;
F_121 ( V_95 -> V_430 , V_706 ,
V_707 ) ;
F_121 ( V_95 -> V_430 , V_708 ,
V_709 ) ;
F_121 ( V_95 -> V_430 , V_710 ,
V_711 ) ;
F_121 ( V_95 -> V_430 , V_712 ,
V_711 ) ;
}
static void F_214 ( struct V_94 * V_95 )
{
F_49 ( V_95 -> V_204 ) ;
V_95 -> V_204 = NULL ;
F_49 ( V_95 -> V_713 ) ;
V_95 -> V_713 = NULL ;
F_49 ( V_95 -> V_401 ) ;
V_95 -> V_401 = NULL ;
F_49 ( V_95 -> V_437 ) ;
V_95 -> V_437 = NULL ;
}
static T_5 F_215 ( struct V_94 * V_95 )
{
V_95 -> V_204 = F_46 ( sizeof( * V_95 -> V_204 ) , V_157 ) ;
if ( ! V_95 -> V_204 )
goto V_714;
V_95 -> V_713 = F_46 ( V_159 , V_157 ) ;
if ( ! V_95 -> V_713 )
goto V_714;
V_95 -> V_401 = F_46 ( V_402 , V_157 ) ;
if ( ! V_95 -> V_401 )
goto V_714;
V_95 -> V_437 = F_46 ( sizeof( * V_95 -> V_437 ) , V_157 ) ;
if ( ! V_95 -> V_437 )
goto V_714;
return 0 ;
V_714:
F_214 ( V_95 ) ;
return - V_158 ;
}
static T_5 F_216 ( struct V_94 * V_95 )
{
T_5 V_66 = 0 ;
V_95 -> V_101 = NULL ;
V_95 -> V_358 = true ;
V_95 -> V_715 = true ;
V_95 -> V_169 = true ;
V_95 -> V_716 = false ;
V_66 = F_215 ( V_95 ) ;
if ( V_66 )
return V_66 ;
F_213 ( V_95 ) ;
F_217 ( & V_95 -> V_717 ) ;
F_120 ( V_95 ) ;
F_212 ( V_95 -> V_204 ) ;
F_218 ( & V_95 -> V_673 ) ;
return V_66 ;
}
static void F_219 ( struct V_94 * V_95 )
{
V_95 -> V_716 = false ;
F_112 ( V_95 ) ;
F_214 ( V_95 ) ;
}
static void F_220 ( struct V_691 * V_650 )
{
F_221 ( & V_650 -> V_697 ) ;
F_217 ( & V_650 -> V_694 ) ;
}
struct V_94 * F_222 ( struct V_718 * V_417 ,
struct V_620 * V_719 )
{
struct V_64 * V_65 = V_417 -> V_720 [ 0 ] -> V_65 ;
struct V_94 * V_95 ;
struct V_75 * V_75 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
T_5 V_66 = 0 ;
T_5 V_721 ;
if ( ! V_65 ) {
F_19 ( L_303 ) ;
return NULL ;
}
V_68 = F_18 ( V_65 ) ;
V_75 = F_175 ( V_719 ) ;
if ( F_223 ( V_75 ) )
return NULL ;
V_95 = F_35 ( V_75 ) ;
V_95 -> V_75 = V_75 ;
V_95 -> V_430 = V_417 ;
F_220 ( & V_95 -> V_692 ) ;
F_224 ( & V_95 -> V_649 ) ;
V_2 = F_181 ( V_95 , V_81 , false ) ;
if ( F_223 ( V_2 ) ) {
F_180 ( V_75 ) ;
return NULL ;
}
V_2 -> V_68 = V_68 ;
V_2 -> V_119 . V_120 = V_65 ;
V_65 -> V_134 = & V_2 -> V_119 ;
F_209 ( V_65 , F_210 ( V_95 -> V_75 ) ) ;
V_66 = F_216 ( V_95 ) ;
if ( V_66 ) {
F_19 ( L_304 , V_66 ) ;
goto V_722;
}
V_68 -> V_2 = V_2 ;
V_66 = F_225 ( V_95 ) ;
if ( V_66 ) {
F_19 ( L_305 , V_66 ) ;
goto V_723;
}
V_66 = F_226 ( V_95 ) ;
if ( V_66 ) {
F_19 ( L_306 , V_66 ) ;
F_227 ( & V_95 -> V_186 ) ;
goto V_723;
}
V_66 = F_98 ( V_68 , V_724 ,
& V_721 ) ;
if ( V_66 ) {
F_19 ( L_307 , V_66 ) ;
goto V_723;
}
V_95 -> V_18 . V_721 = ( T_2 ) V_721 ;
F_228 ( & V_95 -> V_18 ) ;
return V_95 ;
V_723:
F_219 ( V_95 ) ;
V_722:
F_183 ( V_95 , V_2 ) ;
return NULL ;
}
void F_229 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
struct V_1 * V_725 ;
F_219 ( V_95 ) ;
F_230 ( V_95 ) ;
F_231 (vif, tmp, &cfg->vif_list, list) {
F_183 ( V_95 , V_2 ) ;
}
}
static T_5
F_232 ( struct V_67 * V_68 , T_4 V_726 , T_4 V_727 )
{
T_5 V_66 = 0 ;
V_396 V_728 [ 2 ] ;
V_396 V_729 [ 2 ] ;
if ( V_726 ) {
V_66 = F_21 ( V_68 , L_308 , V_727 ) ;
if ( V_66 ) {
F_19 ( L_309 , V_66 ) ;
goto V_730;
}
}
F_3 ( V_5 , L_310 , V_726 ? L_311 : L_312 ) ;
V_66 = F_21 ( V_68 , L_313 , V_726 ) ;
if ( V_66 ) {
F_19 ( L_314 , V_66 ) ;
goto V_730;
}
V_728 [ 0 ] = F_13 ( V_731 ) ;
V_728 [ 1 ] = F_13 ( V_732 ) ;
V_66 = F_29 ( V_68 , V_733 ,
( void * ) V_728 , sizeof( V_728 ) ) ;
if ( V_66 ) {
F_19 ( L_315 , V_66 ) ;
goto V_730;
}
V_729 [ 0 ] = F_13 ( V_734 ) ;
V_729 [ 1 ] = F_13 ( V_732 ) ;
V_66 = F_29 ( V_68 , V_735 ,
( void * ) V_729 , sizeof( V_729 ) ) ;
if ( V_66 ) {
F_19 ( L_316 , V_66 ) ;
goto V_730;
}
V_730:
return V_66 ;
}
static T_5
F_233 ( struct V_67 * V_68 , T_5 V_736 ,
T_5 V_737 , T_5 V_738 )
{
T_5 V_66 = 0 ;
V_66 = F_41 ( V_68 , V_739 ,
V_736 ) ;
if ( V_66 ) {
if ( V_66 == - V_87 )
F_3 ( V_5 , L_317 ) ;
else
F_19 ( L_318 , V_66 ) ;
goto V_740;
}
V_66 = F_41 ( V_68 , V_741 ,
V_737 ) ;
if ( V_66 ) {
if ( V_66 == - V_87 )
F_3 ( V_5 , L_319 ) ;
else
F_19 ( L_320 , V_66 ) ;
goto V_740;
}
V_66 = F_41 ( V_68 , V_742 ,
V_738 ) ;
if ( V_66 ) {
if ( V_66 == - V_87 )
F_3 ( V_5 , L_321 ) ;
else
F_19 ( L_322 , V_66 ) ;
goto V_740;
}
V_740:
return V_66 ;
}
static T_5 F_234 ( struct V_94 * V_95 , T_4 V_743 )
{
struct V_67 * V_68 = F_18 ( F_63 ( V_95 ) ) ;
struct V_19 * V_744 ;
struct V_745 * V_391 ;
struct V_21 V_20 ;
T_5 V_66 ;
T_2 * V_746 ;
T_4 V_138 , V_438 ;
T_4 V_747 ;
enum V_748 V_369 ;
T_4 V_234 ;
T_4 * V_749 ;
bool V_750 ;
T_4 V_55 ;
T_4 V_751 ;
bool V_752 ;
T_4 V_753 ;
V_746 = F_46 ( V_159 , V_157 ) ;
if ( V_746 == NULL )
return - V_158 ;
V_391 = (struct V_745 * ) V_746 ;
V_66 = F_96 ( V_68 , L_323 , V_746 ,
V_159 ) ;
if ( V_66 ) {
F_19 ( L_324 , V_66 ) ;
goto exit;
}
V_630 . V_137 = 0 ;
V_754 . V_137 = 0 ;
V_747 = F_97 ( V_391 -> V_172 ) ;
for ( V_138 = 0 ; V_138 < V_747 ; V_138 ++ ) {
V_20 . V_28 = ( T_1 ) F_97 ( V_391 -> V_755 [ V_138 ] ) ;
V_95 -> V_18 . V_379 ( & V_20 ) ;
if ( V_20 . V_369 == V_398 ) {
V_744 = V_756 ;
V_753 = F_153 ( V_756 ) ;
V_749 = & V_630 . V_137 ;
V_369 = V_382 ;
V_750 = ( V_743 == V_757 ) ;
} else if ( V_20 . V_369 == V_758 ) {
V_744 = V_759 ;
V_753 = F_153 ( V_759 ) ;
V_749 = & V_754 . V_137 ;
V_369 = V_383 ;
V_750 = ! ( V_743 == V_760 ) ;
} else {
F_19 ( L_325 , V_20 . V_28 ) ;
continue;
}
if ( ! V_750 && V_20 . V_25 == V_761 )
continue;
V_752 = false ;
for ( V_438 = 0 ; ( V_438 < * V_749 && ( * V_749 < V_753 ) ) ; V_438 ++ ) {
if ( V_744 [ V_438 ] . V_144 == V_20 . V_23 ) {
V_752 = true ;
break;
}
}
if ( V_752 )
V_55 = V_438 ;
else
V_55 = * V_749 ;
if ( V_55 < V_753 ) {
V_744 [ V_55 ] . V_24 =
F_103 ( V_20 . V_23 , V_369 ) ;
V_744 [ V_55 ] . V_144 = V_20 . V_23 ;
if ( V_20 . V_25 == V_761 && V_750 ) {
V_751 = V_744 [ V_55 ] . V_57 &
V_462 ;
if ( V_20 . V_762 == V_763 ) {
if ( V_751 == V_462 )
V_744 [ V_55 ] . V_57 &=
~ V_462 ;
V_744 [ V_55 ] . V_57 |=
V_764 ;
} else {
V_744 [ V_55 ] . V_57 &=
~ V_462 ;
if ( V_751 == V_462 )
V_744 [ V_55 ] . V_57 |=
V_765 ;
}
} else {
V_744 [ V_55 ] . V_57 =
V_462 ;
V_20 . V_25 = V_26 ;
V_95 -> V_18 . V_27 ( & V_20 ) ;
V_234 = V_20 . V_28 ;
V_66 = F_76 ( V_68 ,
L_326 ,
& V_234 ) ;
if ( ! V_66 ) {
if ( V_234 & V_766 )
V_744 [ V_55 ] . V_57 |=
( V_767 |
V_768 ) ;
if ( V_234 & V_769 )
V_744 [ V_55 ] . V_57 |=
V_770 ;
}
}
if ( ! V_752 )
( * V_749 ) ++ ;
}
}
exit:
F_49 ( V_746 ) ;
return V_66 ;
}
static T_5 F_235 ( struct V_94 * V_95 )
{
struct V_67 * V_68 = F_18 ( F_63 ( V_95 ) ) ;
struct V_75 * V_75 ;
T_5 V_771 ;
T_4 V_772 [ 3 ] ;
T_4 V_773 ;
T_4 V_743 = 0 ;
T_9 V_774 ;
T_5 V_66 ;
T_4 V_775 ;
T_5 V_138 ;
struct V_368 * V_381 [ V_776 ] ;
T_5 V_55 ;
V_66 = F_99 ( V_68 , V_777 ,
& V_771 , sizeof( V_771 ) ) ;
if ( V_66 ) {
F_19 ( L_327 , V_66 ) ;
return V_66 ;
}
V_774 = ( ( char * ) & V_771 ) [ 0 ] ;
F_3 ( V_5 , L_328 , V_774 ) ;
V_66 = F_99 ( V_68 , V_778 ,
& V_772 , sizeof( V_772 ) ) ;
if ( V_66 ) {
F_19 ( L_329 , V_66 ) ;
return V_66 ;
}
F_3 ( V_5 , L_330 ,
V_772 [ 0 ] , V_772 [ 1 ] , V_772 [ 2 ] ) ;
V_66 = F_86 ( V_68 , L_331 , & V_773 ) ;
if ( V_66 ) {
F_19 ( L_332 , V_66 ) ;
} else {
V_66 = F_86 ( V_68 , L_333 , & V_743 ) ;
if ( V_66 )
F_19 ( L_334 , V_66 ) ;
}
F_3 ( V_5 , L_335 , V_773 , V_743 ) ;
V_66 = F_234 ( V_95 , V_743 ) ;
if ( V_66 ) {
F_19 ( L_336 , V_66 ) ;
return V_66 ;
}
V_775 = V_772 [ 0 ] ;
memset ( V_381 , 0 , sizeof( V_381 ) ) ;
for ( V_138 = 1 ; V_138 <= V_775 && V_138 < F_153 ( V_772 ) ; V_138 ++ ) {
V_55 = - 1 ;
if ( ( V_772 [ V_138 ] == V_779 ) &&
( V_754 . V_137 > 0 ) ) {
V_55 = V_383 ;
V_381 [ V_55 ] = & V_754 ;
if ( ( V_743 == V_757 ) ||
( V_743 == V_780 ) )
V_381 [ V_55 ] -> V_781 . V_782 |=
V_783 ;
} else if ( ( V_772 [ V_138 ] == V_784 ) &&
( V_630 . V_137 > 0 ) ) {
V_55 = V_382 ;
V_381 [ V_55 ] = & V_630 ;
if ( V_743 == V_757 )
V_381 [ V_55 ] -> V_781 . V_782 |=
V_783 ;
}
if ( ( V_55 >= 0 ) && V_773 ) {
V_381 [ V_55 ] -> V_781 . V_782 |= V_785 ;
V_381 [ V_55 ] -> V_781 . V_782 |= V_786 ;
V_381 [ V_55 ] -> V_781 . V_787 = true ;
V_381 [ V_55 ] -> V_781 . V_788 =
V_789 ;
V_381 [ V_55 ] -> V_781 . V_790 =
V_791 ;
V_381 [ V_55 ] -> V_781 . V_792 . V_793 [ 0 ] = 0xff ;
}
}
V_75 = F_31 ( V_95 ) ;
V_75 -> V_381 [ V_382 ] = V_381 [ V_382 ] ;
V_75 -> V_381 [ V_383 ] = V_381 [ V_383 ] ;
F_178 ( V_75 , & V_643 ) ;
return V_66 ;
}
static T_5 F_236 ( struct V_94 * V_95 )
{
return F_235 ( V_95 ) ;
}
static T_5 F_237 ( struct V_94 * V_95 )
{
struct V_64 * V_65 ;
struct V_74 * V_119 ;
struct V_67 * V_68 ;
T_5 V_794 ;
T_5 V_66 = 0 ;
if ( V_95 -> V_716 )
return V_66 ;
V_65 = F_63 ( V_95 ) ;
V_119 = V_65 -> V_134 ;
V_68 = F_18 ( V_65 ) ;
F_41 ( V_68 , V_579 , 0 ) ;
F_233 ( V_68 , V_795 ,
V_796 , V_797 ) ;
V_794 = V_95 -> V_358 ? V_359 : V_360 ;
V_66 = F_41 ( V_68 , V_361 , V_794 ) ;
if ( V_66 )
goto V_798;
F_3 ( V_5 , L_337 ,
( V_794 ? L_154 : L_155 ) ) ;
V_66 = F_232 ( V_68 , ( V_95 -> V_715 ? 0 : 1 ) , V_799 ) ;
if ( V_66 )
goto V_798;
V_66 = F_38 ( V_119 -> V_75 , V_65 , V_119 -> V_123 ,
NULL , NULL ) ;
if ( V_66 )
goto V_798;
V_66 = F_236 ( V_95 ) ;
if ( V_66 )
goto V_798;
F_20 ( V_68 , true ) ;
V_95 -> V_716 = true ;
V_798:
return V_66 ;
}
static T_5 F_238 ( struct V_67 * V_68 )
{
F_40 ( V_3 , & V_68 -> V_2 -> V_4 ) ;
return F_237 ( V_68 -> V_417 -> V_418 ) ;
}
static T_5 F_239 ( struct V_67 * V_68 )
{
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
if ( F_1 ( V_68 -> V_2 ) ) {
F_65 ( V_68 -> V_2 ) ;
F_124 ( 500 ) ;
}
F_112 ( V_95 ) ;
F_56 ( V_3 , & V_68 -> V_2 -> V_4 ) ;
return 0 ;
}
T_5 F_240 ( struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
T_5 V_66 = 0 ;
F_207 ( & V_95 -> V_717 ) ;
V_66 = F_238 ( V_68 ) ;
F_208 ( & V_95 -> V_717 ) ;
return V_66 ;
}
T_5 F_241 ( struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_94 * V_95 = V_68 -> V_417 -> V_418 ;
T_5 V_66 = 0 ;
F_207 ( & V_95 -> V_717 ) ;
V_66 = F_239 ( V_68 ) ;
F_208 ( & V_95 -> V_717 ) ;
return V_66 ;
}
enum V_77 F_242 ( struct V_67 * V_68 )
{
struct V_74 * V_119 = & V_68 -> V_2 -> V_119 ;
return V_119 -> V_123 ;
}
T_4 F_243 ( struct V_94 * V_95 , unsigned long V_800 )
{
struct V_1 * V_2 ;
bool V_313 = 0 ;
F_130 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_800 , & V_2 -> V_4 ) )
V_313 ++ ;
}
return V_313 ;
}
static inline bool F_244 ( struct V_691 * V_650 ,
T_2 V_152 )
{
T_2 V_801 ;
F_207 ( & V_650 -> V_694 ) ;
V_801 = V_650 -> V_152 ;
F_208 ( & V_650 -> V_694 ) ;
return V_801 == V_152 ;
}
void F_245 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_691 * V_650 = & V_95 -> V_692 ;
F_207 ( & V_650 -> V_694 ) ;
V_650 -> V_2 = V_2 ;
V_650 -> V_152 = 0 ;
F_208 ( & V_650 -> V_694 ) ;
}
bool F_36 ( struct V_94 * V_95 )
{
struct V_691 * V_650 = & V_95 -> V_692 ;
bool V_802 ;
F_207 ( & V_650 -> V_694 ) ;
V_802 = V_650 -> V_2 != NULL ;
F_208 ( & V_650 -> V_694 ) ;
return V_802 ;
}
int F_246 ( struct V_94 * V_95 ,
T_2 V_152 , T_11 V_356 )
{
struct V_691 * V_650 = & V_95 -> V_692 ;
return F_247 ( V_650 -> V_697 ,
F_244 ( V_650 , V_152 ) , V_356 ) ;
}
