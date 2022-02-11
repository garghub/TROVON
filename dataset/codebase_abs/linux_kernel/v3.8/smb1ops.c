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
static void
F_53 ( struct V_87 * V_88 )
{
#ifdef F_54
F_55 ( & V_88 -> V_124 . V_125 . V_126 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_127 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_128 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_129 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_130 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_131 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_132 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_133 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_134 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_135 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_136 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_137 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_138 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_139 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_140 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_141 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_142 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_143 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_144 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_145 , 0 ) ;
F_55 ( & V_88 -> V_124 . V_125 . V_146 , 0 ) ;
#endif
}
static void
F_56 ( struct V_147 * V_148 , struct V_87 * V_88 )
{
#ifdef F_54
F_57 ( V_148 , L_18 ,
F_58 ( & V_88 -> V_124 . V_125 . V_129 ) ) ;
F_57 ( V_148 , L_19 ,
F_58 ( & V_88 -> V_124 . V_125 . V_127 ) ,
( long long ) ( V_88 -> V_149 ) ) ;
F_57 ( V_148 , L_20 ,
F_58 ( & V_88 -> V_124 . V_125 . V_126 ) ,
( long long ) ( V_88 -> V_150 ) ) ;
F_57 ( V_148 , L_21 ,
F_58 ( & V_88 -> V_124 . V_125 . V_128 ) ) ;
F_57 ( V_148 , L_22 ,
F_58 ( & V_88 -> V_124 . V_125 . V_144 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_142 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_143 ) ) ;
F_57 ( V_148 , L_23 ,
F_58 ( & V_88 -> V_124 . V_125 . V_130 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_133 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_134 ) ) ;
F_57 ( V_148 , L_24 ,
F_58 ( & V_88 -> V_124 . V_125 . V_131 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_132 ) ) ;
F_57 ( V_148 , L_25 ,
F_58 ( & V_88 -> V_124 . V_125 . V_135 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_136 ) ) ;
F_57 ( V_148 , L_26 ,
F_58 ( & V_88 -> V_124 . V_125 . V_137 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_138 ) ) ;
F_57 ( V_148 , L_27 ,
F_58 ( & V_88 -> V_124 . V_125 . V_139 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_140 ) ,
F_58 ( & V_88 -> V_124 . V_125 . V_141 ) ) ;
#endif
}
static void
F_59 ( struct V_151 * V_151 , const char * V_112 ,
struct V_110 * V_111 , struct V_87 * V_88 ,
const unsigned int V_82 )
{
T_6 V_152 ;
struct V_153 * V_154 ;
T_7 V_155 ;
int V_6 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_154 = F_60 ( V_151 ) ;
V_155 = V_154 -> V_156 | V_157 ;
V_152 . V_158 = F_61 ( V_155 ) ;
V_6 = F_62 ( V_82 , V_88 , V_112 , & V_152 , V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
if ( V_6 == 0 )
V_154 -> V_156 = V_155 ;
}
static int
F_63 ( const unsigned int V_82 , struct V_87 * V_88 , const char * V_159 ,
int V_160 , int V_161 , int V_162 ,
struct V_123 * V_19 , T_8 * V_163 , T_4 * V_3 ,
struct V_110 * V_111 )
{
if ( ! ( V_88 -> V_84 -> V_99 & V_164 ) )
return F_64 ( V_82 , V_88 , V_159 , V_160 ,
V_161 , V_162 ,
& V_19 -> V_20 , V_163 , V_3 ,
V_111 -> V_116 , V_111 -> V_117
& V_118 ) ;
return F_65 ( V_82 , V_88 , V_159 , V_160 , V_161 ,
V_162 , & V_19 -> V_20 , V_163 , V_3 ,
V_111 -> V_116 , V_111 -> V_117 &
V_118 ) ;
}
static void
F_66 ( struct V_16 * V_165 , struct V_123 * V_19 , T_8 V_163 )
{
struct V_153 * V_166 = F_60 ( V_165 -> V_167 -> V_168 ) ;
V_165 -> V_19 . V_20 = V_19 -> V_20 ;
F_67 ( V_166 , V_163 ) ;
V_166 -> V_169 = V_166 -> V_170 ;
}
static void
F_68 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
F_69 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_70 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
return F_71 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_72 ( const unsigned int V_82 , struct V_16 * V_165 ,
struct V_171 * V_172 , unsigned int * V_149 ,
char * * V_3 , int * V_173 )
{
V_172 -> V_20 = V_165 -> V_19 . V_20 ;
return F_73 ( V_82 , V_172 , V_149 , V_3 , V_173 ) ;
}
static int
F_74 ( const unsigned int V_82 , struct V_16 * V_165 ,
struct V_171 * V_172 , unsigned int * V_174 ,
struct V_175 * V_176 , unsigned long V_177 )
{
V_172 -> V_20 = V_165 -> V_19 . V_20 ;
return F_75 ( V_82 , V_172 , V_174 , V_176 , V_177 ) ;
}
static int
F_76 ( struct V_151 * V_151 , const char * V_112 ,
T_6 * V_3 , const unsigned int V_82 )
{
int V_163 = 0 ;
int V_6 ;
T_3 V_20 ;
T_8 V_178 ;
struct V_16 * V_179 ;
struct V_153 * V_166 = F_60 ( V_151 ) ;
struct V_110 * V_111 = F_77 ( V_151 -> V_180 ) ;
struct V_181 * V_182 = NULL ;
struct V_87 * V_88 ;
V_179 = F_78 ( V_166 , true ) ;
if ( V_179 ) {
V_20 = V_179 -> V_19 . V_20 ;
V_178 = V_179 -> V_183 ;
V_88 = F_79 ( V_179 -> V_182 ) ;
goto V_184;
}
V_182 = F_80 ( V_111 ) ;
if ( F_81 ( V_182 ) ) {
V_6 = F_82 ( V_182 ) ;
V_182 = NULL ;
goto V_185;
}
V_88 = F_79 ( V_182 ) ;
if ( ! ( V_88 -> V_84 -> V_186 & V_187 ) ) {
V_6 = F_62 ( V_82 , V_88 , V_112 , V_3 ,
V_111 -> V_116 ,
V_111 -> V_117 &
V_118 ) ;
if ( V_6 == 0 ) {
V_166 -> V_156 = F_83 ( V_3 -> V_158 ) ;
goto V_185;
} else if ( V_6 != - V_119 && V_6 != - V_54 )
goto V_185;
}
F_9 ( 1 , L_28
L_29 ) ;
V_6 = F_65 ( V_82 , V_88 , V_112 , V_188 ,
V_189 | V_190 , V_191 ,
& V_20 , & V_163 , NULL , V_111 -> V_116 ,
V_111 -> V_117 & V_118 ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_192 )
V_6 = - V_54 ;
goto V_185;
}
V_178 = V_193 -> V_194 ;
V_184:
V_6 = F_84 ( V_82 , V_88 , V_3 , V_20 , V_178 ) ;
if ( ! V_6 )
V_166 -> V_156 = F_83 ( V_3 -> V_158 ) ;
if ( V_179 == NULL )
F_69 ( V_82 , V_88 , V_20 ) ;
else
F_85 ( V_179 ) ;
V_185:
if ( V_182 != NULL )
F_86 ( V_182 ) ;
return V_6 ;
}
static int
F_87 ( const unsigned int V_82 , struct V_87 * V_88 ,
const char * V_159 , struct V_110 * V_111 ,
struct V_123 * V_19 , T_3 V_195 ,
struct V_196 * V_197 )
{
return F_88 ( V_82 , V_88 , V_159 , V_111 ,
& V_19 -> V_20 , V_195 , V_197 , true ) ;
}
static int
F_89 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 , T_3 V_195 ,
struct V_196 * V_197 )
{
return F_90 ( V_82 , V_88 , V_19 -> V_20 , V_195 , V_197 ) ;
}
static int
F_91 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_123 * V_19 )
{
return F_92 ( V_82 , V_88 , V_19 -> V_20 ) ;
}
static int
F_93 ( struct V_87 * V_88 , struct V_123 * V_19 ,
struct V_153 * V_166 )
{
return F_94 ( 0 , V_88 , V_19 -> V_20 , V_193 -> V_194 , 0 , 0 , 0 , 0 ,
V_198 , false ,
V_166 -> V_199 ? 1 : 0 ) ;
}
static int
F_95 ( const unsigned int V_82 , struct V_87 * V_88 ,
struct V_200 * V_3 )
{
int V_6 = - V_119 ;
V_3 -> V_201 = V_202 ;
if ( ( V_88 -> V_84 -> V_99 & V_101 ) &&
( V_203 & F_37 ( V_88 -> V_92 . V_93 ) ) )
V_6 = F_96 ( V_82 , V_88 , V_3 ) ;
if ( V_6 && ( V_88 -> V_84 -> V_99 & V_164 ) )
V_6 = F_97 ( V_82 , V_88 , V_3 ) ;
if ( V_6 )
V_6 = F_98 ( V_82 , V_88 , V_3 ) ;
return V_6 ;
}
static int
F_99 ( const unsigned int V_82 , struct V_16 * V_165 , T_2 V_204 ,
T_2 V_205 , T_8 type , int V_206 , int V_207 , bool V_208 )
{
return F_94 ( V_82 , F_79 ( V_165 -> V_182 ) , V_165 -> V_19 . V_20 ,
V_193 -> V_194 , V_205 , V_204 , V_207 , V_206 ,
( V_209 ) type , V_208 , 0 ) ;
}
