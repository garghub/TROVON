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
F_4 ( & V_35 ) ;
F_21 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_38 -> V_39 ) &&
( V_24 -> V_40 == V_41 ) &&
( V_24 -> V_42 == V_38 -> V_43 ) ) {
F_5 ( & V_35 ) ;
return V_24 ;
}
}
F_5 ( & V_35 ) ;
return NULL ;
}
static void
F_22 ( void * V_37 )
{
#ifdef F_23
struct V_25 * V_44 = (struct V_25 * ) V_37 ;
F_2 ( V_8 , L_3 ,
V_44 -> V_43 , V_44 -> V_45 , V_44 -> V_46 , V_44 -> V_39 ,
V_44 -> V_47 ) ;
F_2 ( V_8 , L_4 , V_44 , F_24 ( V_44 ) ) ;
#endif
}
static bool
F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_48 == 0 ;
}
static int
F_26 ( const unsigned int V_49 , struct V_50 * V_51 )
{
int V_13 ;
V_51 -> V_2 -> V_36 = 0 ;
V_13 = F_27 ( V_49 , V_51 ) ;
if ( V_13 == - V_52 )
V_13 = - V_53 ;
return V_13 ;
}
static unsigned int
F_28 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_1 * V_2 = V_55 -> V_51 -> V_2 ;
unsigned int V_58 ;
V_58 = V_57 -> V_58 ? V_57 -> V_58 : V_59 ;
V_58 = F_17 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_60 & V_61 ) )
V_58 = F_17 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_58 ;
}
static unsigned int
F_29 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_1 * V_2 = V_55 -> V_51 -> V_2 ;
unsigned int V_62 ;
V_62 = V_57 -> V_62 ? V_57 -> V_62 : V_59 ;
V_62 = F_17 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_60 & V_61 ) )
V_62 = F_17 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_62 ;
}
static int
F_30 ( const unsigned int V_49 , struct V_54 * V_55 )
{
int V_13 ;
unsigned int V_63 = 0 ;
struct V_64 * V_65 ;
V_13 = F_31 ( V_49 , V_55 , V_66 , V_66 ,
V_67 , true ,
NULL , 0 ,
( char * * ) & V_65 , & V_63 ) ;
if ( ( V_13 == 0 ) && ( V_63 > 0 ) ) {
F_2 ( V_9 , L_5 ,
F_32 ( V_65 -> V_68 ) ) ;
F_2 ( V_9 , L_6 ,
F_33 ( V_65 -> V_69 ) ) ;
} else
F_2 ( V_8 , L_7 , V_13 ) ;
return V_13 ;
}
static void
F_34 ( const unsigned int V_49 , struct V_54 * V_55 )
{
int V_13 ;
T_2 V_70 = 0 ;
T_3 V_71 = V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = & V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , & V_70 , & V_71 , NULL , NULL ) ;
if ( V_13 )
return;
#ifdef F_36
F_30 ( V_49 , V_55 ) ;
#endif
F_37 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_85 ) ;
F_37 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_86 ) ;
F_37 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_87 ) ;
F_38 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ) ;
return;
}
static void
F_39 ( const unsigned int V_49 , struct V_54 * V_55 )
{
int V_13 ;
T_2 V_70 = 0 ;
T_3 V_71 = V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = & V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , & V_70 , & V_71 , NULL , NULL ) ;
if ( V_13 )
return;
F_37 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_85 ) ;
F_37 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_86 ) ;
F_38 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ) ;
return;
}
static int
F_40 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_88 * V_89 , const char * V_90 )
{
int V_13 ;
T_2 * V_91 ;
T_4 V_71 = V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
V_91 = F_41 ( V_90 , V_89 ) ;
if ( ! V_91 )
return - V_92 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = & V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , V_91 , & V_71 , NULL , NULL ) ;
if ( V_13 ) {
F_42 ( V_91 ) ;
return V_13 ;
}
V_13 = F_38 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ) ;
F_42 ( V_91 ) ;
return V_13 ;
}
static int
F_43 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_88 * V_89 , const char * V_90 ,
T_5 * V_93 , T_6 * V_94 )
{
* V_93 = F_33 ( V_94 -> V_95 ) ;
return 0 ;
}
static int
F_44 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_75 * V_76 , T_6 * V_94 )
{
int V_13 ;
struct V_96 * V_97 ;
V_97 = F_45 ( sizeof( struct V_96 ) + V_98 * 2 ,
V_99 ) ;
if ( V_97 == NULL )
return - V_92 ;
V_13 = F_46 ( V_49 , V_55 , V_76 -> V_83 , V_76 -> V_84 ,
V_97 ) ;
if ( ! V_13 )
F_47 ( V_94 , V_97 ) ;
F_42 ( V_97 ) ;
return V_13 ;
}
static bool
F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_49 ( struct V_54 * V_55 )
{
#ifdef F_50
int V_100 ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ ) {
F_51 ( & V_55 -> V_102 . V_103 . V_104 [ V_100 ] , 0 ) ;
F_51 ( & V_55 -> V_102 . V_103 . V_105 [ V_100 ] , 0 ) ;
}
#endif
}
static void
F_52 ( struct V_106 * V_107 , struct V_54 * V_55 )
{
F_53 ( V_107 , L_8 ) ;
if ( V_55 -> V_60 & V_108 )
F_53 ( V_107 , L_9 ) ;
if ( V_55 -> V_60 & V_109 )
F_53 ( V_107 , L_10 ) ;
if ( V_55 -> V_60 & V_110 )
F_53 ( V_107 , L_11 ) ;
if ( V_55 -> V_60 & V_111 )
F_53 ( V_107 , L_12 ) ;
if ( V_55 -> V_60 & V_112 )
F_53 ( V_107 , L_13 ) ;
if ( V_55 -> V_60 == 0 )
F_53 ( V_107 , L_14 ) ;
if ( V_55 -> V_113 & V_114 )
F_53 ( V_107 , L_15 ) ;
if ( V_55 -> V_113 & V_115 )
F_53 ( V_107 , L_16 ) ;
if ( V_55 -> V_113 & V_116 )
F_53 ( V_107 , L_17 ) ;
if ( V_55 -> V_113 & V_117 )
F_53 ( V_107 , L_18 ) ;
F_54 ( V_107 , L_19 , V_55 -> V_118 ) ;
if ( V_55 -> V_119 )
F_54 ( V_107 , L_20 ,
V_55 -> V_119 ) ;
}
static void
F_55 ( struct V_106 * V_107 , struct V_54 * V_55 )
{
#ifdef F_50
T_7 * V_120 = V_55 -> V_102 . V_103 . V_104 ;
T_7 * V_121 = V_55 -> V_102 . V_103 . V_105 ;
F_54 ( V_107 , L_21 ,
F_56 ( & V_120 [ V_122 ] ) ,
F_56 ( & V_121 [ V_122 ] ) ) ;
F_54 ( V_107 , L_22 ,
F_56 ( & V_120 [ V_123 ] ) ,
F_56 ( & V_121 [ V_123 ] ) ) ;
F_54 ( V_107 , L_23 ,
F_56 ( & V_120 [ V_124 ] ) ,
F_56 ( & V_121 [ V_124 ] ) ) ;
F_54 ( V_107 , L_24 ,
F_56 ( & V_120 [ V_125 ] ) ,
F_56 ( & V_121 [ V_125 ] ) ) ;
F_54 ( V_107 , L_25 ,
F_56 ( & V_120 [ V_126 ] ) ,
F_56 ( & V_121 [ V_126 ] ) ) ;
F_54 ( V_107 , L_26 ,
F_56 ( & V_120 [ V_127 ] ) ,
F_56 ( & V_121 [ V_127 ] ) ) ;
F_54 ( V_107 , L_27 ,
F_56 ( & V_120 [ V_128 ] ) ,
F_56 ( & V_121 [ V_128 ] ) ) ;
F_54 ( V_107 , L_28 ,
F_56 ( & V_120 [ V_129 ] ) ,
F_56 ( & V_121 [ V_129 ] ) ) ;
F_54 ( V_107 , L_29 ,
F_56 ( & V_120 [ V_130 ] ) ,
F_56 ( & V_121 [ V_130 ] ) ) ;
F_54 ( V_107 , L_30 ,
F_56 ( & V_120 [ V_131 ] ) ,
F_56 ( & V_121 [ V_131 ] ) ) ;
F_54 ( V_107 , L_31 ,
F_56 ( & V_120 [ V_132 ] ) ,
F_56 ( & V_121 [ V_132 ] ) ) ;
F_54 ( V_107 , L_32 ,
F_56 ( & V_120 [ V_133 ] ) ,
F_56 ( & V_121 [ V_133 ] ) ) ;
F_54 ( V_107 , L_33 ,
F_56 ( & V_120 [ V_134 ] ) ,
F_56 ( & V_121 [ V_134 ] ) ) ;
F_54 ( V_107 , L_34 ,
F_56 ( & V_120 [ V_135 ] ) ,
F_56 ( & V_121 [ V_135 ] ) ) ;
F_54 ( V_107 , L_35 ,
F_56 ( & V_120 [ V_136 ] ) ,
F_56 ( & V_121 [ V_136 ] ) ) ;
F_54 ( V_107 , L_36 ,
F_56 ( & V_120 [ V_137 ] ) ,
F_56 ( & V_121 [ V_137 ] ) ) ;
F_54 ( V_107 , L_37 ,
F_56 ( & V_120 [ V_138 ] ) ,
F_56 ( & V_121 [ V_138 ] ) ) ;
F_54 ( V_107 , L_38 ,
F_56 ( & V_120 [ V_139 ] ) ,
F_56 ( & V_121 [ V_139 ] ) ) ;
F_54 ( V_107 , L_39 ,
F_56 ( & V_120 [ V_140 ] ) ,
F_56 ( & V_121 [ V_140 ] ) ) ;
#endif
}
static void
F_57 ( struct V_141 * V_142 , struct V_75 * V_76 , T_8 V_71 )
{
struct V_143 * V_144 = F_58 ( V_142 -> V_145 -> V_146 ) ;
struct V_1 * V_2 = F_59 ( V_142 -> V_147 ) -> V_51 -> V_2 ;
V_142 -> V_76 . V_83 = V_76 -> V_83 ;
V_142 -> V_76 . V_84 = V_76 -> V_84 ;
V_2 -> V_15 -> V_148 ( V_144 , V_71 , V_76 -> V_149 ,
& V_76 -> V_150 ) ;
V_144 -> V_151 = F_60 ( V_144 ) ;
}
static void
F_61 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_75 * V_76 )
{
F_38 ( V_49 , V_55 , V_76 -> V_83 , V_76 -> V_84 ) ;
}
static int
F_62 ( const unsigned int V_49 , struct V_54 * V_55 ,
T_5 V_83 , T_5 V_84 ,
struct V_152 * V_153 )
{
int V_13 ;
unsigned int V_63 ;
struct V_154 * V_155 ;
V_13 = F_31 ( V_49 , V_55 , V_83 , V_84 ,
V_156 , true ,
NULL , 0 ,
( char * * ) & V_155 , & V_63 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_40 , V_13 ) ;
goto V_157;
}
if ( V_63 < sizeof( struct V_154 ) ) {
F_2 ( V_8 , L_41 ) ;
V_13 = - V_158 ;
goto V_157;
}
memcpy ( V_153 -> V_159 , V_155 -> V_160 , V_161 ) ;
V_157:
F_42 ( V_155 ) ;
return V_13 ;
}
static int
F_63 ( const unsigned int V_49 ,
struct V_141 * V_162 ,
struct V_141 * V_163 , T_5 V_164 ,
T_5 V_165 , T_5 V_166 )
{
int V_13 ;
unsigned int V_63 ;
struct V_152 * V_153 ;
struct V_167 * V_168 = NULL ;
struct V_54 * V_55 ;
int V_169 = 0 ;
bool V_170 = false ;
V_153 = F_64 ( sizeof( struct V_152 ) , V_99 ) ;
if ( V_153 == NULL )
return - V_92 ;
F_2 ( V_9 , L_42 ) ;
V_13 = F_62 ( V_49 , F_59 ( V_162 -> V_147 ) ,
V_162 -> V_76 . V_83 ,
V_162 -> V_76 . V_84 , V_153 ) ;
if ( V_13 )
goto V_171;
V_153 -> V_172 = F_65 ( 1 ) ;
V_153 -> V_173 = 0 ;
V_153 -> V_174 = 0 ;
V_55 = F_59 ( V_163 -> V_147 ) ;
while ( V_165 > 0 ) {
V_153 -> V_175 = F_66 ( V_164 ) ;
V_153 -> V_176 = F_66 ( V_166 ) ;
V_153 -> V_177 =
F_67 ( F_17 ( V_178 , V_165 , V_55 -> V_179 ) ) ;
V_13 = F_31 ( V_49 , V_55 , V_163 -> V_76 . V_83 ,
V_163 -> V_76 . V_84 , V_180 ,
true , ( char * ) V_153 ,
sizeof( struct V_152 ) , ( char * * ) & V_168 ,
& V_63 ) ;
if ( V_13 == 0 ) {
if ( V_63 !=
sizeof( struct V_167 ) ) {
F_2 ( V_8 , L_43 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( V_168 -> V_182 == 0 ) {
F_2 ( V_9 , L_44 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( F_32 ( V_168 -> V_182 ) >
F_32 ( V_153 -> V_177 ) ) {
F_2 ( V_8 , L_45 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( F_32 ( V_168 -> V_183 ) != 1 ) {
F_2 ( V_8 , L_46 ) ;
V_13 = - V_181 ;
goto V_171;
}
V_169 ++ ;
V_164 += F_32 ( V_168 -> V_182 ) ;
V_166 += F_32 ( V_168 -> V_182 ) ;
V_165 -= F_32 ( V_168 -> V_182 ) ;
F_2 ( V_9 , L_47 ,
F_32 ( V_168 -> V_183 ) ,
F_32 ( V_168 -> V_184 ) ,
F_32 ( V_168 -> V_182 ) ) ;
} else if ( V_13 == - V_158 ) {
if ( V_63 != sizeof( struct V_167 ) )
goto V_171;
F_2 ( V_9 , L_48 ,
F_32 ( V_168 -> V_183 ) ,
F_32 ( V_168 -> V_184 ) ,
F_32 ( V_168 -> V_182 ) ) ;
if ( ( V_169 != 0 ) || V_170 )
goto V_171;
if ( F_32 ( V_168 -> V_184 ) <
V_55 -> V_179 )
V_55 -> V_179 =
F_32 ( V_168 -> V_184 ) ;
else
goto V_171;
V_170 = true ;
}
}
V_171:
F_42 ( V_153 ) ;
return V_13 ;
}
static int
F_68 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_75 * V_76 )
{
return F_69 ( V_49 , V_55 , V_76 -> V_83 , V_76 -> V_84 ) ;
}
static unsigned int
F_70 ( char * V_37 )
{
struct V_185 * V_186 = (struct V_185 * ) V_37 ;
return V_186 -> V_187 ;
}
static unsigned int
F_71 ( char * V_37 )
{
struct V_185 * V_186 = (struct V_185 * ) V_37 ;
return F_32 ( V_186 -> V_188 ) ;
}
static int
F_72 ( const unsigned int V_49 , struct V_141 * V_142 ,
struct V_189 * V_190 , unsigned int * V_191 ,
char * * V_37 , int * V_192 )
{
V_190 -> V_83 = V_142 -> V_76 . V_83 ;
V_190 -> V_84 = V_142 -> V_76 . V_84 ;
return F_73 ( V_49 , V_190 , V_191 , V_37 , V_192 ) ;
}
static int
F_74 ( const unsigned int V_49 , struct V_141 * V_142 ,
struct V_189 * V_190 , unsigned int * V_193 ,
struct V_194 * V_195 , unsigned long V_196 )
{
V_190 -> V_83 = V_142 -> V_76 . V_83 ;
V_190 -> V_84 = V_142 -> V_76 . V_84 ;
return F_75 ( V_49 , V_190 , V_193 , V_195 , V_196 ) ;
}
static bool F_76 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_141 * V_142 , struct V_197 * V_197 , T_4 V_198 )
{
struct V_143 * V_199 ;
int V_13 ;
V_199 = F_58 ( V_197 ) ;
if ( ( V_199 -> V_200 & V_201 ) && V_198 )
return true ;
if ( ! ( V_199 -> V_200 & V_201 ) && ! V_198 )
return true ;
if ( V_55 -> V_202 )
return false ;
V_13 = F_31 ( V_49 , V_55 , V_142 -> V_76 . V_83 ,
V_142 -> V_76 . V_84 , V_203 ,
true , & V_198 , 1 , NULL , NULL ) ;
if ( V_13 ) {
V_55 -> V_202 = true ;
F_2 ( V_9 , L_49 , V_13 ) ;
return false ;
}
if ( V_198 )
V_199 -> V_200 |= V_201 ;
else
V_199 -> V_200 &= ( ~ V_201 ) ;
return true ;
}
static int
F_77 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_141 * V_142 , T_1 V_28 , bool V_204 )
{
T_9 V_205 = F_66 ( V_28 ) ;
struct V_197 * V_197 ;
V_197 = V_142 -> V_145 -> V_146 ;
if ( ! V_204 && ( V_28 > V_197 -> V_206 + 8192 ) ) {
T_4 V_207 = 1 ;
F_76 ( V_49 , V_55 , V_142 , V_197 , V_207 ) ;
}
return F_78 ( V_49 , V_55 , V_142 -> V_76 . V_83 ,
V_142 -> V_76 . V_84 , V_142 -> V_208 , & V_205 , false ) ;
}
static int
F_79 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_141 * V_142 )
{
return F_80 ( V_49 , V_55 , V_142 -> V_76 . V_83 ,
V_142 -> V_76 . V_84 ) ;
}
static int
F_81 ( const unsigned int V_49 , struct V_54 * V_55 ,
const char * V_209 , struct V_88 * V_89 ,
struct V_75 * V_76 , T_10 V_210 ,
struct V_211 * V_212 )
{
T_2 * V_91 ;
int V_13 ;
T_4 V_71 = V_72 ;
struct V_73 V_74 ;
V_91 = F_41 ( V_209 , V_89 ) ;
if ( ! V_91 )
return - V_92 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 | V_213 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , V_91 , & V_71 , NULL , NULL ) ;
F_42 ( V_91 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_50 ) ;
return V_13 ;
}
V_212 -> V_214 = 0 ;
V_212 -> V_215 = 0 ;
V_13 = F_82 ( V_49 , V_55 , V_76 -> V_83 ,
V_76 -> V_84 , 0 , V_212 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_51 ) ;
F_38 ( V_49 , V_55 , V_76 -> V_83 , V_76 -> V_84 ) ;
}
return V_13 ;
}
static int
F_83 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_75 * V_76 , T_10 V_210 ,
struct V_211 * V_212 )
{
return F_82 ( V_49 , V_55 , V_76 -> V_83 ,
V_76 -> V_84 , 0 , V_212 ) ;
}
static int
F_84 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_75 * V_76 )
{
return F_38 ( V_49 , V_55 , V_76 -> V_83 , V_76 -> V_84 ) ;
}
static bool
F_85 ( char * V_37 , struct V_1 * V_2 , int V_216 )
{
struct V_25 * V_38 = (struct V_25 * ) V_37 ;
if ( V_38 -> V_45 != V_217 )
return false ;
if ( ! V_216 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_38 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_86 ( struct V_54 * V_55 , struct V_75 * V_76 ,
struct V_143 * V_144 )
{
if ( V_55 -> V_51 -> V_2 -> V_60 & V_218 )
return F_87 ( 0 , V_55 , V_144 -> V_219 ,
F_88 ( V_144 ) ) ;
return F_89 ( 0 , V_55 , V_76 -> V_83 ,
V_76 -> V_84 ,
F_90 ( V_144 ) ? 1 : 0 ) ;
}
static int
F_91 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_220 * V_37 )
{
int V_13 ;
T_2 V_70 = 0 ;
T_3 V_71 = V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = & V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , & V_70 , & V_71 , NULL , NULL ) ;
if ( V_13 )
return V_13 ;
V_37 -> V_221 = V_222 ;
V_13 = F_92 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ,
V_37 ) ;
F_38 ( V_49 , V_55 , V_76 . V_83 , V_76 . V_84 ) ;
return V_13 ;
}
static bool
F_93 ( struct V_141 * V_223 , struct V_141 * V_224 )
{
return V_223 -> V_76 . V_83 == V_224 -> V_76 . V_83 &&
V_223 -> V_76 . V_84 == V_224 -> V_76 . V_84 ;
}
static int
F_94 ( const unsigned int V_49 , struct V_141 * V_142 , T_1 V_225 ,
T_1 V_216 , T_8 type , int V_226 , int V_227 , bool V_228 )
{
if ( V_227 && ! V_226 )
type = V_229 ;
return F_95 ( V_49 , F_59 ( V_142 -> V_147 ) ,
V_142 -> V_76 . V_83 , V_142 -> V_76 . V_84 ,
V_230 -> V_231 , V_216 , V_225 , type , V_228 ) ;
}
static void
F_96 ( struct V_197 * V_197 , struct V_75 * V_76 )
{
memcpy ( V_76 -> V_219 , F_58 ( V_197 ) -> V_219 , V_232 ) ;
}
static void
F_97 ( struct V_197 * V_197 , struct V_75 * V_76 )
{
memcpy ( F_58 ( V_197 ) -> V_219 , V_76 -> V_219 , V_232 ) ;
}
static void
F_98 ( struct V_75 * V_76 )
{
F_99 ( V_76 -> V_219 , V_232 ) ;
}
static int
F_100 ( const unsigned int V_49 , struct V_54 * V_55 ,
const char * V_90 , char * * V_233 ,
struct V_88 * V_89 )
{
int V_13 ;
T_2 * V_91 ;
T_4 V_71 = V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
struct V_234 * V_235 = NULL ;
struct V_236 * V_237 ;
unsigned int V_238 , V_239 ;
F_2 ( V_9 , L_52 , V_240 , V_90 ) ;
V_91 = F_41 ( V_90 , V_89 ) ;
if ( ! V_91 )
return - V_92 ;
V_74 . V_55 = V_55 ;
V_74 . V_77 = V_78 ;
V_74 . V_79 = V_80 ;
V_74 . V_81 = 0 ;
V_74 . V_76 = & V_76 ;
V_74 . V_82 = false ;
V_13 = F_35 ( V_49 , & V_74 , V_91 , & V_71 , NULL , & V_235 ) ;
if ( ! V_13 || ! V_235 ) {
F_42 ( V_91 ) ;
return - V_33 ;
}
V_13 = 0 ;
V_237 = (struct V_236 * ) V_235 -> V_241 ;
V_238 = F_11 ( V_237 -> V_242 ) ;
V_239 = F_11 ( V_237 -> V_243 ) ;
* V_233 = F_101 (
( char * ) V_237 -> V_244 + V_239 ,
V_238 , true , V_89 -> V_245 ) ;
if ( ! ( * V_233 ) ) {
F_42 ( V_91 ) ;
return - V_92 ;
}
F_102 ( * V_233 , '/' ) ;
F_2 ( V_9 , L_53 , V_240 , * V_233 ) ;
F_42 ( V_91 ) ;
return V_13 ;
}
static long F_103 ( struct V_246 * V_246 , struct V_54 * V_55 ,
T_11 V_225 , T_11 V_165 , bool V_247 )
{
struct V_197 * V_197 ;
struct V_143 * V_199 ;
struct V_141 * V_142 = V_246 -> V_248 ;
struct V_249 V_250 ;
long V_13 ;
unsigned int V_49 ;
V_49 = F_104 () ;
V_197 = V_142 -> V_145 -> V_146 ;
V_199 = F_58 ( V_197 ) ;
if ( ! F_90 ( V_199 ) )
if ( V_247 == false )
return - V_251 ;
if ( ! ( V_199 -> V_200 & V_201 ) )
return - V_251 ;
if ( V_247 == false )
if ( F_105 ( V_197 ) < V_225 + V_165 )
return - V_251 ;
F_2 ( V_9 , L_54 , V_225 , V_165 ) ;
V_250 . V_252 = F_66 ( V_225 ) ;
V_250 . V_253 = F_66 ( V_225 + V_165 ) ;
V_13 = F_31 ( V_49 , V_55 , V_142 -> V_76 . V_83 ,
V_142 -> V_76 . V_84 , V_254 ,
true , ( char * ) & V_250 ,
sizeof( struct V_249 ) , NULL , NULL ) ;
F_106 ( V_49 ) ;
return V_13 ;
}
static long F_107 ( struct V_246 * V_246 , struct V_54 * V_55 ,
T_11 V_225 , T_11 V_165 )
{
struct V_197 * V_197 ;
struct V_143 * V_199 ;
struct V_141 * V_142 = V_246 -> V_248 ;
struct V_249 V_250 ;
long V_13 ;
unsigned int V_49 ;
T_4 V_207 = 1 ;
V_49 = F_104 () ;
V_197 = V_142 -> V_145 -> V_146 ;
V_199 = F_58 ( V_197 ) ;
if ( ! F_76 ( V_49 , V_55 , V_142 , V_197 , V_207 ) )
return - V_251 ;
F_2 ( V_9 , L_54 , V_225 , V_165 ) ;
V_250 . V_252 = F_66 ( V_225 ) ;
V_250 . V_253 = F_66 ( V_225 + V_165 ) ;
V_13 = F_31 ( V_49 , V_55 , V_142 -> V_76 . V_83 ,
V_142 -> V_76 . V_84 , V_254 ,
true , ( char * ) & V_250 ,
sizeof( struct V_249 ) , NULL , NULL ) ;
F_106 ( V_49 ) ;
return V_13 ;
}
static long F_108 ( struct V_246 * V_246 , struct V_54 * V_55 , int V_255 ,
T_11 V_256 , T_11 V_165 )
{
if ( V_255 & V_257 )
return F_107 ( V_246 , V_55 , V_256 , V_165 ) ;
else if ( V_255 & V_258 ) {
if ( V_255 & V_259 )
return F_103 ( V_246 , V_55 , V_256 , V_165 , true ) ;
return F_103 ( V_246 , V_55 , V_256 , V_165 , false ) ;
}
return - V_251 ;
}
static void
F_109 ( struct V_1 * V_2 ,
struct V_143 * V_144 , bool V_260 )
{
if ( V_260 )
V_2 -> V_15 -> V_148 ( V_144 , V_261 ,
0 , NULL ) ;
else
V_2 -> V_15 -> V_148 ( V_144 , 0 , 0 , NULL ) ;
}
static void
F_110 ( struct V_143 * V_144 , T_8 V_71 ,
unsigned int V_149 , bool * V_150 )
{
V_71 &= 0xFF ;
if ( V_71 == V_262 )
return;
if ( V_71 == V_263 ) {
V_144 -> V_71 = V_264 ;
F_2 ( V_9 , L_55 ,
& V_144 -> V_265 ) ;
} else if ( V_71 == V_266 ) {
V_144 -> V_71 = V_267 ;
F_2 ( V_9 , L_56 ,
& V_144 -> V_265 ) ;
} else if ( V_71 == V_261 ) {
V_144 -> V_71 = V_268 ;
F_2 ( V_9 , L_57 ,
& V_144 -> V_265 ) ;
} else
V_144 -> V_71 = 0 ;
}
static void
F_111 ( struct V_143 * V_144 , T_8 V_71 ,
unsigned int V_149 , bool * V_150 )
{
char V_269 [ 5 ] = { 0 } ;
V_71 &= 0xFF ;
if ( V_71 == V_262 )
return;
V_144 -> V_71 = 0 ;
if ( V_71 & V_270 ) {
V_144 -> V_71 |= V_268 ;
strcat ( V_269 , L_58 ) ;
}
if ( V_71 & V_271 ) {
V_144 -> V_71 |= V_272 ;
strcat ( V_269 , L_59 ) ;
}
if ( V_71 & V_273 ) {
V_144 -> V_71 |= V_274 ;
strcat ( V_269 , L_60 ) ;
}
if ( ! V_144 -> V_71 )
strcat ( V_269 , L_61 ) ;
F_2 ( V_9 , L_62 , V_269 ,
& V_144 -> V_265 ) ;
}
static void
F_112 ( struct V_143 * V_144 , T_8 V_71 ,
unsigned int V_149 , bool * V_150 )
{
unsigned int V_275 = V_144 -> V_71 ;
F_111 ( V_144 , V_71 , V_149 , V_150 ) ;
if ( V_150 ) {
* V_150 = false ;
if ( V_275 == V_268 ) {
if ( V_144 -> V_71 == V_268 &&
( V_149 - V_144 -> V_149 > 0 ) )
* V_150 = true ;
else if ( V_144 -> V_71 == V_276 &&
( V_149 - V_144 -> V_149 > 1 ) )
* V_150 = true ;
else if ( V_144 -> V_71 == V_264 &&
( V_149 - V_144 -> V_149 > 1 ) )
* V_150 = true ;
else if ( V_144 -> V_71 == 0 &&
( V_149 - V_144 -> V_149 > 0 ) )
* V_150 = true ;
} else if ( V_275 == V_276 ) {
if ( V_144 -> V_71 == V_276 &&
( V_149 - V_144 -> V_149 > 0 ) )
* V_150 = true ;
else if ( V_144 -> V_71 == V_264 &&
( V_149 - V_144 -> V_149 > 1 ) )
* V_150 = true ;
}
V_144 -> V_149 = V_149 ;
}
}
static bool
F_113 ( T_8 V_71 )
{
return V_71 == V_261 ;
}
static bool
F_114 ( T_8 V_71 )
{
return ( V_71 & V_270 ) &&
! ( V_71 & V_273 ) ;
}
static T_12
F_115 ( T_3 V_71 )
{
if ( V_71 == V_266 )
return V_277 | V_278 ;
else if ( V_71 == V_261 )
return V_278 ;
else if ( V_71 == V_263 )
return V_279 | V_278 |
V_277 ;
return 0 ;
}
static char *
F_116 ( T_3 * V_219 , T_3 V_71 )
{
struct V_280 * V_37 ;
V_37 = F_45 ( sizeof( struct V_280 ) , V_99 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_281 . V_282 = F_66 ( * ( ( T_5 * ) V_219 ) ) ;
V_37 -> V_281 . V_283 = F_66 ( * ( ( T_5 * ) ( V_219 + 8 ) ) ) ;
V_37 -> V_281 . V_284 = F_115 ( V_71 ) ;
V_37 -> V_285 . V_187 = F_117 ( F_118
( struct V_280 , V_281 ) ) ;
V_37 -> V_285 . V_188 = F_67 ( sizeof( struct V_286 ) ) ;
V_37 -> V_285 . V_287 = F_117 ( F_118
( struct V_280 , V_288 ) ) ;
V_37 -> V_285 . V_289 = F_117 ( 4 ) ;
V_37 -> V_288 [ 0 ] = 'R' ;
V_37 -> V_288 [ 1 ] = 'q' ;
V_37 -> V_288 [ 2 ] = 'L' ;
V_37 -> V_288 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static char *
F_119 ( T_3 * V_219 , T_3 V_71 )
{
struct V_290 * V_37 ;
V_37 = F_45 ( sizeof( struct V_290 ) , V_99 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_281 . V_282 = F_66 ( * ( ( T_5 * ) V_219 ) ) ;
V_37 -> V_281 . V_283 = F_66 ( * ( ( T_5 * ) ( V_219 + 8 ) ) ) ;
V_37 -> V_281 . V_284 = F_115 ( V_71 ) ;
V_37 -> V_285 . V_187 = F_117 ( F_118
( struct V_290 , V_281 ) ) ;
V_37 -> V_285 . V_188 = F_67 ( sizeof( struct V_291 ) ) ;
V_37 -> V_285 . V_287 = F_117 ( F_118
( struct V_290 , V_288 ) ) ;
V_37 -> V_285 . V_289 = F_117 ( 4 ) ;
V_37 -> V_288 [ 0 ] = 'R' ;
V_37 -> V_288 [ 1 ] = 'q' ;
V_37 -> V_288 [ 2 ] = 'L' ;
V_37 -> V_288 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static T_4
F_120 ( void * V_37 , unsigned int * V_149 )
{
struct V_280 * V_292 = (struct V_280 * ) V_37 ;
* V_149 = 0 ;
if ( V_292 -> V_281 . V_293 & V_294 )
return V_262 ;
return F_32 ( V_292 -> V_281 . V_284 ) ;
}
static T_4
F_121 ( void * V_37 , unsigned int * V_149 )
{
struct V_290 * V_292 = (struct V_290 * ) V_37 ;
* V_149 = F_11 ( V_292 -> V_281 . V_295 ) ;
if ( V_292 -> V_281 . V_293 & V_294 )
return V_262 ;
return F_32 ( V_292 -> V_281 . V_284 ) ;
}
static unsigned int
F_122 ( struct V_197 * V_197 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_123 ( struct V_141 * V_142 )
{
return ! V_142 -> V_296 ;
}
