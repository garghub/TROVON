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
memset ( V_81 -> V_97 , 0 , V_8 -> V_91 ) ;
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
F_20 ( & V_8 -> V_64 , V_132 ) ;
F_50 ( & V_8 -> V_133 . V_134 ) ;
F_51 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_81 -> V_38 && V_81 -> V_38 -> V_40
&& V_81 -> V_38 -> V_40 -> V_5 == V_5 )
V_81 -> V_38 = NULL ;
}
F_52 ( & V_8 -> V_133 . V_134 ) ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
}
void
F_53 ( struct V_12 * V_8 ,
struct V_135 * V_136 )
{
T_4 V_137 = F_54 ( V_138 , V_136 ) ;
T_4 V_139 = F_54 ( V_140 , V_136 ) ;
struct V_31 * V_81 , * V_131 ;
unsigned long V_132 = 0 ;
struct V_141 * V_142 ;
int V_47 ;
struct V_39 * V_143 ;
int V_144 = 0 ;
struct V_145 * V_146 = & V_8 -> V_147 . V_148 [ V_149 ] ;
F_20 ( & V_8 -> V_64 , V_132 ) ;
F_50 ( & V_8 -> V_133 . V_134 ) ;
F_51 (psb, next_psb,
&phba->sli4_hba.lpfc_abts_scsi_buf_list, list) {
if ( V_81 -> V_100 . V_150 == V_137 ) {
F_55 ( & V_81 -> V_151 ) ;
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
F_52 (
& V_8 -> V_133 . V_134 ) ;
if ( V_81 -> V_38 && V_81 -> V_38 -> V_40 )
V_143 = V_81 -> V_38 -> V_40 ;
else
V_143 = NULL ;
V_144 = F_56 ( & V_8 -> V_153 ) ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
if ( V_143 ) {
F_57 ( V_8 , V_143 ,
V_81 -> V_100 . V_154 , V_139 , 1 ) ;
F_58 ( V_8 , V_143 , V_136 ) ;
}
F_59 ( V_8 , V_81 ) ;
if ( V_144 )
F_25 ( V_8 ) ;
return;
}
}
F_52 ( & V_8 -> V_133 . V_134 ) ;
for ( V_47 = 1 ; V_47 <= V_8 -> V_147 . V_155 ; V_47 ++ ) {
V_142 = V_8 -> V_147 . V_156 [ V_47 ] ;
if ( ! ( V_142 -> V_101 & V_102 ) ||
( V_142 -> V_101 & V_157 ) )
continue;
if ( V_142 -> V_150 != V_137 )
continue;
V_81 = F_60 ( V_142 , struct V_31 , V_100 ) ;
V_81 -> V_152 = 0 ;
F_21 ( & V_8 -> V_64 , V_132 ) ;
if ( ! F_56 ( & V_146 -> V_158 ) )
F_25 ( V_8 ) ;
return;
}
F_21 ( & V_8 -> V_64 , V_132 ) ;
}
static int
F_61 ( struct V_12 * V_8 ,
struct V_159 * V_160 , int V_161 )
{
struct V_31 * V_81 , * V_162 ;
int V_128 , V_163 ;
int V_164 = 0 , V_165 = 0 , V_166 = 0 , V_167 = 0 ;
T_3 V_168 ;
int V_169 = V_170 ;
F_62 ( V_171 ) ;
F_62 ( V_172 ) ;
F_62 ( V_173 ) ;
if ( V_161 <= 0 )
return - V_174 ;
V_163 = V_8 -> V_91 -
( sizeof( struct V_92 ) + sizeof( struct V_93 ) ) ;
F_51 (psb, psb_next, post_sblist, list) {
F_63 ( & V_81 -> V_151 ) ;
V_165 ++ ;
if ( ( V_169 != V_170 ) &&
( V_81 -> V_100 . V_150 != V_169 + 1 ) ) {
F_64 ( & V_171 , & V_172 ) ;
V_164 = V_165 - 1 ;
F_65 ( & V_81 -> V_151 , & V_171 ) ;
V_165 = 1 ;
} else {
F_65 ( & V_81 -> V_151 , & V_171 ) ;
if ( V_165 == V_175 ) {
F_64 ( & V_171 , & V_172 ) ;
V_164 = V_165 ;
V_165 = 0 ;
}
}
V_166 ++ ;
V_169 = V_81 -> V_100 . V_150 ;
if ( V_166 == V_161 ) {
if ( V_164 == 0 ) {
F_64 ( & V_171 , & V_172 ) ;
V_164 = V_165 ;
} else if ( V_165 == 1 ) {
if ( V_163 > V_176 )
V_168 = V_81 -> V_177 +
V_176 ;
else
V_168 = 0 ;
V_128 = F_66 ( V_8 ,
V_81 -> V_177 ,
V_168 ,
V_81 -> V_100 . V_150 ) ;
if ( V_128 ) {
V_81 -> V_152 = 1 ;
} else {
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
V_167 ++ ;
}
F_65 ( & V_81 -> V_151 , & V_173 ) ;
}
}
if ( V_164 == 0 )
continue;
V_128 = F_67 ( V_8 , & V_172 ,
V_164 ) ;
if ( V_165 == 0 )
V_169 = V_170 ;
V_164 = 0 ;
while ( ! F_56 ( & V_172 ) ) {
F_68 ( & V_172 , V_81 ,
struct V_31 , V_151 ) ;
if ( V_128 ) {
V_81 -> V_152 = 1 ;
} else {
V_81 -> V_152 = 0 ;
V_81 -> V_128 = V_129 ;
V_167 ++ ;
}
F_65 ( & V_81 -> V_151 , & V_173 ) ;
}
}
while ( ! F_56 ( & V_173 ) ) {
F_68 ( & V_173 , V_81 ,
struct V_31 , V_151 ) ;
F_59 ( V_8 , V_81 ) ;
}
return V_167 ;
}
int
F_69 ( struct V_12 * V_8 )
{
F_62 ( V_160 ) ;
int V_167 , V_178 = 0 ;
F_70 ( & V_8 -> V_179 ) ;
F_50 ( & V_8 -> V_180 ) ;
F_64 ( & V_8 -> V_181 , & V_160 ) ;
F_71 ( & V_8 -> V_182 , & V_160 ) ;
F_52 ( & V_8 -> V_180 ) ;
F_72 ( & V_8 -> V_179 ) ;
if ( ! F_56 ( & V_160 ) ) {
V_167 = F_61 ( V_8 , & V_160 ,
V_8 -> V_133 . V_183 ) ;
if ( V_167 == 0 )
V_178 = - V_184 ;
}
return V_178 ;
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
T_4 V_88 , V_185 = 0 ;
int V_89 , V_167 , V_163 ;
F_62 ( V_171 ) ;
F_62 ( V_160 ) ;
F_62 ( V_173 ) ;
V_163 = V_8 -> V_91 -
( sizeof( struct V_92 ) + sizeof( struct V_93 ) ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_6 ,
V_80 , V_8 -> V_91 , V_163 ,
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
memset ( V_81 -> V_97 , 0 , V_8 -> V_91 ) ;
if ( V_8 -> V_186 && ( ( ( unsigned long ) ( V_81 -> V_97 ) &
( unsigned long ) ( V_187 - 1 ) ) != 0 ) ) {
F_44 ( V_8 -> V_98 ,
V_81 -> V_97 , V_81 -> V_99 ) ;
F_42 ( V_81 ) ;
break;
}
V_185 = F_74 ( V_8 ) ;
if ( V_185 == V_170 ) {
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
L_8 , V_185 ) ;
F_75 ( V_8 , V_185 ) ;
break;
}
V_81 -> V_100 . V_154 = V_185 ;
V_81 -> V_100 . V_150 = V_8 -> V_133 . V_188 [ V_185 ] ;
V_81 -> V_100 . V_101 |= V_102 ;
V_81 -> V_35 = V_81 -> V_97 ;
V_81 -> V_92 = ( V_81 -> V_97 + V_163 ) ;
V_81 -> V_93 = (struct V_93 * ) ( ( V_189 * ) V_81 -> V_92 +
sizeof( struct V_92 ) ) ;
V_34 = (struct V_33 * ) V_81 -> V_35 ;
V_87 = V_81 -> V_99 ;
V_85 = ( V_81 -> V_99 + V_163 ) ;
V_86 = V_85 + sizeof( struct V_92 ) ;
V_34 -> V_190 = F_17 ( F_45 ( V_85 ) ) ;
V_34 -> V_191 = F_17 ( F_46 ( V_85 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_192 = F_17 ( sizeof( struct V_92 ) ) ;
V_34 ++ ;
V_34 -> V_190 = F_17 ( F_45 ( V_86 ) ) ;
V_34 -> V_191 = F_17 ( F_46 ( V_86 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_192 = F_17 ( sizeof( struct V_93 ) ) ;
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
V_81 -> V_177 = V_87 ;
F_65 ( & V_81 -> V_151 , & V_160 ) ;
F_70 ( & V_8 -> V_179 ) ;
V_8 -> V_133 . V_183 ++ ;
F_72 ( & V_8 -> V_179 ) ;
}
F_4 ( V_8 , V_94 , V_21 ,
L_9
L_10 , V_89 , V_80 ) ;
if ( ! F_56 ( & V_160 ) )
V_167 = F_61 ( V_8 ,
& V_160 , V_89 ) ;
else
V_167 = 0 ;
return V_167 ;
}
static inline int
F_76 ( struct V_4 * V_5 , int V_80 )
{
return V_5 -> V_8 -> F_76 ( V_5 , V_80 ) ;
}
static struct V_31 *
F_77 ( struct V_12 * V_8 , struct V_39 * V_143 )
{
struct V_31 * V_32 = NULL ;
struct V_159 * V_193 = & V_8 -> V_181 ;
unsigned long V_132 = 0 ;
F_20 ( & V_8 -> V_179 , V_132 ) ;
F_68 ( V_193 , V_32 , struct V_31 ,
V_151 ) ;
if ( ! V_32 ) {
F_50 ( & V_8 -> V_180 ) ;
F_71 ( & V_8 -> V_182 ,
& V_8 -> V_181 ) ;
F_78 ( & V_8 -> V_182 ) ;
F_68 ( V_193 , V_32 ,
struct V_31 , V_151 ) ;
F_52 ( & V_8 -> V_180 ) ;
}
F_21 ( & V_8 -> V_179 , V_132 ) ;
return V_32 ;
}
static struct V_31 *
F_79 ( struct V_12 * V_8 , struct V_39 * V_143 )
{
struct V_31 * V_32 , * V_194 ;
unsigned long V_132 = 0 ;
int V_195 = 0 ;
F_20 ( & V_8 -> V_179 , V_132 ) ;
F_51 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_80 ( V_8 , V_143 ,
V_32 -> V_100 . V_154 ) )
continue;
F_55 ( & V_32 -> V_151 ) ;
V_195 = 1 ;
break;
}
if ( ! V_195 ) {
F_50 ( & V_8 -> V_180 ) ;
F_71 ( & V_8 -> V_182 ,
& V_8 -> V_181 ) ;
F_78 ( & V_8 -> V_182 ) ;
F_52 ( & V_8 -> V_180 ) ;
F_51 (lpfc_cmd, lpfc_cmd_next,
&phba->lpfc_scsi_buf_list_get, list) {
if ( F_80 (
V_8 , V_143 , V_32 -> V_100 . V_154 ) )
continue;
F_55 ( & V_32 -> V_151 ) ;
V_195 = 1 ;
break;
}
}
F_21 ( & V_8 -> V_179 , V_132 ) ;
if ( ! V_195 )
return NULL ;
return V_32 ;
}
static struct V_31 *
F_81 ( struct V_12 * V_8 , struct V_39 * V_143 )
{
return V_8 -> F_81 ( V_8 , V_143 ) ;
}
static void
F_48 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
unsigned long V_132 = 0 ;
V_81 -> V_196 = 0 ;
V_81 -> V_197 = 0 ;
V_81 -> V_198 = 0 ;
F_20 ( & V_8 -> V_180 , V_132 ) ;
V_81 -> V_42 = NULL ;
V_81 -> V_100 . V_101 = V_102 ;
F_65 ( & V_81 -> V_151 , & V_8 -> V_182 ) ;
F_21 ( & V_8 -> V_180 , V_132 ) ;
}
static void
F_59 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
unsigned long V_132 = 0 ;
V_81 -> V_196 = 0 ;
V_81 -> V_197 = 0 ;
V_81 -> V_198 = 0 ;
if ( V_81 -> V_152 ) {
F_20 ( & V_8 -> V_133 . V_134 ,
V_132 ) ;
V_81 -> V_42 = NULL ;
F_65 ( & V_81 -> V_151 ,
& V_8 -> V_133 . V_199 ) ;
F_21 ( & V_8 -> V_133 . V_134 ,
V_132 ) ;
} else {
V_81 -> V_42 = NULL ;
V_81 -> V_100 . V_101 = V_102 ;
F_20 ( & V_8 -> V_180 , V_132 ) ;
F_65 ( & V_81 -> V_151 , & V_8 -> V_182 ) ;
F_21 ( & V_8 -> V_180 , V_132 ) ;
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
struct V_17 * V_200 = NULL ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_82 * V_83 = V_32 -> V_35 ;
struct V_141 * V_142 = & V_32 -> V_100 ;
T_2 * V_201 = & V_32 -> V_100 . V_84 ;
struct V_82 * V_202 = V_201 -> V_119 . V_120 . V_203 ;
T_3 V_204 ;
T_1 V_205 = 0 ;
int V_206 , V_207 = V_13 -> V_208 ;
V_83 += 2 ;
if ( F_84 ( V_13 ) ) {
V_206 = F_85 ( & V_8 -> V_209 -> V_210 , F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_207 ) ;
if ( F_86 ( ! V_206 ) )
return 1 ;
V_32 -> V_196 = V_206 ;
if ( V_32 -> V_196 > V_8 -> V_211 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_11
L_12 ,
V_22 , V_8 -> V_211 ,
V_32 -> V_196 ) ;
V_32 -> V_196 = 0 ;
F_87 ( V_13 ) ;
return 1 ;
}
F_88 (scsi_cmnd, sgel, nseg, num_bde) {
V_204 = F_89 ( V_200 ) ;
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) &&
! ( V_142 -> V_101 & V_212 ) &&
V_206 <= V_213 ) {
V_202 -> V_105 . V_106 . V_108 = V_109 ;
V_202 -> V_105 . V_106 . V_107 = F_90 ( V_200 ) ;
V_202 -> V_104 = F_46 ( V_204 ) ;
V_202 -> V_103 = F_45 ( V_204 ) ;
V_202 ++ ;
} else {
V_83 -> V_105 . V_106 . V_108 = V_109 ;
V_83 -> V_105 . V_106 . V_107 = F_90 ( V_200 ) ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_83 -> V_104 =
F_15 ( F_46 ( V_204 ) ) ;
V_83 -> V_103 =
F_15 ( F_45 ( V_204 ) ) ;
V_83 ++ ;
}
}
}
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) &&
! ( V_142 -> V_101 & V_212 ) ) {
if ( V_205 > V_213 ) {
V_204 = V_32 -> V_99 ;
V_202 -> V_105 . V_106 . V_108 = V_125 ;
V_202 -> V_105 . V_106 . V_107 = ( V_205 *
sizeof( struct V_82 ) ) ;
V_204 += ( sizeof( struct V_92 ) +
sizeof( struct V_93 ) +
( 2 * sizeof( struct V_82 ) ) ) ;
V_202 -> V_103 = F_45 ( V_204 ) ;
V_202 -> V_104 = F_46 ( V_204 ) ;
V_201 -> V_119 . V_120 . V_214 = 2 ;
} else {
V_201 -> V_119 . V_120 . V_214 = ( V_205 + 1 ) ;
}
} else {
V_201 -> V_111 . V_112 . V_113 . V_107 =
( ( V_205 + 2 ) * sizeof( struct V_82 ) ) ;
V_201 -> V_119 . V_120 . V_214 = ( V_205 + 1 ) ;
}
V_92 -> V_215 = F_91 ( F_92 ( V_13 ) ) ;
V_201 -> V_111 . V_216 . V_217 = F_92 ( V_13 ) ;
return 0 ;
}
static int
F_93 ( struct V_12 * V_8 , struct V_13 * V_25 ,
T_1 * V_218 , T_4 * V_219 , T_1 V_220 )
{
struct V_17 * V_221 ;
struct V_17 * V_18 ;
struct V_31 * V_32 = NULL ;
struct V_222 * V_15 = NULL ;
struct V_39 * V_143 ;
struct V_1 * V_38 ;
T_1 V_223 = F_94 ( V_25 ) ;
T_1 V_224 ;
T_1 V_225 ;
T_5 V_226 ;
int V_178 = 0 ;
int V_227 = 0 ;
if ( V_223 == V_228 )
return 0 ;
V_221 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
V_226 = F_95 ( V_25 ) ;
if ( V_8 -> V_229 != V_230 ) {
V_224 = F_9 ( V_25 ) ;
V_225 = ( F_92 ( V_25 ) + V_224 - 1 ) / V_224 ;
if ( ( V_8 -> V_229 < V_226 ) ||
( V_8 -> V_229 >= ( V_226 + V_225 ) ) )
return 0 ;
if ( V_221 ) {
V_227 = V_8 -> V_229 - V_226 ;
V_225 = F_90 ( V_221 ) /
sizeof( struct V_222 ) ;
if ( V_225 < V_227 )
V_227 = V_225 ;
}
}
V_38 = F_1 ( V_25 -> V_26 ) ;
if ( V_38 && V_38 -> V_40 ) {
V_143 = V_38 -> V_40 ;
if ( V_8 -> V_231 &&
( V_8 -> V_231 != V_143 -> V_232 ) )
return 0 ;
if ( V_8 -> V_233 . V_234 . V_235 [ 0 ] &&
( memcmp ( & V_143 -> V_236 , & V_8 -> V_233 ,
sizeof( struct V_237 ) ) != 0 ) )
return 0 ;
}
if ( V_221 ) {
V_15 = (struct V_222 * ) F_5 ( V_221 ) ;
V_15 += V_227 ;
V_32 = (struct V_31 * ) V_25 -> V_238 ;
}
if ( V_218 ) {
if ( V_8 -> V_239 ) {
switch ( V_223 ) {
case V_240 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_13
L_14 ,
( unsigned long ) V_226 , V_227 ,
F_96 ( V_15 -> V_241 ) ) ;
if ( V_32 ) {
V_32 -> V_242 =
V_243 ;
V_32 -> V_244 =
V_15 ;
V_32 -> V_245 =
V_15 -> V_241 ;
}
V_15 -> V_241 = F_91 ( 0xDEADBEEF ) ;
V_8 -> V_239 -- ;
if ( V_8 -> V_239 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_246 | V_247 ;
break;
}
case V_248 :
* V_218 = 0xDEADBEEF ;
V_8 -> V_239 -- ;
if ( V_8 -> V_239 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_246 | V_247 ;
F_4 ( V_8 , V_20 , V_21 ,
L_15
L_16 , ( unsigned long ) V_226 ) ;
break;
case V_249 :
* V_218 = 0xDEADBEEF ;
V_8 -> V_239 -- ;
if ( V_8 -> V_239 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 ;
F_4 ( V_8 , V_20 , V_21 ,
L_17
L_16 , ( unsigned long ) V_226 ) ;
break;
}
}
if ( V_8 -> V_251 ) {
switch ( V_223 ) {
case V_252 :
case V_253 :
case V_254 :
* V_218 = 0xDEADBEEF ;
V_8 -> V_251 -- ;
if ( V_8 -> V_251 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 ;
F_4 ( V_8 , V_20 , V_21 ,
L_18
L_19 , ( unsigned long ) V_226 ) ;
break;
}
}
}
if ( V_219 ) {
if ( V_8 -> V_255 ) {
switch ( V_223 ) {
case V_240 :
if ( V_15 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_20
L_21 ,
( unsigned long ) V_226 , V_227 ,
F_97 ( V_15 -> V_256 ) ) ;
if ( V_32 ) {
V_32 -> V_242 =
V_257 ;
V_32 -> V_244 =
V_15 ;
V_32 -> V_245 =
V_15 -> V_256 ;
}
V_15 -> V_256 = F_98 ( 0xDEAD ) ;
V_8 -> V_255 -- ;
if ( V_8 -> V_255 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_246 | V_247 ;
break;
}
case V_248 :
* V_219 = 0xDEAD ;
V_8 -> V_255 -- ;
if ( V_8 -> V_255 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_246 | V_247 ;
F_4 ( V_8 , V_20 , V_21 ,
L_22
L_16 , ( unsigned long ) V_226 ) ;
break;
case V_249 :
* V_219 = 0xDEAD ;
V_8 -> V_255 -- ;
if ( V_8 -> V_255 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 ;
F_4 ( V_8 , V_20 , V_21 ,
L_23
L_16 , ( unsigned long ) V_226 ) ;
break;
}
}
if ( V_8 -> V_258 ) {
switch ( V_223 ) {
case V_252 :
case V_253 :
case V_254 :
* V_219 = 0xDEAD ;
V_8 -> V_258 -- ;
if ( V_8 -> V_258 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 ;
F_4 ( V_8 , V_20 , V_21 ,
L_24
L_19 , ( unsigned long ) V_226 ) ;
break;
}
}
}
if ( V_220 ) {
if ( V_8 -> V_259 ) {
switch ( V_223 ) {
case V_240 :
V_178 = V_247 ;
case V_248 :
V_8 -> V_259 -- ;
if ( V_8 -> V_259 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 |= V_246 | V_260 ;
F_4 ( V_8 , V_20 , V_21 ,
L_25
L_16 , ( unsigned long ) V_226 ) ;
break;
case V_249 :
V_8 -> V_259 -- ;
if ( V_8 -> V_259 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 | V_260 ;
F_4 ( V_8 , V_20 , V_21 ,
L_26
L_16 , ( unsigned long ) V_226 ) ;
break;
}
}
if ( V_8 -> V_261 ) {
switch ( V_223 ) {
case V_252 :
case V_253 :
case V_254 :
V_8 -> V_261 -- ;
if ( V_8 -> V_261 == 0 ) {
V_8 -> V_231 = 0 ;
V_8 -> V_229 =
V_230 ;
memset ( & V_8 -> V_233 ,
0 , sizeof( struct V_237 ) ) ;
}
V_178 = V_250 | V_260 ;
F_4 ( V_8 , V_20 , V_21 ,
L_27
L_19 , ( unsigned long ) V_226 ) ;
}
}
}
return V_178 ;
}
static int
F_99 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_189 * V_262 , V_189 * V_263 )
{
V_189 V_264 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_94 ( V_25 ) ) {
case V_252 :
case V_249 :
* V_263 = V_265 ;
* V_262 = V_266 ;
break;
case V_253 :
case V_248 :
* V_263 = V_267 ;
* V_262 = V_268 ;
break;
case V_254 :
case V_240 :
* V_263 = V_269 ;
* V_262 = V_270 ;
break;
case V_228 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_28 ,
F_94 ( V_25 ) ) ;
V_264 = 1 ;
break;
}
} else {
switch ( F_94 ( V_25 ) ) {
case V_253 :
case V_248 :
* V_263 = V_267 ;
* V_262 = V_268 ;
break;
case V_254 :
case V_240 :
* V_263 = V_271 ;
* V_262 = V_271 ;
break;
case V_252 :
case V_249 :
* V_263 = V_268 ;
* V_262 = V_267 ;
break;
case V_228 :
default:
F_4 ( V_8 , V_20 , V_21 ,
L_29 ,
F_94 ( V_25 ) ) ;
V_264 = 1 ;
break;
}
}
return V_264 ;
}
static int
F_100 ( struct V_12 * V_8 , struct V_13 * V_25 ,
V_189 * V_262 , V_189 * V_263 )
{
V_189 V_264 = 0 ;
if ( F_11 ( V_25 ) ) {
switch ( F_94 ( V_25 ) ) {
case V_252 :
case V_249 :
* V_263 = V_268 ;
* V_262 = V_267 ;
break;
case V_253 :
case V_248 :
* V_263 = V_266 ;
* V_262 = V_265 ;
break;
case V_254 :
case V_240 :
* V_263 = V_270 ;
* V_262 = V_269 ;
break;
case V_228 :
default:
break;
}
} else {
switch ( F_94 ( V_25 ) ) {
case V_253 :
case V_248 :
* V_263 = V_266 ;
* V_262 = V_265 ;
break;
case V_254 :
case V_240 :
* V_263 = V_272 ;
* V_262 = V_272 ;
break;
case V_252 :
case V_249 :
* V_263 = V_265 ;
* V_262 = V_266 ;
break;
case V_228 :
default:
break;
}
}
return V_264 ;
}
static int
F_101 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_82 * V_83 , int V_273 )
{
struct V_17 * V_18 = NULL ;
struct V_274 * V_275 = NULL ;
struct V_276 * V_277 = NULL ;
T_3 V_204 ;
int V_47 = 0 , V_205 = 0 , V_128 ;
int V_207 = V_25 -> V_208 ;
#ifdef F_102
T_1 V_178 ;
#endif
T_1 V_278 = 1 ;
T_1 V_218 ;
unsigned V_224 ;
V_189 V_262 , V_263 ;
V_128 = F_99 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_128 )
goto V_279;
V_224 = F_9 ( V_25 ) ;
V_218 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_178 = F_93 ( V_8 , V_25 , & V_218 , NULL , 1 ) ;
if ( V_178 ) {
if ( V_178 & V_260 )
F_100 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_178 & V_247 )
V_278 = 0 ;
}
#endif
V_275 = (struct V_274 * ) V_83 ;
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
F_16 ( V_280 , V_275 , V_281 ) ;
V_275 -> V_282 = F_17 ( V_275 -> V_282 ) ;
V_275 -> V_218 = F_17 ( V_218 ) ;
V_205 ++ ;
V_83 ++ ;
V_277 = (struct V_276 * ) V_83 ;
memset ( V_277 , 0 , sizeof( struct V_276 ) ) ;
F_16 ( V_283 , V_277 , V_284 ) ;
F_16 ( V_285 , V_277 , V_262 ) ;
F_16 ( V_286 , V_277 , V_263 ) ;
if ( V_207 == V_287 ) {
if ( F_10 ( V_25 , V_288 ) )
F_16 ( V_289 , V_277 , V_278 ) ;
else
F_16 ( V_289 , V_277 , 0 ) ;
if ( F_10 ( V_25 , V_290 ) )
F_16 ( V_291 , V_277 , V_278 ) ;
else
F_16 ( V_291 , V_277 , 0 ) ;
}
F_16 ( V_292 , V_277 , 1 ) ;
F_16 ( V_293 , V_277 , 0 ) ;
F_16 ( V_294 , V_277 , 0 ) ;
V_277 -> V_282 = F_17 ( V_277 -> V_282 ) ;
V_277 -> V_295 = F_17 ( V_277 -> V_295 ) ;
V_277 -> V_36 = F_17 ( V_277 -> V_36 ) ;
V_205 ++ ;
V_83 ++ ;
F_88 (sc, sgde, datasegcnt, i) {
V_204 = F_89 ( V_18 ) ;
V_83 -> V_104 = F_15 ( F_46 ( V_204 ) ) ;
V_83 -> V_103 = F_15 ( F_45 ( V_204 ) ) ;
V_83 -> V_105 . V_106 . V_107 = F_90 ( V_18 ) ;
if ( V_207 == V_296 )
V_83 -> V_105 . V_106 . V_108 = V_109 ;
else
V_83 -> V_105 . V_106 . V_108 = V_297 ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_83 ++ ;
V_205 ++ ;
}
V_279:
return V_205 ;
}
static int
F_103 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_82 * V_83 , int V_298 , int V_299 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_221 = NULL ;
struct V_274 * V_275 = NULL ;
struct V_276 * V_277 = NULL ;
struct V_300 * V_301 = NULL ;
T_3 V_302 , V_303 ;
unsigned short V_304 = 0 , V_305 = 0 ;
unsigned int V_306 ;
unsigned int V_307 , V_308 = 0 , V_309 ;
unsigned int V_310 , V_311 ;
unsigned int V_312 , V_313 ;
int V_128 ;
int V_207 = V_25 -> V_208 ;
unsigned char V_314 = 0 , V_315 = 0 ;
unsigned V_224 ;
#ifdef F_102
T_1 V_178 ;
#endif
T_1 V_278 = 1 ;
T_1 V_218 ;
V_189 V_262 , V_263 ;
int V_205 = 0 ;
V_221 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_221 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_95 ,
L_30 ,
V_221 , V_18 ) ;
return 0 ;
}
V_128 = F_99 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_128 )
goto V_279;
V_224 = F_9 ( V_25 ) ;
V_218 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_178 = F_93 ( V_8 , V_25 , & V_218 , NULL , 1 ) ;
if ( V_178 ) {
if ( V_178 & V_260 )
F_100 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_178 & V_247 )
V_278 = 0 ;
}
#endif
V_306 = 0 ;
do {
if ( V_205 >= ( V_8 -> V_316 - 2 ) )
return V_205 + 3 ;
V_275 = (struct V_274 * ) V_83 ;
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
F_16 ( V_280 , V_275 , V_281 ) ;
V_275 -> V_282 = F_17 ( V_275 -> V_282 ) ;
V_275 -> V_218 = F_17 ( V_218 ) ;
V_205 ++ ;
V_83 ++ ;
V_277 = (struct V_276 * ) V_83 ;
memset ( V_277 , 0 , sizeof( struct V_276 ) ) ;
F_16 ( V_283 , V_277 , V_284 ) ;
F_16 ( V_285 , V_277 , V_262 ) ;
F_16 ( V_286 , V_277 , V_263 ) ;
if ( F_10 ( V_25 , V_288 ) )
F_16 ( V_289 , V_277 , V_278 ) ;
else
F_16 ( V_289 , V_277 , 0 ) ;
if ( F_10 ( V_25 , V_290 ) )
F_16 ( V_291 , V_277 , V_278 ) ;
else
F_16 ( V_291 , V_277 , 0 ) ;
F_16 ( V_292 , V_277 , 1 ) ;
F_16 ( V_293 , V_277 , 0 ) ;
F_16 ( V_294 , V_277 , 0 ) ;
V_277 -> V_282 = F_17 ( V_277 -> V_282 ) ;
V_277 -> V_295 = F_17 ( V_277 -> V_295 ) ;
V_277 -> V_36 = F_17 ( V_277 -> V_36 ) ;
V_205 ++ ;
V_83 ++ ;
V_303 = F_89 ( V_221 ) + V_308 ;
V_307 = F_90 ( V_221 ) - V_308 ;
F_104 ( V_307 % 8 ) ;
V_301 = (struct V_300 * ) V_83 ;
memset ( V_301 , 0 , sizeof( struct V_300 ) ) ;
F_16 ( V_317 , V_301 , V_318 ) ;
V_301 -> V_103 = F_15 ( F_45 ( V_303 ) ) ;
V_301 -> V_104 = F_15 ( F_46 ( V_303 ) ) ;
V_310 = V_307 / 8 ;
V_311 = V_310 * V_224 ;
if ( ( V_301 -> V_104 & 0xfff ) + V_307 > 0x1000 ) {
V_309 = 0x1000 - ( V_301 -> V_104 & 0xfff ) ;
V_308 += V_309 ;
V_310 = V_309 / 8 ;
V_311 = V_310 * V_224 ;
} else {
V_308 = 0 ;
V_305 ++ ;
}
V_205 ++ ;
V_314 = 0 ;
V_313 = 0 ;
while ( ! V_314 ) {
if ( V_205 >= V_8 -> V_316 )
return V_205 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_31 ,
V_22 ) ;
return 0 ;
}
V_83 ++ ;
V_302 = F_89 ( V_18 ) + V_306 ;
V_83 -> V_104 = F_15 ( F_46 ( V_302 ) ) ;
V_83 -> V_103 = F_15 ( F_45 ( V_302 ) ) ;
V_312 = F_90 ( V_18 ) - V_306 ;
if ( ( V_313 + V_312 ) <= V_311 ) {
V_83 -> V_105 . V_106 . V_107 = V_312 ;
V_306 = 0 ;
if ( ( V_313 + V_312 ) == V_311 )
V_314 = 1 ;
} else {
V_83 -> V_105 . V_106 . V_107 = V_311 - V_313 ;
V_306 += V_83 -> V_105 . V_106 . V_107 ;
}
V_313 += V_83 -> V_105 . V_106 . V_107 ;
if ( V_207 == V_296 )
V_83 -> V_105 . V_106 . V_108 = V_109 ;
else
V_83 -> V_105 . V_106 . V_108 = V_297 ;
V_83 -> V_105 . V_110 = F_15 ( V_83 -> V_105 . V_110 ) ;
V_205 ++ ;
V_304 ++ ;
if ( V_306 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_308 ) {
V_218 += V_310 ;
V_83 ++ ;
continue;
}
if ( V_305 == V_299 ) {
V_315 = 1 ;
} else if ( V_305 < V_299 ) {
V_221 = F_6 ( V_221 ) ;
V_83 ++ ;
V_218 += V_310 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_32 , V_22 ) ;
}
} while ( ! V_315 );
V_279:
return V_205 ;
}
static int
F_105 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_273 )
{
struct V_17 * V_18 = NULL ;
struct V_319 * V_320 = NULL ;
T_3 V_204 ;
int V_47 = 0 , V_321 = 0 , V_128 ;
T_1 V_218 ;
unsigned V_224 ;
V_189 V_262 , V_263 ;
#ifdef F_102
T_1 V_178 ;
#endif
T_1 V_278 = 1 ;
T_1 V_322 ;
T_1 V_323 = 0 ;
V_128 = F_99 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_128 )
goto V_279;
V_224 = F_9 ( V_25 ) ;
V_218 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_178 = F_93 ( V_8 , V_25 , & V_218 , NULL , 1 ) ;
if ( V_178 ) {
if ( V_178 & V_260 )
F_100 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_178 & V_247 )
V_278 = 0 ;
}
#endif
V_320 = (struct V_319 * ) V_34 ;
memset ( V_320 , 0 , sizeof( struct V_319 ) ) ;
F_16 ( V_324 , V_34 , V_325 ) ;
V_320 -> V_241 = F_17 ( V_218 ) ;
V_320 -> V_326 = V_320 -> V_241 ;
if ( V_25 -> V_208 == V_287 ) {
if ( F_10 ( V_25 , V_288 ) )
F_16 ( V_327 , V_320 , V_278 ) ;
else
F_16 ( V_327 , V_320 , 0 ) ;
if ( F_10 ( V_25 , V_290 ) )
F_16 ( V_328 , V_320 , V_278 ) ;
else
F_16 ( V_328 , V_320 , 0 ) ;
}
F_16 ( V_329 , V_320 , V_262 ) ;
F_16 ( V_330 , V_320 , V_263 ) ;
F_16 ( V_331 , V_320 , 1 ) ;
F_16 ( V_332 , V_320 , 0 ) ;
V_320 -> V_36 = F_17 ( V_320 -> V_36 ) ;
V_320 -> V_333 = F_17 ( V_320 -> V_333 ) ;
V_321 ++ ;
V_34 ++ ;
F_88 (sc, sgde, datasegcnt, i) {
V_204 = F_89 ( V_18 ) ;
V_322 = F_90 ( V_18 ) ;
V_34 -> V_191 = F_17 ( F_46 ( V_204 ) ) ;
V_34 -> V_190 = F_17 ( F_45 ( V_204 ) ) ;
if ( ( V_47 + 1 ) == V_273 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_334 , V_34 , V_323 ) ;
F_16 ( V_324 , V_34 , V_335 ) ;
V_34 -> V_192 = F_17 ( V_322 ) ;
V_323 += V_322 ;
V_34 ++ ;
V_321 ++ ;
}
V_279:
return V_321 ;
}
static int
F_106 ( struct V_12 * V_8 , struct V_13 * V_25 ,
struct V_33 * V_34 , int V_298 , int V_299 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_221 = NULL ;
struct V_319 * V_320 = NULL ;
T_3 V_302 , V_303 ;
unsigned short V_304 = 0 , V_305 = 0 ;
unsigned int V_306 ;
unsigned int V_307 , V_308 = 0 , V_309 ;
unsigned int V_310 , V_311 ;
unsigned int V_312 , V_313 ;
int V_128 ;
unsigned char V_314 = 0 , V_315 = 0 ;
unsigned V_224 ;
T_1 V_218 ;
V_189 V_262 , V_263 ;
T_1 V_322 ;
#ifdef F_102
T_1 V_178 ;
#endif
T_1 V_278 = 1 ;
T_1 V_323 = 0 ;
int V_321 = 0 ;
V_221 = F_8 ( V_25 ) ;
V_18 = F_3 ( V_25 ) ;
if ( ! V_221 || ! V_18 ) {
F_4 ( V_8 , V_20 , V_95 ,
L_33 ,
V_221 , V_18 ) ;
return 0 ;
}
V_128 = F_99 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_128 )
goto V_279;
V_224 = F_9 ( V_25 ) ;
V_218 = ( T_1 ) F_95 ( V_25 ) ;
#ifdef F_102
V_178 = F_93 ( V_8 , V_25 , & V_218 , NULL , 1 ) ;
if ( V_178 ) {
if ( V_178 & V_260 )
F_100 ( V_8 , V_25 , & V_262 , & V_263 ) ;
if ( V_178 & V_247 )
V_278 = 0 ;
}
#endif
V_306 = 0 ;
do {
if ( V_321 >= ( V_8 -> V_316 - 2 ) )
return V_321 + 3 ;
V_320 = (struct V_319 * ) V_34 ;
memset ( V_320 , 0 , sizeof( struct V_319 ) ) ;
F_16 ( V_324 , V_34 , V_325 ) ;
V_320 -> V_241 = F_17 ( V_218 ) ;
V_320 -> V_326 = V_320 -> V_241 ;
if ( F_10 ( V_25 , V_288 ) ) {
F_16 ( V_327 , V_320 , V_278 ) ;
} else {
F_16 ( V_327 , V_320 , 0 ) ;
if ( V_262 == V_271 ) {
V_262 = V_336 ;
V_263 = V_336 ;
}
}
if ( F_10 ( V_25 , V_290 ) )
F_16 ( V_328 , V_320 , V_278 ) ;
else
F_16 ( V_328 , V_320 , 0 ) ;
F_16 ( V_329 , V_320 , V_262 ) ;
F_16 ( V_330 , V_320 , V_263 ) ;
F_16 ( V_331 , V_320 , 1 ) ;
F_16 ( V_332 , V_320 , 0 ) ;
V_320 -> V_36 = F_17 ( V_320 -> V_36 ) ;
V_320 -> V_333 = F_17 ( V_320 -> V_333 ) ;
V_321 ++ ;
V_34 ++ ;
V_303 = F_89 ( V_221 ) + V_308 ;
V_307 = F_90 ( V_221 ) - V_308 ;
F_104 ( V_307 % 8 ) ;
V_34 -> V_36 = 0 ;
F_16 ( V_324 , V_34 , V_337 ) ;
V_34 -> V_190 = F_15 ( F_45 ( V_303 ) ) ;
V_34 -> V_191 = F_15 ( F_46 ( V_303 ) ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_310 = V_307 / 8 ;
V_311 = V_310 * V_224 ;
if ( ( V_34 -> V_191 & 0xfff ) + V_307 > 0x1000 ) {
V_309 = 0x1000 - ( V_34 -> V_191 & 0xfff ) ;
V_308 += V_309 ;
V_310 = V_309 / 8 ;
V_311 = V_310 * V_224 ;
} else {
V_308 = 0 ;
V_305 ++ ;
}
V_321 ++ ;
V_314 = 0 ;
V_313 = 0 ;
while ( ! V_314 ) {
if ( V_321 >= V_8 -> V_316 )
return V_321 + 1 ;
if ( ! V_18 ) {
F_4 ( V_8 , V_20 , V_21 ,
L_34 ,
V_22 ) ;
return 0 ;
}
V_34 ++ ;
V_302 = F_89 ( V_18 ) + V_306 ;
V_312 = F_90 ( V_18 ) - V_306 ;
if ( ( V_313 + V_312 ) <= V_311 ) {
V_322 = V_312 ;
V_306 = 0 ;
if ( ( V_313 + V_312 ) == V_311 )
V_314 = 1 ;
} else {
V_322 = V_311 - V_313 ;
V_306 += V_322 ;
}
V_313 += V_322 ;
V_34 -> V_191 = F_17 ( F_46 ( V_302 ) ) ;
V_34 -> V_190 = F_17 ( F_45 ( V_302 ) ) ;
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_334 , V_34 , V_323 ) ;
F_16 ( V_324 , V_34 , V_335 ) ;
V_34 -> V_192 = F_17 ( V_322 ) ;
V_323 += V_322 ;
V_321 ++ ;
V_304 ++ ;
if ( V_306 )
break;
V_18 = F_6 ( V_18 ) ;
}
if ( V_308 ) {
V_218 += V_310 ;
V_34 ++ ;
continue;
}
if ( V_305 == V_299 ) {
F_16 ( V_37 , V_34 , 1 ) ;
V_315 = 1 ;
} else if ( V_305 < V_299 ) {
V_221 = F_6 ( V_221 ) ;
V_34 ++ ;
V_218 += V_310 ;
} else {
F_4 ( V_8 , V_20 , V_21 ,
L_35 , V_22 ) ;
}
} while ( ! V_315 );
V_279:
return V_321 ;
}
static int
F_12 ( struct V_12 * V_8 , struct V_13 * V_25 )
{
int V_264 = V_338 ;
unsigned char V_223 = F_94 ( V_25 ) ;
switch ( V_223 ) {
case V_253 :
case V_248 :
V_264 = V_29 ;
break;
case V_252 :
case V_249 :
case V_254 :
case V_240 :
V_264 = V_339 ;
break;
default:
if ( V_8 )
F_4 ( V_8 , V_20 , V_95 ,
L_36 ,
V_223 ) ;
break;
}
return V_264 ;
}
static int
F_107 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_25 = V_32 -> V_42 ;
int V_340 ;
V_340 = F_92 ( V_25 ) ;
if ( V_25 -> V_208 == V_287 ) {
if ( F_94 ( V_25 ) == V_252 )
return V_340 ;
} else {
if ( F_94 ( V_25 ) == V_249 )
return V_340 ;
}
V_340 += ( V_340 / F_9 ( V_25 ) ) * 8 ;
return V_340 ;
}
static int
F_108 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_82 * V_83 = V_32 -> V_35 ;
T_2 * V_201 = & V_32 -> V_100 . V_84 ;
T_1 V_205 = 0 ;
int V_273 , V_341 , V_207 = V_13 -> V_208 ;
int V_342 = 0 ;
int V_340 ;
V_83 += 2 ;
if ( F_84 ( V_13 ) ) {
V_273 = F_85 ( & V_8 -> V_209 -> V_210 ,
F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_207 ) ;
if ( F_86 ( ! V_273 ) )
return 1 ;
V_32 -> V_196 = V_273 ;
if ( V_32 -> V_196 > V_8 -> V_211 )
goto V_343;
V_342 = F_12 ( V_8 , V_13 ) ;
switch ( V_342 ) {
case V_29 :
if ( ( V_32 -> V_196 + 2 ) > V_8 -> V_316 )
goto V_343;
V_205 = F_101 ( V_8 , V_13 , V_83 ,
V_273 ) ;
if ( V_205 < 2 )
goto V_343;
break;
case V_339 :
V_341 = F_85 ( & V_8 -> V_209 -> V_210 ,
F_8 ( V_13 ) ,
F_109 ( V_13 ) , V_207 ) ;
if ( F_86 ( ! V_341 ) ) {
F_87 ( V_13 ) ;
return 1 ;
}
V_32 -> V_198 = V_341 ;
if ( ( V_32 -> V_198 * 4 ) >
( V_8 -> V_316 - 2 ) )
goto V_343;
V_205 = F_103 ( V_8 , V_13 , V_83 ,
V_273 , V_341 ) ;
if ( ( V_205 < 3 ) ||
( V_205 > V_8 -> V_316 ) )
goto V_343;
break;
case V_338 :
default:
F_87 ( V_13 ) ;
V_32 -> V_196 = 0 ;
F_4 ( V_8 , V_20 , V_95 ,
L_37 ,
V_342 ) ;
return 1 ;
}
}
V_201 -> V_111 . V_112 . V_113 . V_107 = ( 2 * sizeof( struct V_82 ) ) ;
V_201 -> V_111 . V_112 . V_113 . V_107 += ( V_205 * sizeof( struct V_82 ) ) ;
V_201 -> V_122 = 1 ;
V_201 -> V_123 = 1 ;
V_340 = F_107 ( V_8 , V_32 ) ;
V_92 -> V_215 = F_96 ( V_340 ) ;
V_201 -> V_111 . V_216 . V_217 = V_340 ;
return 0 ;
V_343:
if ( V_32 -> V_196 )
F_87 ( V_13 ) ;
if ( V_32 -> V_198 )
F_110 ( & V_8 -> V_209 -> V_210 , F_8 ( V_13 ) ,
F_109 ( V_13 ) ,
V_13 -> V_208 ) ;
F_4 ( V_8 , V_20 , V_95 ,
L_38
L_39 ,
V_32 -> V_196 , V_32 -> V_198 ,
V_8 -> V_316 , V_8 -> V_211 ,
V_342 , V_205 ) ;
V_32 -> V_196 = 0 ;
V_32 -> V_198 = 0 ;
return 1 ;
}
static T_4
F_111 ( V_189 * V_97 , int V_344 )
{
T_4 V_345 = 0 ;
T_4 V_346 ;
V_345 = F_112 ( V_97 , V_344 ) ;
V_346 = F_98 ( V_345 ) ;
return V_346 ;
}
static T_4
F_113 ( V_189 * V_97 , int V_344 )
{
T_4 V_264 ;
V_264 = F_114 ( V_97 , V_344 ) ;
return V_264 ;
}
static void
F_115 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_17 * V_221 ;
struct V_17 * V_18 ;
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_222 * V_15 = NULL ;
V_189 * V_347 = NULL ;
T_4 V_348 , V_349 ;
T_4 V_350 , V_256 ;
T_1 V_351 , V_241 ;
int V_352 , V_341 ;
int V_353 , V_354 , V_355 ;
int V_356 , V_357 , V_358 ;
T_4 V_359 ;
unsigned V_224 ;
V_353 = V_360 ;
V_359 = 0 ;
V_348 = 0 ;
V_352 = F_94 ( V_41 ) ;
if ( ( V_352 == V_253 ) ||
( V_352 == V_248 ) ||
( V_352 == V_228 ) )
goto V_279;
V_356 = 1 ;
V_357 = 0 ;
V_358 = 0 ;
V_221 = F_8 ( V_41 ) ;
V_341 = V_32 -> V_198 ;
if ( V_221 && V_341 ) {
V_18 = F_3 ( V_41 ) ;
V_224 = F_9 ( V_41 ) ;
V_347 = ( V_189 * ) F_5 ( V_18 ) ;
V_355 = V_18 -> V_23 ;
if ( ( V_355 & ( V_224 - 1 ) ) == 0 )
V_358 = 1 ;
V_349 = F_13 ( V_41 -> V_26 -> V_6 ) ;
V_15 = (struct V_222 * ) F_5 ( V_221 ) ;
V_351 = ( T_1 ) F_95 ( V_41 ) ;
V_350 = V_15 -> V_256 ;
V_354 = V_221 -> V_23 ;
while ( V_15 && V_341 ) {
while ( V_354 ) {
if ( ( V_15 -> V_241 == 0xffffffff ) ||
( V_15 -> V_256 == 0xffff ) ) {
V_351 ++ ;
goto V_361;
}
if ( V_358 ) {
V_348 = V_15 -> V_348 ;
if ( F_11 ( V_41 ) )
V_359 = F_113 ( V_347 ,
V_224 ) ;
else
V_359 = F_111 ( V_347 ,
V_224 ) ;
if ( ( V_348 != V_359 ) ) {
V_353 = V_360 ;
goto V_279;
}
}
V_241 = F_96 ( V_15 -> V_241 ) ;
if ( V_356 && ( V_241 != V_351 ) ) {
V_353 = V_362 ;
goto V_279;
}
V_351 ++ ;
V_256 = V_15 -> V_256 ;
if ( V_357 && ( V_256 != V_350 ) ) {
V_353 = V_363 ;
goto V_279;
}
V_361:
V_354 -= sizeof( struct V_222 ) ;
if ( V_354 < 0 )
V_354 = 0 ;
V_15 ++ ;
V_347 += V_224 ;
V_355 -= V_224 ;
if ( V_358 && ( V_355 == 0 ) ) {
V_358 = 0 ;
V_18 = F_6 ( V_18 ) ;
if ( ! V_18 )
goto V_279;
V_347 = ( V_189 * ) F_5 ( V_18 ) ;
V_355 = V_18 -> V_23 ;
if ( ( V_355 & ( V_224 - 1 ) ) == 0 )
V_358 = 1 ;
}
}
V_221 = F_6 ( V_221 ) ;
if ( V_221 ) {
V_15 = (struct V_222 * ) F_5 ( V_221 ) ;
V_354 = V_221 -> V_23 ;
} else {
V_15 = NULL ;
}
V_341 -- ;
}
}
V_279:
if ( V_353 == V_360 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x1 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_369 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_40 ,
( unsigned long ) F_95 ( V_41 ) ,
V_359 , V_348 ) ;
} else if ( V_353 == V_362 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x3 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_371 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_41 ,
( unsigned long ) F_95 ( V_41 ) ,
V_241 , V_351 ) ;
} else if ( V_353 == V_363 ) {
F_116 ( 1 , V_41 -> V_364 , V_365 ,
0x10 , 0x2 ) ;
V_41 -> V_48 = V_366 << 24
| F_117 ( V_367 , V_368 ) ;
V_8 -> V_372 ++ ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_42 ,
( unsigned long ) F_95 ( V_41 ) ,
V_256 , V_350 ) ;
}
}
static int
F_118 ( struct V_12 * V_8 , struct V_31 * V_32 ,
struct V_141 * V_373 )
{
struct V_13 * V_41 = V_32 -> V_42 ;
struct V_374 * V_375 = & V_373 -> V_84 . V_119 . V_376 ;
int V_264 = 0 ;
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
V_339 ) {
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
V_264 = ( - 1 ) ;
goto V_279;
}
if ( F_121 ( V_378 ) ) {
V_41 -> V_48 = F_117 ( V_382 , 0 ) ;
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_50
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
V_264 = ( - 1 ) ;
goto V_279;
}
if ( F_122 ( V_378 ) ) {
V_264 = 1 ;
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
V_264 = 1 ;
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
V_264 = 1 ;
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
case V_252 :
case V_249 :
V_377 /= V_41 -> V_26 -> V_27 ;
break;
case V_253 :
case V_248 :
case V_254 :
case V_240 :
V_377 /= ( V_41 -> V_26 -> V_27 +
sizeof( struct V_222 ) ) ;
break;
}
V_379 = F_95 ( V_41 ) ;
V_379 += V_377 ;
F_126 ( V_379 , & V_41 -> V_364 [ 12 ] ) ;
}
if ( ! V_264 ) {
F_4 ( V_8 , V_370 , V_95 | V_21 ,
L_54
L_48
L_49 , V_41 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_41 ) ,
F_120 ( V_41 -> V_383 ) , V_378 , V_377 ) ;
F_115 ( V_8 , V_32 ) ;
}
V_279:
return V_264 ;
}
static int
F_127 ( struct V_12 * V_8 , struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_17 * V_200 = NULL ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
struct V_33 * V_384 ;
T_2 * V_201 = & V_32 -> V_100 . V_84 ;
T_3 V_204 ;
T_1 V_205 = 0 ;
T_1 V_322 ;
T_1 V_323 = 0 ;
int V_206 ;
struct V_82 * V_385 ;
if ( F_84 ( V_13 ) ) {
V_206 = F_128 ( V_13 ) ;
if ( F_86 ( ! V_206 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_384 = V_34 ;
V_32 -> V_196 = V_206 ;
if ( V_32 -> V_196 > V_8 -> V_211 ) {
F_4 ( V_8 , V_20 , V_21 , L_55
L_56
L_12 ,
V_22 , V_8 -> V_211 ,
V_32 -> V_196 ) ;
V_32 -> V_196 = 0 ;
F_87 ( V_13 ) ;
return 1 ;
}
F_88 (scsi_cmnd, sgel, nseg, num_bde) {
V_204 = F_89 ( V_200 ) ;
V_322 = F_90 ( V_200 ) ;
V_34 -> V_191 = F_17 ( F_46 ( V_204 ) ) ;
V_34 -> V_190 = F_17 ( F_45 ( V_204 ) ) ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
if ( ( V_205 + 1 ) == V_206 )
F_16 ( V_37 , V_34 , 1 ) ;
else
F_16 ( V_37 , V_34 , 0 ) ;
F_16 ( V_334 , V_34 , V_323 ) ;
F_16 ( V_324 , V_34 , V_335 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 -> V_192 = F_17 ( V_322 ) ;
V_323 += V_322 ;
V_34 ++ ;
}
if ( V_8 -> V_116 & V_386 ) {
V_385 = (struct V_82 * )
& ( V_201 -> V_119 . V_387 [ 5 ] ) ;
V_385 -> V_104 = V_384 -> V_191 ;
V_385 -> V_103 = V_384 -> V_190 ;
V_385 -> V_105 . V_106 . V_107 =
F_15 ( V_384 -> V_192 ) ;
V_385 -> V_105 . V_106 . V_108 = V_109 ;
V_385 -> V_105 . V_110 = F_17 ( V_385 -> V_105 . V_110 ) ;
}
} else {
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 1 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
}
V_92 -> V_215 = F_91 ( F_92 ( V_13 ) ) ;
V_201 -> V_111 . V_216 . V_217 = F_92 ( V_13 ) ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_388 )
V_32 -> V_100 . V_101 |= ( V_389 | V_390 ) ;
return 0 ;
}
static int
F_129 ( struct V_12 * V_8 ,
struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_32 -> V_35 ) ;
T_2 * V_201 = & V_32 -> V_100 . V_84 ;
T_1 V_321 = 0 ;
int V_273 , V_341 , V_207 = V_13 -> V_208 ;
int V_342 = 0 ;
int V_340 ;
if ( F_84 ( V_13 ) ) {
V_273 = F_85 ( & V_8 -> V_209 -> V_210 ,
F_3 ( V_13 ) ,
F_84 ( V_13 ) , V_207 ) ;
if ( F_86 ( ! V_273 ) )
return 1 ;
V_34 += 1 ;
V_34 -> V_36 = F_15 ( V_34 -> V_36 ) ;
F_16 ( V_37 , V_34 , 0 ) ;
V_34 -> V_36 = F_17 ( V_34 -> V_36 ) ;
V_34 += 1 ;
V_32 -> V_196 = V_273 ;
if ( V_32 -> V_196 > V_8 -> V_211 )
goto V_343;
V_342 = F_12 ( V_8 , V_13 ) ;
switch ( V_342 ) {
case V_29 :
if ( ( V_32 -> V_196 + 1 ) > V_8 -> V_316 )
goto V_343;
V_321 = F_105 ( V_8 , V_13 , V_34 ,
V_273 ) ;
if ( V_321 < 2 )
goto V_343;
break;
case V_339 :
V_341 = F_85 ( & V_8 -> V_209 -> V_210 ,
F_8 ( V_13 ) ,
F_109 ( V_13 ) , V_207 ) ;
if ( F_86 ( ! V_341 ) ) {
F_87 ( V_13 ) ;
return 1 ;
}
V_32 -> V_198 = V_341 ;
if ( ( V_32 -> V_198 * 3 ) >
( V_8 -> V_316 - 2 ) )
goto V_343;
V_321 = F_106 ( V_8 , V_13 , V_34 ,
V_273 , V_341 ) ;
if ( ( V_321 < 3 ) ||
( V_321 > V_8 -> V_316 ) )
goto V_343;
break;
case V_338 :
default:
F_87 ( V_13 ) ;
V_32 -> V_196 = 0 ;
F_4 ( V_8 , V_20 , V_95 ,
L_57 ,
V_342 ) ;
return 1 ;
}
}
switch ( F_94 ( V_13 ) ) {
case V_249 :
case V_253 :
V_32 -> V_100 . V_101 |= V_391 ;
break;
case V_248 :
case V_252 :
V_32 -> V_100 . V_101 |= V_392 ;
break;
case V_240 :
case V_254 :
V_32 -> V_100 . V_101 |= V_393 ;
break;
}
V_340 = F_107 ( V_8 , V_32 ) ;
V_92 -> V_215 = F_96 ( V_340 ) ;
V_201 -> V_111 . V_216 . V_217 = V_340 ;
if ( ( V_8 -> V_9 ) && ( (struct V_10 * )
V_13 -> V_26 -> V_7 ) -> V_388 )
V_32 -> V_100 . V_101 |= ( V_389 | V_390 ) ;
return 0 ;
V_343:
if ( V_32 -> V_196 )
F_87 ( V_13 ) ;
if ( V_32 -> V_198 )
F_110 ( & V_8 -> V_209 -> V_210 , F_8 ( V_13 ) ,
F_109 ( V_13 ) ,
V_13 -> V_208 ) ;
F_4 ( V_8 , V_20 , V_95 ,
L_58
L_59 ,
V_32 -> V_196 , V_32 -> V_198 ,
V_8 -> V_316 , V_8 -> V_211 ,
V_342 , V_321 ) ;
V_32 -> V_196 = 0 ;
V_32 -> V_198 = 0 ;
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
struct V_31 * V_32 , struct V_141 * V_394 ) {
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_93 * V_395 = V_32 -> V_93 ;
T_1 V_396 = V_395 -> V_397 ;
T_1 V_398 = V_395 -> V_399 ;
T_1 V_217 = V_394 -> V_84 . V_111 . V_216 . V_217 ;
struct V_400 * V_401 = NULL ;
struct V_39 * V_40 = V_32 -> V_38 -> V_40 ;
unsigned long V_43 ;
if ( ! V_40 || ! F_133 ( V_40 ) )
return;
if ( ( V_14 -> V_48 == V_402 ) ||
( V_14 -> V_48 == V_403 ) ) {
V_401 = F_134 ( V_8 ) ;
if ( ! V_401 )
return;
V_401 -> V_111 . V_404 . V_405 =
V_406 ;
V_401 -> V_111 . V_404 . V_407 =
( V_14 -> V_48 == V_402 ) ?
V_408 : V_409 ;
V_401 -> V_111 . V_404 . V_410 = V_14 -> V_26 -> V_410 ;
memcpy ( & V_401 -> V_111 . V_404 . V_411 ,
& V_40 -> V_236 , sizeof( struct V_237 ) ) ;
memcpy ( & V_401 -> V_111 . V_404 . V_412 ,
& V_40 -> V_413 , sizeof( struct V_237 ) ) ;
} else if ( ( V_396 & V_414 ) && V_395 -> V_415 &&
( ( V_14 -> V_14 [ 0 ] == V_416 ) || ( V_14 -> V_14 [ 0 ] == V_417 ) ) ) {
V_401 = F_134 ( V_8 ) ;
if ( ! V_401 )
return;
V_401 -> V_111 . V_418 . V_419 . V_405 =
V_406 ;
V_401 -> V_111 . V_418 . V_419 . V_407 =
V_420 ;
V_401 -> V_111 . V_418 . V_419 . V_410 =
V_14 -> V_26 -> V_410 ;
memcpy ( & V_401 -> V_111 . V_418 . V_419 . V_411 ,
& V_40 -> V_236 , sizeof( struct V_237 ) ) ;
memcpy ( & V_401 -> V_111 . V_418 . V_419 . V_412 ,
& V_40 -> V_413 , sizeof( struct V_237 ) ) ;
V_401 -> V_111 . V_418 . V_421 =
V_14 -> V_364 [ 2 ] & 0xf ;
V_401 -> V_111 . V_418 . V_422 = V_14 -> V_364 [ 12 ] ;
V_401 -> V_111 . V_418 . V_423 = V_14 -> V_364 [ 13 ] ;
} else if ( ( V_14 -> V_208 == V_287 ) &&
V_217 &&
( ( F_96 ( V_395 -> V_424 ) != V_217 ) ||
( ( V_398 == V_425 ) &&
! ( V_396 & ( V_426 | V_427 ) ) ) ) ) {
V_401 = F_134 ( V_8 ) ;
if ( ! V_401 )
return;
V_401 -> V_111 . V_428 . V_429 . V_405 =
V_430 ;
V_401 -> V_111 . V_428 . V_429 . V_407 =
V_431 ;
memcpy ( & V_401 -> V_111 . V_428 . V_429 . V_411 ,
& V_40 -> V_236 , sizeof( struct V_237 ) ) ;
memcpy ( & V_401 -> V_111 . V_428 . V_429 . V_412 ,
& V_40 -> V_413 , sizeof( struct V_237 ) ) ;
V_401 -> V_111 . V_428 . V_410 = V_14 -> V_26 -> V_410 ;
V_401 -> V_111 . V_428 . V_432 = V_14 -> V_14 [ 0 ] ;
V_401 -> V_111 . V_428 . V_433 =
V_217 ;
} else
return;
V_401 -> V_5 = V_5 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
F_65 ( & V_401 -> V_434 . V_435 , & V_8 -> V_436 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_25 ( V_8 ) ;
return;
}
static void
F_135 ( struct V_12 * V_8 , struct V_31 * V_81 )
{
if ( V_81 -> V_196 > 0 )
F_87 ( V_81 -> V_42 ) ;
if ( V_81 -> V_198 > 0 )
F_110 ( & V_8 -> V_209 -> V_210 , F_8 ( V_81 -> V_42 ) ,
F_109 ( V_81 -> V_42 ) ,
V_81 -> V_42 -> V_208 ) ;
}
static void
F_136 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_141 * V_394 )
{
struct V_13 * V_14 = V_32 -> V_42 ;
struct V_92 * V_437 = V_32 -> V_92 ;
struct V_93 * V_395 = V_32 -> V_93 ;
T_1 V_217 = V_394 -> V_84 . V_111 . V_216 . V_217 ;
T_1 V_396 = V_395 -> V_397 ;
T_1 V_398 = V_395 -> V_399 ;
T_1 * V_438 ;
T_1 V_439 = V_440 ;
T_1 V_441 = 0 ;
T_1 V_442 = V_95 | V_443 ;
if ( V_437 -> V_444 ) {
V_398 = 0 ;
goto V_279;
}
if ( V_396 & V_445 ) {
V_441 = F_96 ( V_395 -> V_446 ) ;
if ( V_441 != 0 && V_441 != 4 && V_441 != 8 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_60
L_61 ,
V_14 -> V_26 -> V_447 ,
V_14 -> V_26 -> V_410 , V_14 -> V_14 [ 0 ] ,
V_441 ) ;
V_439 = V_382 ;
goto V_279;
}
if ( V_395 -> V_448 != V_449 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_62
L_63
L_64 ,
V_14 -> V_26 -> V_447 ,
V_14 -> V_26 -> V_410 , V_14 -> V_14 [ 0 ] ,
V_395 -> V_448 ) ;
V_439 = V_382 ;
goto V_279;
}
}
if ( ( V_396 & V_414 ) && V_395 -> V_415 ) {
T_1 V_450 = F_96 ( V_395 -> V_415 ) ;
if ( V_450 > V_451 )
V_450 = V_451 ;
if ( V_396 & V_445 )
V_441 = F_96 ( V_395 -> V_446 ) ;
memcpy ( V_14 -> V_364 , & V_395 -> V_452 + V_441 , V_450 ) ;
}
V_438 = ( T_1 * ) V_14 -> V_364 ;
if ( ! V_398 && ( V_396 & V_426 ) ) {
if ( V_5 -> V_453 & V_95 )
V_442 = V_443 ;
if ( V_5 -> V_453 & V_454 )
V_442 = V_454 ;
}
F_39 ( V_5 , V_370 , V_442 ,
L_65
L_66 ,
V_14 -> V_14 [ 0 ] , V_398 ,
F_96 ( * V_438 ) , F_96 ( * ( V_438 + 3 ) ) , V_396 ,
F_96 ( V_395 -> V_424 ) ,
F_96 ( V_395 -> V_415 ) ,
F_96 ( V_395 -> V_446 ) ,
V_395 -> V_448 ) ;
F_137 ( V_14 , 0 ) ;
if ( V_396 & V_426 ) {
F_137 ( V_14 , F_96 ( V_395 -> V_424 ) ) ;
F_39 ( V_5 , V_94 , V_454 ,
L_67
L_68 ,
F_96 ( V_437 -> V_215 ) ,
F_138 ( V_14 ) , V_217 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_455 ) ;
if ( ( V_14 -> V_208 == V_287 ) &&
V_217 &&
( F_138 ( V_14 ) != V_217 ) ) {
F_39 ( V_5 , V_370 ,
V_95 | V_443 ,
L_69
L_70 ,
F_96 ( V_437 -> V_215 ) ,
F_138 ( V_14 ) , V_217 ,
V_14 -> V_14 [ 0 ] ) ;
F_137 ( V_14 , F_92 ( V_14 ) ) ;
V_439 = V_382 ;
}
if ( ! ( V_396 & V_414 ) &&
( V_398 == V_425 ) &&
( F_92 ( V_14 ) - F_138 ( V_14 )
< V_14 -> V_455 ) ) {
F_39 ( V_5 , V_94 , V_95 ,
L_71
L_72
L_73 ,
V_14 -> V_14 [ 0 ] , F_92 ( V_14 ) ,
F_138 ( V_14 ) , V_14 -> V_455 ) ;
V_439 = V_382 ;
}
} else if ( V_396 & V_427 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_74
L_75 , V_14 -> V_14 [ 0 ] ,
F_92 ( V_14 ) , F_138 ( V_14 ) ) ;
V_439 = V_382 ;
} else if ( V_217 && ( V_14 -> V_208 == V_287 ) ) {
F_39 ( V_5 , V_370 , V_95 | V_443 ,
L_76
L_77 ,
F_96 ( V_437 -> V_215 ) ,
F_96 ( V_395 -> V_424 ) ,
V_217 , V_14 -> V_14 [ 0 ] , V_398 ) ;
switch ( V_398 ) {
case V_425 :
case V_368 :
V_439 = V_382 ;
break;
}
F_137 ( V_14 , F_92 ( V_14 ) ) ;
}
V_279:
V_14 -> V_48 = F_117 ( V_439 , V_398 ) ;
F_132 ( V_5 -> V_8 , V_5 , V_32 , V_394 ) ;
}
static void
F_139 ( struct V_12 * V_8 , struct V_141 * V_456 ,
struct V_141 * V_373 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_456 -> V_130 ;
struct V_4 * V_5 = V_456 -> V_5 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_13 * V_41 ;
int V_48 ;
int V_457 ;
unsigned long V_43 ;
struct V_400 * V_401 ;
struct V_44 * V_45 ;
T_1 V_77 , V_458 ;
T_1 V_442 = V_95 ;
if ( ! ( V_32 -> V_42 ) )
return;
V_41 = V_32 -> V_42 ;
V_45 = V_41 -> V_26 -> V_6 ;
V_32 -> V_48 = ( V_373 -> V_84 . V_111 . V_459 [ 4 ] & V_460 ) ;
V_32 -> V_128 = V_373 -> V_84 . V_461 ;
V_32 -> V_152 = V_373 -> V_101 & V_462 ;
#ifdef F_102
if ( V_32 -> V_242 ) {
struct V_222 * V_15 = NULL ;
V_15 = (struct V_222 * ) V_32 -> V_244 ;
switch ( V_32 -> V_242 ) {
case V_243 :
V_15 -> V_241 =
V_32 -> V_245 ;
break;
case V_257 :
V_15 -> V_256 =
( T_4 ) V_32 -> V_245 ;
break;
case V_463 :
V_15 -> V_348 =
( T_4 ) V_32 -> V_245 ;
break;
default:
break;
}
V_32 -> V_245 = 0 ;
V_32 -> V_242 = 0 ;
V_32 -> V_244 = NULL ;
}
#endif
if ( V_40 && F_133 ( V_40 ) )
F_140 ( & V_40 -> V_464 ) ;
if ( V_32 -> V_128 ) {
if ( V_32 -> V_128 == V_465 &&
( V_32 -> V_48 & V_466 ) )
V_32 -> V_128 = V_467 ;
else if ( V_32 -> V_128 >= V_468 )
V_32 -> V_128 = V_469 ;
if ( V_32 -> V_128 == V_470 &&
! V_32 -> V_93 -> V_399 &&
( V_32 -> V_93 -> V_397 & V_426 ) &&
! ( V_5 -> V_453 & V_454 ) )
V_442 = 0 ;
else
V_442 = V_95 | V_454 ;
F_39 ( V_5 , V_370 , V_442 ,
L_78
L_79
L_80
L_75 ,
V_41 -> V_14 [ 0 ] ,
V_41 -> V_26 ? V_41 -> V_26 -> V_447 : 0xffff ,
V_41 -> V_26 ? V_41 -> V_26 -> V_410 : 0xffff ,
V_32 -> V_128 , V_32 -> V_48 ,
V_5 -> V_471 ,
( V_40 ) ? V_40 -> V_232 : 0 ,
V_8 -> V_115 == V_472 ?
V_32 -> V_100 . V_150 : 0xffff ,
V_373 -> V_84 . V_473 ,
V_32 -> V_100 . V_84 . V_474 ) ;
switch ( V_32 -> V_128 ) {
case V_470 :
F_136 ( V_5 , V_32 , V_373 ) ;
break;
case V_475 :
case V_476 :
V_41 -> V_48 = F_117 ( V_477 , 0 ) ;
V_401 = F_134 ( V_8 ) ;
if ( ! V_401 )
break;
V_401 -> V_111 . V_478 . V_405 =
V_430 ;
V_401 -> V_111 . V_478 . V_407 =
( V_32 -> V_128 == V_475 ) ?
V_479 : V_480 ;
if ( V_40 && F_133 ( V_40 ) ) {
memcpy ( & V_401 -> V_111 . V_478 . V_411 ,
& V_40 -> V_236 ,
sizeof( struct V_237 ) ) ;
memcpy ( & V_401 -> V_111 . V_478 . V_412 ,
& V_40 -> V_413 ,
sizeof( struct V_237 ) ) ;
}
V_401 -> V_5 = V_5 ;
V_401 -> V_434 . V_481 =
V_482 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
F_65 ( & V_401 -> V_434 . V_435 ,
& V_8 -> V_436 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_25 ( V_8 ) ;
break;
case V_465 :
case V_483 :
if ( V_32 -> V_48 == V_484 ||
V_32 -> V_48 ==
V_485 ||
V_32 -> V_48 == V_486 ||
V_32 -> V_48 ==
V_487 ) {
V_41 -> V_48 = F_117 ( V_488 , 0 ) ;
break;
}
if ( V_32 -> V_48 == V_489 ||
V_32 -> V_48 == V_490 ||
V_32 -> V_48 == V_491 ||
V_32 -> V_48 == V_492 ) {
V_41 -> V_48 = F_117 ( V_493 , 0 ) ;
break;
}
if ( ( V_32 -> V_48 == V_494 ||
V_32 -> V_48 == V_495 ) &&
V_373 -> V_84 . V_119 . V_376 . V_378 ) {
if ( F_94 ( V_41 ) != V_228 ) {
F_118 ( V_8 , V_32 ,
V_373 ) ;
break;
} else {
F_39 ( V_5 , V_370 ,
V_21 ,
L_81
L_82 ) ;
}
}
if ( ( V_32 -> V_128 == V_483 )
&& ( V_8 -> V_115 == V_472 )
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
|| ( V_40 -> V_496 != V_497 ) )
V_41 -> V_48 = F_117 ( V_477 ,
V_403 ) ;
} else
V_41 -> V_48 = F_117 ( V_440 , 0 ) ;
if ( V_41 -> V_48 || V_32 -> V_93 -> V_415 ) {
T_1 * V_438 = ( T_1 * ) V_41 -> V_364 ;
F_39 ( V_5 , V_94 , V_95 ,
L_83
L_84 ,
V_41 -> V_26 -> V_447 , V_41 -> V_26 -> V_410 , V_41 ,
V_41 -> V_48 , * V_438 , * ( V_438 + 3 ) , V_41 -> V_498 ,
F_138 ( V_41 ) ) ;
}
F_18 ( V_8 , V_32 ) ;
V_48 = V_41 -> V_48 ;
if ( V_5 -> V_499 &&
F_24 ( V_49 , V_32 -> V_50 +
F_141 ( V_5 -> V_499 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_40 && F_133 ( V_40 ) ) {
if ( V_40 -> V_500 >
F_27 ( & V_40 -> V_464 ) &&
( F_27 ( & V_40 -> V_464 ) >
V_501 ) &&
( ( V_41 -> V_14 [ 0 ] == V_416 ) ||
( V_41 -> V_14 [ 0 ] == V_417 ) ) )
V_40 -> V_500 =
F_27 ( & V_40 -> V_464 ) ;
V_40 -> V_502 = V_49 ;
}
F_21 ( V_45 -> V_51 , V_43 ) ;
} else if ( V_40 && F_133 ( V_40 ) ) {
if ( ( V_40 -> V_500 < V_5 -> V_503 ) &&
F_24 ( V_49 , V_40 -> V_502 +
F_141 ( V_504 ) ) ) {
F_20 ( V_45 -> V_51 , V_43 ) ;
V_457 = V_40 -> V_500 * V_505
/ 100 ;
V_457 = V_457 ? V_457 : 1 ;
V_40 -> V_500 += V_457 ;
if ( V_40 -> V_500 > V_5 -> V_503 )
V_40 -> V_500 = V_5 -> V_503 ;
V_40 -> V_502 = V_49 ;
F_21 ( V_45 -> V_51 , V_43 ) ;
}
}
F_135 ( V_8 , V_32 ) ;
V_77 = V_41 -> V_26 -> V_77 ;
V_458 = V_41 -> V_26 -> V_447 ;
V_41 -> V_506 ( V_41 ) ;
if ( V_8 -> V_507 & V_508 ) {
F_20 ( & V_8 -> V_64 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_509 )
F_142 ( V_32 -> V_509 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_82 ( V_8 , V_32 ) ;
return;
}
F_20 ( & V_8 -> V_64 , V_43 ) ;
V_32 -> V_42 = NULL ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_509 )
F_142 ( V_32 -> V_509 ) ;
F_21 ( V_45 -> V_51 , V_43 ) ;
F_82 ( V_8 , V_32 ) ;
}
static void
F_143 ( V_189 * V_97 , struct V_92 * V_92 )
{
int V_47 , V_510 ;
for ( V_47 = 0 , V_510 = 0 ; V_47 < sizeof( struct V_92 ) ;
V_47 += sizeof( T_1 ) , V_510 ++ ) {
( ( T_1 * ) V_97 ) [ V_510 ] = F_91 ( ( ( T_1 * ) V_92 ) [ V_510 ] ) ;
}
}
static void
F_144 ( struct V_4 * V_5 , struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_13 * V_13 = V_32 -> V_42 ;
struct V_92 * V_92 = V_32 -> V_92 ;
T_2 * V_201 = & V_32 -> V_100 . V_84 ;
struct V_141 * V_511 = & ( V_32 -> V_100 ) ;
int V_207 = V_13 -> V_208 ;
V_189 * V_512 ;
bool V_513 ;
T_1 V_340 ;
if ( ! V_40 || ! F_133 ( V_40 ) )
return;
V_32 -> V_93 -> V_415 = 0 ;
V_32 -> V_92 -> V_444 = 0 ;
F_145 ( V_32 -> V_42 -> V_26 -> V_410 ,
& V_32 -> V_92 -> V_514 ) ;
V_512 = & V_92 -> V_515 [ 0 ] ;
memcpy ( V_512 , V_13 -> V_14 , V_13 -> V_516 ) ;
if ( V_13 -> V_516 < V_517 ) {
V_512 += V_13 -> V_516 ;
memset ( V_512 , 0 , ( V_517 - V_13 -> V_516 ) ) ;
}
V_92 -> V_518 = V_519 ;
V_513 = ( V_8 -> V_115 == V_472 ) ;
V_511 -> V_84 . V_111 . V_216 . V_520 = 0 ;
if ( F_84 ( V_13 ) ) {
if ( V_207 == V_296 ) {
V_201 -> V_521 = V_522 ;
V_201 -> V_523 = V_524 ;
if ( V_5 -> V_525 &&
( V_40 -> V_526 & V_527 ) ) {
V_340 = F_92 ( V_13 ) ;
if ( V_340 < V_5 -> V_525 )
V_511 -> V_84 . V_111 . V_216 . V_520 = V_340 ;
else
V_511 -> V_84 . V_111 . V_216 . V_520 =
V_5 -> V_525 ;
}
V_92 -> V_528 = V_529 ;
V_8 -> V_530 ++ ;
} else {
V_201 -> V_521 = V_531 ;
V_201 -> V_523 = V_524 ;
V_92 -> V_528 = V_532 ;
V_8 -> V_533 ++ ;
}
} else {
V_201 -> V_521 = V_534 ;
V_201 -> V_111 . V_216 . V_217 = 0 ;
V_201 -> V_523 = 0 ;
V_92 -> V_528 = 0 ;
V_8 -> V_535 ++ ;
}
if ( V_8 -> V_115 == 3 &&
! ( V_8 -> V_116 & V_117 ) )
F_143 ( V_201 -> V_119 . V_120 . V_121 , V_92 ) ;
V_511 -> V_84 . V_473 = V_40 -> V_536 ;
if ( V_513 )
V_511 -> V_84 . V_473 =
V_8 -> V_133 . V_537 [ V_40 -> V_536 ] ;
if ( V_40 -> V_538 & V_539 )
V_511 -> V_84 . V_540 = 1 ;
else
V_511 -> V_84 . V_540 = 0 ;
V_511 -> V_84 . V_126 = ( V_40 -> V_538 & 0x0f ) ;
V_511 -> V_130 = V_32 ;
V_511 -> V_541 = F_139 ;
V_511 -> V_84 . V_542 = V_32 -> V_543 ;
V_511 -> V_5 = V_5 ;
}
static int
F_146 ( struct V_4 * V_5 ,
struct V_31 * V_32 ,
T_6 V_410 ,
V_189 V_544 )
{
struct V_141 * V_511 ;
T_2 * V_545 ;
struct V_92 * V_92 ;
struct V_1 * V_38 = V_32 -> V_38 ;
struct V_39 * V_143 = V_38 -> V_40 ;
if ( ! V_143 || ! F_133 ( V_143 ) ||
V_143 -> V_496 != V_497 )
return 0 ;
V_511 = & ( V_32 -> V_100 ) ;
V_511 -> V_5 = V_5 ;
V_545 = & V_511 -> V_84 ;
V_92 = V_32 -> V_92 ;
memset ( V_92 , 0 , sizeof( struct V_92 ) ) ;
F_145 ( V_410 , & V_92 -> V_514 ) ;
V_92 -> V_444 = V_544 ;
if ( V_5 -> V_8 -> V_115 == 3 &&
! ( V_5 -> V_8 -> V_116 & V_117 ) )
F_143 ( V_545 -> V_119 . V_120 . V_121 , V_92 ) ;
V_545 -> V_521 = V_534 ;
V_545 -> V_473 = V_143 -> V_536 ;
if ( V_5 -> V_8 -> V_115 == V_472 ) {
V_545 -> V_473 =
V_5 -> V_8 -> V_133 . V_537 [ V_143 -> V_536 ] ;
}
V_545 -> V_540 = ( V_143 -> V_538 & V_539 ) ? 1 : 0 ;
V_545 -> V_126 = ( V_143 -> V_538 & 0x0f ) ;
V_545 -> V_523 = 0 ;
V_545 -> V_111 . V_216 . V_217 = 0 ;
if ( V_32 -> V_543 > 0xff ) {
V_545 -> V_542 = 0 ;
} else
V_545 -> V_542 = V_32 -> V_543 ;
if ( V_5 -> V_8 -> V_115 == V_472 )
F_14 ( V_5 -> V_8 , V_32 ) ;
return 1 ;
}
int
F_147 ( struct V_12 * V_8 , V_189 V_546 )
{
V_8 -> F_135 = F_135 ;
V_8 -> F_144 = F_144 ;
switch ( V_546 ) {
case V_547 :
V_8 -> F_76 = F_38 ;
V_8 -> F_130 = F_83 ;
V_8 -> F_131 = F_108 ;
V_8 -> F_82 = F_48 ;
V_8 -> F_81 = F_77 ;
break;
case V_548 :
V_8 -> F_76 = F_73 ;
V_8 -> F_130 = F_127 ;
V_8 -> F_131 = F_129 ;
V_8 -> F_82 = F_59 ;
V_8 -> F_81 = F_79 ;
break;
default:
F_4 ( V_8 , V_20 , V_549 ,
L_85 ,
V_546 ) ;
return - V_550 ;
break;
}
V_8 -> F_22 = F_22 ;
V_8 -> F_139 = F_139 ;
return 0 ;
}
static void
F_148 ( struct V_12 * V_8 ,
struct V_141 * V_551 ,
struct V_141 * V_552 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_551 -> V_130 ;
if ( V_32 )
F_82 ( V_8 , V_32 ) ;
return;
}
const char *
F_149 ( struct V_44 * V_6 )
{
struct V_4 * V_5 = (struct V_4 * ) V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_354 , V_553 = 0 ;
static char V_554 [ 384 ] ;
memset ( V_554 , 0 , 384 ) ;
if ( V_8 && V_8 -> V_209 ) {
strncpy ( V_554 , V_8 -> V_555 , 256 ) ;
V_354 = strlen ( V_554 ) ;
snprintf ( V_554 + V_354 ,
384 - V_354 ,
L_86 ,
V_8 -> V_209 -> V_556 -> V_557 ,
V_8 -> V_209 -> V_558 ,
V_8 -> V_209 -> V_559 ) ;
V_354 = strlen ( V_554 ) ;
if ( V_8 -> V_560 [ 0 ] ) {
snprintf ( V_554 + V_354 ,
384 - V_354 ,
L_87 ,
V_8 -> V_560 ) ;
}
V_354 = strlen ( V_554 ) ;
if ( V_8 -> V_115 <= V_561 ) {
V_553 = F_150 ( V_8 ) ;
} else {
if ( V_8 -> V_133 . V_562 . V_563 )
V_553 =
V_8 -> V_133 . V_562 . V_563 ;
else
V_553 = V_8 -> V_133 . V_562 . V_564 ;
}
if ( V_553 != 0 )
snprintf ( V_554 + V_354 , 384 - V_354 ,
L_88 , V_553 ) ;
}
return V_554 ;
}
static T_7 void F_151 ( struct V_12 * V_8 )
{
unsigned long V_565 =
( V_49 + F_141 ( V_8 -> V_566 ) ) ;
if ( ! F_56 ( & V_8 -> V_147 . V_148 [ V_567 ] . V_568 ) )
F_152 ( & V_8 -> V_569 ,
V_565 ) ;
}
void F_153 ( struct V_12 * V_8 )
{
F_151 ( V_8 ) ;
}
void F_154 ( unsigned long V_512 )
{
struct V_12 * V_8 = (struct V_12 * ) V_512 ;
if ( V_8 -> V_507 & V_508 ) {
F_155 ( V_8 ,
& V_8 -> V_147 . V_148 [ V_567 ] , V_570 ) ;
if ( V_8 -> V_507 & V_571 )
F_151 ( V_8 ) ;
}
}
static int
F_156 ( struct V_44 * V_45 , struct V_13 * V_14 )
{
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_1 * V_38 ;
struct V_39 * V_143 ;
struct V_31 * V_32 ;
struct V_78 * V_79 = F_35 ( F_36 ( V_14 -> V_26 ) ) ;
int V_343 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
V_343 = F_157 ( V_79 ) ;
if ( V_343 ) {
V_14 -> V_48 = V_343 ;
goto V_572;
}
V_143 = V_38 -> V_40 ;
if ( ( F_94 ( V_14 ) != V_228 ) &&
( ! ( V_8 -> V_116 & V_117 ) ) ) {
F_4 ( V_8 , V_20 , V_21 ,
L_89
L_90
L_91 ,
V_14 -> V_14 [ 0 ] , F_94 ( V_14 ) ,
V_573 [ F_94 ( V_14 ) ] ) ;
goto V_572;
}
if ( ! V_143 || ! F_133 ( V_143 ) )
goto V_574;
if ( F_27 ( & V_143 -> V_464 ) >= V_143 -> V_500 )
goto V_574;
V_32 = F_81 ( V_8 , V_143 ) ;
if ( V_32 == NULL ) {
F_22 ( V_8 ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_92
L_93 ) ;
goto V_575;
}
V_32 -> V_42 = V_14 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_543 = 0 ;
V_32 -> V_50 = V_49 ;
V_14 -> V_238 = ( unsigned char * ) V_32 ;
if ( F_94 ( V_14 ) != V_228 ) {
if ( V_5 -> V_8 -> V_186 ) {
F_39 ( V_5 ,
V_94 , V_576 ,
L_94
L_95 ,
V_573 [ F_94 ( V_14 ) ] ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_14 ) ,
F_120 ( V_14 -> V_383 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_343 = F_131 ( V_8 , V_32 ) ;
} else {
if ( V_5 -> V_8 -> V_186 ) {
F_39 ( V_5 ,
V_94 , V_576 ,
L_96
L_97 ,
V_14 -> V_14 [ 0 ] ,
( unsigned long long ) F_95 ( V_14 ) ,
F_120 ( V_14 -> V_383 ) ,
( V_14 -> V_14 [ 1 ] >> 5 ) ) ;
}
V_343 = F_130 ( V_8 , V_32 ) ;
}
if ( V_343 )
goto V_577;
F_144 ( V_5 , V_32 , V_143 ) ;
F_23 ( & V_143 -> V_464 ) ;
V_343 = F_158 ( V_8 , V_567 ,
& V_32 -> V_100 , V_578 ) ;
if ( V_343 ) {
F_140 ( & V_143 -> V_464 ) ;
F_39 ( V_5 , V_94 , V_95 ,
L_98
L_99
L_80
L_100 ,
V_343 , V_14 -> V_14 [ 0 ] ,
V_14 -> V_26 ? V_14 -> V_26 -> V_447 : 0xffff ,
V_14 -> V_26 ? V_14 -> V_26 -> V_410 : ( V_579 ) - 1 ,
V_5 -> V_471 , V_143 -> V_232 ,
V_8 -> V_115 == V_472 ?
V_32 -> V_100 . V_150 : 0xffff ,
V_32 -> V_100 . V_84 . V_473 ,
V_32 -> V_100 . V_84 . V_474 ,
V_32 -> V_100 . V_84 . V_542 ,
( T_1 )
( V_14 -> V_383 -> V_543 / 1000 ) ) ;
goto V_577;
}
if ( V_8 -> V_507 & V_508 ) {
F_155 ( V_8 ,
& V_8 -> V_147 . V_148 [ V_567 ] , V_570 ) ;
if ( V_8 -> V_507 & V_571 )
F_151 ( V_8 ) ;
}
return 0 ;
V_577:
F_135 ( V_8 , V_32 ) ;
F_82 ( V_8 , V_32 ) ;
V_575:
return V_580 ;
V_574:
return V_581 ;
V_572:
V_14 -> V_506 ( V_14 ) ;
return 0 ;
}
static int
F_159 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_141 * V_84 ;
struct V_141 * V_582 ;
struct V_31 * V_32 ;
T_2 * V_41 , * V_583 ;
int V_264 = V_584 , V_128 = 0 ;
struct V_145 * V_585 ;
int V_586 , V_587 ;
unsigned long V_43 , V_588 ;
F_160 ( V_509 ) ;
V_128 = F_161 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_584 )
return V_128 ;
F_20 ( & V_8 -> V_64 , V_43 ) ;
if ( V_8 -> V_589 & V_590 ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_101
L_102 ) ;
return V_591 ;
}
V_32 = (struct V_31 * ) V_14 -> V_238 ;
if ( ! V_32 || ! V_32 -> V_42 ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_103
L_104 ,
V_584 , V_14 -> V_26 -> V_447 , V_14 -> V_26 -> V_410 ) ;
return V_584 ;
}
V_84 = & V_32 -> V_100 ;
if ( ! ( V_84 -> V_101 & V_592 ) ) {
F_21 ( & V_8 -> V_64 , V_43 ) ;
F_39 ( V_5 , V_370 , V_95 ,
L_105
L_106 ) ;
return V_591 ;
}
if ( V_32 -> V_42 != V_14 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_107
L_108 ) ;
goto V_593;
}
F_104 ( V_84 -> V_130 != V_32 ) ;
if ( V_84 -> V_101 & V_594 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_109 ) ;
F_21 ( & V_8 -> V_64 , V_43 ) ;
goto V_595;
}
V_582 = F_162 ( V_8 ) ;
if ( V_582 == NULL ) {
V_264 = V_591 ;
goto V_593;
}
V_84 -> V_101 |= V_594 ;
V_41 = & V_84 -> V_84 ;
V_583 = & V_582 -> V_84 ;
V_583 -> V_111 . V_596 . V_597 = V_598 ;
V_583 -> V_111 . V_596 . V_599 = V_41 -> V_473 ;
if ( V_8 -> V_115 == V_472 )
V_583 -> V_111 . V_596 . V_600 = V_84 -> V_150 ;
else
V_583 -> V_111 . V_596 . V_600 = V_41 -> V_474 ;
V_583 -> V_123 = 1 ;
V_583 -> V_126 = V_41 -> V_126 ;
V_582 -> V_601 = V_84 -> V_601 ;
V_582 -> V_101 |= V_602 ;
if ( V_84 -> V_101 & V_390 )
V_582 -> V_101 |= V_390 ;
if ( F_163 ( V_8 ) )
V_583 -> V_521 = V_603 ;
else
V_583 -> V_521 = V_604 ;
V_582 -> V_541 = V_605 ;
V_582 -> V_5 = V_5 ;
if ( V_8 -> V_115 == V_472 ) {
V_586 = V_606 + V_84 -> V_601 ;
V_585 = & V_8 -> V_147 . V_148 [ V_586 ] ;
F_20 ( & V_585 -> V_607 , V_588 ) ;
V_587 = F_164 ( V_8 , V_585 -> V_608 ,
V_582 , 0 ) ;
F_21 ( & V_585 -> V_607 , V_588 ) ;
} else {
V_587 = F_164 ( V_8 , V_567 ,
V_582 , 0 ) ;
}
F_21 ( & V_8 -> V_64 , V_43 ) ;
if ( V_587 == V_609 ) {
F_165 ( V_8 , V_582 ) ;
V_264 = V_591 ;
goto V_279;
}
if ( V_8 -> V_507 & V_571 )
F_155 ( V_8 ,
& V_8 -> V_147 . V_148 [ V_567 ] , V_570 ) ;
V_595:
V_32 -> V_509 = & V_509 ;
F_166 ( V_509 ,
( V_32 -> V_42 != V_14 ) ,
F_141 ( 2 * V_5 -> V_610 * 1000 ) ) ;
F_20 ( V_45 -> V_51 , V_43 ) ;
V_32 -> V_509 = NULL ;
F_21 ( V_45 -> V_51 , V_43 ) ;
if ( V_32 -> V_42 == V_14 ) {
V_264 = V_591 ;
F_39 ( V_5 , V_20 , V_95 ,
L_110
L_111
L_112 ,
V_84 -> V_150 , V_264 ,
V_14 -> V_26 -> V_447 , V_14 -> V_26 -> V_410 ) ;
}
goto V_279;
V_593:
F_21 ( & V_8 -> V_64 , V_43 ) ;
V_279:
F_39 ( V_5 , V_370 , V_95 ,
L_113
L_114 , V_264 , V_14 -> V_26 -> V_447 ,
V_14 -> V_26 -> V_410 ) ;
return V_264 ;
}
static char *
F_167 ( V_189 V_544 )
{
switch ( V_544 ) {
case V_611 :
return L_115 ;
case V_612 :
return L_116 ;
case V_613 :
return L_117 ;
case V_614 :
return L_118 ;
case V_615 :
return L_119 ;
case V_616 :
return L_120 ;
case V_617 :
return L_121 ;
default:
return L_122 ;
}
}
static int
F_168 ( struct V_4 * V_5 , struct V_31 * V_32 )
{
struct V_93 * V_395 = V_32 -> V_93 ;
T_1 V_618 ;
T_1 V_619 ;
V_189 V_620 ;
int V_264 = V_591 ;
if ( V_395 == NULL )
F_39 ( V_5 , V_94 , V_95 ,
L_123 ) ;
else {
V_618 = V_395 -> V_397 ;
V_619 = F_96 ( V_395 -> V_446 ) ;
V_620 = V_395 -> V_448 ;
F_39 ( V_5 , V_94 ,
V_95 ,
L_124
L_125 ,
V_618 ,
V_619 , V_620 ) ;
if ( ( V_395 -> V_397 & V_445 ) && ( V_619 == 8 ) ) {
switch ( V_620 ) {
case V_449 :
F_39 ( V_5 , V_94 , V_95 ,
L_126 ) ;
V_264 = V_584 ;
break;
case V_621 :
F_39 ( V_5 , V_94 , V_95 ,
L_127
L_128 ) ;
break;
case V_622 :
F_39 ( V_5 , V_94 , V_95 ,
L_129
L_130 ) ;
break;
case V_623 :
F_39 ( V_5 , V_94 , V_95 ,
L_131
L_132 ) ;
break;
}
}
}
return V_264 ;
}
static int
F_169 ( struct V_4 * V_5 , struct V_1 * V_38 ,
unsigned V_624 , T_6 V_625 ,
V_189 V_544 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_31 * V_32 ;
struct V_141 * V_142 ;
struct V_141 * V_626 ;
struct V_39 * V_40 = V_38 -> V_40 ;
int V_264 ;
int V_128 ;
if ( ! V_40 || ! F_133 ( V_40 ) )
return V_591 ;
V_32 = F_81 ( V_8 , V_38 -> V_40 ) ;
if ( V_32 == NULL )
return V_591 ;
V_32 -> V_543 = V_8 -> V_627 ;
V_32 -> V_38 = V_38 ;
V_128 = F_146 ( V_5 , V_32 , V_625 ,
V_544 ) ;
if ( ! V_128 ) {
F_82 ( V_8 , V_32 ) ;
return V_591 ;
}
V_142 = & V_32 -> V_100 ;
V_626 = F_170 ( V_8 ) ;
if ( V_626 == NULL ) {
F_82 ( V_8 , V_32 ) ;
return V_591 ;
}
V_142 -> V_541 = F_148 ;
F_39 ( V_5 , V_94 , V_95 ,
L_133
L_134 ,
F_167 ( V_544 ) , V_624 , V_625 ,
V_40 -> V_536 , V_40 -> V_526 , V_142 -> V_150 ,
V_142 -> V_101 ) ;
V_128 = F_171 ( V_8 , V_567 ,
V_142 , V_626 , V_32 -> V_543 ) ;
if ( ( V_128 != V_628 ) ||
( V_626 -> V_84 . V_461 != V_129 ) ) {
F_39 ( V_5 , V_20 , V_95 ,
L_135
L_136 ,
F_167 ( V_544 ) ,
V_624 , V_625 , V_626 -> V_84 . V_461 ,
V_626 -> V_84 . V_111 . V_459 [ 4 ] ,
V_142 -> V_101 ) ;
if ( V_128 == V_628 ) {
if ( V_626 -> V_84 . V_461 == V_470 )
V_264 = F_168 ( V_5 , V_32 ) ;
else
V_264 = V_591 ;
} else if ( V_128 == V_629 ) {
V_264 = V_630 ;
} else {
V_264 = V_591 ;
}
V_32 -> V_128 = V_467 ;
} else
V_264 = V_584 ;
F_165 ( V_8 , V_626 ) ;
if ( V_264 != V_630 )
F_82 ( V_8 , V_32 ) ;
return V_264 ;
}
static int
F_172 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned long V_631 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_39 ( V_5 , V_94 , V_95 ,
L_137 , V_38 ) ;
return V_591 ;
}
V_40 = V_38 -> V_40 ;
V_631 = F_141 ( 2 * V_5 -> V_610 * 1000 ) + V_49 ;
while ( F_24 ( V_631 , V_49 ) ) {
if ( ! V_40 || ! F_133 ( V_40 ) )
return V_591 ;
if ( V_40 -> V_496 == V_497 )
return V_584 ;
F_173 ( F_141 ( 500 ) ) ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 )
return V_591 ;
V_40 = V_38 -> V_40 ;
}
if ( ! V_40 || ! F_133 ( V_40 ) ||
( V_40 -> V_496 != V_497 ) )
return V_591 ;
return V_584 ;
}
static int
F_174 ( struct V_4 * V_5 , T_4 V_624 ,
T_6 V_625 , T_8 V_632 )
{
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_631 ;
int V_633 ;
V_633 = F_175 ( V_5 , V_624 , V_625 , V_632 ) ;
if ( V_633 )
F_176 ( V_5 ,
& V_8 -> V_147 . V_148 [ V_8 -> V_147 . V_634 ] ,
V_624 , V_625 , V_632 ) ;
V_631 = F_141 ( 2 * V_5 -> V_610 * 1000 ) + V_49 ;
while ( F_24 ( V_631 , V_49 ) && V_633 ) {
F_173 ( F_141 ( 20 ) ) ;
V_633 = F_175 ( V_5 , V_624 , V_625 , V_632 ) ;
}
if ( V_633 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_138 ,
( ( V_632 == V_635 ) ? L_139 :
( ( V_632 == V_636 ) ? L_140 :
( ( V_632 == V_637 ) ? L_141 : L_142 ) ) ) ,
V_633 ) ;
return V_591 ;
}
return V_584 ;
}
static int
F_177 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_624 = V_14 -> V_26 -> V_447 ;
T_6 V_625 = V_14 -> V_26 -> V_410 ;
struct V_638 V_419 ;
int V_128 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 || ! V_38 -> V_40 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_143 ,
V_38 ) ;
return V_591 ;
}
V_40 = V_38 -> V_40 ;
V_128 = F_161 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_584 )
return V_128 ;
V_128 = F_172 ( V_5 , V_14 ) ;
if ( V_128 == V_591 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_144 , V_38 ) ;
return V_591 ;
}
V_419 . V_405 = V_406 ;
V_419 . V_407 = V_639 ;
V_419 . V_410 = V_625 ;
memcpy ( V_419 . V_411 , & V_40 -> V_236 , sizeof( struct V_237 ) ) ;
memcpy ( V_419 . V_412 , & V_40 -> V_413 , sizeof( struct V_237 ) ) ;
F_178 ( V_45 , F_179 () ,
sizeof( V_419 ) , ( char * ) & V_419 , V_640 ) ;
V_128 = F_169 ( V_5 , V_38 , V_624 , V_625 ,
V_614 ) ;
F_39 ( V_5 , V_20 , V_95 ,
L_145
L_146 , V_624 , V_625 , V_128 ) ;
if ( V_128 == V_584 )
V_128 = F_174 ( V_5 , V_624 , V_625 ,
V_635 ) ;
return V_128 ;
}
static int
F_180 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
unsigned V_624 = V_14 -> V_26 -> V_447 ;
T_6 V_625 = V_14 -> V_26 -> V_410 ;
struct V_638 V_419 ;
int V_128 ;
V_38 = F_1 ( V_14 -> V_26 ) ;
if ( ! V_38 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_147 , V_38 ) ;
return V_591 ;
}
V_40 = V_38 -> V_40 ;
V_128 = F_161 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_584 )
return V_128 ;
V_128 = F_172 ( V_5 , V_14 ) ;
if ( V_128 == V_591 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_148 , V_38 ) ;
if ( V_40 ) {
F_70 ( V_45 -> V_51 ) ;
V_40 -> V_526 &= ~ V_641 ;
V_40 -> V_538 &= ~ V_539 ;
F_72 ( V_45 -> V_51 ) ;
}
F_174 ( V_5 , V_624 , V_625 ,
V_636 ) ;
return V_642 ;
}
V_419 . V_405 = V_406 ;
V_419 . V_407 = V_643 ;
V_419 . V_410 = 0 ;
memcpy ( V_419 . V_411 , & V_40 -> V_236 , sizeof( struct V_237 ) ) ;
memcpy ( V_419 . V_412 , & V_40 -> V_413 , sizeof( struct V_237 ) ) ;
F_178 ( V_45 , F_179 () ,
sizeof( V_419 ) , ( char * ) & V_419 , V_640 ) ;
V_128 = F_169 ( V_5 , V_38 , V_624 , V_625 ,
V_615 ) ;
F_39 ( V_5 , V_20 , V_95 ,
L_149
L_146 , V_624 , V_625 , V_128 ) ;
if ( V_128 == V_584 )
V_128 = F_174 ( V_5 , V_624 , V_625 ,
V_636 ) ;
return V_128 ;
}
static int
F_181 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_39 * V_143 = NULL ;
struct V_638 V_419 ;
int V_644 ;
int V_264 = V_584 , V_128 , V_47 ;
V_419 . V_405 = V_406 ;
V_419 . V_407 = V_645 ;
V_419 . V_410 = 0 ;
memcpy ( V_419 . V_411 , & V_5 -> V_646 , sizeof( struct V_237 ) ) ;
memcpy ( V_419 . V_412 , & V_5 -> V_647 , sizeof( struct V_237 ) ) ;
F_178 ( V_45 , F_179 () ,
sizeof( V_419 ) , ( char * ) & V_419 , V_640 ) ;
V_128 = F_161 ( V_14 ) ;
if ( V_128 != 0 && V_128 != V_584 )
return V_128 ;
for ( V_47 = 0 ; V_47 < V_648 ; V_47 ++ ) {
V_644 = 0 ;
F_70 ( V_45 -> V_51 ) ;
F_182 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_133 ( V_143 ) )
continue;
if ( V_5 -> V_8 -> V_649 &&
( V_143 -> V_538 & V_539 ) )
continue;
if ( V_143 -> V_496 == V_497 &&
V_143 -> V_650 == V_47 &&
V_143 -> V_79 ) {
V_644 = 1 ;
break;
}
}
F_72 ( V_45 -> V_51 ) ;
if ( ! V_644 )
continue;
V_128 = F_169 ( V_5 , V_143 -> V_79 -> V_651 ,
V_47 , 0 , V_615 ) ;
if ( V_128 != V_584 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_150 ,
V_47 ) ;
V_264 = V_591 ;
}
}
V_128 = F_174 ( V_5 , 0 , 0 , V_637 ) ;
if ( V_128 != V_584 )
V_264 = V_591 ;
F_39 ( V_5 , V_20 , V_95 ,
L_151 , V_264 ) ;
return V_264 ;
}
static int
F_183 ( struct V_13 * V_14 )
{
struct V_44 * V_45 = V_14 -> V_26 -> V_6 ;
struct V_4 * V_5 = (struct V_4 * ) V_45 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
int V_178 , V_264 = V_584 ;
F_39 ( V_5 , V_20 , V_95 ,
L_152 ) ;
F_184 ( V_8 , V_652 ) ;
F_185 ( V_8 ) ;
V_178 = F_186 ( V_8 ) ;
if ( V_178 )
V_264 = V_591 ;
V_178 = F_187 ( V_8 ) ;
if ( V_178 )
V_264 = V_591 ;
F_188 ( V_8 ) ;
if ( V_264 == V_591 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_153 ) ;
F_189 ( V_8 ) ;
}
return V_264 ;
}
static int
F_190 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
struct V_78 * V_79 = F_35 ( F_36 ( V_3 ) ) ;
T_1 V_653 = 0 ;
T_1 V_80 = 0 ;
int V_654 = 0 ;
T_1 V_655 ;
struct V_10 * V_656 ;
unsigned long V_43 ;
struct V_237 V_657 ;
if ( ! V_79 || F_157 ( V_79 ) )
return - V_658 ;
if ( V_8 -> V_9 ) {
F_191 ( V_79 -> V_659 , V_657 . V_234 . V_235 ) ;
F_20 ( & V_8 -> V_660 , V_43 ) ;
V_656 = F_192 ( V_8 ,
& V_8 -> V_661 ,
& V_5 -> V_646 ,
& V_657 ,
V_3 -> V_410 ) ;
if ( ! V_656 ) {
F_21 ( & V_8 -> V_660 , V_43 ) ;
V_656 = F_193 ( V_8 ,
& V_5 -> V_646 ,
& V_657 ,
V_3 -> V_410 , true ) ;
if ( ! V_656 )
return - V_662 ;
F_20 ( & V_8 -> V_660 , V_43 ) ;
F_65 ( & V_656 -> V_663 , & V_8 -> V_661 ) ;
}
V_656 -> V_11 = V_79 -> V_651 ;
V_656 -> V_664 = true ;
F_21 ( & V_8 -> V_660 , V_43 ) ;
V_3 -> V_7 = V_656 ;
} else {
V_3 -> V_7 = V_79 -> V_651 ;
}
V_655 = F_194 ( & V_8 -> V_655 ) ;
V_653 = V_8 -> V_665 ;
V_80 = V_5 -> V_666 + 2 ;
if ( ( V_655 * ( V_5 -> V_666 + 2 ) ) < V_653 )
return 0 ;
if ( V_653 >= V_8 -> V_667 - V_668 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_154
L_155 , V_653 ) ;
return 0 ;
} else if ( V_653 + V_80 >
V_8 -> V_667 - V_668 ) {
F_39 ( V_5 , V_370 , V_95 ,
L_156
L_157
L_158 ,
V_80 , V_8 -> V_667 ,
( V_8 -> V_667 - V_653 ) ) ;
V_80 = V_8 -> V_667 - V_653 ;
}
V_654 = F_76 ( V_5 , V_80 ) ;
if ( V_80 != V_654 ) {
F_39 ( V_5 , V_20 , V_95 ,
L_159
L_160
L_161 ,
V_80 , V_654 ) ;
}
if ( V_654 > 0 )
V_8 -> V_665 += V_654 ;
return 0 ;
}
static int
F_195 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
F_31 ( V_3 , V_5 -> V_666 ) ;
if ( V_8 -> V_507 & V_508 ) {
F_155 ( V_8 ,
& V_8 -> V_147 . V_148 [ V_567 ] , V_570 ) ;
if ( V_8 -> V_507 & V_571 )
F_151 ( V_8 ) ;
}
return 0 ;
}
static void
F_196 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_12 * V_8 = V_5 -> V_8 ;
unsigned long V_43 ;
struct V_10 * V_656 = V_3 -> V_7 ;
F_140 ( & V_8 -> V_655 ) ;
if ( ( V_8 -> V_9 ) && ( V_656 ) ) {
F_20 ( & V_8 -> V_660 , V_43 ) ;
V_656 -> V_664 = false ;
if ( ! V_656 -> V_388 )
F_197 ( V_8 , V_656 ) ;
F_21 ( & V_8 -> V_660 , V_43 ) ;
}
V_3 -> V_7 = NULL ;
return;
}
struct V_10 *
F_193 ( struct V_12 * V_8 , struct V_237 * V_669 ,
struct V_237 * V_657 , T_6 V_410 ,
bool V_670 )
{
struct V_10 * V_671 ;
int V_672 ;
if ( F_86 ( ! V_8 ) || ! V_669 || ! V_657 ||
! ( V_8 -> V_9 ) )
return NULL ;
if ( V_670 )
V_672 = V_673 ;
else
V_672 = V_96 ;
V_671 = F_198 ( V_8 -> V_674 , V_672 ) ;
if ( ! V_671 )
return NULL ;
F_78 ( & V_671 -> V_663 ) ;
V_671 -> V_11 = NULL ;
memcpy ( & V_671 -> V_675 . V_669 , V_669 ,
sizeof( struct V_237 ) ) ;
memcpy ( & V_671 -> V_675 . V_657 , V_657 ,
sizeof( struct V_237 ) ) ;
V_671 -> V_675 . V_410 = V_410 ;
V_671 -> V_388 = false ;
V_671 -> V_664 = false ;
return V_671 ;
}
void
F_197 ( struct V_12 * V_8 ,
struct V_10 * V_671 )
{
if ( F_86 ( ! V_8 ) || ! V_671 ||
! ( V_8 -> V_9 ) )
return;
if ( ! F_56 ( & V_671 -> V_663 ) )
F_55 ( & V_671 -> V_663 ) ;
F_199 ( V_671 , V_8 -> V_674 ) ;
return;
}
struct V_10 *
F_192 ( struct V_12 * V_8 , struct V_159 * V_151 ,
struct V_237 * V_669 ,
struct V_237 * V_657 , T_6 V_410 )
{
struct V_10 * V_671 ;
if ( F_86 ( ! V_8 ) || ! V_151 || ! V_669 || ! V_657 ||
! V_8 -> V_9 )
return NULL ;
F_182 (lun_info, list, listentry) {
if ( ( memcmp ( & V_671 -> V_675 . V_669 , V_669 ,
sizeof( struct V_237 ) ) == 0 ) &&
( memcmp ( & V_671 -> V_675 . V_657 , V_657 ,
sizeof( struct V_237 ) ) == 0 ) &&
( V_671 -> V_675 . V_410 == V_410 ) )
return V_671 ;
}
return NULL ;
}
bool
F_200 ( struct V_12 * V_8 , struct V_237 * V_669 ,
struct V_237 * V_657 , T_6 * V_676 ,
struct V_237 * V_677 ,
struct V_237 * V_678 ,
T_6 * V_679 ,
T_1 * V_680 )
{
unsigned long V_43 ;
struct V_10 * V_671 ;
struct V_681 * V_675 ;
T_6 V_410 ;
bool V_195 = false ;
if ( F_86 ( ! V_8 ) || ! V_669 || ! V_657 ||
! V_676 || ! V_677 ||
! V_678 || ! V_679 || ! V_680 ||
( * V_676 == V_682 ) ||
! V_8 -> V_9 )
return false ;
V_410 = * V_676 ;
* V_679 = V_682 ;
* V_676 = V_682 ;
F_20 ( & V_8 -> V_660 , V_43 ) ;
F_182 (lun_info, &phba->luns, listentry) {
if ( ( ( F_201 ( V_669 -> V_234 . V_235 ) == 0 ) ||
( memcmp ( & V_671 -> V_675 . V_669 , V_669 ,
sizeof( struct V_237 ) ) == 0 ) ) &&
( ( F_201 ( V_657 -> V_234 . V_235 ) == 0 ) ||
( memcmp ( & V_671 -> V_675 . V_657 , V_657 ,
sizeof( struct V_237 ) ) == 0 ) ) &&
( V_671 -> V_388 ) ) {
V_675 = & V_671 -> V_675 ;
if ( ( ! V_195 ) &&
( ( V_410 == V_683 ) ||
( V_675 -> V_410 == V_410 ) ) ) {
* V_679 = V_675 -> V_410 ;
memcpy ( V_677 ,
& V_675 -> V_669 ,
sizeof( struct V_237 ) ) ;
memcpy ( V_678 ,
& V_675 -> V_657 ,
sizeof( struct V_237 ) ) ;
if ( V_671 -> V_664 )
* V_680 =
V_684 ;
else
* V_680 = 0 ;
if ( V_8 -> V_685 & V_686 )
memset ( V_669 , 0x0 ,
sizeof( struct V_237 ) ) ;
if ( V_8 -> V_685 & V_687 )
memset ( V_657 , 0x0 ,
sizeof( struct V_237 ) ) ;
V_195 = true ;
} else if ( V_195 ) {
* V_676 = V_675 -> V_410 ;
memcpy ( V_669 , & V_675 -> V_669 ,
sizeof( struct V_237 ) ) ;
memcpy ( V_657 , & V_675 -> V_657 ,
sizeof( struct V_237 ) ) ;
break;
}
}
}
F_21 ( & V_8 -> V_660 , V_43 ) ;
return V_195 ;
}
bool
F_202 ( struct V_12 * V_8 , struct V_237 * V_669 ,
struct V_237 * V_657 , T_6 V_410 )
{
struct V_10 * V_671 ;
unsigned long V_43 ;
if ( F_86 ( ! V_8 ) || ! V_669 || ! V_657 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_660 , V_43 ) ;
V_671 = F_192 ( V_8 , & V_8 -> V_661 , V_669 ,
V_657 , V_410 ) ;
if ( V_671 ) {
if ( ! V_671 -> V_388 )
V_671 -> V_388 = true ;
F_21 ( & V_8 -> V_660 , V_43 ) ;
return true ;
}
V_671 = F_193 ( V_8 , V_669 , V_657 , V_410 ,
false ) ;
if ( V_671 ) {
V_671 -> V_388 = true ;
V_671 -> V_664 = false ;
F_65 ( & V_671 -> V_663 , & V_8 -> V_661 ) ;
F_21 ( & V_8 -> V_660 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_660 , V_43 ) ;
return false ;
}
bool
F_203 ( struct V_12 * V_8 , struct V_237 * V_669 ,
struct V_237 * V_657 , T_6 V_410 )
{
struct V_10 * V_671 ;
unsigned long V_43 ;
if ( F_86 ( ! V_8 ) || ! V_669 || ! V_657 ||
! V_8 -> V_9 )
return false ;
F_20 ( & V_8 -> V_660 , V_43 ) ;
V_671 = F_192 ( V_8 ,
& V_8 -> V_661 , V_669 ,
V_657 , V_410 ) ;
if ( V_671 ) {
V_671 -> V_388 = false ;
if ( ! V_671 -> V_664 )
F_197 ( V_8 , V_671 ) ;
F_21 ( & V_8 -> V_660 , V_43 ) ;
return true ;
}
F_21 ( & V_8 -> V_660 , V_43 ) ;
return false ;
}
