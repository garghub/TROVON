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
const struct V_29 *
F_8 ( const void * V_30 , int V_31 , T_3 V_32 )
{
const struct V_29 * V_33 = V_30 ;
int V_34 = V_31 ;
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
F_9 ( const T_2 * V_38 , const T_2 * * V_39 , T_4 * V_40 ,
const T_2 * V_41 , T_4 V_42 , T_2 type )
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
F_10 ( const T_2 * V_46 , T_4 V_36 )
{
const struct V_29 * V_38 ;
while ( ( V_38 = F_8 ( V_46 , V_36 , V_47 ) ) ) {
if ( F_9 ( ( const T_2 * ) V_38 , & V_46 , & V_36 ,
V_48 , V_49 , V_50 ) )
return (struct V_45 * ) V_38 ;
}
return NULL ;
}
static struct V_45 *
F_11 ( const T_2 * V_46 , T_4 V_36 )
{
const struct V_29 * V_38 ;
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
static bool F_22 ( struct V_1 * V_2 )
{
enum V_74 V_75 ;
V_75 = V_2 -> V_76 . V_75 ;
return V_75 == V_77 || V_75 == V_78 ;
}
static bool F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_76 . V_75 == V_79 ;
}
static struct V_80 * F_24 ( struct V_81 * V_81 ,
const char * V_82 ,
enum V_74 type ,
T_4 * V_57 ,
struct V_83 * V_84 )
{
F_3 ( V_73 , L_9 , V_82 , type ) ;
switch ( type ) {
case V_79 :
case V_85 :
case V_77 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return F_25 ( - V_90 ) ;
case V_91 :
case V_78 :
case V_92 :
return F_26 ( V_81 , V_82 , type , V_57 , V_84 ) ;
case V_93 :
default:
return F_25 ( - V_94 ) ;
}
}
void F_27 ( struct V_67 * V_68 , int V_95 )
{
T_5 V_66 = 0 ;
if ( F_1 ( V_68 -> V_2 ) ) {
V_66 = F_21 ( V_68 , L_10 , V_95 ) ;
if ( V_66 ) {
F_19 ( L_11 ) ;
return;
}
F_3 ( V_5 , L_12 , V_95 ) ;
}
}
T_5 F_28 ( struct V_96 * V_97 ,
struct V_67 * V_68 , bool V_98 ,
bool V_99 )
{
struct V_100 V_101 ;
struct V_102 * V_103 ;
T_5 V_66 = 0 ;
F_3 ( V_104 , L_13 ) ;
V_103 = V_97 -> V_103 ;
V_97 -> V_103 = NULL ;
if ( F_29 ( & V_97 -> V_105 ) )
F_30 ( & V_97 -> V_105 ) ;
if ( V_99 ) {
F_3 ( V_104 , L_14 ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
memset ( V_101 . V_106 , 0xFF , V_107 ) ;
V_101 . V_108 = V_109 ;
V_101 . V_110 = 0 ;
V_101 . V_111 = F_13 ( 1 ) ;
V_101 . V_112 = F_13 ( 1 ) ;
V_101 . V_113 = F_13 ( - 1 ) ;
V_101 . V_114 = F_13 ( - 1 ) ;
V_101 . V_115 = F_13 ( - 1 ) ;
V_101 . V_116 [ 0 ] = F_14 ( - 1 ) ;
V_66 = F_31 ( V_68 , V_117 ,
& V_101 , sizeof( V_101 ) ) ;
if ( V_66 )
F_19 ( L_15 ) ;
}
if ( V_97 -> V_118 ) {
F_3 ( V_104 , L_16 ) ;
V_97 -> V_118 = false ;
if ( ! V_98 )
F_32 ( F_33 ( V_97 ) ) ;
F_27 ( V_68 , 1 ) ;
} else if ( V_103 ) {
F_3 ( V_104 , L_17 ,
V_98 ? L_18 : L_19 ) ;
F_34 ( V_103 , V_98 ) ;
F_27 ( V_68 , 1 ) ;
}
if ( ! F_35 ( V_119 , & V_97 -> V_120 ) )
F_3 ( V_104 , L_20 ) ;
return V_66 ;
}
static
int F_36 ( struct V_81 * V_81 , struct V_80 * V_76 )
{
struct V_96 * V_97 = F_37 ( V_81 ) ;
struct V_64 * V_65 = V_76 -> V_121 ;
if ( F_38 ( V_97 ) )
return - V_122 ;
if ( V_65 ) {
if ( F_2 ( V_119 , & V_97 -> V_120 ) &&
V_97 -> V_123 . V_68 == F_18 ( V_65 ) )
F_28 ( V_97 , F_18 ( V_65 ) ,
true , true ) ;
F_21 ( F_18 ( V_65 ) , L_10 , 1 ) ;
}
switch ( V_76 -> V_75 ) {
case V_79 :
case V_85 :
case V_77 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return - V_90 ;
case V_91 :
case V_78 :
case V_92 :
return F_39 ( V_81 , V_76 ) ;
case V_93 :
default:
return - V_94 ;
}
return - V_90 ;
}
static T_5
F_40 ( struct V_81 * V_81 , struct V_64 * V_65 ,
enum V_74 type , T_4 * V_57 ,
struct V_83 * V_84 )
{
struct V_96 * V_97 = F_37 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_1 * V_2 = V_68 -> V_2 ;
T_5 V_124 = 0 ;
T_5 V_125 = 0 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_21 , V_65 , type ) ;
switch ( type ) {
case V_88 :
case V_87 :
F_19 ( L_22 ,
type ) ;
return - V_90 ;
case V_79 :
V_124 = 0 ;
break;
case V_85 :
if ( ( V_2 -> V_76 . V_75 == V_91 ) ||
( V_2 -> V_76 . V_75 == V_78 ) ) {
F_3 ( V_73 , L_23 ) ;
return 0 ;
}
V_124 = 1 ;
break;
case V_77 :
case V_78 :
V_125 = 1 ;
break;
default:
V_66 = - V_94 ;
goto V_126;
}
if ( V_125 ) {
if ( type == V_78 ) {
F_3 ( V_5 , L_24 ) ;
V_66 = F_41 ( V_97 , V_127 ) ;
}
if ( ! V_66 ) {
F_42 ( V_128 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_25 ) ;
}
} else {
V_66 = F_43 ( V_68 , V_129 , V_124 ) ;
if ( V_66 ) {
F_19 ( L_26 , V_66 ) ;
V_66 = - V_130 ;
goto V_126;
}
F_3 ( V_5 , L_27 , F_23 ( V_2 ) ?
L_28 : L_29 ) ;
}
V_65 -> V_131 -> V_75 = type ;
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void F_44 ( struct V_96 * V_97 ,
struct V_100 * V_101 ,
struct V_102 * V_132 )
{
T_4 V_133 ;
T_4 V_134 ;
T_5 V_135 ;
T_5 V_13 ;
T_1 V_136 ;
char * V_137 ;
struct V_138 V_139 ;
memset ( V_101 -> V_106 , 0xFF , V_107 ) ;
V_101 -> V_108 = V_109 ;
V_101 -> V_110 = 0 ;
V_101 -> V_111 = 0 ;
V_101 -> V_112 = F_13 ( - 1 ) ;
V_101 -> V_113 = F_13 ( - 1 ) ;
V_101 -> V_114 = F_13 ( - 1 ) ;
V_101 -> V_115 = F_13 ( - 1 ) ;
memset ( & V_101 -> V_139 , 0 , sizeof( V_101 -> V_139 ) ) ;
if ( ! V_132 )
return;
V_133 = V_132 -> V_133 ;
V_134 = V_132 -> V_134 ;
F_3 ( V_104 , L_31 ,
V_134 ) ;
if ( V_134 > 0 ) {
for ( V_135 = 0 ; V_135 < V_134 ; V_135 ++ ) {
V_136 = F_6 ( & V_97 -> V_18 ,
V_132 -> V_140 [ V_135 ] ) ;
F_3 ( V_104 , L_32 ,
V_132 -> V_140 [ V_135 ] -> V_141 , V_136 ) ;
V_101 -> V_116 [ V_135 ] = F_14 ( V_136 ) ;
}
} else {
F_3 ( V_104 , L_33 ) ;
}
F_3 ( V_104 , L_34 , V_133 ) ;
if ( V_133 > 0 ) {
V_13 = F_45 ( struct V_100 , V_116 ) +
V_134 * sizeof( T_1 ) ;
V_13 = F_46 ( V_13 , sizeof( T_4 ) ) ;
V_137 = ( char * ) V_101 + V_13 ;
for ( V_135 = 0 ; V_135 < V_133 ; V_135 ++ ) {
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_142 =
F_13 ( V_132 -> V_143 [ V_135 ] . V_144 ) ;
memcpy ( V_139 . V_145 , V_132 -> V_143 [ V_135 ] . V_146 ,
V_132 -> V_143 [ V_135 ] . V_144 ) ;
if ( ! V_139 . V_142 )
F_3 ( V_104 , L_35 , V_135 ) ;
else
F_3 ( V_104 , L_36 ,
V_135 , V_139 . V_145 , V_139 . V_142 ) ;
memcpy ( V_137 , & V_139 , sizeof( V_139 ) ) ;
V_137 += sizeof( V_139 ) ;
}
} else {
F_3 ( V_104 , L_37 , V_132 -> V_143 ) ;
if ( ( V_132 -> V_143 ) && V_132 -> V_143 -> V_144 ) {
F_3 ( V_104 , L_38 ,
V_101 -> V_139 . V_145 ,
V_132 -> V_143 -> V_144 ) ;
V_101 -> V_139 . V_142 =
F_13 ( V_132 -> V_143 -> V_144 ) ;
memcpy ( & V_101 -> V_139 . V_145 , V_132 -> V_143 -> V_146 ,
V_132 -> V_143 -> V_144 ) ;
}
}
V_101 -> V_111 =
F_13 ( ( V_133 << V_147 ) |
( V_134 & V_148 ) ) ;
}
static T_5
F_47 ( struct V_96 * V_97 , struct V_67 * V_68 ,
struct V_102 * V_132 , T_1 V_149 )
{
T_5 V_150 = V_151 +
F_45 ( struct V_152 , V_101 ) ;
struct V_152 * V_84 ;
T_5 V_66 = 0 ;
F_3 ( V_104 , L_39 ) ;
if ( V_132 != NULL ) {
V_150 += sizeof( T_4 ) * ( ( V_132 -> V_134 + 1 ) / 2 ) ;
V_150 += sizeof( struct V_153 ) * V_132 -> V_133 ;
}
V_84 = F_48 ( V_150 , V_154 ) ;
if ( ! V_84 ) {
V_66 = - V_155 ;
goto exit;
}
F_49 ( V_150 + sizeof( L_40 ) >= V_156 ) ;
F_44 ( V_97 , & V_84 -> V_101 , V_132 ) ;
V_84 -> V_157 = F_13 ( V_158 ) ;
V_84 -> V_149 = F_14 ( V_149 ) ;
V_84 -> V_159 = F_14 ( 0x1234 ) ;
V_66 = F_50 ( V_68 , L_40 , V_84 , V_150 ) ;
if ( V_66 ) {
if ( V_66 == - V_122 )
F_3 ( V_5 , L_41 ) ;
else
F_19 ( L_42 , V_66 ) ;
}
F_51 ( V_84 ) ;
exit:
return V_66 ;
}
static T_5
F_52 ( struct V_96 * V_97 , struct V_81 * V_81 ,
struct V_67 * V_68 , struct V_102 * V_132 )
{
T_5 V_66 ;
T_4 V_160 ;
struct V_161 * V_162 ;
struct V_123 * V_163 = & V_97 -> V_123 ;
F_3 ( V_104 , L_13 ) ;
V_163 -> V_68 = V_68 ;
V_163 -> V_81 = V_81 ;
V_163 -> V_164 = V_165 ;
V_160 = V_97 -> V_166 ? 0 : 1 ;
V_66 = F_43 ( V_68 , V_167 ,
V_160 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
return V_66 ;
}
F_27 ( V_68 , 0 ) ;
V_162 = (struct V_161 * ) V_97 -> V_123 . V_168 ;
V_162 -> V_157 = 0 ;
V_162 -> V_169 = 0 ;
V_162 -> V_31 = V_170 ;
V_66 = V_163 -> V_171 ( V_97 , V_68 , V_132 , V_172 ) ;
if ( V_66 )
F_27 ( V_68 , 1 ) ;
return V_66 ;
}
static T_5
F_53 ( struct V_81 * V_81 , struct V_1 * V_2 ,
struct V_102 * V_132 ,
struct V_173 * V_174 )
{
struct V_67 * V_68 = V_2 -> V_68 ;
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_173 * V_143 ;
struct V_175 * V_176 = & V_97 -> V_177 ;
T_4 V_160 ;
bool V_178 ;
bool V_179 ;
T_5 V_66 ;
T_4 V_142 ;
F_3 ( V_104 , L_43 ) ;
if ( F_2 ( V_119 , & V_97 -> V_120 ) ) {
F_19 ( L_44 , V_97 -> V_120 ) ;
return - V_130 ;
}
if ( F_2 ( V_180 , & V_97 -> V_120 ) ) {
F_19 ( L_45 ,
V_97 -> V_120 ) ;
return - V_130 ;
}
if ( F_2 ( V_181 , & V_97 -> V_120 ) ) {
F_19 ( L_46 ,
V_97 -> V_120 ) ;
return - V_130 ;
}
if ( F_2 ( V_182 , & V_68 -> V_2 -> V_4 ) ) {
F_19 ( L_47 , V_68 -> V_2 -> V_4 ) ;
return - V_130 ;
}
if ( V_2 == V_97 -> V_183 . V_184 [ V_185 ] . V_2 )
V_2 = V_97 -> V_183 . V_184 [ V_186 ] . V_2 ;
F_55 ( & V_97 -> V_105 , V_187 +
V_188 * V_189 / 1000 ) ;
V_178 = false ;
if ( V_132 ) {
V_143 = V_132 -> V_143 ;
V_178 = true ;
} else {
V_143 = V_174 ;
}
V_97 -> V_103 = V_132 ;
F_42 ( V_119 , & V_97 -> V_120 ) ;
if ( V_178 ) {
V_97 -> V_123 . V_171 = F_47 ;
V_66 = F_56 ( V_81 , V_132 , V_2 ) ;
if ( V_66 )
goto V_190;
V_66 = F_52 ( V_97 , V_81 , V_2 -> V_68 , V_132 ) ;
if ( V_66 )
goto V_190;
} else {
F_3 ( V_104 , L_48 ,
V_143 -> V_146 , V_143 -> V_144 ) ;
memset ( & V_176 -> V_139 , 0 , sizeof( V_176 -> V_139 ) ) ;
V_142 = F_57 ( T_2 , sizeof( V_176 -> V_139 . V_145 ) , V_143 -> V_144 ) ;
V_176 -> V_139 . V_142 = F_13 ( 0 ) ;
V_179 = false ;
if ( V_142 ) {
memcpy ( V_176 -> V_139 . V_145 , V_143 -> V_146 , V_142 ) ;
V_176 -> V_139 . V_142 = F_13 ( V_142 ) ;
V_179 = true ;
} else
F_3 ( V_104 , L_49 ) ;
V_160 = V_97 -> V_166 ? 0 : 1 ;
V_66 = F_43 ( V_68 , V_167 ,
V_160 ) ;
if ( V_66 ) {
F_19 ( L_50 , V_66 ) ;
goto V_190;
}
F_27 ( V_68 , 0 ) ;
V_66 = F_31 ( V_68 , V_117 ,
& V_176 -> V_139 , sizeof( V_176 -> V_139 ) ) ;
if ( V_66 ) {
if ( V_66 == - V_122 )
F_3 ( V_5 , L_51 ,
V_176 -> V_139 . V_145 ) ;
else
F_19 ( L_52 , V_66 ) ;
F_27 ( V_68 , 1 ) ;
goto V_190;
}
}
return 0 ;
V_190:
F_58 ( V_119 , & V_97 -> V_120 ) ;
if ( F_29 ( & V_97 -> V_105 ) )
F_30 ( & V_97 -> V_105 ) ;
V_97 -> V_103 = NULL ;
return V_66 ;
}
static T_5
F_59 ( struct V_81 * V_81 , struct V_102 * V_132 )
{
struct V_1 * V_2 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
V_2 = F_60 ( V_132 -> V_76 , struct V_1 , V_76 ) ;
if ( ! F_1 ( V_2 ) )
return - V_191 ;
V_66 = F_53 ( V_81 , V_2 , V_132 , NULL ) ;
if ( V_66 )
F_19 ( L_53 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_61 ( struct V_64 * V_65 , T_4 V_192 )
{
T_5 V_66 = 0 ;
V_66 = F_21 ( F_18 ( V_65 ) , L_54 ,
V_192 ) ;
if ( V_66 )
F_19 ( L_55 , V_66 ) ;
return V_66 ;
}
static T_5 F_62 ( struct V_64 * V_65 , T_4 V_193 )
{
T_5 V_66 = 0 ;
V_66 = F_21 ( F_18 ( V_65 ) , L_56 ,
V_193 ) ;
if ( V_66 )
F_19 ( L_55 , V_66 ) ;
return V_66 ;
}
static T_5 F_63 ( struct V_64 * V_65 , T_4 V_194 , bool V_195 )
{
T_5 V_66 = 0 ;
T_4 V_196 = ( V_195 ? V_197 : V_198 ) ;
V_66 = F_43 ( F_18 ( V_65 ) , V_196 , V_194 ) ;
if ( V_66 ) {
F_19 ( L_57 , V_196 , V_66 ) ;
return V_66 ;
}
return V_66 ;
}
static T_5 F_64 ( struct V_81 * V_81 , T_4 V_199 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_64 * V_65 = F_65 ( V_97 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( V_199 & V_200 &&
( V_97 -> V_201 -> V_192 != V_81 -> V_192 ) ) {
V_97 -> V_201 -> V_192 = V_81 -> V_192 ;
V_66 = F_61 ( V_65 , V_97 -> V_201 -> V_192 ) ;
if ( ! V_66 )
goto V_126;
}
if ( V_199 & V_202 &&
( V_97 -> V_201 -> V_193 != V_81 -> V_193 ) ) {
V_97 -> V_201 -> V_193 = V_81 -> V_193 ;
V_66 = F_62 ( V_65 , V_97 -> V_201 -> V_193 ) ;
if ( ! V_66 )
goto V_126;
}
if ( V_199 & V_203
&& ( V_97 -> V_201 -> V_204 != V_81 -> V_204 ) ) {
V_97 -> V_201 -> V_204 = V_81 -> V_204 ;
V_66 = F_63 ( V_65 , V_97 -> V_201 -> V_204 , true ) ;
if ( ! V_66 )
goto V_126;
}
if ( V_199 & V_205
&& ( V_97 -> V_201 -> V_206 != V_81 -> V_206 ) ) {
V_97 -> V_201 -> V_206 = V_81 -> V_206 ;
V_66 = F_63 ( V_65 , V_97 -> V_201 -> V_206 , false ) ;
if ( ! V_66 )
goto V_126;
}
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void F_66 ( struct V_207 * V_208 )
{
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_54 ( V_2 -> V_76 . V_81 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_2 ( V_209 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_58 ) ;
V_66 = F_31 ( V_2 -> V_68 ,
V_210 , NULL , 0 ) ;
if ( V_66 ) {
F_19 ( L_59 , V_66 ) ;
}
F_58 ( V_209 , & V_2 -> V_4 ) ;
F_68 ( V_2 -> V_76 . V_121 , 0 , NULL , 0 , V_154 ) ;
}
F_58 ( V_182 , & V_2 -> V_4 ) ;
F_58 ( V_181 , & V_97 -> V_120 ) ;
F_69 ( V_2 , V_211 , 0 ) ;
F_3 ( V_73 , L_30 ) ;
}
static T_5
F_70 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_212 * V_84 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_214 V_215 ;
T_6 V_216 = 0 ;
T_5 V_66 = 0 ;
T_5 V_217 = 0 ;
T_5 V_218 ;
T_1 V_136 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( V_84 -> V_146 )
F_3 ( V_219 , L_60 , V_84 -> V_146 ) ;
else {
F_3 ( V_219 , L_61 ) ;
return - V_90 ;
}
F_42 ( V_182 , & V_68 -> V_2 -> V_4 ) ;
if ( V_84 -> V_106 )
F_3 ( V_219 , L_62 , V_84 -> V_106 ) ;
else
F_3 ( V_219 , L_63 ) ;
if ( V_84 -> V_220 . V_221 )
F_3 ( V_219 , L_64 ,
V_84 -> V_220 . V_221 -> V_24 ) ;
else
F_3 ( V_219 , L_65 ) ;
if ( V_84 -> V_222 )
F_3 ( V_219 , L_66 ) ;
else
F_3 ( V_219 , L_67 ) ;
if ( V_84 -> V_38 && V_84 -> V_223 )
F_3 ( V_219 , L_68 , V_84 -> V_223 ) ;
else
F_3 ( V_219 , L_69 ) ;
if ( V_84 -> V_224 )
F_3 ( V_219 , L_70 ,
V_84 -> V_224 ) ;
else
F_3 ( V_219 , L_71 ) ;
if ( V_84 -> V_225 )
F_3 ( V_219 , L_72 , V_84 -> V_225 ) ;
else
F_3 ( V_219 , L_73 ) ;
if ( V_84 -> V_226 )
F_3 ( V_219 , L_74 ) ;
else
F_3 ( V_219 , L_75 ) ;
if ( V_84 -> V_226 )
V_217 |= V_227 ;
V_66 = F_21 ( V_68 , L_76 , V_217 ) ;
if ( V_66 ) {
F_19 ( L_77 , V_66 ) ;
goto V_126;
}
if ( V_84 -> V_224 )
V_218 = V_84 -> V_224 ;
else
V_218 = 100 ;
V_66 = F_43 ( V_68 , V_228 , V_218 ) ;
if ( V_66 ) {
F_19 ( L_78 , V_66 ) ;
goto V_126;
}
memset ( & V_215 , 0 , sizeof( struct V_214 ) ) ;
V_213 -> V_146 . V_142 = F_57 ( T_4 , V_84 -> V_144 , 32 ) ;
memcpy ( V_213 -> V_146 . V_145 , V_84 -> V_146 , V_213 -> V_146 . V_142 ) ;
memcpy ( V_215 . V_139 . V_145 , V_84 -> V_146 , V_213 -> V_146 . V_142 ) ;
V_215 . V_139 . V_142 = F_13 ( V_213 -> V_146 . V_142 ) ;
V_216 = sizeof( V_215 . V_139 ) ;
if ( V_84 -> V_106 ) {
memcpy ( V_215 . V_101 . V_106 , V_84 -> V_106 , V_107 ) ;
V_216 = sizeof( V_215 . V_139 ) +
V_229 ;
memcpy ( V_213 -> V_106 , V_84 -> V_106 , V_107 ) ;
} else {
memset ( V_215 . V_101 . V_106 , 0xFF , V_107 ) ;
memset ( V_213 -> V_106 , 0 , V_107 ) ;
}
if ( V_84 -> V_220 . V_221 ) {
T_4 V_230 ;
V_97 -> V_231 =
F_7 (
V_84 -> V_220 . V_221 -> V_24 ) ;
if ( V_84 -> V_222 ) {
V_136 = F_6 ( & V_97 -> V_18 ,
V_84 -> V_220 . V_221 ) ;
V_215 . V_101 . V_232 [ 0 ] =
F_14 ( V_136 ) ;
V_215 . V_101 . V_233 = F_13 ( 1 ) ;
V_216 += sizeof( V_215 . V_101 ) ;
}
V_230 = V_97 -> V_231 ;
V_66 = F_43 ( V_68 , V_234 ,
V_230 ) ;
if ( V_66 ) {
F_19 ( L_79 , V_66 ) ;
goto V_126;
}
} else
V_97 -> V_231 = 0 ;
V_97 -> V_235 = false ;
V_66 = F_31 ( V_68 , V_236 ,
& V_215 , V_216 ) ;
if ( V_66 ) {
F_19 ( L_80 , V_66 ) ;
goto V_126;
}
V_126:
if ( V_66 )
F_58 ( V_182 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_71 ( struct V_81 * V_81 , struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
F_67 ( V_68 -> V_2 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_72 ( struct V_64 * V_65 ,
struct V_237 * V_238 )
{
struct V_207 * V_213 = F_73 ( V_65 ) ;
struct V_239 * V_240 ;
T_5 V_241 = 0 ;
T_5 V_66 = 0 ;
if ( V_238 -> V_242 . V_243 & V_244 )
V_241 = V_245 | V_246 ;
else if ( V_238 -> V_242 . V_243 & V_247 )
V_241 = V_248 | V_249 ;
else
V_241 = V_250 ;
F_3 ( V_219 , L_81 , V_241 ) ;
V_66 = F_74 ( F_18 ( V_65 ) , L_82 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_83 , V_66 ) ;
return V_66 ;
}
V_240 = & V_213 -> V_240 ;
V_240 -> V_243 = V_238 -> V_242 . V_243 ;
return V_66 ;
}
static T_5 F_75 ( struct V_64 * V_65 ,
struct V_237 * V_238 )
{
struct V_207 * V_213 = F_73 ( V_65 ) ;
struct V_239 * V_240 ;
T_5 V_241 = 0 ;
T_5 V_66 = 0 ;
switch ( V_238 -> V_251 ) {
case V_252 :
V_241 = 0 ;
F_3 ( V_219 , L_84 ) ;
break;
case V_253 :
V_241 = 1 ;
F_3 ( V_219 , L_85 ) ;
break;
case V_254 :
V_241 = 2 ;
F_3 ( V_219 , L_86 ) ;
break;
case V_255 :
F_3 ( V_219 , L_87 ) ;
default:
V_241 = 2 ;
F_19 ( L_88 , V_238 -> V_251 ) ;
break;
}
V_66 = F_74 ( F_18 ( V_65 ) , L_89 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_90 , V_66 ) ;
return V_66 ;
}
V_240 = & V_213 -> V_240 ;
V_240 -> V_251 = V_238 -> V_251 ;
return V_66 ;
}
static T_5
F_76 ( struct V_64 * V_65 ,
struct V_237 * V_238 , bool V_256 )
{
struct V_207 * V_213 = F_73 ( V_65 ) ;
struct V_239 * V_240 ;
T_5 V_257 = 0 ;
T_5 V_258 = 0 ;
T_5 V_217 ;
T_5 V_66 = 0 ;
if ( V_238 -> V_242 . V_259 ) {
switch ( V_238 -> V_242 . V_260 [ 0 ] ) {
case V_261 :
case V_262 :
V_257 = V_227 ;
break;
case V_263 :
V_257 = V_264 ;
break;
case V_265 :
V_257 = V_266 ;
break;
case V_267 :
V_257 = V_266 ;
break;
default:
F_19 ( L_91 ,
V_238 -> V_242 . V_260 [ 0 ] ) ;
return - V_94 ;
}
}
if ( V_238 -> V_242 . V_268 ) {
switch ( V_238 -> V_242 . V_268 ) {
case V_261 :
case V_262 :
V_258 = V_227 ;
break;
case V_263 :
V_258 = V_264 ;
break;
case V_265 :
V_258 = V_266 ;
break;
case V_267 :
V_258 = V_266 ;
break;
default:
F_19 ( L_92 ,
V_238 -> V_242 . V_268 ) ;
return - V_94 ;
}
}
F_3 ( V_219 , L_93 , V_257 , V_258 ) ;
if ( F_11 ( V_238 -> V_38 , V_238 -> V_223 ) && ! V_257 && ! V_258 &&
V_238 -> V_226 )
V_257 = V_266 ;
if ( V_256 )
V_217 = V_257 | V_258 | V_269 ;
else
V_217 = V_257 | V_258 ;
V_66 = F_74 ( F_18 ( V_65 ) , L_76 , V_217 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
return V_66 ;
}
V_240 = & V_213 -> V_240 ;
V_240 -> V_270 = V_238 -> V_242 . V_260 [ 0 ] ;
V_240 -> V_268 = V_238 -> V_242 . V_268 ;
return V_66 ;
}
static T_5
F_77 ( struct V_64 * V_65 , struct V_237 * V_238 )
{
struct V_207 * V_213 = F_73 ( V_65 ) ;
struct V_239 * V_240 ;
T_5 V_241 = 0 ;
T_5 V_66 = 0 ;
if ( V_238 -> V_242 . V_271 ) {
V_66 = F_78 ( F_18 ( V_65 ) ,
L_82 , & V_241 ) ;
if ( V_66 ) {
F_19 ( L_94 , V_66 ) ;
return V_66 ;
}
if ( V_241 & ( V_245 | V_246 ) ) {
switch ( V_238 -> V_242 . V_272 [ 0 ] ) {
case V_273 :
V_241 = V_246 ;
break;
case V_274 :
V_241 = V_245 ;
break;
default:
F_19 ( L_92 ,
V_238 -> V_242 . V_268 ) ;
return - V_94 ;
}
} else if ( V_241 & ( V_248 | V_249 ) ) {
switch ( V_238 -> V_242 . V_272 [ 0 ] ) {
case V_273 :
V_241 = V_249 ;
break;
case V_274 :
V_241 = V_248 ;
break;
default:
F_19 ( L_92 ,
V_238 -> V_242 . V_268 ) ;
return - V_94 ;
}
}
F_3 ( V_219 , L_95 , V_241 ) ;
V_66 = F_74 ( F_18 ( V_65 ) ,
L_82 , V_241 ) ;
if ( V_66 ) {
F_19 ( L_96 , V_66 ) ;
return V_66 ;
}
}
V_240 = & V_213 -> V_240 ;
V_240 -> V_275 = V_238 -> V_242 . V_272 [ 0 ] ;
return V_66 ;
}
static T_5
F_79 ( struct V_64 * V_65 ,
struct V_237 * V_238 )
{
struct V_207 * V_213 = F_73 ( V_65 ) ;
struct V_239 * V_240 ;
struct V_52 V_32 ;
T_5 V_241 ;
T_5 V_66 = 0 ;
F_3 ( V_219 , L_97 , V_238 -> V_276 ) ;
if ( V_238 -> V_276 == 0 )
return 0 ;
V_240 = & V_213 -> V_240 ;
F_3 ( V_219 , L_98 ,
V_240 -> V_243 , V_240 -> V_270 ) ;
if ( V_240 -> V_243 & ( V_244 | V_247 ) )
return 0 ;
if ( ! ( V_240 -> V_270 &
( V_261 | V_262 ) ) )
return 0 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_36 = ( T_4 ) V_238 -> V_276 ;
V_32 . V_55 = ( T_4 ) V_238 -> V_277 ;
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_99 , V_32 . V_36 ) ;
return - V_94 ;
}
memcpy ( V_32 . V_62 , V_238 -> V_32 , V_32 . V_36 ) ;
V_32 . V_57 = V_278 ;
switch ( V_240 -> V_270 ) {
case V_261 :
V_32 . V_56 = V_279 ;
break;
case V_262 :
V_32 . V_56 = V_280 ;
break;
default:
F_19 ( L_100 ,
V_238 -> V_242 . V_260 [ 0 ] ) ;
return - V_94 ;
}
F_3 ( V_219 , L_101 ,
V_32 . V_36 , V_32 . V_55 , V_32 . V_56 ) ;
F_3 ( V_219 , L_102 , V_32 . V_62 ) ;
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
return V_66 ;
if ( V_240 -> V_251 == V_253 ) {
F_3 ( V_219 , L_103 ) ;
V_241 = V_281 ;
V_66 = F_74 ( F_18 ( V_65 ) , L_89 , V_241 ) ;
if ( V_66 )
F_19 ( L_90 , V_66 ) ;
}
return V_66 ;
}
static
enum V_282 F_80 ( struct V_67 * V_68 ,
enum V_282 type )
{
T_4 V_283 ;
if ( type == V_254 ) {
V_283 = F_81 ( V_68 ) >> 4 ;
switch ( V_283 ) {
case 43236 :
F_3 ( V_219 , L_104 ) ;
return V_252 ;
default:
break;
}
}
return type ;
}
static T_5
F_82 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_237 * V_238 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_19 * V_221 = V_238 -> V_231 ;
struct V_214 V_215 ;
T_6 V_216 ;
const struct V_29 * V_284 ;
const struct V_45 * V_285 ;
const void * V_38 ;
T_4 V_223 ;
struct V_286 * V_287 ;
T_1 V_136 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( ! V_238 -> V_146 ) {
F_19 ( L_105 ) ;
return - V_90 ;
}
if ( V_68 -> V_2 == V_97 -> V_183 . V_184 [ V_186 ] . V_2 ) {
V_38 = NULL ;
V_223 = 0 ;
V_285 = F_10 ( ( T_2 * ) V_238 -> V_38 , V_238 -> V_223 ) ;
if ( V_285 ) {
V_38 = V_285 ;
V_223 = V_285 -> V_36 + V_35 ;
} else {
V_284 = F_8 ( ( const T_2 * ) V_238 -> V_38 ,
V_238 -> V_223 ,
V_288 ) ;
if ( V_284 ) {
V_38 = V_284 ;
V_223 = V_284 -> V_36 + V_35 ;
}
}
F_50 ( V_68 , L_106 , V_38 , V_223 ) ;
}
V_66 = F_83 ( V_68 -> V_2 , V_289 ,
V_238 -> V_38 , V_238 -> V_223 ) ;
if ( V_66 )
F_19 ( L_107 ) ;
else
F_3 ( V_73 , L_108 ) ;
F_42 ( V_182 , & V_68 -> V_2 -> V_4 ) ;
if ( V_221 ) {
V_97 -> V_231 =
F_7 ( V_221 -> V_24 ) ;
V_136 = F_6 ( & V_97 -> V_18 , V_221 ) ;
F_3 ( V_219 , L_109 ,
V_97 -> V_231 , V_221 -> V_24 , V_136 ) ;
} else {
V_97 -> V_231 = 0 ;
V_136 = 0 ;
}
F_3 ( V_5 , L_110 , V_238 -> V_38 , V_238 -> V_223 ) ;
V_66 = F_72 ( V_65 , V_238 ) ;
if ( V_66 ) {
F_19 ( L_111 , V_66 ) ;
goto V_126;
}
V_238 -> V_251 = F_80 ( V_68 , V_238 -> V_251 ) ;
V_66 = F_75 ( V_65 , V_238 ) ;
if ( V_66 ) {
F_19 ( L_112 , V_66 ) ;
goto V_126;
}
V_66 = F_76 ( V_65 , V_238 , V_238 -> V_256 == V_290 ) ;
if ( V_66 ) {
F_19 ( L_113 , V_66 ) ;
goto V_126;
}
V_66 = F_77 ( V_65 , V_238 ) ;
if ( V_66 ) {
F_19 ( L_114 , V_66 ) ;
goto V_126;
}
V_66 = F_79 ( V_65 , V_238 ) ;
if ( V_66 ) {
F_19 ( L_115 , V_66 ) ;
goto V_126;
}
V_213 -> V_146 . V_142 = F_57 ( T_4 , ( T_4 ) sizeof( V_213 -> V_146 . V_145 ) ,
( T_4 ) V_238 -> V_144 ) ;
memcpy ( & V_213 -> V_146 . V_145 , V_238 -> V_146 , V_213 -> V_146 . V_142 ) ;
if ( V_213 -> V_146 . V_142 < V_291 ) {
V_213 -> V_146 . V_145 [ V_213 -> V_146 . V_142 ] = 0 ;
F_3 ( V_219 , L_116 , V_213 -> V_146 . V_145 ,
V_213 -> V_146 . V_142 ) ;
}
V_216 = F_45 ( struct V_286 , V_292 ) +
F_45 ( struct V_293 , V_232 ) ;
if ( V_97 -> V_231 )
V_216 += sizeof( T_1 ) ;
V_287 = F_48 ( V_216 , V_154 ) ;
if ( V_287 == NULL ) {
V_66 = - V_155 ;
goto V_126;
}
V_287 -> V_139 . V_142 = F_13 ( V_213 -> V_146 . V_142 ) ;
memcpy ( & V_287 -> V_139 . V_145 , V_238 -> V_146 ,
V_213 -> V_146 . V_142 ) ;
V_287 -> V_294 . V_110 = - 1 ;
V_287 -> V_294 . V_115 = F_13 ( - 1 ) ;
if ( V_238 -> V_106 )
memcpy ( & V_287 -> V_292 . V_106 , V_238 -> V_106 , V_107 ) ;
else
memset ( & V_287 -> V_292 . V_106 , 0xFF , V_107 ) ;
if ( V_97 -> V_231 ) {
V_287 -> V_292 . V_233 = F_13 ( 1 ) ;
V_287 -> V_292 . V_232 [ 0 ] =
F_14 ( V_136 ) ;
V_287 -> V_294 . V_113 =
F_13 ( V_295 ) ;
V_287 -> V_294 . V_114 =
F_13 ( V_296 ) ;
V_287 -> V_294 . V_112 =
F_13 ( V_295 /
V_297 ) ;
} else {
V_287 -> V_294 . V_113 = F_13 ( - 1 ) ;
V_287 -> V_294 . V_114 = F_13 ( - 1 ) ;
V_287 -> V_294 . V_112 = F_13 ( - 1 ) ;
}
V_66 = F_17 ( V_68 , L_117 , V_287 ,
V_216 ) ;
F_51 ( V_287 ) ;
if ( ! V_66 )
goto V_126;
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
V_216 = sizeof( V_215 . V_139 ) ;
memcpy ( & V_215 . V_139 . V_145 , V_238 -> V_146 , V_213 -> V_146 . V_142 ) ;
V_215 . V_139 . V_142 = F_13 ( V_213 -> V_146 . V_142 ) ;
if ( V_238 -> V_106 )
memcpy ( V_215 . V_101 . V_106 , V_238 -> V_106 , V_107 ) ;
else
memset ( V_215 . V_101 . V_106 , 0xFF , V_107 ) ;
if ( V_97 -> V_231 ) {
V_215 . V_101 . V_232 [ 0 ] = F_14 ( V_136 ) ;
V_215 . V_101 . V_233 = F_13 ( 1 ) ;
V_216 += sizeof( V_215 . V_101 ) ;
}
V_66 = F_31 ( V_68 , V_236 ,
& V_215 , V_216 ) ;
if ( V_66 )
F_19 ( L_118 , V_66 ) ;
V_126:
if ( V_66 )
F_58 ( V_182 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_84 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_1 V_298 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_299 V_300 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_119 , V_298 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
F_58 ( V_209 , & V_68 -> V_2 -> V_4 ) ;
F_68 ( V_65 , V_298 , NULL , 0 , V_154 ) ;
memcpy ( & V_300 . V_63 , & V_213 -> V_106 , V_107 ) ;
V_300 . V_241 = F_13 ( V_298 ) ;
V_66 = F_31 ( V_68 , V_210 ,
& V_300 , sizeof( V_300 ) ) ;
if ( V_66 )
F_19 ( L_42 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_85 ( struct V_81 * V_81 , struct V_80 * V_76 ,
enum V_301 type , T_5 V_302 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_64 * V_65 = F_65 ( V_97 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_1 V_303 ;
T_5 V_66 = 0 ;
T_5 V_304 = 0 ;
T_5 V_305 = F_86 ( V_302 ) ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
switch ( type ) {
case V_306 :
break;
case V_307 :
case V_308 :
if ( V_305 < 0 ) {
F_19 ( L_120 ) ;
V_66 = - V_94 ;
goto V_126;
}
break;
}
V_304 = V_309 << 16 ;
V_66 = F_43 ( V_68 , V_310 , V_304 ) ;
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
V_97 -> V_201 -> V_311 = V_305 ;
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_87 ( struct V_81 * V_81 ,
struct V_80 * V_76 ,
T_5 * V_305 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( F_65 ( V_97 ) ) ;
T_5 V_312 ;
T_2 V_313 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
V_66 = F_88 ( V_68 , L_122 , & V_312 ) ;
if ( V_66 ) {
F_19 ( L_42 , V_66 ) ;
goto V_126;
}
V_313 = ( T_2 ) ( V_312 & ~ V_314 ) ;
* V_305 = ( T_5 ) F_4 ( V_313 ) ;
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_89 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 V_277 , bool V_315 , bool V_316 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_4 V_55 ;
T_4 V_217 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_219 , L_124 , V_277 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
V_66 = F_78 ( V_68 , L_76 , & V_217 ) ;
if ( V_66 ) {
F_19 ( L_125 , V_66 ) ;
goto V_126;
}
if ( V_217 & V_227 ) {
V_55 = V_277 ;
V_66 = F_43 ( V_68 ,
V_317 , V_55 ) ;
if ( V_66 )
F_19 ( L_42 , V_66 ) ;
}
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_90 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 V_277 , const T_2 * V_318 , struct V_319 * V_84 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_66 = 0 ;
T_2 V_320 [ 8 ] ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_55 = ( T_4 ) V_277 ;
if ( ! F_91 ( V_318 ) )
memcpy ( ( char * ) & V_32 . V_63 , ( void * ) V_318 , V_107 ) ;
V_32 . V_36 = ( T_4 ) V_84 -> V_276 ;
if ( V_32 . V_36 == 0 ) {
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
F_19 ( L_126 , V_66 ) ;
} else {
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_127 , V_32 . V_36 ) ;
return - V_94 ;
}
F_3 ( V_219 , L_128 , V_32 . V_55 ) ;
memcpy ( V_32 . V_62 , V_84 -> V_32 , V_32 . V_36 ) ;
if ( ! F_22 ( V_68 -> V_2 ) &&
( V_84 -> V_321 == V_263 ) ) {
F_3 ( V_219 , L_129 ) ;
memcpy ( V_320 , & V_32 . V_62 [ 24 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 24 ] , & V_32 . V_62 [ 16 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 16 ] , V_320 , sizeof( V_320 ) ) ;
}
if ( V_84 -> V_322 && V_84 -> V_323 == 6 ) {
T_2 * V_324 ;
V_324 = ( T_2 * ) V_84 -> V_322 ;
V_32 . V_58 . V_59 = ( V_324 [ 5 ] << 24 ) | ( V_324 [ 4 ] << 16 ) |
( V_324 [ 3 ] << 8 ) | V_324 [ 2 ] ;
V_32 . V_58 . V_60 = ( V_324 [ 1 ] << 8 ) | V_324 [ 0 ] ;
V_32 . V_61 = true ;
}
switch ( V_84 -> V_321 ) {
case V_261 :
V_32 . V_56 = V_279 ;
F_3 ( V_219 , L_130 ) ;
break;
case V_262 :
V_32 . V_56 = V_280 ;
F_3 ( V_219 , L_131 ) ;
break;
case V_263 :
V_32 . V_56 = V_325 ;
F_3 ( V_219 , L_132 ) ;
break;
case V_267 :
V_32 . V_56 = V_326 ;
F_3 ( V_219 , L_133 ) ;
break;
case V_265 :
V_32 . V_56 = V_326 ;
F_3 ( V_219 , L_134 ) ;
break;
default:
F_19 ( L_135 , V_84 -> V_321 ) ;
return - V_94 ;
}
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
F_19 ( L_3 , V_66 ) ;
}
return V_66 ;
}
static T_5
F_92 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 V_277 , bool V_327 , const T_2 * V_318 ,
struct V_319 * V_84 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_241 ;
T_5 V_217 ;
T_5 V_66 = 0 ;
T_2 V_320 [ 8 ] ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_219 , L_124 , V_277 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( V_318 &&
( V_84 -> V_321 != V_261 ) &&
( V_84 -> V_321 != V_262 ) ) {
F_3 ( V_73 , L_136 ) ;
return F_90 ( V_81 , V_65 , V_277 , V_318 , V_84 ) ;
}
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_36 = ( T_4 ) V_84 -> V_276 ;
V_32 . V_55 = ( T_4 ) V_277 ;
if ( V_32 . V_36 > sizeof( V_32 . V_62 ) ) {
F_19 ( L_99 , V_32 . V_36 ) ;
V_66 = - V_94 ;
goto V_126;
}
memcpy ( V_32 . V_62 , V_84 -> V_32 , V_32 . V_36 ) ;
V_32 . V_57 = V_278 ;
switch ( V_84 -> V_321 ) {
case V_261 :
V_32 . V_56 = V_279 ;
V_241 = V_227 ;
F_3 ( V_219 , L_130 ) ;
break;
case V_262 :
V_32 . V_56 = V_280 ;
V_241 = V_227 ;
F_3 ( V_219 , L_131 ) ;
break;
case V_263 :
if ( ! F_22 ( V_68 -> V_2 ) ) {
F_3 ( V_219 , L_129 ) ;
memcpy ( V_320 , & V_32 . V_62 [ 24 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 24 ] , & V_32 . V_62 [ 16 ] , sizeof( V_320 ) ) ;
memcpy ( & V_32 . V_62 [ 16 ] , V_320 , sizeof( V_320 ) ) ;
}
V_32 . V_56 = V_325 ;
V_241 = V_264 ;
F_3 ( V_219 , L_132 ) ;
break;
case V_267 :
V_32 . V_56 = V_326 ;
V_241 = V_266 ;
F_3 ( V_219 , L_133 ) ;
break;
case V_265 :
V_32 . V_56 = V_326 ;
V_241 = V_266 ;
F_3 ( V_219 , L_134 ) ;
break;
default:
F_19 ( L_135 , V_84 -> V_321 ) ;
V_66 = - V_94 ;
goto V_126;
}
V_66 = F_15 ( V_65 , & V_32 ) ;
if ( V_66 )
goto V_126;
V_66 = F_78 ( V_68 , L_76 , & V_217 ) ;
if ( V_66 ) {
F_19 ( L_137 , V_66 ) ;
goto V_126;
}
V_217 |= V_241 ;
V_66 = F_74 ( V_68 , L_76 , V_217 ) ;
if ( V_66 ) {
F_19 ( L_138 , V_66 ) ;
goto V_126;
}
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_93 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 V_277 , bool V_327 , const T_2 * V_318 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_52 V_32 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( V_277 >= V_328 ) {
F_19 ( L_139 , V_277 ) ;
return - V_94 ;
}
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_55 = ( T_4 ) V_277 ;
V_32 . V_57 = V_278 ;
V_32 . V_56 = V_329 ;
F_3 ( V_219 , L_124 , V_277 ) ;
V_66 = F_15 ( V_65 , & V_32 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_94 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 V_277 , bool V_327 , const T_2 * V_318 , void * V_330 ,
void (* F_95) ( void * V_330 , struct V_319 * V_84 ) )
{
struct V_319 V_84 ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_239 * V_240 ;
T_5 V_217 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
F_3 ( V_219 , L_124 , V_277 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_66 = F_78 ( V_68 , L_76 , & V_217 ) ;
if ( V_66 ) {
F_19 ( L_125 , V_66 ) ;
V_66 = - V_130 ;
goto V_126;
}
if ( V_217 & V_227 ) {
V_240 = & V_213 -> V_240 ;
if ( V_240 -> V_270 & V_261 ) {
V_84 . V_321 = V_261 ;
F_3 ( V_219 , L_130 ) ;
} else if ( V_240 -> V_270 & V_262 ) {
V_84 . V_321 = V_262 ;
F_3 ( V_219 , L_131 ) ;
}
} else if ( V_217 & V_264 ) {
V_84 . V_321 = V_263 ;
F_3 ( V_219 , L_132 ) ;
} else if ( V_217 & V_266 ) {
V_84 . V_321 = V_267 ;
F_3 ( V_219 , L_133 ) ;
} else {
F_19 ( L_140 , V_217 ) ;
V_66 = - V_94 ;
goto V_126;
}
F_95 ( V_330 , & V_84 ) ;
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_96 ( struct V_81 * V_81 ,
struct V_64 * V_65 , T_2 V_277 )
{
F_3 ( V_5 , L_141 ) ;
return - V_90 ;
}
static T_5
F_97 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 * V_331 , struct V_332 * V_333 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_299 V_334 ;
int V_335 ;
T_5 V_336 ;
T_5 V_66 = 0 ;
T_2 * V_106 = V_213 -> V_106 ;
struct V_337 V_338 ;
T_4 V_339 ;
T_4 V_340 ;
F_3 ( V_73 , L_142 , V_331 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
if ( F_22 ( V_68 -> V_2 ) ) {
memcpy ( & V_338 , V_331 , V_107 ) ;
V_66 = F_98 ( V_68 , L_143 ,
& V_338 ,
sizeof( V_338 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_144 , V_66 ) ;
goto V_126;
}
V_333 -> V_341 = V_342 ;
V_333 -> V_343 = F_99 ( V_338 . V_344 ) * 1000 ;
if ( F_99 ( V_338 . V_57 ) & V_345 ) {
V_333 -> V_341 |= V_346 ;
V_333 -> V_347 = F_99 ( V_338 . V_348 ) ;
}
F_3 ( V_73 , L_145 ,
V_333 -> V_343 , V_333 -> V_347 ) ;
} else if ( V_68 -> V_2 -> V_76 . V_75 == V_85 ) {
if ( memcmp ( V_331 , V_106 , V_107 ) ) {
F_19 ( L_146 ,
V_331 , V_106 ) ;
V_66 = - V_349 ;
goto V_126;
}
V_66 = F_100 ( V_68 , V_350 , & V_336 ) ;
if ( V_66 ) {
F_19 ( L_147 , V_66 ) ;
goto V_126;
} else {
V_333 -> V_341 |= V_351 ;
V_333 -> V_352 . V_353 = V_336 * 5 ;
F_3 ( V_219 , L_148 , V_336 / 2 ) ;
}
if ( F_2 ( V_209 ,
& V_68 -> V_2 -> V_4 ) ) {
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_66 = F_101 ( V_68 , V_354 ,
& V_334 , sizeof( V_334 ) ) ;
if ( V_66 ) {
F_19 ( L_149 , V_66 ) ;
goto V_126;
} else {
V_335 = F_99 ( V_334 . V_241 ) ;
V_333 -> V_341 |= V_355 ;
V_333 -> signal = V_335 ;
F_3 ( V_219 , L_150 , V_335 ) ;
}
V_66 = F_100 ( V_68 , V_356 ,
& V_339 ) ;
if ( V_66 ) {
F_19 ( L_151 ,
V_66 ) ;
goto V_126;
} else {
V_333 -> V_357 . V_224 =
V_339 ;
F_3 ( V_219 , L_152 ,
V_339 ) ;
}
V_66 = F_100 ( V_68 , V_358 ,
& V_340 ) ;
if ( V_66 ) {
F_19 ( L_153 ,
V_66 ) ;
goto V_126;
} else {
V_333 -> V_357 . V_340 = V_340 ;
F_3 ( V_219 , L_154 ,
V_340 ) ;
}
V_333 -> V_341 |= V_359 ;
}
} else
V_66 = - V_360 ;
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_102 ( struct V_81 * V_81 , struct V_64 * V_65 ,
bool V_361 , T_5 V_362 )
{
T_5 V_363 ;
T_5 V_66 = 0 ;
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
F_3 ( V_73 , L_13 ) ;
V_97 -> V_364 = V_361 ;
if ( ! F_1 ( V_68 -> V_2 ) ) {
F_3 ( V_5 , L_155 ) ;
goto V_126;
}
V_363 = V_361 ? V_365 : V_366 ;
if ( V_68 -> V_2 -> V_76 . V_75 == V_91 ) {
F_3 ( V_5 , L_156 ) ;
V_363 = V_366 ;
}
F_3 ( V_5 , L_157 , ( V_363 ? L_158 : L_159 ) ) ;
V_66 = F_43 ( V_68 , V_367 , V_363 ) ;
if ( V_66 ) {
if ( V_66 == - V_368 )
F_19 ( L_160 ) ;
else
F_19 ( L_42 , V_66 ) ;
}
V_126:
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_103 ( struct V_96 * V_97 ,
struct V_369 * V_370 )
{
struct V_81 * V_81 = F_33 ( V_97 ) ;
struct V_19 * V_371 ;
struct V_372 * V_373 ;
struct V_374 * V_375 ;
struct V_21 V_20 ;
T_5 V_66 = 0 ;
T_1 V_231 ;
T_4 V_376 ;
T_1 V_377 ;
T_1 V_378 ;
T_2 * V_379 ;
T_6 V_380 ;
T_5 V_381 ;
if ( F_99 ( V_370 -> V_382 ) > V_383 ) {
F_19 ( L_161 ) ;
return 0 ;
}
if ( ! V_370 -> V_384 ) {
V_20 . V_28 = F_104 ( V_370 -> V_136 ) ;
V_97 -> V_18 . V_385 ( & V_20 ) ;
V_370 -> V_384 = V_20 . V_23 ;
}
V_231 = V_370 -> V_384 ;
if ( V_231 <= V_386 )
V_375 = V_81 -> V_387 [ V_388 ] ;
else
V_375 = V_81 -> V_387 [ V_389 ] ;
V_376 = F_105 ( V_231 , V_375 -> V_375 ) ;
V_371 = F_106 ( V_81 , V_376 ) ;
V_377 = F_104 ( V_370 -> V_390 ) ;
V_378 = F_104 ( V_370 -> V_339 ) ;
V_379 = ( T_2 * ) V_370 + F_104 ( V_370 -> V_391 ) ;
V_380 = F_99 ( V_370 -> V_392 ) ;
V_381 = ( V_393 ) F_104 ( V_370 -> V_394 ) * 100 ;
F_3 ( V_219 , L_162 , V_370 -> V_395 ) ;
F_3 ( V_219 , L_163 , V_231 , V_376 ) ;
F_3 ( V_219 , L_164 , V_377 ) ;
F_3 ( V_219 , L_165 , V_378 ) ;
F_3 ( V_219 , L_166 , V_381 ) ;
V_373 = F_107 ( V_81 , V_371 , ( const T_2 * ) V_370 -> V_395 ,
0 , V_377 , V_378 , V_379 ,
V_380 , V_381 , V_154 ) ;
if ( ! V_373 )
return - V_155 ;
F_108 ( V_81 , V_373 ) ;
return V_66 ;
}
static struct V_369 *
F_109 ( struct V_161 * V_396 , struct V_369 * V_373 )
{
if ( V_373 == NULL )
return V_396 -> V_397 ;
return (struct V_369 * ) ( ( unsigned long ) V_373 +
F_99 ( V_373 -> V_382 ) ) ;
}
static T_5 F_110 ( struct V_96 * V_97 )
{
struct V_161 * V_398 ;
struct V_369 * V_370 = NULL ;
T_5 V_66 = 0 ;
int V_135 ;
V_398 = V_97 -> V_398 ;
if ( V_398 -> V_169 != 0 &&
V_398 -> V_157 != V_399 ) {
F_19 ( L_167 ,
V_398 -> V_157 ) ;
return - V_90 ;
}
F_3 ( V_104 , L_168 , V_398 -> V_169 ) ;
for ( V_135 = 0 ; V_135 < V_398 -> V_169 ; V_135 ++ ) {
V_370 = F_109 ( V_398 , V_370 ) ;
V_66 = F_103 ( V_97 , V_370 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static T_5 F_111 ( struct V_96 * V_97 ,
struct V_64 * V_65 , const T_2 * V_106 )
{
struct V_81 * V_81 = F_33 ( V_97 ) ;
struct V_19 * V_371 ;
struct V_369 * V_370 = NULL ;
struct V_374 * V_375 ;
struct V_372 * V_373 ;
struct V_21 V_20 ;
T_2 * V_30 = NULL ;
T_5 V_66 = 0 ;
T_4 V_376 ;
T_1 V_377 ;
T_1 V_378 ;
T_2 * V_379 ;
T_6 V_380 ;
T_5 V_381 ;
F_3 ( V_73 , L_13 ) ;
V_30 = F_48 ( V_383 , V_154 ) ;
if ( V_30 == NULL ) {
V_66 = - V_155 ;
goto V_400;
}
* ( V_401 * ) V_30 = F_13 ( V_383 ) ;
V_66 = F_101 ( F_18 ( V_65 ) , V_402 ,
V_30 , V_383 ) ;
if ( V_66 ) {
F_19 ( L_169 , V_66 ) ;
goto V_400;
}
V_370 = (struct V_369 * ) ( V_30 + 4 ) ;
V_20 . V_28 = F_104 ( V_370 -> V_136 ) ;
V_97 -> V_18 . V_385 ( & V_20 ) ;
if ( V_20 . V_375 == V_403 )
V_375 = V_81 -> V_387 [ V_388 ] ;
else
V_375 = V_81 -> V_387 [ V_389 ] ;
V_376 = F_105 ( V_20 . V_23 , V_375 -> V_375 ) ;
V_371 = F_106 ( V_81 , V_376 ) ;
V_377 = F_104 ( V_370 -> V_390 ) ;
V_378 = F_104 ( V_370 -> V_339 ) ;
V_379 = ( T_2 * ) V_370 + F_104 ( V_370 -> V_391 ) ;
V_380 = F_99 ( V_370 -> V_392 ) ;
V_381 = ( V_393 ) F_104 ( V_370 -> V_394 ) * 100 ;
F_3 ( V_219 , L_170 , V_20 . V_23 , V_376 ) ;
F_3 ( V_219 , L_171 , V_377 ) ;
F_3 ( V_219 , L_70 , V_378 ) ;
F_3 ( V_219 , L_172 , V_381 ) ;
V_373 = F_107 ( V_81 , V_371 , V_106 ,
0 , V_377 , V_378 ,
V_379 , V_380 , V_381 , V_154 ) ;
if ( ! V_373 ) {
V_66 = - V_155 ;
goto V_400;
}
F_108 ( V_81 , V_373 ) ;
V_400:
F_51 ( V_30 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5 F_112 ( struct V_96 * V_97 ,
struct V_67 * V_68 )
{
struct V_207 * V_213 = F_73 ( V_68 -> V_65 ) ;
struct V_369 * V_370 ;
struct V_153 * V_146 ;
const struct V_29 * V_404 ;
T_1 V_224 ;
T_2 V_340 ;
T_6 V_223 ;
T_2 * V_38 ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_23 ( V_68 -> V_2 ) )
return V_66 ;
V_146 = & V_213 -> V_146 ;
* ( V_401 * ) V_97 -> V_405 = F_13 ( V_406 ) ;
V_66 = F_101 ( V_68 , V_402 ,
V_97 -> V_405 , V_406 ) ;
if ( V_66 ) {
F_19 ( L_173 , V_66 ) ;
goto V_407;
}
V_370 = (struct V_369 * ) ( V_97 -> V_405 + 4 ) ;
V_66 = F_103 ( V_97 , V_370 ) ;
if ( V_66 )
goto V_407;
V_38 = ( ( T_2 * ) V_370 ) + F_104 ( V_370 -> V_391 ) ;
V_223 = F_99 ( V_370 -> V_392 ) ;
V_224 = F_104 ( V_370 -> V_339 ) ;
V_404 = F_8 ( V_38 , V_223 , V_408 ) ;
if ( V_404 )
V_340 = V_404 -> V_62 [ 1 ] ;
else {
T_4 V_409 ;
V_66 = F_88 ( V_68 , L_174 , & V_409 ) ;
if ( V_66 ) {
F_19 ( L_175 , V_66 ) ;
goto V_407;
}
V_340 = ( T_2 ) V_409 ;
}
V_407:
F_3 ( V_73 , L_136 ) ;
return V_66 ;
}
void F_113 ( struct V_96 * V_97 )
{
struct V_123 * V_163 = & V_97 -> V_123 ;
F_42 ( V_180 , & V_97 -> V_120 ) ;
if ( V_97 -> V_103 ) {
V_163 -> V_164 = V_410 ;
F_28 ( V_97 , V_163 -> V_68 , true , true ) ;
}
F_58 ( V_119 , & V_97 -> V_120 ) ;
F_58 ( V_180 , & V_97 -> V_120 ) ;
}
static void F_114 ( struct V_411 * V_412 )
{
struct V_96 * V_97 =
F_60 ( V_412 , struct V_96 ,
V_413 ) ;
F_28 ( V_97 , V_97 -> V_123 . V_68 , true , true ) ;
}
static void F_115 ( unsigned long V_62 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_62 ;
if ( V_97 -> V_103 ) {
F_19 ( L_176 ) ;
F_116 ( & V_97 -> V_413 ) ;
}
}
static T_5
F_117 ( struct V_96 * V_97 ,
struct V_369 * V_373 ,
struct V_369 * V_397 )
{
struct V_21 V_414 , V_415 ;
V_414 . V_28 = F_104 ( V_373 -> V_136 ) ;
V_97 -> V_18 . V_385 ( & V_414 ) ;
V_415 . V_28 = F_104 ( V_397 -> V_136 ) ;
V_97 -> V_18 . V_385 ( & V_415 ) ;
if ( ! memcmp ( & V_397 -> V_395 , & V_373 -> V_395 , V_107 ) &&
V_414 . V_375 == V_415 . V_375 &&
V_397 -> V_142 == V_373 -> V_142 &&
! memcmp ( V_397 -> V_145 , V_373 -> V_145 , V_397 -> V_142 ) ) {
if ( ( V_373 -> V_57 & V_416 ) ==
( V_397 -> V_57 & V_416 ) ) {
V_393 V_417 = F_104 ( V_373 -> V_394 ) ;
V_393 V_418 = F_104 ( V_397 -> V_394 ) ;
if ( V_418 > V_417 )
V_373 -> V_394 = V_397 -> V_394 ;
} else if ( ( V_373 -> V_57 & V_416 ) &&
( V_397 -> V_57 & V_416 ) == 0 ) {
V_373 -> V_394 = V_397 -> V_394 ;
V_373 -> V_57 |= V_416 ;
}
return 1 ;
}
return 0 ;
}
static T_5
F_118 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
T_5 V_423 ;
T_5 V_66 = 0 ;
struct V_424 * V_425 ;
struct V_369 * V_397 ;
struct V_369 * V_373 = NULL ;
T_4 V_426 ;
struct V_161 * V_396 ;
T_4 V_135 ;
bool V_98 ;
V_423 = V_420 -> V_423 ;
if ( ! F_2 ( V_119 , & V_97 -> V_120 ) ) {
F_19 ( L_177 , V_68 -> V_427 ) ;
return - V_360 ;
}
if ( V_423 == V_428 ) {
F_3 ( V_104 , L_178 ) ;
V_425 = (struct V_424 * ) V_62 ;
if ( ! V_425 ) {
F_19 ( L_179 ) ;
goto exit;
}
if ( F_104 ( V_425 -> V_429 ) != 1 ) {
F_19 ( L_180 ,
V_425 -> V_429 ) ;
goto exit;
}
V_397 = & V_425 -> V_397 ;
if ( F_119 ( V_97 , V_397 ) )
goto exit;
if ( ! V_97 -> V_103 ) {
F_3 ( V_104 , L_181 ) ;
goto exit;
}
V_426 = F_99 ( V_397 -> V_382 ) ;
if ( V_426 != ( F_99 ( V_425 -> V_31 ) -
V_170 ) ) {
F_19 ( L_182 ,
V_426 ) ;
goto exit;
}
if ( ! ( F_33 ( V_97 ) -> V_430 &
F_120 ( V_79 ) ) ) {
if ( F_104 ( V_397 -> V_390 ) &
V_431 ) {
F_19 ( L_183 ) ;
goto exit;
}
}
V_396 = (struct V_161 * )
V_97 -> V_123 . V_168 ;
if ( V_426 > V_432 - V_396 -> V_31 ) {
F_19 ( L_184 ) ;
goto exit;
}
for ( V_135 = 0 ; V_135 < V_396 -> V_169 ; V_135 ++ ) {
V_373 = V_373 ? (struct V_369 * )
( ( unsigned char * ) V_373 +
F_99 ( V_373 -> V_382 ) ) : V_396 -> V_397 ;
if ( F_117 ( V_97 , V_373 ,
V_397 ) )
goto exit;
}
memcpy ( & ( V_97 -> V_123 . V_168 [ V_396 -> V_31 ] ) ,
V_397 , V_426 ) ;
V_396 -> V_157 = F_99 ( V_397 -> V_157 ) ;
V_396 -> V_31 += V_426 ;
V_396 -> V_169 ++ ;
} else {
V_97 -> V_123 . V_164 = V_410 ;
if ( F_119 ( V_97 , NULL ) )
goto exit;
if ( V_97 -> V_103 ) {
V_97 -> V_398 = (struct V_161 * )
V_97 -> V_123 . V_168 ;
F_110 ( V_97 ) ;
V_98 = V_423 != V_433 ;
F_28 ( V_97 , V_68 , V_98 ,
false ) ;
} else
F_3 ( V_104 , L_185 ,
V_423 ) ;
}
exit:
return V_66 ;
}
static void F_121 ( struct V_96 * V_97 )
{
F_122 ( V_97 -> V_434 , V_435 ,
F_118 ) ;
V_97 -> V_123 . V_164 = V_410 ;
F_123 ( & V_97 -> V_105 ) ;
V_97 -> V_105 . V_62 = ( unsigned long ) V_97 ;
V_97 -> V_105 . V_436 = F_115 ;
F_124 ( & V_97 -> V_413 ,
F_114 ) ;
}
static T_7 void F_125 ( T_4 V_437 )
{
if ( V_437 < 1000 / V_189 ) {
F_126 () ;
F_127 ( V_437 ) ;
} else {
F_128 ( V_437 ) ;
}
}
static T_5 F_129 ( struct V_81 * V_81 )
{
F_3 ( V_73 , L_13 ) ;
return 0 ;
}
static T_5 F_130 ( struct V_81 * V_81 ,
struct V_438 * V_439 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_64 * V_65 = F_65 ( V_97 ) ;
struct V_1 * V_2 ;
F_3 ( V_73 , L_13 ) ;
V_2 = ( (struct V_67 * ) F_18 ( V_65 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_131 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_67 ( V_2 ) ;
F_125 ( 500 ) ;
}
if ( F_2 ( V_119 , & V_97 -> V_120 ) )
F_113 ( V_97 ) ;
F_27 ( F_18 ( V_65 ) , 1 ) ;
exit:
F_3 ( V_73 , L_30 ) ;
V_97 -> V_120 = 0 ;
return 0 ;
}
static T_8 T_5
F_132 ( struct V_64 * V_65 ,
struct V_440 * V_441 , T_5 V_66 )
{
int V_135 , V_442 ;
int V_443 ;
V_443 = F_99 ( V_441 -> V_444 . V_445 ) ;
F_3 ( V_219 , L_186 , V_443 ) ;
for ( V_135 = 0 ; V_135 < V_443 ; V_135 ++ ) {
F_3 ( V_219 , L_187 , V_135 ,
& V_441 -> V_444 . V_446 [ V_135 ] . V_395 ) ;
for ( V_442 = 0 ; V_442 < V_447 ; V_442 ++ )
F_3 ( V_219 , L_188 ,
V_441 -> V_444 . V_446 [ V_135 ] . V_448 [ V_442 ] ) ;
}
if ( ! V_66 )
F_50 ( F_18 ( V_65 ) , L_189 ,
( char * ) V_441 , sizeof( * V_441 ) ) ;
return V_66 ;
}
static T_5
F_133 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_449 * V_450 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_451 * V_444 = & V_97 -> V_441 -> V_444 ;
T_5 V_66 = 0 ;
int V_135 ;
int V_443 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
V_443 = F_99 ( V_444 -> V_445 ) ;
for ( V_135 = 0 ; V_135 < V_443 ; V_135 ++ )
if ( ! memcmp ( V_450 -> V_106 , V_444 -> V_446 [ V_135 ] . V_395 , V_107 ) )
break;
if ( V_135 < V_452 ) {
memcpy ( V_444 -> V_446 [ V_135 ] . V_395 , V_450 -> V_106 , V_107 ) ;
memcpy ( V_444 -> V_446 [ V_135 ] . V_448 , V_450 -> V_446 , V_447 ) ;
if ( V_135 == V_443 ) {
V_443 ++ ;
V_444 -> V_445 = F_13 ( V_443 ) ;
}
} else
V_66 = - V_94 ;
F_3 ( V_219 , L_190 ,
V_444 -> V_446 [ V_443 ] . V_395 ) ;
for ( V_135 = 0 ; V_135 < V_447 ; V_135 ++ )
F_3 ( V_219 , L_188 , V_444 -> V_446 [ V_443 ] . V_448 [ V_135 ] ) ;
V_66 = F_132 ( V_65 , V_97 -> V_441 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_134 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_449 * V_450 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_451 V_446 ;
T_5 V_66 = 0 ;
int V_135 , V_443 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
memcpy ( & V_446 . V_446 [ 0 ] . V_395 , V_450 -> V_106 , V_107 ) ;
memcpy ( & V_446 . V_446 [ 0 ] . V_448 , V_450 -> V_446 , V_447 ) ;
F_3 ( V_219 , L_191 ,
& V_446 . V_446 [ 0 ] . V_395 ) ;
for ( V_135 = 0 ; V_135 < V_447 ; V_135 ++ )
F_3 ( V_219 , L_188 , V_446 . V_446 [ 0 ] . V_448 [ V_135 ] ) ;
V_443 = F_99 ( V_97 -> V_441 -> V_444 . V_445 ) ;
for ( V_135 = 0 ; V_135 < V_443 ; V_135 ++ )
if ( ! memcmp
( V_450 -> V_106 , & V_97 -> V_441 -> V_444 . V_446 [ V_135 ] . V_395 ,
V_107 ) )
break;
if ( ( V_443 > 0 )
&& ( V_135 < V_443 ) ) {
memset ( & V_97 -> V_441 -> V_444 . V_446 [ V_135 ] , 0 ,
sizeof( struct V_446 ) ) ;
for (; V_135 < ( V_443 - 1 ) ; V_135 ++ ) {
memcpy ( & V_97 -> V_441 -> V_444 . V_446 [ V_135 ] . V_395 ,
& V_97 -> V_441 -> V_444 . V_446 [ V_135 + 1 ] . V_395 ,
V_107 ) ;
memcpy ( & V_97 -> V_441 -> V_444 . V_446 [ V_135 ] . V_448 ,
& V_97 -> V_441 -> V_444 . V_446 [ V_135 + 1 ] . V_448 ,
V_447 ) ;
}
V_97 -> V_441 -> V_444 . V_445 = F_13 ( V_443 - 1 ) ;
} else
V_66 = - V_94 ;
V_66 = F_132 ( V_65 , V_97 -> V_441 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_135 ( struct V_81 * V_81 , struct V_64 * V_65 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
memset ( V_97 -> V_441 , 0 , sizeof( * V_97 -> V_441 ) ) ;
V_66 = F_132 ( V_65 , V_97 -> V_441 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_136 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
struct V_453 * V_454 , * V_455 ;
struct V_102 * V_132 = NULL ;
struct V_173 * V_146 = NULL ;
struct V_19 * V_231 = NULL ;
struct V_81 * V_81 = F_33 ( V_97 ) ;
int V_66 = 0 ;
int V_456 = 0 ;
int V_375 = 0 ;
struct V_457 * V_458 ;
T_4 V_459 ;
T_4 V_423 ;
F_3 ( V_104 , L_13 ) ;
if ( V_420 -> V_460 == V_461 ) {
F_3 ( V_104 , L_192 ) ;
return 0 ;
}
V_458 = (struct V_457 * ) V_62 ;
V_459 = F_99 ( V_458 -> V_169 ) ;
V_423 = F_99 ( V_458 -> V_423 ) ;
F_137 ( V_423 != V_462 ) ;
F_3 ( V_104 , L_193 , V_459 ) ;
if ( V_459 > 0 ) {
int V_135 ;
V_132 = F_48 ( sizeof( * V_132 ) , V_154 ) ;
V_146 = F_138 ( V_459 , sizeof( * V_146 ) , V_154 ) ;
V_231 = F_138 ( V_459 , sizeof( * V_231 ) , V_154 ) ;
if ( ! V_132 || ! V_146 || ! V_231 ) {
V_66 = - V_155 ;
goto V_463;
}
V_132 -> V_81 = V_81 ;
V_62 += sizeof( struct V_457 ) ;
V_455 = (struct V_453 * ) V_62 ;
for ( V_135 = 0 ; V_135 < V_459 ; V_135 ++ ) {
V_454 = & V_455 [ V_135 ] ;
if ( ! V_454 ) {
F_19 ( L_194 ,
V_135 ) ;
V_66 = - V_94 ;
goto V_463;
}
F_3 ( V_104 , L_195 ,
V_454 -> V_145 , V_454 -> V_231 ) ;
memcpy ( V_146 [ V_135 ] . V_146 , V_454 -> V_145 , V_454 -> V_142 ) ;
V_146 [ V_135 ] . V_144 = V_454 -> V_142 ;
V_132 -> V_133 ++ ;
V_456 = V_454 -> V_231 ;
if ( V_456 <= V_386 )
V_375 = V_464 ;
else
V_375 = V_465 ;
V_231 [ V_135 ] . V_24 =
F_105 ( V_456 ,
V_375 ) ;
V_231 [ V_135 ] . V_375 = V_375 ;
V_231 [ V_135 ] . V_57 |= V_466 ;
V_132 -> V_140 [ V_135 ] = & V_231 [ V_135 ] ;
V_132 -> V_134 ++ ;
}
if ( V_132 -> V_133 )
V_132 -> V_143 = & V_146 [ 0 ] ;
if ( F_2 ( V_119 , & V_97 -> V_120 ) ) {
F_113 ( V_97 ) ;
}
F_42 ( V_119 , & V_97 -> V_120 ) ;
V_97 -> V_123 . V_171 = F_47 ;
V_66 = F_52 ( V_97 , V_81 , V_68 , V_132 ) ;
if ( V_66 ) {
F_58 ( V_119 , & V_97 -> V_120 ) ;
goto V_463;
}
V_97 -> V_118 = true ;
V_97 -> V_103 = V_132 ;
} else {
F_19 ( L_196 ) ;
goto V_463;
}
F_51 ( V_146 ) ;
F_51 ( V_231 ) ;
F_51 ( V_132 ) ;
return 0 ;
V_463:
F_51 ( V_146 ) ;
F_51 ( V_231 ) ;
F_51 ( V_132 ) ;
F_139 ( V_81 ) ;
return V_66 ;
}
static int F_140 ( struct V_64 * V_65 )
{
int V_467 ;
V_467 = F_21 ( F_18 ( V_65 ) , L_197 , 0 ) ;
if ( V_467 == 0 ) {
V_467 = F_50 ( F_18 ( V_65 ) , L_198 ,
NULL , 0 ) ;
}
if ( V_467 < 0 )
F_19 ( L_199 , V_467 ) ;
return V_467 ;
}
static int F_141 ( struct V_64 * V_65 )
{
struct V_468 V_469 ;
memset ( & V_469 , 0 , sizeof( V_469 ) ) ;
V_469 . V_157 = F_13 ( V_470 ) ;
V_469 . V_57 = F_14 ( 1 << V_471 ) ;
V_469 . V_472 = V_473 ;
V_469 . exp = V_474 ;
V_469 . V_475 = F_13 ( V_476 ) ;
return F_50 ( F_18 ( V_65 ) , L_200 ,
& V_469 , sizeof( V_469 ) ) ;
}
static int
F_142 ( struct V_81 * V_81 ,
struct V_64 * V_65 ,
struct V_477 * V_132 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_96 * V_97 = F_37 ( V_81 ) ;
struct V_478 V_479 ;
int V_135 ;
int V_467 = 0 ;
F_3 ( V_104 , L_201 ,
V_132 -> V_480 , V_132 -> V_133 ) ;
if ( F_2 ( V_119 , & V_97 -> V_120 ) ) {
F_19 ( L_44 , V_97 -> V_120 ) ;
return - V_130 ;
}
if ( F_2 ( V_181 , & V_97 -> V_120 ) ) {
F_19 ( L_46 ,
V_97 -> V_120 ) ;
return - V_130 ;
}
if ( ! V_132 -> V_133 || ! V_132 -> V_480 ) {
F_19 ( L_202 ,
V_132 -> V_133 ) ;
return - V_94 ;
}
if ( V_132 -> V_133 > 0 ) {
for ( V_135 = 0 ; V_135 < V_132 -> V_133 ; V_135 ++ ) {
F_3 ( V_104 , L_203 ,
V_132 -> V_143 [ V_135 ] . V_146 ) ;
}
}
if ( V_132 -> V_480 > 0 ) {
V_467 = F_140 ( V_65 ) ;
if ( V_467 < 0 ) {
F_19 ( L_204 , V_467 ) ;
return V_467 ;
}
V_467 = F_141 ( V_65 ) ;
if ( V_467 < 0 ) {
F_19 ( L_205 , V_467 ) ;
return - V_94 ;
}
for ( V_135 = 0 ; V_135 < V_132 -> V_480 ; V_135 ++ ) {
struct V_173 * V_146 ;
T_4 V_144 ;
V_146 = & V_132 -> V_481 [ V_135 ] . V_146 ;
V_144 = V_146 -> V_144 ;
if ( ! V_144 ) {
F_19 ( L_206 ) ;
continue;
}
V_479 . V_482 = F_13 ( V_483 ) ;
V_479 . V_275 = F_13 ( V_484 ) ;
V_479 . V_217 = F_13 ( 0 ) ;
V_479 . V_124 = F_13 ( 1 ) ;
V_479 . V_57 = F_13 ( 1 << V_485 ) ;
V_479 . V_146 . V_142 = F_13 ( V_144 ) ;
memcpy ( V_479 . V_146 . V_145 , V_146 -> V_146 , V_144 ) ;
V_467 = F_50 ( V_68 , L_207 , & V_479 ,
sizeof( V_479 ) ) ;
F_3 ( V_104 , L_208 ,
V_467 == 0 ? L_209 : L_210 , V_146 -> V_146 ) ;
}
if ( F_21 ( V_68 , L_197 , 1 ) < 0 ) {
F_19 ( L_211 , V_467 ) ;
return - V_94 ;
}
} else {
return - V_94 ;
}
return 0 ;
}
static int F_143 ( struct V_81 * V_81 ,
struct V_64 * V_65 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
F_3 ( V_104 , L_212 ) ;
F_140 ( V_65 ) ;
if ( V_97 -> V_118 )
F_28 ( V_97 , F_18 ( V_65 ) , true , true ) ;
return 0 ;
}
static int F_144 ( struct V_81 * V_81 ,
struct V_80 * V_76 ,
void * V_62 , int V_36 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_64 * V_65 = F_65 ( V_97 ) ;
struct V_486 * V_487 = V_62 ;
struct V_488 * V_489 ;
int V_467 ;
F_3 ( V_73 , L_213 , V_487 -> V_196 , V_487 -> V_490 ,
V_487 -> V_30 , V_487 -> V_36 ) ;
if ( V_487 -> V_490 )
V_467 = F_31 ( F_18 ( V_65 ) , V_487 -> V_196 ,
V_487 -> V_30 , V_487 -> V_36 ) ;
else
V_467 = F_101 ( F_18 ( V_65 ) , V_487 -> V_196 ,
V_487 -> V_30 , V_487 -> V_36 ) ;
if ( V_467 == 0 ) {
V_489 = F_145 ( V_81 , sizeof( * V_487 ) ) ;
F_146 ( V_489 , V_491 , sizeof( * V_487 ) , V_487 ) ;
V_467 = F_147 ( V_489 ) ;
}
return V_467 ;
}
static T_5 F_148 ( struct V_67 * V_68 )
{
T_5 V_66 ;
V_66 = F_74 ( V_68 , L_89 , 0 ) ;
if ( V_66 < 0 ) {
F_19 ( L_214 , V_66 ) ;
return V_66 ;
}
V_66 = F_74 ( V_68 , L_76 , 0 ) ;
if ( V_66 < 0 ) {
F_19 ( L_215 , V_66 ) ;
return V_66 ;
}
V_66 = F_74 ( V_68 , L_82 , V_492 ) ;
if ( V_66 < 0 ) {
F_19 ( L_216 , V_66 ) ;
return V_66 ;
}
return 0 ;
}
static bool F_149 ( T_2 * V_41 , bool V_493 )
{
if ( V_493 )
return ( memcmp ( V_41 , V_494 , V_49 ) == 0 ) ;
return ( memcmp ( V_41 , V_48 , V_49 ) == 0 ) ;
}
static T_5
F_150 ( struct V_64 * V_65 ,
const struct V_45 * V_285 ,
bool V_493 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_4 V_482 = 0 ;
T_1 V_169 ;
T_5 V_66 = 0 ;
T_5 V_36 = 0 ;
T_4 V_135 ;
T_4 V_217 ;
T_4 V_257 = 0 ;
T_4 V_258 = 0 ;
T_4 V_275 = 0 ;
T_4 V_13 ;
T_2 * V_62 ;
T_1 V_495 ;
T_4 V_496 ;
F_3 ( V_73 , L_13 ) ;
if ( V_285 == NULL )
goto exit;
V_36 = V_285 -> V_36 + V_35 ;
V_62 = ( T_2 * ) V_285 ;
V_13 = V_35 ;
if ( ! V_493 )
V_13 += V_497 ;
else
V_13 += V_498 ;
if ( V_13 + V_499 > V_36 ) {
V_66 = - V_94 ;
F_19 ( L_217 ) ;
goto exit;
}
if ( ! F_149 ( & V_62 [ V_13 ] , V_493 ) ) {
V_66 = - V_94 ;
F_19 ( L_218 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_500 :
V_258 = 0 ;
break;
case V_501 :
case V_502 :
V_258 = V_227 ;
break;
case V_503 :
V_258 = V_264 ;
break;
case V_504 :
V_258 = V_266 ;
break;
default:
V_66 = - V_94 ;
F_19 ( L_219 ) ;
goto exit;
}
V_13 ++ ;
V_169 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
V_13 += V_505 ;
if ( V_13 + ( V_499 * V_169 ) > V_36 ) {
V_66 = - V_94 ;
F_19 ( L_220 ) ;
goto exit;
}
for ( V_135 = 0 ; V_135 < V_169 ; V_135 ++ ) {
if ( ! F_149 ( & V_62 [ V_13 ] , V_493 ) ) {
V_66 = - V_94 ;
F_19 ( L_218 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_500 :
break;
case V_501 :
case V_502 :
V_257 |= V_227 ;
break;
case V_503 :
V_257 |= V_264 ;
break;
case V_504 :
V_257 |= V_266 ;
break;
default:
F_19 ( L_221 ) ;
}
V_13 ++ ;
}
V_169 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
V_13 += V_505 ;
if ( V_13 + ( V_499 * V_169 ) > V_36 ) {
V_66 = - V_94 ;
F_19 ( L_222 ) ;
goto exit;
}
for ( V_135 = 0 ; V_135 < V_169 ; V_135 ++ ) {
if ( ! F_149 ( & V_62 [ V_13 ] , V_493 ) ) {
V_66 = - V_94 ;
F_19 ( L_218 ) ;
goto exit;
}
V_13 += V_49 ;
switch ( V_62 [ V_13 ] ) {
case V_506 :
F_3 ( V_73 , L_223 ) ;
V_275 |= V_492 ;
break;
case V_507 :
F_3 ( V_73 , L_224 ) ;
V_493 ? ( V_275 |= V_249 ) :
( V_275 |= V_246 ) ;
break;
case V_508 :
F_3 ( V_73 , L_225 ) ;
V_493 ? ( V_275 |= V_248 ) :
( V_275 |= V_245 ) ;
break;
default:
F_19 ( L_226 ) ;
}
V_13 ++ ;
}
if ( V_493 ) {
V_496 = 1 ;
if ( ( V_13 + V_509 ) <= V_36 ) {
V_495 = V_62 [ V_13 ] + ( V_62 [ V_13 + 1 ] << 8 ) ;
if ( V_495 & V_510 )
V_496 = 0 ;
}
V_66 = F_74 ( V_68 , L_227 ,
V_496 ) ;
if ( V_66 < 0 ) {
F_19 ( L_228 , V_66 ) ;
goto exit;
}
}
V_217 = ( V_257 | V_258 | V_511 ) ;
V_66 = F_74 ( V_68 , L_89 , V_482 ) ;
if ( V_66 < 0 ) {
F_19 ( L_214 , V_66 ) ;
goto exit;
}
V_66 = F_74 ( V_68 , L_76 , V_217 ) ;
if ( V_66 < 0 ) {
F_19 ( L_215 , V_66 ) ;
goto exit;
}
V_66 = F_74 ( V_68 , L_82 , V_275 ) ;
if ( V_66 < 0 ) {
F_19 ( L_216 , V_66 ) ;
goto exit;
}
exit:
return V_66 ;
}
static T_5
F_151 ( const T_2 * V_512 , T_4 V_513 ,
struct V_514 * V_515 )
{
T_5 V_66 = 0 ;
struct V_45 * V_516 ;
struct V_29 * V_38 ;
struct V_517 * V_518 ;
T_5 V_519 ;
V_519 = ( T_5 ) V_513 ;
memset ( V_515 , 0 , sizeof( * V_515 ) ) ;
V_38 = (struct V_29 * ) V_512 ;
while ( V_38 ) {
if ( V_38 -> V_37 != V_47 )
goto V_520;
V_516 = (struct V_45 * ) V_38 ;
if ( V_516 -> V_36 < ( V_497 - V_35 + 1 ) ) {
F_19 ( L_229 ,
V_516 -> V_36 ) ;
goto V_520;
}
if ( ! memcmp ( V_516 -> V_41 , ( T_2 * ) V_48 , V_49 ) &&
( ( V_516 -> V_521 == V_50 ) ||
( V_516 -> V_521 == V_522 ) ) ) {
F_3 ( V_73 , L_230 ) ;
goto V_520;
}
V_518 = & V_515 -> V_523 [ V_515 -> V_169 ] ;
V_518 -> V_524 = ( char * ) V_516 ;
V_518 -> V_223 = V_516 -> V_36 + V_35 ;
memcpy ( & V_518 -> V_516 , V_516 , sizeof( * V_516 ) ) ;
V_515 -> V_169 ++ ;
F_3 ( V_73 , L_231 ,
V_518 -> V_516 . V_41 [ 0 ] ,
V_518 -> V_516 . V_41 [ 1 ] ,
V_518 -> V_516 . V_41 [ 2 ] ,
V_518 -> V_516 . V_521 ) ;
if ( V_515 -> V_169 >= V_525 )
break;
V_520:
V_519 -= ( V_38 -> V_36 + V_35 ) ;
if ( V_519 <= V_35 )
V_38 = NULL ;
else
V_38 = (struct V_29 * ) ( ( ( T_2 * ) V_38 ) + V_38 -> V_36 +
V_35 ) ;
}
return V_66 ;
}
static T_4
F_152 ( T_2 * V_526 , T_5 V_527 , T_2 * V_524 , T_4 V_223 , T_9 * V_528 )
{
V_401 V_529 ;
V_401 V_530 ;
strncpy ( V_526 , V_528 , V_531 - 1 ) ;
V_526 [ V_531 - 1 ] = '\0' ;
V_529 = F_13 ( 1 ) ;
memcpy ( & V_526 [ V_532 ] , & V_529 , sizeof( V_529 ) ) ;
V_530 = F_13 ( V_527 ) ;
memcpy ( & V_526 [ V_533 ] , & V_530 , sizeof( V_530 ) ) ;
memcpy ( & V_526 [ V_534 ] , V_524 , V_223 ) ;
return V_223 + V_535 ;
}
T_5 F_83 ( struct V_1 * V_2 , T_5 V_527 ,
const T_2 * V_512 , T_4 V_513 )
{
struct V_67 * V_68 ;
struct V_536 * V_537 ;
T_5 V_66 = 0 ;
T_2 * V_538 ;
T_2 * V_539 ;
T_2 * V_540 = NULL ;
int V_541 ;
T_4 * V_542 ;
T_4 V_543 = 0 ;
T_4 V_544 = 0 ;
T_4 V_545 = 0 ;
struct V_514 V_546 ;
struct V_514 V_547 ;
struct V_517 * V_548 ;
T_5 V_135 ;
T_2 * V_137 ;
int V_549 ;
if ( ! V_2 )
return - V_368 ;
V_68 = V_2 -> V_68 ;
V_537 = & V_2 -> V_537 ;
F_3 ( V_73 , L_232 , V_68 -> V_427 , V_527 ) ;
V_538 = F_48 ( V_406 , V_154 ) ;
if ( ! V_538 )
return - V_155 ;
V_539 = V_538 ;
switch ( V_527 ) {
case V_550 :
V_540 = V_537 -> V_551 ;
V_542 = & V_537 -> V_552 ;
V_541 = sizeof( V_537 -> V_551 ) ;
break;
case V_553 :
V_540 = V_537 -> V_554 ;
V_542 = & V_537 -> V_555 ;
V_541 = sizeof( V_537 -> V_554 ) ;
break;
case V_556 :
V_540 = V_537 -> V_557 ;
V_542 = & V_537 -> V_558 ;
V_541 = sizeof( V_537 -> V_557 ) ;
break;
case V_289 :
V_540 = V_537 -> V_559 ;
V_542 = & V_537 -> V_560 ;
V_541 = sizeof( V_537 -> V_559 ) ;
break;
default:
V_66 = - V_360 ;
F_19 ( L_233 ) ;
goto exit;
}
if ( V_513 > V_541 ) {
V_66 = - V_155 ;
F_19 ( L_234 ) ;
goto exit;
}
if ( V_512 && V_513 && V_539 ) {
V_137 = V_539 ;
F_151 ( V_512 , V_513 , & V_547 ) ;
for ( V_135 = 0 ; V_135 < V_547 . V_169 ; V_135 ++ ) {
V_548 = & V_547 . V_523 [ V_135 ] ;
memcpy ( V_137 + V_545 , V_548 -> V_524 ,
V_548 -> V_223 ) ;
V_545 += V_548 -> V_223 ;
}
}
if ( V_540 && * V_542 ) {
if ( V_545 && ( V_545 == * V_542 ) &&
( memcmp ( V_540 , V_539 ,
V_545 ) == 0 ) ) {
F_3 ( V_73 , L_235 ) ;
goto exit;
}
F_151 ( V_540 , * V_542 , & V_546 ) ;
for ( V_135 = 0 ; V_135 < V_546 . V_169 ; V_135 ++ ) {
V_548 = & V_546 . V_523 [ V_135 ] ;
F_3 ( V_73 , L_236 ,
V_548 -> V_516 . V_37 ,
V_548 -> V_516 . V_36 ,
V_548 -> V_516 . V_41 [ 0 ] ,
V_548 -> V_516 . V_41 [ 1 ] ,
V_548 -> V_516 . V_41 [ 2 ] ) ;
V_543 = F_152 ( V_539 , V_527 ,
V_548 -> V_524 ,
V_548 -> V_223 ,
L_237 ) ;
V_539 += V_543 ;
V_544 += V_543 ;
}
}
* V_542 = 0 ;
if ( V_540 && V_545 ) {
V_137 = V_540 ;
V_549 = V_541 ;
for ( V_135 = 0 ; V_135 < V_547 . V_169 ; V_135 ++ ) {
V_548 = & V_547 . V_523 [ V_135 ] ;
if ( V_549 < ( V_548 -> V_516 . V_36 +
V_534 ) ) {
F_19 ( L_238 ,
V_549 ) ;
break;
}
V_549 -= ( V_548 -> V_223 +
V_534 ) ;
F_3 ( V_73 , L_239 ,
V_548 -> V_516 . V_37 ,
V_548 -> V_516 . V_36 ,
V_548 -> V_516 . V_41 [ 0 ] ,
V_548 -> V_516 . V_41 [ 1 ] ,
V_548 -> V_516 . V_41 [ 2 ] ) ;
V_543 = F_152 ( V_539 , V_527 ,
V_548 -> V_524 ,
V_548 -> V_223 ,
L_240 ) ;
memcpy ( V_137 + ( * V_542 ) , V_548 -> V_524 ,
V_548 -> V_223 ) ;
* V_542 += V_548 -> V_223 ;
V_539 += V_543 ;
V_544 += V_543 ;
}
}
if ( V_544 ) {
V_66 = F_17 ( V_68 , L_241 , V_538 ,
V_544 ) ;
if ( V_66 )
F_19 ( L_242 , V_66 ) ;
}
exit:
F_51 ( V_538 ) ;
return V_66 ;
}
T_5 F_153 ( struct V_1 * V_2 )
{
T_5 V_561 [] = {
V_550 ,
V_553 ,
V_556
} ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_154 ( V_561 ) ; V_135 ++ )
F_83 ( V_2 , V_561 [ V_135 ] , NULL , 0 ) ;
memset ( & V_2 -> V_537 , 0 , sizeof( V_2 -> V_537 ) ) ;
return 0 ;
}
static T_5
F_155 ( struct V_1 * V_2 ,
struct V_562 * V_563 )
{
T_5 V_66 ;
V_66 = F_83 ( V_2 , V_556 ,
V_563 -> V_564 , V_563 -> V_565 ) ;
if ( V_66 ) {
F_19 ( L_243 ) ;
return V_66 ;
}
F_3 ( V_73 , L_244 ) ;
V_66 = F_83 ( V_2 , V_553 ,
V_563 -> V_566 ,
V_563 -> V_567 ) ;
if ( V_66 )
F_19 ( L_245 ) ;
else
F_3 ( V_73 , L_246 ) ;
return V_66 ;
}
static T_5
F_156 ( struct V_96 * V_97 ,
struct V_67 * V_68 ,
struct V_19 * V_231 )
{
T_1 V_136 ;
T_5 V_66 ;
F_3 ( V_73 , L_247 , V_231 -> V_375 ,
V_231 -> V_24 ) ;
V_136 = F_6 ( & V_97 -> V_18 , V_231 ) ;
V_66 = F_21 ( V_68 , L_248 , V_136 ) ;
return V_66 ;
}
static T_5
F_157 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_568 * V_569 )
{
T_5 V_391 ;
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
const struct V_29 * V_570 ;
struct V_138 V_139 ;
T_5 V_66 = - V_360 ;
const struct V_29 * V_284 ;
const struct V_45 * V_285 ;
struct V_214 V_215 ;
enum V_74 V_571 ;
struct V_572 V_573 ;
F_3 ( V_73 , L_249 ,
F_158 ( & V_569 -> V_220 ) ,
V_569 -> V_224 ,
V_569 -> V_340 ) ;
F_3 ( V_73 , L_250 ,
V_569 -> V_146 , V_569 -> V_144 , V_569 -> V_251 ,
V_569 -> V_574 ) ;
V_571 = V_68 -> V_2 -> V_76 . V_75 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( V_569 -> V_146 == NULL || V_569 -> V_144 == 0 ) {
V_391 = V_575 + V_576 ;
V_570 = F_8 (
( T_2 * ) & V_569 -> V_563 . V_577 [ V_391 ] ,
V_569 -> V_563 . V_578 - V_391 ,
V_579 ) ;
if ( ! V_570 )
return - V_94 ;
memcpy ( V_139 . V_145 , V_570 -> V_62 , V_570 -> V_36 ) ;
V_139 . V_142 = F_13 ( V_570 -> V_36 ) ;
F_3 ( V_73 , L_251 , V_139 . V_145 ) ;
} else {
memcpy ( V_139 . V_145 , V_569 -> V_146 , V_569 -> V_144 ) ;
V_139 . V_142 = F_13 ( ( T_4 ) V_569 -> V_144 ) ;
}
F_27 ( V_68 , 0 ) ;
F_20 ( V_68 , false ) ;
V_284 = F_8 ( ( T_2 * ) V_569 -> V_563 . V_564 ,
V_569 -> V_563 . V_565 , V_288 ) ;
V_285 = F_10 ( ( T_2 * ) V_569 -> V_563 . V_564 ,
V_569 -> V_563 . V_565 ) ;
if ( ( V_285 != NULL || V_284 != NULL ) ) {
F_3 ( V_73 , L_252 ) ;
if ( V_285 != NULL ) {
V_66 = F_150 ( V_65 , V_285 , false ) ;
if ( V_66 < 0 )
goto exit;
} else {
V_66 = F_150 ( V_65 ,
(struct V_45 * ) V_284 , true ) ;
if ( V_66 < 0 )
goto exit;
}
} else {
F_3 ( V_73 , L_253 ) ;
F_148 ( V_68 ) ;
}
F_155 ( V_68 -> V_2 , & V_569 -> V_563 ) ;
V_66 = F_156 ( V_97 , V_68 , V_569 -> V_220 . V_221 ) ;
if ( V_66 < 0 ) {
F_19 ( L_254 , V_66 ) ;
goto exit;
}
if ( V_569 -> V_224 ) {
V_66 = F_43 ( V_68 , V_228 ,
V_569 -> V_224 ) ;
if ( V_66 < 0 ) {
F_19 ( L_255 , V_66 ) ;
goto exit;
}
}
if ( V_569 -> V_340 ) {
V_66 = F_43 ( V_68 , V_580 ,
V_569 -> V_340 ) ;
if ( V_66 < 0 ) {
F_19 ( L_256 , V_66 ) ;
goto exit;
}
}
if ( V_571 == V_77 ) {
V_66 = F_43 ( V_68 , V_581 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_257 , V_66 ) ;
goto exit;
}
F_21 ( V_68 , L_258 , 0 ) ;
}
V_66 = F_43 ( V_68 , V_129 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_259 , V_66 ) ;
goto exit;
}
if ( V_571 == V_77 ) {
V_66 = F_43 ( V_68 , V_582 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_260 , V_66 ) ;
goto exit;
}
V_66 = F_43 ( V_68 , V_583 , 1 ) ;
if ( V_66 < 0 ) {
F_19 ( L_261 , V_66 ) ;
goto exit;
}
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
memcpy ( & V_215 . V_139 , & V_139 , sizeof( V_139 ) ) ;
V_66 = F_31 ( V_68 , V_236 ,
& V_215 , sizeof( V_215 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_262 , V_66 ) ;
goto exit;
}
F_3 ( V_73 , L_263 ) ;
} else {
V_66 = F_17 ( V_68 , L_264 , & V_139 ,
sizeof( V_139 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_265 , V_66 ) ;
goto exit;
}
V_573 . V_584 = F_13 ( V_68 -> V_427 ) ;
V_573 . V_69 = F_13 ( 1 ) ;
V_66 = F_50 ( V_68 , L_266 , & V_573 ,
sizeof( V_573 ) ) ;
if ( V_66 < 0 ) {
F_19 ( L_267 , V_66 ) ;
goto exit;
}
F_3 ( V_73 , L_268 ) ;
}
F_58 ( V_128 , & V_68 -> V_2 -> V_4 ) ;
F_42 ( V_585 , & V_68 -> V_2 -> V_4 ) ;
exit:
if ( V_66 ) {
F_27 ( V_68 , 1 ) ;
F_20 ( V_68 , true ) ;
}
return V_66 ;
}
static int F_159 ( struct V_81 * V_81 , struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
struct V_572 V_573 ;
struct V_214 V_215 ;
F_3 ( V_73 , L_13 ) ;
if ( V_68 -> V_2 -> V_76 . V_75 == V_77 ) {
F_128 ( 400 ) ;
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
V_66 = F_31 ( V_68 , V_236 ,
& V_215 , sizeof( V_215 ) ) ;
if ( V_66 < 0 )
F_19 ( L_262 , V_66 ) ;
V_66 = F_43 ( V_68 , V_583 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_269 , V_66 ) ;
V_66 = F_43 ( V_68 , V_582 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_260 , V_66 ) ;
V_66 = F_43 ( V_68 , V_129 , 0 ) ;
if ( V_66 < 0 )
F_19 ( L_270 , V_66 ) ;
} else {
V_573 . V_584 = F_13 ( V_68 -> V_427 ) ;
V_573 . V_69 = F_13 ( 0 ) ;
V_66 = F_50 ( V_68 , L_266 , & V_573 ,
sizeof( V_573 ) ) ;
if ( V_66 < 0 )
F_19 ( L_267 , V_66 ) ;
}
F_27 ( V_68 , 1 ) ;
F_20 ( V_68 , true ) ;
F_42 ( V_128 , & V_68 -> V_2 -> V_4 ) ;
F_58 ( V_585 , & V_68 -> V_2 -> V_4 ) ;
return V_66 ;
}
static T_5
F_160 ( struct V_81 * V_81 , struct V_64 * V_65 ,
struct V_562 * V_586 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
F_3 ( V_73 , L_13 ) ;
V_66 = F_155 ( V_68 -> V_2 , V_586 ) ;
return V_66 ;
}
static int
F_161 ( struct V_81 * V_81 , struct V_64 * V_65 ,
T_2 * V_331 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_299 V_300 ;
struct V_67 * V_68 = F_18 ( V_65 ) ;
T_5 V_66 ;
if ( ! V_331 )
return - V_587 ;
F_3 ( V_73 , L_271 , V_331 ) ;
if ( V_68 -> V_2 == V_97 -> V_183 . V_184 [ V_185 ] . V_2 )
V_68 = V_97 -> V_183 . V_184 [ V_186 ] . V_2 -> V_68 ;
if ( ! F_1 ( V_68 -> V_2 ) )
return - V_191 ;
memcpy ( & V_300 . V_63 , V_331 , V_107 ) ;
V_300 . V_241 = F_13 ( V_588 ) ;
V_66 = F_31 ( V_68 , V_589 ,
& V_300 , sizeof( V_300 ) ) ;
if ( V_66 )
F_19 ( L_272 , V_66 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static void
F_162 ( struct V_81 * V_81 ,
struct V_80 * V_76 ,
T_1 V_590 , bool V_591 )
{
struct V_1 * V_2 ;
T_1 V_592 ;
F_3 ( V_73 , L_273 , V_590 , V_591 ) ;
V_592 = ( V_590 & V_593 ) >> 4 ;
V_2 = F_60 ( V_76 , struct V_1 , V_76 ) ;
if ( V_591 )
V_2 -> V_594 |= F_120 ( V_592 ) ;
else
V_2 -> V_594 &= ~ F_120 ( V_592 ) ;
}
static int
F_163 ( struct V_81 * V_81 , struct V_80 * V_76 ,
struct V_595 * V_84 , T_10 * V_330 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_19 * V_221 = V_84 -> V_221 ;
const T_2 * V_30 = V_84 -> V_30 ;
T_6 V_36 = V_84 -> V_36 ;
const struct V_596 * V_597 ;
struct V_1 * V_2 ;
T_5 V_66 = 0 ;
T_5 V_391 ;
T_5 V_223 ;
struct V_598 * V_599 ;
struct V_600 * V_601 ;
bool V_602 ;
T_5 V_603 ;
T_4 V_376 ;
F_3 ( V_73 , L_13 ) ;
* V_330 = 0 ;
V_597 = ( const struct V_596 * ) V_30 ;
if ( ! F_164 ( V_597 -> V_604 ) ) {
F_19 ( L_274 ) ;
return - V_360 ;
}
V_2 = F_60 ( V_76 , struct V_1 , V_76 ) ;
if ( F_165 ( V_597 -> V_604 ) ) {
V_391 = V_575 +
V_576 ;
V_223 = V_36 - V_391 ;
if ( V_2 == V_97 -> V_183 . V_184 [ V_186 ] . V_2 )
V_2 = V_97 -> V_183 . V_184 [ V_185 ] . V_2 ;
V_66 = F_83 ( V_2 ,
V_553 ,
& V_30 [ V_391 ] ,
V_223 ) ;
F_166 ( V_76 , * V_330 , V_30 , V_36 , true ,
V_154 ) ;
} else if ( F_167 ( V_597 -> V_604 ) ) {
V_601 = F_48 ( sizeof( * V_601 ) , V_154 ) ;
if ( V_601 == NULL ) {
F_19 ( L_275 ) ;
V_66 = - V_155 ;
goto exit;
}
V_599 = & V_601 -> V_599 ;
V_599 -> V_605 = F_13 ( * V_330 ) ;
memcpy ( & V_599 -> V_606 [ 0 ] , & V_597 -> V_606 [ 0 ] , V_107 ) ;
memcpy ( & V_601 -> V_106 [ 0 ] , & V_597 -> V_106 [ 0 ] , V_107 ) ;
V_599 -> V_36 = F_14 ( V_36 - V_575 ) ;
if ( V_221 )
V_376 = V_221 -> V_24 ;
else
F_100 ( V_2 -> V_68 , V_607 ,
& V_376 ) ;
V_603 = F_7 ( V_376 ) ;
V_601 -> V_231 = F_13 ( V_603 ) ;
memcpy ( V_599 -> V_62 , & V_30 [ V_575 ] ,
F_104 ( V_599 -> V_36 ) ) ;
F_3 ( V_73 , L_276 ,
* V_330 , F_104 ( V_599 -> V_36 ) , V_376 ) ;
V_602 = F_168 ( V_97 , F_65 ( V_97 ) ,
V_601 ) ;
F_166 ( V_76 , * V_330 , V_30 , V_36 , V_602 ,
V_154 ) ;
F_51 ( V_601 ) ;
} else {
F_3 ( V_73 , L_277 , V_597 -> V_604 ) ;
F_169 ( true , V_30 , V_36 , L_278 , V_36 ) ;
}
exit:
return V_66 ;
}
static int
F_170 ( struct V_81 * V_81 ,
struct V_80 * V_76 ,
T_10 V_330 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_1 * V_2 ;
int V_66 = 0 ;
F_3 ( V_73 , L_279 ) ;
V_2 = V_97 -> V_183 . V_184 [ V_185 ] . V_2 ;
if ( V_2 == NULL ) {
F_19 ( L_280 ) ;
V_66 = - V_368 ;
goto exit;
}
F_171 ( V_2 -> V_68 ) ;
exit:
return V_66 ;
}
static int F_172 ( struct V_81 * V_81 ,
struct V_80 * V_76 ,
enum V_608 V_609 ,
T_1 V_610 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_1 * V_2 ;
V_2 = F_60 ( V_76 , struct V_1 , V_76 ) ;
if ( V_609 != V_611 )
return - V_94 ;
F_42 ( V_181 , & V_97 -> V_120 ) ;
F_113 ( V_97 ) ;
return F_69 ( V_2 , V_612 , V_610 ) ;
}
static void F_173 ( struct V_81 * V_81 ,
struct V_80 * V_76 )
{
struct V_96 * V_97 = F_54 ( V_81 ) ;
struct V_1 * V_2 ;
V_2 = F_60 ( V_76 , struct V_1 , V_76 ) ;
F_69 ( V_2 , V_211 , 0 ) ;
F_58 ( V_181 , & V_97 -> V_120 ) ;
}
static int F_174 ( enum V_613 V_614 )
{
int V_467 ;
switch ( V_614 ) {
case V_615 :
V_467 = V_616 ;
break;
case V_617 :
V_467 = V_618 ;
break;
case V_619 :
V_467 = V_620 ;
break;
default:
F_19 ( L_281 , V_614 ) ;
V_467 = - V_90 ;
}
return V_467 ;
}
static int F_175 ( struct V_81 * V_81 ,
struct V_64 * V_65 , T_2 * V_621 ,
enum V_613 V_614 )
{
struct V_67 * V_68 ;
struct V_622 V_586 ;
int V_467 = 0 ;
V_467 = F_174 ( V_614 ) ;
if ( V_467 < 0 )
return V_467 ;
V_68 = F_18 ( V_65 ) ;
memset ( & V_586 , 0 , sizeof( V_586 ) ) ;
V_586 . V_70 = ( T_2 ) V_467 ;
if ( V_621 )
memcpy ( V_586 . V_63 , V_621 , V_107 ) ;
V_467 = F_50 ( V_68 , L_282 ,
& V_586 , sizeof( V_586 ) ) ;
if ( V_467 < 0 )
F_19 ( L_283 , V_467 ) ;
return V_467 ;
}
static void F_176 ( struct V_81 * V_81 )
{
V_81 -> V_623 = V_624 ;
V_81 -> V_625 = V_624 ;
V_81 -> V_626 = V_627 ;
V_81 -> V_57 |= V_628 ;
}
static struct V_81 * F_177 ( struct V_629 * V_630 )
{
struct V_81 * V_81 ;
T_5 V_66 = 0 ;
V_81 = F_178 ( & V_631 , sizeof( struct V_96 ) ) ;
if ( ! V_81 ) {
F_19 ( L_284 ) ;
return F_25 ( - V_155 ) ;
}
F_179 ( V_81 , V_630 ) ;
V_81 -> V_632 = V_633 ;
V_81 -> V_634 = V_627 ;
V_81 -> V_635 = V_452 ;
V_81 -> V_430 = F_120 ( V_85 ) |
F_120 ( V_79 ) |
F_120 ( V_77 ) |
F_120 ( V_91 ) |
F_120 ( V_78 ) |
F_120 ( V_92 ) ;
V_81 -> V_636 = V_637 ;
V_81 -> V_638 = F_154 ( V_637 ) ;
V_81 -> V_387 [ V_388 ] = & V_639 ;
V_81 -> V_640 = V_641 ;
V_81 -> V_642 = V_643 ;
V_81 -> V_644 = F_154 ( V_643 ) ;
V_81 -> V_57 |= V_645 |
V_646 |
V_647 |
V_648 ;
V_81 -> V_649 = V_650 ;
V_81 -> V_651 = 5000 ;
F_176 ( V_81 ) ;
F_3 ( V_5 , L_285 ) ;
V_81 -> V_652 |= V_653 ;
F_180 ( V_81 , & V_654 ) ;
V_66 = F_181 ( V_81 ) ;
if ( V_66 < 0 ) {
F_19 ( L_286 , V_66 ) ;
F_182 ( V_81 ) ;
return F_25 ( V_66 ) ;
}
return V_81 ;
}
struct V_1 * F_183 ( struct V_96 * V_97 ,
enum V_74 type ,
bool V_655 )
{
struct V_1 * V_2 ;
F_3 ( V_73 , L_287 ,
sizeof( * V_2 ) ) ;
V_2 = F_48 ( sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 )
return F_25 ( - V_155 ) ;
V_2 -> V_76 . V_81 = V_97 -> V_81 ;
V_2 -> V_76 . V_75 = type ;
V_2 -> V_655 = V_655 ;
V_2 -> V_656 = - 1 ;
F_66 ( & V_2 -> V_213 ) ;
F_184 ( & V_2 -> V_396 , & V_97 -> V_657 ) ;
return V_2 ;
}
void F_185 ( struct V_1 * V_2 )
{
F_186 ( & V_2 -> V_396 ) ;
F_51 ( V_2 ) ;
}
void F_187 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_67 * V_68 ;
V_68 = F_18 ( V_65 ) ;
V_2 = V_68 -> V_2 ;
F_185 ( V_2 ) ;
F_188 ( V_65 ) ;
}
static bool F_189 ( const struct V_419 * V_420 )
{
T_4 V_658 = V_420 -> V_460 ;
T_4 V_423 = V_420 -> V_423 ;
if ( V_658 == V_659 && V_423 == V_433 ) {
F_3 ( V_219 , L_288 ) ;
return true ;
}
return false ;
}
static bool F_190 ( const struct V_419 * V_420 )
{
T_4 V_658 = V_420 -> V_460 ;
T_1 V_57 = V_420 -> V_57 ;
if ( ( V_658 == V_660 ) || ( V_658 == V_661 ) ||
( V_658 == V_662 ) ||
( ( V_658 == V_663 ) && ( ! ( V_57 & V_664 ) ) ) ) {
F_3 ( V_219 , L_289 ) ;
return true ;
}
return false ;
}
static bool F_191 ( struct V_96 * V_97 ,
const struct V_419 * V_420 )
{
T_4 V_658 = V_420 -> V_460 ;
T_4 V_423 = V_420 -> V_423 ;
if ( V_658 == V_663 && V_423 == V_665 ) {
F_3 ( V_219 , L_290 ,
V_420 -> V_57 & V_664 ? L_291 : L_292 ) ;
return true ;
}
if ( V_658 == V_659 && V_423 != V_433 ) {
F_3 ( V_219 , L_293 ) ;
return true ;
}
return false ;
}
static void F_192 ( struct V_96 * V_97 )
{
struct V_666 * V_667 = F_193 ( V_97 ) ;
F_51 ( V_667 -> V_668 ) ;
V_667 -> V_668 = NULL ;
V_667 -> V_669 = 0 ;
F_51 ( V_667 -> V_670 ) ;
V_667 -> V_670 = NULL ;
V_667 -> V_671 = 0 ;
}
static T_5 F_194 ( struct V_96 * V_97 ,
struct V_67 * V_68 )
{
struct V_672 * V_673 ;
struct V_666 * V_667 = F_193 ( V_97 ) ;
T_4 V_674 ;
T_4 V_675 ;
T_5 V_66 = 0 ;
F_192 ( V_97 ) ;
V_66 = F_98 ( V_68 , L_294 ,
V_97 -> V_405 , V_676 ) ;
if ( V_66 ) {
F_19 ( L_295 , V_66 ) ;
return V_66 ;
}
V_673 =
(struct V_672 * ) V_97 -> V_405 ;
V_674 = F_99 ( V_673 -> V_674 ) ;
V_675 = F_99 ( V_673 -> V_675 ) ;
if ( V_674 ) {
V_66 = F_98 ( V_68 , L_296 ,
V_97 -> V_405 ,
V_676 ) ;
if ( V_66 ) {
F_19 ( L_297 , V_66 ) ;
return V_66 ;
}
V_667 -> V_669 = V_674 ;
V_667 -> V_668 =
F_195 ( V_97 -> V_405 , V_667 -> V_669 ,
V_154 ) ;
} else {
V_667 -> V_669 = 0 ;
V_667 -> V_668 = NULL ;
}
if ( V_675 ) {
V_66 = F_98 ( V_68 , L_298 ,
V_97 -> V_405 ,
V_676 ) ;
if ( V_66 ) {
F_19 ( L_299 , V_66 ) ;
return V_66 ;
}
V_667 -> V_671 = V_675 ;
V_667 -> V_670 =
F_195 ( V_97 -> V_405 , V_667 -> V_671 ,
V_154 ) ;
} else {
V_667 -> V_671 = 0 ;
V_667 -> V_670 = NULL ;
}
F_3 ( V_219 , L_300 ,
V_667 -> V_669 , V_667 -> V_671 ) ;
return V_66 ;
}
static T_5
F_196 ( struct V_96 * V_97 ,
struct V_64 * V_65 ,
const struct V_419 * V_420 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_666 * V_667 = F_193 ( V_97 ) ;
struct V_81 * V_81 = F_33 ( V_97 ) ;
struct V_19 * V_371 = NULL ;
struct V_374 * V_375 ;
struct V_369 * V_370 ;
struct V_21 V_20 ;
T_4 V_376 ;
T_5 V_66 = 0 ;
T_2 * V_30 ;
F_3 ( V_73 , L_13 ) ;
F_194 ( V_97 , V_68 ) ;
memcpy ( V_213 -> V_106 , V_420 -> V_677 , V_107 ) ;
F_112 ( V_97 , V_68 ) ;
V_30 = F_48 ( V_383 , V_154 ) ;
if ( V_30 == NULL ) {
V_66 = - V_155 ;
goto V_126;
}
* ( V_401 * ) V_30 = F_13 ( V_383 ) ;
V_66 = F_101 ( V_68 , V_402 ,
V_30 , V_383 ) ;
if ( V_66 )
goto V_126;
V_370 = (struct V_369 * ) ( V_30 + 4 ) ;
V_20 . V_28 = F_104 ( V_370 -> V_136 ) ;
V_97 -> V_18 . V_385 ( & V_20 ) ;
if ( V_20 . V_375 == V_403 )
V_375 = V_81 -> V_387 [ V_388 ] ;
else
V_375 = V_81 -> V_387 [ V_389 ] ;
V_376 = F_105 ( V_20 . V_23 , V_375 -> V_375 ) ;
V_371 = F_106 ( V_81 , V_376 ) ;
V_126:
F_51 ( V_30 ) ;
F_197 ( V_65 , V_371 , ( T_2 * ) V_213 -> V_106 ,
V_667 -> V_668 , V_667 -> V_669 ,
V_667 -> V_670 , V_667 -> V_671 , V_154 ) ;
F_3 ( V_219 , L_301 ) ;
F_42 ( V_209 , & V_68 -> V_2 -> V_4 ) ;
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_198 ( struct V_96 * V_97 ,
struct V_64 * V_65 , const struct V_419 * V_420 ,
bool V_678 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_666 * V_667 = F_193 ( V_97 ) ;
T_5 V_66 = 0 ;
F_3 ( V_73 , L_13 ) ;
if ( F_35 ( V_182 ,
& V_68 -> V_2 -> V_4 ) ) {
if ( V_678 ) {
F_194 ( V_97 , V_68 ) ;
memcpy ( V_213 -> V_106 , V_420 -> V_677 , V_107 ) ;
F_112 ( V_97 , V_68 ) ;
F_42 ( V_209 ,
& V_68 -> V_2 -> V_4 ) ;
}
F_199 ( V_65 ,
( T_2 * ) V_213 -> V_106 ,
V_667 -> V_668 ,
V_667 -> V_669 ,
V_667 -> V_670 ,
V_667 -> V_671 ,
V_678 ? V_679 :
V_680 ,
V_154 ) ;
F_3 ( V_219 , L_302 ,
V_678 ? L_303 : L_210 ) ;
}
F_3 ( V_73 , L_30 ) ;
return V_66 ;
}
static T_5
F_200 ( struct V_96 * V_97 ,
struct V_64 * V_65 ,
const struct V_419 * V_420 , void * V_62 )
{
static int V_681 ;
T_4 V_658 = V_420 -> V_460 ;
T_4 V_682 = V_420 -> V_682 ;
struct V_332 V_333 ;
F_3 ( V_219 , L_304 , V_658 , V_682 ) ;
if ( V_658 == V_663 && V_682 == V_683 &&
V_65 != F_65 ( V_97 ) ) {
F_3 ( V_219 , L_305 ) ;
F_201 ( & V_97 -> V_684 ) ;
return 0 ;
}
if ( ( ( V_658 == V_685 ) || ( V_658 == V_686 ) ) &&
( V_682 == V_433 ) ) {
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
V_333 . V_341 = V_687 ;
if ( ! V_62 ) {
F_19 ( L_306 ) ;
return - V_94 ;
}
V_333 . V_688 = V_62 ;
V_333 . V_689 = V_420 -> V_690 ;
V_681 ++ ;
V_333 . V_681 = V_681 ;
F_202 ( V_65 , V_420 -> V_677 , & V_333 , V_154 ) ;
} else if ( ( V_658 == V_662 ) ||
( V_658 == V_661 ) ||
( V_658 == V_660 ) ) {
F_203 ( V_65 , V_420 -> V_677 , V_154 ) ;
}
return 0 ;
}
static T_5
F_204 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
struct V_64 * V_65 = V_68 -> V_65 ;
struct V_207 * V_213 = & V_68 -> V_2 -> V_213 ;
struct V_19 * V_221 ;
T_5 V_66 = 0 ;
T_1 V_682 ;
if ( F_22 ( V_68 -> V_2 ) ) {
V_66 = F_200 ( V_97 , V_65 , V_420 , V_62 ) ;
} else if ( F_189 ( V_420 ) ) {
F_3 ( V_219 , L_307 ) ;
if ( F_23 ( V_68 -> V_2 ) ) {
V_221 = F_106 ( V_97 -> V_81 , V_97 -> V_231 ) ;
memcpy ( V_213 -> V_106 , V_420 -> V_677 , V_107 ) ;
F_111 ( V_97 , V_65 , V_420 -> V_677 ) ;
F_205 ( V_65 , V_420 -> V_677 , V_221 , V_154 ) ;
F_58 ( V_182 ,
& V_68 -> V_2 -> V_4 ) ;
F_42 ( V_209 ,
& V_68 -> V_2 -> V_4 ) ;
} else
F_198 ( V_97 , V_65 , V_420 , true ) ;
} else if ( F_190 ( V_420 ) ) {
F_3 ( V_219 , L_308 ) ;
if ( ! F_23 ( V_68 -> V_2 ) ) {
F_198 ( V_97 , V_65 , V_420 , false ) ;
if ( F_35 ( V_209 ,
& V_68 -> V_2 -> V_4 ) ) {
V_682 = 0 ;
if ( ( ( V_420 -> V_460 == V_661 ) ||
( V_420 -> V_460 == V_662 ) ) &&
( V_420 -> V_682 != V_691 ) )
V_682 = V_420 -> V_682 ;
F_68 ( V_65 , V_682 , NULL , 0 ,
V_154 ) ;
}
}
F_67 ( V_68 -> V_2 ) ;
F_66 ( F_73 ( V_65 ) ) ;
if ( V_65 != F_65 ( V_97 ) )
F_201 ( & V_97 -> V_684 ) ;
} else if ( F_191 ( V_97 , V_420 ) ) {
if ( F_23 ( V_68 -> V_2 ) )
F_58 ( V_182 ,
& V_68 -> V_2 -> V_4 ) ;
else
F_198 ( V_97 , V_65 , V_420 , false ) ;
}
return V_66 ;
}
static T_5
F_206 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
T_5 V_66 = 0 ;
T_4 V_658 = V_420 -> V_460 ;
T_4 V_423 = V_420 -> V_423 ;
if ( V_658 == V_692 && V_423 == V_433 ) {
if ( F_2 ( V_209 , & V_68 -> V_2 -> V_4 ) )
F_196 ( V_97 , V_68 -> V_65 , V_420 ) ;
else
F_198 ( V_97 , V_68 -> V_65 , V_420 , true ) ;
}
return V_66 ;
}
static T_5
F_207 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
T_1 V_57 = V_420 -> V_57 ;
enum V_693 V_694 ;
if ( V_57 & V_695 )
V_694 = V_696 ;
else
V_694 = V_697 ;
F_208 ( V_68 -> V_65 , ( T_2 * ) & V_420 -> V_677 , V_694 , - 1 ,
NULL , V_154 ) ;
return 0 ;
}
static T_5 F_209 ( struct V_67 * V_68 ,
const struct V_419 * V_420 , void * V_62 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
struct V_698 * V_699 = (struct V_698 * ) V_62 ;
struct V_700 * V_658 = & V_97 -> V_701 ;
struct V_1 * V_2 ;
F_3 ( V_73 , L_309 ,
V_699 -> V_149 , V_699 -> V_57 , V_699 -> V_702 ,
V_699 -> V_427 ) ;
F_210 ( & V_658 -> V_703 ) ;
V_658 -> V_149 = V_699 -> V_149 ;
V_2 = V_658 -> V_2 ;
switch ( V_699 -> V_149 ) {
case V_704 :
if ( ! V_97 -> V_701 . V_2 ) {
F_211 ( & V_658 -> V_703 ) ;
return - V_705 ;
}
V_68 -> V_2 = V_2 ;
V_2 -> V_68 = V_68 ;
if ( V_68 -> V_65 ) {
V_2 -> V_76 . V_121 = V_68 -> V_65 ;
V_68 -> V_65 -> V_131 = & V_2 -> V_76 ;
F_212 ( V_68 -> V_65 , F_213 ( V_97 -> V_81 ) ) ;
}
F_211 ( & V_658 -> V_703 ) ;
F_214 ( & V_658 -> V_706 ) ;
return 0 ;
case V_707 :
F_211 ( & V_658 -> V_703 ) ;
if ( F_38 ( V_97 ) )
F_214 ( & V_658 -> V_706 ) ;
return 0 ;
case V_708 :
F_211 ( & V_658 -> V_703 ) ;
F_214 ( & V_658 -> V_706 ) ;
return 0 ;
default:
F_211 ( & V_658 -> V_703 ) ;
break;
}
return - V_94 ;
}
static void F_215 ( struct V_709 * V_201 )
{
V_201 -> V_193 = ( T_4 ) - 1 ;
V_201 -> V_192 = ( T_4 ) - 1 ;
V_201 -> V_206 = ( T_4 ) - 1 ;
V_201 -> V_204 = ( T_4 ) - 1 ;
V_201 -> V_311 = - 1 ;
}
static void F_216 ( struct V_96 * V_97 )
{
F_122 ( V_97 -> V_434 , V_663 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_661 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_660 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_662 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_685 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_686 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_692 ,
F_206 ) ;
F_122 ( V_97 -> V_434 , V_710 ,
F_207 ) ;
F_122 ( V_97 -> V_434 , V_659 ,
F_204 ) ;
F_122 ( V_97 -> V_434 , V_711 ,
F_136 ) ;
F_122 ( V_97 -> V_434 , V_712 ,
F_209 ) ;
F_122 ( V_97 -> V_434 , V_713 ,
V_714 ) ;
F_122 ( V_97 -> V_434 , V_715 ,
V_716 ) ;
F_122 ( V_97 -> V_434 , V_717 ,
V_718 ) ;
F_122 ( V_97 -> V_434 , V_719 ,
V_720 ) ;
F_122 ( V_97 -> V_434 , V_721 ,
V_720 ) ;
}
static void F_217 ( struct V_96 * V_97 )
{
F_51 ( V_97 -> V_201 ) ;
V_97 -> V_201 = NULL ;
F_51 ( V_97 -> V_722 ) ;
V_97 -> V_722 = NULL ;
F_51 ( V_97 -> V_405 ) ;
V_97 -> V_405 = NULL ;
F_51 ( V_97 -> V_441 ) ;
V_97 -> V_441 = NULL ;
}
static T_5 F_218 ( struct V_96 * V_97 )
{
V_97 -> V_201 = F_48 ( sizeof( * V_97 -> V_201 ) , V_154 ) ;
if ( ! V_97 -> V_201 )
goto V_723;
V_97 -> V_722 = F_48 ( V_156 , V_154 ) ;
if ( ! V_97 -> V_722 )
goto V_723;
V_97 -> V_405 = F_48 ( V_406 , V_154 ) ;
if ( ! V_97 -> V_405 )
goto V_723;
V_97 -> V_441 = F_48 ( sizeof( * V_97 -> V_441 ) , V_154 ) ;
if ( ! V_97 -> V_441 )
goto V_723;
return 0 ;
V_723:
F_217 ( V_97 ) ;
return - V_155 ;
}
static T_5 F_219 ( struct V_96 * V_97 )
{
T_5 V_66 = 0 ;
V_97 -> V_103 = NULL ;
V_97 -> V_364 = true ;
V_97 -> V_166 = true ;
V_97 -> V_724 = false ;
V_66 = F_218 ( V_97 ) ;
if ( V_66 )
return V_66 ;
F_216 ( V_97 ) ;
F_220 ( & V_97 -> V_725 ) ;
F_121 ( V_97 ) ;
F_215 ( V_97 -> V_201 ) ;
F_221 ( & V_97 -> V_684 ) ;
return V_66 ;
}
static void F_222 ( struct V_96 * V_97 )
{
V_97 -> V_724 = false ;
F_113 ( V_97 ) ;
F_217 ( V_97 ) ;
}
static void F_223 ( struct V_700 * V_658 )
{
F_224 ( & V_658 -> V_706 ) ;
F_220 ( & V_658 -> V_703 ) ;
}
static int F_225 ( struct V_67 * V_68 )
{
struct V_726 V_727 ;
T_4 V_241 ;
int V_66 ;
V_241 = V_728 ;
V_66 = F_88 ( V_68 , L_310 , & V_241 ) ;
if ( ! V_66 ) {
V_727 . V_375 = F_13 ( V_729 ) ;
V_727 . V_730 = F_13 ( V_731 ) ;
V_66 = F_50 ( V_68 , L_310 , & V_727 ,
sizeof( V_727 ) ) ;
} else {
F_3 ( V_5 , L_311 ) ;
V_241 = V_732 ;
V_66 = F_21 ( V_68 , L_312 , V_241 ) ;
}
return V_66 ;
}
struct V_96 * F_226 ( struct V_733 * V_421 ,
struct V_629 * V_734 )
{
struct V_64 * V_65 = V_421 -> V_735 [ 0 ] -> V_65 ;
struct V_96 * V_97 ;
struct V_81 * V_81 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
T_5 V_66 = 0 ;
T_5 V_736 ;
if ( ! V_65 ) {
F_19 ( L_313 ) ;
return NULL ;
}
V_68 = F_18 ( V_65 ) ;
V_81 = F_177 ( V_734 ) ;
if ( F_227 ( V_81 ) )
return NULL ;
V_97 = F_37 ( V_81 ) ;
V_97 -> V_81 = V_81 ;
V_97 -> V_434 = V_421 ;
F_223 ( & V_97 -> V_701 ) ;
F_228 ( & V_97 -> V_657 ) ;
V_2 = F_183 ( V_97 , V_85 , false ) ;
if ( F_227 ( V_2 ) ) {
F_182 ( V_81 ) ;
return NULL ;
}
V_2 -> V_68 = V_68 ;
V_2 -> V_76 . V_121 = V_65 ;
V_65 -> V_131 = & V_2 -> V_76 ;
F_212 ( V_65 , F_213 ( V_97 -> V_81 ) ) ;
V_66 = F_219 ( V_97 ) ;
if ( V_66 ) {
F_19 ( L_314 , V_66 ) ;
goto V_737;
}
V_68 -> V_2 = V_2 ;
V_66 = F_229 ( V_97 ) ;
if ( V_66 ) {
F_19 ( L_315 , V_66 ) ;
goto V_738;
}
V_66 = F_230 ( V_97 ) ;
if ( V_66 ) {
F_19 ( L_316 , V_66 ) ;
F_231 ( & V_97 -> V_183 ) ;
goto V_738;
}
if ( V_81 -> V_387 [ V_388 ] -> V_739 . V_740 &
V_741 ) {
V_66 = F_225 ( V_68 ) ;
if ( ! V_66 )
V_66 = F_21 ( V_68 , L_317 ,
V_742 ) ;
}
V_66 = F_21 ( V_68 , L_318 , 1 ) ;
if ( V_66 ) {
F_3 ( V_5 , L_319 , V_66 ) ;
V_81 -> V_57 &= ~ V_648 ;
}
V_66 = F_100 ( V_68 , V_743 ,
& V_736 ) ;
if ( V_66 ) {
F_19 ( L_320 , V_66 ) ;
goto V_738;
}
V_97 -> V_18 . V_736 = ( T_2 ) V_736 ;
F_232 ( & V_97 -> V_18 ) ;
return V_97 ;
V_738:
F_222 ( V_97 ) ;
V_737:
F_185 ( V_2 ) ;
return NULL ;
}
void F_233 ( struct V_96 * V_97 )
{
if ( ! V_97 )
return;
F_137 ( ! F_234 ( & V_97 -> V_657 ) ) ;
F_235 ( V_97 -> V_81 ) ;
F_236 ( V_97 ) ;
F_222 ( V_97 ) ;
F_182 ( V_97 -> V_81 ) ;
}
static T_5
F_237 ( struct V_67 * V_68 , T_4 V_744 )
{
T_5 V_66 = 0 ;
V_401 V_745 [ 2 ] ;
V_401 V_746 [ 2 ] ;
if ( V_747 ) {
V_66 = F_21 ( V_68 , L_321 , V_744 ) ;
if ( V_66 ) {
F_19 ( L_322 , V_66 ) ;
goto V_748;
}
}
F_3 ( V_5 , L_323 ,
V_747 ? L_324 : L_325 ) ;
V_66 = F_21 ( V_68 , L_326 , ! ! ( V_747 ) ) ;
if ( V_66 ) {
F_19 ( L_327 , V_66 ) ;
goto V_748;
}
V_745 [ 0 ] = F_13 ( V_749 ) ;
V_745 [ 1 ] = F_13 ( V_750 ) ;
V_66 = F_31 ( V_68 , V_751 ,
( void * ) V_745 , sizeof( V_745 ) ) ;
if ( V_66 ) {
F_19 ( L_328 , V_66 ) ;
goto V_748;
}
V_746 [ 0 ] = F_13 ( V_752 ) ;
V_746 [ 1 ] = F_13 ( V_750 ) ;
V_66 = F_31 ( V_68 , V_753 ,
( void * ) V_746 , sizeof( V_746 ) ) ;
if ( V_66 ) {
F_19 ( L_329 , V_66 ) ;
goto V_748;
}
V_748:
return V_66 ;
}
static T_5
F_238 ( struct V_67 * V_68 , T_5 V_754 ,
T_5 V_755 , T_5 V_756 )
{
T_5 V_66 = 0 ;
V_66 = F_43 ( V_68 , V_757 ,
V_754 ) ;
if ( V_66 ) {
if ( V_66 == - V_90 )
F_3 ( V_5 , L_330 ) ;
else
F_19 ( L_331 , V_66 ) ;
goto V_758;
}
V_66 = F_43 ( V_68 , V_759 ,
V_755 ) ;
if ( V_66 ) {
if ( V_66 == - V_90 )
F_3 ( V_5 , L_332 ) ;
else
F_19 ( L_333 , V_66 ) ;
goto V_758;
}
V_66 = F_43 ( V_68 , V_760 ,
V_756 ) ;
if ( V_66 ) {
if ( V_66 == - V_90 )
F_3 ( V_5 , L_334 ) ;
else
F_19 ( L_335 , V_66 ) ;
goto V_758;
}
V_758:
return V_66 ;
}
static T_5 F_239 ( struct V_96 * V_97 ,
T_4 V_730 [] )
{
struct V_67 * V_68 = F_18 ( F_65 ( V_97 ) ) ;
struct V_19 * V_761 ;
struct V_762 * V_396 ;
struct V_21 V_20 ;
T_5 V_66 ;
T_2 * V_763 ;
T_4 V_135 , V_442 ;
T_4 V_764 ;
enum V_765 V_375 ;
T_4 V_231 ;
T_4 * V_766 ;
T_4 V_55 ;
T_4 V_767 ;
bool V_768 ;
T_4 V_769 ;
V_763 = F_48 ( V_156 , V_154 ) ;
if ( V_763 == NULL )
return - V_155 ;
V_396 = (struct V_762 * ) V_763 ;
V_66 = F_98 ( V_68 , L_336 , V_763 ,
V_156 ) ;
if ( V_66 ) {
F_19 ( L_337 , V_66 ) ;
goto exit;
}
V_639 . V_134 = 0 ;
V_770 . V_134 = 0 ;
V_764 = F_99 ( V_396 -> V_169 ) ;
for ( V_135 = 0 ; V_135 < V_764 ; V_135 ++ ) {
V_20 . V_28 = ( T_1 ) F_99 ( V_396 -> V_771 [ V_135 ] ) ;
V_97 -> V_18 . V_385 ( & V_20 ) ;
if ( V_20 . V_375 == V_403 ) {
V_761 = V_772 ;
V_769 = F_154 ( V_772 ) ;
V_766 = & V_639 . V_134 ;
V_375 = V_388 ;
} else if ( V_20 . V_375 == V_773 ) {
V_761 = V_774 ;
V_769 = F_154 ( V_774 ) ;
V_766 = & V_770 . V_134 ;
V_375 = V_389 ;
} else {
F_19 ( L_338 , V_20 . V_28 ) ;
continue;
}
if ( ! ( V_730 [ V_375 ] & V_775 ) &&
V_20 . V_25 == V_776 )
continue;
V_768 = false ;
for ( V_442 = 0 ; ( V_442 < * V_766 && ( * V_766 < V_769 ) ) ; V_442 ++ ) {
if ( V_761 [ V_442 ] . V_141 == V_20 . V_23 ) {
V_768 = true ;
break;
}
}
if ( V_768 )
V_55 = V_442 ;
else
V_55 = * V_766 ;
if ( V_55 < V_769 ) {
V_761 [ V_55 ] . V_24 =
F_105 ( V_20 . V_23 , V_375 ) ;
V_761 [ V_55 ] . V_141 = V_20 . V_23 ;
if ( V_20 . V_25 == V_776 ) {
V_767 = V_761 [ V_55 ] . V_57 &
V_466 ;
if ( V_20 . V_777 == V_778 ) {
if ( V_767 == V_466 )
V_761 [ V_55 ] . V_57 &=
~ V_466 ;
V_761 [ V_55 ] . V_57 |=
V_779 ;
} else {
V_761 [ V_55 ] . V_57 &=
~ V_466 ;
if ( V_767 == V_466 )
V_761 [ V_55 ] . V_57 |=
V_780 ;
}
} else {
V_761 [ V_55 ] . V_57 =
V_466 ;
V_20 . V_25 = V_26 ;
V_97 -> V_18 . V_27 ( & V_20 ) ;
V_231 = V_20 . V_28 ;
V_66 = F_78 ( V_68 ,
L_339 ,
& V_231 ) ;
if ( ! V_66 ) {
if ( V_231 & V_781 )
V_761 [ V_55 ] . V_57 |=
( V_782 |
V_783 ) ;
if ( V_231 & V_784 )
V_761 [ V_55 ] . V_57 |=
V_783 ;
}
}
if ( ! V_768 )
( * V_766 ) ++ ;
}
}
exit:
F_51 ( V_763 ) ;
return V_66 ;
}
static void F_240 ( struct V_67 * V_68 , T_4 V_730 [] )
{
T_4 V_375 , V_785 ;
int V_66 ;
V_375 = V_729 ;
V_66 = F_88 ( V_68 , L_310 , & V_375 ) ;
if ( ! V_66 ) {
V_730 [ V_388 ] = V_375 ;
V_375 = V_728 ;
V_66 = F_88 ( V_68 , L_310 , & V_375 ) ;
if ( ! V_66 ) {
V_730 [ V_389 ] = V_375 ;
return;
}
F_137 ( 1 ) ;
return;
}
F_3 ( V_5 , L_340 ) ;
V_785 = 0 ;
V_66 = F_88 ( V_68 , L_312 , & V_785 ) ;
if ( V_66 )
V_785 = V_786 ;
switch ( V_785 ) {
case V_732 :
V_730 [ V_388 ] |= V_775 ;
case V_787 :
V_730 [ V_389 ] |= V_775 ;
case V_786 :
V_730 [ V_388 ] |= V_788 ;
V_730 [ V_389 ] |= V_788 ;
break;
default:
F_19 ( L_341 ) ;
}
}
static T_5 F_241 ( struct V_96 * V_97 )
{
struct V_67 * V_68 = F_18 ( F_65 ( V_97 ) ) ;
struct V_81 * V_81 ;
T_5 V_789 ;
T_4 V_790 [ 3 ] ;
T_4 V_791 ;
T_4 V_730 [ 2 ] = { 0 , 0 } ;
T_4 V_792 ;
T_4 V_793 ;
T_9 V_794 ;
T_5 V_66 ;
T_4 V_795 ;
T_5 V_135 ;
struct V_374 * V_387 [ 2 ] = { NULL , NULL } ;
struct V_374 * V_375 ;
V_66 = F_101 ( V_68 , V_796 ,
& V_789 , sizeof( V_789 ) ) ;
if ( V_66 ) {
F_19 ( L_342 , V_66 ) ;
return V_66 ;
}
V_794 = ( ( char * ) & V_789 ) [ 0 ] ;
F_3 ( V_5 , L_343 , V_794 ) ;
V_66 = F_101 ( V_68 , V_797 ,
& V_790 , sizeof( V_790 ) ) ;
if ( V_66 ) {
F_19 ( L_344 , V_66 ) ;
return V_66 ;
}
F_3 ( V_5 , L_345 ,
V_790 [ 0 ] , V_790 [ 1 ] , V_790 [ 2 ] ) ;
V_66 = F_88 ( V_68 , L_346 , & V_791 ) ;
if ( V_66 ) {
F_19 ( L_347 , V_66 ) ;
} else {
F_240 ( V_68 , V_730 ) ;
}
F_3 ( V_5 , L_348 , V_791 ,
V_730 [ V_388 ] , V_730 [ V_389 ] ) ;
V_66 = F_88 ( V_68 , L_349 , & V_792 ) ;
if ( V_66 ) {
F_19 ( L_350 , V_66 ) ;
V_793 = 1 ;
} else {
for ( V_793 = 0 ; V_792 ; V_793 ++ )
V_792 = V_792 & ( V_792 - 1 ) ;
}
F_3 ( V_5 , L_351 , V_793 ) ;
V_66 = F_239 ( V_97 , V_730 ) ;
if ( V_66 ) {
F_19 ( L_352 , V_66 ) ;
return V_66 ;
}
V_795 = V_790 [ 0 ] ;
for ( V_135 = 1 ; V_135 <= V_795 && V_135 < F_154 ( V_790 ) ; V_135 ++ ) {
V_375 = NULL ;
if ( ( V_790 [ V_135 ] == V_728 ) &&
( V_770 . V_134 > 0 ) )
V_375 = & V_770 ;
else if ( ( V_790 [ V_135 ] == V_729 ) &&
( V_639 . V_134 > 0 ) )
V_375 = & V_639 ;
else
continue;
if ( V_730 [ V_375 -> V_375 ] & V_775 ) {
V_375 -> V_739 . V_740 |= V_798 ;
V_375 -> V_739 . V_740 |= V_741 ;
}
V_375 -> V_739 . V_740 |= V_799 ;
V_375 -> V_739 . V_740 |= V_800 ;
V_375 -> V_739 . V_801 = true ;
V_375 -> V_739 . V_802 = V_803 ;
V_375 -> V_739 . V_804 = V_805 ;
memset ( V_375 -> V_739 . V_806 . V_807 , 0xff , V_793 ) ;
V_375 -> V_739 . V_806 . V_808 = V_809 ;
V_387 [ V_375 -> V_375 ] = V_375 ;
}
V_81 = F_33 ( V_97 ) ;
V_81 -> V_387 [ V_388 ] = V_387 [ V_388 ] ;
V_81 -> V_387 [ V_389 ] = V_387 [ V_389 ] ;
F_180 ( V_81 , & V_654 ) ;
return V_66 ;
}
static T_5 F_242 ( struct V_96 * V_97 )
{
return F_241 ( V_97 ) ;
}
static T_5 F_243 ( struct V_96 * V_97 )
{
struct V_64 * V_65 ;
struct V_80 * V_76 ;
struct V_67 * V_68 ;
T_5 V_810 ;
T_5 V_66 = 0 ;
if ( V_97 -> V_724 )
return V_66 ;
V_65 = F_65 ( V_97 ) ;
V_76 = V_65 -> V_131 ;
V_68 = F_18 ( V_65 ) ;
F_43 ( V_68 , V_583 , 0 ) ;
F_238 ( V_68 , V_811 ,
V_812 , V_813 ) ;
V_810 = V_97 -> V_364 ? V_365 : V_366 ;
V_66 = F_43 ( V_68 , V_367 , V_810 ) ;
if ( V_66 )
goto V_814;
F_3 ( V_5 , L_353 ,
( V_810 ? L_158 : L_159 ) ) ;
V_66 = F_237 ( V_68 , V_815 ) ;
if ( V_66 )
goto V_814;
V_66 = F_40 ( V_76 -> V_81 , V_65 , V_76 -> V_75 ,
NULL , NULL ) ;
if ( V_66 )
goto V_814;
V_66 = F_242 ( V_97 ) ;
if ( V_66 )
goto V_814;
F_20 ( V_68 , true ) ;
V_97 -> V_724 = true ;
V_814:
return V_66 ;
}
static T_5 F_244 ( struct V_67 * V_68 )
{
F_42 ( V_3 , & V_68 -> V_2 -> V_4 ) ;
return F_243 ( V_68 -> V_421 -> V_422 ) ;
}
static T_5 F_245 ( struct V_67 * V_68 )
{
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
if ( F_1 ( V_68 -> V_2 ) ) {
F_67 ( V_68 -> V_2 ) ;
F_125 ( 500 ) ;
}
F_113 ( V_97 ) ;
F_58 ( V_3 , & V_68 -> V_2 -> V_4 ) ;
return 0 ;
}
T_5 F_246 ( struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
T_5 V_66 = 0 ;
F_210 ( & V_97 -> V_725 ) ;
V_66 = F_244 ( V_68 ) ;
F_211 ( & V_97 -> V_725 ) ;
return V_66 ;
}
T_5 F_247 ( struct V_64 * V_65 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
struct V_96 * V_97 = V_68 -> V_421 -> V_422 ;
T_5 V_66 = 0 ;
F_210 ( & V_97 -> V_725 ) ;
V_66 = F_245 ( V_68 ) ;
F_211 ( & V_97 -> V_725 ) ;
return V_66 ;
}
enum V_74 F_248 ( struct V_67 * V_68 )
{
struct V_80 * V_76 = & V_68 -> V_2 -> V_76 ;
return V_76 -> V_75 ;
}
T_4 F_249 ( struct V_96 * V_97 , unsigned long V_816 )
{
struct V_1 * V_2 ;
bool V_313 = 0 ;
F_131 (vif, &cfg->vif_list, list) {
if ( F_2 ( V_816 , & V_2 -> V_4 ) )
V_313 ++ ;
}
return V_313 ;
}
static inline bool F_250 ( struct V_700 * V_658 ,
T_2 V_149 )
{
T_2 V_817 ;
F_210 ( & V_658 -> V_703 ) ;
V_817 = V_658 -> V_149 ;
F_211 ( & V_658 -> V_703 ) ;
return V_817 == V_149 ;
}
void F_251 ( struct V_96 * V_97 ,
struct V_1 * V_2 )
{
struct V_700 * V_658 = & V_97 -> V_701 ;
F_210 ( & V_658 -> V_703 ) ;
V_658 -> V_2 = V_2 ;
V_658 -> V_149 = 0 ;
F_211 ( & V_658 -> V_703 ) ;
}
bool F_38 ( struct V_96 * V_97 )
{
struct V_700 * V_658 = & V_97 -> V_701 ;
bool V_818 ;
F_210 ( & V_658 -> V_703 ) ;
V_818 = V_658 -> V_2 != NULL ;
F_211 ( & V_658 -> V_703 ) ;
return V_818 ;
}
int F_252 ( struct V_96 * V_97 ,
T_2 V_149 , T_11 V_362 )
{
struct V_700 * V_658 = & V_97 -> V_701 ;
return F_253 ( V_658 -> V_706 ,
F_250 ( V_658 , V_149 ) , V_362 ) ;
}
