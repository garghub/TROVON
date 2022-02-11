static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
if ( V_5 -> V_8 -> V_9 )
return ( (struct V_10 * ) V_3 -> V_7 ) -> V_11 ;
else
return (struct V_1 * ) V_3 -> V_7 ;
}
static void
F_2 ( struct V_12 * V_8 , struct V_13 * V_14 )
{
void * V_15 , * V_16 ;
struct V_17 * V_18 = F_3 ( V_14 ) ;
if ( ! V_19 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_1 ,
V_22 ) ;
return;
}
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_2 ) ;
return;
}
V_16 = ( void * ) V_19 ;
while ( V_18 ) {
V_15 = F_5 ( V_18 ) ;
memcpy ( V_16 , V_15 , V_18 -> V_23 ) ;
V_16 += V_18 -> V_23 ;
V_18 = F_6 ( V_18 ) ;
}
}
static void
F_7 ( struct V_12 * V_8 , struct V_13 * V_14 )
{
void * V_15 , * V_16 ;
struct V_17 * V_18 = F_8 ( V_14 ) ;
if ( ! V_24 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_3 ,
V_22 ) ;
return;
}
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_4 ) ;
return;
}
V_16 = V_24 ;
while ( V_18 ) {
V_15 = F_5 ( V_18 ) ;
memcpy ( V_16 , V_15 , V_18 -> V_23 ) ;
V_16 += V_18 -> V_23 ;
V_18 = F_6 ( V_18 ) ;
}
}
static inline unsigned
F_9 ( struct V_13 * V_25 )
{
return V_25 -> V_26 -> V_27 ;
}
static inline unsigned
F_10 ( struct V_13 * V_25 , int V_28 )
{
return 1 ;
}
static inline unsigned
F_11 ( struct V_13 * V_25 )
{
if ( F_12 ( NULL , V_25 ) == V_29 )
return 0 ;
if ( F_13 ( V_25 -> V_26 -> V_6 ) == V_30 )
return 1 ;
return 0 ;
}
static void
F_14 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
if ( V_34 ) {
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
}
}
static void
F_18 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_13 * V_41 = V_32 -> V_42 ;
unsigned long V_43 ;
struct V_44 * V_45 = V_41 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
unsigned long V_46 ;
int V_47 ;
if ( V_41 -> V_48 )
return;
V_46 = F_19 ( ( long ) V_49 - ( long ) V_32 -> V_50 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( ! V_5 -> V_52 ||
V_5 -> V_53 ||
! V_40 ||
! V_40 -> V_54 ||
( V_8 -> V_55 == V_56 ) ) {
F_21 ( V_45 -> V_51 , V_43 ) ;
return;
}
if ( V_8 -> V_55 == V_57 ) {
V_47 = ( V_46 + V_8 -> V_58 - 1 - V_8 -> V_59 ) /
V_8 -> V_58 ;
if ( V_47 < 0 )
V_47 = 0 ;
else if ( V_47 >= V_60 )
V_47 = V_60 - 1 ;
} else {
for ( V_47 = 0 ; V_47 < V_60 - 1 ; V_47 ++ )
if ( V_46 <= ( V_8 -> V_59 +
( ( 1 << V_47 ) * V_8 -> V_58 ) ) )
break;
}
V_40 -> V_54 [ V_47 ] . V_61 ++ ;
F_21 ( V_45 -> V_51 , V_43 ) ;
}
static void
F_22 ( struct V_12 * V_8 ,
struct V_4 * V_5 ,
struct V_39 * V_62 ,
T_1 V_63 ,
T_2 V_64 ,
T_2 V_65 )
{
struct V_66 * V_67 ;
unsigned long V_43 ;
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_69 . V_70 . V_71 =
V_72 ;
V_67 -> V_68 . V_69 . V_70 . V_73 =
V_74 ;
V_67 -> V_68 . V_69 . V_70 . V_63 = V_63 ;
if ( V_62 && F_24 ( V_62 ) ) {
memcpy ( & V_67 -> V_68 . V_69 . V_70 . V_75 ,
& V_62 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_69 . V_70 . V_78 ,
& V_62 -> V_79 , sizeof( struct V_77 ) ) ;
}
V_67 -> V_68 . V_69 . V_80 = V_64 ;
V_67 -> V_68 . V_69 . V_81 = V_65 ;
V_67 -> V_5 = V_5 ;
V_67 -> V_82 . V_83 = V_84 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
F_25 ( & V_67 -> V_82 . V_86 , & V_8 -> V_87 ) ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_26 ( V_8 ) ;
return;
}
static int
F_27 ( struct V_2 * V_3 , int V_88 , int V_89 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_1 * V_38 ;
unsigned long V_90 , V_91 ;
V_91 = V_3 -> V_92 ;
switch ( V_89 ) {
case V_93 :
case V_94 :
F_28 ( V_3 , F_29 ( V_3 ) , V_88 ) ;
break;
case V_95 :
if ( F_30 ( V_3 , V_88 ) == 0 )
return V_3 -> V_92 ;
F_31 ( V_5 , V_96 , V_97 ,
L_5
L_6 , V_3 -> V_92 ) ;
break;
default:
return - V_98 ;
}
V_90 = V_3 -> V_92 ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 )
F_22 ( V_8 , V_5 ,
V_38 -> V_40 , V_3 -> V_63 ,
V_91 ,
V_90 ) ;
return V_3 -> V_92 ;
}
static int
F_32 ( struct V_2 * V_3 , int V_99 )
{
if ( V_3 -> V_100 ) {
F_33 ( V_3 , V_99 ) ;
if ( V_99 )
F_34 ( V_3 , V_3 -> V_92 ) ;
else
F_35 ( V_3 , V_3 -> V_92 ) ;
} else
V_99 = 0 ;
return V_99 ;
}
void
F_36 ( struct V_12 * V_8 )
{
unsigned long V_43 ;
T_2 V_101 ;
unsigned long V_102 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
F_37 ( & V_8 -> V_103 ) ;
V_8 -> V_104 = V_49 ;
V_102 = V_8 -> V_105 + V_106 ;
if ( F_38 ( V_102 , V_49 ) ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
return;
}
V_8 -> V_105 = V_49 ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( & V_8 -> V_107 -> V_108 , V_43 ) ;
V_101 = V_8 -> V_107 -> V_109 & V_110 ;
if ( ! V_101 )
V_8 -> V_107 -> V_109 |= V_110 ;
F_21 ( & V_8 -> V_107 -> V_108 , V_43 ) ;
if ( ! V_101 )
F_26 ( V_8 ) ;
return;
}
void
F_39 ( struct V_12 * V_8 )
{
struct V_4 * * V_111 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
unsigned long V_90 ;
unsigned long V_103 , V_112 ;
int V_47 ;
V_103 = F_40 ( & V_8 -> V_103 ) ;
V_112 = F_40 ( & V_8 -> V_112 ) ;
if ( V_103 == 0 )
return;
V_111 = F_41 ( V_8 ) ;
if ( V_111 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_113 && V_111 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_42 ( V_111 [ V_47 ] ) ;
F_43 (sdev, shost) {
V_90 =
V_3 -> V_92 * V_103 /
( V_103 + V_112 ) ;
if ( ! V_90 )
V_90 = V_3 -> V_92 - 1 ;
else
V_90 = V_3 -> V_92 -
V_90 ;
F_27 ( V_3 , V_90 ,
V_93 ) ;
}
}
F_44 ( V_8 , V_111 ) ;
F_45 ( & V_8 -> V_103 , 0 ) ;
F_45 ( & V_8 -> V_112 , 0 ) ;
}
void
F_46 ( struct V_12 * V_8 )
{
struct V_4 * * V_111 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
struct V_114 * V_115 ;
int V_47 ;
V_111 = F_41 ( V_8 ) ;
if ( V_111 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_113 && V_111 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_42 ( V_111 [ V_47 ] ) ;
F_43 (sdev, shost) {
V_115 = F_47 ( F_48 ( V_3 ) ) ;
F_49 ( V_115 ) ;
}
}
F_44 ( V_8 , V_111 ) ;
}
static int
F_50 ( struct V_4 * V_5 , int V_116 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_117 ;
struct V_118 * V_119 ;
T_3 * V_120 ;
T_4 V_121 ;
T_4 V_122 ;
T_4 V_123 ;
T_5 V_124 ;
int V_125 , V_126 ;
V_126 = V_8 -> V_127 -
( sizeof( struct V_128 ) + sizeof( struct V_129 ) ) ;
F_31 ( V_5 , V_130 , V_97 ,
L_7 ,
V_116 , V_8 -> V_127 ,
( int ) sizeof( struct V_128 ) ,
( int ) sizeof( struct V_129 ) , V_126 ) ;
for ( V_125 = 0 ; V_125 < V_116 ; V_125 ++ ) {
V_117 = F_51 ( sizeof( struct V_31 ) , V_131 ) ;
if ( ! V_117 )
break;
V_117 -> V_132 = F_52 ( V_8 -> V_133 ,
V_131 , & V_117 -> V_134 ) ;
if ( ! V_117 -> V_132 ) {
F_53 ( V_117 ) ;
break;
}
memset ( V_117 -> V_132 , 0 , V_8 -> V_127 ) ;
V_124 = F_54 ( V_8 , & V_117 -> V_135 ) ;
if ( V_124 == 0 ) {
F_55 ( V_8 -> V_133 ,
V_117 -> V_132 , V_117 -> V_134 ) ;
F_53 ( V_117 ) ;
break;
}
V_117 -> V_135 . V_136 |= V_137 ;
V_117 -> V_128 = V_117 -> V_132 ;
V_117 -> V_129 = V_117 -> V_132 + sizeof( struct V_128 ) ;
V_117 -> V_35 = V_117 -> V_132 + sizeof( struct V_128 ) +
sizeof( struct V_129 ) ;
V_119 = V_117 -> V_35 ;
V_121 = V_117 -> V_134 ;
V_122 = V_117 -> V_134 + sizeof( struct V_128 ) ;
V_123 = V_117 -> V_134 + sizeof( struct V_128 ) +
sizeof( struct V_129 ) ;
V_119 [ 0 ] . V_138 = F_15 ( F_56 ( V_121 ) ) ;
V_119 [ 0 ] . V_139 = F_15 ( F_57 ( V_121 ) ) ;
V_119 [ 0 ] . V_140 . V_141 . V_142 = sizeof( struct V_128 ) ;
V_119 [ 0 ] . V_140 . V_141 . V_143 = V_144 ;
V_119 [ 0 ] . V_140 . V_145 = F_15 ( V_119 [ 0 ] . V_140 . V_145 ) ;
V_119 [ 1 ] . V_138 = F_15 ( F_56 ( V_122 ) ) ;
V_119 [ 1 ] . V_139 = F_15 ( F_57 ( V_122 ) ) ;
V_119 [ 1 ] . V_140 . V_141 . V_142 = sizeof( struct V_129 ) ;
V_119 [ 1 ] . V_140 . V_141 . V_143 = V_144 ;
V_119 [ 1 ] . V_140 . V_145 = F_15 ( V_119 [ 1 ] . V_140 . V_145 ) ;
V_120 = & V_117 -> V_135 . V_120 ;
V_120 -> V_68 . V_146 . V_147 . V_148 = 0 ;
if ( ( V_8 -> V_149 == 3 ) &&
! ( V_8 -> V_150 & V_151 ) ) {
V_120 -> V_68 . V_146 . V_147 . V_143 = V_152 ;
V_120 -> V_68 . V_146 . V_147 . V_142 = sizeof( struct V_128 ) ;
V_120 -> V_68 . V_146 . V_147 . V_139 = F_58 ( T_3 ,
V_153 . V_154 . V_155 ) ;
V_120 -> V_68 . V_146 . V_147 . V_138 = 0 ;
V_120 -> V_156 = 0 ;
V_120 -> V_157 = 0 ;
V_120 -> V_153 . V_154 . V_158 . V_140 . V_141 . V_143 =
V_144 ;
V_120 -> V_153 . V_154 . V_158 . V_140 . V_141 . V_142 =
sizeof( struct V_129 ) ;
V_120 -> V_153 . V_154 . V_158 . V_139 =
F_57 ( V_122 ) ;
V_120 -> V_153 . V_154 . V_158 . V_138 =
F_56 ( V_122 ) ;
} else {
V_120 -> V_68 . V_146 . V_147 . V_143 = V_159 ;
V_120 -> V_68 . V_146 . V_147 . V_142 =
( 2 * sizeof( struct V_118 ) ) ;
V_120 -> V_68 . V_146 . V_147 . V_139 =
F_57 ( V_123 ) ;
V_120 -> V_68 . V_146 . V_147 . V_138 =
F_56 ( V_123 ) ;
V_120 -> V_156 = 1 ;
V_120 -> V_157 = 1 ;
}
V_120 -> V_160 = V_161 ;
V_117 -> V_162 = V_163 ;
V_117 -> V_135 . V_164 = V_117 ;
F_59 ( V_8 , V_117 ) ;
}
return V_125 ;
}
void
F_60 ( struct V_4 * V_5 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_117 , * V_165 ;
unsigned long V_166 = 0 ;
F_20 ( & V_8 -> V_85 , V_166 ) ;
F_61 ( & V_8 -> V_167 . V_168 ) ;
F_62 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_117 -> V_38 && V_117 -> V_38 -> V_40
&& V_117 -> V_38 -> V_40 -> V_5 == V_5 )
V_117 -> V_38 = NULL ;
}
F_63 ( & V_8 -> V_167 . V_168 ) ;
F_21 ( & V_8 -> V_85 , V_166 ) ;
}
void
F_64 ( struct V_12 * V_8 ,
struct V_169 * V_170 )
{
T_5 V_171 = F_65 ( V_172 , V_170 ) ;
T_5 V_173 = F_65 ( V_174 , V_170 ) ;
struct V_31 * V_117 , * V_165 ;
unsigned long V_166 = 0 ;
struct V_175 * V_176 ;
int V_47 ;
struct V_39 * V_62 ;
int V_177 = 0 ;
struct V_178 * V_179 = & V_8 -> V_180 . V_181 [ V_182 ] ;
F_20 ( & V_8 -> V_85 , V_166 ) ;
F_61 ( & V_8 -> V_167 . V_168 ) ;
F_62 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_117 -> V_135 . V_183 == V_171 ) {
F_66 ( & V_117 -> V_184 ) ;
V_117 -> V_185 = 0 ;
V_117 -> V_162 = V_163 ;
F_63 (
& V_8 -> V_167 . V_168 ) ;
if ( V_117 -> V_38 && V_117 -> V_38 -> V_40 )
V_62 = V_117 -> V_38 -> V_40 ;
else
V_62 = NULL ;
V_177 = F_67 ( & V_8 -> V_186 ) ;
F_21 ( & V_8 -> V_85 , V_166 ) ;
if ( V_62 ) {
F_68 ( V_8 , V_62 ,
V_117 -> V_135 . V_187 , V_173 , 1 ) ;
F_69 ( V_8 , V_62 , V_170 ) ;
}
F_70 ( V_8 , V_117 ) ;
if ( V_177 )
F_26 ( V_8 ) ;
return;
}
}
F_63 ( & V_8 -> V_167 . V_168 ) ;
for ( V_47 = 1 ; V_47 <= V_8 -> V_180 . V_188 ; V_47 ++ ) {
V_176 = V_8 -> V_180 . V_189 [ V_47 ] ;
if ( ! ( V_176 -> V_136 & V_137 ) ||
( V_176 -> V_136 & V_190 ) )
continue;
if ( V_176 -> V_183 != V_171 )
continue;
V_117 = F_71 ( V_176 , struct V_31 , V_135 ) ;
V_117 -> V_185 = 0 ;
F_21 ( & V_8 -> V_85 , V_166 ) ;
if ( ! F_67 ( & V_179 -> V_191 ) )
F_26 ( V_8 ) ;
return;
}
F_21 ( & V_8 -> V_85 , V_166 ) ;
}
static int
F_72 ( struct V_12 * V_8 ,
struct V_192 * V_193 , int V_194 )
{
struct V_31 * V_117 , * V_195 ;
int V_162 , V_196 ;
int V_197 = 0 , V_198 = 0 , V_199 = 0 , V_200 = 0 ;
T_4 V_201 ;
int V_202 = V_203 ;
F_73 ( V_204 ) ;
F_73 ( V_205 ) ;
F_73 ( V_206 ) ;
if ( V_194 <= 0 )
return - V_207 ;
V_196 = V_8 -> V_127 -
( sizeof( struct V_128 ) + sizeof( struct V_129 ) ) ;
F_62 (psb, psb_next, post_sblist, list) {
F_74 ( & V_117 -> V_184 ) ;
V_198 ++ ;
if ( ( V_202 != V_203 ) &&
( V_117 -> V_135 . V_183 != V_202 + 1 ) ) {
F_75 ( & V_204 , & V_205 ) ;
V_197 = V_198 - 1 ;
F_25 ( & V_117 -> V_184 , & V_204 ) ;
V_198 = 1 ;
} else {
F_25 ( & V_117 -> V_184 , & V_204 ) ;
if ( V_198 == V_208 ) {
F_75 ( & V_204 , & V_205 ) ;
V_197 = V_198 ;
V_198 = 0 ;
}
}
V_199 ++ ;
V_202 = V_117 -> V_135 . V_183 ;
if ( V_199 == V_194 ) {
if ( V_197 == 0 ) {
F_75 ( & V_204 , & V_205 ) ;
V_197 = V_198 ;
} else if ( V_198 == 1 ) {
if ( V_196 > V_209 )
V_201 = V_117 -> V_210 +
V_209 ;
else
V_201 = 0 ;
V_162 = F_76 ( V_8 ,
V_117 -> V_210 ,
V_201 ,
V_117 -> V_135 . V_183 ) ;
if ( V_162 ) {
V_117 -> V_185 = 1 ;
} else {
V_117 -> V_185 = 0 ;
V_117 -> V_162 = V_163 ;
V_200 ++ ;
}
F_25 ( & V_117 -> V_184 , & V_206 ) ;
}
}
if ( V_197 == 0 )
continue;
V_162 = F_77 ( V_8 , & V_205 ,
V_197 ) ;
if ( V_198 == 0 )
V_202 = V_203 ;
V_197 = 0 ;
while ( ! F_67 ( & V_205 ) ) {
F_78 ( & V_205 , V_117 ,
struct V_31 , V_184 ) ;
if ( V_162 ) {
V_117 -> V_185 = 1 ;
} else {
V_117 -> V_185 = 0 ;
V_117 -> V_162 = V_163 ;
V_200 ++ ;
}
F_25 ( & V_117 -> V_184 , & V_206 ) ;
}
}
while ( ! F_67 ( & V_206 ) ) {
F_78 ( & V_206 , V_117 ,
struct V_31 , V_184 ) ;
F_70 ( V_8 , V_117 ) ;
}
return V_200 ;
}
int
F_79 ( struct V_12 * V_8 )
{
F_73 ( V_193 ) ;
int V_200 , V_211 = 0 ;
F_80 ( & V_8 -> V_212 ) ;
F_61 ( & V_8 -> V_213 ) ;
F_75 ( & V_8 -> V_214 , & V_193 ) ;
F_81 ( & V_8 -> V_215 , & V_193 ) ;
F_63 ( & V_8 -> V_213 ) ;
F_82 ( & V_8 -> V_212 ) ;
if ( ! F_67 ( & V_193 ) ) {
V_200 = F_72 ( V_8 , & V_193 ,
V_8 -> V_167 . V_216 ) ;
if ( V_200 == 0 )
V_211 = - V_217 ;
}
return V_211 ;
}
static int
F_83 ( struct V_4 * V_5 , int V_116 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_117 ;
struct V_33 * V_34 ;
T_3 * V_120 ;
T_4 V_121 ;
T_4 V_122 ;
T_4 V_123 ;
T_5 V_124 , V_218 = 0 ;
int V_125 , V_200 , V_196 ;
F_73 ( V_204 ) ;
F_73 ( V_193 ) ;
F_73 ( V_206 ) ;
V_196 = V_8 -> V_127 -
( sizeof( struct V_128 ) + sizeof( struct V_129 ) ) ;
F_31 ( V_5 , V_130 , V_97 ,
L_8 ,
V_116 , V_8 -> V_127 , V_196 ,
( int ) sizeof( struct V_128 ) ,
( int ) sizeof( struct V_129 ) ) ;
for ( V_125 = 0 ; V_125 < V_116 ; V_125 ++ ) {
V_117 = F_51 ( sizeof( struct V_31 ) , V_131 ) ;
if ( ! V_117 )
break;
V_117 -> V_132 = F_52 ( V_8 -> V_133 ,
V_131 , & V_117 -> V_134 ) ;
if ( ! V_117 -> V_132 ) {
F_53 ( V_117 ) ;
break;
}
memset ( V_117 -> V_132 , 0 , V_8 -> V_127 ) ;
if ( V_8 -> V_219 && ( ( ( unsigned long ) ( V_117 -> V_132 ) &
( unsigned long ) ( V_220 - 1 ) ) != 0 ) ) {
F_55 ( V_8 -> V_133 ,
V_117 -> V_132 , V_117 -> V_134 ) ;
F_53 ( V_117 ) ;
break;
}
V_218 = F_84 ( V_8 ) ;
if ( V_218 == V_203 ) {
F_55 ( V_8 -> V_133 ,
V_117 -> V_132 , V_117 -> V_134 ) ;
F_53 ( V_117 ) ;
break;
}
V_124 = F_54 ( V_8 , & V_117 -> V_135 ) ;
if ( V_124 == 0 ) {
F_55 ( V_8 -> V_133 ,
V_117 -> V_132 , V_117 -> V_134 ) ;
F_53 ( V_117 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_9
L_10 , V_218 ) ;
F_85 ( V_8 , V_218 ) ;
break;
}
V_117 -> V_135 . V_187 = V_218 ;
V_117 -> V_135 . V_183 = V_8 -> V_167 . V_221 [ V_218 ] ;
V_117 -> V_135 . V_136 |= V_137 ;
V_117 -> V_35 = V_117 -> V_132 ;
V_117 -> V_128 = ( V_117 -> V_132 + V_196 ) ;
V_117 -> V_129 = (struct V_129 * ) ( ( V_222 * ) V_117 -> V_128 +
sizeof( struct V_128 ) ) ;
V_34 = (struct V_33 * ) V_117 -> V_35 ;
V_123 = V_117 -> V_134 ;
V_121 = ( V_117 -> V_134 + V_196 ) ;
V_122 = V_121 + sizeof( struct V_128 ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_121 ) ) ;
V_34 -> V_224 = F_17 ( F_57 ( V_121 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_225 = F_17 ( sizeof( struct V_128 ) ) ;
V_34 ++ ;
V_34 -> V_223 = F_17 ( F_56 ( V_122 ) ) ;
V_34 -> V_224 = F_17 ( F_57 ( V_122 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_225 = F_17 ( sizeof( struct V_129 ) ) ;
V_120 = & V_117 -> V_135 . V_120 ;
V_120 -> V_68 . V_146 . V_147 . V_148 = 0 ;
V_120 -> V_68 . V_146 . V_147 . V_143 = V_144 ;
V_120 -> V_68 . V_146 . V_147 . V_142 = sizeof( struct V_128 ) ;
V_120 -> V_68 . V_146 . V_147 . V_139 = F_57 ( V_121 ) ;
V_120 -> V_68 . V_146 . V_147 . V_138 = F_56 ( V_121 ) ;
V_120 -> V_156 = 1 ;
V_120 -> V_157 = 1 ;
V_120 -> V_160 = V_161 ;
V_117 -> V_135 . V_164 = V_117 ;
V_117 -> V_210 = V_123 ;
F_25 ( & V_117 -> V_184 , & V_193 ) ;
F_80 ( & V_8 -> V_212 ) ;
V_8 -> V_167 . V_216 ++ ;
F_82 ( & V_8 -> V_212 ) ;
}
F_4 ( V_8 , V_130 , V_21 ,
L_11
L_12 , V_125 , V_116 ) ;
if ( ! F_67 ( & V_193 ) )
V_200 = F_72 ( V_8 ,
& V_193 , V_125 ) ;
else
V_200 = 0 ;
return V_200 ;
}
static inline int
F_86 ( struct V_4 * V_5 , int V_116 )
{
return V_5 -> V_8 -> F_86 ( V_5 , V_116 ) ;
}
static struct V_31 *
F_87 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
struct V_31 * V_32 = NULL ;
struct V_192 * V_226 = & V_8 -> V_214 ;
unsigned long V_166 = 0 ;
F_20 ( & V_8 -> V_212 , V_166 ) ;
F_78 ( V_226 , V_32 , struct V_31 ,
V_184 ) ;
if ( ! V_32 ) {
F_61 ( & V_8 -> V_213 ) ;
F_81 ( & V_8 -> V_215 ,
& V_8 -> V_214 ) ;
F_88 ( & V_8 -> V_215 ) ;
F_78 ( V_226 , V_32 ,
struct V_31 , V_184 ) ;
F_63 ( & V_8 -> V_213 ) ;
}
F_21 ( & V_8 -> V_212 , V_166 ) ;
return V_32 ;
}
static struct V_31 *
F_89 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
struct V_31 * V_32 , * V_227 ;
unsigned long V_166 = 0 ;
int V_228 = 0 ;
F_20 ( & V_8 -> V_212 , V_166 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_90 ( V_8 , V_62 ,
V_32 -> V_135 . V_187 ) )
continue;
F_66 ( & V_32 -> V_184 ) ;
V_228 = 1 ;
break;
}
if ( ! V_228 ) {
F_61 ( & V_8 -> V_213 ) ;
F_81 ( & V_8 -> V_215 ,
& V_8 -> V_214 ) ;
F_88 ( & V_8 -> V_215 ) ;
F_63 ( & V_8 -> V_213 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_90 (
V_8 , V_62 , V_32 -> V_135 . V_187 ) )
continue;
F_66 ( & V_32 -> V_184 ) ;
V_228 = 1 ;
break;
}
}
F_21 ( & V_8 -> V_212 , V_166 ) ;
if ( ! V_228 )
return NULL ;
return V_32 ;
}
static struct V_31 *
F_91 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
return V_8 -> F_91 ( V_8 , V_62 ) ;
}
static void
F_59 ( struct V_12 * V_8 , struct V_31 * V_117 )
{
unsigned long V_166 = 0 ;
V_117 -> V_229 = 0 ;
V_117 -> V_230 = 0 ;
V_117 -> V_231 = 0 ;
F_20 ( & V_8 -> V_213 , V_166 ) ;
V_117 -> V_42 = NULL ;
V_117 -> V_135 . V_136 = V_137 ;
F_25 ( & V_117 -> V_184 , & V_8 -> V_215 ) ;
F_21 ( & V_8 -> V_213 , V_166 ) ;
}
static void
F_70 ( struct V_12 * V_8 , struct V_31 * V_117 )
{
unsigned long V_166 = 0 ;
V_117 -> V_229 = 0 ;
V_117 -> V_230 = 0 ;
V_117 -> V_231 = 0 ;
if ( V_117 -> V_185 ) {
F_20 ( & V_8 -> V_167 . V_168 ,
V_166 ) ;
V_117 -> V_42 = NULL ;
F_25 ( & V_117 -> V_184 ,
& V_8 -> V_167 . V_232 ) ;
F_21 ( & V_8 -> V_167 . V_168 ,
V_166 ) ;
} else {
V_117 -> V_42 = NULL ;
V_117 -> V_135 . V_136 = V_137 ;
F_20 ( & V_8 -> V_213 , V_166 ) ;
F_25 ( & V_117 -> V_184 , & V_8 -> V_215 ) ;
F_21 ( & V_8 -> V_213 , V_166 ) ;
}
}
static void
F_92 ( struct V_12 * V_8 , struct V_31 * V_117 )
{
V_8 -> F_92 ( V_8 , V_117 ) ;
}
static int
F_93 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_233 = NULL ;
struct V_128 * V_128 = V_32 -> V_128 ;
struct V_118 * V_119 = V_32 -> V_35 ;
struct V_175 * V_176 = & V_32 -> V_135 ;
T_3 * V_234 = & V_32 -> V_135 . V_120 ;
struct V_118 * V_235 = V_234 -> V_153 . V_154 . V_236 ;
T_4 V_237 ;
T_2 V_238 = 0 ;
int V_239 , V_240 = V_13 -> V_241 ;
V_119 += 2 ;
if ( F_94 ( V_13 ) ) {
V_239 = F_95 ( & V_8 -> V_242 -> V_243 , F_3 ( V_13 ) ,
F_94 ( V_13 ) , V_240 ) ;
if ( F_96 ( ! V_239 ) )
return 1 ;
V_32 -> V_229 = V_239 ;
if ( V_32 -> V_229 > V_8 -> V_244 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_13
L_14 ,
V_22 , V_8 -> V_244 ,
V_32 -> V_229 ) ;
V_32 -> V_229 = 0 ;
F_97 ( V_13 ) ;
return 1 ;
}
F_98 (scsi_cmnd, sgel, nseg, num_bde) {
V_237 = F_99 ( V_233 ) ;
if ( V_8 -> V_149 == 3 &&
! ( V_8 -> V_150 & V_151 ) &&
! ( V_176 -> V_136 & V_245 ) &&
V_239 <= V_246 ) {
V_235 -> V_140 . V_141 . V_143 = V_144 ;
V_235 -> V_140 . V_141 . V_142 = F_100 ( V_233 ) ;
V_235 -> V_139 = F_57 ( V_237 ) ;
V_235 -> V_138 = F_56 ( V_237 ) ;
V_235 ++ ;
} else {
V_119 -> V_140 . V_141 . V_143 = V_144 ;
V_119 -> V_140 . V_141 . V_142 = F_100 ( V_233 ) ;
V_119 -> V_140 . V_145 = F_15 ( V_119 -> V_140 . V_145 ) ;
V_119 -> V_139 =
F_15 ( F_57 ( V_237 ) ) ;
V_119 -> V_138 =
F_15 ( F_56 ( V_237 ) ) ;
V_119 ++ ;
}
}
}
if ( V_8 -> V_149 == 3 &&
! ( V_8 -> V_150 & V_151 ) &&
! ( V_176 -> V_136 & V_245 ) ) {
if ( V_238 > V_246 ) {
V_237 = V_32 -> V_134 ;
V_235 -> V_140 . V_141 . V_143 = V_159 ;
V_235 -> V_140 . V_141 . V_142 = ( V_238 *
sizeof( struct V_118 ) ) ;
V_237 += ( sizeof( struct V_128 ) +
sizeof( struct V_129 ) +
( 2 * sizeof( struct V_118 ) ) ) ;
V_235 -> V_138 = F_56 ( V_237 ) ;
V_235 -> V_139 = F_57 ( V_237 ) ;
V_234 -> V_153 . V_154 . V_247 = 2 ;
} else {
V_234 -> V_153 . V_154 . V_247 = ( V_238 + 1 ) ;
}
} else {
V_234 -> V_68 . V_146 . V_147 . V_142 =
( ( V_238 + 2 ) * sizeof( struct V_118 ) ) ;
V_234 -> V_153 . V_154 . V_247 = ( V_238 + 1 ) ;
}
V_128 -> V_248 = F_101 ( F_102 ( V_13 ) ) ;
V_234 -> V_68 . V_249 . V_250 = F_102 ( V_13 ) ;
return 0 ;
}
static int
F_103 ( struct V_12 * V_8 , struct V_13 * V_25 ,
T_2 * V_251 , T_5 * V_252 , T_2 V_253 )
{
struct V_17 * V_254 ;
struct V_17 * V_18 ;
struct V_31 * V_32 = NULL ;
struct V_255 * V_15 = NULL ;
struct V_39 * V_62 ;
struct V_1 * V_38 ;
T_2 V_256 = F_104 ( V_25 ) ;
T_2 V_257 ;
T_2 V_258 ;
T_6 V_259 ;
int V_211 = 0 ;
int V_260 = 0 ;
if ( V_256 == V_261 )
return 0 ;
V_254 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
V_259 = F_105 ( V_25 ) ;
if ( V_8 -> V_262 != V_263 ) {
V_257 = F_9 ( V_25 ) ;
V_258 = ( F_102 ( V_25 ) + V_257 - 1 ) / V_257 ;
if ( ( V_8 -> V_262 < V_259 ) ||
( V_8 -> V_262 >= ( V_259 + V_258 ) ) )
return 0 ;
if ( V_254 ) {
V_260 = V_8 -> V_262 - V_259 ;
V_258 = F_100 ( V_254 ) /
sizeof( struct V_255 ) ;
if ( V_258 < V_260 )
V_260 = V_258 ;
}
}
V_38 = F_1 ( V_25 -> V_26 ) ;
if ( V_38 && V_38 -> V_40 ) {
V_62 = V_38 -> V_40 ;
if ( V_8 -> V_264 &&
( V_8 -> V_264 != V_62 -> V_265 ) )
return 0 ;
if ( V_8 -> V_266 . V_267 . V_268 [ 0 ] &&
( memcmp ( & V_62 -> V_76 , & V_8 -> V_266 ,
sizeof( struct V_77 ) ) != 0 ) )
return 0 ;
}
if ( V_254 ) {
V_15 = (struct V_255 * ) F_5 ( V_254 ) ;
V_15 += V_260 ;
V_32 = (struct V_31 * ) V_25 -> V_269 ;
}
if ( V_251 ) {
if ( V_8 -> V_270 ) {
switch ( V_256 ) {
case V_271 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_15
L_16 ,
( unsigned long ) V_259 , V_260 ,
F_106 ( V_15 -> V_272 ) ) ;
if ( V_32 ) {
V_32 -> V_273 =
V_274 ;
V_32 -> V_275 =
V_15 ;
V_32 -> V_276 =
V_15 -> V_272 ;
}
V_15 -> V_272 = F_101 ( 0xDEADBEEF ) ;
V_8 -> V_270 -- ;
if ( V_8 -> V_270 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_277 | V_278 ;
break;
}
case V_279 :
* V_251 = 0xDEADBEEF ;
V_8 -> V_270 -- ;
if ( V_8 -> V_270 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_277 | V_278 ;
F_4 ( V_8 , V_20 , V_21 ,
L_17
L_18 , ( unsigned long ) V_259 ) ;
break;
case V_280 :
* V_251 = 0xDEADBEEF ;
V_8 -> V_270 -- ;
if ( V_8 -> V_270 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 ;
F_4 ( V_8 , V_20 , V_21 ,
L_19
L_18 , ( unsigned long ) V_259 ) ;
break;
}
}
if ( V_8 -> V_282 ) {
switch ( V_256 ) {
case V_283 :
case V_284 :
case V_285 :
* V_251 = 0xDEADBEEF ;
V_8 -> V_282 -- ;
if ( V_8 -> V_282 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 ;
F_4 ( V_8 , V_20 , V_21 ,
L_20
L_21 , ( unsigned long ) V_259 ) ;
break;
}
}
}
if ( V_252 ) {
if ( V_8 -> V_286 ) {
switch ( V_256 ) {
case V_271 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_22
L_23 ,
( unsigned long ) V_259 , V_260 ,
F_107 ( V_15 -> V_287 ) ) ;
if ( V_32 ) {
V_32 -> V_273 =
V_288 ;
V_32 -> V_275 =
V_15 ;
V_32 -> V_276 =
V_15 -> V_287 ;
}
V_15 -> V_287 = F_108 ( 0xDEAD ) ;
V_8 -> V_286 -- ;
if ( V_8 -> V_286 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_277 | V_278 ;
break;
}
case V_279 :
* V_252 = 0xDEAD ;
V_8 -> V_286 -- ;
if ( V_8 -> V_286 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_277 | V_278 ;
F_4 ( V_8 , V_20 , V_21 ,
L_24
L_18 , ( unsigned long ) V_259 ) ;
break;
case V_280 :
* V_252 = 0xDEAD ;
V_8 -> V_286 -- ;
if ( V_8 -> V_286 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 ;
F_4 ( V_8 , V_20 , V_21 ,
L_25
L_18 , ( unsigned long ) V_259 ) ;
break;
}
}
if ( V_8 -> V_289 ) {
switch ( V_256 ) {
case V_283 :
case V_284 :
case V_285 :
* V_252 = 0xDEAD ;
V_8 -> V_289 -- ;
if ( V_8 -> V_289 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 ;
F_4 ( V_8 , V_20 , V_21 ,
L_26
L_21 , ( unsigned long ) V_259 ) ;
break;
}
}
}
if ( V_253 ) {
if ( V_8 -> V_290 ) {
switch ( V_256 ) {
case V_271 :
V_211 = V_278 ;
case V_279 :
V_8 -> V_290 -- ;
if ( V_8 -> V_290 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 |= V_277 | V_291 ;
F_4 ( V_8 , V_20 , V_21 ,
L_27
L_18 , ( unsigned long ) V_259 ) ;
break;
case V_280 :
V_8 -> V_290 -- ;
if ( V_8 -> V_290 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 | V_291 ;
F_4 ( V_8 , V_20 , V_21 ,
L_28
L_18 , ( unsigned long ) V_259 ) ;
break;
}
}
if ( V_8 -> V_292 ) {
switch ( V_256 ) {
case V_283 :
case V_284 :
case V_285 :
V_8 -> V_292 -- ;
if ( V_8 -> V_292 == 0 ) {
V_8 -> V_264 = 0 ;
V_8 -> V_262 =
V_263 ;
memset ( & V_8 -> V_266 ,
0 , sizeof( struct V_77 ) ) ;
}
V_211 = V_281 | V_291 ;
F_4 ( V_8 , V_20 , V_21 ,
L_29
L_21 , ( unsigned long ) V_259 ) ;
}
}
}
return V_211 ;
}
static int
F_109 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_222 * V_293 , V_222 * V_294 )
{
V_222 V_295 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_104 ( V_25 ) ) {
case V_283 :
case V_280 :
* V_294 = V_296 ;
* V_293 = V_297 ;
break;
case V_284 :
case V_279 :
* V_294 = V_298 ;
* V_293 = V_299 ;
break;
case V_285 :
case V_271 :
* V_294 = V_300 ;
* V_293 = V_301 ;
break;
case V_261 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_30 ,
F_104 ( V_25 ) ) ;
V_295 = 1 ;
break;
}
} else {
switch ( F_104 ( V_25 ) ) {
case V_284 :
case V_279 :
* V_294 = V_298 ;
* V_293 = V_299 ;
break;
case V_285 :
case V_271 :
* V_294 = V_302 ;
* V_293 = V_302 ;
break;
case V_283 :
case V_280 :
* V_294 = V_299 ;
* V_293 = V_298 ;
break;
case V_261 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_31 ,
F_104 ( V_25 ) ) ;
V_295 = 1 ;
break;
}
}
return V_295 ;
}
static int
F_110 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_222 * V_293 , V_222 * V_294 )
{
V_222 V_295 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_104 ( V_25 ) ) {
case V_283 :
case V_280 :
* V_294 = V_299 ;
* V_293 = V_298 ;
break;
case V_284 :
case V_279 :
* V_294 = V_297 ;
* V_293 = V_296 ;
break;
case V_285 :
case V_271 :
* V_294 = V_301 ;
* V_293 = V_300 ;
break;
case V_261 :
default:
break;
}
} else {
switch ( F_104 ( V_25 ) ) {
case V_284 :
case V_279 :
* V_294 = V_297 ;
* V_293 = V_296 ;
break;
case V_285 :
case V_271 :
* V_294 = V_303 ;
* V_293 = V_303 ;
break;
case V_283 :
case V_280 :
* V_294 = V_296 ;
* V_293 = V_297 ;
break;
case V_261 :
default:
break;
}
}
return V_295 ;
}
static int
F_111 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_118 * V_119 , int V_304 )
{
struct V_17 * V_18 = NULL ;
struct V_305 * V_306 = NULL ;
struct V_307 * V_308 = NULL ;
T_4 V_237 ;
int V_47 = 0 , V_238 = 0 , V_162 ;
int V_240 = V_25 -> V_241 ;
#ifdef F_112
T_2 V_211 ;
#endif
T_2 V_309 = 1 ;
T_2 V_251 ;
unsigned V_257 ;
V_222 V_293 , V_294 ;
V_162 = F_109 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_162 )
goto V_310;
V_257 = F_9 ( V_25 ) ;
V_251 = ( T_2 ) F_105 ( V_25 ) ;
#ifdef F_112
V_211 = F_103 ( V_8 , V_25 , & V_251 , NULL , 1 ) ;
if ( V_211 ) {
if ( V_211 & V_291 )
F_110 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_211 & V_278 )
V_309 = 0 ;
}
#endif
V_306 = (struct V_305 * ) V_119 ;
memset ( V_306 , 0 , sizeof( struct V_305 ) ) ;
F_16 ( V_311 , V_306 , V_312 ) ;
V_306 -> V_313 = F_17 ( V_306 -> V_313 ) ;
V_306 -> V_251 = F_17 ( V_251 ) ;
V_238 ++ ;
V_119 ++ ;
V_308 = (struct V_307 * ) V_119 ;
memset ( V_308 , 0 , sizeof( struct V_307 ) ) ;
F_16 ( V_314 , V_308 , V_315 ) ;
F_16 ( V_316 , V_308 , V_293 ) ;
F_16 ( V_317 , V_308 , V_294 ) ;
if ( V_240 == V_318 ) {
if ( F_10 ( V_25 , V_319 ) )
F_16 ( V_320 , V_308 , V_309 ) ;
else
F_16 ( V_320 , V_308 , 0 ) ;
if ( F_10 ( V_25 , V_321 ) )
F_16 ( V_322 , V_308 , V_309 ) ;
else
F_16 ( V_322 , V_308 , 0 ) ;
}
F_16 ( V_323 , V_308 , 1 ) ;
F_16 ( V_324 , V_308 , 0 ) ;
F_16 ( V_325 , V_308 , 0 ) ;
V_308 -> V_313 = F_17 ( V_308 -> V_313 ) ;
V_308 -> V_326 = F_17 ( V_308 -> V_326 ) ;
V_308 -> V_36 = F_17 ( V_308 -> V_36 ) ;
V_238 ++ ;
V_119 ++ ;
F_98 (sc, sgde, datasegcnt, i) {
V_237 = F_99 ( V_18 ) ;
V_119 -> V_139 = F_15 ( F_57 ( V_237 ) ) ;
V_119 -> V_138 = F_15 ( F_56 ( V_237 ) ) ;
V_119 -> V_140 . V_141 . V_142 = F_100 ( V_18 ) ;
if ( V_240 == V_327 )
V_119 -> V_140 . V_141 . V_143 = V_144 ;
else
V_119 -> V_140 . V_141 . V_143 = V_328 ;
V_119 -> V_140 . V_145 = F_15 ( V_119 -> V_140 . V_145 ) ;
V_119 ++ ;
V_238 ++ ;
}
V_310:
return V_238 ;
}
static int
F_113 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_118 * V_119 , int V_329 , int V_330 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_254 = NULL ;
struct V_305 * V_306 = NULL ;
struct V_307 * V_308 = NULL ;
struct V_331 * V_332 = NULL ;
T_4 V_333 , V_334 ;
unsigned short V_335 = 0 , V_336 = 0 ;
unsigned int V_337 ;
unsigned int V_338 , V_339 = 0 , V_340 ;
unsigned int V_341 , V_342 ;
unsigned int V_343 , V_344 ;
int V_162 ;
int V_240 = V_25 -> V_241 ;
unsigned char V_345 = 0 , V_346 = 0 ;
unsigned V_257 ;
#ifdef F_112
T_2 V_211 ;
#endif
T_2 V_309 = 1 ;
T_2 V_251 ;
V_222 V_293 , V_294 ;
int V_238 = 0 ;
V_254 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_254 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_97 ,
L_32 ,
V_254 , V_18 ) ;
return 0 ;
}
V_162 = F_109 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_162 )
goto V_310;
V_257 = F_9 ( V_25 ) ;
V_251 = ( T_2 ) F_105 ( V_25 ) ;
#ifdef F_112
V_211 = F_103 ( V_8 , V_25 , & V_251 , NULL , 1 ) ;
if ( V_211 ) {
if ( V_211 & V_291 )
F_110 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_211 & V_278 )
V_309 = 0 ;
}
#endif
V_337 = 0 ;
do {
if ( V_238 >= ( V_8 -> V_347 - 2 ) )
return V_238 + 3 ;
V_306 = (struct V_305 * ) V_119 ;
memset ( V_306 , 0 , sizeof( struct V_305 ) ) ;
F_16 ( V_311 , V_306 , V_312 ) ;
V_306 -> V_313 = F_17 ( V_306 -> V_313 ) ;
V_306 -> V_251 = F_17 ( V_251 ) ;
V_238 ++ ;
V_119 ++ ;
V_308 = (struct V_307 * ) V_119 ;
memset ( V_308 , 0 , sizeof( struct V_307 ) ) ;
F_16 ( V_314 , V_308 , V_315 ) ;
F_16 ( V_316 , V_308 , V_293 ) ;
F_16 ( V_317 , V_308 , V_294 ) ;
if ( F_10 ( V_25 , V_319 ) )
F_16 ( V_320 , V_308 , V_309 ) ;
else
F_16 ( V_320 , V_308 , 0 ) ;
if ( F_10 ( V_25 , V_321 ) )
F_16 ( V_322 , V_308 , V_309 ) ;
else
F_16 ( V_322 , V_308 , 0 ) ;
F_16 ( V_323 , V_308 , 1 ) ;
F_16 ( V_324 , V_308 , 0 ) ;
F_16 ( V_325 , V_308 , 0 ) ;
V_308 -> V_313 = F_17 ( V_308 -> V_313 ) ;
V_308 -> V_326 = F_17 ( V_308 -> V_326 ) ;
V_308 -> V_36 = F_17 ( V_308 -> V_36 ) ;
V_238 ++ ;
V_119 ++ ;
V_334 = F_99 ( V_254 ) + V_339 ;
V_338 = F_100 ( V_254 ) - V_339 ;
F_114 ( V_338 % 8 ) ;
V_332 = (struct V_331 * ) V_119 ;
memset ( V_332 , 0 , sizeof( struct V_331 ) ) ;
F_16 ( V_348 , V_332 , V_349 ) ;
V_332 -> V_138 = F_15 ( F_56 ( V_334 ) ) ;
V_332 -> V_139 = F_15 ( F_57 ( V_334 ) ) ;
V_341 = V_338 / 8 ;
V_342 = V_341 * V_257 ;
if ( ( V_332 -> V_139 & 0xfff ) + V_338 > 0x1000 ) {
V_340 = 0x1000 - ( V_332 -> V_139 & 0xfff ) ;
V_339 += V_340 ;
V_341 = V_340 / 8 ;
V_342 = V_341 * V_257 ;
} else {
V_339 = 0 ;
V_336 ++ ;
}
V_238 ++ ;
V_345 = 0 ;
V_344 = 0 ;
while ( ! V_345 ) {
if ( V_238 >= V_8 -> V_347 )
return V_238 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_33 ,
V_22 ) ;
return 0 ;
}
V_119 ++ ;
V_333 = F_99 ( V_18 ) + V_337 ;
V_119 -> V_139 = F_15 ( F_57 ( V_333 ) ) ;
V_119 -> V_138 = F_15 ( F_56 ( V_333 ) ) ;
V_343 = F_100 ( V_18 ) - V_337 ;
if ( ( V_344 + V_343 ) <= V_342 ) {
V_119 -> V_140 . V_141 . V_142 = V_343 ;
V_337 = 0 ;
if ( ( V_344 + V_343 ) == V_342 )
V_345 = 1 ;
} else {
V_119 -> V_140 . V_141 . V_142 = V_342 - V_344 ;
V_337 += V_119 -> V_140 . V_141 . V_142 ;
}
V_344 += V_119 -> V_140 . V_141 . V_142 ;
if ( V_240 == V_327 )
V_119 -> V_140 . V_141 . V_143 = V_144 ;
else
V_119 -> V_140 . V_141 . V_143 = V_328 ;
V_119 -> V_140 . V_145 = F_15 ( V_119 -> V_140 . V_145 ) ;
V_238 ++ ;
V_335 ++ ;
if ( V_337 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_339 ) {
V_251 += V_341 ;
V_119 ++ ;
continue;
}
if ( V_336 == V_330 ) {
V_346 = 1 ;
} else if ( V_336 < V_330 ) {
V_254 = F_6 ( V_254 ) ;
V_119 ++ ;
V_251 += V_341 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_34 , V_22 ) ;
}
} while ( ! V_346 );
V_310:
return V_238 ;
}
static int
F_115 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_304 )
{
struct V_17 * V_18 = NULL ;
struct V_350 * V_351 = NULL ;
T_4 V_237 ;
int V_47 = 0 , V_352 = 0 , V_162 ;
T_2 V_251 ;
unsigned V_257 ;
V_222 V_293 , V_294 ;
#ifdef F_112
T_2 V_211 ;
#endif
T_2 V_309 = 1 ;
T_2 V_353 ;
T_2 V_354 = 0 ;
V_162 = F_109 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_162 )
goto V_310;
V_257 = F_9 ( V_25 ) ;
V_251 = ( T_2 ) F_105 ( V_25 ) ;
#ifdef F_112
V_211 = F_103 ( V_8 , V_25 , & V_251 , NULL , 1 ) ;
if ( V_211 ) {
if ( V_211 & V_291 )
F_110 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_211 & V_278 )
V_309 = 0 ;
}
#endif
V_351 = (struct V_350 * ) V_34 ;
memset ( V_351 , 0 , sizeof( struct V_350 ) ) ;
F_16 ( V_355 , V_34 , V_356 ) ;
V_351 -> V_272 = F_17 ( V_251 ) ;
V_351 -> V_357 = V_351 -> V_272 ;
if ( V_25 -> V_241 == V_318 ) {
if ( F_10 ( V_25 , V_319 ) )
F_16 ( V_358 , V_351 , V_309 ) ;
else
F_16 ( V_358 , V_351 , 0 ) ;
if ( F_10 ( V_25 , V_321 ) )
F_16 ( V_359 , V_351 , V_309 ) ;
else
F_16 ( V_359 , V_351 , 0 ) ;
}
F_16 ( V_360 , V_351 , V_293 ) ;
F_16 ( V_361 , V_351 , V_294 ) ;
F_16 ( V_362 , V_351 , 1 ) ;
F_16 ( V_363 , V_351 , 0 ) ;
V_351 -> V_36 = F_17 ( V_351 -> V_36 ) ;
V_351 -> V_364 = F_17 ( V_351 -> V_364 ) ;
V_352 ++ ;
V_34 ++ ;
F_98 (sc, sgde, datasegcnt, i) {
V_237 = F_99 ( V_18 ) ;
V_353 = F_100 ( V_18 ) ;
V_34 -> V_224 = F_17 ( F_57 ( V_237 ) ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_237 ) ) ;
if ( ( V_47 + 1 ) == V_304 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_365 , V_34 , V_354 ) ;
F_16 ( V_355 , V_34 , V_366 ) ;
V_34 -> V_225 = F_17 ( V_353 ) ;
V_354 += V_353 ;
V_34 ++ ;
V_352 ++ ;
}
V_310:
return V_352 ;
}
static int
F_116 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_329 , int V_330 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_254 = NULL ;
struct V_350 * V_351 = NULL ;
T_4 V_333 , V_334 ;
unsigned short V_335 = 0 , V_336 = 0 ;
unsigned int V_337 ;
unsigned int V_338 , V_339 = 0 , V_340 ;
unsigned int V_341 , V_342 ;
unsigned int V_343 , V_344 ;
int V_162 ;
unsigned char V_345 = 0 , V_346 = 0 ;
unsigned V_257 ;
T_2 V_251 ;
V_222 V_293 , V_294 ;
T_2 V_353 ;
#ifdef F_112
T_2 V_211 ;
#endif
T_2 V_309 = 1 ;
T_2 V_354 = 0 ;
int V_352 = 0 ;
V_254 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_254 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_97 ,
L_35 ,
V_254 , V_18 ) ;
return 0 ;
}
V_162 = F_109 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_162 )
goto V_310;
V_257 = F_9 ( V_25 ) ;
V_251 = ( T_2 ) F_105 ( V_25 ) ;
#ifdef F_112
V_211 = F_103 ( V_8 , V_25 , & V_251 , NULL , 1 ) ;
if ( V_211 ) {
if ( V_211 & V_291 )
F_110 ( V_8 , V_25 , & V_293 , & V_294 ) ;
if ( V_211 & V_278 )
V_309 = 0 ;
}
#endif
V_337 = 0 ;
do {
if ( V_352 >= ( V_8 -> V_347 - 2 ) )
return V_352 + 3 ;
V_351 = (struct V_350 * ) V_34 ;
memset ( V_351 , 0 , sizeof( struct V_350 ) ) ;
F_16 ( V_355 , V_34 , V_356 ) ;
V_351 -> V_272 = F_17 ( V_251 ) ;
V_351 -> V_357 = V_351 -> V_272 ;
if ( F_10 ( V_25 , V_319 ) ) {
F_16 ( V_358 , V_351 , V_309 ) ;
} else {
F_16 ( V_358 , V_351 , 0 ) ;
if ( V_293 == V_302 ) {
V_293 = V_367 ;
V_294 = V_367 ;
}
}
if ( F_10 ( V_25 , V_321 ) )
F_16 ( V_359 , V_351 , V_309 ) ;
else
F_16 ( V_359 , V_351 , 0 ) ;
F_16 ( V_360 , V_351 , V_293 ) ;
F_16 ( V_361 , V_351 , V_294 ) ;
F_16 ( V_362 , V_351 , 1 ) ;
F_16 ( V_363 , V_351 , 0 ) ;
V_351 -> V_36 = F_17 ( V_351 -> V_36 ) ;
V_351 -> V_364 = F_17 ( V_351 -> V_364 ) ;
V_352 ++ ;
V_34 ++ ;
V_334 = F_99 ( V_254 ) + V_339 ;
V_338 = F_100 ( V_254 ) - V_339 ;
F_114 ( V_338 % 8 ) ;
V_34 -> V_36 = 0 ;
F_16 ( V_355 , V_34 , V_368 ) ;
V_34 -> V_223 = F_15 ( F_56 ( V_334 ) ) ;
V_34 -> V_224 = F_15 ( F_57 ( V_334 ) ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_341 = V_338 / 8 ;
V_342 = V_341 * V_257 ;
if ( ( V_34 -> V_224 & 0xfff ) + V_338 > 0x1000 ) {
V_340 = 0x1000 - ( V_34 -> V_224 & 0xfff ) ;
V_339 += V_340 ;
V_341 = V_340 / 8 ;
V_342 = V_341 * V_257 ;
} else {
V_339 = 0 ;
V_336 ++ ;
}
V_352 ++ ;
V_345 = 0 ;
V_344 = 0 ;
while ( ! V_345 ) {
if ( V_352 >= V_8 -> V_347 )
return V_352 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_36 ,
V_22 ) ;
return 0 ;
}
V_34 ++ ;
V_333 = F_99 ( V_18 ) + V_337 ;
V_343 = F_100 ( V_18 ) - V_337 ;
if ( ( V_344 + V_343 ) <= V_342 ) {
V_353 = V_343 ;
V_337 = 0 ;
if ( ( V_344 + V_343 ) == V_342 )
V_345 = 1 ;
} else {
V_353 = V_342 - V_344 ;
V_337 += V_353 ;
}
V_344 += V_353 ;
V_34 -> V_224 = F_17 ( F_57 ( V_333 ) ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_333 ) ) ;
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_365 , V_34 , V_354 ) ;
F_16 ( V_355 , V_34 , V_366 ) ;
V_34 -> V_225 = F_17 ( V_353 ) ;
V_354 += V_353 ;
V_352 ++ ;
V_335 ++ ;
if ( V_337 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_339 ) {
V_251 += V_341 ;
V_34 ++ ;
continue;
}
if ( V_336 == V_330 ) {
F_16 ( V_37 , V_34 , 1 ) ;
V_346 = 1 ;
} else if ( V_336 < V_330 ) {
V_254 = F_6 ( V_254 ) ;
V_34 ++ ;
V_251 += V_341 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_37 , V_22 ) ;
}
} while ( ! V_346 );
V_310:
return V_352 ;
}
static int
F_12 ( struct V_12 * V_8 , struct V_13 * V_25 )
{
int V_295 = V_369 ;
unsigned char V_256 = F_104 ( V_25 ) ;
switch ( V_256 ) {
case V_284 :
case V_279 :
V_295 = V_29 ;
break;
case V_283 :
case V_280 :
case V_285 :
case V_271 :
V_295 = V_370 ;
break;
default:
if ( V_8 )
F_4 ( V_8 , V_20 , V_97 ,
L_38 ,
V_256 ) ;
break;
}
return V_295 ;
}
static int
F_117 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_25 = V_32 -> V_42 ;
int V_371 ;
V_371 = F_102 ( V_25 ) ;
if ( V_25 -> V_241 == V_318 ) {
if ( F_104 ( V_25 ) == V_283 )
return V_371 ;
} else {
if ( F_104 ( V_25 ) == V_280 )
return V_371 ;
}
V_371 += ( V_371 / F_9 ( V_25 ) ) * 8 ;
return V_371 ;
}
static int
F_118 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_128 * V_128 = V_32 -> V_128 ;
struct V_118 * V_119 = V_32 -> V_35 ;
T_3 * V_234 = & V_32 -> V_135 . V_120 ;
T_2 V_238 = 0 ;
int V_304 , V_372 , V_240 = V_13 -> V_241 ;
int V_373 = 0 ;
int V_371 ;
V_119 += 2 ;
if ( F_94 ( V_13 ) ) {
V_304 = F_95 ( & V_8 -> V_242 -> V_243 ,
F_3 ( V_13 ) ,
F_94 ( V_13 ) , V_240 ) ;
if ( F_96 ( ! V_304 ) )
return 1 ;
V_32 -> V_229 = V_304 ;
if ( V_32 -> V_229 > V_8 -> V_244 )
goto V_374;
V_373 = F_12 ( V_8 , V_13 ) ;
switch ( V_373 ) {
case V_29 :
if ( ( V_32 -> V_229 + 2 ) > V_8 -> V_347 )
goto V_374;
V_238 = F_111 ( V_8 , V_13 , V_119 ,
V_304 ) ;
if ( V_238 < 2 )
goto V_374;
break;
case V_370 :
V_372 = F_95 ( & V_8 -> V_242 -> V_243 ,
F_8 ( V_13 ) ,
F_119 ( V_13 ) , V_240 ) ;
if ( F_96 ( ! V_372 ) ) {
F_97 ( V_13 ) ;
return 1 ;
}
V_32 -> V_231 = V_372 ;
if ( ( V_32 -> V_231 * 4 ) >
( V_8 -> V_347 - 2 ) )
goto V_374;
V_238 = F_113 ( V_8 , V_13 , V_119 ,
V_304 , V_372 ) ;
if ( ( V_238 < 3 ) ||
( V_238 > V_8 -> V_347 ) )
goto V_374;
break;
case V_369 :
default:
F_97 ( V_13 ) ;
V_32 -> V_229 = 0 ;
F_4 ( V_8 , V_20 , V_97 ,
L_39 ,
V_373 ) ;
return 1 ;
}
}
V_234 -> V_68 . V_146 . V_147 . V_142 = ( 2 * sizeof( struct V_118 ) ) ;
V_234 -> V_68 . V_146 . V_147 . V_142 += ( V_238 * sizeof( struct V_118 ) ) ;
V_234 -> V_156 = 1 ;
V_234 -> V_157 = 1 ;
V_371 = F_117 ( V_8 , V_32 ) ;
V_128 -> V_248 = F_106 ( V_371 ) ;
V_234 -> V_68 . V_249 . V_250 = V_371 ;
return 0 ;
V_374:
if ( V_32 -> V_229 )
F_97 ( V_13 ) ;
if ( V_32 -> V_231 )
F_120 ( & V_8 -> V_242 -> V_243 , F_8 ( V_13 ) ,
F_119 ( V_13 ) ,
V_13 -> V_241 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_40
L_41 ,
V_32 -> V_229 , V_32 -> V_231 ,
V_8 -> V_347 , V_8 -> V_244 ,
V_373 , V_238 ) ;
V_32 -> V_229 = 0 ;
V_32 -> V_231 = 0 ;
return 1 ;
}
static T_5
F_121 ( V_222 * V_132 , int V_375 )
{
T_5 V_376 = 0 ;
T_5 V_377 ;
V_376 = F_122 ( V_132 , V_375 ) ;
V_377 = F_108 ( V_376 ) ;
return V_377 ;
}
static T_5
F_123 ( V_222 * V_132 , int V_375 )
{
T_5 V_295 ;
V_295 = F_124 ( V_132 , V_375 ) ;
return V_295 ;
}
static void
F_125 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_17 * V_254 ;
struct V_17 * V_18 ;
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_255 * V_15 = NULL ;
V_222 * V_378 = NULL ;
T_5 V_379 , V_380 ;
T_5 V_381 , V_287 ;
T_2 V_382 , V_272 ;
int V_383 , V_372 ;
int V_384 , V_385 , V_386 ;
int V_387 , V_388 , V_389 ;
T_5 V_390 ;
unsigned V_257 ;
V_384 = V_391 ;
V_390 = 0 ;
V_379 = 0 ;
V_383 = F_104 ( V_41 ) ;
if ( ( V_383 == V_284 ) ||
( V_383 == V_279 ) ||
( V_383 == V_261 ) )
goto V_310;
V_387 = 1 ;
V_388 = 0 ;
V_389 = 0 ;
V_254 = F_8 ( V_41 ) ;
V_372 = V_32 -> V_231 ;
if ( V_254 && V_372 ) {
V_18 = F_3 ( V_41 ) ;
V_257 = F_9 ( V_41 ) ;
V_378 = ( V_222 * ) F_5 ( V_18 ) ;
V_386 = V_18 -> V_23 ;
if ( ( V_386 & ( V_257 - 1 ) ) == 0 )
V_389 = 1 ;
V_380 = F_13 ( V_41 -> V_26 -> V_6 ) ;
V_15 = (struct V_255 * ) F_5 ( V_254 ) ;
V_382 = ( T_2 ) F_105 ( V_41 ) ;
V_381 = V_15 -> V_287 ;
V_385 = V_254 -> V_23 ;
while ( V_15 && V_372 ) {
while ( V_385 ) {
if ( ( V_15 -> V_272 == 0xffffffff ) ||
( V_15 -> V_287 == 0xffff ) ) {
V_382 ++ ;
goto V_392;
}
if ( V_389 ) {
V_379 = V_15 -> V_379 ;
if ( F_11 ( V_41 ) )
V_390 = F_123 ( V_378 ,
V_257 ) ;
else
V_390 = F_121 ( V_378 ,
V_257 ) ;
if ( ( V_379 != V_390 ) ) {
V_384 = V_391 ;
goto V_310;
}
}
V_272 = F_106 ( V_15 -> V_272 ) ;
if ( V_387 && ( V_272 != V_382 ) ) {
V_384 = V_393 ;
goto V_310;
}
V_382 ++ ;
V_287 = V_15 -> V_287 ;
if ( V_388 && ( V_287 != V_381 ) ) {
V_384 = V_394 ;
goto V_310;
}
V_392:
V_385 -= sizeof( struct V_255 ) ;
if ( V_385 < 0 )
V_385 = 0 ;
V_15 ++ ;
V_378 += V_257 ;
V_386 -= V_257 ;
if ( V_389 && ( V_386 == 0 ) ) {
V_389 = 0 ;
V_18 = F_6 ( V_18 ) ;
if ( ! V_18 )
goto V_310;
V_378 = ( V_222 * ) F_5 ( V_18 ) ;
V_386 = V_18 -> V_23 ;
if ( ( V_386 & ( V_257 - 1 ) ) == 0 )
V_389 = 1 ;
}
}
V_254 = F_6 ( V_254 ) ;
if ( V_254 ) {
V_15 = (struct V_255 * ) F_5 ( V_254 ) ;
V_385 = V_254 -> V_23 ;
} else {
V_15 = NULL ;
}
V_372 -- ;
}
}
V_310:
if ( V_384 == V_391 ) {
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_400 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_42 ,
( unsigned long ) F_105 ( V_41 ) ,
V_390 , V_379 ) ;
} else if ( V_384 == V_393 ) {
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_401 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_43 ,
( unsigned long ) F_105 ( V_41 ) ,
V_272 , V_382 ) ;
} else if ( V_384 == V_394 ) {
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_402 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_44 ,
( unsigned long ) F_105 ( V_41 ) ,
V_287 , V_381 ) ;
}
}
static int
F_128 ( struct V_12 * V_8 , struct V_31 * V_32 ,
struct V_175 * V_403 )
{
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_404 * V_405 = & V_403 -> V_120 . V_153 . V_406 ;
int V_295 = 0 ;
T_2 V_407 = V_405 -> V_407 ;
T_2 V_408 = V_405 -> V_408 ;
T_1 V_409 = 0 ;
F_61 ( & V_410 ) ;
if ( ! V_411 ) {
F_4 ( V_8 , V_20 , V_21 , L_45
L_46 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_2 ( V_8 , V_41 ) ;
if ( F_12 ( V_8 , V_41 ) ==
V_370 ) {
F_4 ( V_8 , V_20 , V_21 , L_47
L_48 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_7 ( V_8 , V_41 ) ;
}
V_411 = 1 ;
}
F_63 ( & V_410 ) ;
if ( F_129 ( V_408 ) ) {
V_41 -> V_48 = F_127 ( V_412 , 0 ) ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_49
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
V_295 = ( - 1 ) ;
goto V_310;
}
if ( F_131 ( V_408 ) ) {
V_41 -> V_48 = F_127 ( V_412 , 0 ) ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_52
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
V_295 = ( - 1 ) ;
goto V_310;
}
if ( F_132 ( V_408 ) ) {
V_295 = 1 ;
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_400 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_53
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
}
if ( F_133 ( V_408 ) ) {
V_295 = 1 ;
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_401 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_54
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
}
if ( F_134 ( V_408 ) ) {
V_295 = 1 ;
F_126 ( 1 , V_41 -> V_395 , V_396 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_397 << 24
| F_127 ( V_398 , V_399 ) ;
V_8 -> V_402 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_55
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
}
if ( F_135 ( V_408 ) ) {
V_41 -> V_395 [ 7 ] = 0xc ;
V_41 -> V_395 [ 8 ] = 0 ;
V_41 -> V_395 [ 9 ] = 0xa ;
V_41 -> V_395 [ 10 ] = 0x80 ;
switch ( F_104 ( V_41 ) ) {
case V_283 :
case V_280 :
V_407 /= V_41 -> V_26 -> V_27 ;
break;
case V_284 :
case V_279 :
case V_285 :
case V_271 :
V_407 /= ( V_41 -> V_26 -> V_27 +
sizeof( struct V_255 ) ) ;
break;
}
V_409 = F_105 ( V_41 ) ;
V_409 += V_407 ;
F_136 ( V_409 , & V_41 -> V_395 [ 12 ] ) ;
}
if ( ! V_295 ) {
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_56
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_41 ) ,
F_130 ( V_41 -> V_413 ) , V_408 , V_407 ) ;
F_125 ( V_8 , V_32 ) ;
}
V_310:
return V_295 ;
}
static int
F_137 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_233 = NULL ;
struct V_128 * V_128 = V_32 -> V_128 ;
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_33 * V_414 ;
T_3 * V_234 = & V_32 -> V_135 . V_120 ;
T_4 V_237 ;
T_2 V_238 = 0 ;
T_2 V_353 ;
T_2 V_354 = 0 ;
int V_239 ;
struct V_118 * V_415 ;
if ( F_94 ( V_13 ) ) {
V_239 = F_138 ( V_13 ) ;
if ( F_96 ( ! V_239 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_414 = V_34 ;
V_32 -> V_229 = V_239 ;
if ( V_32 -> V_229 > V_8 -> V_244 ) {
F_4 ( V_8 , V_20 , V_21 , L_57
L_58
L_14 ,
V_22 , V_8 -> V_244 ,
V_32 -> V_229 ) ;
V_32 -> V_229 = 0 ;
F_97 ( V_13 ) ;
return 1 ;
}
F_98 (scsi_cmnd, sgel, nseg, num_bde) {
V_237 = F_99 ( V_233 ) ;
V_353 = F_100 ( V_233 ) ;
V_34 -> V_224 = F_17 ( F_57 ( V_237 ) ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_237 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
if ( ( V_238 + 1 ) == V_239 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_365 , V_34 , V_354 ) ;
F_16 ( V_355 , V_34 , V_366 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_225 = F_17 ( V_353 ) ;
V_354 += V_353 ;
V_34 ++ ;
}
if ( V_8 -> V_150 & V_416 ) {
V_415 = (struct V_118 * )
& ( V_234 -> V_153 . V_417 [ 5 ] ) ;
V_415 -> V_139 = V_414 -> V_224 ;
V_415 -> V_138 = V_414 -> V_223 ;
V_415 -> V_140 . V_141 . V_142 =
F_15 ( V_414 -> V_225 ) ;
V_415 -> V_140 . V_141 . V_143 = V_144 ;
V_415 -> V_140 . V_145 = F_17 ( V_415 -> V_140 . V_145 ) ;
}
} else {
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
}
V_128 -> V_248 = F_101 ( F_102 ( V_13 ) ) ;
V_234 -> V_68 . V_249 . V_250 = F_102 ( V_13 ) ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_418 )
V_32 -> V_135 . V_136 |= ( V_419 | V_420 ) ;
return 0 ;
}
static int
F_139 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_128 * V_128 = V_32 -> V_128 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_32 -> V_35 ) ;
T_3 * V_234 = & V_32 -> V_135 . V_120 ;
T_2 V_352 = 0 ;
int V_304 , V_372 , V_240 = V_13 -> V_241 ;
int V_373 = 0 ;
int V_371 ;
if ( F_94 ( V_13 ) ) {
V_304 = F_95 ( & V_8 -> V_242 -> V_243 ,
F_3 ( V_13 ) ,
F_94 ( V_13 ) , V_240 ) ;
if ( F_96 ( ! V_304 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_32 -> V_229 = V_304 ;
if ( V_32 -> V_229 > V_8 -> V_244 )
goto V_374;
V_373 = F_12 ( V_8 , V_13 ) ;
switch ( V_373 ) {
case V_29 :
if ( ( V_32 -> V_229 + 1 ) > V_8 -> V_347 )
goto V_374;
V_352 = F_115 ( V_8 , V_13 , V_34 ,
V_304 ) ;
if ( V_352 < 2 )
goto V_374;
break;
case V_370 :
V_372 = F_95 ( & V_8 -> V_242 -> V_243 ,
F_8 ( V_13 ) ,
F_119 ( V_13 ) , V_240 ) ;
if ( F_96 ( ! V_372 ) ) {
F_97 ( V_13 ) ;
return 1 ;
}
V_32 -> V_231 = V_372 ;
if ( ( V_32 -> V_231 * 3 ) >
( V_8 -> V_347 - 2 ) )
goto V_374;
V_352 = F_116 ( V_8 , V_13 , V_34 ,
V_304 , V_372 ) ;
if ( ( V_352 < 3 ) ||
( V_352 > V_8 -> V_347 ) )
goto V_374;
break;
case V_369 :
default:
F_97 ( V_13 ) ;
V_32 -> V_229 = 0 ;
F_4 ( V_8 , V_20 , V_97 ,
L_59 ,
V_373 ) ;
return 1 ;
}
}
switch ( F_104 ( V_13 ) ) {
case V_280 :
case V_284 :
V_32 -> V_135 . V_136 |= V_421 ;
break;
case V_279 :
case V_283 :
V_32 -> V_135 . V_136 |= V_422 ;
break;
case V_271 :
case V_285 :
V_32 -> V_135 . V_136 |= V_423 ;
break;
}
V_371 = F_117 ( V_8 , V_32 ) ;
V_128 -> V_248 = F_106 ( V_371 ) ;
V_234 -> V_68 . V_249 . V_250 = V_371 ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_418 )
V_32 -> V_135 . V_136 |= ( V_419 | V_420 ) ;
return 0 ;
V_374:
if ( V_32 -> V_229 )
F_97 ( V_13 ) ;
if ( V_32 -> V_231 )
F_120 ( & V_8 -> V_242 -> V_243 , F_8 ( V_13 ) ,
F_119 ( V_13 ) ,
V_13 -> V_241 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_60
L_61 ,
V_32 -> V_229 , V_32 -> V_231 ,
V_8 -> V_347 , V_8 -> V_244 ,
V_373 , V_352 ) ;
V_32 -> V_229 = 0 ;
V_32 -> V_231 = 0 ;
return 1 ;
}
static inline int
F_140 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_140 ( V_8 , V_32 ) ;
}
static inline int
F_141 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_141 ( V_8 , V_32 ) ;
}
static void
F_142 ( struct V_12 * V_8 , struct V_4 * V_5 ,
struct V_31 * V_32 , struct V_175 * V_424 ) {
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_129 * V_425 = V_32 -> V_129 ;
T_2 V_426 = V_425 -> V_427 ;
T_2 V_428 = V_425 -> V_429 ;
T_2 V_250 = V_424 -> V_120 . V_68 . V_249 . V_250 ;
struct V_66 * V_67 = NULL ;
struct V_39 * V_40 = V_32 -> V_38 -> V_40 ;
unsigned long V_43 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return;
if ( ( V_14 -> V_48 == V_430 ) ||
( V_14 -> V_48 == V_431 ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_432 . V_71 =
V_72 ;
V_67 -> V_68 . V_432 . V_73 =
( V_14 -> V_48 == V_430 ) ?
V_433 : V_434 ;
V_67 -> V_68 . V_432 . V_63 = V_14 -> V_26 -> V_63 ;
memcpy ( & V_67 -> V_68 . V_432 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_432 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
} else if ( ( V_426 & V_435 ) && V_425 -> V_436 &&
( ( V_14 -> V_14 [ 0 ] == V_437 ) || ( V_14 -> V_14 [ 0 ] == V_438 ) ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_439 . V_70 . V_71 =
V_72 ;
V_67 -> V_68 . V_439 . V_70 . V_73 =
V_440 ;
V_67 -> V_68 . V_439 . V_70 . V_63 =
V_14 -> V_26 -> V_63 ;
memcpy ( & V_67 -> V_68 . V_439 . V_70 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_439 . V_70 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
V_67 -> V_68 . V_439 . V_441 =
V_14 -> V_395 [ 2 ] & 0xf ;
V_67 -> V_68 . V_439 . V_442 = V_14 -> V_395 [ 12 ] ;
V_67 -> V_68 . V_439 . V_443 = V_14 -> V_395 [ 13 ] ;
} else if ( ( V_14 -> V_241 == V_318 ) &&
V_250 &&
( ( F_106 ( V_425 -> V_444 ) != V_250 ) ||
( ( V_428 == V_445 ) &&
! ( V_426 & ( V_446 | V_447 ) ) ) ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_448 . V_449 . V_71 =
V_450 ;
V_67 -> V_68 . V_448 . V_449 . V_73 =
V_451 ;
memcpy ( & V_67 -> V_68 . V_448 . V_449 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_448 . V_449 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
V_67 -> V_68 . V_448 . V_63 = V_14 -> V_26 -> V_63 ;
V_67 -> V_68 . V_448 . V_452 = V_14 -> V_14 [ 0 ] ;
V_67 -> V_68 . V_448 . V_453 =
V_250 ;
} else
return;
V_67 -> V_5 = V_5 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
F_25 ( & V_67 -> V_82 . V_86 , & V_8 -> V_87 ) ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_26 ( V_8 ) ;
return;
}
static void
F_143 ( struct V_12 * V_8 , struct V_31 * V_117 )
{
if ( V_117 -> V_229 > 0 )
F_97 ( V_117 -> V_42 ) ;
if ( V_117 -> V_231 > 0 )
F_120 ( & V_8 -> V_242 -> V_243 , F_8 ( V_117 -> V_42 ) ,
F_119 ( V_117 -> V_42 ) ,
V_117 -> V_42 -> V_241 ) ;
}
static void
F_144 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_175 * V_424 )
{
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_128 * V_454 = V_32 -> V_128 ;
struct V_129 * V_425 = V_32 -> V_129 ;
T_2 V_250 = V_424 -> V_120 . V_68 . V_249 . V_250 ;
T_2 V_426 = V_425 -> V_427 ;
T_2 V_428 = V_425 -> V_429 ;
T_2 * V_455 ;
T_2 V_456 = V_457 ;
T_2 V_458 = 0 ;
T_2 V_459 = V_97 | V_460 ;
if ( V_454 -> V_461 ) {
V_428 = 0 ;
goto V_310;
}
if ( V_426 & V_462 ) {
V_458 = F_106 ( V_425 -> V_463 ) ;
if ( V_458 != 0 && V_458 != 4 && V_458 != 8 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_62
L_63 ,
V_14 -> V_26 -> V_464 ,
V_14 -> V_26 -> V_63 , V_14 -> V_14 [ 0 ] ,
V_458 ) ;
V_456 = V_412 ;
goto V_310;
}
if ( V_425 -> V_465 != V_466 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_64
L_65
L_66 ,
V_14 -> V_26 -> V_464 ,
V_14 -> V_26 -> V_63 , V_14 -> V_14 [ 0 ] ,
V_425 -> V_465 ) ;
V_456 = V_412 ;
goto V_310;
}
}
if ( ( V_426 & V_435 ) && V_425 -> V_436 ) {
T_2 V_467 = F_106 ( V_425 -> V_436 ) ;
if ( V_467 > V_468 )
V_467 = V_468 ;
if ( V_426 & V_462 )
V_458 = F_106 ( V_425 -> V_463 ) ;
memcpy ( V_14 -> V_395 , & V_425 -> V_469 + V_458 , V_467 ) ;
}
V_455 = ( T_2 * ) V_14 -> V_395 ;
if ( ! V_428 && ( V_426 & V_446 ) ) {
if ( V_5 -> V_470 & V_97 )
V_459 = V_460 ;
if ( V_5 -> V_470 & V_471 )
V_459 = V_471 ;
}
F_31 ( V_5 , V_96 , V_459 ,
L_67
L_68 ,
V_14 -> V_14 [ 0 ] , V_428 ,
F_106 ( * V_455 ) , F_106 ( * ( V_455 + 3 ) ) , V_426 ,
F_106 ( V_425 -> V_444 ) ,
F_106 ( V_425 -> V_436 ) ,
F_106 ( V_425 -> V_463 ) ,
V_425 -> V_465 ) ;
F_145 ( V_14 , 0 ) ;
if ( V_426 & V_446 ) {
F_145 ( V_14 , F_106 ( V_425 -> V_444 ) ) ;
F_31 ( V_5 , V_130 , V_471 ,
L_69
L_70 ,
F_106 ( V_454 -> V_248 ) ,
F_146 ( V_14 ) , V_250 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_472 ) ;
if ( ( V_14 -> V_241 == V_318 ) &&
V_250 &&
( F_146 ( V_14 ) != V_250 ) ) {
F_31 ( V_5 , V_96 ,
V_97 | V_460 ,
L_71
L_72 ,
F_106 ( V_454 -> V_248 ) ,
F_146 ( V_14 ) , V_250 ,
V_14 -> V_14 [ 0 ] ) ;
F_145 ( V_14 , F_102 ( V_14 ) ) ;
V_456 = V_412 ;
}
if ( ! ( V_426 & V_435 ) &&
( V_428 == V_445 ) &&
( F_102 ( V_14 ) - F_146 ( V_14 )
< V_14 -> V_472 ) ) {
F_31 ( V_5 , V_130 , V_97 ,
L_73
L_74
L_75 ,
V_14 -> V_14 [ 0 ] , F_102 ( V_14 ) ,
F_146 ( V_14 ) , V_14 -> V_472 ) ;
V_456 = V_412 ;
}
} else if ( V_426 & V_447 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_76
L_77 , V_14 -> V_14 [ 0 ] ,
F_102 ( V_14 ) , F_146 ( V_14 ) ) ;
V_456 = V_412 ;
} else if ( V_250 && ( V_14 -> V_241 == V_318 ) ) {
F_31 ( V_5 , V_96 , V_97 | V_460 ,
L_78
L_79 ,
F_106 ( V_454 -> V_248 ) ,
F_106 ( V_425 -> V_444 ) ,
V_250 , V_14 -> V_14 [ 0 ] , V_428 ) ;
switch ( V_428 ) {
case V_445 :
case V_399 :
V_456 = V_412 ;
break;
}
F_145 ( V_14 , F_102 ( V_14 ) ) ;
}
V_310:
V_14 -> V_48 = F_127 ( V_456 , V_428 ) ;
F_142 ( V_5 -> V_8 , V_5 , V_32 , V_424 ) ;
}
static void
F_147 ( struct V_12 * V_8 , struct V_175 * V_473 ,
struct V_175 * V_403 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_473 -> V_164 ;
struct V_4 * V_5 = V_473 -> V_5 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_13 * V_41 ;
int V_48 ;
int V_474 ;
unsigned long V_43 ;
struct V_66 * V_67 ;
struct V_44 * V_45 ;
T_2 V_92 , V_475 ;
T_2 V_459 = V_97 ;
if ( ! ( V_32 -> V_42 ) )
return;
V_41 = V_32 -> V_42 ;
V_45 = V_41 -> V_26 -> V_6 ;
V_32 -> V_48 = ( V_403 -> V_120 . V_68 . V_476 [ 4 ] & V_477 ) ;
V_32 -> V_162 = V_403 -> V_120 . V_478 ;
V_32 -> V_185 = V_403 -> V_136 & V_479 ;
#ifdef F_112
if ( V_32 -> V_273 ) {
struct V_255 * V_15 = NULL ;
V_15 = (struct V_255 * ) V_32 -> V_275 ;
switch ( V_32 -> V_273 ) {
case V_274 :
V_15 -> V_272 =
V_32 -> V_276 ;
break;
case V_288 :
V_15 -> V_287 =
( T_5 ) V_32 -> V_276 ;
break;
case V_480 :
V_15 -> V_379 =
( T_5 ) V_32 -> V_276 ;
break;
default:
break;
}
V_32 -> V_276 = 0 ;
V_32 -> V_273 = 0 ;
V_32 -> V_275 = NULL ;
}
#endif
if ( V_40 && F_24 ( V_40 ) )
F_148 ( & V_40 -> V_481 ) ;
if ( V_32 -> V_162 ) {
if ( V_32 -> V_162 == V_482 &&
( V_32 -> V_48 & V_483 ) )
V_32 -> V_162 = V_484 ;
else if ( V_32 -> V_162 >= V_485 )
V_32 -> V_162 = V_486 ;
if ( V_32 -> V_162 == V_487 &&
! V_32 -> V_129 -> V_429 &&
( V_32 -> V_129 -> V_427 & V_446 ) &&
! ( V_5 -> V_470 & V_471 ) )
V_459 = 0 ;
else
V_459 = V_97 | V_471 ;
F_31 ( V_5 , V_96 , V_459 ,
L_80
L_81
L_82
L_77 ,
V_41 -> V_14 [ 0 ] ,
V_41 -> V_26 ? V_41 -> V_26 -> V_464 : 0xffff ,
V_41 -> V_26 ? V_41 -> V_26 -> V_63 : 0xffff ,
V_32 -> V_162 , V_32 -> V_48 ,
V_5 -> V_488 ,
( V_40 ) ? V_40 -> V_265 : 0 ,
V_8 -> V_149 == V_489 ?
V_32 -> V_135 . V_183 : 0xffff ,
V_403 -> V_120 . V_490 ,
V_32 -> V_135 . V_120 . V_491 ) ;
switch ( V_32 -> V_162 ) {
case V_487 :
F_144 ( V_5 , V_32 , V_403 ) ;
break;
case V_492 :
case V_493 :
V_41 -> V_48 = F_127 ( V_494 , 0 ) ;
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
break;
V_67 -> V_68 . V_495 . V_71 =
V_450 ;
V_67 -> V_68 . V_495 . V_73 =
( V_32 -> V_162 == V_492 ) ?
V_496 : V_497 ;
if ( V_40 && F_24 ( V_40 ) ) {
memcpy ( & V_67 -> V_68 . V_495 . V_75 ,
& V_40 -> V_76 ,
sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_495 . V_78 ,
& V_40 -> V_79 ,
sizeof( struct V_77 ) ) ;
}
V_67 -> V_5 = V_5 ;
V_67 -> V_82 . V_83 =
V_84 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
F_25 ( & V_67 -> V_82 . V_86 ,
& V_8 -> V_87 ) ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_26 ( V_8 ) ;
break;
case V_482 :
case V_498 :
if ( V_32 -> V_48 == V_499 ||
V_32 -> V_48 ==
V_500 ||
V_32 -> V_48 == V_501 ||
V_32 -> V_48 ==
V_502 ) {
V_41 -> V_48 = F_127 ( V_503 , 0 ) ;
break;
}
if ( V_32 -> V_48 == V_504 ||
V_32 -> V_48 == V_505 ||
V_32 -> V_48 == V_506 ||
V_32 -> V_48 == V_507 ) {
V_41 -> V_48 = F_127 ( V_508 , 0 ) ;
break;
}
if ( ( V_32 -> V_48 == V_509 ||
V_32 -> V_48 == V_510 ) &&
V_403 -> V_120 . V_153 . V_406 . V_408 ) {
if ( F_104 ( V_41 ) != V_261 ) {
F_128 ( V_8 , V_32 ,
V_403 ) ;
break;
} else {
F_31 ( V_5 , V_96 ,
V_21 ,
L_83
L_84 ) ;
}
}
if ( ( V_32 -> V_162 == V_498 )
&& ( V_8 -> V_149 == V_489 )
&& ( V_40 && F_24 ( V_40 ) ) ) {
F_68 ( V_8 , V_40 ,
V_32 -> V_135 . V_187 ,
0 , 0 ) ;
}
default:
V_41 -> V_48 = F_127 ( V_412 , 0 ) ;
break;
}
if ( ! V_40 || ! F_24 ( V_40 )
|| ( V_40 -> V_511 != V_512 ) )
V_41 -> V_48 = F_127 ( V_494 ,
V_431 ) ;
} else
V_41 -> V_48 = F_127 ( V_457 , 0 ) ;
if ( V_41 -> V_48 || V_32 -> V_129 -> V_436 ) {
T_2 * V_455 = ( T_2 * ) V_41 -> V_395 ;
F_31 ( V_5 , V_130 , V_97 ,
L_85
L_86 ,
V_41 -> V_26 -> V_464 , V_41 -> V_26 -> V_63 , V_41 ,
V_41 -> V_48 , * V_455 , * ( V_455 + 3 ) , V_41 -> V_513 ,
F_146 ( V_41 ) ) ;
}
F_18 ( V_8 , V_32 ) ;
V_48 = V_41 -> V_48 ;
if ( V_5 -> V_514 &&
F_38 ( V_49 , V_32 -> V_50 +
F_149 ( V_5 -> V_514 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_40 && F_24 ( V_40 ) ) {
if ( V_40 -> V_515 >
F_40 ( & V_40 -> V_481 ) &&
( F_40 ( & V_40 -> V_481 ) >
V_516 ) &&
( ( V_41 -> V_14 [ 0 ] == V_437 ) ||
( V_41 -> V_14 [ 0 ] == V_438 ) ) )
V_40 -> V_515 =
F_40 ( & V_40 -> V_481 ) ;
V_40 -> V_517 = V_49 ;
}
F_21 ( V_45 -> V_51 , V_43 ) ;
} else if ( V_40 && F_24 ( V_40 ) ) {
if ( ( V_40 -> V_515 < V_5 -> V_518 ) &&
F_38 ( V_49 , V_40 -> V_517 +
F_149 ( V_519 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
V_474 = V_40 -> V_515 * V_520
/ 100 ;
V_474 = V_474 ? V_474 : 1 ;
V_40 -> V_515 += V_474 ;
if ( V_40 -> V_515 > V_5 -> V_518 )
V_40 -> V_515 = V_5 -> V_518 ;
V_40 -> V_517 = V_49 ;
F_21 ( V_45 -> V_51 , V_43 ) ;
}
}
F_143 ( V_8 , V_32 ) ;
V_92 = V_41 -> V_26 -> V_92 ;
V_475 = V_41 -> V_26 -> V_464 ;
V_41 -> V_521 ( V_41 ) ;
if ( V_8 -> V_522 & V_523 ) {
F_20 ( & V_8 -> V_85 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_524 )
F_150 ( V_32 -> V_524 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_92 ( V_8 , V_32 ) ;
return;
}
F_20 ( & V_8 -> V_85 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_524 )
F_150 ( V_32 -> V_524 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_92 ( V_8 , V_32 ) ;
}
static void
F_151 ( V_222 * V_132 , struct V_128 * V_128 )
{
int V_47 , V_525 ;
for ( V_47 = 0 , V_525 = 0 ; V_47 < sizeof( struct V_128 ) ;
V_47 += sizeof( T_2 ) , V_525 ++ ) {
( ( T_2 * ) V_132 ) [ V_525 ] = F_101 ( ( ( T_2 * ) V_128 ) [ V_525 ] ) ;
}
}
static void
F_152 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_128 * V_128 = V_32 -> V_128 ;
T_3 * V_234 = & V_32 -> V_135 . V_120 ;
struct V_175 * V_526 = & ( V_32 -> V_135 ) ;
int V_240 = V_13 -> V_241 ;
char V_527 [ 2 ] ;
V_222 * V_528 ;
bool V_529 ;
T_2 V_371 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return;
V_32 -> V_129 -> V_436 = 0 ;
V_32 -> V_128 -> V_461 = 0 ;
F_153 ( V_32 -> V_42 -> V_26 -> V_63 ,
& V_32 -> V_128 -> V_530 ) ;
V_528 = & V_128 -> V_531 [ 0 ] ;
memcpy ( V_528 , V_13 -> V_14 , V_13 -> V_532 ) ;
if ( V_13 -> V_532 < V_533 ) {
V_528 += V_13 -> V_532 ;
memset ( V_528 , 0 , ( V_533 - V_13 -> V_532 ) ) ;
}
if ( F_154 ( V_13 , V_527 ) ) {
switch ( V_527 [ 0 ] ) {
case V_534 :
V_128 -> V_535 = V_536 ;
break;
case V_537 :
V_128 -> V_535 = V_538 ;
break;
default:
V_128 -> V_535 = V_539 ;
break;
}
} else
V_128 -> V_535 = V_539 ;
V_529 = ( V_8 -> V_149 == V_489 ) ;
V_526 -> V_120 . V_68 . V_249 . V_540 = 0 ;
if ( F_94 ( V_13 ) ) {
if ( V_240 == V_327 ) {
V_234 -> V_541 = V_542 ;
V_234 -> V_543 = V_544 ;
if ( V_5 -> V_545 &&
( V_40 -> V_546 & V_547 ) ) {
V_371 = F_102 ( V_13 ) ;
if ( V_371 < V_5 -> V_545 )
V_526 -> V_120 . V_68 . V_249 . V_540 = V_371 ;
else
V_526 -> V_120 . V_68 . V_249 . V_540 =
V_5 -> V_545 ;
}
V_128 -> V_548 = V_549 ;
V_8 -> V_550 ++ ;
} else {
V_234 -> V_541 = V_551 ;
V_234 -> V_543 = V_544 ;
V_128 -> V_548 = V_552 ;
V_8 -> V_553 ++ ;
}
} else {
V_234 -> V_541 = V_554 ;
V_234 -> V_68 . V_249 . V_250 = 0 ;
V_234 -> V_543 = 0 ;
V_128 -> V_548 = 0 ;
V_8 -> V_555 ++ ;
}
if ( V_8 -> V_149 == 3 &&
! ( V_8 -> V_150 & V_151 ) )
F_151 ( V_234 -> V_153 . V_154 . V_155 , V_128 ) ;
V_526 -> V_120 . V_490 = V_40 -> V_556 ;
if ( V_529 )
V_526 -> V_120 . V_490 =
V_8 -> V_167 . V_557 [ V_40 -> V_556 ] ;
if ( V_40 -> V_558 & V_559 )
V_526 -> V_120 . V_560 = 1 ;
else
V_526 -> V_120 . V_560 = 0 ;
V_526 -> V_120 . V_160 = ( V_40 -> V_558 & 0x0f ) ;
V_526 -> V_164 = V_32 ;
V_526 -> V_561 = F_147 ;
V_526 -> V_120 . V_562 = V_32 -> V_563 ;
V_526 -> V_5 = V_5 ;
}
static int
F_155 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
T_1 V_63 ,
V_222 V_564 )
{
struct V_175 * V_526 ;
T_3 * V_565 ;
struct V_128 * V_128 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_62 = V_38 -> V_40 ;
if ( ! V_62 || ! F_24 ( V_62 ) ||
V_62 -> V_511 != V_512 )
return 0 ;
V_526 = & ( V_32 -> V_135 ) ;
V_526 -> V_5 = V_5 ;
V_565 = & V_526 -> V_120 ;
V_128 = V_32 -> V_128 ;
memset ( V_128 , 0 , sizeof( struct V_128 ) ) ;
F_153 ( V_63 , & V_128 -> V_530 ) ;
V_128 -> V_461 = V_564 ;
if ( V_5 -> V_8 -> V_149 == 3 &&
! ( V_5 -> V_8 -> V_150 & V_151 ) )
F_151 ( V_565 -> V_153 . V_154 . V_155 , V_128 ) ;
V_565 -> V_541 = V_554 ;
V_565 -> V_490 = V_62 -> V_556 ;
if ( V_5 -> V_8 -> V_149 == V_489 ) {
V_565 -> V_490 =
V_5 -> V_8 -> V_167 . V_557 [ V_62 -> V_556 ] ;
}
V_565 -> V_560 = ( V_62 -> V_558 & V_559 ) ? 1 : 0 ;
V_565 -> V_160 = ( V_62 -> V_558 & 0x0f ) ;
V_565 -> V_543 = 0 ;
V_565 -> V_68 . V_249 . V_250 = 0 ;
if ( V_32 -> V_563 > 0xff ) {
V_565 -> V_562 = 0 ;
} else
V_565 -> V_562 = V_32 -> V_563 ;
if ( V_5 -> V_8 -> V_149 == V_489 )
F_14 ( V_5 -> V_8 , V_32 ) ;
return 1 ;
}
int
F_156 ( struct V_12 * V_8 , V_222 V_566 )
{
V_8 -> F_143 = F_143 ;
V_8 -> F_152 = F_152 ;
switch ( V_566 ) {
case V_567 :
V_8 -> F_86 = F_50 ;
V_8 -> F_140 = F_93 ;
V_8 -> F_141 = F_118 ;
V_8 -> F_92 = F_59 ;
V_8 -> F_91 = F_87 ;
break;
case V_568 :
V_8 -> F_86 = F_83 ;
V_8 -> F_140 = F_137 ;
V_8 -> F_141 = F_139 ;
V_8 -> F_92 = F_70 ;
V_8 -> F_91 = F_89 ;
break;
default:
F_4 ( V_8 , V_20 , V_569 ,
L_87 ,
V_566 ) ;
return - V_570 ;
break;
}
V_8 -> F_36 = F_36 ;
V_8 -> F_147 = F_147 ;
return 0 ;
}
static void
F_157 ( struct V_12 * V_8 ,
struct V_175 * V_571 ,
struct V_175 * V_572 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_571 -> V_164 ;
if ( V_32 )
F_92 ( V_8 , V_32 ) ;
return;
}
const char *
F_158 ( struct V_44 * V_6 )
{
struct V_4 * V_5 = (struct V_4 * ) V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_385 , V_573 = 0 ;
static char V_574 [ 384 ] ;
memset ( V_574 , 0 , 384 ) ;
if ( V_8 && V_8 -> V_242 ) {
strncpy ( V_574 , V_8 -> V_575 , 256 ) ;
V_385 = strlen ( V_574 ) ;
snprintf ( V_574 + V_385 ,
384 - V_385 ,
L_88 ,
V_8 -> V_242 -> V_576 -> V_577 ,
V_8 -> V_242 -> V_578 ,
V_8 -> V_242 -> V_579 ) ;
V_385 = strlen ( V_574 ) ;
if ( V_8 -> V_580 [ 0 ] ) {
snprintf ( V_574 + V_385 ,
384 - V_385 ,
L_89 ,
V_8 -> V_580 ) ;
}
V_385 = strlen ( V_574 ) ;
if ( V_8 -> V_149 <= V_581 ) {
V_573 = F_159 ( V_8 ) ;
} else {
if ( V_8 -> V_167 . V_582 . V_583 )
V_573 =
V_8 -> V_167 . V_582 . V_583 ;
else
V_573 = V_8 -> V_167 . V_582 . V_584 ;
}
if ( V_573 != 0 )
snprintf ( V_574 + V_385 , 384 - V_385 ,
L_90 , V_573 ) ;
}
return V_574 ;
}
static T_7 void F_160 ( struct V_12 * V_8 )
{
unsigned long V_585 =
( V_49 + F_149 ( V_8 -> V_586 ) ) ;
if ( ! F_67 ( & V_8 -> V_180 . V_181 [ V_587 ] . V_588 ) )
F_161 ( & V_8 -> V_589 ,
V_585 ) ;
}
void F_162 ( struct V_12 * V_8 )
{
F_160 ( V_8 ) ;
}
void F_163 ( unsigned long V_528 )
{
struct V_12 * V_8 = (struct V_12 * ) V_528 ;
if ( V_8 -> V_522 & V_523 ) {
F_164 ( V_8 ,
& V_8 -> V_180 . V_181 [ V_587 ] , V_590 ) ;
if ( V_8 -> V_522 & V_591 )
F_160 ( V_8 ) ;
}
}
static int
F_165 ( struct V_44 * V_45 , struct V_13 * V_14 )
{
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_1 * V_38 ;
struct V_39 * V_62 ;
struct V_31 * V_32 ;
struct V_114 * V_115 = F_47 ( F_48 ( V_14 -> V_26 ) ) ;
int V_374 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
V_374 = F_166 ( V_115 ) ;
if ( V_374 ) {
V_14 -> V_48 = V_374 ;
goto V_592;
}
V_62 = V_38 -> V_40 ;
if ( ( F_104 ( V_14 ) != V_261 ) &&
( ! ( V_8 -> V_150 & V_151 ) ) ) {
F_4 ( V_8 , V_20 , V_21 ,
L_91
L_92
L_93 ,
V_14 -> V_14 [ 0 ] , F_104 ( V_14 ) ,
V_593 [ F_104 ( V_14 ) ] ) ;
goto V_592;
}
if ( ! V_62 || ! F_24 ( V_62 ) )
goto V_594;
if ( F_40 ( & V_62 -> V_481 ) >= V_62 -> V_515 )
goto V_594;
V_32 = F_91 ( V_8 , V_62 ) ;
if ( V_32 == NULL ) {
F_36 ( V_8 ) ;
F_31 ( V_5 , V_130 , V_97 ,
L_94
L_95 ) ;
goto V_595;
}
V_32 -> V_42 = V_14 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_563 = 0 ;
V_32 -> V_50 = V_49 ;
V_14 -> V_269 = ( unsigned char * ) V_32 ;
if ( F_104 ( V_14 ) != V_261 ) {
if ( V_5 -> V_8 -> V_219 ) {
F_31 ( V_5 ,
V_130 , V_596 ,
L_96
L_97 ,
V_593 [ F_104 ( V_14 ) ] ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_14 ) ,
F_130 ( V_14 -> V_413 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_374 = F_141 ( V_8 , V_32 ) ;
} else {
if ( V_5 -> V_8 -> V_219 ) {
F_31 ( V_5 ,
V_130 , V_596 ,
L_98
L_99 ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_105 ( V_14 ) ,
F_130 ( V_14 -> V_413 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_374 = F_140 ( V_8 , V_32 ) ;
}
if ( V_374 )
goto V_597;
F_152 ( V_5 , V_32 , V_62 ) ;
F_37 ( & V_62 -> V_481 ) ;
V_374 = F_167 ( V_8 , V_587 ,
& V_32 -> V_135 , V_598 ) ;
if ( V_374 ) {
F_148 ( & V_62 -> V_481 ) ;
F_31 ( V_5 , V_130 , V_97 ,
L_100
L_101
L_82
L_102 ,
V_374 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_26 ? V_14 -> V_26 -> V_464 : 0xffff ,
V_14 -> V_26 ? V_14 -> V_26 -> V_63 : ( V_599 ) - 1 ,
V_5 -> V_488 , V_62 -> V_265 ,
V_8 -> V_149 == V_489 ?
V_32 -> V_135 . V_183 : 0xffff ,
V_32 -> V_135 . V_120 . V_490 ,
V_32 -> V_135 . V_120 . V_491 ,
V_32 -> V_135 . V_120 . V_562 ,
( T_2 )
( V_14 -> V_413 -> V_563 / 1000 ) ) ;
goto V_597;
}
if ( V_8 -> V_522 & V_523 ) {
F_164 ( V_8 ,
& V_8 -> V_180 . V_181 [ V_587 ] , V_590 ) ;
if ( V_8 -> V_522 & V_591 )
F_160 ( V_8 ) ;
}
return 0 ;
V_597:
F_143 ( V_8 , V_32 ) ;
F_92 ( V_8 , V_32 ) ;
V_595:
return V_600 ;
V_594:
return V_601 ;
V_592:
V_14 -> V_521 ( V_14 ) ;
return 0 ;
}
static int
F_168 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_175 * V_120 ;
struct V_175 * V_602 ;
struct V_31 * V_32 ;
T_3 * V_41 , * V_603 ;
int V_295 = V_604 , V_162 = 0 ;
struct V_178 * V_605 ;
int V_606 , V_607 ;
unsigned long V_43 , V_608 ;
F_169 ( V_524 ) ;
V_162 = F_170 ( V_14 ) ;
if ( V_162 != 0 && V_162 != V_604 )
return V_162 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
if ( V_8 -> V_609 & V_610 ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_103
L_104 ) ;
return V_611 ;
}
V_32 = (struct V_31 * ) V_14 -> V_269 ;
if ( ! V_32 || ! V_32 -> V_42 ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_105
L_106 ,
V_604 , V_14 -> V_26 -> V_464 , V_14 -> V_26 -> V_63 ) ;
return V_604 ;
}
V_120 = & V_32 -> V_135 ;
if ( ! ( V_120 -> V_136 & V_612 ) ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_107
L_108 ) ;
return V_611 ;
}
if ( V_32 -> V_42 != V_14 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_109
L_110 ) ;
goto V_613;
}
F_114 ( V_120 -> V_164 != V_32 ) ;
if ( V_120 -> V_136 & V_614 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_111 ) ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
goto V_615;
}
V_602 = F_171 ( V_8 ) ;
if ( V_602 == NULL ) {
V_295 = V_611 ;
goto V_613;
}
V_120 -> V_136 |= V_614 ;
V_41 = & V_120 -> V_120 ;
V_603 = & V_602 -> V_120 ;
V_603 -> V_68 . V_616 . V_617 = V_618 ;
V_603 -> V_68 . V_616 . V_619 = V_41 -> V_490 ;
if ( V_8 -> V_149 == V_489 )
V_603 -> V_68 . V_616 . V_620 = V_120 -> V_183 ;
else
V_603 -> V_68 . V_616 . V_620 = V_41 -> V_491 ;
V_603 -> V_157 = 1 ;
V_603 -> V_160 = V_41 -> V_160 ;
V_602 -> V_621 = V_120 -> V_621 ;
V_602 -> V_136 |= V_622 ;
if ( V_120 -> V_136 & V_420 )
V_602 -> V_136 |= V_420 ;
if ( F_172 ( V_8 ) )
V_603 -> V_541 = V_623 ;
else
V_603 -> V_541 = V_624 ;
V_602 -> V_561 = V_625 ;
V_602 -> V_5 = V_5 ;
if ( V_8 -> V_149 == V_489 ) {
V_606 = V_626 + V_120 -> V_621 ;
V_605 = & V_8 -> V_180 . V_181 [ V_606 ] ;
F_20 ( & V_605 -> V_627 , V_608 ) ;
V_607 = F_173 ( V_8 , V_605 -> V_628 ,
V_602 , 0 ) ;
F_21 ( & V_605 -> V_627 , V_608 ) ;
} else {
V_607 = F_173 ( V_8 , V_587 ,
V_602 , 0 ) ;
}
F_21 ( & V_8 -> V_85 , V_43 ) ;
if ( V_607 == V_629 ) {
F_174 ( V_8 , V_602 ) ;
V_295 = V_611 ;
goto V_310;
}
if ( V_8 -> V_522 & V_591 )
F_164 ( V_8 ,
& V_8 -> V_180 . V_181 [ V_587 ] , V_590 ) ;
V_615:
V_32 -> V_524 = & V_524 ;
F_175 ( V_524 ,
( V_32 -> V_42 != V_14 ) ,
F_149 ( 2 * V_5 -> V_630 * 1000 ) ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
V_32 -> V_524 = NULL ;
F_21 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_42 == V_14 ) {
V_295 = V_611 ;
F_31 ( V_5 , V_20 , V_97 ,
L_112
L_113
L_114 ,
V_120 -> V_183 , V_295 ,
V_14 -> V_26 -> V_464 , V_14 -> V_26 -> V_63 ) ;
}
goto V_310;
V_613:
F_21 ( & V_8 -> V_85 , V_43 ) ;
V_310:
F_31 ( V_5 , V_96 , V_97 ,
L_115
L_116 , V_295 , V_14 -> V_26 -> V_464 ,
V_14 -> V_26 -> V_63 ) ;
return V_295 ;
}
static char *
F_176 ( V_222 V_564 )
{
switch ( V_564 ) {
case V_631 :
return L_117 ;
case V_632 :
return L_118 ;
case V_633 :
return L_119 ;
case V_634 :
return L_120 ;
case V_635 :
return L_121 ;
case V_636 :
return L_122 ;
case V_637 :
return L_123 ;
default:
return L_124 ;
}
}
static int
F_177 ( struct V_4 * V_5 , struct V_31 * V_32 )
{
struct V_129 * V_425 = V_32 -> V_129 ;
T_2 V_638 ;
T_2 V_639 ;
V_222 V_640 ;
int V_295 = V_611 ;
if ( V_425 == NULL )
F_31 ( V_5 , V_130 , V_97 ,
L_125 ) ;
else {
V_638 = V_425 -> V_427 ;
V_639 = F_106 ( V_425 -> V_463 ) ;
V_640 = V_425 -> V_465 ;
F_31 ( V_5 , V_130 ,
V_97 ,
L_126
L_127 ,
V_638 ,
V_639 , V_640 ) ;
if ( ( V_425 -> V_427 & V_462 ) && ( V_639 == 8 ) ) {
switch ( V_640 ) {
case V_466 :
F_31 ( V_5 , V_130 , V_97 ,
L_128 ) ;
V_295 = V_604 ;
break;
case V_641 :
F_31 ( V_5 , V_130 , V_97 ,
L_129
L_130 ) ;
break;
case V_642 :
F_31 ( V_5 , V_130 , V_97 ,
L_131
L_132 ) ;
break;
case V_643 :
F_31 ( V_5 , V_130 , V_97 ,
L_133
L_134 ) ;
break;
}
}
}
return V_295 ;
}
static int
F_178 ( struct V_4 * V_5 , struct V_1 * V_38 ,
unsigned V_644 , T_1 V_645 ,
V_222 V_564 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_32 ;
struct V_175 * V_176 ;
struct V_175 * V_646 ;
struct V_39 * V_40 = V_38 -> V_40 ;
int V_295 ;
int V_162 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return V_611 ;
V_32 = F_91 ( V_8 , V_38 -> V_40 ) ;
if ( V_32 == NULL )
return V_611 ;
V_32 -> V_563 = V_8 -> V_647 ;
V_32 -> V_38 = V_38 ;
V_162 = F_155 ( V_5 , V_32 , V_645 ,
V_564 ) ;
if ( ! V_162 ) {
F_92 ( V_8 , V_32 ) ;
return V_611 ;
}
V_176 = & V_32 -> V_135 ;
V_646 = F_179 ( V_8 ) ;
if ( V_646 == NULL ) {
F_92 ( V_8 , V_32 ) ;
return V_611 ;
}
V_176 -> V_561 = F_157 ;
F_31 ( V_5 , V_130 , V_97 ,
L_135
L_136 ,
F_176 ( V_564 ) , V_644 , V_645 ,
V_40 -> V_556 , V_40 -> V_546 , V_176 -> V_183 ,
V_176 -> V_136 ) ;
V_162 = F_180 ( V_8 , V_587 ,
V_176 , V_646 , V_32 -> V_563 ) ;
if ( ( V_162 != V_648 ) ||
( V_646 -> V_120 . V_478 != V_163 ) ) {
F_31 ( V_5 , V_20 , V_97 ,
L_137
L_138 ,
F_176 ( V_564 ) ,
V_644 , V_645 , V_646 -> V_120 . V_478 ,
V_646 -> V_120 . V_68 . V_476 [ 4 ] ,
V_176 -> V_136 ) ;
if ( V_162 == V_648 ) {
if ( V_646 -> V_120 . V_478 == V_487 )
V_295 = F_177 ( V_5 , V_32 ) ;
else
V_295 = V_611 ;
} else if ( V_162 == V_649 ) {
V_295 = V_650 ;
} else {
V_295 = V_611 ;
}
V_32 -> V_162 = V_484 ;
} else
V_295 = V_604 ;
F_174 ( V_8 , V_646 ) ;
if ( V_295 != V_650 )
F_92 ( V_8 , V_32 ) ;
return V_295 ;
}
static int
F_181 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned long V_651 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_130 , V_97 ,
L_139 , V_38 ) ;
return V_611 ;
}
V_40 = V_38 -> V_40 ;
V_651 = F_149 ( 2 * V_5 -> V_630 * 1000 ) + V_49 ;
while ( F_38 ( V_651 , V_49 ) ) {
if ( ! V_40 || ! F_24 ( V_40 ) )
return V_611 ;
if ( V_40 -> V_511 == V_512 )
return V_604 ;
F_182 ( F_149 ( 500 ) ) ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 )
return V_611 ;
V_40 = V_38 -> V_40 ;
}
if ( ! V_40 || ! F_24 ( V_40 ) ||
( V_40 -> V_511 != V_512 ) )
return V_611 ;
return V_604 ;
}
static int
F_183 ( struct V_4 * V_5 , T_5 V_644 ,
T_1 V_645 , T_8 V_652 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_651 ;
int V_653 ;
V_653 = F_184 ( V_5 , V_644 , V_645 , V_652 ) ;
if ( V_653 )
F_185 ( V_5 ,
& V_8 -> V_180 . V_181 [ V_8 -> V_180 . V_654 ] ,
V_644 , V_645 , V_652 ) ;
V_651 = F_149 ( 2 * V_5 -> V_630 * 1000 ) + V_49 ;
while ( F_38 ( V_651 , V_49 ) && V_653 ) {
F_182 ( F_149 ( 20 ) ) ;
V_653 = F_184 ( V_5 , V_644 , V_645 , V_652 ) ;
}
if ( V_653 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_140 ,
( ( V_652 == V_655 ) ? L_141 :
( ( V_652 == V_656 ) ? L_142 :
( ( V_652 == V_657 ) ? L_143 : L_144 ) ) ) ,
V_653 ) ;
return V_611 ;
}
return V_604 ;
}
static int
F_186 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_644 = V_14 -> V_26 -> V_464 ;
T_1 V_645 = V_14 -> V_26 -> V_63 ;
struct V_658 V_70 ;
int V_162 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_145 , V_38 ) ;
return V_611 ;
}
V_40 = V_38 -> V_40 ;
V_162 = F_170 ( V_14 ) ;
if ( V_162 != 0 && V_162 != V_604 )
return V_162 ;
V_162 = F_181 ( V_5 , V_14 ) ;
if ( V_162 == V_611 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_146 , V_38 ) ;
return V_611 ;
}
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_659 ;
V_70 . V_63 = V_645 ;
memcpy ( V_70 . V_75 , & V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_40 -> V_79 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_660 ) ;
V_162 = F_178 ( V_5 , V_38 , V_644 , V_645 ,
V_634 ) ;
F_31 ( V_5 , V_20 , V_97 ,
L_147
L_148 , V_644 , V_645 , V_162 ) ;
if ( V_162 == V_604 )
V_162 = F_183 ( V_5 , V_644 , V_645 ,
V_655 ) ;
return V_162 ;
}
static int
F_189 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_644 = V_14 -> V_26 -> V_464 ;
T_1 V_645 = V_14 -> V_26 -> V_63 ;
struct V_658 V_70 ;
int V_162 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_149 , V_38 ) ;
return V_611 ;
}
V_40 = V_38 -> V_40 ;
V_162 = F_170 ( V_14 ) ;
if ( V_162 != 0 && V_162 != V_604 )
return V_162 ;
V_162 = F_181 ( V_5 , V_14 ) ;
if ( V_162 == V_611 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_150 , V_38 ) ;
F_80 ( V_45 -> V_51 ) ;
V_40 -> V_546 &= ~ V_661 ;
V_40 -> V_558 &= ~ V_559 ;
F_82 ( V_45 -> V_51 ) ;
F_183 ( V_5 , V_644 , V_645 ,
V_656 ) ;
return V_662 ;
}
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_663 ;
V_70 . V_63 = 0 ;
memcpy ( V_70 . V_75 , & V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_40 -> V_79 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_660 ) ;
V_162 = F_178 ( V_5 , V_38 , V_644 , V_645 ,
V_635 ) ;
F_31 ( V_5 , V_20 , V_97 ,
L_151
L_148 , V_644 , V_645 , V_162 ) ;
if ( V_162 == V_604 )
V_162 = F_183 ( V_5 , V_644 , V_645 ,
V_656 ) ;
return V_162 ;
}
static int
F_190 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_39 * V_62 = NULL ;
struct V_658 V_70 ;
int V_664 ;
int V_295 = V_604 , V_162 , V_47 ;
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_665 ;
V_70 . V_63 = 0 ;
memcpy ( V_70 . V_75 , & V_5 -> V_666 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_5 -> V_667 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_660 ) ;
V_162 = F_170 ( V_14 ) ;
if ( V_162 != 0 && V_162 != V_604 )
return V_162 ;
for ( V_47 = 0 ; V_47 < V_668 ; V_47 ++ ) {
V_664 = 0 ;
F_80 ( V_45 -> V_51 ) ;
F_191 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_24 ( V_62 ) )
continue;
if ( V_5 -> V_8 -> V_669 &&
( V_62 -> V_558 & V_559 ) )
continue;
if ( V_62 -> V_511 == V_512 &&
V_62 -> V_670 == V_47 &&
V_62 -> V_115 ) {
V_664 = 1 ;
break;
}
}
F_82 ( V_45 -> V_51 ) ;
if ( ! V_664 )
continue;
V_162 = F_178 ( V_5 , V_62 -> V_115 -> V_671 ,
V_47 , 0 , V_635 ) ;
if ( V_162 != V_604 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_152 ,
V_47 ) ;
V_295 = V_611 ;
}
}
V_162 = F_183 ( V_5 , 0 , 0 , V_657 ) ;
if ( V_162 != V_604 )
V_295 = V_611 ;
F_31 ( V_5 , V_20 , V_97 ,
L_153 , V_295 ) ;
return V_295 ;
}
static int
F_192 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_211 , V_295 = V_604 ;
F_31 ( V_5 , V_20 , V_97 ,
L_154 ) ;
F_193 ( V_8 , V_672 ) ;
F_194 ( V_8 ) ;
V_211 = F_195 ( V_8 ) ;
if ( V_211 )
V_295 = V_611 ;
V_211 = F_196 ( V_8 ) ;
if ( V_211 )
V_295 = V_611 ;
F_197 ( V_8 ) ;
if ( V_295 == V_611 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_155 ) ;
F_198 ( V_8 ) ;
}
return V_295 ;
}
static int
F_199 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_114 * V_115 = F_47 ( F_48 ( V_3 ) ) ;
T_2 V_673 = 0 ;
T_2 V_116 = 0 ;
int V_674 = 0 ;
T_2 V_675 ;
struct V_10 * V_676 ;
unsigned long V_43 ;
struct V_77 V_677 ;
if ( ! V_115 || F_166 ( V_115 ) )
return - V_678 ;
if ( V_8 -> V_9 ) {
F_200 ( V_115 -> V_679 , V_677 . V_267 . V_268 ) ;
F_20 ( & V_8 -> V_680 , V_43 ) ;
V_676 = F_201 ( V_8 ,
& V_8 -> V_681 ,
& V_5 -> V_666 ,
& V_677 ,
V_3 -> V_63 ) ;
if ( ! V_676 ) {
F_21 ( & V_8 -> V_680 , V_43 ) ;
V_676 = F_202 ( V_8 ,
& V_5 -> V_666 ,
& V_677 ,
V_3 -> V_63 , true ) ;
if ( ! V_676 )
return - V_682 ;
F_20 ( & V_8 -> V_680 , V_43 ) ;
F_25 ( & V_676 -> V_683 , & V_8 -> V_681 ) ;
}
V_676 -> V_11 = V_115 -> V_671 ;
V_676 -> V_684 = true ;
F_21 ( & V_8 -> V_680 , V_43 ) ;
V_3 -> V_7 = V_676 ;
} else {
V_3 -> V_7 = V_115 -> V_671 ;
}
V_675 = F_203 ( & V_8 -> V_675 ) ;
V_673 = V_8 -> V_685 ;
V_116 = V_5 -> V_686 + 2 ;
if ( ( V_675 * ( V_5 -> V_686 + 2 ) ) < V_673 )
return 0 ;
if ( V_673 >= V_8 -> V_687 - V_688 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_156
L_157 , V_673 ) ;
return 0 ;
} else if ( V_673 + V_116 >
V_8 -> V_687 - V_688 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_158
L_159
L_160 ,
V_116 , V_8 -> V_687 ,
( V_8 -> V_687 - V_673 ) ) ;
V_116 = V_8 -> V_687 - V_673 ;
}
V_674 = F_86 ( V_5 , V_116 ) ;
if ( V_116 != V_674 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_161
L_162
L_163 ,
V_116 , V_674 ) ;
}
if ( V_674 > 0 )
V_8 -> V_685 += V_674 ;
return 0 ;
}
static int
F_204 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
if ( V_3 -> V_100 )
F_34 ( V_3 , V_5 -> V_686 ) ;
else
F_35 ( V_3 , V_5 -> V_686 ) ;
if ( V_8 -> V_522 & V_523 ) {
F_164 ( V_8 ,
& V_8 -> V_180 . V_181 [ V_587 ] , V_590 ) ;
if ( V_8 -> V_522 & V_591 )
F_160 ( V_8 ) ;
}
return 0 ;
}
static void
F_205 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_43 ;
struct V_10 * V_676 = V_3 -> V_7 ;
F_148 ( & V_8 -> V_675 ) ;
if ( ( V_8 -> V_9 ) && ( V_676 ) ) {
F_20 ( & V_8 -> V_680 , V_43 ) ;
V_676 -> V_684 = false ;
if ( ! V_676 -> V_418 )
F_206 ( V_8 , V_676 ) ;
F_21 ( & V_8 -> V_680 , V_43 ) ;
}
V_3 -> V_7 = NULL ;
return;
}
struct V_10 *
F_202 ( struct V_12 * V_8 , struct V_77 * V_689 ,
struct V_77 * V_677 , T_1 V_63 ,
bool V_690 )
{
struct V_10 * V_691 ;
int V_692 ;
if ( F_96 ( ! V_8 ) || ! V_689 || ! V_677 ||
! ( V_8 -> V_9 ) )
return NULL ;
if ( V_690 )
V_692 = V_693 ;
else
V_692 = V_131 ;
V_691 = F_207 ( V_8 -> V_694 , V_692 ) ;
if ( ! V_691 )
return NULL ;
F_88 ( & V_691 -> V_683 ) ;
V_691 -> V_11 = NULL ;
memcpy ( & V_691 -> V_695 . V_689 , V_689 ,
sizeof( struct V_77 ) ) ;
memcpy ( & V_691 -> V_695 . V_677 , V_677 ,
sizeof( struct V_77 ) ) ;
V_691 -> V_695 . V_63 = V_63 ;
V_691 -> V_418 = false ;
V_691 -> V_684 = false ;
return V_691 ;
}
void
F_206 ( struct V_12 * V_8 ,
struct V_10 * V_691 )
{
if ( F_96 ( ! V_8 ) || ! V_691 ||
! ( V_8 -> V_9 ) )
return;
if ( ! F_67 ( & V_691 -> V_683 ) )
F_66 ( & V_691 -> V_683 ) ;
F_208 ( V_691 , V_8 -> V_694 ) ;
return;
}
struct V_10 *
F_201 ( struct V_12 * V_8 , struct V_192 * V_184 ,
struct V_77 * V_689 ,
struct V_77 * V_677 , T_1 V_63 )
{
struct V_10 * V_691 ;
if ( F_96 ( ! V_8 ) || ! V_184 || ! V_689 || ! V_677 ||
! V_8 -> V_9 )
return NULL ;
F_191 (lun_info, list, listentry) {
if ( ( memcmp ( & V_691 -> V_695 . V_689 , V_689 ,
sizeof( struct V_77 ) ) == 0 ) &&
( memcmp ( & V_691 -> V_695 . V_677 , V_677 ,
sizeof( struct V_77 ) ) == 0 ) &&
( V_691 -> V_695 . V_63 == V_63 ) )
return V_691 ;
}
return NULL ;
}
bool
F_209 ( struct V_12 * V_8 , struct V_77 * V_689 ,
struct V_77 * V_677 , T_1 * V_696 ,
struct V_77 * V_697 ,
struct V_77 * V_698 ,
T_1 * V_699 ,
T_2 * V_700 )
{
unsigned long V_43 ;
struct V_10 * V_691 ;
struct V_701 * V_695 ;
T_1 V_63 ;
bool V_228 = false ;
if ( F_96 ( ! V_8 ) || ! V_689 || ! V_677 ||
! V_696 || ! V_697 ||
! V_698 || ! V_699 || ! V_700 ||
( * V_696 == V_702 ) ||
! V_8 -> V_9 )
return false ;
V_63 = * V_696 ;
* V_699 = V_702 ;
* V_696 = V_702 ;
F_20 ( & V_8 -> V_680 , V_43 ) ;
F_191 (lun_info, &phba->luns, listentry) {
if ( ( ( F_210 ( V_689 -> V_267 . V_268 ) == 0 ) ||
( memcmp ( & V_691 -> V_695 . V_689 , V_689 ,
sizeof( struct V_77 ) ) == 0 ) ) &&
( ( F_210 ( V_677 -> V_267 . V_268 ) == 0 ) ||
( memcmp ( & V_691 -> V_695 . V_677 , V_677 ,
sizeof( struct V_77 ) ) == 0 ) ) &&
( V_691 -> V_418 ) ) {
V_695 = & V_691 -> V_695 ;
if ( ( ! V_228 ) &&
( ( V_63 == V_703 ) ||
( V_695 -> V_63 == V_63 ) ) ) {
* V_699 = V_695 -> V_63 ;
memcpy ( V_697 ,
& V_695 -> V_689 ,
sizeof( struct V_77 ) ) ;
memcpy ( V_698 ,
& V_695 -> V_677 ,
sizeof( struct V_77 ) ) ;
if ( V_691 -> V_684 )
* V_700 =
V_704 ;
else
* V_700 = 0 ;
if ( V_8 -> V_705 & V_706 )
memset ( V_689 , 0x0 ,
sizeof( struct V_77 ) ) ;
if ( V_8 -> V_705 & V_707 )
memset ( V_677 , 0x0 ,
sizeof( struct V_77 ) ) ;
V_228 = true ;
} else if ( V_228 ) {
* V_696 = V_695 -> V_63 ;
memcpy ( V_689 , & V_695 -> V_689 ,
sizeof( struct V_77 ) ) ;
memcpy ( V_677 , & V_695 -> V_677 ,
sizeof( struct V_77 ) ) ;
break;
}
}
}
F_21 ( & V_8 -> V_680 , V_43 ) ;
return V_228 ;
}
bool
F_211 ( struct V_12 * V_8 , struct V_77 * V_689 ,
struct V_77 * V_677 , T_1 V_63 )
{
struct V_10 * V_691 ;
unsigned long V_43 ;
if ( F_96 ( ! V_8 ) || ! V_689 || ! V_677 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_680 , V_43 ) ;
V_691 = F_201 ( V_8 , & V_8 -> V_681 , V_689 ,
V_677 , V_63 ) ;
if ( V_691 ) {
if ( ! V_691 -> V_418 )
V_691 -> V_418 = true ;
F_21 ( & V_8 -> V_680 , V_43 ) ;
return true ;
}
V_691 = F_202 ( V_8 , V_689 , V_677 , V_63 ,
false ) ;
if ( V_691 ) {
V_691 -> V_418 = true ;
V_691 -> V_684 = false ;
F_25 ( & V_691 -> V_683 , & V_8 -> V_681 ) ;
F_21 ( & V_8 -> V_680 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_680 , V_43 ) ;
return false ;
}
bool
F_212 ( struct V_12 * V_8 , struct V_77 * V_689 ,
struct V_77 * V_677 , T_1 V_63 )
{
struct V_10 * V_691 ;
unsigned long V_43 ;
if ( F_96 ( ! V_8 ) || ! V_689 || ! V_677 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_680 , V_43 ) ;
V_691 = F_201 ( V_8 ,
& V_8 -> V_681 , V_689 ,
V_677 , V_63 ) ;
if ( V_691 ) {
V_691 -> V_418 = false ;
if ( ! V_691 -> V_684 )
F_206 ( V_8 , V_691 ) ;
F_21 ( & V_8 -> V_680 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_680 , V_43 ) ;
return false ;
}
