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
struct V_145 * V_146 = F_58 ( F_59 ( V_144 -> V_147 ) ) ;
struct V_1 * V_2 = F_60 ( V_144 -> V_148 ) -> V_52 -> V_2 ;
V_144 -> V_78 . V_85 = V_78 -> V_85 ;
V_144 -> V_78 . V_86 = V_78 -> V_86 ;
V_2 -> V_15 -> V_149 ( V_146 , V_73 , V_78 -> V_150 ,
& V_78 -> V_151 ) ;
V_146 -> V_152 = F_61 ( V_146 ) ;
}
static void
F_62 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
static int
F_63 ( const unsigned int V_50 , struct V_55 * V_56 ,
T_5 V_85 , T_5 V_86 ,
struct V_153 * V_154 )
{
int V_13 ;
unsigned int V_64 ;
struct V_155 * V_156 ;
V_13 = F_32 ( V_50 , V_56 , V_85 , V_86 ,
V_157 , true ,
NULL , 0 ,
( char * * ) & V_156 , & V_64 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_41 , V_13 ) ;
goto V_158;
}
if ( V_64 < sizeof( struct V_155 ) ) {
F_2 ( V_8 , L_42 ) ;
V_13 = - V_69 ;
goto V_158;
}
memcpy ( V_154 -> V_159 , V_156 -> V_160 , V_161 ) ;
V_158:
F_42 ( V_156 ) ;
return V_13 ;
}
static int
F_64 ( const unsigned int V_50 ,
struct V_143 * V_162 ,
struct V_143 * V_163 , T_5 V_164 ,
T_5 V_165 , T_5 V_166 )
{
int V_13 ;
unsigned int V_64 ;
struct V_153 * V_154 ;
struct V_167 * V_168 = NULL ;
struct V_55 * V_56 ;
int V_169 = 0 ;
bool V_170 = false ;
V_154 = F_65 ( sizeof( struct V_153 ) , V_101 ) ;
if ( V_154 == NULL )
return - V_94 ;
F_2 ( V_9 , L_43 ) ;
V_13 = F_63 ( V_50 , F_60 ( V_162 -> V_148 ) ,
V_162 -> V_78 . V_85 ,
V_162 -> V_78 . V_86 , V_154 ) ;
if ( V_13 )
goto V_171;
V_154 -> V_172 = F_66 ( 1 ) ;
V_154 -> V_173 = 0 ;
V_154 -> V_174 = 0 ;
V_56 = F_60 ( V_163 -> V_148 ) ;
while ( V_165 > 0 ) {
V_154 -> V_175 = F_67 ( V_164 ) ;
V_154 -> V_176 = F_67 ( V_166 ) ;
V_154 -> V_177 =
F_66 ( F_17 ( V_178 , V_165 , V_56 -> V_179 ) ) ;
V_13 = F_32 ( V_50 , V_56 , V_163 -> V_78 . V_85 ,
V_163 -> V_78 . V_86 , V_180 ,
true , ( char * ) V_154 ,
sizeof( struct V_153 ) , ( char * * ) & V_168 ,
& V_64 ) ;
if ( V_13 == 0 ) {
if ( V_64 !=
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
if ( F_33 ( V_168 -> V_182 ) >
F_33 ( V_154 -> V_177 ) ) {
F_2 ( V_8 , L_46 ) ;
V_13 = - V_181 ;
goto V_171;
}
if ( F_33 ( V_168 -> V_183 ) != 1 ) {
F_2 ( V_8 , L_47 ) ;
V_13 = - V_181 ;
goto V_171;
}
V_169 ++ ;
V_164 += F_33 ( V_168 -> V_182 ) ;
V_166 += F_33 ( V_168 -> V_182 ) ;
V_165 -= F_33 ( V_168 -> V_182 ) ;
F_2 ( V_9 , L_48 ,
F_33 ( V_168 -> V_183 ) ,
F_33 ( V_168 -> V_184 ) ,
F_33 ( V_168 -> V_182 ) ) ;
} else if ( V_13 == - V_69 ) {
if ( V_64 != sizeof( struct V_167 ) )
goto V_171;
F_2 ( V_9 , L_49 ,
F_33 ( V_168 -> V_183 ) ,
F_33 ( V_168 -> V_184 ) ,
F_33 ( V_168 -> V_182 ) ) ;
if ( ( V_169 != 0 ) || V_170 )
goto V_171;
if ( F_33 ( V_168 -> V_184 ) <
V_56 -> V_179 )
V_56 -> V_179 =
F_33 ( V_168 -> V_184 ) ;
else
goto V_171;
V_170 = true ;
} else
goto V_171;
}
V_171:
F_42 ( V_154 ) ;
return V_13 ;
}
static int
F_68 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
return F_69 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
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
return F_33 ( V_186 -> V_188 ) ;
}
static int
F_72 ( const unsigned int V_50 , struct V_77 * V_189 ,
struct V_190 * V_191 , unsigned int * V_192 ,
char * * V_37 , int * V_193 )
{
V_191 -> V_85 = V_189 -> V_85 ;
V_191 -> V_86 = V_189 -> V_86 ;
return F_73 ( V_50 , V_191 , V_192 , V_37 , V_193 ) ;
}
static int
F_74 ( const unsigned int V_50 , struct V_77 * V_189 ,
struct V_190 * V_191 , unsigned int * V_194 ,
struct V_195 * V_196 , unsigned long V_197 )
{
V_191 -> V_85 = V_189 -> V_85 ;
V_191 -> V_86 = V_189 -> V_86 ;
return F_75 ( V_50 , V_191 , V_194 , V_196 , V_197 ) ;
}
static bool F_76 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 , struct V_198 * V_198 , T_4 V_199 )
{
struct V_145 * V_200 ;
int V_13 ;
V_200 = F_58 ( V_198 ) ;
if ( ( V_200 -> V_201 & V_202 ) && V_199 )
return true ;
if ( ! ( V_200 -> V_201 & V_202 ) && ! V_199 )
return true ;
if ( V_56 -> V_203 )
return false ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_204 ,
true , & V_199 , 1 , NULL , NULL ) ;
if ( V_13 ) {
V_56 -> V_203 = true ;
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
F_77 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 , T_1 V_28 , bool V_205 )
{
T_9 V_206 = F_67 ( V_28 ) ;
struct V_198 * V_198 ;
V_198 = F_59 ( V_144 -> V_147 ) ;
if ( ! V_205 && ( V_28 > V_198 -> V_207 + 8192 ) ) {
T_4 V_208 = 1 ;
F_76 ( V_50 , V_56 , V_144 , V_198 , V_208 ) ;
}
return F_78 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_144 -> V_209 , & V_206 , false ) ;
}
static int
F_79 ( const unsigned int V_50 ,
struct V_143 * V_162 ,
struct V_143 * V_163 , T_5 V_164 ,
T_5 V_165 , T_5 V_166 )
{
int V_13 ;
unsigned int V_64 ;
char * V_168 = NULL ;
struct V_210 V_211 ;
struct V_55 * V_56 = F_60 ( V_163 -> V_148 ) ;
if ( ( F_33 ( V_56 -> V_212 . V_213 ) &
V_214 ) == 0 )
return - V_215 ;
V_211 . V_216 = V_162 -> V_78 . V_86 ;
V_211 . V_217 = V_162 -> V_78 . V_85 ;
V_211 . V_218 = F_67 ( V_164 ) ;
V_211 . V_219 = F_67 ( V_166 ) ;
V_211 . V_220 = F_67 ( V_165 ) ;
F_2 ( V_9 , L_51 ,
V_164 , V_166 , V_165 ) ;
V_13 = F_77 ( V_50 , V_56 , V_163 , V_166 + V_165 , false ) ;
if ( V_13 )
goto V_221;
V_13 = F_32 ( V_50 , V_56 , V_163 -> V_78 . V_85 ,
V_163 -> V_78 . V_86 ,
V_222 ,
true , ( char * ) & V_211 ,
sizeof( struct V_210 ) ,
( char * * ) & V_168 ,
& V_64 ) ;
if ( V_64 > 0 )
F_2 ( V_9 , L_52 ) ;
V_221:
return V_13 ;
}
static int
F_80 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 )
{
return F_81 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 ) ;
}
static int
F_82 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_143 * V_144 )
{
struct V_223 V_224 ;
char * V_168 = NULL ;
unsigned int V_64 ;
V_224 . V_225 = F_83 ( V_226 ) ;
V_224 . V_47 = 0 ;
V_224 . V_173 = 0 ;
return F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 ,
V_227 ,
true , ( char * ) & V_224 ,
sizeof( struct V_223 ) ,
( char * * ) & V_168 ,
& V_64 ) ;
}
static int
F_84 ( const unsigned int V_50 , struct V_55 * V_56 ,
const char * V_228 , struct V_90 * V_91 ,
struct V_77 * V_78 , T_10 V_229 ,
struct V_230 * V_231 )
{
T_2 * V_93 ;
int V_13 ;
T_4 V_73 = V_74 ;
struct V_75 V_76 ;
V_93 = F_41 ( V_228 , V_91 ) ;
if ( ! V_93 )
return - V_94 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 | V_232 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , V_93 , & V_73 , NULL , NULL ) ;
F_42 ( V_93 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_53 ) ;
return V_13 ;
}
V_231 -> V_233 = 0 ;
V_231 -> V_234 = 0 ;
V_13 = F_85 ( V_50 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 , 0 , V_231 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_54 ) ;
F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
return V_13 ;
}
static int
F_86 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 , T_10 V_229 ,
struct V_230 * V_231 )
{
return F_85 ( V_50 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 , 0 , V_231 ) ;
}
static int
F_87 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_77 * V_78 )
{
return F_38 ( V_50 , V_56 , V_78 -> V_85 , V_78 -> V_86 ) ;
}
static bool
F_88 ( char * V_37 , struct V_1 * V_2 , int V_235 )
{
struct V_25 * V_38 = (struct V_25 * ) V_37 ;
if ( V_38 -> V_46 != V_236 )
return false ;
if ( ! V_235 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_38 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_89 ( struct V_55 * V_56 , struct V_77 * V_78 ,
struct V_145 * V_146 )
{
if ( V_56 -> V_52 -> V_2 -> V_61 & V_237 )
return F_90 ( 0 , V_56 , V_146 -> V_238 ,
F_91 ( V_146 ) ) ;
return F_92 ( 0 , V_56 , V_78 -> V_85 ,
V_78 -> V_86 ,
F_93 ( V_146 ) ? 1 : 0 ) ;
}
static int
F_94 ( const unsigned int V_50 , struct V_55 * V_56 ,
struct V_239 * V_37 )
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
V_37 -> V_240 = V_241 ;
V_13 = F_95 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ,
V_37 ) ;
F_38 ( V_50 , V_56 , V_78 . V_85 , V_78 . V_86 ) ;
return V_13 ;
}
static bool
F_96 ( struct V_143 * V_242 , struct V_143 * V_243 )
{
return V_242 -> V_78 . V_85 == V_243 -> V_78 . V_85 &&
V_242 -> V_78 . V_86 == V_243 -> V_78 . V_86 ;
}
static int
F_97 ( const unsigned int V_50 , struct V_143 * V_144 , T_1 V_244 ,
T_1 V_235 , T_8 type , int V_245 , int V_246 , bool V_247 )
{
if ( V_246 && ! V_245 )
type = V_248 ;
return F_98 ( V_50 , F_60 ( V_144 -> V_148 ) ,
V_144 -> V_78 . V_85 , V_144 -> V_78 . V_86 ,
V_249 -> V_250 , V_235 , V_244 , type , V_247 ) ;
}
static void
F_99 ( struct V_198 * V_198 , struct V_77 * V_78 )
{
memcpy ( V_78 -> V_238 , F_58 ( V_198 ) -> V_238 , V_251 ) ;
}
static void
F_100 ( struct V_198 * V_198 , struct V_77 * V_78 )
{
memcpy ( F_58 ( V_198 ) -> V_238 , V_78 -> V_238 , V_251 ) ;
}
static void
F_101 ( struct V_77 * V_78 )
{
F_102 ( V_78 -> V_238 , V_251 ) ;
}
static int
F_103 ( const unsigned int V_50 , struct V_55 * V_56 ,
const char * V_92 , char * * V_252 ,
struct V_90 * V_91 )
{
int V_13 ;
T_2 * V_93 ;
T_4 V_73 = V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
struct V_253 * V_254 = NULL ;
struct V_255 * V_256 ;
unsigned int V_257 , V_258 ;
F_2 ( V_9 , L_55 , V_259 , V_92 ) ;
V_93 = F_41 ( V_92 , V_91 ) ;
if ( ! V_93 )
return - V_94 ;
V_76 . V_56 = V_56 ;
V_76 . V_79 = V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = 0 ;
V_76 . V_78 = & V_78 ;
V_76 . V_84 = false ;
V_13 = F_35 ( V_50 , & V_76 , V_93 , & V_73 , NULL , & V_254 ) ;
if ( ! V_13 || ! V_254 ) {
F_42 ( V_93 ) ;
return - V_33 ;
}
V_13 = 0 ;
V_256 = (struct V_255 * ) V_254 -> V_260 ;
V_257 = F_11 ( V_256 -> V_261 ) ;
V_258 = F_11 ( V_256 -> V_262 ) ;
* V_252 = F_104 (
( char * ) V_256 -> V_263 + V_258 ,
V_257 , true , V_91 -> V_264 ) ;
if ( ! ( * V_252 ) ) {
F_42 ( V_93 ) ;
return - V_94 ;
}
F_105 ( * V_252 , '/' ) ;
F_2 ( V_9 , L_56 , V_259 , * V_252 ) ;
F_42 ( V_93 ) ;
return V_13 ;
}
static long F_106 ( struct V_265 * V_265 , struct V_55 * V_56 ,
T_11 V_244 , T_11 V_165 , bool V_266 )
{
struct V_198 * V_198 ;
struct V_145 * V_200 ;
struct V_143 * V_144 = V_265 -> V_267 ;
struct V_268 V_269 ;
long V_13 ;
unsigned int V_50 ;
V_50 = F_107 () ;
V_198 = F_59 ( V_144 -> V_147 ) ;
V_200 = F_58 ( V_198 ) ;
if ( ! F_93 ( V_200 ) )
if ( V_266 == false )
return - V_215 ;
if ( ! ( V_200 -> V_201 & V_202 ) )
return - V_215 ;
if ( V_266 == false )
if ( F_108 ( V_198 ) < V_244 + V_165 )
return - V_215 ;
F_2 ( V_9 , L_57 , V_244 , V_165 ) ;
V_269 . V_270 = F_67 ( V_244 ) ;
V_269 . V_271 = F_67 ( V_244 + V_165 ) ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_272 ,
true , ( char * ) & V_269 ,
sizeof( struct V_268 ) , NULL , NULL ) ;
F_109 ( V_50 ) ;
return V_13 ;
}
static long F_110 ( struct V_265 * V_265 , struct V_55 * V_56 ,
T_11 V_244 , T_11 V_165 )
{
struct V_198 * V_198 ;
struct V_145 * V_200 ;
struct V_143 * V_144 = V_265 -> V_267 ;
struct V_268 V_269 ;
long V_13 ;
unsigned int V_50 ;
T_4 V_208 = 1 ;
V_50 = F_107 () ;
V_198 = F_59 ( V_144 -> V_147 ) ;
V_200 = F_58 ( V_198 ) ;
if ( ! F_76 ( V_50 , V_56 , V_144 , V_198 , V_208 ) )
return - V_215 ;
F_2 ( V_9 , L_57 , V_244 , V_165 ) ;
V_269 . V_270 = F_67 ( V_244 ) ;
V_269 . V_271 = F_67 ( V_244 + V_165 ) ;
V_13 = F_32 ( V_50 , V_56 , V_144 -> V_78 . V_85 ,
V_144 -> V_78 . V_86 , V_272 ,
true , ( char * ) & V_269 ,
sizeof( struct V_268 ) , NULL , NULL ) ;
F_109 ( V_50 ) ;
return V_13 ;
}
static long F_111 ( struct V_265 * V_265 , struct V_55 * V_56 ,
T_11 V_273 , T_11 V_165 , bool V_266 )
{
struct V_198 * V_198 ;
struct V_145 * V_200 ;
struct V_143 * V_144 = V_265 -> V_267 ;
long V_13 = - V_215 ;
unsigned int V_50 ;
V_50 = F_107 () ;
V_198 = F_59 ( V_144 -> V_147 ) ;
V_200 = F_58 ( V_198 ) ;
if ( ! F_93 ( V_200 ) )
if ( V_266 == false )
return - V_215 ;
if ( ( V_200 -> V_201 & V_202 ) == 0 ) {
if ( V_266 == true )
return 0 ;
else if ( F_108 ( V_198 ) >= V_273 + V_165 )
return 0 ;
else
return - V_215 ;
}
if ( ( V_266 == true ) || ( F_108 ( V_198 ) >= V_273 + V_165 ) ) {
if ( ( V_273 > 8192 ) || ( V_273 + V_165 + 8192 < F_108 ( V_198 ) ) )
return - V_215 ;
V_13 = F_76 ( V_50 , V_56 , V_144 , V_198 , false ) ;
}
F_109 ( V_50 ) ;
return V_13 ;
}
static long F_112 ( struct V_265 * V_265 , struct V_55 * V_56 , int V_274 ,
T_11 V_273 , T_11 V_165 )
{
if ( V_274 & V_275 )
return F_110 ( V_265 , V_56 , V_273 , V_165 ) ;
else if ( V_274 & V_276 ) {
if ( V_274 & V_277 )
return F_106 ( V_265 , V_56 , V_273 , V_165 , true ) ;
return F_106 ( V_265 , V_56 , V_273 , V_165 , false ) ;
} else if ( V_274 == V_277 )
return F_111 ( V_265 , V_56 , V_273 , V_165 , true ) ;
else if ( V_274 == 0 )
return F_111 ( V_265 , V_56 , V_273 , V_165 , false ) ;
return - V_215 ;
}
static void
F_113 ( struct V_1 * V_2 ,
struct V_145 * V_146 , bool V_278 )
{
if ( V_278 )
V_2 -> V_15 -> V_149 ( V_146 , V_279 ,
0 , NULL ) ;
else
V_2 -> V_15 -> V_149 ( V_146 , 0 , 0 , NULL ) ;
}
static void
F_114 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_150 , bool * V_151 )
{
V_73 &= 0xFF ;
if ( V_73 == V_280 )
return;
if ( V_73 == V_281 ) {
V_146 -> V_73 = V_282 ;
F_2 ( V_9 , L_58 ,
& V_146 -> V_283 ) ;
} else if ( V_73 == V_284 ) {
V_146 -> V_73 = V_285 ;
F_2 ( V_9 , L_59 ,
& V_146 -> V_283 ) ;
} else if ( V_73 == V_279 ) {
V_146 -> V_73 = V_286 ;
F_2 ( V_9 , L_60 ,
& V_146 -> V_283 ) ;
} else
V_146 -> V_73 = 0 ;
}
static void
F_115 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_150 , bool * V_151 )
{
char V_287 [ 5 ] = { 0 } ;
V_73 &= 0xFF ;
if ( V_73 == V_280 )
return;
V_146 -> V_73 = 0 ;
if ( V_73 & V_288 ) {
V_146 -> V_73 |= V_286 ;
strcat ( V_287 , L_61 ) ;
}
if ( V_73 & V_289 ) {
V_146 -> V_73 |= V_290 ;
strcat ( V_287 , L_62 ) ;
}
if ( V_73 & V_291 ) {
V_146 -> V_73 |= V_292 ;
strcat ( V_287 , L_63 ) ;
}
if ( ! V_146 -> V_73 )
strcat ( V_287 , L_64 ) ;
F_2 ( V_9 , L_65 , V_287 ,
& V_146 -> V_283 ) ;
}
static void
F_116 ( struct V_145 * V_146 , T_8 V_73 ,
unsigned int V_150 , bool * V_151 )
{
unsigned int V_293 = V_146 -> V_73 ;
F_115 ( V_146 , V_73 , V_150 , V_151 ) ;
if ( V_151 ) {
* V_151 = false ;
if ( V_293 == V_286 ) {
if ( V_146 -> V_73 == V_286 &&
( V_150 - V_146 -> V_150 > 0 ) )
* V_151 = true ;
else if ( V_146 -> V_73 == V_294 &&
( V_150 - V_146 -> V_150 > 1 ) )
* V_151 = true ;
else if ( V_146 -> V_73 == V_282 &&
( V_150 - V_146 -> V_150 > 1 ) )
* V_151 = true ;
else if ( V_146 -> V_73 == 0 &&
( V_150 - V_146 -> V_150 > 0 ) )
* V_151 = true ;
} else if ( V_293 == V_294 ) {
if ( V_146 -> V_73 == V_294 &&
( V_150 - V_146 -> V_150 > 0 ) )
* V_151 = true ;
else if ( V_146 -> V_73 == V_282 &&
( V_150 - V_146 -> V_150 > 1 ) )
* V_151 = true ;
}
V_146 -> V_150 = V_150 ;
}
}
static bool
F_117 ( T_8 V_73 )
{
return V_73 == V_279 ;
}
static bool
F_118 ( T_8 V_73 )
{
return ( V_73 & V_288 ) &&
! ( V_73 & V_291 ) ;
}
static T_12
F_119 ( T_3 V_73 )
{
if ( V_73 == V_284 )
return V_295 | V_296 ;
else if ( V_73 == V_279 )
return V_296 ;
else if ( V_73 == V_281 )
return V_297 | V_296 |
V_295 ;
return 0 ;
}
static char *
F_120 ( T_3 * V_238 , T_3 V_73 )
{
struct V_298 * V_37 ;
V_37 = F_45 ( sizeof( struct V_298 ) , V_101 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_299 . V_300 = F_67 ( * ( ( T_5 * ) V_238 ) ) ;
V_37 -> V_299 . V_301 = F_67 ( * ( ( T_5 * ) ( V_238 + 8 ) ) ) ;
V_37 -> V_299 . V_302 = F_119 ( V_73 ) ;
V_37 -> V_303 . V_187 = F_83 ( F_121
( struct V_298 , V_299 ) ) ;
V_37 -> V_303 . V_188 = F_66 ( sizeof( struct V_304 ) ) ;
V_37 -> V_303 . V_305 = F_83 ( F_121
( struct V_298 , V_306 ) ) ;
V_37 -> V_303 . V_307 = F_83 ( 4 ) ;
V_37 -> V_306 [ 0 ] = 'R' ;
V_37 -> V_306 [ 1 ] = 'q' ;
V_37 -> V_306 [ 2 ] = 'L' ;
V_37 -> V_306 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static char *
F_122 ( T_3 * V_238 , T_3 V_73 )
{
struct V_308 * V_37 ;
V_37 = F_45 ( sizeof( struct V_308 ) , V_101 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_299 . V_300 = F_67 ( * ( ( T_5 * ) V_238 ) ) ;
V_37 -> V_299 . V_301 = F_67 ( * ( ( T_5 * ) ( V_238 + 8 ) ) ) ;
V_37 -> V_299 . V_302 = F_119 ( V_73 ) ;
V_37 -> V_303 . V_187 = F_83 ( F_121
( struct V_308 , V_299 ) ) ;
V_37 -> V_303 . V_188 = F_66 ( sizeof( struct V_309 ) ) ;
V_37 -> V_303 . V_305 = F_83 ( F_121
( struct V_308 , V_306 ) ) ;
V_37 -> V_303 . V_307 = F_83 ( 4 ) ;
V_37 -> V_306 [ 0 ] = 'R' ;
V_37 -> V_306 [ 1 ] = 'q' ;
V_37 -> V_306 [ 2 ] = 'L' ;
V_37 -> V_306 [ 3 ] = 's' ;
return ( char * ) V_37 ;
}
static T_4
F_123 ( void * V_37 , unsigned int * V_150 )
{
struct V_298 * V_310 = (struct V_298 * ) V_37 ;
* V_150 = 0 ;
if ( V_310 -> V_299 . V_311 & V_312 )
return V_280 ;
return F_33 ( V_310 -> V_299 . V_302 ) ;
}
static T_4
F_124 ( void * V_37 , unsigned int * V_150 )
{
struct V_308 * V_310 = (struct V_308 * ) V_37 ;
* V_150 = F_11 ( V_310 -> V_299 . V_313 ) ;
if ( V_310 -> V_299 . V_311 & V_312 )
return V_280 ;
return F_33 ( V_310 -> V_299 . V_302 ) ;
}
static unsigned int
F_125 ( struct V_198 * V_198 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_126 ( struct V_143 * V_144 )
{
return ! V_144 -> V_314 ;
}
