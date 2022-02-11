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
T_1 V_64 ,
T_1 V_65 )
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
int
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
T_1 V_101 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
F_37 ( & V_8 -> V_102 ) ;
V_8 -> V_103 = V_49 ;
if ( ( V_8 -> V_104 + V_105 ) > V_49 ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
return;
}
V_8 -> V_104 = V_49 ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( & V_8 -> V_106 -> V_107 , V_43 ) ;
V_101 = V_8 -> V_106 -> V_108 & V_109 ;
if ( ! V_101 )
V_8 -> V_106 -> V_108 |= V_109 ;
F_21 ( & V_8 -> V_106 -> V_107 , V_43 ) ;
if ( ! V_101 )
F_26 ( V_8 ) ;
return;
}
void
F_38 ( struct V_12 * V_8 )
{
struct V_4 * * V_110 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
unsigned long V_90 ;
unsigned long V_102 , V_111 ;
int V_47 ;
V_102 = F_39 ( & V_8 -> V_102 ) ;
V_111 = F_39 ( & V_8 -> V_111 ) ;
if ( V_102 == 0 )
return;
V_110 = F_40 ( V_8 ) ;
if ( V_110 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_112 && V_110 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_41 ( V_110 [ V_47 ] ) ;
F_42 (sdev, shost) {
V_90 =
V_3 -> V_92 * V_102 /
( V_102 + V_111 ) ;
if ( ! V_90 )
V_90 = V_3 -> V_92 - 1 ;
else
V_90 = V_3 -> V_92 -
V_90 ;
F_27 ( V_3 , V_90 ,
V_93 ) ;
}
}
F_43 ( V_8 , V_110 ) ;
F_44 ( & V_8 -> V_102 , 0 ) ;
F_44 ( & V_8 -> V_111 , 0 ) ;
}
void
F_45 ( struct V_12 * V_8 )
{
struct V_4 * * V_110 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
struct V_113 * V_114 ;
int V_47 ;
V_110 = F_40 ( V_8 ) ;
if ( V_110 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_112 && V_110 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_41 ( V_110 [ V_47 ] ) ;
F_42 (sdev, shost) {
V_114 = F_46 ( F_47 ( V_3 ) ) ;
F_48 ( V_114 ) ;
}
}
F_43 ( V_8 , V_110 ) ;
}
static int
F_49 ( struct V_4 * V_5 , int V_115 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_116 ;
struct V_117 * V_118 ;
T_2 * V_119 ;
T_3 V_120 ;
T_3 V_121 ;
T_3 V_122 ;
T_4 V_123 ;
int V_124 , V_125 ;
V_125 = V_8 -> V_126 -
( sizeof( struct V_127 ) + sizeof( struct V_128 ) ) ;
F_31 ( V_5 , V_129 , V_97 ,
L_7 ,
V_115 , V_8 -> V_126 ,
( int ) sizeof( struct V_127 ) ,
( int ) sizeof( struct V_128 ) , V_125 ) ;
for ( V_124 = 0 ; V_124 < V_115 ; V_124 ++ ) {
V_116 = F_50 ( sizeof( struct V_31 ) , V_130 ) ;
if ( ! V_116 )
break;
V_116 -> V_131 = F_51 ( V_8 -> V_132 ,
V_130 , & V_116 -> V_133 ) ;
if ( ! V_116 -> V_131 ) {
F_52 ( V_116 ) ;
break;
}
memset ( V_116 -> V_131 , 0 , V_8 -> V_126 ) ;
V_123 = F_53 ( V_8 , & V_116 -> V_134 ) ;
if ( V_123 == 0 ) {
F_54 ( V_8 -> V_132 ,
V_116 -> V_131 , V_116 -> V_133 ) ;
F_52 ( V_116 ) ;
break;
}
V_116 -> V_134 . V_135 |= V_136 ;
V_116 -> V_127 = V_116 -> V_131 ;
V_116 -> V_128 = V_116 -> V_131 + sizeof( struct V_127 ) ;
V_116 -> V_35 = V_116 -> V_131 + sizeof( struct V_127 ) +
sizeof( struct V_128 ) ;
V_118 = V_116 -> V_35 ;
V_120 = V_116 -> V_133 ;
V_121 = V_116 -> V_133 + sizeof( struct V_127 ) ;
V_122 = V_116 -> V_133 + sizeof( struct V_127 ) +
sizeof( struct V_128 ) ;
V_118 [ 0 ] . V_137 = F_15 ( F_55 ( V_120 ) ) ;
V_118 [ 0 ] . V_138 = F_15 ( F_56 ( V_120 ) ) ;
V_118 [ 0 ] . V_139 . V_140 . V_141 = sizeof( struct V_127 ) ;
V_118 [ 0 ] . V_139 . V_140 . V_142 = V_143 ;
V_118 [ 0 ] . V_139 . V_144 = F_15 ( V_118 [ 0 ] . V_139 . V_144 ) ;
V_118 [ 1 ] . V_137 = F_15 ( F_55 ( V_121 ) ) ;
V_118 [ 1 ] . V_138 = F_15 ( F_56 ( V_121 ) ) ;
V_118 [ 1 ] . V_139 . V_140 . V_141 = sizeof( struct V_128 ) ;
V_118 [ 1 ] . V_139 . V_140 . V_142 = V_143 ;
V_118 [ 1 ] . V_139 . V_144 = F_15 ( V_118 [ 1 ] . V_139 . V_144 ) ;
V_119 = & V_116 -> V_134 . V_119 ;
V_119 -> V_68 . V_145 . V_146 . V_147 = 0 ;
if ( ( V_8 -> V_148 == 3 ) &&
! ( V_8 -> V_149 & V_150 ) ) {
V_119 -> V_68 . V_145 . V_146 . V_142 = V_151 ;
V_119 -> V_68 . V_145 . V_146 . V_141 = sizeof( struct V_127 ) ;
V_119 -> V_68 . V_145 . V_146 . V_138 = F_57 ( T_2 ,
V_152 . V_153 . V_154 ) ;
V_119 -> V_68 . V_145 . V_146 . V_137 = 0 ;
V_119 -> V_155 = 0 ;
V_119 -> V_156 = 0 ;
V_119 -> V_152 . V_153 . V_157 . V_139 . V_140 . V_142 =
V_143 ;
V_119 -> V_152 . V_153 . V_157 . V_139 . V_140 . V_141 =
sizeof( struct V_128 ) ;
V_119 -> V_152 . V_153 . V_157 . V_138 =
F_56 ( V_121 ) ;
V_119 -> V_152 . V_153 . V_157 . V_137 =
F_55 ( V_121 ) ;
} else {
V_119 -> V_68 . V_145 . V_146 . V_142 = V_158 ;
V_119 -> V_68 . V_145 . V_146 . V_141 =
( 2 * sizeof( struct V_117 ) ) ;
V_119 -> V_68 . V_145 . V_146 . V_138 =
F_56 ( V_122 ) ;
V_119 -> V_68 . V_145 . V_146 . V_137 =
F_55 ( V_122 ) ;
V_119 -> V_155 = 1 ;
V_119 -> V_156 = 1 ;
}
V_119 -> V_159 = V_160 ;
V_116 -> V_161 = V_162 ;
V_116 -> V_134 . V_163 = V_116 ;
F_58 ( V_8 , V_116 ) ;
}
return V_124 ;
}
void
F_59 ( struct V_4 * V_5 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_116 , * V_164 ;
unsigned long V_165 = 0 ;
F_20 ( & V_8 -> V_85 , V_165 ) ;
F_60 ( & V_8 -> V_166 . V_167 ) ;
F_61 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_116 -> V_38 && V_116 -> V_38 -> V_40
&& V_116 -> V_38 -> V_40 -> V_5 == V_5 )
V_116 -> V_38 = NULL ;
}
F_62 ( & V_8 -> V_166 . V_167 ) ;
F_21 ( & V_8 -> V_85 , V_165 ) ;
}
void
F_63 ( struct V_12 * V_8 ,
struct V_168 * V_169 )
{
T_4 V_170 = F_64 ( V_171 , V_169 ) ;
T_4 V_172 = F_64 ( V_173 , V_169 ) ;
struct V_31 * V_116 , * V_164 ;
unsigned long V_165 = 0 ;
struct V_174 * V_175 ;
int V_47 ;
struct V_39 * V_62 ;
int V_176 = 0 ;
struct V_177 * V_178 = & V_8 -> V_179 . V_180 [ V_181 ] ;
F_20 ( & V_8 -> V_85 , V_165 ) ;
F_60 ( & V_8 -> V_166 . V_167 ) ;
F_61 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_116 -> V_134 . V_182 == V_170 ) {
F_65 ( & V_116 -> V_183 ) ;
V_116 -> V_184 = 0 ;
V_116 -> V_161 = V_162 ;
F_62 (
& V_8 -> V_166 . V_167 ) ;
if ( V_116 -> V_38 && V_116 -> V_38 -> V_40 )
V_62 = V_116 -> V_38 -> V_40 ;
else
V_62 = NULL ;
V_176 = F_66 ( & V_8 -> V_185 ) ;
F_21 ( & V_8 -> V_85 , V_165 ) ;
if ( V_62 ) {
F_67 ( V_8 , V_62 ,
V_116 -> V_134 . V_186 , V_172 , 1 ) ;
F_68 ( V_8 , V_62 , V_169 ) ;
}
F_69 ( V_8 , V_116 ) ;
if ( V_176 )
F_26 ( V_8 ) ;
return;
}
}
F_62 ( & V_8 -> V_166 . V_167 ) ;
for ( V_47 = 1 ; V_47 <= V_8 -> V_179 . V_187 ; V_47 ++ ) {
V_175 = V_8 -> V_179 . V_188 [ V_47 ] ;
if ( ! ( V_175 -> V_135 & V_136 ) ||
( V_175 -> V_135 & V_189 ) )
continue;
if ( V_175 -> V_182 != V_170 )
continue;
V_116 = F_70 ( V_175 , struct V_31 , V_134 ) ;
V_116 -> V_184 = 0 ;
F_21 ( & V_8 -> V_85 , V_165 ) ;
if ( ! F_66 ( & V_178 -> V_190 ) )
F_26 ( V_8 ) ;
return;
}
F_21 ( & V_8 -> V_85 , V_165 ) ;
}
int
F_71 ( struct V_12 * V_8 ,
struct V_191 * V_192 , int V_193 )
{
struct V_31 * V_116 , * V_194 ;
int V_161 , V_195 ;
int V_196 = 0 , V_197 = 0 , V_198 = 0 , V_199 = 0 ;
T_3 V_200 ;
int V_201 = V_202 ;
F_72 ( V_203 ) ;
F_72 ( V_204 ) ;
F_72 ( V_205 ) ;
if ( V_193 <= 0 )
return - V_206 ;
V_195 = V_8 -> V_126 -
( sizeof( struct V_127 ) + sizeof( struct V_128 ) ) ;
F_61 (psb, psb_next, post_sblist, list) {
F_73 ( & V_116 -> V_183 ) ;
V_197 ++ ;
if ( ( V_201 != V_202 ) &&
( V_116 -> V_134 . V_182 != V_201 + 1 ) ) {
F_74 ( & V_203 , & V_204 ) ;
V_196 = V_197 - 1 ;
F_25 ( & V_116 -> V_183 , & V_203 ) ;
V_197 = 1 ;
} else {
F_25 ( & V_116 -> V_183 , & V_203 ) ;
if ( V_197 == V_207 ) {
F_74 ( & V_203 , & V_204 ) ;
V_196 = V_197 ;
V_197 = 0 ;
}
}
V_198 ++ ;
V_201 = V_116 -> V_134 . V_182 ;
if ( V_198 == V_193 ) {
if ( V_196 == 0 ) {
F_74 ( & V_203 , & V_204 ) ;
V_196 = V_197 ;
} else if ( V_197 == 1 ) {
if ( V_195 > V_208 )
V_200 = V_116 -> V_209 +
V_208 ;
else
V_200 = 0 ;
V_161 = F_75 ( V_8 ,
V_116 -> V_209 ,
V_200 ,
V_116 -> V_134 . V_182 ) ;
if ( V_161 ) {
V_116 -> V_184 = 1 ;
} else {
V_116 -> V_184 = 0 ;
V_116 -> V_161 = V_162 ;
V_199 ++ ;
}
F_25 ( & V_116 -> V_183 , & V_205 ) ;
}
}
if ( V_196 == 0 )
continue;
V_161 = F_76 ( V_8 , & V_204 ,
V_196 ) ;
if ( V_197 == 0 )
V_201 = V_202 ;
V_196 = 0 ;
while ( ! F_66 ( & V_204 ) ) {
F_77 ( & V_204 , V_116 ,
struct V_31 , V_183 ) ;
if ( V_161 ) {
V_116 -> V_184 = 1 ;
} else {
V_116 -> V_184 = 0 ;
V_116 -> V_161 = V_162 ;
V_199 ++ ;
}
F_25 ( & V_116 -> V_183 , & V_205 ) ;
}
}
while ( ! F_66 ( & V_205 ) ) {
F_77 ( & V_205 , V_116 ,
struct V_31 , V_183 ) ;
F_69 ( V_8 , V_116 ) ;
}
return V_199 ;
}
int
F_78 ( struct V_12 * V_8 )
{
F_72 ( V_192 ) ;
int V_199 , V_210 = 0 ;
F_79 ( & V_8 -> V_211 ) ;
F_60 ( & V_8 -> V_212 ) ;
F_74 ( & V_8 -> V_213 , & V_192 ) ;
F_80 ( & V_8 -> V_214 , & V_192 ) ;
F_62 ( & V_8 -> V_212 ) ;
F_81 ( & V_8 -> V_211 ) ;
if ( ! F_66 ( & V_192 ) ) {
V_199 = F_71 ( V_8 , & V_192 ,
V_8 -> V_166 . V_215 ) ;
if ( V_199 == 0 )
V_210 = - V_216 ;
}
return V_210 ;
}
static int
F_82 ( struct V_4 * V_5 , int V_115 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_116 ;
struct V_33 * V_34 ;
T_2 * V_119 ;
T_3 V_120 ;
T_3 V_121 ;
T_3 V_122 ;
T_4 V_123 , V_217 = 0 ;
int V_124 , V_199 , V_195 ;
F_72 ( V_203 ) ;
F_72 ( V_192 ) ;
F_72 ( V_205 ) ;
V_195 = V_8 -> V_126 -
( sizeof( struct V_127 ) + sizeof( struct V_128 ) ) ;
F_31 ( V_5 , V_129 , V_97 ,
L_8 ,
V_115 , V_8 -> V_126 , V_195 ,
( int ) sizeof( struct V_127 ) ,
( int ) sizeof( struct V_128 ) ) ;
for ( V_124 = 0 ; V_124 < V_115 ; V_124 ++ ) {
V_116 = F_50 ( sizeof( struct V_31 ) , V_130 ) ;
if ( ! V_116 )
break;
V_116 -> V_131 = F_51 ( V_8 -> V_132 ,
V_130 , & V_116 -> V_133 ) ;
if ( ! V_116 -> V_131 ) {
F_52 ( V_116 ) ;
break;
}
memset ( V_116 -> V_131 , 0 , V_8 -> V_126 ) ;
if ( V_8 -> V_218 && ( ( ( unsigned long ) ( V_116 -> V_131 ) &
( unsigned long ) ( V_219 - 1 ) ) != 0 ) ) {
F_54 ( V_8 -> V_132 ,
V_116 -> V_131 , V_116 -> V_133 ) ;
F_52 ( V_116 ) ;
break;
}
V_217 = F_83 ( V_8 ) ;
if ( V_217 == V_202 ) {
F_54 ( V_8 -> V_132 ,
V_116 -> V_131 , V_116 -> V_133 ) ;
F_52 ( V_116 ) ;
break;
}
V_123 = F_53 ( V_8 , & V_116 -> V_134 ) ;
if ( V_123 == 0 ) {
F_54 ( V_8 -> V_132 ,
V_116 -> V_131 , V_116 -> V_133 ) ;
F_52 ( V_116 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_9
L_10 , V_217 ) ;
F_84 ( V_8 , V_217 ) ;
break;
}
V_116 -> V_134 . V_186 = V_217 ;
V_116 -> V_134 . V_182 = V_8 -> V_166 . V_220 [ V_217 ] ;
V_116 -> V_134 . V_135 |= V_136 ;
V_116 -> V_35 = V_116 -> V_131 ;
V_116 -> V_127 = ( V_116 -> V_131 + V_195 ) ;
V_116 -> V_128 = (struct V_128 * ) ( ( V_221 * ) V_116 -> V_127 +
sizeof( struct V_127 ) ) ;
V_34 = (struct V_33 * ) V_116 -> V_35 ;
V_122 = V_116 -> V_133 ;
V_120 = ( V_116 -> V_133 + V_195 ) ;
V_121 = V_120 + sizeof( struct V_127 ) ;
V_34 -> V_222 = F_17 ( F_55 ( V_120 ) ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_120 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_224 = F_17 ( sizeof( struct V_127 ) ) ;
V_34 ++ ;
V_34 -> V_222 = F_17 ( F_55 ( V_121 ) ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_121 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_224 = F_17 ( sizeof( struct V_128 ) ) ;
V_119 = & V_116 -> V_134 . V_119 ;
V_119 -> V_68 . V_145 . V_146 . V_147 = 0 ;
V_119 -> V_68 . V_145 . V_146 . V_142 = V_143 ;
V_119 -> V_68 . V_145 . V_146 . V_141 = sizeof( struct V_127 ) ;
V_119 -> V_68 . V_145 . V_146 . V_138 = F_56 ( V_120 ) ;
V_119 -> V_68 . V_145 . V_146 . V_137 = F_55 ( V_120 ) ;
V_119 -> V_155 = 1 ;
V_119 -> V_156 = 1 ;
V_119 -> V_159 = V_160 ;
V_116 -> V_134 . V_163 = V_116 ;
V_116 -> V_209 = V_122 ;
F_25 ( & V_116 -> V_183 , & V_192 ) ;
F_79 ( & V_8 -> V_211 ) ;
V_8 -> V_166 . V_215 ++ ;
F_81 ( & V_8 -> V_211 ) ;
}
F_4 ( V_8 , V_129 , V_21 ,
L_11
L_12 , V_124 , V_115 ) ;
if ( ! F_66 ( & V_192 ) )
V_199 = F_71 ( V_8 ,
& V_192 , V_124 ) ;
else
V_199 = 0 ;
return V_199 ;
}
static inline int
F_85 ( struct V_4 * V_5 , int V_115 )
{
return V_5 -> V_8 -> F_85 ( V_5 , V_115 ) ;
}
static struct V_31 *
F_86 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
struct V_31 * V_32 = NULL ;
struct V_191 * V_225 = & V_8 -> V_213 ;
unsigned long V_165 = 0 ;
F_20 ( & V_8 -> V_211 , V_165 ) ;
F_77 ( V_225 , V_32 , struct V_31 ,
V_183 ) ;
if ( ! V_32 ) {
F_60 ( & V_8 -> V_212 ) ;
F_80 ( & V_8 -> V_214 ,
& V_8 -> V_213 ) ;
F_87 ( & V_8 -> V_214 ) ;
F_77 ( V_225 , V_32 ,
struct V_31 , V_183 ) ;
F_62 ( & V_8 -> V_212 ) ;
}
F_21 ( & V_8 -> V_211 , V_165 ) ;
return V_32 ;
}
static struct V_31 *
F_88 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
struct V_31 * V_32 , * V_226 ;
unsigned long V_165 = 0 ;
int V_227 = 0 ;
F_20 ( & V_8 -> V_211 , V_165 ) ;
F_61 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 ( V_8 , V_62 ,
V_32 -> V_134 . V_186 ) )
continue;
F_65 ( & V_32 -> V_183 ) ;
V_227 = 1 ;
break;
}
if ( ! V_227 ) {
F_60 ( & V_8 -> V_212 ) ;
F_80 ( & V_8 -> V_214 ,
& V_8 -> V_213 ) ;
F_87 ( & V_8 -> V_214 ) ;
F_62 ( & V_8 -> V_212 ) ;
F_61 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 (
V_8 , V_62 , V_32 -> V_134 . V_186 ) )
continue;
F_65 ( & V_32 -> V_183 ) ;
V_227 = 1 ;
break;
}
}
F_21 ( & V_8 -> V_211 , V_165 ) ;
if ( ! V_227 )
return NULL ;
return V_32 ;
}
static struct V_31 *
F_90 ( struct V_12 * V_8 , struct V_39 * V_62 )
{
return V_8 -> F_90 ( V_8 , V_62 ) ;
}
static void
F_58 ( struct V_12 * V_8 , struct V_31 * V_116 )
{
unsigned long V_165 = 0 ;
V_116 -> V_228 = 0 ;
V_116 -> V_229 = 0 ;
V_116 -> V_230 = 0 ;
F_20 ( & V_8 -> V_212 , V_165 ) ;
V_116 -> V_42 = NULL ;
V_116 -> V_134 . V_135 = V_136 ;
F_25 ( & V_116 -> V_183 , & V_8 -> V_214 ) ;
F_21 ( & V_8 -> V_212 , V_165 ) ;
}
static void
F_69 ( struct V_12 * V_8 , struct V_31 * V_116 )
{
unsigned long V_165 = 0 ;
V_116 -> V_228 = 0 ;
V_116 -> V_229 = 0 ;
V_116 -> V_230 = 0 ;
if ( V_116 -> V_184 ) {
F_20 ( & V_8 -> V_166 . V_167 ,
V_165 ) ;
V_116 -> V_42 = NULL ;
F_25 ( & V_116 -> V_183 ,
& V_8 -> V_166 . V_231 ) ;
F_21 ( & V_8 -> V_166 . V_167 ,
V_165 ) ;
} else {
V_116 -> V_42 = NULL ;
V_116 -> V_134 . V_135 = V_136 ;
F_20 ( & V_8 -> V_212 , V_165 ) ;
F_25 ( & V_116 -> V_183 , & V_8 -> V_214 ) ;
F_21 ( & V_8 -> V_212 , V_165 ) ;
}
}
static void
F_91 ( struct V_12 * V_8 , struct V_31 * V_116 )
{
V_8 -> F_91 ( V_8 , V_116 ) ;
}
static int
F_92 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_232 = NULL ;
struct V_127 * V_127 = V_32 -> V_127 ;
struct V_117 * V_118 = V_32 -> V_35 ;
struct V_174 * V_175 = & V_32 -> V_134 ;
T_2 * V_233 = & V_32 -> V_134 . V_119 ;
struct V_117 * V_234 = V_233 -> V_152 . V_153 . V_235 ;
T_3 V_236 ;
T_1 V_237 = 0 ;
int V_238 , V_239 = V_13 -> V_240 ;
V_118 += 2 ;
if ( F_93 ( V_13 ) ) {
V_238 = F_94 ( & V_8 -> V_241 -> V_242 , F_3 ( V_13 ) ,
F_93 ( V_13 ) , V_239 ) ;
if ( F_95 ( ! V_238 ) )
return 1 ;
V_32 -> V_228 = V_238 ;
if ( V_32 -> V_228 > V_8 -> V_243 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_13
L_14 ,
V_22 , V_8 -> V_243 ,
V_32 -> V_228 ) ;
V_32 -> V_228 = 0 ;
F_96 ( V_13 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_236 = F_98 ( V_232 ) ;
if ( V_8 -> V_148 == 3 &&
! ( V_8 -> V_149 & V_150 ) &&
! ( V_175 -> V_135 & V_244 ) &&
V_238 <= V_245 ) {
V_234 -> V_139 . V_140 . V_142 = V_143 ;
V_234 -> V_139 . V_140 . V_141 = F_99 ( V_232 ) ;
V_234 -> V_138 = F_56 ( V_236 ) ;
V_234 -> V_137 = F_55 ( V_236 ) ;
V_234 ++ ;
} else {
V_118 -> V_139 . V_140 . V_142 = V_143 ;
V_118 -> V_139 . V_140 . V_141 = F_99 ( V_232 ) ;
V_118 -> V_139 . V_144 = F_15 ( V_118 -> V_139 . V_144 ) ;
V_118 -> V_138 =
F_15 ( F_56 ( V_236 ) ) ;
V_118 -> V_137 =
F_15 ( F_55 ( V_236 ) ) ;
V_118 ++ ;
}
}
}
if ( V_8 -> V_148 == 3 &&
! ( V_8 -> V_149 & V_150 ) &&
! ( V_175 -> V_135 & V_244 ) ) {
if ( V_237 > V_245 ) {
V_236 = V_32 -> V_133 ;
V_234 -> V_139 . V_140 . V_142 = V_158 ;
V_234 -> V_139 . V_140 . V_141 = ( V_237 *
sizeof( struct V_117 ) ) ;
V_236 += ( sizeof( struct V_127 ) +
sizeof( struct V_128 ) +
( 2 * sizeof( struct V_117 ) ) ) ;
V_234 -> V_137 = F_55 ( V_236 ) ;
V_234 -> V_138 = F_56 ( V_236 ) ;
V_233 -> V_152 . V_153 . V_246 = 2 ;
} else {
V_233 -> V_152 . V_153 . V_246 = ( V_237 + 1 ) ;
}
} else {
V_233 -> V_68 . V_145 . V_146 . V_141 =
( ( V_237 + 2 ) * sizeof( struct V_117 ) ) ;
V_233 -> V_152 . V_153 . V_246 = ( V_237 + 1 ) ;
}
V_127 -> V_247 = F_100 ( F_101 ( V_13 ) ) ;
V_233 -> V_68 . V_248 . V_249 = F_101 ( V_13 ) ;
return 0 ;
}
static int
F_102 ( struct V_12 * V_8 , struct V_13 * V_25 ,
T_1 * V_250 , T_4 * V_251 , T_1 V_252 )
{
struct V_17 * V_253 ;
struct V_17 * V_18 ;
struct V_31 * V_32 = NULL ;
struct V_254 * V_15 = NULL ;
struct V_39 * V_62 ;
struct V_1 * V_38 ;
T_1 V_255 = F_103 ( V_25 ) ;
T_1 V_256 ;
T_1 V_257 ;
T_5 V_258 ;
int V_210 = 0 ;
int V_259 = 0 ;
if ( V_255 == V_260 )
return 0 ;
V_253 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
V_258 = F_104 ( V_25 ) ;
if ( V_8 -> V_261 != V_262 ) {
V_256 = F_9 ( V_25 ) ;
V_257 = ( F_101 ( V_25 ) + V_256 - 1 ) / V_256 ;
if ( ( V_8 -> V_261 < V_258 ) ||
( V_8 -> V_261 >= ( V_258 + V_257 ) ) )
return 0 ;
if ( V_253 ) {
V_259 = V_8 -> V_261 - V_258 ;
V_257 = F_99 ( V_253 ) /
sizeof( struct V_254 ) ;
if ( V_257 < V_259 )
V_259 = V_257 ;
}
}
V_38 = F_1 ( V_25 -> V_26 ) ;
if ( V_38 && V_38 -> V_40 ) {
V_62 = V_38 -> V_40 ;
if ( V_8 -> V_263 &&
( V_8 -> V_263 != V_62 -> V_264 ) )
return 0 ;
if ( V_8 -> V_265 . V_266 . V_267 [ 0 ] &&
( memcmp ( & V_62 -> V_76 , & V_8 -> V_265 ,
sizeof( struct V_77 ) ) != 0 ) )
return 0 ;
}
if ( V_253 ) {
V_15 = (struct V_254 * ) F_5 ( V_253 ) ;
V_15 += V_259 ;
V_32 = (struct V_31 * ) V_25 -> V_268 ;
}
if ( V_250 ) {
if ( V_8 -> V_269 ) {
switch ( V_255 ) {
case V_270 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_15
L_16 ,
( unsigned long ) V_258 , V_259 ,
F_105 ( V_15 -> V_271 ) ) ;
if ( V_32 ) {
V_32 -> V_272 =
V_273 ;
V_32 -> V_274 =
V_15 ;
V_32 -> V_275 =
V_15 -> V_271 ;
}
V_15 -> V_271 = F_100 ( 0xDEADBEEF ) ;
V_8 -> V_269 -- ;
if ( V_8 -> V_269 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_276 | V_277 ;
break;
}
case V_278 :
* V_250 = 0xDEADBEEF ;
V_8 -> V_269 -- ;
if ( V_8 -> V_269 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_276 | V_277 ;
F_4 ( V_8 , V_20 , V_21 ,
L_17
L_18 , ( unsigned long ) V_258 ) ;
break;
case V_279 :
* V_250 = 0xDEADBEEF ;
V_8 -> V_269 -- ;
if ( V_8 -> V_269 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 ;
F_4 ( V_8 , V_20 , V_21 ,
L_19
L_18 , ( unsigned long ) V_258 ) ;
break;
}
}
if ( V_8 -> V_281 ) {
switch ( V_255 ) {
case V_282 :
case V_283 :
case V_284 :
* V_250 = 0xDEADBEEF ;
V_8 -> V_281 -- ;
if ( V_8 -> V_281 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 ;
F_4 ( V_8 , V_20 , V_21 ,
L_20
L_21 , ( unsigned long ) V_258 ) ;
break;
}
}
}
if ( V_251 ) {
if ( V_8 -> V_285 ) {
switch ( V_255 ) {
case V_270 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_22
L_23 ,
( unsigned long ) V_258 , V_259 ,
F_106 ( V_15 -> V_286 ) ) ;
if ( V_32 ) {
V_32 -> V_272 =
V_287 ;
V_32 -> V_274 =
V_15 ;
V_32 -> V_275 =
V_15 -> V_286 ;
}
V_15 -> V_286 = F_107 ( 0xDEAD ) ;
V_8 -> V_285 -- ;
if ( V_8 -> V_285 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_276 | V_277 ;
break;
}
case V_278 :
* V_251 = 0xDEAD ;
V_8 -> V_285 -- ;
if ( V_8 -> V_285 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_276 | V_277 ;
F_4 ( V_8 , V_20 , V_21 ,
L_24
L_18 , ( unsigned long ) V_258 ) ;
break;
case V_279 :
* V_251 = 0xDEAD ;
V_8 -> V_285 -- ;
if ( V_8 -> V_285 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 ;
F_4 ( V_8 , V_20 , V_21 ,
L_25
L_18 , ( unsigned long ) V_258 ) ;
break;
}
}
if ( V_8 -> V_288 ) {
switch ( V_255 ) {
case V_282 :
case V_283 :
case V_284 :
* V_251 = 0xDEAD ;
V_8 -> V_288 -- ;
if ( V_8 -> V_288 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 ;
F_4 ( V_8 , V_20 , V_21 ,
L_26
L_21 , ( unsigned long ) V_258 ) ;
break;
}
}
}
if ( V_252 ) {
if ( V_8 -> V_289 ) {
switch ( V_255 ) {
case V_270 :
V_210 = V_277 ;
case V_278 :
V_8 -> V_289 -- ;
if ( V_8 -> V_289 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 |= V_276 | V_290 ;
F_4 ( V_8 , V_20 , V_21 ,
L_27
L_18 , ( unsigned long ) V_258 ) ;
break;
case V_279 :
V_8 -> V_289 -- ;
if ( V_8 -> V_289 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 | V_290 ;
F_4 ( V_8 , V_20 , V_21 ,
L_28
L_18 , ( unsigned long ) V_258 ) ;
break;
}
}
if ( V_8 -> V_291 ) {
switch ( V_255 ) {
case V_282 :
case V_283 :
case V_284 :
V_8 -> V_291 -- ;
if ( V_8 -> V_291 == 0 ) {
V_8 -> V_263 = 0 ;
V_8 -> V_261 =
V_262 ;
memset ( & V_8 -> V_265 ,
0 , sizeof( struct V_77 ) ) ;
}
V_210 = V_280 | V_290 ;
F_4 ( V_8 , V_20 , V_21 ,
L_29
L_21 , ( unsigned long ) V_258 ) ;
}
}
}
return V_210 ;
}
static int
F_108 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_221 * V_292 , V_221 * V_293 )
{
V_221 V_294 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_103 ( V_25 ) ) {
case V_282 :
case V_279 :
* V_293 = V_295 ;
* V_292 = V_296 ;
break;
case V_283 :
case V_278 :
* V_293 = V_297 ;
* V_292 = V_298 ;
break;
case V_284 :
case V_270 :
* V_293 = V_299 ;
* V_292 = V_300 ;
break;
case V_260 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_30 ,
F_103 ( V_25 ) ) ;
V_294 = 1 ;
break;
}
} else {
switch ( F_103 ( V_25 ) ) {
case V_283 :
case V_278 :
* V_293 = V_297 ;
* V_292 = V_298 ;
break;
case V_284 :
case V_270 :
* V_293 = V_301 ;
* V_292 = V_301 ;
break;
case V_282 :
case V_279 :
* V_293 = V_298 ;
* V_292 = V_297 ;
break;
case V_260 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_31 ,
F_103 ( V_25 ) ) ;
V_294 = 1 ;
break;
}
}
return V_294 ;
}
static int
F_109 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_221 * V_292 , V_221 * V_293 )
{
V_221 V_294 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_103 ( V_25 ) ) {
case V_282 :
case V_279 :
* V_293 = V_298 ;
* V_292 = V_297 ;
break;
case V_283 :
case V_278 :
* V_293 = V_296 ;
* V_292 = V_295 ;
break;
case V_284 :
case V_270 :
* V_293 = V_300 ;
* V_292 = V_299 ;
break;
case V_260 :
default:
break;
}
} else {
switch ( F_103 ( V_25 ) ) {
case V_283 :
case V_278 :
* V_293 = V_296 ;
* V_292 = V_295 ;
break;
case V_284 :
case V_270 :
* V_293 = V_302 ;
* V_292 = V_302 ;
break;
case V_282 :
case V_279 :
* V_293 = V_295 ;
* V_292 = V_296 ;
break;
case V_260 :
default:
break;
}
}
return V_294 ;
}
static int
F_110 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_117 * V_118 , int V_303 )
{
struct V_17 * V_18 = NULL ;
struct V_304 * V_305 = NULL ;
struct V_306 * V_307 = NULL ;
T_3 V_236 ;
int V_47 = 0 , V_237 = 0 , V_161 ;
int V_239 = V_25 -> V_240 ;
#ifdef F_111
T_1 V_210 ;
#endif
T_1 V_308 = 1 ;
T_1 V_250 ;
unsigned V_256 ;
V_221 V_292 , V_293 ;
V_161 = F_108 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_161 )
goto V_309;
V_256 = F_9 ( V_25 ) ;
V_250 = ( T_1 ) F_104 ( V_25 ) ;
#ifdef F_111
V_210 = F_102 ( V_8 , V_25 , & V_250 , NULL , 1 ) ;
if ( V_210 ) {
if ( V_210 & V_290 )
F_109 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_210 & V_277 )
V_308 = 0 ;
}
#endif
V_305 = (struct V_304 * ) V_118 ;
memset ( V_305 , 0 , sizeof( struct V_304 ) ) ;
F_16 ( V_310 , V_305 , V_311 ) ;
V_305 -> V_312 = F_17 ( V_305 -> V_312 ) ;
V_305 -> V_250 = F_17 ( V_250 ) ;
V_237 ++ ;
V_118 ++ ;
V_307 = (struct V_306 * ) V_118 ;
memset ( V_307 , 0 , sizeof( struct V_306 ) ) ;
F_16 ( V_313 , V_307 , V_314 ) ;
F_16 ( V_315 , V_307 , V_292 ) ;
F_16 ( V_316 , V_307 , V_293 ) ;
if ( V_239 == V_317 ) {
if ( F_10 ( V_25 , V_318 ) )
F_16 ( V_319 , V_307 , V_308 ) ;
else
F_16 ( V_319 , V_307 , 0 ) ;
if ( F_10 ( V_25 , V_320 ) )
F_16 ( V_321 , V_307 , V_308 ) ;
else
F_16 ( V_321 , V_307 , 0 ) ;
}
F_16 ( V_322 , V_307 , 1 ) ;
F_16 ( V_323 , V_307 , 0 ) ;
F_16 ( V_324 , V_307 , 0 ) ;
V_307 -> V_312 = F_17 ( V_307 -> V_312 ) ;
V_307 -> V_325 = F_17 ( V_307 -> V_325 ) ;
V_307 -> V_36 = F_17 ( V_307 -> V_36 ) ;
V_237 ++ ;
V_118 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_236 = F_98 ( V_18 ) ;
V_118 -> V_138 = F_15 ( F_56 ( V_236 ) ) ;
V_118 -> V_137 = F_15 ( F_55 ( V_236 ) ) ;
V_118 -> V_139 . V_140 . V_141 = F_99 ( V_18 ) ;
if ( V_239 == V_326 )
V_118 -> V_139 . V_140 . V_142 = V_143 ;
else
V_118 -> V_139 . V_140 . V_142 = V_327 ;
V_118 -> V_139 . V_144 = F_15 ( V_118 -> V_139 . V_144 ) ;
V_118 ++ ;
V_237 ++ ;
}
V_309:
return V_237 ;
}
static int
F_112 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_117 * V_118 , int V_328 , int V_329 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_253 = NULL ;
struct V_304 * V_305 = NULL ;
struct V_306 * V_307 = NULL ;
struct V_330 * V_331 = NULL ;
T_3 V_332 , V_333 ;
unsigned short V_334 = 0 , V_335 = 0 ;
unsigned int V_336 ;
unsigned int V_337 , V_338 = 0 , V_339 ;
unsigned int V_340 , V_341 ;
unsigned int V_342 , V_343 ;
int V_161 ;
int V_239 = V_25 -> V_240 ;
unsigned char V_344 = 0 , V_345 = 0 ;
unsigned V_256 ;
#ifdef F_111
T_1 V_210 ;
#endif
T_1 V_308 = 1 ;
T_1 V_250 ;
V_221 V_292 , V_293 ;
int V_237 = 0 ;
V_253 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_253 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_97 ,
L_32 ,
V_253 , V_18 ) ;
return 0 ;
}
V_161 = F_108 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_161 )
goto V_309;
V_256 = F_9 ( V_25 ) ;
V_250 = ( T_1 ) F_104 ( V_25 ) ;
#ifdef F_111
V_210 = F_102 ( V_8 , V_25 , & V_250 , NULL , 1 ) ;
if ( V_210 ) {
if ( V_210 & V_290 )
F_109 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_210 & V_277 )
V_308 = 0 ;
}
#endif
V_336 = 0 ;
do {
if ( V_237 >= ( V_8 -> V_346 - 2 ) )
return V_237 + 3 ;
V_305 = (struct V_304 * ) V_118 ;
memset ( V_305 , 0 , sizeof( struct V_304 ) ) ;
F_16 ( V_310 , V_305 , V_311 ) ;
V_305 -> V_312 = F_17 ( V_305 -> V_312 ) ;
V_305 -> V_250 = F_17 ( V_250 ) ;
V_237 ++ ;
V_118 ++ ;
V_307 = (struct V_306 * ) V_118 ;
memset ( V_307 , 0 , sizeof( struct V_306 ) ) ;
F_16 ( V_313 , V_307 , V_314 ) ;
F_16 ( V_315 , V_307 , V_292 ) ;
F_16 ( V_316 , V_307 , V_293 ) ;
if ( F_10 ( V_25 , V_318 ) )
F_16 ( V_319 , V_307 , V_308 ) ;
else
F_16 ( V_319 , V_307 , 0 ) ;
if ( F_10 ( V_25 , V_320 ) )
F_16 ( V_321 , V_307 , V_308 ) ;
else
F_16 ( V_321 , V_307 , 0 ) ;
F_16 ( V_322 , V_307 , 1 ) ;
F_16 ( V_323 , V_307 , 0 ) ;
F_16 ( V_324 , V_307 , 0 ) ;
V_307 -> V_312 = F_17 ( V_307 -> V_312 ) ;
V_307 -> V_325 = F_17 ( V_307 -> V_325 ) ;
V_307 -> V_36 = F_17 ( V_307 -> V_36 ) ;
V_237 ++ ;
V_118 ++ ;
V_333 = F_98 ( V_253 ) + V_338 ;
V_337 = F_99 ( V_253 ) - V_338 ;
F_113 ( V_337 % 8 ) ;
V_331 = (struct V_330 * ) V_118 ;
memset ( V_331 , 0 , sizeof( struct V_330 ) ) ;
F_16 ( V_347 , V_331 , V_348 ) ;
V_331 -> V_137 = F_15 ( F_55 ( V_333 ) ) ;
V_331 -> V_138 = F_15 ( F_56 ( V_333 ) ) ;
V_340 = V_337 / 8 ;
V_341 = V_340 * V_256 ;
if ( ( V_331 -> V_138 & 0xfff ) + V_337 > 0x1000 ) {
V_339 = 0x1000 - ( V_331 -> V_138 & 0xfff ) ;
V_338 += V_339 ;
V_340 = V_339 / 8 ;
V_341 = V_340 * V_256 ;
} else {
V_338 = 0 ;
V_335 ++ ;
}
V_237 ++ ;
V_344 = 0 ;
V_343 = 0 ;
while ( ! V_344 ) {
if ( V_237 >= V_8 -> V_346 )
return V_237 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_33 ,
V_22 ) ;
return 0 ;
}
V_118 ++ ;
V_332 = F_98 ( V_18 ) + V_336 ;
V_118 -> V_138 = F_15 ( F_56 ( V_332 ) ) ;
V_118 -> V_137 = F_15 ( F_55 ( V_332 ) ) ;
V_342 = F_99 ( V_18 ) - V_336 ;
if ( ( V_343 + V_342 ) <= V_341 ) {
V_118 -> V_139 . V_140 . V_141 = V_342 ;
V_336 = 0 ;
if ( ( V_343 + V_342 ) == V_341 )
V_344 = 1 ;
} else {
V_118 -> V_139 . V_140 . V_141 = V_341 - V_343 ;
V_336 += V_118 -> V_139 . V_140 . V_141 ;
}
V_343 += V_118 -> V_139 . V_140 . V_141 ;
if ( V_239 == V_326 )
V_118 -> V_139 . V_140 . V_142 = V_143 ;
else
V_118 -> V_139 . V_140 . V_142 = V_327 ;
V_118 -> V_139 . V_144 = F_15 ( V_118 -> V_139 . V_144 ) ;
V_237 ++ ;
V_334 ++ ;
if ( V_336 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_338 ) {
V_250 += V_340 ;
V_118 ++ ;
continue;
}
if ( V_335 == V_329 ) {
V_345 = 1 ;
} else if ( V_335 < V_329 ) {
V_253 = F_6 ( V_253 ) ;
V_118 ++ ;
V_250 += V_340 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_34 , V_22 ) ;
}
} while ( ! V_345 );
V_309:
return V_237 ;
}
static int
F_114 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_303 )
{
struct V_17 * V_18 = NULL ;
struct V_349 * V_350 = NULL ;
T_3 V_236 ;
int V_47 = 0 , V_351 = 0 , V_161 ;
T_1 V_250 ;
unsigned V_256 ;
V_221 V_292 , V_293 ;
#ifdef F_111
T_1 V_210 ;
#endif
T_1 V_308 = 1 ;
T_1 V_352 ;
T_1 V_353 = 0 ;
V_161 = F_108 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_161 )
goto V_309;
V_256 = F_9 ( V_25 ) ;
V_250 = ( T_1 ) F_104 ( V_25 ) ;
#ifdef F_111
V_210 = F_102 ( V_8 , V_25 , & V_250 , NULL , 1 ) ;
if ( V_210 ) {
if ( V_210 & V_290 )
F_109 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_210 & V_277 )
V_308 = 0 ;
}
#endif
V_350 = (struct V_349 * ) V_34 ;
memset ( V_350 , 0 , sizeof( struct V_349 ) ) ;
F_16 ( V_354 , V_34 , V_355 ) ;
V_350 -> V_271 = F_17 ( V_250 ) ;
V_350 -> V_356 = V_350 -> V_271 ;
if ( V_25 -> V_240 == V_317 ) {
if ( F_10 ( V_25 , V_318 ) )
F_16 ( V_357 , V_350 , V_308 ) ;
else
F_16 ( V_357 , V_350 , 0 ) ;
if ( F_10 ( V_25 , V_320 ) )
F_16 ( V_358 , V_350 , V_308 ) ;
else
F_16 ( V_358 , V_350 , 0 ) ;
}
F_16 ( V_359 , V_350 , V_292 ) ;
F_16 ( V_360 , V_350 , V_293 ) ;
F_16 ( V_361 , V_350 , 1 ) ;
F_16 ( V_362 , V_350 , 0 ) ;
V_350 -> V_36 = F_17 ( V_350 -> V_36 ) ;
V_350 -> V_363 = F_17 ( V_350 -> V_363 ) ;
V_351 ++ ;
V_34 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_236 = F_98 ( V_18 ) ;
V_352 = F_99 ( V_18 ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_236 ) ) ;
V_34 -> V_222 = F_17 ( F_55 ( V_236 ) ) ;
if ( ( V_47 + 1 ) == V_303 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_364 , V_34 , V_353 ) ;
F_16 ( V_354 , V_34 , V_365 ) ;
V_34 -> V_224 = F_17 ( V_352 ) ;
V_353 += V_352 ;
V_34 ++ ;
V_351 ++ ;
}
V_309:
return V_351 ;
}
static int
F_115 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_328 , int V_329 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_253 = NULL ;
struct V_349 * V_350 = NULL ;
T_3 V_332 , V_333 ;
unsigned short V_334 = 0 , V_335 = 0 ;
unsigned int V_336 ;
unsigned int V_337 , V_338 = 0 , V_339 ;
unsigned int V_340 , V_341 ;
unsigned int V_342 , V_343 ;
int V_161 ;
unsigned char V_344 = 0 , V_345 = 0 ;
unsigned V_256 ;
T_1 V_250 ;
V_221 V_292 , V_293 ;
T_1 V_352 ;
#ifdef F_111
T_1 V_210 ;
#endif
T_1 V_308 = 1 ;
T_1 V_353 = 0 ;
int V_351 = 0 ;
V_253 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_253 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_97 ,
L_35 ,
V_253 , V_18 ) ;
return 0 ;
}
V_161 = F_108 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_161 )
goto V_309;
V_256 = F_9 ( V_25 ) ;
V_250 = ( T_1 ) F_104 ( V_25 ) ;
#ifdef F_111
V_210 = F_102 ( V_8 , V_25 , & V_250 , NULL , 1 ) ;
if ( V_210 ) {
if ( V_210 & V_290 )
F_109 ( V_8 , V_25 , & V_292 , & V_293 ) ;
if ( V_210 & V_277 )
V_308 = 0 ;
}
#endif
V_336 = 0 ;
do {
if ( V_351 >= ( V_8 -> V_346 - 2 ) )
return V_351 + 3 ;
V_350 = (struct V_349 * ) V_34 ;
memset ( V_350 , 0 , sizeof( struct V_349 ) ) ;
F_16 ( V_354 , V_34 , V_355 ) ;
V_350 -> V_271 = F_17 ( V_250 ) ;
V_350 -> V_356 = V_350 -> V_271 ;
if ( F_10 ( V_25 , V_318 ) ) {
F_16 ( V_357 , V_350 , V_308 ) ;
} else {
F_16 ( V_357 , V_350 , 0 ) ;
if ( V_292 == V_301 ) {
V_292 = V_366 ;
V_293 = V_366 ;
}
}
if ( F_10 ( V_25 , V_320 ) )
F_16 ( V_358 , V_350 , V_308 ) ;
else
F_16 ( V_358 , V_350 , 0 ) ;
F_16 ( V_359 , V_350 , V_292 ) ;
F_16 ( V_360 , V_350 , V_293 ) ;
F_16 ( V_361 , V_350 , 1 ) ;
F_16 ( V_362 , V_350 , 0 ) ;
V_350 -> V_36 = F_17 ( V_350 -> V_36 ) ;
V_350 -> V_363 = F_17 ( V_350 -> V_363 ) ;
V_351 ++ ;
V_34 ++ ;
V_333 = F_98 ( V_253 ) + V_338 ;
V_337 = F_99 ( V_253 ) - V_338 ;
F_113 ( V_337 % 8 ) ;
V_34 -> V_36 = 0 ;
F_16 ( V_354 , V_34 , V_367 ) ;
V_34 -> V_222 = F_15 ( F_55 ( V_333 ) ) ;
V_34 -> V_223 = F_15 ( F_56 ( V_333 ) ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_340 = V_337 / 8 ;
V_341 = V_340 * V_256 ;
if ( ( V_34 -> V_223 & 0xfff ) + V_337 > 0x1000 ) {
V_339 = 0x1000 - ( V_34 -> V_223 & 0xfff ) ;
V_338 += V_339 ;
V_340 = V_339 / 8 ;
V_341 = V_340 * V_256 ;
} else {
V_338 = 0 ;
V_335 ++ ;
}
V_351 ++ ;
V_344 = 0 ;
V_343 = 0 ;
while ( ! V_344 ) {
if ( V_351 >= V_8 -> V_346 )
return V_351 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_36 ,
V_22 ) ;
return 0 ;
}
V_34 ++ ;
V_332 = F_98 ( V_18 ) + V_336 ;
V_342 = F_99 ( V_18 ) - V_336 ;
if ( ( V_343 + V_342 ) <= V_341 ) {
V_352 = V_342 ;
V_336 = 0 ;
if ( ( V_343 + V_342 ) == V_341 )
V_344 = 1 ;
} else {
V_352 = V_341 - V_343 ;
V_336 += V_352 ;
}
V_343 += V_352 ;
V_34 -> V_223 = F_17 ( F_56 ( V_332 ) ) ;
V_34 -> V_222 = F_17 ( F_55 ( V_332 ) ) ;
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_364 , V_34 , V_353 ) ;
F_16 ( V_354 , V_34 , V_365 ) ;
V_34 -> V_224 = F_17 ( V_352 ) ;
V_353 += V_352 ;
V_351 ++ ;
V_334 ++ ;
if ( V_336 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_338 ) {
V_250 += V_340 ;
V_34 ++ ;
continue;
}
if ( V_335 == V_329 ) {
F_16 ( V_37 , V_34 , 1 ) ;
V_345 = 1 ;
} else if ( V_335 < V_329 ) {
V_253 = F_6 ( V_253 ) ;
V_34 ++ ;
V_250 += V_340 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_37 , V_22 ) ;
}
} while ( ! V_345 );
V_309:
return V_351 ;
}
static int
F_12 ( struct V_12 * V_8 , struct V_13 * V_25 )
{
int V_294 = V_368 ;
unsigned char V_255 = F_103 ( V_25 ) ;
switch ( V_255 ) {
case V_283 :
case V_278 :
V_294 = V_29 ;
break;
case V_282 :
case V_279 :
case V_284 :
case V_270 :
V_294 = V_369 ;
break;
default:
if ( V_8 )
F_4 ( V_8 , V_20 , V_97 ,
L_38 ,
V_255 ) ;
break;
}
return V_294 ;
}
static int
F_116 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_25 = V_32 -> V_42 ;
int V_370 ;
V_370 = F_101 ( V_25 ) ;
if ( V_25 -> V_240 == V_317 ) {
if ( F_103 ( V_25 ) == V_282 )
return V_370 ;
} else {
if ( F_103 ( V_25 ) == V_279 )
return V_370 ;
}
V_370 += ( V_370 / F_9 ( V_25 ) ) * 8 ;
return V_370 ;
}
static int
F_117 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_127 * V_127 = V_32 -> V_127 ;
struct V_117 * V_118 = V_32 -> V_35 ;
T_2 * V_233 = & V_32 -> V_134 . V_119 ;
T_1 V_237 = 0 ;
int V_303 , V_371 , V_239 = V_13 -> V_240 ;
int V_372 = 0 ;
int V_370 ;
V_118 += 2 ;
if ( F_93 ( V_13 ) ) {
V_303 = F_94 ( & V_8 -> V_241 -> V_242 ,
F_3 ( V_13 ) ,
F_93 ( V_13 ) , V_239 ) ;
if ( F_95 ( ! V_303 ) )
return 1 ;
V_32 -> V_228 = V_303 ;
if ( V_32 -> V_228 > V_8 -> V_243 )
goto V_373;
V_372 = F_12 ( V_8 , V_13 ) ;
switch ( V_372 ) {
case V_29 :
if ( ( V_32 -> V_228 + 2 ) > V_8 -> V_346 )
goto V_373;
V_237 = F_110 ( V_8 , V_13 , V_118 ,
V_303 ) ;
if ( V_237 < 2 )
goto V_373;
break;
case V_369 :
V_371 = F_94 ( & V_8 -> V_241 -> V_242 ,
F_8 ( V_13 ) ,
F_118 ( V_13 ) , V_239 ) ;
if ( F_95 ( ! V_371 ) ) {
F_96 ( V_13 ) ;
return 1 ;
}
V_32 -> V_230 = V_371 ;
if ( ( V_32 -> V_230 * 4 ) >
( V_8 -> V_346 - 2 ) )
goto V_373;
V_237 = F_112 ( V_8 , V_13 , V_118 ,
V_303 , V_371 ) ;
if ( ( V_237 < 3 ) ||
( V_237 > V_8 -> V_346 ) )
goto V_373;
break;
case V_368 :
default:
F_96 ( V_13 ) ;
V_32 -> V_228 = 0 ;
F_4 ( V_8 , V_20 , V_97 ,
L_39 ,
V_372 ) ;
return 1 ;
}
}
V_233 -> V_68 . V_145 . V_146 . V_141 = ( 2 * sizeof( struct V_117 ) ) ;
V_233 -> V_68 . V_145 . V_146 . V_141 += ( V_237 * sizeof( struct V_117 ) ) ;
V_233 -> V_155 = 1 ;
V_233 -> V_156 = 1 ;
V_370 = F_116 ( V_8 , V_32 ) ;
V_127 -> V_247 = F_105 ( V_370 ) ;
V_233 -> V_68 . V_248 . V_249 = V_370 ;
return 0 ;
V_373:
if ( V_32 -> V_228 )
F_96 ( V_13 ) ;
if ( V_32 -> V_230 )
F_119 ( & V_8 -> V_241 -> V_242 , F_8 ( V_13 ) ,
F_118 ( V_13 ) ,
V_13 -> V_240 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_40
L_41 ,
V_32 -> V_228 , V_32 -> V_230 ,
V_8 -> V_346 , V_8 -> V_243 ,
V_372 , V_237 ) ;
V_32 -> V_228 = 0 ;
V_32 -> V_230 = 0 ;
return 1 ;
}
T_4
F_120 ( V_221 * V_131 , int V_374 )
{
T_4 V_375 = 0 ;
T_4 V_376 ;
V_375 = F_121 ( V_131 , V_374 ) ;
V_376 = F_107 ( V_375 ) ;
return V_376 ;
}
T_4
F_122 ( V_221 * V_131 , int V_374 )
{
T_4 V_294 ;
V_294 = F_123 ( V_131 , V_374 ) ;
return V_294 ;
}
void
F_124 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_17 * V_253 ;
struct V_17 * V_18 ;
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_254 * V_15 = NULL ;
V_221 * V_377 = NULL ;
T_4 V_378 , V_379 ;
T_4 V_380 , V_286 ;
T_1 V_381 , V_271 ;
int V_382 , V_371 ;
int V_383 , V_384 , V_385 ;
int V_386 , V_387 , V_388 ;
T_4 V_389 ;
unsigned V_256 ;
V_383 = V_390 ;
V_389 = 0 ;
V_378 = 0 ;
V_382 = F_103 ( V_41 ) ;
if ( ( V_382 == V_283 ) ||
( V_382 == V_278 ) ||
( V_382 == V_260 ) )
goto V_309;
V_386 = 1 ;
V_387 = 0 ;
V_388 = 0 ;
V_253 = F_8 ( V_41 ) ;
V_371 = V_32 -> V_230 ;
if ( V_253 && V_371 ) {
V_18 = F_3 ( V_41 ) ;
V_256 = F_9 ( V_41 ) ;
V_377 = ( V_221 * ) F_5 ( V_18 ) ;
V_385 = V_18 -> V_23 ;
if ( ( V_385 & ( V_256 - 1 ) ) == 0 )
V_388 = 1 ;
V_379 = F_13 ( V_41 -> V_26 -> V_6 ) ;
V_15 = (struct V_254 * ) F_5 ( V_253 ) ;
V_381 = ( T_1 ) F_104 ( V_41 ) ;
V_380 = V_15 -> V_286 ;
V_384 = V_253 -> V_23 ;
while ( V_15 && V_371 ) {
while ( V_384 ) {
if ( ( V_15 -> V_271 == 0xffffffff ) ||
( V_15 -> V_286 == 0xffff ) ) {
V_381 ++ ;
goto V_391;
}
if ( V_388 ) {
V_378 = V_15 -> V_378 ;
if ( F_11 ( V_41 ) )
V_389 = F_122 ( V_377 ,
V_256 ) ;
else
V_389 = F_120 ( V_377 ,
V_256 ) ;
if ( ( V_378 != V_389 ) ) {
V_383 = V_390 ;
goto V_309;
}
}
V_271 = F_105 ( V_15 -> V_271 ) ;
if ( V_386 && ( V_271 != V_381 ) ) {
V_383 = V_392 ;
goto V_309;
}
V_381 ++ ;
V_286 = V_15 -> V_286 ;
if ( V_387 && ( V_286 != V_380 ) ) {
V_383 = V_393 ;
goto V_309;
}
V_391:
V_384 -= sizeof( struct V_254 ) ;
if ( V_384 < 0 )
V_384 = 0 ;
V_15 ++ ;
V_377 += V_256 ;
V_385 -= V_256 ;
if ( V_388 && ( V_385 == 0 ) ) {
V_388 = 0 ;
V_18 = F_6 ( V_18 ) ;
if ( ! V_18 )
goto V_309;
V_377 = ( V_221 * ) F_5 ( V_18 ) ;
V_385 = V_18 -> V_23 ;
if ( ( V_385 & ( V_256 - 1 ) ) == 0 )
V_388 = 1 ;
}
}
V_253 = F_6 ( V_253 ) ;
if ( V_253 ) {
V_15 = (struct V_254 * ) F_5 ( V_253 ) ;
V_384 = V_253 -> V_23 ;
} else {
V_15 = NULL ;
}
V_371 -- ;
}
}
V_309:
if ( V_383 == V_390 ) {
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_399 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_42 ,
( unsigned long ) F_104 ( V_41 ) ,
V_389 , V_378 ) ;
} else if ( V_383 == V_392 ) {
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_400 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_43 ,
( unsigned long ) F_104 ( V_41 ) ,
V_271 , V_381 ) ;
} else if ( V_383 == V_393 ) {
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_401 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_44 ,
( unsigned long ) F_104 ( V_41 ) ,
V_286 , V_380 ) ;
}
}
static int
F_127 ( struct V_12 * V_8 , struct V_31 * V_32 ,
struct V_174 * V_402 )
{
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_403 * V_404 = & V_402 -> V_119 . V_152 . V_405 ;
int V_294 = 0 ;
T_1 V_406 = V_404 -> V_406 ;
T_1 V_407 = V_404 -> V_407 ;
T_6 V_408 = 0 ;
F_60 ( & V_409 ) ;
if ( ! V_410 ) {
F_4 ( V_8 , V_20 , V_21 , L_45
L_46 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_2 ( V_8 , V_41 ) ;
if ( F_12 ( V_8 , V_41 ) ==
V_369 ) {
F_4 ( V_8 , V_20 , V_21 , L_47
L_48 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_7 ( V_8 , V_41 ) ;
}
V_410 = 1 ;
}
F_62 ( & V_409 ) ;
if ( F_128 ( V_407 ) ) {
V_41 -> V_48 = F_126 ( V_411 , 0 ) ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_49
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
V_294 = ( - 1 ) ;
goto V_309;
}
if ( F_130 ( V_407 ) ) {
V_41 -> V_48 = F_126 ( V_411 , 0 ) ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_52
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
V_294 = ( - 1 ) ;
goto V_309;
}
if ( F_131 ( V_407 ) ) {
V_294 = 1 ;
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_399 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_53
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_132 ( V_407 ) ) {
V_294 = 1 ;
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_400 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_54
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_133 ( V_407 ) ) {
V_294 = 1 ;
F_125 ( 1 , V_41 -> V_394 , V_395 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_396 << 24
| F_126 ( V_397 , V_398 ) ;
V_8 -> V_401 ++ ;
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_55
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_134 ( V_407 ) ) {
V_41 -> V_394 [ 7 ] = 0xc ;
V_41 -> V_394 [ 8 ] = 0 ;
V_41 -> V_394 [ 9 ] = 0xa ;
V_41 -> V_394 [ 10 ] = 0x80 ;
switch ( F_103 ( V_41 ) ) {
case V_282 :
case V_279 :
V_406 /= V_41 -> V_26 -> V_27 ;
break;
case V_283 :
case V_278 :
case V_284 :
case V_270 :
V_406 /= ( V_41 -> V_26 -> V_27 +
sizeof( struct V_254 ) ) ;
break;
}
V_408 = F_104 ( V_41 ) ;
V_408 += V_406 ;
F_135 ( V_408 , & V_41 -> V_394 [ 12 ] ) ;
}
if ( ! V_294 ) {
F_4 ( V_8 , V_96 , V_97 | V_21 ,
L_56
L_50
L_51 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_41 ) ,
F_129 ( V_41 -> V_412 ) , V_407 , V_406 ) ;
F_124 ( V_8 , V_32 ) ;
}
V_309:
return V_294 ;
}
static int
F_136 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_232 = NULL ;
struct V_127 * V_127 = V_32 -> V_127 ;
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_33 * V_413 ;
T_2 * V_233 = & V_32 -> V_134 . V_119 ;
T_3 V_236 ;
T_1 V_237 = 0 ;
T_1 V_352 ;
T_1 V_353 = 0 ;
int V_238 ;
struct V_117 * V_414 ;
if ( F_93 ( V_13 ) ) {
V_238 = F_137 ( V_13 ) ;
if ( F_95 ( ! V_238 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_413 = V_34 ;
V_32 -> V_228 = V_238 ;
if ( V_32 -> V_228 > V_8 -> V_243 ) {
F_4 ( V_8 , V_20 , V_21 , L_57
L_58
L_14 ,
V_22 , V_8 -> V_243 ,
V_32 -> V_228 ) ;
V_32 -> V_228 = 0 ;
F_96 ( V_13 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_236 = F_98 ( V_232 ) ;
V_352 = F_99 ( V_232 ) ;
V_34 -> V_223 = F_17 ( F_56 ( V_236 ) ) ;
V_34 -> V_222 = F_17 ( F_55 ( V_236 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
if ( ( V_237 + 1 ) == V_238 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_364 , V_34 , V_353 ) ;
F_16 ( V_354 , V_34 , V_365 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_224 = F_17 ( V_352 ) ;
V_353 += V_352 ;
V_34 ++ ;
}
if ( V_8 -> V_149 & V_415 ) {
V_414 = (struct V_117 * )
& ( V_233 -> V_152 . V_416 [ 5 ] ) ;
V_414 -> V_138 = V_413 -> V_223 ;
V_414 -> V_137 = V_413 -> V_222 ;
V_414 -> V_139 . V_140 . V_141 =
F_15 ( V_413 -> V_224 ) ;
V_414 -> V_139 . V_140 . V_142 = V_143 ;
V_414 -> V_139 . V_144 = F_17 ( V_414 -> V_139 . V_144 ) ;
}
} else {
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
}
V_127 -> V_247 = F_100 ( F_101 ( V_13 ) ) ;
V_233 -> V_68 . V_248 . V_249 = F_101 ( V_13 ) ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_417 )
V_32 -> V_134 . V_135 |= V_418 ;
return 0 ;
}
static int
F_138 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_127 * V_127 = V_32 -> V_127 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_32 -> V_35 ) ;
T_2 * V_233 = & V_32 -> V_134 . V_119 ;
T_1 V_351 = 0 ;
int V_303 , V_371 , V_239 = V_13 -> V_240 ;
int V_372 = 0 ;
int V_370 ;
if ( F_93 ( V_13 ) ) {
V_303 = F_94 ( & V_8 -> V_241 -> V_242 ,
F_3 ( V_13 ) ,
F_93 ( V_13 ) , V_239 ) ;
if ( F_95 ( ! V_303 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_32 -> V_228 = V_303 ;
if ( V_32 -> V_228 > V_8 -> V_243 )
goto V_373;
V_372 = F_12 ( V_8 , V_13 ) ;
switch ( V_372 ) {
case V_29 :
if ( ( V_32 -> V_228 + 1 ) > V_8 -> V_346 )
goto V_373;
V_351 = F_114 ( V_8 , V_13 , V_34 ,
V_303 ) ;
if ( V_351 < 2 )
goto V_373;
break;
case V_369 :
V_371 = F_94 ( & V_8 -> V_241 -> V_242 ,
F_8 ( V_13 ) ,
F_118 ( V_13 ) , V_239 ) ;
if ( F_95 ( ! V_371 ) ) {
F_96 ( V_13 ) ;
return 1 ;
}
V_32 -> V_230 = V_371 ;
if ( ( V_32 -> V_230 * 3 ) >
( V_8 -> V_346 - 2 ) )
goto V_373;
V_351 = F_115 ( V_8 , V_13 , V_34 ,
V_303 , V_371 ) ;
if ( ( V_351 < 3 ) ||
( V_351 > V_8 -> V_346 ) )
goto V_373;
break;
case V_368 :
default:
F_96 ( V_13 ) ;
V_32 -> V_228 = 0 ;
F_4 ( V_8 , V_20 , V_97 ,
L_59 ,
V_372 ) ;
return 1 ;
}
}
switch ( F_103 ( V_13 ) ) {
case V_279 :
case V_283 :
V_32 -> V_134 . V_135 |= V_419 ;
break;
case V_278 :
case V_282 :
V_32 -> V_134 . V_135 |= V_420 ;
break;
case V_270 :
case V_284 :
V_32 -> V_134 . V_135 |= V_421 ;
break;
}
V_370 = F_116 ( V_8 , V_32 ) ;
V_127 -> V_247 = F_105 ( V_370 ) ;
V_233 -> V_68 . V_248 . V_249 = V_370 ;
return 0 ;
V_373:
if ( V_32 -> V_228 )
F_96 ( V_13 ) ;
if ( V_32 -> V_230 )
F_119 ( & V_8 -> V_241 -> V_242 , F_8 ( V_13 ) ,
F_118 ( V_13 ) ,
V_13 -> V_240 ) ;
F_4 ( V_8 , V_20 , V_97 ,
L_60
L_61 ,
V_32 -> V_228 , V_32 -> V_230 ,
V_8 -> V_346 , V_8 -> V_243 ,
V_372 , V_351 ) ;
V_32 -> V_228 = 0 ;
V_32 -> V_230 = 0 ;
return 1 ;
}
static inline int
F_139 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_139 ( V_8 , V_32 ) ;
}
static inline int
F_140 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_140 ( V_8 , V_32 ) ;
}
static void
F_141 ( struct V_12 * V_8 , struct V_4 * V_5 ,
struct V_31 * V_32 , struct V_174 * V_422 ) {
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_128 * V_423 = V_32 -> V_128 ;
T_1 V_424 = V_423 -> V_425 ;
T_1 V_426 = V_423 -> V_427 ;
T_1 V_249 = V_422 -> V_119 . V_68 . V_248 . V_249 ;
struct V_66 * V_67 = NULL ;
struct V_39 * V_40 = V_32 -> V_38 -> V_40 ;
unsigned long V_43 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return;
if ( ( V_14 -> V_48 == V_428 ) ||
( V_14 -> V_48 == V_429 ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_430 . V_71 =
V_72 ;
V_67 -> V_68 . V_430 . V_73 =
( V_14 -> V_48 == V_428 ) ?
V_431 : V_432 ;
V_67 -> V_68 . V_430 . V_63 = V_14 -> V_26 -> V_63 ;
memcpy ( & V_67 -> V_68 . V_430 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_430 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
} else if ( ( V_424 & V_433 ) && V_423 -> V_434 &&
( ( V_14 -> V_14 [ 0 ] == V_435 ) || ( V_14 -> V_14 [ 0 ] == V_436 ) ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_437 . V_70 . V_71 =
V_72 ;
V_67 -> V_68 . V_437 . V_70 . V_73 =
V_438 ;
V_67 -> V_68 . V_437 . V_70 . V_63 =
V_14 -> V_26 -> V_63 ;
memcpy ( & V_67 -> V_68 . V_437 . V_70 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_437 . V_70 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
V_67 -> V_68 . V_437 . V_439 =
V_14 -> V_394 [ 2 ] & 0xf ;
V_67 -> V_68 . V_437 . V_440 = V_14 -> V_394 [ 12 ] ;
V_67 -> V_68 . V_437 . V_441 = V_14 -> V_394 [ 13 ] ;
} else if ( ( V_14 -> V_240 == V_317 ) &&
V_249 &&
( ( F_105 ( V_423 -> V_442 ) != V_249 ) ||
( ( V_426 == V_443 ) &&
! ( V_424 & ( V_444 | V_445 ) ) ) ) ) {
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
return;
V_67 -> V_68 . V_446 . V_447 . V_71 =
V_448 ;
V_67 -> V_68 . V_446 . V_447 . V_73 =
V_449 ;
memcpy ( & V_67 -> V_68 . V_446 . V_447 . V_75 ,
& V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_446 . V_447 . V_78 ,
& V_40 -> V_79 , sizeof( struct V_77 ) ) ;
V_67 -> V_68 . V_446 . V_63 = V_14 -> V_26 -> V_63 ;
V_67 -> V_68 . V_446 . V_450 = V_14 -> V_14 [ 0 ] ;
V_67 -> V_68 . V_446 . V_451 =
V_249 ;
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
F_142 ( struct V_12 * V_8 , struct V_31 * V_116 )
{
if ( V_116 -> V_228 > 0 )
F_96 ( V_116 -> V_42 ) ;
if ( V_116 -> V_230 > 0 )
F_119 ( & V_8 -> V_241 -> V_242 , F_8 ( V_116 -> V_42 ) ,
F_118 ( V_116 -> V_42 ) ,
V_116 -> V_42 -> V_240 ) ;
}
static void
F_143 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_174 * V_422 )
{
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_127 * V_452 = V_32 -> V_127 ;
struct V_128 * V_423 = V_32 -> V_128 ;
T_1 V_249 = V_422 -> V_119 . V_68 . V_248 . V_249 ;
T_1 V_424 = V_423 -> V_425 ;
T_1 V_426 = V_423 -> V_427 ;
T_1 * V_453 ;
T_1 V_454 = V_455 ;
T_1 V_456 = 0 ;
T_1 V_457 = V_97 | V_458 ;
if ( V_452 -> V_459 ) {
V_426 = 0 ;
goto V_309;
}
if ( V_424 & V_460 ) {
V_456 = F_105 ( V_423 -> V_461 ) ;
if ( V_456 != 0 && V_456 != 4 && V_456 != 8 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_62
L_63 ,
V_14 -> V_26 -> V_462 ,
V_14 -> V_26 -> V_63 , V_14 -> V_14 [ 0 ] ,
V_456 ) ;
V_454 = V_411 ;
goto V_309;
}
if ( V_423 -> V_463 != V_464 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_64
L_65
L_66 ,
V_14 -> V_26 -> V_462 ,
V_14 -> V_26 -> V_63 , V_14 -> V_14 [ 0 ] ,
V_423 -> V_463 ) ;
V_454 = V_411 ;
goto V_309;
}
}
if ( ( V_424 & V_433 ) && V_423 -> V_434 ) {
T_1 V_465 = F_105 ( V_423 -> V_434 ) ;
if ( V_465 > V_466 )
V_465 = V_466 ;
if ( V_424 & V_460 )
V_456 = F_105 ( V_423 -> V_461 ) ;
memcpy ( V_14 -> V_394 , & V_423 -> V_467 + V_456 , V_465 ) ;
}
V_453 = ( T_1 * ) V_14 -> V_394 ;
if ( ! V_426 && ( V_424 & V_444 ) ) {
if ( V_5 -> V_468 & V_97 )
V_457 = V_458 ;
if ( V_5 -> V_468 & V_469 )
V_457 = V_469 ;
}
F_31 ( V_5 , V_96 , V_457 ,
L_67
L_68 ,
V_14 -> V_14 [ 0 ] , V_426 ,
F_105 ( * V_453 ) , F_105 ( * ( V_453 + 3 ) ) , V_424 ,
F_105 ( V_423 -> V_442 ) ,
F_105 ( V_423 -> V_434 ) ,
F_105 ( V_423 -> V_461 ) ,
V_423 -> V_463 ) ;
F_144 ( V_14 , 0 ) ;
if ( V_424 & V_444 ) {
F_144 ( V_14 , F_105 ( V_423 -> V_442 ) ) ;
F_31 ( V_5 , V_129 , V_469 ,
L_69
L_70 ,
F_105 ( V_452 -> V_247 ) ,
F_145 ( V_14 ) , V_249 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_470 ) ;
if ( ( V_14 -> V_240 == V_317 ) &&
V_249 &&
( F_145 ( V_14 ) != V_249 ) ) {
F_31 ( V_5 , V_96 ,
V_97 | V_458 ,
L_71
L_72 ,
F_105 ( V_452 -> V_247 ) ,
F_145 ( V_14 ) , V_249 ,
V_14 -> V_14 [ 0 ] ) ;
F_144 ( V_14 , F_101 ( V_14 ) ) ;
V_454 = V_411 ;
}
if ( ! ( V_424 & V_433 ) &&
( V_426 == V_443 ) &&
( F_101 ( V_14 ) - F_145 ( V_14 )
< V_14 -> V_470 ) ) {
F_31 ( V_5 , V_129 , V_97 ,
L_73
L_74
L_75 ,
V_14 -> V_14 [ 0 ] , F_101 ( V_14 ) ,
F_145 ( V_14 ) , V_14 -> V_470 ) ;
V_454 = V_411 ;
}
} else if ( V_424 & V_445 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_76
L_77 , V_14 -> V_14 [ 0 ] ,
F_101 ( V_14 ) , F_145 ( V_14 ) ) ;
V_454 = V_411 ;
} else if ( V_249 && ( V_14 -> V_240 == V_317 ) ) {
F_31 ( V_5 , V_96 , V_97 | V_458 ,
L_78
L_79 ,
F_105 ( V_452 -> V_247 ) ,
F_105 ( V_423 -> V_442 ) ,
V_249 , V_14 -> V_14 [ 0 ] , V_426 ) ;
switch ( V_426 ) {
case V_443 :
case V_398 :
V_454 = V_411 ;
break;
}
F_144 ( V_14 , F_101 ( V_14 ) ) ;
}
V_309:
V_14 -> V_48 = F_126 ( V_454 , V_426 ) ;
F_141 ( V_5 -> V_8 , V_5 , V_32 , V_422 ) ;
}
static void
F_146 ( struct V_12 * V_8 , struct V_174 * V_471 ,
struct V_174 * V_402 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_471 -> V_163 ;
struct V_4 * V_5 = V_471 -> V_5 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_13 * V_41 ;
int V_48 ;
int V_472 ;
unsigned long V_43 ;
struct V_66 * V_67 ;
struct V_44 * V_45 ;
T_1 V_92 , V_473 ;
T_1 V_457 = V_97 ;
if ( ! ( V_32 -> V_42 ) )
return;
V_41 = V_32 -> V_42 ;
V_45 = V_41 -> V_26 -> V_6 ;
V_32 -> V_48 = ( V_402 -> V_119 . V_68 . V_474 [ 4 ] & V_475 ) ;
V_32 -> V_161 = V_402 -> V_119 . V_476 ;
V_32 -> V_184 = V_402 -> V_135 & V_477 ;
#ifdef F_111
if ( V_32 -> V_272 ) {
struct V_254 * V_15 = NULL ;
V_15 = (struct V_254 * ) V_32 -> V_274 ;
switch ( V_32 -> V_272 ) {
case V_273 :
V_15 -> V_271 =
V_32 -> V_275 ;
break;
case V_287 :
V_15 -> V_286 =
( T_4 ) V_32 -> V_275 ;
break;
case V_478 :
V_15 -> V_378 =
( T_4 ) V_32 -> V_275 ;
break;
default:
break;
}
V_32 -> V_275 = 0 ;
V_32 -> V_272 = 0 ;
V_32 -> V_274 = NULL ;
}
#endif
if ( V_40 && F_24 ( V_40 ) )
F_147 ( & V_40 -> V_479 ) ;
if ( V_32 -> V_161 ) {
if ( V_32 -> V_161 == V_480 &&
( V_32 -> V_48 & V_481 ) )
V_32 -> V_161 = V_482 ;
else if ( V_32 -> V_161 >= V_483 )
V_32 -> V_161 = V_484 ;
if ( V_32 -> V_161 == V_485 &&
! V_32 -> V_128 -> V_427 &&
( V_32 -> V_128 -> V_425 & V_444 ) &&
! ( V_5 -> V_468 & V_469 ) )
V_457 = 0 ;
else
V_457 = V_97 | V_469 ;
F_31 ( V_5 , V_96 , V_457 ,
L_80
L_81
L_82
L_77 ,
V_41 -> V_14 [ 0 ] ,
V_41 -> V_26 ? V_41 -> V_26 -> V_462 : 0xffff ,
V_41 -> V_26 ? V_41 -> V_26 -> V_63 : 0xffff ,
V_32 -> V_161 , V_32 -> V_48 ,
V_5 -> V_486 ,
( V_40 ) ? V_40 -> V_264 : 0 ,
V_8 -> V_148 == V_487 ?
V_32 -> V_134 . V_182 : 0xffff ,
V_402 -> V_119 . V_488 ,
V_32 -> V_134 . V_119 . V_489 ) ;
switch ( V_32 -> V_161 ) {
case V_485 :
F_143 ( V_5 , V_32 , V_402 ) ;
break;
case V_490 :
case V_491 :
V_41 -> V_48 = F_126 ( V_492 , 0 ) ;
V_67 = F_23 ( V_8 ) ;
if ( ! V_67 )
break;
V_67 -> V_68 . V_493 . V_71 =
V_448 ;
V_67 -> V_68 . V_493 . V_73 =
( V_32 -> V_161 == V_490 ) ?
V_494 : V_495 ;
if ( V_40 && F_24 ( V_40 ) ) {
memcpy ( & V_67 -> V_68 . V_493 . V_75 ,
& V_40 -> V_76 ,
sizeof( struct V_77 ) ) ;
memcpy ( & V_67 -> V_68 . V_493 . V_78 ,
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
case V_480 :
case V_496 :
if ( V_32 -> V_48 == V_497 ||
V_32 -> V_48 ==
V_498 ||
V_32 -> V_48 == V_499 ||
V_32 -> V_48 ==
V_500 ) {
V_41 -> V_48 = F_126 ( V_501 , 0 ) ;
break;
}
if ( V_32 -> V_48 == V_502 ||
V_32 -> V_48 == V_503 ||
V_32 -> V_48 == V_504 ||
V_32 -> V_48 == V_505 ) {
V_41 -> V_48 = F_126 ( V_506 , 0 ) ;
break;
}
if ( ( V_32 -> V_48 == V_507 ||
V_32 -> V_48 == V_508 ) &&
V_402 -> V_119 . V_152 . V_405 . V_407 ) {
if ( F_103 ( V_41 ) != V_260 ) {
F_127 ( V_8 , V_32 ,
V_402 ) ;
break;
} else {
F_31 ( V_5 , V_96 ,
V_21 ,
L_83
L_84 ) ;
}
}
if ( ( V_32 -> V_161 == V_496 )
&& ( V_8 -> V_148 == V_487 )
&& ( V_40 && F_24 ( V_40 ) ) ) {
F_67 ( V_8 , V_40 ,
V_32 -> V_134 . V_186 ,
0 , 0 ) ;
}
default:
V_41 -> V_48 = F_126 ( V_411 , 0 ) ;
break;
}
if ( ! V_40 || ! F_24 ( V_40 )
|| ( V_40 -> V_509 != V_510 ) )
V_41 -> V_48 = F_126 ( V_492 ,
V_429 ) ;
} else
V_41 -> V_48 = F_126 ( V_455 , 0 ) ;
if ( V_41 -> V_48 || V_32 -> V_128 -> V_434 ) {
T_1 * V_453 = ( T_1 * ) V_41 -> V_394 ;
F_31 ( V_5 , V_129 , V_97 ,
L_85
L_86 ,
V_41 -> V_26 -> V_462 , V_41 -> V_26 -> V_63 , V_41 ,
V_41 -> V_48 , * V_453 , * ( V_453 + 3 ) , V_41 -> V_511 ,
F_145 ( V_41 ) ) ;
}
F_18 ( V_8 , V_32 ) ;
V_48 = V_41 -> V_48 ;
if ( V_5 -> V_512 &&
F_148 ( V_49 , V_32 -> V_50 +
F_149 ( V_5 -> V_512 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_40 && F_24 ( V_40 ) ) {
if ( V_40 -> V_513 >
F_39 ( & V_40 -> V_479 ) &&
( F_39 ( & V_40 -> V_479 ) >
V_514 ) &&
( ( V_41 -> V_14 [ 0 ] == V_435 ) ||
( V_41 -> V_14 [ 0 ] == V_436 ) ) )
V_40 -> V_513 =
F_39 ( & V_40 -> V_479 ) ;
V_40 -> V_515 = V_49 ;
}
F_21 ( V_45 -> V_51 , V_43 ) ;
} else if ( V_40 && F_24 ( V_40 ) ) {
if ( ( V_40 -> V_513 < V_5 -> V_516 ) &&
F_148 ( V_49 , V_40 -> V_515 +
F_149 ( V_517 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
V_472 = V_40 -> V_513 * V_518
/ 100 ;
V_472 = V_472 ? V_472 : 1 ;
V_40 -> V_513 += V_472 ;
if ( V_40 -> V_513 > V_5 -> V_516 )
V_40 -> V_513 = V_5 -> V_516 ;
V_40 -> V_515 = V_49 ;
F_21 ( V_45 -> V_51 , V_43 ) ;
}
}
F_142 ( V_8 , V_32 ) ;
V_92 = V_41 -> V_26 -> V_92 ;
V_473 = V_41 -> V_26 -> V_462 ;
V_41 -> V_519 ( V_41 ) ;
if ( V_8 -> V_520 & V_521 ) {
F_20 ( & V_8 -> V_85 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_522 )
F_150 ( V_32 -> V_522 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_91 ( V_8 , V_32 ) ;
return;
}
F_20 ( & V_8 -> V_85 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_522 )
F_150 ( V_32 -> V_522 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_91 ( V_8 , V_32 ) ;
}
static void
F_151 ( V_221 * V_131 , struct V_127 * V_127 )
{
int V_47 , V_523 ;
for ( V_47 = 0 , V_523 = 0 ; V_47 < sizeof( struct V_127 ) ;
V_47 += sizeof( T_1 ) , V_523 ++ ) {
( ( T_1 * ) V_131 ) [ V_523 ] = F_100 ( ( ( T_1 * ) V_127 ) [ V_523 ] ) ;
}
}
static void
F_152 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_127 * V_127 = V_32 -> V_127 ;
T_2 * V_233 = & V_32 -> V_134 . V_119 ;
struct V_174 * V_524 = & ( V_32 -> V_134 ) ;
int V_239 = V_13 -> V_240 ;
char V_525 [ 2 ] ;
V_221 * V_526 ;
bool V_527 ;
T_1 V_370 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return;
V_32 -> V_128 -> V_434 = 0 ;
V_32 -> V_127 -> V_459 = 0 ;
F_153 ( V_32 -> V_42 -> V_26 -> V_63 ,
& V_32 -> V_127 -> V_528 ) ;
V_526 = & V_127 -> V_529 [ 0 ] ;
memcpy ( V_526 , V_13 -> V_14 , V_13 -> V_530 ) ;
if ( V_13 -> V_530 < V_531 ) {
V_526 += V_13 -> V_530 ;
memset ( V_526 , 0 , ( V_531 - V_13 -> V_530 ) ) ;
}
if ( F_154 ( V_13 , V_525 ) ) {
switch ( V_525 [ 0 ] ) {
case V_532 :
V_127 -> V_533 = V_534 ;
break;
case V_535 :
V_127 -> V_533 = V_536 ;
break;
default:
V_127 -> V_533 = V_537 ;
break;
}
} else
V_127 -> V_533 = V_537 ;
V_527 = ( V_8 -> V_148 == V_487 ) ;
V_524 -> V_119 . V_68 . V_248 . V_538 = 0 ;
if ( F_93 ( V_13 ) ) {
if ( V_239 == V_326 ) {
V_233 -> V_539 = V_540 ;
V_233 -> V_541 = V_542 ;
if ( V_5 -> V_543 &&
( V_40 -> V_544 & V_545 ) ) {
V_370 = F_101 ( V_13 ) ;
if ( V_370 < V_5 -> V_543 )
V_524 -> V_119 . V_68 . V_248 . V_538 = V_370 ;
else
V_524 -> V_119 . V_68 . V_248 . V_538 =
V_5 -> V_543 ;
}
V_127 -> V_546 = V_547 ;
V_8 -> V_548 ++ ;
} else {
V_233 -> V_539 = V_549 ;
V_233 -> V_541 = V_542 ;
V_127 -> V_546 = V_550 ;
V_8 -> V_551 ++ ;
}
} else {
V_233 -> V_539 = V_552 ;
V_233 -> V_68 . V_248 . V_249 = 0 ;
V_233 -> V_541 = 0 ;
V_127 -> V_546 = 0 ;
V_8 -> V_553 ++ ;
}
if ( V_8 -> V_148 == 3 &&
! ( V_8 -> V_149 & V_150 ) )
F_151 ( V_233 -> V_152 . V_153 . V_154 , V_127 ) ;
V_524 -> V_119 . V_488 = V_40 -> V_554 ;
if ( V_527 )
V_524 -> V_119 . V_488 =
V_8 -> V_166 . V_555 [ V_40 -> V_554 ] ;
if ( V_40 -> V_556 & V_557 )
V_524 -> V_119 . V_558 = 1 ;
else
V_524 -> V_119 . V_558 = 0 ;
V_524 -> V_119 . V_159 = ( V_40 -> V_556 & 0x0f ) ;
V_524 -> V_163 = V_32 ;
V_524 -> V_559 = F_146 ;
V_524 -> V_119 . V_560 = V_32 -> V_561 ;
V_524 -> V_5 = V_5 ;
}
static int
F_155 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
unsigned int V_63 ,
V_221 V_562 )
{
struct V_174 * V_524 ;
T_2 * V_563 ;
struct V_127 * V_127 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_62 = V_38 -> V_40 ;
if ( ! V_62 || ! F_24 ( V_62 ) ||
V_62 -> V_509 != V_510 )
return 0 ;
V_524 = & ( V_32 -> V_134 ) ;
V_524 -> V_5 = V_5 ;
V_563 = & V_524 -> V_119 ;
V_127 = V_32 -> V_127 ;
memset ( V_127 , 0 , sizeof( struct V_127 ) ) ;
F_153 ( V_63 , & V_127 -> V_528 ) ;
V_127 -> V_459 = V_562 ;
if ( V_5 -> V_8 -> V_148 == 3 &&
! ( V_5 -> V_8 -> V_149 & V_150 ) )
F_151 ( V_563 -> V_152 . V_153 . V_154 , V_127 ) ;
V_563 -> V_539 = V_552 ;
V_563 -> V_488 = V_62 -> V_554 ;
if ( V_5 -> V_8 -> V_148 == V_487 ) {
V_563 -> V_488 =
V_5 -> V_8 -> V_166 . V_555 [ V_62 -> V_554 ] ;
}
V_563 -> V_558 = ( V_62 -> V_556 & V_557 ) ? 1 : 0 ;
V_563 -> V_159 = ( V_62 -> V_556 & 0x0f ) ;
V_563 -> V_541 = 0 ;
V_563 -> V_68 . V_248 . V_249 = 0 ;
if ( V_32 -> V_561 > 0xff ) {
V_563 -> V_560 = 0 ;
} else
V_563 -> V_560 = V_32 -> V_561 ;
if ( V_5 -> V_8 -> V_148 == V_487 )
F_14 ( V_5 -> V_8 , V_32 ) ;
return 1 ;
}
int
F_156 ( struct V_12 * V_8 , V_221 V_564 )
{
V_8 -> F_142 = F_142 ;
V_8 -> F_152 = F_152 ;
switch ( V_564 ) {
case V_565 :
V_8 -> F_85 = F_49 ;
V_8 -> F_139 = F_92 ;
V_8 -> F_140 = F_117 ;
V_8 -> F_91 = F_58 ;
V_8 -> F_90 = F_86 ;
break;
case V_566 :
V_8 -> F_85 = F_82 ;
V_8 -> F_139 = F_136 ;
V_8 -> F_140 = F_138 ;
V_8 -> F_91 = F_69 ;
V_8 -> F_90 = F_88 ;
break;
default:
F_4 ( V_8 , V_20 , V_567 ,
L_87 ,
V_564 ) ;
return - V_568 ;
break;
}
V_8 -> F_36 = F_36 ;
V_8 -> F_146 = F_146 ;
return 0 ;
}
static void
F_157 ( struct V_12 * V_8 ,
struct V_174 * V_569 ,
struct V_174 * V_570 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_569 -> V_163 ;
if ( V_32 )
F_91 ( V_8 , V_32 ) ;
return;
}
const char *
F_158 ( struct V_44 * V_6 )
{
struct V_4 * V_5 = (struct V_4 * ) V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_384 , V_571 = 0 ;
static char V_572 [ 384 ] ;
memset ( V_572 , 0 , 384 ) ;
if ( V_8 && V_8 -> V_241 ) {
strncpy ( V_572 , V_8 -> V_573 , 256 ) ;
V_384 = strlen ( V_572 ) ;
snprintf ( V_572 + V_384 ,
384 - V_384 ,
L_88 ,
V_8 -> V_241 -> V_574 -> V_575 ,
V_8 -> V_241 -> V_576 ,
V_8 -> V_241 -> V_577 ) ;
V_384 = strlen ( V_572 ) ;
if ( V_8 -> V_578 [ 0 ] ) {
snprintf ( V_572 + V_384 ,
384 - V_384 ,
L_89 ,
V_8 -> V_578 ) ;
}
V_384 = strlen ( V_572 ) ;
if ( V_8 -> V_148 <= V_579 ) {
V_571 = F_159 ( V_8 ) ;
} else {
if ( V_8 -> V_166 . V_580 . V_581 )
V_571 =
V_8 -> V_166 . V_580 . V_581 ;
else
V_571 = V_8 -> V_166 . V_580 . V_582 ;
}
if ( V_571 != 0 )
snprintf ( V_572 + V_384 , 384 - V_384 ,
L_90 , V_571 ) ;
}
return V_572 ;
}
static T_7 void F_160 ( struct V_12 * V_8 )
{
unsigned long V_583 =
( V_49 + F_149 ( V_8 -> V_584 ) ) ;
if ( ! F_66 ( & V_8 -> V_179 . V_180 [ V_585 ] . V_586 ) )
F_161 ( & V_8 -> V_587 ,
V_583 ) ;
}
void F_162 ( struct V_12 * V_8 )
{
F_160 ( V_8 ) ;
}
void F_163 ( unsigned long V_526 )
{
struct V_12 * V_8 = (struct V_12 * ) V_526 ;
if ( V_8 -> V_520 & V_521 ) {
F_164 ( V_8 ,
& V_8 -> V_179 . V_180 [ V_585 ] , V_588 ) ;
if ( V_8 -> V_520 & V_589 )
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
struct V_113 * V_114 = F_46 ( F_47 ( V_14 -> V_26 ) ) ;
int V_373 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
V_373 = F_166 ( V_114 ) ;
if ( V_373 ) {
V_14 -> V_48 = V_373 ;
goto V_590;
}
V_62 = V_38 -> V_40 ;
if ( ( F_103 ( V_14 ) != V_260 ) &&
( ! ( V_8 -> V_149 & V_150 ) ) ) {
F_4 ( V_8 , V_20 , V_21 ,
L_91
L_92
L_93 ,
V_14 -> V_14 [ 0 ] , F_103 ( V_14 ) ,
V_591 [ F_103 ( V_14 ) ] ) ;
goto V_590;
}
if ( ! V_62 || ! F_24 ( V_62 ) )
goto V_592;
if ( F_39 ( & V_62 -> V_479 ) >= V_62 -> V_513 )
goto V_592;
V_32 = F_90 ( V_8 , V_62 ) ;
if ( V_32 == NULL ) {
F_36 ( V_8 ) ;
F_31 ( V_5 , V_129 , V_97 ,
L_94
L_95 ) ;
goto V_593;
}
V_32 -> V_42 = V_14 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_561 = 0 ;
V_32 -> V_50 = V_49 ;
V_14 -> V_268 = ( unsigned char * ) V_32 ;
if ( F_103 ( V_14 ) != V_260 ) {
if ( V_5 -> V_8 -> V_218 ) {
F_31 ( V_5 ,
V_129 , V_594 ,
L_96
L_97 ,
V_591 [ F_103 ( V_14 ) ] ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_14 ) ,
F_129 ( V_14 -> V_412 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_373 = F_140 ( V_8 , V_32 ) ;
} else {
if ( V_5 -> V_8 -> V_218 ) {
F_31 ( V_5 ,
V_129 , V_594 ,
L_98
L_99 ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_104 ( V_14 ) ,
F_129 ( V_14 -> V_412 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_373 = F_139 ( V_8 , V_32 ) ;
}
if ( V_373 )
goto V_595;
F_152 ( V_5 , V_32 , V_62 ) ;
F_37 ( & V_62 -> V_479 ) ;
V_373 = F_167 ( V_8 , V_585 ,
& V_32 -> V_134 , V_596 ) ;
if ( V_373 ) {
F_147 ( & V_62 -> V_479 ) ;
F_31 ( V_5 , V_129 , V_97 ,
L_100
L_101
L_82
L_102 ,
V_373 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_26 ? V_14 -> V_26 -> V_462 : 0xffff ,
V_14 -> V_26 ? V_14 -> V_26 -> V_63 : 0xffff ,
V_5 -> V_486 , V_62 -> V_264 ,
V_8 -> V_148 == V_487 ?
V_32 -> V_134 . V_182 : 0xffff ,
V_32 -> V_134 . V_119 . V_488 ,
V_32 -> V_134 . V_119 . V_489 ,
V_32 -> V_134 . V_119 . V_560 ,
( T_1 )
( V_14 -> V_412 -> V_561 / 1000 ) ) ;
goto V_595;
}
if ( V_8 -> V_520 & V_521 ) {
F_164 ( V_8 ,
& V_8 -> V_179 . V_180 [ V_585 ] , V_588 ) ;
if ( V_8 -> V_520 & V_589 )
F_160 ( V_8 ) ;
}
return 0 ;
V_595:
F_142 ( V_8 , V_32 ) ;
F_91 ( V_8 , V_32 ) ;
V_593:
return V_597 ;
V_592:
return V_598 ;
V_590:
V_14 -> V_519 ( V_14 ) ;
return 0 ;
}
static int
F_168 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_174 * V_119 ;
struct V_174 * V_599 ;
struct V_31 * V_32 ;
T_2 * V_41 , * V_600 ;
int V_294 = V_601 , V_161 = 0 ;
struct V_177 * V_602 ;
int V_603 , V_604 ;
unsigned long V_43 , V_605 ;
F_169 ( V_522 ) ;
V_161 = F_170 ( V_14 ) ;
if ( V_161 != 0 && V_161 != V_601 )
return V_161 ;
F_20 ( & V_8 -> V_85 , V_43 ) ;
if ( V_8 -> V_606 & V_607 ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_103
L_104 ) ;
return V_608 ;
}
V_32 = (struct V_31 * ) V_14 -> V_268 ;
if ( ! V_32 || ! V_32 -> V_42 ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_105
L_106 ,
V_601 , V_14 -> V_26 -> V_462 , V_14 -> V_26 -> V_63 ) ;
return V_601 ;
}
V_119 = & V_32 -> V_134 ;
if ( ! ( V_119 -> V_135 & V_609 ) ) {
F_21 ( & V_8 -> V_85 , V_43 ) ;
F_31 ( V_5 , V_96 , V_97 ,
L_107
L_108 ) ;
return V_608 ;
}
if ( V_32 -> V_42 != V_14 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_109
L_110 ) ;
goto V_610;
}
F_113 ( V_119 -> V_163 != V_32 ) ;
if ( V_119 -> V_135 & V_611 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_111 ) ;
F_21 ( & V_8 -> V_85 , V_43 ) ;
goto V_612;
}
V_599 = F_171 ( V_8 ) ;
if ( V_599 == NULL ) {
V_294 = V_608 ;
goto V_610;
}
V_119 -> V_135 |= V_611 ;
V_41 = & V_119 -> V_119 ;
V_600 = & V_599 -> V_119 ;
V_600 -> V_68 . V_613 . V_614 = V_615 ;
V_600 -> V_68 . V_613 . V_616 = V_41 -> V_488 ;
if ( V_8 -> V_148 == V_487 )
V_600 -> V_68 . V_613 . V_617 = V_119 -> V_182 ;
else
V_600 -> V_68 . V_613 . V_617 = V_41 -> V_489 ;
V_600 -> V_156 = 1 ;
V_600 -> V_159 = V_41 -> V_159 ;
V_599 -> V_618 = V_119 -> V_618 ;
V_599 -> V_135 |= V_619 ;
if ( F_172 ( V_8 ) )
V_600 -> V_539 = V_620 ;
else
V_600 -> V_539 = V_621 ;
V_599 -> V_559 = V_622 ;
V_599 -> V_5 = V_5 ;
if ( V_8 -> V_148 == V_487 ) {
V_603 = V_623 + V_119 -> V_618 ;
V_602 = & V_8 -> V_179 . V_180 [ V_603 ] ;
F_20 ( & V_602 -> V_624 , V_605 ) ;
V_604 = F_173 ( V_8 , V_602 -> V_625 ,
V_599 , 0 ) ;
F_21 ( & V_602 -> V_624 , V_605 ) ;
} else {
V_604 = F_173 ( V_8 , V_585 ,
V_599 , 0 ) ;
}
F_21 ( & V_8 -> V_85 , V_43 ) ;
if ( V_604 == V_626 ) {
F_174 ( V_8 , V_599 ) ;
V_294 = V_608 ;
goto V_309;
}
if ( V_8 -> V_520 & V_589 )
F_164 ( V_8 ,
& V_8 -> V_179 . V_180 [ V_585 ] , V_588 ) ;
V_612:
V_32 -> V_522 = & V_522 ;
F_175 ( V_522 ,
( V_32 -> V_42 != V_14 ) ,
F_149 ( 2 * V_5 -> V_627 * 1000 ) ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
V_32 -> V_522 = NULL ;
F_21 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_42 == V_14 ) {
V_294 = V_608 ;
F_31 ( V_5 , V_20 , V_97 ,
L_112
L_113
L_114 ,
V_119 -> V_182 , V_294 ,
V_14 -> V_26 -> V_462 , V_14 -> V_26 -> V_63 ) ;
}
goto V_309;
V_610:
F_21 ( & V_8 -> V_85 , V_43 ) ;
V_309:
F_31 ( V_5 , V_96 , V_97 ,
L_115
L_116 , V_294 , V_14 -> V_26 -> V_462 ,
V_14 -> V_26 -> V_63 ) ;
return V_294 ;
}
static char *
F_176 ( V_221 V_562 )
{
switch ( V_562 ) {
case V_628 :
return L_117 ;
case V_629 :
return L_118 ;
case V_630 :
return L_119 ;
case V_631 :
return L_120 ;
case V_632 :
return L_121 ;
case V_633 :
return L_122 ;
case V_634 :
return L_123 ;
default:
return L_124 ;
}
}
static int
F_177 ( struct V_4 * V_5 , struct V_31 * V_32 )
{
struct V_128 * V_423 = V_32 -> V_128 ;
T_1 V_635 ;
T_1 V_636 ;
V_221 V_637 ;
int V_294 = V_608 ;
if ( V_423 == NULL )
F_31 ( V_5 , V_129 , V_97 ,
L_125 ) ;
else {
V_635 = V_423 -> V_425 ;
V_636 = F_105 ( V_423 -> V_461 ) ;
V_637 = V_423 -> V_463 ;
F_31 ( V_5 , V_129 ,
V_97 ,
L_126
L_127 ,
V_635 ,
V_636 , V_637 ) ;
if ( ( V_423 -> V_425 & V_460 ) && ( V_636 == 8 ) ) {
switch ( V_637 ) {
case V_464 :
F_31 ( V_5 , V_129 , V_97 ,
L_128 ) ;
V_294 = V_601 ;
break;
case V_638 :
F_31 ( V_5 , V_129 , V_97 ,
L_129
L_130 ) ;
break;
case V_639 :
F_31 ( V_5 , V_129 , V_97 ,
L_131
L_132 ) ;
break;
case V_640 :
F_31 ( V_5 , V_129 , V_97 ,
L_133
L_134 ) ;
break;
}
}
}
return V_294 ;
}
static int
F_178 ( struct V_4 * V_5 , struct V_1 * V_38 ,
unsigned V_641 , unsigned int V_642 ,
V_221 V_562 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_32 ;
struct V_174 * V_175 ;
struct V_174 * V_643 ;
struct V_39 * V_40 = V_38 -> V_40 ;
int V_294 ;
int V_161 ;
if ( ! V_40 || ! F_24 ( V_40 ) )
return V_608 ;
V_32 = F_90 ( V_8 , V_38 -> V_40 ) ;
if ( V_32 == NULL )
return V_608 ;
V_32 -> V_561 = V_8 -> V_644 ;
V_32 -> V_38 = V_38 ;
V_161 = F_155 ( V_5 , V_32 , V_642 ,
V_562 ) ;
if ( ! V_161 ) {
F_91 ( V_8 , V_32 ) ;
return V_608 ;
}
V_175 = & V_32 -> V_134 ;
V_643 = F_179 ( V_8 ) ;
if ( V_643 == NULL ) {
F_91 ( V_8 , V_32 ) ;
return V_608 ;
}
V_175 -> V_559 = F_157 ;
F_31 ( V_5 , V_129 , V_97 ,
L_135
L_136 ,
F_176 ( V_562 ) , V_641 , V_642 ,
V_40 -> V_554 , V_40 -> V_544 , V_175 -> V_182 ,
V_175 -> V_135 ) ;
V_161 = F_180 ( V_8 , V_585 ,
V_175 , V_643 , V_32 -> V_561 ) ;
if ( ( V_161 != V_645 ) ||
( V_643 -> V_119 . V_476 != V_162 ) ) {
F_31 ( V_5 , V_20 , V_97 ,
L_137
L_138 ,
F_176 ( V_562 ) ,
V_641 , V_642 , V_643 -> V_119 . V_476 ,
V_643 -> V_119 . V_68 . V_474 [ 4 ] ,
V_175 -> V_135 ) ;
if ( V_161 == V_645 ) {
if ( V_643 -> V_119 . V_476 == V_485 )
V_294 = F_177 ( V_5 , V_32 ) ;
else
V_294 = V_608 ;
} else if ( V_161 == V_646 ) {
V_294 = V_647 ;
} else {
V_294 = V_608 ;
}
V_32 -> V_161 = V_482 ;
} else
V_294 = V_601 ;
F_174 ( V_8 , V_643 ) ;
if ( V_294 != V_647 )
F_91 ( V_8 , V_32 ) ;
return V_294 ;
}
static int
F_181 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned long V_648 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_129 , V_97 ,
L_139 , V_38 ) ;
return V_608 ;
}
V_40 = V_38 -> V_40 ;
V_648 = F_149 ( 2 * V_5 -> V_627 * 1000 ) + V_49 ;
while ( F_148 ( V_648 , V_49 ) ) {
if ( ! V_40 || ! F_24 ( V_40 ) )
return V_608 ;
if ( V_40 -> V_509 == V_510 )
return V_601 ;
F_182 ( F_149 ( 500 ) ) ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 )
return V_608 ;
V_40 = V_38 -> V_40 ;
}
if ( ! V_40 || ! F_24 ( V_40 ) ||
( V_40 -> V_509 != V_510 ) )
return V_608 ;
return V_601 ;
}
static int
F_183 ( struct V_4 * V_5 , T_4 V_641 ,
T_6 V_642 , T_8 V_649 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_648 ;
int V_650 ;
V_650 = F_184 ( V_5 , V_641 , V_642 , V_649 ) ;
if ( V_650 )
F_185 ( V_5 ,
& V_8 -> V_179 . V_180 [ V_8 -> V_179 . V_651 ] ,
V_641 , V_642 , V_649 ) ;
V_648 = F_149 ( 2 * V_5 -> V_627 * 1000 ) + V_49 ;
while ( F_148 ( V_648 , V_49 ) && V_650 ) {
F_182 ( F_149 ( 20 ) ) ;
V_650 = F_184 ( V_5 , V_641 , V_642 , V_649 ) ;
}
if ( V_650 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_140 ,
( ( V_649 == V_652 ) ? L_141 :
( ( V_649 == V_653 ) ? L_142 :
( ( V_649 == V_654 ) ? L_143 : L_144 ) ) ) ,
V_650 ) ;
return V_608 ;
}
return V_601 ;
}
static int
F_186 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_641 = V_14 -> V_26 -> V_462 ;
unsigned int V_642 = V_14 -> V_26 -> V_63 ;
struct V_655 V_70 ;
int V_161 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_145 , V_38 ) ;
return V_608 ;
}
V_40 = V_38 -> V_40 ;
V_161 = F_170 ( V_14 ) ;
if ( V_161 != 0 && V_161 != V_601 )
return V_161 ;
V_161 = F_181 ( V_5 , V_14 ) ;
if ( V_161 == V_608 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_146 , V_38 ) ;
return V_608 ;
}
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_656 ;
V_70 . V_63 = V_642 ;
memcpy ( V_70 . V_75 , & V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_40 -> V_79 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_657 ) ;
V_161 = F_178 ( V_5 , V_38 , V_641 , V_642 ,
V_631 ) ;
F_31 ( V_5 , V_20 , V_97 ,
L_147
L_148 , V_641 , V_642 , V_161 ) ;
if ( V_161 == V_601 )
V_161 = F_183 ( V_5 , V_641 , V_642 ,
V_652 ) ;
return V_161 ;
}
static int
F_189 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_641 = V_14 -> V_26 -> V_462 ;
unsigned int V_642 = V_14 -> V_26 -> V_63 ;
struct V_655 V_70 ;
int V_161 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_149 , V_38 ) ;
return V_608 ;
}
V_40 = V_38 -> V_40 ;
V_161 = F_170 ( V_14 ) ;
if ( V_161 != 0 && V_161 != V_601 )
return V_161 ;
V_161 = F_181 ( V_5 , V_14 ) ;
if ( V_161 == V_608 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_150 , V_38 ) ;
return V_608 ;
}
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_658 ;
V_70 . V_63 = 0 ;
memcpy ( V_70 . V_75 , & V_40 -> V_76 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_40 -> V_79 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_657 ) ;
V_161 = F_178 ( V_5 , V_38 , V_641 , V_642 ,
V_632 ) ;
F_31 ( V_5 , V_20 , V_97 ,
L_151
L_148 , V_641 , V_642 , V_161 ) ;
if ( V_161 == V_601 )
V_161 = F_183 ( V_5 , V_641 , V_642 ,
V_653 ) ;
return V_161 ;
}
static int
F_190 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_39 * V_62 = NULL ;
struct V_655 V_70 ;
int V_659 ;
int V_294 = V_601 , V_161 , V_47 ;
V_70 . V_71 = V_72 ;
V_70 . V_73 = V_660 ;
V_70 . V_63 = 0 ;
memcpy ( V_70 . V_75 , & V_5 -> V_661 , sizeof( struct V_77 ) ) ;
memcpy ( V_70 . V_78 , & V_5 -> V_662 , sizeof( struct V_77 ) ) ;
F_187 ( V_45 , F_188 () ,
sizeof( V_70 ) , ( char * ) & V_70 , V_657 ) ;
V_161 = F_170 ( V_14 ) ;
if ( V_161 != 0 && V_161 != V_601 )
return V_161 ;
for ( V_47 = 0 ; V_47 < V_663 ; V_47 ++ ) {
V_659 = 0 ;
F_79 ( V_45 -> V_51 ) ;
F_191 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_24 ( V_62 ) )
continue;
if ( V_5 -> V_8 -> V_664 &&
( V_62 -> V_556 & V_557 ) )
continue;
if ( V_62 -> V_509 == V_510 &&
V_62 -> V_665 == V_47 &&
V_62 -> V_114 ) {
V_659 = 1 ;
break;
}
}
F_81 ( V_45 -> V_51 ) ;
if ( ! V_659 )
continue;
V_161 = F_178 ( V_5 , V_62 -> V_114 -> V_666 ,
V_47 , 0 , V_632 ) ;
if ( V_161 != V_601 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_152 ,
V_47 ) ;
V_294 = V_608 ;
}
}
V_161 = F_183 ( V_5 , 0 , 0 , V_654 ) ;
if ( V_161 != V_601 )
V_294 = V_608 ;
F_31 ( V_5 , V_20 , V_97 ,
L_153 , V_294 ) ;
return V_294 ;
}
static int
F_192 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_210 , V_294 = V_601 ;
F_31 ( V_5 , V_20 , V_97 ,
L_154 ) ;
F_193 ( V_8 , V_667 ) ;
F_194 ( V_8 ) ;
V_210 = F_195 ( V_8 ) ;
if ( V_210 )
V_294 = V_608 ;
V_210 = F_196 ( V_8 ) ;
if ( V_210 )
V_294 = V_608 ;
F_197 ( V_8 ) ;
if ( V_294 == V_608 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_155 ) ;
F_198 ( V_8 ) ;
}
return V_294 ;
}
static int
F_199 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_113 * V_114 = F_46 ( F_47 ( V_3 ) ) ;
T_1 V_668 = 0 ;
T_1 V_115 = 0 ;
int V_669 = 0 ;
T_1 V_670 ;
struct V_10 * V_671 ;
unsigned long V_43 ;
struct V_77 V_672 ;
if ( ! V_114 || F_166 ( V_114 ) )
return - V_673 ;
if ( V_8 -> V_9 ) {
F_200 ( V_114 -> V_674 , V_672 . V_266 . V_267 ) ;
F_20 ( & V_8 -> V_675 , V_43 ) ;
V_671 = F_201 ( V_8 ,
& V_8 -> V_676 ,
& V_5 -> V_661 ,
& V_672 ,
V_3 -> V_63 ) ;
if ( ! V_671 ) {
F_21 ( & V_8 -> V_675 , V_43 ) ;
V_671 = F_202 ( V_8 ,
& V_5 -> V_661 ,
& V_672 ,
V_3 -> V_63 , true ) ;
if ( ! V_671 )
return - V_677 ;
F_20 ( & V_8 -> V_675 , V_43 ) ;
F_25 ( & V_671 -> V_678 , & V_8 -> V_676 ) ;
}
V_671 -> V_11 = V_114 -> V_666 ;
V_671 -> V_679 = true ;
F_21 ( & V_8 -> V_675 , V_43 ) ;
V_3 -> V_7 = V_671 ;
} else {
V_3 -> V_7 = V_114 -> V_666 ;
}
V_670 = F_203 ( & V_8 -> V_670 ) ;
V_668 = V_8 -> V_680 ;
V_115 = V_5 -> V_681 + 2 ;
if ( ( V_670 * ( V_5 -> V_681 + 2 ) ) < V_668 )
return 0 ;
if ( V_668 >= V_8 -> V_682 - V_683 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_156
L_157 , V_668 ) ;
return 0 ;
} else if ( V_668 + V_115 >
V_8 -> V_682 - V_683 ) {
F_31 ( V_5 , V_96 , V_97 ,
L_158
L_159
L_160 ,
V_115 , V_8 -> V_682 ,
( V_8 -> V_682 - V_668 ) ) ;
V_115 = V_8 -> V_682 - V_668 ;
}
V_669 = F_85 ( V_5 , V_115 ) ;
if ( V_115 != V_669 ) {
F_31 ( V_5 , V_20 , V_97 ,
L_161
L_162
L_163 ,
V_115 , V_669 ) ;
}
if ( V_669 > 0 )
V_8 -> V_680 += V_669 ;
return 0 ;
}
static int
F_204 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
if ( V_3 -> V_100 )
F_34 ( V_3 , V_5 -> V_681 ) ;
else
F_35 ( V_3 , V_5 -> V_681 ) ;
if ( V_8 -> V_520 & V_521 ) {
F_164 ( V_8 ,
& V_8 -> V_179 . V_180 [ V_585 ] , V_588 ) ;
if ( V_8 -> V_520 & V_589 )
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
struct V_10 * V_671 = V_3 -> V_7 ;
F_147 ( & V_8 -> V_670 ) ;
if ( ( V_8 -> V_9 ) && ( V_671 ) ) {
F_20 ( & V_8 -> V_675 , V_43 ) ;
V_671 -> V_679 = false ;
if ( ! V_671 -> V_417 )
F_206 ( V_8 , V_671 ) ;
F_21 ( & V_8 -> V_675 , V_43 ) ;
}
V_3 -> V_7 = NULL ;
return;
}
struct V_10 *
F_202 ( struct V_12 * V_8 , struct V_77 * V_684 ,
struct V_77 * V_672 , T_6 V_63 ,
bool V_685 )
{
struct V_10 * V_686 ;
int V_687 ;
if ( F_95 ( ! V_8 ) || ! V_684 || ! V_672 ||
! ( V_8 -> V_9 ) )
return NULL ;
if ( V_685 )
V_687 = V_688 ;
else
V_687 = V_130 ;
V_686 = F_207 ( V_8 -> V_689 , V_687 ) ;
if ( ! V_686 )
return NULL ;
F_87 ( & V_686 -> V_678 ) ;
V_686 -> V_11 = NULL ;
memcpy ( & V_686 -> V_690 . V_684 , V_684 ,
sizeof( struct V_77 ) ) ;
memcpy ( & V_686 -> V_690 . V_672 , V_672 ,
sizeof( struct V_77 ) ) ;
V_686 -> V_690 . V_63 = V_63 ;
V_686 -> V_417 = false ;
V_686 -> V_679 = false ;
return V_686 ;
}
void
F_206 ( struct V_12 * V_8 ,
struct V_10 * V_686 )
{
if ( F_95 ( ! V_8 ) || ! V_686 ||
! ( V_8 -> V_9 ) )
return;
if ( ! F_66 ( & V_686 -> V_678 ) )
F_65 ( & V_686 -> V_678 ) ;
F_208 ( V_686 , V_8 -> V_689 ) ;
return;
}
struct V_10 *
F_201 ( struct V_12 * V_8 , struct V_191 * V_183 ,
struct V_77 * V_684 ,
struct V_77 * V_672 , T_6 V_63 )
{
struct V_10 * V_686 ;
if ( F_95 ( ! V_8 ) || ! V_183 || ! V_684 || ! V_672 ||
! V_8 -> V_9 )
return NULL ;
F_191 (lun_info, list, listentry) {
if ( ( memcmp ( & V_686 -> V_690 . V_684 , V_684 ,
sizeof( struct V_77 ) ) == 0 ) &&
( memcmp ( & V_686 -> V_690 . V_672 , V_672 ,
sizeof( struct V_77 ) ) == 0 ) &&
( V_686 -> V_690 . V_63 == V_63 ) )
return V_686 ;
}
return NULL ;
}
bool
F_209 ( struct V_12 * V_8 , struct V_77 * V_684 ,
struct V_77 * V_672 , T_6 * V_691 ,
struct V_77 * V_692 ,
struct V_77 * V_693 ,
T_6 * V_694 ,
T_1 * V_695 )
{
unsigned long V_43 ;
struct V_10 * V_686 ;
struct V_696 * V_690 ;
T_6 V_63 ;
bool V_227 = false ;
if ( F_95 ( ! V_8 ) || ! V_684 || ! V_672 ||
! V_691 || ! V_692 ||
! V_693 || ! V_694 || ! V_695 ||
( * V_691 == V_697 ) ||
! V_8 -> V_9 )
return false ;
V_63 = * V_691 ;
* V_694 = V_697 ;
* V_691 = V_697 ;
F_20 ( & V_8 -> V_675 , V_43 ) ;
F_191 (lun_info, &phba->luns, listentry) {
if ( ( ( F_210 ( V_684 -> V_266 . V_267 ) == 0 ) ||
( memcmp ( & V_686 -> V_690 . V_684 , V_684 ,
sizeof( struct V_77 ) ) == 0 ) ) &&
( ( F_210 ( V_672 -> V_266 . V_267 ) == 0 ) ||
( memcmp ( & V_686 -> V_690 . V_672 , V_672 ,
sizeof( struct V_77 ) ) == 0 ) ) &&
( V_686 -> V_417 ) ) {
V_690 = & V_686 -> V_690 ;
if ( ( ! V_227 ) &&
( ( V_63 == V_698 ) ||
( V_690 -> V_63 == V_63 ) ) ) {
* V_694 = V_690 -> V_63 ;
memcpy ( V_692 ,
& V_690 -> V_684 ,
sizeof( struct V_77 ) ) ;
memcpy ( V_693 ,
& V_690 -> V_672 ,
sizeof( struct V_77 ) ) ;
if ( V_686 -> V_679 )
* V_695 =
V_699 ;
else
* V_695 = 0 ;
if ( V_8 -> V_700 & V_701 )
memset ( V_684 , 0x0 ,
sizeof( struct V_77 ) ) ;
if ( V_8 -> V_700 & V_702 )
memset ( V_672 , 0x0 ,
sizeof( struct V_77 ) ) ;
V_227 = true ;
} else if ( V_227 ) {
* V_691 = V_690 -> V_63 ;
memcpy ( V_684 , & V_690 -> V_684 ,
sizeof( struct V_77 ) ) ;
memcpy ( V_672 , & V_690 -> V_672 ,
sizeof( struct V_77 ) ) ;
break;
}
}
}
F_21 ( & V_8 -> V_675 , V_43 ) ;
return V_227 ;
}
bool
F_211 ( struct V_12 * V_8 , struct V_77 * V_684 ,
struct V_77 * V_672 , T_6 V_63 )
{
struct V_10 * V_686 ;
unsigned long V_43 ;
if ( F_95 ( ! V_8 ) || ! V_684 || ! V_672 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_675 , V_43 ) ;
V_686 = F_201 ( V_8 , & V_8 -> V_676 , V_684 ,
V_672 , V_63 ) ;
if ( V_686 ) {
if ( ! V_686 -> V_417 )
V_686 -> V_417 = true ;
F_21 ( & V_8 -> V_675 , V_43 ) ;
return true ;
}
V_686 = F_202 ( V_8 , V_684 , V_672 , V_63 ,
false ) ;
if ( V_686 ) {
V_686 -> V_417 = true ;
V_686 -> V_679 = false ;
F_25 ( & V_686 -> V_678 , & V_8 -> V_676 ) ;
F_21 ( & V_8 -> V_675 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_675 , V_43 ) ;
return false ;
}
bool
F_212 ( struct V_12 * V_8 , struct V_77 * V_684 ,
struct V_77 * V_672 , T_6 V_63 )
{
struct V_10 * V_686 ;
unsigned long V_43 ;
if ( F_95 ( ! V_8 ) || ! V_684 || ! V_672 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_675 , V_43 ) ;
V_686 = F_201 ( V_8 ,
& V_8 -> V_676 , V_684 ,
V_672 , V_63 ) ;
if ( V_686 ) {
V_686 -> V_417 = false ;
if ( ! V_686 -> V_679 )
F_206 ( V_8 , V_686 ) ;
F_21 ( & V_8 -> V_675 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_675 , V_43 ) ;
return false ;
}
