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
F_13 ( T_1 * * V_34 , T_3 type , void * V_35 , T_4 V_36 )
{
T_3 V_37 ;
struct V_38 * V_39 = (struct V_38 * ) * V_34 ;
if ( F_14 ( V_36 > V_40 ) )
return;
V_37 = V_36 ;
V_39 -> type = F_9 ( type ) ;
V_37 += 4 ;
V_37 = ( V_37 + 3 ) & ~ 3 ;
V_39 -> V_37 = F_9 ( V_37 ) ;
memcpy ( V_39 -> V_41 , V_35 , V_36 ) ;
if ( V_37 > V_36 )
memset ( V_39 -> V_41 + V_36 , 0 , V_37 - V_36 ) ;
* V_34 += V_37 ;
}
static void
F_15 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
void * V_23 ;
struct V_1 * V_5 = V_43 -> V_44 ;
if ( V_43 -> V_45 != V_46 ) {
F_16 ( V_5 , L_3 ,
V_43 -> V_45 ) ;
F_5 ( V_5 , V_47 ) ;
}
V_23 = V_43 -> V_48 . V_49 ;
if ( F_17 ( F_18 ( V_23 ) ) != V_50 ) {
F_16 ( V_5 , L_4 ,
F_19 ( V_23 ) , F_20 ( V_23 ) ) ;
}
}
static void
F_21 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
void * V_23 ;
T_1 * V_51 ;
T_2 V_37 = 0 ;
T_5 V_35 ;
T_6 V_52 ;
T_2 V_53 = 0 ;
struct V_1 * V_5 = V_43 -> V_44 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_1 V_19 [ 64 ] ;
T_1 * V_58 ;
if ( V_43 -> V_45 != V_46 ) {
F_16 ( V_5 , L_5 ,
V_43 -> V_45 ) ;
F_5 ( V_5 , V_47 ) ;
}
V_23 = V_43 -> V_48 . V_49 ;
if ( F_17 ( F_18 ( V_23 ) ) != V_50 ) {
F_16 ( V_5 , L_6 ,
F_19 ( V_23 ) , F_20 ( V_23 ) ) ;
}
if ( ! F_22 ( V_43 -> V_59 ) ) {
F_5 ( V_5 , V_47 ) ;
return;
}
memset ( V_23 , 0 , V_60 ) ;
F_8 ( V_23 , V_61 , V_62 , V_63 ) ;
V_51 = ( T_1 * ) F_23 ( V_23 ) ;
V_57 = (struct V_56 * ) V_51 ;
memcpy ( & V_57 -> V_64 , F_7 ( V_5 ) , 8 ) ;
V_51 += sizeof( * V_57 ) ;
V_55 = (struct V_54 * ) V_51 ;
V_55 -> V_53 = 0 ;
V_37 += sizeof( V_55 -> V_53 ) ;
V_51 += sizeof( V_55 -> V_53 ) ;
V_58 = & V_19 [ 0 ] ;
memset ( V_58 , 0 , V_65 ) ;
V_58 [ 2 ] = 1 ;
V_58 [ 7 ] = 1 ;
F_13 ( & V_51 , V_66 ,
V_58 , V_65 ) ;
V_53 ++ ;
V_35 = F_24 ( V_67 | V_68 ) ;
F_13 ( & V_51 , V_69 ,
& V_35 ,
V_70 ) ;
V_53 ++ ;
if ( V_3 -> V_71 [ V_5 -> V_4 ] . V_72 == V_73 )
V_35 = F_24 ( V_67 ) ;
else if ( V_3 -> V_71 [ V_5 -> V_4 ] . V_72 == V_74 )
V_35 = F_24 ( V_68 ) ;
else
V_35 = F_24 ( V_75 ) ;
F_13 ( & V_51 , V_76 ,
& V_35 , V_77 ) ;
V_53 ++ ;
V_52 = V_5 -> V_78 . V_79 . V_80 ;
F_13 ( & V_51 , V_81 ,
& V_52 , sizeof( V_52 ) ) ;
V_53 ++ ;
strcpy ( V_19 , L_7 ) ;
F_13 ( & V_51 , V_82 , V_19 ,
strlen ( V_19 ) ) ;
V_53 ++ ;
if ( ! F_10 ( V_19 , sizeof( V_19 ) ) ) {
F_13 ( & V_51 , V_83 ,
V_19 , strlen ( V_19 ) ) ;
V_53 ++ ;
}
V_55 -> V_53 = F_24 ( V_53 ) ;
V_37 = ( T_2 ) ( V_51 - ( T_1 * ) V_23 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_26 ( V_43 , F_15 ,
V_85 , & V_43 -> V_48 , V_37 ) ) {
F_5 ( V_5 , V_47 ) ;
F_16 ( V_5 , L_8 ) ;
}
F_27 ( & V_3 -> V_84 ) ;
}
static void
F_28 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
void * V_23 ;
T_1 * V_51 ;
T_2 V_37 = 0 ;
T_2 V_53 = 0 ;
T_5 V_86 = F_24 ( 65536 ) ;
struct V_87 * V_88 ;
struct V_1 * V_5 = V_43 -> V_44 ;
struct V_89 * V_90 ;
struct V_54 * V_55 ;
T_1 V_19 [ 64 ] ;
if ( V_43 -> V_45 != V_46 ) {
F_16 ( V_5 , L_9 ,
V_43 -> V_45 ) ;
F_5 ( V_5 , V_47 ) ;
}
if ( ! F_22 ( V_43 -> V_59 ) ) {
F_5 ( V_5 , V_47 ) ;
return;
}
V_23 = V_43 -> V_48 . V_49 ;
if ( F_17 ( F_18 ( V_23 ) ) != V_50 ) {
F_16 ( V_5 , L_10 ,
F_19 ( V_23 ) , F_20 ( V_23 ) ) ;
}
memset ( V_23 , 0 , V_60 ) ;
F_8 ( V_23 , V_61 , V_62 , V_91 ) ;
V_37 = V_60 ;
V_51 = ( T_1 * ) F_23 ( V_23 ) ;
V_88 = (struct V_87 * ) V_51 ;
memcpy ( & V_88 -> V_92 , F_7 ( V_5 ) , 8 ) ;
V_51 += sizeof( * V_88 ) ;
V_90 = (struct V_89 * ) V_51 ;
V_90 -> V_93 = F_24 ( 1 ) ;
memcpy ( & V_90 -> V_94 [ 0 ] . V_64 , F_7 ( V_5 ) , 8 ) ;
V_51 += sizeof( * V_90 ) ;
V_55 = (struct V_54 * ) V_51 ;
V_55 -> V_53 = 0 ;
V_37 += sizeof( V_55 -> V_53 ) ;
V_51 += sizeof( V_55 -> V_53 ) ;
F_13 ( & V_51 , V_95 , F_29 ( V_5 ) ,
V_96 ) ;
V_53 ++ ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
strcpy ( V_19 , L_11 ) ;
F_13 ( & V_51 , V_97 , V_19 ,
strlen ( V_19 ) ) ;
V_53 ++ ;
F_13 ( & V_51 , V_98 ,
V_3 -> V_99 . V_100 , sizeof( V_3 -> V_99 . V_100 ) ) ;
V_53 ++ ;
F_13 ( & V_51 , V_101 , V_3 -> V_99 . V_92 ,
sizeof( V_3 -> V_99 . V_92 ) ) ;
V_53 ++ ;
F_13 ( & V_51 , V_102 ,
V_3 -> V_103 , strlen ( V_3 -> V_103 ) ) ;
V_53 ++ ;
F_13 ( & V_51 , V_104 ,
V_3 -> V_105 , sizeof( V_3 -> V_105 ) ) ;
V_53 ++ ;
F_13 ( & V_51 , V_106 ,
V_3 -> V_107 , strlen ( V_3 -> V_107 ) ) ;
V_53 ++ ;
if ( ! F_12 ( V_19 , sizeof( V_19 ) ) ) {
F_13 ( & V_51 , V_108 ,
V_19 , strlen ( V_19 ) ) ;
V_53 ++ ;
}
F_13 ( & V_51 , V_109 ,
& V_86 , V_110 ) ;
V_37 = ( T_2 ) ( V_51 - ( T_1 * ) V_23 ) ;
V_53 ++ ;
V_55 -> V_53 = F_24 ( V_53 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_26 ( V_43 , F_21 ,
V_85 , & V_43 -> V_48 , V_37 ) ) {
F_5 ( V_5 , V_47 ) ;
F_16 ( V_5 , L_12 ) ;
}
F_27 ( & V_3 -> V_84 ) ;
}
static void
F_30 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
struct V_1 * V_5 = V_43 -> V_44 ;
void * V_23 ;
struct V_56 * V_57 ;
T_2 V_37 ;
if ( V_43 -> V_45 != V_46 ) {
F_16 ( V_5 , L_13 ,
V_43 -> V_45 ) ;
F_5 ( V_5 , V_47 ) ;
}
if ( ! F_22 ( V_43 -> V_59 ) ) {
F_5 ( V_5 , V_47 ) ;
return;
}
V_23 = V_43 -> V_48 . V_49 ;
if ( F_17 ( F_18 ( V_23 ) ) != V_50 ) {
F_16 ( V_5 , L_14 ,
F_19 ( V_23 ) , F_20 ( V_23 ) ) ;
}
memset ( V_23 , 0 , V_60 ) ;
F_8 ( V_23 , V_61 , V_62 , V_111 ) ;
V_37 = V_60 ;
V_57 = (struct V_56 * ) F_23 ( V_23 ) ;
memcpy ( & V_57 -> V_64 , F_7 ( V_5 ) , 8 ) ;
V_37 += sizeof( * V_57 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_26 ( V_43 , F_28 ,
V_85 , & V_43 -> V_48 , V_37 ) ) {
F_5 ( V_5 , V_47 ) ;
F_16 ( V_5 , L_15 ) ;
}
F_27 ( & V_3 -> V_84 ) ;
}
int
F_31 ( struct V_1 * V_5 , void * V_112 )
{
struct V_42 * V_43 ;
struct V_113 * V_114 = (struct V_113 * ) V_112 ;
void * V_23 ;
struct V_87 * V_88 ;
T_2 V_37 ;
if ( ! ( V_5 -> V_115 & V_116 ) )
return - V_117 ;
if ( ! F_22 ( V_114 ) )
F_5 ( V_5 , V_47 ) ;
V_43 = V_5 -> V_118 ;
V_43 -> V_44 = V_5 ;
V_43 -> V_59 = V_114 ;
V_23 = V_43 -> V_48 . V_49 ;
memset ( V_23 , 0 , V_60 ) ;
F_8 ( V_23 , V_61 , V_62 , V_119 ) ;
V_37 = V_60 ;
V_88 = (struct V_87 * ) F_23 ( V_23 ) ;
memcpy ( & V_88 -> V_92 , F_7 ( V_5 ) , 8 ) ;
V_37 += sizeof( * V_88 ) ;
if ( F_26 ( V_43 , F_30 ,
V_85 , & V_43 -> V_48 , V_37 ) ) {
F_5 ( V_5 , V_47 ) ;
F_16 ( V_5 , L_16 ) ;
}
return 0 ;
}
static void
F_32 ( struct V_2 * V_3 , struct V_120 * V_121 )
{
struct V_1 * V_5 = ( (struct V_1 * ) V_121 -> V_122 ) ;
struct V_123 * V_124 = (struct V_123 * ) ( V_121 -> V_125 ) ;
struct V_126 * V_79 ;
struct V_127 * V_128 ;
enum V_129 V_130 ;
T_5 V_131 ;
V_130 = F_33 ( F_34 ( V_124 -> V_132 ) ) ;
if ( V_130 != V_46 ) {
F_35 ( V_3 , L_17 , V_130 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return;
}
F_25 ( & V_3 -> V_84 ) ;
memcpy ( V_5 -> V_134 , V_124 -> V_135 , sizeof( V_5 -> V_134 ) ) ;
memcpy ( & V_131 , & V_124 -> V_135 [ 3 ] , sizeof( T_1 ) * 3 ) ;
V_5 -> V_131 = F_34 ( V_131 ) ;
V_5 -> V_131 = V_5 -> V_131 >> 8 ;
memcpy ( F_29 ( V_5 ) , V_124 -> V_136 , 8 ) ;
memcpy ( F_7 ( V_5 ) , V_124 -> V_137 , 8 ) ;
V_79 = (struct V_126 * ) V_124 -> V_138 ;
V_5 -> V_78 . V_79 . V_139 = V_79 -> V_139 ;
V_5 -> V_78 . V_79 . V_140 = V_79 -> V_140 ;
V_5 -> V_78 . V_79 . V_141 = V_79 -> V_141 ;
V_5 -> V_78 . V_79 . V_142 = V_79 -> V_142 ;
V_5 -> V_78 . V_79 . V_80 = V_79 -> V_80 ;
V_5 -> V_78 . V_79 . V_143 = V_79 -> V_143 ;
V_5 -> V_78 . V_79 . V_144 = V_79 -> V_144 ;
V_128 = (struct V_127 * ) V_124 -> V_145 ;
V_5 -> V_78 . V_128 [ 2 ] . V_146 = V_128 -> V_146 ;
V_5 -> V_78 . V_128 [ 2 ] . V_147 = V_128 -> V_147 ;
V_5 -> V_78 . V_128 [ 2 ] . V_148 = V_128 -> V_148 ;
V_5 -> V_78 . V_128 [ 2 ] . V_149 = V_128 -> V_149 ;
F_27 ( & V_3 -> V_84 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
F_37 ( V_5 , V_150 ) ;
}
static int
F_38 ( struct V_1 * V_5 ,
void (* F_39) ( struct V_2 * , struct V_120 * ) )
{
struct V_2 * V_3 = V_5 -> V_151 ;
struct V_120 * V_121 ;
V_121 = F_40 ( V_3 -> V_133 , V_152 ) ;
if ( ! V_121 ) {
F_5 ( V_3 , V_153 ) ;
return - V_154 ;
}
F_41 ( V_5 , V_121 ,
V_155 ,
V_5 -> V_156 ,
V_5 -> V_16 ,
F_39 ) ;
if ( F_42 ( V_3 , V_121 ) ) {
F_35 ( V_3 , L_18 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return - V_157 ;
}
return 0 ;
}
static int
F_43 ( struct V_1 * V_5 , bool V_158 )
{
struct V_2 * V_3 = V_5 -> V_151 ;
struct V_120 * V_121 ;
enum V_129 V_130 ;
T_1 V_4 ;
T_1 V_159 ;
struct V_160 * V_161 ;
int V_162 ;
V_121 = F_40 ( V_3 -> V_133 , V_152 ) ;
if ( ! V_121 ) {
F_5 ( V_3 , V_153 ) ;
return - V_154 ;
}
V_4 = V_5 -> V_4 ;
V_159 = V_158 ? V_163 : V_164 ;
F_44 ( V_3 , L_19 ,
V_159 ? L_20 : L_21 , V_4 ) ;
F_45 ( V_5 , V_121 , V_155 ,
V_4 , V_159 , 0 , 0 , 0 , NULL ) ;
if ( F_42 ( V_3 , V_121 ) ) {
F_35 ( V_3 , L_22 ,
V_4 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return - V_157 ;
}
V_130 = F_46 ( V_121 ) ;
if ( V_130 != V_46 ) {
F_35 ( V_3 ,
L_23
L_24 , V_159 ? L_20 : L_21 , V_4 , V_130 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return - V_157 ;
}
if ( ! V_158 )
goto V_165;
V_161 = (struct V_160 * ) V_121 -> V_125 ;
memcpy ( F_29 ( V_5 ) , V_161 -> V_136 , 8 ) ;
memcpy ( F_7 ( V_5 ) , V_161 -> V_137 , 8 ) ;
for ( V_162 = 0 ; V_162 < V_166 ; V_162 ++ )
if ( V_3 -> V_71 [ V_162 ] . V_4 == V_4 )
memcpy ( V_3 -> V_71 [ V_162 ] . V_134 , V_161 -> V_167 , 6 ) ;
V_165:
F_36 ( V_121 , V_3 -> V_133 ) ;
return 0 ;
}
static void
F_47 ( struct V_2 * V_3 , struct V_120 * V_121 )
{
struct V_1 * V_5 = (struct V_1 * ) V_121 -> V_122 ;
struct V_168 * V_169 ;
struct V_170 * V_124 =
(struct V_170 * ) ( V_121 -> V_125 ) ;
enum V_129 V_130 ;
V_130 = F_33 ( F_34 ( V_124 -> V_171 ) ) ;
if ( V_130 != V_46 ) {
F_48 ( V_5 , L_25 ,
V_130 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return;
}
F_25 ( & V_3 -> V_84 ) ;
V_169 = V_5 -> V_172 ;
V_169 -> V_173 = F_49 (
F_17 ( V_124 -> V_174 ) ) ;
V_169 -> V_175 = F_17 ( V_124 -> V_175 ) ;
V_169 -> V_176 = V_124 -> V_176 ;
V_169 -> V_177 = F_17 ( V_124 -> V_177 ) ;
V_169 -> V_178 = F_50 ( V_124 -> V_178 ) ;
V_169 -> V_179 = F_51 ( F_34 ( V_124 -> V_180 ) ) ;
V_169 -> V_181 = F_52 ( V_124 -> V_182 ) ;
V_169 -> V_183 = F_53 ( V_124 -> V_182 ) ;
V_169 -> V_184 = F_54 ( V_124 -> V_182 ) ;
V_169 -> V_4 = F_55 ( V_124 -> V_182 ) ;
memcpy ( V_169 -> V_185 , V_124 -> V_185 , sizeof( V_169 -> V_185 ) ) ;
memcpy ( V_169 -> V_134 , V_124 -> V_134 , sizeof( V_169 -> V_134 ) ) ;
memcpy ( V_169 -> V_186 , V_124 -> V_186 , sizeof( V_169 -> V_186 ) ) ;
memcpy ( V_169 -> V_187 , V_124 -> V_187 , sizeof( V_169 -> V_187 ) ) ;
memcpy ( V_169 -> V_188 , V_124 -> V_188 , sizeof( V_169 -> V_188 ) ) ;
F_27 ( & V_3 -> V_84 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
}
static int
F_56 ( struct V_1 * V_5 ,
void (* F_39) ( struct V_2 * , struct V_120 * ) )
{
struct V_2 * V_3 = V_5 -> V_151 ;
struct V_120 * V_121 ;
V_121 = F_40 ( V_3 -> V_133 , V_152 ) ;
if ( ! V_121 ) {
F_5 ( V_3 , V_153 ) ;
return - V_154 ;
}
F_57 ( V_5 , V_121 , V_155 ,
V_5 -> V_4 , V_5 -> V_156 , F_39 ) ;
if ( F_42 ( V_3 , V_121 ) ) {
F_35 ( V_3 , L_26 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return - V_157 ;
}
return 0 ;
}
static void
F_58 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_179 ,
T_2 V_189 )
{
struct V_1 * V_5 = NULL ;
V_5 = F_3 ( V_3 , V_189 ) ;
if ( ! V_5 ) {
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_35 ( V_3 , L_27 ,
V_4 ) ;
F_59 ( 0 ) ;
return;
}
if ( V_5 -> V_16 != V_190 ) {
F_27 ( & V_3 -> V_84 ) ;
F_60 ( V_3 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( ! V_5 ) {
F_35 ( V_3 ,
L_28
L_29 ,
V_4 , V_189 ) ;
F_59 ( 0 ) ;
return;
}
V_5 -> V_4 = V_4 ;
}
V_5 -> V_16 = V_189 ;
V_5 -> V_191 &= ~ 0xFFFF ;
V_5 -> V_191 |= V_189 ;
}
V_5 -> V_156 = V_179 ;
F_61 ( V_3 , L_30 , V_4 ) ;
F_5 ( V_5 , V_192 ) ;
F_62 ( & V_5 -> V_193 , V_194 ) ;
}
static void
F_63 ( struct V_1 * V_5 , enum V_195 V_196 )
{
struct V_113 * V_197 = (struct V_113 * ) & V_5 -> V_197 ;
struct V_7 * V_8 , * V_198 ;
struct V_113 * V_199 ;
F_64 (tmp, next, &rnhead->sm.sm_list) {
V_199 = (struct V_113 * ) V_8 ;
F_62 ( & V_199 -> V_193 , V_196 ) ;
}
}
static void
F_65 ( struct V_1 * V_5 )
{
struct V_113 * V_197 = (struct V_113 * ) & V_5 -> V_197 ;
struct V_7 * V_8 , * V_200 ;
struct V_113 * V_199 ;
F_64 (tmp, next_rn, &rnhead->sm.sm_list) {
V_199 = (struct V_113 * ) V_8 ;
F_66 ( V_5 , V_199 ) ;
}
}
static void
F_67 ( struct V_1 * V_5 , enum V_201 V_196 )
{
struct V_7 * V_8 ;
struct V_1 * V_13 , * V_12 ;
if ( F_68 ( V_5 ) ) {
F_62 ( & V_5 -> V_193 , V_196 ) ;
return;
}
V_12 = V_5 ;
F_2 (tmp, &sln->cln_head) {
V_13 = (struct V_1 * ) V_8 ;
F_62 ( & V_13 -> V_193 , V_196 ) ;
}
F_62 ( & V_5 -> V_193 , V_196 ) ;
}
static void
F_69 ( struct V_1 * V_5 )
{
F_67 ( V_5 , V_202 ) ;
}
static void
F_70 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_179 ,
T_2 V_189 )
{
struct V_168 * V_203 ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_189 ) ;
if ( V_5 ) {
V_203 = V_5 -> V_172 ;
F_5 ( V_5 , V_204 ) ;
if ( ! F_71 ( V_5 ) ) {
F_72 ( V_5 ,
L_31
L_32 ,
V_4 ) ;
F_5 ( V_5 , V_205 ) ;
return;
}
if ( V_203 -> V_4 != V_4 ) {
F_72 ( V_5 ,
L_33
L_34 , V_4 ) ;
F_5 ( V_5 , V_205 ) ;
return;
}
if ( V_5 -> V_156 != V_179 ) {
F_72 ( V_5 ,
L_33
L_35 , V_179 ) ;
F_5 ( V_5 , V_205 ) ;
return;
}
F_61 ( V_3 , L_36 , V_4 ) ;
F_69 ( V_5 ) ;
return;
} else {
F_73 ( V_3 ,
L_37 ,
V_189 ) ;
F_5 ( V_3 , V_205 ) ;
}
}
int
F_71 ( struct V_1 * V_5 )
{
return ( F_74 ( V_5 ) == ( ( V_206 ) V_207 ) ) ;
}
static void
F_75 ( struct V_1 * V_5 , enum V_201 V_196 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
struct V_1 * V_6 = V_3 -> V_6 ;
int V_208 ;
F_5 ( V_5 , V_209 [ V_196 ] ) ;
switch ( V_196 ) {
case V_194 :
F_77 ( & V_5 -> V_193 , V_210 ) ;
if ( F_78 ( V_5 ) ) {
V_208 = F_56 ( V_5 ,
F_47 ) ;
if ( V_208 != 0 ) {
F_5 ( V_5 , V_211 ) ;
break;
}
F_79 ( & V_5 -> V_172 -> V_212 , & V_6 -> V_213 ) ;
}
V_208 = F_38 ( V_5 , F_32 ) ;
if ( V_208 != 0 ) {
F_5 ( V_5 , V_211 ) ;
}
break;
case V_214 :
break;
default:
F_16 ( V_5 ,
L_38
L_39 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_215 ) ;
break;
}
}
static void
V_210 ( struct V_1 * V_5 , enum V_201 V_196 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
F_5 ( V_5 , V_209 [ V_196 ] ) ;
switch ( V_196 ) {
case V_194 :
F_72 ( V_5 ,
L_40
L_41 , V_5 -> V_4 ) ;
F_5 ( V_5 , V_205 ) ;
break;
case V_216 :
F_77 ( & V_5 -> V_193 , V_207 ) ;
F_27 ( & V_3 -> V_84 ) ;
F_37 ( V_5 , V_217 ) ;
F_25 ( & V_3 -> V_84 ) ;
break;
case V_202 :
case V_214 :
F_77 ( & V_5 -> V_193 , F_75 ) ;
if ( F_78 ( V_5 ) ) {
F_80 ( & V_5 -> V_172 -> V_212 ) ;
}
break;
default:
F_16 ( V_5 ,
L_38
L_39 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_215 ) ;
break;
}
}
static void
V_207 ( struct V_1 * V_5 , enum V_201 V_196 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
F_5 ( V_5 , V_209 [ V_196 ] ) ;
switch ( V_196 ) {
case V_216 :
F_16 ( V_5 ,
L_42
L_43 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_205 ) ;
break;
case V_202 :
F_77 ( & V_5 -> V_193 , V_218 ) ;
F_63 ( V_5 , V_219 ) ;
F_27 ( & V_3 -> V_84 ) ;
F_37 ( V_5 , V_220 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_78 ( V_5 ) ) {
F_80 ( & V_5 -> V_172 -> V_212 ) ;
}
break;
case V_214 :
F_77 ( & V_5 -> V_193 , V_218 ) ;
F_63 ( V_5 , V_219 ) ;
F_27 ( & V_3 -> V_84 ) ;
F_37 ( V_5 , V_220 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_78 ( V_5 ) ) {
F_80 ( & V_5 -> V_172 -> V_212 ) ;
}
break;
case V_221 :
F_77 ( & V_5 -> V_193 , F_75 ) ;
F_63 ( V_5 , V_222 ) ;
break;
case V_223 :
F_77 ( & V_5 -> V_193 , V_218 ) ;
F_63 ( V_5 , V_219 ) ;
break;
default:
F_16 ( V_5 ,
L_38
L_39 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_215 ) ;
F_59 ( 0 ) ;
break;
}
}
static void
V_218 ( struct V_1 * V_5 , enum V_201 V_196 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
struct V_1 * V_6 = V_3 -> V_6 ;
int V_208 ;
F_5 ( V_5 , V_209 [ V_196 ] ) ;
switch ( V_196 ) {
case V_194 :
F_77 ( & V_5 -> V_193 , V_210 ) ;
if ( F_78 ( V_5 ) ) {
V_208 = F_56 ( V_5 ,
F_47 ) ;
if ( V_208 != 0 ) {
F_5 ( V_5 , V_211 ) ;
break;
}
F_79 ( & V_5 -> V_172 -> V_212 , & V_6 -> V_213 ) ;
}
V_208 = F_38 ( V_5 , F_32 ) ;
if ( V_208 != 0 ) {
F_5 ( V_5 , V_211 ) ;
}
break;
case V_202 :
case V_214 :
case V_223 :
F_16 ( V_5 ,
L_42
L_44 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_205 ) ;
break;
case V_221 :
F_77 ( & V_5 -> V_193 , F_75 ) ;
F_63 ( V_5 , V_222 ) ;
break;
default:
F_16 ( V_5 ,
L_38
L_45 , V_196 , V_5 -> V_131 ) ;
F_5 ( V_5 , V_215 ) ;
F_59 ( 0 ) ;
break;
}
}
static void
F_81 ( struct V_224 * V_224 )
{
struct V_168 * V_172 = F_82 ( V_224 ,
struct V_168 , V_224 ) ;
F_83 ( V_172 ) ;
}
void
F_84 ( struct V_1 * V_5 , T_7 * V_225 )
{
if ( F_74 ( V_5 ) == ( ( V_206 ) F_75 ) ) {
strcpy ( V_225 , L_46 ) ;
return;
}
if ( F_74 ( V_5 ) == ( ( V_206 ) V_207 ) ) {
strcpy ( V_225 , L_47 ) ;
return;
}
if ( F_74 ( V_5 ) == ( ( V_206 ) V_218 ) ) {
strcpy ( V_225 , L_48 ) ;
return;
}
strcpy ( V_225 , L_49 ) ;
}
int
F_85 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_226 * V_227 )
{
struct V_120 * V_121 ;
struct V_228 V_229 ;
enum V_129 V_130 ;
int V_230 ;
V_121 = F_40 ( V_3 -> V_133 , V_152 ) ;
if ( ! V_121 ) {
F_35 ( V_3 , L_50 ) ;
return - V_157 ;
}
V_229 . V_4 = V_4 ;
for ( V_230 = 1 ; V_230 <= 3 ; V_230 ++ ) {
V_229 . V_230 = ( V_230 - 1 ) * 6 + 1 ;
V_229 . V_231 = 6 ;
if ( V_230 == 3 )
V_229 . V_231 = 4 ;
F_86 ( V_3 , V_121 , V_155 ,
& V_229 , NULL ) ;
if ( F_42 ( V_3 , V_121 ) ) {
F_35 ( V_3 , L_51 ) ;
F_36 ( V_121 , V_3 -> V_133 ) ;
return - V_157 ;
}
F_87 ( V_3 , V_121 , & V_130 ,
& V_229 , V_227 ) ;
}
F_36 ( V_121 , V_3 -> V_133 ) ;
return 0 ;
}
static void
F_88 ( struct V_2 * V_3 , void * V_232 , T_2 V_37 )
{
struct V_233 * V_234 = F_89 ( V_3 ) ;
struct V_42 * V_235 = NULL ;
struct V_236 * V_237 ;
V_237 = (struct V_236 * ) V_232 ;
if ( V_37 < sizeof( struct V_236 ) ) {
F_35 ( V_234 -> V_3 ,
L_52 , V_37 ) ;
V_234 -> V_238 . V_211 ++ ;
return;
}
V_235 = (struct V_42 * ) ( ( V_239 ) V_237 -> V_240 ) ;
V_235 -> V_45 = F_90 ( V_237 ) ;
F_25 ( & V_3 -> V_84 ) ;
if ( F_91 ( V_234 , V_235 ) != 0 ) {
F_35 ( V_234 -> V_3 ,
L_53 ,
V_235 ) ;
V_234 -> V_238 . V_211 ++ ;
F_27 ( & V_3 -> V_84 ) ;
return;
}
V_234 = F_89 ( V_3 ) ;
F_80 ( & V_235 -> V_193 . V_241 ) ;
V_234 -> V_238 . V_242 -- ;
F_27 ( & V_3 -> V_84 ) ;
if ( V_235 -> V_243 )
V_235 -> V_243 ( V_3 , V_235 ) ;
}
void
F_92 ( struct V_2 * V_3 , T_8 V_244 , T_9 * V_23 )
{
struct V_1 * V_5 ;
struct V_113 * V_199 ;
T_1 V_4 , V_245 = * ( T_1 * ) V_23 ;
struct V_160 * V_161 ;
struct V_246 * V_232 ;
struct V_247 * V_248 ;
enum V_249 V_250 ;
T_2 V_179 , V_251 , V_189 ;
enum V_201 V_196 ;
if ( V_244 == V_252 && V_245 == V_253 ) {
V_161 = (struct V_160 * ) V_23 ;
V_250 = V_161 -> V_250 ;
V_4 = F_93 (
F_34 ( V_161 -> V_254 ) ) ;
V_179 = F_94 ( F_34 ( V_161 -> V_255 ) ) ;
V_189 = F_95 ( F_34 ( V_161 -> V_256 ) ) ;
if ( V_250 == V_257 ) {
F_25 ( & V_3 -> V_84 ) ;
F_58 ( V_3 , V_4 , V_179 , V_189 ) ;
F_27 ( & V_3 -> V_84 ) ;
} else if ( V_250 == V_258 ) {
F_25 ( & V_3 -> V_84 ) ;
F_70 ( V_3 , V_4 , V_179 , V_189 ) ;
F_27 ( & V_3 -> V_84 ) ;
} else {
F_73 ( V_3 , L_54 ,
V_161 -> V_250 ) ;
F_5 ( V_3 , V_259 ) ;
}
} else if ( V_244 == V_260 ) {
V_232 = (struct V_246 * ) ( V_23 + 4 ) ;
if ( F_96 ( F_50 ( V_232 -> V_261 ) )
== V_262 ) {
V_248 = (struct V_247 * ) ( V_23 + 4 ) ;
V_251 = F_97 (
F_34 ( V_248 -> V_132 ) ) ;
V_189 = F_98 (
F_34 ( V_248 -> V_263 ) ) ;
F_44 ( V_3 ,
L_55
L_56 , V_251 ,
V_248 -> V_264 , V_189 ) ;
if ( V_248 -> V_265 != V_266 ) {
F_35 ( V_3 ,
L_57
L_58 ,
V_248 -> V_265 ,
V_251 ) ;
F_5 ( V_3 , V_205 ) ;
return;
}
F_25 ( & V_3 -> V_84 ) ;
V_5 = F_3 ( V_3 , V_189 ) ;
if ( ! V_5 ) {
F_35 ( V_3 ,
L_59
L_60 , V_189 , V_251 ) ;
F_5 ( V_3 , V_205 ) ;
goto V_267;
}
V_199 = F_99 ( V_5 , V_251 ,
& V_248 -> V_268 . V_269 ) ;
if ( ! V_199 ) {
F_16 ( V_5 ,
L_61
L_62 , V_251 ) ;
F_5 ( V_3 , V_205 ) ;
goto V_267;
}
V_5 -> V_270 = V_5 -> V_271 ;
V_5 -> V_271 = V_248 -> V_264 ;
F_5 ( V_5 , V_272 [ V_248 -> V_264 ] ) ;
V_196 = F_100 ( V_248 -> V_264 ) ;
if ( V_196 ) {
F_16 ( V_5 ,
L_63
L_64 , V_196 ,
V_248 -> V_264 , V_251 ) ;
F_62 ( & V_5 -> V_193 , V_196 ) ;
}
F_101 ( V_199 , V_248 -> V_264 ) ;
V_267:
F_27 ( & V_3 -> V_84 ) ;
return;
} else {
F_73 ( V_3 , L_65 ,
F_96 ( F_50 ( ( V_232 -> V_261 ) ) ) ) ;
F_5 ( V_3 , V_259 ) ;
}
} else if ( V_244 == V_252 ) {
V_232 = (struct V_246 * ) ( V_23 ) ;
if ( F_96 ( F_50 ( V_232 -> V_261 ) ) == V_273 ) {
F_88 ( V_3 , V_232 ,
sizeof( struct V_236 ) ) ;
} else {
F_73 ( V_3 , L_65 ,
F_96 ( F_50 ( ( V_232 -> V_261 ) ) ) ) ;
F_5 ( V_3 , V_259 ) ;
}
} else {
F_73 ( V_3 , L_66 , V_245 ) ;
F_5 ( V_3 , V_259 ) ;
}
}
int
F_102 ( struct V_1 * V_5 )
{
int V_208 = 0 ;
if ( F_78 ( V_5 ) && ! ( V_5 -> V_115 & V_274 ) ) {
V_208 = F_43 ( V_5 , 1 ) ;
V_5 -> V_115 |= V_274 ;
}
return V_208 ;
}
void
F_103 ( struct V_1 * V_5 )
{
F_67 ( V_5 , V_214 ) ;
if ( F_78 ( V_5 ) && ( V_5 -> V_115 & V_274 ) ) {
F_43 ( V_5 , 0 ) ;
V_5 -> V_115 &= ~ V_274 ;
}
F_16 ( V_5 , L_67 , V_5 ) ;
}
void
F_104 ( struct V_1 * V_5 )
{
F_67 ( V_5 , V_221 ) ;
if ( F_78 ( V_5 ) )
V_5 -> V_16 = V_190 ;
F_16 ( V_5 , L_68 , V_5 ) ;
}
static int
F_105 ( struct V_42 * V_235 , T_2 V_275 ,
T_2 V_276 , T_1 V_159 , T_2 V_277 ,
T_2 V_278 , T_2 V_279 , T_1 * V_280 )
{
struct V_236 * V_232 ;
T_5 V_281 ;
V_232 = (struct V_236 * ) V_280 ;
V_232 -> V_282 = F_106 ( F_107 ( V_273 ) |
F_108 ( V_276 ) ) ;
V_275 = F_109 ( V_275 , 16 ) ;
V_232 -> V_283 = F_106 ( F_110 ( V_279 ) |
F_111 ( V_275 ) ) ;
V_232 -> V_284 = V_159 ;
V_232 -> V_285 = 0 ;
V_232 -> V_286 = 0 ;
V_232 -> V_240 = V_235 -> V_287 ;
V_232 -> V_288 = F_112 ( F_113 (
V_235 -> V_44 -> V_151 , V_235 -> V_289 ) ) ;
V_232 -> V_290 = F_114 ( 1 ) ;
V_232 -> V_291 = ( T_1 ) V_235 -> V_292 ;
V_281 = F_24 ( V_277 ) ;
memcpy ( V_232 -> V_293 , F_115 ( V_281 ) , 3 ) ;
V_281 = F_24 ( V_278 ) ;
memcpy ( V_232 -> V_294 , F_115 ( V_281 ) , 3 ) ;
V_232 -> V_295 = F_106 ( V_235 -> V_48 . V_37 ) ;
V_232 -> V_296 = F_116 ( V_235 -> V_48 . V_297 ) ;
return 0 ;
}
static int
F_117 ( struct V_233 * V_234 , struct V_42 * V_235 ,
T_1 V_159 , struct V_298 * V_51 ,
T_2 V_299 )
{
struct V_300 V_301 ;
struct V_1 * V_5 = V_235 -> V_44 ;
struct V_113 * V_199 = V_235 -> V_59 ;
struct V_2 * V_3 = V_234 -> V_3 ;
T_1 V_280 [ 64 ] ;
struct V_302 V_303 ;
T_2 V_304 = 0 ;
T_1 V_305 = 0 ;
T_2 V_306 = 0 ;
int V_307 = 0 ;
V_304 = sizeof( struct V_236 ) ;
if ( V_299 < 256 ) {
V_304 += F_118 ( V_299 , 8 ) ;
V_305 = ( T_1 ) V_299 ;
} else
V_304 += sizeof( struct V_302 ) ;
V_304 = F_118 ( V_304 , 16 ) ;
V_307 = F_119 ( V_3 , V_234 -> V_308 , V_304 , & V_301 ) ;
if ( V_307 != 0 ) {
F_35 ( V_3 , L_69 ,
V_235 , V_307 ) ;
return V_307 ;
}
F_105 ( V_235 , V_304 , V_305 , V_159 ,
V_5 -> V_131 , V_199 -> V_131 ,
F_120 ( V_199 ) ,
& V_280 [ 0 ] ) ;
F_121 ( & V_280 [ 0 ] , & V_301 , V_306 ,
sizeof( struct V_236 ) ) ;
V_306 += sizeof( struct V_236 ) ;
if ( V_305 )
F_121 ( V_51 -> V_49 , & V_301 , V_306 , V_305 ) ;
else {
V_303 . V_309 = F_24 ( F_122 ( V_310 ) |
V_311 | F_123 ( 1 ) ) ;
V_303 . V_312 = F_106 ( V_299 ) ;
V_303 . V_313 = F_116 ( V_51 -> V_297 ) ;
F_121 ( & V_303 , & V_301 , F_118 ( V_306 , 8 ) ,
sizeof( struct V_302 ) ) ;
}
F_124 ( V_234 -> V_3 , V_234 -> V_308 , false ) ;
return V_307 ;
}
static int
F_26 ( struct V_42 * V_235 ,
void (* V_243) ( struct V_2 * , struct V_42 * ) ,
enum V_314 V_315 , struct V_298 * V_51 ,
T_2 V_299 )
{
struct V_2 * V_3 = F_76 ( V_235 -> V_44 ) ;
struct V_233 * V_234 = F_89 ( V_3 ) ;
int V_208 ;
F_125 ( V_299 > V_51 -> V_37 ) ;
V_235 -> V_243 = V_243 ;
V_235 -> V_287 = ( V_239 ) ( V_235 ) ;
V_235 -> V_308 = V_234 -> V_308 ;
V_235 -> V_289 = V_234 -> V_289 ;
V_208 = F_117 ( V_234 , V_235 , V_315 , V_51 , V_299 ) ;
if ( V_208 == 0 ) {
F_79 ( & V_235 -> V_193 . V_241 , & V_234 -> V_316 ) ;
V_234 -> V_238 . V_242 ++ ;
}
return V_208 ;
}
static int
F_126 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
struct V_298 * V_48 ;
V_5 -> V_118 = F_127 ( sizeof( struct V_42 ) , V_317 ) ;
if ( ! V_5 -> V_118 ) {
F_48 ( V_5 , L_70 ) ;
F_5 ( V_3 , V_153 ) ;
return - V_154 ;
}
V_48 = & V_5 -> V_118 -> V_48 ;
V_48 -> V_37 = 2048 ;
V_48 -> V_49 = F_128 ( V_3 -> V_318 , V_48 -> V_37 ,
& V_48 -> V_297 ) ;
if ( ! V_48 -> V_49 ) {
F_35 ( V_3 , L_71 ) ;
F_83 ( V_5 -> V_118 ) ;
V_5 -> V_118 = NULL ;
return - V_154 ;
}
V_5 -> V_115 |= V_116 ;
return 0 ;
}
static int
F_129 ( struct V_1 * V_5 )
{
struct V_298 * V_48 ;
struct V_2 * V_3 = F_76 ( V_5 ) ;
if ( ! V_5 -> V_118 )
return 0 ;
V_48 = & V_5 -> V_118 -> V_48 ;
if ( V_48 -> V_49 )
F_130 ( V_3 -> V_318 , V_48 -> V_37 , V_48 -> V_49 ,
V_48 -> V_297 ) ;
F_83 ( V_5 -> V_118 ) ;
return 0 ;
}
int
F_131 ( struct V_1 * V_5 , unsigned long V_319 ,
unsigned long time , unsigned long V_320 ,
unsigned long V_321 )
{
int V_208 = 0 ;
if ( time >= V_320 )
return 1 ;
if ( ! V_5 -> V_322 )
V_5 -> V_322 = V_319 ;
if ( ( ( V_319 - V_5 -> V_322 ) >= V_321 ) ) {
if ( ! V_5 -> V_323 )
V_5 -> V_323 = V_5 -> V_324 ;
else {
if ( V_5 -> V_323 == V_5 -> V_324 )
return 1 ;
V_5 -> V_323 = V_5 -> V_324 ;
}
V_5 -> V_322 = V_319 ;
}
return V_208 ;
}
void
F_132 ( struct V_2 * V_3 , enum V_325 V_326 )
{
struct V_7 * V_8 ;
struct V_1 * V_5 ;
F_44 ( V_3 , L_72 , V_326 ) ;
F_2 (tmp, &hw->sln_head) {
V_5 = (struct V_1 * ) V_8 ;
switch ( V_326 ) {
case V_327 :
F_102 ( V_5 ) ;
break;
case V_328 :
case V_329 :
F_104 ( V_5 ) ;
break;
case V_330 :
F_103 ( V_5 ) ;
break;
default:
break;
}
}
}
void
F_133 ( struct V_2 * V_3 , T_1 V_4 , bool V_331 )
{
struct V_7 * V_8 ;
struct V_1 * V_5 ;
F_44 ( V_3 , L_73 , V_4 ) ;
F_2 (tmp, &hw->sln_head) {
V_5 = (struct V_1 * ) V_8 ;
if ( V_5 -> V_4 != V_4 )
continue;
if ( V_331 )
F_103 ( V_5 ) ;
else
F_102 ( V_5 ) ;
}
}
static int
F_134 ( struct V_1 * V_5 )
{
int V_208 = - V_157 ;
struct V_1 * V_6 , * V_332 ;
struct V_2 * V_3 = F_76 ( V_5 ) ;
F_135 ( & V_5 -> V_193 , F_75 ) ;
V_5 -> V_16 = V_190 ;
V_5 -> V_156 = V_190 ;
if ( F_136 ( V_5 ) ) {
V_5 -> V_172 = F_127 ( sizeof( struct V_168 ) , V_317 ) ;
if ( ! V_5 -> V_172 ) {
F_48 ( V_5 , L_74 ) ;
F_5 ( V_3 , V_153 ) ;
goto V_333;
}
F_137 ( & V_5 -> V_213 ) ;
F_138 ( & V_5 -> V_172 -> V_224 ) ;
if ( V_334 && F_126 ( V_5 ) )
goto V_333;
} else {
V_6 = F_139 ( V_5 ) ;
if ( F_68 ( V_5 ) ) {
V_332 = F_140 ( V_5 ) ;
F_141 ( & V_332 -> V_172 -> V_224 ) ;
V_5 -> V_172 = V_332 -> V_172 ;
} else {
V_5 -> V_172 = F_127 ( sizeof( struct V_168 ) ,
V_317 ) ;
if ( ! V_5 -> V_172 ) {
F_48 ( V_5 , L_75 ) ;
F_5 ( V_3 , V_153 ) ;
goto V_333;
}
F_138 ( & V_5 -> V_172 -> V_224 ) ;
if ( V_334 && F_126 ( V_5 ) )
goto V_333;
}
}
return 0 ;
V_333:
return V_208 ;
}
static void
F_142 ( struct V_1 * V_5 )
{
struct V_1 * V_332 ;
F_65 ( V_5 ) ;
if ( F_68 ( V_5 ) ) {
V_332 = F_140 ( V_5 ) ;
F_143 ( & V_332 -> V_172 -> V_224 , F_81 ) ;
} else {
F_143 ( & V_5 -> V_172 -> V_224 , F_81 ) ;
if ( V_334 )
F_129 ( V_5 ) ;
}
V_5 -> V_172 = NULL ;
}
int
F_144 ( struct V_1 * V_5 , struct V_2 * V_3 ,
struct V_1 * V_332 )
{
int V_208 = - V_157 ;
F_76 ( V_5 ) = V_3 ;
if ( V_332 )
V_5 -> V_332 = V_332 ;
else
V_5 -> V_332 = NULL ;
V_5 -> V_324 = 0 ;
V_5 -> V_323 = 0 ;
V_5 -> V_322 = 0 ;
F_137 ( & V_5 -> V_197 ) ;
F_137 ( & V_5 -> V_17 ) ;
V_5 -> V_335 . V_336 = V_3 -> V_335 . V_336 ;
if ( F_134 ( V_5 ) )
goto V_333;
F_25 ( & V_3 -> V_84 ) ;
F_79 ( & V_5 -> V_193 . V_241 , V_332 ? & V_332 -> V_17 : & V_3 -> V_14 ) ;
if ( V_332 )
V_332 -> V_337 ++ ;
F_27 ( & V_3 -> V_84 ) ;
V_3 -> V_338 ++ ;
return 0 ;
V_333:
F_76 ( V_5 ) = NULL ;
return V_208 ;
}
void
F_145 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_76 ( V_5 ) ;
F_142 ( V_5 ) ;
F_25 ( & V_3 -> V_84 ) ;
F_80 ( & V_5 -> V_193 . V_241 ) ;
if ( V_5 -> V_332 )
V_5 -> V_332 -> V_337 -- ;
if ( F_4 ( & V_3 -> V_14 ) )
V_3 -> V_6 = NULL ;
else
V_3 -> V_6 = (struct V_1 * ) F_146 ( & V_3 -> V_14 ) ;
F_27 ( & V_3 -> V_84 ) ;
F_76 ( V_5 ) = NULL ;
V_3 -> V_338 -- ;
}
