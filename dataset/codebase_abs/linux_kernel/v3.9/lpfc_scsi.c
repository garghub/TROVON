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
int V_116 ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
V_108 = F_45 ( sizeof( struct V_15 ) , V_117 ) ;
if ( ! V_108 )
break;
V_108 -> V_118 = F_46 ( V_2 -> V_119 ,
V_117 , & V_108 -> V_120 ) ;
if ( ! V_108 -> V_118 ) {
F_47 ( V_108 ) ;
break;
}
memset ( V_108 -> V_118 , 0 , V_2 -> V_121 ) ;
V_115 = F_48 ( V_2 , & V_108 -> V_122 ) ;
if ( V_115 == 0 ) {
F_49 ( V_2 -> V_119 ,
V_108 -> V_118 , V_108 -> V_120 ) ;
F_47 ( V_108 ) ;
break;
}
V_108 -> V_122 . V_123 |= V_124 ;
V_108 -> V_125 = V_108 -> V_118 ;
V_108 -> V_126 = V_108 -> V_118 + sizeof( struct V_125 ) ;
V_108 -> V_19 = V_108 -> V_118 + sizeof( struct V_125 ) +
sizeof( struct V_126 ) ;
V_110 = V_108 -> V_19 ;
V_112 = V_108 -> V_120 ;
V_113 = V_108 -> V_120 + sizeof( struct V_125 ) ;
V_114 = V_108 -> V_120 + sizeof( struct V_125 ) +
sizeof( struct V_126 ) ;
V_110 [ 0 ] . V_127 = F_9 ( F_50 ( V_112 ) ) ;
V_110 [ 0 ] . V_128 = F_9 ( F_51 ( V_112 ) ) ;
V_110 [ 0 ] . V_129 . V_130 . V_131 = sizeof( struct V_125 ) ;
V_110 [ 0 ] . V_129 . V_130 . V_132 = V_133 ;
V_110 [ 0 ] . V_129 . V_134 = F_9 ( V_110 [ 0 ] . V_129 . V_134 ) ;
V_110 [ 1 ] . V_127 = F_9 ( F_50 ( V_113 ) ) ;
V_110 [ 1 ] . V_128 = F_9 ( F_51 ( V_113 ) ) ;
V_110 [ 1 ] . V_129 . V_130 . V_131 = sizeof( struct V_126 ) ;
V_110 [ 1 ] . V_129 . V_130 . V_132 = V_133 ;
V_110 [ 1 ] . V_129 . V_134 = F_9 ( V_110 [ 1 ] . V_129 . V_134 ) ;
V_111 = & V_108 -> V_122 . V_111 ;
V_111 -> V_58 . V_135 . V_136 . V_137 = 0 ;
if ( ( V_2 -> V_138 == 3 ) &&
! ( V_2 -> V_139 & V_140 ) ) {
V_111 -> V_58 . V_135 . V_136 . V_132 = V_141 ;
V_111 -> V_58 . V_135 . V_136 . V_131 = sizeof( struct V_125 ) ;
V_111 -> V_58 . V_135 . V_136 . V_128 = F_52 ( T_2 ,
V_142 . V_143 . V_144 ) ;
V_111 -> V_58 . V_135 . V_136 . V_127 = 0 ;
V_111 -> V_145 = 0 ;
V_111 -> V_146 = 0 ;
V_111 -> V_142 . V_143 . V_147 . V_129 . V_130 . V_132 =
V_133 ;
V_111 -> V_142 . V_143 . V_147 . V_129 . V_130 . V_131 =
sizeof( struct V_126 ) ;
V_111 -> V_142 . V_143 . V_147 . V_128 =
F_51 ( V_113 ) ;
V_111 -> V_142 . V_143 . V_147 . V_127 =
F_50 ( V_113 ) ;
} else {
V_111 -> V_58 . V_135 . V_136 . V_132 = V_148 ;
V_111 -> V_58 . V_135 . V_136 . V_131 =
( 2 * sizeof( struct V_109 ) ) ;
V_111 -> V_58 . V_135 . V_136 . V_128 =
F_51 ( V_114 ) ;
V_111 -> V_58 . V_135 . V_136 . V_127 =
F_50 ( V_114 ) ;
V_111 -> V_145 = 1 ;
V_111 -> V_146 = 1 ;
}
V_111 -> V_149 = V_150 ;
V_108 -> V_151 = V_152 ;
V_108 -> V_122 . V_153 = V_108 ;
F_53 ( V_2 , V_108 ) ;
}
return V_116 ;
}
void
F_54 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_108 , * V_154 ;
unsigned long V_155 = 0 ;
F_14 ( & V_2 -> V_75 , V_155 ) ;
F_55 ( & V_2 -> V_156 . V_157 ) ;
F_56 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_108 -> V_23 && V_108 -> V_23 -> V_25
&& V_108 -> V_23 -> V_25 -> V_34 == V_34 )
V_108 -> V_23 = NULL ;
}
F_57 ( & V_2 -> V_156 . V_157 ) ;
F_15 ( & V_2 -> V_75 , V_155 ) ;
}
void
F_58 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
T_4 V_160 = F_59 ( V_161 , V_159 ) ;
T_4 V_162 = F_59 ( V_163 , V_159 ) ;
struct V_15 * V_108 , * V_154 ;
unsigned long V_155 = 0 ;
struct V_164 * V_165 ;
int V_37 ;
struct V_24 * V_52 ;
int V_166 = 0 ;
struct V_167 * V_168 = & V_2 -> V_169 . V_170 [ V_171 ] ;
F_14 ( & V_2 -> V_75 , V_155 ) ;
F_55 ( & V_2 -> V_156 . V_157 ) ;
F_56 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_108 -> V_122 . V_172 == V_160 ) {
F_60 ( & V_108 -> V_173 ) ;
V_108 -> V_174 = 0 ;
V_108 -> V_151 = V_152 ;
F_57 (
& V_2 -> V_156 . V_157 ) ;
if ( V_108 -> V_23 && V_108 -> V_23 -> V_25 )
V_52 = V_108 -> V_23 -> V_25 ;
else
V_52 = NULL ;
V_166 = F_61 ( & V_2 -> V_175 ) ;
F_15 ( & V_2 -> V_75 , V_155 ) ;
if ( V_52 ) {
F_62 ( V_2 , V_52 ,
V_108 -> V_122 . V_176 , V_162 , 1 ) ;
F_63 ( V_2 , V_52 , V_159 ) ;
}
F_64 ( V_2 , V_108 ) ;
if ( V_166 )
F_20 ( V_2 ) ;
return;
}
}
F_57 ( & V_2 -> V_156 . V_157 ) ;
for ( V_37 = 1 ; V_37 <= V_2 -> V_169 . V_177 ; V_37 ++ ) {
V_165 = V_2 -> V_169 . V_178 [ V_37 ] ;
if ( ! ( V_165 -> V_123 & V_124 ) ||
( V_165 -> V_123 & V_179 ) )
continue;
if ( V_165 -> V_172 != V_160 )
continue;
V_108 = F_65 ( V_165 , struct V_15 , V_122 ) ;
V_108 -> V_174 = 0 ;
F_15 ( & V_2 -> V_75 , V_155 ) ;
if ( V_168 -> V_180 )
F_20 ( V_2 ) ;
return;
}
F_15 ( & V_2 -> V_75 , V_155 ) ;
}
int
F_66 ( struct V_1 * V_2 ,
struct V_181 * V_182 , int V_183 )
{
struct V_15 * V_108 , * V_184 ;
int V_151 ;
int V_185 = 0 , V_186 = 0 , V_187 = 0 , V_188 = 0 ;
T_3 V_189 ;
int V_190 = V_191 ;
F_67 ( V_192 ) ;
F_67 ( V_193 ) ;
F_67 ( V_194 ) ;
if ( V_183 <= 0 )
return - V_195 ;
F_56 (psb, psb_next, post_sblist, list) {
F_68 ( & V_108 -> V_173 ) ;
V_186 ++ ;
if ( ( V_190 != V_191 ) &&
( V_108 -> V_122 . V_172 != V_190 + 1 ) ) {
F_69 ( & V_192 , & V_193 ) ;
V_185 = V_186 - 1 ;
F_19 ( & V_108 -> V_173 , & V_192 ) ;
V_186 = 1 ;
} else {
F_19 ( & V_108 -> V_173 , & V_192 ) ;
if ( V_186 == V_196 ) {
F_69 ( & V_192 , & V_193 ) ;
V_185 = V_186 ;
V_186 = 0 ;
}
}
V_187 ++ ;
V_190 = V_108 -> V_122 . V_172 ;
if ( V_187 == V_183 ) {
if ( V_185 == 0 ) {
F_69 ( & V_192 , & V_193 ) ;
V_185 = V_186 ;
} else if ( V_186 == 1 ) {
if ( V_2 -> V_121 > V_197 )
V_189 = V_108 -> V_198 +
V_197 ;
else
V_189 = 0 ;
V_151 = F_70 ( V_2 ,
V_108 -> V_198 ,
V_189 ,
V_108 -> V_122 . V_172 ) ;
if ( V_151 ) {
V_108 -> V_174 = 1 ;
} else {
V_108 -> V_174 = 0 ;
V_108 -> V_151 = V_152 ;
V_188 ++ ;
}
F_19 ( & V_108 -> V_173 , & V_194 ) ;
}
}
if ( V_185 == 0 )
continue;
V_151 = F_71 ( V_2 , & V_193 ,
V_185 ) ;
if ( V_186 == 0 )
V_190 = V_191 ;
V_185 = 0 ;
while ( ! F_61 ( & V_193 ) ) {
F_72 ( & V_193 , V_108 ,
struct V_15 , V_173 ) ;
if ( V_151 ) {
V_108 -> V_174 = 1 ;
} else {
V_108 -> V_174 = 0 ;
V_108 -> V_151 = V_152 ;
V_188 ++ ;
}
F_19 ( & V_108 -> V_173 , & V_194 ) ;
}
}
while ( ! F_61 ( & V_194 ) ) {
F_72 ( & V_194 , V_108 ,
struct V_15 , V_173 ) ;
F_64 ( V_2 , V_108 ) ;
}
return V_188 ;
}
int
F_73 ( struct V_1 * V_2 )
{
F_67 ( V_182 ) ;
int V_188 , V_199 = 0 ;
F_55 ( & V_2 -> V_200 ) ;
F_69 ( & V_2 -> V_201 , & V_182 ) ;
F_57 ( & V_2 -> V_200 ) ;
if ( ! F_61 ( & V_182 ) ) {
V_188 = F_66 ( V_2 , & V_182 ,
V_2 -> V_156 . V_202 ) ;
if ( V_188 == 0 )
V_199 = - V_203 ;
}
return V_199 ;
}
static int
F_74 ( struct V_33 * V_34 , int V_107 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_108 ;
struct V_17 * V_18 ;
T_2 * V_111 ;
T_3 V_112 ;
T_3 V_113 ;
T_3 V_114 , V_189 ;
T_4 V_115 , V_204 = 0 ;
int V_116 , V_188 ;
F_67 ( V_192 ) ;
F_67 ( V_182 ) ;
F_67 ( V_194 ) ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
V_108 = F_45 ( sizeof( struct V_15 ) , V_117 ) ;
if ( ! V_108 )
break;
V_108 -> V_118 = F_46 ( V_2 -> V_119 ,
V_117 , & V_108 -> V_120 ) ;
if ( ! V_108 -> V_118 ) {
F_47 ( V_108 ) ;
break;
}
memset ( V_108 -> V_118 , 0 , V_2 -> V_121 ) ;
V_115 = F_48 ( V_2 , & V_108 -> V_122 ) ;
if ( V_115 == 0 ) {
F_49 ( V_2 -> V_119 ,
V_108 -> V_118 , V_108 -> V_120 ) ;
F_47 ( V_108 ) ;
break;
}
V_204 = F_75 ( V_2 ) ;
if ( V_204 == V_191 ) {
F_49 ( V_2 -> V_119 ,
V_108 -> V_118 , V_108 -> V_120 ) ;
F_47 ( V_108 ) ;
break;
}
V_108 -> V_122 . V_176 = V_204 ;
V_108 -> V_122 . V_172 = V_2 -> V_156 . V_205 [ V_204 ] ;
V_108 -> V_122 . V_123 |= V_124 ;
V_108 -> V_19 = V_108 -> V_118 ;
V_108 -> V_125 = ( V_108 -> V_118 + V_2 -> V_121 )
- ( sizeof( struct V_125 ) + sizeof( struct V_126 ) ) ;
V_108 -> V_126 = (struct V_126 * ) ( ( V_206 * ) V_108 -> V_125 +
sizeof( struct V_125 ) ) ;
V_18 = (struct V_17 * ) V_108 -> V_19 ;
V_114 = V_108 -> V_120 ;
V_112 =
( V_108 -> V_120 + V_2 -> V_121 )
- ( sizeof( struct V_125 ) + sizeof( struct V_126 ) ) ;
V_113 = V_112 + sizeof( struct V_125 ) ;
V_18 -> V_207 = F_11 ( F_50 ( V_112 ) ) ;
V_18 -> V_208 = F_11 ( F_51 ( V_112 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_209 = F_11 ( sizeof( struct V_125 ) ) ;
V_18 ++ ;
V_18 -> V_207 = F_11 ( F_50 ( V_113 ) ) ;
V_18 -> V_208 = F_11 ( F_51 ( V_113 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 1 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_209 = F_11 ( sizeof( struct V_126 ) ) ;
V_111 = & V_108 -> V_122 . V_111 ;
V_111 -> V_58 . V_135 . V_136 . V_137 = 0 ;
V_111 -> V_58 . V_135 . V_136 . V_132 = V_133 ;
V_111 -> V_58 . V_135 . V_136 . V_131 = sizeof( struct V_125 ) ;
V_111 -> V_58 . V_135 . V_136 . V_128 = F_51 ( V_112 ) ;
V_111 -> V_58 . V_135 . V_136 . V_127 = F_50 ( V_112 ) ;
V_111 -> V_145 = 1 ;
V_111 -> V_146 = 1 ;
V_111 -> V_149 = V_150 ;
V_108 -> V_122 . V_153 = V_108 ;
if ( V_2 -> V_121 > V_197 )
V_189 = V_114 + V_197 ;
else
V_189 = 0 ;
V_108 -> V_198 = V_114 ;
F_19 ( & V_108 -> V_173 , & V_182 ) ;
F_76 ( & V_2 -> V_200 ) ;
V_2 -> V_156 . V_202 ++ ;
F_77 ( & V_2 -> V_200 ) ;
}
F_3 ( V_2 , V_210 , V_11 ,
L_5
L_6 , V_116 , V_107 ) ;
if ( ! F_61 ( & V_182 ) )
V_188 = F_66 ( V_2 ,
& V_182 , V_116 ) ;
else
V_188 = 0 ;
return V_188 ;
}
static inline int
F_78 ( struct V_33 * V_34 , int V_107 )
{
return V_34 -> V_2 -> F_78 ( V_34 , V_107 ) ;
}
static struct V_15 *
F_79 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
struct V_15 * V_16 = NULL ;
struct V_181 * V_211 = & V_2 -> V_201 ;
unsigned long V_155 = 0 ;
F_14 ( & V_2 -> V_200 , V_155 ) ;
F_72 ( V_211 , V_16 , struct V_15 , V_173 ) ;
if ( V_16 ) {
V_16 -> V_212 = 0 ;
V_16 -> V_213 = 0 ;
V_16 -> V_214 = 0 ;
}
F_15 ( & V_2 -> V_200 , V_155 ) ;
return V_16 ;
}
static struct V_15 *
F_80 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
struct V_15 * V_16 ;
unsigned long V_155 = 0 ;
int V_215 = 0 ;
F_14 ( & V_2 -> V_200 , V_155 ) ;
F_81 (lpfc_cmd, &phba->lpfc_scsi_buf_list,
list) {
if ( F_82 ( V_2 , V_52 ,
V_16 -> V_122 . V_176 ) )
continue;
F_60 ( & V_16 -> V_173 ) ;
V_215 = 1 ;
V_16 -> V_212 = 0 ;
V_16 -> V_213 = 0 ;
V_16 -> V_214 = 0 ;
break;
}
F_15 ( & V_2 -> V_200 ,
V_155 ) ;
if ( ! V_215 )
return NULL ;
else
return V_16 ;
}
static struct V_15 *
F_83 ( struct V_1 * V_2 , struct V_24 * V_52 )
{
return V_2 -> F_83 ( V_2 , V_52 ) ;
}
static void
F_53 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
unsigned long V_155 = 0 ;
F_14 ( & V_2 -> V_200 , V_155 ) ;
V_108 -> V_27 = NULL ;
F_19 ( & V_108 -> V_173 , & V_2 -> V_201 ) ;
F_15 ( & V_2 -> V_200 , V_155 ) ;
}
static void
F_64 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
unsigned long V_155 = 0 ;
if ( V_108 -> V_174 ) {
F_14 ( & V_2 -> V_156 . V_157 ,
V_155 ) ;
V_108 -> V_27 = NULL ;
F_19 ( & V_108 -> V_173 ,
& V_2 -> V_156 . V_216 ) ;
F_15 ( & V_2 -> V_156 . V_157 ,
V_155 ) ;
} else {
F_14 ( & V_2 -> V_200 , V_155 ) ;
V_108 -> V_27 = NULL ;
F_19 ( & V_108 -> V_173 , & V_2 -> V_201 ) ;
F_15 ( & V_2 -> V_200 , V_155 ) ;
}
}
static void
F_84 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
V_2 -> F_84 ( V_2 , V_108 ) ;
}
static int
F_85 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_7 * V_217 = NULL ;
struct V_125 * V_125 = V_16 -> V_125 ;
struct V_109 * V_110 = V_16 -> V_19 ;
struct V_164 * V_165 = & V_16 -> V_122 ;
T_2 * V_218 = & V_16 -> V_122 . V_111 ;
struct V_109 * V_219 = V_218 -> V_142 . V_143 . V_220 ;
T_3 V_221 ;
T_1 V_222 = 0 ;
int V_223 , V_224 = V_3 -> V_225 ;
V_110 += 2 ;
if ( F_86 ( V_3 ) ) {
V_223 = F_87 ( & V_2 -> V_226 -> V_227 , F_2 ( V_3 ) ,
F_86 ( V_3 ) , V_224 ) ;
if ( F_88 ( ! V_223 ) )
return 1 ;
V_16 -> V_212 = V_223 ;
if ( V_16 -> V_212 > V_2 -> V_228 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_7
L_8 ,
V_12 , V_2 -> V_228 ,
V_16 -> V_212 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
F_90 (scsi_cmnd, sgel, nseg, num_bde) {
V_221 = F_91 ( V_217 ) ;
if ( V_2 -> V_138 == 3 &&
! ( V_2 -> V_139 & V_140 ) &&
! ( V_165 -> V_123 & V_229 ) &&
V_223 <= V_230 ) {
V_219 -> V_129 . V_130 . V_132 = V_133 ;
V_219 -> V_129 . V_130 . V_131 = F_92 ( V_217 ) ;
V_219 -> V_128 = F_51 ( V_221 ) ;
V_219 -> V_127 = F_50 ( V_221 ) ;
V_219 ++ ;
} else {
V_110 -> V_129 . V_130 . V_132 = V_133 ;
V_110 -> V_129 . V_130 . V_131 = F_92 ( V_217 ) ;
V_110 -> V_129 . V_134 = F_9 ( V_110 -> V_129 . V_134 ) ;
V_110 -> V_128 =
F_9 ( F_51 ( V_221 ) ) ;
V_110 -> V_127 =
F_9 ( F_50 ( V_221 ) ) ;
V_110 ++ ;
}
}
}
if ( V_2 -> V_138 == 3 &&
! ( V_2 -> V_139 & V_140 ) &&
! ( V_165 -> V_123 & V_229 ) ) {
if ( V_222 > V_230 ) {
V_221 = V_16 -> V_120 ;
V_219 -> V_129 . V_130 . V_132 = V_148 ;
V_219 -> V_129 . V_130 . V_131 = ( V_222 *
sizeof( struct V_109 ) ) ;
V_221 += ( sizeof( struct V_125 ) +
sizeof( struct V_126 ) +
( 2 * sizeof( struct V_109 ) ) ) ;
V_219 -> V_127 = F_50 ( V_221 ) ;
V_219 -> V_128 = F_51 ( V_221 ) ;
V_218 -> V_142 . V_143 . V_231 = 2 ;
} else {
V_218 -> V_142 . V_143 . V_231 = ( V_222 + 1 ) ;
}
} else {
V_218 -> V_58 . V_135 . V_136 . V_131 =
( ( V_222 + 2 ) * sizeof( struct V_109 ) ) ;
V_218 -> V_142 . V_143 . V_231 = ( V_222 + 1 ) ;
}
V_125 -> V_232 = F_93 ( F_94 ( V_3 ) ) ;
V_218 -> V_58 . V_233 . V_234 = F_94 ( V_3 ) ;
return 0 ;
}
static inline unsigned
F_95 ( struct V_3 * V_235 )
{
return V_235 -> V_31 -> V_236 ;
}
static int
F_96 ( struct V_1 * V_2 , struct V_3 * V_235 ,
T_1 * V_237 , T_4 * V_238 , T_1 V_239 )
{
struct V_7 * V_240 ;
struct V_7 * V_8 ;
struct V_15 * V_16 = NULL ;
struct V_241 * V_5 = NULL ;
struct V_24 * V_52 ;
struct V_22 * V_23 ;
T_1 V_242 = F_97 ( V_235 ) ;
T_1 V_243 ;
T_1 V_244 ;
T_5 V_245 ;
int V_199 = 0 ;
int V_246 = 0 ;
if ( V_242 == V_247 )
return 0 ;
V_240 = F_7 ( V_235 ) ;
V_8 = F_2 ( V_235 ) ;
V_245 = F_98 ( V_235 ) ;
if ( V_2 -> V_248 != V_249 ) {
V_243 = F_95 ( V_235 ) ;
V_244 = ( F_94 ( V_235 ) + V_243 - 1 ) / V_243 ;
if ( ( V_2 -> V_248 < V_245 ) ||
( V_2 -> V_248 >= ( V_245 + V_244 ) ) )
return 0 ;
if ( V_240 ) {
V_246 = V_2 -> V_248 - V_245 ;
V_244 = F_92 ( V_240 ) /
sizeof( struct V_241 ) ;
if ( V_244 < V_246 )
V_246 = V_244 ;
}
}
V_23 = V_235 -> V_31 -> V_35 ;
if ( V_23 && V_23 -> V_25 ) {
V_52 = V_23 -> V_25 ;
if ( V_2 -> V_250 &&
( V_2 -> V_250 != V_52 -> V_251 ) )
return 0 ;
if ( V_2 -> V_252 . V_253 . V_254 [ 0 ] &&
( memcmp ( & V_52 -> V_66 , & V_2 -> V_252 ,
sizeof( struct V_67 ) ) != 0 ) )
return 0 ;
}
if ( V_240 ) {
V_5 = (struct V_241 * ) F_4 ( V_240 ) ;
V_5 += V_246 ;
V_16 = (struct V_15 * ) V_235 -> V_255 ;
}
if ( V_237 ) {
if ( V_2 -> V_256 ) {
switch ( V_242 ) {
case V_257 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_9
L_10 ,
( unsigned long ) V_245 , V_246 ,
F_99 ( V_5 -> V_258 ) ) ;
if ( V_16 ) {
V_16 -> V_259 =
V_260 ;
V_16 -> V_261 =
V_5 ;
V_16 -> V_262 =
V_5 -> V_258 ;
}
V_5 -> V_258 = F_93 ( 0xDEADBEEF ) ;
V_2 -> V_256 -- ;
if ( V_2 -> V_256 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_263 | V_264 ;
break;
}
case V_265 :
* V_237 = 0xDEADBEEF ;
V_2 -> V_256 -- ;
if ( V_2 -> V_256 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_263 | V_264 ;
F_3 ( V_2 , V_10 , V_11 ,
L_11
L_12 , ( unsigned long ) V_245 ) ;
break;
case V_266 :
* V_237 = 0xDEADBEEF ;
V_2 -> V_256 -- ;
if ( V_2 -> V_256 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 ;
F_3 ( V_2 , V_10 , V_11 ,
L_13
L_12 , ( unsigned long ) V_245 ) ;
break;
}
}
if ( V_2 -> V_268 ) {
switch ( V_242 ) {
case V_269 :
case V_270 :
case V_271 :
* V_237 = 0xDEADBEEF ;
V_2 -> V_268 -- ;
if ( V_2 -> V_268 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 ;
F_3 ( V_2 , V_10 , V_11 ,
L_14
L_15 , ( unsigned long ) V_245 ) ;
break;
}
}
}
if ( V_238 ) {
if ( V_2 -> V_272 ) {
switch ( V_242 ) {
case V_257 :
if ( V_5 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_16
L_17 ,
( unsigned long ) V_245 , V_246 ,
F_100 ( V_5 -> V_273 ) ) ;
if ( V_16 ) {
V_16 -> V_259 =
V_274 ;
V_16 -> V_261 =
V_5 ;
V_16 -> V_262 =
V_5 -> V_273 ;
}
V_5 -> V_273 = F_101 ( 0xDEAD ) ;
V_2 -> V_272 -- ;
if ( V_2 -> V_272 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_263 | V_264 ;
break;
}
case V_265 :
* V_238 = 0xDEAD ;
V_2 -> V_272 -- ;
if ( V_2 -> V_272 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_263 | V_264 ;
F_3 ( V_2 , V_10 , V_11 ,
L_18
L_12 , ( unsigned long ) V_245 ) ;
break;
case V_266 :
* V_238 = 0xDEAD ;
V_2 -> V_272 -- ;
if ( V_2 -> V_272 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 ;
F_3 ( V_2 , V_10 , V_11 ,
L_19
L_12 , ( unsigned long ) V_245 ) ;
break;
}
}
if ( V_2 -> V_275 ) {
switch ( V_242 ) {
case V_269 :
case V_270 :
case V_271 :
* V_238 = 0xDEAD ;
V_2 -> V_275 -- ;
if ( V_2 -> V_275 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 ;
F_3 ( V_2 , V_10 , V_11 ,
L_20
L_15 , ( unsigned long ) V_245 ) ;
break;
}
}
}
if ( V_239 ) {
if ( V_2 -> V_276 ) {
switch ( V_242 ) {
case V_257 :
V_199 = V_264 ;
case V_265 :
V_2 -> V_276 -- ;
if ( V_2 -> V_276 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 |= V_263 | V_277 ;
F_3 ( V_2 , V_10 , V_11 ,
L_21
L_12 , ( unsigned long ) V_245 ) ;
break;
case V_266 :
V_2 -> V_276 -- ;
if ( V_2 -> V_276 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 | V_277 ;
F_3 ( V_2 , V_10 , V_11 ,
L_22
L_12 , ( unsigned long ) V_245 ) ;
break;
}
}
if ( V_2 -> V_278 ) {
switch ( V_242 ) {
case V_269 :
case V_270 :
case V_271 :
V_2 -> V_278 -- ;
if ( V_2 -> V_278 == 0 ) {
V_2 -> V_250 = 0 ;
V_2 -> V_248 =
V_249 ;
memset ( & V_2 -> V_252 ,
0 , sizeof( struct V_67 ) ) ;
}
V_199 = V_267 | V_277 ;
F_3 ( V_2 , V_10 , V_11 ,
L_23
L_15 , ( unsigned long ) V_245 ) ;
}
}
}
return V_199 ;
}
static int
F_102 ( struct V_1 * V_2 , struct V_3 * V_235 ,
V_206 * V_279 , V_206 * V_280 )
{
V_206 V_281 = F_103 ( V_235 -> V_31 -> V_32 ) ;
V_206 V_282 = 0 ;
if ( V_281 == V_283 ) {
switch ( F_97 ( V_235 ) ) {
case V_269 :
case V_266 :
* V_280 = V_284 ;
* V_279 = V_285 ;
break;
case V_270 :
case V_265 :
* V_280 = V_286 ;
* V_279 = V_287 ;
break;
case V_271 :
case V_257 :
* V_280 = V_288 ;
* V_279 = V_289 ;
break;
case V_247 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_24 ,
F_97 ( V_235 ) ) ;
V_282 = 1 ;
break;
}
} else {
switch ( F_97 ( V_235 ) ) {
case V_270 :
case V_265 :
* V_280 = V_286 ;
* V_279 = V_287 ;
break;
case V_271 :
case V_257 :
* V_280 = V_290 ;
* V_279 = V_290 ;
break;
case V_269 :
case V_266 :
* V_280 = V_287 ;
* V_279 = V_286 ;
break;
case V_247 :
default:
F_3 ( V_2 , V_10 , V_11 ,
L_25 ,
F_97 ( V_235 ) ) ;
V_282 = 1 ;
break;
}
}
return V_282 ;
}
static int
F_104 ( struct V_1 * V_2 , struct V_3 * V_235 ,
V_206 * V_279 , V_206 * V_280 )
{
V_206 V_281 = F_103 ( V_235 -> V_31 -> V_32 ) ;
V_206 V_282 = 0 ;
if ( V_281 == V_283 ) {
switch ( F_97 ( V_235 ) ) {
case V_269 :
case V_266 :
* V_280 = V_287 ;
* V_279 = V_286 ;
break;
case V_270 :
case V_265 :
* V_280 = V_285 ;
* V_279 = V_284 ;
break;
case V_271 :
case V_257 :
* V_280 = V_289 ;
* V_279 = V_288 ;
break;
case V_247 :
default:
break;
}
} else {
switch ( F_97 ( V_235 ) ) {
case V_270 :
case V_265 :
* V_280 = V_285 ;
* V_279 = V_284 ;
break;
case V_271 :
case V_257 :
* V_280 = V_291 ;
* V_279 = V_291 ;
break;
case V_269 :
case V_266 :
* V_280 = V_284 ;
* V_279 = V_285 ;
break;
case V_247 :
default:
break;
}
}
return V_282 ;
}
static int
F_105 ( struct V_1 * V_2 , struct V_3 * V_235 ,
struct V_109 * V_110 , int V_292 )
{
struct V_7 * V_8 = NULL ;
struct V_293 * V_294 = NULL ;
struct V_295 * V_296 = NULL ;
T_3 V_221 ;
int V_37 = 0 , V_222 = 0 , V_151 ;
int V_224 = V_235 -> V_225 ;
#ifdef F_106
T_1 V_199 ;
#endif
T_1 V_297 = 1 ;
T_1 V_237 ;
unsigned V_243 ;
V_206 V_279 , V_280 ;
V_151 = F_102 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_151 )
goto V_298;
V_243 = F_95 ( V_235 ) ;
V_237 = ( T_1 ) F_98 ( V_235 ) ;
#ifdef F_106
V_199 = F_96 ( V_2 , V_235 , & V_237 , NULL , 1 ) ;
if ( V_199 ) {
if ( V_199 & V_277 )
F_104 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_199 & V_264 )
V_297 = 0 ;
}
#endif
V_294 = (struct V_293 * ) V_110 ;
memset ( V_294 , 0 , sizeof( struct V_293 ) ) ;
F_10 ( V_299 , V_294 , V_300 ) ;
V_294 -> V_301 = F_11 ( V_294 -> V_301 ) ;
V_294 -> V_237 = F_11 ( V_237 ) ;
V_222 ++ ;
V_110 ++ ;
V_296 = (struct V_295 * ) V_110 ;
memset ( V_296 , 0 , sizeof( struct V_295 ) ) ;
F_10 ( V_302 , V_296 , V_303 ) ;
F_10 ( V_304 , V_296 , V_279 ) ;
F_10 ( V_305 , V_296 , V_280 ) ;
if ( V_224 == V_306 ) {
F_10 ( V_307 , V_296 , V_297 ) ;
F_10 ( V_308 , V_296 , V_297 ) ;
}
F_10 ( V_309 , V_296 , 1 ) ;
F_10 ( V_310 , V_296 , 0 ) ;
F_10 ( V_311 , V_296 , 0 ) ;
V_296 -> V_301 = F_11 ( V_296 -> V_301 ) ;
V_296 -> V_312 = F_11 ( V_296 -> V_312 ) ;
V_296 -> V_20 = F_11 ( V_296 -> V_20 ) ;
V_222 ++ ;
V_110 ++ ;
F_90 (sc, sgde, datasegcnt, i) {
V_221 = F_91 ( V_8 ) ;
V_110 -> V_128 = F_9 ( F_51 ( V_221 ) ) ;
V_110 -> V_127 = F_9 ( F_50 ( V_221 ) ) ;
V_110 -> V_129 . V_130 . V_131 = F_92 ( V_8 ) ;
if ( V_224 == V_313 )
V_110 -> V_129 . V_130 . V_132 = V_133 ;
else
V_110 -> V_129 . V_130 . V_132 = V_314 ;
V_110 -> V_129 . V_134 = F_9 ( V_110 -> V_129 . V_134 ) ;
V_110 ++ ;
V_222 ++ ;
}
V_298:
return V_222 ;
}
static int
F_107 ( struct V_1 * V_2 , struct V_3 * V_235 ,
struct V_109 * V_110 , int V_315 , int V_316 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_240 = NULL ;
struct V_293 * V_294 = NULL ;
struct V_295 * V_296 = NULL ;
struct V_317 * V_318 = NULL ;
T_3 V_319 , V_320 ;
unsigned short V_321 = 0 , V_322 = 0 ;
unsigned int V_323 ;
unsigned int V_324 , V_325 = 0 , V_326 ;
unsigned int V_327 , V_328 ;
unsigned int V_329 , V_330 ;
int V_151 ;
int V_224 = V_235 -> V_225 ;
unsigned char V_331 = 0 , V_332 = 0 ;
unsigned V_243 ;
#ifdef F_106
T_1 V_199 ;
#endif
T_1 V_297 = 1 ;
T_1 V_237 ;
V_206 V_279 , V_280 ;
int V_222 = 0 ;
V_240 = F_7 ( V_235 ) ;
V_8 = F_2 ( V_235 ) ;
if ( ! V_240 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_333 ,
L_26 ,
V_240 , V_8 ) ;
return 0 ;
}
V_151 = F_102 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_151 )
goto V_298;
V_243 = F_95 ( V_235 ) ;
V_237 = ( T_1 ) F_98 ( V_235 ) ;
#ifdef F_106
V_199 = F_96 ( V_2 , V_235 , & V_237 , NULL , 1 ) ;
if ( V_199 ) {
if ( V_199 & V_277 )
F_104 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_199 & V_264 )
V_297 = 0 ;
}
#endif
V_323 = 0 ;
do {
V_294 = (struct V_293 * ) V_110 ;
memset ( V_294 , 0 , sizeof( struct V_293 ) ) ;
F_10 ( V_299 , V_294 , V_300 ) ;
V_294 -> V_301 = F_11 ( V_294 -> V_301 ) ;
V_294 -> V_237 = F_11 ( V_237 ) ;
V_222 ++ ;
V_110 ++ ;
V_296 = (struct V_295 * ) V_110 ;
memset ( V_296 , 0 , sizeof( struct V_295 ) ) ;
F_10 ( V_302 , V_296 , V_303 ) ;
F_10 ( V_304 , V_296 , V_279 ) ;
F_10 ( V_305 , V_296 , V_280 ) ;
F_10 ( V_307 , V_296 , V_297 ) ;
F_10 ( V_308 , V_296 , V_297 ) ;
F_10 ( V_309 , V_296 , 1 ) ;
F_10 ( V_310 , V_296 , 0 ) ;
F_10 ( V_311 , V_296 , 0 ) ;
V_296 -> V_301 = F_11 ( V_296 -> V_301 ) ;
V_296 -> V_312 = F_11 ( V_296 -> V_312 ) ;
V_296 -> V_20 = F_11 ( V_296 -> V_20 ) ;
V_222 ++ ;
V_110 ++ ;
V_320 = F_91 ( V_240 ) + V_325 ;
V_324 = F_92 ( V_240 ) - V_325 ;
F_108 ( V_324 % 8 ) ;
V_318 = (struct V_317 * ) V_110 ;
memset ( V_318 , 0 , sizeof( struct V_317 ) ) ;
F_10 ( V_334 , V_318 , V_335 ) ;
V_318 -> V_127 = F_9 ( F_50 ( V_320 ) ) ;
V_318 -> V_128 = F_9 ( F_51 ( V_320 ) ) ;
V_327 = V_324 / 8 ;
V_328 = V_327 * V_243 ;
if ( ( V_318 -> V_128 & 0xfff ) + V_324 > 0x1000 ) {
V_326 = 0x1000 - ( V_318 -> V_128 & 0xfff ) ;
V_325 += V_326 ;
V_327 = V_326 / 8 ;
V_328 = V_327 * V_243 ;
} else {
V_325 = 0 ;
V_322 ++ ;
}
V_222 ++ ;
V_331 = 0 ;
V_330 = 0 ;
while ( ! V_331 ) {
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_27 ,
V_12 ) ;
return 0 ;
}
V_110 ++ ;
V_319 = F_91 ( V_8 ) + V_323 ;
V_110 -> V_128 = F_9 ( F_51 ( V_319 ) ) ;
V_110 -> V_127 = F_9 ( F_50 ( V_319 ) ) ;
V_329 = F_92 ( V_8 ) - V_323 ;
if ( ( V_330 + V_329 ) <= V_328 ) {
V_110 -> V_129 . V_130 . V_131 = V_329 ;
V_323 = 0 ;
if ( ( V_330 + V_329 ) == V_328 )
V_331 = 1 ;
} else {
V_110 -> V_129 . V_130 . V_131 = V_328 - V_330 ;
V_323 += V_110 -> V_129 . V_130 . V_131 ;
}
V_330 += V_110 -> V_129 . V_130 . V_131 ;
if ( V_224 == V_313 )
V_110 -> V_129 . V_130 . V_132 = V_133 ;
else
V_110 -> V_129 . V_130 . V_132 = V_314 ;
V_110 -> V_129 . V_134 = F_9 ( V_110 -> V_129 . V_134 ) ;
V_222 ++ ;
V_321 ++ ;
if ( V_323 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_325 ) {
V_237 += V_327 ;
V_110 ++ ;
continue;
}
if ( V_322 == V_316 ) {
V_332 = 1 ;
} else if ( V_322 < V_316 ) {
V_240 = F_5 ( V_240 ) ;
V_110 ++ ;
V_237 += V_327 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_28 , V_12 ) ;
}
} while ( ! V_332 );
V_298:
return V_222 ;
}
static int
F_109 ( struct V_1 * V_2 , struct V_3 * V_235 ,
struct V_17 * V_18 , int V_292 )
{
struct V_7 * V_8 = NULL ;
struct V_336 * V_337 = NULL ;
T_3 V_221 ;
int V_37 = 0 , V_338 = 0 , V_151 ;
int V_224 = V_235 -> V_225 ;
T_1 V_237 ;
unsigned V_243 ;
V_206 V_279 , V_280 ;
#ifdef F_106
T_1 V_199 ;
#endif
T_1 V_297 = 1 ;
T_1 V_339 ;
T_1 V_340 = 0 ;
V_151 = F_102 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_151 )
goto V_298;
V_243 = F_95 ( V_235 ) ;
V_237 = ( T_1 ) F_98 ( V_235 ) ;
#ifdef F_106
V_199 = F_96 ( V_2 , V_235 , & V_237 , NULL , 1 ) ;
if ( V_199 ) {
if ( V_199 & V_277 )
F_104 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_199 & V_264 )
V_297 = 0 ;
}
#endif
V_337 = (struct V_336 * ) V_18 ;
memset ( V_337 , 0 , sizeof( struct V_336 ) ) ;
F_10 ( V_341 , V_18 , V_342 ) ;
V_337 -> V_258 = F_11 ( V_237 ) ;
V_337 -> V_343 = V_337 -> V_258 ;
F_10 ( V_344 , V_337 , V_279 ) ;
F_10 ( V_345 , V_337 , V_280 ) ;
if ( V_224 == V_306 ) {
F_10 ( V_346 , V_337 , V_297 ) ;
F_10 ( V_347 , V_337 , V_297 ) ;
}
F_10 ( V_348 , V_337 , 1 ) ;
F_10 ( V_349 , V_337 , 0 ) ;
V_337 -> V_20 = F_11 ( V_337 -> V_20 ) ;
V_337 -> V_350 = F_11 ( V_337 -> V_350 ) ;
V_338 ++ ;
V_18 ++ ;
F_90 (sc, sgde, datasegcnt, i) {
V_221 = F_91 ( V_8 ) ;
V_339 = F_92 ( V_8 ) ;
V_18 -> V_208 = F_11 ( F_51 ( V_221 ) ) ;
V_18 -> V_207 = F_11 ( F_50 ( V_221 ) ) ;
if ( ( V_37 + 1 ) == V_292 )
F_10 ( V_21 , V_18 , 1 ) ;
else
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_351 , V_18 , V_340 ) ;
F_10 ( V_341 , V_18 , V_352 ) ;
V_18 -> V_209 = F_11 ( V_339 ) ;
V_340 += V_339 ;
V_18 ++ ;
V_338 ++ ;
}
V_298:
return V_338 ;
}
static int
F_110 ( struct V_1 * V_2 , struct V_3 * V_235 ,
struct V_17 * V_18 , int V_315 , int V_316 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_240 = NULL ;
struct V_336 * V_337 = NULL ;
T_3 V_319 , V_320 ;
unsigned short V_321 = 0 , V_322 = 0 ;
unsigned int V_323 ;
unsigned int V_324 , V_325 = 0 , V_326 ;
unsigned int V_327 , V_328 ;
unsigned int V_329 , V_330 ;
int V_151 ;
unsigned char V_331 = 0 , V_332 = 0 ;
unsigned V_243 ;
T_1 V_237 ;
V_206 V_279 , V_280 ;
T_1 V_339 ;
#ifdef F_106
T_1 V_199 ;
#endif
T_1 V_297 = 1 ;
T_1 V_340 = 0 ;
int V_338 = 0 ;
V_240 = F_7 ( V_235 ) ;
V_8 = F_2 ( V_235 ) ;
if ( ! V_240 || ! V_8 ) {
F_3 ( V_2 , V_10 , V_333 ,
L_29 ,
V_240 , V_8 ) ;
return 0 ;
}
V_151 = F_102 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_151 )
goto V_298;
V_243 = F_95 ( V_235 ) ;
V_237 = ( T_1 ) F_98 ( V_235 ) ;
#ifdef F_106
V_199 = F_96 ( V_2 , V_235 , & V_237 , NULL , 1 ) ;
if ( V_199 ) {
if ( V_199 & V_277 )
F_104 ( V_2 , V_235 , & V_279 , & V_280 ) ;
if ( V_199 & V_264 )
V_297 = 0 ;
}
#endif
V_323 = 0 ;
do {
V_337 = (struct V_336 * ) V_18 ;
memset ( V_337 , 0 , sizeof( struct V_336 ) ) ;
F_10 ( V_341 , V_18 , V_342 ) ;
V_337 -> V_258 = F_11 ( V_237 ) ;
V_337 -> V_343 = V_337 -> V_258 ;
F_10 ( V_344 , V_337 , V_279 ) ;
F_10 ( V_345 , V_337 , V_280 ) ;
F_10 ( V_346 , V_337 , V_297 ) ;
F_10 ( V_347 , V_337 , V_297 ) ;
F_10 ( V_348 , V_337 , 1 ) ;
F_10 ( V_349 , V_337 , 0 ) ;
V_337 -> V_20 = F_11 ( V_337 -> V_20 ) ;
V_337 -> V_350 = F_11 ( V_337 -> V_350 ) ;
V_338 ++ ;
V_18 ++ ;
V_320 = F_91 ( V_240 ) + V_325 ;
V_324 = F_92 ( V_240 ) - V_325 ;
F_108 ( V_324 % 8 ) ;
V_18 -> V_20 = 0 ;
F_10 ( V_341 , V_18 , V_353 ) ;
V_18 -> V_207 = F_9 ( F_50 ( V_320 ) ) ;
V_18 -> V_208 = F_9 ( F_51 ( V_320 ) ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_327 = V_324 / 8 ;
V_328 = V_327 * V_243 ;
if ( ( V_18 -> V_208 & 0xfff ) + V_324 > 0x1000 ) {
V_326 = 0x1000 - ( V_18 -> V_208 & 0xfff ) ;
V_325 += V_326 ;
V_327 = V_326 / 8 ;
V_328 = V_327 * V_243 ;
} else {
V_325 = 0 ;
V_322 ++ ;
}
V_338 ++ ;
V_331 = 0 ;
V_330 = 0 ;
while ( ! V_331 ) {
if ( ! V_8 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_30 ,
V_12 ) ;
return 0 ;
}
V_18 ++ ;
V_319 = F_91 ( V_8 ) + V_323 ;
V_329 = F_92 ( V_8 ) - V_323 ;
if ( ( V_330 + V_329 ) <= V_328 ) {
V_339 = V_329 ;
V_323 = 0 ;
if ( ( V_330 + V_329 ) == V_328 )
V_331 = 1 ;
} else {
V_339 = V_328 - V_330 ;
V_323 += V_339 ;
}
V_330 += V_339 ;
V_18 -> V_208 = F_11 ( F_51 ( V_319 ) ) ;
V_18 -> V_207 = F_11 ( F_50 ( V_319 ) ) ;
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_351 , V_18 , V_340 ) ;
F_10 ( V_341 , V_18 , V_352 ) ;
V_18 -> V_209 = F_11 ( V_339 ) ;
V_340 += V_339 ;
V_338 ++ ;
V_321 ++ ;
if ( V_323 )
break;
V_8 = F_5 ( V_8 ) ;
}
if ( V_325 ) {
V_237 += V_327 ;
V_18 ++ ;
continue;
}
if ( V_322 == V_316 ) {
F_10 ( V_21 , V_18 , 1 ) ;
V_332 = 1 ;
} else if ( V_322 < V_316 ) {
V_240 = F_5 ( V_240 ) ;
V_18 ++ ;
V_237 += V_327 ;
} else {
F_3 ( V_2 , V_10 , V_11 ,
L_31 , V_12 ) ;
}
} while ( ! V_332 );
V_298:
return V_338 ;
}
static int
F_111 ( struct V_1 * V_2 , struct V_3 * V_235 )
{
int V_282 = V_354 ;
unsigned char V_242 = F_97 ( V_235 ) ;
switch ( V_242 ) {
case V_270 :
case V_265 :
V_282 = V_355 ;
break;
case V_269 :
case V_266 :
case V_271 :
case V_257 :
V_282 = V_356 ;
break;
default:
F_3 ( V_2 , V_10 , V_333 ,
L_32 , V_242 ) ;
break;
}
return V_282 ;
}
static int
F_112 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_125 * V_125 = V_16 -> V_125 ;
struct V_109 * V_110 = V_16 -> V_19 ;
T_2 * V_218 = & V_16 -> V_122 . V_111 ;
T_1 V_222 = 0 ;
int V_292 , V_357 , V_224 = V_3 -> V_225 ;
int V_358 = 0 ;
int V_359 , V_360 ;
unsigned V_243 ;
V_110 += 2 ;
if ( F_86 ( V_3 ) ) {
V_292 = F_87 ( & V_2 -> V_226 -> V_227 ,
F_2 ( V_3 ) ,
F_86 ( V_3 ) , V_224 ) ;
if ( F_88 ( ! V_292 ) )
return 1 ;
V_16 -> V_212 = V_292 ;
if ( V_16 -> V_212 > V_2 -> V_228 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_33
L_34
L_35 ,
V_12 , V_2 -> V_228 ,
V_16 -> V_212 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
V_358 = F_111 ( V_2 , V_3 ) ;
switch ( V_358 ) {
case V_355 :
V_222 = F_105 ( V_2 , V_3 , V_110 ,
V_292 ) ;
if ( V_222 < 2 )
goto V_361;
break;
case V_356 : {
V_357 = F_87 ( & V_2 -> V_226 -> V_227 ,
F_7 ( V_3 ) ,
F_113 ( V_3 ) , V_224 ) ;
if ( F_88 ( ! V_357 ) ) {
F_89 ( V_3 ) ;
return 1 ;
}
V_16 -> V_214 = V_357 ;
if ( V_16 -> V_214
> V_2 -> V_362 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_36
L_37
L_38 , V_12 ,
V_2 -> V_362 ,
V_16 -> V_214 ) ;
F_114 ( & V_2 -> V_226 -> V_227 ,
F_7 ( V_3 ) ,
F_113 ( V_3 ) ,
V_224 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
V_222 = F_107 ( V_2 , V_3 , V_110 ,
V_292 , V_357 ) ;
if ( V_222 < 3 )
goto V_361;
break;
}
case V_354 :
default:
F_3 ( V_2 , V_10 , V_333 ,
L_39 ,
V_358 ) ;
return 1 ;
}
}
V_218 -> V_58 . V_135 . V_136 . V_131 = ( 2 * sizeof( struct V_109 ) ) ;
V_218 -> V_58 . V_135 . V_136 . V_131 += ( V_222 * sizeof( struct V_109 ) ) ;
V_218 -> V_145 = 1 ;
V_218 -> V_146 = 1 ;
V_360 = F_94 ( V_3 ) ;
if ( F_115 ( V_3 ) == V_363 ) {
V_243 = F_95 ( V_3 ) ;
V_359 = ( V_360 / V_243 ) * 8 ;
V_360 += V_359 ;
}
V_125 -> V_232 = F_99 ( V_360 ) ;
V_218 -> V_58 . V_233 . V_234 = V_360 ;
return 0 ;
V_361:
F_3 ( V_2 , V_10 , V_333 ,
L_40
L_41 ,
V_358 , V_222 ) ;
return 1 ;
}
static int
F_116 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_164 * V_364 )
{
struct V_3 * V_26 = V_16 -> V_27 ;
struct V_365 * V_366 = & V_364 -> V_111 . V_142 . V_367 ;
int V_282 = 0 ;
T_1 V_368 = V_366 -> V_368 ;
T_1 V_369 = V_366 -> V_369 ;
T_6 V_370 = 0 ;
F_3 ( V_2 , V_10 , V_11 , L_42
L_43
L_44 ,
V_26 -> V_4 [ 0 ] , ( unsigned long long ) F_98 ( V_26 ) ,
F_117 ( V_26 -> V_371 ) , V_369 , V_368 ) ;
F_55 ( & V_372 ) ;
if ( ! V_373 ) {
F_3 ( V_2 , V_10 , V_11 , L_45
L_46 ,
( V_26 -> V_4 [ 7 ] << 8 | V_26 -> V_4 [ 8 ] ) ) ;
F_1 ( V_2 , V_26 ) ;
if ( F_111 ( V_2 , V_26 ) ==
V_356 ) {
F_3 ( V_2 , V_10 , V_11 , L_47
L_48 ,
( V_26 -> V_4 [ 7 ] << 8 | V_26 -> V_4 [ 8 ] ) ) ;
F_6 ( V_2 , V_26 ) ;
}
V_373 = 1 ;
}
F_57 ( & V_372 ) ;
if ( F_118 ( V_369 ) ) {
V_26 -> V_38 = F_119 ( V_374 , 0 ) ;
F_3 ( V_2 , V_10 , V_11 , L_49
L_50 ,
V_369 ) ;
V_282 = ( - 1 ) ;
goto V_298;
}
if ( F_120 ( V_369 ) ) {
V_26 -> V_38 = F_119 ( V_374 , 0 ) ;
F_3 ( V_2 , V_10 , V_11 , L_51
L_52 ,
V_369 ) ;
V_282 = ( - 1 ) ;
goto V_298;
}
if ( F_121 ( V_369 ) ) {
V_282 = 1 ;
F_122 ( 1 , V_26 -> V_375 , V_376 ,
0x10 , 0x1 ) ;
V_26 -> V_38 = V_377 << 24
| F_119 ( V_378 , V_379 ) ;
V_2 -> V_380 ++ ;
F_3 ( V_2 , V_10 , V_11 ,
L_53 ) ;
}
if ( F_123 ( V_369 ) ) {
V_282 = 1 ;
F_122 ( 1 , V_26 -> V_375 , V_376 ,
0x10 , 0x3 ) ;
V_26 -> V_38 = V_377 << 24
| F_119 ( V_378 , V_379 ) ;
V_2 -> V_381 ++ ;
F_3 ( V_2 , V_10 , V_11 ,
L_54 ) ;
}
if ( F_124 ( V_369 ) ) {
V_282 = 1 ;
F_122 ( 1 , V_26 -> V_375 , V_376 ,
0x10 , 0x2 ) ;
V_26 -> V_38 = V_377 << 24
| F_119 ( V_378 , V_379 ) ;
V_2 -> V_382 ++ ;
F_3 ( V_2 , V_10 , V_11 ,
L_55 ) ;
}
if ( F_125 ( V_369 ) ) {
V_26 -> V_375 [ 7 ] = 0xc ;
V_26 -> V_375 [ 8 ] = 0 ;
V_26 -> V_375 [ 9 ] = 0xa ;
V_26 -> V_375 [ 10 ] = 0x80 ;
switch ( F_97 ( V_26 ) ) {
case V_269 :
case V_266 :
V_368 /= V_26 -> V_31 -> V_236 ;
break;
case V_270 :
case V_265 :
case V_271 :
case V_257 :
V_368 /= ( V_26 -> V_31 -> V_236 +
sizeof( struct V_241 ) ) ;
break;
}
V_370 = F_98 ( V_26 ) ;
V_370 += V_368 ;
F_126 ( V_370 , & V_26 -> V_375 [ 12 ] ) ;
}
if ( ! V_282 ) {
V_26 -> V_38 = F_119 ( V_374 , 0 ) ;
F_3 ( V_2 , V_10 , V_11 ,
L_56 ) ;
}
V_298:
return V_282 ;
}
static int
F_127 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_7 * V_217 = NULL ;
struct V_125 * V_125 = V_16 -> V_125 ;
struct V_17 * V_18 = (struct V_17 * ) V_16 -> V_19 ;
struct V_17 * V_383 ;
T_2 * V_218 = & V_16 -> V_122 . V_111 ;
T_3 V_221 ;
T_1 V_222 = 0 ;
T_1 V_339 ;
T_1 V_340 = 0 ;
int V_223 ;
struct V_109 * V_384 ;
if ( F_86 ( V_3 ) ) {
V_223 = F_128 ( V_3 ) ;
if ( F_88 ( ! V_223 ) )
return 1 ;
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 += 1 ;
V_383 = V_18 ;
V_16 -> V_212 = V_223 ;
if ( V_16 -> V_212 > V_2 -> V_228 ) {
F_3 ( V_2 , V_10 , V_11 , L_57
L_58
L_8 ,
V_12 , V_2 -> V_228 ,
V_16 -> V_212 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
F_90 (scsi_cmnd, sgel, nseg, num_bde) {
V_221 = F_91 ( V_217 ) ;
V_339 = F_92 ( V_217 ) ;
V_18 -> V_208 = F_11 ( F_51 ( V_221 ) ) ;
V_18 -> V_207 = F_11 ( F_50 ( V_221 ) ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
if ( ( V_222 + 1 ) == V_223 )
F_10 ( V_21 , V_18 , 1 ) ;
else
F_10 ( V_21 , V_18 , 0 ) ;
F_10 ( V_351 , V_18 , V_340 ) ;
F_10 ( V_341 , V_18 , V_352 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 -> V_209 = F_11 ( V_339 ) ;
V_340 += V_339 ;
V_18 ++ ;
}
if ( V_2 -> V_139 & V_385 ) {
V_384 = (struct V_109 * )
& ( V_218 -> V_142 . V_386 [ 5 ] ) ;
V_384 -> V_128 = V_383 -> V_208 ;
V_384 -> V_127 = V_383 -> V_207 ;
V_384 -> V_129 . V_130 . V_131 =
F_9 ( V_383 -> V_209 ) ;
V_384 -> V_129 . V_130 . V_132 = V_133 ;
V_384 -> V_129 . V_134 = F_11 ( V_384 -> V_129 . V_134 ) ;
}
} else {
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 1 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
}
V_125 -> V_232 = F_93 ( F_94 ( V_3 ) ) ;
V_218 -> V_58 . V_233 . V_234 = F_94 ( V_3 ) ;
return 0 ;
}
static int
F_129 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_235 = V_16 -> V_27 ;
int V_359 , V_360 ;
unsigned V_243 ;
V_360 = F_94 ( V_235 ) ;
if ( V_235 -> V_225 == V_306 ) {
if ( F_97 ( V_235 ) == V_269 )
return V_360 ;
} else {
if ( F_97 ( V_235 ) == V_266 )
return V_360 ;
}
V_243 = F_95 ( V_235 ) ;
V_359 = ( V_360 / V_243 ) * 8 ;
V_360 += V_359 ;
return V_360 ;
}
static int
F_130 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_125 * V_125 = V_16 -> V_125 ;
struct V_17 * V_18 = (struct V_17 * ) ( V_16 -> V_19 ) ;
T_2 * V_218 = & V_16 -> V_122 . V_111 ;
T_1 V_222 = 0 ;
int V_292 , V_357 , V_224 = V_3 -> V_225 ;
int V_358 = 0 ;
int V_360 ;
if ( F_86 ( V_3 ) ) {
V_292 = F_87 ( & V_2 -> V_226 -> V_227 ,
F_2 ( V_3 ) ,
F_86 ( V_3 ) , V_224 ) ;
if ( F_88 ( ! V_292 ) )
return 1 ;
V_18 += 1 ;
V_18 -> V_20 = F_9 ( V_18 -> V_20 ) ;
F_10 ( V_21 , V_18 , 0 ) ;
V_18 -> V_20 = F_11 ( V_18 -> V_20 ) ;
V_18 += 1 ;
V_16 -> V_212 = V_292 ;
if ( V_16 -> V_212 > V_2 -> V_228 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_59
L_34
L_35 ,
V_12 , V_2 -> V_228 ,
V_16 -> V_212 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
V_358 = F_111 ( V_2 , V_3 ) ;
switch ( V_358 ) {
case V_355 :
V_222 = F_109 ( V_2 , V_3 , V_18 ,
V_292 ) ;
if ( V_222 < 2 )
goto V_361;
break;
case V_356 : {
V_357 = F_87 ( & V_2 -> V_226 -> V_227 ,
F_7 ( V_3 ) ,
F_113 ( V_3 ) , V_224 ) ;
if ( F_88 ( ! V_357 ) ) {
F_89 ( V_3 ) ;
return 1 ;
}
V_16 -> V_214 = V_357 ;
if ( V_16 -> V_214
> V_2 -> V_362 ) {
F_3 ( V_2 , V_10 , V_11 ,
L_60
L_37
L_38 , V_12 ,
V_2 -> V_362 ,
V_16 -> V_214 ) ;
F_114 ( & V_2 -> V_226 -> V_227 ,
F_7 ( V_3 ) ,
F_113 ( V_3 ) ,
V_224 ) ;
F_89 ( V_3 ) ;
return 1 ;
}
V_222 = F_110 ( V_2 , V_3 , V_18 ,
V_292 , V_357 ) ;
if ( V_222 < 3 )
goto V_361;
break;
}
case V_354 :
default:
F_3 ( V_2 , V_10 , V_333 ,
L_61 ,
V_358 ) ;
return 1 ;
}
}
switch ( F_97 ( V_3 ) ) {
case V_266 :
case V_270 :
V_16 -> V_122 . V_123 |= V_387 ;
break;
case V_265 :
case V_269 :
V_16 -> V_122 . V_123 |= V_388 ;
break;
case V_257 :
case V_271 :
V_16 -> V_122 . V_123 |= V_389 ;
break;
}
V_360 = F_129 ( V_2 , V_16 ) ;
V_125 -> V_232 = F_99 ( V_360 ) ;
V_218 -> V_58 . V_233 . V_234 = V_360 ;
return 0 ;
V_361:
F_3 ( V_2 , V_10 , V_333 ,
L_62
L_41 ,
V_358 , V_222 ) ;
return 1 ;
}
static inline int
F_131 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return V_2 -> F_131 ( V_2 , V_16 ) ;
}
static inline int
F_132 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return V_2 -> F_132 ( V_2 , V_16 ) ;
}
static void
F_133 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_15 * V_16 , struct V_164 * V_390 ) {
struct V_3 * V_4 = V_16 -> V_27 ;
struct V_126 * V_391 = V_16 -> V_126 ;
T_1 V_392 = V_391 -> V_393 ;
T_1 V_394 = V_391 -> V_395 ;
T_1 V_234 = V_390 -> V_111 . V_58 . V_233 . V_234 ;
struct V_56 * V_57 = NULL ;
struct V_24 * V_25 = V_16 -> V_23 -> V_25 ;
unsigned long V_28 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return;
if ( ( V_4 -> V_38 == V_396 ) ||
( V_4 -> V_38 == V_397 ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_398 . V_61 =
V_62 ;
V_57 -> V_58 . V_398 . V_63 =
( V_4 -> V_38 == V_396 ) ?
V_399 : V_400 ;
V_57 -> V_58 . V_398 . V_53 = V_4 -> V_31 -> V_53 ;
memcpy ( & V_57 -> V_58 . V_398 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_398 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
} else if ( ( V_392 & V_401 ) && V_391 -> V_402 &&
( ( V_4 -> V_4 [ 0 ] == V_403 ) || ( V_4 -> V_4 [ 0 ] == V_404 ) ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_405 . V_60 . V_61 =
V_62 ;
V_57 -> V_58 . V_405 . V_60 . V_63 =
V_406 ;
V_57 -> V_58 . V_405 . V_60 . V_53 =
V_4 -> V_31 -> V_53 ;
memcpy ( & V_57 -> V_58 . V_405 . V_60 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_405 . V_60 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
V_57 -> V_58 . V_405 . V_407 =
V_4 -> V_375 [ 2 ] & 0xf ;
V_57 -> V_58 . V_405 . V_408 = V_4 -> V_375 [ 12 ] ;
V_57 -> V_58 . V_405 . V_409 = V_4 -> V_375 [ 13 ] ;
} else if ( ( V_4 -> V_225 == V_306 ) &&
V_234 &&
( ( F_99 ( V_391 -> V_410 ) != V_234 ) ||
( ( V_394 == V_411 ) &&
! ( V_392 & ( V_412 | V_413 ) ) ) ) ) {
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
return;
V_57 -> V_58 . V_414 . V_415 . V_61 =
V_416 ;
V_57 -> V_58 . V_414 . V_415 . V_63 =
V_417 ;
memcpy ( & V_57 -> V_58 . V_414 . V_415 . V_65 ,
& V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_414 . V_415 . V_68 ,
& V_25 -> V_69 , sizeof( struct V_67 ) ) ;
V_57 -> V_58 . V_414 . V_53 = V_4 -> V_31 -> V_53 ;
V_57 -> V_58 . V_414 . V_418 = V_4 -> V_4 [ 0 ] ;
V_57 -> V_58 . V_414 . V_419 =
V_234 ;
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
F_134 ( struct V_1 * V_2 , struct V_15 * V_108 )
{
if ( V_108 -> V_212 > 0 )
F_89 ( V_108 -> V_27 ) ;
if ( V_108 -> V_214 > 0 )
F_114 ( & V_2 -> V_226 -> V_227 , F_7 ( V_108 -> V_27 ) ,
F_113 ( V_108 -> V_27 ) ,
V_108 -> V_27 -> V_225 ) ;
}
static void
F_135 ( struct V_33 * V_34 , struct V_15 * V_16 ,
struct V_164 * V_390 )
{
struct V_3 * V_4 = V_16 -> V_27 ;
struct V_125 * V_420 = V_16 -> V_125 ;
struct V_126 * V_391 = V_16 -> V_126 ;
T_1 V_234 = V_390 -> V_111 . V_58 . V_233 . V_234 ;
T_1 V_392 = V_391 -> V_393 ;
T_1 V_394 = V_391 -> V_395 ;
T_1 * V_421 ;
T_1 V_422 = V_423 ;
T_1 V_424 = 0 ;
T_1 V_425 = V_333 | V_426 ;
if ( V_420 -> V_427 ) {
V_394 = 0 ;
goto V_298;
}
if ( V_392 & V_428 ) {
V_424 = F_99 ( V_391 -> V_429 ) ;
if ( V_424 != 0 && V_424 != 4 && V_424 != 8 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_63
L_64 ,
V_4 -> V_31 -> V_430 ,
V_4 -> V_31 -> V_53 , V_4 -> V_4 [ 0 ] ,
V_424 ) ;
V_422 = V_374 ;
goto V_298;
}
if ( V_391 -> V_431 != V_432 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_65
L_66
L_67 ,
V_4 -> V_31 -> V_430 ,
V_4 -> V_31 -> V_53 , V_4 -> V_4 [ 0 ] ,
V_391 -> V_431 ) ;
V_422 = V_374 ;
goto V_298;
}
}
if ( ( V_392 & V_401 ) && V_391 -> V_402 ) {
T_1 V_433 = F_99 ( V_391 -> V_402 ) ;
if ( V_433 > V_434 )
V_433 = V_434 ;
if ( V_392 & V_428 )
V_424 = F_99 ( V_391 -> V_429 ) ;
memcpy ( V_4 -> V_375 , & V_391 -> V_435 + V_424 , V_433 ) ;
}
V_421 = ( T_1 * ) V_4 -> V_375 ;
if ( ! V_394 && ( V_392 & V_412 ) ) {
if ( V_34 -> V_436 & V_333 )
V_425 = V_426 ;
if ( V_34 -> V_436 & V_437 )
V_425 = V_437 ;
}
F_136 ( V_34 , V_438 , V_425 ,
L_68
L_69 ,
V_4 -> V_4 [ 0 ] , V_394 ,
F_99 ( * V_421 ) , F_99 ( * ( V_421 + 3 ) ) , V_392 ,
F_99 ( V_391 -> V_410 ) ,
F_99 ( V_391 -> V_402 ) ,
F_99 ( V_391 -> V_429 ) ,
V_391 -> V_431 ) ;
F_137 ( V_4 , 0 ) ;
if ( V_392 & V_412 ) {
F_137 ( V_4 , F_99 ( V_391 -> V_410 ) ) ;
F_136 ( V_34 , V_210 , V_437 ,
L_70
L_71 ,
F_99 ( V_420 -> V_232 ) ,
F_138 ( V_4 ) , V_234 , V_4 -> V_4 [ 0 ] ,
V_4 -> V_439 ) ;
if ( ( V_4 -> V_225 == V_306 ) &&
V_234 &&
( F_138 ( V_4 ) != V_234 ) ) {
F_136 ( V_34 , V_438 ,
V_333 | V_426 ,
L_72
L_73 ,
F_99 ( V_420 -> V_232 ) ,
F_138 ( V_4 ) , V_234 ,
V_4 -> V_4 [ 0 ] ) ;
F_137 ( V_4 , F_94 ( V_4 ) ) ;
V_422 = V_374 ;
}
if ( ! ( V_392 & V_401 ) &&
( V_394 == V_411 ) &&
( F_94 ( V_4 ) - F_138 ( V_4 )
< V_4 -> V_439 ) ) {
F_136 ( V_34 , V_210 , V_333 ,
L_74
L_75
L_76 ,
V_4 -> V_4 [ 0 ] , F_94 ( V_4 ) ,
F_138 ( V_4 ) , V_4 -> V_439 ) ;
V_422 = V_374 ;
}
} else if ( V_392 & V_413 ) {
F_136 ( V_34 , V_438 , V_333 ,
L_77
L_78 , V_4 -> V_4 [ 0 ] ,
F_94 ( V_4 ) , F_138 ( V_4 ) ) ;
V_422 = V_374 ;
} else if ( V_234 ) {
F_136 ( V_34 , V_438 , V_333 | V_426 ,
L_79
L_80 ,
F_99 ( V_420 -> V_232 ) ,
F_99 ( V_391 -> V_410 ) ,
V_234 , V_4 -> V_4 [ 0 ] , V_394 ) ;
switch ( V_394 ) {
case V_411 :
case V_379 :
V_422 = V_374 ;
break;
}
F_137 ( V_4 , F_94 ( V_4 ) ) ;
}
V_298:
V_4 -> V_38 = F_119 ( V_422 , V_394 ) ;
F_133 ( V_34 -> V_2 , V_34 , V_16 , V_390 ) ;
}
static void
F_139 ( struct V_1 * V_2 , struct V_164 * V_440 ,
struct V_164 * V_364 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_440 -> V_153 ;
struct V_33 * V_34 = V_440 -> V_34 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_3 * V_26 ;
int V_38 ;
struct V_78 * V_441 ;
int V_442 ;
unsigned long V_28 ;
struct V_56 * V_57 ;
struct V_29 * V_30 ;
T_1 V_84 , V_443 ;
T_1 V_425 = V_333 ;
if ( ! ( V_16 -> V_27 ) )
return;
V_26 = V_16 -> V_27 ;
V_30 = V_26 -> V_31 -> V_32 ;
V_16 -> V_38 = ( V_364 -> V_111 . V_58 . V_444 [ 4 ] & V_445 ) ;
V_16 -> V_151 = V_364 -> V_111 . V_446 ;
V_16 -> V_174 = V_364 -> V_123 & V_447 ;
#ifdef F_106
if ( V_16 -> V_259 ) {
struct V_241 * V_5 = NULL ;
V_5 = (struct V_241 * ) V_16 -> V_261 ;
switch ( V_16 -> V_259 ) {
case V_260 :
V_5 -> V_258 =
V_16 -> V_262 ;
break;
case V_274 :
V_5 -> V_273 =
( T_4 ) V_16 -> V_262 ;
break;
case V_448 :
V_5 -> V_449 =
( T_4 ) V_16 -> V_262 ;
break;
default:
break;
}
V_16 -> V_262 = 0 ;
V_16 -> V_259 = 0 ;
V_16 -> V_261 = NULL ;
}
#endif
if ( V_25 && F_18 ( V_25 ) )
F_140 ( & V_25 -> V_450 ) ;
if ( V_16 -> V_151 ) {
if ( V_16 -> V_151 == V_451 &&
( V_16 -> V_38 & V_452 ) )
V_16 -> V_151 = V_453 ;
else if ( V_16 -> V_151 >= V_454 )
V_16 -> V_151 = V_455 ;
if ( V_16 -> V_151 == V_456 &&
! V_16 -> V_126 -> V_395 &&
( V_16 -> V_126 -> V_393 & V_412 ) &&
! ( V_34 -> V_436 & V_437 ) )
V_425 = 0 ;
else
V_425 = V_333 | V_437 ;
F_136 ( V_34 , V_438 , V_425 ,
L_81
L_82
L_83
L_78 ,
V_26 -> V_4 [ 0 ] ,
V_26 -> V_31 ? V_26 -> V_31 -> V_430 : 0xffff ,
V_26 -> V_31 ? V_26 -> V_31 -> V_53 : 0xffff ,
V_16 -> V_151 , V_16 -> V_38 ,
V_34 -> V_457 , V_25 -> V_251 ,
V_2 -> V_138 == V_458 ?
V_16 -> V_122 . V_172 : 0xffff ,
V_364 -> V_111 . V_459 ,
V_16 -> V_122 . V_111 . V_460 ) ;
switch ( V_16 -> V_151 ) {
case V_456 :
F_135 ( V_34 , V_16 , V_364 ) ;
break;
case V_461 :
case V_462 :
V_26 -> V_38 = F_119 ( V_463 , 0 ) ;
V_57 = F_17 ( V_2 ) ;
if ( ! V_57 )
break;
V_57 -> V_58 . V_464 . V_61 =
V_416 ;
V_57 -> V_58 . V_464 . V_63 =
( V_16 -> V_151 == V_461 ) ?
V_465 : V_466 ;
if ( V_25 && F_18 ( V_25 ) ) {
memcpy ( & V_57 -> V_58 . V_464 . V_65 ,
& V_25 -> V_66 ,
sizeof( struct V_67 ) ) ;
memcpy ( & V_57 -> V_58 . V_464 . V_68 ,
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
case V_451 :
case V_467 :
if ( V_16 -> V_38 == V_468 ||
V_16 -> V_38 ==
V_469 ||
V_16 -> V_38 == V_470 ||
V_16 -> V_38 ==
V_471 ) {
V_26 -> V_38 = F_119 ( V_472 , 0 ) ;
break;
}
if ( V_16 -> V_38 == V_473 ||
V_16 -> V_38 == V_474 ||
V_16 -> V_38 == V_475 ||
V_16 -> V_38 == V_476 ) {
V_26 -> V_38 = F_119 ( V_477 , 0 ) ;
break;
}
if ( ( V_16 -> V_38 == V_478 ||
V_16 -> V_38 == V_479 ) &&
V_364 -> V_111 . V_142 . V_367 . V_369 ) {
if ( F_97 ( V_26 ) != V_247 ) {
F_116 ( V_2 , V_16 ,
V_364 ) ;
break;
} else {
F_136 ( V_34 , V_438 ,
V_11 ,
L_84
L_85 ) ;
}
}
if ( ( V_16 -> V_151 == V_467 )
&& ( V_2 -> V_138 == V_458 )
&& ( V_25 && F_18 ( V_25 ) ) ) {
F_62 ( V_2 , V_25 ,
V_16 -> V_122 . V_176 ,
0 , 0 ) ;
}
default:
V_26 -> V_38 = F_119 ( V_374 , 0 ) ;
break;
}
if ( ! V_25 || ! F_18 ( V_25 )
|| ( V_25 -> V_480 != V_481 ) )
V_26 -> V_38 = F_119 ( V_463 ,
V_397 ) ;
} else
V_26 -> V_38 = F_119 ( V_423 , 0 ) ;
if ( V_26 -> V_38 || V_16 -> V_126 -> V_402 ) {
T_1 * V_421 = ( T_1 * ) V_26 -> V_375 ;
F_136 ( V_34 , V_210 , V_333 ,
L_86
L_87 ,
V_26 -> V_31 -> V_430 , V_26 -> V_31 -> V_53 , V_26 ,
V_26 -> V_38 , * V_421 , * ( V_421 + 3 ) , V_26 -> V_482 ,
F_138 ( V_26 ) ) ;
}
F_12 ( V_2 , V_16 ) ;
V_38 = V_26 -> V_38 ;
if ( V_34 -> V_483 &&
F_141 ( V_39 , V_16 -> V_40 +
F_142 ( V_34 -> V_483 ) ) ) {
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_25 && F_18 ( V_25 ) ) {
if ( V_25 -> V_484 >
F_33 ( & V_25 -> V_450 ) &&
( F_33 ( & V_25 -> V_450 ) >
V_485 ) &&
( ( V_26 -> V_4 [ 0 ] == V_403 ) ||
( V_26 -> V_4 [ 0 ] == V_404 ) ) )
V_25 -> V_484 =
F_33 ( & V_25 -> V_450 ) ;
V_25 -> V_486 = V_39 ;
}
F_15 ( V_30 -> V_41 , V_28 ) ;
} else if ( V_25 && F_18 ( V_25 ) ) {
if ( ( V_25 -> V_484 < V_34 -> V_487 ) &&
F_141 ( V_39 , V_25 -> V_486 +
F_142 ( V_488 ) ) ) {
F_14 ( V_30 -> V_41 , V_28 ) ;
V_442 = V_25 -> V_484 * V_489
/ 100 ;
V_442 = V_442 ? V_442 : 1 ;
V_25 -> V_484 += V_442 ;
if ( V_25 -> V_484 > V_34 -> V_487 )
V_25 -> V_484 = V_34 -> V_487 ;
V_25 -> V_486 = V_39 ;
F_15 ( V_30 -> V_41 , V_28 ) ;
}
}
F_134 ( V_2 , V_16 ) ;
V_84 = V_26 -> V_31 -> V_84 ;
V_443 = V_26 -> V_31 -> V_430 ;
V_26 -> V_490 ( V_26 ) ;
if ( V_2 -> V_491 & V_492 ) {
F_14 ( & V_2 -> V_75 , V_28 ) ;
V_16 -> V_27 = NULL ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_16 -> V_493 )
F_143 ( V_16 -> V_493 ) ;
F_15 ( V_30 -> V_41 , V_28 ) ;
F_84 ( V_2 , V_16 ) ;
return;
}
if ( ! V_38 )
F_30 ( V_34 , V_84 ) ;
if ( V_38 == V_396 && V_25 &&
F_18 ( V_25 ) ) {
F_36 (tmp_sdev, shost) {
if ( V_441 -> V_430 != V_443 )
continue;
V_442 = F_144 ( V_441 ,
V_441 -> V_84 - 1 ) ;
if ( V_442 <= 0 )
continue;
F_136 ( V_34 , V_438 , V_333 ,
L_88
L_89 , V_442 ) ;
F_16 ( V_2 , V_34 ,
V_25 ,
V_441 -> V_53 ,
V_442 + 1 , V_442 ) ;
}
}
F_14 ( & V_2 -> V_75 , V_28 ) ;
V_16 -> V_27 = NULL ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_14 ( V_30 -> V_41 , V_28 ) ;
if ( V_16 -> V_493 )
F_143 ( V_16 -> V_493 ) ;
F_15 ( V_30 -> V_41 , V_28 ) ;
F_84 ( V_2 , V_16 ) ;
}
static void
F_145 ( V_206 * V_118 , struct V_125 * V_125 )
{
int V_37 , V_494 ;
for ( V_37 = 0 , V_494 = 0 ; V_37 < sizeof( struct V_125 ) ;
V_37 += sizeof( T_1 ) , V_494 ++ ) {
( ( T_1 * ) V_118 ) [ V_494 ] = F_93 ( ( ( T_1 * ) V_125 ) [ V_494 ] ) ;
}
}
static void
F_146 ( struct V_33 * V_34 , struct V_15 * V_16 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_3 = V_16 -> V_27 ;
struct V_125 * V_125 = V_16 -> V_125 ;
T_2 * V_218 = & V_16 -> V_122 . V_111 ;
struct V_164 * V_495 = & ( V_16 -> V_122 ) ;
int V_224 = V_3 -> V_225 ;
char V_496 [ 2 ] ;
V_206 * V_497 ;
bool V_498 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return;
V_16 -> V_126 -> V_402 = 0 ;
V_16 -> V_125 -> V_427 = 0 ;
F_147 ( V_16 -> V_27 -> V_31 -> V_53 ,
& V_16 -> V_125 -> V_499 ) ;
V_497 = & V_125 -> V_500 [ 0 ] ;
memcpy ( V_497 , V_3 -> V_4 , V_3 -> V_501 ) ;
if ( V_3 -> V_501 < V_502 ) {
V_497 += V_3 -> V_501 ;
memset ( V_497 , 0 , ( V_502 - V_3 -> V_501 ) ) ;
}
if ( F_148 ( V_3 , V_496 ) ) {
switch ( V_496 [ 0 ] ) {
case V_503 :
V_125 -> V_504 = V_505 ;
break;
case V_506 :
V_125 -> V_504 = V_507 ;
break;
default:
V_125 -> V_504 = V_508 ;
break;
}
} else
V_125 -> V_504 = V_508 ;
V_498 = ( V_2 -> V_138 == V_458 ) ;
if ( F_86 ( V_3 ) ) {
if ( V_224 == V_313 ) {
V_218 -> V_509 = V_510 ;
if ( V_498 )
V_218 -> V_511 = V_512 ;
else {
V_218 -> V_58 . V_233 . V_234 = 0 ;
V_218 -> V_511 = 0 ;
}
V_125 -> V_513 = V_514 ;
V_2 -> V_515 ++ ;
} else {
V_218 -> V_509 = V_516 ;
V_218 -> V_511 = V_512 ;
V_125 -> V_513 = V_517 ;
V_2 -> V_518 ++ ;
}
} else {
V_218 -> V_509 = V_519 ;
V_218 -> V_58 . V_233 . V_234 = 0 ;
V_218 -> V_511 = 0 ;
V_125 -> V_513 = 0 ;
V_2 -> V_520 ++ ;
}
if ( V_2 -> V_138 == 3 &&
! ( V_2 -> V_139 & V_140 ) )
F_145 ( V_218 -> V_142 . V_143 . V_144 , V_125 ) ;
V_495 -> V_111 . V_459 = V_25 -> V_521 ;
if ( V_498 )
V_495 -> V_111 . V_459 =
V_2 -> V_156 . V_522 [ V_25 -> V_521 ] ;
if ( V_25 -> V_523 & V_524 )
V_495 -> V_111 . V_525 = 1 ;
else
V_495 -> V_111 . V_525 = 0 ;
V_495 -> V_111 . V_149 = ( V_25 -> V_523 & 0x0f ) ;
V_495 -> V_153 = V_16 ;
V_495 -> V_526 = F_139 ;
V_495 -> V_111 . V_527 = V_16 -> V_528 ;
V_495 -> V_34 = V_34 ;
}
static int
F_149 ( struct V_33 * V_34 ,
struct V_15 * V_16 ,
unsigned int V_53 ,
V_206 V_529 )
{
struct V_164 * V_495 ;
T_2 * V_530 ;
struct V_125 * V_125 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_52 = V_23 -> V_25 ;
if ( ! V_52 || ! F_18 ( V_52 ) ||
V_52 -> V_480 != V_481 )
return 0 ;
V_495 = & ( V_16 -> V_122 ) ;
V_495 -> V_34 = V_34 ;
V_530 = & V_495 -> V_111 ;
V_125 = V_16 -> V_125 ;
memset ( V_125 , 0 , sizeof( struct V_125 ) ) ;
F_147 ( V_53 , & V_125 -> V_499 ) ;
V_125 -> V_427 = V_529 ;
if ( V_34 -> V_2 -> V_138 == 3 &&
! ( V_34 -> V_2 -> V_139 & V_140 ) )
F_145 ( V_530 -> V_142 . V_143 . V_144 , V_125 ) ;
V_530 -> V_509 = V_519 ;
V_530 -> V_459 = V_52 -> V_521 ;
if ( V_34 -> V_2 -> V_138 == V_458 ) {
V_530 -> V_459 =
V_34 -> V_2 -> V_156 . V_522 [ V_52 -> V_521 ] ;
}
if ( V_52 -> V_523 & V_524 ) {
V_530 -> V_525 = 1 ;
}
V_530 -> V_149 = ( V_52 -> V_523 & 0x0f ) ;
if ( V_16 -> V_528 > 0xff ) {
V_530 -> V_527 = 0 ;
} else
V_530 -> V_527 = V_16 -> V_528 ;
if ( V_34 -> V_2 -> V_138 == V_458 )
F_8 ( V_34 -> V_2 , V_16 ) ;
return 1 ;
}
int
F_150 ( struct V_1 * V_2 , V_206 V_531 )
{
V_2 -> F_134 = F_134 ;
V_2 -> F_146 = F_146 ;
switch ( V_531 ) {
case V_532 :
V_2 -> F_78 = F_44 ;
V_2 -> F_131 = F_85 ;
V_2 -> F_132 = F_112 ;
V_2 -> F_84 = F_53 ;
V_2 -> F_83 = F_79 ;
break;
case V_533 :
V_2 -> F_78 = F_74 ;
V_2 -> F_131 = F_127 ;
V_2 -> F_132 = F_130 ;
V_2 -> F_84 = F_64 ;
V_2 -> F_83 = F_80 ;
break;
default:
F_3 ( V_2 , V_10 , V_534 ,
L_90 ,
V_531 ) ;
return - V_535 ;
break;
}
V_2 -> F_28 = F_28 ;
V_2 -> F_139 = F_139 ;
return 0 ;
}
static void
F_151 ( struct V_1 * V_2 ,
struct V_164 * V_536 ,
struct V_164 * V_537 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_536 -> V_153 ;
if ( V_16 )
F_84 ( V_2 , V_16 ) ;
return;
}
const char *
F_152 ( struct V_29 * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_538 , V_539 = 0 ;
static char V_540 [ 384 ] ;
memset ( V_540 , 0 , 384 ) ;
if ( V_2 && V_2 -> V_226 ) {
strncpy ( V_540 , V_2 -> V_541 , 256 ) ;
V_538 = strlen ( V_540 ) ;
snprintf ( V_540 + V_538 ,
384 - V_538 ,
L_91 ,
V_2 -> V_226 -> V_542 -> V_543 ,
V_2 -> V_226 -> V_544 ,
V_2 -> V_226 -> V_545 ) ;
V_538 = strlen ( V_540 ) ;
if ( V_2 -> V_546 [ 0 ] ) {
snprintf ( V_540 + V_538 ,
384 - V_538 ,
L_92 ,
V_2 -> V_546 ) ;
}
V_538 = strlen ( V_540 ) ;
if ( V_2 -> V_138 <= V_547 ) {
V_539 = F_153 ( V_2 ) ;
} else {
if ( V_2 -> V_156 . V_548 . V_549 )
V_539 =
V_2 -> V_156 . V_548 . V_549 ;
else
V_539 = V_2 -> V_156 . V_548 . V_550 ;
}
if ( V_539 != 0 )
snprintf ( V_540 + V_538 , 384 - V_538 ,
L_93 , V_539 ) ;
}
return V_540 ;
}
static T_7 void F_154 ( struct V_1 * V_2 )
{
unsigned long V_551 =
( V_39 + F_142 ( V_2 -> V_552 ) ) ;
if ( V_2 -> V_169 . V_170 [ V_553 ] . V_554 )
F_155 ( & V_2 -> V_555 ,
V_551 ) ;
}
void F_156 ( struct V_1 * V_2 )
{
F_154 ( V_2 ) ;
}
void F_157 ( unsigned long V_497 )
{
struct V_1 * V_2 = (struct V_1 * ) V_497 ;
if ( V_2 -> V_491 & V_492 ) {
F_158 ( V_2 ,
& V_2 -> V_169 . V_170 [ V_553 ] , V_556 ) ;
if ( V_2 -> V_491 & V_557 )
F_154 ( V_2 ) ;
}
}
static int
F_159 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_52 ;
struct V_15 * V_16 ;
struct V_105 * V_106 = F_41 ( F_42 ( V_4 -> V_31 ) ) ;
int V_361 ;
V_361 = F_160 ( V_106 ) ;
if ( V_361 ) {
V_4 -> V_38 = V_361 ;
goto V_558;
}
V_52 = V_23 -> V_25 ;
if ( ( F_97 ( V_4 ) != V_247 ) &&
( ! ( V_2 -> V_139 & V_140 ) ) ) {
F_3 ( V_2 , V_10 , V_11 ,
L_94
L_95
L_96 ,
V_4 -> V_4 [ 0 ] , F_97 ( V_4 ) ,
V_559 [ F_97 ( V_4 ) ] ) ;
goto V_558;
}
if ( ! V_52 || ! F_18 ( V_52 ) )
goto V_560;
if ( F_33 ( & V_52 -> V_450 ) >= V_52 -> V_484 )
goto V_560;
V_16 = F_83 ( V_2 , V_52 ) ;
if ( V_16 == NULL ) {
F_28 ( V_2 ) ;
F_136 ( V_34 , V_210 , V_333 ,
L_97
L_98 ) ;
goto V_561;
}
V_16 -> V_27 = V_4 ;
V_16 -> V_23 = V_23 ;
V_16 -> V_528 = 0 ;
V_16 -> V_40 = V_39 ;
V_4 -> V_255 = ( unsigned char * ) V_16 ;
if ( F_97 ( V_4 ) != V_247 ) {
if ( V_34 -> V_2 -> V_562 ) {
F_136 ( V_34 , V_210 , V_11 ,
L_99
L_100 ,
V_559 [ F_97 ( V_4 ) ] ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_98 ( V_4 ) ,
F_117 ( V_4 -> V_371 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_361 = F_132 ( V_2 , V_16 ) ;
} else {
if ( V_34 -> V_2 -> V_562 ) {
F_136 ( V_34 , V_210 , V_11 ,
L_101
L_102 ,
V_4 -> V_4 [ 0 ] ,
( unsigned long long ) F_98 ( V_4 ) ,
F_117 ( V_4 -> V_371 ) ,
( V_4 -> V_4 [ 1 ] >> 5 ) ) ;
}
V_361 = F_131 ( V_2 , V_16 ) ;
}
if ( V_361 )
goto V_563;
F_146 ( V_34 , V_16 , V_52 ) ;
F_29 ( & V_52 -> V_450 ) ;
V_361 = F_161 ( V_2 , V_553 ,
& V_16 -> V_122 , V_564 ) ;
if ( V_361 ) {
F_140 ( & V_52 -> V_450 ) ;
goto V_563;
}
if ( V_2 -> V_491 & V_492 ) {
F_158 ( V_2 ,
& V_2 -> V_169 . V_170 [ V_553 ] , V_556 ) ;
if ( V_2 -> V_491 & V_557 )
F_154 ( V_2 ) ;
}
return 0 ;
V_563:
F_134 ( V_2 , V_16 ) ;
F_84 ( V_2 , V_16 ) ;
V_561:
return V_565 ;
V_560:
return V_566 ;
V_558:
V_4 -> V_490 ( V_4 ) ;
return 0 ;
}
static int
F_162 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_164 * V_111 ;
struct V_164 * V_567 ;
struct V_15 * V_16 ;
T_2 * V_26 , * V_568 ;
int V_282 = V_569 , V_151 = 0 ;
unsigned long V_28 ;
F_163 ( V_493 ) ;
V_151 = F_164 ( V_4 ) ;
if ( V_151 != 0 && V_151 != V_569 )
return V_151 ;
F_14 ( & V_2 -> V_75 , V_28 ) ;
if ( V_2 -> V_570 & V_571 ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_136 ( V_34 , V_438 , V_333 ,
L_103
L_104 ) ;
return V_572 ;
}
V_16 = (struct V_15 * ) V_4 -> V_255 ;
if ( ! V_16 || ! V_16 -> V_27 ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_136 ( V_34 , V_438 , V_333 ,
L_105
L_106 ,
V_569 , V_4 -> V_31 -> V_430 , V_4 -> V_31 -> V_53 ) ;
return V_569 ;
}
V_111 = & V_16 -> V_122 ;
if ( ! ( V_111 -> V_123 & V_573 ) ) {
F_15 ( & V_2 -> V_75 , V_28 ) ;
F_136 ( V_34 , V_438 , V_333 ,
L_107
L_108 ) ;
return V_572 ;
}
if ( V_16 -> V_27 != V_4 ) {
F_136 ( V_34 , V_438 , V_333 ,
L_109
L_110 ) ;
goto V_574;
}
F_108 ( V_111 -> V_153 != V_16 ) ;
V_567 = F_165 ( V_2 ) ;
if ( V_567 == NULL ) {
V_282 = V_572 ;
goto V_574;
}
V_26 = & V_111 -> V_111 ;
V_568 = & V_567 -> V_111 ;
V_568 -> V_58 . V_575 . V_576 = V_577 ;
V_568 -> V_58 . V_575 . V_578 = V_26 -> V_459 ;
if ( V_2 -> V_138 == V_458 )
V_568 -> V_58 . V_575 . V_579 = V_111 -> V_172 ;
else
V_568 -> V_58 . V_575 . V_579 = V_26 -> V_460 ;
V_568 -> V_146 = 1 ;
V_568 -> V_149 = V_26 -> V_149 ;
V_567 -> V_580 = V_111 -> V_580 ;
V_567 -> V_123 |= V_581 ;
if ( F_166 ( V_2 ) )
V_568 -> V_509 = V_582 ;
else
V_568 -> V_509 = V_583 ;
V_567 -> V_526 = V_584 ;
V_567 -> V_34 = V_34 ;
F_15 ( & V_2 -> V_75 , V_28 ) ;
if ( F_161 ( V_2 , V_553 , V_567 , 0 ) ==
V_585 ) {
F_167 ( V_2 , V_567 ) ;
V_282 = V_572 ;
goto V_298;
}
if ( V_2 -> V_491 & V_557 )
F_158 ( V_2 ,
& V_2 -> V_169 . V_170 [ V_553 ] , V_556 ) ;
V_16 -> V_493 = & V_493 ;
F_168 ( V_493 ,
( V_16 -> V_27 != V_4 ) ,
( 2 * V_34 -> V_586 * V_587 ) ) ;
V_16 -> V_493 = NULL ;
if ( V_16 -> V_27 == V_4 ) {
V_282 = V_572 ;
F_136 ( V_34 , V_10 , V_333 ,
L_111
L_112
L_113 ,
V_111 -> V_172 , V_282 ,
V_4 -> V_31 -> V_430 , V_4 -> V_31 -> V_53 ) ;
}
goto V_298;
V_574:
F_15 ( & V_2 -> V_75 , V_28 ) ;
V_298:
F_136 ( V_34 , V_438 , V_333 ,
L_114
L_115 , V_282 , V_4 -> V_31 -> V_430 ,
V_4 -> V_31 -> V_53 ) ;
return V_282 ;
}
static char *
F_169 ( V_206 V_529 )
{
switch ( V_529 ) {
case V_588 :
return L_116 ;
case V_589 :
return L_117 ;
case V_590 :
return L_118 ;
case V_591 :
return L_119 ;
case V_592 :
return L_120 ;
case V_593 :
return L_121 ;
case V_594 :
return L_122 ;
default:
return L_123 ;
}
}
static int
F_170 ( struct V_33 * V_34 , struct V_22 * V_23 ,
unsigned V_595 , unsigned int V_596 ,
V_206 V_529 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_15 * V_16 ;
struct V_164 * V_165 ;
struct V_164 * V_597 ;
struct V_24 * V_25 = V_23 -> V_25 ;
int V_282 ;
int V_151 ;
if ( ! V_25 || ! F_18 ( V_25 ) )
return V_572 ;
V_16 = F_83 ( V_2 , V_23 -> V_25 ) ;
if ( V_16 == NULL )
return V_572 ;
V_16 -> V_528 = 60 ;
V_16 -> V_23 = V_23 ;
V_151 = F_149 ( V_34 , V_16 , V_596 ,
V_529 ) ;
if ( ! V_151 ) {
F_84 ( V_2 , V_16 ) ;
return V_572 ;
}
V_165 = & V_16 -> V_122 ;
V_597 = F_171 ( V_2 ) ;
if ( V_597 == NULL ) {
F_84 ( V_2 , V_16 ) ;
return V_572 ;
}
F_136 ( V_34 , V_210 , V_333 ,
L_124
L_125 ,
F_169 ( V_529 ) , V_595 , V_596 ,
V_25 -> V_521 , V_25 -> V_598 , V_165 -> V_172 ,
V_165 -> V_123 ) ;
V_151 = F_172 ( V_2 , V_553 ,
V_165 , V_597 , V_16 -> V_528 ) ;
if ( V_151 != V_599 ) {
if ( V_151 == V_600 ) {
V_165 -> V_526 = F_151 ;
V_282 = V_601 ;
} else
V_282 = V_572 ;
V_16 -> V_151 = V_453 ;
F_136 ( V_34 , V_10 , V_333 ,
L_126
L_127 ,
F_169 ( V_529 ) ,
V_595 , V_596 , V_597 -> V_111 . V_446 ,
V_597 -> V_111 . V_58 . V_444 [ 4 ] ,
V_165 -> V_123 ) ;
} else if ( V_151 == V_602 )
V_282 = V_572 ;
else
V_282 = V_569 ;
F_167 ( V_2 , V_597 ) ;
if ( V_282 != V_601 )
F_84 ( V_2 , V_16 ) ;
return V_282 ;
}
static int
F_173 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned long V_603 ;
if ( ! V_23 ) {
F_136 ( V_34 , V_210 , V_333 ,
L_128 , V_23 ) ;
return V_572 ;
}
V_25 = V_23 -> V_25 ;
V_603 = F_142 ( 2 * V_34 -> V_586 * 1000 ) + V_39 ;
while ( F_141 ( V_603 , V_39 ) ) {
if ( ! V_25 || ! F_18 ( V_25 ) )
return V_572 ;
if ( V_25 -> V_480 == V_481 )
return V_569 ;
F_174 ( F_142 ( 500 ) ) ;
V_23 = V_4 -> V_31 -> V_35 ;
if ( ! V_23 )
return V_572 ;
V_25 = V_23 -> V_25 ;
}
if ( ! V_25 || ! F_18 ( V_25 ) ||
( V_25 -> V_480 != V_481 ) )
return V_572 ;
return V_569 ;
}
static int
F_175 ( struct V_33 * V_34 , T_4 V_595 ,
T_6 V_596 , T_8 V_604 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_603 ;
int V_605 ;
V_605 = F_176 ( V_34 , V_595 , V_596 , V_604 ) ;
if ( V_605 )
F_177 ( V_34 , & V_2 -> V_169 . V_170 [ V_2 -> V_169 . V_606 ] ,
V_595 , V_596 , V_604 ) ;
V_603 = F_142 ( 2 * V_34 -> V_586 * 1000 ) + V_39 ;
while ( F_141 ( V_603 , V_39 ) && V_605 ) {
F_174 ( F_142 ( 20 ) ) ;
V_605 = F_176 ( V_34 , V_595 , V_596 , V_604 ) ;
}
if ( V_605 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_129 ,
( ( V_604 == V_607 ) ? L_130 :
( ( V_604 == V_608 ) ? L_131 :
( ( V_604 == V_609 ) ? L_132 : L_133 ) ) ) ,
V_605 ) ;
return V_572 ;
}
return V_569 ;
}
static int
F_178 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned V_595 = V_4 -> V_31 -> V_430 ;
unsigned int V_596 = V_4 -> V_31 -> V_53 ;
struct V_610 V_60 ;
int V_151 , V_282 = V_569 ;
if ( ! V_23 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_134 , V_23 ) ;
return V_572 ;
}
V_25 = V_23 -> V_25 ;
V_151 = F_164 ( V_4 ) ;
if ( V_151 != 0 && V_151 != V_569 )
return V_151 ;
V_151 = F_173 ( V_34 , V_4 ) ;
if ( V_151 == V_572 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_135 , V_23 ) ;
return V_572 ;
}
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_611 ;
V_60 . V_53 = V_596 ;
memcpy ( V_60 . V_65 , & V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_25 -> V_69 , sizeof( struct V_67 ) ) ;
F_179 ( V_30 , F_180 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_612 ) ;
V_151 = F_170 ( V_34 , V_23 , V_595 , V_596 ,
V_591 ) ;
F_136 ( V_34 , V_10 , V_333 ,
L_136
L_137 , V_595 , V_596 , V_151 ) ;
V_282 = F_175 ( V_34 , V_595 , V_596 ,
V_607 ) ;
return V_282 ;
}
static int
F_181 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_22 * V_23 = V_4 -> V_31 -> V_35 ;
struct V_24 * V_25 ;
unsigned V_595 = V_4 -> V_31 -> V_430 ;
unsigned int V_596 = V_4 -> V_31 -> V_53 ;
struct V_610 V_60 ;
int V_151 , V_282 = V_569 ;
if ( ! V_23 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_138 , V_23 ) ;
return V_572 ;
}
V_25 = V_23 -> V_25 ;
V_151 = F_164 ( V_4 ) ;
if ( V_151 != 0 && V_151 != V_569 )
return V_151 ;
V_151 = F_173 ( V_34 , V_4 ) ;
if ( V_151 == V_572 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_139 , V_23 ) ;
return V_572 ;
}
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_613 ;
V_60 . V_53 = 0 ;
memcpy ( V_60 . V_65 , & V_25 -> V_66 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_25 -> V_69 , sizeof( struct V_67 ) ) ;
F_179 ( V_30 , F_180 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_612 ) ;
V_151 = F_170 ( V_34 , V_23 , V_595 , V_596 ,
V_592 ) ;
F_136 ( V_34 , V_10 , V_333 ,
L_140
L_137 , V_595 , V_596 , V_151 ) ;
V_282 = F_175 ( V_34 , V_595 , V_596 ,
V_608 ) ;
return V_282 ;
}
static int
F_182 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_24 * V_52 = NULL ;
struct V_610 V_60 ;
int V_614 ;
int V_282 = V_569 , V_151 , V_37 ;
V_60 . V_61 = V_62 ;
V_60 . V_63 = V_615 ;
V_60 . V_53 = 0 ;
memcpy ( V_60 . V_65 , & V_34 -> V_616 , sizeof( struct V_67 ) ) ;
memcpy ( V_60 . V_68 , & V_34 -> V_617 , sizeof( struct V_67 ) ) ;
F_179 ( V_30 , F_180 () ,
sizeof( V_60 ) , ( char * ) & V_60 , V_612 ) ;
V_151 = F_164 ( V_4 ) ;
if ( V_151 != 0 && V_151 != V_569 )
return V_151 ;
for ( V_37 = 0 ; V_37 < V_618 ; V_37 ++ ) {
V_614 = 0 ;
F_76 ( V_30 -> V_41 ) ;
F_81 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_18 ( V_52 ) )
continue;
if ( V_34 -> V_2 -> V_619 &&
( V_52 -> V_523 & V_524 ) )
continue;
if ( V_52 -> V_480 == V_481 &&
V_52 -> V_620 == V_37 &&
V_52 -> V_106 ) {
V_614 = 1 ;
break;
}
}
F_77 ( V_30 -> V_41 ) ;
if ( ! V_614 )
continue;
V_151 = F_170 ( V_34 , V_52 -> V_106 -> V_621 ,
V_37 , 0 , V_592 ) ;
if ( V_151 != V_569 ) {
F_136 ( V_34 , V_10 , V_333 ,
L_141 ,
V_37 ) ;
V_282 = V_572 ;
}
}
V_151 = F_175 ( V_34 , 0 , 0 , V_609 ) ;
if ( V_151 != V_569 )
V_282 = V_572 ;
F_136 ( V_34 , V_10 , V_333 ,
L_142 , V_282 ) ;
return V_282 ;
}
static int
F_183 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_31 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_30 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_199 , V_282 = V_569 ;
F_184 ( V_2 , V_622 ) ;
F_185 ( V_2 ) ;
V_199 = F_186 ( V_2 ) ;
if ( V_199 )
V_282 = V_572 ;
F_187 ( V_2 ) ;
F_188 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_333 ,
L_143 , V_282 ) ;
return V_282 ;
}
static int
F_189 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_105 * V_106 = F_41 ( F_42 ( V_79 ) ) ;
T_1 V_623 = 0 ;
T_1 V_107 = 0 ;
int V_624 = 0 ;
T_1 V_625 ;
if ( ! V_106 || F_160 ( V_106 ) )
return - V_626 ;
V_79 -> V_35 = V_106 -> V_621 ;
V_625 = F_190 ( & V_2 -> V_625 ) ;
V_623 = V_2 -> V_627 ;
V_107 = V_34 -> V_97 + 2 ;
if ( ( V_625 * ( V_34 -> V_97 + 2 ) ) < V_623 )
return 0 ;
if ( V_623 >= V_2 -> V_628 - V_629 ) {
F_136 ( V_34 , V_438 , V_333 ,
L_144
L_145 , V_623 ) ;
return 0 ;
} else if ( V_623 + V_107 >
V_2 -> V_628 - V_629 ) {
F_136 ( V_34 , V_438 , V_333 ,
L_146
L_147
L_148 ,
V_107 , V_2 -> V_628 ,
( V_2 -> V_628 - V_623 ) ) ;
V_107 = V_2 -> V_628 - V_623 ;
}
V_624 = F_78 ( V_34 , V_107 ) ;
if ( V_107 != V_624 ) {
F_136 ( V_34 , V_438 , V_333 ,
L_149
L_150
L_151 ,
V_107 , V_624 ) ;
}
if ( V_624 > 0 )
V_2 -> V_627 += V_624 ;
return 0 ;
}
static int
F_191 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
if ( V_79 -> V_86 )
F_26 ( V_79 , V_34 -> V_97 ) ;
else
F_27 ( V_79 , V_34 -> V_97 ) ;
if ( V_2 -> V_491 & V_492 ) {
F_158 ( V_2 ,
& V_2 -> V_169 . V_170 [ V_553 ] , V_556 ) ;
if ( V_2 -> V_491 & V_557 )
F_154 ( V_2 ) ;
}
return 0 ;
}
static void
F_192 ( struct V_78 * V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 -> V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
F_140 ( & V_2 -> V_625 ) ;
V_79 -> V_35 = NULL ;
return;
}
