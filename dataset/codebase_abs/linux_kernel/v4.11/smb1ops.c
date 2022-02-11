static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 [ 0 ] . V_11 ;
V_9 -> V_12 = F_2 ( sizeof( struct V_8 ) - 4 + 2 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_15 = 0 ;
F_3 ( 0 , V_9 ) ;
F_4 ( & V_2 -> V_16 ) ;
V_7 = F_5 ( V_9 , V_2 , & V_6 -> V_17 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_16 ) ;
return V_7 ;
}
-- V_2 -> V_17 ;
V_7 = F_7 ( V_2 , V_9 , F_8 ( V_9 -> V_12 ) ) ;
if ( V_7 < 0 )
V_2 -> V_17 -- ;
F_6 ( & V_2 -> V_16 ) ;
F_9 ( V_18 , L_1 ,
F_10 ( V_9 ) , V_7 ) ;
return V_7 ;
}
static bool
F_11 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
return V_20 -> V_22 . V_23 == V_21 -> V_22 . V_23 ;
}
static unsigned int
F_12 ( char * V_24 )
{
T_1 * V_25 = ( T_1 * ) V_24 ;
return F_13 ( V_25 -> V_26 ) ;
}
static unsigned int
F_14 ( char * V_24 )
{
T_1 * V_25 = ( T_1 * ) V_24 ;
return ( F_13 ( V_25 -> V_27 ) << 16 ) +
F_13 ( V_25 -> V_28 ) ;
}
static struct V_5 *
F_15 ( struct V_1 * V_2 , char * V_29 )
{
struct V_8 * V_24 = (struct V_8 * ) V_29 ;
struct V_5 * V_6 ;
F_16 ( & V_30 ) ;
F_17 (mid, &server->pending_mid_q, qhead) {
if ( F_18 ( V_6 -> V_6 , V_24 ) &&
V_6 -> V_31 == V_32 &&
F_13 ( V_6 -> V_33 ) == V_24 -> V_13 ) {
F_19 ( & V_30 ) ;
return V_6 ;
}
}
F_19 ( & V_30 ) ;
return NULL ;
}
static void
F_20 ( struct V_1 * V_2 , const unsigned int V_34 ,
const int V_35 )
{
F_16 ( & V_2 -> V_36 ) ;
V_2 -> V_37 += V_34 ;
V_2 -> V_38 -- ;
F_19 ( & V_2 -> V_36 ) ;
F_21 ( & V_2 -> V_39 ) ;
}
static void
F_22 ( struct V_1 * V_2 , const int V_40 )
{
F_16 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = V_40 ;
V_2 -> V_41 = V_40 > 1 ? V_42 : false ;
F_19 ( & V_2 -> V_36 ) ;
}
static int *
F_23 ( struct V_1 * V_2 , const int V_35 )
{
return & V_2 -> V_37 ;
}
static unsigned int
F_24 ( struct V_5 * V_6 )
{
return 1 ;
}
static T_2
F_25 ( struct V_1 * V_2 )
{
T_2 V_6 = 0 ;
T_3 V_43 , V_44 ;
bool V_45 ;
F_16 ( & V_30 ) ;
V_44 = ( T_3 ) ( ( V_2 -> V_46 ) & 0xffff ) ;
V_43 = V_44 ;
V_44 ++ ;
while ( V_44 != V_43 ) {
struct V_5 * V_47 ;
unsigned int V_48 ;
V_45 = false ;
if ( V_44 == 0 )
V_44 ++ ;
V_48 = 0 ;
F_17 (mid_entry, &server->pending_mid_q, qhead) {
++ V_48 ;
if ( V_47 -> V_6 == V_44 &&
V_47 -> V_31 == V_32 ) {
V_45 = true ;
break;
}
}
if ( V_48 > 32768 )
V_2 -> V_49 = V_50 ;
if ( ! V_45 ) {
V_6 = ( T_2 ) V_44 ;
V_2 -> V_46 = V_6 ;
break;
}
V_44 ++ ;
}
F_19 ( & V_30 ) ;
return V_6 ;
}
static int
F_26 ( char * V_24 )
{
struct V_8 * V_51 = (struct V_8 * ) V_24 ;
struct V_52 * V_53 ;
int V_54 ;
T_3 V_55 , V_56 ;
if ( V_51 -> V_13 != V_57 )
return 0 ;
if ( V_51 -> V_15 != 10 ) {
F_9 ( V_18 , L_2 ) ;
return - V_58 ;
}
V_53 = (struct V_52 * ) V_51 ;
V_55 = F_27 ( & V_53 -> V_59 . V_60 ) ;
V_56 = F_27 ( & V_53 -> V_59 . V_61 ) ;
if ( V_55 == V_56 )
return 0 ;
else if ( V_55 < V_56 ) {
F_9 ( V_18 , L_3 ,
V_55 , V_56 ) ;
return - V_58 ;
}
V_54 = V_55 - V_56 ;
F_9 ( V_18 , L_4 ,
V_54 ) ;
if ( V_55 > V_62 ) {
F_9 ( V_63 , L_5 ,
V_55 , V_62 ) ;
return - V_58 ;
}
return V_54 ;
}
static int
F_28 ( char * V_64 , struct V_8 * V_65 )
{
struct V_52 * V_66 = (struct V_52 * ) V_64 ;
struct V_52 * V_53 = (struct V_52 * ) V_65 ;
char * V_67 ;
char * V_68 ;
int V_54 ;
unsigned int V_69 , V_70 ;
T_3 V_71 , V_72 , V_73 ;
V_72 = F_27 ( & V_66 -> V_59 . V_60 ) ;
V_71 = F_27 ( & V_53 -> V_59 . V_60 ) ;
if ( V_71 != V_72 )
F_9 ( V_18 , L_6 ,
V_72 , V_71 ) ;
V_70 = F_27 ( & V_53 -> V_59 . V_61 ) ;
V_54 = V_71 - V_70 ;
if ( V_54 < 0 ) {
F_9 ( V_18 , L_7 ,
V_71 , V_70 ) ;
return - V_74 ;
}
if ( V_54 == 0 ) {
F_9 ( V_18 , L_8 ) ;
return 0 ;
}
V_73 = F_27 ( & V_66 -> V_59 . V_61 ) ;
if ( V_54 < V_73 )
F_9 ( V_18 , L_9 ) ;
V_67 = ( char * ) & V_53 -> V_75 . V_76 +
F_27 ( & V_53 -> V_59 . V_26 ) ;
V_68 = ( char * ) & V_66 -> V_75 . V_76 +
F_27 ( & V_66 -> V_59 . V_26 ) ;
V_67 += V_70 ;
V_70 += V_73 ;
if ( V_70 > V_77 ) {
F_9 ( V_18 , L_10 ,
V_70 ) ;
return - V_74 ;
}
F_29 ( V_70 , & V_53 -> V_59 . V_61 ) ;
V_69 = F_30 ( V_65 ) ;
V_69 += V_73 ;
if ( V_69 > V_77 ) {
F_9 ( V_18 , L_11 , V_69 ) ;
return - V_74 ;
}
F_3 ( V_69 , V_65 ) ;
V_69 = F_8 ( V_65 -> V_12 ) ;
V_69 += V_73 ;
if ( V_69 > V_62 + V_78 - 4 ) {
F_9 ( V_18 , L_12 ,
V_69 ) ;
return - V_79 ;
}
V_65 -> V_12 = F_2 ( V_69 ) ;
memcpy ( V_67 , V_68 , V_73 ) ;
if ( V_54 != V_73 ) {
F_9 ( V_18 , L_13 ) ;
return 1 ;
}
F_9 ( V_18 , L_14 ) ;
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 ,
struct V_80 * V_81 , bool V_82 )
{
if ( V_82 )
F_32 ( V_81 , V_83 ) ;
else
F_32 ( V_81 , 0 ) ;
}
static bool
F_33 ( struct V_5 * V_6 , struct V_1 * V_2 ,
char * V_24 , int V_84 )
{
if ( V_84 )
return false ;
if ( F_26 ( V_24 ) <= 0 )
return false ;
V_6 -> V_85 = true ;
if ( V_6 -> V_86 ) {
V_84 = F_28 ( V_24 , V_6 -> V_86 ) ;
if ( V_84 > 0 )
return true ;
V_6 -> V_87 = true ;
F_34 ( V_6 , V_84 ) ;
return true ;
}
if ( ! V_2 -> V_88 ) {
F_9 ( V_63 , L_15 ) ;
} else {
V_6 -> V_86 = V_24 ;
V_6 -> V_88 = true ;
V_2 -> V_89 = NULL ;
}
return true ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_90 == 0 ;
}
static int
F_36 ( const unsigned int V_91 , struct V_92 * V_93 )
{
int V_7 ;
V_7 = F_37 ( V_91 , V_93 ) ;
if ( V_7 == - V_94 ) {
F_38 ( V_93 -> V_2 , 1 ) ;
V_7 = F_37 ( V_91 , V_93 ) ;
if ( V_7 == - V_94 )
V_7 = - V_95 ;
}
return V_7 ;
}
static unsigned int
F_39 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
T_2 V_100 = F_40 ( V_97 -> V_101 . V_102 ) ;
struct V_1 * V_2 = V_97 -> V_93 -> V_2 ;
unsigned int V_103 ;
if ( V_99 -> V_103 )
V_103 = V_99 -> V_103 ;
else if ( V_97 -> V_104 && ( V_100 & V_105 ) )
V_103 = V_106 ;
else
V_103 = V_107 ;
if ( ! V_97 -> V_104 || ! ( V_100 & V_105 ) )
V_103 = F_41 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_108 & V_109 ) ||
( ! ( V_2 -> V_108 & V_110 ) && V_2 -> V_111 ) )
V_103 = F_41 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_103 = F_41 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_103 ;
}
static unsigned int
F_42 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
T_2 V_100 = F_40 ( V_97 -> V_101 . V_102 ) ;
struct V_1 * V_2 = V_97 -> V_93 -> V_2 ;
unsigned int V_112 , V_113 ;
if ( V_97 -> V_104 && ( V_100 & V_114 ) )
V_113 = V_106 ;
else if ( V_2 -> V_108 & V_115 )
V_113 = V_116 ;
else
V_113 = V_2 -> V_90 - sizeof( T_1 ) ;
V_112 = V_99 -> V_112 ? V_99 -> V_112 : V_113 ;
if ( ! ( V_2 -> V_108 & V_115 ) )
V_112 = F_41 (unsigned int, CIFSMaxBufSize, rsize) ;
V_112 = F_41 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_112 ;
}
static void
F_43 ( const unsigned int V_91 , struct V_96 * V_97 )
{
F_44 ( V_91 , V_97 ) ;
F_45 ( V_91 , V_97 ) ;
}
static int
F_46 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_117 * V_118 , const char * V_119 )
{
int V_7 ;
T_4 * V_120 ;
V_120 = F_47 ( sizeof( T_4 ) , V_121 ) ;
if ( V_120 == NULL )
return - V_122 ;
V_7 = F_48 ( V_91 , V_97 , V_119 , V_120 ,
0 , V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
if ( V_7 == - V_124 || V_7 == - V_58 )
V_7 = F_50 ( V_91 , V_97 , V_119 , V_120 ,
V_118 -> V_123 , F_49 ( V_118 ) ) ;
F_51 ( V_120 ) ;
return V_7 ;
}
static int
F_52 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_117 * V_118 , const char * V_119 ,
T_4 * V_125 , bool * V_126 , bool * V_127 )
{
int V_7 ;
* V_127 = false ;
V_7 = F_48 ( V_91 , V_97 , V_119 , V_125 , 0 ,
V_118 -> V_123 , F_49 ( V_118 ) ) ;
if ( ( V_7 == - V_124 ) || ( V_7 == - V_58 ) ) {
V_7 = F_50 ( V_91 , V_97 , V_119 , V_125 ,
V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
* V_126 = true ;
}
if ( ! V_7 && ( F_53 ( V_125 -> V_128 ) & V_129 ) ) {
int V_130 ;
int V_131 = 0 ;
struct V_132 V_22 ;
struct V_133 V_134 ;
V_134 . V_97 = V_97 ;
V_134 . V_118 = V_118 ;
V_134 . V_135 = V_136 ;
V_134 . V_137 = 0 ;
V_134 . V_138 = V_139 ;
V_134 . V_140 = V_119 ;
V_134 . V_22 = & V_22 ;
V_134 . V_141 = false ;
V_130 = F_54 ( V_91 , & V_134 , & V_131 , NULL ) ;
if ( V_130 == - V_124 )
* V_127 = true ;
else if ( V_130 == 0 )
F_55 ( V_91 , V_97 , V_22 . V_23 ) ;
}
return V_7 ;
}
static int
F_56 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_117 * V_118 , const char * V_119 ,
T_5 * V_142 , T_4 * V_125 )
{
return F_57 ( V_91 , V_97 , V_119 , V_142 ,
V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
}
static int
F_58 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_132 * V_22 , T_4 * V_125 )
{
return F_59 ( V_91 , V_97 , V_22 -> V_23 , V_125 ) ;
}
static void
F_60 ( struct V_96 * V_97 )
{
#ifdef F_61
F_62 ( & V_97 -> V_143 . V_144 . V_145 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_146 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_147 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_148 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_149 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_150 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_151 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_152 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_153 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_154 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_155 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_156 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_157 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_158 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_159 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_160 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_161 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_162 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_163 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_164 , 0 ) ;
F_62 ( & V_97 -> V_143 . V_144 . V_165 , 0 ) ;
#endif
}
static void
F_63 ( struct V_166 * V_167 , struct V_96 * V_97 )
{
#ifdef F_61
F_64 ( V_167 , L_16 ,
F_65 ( & V_97 -> V_143 . V_144 . V_148 ) ) ;
F_64 ( V_167 , L_17 ,
F_65 ( & V_97 -> V_143 . V_144 . V_146 ) ,
( long long ) ( V_97 -> V_168 ) ) ;
F_64 ( V_167 , L_18 ,
F_65 ( & V_97 -> V_143 . V_144 . V_145 ) ,
( long long ) ( V_97 -> V_169 ) ) ;
F_64 ( V_167 , L_19 ,
F_65 ( & V_97 -> V_143 . V_144 . V_147 ) ) ;
F_64 ( V_167 , L_20 ,
F_65 ( & V_97 -> V_143 . V_144 . V_163 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_161 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_162 ) ) ;
F_64 ( V_167 , L_21 ,
F_65 ( & V_97 -> V_143 . V_144 . V_149 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_152 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_153 ) ) ;
F_64 ( V_167 , L_22 ,
F_65 ( & V_97 -> V_143 . V_144 . V_150 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_151 ) ) ;
F_64 ( V_167 , L_23 ,
F_65 ( & V_97 -> V_143 . V_144 . V_154 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_155 ) ) ;
F_64 ( V_167 , L_24 ,
F_65 ( & V_97 -> V_143 . V_144 . V_156 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_157 ) ) ;
F_64 ( V_167 , L_25 ,
F_65 ( & V_97 -> V_143 . V_144 . V_158 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_159 ) ,
F_65 ( & V_97 -> V_143 . V_144 . V_160 ) ) ;
#endif
}
static void
F_66 ( struct V_170 * V_170 , const char * V_119 ,
struct V_117 * V_118 , struct V_96 * V_97 ,
const unsigned int V_91 )
{
T_6 V_171 ;
struct V_80 * V_172 ;
T_7 V_173 ;
int V_7 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_172 = F_67 ( V_170 ) ;
V_173 = V_172 -> V_174 | V_175 ;
V_171 . V_128 = F_68 ( V_173 ) ;
V_7 = F_69 ( V_91 , V_97 , V_119 , & V_171 , V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
if ( V_7 == 0 )
V_172 -> V_174 = V_173 ;
}
static int
F_70 ( const unsigned int V_91 , struct V_133 * V_134 ,
T_8 * V_131 , T_4 * V_24 )
{
if ( ! ( V_134 -> V_97 -> V_93 -> V_108 & V_176 ) )
return F_71 ( V_91 , V_134 -> V_97 , V_134 -> V_140 ,
V_134 -> V_138 ,
V_134 -> V_135 ,
V_134 -> V_137 ,
& V_134 -> V_22 -> V_23 , V_131 , V_24 ,
V_134 -> V_118 -> V_123 ,
F_49 ( V_134 -> V_118 ) ) ;
return F_54 ( V_91 , V_134 , V_131 , V_24 ) ;
}
static void
F_72 ( struct V_19 * V_177 , struct V_132 * V_22 , T_8 V_131 )
{
struct V_80 * V_81 = F_67 ( F_73 ( V_177 -> V_178 ) ) ;
V_177 -> V_22 . V_23 = V_22 -> V_23 ;
F_32 ( V_81 , V_131 ) ;
V_81 -> V_179 = F_74 ( V_81 ) ;
}
static void
F_75 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_132 * V_22 )
{
F_55 ( V_91 , V_97 , V_22 -> V_23 ) ;
}
static int
F_76 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_132 * V_22 )
{
return F_77 ( V_91 , V_97 , V_22 -> V_23 ) ;
}
static int
F_78 ( const unsigned int V_91 , struct V_132 * V_180 ,
struct V_181 * V_182 , unsigned int * V_168 ,
char * * V_24 , int * V_183 )
{
V_182 -> V_23 = V_180 -> V_23 ;
return F_79 ( V_91 , V_182 , V_168 , V_24 , V_183 ) ;
}
static int
F_80 ( const unsigned int V_91 , struct V_132 * V_180 ,
struct V_181 * V_182 , unsigned int * V_184 ,
struct V_185 * V_186 , unsigned long V_187 )
{
V_182 -> V_23 = V_180 -> V_23 ;
return F_81 ( V_91 , V_182 , V_184 , V_186 , V_187 ) ;
}
static int
F_82 ( struct V_170 * V_170 , const char * V_119 ,
T_6 * V_24 , const unsigned int V_91 )
{
int V_131 = 0 ;
int V_7 ;
T_8 V_188 ;
struct V_132 V_22 ;
struct V_133 V_134 ;
struct V_19 * V_189 ;
struct V_80 * V_81 = F_67 ( V_170 ) ;
struct V_117 * V_118 = F_83 ( V_170 -> V_190 ) ;
struct V_191 * V_192 = NULL ;
struct V_96 * V_97 ;
V_189 = F_84 ( V_81 , true ) ;
if ( V_189 ) {
V_22 . V_23 = V_189 -> V_22 . V_23 ;
V_188 = V_189 -> V_193 ;
V_97 = F_85 ( V_189 -> V_192 ) ;
goto V_194;
}
V_192 = F_86 ( V_118 ) ;
if ( F_87 ( V_192 ) ) {
V_7 = F_88 ( V_192 ) ;
V_192 = NULL ;
goto V_195;
}
V_97 = F_85 ( V_192 ) ;
V_7 = F_69 ( V_91 , V_97 , V_119 , V_24 , V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
if ( V_7 == 0 ) {
V_81 -> V_174 = F_53 ( V_24 -> V_128 ) ;
goto V_195;
} else if ( V_7 != - V_124 && V_7 != - V_58 ) {
goto V_195;
}
V_134 . V_97 = V_97 ;
V_134 . V_118 = V_118 ;
V_134 . V_135 = V_196 | V_197 ;
V_134 . V_137 = V_198 ;
V_134 . V_138 = V_139 ;
V_134 . V_140 = V_119 ;
V_134 . V_22 = & V_22 ;
V_134 . V_141 = false ;
F_9 ( V_18 , L_26 ) ;
V_7 = F_54 ( V_91 , & V_134 , & V_131 , NULL ) ;
if ( V_7 != 0 ) {
if ( V_7 == - V_199 )
V_7 = - V_58 ;
goto V_195;
}
V_188 = V_200 -> V_201 ;
V_194:
V_7 = F_89 ( V_91 , V_97 , V_24 , V_22 . V_23 , V_188 ) ;
if ( ! V_7 )
V_81 -> V_174 = F_53 ( V_24 -> V_128 ) ;
if ( V_189 == NULL )
F_55 ( V_91 , V_97 , V_22 . V_23 ) ;
else
F_90 ( V_189 ) ;
V_195:
if ( V_192 != NULL )
F_91 ( V_192 ) ;
return V_7 ;
}
static int
F_92 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_19 * V_177 )
{
return F_93 ( V_91 , V_97 , V_177 -> V_22 . V_23 ) ;
}
static int
F_94 ( const unsigned int V_91 , struct V_96 * V_97 ,
const char * V_140 , struct V_117 * V_118 ,
struct V_132 * V_22 , T_3 V_202 ,
struct V_203 * V_204 )
{
return F_95 ( V_91 , V_97 , V_140 , V_118 ,
& V_22 -> V_23 , V_202 , V_204 , true ) ;
}
static int
F_96 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_132 * V_22 , T_3 V_202 ,
struct V_203 * V_204 )
{
return F_97 ( V_91 , V_97 , V_22 -> V_23 , V_202 , V_204 ) ;
}
static int
F_98 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_132 * V_22 )
{
return F_99 ( V_91 , V_97 , V_22 -> V_23 ) ;
}
static int
F_100 ( struct V_96 * V_97 , struct V_132 * V_22 ,
struct V_80 * V_81 )
{
return F_101 ( 0 , V_97 , V_22 -> V_23 , V_200 -> V_201 , 0 , 0 , 0 , 0 ,
V_205 , false ,
F_102 ( V_81 ) ? 1 : 0 ) ;
}
static int
F_103 ( const unsigned int V_91 , struct V_96 * V_97 ,
struct V_206 * V_24 )
{
int V_7 = - V_124 ;
V_24 -> V_207 = V_208 ;
if ( ( V_97 -> V_93 -> V_108 & V_110 ) &&
( V_209 & F_40 ( V_97 -> V_101 . V_102 ) ) )
V_7 = F_104 ( V_91 , V_97 , V_24 ) ;
if ( V_7 && ( V_97 -> V_93 -> V_108 & V_176 ) )
V_7 = F_105 ( V_91 , V_97 , V_24 ) ;
if ( V_7 )
V_7 = F_106 ( V_91 , V_97 , V_24 ) ;
return V_7 ;
}
static int
F_107 ( const unsigned int V_91 , struct V_19 * V_177 , T_2 V_210 ,
T_2 V_211 , T_8 type , int V_212 , int V_213 , bool V_214 )
{
return F_101 ( V_91 , F_85 ( V_177 -> V_192 ) , V_177 -> V_22 . V_23 ,
V_200 -> V_201 , V_211 , V_210 , V_213 , V_212 ,
( V_215 ) type , V_214 , 0 ) ;
}
static int
F_108 ( const unsigned int V_91 , struct V_96 * V_97 ,
const unsigned char * V_216 , char * * V_217 ,
const struct V_218 * V_219 )
{
#ifdef F_109
int V_7 ;
unsigned int V_220 = 0 ;
struct V_221 * V_222 = NULL ;
V_7 = F_110 ( V_91 , V_97 -> V_93 , V_216 , V_219 ,
& V_220 , & V_222 , 0 ) ;
if ( ! V_7 && V_220 > 0 ) {
* V_217 = F_111 ( V_222 -> V_223 ,
strlen ( V_222 -> V_223 ) ,
V_121 ) ;
if ( ! * V_217 )
V_7 = - V_122 ;
F_112 ( V_222 , V_220 ) ;
}
return V_7 ;
#else
return - V_224 ;
#endif
}
static int
F_113 ( const unsigned int V_91 , struct V_96 * V_97 ,
const char * V_119 , char * * V_225 ,
struct V_117 * V_118 )
{
int V_7 ;
int V_131 = 0 ;
struct V_132 V_22 ;
struct V_133 V_134 ;
F_9 ( V_18 , L_27 , V_226 , V_119 ) ;
if ( F_114 ( V_97 -> V_93 ) ) {
V_7 = F_115 ( V_91 , V_97 , V_119 , V_225 ,
V_118 -> V_123 ,
F_49 ( V_118 ) ) ;
if ( V_7 == - V_224 )
V_7 = F_108 ( V_91 , V_97 , V_119 ,
V_225 ,
V_118 -> V_123 ) ;
goto V_195;
}
V_134 . V_97 = V_97 ;
V_134 . V_118 = V_118 ;
V_134 . V_135 = V_136 ;
V_134 . V_137 = V_227 ;
V_134 . V_138 = V_139 ;
V_134 . V_140 = V_119 ;
V_134 . V_22 = & V_22 ;
V_134 . V_141 = false ;
V_7 = F_54 ( V_91 , & V_134 , & V_131 , NULL ) ;
if ( V_7 )
goto V_195;
V_7 = F_116 ( V_91 , V_97 , V_22 . V_23 , V_225 ,
V_118 -> V_123 ) ;
if ( V_7 )
goto V_228;
F_117 ( * V_225 , '/' ) ;
V_228:
F_55 ( V_91 , V_97 , V_22 . V_23 ) ;
V_195:
if ( ! V_7 )
F_9 ( V_18 , L_28 , V_226 , * V_225 ) ;
return V_7 ;
}
static bool
F_118 ( T_8 V_131 )
{
return V_131 == V_83 ;
}
static unsigned int
F_119 ( struct V_170 * V_170 )
{
return F_83 ( V_170 -> V_190 ) -> V_103 ;
}
static bool
F_120 ( struct V_19 * V_177 )
{
return ! V_177 -> V_204 . V_229 && ! V_177 -> V_230 ;
}
static bool
F_121 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 == V_231 )
return true ;
return false ;
}
