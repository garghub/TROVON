struct V_1 *
F_1 (
struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
int V_6 = 0 ;
F_2 () ;
V_5 = F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( V_5 ) {
ASSERT ( F_4 ( & V_5 -> V_8 ) >= 0 ) ;
V_6 = F_5 ( & V_5 -> V_8 ) ;
}
F_6 () ;
F_7 ( V_3 , V_4 , V_6 , V_9 ) ;
return V_5 ;
}
struct V_1 *
F_8 (
struct V_2 * V_3 ,
T_1 V_10 ,
int V_11 )
{
struct V_1 * V_5 ;
int V_12 ;
int V_6 ;
F_2 () ;
V_12 = F_9 ( & V_3 -> V_7 ,
( void * * ) & V_5 , V_10 , 1 , V_11 ) ;
if ( V_12 <= 0 ) {
F_6 () ;
return NULL ;
}
V_6 = F_5 ( & V_5 -> V_8 ) ;
F_6 () ;
F_10 ( V_3 , V_5 -> V_13 , V_6 , V_9 ) ;
return V_5 ;
}
void
F_11 (
struct V_1 * V_5 )
{
int V_6 ;
ASSERT ( F_4 ( & V_5 -> V_8 ) > 0 ) ;
V_6 = F_12 ( & V_5 -> V_8 ) ;
F_13 ( V_5 -> V_14 , V_5 -> V_13 , V_6 , V_9 ) ;
}
STATIC int
F_14 (
T_2 * V_3 ,
T_3 * V_15 ,
bool V_16 ,
bool V_17 )
{
if ( V_15 -> V_18 != V_19 ) {
F_15 ( V_3 , L_1 ) ;
return F_16 ( V_20 ) ;
}
if ( ! F_17 ( V_15 ) ) {
F_15 ( V_3 , L_2 ) ;
return F_16 ( V_20 ) ;
}
if ( V_17 && F_18 ( V_15 ) == V_21 ) {
F_19 ( V_3 ,
L_3
L_4 ) ;
if ( F_20 ( V_15 ,
V_22 ) ) {
F_15 ( V_3 ,
L_5
L_6 ,
( V_15 -> V_23 &
V_22 ) ) ;
}
if ( F_21 ( V_15 ,
V_24 ) ) {
F_19 ( V_3 ,
L_7 ,
( V_15 -> V_25 &
V_24 ) ) ;
if ( ! ( V_3 -> V_26 & V_27 ) ) {
F_15 ( V_3 ,
L_8
L_9 ) ;
return F_16 ( V_28 ) ;
}
}
if ( F_22 ( V_15 ,
V_29 ) ) {
F_15 ( V_3 ,
L_10
L_11 ,
( V_15 -> V_30 &
V_29 ) ) ;
return F_16 ( V_28 ) ;
}
}
if ( F_23 ( V_15 ) ) {
if ( V_15 -> V_31 & ( V_32 | V_33 ) ) {
F_24 ( V_3 ,
L_12 ) ;
return F_16 ( V_34 ) ;
}
} else if ( V_15 -> V_31 & ( V_35 | V_36 |
V_37 | V_38 ) ) {
F_24 ( V_3 ,
L_13 ) ;
return F_16 ( V_34 ) ;
}
if ( F_25 (
V_15 -> V_39 == 0 && V_3 -> V_40 == V_3 -> V_41 ) ) {
F_15 ( V_3 ,
L_14
L_15 ) ;
return F_16 ( V_28 ) ;
}
if ( F_25 (
V_15 -> V_39 != 0 && V_3 -> V_40 != V_3 -> V_41 ) ) {
F_15 ( V_3 ,
L_16
L_17 ) ;
return F_16 ( V_28 ) ;
}
if ( F_25 (
V_15 -> V_42 <= 0 ||
V_15 -> V_43 < V_44 ||
V_15 -> V_43 > V_45 ||
V_15 -> V_46 < V_47 ||
V_15 -> V_46 > V_48 ||
V_15 -> V_43 != ( 1 << V_15 -> V_46 ) ||
V_15 -> V_49 < V_50 ||
V_15 -> V_49 > V_51 ||
V_15 -> V_52 < V_53 ||
V_15 -> V_52 > V_54 ||
V_15 -> V_49 != ( 1 << V_15 -> V_52 ) ||
V_15 -> V_55 < V_56 ||
V_15 -> V_55 > V_57 ||
V_15 -> V_58 < V_59 ||
V_15 -> V_58 > V_60 ||
V_15 -> V_55 != ( 1 << V_15 -> V_58 ) ||
( V_15 -> V_52 - V_15 -> V_58 != V_15 -> V_61 ) ||
( V_15 -> V_62 * V_15 -> V_49 > V_63 ) ||
( V_15 -> V_62 * V_15 -> V_49 < V_64 ) ||
( V_15 -> V_65 > 100 ) ||
V_15 -> V_66 == 0 ||
V_15 -> V_66 > F_26 ( V_15 ) ||
V_15 -> V_66 < F_27 ( V_15 ) ) ) {
F_24 ( V_3 , L_18 ) ;
return F_16 ( V_34 ) ;
}
if ( F_25 ( V_15 -> V_49 > V_67 ) ) {
F_15 ( V_3 ,
L_19
L_20 ,
V_15 -> V_49 , V_67 ) ;
return F_16 ( V_68 ) ;
}
switch ( V_15 -> V_55 ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_15 ( V_3 , L_21 ,
V_15 -> V_55 ) ;
return F_16 ( V_68 ) ;
}
if ( F_28 ( V_15 , V_15 -> V_66 ) ||
F_28 ( V_15 , V_15 -> V_69 ) ) {
F_15 ( V_3 ,
L_22 ) ;
return F_16 ( V_70 ) ;
}
if ( V_16 && V_15 -> V_71 ) {
F_15 ( V_3 , L_23 ) ;
return F_16 ( V_34 ) ;
}
if ( F_25 ( ! F_29 ( V_15 ) ) ) {
F_15 ( V_3 , L_24 ) ;
return F_16 ( V_68 ) ;
}
return 0 ;
}
void
F_30 ( struct V_72 * V_15 )
{
if ( V_15 -> V_73 == 0 )
V_15 -> V_73 = V_74 ;
if ( V_15 -> V_75 == 0 )
V_15 -> V_75 = V_74 ;
if ( V_15 -> V_76 == 0 )
V_15 -> V_76 = V_74 ;
if ( F_23 ( V_15 ) )
return;
if ( V_15 -> V_31 & V_32 )
V_15 -> V_31 |= ( V_15 -> V_31 & V_77 ) ?
V_35 : V_36 ;
if ( V_15 -> V_31 & V_33 )
V_15 -> V_31 |= ( V_15 -> V_31 & V_77 ) ?
V_37 : V_38 ;
V_15 -> V_31 &= ~ ( V_32 | V_33 ) ;
if ( V_15 -> V_31 & V_77 ) {
V_15 -> V_76 = V_15 -> V_75 ;
V_15 -> V_75 = V_74 ;
}
}
void
F_31 (
struct V_72 * V_78 ,
T_4 * V_79 )
{
V_78 -> V_18 = F_32 ( V_79 -> V_18 ) ;
V_78 -> V_49 = F_32 ( V_79 -> V_49 ) ;
V_78 -> V_66 = F_33 ( V_79 -> V_66 ) ;
V_78 -> V_69 = F_33 ( V_79 -> V_69 ) ;
V_78 -> V_80 = F_33 ( V_79 -> V_80 ) ;
memcpy ( & V_78 -> V_81 , & V_79 -> V_81 , sizeof( V_78 -> V_81 ) ) ;
V_78 -> V_39 = F_33 ( V_79 -> V_39 ) ;
V_78 -> V_82 = F_33 ( V_79 -> V_82 ) ;
V_78 -> V_83 = F_33 ( V_79 -> V_83 ) ;
V_78 -> V_84 = F_33 ( V_79 -> V_84 ) ;
V_78 -> V_62 = F_32 ( V_79 -> V_62 ) ;
V_78 -> V_85 = F_32 ( V_79 -> V_85 ) ;
V_78 -> V_42 = F_32 ( V_79 -> V_42 ) ;
V_78 -> V_86 = F_32 ( V_79 -> V_86 ) ;
V_78 -> V_87 = F_32 ( V_79 -> V_87 ) ;
V_78 -> V_88 = F_34 ( V_79 -> V_88 ) ;
V_78 -> V_43 = F_34 ( V_79 -> V_43 ) ;
V_78 -> V_55 = F_34 ( V_79 -> V_55 ) ;
V_78 -> V_89 = F_34 ( V_79 -> V_89 ) ;
memcpy ( & V_78 -> V_90 , & V_79 -> V_90 , sizeof( V_78 -> V_90 ) ) ;
V_78 -> V_52 = V_79 -> V_52 ;
V_78 -> V_46 = V_79 -> V_46 ;
V_78 -> V_58 = V_79 -> V_58 ;
V_78 -> V_61 = V_79 -> V_61 ;
V_78 -> V_91 = V_79 -> V_91 ;
V_78 -> V_92 = V_79 -> V_92 ;
V_78 -> V_71 = V_79 -> V_71 ;
V_78 -> V_65 = V_79 -> V_65 ;
V_78 -> V_93 = F_33 ( V_79 -> V_93 ) ;
V_78 -> V_94 = F_33 ( V_79 -> V_94 ) ;
V_78 -> V_95 = F_33 ( V_79 -> V_95 ) ;
V_78 -> V_96 = F_33 ( V_79 -> V_96 ) ;
V_78 -> V_73 = F_33 ( V_79 -> V_73 ) ;
V_78 -> V_75 = F_33 ( V_79 -> V_75 ) ;
V_78 -> V_31 = F_34 ( V_79 -> V_31 ) ;
V_78 -> V_97 = V_79 -> V_97 ;
V_78 -> V_98 = V_79 -> V_98 ;
V_78 -> V_99 = F_32 ( V_79 -> V_99 ) ;
V_78 -> V_100 = F_32 ( V_79 -> V_100 ) ;
V_78 -> V_101 = F_32 ( V_79 -> V_101 ) ;
V_78 -> V_102 = V_79 -> V_102 ;
V_78 -> V_103 = V_79 -> V_103 ;
V_78 -> V_104 = F_34 ( V_79 -> V_104 ) ;
V_78 -> V_105 = F_32 ( V_79 -> V_105 ) ;
V_78 -> V_106 = F_32 ( V_79 -> V_106 ) ;
V_78 -> V_107 = F_32 ( V_79 -> V_107 ) ;
V_78 -> V_23 = F_32 ( V_79 -> V_23 ) ;
V_78 -> V_25 = F_32 ( V_79 -> V_25 ) ;
V_78 -> V_30 = F_32 ( V_79 -> V_30 ) ;
V_78 -> V_108 =
F_32 ( V_79 -> V_108 ) ;
V_78 -> V_109 = 0 ;
V_78 -> V_76 = F_33 ( V_79 -> V_76 ) ;
V_78 -> V_110 = F_33 ( V_79 -> V_110 ) ;
}
static inline void
F_35 (
T_4 * V_78 ,
T_3 * V_79 ,
T_5 * V_111 )
{
T_6 V_112 = V_79 -> V_31 ;
if ( F_23 ( V_79 ) )
return;
if ( * V_111 & V_113 ) {
V_112 &= ~ ( V_35 | V_37 |
V_36 | V_38 ) ;
if ( V_79 -> V_31 &
( V_35 | V_36 ) )
V_112 |= V_32 ;
if ( V_79 -> V_31 &
( V_37 | V_38 ) )
V_112 |= V_33 ;
V_78 -> V_31 = F_36 ( V_112 ) ;
* V_111 &= ~ V_113 ;
}
if ( ( * V_111 & V_114 ) &&
( V_79 -> V_31 & V_115 ) )
V_78 -> V_75 = F_37 ( V_79 -> V_75 ) ;
else if ( ( * V_111 & V_116 ) &&
( V_79 -> V_31 & V_77 ) )
V_78 -> V_75 = F_37 ( V_79 -> V_76 ) ;
* V_111 &= ~ ( V_116 | V_114 ) ;
}
void
F_38 (
T_4 * V_78 ,
T_3 * V_79 ,
T_5 V_111 )
{
T_7 V_117 = ( T_7 ) V_78 ;
T_7 V_118 = ( T_7 ) V_79 ;
T_8 V_119 ;
int V_10 ;
int V_120 ;
ASSERT ( V_111 ) ;
if ( ! V_111 )
return;
F_35 ( V_78 , V_79 , & V_111 ) ;
while ( V_111 ) {
V_119 = ( T_8 ) F_39 ( ( V_121 ) V_111 ) ;
V_10 = V_122 [ V_119 ] . V_123 ;
V_120 = V_122 [ V_119 + 1 ] . V_123 - V_10 ;
ASSERT ( V_122 [ V_119 ] . type == 0 || V_122 [ V_119 ] . type == 1 ) ;
if ( V_120 == 1 || V_122 [ V_119 ] . type == 1 ) {
memcpy ( V_117 + V_10 , V_118 + V_10 , V_120 ) ;
} else {
switch ( V_120 ) {
case 2 :
* ( V_124 * ) ( V_117 + V_10 ) =
F_36 ( * ( V_125 * ) ( V_118 + V_10 ) ) ;
break;
case 4 :
* ( V_126 * ) ( V_117 + V_10 ) =
F_40 ( * ( V_127 * ) ( V_118 + V_10 ) ) ;
break;
case 8 :
* ( V_128 * ) ( V_117 + V_10 ) =
F_37 ( * ( V_129 * ) ( V_118 + V_10 ) ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
V_111 &= ~ ( 1LL << V_119 ) ;
}
}
static int
F_41 (
struct V_130 * V_131 ,
bool V_17 )
{
struct V_2 * V_3 = V_131 -> V_132 -> V_133 ;
struct V_72 V_134 ;
F_31 ( & V_134 , F_42 ( V_131 ) ) ;
return F_14 ( V_3 , & V_134 , V_131 -> V_135 == V_136 ,
V_17 ) ;
}
static void
F_43 (
struct V_130 * V_131 )
{
struct V_2 * V_3 = V_131 -> V_132 -> V_133 ;
struct V_137 * V_138 = F_42 ( V_131 ) ;
int error ;
if ( V_138 -> V_18 == F_40 ( V_19 ) &&
( ( ( F_34 ( V_138 -> V_88 ) & V_139 ) ==
V_21 ) ||
V_138 -> V_140 != 0 ) ) {
if ( ! F_44 ( V_131 -> V_141 , F_45 ( V_131 -> V_142 ) ,
F_46 ( struct V_72 , V_140 ) ) ) {
if ( V_131 -> V_135 == V_136 ||
F_47 ( & V_3 -> V_143 ) ) {
error = V_34 ;
goto V_144;
}
}
}
error = F_41 ( V_131 , true ) ;
V_144:
if ( error ) {
if ( error == V_34 )
F_48 ( V_145 , V_146 ,
V_3 , V_131 -> V_141 ) ;
F_49 ( V_131 , error ) ;
}
}
static void
F_50 (
struct V_130 * V_131 )
{
struct V_137 * V_138 = F_42 ( V_131 ) ;
if ( V_138 -> V_18 == F_40 ( V_19 ) ) {
F_43 ( V_131 ) ;
return;
}
F_49 ( V_131 , V_20 ) ;
}
static void
F_51 (
struct V_130 * V_131 )
{
struct V_2 * V_3 = V_131 -> V_132 -> V_133 ;
struct V_147 * V_148 = V_131 -> V_149 ;
int error ;
error = F_41 ( V_131 , false ) ;
if ( error ) {
F_48 ( V_145 , V_146 ,
V_3 , V_131 -> V_141 ) ;
F_49 ( V_131 , error ) ;
return;
}
if ( ! F_47 ( & V_3 -> V_143 ) )
return;
if ( V_148 )
F_42 ( V_131 ) -> V_110 = F_37 ( V_148 -> V_150 . V_151 ) ;
F_52 ( V_131 -> V_141 , F_45 ( V_131 -> V_142 ) ,
F_46 ( struct V_72 , V_140 ) ) ;
}
void
F_53 (
struct V_2 * V_3 ,
struct V_72 * V_15 )
{
V_3 -> V_152 = V_3 -> V_153 = 0 ;
F_54 ( & V_3 -> V_154 ) ;
V_3 -> V_155 = V_3 -> V_143 . V_42 ;
V_3 -> V_156 = V_15 -> V_52 + V_157 ;
V_3 -> V_158 = V_15 -> V_52 - V_159 ;
V_3 -> V_160 = V_15 -> V_46 - V_159 ;
V_3 -> V_161 = F_55 ( V_15 -> V_42 - 1 ) + 1 ;
V_3 -> V_162 = V_15 -> V_61 + V_15 -> V_91 ;
V_3 -> V_163 = V_15 -> V_49 - 1 ;
V_3 -> V_164 = V_15 -> V_49 >> V_165 ;
V_3 -> V_166 = V_3 -> V_164 - 1 ;
V_3 -> V_167 [ 0 ] = F_56 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_167 [ 1 ] = F_56 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_168 [ 0 ] = V_3 -> V_167 [ 0 ] / 2 ;
V_3 -> V_168 [ 1 ] = V_3 -> V_167 [ 1 ] / 2 ;
V_3 -> V_169 [ 0 ] = F_57 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_169 [ 1 ] = F_57 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_170 [ 0 ] = V_3 -> V_169 [ 0 ] / 2 ;
V_3 -> V_170 [ 1 ] = V_3 -> V_169 [ 1 ] / 2 ;
V_3 -> V_171 [ 0 ] = F_58 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_171 [ 1 ] = F_58 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_172 [ 0 ] = V_3 -> V_171 [ 0 ] / 2 ;
V_3 -> V_172 [ 1 ] = V_3 -> V_171 [ 1 ] / 2 ;
V_3 -> V_173 = F_59 ( V_3 , 1 ) ;
V_3 -> V_174 = ( int ) F_60 ( ( T_6 ) V_175 ,
V_15 -> V_89 ) ;
V_3 -> V_176 = V_3 -> V_174 >> V_15 -> V_61 ;
}
int
F_61 (
struct V_2 * V_3 ,
T_1 V_177 )
{
T_1 V_178 ;
T_9 * V_5 ;
T_3 * V_15 = & V_3 -> V_143 ;
T_10 V_179 = 0 ;
T_10 V_180 = 0 ;
T_10 V_181 = 0 ;
T_10 V_182 = 0 ;
T_10 V_183 = 0 ;
int error ;
for ( V_178 = 0 ; V_178 < V_177 ; V_178 ++ ) {
error = F_62 ( V_3 , NULL , V_178 , 0 ) ;
if ( error )
return error ;
error = F_63 ( V_3 , NULL , V_178 ) ;
if ( error )
return error ;
V_5 = F_1 ( V_3 , V_178 ) ;
V_179 += V_5 -> V_184 ;
V_180 += V_5 -> V_185 ;
V_181 += V_5 -> V_186 ;
V_182 += V_5 -> V_187 ;
V_183 += V_5 -> V_188 ;
F_11 ( V_5 ) ;
}
F_64 ( & V_3 -> V_189 ) ;
V_15 -> V_94 = V_179 ;
V_15 -> V_93 = V_180 ;
V_15 -> V_95 = V_181 + V_182 + V_183 ;
F_65 ( & V_3 -> V_189 ) ;
F_66 ( V_3 ) ;
return 0 ;
}
void
F_67 ( T_11 * V_190 , T_5 V_111 )
{
T_12 * V_131 ;
int V_10 ;
int V_191 ;
T_2 * V_3 ;
T_8 V_119 ;
ASSERT ( V_111 ) ;
if ( ! V_111 )
return;
V_3 = V_190 -> V_192 ;
V_131 = F_68 ( V_190 , V_3 , 0 ) ;
V_10 = sizeof( T_3 ) ;
V_191 = 0 ;
F_38 ( F_42 ( V_131 ) , & V_3 -> V_143 , V_111 ) ;
V_119 = ( T_8 ) F_69 ( ( V_121 ) V_111 ) ;
ASSERT ( ( 1LL << V_119 ) & V_193 ) ;
V_191 = V_122 [ V_119 + 1 ] . V_123 - 1 ;
V_119 = ( T_8 ) F_39 ( ( V_121 ) V_111 ) ;
ASSERT ( ( 1LL << V_119 ) & V_193 ) ;
V_10 = V_122 [ V_119 ] . V_123 ;
F_70 ( V_190 , V_131 , V_194 ) ;
F_71 ( V_190 , V_131 , V_10 , V_191 ) ;
}
