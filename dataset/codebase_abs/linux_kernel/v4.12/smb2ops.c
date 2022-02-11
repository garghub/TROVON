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
if ( V_10 ) {
V_2 -> V_7 = true ;
V_2 -> V_5 = 1 ;
} else
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , const unsigned int V_11 ,
const int V_12 )
{
int * V_13 , V_14 = 0 ;
F_4 ( & V_2 -> V_15 ) ;
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_12 ) ;
* V_13 += V_11 ;
if ( * V_13 > 65000 ) {
* V_13 = 65000 ;
F_5 ( V_18 L_3 ) ;
}
V_2 -> V_19 -- ;
if ( V_2 -> V_19 == 0 && ( V_12 & V_20 ) != V_21 )
V_14 = F_1 ( V_2 ) ;
else if ( V_2 -> V_19 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_22 ) ;
if ( V_14 )
F_8 ( V_2 ) ;
}
static void
F_9 ( struct V_1 * V_2 , const int V_13 )
{
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 = V_13 ;
F_6 ( & V_2 -> V_15 ) ;
}
static int *
F_10 ( struct V_1 * V_2 , const int V_12 )
{
switch ( V_12 ) {
case V_23 :
return & V_2 -> V_4 ;
case V_24 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_11 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_12 ( V_26 -> V_29 ) ;
return F_13 ( V_28 -> V_30 ) ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int * V_32 , unsigned int * V_3 )
{
int V_14 = 0 ;
unsigned int V_33 ;
F_4 ( & V_2 -> V_15 ) ;
while ( 1 ) {
if ( V_2 -> V_3 <= 0 ) {
F_6 ( & V_2 -> V_15 ) ;
F_15 ( V_2 ) ;
V_14 = F_16 ( V_2 -> V_22 ,
F_17 ( V_2 , & V_2 -> V_3 ) ) ;
F_18 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_4 ( & V_2 -> V_15 ) ;
} else {
if ( V_2 -> V_34 == V_35 ) {
F_6 ( & V_2 -> V_15 ) ;
return - V_36 ;
}
V_33 = V_2 -> V_3 ;
if ( V_33 == 1 ) {
* V_32 = V_37 ;
* V_3 = 0 ;
break;
}
V_33 -- ;
* V_32 = F_19 (unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE) ;
* V_3 = F_20 ( * V_32 , V_37 ) ;
V_2 -> V_3 -= * V_3 ;
V_2 -> V_19 ++ ;
break;
}
}
F_6 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static T_1
F_21 ( struct V_1 * V_2 )
{
T_1 V_26 ;
F_4 ( & V_38 ) ;
V_26 = V_2 -> V_39 ++ ;
F_6 ( & V_38 ) ;
return V_26 ;
}
static struct V_25 *
F_22 ( struct V_1 * V_2 , char * V_40 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 = F_12 ( V_40 ) ;
T_1 V_41 = F_23 ( V_28 -> V_42 ) ;
if ( V_28 -> V_43 == V_44 ) {
F_2 ( V_8 , L_4 ) ;
return NULL ;
}
F_4 ( & V_38 ) ;
F_24 (mid, &server->pending_mid_q, qhead) {
if ( ( V_26 -> V_26 == V_41 ) &&
( V_26 -> V_45 == V_46 ) &&
( V_26 -> V_47 == V_28 -> V_48 ) ) {
F_6 ( & V_38 ) ;
return V_26 ;
}
}
F_6 ( & V_38 ) ;
return NULL ;
}
static void
F_25 ( void * V_40 )
{
#ifdef F_26
struct V_27 * V_28 = F_12 ( V_40 ) ;
F_2 ( V_8 , L_5 ,
V_28 -> V_48 , V_28 -> V_49 , V_28 -> V_50 , V_28 -> V_42 ,
V_28 -> V_51 ) ;
F_2 ( V_8 , L_6 , V_40 , F_27 ( V_40 ) ) ;
#endif
}
static bool
F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_52 == 0 ;
}
static int
F_29 ( const unsigned int V_53 , struct V_54 * V_55 )
{
int V_14 ;
V_55 -> V_2 -> V_39 = 0 ;
V_14 = F_30 ( V_53 , V_55 ) ;
if ( V_14 == - V_56 )
V_14 = - V_57 ;
return V_14 ;
}
static unsigned int
F_31 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_62 ;
V_62 = V_61 -> V_62 ? V_61 -> V_62 : V_63 ;
V_62 = F_19 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_62 = F_19 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_62 ;
}
static unsigned int
F_32 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_66 ;
V_66 = V_61 -> V_66 ? V_61 -> V_66 : V_63 ;
V_66 = F_19 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_66 = F_19 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_66 ;
}
static int
F_33 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
unsigned int V_67 = 0 ;
struct V_68 * V_69 ;
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_71 , true ,
false ,
NULL , 0 ,
( char * * ) & V_69 , & V_67 ) ;
if ( V_14 != 0 )
F_2 ( V_8 , L_7 , V_14 ) ;
else if ( V_67 < sizeof( struct V_68 ) ) {
F_2 ( V_8 , L_8 ) ;
V_14 = - V_72 ;
} else {
F_2 ( V_9 , L_9 ,
F_35 ( V_69 -> V_73 ) ) ;
F_2 ( V_9 , L_10 ,
F_23 ( V_69 -> V_74 ) ) ;
}
F_36 ( V_69 ) ;
return V_14 ;
}
static void
F_37 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
#ifdef F_39
F_33 ( V_53 , V_59 ) ;
#endif
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_92 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static void
F_42 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static int
F_43 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_96 = F_44 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
if ( V_14 ) {
F_36 ( V_96 ) ;
return V_14 ;
}
V_14 = F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
F_36 ( V_96 ) ;
return V_14 ;
}
static int
F_45 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 ,
T_5 * V_98 , T_6 * V_99 )
{
* V_98 = F_23 ( V_99 -> V_100 ) ;
return 0 ;
}
static int
F_46 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_6 * V_99 )
{
int V_14 ;
struct V_101 * V_102 ;
V_102 = F_47 ( sizeof( struct V_101 ) + V_103 * 2 ,
V_104 ) ;
if ( V_102 == NULL )
return - V_97 ;
V_14 = F_48 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ,
V_102 ) ;
if ( ! V_14 )
F_49 ( V_99 , V_102 ) ;
F_36 ( V_102 ) ;
return V_14 ;
}
static bool
F_50 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_51 ( struct V_58 * V_59 )
{
#ifdef F_52
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
F_53 ( & V_59 -> V_107 . V_108 . V_109 [ V_105 ] , 0 ) ;
F_53 ( & V_59 -> V_107 . V_108 . V_110 [ V_105 ] , 0 ) ;
}
#endif
}
static void
F_54 ( struct V_111 * V_112 , struct V_58 * V_59 )
{
F_55 ( V_112 , L_11 ) ;
if ( V_59 -> V_64 & V_113 )
F_55 ( V_112 , L_12 ) ;
if ( V_59 -> V_64 & V_114 )
F_55 ( V_112 , L_13 ) ;
if ( V_59 -> V_64 & V_115 )
F_55 ( V_112 , L_14 ) ;
if ( V_59 -> V_64 & V_116 )
F_55 ( V_112 , L_15 ) ;
if ( V_59 -> V_64 & V_117 )
F_55 ( V_112 , L_16 ) ;
if ( V_59 -> V_64 == 0 )
F_55 ( V_112 , L_17 ) ;
if ( V_59 -> V_118 & V_119 )
F_55 ( V_112 , L_18 ) ;
if ( V_59 -> V_118 & V_120 )
F_55 ( V_112 , L_19 ) ;
if ( V_59 -> V_118 & V_121 )
F_55 ( V_112 , L_20 ) ;
if ( V_59 -> V_118 & V_122 )
F_55 ( V_112 , L_21 ) ;
F_56 ( V_112 , L_22 , V_59 -> V_123 ) ;
if ( V_59 -> V_124 )
F_56 ( V_112 , L_23 ,
V_59 -> V_124 ) ;
}
static void
F_57 ( struct V_111 * V_112 , struct V_58 * V_59 )
{
#ifdef F_52
T_7 * V_125 = V_59 -> V_107 . V_108 . V_109 ;
T_7 * V_126 = V_59 -> V_107 . V_108 . V_110 ;
F_56 ( V_112 , L_24 ,
F_58 ( & V_125 [ V_127 ] ) ,
F_58 ( & V_126 [ V_127 ] ) ) ;
F_56 ( V_112 , L_25 ,
F_58 ( & V_125 [ V_128 ] ) ,
F_58 ( & V_126 [ V_128 ] ) ) ;
F_56 ( V_112 , L_26 ,
F_58 ( & V_125 [ V_129 ] ) ,
F_58 ( & V_126 [ V_129 ] ) ) ;
F_56 ( V_112 , L_27 ,
F_58 ( & V_125 [ V_130 ] ) ,
F_58 ( & V_126 [ V_130 ] ) ) ;
F_56 ( V_112 , L_28 ,
F_58 ( & V_125 [ V_131 ] ) ,
F_58 ( & V_126 [ V_131 ] ) ) ;
F_56 ( V_112 , L_29 ,
F_58 ( & V_125 [ V_132 ] ) ,
F_58 ( & V_126 [ V_132 ] ) ) ;
F_56 ( V_112 , L_30 ,
F_58 ( & V_125 [ V_133 ] ) ,
F_58 ( & V_126 [ V_133 ] ) ) ;
F_56 ( V_112 , L_31 ,
F_58 ( & V_125 [ V_134 ] ) ,
F_58 ( & V_126 [ V_134 ] ) ) ;
F_56 ( V_112 , L_32 ,
F_58 ( & V_125 [ V_135 ] ) ,
F_58 ( & V_126 [ V_135 ] ) ) ;
F_56 ( V_112 , L_33 ,
F_58 ( & V_125 [ V_136 ] ) ,
F_58 ( & V_126 [ V_136 ] ) ) ;
F_56 ( V_112 , L_34 ,
F_58 ( & V_125 [ V_137 ] ) ,
F_58 ( & V_126 [ V_137 ] ) ) ;
F_56 ( V_112 , L_35 ,
F_58 ( & V_125 [ V_138 ] ) ,
F_58 ( & V_126 [ V_138 ] ) ) ;
F_56 ( V_112 , L_36 ,
F_58 ( & V_125 [ V_139 ] ) ,
F_58 ( & V_126 [ V_139 ] ) ) ;
F_56 ( V_112 , L_37 ,
F_58 ( & V_125 [ V_140 ] ) ,
F_58 ( & V_126 [ V_140 ] ) ) ;
F_56 ( V_112 , L_38 ,
F_58 ( & V_125 [ V_141 ] ) ,
F_58 ( & V_126 [ V_141 ] ) ) ;
F_56 ( V_112 , L_39 ,
F_58 ( & V_125 [ V_142 ] ) ,
F_58 ( & V_126 [ V_142 ] ) ) ;
F_56 ( V_112 , L_40 ,
F_58 ( & V_125 [ V_143 ] ) ,
F_58 ( & V_126 [ V_143 ] ) ) ;
F_56 ( V_112 , L_41 ,
F_58 ( & V_125 [ V_144 ] ) ,
F_58 ( & V_126 [ V_144 ] ) ) ;
F_56 ( V_112 , L_42 ,
F_58 ( & V_125 [ V_145 ] ) ,
F_58 ( & V_126 [ V_145 ] ) ) ;
#endif
}
static void
F_59 ( struct V_146 * V_147 , struct V_80 * V_81 , T_8 V_76 )
{
struct V_148 * V_149 = F_60 ( F_61 ( V_147 -> V_150 ) ) ;
struct V_1 * V_2 = F_62 ( V_147 -> V_151 ) -> V_55 -> V_2 ;
V_147 -> V_81 . V_88 = V_81 -> V_88 ;
V_147 -> V_81 . V_89 = V_81 -> V_89 ;
V_2 -> V_16 -> V_152 ( V_149 , V_76 , V_81 -> V_153 ,
& V_81 -> V_154 ) ;
V_149 -> V_155 = F_63 ( V_149 ) ;
memcpy ( V_147 -> V_81 . V_156 , V_81 -> V_156 , 16 ) ;
}
static void
F_64 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static int
F_65 ( const unsigned int V_53 , struct V_58 * V_59 ,
T_5 V_88 , T_5 V_89 ,
struct V_157 * V_158 )
{
int V_14 ;
unsigned int V_67 ;
struct V_159 * V_160 ;
V_14 = F_34 ( V_53 , V_59 , V_88 , V_89 ,
V_161 , true ,
false ,
NULL , 0 ,
( char * * ) & V_160 , & V_67 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_43 , V_14 ) ;
goto V_162;
}
if ( V_67 < sizeof( struct V_159 ) ) {
F_2 ( V_8 , L_44 ) ;
V_14 = - V_72 ;
goto V_162;
}
memcpy ( V_158 -> V_163 , V_160 -> V_164 , V_165 ) ;
V_162:
F_36 ( V_160 ) ;
return V_14 ;
}
static T_9
F_66 ( const unsigned int V_53 ,
struct V_146 * V_166 ,
struct V_146 * V_167 , T_5 V_168 ,
T_5 V_169 , T_5 V_170 )
{
int V_14 ;
unsigned int V_67 ;
struct V_157 * V_158 ;
struct V_171 * V_172 = NULL ;
struct V_58 * V_59 ;
int V_173 = 0 ;
bool V_174 = false ;
T_9 V_175 , V_176 = 0 ;
V_158 = F_67 ( sizeof( struct V_157 ) , V_104 ) ;
if ( V_158 == NULL )
return - V_97 ;
F_2 ( V_9 , L_45 ) ;
V_14 = F_65 ( V_53 , F_62 ( V_166 -> V_151 ) ,
V_166 -> V_81 . V_88 ,
V_166 -> V_81 . V_89 , V_158 ) ;
if ( V_14 )
goto V_177;
V_158 -> V_178 = F_68 ( 1 ) ;
V_158 -> V_179 = 0 ;
V_158 -> V_180 = 0 ;
V_59 = F_62 ( V_167 -> V_151 ) ;
while ( V_169 > 0 ) {
V_158 -> V_181 = F_69 ( V_168 ) ;
V_158 -> V_182 = F_69 ( V_170 ) ;
V_158 -> V_183 =
F_68 ( F_19 ( V_184 , V_169 , V_59 -> V_185 ) ) ;
V_14 = F_34 ( V_53 , V_59 , V_167 -> V_81 . V_88 ,
V_167 -> V_81 . V_89 , V_186 ,
true , false ,
( char * ) V_158 ,
sizeof( struct V_157 ) , ( char * * ) & V_172 ,
& V_67 ) ;
if ( V_14 == 0 ) {
if ( V_67 !=
sizeof( struct V_171 ) ) {
F_2 ( V_8 , L_46 ) ;
V_14 = - V_187 ;
goto V_177;
}
if ( V_172 -> V_188 == 0 ) {
F_2 ( V_9 , L_47 ) ;
V_14 = - V_187 ;
goto V_177;
}
if ( F_35 ( V_172 -> V_188 ) >
F_35 ( V_158 -> V_183 ) ) {
F_2 ( V_8 , L_48 ) ;
V_14 = - V_187 ;
goto V_177;
}
if ( F_35 ( V_172 -> V_189 ) != 1 ) {
F_2 ( V_8 , L_49 ) ;
V_14 = - V_187 ;
goto V_177;
}
V_173 ++ ;
V_175 = F_35 ( V_172 -> V_188 ) ;
V_168 += V_175 ;
V_170 += V_175 ;
V_169 -= V_175 ;
V_176 += V_175 ;
F_2 ( V_9 , L_50 ,
F_35 ( V_172 -> V_189 ) ,
F_35 ( V_172 -> V_190 ) ,
V_175 ) ;
} else if ( V_14 == - V_72 ) {
if ( V_67 != sizeof( struct V_171 ) )
goto V_177;
F_2 ( V_9 , L_51 ,
F_35 ( V_172 -> V_189 ) ,
F_35 ( V_172 -> V_190 ) ,
F_35 ( V_172 -> V_188 ) ) ;
if ( ( V_173 != 0 ) || V_174 )
goto V_177;
if ( F_35 ( V_172 -> V_190 ) <
V_59 -> V_185 )
V_59 -> V_185 =
F_35 ( V_172 -> V_190 ) ;
else
goto V_177;
V_174 = true ;
} else
goto V_177;
}
V_177:
F_36 ( V_158 ) ;
F_36 ( V_172 ) ;
if ( V_14 )
return V_14 ;
else
return V_176 ;
}
static int
F_70 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_71 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static unsigned int
F_72 ( char * V_40 )
{
struct V_191 * V_192 = (struct V_191 * ) V_40 ;
return V_192 -> V_193 ;
}
static unsigned int
F_73 ( char * V_40 )
{
struct V_191 * V_192 = (struct V_191 * ) V_40 ;
return F_35 ( V_192 -> V_194 ) ;
}
static int
F_74 ( const unsigned int V_53 , struct V_80 * V_195 ,
struct V_196 * V_197 , unsigned int * V_198 ,
char * * V_40 , int * V_199 )
{
V_197 -> V_88 = V_195 -> V_88 ;
V_197 -> V_89 = V_195 -> V_89 ;
return F_75 ( V_53 , V_197 , V_198 , V_40 , V_199 ) ;
}
static int
F_76 ( const unsigned int V_53 , struct V_80 * V_195 ,
struct V_196 * V_197 , unsigned int * V_200 ,
struct V_201 * V_202 , unsigned long V_203 )
{
V_197 -> V_88 = V_195 -> V_88 ;
V_197 -> V_89 = V_195 -> V_89 ;
return F_77 ( V_53 , V_197 , V_200 , V_202 , V_203 ) ;
}
static bool F_78 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 , struct V_204 * V_204 , T_4 V_205 )
{
struct V_148 * V_206 ;
int V_14 ;
V_206 = F_60 ( V_204 ) ;
if ( ( V_206 -> V_207 & V_208 ) && V_205 )
return true ;
if ( ! ( V_206 -> V_207 & V_208 ) && ! V_205 )
return true ;
if ( V_59 -> V_209 )
return false ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_210 ,
true , false ,
& V_205 , 1 , NULL , NULL ) ;
if ( V_14 ) {
V_59 -> V_209 = true ;
F_2 ( V_9 , L_52 , V_14 ) ;
return false ;
}
if ( V_205 )
V_206 -> V_207 |= V_208 ;
else
V_206 -> V_207 &= ( ~ V_208 ) ;
return true ;
}
static int
F_79 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 , T_1 V_31 , bool V_211 )
{
T_10 V_212 = F_69 ( V_31 ) ;
struct V_204 * V_204 ;
V_204 = F_61 ( V_147 -> V_150 ) ;
if ( ! V_211 && ( V_31 > V_204 -> V_213 + 8192 ) ) {
T_4 V_214 = 1 ;
F_78 ( V_53 , V_59 , V_147 , V_204 , V_214 ) ;
}
return F_80 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_147 -> V_215 , & V_212 , false ) ;
}
static int
F_81 ( const unsigned int V_53 ,
struct V_146 * V_166 ,
struct V_146 * V_167 , T_5 V_168 ,
T_5 V_169 , T_5 V_170 )
{
int V_14 ;
unsigned int V_67 ;
struct V_216 V_217 ;
struct V_58 * V_59 = F_62 ( V_167 -> V_151 ) ;
if ( ( F_35 ( V_59 -> V_218 . V_219 ) &
V_220 ) == 0 )
return - V_221 ;
V_217 . V_222 = V_166 -> V_81 . V_89 ;
V_217 . V_223 = V_166 -> V_81 . V_88 ;
V_217 . V_224 = F_69 ( V_168 ) ;
V_217 . V_225 = F_69 ( V_170 ) ;
V_217 . V_226 = F_69 ( V_169 ) ;
F_2 ( V_9 , L_53 ,
V_168 , V_170 , V_169 ) ;
V_14 = F_79 ( V_53 , V_59 , V_167 , V_170 + V_169 , false ) ;
if ( V_14 )
goto V_227;
V_14 = F_34 ( V_53 , V_59 , V_167 -> V_81 . V_88 ,
V_167 -> V_81 . V_89 ,
V_228 ,
true , false ,
( char * ) & V_217 ,
sizeof( struct V_216 ) ,
NULL ,
& V_67 ) ;
if ( V_67 > 0 )
F_2 ( V_9 , L_54 ) ;
V_227:
return V_14 ;
}
static int
F_82 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 )
{
return F_83 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 ) ;
}
static int
F_84 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 )
{
struct V_229 V_230 ;
unsigned int V_67 ;
V_230 . V_231 = F_85 ( V_232 ) ;
V_230 . V_50 = 0 ;
V_230 . V_179 = 0 ;
return F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 ,
V_233 ,
true , false ,
( char * ) & V_230 ,
sizeof( struct V_229 ) ,
NULL ,
& V_67 ) ;
}
static int
F_86 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 , void T_11 * V_234 )
{
char * V_172 = NULL ;
unsigned int V_67 = 0 ;
int V_14 ;
struct V_235 V_236 ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 ,
V_237 ,
true , false ,
NULL , 0 ,
( char * * ) & V_172 ,
& V_67 ) ;
F_2 ( V_9 , L_55 ,
V_14 , V_67 ) ;
if ( V_14 )
return V_14 ;
if ( V_67 && ( V_234 != NULL ) && ( V_172 != NULL ) ) {
if ( F_87 ( & V_236 , V_234 ,
sizeof( struct V_235 ) ) ) {
V_14 = - V_238 ;
F_36 ( V_172 ) ;
return V_14 ;
}
if ( V_236 . V_239 < sizeof( struct V_235 ) ) {
V_14 = - V_240 ;
F_36 ( V_172 ) ;
return V_14 ;
}
if ( V_67 > V_236 . V_239 )
V_67 = V_236 . V_239 ;
if ( F_88 ( V_234 , V_172 , V_67 ) )
V_14 = - V_238 ;
}
F_36 ( V_172 ) ;
return V_14 ;
}
static int
F_89 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_241 , struct V_93 * V_94 ,
struct V_80 * V_81 , T_12 V_242 ,
struct V_243 * V_244 )
{
T_2 * V_96 ;
int V_14 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
V_96 = F_44 ( V_241 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 | V_245 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_56 , V_14 ) ;
return V_14 ;
}
V_244 -> V_246 = 0 ;
V_244 -> V_247 = 0 ;
V_14 = F_90 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_244 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_57 , V_14 ) ;
F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
return V_14 ;
}
static int
F_91 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_12 V_242 ,
struct V_243 * V_244 )
{
return F_90 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_244 ) ;
}
static int
F_92 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static bool
F_93 ( char * V_40 , struct V_1 * V_2 , int V_248 )
{
struct V_27 * V_28 = F_12 ( V_40 ) ;
if ( V_28 -> V_49 != V_249 )
return false ;
if ( ! V_248 ) {
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 += F_13 ( V_28 -> V_30 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_22 ) ;
}
return true ;
}
static int
F_94 ( struct V_58 * V_59 , struct V_80 * V_81 ,
struct V_148 * V_149 )
{
if ( V_59 -> V_55 -> V_2 -> V_64 & V_250 )
return F_95 ( 0 , V_59 , V_149 -> V_251 ,
F_96 ( V_149 ) ) ;
return F_97 ( 0 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 ,
F_98 ( V_149 ) ? 1 : 0 ) ;
}
static int
F_99 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_252 * V_40 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return V_14 ;
V_40 -> V_253 = V_254 ;
V_14 = F_100 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_40 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return V_14 ;
}
static bool
F_101 ( struct V_146 * V_255 , struct V_146 * V_256 )
{
return V_255 -> V_81 . V_88 == V_256 -> V_81 . V_88 &&
V_255 -> V_81 . V_89 == V_256 -> V_81 . V_89 ;
}
static int
F_102 ( const unsigned int V_53 , struct V_146 * V_147 , T_1 V_257 ,
T_1 V_248 , T_8 type , int V_258 , int V_259 , bool V_260 )
{
if ( V_259 && ! V_258 )
type = V_261 ;
return F_103 ( V_53 , F_62 ( V_147 -> V_151 ) ,
V_147 -> V_81 . V_88 , V_147 -> V_81 . V_89 ,
V_262 -> V_263 , V_248 , V_257 , type , V_260 ) ;
}
static void
F_104 ( struct V_204 * V_204 , struct V_80 * V_81 )
{
memcpy ( V_81 -> V_251 , F_60 ( V_204 ) -> V_251 , V_264 ) ;
}
static void
F_105 ( struct V_204 * V_204 , struct V_80 * V_81 )
{
memcpy ( F_60 ( V_204 ) -> V_251 , V_81 -> V_251 , V_264 ) ;
}
static void
F_106 ( struct V_80 * V_81 )
{
F_107 ( V_81 -> V_251 ) ;
}
static int
F_108 ( const unsigned int V_53 , struct V_54 * V_55 ,
const char * V_265 ,
struct V_266 * * V_267 ,
unsigned int * V_268 ,
const struct V_269 * V_270 , int V_271 )
{
int V_14 ;
T_2 * V_96 = NULL ;
int V_272 = 0 ;
struct V_58 * V_59 ;
struct V_273 * V_274 = NULL ;
struct V_275 * V_276 = NULL ;
V_184 V_277 = 0 , V_278 = 0 ;
F_2 ( V_9 , L_58 , V_265 ) ;
F_4 ( & V_279 ) ;
V_59 = F_109 ( & V_55 -> V_280 , struct V_58 ,
V_280 ) ;
if ( V_59 )
V_59 -> V_281 ++ ;
F_6 ( & V_279 ) ;
if ( ! V_59 ) {
F_2 ( V_8 , L_59 ,
V_55 ) ;
V_14 = - V_282 ;
goto V_283;
}
V_96 = F_110 ( V_265 , V_103 ,
& V_272 ,
V_270 , V_271 ) ;
if ( ! V_96 ) {
V_14 = - V_97 ;
goto V_283;
}
V_277 = sizeof( * V_274 ) + V_272 ;
V_274 = F_47 ( V_277 , V_104 ) ;
if ( ! V_274 ) {
V_14 = - V_97 ;
goto V_283;
}
V_274 -> V_284 = V_285 ;
memcpy ( V_274 -> V_286 , V_96 , V_272 ) ;
do {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_287 ,
true , true ,
( char * ) V_274 , V_277 ,
( char * * ) & V_276 , & V_278 ) ;
if ( V_14 == - V_282 ) {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_287 ,
true , false ,
( char * ) V_274 , V_277 ,
( char * * ) & V_276 , & V_278 ) ;
}
} while ( V_14 == - V_56 );
if ( V_14 ) {
F_2 ( V_8 , L_60 , V_14 ) ;
goto V_283;
}
V_14 = F_111 ( V_276 , V_278 ,
V_268 , V_267 ,
V_270 , V_271 , V_265 ,
true ) ;
if ( V_14 ) {
F_2 ( V_8 , L_61 , V_14 ) ;
goto V_283;
}
V_283:
if ( V_59 ) {
F_4 ( & V_279 ) ;
V_59 -> V_281 -- ;
F_6 ( & V_279 ) ;
}
F_36 ( V_96 ) ;
F_36 ( V_274 ) ;
F_36 ( V_276 ) ;
return V_14 ;
}
static int
F_112 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_95 , char * * V_288 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_289 * V_290 = NULL ;
struct V_291 * V_292 ;
unsigned int V_293 ;
unsigned int V_294 ;
unsigned int V_295 ;
unsigned int V_296 ;
F_2 ( V_9 , L_62 , V_297 , V_95 ) ;
V_96 = F_44 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , & V_290 ) ;
if ( ! V_14 || ! V_290 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_35 ( V_290 -> V_226 ) < sizeof( struct V_291 ) ||
F_113 ( V_290 ) + 4 < V_298 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
V_14 = 0 ;
V_292 = (struct V_291 * ) V_290 -> V_299 ;
V_293 = F_13 ( V_292 -> V_300 ) ;
V_294 = F_13 ( V_292 -> V_301 ) ;
V_295 = F_13 ( V_292 -> V_302 ) ;
V_296 = F_13 ( V_292 -> V_303 ) ;
if ( F_113 ( V_290 ) + 4 <
V_298 + V_294 + V_293 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_113 ( V_290 ) + 4 <
V_298 + V_296 + V_295 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
* V_288 = F_114 (
( char * ) V_292 -> V_304 + V_294 ,
V_293 , true , V_94 -> V_305 ) ;
if ( ! ( * V_288 ) ) {
F_36 ( V_96 ) ;
return - V_97 ;
}
F_115 ( * V_288 , '/' ) ;
F_2 ( V_9 , L_63 , V_297 , * V_288 ) ;
F_36 ( V_96 ) ;
return V_14 ;
}
static long F_116 ( struct V_306 * V_306 , struct V_58 * V_59 ,
T_13 V_257 , T_13 V_169 , bool V_307 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_306 -> V_308 ;
struct V_309 V_310 ;
long V_14 ;
unsigned int V_53 ;
V_53 = F_117 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_98 ( V_206 ) )
if ( V_307 == false )
return - V_221 ;
if ( ! ( V_206 -> V_207 & V_208 ) )
return - V_221 ;
if ( V_307 == false )
if ( F_118 ( V_204 ) < V_257 + V_169 )
return - V_221 ;
F_2 ( V_9 , L_64 , V_257 , V_169 ) ;
V_310 . V_311 = F_69 ( V_257 ) ;
V_310 . V_312 = F_69 ( V_257 + V_169 ) ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_313 ,
true , false ,
( char * ) & V_310 ,
sizeof( struct V_309 ) , NULL , NULL ) ;
F_119 ( V_53 ) ;
return V_14 ;
}
static long F_120 ( struct V_306 * V_306 , struct V_58 * V_59 ,
T_13 V_257 , T_13 V_169 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_306 -> V_308 ;
struct V_309 V_310 ;
long V_14 ;
unsigned int V_53 ;
T_4 V_214 = 1 ;
V_53 = F_117 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_78 ( V_53 , V_59 , V_147 , V_204 , V_214 ) )
return - V_221 ;
F_2 ( V_9 , L_64 , V_257 , V_169 ) ;
V_310 . V_311 = F_69 ( V_257 ) ;
V_310 . V_312 = F_69 ( V_257 + V_169 ) ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_313 ,
true , false ,
( char * ) & V_310 ,
sizeof( struct V_309 ) , NULL , NULL ) ;
F_119 ( V_53 ) ;
return V_14 ;
}
static long F_121 ( struct V_306 * V_306 , struct V_58 * V_59 ,
T_13 V_314 , T_13 V_169 , bool V_307 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_306 -> V_308 ;
long V_14 = - V_221 ;
unsigned int V_53 ;
V_53 = F_117 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_98 ( V_206 ) )
if ( V_307 == false )
return - V_221 ;
if ( ( V_206 -> V_207 & V_208 ) == 0 ) {
if ( V_307 == true )
return 0 ;
else if ( F_118 ( V_204 ) >= V_314 + V_169 )
return 0 ;
else
return - V_221 ;
}
if ( ( V_307 == true ) || ( F_118 ( V_204 ) >= V_314 + V_169 ) ) {
if ( ( V_314 > 8192 ) || ( V_314 + V_169 + 8192 < F_118 ( V_204 ) ) )
return - V_221 ;
V_14 = F_78 ( V_53 , V_59 , V_147 , V_204 , false ) ;
}
F_119 ( V_53 ) ;
return V_14 ;
}
static long F_122 ( struct V_306 * V_306 , struct V_58 * V_59 , int V_315 ,
T_13 V_314 , T_13 V_169 )
{
if ( V_315 & V_316 )
return F_120 ( V_306 , V_59 , V_314 , V_169 ) ;
else if ( V_315 & V_317 ) {
if ( V_315 & V_318 )
return F_116 ( V_306 , V_59 , V_314 , V_169 , true ) ;
return F_116 ( V_306 , V_59 , V_314 , V_169 , false ) ;
} else if ( V_315 == V_318 )
return F_121 ( V_306 , V_59 , V_314 , V_169 , true ) ;
else if ( V_315 == 0 )
return F_121 ( V_306 , V_59 , V_314 , V_169 , false ) ;
return - V_221 ;
}
static void
F_123 ( struct V_1 * V_2 ,
struct V_148 * V_149 , bool V_319 )
{
if ( V_319 )
V_2 -> V_16 -> V_152 ( V_149 , V_320 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_152 ( V_149 , 0 , 0 , NULL ) ;
}
static void
F_124 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
V_76 &= 0xFF ;
if ( V_76 == V_321 )
return;
if ( V_76 == V_322 ) {
V_149 -> V_76 = V_323 ;
F_2 ( V_9 , L_65 ,
& V_149 -> V_324 ) ;
} else if ( V_76 == V_325 ) {
V_149 -> V_76 = V_326 ;
F_2 ( V_9 , L_66 ,
& V_149 -> V_324 ) ;
} else if ( V_76 == V_320 ) {
V_149 -> V_76 = V_327 ;
F_2 ( V_9 , L_67 ,
& V_149 -> V_324 ) ;
} else
V_149 -> V_76 = 0 ;
}
static void
F_125 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
char V_328 [ 5 ] = { 0 } ;
V_76 &= 0xFF ;
if ( V_76 == V_321 )
return;
V_149 -> V_76 = 0 ;
if ( V_76 & V_329 ) {
V_149 -> V_76 |= V_327 ;
strcat ( V_328 , L_68 ) ;
}
if ( V_76 & V_330 ) {
V_149 -> V_76 |= V_331 ;
strcat ( V_328 , L_69 ) ;
}
if ( V_76 & V_332 ) {
V_149 -> V_76 |= V_333 ;
strcat ( V_328 , L_70 ) ;
}
if ( ! V_149 -> V_76 )
strcat ( V_328 , L_71 ) ;
F_2 ( V_9 , L_72 , V_328 ,
& V_149 -> V_324 ) ;
}
static void
F_126 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
unsigned int V_334 = V_149 -> V_76 ;
F_125 ( V_149 , V_76 , V_153 , V_154 ) ;
if ( V_154 ) {
* V_154 = false ;
if ( V_334 == V_327 ) {
if ( V_149 -> V_76 == V_327 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_335 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_323 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == 0 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
} else if ( V_334 == V_335 ) {
if ( V_149 -> V_76 == V_335 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_323 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
}
V_149 -> V_153 = V_153 ;
}
}
static bool
F_127 ( T_8 V_76 )
{
return V_76 == V_320 ;
}
static bool
F_128 ( T_8 V_76 )
{
return ( V_76 & V_329 ) &&
! ( V_76 & V_332 ) ;
}
static T_14
F_129 ( T_3 V_76 )
{
if ( V_76 == V_325 )
return V_336 | V_337 ;
else if ( V_76 == V_320 )
return V_337 ;
else if ( V_76 == V_322 )
return V_338 | V_337 |
V_336 ;
return 0 ;
}
static char *
F_130 ( T_3 * V_251 , T_3 V_76 )
{
struct V_339 * V_40 ;
V_40 = F_47 ( sizeof( struct V_339 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_340 . V_341 = F_69 ( * ( ( T_5 * ) V_251 ) ) ;
V_40 -> V_340 . V_342 = F_69 ( * ( ( T_5 * ) ( V_251 + 8 ) ) ) ;
V_40 -> V_340 . V_343 = F_129 ( V_76 ) ;
V_40 -> V_344 . V_193 = F_85 ( F_131
( struct V_339 , V_340 ) ) ;
V_40 -> V_344 . V_194 = F_68 ( sizeof( struct V_345 ) ) ;
V_40 -> V_344 . V_346 = F_85 ( F_131
( struct V_339 , V_347 ) ) ;
V_40 -> V_344 . V_348 = F_85 ( 4 ) ;
V_40 -> V_347 [ 0 ] = 'R' ;
V_40 -> V_347 [ 1 ] = 'q' ;
V_40 -> V_347 [ 2 ] = 'L' ;
V_40 -> V_347 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static char *
F_132 ( T_3 * V_251 , T_3 V_76 )
{
struct V_349 * V_40 ;
V_40 = F_47 ( sizeof( struct V_349 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_340 . V_341 = F_69 ( * ( ( T_5 * ) V_251 ) ) ;
V_40 -> V_340 . V_342 = F_69 ( * ( ( T_5 * ) ( V_251 + 8 ) ) ) ;
V_40 -> V_340 . V_343 = F_129 ( V_76 ) ;
V_40 -> V_344 . V_193 = F_85 ( F_131
( struct V_349 , V_340 ) ) ;
V_40 -> V_344 . V_194 = F_68 ( sizeof( struct V_350 ) ) ;
V_40 -> V_344 . V_346 = F_85 ( F_131
( struct V_349 , V_347 ) ) ;
V_40 -> V_344 . V_348 = F_85 ( 4 ) ;
V_40 -> V_347 [ 0 ] = 'R' ;
V_40 -> V_347 [ 1 ] = 'q' ;
V_40 -> V_347 [ 2 ] = 'L' ;
V_40 -> V_347 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static T_4
F_133 ( void * V_40 , unsigned int * V_153 )
{
struct V_339 * V_351 = (struct V_339 * ) V_40 ;
* V_153 = 0 ;
if ( V_351 -> V_340 . V_352 & V_353 )
return V_321 ;
return F_35 ( V_351 -> V_340 . V_343 ) ;
}
static T_4
F_134 ( void * V_40 , unsigned int * V_153 )
{
struct V_349 * V_351 = (struct V_349 * ) V_40 ;
* V_153 = F_13 ( V_351 -> V_340 . V_354 ) ;
if ( V_351 -> V_340 . V_352 & V_353 )
return V_321 ;
return F_35 ( V_351 -> V_340 . V_343 ) ;
}
static unsigned int
F_135 ( struct V_204 * V_204 )
{
return F_19 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_136 ( struct V_146 * V_147 )
{
return ! V_147 -> V_355 ;
}
static void
F_137 ( struct V_356 * V_357 , struct V_358 * V_359 )
{
struct V_27 * V_28 =
(struct V_27 * ) V_359 -> V_360 [ 1 ] . V_361 ;
unsigned int V_362 = F_113 ( V_359 -> V_360 [ 0 ] . V_361 ) ;
memset ( V_357 , 0 , sizeof( struct V_356 ) ) ;
V_357 -> V_43 = V_44 ;
V_357 -> V_363 = F_68 ( V_362 ) ;
V_357 -> V_50 = F_85 ( 0x01 ) ;
F_138 ( & V_357 -> V_364 , V_365 ) ;
memcpy ( & V_357 -> V_366 , & V_28 -> V_366 , 8 ) ;
F_139 ( V_357 , sizeof( struct V_356 ) - 4 ) ;
F_139 ( V_357 , V_362 ) ;
}
static struct V_367 *
F_140 ( struct V_358 * V_368 , T_3 * V_369 )
{
unsigned int V_370 = V_368 -> V_371 + V_368 -> V_372 + 1 ;
unsigned int V_373 = sizeof( struct V_356 ) - 24 ;
struct V_367 * V_374 ;
unsigned int V_105 ;
unsigned int V_375 ;
V_374 = F_141 ( V_370 , sizeof( struct V_367 ) , V_104 ) ;
if ( ! V_374 )
return NULL ;
F_142 ( V_374 , V_370 ) ;
F_143 ( & V_374 [ 0 ] , V_368 -> V_360 [ 0 ] . V_361 + 24 , V_373 ) ;
for ( V_105 = 1 ; V_105 < V_368 -> V_371 ; V_105 ++ )
F_143 ( & V_374 [ V_105 ] , V_368 -> V_360 [ V_105 ] . V_361 ,
V_368 -> V_360 [ V_105 ] . V_376 ) ;
for ( V_375 = 0 ; V_105 < V_370 - 1 ; V_105 ++ , V_375 ++ ) {
unsigned int V_169 = ( V_375 < V_368 -> V_372 - 1 ) ? V_368 -> V_377
: V_368 -> V_378 ;
F_144 ( & V_374 [ V_105 ] , V_368 -> V_379 [ V_375 ] , V_169 , 0 ) ;
}
F_143 ( & V_374 [ V_370 - 1 ] , V_369 , V_380 ) ;
return V_374 ;
}
static void F_145 ( struct V_381 * V_382 , int V_383 )
{
struct V_384 * V_385 = V_382 -> V_99 ;
if ( V_383 == - V_386 )
return;
V_385 -> V_383 = V_383 ;
F_146 ( & V_385 -> V_387 ) ;
}
static int
F_147 ( struct V_1 * V_2 , T_1 V_388 , int V_389 , T_3 * V_390 )
{
struct V_54 * V_55 ;
T_3 * V_391 ;
F_4 ( & V_279 ) ;
F_24 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_55 -> V_392 != V_388 )
continue;
V_391 = V_389 ? V_55 -> V_393 :
V_55 -> V_394 ;
memcpy ( V_390 , V_391 , V_395 ) ;
F_6 ( & V_279 ) ;
return 0 ;
}
F_6 ( & V_279 ) ;
return 1 ;
}
static int
F_148 ( struct V_1 * V_2 , struct V_358 * V_368 , int V_389 )
{
struct V_356 * V_357 =
(struct V_356 * ) V_368 -> V_360 [ 0 ] . V_361 ;
unsigned int V_373 = sizeof( struct V_356 ) - 24 ;
int V_14 = 0 ;
struct V_367 * V_374 ;
T_3 V_369 [ V_380 ] = {} ;
T_3 V_390 [ V_395 ] ;
struct V_396 * V_382 ;
char * V_397 ;
unsigned int V_398 ;
struct V_384 V_399 = { 0 , } ;
struct V_400 * V_401 ;
unsigned int V_402 = F_35 ( V_357 -> V_363 ) ;
F_149 ( & V_399 . V_387 ) ;
V_14 = F_147 ( V_2 , V_357 -> V_366 , V_389 , V_390 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_73 , V_297 ,
V_389 ? L_74 : L_75 ) ;
return 0 ;
}
V_14 = F_150 ( V_2 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_76 , V_297 ) ;
return V_14 ;
}
V_401 = V_389 ? V_2 -> V_403 . V_404 :
V_2 -> V_403 . V_405 ;
V_14 = F_151 ( V_401 , V_390 , V_395 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_77 , V_297 , V_14 ) ;
return V_14 ;
}
V_14 = F_152 ( V_401 , V_380 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_78 , V_297 , V_14 ) ;
return V_14 ;
}
V_382 = F_153 ( V_401 , V_104 ) ;
if ( ! V_382 ) {
F_2 ( V_8 , L_79 , V_297 ) ;
return - V_97 ;
}
if ( ! V_389 ) {
memcpy ( V_369 , & V_357 -> V_406 , V_380 ) ;
V_402 += V_380 ;
}
V_374 = F_140 ( V_368 , V_369 ) ;
if ( ! V_374 ) {
F_2 ( V_8 , L_80 , V_297 ) ;
V_14 = - V_97 ;
goto V_407;
}
V_398 = F_154 ( V_401 ) ;
V_397 = F_47 ( V_398 , V_104 ) ;
if ( ! V_397 ) {
F_2 ( V_8 , L_81 , V_297 ) ;
V_14 = - V_97 ;
goto V_408;
}
V_397 [ 0 ] = 3 ;
memcpy ( V_397 + 1 , ( char * ) V_357 -> V_364 , V_365 ) ;
F_155 ( V_382 , V_374 , V_374 , V_402 , V_397 ) ;
F_156 ( V_382 , V_373 ) ;
F_157 ( V_382 , V_409 ,
F_145 , & V_399 ) ;
V_14 = V_389 ? F_158 ( V_382 ) : F_159 ( V_382 ) ;
if ( V_14 == - V_386 || V_14 == - V_410 ) {
F_160 ( & V_399 . V_387 ) ;
V_14 = V_399 . V_383 ;
}
if ( ! V_14 && V_389 )
memcpy ( & V_357 -> V_406 , V_369 , V_380 ) ;
F_36 ( V_397 ) ;
V_408:
F_36 ( V_374 ) ;
V_407:
F_36 ( V_382 ) ;
return V_14 ;
}
static int
F_161 ( struct V_1 * V_2 , struct V_358 * V_411 ,
struct V_358 * V_359 )
{
struct V_201 * V_202 ;
struct V_412 * * V_413 ;
struct V_356 * V_357 ;
unsigned int V_414 = V_359 -> V_372 ;
int V_105 ;
int V_14 = - V_97 ;
V_413 = F_141 ( V_414 , sizeof( struct V_412 * ) , V_104 ) ;
if ( ! V_413 )
return V_14 ;
V_411 -> V_379 = V_413 ;
V_411 -> V_372 = V_359 -> V_372 ;
V_411 -> V_377 = V_359 -> V_377 ;
V_411 -> V_378 = V_359 -> V_378 ;
for ( V_105 = 0 ; V_105 < V_414 ; V_105 ++ ) {
V_413 [ V_105 ] = F_162 ( V_104 | V_415 ) ;
if ( ! V_413 [ V_105 ] )
goto V_416;
}
V_202 = F_141 ( V_359 -> V_371 , sizeof( struct V_201 ) , V_104 ) ;
if ( ! V_202 )
goto V_416;
memcpy ( & V_202 [ 1 ] , & V_359 -> V_360 [ 1 ] ,
sizeof( struct V_201 ) * ( V_359 -> V_371 - 1 ) ) ;
V_411 -> V_360 = V_202 ;
V_411 -> V_371 = V_359 -> V_371 ;
V_357 = F_67 ( sizeof( struct V_356 ) , V_104 ) ;
if ( ! V_357 )
goto V_417;
F_137 ( V_357 , V_359 ) ;
V_411 -> V_360 [ 0 ] . V_361 = V_357 ;
V_411 -> V_360 [ 0 ] . V_376 = sizeof( struct V_356 ) ;
for ( V_105 = 0 ; V_105 < V_414 ; V_105 ++ ) {
char * V_418 = F_163 ( V_411 -> V_379 [ V_105 ] ) ;
char * V_419 = F_163 ( V_359 -> V_379 [ V_105 ] ) ;
unsigned int V_169 = ( V_105 < V_414 - 1 ) ? V_411 -> V_377 :
V_411 -> V_378 ;
memcpy ( V_418 , V_419 , V_169 ) ;
F_164 ( V_411 -> V_379 [ V_105 ] ) ;
F_164 ( V_359 -> V_379 [ V_105 ] ) ;
}
V_14 = F_148 ( V_2 , V_411 , 1 ) ;
F_2 ( V_9 , L_82 , V_14 ) ;
if ( V_14 )
goto V_420;
return V_14 ;
V_420:
F_36 ( V_357 ) ;
V_417:
F_36 ( V_202 ) ;
V_416:
for ( V_105 = V_105 - 1 ; V_105 >= 0 ; V_105 -- )
F_165 ( V_413 [ V_105 ] ) ;
F_36 ( V_413 ) ;
return V_14 ;
}
static void
F_166 ( struct V_358 * V_368 )
{
int V_105 = V_368 -> V_372 - 1 ;
for (; V_105 >= 0 ; V_105 -- )
F_165 ( V_368 -> V_379 [ V_105 ] ) ;
F_36 ( V_368 -> V_379 ) ;
F_36 ( V_368 -> V_360 [ 0 ] . V_361 ) ;
F_36 ( V_368 -> V_360 ) ;
}
static int
F_167 ( void * V_40 )
{
struct V_356 * V_421 = V_40 ;
return V_421 -> V_43 == V_44 ;
}
static int
F_168 ( struct V_1 * V_2 , char * V_40 ,
unsigned int V_422 , struct V_412 * * V_413 ,
unsigned int V_414 , unsigned int V_423 )
{
struct V_201 V_202 [ 2 ] ;
struct V_358 V_368 = { NULL } ;
struct V_424 * V_425 ;
int V_14 ;
V_202 [ 0 ] . V_361 = V_40 ;
V_202 [ 0 ] . V_376 = sizeof( struct V_356 ) ;
V_202 [ 1 ] . V_361 = V_40 + sizeof( struct V_356 ) ;
V_202 [ 1 ] . V_376 = V_422 ;
V_368 . V_360 = V_202 ;
V_368 . V_371 = 2 ;
V_368 . V_379 = V_413 ;
V_368 . V_372 = V_414 ;
V_368 . V_377 = V_426 ;
V_368 . V_378 = ( V_423 % V_426 ) ? : V_426 ;
V_14 = F_148 ( V_2 , & V_368 , 0 ) ;
F_2 ( V_9 , L_83 , V_14 ) ;
if ( V_14 )
return V_14 ;
memmove ( V_40 + 4 , V_202 [ 1 ] . V_361 , V_422 ) ;
V_425 = (struct V_424 * ) V_40 ;
V_425 -> V_427 = F_169 ( V_422 + V_423 ) ;
V_2 -> V_428 = V_422 + V_423 + 4 ;
return V_14 ;
}
static int
F_170 ( struct V_1 * V_2 , struct V_412 * * V_413 ,
unsigned int V_414 , unsigned int V_169 )
{
int V_105 ;
int V_248 ;
for ( V_105 = 0 ; V_105 < V_414 ; V_105 ++ ) {
struct V_412 * V_412 = V_413 [ V_105 ] ;
T_15 V_429 ;
V_429 = V_169 ;
if ( V_169 >= V_426 ) {
V_429 = V_426 ;
V_169 -= V_429 ;
} else {
F_171 ( V_412 , V_169 , V_426 - V_169 ) ;
V_169 = 0 ;
}
V_248 = F_172 ( V_2 , V_412 , V_429 ) ;
if ( V_248 < 0 )
return V_248 ;
V_2 -> V_428 += V_248 ;
}
return 0 ;
}
static int
F_173 ( struct V_412 * * V_413 , unsigned int V_414 , unsigned int V_430 ,
unsigned int V_431 , struct V_432 * * V_433 )
{
struct V_432 * V_434 ;
int V_105 ;
V_434 = F_174 ( V_414 , sizeof( struct V_432 ) , V_104 ) ;
if ( ! V_434 )
return - V_97 ;
for ( V_105 = 0 ; V_105 < V_414 ; V_105 ++ ) {
V_434 [ V_105 ] . V_435 = V_413 [ V_105 ] ;
V_434 [ V_105 ] . V_436 = ( V_105 == 0 ) ? V_431 : 0 ;
V_434 [ V_105 ] . V_437 = F_19 (unsigned int, PAGE_SIZE, data_size) ;
V_430 -= V_434 [ V_105 ] . V_437 ;
}
if ( V_430 != 0 ) {
F_2 ( V_8 , L_84 , V_297 ) ;
F_36 ( V_434 ) ;
return - V_187 ;
}
* V_433 = V_434 ;
return 0 ;
}
static int
F_175 ( struct V_1 * V_2 , struct V_25 * V_26 ,
char * V_40 , unsigned int V_438 , struct V_412 * * V_413 ,
unsigned int V_414 , unsigned int V_423 )
{
unsigned int V_439 ;
unsigned int V_440 ;
unsigned int V_431 ;
unsigned int V_441 ;
unsigned int V_442 ;
struct V_443 * V_444 = V_26 -> V_445 ;
struct V_27 * V_28 = F_12 ( V_40 ) ;
struct V_432 * V_434 = NULL ;
struct V_446 V_447 ;
struct V_201 V_202 ;
int V_248 ;
if ( V_28 -> V_48 != V_448 ) {
F_2 ( V_8 , L_85 ) ;
return - V_449 ;
}
if ( V_2 -> V_16 -> V_450 &&
V_2 -> V_16 -> V_450 ( V_40 , V_2 , 0 ) )
return - 1 ;
V_444 -> V_399 = V_2 -> V_16 -> V_451 ( V_40 , false ) ;
if ( V_444 -> V_399 != 0 ) {
F_2 ( V_9 , L_86 ,
V_297 , V_444 -> V_399 ) ;
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
V_439 = V_2 -> V_16 -> V_452 ( V_40 ) + 4 ;
V_440 = V_2 -> V_16 -> V_453 ( V_40 ) ;
if ( V_439 < V_2 -> V_454 -> V_455 ) {
F_2 ( V_9 , L_87 ,
V_297 , V_439 ) ;
V_439 = V_2 -> V_454 -> V_455 ;
} else if ( V_439 > V_456 ) {
F_2 ( V_9 , L_88 ,
V_297 , V_439 ) ;
V_444 -> V_399 = - V_187 ;
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
V_442 = V_439 - V_2 -> V_454 -> V_455 ;
if ( V_438 <= V_439 ) {
V_441 = V_442 / V_426 ;
V_431 = V_442 % V_426 ;
if ( V_441 != 0 ) {
F_2 ( V_9 , L_89 ,
V_297 , V_439 ) ;
V_444 -> V_399 = - V_187 ;
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
if ( V_440 > V_423 - V_442 ) {
V_444 -> V_399 = - V_187 ;
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
V_444 -> V_399 = F_173 ( V_413 , V_414 , V_423 ,
V_431 , & V_434 ) ;
if ( V_444 -> V_399 != 0 ) {
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
F_177 ( & V_447 , V_457 | V_458 , V_434 , V_414 , V_440 ) ;
} else if ( V_438 >= V_439 + V_440 ) {
F_178 ( V_414 > 0 , L_90 ) ;
V_202 . V_361 = V_40 + V_439 ;
V_202 . V_376 = V_440 ;
F_179 ( & V_447 , V_457 | V_459 , & V_202 , 1 , V_440 ) ;
} else {
F_178 ( 1 , L_91 ) ;
V_444 -> V_399 = - V_187 ;
F_176 ( V_26 , V_444 -> V_399 ) ;
return 0 ;
}
V_444 -> V_202 [ 0 ] . V_361 = V_40 ;
V_444 -> V_202 [ 0 ] . V_376 = 4 ;
V_444 -> V_202 [ 1 ] . V_361 = V_40 + 4 ;
V_444 -> V_202 [ 1 ] . V_376 = V_2 -> V_454 -> V_455 - 4 ;
F_2 ( V_9 , L_92 ,
V_444 -> V_202 [ 0 ] . V_361 , V_2 -> V_454 -> V_455 ) ;
V_248 = V_444 -> V_460 ( V_2 , V_444 , & V_447 ) ;
F_36 ( V_434 ) ;
if ( V_248 < 0 )
return V_248 ;
F_176 ( V_26 , false ) ;
return V_248 ;
}
static int
F_180 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_461 ;
struct V_356 * V_357 = (struct V_356 * ) V_40 ;
unsigned int V_414 ;
struct V_412 * * V_413 ;
unsigned int V_169 ;
unsigned int V_462 = F_113 ( V_40 ) + 4 ;
int V_14 ;
int V_105 = 0 ;
V_169 = F_19 (unsigned int, buflen, server->vals->read_rsp_size - 4 +
sizeof(struct smb2_transform_hdr)) - F_181 ( V_2 ) + 1 ;
V_14 = F_182 ( V_2 , V_40 + F_181 ( V_2 ) - 1 , V_169 ) ;
if ( V_14 < 0 )
return V_14 ;
V_2 -> V_428 += V_14 ;
V_169 = F_35 ( V_357 -> V_363 ) + 4 -
V_2 -> V_454 -> V_455 ;
V_414 = F_20 ( V_169 , V_426 ) ;
V_413 = F_141 ( V_414 , sizeof( struct V_412 * ) , V_104 ) ;
if ( ! V_413 ) {
V_14 = - V_97 ;
goto V_463;
}
for (; V_105 < V_414 ; V_105 ++ ) {
V_413 [ V_105 ] = F_162 ( V_104 | V_415 ) ;
if ( ! V_413 [ V_105 ] ) {
V_14 = - V_97 ;
goto V_463;
}
}
V_14 = F_170 ( V_2 , V_413 , V_414 , V_169 ) ;
if ( V_14 )
goto V_464;
V_14 = F_183 ( V_2 ) ;
if ( V_14 )
goto V_464;
V_14 = F_168 ( V_2 , V_40 , V_2 -> V_454 -> V_455 - 4 ,
V_413 , V_414 , V_169 ) ;
if ( V_14 )
goto V_464;
* V_26 = F_22 ( V_2 , V_40 ) ;
if ( * V_26 == NULL )
F_2 ( V_9 , L_93 ) ;
else {
F_2 ( V_9 , L_94 ) ;
( * V_26 ) -> V_465 = true ;
V_14 = F_175 ( V_2 , * V_26 , V_40 ,
V_2 -> V_454 -> V_455 ,
V_413 , V_414 , V_169 ) ;
}
V_464:
for ( V_105 = V_105 - 1 ; V_105 >= 0 ; V_105 -- )
F_165 ( V_413 [ V_105 ] ) ;
F_36 ( V_413 ) ;
return V_14 ;
V_463:
F_183 ( V_2 ) ;
goto V_464;
}
static int
F_184 ( struct V_1 * V_2 ,
struct V_25 * * V_26 )
{
int V_248 ;
char * V_40 = V_2 -> V_461 ;
unsigned int V_466 = F_113 ( V_40 ) ;
unsigned int V_467 ;
struct V_25 * V_468 ;
if ( V_466 + 4 > V_456 ) {
V_2 -> V_469 = true ;
memcpy ( V_2 -> V_470 , V_40 , V_2 -> V_428 ) ;
V_40 = V_2 -> V_470 ;
}
V_248 = F_182 ( V_2 , V_40 + F_181 ( V_2 ) - 1 ,
V_466 - F_181 ( V_2 ) + 1 + 4 ) ;
if ( V_248 < 0 )
return V_248 ;
V_2 -> V_428 += V_248 ;
V_467 = V_466 + 4 - sizeof( struct V_356 ) ;
V_248 = F_168 ( V_2 , V_40 , V_467 , NULL , 0 , 0 ) ;
if ( V_248 )
return V_248 ;
V_468 = F_22 ( V_2 , V_40 ) ;
if ( V_468 == NULL )
F_2 ( V_9 , L_93 ) ;
else {
F_2 ( V_9 , L_94 ) ;
V_468 -> V_465 = true ;
}
* V_26 = V_468 ;
if ( V_468 && V_468 -> V_471 )
return V_468 -> V_471 ( V_2 , V_468 ) ;
return F_185 ( V_2 , V_468 ) ;
}
static int
F_186 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_461 ;
unsigned int V_466 = F_113 ( V_40 ) ;
struct V_356 * V_357 = (struct V_356 * ) V_40 ;
unsigned int V_362 = F_35 ( V_357 -> V_363 ) ;
if ( V_466 + 4 < sizeof( struct V_356 ) +
sizeof( struct V_27 ) ) {
F_2 ( V_8 , L_95 ,
V_466 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_472 ) ;
return - V_473 ;
}
if ( V_466 + 4 < V_362 + sizeof( struct V_356 ) ) {
F_2 ( V_8 , L_96 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_472 ) ;
return - V_473 ;
}
if ( V_466 + 4 > V_474 + F_187 ( V_2 ) )
return F_180 ( V_2 , V_26 ) ;
return F_184 ( V_2 , V_26 ) ;
}
int
F_188 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
char * V_40 = V_2 -> V_469 ? V_2 -> V_470 : V_2 -> V_461 ;
return F_175 ( V_2 , V_26 , V_40 , F_113 ( V_40 ) + 4 ,
NULL , 0 , 0 ) ;
}
