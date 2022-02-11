static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 ;
F_2 (tmp, &hw->sln_head) {
V_5 = (struct V_1 * ) V_8 ;
if ( V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 *
F_3 ( struct V_2 * V_3 , T_2 V_9 )
{
struct V_7 * V_10 , * V_11 ;
struct V_1 * V_12 = NULL , * V_13 = NULL ;
if ( F_4 ( & V_3 -> V_14 ) ) {
F_5 ( V_3 , V_15 ) ;
return NULL ;
}
F_2 (tmp1, &hw->sln_head) {
V_12 = (struct V_1 * ) V_10 ;
if ( V_12 -> V_16 == V_9 )
return V_12 ;
if ( F_4 ( & V_12 -> V_17 ) )
continue;
F_2 (tmp2, &sln->cln_head) {
V_13 = (struct V_1 * ) V_11 ;
if ( V_13 -> V_16 == V_9 )
return V_13 ;
}
}
F_5 ( V_3 , V_15 ) ;
return NULL ;
}
struct V_1 *
F_6 ( struct V_2 * V_3 , T_1 * V_18 )
{
struct V_7 * V_10 , * V_11 ;
struct V_1 * V_12 = NULL , * V_13 = NULL ;
if ( F_4 ( & V_3 -> V_14 ) ) {
F_5 ( V_3 , V_15 ) ;
return NULL ;
}
F_2 (tmp1, &hw->sln_head) {
V_12 = (struct V_1 * ) V_10 ;
if ( ! memcmp ( F_7 ( V_12 ) , V_18 , 8 ) )
return V_12 ;
if ( F_4 ( & V_12 -> V_17 ) )
continue;
F_2 (tmp2, &sln->cln_head) {
V_13 = (struct V_1 * ) V_11 ;
if ( ! memcmp ( F_7 ( V_13 ) , V_18 , 8 ) )
return V_13 ;
}
}
return NULL ;
}
static void
F_8 ( void * V_19 , T_1 type , T_1 V_20 , T_3 V_21 )
{
struct V_22 * V_23 = (struct V_22 * ) V_19 ;
V_23 -> V_24 = V_25 ;
V_23 -> V_26 = type ;
V_23 -> V_27 = V_20 ;
V_23 -> V_28 = F_9 ( V_21 ) ;
}
static int
F_10 ( T_1 * V_19 , T_4 V_29 )
{
if ( snprintf ( V_19 , V_29 , L_1 , F_11 () -> V_30 ) > 0 )
return 0 ;
return - 1 ;
}
static int
F_12 ( T_1 * V_19 , T_4 V_29 )
{
if ( snprintf ( V_19 , V_29 , L_2 ,
F_11 () -> V_31 ,
F_11 () -> V_32 ,
F_11 () -> V_33 ) > 0 )
return 0 ;
return - 1 ;
}
static inline void
F_13 ( T_1 * * V_34 , T_3 type , T_1 * V_35 , T_3 V_36 )
{
struct V_37 * V_38 = (struct V_37 * ) * V_34 ;
V_38 -> type = F_9 ( type ) ;
V_36 += 4 ;
V_36 = ( V_36 + 3 ) & ~ 3 ;
V_38 -> V_36 = F_9 ( V_36 ) ;
memcpy ( V_38 -> V_39 , V_35 , V_36 ) ;
* V_34 += V_36 ;
}
static void
F_14 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
void * V_23 ;
struct V_1 * V_5 = V_41 -> V_42 ;
if ( V_41 -> V_43 != V_44 ) {
F_15 ( V_5 , L_3 ,
V_41 -> V_43 ) ;
F_5 ( V_5 , V_45 ) ;
}
V_23 = V_41 -> V_46 . V_47 ;
if ( F_16 ( F_17 ( V_23 ) ) != V_48 ) {
F_15 ( V_5 , L_4 ,
F_18 ( V_23 ) , F_19 ( V_23 ) ) ;
}
}
static void
F_20 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
void * V_23 ;
T_1 * V_49 ;
T_2 V_36 = 0 ;
T_5 V_35 ;
T_6 V_50 ;
T_2 V_51 = 0 ;
struct V_1 * V_5 = V_41 -> V_42 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_1 V_19 [ 64 ] ;
T_1 * V_56 ;
if ( V_41 -> V_43 != V_44 ) {
F_15 ( V_5 , L_5 ,
V_41 -> V_43 ) ;
F_5 ( V_5 , V_45 ) ;
}
V_23 = V_41 -> V_46 . V_47 ;
if ( F_16 ( F_17 ( V_23 ) ) != V_48 ) {
F_15 ( V_5 , L_6 ,
F_18 ( V_23 ) , F_19 ( V_23 ) ) ;
}
if ( ! F_21 ( V_41 -> V_57 ) ) {
F_5 ( V_5 , V_45 ) ;
return;
}
memset ( V_23 , 0 , V_58 ) ;
F_8 ( V_23 , V_59 , V_60 , V_61 ) ;
V_49 = ( T_1 * ) F_22 ( V_23 ) ;
V_55 = (struct V_54 * ) V_49 ;
memcpy ( & V_55 -> V_62 , F_7 ( V_5 ) , 8 ) ;
V_49 += sizeof( * V_55 ) ;
V_53 = (struct V_52 * ) V_49 ;
V_53 -> V_51 = 0 ;
V_36 += sizeof( V_53 -> V_51 ) ;
V_49 += sizeof( V_53 -> V_51 ) ;
V_56 = & V_19 [ 0 ] ;
memset ( V_56 , 0 , V_63 ) ;
V_56 [ 2 ] = 1 ;
V_56 [ 7 ] = 1 ;
F_13 ( & V_49 , V_64 ,
V_56 , V_63 ) ;
V_51 ++ ;
V_35 = F_23 ( V_65 | V_66 ) ;
F_13 ( & V_49 , V_67 ,
( T_1 * ) & V_35 ,
V_68 ) ;
V_51 ++ ;
if ( V_3 -> V_69 [ V_5 -> V_4 ] . V_70 == V_71 )
V_35 = F_23 ( V_65 ) ;
else if ( V_3 -> V_69 [ V_5 -> V_4 ] . V_70 == V_72 )
V_35 = F_23 ( V_66 ) ;
else
V_35 = F_23 ( V_73 ) ;
F_13 ( & V_49 , V_74 ,
( T_1 * ) & V_35 ,
V_75 ) ;
V_51 ++ ;
V_50 = V_5 -> V_76 . V_77 . V_78 ;
F_13 ( & V_49 , V_79 ,
( T_1 * ) & V_50 , V_80 ) ;
V_51 ++ ;
strcpy ( V_19 , L_7 ) ;
F_13 ( & V_49 , V_81 , V_19 ,
( T_3 ) strlen ( V_19 ) ) ;
V_51 ++ ;
if ( ! F_10 ( V_19 , sizeof( V_19 ) ) ) {
F_13 ( & V_49 , V_82 ,
V_19 , ( T_3 ) strlen ( V_19 ) ) ;
V_51 ++ ;
}
V_53 -> V_51 = F_23 ( V_51 ) ;
V_36 = ( T_2 ) ( V_49 - ( T_1 * ) V_23 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_25 ( V_41 , F_14 ,
V_84 , & V_41 -> V_46 , V_36 ) ) {
F_5 ( V_5 , V_45 ) ;
F_15 ( V_5 , L_8 ) ;
}
F_26 ( & V_3 -> V_83 ) ;
}
static void
F_27 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
void * V_23 ;
T_1 * V_49 ;
T_2 V_36 = 0 ;
T_2 V_51 = 0 ;
T_5 V_85 = F_23 ( 65536 ) ;
struct V_86 * V_87 ;
struct V_1 * V_5 = V_41 -> V_42 ;
struct V_88 * V_89 ;
struct V_52 * V_53 ;
T_1 V_19 [ 64 ] ;
if ( V_41 -> V_43 != V_44 ) {
F_15 ( V_5 , L_9 ,
V_41 -> V_43 ) ;
F_5 ( V_5 , V_45 ) ;
}
if ( ! F_21 ( V_41 -> V_57 ) ) {
F_5 ( V_5 , V_45 ) ;
return;
}
V_23 = V_41 -> V_46 . V_47 ;
if ( F_16 ( F_17 ( V_23 ) ) != V_48 ) {
F_15 ( V_5 , L_10 ,
F_18 ( V_23 ) , F_19 ( V_23 ) ) ;
}
memset ( V_23 , 0 , V_58 ) ;
F_8 ( V_23 , V_59 , V_60 , V_90 ) ;
V_36 = V_58 ;
V_49 = ( T_1 * ) F_22 ( V_23 ) ;
V_87 = (struct V_86 * ) V_49 ;
memcpy ( & V_87 -> V_91 , F_7 ( V_5 ) , 8 ) ;
V_49 += sizeof( * V_87 ) ;
V_89 = (struct V_88 * ) V_49 ;
V_89 -> V_92 = F_23 ( 1 ) ;
memcpy ( & V_89 -> V_93 [ 0 ] . V_62 , F_7 ( V_5 ) , 8 ) ;
V_49 += sizeof( * V_89 ) ;
V_53 = (struct V_52 * ) V_49 ;
V_53 -> V_51 = 0 ;
V_36 += sizeof( V_53 -> V_51 ) ;
V_49 += sizeof( V_53 -> V_51 ) ;
F_13 ( & V_49 , V_94 , F_28 ( V_5 ) ,
V_95 ) ;
V_51 ++ ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
strcpy ( V_19 , L_11 ) ;
F_13 ( & V_49 , V_96 , V_19 ,
( T_3 ) strlen ( V_19 ) ) ;
V_51 ++ ;
F_13 ( & V_49 , V_97 ,
V_3 -> V_98 . V_99 , ( T_3 ) sizeof( V_3 -> V_98 . V_99 ) ) ;
V_51 ++ ;
F_13 ( & V_49 , V_100 , V_3 -> V_98 . V_91 ,
( T_3 ) sizeof( V_3 -> V_98 . V_91 ) ) ;
V_51 ++ ;
F_13 ( & V_49 , V_101 ,
V_3 -> V_102 , ( T_3 ) strlen ( V_3 -> V_102 ) ) ;
V_51 ++ ;
F_13 ( & V_49 , V_103 ,
V_3 -> V_104 , ( T_3 ) sizeof( V_3 -> V_104 ) ) ;
V_51 ++ ;
F_13 ( & V_49 , V_105 ,
V_3 -> V_106 , ( T_3 ) strlen ( V_3 -> V_106 ) ) ;
V_51 ++ ;
if ( ! F_12 ( V_19 , sizeof( V_19 ) ) ) {
F_13 ( & V_49 , V_107 ,
V_19 , ( T_3 ) strlen ( V_19 ) ) ;
V_51 ++ ;
}
F_13 ( & V_49 , V_108 ,
( T_1 * ) & V_85 ,
V_109 ) ;
V_36 = ( T_2 ) ( V_49 - ( T_1 * ) V_23 ) ;
V_51 ++ ;
V_53 -> V_51 = F_23 ( V_51 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_25 ( V_41 , F_20 ,
V_84 , & V_41 -> V_46 , V_36 ) ) {
F_5 ( V_5 , V_45 ) ;
F_15 ( V_5 , L_12 ) ;
}
F_26 ( & V_3 -> V_83 ) ;
}
static void
F_29 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
struct V_1 * V_5 = V_41 -> V_42 ;
void * V_23 ;
struct V_54 * V_55 ;
T_2 V_36 ;
if ( V_41 -> V_43 != V_44 ) {
F_15 ( V_5 , L_13 ,
V_41 -> V_43 ) ;
F_5 ( V_5 , V_45 ) ;
}
if ( ! F_21 ( V_41 -> V_57 ) ) {
F_5 ( V_5 , V_45 ) ;
return;
}
V_23 = V_41 -> V_46 . V_47 ;
if ( F_16 ( F_17 ( V_23 ) ) != V_48 ) {
F_15 ( V_5 , L_14 ,
F_18 ( V_23 ) , F_19 ( V_23 ) ) ;
}
memset ( V_23 , 0 , V_58 ) ;
F_8 ( V_23 , V_59 , V_60 , V_110 ) ;
V_36 = V_58 ;
V_55 = (struct V_54 * ) F_22 ( V_23 ) ;
memcpy ( & V_55 -> V_62 , F_7 ( V_5 ) , 8 ) ;
V_36 += sizeof( * V_55 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_25 ( V_41 , F_27 ,
V_84 , & V_41 -> V_46 , V_36 ) ) {
F_5 ( V_5 , V_45 ) ;
F_15 ( V_5 , L_15 ) ;
}
F_26 ( & V_3 -> V_83 ) ;
}
int
F_30 ( struct V_1 * V_5 , void * V_111 )
{
struct V_40 * V_41 ;
struct V_112 * V_113 = (struct V_112 * ) V_111 ;
void * V_23 ;
struct V_86 * V_87 ;
T_2 V_36 ;
if ( ! ( V_5 -> V_114 & V_115 ) )
return - V_116 ;
if ( ! F_21 ( V_113 ) )
F_5 ( V_5 , V_45 ) ;
V_41 = V_5 -> V_117 ;
V_41 -> V_42 = V_5 ;
V_41 -> V_57 = V_113 ;
V_23 = V_41 -> V_46 . V_47 ;
memset ( V_23 , 0 , V_58 ) ;
F_8 ( V_23 , V_59 , V_60 , V_118 ) ;
V_36 = V_58 ;
V_87 = (struct V_86 * ) F_22 ( V_23 ) ;
memcpy ( & V_87 -> V_91 , F_7 ( V_5 ) , 8 ) ;
V_36 += sizeof( * V_87 ) ;
if ( F_25 ( V_41 , F_29 ,
V_84 , & V_41 -> V_46 , V_36 ) ) {
F_5 ( V_5 , V_45 ) ;
F_15 ( V_5 , L_16 ) ;
}
return 0 ;
}
static void
F_31 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_1 * V_5 = ( (struct V_1 * ) V_120 -> V_121 ) ;
struct V_122 * V_123 = (struct V_122 * ) ( V_120 -> V_124 ) ;
struct V_125 * V_77 ;
struct V_126 * V_127 ;
enum V_128 V_129 ;
T_5 V_130 ;
V_129 = F_32 ( F_33 ( V_123 -> V_131 ) ) ;
if ( V_129 != V_44 ) {
F_34 ( V_3 , L_17 , V_129 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return;
}
F_24 ( & V_3 -> V_83 ) ;
memcpy ( V_5 -> V_133 , V_123 -> V_134 , sizeof( V_5 -> V_133 ) ) ;
memcpy ( & V_130 , & V_123 -> V_134 [ 3 ] , sizeof( T_1 ) * 3 ) ;
V_5 -> V_130 = F_33 ( V_130 ) ;
V_5 -> V_130 = V_5 -> V_130 >> 8 ;
memcpy ( F_28 ( V_5 ) , V_123 -> V_135 , 8 ) ;
memcpy ( F_7 ( V_5 ) , V_123 -> V_136 , 8 ) ;
V_77 = (struct V_125 * ) V_123 -> V_137 ;
V_5 -> V_76 . V_77 . V_138 = V_77 -> V_138 ;
V_5 -> V_76 . V_77 . V_139 = V_77 -> V_139 ;
V_5 -> V_76 . V_77 . V_140 = V_77 -> V_140 ;
V_5 -> V_76 . V_77 . V_141 = V_77 -> V_141 ;
V_5 -> V_76 . V_77 . V_78 = V_77 -> V_78 ;
V_5 -> V_76 . V_77 . V_142 = V_77 -> V_142 ;
V_5 -> V_76 . V_77 . V_143 = V_77 -> V_143 ;
V_127 = (struct V_126 * ) V_123 -> V_144 ;
V_5 -> V_76 . V_127 [ 2 ] . V_145 = V_127 -> V_145 ;
V_5 -> V_76 . V_127 [ 2 ] . V_146 = V_127 -> V_146 ;
V_5 -> V_76 . V_127 [ 2 ] . V_147 = V_127 -> V_147 ;
V_5 -> V_76 . V_127 [ 2 ] . V_148 = V_127 -> V_148 ;
F_26 ( & V_3 -> V_83 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
F_36 ( V_5 , V_149 ) ;
}
static int
F_37 ( struct V_1 * V_5 ,
void (* F_38) ( struct V_2 * , struct V_119 * ) )
{
struct V_2 * V_3 = V_5 -> V_150 ;
struct V_119 * V_120 ;
V_120 = F_39 ( V_3 -> V_132 , V_151 ) ;
if ( ! V_120 ) {
F_5 ( V_3 , V_152 ) ;
return - V_153 ;
}
F_40 ( V_5 , V_120 ,
V_154 ,
V_5 -> V_155 ,
V_5 -> V_16 ,
F_38 ) ;
if ( F_41 ( V_3 , V_120 ) ) {
F_34 ( V_3 , L_18 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return - V_156 ;
}
return 0 ;
}
static int
F_42 ( struct V_1 * V_5 , bool V_157 )
{
struct V_2 * V_3 = V_5 -> V_150 ;
struct V_119 * V_120 ;
enum V_128 V_129 ;
T_1 V_4 ;
T_1 V_158 ;
struct V_159 * V_160 ;
int V_161 ;
V_120 = F_39 ( V_3 -> V_132 , V_151 ) ;
if ( ! V_120 ) {
F_5 ( V_3 , V_152 ) ;
return - V_153 ;
}
V_4 = V_5 -> V_4 ;
V_158 = V_157 ? V_162 : V_163 ;
F_43 ( V_3 , L_19 ,
V_158 ? L_20 : L_21 , V_4 ) ;
F_44 ( V_5 , V_120 , V_154 ,
V_4 , V_158 , 0 , 0 , 0 , NULL ) ;
if ( F_41 ( V_3 , V_120 ) ) {
F_34 ( V_3 , L_22 ,
V_4 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return - V_156 ;
}
V_129 = F_45 ( V_120 ) ;
if ( V_129 != V_44 ) {
F_34 ( V_3 ,
L_23
L_24 , V_158 ? L_20 : L_21 , V_4 , V_129 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return - V_156 ;
}
if ( ! V_157 )
goto V_164;
V_160 = (struct V_159 * ) V_120 -> V_124 ;
memcpy ( F_28 ( V_5 ) , V_160 -> V_135 , 8 ) ;
memcpy ( F_7 ( V_5 ) , V_160 -> V_136 , 8 ) ;
for ( V_161 = 0 ; V_161 < V_165 ; V_161 ++ )
if ( V_3 -> V_69 [ V_161 ] . V_4 == V_4 )
memcpy ( V_3 -> V_69 [ V_161 ] . V_133 , V_160 -> V_166 , 6 ) ;
V_164:
F_35 ( V_120 , V_3 -> V_132 ) ;
return 0 ;
}
static void
F_46 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_1 * V_5 = (struct V_1 * ) V_120 -> V_121 ;
struct V_167 * V_168 ;
struct V_169 * V_123 =
(struct V_169 * ) ( V_120 -> V_124 ) ;
enum V_128 V_129 ;
V_129 = F_32 ( F_33 ( V_123 -> V_170 ) ) ;
if ( V_129 != V_44 ) {
F_47 ( V_5 , L_25 ,
V_129 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return;
}
F_24 ( & V_3 -> V_83 ) ;
V_168 = V_5 -> V_171 ;
V_168 -> V_172 = F_48 (
F_16 ( V_123 -> V_173 ) ) ;
V_168 -> V_174 = F_16 ( V_123 -> V_174 ) ;
V_168 -> V_175 = V_123 -> V_175 ;
V_168 -> V_176 = F_16 ( V_123 -> V_176 ) ;
V_168 -> V_177 = F_49 ( V_123 -> V_177 ) ;
V_168 -> V_178 = F_50 ( F_33 ( V_123 -> V_179 ) ) ;
V_168 -> V_180 = F_51 ( V_123 -> V_181 ) ;
V_168 -> V_182 = F_52 ( V_123 -> V_181 ) ;
V_168 -> V_183 = F_53 ( V_123 -> V_181 ) ;
V_168 -> V_4 = F_54 ( V_123 -> V_181 ) ;
memcpy ( V_168 -> V_184 , V_123 -> V_184 , sizeof( V_168 -> V_184 ) ) ;
memcpy ( V_168 -> V_133 , V_123 -> V_133 , sizeof( V_168 -> V_133 ) ) ;
memcpy ( V_168 -> V_185 , V_123 -> V_185 , sizeof( V_168 -> V_185 ) ) ;
memcpy ( V_168 -> V_186 , V_123 -> V_186 , sizeof( V_168 -> V_186 ) ) ;
memcpy ( V_168 -> V_187 , V_123 -> V_187 , sizeof( V_168 -> V_187 ) ) ;
F_26 ( & V_3 -> V_83 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
}
static int
F_55 ( struct V_1 * V_5 ,
void (* F_38) ( struct V_2 * , struct V_119 * ) )
{
struct V_2 * V_3 = V_5 -> V_150 ;
struct V_119 * V_120 ;
V_120 = F_39 ( V_3 -> V_132 , V_151 ) ;
if ( ! V_120 ) {
F_5 ( V_3 , V_152 ) ;
return - V_153 ;
}
F_56 ( V_5 , V_120 , V_154 ,
V_5 -> V_4 , V_5 -> V_155 , F_38 ) ;
if ( F_41 ( V_3 , V_120 ) ) {
F_34 ( V_3 , L_26 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return - V_156 ;
}
return 0 ;
}
static void
F_57 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_178 ,
T_2 V_188 )
{
struct V_1 * V_5 = NULL ;
V_5 = F_3 ( V_3 , V_188 ) ;
if ( ! V_5 ) {
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_34 ( V_3 , L_27 ,
V_4 ) ;
F_58 ( 0 ) ;
return;
}
if ( V_5 -> V_16 != V_189 ) {
F_26 ( & V_3 -> V_83 ) ;
F_59 ( V_3 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( ! V_5 ) {
F_34 ( V_3 ,
L_28
L_29 ,
V_4 , V_188 ) ;
F_58 ( 0 ) ;
return;
}
V_5 -> V_4 = V_4 ;
}
V_5 -> V_16 = V_188 ;
V_5 -> V_190 &= ~ 0xFFFF ;
V_5 -> V_190 |= V_188 ;
}
V_5 -> V_155 = V_178 ;
F_60 ( V_3 , L_30 , V_4 ) ;
F_5 ( V_5 , V_191 ) ;
F_61 ( & V_5 -> V_192 , V_193 ) ;
}
static void
F_62 ( struct V_1 * V_5 , enum V_194 V_195 )
{
struct V_112 * V_196 = (struct V_112 * ) & V_5 -> V_196 ;
struct V_7 * V_8 , * V_197 ;
struct V_112 * V_198 ;
F_63 (tmp, next, &rnhead->sm.sm_list) {
V_198 = (struct V_112 * ) V_8 ;
F_61 ( & V_198 -> V_192 , V_195 ) ;
}
}
static void
F_64 ( struct V_1 * V_5 )
{
struct V_112 * V_196 = (struct V_112 * ) & V_5 -> V_196 ;
struct V_7 * V_8 , * V_199 ;
struct V_112 * V_198 ;
F_63 (tmp, next_rn, &rnhead->sm.sm_list) {
V_198 = (struct V_112 * ) V_8 ;
F_65 ( V_5 , V_198 ) ;
}
}
static void
F_66 ( struct V_1 * V_5 , enum V_200 V_195 )
{
struct V_7 * V_8 ;
struct V_1 * V_13 , * V_12 ;
if ( F_67 ( V_5 ) ) {
F_61 ( & V_5 -> V_192 , V_195 ) ;
return;
}
V_12 = V_5 ;
F_2 (tmp, &sln->cln_head) {
V_13 = (struct V_1 * ) V_8 ;
F_61 ( & V_13 -> V_192 , V_195 ) ;
}
F_61 ( & V_5 -> V_192 , V_195 ) ;
}
static void
F_68 ( struct V_1 * V_5 )
{
F_66 ( V_5 , V_201 ) ;
}
static void
F_69 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_178 ,
T_2 V_188 )
{
struct V_167 * V_202 ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_188 ) ;
if ( V_5 ) {
V_202 = V_5 -> V_171 ;
F_5 ( V_5 , V_203 ) ;
if ( ! F_70 ( V_5 ) ) {
F_71 ( V_5 ,
L_31
L_32 ,
V_4 ) ;
F_5 ( V_5 , V_204 ) ;
return;
}
if ( V_202 -> V_4 != V_4 ) {
F_71 ( V_5 ,
L_33
L_34 , V_4 ) ;
F_5 ( V_5 , V_204 ) ;
return;
}
if ( V_5 -> V_155 != V_178 ) {
F_71 ( V_5 ,
L_33
L_35 , V_178 ) ;
F_5 ( V_5 , V_204 ) ;
return;
}
F_60 ( V_3 , L_36 , V_4 ) ;
F_68 ( V_5 ) ;
return;
} else {
F_72 ( V_3 ,
L_37 ,
V_188 ) ;
F_5 ( V_3 , V_204 ) ;
}
}
int
F_70 ( struct V_1 * V_5 )
{
return ( F_73 ( V_5 ) == ( ( V_205 ) V_206 ) ) ;
}
static void
F_74 ( struct V_1 * V_5 , enum V_200 V_195 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
struct V_1 * V_6 = V_3 -> V_6 ;
int V_207 ;
F_5 ( V_5 , V_208 [ V_195 ] ) ;
switch ( V_195 ) {
case V_193 :
F_76 ( & V_5 -> V_192 , V_209 ) ;
if ( F_77 ( V_5 ) ) {
V_207 = F_55 ( V_5 ,
F_46 ) ;
if ( V_207 != 0 ) {
F_5 ( V_5 , V_210 ) ;
break;
}
F_78 ( & V_5 -> V_171 -> V_211 , & V_6 -> V_212 ) ;
}
V_207 = F_37 ( V_5 , F_31 ) ;
if ( V_207 != 0 ) {
F_5 ( V_5 , V_210 ) ;
}
break;
case V_213 :
break;
default:
F_15 ( V_5 ,
L_38
L_39 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_214 ) ;
break;
}
}
static void
V_209 ( struct V_1 * V_5 , enum V_200 V_195 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
F_5 ( V_5 , V_208 [ V_195 ] ) ;
switch ( V_195 ) {
case V_193 :
F_71 ( V_5 ,
L_40
L_41 , V_5 -> V_4 ) ;
F_5 ( V_5 , V_204 ) ;
break;
case V_215 :
F_76 ( & V_5 -> V_192 , V_206 ) ;
F_26 ( & V_3 -> V_83 ) ;
F_36 ( V_5 , V_216 ) ;
F_24 ( & V_3 -> V_83 ) ;
break;
case V_201 :
case V_213 :
F_76 ( & V_5 -> V_192 , F_74 ) ;
if ( F_77 ( V_5 ) ) {
F_79 ( & V_5 -> V_171 -> V_211 ) ;
}
break;
default:
F_15 ( V_5 ,
L_38
L_39 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_214 ) ;
break;
}
}
static void
V_206 ( struct V_1 * V_5 , enum V_200 V_195 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
F_5 ( V_5 , V_208 [ V_195 ] ) ;
switch ( V_195 ) {
case V_215 :
F_15 ( V_5 ,
L_42
L_43 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_204 ) ;
break;
case V_201 :
F_76 ( & V_5 -> V_192 , V_217 ) ;
F_62 ( V_5 , V_218 ) ;
F_26 ( & V_3 -> V_83 ) ;
F_36 ( V_5 , V_219 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_77 ( V_5 ) ) {
F_79 ( & V_5 -> V_171 -> V_211 ) ;
}
break;
case V_213 :
F_76 ( & V_5 -> V_192 , V_217 ) ;
F_62 ( V_5 , V_218 ) ;
F_26 ( & V_3 -> V_83 ) ;
F_36 ( V_5 , V_219 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_77 ( V_5 ) ) {
F_79 ( & V_5 -> V_171 -> V_211 ) ;
}
break;
case V_220 :
F_76 ( & V_5 -> V_192 , F_74 ) ;
F_62 ( V_5 , V_221 ) ;
break;
case V_222 :
F_76 ( & V_5 -> V_192 , V_217 ) ;
F_62 ( V_5 , V_218 ) ;
break;
default:
F_15 ( V_5 ,
L_38
L_39 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_214 ) ;
F_58 ( 0 ) ;
break;
}
}
static void
V_217 ( struct V_1 * V_5 , enum V_200 V_195 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
struct V_1 * V_6 = V_3 -> V_6 ;
int V_207 ;
F_5 ( V_5 , V_208 [ V_195 ] ) ;
switch ( V_195 ) {
case V_193 :
F_76 ( & V_5 -> V_192 , V_209 ) ;
if ( F_77 ( V_5 ) ) {
V_207 = F_55 ( V_5 ,
F_46 ) ;
if ( V_207 != 0 ) {
F_5 ( V_5 , V_210 ) ;
break;
}
F_78 ( & V_5 -> V_171 -> V_211 , & V_6 -> V_212 ) ;
}
V_207 = F_37 ( V_5 , F_31 ) ;
if ( V_207 != 0 ) {
F_5 ( V_5 , V_210 ) ;
}
break;
case V_201 :
case V_213 :
case V_222 :
F_15 ( V_5 ,
L_42
L_44 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_204 ) ;
break;
case V_220 :
F_76 ( & V_5 -> V_192 , F_74 ) ;
F_62 ( V_5 , V_221 ) ;
break;
default:
F_15 ( V_5 ,
L_38
L_45 , V_195 , V_5 -> V_130 ) ;
F_5 ( V_5 , V_214 ) ;
F_58 ( 0 ) ;
break;
}
}
static void
F_80 ( struct V_223 * V_223 )
{
struct V_167 * V_171 = F_81 ( V_223 ,
struct V_167 , V_223 ) ;
F_82 ( V_171 ) ;
}
void
F_83 ( struct V_1 * V_5 , T_7 * V_224 )
{
if ( F_73 ( V_5 ) == ( ( V_205 ) F_74 ) ) {
strcpy ( V_224 , L_46 ) ;
return;
}
if ( F_73 ( V_5 ) == ( ( V_205 ) V_206 ) ) {
strcpy ( V_224 , L_47 ) ;
return;
}
if ( F_73 ( V_5 ) == ( ( V_205 ) V_217 ) ) {
strcpy ( V_224 , L_48 ) ;
return;
}
strcpy ( V_224 , L_49 ) ;
}
int
F_84 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_225 * V_226 )
{
struct V_119 * V_120 ;
struct V_227 V_228 ;
enum V_128 V_129 ;
int V_229 ;
V_120 = F_39 ( V_3 -> V_132 , V_151 ) ;
if ( ! V_120 ) {
F_34 ( V_3 , L_50 ) ;
return - V_156 ;
}
V_228 . V_4 = V_4 ;
for ( V_229 = 1 ; V_229 <= 3 ; V_229 ++ ) {
V_228 . V_229 = ( V_229 - 1 ) * 6 + 1 ;
V_228 . V_230 = 6 ;
if ( V_229 == 3 )
V_228 . V_230 = 4 ;
F_85 ( V_3 , V_120 , V_154 ,
& V_228 , NULL ) ;
if ( F_41 ( V_3 , V_120 ) ) {
F_34 ( V_3 , L_51 ) ;
F_35 ( V_120 , V_3 -> V_132 ) ;
return - V_156 ;
}
F_86 ( V_3 , V_120 , & V_129 ,
& V_228 , V_226 ) ;
}
F_35 ( V_120 , V_3 -> V_132 ) ;
return 0 ;
}
static void
F_87 ( struct V_2 * V_3 , void * V_231 , T_2 V_36 )
{
struct V_232 * V_233 = F_88 ( V_3 ) ;
struct V_40 * V_234 = NULL ;
struct V_235 * V_236 ;
V_236 = (struct V_235 * ) V_231 ;
if ( V_36 < sizeof( struct V_235 ) ) {
F_34 ( V_233 -> V_3 ,
L_52 , V_36 ) ;
V_233 -> V_237 . V_210 ++ ;
return;
}
V_234 = (struct V_40 * ) ( ( V_238 ) V_236 -> V_239 ) ;
V_234 -> V_43 = F_89 ( V_236 ) ;
F_24 ( & V_3 -> V_83 ) ;
if ( F_90 ( V_233 , V_234 ) != 0 ) {
F_34 ( V_233 -> V_3 ,
L_53 ,
V_234 ) ;
V_233 -> V_237 . V_210 ++ ;
F_26 ( & V_3 -> V_83 ) ;
return;
}
V_233 = F_88 ( V_3 ) ;
F_79 ( & V_234 -> V_192 . V_240 ) ;
V_233 -> V_237 . V_241 -- ;
F_26 ( & V_3 -> V_83 ) ;
if ( V_234 -> V_242 )
V_234 -> V_242 ( V_3 , V_234 ) ;
}
void
F_91 ( struct V_2 * V_3 , T_8 V_243 , T_9 * V_23 )
{
struct V_1 * V_5 ;
struct V_112 * V_198 ;
T_1 V_4 , V_244 = * ( T_1 * ) V_23 ;
struct V_159 * V_160 ;
struct V_245 * V_231 ;
struct V_246 * V_247 ;
enum V_248 V_249 ;
T_2 V_178 , V_250 , V_188 ;
enum V_200 V_195 ;
if ( V_243 == V_251 && V_244 == V_252 ) {
V_160 = (struct V_159 * ) V_23 ;
V_249 = V_160 -> V_249 ;
V_4 = F_92 (
F_33 ( V_160 -> V_253 ) ) ;
V_178 = F_93 ( F_33 ( V_160 -> V_254 ) ) ;
V_188 = F_94 ( F_33 ( V_160 -> V_255 ) ) ;
if ( V_249 == V_256 ) {
F_24 ( & V_3 -> V_83 ) ;
F_57 ( V_3 , V_4 , V_178 , V_188 ) ;
F_26 ( & V_3 -> V_83 ) ;
} else if ( V_249 == V_257 ) {
F_24 ( & V_3 -> V_83 ) ;
F_69 ( V_3 , V_4 , V_178 , V_188 ) ;
F_26 ( & V_3 -> V_83 ) ;
} else {
F_72 ( V_3 , L_54 ,
V_160 -> V_249 ) ;
F_5 ( V_3 , V_258 ) ;
}
} else if ( V_243 == V_259 ) {
V_231 = (struct V_245 * ) ( V_23 + 4 ) ;
if ( F_95 ( F_49 ( V_231 -> V_260 ) )
== V_261 ) {
V_247 = (struct V_246 * ) ( V_23 + 4 ) ;
V_250 = F_96 (
F_33 ( V_247 -> V_131 ) ) ;
V_188 = F_97 (
F_33 ( V_247 -> V_262 ) ) ;
F_43 ( V_3 ,
L_55
L_56 , V_250 ,
V_247 -> V_263 , V_188 ) ;
if ( V_247 -> V_264 != V_265 ) {
F_34 ( V_3 ,
L_57
L_58 ,
V_247 -> V_264 ,
V_250 ) ;
F_5 ( V_3 , V_204 ) ;
return;
}
F_24 ( & V_3 -> V_83 ) ;
V_5 = F_3 ( V_3 , V_188 ) ;
if ( ! V_5 ) {
F_34 ( V_3 ,
L_59
L_60 , V_188 , V_250 ) ;
F_5 ( V_3 , V_204 ) ;
goto V_266;
}
V_198 = F_98 ( V_5 , V_250 ,
& V_247 -> V_267 . V_268 ) ;
if ( ! V_198 ) {
F_15 ( V_5 ,
L_61
L_62 , V_250 ) ;
F_5 ( V_3 , V_204 ) ;
goto V_266;
}
V_5 -> V_269 = V_5 -> V_270 ;
V_5 -> V_270 = V_247 -> V_263 ;
F_5 ( V_5 , V_271 [ V_247 -> V_263 ] ) ;
V_195 = F_99 ( V_247 -> V_263 ) ;
if ( V_195 ) {
F_15 ( V_5 ,
L_63
L_64 , V_195 ,
V_247 -> V_263 , V_250 ) ;
F_61 ( & V_5 -> V_192 , V_195 ) ;
}
F_100 ( V_198 , V_247 -> V_263 ) ;
V_266:
F_26 ( & V_3 -> V_83 ) ;
return;
} else {
F_72 ( V_3 , L_65 ,
F_95 ( F_49 ( ( V_231 -> V_260 ) ) ) ) ;
F_5 ( V_3 , V_258 ) ;
}
} else if ( V_243 == V_251 ) {
V_231 = (struct V_245 * ) ( V_23 ) ;
if ( F_95 ( F_49 ( V_231 -> V_260 ) ) == V_272 ) {
F_87 ( V_3 , V_231 ,
sizeof( struct V_235 ) ) ;
} else {
F_72 ( V_3 , L_65 ,
F_95 ( F_49 ( ( V_231 -> V_260 ) ) ) ) ;
F_5 ( V_3 , V_258 ) ;
}
} else {
F_72 ( V_3 , L_66 , V_244 ) ;
F_5 ( V_3 , V_258 ) ;
}
}
int
F_101 ( struct V_1 * V_5 )
{
int V_207 = 0 ;
if ( F_77 ( V_5 ) && ! ( V_5 -> V_114 & V_273 ) ) {
V_207 = F_42 ( V_5 , 1 ) ;
V_5 -> V_114 |= V_273 ;
}
return V_207 ;
}
void
F_102 ( struct V_1 * V_5 )
{
F_66 ( V_5 , V_213 ) ;
if ( F_77 ( V_5 ) && ( V_5 -> V_114 & V_273 ) ) {
F_42 ( V_5 , 0 ) ;
V_5 -> V_114 &= ~ V_273 ;
}
F_15 ( V_5 , L_67 , V_5 ) ;
}
void
F_103 ( struct V_1 * V_5 )
{
F_66 ( V_5 , V_220 ) ;
if ( F_77 ( V_5 ) )
V_5 -> V_16 = V_189 ;
F_15 ( V_5 , L_68 , V_5 ) ;
}
static int
F_104 ( struct V_40 * V_234 , T_2 V_274 ,
T_2 V_275 , T_1 V_158 , T_2 V_276 ,
T_2 V_277 , T_2 V_278 , T_1 * V_279 )
{
struct V_235 * V_231 ;
T_5 V_280 ;
V_231 = (struct V_235 * ) V_279 ;
V_231 -> V_281 = F_105 ( F_106 ( V_272 ) |
F_107 ( V_275 ) ) ;
V_274 = F_108 ( V_274 , 16 ) ;
V_231 -> V_282 = F_105 ( F_109 ( V_278 ) |
F_110 ( V_274 ) ) ;
V_231 -> V_283 = V_158 ;
V_231 -> V_284 = 0 ;
V_231 -> V_285 = 0 ;
V_231 -> V_239 = V_234 -> V_286 ;
V_231 -> V_287 = F_111 ( F_112 (
V_234 -> V_42 -> V_150 , V_234 -> V_288 ) ) ;
V_231 -> V_289 = F_113 ( 1 ) ;
V_231 -> V_290 = ( T_1 ) V_234 -> V_291 ;
V_280 = F_23 ( V_276 ) ;
memcpy ( V_231 -> V_292 , F_114 ( V_280 ) , 3 ) ;
V_280 = F_23 ( V_277 ) ;
memcpy ( V_231 -> V_293 , F_114 ( V_280 ) , 3 ) ;
V_231 -> V_294 = F_105 ( V_234 -> V_46 . V_36 ) ;
V_231 -> V_295 = F_115 ( V_234 -> V_46 . V_296 ) ;
return 0 ;
}
static int
F_116 ( struct V_232 * V_233 , struct V_40 * V_234 ,
T_1 V_158 , struct V_297 * V_49 ,
T_2 V_298 )
{
struct V_299 V_300 ;
struct V_1 * V_5 = V_234 -> V_42 ;
struct V_112 * V_198 = V_234 -> V_57 ;
struct V_2 * V_3 = V_233 -> V_3 ;
T_1 V_279 [ 64 ] ;
struct V_301 V_302 ;
T_2 V_303 = 0 ;
T_1 V_304 = 0 ;
T_2 V_305 = 0 ;
int V_306 = 0 ;
V_303 = sizeof( struct V_235 ) ;
if ( V_298 < 256 ) {
V_303 += F_117 ( V_298 , 8 ) ;
V_304 = ( T_1 ) V_298 ;
} else
V_303 += sizeof( struct V_301 ) ;
V_303 = F_117 ( V_303 , 16 ) ;
V_306 = F_118 ( V_3 , V_233 -> V_307 , V_303 , & V_300 ) ;
if ( V_306 != 0 ) {
F_34 ( V_3 , L_69 ,
V_234 , V_306 ) ;
return V_306 ;
}
F_104 ( V_234 , V_303 , V_304 , V_158 ,
V_5 -> V_130 , V_198 -> V_130 ,
F_119 ( V_198 ) ,
& V_279 [ 0 ] ) ;
F_120 ( & V_279 [ 0 ] , & V_300 , V_305 ,
sizeof( struct V_235 ) ) ;
V_305 += sizeof( struct V_235 ) ;
if ( V_304 )
F_120 ( V_49 -> V_47 , & V_300 , V_305 , V_304 ) ;
else {
V_302 . V_308 = F_23 ( F_121 ( V_309 ) |
V_310 | F_122 ( 1 ) ) ;
V_302 . V_311 = F_105 ( V_298 ) ;
V_302 . V_312 = F_115 ( V_49 -> V_296 ) ;
F_120 ( & V_302 , & V_300 , F_117 ( V_305 , 8 ) ,
sizeof( struct V_301 ) ) ;
}
F_123 ( V_233 -> V_3 , V_233 -> V_307 , false ) ;
return V_306 ;
}
static int
F_25 ( struct V_40 * V_234 ,
void (* V_242) ( struct V_2 * , struct V_40 * ) ,
enum V_313 V_314 , struct V_297 * V_49 ,
T_2 V_298 )
{
struct V_2 * V_3 = F_75 ( V_234 -> V_42 ) ;
struct V_232 * V_233 = F_88 ( V_3 ) ;
int V_207 ;
V_234 -> V_242 = V_242 ;
V_234 -> V_286 = ( V_238 ) ( V_234 ) ;
V_234 -> V_307 = V_233 -> V_307 ;
V_234 -> V_288 = V_233 -> V_288 ;
V_207 = F_116 ( V_233 , V_234 , V_314 , V_49 , V_298 ) ;
if ( V_207 == 0 ) {
F_78 ( & V_234 -> V_192 . V_240 , & V_233 -> V_315 ) ;
V_233 -> V_237 . V_241 ++ ;
}
return V_207 ;
}
static int
F_124 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
struct V_297 * V_46 ;
V_5 -> V_117 = F_125 ( sizeof( struct V_40 ) , V_316 ) ;
if ( ! V_5 -> V_117 ) {
F_47 ( V_5 , L_70 ) ;
F_5 ( V_3 , V_152 ) ;
return - V_153 ;
}
V_46 = & V_5 -> V_117 -> V_46 ;
V_46 -> V_36 = 2048 ;
V_46 -> V_47 = F_126 ( V_3 -> V_317 , V_46 -> V_36 ,
& V_46 -> V_296 ) ;
if ( ! V_46 -> V_47 ) {
F_34 ( V_3 , L_71 ) ;
F_82 ( V_5 -> V_117 ) ;
V_5 -> V_117 = NULL ;
return - V_153 ;
}
V_5 -> V_114 |= V_115 ;
return 0 ;
}
static int
F_127 ( struct V_1 * V_5 )
{
struct V_297 * V_46 ;
struct V_2 * V_3 = F_75 ( V_5 ) ;
if ( ! V_5 -> V_117 )
return 0 ;
V_46 = & V_5 -> V_117 -> V_46 ;
if ( V_46 -> V_47 )
F_128 ( V_3 -> V_317 , V_46 -> V_36 , V_46 -> V_47 ,
V_46 -> V_296 ) ;
F_82 ( V_5 -> V_117 ) ;
return 0 ;
}
int
F_129 ( struct V_1 * V_5 , unsigned long V_318 ,
unsigned long time , unsigned long V_319 ,
unsigned long V_320 )
{
int V_207 = 0 ;
if ( time >= V_319 )
return 1 ;
if ( ! V_5 -> V_321 )
V_5 -> V_321 = V_318 ;
if ( ( ( V_318 - V_5 -> V_321 ) >= V_320 ) ) {
if ( ! V_5 -> V_322 )
V_5 -> V_322 = V_5 -> V_323 ;
else {
if ( V_5 -> V_322 == V_5 -> V_323 )
return 1 ;
V_5 -> V_322 = V_5 -> V_323 ;
}
V_5 -> V_321 = V_318 ;
}
return V_207 ;
}
void
F_130 ( struct V_2 * V_3 , enum V_324 V_325 )
{
struct V_7 * V_8 ;
struct V_1 * V_5 ;
F_43 ( V_3 , L_72 , V_325 ) ;
F_2 (tmp, &hw->sln_head) {
V_5 = (struct V_1 * ) V_8 ;
switch ( V_325 ) {
case V_326 :
F_101 ( V_5 ) ;
break;
case V_327 :
case V_328 :
F_103 ( V_5 ) ;
break;
case V_329 :
F_102 ( V_5 ) ;
break;
default:
break;
}
}
}
void
F_131 ( struct V_2 * V_3 , T_1 V_4 , bool V_330 )
{
struct V_7 * V_8 ;
struct V_1 * V_5 ;
F_43 ( V_3 , L_73 , V_4 ) ;
F_2 (tmp, &hw->sln_head) {
V_5 = (struct V_1 * ) V_8 ;
if ( V_5 -> V_4 != V_4 )
continue;
if ( V_330 )
F_102 ( V_5 ) ;
else
F_101 ( V_5 ) ;
}
}
static int
F_132 ( struct V_1 * V_5 )
{
int V_207 = - V_156 ;
struct V_1 * V_6 , * V_331 ;
struct V_2 * V_3 = F_75 ( V_5 ) ;
F_133 ( & V_5 -> V_192 , F_74 ) ;
V_5 -> V_16 = V_189 ;
V_5 -> V_155 = V_189 ;
if ( F_134 ( V_5 ) ) {
V_5 -> V_171 = F_125 ( sizeof( struct V_167 ) , V_316 ) ;
if ( ! V_5 -> V_171 ) {
F_47 ( V_5 , L_74 ) ;
F_5 ( V_3 , V_152 ) ;
goto V_332;
}
F_135 ( & V_5 -> V_212 ) ;
F_136 ( & V_5 -> V_171 -> V_223 ) ;
if ( V_333 && F_124 ( V_5 ) )
goto V_332;
} else {
V_6 = F_137 ( V_5 ) ;
if ( F_67 ( V_5 ) ) {
V_331 = F_138 ( V_5 ) ;
F_139 ( & V_331 -> V_171 -> V_223 ) ;
V_5 -> V_171 = V_331 -> V_171 ;
} else {
V_5 -> V_171 = F_125 ( sizeof( struct V_167 ) ,
V_316 ) ;
if ( ! V_5 -> V_171 ) {
F_47 ( V_5 , L_75 ) ;
F_5 ( V_3 , V_152 ) ;
goto V_332;
}
F_136 ( & V_5 -> V_171 -> V_223 ) ;
if ( V_333 && F_124 ( V_5 ) )
goto V_332;
}
}
return 0 ;
V_332:
return V_207 ;
}
static void
F_140 ( struct V_1 * V_5 )
{
struct V_1 * V_331 ;
F_64 ( V_5 ) ;
if ( F_67 ( V_5 ) ) {
V_331 = F_138 ( V_5 ) ;
F_141 ( & V_331 -> V_171 -> V_223 , F_80 ) ;
} else {
F_141 ( & V_5 -> V_171 -> V_223 , F_80 ) ;
if ( V_333 )
F_127 ( V_5 ) ;
}
V_5 -> V_171 = NULL ;
}
int
F_142 ( struct V_1 * V_5 , struct V_2 * V_3 ,
struct V_1 * V_331 )
{
int V_207 = - V_156 ;
F_75 ( V_5 ) = V_3 ;
if ( V_331 )
V_5 -> V_331 = V_331 ;
else
V_5 -> V_331 = NULL ;
V_5 -> V_323 = 0 ;
V_5 -> V_322 = 0 ;
V_5 -> V_321 = 0 ;
F_135 ( & V_5 -> V_196 ) ;
F_135 ( & V_5 -> V_17 ) ;
V_5 -> V_334 . V_335 = V_3 -> V_334 . V_335 ;
if ( F_132 ( V_5 ) )
goto V_332;
F_24 ( & V_3 -> V_83 ) ;
F_78 ( & V_5 -> V_192 . V_240 , V_331 ? & V_331 -> V_17 : & V_3 -> V_14 ) ;
if ( V_331 )
V_331 -> V_336 ++ ;
F_26 ( & V_3 -> V_83 ) ;
V_3 -> V_337 ++ ;
return 0 ;
V_332:
F_75 ( V_5 ) = NULL ;
return V_207 ;
}
void
F_143 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_75 ( V_5 ) ;
F_140 ( V_5 ) ;
F_24 ( & V_3 -> V_83 ) ;
F_79 ( & V_5 -> V_192 . V_240 ) ;
if ( V_5 -> V_331 )
V_5 -> V_331 -> V_336 -- ;
if ( F_4 ( & V_3 -> V_14 ) )
V_3 -> V_6 = NULL ;
else
V_3 -> V_6 = (struct V_1 * ) F_144 ( & V_3 -> V_14 ) ;
F_26 ( & V_3 -> V_83 ) ;
F_75 ( V_5 ) = NULL ;
V_3 -> V_337 -- ;
}
