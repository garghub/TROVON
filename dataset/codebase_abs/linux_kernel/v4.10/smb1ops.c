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
static void
F_31 ( struct V_1 * V_2 ,
struct V_76 * V_77 , bool V_78 )
{
if ( V_78 )
F_32 ( V_77 , V_79 ) ;
else
F_32 ( V_77 , 0 ) ;
}
static bool
F_33 ( struct V_4 * V_5 , struct V_1 * V_2 ,
char * V_3 , int V_80 )
{
if ( V_80 )
return false ;
if ( F_26 ( V_3 ) <= 0 )
return false ;
V_5 -> V_81 = true ;
if ( V_5 -> V_82 ) {
V_80 = F_28 ( V_3 , V_5 -> V_82 ) ;
if ( V_80 > 0 )
return true ;
V_5 -> V_83 = true ;
F_34 ( V_5 , V_80 ) ;
return true ;
}
if ( ! V_2 -> V_84 ) {
F_9 ( V_59 , L_15 ) ;
} else {
V_5 -> V_82 = V_3 ;
V_5 -> V_84 = true ;
V_2 -> V_85 = NULL ;
}
return true ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_86 == 0 ;
}
static int
F_36 ( const unsigned int V_87 , struct V_88 * V_89 )
{
int V_6 ;
V_6 = F_37 ( V_87 , V_89 ) ;
if ( V_6 == - V_90 ) {
F_38 ( V_89 -> V_2 , 1 ) ;
V_6 = F_37 ( V_87 , V_89 ) ;
if ( V_6 == - V_90 )
V_6 = - V_91 ;
}
return V_6 ;
}
static unsigned int
F_39 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
T_2 V_96 = F_40 ( V_93 -> V_97 . V_98 ) ;
struct V_1 * V_2 = V_93 -> V_89 -> V_2 ;
unsigned int V_99 ;
if ( V_95 -> V_99 )
V_99 = V_95 -> V_99 ;
else if ( V_93 -> V_100 && ( V_96 & V_101 ) )
V_99 = V_102 ;
else
V_99 = V_103 ;
if ( ! V_93 -> V_100 || ! ( V_96 & V_101 ) )
V_99 = F_41 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_104 & V_105 ) ||
( ! ( V_2 -> V_104 & V_106 ) && V_2 -> V_107 ) )
V_99 = F_41 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_99 = F_41 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_99 ;
}
static unsigned int
F_42 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
T_2 V_96 = F_40 ( V_93 -> V_97 . V_98 ) ;
struct V_1 * V_2 = V_93 -> V_89 -> V_2 ;
unsigned int V_108 , V_109 ;
if ( V_93 -> V_100 && ( V_96 & V_110 ) )
V_109 = V_102 ;
else if ( V_2 -> V_104 & V_111 )
V_109 = V_112 ;
else
V_109 = V_2 -> V_86 - sizeof( T_1 ) ;
V_108 = V_95 -> V_108 ? V_95 -> V_108 : V_109 ;
if ( ! ( V_2 -> V_104 & V_111 ) )
V_108 = F_41 (unsigned int, CIFSMaxBufSize, rsize) ;
V_108 = F_41 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_108 ;
}
static void
F_43 ( const unsigned int V_87 , struct V_92 * V_93 )
{
F_44 ( V_87 , V_93 ) ;
F_45 ( V_87 , V_93 ) ;
}
static int
F_46 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_113 * V_114 , const char * V_115 )
{
int V_6 ;
T_4 * V_116 ;
V_116 = F_47 ( sizeof( T_4 ) , V_117 ) ;
if ( V_116 == NULL )
return - V_118 ;
V_6 = F_48 ( V_87 , V_93 , V_115 , V_116 ,
0 , V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
if ( V_6 == - V_120 || V_6 == - V_54 )
V_6 = F_50 ( V_87 , V_93 , V_115 , V_116 ,
V_114 -> V_119 , F_49 ( V_114 ) ) ;
F_51 ( V_116 ) ;
return V_6 ;
}
static int
F_52 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_113 * V_114 , const char * V_115 ,
T_4 * V_121 , bool * V_122 , bool * V_123 )
{
int V_6 ;
* V_123 = false ;
V_6 = F_48 ( V_87 , V_93 , V_115 , V_121 , 0 ,
V_114 -> V_119 , F_49 ( V_114 ) ) ;
if ( ( V_6 == - V_120 ) || ( V_6 == - V_54 ) ) {
V_6 = F_50 ( V_87 , V_93 , V_115 , V_121 ,
V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
* V_122 = true ;
}
if ( ! V_6 && ( F_53 ( V_121 -> V_124 ) & V_125 ) ) {
int V_126 ;
int V_127 = 0 ;
struct V_128 V_19 ;
struct V_129 V_130 ;
V_130 . V_93 = V_93 ;
V_130 . V_114 = V_114 ;
V_130 . V_131 = V_132 ;
V_130 . V_133 = 0 ;
V_130 . V_134 = V_135 ;
V_130 . V_136 = V_115 ;
V_130 . V_19 = & V_19 ;
V_130 . V_137 = false ;
V_126 = F_54 ( V_87 , & V_130 , & V_127 , NULL ) ;
if ( V_126 == - V_120 )
* V_123 = true ;
else if ( V_126 == 0 )
F_55 ( V_87 , V_93 , V_19 . V_20 ) ;
}
return V_6 ;
}
static int
F_56 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_113 * V_114 , const char * V_115 ,
T_5 * V_138 , T_4 * V_121 )
{
return F_57 ( V_87 , V_93 , V_115 , V_138 ,
V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
}
static int
F_58 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_128 * V_19 , T_4 * V_121 )
{
return F_59 ( V_87 , V_93 , V_19 -> V_20 , V_121 ) ;
}
static void
F_60 ( struct V_92 * V_93 )
{
#ifdef F_61
F_62 ( & V_93 -> V_139 . V_140 . V_141 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_142 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_143 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_144 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_145 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_146 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_147 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_148 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_149 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_150 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_151 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_152 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_153 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_154 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_155 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_156 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_157 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_158 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_159 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_160 , 0 ) ;
F_62 ( & V_93 -> V_139 . V_140 . V_161 , 0 ) ;
#endif
}
static void
F_63 ( struct V_162 * V_163 , struct V_92 * V_93 )
{
#ifdef F_61
F_64 ( V_163 , L_16 ,
F_65 ( & V_93 -> V_139 . V_140 . V_144 ) ) ;
F_64 ( V_163 , L_17 ,
F_65 ( & V_93 -> V_139 . V_140 . V_142 ) ,
( long long ) ( V_93 -> V_164 ) ) ;
F_64 ( V_163 , L_18 ,
F_65 ( & V_93 -> V_139 . V_140 . V_141 ) ,
( long long ) ( V_93 -> V_165 ) ) ;
F_64 ( V_163 , L_19 ,
F_65 ( & V_93 -> V_139 . V_140 . V_143 ) ) ;
F_64 ( V_163 , L_20 ,
F_65 ( & V_93 -> V_139 . V_140 . V_159 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_157 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_158 ) ) ;
F_64 ( V_163 , L_21 ,
F_65 ( & V_93 -> V_139 . V_140 . V_145 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_148 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_149 ) ) ;
F_64 ( V_163 , L_22 ,
F_65 ( & V_93 -> V_139 . V_140 . V_146 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_147 ) ) ;
F_64 ( V_163 , L_23 ,
F_65 ( & V_93 -> V_139 . V_140 . V_150 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_151 ) ) ;
F_64 ( V_163 , L_24 ,
F_65 ( & V_93 -> V_139 . V_140 . V_152 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_153 ) ) ;
F_64 ( V_163 , L_25 ,
F_65 ( & V_93 -> V_139 . V_140 . V_154 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_155 ) ,
F_65 ( & V_93 -> V_139 . V_140 . V_156 ) ) ;
#endif
}
static void
F_66 ( struct V_166 * V_166 , const char * V_115 ,
struct V_113 * V_114 , struct V_92 * V_93 ,
const unsigned int V_87 )
{
T_6 V_167 ;
struct V_76 * V_168 ;
T_7 V_169 ;
int V_6 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_168 = F_67 ( V_166 ) ;
V_169 = V_168 -> V_170 | V_171 ;
V_167 . V_124 = F_68 ( V_169 ) ;
V_6 = F_69 ( V_87 , V_93 , V_115 , & V_167 , V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
if ( V_6 == 0 )
V_168 -> V_170 = V_169 ;
}
static int
F_70 ( const unsigned int V_87 , struct V_129 * V_130 ,
T_8 * V_127 , T_4 * V_3 )
{
if ( ! ( V_130 -> V_93 -> V_89 -> V_104 & V_172 ) )
return F_71 ( V_87 , V_130 -> V_93 , V_130 -> V_136 ,
V_130 -> V_134 ,
V_130 -> V_131 ,
V_130 -> V_133 ,
& V_130 -> V_19 -> V_20 , V_127 , V_3 ,
V_130 -> V_114 -> V_119 ,
F_49 ( V_130 -> V_114 ) ) ;
return F_54 ( V_87 , V_130 , V_127 , V_3 ) ;
}
static void
F_72 ( struct V_16 * V_173 , struct V_128 * V_19 , T_8 V_127 )
{
struct V_76 * V_77 = F_67 ( F_73 ( V_173 -> V_174 ) ) ;
V_173 -> V_19 . V_20 = V_19 -> V_20 ;
F_32 ( V_77 , V_127 ) ;
V_77 -> V_175 = F_74 ( V_77 ) ;
}
static void
F_75 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_128 * V_19 )
{
F_55 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_76 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_128 * V_19 )
{
return F_77 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_78 ( const unsigned int V_87 , struct V_128 * V_176 ,
struct V_177 * V_178 , unsigned int * V_164 ,
char * * V_3 , int * V_179 )
{
V_178 -> V_20 = V_176 -> V_20 ;
return F_79 ( V_87 , V_178 , V_164 , V_3 , V_179 ) ;
}
static int
F_80 ( const unsigned int V_87 , struct V_128 * V_176 ,
struct V_177 * V_178 , unsigned int * V_180 ,
struct V_181 * V_182 , unsigned long V_183 )
{
V_178 -> V_20 = V_176 -> V_20 ;
return F_81 ( V_87 , V_178 , V_180 , V_182 , V_183 ) ;
}
static int
F_82 ( struct V_166 * V_166 , const char * V_115 ,
T_6 * V_3 , const unsigned int V_87 )
{
int V_127 = 0 ;
int V_6 ;
T_8 V_184 ;
struct V_128 V_19 ;
struct V_129 V_130 ;
struct V_16 * V_185 ;
struct V_76 * V_77 = F_67 ( V_166 ) ;
struct V_113 * V_114 = F_83 ( V_166 -> V_186 ) ;
struct V_187 * V_188 = NULL ;
struct V_92 * V_93 ;
V_185 = F_84 ( V_77 , true ) ;
if ( V_185 ) {
V_19 . V_20 = V_185 -> V_19 . V_20 ;
V_184 = V_185 -> V_189 ;
V_93 = F_85 ( V_185 -> V_188 ) ;
goto V_190;
}
V_188 = F_86 ( V_114 ) ;
if ( F_87 ( V_188 ) ) {
V_6 = F_88 ( V_188 ) ;
V_188 = NULL ;
goto V_191;
}
V_93 = F_85 ( V_188 ) ;
V_6 = F_69 ( V_87 , V_93 , V_115 , V_3 , V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
if ( V_6 == 0 ) {
V_77 -> V_170 = F_53 ( V_3 -> V_124 ) ;
goto V_191;
} else if ( V_6 != - V_120 && V_6 != - V_54 ) {
goto V_191;
}
V_130 . V_93 = V_93 ;
V_130 . V_114 = V_114 ;
V_130 . V_131 = V_192 | V_193 ;
V_130 . V_133 = V_194 ;
V_130 . V_134 = V_135 ;
V_130 . V_136 = V_115 ;
V_130 . V_19 = & V_19 ;
V_130 . V_137 = false ;
F_9 ( V_15 , L_26 ) ;
V_6 = F_54 ( V_87 , & V_130 , & V_127 , NULL ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_195 )
V_6 = - V_54 ;
goto V_191;
}
V_184 = V_196 -> V_197 ;
V_190:
V_6 = F_89 ( V_87 , V_93 , V_3 , V_19 . V_20 , V_184 ) ;
if ( ! V_6 )
V_77 -> V_170 = F_53 ( V_3 -> V_124 ) ;
if ( V_185 == NULL )
F_55 ( V_87 , V_93 , V_19 . V_20 ) ;
else
F_90 ( V_185 ) ;
V_191:
if ( V_188 != NULL )
F_91 ( V_188 ) ;
return V_6 ;
}
static int
F_92 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_16 * V_173 )
{
return F_93 ( V_87 , V_93 , V_173 -> V_19 . V_20 ) ;
}
static int
F_94 ( const unsigned int V_87 , struct V_92 * V_93 ,
const char * V_136 , struct V_113 * V_114 ,
struct V_128 * V_19 , T_3 V_198 ,
struct V_199 * V_200 )
{
return F_95 ( V_87 , V_93 , V_136 , V_114 ,
& V_19 -> V_20 , V_198 , V_200 , true ) ;
}
static int
F_96 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_128 * V_19 , T_3 V_198 ,
struct V_199 * V_200 )
{
return F_97 ( V_87 , V_93 , V_19 -> V_20 , V_198 , V_200 ) ;
}
static int
F_98 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_128 * V_19 )
{
return F_99 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_100 ( struct V_92 * V_93 , struct V_128 * V_19 ,
struct V_76 * V_77 )
{
return F_101 ( 0 , V_93 , V_19 -> V_20 , V_196 -> V_197 , 0 , 0 , 0 , 0 ,
V_201 , false ,
F_102 ( V_77 ) ? 1 : 0 ) ;
}
static int
F_103 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_202 * V_3 )
{
int V_6 = - V_120 ;
V_3 -> V_203 = V_204 ;
if ( ( V_93 -> V_89 -> V_104 & V_106 ) &&
( V_205 & F_40 ( V_93 -> V_97 . V_98 ) ) )
V_6 = F_104 ( V_87 , V_93 , V_3 ) ;
if ( V_6 && ( V_93 -> V_89 -> V_104 & V_172 ) )
V_6 = F_105 ( V_87 , V_93 , V_3 ) ;
if ( V_6 )
V_6 = F_106 ( V_87 , V_93 , V_3 ) ;
return V_6 ;
}
static int
F_107 ( const unsigned int V_87 , struct V_16 * V_173 , T_2 V_206 ,
T_2 V_207 , T_8 type , int V_208 , int V_209 , bool V_210 )
{
return F_101 ( V_87 , F_85 ( V_173 -> V_188 ) , V_173 -> V_19 . V_20 ,
V_196 -> V_197 , V_207 , V_206 , V_209 , V_208 ,
( V_211 ) type , V_210 , 0 ) ;
}
static int
F_108 ( const unsigned int V_87 , struct V_92 * V_93 ,
const unsigned char * V_212 , char * * V_213 ,
const struct V_214 * V_215 )
{
#ifdef F_109
int V_6 ;
unsigned int V_216 = 0 ;
struct V_217 * V_218 = NULL ;
V_6 = F_110 ( V_87 , V_93 -> V_89 , V_212 , V_215 ,
& V_216 , & V_218 , 0 ) ;
if ( ! V_6 && V_216 > 0 ) {
* V_213 = F_111 ( V_218 -> V_219 ,
strlen ( V_218 -> V_219 ) ,
V_117 ) ;
if ( ! * V_213 )
V_6 = - V_118 ;
F_112 ( V_218 , V_216 ) ;
}
return V_6 ;
#else
return - V_220 ;
#endif
}
static int
F_113 ( const unsigned int V_87 , struct V_92 * V_93 ,
const char * V_115 , char * * V_221 ,
struct V_113 * V_114 )
{
int V_6 ;
int V_127 = 0 ;
struct V_128 V_19 ;
struct V_129 V_130 ;
F_9 ( V_15 , L_27 , V_222 , V_115 ) ;
if ( F_114 ( V_93 -> V_89 ) ) {
V_6 = F_115 ( V_87 , V_93 , V_115 , V_221 ,
V_114 -> V_119 ,
F_49 ( V_114 ) ) ;
if ( V_6 == - V_220 )
V_6 = F_108 ( V_87 , V_93 , V_115 ,
V_221 ,
V_114 -> V_119 ) ;
goto V_191;
}
V_130 . V_93 = V_93 ;
V_130 . V_114 = V_114 ;
V_130 . V_131 = V_132 ;
V_130 . V_133 = V_223 ;
V_130 . V_134 = V_135 ;
V_130 . V_136 = V_115 ;
V_130 . V_19 = & V_19 ;
V_130 . V_137 = false ;
V_6 = F_54 ( V_87 , & V_130 , & V_127 , NULL ) ;
if ( V_6 )
goto V_191;
V_6 = F_116 ( V_87 , V_93 , V_19 . V_20 , V_221 ,
V_114 -> V_119 ) ;
if ( V_6 )
goto V_224;
F_117 ( * V_221 , '/' ) ;
V_224:
F_55 ( V_87 , V_93 , V_19 . V_20 ) ;
V_191:
if ( ! V_6 )
F_9 ( V_15 , L_28 , V_222 , * V_221 ) ;
return V_6 ;
}
static bool
F_118 ( T_8 V_127 )
{
return V_127 == V_79 ;
}
static unsigned int
F_119 ( struct V_166 * V_166 )
{
return F_83 ( V_166 -> V_186 ) -> V_99 ;
}
static bool
F_120 ( struct V_16 * V_173 )
{
return ! V_173 -> V_200 . V_225 && ! V_173 -> V_226 ;
}
