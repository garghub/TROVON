STATIC int
F_1 (
struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 . V_5 ;
int V_6 , V_7 ;
if ( V_2 -> V_8 & V_9 )
return 0 ;
if ( F_2 ( V_3 ) ) {
F_3 ( V_2 , L_1 ) ;
return F_4 ( V_10 ) ;
}
F_5 ( & V_11 ) ;
for ( V_7 = 0 , V_6 = - 1 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) ) {
V_6 = V_7 ;
continue;
}
if ( F_6 ( V_3 , & V_13 [ V_7 ] ) )
goto V_14;
}
if ( V_6 < 0 ) {
V_13 = F_7 ( V_13 ,
( V_12 + 1 ) * sizeof( * V_13 ) ,
V_12 * sizeof( * V_13 ) ,
V_15 ) ;
V_6 = V_12 ++ ;
}
V_13 [ V_6 ] = * V_3 ;
F_8 ( & V_11 ) ;
return 0 ;
V_14:
F_8 ( & V_11 ) ;
F_3 ( V_2 , L_2 , V_3 ) ;
return F_4 ( V_10 ) ;
}
STATIC void
F_9 (
struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 . V_5 ;
int V_7 ;
if ( V_2 -> V_8 & V_9 )
return;
F_5 ( & V_11 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) )
continue;
if ( ! F_6 ( V_3 , & V_13 [ V_7 ] ) )
continue;
memset ( & V_13 [ V_7 ] , 0 , sizeof( T_1 ) ) ;
break;
}
ASSERT ( V_7 < V_12 ) ;
F_8 ( & V_11 ) ;
}
struct V_16 *
F_10 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_16 * V_18 ;
int V_19 = 0 ;
F_11 () ;
V_18 = F_12 ( & V_2 -> V_20 , V_17 ) ;
if ( V_18 ) {
ASSERT ( F_13 ( & V_18 -> V_21 ) >= 0 ) ;
V_19 = F_14 ( & V_18 -> V_21 ) ;
}
F_15 () ;
F_16 ( V_2 , V_17 , V_19 , V_22 ) ;
return V_18 ;
}
struct V_16 *
F_17 (
struct V_1 * V_2 ,
T_2 V_23 ,
int V_24 )
{
struct V_16 * V_18 ;
int V_25 ;
int V_19 ;
F_11 () ;
V_25 = F_18 ( & V_2 -> V_20 ,
( void * * ) & V_18 , V_23 , 1 , V_24 ) ;
if ( V_25 <= 0 ) {
F_15 () ;
return NULL ;
}
V_19 = F_14 ( & V_18 -> V_21 ) ;
F_15 () ;
F_19 ( V_2 , V_18 -> V_26 , V_19 , V_22 ) ;
return V_18 ;
}
void
F_20 ( struct V_16 * V_18 )
{
int V_19 ;
ASSERT ( F_13 ( & V_18 -> V_21 ) > 0 ) ;
V_19 = F_21 ( & V_18 -> V_21 ) ;
F_22 ( V_18 -> V_27 , V_18 -> V_26 , V_19 , V_22 ) ;
}
STATIC void
F_23 (
struct V_28 * V_29 )
{
struct V_16 * V_18 = F_24 ( V_29 , struct V_16 , V_28 ) ;
ASSERT ( F_13 ( & V_18 -> V_21 ) == 0 ) ;
F_25 ( V_18 ) ;
}
STATIC void
F_26 (
T_3 * V_2 )
{
T_2 V_17 ;
struct V_16 * V_18 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 . V_30 ; V_17 ++ ) {
F_27 ( & V_2 -> V_31 ) ;
V_18 = F_28 ( & V_2 -> V_20 , V_17 ) ;
F_29 ( & V_2 -> V_31 ) ;
ASSERT ( V_18 ) ;
ASSERT ( F_13 ( & V_18 -> V_21 ) == 0 ) ;
F_30 ( & V_18 -> V_28 , F_23 ) ;
}
}
int
F_31 (
T_4 * V_32 ,
T_5 V_33 )
{
ASSERT ( V_34 >= V_32 -> V_35 ) ;
ASSERT ( V_32 -> V_35 >= V_36 ) ;
#if V_37
if ( V_33 >> ( V_38 - V_32 -> V_35 ) > V_39 )
return V_40 ;
#else
if ( V_33 << ( V_32 -> V_35 - V_36 ) > V_41 )
return V_40 ;
#endif
return 0 ;
}
STATIC int
F_32 (
T_3 * V_2 ,
T_4 * V_32 ,
bool V_42 ,
bool V_43 )
{
if ( V_32 -> V_44 != V_45 ) {
F_3 ( V_2 , L_3 ) ;
return F_4 ( V_46 ) ;
}
if ( ! F_33 ( V_32 ) ) {
F_3 ( V_2 , L_4 ) ;
return F_4 ( V_46 ) ;
}
if ( ( V_32 -> V_47 & ( V_48 | V_49 ) ) &&
( V_32 -> V_47 & ( V_50 | V_51 |
V_52 | V_53 ) ) ) {
F_34 ( V_2 ,
L_5 ) ;
return F_4 ( V_54 ) ;
}
if ( V_43 && F_35 ( V_32 ) == V_55 ) {
F_36 ( V_2 ,
L_6
L_7 ) ;
if ( F_37 ( V_32 ,
V_56 ) ) {
F_3 ( V_2 ,
L_8
L_9 ,
( V_32 -> V_57 &
V_56 ) ) ;
}
if ( F_38 ( V_32 ,
V_58 ) ) {
F_36 ( V_2 ,
L_10 ,
( V_32 -> V_59 &
V_58 ) ) ;
if ( ! ( V_2 -> V_8 & V_60 ) ) {
F_3 ( V_2 ,
L_11
L_12 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_39 ( V_32 ,
V_61 ) ) {
F_3 ( V_2 ,
L_13
L_14 ,
( V_32 -> V_62 &
V_61 ) ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_40 (
V_32 -> V_63 == 0 && V_2 -> V_64 == V_2 -> V_65 ) ) {
F_3 ( V_2 ,
L_15
L_16 ) ;
return F_4 ( V_10 ) ;
}
if ( F_40 (
V_32 -> V_63 != 0 && V_2 -> V_64 != V_2 -> V_65 ) ) {
F_3 ( V_2 ,
L_17
L_18 ) ;
return F_4 ( V_10 ) ;
}
if ( F_40 (
V_32 -> V_30 <= 0 ||
V_32 -> V_66 < V_67 ||
V_32 -> V_66 > V_68 ||
V_32 -> V_69 < V_70 ||
V_32 -> V_69 > V_71 ||
V_32 -> V_66 != ( 1 << V_32 -> V_69 ) ||
V_32 -> V_72 < V_73 ||
V_32 -> V_72 > V_74 ||
V_32 -> V_35 < V_75 ||
V_32 -> V_35 > V_76 ||
V_32 -> V_72 != ( 1 << V_32 -> V_35 ) ||
V_32 -> V_77 < V_78 ||
V_32 -> V_77 > V_79 ||
V_32 -> V_80 < V_81 ||
V_32 -> V_80 > V_82 ||
V_32 -> V_77 != ( 1 << V_32 -> V_80 ) ||
( V_32 -> V_35 - V_32 -> V_80 != V_32 -> V_83 ) ||
( V_32 -> V_84 * V_32 -> V_72 > V_85 ) ||
( V_32 -> V_84 * V_32 -> V_72 < V_86 ) ||
( V_32 -> V_87 > 100 ) ||
V_32 -> V_88 == 0 ||
V_32 -> V_88 > F_41 ( V_32 ) ||
V_32 -> V_88 < F_42 ( V_32 ) ) ) {
F_43 ( L_19 ,
V_89 , V_2 , V_32 ) ;
return F_4 ( V_54 ) ;
}
if ( F_40 ( V_32 -> V_72 > V_90 ) ) {
F_3 ( V_2 ,
L_20
L_21 ,
V_32 -> V_72 , V_90 ) ;
return F_4 ( V_91 ) ;
}
switch ( V_32 -> V_77 ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_3 ( V_2 , L_22 ,
V_32 -> V_77 ) ;
return F_4 ( V_91 ) ;
}
if ( F_31 ( V_32 , V_32 -> V_88 ) ||
F_31 ( V_32 , V_32 -> V_92 ) ) {
F_3 ( V_2 ,
L_23 ) ;
return F_4 ( V_40 ) ;
}
if ( V_42 && V_32 -> V_93 ) {
F_3 ( V_2 , L_24 ) ;
return F_4 ( V_54 ) ;
}
if ( F_40 ( ! F_44 ( V_32 ) ) ) {
F_3 ( V_2 , L_25 ) ;
return F_4 ( V_91 ) ;
}
return 0 ;
}
int
F_45 (
T_3 * V_2 ,
T_2 V_94 ,
T_2 * V_95 )
{
T_2 V_96 ;
T_2 V_97 = 0 ;
T_6 * V_18 ;
T_7 V_98 ;
T_8 V_99 ;
T_4 * V_32 = & V_2 -> V_4 ;
int error = - V_100 ;
for ( V_96 = 0 ; V_96 < V_94 ; V_96 ++ ) {
V_18 = F_10 ( V_2 , V_96 ) ;
if ( V_18 ) {
F_20 ( V_18 ) ;
continue;
}
if ( ! V_97 )
V_97 = V_96 ;
V_18 = F_46 ( sizeof( * V_18 ) , V_101 ) ;
if ( ! V_18 )
goto V_102;
V_18 -> V_26 = V_96 ;
V_18 -> V_27 = V_2 ;
F_47 ( & V_18 -> V_103 ) ;
F_48 ( & V_18 -> V_104 ) ;
F_49 ( & V_18 -> V_105 , V_106 ) ;
F_47 ( & V_18 -> V_107 ) ;
V_18 -> V_108 = V_109 ;
if ( F_50 ( V_110 ) )
goto V_102;
F_27 ( & V_2 -> V_31 ) ;
if ( F_51 ( & V_2 -> V_20 , V_96 , V_18 ) ) {
F_52 () ;
F_29 ( & V_2 -> V_31 ) ;
F_53 () ;
error = - V_111 ;
goto V_102;
}
F_29 ( & V_2 -> V_31 ) ;
F_53 () ;
}
V_98 = F_54 ( V_2 , V_32 -> V_112 - 1 , 0 ) ;
V_99 = F_55 ( V_2 , V_94 - 1 , V_98 ) ;
if ( ( V_2 -> V_8 & V_113 ) && V_99 > V_114 )
V_2 -> V_8 |= V_115 ;
else
V_2 -> V_8 &= ~ V_115 ;
if ( V_2 -> V_8 & V_115 )
V_96 = F_56 ( V_2 ) ;
else
V_96 = F_57 ( V_2 ) ;
if ( V_95 )
* V_95 = V_96 ;
return 0 ;
V_102:
F_25 ( V_18 ) ;
for (; V_96 > V_97 ; V_96 -- ) {
V_18 = F_28 ( & V_2 -> V_20 , V_96 ) ;
F_25 ( V_18 ) ;
}
return error ;
}
static void
F_58 ( struct V_116 * V_32 )
{
if ( V_32 -> V_47 & V_48 )
V_32 -> V_47 |= ( V_32 -> V_47 & V_117 ) ?
V_50 : V_51 ;
if ( V_32 -> V_47 & V_49 )
V_32 -> V_47 |= ( V_32 -> V_47 & V_117 ) ?
V_52 : V_53 ;
V_32 -> V_47 &= ~ ( V_48 | V_49 ) ;
}
void
F_59 (
struct V_116 * V_118 ,
T_9 * V_119 )
{
V_118 -> V_44 = F_60 ( V_119 -> V_44 ) ;
V_118 -> V_72 = F_60 ( V_119 -> V_72 ) ;
V_118 -> V_88 = F_61 ( V_119 -> V_88 ) ;
V_118 -> V_92 = F_61 ( V_119 -> V_92 ) ;
V_118 -> V_120 = F_61 ( V_119 -> V_120 ) ;
memcpy ( & V_118 -> V_5 , & V_119 -> V_5 , sizeof( V_118 -> V_5 ) ) ;
V_118 -> V_63 = F_61 ( V_119 -> V_63 ) ;
V_118 -> V_121 = F_61 ( V_119 -> V_121 ) ;
V_118 -> V_122 = F_61 ( V_119 -> V_122 ) ;
V_118 -> V_123 = F_61 ( V_119 -> V_123 ) ;
V_118 -> V_84 = F_60 ( V_119 -> V_84 ) ;
V_118 -> V_112 = F_60 ( V_119 -> V_112 ) ;
V_118 -> V_30 = F_60 ( V_119 -> V_30 ) ;
V_118 -> V_124 = F_60 ( V_119 -> V_124 ) ;
V_118 -> V_125 = F_60 ( V_119 -> V_125 ) ;
V_118 -> V_126 = F_62 ( V_119 -> V_126 ) ;
V_118 -> V_66 = F_62 ( V_119 -> V_66 ) ;
V_118 -> V_77 = F_62 ( V_119 -> V_77 ) ;
V_118 -> V_127 = F_62 ( V_119 -> V_127 ) ;
memcpy ( & V_118 -> V_128 , & V_119 -> V_128 , sizeof( V_118 -> V_128 ) ) ;
V_118 -> V_35 = V_119 -> V_35 ;
V_118 -> V_69 = V_119 -> V_69 ;
V_118 -> V_80 = V_119 -> V_80 ;
V_118 -> V_83 = V_119 -> V_83 ;
V_118 -> V_129 = V_119 -> V_129 ;
V_118 -> V_130 = V_119 -> V_130 ;
V_118 -> V_93 = V_119 -> V_93 ;
V_118 -> V_87 = V_119 -> V_87 ;
V_118 -> V_131 = F_61 ( V_119 -> V_131 ) ;
V_118 -> V_132 = F_61 ( V_119 -> V_132 ) ;
V_118 -> V_133 = F_61 ( V_119 -> V_133 ) ;
V_118 -> V_134 = F_61 ( V_119 -> V_134 ) ;
V_118 -> V_135 = F_61 ( V_119 -> V_135 ) ;
V_118 -> V_136 = F_61 ( V_119 -> V_136 ) ;
V_118 -> V_47 = F_62 ( V_119 -> V_47 ) ;
V_118 -> V_137 = V_119 -> V_137 ;
V_118 -> V_138 = V_119 -> V_138 ;
V_118 -> V_139 = F_60 ( V_119 -> V_139 ) ;
V_118 -> V_140 = F_60 ( V_119 -> V_140 ) ;
V_118 -> V_141 = F_60 ( V_119 -> V_141 ) ;
V_118 -> V_142 = V_119 -> V_142 ;
V_118 -> V_143 = V_119 -> V_143 ;
V_118 -> V_144 = F_62 ( V_119 -> V_144 ) ;
V_118 -> V_145 = F_60 ( V_119 -> V_145 ) ;
V_118 -> V_146 = F_60 ( V_119 -> V_146 ) ;
V_118 -> V_147 = F_60 ( V_119 -> V_147 ) ;
V_118 -> V_57 = F_60 ( V_119 -> V_57 ) ;
V_118 -> V_59 = F_60 ( V_119 -> V_59 ) ;
V_118 -> V_62 = F_60 ( V_119 -> V_62 ) ;
V_118 -> V_148 =
F_60 ( V_119 -> V_148 ) ;
V_118 -> V_149 = 0 ;
V_118 -> V_150 = F_61 ( V_119 -> V_150 ) ;
V_118 -> V_151 = F_61 ( V_119 -> V_151 ) ;
}
static inline void
F_63 (
T_9 * V_118 ,
T_4 * V_119 ,
T_10 * V_152 )
{
T_11 V_153 = V_119 -> V_47 ;
if ( * V_152 & V_154 ) {
V_153 &= ~ ( V_50 | V_52 |
V_51 | V_53 ) ;
if ( V_119 -> V_47 &
( V_50 | V_51 ) )
V_153 |= V_48 ;
if ( V_119 -> V_47 &
( V_52 | V_53 ) )
V_153 |= V_49 ;
V_118 -> V_47 = F_64 ( V_153 ) ;
* V_152 &= ~ V_154 ;
}
}
void
F_65 (
T_9 * V_118 ,
T_4 * V_119 ,
T_10 V_152 )
{
T_12 V_155 = ( T_12 ) V_118 ;
T_12 V_156 = ( T_12 ) V_119 ;
T_13 V_157 ;
int V_23 ;
int V_158 ;
ASSERT ( V_152 ) ;
if ( ! V_152 )
return;
F_63 ( V_118 , V_119 , & V_152 ) ;
while ( V_152 ) {
V_157 = ( T_13 ) F_66 ( ( T_5 ) V_152 ) ;
V_23 = V_159 [ V_157 ] . V_160 ;
V_158 = V_159 [ V_157 + 1 ] . V_160 - V_23 ;
ASSERT ( V_159 [ V_157 ] . type == 0 || V_159 [ V_157 ] . type == 1 ) ;
if ( V_158 == 1 || V_159 [ V_157 ] . type == 1 ) {
memcpy ( V_155 + V_23 , V_156 + V_23 , V_158 ) ;
} else {
switch ( V_158 ) {
case 2 :
* ( V_161 * ) ( V_155 + V_23 ) =
F_64 ( * ( V_162 * ) ( V_156 + V_23 ) ) ;
break;
case 4 :
* ( V_163 * ) ( V_155 + V_23 ) =
F_67 ( * ( V_164 * ) ( V_156 + V_23 ) ) ;
break;
case 8 :
* ( V_165 * ) ( V_155 + V_23 ) =
F_68 ( * ( V_166 * ) ( V_156 + V_23 ) ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
V_152 &= ~ ( 1LL << V_157 ) ;
}
}
static int
F_69 (
struct V_167 * V_168 ,
bool V_43 )
{
struct V_1 * V_2 = V_168 -> V_169 -> V_170 ;
struct V_116 V_171 ;
F_59 ( & V_171 , F_70 ( V_168 ) ) ;
return F_32 ( V_2 , & V_171 , V_168 -> V_172 == V_173 ,
V_43 ) ;
}
static void
F_71 (
struct V_167 * V_168 )
{
struct V_1 * V_2 = V_168 -> V_169 -> V_170 ;
struct V_174 * V_175 = F_70 ( V_168 ) ;
int error ;
if ( V_175 -> V_44 == F_67 ( V_45 ) &&
( ( ( F_62 ( V_175 -> V_126 ) & V_176 ) ==
V_55 ) ||
V_175 -> V_177 != 0 ) ) {
if ( ! F_72 ( V_168 -> V_178 , F_62 ( V_175 -> V_66 ) ,
F_73 ( struct V_116 , V_177 ) ) ) {
error = V_54 ;
goto V_179;
}
}
error = F_69 ( V_168 , true ) ;
V_179:
if ( error ) {
F_43 ( V_180 , V_89 , V_2 , V_168 -> V_178 ) ;
F_74 ( V_168 , error ) ;
}
}
static void
F_75 (
struct V_167 * V_168 )
{
struct V_174 * V_175 = F_70 ( V_168 ) ;
if ( V_175 -> V_44 == F_67 ( V_45 ) ) {
F_71 ( V_168 ) ;
return;
}
F_74 ( V_168 , V_46 ) ;
}
static void
F_76 (
struct V_167 * V_168 )
{
struct V_1 * V_2 = V_168 -> V_169 -> V_170 ;
struct V_181 * V_182 = V_168 -> V_183 ;
int error ;
error = F_69 ( V_168 , false ) ;
if ( error ) {
F_43 ( V_180 , V_89 , V_2 , V_168 -> V_178 ) ;
F_74 ( V_168 , error ) ;
return;
}
if ( ! F_77 ( & V_2 -> V_4 ) )
return;
if ( V_182 )
F_70 ( V_168 ) -> V_151 = F_68 ( V_182 -> V_184 . V_185 ) ;
F_78 ( V_168 -> V_178 , F_79 ( V_168 -> V_186 ) ,
F_73 ( struct V_116 , V_177 ) ) ;
}
int
F_80 ( T_3 * V_2 , int V_187 )
{
unsigned int V_188 ;
struct V_167 * V_168 ;
struct V_116 * V_32 = & V_2 -> V_4 ;
int error ;
int V_189 = ! ( V_187 & V_190 ) ;
ASSERT ( V_2 -> V_191 == NULL ) ;
ASSERT ( V_2 -> V_65 != NULL ) ;
V_188 = F_81 ( V_2 -> V_65 ) ;
V_192:
V_168 = F_82 ( V_2 -> V_65 , V_173 ,
F_83 ( V_188 ) , 0 ,
V_189 ? & V_193
: & V_194 ) ;
if ( ! V_168 ) {
if ( V_189 )
F_3 ( V_2 , L_26 ) ;
return V_195 ;
}
if ( V_168 -> V_196 ) {
error = V_168 -> V_196 ;
if ( V_189 )
F_3 ( V_2 , L_27 , error ) ;
goto V_197;
}
F_59 ( & V_2 -> V_4 , F_70 ( V_168 ) ) ;
F_58 ( & V_2 -> V_4 ) ;
if ( V_188 > V_32 -> V_66 ) {
if ( V_189 )
F_3 ( V_2 , L_28 ,
V_188 , V_32 -> V_66 ) ;
error = V_91 ;
goto V_197;
}
if ( V_188 < V_32 -> V_66 ) {
F_84 ( V_168 ) ;
V_188 = V_32 -> V_66 ;
goto V_192;
}
F_85 ( V_2 ) ;
V_168 -> V_198 = & V_193 ;
V_2 -> V_191 = V_168 ;
F_86 ( V_168 ) ;
return 0 ;
V_197:
F_84 ( V_168 ) ;
return error ;
}
STATIC void
F_87 ( T_3 * V_2 , T_4 * V_32 )
{
V_2 -> V_199 = V_2 -> V_200 = 0 ;
F_47 ( & V_2 -> V_201 ) ;
V_2 -> V_202 = V_2 -> V_4 . V_30 ;
V_2 -> V_203 = V_32 -> V_35 + V_204 ;
V_2 -> V_205 = V_32 -> V_35 - V_36 ;
V_2 -> V_206 = V_32 -> V_69 - V_36 ;
V_2 -> V_207 = F_88 ( V_32 -> V_30 - 1 ) + 1 ;
V_2 -> V_208 = V_32 -> V_83 + V_32 -> V_129 ;
V_2 -> V_209 = V_32 -> V_72 - 1 ;
V_2 -> V_210 = V_32 -> V_72 >> V_211 ;
V_2 -> V_212 = V_2 -> V_210 - 1 ;
V_2 -> V_213 [ 0 ] = F_89 ( V_2 , V_32 -> V_72 , 1 ) ;
V_2 -> V_213 [ 1 ] = F_89 ( V_2 , V_32 -> V_72 , 0 ) ;
V_2 -> V_214 [ 0 ] = V_2 -> V_213 [ 0 ] / 2 ;
V_2 -> V_214 [ 1 ] = V_2 -> V_213 [ 1 ] / 2 ;
V_2 -> V_215 [ 0 ] = F_90 ( V_2 , V_32 -> V_72 , 1 ) ;
V_2 -> V_215 [ 1 ] = F_90 ( V_2 , V_32 -> V_72 , 0 ) ;
V_2 -> V_216 [ 0 ] = V_2 -> V_215 [ 0 ] / 2 ;
V_2 -> V_216 [ 1 ] = V_2 -> V_215 [ 1 ] / 2 ;
V_2 -> V_217 [ 0 ] = F_91 ( V_2 , V_32 -> V_72 , 1 ) ;
V_2 -> V_217 [ 1 ] = F_91 ( V_2 , V_32 -> V_72 , 0 ) ;
V_2 -> V_218 [ 0 ] = V_2 -> V_217 [ 0 ] / 2 ;
V_2 -> V_218 [ 1 ] = V_2 -> V_217 [ 1 ] / 2 ;
V_2 -> V_219 = F_92 ( V_2 , 1 ) ;
V_2 -> V_220 = ( int ) F_93 ( ( T_11 ) V_221 ,
V_32 -> V_127 ) ;
V_2 -> V_222 = V_2 -> V_220 >> V_32 -> V_83 ;
}
STATIC int
F_94 ( T_3 * V_2 , T_2 V_94 )
{
T_2 V_96 ;
T_6 * V_18 ;
T_4 * V_32 = & V_2 -> V_4 ;
T_14 V_223 = 0 ;
T_14 V_224 = 0 ;
T_14 V_225 = 0 ;
T_14 V_226 = 0 ;
T_14 V_227 = 0 ;
int error ;
for ( V_96 = 0 ; V_96 < V_94 ; V_96 ++ ) {
error = F_95 ( V_2 , NULL , V_96 , 0 ) ;
if ( error )
return error ;
error = F_96 ( V_2 , NULL , V_96 ) ;
if ( error )
return error ;
V_18 = F_10 ( V_2 , V_96 ) ;
V_223 += V_18 -> V_228 ;
V_224 += V_18 -> V_229 ;
V_225 += V_18 -> V_230 ;
V_226 += V_18 -> V_231 ;
V_227 += V_18 -> V_232 ;
F_20 ( V_18 ) ;
}
F_27 ( & V_2 -> V_233 ) ;
V_32 -> V_132 = V_223 ;
V_32 -> V_131 = V_224 ;
V_32 -> V_133 = V_225 + V_226 + V_227 ;
F_29 ( & V_2 -> V_233 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
STATIC int
F_97 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
if ( V_2 -> V_234 ) {
if ( ( F_79 ( V_2 -> V_234 ) & V_2 -> V_209 ) ||
( F_79 ( V_2 -> V_235 ) & V_2 -> V_209 ) ) {
F_3 ( V_2 ,
L_29 ,
V_32 -> V_72 ) ;
return F_4 ( V_10 ) ;
} else {
V_2 -> V_234 = F_98 ( V_2 , V_2 -> V_234 ) ;
if ( V_2 -> V_234 && ( V_32 -> V_112 % V_2 -> V_234 ) ) {
F_3 ( V_2 ,
L_30 ,
V_32 -> V_112 ) ;
return F_4 ( V_10 ) ;
} else if ( V_2 -> V_234 ) {
V_2 -> V_235 = F_98 ( V_2 , V_2 -> V_235 ) ;
} else {
F_3 ( V_2 ,
L_31 ,
V_2 -> V_234 , V_32 -> V_72 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_99 ( V_32 ) ) {
if ( V_32 -> V_140 != V_2 -> V_234 ) {
V_32 -> V_140 = V_2 -> V_234 ;
V_2 -> V_236 |= V_237 ;
}
if ( V_32 -> V_141 != V_2 -> V_235 ) {
V_32 -> V_141 = V_2 -> V_235 ;
V_2 -> V_236 |= V_238 ;
}
} else {
F_3 ( V_2 ,
L_32 ) ;
return F_4 ( V_10 ) ;
}
} else if ( ( V_2 -> V_8 & V_239 ) != V_239 &&
F_99 ( & V_2 -> V_4 ) ) {
V_2 -> V_234 = V_32 -> V_140 ;
V_2 -> V_235 = V_32 -> V_141 ;
}
return 0 ;
}
STATIC void
F_100 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
T_5 V_240 ;
if ( V_32 -> V_87 ) {
V_240 = V_32 -> V_88 * V_32 -> V_87 ;
F_101 ( V_240 , 100 ) ;
F_101 ( V_240 , V_2 -> V_222 ) ;
V_2 -> V_241 = ( V_240 * V_2 -> V_222 ) <<
V_32 -> V_83 ;
} else {
V_2 -> V_241 = 0 ;
}
}
STATIC void
F_102 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
int V_242 , V_243 ;
if ( ! ( V_2 -> V_8 & V_244 ) ) {
if ( V_2 -> V_8 & V_245 ) {
V_242 = V_246 ;
V_243 = V_247 ;
} else {
V_242 = V_248 ;
V_243 = V_249 ;
}
} else {
V_242 = V_2 -> V_250 ;
V_243 = V_2 -> V_251 ;
}
if ( V_32 -> V_35 > V_242 ) {
V_2 -> V_250 = V_32 -> V_35 ;
} else {
V_2 -> V_250 = V_242 ;
}
V_2 -> V_252 = 1 << ( V_2 -> V_250 - V_32 -> V_35 ) ;
if ( V_32 -> V_35 > V_243 ) {
V_2 -> V_251 = V_32 -> V_35 ;
} else {
V_2 -> V_251 = V_243 ;
}
V_2 -> V_253 = 1 << ( V_2 -> V_251 - V_32 -> V_35 ) ;
}
void
F_103 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_254 ; V_7 ++ ) {
T_5 V_255 = V_2 -> V_4 . V_88 ;
F_101 ( V_255 , 100 ) ;
V_2 -> V_256 [ V_7 ] = V_255 * ( V_7 + 1 ) ;
}
}
STATIC void
F_104 ( T_3 * V_2 )
{
if ( F_105 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_139 >=
F_106 ( V_2 , V_2 -> V_257 ) )
V_2 -> V_258 = V_2 -> V_4 . V_139 - 1 ;
else
V_2 -> V_258 = 0 ;
if ( V_2 -> V_234 && V_2 -> V_258 &&
! ( V_2 -> V_234 & V_2 -> V_258 ) )
V_2 -> V_259 = V_2 -> V_234 ;
else
V_2 -> V_259 = 0 ;
}
STATIC int
F_107 ( T_3 * V_2 )
{
T_15 * V_168 ;
T_16 V_260 ;
V_260 = ( T_16 ) F_92 ( V_2 , V_2 -> V_4 . V_88 ) ;
if ( F_108 ( V_2 , V_260 ) != V_2 -> V_4 . V_88 ) {
F_3 ( V_2 , L_33 ) ;
return F_4 ( V_40 ) ;
}
V_168 = F_82 ( V_2 -> V_65 ,
V_260 - F_109 ( V_2 , 1 ) ,
F_109 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_168 ) {
F_3 ( V_2 , L_34 ) ;
return V_195 ;
}
F_84 ( V_168 ) ;
if ( V_2 -> V_64 != V_2 -> V_65 ) {
V_260 = ( T_16 ) F_92 ( V_2 , V_2 -> V_4 . V_125 ) ;
if ( F_108 ( V_2 , V_260 ) != V_2 -> V_4 . V_125 ) {
F_3 ( V_2 , L_35 ) ;
return F_4 ( V_40 ) ;
}
V_168 = F_82 ( V_2 -> V_64 ,
V_260 - F_92 ( V_2 , 1 ) ,
F_92 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_168 ) {
F_3 ( V_2 , L_36 ) ;
return V_195 ;
}
F_84 ( V_168 ) ;
}
return 0 ;
}
int
F_110 (
struct V_1 * V_2 )
{
int error ;
struct V_261 * V_262 ;
V_2 -> V_263 = 0 ;
if ( V_2 -> V_4 . V_47 == 0 )
return 0 ;
F_27 ( & V_2 -> V_233 ) ;
V_2 -> V_4 . V_47 = 0 ;
F_29 ( & V_2 -> V_233 ) ;
if ( V_2 -> V_8 & V_60 )
return 0 ;
V_262 = F_111 ( V_2 , V_264 ) ;
error = F_112 ( V_262 , 0 , F_113 ( V_2 ) ,
0 , 0 , V_265 ) ;
if ( error ) {
F_114 ( V_262 , 0 ) ;
F_36 ( V_2 , L_37 , V_180 ) ;
return error ;
}
F_115 ( V_262 , V_154 ) ;
return F_116 ( V_262 , 0 ) ;
}
T_5
F_117 ( T_3 * V_2 )
{
T_5 V_266 ;
V_266 = V_2 -> V_4 . V_88 ;
F_101 ( V_266 , 20 ) ;
V_266 = F_118 ( T_5 , V_266 , 8192 ) ;
return V_266 ;
}
int
F_119 (
T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
T_17 * V_267 ;
T_5 V_266 ;
T_18 V_268 = 0 ;
T_18 V_269 = 0 ;
int error = 0 ;
F_87 ( V_2 , V_32 ) ;
if ( F_120 ( V_32 ) ) {
F_3 ( V_2 , L_38 ) ;
V_32 -> V_146 |= V_32 -> V_147 ;
V_32 -> V_147 = V_32 -> V_146 ;
V_2 -> V_236 |= V_270 | V_271 ;
if ( F_121 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_272 ) )
V_2 -> V_8 |= V_273 ;
}
if ( F_121 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_272 ) ) {
F_122 ( & V_2 -> V_4 ) ;
V_2 -> V_236 |= V_270 ;
if ( ! V_32 -> V_146 )
V_2 -> V_236 |= V_274 ;
}
error = F_97 ( V_2 ) ;
if ( error )
goto V_275;
F_123 ( V_2 ) ;
F_124 ( V_2 , V_276 ) ;
F_124 ( V_2 , V_277 ) ;
F_125 ( V_2 ) ;
F_100 ( V_2 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_275;
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
V_2 -> V_257 = V_278 ;
F_104 ( V_2 ) ;
error = F_107 ( V_2 ) ;
if ( error )
goto V_279;
error = F_126 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_39 ) ;
goto V_279;
}
F_127 ( & V_32 -> V_5 , V_2 -> V_280 ) ;
V_2 -> V_281 = 0 ;
F_128 ( V_2 ) ;
V_2 -> V_282 = ( V_2 -> V_4 . V_72 * 37 ) / 100 ;
F_129 ( V_2 ) ;
F_47 ( & V_2 -> V_31 ) ;
F_49 ( & V_2 -> V_20 , V_106 ) ;
error = F_45 ( V_2 , V_32 -> V_30 , & V_2 -> V_202 ) ;
if ( error ) {
F_3 ( V_2 , L_40 , error ) ;
goto V_279;
}
if ( ! V_32 -> V_125 ) {
F_3 ( V_2 , L_41 ) ;
F_130 ( L_42 , V_89 , V_2 ) ;
error = F_4 ( V_54 ) ;
goto V_283;
}
error = F_131 ( V_2 , V_2 -> V_64 ,
F_132 ( V_2 , V_32 -> V_63 ) ,
F_92 ( V_2 , V_32 -> V_125 ) ) ;
if ( error ) {
F_3 ( V_2 , L_43 ) ;
goto V_284;
}
if ( F_133 ( & V_2 -> V_4 ) &&
! F_134 ( V_2 ) &&
! V_2 -> V_4 . V_93 ) {
error = F_94 ( V_2 , V_32 -> V_30 ) ;
if ( error )
goto V_284;
}
error = F_135 ( V_2 , NULL , V_32 -> V_121 , 0 , V_285 , & V_267 ) ;
if ( error ) {
F_3 ( V_2 , L_44 ) ;
goto V_286;
}
ASSERT ( V_267 != NULL ) ;
if ( F_40 ( ! F_136 ( V_267 -> V_287 . V_288 ) ) ) {
F_3 ( V_2 , L_45 ,
( unsigned long long ) V_267 -> V_289 ) ;
F_137 ( V_267 , V_285 ) ;
F_130 ( L_46 , V_89 ,
V_2 ) ;
error = F_4 ( V_54 ) ;
goto V_290;
}
V_2 -> V_291 = V_267 ;
F_137 ( V_267 , V_285 ) ;
error = F_138 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_47 ) ;
goto V_290;
}
if ( V_2 -> V_236 && ! ( V_2 -> V_8 & V_60 ) ) {
error = F_139 ( V_2 , V_2 -> V_236 ) ;
if ( error ) {
F_3 ( V_2 , L_48 ) ;
goto V_292;
}
}
if ( F_140 ( V_2 ) ) {
error = F_141 ( V_2 , & V_268 , & V_269 ) ;
if ( error )
goto V_292;
} else {
ASSERT ( ! F_142 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_47 & V_293 ) {
F_34 ( V_2 , L_49 ) ;
error = F_110 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_143 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_50 ) ;
goto V_292;
}
if ( V_268 ) {
ASSERT ( V_2 -> V_263 == 0 ) ;
V_2 -> V_263 = V_269 ;
F_144 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_60 ) ) {
V_266 = F_117 ( V_2 ) ;
error = F_145 ( V_2 , & V_266 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_51 ) ;
}
return 0 ;
V_292:
F_146 ( V_2 ) ;
V_290:
F_147 ( V_267 ) ;
V_286:
F_148 ( V_2 ) ;
V_284:
if ( V_2 -> V_64 && V_2 -> V_64 != V_2 -> V_65 )
F_149 ( V_2 -> V_64 ) ;
F_149 ( V_2 -> V_65 ) ;
V_283:
F_26 ( V_2 ) ;
V_279:
F_9 ( V_2 ) ;
V_275:
return error ;
}
void
F_150 (
struct V_1 * V_2 )
{
T_5 V_266 ;
int error ;
F_151 ( & V_2 -> V_294 ) ;
F_152 ( V_2 ) ;
F_146 ( V_2 ) ;
F_147 ( V_2 -> V_291 ) ;
F_153 ( V_2 , V_295 ) ;
F_154 ( V_2 -> V_296 ) ;
F_151 ( & V_2 -> V_297 ) ;
F_155 ( V_2 , V_298 ) ;
F_156 ( V_2 ) ;
V_266 = 0 ;
error = F_145 ( V_2 , & V_266 , NULL ) ;
if ( error )
F_3 ( V_2 , L_52
L_53 ) ;
error = F_157 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_54
L_53 ) ;
F_148 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_158 ( V_299 )
F_159 ( V_2 , 0 ) ;
#endif
F_26 ( V_2 ) ;
}
int
F_160 ( T_3 * V_2 )
{
return ! ( V_2 -> V_300 -> V_301 . V_302 || F_161 ( V_2 ) ||
( V_2 -> V_8 & V_60 ) ) ;
}
int
F_157 ( T_3 * V_2 )
{
T_19 * V_262 ;
int error ;
if ( ! F_160 ( V_2 ) )
return 0 ;
F_162 ( V_2 , 0 ) ;
if ( ! F_133 ( & V_2 -> V_4 ) )
return 0 ;
V_262 = F_163 ( V_2 , V_303 , V_15 ) ;
error = F_112 ( V_262 , 0 , F_164 ( V_2 ) , 0 , 0 ,
V_265 ) ;
if ( error ) {
F_114 ( V_262 , 0 ) ;
return error ;
}
F_115 ( V_262 , V_304 | V_305 | V_306 ) ;
F_165 ( V_262 ) ;
error = F_116 ( V_262 , 0 ) ;
return error ;
}
void
F_115 ( T_19 * V_262 , T_10 V_152 )
{
T_15 * V_168 ;
int V_23 ;
int V_307 ;
T_3 * V_2 ;
T_13 V_157 ;
ASSERT ( V_152 ) ;
if ( ! V_152 )
return;
V_2 = V_262 -> V_308 ;
V_168 = F_166 ( V_262 , V_2 , 0 ) ;
V_23 = sizeof( T_4 ) ;
V_307 = 0 ;
F_65 ( F_70 ( V_168 ) , & V_2 -> V_4 , V_152 ) ;
V_157 = ( T_13 ) F_167 ( ( T_5 ) V_152 ) ;
ASSERT ( ( 1LL << V_157 ) & V_309 ) ;
V_307 = V_159 [ V_157 + 1 ] . V_160 - 1 ;
V_157 = ( T_13 ) F_66 ( ( T_5 ) V_152 ) ;
ASSERT ( ( 1LL << V_157 ) & V_309 ) ;
V_23 = V_159 [ V_157 ] . V_160 ;
F_168 ( V_262 , V_168 , V_310 ) ;
F_169 ( V_262 , V_168 , V_23 , V_307 ) ;
}
STATIC int
F_170 (
T_3 * V_2 ,
T_13 V_311 ,
T_20 V_312 ,
int V_313 )
{
int V_314 ;
long long V_315 ;
long long V_316 , V_317 ;
switch ( V_311 ) {
case V_318 :
V_315 = ( long long ) V_2 -> V_4 . V_131 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_131 = V_315 ;
return 0 ;
case V_319 :
V_315 = ( long long ) V_2 -> V_4 . V_132 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_132 = V_315 ;
return 0 ;
case V_320 :
V_315 = ( long long )
V_2 -> V_4 . V_133 - F_171 ( V_2 ) ;
V_316 = ( long long ) ( V_2 -> V_321 - V_2 -> V_322 ) ;
if ( V_312 > 0 ) {
if ( V_316 > V_312 ) {
V_2 -> V_322 += V_312 ;
} else {
V_317 = V_312 - V_316 ;
V_2 -> V_322 = V_2 -> V_321 ;
V_315 += V_317 ;
}
} else {
V_315 += V_312 ;
if ( V_315 >= 0 ) {
V_2 -> V_4 . V_133 = V_315 +
F_171 ( V_2 ) ;
return 0 ;
}
if ( ! V_313 )
return F_4 ( V_323 ) ;
V_315 = ( long long ) V_2 -> V_322 + V_312 ;
if ( V_315 >= 0 ) {
V_2 -> V_322 = V_315 ;
return 0 ;
}
F_172 ( V_324
L_55
L_56 ,
V_2 -> V_325 ) ;
return F_4 ( V_323 ) ;
}
V_2 -> V_4 . V_133 = V_315 + F_171 ( V_2 ) ;
return 0 ;
case V_326 :
V_315 = ( long long ) V_2 -> V_4 . V_134 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
return F_4 ( V_323 ) ;
}
V_2 -> V_4 . V_134 = V_315 ;
return 0 ;
case V_327 :
V_315 = ( long long ) V_2 -> V_4 . V_88 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_88 = V_315 ;
return 0 ;
case V_328 :
V_314 = V_2 -> V_4 . V_30 ;
V_314 += V_312 ;
if ( V_314 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_30 = V_314 ;
return 0 ;
case V_329 :
V_314 = V_2 -> V_4 . V_87 ;
V_314 += V_312 ;
if ( V_314 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_87 = V_314 ;
return 0 ;
case V_330 :
V_314 = V_2 -> V_4 . V_84 ;
V_314 += V_312 ;
if ( V_314 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_84 = V_314 ;
return 0 ;
case V_331 :
V_314 = V_2 -> V_4 . V_124 ;
V_314 += V_312 ;
if ( V_314 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_124 = V_314 ;
return 0 ;
case V_332 :
V_315 = ( long long ) V_2 -> V_4 . V_92 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_92 = V_315 ;
return 0 ;
case V_333 :
V_315 = ( long long ) V_2 -> V_4 . V_120 ;
V_315 += V_312 ;
if ( V_315 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_120 = V_315 ;
return 0 ;
case V_334 :
V_314 = V_2 -> V_4 . V_130 ;
V_314 += V_312 ;
if ( V_314 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_130 = V_314 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_173 (
struct V_1 * V_2 ,
T_13 V_311 ,
T_20 V_312 ,
int V_313 )
{
int V_335 ;
#ifdef F_174
ASSERT ( V_311 < V_318 || V_311 > V_320 ) ;
#endif
F_27 ( & V_2 -> V_233 ) ;
V_335 = F_170 ( V_2 , V_311 , V_312 , V_313 ) ;
F_29 ( & V_2 -> V_233 ) ;
return V_335 ;
}
int
F_175 (
struct V_1 * V_2 ,
T_21 * V_336 ,
T_18 V_337 ,
int V_313 )
{
T_21 * V_338 ;
int error = 0 ;
F_27 ( & V_2 -> V_233 ) ;
for ( V_338 = V_336 ; V_338 < ( V_336 + V_337 ) ; V_338 ++ ) {
ASSERT ( V_338 -> V_339 < V_318 ||
V_338 -> V_339 > V_320 ) ;
error = F_170 ( V_2 , V_338 -> V_339 ,
V_338 -> V_340 , V_313 ) ;
if ( error )
goto V_341;
}
F_29 ( & V_2 -> V_233 ) ;
return 0 ;
V_341:
while ( -- V_338 >= V_336 ) {
error = F_170 ( V_2 , V_338 -> V_339 ,
- V_338 -> V_340 , V_313 ) ;
ASSERT ( error == 0 ) ;
}
F_29 ( & V_2 -> V_233 ) ;
return error ;
}
struct V_167 *
F_176 (
struct V_1 * V_2 ,
int V_187 )
{
struct V_167 * V_168 = V_2 -> V_191 ;
if ( ! F_177 ( V_168 ) ) {
if ( V_187 & V_342 )
return NULL ;
F_178 ( V_168 ) ;
}
F_179 ( V_168 ) ;
ASSERT ( F_180 ( V_168 ) ) ;
return V_168 ;
}
void
F_181 (
struct V_1 * V_2 )
{
struct V_167 * V_168 = V_2 -> V_191 ;
F_178 ( V_168 ) ;
V_2 -> V_191 = NULL ;
F_84 ( V_168 ) ;
}
int
F_139 (
T_3 * V_2 ,
T_10 V_152 )
{
T_19 * V_262 ;
int error ;
ASSERT ( V_152 & ( V_237 | V_238 | V_343 |
V_270 | V_271 |
V_274 ) ) ;
V_262 = F_111 ( V_2 , V_344 ) ;
error = F_112 ( V_262 , 0 , F_164 ( V_2 ) , 0 , 0 ,
V_265 ) ;
if ( error ) {
F_114 ( V_262 , 0 ) ;
return error ;
}
F_115 ( V_262 , V_152 ) ;
error = F_116 ( V_262 , 0 ) ;
return error ;
}
int
F_182 (
struct V_1 * V_2 ,
char * V_345 )
{
if ( F_183 ( V_2 -> V_65 ) ||
F_183 ( V_2 -> V_64 ) ||
( V_2 -> V_346 && F_183 ( V_2 -> V_346 ) ) ) {
F_34 ( V_2 , L_57 , V_345 ) ;
F_34 ( V_2 , L_58 ) ;
return V_347 ;
}
return 0 ;
}
STATIC int
F_184 (
struct V_348 * V_349 ,
unsigned long V_350 ,
void * V_351 )
{
T_22 * V_352 ;
T_3 * V_2 ;
V_2 = ( T_3 * ) F_24 ( V_349 , T_3 , V_353 ) ;
V_352 = ( T_22 * )
F_185 ( V_2 -> V_354 , ( unsigned long ) V_351 ) ;
switch ( V_350 ) {
case V_355 :
case V_356 :
memset ( V_352 , 0 , sizeof( T_22 ) ) ;
break;
case V_357 :
case V_358 :
F_186 ( V_2 ) ;
F_187 ( V_2 , V_318 , 0 ) ;
F_187 ( V_2 , V_319 , 0 ) ;
F_187 ( V_2 , V_320 , 0 ) ;
F_188 ( V_2 ) ;
break;
case V_359 :
case V_360 :
F_186 ( V_2 ) ;
F_27 ( & V_2 -> V_233 ) ;
F_189 ( V_2 , V_318 ) ;
F_189 ( V_2 , V_319 ) ;
F_189 ( V_2 , V_320 ) ;
V_2 -> V_4 . V_131 += V_352 -> V_361 ;
V_2 -> V_4 . V_132 += V_352 -> V_362 ;
V_2 -> V_4 . V_133 += V_352 -> V_363 ;
memset ( V_352 , 0 , sizeof( T_22 ) ) ;
F_190 ( V_2 , V_318 , 0 ) ;
F_190 ( V_2 , V_319 , 0 ) ;
F_190 ( V_2 , V_320 , 0 ) ;
F_29 ( & V_2 -> V_233 ) ;
F_188 ( V_2 ) ;
break;
}
return V_364 ;
}
int
F_191 (
T_3 * V_2 )
{
T_22 * V_352 ;
int V_7 ;
V_2 -> V_354 = F_192 ( T_22 ) ;
if ( V_2 -> V_354 == NULL )
return - V_100 ;
#ifdef F_193
V_2 -> V_353 . V_365 = F_184 ;
V_2 -> V_353 . V_366 = 0 ;
F_194 ( & V_2 -> V_353 ) ;
#endif
F_195 (i) {
V_352 = ( T_22 * ) F_185 ( V_2 -> V_354 , V_7 ) ;
memset ( V_352 , 0 , sizeof( T_22 ) ) ;
}
F_48 ( & V_2 -> V_367 ) ;
V_2 -> V_368 = - 1 ;
return 0 ;
}
void
F_85 (
T_3 * V_2 )
{
F_186 ( V_2 ) ;
V_2 -> V_368 = - 1 ;
F_187 ( V_2 , V_318 , 0 ) ;
F_187 ( V_2 , V_319 , 0 ) ;
F_187 ( V_2 , V_320 , 0 ) ;
F_188 ( V_2 ) ;
}
void
F_196 (
T_3 * V_2 )
{
if ( V_2 -> V_354 ) {
F_197 ( & V_2 -> V_353 ) ;
F_198 ( V_2 -> V_354 ) ;
}
F_199 ( & V_2 -> V_367 ) ;
}
STATIC void
F_200 (
T_22 * V_369 )
{
while ( F_201 ( V_370 , & V_369 -> V_371 ) ) {
F_202 ( 1000 ) ;
}
}
STATIC void
F_203 (
T_22 * V_369 )
{
F_204 ( V_370 , & V_369 -> V_371 ) ;
}
STATIC void
F_205 (
T_3 * V_2 )
{
T_22 * V_352 ;
int V_7 ;
F_195 (i) {
V_352 = ( T_22 * ) F_185 ( V_2 -> V_354 , V_7 ) ;
F_200 ( V_352 ) ;
}
}
STATIC void
F_206 (
T_3 * V_2 )
{
T_22 * V_352 ;
int V_7 ;
F_195 (i) {
V_352 = ( T_22 * ) F_185 ( V_2 -> V_354 , V_7 ) ;
F_203 ( V_352 ) ;
}
}
STATIC void
F_207 (
T_3 * V_2 ,
T_22 * V_372 ,
int V_187 )
{
T_22 * V_352 ;
int V_7 ;
memset ( V_372 , 0 , sizeof( T_22 ) ) ;
if ( ! ( V_187 & V_373 ) )
F_205 ( V_2 ) ;
F_195 (i) {
V_352 = ( T_22 * ) F_185 ( V_2 -> V_354 , V_7 ) ;
V_372 -> V_361 += V_352 -> V_361 ;
V_372 -> V_362 += V_352 -> V_362 ;
V_372 -> V_363 += V_352 -> V_363 ;
}
if ( ! ( V_187 & V_373 ) )
F_206 ( V_2 ) ;
}
STATIC int
F_208 (
T_3 * V_2 ,
T_13 V_311 )
{
ASSERT ( ( V_311 >= V_318 ) && ( V_311 <= V_320 ) ) ;
return F_209 ( V_311 , & V_2 -> V_368 ) ;
}
STATIC void
F_189 (
T_3 * V_2 ,
T_13 V_311 )
{
T_22 V_372 ;
ASSERT ( ( V_311 >= V_318 ) && ( V_311 <= V_320 ) ) ;
if ( F_208 ( V_2 , V_311 ) )
return;
F_205 ( V_2 ) ;
if ( ! F_201 ( V_311 , & V_2 -> V_368 ) ) {
F_207 ( V_2 , & V_372 , V_373 ) ;
switch( V_311 ) {
case V_318 :
V_2 -> V_4 . V_131 = V_372 . V_361 ;
break;
case V_319 :
V_2 -> V_4 . V_132 = V_372 . V_362 ;
break;
case V_320 :
V_2 -> V_4 . V_133 = V_372 . V_363 ;
break;
default:
F_52 () ;
}
}
F_206 ( V_2 ) ;
}
STATIC void
F_210 (
T_3 * V_2 ,
T_13 V_311 ,
T_14 V_374 ,
T_14 V_375 )
{
T_22 * V_352 ;
int V_7 ;
ASSERT ( ( V_311 >= V_318 ) && ( V_311 <= V_320 ) ) ;
F_205 ( V_2 ) ;
F_195 (i) {
V_352 = F_185 ( V_2 -> V_354 , V_7 ) ;
switch ( V_311 ) {
case V_318 :
V_352 -> V_361 = V_374 + V_375 ;
break;
case V_319 :
V_352 -> V_362 = V_374 + V_375 ;
break;
case V_320 :
V_352 -> V_363 = V_374 + V_375 ;
break;
default:
F_52 () ;
break;
}
V_375 = 0 ;
}
F_204 ( V_311 , & V_2 -> V_368 ) ;
F_206 ( V_2 ) ;
}
void
F_211 (
T_3 * V_2 ,
int V_187 )
{
T_22 V_372 ;
F_207 ( V_2 , & V_372 , V_187 ) ;
if ( ! F_208 ( V_2 , V_318 ) )
V_2 -> V_4 . V_131 = V_372 . V_361 ;
if ( ! F_208 ( V_2 , V_319 ) )
V_2 -> V_4 . V_132 = V_372 . V_362 ;
if ( ! F_208 ( V_2 , V_320 ) )
V_2 -> V_4 . V_133 = V_372 . V_363 ;
}
void
F_162 (
T_3 * V_2 ,
int V_187 )
{
F_27 ( & V_2 -> V_233 ) ;
F_211 ( V_2 , V_187 ) ;
F_29 ( & V_2 -> V_233 ) ;
}
STATIC void
F_190 (
T_3 * V_2 ,
T_13 V_311 ,
int V_376 )
{
T_14 V_374 , V_375 ;
int V_377 = F_212 () ;
T_14 V_378 = ( T_14 ) V_376 ;
F_189 ( V_2 , V_311 ) ;
switch ( V_311 ) {
case V_318 :
V_374 = V_2 -> V_4 . V_131 ;
V_375 = F_101 ( V_374 , V_377 ) ;
if ( V_374 < F_213 ( V_378 , V_379 ) )
return;
break;
case V_319 :
V_374 = V_2 -> V_4 . V_132 ;
V_375 = F_101 ( V_374 , V_377 ) ;
if ( V_374 < F_213 ( V_378 , V_379 ) )
return;
break;
case V_320 :
V_374 = V_2 -> V_4 . V_133 ;
V_375 = F_101 ( V_374 , V_377 ) ;
if ( V_374 < F_213 ( V_378 , F_214 ( V_2 ) ) )
return;
break;
default:
F_52 () ;
V_374 = V_375 = 0 ;
break;
}
F_210 ( V_2 , V_311 , V_374 , V_375 ) ;
}
STATIC void
F_187 (
T_3 * V_2 ,
T_13 V_152 ,
int V_376 )
{
F_27 ( & V_2 -> V_233 ) ;
F_190 ( V_2 , V_152 , V_376 ) ;
F_29 ( & V_2 -> V_233 ) ;
}
int
F_215 (
T_3 * V_2 ,
T_13 V_311 ,
T_20 V_312 ,
int V_313 )
{
T_22 * V_369 ;
long long V_315 ;
int V_380 = 0 ;
F_216 () ;
V_381:
F_217 () ;
V_369 = F_218 ( V_2 -> V_354 ) ;
if ( F_40 ( F_208 ( V_2 , V_311 ) ) )
goto V_382;
F_200 ( V_369 ) ;
if ( F_40 ( F_208 ( V_2 , V_311 ) ) ) {
F_203 ( V_369 ) ;
goto V_382;
}
switch ( V_311 ) {
case V_318 :
V_315 = V_369 -> V_361 ;
V_315 += V_312 ;
if ( F_40 ( V_315 < 0 ) )
goto V_383;
V_369 -> V_361 = V_315 ;
break;
case V_319 :
V_315 = V_369 -> V_362 ;
V_315 += V_312 ;
if ( F_40 ( V_315 < 0 ) )
goto V_383;
V_369 -> V_362 = V_315 ;
break;
case V_320 :
F_219 ( ( V_2 -> V_321 - V_2 -> V_322 ) != 0 ) ;
V_315 = V_369 -> V_363 - F_171 ( V_2 ) ;
V_315 += V_312 ;
if ( F_40 ( V_315 < 0 ) )
goto V_383;
V_369 -> V_363 = V_315 + F_171 ( V_2 ) ;
break;
default:
F_52 () ;
break;
}
F_203 ( V_369 ) ;
F_220 () ;
return 0 ;
V_382:
F_220 () ;
F_186 ( V_2 ) ;
if ( ! ( F_208 ( V_2 , V_311 ) ) ) {
F_188 ( V_2 ) ;
goto V_381;
}
F_27 ( & V_2 -> V_233 ) ;
V_380 = F_170 ( V_2 , V_311 , V_312 , V_313 ) ;
F_29 ( & V_2 -> V_233 ) ;
if ( V_380 != V_323 )
F_187 ( V_2 , V_311 , 0 ) ;
F_188 ( V_2 ) ;
return V_380 ;
V_383:
F_203 ( V_369 ) ;
F_220 () ;
F_186 ( V_2 ) ;
F_187 ( V_2 , V_311 , V_312 ) ;
F_188 ( V_2 ) ;
goto V_381;
}
