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
static void
F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = (struct V_17 * ) V_16 -> V_19 ;
if ( V_18 ) {
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 1 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
}
}
static void
F_12 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_3 * V_26 = V_16 -> V_27 ;
unsigned long V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
unsigned long V_36 ;
int V_37 ;
if ( V_26 -> V_38 )
return;
V_36 = F_13 ( ( long ) V_39 - ( long ) V_16 -> V_40 ) ;
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( ! V_34 -> V_42 ||
V_34 -> V_43 ||
! V_25 ||
! V_25 -> V_44 ||
( V_2 -> V_45 == V_46 ) ) {
F_15 ( V_30 -> V_41 , V_28 ) ;
return;
}
if ( V_2 -> V_45 == V_47 ) {
V_37 = ( V_36 + V_2 -> V_48 - 1 - V_2 -> V_49 ) /
V_2 -> V_48 ;
if ( V_37 < 0 )
V_37 = 0 ;
else if ( V_37 >= V_50 )
V_37 = V_50 - 1 ;
} else {
for ( V_37 = 0 ; V_37 < V_50 - 1 ; V_37 ++ )
if ( V_36 <= ( V_2 -> V_49 +
( ( 1 << V_37 ) * V_2 -> V_48 ) ) )
break;
}
V_25 -> V_44 [ V_37 ] . V_51 ++ ;
F_15 ( V_30 -> V_41 , V_28 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_24 * V_52 ,
T_1 V_53 ,
T_1 V_54 ,
T_1 V_55 )
{
struct V_56 * V_57 ;
unsigned long V_28 ;
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_59 . V_60 . V_61 =
V_62 ;
V_57 -> V_58 . V_59 . V_60 . V_63 =
V_64 ;
V_57 -> V_58 . V_59 . V_60 . V_53 = V_53 ;
if ( V_52 && F_18 ( V_52 ) ) {
memcpy ( & V_57 -> V_58 . V_59 . V_60 . V_65 ,
& V_52 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_59 . V_60 . V_68 ,
& V_52 -> V_69 , sizeof( struct V_67 ) ) ;
}
V_57 -> V_58 . V_59 . V_70 = V_54 ;
V_57 -> V_58 . V_59 . V_71 = V_55 ;
V_57 -> V_34 = V_34 ;
V_57 -> V_72 . V_73 = V_74 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
F_19 ( & V_57 -> V_72 . V_76 , & V_2 -> V_77 ) ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_20 ( V_2 ) ;
return;
}
int
F_21 ( struct V_78 * V_79 , int V_80 , int V_81 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_22 * V_23 ;
unsigned long V_82 , V_83 ;
V_83 = V_79 -> V_84 ;
F_22 ( V_79 , F_23 ( V_79 ) , V_80 ) ;
V_82 = V_79 -> V_84 ;
V_23 = V_79 -> V_35 ;
if ( V_23 )
F_16 ( V_2 , V_34 ,
V_23 -> V_25 , V_79 -> V_53 ,
V_83 ,
V_82 ) ;
return V_79 -> V_84 ;
}
static int
F_24 ( struct V_78 * V_79 , int V_85 )
{
if ( V_79 -> V_86 ) {
F_25 ( V_79 , V_85 ) ;
if ( V_85 )
F_26 ( V_79 , V_79 -> V_84 ) ;
else
F_27 ( V_79 , V_79 -> V_84 ) ;
} else
V_85 = 0 ;
return V_85 ;
}
void
F_28 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
T_1 V_87 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
F_29 ( & V_2 -> V_88 ) ;
V_2 -> V_89 = V_39 ;
if ( ( V_2 -> V_90 + V_91 ) > V_39 ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
return;
}
V_2 -> V_90 = V_39 ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( & V_2 -> V_92 -> V_93 , V_28 ) ;
V_87 = V_2 -> V_92 -> V_94 & V_95 ;
if ( ! V_87 )
V_2 -> V_92 -> V_94 |= V_95 ;
F_15 ( & V_2 -> V_92 -> V_93 , V_28 ) ;
if ( ! V_87 )
F_20 ( V_2 ) ;
return;
}
static inline void
F_30 ( struct V_33 * V_34 ,
T_1 V_84 )
{
unsigned long V_28 ;
struct V_1 * V_2 = V_34 -> V_2 ;
T_1 V_87 ;
F_29 ( & V_2 -> V_96 ) ;
if ( V_34 -> V_97 <= V_84 )
return;
F_14 ( & V_2 -> V_75 , V_28 ) ;
if ( F_31 ( V_39 ,
V_2 -> V_98 + V_99 ) ||
F_31 ( V_39 ,
V_2 -> V_89 + V_99 ) ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
return;
}
V_2 -> V_98 = V_39 ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( & V_2 -> V_92 -> V_93 , V_28 ) ;
V_87 = V_2 -> V_92 -> V_94 & V_100 ;
if ( ! V_87 )
V_2 -> V_92 -> V_94 |= V_100 ;
F_15 ( & V_2 -> V_92 -> V_93 , V_28 ) ;
if ( ! V_87 )
F_20 ( V_2 ) ;
return;
}
void
F_32 ( struct V_1 * V_2 )
{
struct V_33 * * V_101 ;
struct V_29 * V_30 ;
struct V_78 * V_79 ;
unsigned long V_82 ;
unsigned long V_88 , V_96 ;
int V_37 ;
V_88 = F_33 ( & V_2 -> V_88 ) ;
V_96 = F_33 ( & V_2 -> V_96 ) ;
if ( V_88 == 0 )
return;
V_101 = F_34 ( V_2 ) ;
if ( V_101 != NULL )
for ( V_37 = 0 ; V_37 <= V_2 -> V_102 && V_101 [ V_37 ] != NULL ; V_37 ++ ) {
V_30 = F_35 ( V_101 [ V_37 ] ) ;
F_36 (sdev, shost) {
V_82 =
V_79 -> V_84 * V_88 /
( V_88 + V_96 ) ;
if ( ! V_82 )
V_82 = V_79 -> V_84 - 1 ;
else
V_82 = V_79 -> V_84 -
V_82 ;
F_21 ( V_79 , V_82 ,
V_103 ) ;
}
}
F_37 ( V_2 , V_101 ) ;
F_38 ( & V_2 -> V_88 , 0 ) ;
F_38 ( & V_2 -> V_96 , 0 ) ;
}
void
F_39 ( struct V_1 * V_2 )
{
struct V_33 * * V_101 ;
struct V_29 * V_30 ;
struct V_78 * V_79 ;
int V_37 ;
V_101 = F_34 ( V_2 ) ;
if ( V_101 != NULL )
for ( V_37 = 0 ; V_37 <= V_2 -> V_102 && V_101 [ V_37 ] != NULL ; V_37 ++ ) {
V_30 = F_35 ( V_101 [ V_37 ] ) ;
F_36 (sdev, shost) {
if ( V_101 [ V_37 ] -> V_97 <=
V_79 -> V_84 )
continue;
F_21 ( V_79 ,
V_79 -> V_84 + 1 ,
V_104 ) ;
}
}
F_37 ( V_2 , V_101 ) ;
F_38 ( & V_2 -> V_88 , 0 ) ;
F_38 ( & V_2 -> V_96 , 0 ) ;
}
void
F_40 ( struct V_1 * V_2 )
{
struct V_33 * * V_101 ;
struct V_29 * V_30 ;
struct V_78 * V_79 ;
struct V_105 * V_106 ;
int V_37 ;
V_101 = F_34 ( V_2 ) ;
if ( V_101 != NULL )
for ( V_37 = 0 ; V_37 <= V_2 -> V_102 && V_101 [ V_37 ] != NULL ; V_37 ++ ) {
V_30 = F_35 ( V_101 [ V_37 ] ) ;
F_36 (sdev, shost) {
V_106 = F_41 ( F_42 ( V_79 ) ) ;
F_43 ( V_106 ) ;
}
}
F_37 ( V_2 , V_101 ) ;
}
static int
F_44 ( struct V_33 * V_34 , int V_107 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_108 ;
struct V_109 * V_110 ;
T_2 * V_111 ;
T_3 V_112 ;
T_3 V_113 ;
T_3 V_114 ;
T_4 V_115 ;
int V_116 , V_117 ;
V_117 = V_2 -> V_118 -
( sizeof( struct V_119 ) + sizeof( struct V_120 ) ) ;
F_45 ( V_34 , V_121 , V_122 ,
L_5 ,
V_107 , V_2 -> V_118 ,
( int ) sizeof( struct V_119 ) ,
( int ) sizeof( struct V_120 ) , V_117 ) ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
V_108 = F_46 ( sizeof( struct V_15 ) , V_123 ) ;
if ( ! V_108 )
break;
V_108 -> V_124 = F_47 ( V_2 -> V_125 ,
V_123 , & V_108 -> V_126 ) ;
if ( ! V_108 -> V_124 ) {
F_48 ( V_108 ) ;
break;
}
memset ( V_108 -> V_124 , 0 , V_2 -> V_118 ) ;
V_115 = F_49 ( V_2 , & V_108 -> V_127 ) ;
if ( V_115 == 0 ) {
F_50 ( V_2 -> V_125 ,
V_108 -> V_124 , V_108 -> V_126 ) ;
F_48 ( V_108 ) ;
break;
}
V_108 -> V_127 . V_128 |= V_129 ;
V_108 -> V_119 = V_108 -> V_124 ;
V_108 -> V_120 = V_108 -> V_124 + sizeof( struct V_119 ) ;
V_108 -> V_19 = V_108 -> V_124 + sizeof( struct V_119 ) +
sizeof( struct V_120 ) ;
V_110 = V_108 -> V_19 ;
V_112 = V_108 -> V_126 ;
V_113 = V_108 -> V_126 + sizeof( struct V_119 ) ;
V_114 = V_108 -> V_126 + sizeof( struct V_119 ) +
sizeof( struct V_120 ) ;
V_110 [ 0 ] . V_130 = F_9 ( F_51 ( V_112 ) ) ;
V_110 [ 0 ] . V_131 = F_9 ( F_52 ( V_112 ) ) ;
V_110 [ 0 ] . V_132 . V_133 . V_134 = sizeof( struct V_119 ) ;
V_110 [ 0 ] . V_132 . V_133 . V_135 = V_136 ;
V_110 [ 0 ] . V_132 . V_137 = F_9 ( V_110 [ 0 ] . V_132 . V_137 ) ;
V_110 [ 1 ] . V_130 = F_9 ( F_51 ( V_113 ) ) ;
V_110 [ 1 ] . V_131 = F_9 ( F_52 ( V_113 ) ) ;
V_110 [ 1 ] . V_132 . V_133 . V_134 = sizeof( struct V_120 ) ;
V_110 [ 1 ] . V_132 . V_133 . V_135 = V_136 ;
V_110 [ 1 ] . V_132 . V_137 = F_9 ( V_110 [ 1 ] . V_132 . V_137 ) ;
V_111 = & V_108 -> V_127 . V_111 ;
V_111 -> V_58 . V_138 . V_139 . V_140 = 0 ;
if ( ( V_2 -> V_141 == 3 ) &&
! ( V_2 -> V_142 & V_143 ) ) {
V_111 -> V_58 . V_138 . V_139 . V_135 = V_144 ;
V_111 -> V_58 . V_138 . V_139 . V_134 = sizeof( struct V_119 ) ;
V_111 -> V_58 . V_138 . V_139 . V_131 = F_53 ( T_2 ,
V_145 . V_146 . V_147 ) ;
V_111 -> V_58 . V_138 . V_139 . V_130 = 0 ;
V_111 -> V_148 = 0 ;
V_111 -> V_149 = 0 ;
V_111 -> V_145 . V_146 . V_150 . V_132 . V_133 . V_135 =
V_136 ;
V_111 -> V_145 . V_146 . V_150 . V_132 . V_133 . V_134 =
sizeof( struct V_120 ) ;
V_111 -> V_145 . V_146 . V_150 . V_131 =
F_52 ( V_113 ) ;
V_111 -> V_145 . V_146 . V_150 . V_130 =
F_51 ( V_113 ) ;
} else {
V_111 -> V_58 . V_138 . V_139 . V_135 = V_151 ;
V_111 -> V_58 . V_138 . V_139 . V_134 =
( 2 * sizeof( struct V_109 ) ) ;
V_111 -> V_58 . V_138 . V_139 . V_131 =
F_52 ( V_114 ) ;
V_111 -> V_58 . V_138 . V_139 . V_130 =
F_51 ( V_114 ) ;
V_111 -> V_148 = 1 ;
V_111 -> V_149 = 1 ;
}
V_111 -> V_152 = V_153 ;
V_108 -> V_154 = V_155 ;
V_108 -> V_127 . V_156 = V_108 ;
F_54 ( V_2 , V_108 ) ;
}
return V_116 ;
}
void
F_55 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_108 , * V_157 ;
unsigned long V_158 = 0 ;
F_14 ( & V_2 -> V_75 , V_158 ) ;
F_56 ( & V_2 -> V_159 . V_160 ) ;
F_57 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_108 -> V_23 && V_108 -> V_23 -> V_25
&& V_108 -> V_23 -> V_25 -> V_34 == V_34 )
V_108 -> V_23 = NULL ;
}
F_58 ( & V_2 -> V_159 . V_160 ) ;
F_15 ( & V_2 -> V_75 , V_158 ) ;
}
void
F_59 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
T_4 V_163 = F_60 ( V_164 , V_162 ) ;
T_4 V_165 = F_60 ( V_166 , V_162 ) ;
struct V_15 * V_108 , * V_157 ;
unsigned long V_158 = 0 ;
struct V_167 * V_168 ;
int V_37 ;
struct V_24 * V_52 ;
int V_169 = 0 ;
struct V_170 * V_171 = & V_2 -> V_172 . V_173 [ V_174 ] ;
F_14 ( & V_2 -> V_75 , V_158 ) ;
F_56 ( & V_2 -> V_159 . V_160 ) ;
F_57 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_108 -> V_127 . V_175 == V_163 ) {
F_61 ( & V_108 -> V_176 ) ;
V_108 -> V_177 = 0 ;
V_108 -> V_154 = V_155 ;
F_58 (
& V_2 -> V_159 . V_160 ) ;
if ( V_108 -> V_23 && V_108 -> V_23 -> V_25 )
V_52 = V_108 -> V_23 -> V_25 ;
else
V_52 = NULL ;
V_169 = F_62 ( & V_2 -> V_178 ) ;
F_15 ( & V_2 -> V_75 , V_158 ) ;
if ( V_52 ) {
F_63 ( V_2 , V_52 ,
V_108 -> V_127 . V_179 , V_165 , 1 ) ;
F_64 ( V_2 , V_52 , V_162 ) ;
}
F_65 ( V_2 , V_108 ) ;
if ( V_169 )
F_20 ( V_2 ) ;
return;
}
}
F_58 ( & V_2 -> V_159 . V_160 ) ;
for ( V_37 = 1 ; V_37 <= V_2 -> V_172 . V_180 ; V_37 ++ ) {
V_168 = V_2 -> V_172 . V_181 [ V_37 ] ;
if ( ! ( V_168 -> V_128 & V_129 ) ||
( V_168 -> V_128 & V_182 ) )
continue;
if ( V_168 -> V_175 != V_163 )
continue;
V_108 = F_66 ( V_168 , struct V_15 , V_127 ) ;
V_108 -> V_177 = 0 ;
F_15 ( & V_2 -> V_75 , V_158 ) ;
if ( ! F_62 ( & V_171 -> V_183 ) )
F_20 ( V_2 ) ;
return;
}
F_15 ( & V_2 -> V_75 , V_158 ) ;
}
int
F_67 ( struct V_1 * V_2 ,
struct V_184 * V_185 , int V_186 )
{
struct V_15 * V_108 , * V_187 ;
int V_154 , V_188 ;
int V_189 = 0 , V_190 = 0 , V_191 = 0 , V_192 = 0 ;
T_3 V_193 ;
int V_194 = V_195 ;
F_68 ( V_196 ) ;
F_68 ( V_197 ) ;
F_68 ( V_198 ) ;
if ( V_186 <= 0 )
return - V_199 ;
V_188 = V_2 -> V_118 -
( sizeof( struct V_119 ) + sizeof( struct V_120 ) ) ;
F_57 (psb, psb_next, post_sblist, list) {
F_69 ( & V_108 -> V_176 ) ;
V_190 ++ ;
if ( ( V_194 != V_195 ) &&
( V_108 -> V_127 . V_175 != V_194 + 1 ) ) {
F_70 ( & V_196 , & V_197 ) ;
V_189 = V_190 - 1 ;
F_19 ( & V_108 -> V_176 , & V_196 ) ;
V_190 = 1 ;
} else {
F_19 ( & V_108 -> V_176 , & V_196 ) ;
if ( V_190 == V_200 ) {
F_70 ( & V_196 , & V_197 ) ;
V_189 = V_190 ;
V_190 = 0 ;
}
}
V_191 ++ ;
V_194 = V_108 -> V_127 . V_175 ;
if ( V_191 == V_186 ) {
if ( V_189 == 0 ) {
F_70 ( & V_196 , & V_197 ) ;
V_189 = V_190 ;
} else if ( V_190 == 1 ) {
if ( V_188 > V_201 )
V_193 = V_108 -> V_202 +
V_201 ;
else
V_193 = 0 ;
V_154 = F_71 ( V_2 ,
V_108 -> V_202 ,
V_193 ,
V_108 -> V_127 . V_175 ) ;
if ( V_154 ) {
V_108 -> V_177 = 1 ;
} else {
V_108 -> V_177 = 0 ;
V_108 -> V_154 = V_155 ;
V_192 ++ ;
}
F_19 ( & V_108 -> V_176 , & V_198 ) ;
}
}
if ( V_189 == 0 )
continue;
V_154 = F_72 ( V_2 , & V_197 ,
V_189 ) ;
if ( V_190 == 0 )
V_194 = V_195 ;
V_189 = 0 ;
while ( ! F_62 ( & V_197 ) ) {
F_73 ( & V_197 , V_108 ,
struct V_15 , V_176 ) ;
if ( V_154 ) {
V_108 -> V_177 = 1 ;
} else {
V_108 -> V_177 = 0 ;
V_108 -> V_154 = V_155 ;
V_192 ++ ;
}
F_19 ( & V_108 -> V_176 , & V_198 ) ;
}
}
while ( ! F_62 ( & V_198 ) ) {
F_73 ( & V_198 , V_108 ,
struct V_15 , V_176 ) ;
F_65 ( V_2 , V_108 ) ;
}
return V_192 ;
}
int
F_74 ( struct V_1 * V_2 )
{
F_68 ( V_185 ) ;
int V_192 , V_203 = 0 ;
F_75 ( & V_2 -> V_204 ) ;
F_75 ( & V_2 -> V_205 ) ;
F_70 ( & V_2 -> V_206 , & V_185 ) ;
F_76 ( & V_2 -> V_207 , & V_185 ) ;
F_77 ( & V_2 -> V_205 ) ;
F_77 ( & V_2 -> V_204 ) ;
if ( ! F_62 ( & V_185 ) ) {
V_192 = F_67 ( V_2 , & V_185 ,
V_2 -> V_159 . V_208 ) ;
if ( V_192 == 0 )
V_203 = - V_209 ;
}
return V_203 ;
}
static int
F_78 ( struct V_33 * V_34 , int V_107 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_108 ;
struct V_17 * V_18 ;
T_2 * V_111 ;
T_3 V_112 ;
T_3 V_113 ;
T_3 V_114 ;
T_4 V_115 , V_210 = 0 ;
int V_116 , V_192 , V_188 ;
F_68 ( V_196 ) ;
F_68 ( V_185 ) ;
F_68 ( V_198 ) ;
V_188 = V_2 -> V_118 -
( sizeof( struct V_119 ) + sizeof( struct V_120 ) ) ;
F_45 ( V_34 , V_121 , V_122 ,
L_6 ,
V_107 , V_2 -> V_118 , V_188 ,
( int ) sizeof( struct V_119 ) ,
( int ) sizeof( struct V_120 ) ) ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
V_108 = F_46 ( sizeof( struct V_15 ) , V_123 ) ;
if ( ! V_108 )
break;
V_108 -> V_124 = F_47 ( V_2 -> V_125 ,
V_123 , & V_108 -> V_126 ) ;
if ( ! V_108 -> V_124 ) {
F_48 ( V_108 ) ;
break;
}
memset ( V_108 -> V_124 , 0 , V_2 -> V_118 ) ;
if ( ( ( unsigned long ) ( V_108 -> V_124 ) &
( unsigned long ) ( V_211 - 1 ) ) != 0 ) {
F_50 ( V_2 -> V_125 ,
V_108 -> V_124 , V_108 -> V_126 ) ;
F_48 ( V_108 ) ;
break;
}
V_115 = F_49 ( V_2 , & V_108 -> V_127 ) ;
if ( V_115 == 0 ) {
F_50 ( V_2 -> V_125 ,
V_108 -> V_124 , V_108 -> V_126 ) ;
F_48 ( V_108 ) ;
break;
}
V_210 = F_79 ( V_2 ) ;
if ( V_210 == V_195 ) {
F_50 ( V_2 -> V_125 ,
V_108 -> V_124 , V_108 -> V_126 ) ;
F_48 ( V_108 ) ;
break;
}
V_108 -> V_127 . V_179 = V_210 ;
V_108 -> V_127 . V_175 = V_2 -> V_159 . V_212 [ V_210 ] ;
V_108 -> V_127 . V_128 |= V_129 ;
V_108 -> V_19 = V_108 -> V_124 ;
V_108 -> V_119 = ( V_108 -> V_124 + V_188 ) ;
V_108 -> V_120 = (struct V_120 * ) ( ( V_213 * ) V_108 -> V_119 +
sizeof( struct V_119 ) ) ;
V_18 = (struct V_17 * ) V_108 -> V_19 ;
V_114 = V_108 -> V_126 ;
V_112 = ( V_108 -> V_126 + V_188 ) ;
V_113 = V_112 + sizeof( struct V_119 ) ;
V_18 -> V_214 = F_11 ( F_51 ( V_112 ) ) ;
V_18 -> V_215 = F_11 ( F_52 ( V_112 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_216 = F_11 ( sizeof( struct V_119 ) ) ;
V_18 ++ ;
V_18 -> V_214 = F_11 ( F_51 ( V_113 ) ) ;
V_18 -> V_215 = F_11 ( F_52 ( V_113 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 1 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_216 = F_11 ( sizeof( struct V_120 ) ) ;
V_111 = & V_108 -> V_127 . V_111 ;
V_111 -> V_58 . V_138 . V_139 . V_140 = 0 ;
V_111 -> V_58 . V_138 . V_139 . V_135 = V_136 ;
V_111 -> V_58 . V_138 . V_139 . V_134 = sizeof( struct V_119 ) ;
V_111 -> V_58 . V_138 . V_139 . V_131 = F_52 ( V_112 ) ;
V_111 -> V_58 . V_138 . V_139 . V_130 = F_51 ( V_112 ) ;
V_111 -> V_148 = 1 ;
V_111 -> V_149 = 1 ;
V_111 -> V_152 = V_153 ;
V_108 -> V_127 . V_156 = V_108 ;
V_108 -> V_202 = V_114 ;
F_19 ( & V_108 -> V_176 , & V_185 ) ;
F_75 ( & V_2 -> V_204 ) ;
V_2 -> V_159 . V_208 ++ ;
F_77 ( & V_2 -> V_204 ) ;
}
F_3 ( V_2 , V_121 , V_11 ,
L_7
L_8 , V_116 , V_107 ) ;
if ( ! F_62 ( & V_185 ) )
V_192 = F_67 ( V_2 ,
& V_185 , V_116 ) ;
else
V_192 = 0 ;
return V_192 ;
}
static inline int
F_80 ( struct V_33 * V_34 , int V_107 )
{
return V_34 -> V_2 -> F_80 ( V_34 , V_107 ) ;
}
static struct V_15 *
F_81 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
struct V_15 * V_16 = NULL ;
struct V_184 * V_217 = & V_2 -> V_206 ;
unsigned long V_218 = 0 ;
unsigned long V_219 = 0 ;
F_14 ( & V_2 -> V_204 , V_218 ) ;
F_73 ( V_217 , V_16 , struct V_15 ,
V_176 ) ;
if ( ! V_16 ) {
F_14 ( & V_2 -> V_205 , V_219 ) ;
F_76 ( & V_2 -> V_207 ,
& V_2 -> V_206 ) ;
F_82 ( & V_2 -> V_207 ) ;
F_73 ( V_217 , V_16 ,
struct V_15 , V_176 ) ;
F_15 ( & V_2 -> V_205 , V_219 ) ;
}
F_15 ( & V_2 -> V_204 , V_218 ) ;
return V_16 ;
}
static struct V_15 *
F_83 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
struct V_15 * V_16 ;
unsigned long V_218 = 0 ;
unsigned long V_219 = 0 ;
int V_220 = 0 ;
F_14 ( & V_2 -> V_204 , V_218 ) ;
F_84 (lpfc_cmd, &phba->lpfc_scsi_buf_list_get, list) {
if ( F_85 ( V_2 , V_52 ,
V_16 -> V_127 . V_179 ) )
continue;
F_61 ( & V_16 -> V_176 ) ;
V_220 = 1 ;
break;
}
if ( ! V_220 ) {
F_14 ( & V_2 -> V_205 , V_219 ) ;
F_76 ( & V_2 -> V_207 ,
& V_2 -> V_206 ) ;
F_82 ( & V_2 -> V_207 ) ;
F_15 ( & V_2 -> V_205 , V_219 ) ;
F_84 (lpfc_cmd, &phba->lpfc_scsi_buf_list_get,
list) {
if ( F_85 (
V_2 , V_52 , V_16 -> V_127 . V_179 ) )
continue;
F_61 ( & V_16 -> V_176 ) ;
V_220 = 1 ;
break;
}
}
F_15 ( & V_2 -> V_204 , V_218 ) ;
if ( ! V_220 )
return NULL ;
return V_16 ;
}
static struct V_15 *
F_86 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
return V_2 -> F_86 ( V_2 , V_52 ) ;
}
static void
F_54 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
unsigned long V_158 = 0 ;
V_108 -> V_221 = 0 ;
V_108 -> V_222 = 0 ;
V_108 -> V_223 = 0 ;
F_14 ( & V_2 -> V_205 , V_158 ) ;
V_108 -> V_27 = NULL ;
V_108 -> V_127 . V_128 = V_129 ;
F_19 ( & V_108 -> V_176 , & V_2 -> V_207 ) ;
F_15 ( & V_2 -> V_205 , V_158 ) ;
}
static void
F_65 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
unsigned long V_158 = 0 ;
V_108 -> V_221 = 0 ;
V_108 -> V_222 = 0 ;
V_108 -> V_223 = 0 ;
if ( V_108 -> V_177 ) {
F_14 ( & V_2 -> V_159 . V_160 ,
V_158 ) ;
V_108 -> V_27 = NULL ;
F_19 ( & V_108 -> V_176 ,
& V_2 -> V_159 . V_224 ) ;
F_15 ( & V_2 -> V_159 . V_160 ,
V_158 ) ;
} else {
V_108 -> V_27 = NULL ;
V_108 -> V_127 . V_128 = V_129 ;
F_14 ( & V_2 -> V_205 , V_158 ) ;
F_19 ( & V_108 -> V_176 , & V_2 -> V_207 ) ;
F_15 ( & V_2 -> V_205 , V_158 ) ;
}
}
static void
F_87 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
V_2 -> F_87 ( V_2 , V_108 ) ;
}
static int
F_88 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_7 * V_225 = NULL ;
struct V_119 * V_119 = V_16 -> V_119 ;
struct V_109 * V_110 = V_16 -> V_19 ;
struct V_167 * V_168 = & V_16 -> V_127 ;
T_2 * V_226 = & V_16 -> V_127 . V_111 ;
struct V_109 * V_227 = V_226 -> V_145 . V_146 . V_228 ;
T_3 V_229 ;
T_1 V_230 = 0 ;
int V_231 , V_232 = V_3 -> V_233 ;
V_110 += 2 ;
if ( F_89 ( V_3 ) ) {
V_231 = F_90 ( & V_2 -> V_234 -> V_235 , F_2 ( V_3 ) ,
F_89 ( V_3 ) , V_232 ) ;
if ( F_91 ( ! V_231 ) )
return 1 ;
V_16 -> V_221 = V_231 ;
if ( V_16 -> V_221 > V_2 -> V_236 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_9
L_10 ,
V_12 , V_2 -> V_236 ,
V_16 -> V_221 ) ;
V_16 -> V_221 = 0 ;
F_92 ( V_3 ) ;
return 1 ;
}
F_93 (scsi_cmnd, sgel, nseg, num_bde) {
V_229 = F_94 ( V_225 ) ;
if ( V_2 -> V_141 == 3 &&
! ( V_2 -> V_142 & V_143 ) &&
! ( V_168 -> V_128 & V_237 ) &&
V_231 <= V_238 ) {
V_227 -> V_132 . V_133 . V_135 = V_136 ;
V_227 -> V_132 . V_133 . V_134 = F_95 ( V_225 ) ;
V_227 -> V_131 = F_52 ( V_229 ) ;
V_227 -> V_130 = F_51 ( V_229 ) ;
V_227 ++ ;
} else {
V_110 -> V_132 . V_133 . V_135 = V_136 ;
V_110 -> V_132 . V_133 . V_134 = F_95 ( V_225 ) ;
V_110 -> V_132 . V_137 = F_9 ( V_110 -> V_132 . V_137 ) ;
V_110 -> V_131 =
F_9 ( F_52 ( V_229 ) ) ;
V_110 -> V_130 =
F_9 ( F_51 ( V_229 ) ) ;
V_110 ++ ;
}
}
}
if ( V_2 -> V_141 == 3 &&
! ( V_2 -> V_142 & V_143 ) &&
! ( V_168 -> V_128 & V_237 ) ) {
if ( V_230 > V_238 ) {
V_229 = V_16 -> V_126 ;
V_227 -> V_132 . V_133 . V_135 = V_151 ;
V_227 -> V_132 . V_133 . V_134 = ( V_230 *
sizeof( struct V_109 ) ) ;
V_229 += ( sizeof( struct V_119 ) +
sizeof( struct V_120 ) +
( 2 * sizeof( struct V_109 ) ) ) ;
V_227 -> V_130 = F_51 ( V_229 ) ;
V_227 -> V_131 = F_52 ( V_229 ) ;
V_226 -> V_145 . V_146 . V_239 = 2 ;
} else {
V_226 -> V_145 . V_146 . V_239 = ( V_230 + 1 ) ;
}
} else {
V_226 -> V_58 . V_138 . V_139 . V_134 =
( ( V_230 + 2 ) * sizeof( struct V_109 ) ) ;
V_226 -> V_145 . V_146 . V_239 = ( V_230 + 1 ) ;
}
V_119 -> V_240 = F_96 ( F_97 ( V_3 ) ) ;
V_226 -> V_58 . V_241 . V_242 = F_97 ( V_3 ) ;
return 0 ;
}
static inline unsigned
F_98 ( struct V_3 * V_243 )
{
return V_243 -> V_31 -> V_244 ;
}
static int
F_99 ( struct V_1 * V_2 , struct V_3 * V_243 ,
T_1 * V_245 , T_4 * V_246 , T_1 V_247 )
{
struct V_7 * V_248 ;
struct V_7 * V_8 ;
struct V_15 * V_16 = NULL ;
struct V_249 * V_5 = NULL ;
struct V_24 * V_52 ;
struct V_22 * V_23 ;
T_1 V_250 = F_100 ( V_243 ) ;
T_1 V_251 ;
T_1 V_252 ;
T_5 V_253 ;
int V_203 = 0 ;
int V_254 = 0 ;
if ( V_250 == V_255 )
return 0 ;
V_248 = F_7 ( V_243 ) ;
V_8 = F_2 ( V_243 ) ;
V_253 = F_101 ( V_243 ) ;
if ( V_2 -> V_256 != V_257 ) {
V_251 = F_98 ( V_243 ) ;
V_252 = ( F_97 ( V_243 ) + V_251 - 1 ) / V_251 ;
if ( ( V_2 -> V_256 < V_253 ) ||
( V_2 -> V_256 >= ( V_253 + V_252 ) ) )
return 0 ;
if ( V_248 ) {
V_254 = V_2 -> V_256 - V_253 ;
V_252 = F_95 ( V_248 ) /
sizeof( struct V_249 ) ;
if ( V_252 < V_254 )
V_254 = V_252 ;
}
}
V_23 = V_243 -> V_31 -> V_35 ;
if ( V_23 && V_23 -> V_25 ) {
V_52 = V_23 -> V_25 ;
if ( V_2 -> V_258 &&
( V_2 -> V_258 != V_52 -> V_259 ) )
return 0 ;
if ( V_2 -> V_260 . V_261 . V_262 [ 0 ] &&
( memcmp ( & V_52 -> V_66 , & V_2 -> V_260 ,
sizeof( struct V_67 ) ) != 0 ) )
return 0 ;
}
if ( V_248 ) {
V_5 = (struct V_249 * ) F_4 ( V_248 ) ;
V_5 += V_254 ;
V_16 = (struct V_15 * ) V_243 -> V_263 ;
}
if ( V_245 ) {
if ( V_2 -> V_264 ) {
switch ( V_250 ) {
case V_265 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_11
L_12 ,
( unsigned long ) V_253 , V_254 ,
F_102 ( V_5 -> V_266 ) ) ;
if ( V_16 ) {
V_16 -> V_267 =
V_268 ;
V_16 -> V_269 =
V_5 ;
V_16 -> V_270 =
V_5 -> V_266 ;
}
V_5 -> V_266 = F_96 ( 0xDEADBEEF ) ;
V_2 -> V_264 -- ;
if ( V_2 -> V_264 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_271 | V_272 ;
break;
}
case V_273 :
* V_245 = 0xDEADBEEF ;
V_2 -> V_264 -- ;
if ( V_2 -> V_264 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_271 | V_272 ;
F_3 ( V_2 , V_10 , V_11 ,
L_13
L_14 , ( unsigned long ) V_253 ) ;
break;
case V_274 :
* V_245 = 0xDEADBEEF ;
V_2 -> V_264 -- ;
if ( V_2 -> V_264 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_15
L_14 , ( unsigned long ) V_253 ) ;
break;
}
}
if ( V_2 -> V_276 ) {
switch ( V_250 ) {
case V_277 :
case V_278 :
case V_279 :
* V_245 = 0xDEADBEEF ;
V_2 -> V_276 -- ;
if ( V_2 -> V_276 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_16
L_17 , ( unsigned long ) V_253 ) ;
break;
}
}
}
if ( V_246 ) {
if ( V_2 -> V_280 ) {
switch ( V_250 ) {
case V_265 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_18
L_19 ,
( unsigned long ) V_253 , V_254 ,
F_103 ( V_5 -> V_281 ) ) ;
if ( V_16 ) {
V_16 -> V_267 =
V_282 ;
V_16 -> V_269 =
V_5 ;
V_16 -> V_270 =
V_5 -> V_281 ;
}
V_5 -> V_281 = F_104 ( 0xDEAD ) ;
V_2 -> V_280 -- ;
if ( V_2 -> V_280 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_271 | V_272 ;
break;
}
case V_273 :
* V_246 = 0xDEAD ;
V_2 -> V_280 -- ;
if ( V_2 -> V_280 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_271 | V_272 ;
F_3 ( V_2 , V_10 , V_11 ,
L_20
L_14 , ( unsigned long ) V_253 ) ;
break;
case V_274 :
* V_246 = 0xDEAD ;
V_2 -> V_280 -- ;
if ( V_2 -> V_280 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_21
L_14 , ( unsigned long ) V_253 ) ;
break;
}
}
if ( V_2 -> V_283 ) {
switch ( V_250 ) {
case V_277 :
case V_278 :
case V_279 :
* V_246 = 0xDEAD ;
V_2 -> V_283 -- ;
if ( V_2 -> V_283 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 ;
F_3 ( V_2 , V_10 , V_11 ,
L_22
L_17 , ( unsigned long ) V_253 ) ;
break;
}
}
}
if ( V_247 ) {
if ( V_2 -> V_284 ) {
switch ( V_250 ) {
case V_265 :
V_203 = V_272 ;
case V_273 :
V_2 -> V_284 -- ;
if ( V_2 -> V_284 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 |= V_271 | V_285 ;
F_3 ( V_2 , V_10 , V_11 ,
L_23
L_14 , ( unsigned long ) V_253 ) ;
break;
case V_274 :
V_2 -> V_284 -- ;
if ( V_2 -> V_284 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 | V_285 ;
F_3 ( V_2 , V_10 , V_11 ,
L_24
L_14 , ( unsigned long ) V_253 ) ;
break;
}
}
if ( V_2 -> V_286 ) {
switch ( V_250 ) {
case V_277 :
case V_278 :
case V_279 :
V_2 -> V_286 -- ;
if ( V_2 -> V_286 == 0 ) {
V_2 -> V_258 = 0 ;
V_2 -> V_256 =
V_257 ;
memset ( & V_2 -> V_260 ,
0 , sizeof( struct V_67 ) ) ;
}
V_203 = V_275 | V_285 ;
F_3 ( V_2 , V_10 , V_11 ,
L_25
L_17 , ( unsigned long ) V_253 ) ;
}
}
}
return V_203 ;
}
static int
F_105 ( struct V_1 * V_2 , struct V_3 * V_243 ,
V_213 * V_287 , V_213 * V_288 )
{
V_213 V_289 = F_106 ( V_243 -> V_31 -> V_32 ) ;
V_213 V_290 = 0 ;
if ( V_289 == V_291 ) {
switch ( F_100 ( V_243 ) ) {
case V_277 :
case V_274 :
* V_288 = V_292 ;
* V_287 = V_293 ;
break;
case V_278 :
case V_273 :
* V_288 = V_294 ;
* V_287 = V_295 ;
break;
case V_279 :
case V_265 :
* V_288 = V_296 ;
* V_287 = V_297 ;
break;
case V_255 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_26 ,
F_100 ( V_243 ) ) ;
V_290 = 1 ;
break;
}
} else {
switch ( F_100 ( V_243 ) ) {
case V_278 :
case V_273 :
* V_288 = V_294 ;
* V_287 = V_295 ;
break;
case V_279 :
case V_265 :
* V_288 = V_298 ;
* V_287 = V_298 ;
break;
case V_277 :
case V_274 :
* V_288 = V_295 ;
* V_287 = V_294 ;
break;
case V_255 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_27 ,
F_100 ( V_243 ) ) ;
V_290 = 1 ;
break;
}
}
return V_290 ;
}
static int
F_107 ( struct V_1 * V_2 , struct V_3 * V_243 ,
V_213 * V_287 , V_213 * V_288 )
{
V_213 V_289 = F_106 ( V_243 -> V_31 -> V_32 ) ;
V_213 V_290 = 0 ;
if ( V_289 == V_291 ) {
switch ( F_100 ( V_243 ) ) {
case V_277 :
case V_274 :
* V_288 = V_295 ;
* V_287 = V_294 ;
break;
case V_278 :
case V_273 :
* V_288 = V_293 ;
* V_287 = V_292 ;
break;
case V_279 :
case V_265 :
* V_288 = V_297 ;
* V_287 = V_296 ;
break;
case V_255 :
default:
break;
}
} else {
switch ( F_100 ( V_243 ) ) {
case V_278 :
case V_273 :
* V_288 = V_293 ;
* V_287 = V_292 ;
break;
case V_279 :
case V_265 :
* V_288 = V_299 ;
* V_287 = V_299 ;
break;
case V_277 :
case V_274 :
* V_288 = V_292 ;
* V_287 = V_293 ;
break;
case V_255 :
default:
break;
}
}
return V_290 ;
}
static int
F_108 ( struct V_1 * V_2 , struct V_3 * V_243 ,
struct V_109 * V_110 , int V_300 )
{
struct V_7 * V_8 = NULL ;
struct V_301 * V_302 = NULL ;
struct V_303 * V_304 = NULL ;
T_3 V_229 ;
int V_37 = 0 , V_230 = 0 , V_154 ;
int V_232 = V_243 -> V_233 ;
#ifdef F_109
T_1 V_203 ;
#endif
T_1 V_305 = 1 ;
T_1 V_245 ;
unsigned V_251 ;
V_213 V_287 , V_288 ;
V_154 = F_105 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_154 )
goto V_306;
V_251 = F_98 ( V_243 ) ;
V_245 = ( T_1 ) F_101 ( V_243 ) ;
#ifdef F_109
V_203 = F_99 ( V_2 , V_243 , & V_245 , NULL , 1 ) ;
if ( V_203 ) {
if ( V_203 & V_285 )
F_107 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_203 & V_272 )
V_305 = 0 ;
}
#endif
V_302 = (struct V_301 * ) V_110 ;
memset ( V_302 , 0 , sizeof( struct V_301 ) ) ;
F_10 ( V_307 , V_302 , V_308 ) ;
V_302 -> V_309 = F_11 ( V_302 -> V_309 ) ;
V_302 -> V_245 = F_11 ( V_245 ) ;
V_230 ++ ;
V_110 ++ ;
V_304 = (struct V_303 * ) V_110 ;
memset ( V_304 , 0 , sizeof( struct V_303 ) ) ;
F_10 ( V_310 , V_304 , V_311 ) ;
F_10 ( V_312 , V_304 , V_287 ) ;
F_10 ( V_313 , V_304 , V_288 ) ;
if ( V_232 == V_314 ) {
if ( F_110 ( V_243 , V_315 ) )
F_10 ( V_316 , V_304 , V_305 ) ;
else
F_10 ( V_316 , V_304 , 0 ) ;
if ( F_110 ( V_243 , V_317 ) )
F_10 ( V_318 , V_304 , V_305 ) ;
else
F_10 ( V_318 , V_304 , 0 ) ;
}
F_10 ( V_319 , V_304 , 1 ) ;
F_10 ( V_320 , V_304 , 0 ) ;
F_10 ( V_321 , V_304 , 0 ) ;
V_304 -> V_309 = F_11 ( V_304 -> V_309 ) ;
V_304 -> V_322 = F_11 ( V_304 -> V_322 ) ;
V_304 -> V_20 = F_11 ( V_304 -> V_20 ) ;
V_230 ++ ;
V_110 ++ ;
F_93 (sc, sgde, datasegcnt, i) {
V_229 = F_94 ( V_8 ) ;
V_110 -> V_131 = F_9 ( F_52 ( V_229 ) ) ;
V_110 -> V_130 = F_9 ( F_51 ( V_229 ) ) ;
V_110 -> V_132 . V_133 . V_134 = F_95 ( V_8 ) ;
if ( V_232 == V_323 )
V_110 -> V_132 . V_133 . V_135 = V_136 ;
else
V_110 -> V_132 . V_133 . V_135 = V_324 ;
V_110 -> V_132 . V_137 = F_9 ( V_110 -> V_132 . V_137 ) ;
V_110 ++ ;
V_230 ++ ;
}
V_306:
return V_230 ;
}
static int
F_111 ( struct V_1 * V_2 , struct V_3 * V_243 ,
struct V_109 * V_110 , int V_325 , int V_326 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_248 = NULL ;
struct V_301 * V_302 = NULL ;
struct V_303 * V_304 = NULL ;
struct V_327 * V_328 = NULL ;
T_3 V_329 , V_330 ;
unsigned short V_331 = 0 , V_332 = 0 ;
unsigned int V_333 ;
unsigned int V_334 , V_335 = 0 , V_336 ;
unsigned int V_337 , V_338 ;
unsigned int V_339 , V_340 ;
int V_154 ;
int V_232 = V_243 -> V_233 ;
unsigned char V_341 = 0 , V_342 = 0 ;
unsigned V_251 ;
#ifdef F_109
T_1 V_203 ;
#endif
T_1 V_305 = 1 ;
T_1 V_245 ;
V_213 V_287 , V_288 ;
int V_230 = 0 ;
V_248 = F_7 ( V_243 ) ;
V_8 = F_2 ( V_243 ) ;
if ( ! V_248 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_122 ,
L_28 ,
V_248 , V_8 ) ;
return 0 ;
}
V_154 = F_105 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_154 )
goto V_306;
V_251 = F_98 ( V_243 ) ;
V_245 = ( T_1 ) F_101 ( V_243 ) ;
#ifdef F_109
V_203 = F_99 ( V_2 , V_243 , & V_245 , NULL , 1 ) ;
if ( V_203 ) {
if ( V_203 & V_285 )
F_107 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_203 & V_272 )
V_305 = 0 ;
}
#endif
V_333 = 0 ;
do {
if ( V_230 >= ( V_2 -> V_343 - 2 ) )
return V_230 + 3 ;
V_302 = (struct V_301 * ) V_110 ;
memset ( V_302 , 0 , sizeof( struct V_301 ) ) ;
F_10 ( V_307 , V_302 , V_308 ) ;
V_302 -> V_309 = F_11 ( V_302 -> V_309 ) ;
V_302 -> V_245 = F_11 ( V_245 ) ;
V_230 ++ ;
V_110 ++ ;
V_304 = (struct V_303 * ) V_110 ;
memset ( V_304 , 0 , sizeof( struct V_303 ) ) ;
F_10 ( V_310 , V_304 , V_311 ) ;
F_10 ( V_312 , V_304 , V_287 ) ;
F_10 ( V_313 , V_304 , V_288 ) ;
if ( F_110 ( V_243 , V_315 ) )
F_10 ( V_316 , V_304 , V_305 ) ;
else
F_10 ( V_316 , V_304 , 0 ) ;
if ( F_110 ( V_243 , V_317 ) )
F_10 ( V_318 , V_304 , V_305 ) ;
else
F_10 ( V_318 , V_304 , 0 ) ;
F_10 ( V_319 , V_304 , 1 ) ;
F_10 ( V_320 , V_304 , 0 ) ;
F_10 ( V_321 , V_304 , 0 ) ;
V_304 -> V_309 = F_11 ( V_304 -> V_309 ) ;
V_304 -> V_322 = F_11 ( V_304 -> V_322 ) ;
V_304 -> V_20 = F_11 ( V_304 -> V_20 ) ;
V_230 ++ ;
V_110 ++ ;
V_330 = F_94 ( V_248 ) + V_335 ;
V_334 = F_95 ( V_248 ) - V_335 ;
F_112 ( V_334 % 8 ) ;
V_328 = (struct V_327 * ) V_110 ;
memset ( V_328 , 0 , sizeof( struct V_327 ) ) ;
F_10 ( V_344 , V_328 , V_345 ) ;
V_328 -> V_130 = F_9 ( F_51 ( V_330 ) ) ;
V_328 -> V_131 = F_9 ( F_52 ( V_330 ) ) ;
V_337 = V_334 / 8 ;
V_338 = V_337 * V_251 ;
if ( ( V_328 -> V_131 & 0xfff ) + V_334 > 0x1000 ) {
V_336 = 0x1000 - ( V_328 -> V_131 & 0xfff ) ;
V_335 += V_336 ;
V_337 = V_336 / 8 ;
V_338 = V_337 * V_251 ;
} else {
V_335 = 0 ;
V_332 ++ ;
}
V_230 ++ ;
V_341 = 0 ;
V_340 = 0 ;
while ( ! V_341 ) {
if ( V_230 >= V_2 -> V_343 )
return V_230 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_29 ,
V_12 ) ;
return 0 ;
}
V_110 ++ ;
V_329 = F_94 ( V_8 ) + V_333 ;
V_110 -> V_131 = F_9 ( F_52 ( V_329 ) ) ;
V_110 -> V_130 = F_9 ( F_51 ( V_329 ) ) ;
V_339 = F_95 ( V_8 ) - V_333 ;
if ( ( V_340 + V_339 ) <= V_338 ) {
V_110 -> V_132 . V_133 . V_134 = V_339 ;
V_333 = 0 ;
if ( ( V_340 + V_339 ) == V_338 )
V_341 = 1 ;
} else {
V_110 -> V_132 . V_133 . V_134 = V_338 - V_340 ;
V_333 += V_110 -> V_132 . V_133 . V_134 ;
}
V_340 += V_110 -> V_132 . V_133 . V_134 ;
if ( V_232 == V_323 )
V_110 -> V_132 . V_133 . V_135 = V_136 ;
else
V_110 -> V_132 . V_133 . V_135 = V_324 ;
V_110 -> V_132 . V_137 = F_9 ( V_110 -> V_132 . V_137 ) ;
V_230 ++ ;
V_331 ++ ;
if ( V_333 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_335 ) {
V_245 += V_337 ;
V_110 ++ ;
continue;
}
if ( V_332 == V_326 ) {
V_342 = 1 ;
} else if ( V_332 < V_326 ) {
V_248 = F_5 ( V_248 ) ;
V_110 ++ ;
V_245 += V_337 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_30 , V_12 ) ;
}
} while ( ! V_342 );
V_306:
return V_230 ;
}
static int
F_113 ( struct V_1 * V_2 , struct V_3 * V_243 ,
struct V_17 * V_18 , int V_300 )
{
struct V_7 * V_8 = NULL ;
struct V_346 * V_347 = NULL ;
T_3 V_229 ;
int V_37 = 0 , V_348 = 0 , V_154 ;
T_1 V_245 ;
unsigned V_251 ;
V_213 V_287 , V_288 ;
#ifdef F_109
T_1 V_203 ;
#endif
T_1 V_305 = 1 ;
T_1 V_349 ;
T_1 V_350 = 0 ;
V_154 = F_105 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_154 )
goto V_306;
V_251 = F_98 ( V_243 ) ;
V_245 = ( T_1 ) F_101 ( V_243 ) ;
#ifdef F_109
V_203 = F_99 ( V_2 , V_243 , & V_245 , NULL , 1 ) ;
if ( V_203 ) {
if ( V_203 & V_285 )
F_107 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_203 & V_272 )
V_305 = 0 ;
}
#endif
V_347 = (struct V_346 * ) V_18 ;
memset ( V_347 , 0 , sizeof( struct V_346 ) ) ;
F_10 ( V_351 , V_18 , V_352 ) ;
V_347 -> V_266 = F_11 ( V_245 ) ;
V_347 -> V_353 = V_347 -> V_266 ;
if ( V_243 -> V_233 == V_314 ) {
if ( F_110 ( V_243 , V_315 ) )
F_10 ( V_354 , V_347 , V_305 ) ;
else
F_10 ( V_354 , V_347 , 0 ) ;
if ( F_110 ( V_243 , V_317 ) )
F_10 ( V_355 , V_347 , V_305 ) ;
else
F_10 ( V_355 , V_347 , 0 ) ;
}
F_10 ( V_356 , V_347 , V_287 ) ;
F_10 ( V_357 , V_347 , V_288 ) ;
F_10 ( V_358 , V_347 , 1 ) ;
F_10 ( V_359 , V_347 , 0 ) ;
V_347 -> V_20 = F_11 ( V_347 -> V_20 ) ;
V_347 -> V_360 = F_11 ( V_347 -> V_360 ) ;
V_348 ++ ;
V_18 ++ ;
F_93 (sc, sgde, datasegcnt, i) {
V_229 = F_94 ( V_8 ) ;
V_349 = F_95 ( V_8 ) ;
V_18 -> V_215 = F_11 ( F_52 ( V_229 ) ) ;
V_18 -> V_214 = F_11 ( F_51 ( V_229 ) ) ;
if ( ( V_37 + 1 ) == V_300 )
F_10 ( V_21 , V_18 , 1 ) ;
else
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_361 , V_18 , V_350 ) ;
F_10 ( V_351 , V_18 , V_362 ) ;
V_18 -> V_216 = F_11 ( V_349 ) ;
V_350 += V_349 ;
V_18 ++ ;
V_348 ++ ;
}
V_306:
return V_348 ;
}
static int
F_114 ( struct V_1 * V_2 , struct V_3 * V_243 ,
struct V_17 * V_18 , int V_325 , int V_326 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_248 = NULL ;
struct V_346 * V_347 = NULL ;
T_3 V_329 , V_330 ;
unsigned short V_331 = 0 , V_332 = 0 ;
unsigned int V_333 ;
unsigned int V_334 , V_335 = 0 , V_336 ;
unsigned int V_337 , V_338 ;
unsigned int V_339 , V_340 ;
int V_154 ;
unsigned char V_341 = 0 , V_342 = 0 ;
unsigned V_251 ;
T_1 V_245 ;
V_213 V_287 , V_288 ;
T_1 V_349 ;
#ifdef F_109
T_1 V_203 ;
#endif
T_1 V_305 = 1 ;
T_1 V_350 = 0 ;
int V_348 = 0 ;
V_248 = F_7 ( V_243 ) ;
V_8 = F_2 ( V_243 ) ;
if ( ! V_248 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_122 ,
L_31 ,
V_248 , V_8 ) ;
return 0 ;
}
V_154 = F_105 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_154 )
goto V_306;
V_251 = F_98 ( V_243 ) ;
V_245 = ( T_1 ) F_101 ( V_243 ) ;
#ifdef F_109
V_203 = F_99 ( V_2 , V_243 , & V_245 , NULL , 1 ) ;
if ( V_203 ) {
if ( V_203 & V_285 )
F_107 ( V_2 , V_243 , & V_287 , & V_288 ) ;
if ( V_203 & V_272 )
V_305 = 0 ;
}
#endif
V_333 = 0 ;
do {
if ( V_348 >= ( V_2 -> V_343 - 2 ) )
return V_348 + 3 ;
V_347 = (struct V_346 * ) V_18 ;
memset ( V_347 , 0 , sizeof( struct V_346 ) ) ;
F_10 ( V_351 , V_18 , V_352 ) ;
V_347 -> V_266 = F_11 ( V_245 ) ;
V_347 -> V_353 = V_347 -> V_266 ;
if ( F_110 ( V_243 , V_315 ) ) {
F_10 ( V_354 , V_347 , V_305 ) ;
} else {
F_10 ( V_354 , V_347 , 0 ) ;
if ( V_287 == V_298 ) {
V_287 = V_363 ;
V_288 = V_363 ;
}
}
if ( F_110 ( V_243 , V_317 ) )
F_10 ( V_355 , V_347 , V_305 ) ;
else
F_10 ( V_355 , V_347 , 0 ) ;
F_10 ( V_356 , V_347 , V_287 ) ;
F_10 ( V_357 , V_347 , V_288 ) ;
F_10 ( V_358 , V_347 , 1 ) ;
F_10 ( V_359 , V_347 , 0 ) ;
V_347 -> V_20 = F_11 ( V_347 -> V_20 ) ;
V_347 -> V_360 = F_11 ( V_347 -> V_360 ) ;
V_348 ++ ;
V_18 ++ ;
V_330 = F_94 ( V_248 ) + V_335 ;
V_334 = F_95 ( V_248 ) - V_335 ;
F_112 ( V_334 % 8 ) ;
V_18 -> V_20 = 0 ;
F_10 ( V_351 , V_18 , V_364 ) ;
V_18 -> V_214 = F_9 ( F_51 ( V_330 ) ) ;
V_18 -> V_215 = F_9 ( F_52 ( V_330 ) ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_337 = V_334 / 8 ;
V_338 = V_337 * V_251 ;
if ( ( V_18 -> V_215 & 0xfff ) + V_334 > 0x1000 ) {
V_336 = 0x1000 - ( V_18 -> V_215 & 0xfff ) ;
V_335 += V_336 ;
V_337 = V_336 / 8 ;
V_338 = V_337 * V_251 ;
} else {
V_335 = 0 ;
V_332 ++ ;
}
V_348 ++ ;
V_341 = 0 ;
V_340 = 0 ;
while ( ! V_341 ) {
if ( V_348 >= V_2 -> V_343 )
return V_348 + 1 ;
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_32 ,
V_12 ) ;
return 0 ;
}
V_18 ++ ;
V_329 = F_94 ( V_8 ) + V_333 ;
V_339 = F_95 ( V_8 ) - V_333 ;
if ( ( V_340 + V_339 ) <= V_338 ) {
V_349 = V_339 ;
V_333 = 0 ;
if ( ( V_340 + V_339 ) == V_338 )
V_341 = 1 ;
} else {
V_349 = V_338 - V_340 ;
V_333 += V_349 ;
}
V_340 += V_349 ;
V_18 -> V_215 = F_11 ( F_52 ( V_329 ) ) ;
V_18 -> V_214 = F_11 ( F_51 ( V_329 ) ) ;
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_361 , V_18 , V_350 ) ;
F_10 ( V_351 , V_18 , V_362 ) ;
V_18 -> V_216 = F_11 ( V_349 ) ;
V_350 += V_349 ;
V_348 ++ ;
V_331 ++ ;
if ( V_333 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_335 ) {
V_245 += V_337 ;
V_18 ++ ;
continue;
}
if ( V_332 == V_326 ) {
F_10 ( V_21 , V_18 , 1 ) ;
V_342 = 1 ;
} else if ( V_332 < V_326 ) {
V_248 = F_5 ( V_248 ) ;
V_18 ++ ;
V_245 += V_337 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_33 , V_12 ) ;
}
} while ( ! V_342 );
V_306:
return V_348 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_3 * V_243 )
{
int V_290 = V_365 ;
unsigned char V_250 = F_100 ( V_243 ) ;
switch ( V_250 ) {
case V_278 :
case V_273 :
V_290 = V_366 ;
break;
case V_277 :
case V_274 :
case V_279 :
case V_265 :
V_290 = V_367 ;
break;
default:
F_3 ( V_2 , V_10 , V_122 ,
L_34 , V_250 ) ;
break;
}
return V_290 ;
}
static int
F_116 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_243 = V_16 -> V_27 ;
int V_368 ;
V_368 = F_97 ( V_243 ) ;
if ( V_243 -> V_233 == V_314 ) {
if ( F_100 ( V_243 ) == V_277 )
return V_368 ;
} else {
if ( F_100 ( V_243 ) == V_274 )
return V_368 ;
}
if ( F_110 ( V_243 , V_369 ) )
V_368 += ( V_368 / F_98 ( V_243 ) ) * 8 ;
return V_368 ;
}
static int
F_117 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_119 * V_119 = V_16 -> V_119 ;
struct V_109 * V_110 = V_16 -> V_19 ;
T_2 * V_226 = & V_16 -> V_127 . V_111 ;
T_1 V_230 = 0 ;
int V_300 , V_370 , V_232 = V_3 -> V_233 ;
int V_371 = 0 ;
int V_368 ;
V_110 += 2 ;
if ( F_89 ( V_3 ) ) {
V_300 = F_90 ( & V_2 -> V_234 -> V_235 ,
F_2 ( V_3 ) ,
F_89 ( V_3 ) , V_232 ) ;
if ( F_91 ( ! V_300 ) )
return 1 ;
V_16 -> V_221 = V_300 ;
if ( V_16 -> V_221 > V_2 -> V_236 )
goto V_372;
V_371 = F_115 ( V_2 , V_3 ) ;
switch ( V_371 ) {
case V_366 :
if ( ( V_16 -> V_221 + 2 ) > V_2 -> V_343 )
goto V_372;
V_230 = F_108 ( V_2 , V_3 , V_110 ,
V_300 ) ;
if ( V_230 < 2 )
goto V_372;
break;
case V_367 :
V_370 = F_90 ( & V_2 -> V_234 -> V_235 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_232 ) ;
if ( F_91 ( ! V_370 ) ) {
F_92 ( V_3 ) ;
return 1 ;
}
V_16 -> V_223 = V_370 ;
if ( ( V_16 -> V_223 * 4 ) >
( V_2 -> V_343 - 2 ) )
goto V_372;
V_230 = F_111 ( V_2 , V_3 , V_110 ,
V_300 , V_370 ) ;
if ( ( V_230 < 3 ) ||
( V_230 > V_2 -> V_343 ) )
goto V_372;
break;
case V_365 :
default:
F_92 ( V_3 ) ;
V_16 -> V_221 = 0 ;
F_3 ( V_2 , V_10 , V_122 ,
L_35 ,
V_371 ) ;
return 1 ;
}
}
V_226 -> V_58 . V_138 . V_139 . V_134 = ( 2 * sizeof( struct V_109 ) ) ;
V_226 -> V_58 . V_138 . V_139 . V_134 += ( V_230 * sizeof( struct V_109 ) ) ;
V_226 -> V_148 = 1 ;
V_226 -> V_149 = 1 ;
V_368 = F_116 ( V_2 , V_16 ) ;
V_119 -> V_240 = F_102 ( V_368 ) ;
V_226 -> V_58 . V_241 . V_242 = V_368 ;
return 0 ;
V_372:
if ( V_16 -> V_221 )
F_92 ( V_3 ) ;
if ( V_16 -> V_223 )
F_119 ( & V_2 -> V_234 -> V_235 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_233 ) ;
F_3 ( V_2 , V_10 , V_122 ,
L_36
L_37 ,
V_16 -> V_221 , V_16 -> V_223 ,
V_2 -> V_343 , V_2 -> V_236 ,
V_371 , V_230 ) ;
V_16 -> V_221 = 0 ;
V_16 -> V_223 = 0 ;
return 1 ;
}
T_4
F_120 ( V_213 * V_124 , int V_373 )
{
T_4 V_374 = 0 ;
T_4 V_375 ;
V_374 = F_121 ( V_124 , V_373 ) ;
V_375 = F_104 ( V_374 ) ;
return V_375 ;
}
T_4
F_122 ( V_213 * V_124 , int V_373 )
{
T_4 V_290 ;
V_290 = F_123 ( V_124 , V_373 ) ;
return V_290 ;
}
void
F_124 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_7 * V_248 ;
struct V_7 * V_8 ;
struct V_3 * V_26 = V_16 -> V_27 ;
struct V_249 * V_5 = NULL ;
V_213 * V_376 = NULL ;
T_4 V_377 , V_289 ;
T_4 V_378 , V_281 ;
T_1 V_379 , V_266 ;
int V_380 , V_370 ;
int V_381 , V_382 , V_383 ;
int V_384 , V_385 , V_386 ;
T_4 V_387 ;
unsigned V_251 ;
V_381 = V_388 ;
V_387 = 0 ;
V_377 = 0 ;
V_380 = F_100 ( V_26 ) ;
if ( ( V_380 == V_278 ) ||
( V_380 == V_273 ) ||
( V_380 == V_255 ) )
goto V_306;
V_384 = 1 ;
V_385 = 0 ;
V_386 = 0 ;
V_248 = F_7 ( V_26 ) ;
V_370 = V_16 -> V_223 ;
if ( V_248 && V_370 ) {
V_8 = F_2 ( V_26 ) ;
V_251 = F_98 ( V_26 ) ;
V_376 = ( V_213 * ) F_4 ( V_8 ) ;
V_383 = V_8 -> V_13 ;
if ( ( V_383 & ( V_251 - 1 ) ) == 0 )
V_386 = 1 ;
V_289 = F_106 ( V_26 -> V_31 -> V_32 ) ;
V_379 = ( T_1 ) F_101 ( V_26 ) ;
V_378 = V_5 -> V_281 ;
V_5 = (struct V_249 * ) F_4 ( V_248 ) ;
V_382 = V_248 -> V_13 ;
while ( V_5 && V_370 ) {
while ( V_382 ) {
if ( ( V_5 -> V_266 == 0xffffffff ) ||
( V_5 -> V_281 == 0xffff ) ) {
V_379 ++ ;
goto V_389;
}
V_281 = V_5 -> V_281 ;
if ( V_385 && ( V_281 != V_378 ) ) {
V_381 = V_390 ;
goto V_306;
}
V_266 = F_102 ( V_5 -> V_266 ) ;
if ( V_384 && ( V_266 != V_379 ) ) {
V_381 = V_391 ;
goto V_306;
}
V_379 ++ ;
if ( V_386 ) {
V_377 = V_5 -> V_377 ;
if ( V_289 == V_291 )
V_387 = F_122 ( V_376 ,
V_251 ) ;
else
V_387 = F_120 ( V_376 ,
V_251 ) ;
if ( ( V_377 != V_387 ) ) {
V_381 = V_388 ;
goto V_306;
}
}
V_389:
V_382 -= sizeof( struct V_249 ) ;
if ( V_382 < 0 )
V_382 = 0 ;
V_5 ++ ;
V_376 += V_251 ;
V_383 -= V_251 ;
if ( V_386 && ( V_383 == 0 ) ) {
V_386 = 0 ;
V_8 = F_5 ( V_8 ) ;
if ( ! V_8 )
goto V_306;
V_376 = ( V_213 * ) F_4 ( V_8 ) ;
V_383 = V_8 -> V_13 ;
if ( ( V_383 & ( V_251 - 1 ) ) == 0 )
V_386 = 1 ;
}
}
V_248 = F_5 ( V_248 ) ;
if ( V_248 ) {
V_5 = (struct V_249 * ) F_4 ( V_248 ) ;
V_382 = V_248 -> V_13 ;
} else {
V_5 = NULL ;
}
V_370 -- ;
}
}
V_306:
if ( V_381 == V_388 ) {
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x1 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_397 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_38 ,
( unsigned long ) F_101 ( V_26 ) ,
V_387 , V_377 ) ;
} else if ( V_381 == V_391 ) {
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x3 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_399 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_39 ,
( unsigned long ) F_101 ( V_26 ) ,
V_266 , V_379 ) ;
} else if ( V_381 == V_390 ) {
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x2 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_40 ,
( unsigned long ) F_101 ( V_26 ) ,
V_281 , V_378 ) ;
}
}
static int
F_127 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_167 * V_401 )
{
struct V_3 * V_26 = V_16 -> V_27 ;
struct V_402 * V_403 = & V_401 -> V_111 . V_145 . V_404 ;
int V_290 = 0 ;
T_1 V_405 = V_403 -> V_405 ;
T_1 V_406 = V_403 -> V_406 ;
T_6 V_407 = 0 ;
F_56 ( & V_408 ) ;
if ( ! V_409 ) {
F_3 ( V_2 , V_10 , V_11 , L_41
L_42 ,
( V_26 -> V_4 [ 7 ] << 8 | V_26 -> V_4 [ 8 ] ) ) ;
F_1 ( V_2 , V_26 ) ;
if ( F_115 ( V_2 , V_26 ) ==
V_367 ) {
F_3 ( V_2 , V_10 , V_11 , L_43
L_44 ,
( V_26 -> V_4 [ 7 ] << 8 | V_26 -> V_4 [ 8 ] ) ) ;
F_6 ( V_2 , V_26 ) ;
}
V_409 = 1 ;
}
F_58 ( & V_408 ) ;
if ( F_128 ( V_406 ) ) {
V_26 -> V_38 = F_126 ( V_410 , 0 ) ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_45
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
V_290 = ( - 1 ) ;
goto V_306;
}
if ( F_130 ( V_406 ) ) {
V_26 -> V_38 = F_126 ( V_410 , 0 ) ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_48
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
V_290 = ( - 1 ) ;
goto V_306;
}
if ( F_131 ( V_406 ) ) {
V_290 = 1 ;
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x1 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_397 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_49
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_132 ( V_406 ) ) {
V_290 = 1 ;
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x3 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_399 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_50
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_133 ( V_406 ) ) {
V_290 = 1 ;
F_125 ( 1 , V_26 -> V_392 , V_393 ,
0x10 , 0x2 ) ;
V_26 -> V_38 = V_394 << 24
| F_126 ( V_395 , V_396 ) ;
V_2 -> V_400 ++ ;
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_51
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
}
if ( F_134 ( V_406 ) ) {
V_26 -> V_392 [ 7 ] = 0xc ;
V_26 -> V_392 [ 8 ] = 0 ;
V_26 -> V_392 [ 9 ] = 0xa ;
V_26 -> V_392 [ 10 ] = 0x80 ;
switch ( F_100 ( V_26 ) ) {
case V_277 :
case V_274 :
V_405 /= V_26 -> V_31 -> V_244 ;
break;
case V_278 :
case V_273 :
case V_279 :
case V_265 :
V_405 /= ( V_26 -> V_31 -> V_244 +
sizeof( struct V_249 ) ) ;
break;
}
V_407 = F_101 ( V_26 ) ;
V_407 += V_405 ;
F_135 ( V_407 , & V_26 -> V_392 [ 12 ] ) ;
}
if ( ! V_290 ) {
F_3 ( V_2 , V_398 , V_122 | V_11 ,
L_52
L_46
L_47 , V_26 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_26 ) ,
F_129 ( V_26 -> V_411 ) , V_406 , V_405 ) ;
F_124 ( V_2 , V_16 ) ;
}
V_306:
return V_290 ;
}
static int
F_136 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_7 * V_225 = NULL ;
struct V_119 * V_119 = V_16 -> V_119 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 -> V_19 ;
struct V_17 * V_412 ;
T_2 * V_226 = & V_16 -> V_127 . V_111 ;
T_3 V_229 ;
T_1 V_230 = 0 ;
T_1 V_349 ;
T_1 V_350 = 0 ;
int V_231 ;
struct V_109 * V_413 ;
if ( F_89 ( V_3 ) ) {
V_231 = F_137 ( V_3 ) ;
if ( F_91 ( ! V_231 ) )
return 1 ;
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 += 1 ;
V_412 = V_18 ;
V_16 -> V_221 = V_231 ;
if ( V_16 -> V_221 > V_2 -> V_236 ) {
F_3 ( V_2 , V_10 , V_11 , L_53
L_54
L_10 ,
V_12 , V_2 -> V_236 ,
V_16 -> V_221 ) ;
V_16 -> V_221 = 0 ;
F_92 ( V_3 ) ;
return 1 ;
}
F_93 (scsi_cmnd, sgel, nseg, num_bde) {
V_229 = F_94 ( V_225 ) ;
V_349 = F_95 ( V_225 ) ;
V_18 -> V_215 = F_11 ( F_52 ( V_229 ) ) ;
V_18 -> V_214 = F_11 ( F_51 ( V_229 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
if ( ( V_230 + 1 ) == V_231 )
F_10 ( V_21 , V_18 , 1 ) ;
else
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_361 , V_18 , V_350 ) ;
F_10 ( V_351 , V_18 , V_362 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_216 = F_11 ( V_349 ) ;
V_350 += V_349 ;
V_18 ++ ;
}
if ( V_2 -> V_142 & V_414 ) {
V_413 = (struct V_109 * )
& ( V_226 -> V_145 . V_415 [ 5 ] ) ;
V_413 -> V_131 = V_412 -> V_215 ;
V_413 -> V_130 = V_412 -> V_214 ;
V_413 -> V_132 . V_133 . V_134 =
F_9 ( V_412 -> V_216 ) ;
V_413 -> V_132 . V_133 . V_135 = V_136 ;
V_413 -> V_132 . V_137 = F_11 ( V_413 -> V_132 . V_137 ) ;
}
} else {
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 1 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
}
V_119 -> V_240 = F_96 ( F_97 ( V_3 ) ) ;
V_226 -> V_58 . V_241 . V_242 = F_97 ( V_3 ) ;
return 0 ;
}
static int
F_138 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_119 * V_119 = V_16 -> V_119 ;
struct V_17 * V_18 = (struct V_17 * ) ( V_16 -> V_19 ) ;
T_2 * V_226 = & V_16 -> V_127 . V_111 ;
T_1 V_348 = 0 ;
int V_300 , V_370 , V_232 = V_3 -> V_233 ;
int V_371 = 0 ;
int V_368 ;
if ( F_89 ( V_3 ) ) {
V_300 = F_90 ( & V_2 -> V_234 -> V_235 ,
F_2 ( V_3 ) ,
F_89 ( V_3 ) , V_232 ) ;
if ( F_91 ( ! V_300 ) )
return 1 ;
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 += 1 ;
V_16 -> V_221 = V_300 ;
if ( V_16 -> V_221 > V_2 -> V_236 )
goto V_372;
V_371 = F_115 ( V_2 , V_3 ) ;
switch ( V_371 ) {
case V_366 :
if ( ( V_16 -> V_221 + 1 ) > V_2 -> V_343 )
goto V_372;
V_348 = F_113 ( V_2 , V_3 , V_18 ,
V_300 ) ;
if ( V_348 < 2 )
goto V_372;
break;
case V_367 :
V_370 = F_90 ( & V_2 -> V_234 -> V_235 ,
F_7 ( V_3 ) ,
F_118 ( V_3 ) , V_232 ) ;
if ( F_91 ( ! V_370 ) ) {
F_92 ( V_3 ) ;
return 1 ;
}
V_16 -> V_223 = V_370 ;
if ( ( V_16 -> V_223 * 3 ) >
( V_2 -> V_343 - 2 ) )
goto V_372;
V_348 = F_114 ( V_2 , V_3 , V_18 ,
V_300 , V_370 ) ;
if ( ( V_348 < 3 ) ||
( V_348 > V_2 -> V_343 ) )
goto V_372;
break;
case V_365 :
default:
F_92 ( V_3 ) ;
V_16 -> V_221 = 0 ;
F_3 ( V_2 , V_10 , V_122 ,
L_55 ,
V_371 ) ;
return 1 ;
}
}
switch ( F_100 ( V_3 ) ) {
case V_274 :
case V_278 :
V_16 -> V_127 . V_128 |= V_416 ;
break;
case V_273 :
case V_277 :
V_16 -> V_127 . V_128 |= V_417 ;
break;
case V_265 :
case V_279 :
V_16 -> V_127 . V_128 |= V_418 ;
break;
}
V_368 = F_116 ( V_2 , V_16 ) ;
V_119 -> V_240 = F_102 ( V_368 ) ;
V_226 -> V_58 . V_241 . V_242 = V_368 ;
return 0 ;
V_372:
if ( V_16 -> V_221 )
F_92 ( V_3 ) ;
if ( V_16 -> V_223 )
F_119 ( & V_2 -> V_234 -> V_235 , F_7 ( V_3 ) ,
F_118 ( V_3 ) ,
V_3 -> V_233 ) ;
F_3 ( V_2 , V_10 , V_122 ,
L_56
L_57 ,
V_16 -> V_221 , V_16 -> V_223 ,
V_2 -> V_343 , V_2 -> V_236 ,
V_371 , V_348 ) ;
V_16 -> V_221 = 0 ;
V_16 -> V_223 = 0 ;
return 1 ;
}
static inline int
F_139 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return V_2 -> F_139 ( V_2 , V_16 ) ;
}
static inline int
F_140 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return V_2 -> F_140 ( V_2 , V_16 ) ;
}
static void
F_141 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_15 * V_16 , struct V_167 * V_419 ) {
struct V_3 * V_4 = V_16 -> V_27 ;
struct V_120 * V_420 = V_16 -> V_120 ;
T_1 V_421 = V_420 -> V_422 ;
T_1 V_423 = V_420 -> V_424 ;
T_1 V_242 = V_419 -> V_111 . V_58 . V_241 . V_242 ;
struct V_56 * V_57 = NULL ;
struct V_24 * V_25 = V_16 -> V_23 -> V_25 ;
unsigned long V_28 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return;
if ( ( V_4 -> V_38 == V_425 ) ||
( V_4 -> V_38 == V_426 ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_427 . V_61 =
V_62 ;
V_57 -> V_58 . V_427 . V_63 =
( V_4 -> V_38 == V_425 ) ?
V_428 : V_429 ;
V_57 -> V_58 . V_427 . V_53 = V_4 -> V_31 -> V_53 ;
memcpy ( & V_57 -> V_58 . V_427 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_427 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
} else if ( ( V_421 & V_430 ) && V_420 -> V_431 &&
( ( V_4 -> V_4 [ 0 ] == V_432 ) || ( V_4 -> V_4 [ 0 ] == V_433 ) ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_434 . V_60 . V_61 =
V_62 ;
V_57 -> V_58 . V_434 . V_60 . V_63 =
V_435 ;
V_57 -> V_58 . V_434 . V_60 . V_53 =
V_4 -> V_31 -> V_53 ;
memcpy ( & V_57 -> V_58 . V_434 . V_60 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_434 . V_60 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
V_57 -> V_58 . V_434 . V_436 =
V_4 -> V_392 [ 2 ] & 0xf ;
V_57 -> V_58 . V_434 . V_437 = V_4 -> V_392 [ 12 ] ;
V_57 -> V_58 . V_434 . V_438 = V_4 -> V_392 [ 13 ] ;
} else if ( ( V_4 -> V_233 == V_314 ) &&
V_242 &&
( ( F_102 ( V_420 -> V_439 ) != V_242 ) ||
( ( V_423 == V_440 ) &&
! ( V_421 & ( V_441 | V_442 ) ) ) ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_443 . V_444 . V_61 =
V_445 ;
V_57 -> V_58 . V_443 . V_444 . V_63 =
V_446 ;
memcpy ( & V_57 -> V_58 . V_443 . V_444 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_443 . V_444 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
V_57 -> V_58 . V_443 . V_53 = V_4 -> V_31 -> V_53 ;
V_57 -> V_58 . V_443 . V_447 = V_4 -> V_4 [ 0 ] ;
V_57 -> V_58 . V_443 . V_448 =
V_242 ;
} else
return;
V_57 -> V_34 = V_34 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
F_19 ( & V_57 -> V_72 . V_76 , & V_2 -> V_77 ) ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_20 ( V_2 ) ;
return;
}
static void
F_142 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
if ( V_108 -> V_221 > 0 )
F_92 ( V_108 -> V_27 ) ;
if ( V_108 -> V_223 > 0 )
F_119 ( & V_2 -> V_234 -> V_235 , F_7 ( V_108 -> V_27 ) ,
F_118 ( V_108 -> V_27 ) ,
V_108 -> V_27 -> V_233 ) ;
}
static void
F_143 ( struct V_33 * V_34 , struct V_15 * V_16 ,
struct V_167 * V_419 )
{
struct V_3 * V_4 = V_16 -> V_27 ;
struct V_119 * V_449 = V_16 -> V_119 ;
struct V_120 * V_420 = V_16 -> V_120 ;
T_1 V_242 = V_419 -> V_111 . V_58 . V_241 . V_242 ;
T_1 V_421 = V_420 -> V_422 ;
T_1 V_423 = V_420 -> V_424 ;
T_1 * V_450 ;
T_1 V_451 = V_452 ;
T_1 V_453 = 0 ;
T_1 V_454 = V_122 | V_455 ;
if ( V_449 -> V_456 ) {
V_423 = 0 ;
goto V_306;
}
if ( V_421 & V_457 ) {
V_453 = F_102 ( V_420 -> V_458 ) ;
if ( V_453 != 0 && V_453 != 4 && V_453 != 8 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_58
L_59 ,
V_4 -> V_31 -> V_459 ,
V_4 -> V_31 -> V_53 , V_4 -> V_4 [ 0 ] ,
V_453 ) ;
V_451 = V_410 ;
goto V_306;
}
if ( V_420 -> V_460 != V_461 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_60
L_61
L_62 ,
V_4 -> V_31 -> V_459 ,
V_4 -> V_31 -> V_53 , V_4 -> V_4 [ 0 ] ,
V_420 -> V_460 ) ;
V_451 = V_410 ;
goto V_306;
}
}
if ( ( V_421 & V_430 ) && V_420 -> V_431 ) {
T_1 V_462 = F_102 ( V_420 -> V_431 ) ;
if ( V_462 > V_463 )
V_462 = V_463 ;
if ( V_421 & V_457 )
V_453 = F_102 ( V_420 -> V_458 ) ;
memcpy ( V_4 -> V_392 , & V_420 -> V_464 + V_453 , V_462 ) ;
}
V_450 = ( T_1 * ) V_4 -> V_392 ;
if ( ! V_423 && ( V_421 & V_441 ) ) {
if ( V_34 -> V_465 & V_122 )
V_454 = V_455 ;
if ( V_34 -> V_465 & V_466 )
V_454 = V_466 ;
}
F_45 ( V_34 , V_398 , V_454 ,
L_63
L_64 ,
V_4 -> V_4 [ 0 ] , V_423 ,
F_102 ( * V_450 ) , F_102 ( * ( V_450 + 3 ) ) , V_421 ,
F_102 ( V_420 -> V_439 ) ,
F_102 ( V_420 -> V_431 ) ,
F_102 ( V_420 -> V_458 ) ,
V_420 -> V_460 ) ;
F_144 ( V_4 , 0 ) ;
if ( V_421 & V_441 ) {
F_144 ( V_4 , F_102 ( V_420 -> V_439 ) ) ;
F_45 ( V_34 , V_121 , V_466 ,
L_65
L_66 ,
F_102 ( V_449 -> V_240 ) ,
F_145 ( V_4 ) , V_242 , V_4 -> V_4 [ 0 ] ,
V_4 -> V_467 ) ;
if ( ( V_4 -> V_233 == V_314 ) &&
V_242 &&
( F_145 ( V_4 ) != V_242 ) ) {
F_45 ( V_34 , V_398 ,
V_122 | V_455 ,
L_67
L_68 ,
F_102 ( V_449 -> V_240 ) ,
F_145 ( V_4 ) , V_242 ,
V_4 -> V_4 [ 0 ] ) ;
F_144 ( V_4 , F_97 ( V_4 ) ) ;
V_451 = V_410 ;
}
if ( ! ( V_421 & V_430 ) &&
( V_423 == V_440 ) &&
( F_97 ( V_4 ) - F_145 ( V_4 )
< V_4 -> V_467 ) ) {
F_45 ( V_34 , V_121 , V_122 ,
L_69
L_70
L_71 ,
V_4 -> V_4 [ 0 ] , F_97 ( V_4 ) ,
F_145 ( V_4 ) , V_4 -> V_467 ) ;
V_451 = V_410 ;
}
} else if ( V_421 & V_442 ) {
F_45 ( V_34 , V_398 , V_122 ,
L_72
L_73 , V_4 -> V_4 [ 0 ] ,
F_97 ( V_4 ) , F_145 ( V_4 ) ) ;
V_451 = V_410 ;
} else if ( V_242 ) {
F_45 ( V_34 , V_398 , V_122 | V_455 ,
L_74
L_75 ,
F_102 ( V_449 -> V_240 ) ,
F_102 ( V_420 -> V_439 ) ,
V_242 , V_4 -> V_4 [ 0 ] , V_423 ) ;
switch ( V_423 ) {
case V_440 :
case V_396 :
V_451 = V_410 ;
break;
}
F_144 ( V_4 , F_97 ( V_4 ) ) ;
}
V_306:
V_4 -> V_38 = F_126 ( V_451 , V_423 ) ;
F_141 ( V_34 -> V_2 , V_34 , V_16 , V_419 ) ;
}
static void
F_146 ( struct V_1 * V_2 , struct V_167 * V_468 ,
struct V_167 * V_401 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_468 -> V_156 ;
struct V_33 * V_34 = V_468 -> V_34 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_3 * V_26 ;
int V_38 ;
struct V_78 * V_469 ;
int V_470 ;
unsigned long V_28 ;
struct V_56 * V_57 ;
struct V_29 * V_30 ;
T_1 V_84 , V_471 ;
T_1 V_454 = V_122 ;
if ( ! ( V_16 -> V_27 ) )
return;
V_26 = V_16 -> V_27 ;
V_30 = V_26 -> V_31 -> V_32 ;
V_16 -> V_38 = ( V_401 -> V_111 . V_58 . V_472 [ 4 ] & V_473 ) ;
V_16 -> V_154 = V_401 -> V_111 . V_474 ;
V_16 -> V_177 = V_401 -> V_128 & V_475 ;
#ifdef F_109
if ( V_16 -> V_267 ) {
struct V_249 * V_5 = NULL ;
V_5 = (struct V_249 * ) V_16 -> V_269 ;
switch ( V_16 -> V_267 ) {
case V_268 :
V_5 -> V_266 =
V_16 -> V_270 ;
break;
case V_282 :
V_5 -> V_281 =
( T_4 ) V_16 -> V_270 ;
break;
case V_476 :
V_5 -> V_377 =
( T_4 ) V_16 -> V_270 ;
break;
default:
break;
}
V_16 -> V_270 = 0 ;
V_16 -> V_267 = 0 ;
V_16 -> V_269 = NULL ;
}
#endif
if ( V_25 && F_18 ( V_25 ) )
F_147 ( & V_25 -> V_477 ) ;
if ( V_16 -> V_154 ) {
if ( V_16 -> V_154 == V_478 &&
( V_16 -> V_38 & V_479 ) )
V_16 -> V_154 = V_480 ;
else if ( V_16 -> V_154 >= V_481 )
V_16 -> V_154 = V_482 ;
if ( V_16 -> V_154 == V_483 &&
! V_16 -> V_120 -> V_424 &&
( V_16 -> V_120 -> V_422 & V_441 ) &&
! ( V_34 -> V_465 & V_466 ) )
V_454 = 0 ;
else
V_454 = V_122 | V_466 ;
F_45 ( V_34 , V_398 , V_454 ,
L_76
L_77
L_78
L_73 ,
V_26 -> V_4 [ 0 ] ,
V_26 -> V_31 ? V_26 -> V_31 -> V_459 : 0xffff ,
V_26 -> V_31 ? V_26 -> V_31 -> V_53 : 0xffff ,
V_16 -> V_154 , V_16 -> V_38 ,
V_34 -> V_484 , V_25 -> V_259 ,
V_2 -> V_141 == V_485 ?
V_16 -> V_127 . V_175 : 0xffff ,
V_401 -> V_111 . V_486 ,
V_16 -> V_127 . V_111 . V_487 ) ;
switch ( V_16 -> V_154 ) {
case V_483 :
F_143 ( V_34 , V_16 , V_401 ) ;
break;
case V_488 :
case V_489 :
V_26 -> V_38 = F_126 ( V_490 , 0 ) ;
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
break;
V_57 -> V_58 . V_491 . V_61 =
V_445 ;
V_57 -> V_58 . V_491 . V_63 =
( V_16 -> V_154 == V_488 ) ?
V_492 : V_493 ;
if ( V_25 && F_18 ( V_25 ) ) {
memcpy ( & V_57 -> V_58 . V_491 . V_65 ,
& V_25 -> V_66 ,
sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_491 . V_68 ,
& V_25 -> V_69 ,
sizeof( struct V_67 ) ) ;
}
V_57 -> V_34 = V_34 ;
V_57 -> V_72 . V_73 =
V_74 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
F_19 ( & V_57 -> V_72 . V_76 ,
& V_2 -> V_77 ) ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_20 ( V_2 ) ;
break;
case V_478 :
case V_494 :
if ( V_16 -> V_38 == V_495 ||
V_16 -> V_38 ==
V_496 ||
V_16 -> V_38 == V_497 ||
V_16 -> V_38 ==
V_498 ) {
V_26 -> V_38 = F_126 ( V_499 , 0 ) ;
break;
}
if ( V_16 -> V_38 == V_500 ||
V_16 -> V_38 == V_501 ||
V_16 -> V_38 == V_502 ||
V_16 -> V_38 == V_503 ) {
V_26 -> V_38 = F_126 ( V_504 , 0 ) ;
break;
}
if ( ( V_16 -> V_38 == V_505 ||
V_16 -> V_38 == V_506 ) &&
V_401 -> V_111 . V_145 . V_404 . V_406 ) {
if ( F_100 ( V_26 ) != V_255 ) {
F_127 ( V_2 , V_16 ,
V_401 ) ;
break;
} else {
F_45 ( V_34 , V_398 ,
V_11 ,
L_79
L_80 ) ;
}
}
if ( ( V_16 -> V_154 == V_494 )
&& ( V_2 -> V_141 == V_485 )
&& ( V_25 && F_18 ( V_25 ) ) ) {
F_63 ( V_2 , V_25 ,
V_16 -> V_127 . V_179 ,
0 , 0 ) ;
}
default:
V_26 -> V_38 = F_126 ( V_410 , 0 ) ;
break;
}
if ( ! V_25 || ! F_18 ( V_25 )
|| ( V_25 -> V_507 != V_508 ) )
V_26 -> V_38 = F_126 ( V_490 ,
V_426 ) ;
} else
V_26 -> V_38 = F_126 ( V_452 , 0 ) ;
if ( V_26 -> V_38 || V_16 -> V_120 -> V_431 ) {
T_1 * V_450 = ( T_1 * ) V_26 -> V_392 ;
F_45 ( V_34 , V_121 , V_122 ,
L_81
L_82 ,
V_26 -> V_31 -> V_459 , V_26 -> V_31 -> V_53 , V_26 ,
V_26 -> V_38 , * V_450 , * ( V_450 + 3 ) , V_26 -> V_509 ,
F_145 ( V_26 ) ) ;
}
F_12 ( V_2 , V_16 ) ;
V_38 = V_26 -> V_38 ;
if ( V_34 -> V_510 &&
F_148 ( V_39 , V_16 -> V_40 +
F_149 ( V_34 -> V_510 ) ) ) {
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_25 && F_18 ( V_25 ) ) {
if ( V_25 -> V_511 >
F_33 ( & V_25 -> V_477 ) &&
( F_33 ( & V_25 -> V_477 ) >
V_512 ) &&
( ( V_26 -> V_4 [ 0 ] == V_432 ) ||
( V_26 -> V_4 [ 0 ] == V_433 ) ) )
V_25 -> V_511 =
F_33 ( & V_25 -> V_477 ) ;
V_25 -> V_513 = V_39 ;
}
F_15 ( V_30 -> V_41 , V_28 ) ;
} else if ( V_25 && F_18 ( V_25 ) ) {
if ( ( V_25 -> V_511 < V_34 -> V_514 ) &&
F_148 ( V_39 , V_25 -> V_513 +
F_149 ( V_515 ) ) ) {
F_14 ( V_30 -> V_41 , V_28 ) ;
V_470 = V_25 -> V_511 * V_516
/ 100 ;
V_470 = V_470 ? V_470 : 1 ;
V_25 -> V_511 += V_470 ;
if ( V_25 -> V_511 > V_34 -> V_514 )
V_25 -> V_511 = V_34 -> V_514 ;
V_25 -> V_513 = V_39 ;
F_15 ( V_30 -> V_41 , V_28 ) ;
}
}
F_142 ( V_2 , V_16 ) ;
V_84 = V_26 -> V_31 -> V_84 ;
V_471 = V_26 -> V_31 -> V_459 ;
V_26 -> V_517 ( V_26 ) ;
if ( V_2 -> V_518 & V_519 ) {
F_14 ( & V_2 -> V_75 , V_28 ) ;
V_16 -> V_27 = NULL ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_16 -> V_520 )
F_150 ( V_16 -> V_520 ) ;
F_15 ( V_30 -> V_41 , V_28 ) ;
F_87 ( V_2 , V_16 ) ;
return;
}
if ( ! V_38 )
F_30 ( V_34 , V_84 ) ;
if ( V_38 == V_425 && V_25 &&
F_18 ( V_25 ) ) {
F_36 (tmp_sdev, shost) {
if ( V_469 -> V_459 != V_471 )
continue;
V_470 = F_151 ( V_469 ,
V_469 -> V_84 - 1 ) ;
if ( V_470 <= 0 )
continue;
F_45 ( V_34 , V_398 , V_122 ,
L_83
L_84 , V_470 ) ;
F_16 ( V_2 , V_34 ,
V_25 ,
V_469 -> V_53 ,
V_470 + 1 , V_470 ) ;
}
}
F_14 ( & V_2 -> V_75 , V_28 ) ;
V_16 -> V_27 = NULL ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_16 -> V_520 )
F_150 ( V_16 -> V_520 ) ;
F_15 ( V_30 -> V_41 , V_28 ) ;
F_87 ( V_2 , V_16 ) ;
}
static void
F_152 ( V_213 * V_124 , struct V_119 * V_119 )
{
int V_37 , V_521 ;
for ( V_37 = 0 , V_521 = 0 ; V_37 < sizeof( struct V_119 ) ;
V_37 += sizeof( T_1 ) , V_521 ++ ) {
( ( T_1 * ) V_124 ) [ V_521 ] = F_96 ( ( ( T_1 * ) V_119 ) [ V_521 ] ) ;
}
}
static void
F_153 ( struct V_33 * V_34 , struct V_15 * V_16 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_119 * V_119 = V_16 -> V_119 ;
T_2 * V_226 = & V_16 -> V_127 . V_111 ;
struct V_167 * V_522 = & ( V_16 -> V_127 ) ;
int V_232 = V_3 -> V_233 ;
char V_523 [ 2 ] ;
V_213 * V_524 ;
bool V_525 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return;
V_16 -> V_120 -> V_431 = 0 ;
V_16 -> V_119 -> V_456 = 0 ;
F_154 ( V_16 -> V_27 -> V_31 -> V_53 ,
& V_16 -> V_119 -> V_526 ) ;
V_524 = & V_119 -> V_527 [ 0 ] ;
memcpy ( V_524 , V_3 -> V_4 , V_3 -> V_528 ) ;
if ( V_3 -> V_528 < V_529 ) {
V_524 += V_3 -> V_528 ;
memset ( V_524 , 0 , ( V_529 - V_3 -> V_528 ) ) ;
}
if ( F_155 ( V_3 , V_523 ) ) {
switch ( V_523 [ 0 ] ) {
case V_530 :
V_119 -> V_531 = V_532 ;
break;
case V_533 :
V_119 -> V_531 = V_534 ;
break;
default:
V_119 -> V_531 = V_535 ;
break;
}
} else
V_119 -> V_531 = V_535 ;
V_525 = ( V_2 -> V_141 == V_485 ) ;
if ( F_89 ( V_3 ) ) {
if ( V_232 == V_323 ) {
V_226 -> V_536 = V_537 ;
if ( V_525 )
V_226 -> V_538 = V_539 ;
else {
V_226 -> V_58 . V_241 . V_242 = 0 ;
V_226 -> V_538 = 0 ;
}
V_119 -> V_540 = V_541 ;
V_2 -> V_542 ++ ;
} else {
V_226 -> V_536 = V_543 ;
V_226 -> V_538 = V_539 ;
V_119 -> V_540 = V_544 ;
V_2 -> V_545 ++ ;
}
} else {
V_226 -> V_536 = V_546 ;
V_226 -> V_58 . V_241 . V_242 = 0 ;
V_226 -> V_538 = 0 ;
V_119 -> V_540 = 0 ;
V_2 -> V_547 ++ ;
}
if ( V_2 -> V_141 == 3 &&
! ( V_2 -> V_142 & V_143 ) )
F_152 ( V_226 -> V_145 . V_146 . V_147 , V_119 ) ;
V_522 -> V_111 . V_486 = V_25 -> V_548 ;
if ( V_525 )
V_522 -> V_111 . V_486 =
V_2 -> V_159 . V_549 [ V_25 -> V_548 ] ;
if ( V_25 -> V_550 & V_551 )
V_522 -> V_111 . V_552 = 1 ;
else
V_522 -> V_111 . V_552 = 0 ;
V_522 -> V_111 . V_152 = ( V_25 -> V_550 & 0x0f ) ;
V_522 -> V_156 = V_16 ;
V_522 -> V_553 = F_146 ;
V_522 -> V_111 . V_554 = V_16 -> V_555 ;
V_522 -> V_34 = V_34 ;
}
static int
F_156 ( struct V_33 * V_34 ,
struct V_15 * V_16 ,
unsigned int V_53 ,
V_213 V_556 )
{
struct V_167 * V_522 ;
T_2 * V_557 ;
struct V_119 * V_119 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_52 = V_23 -> V_25 ;
if ( ! V_52 || ! F_18 ( V_52 ) ||
V_52 -> V_507 != V_508 )
return 0 ;
V_522 = & ( V_16 -> V_127 ) ;
V_522 -> V_34 = V_34 ;
V_557 = & V_522 -> V_111 ;
V_119 = V_16 -> V_119 ;
memset ( V_119 , 0 , sizeof( struct V_119 ) ) ;
F_154 ( V_53 , & V_119 -> V_526 ) ;
V_119 -> V_456 = V_556 ;
if ( V_34 -> V_2 -> V_141 == 3 &&
! ( V_34 -> V_2 -> V_142 & V_143 ) )
F_152 ( V_557 -> V_145 . V_146 . V_147 , V_119 ) ;
V_557 -> V_536 = V_546 ;
V_557 -> V_486 = V_52 -> V_548 ;
if ( V_34 -> V_2 -> V_141 == V_485 ) {
V_557 -> V_486 =
V_34 -> V_2 -> V_159 . V_549 [ V_52 -> V_548 ] ;
}
if ( V_52 -> V_550 & V_551 ) {
V_557 -> V_552 = 1 ;
}
V_557 -> V_152 = ( V_52 -> V_550 & 0x0f ) ;
if ( V_16 -> V_555 > 0xff ) {
V_557 -> V_554 = 0 ;
} else
V_557 -> V_554 = V_16 -> V_555 ;
if ( V_34 -> V_2 -> V_141 == V_485 )
F_8 ( V_34 -> V_2 , V_16 ) ;
return 1 ;
}
int
F_157 ( struct V_1 * V_2 , V_213 V_558 )
{
V_2 -> F_142 = F_142 ;
V_2 -> F_153 = F_153 ;
switch ( V_558 ) {
case V_559 :
V_2 -> F_80 = F_44 ;
V_2 -> F_139 = F_88 ;
V_2 -> F_140 = F_117 ;
V_2 -> F_87 = F_54 ;
V_2 -> F_86 = F_81 ;
break;
case V_560 :
V_2 -> F_80 = F_78 ;
V_2 -> F_139 = F_136 ;
V_2 -> F_140 = F_138 ;
V_2 -> F_87 = F_65 ;
V_2 -> F_86 = F_83 ;
break;
default:
F_3 ( V_2 , V_10 , V_561 ,
L_85 ,
V_558 ) ;
return - V_562 ;
break;
}
V_2 -> F_28 = F_28 ;
V_2 -> F_146 = F_146 ;
return 0 ;
}
static void
F_158 ( struct V_1 * V_2 ,
struct V_167 * V_563 ,
struct V_167 * V_564 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_563 -> V_156 ;
if ( V_16 )
F_87 ( V_2 , V_16 ) ;
return;
}
const char *
F_159 ( struct V_29 * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_382 , V_565 = 0 ;
static char V_566 [ 384 ] ;
memset ( V_566 , 0 , 384 ) ;
if ( V_2 && V_2 -> V_234 ) {
strncpy ( V_566 , V_2 -> V_567 , 256 ) ;
V_382 = strlen ( V_566 ) ;
snprintf ( V_566 + V_382 ,
384 - V_382 ,
L_86 ,
V_2 -> V_234 -> V_568 -> V_569 ,
V_2 -> V_234 -> V_570 ,
V_2 -> V_234 -> V_571 ) ;
V_382 = strlen ( V_566 ) ;
if ( V_2 -> V_572 [ 0 ] ) {
snprintf ( V_566 + V_382 ,
384 - V_382 ,
L_87 ,
V_2 -> V_572 ) ;
}
V_382 = strlen ( V_566 ) ;
if ( V_2 -> V_141 <= V_573 ) {
V_565 = F_160 ( V_2 ) ;
} else {
if ( V_2 -> V_159 . V_574 . V_575 )
V_565 =
V_2 -> V_159 . V_574 . V_575 ;
else
V_565 = V_2 -> V_159 . V_574 . V_576 ;
}
if ( V_565 != 0 )
snprintf ( V_566 + V_382 , 384 - V_382 ,
L_88 , V_565 ) ;
}
return V_566 ;
}
static T_7 void F_161 ( struct V_1 * V_2 )
{
unsigned long V_577 =
( V_39 + F_149 ( V_2 -> V_578 ) ) ;
if ( ! F_62 ( & V_2 -> V_172 . V_173 [ V_579 ] . V_580 ) )
F_162 ( & V_2 -> V_581 ,
V_577 ) ;
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
& V_2 -> V_172 . V_173 [ V_579 ] , V_582 ) ;
if ( V_2 -> V_518 & V_583 )
F_161 ( V_2 ) ;
}
}
static int
F_166 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_52 ;
struct V_15 * V_16 ;
struct V_105 * V_106 = F_41 ( F_42 ( V_4 -> V_31 ) ) ;
int V_372 ;
V_372 = F_167 ( V_106 ) ;
if ( V_372 ) {
V_4 -> V_38 = V_372 ;
goto V_584;
}
V_52 = V_23 -> V_25 ;
if ( ( F_100 ( V_4 ) != V_255 ) &&
( ! ( V_2 -> V_142 & V_143 ) ) ) {
F_3 ( V_2 , V_10 , V_11 ,
L_89
L_90
L_91 ,
V_4 -> V_4 [ 0 ] , F_100 ( V_4 ) ,
V_585 [ F_100 ( V_4 ) ] ) ;
goto V_584;
}
if ( ! V_52 || ! F_18 ( V_52 ) )
goto V_586;
if ( F_33 ( & V_52 -> V_477 ) >= V_52 -> V_511 )
goto V_586;
V_16 = F_86 ( V_2 , V_52 ) ;
if ( V_16 == NULL ) {
F_28 ( V_2 ) ;
F_45 ( V_34 , V_121 , V_122 ,
L_92
L_93 ) ;
goto V_587;
}
V_16 -> V_27 = V_4 ;
V_16 -> V_23 = V_23 ;
V_16 -> V_555 = 0 ;
V_16 -> V_40 = V_39 ;
V_4 -> V_263 = ( unsigned char * ) V_16 ;
if ( F_100 ( V_4 ) != V_255 ) {
if ( V_34 -> V_2 -> V_588 ) {
F_45 ( V_34 ,
V_121 , V_589 ,
L_94
L_95 ,
V_585 [ F_100 ( V_4 ) ] ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_4 ) ,
F_129 ( V_4 -> V_411 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_372 = F_140 ( V_2 , V_16 ) ;
} else {
if ( V_34 -> V_2 -> V_588 ) {
F_45 ( V_34 ,
V_121 , V_589 ,
L_96
L_97 ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_101 ( V_4 ) ,
F_129 ( V_4 -> V_411 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_372 = F_139 ( V_2 , V_16 ) ;
}
if ( V_372 )
goto V_590;
F_153 ( V_34 , V_16 , V_52 ) ;
F_29 ( & V_52 -> V_477 ) ;
V_372 = F_168 ( V_2 , V_579 ,
& V_16 -> V_127 , V_591 ) ;
if ( V_372 ) {
F_147 ( & V_52 -> V_477 ) ;
goto V_590;
}
if ( V_2 -> V_518 & V_519 ) {
F_165 ( V_2 ,
& V_2 -> V_172 . V_173 [ V_579 ] , V_582 ) ;
if ( V_2 -> V_518 & V_583 )
F_161 ( V_2 ) ;
}
return 0 ;
V_590:
F_142 ( V_2 , V_16 ) ;
F_87 ( V_2 , V_16 ) ;
V_587:
return V_592 ;
V_586:
return V_593 ;
V_584:
V_4 -> V_517 ( V_4 ) ;
return 0 ;
}
static int
F_169 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_167 * V_111 ;
struct V_167 * V_594 ;
struct V_15 * V_16 ;
T_2 * V_26 , * V_595 ;
int V_290 = V_596 , V_154 = 0 ;
unsigned long V_28 ;
F_170 ( V_520 ) ;
V_154 = F_171 ( V_4 ) ;
if ( V_154 != 0 && V_154 != V_596 )
return V_154 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
if ( V_2 -> V_597 & V_598 ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_45 ( V_34 , V_398 , V_122 ,
L_98
L_99 ) ;
return V_599 ;
}
V_16 = (struct V_15 * ) V_4 -> V_263 ;
if ( ! V_16 || ! V_16 -> V_27 ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_45 ( V_34 , V_398 , V_122 ,
L_100
L_101 ,
V_596 , V_4 -> V_31 -> V_459 , V_4 -> V_31 -> V_53 ) ;
return V_596 ;
}
V_111 = & V_16 -> V_127 ;
if ( ! ( V_111 -> V_128 & V_600 ) ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_45 ( V_34 , V_398 , V_122 ,
L_102
L_103 ) ;
return V_599 ;
}
if ( V_16 -> V_27 != V_4 ) {
F_45 ( V_34 , V_398 , V_122 ,
L_104
L_105 ) ;
goto V_601;
}
F_112 ( V_111 -> V_156 != V_16 ) ;
V_594 = F_172 ( V_2 ) ;
if ( V_594 == NULL ) {
V_290 = V_599 ;
goto V_601;
}
V_26 = & V_111 -> V_111 ;
V_595 = & V_594 -> V_111 ;
V_595 -> V_58 . V_602 . V_603 = V_604 ;
V_595 -> V_58 . V_602 . V_605 = V_26 -> V_486 ;
if ( V_2 -> V_141 == V_485 )
V_595 -> V_58 . V_602 . V_606 = V_111 -> V_175 ;
else
V_595 -> V_58 . V_602 . V_606 = V_26 -> V_487 ;
V_595 -> V_149 = 1 ;
V_595 -> V_152 = V_26 -> V_152 ;
V_594 -> V_607 = V_111 -> V_607 ;
V_594 -> V_128 |= V_608 ;
if ( F_173 ( V_2 ) )
V_595 -> V_536 = V_609 ;
else
V_595 -> V_536 = V_610 ;
V_594 -> V_553 = V_611 ;
V_594 -> V_34 = V_34 ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
if ( F_168 ( V_2 , V_579 , V_594 , 0 ) ==
V_612 ) {
F_174 ( V_2 , V_594 ) ;
V_290 = V_599 ;
goto V_306;
}
if ( V_2 -> V_518 & V_583 )
F_165 ( V_2 ,
& V_2 -> V_172 . V_173 [ V_579 ] , V_582 ) ;
V_16 -> V_520 = & V_520 ;
F_175 ( V_520 ,
( V_16 -> V_27 != V_4 ) ,
F_149 ( 2 * V_34 -> V_613 * 1000 ) ) ;
V_16 -> V_520 = NULL ;
if ( V_16 -> V_27 == V_4 ) {
V_290 = V_599 ;
F_45 ( V_34 , V_10 , V_122 ,
L_106
L_107
L_108 ,
V_111 -> V_175 , V_290 ,
V_4 -> V_31 -> V_459 , V_4 -> V_31 -> V_53 ) ;
}
goto V_306;
V_601:
F_15 ( & V_2 -> V_75 , V_28 ) ;
V_306:
F_45 ( V_34 , V_398 , V_122 ,
L_109
L_110 , V_290 , V_4 -> V_31 -> V_459 ,
V_4 -> V_31 -> V_53 ) ;
return V_290 ;
}
static char *
F_176 ( V_213 V_556 )
{
switch ( V_556 ) {
case V_614 :
return L_111 ;
case V_615 :
return L_112 ;
case V_616 :
return L_113 ;
case V_617 :
return L_114 ;
case V_618 :
return L_115 ;
case V_619 :
return L_116 ;
case V_620 :
return L_117 ;
default:
return L_118 ;
}
}
static int
F_177 ( struct V_33 * V_34 , struct V_22 * V_23 ,
unsigned V_621 , unsigned int V_622 ,
V_213 V_556 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_16 ;
struct V_167 * V_168 ;
struct V_167 * V_623 ;
struct V_24 * V_25 = V_23 -> V_25 ;
int V_290 ;
int V_154 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return V_599 ;
V_16 = F_86 ( V_2 , V_23 -> V_25 ) ;
if ( V_16 == NULL )
return V_599 ;
V_16 -> V_555 = 60 ;
V_16 -> V_23 = V_23 ;
V_154 = F_156 ( V_34 , V_16 , V_622 ,
V_556 ) ;
if ( ! V_154 ) {
F_87 ( V_2 , V_16 ) ;
return V_599 ;
}
V_168 = & V_16 -> V_127 ;
V_623 = F_178 ( V_2 ) ;
if ( V_623 == NULL ) {
F_87 ( V_2 , V_16 ) ;
return V_599 ;
}
F_45 ( V_34 , V_121 , V_122 ,
L_119
L_120 ,
F_176 ( V_556 ) , V_621 , V_622 ,
V_25 -> V_548 , V_25 -> V_624 , V_168 -> V_175 ,
V_168 -> V_128 ) ;
V_154 = F_179 ( V_2 , V_579 ,
V_168 , V_623 , V_16 -> V_555 ) ;
if ( V_154 != V_625 ) {
if ( V_154 == V_626 ) {
V_168 -> V_553 = F_158 ;
V_290 = V_627 ;
} else
V_290 = V_599 ;
V_16 -> V_154 = V_480 ;
F_45 ( V_34 , V_10 , V_122 ,
L_121
L_122 ,
F_176 ( V_556 ) ,
V_621 , V_622 , V_623 -> V_111 . V_474 ,
V_623 -> V_111 . V_58 . V_472 [ 4 ] ,
V_168 -> V_128 ) ;
} else if ( V_154 == V_628 )
V_290 = V_599 ;
else
V_290 = V_596 ;
F_174 ( V_2 , V_623 ) ;
if ( V_290 != V_627 )
F_87 ( V_2 , V_16 ) ;
return V_290 ;
}
static int
F_180 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned long V_629 ;
if ( ! V_23 ) {
F_45 ( V_34 , V_121 , V_122 ,
L_123 , V_23 ) ;
return V_599 ;
}
V_25 = V_23 -> V_25 ;
V_629 = F_149 ( 2 * V_34 -> V_613 * 1000 ) + V_39 ;
while ( F_148 ( V_629 , V_39 ) ) {
if ( ! V_25 || ! F_18 ( V_25 ) )
return V_599 ;
if ( V_25 -> V_507 == V_508 )
return V_596 ;
F_181 ( F_149 ( 500 ) ) ;
V_23 = V_4 -> V_31 -> V_35 ;
if ( ! V_23 )
return V_599 ;
V_25 = V_23 -> V_25 ;
}
if ( ! V_25 || ! F_18 ( V_25 ) ||
( V_25 -> V_507 != V_508 ) )
return V_599 ;
return V_596 ;
}
static int
F_182 ( struct V_33 * V_34 , T_4 V_621 ,
T_6 V_622 , T_8 V_630 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_629 ;
int V_631 ;
V_631 = F_183 ( V_34 , V_621 , V_622 , V_630 ) ;
if ( V_631 )
F_184 ( V_34 , & V_2 -> V_172 . V_173 [ V_2 -> V_172 . V_632 ] ,
V_621 , V_622 , V_630 ) ;
V_629 = F_149 ( 2 * V_34 -> V_613 * 1000 ) + V_39 ;
while ( F_148 ( V_629 , V_39 ) && V_631 ) {
F_181 ( F_149 ( 20 ) ) ;
V_631 = F_183 ( V_34 , V_621 , V_622 , V_630 ) ;
}
if ( V_631 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_124 ,
( ( V_630 == V_633 ) ? L_125 :
( ( V_630 == V_634 ) ? L_126 :
( ( V_630 == V_635 ) ? L_127 : L_128 ) ) ) ,
V_631 ) ;
return V_599 ;
}
return V_596 ;
}
static int
F_185 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned V_621 = V_4 -> V_31 -> V_459 ;
unsigned int V_622 = V_4 -> V_31 -> V_53 ;
struct V_636 V_60 ;
int V_154 , V_290 = V_596 ;
if ( ! V_23 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_129 , V_23 ) ;
return V_599 ;
}
V_25 = V_23 -> V_25 ;
V_154 = F_171 ( V_4 ) ;
if ( V_154 != 0 && V_154 != V_596 )
return V_154 ;
V_154 = F_180 ( V_34 , V_4 ) ;
if ( V_154 == V_599 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_130 , V_23 ) ;
return V_599 ;
}
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_637 ;
V_60 . V_53 = V_622 ;
memcpy ( V_60 . V_65 , & V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_25 -> V_69 , sizeof( struct V_67 ) ) ;
F_186 ( V_30 , F_187 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_638 ) ;
V_154 = F_177 ( V_34 , V_23 , V_621 , V_622 ,
V_617 ) ;
F_45 ( V_34 , V_10 , V_122 ,
L_131
L_132 , V_621 , V_622 , V_154 ) ;
V_290 = F_182 ( V_34 , V_621 , V_622 ,
V_633 ) ;
return V_290 ;
}
static int
F_188 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned V_621 = V_4 -> V_31 -> V_459 ;
unsigned int V_622 = V_4 -> V_31 -> V_53 ;
struct V_636 V_60 ;
int V_154 , V_290 = V_596 ;
if ( ! V_23 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_133 , V_23 ) ;
return V_599 ;
}
V_25 = V_23 -> V_25 ;
V_154 = F_171 ( V_4 ) ;
if ( V_154 != 0 && V_154 != V_596 )
return V_154 ;
V_154 = F_180 ( V_34 , V_4 ) ;
if ( V_154 == V_599 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_134 , V_23 ) ;
return V_599 ;
}
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_639 ;
V_60 . V_53 = 0 ;
memcpy ( V_60 . V_65 , & V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_25 -> V_69 , sizeof( struct V_67 ) ) ;
F_186 ( V_30 , F_187 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_638 ) ;
V_154 = F_177 ( V_34 , V_23 , V_621 , V_622 ,
V_618 ) ;
F_45 ( V_34 , V_10 , V_122 ,
L_135
L_132 , V_621 , V_622 , V_154 ) ;
V_290 = F_182 ( V_34 , V_621 , V_622 ,
V_634 ) ;
return V_290 ;
}
static int
F_189 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_24 * V_52 = NULL ;
struct V_636 V_60 ;
int V_640 ;
int V_290 = V_596 , V_154 , V_37 ;
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_641 ;
V_60 . V_53 = 0 ;
memcpy ( V_60 . V_65 , & V_34 -> V_642 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_34 -> V_643 , sizeof( struct V_67 ) ) ;
F_186 ( V_30 , F_187 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_638 ) ;
V_154 = F_171 ( V_4 ) ;
if ( V_154 != 0 && V_154 != V_596 )
return V_154 ;
for ( V_37 = 0 ; V_37 < V_644 ; V_37 ++ ) {
V_640 = 0 ;
F_75 ( V_30 -> V_41 ) ;
F_84 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_18 ( V_52 ) )
continue;
if ( V_34 -> V_2 -> V_645 &&
( V_52 -> V_550 & V_551 ) )
continue;
if ( V_52 -> V_507 == V_508 &&
V_52 -> V_646 == V_37 &&
V_52 -> V_106 ) {
V_640 = 1 ;
break;
}
}
F_77 ( V_30 -> V_41 ) ;
if ( ! V_640 )
continue;
V_154 = F_177 ( V_34 , V_52 -> V_106 -> V_647 ,
V_37 , 0 , V_618 ) ;
if ( V_154 != V_596 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_136 ,
V_37 ) ;
V_290 = V_599 ;
}
}
V_154 = F_182 ( V_34 , 0 , 0 , V_635 ) ;
if ( V_154 != V_596 )
V_290 = V_599 ;
F_45 ( V_34 , V_10 , V_122 ,
L_137 , V_290 ) ;
return V_290 ;
}
static int
F_190 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_203 , V_290 = V_596 ;
F_45 ( V_34 , V_10 , V_122 ,
L_138 ) ;
F_191 ( V_2 , V_648 ) ;
F_192 ( V_2 ) ;
V_203 = F_193 ( V_2 ) ;
if ( V_203 )
V_290 = V_599 ;
V_203 = F_194 ( V_2 ) ;
if ( V_203 )
V_290 = V_599 ;
F_195 ( V_2 ) ;
if ( V_290 == V_599 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_139 ) ;
F_196 ( V_2 ) ;
}
return V_290 ;
}
static int
F_197 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_105 * V_106 = F_41 ( F_42 ( V_79 ) ) ;
T_1 V_649 = 0 ;
T_1 V_107 = 0 ;
int V_650 = 0 ;
T_1 V_651 ;
if ( ! V_106 || F_167 ( V_106 ) )
return - V_652 ;
V_79 -> V_35 = V_106 -> V_647 ;
V_651 = F_198 ( & V_2 -> V_651 ) ;
V_649 = V_2 -> V_653 ;
V_107 = V_34 -> V_97 + 2 ;
if ( ( V_651 * ( V_34 -> V_97 + 2 ) ) < V_649 )
return 0 ;
if ( V_649 >= V_2 -> V_654 - V_655 ) {
F_45 ( V_34 , V_398 , V_122 ,
L_140
L_141 , V_649 ) ;
return 0 ;
} else if ( V_649 + V_107 >
V_2 -> V_654 - V_655 ) {
F_45 ( V_34 , V_398 , V_122 ,
L_142
L_143
L_144 ,
V_107 , V_2 -> V_654 ,
( V_2 -> V_654 - V_649 ) ) ;
V_107 = V_2 -> V_654 - V_649 ;
}
V_650 = F_80 ( V_34 , V_107 ) ;
if ( V_107 != V_650 ) {
F_45 ( V_34 , V_10 , V_122 ,
L_145
L_146
L_147 ,
V_107 , V_650 ) ;
}
if ( V_650 > 0 )
V_2 -> V_653 += V_650 ;
return 0 ;
}
static int
F_199 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
if ( V_79 -> V_86 )
F_26 ( V_79 , V_34 -> V_97 ) ;
else
F_27 ( V_79 , V_34 -> V_97 ) ;
if ( V_2 -> V_518 & V_519 ) {
F_165 ( V_2 ,
& V_2 -> V_172 . V_173 [ V_579 ] , V_582 ) ;
if ( V_2 -> V_518 & V_583 )
F_161 ( V_2 ) ;
}
return 0 ;
}
static void
F_200 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
F_147 ( & V_2 -> V_651 ) ;
V_79 -> V_35 = NULL ;
return;
}
