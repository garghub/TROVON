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
if ( V_13 != 0 )
F_2 ( V_8 , L_5 , V_13 ) ;
else if ( V_63 < sizeof( struct V_64 ) ) {
F_2 ( V_8 , L_6 ) ;
V_13 = - V_68 ;
} else {
F_2 ( V_9 , L_7 ,
F_32 ( V_65 -> V_69 ) ) ;
F_2 ( V_9 , L_8 ,
F_33 ( V_65 -> V_70 ) ) ;
}
return V_13 ;
}
static void
F_34 ( const unsigned int V_49 , struct V_54 * V_55 )
{
int V_13 ;
T_2 V_71 = 0 ;
T_3 V_72 = V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = & V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , & V_71 , & V_72 , NULL , NULL ) ;
if ( V_13 )
return;
#ifdef F_36
F_30 ( V_49 , V_55 ) ;
#endif
F_37 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_86 ) ;
F_37 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_87 ) ;
F_37 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_88 ) ;
F_38 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ) ;
return;
}
static void
F_39 ( const unsigned int V_49 , struct V_54 * V_55 )
{
int V_13 ;
T_2 V_71 = 0 ;
T_3 V_72 = V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = & V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , & V_71 , & V_72 , NULL , NULL ) ;
if ( V_13 )
return;
F_37 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_86 ) ;
F_37 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_87 ) ;
F_38 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ) ;
return;
}
static int
F_40 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_89 * V_90 , const char * V_91 )
{
int V_13 ;
T_2 * V_92 ;
T_4 V_72 = V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
V_92 = F_41 ( V_91 , V_90 ) ;
if ( ! V_92 )
return - V_93 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = & V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , V_92 , & V_72 , NULL , NULL ) ;
if ( V_13 ) {
F_42 ( V_92 ) ;
return V_13 ;
}
V_13 = F_38 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ) ;
F_42 ( V_92 ) ;
return V_13 ;
}
static int
F_43 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_89 * V_90 , const char * V_91 ,
T_5 * V_94 , T_6 * V_95 )
{
* V_94 = F_33 ( V_95 -> V_96 ) ;
return 0 ;
}
static int
F_44 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_76 * V_77 , T_6 * V_95 )
{
int V_13 ;
struct V_97 * V_98 ;
V_98 = F_45 ( sizeof( struct V_97 ) + V_99 * 2 ,
V_100 ) ;
if ( V_98 == NULL )
return - V_93 ;
V_13 = F_46 ( V_49 , V_55 , V_77 -> V_84 , V_77 -> V_85 ,
V_98 ) ;
if ( ! V_13 )
F_47 ( V_95 , V_98 ) ;
F_42 ( V_98 ) ;
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
int V_101 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
F_51 ( & V_55 -> V_103 . V_104 . V_105 [ V_101 ] , 0 ) ;
F_51 ( & V_55 -> V_103 . V_104 . V_106 [ V_101 ] , 0 ) ;
}
#endif
}
static void
F_52 ( struct V_107 * V_108 , struct V_54 * V_55 )
{
F_53 ( V_108 , L_9 ) ;
if ( V_55 -> V_60 & V_109 )
F_53 ( V_108 , L_10 ) ;
if ( V_55 -> V_60 & V_110 )
F_53 ( V_108 , L_11 ) ;
if ( V_55 -> V_60 & V_111 )
F_53 ( V_108 , L_12 ) ;
if ( V_55 -> V_60 & V_112 )
F_53 ( V_108 , L_13 ) ;
if ( V_55 -> V_60 & V_113 )
F_53 ( V_108 , L_14 ) ;
if ( V_55 -> V_60 == 0 )
F_53 ( V_108 , L_15 ) ;
if ( V_55 -> V_114 & V_115 )
F_53 ( V_108 , L_16 ) ;
if ( V_55 -> V_114 & V_116 )
F_53 ( V_108 , L_17 ) ;
if ( V_55 -> V_114 & V_117 )
F_53 ( V_108 , L_18 ) ;
if ( V_55 -> V_114 & V_118 )
F_53 ( V_108 , L_19 ) ;
F_54 ( V_108 , L_20 , V_55 -> V_119 ) ;
if ( V_55 -> V_120 )
F_54 ( V_108 , L_21 ,
V_55 -> V_120 ) ;
}
static void
F_55 ( struct V_107 * V_108 , struct V_54 * V_55 )
{
#ifdef F_50
T_7 * V_121 = V_55 -> V_103 . V_104 . V_105 ;
T_7 * V_122 = V_55 -> V_103 . V_104 . V_106 ;
F_54 ( V_108 , L_22 ,
F_56 ( & V_121 [ V_123 ] ) ,
F_56 ( & V_122 [ V_123 ] ) ) ;
F_54 ( V_108 , L_23 ,
F_56 ( & V_121 [ V_124 ] ) ,
F_56 ( & V_122 [ V_124 ] ) ) ;
F_54 ( V_108 , L_24 ,
F_56 ( & V_121 [ V_125 ] ) ,
F_56 ( & V_122 [ V_125 ] ) ) ;
F_54 ( V_108 , L_25 ,
F_56 ( & V_121 [ V_126 ] ) ,
F_56 ( & V_122 [ V_126 ] ) ) ;
F_54 ( V_108 , L_26 ,
F_56 ( & V_121 [ V_127 ] ) ,
F_56 ( & V_122 [ V_127 ] ) ) ;
F_54 ( V_108 , L_27 ,
F_56 ( & V_121 [ V_128 ] ) ,
F_56 ( & V_122 [ V_128 ] ) ) ;
F_54 ( V_108 , L_28 ,
F_56 ( & V_121 [ V_129 ] ) ,
F_56 ( & V_122 [ V_129 ] ) ) ;
F_54 ( V_108 , L_29 ,
F_56 ( & V_121 [ V_130 ] ) ,
F_56 ( & V_122 [ V_130 ] ) ) ;
F_54 ( V_108 , L_30 ,
F_56 ( & V_121 [ V_131 ] ) ,
F_56 ( & V_122 [ V_131 ] ) ) ;
F_54 ( V_108 , L_31 ,
F_56 ( & V_121 [ V_132 ] ) ,
F_56 ( & V_122 [ V_132 ] ) ) ;
F_54 ( V_108 , L_32 ,
F_56 ( & V_121 [ V_133 ] ) ,
F_56 ( & V_122 [ V_133 ] ) ) ;
F_54 ( V_108 , L_33 ,
F_56 ( & V_121 [ V_134 ] ) ,
F_56 ( & V_122 [ V_134 ] ) ) ;
F_54 ( V_108 , L_34 ,
F_56 ( & V_121 [ V_135 ] ) ,
F_56 ( & V_122 [ V_135 ] ) ) ;
F_54 ( V_108 , L_35 ,
F_56 ( & V_121 [ V_136 ] ) ,
F_56 ( & V_122 [ V_136 ] ) ) ;
F_54 ( V_108 , L_36 ,
F_56 ( & V_121 [ V_137 ] ) ,
F_56 ( & V_122 [ V_137 ] ) ) ;
F_54 ( V_108 , L_37 ,
F_56 ( & V_121 [ V_138 ] ) ,
F_56 ( & V_122 [ V_138 ] ) ) ;
F_54 ( V_108 , L_38 ,
F_56 ( & V_121 [ V_139 ] ) ,
F_56 ( & V_122 [ V_139 ] ) ) ;
F_54 ( V_108 , L_39 ,
F_56 ( & V_121 [ V_140 ] ) ,
F_56 ( & V_122 [ V_140 ] ) ) ;
F_54 ( V_108 , L_40 ,
F_56 ( & V_121 [ V_141 ] ) ,
F_56 ( & V_122 [ V_141 ] ) ) ;
#endif
}
static void
F_57 ( struct V_142 * V_143 , struct V_76 * V_77 , T_8 V_72 )
{
struct V_144 * V_145 = F_58 ( V_143 -> V_146 -> V_147 ) ;
struct V_1 * V_2 = F_59 ( V_143 -> V_148 ) -> V_51 -> V_2 ;
V_143 -> V_77 . V_84 = V_77 -> V_84 ;
V_143 -> V_77 . V_85 = V_77 -> V_85 ;
V_2 -> V_15 -> V_149 ( V_145 , V_72 , V_77 -> V_150 ,
& V_77 -> V_151 ) ;
V_145 -> V_152 = F_60 ( V_145 ) ;
}
static void
F_61 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_76 * V_77 )
{
F_38 ( V_49 , V_55 , V_77 -> V_84 , V_77 -> V_85 ) ;
}
static int
F_62 ( const unsigned int V_49 , struct V_54 * V_55 ,
T_5 V_84 , T_5 V_85 ,
struct V_153 * V_154 )
{
int V_13 ;
unsigned int V_63 ;
struct V_155 * V_156 ;
V_13 = F_31 ( V_49 , V_55 , V_84 , V_85 ,
V_157 , true ,
NULL , 0 ,
( char * * ) & V_156 , & V_63 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_41 , V_13 ) ;
goto V_158;
}
if ( V_63 < sizeof( struct V_155 ) ) {
F_2 ( V_8 , L_42 ) ;
V_13 = - V_68 ;
goto V_158;
}
memcpy ( V_154 -> V_159 , V_156 -> V_160 , V_161 ) ;
V_158:
F_42 ( V_156 ) ;
return V_13 ;
}
static int
F_63 ( const unsigned int V_49 ,
struct V_142 * V_162 ,
struct V_142 * V_163 , T_5 V_164 ,
T_5 V_165 , T_5 V_166 )
{
int V_13 ;
unsigned int V_63 ;
struct V_153 * V_154 ;
struct V_167 * V_168 = NULL ;
struct V_54 * V_55 ;
int V_169 = 0 ;
bool V_170 = false ;
V_154 = F_64 ( sizeof( struct V_153 ) , V_100 ) ;
if ( V_154 == NULL )
return - V_93 ;
F_2 ( V_9 , L_43 ) ;
V_13 = F_62 ( V_49 , F_59 ( V_162 -> V_148 ) ,
V_162 -> V_77 . V_84 ,
V_162 -> V_77 . V_85 , V_154 ) ;
if ( V_13 )
goto V_171;
V_154 -> V_172 = F_65 ( 1 ) ;
V_154 -> V_173 = 0 ;
V_154 -> V_174 = 0 ;
V_55 = F_59 ( V_163 -> V_148 ) ;
while ( V_165 > 0 ) {
V_154 -> V_175 = F_66 ( V_164 ) ;
V_154 -> V_176 = F_66 ( V_166 ) ;
V_154 -> V_177 =
F_67 ( F_17 ( V_178 , V_165 , V_55 -> V_179 ) ) ;
V_13 = F_31 ( V_49 , V_55 , V_163 -> V_77 . V_84 ,
V_163 -> V_77 . V_85 , V_180 ,
true , ( char * ) V_154 ,
sizeof( struct V_153 ) , ( char * * ) & V_168 ,
& V_63 ) ;
if ( V_13 == 0 ) {
if ( V_63 !=
sizeof( struct V_167 ) ) {
F_2 ( V_8 , L_44 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( V_168 -> V_182 == 0 ) {
F_2 ( V_9 , L_45 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( F_32 ( V_168 -> V_182 ) >
F_32 ( V_154 -> V_177 ) ) {
F_2 ( V_8 , L_46 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( F_32 ( V_168 -> V_183 ) != 1 ) {
F_2 ( V_8 , L_47 ) ;
V_13 = - V_181 ;
goto V_171;
}
V_169 ++ ;
V_164 += F_32 ( V_168 -> V_182 ) ;
V_166 += F_32 ( V_168 -> V_182 ) ;
V_165 -= F_32 ( V_168 -> V_182 ) ;
F_2 ( V_9 , L_48 ,
F_32 ( V_168 -> V_183 ) ,
F_32 ( V_168 -> V_184 ) ,
F_32 ( V_168 -> V_182 ) ) ;
} else if ( V_13 == - V_68 ) {
if ( V_63 != sizeof( struct V_167 ) )
goto V_171;
F_2 ( V_9 , L_49 ,
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
F_42 ( V_154 ) ;
return V_13 ;
}
static int
F_68 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_76 * V_77 )
{
return F_69 ( V_49 , V_55 , V_77 -> V_84 , V_77 -> V_85 ) ;
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
F_72 ( const unsigned int V_49 , struct V_76 * V_189 ,
struct V_190 * V_191 , unsigned int * V_192 ,
char * * V_37 , int * V_193 )
{
V_191 -> V_84 = V_189 -> V_84 ;
V_191 -> V_85 = V_189 -> V_85 ;
return F_73 ( V_49 , V_191 , V_192 , V_37 , V_193 ) ;
}
static int
F_74 ( const unsigned int V_49 , struct V_76 * V_189 ,
struct V_190 * V_191 , unsigned int * V_194 ,
struct V_195 * V_196 , unsigned long V_197 )
{
V_191 -> V_84 = V_189 -> V_84 ;
V_191 -> V_85 = V_189 -> V_85 ;
return F_75 ( V_49 , V_191 , V_194 , V_196 , V_197 ) ;
}
static bool F_76 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_142 * V_143 , struct V_198 * V_198 , T_4 V_199 )
{
struct V_144 * V_200 ;
int V_13 ;
V_200 = F_58 ( V_198 ) ;
if ( ( V_200 -> V_201 & V_202 ) && V_199 )
return true ;
if ( ! ( V_200 -> V_201 & V_202 ) && ! V_199 )
return true ;
if ( V_55 -> V_203 )
return false ;
V_13 = F_31 ( V_49 , V_55 , V_143 -> V_77 . V_84 ,
V_143 -> V_77 . V_85 , V_204 ,
true , & V_199 , 1 , NULL , NULL ) ;
if ( V_13 ) {
V_55 -> V_203 = true ;
F_2 ( V_9 , L_50 , V_13 ) ;
return false ;
}
if ( V_199 )
V_200 -> V_201 |= V_202 ;
else
V_200 -> V_201 &= ( ~ V_202 ) ;
return true ;
}
static int
F_77 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_142 * V_143 , T_1 V_28 , bool V_205 )
{
T_9 V_206 = F_66 ( V_28 ) ;
struct V_198 * V_198 ;
V_198 = V_143 -> V_146 -> V_147 ;
if ( ! V_205 && ( V_28 > V_198 -> V_207 + 8192 ) ) {
T_4 V_208 = 1 ;
F_76 ( V_49 , V_55 , V_143 , V_198 , V_208 ) ;
}
return F_78 ( V_49 , V_55 , V_143 -> V_77 . V_84 ,
V_143 -> V_77 . V_85 , V_143 -> V_209 , & V_206 , false ) ;
}
static int
F_79 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_142 * V_143 )
{
return F_80 ( V_49 , V_55 , V_143 -> V_77 . V_84 ,
V_143 -> V_77 . V_85 ) ;
}
static int
F_81 ( const unsigned int V_49 , struct V_54 * V_55 ,
const char * V_210 , struct V_89 * V_90 ,
struct V_76 * V_77 , T_10 V_211 ,
struct V_212 * V_213 )
{
T_2 * V_92 ;
int V_13 ;
T_4 V_72 = V_73 ;
struct V_74 V_75 ;
V_92 = F_41 ( V_210 , V_90 ) ;
if ( ! V_92 )
return - V_93 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 | V_214 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , V_92 , & V_72 , NULL , NULL ) ;
F_42 ( V_92 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_51 ) ;
return V_13 ;
}
V_213 -> V_215 = 0 ;
V_213 -> V_216 = 0 ;
V_13 = F_82 ( V_49 , V_55 , V_77 -> V_84 ,
V_77 -> V_85 , 0 , V_213 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_52 ) ;
F_38 ( V_49 , V_55 , V_77 -> V_84 , V_77 -> V_85 ) ;
}
return V_13 ;
}
static int
F_83 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_76 * V_77 , T_10 V_211 ,
struct V_212 * V_213 )
{
return F_82 ( V_49 , V_55 , V_77 -> V_84 ,
V_77 -> V_85 , 0 , V_213 ) ;
}
static int
F_84 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_76 * V_77 )
{
return F_38 ( V_49 , V_55 , V_77 -> V_84 , V_77 -> V_85 ) ;
}
static bool
F_85 ( char * V_37 , struct V_1 * V_2 , int V_217 )
{
struct V_25 * V_38 = (struct V_25 * ) V_37 ;
if ( V_38 -> V_45 != V_218 )
return false ;
if ( ! V_217 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_38 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_86 ( struct V_54 * V_55 , struct V_76 * V_77 ,
struct V_144 * V_145 )
{
if ( V_55 -> V_51 -> V_2 -> V_60 & V_219 )
return F_87 ( 0 , V_55 , V_145 -> V_220 ,
F_88 ( V_145 ) ) ;
return F_89 ( 0 , V_55 , V_77 -> V_84 ,
V_77 -> V_85 ,
F_90 ( V_145 ) ? 1 : 0 ) ;
}
static int
F_91 ( const unsigned int V_49 , struct V_54 * V_55 ,
struct V_221 * V_37 )
{
int V_13 ;
T_2 V_71 = 0 ;
T_3 V_72 = V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = & V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , & V_71 , & V_72 , NULL , NULL ) ;
if ( V_13 )
return V_13 ;
V_37 -> V_222 = V_223 ;
V_13 = F_92 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ,
V_37 ) ;
F_38 ( V_49 , V_55 , V_77 . V_84 , V_77 . V_85 ) ;
return V_13 ;
}
static bool
F_93 ( struct V_142 * V_224 , struct V_142 * V_225 )
{
return V_224 -> V_77 . V_84 == V_225 -> V_77 . V_84 &&
V_224 -> V_77 . V_85 == V_225 -> V_77 . V_85 ;
}
static int
F_94 ( const unsigned int V_49 , struct V_142 * V_143 , T_1 V_226 ,
T_1 V_217 , T_8 type , int V_227 , int V_228 , bool V_229 )
{
if ( V_228 && ! V_227 )
type = V_230 ;
return F_95 ( V_49 , F_59 ( V_143 -> V_148 ) ,
V_143 -> V_77 . V_84 , V_143 -> V_77 . V_85 ,
V_231 -> V_232 , V_217 , V_226 , type , V_229 ) ;
}
static void
F_96 ( struct V_198 * V_198 , struct V_76 * V_77 )
{
memcpy ( V_77 -> V_220 , F_58 ( V_198 ) -> V_220 , V_233 ) ;
}
static void
F_97 ( struct V_198 * V_198 , struct V_76 * V_77 )
{
memcpy ( F_58 ( V_198 ) -> V_220 , V_77 -> V_220 , V_233 ) ;
}
static void
F_98 ( struct V_76 * V_77 )
{
F_99 ( V_77 -> V_220 , V_233 ) ;
}
static int
F_100 ( const unsigned int V_49 , struct V_54 * V_55 ,
const char * V_91 , char * * V_234 ,
struct V_89 * V_90 )
{
int V_13 ;
T_2 * V_92 ;
T_4 V_72 = V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
struct V_235 * V_236 = NULL ;
struct V_237 * V_238 ;
unsigned int V_239 , V_240 ;
F_2 ( V_9 , L_53 , V_241 , V_91 ) ;
V_92 = F_41 ( V_91 , V_90 ) ;
if ( ! V_92 )
return - V_93 ;
V_75 . V_55 = V_55 ;
V_75 . V_78 = V_79 ;
V_75 . V_80 = V_81 ;
V_75 . V_82 = 0 ;
V_75 . V_77 = & V_77 ;
V_75 . V_83 = false ;
V_13 = F_35 ( V_49 , & V_75 , V_92 , & V_72 , NULL , & V_236 ) ;
if ( ! V_13 || ! V_236 ) {
F_42 ( V_92 ) ;
return - V_33 ;
}
V_13 = 0 ;
V_238 = (struct V_237 * ) V_236 -> V_242 ;
V_239 = F_11 ( V_238 -> V_243 ) ;
V_240 = F_11 ( V_238 -> V_244 ) ;
* V_234 = F_101 (
( char * ) V_238 -> V_245 + V_240 ,
V_239 , true , V_90 -> V_246 ) ;
if ( ! ( * V_234 ) ) {
F_42 ( V_92 ) ;
return - V_93 ;
}
F_102 ( * V_234 , '/' ) ;
F_2 ( V_9 , L_54 , V_241 , * V_234 ) ;
F_42 ( V_92 ) ;
return V_13 ;
}
static long F_103 ( struct V_247 * V_247 , struct V_54 * V_55 ,
T_11 V_226 , T_11 V_165 , bool V_248 )
{
struct V_198 * V_198 ;
struct V_144 * V_200 ;
struct V_142 * V_143 = V_247 -> V_249 ;
struct V_250 V_251 ;
long V_13 ;
unsigned int V_49 ;
V_49 = F_104 () ;
V_198 = V_143 -> V_146 -> V_147 ;
V_200 = F_58 ( V_198 ) ;
if ( ! F_90 ( V_200 ) )
if ( V_248 == false )
return - V_252 ;
if ( ! ( V_200 -> V_201 & V_202 ) )
return - V_252 ;
if ( V_248 == false )
if ( F_105 ( V_198 ) < V_226 + V_165 )
return - V_252 ;
F_2 ( V_9 , L_55 , V_226 , V_165 ) ;
V_251 . V_253 = F_66 ( V_226 ) ;
V_251 . V_254 = F_66 ( V_226 + V_165 ) ;
V_13 = F_31 ( V_49 , V_55 , V_143 -> V_77 . V_84 ,
V_143 -> V_77 . V_85 , V_255 ,
true , ( char * ) & V_251 ,
sizeof( struct V_250 ) , NULL , NULL ) ;
F_106 ( V_49 ) ;
return V_13 ;
}
static long F_107 ( struct V_247 * V_247 , struct V_54 * V_55 ,
T_11 V_226 , T_11 V_165 )
{
struct V_198 * V_198 ;
struct V_144 * V_200 ;
struct V_142 * V_143 = V_247 -> V_249 ;
struct V_250 V_251 ;
long V_13 ;
unsigned int V_49 ;
T_4 V_208 = 1 ;
V_49 = F_104 () ;
V_198 = V_143 -> V_146 -> V_147 ;
V_200 = F_58 ( V_198 ) ;
if ( ! F_76 ( V_49 , V_55 , V_143 , V_198 , V_208 ) )
return - V_252 ;
F_2 ( V_9 , L_55 , V_226 , V_165 ) ;
V_251 . V_253 = F_66 ( V_226 ) ;
V_251 . V_254 = F_66 ( V_226 + V_165 ) ;
V_13 = F_31 ( V_49 , V_55 , V_143 -> V_77 . V_84 ,
V_143 -> V_77 . V_85 , V_255 ,
true , ( char * ) & V_251 ,
sizeof( struct V_250 ) , NULL , NULL ) ;
F_106 ( V_49 ) ;
return V_13 ;
}
static long F_108 ( struct V_247 * V_247 , struct V_54 * V_55 , int V_256 ,
T_11 V_257 , T_11 V_165 )
{
if ( V_256 & V_258 )
return F_107 ( V_247 , V_55 , V_257 , V_165 ) ;
else if ( V_256 & V_259 ) {
if ( V_256 & V_260 )
return F_103 ( V_247 , V_55 , V_257 , V_165 , true ) ;
return F_103 ( V_247 , V_55 , V_257 , V_165 , false ) ;
}
return - V_252 ;
}
static void
F_109 ( struct V_1 * V_2 ,
struct V_144 * V_145 , bool V_261 )
{
if ( V_261 )
V_2 -> V_15 -> V_149 ( V_145 , V_262 ,
0 , NULL ) ;
else
V_2 -> V_15 -> V_149 ( V_145 , 0 , 0 , NULL ) ;
}
static void
F_110 ( struct V_144 * V_145 , T_8 V_72 ,
unsigned int V_150 , bool * V_151 )
{
V_72 &= 0xFF ;
if ( V_72 == V_263 )
return;
if ( V_72 == V_264 ) {
V_145 -> V_72 = V_265 ;
F_2 ( V_9 , L_56 ,
& V_145 -> V_266 ) ;
} else if ( V_72 == V_267 ) {
V_145 -> V_72 = V_268 ;
F_2 ( V_9 , L_57 ,
& V_145 -> V_266 ) ;
} else if ( V_72 == V_262 ) {
V_145 -> V_72 = V_269 ;
F_2 ( V_9 , L_58 ,
& V_145 -> V_266 ) ;
} else
V_145 -> V_72 = 0 ;
}
static void
F_111 ( struct V_144 * V_145 , T_8 V_72 ,
unsigned int V_150 , bool * V_151 )
{
char V_270 [ 5 ] = { 0 } ;
V_72 &= 0xFF ;
if ( V_72 == V_263 )
return;
V_145 -> V_72 = 0 ;
if ( V_72 & V_271 ) {
V_145 -> V_72 |= V_269 ;
strcat ( V_270 , L_59 ) ;
}
if ( V_72 & V_272 ) {
V_145 -> V_72 |= V_273 ;
strcat ( V_270 , L_60 ) ;
}
if ( V_72 & V_274 ) {
V_145 -> V_72 |= V_275 ;
strcat ( V_270 , L_61 ) ;
}
if ( ! V_145 -> V_72 )
strcat ( V_270 , L_62 ) ;
F_2 ( V_9 , L_63 , V_270 ,
& V_145 -> V_266 ) ;
}
static void
F_112 ( struct V_144 * V_145 , T_8 V_72 ,
unsigned int V_150 , bool * V_151 )
{
unsigned int V_276 = V_145 -> V_72 ;
F_111 ( V_145 , V_72 , V_150 , V_151 ) ;
if ( V_151 ) {
* V_151 = false ;
if ( V_276 == V_269 ) {
if ( V_145 -> V_72 == V_269 &&
( V_150 - V_145 -> V_150 > 0 ) )
* V_151 = true ;
else if ( V_145 -> V_72 == V_277 &&
( V_150 - V_145 -> V_150 > 1 ) )
* V_151 = true ;
else if ( V_145 -> V_72 == V_265 &&
( V_150 - V_145 -> V_150 > 1 ) )
* V_151 = true ;
else if ( V_145 -> V_72 == 0 &&
( V_150 - V_145 -> V_150 > 0 ) )
* V_151 = true ;
} else if ( V_276 == V_277 ) {
if ( V_145 -> V_72 == V_277 &&
( V_150 - V_145 -> V_150 > 0 ) )
* V_151 = true ;
else if ( V_145 -> V_72 == V_265 &&
( V_150 - V_145 -> V_150 > 1 ) )
* V_151 = true ;
}
V_145 -> V_150 = V_150 ;
}
}
static bool
F_113 ( T_8 V_72 )
{
return V_72 == V_262 ;
}
static bool
F_114 ( T_8 V_72 )
{
return ( V_72 & V_271 ) &&
! ( V_72 & V_274 ) ;
}
static T_12
F_115 ( T_3 V_72 )
{
if ( V_72 == V_267 )
return V_278 | V_279 ;
else if ( V_72 == V_262 )
return V_279 ;
else if ( V_72 == V_264 )
return V_280 | V_279 |
V_278 ;
return 0 ;
}
static char *
F_116 ( T_3 * V_220 , T_3 V_72 )
{
struct V_281 * V_37 ;
V_37 = F_45 ( sizeof( struct V_281 ) , V_100 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_282 . V_283 = F_66 ( * ( ( T_5 * ) V_220 ) ) ;
V_37 -> V_282 . V_284 = F_66 ( * ( ( T_5 * ) ( V_220 + 8 ) ) ) ;
V_37 -> V_282 . V_285 = F_115 ( V_72 ) ;
V_37 -> V_286 . V_187 = F_117 ( F_118
( struct V_281 , V_282 ) ) ;
V_37 -> V_286 . V_188 = F_67 ( sizeof( struct V_287 ) ) ;
V_37 -> V_286 . V_288 = F_117 ( F_118
( struct V_281 , V_289 ) ) ;
V_37 -> V_286 . V_290 = F_117 ( 4 ) ;
V_37 -> V_289 [ 0 ] = 'R' ;
V_37 -> V_289 [ 1 ] = 'q' ;
V_37 -> V_289 [ 2 ] = 'L' ;
V_37 -> V_289 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static char *
F_119 ( T_3 * V_220 , T_3 V_72 )
{
struct V_291 * V_37 ;
V_37 = F_45 ( sizeof( struct V_291 ) , V_100 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_282 . V_283 = F_66 ( * ( ( T_5 * ) V_220 ) ) ;
V_37 -> V_282 . V_284 = F_66 ( * ( ( T_5 * ) ( V_220 + 8 ) ) ) ;
V_37 -> V_282 . V_285 = F_115 ( V_72 ) ;
V_37 -> V_286 . V_187 = F_117 ( F_118
( struct V_291 , V_282 ) ) ;
V_37 -> V_286 . V_188 = F_67 ( sizeof( struct V_292 ) ) ;
V_37 -> V_286 . V_288 = F_117 ( F_118
( struct V_291 , V_289 ) ) ;
V_37 -> V_286 . V_290 = F_117 ( 4 ) ;
V_37 -> V_289 [ 0 ] = 'R' ;
V_37 -> V_289 [ 1 ] = 'q' ;
V_37 -> V_289 [ 2 ] = 'L' ;
V_37 -> V_289 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static T_4
F_120 ( void * V_37 , unsigned int * V_150 )
{
struct V_281 * V_293 = (struct V_281 * ) V_37 ;
* V_150 = 0 ;
if ( V_293 -> V_282 . V_294 & V_295 )
return V_263 ;
return F_32 ( V_293 -> V_282 . V_285 ) ;
}
static T_4
F_121 ( void * V_37 , unsigned int * V_150 )
{
struct V_291 * V_293 = (struct V_291 * ) V_37 ;
* V_150 = F_11 ( V_293 -> V_282 . V_296 ) ;
if ( V_293 -> V_282 . V_294 & V_295 )
return V_263 ;
return F_32 ( V_293 -> V_282 . V_285 ) ;
}
static unsigned int
F_122 ( struct V_198 * V_198 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_123 ( struct V_142 * V_143 )
{
return ! V_143 -> V_297 ;
}
