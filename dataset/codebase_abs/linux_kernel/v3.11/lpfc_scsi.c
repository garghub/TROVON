static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
void * V_5 , * V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( ! V_9 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_1 ,
V_12 ) ;
return;
}
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_2 ) ;
return;
}
V_6 = ( void * ) V_9 ;
while ( V_8 ) {
V_5 = F_4 ( V_8 ) ;
memcpy ( V_6 , V_5 , V_8 -> V_13 ) ;
V_6 += V_8 -> V_13 ;
V_8 = F_5 ( V_8 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
void * V_5 , * V_6 ;
struct V_7 * V_8 = F_7 ( V_4 ) ;
if ( ! V_14 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_3 ,
V_12 ) ;
return;
}
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_4 ) ;
return;
}
V_6 = V_14 ;
while ( V_8 ) {
V_5 = F_4 ( V_8 ) ;
memcpy ( V_6 , V_5 , V_8 -> V_13 ) ;
V_6 += V_8 -> V_13 ;
V_8 = F_5 ( V_8 ) ;
}
}
static inline unsigned
F_8 ( struct V_3 * V_15 )
{
return V_15 -> V_16 -> V_17 ;
}
static inline unsigned
F_9 ( struct V_3 * V_15 , int V_18 )
{
return 1 ;
}
static inline unsigned
F_10 ( struct V_3 * V_15 )
{
if ( F_11 ( NULL , V_15 ) == V_19 )
return 0 ;
if ( F_12 ( V_15 -> V_16 -> V_20 ) == V_21 )
return 1 ;
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
if ( V_25 ) {
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 1 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
}
}
static void
F_17 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_29 * V_30 = V_23 -> V_30 ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_3 * V_33 = V_23 -> V_34 ;
unsigned long V_35 ;
struct V_36 * V_37 = V_33 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
unsigned long V_41 ;
int V_42 ;
if ( V_33 -> V_43 )
return;
V_41 = F_18 ( ( long ) V_44 - ( long ) V_23 -> V_45 ) ;
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( ! V_39 -> V_47 ||
V_39 -> V_48 ||
! V_32 ||
! V_32 -> V_49 ||
( V_2 -> V_50 == V_51 ) ) {
F_20 ( V_37 -> V_46 , V_35 ) ;
return;
}
if ( V_2 -> V_50 == V_52 ) {
V_42 = ( V_41 + V_2 -> V_53 - 1 - V_2 -> V_54 ) /
V_2 -> V_53 ;
if ( V_42 < 0 )
V_42 = 0 ;
else if ( V_42 >= V_55 )
V_42 = V_55 - 1 ;
} else {
for ( V_42 = 0 ; V_42 < V_55 - 1 ; V_42 ++ )
if ( V_41 <= ( V_2 -> V_54 +
( ( 1 << V_42 ) * V_2 -> V_53 ) ) )
break;
}
V_32 -> V_49 [ V_42 ] . V_56 ++ ;
F_20 ( V_37 -> V_46 , V_35 ) ;
}
static void
F_21 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_31 * V_57 ,
T_1 V_58 ,
T_1 V_59 ,
T_1 V_60 )
{
struct V_61 * V_62 ;
unsigned long V_35 ;
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_64 . V_65 . V_66 =
V_67 ;
V_62 -> V_63 . V_64 . V_65 . V_68 =
V_69 ;
V_62 -> V_63 . V_64 . V_65 . V_58 = V_58 ;
if ( V_57 && F_23 ( V_57 ) ) {
memcpy ( & V_62 -> V_63 . V_64 . V_65 . V_70 ,
& V_57 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_64 . V_65 . V_73 ,
& V_57 -> V_74 , sizeof( struct V_72 ) ) ;
}
V_62 -> V_63 . V_64 . V_75 = V_59 ;
V_62 -> V_63 . V_64 . V_76 = V_60 ;
V_62 -> V_39 = V_39 ;
V_62 -> V_77 . V_78 = V_79 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
F_24 ( & V_62 -> V_77 . V_81 , & V_2 -> V_82 ) ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_25 ( V_2 ) ;
return;
}
int
F_26 ( struct V_83 * V_84 , int V_85 , int V_86 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_29 * V_30 ;
unsigned long V_87 , V_88 ;
V_88 = V_84 -> V_89 ;
F_27 ( V_84 , F_28 ( V_84 ) , V_85 ) ;
V_87 = V_84 -> V_89 ;
V_30 = V_84 -> V_40 ;
if ( V_30 )
F_21 ( V_2 , V_39 ,
V_30 -> V_32 , V_84 -> V_58 ,
V_88 ,
V_87 ) ;
return V_84 -> V_89 ;
}
static int
F_29 ( struct V_83 * V_84 , int V_90 )
{
if ( V_84 -> V_91 ) {
F_30 ( V_84 , V_90 ) ;
if ( V_90 )
F_31 ( V_84 , V_84 -> V_89 ) ;
else
F_32 ( V_84 , V_84 -> V_89 ) ;
} else
V_90 = 0 ;
return V_90 ;
}
void
F_33 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
T_1 V_92 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
F_34 ( & V_2 -> V_93 ) ;
V_2 -> V_94 = V_44 ;
if ( ( V_2 -> V_95 + V_96 ) > V_44 ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
return;
}
V_2 -> V_95 = V_44 ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( & V_2 -> V_97 -> V_98 , V_35 ) ;
V_92 = V_2 -> V_97 -> V_99 & V_100 ;
if ( ! V_92 )
V_2 -> V_97 -> V_99 |= V_100 ;
F_20 ( & V_2 -> V_97 -> V_98 , V_35 ) ;
if ( ! V_92 )
F_25 ( V_2 ) ;
return;
}
static inline void
F_35 ( struct V_38 * V_39 ,
T_1 V_89 )
{
unsigned long V_35 ;
struct V_1 * V_2 = V_39 -> V_2 ;
T_1 V_92 ;
F_34 ( & V_2 -> V_101 ) ;
if ( V_39 -> V_102 <= V_89 )
return;
F_19 ( & V_2 -> V_80 , V_35 ) ;
if ( F_36 ( V_44 ,
V_2 -> V_103 + V_104 ) ||
F_36 ( V_44 ,
V_2 -> V_94 + V_104 ) ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
return;
}
V_2 -> V_103 = V_44 ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( & V_2 -> V_97 -> V_98 , V_35 ) ;
V_92 = V_2 -> V_97 -> V_99 & V_105 ;
if ( ! V_92 )
V_2 -> V_97 -> V_99 |= V_105 ;
F_20 ( & V_2 -> V_97 -> V_98 , V_35 ) ;
if ( ! V_92 )
F_25 ( V_2 ) ;
return;
}
void
F_37 ( struct V_1 * V_2 )
{
struct V_38 * * V_106 ;
struct V_36 * V_37 ;
struct V_83 * V_84 ;
unsigned long V_87 ;
unsigned long V_93 , V_101 ;
int V_42 ;
V_93 = F_38 ( & V_2 -> V_93 ) ;
V_101 = F_38 ( & V_2 -> V_101 ) ;
if ( V_93 == 0 )
return;
V_106 = F_39 ( V_2 ) ;
if ( V_106 != NULL )
for ( V_42 = 0 ; V_42 <= V_2 -> V_107 && V_106 [ V_42 ] != NULL ; V_42 ++ ) {
V_37 = F_40 ( V_106 [ V_42 ] ) ;
F_41 (sdev, shost) {
V_87 =
V_84 -> V_89 * V_93 /
( V_93 + V_101 ) ;
if ( ! V_87 )
V_87 = V_84 -> V_89 - 1 ;
else
V_87 = V_84 -> V_89 -
V_87 ;
F_26 ( V_84 , V_87 ,
V_108 ) ;
}
}
F_42 ( V_2 , V_106 ) ;
F_43 ( & V_2 -> V_93 , 0 ) ;
F_43 ( & V_2 -> V_101 , 0 ) ;
}
void
F_44 ( struct V_1 * V_2 )
{
struct V_38 * * V_106 ;
struct V_36 * V_37 ;
struct V_83 * V_84 ;
int V_42 ;
V_106 = F_39 ( V_2 ) ;
if ( V_106 != NULL )
for ( V_42 = 0 ; V_42 <= V_2 -> V_107 && V_106 [ V_42 ] != NULL ; V_42 ++ ) {
V_37 = F_40 ( V_106 [ V_42 ] ) ;
F_41 (sdev, shost) {
if ( V_106 [ V_42 ] -> V_102 <=
V_84 -> V_89 )
continue;
F_26 ( V_84 ,
V_84 -> V_89 + 1 ,
V_109 ) ;
}
}
F_42 ( V_2 , V_106 ) ;
F_43 ( & V_2 -> V_93 , 0 ) ;
F_43 ( & V_2 -> V_101 , 0 ) ;
}
void
F_45 ( struct V_1 * V_2 )
{
struct V_38 * * V_106 ;
struct V_36 * V_37 ;
struct V_83 * V_84 ;
struct V_110 * V_111 ;
int V_42 ;
V_106 = F_39 ( V_2 ) ;
if ( V_106 != NULL )
for ( V_42 = 0 ; V_42 <= V_2 -> V_107 && V_106 [ V_42 ] != NULL ; V_42 ++ ) {
V_37 = F_40 ( V_106 [ V_42 ] ) ;
F_41 (sdev, shost) {
V_111 = F_46 ( F_47 ( V_84 ) ) ;
F_48 ( V_111 ) ;
}
}
F_42 ( V_2 , V_106 ) ;
}
static int
F_49 ( struct V_38 * V_39 , int V_112 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_22 * V_113 ;
struct V_114 * V_115 ;
T_2 * V_116 ;
T_3 V_117 ;
T_3 V_118 ;
T_3 V_119 ;
T_4 V_120 ;
int V_121 , V_122 ;
V_122 = V_2 -> V_123 -
( sizeof( struct V_124 ) + sizeof( struct V_125 ) ) ;
F_50 ( V_39 , V_126 , V_127 ,
L_5 ,
V_112 , V_2 -> V_123 ,
( int ) sizeof( struct V_124 ) ,
( int ) sizeof( struct V_125 ) , V_122 ) ;
for ( V_121 = 0 ; V_121 < V_112 ; V_121 ++ ) {
V_113 = F_51 ( sizeof( struct V_22 ) , V_128 ) ;
if ( ! V_113 )
break;
V_113 -> V_129 = F_52 ( V_2 -> V_130 ,
V_128 , & V_113 -> V_131 ) ;
if ( ! V_113 -> V_129 ) {
F_53 ( V_113 ) ;
break;
}
memset ( V_113 -> V_129 , 0 , V_2 -> V_123 ) ;
V_120 = F_54 ( V_2 , & V_113 -> V_132 ) ;
if ( V_120 == 0 ) {
F_55 ( V_2 -> V_130 ,
V_113 -> V_129 , V_113 -> V_131 ) ;
F_53 ( V_113 ) ;
break;
}
V_113 -> V_132 . V_133 |= V_134 ;
V_113 -> V_124 = V_113 -> V_129 ;
V_113 -> V_125 = V_113 -> V_129 + sizeof( struct V_124 ) ;
V_113 -> V_26 = V_113 -> V_129 + sizeof( struct V_124 ) +
sizeof( struct V_125 ) ;
V_115 = V_113 -> V_26 ;
V_117 = V_113 -> V_131 ;
V_118 = V_113 -> V_131 + sizeof( struct V_124 ) ;
V_119 = V_113 -> V_131 + sizeof( struct V_124 ) +
sizeof( struct V_125 ) ;
V_115 [ 0 ] . V_135 = F_14 ( F_56 ( V_117 ) ) ;
V_115 [ 0 ] . V_136 = F_14 ( F_57 ( V_117 ) ) ;
V_115 [ 0 ] . V_137 . V_138 . V_139 = sizeof( struct V_124 ) ;
V_115 [ 0 ] . V_137 . V_138 . V_140 = V_141 ;
V_115 [ 0 ] . V_137 . V_142 = F_14 ( V_115 [ 0 ] . V_137 . V_142 ) ;
V_115 [ 1 ] . V_135 = F_14 ( F_56 ( V_118 ) ) ;
V_115 [ 1 ] . V_136 = F_14 ( F_57 ( V_118 ) ) ;
V_115 [ 1 ] . V_137 . V_138 . V_139 = sizeof( struct V_125 ) ;
V_115 [ 1 ] . V_137 . V_138 . V_140 = V_141 ;
V_115 [ 1 ] . V_137 . V_142 = F_14 ( V_115 [ 1 ] . V_137 . V_142 ) ;
V_116 = & V_113 -> V_132 . V_116 ;
V_116 -> V_63 . V_143 . V_144 . V_145 = 0 ;
if ( ( V_2 -> V_146 == 3 ) &&
! ( V_2 -> V_147 & V_148 ) ) {
V_116 -> V_63 . V_143 . V_144 . V_140 = V_149 ;
V_116 -> V_63 . V_143 . V_144 . V_139 = sizeof( struct V_124 ) ;
V_116 -> V_63 . V_143 . V_144 . V_136 = F_58 ( T_2 ,
V_150 . V_151 . V_152 ) ;
V_116 -> V_63 . V_143 . V_144 . V_135 = 0 ;
V_116 -> V_153 = 0 ;
V_116 -> V_154 = 0 ;
V_116 -> V_150 . V_151 . V_155 . V_137 . V_138 . V_140 =
V_141 ;
V_116 -> V_150 . V_151 . V_155 . V_137 . V_138 . V_139 =
sizeof( struct V_125 ) ;
V_116 -> V_150 . V_151 . V_155 . V_136 =
F_57 ( V_118 ) ;
V_116 -> V_150 . V_151 . V_155 . V_135 =
F_56 ( V_118 ) ;
} else {
V_116 -> V_63 . V_143 . V_144 . V_140 = V_156 ;
V_116 -> V_63 . V_143 . V_144 . V_139 =
( 2 * sizeof( struct V_114 ) ) ;
V_116 -> V_63 . V_143 . V_144 . V_136 =
F_57 ( V_119 ) ;
V_116 -> V_63 . V_143 . V_144 . V_135 =
F_56 ( V_119 ) ;
V_116 -> V_153 = 1 ;
V_116 -> V_154 = 1 ;
}
V_116 -> V_157 = V_158 ;
V_113 -> V_159 = V_160 ;
V_113 -> V_132 . V_161 = V_113 ;
F_59 ( V_2 , V_113 ) ;
}
return V_121 ;
}
void
F_60 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_22 * V_113 , * V_162 ;
unsigned long V_163 = 0 ;
F_19 ( & V_2 -> V_80 , V_163 ) ;
F_61 ( & V_2 -> V_164 . V_165 ) ;
F_62 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_113 -> V_30 && V_113 -> V_30 -> V_32
&& V_113 -> V_30 -> V_32 -> V_39 == V_39 )
V_113 -> V_30 = NULL ;
}
F_63 ( & V_2 -> V_164 . V_165 ) ;
F_20 ( & V_2 -> V_80 , V_163 ) ;
}
void
F_64 ( struct V_1 * V_2 ,
struct V_166 * V_167 )
{
T_4 V_168 = F_65 ( V_169 , V_167 ) ;
T_4 V_170 = F_65 ( V_171 , V_167 ) ;
struct V_22 * V_113 , * V_162 ;
unsigned long V_163 = 0 ;
struct V_172 * V_173 ;
int V_42 ;
struct V_31 * V_57 ;
int V_174 = 0 ;
struct V_175 * V_176 = & V_2 -> V_177 . V_178 [ V_179 ] ;
F_19 ( & V_2 -> V_80 , V_163 ) ;
F_61 ( & V_2 -> V_164 . V_165 ) ;
F_62 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_113 -> V_132 . V_180 == V_168 ) {
F_66 ( & V_113 -> V_181 ) ;
V_113 -> V_182 = 0 ;
V_113 -> V_159 = V_160 ;
F_63 (
& V_2 -> V_164 . V_165 ) ;
if ( V_113 -> V_30 && V_113 -> V_30 -> V_32 )
V_57 = V_113 -> V_30 -> V_32 ;
else
V_57 = NULL ;
V_174 = F_67 ( & V_2 -> V_183 ) ;
F_20 ( & V_2 -> V_80 , V_163 ) ;
if ( V_57 ) {
F_68 ( V_2 , V_57 ,
V_113 -> V_132 . V_184 , V_170 , 1 ) ;
F_69 ( V_2 , V_57 , V_167 ) ;
}
F_70 ( V_2 , V_113 ) ;
if ( V_174 )
F_25 ( V_2 ) ;
return;
}
}
F_63 ( & V_2 -> V_164 . V_165 ) ;
for ( V_42 = 1 ; V_42 <= V_2 -> V_177 . V_185 ; V_42 ++ ) {
V_173 = V_2 -> V_177 . V_186 [ V_42 ] ;
if ( ! ( V_173 -> V_133 & V_134 ) ||
( V_173 -> V_133 & V_187 ) )
continue;
if ( V_173 -> V_180 != V_168 )
continue;
V_113 = F_71 ( V_173 , struct V_22 , V_132 ) ;
V_113 -> V_182 = 0 ;
F_20 ( & V_2 -> V_80 , V_163 ) ;
if ( ! F_67 ( & V_176 -> V_188 ) )
F_25 ( V_2 ) ;
return;
}
F_20 ( & V_2 -> V_80 , V_163 ) ;
}
int
F_72 ( struct V_1 * V_2 ,
struct V_189 * V_190 , int V_191 )
{
struct V_22 * V_113 , * V_192 ;
int V_159 , V_193 ;
int V_194 = 0 , V_195 = 0 , V_196 = 0 , V_197 = 0 ;
T_3 V_198 ;
int V_199 = V_200 ;
F_73 ( V_201 ) ;
F_73 ( V_202 ) ;
F_73 ( V_203 ) ;
if ( V_191 <= 0 )
return - V_204 ;
V_193 = V_2 -> V_123 -
( sizeof( struct V_124 ) + sizeof( struct V_125 ) ) ;
F_62 (psb, psb_next, post_sblist, list) {
F_74 ( & V_113 -> V_181 ) ;
V_195 ++ ;
if ( ( V_199 != V_200 ) &&
( V_113 -> V_132 . V_180 != V_199 + 1 ) ) {
F_75 ( & V_201 , & V_202 ) ;
V_194 = V_195 - 1 ;
F_24 ( & V_113 -> V_181 , & V_201 ) ;
V_195 = 1 ;
} else {
F_24 ( & V_113 -> V_181 , & V_201 ) ;
if ( V_195 == V_205 ) {
F_75 ( & V_201 , & V_202 ) ;
V_194 = V_195 ;
V_195 = 0 ;
}
}
V_196 ++ ;
V_199 = V_113 -> V_132 . V_180 ;
if ( V_196 == V_191 ) {
if ( V_194 == 0 ) {
F_75 ( & V_201 , & V_202 ) ;
V_194 = V_195 ;
} else if ( V_195 == 1 ) {
if ( V_193 > V_206 )
V_198 = V_113 -> V_207 +
V_206 ;
else
V_198 = 0 ;
V_159 = F_76 ( V_2 ,
V_113 -> V_207 ,
V_198 ,
V_113 -> V_132 . V_180 ) ;
if ( V_159 ) {
V_113 -> V_182 = 1 ;
} else {
V_113 -> V_182 = 0 ;
V_113 -> V_159 = V_160 ;
V_197 ++ ;
}
F_24 ( & V_113 -> V_181 , & V_203 ) ;
}
}
if ( V_194 == 0 )
continue;
V_159 = F_77 ( V_2 , & V_202 ,
V_194 ) ;
if ( V_195 == 0 )
V_199 = V_200 ;
V_194 = 0 ;
while ( ! F_67 ( & V_202 ) ) {
F_78 ( & V_202 , V_113 ,
struct V_22 , V_181 ) ;
if ( V_159 ) {
V_113 -> V_182 = 1 ;
} else {
V_113 -> V_182 = 0 ;
V_113 -> V_159 = V_160 ;
V_197 ++ ;
}
F_24 ( & V_113 -> V_181 , & V_203 ) ;
}
}
while ( ! F_67 ( & V_203 ) ) {
F_78 ( & V_203 , V_113 ,
struct V_22 , V_181 ) ;
F_70 ( V_2 , V_113 ) ;
}
return V_197 ;
}
int
F_79 ( struct V_1 * V_2 )
{
F_73 ( V_190 ) ;
int V_197 , V_208 = 0 ;
F_80 ( & V_2 -> V_209 ) ;
F_80 ( & V_2 -> V_210 ) ;
F_75 ( & V_2 -> V_211 , & V_190 ) ;
F_81 ( & V_2 -> V_212 , & V_190 ) ;
F_82 ( & V_2 -> V_210 ) ;
F_82 ( & V_2 -> V_209 ) ;
if ( ! F_67 ( & V_190 ) ) {
V_197 = F_72 ( V_2 , & V_190 ,
V_2 -> V_164 . V_213 ) ;
if ( V_197 == 0 )
V_208 = - V_214 ;
}
return V_208 ;
}
static int
F_83 ( struct V_38 * V_39 , int V_112 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_22 * V_113 ;
struct V_24 * V_25 ;
T_2 * V_116 ;
T_3 V_117 ;
T_3 V_118 ;
T_3 V_119 ;
T_4 V_120 , V_215 = 0 ;
int V_121 , V_197 , V_193 ;
F_73 ( V_201 ) ;
F_73 ( V_190 ) ;
F_73 ( V_203 ) ;
V_193 = V_2 -> V_123 -
( sizeof( struct V_124 ) + sizeof( struct V_125 ) ) ;
F_50 ( V_39 , V_126 , V_127 ,
L_6 ,
V_112 , V_2 -> V_123 , V_193 ,
( int ) sizeof( struct V_124 ) ,
( int ) sizeof( struct V_125 ) ) ;
for ( V_121 = 0 ; V_121 < V_112 ; V_121 ++ ) {
V_113 = F_51 ( sizeof( struct V_22 ) , V_128 ) ;
if ( ! V_113 )
break;
V_113 -> V_129 = F_52 ( V_2 -> V_130 ,
V_128 , & V_113 -> V_131 ) ;
if ( ! V_113 -> V_129 ) {
F_53 ( V_113 ) ;
break;
}
memset ( V_113 -> V_129 , 0 , V_2 -> V_123 ) ;
if ( ( ( unsigned long ) ( V_113 -> V_129 ) &
( unsigned long ) ( V_216 - 1 ) ) != 0 ) {
F_55 ( V_2 -> V_130 ,
V_113 -> V_129 , V_113 -> V_131 ) ;
F_53 ( V_113 ) ;
break;
}
V_120 = F_54 ( V_2 , & V_113 -> V_132 ) ;
if ( V_120 == 0 ) {
F_55 ( V_2 -> V_130 ,
V_113 -> V_129 , V_113 -> V_131 ) ;
F_53 ( V_113 ) ;
break;
}
V_215 = F_84 ( V_2 ) ;
if ( V_215 == V_200 ) {
F_55 ( V_2 -> V_130 ,
V_113 -> V_129 , V_113 -> V_131 ) ;
F_53 ( V_113 ) ;
break;
}
V_113 -> V_132 . V_184 = V_215 ;
V_113 -> V_132 . V_180 = V_2 -> V_164 . V_217 [ V_215 ] ;
V_113 -> V_132 . V_133 |= V_134 ;
V_113 -> V_26 = V_113 -> V_129 ;
V_113 -> V_124 = ( V_113 -> V_129 + V_193 ) ;
V_113 -> V_125 = (struct V_125 * ) ( ( V_218 * ) V_113 -> V_124 +
sizeof( struct V_124 ) ) ;
V_25 = (struct V_24 * ) V_113 -> V_26 ;
V_119 = V_113 -> V_131 ;
V_117 = ( V_113 -> V_131 + V_193 ) ;
V_118 = V_117 + sizeof( struct V_124 ) ;
V_25 -> V_219 = F_16 ( F_56 ( V_117 ) ) ;
V_25 -> V_220 = F_16 ( F_57 ( V_117 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_221 = F_16 ( sizeof( struct V_124 ) ) ;
V_25 ++ ;
V_25 -> V_219 = F_16 ( F_56 ( V_118 ) ) ;
V_25 -> V_220 = F_16 ( F_57 ( V_118 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 1 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_221 = F_16 ( sizeof( struct V_125 ) ) ;
V_116 = & V_113 -> V_132 . V_116 ;
V_116 -> V_63 . V_143 . V_144 . V_145 = 0 ;
V_116 -> V_63 . V_143 . V_144 . V_140 = V_141 ;
V_116 -> V_63 . V_143 . V_144 . V_139 = sizeof( struct V_124 ) ;
V_116 -> V_63 . V_143 . V_144 . V_136 = F_57 ( V_117 ) ;
V_116 -> V_63 . V_143 . V_144 . V_135 = F_56 ( V_117 ) ;
V_116 -> V_153 = 1 ;
V_116 -> V_154 = 1 ;
V_116 -> V_157 = V_158 ;
V_113 -> V_132 . V_161 = V_113 ;
V_113 -> V_207 = V_119 ;
F_24 ( & V_113 -> V_181 , & V_190 ) ;
F_80 ( & V_2 -> V_209 ) ;
V_2 -> V_164 . V_213 ++ ;
F_82 ( & V_2 -> V_209 ) ;
}
F_3 ( V_2 , V_126 , V_11 ,
L_7
L_8 , V_121 , V_112 ) ;
if ( ! F_67 ( & V_190 ) )
V_197 = F_72 ( V_2 ,
& V_190 , V_121 ) ;
else
V_197 = 0 ;
return V_197 ;
}
static inline int
F_85 ( struct V_38 * V_39 , int V_112 )
{
return V_39 -> V_2 -> F_85 ( V_39 , V_112 ) ;
}
static struct V_22 *
F_86 ( struct V_1 * V_2 , struct V_31 * V_57 )
{
struct V_22 * V_23 = NULL ;
struct V_189 * V_222 = & V_2 -> V_211 ;
unsigned long V_223 = 0 ;
unsigned long V_224 = 0 ;
F_19 ( & V_2 -> V_209 , V_223 ) ;
F_78 ( V_222 , V_23 , struct V_22 ,
V_181 ) ;
if ( ! V_23 ) {
F_19 ( & V_2 -> V_210 , V_224 ) ;
F_81 ( & V_2 -> V_212 ,
& V_2 -> V_211 ) ;
F_87 ( & V_2 -> V_212 ) ;
F_78 ( V_222 , V_23 ,
struct V_22 , V_181 ) ;
F_20 ( & V_2 -> V_210 , V_224 ) ;
}
F_20 ( & V_2 -> V_209 , V_223 ) ;
return V_23 ;
}
static struct V_22 *
F_88 ( struct V_1 * V_2 , struct V_31 * V_57 )
{
struct V_22 * V_23 , * V_225 ;
unsigned long V_223 = 0 ;
unsigned long V_224 = 0 ;
int V_226 = 0 ;
F_19 ( & V_2 -> V_209 , V_223 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 ( V_2 , V_57 ,
V_23 -> V_132 . V_184 ) )
continue;
F_66 ( & V_23 -> V_181 ) ;
V_226 = 1 ;
break;
}
if ( ! V_226 ) {
F_19 ( & V_2 -> V_210 , V_224 ) ;
F_81 ( & V_2 -> V_212 ,
& V_2 -> V_211 ) ;
F_87 ( & V_2 -> V_212 ) ;
F_20 ( & V_2 -> V_210 , V_224 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 (
V_2 , V_57 , V_23 -> V_132 . V_184 ) )
continue;
F_66 ( & V_23 -> V_181 ) ;
V_226 = 1 ;
break;
}
}
F_20 ( & V_2 -> V_209 , V_223 ) ;
if ( ! V_226 )
return NULL ;
return V_23 ;
}
static struct V_22 *
F_90 ( struct V_1 * V_2 , struct V_31 * V_57 )
{
return V_2 -> F_90 ( V_2 , V_57 ) ;
}
static void
F_59 ( struct V_1 * V_2 , struct V_22 * V_113 )
{
unsigned long V_163 = 0 ;
V_113 -> V_227 = 0 ;
V_113 -> V_228 = 0 ;
V_113 -> V_229 = 0 ;
F_19 ( & V_2 -> V_210 , V_163 ) ;
V_113 -> V_34 = NULL ;
V_113 -> V_132 . V_133 = V_134 ;
F_24 ( & V_113 -> V_181 , & V_2 -> V_212 ) ;
F_20 ( & V_2 -> V_210 , V_163 ) ;
}
static void
F_70 ( struct V_1 * V_2 , struct V_22 * V_113 )
{
unsigned long V_163 = 0 ;
V_113 -> V_227 = 0 ;
V_113 -> V_228 = 0 ;
V_113 -> V_229 = 0 ;
if ( V_113 -> V_182 ) {
F_19 ( & V_2 -> V_164 . V_165 ,
V_163 ) ;
V_113 -> V_34 = NULL ;
F_24 ( & V_113 -> V_181 ,
& V_2 -> V_164 . V_230 ) ;
F_20 ( & V_2 -> V_164 . V_165 ,
V_163 ) ;
} else {
V_113 -> V_34 = NULL ;
V_113 -> V_132 . V_133 = V_134 ;
F_19 ( & V_2 -> V_210 , V_163 ) ;
F_24 ( & V_113 -> V_181 , & V_2 -> V_212 ) ;
F_20 ( & V_2 -> V_210 , V_163 ) ;
}
}
static void
F_91 ( struct V_1 * V_2 , struct V_22 * V_113 )
{
V_2 -> F_91 ( V_2 , V_113 ) ;
}
static int
F_92 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_7 * V_231 = NULL ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_114 * V_115 = V_23 -> V_26 ;
struct V_172 * V_173 = & V_23 -> V_132 ;
T_2 * V_232 = & V_23 -> V_132 . V_116 ;
struct V_114 * V_233 = V_232 -> V_150 . V_151 . V_234 ;
T_3 V_235 ;
T_1 V_236 = 0 ;
int V_237 , V_238 = V_3 -> V_239 ;
V_115 += 2 ;
if ( F_93 ( V_3 ) ) {
V_237 = F_94 ( & V_2 -> V_240 -> V_241 , F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_238 ) ;
if ( F_95 ( ! V_237 ) )
return 1 ;
V_23 -> V_227 = V_237 ;
if ( V_23 -> V_227 > V_2 -> V_242 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_9
L_10 ,
V_12 , V_2 -> V_242 ,
V_23 -> V_227 ) ;
V_23 -> V_227 = 0 ;
F_96 ( V_3 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_235 = F_98 ( V_231 ) ;
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) &&
! ( V_173 -> V_133 & V_243 ) &&
V_237 <= V_244 ) {
V_233 -> V_137 . V_138 . V_140 = V_141 ;
V_233 -> V_137 . V_138 . V_139 = F_99 ( V_231 ) ;
V_233 -> V_136 = F_57 ( V_235 ) ;
V_233 -> V_135 = F_56 ( V_235 ) ;
V_233 ++ ;
} else {
V_115 -> V_137 . V_138 . V_140 = V_141 ;
V_115 -> V_137 . V_138 . V_139 = F_99 ( V_231 ) ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_115 -> V_136 =
F_14 ( F_57 ( V_235 ) ) ;
V_115 -> V_135 =
F_14 ( F_56 ( V_235 ) ) ;
V_115 ++ ;
}
}
}
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) &&
! ( V_173 -> V_133 & V_243 ) ) {
if ( V_236 > V_244 ) {
V_235 = V_23 -> V_131 ;
V_233 -> V_137 . V_138 . V_140 = V_156 ;
V_233 -> V_137 . V_138 . V_139 = ( V_236 *
sizeof( struct V_114 ) ) ;
V_235 += ( sizeof( struct V_124 ) +
sizeof( struct V_125 ) +
( 2 * sizeof( struct V_114 ) ) ) ;
V_233 -> V_135 = F_56 ( V_235 ) ;
V_233 -> V_136 = F_57 ( V_235 ) ;
V_232 -> V_150 . V_151 . V_245 = 2 ;
} else {
V_232 -> V_150 . V_151 . V_245 = ( V_236 + 1 ) ;
}
} else {
V_232 -> V_63 . V_143 . V_144 . V_139 =
( ( V_236 + 2 ) * sizeof( struct V_114 ) ) ;
V_232 -> V_150 . V_151 . V_245 = ( V_236 + 1 ) ;
}
V_124 -> V_246 = F_100 ( F_101 ( V_3 ) ) ;
V_232 -> V_63 . V_247 . V_248 = F_101 ( V_3 ) ;
return 0 ;
}
static int
F_102 ( struct V_1 * V_2 , struct V_3 * V_15 ,
T_1 * V_249 , T_4 * V_250 , T_1 V_251 )
{
struct V_7 * V_252 ;
struct V_7 * V_8 ;
struct V_22 * V_23 = NULL ;
struct V_253 * V_5 = NULL ;
struct V_31 * V_57 ;
struct V_29 * V_30 ;
T_1 V_254 = F_103 ( V_15 ) ;
T_1 V_255 ;
T_1 V_256 ;
T_5 V_257 ;
int V_208 = 0 ;
int V_258 = 0 ;
if ( V_254 == V_259 )
return 0 ;
V_252 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
V_257 = F_104 ( V_15 ) ;
if ( V_2 -> V_260 != V_261 ) {
V_255 = F_8 ( V_15 ) ;
V_256 = ( F_101 ( V_15 ) + V_255 - 1 ) / V_255 ;
if ( ( V_2 -> V_260 < V_257 ) ||
( V_2 -> V_260 >= ( V_257 + V_256 ) ) )
return 0 ;
if ( V_252 ) {
V_258 = V_2 -> V_260 - V_257 ;
V_256 = F_99 ( V_252 ) /
sizeof( struct V_253 ) ;
if ( V_256 < V_258 )
V_258 = V_256 ;
}
}
V_30 = V_15 -> V_16 -> V_40 ;
if ( V_30 && V_30 -> V_32 ) {
V_57 = V_30 -> V_32 ;
if ( V_2 -> V_262 &&
( V_2 -> V_262 != V_57 -> V_263 ) )
return 0 ;
if ( V_2 -> V_264 . V_265 . V_266 [ 0 ] &&
( memcmp ( & V_57 -> V_71 , & V_2 -> V_264 ,
sizeof( struct V_72 ) ) != 0 ) )
return 0 ;
}
if ( V_252 ) {
V_5 = (struct V_253 * ) F_4 ( V_252 ) ;
V_5 += V_258 ;
V_23 = (struct V_22 * ) V_15 -> V_267 ;
}
if ( V_249 ) {
if ( V_2 -> V_268 ) {
switch ( V_254 ) {
case V_269 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_11
L_12 ,
( unsigned long ) V_257 , V_258 ,
F_105 ( V_5 -> V_270 ) ) ;
if ( V_23 ) {
V_23 -> V_271 =
V_272 ;
V_23 -> V_273 =
V_5 ;
V_23 -> V_274 =
V_5 -> V_270 ;
}
V_5 -> V_270 = F_100 ( 0xDEADBEEF ) ;
V_2 -> V_268 -- ;
if ( V_2 -> V_268 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_275 | V_276 ;
break;
}
case V_277 :
* V_249 = 0xDEADBEEF ;
V_2 -> V_268 -- ;
if ( V_2 -> V_268 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_275 | V_276 ;
F_3 ( V_2 , V_10 , V_11 ,
L_13
L_14 , ( unsigned long ) V_257 ) ;
break;
case V_278 :
* V_249 = 0xDEADBEEF ;
V_2 -> V_268 -- ;
if ( V_2 -> V_268 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 ;
F_3 ( V_2 , V_10 , V_11 ,
L_15
L_14 , ( unsigned long ) V_257 ) ;
break;
}
}
if ( V_2 -> V_280 ) {
switch ( V_254 ) {
case V_281 :
case V_282 :
case V_283 :
* V_249 = 0xDEADBEEF ;
V_2 -> V_280 -- ;
if ( V_2 -> V_280 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 ;
F_3 ( V_2 , V_10 , V_11 ,
L_16
L_17 , ( unsigned long ) V_257 ) ;
break;
}
}
}
if ( V_250 ) {
if ( V_2 -> V_284 ) {
switch ( V_254 ) {
case V_269 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_18
L_19 ,
( unsigned long ) V_257 , V_258 ,
F_106 ( V_5 -> V_285 ) ) ;
if ( V_23 ) {
V_23 -> V_271 =
V_286 ;
V_23 -> V_273 =
V_5 ;
V_23 -> V_274 =
V_5 -> V_285 ;
}
V_5 -> V_285 = F_107 ( 0xDEAD ) ;
V_2 -> V_284 -- ;
if ( V_2 -> V_284 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_275 | V_276 ;
break;
}
case V_277 :
* V_250 = 0xDEAD ;
V_2 -> V_284 -- ;
if ( V_2 -> V_284 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_275 | V_276 ;
F_3 ( V_2 , V_10 , V_11 ,
L_20
L_14 , ( unsigned long ) V_257 ) ;
break;
case V_278 :
* V_250 = 0xDEAD ;
V_2 -> V_284 -- ;
if ( V_2 -> V_284 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 ;
F_3 ( V_2 , V_10 , V_11 ,
L_21
L_14 , ( unsigned long ) V_257 ) ;
break;
}
}
if ( V_2 -> V_287 ) {
switch ( V_254 ) {
case V_281 :
case V_282 :
case V_283 :
* V_250 = 0xDEAD ;
V_2 -> V_287 -- ;
if ( V_2 -> V_287 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 ;
F_3 ( V_2 , V_10 , V_11 ,
L_22
L_17 , ( unsigned long ) V_257 ) ;
break;
}
}
}
if ( V_251 ) {
if ( V_2 -> V_288 ) {
switch ( V_254 ) {
case V_269 :
V_208 = V_276 ;
case V_277 :
V_2 -> V_288 -- ;
if ( V_2 -> V_288 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 |= V_275 | V_289 ;
F_3 ( V_2 , V_10 , V_11 ,
L_23
L_14 , ( unsigned long ) V_257 ) ;
break;
case V_278 :
V_2 -> V_288 -- ;
if ( V_2 -> V_288 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 | V_289 ;
F_3 ( V_2 , V_10 , V_11 ,
L_24
L_14 , ( unsigned long ) V_257 ) ;
break;
}
}
if ( V_2 -> V_290 ) {
switch ( V_254 ) {
case V_281 :
case V_282 :
case V_283 :
V_2 -> V_290 -- ;
if ( V_2 -> V_290 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_260 =
V_261 ;
memset ( & V_2 -> V_264 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_279 | V_289 ;
F_3 ( V_2 , V_10 , V_11 ,
L_25
L_17 , ( unsigned long ) V_257 ) ;
}
}
}
return V_208 ;
}
static int
F_108 ( struct V_1 * V_2 , struct V_3 * V_15 ,
V_218 * V_291 , V_218 * V_292 )
{
V_218 V_293 = 0 ;
if ( F_10 ( V_15 ) ) {
switch ( F_103 ( V_15 ) ) {
case V_281 :
case V_278 :
* V_292 = V_294 ;
* V_291 = V_295 ;
break;
case V_282 :
case V_277 :
* V_292 = V_296 ;
* V_291 = V_297 ;
break;
case V_283 :
case V_269 :
* V_292 = V_298 ;
* V_291 = V_299 ;
break;
case V_259 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_26 ,
F_103 ( V_15 ) ) ;
V_293 = 1 ;
break;
}
} else {
switch ( F_103 ( V_15 ) ) {
case V_282 :
case V_277 :
* V_292 = V_296 ;
* V_291 = V_297 ;
break;
case V_283 :
case V_269 :
* V_292 = V_300 ;
* V_291 = V_300 ;
break;
case V_281 :
case V_278 :
* V_292 = V_297 ;
* V_291 = V_296 ;
break;
case V_259 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_27 ,
F_103 ( V_15 ) ) ;
V_293 = 1 ;
break;
}
}
return V_293 ;
}
static int
F_109 ( struct V_1 * V_2 , struct V_3 * V_15 ,
V_218 * V_291 , V_218 * V_292 )
{
V_218 V_293 = 0 ;
if ( F_10 ( V_15 ) ) {
switch ( F_103 ( V_15 ) ) {
case V_281 :
case V_278 :
* V_292 = V_297 ;
* V_291 = V_296 ;
break;
case V_282 :
case V_277 :
* V_292 = V_295 ;
* V_291 = V_294 ;
break;
case V_283 :
case V_269 :
* V_292 = V_299 ;
* V_291 = V_298 ;
break;
case V_259 :
default:
break;
}
} else {
switch ( F_103 ( V_15 ) ) {
case V_282 :
case V_277 :
* V_292 = V_295 ;
* V_291 = V_294 ;
break;
case V_283 :
case V_269 :
* V_292 = V_301 ;
* V_291 = V_301 ;
break;
case V_281 :
case V_278 :
* V_292 = V_294 ;
* V_291 = V_295 ;
break;
case V_259 :
default:
break;
}
}
return V_293 ;
}
static int
F_110 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_114 * V_115 , int V_302 )
{
struct V_7 * V_8 = NULL ;
struct V_303 * V_304 = NULL ;
struct V_305 * V_306 = NULL ;
T_3 V_235 ;
int V_42 = 0 , V_236 = 0 , V_159 ;
int V_238 = V_15 -> V_239 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_307 = 1 ;
T_1 V_249 ;
unsigned V_255 ;
V_218 V_291 , V_292 ;
V_159 = F_108 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_159 )
goto V_308;
V_255 = F_8 ( V_15 ) ;
V_249 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_249 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_289 )
F_109 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_208 & V_276 )
V_307 = 0 ;
}
#endif
V_304 = (struct V_303 * ) V_115 ;
memset ( V_304 , 0 , sizeof( struct V_303 ) ) ;
F_15 ( V_309 , V_304 , V_310 ) ;
V_304 -> V_311 = F_16 ( V_304 -> V_311 ) ;
V_304 -> V_249 = F_16 ( V_249 ) ;
V_236 ++ ;
V_115 ++ ;
V_306 = (struct V_305 * ) V_115 ;
memset ( V_306 , 0 , sizeof( struct V_305 ) ) ;
F_15 ( V_312 , V_306 , V_313 ) ;
F_15 ( V_314 , V_306 , V_291 ) ;
F_15 ( V_315 , V_306 , V_292 ) ;
if ( V_238 == V_316 ) {
if ( F_9 ( V_15 , V_317 ) )
F_15 ( V_318 , V_306 , V_307 ) ;
else
F_15 ( V_318 , V_306 , 0 ) ;
if ( F_9 ( V_15 , V_319 ) )
F_15 ( V_320 , V_306 , V_307 ) ;
else
F_15 ( V_320 , V_306 , 0 ) ;
}
F_15 ( V_321 , V_306 , 1 ) ;
F_15 ( V_322 , V_306 , 0 ) ;
F_15 ( V_323 , V_306 , 0 ) ;
V_306 -> V_311 = F_16 ( V_306 -> V_311 ) ;
V_306 -> V_324 = F_16 ( V_306 -> V_324 ) ;
V_306 -> V_27 = F_16 ( V_306 -> V_27 ) ;
V_236 ++ ;
V_115 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_235 = F_98 ( V_8 ) ;
V_115 -> V_136 = F_14 ( F_57 ( V_235 ) ) ;
V_115 -> V_135 = F_14 ( F_56 ( V_235 ) ) ;
V_115 -> V_137 . V_138 . V_139 = F_99 ( V_8 ) ;
if ( V_238 == V_325 )
V_115 -> V_137 . V_138 . V_140 = V_141 ;
else
V_115 -> V_137 . V_138 . V_140 = V_326 ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_115 ++ ;
V_236 ++ ;
}
V_308:
return V_236 ;
}
static int
F_112 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_114 * V_115 , int V_327 , int V_328 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_252 = NULL ;
struct V_303 * V_304 = NULL ;
struct V_305 * V_306 = NULL ;
struct V_329 * V_330 = NULL ;
T_3 V_331 , V_332 ;
unsigned short V_333 = 0 , V_334 = 0 ;
unsigned int V_335 ;
unsigned int V_336 , V_337 = 0 , V_338 ;
unsigned int V_339 , V_340 ;
unsigned int V_341 , V_342 ;
int V_159 ;
int V_238 = V_15 -> V_239 ;
unsigned char V_343 = 0 , V_344 = 0 ;
unsigned V_255 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_307 = 1 ;
T_1 V_249 ;
V_218 V_291 , V_292 ;
int V_236 = 0 ;
V_252 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
if ( ! V_252 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_127 ,
L_28 ,
V_252 , V_8 ) ;
return 0 ;
}
V_159 = F_108 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_159 )
goto V_308;
V_255 = F_8 ( V_15 ) ;
V_249 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_249 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_289 )
F_109 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_208 & V_276 )
V_307 = 0 ;
}
#endif
V_335 = 0 ;
do {
if ( V_236 >= ( V_2 -> V_345 - 2 ) )
return V_236 + 3 ;
V_304 = (struct V_303 * ) V_115 ;
memset ( V_304 , 0 , sizeof( struct V_303 ) ) ;
F_15 ( V_309 , V_304 , V_310 ) ;
V_304 -> V_311 = F_16 ( V_304 -> V_311 ) ;
V_304 -> V_249 = F_16 ( V_249 ) ;
V_236 ++ ;
V_115 ++ ;
V_306 = (struct V_305 * ) V_115 ;
memset ( V_306 , 0 , sizeof( struct V_305 ) ) ;
F_15 ( V_312 , V_306 , V_313 ) ;
F_15 ( V_314 , V_306 , V_291 ) ;
F_15 ( V_315 , V_306 , V_292 ) ;
if ( F_9 ( V_15 , V_317 ) )
F_15 ( V_318 , V_306 , V_307 ) ;
else
F_15 ( V_318 , V_306 , 0 ) ;
if ( F_9 ( V_15 , V_319 ) )
F_15 ( V_320 , V_306 , V_307 ) ;
else
F_15 ( V_320 , V_306 , 0 ) ;
F_15 ( V_321 , V_306 , 1 ) ;
F_15 ( V_322 , V_306 , 0 ) ;
F_15 ( V_323 , V_306 , 0 ) ;
V_306 -> V_311 = F_16 ( V_306 -> V_311 ) ;
V_306 -> V_324 = F_16 ( V_306 -> V_324 ) ;
V_306 -> V_27 = F_16 ( V_306 -> V_27 ) ;
V_236 ++ ;
V_115 ++ ;
V_332 = F_98 ( V_252 ) + V_337 ;
V_336 = F_99 ( V_252 ) - V_337 ;
F_113 ( V_336 % 8 ) ;
V_330 = (struct V_329 * ) V_115 ;
memset ( V_330 , 0 , sizeof( struct V_329 ) ) ;
F_15 ( V_346 , V_330 , V_347 ) ;
V_330 -> V_135 = F_14 ( F_56 ( V_332 ) ) ;
V_330 -> V_136 = F_14 ( F_57 ( V_332 ) ) ;
V_339 = V_336 / 8 ;
V_340 = V_339 * V_255 ;
if ( ( V_330 -> V_136 & 0xfff ) + V_336 > 0x1000 ) {
V_338 = 0x1000 - ( V_330 -> V_136 & 0xfff ) ;
V_337 += V_338 ;
V_339 = V_338 / 8 ;
V_340 = V_339 * V_255 ;
} else {
V_337 = 0 ;
V_334 ++ ;
}
V_236 ++ ;
V_343 = 0 ;
V_342 = 0 ;
while ( ! V_343 ) {
if ( V_236 >= V_2 -> V_345 )
return V_236 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_29 ,
V_12 ) ;
return 0 ;
}
V_115 ++ ;
V_331 = F_98 ( V_8 ) + V_335 ;
V_115 -> V_136 = F_14 ( F_57 ( V_331 ) ) ;
V_115 -> V_135 = F_14 ( F_56 ( V_331 ) ) ;
V_341 = F_99 ( V_8 ) - V_335 ;
if ( ( V_342 + V_341 ) <= V_340 ) {
V_115 -> V_137 . V_138 . V_139 = V_341 ;
V_335 = 0 ;
if ( ( V_342 + V_341 ) == V_340 )
V_343 = 1 ;
} else {
V_115 -> V_137 . V_138 . V_139 = V_340 - V_342 ;
V_335 += V_115 -> V_137 . V_138 . V_139 ;
}
V_342 += V_115 -> V_137 . V_138 . V_139 ;
if ( V_238 == V_325 )
V_115 -> V_137 . V_138 . V_140 = V_141 ;
else
V_115 -> V_137 . V_138 . V_140 = V_326 ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_236 ++ ;
V_333 ++ ;
if ( V_335 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_337 ) {
V_249 += V_339 ;
V_115 ++ ;
continue;
}
if ( V_334 == V_328 ) {
V_344 = 1 ;
} else if ( V_334 < V_328 ) {
V_252 = F_5 ( V_252 ) ;
V_115 ++ ;
V_249 += V_339 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_30 , V_12 ) ;
}
} while ( ! V_344 );
V_308:
return V_236 ;
}
static int
F_114 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_24 * V_25 , int V_302 )
{
struct V_7 * V_8 = NULL ;
struct V_348 * V_349 = NULL ;
T_3 V_235 ;
int V_42 = 0 , V_350 = 0 , V_159 ;
T_1 V_249 ;
unsigned V_255 ;
V_218 V_291 , V_292 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_307 = 1 ;
T_1 V_351 ;
T_1 V_352 = 0 ;
V_159 = F_108 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_159 )
goto V_308;
V_255 = F_8 ( V_15 ) ;
V_249 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_249 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_289 )
F_109 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_208 & V_276 )
V_307 = 0 ;
}
#endif
V_349 = (struct V_348 * ) V_25 ;
memset ( V_349 , 0 , sizeof( struct V_348 ) ) ;
F_15 ( V_353 , V_25 , V_354 ) ;
V_349 -> V_270 = F_16 ( V_249 ) ;
V_349 -> V_355 = V_349 -> V_270 ;
if ( V_15 -> V_239 == V_316 ) {
if ( F_9 ( V_15 , V_317 ) )
F_15 ( V_356 , V_349 , V_307 ) ;
else
F_15 ( V_356 , V_349 , 0 ) ;
if ( F_9 ( V_15 , V_319 ) )
F_15 ( V_357 , V_349 , V_307 ) ;
else
F_15 ( V_357 , V_349 , 0 ) ;
}
F_15 ( V_358 , V_349 , V_291 ) ;
F_15 ( V_359 , V_349 , V_292 ) ;
F_15 ( V_360 , V_349 , 1 ) ;
F_15 ( V_361 , V_349 , 0 ) ;
V_349 -> V_27 = F_16 ( V_349 -> V_27 ) ;
V_349 -> V_362 = F_16 ( V_349 -> V_362 ) ;
V_350 ++ ;
V_25 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_235 = F_98 ( V_8 ) ;
V_351 = F_99 ( V_8 ) ;
V_25 -> V_220 = F_16 ( F_57 ( V_235 ) ) ;
V_25 -> V_219 = F_16 ( F_56 ( V_235 ) ) ;
if ( ( V_42 + 1 ) == V_302 )
F_15 ( V_28 , V_25 , 1 ) ;
else
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_363 , V_25 , V_352 ) ;
F_15 ( V_353 , V_25 , V_364 ) ;
V_25 -> V_221 = F_16 ( V_351 ) ;
V_352 += V_351 ;
V_25 ++ ;
V_350 ++ ;
}
V_308:
return V_350 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_24 * V_25 , int V_327 , int V_328 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_252 = NULL ;
struct V_348 * V_349 = NULL ;
T_3 V_331 , V_332 ;
unsigned short V_333 = 0 , V_334 = 0 ;
unsigned int V_335 ;
unsigned int V_336 , V_337 = 0 , V_338 ;
unsigned int V_339 , V_340 ;
unsigned int V_341 , V_342 ;
int V_159 ;
unsigned char V_343 = 0 , V_344 = 0 ;
unsigned V_255 ;
T_1 V_249 ;
V_218 V_291 , V_292 ;
T_1 V_351 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_307 = 1 ;
T_1 V_352 = 0 ;
int V_350 = 0 ;
V_252 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
if ( ! V_252 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_127 ,
L_31 ,
V_252 , V_8 ) ;
return 0 ;
}
V_159 = F_108 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_159 )
goto V_308;
V_255 = F_8 ( V_15 ) ;
V_249 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_249 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_289 )
F_109 ( V_2 , V_15 , & V_291 , & V_292 ) ;
if ( V_208 & V_276 )
V_307 = 0 ;
}
#endif
V_335 = 0 ;
do {
if ( V_350 >= ( V_2 -> V_345 - 2 ) )
return V_350 + 3 ;
V_349 = (struct V_348 * ) V_25 ;
memset ( V_349 , 0 , sizeof( struct V_348 ) ) ;
F_15 ( V_353 , V_25 , V_354 ) ;
V_349 -> V_270 = F_16 ( V_249 ) ;
V_349 -> V_355 = V_349 -> V_270 ;
if ( F_9 ( V_15 , V_317 ) ) {
F_15 ( V_356 , V_349 , V_307 ) ;
} else {
F_15 ( V_356 , V_349 , 0 ) ;
if ( V_291 == V_300 ) {
V_291 = V_365 ;
V_292 = V_365 ;
}
}
if ( F_9 ( V_15 , V_319 ) )
F_15 ( V_357 , V_349 , V_307 ) ;
else
F_15 ( V_357 , V_349 , 0 ) ;
F_15 ( V_358 , V_349 , V_291 ) ;
F_15 ( V_359 , V_349 , V_292 ) ;
F_15 ( V_360 , V_349 , 1 ) ;
F_15 ( V_361 , V_349 , 0 ) ;
V_349 -> V_27 = F_16 ( V_349 -> V_27 ) ;
V_349 -> V_362 = F_16 ( V_349 -> V_362 ) ;
V_350 ++ ;
V_25 ++ ;
V_332 = F_98 ( V_252 ) + V_337 ;
V_336 = F_99 ( V_252 ) - V_337 ;
F_113 ( V_336 % 8 ) ;
V_25 -> V_27 = 0 ;
F_15 ( V_353 , V_25 , V_366 ) ;
V_25 -> V_219 = F_14 ( F_56 ( V_332 ) ) ;
V_25 -> V_220 = F_14 ( F_57 ( V_332 ) ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_339 = V_336 / 8 ;
V_340 = V_339 * V_255 ;
if ( ( V_25 -> V_220 & 0xfff ) + V_336 > 0x1000 ) {
V_338 = 0x1000 - ( V_25 -> V_220 & 0xfff ) ;
V_337 += V_338 ;
V_339 = V_338 / 8 ;
V_340 = V_339 * V_255 ;
} else {
V_337 = 0 ;
V_334 ++ ;
}
V_350 ++ ;
V_343 = 0 ;
V_342 = 0 ;
while ( ! V_343 ) {
if ( V_350 >= V_2 -> V_345 )
return V_350 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_32 ,
V_12 ) ;
return 0 ;
}
V_25 ++ ;
V_331 = F_98 ( V_8 ) + V_335 ;
V_341 = F_99 ( V_8 ) - V_335 ;
if ( ( V_342 + V_341 ) <= V_340 ) {
V_351 = V_341 ;
V_335 = 0 ;
if ( ( V_342 + V_341 ) == V_340 )
V_343 = 1 ;
} else {
V_351 = V_340 - V_342 ;
V_335 += V_351 ;
}
V_342 += V_351 ;
V_25 -> V_220 = F_16 ( F_57 ( V_331 ) ) ;
V_25 -> V_219 = F_16 ( F_56 ( V_331 ) ) ;
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_363 , V_25 , V_352 ) ;
F_15 ( V_353 , V_25 , V_364 ) ;
V_25 -> V_221 = F_16 ( V_351 ) ;
V_352 += V_351 ;
V_350 ++ ;
V_333 ++ ;
if ( V_335 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_337 ) {
V_249 += V_339 ;
V_25 ++ ;
continue;
}
if ( V_334 == V_328 ) {
F_15 ( V_28 , V_25 , 1 ) ;
V_344 = 1 ;
} else if ( V_334 < V_328 ) {
V_252 = F_5 ( V_252 ) ;
V_25 ++ ;
V_249 += V_339 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_33 , V_12 ) ;
}
} while ( ! V_344 );
V_308:
return V_350 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_3 * V_15 )
{
int V_293 = V_367 ;
unsigned char V_254 = F_103 ( V_15 ) ;
switch ( V_254 ) {
case V_282 :
case V_277 :
V_293 = V_19 ;
break;
case V_281 :
case V_278 :
case V_283 :
case V_269 :
V_293 = V_368 ;
break;
default:
if ( V_2 )
F_3 ( V_2 , V_10 , V_127 ,
L_34 ,
V_254 ) ;
break;
}
return V_293 ;
}
static int
F_116 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_15 = V_23 -> V_34 ;
int V_369 ;
V_369 = F_101 ( V_15 ) ;
if ( V_15 -> V_239 == V_316 ) {
if ( F_103 ( V_15 ) == V_281 )
return V_369 ;
} else {
if ( F_103 ( V_15 ) == V_278 )
return V_369 ;
}
V_369 += ( V_369 / F_8 ( V_15 ) ) * 8 ;
return V_369 ;
}
static int
F_117 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_114 * V_115 = V_23 -> V_26 ;
T_2 * V_232 = & V_23 -> V_132 . V_116 ;
T_1 V_236 = 0 ;
int V_302 , V_370 , V_238 = V_3 -> V_239 ;
int V_371 = 0 ;
int V_369 ;
V_115 += 2 ;
if ( F_93 ( V_3 ) ) {
V_302 = F_94 ( & V_2 -> V_240 -> V_241 ,
F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_238 ) ;
if ( F_95 ( ! V_302 ) )
return 1 ;
V_23 -> V_227 = V_302 ;
if ( V_23 -> V_227 > V_2 -> V_242 )
goto V_372;
V_371 = F_11 ( V_2 , V_3 ) ;
switch ( V_371 ) {
case V_19 :
if ( ( V_23 -> V_227 + 2 ) > V_2 -> V_345 )
goto V_372;
V_236 = F_110 ( V_2 , V_3 , V_115 ,
V_302 ) ;
if ( V_236 < 2 )
goto V_372;
break;
case V_368 :
V_370 = F_94 ( & V_2 -> V_240 -> V_241 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_238 ) ;
if ( F_95 ( ! V_370 ) ) {
F_96 ( V_3 ) ;
return 1 ;
}
V_23 -> V_229 = V_370 ;
if ( ( V_23 -> V_229 * 4 ) >
( V_2 -> V_345 - 2 ) )
goto V_372;
V_236 = F_112 ( V_2 , V_3 , V_115 ,
V_302 , V_370 ) ;
if ( ( V_236 < 3 ) ||
( V_236 > V_2 -> V_345 ) )
goto V_372;
break;
case V_367 :
default:
F_96 ( V_3 ) ;
V_23 -> V_227 = 0 ;
F_3 ( V_2 , V_10 , V_127 ,
L_35 ,
V_371 ) ;
return 1 ;
}
}
V_232 -> V_63 . V_143 . V_144 . V_139 = ( 2 * sizeof( struct V_114 ) ) ;
V_232 -> V_63 . V_143 . V_144 . V_139 += ( V_236 * sizeof( struct V_114 ) ) ;
V_232 -> V_153 = 1 ;
V_232 -> V_154 = 1 ;
V_369 = F_116 ( V_2 , V_23 ) ;
V_124 -> V_246 = F_105 ( V_369 ) ;
V_232 -> V_63 . V_247 . V_248 = V_369 ;
return 0 ;
V_372:
if ( V_23 -> V_227 )
F_96 ( V_3 ) ;
if ( V_23 -> V_229 )
F_119 ( & V_2 -> V_240 -> V_241 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_239 ) ;
F_3 ( V_2 , V_10 , V_127 ,
L_36
L_37 ,
V_23 -> V_227 , V_23 -> V_229 ,
V_2 -> V_345 , V_2 -> V_242 ,
V_371 , V_236 ) ;
V_23 -> V_227 = 0 ;
V_23 -> V_229 = 0 ;
return 1 ;
}
T_4
F_120 ( V_218 * V_129 , int V_373 )
{
T_4 V_374 = 0 ;
T_4 V_375 ;
V_374 = F_121 ( V_129 , V_373 ) ;
V_375 = F_107 ( V_374 ) ;
return V_375 ;
}
T_4
F_122 ( V_218 * V_129 , int V_373 )
{
T_4 V_293 ;
V_293 = F_123 ( V_129 , V_373 ) ;
return V_293 ;
}
void
F_124 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_7 * V_252 ;
struct V_7 * V_8 ;
struct V_3 * V_33 = V_23 -> V_34 ;
struct V_253 * V_5 = NULL ;
V_218 * V_376 = NULL ;
T_4 V_377 , V_378 ;
T_4 V_379 , V_285 ;
T_1 V_380 , V_270 ;
int V_381 , V_370 ;
int V_382 , V_383 , V_384 ;
int V_385 , V_386 , V_387 ;
T_4 V_388 ;
unsigned V_255 ;
V_382 = V_389 ;
V_388 = 0 ;
V_377 = 0 ;
V_381 = F_103 ( V_33 ) ;
if ( ( V_381 == V_282 ) ||
( V_381 == V_277 ) ||
( V_381 == V_259 ) )
goto V_308;
V_385 = 1 ;
V_386 = 0 ;
V_387 = 0 ;
V_252 = F_7 ( V_33 ) ;
V_370 = V_23 -> V_229 ;
if ( V_252 && V_370 ) {
V_8 = F_2 ( V_33 ) ;
V_255 = F_8 ( V_33 ) ;
V_376 = ( V_218 * ) F_4 ( V_8 ) ;
V_384 = V_8 -> V_13 ;
if ( ( V_384 & ( V_255 - 1 ) ) == 0 )
V_387 = 1 ;
V_378 = F_12 ( V_33 -> V_16 -> V_20 ) ;
V_5 = (struct V_253 * ) F_4 ( V_252 ) ;
V_380 = ( T_1 ) F_104 ( V_33 ) ;
V_379 = V_5 -> V_285 ;
V_383 = V_252 -> V_13 ;
while ( V_5 && V_370 ) {
while ( V_383 ) {
if ( ( V_5 -> V_270 == 0xffffffff ) ||
( V_5 -> V_285 == 0xffff ) ) {
V_380 ++ ;
goto V_390;
}
if ( V_387 ) {
V_377 = V_5 -> V_377 ;
if ( F_10 ( V_33 ) )
V_388 = F_122 ( V_376 ,
V_255 ) ;
else
V_388 = F_120 ( V_376 ,
V_255 ) ;
if ( ( V_377 != V_388 ) ) {
V_382 = V_389 ;
goto V_308;
}
}
V_270 = F_105 ( V_5 -> V_270 ) ;
if ( V_385 && ( V_270 != V_380 ) ) {
V_382 = V_391 ;
goto V_308;
}
V_380 ++ ;
V_285 = V_5 -> V_285 ;
if ( V_386 && ( V_285 != V_379 ) ) {
V_382 = V_392 ;
goto V_308;
}
V_390:
V_383 -= sizeof( struct V_253 ) ;
if ( V_383 < 0 )
V_383 = 0 ;
V_5 ++ ;
V_376 += V_255 ;
V_384 -= V_255 ;
if ( V_387 && ( V_384 == 0 ) ) {
V_387 = 0 ;
V_8 = F_5 ( V_8 ) ;
if ( ! V_8 )
goto V_308;
V_376 = ( V_218 * ) F_4 ( V_8 ) ;
V_384 = V_8 -> V_13 ;
if ( ( V_384 & ( V_255 - 1 ) ) == 0 )
V_387 = 1 ;
}
}
V_252 = F_5 ( V_252 ) ;
if ( V_252 ) {
V_5 = (struct V_253 * ) F_4 ( V_252 ) ;
V_383 = V_252 -> V_13 ;
} else {
V_5 = NULL ;
}
V_370 -- ;
}
}
V_308:
if ( V_382 == V_389 ) {
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x1 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_398 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_38 ,
( unsigned long ) F_104 ( V_33 ) ,
V_388 , V_377 ) ;
} else if ( V_382 == V_391 ) {
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x3 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_39 ,
( unsigned long ) F_104 ( V_33 ) ,
V_270 , V_380 ) ;
} else if ( V_382 == V_392 ) {
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x2 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_401 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_40 ,
( unsigned long ) F_104 ( V_33 ) ,
V_285 , V_379 ) ;
}
}
static int
F_127 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_172 * V_402 )
{
struct V_3 * V_33 = V_23 -> V_34 ;
struct V_403 * V_404 = & V_402 -> V_116 . V_150 . V_405 ;
int V_293 = 0 ;
T_1 V_406 = V_404 -> V_406 ;
T_1 V_407 = V_404 -> V_407 ;
T_6 V_408 = 0 ;
F_61 ( & V_409 ) ;
if ( ! V_410 ) {
F_3 ( V_2 , V_10 , V_11 , L_41
L_42 ,
( V_33 -> V_4 [ 7 ] << 8 | V_33 -> V_4 [ 8 ] ) ) ;
F_1 ( V_2 , V_33 ) ;
if ( F_11 ( V_2 , V_33 ) ==
V_368 ) {
F_3 ( V_2 , V_10 , V_11 , L_43
L_44 ,
( V_33 -> V_4 [ 7 ] << 8 | V_33 -> V_4 [ 8 ] ) ) ;
F_6 ( V_2 , V_33 ) ;
}
V_410 = 1 ;
}
F_63 ( & V_409 ) ;
if ( F_128 ( V_407 ) ) {
V_33 -> V_43 = F_126 ( V_411 , 0 ) ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_45
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
V_293 = ( - 1 ) ;
goto V_308;
}
if ( F_130 ( V_407 ) ) {
V_33 -> V_43 = F_126 ( V_411 , 0 ) ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_48
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
V_293 = ( - 1 ) ;
goto V_308;
}
if ( F_131 ( V_407 ) ) {
V_293 = 1 ;
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x1 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_398 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_49
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_132 ( V_407 ) ) {
V_293 = 1 ;
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x3 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_50
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_133 ( V_407 ) ) {
V_293 = 1 ;
F_125 ( 1 , V_33 -> V_393 , V_394 ,
0x10 , 0x2 ) ;
V_33 -> V_43 = V_395 << 24
| F_126 ( V_396 , V_397 ) ;
V_2 -> V_401 ++ ;
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_51
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
}
if ( F_134 ( V_407 ) ) {
V_33 -> V_393 [ 7 ] = 0xc ;
V_33 -> V_393 [ 8 ] = 0 ;
V_33 -> V_393 [ 9 ] = 0xa ;
V_33 -> V_393 [ 10 ] = 0x80 ;
switch ( F_103 ( V_33 ) ) {
case V_281 :
case V_278 :
V_406 /= V_33 -> V_16 -> V_17 ;
break;
case V_282 :
case V_277 :
case V_283 :
case V_269 :
V_406 /= ( V_33 -> V_16 -> V_17 +
sizeof( struct V_253 ) ) ;
break;
}
V_408 = F_104 ( V_33 ) ;
V_408 += V_406 ;
F_135 ( V_408 , & V_33 -> V_393 [ 12 ] ) ;
}
if ( ! V_293 ) {
F_3 ( V_2 , V_399 , V_127 | V_11 ,
L_52
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_412 ) , V_407 , V_406 ) ;
F_124 ( V_2 , V_23 ) ;
}
V_308:
return V_293 ;
}
static int
F_136 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_7 * V_231 = NULL ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
struct V_24 * V_413 ;
T_2 * V_232 = & V_23 -> V_132 . V_116 ;
T_3 V_235 ;
T_1 V_236 = 0 ;
T_1 V_351 ;
T_1 V_352 = 0 ;
int V_237 ;
struct V_114 * V_414 ;
if ( F_93 ( V_3 ) ) {
V_237 = F_137 ( V_3 ) ;
if ( F_95 ( ! V_237 ) )
return 1 ;
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 += 1 ;
V_413 = V_25 ;
V_23 -> V_227 = V_237 ;
if ( V_23 -> V_227 > V_2 -> V_242 ) {
F_3 ( V_2 , V_10 , V_11 , L_53
L_54
L_10 ,
V_12 , V_2 -> V_242 ,
V_23 -> V_227 ) ;
V_23 -> V_227 = 0 ;
F_96 ( V_3 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_235 = F_98 ( V_231 ) ;
V_351 = F_99 ( V_231 ) ;
V_25 -> V_220 = F_16 ( F_57 ( V_235 ) ) ;
V_25 -> V_219 = F_16 ( F_56 ( V_235 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
if ( ( V_236 + 1 ) == V_237 )
F_15 ( V_28 , V_25 , 1 ) ;
else
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_363 , V_25 , V_352 ) ;
F_15 ( V_353 , V_25 , V_364 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_221 = F_16 ( V_351 ) ;
V_352 += V_351 ;
V_25 ++ ;
}
if ( V_2 -> V_147 & V_415 ) {
V_414 = (struct V_114 * )
& ( V_232 -> V_150 . V_416 [ 5 ] ) ;
V_414 -> V_136 = V_413 -> V_220 ;
V_414 -> V_135 = V_413 -> V_219 ;
V_414 -> V_137 . V_138 . V_139 =
F_14 ( V_413 -> V_221 ) ;
V_414 -> V_137 . V_138 . V_140 = V_141 ;
V_414 -> V_137 . V_142 = F_16 ( V_414 -> V_137 . V_142 ) ;
}
} else {
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 1 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
}
V_124 -> V_246 = F_100 ( F_101 ( V_3 ) ) ;
V_232 -> V_63 . V_247 . V_248 = F_101 ( V_3 ) ;
return 0 ;
}
static int
F_138 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_24 * V_25 = (struct V_24 * ) ( V_23 -> V_26 ) ;
T_2 * V_232 = & V_23 -> V_132 . V_116 ;
T_1 V_350 = 0 ;
int V_302 , V_370 , V_238 = V_3 -> V_239 ;
int V_371 = 0 ;
int V_369 ;
if ( F_93 ( V_3 ) ) {
V_302 = F_94 ( & V_2 -> V_240 -> V_241 ,
F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_238 ) ;
if ( F_95 ( ! V_302 ) )
return 1 ;
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 += 1 ;
V_23 -> V_227 = V_302 ;
if ( V_23 -> V_227 > V_2 -> V_242 )
goto V_372;
V_371 = F_11 ( V_2 , V_3 ) ;
switch ( V_371 ) {
case V_19 :
if ( ( V_23 -> V_227 + 1 ) > V_2 -> V_345 )
goto V_372;
V_350 = F_114 ( V_2 , V_3 , V_25 ,
V_302 ) ;
if ( V_350 < 2 )
goto V_372;
break;
case V_368 :
V_370 = F_94 ( & V_2 -> V_240 -> V_241 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_238 ) ;
if ( F_95 ( ! V_370 ) ) {
F_96 ( V_3 ) ;
return 1 ;
}
V_23 -> V_229 = V_370 ;
if ( ( V_23 -> V_229 * 3 ) >
( V_2 -> V_345 - 2 ) )
goto V_372;
V_350 = F_115 ( V_2 , V_3 , V_25 ,
V_302 , V_370 ) ;
if ( ( V_350 < 3 ) ||
( V_350 > V_2 -> V_345 ) )
goto V_372;
break;
case V_367 :
default:
F_96 ( V_3 ) ;
V_23 -> V_227 = 0 ;
F_3 ( V_2 , V_10 , V_127 ,
L_55 ,
V_371 ) ;
return 1 ;
}
}
switch ( F_103 ( V_3 ) ) {
case V_278 :
case V_282 :
V_23 -> V_132 . V_133 |= V_417 ;
break;
case V_277 :
case V_281 :
V_23 -> V_132 . V_133 |= V_418 ;
break;
case V_269 :
case V_283 :
V_23 -> V_132 . V_133 |= V_419 ;
break;
}
V_369 = F_116 ( V_2 , V_23 ) ;
V_124 -> V_246 = F_105 ( V_369 ) ;
V_232 -> V_63 . V_247 . V_248 = V_369 ;
return 0 ;
V_372:
if ( V_23 -> V_227 )
F_96 ( V_3 ) ;
if ( V_23 -> V_229 )
F_119 ( & V_2 -> V_240 -> V_241 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_239 ) ;
F_3 ( V_2 , V_10 , V_127 ,
L_56
L_57 ,
V_23 -> V_227 , V_23 -> V_229 ,
V_2 -> V_345 , V_2 -> V_242 ,
V_371 , V_350 ) ;
V_23 -> V_227 = 0 ;
V_23 -> V_229 = 0 ;
return 1 ;
}
static inline int
F_139 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
return V_2 -> F_139 ( V_2 , V_23 ) ;
}
static inline int
F_140 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
return V_2 -> F_140 ( V_2 , V_23 ) ;
}
static void
F_141 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_22 * V_23 , struct V_172 * V_420 ) {
struct V_3 * V_4 = V_23 -> V_34 ;
struct V_125 * V_421 = V_23 -> V_125 ;
T_1 V_422 = V_421 -> V_423 ;
T_1 V_424 = V_421 -> V_425 ;
T_1 V_248 = V_420 -> V_116 . V_63 . V_247 . V_248 ;
struct V_61 * V_62 = NULL ;
struct V_31 * V_32 = V_23 -> V_30 -> V_32 ;
unsigned long V_35 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return;
if ( ( V_4 -> V_43 == V_426 ) ||
( V_4 -> V_43 == V_427 ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_428 . V_66 =
V_67 ;
V_62 -> V_63 . V_428 . V_68 =
( V_4 -> V_43 == V_426 ) ?
V_429 : V_430 ;
V_62 -> V_63 . V_428 . V_58 = V_4 -> V_16 -> V_58 ;
memcpy ( & V_62 -> V_63 . V_428 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_428 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
} else if ( ( V_422 & V_431 ) && V_421 -> V_432 &&
( ( V_4 -> V_4 [ 0 ] == V_433 ) || ( V_4 -> V_4 [ 0 ] == V_434 ) ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_435 . V_65 . V_66 =
V_67 ;
V_62 -> V_63 . V_435 . V_65 . V_68 =
V_436 ;
V_62 -> V_63 . V_435 . V_65 . V_58 =
V_4 -> V_16 -> V_58 ;
memcpy ( & V_62 -> V_63 . V_435 . V_65 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_435 . V_65 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
V_62 -> V_63 . V_435 . V_437 =
V_4 -> V_393 [ 2 ] & 0xf ;
V_62 -> V_63 . V_435 . V_438 = V_4 -> V_393 [ 12 ] ;
V_62 -> V_63 . V_435 . V_439 = V_4 -> V_393 [ 13 ] ;
} else if ( ( V_4 -> V_239 == V_316 ) &&
V_248 &&
( ( F_105 ( V_421 -> V_440 ) != V_248 ) ||
( ( V_424 == V_441 ) &&
! ( V_422 & ( V_442 | V_443 ) ) ) ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_444 . V_445 . V_66 =
V_446 ;
V_62 -> V_63 . V_444 . V_445 . V_68 =
V_447 ;
memcpy ( & V_62 -> V_63 . V_444 . V_445 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_444 . V_445 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
V_62 -> V_63 . V_444 . V_58 = V_4 -> V_16 -> V_58 ;
V_62 -> V_63 . V_444 . V_448 = V_4 -> V_4 [ 0 ] ;
V_62 -> V_63 . V_444 . V_449 =
V_248 ;
} else
return;
V_62 -> V_39 = V_39 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
F_24 ( & V_62 -> V_77 . V_81 , & V_2 -> V_82 ) ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_25 ( V_2 ) ;
return;
}
static void
F_142 ( struct V_1 * V_2 , struct V_22 * V_113 )
{
if ( V_113 -> V_227 > 0 )
F_96 ( V_113 -> V_34 ) ;
if ( V_113 -> V_229 > 0 )
F_119 ( & V_2 -> V_240 -> V_241 , F_7 ( V_113 -> V_34 ) ,
F_118 ( V_113 -> V_34 ) ,
V_113 -> V_34 -> V_239 ) ;
}
static void
F_143 ( struct V_38 * V_39 , struct V_22 * V_23 ,
struct V_172 * V_420 )
{
struct V_3 * V_4 = V_23 -> V_34 ;
struct V_124 * V_450 = V_23 -> V_124 ;
struct V_125 * V_421 = V_23 -> V_125 ;
T_1 V_248 = V_420 -> V_116 . V_63 . V_247 . V_248 ;
T_1 V_422 = V_421 -> V_423 ;
T_1 V_424 = V_421 -> V_425 ;
T_1 * V_451 ;
T_1 V_452 = V_453 ;
T_1 V_454 = 0 ;
T_1 V_455 = V_127 | V_456 ;
if ( V_450 -> V_457 ) {
V_424 = 0 ;
goto V_308;
}
if ( V_422 & V_458 ) {
V_454 = F_105 ( V_421 -> V_459 ) ;
if ( V_454 != 0 && V_454 != 4 && V_454 != 8 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_58
L_59 ,
V_4 -> V_16 -> V_460 ,
V_4 -> V_16 -> V_58 , V_4 -> V_4 [ 0 ] ,
V_454 ) ;
V_452 = V_411 ;
goto V_308;
}
if ( V_421 -> V_461 != V_462 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_60
L_61
L_62 ,
V_4 -> V_16 -> V_460 ,
V_4 -> V_16 -> V_58 , V_4 -> V_4 [ 0 ] ,
V_421 -> V_461 ) ;
V_452 = V_411 ;
goto V_308;
}
}
if ( ( V_422 & V_431 ) && V_421 -> V_432 ) {
T_1 V_463 = F_105 ( V_421 -> V_432 ) ;
if ( V_463 > V_464 )
V_463 = V_464 ;
if ( V_422 & V_458 )
V_454 = F_105 ( V_421 -> V_459 ) ;
memcpy ( V_4 -> V_393 , & V_421 -> V_465 + V_454 , V_463 ) ;
}
V_451 = ( T_1 * ) V_4 -> V_393 ;
if ( ! V_424 && ( V_422 & V_442 ) ) {
if ( V_39 -> V_466 & V_127 )
V_455 = V_456 ;
if ( V_39 -> V_466 & V_467 )
V_455 = V_467 ;
}
F_50 ( V_39 , V_399 , V_455 ,
L_63
L_64 ,
V_4 -> V_4 [ 0 ] , V_424 ,
F_105 ( * V_451 ) , F_105 ( * ( V_451 + 3 ) ) , V_422 ,
F_105 ( V_421 -> V_440 ) ,
F_105 ( V_421 -> V_432 ) ,
F_105 ( V_421 -> V_459 ) ,
V_421 -> V_461 ) ;
F_144 ( V_4 , 0 ) ;
if ( V_422 & V_442 ) {
F_144 ( V_4 , F_105 ( V_421 -> V_440 ) ) ;
F_50 ( V_39 , V_126 , V_467 ,
L_65
L_66 ,
F_105 ( V_450 -> V_246 ) ,
F_145 ( V_4 ) , V_248 , V_4 -> V_4 [ 0 ] ,
V_4 -> V_468 ) ;
if ( ( V_4 -> V_239 == V_316 ) &&
V_248 &&
( F_145 ( V_4 ) != V_248 ) ) {
F_50 ( V_39 , V_399 ,
V_127 | V_456 ,
L_67
L_68 ,
F_105 ( V_450 -> V_246 ) ,
F_145 ( V_4 ) , V_248 ,
V_4 -> V_4 [ 0 ] ) ;
F_144 ( V_4 , F_101 ( V_4 ) ) ;
V_452 = V_411 ;
}
if ( ! ( V_422 & V_431 ) &&
( V_424 == V_441 ) &&
( F_101 ( V_4 ) - F_145 ( V_4 )
< V_4 -> V_468 ) ) {
F_50 ( V_39 , V_126 , V_127 ,
L_69
L_70
L_71 ,
V_4 -> V_4 [ 0 ] , F_101 ( V_4 ) ,
F_145 ( V_4 ) , V_4 -> V_468 ) ;
V_452 = V_411 ;
}
} else if ( V_422 & V_443 ) {
F_50 ( V_39 , V_399 , V_127 ,
L_72
L_73 , V_4 -> V_4 [ 0 ] ,
F_101 ( V_4 ) , F_145 ( V_4 ) ) ;
V_452 = V_411 ;
} else if ( V_248 ) {
F_50 ( V_39 , V_399 , V_127 | V_456 ,
L_74
L_75 ,
F_105 ( V_450 -> V_246 ) ,
F_105 ( V_421 -> V_440 ) ,
V_248 , V_4 -> V_4 [ 0 ] , V_424 ) ;
switch ( V_424 ) {
case V_441 :
case V_397 :
V_452 = V_411 ;
break;
}
F_144 ( V_4 , F_101 ( V_4 ) ) ;
}
V_308:
V_4 -> V_43 = F_126 ( V_452 , V_424 ) ;
F_141 ( V_39 -> V_2 , V_39 , V_23 , V_420 ) ;
}
static void
F_146 ( struct V_1 * V_2 , struct V_172 * V_469 ,
struct V_172 * V_402 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_469 -> V_161 ;
struct V_38 * V_39 = V_469 -> V_39 ;
struct V_29 * V_30 = V_23 -> V_30 ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_3 * V_33 ;
int V_43 ;
struct V_83 * V_470 ;
int V_471 ;
unsigned long V_35 ;
struct V_61 * V_62 ;
struct V_36 * V_37 ;
T_1 V_89 , V_472 ;
T_1 V_455 = V_127 ;
if ( ! ( V_23 -> V_34 ) )
return;
V_33 = V_23 -> V_34 ;
V_37 = V_33 -> V_16 -> V_20 ;
V_23 -> V_43 = ( V_402 -> V_116 . V_63 . V_473 [ 4 ] & V_474 ) ;
V_23 -> V_159 = V_402 -> V_116 . V_475 ;
V_23 -> V_182 = V_402 -> V_133 & V_476 ;
#ifdef F_111
if ( V_23 -> V_271 ) {
struct V_253 * V_5 = NULL ;
V_5 = (struct V_253 * ) V_23 -> V_273 ;
switch ( V_23 -> V_271 ) {
case V_272 :
V_5 -> V_270 =
V_23 -> V_274 ;
break;
case V_286 :
V_5 -> V_285 =
( T_4 ) V_23 -> V_274 ;
break;
case V_477 :
V_5 -> V_377 =
( T_4 ) V_23 -> V_274 ;
break;
default:
break;
}
V_23 -> V_274 = 0 ;
V_23 -> V_271 = 0 ;
V_23 -> V_273 = NULL ;
}
#endif
if ( V_32 && F_23 ( V_32 ) )
F_147 ( & V_32 -> V_478 ) ;
if ( V_23 -> V_159 ) {
if ( V_23 -> V_159 == V_479 &&
( V_23 -> V_43 & V_480 ) )
V_23 -> V_159 = V_481 ;
else if ( V_23 -> V_159 >= V_482 )
V_23 -> V_159 = V_483 ;
if ( V_23 -> V_159 == V_484 &&
! V_23 -> V_125 -> V_425 &&
( V_23 -> V_125 -> V_423 & V_442 ) &&
! ( V_39 -> V_466 & V_467 ) )
V_455 = 0 ;
else
V_455 = V_127 | V_467 ;
F_50 ( V_39 , V_399 , V_455 ,
L_76
L_77
L_78
L_73 ,
V_33 -> V_4 [ 0 ] ,
V_33 -> V_16 ? V_33 -> V_16 -> V_460 : 0xffff ,
V_33 -> V_16 ? V_33 -> V_16 -> V_58 : 0xffff ,
V_23 -> V_159 , V_23 -> V_43 ,
V_39 -> V_485 ,
( V_32 ) ? V_32 -> V_263 : 0 ,
V_2 -> V_146 == V_486 ?
V_23 -> V_132 . V_180 : 0xffff ,
V_402 -> V_116 . V_487 ,
V_23 -> V_132 . V_116 . V_488 ) ;
switch ( V_23 -> V_159 ) {
case V_484 :
F_143 ( V_39 , V_23 , V_402 ) ;
break;
case V_489 :
case V_490 :
V_33 -> V_43 = F_126 ( V_491 , 0 ) ;
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
break;
V_62 -> V_63 . V_492 . V_66 =
V_446 ;
V_62 -> V_63 . V_492 . V_68 =
( V_23 -> V_159 == V_489 ) ?
V_493 : V_494 ;
if ( V_32 && F_23 ( V_32 ) ) {
memcpy ( & V_62 -> V_63 . V_492 . V_70 ,
& V_32 -> V_71 ,
sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_492 . V_73 ,
& V_32 -> V_74 ,
sizeof( struct V_72 ) ) ;
}
V_62 -> V_39 = V_39 ;
V_62 -> V_77 . V_78 =
V_79 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
F_24 ( & V_62 -> V_77 . V_81 ,
& V_2 -> V_82 ) ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_25 ( V_2 ) ;
break;
case V_479 :
case V_495 :
if ( V_23 -> V_43 == V_496 ||
V_23 -> V_43 ==
V_497 ||
V_23 -> V_43 == V_498 ||
V_23 -> V_43 ==
V_499 ) {
V_33 -> V_43 = F_126 ( V_500 , 0 ) ;
break;
}
if ( V_23 -> V_43 == V_501 ||
V_23 -> V_43 == V_502 ||
V_23 -> V_43 == V_503 ||
V_23 -> V_43 == V_504 ) {
V_33 -> V_43 = F_126 ( V_505 , 0 ) ;
break;
}
if ( ( V_23 -> V_43 == V_506 ||
V_23 -> V_43 == V_507 ) &&
V_402 -> V_116 . V_150 . V_405 . V_407 ) {
if ( F_103 ( V_33 ) != V_259 ) {
F_127 ( V_2 , V_23 ,
V_402 ) ;
break;
} else {
F_50 ( V_39 , V_399 ,
V_11 ,
L_79
L_80 ) ;
}
}
if ( ( V_23 -> V_159 == V_495 )
&& ( V_2 -> V_146 == V_486 )
&& ( V_32 && F_23 ( V_32 ) ) ) {
F_68 ( V_2 , V_32 ,
V_23 -> V_132 . V_184 ,
0 , 0 ) ;
}
default:
V_33 -> V_43 = F_126 ( V_411 , 0 ) ;
break;
}
if ( ! V_32 || ! F_23 ( V_32 )
|| ( V_32 -> V_508 != V_509 ) )
V_33 -> V_43 = F_126 ( V_491 ,
V_427 ) ;
} else
V_33 -> V_43 = F_126 ( V_453 , 0 ) ;
if ( V_33 -> V_43 || V_23 -> V_125 -> V_432 ) {
T_1 * V_451 = ( T_1 * ) V_33 -> V_393 ;
F_50 ( V_39 , V_126 , V_127 ,
L_81
L_82 ,
V_33 -> V_16 -> V_460 , V_33 -> V_16 -> V_58 , V_33 ,
V_33 -> V_43 , * V_451 , * ( V_451 + 3 ) , V_33 -> V_510 ,
F_145 ( V_33 ) ) ;
}
F_17 ( V_2 , V_23 ) ;
V_43 = V_33 -> V_43 ;
if ( V_39 -> V_511 &&
F_148 ( V_44 , V_23 -> V_45 +
F_149 ( V_39 -> V_511 ) ) ) {
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_32 && F_23 ( V_32 ) ) {
if ( V_32 -> V_512 >
F_38 ( & V_32 -> V_478 ) &&
( F_38 ( & V_32 -> V_478 ) >
V_513 ) &&
( ( V_33 -> V_4 [ 0 ] == V_433 ) ||
( V_33 -> V_4 [ 0 ] == V_434 ) ) )
V_32 -> V_512 =
F_38 ( & V_32 -> V_478 ) ;
V_32 -> V_514 = V_44 ;
}
F_20 ( V_37 -> V_46 , V_35 ) ;
} else if ( V_32 && F_23 ( V_32 ) ) {
if ( ( V_32 -> V_512 < V_39 -> V_515 ) &&
F_148 ( V_44 , V_32 -> V_514 +
F_149 ( V_516 ) ) ) {
F_19 ( V_37 -> V_46 , V_35 ) ;
V_471 = V_32 -> V_512 * V_517
/ 100 ;
V_471 = V_471 ? V_471 : 1 ;
V_32 -> V_512 += V_471 ;
if ( V_32 -> V_512 > V_39 -> V_515 )
V_32 -> V_512 = V_39 -> V_515 ;
V_32 -> V_514 = V_44 ;
F_20 ( V_37 -> V_46 , V_35 ) ;
}
}
F_142 ( V_2 , V_23 ) ;
V_89 = V_33 -> V_16 -> V_89 ;
V_472 = V_33 -> V_16 -> V_460 ;
V_33 -> V_518 ( V_33 ) ;
if ( V_2 -> V_519 & V_520 ) {
F_19 ( & V_2 -> V_80 , V_35 ) ;
V_23 -> V_34 = NULL ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_23 -> V_521 )
F_150 ( V_23 -> V_521 ) ;
F_20 ( V_37 -> V_46 , V_35 ) ;
F_91 ( V_2 , V_23 ) ;
return;
}
if ( ! V_43 )
F_35 ( V_39 , V_89 ) ;
if ( V_43 == V_426 && V_32 &&
F_23 ( V_32 ) ) {
F_41 (tmp_sdev, shost) {
if ( V_470 -> V_460 != V_472 )
continue;
V_471 = F_151 ( V_470 ,
V_470 -> V_89 - 1 ) ;
if ( V_471 <= 0 )
continue;
F_50 ( V_39 , V_399 , V_127 ,
L_83
L_84 , V_471 ) ;
F_21 ( V_2 , V_39 ,
V_32 ,
V_470 -> V_58 ,
V_471 + 1 , V_471 ) ;
}
}
F_19 ( & V_2 -> V_80 , V_35 ) ;
V_23 -> V_34 = NULL ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_23 -> V_521 )
F_150 ( V_23 -> V_521 ) ;
F_20 ( V_37 -> V_46 , V_35 ) ;
F_91 ( V_2 , V_23 ) ;
}
static void
F_152 ( V_218 * V_129 , struct V_124 * V_124 )
{
int V_42 , V_522 ;
for ( V_42 = 0 , V_522 = 0 ; V_42 < sizeof( struct V_124 ) ;
V_42 += sizeof( T_1 ) , V_522 ++ ) {
( ( T_1 * ) V_129 ) [ V_522 ] = F_100 ( ( ( T_1 * ) V_124 ) [ V_522 ] ) ;
}
}
static void
F_153 ( struct V_38 * V_39 , struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
T_2 * V_232 = & V_23 -> V_132 . V_116 ;
struct V_172 * V_523 = & ( V_23 -> V_132 ) ;
int V_238 = V_3 -> V_239 ;
char V_524 [ 2 ] ;
V_218 * V_525 ;
bool V_526 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return;
V_23 -> V_125 -> V_432 = 0 ;
V_23 -> V_124 -> V_457 = 0 ;
F_154 ( V_23 -> V_34 -> V_16 -> V_58 ,
& V_23 -> V_124 -> V_527 ) ;
V_525 = & V_124 -> V_528 [ 0 ] ;
memcpy ( V_525 , V_3 -> V_4 , V_3 -> V_529 ) ;
if ( V_3 -> V_529 < V_530 ) {
V_525 += V_3 -> V_529 ;
memset ( V_525 , 0 , ( V_530 - V_3 -> V_529 ) ) ;
}
if ( F_155 ( V_3 , V_524 ) ) {
switch ( V_524 [ 0 ] ) {
case V_531 :
V_124 -> V_532 = V_533 ;
break;
case V_534 :
V_124 -> V_532 = V_535 ;
break;
default:
V_124 -> V_532 = V_536 ;
break;
}
} else
V_124 -> V_532 = V_536 ;
V_526 = ( V_2 -> V_146 == V_486 ) ;
if ( F_93 ( V_3 ) ) {
if ( V_238 == V_325 ) {
V_232 -> V_537 = V_538 ;
if ( V_526 )
V_232 -> V_539 = V_540 ;
else {
V_232 -> V_63 . V_247 . V_248 = 0 ;
V_232 -> V_539 = 0 ;
}
V_124 -> V_541 = V_542 ;
V_2 -> V_543 ++ ;
} else {
V_232 -> V_537 = V_544 ;
V_232 -> V_539 = V_540 ;
V_124 -> V_541 = V_545 ;
V_2 -> V_546 ++ ;
}
} else {
V_232 -> V_537 = V_547 ;
V_232 -> V_63 . V_247 . V_248 = 0 ;
V_232 -> V_539 = 0 ;
V_124 -> V_541 = 0 ;
V_2 -> V_548 ++ ;
}
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) )
F_152 ( V_232 -> V_150 . V_151 . V_152 , V_124 ) ;
V_523 -> V_116 . V_487 = V_32 -> V_549 ;
if ( V_526 )
V_523 -> V_116 . V_487 =
V_2 -> V_164 . V_550 [ V_32 -> V_549 ] ;
if ( V_32 -> V_551 & V_552 )
V_523 -> V_116 . V_553 = 1 ;
else
V_523 -> V_116 . V_553 = 0 ;
V_523 -> V_116 . V_157 = ( V_32 -> V_551 & 0x0f ) ;
V_523 -> V_161 = V_23 ;
V_523 -> V_554 = F_146 ;
V_523 -> V_116 . V_555 = V_23 -> V_556 ;
V_523 -> V_39 = V_39 ;
}
static int
F_156 ( struct V_38 * V_39 ,
struct V_22 * V_23 ,
unsigned int V_58 ,
V_218 V_557 )
{
struct V_172 * V_523 ;
T_2 * V_558 ;
struct V_124 * V_124 ;
struct V_29 * V_30 = V_23 -> V_30 ;
struct V_31 * V_57 = V_30 -> V_32 ;
if ( ! V_57 || ! F_23 ( V_57 ) ||
V_57 -> V_508 != V_509 )
return 0 ;
V_523 = & ( V_23 -> V_132 ) ;
V_523 -> V_39 = V_39 ;
V_558 = & V_523 -> V_116 ;
V_124 = V_23 -> V_124 ;
memset ( V_124 , 0 , sizeof( struct V_124 ) ) ;
F_154 ( V_58 , & V_124 -> V_527 ) ;
V_124 -> V_457 = V_557 ;
if ( V_39 -> V_2 -> V_146 == 3 &&
! ( V_39 -> V_2 -> V_147 & V_148 ) )
F_152 ( V_558 -> V_150 . V_151 . V_152 , V_124 ) ;
V_558 -> V_537 = V_547 ;
V_558 -> V_487 = V_57 -> V_549 ;
if ( V_39 -> V_2 -> V_146 == V_486 ) {
V_558 -> V_487 =
V_39 -> V_2 -> V_164 . V_550 [ V_57 -> V_549 ] ;
}
if ( V_57 -> V_551 & V_552 ) {
V_558 -> V_553 = 1 ;
}
V_558 -> V_157 = ( V_57 -> V_551 & 0x0f ) ;
if ( V_23 -> V_556 > 0xff ) {
V_558 -> V_555 = 0 ;
} else
V_558 -> V_555 = V_23 -> V_556 ;
if ( V_39 -> V_2 -> V_146 == V_486 )
F_13 ( V_39 -> V_2 , V_23 ) ;
return 1 ;
}
int
F_157 ( struct V_1 * V_2 , V_218 V_559 )
{
V_2 -> F_142 = F_142 ;
V_2 -> F_153 = F_153 ;
switch ( V_559 ) {
case V_560 :
V_2 -> F_85 = F_49 ;
V_2 -> F_139 = F_92 ;
V_2 -> F_140 = F_117 ;
V_2 -> F_91 = F_59 ;
V_2 -> F_90 = F_86 ;
break;
case V_561 :
V_2 -> F_85 = F_83 ;
V_2 -> F_139 = F_136 ;
V_2 -> F_140 = F_138 ;
V_2 -> F_91 = F_70 ;
V_2 -> F_90 = F_88 ;
break;
default:
F_3 ( V_2 , V_10 , V_562 ,
L_85 ,
V_559 ) ;
return - V_563 ;
break;
}
V_2 -> F_33 = F_33 ;
V_2 -> F_146 = F_146 ;
return 0 ;
}
static void
F_158 ( struct V_1 * V_2 ,
struct V_172 * V_564 ,
struct V_172 * V_565 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_564 -> V_161 ;
if ( V_23 )
F_91 ( V_2 , V_23 ) ;
return;
}
const char *
F_159 ( struct V_36 * V_20 )
{
struct V_38 * V_39 = (struct V_38 * ) V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
int V_383 , V_566 = 0 ;
static char V_567 [ 384 ] ;
memset ( V_567 , 0 , 384 ) ;
if ( V_2 && V_2 -> V_240 ) {
strncpy ( V_567 , V_2 -> V_568 , 256 ) ;
V_383 = strlen ( V_567 ) ;
snprintf ( V_567 + V_383 ,
384 - V_383 ,
L_86 ,
V_2 -> V_240 -> V_569 -> V_570 ,
V_2 -> V_240 -> V_571 ,
V_2 -> V_240 -> V_572 ) ;
V_383 = strlen ( V_567 ) ;
if ( V_2 -> V_573 [ 0 ] ) {
snprintf ( V_567 + V_383 ,
384 - V_383 ,
L_87 ,
V_2 -> V_573 ) ;
}
V_383 = strlen ( V_567 ) ;
if ( V_2 -> V_146 <= V_574 ) {
V_566 = F_160 ( V_2 ) ;
} else {
if ( V_2 -> V_164 . V_575 . V_576 )
V_566 =
V_2 -> V_164 . V_575 . V_576 ;
else
V_566 = V_2 -> V_164 . V_575 . V_577 ;
}
if ( V_566 != 0 )
snprintf ( V_567 + V_383 , 384 - V_383 ,
L_88 , V_566 ) ;
}
return V_567 ;
}
static T_7 void F_161 ( struct V_1 * V_2 )
{
unsigned long V_578 =
( V_44 + F_149 ( V_2 -> V_579 ) ) ;
if ( ! F_67 ( & V_2 -> V_177 . V_178 [ V_580 ] . V_581 ) )
F_162 ( & V_2 -> V_582 ,
V_578 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
}
void F_164 ( unsigned long V_525 )
{
struct V_1 * V_2 = (struct V_1 * ) V_525 ;
if ( V_2 -> V_519 & V_520 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_580 ] , V_583 ) ;
if ( V_2 -> V_519 & V_584 )
F_161 ( V_2 ) ;
}
}
static int
F_166 ( struct V_36 * V_37 , struct V_3 * V_4 )
{
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_57 ;
struct V_22 * V_23 ;
struct V_110 * V_111 = F_46 ( F_47 ( V_4 -> V_16 ) ) ;
int V_372 ;
V_372 = F_167 ( V_111 ) ;
if ( V_372 ) {
V_4 -> V_43 = V_372 ;
goto V_585;
}
V_57 = V_30 -> V_32 ;
if ( ( F_103 ( V_4 ) != V_259 ) &&
( ! ( V_2 -> V_147 & V_148 ) ) ) {
F_3 ( V_2 , V_10 , V_11 ,
L_89
L_90
L_91 ,
V_4 -> V_4 [ 0 ] , F_103 ( V_4 ) ,
V_586 [ F_103 ( V_4 ) ] ) ;
goto V_585;
}
if ( ! V_57 || ! F_23 ( V_57 ) )
goto V_587;
if ( F_38 ( & V_57 -> V_478 ) >= V_57 -> V_512 )
goto V_587;
V_23 = F_90 ( V_2 , V_57 ) ;
if ( V_23 == NULL ) {
F_33 ( V_2 ) ;
F_50 ( V_39 , V_126 , V_127 ,
L_92
L_93 ) ;
goto V_588;
}
V_23 -> V_34 = V_4 ;
V_23 -> V_30 = V_30 ;
V_23 -> V_556 = 0 ;
V_23 -> V_45 = V_44 ;
V_4 -> V_267 = ( unsigned char * ) V_23 ;
if ( F_103 ( V_4 ) != V_259 ) {
if ( V_39 -> V_2 -> V_589 ) {
F_50 ( V_39 ,
V_126 , V_590 ,
L_94
L_95 ,
V_586 [ F_103 ( V_4 ) ] ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_4 ) ,
F_129 ( V_4 -> V_412 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_372 = F_140 ( V_2 , V_23 ) ;
} else {
if ( V_39 -> V_2 -> V_589 ) {
F_50 ( V_39 ,
V_126 , V_590 ,
L_96
L_97 ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_4 ) ,
F_129 ( V_4 -> V_412 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_372 = F_139 ( V_2 , V_23 ) ;
}
if ( V_372 )
goto V_591;
F_153 ( V_39 , V_23 , V_57 ) ;
F_34 ( & V_57 -> V_478 ) ;
V_372 = F_168 ( V_2 , V_580 ,
& V_23 -> V_132 , V_592 ) ;
if ( V_372 ) {
F_147 ( & V_57 -> V_478 ) ;
goto V_591;
}
if ( V_2 -> V_519 & V_520 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_580 ] , V_583 ) ;
if ( V_2 -> V_519 & V_584 )
F_161 ( V_2 ) ;
}
return 0 ;
V_591:
F_142 ( V_2 , V_23 ) ;
F_91 ( V_2 , V_23 ) ;
V_588:
return V_593 ;
V_587:
return V_594 ;
V_585:
V_4 -> V_518 ( V_4 ) ;
return 0 ;
}
static int
F_169 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_172 * V_116 ;
struct V_172 * V_595 ;
struct V_22 * V_23 ;
T_2 * V_33 , * V_596 ;
int V_293 = V_597 , V_159 = 0 ;
unsigned long V_35 ;
F_170 ( V_521 ) ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_597 )
return V_159 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
if ( V_2 -> V_598 & V_599 ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_399 , V_127 ,
L_98
L_99 ) ;
return V_600 ;
}
V_23 = (struct V_22 * ) V_4 -> V_267 ;
if ( ! V_23 || ! V_23 -> V_34 ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_399 , V_127 ,
L_100
L_101 ,
V_597 , V_4 -> V_16 -> V_460 , V_4 -> V_16 -> V_58 ) ;
return V_597 ;
}
V_116 = & V_23 -> V_132 ;
if ( ! ( V_116 -> V_133 & V_601 ) ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_399 , V_127 ,
L_102
L_103 ) ;
return V_600 ;
}
if ( V_23 -> V_34 != V_4 ) {
F_50 ( V_39 , V_399 , V_127 ,
L_104
L_105 ) ;
goto V_602;
}
F_113 ( V_116 -> V_161 != V_23 ) ;
V_595 = F_172 ( V_2 ) ;
if ( V_595 == NULL ) {
V_293 = V_600 ;
goto V_602;
}
V_33 = & V_116 -> V_116 ;
V_596 = & V_595 -> V_116 ;
V_596 -> V_63 . V_603 . V_604 = V_605 ;
V_596 -> V_63 . V_603 . V_606 = V_33 -> V_487 ;
if ( V_2 -> V_146 == V_486 )
V_596 -> V_63 . V_603 . V_607 = V_116 -> V_180 ;
else
V_596 -> V_63 . V_603 . V_607 = V_33 -> V_488 ;
V_596 -> V_154 = 1 ;
V_596 -> V_157 = V_33 -> V_157 ;
V_595 -> V_608 = V_116 -> V_608 ;
V_595 -> V_133 |= V_609 ;
if ( F_173 ( V_2 ) )
V_596 -> V_537 = V_610 ;
else
V_596 -> V_537 = V_611 ;
V_595 -> V_554 = V_612 ;
V_595 -> V_39 = V_39 ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
if ( F_168 ( V_2 , V_580 , V_595 , 0 ) ==
V_613 ) {
F_174 ( V_2 , V_595 ) ;
V_293 = V_600 ;
goto V_308;
}
if ( V_2 -> V_519 & V_584 )
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_580 ] , V_583 ) ;
V_23 -> V_521 = & V_521 ;
F_175 ( V_521 ,
( V_23 -> V_34 != V_4 ) ,
F_149 ( 2 * V_39 -> V_614 * 1000 ) ) ;
V_23 -> V_521 = NULL ;
if ( V_23 -> V_34 == V_4 ) {
V_293 = V_600 ;
F_50 ( V_39 , V_10 , V_127 ,
L_106
L_107
L_108 ,
V_116 -> V_180 , V_293 ,
V_4 -> V_16 -> V_460 , V_4 -> V_16 -> V_58 ) ;
}
goto V_308;
V_602:
F_20 ( & V_2 -> V_80 , V_35 ) ;
V_308:
F_50 ( V_39 , V_399 , V_127 ,
L_109
L_110 , V_293 , V_4 -> V_16 -> V_460 ,
V_4 -> V_16 -> V_58 ) ;
return V_293 ;
}
static char *
F_176 ( V_218 V_557 )
{
switch ( V_557 ) {
case V_615 :
return L_111 ;
case V_616 :
return L_112 ;
case V_617 :
return L_113 ;
case V_618 :
return L_114 ;
case V_619 :
return L_115 ;
case V_620 :
return L_116 ;
case V_621 :
return L_117 ;
default:
return L_118 ;
}
}
static int
F_177 ( struct V_38 * V_39 , struct V_29 * V_30 ,
unsigned V_622 , unsigned int V_623 ,
V_218 V_557 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_22 * V_23 ;
struct V_172 * V_173 ;
struct V_172 * V_624 ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_293 ;
int V_159 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return V_600 ;
V_23 = F_90 ( V_2 , V_30 -> V_32 ) ;
if ( V_23 == NULL )
return V_600 ;
V_23 -> V_556 = 60 ;
V_23 -> V_30 = V_30 ;
V_159 = F_156 ( V_39 , V_23 , V_623 ,
V_557 ) ;
if ( ! V_159 ) {
F_91 ( V_2 , V_23 ) ;
return V_600 ;
}
V_173 = & V_23 -> V_132 ;
V_624 = F_178 ( V_2 ) ;
if ( V_624 == NULL ) {
F_91 ( V_2 , V_23 ) ;
return V_600 ;
}
F_50 ( V_39 , V_126 , V_127 ,
L_119
L_120 ,
F_176 ( V_557 ) , V_622 , V_623 ,
V_32 -> V_549 , V_32 -> V_625 , V_173 -> V_180 ,
V_173 -> V_133 ) ;
V_159 = F_179 ( V_2 , V_580 ,
V_173 , V_624 , V_23 -> V_556 ) ;
if ( V_159 != V_626 ) {
if ( V_159 == V_627 ) {
V_173 -> V_554 = F_158 ;
V_293 = V_628 ;
} else
V_293 = V_600 ;
V_23 -> V_159 = V_481 ;
F_50 ( V_39 , V_10 , V_127 ,
L_121
L_122 ,
F_176 ( V_557 ) ,
V_622 , V_623 , V_624 -> V_116 . V_475 ,
V_624 -> V_116 . V_63 . V_473 [ 4 ] ,
V_173 -> V_133 ) ;
} else if ( V_159 == V_629 )
V_293 = V_600 ;
else
V_293 = V_597 ;
F_174 ( V_2 , V_624 ) ;
if ( V_293 != V_628 )
F_91 ( V_2 , V_23 ) ;
return V_293 ;
}
static int
F_180 ( struct V_38 * V_39 , struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned long V_630 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_126 , V_127 ,
L_123 , V_30 ) ;
return V_600 ;
}
V_32 = V_30 -> V_32 ;
V_630 = F_149 ( 2 * V_39 -> V_614 * 1000 ) + V_44 ;
while ( F_148 ( V_630 , V_44 ) ) {
if ( ! V_32 || ! F_23 ( V_32 ) )
return V_600 ;
if ( V_32 -> V_508 == V_509 )
return V_597 ;
F_181 ( F_149 ( 500 ) ) ;
V_30 = V_4 -> V_16 -> V_40 ;
if ( ! V_30 )
return V_600 ;
V_32 = V_30 -> V_32 ;
}
if ( ! V_32 || ! F_23 ( V_32 ) ||
( V_32 -> V_508 != V_509 ) )
return V_600 ;
return V_597 ;
}
static int
F_182 ( struct V_38 * V_39 , T_4 V_622 ,
T_6 V_623 , T_8 V_631 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
unsigned long V_630 ;
int V_632 ;
V_632 = F_183 ( V_39 , V_622 , V_623 , V_631 ) ;
if ( V_632 )
F_184 ( V_39 , & V_2 -> V_177 . V_178 [ V_2 -> V_177 . V_633 ] ,
V_622 , V_623 , V_631 ) ;
V_630 = F_149 ( 2 * V_39 -> V_614 * 1000 ) + V_44 ;
while ( F_148 ( V_630 , V_44 ) && V_632 ) {
F_181 ( F_149 ( 20 ) ) ;
V_632 = F_183 ( V_39 , V_622 , V_623 , V_631 ) ;
}
if ( V_632 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_124 ,
( ( V_631 == V_634 ) ? L_125 :
( ( V_631 == V_635 ) ? L_126 :
( ( V_631 == V_636 ) ? L_127 : L_128 ) ) ) ,
V_632 ) ;
return V_600 ;
}
return V_597 ;
}
static int
F_185 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned V_622 = V_4 -> V_16 -> V_460 ;
unsigned int V_623 = V_4 -> V_16 -> V_58 ;
struct V_637 V_65 ;
int V_159 , V_293 = V_597 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_129 , V_30 ) ;
return V_600 ;
}
V_32 = V_30 -> V_32 ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_597 )
return V_159 ;
V_159 = F_180 ( V_39 , V_4 ) ;
if ( V_159 == V_600 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_130 , V_30 ) ;
return V_600 ;
}
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_638 ;
V_65 . V_58 = V_623 ;
memcpy ( V_65 . V_70 , & V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_32 -> V_74 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_639 ) ;
V_159 = F_177 ( V_39 , V_30 , V_622 , V_623 ,
V_618 ) ;
F_50 ( V_39 , V_10 , V_127 ,
L_131
L_132 , V_622 , V_623 , V_159 ) ;
V_293 = F_182 ( V_39 , V_622 , V_623 ,
V_634 ) ;
return V_293 ;
}
static int
F_188 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned V_622 = V_4 -> V_16 -> V_460 ;
unsigned int V_623 = V_4 -> V_16 -> V_58 ;
struct V_637 V_65 ;
int V_159 , V_293 = V_597 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_133 , V_30 ) ;
return V_600 ;
}
V_32 = V_30 -> V_32 ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_597 )
return V_159 ;
V_159 = F_180 ( V_39 , V_4 ) ;
if ( V_159 == V_600 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_134 , V_30 ) ;
return V_600 ;
}
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_640 ;
V_65 . V_58 = 0 ;
memcpy ( V_65 . V_70 , & V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_32 -> V_74 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_639 ) ;
V_159 = F_177 ( V_39 , V_30 , V_622 , V_623 ,
V_619 ) ;
F_50 ( V_39 , V_10 , V_127 ,
L_135
L_132 , V_622 , V_623 , V_159 ) ;
V_293 = F_182 ( V_39 , V_622 , V_623 ,
V_635 ) ;
return V_293 ;
}
static int
F_189 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_31 * V_57 = NULL ;
struct V_637 V_65 ;
int V_641 ;
int V_293 = V_597 , V_159 , V_42 ;
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_642 ;
V_65 . V_58 = 0 ;
memcpy ( V_65 . V_70 , & V_39 -> V_643 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_39 -> V_644 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_639 ) ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_597 )
return V_159 ;
for ( V_42 = 0 ; V_42 < V_645 ; V_42 ++ ) {
V_641 = 0 ;
F_80 ( V_37 -> V_46 ) ;
F_190 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_23 ( V_57 ) )
continue;
if ( V_39 -> V_2 -> V_646 &&
( V_57 -> V_551 & V_552 ) )
continue;
if ( V_57 -> V_508 == V_509 &&
V_57 -> V_647 == V_42 &&
V_57 -> V_111 ) {
V_641 = 1 ;
break;
}
}
F_82 ( V_37 -> V_46 ) ;
if ( ! V_641 )
continue;
V_159 = F_177 ( V_39 , V_57 -> V_111 -> V_648 ,
V_42 , 0 , V_619 ) ;
if ( V_159 != V_597 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_136 ,
V_42 ) ;
V_293 = V_600 ;
}
}
V_159 = F_182 ( V_39 , 0 , 0 , V_636 ) ;
if ( V_159 != V_597 )
V_293 = V_600 ;
F_50 ( V_39 , V_10 , V_127 ,
L_137 , V_293 ) ;
return V_293 ;
}
static int
F_191 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
int V_208 , V_293 = V_597 ;
F_50 ( V_39 , V_10 , V_127 ,
L_138 ) ;
F_192 ( V_2 , V_649 ) ;
F_193 ( V_2 ) ;
V_208 = F_194 ( V_2 ) ;
if ( V_208 )
V_293 = V_600 ;
V_208 = F_195 ( V_2 ) ;
if ( V_208 )
V_293 = V_600 ;
F_196 ( V_2 ) ;
if ( V_293 == V_600 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_139 ) ;
F_197 ( V_2 ) ;
}
return V_293 ;
}
static int
F_198 ( struct V_83 * V_84 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_110 * V_111 = F_46 ( F_47 ( V_84 ) ) ;
T_1 V_650 = 0 ;
T_1 V_112 = 0 ;
int V_651 = 0 ;
T_1 V_652 ;
if ( ! V_111 || F_167 ( V_111 ) )
return - V_653 ;
V_84 -> V_40 = V_111 -> V_648 ;
V_652 = F_199 ( & V_2 -> V_652 ) ;
V_650 = V_2 -> V_654 ;
V_112 = V_39 -> V_102 + 2 ;
if ( ( V_652 * ( V_39 -> V_102 + 2 ) ) < V_650 )
return 0 ;
if ( V_650 >= V_2 -> V_655 - V_656 ) {
F_50 ( V_39 , V_399 , V_127 ,
L_140
L_141 , V_650 ) ;
return 0 ;
} else if ( V_650 + V_112 >
V_2 -> V_655 - V_656 ) {
F_50 ( V_39 , V_399 , V_127 ,
L_142
L_143
L_144 ,
V_112 , V_2 -> V_655 ,
( V_2 -> V_655 - V_650 ) ) ;
V_112 = V_2 -> V_655 - V_650 ;
}
V_651 = F_85 ( V_39 , V_112 ) ;
if ( V_112 != V_651 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_145
L_146
L_147 ,
V_112 , V_651 ) ;
}
if ( V_651 > 0 )
V_2 -> V_654 += V_651 ;
return 0 ;
}
static int
F_200 ( struct V_83 * V_84 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
if ( V_84 -> V_91 )
F_31 ( V_84 , V_39 -> V_102 ) ;
else
F_32 ( V_84 , V_39 -> V_102 ) ;
if ( V_2 -> V_519 & V_520 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_580 ] , V_583 ) ;
if ( V_2 -> V_519 & V_584 )
F_161 ( V_2 ) ;
}
return 0 ;
}
static void
F_201 ( struct V_83 * V_84 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
F_147 ( & V_2 -> V_652 ) ;
V_84 -> V_40 = NULL ;
return;
}
