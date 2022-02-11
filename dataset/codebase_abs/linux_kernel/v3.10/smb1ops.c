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
V_8 -> V_16 , V_6 ) ;
return V_6 ;
}
static bool
F_10 ( struct V_17 * V_18 , struct V_17 * V_19 )
{
return V_18 -> V_20 . V_21 == V_19 -> V_20 . V_21 ;
}
static unsigned int
F_11 ( char * V_3 )
{
T_1 * V_22 = ( T_1 * ) V_3 ;
return F_12 ( V_22 -> V_23 ) ;
}
static unsigned int
F_13 ( char * V_3 )
{
T_1 * V_22 = ( T_1 * ) V_3 ;
return ( F_12 ( V_22 -> V_24 ) << 16 ) +
F_12 ( V_22 -> V_25 ) ;
}
static struct V_4 *
F_14 ( struct V_1 * V_2 , char * V_26 )
{
struct V_7 * V_3 = (struct V_7 * ) V_26 ;
struct V_4 * V_5 ;
F_15 ( & V_27 ) ;
F_16 (mid, &server->pending_mid_q, qhead) {
if ( V_5 -> V_5 == V_3 -> V_16 &&
V_5 -> V_28 == V_29 &&
F_12 ( V_5 -> V_30 ) == V_3 -> V_10 ) {
F_17 ( & V_27 ) ;
return V_5 ;
}
}
F_17 ( & V_27 ) ;
return NULL ;
}
static void
F_18 ( struct V_1 * V_2 , const unsigned int V_31 ,
const int V_32 )
{
F_15 ( & V_2 -> V_33 ) ;
V_2 -> V_34 += V_31 ;
V_2 -> V_35 -- ;
F_17 ( & V_2 -> V_33 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
static void
F_20 ( struct V_1 * V_2 , const int V_37 )
{
F_15 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = V_37 ;
V_2 -> V_38 = V_37 > 1 ? V_39 : false ;
F_17 ( & V_2 -> V_33 ) ;
}
static int *
F_21 ( struct V_1 * V_2 , const int V_32 )
{
return & V_2 -> V_34 ;
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
T_3 V_40 , V_41 ;
bool V_42 ;
F_15 ( & V_27 ) ;
V_41 = ( T_3 ) ( ( V_2 -> V_43 ) & 0xffff ) ;
V_40 = V_41 ;
V_41 ++ ;
while ( V_41 != V_40 ) {
struct V_4 * V_44 ;
unsigned int V_45 ;
V_42 = false ;
if ( V_41 == 0 )
V_41 ++ ;
V_45 = 0 ;
F_16 (mid_entry, &server->pending_mid_q, qhead) {
++ V_45 ;
if ( V_44 -> V_5 == V_41 &&
V_44 -> V_28 == V_29 ) {
V_42 = true ;
break;
}
}
if ( V_45 > 32768 )
V_2 -> V_46 = V_47 ;
if ( ! V_42 ) {
V_5 = ( T_2 ) V_41 ;
V_2 -> V_43 = V_5 ;
break;
}
V_41 ++ ;
}
F_17 ( & V_27 ) ;
return V_5 ;
}
static int
F_24 ( char * V_3 )
{
struct V_7 * V_48 = (struct V_7 * ) V_3 ;
struct V_49 * V_50 ;
int V_51 ;
T_3 V_52 , V_53 ;
if ( V_48 -> V_10 != V_54 )
return 0 ;
if ( V_48 -> V_12 != 10 ) {
F_9 ( V_15 , L_2 ) ;
return - V_55 ;
}
V_50 = (struct V_49 * ) V_48 ;
V_52 = F_25 ( & V_50 -> V_56 . V_57 ) ;
V_53 = F_25 ( & V_50 -> V_56 . V_58 ) ;
if ( V_52 == V_53 )
return 0 ;
else if ( V_52 < V_53 ) {
F_9 ( V_15 , L_3 ,
V_52 , V_53 ) ;
return - V_55 ;
}
V_51 = V_52 - V_53 ;
F_9 ( V_15 , L_4 ,
V_51 ) ;
if ( V_52 > V_59 ) {
F_9 ( V_60 , L_5 ,
V_52 , V_59 ) ;
return - V_55 ;
}
return V_51 ;
}
static int
F_26 ( char * V_61 , struct V_7 * V_62 )
{
struct V_49 * V_63 = (struct V_49 * ) V_61 ;
struct V_49 * V_50 = (struct V_49 * ) V_62 ;
char * V_64 ;
char * V_65 ;
int V_51 ;
unsigned int V_66 , V_67 ;
T_3 V_68 , V_69 , V_70 ;
V_69 = F_25 ( & V_63 -> V_56 . V_57 ) ;
V_68 = F_25 ( & V_50 -> V_56 . V_57 ) ;
if ( V_68 != V_69 )
F_9 ( V_15 , L_6 ,
V_69 , V_68 ) ;
V_67 = F_25 ( & V_50 -> V_56 . V_58 ) ;
V_51 = V_68 - V_67 ;
if ( V_51 < 0 ) {
F_9 ( V_15 , L_7 ,
V_68 , V_67 ) ;
return - V_71 ;
}
if ( V_51 == 0 ) {
F_9 ( V_15 , L_8 ) ;
return 0 ;
}
V_70 = F_25 ( & V_63 -> V_56 . V_58 ) ;
if ( V_51 < V_70 )
F_9 ( V_15 , L_9 ) ;
V_64 = ( char * ) & V_50 -> V_72 . V_73 +
F_25 ( & V_50 -> V_56 . V_23 ) ;
V_65 = ( char * ) & V_63 -> V_72 . V_73 +
F_25 ( & V_63 -> V_56 . V_23 ) ;
V_64 += V_67 ;
V_67 += V_70 ;
if ( V_67 > V_74 ) {
F_9 ( V_15 , L_10 ,
V_67 ) ;
return - V_71 ;
}
F_27 ( V_67 , & V_50 -> V_56 . V_58 ) ;
V_66 = F_28 ( V_62 ) ;
V_66 += V_70 ;
if ( V_66 > V_74 ) {
F_9 ( V_15 , L_11 , V_66 ) ;
return - V_71 ;
}
F_3 ( V_66 , V_62 ) ;
V_66 = F_8 ( V_62 -> V_9 ) ;
V_66 += V_70 ;
if ( V_66 > V_59 + V_75 - 4 ) {
F_9 ( V_15 , L_12 ,
V_66 ) ;
return - V_76 ;
}
V_62 -> V_9 = F_2 ( V_66 ) ;
memcpy ( V_64 , V_65 , V_70 ) ;
if ( V_51 != V_70 ) {
F_9 ( V_15 , L_13 ) ;
return 1 ;
}
F_9 ( V_15 , L_14 ) ;
return 0 ;
}
static bool
F_29 ( struct V_4 * V_5 , struct V_1 * V_2 ,
char * V_3 , int V_77 )
{
if ( V_77 )
return false ;
if ( F_24 ( V_3 ) <= 0 )
return false ;
V_5 -> V_78 = true ;
if ( V_5 -> V_79 ) {
V_77 = F_26 ( V_3 , V_5 -> V_79 ) ;
if ( V_77 > 0 )
return true ;
V_5 -> V_80 = true ;
F_30 ( V_5 , V_77 ) ;
return true ;
}
if ( ! V_2 -> V_81 ) {
F_9 ( V_60 , L_15 ) ;
} else {
V_5 -> V_79 = V_3 ;
V_5 -> V_81 = true ;
V_2 -> V_82 = NULL ;
}
return true ;
}
static bool
F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_83 == 0 ;
}
static int
F_32 ( const unsigned int V_84 , struct V_85 * V_86 )
{
int V_6 ;
V_6 = F_33 ( V_84 , V_86 ) ;
if ( V_6 == - V_87 ) {
F_34 ( V_86 -> V_2 , 1 ) ;
V_6 = F_33 ( V_84 , V_86 ) ;
if ( V_6 == - V_87 )
V_6 = - V_88 ;
}
return V_6 ;
}
static unsigned int
F_35 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
T_2 V_93 = F_36 ( V_90 -> V_94 . V_95 ) ;
struct V_1 * V_2 = V_90 -> V_86 -> V_2 ;
unsigned int V_96 ;
if ( V_92 -> V_96 )
V_96 = V_92 -> V_96 ;
else if ( V_90 -> V_97 && ( V_93 & V_98 ) )
V_96 = V_99 ;
else
V_96 = V_100 ;
if ( ! V_90 -> V_97 || ! ( V_93 & V_98 ) )
V_96 = F_37 (unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE) ;
if ( ! ( V_2 -> V_101 & V_102 ) ||
( ! ( V_2 -> V_101 & V_103 ) &&
( V_2 -> V_104 & ( V_105 | V_106 ) ) ) )
V_96 = F_37 (unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4 ) ;
V_96 = F_37 (unsigned int, wsize, CIFS_MAX_WSIZE) ;
return V_96 ;
}
static unsigned int
F_38 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
T_2 V_93 = F_36 ( V_90 -> V_94 . V_95 ) ;
struct V_1 * V_2 = V_90 -> V_86 -> V_2 ;
unsigned int V_107 , V_108 ;
if ( V_90 -> V_97 && ( V_93 & V_109 ) )
V_108 = V_99 ;
else if ( V_2 -> V_101 & V_110 )
V_108 = V_111 ;
else
V_108 = V_2 -> V_83 - sizeof( T_1 ) ;
V_107 = V_92 -> V_107 ? V_92 -> V_107 : V_108 ;
if ( ! ( V_2 -> V_101 & V_110 ) )
V_107 = F_37 (unsigned int, CIFSMaxBufSize, rsize) ;
V_107 = F_37 (unsigned int, rsize, CIFS_MAX_RSIZE) ;
return V_107 ;
}
static void
F_39 ( const unsigned int V_84 , struct V_89 * V_90 )
{
F_40 ( V_84 , V_90 ) ;
F_41 ( V_84 , V_90 ) ;
}
static int
F_42 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_112 * V_113 , const char * V_114 )
{
int V_6 ;
T_4 * V_115 ;
V_115 = F_43 ( sizeof( T_4 ) , V_116 ) ;
if ( V_115 == NULL )
return - V_117 ;
V_6 = F_44 ( V_84 , V_90 , V_114 , V_115 ,
0 , V_113 -> V_118 ,
V_113 -> V_119 &
V_120 ) ;
if ( V_6 == - V_121 || V_6 == - V_55 )
V_6 = F_45 ( V_84 , V_90 , V_114 , V_115 ,
V_113 -> V_118 , V_113 -> V_119 &
V_120 ) ;
F_46 ( V_115 ) ;
return V_6 ;
}
static int
F_47 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_112 * V_113 , const char * V_114 ,
T_4 * V_122 , bool * V_123 )
{
int V_6 ;
V_6 = F_44 ( V_84 , V_90 , V_114 , V_122 , 0 ,
V_113 -> V_118 , V_113 -> V_119 &
V_120 ) ;
if ( ( V_6 == - V_121 ) || ( V_6 == - V_55 ) ) {
V_6 = F_45 ( V_84 , V_90 , V_114 , V_122 ,
V_113 -> V_118 ,
V_113 -> V_119 &
V_120 ) ;
* V_123 = true ;
}
return V_6 ;
}
static int
F_48 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_112 * V_113 , const char * V_114 ,
T_5 * V_124 , T_4 * V_122 )
{
return F_49 ( V_84 , V_90 , V_114 , V_124 ,
V_113 -> V_118 ,
V_113 -> V_119 &
V_120 ) ;
}
static int
F_50 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_125 * V_20 , T_4 * V_122 )
{
return F_51 ( V_84 , V_90 , V_20 -> V_21 , V_122 ) ;
}
static void
F_52 ( struct V_89 * V_90 )
{
#ifdef F_53
F_54 ( & V_90 -> V_126 . V_127 . V_128 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_129 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_130 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_131 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_132 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_133 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_134 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_135 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_136 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_137 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_138 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_139 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_140 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_141 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_142 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_143 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_144 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_145 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_146 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_147 , 0 ) ;
F_54 ( & V_90 -> V_126 . V_127 . V_148 , 0 ) ;
#endif
}
static void
F_55 ( struct V_149 * V_150 , struct V_89 * V_90 )
{
#ifdef F_53
F_56 ( V_150 , L_16 ,
F_57 ( & V_90 -> V_126 . V_127 . V_131 ) ) ;
F_56 ( V_150 , L_17 ,
F_57 ( & V_90 -> V_126 . V_127 . V_129 ) ,
( long long ) ( V_90 -> V_151 ) ) ;
F_56 ( V_150 , L_18 ,
F_57 ( & V_90 -> V_126 . V_127 . V_128 ) ,
( long long ) ( V_90 -> V_152 ) ) ;
F_56 ( V_150 , L_19 ,
F_57 ( & V_90 -> V_126 . V_127 . V_130 ) ) ;
F_56 ( V_150 , L_20 ,
F_57 ( & V_90 -> V_126 . V_127 . V_146 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_144 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_145 ) ) ;
F_56 ( V_150 , L_21 ,
F_57 ( & V_90 -> V_126 . V_127 . V_132 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_135 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_136 ) ) ;
F_56 ( V_150 , L_22 ,
F_57 ( & V_90 -> V_126 . V_127 . V_133 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_134 ) ) ;
F_56 ( V_150 , L_23 ,
F_57 ( & V_90 -> V_126 . V_127 . V_137 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_138 ) ) ;
F_56 ( V_150 , L_24 ,
F_57 ( & V_90 -> V_126 . V_127 . V_139 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_140 ) ) ;
F_56 ( V_150 , L_25 ,
F_57 ( & V_90 -> V_126 . V_127 . V_141 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_142 ) ,
F_57 ( & V_90 -> V_126 . V_127 . V_143 ) ) ;
#endif
}
static void
F_58 ( struct V_153 * V_153 , const char * V_114 ,
struct V_112 * V_113 , struct V_89 * V_90 ,
const unsigned int V_84 )
{
T_6 V_154 ;
struct V_155 * V_156 ;
T_7 V_157 ;
int V_6 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_156 = F_59 ( V_153 ) ;
V_157 = V_156 -> V_158 | V_159 ;
V_154 . V_160 = F_60 ( V_157 ) ;
V_6 = F_61 ( V_84 , V_90 , V_114 , & V_154 , V_113 -> V_118 ,
V_113 -> V_119 &
V_120 ) ;
if ( V_6 == 0 )
V_156 -> V_158 = V_157 ;
}
static int
F_62 ( const unsigned int V_84 , struct V_89 * V_90 , const char * V_161 ,
int V_162 , int V_163 , int V_164 ,
struct V_125 * V_20 , T_8 * V_165 , T_4 * V_3 ,
struct V_112 * V_113 )
{
if ( ! ( V_90 -> V_86 -> V_101 & V_166 ) )
return F_63 ( V_84 , V_90 , V_161 , V_162 ,
V_163 , V_164 ,
& V_20 -> V_21 , V_165 , V_3 ,
V_113 -> V_118 , V_113 -> V_119
& V_120 ) ;
return F_64 ( V_84 , V_90 , V_161 , V_162 , V_163 ,
V_164 , & V_20 -> V_21 , V_165 , V_3 ,
V_113 -> V_118 , V_113 -> V_119 &
V_120 ) ;
}
static void
F_65 ( struct V_17 * V_167 , struct V_125 * V_20 , T_8 V_165 )
{
struct V_155 * V_168 = F_59 ( V_167 -> V_169 -> V_170 ) ;
V_167 -> V_20 . V_21 = V_20 -> V_21 ;
F_66 ( V_168 , V_165 ) ;
V_168 -> V_171 = V_168 -> V_172 ;
}
static void
F_67 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_125 * V_20 )
{
F_68 ( V_84 , V_90 , V_20 -> V_21 ) ;
}
static int
F_69 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_125 * V_20 )
{
return F_70 ( V_84 , V_90 , V_20 -> V_21 ) ;
}
static int
F_71 ( const unsigned int V_84 , struct V_17 * V_167 ,
struct V_173 * V_174 , unsigned int * V_151 ,
char * * V_3 , int * V_175 )
{
V_174 -> V_21 = V_167 -> V_20 . V_21 ;
return F_72 ( V_84 , V_174 , V_151 , V_3 , V_175 ) ;
}
static int
F_73 ( const unsigned int V_84 , struct V_17 * V_167 ,
struct V_173 * V_174 , unsigned int * V_176 ,
struct V_177 * V_178 , unsigned long V_179 )
{
V_174 -> V_21 = V_167 -> V_20 . V_21 ;
return F_74 ( V_84 , V_174 , V_176 , V_178 , V_179 ) ;
}
static int
F_75 ( struct V_153 * V_153 , const char * V_114 ,
T_6 * V_3 , const unsigned int V_84 )
{
int V_165 = 0 ;
int V_6 ;
T_3 V_21 ;
T_8 V_180 ;
struct V_17 * V_181 ;
struct V_155 * V_168 = F_59 ( V_153 ) ;
struct V_112 * V_113 = F_76 ( V_153 -> V_182 ) ;
struct V_183 * V_184 = NULL ;
struct V_89 * V_90 ;
V_181 = F_77 ( V_168 , true ) ;
if ( V_181 ) {
V_21 = V_181 -> V_20 . V_21 ;
V_180 = V_181 -> V_185 ;
V_90 = F_78 ( V_181 -> V_184 ) ;
goto V_186;
}
V_184 = F_79 ( V_113 ) ;
if ( F_80 ( V_184 ) ) {
V_6 = F_81 ( V_184 ) ;
V_184 = NULL ;
goto V_187;
}
V_90 = F_78 ( V_184 ) ;
if ( ! ( V_90 -> V_86 -> V_188 & V_189 ) ) {
V_6 = F_61 ( V_84 , V_90 , V_114 , V_3 ,
V_113 -> V_118 ,
V_113 -> V_119 &
V_120 ) ;
if ( V_6 == 0 ) {
V_168 -> V_158 = F_82 ( V_3 -> V_160 ) ;
goto V_187;
} else if ( V_6 != - V_121 && V_6 != - V_55 )
goto V_187;
}
F_9 ( V_15 , L_26 ) ;
V_6 = F_64 ( V_84 , V_90 , V_114 , V_190 ,
V_191 | V_192 , V_193 ,
& V_21 , & V_165 , NULL , V_113 -> V_118 ,
V_113 -> V_119 & V_120 ) ;
if ( V_6 != 0 ) {
if ( V_6 == - V_194 )
V_6 = - V_55 ;
goto V_187;
}
V_180 = V_195 -> V_196 ;
V_186:
V_6 = F_83 ( V_84 , V_90 , V_3 , V_21 , V_180 ) ;
if ( ! V_6 )
V_168 -> V_158 = F_82 ( V_3 -> V_160 ) ;
if ( V_181 == NULL )
F_68 ( V_84 , V_90 , V_21 ) ;
else
F_84 ( V_181 ) ;
V_187:
if ( V_184 != NULL )
F_85 ( V_184 ) ;
return V_6 ;
}
static int
F_86 ( const unsigned int V_84 , struct V_89 * V_90 ,
const char * V_161 , struct V_112 * V_113 ,
struct V_125 * V_20 , T_3 V_197 ,
struct V_198 * V_199 )
{
return F_87 ( V_84 , V_90 , V_161 , V_113 ,
& V_20 -> V_21 , V_197 , V_199 , true ) ;
}
static int
F_88 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_125 * V_20 , T_3 V_197 ,
struct V_198 * V_199 )
{
return F_89 ( V_84 , V_90 , V_20 -> V_21 , V_197 , V_199 ) ;
}
static int
F_90 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_125 * V_20 )
{
return F_91 ( V_84 , V_90 , V_20 -> V_21 ) ;
}
static int
F_92 ( struct V_89 * V_90 , struct V_125 * V_20 ,
struct V_155 * V_168 )
{
return F_93 ( 0 , V_90 , V_20 -> V_21 , V_195 -> V_196 , 0 , 0 , 0 , 0 ,
V_200 , false ,
V_168 -> V_201 ? 1 : 0 ) ;
}
static int
F_94 ( const unsigned int V_84 , struct V_89 * V_90 ,
struct V_202 * V_3 )
{
int V_6 = - V_121 ;
V_3 -> V_203 = V_204 ;
if ( ( V_90 -> V_86 -> V_101 & V_103 ) &&
( V_205 & F_36 ( V_90 -> V_94 . V_95 ) ) )
V_6 = F_95 ( V_84 , V_90 , V_3 ) ;
if ( V_6 && ( V_90 -> V_86 -> V_101 & V_166 ) )
V_6 = F_96 ( V_84 , V_90 , V_3 ) ;
if ( V_6 )
V_6 = F_97 ( V_84 , V_90 , V_3 ) ;
return V_6 ;
}
static int
F_98 ( const unsigned int V_84 , struct V_17 * V_167 , T_2 V_206 ,
T_2 V_207 , T_8 type , int V_208 , int V_209 , bool V_210 )
{
return F_93 ( V_84 , F_78 ( V_167 -> V_184 ) , V_167 -> V_20 . V_21 ,
V_195 -> V_196 , V_207 , V_206 , V_209 , V_208 ,
( V_211 ) type , V_210 , 0 ) ;
}
