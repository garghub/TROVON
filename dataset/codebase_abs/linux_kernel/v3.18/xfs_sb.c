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
return - V_20 ;
}
if ( ! F_16 ( V_15 ) ) {
F_15 ( V_3 , L_2 ) ;
return - V_20 ;
}
if ( V_17 && F_17 ( V_15 ) == V_21 ) {
if ( F_18 ( V_15 ,
V_22 ) ) {
F_15 ( V_3 ,
L_3
L_4 ,
( V_15 -> V_23 &
V_22 ) ) ;
}
if ( F_19 ( V_15 ,
V_24 ) ) {
F_20 ( V_3 ,
L_5 ,
( V_15 -> V_25 &
V_24 ) ) ;
if ( ! ( V_3 -> V_26 & V_27 ) ) {
F_15 ( V_3 ,
L_6
L_7 ) ;
return - V_28 ;
}
}
if ( F_21 ( V_15 ,
V_29 ) ) {
F_15 ( V_3 ,
L_8
L_9 ,
( V_15 -> V_30 &
V_29 ) ) ;
return - V_28 ;
}
}
if ( F_22 ( V_15 ) ) {
if ( V_15 -> V_31 & ( V_32 | V_33 ) ) {
F_23 ( V_3 ,
L_10 ) ;
return - V_34 ;
}
} else if ( V_15 -> V_31 & ( V_35 | V_36 |
V_37 | V_38 ) ) {
F_23 ( V_3 ,
L_11 ) ;
return - V_34 ;
}
if ( F_24 (
V_15 -> V_39 == 0 && V_3 -> V_40 == V_3 -> V_41 ) ) {
F_15 ( V_3 ,
L_12
L_13 ) ;
return - V_28 ;
}
if ( F_24 (
V_15 -> V_39 != 0 && V_3 -> V_40 != V_3 -> V_41 ) ) {
F_15 ( V_3 ,
L_14
L_15 ) ;
return - V_28 ;
}
if ( F_24 (
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
V_15 -> V_55 > V_54 ||
V_15 -> V_56 < V_57 ||
V_15 -> V_56 > V_58 ||
V_15 -> V_59 < V_60 ||
V_15 -> V_59 > V_61 ||
V_15 -> V_56 != ( 1 << V_15 -> V_59 ) ||
V_15 -> V_62 > V_63 ||
V_15 -> V_64 != F_25 ( V_15 -> V_49 , V_15 -> V_56 ) ||
( V_15 -> V_52 - V_15 -> V_59 != V_15 -> V_65 ) ||
( V_15 -> V_66 * V_15 -> V_49 > V_67 ) ||
( V_15 -> V_66 * V_15 -> V_49 < V_68 ) ||
( V_15 -> V_69 > 100 ) ||
V_15 -> V_70 == 0 ||
V_15 -> V_70 > F_26 ( V_15 ) ||
V_15 -> V_70 < F_27 ( V_15 ) ||
V_15 -> V_71 != 0 ) ) {
F_23 ( V_3 , L_16 ) ;
return - V_34 ;
}
if ( F_24 ( V_15 -> V_49 > V_72 ) ) {
F_15 ( V_3 ,
L_17
L_18 ,
V_15 -> V_49 , V_72 ) ;
return - V_73 ;
}
switch ( V_15 -> V_56 ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_15 ( V_3 , L_19 ,
V_15 -> V_56 ) ;
return - V_73 ;
}
if ( F_28 ( V_15 , V_15 -> V_70 ) ||
F_28 ( V_15 , V_15 -> V_74 ) ) {
F_15 ( V_3 ,
L_20 ) ;
return - V_75 ;
}
if ( V_16 && V_15 -> V_76 ) {
F_15 ( V_3 , L_21 ) ;
return - V_34 ;
}
return 0 ;
}
void
F_29 ( struct V_77 * V_15 )
{
if ( V_15 -> V_78 == 0 )
V_15 -> V_78 = V_79 ;
if ( V_15 -> V_80 == 0 )
V_15 -> V_80 = V_79 ;
if ( V_15 -> V_81 == 0 )
V_15 -> V_81 = V_79 ;
if ( F_22 ( V_15 ) )
return;
if ( V_15 -> V_31 & V_32 )
V_15 -> V_31 |= ( V_15 -> V_31 & V_82 ) ?
V_35 : V_36 ;
if ( V_15 -> V_31 & V_33 )
V_15 -> V_31 |= ( V_15 -> V_31 & V_82 ) ?
V_37 : V_38 ;
V_15 -> V_31 &= ~ ( V_32 | V_33 ) ;
if ( V_15 -> V_31 & V_82 ) {
V_15 -> V_81 = V_15 -> V_80 ;
V_15 -> V_80 = V_79 ;
}
}
static void
F_30 (
struct V_77 * V_83 ,
T_4 * V_84 ,
bool V_85 )
{
V_83 -> V_18 = F_31 ( V_84 -> V_18 ) ;
V_83 -> V_49 = F_31 ( V_84 -> V_49 ) ;
V_83 -> V_70 = F_32 ( V_84 -> V_70 ) ;
V_83 -> V_74 = F_32 ( V_84 -> V_74 ) ;
V_83 -> V_86 = F_32 ( V_84 -> V_86 ) ;
memcpy ( & V_83 -> V_87 , & V_84 -> V_87 , sizeof( V_83 -> V_87 ) ) ;
V_83 -> V_39 = F_32 ( V_84 -> V_39 ) ;
V_83 -> V_88 = F_32 ( V_84 -> V_88 ) ;
V_83 -> V_89 = F_32 ( V_84 -> V_89 ) ;
V_83 -> V_90 = F_32 ( V_84 -> V_90 ) ;
V_83 -> V_66 = F_31 ( V_84 -> V_66 ) ;
V_83 -> V_91 = F_31 ( V_84 -> V_91 ) ;
V_83 -> V_42 = F_31 ( V_84 -> V_42 ) ;
V_83 -> V_92 = F_31 ( V_84 -> V_92 ) ;
V_83 -> V_93 = F_31 ( V_84 -> V_93 ) ;
V_83 -> V_94 = F_33 ( V_84 -> V_94 ) ;
V_83 -> V_43 = F_33 ( V_84 -> V_43 ) ;
V_83 -> V_56 = F_33 ( V_84 -> V_56 ) ;
V_83 -> V_64 = F_33 ( V_84 -> V_64 ) ;
memcpy ( & V_83 -> V_95 , & V_84 -> V_95 , sizeof( V_83 -> V_95 ) ) ;
V_83 -> V_52 = V_84 -> V_52 ;
V_83 -> V_46 = V_84 -> V_46 ;
V_83 -> V_59 = V_84 -> V_59 ;
V_83 -> V_65 = V_84 -> V_65 ;
V_83 -> V_96 = V_84 -> V_96 ;
V_83 -> V_97 = V_84 -> V_97 ;
V_83 -> V_76 = V_84 -> V_76 ;
V_83 -> V_69 = V_84 -> V_69 ;
V_83 -> V_98 = F_32 ( V_84 -> V_98 ) ;
V_83 -> V_99 = F_32 ( V_84 -> V_99 ) ;
V_83 -> V_100 = F_32 ( V_84 -> V_100 ) ;
V_83 -> V_101 = F_32 ( V_84 -> V_101 ) ;
V_83 -> V_78 = F_32 ( V_84 -> V_78 ) ;
V_83 -> V_80 = F_32 ( V_84 -> V_80 ) ;
V_83 -> V_31 = F_33 ( V_84 -> V_31 ) ;
V_83 -> V_102 = V_84 -> V_102 ;
V_83 -> V_71 = V_84 -> V_71 ;
V_83 -> V_103 = F_31 ( V_84 -> V_103 ) ;
V_83 -> V_104 = F_31 ( V_84 -> V_104 ) ;
V_83 -> V_105 = F_31 ( V_84 -> V_105 ) ;
V_83 -> V_55 = V_84 -> V_55 ;
V_83 -> V_106 = V_84 -> V_106 ;
V_83 -> V_107 = F_33 ( V_84 -> V_107 ) ;
V_83 -> V_62 = F_31 ( V_84 -> V_62 ) ;
V_83 -> V_108 = F_31 ( V_84 -> V_108 ) ;
V_83 -> V_109 = F_31 ( V_84 -> V_109 ) ;
V_83 -> V_23 = F_31 ( V_84 -> V_23 ) ;
V_83 -> V_25 = F_31 ( V_84 -> V_25 ) ;
V_83 -> V_30 = F_31 ( V_84 -> V_30 ) ;
V_83 -> V_110 =
F_31 ( V_84 -> V_110 ) ;
V_83 -> V_111 = 0 ;
V_83 -> V_112 = 0 ;
V_83 -> V_81 = F_32 ( V_84 -> V_81 ) ;
V_83 -> V_113 = F_32 ( V_84 -> V_113 ) ;
if ( V_85 )
F_29 ( V_83 ) ;
}
void
F_34 (
struct V_77 * V_83 ,
T_4 * V_84 )
{
F_30 ( V_83 , V_84 , true ) ;
}
static inline void
F_35 (
T_4 * V_83 ,
T_3 * V_84 ,
T_5 * V_114 )
{
T_6 V_115 = V_84 -> V_31 ;
if ( F_22 ( V_84 ) )
return;
if ( * V_114 & V_116 ) {
V_115 &= ~ ( V_35 | V_37 |
V_36 | V_38 ) ;
if ( V_84 -> V_31 &
( V_35 | V_36 ) )
V_115 |= V_32 ;
if ( V_84 -> V_31 &
( V_37 | V_38 ) )
V_115 |= V_33 ;
V_83 -> V_31 = F_36 ( V_115 ) ;
* V_114 &= ~ V_116 ;
}
if ( ( * V_114 & V_117 ) &&
( V_84 -> V_31 & V_118 ) )
V_83 -> V_80 = F_37 ( V_84 -> V_80 ) ;
else if ( ( * V_114 & V_119 ) &&
( V_84 -> V_31 & V_82 ) )
V_83 -> V_80 = F_37 ( V_84 -> V_81 ) ;
else {
if ( V_84 -> V_80 == V_79 &&
V_84 -> V_81 == V_79 )
V_83 -> V_80 = F_37 ( V_79 ) ;
}
* V_114 &= ~ ( V_119 | V_117 ) ;
}
void
F_38 (
T_4 * V_83 ,
T_3 * V_84 ,
T_5 V_114 )
{
T_7 V_120 = ( T_7 ) V_83 ;
T_7 V_121 = ( T_7 ) V_84 ;
T_8 V_122 ;
int V_10 ;
int V_123 ;
ASSERT ( V_114 ) ;
if ( ! V_114 )
return;
V_114 &= ~ V_124 ;
F_35 ( V_83 , V_84 , & V_114 ) ;
while ( V_114 ) {
V_122 = ( T_8 ) F_39 ( ( V_125 ) V_114 ) ;
V_10 = V_126 [ V_122 ] . V_127 ;
V_123 = V_126 [ V_122 + 1 ] . V_127 - V_10 ;
ASSERT ( V_126 [ V_122 ] . type == 0 || V_126 [ V_122 ] . type == 1 ) ;
if ( V_123 == 1 || V_126 [ V_122 ] . type == 1 ) {
memcpy ( V_120 + V_10 , V_121 + V_10 , V_123 ) ;
} else {
switch ( V_123 ) {
case 2 :
* ( V_128 * ) ( V_120 + V_10 ) =
F_36 ( * ( V_129 * ) ( V_121 + V_10 ) ) ;
break;
case 4 :
* ( V_130 * ) ( V_120 + V_10 ) =
F_40 ( * ( V_131 * ) ( V_121 + V_10 ) ) ;
break;
case 8 :
* ( V_132 * ) ( V_120 + V_10 ) =
F_37 ( * ( V_133 * ) ( V_121 + V_10 ) ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
V_114 &= ~ ( 1LL << V_122 ) ;
}
}
static int
F_41 (
struct V_134 * V_135 ,
bool V_17 )
{
struct V_2 * V_3 = V_135 -> V_136 -> V_137 ;
struct V_77 V_138 ;
F_30 ( & V_138 , F_42 ( V_135 ) , false ) ;
return F_14 ( V_3 , & V_138 , V_135 -> V_139 == V_140 ,
V_17 ) ;
}
static void
F_43 (
struct V_134 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_136 -> V_137 ;
struct V_141 * V_142 = F_42 ( V_135 ) ;
int error ;
if ( V_142 -> V_18 == F_40 ( V_19 ) &&
( ( ( F_33 ( V_142 -> V_94 ) & V_143 ) ==
V_21 ) ||
V_142 -> V_111 != 0 ) ) {
if ( ! F_44 ( V_135 , V_144 ) ) {
if ( V_135 -> V_139 == V_140 ||
F_45 ( & V_3 -> V_145 ) ) {
error = - V_146 ;
goto V_147;
}
}
}
error = F_41 ( V_135 , true ) ;
V_147:
if ( error ) {
F_46 ( V_135 , error ) ;
if ( error == - V_34 || error == - V_146 )
F_47 ( V_135 ) ;
}
}
static void
F_48 (
struct V_134 * V_135 )
{
struct V_141 * V_142 = F_42 ( V_135 ) ;
if ( V_142 -> V_18 == F_40 ( V_19 ) ) {
F_43 ( V_135 ) ;
return;
}
F_46 ( V_135 , - V_20 ) ;
}
static void
F_49 (
struct V_134 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_136 -> V_137 ;
struct V_148 * V_149 = V_135 -> V_150 ;
int error ;
error = F_41 ( V_135 , false ) ;
if ( error ) {
F_46 ( V_135 , error ) ;
F_47 ( V_135 ) ;
return;
}
if ( ! F_45 ( & V_3 -> V_145 ) )
return;
if ( V_149 )
F_42 ( V_135 ) -> V_113 = F_37 ( V_149 -> V_151 . V_152 ) ;
F_50 ( V_135 , V_144 ) ;
}
void
F_51 (
struct V_2 * V_3 ,
struct V_77 * V_15 )
{
V_3 -> V_153 = V_3 -> V_154 = 0 ;
F_52 ( & V_3 -> V_155 ) ;
V_3 -> V_156 = V_3 -> V_145 . V_42 ;
V_3 -> V_157 = V_15 -> V_52 + V_158 ;
V_3 -> V_159 = V_15 -> V_52 - V_160 ;
V_3 -> V_161 = V_15 -> V_46 - V_160 ;
V_3 -> V_162 = F_53 ( V_15 -> V_42 - 1 ) + 1 ;
V_3 -> V_163 = V_15 -> V_65 + V_15 -> V_96 ;
V_3 -> V_164 = V_15 -> V_49 - 1 ;
V_3 -> V_165 = V_15 -> V_49 >> V_166 ;
V_3 -> V_167 = V_3 -> V_165 - 1 ;
V_3 -> V_168 [ 0 ] = F_54 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_168 [ 1 ] = F_54 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_169 [ 0 ] = V_3 -> V_168 [ 0 ] / 2 ;
V_3 -> V_169 [ 1 ] = V_3 -> V_168 [ 1 ] / 2 ;
V_3 -> V_170 [ 0 ] = F_55 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_170 [ 1 ] = F_55 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_171 [ 0 ] = V_3 -> V_170 [ 0 ] / 2 ;
V_3 -> V_171 [ 1 ] = V_3 -> V_170 [ 1 ] / 2 ;
V_3 -> V_172 [ 0 ] = F_56 ( V_3 , V_15 -> V_49 , 1 ) ;
V_3 -> V_172 [ 1 ] = F_56 ( V_3 , V_15 -> V_49 , 0 ) ;
V_3 -> V_173 [ 0 ] = V_3 -> V_172 [ 0 ] / 2 ;
V_3 -> V_173 [ 1 ] = V_3 -> V_172 [ 1 ] / 2 ;
V_3 -> V_174 = F_57 ( V_3 , 1 ) ;
V_3 -> V_175 = ( int ) F_58 ( ( T_6 ) V_176 ,
V_15 -> V_64 ) ;
V_3 -> V_177 = V_3 -> V_175 >> V_15 -> V_65 ;
}
int
F_59 (
struct V_2 * V_3 ,
T_1 V_178 )
{
T_1 V_179 ;
T_9 * V_5 ;
T_3 * V_15 = & V_3 -> V_145 ;
T_10 V_180 = 0 ;
T_10 V_181 = 0 ;
T_10 V_182 = 0 ;
T_10 V_183 = 0 ;
T_10 V_184 = 0 ;
int error ;
for ( V_179 = 0 ; V_179 < V_178 ; V_179 ++ ) {
error = F_60 ( V_3 , NULL , V_179 , 0 ) ;
if ( error )
return error ;
error = F_61 ( V_3 , NULL , V_179 ) ;
if ( error )
return error ;
V_5 = F_1 ( V_3 , V_179 ) ;
V_180 += V_5 -> V_185 ;
V_181 += V_5 -> V_186 ;
V_182 += V_5 -> V_187 ;
V_183 += V_5 -> V_188 ;
V_184 += V_5 -> V_189 ;
F_11 ( V_5 ) ;
}
F_62 ( & V_3 -> V_190 ) ;
V_15 -> V_99 = V_180 ;
V_15 -> V_98 = V_181 ;
V_15 -> V_100 = V_182 + V_183 + V_184 ;
F_63 ( & V_3 -> V_190 ) ;
F_64 ( V_3 ) ;
return 0 ;
}
void
F_65 ( T_11 * V_191 , T_5 V_114 )
{
T_12 * V_135 ;
int V_10 ;
int V_192 ;
T_2 * V_3 ;
T_8 V_122 ;
ASSERT ( V_114 ) ;
if ( ! V_114 )
return;
V_3 = V_191 -> V_193 ;
V_135 = F_66 ( V_191 , V_3 , 0 ) ;
V_10 = sizeof( T_3 ) ;
V_192 = 0 ;
F_38 ( F_42 ( V_135 ) , & V_3 -> V_145 , V_114 ) ;
V_122 = ( T_8 ) F_67 ( ( V_125 ) V_114 ) ;
ASSERT ( ( 1LL << V_122 ) & V_194 ) ;
V_192 = V_126 [ V_122 + 1 ] . V_127 - 1 ;
V_122 = ( T_8 ) F_39 ( ( V_125 ) V_114 ) ;
ASSERT ( ( 1LL << V_122 ) & V_194 ) ;
V_10 = V_126 [ V_122 ] . V_127 ;
F_68 ( V_191 , V_135 , V_195 ) ;
F_69 ( V_191 , V_135 , V_10 , V_192 ) ;
}
