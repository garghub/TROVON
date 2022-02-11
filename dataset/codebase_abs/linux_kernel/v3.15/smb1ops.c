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
V_114 -> V_120 &
V_121 ) ;
if ( V_6 == - V_122 || V_6 == - V_54 )
V_6 = F_49 ( V_87 , V_93 , V_115 , V_116 ,
V_114 -> V_119 , V_114 -> V_120 &
V_121 ) ;
F_50 ( V_116 ) ;
return V_6 ;
}
static int
F_51 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_113 * V_114 , const char * V_115 ,
T_4 * V_123 , bool * V_124 , bool * V_125 )
{
int V_6 ;
* V_125 = false ;
V_6 = F_48 ( V_87 , V_93 , V_115 , V_123 , 0 ,
V_114 -> V_119 , V_114 -> V_120 &
V_121 ) ;
if ( ( V_6 == - V_122 ) || ( V_6 == - V_54 ) ) {
V_6 = F_49 ( V_87 , V_93 , V_115 , V_123 ,
V_114 -> V_119 ,
V_114 -> V_120 &
V_121 ) ;
* V_124 = true ;
}
if ( ! V_6 && ( F_52 ( V_123 -> V_126 ) & V_127 ) ) {
int V_128 ;
int V_129 = 0 ;
struct V_130 V_19 ;
struct V_131 V_132 ;
V_132 . V_93 = V_93 ;
V_132 . V_114 = V_114 ;
V_132 . V_133 = V_134 ;
V_132 . V_135 = 0 ;
V_132 . V_136 = V_137 ;
V_132 . V_138 = V_115 ;
V_132 . V_19 = & V_19 ;
V_132 . V_139 = false ;
V_128 = F_53 ( V_87 , & V_132 , & V_129 , NULL ) ;
if ( V_128 == - V_122 )
* V_125 = true ;
else
F_54 ( V_87 , V_93 , V_19 . V_20 ) ;
}
return V_6 ;
}
static int
F_55 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_113 * V_114 , const char * V_115 ,
T_5 * V_140 , T_4 * V_123 )
{
return F_56 ( V_87 , V_93 , V_115 , V_140 ,
V_114 -> V_119 ,
V_114 -> V_120 &
V_121 ) ;
}
static int
F_57 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_130 * V_19 , T_4 * V_123 )
{
return F_58 ( V_87 , V_93 , V_19 -> V_20 , V_123 ) ;
}
static void
F_59 ( struct V_92 * V_93 )
{
#ifdef F_60
F_61 ( & V_93 -> V_141 . V_142 . V_143 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_144 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_145 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_146 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_147 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_148 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_149 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_150 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_151 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_152 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_153 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_154 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_155 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_156 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_157 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_158 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_159 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_160 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_161 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_162 , 0 ) ;
F_61 ( & V_93 -> V_141 . V_142 . V_163 , 0 ) ;
#endif
}
static void
F_62 ( struct V_164 * V_165 , struct V_92 * V_93 )
{
#ifdef F_60
F_63 ( V_165 , L_16 ,
F_64 ( & V_93 -> V_141 . V_142 . V_146 ) ) ;
F_63 ( V_165 , L_17 ,
F_64 ( & V_93 -> V_141 . V_142 . V_144 ) ,
( long long ) ( V_93 -> V_166 ) ) ;
F_63 ( V_165 , L_18 ,
F_64 ( & V_93 -> V_141 . V_142 . V_143 ) ,
( long long ) ( V_93 -> V_167 ) ) ;
F_63 ( V_165 , L_19 ,
F_64 ( & V_93 -> V_141 . V_142 . V_145 ) ) ;
F_63 ( V_165 , L_20 ,
F_64 ( & V_93 -> V_141 . V_142 . V_161 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_159 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_160 ) ) ;
F_63 ( V_165 , L_21 ,
F_64 ( & V_93 -> V_141 . V_142 . V_147 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_150 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_151 ) ) ;
F_63 ( V_165 , L_22 ,
F_64 ( & V_93 -> V_141 . V_142 . V_148 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_149 ) ) ;
F_63 ( V_165 , L_23 ,
F_64 ( & V_93 -> V_141 . V_142 . V_152 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_153 ) ) ;
F_63 ( V_165 , L_24 ,
F_64 ( & V_93 -> V_141 . V_142 . V_154 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_155 ) ) ;
F_63 ( V_165 , L_25 ,
F_64 ( & V_93 -> V_141 . V_142 . V_156 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_157 ) ,
F_64 ( & V_93 -> V_141 . V_142 . V_158 ) ) ;
#endif
}
static void
F_65 ( struct V_168 * V_168 , const char * V_115 ,
struct V_113 * V_114 , struct V_92 * V_93 ,
const unsigned int V_87 )
{
T_6 V_169 ;
struct V_76 * V_170 ;
T_7 V_171 ;
int V_6 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_170 = F_66 ( V_168 ) ;
V_171 = V_170 -> V_172 | V_173 ;
V_169 . V_126 = F_67 ( V_171 ) ;
V_6 = F_68 ( V_87 , V_93 , V_115 , & V_169 , V_114 -> V_119 ,
V_114 -> V_120 &
V_121 ) ;
if ( V_6 == 0 )
V_170 -> V_172 = V_171 ;
}
static int
F_69 ( const unsigned int V_87 , struct V_131 * V_132 ,
T_8 * V_129 , T_4 * V_3 )
{
if ( ! ( V_132 -> V_93 -> V_89 -> V_104 & V_174 ) )
return F_70 ( V_87 , V_132 -> V_93 , V_132 -> V_138 ,
V_132 -> V_136 ,
V_132 -> V_133 ,
V_132 -> V_135 ,
& V_132 -> V_19 -> V_20 , V_129 , V_3 ,
V_132 -> V_114 -> V_119 ,
V_132 -> V_114 -> V_120
& V_121 ) ;
return F_53 ( V_87 , V_132 , V_129 , V_3 ) ;
}
static void
F_71 ( struct V_16 * V_175 , struct V_130 * V_19 , T_8 V_129 )
{
struct V_76 * V_77 = F_66 ( V_175 -> V_176 -> V_177 ) ;
V_175 -> V_19 . V_20 = V_19 -> V_20 ;
F_32 ( V_77 , V_129 ) ;
V_77 -> V_178 = F_72 ( V_77 ) ;
}
static void
F_73 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_130 * V_19 )
{
F_54 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_74 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_130 * V_19 )
{
return F_75 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_76 ( const unsigned int V_87 , struct V_16 * V_175 ,
struct V_179 * V_180 , unsigned int * V_166 ,
char * * V_3 , int * V_181 )
{
V_180 -> V_20 = V_175 -> V_19 . V_20 ;
return F_77 ( V_87 , V_180 , V_166 , V_3 , V_181 ) ;
}
static int
F_78 ( const unsigned int V_87 , struct V_16 * V_175 ,
struct V_179 * V_180 , unsigned int * V_182 ,
struct V_183 * V_184 , unsigned long V_185 )
{
V_180 -> V_20 = V_175 -> V_19 . V_20 ;
return F_79 ( V_87 , V_180 , V_182 , V_184 , V_185 ) ;
}
static int
F_80 ( struct V_168 * V_168 , const char * V_115 ,
T_6 * V_3 , const unsigned int V_87 )
{
int V_129 = 0 ;
int V_6 ;
T_8 V_186 ;
struct V_130 V_19 ;
struct V_131 V_132 ;
struct V_16 * V_187 ;
struct V_76 * V_77 = F_66 ( V_168 ) ;
struct V_113 * V_114 = F_81 ( V_168 -> V_188 ) ;
struct V_189 * V_190 = NULL ;
struct V_92 * V_93 ;
V_187 = F_82 ( V_77 , true ) ;
if ( V_187 ) {
V_19 . V_20 = V_187 -> V_19 . V_20 ;
V_186 = V_187 -> V_191 ;
V_93 = F_83 ( V_187 -> V_190 ) ;
goto V_192;
}
V_190 = F_84 ( V_114 ) ;
if ( F_85 ( V_190 ) ) {
V_6 = F_86 ( V_190 ) ;
V_190 = NULL ;
goto V_193;
}
V_93 = F_83 ( V_190 ) ;
V_6 = F_68 ( V_87 , V_93 , V_115 , V_3 , V_114 -> V_119 ,
V_114 -> V_120 &
V_121 ) ;
if ( V_6 == 0 ) {
V_77 -> V_172 = F_52 ( V_3 -> V_126 ) ;
goto V_193;
} else if ( V_6 != - V_122 && V_6 != - V_54 ) {
goto V_193;
}
V_132 . V_93 = V_93 ;
V_132 . V_114 = V_114 ;
V_132 . V_133 = V_194 | V_195 ;
V_132 . V_135 = V_196 ;
V_132 . V_136 = V_137 ;
V_132 . V_138 = V_115 ;
V_132 . V_19 = & V_19 ;
V_132 . V_139 = false ;
F_9 ( V_15 , L_26 ) ;
V_6 = F_53 ( V_87 , & V_132 , & V_129 , NULL ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_197 )
V_6 = - V_54 ;
goto V_193;
}
V_186 = V_198 -> V_199 ;
V_192:
V_6 = F_87 ( V_87 , V_93 , V_3 , V_19 . V_20 , V_186 ) ;
if ( ! V_6 )
V_77 -> V_172 = F_52 ( V_3 -> V_126 ) ;
if ( V_187 == NULL )
F_54 ( V_87 , V_93 , V_19 . V_20 ) ;
else
F_88 ( V_187 ) ;
V_193:
if ( V_190 != NULL )
F_89 ( V_190 ) ;
return V_6 ;
}
static int
F_90 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_16 * V_175 )
{
return F_91 ( V_87 , V_93 , V_175 -> V_19 . V_20 ) ;
}
static int
F_92 ( const unsigned int V_87 , struct V_92 * V_93 ,
const char * V_138 , struct V_113 * V_114 ,
struct V_130 * V_19 , T_3 V_200 ,
struct V_201 * V_202 )
{
return F_93 ( V_87 , V_93 , V_138 , V_114 ,
& V_19 -> V_20 , V_200 , V_202 , true ) ;
}
static int
F_94 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_130 * V_19 , T_3 V_200 ,
struct V_201 * V_202 )
{
return F_95 ( V_87 , V_93 , V_19 -> V_20 , V_200 , V_202 ) ;
}
static int
F_96 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_130 * V_19 )
{
return F_97 ( V_87 , V_93 , V_19 -> V_20 ) ;
}
static int
F_98 ( struct V_92 * V_93 , struct V_130 * V_19 ,
struct V_76 * V_77 )
{
return F_99 ( 0 , V_93 , V_19 -> V_20 , V_198 -> V_199 , 0 , 0 , 0 , 0 ,
V_203 , false ,
F_100 ( V_77 ) ? 1 : 0 ) ;
}
static int
F_101 ( const unsigned int V_87 , struct V_92 * V_93 ,
struct V_204 * V_3 )
{
int V_6 = - V_122 ;
V_3 -> V_205 = V_206 ;
if ( ( V_93 -> V_89 -> V_104 & V_106 ) &&
( V_207 & F_40 ( V_93 -> V_97 . V_98 ) ) )
V_6 = F_102 ( V_87 , V_93 , V_3 ) ;
if ( V_6 && ( V_93 -> V_89 -> V_104 & V_174 ) )
V_6 = F_103 ( V_87 , V_93 , V_3 ) ;
if ( V_6 )
V_6 = F_104 ( V_87 , V_93 , V_3 ) ;
return V_6 ;
}
static int
F_105 ( const unsigned int V_87 , struct V_16 * V_175 , T_2 V_208 ,
T_2 V_209 , T_8 type , int V_210 , int V_211 , bool V_212 )
{
return F_99 ( V_87 , F_83 ( V_175 -> V_190 ) , V_175 -> V_19 . V_20 ,
V_198 -> V_199 , V_209 , V_208 , V_211 , V_210 ,
( V_213 ) type , V_212 , 0 ) ;
}
static int
F_106 ( const unsigned int V_87 , struct V_92 * V_93 ,
const unsigned char * V_214 , char * * V_215 ,
const struct V_216 * V_217 )
{
#ifdef F_107
int V_6 ;
unsigned int V_218 = 0 ;
struct V_219 * V_220 = NULL ;
V_6 = F_108 ( V_87 , V_93 -> V_89 , V_214 , V_217 ,
& V_218 , & V_220 , 0 ) ;
if ( ! V_6 && V_218 > 0 ) {
* V_215 = F_109 ( V_220 -> V_221 ,
strlen ( V_220 -> V_221 ) ,
V_117 ) ;
if ( ! * V_215 )
V_6 = - V_118 ;
F_110 ( V_220 , V_218 ) ;
}
return V_6 ;
#else
return - V_222 ;
#endif
}
static int
F_111 ( const unsigned int V_87 , struct V_92 * V_93 ,
const char * V_115 , char * * V_223 ,
struct V_113 * V_114 )
{
int V_6 ;
int V_129 = 0 ;
struct V_130 V_19 ;
struct V_131 V_132 ;
F_9 ( V_15 , L_27 , V_224 , V_115 ) ;
if ( F_112 ( V_93 -> V_89 ) ) {
V_6 = F_113 ( V_87 , V_93 , V_115 , V_223 ,
V_114 -> V_119 ) ;
if ( V_6 == - V_222 )
V_6 = F_106 ( V_87 , V_93 , V_115 ,
V_223 ,
V_114 -> V_119 ) ;
goto V_193;
}
V_132 . V_93 = V_93 ;
V_132 . V_114 = V_114 ;
V_132 . V_133 = V_134 ;
V_132 . V_135 = V_225 ;
V_132 . V_136 = V_137 ;
V_132 . V_138 = V_115 ;
V_132 . V_19 = & V_19 ;
V_132 . V_139 = false ;
V_6 = F_53 ( V_87 , & V_132 , & V_129 , NULL ) ;
if ( V_6 )
goto V_193;
V_6 = F_114 ( V_87 , V_93 , V_19 . V_20 , V_223 ,
V_114 -> V_119 ) ;
if ( V_6 )
goto V_226;
F_115 ( * V_223 , '/' ) ;
V_226:
F_54 ( V_87 , V_93 , V_19 . V_20 ) ;
V_193:
if ( ! V_6 )
F_9 ( V_15 , L_28 , V_224 , * V_223 ) ;
return V_6 ;
}
static bool
F_116 ( T_8 V_129 )
{
return V_129 == V_79 ;
}
