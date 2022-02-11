static int
F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 ;
V_8 -> V_9 = F_2 ( sizeof( struct V_7 ) - 4 + 2 ) ;
V_8 -> V_10 = V_11 ;
V_8 -> V_12 = 0 ;
F_3 ( 0 , V_8 ) ;
F_4 ( & V_2 -> V_13 ) ;
V_6 = F_5 ( V_8 , V_2 , & V_5 -> V_14 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_13 ) ;
return V_6 ;
}
-- V_2 -> V_14 ;
V_6 = F_7 ( V_2 , V_8 , F_8 ( V_8 -> V_9 ) ) ;
if ( V_6 < 0 )
V_2 -> V_14 -- ;
F_6 ( & V_2 -> V_13 ) ;
F_9 ( V_15 , L_1 ,
F_10 ( V_8 ) , V_6 ) ;
return V_6 ;
}
static bool
F_11 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
return V_17 -> V_19 . V_20 == V_18 -> V_19 . V_20 ;
}
static unsigned int
F_12 ( char * V_3 )
{
T_1 * V_21 = ( T_1 * ) V_3 ;
return F_13 ( V_21 -> V_22 ) ;
}
static unsigned int
F_14 ( char * V_3 )
{
T_1 * V_21 = ( T_1 * ) V_3 ;
return ( F_13 ( V_21 -> V_23 ) << 16 ) +
F_13 ( V_21 -> V_24 ) ;
}
static struct V_4 *
F_15 ( struct V_1 * V_2 , char * V_25 )
{
struct V_7 * V_3 = (struct V_7 * ) V_25 ;
struct V_4 * V_5 ;
F_16 ( & V_26 ) ;
F_17 (mid, &server->pending_mid_q, qhead) {
if ( F_18 ( V_5 -> V_5 , V_3 ) &&
V_5 -> V_27 == V_28 &&
F_13 ( V_5 -> V_29 ) == V_3 -> V_10 ) {
F_19 ( & V_26 ) ;
return V_5 ;
}
}
F_19 ( & V_26 ) ;
return NULL ;
}
static void
F_20 ( struct V_1 * V_2 , const unsigned int V_30 ,
const int V_31 )
{
F_16 ( & V_2 -> V_32 ) ;
V_2 -> V_33 += V_30 ;
V_2 -> V_34 -- ;
F_19 ( & V_2 -> V_32 ) ;
F_21 ( & V_2 -> V_35 ) ;
}
static void
F_22 ( struct V_1 * V_2 , const int V_36 )
{
F_16 ( & V_2 -> V_32 ) ;
V_2 -> V_33 = V_36 ;
V_2 -> V_37 = V_36 > 1 ? V_38 : false ;
F_19 ( & V_2 -> V_32 ) ;
}
static int *
F_23 ( struct V_1 * V_2 , const int V_31 )
{
return & V_2 -> V_33 ;
}
static unsigned int
F_24 ( struct V_4 * V_5 )
{
return 1 ;
}
static T_2
F_25 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
T_3 V_39 , V_40 ;
bool V_41 ;
F_16 ( & V_26 ) ;
V_40 = ( T_3 ) ( ( V_2 -> V_42 ) & 0xffff ) ;
V_39 = V_40 ;
V_40 ++ ;
while ( V_40 != V_39 ) {
struct V_4 * V_43 ;
unsigned int V_44 ;
V_41 = false ;
if ( V_40 == 0 )
V_40 ++ ;
V_44 = 0 ;
F_17 (mid_entry, &server->pending_mid_q, qhead) {
++ V_44 ;
if ( V_43 -> V_5 == V_40 &&
V_43 -> V_27 == V_28 ) {
V_41 = true ;
break;
}
}
if ( V_44 > 32768 )
V_2 -> V_45 = V_46 ;
if ( ! V_41 ) {
V_5 = ( T_2 ) V_40 ;
V_2 -> V_42 = V_5 ;
break;
}
V_40 ++ ;
}
F_19 ( & V_26 ) ;
return V_5 ;
}
static int
F_26 ( char * V_3 )
{
struct V_7 * V_47 = (struct V_7 * ) V_3 ;
struct V_48 * V_49 ;
int V_50 ;
T_3 V_51 , V_52 ;
if ( V_47 -> V_10 != V_53 )
return 0 ;
if ( V_47 -> V_12 != 10 ) {
F_9 ( V_15 , L_2 ) ;
return - V_54 ;
}
V_49 = (struct V_48 * ) V_47 ;
V_51 = F_27 ( & V_49 -> V_55 . V_56 ) ;
V_52 = F_27 ( & V_49 -> V_55 . V_57 ) ;
if ( V_51 == V_52 )
return 0 ;
else if ( V_51 < V_52 ) {
F_9 ( V_15 , L_3 ,
V_51 , V_52 ) ;
return - V_54 ;
}
V_50 = V_51 - V_52 ;
F_9 ( V_15 , L_4 ,
V_50 ) ;
if ( V_51 > V_58 ) {
F_9 ( V_59 , L_5 ,
V_51 , V_58 ) ;
return - V_54 ;
}
return V_50 ;
}
static int
F_28 ( char * V_60 , struct V_7 * V_61 )
{
struct V_48 * V_62 = (struct V_48 * ) V_60 ;
struct V_48 * V_49 = (struct V_48 * ) V_61 ;
char * V_63 ;
char * V_64 ;
int V_50 ;
unsigned int V_65 , V_66 ;
T_3 V_67 , V_68 , V_69 ;
V_68 = F_27 ( & V_62 -> V_55 . V_56 ) ;
V_67 = F_27 ( & V_49 -> V_55 . V_56 ) ;
if ( V_67 != V_68 )
F_9 ( V_15 , L_6 ,
V_68 , V_67 ) ;
V_66 = F_27 ( & V_49 -> V_55 . V_57 ) ;
V_50 = V_67 - V_66 ;
if ( V_50 < 0 ) {
F_9 ( V_15 , L_7 ,
V_67 , V_66 ) ;
return - V_70 ;
}
if ( V_50 == 0 ) {
F_9 ( V_15 , L_8 ) ;
return 0 ;
}
V_69 = F_27 ( & V_62 -> V_55 . V_57 ) ;
if ( V_50 < V_69 )
F_9 ( V_15 , L_9 ) ;
V_63 = ( char * ) & V_49 -> V_71 . V_72 +
F_27 ( & V_49 -> V_55 . V_22 ) ;
V_64 = ( char * ) & V_62 -> V_71 . V_72 +
F_27 ( & V_62 -> V_55 . V_22 ) ;
V_63 += V_66 ;
V_66 += V_69 ;
if ( V_66 > V_73 ) {
F_9 ( V_15 , L_10 ,
V_66 ) ;
return - V_70 ;
}
F_29 ( V_66 , & V_49 -> V_55 . V_57 ) ;
V_65 = F_30 ( V_61 ) ;
V_65 += V_69 ;
if ( V_65 > V_73 ) {
F_9 ( V_15 , L_11 , V_65 ) ;
return - V_70 ;
}
F_3 ( V_65 , V_61 ) ;
V_65 = F_8 ( V_61 -> V_9 ) ;
V_65 += V_69 ;
if ( V_65 > V_58 + V_74 - 4 ) {
F_9 ( V_15 , L_12 ,
V_65 ) ;
return - V_75 ;
}
V_61 -> V_9 = F_2 ( V_65 ) ;
memcpy ( V_63 , V_64 , V_69 ) ;
if ( V_50 != V_69 ) {
F_9 ( V_15 , L_13 ) ;
return 1 ;
}
F_9 ( V_15 , L_14 ) ;
return 0 ;
}
static bool
F_31 ( struct V_4 * V_5 , struct V_1 * V_2 ,
char * V_3 , int V_76 )
{
if ( V_76 )
return false ;
if ( F_26 ( V_3 ) <= 0 )
return false ;
V_5 -> V_77 = true ;
if ( V_5 -> V_78 ) {
V_76 = F_28 ( V_3 , V_5 -> V_78 ) ;
if ( V_76 > 0 )
return true ;
V_5 -> V_79 = true ;
F_32 ( V_5 , V_76 ) ;
return true ;
}
if ( ! V_2 -> V_80 ) {
F_9 ( V_59 , L_15 ) ;
} else {
V_5 -> V_78 = V_3 ;
V_5 -> V_80 = true ;
V_2 -> V_81 = NULL ;
}
return true ;
}
static bool
F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_82 == 0 ;
}
static int
F_34 ( const unsigned int V_83 , struct V_84 * V_85 )
{
int V_6 ;
V_6 = F_35 ( V_83 , V_85 ) ;
if ( V_6 == - V_86 ) {
F_36 ( V_85 -> V_2 , 1 ) ;
V_6 = F_35 ( V_83 , V_85 ) ;
if ( V_6 == - V_86 )
V_6 = - V_87 ;
}
return V_6 ;
}
static unsigned int
F_37 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
T_2 V_92 = F_38 ( V_89 -> V_93 . V_94 ) ;
struct V_1 * V_2 = V_89 -> V_85 -> V_2 ;
unsigned int V_95 ;
if ( V_91 -> V_95 )
V_95 = V_91 -> V_95 ;
else if ( V_89 -> V_96 && ( V_92 & V_97 ) )
V_95 = V_98 ;
else
V_95 = V_99 ;
if ( ! V_89 -> V_96 || ! ( V_92 & V_97 ) )
V_95 = F_39 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_100 & V_101 ) ||
( ! ( V_2 -> V_100 & V_102 ) && V_2 -> V_103 ) )
V_95 = F_39 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_95 = F_39 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_95 ;
}
static unsigned int
F_40 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
T_2 V_92 = F_38 ( V_89 -> V_93 . V_94 ) ;
struct V_1 * V_2 = V_89 -> V_85 -> V_2 ;
unsigned int V_104 , V_105 ;
if ( V_89 -> V_96 && ( V_92 & V_106 ) )
V_105 = V_98 ;
else if ( V_2 -> V_100 & V_107 )
V_105 = V_108 ;
else
V_105 = V_2 -> V_82 - sizeof( T_1 ) ;
V_104 = V_91 -> V_104 ? V_91 -> V_104 : V_105 ;
if ( ! ( V_2 -> V_100 & V_107 ) )
V_104 = F_39 (unsigned int, CIFSMaxBufSize, rsize) ;
V_104 = F_39 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_104 ;
}
static void
F_41 ( const unsigned int V_83 , struct V_88 * V_89 )
{
F_42 ( V_83 , V_89 ) ;
F_43 ( V_83 , V_89 ) ;
}
static int
F_44 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_109 * V_110 , const char * V_111 )
{
int V_6 ;
T_4 * V_112 ;
V_112 = F_45 ( sizeof( T_4 ) , V_113 ) ;
if ( V_112 == NULL )
return - V_114 ;
V_6 = F_46 ( V_83 , V_89 , V_111 , V_112 ,
0 , V_110 -> V_115 ,
V_110 -> V_116 &
V_117 ) ;
if ( V_6 == - V_118 || V_6 == - V_54 )
V_6 = F_47 ( V_83 , V_89 , V_111 , V_112 ,
V_110 -> V_115 , V_110 -> V_116 &
V_117 ) ;
F_48 ( V_112 ) ;
return V_6 ;
}
static int
F_49 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_109 * V_110 , const char * V_111 ,
T_4 * V_119 , bool * V_120 , bool * V_121 )
{
int V_6 ;
* V_121 = false ;
V_6 = F_46 ( V_83 , V_89 , V_111 , V_119 , 0 ,
V_110 -> V_115 , V_110 -> V_116 &
V_117 ) ;
if ( ( V_6 == - V_118 ) || ( V_6 == - V_54 ) ) {
V_6 = F_47 ( V_83 , V_89 , V_111 , V_119 ,
V_110 -> V_115 ,
V_110 -> V_116 &
V_117 ) ;
* V_120 = true ;
}
if ( ! V_6 && ( F_50 ( V_119 -> V_122 ) & V_123 ) ) {
int V_124 ;
int V_125 = 0 ;
struct V_126 V_19 ;
struct V_127 V_128 ;
V_128 . V_89 = V_89 ;
V_128 . V_110 = V_110 ;
V_128 . V_129 = V_130 ;
V_128 . V_131 = 0 ;
V_128 . V_132 = V_133 ;
V_128 . V_134 = V_111 ;
V_128 . V_19 = & V_19 ;
V_128 . V_135 = false ;
V_124 = F_51 ( V_83 , & V_128 , & V_125 , NULL ) ;
if ( V_124 == - V_118 )
* V_121 = true ;
else
F_52 ( V_83 , V_89 , V_19 . V_20 ) ;
}
return V_6 ;
}
static int
F_53 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_109 * V_110 , const char * V_111 ,
T_5 * V_136 , T_4 * V_119 )
{
return F_54 ( V_83 , V_89 , V_111 , V_136 ,
V_110 -> V_115 ,
V_110 -> V_116 &
V_117 ) ;
}
static int
F_55 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_126 * V_19 , T_4 * V_119 )
{
return F_56 ( V_83 , V_89 , V_19 -> V_20 , V_119 ) ;
}
static void
F_57 ( struct V_88 * V_89 )
{
#ifdef F_58
F_59 ( & V_89 -> V_137 . V_138 . V_139 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_140 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_141 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_142 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_143 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_144 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_145 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_146 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_147 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_148 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_149 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_150 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_151 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_152 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_153 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_154 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_155 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_156 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_157 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_158 , 0 ) ;
F_59 ( & V_89 -> V_137 . V_138 . V_159 , 0 ) ;
#endif
}
static void
F_60 ( struct V_160 * V_161 , struct V_88 * V_89 )
{
#ifdef F_58
F_61 ( V_161 , L_16 ,
F_62 ( & V_89 -> V_137 . V_138 . V_142 ) ) ;
F_61 ( V_161 , L_17 ,
F_62 ( & V_89 -> V_137 . V_138 . V_140 ) ,
( long long ) ( V_89 -> V_162 ) ) ;
F_61 ( V_161 , L_18 ,
F_62 ( & V_89 -> V_137 . V_138 . V_139 ) ,
( long long ) ( V_89 -> V_163 ) ) ;
F_61 ( V_161 , L_19 ,
F_62 ( & V_89 -> V_137 . V_138 . V_141 ) ) ;
F_61 ( V_161 , L_20 ,
F_62 ( & V_89 -> V_137 . V_138 . V_157 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_155 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_156 ) ) ;
F_61 ( V_161 , L_21 ,
F_62 ( & V_89 -> V_137 . V_138 . V_143 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_146 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_147 ) ) ;
F_61 ( V_161 , L_22 ,
F_62 ( & V_89 -> V_137 . V_138 . V_144 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_145 ) ) ;
F_61 ( V_161 , L_23 ,
F_62 ( & V_89 -> V_137 . V_138 . V_148 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_149 ) ) ;
F_61 ( V_161 , L_24 ,
F_62 ( & V_89 -> V_137 . V_138 . V_150 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_151 ) ) ;
F_61 ( V_161 , L_25 ,
F_62 ( & V_89 -> V_137 . V_138 . V_152 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_153 ) ,
F_62 ( & V_89 -> V_137 . V_138 . V_154 ) ) ;
#endif
}
static void
F_63 ( struct V_164 * V_164 , const char * V_111 ,
struct V_109 * V_110 , struct V_88 * V_89 ,
const unsigned int V_83 )
{
T_6 V_165 ;
struct V_166 * V_167 ;
T_7 V_168 ;
int V_6 ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_167 = F_64 ( V_164 ) ;
V_168 = V_167 -> V_169 | V_170 ;
V_165 . V_122 = F_65 ( V_168 ) ;
V_6 = F_66 ( V_83 , V_89 , V_111 , & V_165 , V_110 -> V_115 ,
V_110 -> V_116 &
V_117 ) ;
if ( V_6 == 0 )
V_167 -> V_169 = V_168 ;
}
static int
F_67 ( const unsigned int V_83 , struct V_127 * V_128 ,
T_8 * V_125 , T_4 * V_3 )
{
if ( ! ( V_128 -> V_89 -> V_85 -> V_100 & V_171 ) )
return F_68 ( V_83 , V_128 -> V_89 , V_128 -> V_134 ,
V_128 -> V_132 ,
V_128 -> V_129 ,
V_128 -> V_131 ,
& V_128 -> V_19 -> V_20 , V_125 , V_3 ,
V_128 -> V_110 -> V_115 ,
V_128 -> V_110 -> V_116
& V_117 ) ;
return F_51 ( V_83 , V_128 , V_125 , V_3 ) ;
}
static void
F_69 ( struct V_16 * V_172 , struct V_126 * V_19 , T_8 V_125 )
{
struct V_166 * V_173 = F_64 ( V_172 -> V_174 -> V_175 ) ;
V_172 -> V_19 . V_20 = V_19 -> V_20 ;
F_70 ( V_173 , V_125 ) ;
V_173 -> V_176 = F_71 ( V_173 ) ;
}
static void
F_72 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_126 * V_19 )
{
F_52 ( V_83 , V_89 , V_19 -> V_20 ) ;
}
static int
F_73 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_126 * V_19 )
{
return F_74 ( V_83 , V_89 , V_19 -> V_20 ) ;
}
static int
F_75 ( const unsigned int V_83 , struct V_16 * V_172 ,
struct V_177 * V_178 , unsigned int * V_162 ,
char * * V_3 , int * V_179 )
{
V_178 -> V_20 = V_172 -> V_19 . V_20 ;
return F_76 ( V_83 , V_178 , V_162 , V_3 , V_179 ) ;
}
static int
F_77 ( const unsigned int V_83 , struct V_16 * V_172 ,
struct V_177 * V_178 , unsigned int * V_180 ,
struct V_181 * V_182 , unsigned long V_183 )
{
V_178 -> V_20 = V_172 -> V_19 . V_20 ;
return F_78 ( V_83 , V_178 , V_180 , V_182 , V_183 ) ;
}
static int
F_79 ( struct V_164 * V_164 , const char * V_111 ,
T_6 * V_3 , const unsigned int V_83 )
{
int V_125 = 0 ;
int V_6 ;
T_8 V_184 ;
struct V_126 V_19 ;
struct V_127 V_128 ;
struct V_16 * V_185 ;
struct V_166 * V_173 = F_64 ( V_164 ) ;
struct V_109 * V_110 = F_80 ( V_164 -> V_186 ) ;
struct V_187 * V_188 = NULL ;
struct V_88 * V_89 ;
V_185 = F_81 ( V_173 , true ) ;
if ( V_185 ) {
V_19 . V_20 = V_185 -> V_19 . V_20 ;
V_184 = V_185 -> V_189 ;
V_89 = F_82 ( V_185 -> V_188 ) ;
goto V_190;
}
V_188 = F_83 ( V_110 ) ;
if ( F_84 ( V_188 ) ) {
V_6 = F_85 ( V_188 ) ;
V_188 = NULL ;
goto V_191;
}
V_89 = F_82 ( V_188 ) ;
V_6 = F_66 ( V_83 , V_89 , V_111 , V_3 , V_110 -> V_115 ,
V_110 -> V_116 &
V_117 ) ;
if ( V_6 == 0 ) {
V_173 -> V_169 = F_50 ( V_3 -> V_122 ) ;
goto V_191;
} else if ( V_6 != - V_118 && V_6 != - V_54 ) {
goto V_191;
}
V_128 . V_89 = V_89 ;
V_128 . V_110 = V_110 ;
V_128 . V_129 = V_192 | V_193 ;
V_128 . V_131 = V_194 ;
V_128 . V_132 = V_133 ;
V_128 . V_134 = V_111 ;
V_128 . V_19 = & V_19 ;
V_128 . V_135 = false ;
F_9 ( V_15 , L_26 ) ;
V_6 = F_51 ( V_83 , & V_128 , & V_125 , NULL ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_195 )
V_6 = - V_54 ;
goto V_191;
}
V_184 = V_196 -> V_197 ;
V_190:
V_6 = F_86 ( V_83 , V_89 , V_3 , V_19 . V_20 , V_184 ) ;
if ( ! V_6 )
V_173 -> V_169 = F_50 ( V_3 -> V_122 ) ;
if ( V_185 == NULL )
F_52 ( V_83 , V_89 , V_19 . V_20 ) ;
else
F_87 ( V_185 ) ;
V_191:
if ( V_188 != NULL )
F_88 ( V_188 ) ;
return V_6 ;
}
static int
F_89 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_16 * V_172 )
{
return F_90 ( V_83 , V_89 , V_172 -> V_19 . V_20 ) ;
}
static int
F_91 ( const unsigned int V_83 , struct V_88 * V_89 ,
const char * V_134 , struct V_109 * V_110 ,
struct V_126 * V_19 , T_3 V_198 ,
struct V_199 * V_200 )
{
return F_92 ( V_83 , V_89 , V_134 , V_110 ,
& V_19 -> V_20 , V_198 , V_200 , true ) ;
}
static int
F_93 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_126 * V_19 , T_3 V_198 ,
struct V_199 * V_200 )
{
return F_94 ( V_83 , V_89 , V_19 -> V_20 , V_198 , V_200 ) ;
}
static int
F_95 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_126 * V_19 )
{
return F_96 ( V_83 , V_89 , V_19 -> V_20 ) ;
}
static int
F_97 ( struct V_88 * V_89 , struct V_126 * V_19 ,
struct V_166 * V_173 )
{
return F_98 ( 0 , V_89 , V_19 -> V_20 , V_196 -> V_197 , 0 , 0 , 0 , 0 ,
V_201 , false ,
F_99 ( V_173 ) ? 1 : 0 ) ;
}
static int
F_100 ( const unsigned int V_83 , struct V_88 * V_89 ,
struct V_202 * V_3 )
{
int V_6 = - V_118 ;
V_3 -> V_203 = V_204 ;
if ( ( V_89 -> V_85 -> V_100 & V_102 ) &&
( V_205 & F_38 ( V_89 -> V_93 . V_94 ) ) )
V_6 = F_101 ( V_83 , V_89 , V_3 ) ;
if ( V_6 && ( V_89 -> V_85 -> V_100 & V_171 ) )
V_6 = F_102 ( V_83 , V_89 , V_3 ) ;
if ( V_6 )
V_6 = F_103 ( V_83 , V_89 , V_3 ) ;
return V_6 ;
}
static int
F_104 ( const unsigned int V_83 , struct V_16 * V_172 , T_2 V_206 ,
T_2 V_207 , T_8 type , int V_208 , int V_209 , bool V_210 )
{
return F_98 ( V_83 , F_82 ( V_172 -> V_188 ) , V_172 -> V_19 . V_20 ,
V_196 -> V_197 , V_207 , V_206 , V_209 , V_208 ,
( V_211 ) type , V_210 , 0 ) ;
}
static int
F_105 ( const unsigned int V_83 , struct V_88 * V_89 ,
const unsigned char * V_212 , char * * V_213 ,
const struct V_214 * V_215 )
{
#ifdef F_106
int V_6 ;
unsigned int V_216 = 0 ;
struct V_217 * V_218 = NULL ;
V_6 = F_107 ( V_83 , V_89 -> V_85 , V_212 , V_215 ,
& V_216 , & V_218 , 0 ) ;
if ( ! V_6 && V_216 > 0 ) {
* V_213 = F_108 ( V_218 -> V_219 ,
strlen ( V_218 -> V_219 ) ,
V_113 ) ;
if ( ! * V_213 )
V_6 = - V_114 ;
F_109 ( V_218 , V_216 ) ;
}
return V_6 ;
#else
return - V_220 ;
#endif
}
static int
F_110 ( const unsigned int V_83 , struct V_88 * V_89 ,
const char * V_111 , char * * V_221 ,
struct V_109 * V_110 )
{
int V_6 ;
int V_125 = 0 ;
struct V_126 V_19 ;
struct V_127 V_128 ;
F_9 ( V_15 , L_27 , V_222 , V_111 ) ;
if ( F_111 ( V_89 -> V_85 ) ) {
V_6 = F_112 ( V_83 , V_89 , V_111 , V_221 ,
V_110 -> V_115 ) ;
if ( V_6 == - V_220 )
V_6 = F_105 ( V_83 , V_89 , V_111 ,
V_221 ,
V_110 -> V_115 ) ;
goto V_191;
}
V_128 . V_89 = V_89 ;
V_128 . V_110 = V_110 ;
V_128 . V_129 = V_130 ;
V_128 . V_131 = V_223 ;
V_128 . V_132 = V_133 ;
V_128 . V_134 = V_111 ;
V_128 . V_19 = & V_19 ;
V_128 . V_135 = false ;
V_6 = F_51 ( V_83 , & V_128 , & V_125 , NULL ) ;
if ( V_6 )
goto V_191;
V_6 = F_113 ( V_83 , V_89 , V_19 . V_20 , V_221 ,
V_110 -> V_115 ) ;
if ( V_6 )
goto V_224;
F_114 ( * V_221 , '/' ) ;
V_224:
F_52 ( V_83 , V_89 , V_19 . V_20 ) ;
V_191:
if ( ! V_6 )
F_9 ( V_15 , L_28 , V_222 , * V_221 ) ;
return V_6 ;
}
static bool
F_115 ( T_8 V_125 )
{
return V_125 == V_225 ;
}
