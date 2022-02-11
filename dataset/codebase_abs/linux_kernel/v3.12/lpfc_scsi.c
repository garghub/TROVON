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
F_61 ( & V_2 -> V_210 ) ;
F_75 ( & V_2 -> V_211 , & V_190 ) ;
F_81 ( & V_2 -> V_212 , & V_190 ) ;
F_63 ( & V_2 -> V_210 ) ;
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
if ( V_2 -> V_216 && ( ( ( unsigned long ) ( V_113 -> V_129 ) &
( unsigned long ) ( V_217 - 1 ) ) != 0 ) ) {
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
V_113 -> V_132 . V_180 = V_2 -> V_164 . V_218 [ V_215 ] ;
V_113 -> V_132 . V_133 |= V_134 ;
V_113 -> V_26 = V_113 -> V_129 ;
V_113 -> V_124 = ( V_113 -> V_129 + V_193 ) ;
V_113 -> V_125 = (struct V_125 * ) ( ( V_219 * ) V_113 -> V_124 +
sizeof( struct V_124 ) ) ;
V_25 = (struct V_24 * ) V_113 -> V_26 ;
V_119 = V_113 -> V_131 ;
V_117 = ( V_113 -> V_131 + V_193 ) ;
V_118 = V_117 + sizeof( struct V_124 ) ;
V_25 -> V_220 = F_16 ( F_56 ( V_117 ) ) ;
V_25 -> V_221 = F_16 ( F_57 ( V_117 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_222 = F_16 ( sizeof( struct V_124 ) ) ;
V_25 ++ ;
V_25 -> V_220 = F_16 ( F_56 ( V_118 ) ) ;
V_25 -> V_221 = F_16 ( F_57 ( V_118 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 1 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_222 = F_16 ( sizeof( struct V_125 ) ) ;
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
struct V_189 * V_223 = & V_2 -> V_211 ;
unsigned long V_163 = 0 ;
F_19 ( & V_2 -> V_209 , V_163 ) ;
F_78 ( V_223 , V_23 , struct V_22 ,
V_181 ) ;
if ( ! V_23 ) {
F_61 ( & V_2 -> V_210 ) ;
F_81 ( & V_2 -> V_212 ,
& V_2 -> V_211 ) ;
F_87 ( & V_2 -> V_212 ) ;
F_78 ( V_223 , V_23 ,
struct V_22 , V_181 ) ;
F_63 ( & V_2 -> V_210 ) ;
}
F_20 ( & V_2 -> V_209 , V_163 ) ;
return V_23 ;
}
static struct V_22 *
F_88 ( struct V_1 * V_2 , struct V_31 * V_57 )
{
struct V_22 * V_23 , * V_224 ;
unsigned long V_163 = 0 ;
int V_225 = 0 ;
F_19 ( & V_2 -> V_209 , V_163 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 ( V_2 , V_57 ,
V_23 -> V_132 . V_184 ) )
continue;
F_66 ( & V_23 -> V_181 ) ;
V_225 = 1 ;
break;
}
if ( ! V_225 ) {
F_61 ( & V_2 -> V_210 ) ;
F_81 ( & V_2 -> V_212 ,
& V_2 -> V_211 ) ;
F_87 ( & V_2 -> V_212 ) ;
F_63 ( & V_2 -> V_210 ) ;
F_62 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_89 (
V_2 , V_57 , V_23 -> V_132 . V_184 ) )
continue;
F_66 ( & V_23 -> V_181 ) ;
V_225 = 1 ;
break;
}
}
F_20 ( & V_2 -> V_209 , V_163 ) ;
if ( ! V_225 )
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
V_113 -> V_226 = 0 ;
V_113 -> V_227 = 0 ;
V_113 -> V_228 = 0 ;
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
V_113 -> V_226 = 0 ;
V_113 -> V_227 = 0 ;
V_113 -> V_228 = 0 ;
if ( V_113 -> V_182 ) {
F_19 ( & V_2 -> V_164 . V_165 ,
V_163 ) ;
V_113 -> V_34 = NULL ;
F_24 ( & V_113 -> V_181 ,
& V_2 -> V_164 . V_229 ) ;
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
struct V_7 * V_230 = NULL ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_114 * V_115 = V_23 -> V_26 ;
struct V_172 * V_173 = & V_23 -> V_132 ;
T_2 * V_231 = & V_23 -> V_132 . V_116 ;
struct V_114 * V_232 = V_231 -> V_150 . V_151 . V_233 ;
T_3 V_234 ;
T_1 V_235 = 0 ;
int V_236 , V_237 = V_3 -> V_238 ;
V_115 += 2 ;
if ( F_93 ( V_3 ) ) {
V_236 = F_94 ( & V_2 -> V_239 -> V_240 , F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_237 ) ;
if ( F_95 ( ! V_236 ) )
return 1 ;
V_23 -> V_226 = V_236 ;
if ( V_23 -> V_226 > V_2 -> V_241 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_9
L_10 ,
V_12 , V_2 -> V_241 ,
V_23 -> V_226 ) ;
V_23 -> V_226 = 0 ;
F_96 ( V_3 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_234 = F_98 ( V_230 ) ;
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) &&
! ( V_173 -> V_133 & V_242 ) &&
V_236 <= V_243 ) {
V_232 -> V_137 . V_138 . V_140 = V_141 ;
V_232 -> V_137 . V_138 . V_139 = F_99 ( V_230 ) ;
V_232 -> V_136 = F_57 ( V_234 ) ;
V_232 -> V_135 = F_56 ( V_234 ) ;
V_232 ++ ;
} else {
V_115 -> V_137 . V_138 . V_140 = V_141 ;
V_115 -> V_137 . V_138 . V_139 = F_99 ( V_230 ) ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_115 -> V_136 =
F_14 ( F_57 ( V_234 ) ) ;
V_115 -> V_135 =
F_14 ( F_56 ( V_234 ) ) ;
V_115 ++ ;
}
}
}
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) &&
! ( V_173 -> V_133 & V_242 ) ) {
if ( V_235 > V_243 ) {
V_234 = V_23 -> V_131 ;
V_232 -> V_137 . V_138 . V_140 = V_156 ;
V_232 -> V_137 . V_138 . V_139 = ( V_235 *
sizeof( struct V_114 ) ) ;
V_234 += ( sizeof( struct V_124 ) +
sizeof( struct V_125 ) +
( 2 * sizeof( struct V_114 ) ) ) ;
V_232 -> V_135 = F_56 ( V_234 ) ;
V_232 -> V_136 = F_57 ( V_234 ) ;
V_231 -> V_150 . V_151 . V_244 = 2 ;
} else {
V_231 -> V_150 . V_151 . V_244 = ( V_235 + 1 ) ;
}
} else {
V_231 -> V_63 . V_143 . V_144 . V_139 =
( ( V_235 + 2 ) * sizeof( struct V_114 ) ) ;
V_231 -> V_150 . V_151 . V_244 = ( V_235 + 1 ) ;
}
V_124 -> V_245 = F_100 ( F_101 ( V_3 ) ) ;
V_231 -> V_63 . V_246 . V_247 = F_101 ( V_3 ) ;
return 0 ;
}
static int
F_102 ( struct V_1 * V_2 , struct V_3 * V_15 ,
T_1 * V_248 , T_4 * V_249 , T_1 V_250 )
{
struct V_7 * V_251 ;
struct V_7 * V_8 ;
struct V_22 * V_23 = NULL ;
struct V_252 * V_5 = NULL ;
struct V_31 * V_57 ;
struct V_29 * V_30 ;
T_1 V_253 = F_103 ( V_15 ) ;
T_1 V_254 ;
T_1 V_255 ;
T_5 V_256 ;
int V_208 = 0 ;
int V_257 = 0 ;
if ( V_253 == V_258 )
return 0 ;
V_251 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
V_256 = F_104 ( V_15 ) ;
if ( V_2 -> V_259 != V_260 ) {
V_254 = F_8 ( V_15 ) ;
V_255 = ( F_101 ( V_15 ) + V_254 - 1 ) / V_254 ;
if ( ( V_2 -> V_259 < V_256 ) ||
( V_2 -> V_259 >= ( V_256 + V_255 ) ) )
return 0 ;
if ( V_251 ) {
V_257 = V_2 -> V_259 - V_256 ;
V_255 = F_99 ( V_251 ) /
sizeof( struct V_252 ) ;
if ( V_255 < V_257 )
V_257 = V_255 ;
}
}
V_30 = V_15 -> V_16 -> V_40 ;
if ( V_30 && V_30 -> V_32 ) {
V_57 = V_30 -> V_32 ;
if ( V_2 -> V_261 &&
( V_2 -> V_261 != V_57 -> V_262 ) )
return 0 ;
if ( V_2 -> V_263 . V_264 . V_265 [ 0 ] &&
( memcmp ( & V_57 -> V_71 , & V_2 -> V_263 ,
sizeof( struct V_72 ) ) != 0 ) )
return 0 ;
}
if ( V_251 ) {
V_5 = (struct V_252 * ) F_4 ( V_251 ) ;
V_5 += V_257 ;
V_23 = (struct V_22 * ) V_15 -> V_266 ;
}
if ( V_248 ) {
if ( V_2 -> V_267 ) {
switch ( V_253 ) {
case V_268 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_11
L_12 ,
( unsigned long ) V_256 , V_257 ,
F_105 ( V_5 -> V_269 ) ) ;
if ( V_23 ) {
V_23 -> V_270 =
V_271 ;
V_23 -> V_272 =
V_5 ;
V_23 -> V_273 =
V_5 -> V_269 ;
}
V_5 -> V_269 = F_100 ( 0xDEADBEEF ) ;
V_2 -> V_267 -- ;
if ( V_2 -> V_267 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_274 | V_275 ;
break;
}
case V_276 :
* V_248 = 0xDEADBEEF ;
V_2 -> V_267 -- ;
if ( V_2 -> V_267 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_274 | V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_13
L_14 , ( unsigned long ) V_256 ) ;
break;
case V_277 :
* V_248 = 0xDEADBEEF ;
V_2 -> V_267 -- ;
if ( V_2 -> V_267 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 ;
F_3 ( V_2 , V_10 , V_11 ,
L_15
L_14 , ( unsigned long ) V_256 ) ;
break;
}
}
if ( V_2 -> V_279 ) {
switch ( V_253 ) {
case V_280 :
case V_281 :
case V_282 :
* V_248 = 0xDEADBEEF ;
V_2 -> V_279 -- ;
if ( V_2 -> V_279 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 ;
F_3 ( V_2 , V_10 , V_11 ,
L_16
L_17 , ( unsigned long ) V_256 ) ;
break;
}
}
}
if ( V_249 ) {
if ( V_2 -> V_283 ) {
switch ( V_253 ) {
case V_268 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_18
L_19 ,
( unsigned long ) V_256 , V_257 ,
F_106 ( V_5 -> V_284 ) ) ;
if ( V_23 ) {
V_23 -> V_270 =
V_285 ;
V_23 -> V_272 =
V_5 ;
V_23 -> V_273 =
V_5 -> V_284 ;
}
V_5 -> V_284 = F_107 ( 0xDEAD ) ;
V_2 -> V_283 -- ;
if ( V_2 -> V_283 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_274 | V_275 ;
break;
}
case V_276 :
* V_249 = 0xDEAD ;
V_2 -> V_283 -- ;
if ( V_2 -> V_283 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_274 | V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_20
L_14 , ( unsigned long ) V_256 ) ;
break;
case V_277 :
* V_249 = 0xDEAD ;
V_2 -> V_283 -- ;
if ( V_2 -> V_283 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 ;
F_3 ( V_2 , V_10 , V_11 ,
L_21
L_14 , ( unsigned long ) V_256 ) ;
break;
}
}
if ( V_2 -> V_286 ) {
switch ( V_253 ) {
case V_280 :
case V_281 :
case V_282 :
* V_249 = 0xDEAD ;
V_2 -> V_286 -- ;
if ( V_2 -> V_286 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 ;
F_3 ( V_2 , V_10 , V_11 ,
L_22
L_17 , ( unsigned long ) V_256 ) ;
break;
}
}
}
if ( V_250 ) {
if ( V_2 -> V_287 ) {
switch ( V_253 ) {
case V_268 :
V_208 = V_275 ;
case V_276 :
V_2 -> V_287 -- ;
if ( V_2 -> V_287 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 |= V_274 | V_288 ;
F_3 ( V_2 , V_10 , V_11 ,
L_23
L_14 , ( unsigned long ) V_256 ) ;
break;
case V_277 :
V_2 -> V_287 -- ;
if ( V_2 -> V_287 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 | V_288 ;
F_3 ( V_2 , V_10 , V_11 ,
L_24
L_14 , ( unsigned long ) V_256 ) ;
break;
}
}
if ( V_2 -> V_289 ) {
switch ( V_253 ) {
case V_280 :
case V_281 :
case V_282 :
V_2 -> V_289 -- ;
if ( V_2 -> V_289 == 0 ) {
V_2 -> V_261 = 0 ;
V_2 -> V_259 =
V_260 ;
memset ( & V_2 -> V_263 ,
0 , sizeof( struct V_72 ) ) ;
}
V_208 = V_278 | V_288 ;
F_3 ( V_2 , V_10 , V_11 ,
L_25
L_17 , ( unsigned long ) V_256 ) ;
}
}
}
return V_208 ;
}
static int
F_108 ( struct V_1 * V_2 , struct V_3 * V_15 ,
V_219 * V_290 , V_219 * V_291 )
{
V_219 V_292 = 0 ;
if ( F_10 ( V_15 ) ) {
switch ( F_103 ( V_15 ) ) {
case V_280 :
case V_277 :
* V_291 = V_293 ;
* V_290 = V_294 ;
break;
case V_281 :
case V_276 :
* V_291 = V_295 ;
* V_290 = V_296 ;
break;
case V_282 :
case V_268 :
* V_291 = V_297 ;
* V_290 = V_298 ;
break;
case V_258 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_26 ,
F_103 ( V_15 ) ) ;
V_292 = 1 ;
break;
}
} else {
switch ( F_103 ( V_15 ) ) {
case V_281 :
case V_276 :
* V_291 = V_295 ;
* V_290 = V_296 ;
break;
case V_282 :
case V_268 :
* V_291 = V_299 ;
* V_290 = V_299 ;
break;
case V_280 :
case V_277 :
* V_291 = V_296 ;
* V_290 = V_295 ;
break;
case V_258 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_27 ,
F_103 ( V_15 ) ) ;
V_292 = 1 ;
break;
}
}
return V_292 ;
}
static int
F_109 ( struct V_1 * V_2 , struct V_3 * V_15 ,
V_219 * V_290 , V_219 * V_291 )
{
V_219 V_292 = 0 ;
if ( F_10 ( V_15 ) ) {
switch ( F_103 ( V_15 ) ) {
case V_280 :
case V_277 :
* V_291 = V_296 ;
* V_290 = V_295 ;
break;
case V_281 :
case V_276 :
* V_291 = V_294 ;
* V_290 = V_293 ;
break;
case V_282 :
case V_268 :
* V_291 = V_298 ;
* V_290 = V_297 ;
break;
case V_258 :
default:
break;
}
} else {
switch ( F_103 ( V_15 ) ) {
case V_281 :
case V_276 :
* V_291 = V_294 ;
* V_290 = V_293 ;
break;
case V_282 :
case V_268 :
* V_291 = V_300 ;
* V_290 = V_300 ;
break;
case V_280 :
case V_277 :
* V_291 = V_293 ;
* V_290 = V_294 ;
break;
case V_258 :
default:
break;
}
}
return V_292 ;
}
static int
F_110 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_114 * V_115 , int V_301 )
{
struct V_7 * V_8 = NULL ;
struct V_302 * V_303 = NULL ;
struct V_304 * V_305 = NULL ;
T_3 V_234 ;
int V_42 = 0 , V_235 = 0 , V_159 ;
int V_237 = V_15 -> V_238 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_306 = 1 ;
T_1 V_248 ;
unsigned V_254 ;
V_219 V_290 , V_291 ;
V_159 = F_108 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_159 )
goto V_307;
V_254 = F_8 ( V_15 ) ;
V_248 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_248 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_288 )
F_109 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_208 & V_275 )
V_306 = 0 ;
}
#endif
V_303 = (struct V_302 * ) V_115 ;
memset ( V_303 , 0 , sizeof( struct V_302 ) ) ;
F_15 ( V_308 , V_303 , V_309 ) ;
V_303 -> V_310 = F_16 ( V_303 -> V_310 ) ;
V_303 -> V_248 = F_16 ( V_248 ) ;
V_235 ++ ;
V_115 ++ ;
V_305 = (struct V_304 * ) V_115 ;
memset ( V_305 , 0 , sizeof( struct V_304 ) ) ;
F_15 ( V_311 , V_305 , V_312 ) ;
F_15 ( V_313 , V_305 , V_290 ) ;
F_15 ( V_314 , V_305 , V_291 ) ;
if ( V_237 == V_315 ) {
if ( F_9 ( V_15 , V_316 ) )
F_15 ( V_317 , V_305 , V_306 ) ;
else
F_15 ( V_317 , V_305 , 0 ) ;
if ( F_9 ( V_15 , V_318 ) )
F_15 ( V_319 , V_305 , V_306 ) ;
else
F_15 ( V_319 , V_305 , 0 ) ;
}
F_15 ( V_320 , V_305 , 1 ) ;
F_15 ( V_321 , V_305 , 0 ) ;
F_15 ( V_322 , V_305 , 0 ) ;
V_305 -> V_310 = F_16 ( V_305 -> V_310 ) ;
V_305 -> V_323 = F_16 ( V_305 -> V_323 ) ;
V_305 -> V_27 = F_16 ( V_305 -> V_27 ) ;
V_235 ++ ;
V_115 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_234 = F_98 ( V_8 ) ;
V_115 -> V_136 = F_14 ( F_57 ( V_234 ) ) ;
V_115 -> V_135 = F_14 ( F_56 ( V_234 ) ) ;
V_115 -> V_137 . V_138 . V_139 = F_99 ( V_8 ) ;
if ( V_237 == V_324 )
V_115 -> V_137 . V_138 . V_140 = V_141 ;
else
V_115 -> V_137 . V_138 . V_140 = V_325 ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_115 ++ ;
V_235 ++ ;
}
V_307:
return V_235 ;
}
static int
F_112 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_114 * V_115 , int V_326 , int V_327 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_251 = NULL ;
struct V_302 * V_303 = NULL ;
struct V_304 * V_305 = NULL ;
struct V_328 * V_329 = NULL ;
T_3 V_330 , V_331 ;
unsigned short V_332 = 0 , V_333 = 0 ;
unsigned int V_334 ;
unsigned int V_335 , V_336 = 0 , V_337 ;
unsigned int V_338 , V_339 ;
unsigned int V_340 , V_341 ;
int V_159 ;
int V_237 = V_15 -> V_238 ;
unsigned char V_342 = 0 , V_343 = 0 ;
unsigned V_254 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_306 = 1 ;
T_1 V_248 ;
V_219 V_290 , V_291 ;
int V_235 = 0 ;
V_251 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
if ( ! V_251 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_127 ,
L_28 ,
V_251 , V_8 ) ;
return 0 ;
}
V_159 = F_108 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_159 )
goto V_307;
V_254 = F_8 ( V_15 ) ;
V_248 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_248 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_288 )
F_109 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_208 & V_275 )
V_306 = 0 ;
}
#endif
V_334 = 0 ;
do {
if ( V_235 >= ( V_2 -> V_344 - 2 ) )
return V_235 + 3 ;
V_303 = (struct V_302 * ) V_115 ;
memset ( V_303 , 0 , sizeof( struct V_302 ) ) ;
F_15 ( V_308 , V_303 , V_309 ) ;
V_303 -> V_310 = F_16 ( V_303 -> V_310 ) ;
V_303 -> V_248 = F_16 ( V_248 ) ;
V_235 ++ ;
V_115 ++ ;
V_305 = (struct V_304 * ) V_115 ;
memset ( V_305 , 0 , sizeof( struct V_304 ) ) ;
F_15 ( V_311 , V_305 , V_312 ) ;
F_15 ( V_313 , V_305 , V_290 ) ;
F_15 ( V_314 , V_305 , V_291 ) ;
if ( F_9 ( V_15 , V_316 ) )
F_15 ( V_317 , V_305 , V_306 ) ;
else
F_15 ( V_317 , V_305 , 0 ) ;
if ( F_9 ( V_15 , V_318 ) )
F_15 ( V_319 , V_305 , V_306 ) ;
else
F_15 ( V_319 , V_305 , 0 ) ;
F_15 ( V_320 , V_305 , 1 ) ;
F_15 ( V_321 , V_305 , 0 ) ;
F_15 ( V_322 , V_305 , 0 ) ;
V_305 -> V_310 = F_16 ( V_305 -> V_310 ) ;
V_305 -> V_323 = F_16 ( V_305 -> V_323 ) ;
V_305 -> V_27 = F_16 ( V_305 -> V_27 ) ;
V_235 ++ ;
V_115 ++ ;
V_331 = F_98 ( V_251 ) + V_336 ;
V_335 = F_99 ( V_251 ) - V_336 ;
F_113 ( V_335 % 8 ) ;
V_329 = (struct V_328 * ) V_115 ;
memset ( V_329 , 0 , sizeof( struct V_328 ) ) ;
F_15 ( V_345 , V_329 , V_346 ) ;
V_329 -> V_135 = F_14 ( F_56 ( V_331 ) ) ;
V_329 -> V_136 = F_14 ( F_57 ( V_331 ) ) ;
V_338 = V_335 / 8 ;
V_339 = V_338 * V_254 ;
if ( ( V_329 -> V_136 & 0xfff ) + V_335 > 0x1000 ) {
V_337 = 0x1000 - ( V_329 -> V_136 & 0xfff ) ;
V_336 += V_337 ;
V_338 = V_337 / 8 ;
V_339 = V_338 * V_254 ;
} else {
V_336 = 0 ;
V_333 ++ ;
}
V_235 ++ ;
V_342 = 0 ;
V_341 = 0 ;
while ( ! V_342 ) {
if ( V_235 >= V_2 -> V_344 )
return V_235 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_29 ,
V_12 ) ;
return 0 ;
}
V_115 ++ ;
V_330 = F_98 ( V_8 ) + V_334 ;
V_115 -> V_136 = F_14 ( F_57 ( V_330 ) ) ;
V_115 -> V_135 = F_14 ( F_56 ( V_330 ) ) ;
V_340 = F_99 ( V_8 ) - V_334 ;
if ( ( V_341 + V_340 ) <= V_339 ) {
V_115 -> V_137 . V_138 . V_139 = V_340 ;
V_334 = 0 ;
if ( ( V_341 + V_340 ) == V_339 )
V_342 = 1 ;
} else {
V_115 -> V_137 . V_138 . V_139 = V_339 - V_341 ;
V_334 += V_115 -> V_137 . V_138 . V_139 ;
}
V_341 += V_115 -> V_137 . V_138 . V_139 ;
if ( V_237 == V_324 )
V_115 -> V_137 . V_138 . V_140 = V_141 ;
else
V_115 -> V_137 . V_138 . V_140 = V_325 ;
V_115 -> V_137 . V_142 = F_14 ( V_115 -> V_137 . V_142 ) ;
V_235 ++ ;
V_332 ++ ;
if ( V_334 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_336 ) {
V_248 += V_338 ;
V_115 ++ ;
continue;
}
if ( V_333 == V_327 ) {
V_343 = 1 ;
} else if ( V_333 < V_327 ) {
V_251 = F_5 ( V_251 ) ;
V_115 ++ ;
V_248 += V_338 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_30 , V_12 ) ;
}
} while ( ! V_343 );
V_307:
return V_235 ;
}
static int
F_114 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_24 * V_25 , int V_301 )
{
struct V_7 * V_8 = NULL ;
struct V_347 * V_348 = NULL ;
T_3 V_234 ;
int V_42 = 0 , V_349 = 0 , V_159 ;
T_1 V_248 ;
unsigned V_254 ;
V_219 V_290 , V_291 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_306 = 1 ;
T_1 V_350 ;
T_1 V_351 = 0 ;
V_159 = F_108 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_159 )
goto V_307;
V_254 = F_8 ( V_15 ) ;
V_248 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_248 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_288 )
F_109 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_208 & V_275 )
V_306 = 0 ;
}
#endif
V_348 = (struct V_347 * ) V_25 ;
memset ( V_348 , 0 , sizeof( struct V_347 ) ) ;
F_15 ( V_352 , V_25 , V_353 ) ;
V_348 -> V_269 = F_16 ( V_248 ) ;
V_348 -> V_354 = V_348 -> V_269 ;
if ( V_15 -> V_238 == V_315 ) {
if ( F_9 ( V_15 , V_316 ) )
F_15 ( V_355 , V_348 , V_306 ) ;
else
F_15 ( V_355 , V_348 , 0 ) ;
if ( F_9 ( V_15 , V_318 ) )
F_15 ( V_356 , V_348 , V_306 ) ;
else
F_15 ( V_356 , V_348 , 0 ) ;
}
F_15 ( V_357 , V_348 , V_290 ) ;
F_15 ( V_358 , V_348 , V_291 ) ;
F_15 ( V_359 , V_348 , 1 ) ;
F_15 ( V_360 , V_348 , 0 ) ;
V_348 -> V_27 = F_16 ( V_348 -> V_27 ) ;
V_348 -> V_361 = F_16 ( V_348 -> V_361 ) ;
V_349 ++ ;
V_25 ++ ;
F_97 (sc, sgde, datasegcnt, i) {
V_234 = F_98 ( V_8 ) ;
V_350 = F_99 ( V_8 ) ;
V_25 -> V_221 = F_16 ( F_57 ( V_234 ) ) ;
V_25 -> V_220 = F_16 ( F_56 ( V_234 ) ) ;
if ( ( V_42 + 1 ) == V_301 )
F_15 ( V_28 , V_25 , 1 ) ;
else
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_362 , V_25 , V_351 ) ;
F_15 ( V_352 , V_25 , V_363 ) ;
V_25 -> V_222 = F_16 ( V_350 ) ;
V_351 += V_350 ;
V_25 ++ ;
V_349 ++ ;
}
V_307:
return V_349 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_3 * V_15 ,
struct V_24 * V_25 , int V_326 , int V_327 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_251 = NULL ;
struct V_347 * V_348 = NULL ;
T_3 V_330 , V_331 ;
unsigned short V_332 = 0 , V_333 = 0 ;
unsigned int V_334 ;
unsigned int V_335 , V_336 = 0 , V_337 ;
unsigned int V_338 , V_339 ;
unsigned int V_340 , V_341 ;
int V_159 ;
unsigned char V_342 = 0 , V_343 = 0 ;
unsigned V_254 ;
T_1 V_248 ;
V_219 V_290 , V_291 ;
T_1 V_350 ;
#ifdef F_111
T_1 V_208 ;
#endif
T_1 V_306 = 1 ;
T_1 V_351 = 0 ;
int V_349 = 0 ;
V_251 = F_7 ( V_15 ) ;
V_8 = F_2 ( V_15 ) ;
if ( ! V_251 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_127 ,
L_31 ,
V_251 , V_8 ) ;
return 0 ;
}
V_159 = F_108 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_159 )
goto V_307;
V_254 = F_8 ( V_15 ) ;
V_248 = ( T_1 ) F_104 ( V_15 ) ;
#ifdef F_111
V_208 = F_102 ( V_2 , V_15 , & V_248 , NULL , 1 ) ;
if ( V_208 ) {
if ( V_208 & V_288 )
F_109 ( V_2 , V_15 , & V_290 , & V_291 ) ;
if ( V_208 & V_275 )
V_306 = 0 ;
}
#endif
V_334 = 0 ;
do {
if ( V_349 >= ( V_2 -> V_344 - 2 ) )
return V_349 + 3 ;
V_348 = (struct V_347 * ) V_25 ;
memset ( V_348 , 0 , sizeof( struct V_347 ) ) ;
F_15 ( V_352 , V_25 , V_353 ) ;
V_348 -> V_269 = F_16 ( V_248 ) ;
V_348 -> V_354 = V_348 -> V_269 ;
if ( F_9 ( V_15 , V_316 ) ) {
F_15 ( V_355 , V_348 , V_306 ) ;
} else {
F_15 ( V_355 , V_348 , 0 ) ;
if ( V_290 == V_299 ) {
V_290 = V_364 ;
V_291 = V_364 ;
}
}
if ( F_9 ( V_15 , V_318 ) )
F_15 ( V_356 , V_348 , V_306 ) ;
else
F_15 ( V_356 , V_348 , 0 ) ;
F_15 ( V_357 , V_348 , V_290 ) ;
F_15 ( V_358 , V_348 , V_291 ) ;
F_15 ( V_359 , V_348 , 1 ) ;
F_15 ( V_360 , V_348 , 0 ) ;
V_348 -> V_27 = F_16 ( V_348 -> V_27 ) ;
V_348 -> V_361 = F_16 ( V_348 -> V_361 ) ;
V_349 ++ ;
V_25 ++ ;
V_331 = F_98 ( V_251 ) + V_336 ;
V_335 = F_99 ( V_251 ) - V_336 ;
F_113 ( V_335 % 8 ) ;
V_25 -> V_27 = 0 ;
F_15 ( V_352 , V_25 , V_365 ) ;
V_25 -> V_220 = F_14 ( F_56 ( V_331 ) ) ;
V_25 -> V_221 = F_14 ( F_57 ( V_331 ) ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_338 = V_335 / 8 ;
V_339 = V_338 * V_254 ;
if ( ( V_25 -> V_221 & 0xfff ) + V_335 > 0x1000 ) {
V_337 = 0x1000 - ( V_25 -> V_221 & 0xfff ) ;
V_336 += V_337 ;
V_338 = V_337 / 8 ;
V_339 = V_338 * V_254 ;
} else {
V_336 = 0 ;
V_333 ++ ;
}
V_349 ++ ;
V_342 = 0 ;
V_341 = 0 ;
while ( ! V_342 ) {
if ( V_349 >= V_2 -> V_344 )
return V_349 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_32 ,
V_12 ) ;
return 0 ;
}
V_25 ++ ;
V_330 = F_98 ( V_8 ) + V_334 ;
V_340 = F_99 ( V_8 ) - V_334 ;
if ( ( V_341 + V_340 ) <= V_339 ) {
V_350 = V_340 ;
V_334 = 0 ;
if ( ( V_341 + V_340 ) == V_339 )
V_342 = 1 ;
} else {
V_350 = V_339 - V_341 ;
V_334 += V_350 ;
}
V_341 += V_350 ;
V_25 -> V_221 = F_16 ( F_57 ( V_330 ) ) ;
V_25 -> V_220 = F_16 ( F_56 ( V_330 ) ) ;
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_362 , V_25 , V_351 ) ;
F_15 ( V_352 , V_25 , V_363 ) ;
V_25 -> V_222 = F_16 ( V_350 ) ;
V_351 += V_350 ;
V_349 ++ ;
V_332 ++ ;
if ( V_334 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_336 ) {
V_248 += V_338 ;
V_25 ++ ;
continue;
}
if ( V_333 == V_327 ) {
F_15 ( V_28 , V_25 , 1 ) ;
V_343 = 1 ;
} else if ( V_333 < V_327 ) {
V_251 = F_5 ( V_251 ) ;
V_25 ++ ;
V_248 += V_338 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_33 , V_12 ) ;
}
} while ( ! V_343 );
V_307:
return V_349 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_3 * V_15 )
{
int V_292 = V_366 ;
unsigned char V_253 = F_103 ( V_15 ) ;
switch ( V_253 ) {
case V_281 :
case V_276 :
V_292 = V_19 ;
break;
case V_280 :
case V_277 :
case V_282 :
case V_268 :
V_292 = V_367 ;
break;
default:
if ( V_2 )
F_3 ( V_2 , V_10 , V_127 ,
L_34 ,
V_253 ) ;
break;
}
return V_292 ;
}
static int
F_116 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_15 = V_23 -> V_34 ;
int V_368 ;
V_368 = F_101 ( V_15 ) ;
if ( V_15 -> V_238 == V_315 ) {
if ( F_103 ( V_15 ) == V_280 )
return V_368 ;
} else {
if ( F_103 ( V_15 ) == V_277 )
return V_368 ;
}
V_368 += ( V_368 / F_8 ( V_15 ) ) * 8 ;
return V_368 ;
}
static int
F_117 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_114 * V_115 = V_23 -> V_26 ;
T_2 * V_231 = & V_23 -> V_132 . V_116 ;
T_1 V_235 = 0 ;
int V_301 , V_369 , V_237 = V_3 -> V_238 ;
int V_370 = 0 ;
int V_368 ;
V_115 += 2 ;
if ( F_93 ( V_3 ) ) {
V_301 = F_94 ( & V_2 -> V_239 -> V_240 ,
F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_237 ) ;
if ( F_95 ( ! V_301 ) )
return 1 ;
V_23 -> V_226 = V_301 ;
if ( V_23 -> V_226 > V_2 -> V_241 )
goto V_371;
V_370 = F_11 ( V_2 , V_3 ) ;
switch ( V_370 ) {
case V_19 :
if ( ( V_23 -> V_226 + 2 ) > V_2 -> V_344 )
goto V_371;
V_235 = F_110 ( V_2 , V_3 , V_115 ,
V_301 ) ;
if ( V_235 < 2 )
goto V_371;
break;
case V_367 :
V_369 = F_94 ( & V_2 -> V_239 -> V_240 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_237 ) ;
if ( F_95 ( ! V_369 ) ) {
F_96 ( V_3 ) ;
return 1 ;
}
V_23 -> V_228 = V_369 ;
if ( ( V_23 -> V_228 * 4 ) >
( V_2 -> V_344 - 2 ) )
goto V_371;
V_235 = F_112 ( V_2 , V_3 , V_115 ,
V_301 , V_369 ) ;
if ( ( V_235 < 3 ) ||
( V_235 > V_2 -> V_344 ) )
goto V_371;
break;
case V_366 :
default:
F_96 ( V_3 ) ;
V_23 -> V_226 = 0 ;
F_3 ( V_2 , V_10 , V_127 ,
L_35 ,
V_370 ) ;
return 1 ;
}
}
V_231 -> V_63 . V_143 . V_144 . V_139 = ( 2 * sizeof( struct V_114 ) ) ;
V_231 -> V_63 . V_143 . V_144 . V_139 += ( V_235 * sizeof( struct V_114 ) ) ;
V_231 -> V_153 = 1 ;
V_231 -> V_154 = 1 ;
V_368 = F_116 ( V_2 , V_23 ) ;
V_124 -> V_245 = F_105 ( V_368 ) ;
V_231 -> V_63 . V_246 . V_247 = V_368 ;
return 0 ;
V_371:
if ( V_23 -> V_226 )
F_96 ( V_3 ) ;
if ( V_23 -> V_228 )
F_119 ( & V_2 -> V_239 -> V_240 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_238 ) ;
F_3 ( V_2 , V_10 , V_127 ,
L_36
L_37 ,
V_23 -> V_226 , V_23 -> V_228 ,
V_2 -> V_344 , V_2 -> V_241 ,
V_370 , V_235 ) ;
V_23 -> V_226 = 0 ;
V_23 -> V_228 = 0 ;
return 1 ;
}
T_4
F_120 ( V_219 * V_129 , int V_372 )
{
T_4 V_373 = 0 ;
T_4 V_374 ;
V_373 = F_121 ( V_129 , V_372 ) ;
V_374 = F_107 ( V_373 ) ;
return V_374 ;
}
T_4
F_122 ( V_219 * V_129 , int V_372 )
{
T_4 V_292 ;
V_292 = F_123 ( V_129 , V_372 ) ;
return V_292 ;
}
void
F_124 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_7 * V_251 ;
struct V_7 * V_8 ;
struct V_3 * V_33 = V_23 -> V_34 ;
struct V_252 * V_5 = NULL ;
V_219 * V_375 = NULL ;
T_4 V_376 , V_377 ;
T_4 V_378 , V_284 ;
T_1 V_379 , V_269 ;
int V_380 , V_369 ;
int V_381 , V_382 , V_383 ;
int V_384 , V_385 , V_386 ;
T_4 V_387 ;
unsigned V_254 ;
V_381 = V_388 ;
V_387 = 0 ;
V_376 = 0 ;
V_380 = F_103 ( V_33 ) ;
if ( ( V_380 == V_281 ) ||
( V_380 == V_276 ) ||
( V_380 == V_258 ) )
goto V_307;
V_384 = 1 ;
V_385 = 0 ;
V_386 = 0 ;
V_251 = F_7 ( V_33 ) ;
V_369 = V_23 -> V_228 ;
if ( V_251 && V_369 ) {
V_8 = F_2 ( V_33 ) ;
V_254 = F_8 ( V_33 ) ;
V_375 = ( V_219 * ) F_4 ( V_8 ) ;
V_383 = V_8 -> V_13 ;
if ( ( V_383 & ( V_254 - 1 ) ) == 0 )
V_386 = 1 ;
V_377 = F_12 ( V_33 -> V_16 -> V_20 ) ;
V_5 = (struct V_252 * ) F_4 ( V_251 ) ;
V_379 = ( T_1 ) F_104 ( V_33 ) ;
V_378 = V_5 -> V_284 ;
V_382 = V_251 -> V_13 ;
while ( V_5 && V_369 ) {
while ( V_382 ) {
if ( ( V_5 -> V_269 == 0xffffffff ) ||
( V_5 -> V_284 == 0xffff ) ) {
V_379 ++ ;
goto V_389;
}
if ( V_386 ) {
V_376 = V_5 -> V_376 ;
if ( F_10 ( V_33 ) )
V_387 = F_122 ( V_375 ,
V_254 ) ;
else
V_387 = F_120 ( V_375 ,
V_254 ) ;
if ( ( V_376 != V_387 ) ) {
V_381 = V_388 ;
goto V_307;
}
}
V_269 = F_105 ( V_5 -> V_269 ) ;
if ( V_384 && ( V_269 != V_379 ) ) {
V_381 = V_390 ;
goto V_307;
}
V_379 ++ ;
V_284 = V_5 -> V_284 ;
if ( V_385 && ( V_284 != V_378 ) ) {
V_381 = V_391 ;
goto V_307;
}
V_389:
V_382 -= sizeof( struct V_252 ) ;
if ( V_382 < 0 )
V_382 = 0 ;
V_5 ++ ;
V_375 += V_254 ;
V_383 -= V_254 ;
if ( V_386 && ( V_383 == 0 ) ) {
V_386 = 0 ;
V_8 = F_5 ( V_8 ) ;
if ( ! V_8 )
goto V_307;
V_375 = ( V_219 * ) F_4 ( V_8 ) ;
V_383 = V_8 -> V_13 ;
if ( ( V_383 & ( V_254 - 1 ) ) == 0 )
V_386 = 1 ;
}
}
V_251 = F_5 ( V_251 ) ;
if ( V_251 ) {
V_5 = (struct V_252 * ) F_4 ( V_251 ) ;
V_382 = V_251 -> V_13 ;
} else {
V_5 = NULL ;
}
V_369 -- ;
}
}
V_307:
if ( V_381 == V_388 ) {
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x1 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_397 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_38 ,
( unsigned long ) F_104 ( V_33 ) ,
V_387 , V_376 ) ;
} else if ( V_381 == V_390 ) {
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x3 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_399 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_39 ,
( unsigned long ) F_104 ( V_33 ) ,
V_269 , V_379 ) ;
} else if ( V_381 == V_391 ) {
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x2 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_40 ,
( unsigned long ) F_104 ( V_33 ) ,
V_284 , V_378 ) ;
}
}
static int
F_127 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_172 * V_401 )
{
struct V_3 * V_33 = V_23 -> V_34 ;
struct V_402 * V_403 = & V_401 -> V_116 . V_150 . V_404 ;
int V_292 = 0 ;
T_1 V_405 = V_403 -> V_405 ;
T_1 V_406 = V_403 -> V_406 ;
T_6 V_407 = 0 ;
F_61 ( & V_408 ) ;
if ( ! V_409 ) {
F_3 ( V_2 , V_10 , V_11 , L_41
L_42 ,
( V_33 -> V_4 [ 7 ] << 8 | V_33 -> V_4 [ 8 ] ) ) ;
F_1 ( V_2 , V_33 ) ;
if ( F_11 ( V_2 , V_33 ) ==
V_367 ) {
F_3 ( V_2 , V_10 , V_11 , L_43
L_44 ,
( V_33 -> V_4 [ 7 ] << 8 | V_33 -> V_4 [ 8 ] ) ) ;
F_6 ( V_2 , V_33 ) ;
}
V_409 = 1 ;
}
F_63 ( & V_408 ) ;
if ( F_128 ( V_406 ) ) {
V_33 -> V_43 = F_126 ( V_410 , 0 ) ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_45
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
V_292 = ( - 1 ) ;
goto V_307;
}
if ( F_130 ( V_406 ) ) {
V_33 -> V_43 = F_126 ( V_410 , 0 ) ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_48
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
V_292 = ( - 1 ) ;
goto V_307;
}
if ( F_131 ( V_406 ) ) {
V_292 = 1 ;
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x1 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_397 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_49
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_132 ( V_406 ) ) {
V_292 = 1 ;
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x3 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_399 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_50
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_133 ( V_406 ) ) {
V_292 = 1 ;
F_125 ( 1 , V_33 -> V_392 , V_393 ,
0x10 , 0x2 ) ;
V_33 -> V_43 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_51
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_134 ( V_406 ) ) {
V_33 -> V_392 [ 7 ] = 0xc ;
V_33 -> V_392 [ 8 ] = 0 ;
V_33 -> V_392 [ 9 ] = 0xa ;
V_33 -> V_392 [ 10 ] = 0x80 ;
switch ( F_103 ( V_33 ) ) {
case V_280 :
case V_277 :
V_405 /= V_33 -> V_16 -> V_17 ;
break;
case V_281 :
case V_276 :
case V_282 :
case V_268 :
V_405 /= ( V_33 -> V_16 -> V_17 +
sizeof( struct V_252 ) ) ;
break;
}
V_407 = F_104 ( V_33 ) ;
V_407 += V_405 ;
F_135 ( V_407 , & V_33 -> V_392 [ 12 ] ) ;
}
if ( ! V_292 ) {
F_3 ( V_2 , V_398 , V_127 | V_11 ,
L_52
L_46
L_47 , V_33 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_33 ) ,
F_129 ( V_33 -> V_411 ) , V_406 , V_405 ) ;
F_124 ( V_2 , V_23 ) ;
}
V_307:
return V_292 ;
}
static int
F_136 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_7 * V_230 = NULL ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
struct V_24 * V_412 ;
T_2 * V_231 = & V_23 -> V_132 . V_116 ;
T_3 V_234 ;
T_1 V_235 = 0 ;
T_1 V_350 ;
T_1 V_351 = 0 ;
int V_236 ;
struct V_114 * V_413 ;
if ( F_93 ( V_3 ) ) {
V_236 = F_137 ( V_3 ) ;
if ( F_95 ( ! V_236 ) )
return 1 ;
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 += 1 ;
V_412 = V_25 ;
V_23 -> V_226 = V_236 ;
if ( V_23 -> V_226 > V_2 -> V_241 ) {
F_3 ( V_2 , V_10 , V_11 , L_53
L_54
L_10 ,
V_12 , V_2 -> V_241 ,
V_23 -> V_226 ) ;
V_23 -> V_226 = 0 ;
F_96 ( V_3 ) ;
return 1 ;
}
F_97 (scsi_cmnd, sgel, nseg, num_bde) {
V_234 = F_98 ( V_230 ) ;
V_350 = F_99 ( V_230 ) ;
V_25 -> V_221 = F_16 ( F_57 ( V_234 ) ) ;
V_25 -> V_220 = F_16 ( F_56 ( V_234 ) ) ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
if ( ( V_235 + 1 ) == V_236 )
F_15 ( V_28 , V_25 , 1 ) ;
else
F_15 ( V_28 , V_25 , 0 ) ;
F_15 ( V_362 , V_25 , V_351 ) ;
F_15 ( V_352 , V_25 , V_363 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 -> V_222 = F_16 ( V_350 ) ;
V_351 += V_350 ;
V_25 ++ ;
}
if ( V_2 -> V_147 & V_414 ) {
V_413 = (struct V_114 * )
& ( V_231 -> V_150 . V_415 [ 5 ] ) ;
V_413 -> V_136 = V_412 -> V_221 ;
V_413 -> V_135 = V_412 -> V_220 ;
V_413 -> V_137 . V_138 . V_139 =
F_14 ( V_412 -> V_222 ) ;
V_413 -> V_137 . V_138 . V_140 = V_141 ;
V_413 -> V_137 . V_142 = F_16 ( V_413 -> V_137 . V_142 ) ;
}
} else {
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 1 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
}
V_124 -> V_245 = F_100 ( F_101 ( V_3 ) ) ;
V_231 -> V_63 . V_246 . V_247 = F_101 ( V_3 ) ;
return 0 ;
}
static int
F_138 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
struct V_24 * V_25 = (struct V_24 * ) ( V_23 -> V_26 ) ;
T_2 * V_231 = & V_23 -> V_132 . V_116 ;
T_1 V_349 = 0 ;
int V_301 , V_369 , V_237 = V_3 -> V_238 ;
int V_370 = 0 ;
int V_368 ;
if ( F_93 ( V_3 ) ) {
V_301 = F_94 ( & V_2 -> V_239 -> V_240 ,
F_2 ( V_3 ) ,
F_93 ( V_3 ) , V_237 ) ;
if ( F_95 ( ! V_301 ) )
return 1 ;
V_25 += 1 ;
V_25 -> V_27 = F_14 ( V_25 -> V_27 ) ;
F_15 ( V_28 , V_25 , 0 ) ;
V_25 -> V_27 = F_16 ( V_25 -> V_27 ) ;
V_25 += 1 ;
V_23 -> V_226 = V_301 ;
if ( V_23 -> V_226 > V_2 -> V_241 )
goto V_371;
V_370 = F_11 ( V_2 , V_3 ) ;
switch ( V_370 ) {
case V_19 :
if ( ( V_23 -> V_226 + 1 ) > V_2 -> V_344 )
goto V_371;
V_349 = F_114 ( V_2 , V_3 , V_25 ,
V_301 ) ;
if ( V_349 < 2 )
goto V_371;
break;
case V_367 :
V_369 = F_94 ( & V_2 -> V_239 -> V_240 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_237 ) ;
if ( F_95 ( ! V_369 ) ) {
F_96 ( V_3 ) ;
return 1 ;
}
V_23 -> V_228 = V_369 ;
if ( ( V_23 -> V_228 * 3 ) >
( V_2 -> V_344 - 2 ) )
goto V_371;
V_349 = F_115 ( V_2 , V_3 , V_25 ,
V_301 , V_369 ) ;
if ( ( V_349 < 3 ) ||
( V_349 > V_2 -> V_344 ) )
goto V_371;
break;
case V_366 :
default:
F_96 ( V_3 ) ;
V_23 -> V_226 = 0 ;
F_3 ( V_2 , V_10 , V_127 ,
L_55 ,
V_370 ) ;
return 1 ;
}
}
switch ( F_103 ( V_3 ) ) {
case V_277 :
case V_281 :
V_23 -> V_132 . V_133 |= V_416 ;
break;
case V_276 :
case V_280 :
V_23 -> V_132 . V_133 |= V_417 ;
break;
case V_268 :
case V_282 :
V_23 -> V_132 . V_133 |= V_418 ;
break;
}
V_368 = F_116 ( V_2 , V_23 ) ;
V_124 -> V_245 = F_105 ( V_368 ) ;
V_231 -> V_63 . V_246 . V_247 = V_368 ;
return 0 ;
V_371:
if ( V_23 -> V_226 )
F_96 ( V_3 ) ;
if ( V_23 -> V_228 )
F_119 ( & V_2 -> V_239 -> V_240 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_238 ) ;
F_3 ( V_2 , V_10 , V_127 ,
L_56
L_57 ,
V_23 -> V_226 , V_23 -> V_228 ,
V_2 -> V_344 , V_2 -> V_241 ,
V_370 , V_349 ) ;
V_23 -> V_226 = 0 ;
V_23 -> V_228 = 0 ;
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
struct V_22 * V_23 , struct V_172 * V_419 ) {
struct V_3 * V_4 = V_23 -> V_34 ;
struct V_125 * V_420 = V_23 -> V_125 ;
T_1 V_421 = V_420 -> V_422 ;
T_1 V_423 = V_420 -> V_424 ;
T_1 V_247 = V_419 -> V_116 . V_63 . V_246 . V_247 ;
struct V_61 * V_62 = NULL ;
struct V_31 * V_32 = V_23 -> V_30 -> V_32 ;
unsigned long V_35 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return;
if ( ( V_4 -> V_43 == V_425 ) ||
( V_4 -> V_43 == V_426 ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_427 . V_66 =
V_67 ;
V_62 -> V_63 . V_427 . V_68 =
( V_4 -> V_43 == V_425 ) ?
V_428 : V_429 ;
V_62 -> V_63 . V_427 . V_58 = V_4 -> V_16 -> V_58 ;
memcpy ( & V_62 -> V_63 . V_427 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_427 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
} else if ( ( V_421 & V_430 ) && V_420 -> V_431 &&
( ( V_4 -> V_4 [ 0 ] == V_432 ) || ( V_4 -> V_4 [ 0 ] == V_433 ) ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_434 . V_65 . V_66 =
V_67 ;
V_62 -> V_63 . V_434 . V_65 . V_68 =
V_435 ;
V_62 -> V_63 . V_434 . V_65 . V_58 =
V_4 -> V_16 -> V_58 ;
memcpy ( & V_62 -> V_63 . V_434 . V_65 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_434 . V_65 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
V_62 -> V_63 . V_434 . V_436 =
V_4 -> V_392 [ 2 ] & 0xf ;
V_62 -> V_63 . V_434 . V_437 = V_4 -> V_392 [ 12 ] ;
V_62 -> V_63 . V_434 . V_438 = V_4 -> V_392 [ 13 ] ;
} else if ( ( V_4 -> V_238 == V_315 ) &&
V_247 &&
( ( F_105 ( V_420 -> V_439 ) != V_247 ) ||
( ( V_423 == V_440 ) &&
! ( V_421 & ( V_441 | V_442 ) ) ) ) ) {
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
return;
V_62 -> V_63 . V_443 . V_444 . V_66 =
V_445 ;
V_62 -> V_63 . V_443 . V_444 . V_68 =
V_446 ;
memcpy ( & V_62 -> V_63 . V_443 . V_444 . V_70 ,
& V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_443 . V_444 . V_73 ,
& V_32 -> V_74 , sizeof( struct V_72 ) ) ;
V_62 -> V_63 . V_443 . V_58 = V_4 -> V_16 -> V_58 ;
V_62 -> V_63 . V_443 . V_447 = V_4 -> V_4 [ 0 ] ;
V_62 -> V_63 . V_443 . V_448 =
V_247 ;
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
if ( V_113 -> V_226 > 0 )
F_96 ( V_113 -> V_34 ) ;
if ( V_113 -> V_228 > 0 )
F_119 ( & V_2 -> V_239 -> V_240 , F_7 ( V_113 -> V_34 ) ,
F_118 ( V_113 -> V_34 ) ,
V_113 -> V_34 -> V_238 ) ;
}
static void
F_143 ( struct V_38 * V_39 , struct V_22 * V_23 ,
struct V_172 * V_419 )
{
struct V_3 * V_4 = V_23 -> V_34 ;
struct V_124 * V_449 = V_23 -> V_124 ;
struct V_125 * V_420 = V_23 -> V_125 ;
T_1 V_247 = V_419 -> V_116 . V_63 . V_246 . V_247 ;
T_1 V_421 = V_420 -> V_422 ;
T_1 V_423 = V_420 -> V_424 ;
T_1 * V_450 ;
T_1 V_451 = V_452 ;
T_1 V_453 = 0 ;
T_1 V_454 = V_127 | V_455 ;
if ( V_449 -> V_456 ) {
V_423 = 0 ;
goto V_307;
}
if ( V_421 & V_457 ) {
V_453 = F_105 ( V_420 -> V_458 ) ;
if ( V_453 != 0 && V_453 != 4 && V_453 != 8 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_58
L_59 ,
V_4 -> V_16 -> V_459 ,
V_4 -> V_16 -> V_58 , V_4 -> V_4 [ 0 ] ,
V_453 ) ;
V_451 = V_410 ;
goto V_307;
}
if ( V_420 -> V_460 != V_461 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_60
L_61
L_62 ,
V_4 -> V_16 -> V_459 ,
V_4 -> V_16 -> V_58 , V_4 -> V_4 [ 0 ] ,
V_420 -> V_460 ) ;
V_451 = V_410 ;
goto V_307;
}
}
if ( ( V_421 & V_430 ) && V_420 -> V_431 ) {
T_1 V_462 = F_105 ( V_420 -> V_431 ) ;
if ( V_462 > V_463 )
V_462 = V_463 ;
if ( V_421 & V_457 )
V_453 = F_105 ( V_420 -> V_458 ) ;
memcpy ( V_4 -> V_392 , & V_420 -> V_464 + V_453 , V_462 ) ;
}
V_450 = ( T_1 * ) V_4 -> V_392 ;
if ( ! V_423 && ( V_421 & V_441 ) ) {
if ( V_39 -> V_465 & V_127 )
V_454 = V_455 ;
if ( V_39 -> V_465 & V_466 )
V_454 = V_466 ;
}
F_50 ( V_39 , V_398 , V_454 ,
L_63
L_64 ,
V_4 -> V_4 [ 0 ] , V_423 ,
F_105 ( * V_450 ) , F_105 ( * ( V_450 + 3 ) ) , V_421 ,
F_105 ( V_420 -> V_439 ) ,
F_105 ( V_420 -> V_431 ) ,
F_105 ( V_420 -> V_458 ) ,
V_420 -> V_460 ) ;
F_144 ( V_4 , 0 ) ;
if ( V_421 & V_441 ) {
F_144 ( V_4 , F_105 ( V_420 -> V_439 ) ) ;
F_50 ( V_39 , V_126 , V_466 ,
L_65
L_66 ,
F_105 ( V_449 -> V_245 ) ,
F_145 ( V_4 ) , V_247 , V_4 -> V_4 [ 0 ] ,
V_4 -> V_467 ) ;
if ( ( V_4 -> V_238 == V_315 ) &&
V_247 &&
( F_145 ( V_4 ) != V_247 ) ) {
F_50 ( V_39 , V_398 ,
V_127 | V_455 ,
L_67
L_68 ,
F_105 ( V_449 -> V_245 ) ,
F_145 ( V_4 ) , V_247 ,
V_4 -> V_4 [ 0 ] ) ;
F_144 ( V_4 , F_101 ( V_4 ) ) ;
V_451 = V_410 ;
}
if ( ! ( V_421 & V_430 ) &&
( V_423 == V_440 ) &&
( F_101 ( V_4 ) - F_145 ( V_4 )
< V_4 -> V_467 ) ) {
F_50 ( V_39 , V_126 , V_127 ,
L_69
L_70
L_71 ,
V_4 -> V_4 [ 0 ] , F_101 ( V_4 ) ,
F_145 ( V_4 ) , V_4 -> V_467 ) ;
V_451 = V_410 ;
}
} else if ( V_421 & V_442 ) {
F_50 ( V_39 , V_398 , V_127 ,
L_72
L_73 , V_4 -> V_4 [ 0 ] ,
F_101 ( V_4 ) , F_145 ( V_4 ) ) ;
V_451 = V_410 ;
} else if ( V_247 && ( V_4 -> V_238 == V_315 ) ) {
F_50 ( V_39 , V_398 , V_127 | V_455 ,
L_74
L_75 ,
F_105 ( V_449 -> V_245 ) ,
F_105 ( V_420 -> V_439 ) ,
V_247 , V_4 -> V_4 [ 0 ] , V_423 ) ;
switch ( V_423 ) {
case V_440 :
case V_396 :
V_451 = V_410 ;
break;
}
F_144 ( V_4 , F_101 ( V_4 ) ) ;
}
V_307:
V_4 -> V_43 = F_126 ( V_451 , V_423 ) ;
F_141 ( V_39 -> V_2 , V_39 , V_23 , V_419 ) ;
}
static void
F_146 ( struct V_1 * V_2 , struct V_172 * V_468 ,
struct V_172 * V_401 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_468 -> V_161 ;
struct V_38 * V_39 = V_468 -> V_39 ;
struct V_29 * V_30 = V_23 -> V_30 ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_3 * V_33 ;
int V_43 ;
struct V_83 * V_469 ;
int V_470 ;
unsigned long V_35 ;
struct V_61 * V_62 ;
struct V_36 * V_37 ;
T_1 V_89 , V_471 ;
T_1 V_454 = V_127 ;
if ( ! ( V_23 -> V_34 ) )
return;
V_33 = V_23 -> V_34 ;
V_37 = V_33 -> V_16 -> V_20 ;
V_23 -> V_43 = ( V_401 -> V_116 . V_63 . V_472 [ 4 ] & V_473 ) ;
V_23 -> V_159 = V_401 -> V_116 . V_474 ;
V_23 -> V_182 = V_401 -> V_133 & V_475 ;
#ifdef F_111
if ( V_23 -> V_270 ) {
struct V_252 * V_5 = NULL ;
V_5 = (struct V_252 * ) V_23 -> V_272 ;
switch ( V_23 -> V_270 ) {
case V_271 :
V_5 -> V_269 =
V_23 -> V_273 ;
break;
case V_285 :
V_5 -> V_284 =
( T_4 ) V_23 -> V_273 ;
break;
case V_476 :
V_5 -> V_376 =
( T_4 ) V_23 -> V_273 ;
break;
default:
break;
}
V_23 -> V_273 = 0 ;
V_23 -> V_270 = 0 ;
V_23 -> V_272 = NULL ;
}
#endif
if ( V_32 && F_23 ( V_32 ) )
F_147 ( & V_32 -> V_477 ) ;
if ( V_23 -> V_159 ) {
if ( V_23 -> V_159 == V_478 &&
( V_23 -> V_43 & V_479 ) )
V_23 -> V_159 = V_480 ;
else if ( V_23 -> V_159 >= V_481 )
V_23 -> V_159 = V_482 ;
if ( V_23 -> V_159 == V_483 &&
! V_23 -> V_125 -> V_424 &&
( V_23 -> V_125 -> V_422 & V_441 ) &&
! ( V_39 -> V_465 & V_466 ) )
V_454 = 0 ;
else
V_454 = V_127 | V_466 ;
F_50 ( V_39 , V_398 , V_454 ,
L_76
L_77
L_78
L_73 ,
V_33 -> V_4 [ 0 ] ,
V_33 -> V_16 ? V_33 -> V_16 -> V_459 : 0xffff ,
V_33 -> V_16 ? V_33 -> V_16 -> V_58 : 0xffff ,
V_23 -> V_159 , V_23 -> V_43 ,
V_39 -> V_484 ,
( V_32 ) ? V_32 -> V_262 : 0 ,
V_2 -> V_146 == V_485 ?
V_23 -> V_132 . V_180 : 0xffff ,
V_401 -> V_116 . V_486 ,
V_23 -> V_132 . V_116 . V_487 ) ;
switch ( V_23 -> V_159 ) {
case V_483 :
F_143 ( V_39 , V_23 , V_401 ) ;
break;
case V_488 :
case V_489 :
V_33 -> V_43 = F_126 ( V_490 , 0 ) ;
V_62 = F_22 ( V_2 ) ;
if ( ! V_62 )
break;
V_62 -> V_63 . V_491 . V_66 =
V_445 ;
V_62 -> V_63 . V_491 . V_68 =
( V_23 -> V_159 == V_488 ) ?
V_492 : V_493 ;
if ( V_32 && F_23 ( V_32 ) ) {
memcpy ( & V_62 -> V_63 . V_491 . V_70 ,
& V_32 -> V_71 ,
sizeof( struct V_72 ) ) ;
memcpy ( & V_62 -> V_63 . V_491 . V_73 ,
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
case V_478 :
case V_494 :
if ( V_23 -> V_43 == V_495 ||
V_23 -> V_43 ==
V_496 ||
V_23 -> V_43 == V_497 ||
V_23 -> V_43 ==
V_498 ) {
V_33 -> V_43 = F_126 ( V_499 , 0 ) ;
break;
}
if ( V_23 -> V_43 == V_500 ||
V_23 -> V_43 == V_501 ||
V_23 -> V_43 == V_502 ||
V_23 -> V_43 == V_503 ) {
V_33 -> V_43 = F_126 ( V_504 , 0 ) ;
break;
}
if ( ( V_23 -> V_43 == V_505 ||
V_23 -> V_43 == V_506 ) &&
V_401 -> V_116 . V_150 . V_404 . V_406 ) {
if ( F_103 ( V_33 ) != V_258 ) {
F_127 ( V_2 , V_23 ,
V_401 ) ;
break;
} else {
F_50 ( V_39 , V_398 ,
V_11 ,
L_79
L_80 ) ;
}
}
if ( ( V_23 -> V_159 == V_494 )
&& ( V_2 -> V_146 == V_485 )
&& ( V_32 && F_23 ( V_32 ) ) ) {
F_68 ( V_2 , V_32 ,
V_23 -> V_132 . V_184 ,
0 , 0 ) ;
}
default:
V_33 -> V_43 = F_126 ( V_410 , 0 ) ;
break;
}
if ( ! V_32 || ! F_23 ( V_32 )
|| ( V_32 -> V_507 != V_508 ) )
V_33 -> V_43 = F_126 ( V_490 ,
V_426 ) ;
} else
V_33 -> V_43 = F_126 ( V_452 , 0 ) ;
if ( V_33 -> V_43 || V_23 -> V_125 -> V_431 ) {
T_1 * V_450 = ( T_1 * ) V_33 -> V_392 ;
F_50 ( V_39 , V_126 , V_127 ,
L_81
L_82 ,
V_33 -> V_16 -> V_459 , V_33 -> V_16 -> V_58 , V_33 ,
V_33 -> V_43 , * V_450 , * ( V_450 + 3 ) , V_33 -> V_509 ,
F_145 ( V_33 ) ) ;
}
F_17 ( V_2 , V_23 ) ;
V_43 = V_33 -> V_43 ;
if ( V_39 -> V_510 &&
F_148 ( V_44 , V_23 -> V_45 +
F_149 ( V_39 -> V_510 ) ) ) {
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_32 && F_23 ( V_32 ) ) {
if ( V_32 -> V_511 >
F_38 ( & V_32 -> V_477 ) &&
( F_38 ( & V_32 -> V_477 ) >
V_512 ) &&
( ( V_33 -> V_4 [ 0 ] == V_432 ) ||
( V_33 -> V_4 [ 0 ] == V_433 ) ) )
V_32 -> V_511 =
F_38 ( & V_32 -> V_477 ) ;
V_32 -> V_513 = V_44 ;
}
F_20 ( V_37 -> V_46 , V_35 ) ;
} else if ( V_32 && F_23 ( V_32 ) ) {
if ( ( V_32 -> V_511 < V_39 -> V_514 ) &&
F_148 ( V_44 , V_32 -> V_513 +
F_149 ( V_515 ) ) ) {
F_19 ( V_37 -> V_46 , V_35 ) ;
V_470 = V_32 -> V_511 * V_516
/ 100 ;
V_470 = V_470 ? V_470 : 1 ;
V_32 -> V_511 += V_470 ;
if ( V_32 -> V_511 > V_39 -> V_514 )
V_32 -> V_511 = V_39 -> V_514 ;
V_32 -> V_513 = V_44 ;
F_20 ( V_37 -> V_46 , V_35 ) ;
}
}
F_142 ( V_2 , V_23 ) ;
V_89 = V_33 -> V_16 -> V_89 ;
V_471 = V_33 -> V_16 -> V_459 ;
V_33 -> V_517 ( V_33 ) ;
if ( V_2 -> V_518 & V_519 ) {
F_19 ( & V_2 -> V_80 , V_35 ) ;
V_23 -> V_34 = NULL ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_23 -> V_520 )
F_150 ( V_23 -> V_520 ) ;
F_20 ( V_37 -> V_46 , V_35 ) ;
F_91 ( V_2 , V_23 ) ;
return;
}
if ( ! V_43 )
F_35 ( V_39 , V_89 ) ;
if ( V_43 == V_425 && V_32 &&
F_23 ( V_32 ) ) {
F_41 (tmp_sdev, shost) {
if ( V_469 -> V_459 != V_471 )
continue;
V_470 = F_151 ( V_469 ,
V_469 -> V_89 - 1 ) ;
if ( V_470 <= 0 )
continue;
F_50 ( V_39 , V_398 , V_127 ,
L_83
L_84 , V_470 ) ;
F_21 ( V_2 , V_39 ,
V_32 ,
V_469 -> V_58 ,
V_470 + 1 , V_470 ) ;
}
}
F_19 ( & V_2 -> V_80 , V_35 ) ;
V_23 -> V_34 = NULL ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_19 ( V_37 -> V_46 , V_35 ) ;
if ( V_23 -> V_520 )
F_150 ( V_23 -> V_520 ) ;
F_20 ( V_37 -> V_46 , V_35 ) ;
F_91 ( V_2 , V_23 ) ;
}
static void
F_152 ( V_219 * V_129 , struct V_124 * V_124 )
{
int V_42 , V_521 ;
for ( V_42 = 0 , V_521 = 0 ; V_42 < sizeof( struct V_124 ) ;
V_42 += sizeof( T_1 ) , V_521 ++ ) {
( ( T_1 * ) V_129 ) [ V_521 ] = F_100 ( ( ( T_1 * ) V_124 ) [ V_521 ] ) ;
}
}
static void
F_153 ( struct V_38 * V_39 , struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_3 * V_3 = V_23 -> V_34 ;
struct V_124 * V_124 = V_23 -> V_124 ;
T_2 * V_231 = & V_23 -> V_132 . V_116 ;
struct V_172 * V_522 = & ( V_23 -> V_132 ) ;
int V_237 = V_3 -> V_238 ;
char V_523 [ 2 ] ;
V_219 * V_524 ;
bool V_525 ;
T_1 V_368 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return;
V_23 -> V_125 -> V_431 = 0 ;
V_23 -> V_124 -> V_456 = 0 ;
F_154 ( V_23 -> V_34 -> V_16 -> V_58 ,
& V_23 -> V_124 -> V_526 ) ;
V_524 = & V_124 -> V_527 [ 0 ] ;
memcpy ( V_524 , V_3 -> V_4 , V_3 -> V_528 ) ;
if ( V_3 -> V_528 < V_529 ) {
V_524 += V_3 -> V_528 ;
memset ( V_524 , 0 , ( V_529 - V_3 -> V_528 ) ) ;
}
if ( F_155 ( V_3 , V_523 ) ) {
switch ( V_523 [ 0 ] ) {
case V_530 :
V_124 -> V_531 = V_532 ;
break;
case V_533 :
V_124 -> V_531 = V_534 ;
break;
default:
V_124 -> V_531 = V_535 ;
break;
}
} else
V_124 -> V_531 = V_535 ;
V_525 = ( V_2 -> V_146 == V_485 ) ;
if ( F_93 ( V_3 ) ) {
if ( V_237 == V_324 ) {
V_231 -> V_536 = V_537 ;
V_231 -> V_538 = V_539 ;
if ( V_39 -> V_540 &&
( V_32 -> V_541 & V_542 ) ) {
V_368 = F_101 ( V_3 ) ;
if ( V_368 < V_39 -> V_540 )
V_522 -> V_116 . V_63 . V_246 . V_543 = V_368 ;
else
V_522 -> V_116 . V_63 . V_246 . V_543 =
V_39 -> V_540 ;
}
V_124 -> V_544 = V_545 ;
V_2 -> V_546 ++ ;
} else {
V_231 -> V_536 = V_547 ;
V_231 -> V_538 = V_539 ;
V_124 -> V_544 = V_548 ;
V_2 -> V_549 ++ ;
}
} else {
V_231 -> V_536 = V_550 ;
V_231 -> V_63 . V_246 . V_247 = 0 ;
V_231 -> V_538 = 0 ;
V_124 -> V_544 = 0 ;
V_2 -> V_551 ++ ;
}
if ( V_2 -> V_146 == 3 &&
! ( V_2 -> V_147 & V_148 ) )
F_152 ( V_231 -> V_150 . V_151 . V_152 , V_124 ) ;
V_522 -> V_116 . V_486 = V_32 -> V_552 ;
if ( V_525 )
V_522 -> V_116 . V_486 =
V_2 -> V_164 . V_553 [ V_32 -> V_552 ] ;
if ( V_32 -> V_554 & V_555 )
V_522 -> V_116 . V_556 = 1 ;
else
V_522 -> V_116 . V_556 = 0 ;
V_522 -> V_116 . V_157 = ( V_32 -> V_554 & 0x0f ) ;
V_522 -> V_161 = V_23 ;
V_522 -> V_557 = F_146 ;
V_522 -> V_116 . V_558 = V_23 -> V_559 ;
V_522 -> V_39 = V_39 ;
}
static int
F_156 ( struct V_38 * V_39 ,
struct V_22 * V_23 ,
unsigned int V_58 ,
V_219 V_560 )
{
struct V_172 * V_522 ;
T_2 * V_561 ;
struct V_124 * V_124 ;
struct V_29 * V_30 = V_23 -> V_30 ;
struct V_31 * V_57 = V_30 -> V_32 ;
if ( ! V_57 || ! F_23 ( V_57 ) ||
V_57 -> V_507 != V_508 )
return 0 ;
V_522 = & ( V_23 -> V_132 ) ;
V_522 -> V_39 = V_39 ;
V_561 = & V_522 -> V_116 ;
V_124 = V_23 -> V_124 ;
memset ( V_124 , 0 , sizeof( struct V_124 ) ) ;
F_154 ( V_58 , & V_124 -> V_526 ) ;
V_124 -> V_456 = V_560 ;
if ( V_39 -> V_2 -> V_146 == 3 &&
! ( V_39 -> V_2 -> V_147 & V_148 ) )
F_152 ( V_561 -> V_150 . V_151 . V_152 , V_124 ) ;
V_561 -> V_536 = V_550 ;
V_561 -> V_486 = V_57 -> V_552 ;
if ( V_39 -> V_2 -> V_146 == V_485 ) {
V_561 -> V_486 =
V_39 -> V_2 -> V_164 . V_553 [ V_57 -> V_552 ] ;
}
if ( V_57 -> V_554 & V_555 ) {
V_561 -> V_556 = 1 ;
}
V_561 -> V_157 = ( V_57 -> V_554 & 0x0f ) ;
if ( V_23 -> V_559 > 0xff ) {
V_561 -> V_558 = 0 ;
} else
V_561 -> V_558 = V_23 -> V_559 ;
if ( V_39 -> V_2 -> V_146 == V_485 )
F_13 ( V_39 -> V_2 , V_23 ) ;
return 1 ;
}
int
F_157 ( struct V_1 * V_2 , V_219 V_562 )
{
V_2 -> F_142 = F_142 ;
V_2 -> F_153 = F_153 ;
switch ( V_562 ) {
case V_563 :
V_2 -> F_85 = F_49 ;
V_2 -> F_139 = F_92 ;
V_2 -> F_140 = F_117 ;
V_2 -> F_91 = F_59 ;
V_2 -> F_90 = F_86 ;
break;
case V_564 :
V_2 -> F_85 = F_83 ;
V_2 -> F_139 = F_136 ;
V_2 -> F_140 = F_138 ;
V_2 -> F_91 = F_70 ;
V_2 -> F_90 = F_88 ;
break;
default:
F_3 ( V_2 , V_10 , V_565 ,
L_85 ,
V_562 ) ;
return - V_566 ;
break;
}
V_2 -> F_33 = F_33 ;
V_2 -> F_146 = F_146 ;
return 0 ;
}
static void
F_158 ( struct V_1 * V_2 ,
struct V_172 * V_567 ,
struct V_172 * V_568 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_567 -> V_161 ;
if ( V_23 )
F_91 ( V_2 , V_23 ) ;
return;
}
const char *
F_159 ( struct V_36 * V_20 )
{
struct V_38 * V_39 = (struct V_38 * ) V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
int V_382 , V_569 = 0 ;
static char V_570 [ 384 ] ;
memset ( V_570 , 0 , 384 ) ;
if ( V_2 && V_2 -> V_239 ) {
strncpy ( V_570 , V_2 -> V_571 , 256 ) ;
V_382 = strlen ( V_570 ) ;
snprintf ( V_570 + V_382 ,
384 - V_382 ,
L_86 ,
V_2 -> V_239 -> V_572 -> V_573 ,
V_2 -> V_239 -> V_574 ,
V_2 -> V_239 -> V_575 ) ;
V_382 = strlen ( V_570 ) ;
if ( V_2 -> V_576 [ 0 ] ) {
snprintf ( V_570 + V_382 ,
384 - V_382 ,
L_87 ,
V_2 -> V_576 ) ;
}
V_382 = strlen ( V_570 ) ;
if ( V_2 -> V_146 <= V_577 ) {
V_569 = F_160 ( V_2 ) ;
} else {
if ( V_2 -> V_164 . V_578 . V_579 )
V_569 =
V_2 -> V_164 . V_578 . V_579 ;
else
V_569 = V_2 -> V_164 . V_578 . V_580 ;
}
if ( V_569 != 0 )
snprintf ( V_570 + V_382 , 384 - V_382 ,
L_88 , V_569 ) ;
}
return V_570 ;
}
static T_7 void F_161 ( struct V_1 * V_2 )
{
unsigned long V_581 =
( V_44 + F_149 ( V_2 -> V_582 ) ) ;
if ( ! F_67 ( & V_2 -> V_177 . V_178 [ V_583 ] . V_584 ) )
F_162 ( & V_2 -> V_585 ,
V_581 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
}
void F_164 ( unsigned long V_524 )
{
struct V_1 * V_2 = (struct V_1 * ) V_524 ;
if ( V_2 -> V_518 & V_519 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_583 ] , V_586 ) ;
if ( V_2 -> V_518 & V_587 )
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
int V_371 ;
V_371 = F_167 ( V_111 ) ;
if ( V_371 ) {
V_4 -> V_43 = V_371 ;
goto V_588;
}
V_57 = V_30 -> V_32 ;
if ( ( F_103 ( V_4 ) != V_258 ) &&
( ! ( V_2 -> V_147 & V_148 ) ) ) {
F_3 ( V_2 , V_10 , V_11 ,
L_89
L_90
L_91 ,
V_4 -> V_4 [ 0 ] , F_103 ( V_4 ) ,
V_589 [ F_103 ( V_4 ) ] ) ;
goto V_588;
}
if ( ! V_57 || ! F_23 ( V_57 ) )
goto V_590;
if ( F_38 ( & V_57 -> V_477 ) >= V_57 -> V_511 )
goto V_590;
V_23 = F_90 ( V_2 , V_57 ) ;
if ( V_23 == NULL ) {
F_33 ( V_2 ) ;
F_50 ( V_39 , V_126 , V_127 ,
L_92
L_93 ) ;
goto V_591;
}
V_23 -> V_34 = V_4 ;
V_23 -> V_30 = V_30 ;
V_23 -> V_559 = 0 ;
V_23 -> V_45 = V_44 ;
V_4 -> V_266 = ( unsigned char * ) V_23 ;
if ( F_103 ( V_4 ) != V_258 ) {
if ( V_39 -> V_2 -> V_216 ) {
F_50 ( V_39 ,
V_126 , V_592 ,
L_94
L_95 ,
V_589 [ F_103 ( V_4 ) ] ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_4 ) ,
F_129 ( V_4 -> V_411 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_371 = F_140 ( V_2 , V_23 ) ;
} else {
if ( V_39 -> V_2 -> V_216 ) {
F_50 ( V_39 ,
V_126 , V_592 ,
L_96
L_97 ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_104 ( V_4 ) ,
F_129 ( V_4 -> V_411 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_371 = F_139 ( V_2 , V_23 ) ;
}
if ( V_371 )
goto V_593;
F_153 ( V_39 , V_23 , V_57 ) ;
F_34 ( & V_57 -> V_477 ) ;
V_371 = F_168 ( V_2 , V_583 ,
& V_23 -> V_132 , V_594 ) ;
if ( V_371 ) {
F_147 ( & V_57 -> V_477 ) ;
goto V_593;
}
if ( V_2 -> V_518 & V_519 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_583 ] , V_586 ) ;
if ( V_2 -> V_518 & V_587 )
F_161 ( V_2 ) ;
}
return 0 ;
V_593:
F_142 ( V_2 , V_23 ) ;
F_91 ( V_2 , V_23 ) ;
V_591:
return V_595 ;
V_590:
return V_596 ;
V_588:
V_4 -> V_517 ( V_4 ) ;
return 0 ;
}
static int
F_169 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_172 * V_116 ;
struct V_172 * V_597 ;
struct V_22 * V_23 ;
T_2 * V_33 , * V_598 ;
int V_292 = V_599 , V_159 = 0 ;
unsigned long V_35 ;
F_170 ( V_520 ) ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_599 )
return V_159 ;
F_19 ( & V_2 -> V_80 , V_35 ) ;
if ( V_2 -> V_600 & V_601 ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_398 , V_127 ,
L_98
L_99 ) ;
return V_602 ;
}
V_23 = (struct V_22 * ) V_4 -> V_266 ;
if ( ! V_23 || ! V_23 -> V_34 ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_398 , V_127 ,
L_100
L_101 ,
V_599 , V_4 -> V_16 -> V_459 , V_4 -> V_16 -> V_58 ) ;
return V_599 ;
}
V_116 = & V_23 -> V_132 ;
if ( ! ( V_116 -> V_133 & V_603 ) ) {
F_20 ( & V_2 -> V_80 , V_35 ) ;
F_50 ( V_39 , V_398 , V_127 ,
L_102
L_103 ) ;
return V_602 ;
}
if ( V_23 -> V_34 != V_4 ) {
F_50 ( V_39 , V_398 , V_127 ,
L_104
L_105 ) ;
goto V_604;
}
F_113 ( V_116 -> V_161 != V_23 ) ;
V_597 = F_172 ( V_2 ) ;
if ( V_597 == NULL ) {
V_292 = V_602 ;
goto V_604;
}
V_116 -> V_133 |= V_605 ;
V_33 = & V_116 -> V_116 ;
V_598 = & V_597 -> V_116 ;
V_598 -> V_63 . V_606 . V_607 = V_608 ;
V_598 -> V_63 . V_606 . V_609 = V_33 -> V_486 ;
if ( V_2 -> V_146 == V_485 )
V_598 -> V_63 . V_606 . V_610 = V_116 -> V_180 ;
else
V_598 -> V_63 . V_606 . V_610 = V_33 -> V_487 ;
V_598 -> V_154 = 1 ;
V_598 -> V_157 = V_33 -> V_157 ;
V_597 -> V_611 = V_116 -> V_611 ;
V_597 -> V_133 |= V_612 ;
if ( F_173 ( V_2 ) )
V_598 -> V_536 = V_613 ;
else
V_598 -> V_536 = V_614 ;
V_597 -> V_557 = V_615 ;
V_597 -> V_39 = V_39 ;
F_20 ( & V_2 -> V_80 , V_35 ) ;
if ( F_168 ( V_2 , V_583 , V_597 , 0 ) ==
V_616 ) {
F_174 ( V_2 , V_597 ) ;
V_292 = V_602 ;
goto V_307;
}
if ( V_2 -> V_518 & V_587 )
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_583 ] , V_586 ) ;
V_23 -> V_520 = & V_520 ;
F_175 ( V_520 ,
( V_23 -> V_34 != V_4 ) ,
F_149 ( 2 * V_39 -> V_617 * 1000 ) ) ;
V_23 -> V_520 = NULL ;
if ( V_23 -> V_34 == V_4 ) {
V_292 = V_602 ;
F_50 ( V_39 , V_10 , V_127 ,
L_106
L_107
L_108 ,
V_116 -> V_180 , V_292 ,
V_4 -> V_16 -> V_459 , V_4 -> V_16 -> V_58 ) ;
}
goto V_307;
V_604:
F_20 ( & V_2 -> V_80 , V_35 ) ;
V_307:
F_50 ( V_39 , V_398 , V_127 ,
L_109
L_110 , V_292 , V_4 -> V_16 -> V_459 ,
V_4 -> V_16 -> V_58 ) ;
return V_292 ;
}
static char *
F_176 ( V_219 V_560 )
{
switch ( V_560 ) {
case V_618 :
return L_111 ;
case V_619 :
return L_112 ;
case V_620 :
return L_113 ;
case V_621 :
return L_114 ;
case V_622 :
return L_115 ;
case V_623 :
return L_116 ;
case V_624 :
return L_117 ;
default:
return L_118 ;
}
}
static int
F_177 ( struct V_38 * V_39 , struct V_29 * V_30 ,
unsigned V_625 , unsigned int V_626 ,
V_219 V_560 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_22 * V_23 ;
struct V_172 * V_173 ;
struct V_172 * V_627 ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_292 ;
int V_159 ;
if ( ! V_32 || ! F_23 ( V_32 ) )
return V_602 ;
V_23 = F_90 ( V_2 , V_30 -> V_32 ) ;
if ( V_23 == NULL )
return V_602 ;
V_23 -> V_559 = V_2 -> V_628 ;
V_23 -> V_30 = V_30 ;
V_159 = F_156 ( V_39 , V_23 , V_626 ,
V_560 ) ;
if ( ! V_159 ) {
F_91 ( V_2 , V_23 ) ;
return V_602 ;
}
V_173 = & V_23 -> V_132 ;
V_627 = F_178 ( V_2 ) ;
if ( V_627 == NULL ) {
F_91 ( V_2 , V_23 ) ;
return V_602 ;
}
V_173 -> V_557 = F_158 ;
F_50 ( V_39 , V_126 , V_127 ,
L_119
L_120 ,
F_176 ( V_560 ) , V_625 , V_626 ,
V_32 -> V_552 , V_32 -> V_541 , V_173 -> V_180 ,
V_173 -> V_133 ) ;
V_159 = F_179 ( V_2 , V_583 ,
V_173 , V_627 , V_23 -> V_559 ) ;
if ( V_159 != V_629 ) {
if ( V_159 == V_630 ) {
V_292 = V_631 ;
} else
V_292 = V_602 ;
V_23 -> V_159 = V_480 ;
F_50 ( V_39 , V_10 , V_127 ,
L_121
L_122 ,
F_176 ( V_560 ) ,
V_625 , V_626 , V_627 -> V_116 . V_474 ,
V_627 -> V_116 . V_63 . V_472 [ 4 ] ,
V_173 -> V_133 ) ;
} else if ( V_159 == V_632 )
V_292 = V_602 ;
else
V_292 = V_599 ;
F_174 ( V_2 , V_627 ) ;
if ( V_292 != V_631 )
F_91 ( V_2 , V_23 ) ;
return V_292 ;
}
static int
F_180 ( struct V_38 * V_39 , struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned long V_633 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_126 , V_127 ,
L_123 , V_30 ) ;
return V_602 ;
}
V_32 = V_30 -> V_32 ;
V_633 = F_149 ( 2 * V_39 -> V_617 * 1000 ) + V_44 ;
while ( F_148 ( V_633 , V_44 ) ) {
if ( ! V_32 || ! F_23 ( V_32 ) )
return V_602 ;
if ( V_32 -> V_507 == V_508 )
return V_599 ;
F_181 ( F_149 ( 500 ) ) ;
V_30 = V_4 -> V_16 -> V_40 ;
if ( ! V_30 )
return V_602 ;
V_32 = V_30 -> V_32 ;
}
if ( ! V_32 || ! F_23 ( V_32 ) ||
( V_32 -> V_507 != V_508 ) )
return V_602 ;
return V_599 ;
}
static int
F_182 ( struct V_38 * V_39 , T_4 V_625 ,
T_6 V_626 , T_8 V_634 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
unsigned long V_633 ;
int V_635 ;
V_635 = F_183 ( V_39 , V_625 , V_626 , V_634 ) ;
if ( V_635 )
F_184 ( V_39 , & V_2 -> V_177 . V_178 [ V_2 -> V_177 . V_636 ] ,
V_625 , V_626 , V_634 ) ;
V_633 = F_149 ( 2 * V_39 -> V_617 * 1000 ) + V_44 ;
while ( F_148 ( V_633 , V_44 ) && V_635 ) {
F_181 ( F_149 ( 20 ) ) ;
V_635 = F_183 ( V_39 , V_625 , V_626 , V_634 ) ;
}
if ( V_635 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_124 ,
( ( V_634 == V_637 ) ? L_125 :
( ( V_634 == V_638 ) ? L_126 :
( ( V_634 == V_639 ) ? L_127 : L_128 ) ) ) ,
V_635 ) ;
return V_602 ;
}
return V_599 ;
}
static int
F_185 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned V_625 = V_4 -> V_16 -> V_459 ;
unsigned int V_626 = V_4 -> V_16 -> V_58 ;
struct V_640 V_65 ;
int V_159 , V_292 = V_599 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_129 , V_30 ) ;
return V_602 ;
}
V_32 = V_30 -> V_32 ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_599 )
return V_159 ;
V_159 = F_180 ( V_39 , V_4 ) ;
if ( V_159 == V_602 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_130 , V_30 ) ;
return V_602 ;
}
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_641 ;
V_65 . V_58 = V_626 ;
memcpy ( V_65 . V_70 , & V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_32 -> V_74 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_642 ) ;
V_159 = F_177 ( V_39 , V_30 , V_625 , V_626 ,
V_621 ) ;
F_50 ( V_39 , V_10 , V_127 ,
L_131
L_132 , V_625 , V_626 , V_159 ) ;
V_292 = F_182 ( V_39 , V_625 , V_626 ,
V_637 ) ;
return V_292 ;
}
static int
F_188 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_29 * V_30 = V_4 -> V_16 -> V_40 ;
struct V_31 * V_32 ;
unsigned V_625 = V_4 -> V_16 -> V_459 ;
unsigned int V_626 = V_4 -> V_16 -> V_58 ;
struct V_640 V_65 ;
int V_159 , V_292 = V_599 ;
if ( ! V_30 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_133 , V_30 ) ;
return V_602 ;
}
V_32 = V_30 -> V_32 ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_599 )
return V_159 ;
V_159 = F_180 ( V_39 , V_4 ) ;
if ( V_159 == V_602 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_134 , V_30 ) ;
return V_602 ;
}
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_643 ;
V_65 . V_58 = 0 ;
memcpy ( V_65 . V_70 , & V_32 -> V_71 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_32 -> V_74 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_642 ) ;
V_159 = F_177 ( V_39 , V_30 , V_625 , V_626 ,
V_622 ) ;
F_50 ( V_39 , V_10 , V_127 ,
L_135
L_132 , V_625 , V_626 , V_159 ) ;
V_292 = F_182 ( V_39 , V_625 , V_626 ,
V_638 ) ;
return V_292 ;
}
static int
F_189 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_31 * V_57 = NULL ;
struct V_640 V_65 ;
int V_644 ;
int V_292 = V_599 , V_159 , V_42 ;
V_65 . V_66 = V_67 ;
V_65 . V_68 = V_645 ;
V_65 . V_58 = 0 ;
memcpy ( V_65 . V_70 , & V_39 -> V_646 , sizeof( struct V_72 ) ) ;
memcpy ( V_65 . V_73 , & V_39 -> V_647 , sizeof( struct V_72 ) ) ;
F_186 ( V_37 , F_187 () ,
sizeof( V_65 ) , ( char * ) & V_65 , V_642 ) ;
V_159 = F_171 ( V_4 ) ;
if ( V_159 != 0 && V_159 != V_599 )
return V_159 ;
for ( V_42 = 0 ; V_42 < V_648 ; V_42 ++ ) {
V_644 = 0 ;
F_80 ( V_37 -> V_46 ) ;
F_190 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_23 ( V_57 ) )
continue;
if ( V_39 -> V_2 -> V_649 &&
( V_57 -> V_554 & V_555 ) )
continue;
if ( V_57 -> V_507 == V_508 &&
V_57 -> V_650 == V_42 &&
V_57 -> V_111 ) {
V_644 = 1 ;
break;
}
}
F_82 ( V_37 -> V_46 ) ;
if ( ! V_644 )
continue;
V_159 = F_177 ( V_39 , V_57 -> V_111 -> V_651 ,
V_42 , 0 , V_622 ) ;
if ( V_159 != V_599 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_136 ,
V_42 ) ;
V_292 = V_602 ;
}
}
V_159 = F_182 ( V_39 , 0 , 0 , V_639 ) ;
if ( V_159 != V_599 )
V_292 = V_602 ;
F_50 ( V_39 , V_10 , V_127 ,
L_137 , V_292 ) ;
return V_292 ;
}
static int
F_191 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_16 -> V_20 ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
int V_208 , V_292 = V_599 ;
F_50 ( V_39 , V_10 , V_127 ,
L_138 ) ;
F_192 ( V_2 , V_652 ) ;
F_193 ( V_2 ) ;
V_208 = F_194 ( V_2 ) ;
if ( V_208 )
V_292 = V_602 ;
V_208 = F_195 ( V_2 ) ;
if ( V_208 )
V_292 = V_602 ;
F_196 ( V_2 ) ;
if ( V_292 == V_602 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_139 ) ;
F_197 ( V_2 ) ;
}
return V_292 ;
}
static int
F_198 ( struct V_83 * V_84 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_110 * V_111 = F_46 ( F_47 ( V_84 ) ) ;
T_1 V_653 = 0 ;
T_1 V_112 = 0 ;
int V_654 = 0 ;
T_1 V_655 ;
if ( ! V_111 || F_167 ( V_111 ) )
return - V_656 ;
V_84 -> V_40 = V_111 -> V_651 ;
V_655 = F_199 ( & V_2 -> V_655 ) ;
V_653 = V_2 -> V_657 ;
V_112 = V_39 -> V_102 + 2 ;
if ( ( V_655 * ( V_39 -> V_102 + 2 ) ) < V_653 )
return 0 ;
if ( V_653 >= V_2 -> V_658 - V_659 ) {
F_50 ( V_39 , V_398 , V_127 ,
L_140
L_141 , V_653 ) ;
return 0 ;
} else if ( V_653 + V_112 >
V_2 -> V_658 - V_659 ) {
F_50 ( V_39 , V_398 , V_127 ,
L_142
L_143
L_144 ,
V_112 , V_2 -> V_658 ,
( V_2 -> V_658 - V_653 ) ) ;
V_112 = V_2 -> V_658 - V_653 ;
}
V_654 = F_85 ( V_39 , V_112 ) ;
if ( V_112 != V_654 ) {
F_50 ( V_39 , V_10 , V_127 ,
L_145
L_146
L_147 ,
V_112 , V_654 ) ;
}
if ( V_654 > 0 )
V_2 -> V_657 += V_654 ;
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
if ( V_2 -> V_518 & V_519 ) {
F_165 ( V_2 ,
& V_2 -> V_177 . V_178 [ V_583 ] , V_586 ) ;
if ( V_2 -> V_518 & V_587 )
F_161 ( V_2 ) ;
}
return 0 ;
}
static void
F_201 ( struct V_83 * V_84 )
{
struct V_38 * V_39 = (struct V_38 * ) V_84 -> V_20 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
F_147 ( & V_2 -> V_655 ) ;
V_84 -> V_40 = NULL ;
return;
}
