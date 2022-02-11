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
void
F_22 ( struct V_12 * V_8 )
{
unsigned long V_43 ;
T_1 V_62 ;
unsigned long V_63 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
F_23 ( & V_8 -> V_65 ) ;
V_8 -> V_66 = V_49 ;
V_63 = V_8 -> V_67 + V_68 ;
if ( F_24 ( V_63 , V_49 ) ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
return;
}
V_8 -> V_67 = V_49 ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_20 ( & V_8 -> V_69 -> V_70 , V_43 ) ;
V_62 = V_8 -> V_69 -> V_71 & V_72 ;
if ( ! V_62 )
V_8 -> V_69 -> V_71 |= V_72 ;
F_21 ( & V_8 -> V_69 -> V_70 , V_43 ) ;
if ( ! V_62 )
F_25 ( V_8 ) ;
return;
}
void
F_26 ( struct V_12 * V_8 )
{
struct V_4 * * V_73 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
unsigned long V_74 ;
unsigned long V_65 , V_75 ;
int V_47 ;
V_65 = F_27 ( & V_8 -> V_65 ) ;
V_75 = F_27 ( & V_8 -> V_75 ) ;
if ( V_65 == 0 )
return;
V_73 = F_28 ( V_8 ) ;
if ( V_73 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_76 && V_73 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_29 ( V_73 [ V_47 ] ) ;
F_30 (sdev, shost) {
V_74 =
V_3 -> V_77 * V_65 /
( V_65 + V_75 ) ;
if ( ! V_74 )
V_74 = V_3 -> V_77 - 1 ;
else
V_74 = V_3 -> V_77 -
V_74 ;
F_31 ( V_3 , V_74 ) ;
}
}
F_32 ( V_8 , V_73 ) ;
F_33 ( & V_8 -> V_65 , 0 ) ;
F_33 ( & V_8 -> V_75 , 0 ) ;
}
void
F_34 ( struct V_12 * V_8 )
{
struct V_4 * * V_73 ;
struct V_44 * V_45 ;
struct V_2 * V_3 ;
struct V_78 * V_79 ;
int V_47 ;
V_73 = F_28 ( V_8 ) ;
if ( V_73 != NULL )
for ( V_47 = 0 ; V_47 <= V_8 -> V_76 && V_73 [ V_47 ] != NULL ; V_47 ++ ) {
V_45 = F_29 ( V_73 [ V_47 ] ) ;
F_30 (sdev, shost) {
V_79 = F_35 ( F_36 ( V_3 ) ) ;
F_37 ( V_79 ) ;
}
}
F_32 ( V_8 , V_73 ) ;
}
static int
F_38 ( struct V_4 * V_5 , int V_80 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_81 ;
struct V_82 * V_83 ;
T_2 * V_84 ;
T_3 V_85 ;
T_3 V_86 ;
T_3 V_87 ;
T_4 V_88 ;
int V_89 , V_90 ;
V_90 = V_8 -> V_91 -
( sizeof( struct V_92 ) + sizeof( struct V_93 ) ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_5 ,
V_80 , V_8 -> V_91 ,
( int ) sizeof( struct V_92 ) ,
( int ) sizeof( struct V_93 ) , V_90 ) ;
for ( V_89 = 0 ; V_89 < V_80 ; V_89 ++ ) {
V_81 = F_40 ( sizeof( struct V_31 ) , V_96 ) ;
if ( ! V_81 )
break;
V_81 -> V_97 = F_41 ( V_8 -> V_98 ,
V_96 , & V_81 -> V_99 ) ;
if ( ! V_81 -> V_97 ) {
F_42 ( V_81 ) ;
break;
}
V_88 = F_43 ( V_8 , & V_81 -> V_100 ) ;
if ( V_88 == 0 ) {
F_44 ( V_8 -> V_98 ,
V_81 -> V_97 , V_81 -> V_99 ) ;
F_42 ( V_81 ) ;
break;
}
V_81 -> V_100 . V_101 |= V_102 ;
V_81 -> V_92 = V_81 -> V_97 ;
V_81 -> V_93 = V_81 -> V_97 + sizeof( struct V_92 ) ;
V_81 -> V_35 = V_81 -> V_97 + sizeof( struct V_92 ) +
sizeof( struct V_93 ) ;
V_83 = V_81 -> V_35 ;
V_85 = V_81 -> V_99 ;
V_86 = V_81 -> V_99 + sizeof( struct V_92 ) ;
V_87 = V_81 -> V_99 + sizeof( struct V_92 ) +
sizeof( struct V_93 ) ;
V_83 [ 0 ] . V_103 = F_15 ( F_45 ( V_85 ) ) ;
V_83 [ 0 ] . V_104 = F_15 ( F_46 ( V_85 ) ) ;
V_83 [ 0 ] . V_105 . V_106 . V_107 = sizeof( struct V_92 ) ;
V_83 [ 0 ] . V_105 . V_106 . V_108 = V_109 ;
V_83 [ 0 ] . V_105 . V_110 = F_15 ( V_83 [ 0 ] . V_105 . V_110 ) ;
V_83 [ 1 ] . V_103 = F_15 ( F_45 ( V_86 ) ) ;
V_83 [ 1 ] . V_104 = F_15 ( F_46 ( V_86 ) ) ;
V_83 [ 1 ] . V_105 . V_106 . V_107 = sizeof( struct V_93 ) ;
V_83 [ 1 ] . V_105 . V_106 . V_108 = V_109 ;
V_83 [ 1 ] . V_105 . V_110 = F_15 ( V_83 [ 1 ] . V_105 . V_110 ) ;
V_84 = & V_81 -> V_100 . V_84 ;
V_84 -> V_111 . V_112 . V_113 . V_114 = 0 ;
if ( ( V_8 -> V_115 == 3 ) &&
! ( V_8 -> V_116 & V_117 ) ) {
V_84 -> V_111 . V_112 . V_113 . V_108 = V_118 ;
V_84 -> V_111 . V_112 . V_113 . V_107 = sizeof( struct V_92 ) ;
V_84 -> V_111 . V_112 . V_113 . V_104 = F_47 ( T_2 ,
V_119 . V_120 . V_121 ) ;
V_84 -> V_111 . V_112 . V_113 . V_103 = 0 ;
V_84 -> V_122 = 0 ;
V_84 -> V_123 = 0 ;
V_84 -> V_119 . V_120 . V_124 . V_105 . V_106 . V_108 =
V_109 ;
V_84 -> V_119 . V_120 . V_124 . V_105 . V_106 . V_107 =
sizeof( struct V_93 ) ;
V_84 -> V_119 . V_120 . V_124 . V_104 =
F_46 ( V_86 ) ;
V_84 -> V_119 . V_120 . V_124 . V_103 =
F_45 ( V_86 ) ;
} else {
V_84 -> V_111 . V_112 . V_113 . V_108 = V_125 ;
V_84 -> V_111 . V_112 . V_113 . V_107 =
( 2 * sizeof( struct V_82 ) ) ;
V_84 -> V_111 . V_112 . V_113 . V_104 =
F_46 ( V_87 ) ;
V_84 -> V_111 . V_112 . V_113 . V_103 =
F_45 ( V_87 ) ;
V_84 -> V_122 = 1 ;
V_84 -> V_123 = 1 ;
}
V_84 -> V_126 = V_127 ;
V_81 -> V_128 = V_129 ;
V_81 -> V_100 . V_130 = V_81 ;
F_48 ( V_8 , V_81 ) ;
}
return V_89 ;
}
void
F_49 ( struct V_4 * V_5 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_81 , * V_131 ;
unsigned long V_132 = 0 ;
if ( ! ( V_8 -> V_133 & V_134 ) )
return;
F_20 ( & V_8 -> V_64 , V_132 ) ;
F_50 ( & V_8 -> V_135 . V_136 ) ;
F_51 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_81 -> V_38 && V_81 -> V_38 -> V_40
&& V_81 -> V_38 -> V_40 -> V_5 == V_5 )
V_81 -> V_38 = NULL ;
}
F_52 ( & V_8 -> V_135 . V_136 ) ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
}
void
F_53 ( struct V_12 * V_8 ,
struct V_137 * V_138 )
{
T_4 V_139 = F_54 ( V_140 , V_138 ) ;
T_4 V_141 = F_54 ( V_142 , V_138 ) ;
struct V_31 * V_81 , * V_131 ;
unsigned long V_132 = 0 ;
struct V_143 * V_144 ;
int V_47 ;
struct V_39 * V_145 ;
int V_146 = 0 ;
struct V_147 * V_148 = V_8 -> V_135 . V_149 -> V_148 ;
if ( ! ( V_8 -> V_133 & V_134 ) )
return;
F_20 ( & V_8 -> V_64 , V_132 ) ;
F_50 ( & V_8 -> V_135 . V_136 ) ;
F_51 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_81 -> V_100 . V_150 == V_139 ) {
F_55 ( & V_81 -> V_151 ) ;
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
F_52 (
& V_8 -> V_135 . V_136 ) ;
if ( V_81 -> V_38 && V_81 -> V_38 -> V_40 )
V_145 = V_81 -> V_38 -> V_40 ;
else
V_145 = NULL ;
V_146 = F_56 ( & V_8 -> V_153 ) ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
if ( V_145 ) {
F_57 ( V_8 , V_145 ,
V_81 -> V_100 . V_154 , V_141 , 1 ) ;
F_58 ( V_8 , V_145 , V_138 ) ;
}
F_59 ( V_8 , V_81 ) ;
if ( V_146 )
F_25 ( V_8 ) ;
return;
}
}
F_52 ( & V_8 -> V_135 . V_136 ) ;
for ( V_47 = 1 ; V_47 <= V_8 -> V_155 . V_156 ; V_47 ++ ) {
V_144 = V_8 -> V_155 . V_157 [ V_47 ] ;
if ( ! ( V_144 -> V_101 & V_102 ) ||
( V_144 -> V_101 & V_158 ) )
continue;
if ( V_144 -> V_150 != V_139 )
continue;
V_81 = F_60 ( V_144 , struct V_31 , V_100 ) ;
V_81 -> V_152 = 0 ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
if ( ! F_56 ( & V_148 -> V_159 ) )
F_25 ( V_8 ) ;
return;
}
F_21 ( & V_8 -> V_64 , V_132 ) ;
}
static int
F_61 ( struct V_12 * V_8 ,
struct V_160 * V_161 , int V_162 )
{
struct V_31 * V_81 , * V_163 ;
int V_128 , V_164 ;
int V_165 = 0 , V_166 = 0 , V_167 = 0 , V_168 = 0 ;
T_3 V_169 ;
int V_170 = V_171 ;
F_62 ( V_172 ) ;
F_62 ( V_173 ) ;
F_62 ( V_174 ) ;
if ( V_162 <= 0 )
return - V_175 ;
V_164 = V_8 -> V_91 -
( sizeof( struct V_92 ) + sizeof( struct V_93 ) ) ;
F_51 (psb, psb_next, post_sblist, list) {
F_63 ( & V_81 -> V_151 ) ;
V_166 ++ ;
if ( ( V_170 != V_171 ) &&
( V_81 -> V_100 . V_150 != V_170 + 1 ) ) {
F_64 ( & V_172 , & V_173 ) ;
V_165 = V_166 - 1 ;
F_65 ( & V_81 -> V_151 , & V_172 ) ;
V_166 = 1 ;
} else {
F_65 ( & V_81 -> V_151 , & V_172 ) ;
if ( V_166 == V_176 ) {
F_64 ( & V_172 , & V_173 ) ;
V_165 = V_166 ;
V_166 = 0 ;
}
}
V_167 ++ ;
V_170 = V_81 -> V_100 . V_150 ;
if ( V_167 == V_162 ) {
if ( V_165 == 0 ) {
F_64 ( & V_172 , & V_173 ) ;
V_165 = V_166 ;
} else if ( V_166 == 1 ) {
if ( V_164 > V_177 )
V_169 = V_81 -> V_178 +
V_177 ;
else
V_169 = 0 ;
V_128 = F_66 ( V_8 ,
V_81 -> V_178 ,
V_169 ,
V_81 -> V_100 . V_150 ) ;
if ( V_128 ) {
V_81 -> V_152 = 1 ;
} else {
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
V_168 ++ ;
}
F_65 ( & V_81 -> V_151 , & V_174 ) ;
}
}
if ( V_165 == 0 )
continue;
V_128 = F_67 ( V_8 , & V_173 ,
V_165 ) ;
if ( V_166 == 0 )
V_170 = V_171 ;
V_165 = 0 ;
while ( ! F_56 ( & V_173 ) ) {
F_68 ( & V_173 , V_81 ,
struct V_31 , V_151 ) ;
if ( V_128 ) {
V_81 -> V_152 = 1 ;
} else {
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
V_168 ++ ;
}
F_65 ( & V_81 -> V_151 , & V_174 ) ;
}
}
while ( ! F_56 ( & V_174 ) ) {
F_68 ( & V_174 , V_81 ,
struct V_31 , V_151 ) ;
F_59 ( V_8 , V_81 ) ;
}
return V_168 ;
}
int
F_69 ( struct V_12 * V_8 )
{
F_62 ( V_161 ) ;
int V_168 , V_179 = 0 ;
F_70 ( & V_8 -> V_180 ) ;
F_50 ( & V_8 -> V_181 ) ;
F_64 ( & V_8 -> V_182 , & V_161 ) ;
F_71 ( & V_8 -> V_183 , & V_161 ) ;
F_52 ( & V_8 -> V_181 ) ;
F_72 ( & V_8 -> V_180 ) ;
if ( ! F_56 ( & V_161 ) ) {
V_168 = F_61 ( V_8 , & V_161 ,
V_8 -> V_135 . V_184 ) ;
if ( V_168 == 0 )
V_179 = - V_185 ;
}
return V_179 ;
}
static int
F_73 ( struct V_4 * V_5 , int V_80 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_81 ;
struct V_33 * V_34 ;
T_2 * V_84 ;
T_3 V_85 ;
T_3 V_86 ;
T_3 V_87 ;
T_4 V_88 , V_186 = 0 ;
int V_89 , V_168 , V_164 ;
F_62 ( V_172 ) ;
F_62 ( V_161 ) ;
F_62 ( V_174 ) ;
V_164 = V_8 -> V_91 -
( sizeof( struct V_92 ) + sizeof( struct V_93 ) ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_6 ,
V_80 , V_8 -> V_91 , V_164 ,
( int ) sizeof( struct V_92 ) ,
( int ) sizeof( struct V_93 ) ) ;
for ( V_89 = 0 ; V_89 < V_80 ; V_89 ++ ) {
V_81 = F_40 ( sizeof( struct V_31 ) , V_96 ) ;
if ( ! V_81 )
break;
V_81 -> V_97 = F_41 ( V_8 -> V_98 ,
V_96 , & V_81 -> V_99 ) ;
if ( ! V_81 -> V_97 ) {
F_42 ( V_81 ) ;
break;
}
if ( V_8 -> V_187 && ( ( ( unsigned long ) ( V_81 -> V_97 ) &
( unsigned long ) ( V_188 - 1 ) ) != 0 ) ) {
F_44 ( V_8 -> V_98 ,
V_81 -> V_97 , V_81 -> V_99 ) ;
F_42 ( V_81 ) ;
break;
}
V_186 = F_74 ( V_8 ) ;
if ( V_186 == V_171 ) {
F_44 ( V_8 -> V_98 ,
V_81 -> V_97 , V_81 -> V_99 ) ;
F_42 ( V_81 ) ;
break;
}
V_88 = F_43 ( V_8 , & V_81 -> V_100 ) ;
if ( V_88 == 0 ) {
F_44 ( V_8 -> V_98 ,
V_81 -> V_97 , V_81 -> V_99 ) ;
F_42 ( V_81 ) ;
F_4 ( V_8 , V_20 , V_95 ,
L_7
L_8 , V_186 ) ;
F_75 ( V_8 , V_186 ) ;
break;
}
V_81 -> V_100 . V_154 = V_186 ;
V_81 -> V_100 . V_150 = V_8 -> V_135 . V_189 [ V_186 ] ;
V_81 -> V_100 . V_101 |= V_102 ;
V_81 -> V_35 = V_81 -> V_97 ;
V_81 -> V_92 = ( V_81 -> V_97 + V_164 ) ;
V_81 -> V_93 = (struct V_93 * ) ( ( V_190 * ) V_81 -> V_92 +
sizeof( struct V_92 ) ) ;
V_34 = (struct V_33 * ) V_81 -> V_35 ;
V_87 = V_81 -> V_99 ;
V_85 = ( V_81 -> V_99 + V_164 ) ;
V_86 = V_85 + sizeof( struct V_92 ) ;
V_34 -> V_191 = F_17 ( F_45 ( V_85 ) ) ;
V_34 -> V_192 = F_17 ( F_46 ( V_85 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_193 = F_17 ( sizeof( struct V_92 ) ) ;
V_34 ++ ;
V_34 -> V_191 = F_17 ( F_45 ( V_86 ) ) ;
V_34 -> V_192 = F_17 ( F_46 ( V_86 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_193 = F_17 ( sizeof( struct V_93 ) ) ;
V_84 = & V_81 -> V_100 . V_84 ;
V_84 -> V_111 . V_112 . V_113 . V_114 = 0 ;
V_84 -> V_111 . V_112 . V_113 . V_108 = V_109 ;
V_84 -> V_111 . V_112 . V_113 . V_107 = sizeof( struct V_92 ) ;
V_84 -> V_111 . V_112 . V_113 . V_104 = F_46 ( V_85 ) ;
V_84 -> V_111 . V_112 . V_113 . V_103 = F_45 ( V_85 ) ;
V_84 -> V_122 = 1 ;
V_84 -> V_123 = 1 ;
V_84 -> V_126 = V_127 ;
V_81 -> V_100 . V_130 = V_81 ;
V_81 -> V_178 = V_87 ;
F_65 ( & V_81 -> V_151 , & V_161 ) ;
F_70 ( & V_8 -> V_180 ) ;
V_8 -> V_135 . V_184 ++ ;
F_72 ( & V_8 -> V_180 ) ;
}
F_4 ( V_8 , V_94 , V_21 | V_95 ,
L_9
L_10 , V_89 , V_80 ) ;
if ( ! F_56 ( & V_161 ) )
V_168 = F_61 ( V_8 ,
& V_161 , V_89 ) ;
else
V_168 = 0 ;
return V_168 ;
}
static inline int
F_76 ( struct V_4 * V_5 , int V_80 )
{
return V_5 -> V_8 -> F_76 ( V_5 , V_80 ) ;
}
static struct V_31 *
F_77 ( struct V_12 * V_8 , struct V_39 * V_145 )
{
struct V_31 * V_32 = NULL ;
struct V_160 * V_194 = & V_8 -> V_182 ;
unsigned long V_132 = 0 ;
F_20 ( & V_8 -> V_180 , V_132 ) ;
F_68 ( V_194 , V_32 , struct V_31 ,
V_151 ) ;
if ( ! V_32 ) {
F_50 ( & V_8 -> V_181 ) ;
F_71 ( & V_8 -> V_183 ,
& V_8 -> V_182 ) ;
F_78 ( & V_8 -> V_183 ) ;
F_68 ( V_194 , V_32 ,
struct V_31 , V_151 ) ;
F_52 ( & V_8 -> V_181 ) ;
}
F_21 ( & V_8 -> V_180 , V_132 ) ;
return V_32 ;
}
static struct V_31 *
F_79 ( struct V_12 * V_8 , struct V_39 * V_145 )
{
struct V_31 * V_32 , * V_195 ;
unsigned long V_132 = 0 ;
int V_196 = 0 ;
F_20 ( & V_8 -> V_180 , V_132 ) ;
F_51 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_80 ( V_8 , V_145 ,
V_32 -> V_100 . V_154 ) )
continue;
F_55 ( & V_32 -> V_151 ) ;
V_196 = 1 ;
break;
}
if ( ! V_196 ) {
F_50 ( & V_8 -> V_181 ) ;
F_71 ( & V_8 -> V_183 ,
& V_8 -> V_182 ) ;
F_78 ( & V_8 -> V_183 ) ;
F_52 ( & V_8 -> V_181 ) ;
F_51 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_80 (
V_8 , V_145 , V_32 -> V_100 . V_154 ) )
continue;
F_55 ( & V_32 -> V_151 ) ;
V_196 = 1 ;
break;
}
}
F_21 ( & V_8 -> V_180 , V_132 ) ;
if ( ! V_196 )
return NULL ;
return V_32 ;
}
static struct V_31 *
F_81 ( struct V_12 * V_8 , struct V_39 * V_145 )
{
return V_8 -> F_81 ( V_8 , V_145 ) ;
}
static void
F_48 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
unsigned long V_132 = 0 ;
V_81 -> V_197 = 0 ;
V_81 -> V_198 = 0 ;
V_81 -> V_199 = 0 ;
F_20 ( & V_8 -> V_181 , V_132 ) ;
V_81 -> V_42 = NULL ;
V_81 -> V_100 . V_101 = V_102 ;
F_65 ( & V_81 -> V_151 , & V_8 -> V_183 ) ;
F_21 ( & V_8 -> V_181 , V_132 ) ;
}
static void
F_59 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
unsigned long V_132 = 0 ;
V_81 -> V_197 = 0 ;
V_81 -> V_198 = 0 ;
V_81 -> V_199 = 0 ;
if ( V_81 -> V_152 ) {
F_20 ( & V_8 -> V_135 . V_136 ,
V_132 ) ;
V_81 -> V_42 = NULL ;
F_65 ( & V_81 -> V_151 ,
& V_8 -> V_135 . V_200 ) ;
F_21 ( & V_8 -> V_135 . V_136 ,
V_132 ) ;
} else {
V_81 -> V_42 = NULL ;
V_81 -> V_100 . V_101 = V_102 ;
F_20 ( & V_8 -> V_181 , V_132 ) ;
F_65 ( & V_81 -> V_151 , & V_8 -> V_183 ) ;
F_21 ( & V_8 -> V_181 , V_132 ) ;
}
}
static void
F_82 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
V_8 -> F_82 ( V_8 , V_81 ) ;
}
static int
F_83 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_201 = NULL ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_82 * V_83 = V_32 -> V_35 ;
struct V_143 * V_144 = & V_32 -> V_100 ;
T_2 * V_202 = & V_32 -> V_100 . V_84 ;
struct V_82 * V_203 = V_202 -> V_119 . V_120 . V_204 ;
T_3 V_205 ;
T_1 V_206 = 0 ;
int V_207 , V_208 = V_13 -> V_209 ;
V_83 += 2 ;
if ( F_84 ( V_13 ) ) {
V_207 = F_85 ( & V_8 -> V_210 -> V_211 , F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_208 ) ;
if ( F_86 ( ! V_207 ) )
return 1 ;
V_32 -> V_197 = V_207 ;
if ( V_32 -> V_197 > V_8 -> V_212 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_11
L_12 ,
V_22 , V_8 -> V_212 ,
V_32 -> V_197 ) ;
V_32 -> V_197 = 0 ;
F_87 ( V_13 ) ;
return 1 ;
}
F_88 (scsi_cmnd, sgel, nseg, num_bde) {
V_205 = F_89 ( V_201 ) ;
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) &&
! ( V_144 -> V_101 & V_213 ) &&
V_207 <= V_214 ) {
V_203 -> V_105 . V_106 . V_108 = V_109 ;
V_203 -> V_105 . V_106 . V_107 = F_90 ( V_201 ) ;
V_203 -> V_104 = F_46 ( V_205 ) ;
V_203 -> V_103 = F_45 ( V_205 ) ;
V_203 ++ ;
} else {
V_83 -> V_105 . V_106 . V_108 = V_109 ;
V_83 -> V_105 . V_106 . V_107 = F_90 ( V_201 ) ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_83 -> V_104 =
F_15 ( F_46 ( V_205 ) ) ;
V_83 -> V_103 =
F_15 ( F_45 ( V_205 ) ) ;
V_83 ++ ;
}
}
}
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) &&
! ( V_144 -> V_101 & V_213 ) ) {
if ( V_206 > V_214 ) {
V_205 = V_32 -> V_99 ;
V_203 -> V_105 . V_106 . V_108 = V_125 ;
V_203 -> V_105 . V_106 . V_107 = ( V_206 *
sizeof( struct V_82 ) ) ;
V_205 += ( sizeof( struct V_92 ) +
sizeof( struct V_93 ) +
( 2 * sizeof( struct V_82 ) ) ) ;
V_203 -> V_103 = F_45 ( V_205 ) ;
V_203 -> V_104 = F_46 ( V_205 ) ;
V_202 -> V_119 . V_120 . V_215 = 2 ;
} else {
V_202 -> V_119 . V_120 . V_215 = ( V_206 + 1 ) ;
}
} else {
V_202 -> V_111 . V_112 . V_113 . V_107 =
( ( V_206 + 2 ) * sizeof( struct V_82 ) ) ;
V_202 -> V_119 . V_120 . V_215 = ( V_206 + 1 ) ;
}
V_92 -> V_216 = F_91 ( F_92 ( V_13 ) ) ;
V_202 -> V_111 . V_217 . V_218 = F_92 ( V_13 ) ;
return 0 ;
}
static int
F_93 ( struct V_12 * V_8 , struct V_13 * V_25 ,
T_1 * V_219 , T_4 * V_220 , T_1 V_221 )
{
struct V_17 * V_222 ;
struct V_31 * V_32 = NULL ;
struct V_223 * V_15 = NULL ;
struct V_39 * V_145 ;
struct V_1 * V_38 ;
T_1 V_224 = F_94 ( V_25 ) ;
T_1 V_225 ;
T_1 V_226 ;
T_5 V_227 ;
int V_179 = 0 ;
int V_228 = 0 ;
if ( V_224 == V_229 )
return 0 ;
V_222 = F_8 ( V_25 ) ;
V_227 = F_95 ( V_25 ) ;
if ( V_8 -> V_230 != V_231 ) {
V_225 = F_9 ( V_25 ) ;
V_226 = ( F_92 ( V_25 ) + V_225 - 1 ) / V_225 ;
if ( ( V_8 -> V_230 < V_227 ) ||
( V_8 -> V_230 >= ( V_227 + V_226 ) ) )
return 0 ;
if ( V_222 ) {
V_228 = V_8 -> V_230 - V_227 ;
V_226 = F_90 ( V_222 ) /
sizeof( struct V_223 ) ;
if ( V_226 < V_228 )
V_228 = V_226 ;
}
}
V_38 = F_1 ( V_25 -> V_26 ) ;
if ( V_38 && V_38 -> V_40 ) {
V_145 = V_38 -> V_40 ;
if ( V_8 -> V_232 &&
( V_8 -> V_232 != V_145 -> V_233 ) )
return 0 ;
if ( V_8 -> V_234 . V_235 . V_236 [ 0 ] &&
( memcmp ( & V_145 -> V_237 , & V_8 -> V_234 ,
sizeof( struct V_238 ) ) != 0 ) )
return 0 ;
}
if ( V_222 ) {
V_15 = (struct V_223 * ) F_5 ( V_222 ) ;
V_15 += V_228 ;
V_32 = (struct V_31 * ) V_25 -> V_239 ;
}
if ( V_219 ) {
if ( V_8 -> V_240 ) {
switch ( V_224 ) {
case V_241 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_13
L_14 ,
( unsigned long ) V_227 , V_228 ,
F_96 ( V_15 -> V_242 ) ) ;
if ( V_32 ) {
V_32 -> V_243 =
V_244 ;
V_32 -> V_245 =
V_15 ;
V_32 -> V_246 =
V_15 -> V_242 ;
}
V_15 -> V_242 = F_91 ( 0xDEADBEEF ) ;
V_8 -> V_240 -- ;
if ( V_8 -> V_240 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_247 | V_248 ;
break;
}
case V_249 :
* V_219 = 0xDEADBEEF ;
V_8 -> V_240 -- ;
if ( V_8 -> V_240 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_247 | V_248 ;
F_4 ( V_8 , V_20 , V_21 ,
L_15
L_16 , ( unsigned long ) V_227 ) ;
break;
case V_250 :
* V_219 = 0xDEADBEEF ;
V_8 -> V_240 -- ;
if ( V_8 -> V_240 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 ;
F_4 ( V_8 , V_20 , V_21 ,
L_17
L_16 , ( unsigned long ) V_227 ) ;
break;
}
}
if ( V_8 -> V_252 ) {
switch ( V_224 ) {
case V_253 :
case V_254 :
case V_255 :
* V_219 = 0xDEADBEEF ;
V_8 -> V_252 -- ;
if ( V_8 -> V_252 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 ;
F_4 ( V_8 , V_20 , V_21 ,
L_18
L_19 , ( unsigned long ) V_227 ) ;
break;
}
}
}
if ( V_220 ) {
if ( V_8 -> V_256 ) {
switch ( V_224 ) {
case V_241 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_20
L_21 ,
( unsigned long ) V_227 , V_228 ,
F_97 ( V_15 -> V_257 ) ) ;
if ( V_32 ) {
V_32 -> V_243 =
V_258 ;
V_32 -> V_245 =
V_15 ;
V_32 -> V_246 =
V_15 -> V_257 ;
}
V_15 -> V_257 = F_98 ( 0xDEAD ) ;
V_8 -> V_256 -- ;
if ( V_8 -> V_256 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_247 | V_248 ;
break;
}
case V_249 :
* V_220 = 0xDEAD ;
V_8 -> V_256 -- ;
if ( V_8 -> V_256 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_247 | V_248 ;
F_4 ( V_8 , V_20 , V_21 ,
L_22
L_16 , ( unsigned long ) V_227 ) ;
break;
case V_250 :
* V_220 = 0xDEAD ;
V_8 -> V_256 -- ;
if ( V_8 -> V_256 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 ;
F_4 ( V_8 , V_20 , V_21 ,
L_23
L_16 , ( unsigned long ) V_227 ) ;
break;
}
}
if ( V_8 -> V_259 ) {
switch ( V_224 ) {
case V_253 :
case V_254 :
case V_255 :
* V_220 = 0xDEAD ;
V_8 -> V_259 -- ;
if ( V_8 -> V_259 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 ;
F_4 ( V_8 , V_20 , V_21 ,
L_24
L_19 , ( unsigned long ) V_227 ) ;
break;
}
}
}
if ( V_221 ) {
if ( V_8 -> V_260 ) {
switch ( V_224 ) {
case V_241 :
V_179 = V_248 ;
case V_249 :
V_8 -> V_260 -- ;
if ( V_8 -> V_260 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 |= V_247 | V_261 ;
F_4 ( V_8 , V_20 , V_21 ,
L_25
L_16 , ( unsigned long ) V_227 ) ;
break;
case V_250 :
V_8 -> V_260 -- ;
if ( V_8 -> V_260 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 | V_261 ;
F_4 ( V_8 , V_20 , V_21 ,
L_26
L_16 , ( unsigned long ) V_227 ) ;
break;
}
}
if ( V_8 -> V_262 ) {
switch ( V_224 ) {
case V_253 :
case V_254 :
case V_255 :
V_8 -> V_262 -- ;
if ( V_8 -> V_262 == 0 ) {
V_8 -> V_232 = 0 ;
V_8 -> V_230 =
V_231 ;
memset ( & V_8 -> V_234 ,
0 , sizeof( struct V_238 ) ) ;
}
V_179 = V_251 | V_261 ;
F_4 ( V_8 , V_20 , V_21 ,
L_27
L_19 , ( unsigned long ) V_227 ) ;
}
}
}
return V_179 ;
}
static int
F_99 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_190 * V_263 , V_190 * V_264 )
{
V_190 V_265 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_94 ( V_25 ) ) {
case V_253 :
case V_250 :
* V_264 = V_266 ;
* V_263 = V_267 ;
break;
case V_254 :
case V_249 :
* V_264 = V_268 ;
* V_263 = V_269 ;
break;
case V_255 :
case V_241 :
* V_264 = V_270 ;
* V_263 = V_271 ;
break;
case V_229 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_28 ,
F_94 ( V_25 ) ) ;
V_265 = 1 ;
break;
}
} else {
switch ( F_94 ( V_25 ) ) {
case V_254 :
case V_249 :
* V_264 = V_268 ;
* V_263 = V_269 ;
break;
case V_255 :
case V_241 :
* V_264 = V_272 ;
* V_263 = V_272 ;
break;
case V_253 :
case V_250 :
* V_264 = V_269 ;
* V_263 = V_268 ;
break;
case V_229 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_29 ,
F_94 ( V_25 ) ) ;
V_265 = 1 ;
break;
}
}
return V_265 ;
}
static int
F_100 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_190 * V_263 , V_190 * V_264 )
{
V_190 V_265 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_94 ( V_25 ) ) {
case V_253 :
case V_250 :
* V_264 = V_269 ;
* V_263 = V_268 ;
break;
case V_254 :
case V_249 :
* V_264 = V_267 ;
* V_263 = V_266 ;
break;
case V_255 :
case V_241 :
* V_264 = V_271 ;
* V_263 = V_270 ;
break;
case V_229 :
default:
break;
}
} else {
switch ( F_94 ( V_25 ) ) {
case V_254 :
case V_249 :
* V_264 = V_267 ;
* V_263 = V_266 ;
break;
case V_255 :
case V_241 :
* V_264 = V_273 ;
* V_263 = V_273 ;
break;
case V_253 :
case V_250 :
* V_264 = V_266 ;
* V_263 = V_267 ;
break;
case V_229 :
default:
break;
}
}
return V_265 ;
}
static int
F_101 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_82 * V_83 , int V_274 )
{
struct V_17 * V_18 = NULL ;
struct V_275 * V_276 = NULL ;
struct V_277 * V_278 = NULL ;
T_3 V_205 ;
int V_47 = 0 , V_206 = 0 , V_128 ;
int V_208 = V_25 -> V_209 ;
#ifdef F_102
T_1 V_179 ;
#endif
T_1 V_279 = 1 ;
T_1 V_219 ;
V_190 V_263 , V_264 ;
V_128 = F_99 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_128 )
goto V_280;
V_219 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_179 = F_93 ( V_8 , V_25 , & V_219 , NULL , 1 ) ;
if ( V_179 ) {
if ( V_179 & V_261 )
F_100 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_179 & V_248 )
V_279 = 0 ;
}
#endif
V_276 = (struct V_275 * ) V_83 ;
memset ( V_276 , 0 , sizeof( struct V_275 ) ) ;
F_16 ( V_281 , V_276 , V_282 ) ;
V_276 -> V_283 = F_17 ( V_276 -> V_283 ) ;
V_276 -> V_219 = F_17 ( V_219 ) ;
V_206 ++ ;
V_83 ++ ;
V_278 = (struct V_277 * ) V_83 ;
memset ( V_278 , 0 , sizeof( struct V_277 ) ) ;
F_16 ( V_284 , V_278 , V_285 ) ;
F_16 ( V_286 , V_278 , V_263 ) ;
F_16 ( V_287 , V_278 , V_264 ) ;
if ( V_208 == V_288 ) {
if ( F_10 ( V_25 , V_289 ) )
F_16 ( V_290 , V_278 , V_279 ) ;
else
F_16 ( V_290 , V_278 , 0 ) ;
if ( F_10 ( V_25 , V_291 ) )
F_16 ( V_292 , V_278 , V_279 ) ;
else
F_16 ( V_292 , V_278 , 0 ) ;
}
F_16 ( V_293 , V_278 , 1 ) ;
F_16 ( V_294 , V_278 , 0 ) ;
F_16 ( V_295 , V_278 , 0 ) ;
V_278 -> V_283 = F_17 ( V_278 -> V_283 ) ;
V_278 -> V_296 = F_17 ( V_278 -> V_296 ) ;
V_278 -> V_36 = F_17 ( V_278 -> V_36 ) ;
V_206 ++ ;
V_83 ++ ;
F_88 (sc, sgde, datasegcnt, i) {
V_205 = F_89 ( V_18 ) ;
V_83 -> V_104 = F_15 ( F_46 ( V_205 ) ) ;
V_83 -> V_103 = F_15 ( F_45 ( V_205 ) ) ;
V_83 -> V_105 . V_106 . V_107 = F_90 ( V_18 ) ;
if ( V_208 == V_297 )
V_83 -> V_105 . V_106 . V_108 = V_109 ;
else
V_83 -> V_105 . V_106 . V_108 = V_298 ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_83 ++ ;
V_206 ++ ;
}
V_280:
return V_206 ;
}
static int
F_103 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_82 * V_83 , int V_299 , int V_300 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_222 = NULL ;
struct V_275 * V_276 = NULL ;
struct V_277 * V_278 = NULL ;
struct V_301 * V_302 = NULL ;
T_3 V_303 , V_304 ;
unsigned short V_305 = 0 , V_306 = 0 ;
unsigned int V_307 ;
unsigned int V_308 , V_309 = 0 , V_310 ;
unsigned int V_311 , V_312 ;
unsigned int V_313 , V_314 ;
int V_128 ;
int V_208 = V_25 -> V_209 ;
unsigned char V_315 = 0 , V_316 = 0 ;
unsigned V_225 ;
#ifdef F_102
T_1 V_179 ;
#endif
T_1 V_279 = 1 ;
T_1 V_219 ;
V_190 V_263 , V_264 ;
int V_206 = 0 ;
V_222 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_222 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_95 ,
L_30 ,
V_222 , V_18 ) ;
return 0 ;
}
V_128 = F_99 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_128 )
goto V_280;
V_225 = F_9 ( V_25 ) ;
V_219 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_179 = F_93 ( V_8 , V_25 , & V_219 , NULL , 1 ) ;
if ( V_179 ) {
if ( V_179 & V_261 )
F_100 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_179 & V_248 )
V_279 = 0 ;
}
#endif
V_307 = 0 ;
do {
if ( V_206 >= ( V_8 -> V_317 - 2 ) )
return V_206 + 3 ;
V_276 = (struct V_275 * ) V_83 ;
memset ( V_276 , 0 , sizeof( struct V_275 ) ) ;
F_16 ( V_281 , V_276 , V_282 ) ;
V_276 -> V_283 = F_17 ( V_276 -> V_283 ) ;
V_276 -> V_219 = F_17 ( V_219 ) ;
V_206 ++ ;
V_83 ++ ;
V_278 = (struct V_277 * ) V_83 ;
memset ( V_278 , 0 , sizeof( struct V_277 ) ) ;
F_16 ( V_284 , V_278 , V_285 ) ;
F_16 ( V_286 , V_278 , V_263 ) ;
F_16 ( V_287 , V_278 , V_264 ) ;
if ( F_10 ( V_25 , V_289 ) )
F_16 ( V_290 , V_278 , V_279 ) ;
else
F_16 ( V_290 , V_278 , 0 ) ;
if ( F_10 ( V_25 , V_291 ) )
F_16 ( V_292 , V_278 , V_279 ) ;
else
F_16 ( V_292 , V_278 , 0 ) ;
F_16 ( V_293 , V_278 , 1 ) ;
F_16 ( V_294 , V_278 , 0 ) ;
F_16 ( V_295 , V_278 , 0 ) ;
V_278 -> V_283 = F_17 ( V_278 -> V_283 ) ;
V_278 -> V_296 = F_17 ( V_278 -> V_296 ) ;
V_278 -> V_36 = F_17 ( V_278 -> V_36 ) ;
V_206 ++ ;
V_83 ++ ;
V_304 = F_89 ( V_222 ) + V_309 ;
V_308 = F_90 ( V_222 ) - V_309 ;
F_104 ( V_308 % 8 ) ;
V_302 = (struct V_301 * ) V_83 ;
memset ( V_302 , 0 , sizeof( struct V_301 ) ) ;
F_16 ( V_318 , V_302 , V_319 ) ;
V_302 -> V_103 = F_15 ( F_45 ( V_304 ) ) ;
V_302 -> V_104 = F_15 ( F_46 ( V_304 ) ) ;
V_311 = V_308 / 8 ;
V_312 = V_311 * V_225 ;
if ( ( V_302 -> V_104 & 0xfff ) + V_308 > 0x1000 ) {
V_310 = 0x1000 - ( V_302 -> V_104 & 0xfff ) ;
V_309 += V_310 ;
V_311 = V_310 / 8 ;
V_312 = V_311 * V_225 ;
} else {
V_309 = 0 ;
V_306 ++ ;
}
V_206 ++ ;
V_315 = 0 ;
V_314 = 0 ;
while ( ! V_315 ) {
if ( V_206 >= V_8 -> V_317 )
return V_206 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_31 ,
V_22 ) ;
return 0 ;
}
V_83 ++ ;
V_303 = F_89 ( V_18 ) + V_307 ;
V_83 -> V_104 = F_15 ( F_46 ( V_303 ) ) ;
V_83 -> V_103 = F_15 ( F_45 ( V_303 ) ) ;
V_313 = F_90 ( V_18 ) - V_307 ;
if ( ( V_314 + V_313 ) <= V_312 ) {
V_83 -> V_105 . V_106 . V_107 = V_313 ;
V_307 = 0 ;
if ( ( V_314 + V_313 ) == V_312 )
V_315 = 1 ;
} else {
V_83 -> V_105 . V_106 . V_107 = V_312 - V_314 ;
V_307 += V_83 -> V_105 . V_106 . V_107 ;
}
V_314 += V_83 -> V_105 . V_106 . V_107 ;
if ( V_208 == V_297 )
V_83 -> V_105 . V_106 . V_108 = V_109 ;
else
V_83 -> V_105 . V_106 . V_108 = V_298 ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_206 ++ ;
V_305 ++ ;
if ( V_307 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_309 ) {
V_219 += V_311 ;
V_83 ++ ;
continue;
}
if ( V_306 == V_300 ) {
V_316 = 1 ;
} else if ( V_306 < V_300 ) {
V_222 = F_6 ( V_222 ) ;
V_83 ++ ;
V_219 += V_311 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_32 , V_22 ) ;
}
} while ( ! V_316 );
V_280:
return V_206 ;
}
static int
F_105 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_274 )
{
struct V_17 * V_18 = NULL ;
struct V_320 * V_321 = NULL ;
T_3 V_205 ;
int V_47 = 0 , V_322 = 0 , V_128 ;
T_1 V_219 ;
V_190 V_263 , V_264 ;
#ifdef F_102
T_1 V_179 ;
#endif
T_1 V_279 = 1 ;
T_1 V_323 ;
T_1 V_324 = 0 ;
V_128 = F_99 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_128 )
goto V_280;
V_219 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_179 = F_93 ( V_8 , V_25 , & V_219 , NULL , 1 ) ;
if ( V_179 ) {
if ( V_179 & V_261 )
F_100 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_179 & V_248 )
V_279 = 0 ;
}
#endif
V_321 = (struct V_320 * ) V_34 ;
memset ( V_321 , 0 , sizeof( struct V_320 ) ) ;
F_16 ( V_325 , V_34 , V_326 ) ;
V_321 -> V_242 = F_17 ( V_219 ) ;
V_321 -> V_327 = V_321 -> V_242 ;
if ( V_25 -> V_209 == V_288 ) {
if ( F_10 ( V_25 , V_289 ) )
F_16 ( V_328 , V_321 , V_279 ) ;
else
F_16 ( V_328 , V_321 , 0 ) ;
if ( F_10 ( V_25 , V_291 ) )
F_16 ( V_329 , V_321 , V_279 ) ;
else
F_16 ( V_329 , V_321 , 0 ) ;
}
F_16 ( V_330 , V_321 , V_263 ) ;
F_16 ( V_331 , V_321 , V_264 ) ;
F_16 ( V_332 , V_321 , 1 ) ;
F_16 ( V_333 , V_321 , 0 ) ;
V_321 -> V_36 = F_17 ( V_321 -> V_36 ) ;
V_321 -> V_334 = F_17 ( V_321 -> V_334 ) ;
V_322 ++ ;
V_34 ++ ;
F_88 (sc, sgde, datasegcnt, i) {
V_205 = F_89 ( V_18 ) ;
V_323 = F_90 ( V_18 ) ;
V_34 -> V_192 = F_17 ( F_46 ( V_205 ) ) ;
V_34 -> V_191 = F_17 ( F_45 ( V_205 ) ) ;
if ( ( V_47 + 1 ) == V_274 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_335 , V_34 , V_324 ) ;
F_16 ( V_325 , V_34 , V_336 ) ;
V_34 -> V_193 = F_17 ( V_323 ) ;
V_324 += V_323 ;
V_34 ++ ;
V_322 ++ ;
}
V_280:
return V_322 ;
}
static int
F_106 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_299 , int V_300 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_222 = NULL ;
struct V_320 * V_321 = NULL ;
T_3 V_303 , V_304 ;
unsigned short V_305 = 0 , V_306 = 0 ;
unsigned int V_307 ;
unsigned int V_308 , V_309 = 0 , V_310 ;
unsigned int V_311 , V_312 ;
unsigned int V_313 , V_314 ;
int V_128 ;
unsigned char V_315 = 0 , V_316 = 0 ;
unsigned V_225 ;
T_1 V_219 ;
V_190 V_263 , V_264 ;
T_1 V_323 ;
#ifdef F_102
T_1 V_179 ;
#endif
T_1 V_279 = 1 ;
T_1 V_324 = 0 ;
int V_322 = 0 ;
V_222 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_222 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_95 ,
L_33 ,
V_222 , V_18 ) ;
return 0 ;
}
V_128 = F_99 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_128 )
goto V_280;
V_225 = F_9 ( V_25 ) ;
V_219 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_179 = F_93 ( V_8 , V_25 , & V_219 , NULL , 1 ) ;
if ( V_179 ) {
if ( V_179 & V_261 )
F_100 ( V_8 , V_25 , & V_263 , & V_264 ) ;
if ( V_179 & V_248 )
V_279 = 0 ;
}
#endif
V_307 = 0 ;
do {
if ( V_322 >= ( V_8 -> V_317 - 2 ) )
return V_322 + 3 ;
V_321 = (struct V_320 * ) V_34 ;
memset ( V_321 , 0 , sizeof( struct V_320 ) ) ;
F_16 ( V_325 , V_34 , V_326 ) ;
V_321 -> V_242 = F_17 ( V_219 ) ;
V_321 -> V_327 = V_321 -> V_242 ;
if ( F_10 ( V_25 , V_289 ) ) {
F_16 ( V_328 , V_321 , V_279 ) ;
} else {
F_16 ( V_328 , V_321 , 0 ) ;
if ( V_263 == V_272 ) {
V_263 = V_337 ;
V_264 = V_337 ;
}
}
if ( F_10 ( V_25 , V_291 ) )
F_16 ( V_329 , V_321 , V_279 ) ;
else
F_16 ( V_329 , V_321 , 0 ) ;
F_16 ( V_330 , V_321 , V_263 ) ;
F_16 ( V_331 , V_321 , V_264 ) ;
F_16 ( V_332 , V_321 , 1 ) ;
F_16 ( V_333 , V_321 , 0 ) ;
V_321 -> V_36 = F_17 ( V_321 -> V_36 ) ;
V_321 -> V_334 = F_17 ( V_321 -> V_334 ) ;
V_322 ++ ;
V_34 ++ ;
V_304 = F_89 ( V_222 ) + V_309 ;
V_308 = F_90 ( V_222 ) - V_309 ;
F_104 ( V_308 % 8 ) ;
V_34 -> V_36 = 0 ;
F_16 ( V_325 , V_34 , V_338 ) ;
V_34 -> V_191 = F_15 ( F_45 ( V_304 ) ) ;
V_34 -> V_192 = F_15 ( F_46 ( V_304 ) ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_311 = V_308 / 8 ;
V_312 = V_311 * V_225 ;
if ( ( V_34 -> V_192 & 0xfff ) + V_308 > 0x1000 ) {
V_310 = 0x1000 - ( V_34 -> V_192 & 0xfff ) ;
V_309 += V_310 ;
V_311 = V_310 / 8 ;
V_312 = V_311 * V_225 ;
} else {
V_309 = 0 ;
V_306 ++ ;
}
V_322 ++ ;
V_315 = 0 ;
V_314 = 0 ;
while ( ! V_315 ) {
if ( V_322 >= V_8 -> V_317 )
return V_322 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_34 ,
V_22 ) ;
return 0 ;
}
V_34 ++ ;
V_303 = F_89 ( V_18 ) + V_307 ;
V_313 = F_90 ( V_18 ) - V_307 ;
if ( ( V_314 + V_313 ) <= V_312 ) {
V_323 = V_313 ;
V_307 = 0 ;
if ( ( V_314 + V_313 ) == V_312 )
V_315 = 1 ;
} else {
V_323 = V_312 - V_314 ;
V_307 += V_323 ;
}
V_314 += V_323 ;
V_34 -> V_192 = F_17 ( F_46 ( V_303 ) ) ;
V_34 -> V_191 = F_17 ( F_45 ( V_303 ) ) ;
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_335 , V_34 , V_324 ) ;
F_16 ( V_325 , V_34 , V_336 ) ;
V_34 -> V_193 = F_17 ( V_323 ) ;
V_324 += V_323 ;
V_322 ++ ;
V_305 ++ ;
if ( V_307 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_309 ) {
V_219 += V_311 ;
V_34 ++ ;
continue;
}
if ( V_306 == V_300 ) {
F_16 ( V_37 , V_34 , 1 ) ;
V_316 = 1 ;
} else if ( V_306 < V_300 ) {
V_222 = F_6 ( V_222 ) ;
V_34 ++ ;
V_219 += V_311 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_35 , V_22 ) ;
}
} while ( ! V_316 );
V_280:
return V_322 ;
}
static int
F_12 ( struct V_12 * V_8 , struct V_13 * V_25 )
{
int V_265 = V_339 ;
unsigned char V_224 = F_94 ( V_25 ) ;
switch ( V_224 ) {
case V_254 :
case V_249 :
V_265 = V_29 ;
break;
case V_253 :
case V_250 :
case V_255 :
case V_241 :
V_265 = V_340 ;
break;
default:
if ( V_8 )
F_4 ( V_8 , V_20 , V_95 ,
L_36 ,
V_224 ) ;
break;
}
return V_265 ;
}
static int
F_107 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_25 = V_32 -> V_42 ;
int V_341 ;
V_341 = F_92 ( V_25 ) ;
if ( V_25 -> V_209 == V_288 ) {
if ( F_94 ( V_25 ) == V_253 )
return V_341 ;
} else {
if ( F_94 ( V_25 ) == V_250 )
return V_341 ;
}
V_341 += ( V_341 / F_9 ( V_25 ) ) * 8 ;
return V_341 ;
}
static int
F_108 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_82 * V_83 = V_32 -> V_35 ;
T_2 * V_202 = & V_32 -> V_100 . V_84 ;
T_1 V_206 = 0 ;
int V_274 , V_342 , V_208 = V_13 -> V_209 ;
int V_343 = 0 ;
int V_341 ;
V_83 += 2 ;
if ( F_84 ( V_13 ) ) {
V_274 = F_85 ( & V_8 -> V_210 -> V_211 ,
F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_208 ) ;
if ( F_86 ( ! V_274 ) )
return 1 ;
V_32 -> V_197 = V_274 ;
if ( V_32 -> V_197 > V_8 -> V_212 )
goto V_344;
V_343 = F_12 ( V_8 , V_13 ) ;
switch ( V_343 ) {
case V_29 :
if ( ( V_32 -> V_197 + 2 ) > V_8 -> V_317 )
goto V_344;
V_206 = F_101 ( V_8 , V_13 , V_83 ,
V_274 ) ;
if ( V_206 < 2 )
goto V_344;
break;
case V_340 :
V_342 = F_85 ( & V_8 -> V_210 -> V_211 ,
F_8 ( V_13 ) ,
F_109 ( V_13 ) , V_208 ) ;
if ( F_86 ( ! V_342 ) ) {
F_87 ( V_13 ) ;
return 1 ;
}
V_32 -> V_199 = V_342 ;
if ( ( V_32 -> V_199 * 4 ) >
( V_8 -> V_317 - 2 ) )
goto V_344;
V_206 = F_103 ( V_8 , V_13 , V_83 ,
V_274 , V_342 ) ;
if ( ( V_206 < 3 ) ||
( V_206 > V_8 -> V_317 ) )
goto V_344;
break;
case V_339 :
default:
F_87 ( V_13 ) ;
V_32 -> V_197 = 0 ;
F_4 ( V_8 , V_20 , V_95 ,
L_37 ,
V_343 ) ;
return 1 ;
}
}
V_202 -> V_111 . V_112 . V_113 . V_107 = ( 2 * sizeof( struct V_82 ) ) ;
V_202 -> V_111 . V_112 . V_113 . V_107 += ( V_206 * sizeof( struct V_82 ) ) ;
V_202 -> V_122 = 1 ;
V_202 -> V_123 = 1 ;
V_341 = F_107 ( V_8 , V_32 ) ;
V_92 -> V_216 = F_96 ( V_341 ) ;
V_202 -> V_111 . V_217 . V_218 = V_341 ;
return 0 ;
V_344:
if ( V_32 -> V_197 )
F_87 ( V_13 ) ;
if ( V_32 -> V_199 )
F_110 ( & V_8 -> V_210 -> V_211 , F_8 ( V_13 ) ,
F_109 ( V_13 ) ,
V_13 -> V_209 ) ;
F_4 ( V_8 , V_20 , V_95 ,
L_38
L_39 ,
V_32 -> V_197 , V_32 -> V_199 ,
V_8 -> V_317 , V_8 -> V_212 ,
V_343 , V_206 ) ;
V_32 -> V_197 = 0 ;
V_32 -> V_199 = 0 ;
return 1 ;
}
static T_4
F_111 ( V_190 * V_97 , int V_345 )
{
T_4 V_346 = 0 ;
T_4 V_347 ;
V_346 = F_112 ( V_97 , V_345 ) ;
V_347 = F_98 ( V_346 ) ;
return V_347 ;
}
static T_4
F_113 ( V_190 * V_97 , int V_345 )
{
T_4 V_265 ;
V_265 = F_114 ( V_97 , V_345 ) ;
return V_265 ;
}
static void
F_115 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_17 * V_222 ;
struct V_17 * V_18 ;
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_223 * V_15 = NULL ;
V_190 * V_348 = NULL ;
T_4 V_349 ;
T_4 V_350 , V_257 ;
T_1 V_351 , V_242 ;
int V_352 , V_342 ;
int V_353 , V_354 , V_355 ;
int V_356 , V_357 , V_358 ;
T_4 V_359 ;
unsigned V_225 ;
V_353 = V_360 ;
V_359 = 0 ;
V_349 = 0 ;
V_352 = F_94 ( V_41 ) ;
if ( ( V_352 == V_254 ) ||
( V_352 == V_249 ) ||
( V_352 == V_229 ) )
goto V_280;
V_356 = 1 ;
V_357 = 0 ;
V_358 = 0 ;
V_222 = F_8 ( V_41 ) ;
V_342 = V_32 -> V_199 ;
if ( V_222 && V_342 ) {
V_18 = F_3 ( V_41 ) ;
V_225 = F_9 ( V_41 ) ;
V_348 = ( V_190 * ) F_5 ( V_18 ) ;
V_355 = V_18 -> V_23 ;
if ( ( V_355 & ( V_225 - 1 ) ) == 0 )
V_358 = 1 ;
V_15 = (struct V_223 * ) F_5 ( V_222 ) ;
V_351 = ( T_1 ) F_95 ( V_41 ) ;
V_350 = V_15 -> V_257 ;
V_354 = V_222 -> V_23 ;
while ( V_15 && V_342 ) {
while ( V_354 ) {
if ( ( V_15 -> V_242 == 0xffffffff ) ||
( V_15 -> V_257 == 0xffff ) ) {
V_351 ++ ;
goto V_361;
}
if ( V_358 ) {
V_349 = V_15 -> V_349 ;
if ( F_11 ( V_41 ) )
V_359 = F_113 ( V_348 ,
V_225 ) ;
else
V_359 = F_111 ( V_348 ,
V_225 ) ;
if ( ( V_349 != V_359 ) ) {
V_353 = V_360 ;
goto V_280;
}
}
V_242 = F_96 ( V_15 -> V_242 ) ;
if ( V_356 && ( V_242 != V_351 ) ) {
V_353 = V_362 ;
goto V_280;
}
V_351 ++ ;
V_257 = V_15 -> V_257 ;
if ( V_357 && ( V_257 != V_350 ) ) {
V_353 = V_363 ;
goto V_280;
}
V_361:
V_354 -= sizeof( struct V_223 ) ;
if ( V_354 < 0 )
V_354 = 0 ;
V_15 ++ ;
V_348 += V_225 ;
V_355 -= V_225 ;
if ( V_358 && ( V_355 == 0 ) ) {
V_358 = 0 ;
V_18 = F_6 ( V_18 ) ;
if ( ! V_18 )
goto V_280;
V_348 = ( V_190 * ) F_5 ( V_18 ) ;
V_355 = V_18 -> V_23 ;
if ( ( V_355 & ( V_225 - 1 ) ) == 0 )
V_358 = 1 ;
}
}
V_222 = F_6 ( V_222 ) ;
if ( V_222 ) {
V_15 = (struct V_223 * ) F_5 ( V_222 ) ;
V_354 = V_222 -> V_23 ;
} else {
V_15 = NULL ;
}
V_342 -- ;
}
}
V_280:
if ( V_353 == V_360 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_369 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_40 ,
( unsigned long ) F_95 ( V_41 ) ,
V_359 , V_349 ) ;
} else if ( V_353 == V_362 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_371 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_41 ,
( unsigned long ) F_95 ( V_41 ) ,
V_242 , V_351 ) ;
} else if ( V_353 == V_363 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_372 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_42 ,
( unsigned long ) F_95 ( V_41 ) ,
V_257 , V_350 ) ;
}
}
static int
F_118 ( struct V_12 * V_8 , struct V_31 * V_32 ,
struct V_143 * V_373 )
{
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_374 * V_375 = & V_373 -> V_84 . V_119 . V_376 ;
int V_265 = 0 ;
T_1 V_377 = V_375 -> V_377 ;
T_1 V_378 = V_375 -> V_378 ;
T_6 V_379 = 0 ;
F_50 ( & V_380 ) ;
if ( ! V_381 ) {
F_4 ( V_8 , V_20 , V_21 , L_43
L_44 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_2 ( V_8 , V_41 ) ;
if ( F_12 ( V_8 , V_41 ) ==
V_340 ) {
F_4 ( V_8 , V_20 , V_21 , L_45
L_46 ,
( V_41 -> V_14 [ 7 ] << 8 | V_41 -> V_14 [ 8 ] ) ) ;
F_7 ( V_8 , V_41 ) ;
}
V_381 = 1 ;
}
F_52 ( & V_380 ) ;
if ( F_119 ( V_378 ) ) {
V_41 -> V_48 = F_117 ( V_382 , 0 ) ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_47
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
V_265 = ( - 1 ) ;
goto V_280;
}
if ( F_121 ( V_378 ) ) {
V_41 -> V_48 = F_117 ( V_382 , 0 ) ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_50
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
V_265 = ( - 1 ) ;
goto V_280;
}
if ( F_122 ( V_378 ) ) {
V_265 = 1 ;
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_369 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_51
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
}
if ( F_123 ( V_378 ) ) {
V_265 = 1 ;
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_371 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_52
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
}
if ( F_124 ( V_378 ) ) {
V_265 = 1 ;
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_372 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_53
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
}
if ( F_125 ( V_378 ) ) {
V_41 -> V_364 [ 7 ] = 0xc ;
V_41 -> V_364 [ 8 ] = 0 ;
V_41 -> V_364 [ 9 ] = 0xa ;
V_41 -> V_364 [ 10 ] = 0x80 ;
switch ( F_94 ( V_41 ) ) {
case V_253 :
case V_250 :
V_377 /= V_41 -> V_26 -> V_27 ;
break;
case V_254 :
case V_249 :
case V_255 :
case V_241 :
V_377 /= ( V_41 -> V_26 -> V_27 +
sizeof( struct V_223 ) ) ;
break;
}
V_379 = F_95 ( V_41 ) ;
V_379 += V_377 ;
F_126 ( V_379 , & V_41 -> V_364 [ 12 ] ) ;
}
if ( ! V_265 ) {
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_54
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
F_115 ( V_8 , V_32 ) ;
}
V_280:
return V_265 ;
}
static int
F_127 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_201 = NULL ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_33 * V_384 ;
T_2 * V_202 = & V_32 -> V_100 . V_84 ;
T_3 V_205 ;
T_1 V_206 = 0 ;
T_1 V_323 ;
T_1 V_324 = 0 ;
int V_207 ;
struct V_82 * V_385 ;
if ( F_84 ( V_13 ) ) {
V_207 = F_128 ( V_13 ) ;
if ( F_86 ( V_207 <= 0 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_384 = V_34 ;
V_32 -> V_197 = V_207 ;
if ( V_32 -> V_197 > V_8 -> V_212 ) {
F_4 ( V_8 , V_20 , V_21 , L_55
L_56
L_12 ,
V_22 , V_8 -> V_212 ,
V_32 -> V_197 ) ;
V_32 -> V_197 = 0 ;
F_87 ( V_13 ) ;
return 1 ;
}
F_88 (scsi_cmnd, sgel, nseg, num_bde) {
V_205 = F_89 ( V_201 ) ;
V_323 = F_90 ( V_201 ) ;
V_34 -> V_192 = F_17 ( F_46 ( V_205 ) ) ;
V_34 -> V_191 = F_17 ( F_45 ( V_205 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
if ( ( V_206 + 1 ) == V_207 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_335 , V_34 , V_324 ) ;
F_16 ( V_325 , V_34 , V_336 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_193 = F_17 ( V_323 ) ;
V_324 += V_323 ;
V_34 ++ ;
}
if ( V_8 -> V_116 & V_386 ) {
V_385 = (struct V_82 * )
& ( V_202 -> V_119 . V_387 [ 5 ] ) ;
V_385 -> V_104 = V_384 -> V_192 ;
V_385 -> V_103 = V_384 -> V_191 ;
V_385 -> V_105 . V_106 . V_107 =
F_15 ( V_384 -> V_193 ) ;
V_385 -> V_105 . V_106 . V_108 = V_109 ;
V_385 -> V_105 . V_110 = F_17 ( V_385 -> V_105 . V_110 ) ;
}
} else {
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
}
V_92 -> V_216 = F_91 ( F_92 ( V_13 ) ) ;
V_202 -> V_111 . V_217 . V_218 = F_92 ( V_13 ) ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_388 ) {
V_32 -> V_100 . V_101 |= ( V_389 | V_390 ) ;
V_32 -> V_100 . V_391 = ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_391 ;
}
return 0 ;
}
static int
F_129 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_32 -> V_35 ) ;
T_2 * V_202 = & V_32 -> V_100 . V_84 ;
T_1 V_322 = 0 ;
int V_274 , V_342 , V_208 = V_13 -> V_209 ;
int V_343 = 0 ;
int V_341 ;
if ( F_84 ( V_13 ) ) {
V_274 = F_85 ( & V_8 -> V_210 -> V_211 ,
F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_208 ) ;
if ( F_86 ( ! V_274 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_32 -> V_197 = V_274 ;
if ( V_32 -> V_197 > V_8 -> V_212 )
goto V_344;
V_343 = F_12 ( V_8 , V_13 ) ;
switch ( V_343 ) {
case V_29 :
if ( ( V_32 -> V_197 + 1 ) > V_8 -> V_317 )
goto V_344;
V_322 = F_105 ( V_8 , V_13 , V_34 ,
V_274 ) ;
if ( V_322 < 2 )
goto V_344;
break;
case V_340 :
V_342 = F_85 ( & V_8 -> V_210 -> V_211 ,
F_8 ( V_13 ) ,
F_109 ( V_13 ) , V_208 ) ;
if ( F_86 ( ! V_342 ) ) {
F_87 ( V_13 ) ;
return 1 ;
}
V_32 -> V_199 = V_342 ;
if ( ( V_32 -> V_199 * 3 ) >
( V_8 -> V_317 - 2 ) )
goto V_344;
V_322 = F_106 ( V_8 , V_13 , V_34 ,
V_274 , V_342 ) ;
if ( ( V_322 < 3 ) ||
( V_322 > V_8 -> V_317 ) )
goto V_344;
break;
case V_339 :
default:
F_87 ( V_13 ) ;
V_32 -> V_197 = 0 ;
F_4 ( V_8 , V_20 , V_95 ,
L_57 ,
V_343 ) ;
return 1 ;
}
}
switch ( F_94 ( V_13 ) ) {
case V_250 :
case V_254 :
V_32 -> V_100 . V_101 |= V_392 ;
break;
case V_249 :
case V_253 :
V_32 -> V_100 . V_101 |= V_393 ;
break;
case V_241 :
case V_255 :
V_32 -> V_100 . V_101 |= V_394 ;
break;
}
V_341 = F_107 ( V_8 , V_32 ) ;
V_92 -> V_216 = F_96 ( V_341 ) ;
V_202 -> V_111 . V_217 . V_218 = V_341 ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_388 )
V_32 -> V_100 . V_101 |= ( V_389 | V_390 ) ;
return 0 ;
V_344:
if ( V_32 -> V_197 )
F_87 ( V_13 ) ;
if ( V_32 -> V_199 )
F_110 ( & V_8 -> V_210 -> V_211 , F_8 ( V_13 ) ,
F_109 ( V_13 ) ,
V_13 -> V_209 ) ;
F_4 ( V_8 , V_20 , V_95 ,
L_58
L_59 ,
V_32 -> V_197 , V_32 -> V_199 ,
V_8 -> V_317 , V_8 -> V_212 ,
V_343 , V_322 ) ;
V_32 -> V_197 = 0 ;
V_32 -> V_199 = 0 ;
return 1 ;
}
static inline int
F_130 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_130 ( V_8 , V_32 ) ;
}
static inline int
F_131 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
return V_8 -> F_131 ( V_8 , V_32 ) ;
}
static void
F_132 ( struct V_12 * V_8 , struct V_4 * V_5 ,
struct V_31 * V_32 , struct V_143 * V_395 ) {
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_93 * V_396 = V_32 -> V_93 ;
T_1 V_397 = V_396 -> V_398 ;
T_1 V_399 = V_396 -> V_400 ;
T_1 V_218 = V_395 -> V_84 . V_111 . V_217 . V_218 ;
struct V_401 * V_402 = NULL ;
struct V_39 * V_40 = V_32 -> V_38 -> V_40 ;
unsigned long V_43 ;
if ( ! V_40 || ! F_133 ( V_40 ) )
return;
if ( ( V_14 -> V_48 == V_403 ) ||
( V_14 -> V_48 == V_404 ) ) {
V_402 = F_134 ( V_8 ) ;
if ( ! V_402 )
return;
V_402 -> V_111 . V_405 . V_406 =
V_407 ;
V_402 -> V_111 . V_405 . V_408 =
( V_14 -> V_48 == V_403 ) ?
V_409 : V_410 ;
V_402 -> V_111 . V_405 . V_411 = V_14 -> V_26 -> V_411 ;
memcpy ( & V_402 -> V_111 . V_405 . V_412 ,
& V_40 -> V_237 , sizeof( struct V_238 ) ) ;
memcpy ( & V_402 -> V_111 . V_405 . V_413 ,
& V_40 -> V_414 , sizeof( struct V_238 ) ) ;
} else if ( ( V_397 & V_415 ) && V_396 -> V_416 &&
( ( V_14 -> V_14 [ 0 ] == V_417 ) || ( V_14 -> V_14 [ 0 ] == V_418 ) ) ) {
V_402 = F_134 ( V_8 ) ;
if ( ! V_402 )
return;
V_402 -> V_111 . V_419 . V_420 . V_406 =
V_407 ;
V_402 -> V_111 . V_419 . V_420 . V_408 =
V_421 ;
V_402 -> V_111 . V_419 . V_420 . V_411 =
V_14 -> V_26 -> V_411 ;
memcpy ( & V_402 -> V_111 . V_419 . V_420 . V_412 ,
& V_40 -> V_237 , sizeof( struct V_238 ) ) ;
memcpy ( & V_402 -> V_111 . V_419 . V_420 . V_413 ,
& V_40 -> V_414 , sizeof( struct V_238 ) ) ;
V_402 -> V_111 . V_419 . V_422 =
V_14 -> V_364 [ 2 ] & 0xf ;
V_402 -> V_111 . V_419 . V_423 = V_14 -> V_364 [ 12 ] ;
V_402 -> V_111 . V_419 . V_424 = V_14 -> V_364 [ 13 ] ;
} else if ( ( V_14 -> V_209 == V_288 ) &&
V_218 &&
( ( F_96 ( V_396 -> V_425 ) != V_218 ) ||
( ( V_399 == V_426 ) &&
! ( V_397 & ( V_427 | V_428 ) ) ) ) ) {
V_402 = F_134 ( V_8 ) ;
if ( ! V_402 )
return;
V_402 -> V_111 . V_429 . V_430 . V_406 =
V_431 ;
V_402 -> V_111 . V_429 . V_430 . V_408 =
V_432 ;
memcpy ( & V_402 -> V_111 . V_429 . V_430 . V_412 ,
& V_40 -> V_237 , sizeof( struct V_238 ) ) ;
memcpy ( & V_402 -> V_111 . V_429 . V_430 . V_413 ,
& V_40 -> V_414 , sizeof( struct V_238 ) ) ;
V_402 -> V_111 . V_429 . V_411 = V_14 -> V_26 -> V_411 ;
V_402 -> V_111 . V_429 . V_433 = V_14 -> V_14 [ 0 ] ;
V_402 -> V_111 . V_429 . V_434 =
V_218 ;
} else
return;
V_402 -> V_5 = V_5 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
F_65 ( & V_402 -> V_435 . V_436 , & V_8 -> V_437 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_25 ( V_8 ) ;
return;
}
static void
F_135 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
if ( V_81 -> V_197 > 0 )
F_87 ( V_81 -> V_42 ) ;
if ( V_81 -> V_199 > 0 )
F_110 ( & V_8 -> V_210 -> V_211 , F_8 ( V_81 -> V_42 ) ,
F_109 ( V_81 -> V_42 ) ,
V_81 -> V_42 -> V_209 ) ;
}
static void
F_136 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_143 * V_395 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_92 * V_438 = V_32 -> V_92 ;
struct V_93 * V_396 = V_32 -> V_93 ;
T_1 V_218 = V_395 -> V_84 . V_111 . V_217 . V_218 ;
T_1 V_397 = V_396 -> V_398 ;
T_1 V_399 = V_396 -> V_400 ;
T_1 * V_439 ;
T_1 V_440 = V_441 ;
T_1 V_442 = 0 ;
T_1 V_216 ;
T_1 V_443 = V_95 | V_444 ;
if ( V_438 -> V_445 ) {
V_399 = 0 ;
goto V_280;
}
if ( V_397 & V_446 ) {
V_442 = F_96 ( V_396 -> V_447 ) ;
if ( V_442 != 0 && V_442 != 4 && V_442 != 8 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_60
L_61 ,
V_14 -> V_26 -> V_448 ,
V_14 -> V_26 -> V_411 , V_14 -> V_14 [ 0 ] ,
V_442 ) ;
V_440 = V_382 ;
goto V_280;
}
if ( V_396 -> V_449 != V_450 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_62
L_63
L_64 ,
V_14 -> V_26 -> V_448 ,
V_14 -> V_26 -> V_411 , V_14 -> V_14 [ 0 ] ,
V_396 -> V_449 ) ;
V_440 = V_382 ;
goto V_280;
}
}
if ( ( V_397 & V_415 ) && V_396 -> V_416 ) {
T_1 V_451 = F_96 ( V_396 -> V_416 ) ;
if ( V_451 > V_452 )
V_451 = V_452 ;
if ( V_397 & V_446 )
V_442 = F_96 ( V_396 -> V_447 ) ;
memcpy ( V_14 -> V_364 , & V_396 -> V_453 + V_442 , V_451 ) ;
}
V_439 = ( T_1 * ) V_14 -> V_364 ;
if ( ! V_399 && ( V_397 & V_427 ) ) {
if ( V_5 -> V_454 & V_95 )
V_443 = V_444 ;
if ( V_5 -> V_454 & V_455 )
V_443 = V_455 ;
}
F_39 ( V_5 , V_370 , V_443 ,
L_65
L_66 ,
V_14 -> V_14 [ 0 ] , V_399 ,
F_96 ( * V_439 ) , F_96 ( * ( V_439 + 3 ) ) , V_397 ,
F_96 ( V_396 -> V_425 ) ,
F_96 ( V_396 -> V_416 ) ,
F_96 ( V_396 -> V_447 ) ,
V_396 -> V_449 ) ;
F_137 ( V_14 , 0 ) ;
V_216 = F_96 ( V_438 -> V_216 ) ;
if ( V_397 & V_427 ) {
F_137 ( V_14 , F_96 ( V_396 -> V_425 ) ) ;
F_39 ( V_5 , V_94 , V_455 ,
L_67
L_68 ,
V_216 ,
F_138 ( V_14 ) , V_218 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_456 ) ;
if ( ( V_14 -> V_209 == V_288 ) &&
V_218 &&
( F_138 ( V_14 ) != V_218 ) ) {
F_39 ( V_5 , V_370 ,
V_95 | V_444 ,
L_69
L_70 ,
V_216 ,
F_138 ( V_14 ) , V_218 ,
V_14 -> V_14 [ 0 ] ) ;
F_137 ( V_14 , F_92 ( V_14 ) ) ;
V_440 = V_382 ;
}
if ( ! ( V_397 & V_415 ) &&
( V_399 == V_426 ) &&
( F_92 ( V_14 ) - F_138 ( V_14 )
< V_14 -> V_456 ) ) {
F_39 ( V_5 , V_94 , V_95 ,
L_71
L_72
L_73 ,
V_14 -> V_14 [ 0 ] , F_92 ( V_14 ) ,
F_138 ( V_14 ) , V_14 -> V_456 ) ;
V_440 = V_382 ;
}
} else if ( V_397 & V_428 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_74
L_75 , V_14 -> V_14 [ 0 ] ,
F_92 ( V_14 ) , F_138 ( V_14 ) ) ;
V_440 = V_382 ;
} else if ( V_218 ) {
F_39 ( V_5 , V_370 , V_95 | V_444 ,
L_76
L_77 ,
( ( V_14 -> V_209 == V_288 ) ?
L_78 : L_79 ) ,
( ( V_8 -> V_115 == V_457 ) ?
V_32 -> V_100 . V_150 :
V_395 -> V_84 . V_458 ) ,
V_216 , F_96 ( V_396 -> V_425 ) ,
V_218 , V_14 -> V_14 [ 0 ] , V_399 ) ;
if ( V_218 > V_216 )
goto V_280;
switch ( V_399 ) {
case V_426 :
case V_368 :
V_440 = V_382 ;
break;
}
F_137 ( V_14 , F_92 ( V_14 ) ) ;
}
V_280:
V_14 -> V_48 = F_117 ( V_440 , V_399 ) ;
F_132 ( V_5 -> V_8 , V_5 , V_32 , V_395 ) ;
}
int F_139 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_459 * V_460 ;
int V_461 , V_462 ;
T_1 V_463 ;
T_4 V_464 ;
if ( V_14 && F_140 ( V_14 -> V_26 -> V_6 ) ) {
V_463 = F_141 ( V_14 -> V_383 ) ;
V_464 = F_142 ( V_463 ) ;
return V_464 ;
}
if ( V_8 -> V_465 == V_466
&& V_8 -> V_467 > 1 ) {
V_462 = F_143 () ;
if ( V_462 < V_8 -> V_135 . V_468 ) {
V_460 = V_8 -> V_135 . V_469 ;
V_460 += V_462 ;
return V_460 -> V_470 ;
}
}
V_461 = F_144 ( 1 , & V_8 -> V_471 ) ;
V_461 = V_461 % V_8 -> V_467 ;
return V_461 ;
}
static void
F_145 ( struct V_12 * V_8 , struct V_143 * V_472 ,
struct V_143 * V_373 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_472 -> V_130 ;
struct V_4 * V_5 = V_472 -> V_5 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_13 * V_41 ;
int V_473 ;
unsigned long V_43 ;
struct V_401 * V_402 ;
struct V_44 * V_45 ;
T_1 V_443 = V_95 ;
V_8 -> V_474 ++ ;
V_41 = V_32 -> V_42 ;
if ( ! V_41 )
return;
V_45 = V_41 -> V_26 -> V_6 ;
V_32 -> V_48 = ( V_373 -> V_84 . V_111 . V_475 [ 4 ] & V_476 ) ;
V_32 -> V_128 = V_373 -> V_84 . V_477 ;
V_32 -> V_152 = V_373 -> V_101 & V_478 ;
#ifdef F_102
if ( V_32 -> V_243 ) {
struct V_223 * V_15 = NULL ;
V_15 = (struct V_223 * ) V_32 -> V_245 ;
switch ( V_32 -> V_243 ) {
case V_244 :
V_15 -> V_242 =
V_32 -> V_246 ;
break;
case V_258 :
V_15 -> V_257 =
( T_4 ) V_32 -> V_246 ;
break;
case V_479 :
V_15 -> V_349 =
( T_4 ) V_32 -> V_246 ;
break;
default:
break;
}
V_32 -> V_246 = 0 ;
V_32 -> V_243 = 0 ;
V_32 -> V_245 = NULL ;
}
#endif
if ( V_40 && F_133 ( V_40 ) )
F_146 ( & V_40 -> V_480 ) ;
if ( V_32 -> V_128 ) {
if ( V_32 -> V_128 == V_481 &&
( V_32 -> V_48 & V_482 ) )
V_32 -> V_128 = V_483 ;
else if ( V_32 -> V_128 >= V_484 )
V_32 -> V_128 = V_485 ;
if ( V_32 -> V_128 == V_486 &&
! V_32 -> V_93 -> V_400 &&
( V_32 -> V_93 -> V_398 & V_427 ) &&
! ( V_5 -> V_454 & V_455 ) )
V_443 = 0 ;
else
V_443 = V_95 | V_455 ;
F_39 ( V_5 , V_370 , V_443 ,
L_80
L_81
L_82
L_75 ,
V_41 -> V_14 [ 0 ] ,
V_41 -> V_26 ? V_41 -> V_26 -> V_448 : 0xffff ,
V_41 -> V_26 ? V_41 -> V_26 -> V_411 : 0xffff ,
V_32 -> V_128 , V_32 -> V_48 ,
V_5 -> V_487 ,
( V_40 ) ? V_40 -> V_233 : 0 ,
V_8 -> V_115 == V_457 ?
V_32 -> V_100 . V_150 : 0xffff ,
V_373 -> V_84 . V_458 ,
V_32 -> V_100 . V_84 . V_488 ) ;
switch ( V_32 -> V_128 ) {
case V_486 :
F_136 ( V_5 , V_32 , V_373 ) ;
break;
case V_489 :
case V_490 :
V_41 -> V_48 = F_117 ( V_491 , 0 ) ;
V_402 = F_134 ( V_8 ) ;
if ( ! V_402 )
break;
V_402 -> V_111 . V_492 . V_406 =
V_431 ;
V_402 -> V_111 . V_492 . V_408 =
( V_32 -> V_128 == V_489 ) ?
V_493 : V_494 ;
if ( V_40 && F_133 ( V_40 ) ) {
memcpy ( & V_402 -> V_111 . V_492 . V_412 ,
& V_40 -> V_237 ,
sizeof( struct V_238 ) ) ;
memcpy ( & V_402 -> V_111 . V_492 . V_413 ,
& V_40 -> V_414 ,
sizeof( struct V_238 ) ) ;
}
V_402 -> V_5 = V_5 ;
V_402 -> V_435 . V_495 =
V_496 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
F_65 ( & V_402 -> V_435 . V_436 ,
& V_8 -> V_437 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_25 ( V_8 ) ;
break;
case V_481 :
case V_497 :
if ( V_32 -> V_48 == V_498 ||
V_32 -> V_48 ==
V_499 ||
V_32 -> V_48 == V_500 ||
V_32 -> V_48 ==
V_501 ) {
V_41 -> V_48 = F_117 ( V_502 , 0 ) ;
break;
}
if ( V_32 -> V_48 == V_503 ||
V_32 -> V_48 == V_504 ||
V_32 -> V_48 == V_505 ||
V_32 -> V_48 == V_506 ) {
V_41 -> V_48 = F_117 ( V_507 , 0 ) ;
break;
}
if ( ( V_32 -> V_48 == V_508 ||
V_32 -> V_48 == V_509 ) &&
V_373 -> V_84 . V_119 . V_376 . V_378 ) {
if ( F_94 ( V_41 ) != V_229 ) {
F_118 ( V_8 , V_32 ,
V_373 ) ;
break;
} else {
F_39 ( V_5 , V_370 ,
V_21 ,
L_83
L_84 ) ;
}
}
if ( ( V_32 -> V_128 == V_497 )
&& ( V_8 -> V_115 == V_457 )
&& ( V_40 && F_133 ( V_40 ) ) ) {
F_57 ( V_8 , V_40 ,
V_32 -> V_100 . V_154 ,
0 , 0 ) ;
}
default:
V_41 -> V_48 = F_117 ( V_382 , 0 ) ;
break;
}
if ( ! V_40 || ! F_133 ( V_40 )
|| ( V_40 -> V_510 != V_511 ) )
V_41 -> V_48 = F_117 ( V_491 ,
V_404 ) ;
} else
V_41 -> V_48 = F_117 ( V_441 , 0 ) ;
if ( V_41 -> V_48 || V_32 -> V_93 -> V_416 ) {
T_1 * V_439 = ( T_1 * ) V_41 -> V_364 ;
F_39 ( V_5 , V_94 , V_95 ,
L_85
L_86 ,
V_41 -> V_26 -> V_448 , V_41 -> V_26 -> V_411 , V_41 ,
V_41 -> V_48 , * V_439 , * ( V_439 + 3 ) , V_41 -> V_512 ,
F_138 ( V_41 ) ) ;
}
F_18 ( V_8 , V_32 ) ;
if ( V_5 -> V_513 &&
F_24 ( V_49 , V_32 -> V_50 +
F_147 ( V_5 -> V_513 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_40 && F_133 ( V_40 ) ) {
if ( V_40 -> V_514 >
F_27 ( & V_40 -> V_480 ) &&
( F_27 ( & V_40 -> V_480 ) >
V_515 ) &&
( ( V_41 -> V_14 [ 0 ] == V_417 ) ||
( V_41 -> V_14 [ 0 ] == V_418 ) ) )
V_40 -> V_514 =
F_27 ( & V_40 -> V_480 ) ;
V_40 -> V_516 = V_49 ;
}
F_21 ( V_45 -> V_51 , V_43 ) ;
} else if ( V_40 && F_133 ( V_40 ) ) {
if ( ( V_40 -> V_514 < V_5 -> V_517 ) &&
F_24 ( V_49 , V_40 -> V_516 +
F_147 ( V_518 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
V_473 = V_40 -> V_514 * V_519
/ 100 ;
V_473 = V_473 ? V_473 : 1 ;
V_40 -> V_514 += V_473 ;
if ( V_40 -> V_514 > V_5 -> V_517 )
V_40 -> V_514 = V_5 -> V_517 ;
V_40 -> V_516 = V_49 ;
F_21 ( V_45 -> V_51 , V_43 ) ;
}
}
F_135 ( V_8 , V_32 ) ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
V_41 -> V_520 ( V_41 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_521 )
F_148 ( V_32 -> V_521 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_82 ( V_8 , V_32 ) ;
}
static void
F_149 ( V_190 * V_97 , struct V_92 * V_92 )
{
int V_47 , V_522 ;
for ( V_47 = 0 , V_522 = 0 ; V_47 < sizeof( struct V_92 ) ;
V_47 += sizeof( T_1 ) , V_522 ++ ) {
( ( T_1 * ) V_97 ) [ V_522 ] = F_91 ( ( ( T_1 * ) V_92 ) [ V_522 ] ) ;
}
}
static void
F_150 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
T_2 * V_202 = & V_32 -> V_100 . V_84 ;
struct V_143 * V_523 = & ( V_32 -> V_100 ) ;
int V_208 = V_13 -> V_209 ;
V_190 * V_524 ;
bool V_525 ;
T_1 V_341 ;
if ( ! V_40 || ! F_133 ( V_40 ) )
return;
V_32 -> V_93 -> V_416 = 0 ;
V_32 -> V_92 -> V_445 = 0 ;
F_151 ( V_32 -> V_42 -> V_26 -> V_411 ,
& V_32 -> V_92 -> V_526 ) ;
V_524 = & V_92 -> V_527 [ 0 ] ;
memcpy ( V_524 , V_13 -> V_14 , V_13 -> V_528 ) ;
if ( V_13 -> V_528 < V_529 ) {
V_524 += V_13 -> V_528 ;
memset ( V_524 , 0 , ( V_529 - V_13 -> V_528 ) ) ;
}
V_92 -> V_530 = V_531 ;
V_525 = ( V_8 -> V_115 == V_457 ) ;
V_523 -> V_84 . V_111 . V_217 . V_532 = 0 ;
if ( F_84 ( V_13 ) ) {
if ( V_208 == V_297 ) {
V_202 -> V_533 = V_534 ;
V_202 -> V_535 = V_536 ;
if ( V_5 -> V_537 &&
( V_40 -> V_538 & V_539 ) ) {
V_341 = F_92 ( V_13 ) ;
if ( V_341 < V_5 -> V_537 )
V_523 -> V_84 . V_111 . V_217 . V_532 = V_341 ;
else
V_523 -> V_84 . V_111 . V_217 . V_532 =
V_5 -> V_537 ;
}
V_92 -> V_540 = V_541 ;
V_8 -> V_542 ++ ;
} else {
V_202 -> V_533 = V_543 ;
V_202 -> V_535 = V_536 ;
V_92 -> V_540 = V_544 ;
V_8 -> V_545 ++ ;
}
} else {
V_202 -> V_533 = V_546 ;
V_202 -> V_111 . V_217 . V_218 = 0 ;
V_202 -> V_535 = 0 ;
V_92 -> V_540 = 0 ;
V_8 -> V_547 ++ ;
}
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) )
F_149 ( V_202 -> V_119 . V_120 . V_121 , V_92 ) ;
V_523 -> V_84 . V_458 = V_40 -> V_548 ;
if ( V_525 )
V_523 -> V_84 . V_458 =
V_8 -> V_135 . V_549 [ V_40 -> V_548 ] ;
if ( V_40 -> V_550 & V_551 )
V_523 -> V_84 . V_552 = 1 ;
else
V_523 -> V_84 . V_552 = 0 ;
V_523 -> V_84 . V_126 = ( V_40 -> V_550 & 0x0f ) ;
V_523 -> V_130 = V_32 ;
V_523 -> V_553 = F_145 ;
V_523 -> V_84 . V_554 = V_32 -> V_555 ;
V_523 -> V_5 = V_5 ;
}
static int
F_152 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
T_6 V_411 ,
V_190 V_556 )
{
struct V_143 * V_523 ;
T_2 * V_557 ;
struct V_92 * V_92 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_145 = V_38 -> V_40 ;
if ( ! V_145 || ! F_133 ( V_145 ) ||
V_145 -> V_510 != V_511 )
return 0 ;
V_523 = & ( V_32 -> V_100 ) ;
V_523 -> V_5 = V_5 ;
V_557 = & V_523 -> V_84 ;
V_92 = V_32 -> V_92 ;
memset ( V_92 , 0 , sizeof( struct V_92 ) ) ;
F_151 ( V_411 , & V_92 -> V_526 ) ;
V_92 -> V_445 = V_556 ;
if ( V_5 -> V_8 -> V_115 == 3 &&
! ( V_5 -> V_8 -> V_116 & V_117 ) )
F_149 ( V_557 -> V_119 . V_120 . V_121 , V_92 ) ;
V_557 -> V_533 = V_546 ;
V_557 -> V_458 = V_145 -> V_548 ;
if ( V_5 -> V_8 -> V_115 == V_457 ) {
V_557 -> V_458 =
V_5 -> V_8 -> V_135 . V_549 [ V_145 -> V_548 ] ;
}
V_557 -> V_552 = ( V_145 -> V_550 & V_551 ) ? 1 : 0 ;
V_557 -> V_126 = ( V_145 -> V_550 & 0x0f ) ;
V_557 -> V_535 = 0 ;
V_557 -> V_111 . V_217 . V_218 = 0 ;
if ( V_32 -> V_555 > 0xff ) {
V_557 -> V_554 = 0 ;
} else
V_557 -> V_554 = V_32 -> V_555 ;
if ( V_5 -> V_8 -> V_115 == V_457 )
F_14 ( V_5 -> V_8 , V_32 ) ;
return 1 ;
}
int
F_153 ( struct V_12 * V_8 , V_190 V_558 )
{
V_8 -> F_135 = F_135 ;
V_8 -> F_150 = F_150 ;
switch ( V_558 ) {
case V_559 :
V_8 -> F_76 = F_38 ;
V_8 -> F_130 = F_83 ;
V_8 -> F_131 = F_108 ;
V_8 -> F_82 = F_48 ;
V_8 -> F_81 = F_77 ;
break;
case V_560 :
V_8 -> F_76 = F_73 ;
V_8 -> F_130 = F_127 ;
V_8 -> F_131 = F_129 ;
V_8 -> F_82 = F_59 ;
V_8 -> F_81 = F_79 ;
break;
default:
F_4 ( V_8 , V_20 , V_561 ,
L_87 ,
V_558 ) ;
return - V_562 ;
break;
}
V_8 -> F_22 = F_22 ;
V_8 -> F_145 = F_145 ;
return 0 ;
}
static void
F_154 ( struct V_12 * V_8 ,
struct V_143 * V_563 ,
struct V_143 * V_564 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_563 -> V_130 ;
if ( V_32 )
F_82 ( V_8 , V_32 ) ;
return;
}
const char *
F_155 ( struct V_44 * V_6 )
{
struct V_4 * V_5 = (struct V_4 * ) V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_354 , V_565 = 0 ;
static char V_566 [ 384 ] ;
memset ( V_566 , 0 , 384 ) ;
if ( V_8 && V_8 -> V_210 ) {
strncpy ( V_566 , V_8 -> V_567 , 256 ) ;
V_354 = strlen ( V_566 ) ;
snprintf ( V_566 + V_354 ,
384 - V_354 ,
L_88 ,
V_8 -> V_210 -> V_568 -> V_569 ,
V_8 -> V_210 -> V_570 ,
V_8 -> V_210 -> V_571 ) ;
V_354 = strlen ( V_566 ) ;
if ( V_8 -> V_572 [ 0 ] ) {
snprintf ( V_566 + V_354 ,
384 - V_354 ,
L_89 ,
V_8 -> V_572 ) ;
}
V_354 = strlen ( V_566 ) ;
V_565 = F_156 ( V_8 ) ;
if ( V_565 != 0 )
snprintf ( V_566 + V_354 , 384 - V_354 ,
L_90 , V_565 ) ;
}
return V_566 ;
}
static T_7 void F_157 ( struct V_12 * V_8 )
{
unsigned long V_573 =
( V_49 + F_147 ( V_8 -> V_574 ) ) ;
if ( ! F_56 ( & V_8 -> V_155 . V_575 [ V_576 ] . V_577 ) )
F_158 ( & V_8 -> V_578 ,
V_573 ) ;
}
void F_159 ( struct V_12 * V_8 )
{
F_157 ( V_8 ) ;
}
void F_160 ( unsigned long V_524 )
{
struct V_12 * V_8 = (struct V_12 * ) V_524 ;
if ( V_8 -> V_579 & V_580 ) {
F_161 ( V_8 ,
& V_8 -> V_155 . V_575 [ V_576 ] , V_581 ) ;
if ( V_8 -> V_579 & V_582 )
F_157 ( V_8 ) ;
}
}
static int
F_162 ( struct V_44 * V_45 , struct V_13 * V_14 )
{
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_1 * V_38 ;
struct V_39 * V_145 ;
struct V_31 * V_32 ;
struct V_78 * V_79 = F_35 ( F_36 ( V_14 -> V_26 ) ) ;
int V_344 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
V_344 = F_163 ( V_79 ) ;
if ( V_344 ) {
V_14 -> V_48 = V_344 ;
goto V_583;
}
V_145 = V_38 -> V_40 ;
if ( ( F_94 ( V_14 ) != V_229 ) &&
( ! ( V_8 -> V_116 & V_117 ) ) ) {
F_4 ( V_8 , V_20 , V_21 ,
L_91
L_92
L_93 ,
V_14 -> V_14 [ 0 ] , F_94 ( V_14 ) ,
V_584 [ F_94 ( V_14 ) ] ) ;
goto V_583;
}
if ( ! V_145 || ! F_133 ( V_145 ) )
goto V_585;
if ( F_27 ( & V_145 -> V_480 ) >= V_145 -> V_514 )
goto V_585;
V_32 = F_81 ( V_8 , V_145 ) ;
if ( V_32 == NULL ) {
F_22 ( V_8 ) ;
F_39 ( V_5 , V_94 , V_444 ,
L_94
L_95 ) ;
goto V_586;
}
V_32 -> V_42 = V_14 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_555 = 0 ;
V_32 -> V_50 = V_49 ;
V_14 -> V_239 = ( unsigned char * ) V_32 ;
if ( F_94 ( V_14 ) != V_229 ) {
if ( V_5 -> V_8 -> V_187 ) {
F_39 ( V_5 ,
V_94 , V_587 ,
L_96
L_97 ,
V_584 [ F_94 ( V_14 ) ] ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_14 ) ,
F_120 ( V_14 -> V_383 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_344 = F_131 ( V_8 , V_32 ) ;
} else {
if ( V_5 -> V_8 -> V_187 ) {
F_39 ( V_5 ,
V_94 , V_587 ,
L_98
L_99 ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_14 ) ,
F_120 ( V_14 -> V_383 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_344 = F_130 ( V_8 , V_32 ) ;
}
if ( V_344 )
goto V_588;
F_150 ( V_5 , V_32 , V_145 ) ;
F_23 ( & V_145 -> V_480 ) ;
V_344 = F_164 ( V_8 , V_576 ,
& V_32 -> V_100 , V_589 ) ;
if ( V_344 ) {
F_146 ( & V_145 -> V_480 ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_100
L_101
L_82
L_102 ,
V_344 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_26 ? V_14 -> V_26 -> V_448 : 0xffff ,
V_14 -> V_26 ? V_14 -> V_26 -> V_411 : ( V_590 ) - 1 ,
V_5 -> V_487 , V_145 -> V_233 ,
V_8 -> V_115 == V_457 ?
V_32 -> V_100 . V_150 : 0xffff ,
V_32 -> V_100 . V_84 . V_458 ,
V_32 -> V_100 . V_84 . V_488 ,
V_32 -> V_100 . V_84 . V_554 ,
( T_1 )
( V_14 -> V_383 -> V_555 / 1000 ) ) ;
goto V_588;
}
if ( V_8 -> V_579 & V_580 ) {
F_161 ( V_8 ,
& V_8 -> V_155 . V_575 [ V_576 ] , V_581 ) ;
if ( V_8 -> V_579 & V_582 )
F_157 ( V_8 ) ;
}
return 0 ;
V_588:
F_135 ( V_8 , V_32 ) ;
F_82 ( V_8 , V_32 ) ;
V_586:
return V_591 ;
V_585:
return V_592 ;
V_583:
V_14 -> V_520 ( V_14 ) ;
return 0 ;
}
static int
F_165 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_143 * V_84 ;
struct V_143 * V_593 ;
struct V_31 * V_32 ;
T_2 * V_41 , * V_594 ;
int V_265 = V_595 , V_128 = 0 ;
struct V_147 * V_596 ;
int V_597 ;
unsigned long V_43 , V_598 ;
F_166 ( V_521 ) ;
V_128 = F_167 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_595 )
return V_128 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
if ( V_8 -> V_599 & V_600 ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_103
L_104 ) ;
return V_601 ;
}
V_32 = (struct V_31 * ) V_14 -> V_239 ;
if ( ! V_32 || ! V_32 -> V_42 ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_105
L_106 ,
V_595 , V_14 -> V_26 -> V_448 , V_14 -> V_26 -> V_411 ) ;
return V_595 ;
}
V_84 = & V_32 -> V_100 ;
if ( ! ( V_84 -> V_101 & V_602 ) ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_107
L_108 ) ;
return V_601 ;
}
if ( V_32 -> V_42 != V_14 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_109
L_110 ) ;
goto V_603;
}
F_104 ( V_84 -> V_130 != V_32 ) ;
if ( V_84 -> V_101 & V_604 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_111 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
goto V_605;
}
V_593 = F_168 ( V_8 ) ;
if ( V_593 == NULL ) {
V_265 = V_601 ;
goto V_603;
}
V_84 -> V_101 |= V_604 ;
V_41 = & V_84 -> V_84 ;
V_594 = & V_593 -> V_84 ;
V_594 -> V_111 . V_606 . V_607 = V_608 ;
V_594 -> V_111 . V_606 . V_609 = V_41 -> V_458 ;
if ( V_8 -> V_115 == V_457 )
V_594 -> V_111 . V_606 . V_610 = V_84 -> V_150 ;
else
V_594 -> V_111 . V_606 . V_610 = V_41 -> V_488 ;
V_594 -> V_123 = 1 ;
V_594 -> V_126 = V_41 -> V_126 ;
V_593 -> V_611 = V_84 -> V_611 ;
V_593 -> V_101 |= V_612 ;
if ( V_84 -> V_101 & V_390 )
V_593 -> V_101 |= V_390 ;
if ( F_169 ( V_8 ) )
V_594 -> V_533 = V_613 ;
else
V_594 -> V_533 = V_614 ;
V_593 -> V_553 = V_615 ;
V_593 -> V_5 = V_5 ;
if ( V_8 -> V_115 == V_457 ) {
V_596 = F_170 ( V_8 , V_84 ) ;
if ( V_596 == NULL ) {
V_265 = V_601 ;
goto V_603;
}
F_20 ( & V_596 -> V_616 , V_598 ) ;
V_597 = F_171 ( V_8 , V_596 -> V_617 ,
V_593 , 0 ) ;
F_21 ( & V_596 -> V_616 , V_598 ) ;
} else {
V_597 = F_171 ( V_8 , V_576 ,
V_593 , 0 ) ;
}
F_21 ( & V_8 -> V_64 , V_43 ) ;
if ( V_597 == V_618 ) {
F_172 ( V_8 , V_593 ) ;
V_265 = V_601 ;
goto V_280;
}
if ( V_8 -> V_579 & V_582 )
F_161 ( V_8 ,
& V_8 -> V_155 . V_575 [ V_576 ] , V_581 ) ;
V_605:
V_32 -> V_521 = & V_521 ;
F_173 ( V_521 ,
( V_32 -> V_42 != V_14 ) ,
F_147 ( 2 * V_5 -> V_619 * 1000 ) ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
V_32 -> V_521 = NULL ;
F_21 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_42 == V_14 ) {
V_265 = V_601 ;
F_39 ( V_5 , V_20 , V_95 ,
L_112
L_113
L_114 ,
V_84 -> V_150 , V_265 ,
V_14 -> V_26 -> V_448 , V_14 -> V_26 -> V_411 ) ;
}
goto V_280;
V_603:
F_21 ( & V_8 -> V_64 , V_43 ) ;
V_280:
F_39 ( V_5 , V_370 , V_95 ,
L_115
L_116 , V_265 , V_14 -> V_26 -> V_448 ,
V_14 -> V_26 -> V_411 ) ;
return V_265 ;
}
static char *
F_174 ( V_190 V_556 )
{
switch ( V_556 ) {
case V_620 :
return L_117 ;
case V_621 :
return L_118 ;
case V_622 :
return L_119 ;
case V_623 :
return L_120 ;
case V_624 :
return L_121 ;
case V_625 :
return L_122 ;
case V_626 :
return L_123 ;
default:
return L_124 ;
}
}
static int
F_175 ( struct V_4 * V_5 , struct V_31 * V_32 )
{
struct V_93 * V_396 = V_32 -> V_93 ;
T_1 V_627 ;
T_1 V_628 ;
V_190 V_629 ;
int V_265 = V_601 ;
if ( V_396 == NULL )
F_39 ( V_5 , V_94 , V_95 ,
L_125 ) ;
else {
V_627 = V_396 -> V_398 ;
V_628 = F_96 ( V_396 -> V_447 ) ;
V_629 = V_396 -> V_449 ;
F_39 ( V_5 , V_94 ,
V_95 ,
L_126
L_127 ,
V_627 ,
V_628 , V_629 ) ;
if ( ( V_396 -> V_398 & V_446 ) && ( V_628 == 8 ) ) {
switch ( V_629 ) {
case V_450 :
F_39 ( V_5 , V_94 , V_95 ,
L_128 ) ;
V_265 = V_595 ;
break;
case V_630 :
F_39 ( V_5 , V_94 , V_95 ,
L_129
L_130 ) ;
break;
case V_631 :
F_39 ( V_5 , V_94 , V_95 ,
L_131
L_132 ) ;
break;
case V_632 :
F_39 ( V_5 , V_94 , V_95 ,
L_133
L_134 ) ;
break;
}
}
}
return V_265 ;
}
static int
F_176 ( struct V_4 * V_5 , struct V_13 * V_14 ,
unsigned int V_633 , T_6 V_634 ,
V_190 V_556 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_32 ;
struct V_143 * V_144 ;
struct V_143 * V_635 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
int V_265 ;
int V_128 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 || ! V_38 -> V_40 || ! F_133 ( V_38 -> V_40 ) )
return V_601 ;
V_40 = V_38 -> V_40 ;
V_32 = F_81 ( V_8 , V_40 ) ;
if ( V_32 == NULL )
return V_601 ;
V_32 -> V_555 = V_8 -> V_636 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_42 = V_14 ;
V_128 = F_152 ( V_5 , V_32 , V_634 ,
V_556 ) ;
if ( ! V_128 ) {
F_82 ( V_8 , V_32 ) ;
return V_601 ;
}
V_144 = & V_32 -> V_100 ;
V_635 = F_177 ( V_8 ) ;
if ( V_635 == NULL ) {
F_82 ( V_8 , V_32 ) ;
return V_601 ;
}
V_144 -> V_553 = F_154 ;
F_39 ( V_5 , V_94 , V_95 ,
L_135
L_136 ,
F_174 ( V_556 ) , V_633 , V_634 ,
V_40 -> V_548 , V_40 -> V_538 , V_144 -> V_150 ,
V_144 -> V_101 ) ;
V_128 = F_178 ( V_8 , V_576 ,
V_144 , V_635 , V_32 -> V_555 ) ;
if ( ( V_128 != V_637 ) ||
( V_635 -> V_84 . V_477 != V_129 ) ) {
if ( V_128 != V_637 ||
V_635 -> V_84 . V_477 != V_486 )
F_39 ( V_5 , V_20 , V_95 ,
L_137
L_138 ,
F_174 ( V_556 ) ,
V_633 , V_634 ,
V_635 -> V_84 . V_477 ,
V_635 -> V_84 . V_111 . V_475 [ 4 ] ,
V_144 -> V_101 ) ;
if ( V_128 == V_637 ) {
if ( V_635 -> V_84 . V_477 == V_486 )
V_265 = F_175 ( V_5 , V_32 ) ;
else
V_265 = V_601 ;
} else if ( V_128 == V_638 ) {
V_265 = V_639 ;
} else {
V_265 = V_601 ;
}
} else
V_265 = V_595 ;
F_172 ( V_8 , V_635 ) ;
if ( V_265 != V_639 )
F_82 ( V_8 , V_32 ) ;
return V_265 ;
}
static int
F_179 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned long V_640 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_39 ( V_5 , V_94 , V_95 ,
L_139 , V_38 ) ;
return V_601 ;
}
V_40 = V_38 -> V_40 ;
V_640 = F_147 ( 2 * V_5 -> V_619 * 1000 ) + V_49 ;
while ( F_24 ( V_640 , V_49 ) ) {
if ( ! V_40 || ! F_133 ( V_40 ) )
return V_601 ;
if ( V_40 -> V_510 == V_511 )
return V_595 ;
F_180 ( F_147 ( 500 ) ) ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 )
return V_601 ;
V_40 = V_38 -> V_40 ;
}
if ( ! V_40 || ! F_133 ( V_40 ) ||
( V_40 -> V_510 != V_511 ) )
return V_601 ;
return V_595 ;
}
static int
F_181 ( struct V_4 * V_5 , T_4 V_633 ,
T_6 V_634 , T_8 V_641 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_640 ;
int V_642 ;
V_642 = F_182 ( V_5 , V_633 , V_634 , V_641 ) ;
if ( V_642 )
F_183 ( V_5 ,
& V_8 -> V_155 . V_575 [ V_576 ] ,
V_633 , V_634 , V_641 ) ;
V_640 = F_147 ( 2 * V_5 -> V_619 * 1000 ) + V_49 ;
while ( F_24 ( V_640 , V_49 ) && V_642 ) {
F_180 ( F_147 ( 20 ) ) ;
V_642 = F_182 ( V_5 , V_633 , V_634 , V_641 ) ;
}
if ( V_642 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_140 ,
( ( V_641 == V_643 ) ? L_141 :
( ( V_641 == V_644 ) ? L_142 :
( ( V_641 == V_645 ) ? L_143 : L_144 ) ) ) ,
V_642 ) ;
return V_601 ;
}
return V_595 ;
}
static int
F_184 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_633 = V_14 -> V_26 -> V_448 ;
T_6 V_634 = V_14 -> V_26 -> V_411 ;
struct V_646 V_420 ;
int V_128 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 || ! V_38 -> V_40 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_145 ,
V_38 ) ;
return V_601 ;
}
V_40 = V_38 -> V_40 ;
V_128 = F_167 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_595 )
return V_128 ;
V_128 = F_179 ( V_5 , V_14 ) ;
if ( V_128 == V_601 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_146 , V_38 ) ;
return V_601 ;
}
V_420 . V_406 = V_407 ;
V_420 . V_408 = V_647 ;
V_420 . V_411 = V_634 ;
memcpy ( V_420 . V_412 , & V_40 -> V_237 , sizeof( struct V_238 ) ) ;
memcpy ( V_420 . V_413 , & V_40 -> V_414 , sizeof( struct V_238 ) ) ;
F_185 ( V_45 , F_186 () ,
sizeof( V_420 ) , ( char * ) & V_420 , V_648 ) ;
V_128 = F_176 ( V_5 , V_14 , V_633 , V_634 ,
V_623 ) ;
F_39 ( V_5 , V_20 , V_95 ,
L_147
L_148 , V_633 , V_634 , V_128 ) ;
if ( V_128 == V_595 )
V_128 = F_181 ( V_5 , V_633 , V_634 ,
V_643 ) ;
return V_128 ;
}
static int
F_187 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_633 = V_14 -> V_26 -> V_448 ;
T_6 V_634 = V_14 -> V_26 -> V_411 ;
struct V_646 V_420 ;
int V_128 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_149 , V_38 ) ;
return V_601 ;
}
V_40 = V_38 -> V_40 ;
V_128 = F_167 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_595 )
return V_128 ;
V_128 = F_179 ( V_5 , V_14 ) ;
if ( V_128 == V_601 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_150 , V_38 ) ;
if ( V_40 ) {
F_70 ( V_45 -> V_51 ) ;
V_40 -> V_538 &= ~ V_649 ;
V_40 -> V_550 &= ~ V_551 ;
F_72 ( V_45 -> V_51 ) ;
}
F_181 ( V_5 , V_633 , V_634 ,
V_644 ) ;
return V_650 ;
}
V_420 . V_406 = V_407 ;
V_420 . V_408 = V_651 ;
V_420 . V_411 = 0 ;
memcpy ( V_420 . V_412 , & V_40 -> V_237 , sizeof( struct V_238 ) ) ;
memcpy ( V_420 . V_413 , & V_40 -> V_414 , sizeof( struct V_238 ) ) ;
F_185 ( V_45 , F_186 () ,
sizeof( V_420 ) , ( char * ) & V_420 , V_648 ) ;
V_128 = F_176 ( V_5 , V_14 , V_633 , V_634 ,
V_624 ) ;
F_39 ( V_5 , V_20 , V_95 ,
L_151
L_148 , V_633 , V_634 , V_128 ) ;
if ( V_128 == V_595 )
V_128 = F_181 ( V_5 , V_633 , V_634 ,
V_644 ) ;
return V_128 ;
}
static int
F_188 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_39 * V_145 = NULL ;
struct V_646 V_420 ;
int V_652 ;
int V_265 = V_595 , V_128 , V_47 ;
V_420 . V_406 = V_407 ;
V_420 . V_408 = V_653 ;
V_420 . V_411 = 0 ;
memcpy ( V_420 . V_412 , & V_5 -> V_654 , sizeof( struct V_238 ) ) ;
memcpy ( V_420 . V_413 , & V_5 -> V_655 , sizeof( struct V_238 ) ) ;
F_185 ( V_45 , F_186 () ,
sizeof( V_420 ) , ( char * ) & V_420 , V_648 ) ;
V_128 = F_167 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_595 )
return V_128 ;
for ( V_47 = 0 ; V_47 < V_656 ; V_47 ++ ) {
V_652 = 0 ;
F_70 ( V_45 -> V_51 ) ;
F_189 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_133 ( V_145 ) )
continue;
if ( V_5 -> V_8 -> V_657 &&
( V_145 -> V_550 & V_551 ) )
continue;
if ( V_145 -> V_510 == V_511 &&
V_145 -> V_658 == V_47 &&
V_145 -> V_79 &&
V_145 -> V_659 & V_660 ) {
V_652 = 1 ;
break;
}
}
F_72 ( V_45 -> V_51 ) ;
if ( ! V_652 )
continue;
V_128 = F_176 ( V_5 , V_14 ,
V_47 , 0 , V_624 ) ;
if ( V_128 != V_595 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_152 ,
V_47 ) ;
V_265 = V_601 ;
}
}
V_128 = F_181 ( V_5 , 0 , 0 , V_645 ) ;
if ( V_128 != V_595 )
V_265 = V_601 ;
F_39 ( V_5 , V_20 , V_95 ,
L_153 , V_265 ) ;
return V_265 ;
}
static int
F_190 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_179 , V_265 = V_595 ;
F_39 ( V_5 , V_20 , V_95 ,
L_154 ) ;
F_191 ( V_8 , V_661 ) ;
F_192 ( V_8 ) ;
V_179 = F_193 ( V_8 ) ;
if ( V_179 )
V_265 = V_601 ;
V_179 = F_194 ( V_8 ) ;
if ( V_179 )
V_265 = V_601 ;
F_195 ( V_8 ) ;
if ( V_265 == V_601 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_155 ) ;
F_196 ( V_8 ) ;
}
return V_265 ;
}
static int
F_197 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_78 * V_79 = F_35 ( F_36 ( V_3 ) ) ;
T_1 V_662 = 0 ;
T_1 V_80 = 0 ;
int V_663 = 0 ;
T_1 V_664 ;
struct V_10 * V_665 ;
unsigned long V_43 ;
struct V_238 V_666 ;
if ( ! V_79 || F_163 ( V_79 ) )
return - V_667 ;
if ( V_8 -> V_9 ) {
F_198 ( V_79 -> V_668 , V_666 . V_235 . V_236 ) ;
F_20 ( & V_8 -> V_669 , V_43 ) ;
V_665 = F_199 ( V_8 ,
& V_8 -> V_670 ,
& V_5 -> V_654 ,
& V_666 ,
V_3 -> V_411 ) ;
if ( ! V_665 ) {
F_21 ( & V_8 -> V_669 , V_43 ) ;
V_665 = F_200 ( V_8 ,
& V_5 -> V_654 ,
& V_666 ,
V_3 -> V_411 ,
V_8 -> V_671 ,
true ) ;
if ( ! V_665 )
return - V_672 ;
F_20 ( & V_8 -> V_669 , V_43 ) ;
F_65 ( & V_665 -> V_673 , & V_8 -> V_670 ) ;
}
V_665 -> V_11 = V_79 -> V_674 ;
V_665 -> V_675 = true ;
F_21 ( & V_8 -> V_669 , V_43 ) ;
V_3 -> V_7 = V_665 ;
} else {
V_3 -> V_7 = V_79 -> V_674 ;
}
V_664 = F_201 ( & V_8 -> V_664 ) ;
V_662 = V_8 -> V_676 ;
V_80 = V_5 -> V_677 + 2 ;
if ( ( V_664 * ( V_5 -> V_677 + 2 ) ) < V_662 )
return 0 ;
if ( V_662 >= V_8 -> V_678 - V_679 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_156
L_157 , V_662 ) ;
return 0 ;
} else if ( V_662 + V_80 >
V_8 -> V_678 - V_679 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_158
L_159
L_160 ,
V_80 , V_8 -> V_678 ,
( V_8 -> V_678 - V_662 ) ) ;
V_80 = V_8 -> V_678 - V_662 ;
}
V_663 = F_76 ( V_5 , V_80 ) ;
if ( V_80 != V_663 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_161
L_162
L_163 ,
V_80 , V_663 ) ;
}
if ( V_663 > 0 )
V_8 -> V_676 += V_663 ;
return 0 ;
}
static int
F_202 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
F_31 ( V_3 , V_5 -> V_677 ) ;
if ( V_8 -> V_579 & V_580 ) {
F_161 ( V_8 ,
& V_8 -> V_155 . V_575 [ V_576 ] , V_581 ) ;
if ( V_8 -> V_579 & V_582 )
F_157 ( V_8 ) ;
}
return 0 ;
}
static void
F_203 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_43 ;
struct V_10 * V_665 = V_3 -> V_7 ;
F_146 ( & V_8 -> V_664 ) ;
if ( ( V_8 -> V_9 ) && ( V_665 ) ) {
F_20 ( & V_8 -> V_669 , V_43 ) ;
V_665 -> V_675 = false ;
if ( ! V_665 -> V_388 )
F_204 ( V_8 , V_665 ) ;
F_21 ( & V_8 -> V_669 , V_43 ) ;
}
V_3 -> V_7 = NULL ;
return;
}
struct V_10 *
F_200 ( struct V_12 * V_8 , struct V_238 * V_680 ,
struct V_238 * V_666 , T_6 V_411 ,
T_1 V_681 , bool V_682 )
{
struct V_10 * V_683 ;
int V_684 ;
if ( F_86 ( ! V_8 ) || ! V_680 || ! V_666 ||
! ( V_8 -> V_9 ) )
return NULL ;
if ( V_682 )
V_684 = V_685 ;
else
V_684 = V_96 ;
V_683 = F_205 ( V_8 -> V_686 , V_684 ) ;
if ( ! V_683 )
return NULL ;
F_78 ( & V_683 -> V_673 ) ;
V_683 -> V_11 = NULL ;
memcpy ( & V_683 -> V_687 . V_680 , V_680 ,
sizeof( struct V_238 ) ) ;
memcpy ( & V_683 -> V_687 . V_666 , V_666 ,
sizeof( struct V_238 ) ) ;
V_683 -> V_687 . V_411 = V_411 ;
V_683 -> V_388 = false ;
V_683 -> V_391 = V_681 ;
V_683 -> V_675 = false ;
return V_683 ;
}
void
F_204 ( struct V_12 * V_8 ,
struct V_10 * V_683 )
{
if ( F_86 ( ! V_8 ) || ! V_683 ||
! ( V_8 -> V_9 ) )
return;
if ( ! F_56 ( & V_683 -> V_673 ) )
F_55 ( & V_683 -> V_673 ) ;
F_206 ( V_683 , V_8 -> V_686 ) ;
return;
}
struct V_10 *
F_199 ( struct V_12 * V_8 , struct V_160 * V_151 ,
struct V_238 * V_680 ,
struct V_238 * V_666 , T_6 V_411 )
{
struct V_10 * V_683 ;
if ( F_86 ( ! V_8 ) || ! V_151 || ! V_680 || ! V_666 ||
! V_8 -> V_9 )
return NULL ;
F_189 (lun_info, list, listentry) {
if ( ( memcmp ( & V_683 -> V_687 . V_680 , V_680 ,
sizeof( struct V_238 ) ) == 0 ) &&
( memcmp ( & V_683 -> V_687 . V_666 , V_666 ,
sizeof( struct V_238 ) ) == 0 ) &&
( V_683 -> V_687 . V_411 == V_411 ) )
return V_683 ;
}
return NULL ;
}
bool
F_207 ( struct V_12 * V_8 , struct V_238 * V_680 ,
struct V_238 * V_666 , T_6 * V_688 ,
struct V_238 * V_689 ,
struct V_238 * V_690 ,
T_6 * V_691 ,
T_1 * V_692 ,
T_1 * V_693 )
{
unsigned long V_43 ;
struct V_10 * V_683 ;
struct V_694 * V_687 ;
T_6 V_411 ;
bool V_196 = false ;
if ( F_86 ( ! V_8 ) || ! V_680 || ! V_666 ||
! V_688 || ! V_689 ||
! V_690 || ! V_691 || ! V_692 ||
( * V_688 == V_695 ) ||
! V_8 -> V_9 )
return false ;
V_411 = * V_688 ;
* V_691 = V_695 ;
* V_688 = V_695 ;
F_20 ( & V_8 -> V_669 , V_43 ) ;
F_189 (lun_info, &phba->luns, listentry) {
if ( ( ( F_208 ( V_680 -> V_235 . V_236 ) == 0 ) ||
( memcmp ( & V_683 -> V_687 . V_680 , V_680 ,
sizeof( struct V_238 ) ) == 0 ) ) &&
( ( F_208 ( V_666 -> V_235 . V_236 ) == 0 ) ||
( memcmp ( & V_683 -> V_687 . V_666 , V_666 ,
sizeof( struct V_238 ) ) == 0 ) ) &&
( V_683 -> V_388 ) ) {
V_687 = & V_683 -> V_687 ;
if ( ( ! V_196 ) &&
( ( V_411 == V_696 ) ||
( V_687 -> V_411 == V_411 ) ) ) {
* V_691 = V_687 -> V_411 ;
memcpy ( V_689 ,
& V_687 -> V_680 ,
sizeof( struct V_238 ) ) ;
memcpy ( V_690 ,
& V_687 -> V_666 ,
sizeof( struct V_238 ) ) ;
if ( V_683 -> V_675 )
* V_692 =
V_697 ;
else
* V_692 = 0 ;
* V_693 = V_683 -> V_391 ;
if ( V_8 -> V_698 & V_699 )
memset ( V_680 , 0x0 ,
sizeof( struct V_238 ) ) ;
if ( V_8 -> V_698 & V_700 )
memset ( V_666 , 0x0 ,
sizeof( struct V_238 ) ) ;
V_196 = true ;
} else if ( V_196 ) {
* V_688 = V_687 -> V_411 ;
memcpy ( V_680 , & V_687 -> V_680 ,
sizeof( struct V_238 ) ) ;
memcpy ( V_666 , & V_687 -> V_666 ,
sizeof( struct V_238 ) ) ;
break;
}
}
}
F_21 ( & V_8 -> V_669 , V_43 ) ;
return V_196 ;
}
bool
F_209 ( struct V_12 * V_8 , struct V_238 * V_680 ,
struct V_238 * V_666 , T_6 V_411 , V_190 V_681 )
{
struct V_10 * V_683 ;
unsigned long V_43 ;
if ( F_86 ( ! V_8 ) || ! V_680 || ! V_666 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_669 , V_43 ) ;
V_683 = F_199 ( V_8 , & V_8 -> V_670 , V_680 ,
V_666 , V_411 ) ;
if ( V_683 ) {
if ( ! V_683 -> V_388 )
V_683 -> V_388 = true ;
V_683 -> V_391 = V_681 ;
F_21 ( & V_8 -> V_669 , V_43 ) ;
return true ;
}
V_683 = F_200 ( V_8 , V_680 , V_666 , V_411 ,
V_681 , false ) ;
if ( V_683 ) {
V_683 -> V_388 = true ;
V_683 -> V_391 = V_681 ;
V_683 -> V_675 = false ;
F_65 ( & V_683 -> V_673 , & V_8 -> V_670 ) ;
F_21 ( & V_8 -> V_669 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_669 , V_43 ) ;
return false ;
}
bool
F_210 ( struct V_12 * V_8 , struct V_238 * V_680 ,
struct V_238 * V_666 , T_6 V_411 , V_190 V_681 )
{
struct V_10 * V_683 ;
unsigned long V_43 ;
if ( F_86 ( ! V_8 ) || ! V_680 || ! V_666 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_669 , V_43 ) ;
V_683 = F_199 ( V_8 ,
& V_8 -> V_670 , V_680 ,
V_666 , V_411 ) ;
if ( V_683 ) {
V_683 -> V_388 = false ;
V_683 -> V_391 = V_681 ;
if ( ! V_683 -> V_675 )
F_204 ( V_8 , V_683 ) ;
F_21 ( & V_8 -> V_669 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_669 , V_43 ) ;
return false ;
}
static int
F_211 ( struct V_44 * V_45 , struct V_13 * V_14 )
{
return V_591 ;
}
static int
F_212 ( struct V_13 * V_14 )
{
return V_601 ;
}
static int
F_213 ( struct V_2 * V_3 )
{
return - V_562 ;
}
