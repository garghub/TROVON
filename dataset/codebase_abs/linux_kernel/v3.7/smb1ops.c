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
V_6 = F_7 ( V_2 , V_8 , F_8 ( V_8 -> V_9 ) ) ;
F_6 ( & V_2 -> V_13 ) ;
F_9 ( 1 , L_1 ,
V_8 -> V_15 , V_6 ) ;
return V_6 ;
}
static bool
F_10 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
return V_17 -> V_19 . V_20 == V_18 -> V_19 . V_20 ;
}
static unsigned int
F_11 ( char * V_3 )
{
T_1 * V_21 = ( T_1 * ) V_3 ;
return F_12 ( V_21 -> V_22 ) ;
}
static unsigned int
F_13 ( char * V_3 )
{
T_1 * V_21 = ( T_1 * ) V_3 ;
return ( F_12 ( V_21 -> V_23 ) << 16 ) +
F_12 ( V_21 -> V_24 ) ;
}
static struct V_4 *
F_14 ( struct V_1 * V_2 , char * V_25 )
{
struct V_7 * V_3 = (struct V_7 * ) V_25 ;
struct V_4 * V_5 ;
F_15 ( & V_26 ) ;
F_16 (mid, &server->pending_mid_q, qhead) {
if ( V_5 -> V_5 == V_3 -> V_15 &&
V_5 -> V_27 == V_28 &&
F_12 ( V_5 -> V_29 ) == V_3 -> V_10 ) {
F_17 ( & V_26 ) ;
return V_5 ;
}
}
F_17 ( & V_26 ) ;
return NULL ;
}
static void
F_18 ( struct V_1 * V_2 , const unsigned int V_30 ,
const int V_31 )
{
F_15 ( & V_2 -> V_32 ) ;
V_2 -> V_33 += V_30 ;
V_2 -> V_34 -- ;
F_17 ( & V_2 -> V_32 ) ;
F_19 ( & V_2 -> V_35 ) ;
}
static void
F_20 ( struct V_1 * V_2 , const int V_36 )
{
F_15 ( & V_2 -> V_32 ) ;
V_2 -> V_33 = V_36 ;
V_2 -> V_37 = V_36 > 1 ? V_38 : false ;
F_17 ( & V_2 -> V_32 ) ;
}
static int *
F_21 ( struct V_1 * V_2 , const int V_31 )
{
return & V_2 -> V_33 ;
}
static unsigned int
F_22 ( struct V_4 * V_5 )
{
return 1 ;
}
static T_2
F_23 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
T_3 V_39 , V_40 ;
bool V_41 ;
F_15 ( & V_26 ) ;
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
F_16 (mid_entry, &server->pending_mid_q, qhead) {
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
F_17 ( & V_26 ) ;
return V_5 ;
}
static int
F_24 ( char * V_3 )
{
struct V_7 * V_47 = (struct V_7 * ) V_3 ;
struct V_48 * V_49 ;
int V_50 ;
T_3 V_51 , V_52 ;
if ( V_47 -> V_10 != V_53 )
return 0 ;
if ( V_47 -> V_12 != 10 ) {
F_9 ( 1 , L_2 ) ;
return - V_54 ;
}
V_49 = (struct V_48 * ) V_47 ;
V_51 = F_25 ( & V_49 -> V_55 . V_56 ) ;
V_52 = F_25 ( & V_49 -> V_55 . V_57 ) ;
if ( V_51 == V_52 )
return 0 ;
else if ( V_51 < V_52 ) {
F_9 ( 1 , L_3 ,
V_51 , V_52 ) ;
return - V_54 ;
}
V_50 = V_51 - V_52 ;
F_9 ( 1 , L_4 ,
V_50 ) ;
if ( V_51 > V_58 ) {
F_26 ( 1 , L_5 ,
V_51 , V_58 ) ;
return - V_54 ;
}
return V_50 ;
}
static int
F_27 ( char * V_59 , struct V_7 * V_60 )
{
struct V_48 * V_61 = (struct V_48 * ) V_59 ;
struct V_48 * V_49 = (struct V_48 * ) V_60 ;
char * V_62 ;
char * V_63 ;
int V_50 ;
unsigned int V_64 , V_65 ;
T_3 V_66 , V_67 , V_68 ;
V_67 = F_25 ( & V_61 -> V_55 . V_56 ) ;
V_66 = F_25 ( & V_49 -> V_55 . V_56 ) ;
if ( V_66 != V_67 )
F_9 ( 1 , L_6
L_7 , V_67 , V_66 ) ;
V_65 = F_25 ( & V_49 -> V_55 . V_57 ) ;
V_50 = V_66 - V_65 ;
if ( V_50 < 0 ) {
F_9 ( 1 , L_8
L_9 , V_66 , V_65 ) ;
return - V_69 ;
}
if ( V_50 == 0 ) {
F_9 ( 1 , L_10 ) ;
return 0 ;
}
V_68 = F_25 ( & V_61 -> V_55 . V_57 ) ;
if ( V_50 < V_68 )
F_9 ( 1 , L_11 ) ;
V_62 = ( char * ) & V_49 -> V_70 . V_71 +
F_25 ( & V_49 -> V_55 . V_22 ) ;
V_63 = ( char * ) & V_61 -> V_70 . V_71 +
F_25 ( & V_61 -> V_55 . V_22 ) ;
V_62 += V_65 ;
V_65 += V_68 ;
if ( V_65 > V_72 ) {
F_9 ( 1 , L_12 , V_65 ) ;
return - V_69 ;
}
F_28 ( V_65 , & V_49 -> V_55 . V_57 ) ;
V_64 = F_29 ( V_60 ) ;
V_64 += V_68 ;
if ( V_64 > V_72 ) {
F_9 ( 1 , L_13 , V_64 ) ;
return - V_69 ;
}
F_3 ( V_64 , V_60 ) ;
V_64 = F_8 ( V_60 -> V_9 ) ;
V_64 += V_68 ;
if ( V_64 > V_58 + V_73 - 4 ) {
F_9 ( 1 , L_14 , V_64 ) ;
return - V_74 ;
}
V_60 -> V_9 = F_2 ( V_64 ) ;
memcpy ( V_62 , V_63 , V_68 ) ;
if ( V_50 != V_68 ) {
F_9 ( 1 , L_15 ) ;
return 1 ;
}
F_9 ( 1 , L_16 ) ;
return 0 ;
}
static bool
F_30 ( struct V_4 * V_5 , struct V_1 * V_2 ,
char * V_3 , int V_75 )
{
if ( V_75 )
return false ;
if ( F_24 ( V_3 ) <= 0 )
return false ;
V_5 -> V_76 = true ;
if ( V_5 -> V_77 ) {
V_75 = F_27 ( V_3 , V_5 -> V_77 ) ;
if ( V_75 > 0 )
return true ;
V_5 -> V_78 = true ;
F_31 ( V_5 , V_75 ) ;
return true ;
}
if ( ! V_2 -> V_79 ) {
F_26 ( 1 , L_17 ) ;
} else {
V_5 -> V_77 = V_3 ;
V_5 -> V_79 = true ;
V_2 -> V_80 = NULL ;
}
return true ;
}
static bool
F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_81 == 0 ;
}
static int
F_33 ( const unsigned int V_82 , struct V_83 * V_84 )
{
int V_6 ;
V_6 = F_34 ( V_82 , V_84 ) ;
if ( V_6 == - V_85 ) {
F_35 ( V_84 -> V_2 , 1 ) ;
V_6 = F_34 ( V_82 , V_84 ) ;
if ( V_6 == - V_85 )
V_6 = - V_86 ;
}
return V_6 ;
}
static unsigned int
F_36 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
T_2 V_91 = F_37 ( V_88 -> V_92 . V_93 ) ;
struct V_1 * V_2 = V_88 -> V_84 -> V_2 ;
unsigned int V_94 ;
if ( V_90 -> V_94 )
V_94 = V_90 -> V_94 ;
else if ( V_88 -> V_95 && ( V_91 & V_96 ) )
V_94 = V_97 ;
else
V_94 = V_98 ;
if ( ! V_88 -> V_95 || ! ( V_91 & V_96 ) )
V_94 = F_38 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_99 & V_100 ) ||
( ! ( V_2 -> V_99 & V_101 ) &&
( V_2 -> V_102 & ( V_103 | V_104 ) ) ) )
V_94 = F_38 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_94 = F_38 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_94 ;
}
static unsigned int
F_39 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
T_2 V_91 = F_37 ( V_88 -> V_92 . V_93 ) ;
struct V_1 * V_2 = V_88 -> V_84 -> V_2 ;
unsigned int V_105 , V_106 ;
if ( V_88 -> V_95 && ( V_91 & V_107 ) )
V_106 = V_97 ;
else if ( V_2 -> V_99 & V_108 )
V_106 = V_109 ;
else
V_106 = V_2 -> V_81 - sizeof( T_1 ) ;
V_105 = V_90 -> V_105 ? V_90 -> V_105 : V_106 ;
if ( ! ( V_2 -> V_99 & V_108 ) )
V_105 = F_38 (unsigned int, CIFSMaxBufSize, rsize) ;
V_105 = F_38 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_105 ;
}
static void
F_40 ( const unsigned int V_82 , struct V_87 * V_88 )
{
F_41 ( V_82 , V_88 ) ;
F_42 ( V_82 , V_88 ) ;
}
static int
F_43 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_110 * V_111 , const char * V_112 )
{
int V_6 ;
T_4 * V_113 ;
V_113 = F_44 ( sizeof( T_4 ) , V_114 ) ;
if ( V_113 == NULL )
return - V_115 ;
V_6 = F_45 ( V_82 , V_88 , V_112 , V_113 ,
0 , V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
if ( V_6 == - V_119 || V_6 == - V_54 )
V_6 = F_46 ( V_82 , V_88 , V_112 , V_113 ,
V_111 -> V_116 , V_111 -> V_117 &
V_118 ) ;
F_47 ( V_113 ) ;
return V_6 ;
}
static int
F_48 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_110 * V_111 , const char * V_112 ,
T_4 * V_120 , bool * V_121 )
{
int V_6 ;
V_6 = F_45 ( V_82 , V_88 , V_112 , V_120 , 0 ,
V_111 -> V_116 , V_111 -> V_117 &
V_118 ) ;
if ( ( V_6 == - V_119 ) || ( V_6 == - V_54 ) ) {
V_6 = F_46 ( V_82 , V_88 , V_112 , V_120 ,
V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
* V_121 = true ;
}
return V_6 ;
}
static int
F_49 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_110 * V_111 , const char * V_112 ,
T_5 * V_122 , T_4 * V_120 )
{
return F_50 ( V_82 , V_88 , V_112 , V_122 ,
V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
}
static int
F_51 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 , T_4 * V_120 )
{
return F_52 ( V_82 , V_88 , V_19 -> V_20 , V_120 ) ;
}
static char *
F_53 ( struct V_89 * V_124 , struct V_110 * V_111 ,
struct V_87 * V_88 )
{
int V_125 = V_124 -> V_126 ? strlen ( V_124 -> V_126 ) : 0 ;
int V_127 ;
char * V_112 = NULL ;
if ( V_125 == 0 ) {
V_112 = F_54 ( 1 , V_114 ) ;
return V_112 ;
}
if ( V_88 -> V_128 & V_129 )
V_127 = F_55 ( V_88 -> V_130 , V_131 + 1 ) ;
else
V_127 = 0 ;
V_112 = F_44 ( V_127 + V_125 + 1 , V_114 ) ;
if ( V_112 == NULL )
return V_112 ;
if ( V_127 )
strncpy ( V_112 , V_88 -> V_130 , V_127 ) ;
strncpy ( V_112 + V_127 , V_124 -> V_126 , V_125 ) ;
F_56 ( V_112 , F_57 ( V_111 ) ) ;
V_112 [ V_127 + V_125 ] = 0 ;
return V_112 ;
}
static void
F_58 ( struct V_87 * V_88 )
{
#ifdef F_59
F_60 ( & V_88 -> V_132 . V_133 . V_134 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_135 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_136 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_137 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_138 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_139 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_140 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_141 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_142 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_143 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_144 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_145 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_146 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_147 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_148 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_149 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_150 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_151 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_152 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_153 , 0 ) ;
F_60 ( & V_88 -> V_132 . V_133 . V_154 , 0 ) ;
#endif
}
static void
F_61 ( struct V_155 * V_156 , struct V_87 * V_88 )
{
#ifdef F_59
F_62 ( V_156 , L_18 ,
F_63 ( & V_88 -> V_132 . V_133 . V_137 ) ) ;
F_62 ( V_156 , L_19 ,
F_63 ( & V_88 -> V_132 . V_133 . V_135 ) ,
( long long ) ( V_88 -> V_157 ) ) ;
F_62 ( V_156 , L_20 ,
F_63 ( & V_88 -> V_132 . V_133 . V_134 ) ,
( long long ) ( V_88 -> V_158 ) ) ;
F_62 ( V_156 , L_21 ,
F_63 ( & V_88 -> V_132 . V_133 . V_136 ) ) ;
F_62 ( V_156 , L_22 ,
F_63 ( & V_88 -> V_132 . V_133 . V_152 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_150 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_151 ) ) ;
F_62 ( V_156 , L_23 ,
F_63 ( & V_88 -> V_132 . V_133 . V_138 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_141 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_142 ) ) ;
F_62 ( V_156 , L_24 ,
F_63 ( & V_88 -> V_132 . V_133 . V_139 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_140 ) ) ;
F_62 ( V_156 , L_25 ,
F_63 ( & V_88 -> V_132 . V_133 . V_143 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_144 ) ) ;
F_62 ( V_156 , L_26 ,
F_63 ( & V_88 -> V_132 . V_133 . V_145 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_146 ) ) ;
F_62 ( V_156 , L_27 ,
F_63 ( & V_88 -> V_132 . V_133 . V_147 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_148 ) ,
F_63 ( & V_88 -> V_132 . V_133 . V_149 ) ) ;
#endif
}
static void
F_64 ( struct V_159 * V_159 , const char * V_112 ,
struct V_110 * V_111 , struct V_87 * V_88 ,
const unsigned int V_82 )
{
T_6 V_160 ;
struct V_161 * V_162 ;
T_7 V_163 ;
int V_6 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_162 = F_65 ( V_159 ) ;
V_163 = V_162 -> V_164 | V_165 ;
V_160 . V_166 = F_66 ( V_163 ) ;
V_6 = F_67 ( V_82 , V_88 , V_112 , & V_160 , V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
if ( V_6 == 0 )
V_162 -> V_164 = V_163 ;
}
static int
F_68 ( const unsigned int V_82 , struct V_87 * V_88 , const char * V_167 ,
int V_168 , int V_169 , int V_170 ,
struct V_123 * V_19 , T_8 * V_171 , T_4 * V_3 ,
struct V_110 * V_111 )
{
if ( ! ( V_88 -> V_84 -> V_99 & V_172 ) )
return F_69 ( V_82 , V_88 , V_167 , V_168 ,
V_169 , V_170 ,
& V_19 -> V_20 , V_171 , V_3 ,
V_111 -> V_116 , V_111 -> V_117
& V_118 ) ;
return F_70 ( V_82 , V_88 , V_167 , V_168 , V_169 ,
V_170 , & V_19 -> V_20 , V_171 , V_3 ,
V_111 -> V_116 , V_111 -> V_117 &
V_118 ) ;
}
static void
F_71 ( struct V_16 * V_173 , struct V_123 * V_19 , T_8 V_171 )
{
struct V_161 * V_174 = F_65 ( V_173 -> V_175 -> V_176 ) ;
V_173 -> V_19 . V_20 = V_19 -> V_20 ;
F_72 ( V_174 , V_171 ) ;
V_174 -> V_177 = V_174 -> V_178 ;
}
static void
F_73 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
F_74 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_75 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
return F_76 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_77 ( const unsigned int V_82 , struct V_16 * V_173 ,
struct V_179 * V_180 , unsigned int * V_157 ,
char * * V_3 , int * V_181 )
{
V_180 -> V_20 = V_173 -> V_19 . V_20 ;
return F_78 ( V_82 , V_180 , V_157 , V_3 , V_181 ) ;
}
static int
F_79 ( const unsigned int V_82 , struct V_16 * V_173 ,
struct V_179 * V_180 , unsigned int * V_182 ,
struct V_183 * V_184 , unsigned long V_185 )
{
V_180 -> V_20 = V_173 -> V_19 . V_20 ;
return F_80 ( V_82 , V_180 , V_182 , V_184 , V_185 ) ;
}
static int
F_81 ( struct V_159 * V_159 , const char * V_112 ,
T_6 * V_3 , const unsigned int V_82 )
{
int V_171 = 0 ;
int V_6 ;
T_3 V_20 ;
T_8 V_186 ;
struct V_16 * V_187 ;
struct V_161 * V_174 = F_65 ( V_159 ) ;
struct V_110 * V_111 = F_82 ( V_159 -> V_188 ) ;
struct V_189 * V_190 = NULL ;
struct V_87 * V_88 ;
V_187 = F_83 ( V_174 , true ) ;
if ( V_187 ) {
V_20 = V_187 -> V_19 . V_20 ;
V_186 = V_187 -> V_191 ;
V_88 = F_84 ( V_187 -> V_190 ) ;
goto V_192;
}
V_190 = F_85 ( V_111 ) ;
if ( F_86 ( V_190 ) ) {
V_6 = F_87 ( V_190 ) ;
V_190 = NULL ;
goto V_193;
}
V_88 = F_84 ( V_190 ) ;
if ( ! ( V_88 -> V_84 -> V_194 & V_195 ) ) {
V_6 = F_67 ( V_82 , V_88 , V_112 , V_3 ,
V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
if ( V_6 == 0 ) {
V_174 -> V_164 = F_88 ( V_3 -> V_166 ) ;
goto V_193;
} else if ( V_6 != - V_119 && V_6 != - V_54 )
goto V_193;
}
F_9 ( 1 , L_28
L_29 ) ;
V_6 = F_70 ( V_82 , V_88 , V_112 , V_196 ,
V_197 | V_198 , V_199 ,
& V_20 , & V_171 , NULL , V_111 -> V_116 ,
V_111 -> V_117 & V_118 ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_200 )
V_6 = - V_54 ;
goto V_193;
}
V_186 = V_201 -> V_202 ;
V_192:
V_6 = F_89 ( V_82 , V_88 , V_3 , V_20 , V_186 ) ;
if ( ! V_6 )
V_174 -> V_164 = F_88 ( V_3 -> V_166 ) ;
if ( V_187 == NULL )
F_74 ( V_82 , V_88 , V_20 ) ;
else
F_90 ( V_187 ) ;
V_193:
if ( V_190 != NULL )
F_91 ( V_190 ) ;
return V_6 ;
}
static int
F_92 ( const unsigned int V_82 , struct V_87 * V_88 ,
const char * V_167 , struct V_110 * V_111 ,
struct V_123 * V_19 , T_3 V_203 ,
struct V_204 * V_205 )
{
return F_93 ( V_82 , V_88 , V_167 , V_111 ,
& V_19 -> V_20 , V_203 , V_205 , true ) ;
}
static int
F_94 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 , T_3 V_203 ,
struct V_204 * V_205 )
{
return F_95 ( V_82 , V_88 , V_19 -> V_20 , V_203 , V_205 ) ;
}
static int
F_96 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
return F_97 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_98 ( struct V_87 * V_88 , struct V_123 * V_19 ,
struct V_161 * V_174 )
{
return F_99 ( 0 , V_88 , V_19 -> V_20 , V_201 -> V_202 , 0 , 0 , 0 , 0 ,
V_206 , false ,
V_174 -> V_207 ? 1 : 0 ) ;
}
static int
F_100 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_208 * V_3 )
{
int V_6 = - V_119 ;
V_3 -> V_209 = V_210 ;
if ( ( V_88 -> V_84 -> V_99 & V_101 ) &&
( V_211 & F_37 ( V_88 -> V_92 . V_93 ) ) )
V_6 = F_101 ( V_82 , V_88 , V_3 ) ;
if ( V_6 && ( V_88 -> V_84 -> V_99 & V_172 ) )
V_6 = F_102 ( V_82 , V_88 , V_3 ) ;
if ( V_6 )
V_6 = F_103 ( V_82 , V_88 , V_3 ) ;
return V_6 ;
}
static int
F_104 ( const unsigned int V_82 , struct V_16 * V_173 , T_2 V_212 ,
T_2 V_213 , T_8 type , int V_214 , int V_215 , bool V_216 )
{
return F_99 ( V_82 , F_84 ( V_173 -> V_190 ) , V_173 -> V_19 . V_20 ,
V_201 -> V_202 , V_213 , V_212 , V_215 , V_214 ,
( V_217 ) type , V_216 , 0 ) ;
}
