static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( V_8 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_2 ( V_9 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , const unsigned int V_10 ,
const int V_11 )
{
int * V_12 , V_13 = 0 ;
F_4 ( & V_2 -> V_14 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_11 ) ;
* V_12 += V_10 ;
V_2 -> V_17 -- ;
if ( V_2 -> V_17 == 0 && ( V_11 & V_18 ) != V_19 )
V_13 = F_1 ( V_2 ) ;
else if ( V_2 -> V_17 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_13 )
F_7 ( V_2 ) ;
}
static void
F_8 ( struct V_1 * V_2 , const int V_12 )
{
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 = V_12 ;
F_5 ( & V_2 -> V_14 ) ;
}
static int *
F_9 ( struct V_1 * V_2 , const int V_11 )
{
switch ( V_11 ) {
case V_21 :
return & V_2 -> V_4 ;
case V_22 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_10 ( struct V_23 * V_24 )
{
return F_11 ( ( (struct V_25 * ) V_24 -> V_26 ) -> V_27 ) ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int * V_29 , unsigned int * V_3 )
{
int V_13 = 0 ;
unsigned int V_30 ;
F_4 ( & V_2 -> V_14 ) ;
while ( 1 ) {
if ( V_2 -> V_3 <= 0 ) {
F_5 ( & V_2 -> V_14 ) ;
F_13 ( V_2 ) ;
V_13 = F_14 ( V_2 -> V_20 ,
F_15 ( V_2 , & V_2 -> V_3 ) ) ;
F_16 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_4 ( & V_2 -> V_14 ) ;
} else {
if ( V_2 -> V_31 == V_32 ) {
F_5 ( & V_2 -> V_14 ) ;
return - V_33 ;
}
V_30 = V_2 -> V_3 ;
if ( V_30 == 1 ) {
* V_29 = V_34 ;
* V_3 = 0 ;
break;
}
V_30 -- ;
* V_29 = F_17 (unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE) ;
* V_3 = F_18 ( * V_29 , V_34 ) ;
V_2 -> V_3 -= * V_3 ;
V_2 -> V_17 ++ ;
break;
}
}
F_5 ( & V_2 -> V_14 ) ;
return V_13 ;
}
static T_1
F_19 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_4 ( & V_35 ) ;
V_24 = V_2 -> V_36 ++ ;
F_5 ( & V_35 ) ;
return V_24 ;
}
static struct V_23 *
F_20 ( struct V_1 * V_2 , char * V_37 )
{
struct V_23 * V_24 ;
struct V_25 * V_38 = (struct V_25 * ) V_37 ;
T_1 V_39 = F_21 ( V_38 -> V_40 ) ;
F_4 ( & V_35 ) ;
F_22 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_39 ) &&
( V_24 -> V_41 == V_42 ) &&
( V_24 -> V_43 == V_38 -> V_44 ) ) {
F_5 ( & V_35 ) ;
return V_24 ;
}
}
F_5 ( & V_35 ) ;
return NULL ;
}
static void
F_23 ( void * V_37 )
{
#ifdef F_24
struct V_25 * V_45 = (struct V_25 * ) V_37 ;
F_2 ( V_8 , L_3 ,
V_45 -> V_44 , V_45 -> V_46 , V_45 -> V_47 , V_45 -> V_40 ,
V_45 -> V_48 ) ;
F_2 ( V_8 , L_4 , V_45 , F_25 ( V_45 ) ) ;
#endif
}
static bool
F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_49 == 0 ;
}
static int
F_27 ( const unsigned int V_50 , struct V_51 * V_52 )
{
int V_13 ;
V_52 -> V_2 -> V_36 = 0 ;
V_13 = F_28 ( V_50 , V_52 ) ;
if ( V_13 == - V_53 )
V_13 = - V_54 ;
return V_13 ;
}
static unsigned int
F_29 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_56 -> V_52 -> V_2 ;
unsigned int V_59 ;
V_59 = V_58 -> V_59 ? V_58 -> V_59 : V_60 ;
V_59 = F_17 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_61 & V_62 ) )
V_59 = F_17 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_59 ;
}
static unsigned int
F_30 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_56 -> V_52 -> V_2 ;
unsigned int V_63 ;
V_63 = V_58 -> V_63 ? V_58 -> V_63 : V_60 ;
V_63 = F_17 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_61 & V_62 ) )
V_63 = F_17 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_63 ;
}
static int
F_31 ( const unsigned int V_50 , struct V_55 * V_56 )
{
int V_13 ;
unsigned int V_64 = 0 ;
struct V_65 * V_66 ;
V_13 = F_32 ( V_50 , V_56 , V_67 , V_67 ,
V_68 , true ,
NULL , 0 ,
( char * * ) & V_66 , & V_64 ) ;
if ( V_13 != 0 )
F_2 ( V_8 , L_5 , V_13 ) ;
else if ( V_64 < sizeof( struct V_65 ) ) {
F_2 ( V_8 , L_6 ) ;
V_13 = - V_69 ;
} else {
F_2 ( V_9 , L_7 ,
F_33 ( V_66 -> V_70 ) ) ;
F_2 ( V_9 , L_8 ,
F_21 ( V_66 -> V_71 ) ) ;
}
return V_13 ;
}
static void
F_34 ( const unsigned int V_50 , struct V_55 * V_56 )
{
int V_13 ;
T_2 V_72 = 0 ;
T_3 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , & V_72 , & V_73 , NULL , NULL ) ;
if ( V_13 )
return;
#ifdef F_36
F_31 ( V_50 , V_56 ) ;
#endif
F_37 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_87 ) ;
F_37 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_88 ) ;
F_37 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_89 ) ;
F_38 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ) ;
return;
}
static void
F_39 ( const unsigned int V_50 , struct V_55 * V_56 )
{
int V_13 ;
T_2 V_72 = 0 ;
T_3 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , & V_72 , & V_73 , NULL , NULL ) ;
if ( V_13 )
return;
F_37 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_87 ) ;
F_37 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_88 ) ;
F_38 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ) ;
return;
}
static int
F_40 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_90 * V_91 , const char * V_92 )
{
int V_13 ;
T_2 * V_93 ;
T_4 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
V_93 = F_41 ( V_92 , V_91 ) ;
if ( ! V_93 )
return - V_94 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , V_93 , & V_73 , NULL , NULL ) ;
if ( V_13 ) {
F_42 ( V_93 ) ;
return V_13 ;
}
V_13 = F_38 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ) ;
F_42 ( V_93 ) ;
return V_13 ;
}
static int
F_43 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_90 * V_91 , const char * V_92 ,
T_5 * V_95 , T_6 * V_96 )
{
* V_95 = F_21 ( V_96 -> V_97 ) ;
return 0 ;
}
static int
F_44 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 , T_6 * V_96 )
{
int V_13 ;
struct V_98 * V_99 ;
V_99 = F_45 ( sizeof( struct V_98 ) + V_100 * 2 ,
V_101 ) ;
if ( V_99 == NULL )
return - V_94 ;
V_13 = F_46 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ,
V_99 ) ;
if ( ! V_13 )
F_47 ( V_96 , V_99 ) ;
F_42 ( V_99 ) ;
return V_13 ;
}
static bool
F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_49 ( struct V_55 * V_56 )
{
#ifdef F_50
int V_102 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
F_51 ( & V_56 -> V_104 . V_105 . V_106 [ V_102 ] , 0 ) ;
F_51 ( & V_56 -> V_104 . V_105 . V_107 [ V_102 ] , 0 ) ;
}
#endif
}
static void
F_52 ( struct V_108 * V_109 , struct V_55 * V_56 )
{
F_53 ( V_109 , L_9 ) ;
if ( V_56 -> V_61 & V_110 )
F_53 ( V_109 , L_10 ) ;
if ( V_56 -> V_61 & V_111 )
F_53 ( V_109 , L_11 ) ;
if ( V_56 -> V_61 & V_112 )
F_53 ( V_109 , L_12 ) ;
if ( V_56 -> V_61 & V_113 )
F_53 ( V_109 , L_13 ) ;
if ( V_56 -> V_61 & V_114 )
F_53 ( V_109 , L_14 ) ;
if ( V_56 -> V_61 == 0 )
F_53 ( V_109 , L_15 ) ;
if ( V_56 -> V_115 & V_116 )
F_53 ( V_109 , L_16 ) ;
if ( V_56 -> V_115 & V_117 )
F_53 ( V_109 , L_17 ) ;
if ( V_56 -> V_115 & V_118 )
F_53 ( V_109 , L_18 ) ;
if ( V_56 -> V_115 & V_119 )
F_53 ( V_109 , L_19 ) ;
F_54 ( V_109 , L_20 , V_56 -> V_120 ) ;
if ( V_56 -> V_121 )
F_54 ( V_109 , L_21 ,
V_56 -> V_121 ) ;
}
static void
F_55 ( struct V_108 * V_109 , struct V_55 * V_56 )
{
#ifdef F_50
T_7 * V_122 = V_56 -> V_104 . V_105 . V_106 ;
T_7 * V_123 = V_56 -> V_104 . V_105 . V_107 ;
F_54 ( V_109 , L_22 ,
F_56 ( & V_122 [ V_124 ] ) ,
F_56 ( & V_123 [ V_124 ] ) ) ;
F_54 ( V_109 , L_23 ,
F_56 ( & V_122 [ V_125 ] ) ,
F_56 ( & V_123 [ V_125 ] ) ) ;
F_54 ( V_109 , L_24 ,
F_56 ( & V_122 [ V_126 ] ) ,
F_56 ( & V_123 [ V_126 ] ) ) ;
F_54 ( V_109 , L_25 ,
F_56 ( & V_122 [ V_127 ] ) ,
F_56 ( & V_123 [ V_127 ] ) ) ;
F_54 ( V_109 , L_26 ,
F_56 ( & V_122 [ V_128 ] ) ,
F_56 ( & V_123 [ V_128 ] ) ) ;
F_54 ( V_109 , L_27 ,
F_56 ( & V_122 [ V_129 ] ) ,
F_56 ( & V_123 [ V_129 ] ) ) ;
F_54 ( V_109 , L_28 ,
F_56 ( & V_122 [ V_130 ] ) ,
F_56 ( & V_123 [ V_130 ] ) ) ;
F_54 ( V_109 , L_29 ,
F_56 ( & V_122 [ V_131 ] ) ,
F_56 ( & V_123 [ V_131 ] ) ) ;
F_54 ( V_109 , L_30 ,
F_56 ( & V_122 [ V_132 ] ) ,
F_56 ( & V_123 [ V_132 ] ) ) ;
F_54 ( V_109 , L_31 ,
F_56 ( & V_122 [ V_133 ] ) ,
F_56 ( & V_123 [ V_133 ] ) ) ;
F_54 ( V_109 , L_32 ,
F_56 ( & V_122 [ V_134 ] ) ,
F_56 ( & V_123 [ V_134 ] ) ) ;
F_54 ( V_109 , L_33 ,
F_56 ( & V_122 [ V_135 ] ) ,
F_56 ( & V_123 [ V_135 ] ) ) ;
F_54 ( V_109 , L_34 ,
F_56 ( & V_122 [ V_136 ] ) ,
F_56 ( & V_123 [ V_136 ] ) ) ;
F_54 ( V_109 , L_35 ,
F_56 ( & V_122 [ V_137 ] ) ,
F_56 ( & V_123 [ V_137 ] ) ) ;
F_54 ( V_109 , L_36 ,
F_56 ( & V_122 [ V_138 ] ) ,
F_56 ( & V_123 [ V_138 ] ) ) ;
F_54 ( V_109 , L_37 ,
F_56 ( & V_122 [ V_139 ] ) ,
F_56 ( & V_123 [ V_139 ] ) ) ;
F_54 ( V_109 , L_38 ,
F_56 ( & V_122 [ V_140 ] ) ,
F_56 ( & V_123 [ V_140 ] ) ) ;
F_54 ( V_109 , L_39 ,
F_56 ( & V_122 [ V_141 ] ) ,
F_56 ( & V_123 [ V_141 ] ) ) ;
F_54 ( V_109 , L_40 ,
F_56 ( & V_122 [ V_142 ] ) ,
F_56 ( & V_123 [ V_142 ] ) ) ;
#endif
}
static void
F_57 ( struct V_143 * V_144 , struct V_77 * V_78 , T_8 V_73 )
{
struct V_145 * V_146 = F_58 ( V_144 -> V_147 -> V_148 ) ;
struct V_1 * V_2 = F_59 ( V_144 -> V_149 ) -> V_52 -> V_2 ;
V_144 -> V_78 . V_85 = V_78 -> V_85 ;
V_144 -> V_78 . V_86 = V_78 -> V_86 ;
V_2 -> V_15 -> V_150 ( V_146 , V_73 , V_78 -> V_151 ,
& V_78 -> V_152 ) ;
V_146 -> V_153 = F_60 ( V_146 ) ;
}
static void
F_61 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
static int
F_62 ( const unsigned int V_50 , struct V_55 * V_56 ,
T_5 V_85 , T_5 V_86 ,
struct V_154 * V_155 )
{
int V_13 ;
unsigned int V_64 ;
struct V_156 * V_157 ;
V_13 = F_32 ( V_50 , V_56 , V_85 , V_86 ,
V_158 , true ,
NULL , 0 ,
( char * * ) & V_157 , & V_64 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_41 , V_13 ) ;
goto V_159;
}
if ( V_64 < sizeof( struct V_156 ) ) {
F_2 ( V_8 , L_42 ) ;
V_13 = - V_69 ;
goto V_159;
}
memcpy ( V_155 -> V_160 , V_157 -> V_161 , V_162 ) ;
V_159:
F_42 ( V_157 ) ;
return V_13 ;
}
static int
F_63 ( const unsigned int V_50 ,
struct V_143 * V_163 ,
struct V_143 * V_164 , T_5 V_165 ,
T_5 V_166 , T_5 V_167 )
{
int V_13 ;
unsigned int V_64 ;
struct V_154 * V_155 ;
struct V_168 * V_169 = NULL ;
struct V_55 * V_56 ;
int V_170 = 0 ;
bool V_171 = false ;
V_155 = F_64 ( sizeof( struct V_154 ) , V_101 ) ;
if ( V_155 == NULL )
return - V_94 ;
F_2 ( V_9 , L_43 ) ;
V_13 = F_62 ( V_50 , F_59 ( V_163 -> V_149 ) ,
V_163 -> V_78 . V_85 ,
V_163 -> V_78 . V_86 , V_155 ) ;
if ( V_13 )
goto V_172;
V_155 -> V_173 = F_65 ( 1 ) ;
V_155 -> V_174 = 0 ;
V_155 -> V_175 = 0 ;
V_56 = F_59 ( V_164 -> V_149 ) ;
while ( V_166 > 0 ) {
V_155 -> V_176 = F_66 ( V_165 ) ;
V_155 -> V_177 = F_66 ( V_167 ) ;
V_155 -> V_178 =
F_65 ( F_17 ( V_179 , V_166 , V_56 -> V_180 ) ) ;
V_13 = F_32 ( V_50 , V_56 , V_164 -> V_78 . V_85 ,
V_164 -> V_78 . V_86 , V_181 ,
true , ( char * ) V_155 ,
sizeof( struct V_154 ) , ( char * * ) & V_169 ,
& V_64 ) ;
if ( V_13 == 0 ) {
if ( V_64 !=
sizeof( struct V_168 ) ) {
F_2 ( V_8 , L_44 ) ;
V_13 = - V_182 ;
goto V_172;
}
if ( V_169 -> V_183 == 0 ) {
F_2 ( V_9 , L_45 ) ;
V_13 = - V_182 ;
goto V_172;
}
if ( F_33 ( V_169 -> V_183 ) >
F_33 ( V_155 -> V_178 ) ) {
F_2 ( V_8 , L_46 ) ;
V_13 = - V_182 ;
goto V_172;
}
if ( F_33 ( V_169 -> V_184 ) != 1 ) {
F_2 ( V_8 , L_47 ) ;
V_13 = - V_182 ;
goto V_172;
}
V_170 ++ ;
V_165 += F_33 ( V_169 -> V_183 ) ;
V_167 += F_33 ( V_169 -> V_183 ) ;
V_166 -= F_33 ( V_169 -> V_183 ) ;
F_2 ( V_9 , L_48 ,
F_33 ( V_169 -> V_184 ) ,
F_33 ( V_169 -> V_185 ) ,
F_33 ( V_169 -> V_183 ) ) ;
} else if ( V_13 == - V_69 ) {
if ( V_64 != sizeof( struct V_168 ) )
goto V_172;
F_2 ( V_9 , L_49 ,
F_33 ( V_169 -> V_184 ) ,
F_33 ( V_169 -> V_185 ) ,
F_33 ( V_169 -> V_183 ) ) ;
if ( ( V_170 != 0 ) || V_171 )
goto V_172;
if ( F_33 ( V_169 -> V_185 ) <
V_56 -> V_180 )
V_56 -> V_180 =
F_33 ( V_169 -> V_185 ) ;
else
goto V_172;
V_171 = true ;
}
}
V_172:
F_42 ( V_155 ) ;
return V_13 ;
}
static int
F_67 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
return F_68 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
static unsigned int
F_69 ( char * V_37 )
{
struct V_186 * V_187 = (struct V_186 * ) V_37 ;
return V_187 -> V_188 ;
}
static unsigned int
F_70 ( char * V_37 )
{
struct V_186 * V_187 = (struct V_186 * ) V_37 ;
return F_33 ( V_187 -> V_189 ) ;
}
static int
F_71 ( const unsigned int V_50 , struct V_77 * V_190 ,
struct V_191 * V_192 , unsigned int * V_193 ,
char * * V_37 , int * V_194 )
{
V_192 -> V_85 = V_190 -> V_85 ;
V_192 -> V_86 = V_190 -> V_86 ;
return F_72 ( V_50 , V_192 , V_193 , V_37 , V_194 ) ;
}
static int
F_73 ( const unsigned int V_50 , struct V_77 * V_190 ,
struct V_191 * V_192 , unsigned int * V_195 ,
struct V_196 * V_197 , unsigned long V_198 )
{
V_192 -> V_85 = V_190 -> V_85 ;
V_192 -> V_86 = V_190 -> V_86 ;
return F_74 ( V_50 , V_192 , V_195 , V_197 , V_198 ) ;
}
static bool F_75 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 , struct V_199 * V_199 , T_4 V_200 )
{
struct V_145 * V_201 ;
int V_13 ;
V_201 = F_58 ( V_199 ) ;
if ( ( V_201 -> V_202 & V_203 ) && V_200 )
return true ;
if ( ! ( V_201 -> V_202 & V_203 ) && ! V_200 )
return true ;
if ( V_56 -> V_204 )
return false ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_205 ,
true , & V_200 , 1 , NULL , NULL ) ;
if ( V_13 ) {
V_56 -> V_204 = true ;
F_2 ( V_9 , L_50 , V_13 ) ;
return false ;
}
if ( V_200 )
V_201 -> V_202 |= V_203 ;
else
V_201 -> V_202 &= ( ~ V_203 ) ;
return true ;
}
static int
F_76 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 , T_1 V_28 , bool V_206 )
{
T_9 V_207 = F_66 ( V_28 ) ;
struct V_199 * V_199 ;
V_199 = V_144 -> V_147 -> V_148 ;
if ( ! V_206 && ( V_28 > V_199 -> V_208 + 8192 ) ) {
T_4 V_209 = 1 ;
F_75 ( V_50 , V_56 , V_144 , V_199 , V_209 ) ;
}
return F_77 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_144 -> V_210 , & V_207 , false ) ;
}
static int
F_78 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 )
{
return F_79 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 ) ;
}
static int
F_80 ( const unsigned int V_50 , struct V_55 * V_56 ,
const char * V_211 , struct V_90 * V_91 ,
struct V_77 * V_78 , T_10 V_212 ,
struct V_213 * V_214 )
{
T_2 * V_93 ;
int V_13 ;
T_4 V_73 = V_74 ;
struct V_75 V_76 ;
V_93 = F_41 ( V_211 , V_91 ) ;
if ( ! V_93 )
return - V_94 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 | V_215 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , V_93 , & V_73 , NULL , NULL ) ;
F_42 ( V_93 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_51 ) ;
return V_13 ;
}
V_214 -> V_216 = 0 ;
V_214 -> V_217 = 0 ;
V_13 = F_81 ( V_50 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 , 0 , V_214 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_52 ) ;
F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
return V_13 ;
}
static int
F_82 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 , T_10 V_212 ,
struct V_213 * V_214 )
{
return F_81 ( V_50 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 , 0 , V_214 ) ;
}
static int
F_83 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
return F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
static bool
F_84 ( char * V_37 , struct V_1 * V_2 , int V_218 )
{
struct V_25 * V_38 = (struct V_25 * ) V_37 ;
if ( V_38 -> V_46 != V_219 )
return false ;
if ( ! V_218 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_38 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_85 ( struct V_55 * V_56 , struct V_77 * V_78 ,
struct V_145 * V_146 )
{
if ( V_56 -> V_52 -> V_2 -> V_61 & V_220 )
return F_86 ( 0 , V_56 , V_146 -> V_221 ,
F_87 ( V_146 ) ) ;
return F_88 ( 0 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 ,
F_89 ( V_146 ) ? 1 : 0 ) ;
}
static int
F_90 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_222 * V_37 )
{
int V_13 ;
T_2 V_72 = 0 ;
T_3 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , & V_72 , & V_73 , NULL , NULL ) ;
if ( V_13 )
return V_13 ;
V_37 -> V_223 = V_224 ;
V_13 = F_91 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_37 ) ;
F_38 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ) ;
return V_13 ;
}
static bool
F_92 ( struct V_143 * V_225 , struct V_143 * V_226 )
{
return V_225 -> V_78 . V_85 == V_226 -> V_78 . V_85 &&
V_225 -> V_78 . V_86 == V_226 -> V_78 . V_86 ;
}
static int
F_93 ( const unsigned int V_50 , struct V_143 * V_144 , T_1 V_227 ,
T_1 V_218 , T_8 type , int V_228 , int V_229 , bool V_230 )
{
if ( V_229 && ! V_228 )
type = V_231 ;
return F_94 ( V_50 , F_59 ( V_144 -> V_149 ) ,
V_144 -> V_78 . V_85 , V_144 -> V_78 . V_86 ,
V_232 -> V_233 , V_218 , V_227 , type , V_230 ) ;
}
static void
F_95 ( struct V_199 * V_199 , struct V_77 * V_78 )
{
memcpy ( V_78 -> V_221 , F_58 ( V_199 ) -> V_221 , V_234 ) ;
}
static void
F_96 ( struct V_199 * V_199 , struct V_77 * V_78 )
{
memcpy ( F_58 ( V_199 ) -> V_221 , V_78 -> V_221 , V_234 ) ;
}
static void
F_97 ( struct V_77 * V_78 )
{
F_98 ( V_78 -> V_221 , V_234 ) ;
}
static int
F_99 ( const unsigned int V_50 , struct V_55 * V_56 ,
const char * V_92 , char * * V_235 ,
struct V_90 * V_91 )
{
int V_13 ;
T_2 * V_93 ;
T_4 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
struct V_236 * V_237 = NULL ;
struct V_238 * V_239 ;
unsigned int V_240 , V_241 ;
F_2 ( V_9 , L_53 , V_242 , V_92 ) ;
V_93 = F_41 ( V_92 , V_91 ) ;
if ( ! V_93 )
return - V_94 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , V_93 , & V_73 , NULL , & V_237 ) ;
if ( ! V_13 || ! V_237 ) {
F_42 ( V_93 ) ;
return - V_33 ;
}
V_13 = 0 ;
V_239 = (struct V_238 * ) V_237 -> V_243 ;
V_240 = F_11 ( V_239 -> V_244 ) ;
V_241 = F_11 ( V_239 -> V_245 ) ;
* V_235 = F_100 (
( char * ) V_239 -> V_246 + V_241 ,
V_240 , true , V_91 -> V_247 ) ;
if ( ! ( * V_235 ) ) {
F_42 ( V_93 ) ;
return - V_94 ;
}
F_101 ( * V_235 , '/' ) ;
F_2 ( V_9 , L_54 , V_242 , * V_235 ) ;
F_42 ( V_93 ) ;
return V_13 ;
}
static long F_102 ( struct V_248 * V_248 , struct V_55 * V_56 ,
T_11 V_227 , T_11 V_166 , bool V_249 )
{
struct V_199 * V_199 ;
struct V_145 * V_201 ;
struct V_143 * V_144 = V_248 -> V_250 ;
struct V_251 V_252 ;
long V_13 ;
unsigned int V_50 ;
V_50 = F_103 () ;
V_199 = V_144 -> V_147 -> V_148 ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_89 ( V_201 ) )
if ( V_249 == false )
return - V_253 ;
if ( ! ( V_201 -> V_202 & V_203 ) )
return - V_253 ;
if ( V_249 == false )
if ( F_104 ( V_199 ) < V_227 + V_166 )
return - V_253 ;
F_2 ( V_9 , L_55 , V_227 , V_166 ) ;
V_252 . V_254 = F_66 ( V_227 ) ;
V_252 . V_255 = F_66 ( V_227 + V_166 ) ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_256 ,
true , ( char * ) & V_252 ,
sizeof( struct V_251 ) , NULL , NULL ) ;
F_105 ( V_50 ) ;
return V_13 ;
}
static long F_106 ( struct V_248 * V_248 , struct V_55 * V_56 ,
T_11 V_227 , T_11 V_166 )
{
struct V_199 * V_199 ;
struct V_145 * V_201 ;
struct V_143 * V_144 = V_248 -> V_250 ;
struct V_251 V_252 ;
long V_13 ;
unsigned int V_50 ;
T_4 V_209 = 1 ;
V_50 = F_103 () ;
V_199 = V_144 -> V_147 -> V_148 ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_75 ( V_50 , V_56 , V_144 , V_199 , V_209 ) )
return - V_253 ;
F_2 ( V_9 , L_55 , V_227 , V_166 ) ;
V_252 . V_254 = F_66 ( V_227 ) ;
V_252 . V_255 = F_66 ( V_227 + V_166 ) ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_256 ,
true , ( char * ) & V_252 ,
sizeof( struct V_251 ) , NULL , NULL ) ;
F_105 ( V_50 ) ;
return V_13 ;
}
static long F_107 ( struct V_248 * V_248 , struct V_55 * V_56 ,
T_11 V_257 , T_11 V_166 , bool V_249 )
{
struct V_199 * V_199 ;
struct V_145 * V_201 ;
struct V_143 * V_144 = V_248 -> V_250 ;
long V_13 = - V_253 ;
unsigned int V_50 ;
V_50 = F_103 () ;
V_199 = V_144 -> V_147 -> V_148 ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_89 ( V_201 ) )
if ( V_249 == false )
return - V_253 ;
if ( ( V_201 -> V_202 & V_203 ) == 0 ) {
if ( V_249 == true )
return 0 ;
else if ( F_104 ( V_199 ) >= V_257 + V_166 )
return 0 ;
else
return - V_253 ;
}
if ( ( V_249 == true ) || ( F_104 ( V_199 ) >= V_257 + V_166 ) ) {
if ( ( V_257 > 8192 ) || ( V_257 + V_166 + 8192 < F_104 ( V_199 ) ) )
return - V_253 ;
V_13 = F_75 ( V_50 , V_56 , V_144 , V_199 , false ) ;
}
F_105 ( V_50 ) ;
return V_13 ;
}
static long F_108 ( struct V_248 * V_248 , struct V_55 * V_56 , int V_258 ,
T_11 V_257 , T_11 V_166 )
{
if ( V_258 & V_259 )
return F_106 ( V_248 , V_56 , V_257 , V_166 ) ;
else if ( V_258 & V_260 ) {
if ( V_258 & V_261 )
return F_102 ( V_248 , V_56 , V_257 , V_166 , true ) ;
return F_102 ( V_248 , V_56 , V_257 , V_166 , false ) ;
} else if ( V_258 == V_261 )
return F_107 ( V_248 , V_56 , V_257 , V_166 , true ) ;
else if ( V_258 == 0 )
return F_107 ( V_248 , V_56 , V_257 , V_166 , false ) ;
return - V_253 ;
}
static void
F_109 ( struct V_1 * V_2 ,
struct V_145 * V_146 , bool V_262 )
{
if ( V_262 )
V_2 -> V_15 -> V_150 ( V_146 , V_263 ,
0 , NULL ) ;
else
V_2 -> V_15 -> V_150 ( V_146 , 0 , 0 , NULL ) ;
}
static void
F_110 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_151 , bool * V_152 )
{
V_73 &= 0xFF ;
if ( V_73 == V_264 )
return;
if ( V_73 == V_265 ) {
V_146 -> V_73 = V_266 ;
F_2 ( V_9 , L_56 ,
& V_146 -> V_267 ) ;
} else if ( V_73 == V_268 ) {
V_146 -> V_73 = V_269 ;
F_2 ( V_9 , L_57 ,
& V_146 -> V_267 ) ;
} else if ( V_73 == V_263 ) {
V_146 -> V_73 = V_270 ;
F_2 ( V_9 , L_58 ,
& V_146 -> V_267 ) ;
} else
V_146 -> V_73 = 0 ;
}
static void
F_111 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_151 , bool * V_152 )
{
char V_271 [ 5 ] = { 0 } ;
V_73 &= 0xFF ;
if ( V_73 == V_264 )
return;
V_146 -> V_73 = 0 ;
if ( V_73 & V_272 ) {
V_146 -> V_73 |= V_270 ;
strcat ( V_271 , L_59 ) ;
}
if ( V_73 & V_273 ) {
V_146 -> V_73 |= V_274 ;
strcat ( V_271 , L_60 ) ;
}
if ( V_73 & V_275 ) {
V_146 -> V_73 |= V_276 ;
strcat ( V_271 , L_61 ) ;
}
if ( ! V_146 -> V_73 )
strcat ( V_271 , L_62 ) ;
F_2 ( V_9 , L_63 , V_271 ,
& V_146 -> V_267 ) ;
}
static void
F_112 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_151 , bool * V_152 )
{
unsigned int V_277 = V_146 -> V_73 ;
F_111 ( V_146 , V_73 , V_151 , V_152 ) ;
if ( V_152 ) {
* V_152 = false ;
if ( V_277 == V_270 ) {
if ( V_146 -> V_73 == V_270 &&
( V_151 - V_146 -> V_151 > 0 ) )
* V_152 = true ;
else if ( V_146 -> V_73 == V_278 &&
( V_151 - V_146 -> V_151 > 1 ) )
* V_152 = true ;
else if ( V_146 -> V_73 == V_266 &&
( V_151 - V_146 -> V_151 > 1 ) )
* V_152 = true ;
else if ( V_146 -> V_73 == 0 &&
( V_151 - V_146 -> V_151 > 0 ) )
* V_152 = true ;
} else if ( V_277 == V_278 ) {
if ( V_146 -> V_73 == V_278 &&
( V_151 - V_146 -> V_151 > 0 ) )
* V_152 = true ;
else if ( V_146 -> V_73 == V_266 &&
( V_151 - V_146 -> V_151 > 1 ) )
* V_152 = true ;
}
V_146 -> V_151 = V_151 ;
}
}
static bool
F_113 ( T_8 V_73 )
{
return V_73 == V_263 ;
}
static bool
F_114 ( T_8 V_73 )
{
return ( V_73 & V_272 ) &&
! ( V_73 & V_275 ) ;
}
static T_12
F_115 ( T_3 V_73 )
{
if ( V_73 == V_268 )
return V_279 | V_280 ;
else if ( V_73 == V_263 )
return V_280 ;
else if ( V_73 == V_265 )
return V_281 | V_280 |
V_279 ;
return 0 ;
}
static char *
F_116 ( T_3 * V_221 , T_3 V_73 )
{
struct V_282 * V_37 ;
V_37 = F_45 ( sizeof( struct V_282 ) , V_101 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_283 . V_284 = F_66 ( * ( ( T_5 * ) V_221 ) ) ;
V_37 -> V_283 . V_285 = F_66 ( * ( ( T_5 * ) ( V_221 + 8 ) ) ) ;
V_37 -> V_283 . V_286 = F_115 ( V_73 ) ;
V_37 -> V_287 . V_188 = F_117 ( F_118
( struct V_282 , V_283 ) ) ;
V_37 -> V_287 . V_189 = F_65 ( sizeof( struct V_288 ) ) ;
V_37 -> V_287 . V_289 = F_117 ( F_118
( struct V_282 , V_290 ) ) ;
V_37 -> V_287 . V_291 = F_117 ( 4 ) ;
V_37 -> V_290 [ 0 ] = 'R' ;
V_37 -> V_290 [ 1 ] = 'q' ;
V_37 -> V_290 [ 2 ] = 'L' ;
V_37 -> V_290 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static char *
F_119 ( T_3 * V_221 , T_3 V_73 )
{
struct V_292 * V_37 ;
V_37 = F_45 ( sizeof( struct V_292 ) , V_101 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_283 . V_284 = F_66 ( * ( ( T_5 * ) V_221 ) ) ;
V_37 -> V_283 . V_285 = F_66 ( * ( ( T_5 * ) ( V_221 + 8 ) ) ) ;
V_37 -> V_283 . V_286 = F_115 ( V_73 ) ;
V_37 -> V_287 . V_188 = F_117 ( F_118
( struct V_292 , V_283 ) ) ;
V_37 -> V_287 . V_189 = F_65 ( sizeof( struct V_293 ) ) ;
V_37 -> V_287 . V_289 = F_117 ( F_118
( struct V_292 , V_290 ) ) ;
V_37 -> V_287 . V_291 = F_117 ( 4 ) ;
V_37 -> V_290 [ 0 ] = 'R' ;
V_37 -> V_290 [ 1 ] = 'q' ;
V_37 -> V_290 [ 2 ] = 'L' ;
V_37 -> V_290 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static T_4
F_120 ( void * V_37 , unsigned int * V_151 )
{
struct V_282 * V_294 = (struct V_282 * ) V_37 ;
* V_151 = 0 ;
if ( V_294 -> V_283 . V_295 & V_296 )
return V_264 ;
return F_33 ( V_294 -> V_283 . V_286 ) ;
}
static T_4
F_121 ( void * V_37 , unsigned int * V_151 )
{
struct V_292 * V_294 = (struct V_292 * ) V_37 ;
* V_151 = F_11 ( V_294 -> V_283 . V_297 ) ;
if ( V_294 -> V_283 . V_295 & V_296 )
return V_264 ;
return F_33 ( V_294 -> V_283 . V_286 ) ;
}
static unsigned int
F_122 ( struct V_199 * V_199 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_123 ( struct V_143 * V_144 )
{
return ! V_144 -> V_298 ;
}
