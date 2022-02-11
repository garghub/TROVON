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
static bool
F_94 ( char * V_40 )
{
struct V_27 * V_28 = F_12 ( V_40 ) ;
if ( V_28 -> V_49 != V_250 )
return false ;
F_2 ( V_9 , L_58 ) ;
return true ;
}
static int
F_95 ( struct V_58 * V_59 , struct V_80 * V_81 ,
struct V_148 * V_149 )
{
if ( V_59 -> V_55 -> V_2 -> V_64 & V_251 )
return F_96 ( 0 , V_59 , V_149 -> V_252 ,
F_97 ( V_149 ) ) ;
return F_98 ( 0 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 ,
F_99 ( V_149 ) ? 1 : 0 ) ;
}
static int
F_100 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_253 * V_40 )
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
V_40 -> V_254 = V_255 ;
V_14 = F_101 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_40 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return V_14 ;
}
static bool
F_102 ( struct V_146 * V_256 , struct V_146 * V_257 )
{
return V_256 -> V_81 . V_88 == V_257 -> V_81 . V_88 &&
V_256 -> V_81 . V_89 == V_257 -> V_81 . V_89 ;
}
static int
F_103 ( const unsigned int V_53 , struct V_146 * V_147 , T_1 V_258 ,
T_1 V_248 , T_8 type , int V_259 , int V_260 , bool V_261 )
{
if ( V_260 && ! V_259 )
type = V_262 ;
return F_104 ( V_53 , F_62 ( V_147 -> V_151 ) ,
V_147 -> V_81 . V_88 , V_147 -> V_81 . V_89 ,
V_263 -> V_264 , V_248 , V_258 , type , V_261 ) ;
}
static void
F_105 ( struct V_204 * V_204 , struct V_80 * V_81 )
{
memcpy ( V_81 -> V_252 , F_60 ( V_204 ) -> V_252 , V_265 ) ;
}
static void
F_106 ( struct V_204 * V_204 , struct V_80 * V_81 )
{
memcpy ( F_60 ( V_204 ) -> V_252 , V_81 -> V_252 , V_265 ) ;
}
static void
F_107 ( struct V_80 * V_81 )
{
F_108 ( V_81 -> V_252 ) ;
}
static int
F_109 ( const unsigned int V_53 , struct V_54 * V_55 ,
const char * V_266 ,
struct V_267 * * V_268 ,
unsigned int * V_269 ,
const struct V_270 * V_271 , int V_272 )
{
int V_14 ;
T_2 * V_96 = NULL ;
int V_273 = 0 ;
struct V_58 * V_59 ;
struct V_274 * V_275 = NULL ;
struct V_276 * V_277 = NULL ;
V_184 V_278 = 0 , V_279 = 0 ;
F_2 ( V_9 , L_59 , V_266 ) ;
F_4 ( & V_280 ) ;
V_59 = F_110 ( & V_55 -> V_281 , struct V_58 ,
V_281 ) ;
if ( V_59 )
V_59 -> V_282 ++ ;
F_6 ( & V_280 ) ;
if ( ! V_59 ) {
F_2 ( V_8 , L_60 ,
V_55 ) ;
V_14 = - V_283 ;
goto V_284;
}
V_96 = F_111 ( V_266 , V_103 ,
& V_273 ,
V_271 , V_272 ) ;
if ( ! V_96 ) {
V_14 = - V_97 ;
goto V_284;
}
V_278 = sizeof( * V_275 ) + V_273 ;
V_275 = F_47 ( V_278 , V_104 ) ;
if ( ! V_275 ) {
V_14 = - V_97 ;
goto V_284;
}
V_275 -> V_285 = V_286 ;
memcpy ( V_275 -> V_287 , V_96 , V_273 ) ;
do {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_288 ,
true , true ,
( char * ) V_275 , V_278 ,
( char * * ) & V_277 , & V_279 ) ;
if ( V_14 == - V_283 ) {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_288 ,
true , false ,
( char * ) V_275 , V_278 ,
( char * * ) & V_277 , & V_279 ) ;
}
} while ( V_14 == - V_56 );
if ( V_14 ) {
F_2 ( V_8 , L_61 , V_14 ) ;
goto V_284;
}
V_14 = F_112 ( V_277 , V_279 ,
V_269 , V_268 ,
V_271 , V_272 , V_266 ,
true ) ;
if ( V_14 ) {
F_2 ( V_8 , L_62 , V_14 ) ;
goto V_284;
}
V_284:
if ( V_59 ) {
F_4 ( & V_280 ) ;
V_59 -> V_282 -- ;
F_6 ( & V_280 ) ;
}
F_36 ( V_96 ) ;
F_36 ( V_275 ) ;
F_36 ( V_277 ) ;
return V_14 ;
}
static int
F_113 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_95 , char * * V_289 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_290 * V_291 = NULL ;
struct V_292 * V_293 ;
unsigned int V_294 ;
unsigned int V_295 ;
unsigned int V_296 ;
unsigned int V_297 ;
F_2 ( V_9 , L_63 , V_298 , V_95 ) ;
V_96 = F_44 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , & V_291 ) ;
if ( ! V_14 || ! V_291 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_35 ( V_291 -> V_226 ) < sizeof( struct V_292 ) ||
F_114 ( V_291 ) + 4 < V_299 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
V_14 = 0 ;
V_293 = (struct V_292 * ) V_291 -> V_300 ;
V_294 = F_13 ( V_293 -> V_301 ) ;
V_295 = F_13 ( V_293 -> V_302 ) ;
V_296 = F_13 ( V_293 -> V_303 ) ;
V_297 = F_13 ( V_293 -> V_304 ) ;
if ( F_114 ( V_291 ) + 4 <
V_299 + V_295 + V_294 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_114 ( V_291 ) + 4 <
V_299 + V_297 + V_296 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
* V_289 = F_115 (
( char * ) V_293 -> V_305 + V_295 ,
V_294 , true , V_94 -> V_306 ) ;
if ( ! ( * V_289 ) ) {
F_36 ( V_96 ) ;
return - V_97 ;
}
F_116 ( * V_289 , '/' ) ;
F_2 ( V_9 , L_64 , V_298 , * V_289 ) ;
F_36 ( V_96 ) ;
return V_14 ;
}
static struct V_307 *
F_117 ( struct V_93 * V_94 ,
const struct V_80 * V_308 , V_184 * V_309 )
{
struct V_307 * V_310 = NULL ;
unsigned int V_53 ;
int V_14 = - V_221 ;
struct V_311 * V_151 = F_118 ( V_94 ) ;
if ( F_119 ( V_151 ) )
return F_120 ( V_151 ) ;
V_53 = F_121 () ;
F_2 ( V_9 , L_65 ) ;
V_14 = F_122 ( V_53 , F_62 ( V_151 ) , V_308 -> V_88 ,
V_308 -> V_89 , ( void * * ) & V_310 , V_309 ) ;
F_123 ( V_53 ) ;
F_124 ( V_151 ) ;
F_2 ( V_9 , L_66 , V_298 , V_14 , * V_309 ) ;
if ( V_14 )
return F_125 ( V_14 ) ;
return V_310 ;
}
static struct V_307 *
F_126 ( struct V_93 * V_94 ,
const char * V_241 , V_184 * V_309 )
{
struct V_307 * V_310 = NULL ;
T_3 V_76 = V_77 ;
unsigned int V_53 ;
int V_14 ;
struct V_58 * V_59 ;
struct V_311 * V_151 = F_118 ( V_94 ) ;
struct V_80 V_81 ;
struct V_78 V_79 ;
T_2 * V_96 ;
F_2 ( V_9 , L_67 , V_241 ) ;
if ( F_119 ( V_151 ) )
return F_120 ( V_151 ) ;
V_59 = F_62 ( V_151 ) ;
V_53 = F_121 () ;
if ( F_127 ( V_94 ) )
V_79 . V_86 = V_312 ;
else
V_79 . V_86 = 0 ;
V_96 = F_44 ( V_241 , V_94 ) ;
if ( ! V_96 )
return F_125 ( - V_97 ) ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_313 ;
V_79 . V_84 = V_85 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( ! V_14 ) {
V_14 = F_122 ( V_53 , F_62 ( V_151 ) , V_81 . V_88 ,
V_81 . V_89 , ( void * * ) & V_310 , V_309 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
}
F_124 ( V_151 ) ;
F_123 ( V_53 ) ;
F_2 ( V_9 , L_66 , V_298 , V_14 , * V_309 ) ;
if ( V_14 )
return F_125 ( V_14 ) ;
return V_310 ;
}
static int
F_128 ( struct V_307 * V_314 , T_8 V_315 ,
struct V_204 * V_204 , const char * V_241 , int V_316 )
{
T_3 V_76 = V_77 ;
unsigned int V_53 ;
int V_14 , V_317 = 0 ;
struct V_58 * V_59 ;
struct V_93 * V_94 = F_129 ( V_204 -> V_318 ) ;
struct V_311 * V_151 = F_118 ( V_94 ) ;
struct V_80 V_81 ;
struct V_78 V_79 ;
T_2 * V_96 ;
F_2 ( V_9 , L_68 , V_241 ) ;
if ( F_119 ( V_151 ) )
return F_130 ( V_151 ) ;
V_59 = F_62 ( V_151 ) ;
V_53 = F_121 () ;
if ( F_127 ( V_94 ) )
V_79 . V_86 = V_312 ;
else
V_79 . V_86 = 0 ;
if ( V_316 == V_319 || V_316 == V_320 )
V_317 = V_321 ;
else
V_317 = V_322 ;
V_96 = F_44 ( V_241 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_317 ;
V_79 . V_84 = V_85 ;
V_79 . V_241 = V_241 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( ! V_14 ) {
V_14 = F_131 ( V_53 , F_62 ( V_151 ) , V_81 . V_88 ,
V_81 . V_89 , V_314 , V_315 , V_316 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
}
F_124 ( V_151 ) ;
F_123 ( V_53 ) ;
return V_14 ;
}
static struct V_307 *
F_132 ( struct V_93 * V_94 ,
struct V_204 * V_204 , const char * V_241 ,
V_184 * V_309 )
{
struct V_307 * V_310 = NULL ;
struct V_146 * V_323 = NULL ;
if ( V_204 )
V_323 = F_133 ( F_60 ( V_204 ) , true ) ;
if ( ! V_323 )
return F_126 ( V_94 , V_241 , V_309 ) ;
V_310 = F_117 ( V_94 , & V_323 -> V_81 , V_309 ) ;
F_134 ( V_323 ) ;
return V_310 ;
}
static long F_135 ( struct V_324 * V_324 , struct V_58 * V_59 ,
T_13 V_258 , T_13 V_169 , bool V_325 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_324 -> V_326 ;
struct V_327 V_328 ;
long V_14 ;
unsigned int V_53 ;
V_53 = F_121 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_99 ( V_206 ) )
if ( V_325 == false )
return - V_221 ;
if ( ! ( V_206 -> V_207 & V_208 ) )
return - V_221 ;
if ( V_325 == false )
if ( F_136 ( V_204 ) < V_258 + V_169 )
return - V_221 ;
F_2 ( V_9 , L_69 , V_258 , V_169 ) ;
V_328 . V_329 = F_69 ( V_258 ) ;
V_328 . V_330 = F_69 ( V_258 + V_169 ) ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_331 ,
true , false ,
( char * ) & V_328 ,
sizeof( struct V_327 ) , NULL , NULL ) ;
F_123 ( V_53 ) ;
return V_14 ;
}
static long F_137 ( struct V_324 * V_324 , struct V_58 * V_59 ,
T_13 V_258 , T_13 V_169 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_324 -> V_326 ;
struct V_327 V_328 ;
long V_14 ;
unsigned int V_53 ;
T_4 V_214 = 1 ;
V_53 = F_121 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_78 ( V_53 , V_59 , V_147 , V_204 , V_214 ) )
return - V_221 ;
F_2 ( V_9 , L_69 , V_258 , V_169 ) ;
V_328 . V_329 = F_69 ( V_258 ) ;
V_328 . V_330 = F_69 ( V_258 + V_169 ) ;
V_14 = F_34 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_331 ,
true , false ,
( char * ) & V_328 ,
sizeof( struct V_327 ) , NULL , NULL ) ;
F_123 ( V_53 ) ;
return V_14 ;
}
static long F_138 ( struct V_324 * V_324 , struct V_58 * V_59 ,
T_13 V_332 , T_13 V_169 , bool V_325 )
{
struct V_204 * V_204 ;
struct V_148 * V_206 ;
struct V_146 * V_147 = V_324 -> V_326 ;
long V_14 = - V_221 ;
unsigned int V_53 ;
V_53 = F_121 () ;
V_204 = F_61 ( V_147 -> V_150 ) ;
V_206 = F_60 ( V_204 ) ;
if ( ! F_99 ( V_206 ) )
if ( V_325 == false )
return - V_221 ;
if ( ( V_206 -> V_207 & V_208 ) == 0 ) {
if ( V_325 == true )
return 0 ;
else if ( F_136 ( V_204 ) >= V_332 + V_169 )
return 0 ;
else
return - V_221 ;
}
if ( ( V_325 == true ) || ( F_136 ( V_204 ) >= V_332 + V_169 ) ) {
if ( ( V_332 > 8192 ) || ( V_332 + V_169 + 8192 < F_136 ( V_204 ) ) )
return - V_221 ;
V_14 = F_78 ( V_53 , V_59 , V_147 , V_204 , false ) ;
}
F_123 ( V_53 ) ;
return V_14 ;
}
static long F_139 ( struct V_324 * V_324 , struct V_58 * V_59 , int V_333 ,
T_13 V_332 , T_13 V_169 )
{
if ( V_333 & V_334 )
return F_137 ( V_324 , V_59 , V_332 , V_169 ) ;
else if ( V_333 & V_335 ) {
if ( V_333 & V_336 )
return F_135 ( V_324 , V_59 , V_332 , V_169 , true ) ;
return F_135 ( V_324 , V_59 , V_332 , V_169 , false ) ;
} else if ( V_333 == V_336 )
return F_138 ( V_324 , V_59 , V_332 , V_169 , true ) ;
else if ( V_333 == 0 )
return F_138 ( V_324 , V_59 , V_332 , V_169 , false ) ;
return - V_221 ;
}
static void
F_140 ( struct V_1 * V_2 ,
struct V_148 * V_149 , bool V_337 )
{
if ( V_337 )
V_2 -> V_16 -> V_152 ( V_149 , V_338 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_152 ( V_149 , 0 , 0 , NULL ) ;
}
static void
F_141 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
V_76 &= 0xFF ;
if ( V_76 == V_339 )
return;
if ( V_76 == V_340 ) {
V_149 -> V_76 = V_341 ;
F_2 ( V_9 , L_70 ,
& V_149 -> V_342 ) ;
} else if ( V_76 == V_343 ) {
V_149 -> V_76 = V_344 ;
F_2 ( V_9 , L_71 ,
& V_149 -> V_342 ) ;
} else if ( V_76 == V_338 ) {
V_149 -> V_76 = V_345 ;
F_2 ( V_9 , L_72 ,
& V_149 -> V_342 ) ;
} else
V_149 -> V_76 = 0 ;
}
static void
F_142 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
char V_346 [ 5 ] = { 0 } ;
V_76 &= 0xFF ;
if ( V_76 == V_339 )
return;
V_149 -> V_76 = 0 ;
if ( V_76 & V_347 ) {
V_149 -> V_76 |= V_345 ;
strcat ( V_346 , L_73 ) ;
}
if ( V_76 & V_348 ) {
V_149 -> V_76 |= V_349 ;
strcat ( V_346 , L_74 ) ;
}
if ( V_76 & V_350 ) {
V_149 -> V_76 |= V_351 ;
strcat ( V_346 , L_75 ) ;
}
if ( ! V_149 -> V_76 )
strcat ( V_346 , L_76 ) ;
F_2 ( V_9 , L_77 , V_346 ,
& V_149 -> V_342 ) ;
}
static void
F_143 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
unsigned int V_352 = V_149 -> V_76 ;
F_142 ( V_149 , V_76 , V_153 , V_154 ) ;
if ( V_154 ) {
* V_154 = false ;
if ( V_352 == V_345 ) {
if ( V_149 -> V_76 == V_345 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_353 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_341 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == 0 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
} else if ( V_352 == V_353 ) {
if ( V_149 -> V_76 == V_353 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_341 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
}
V_149 -> V_153 = V_153 ;
}
}
static bool
F_144 ( T_8 V_76 )
{
return V_76 == V_338 ;
}
static bool
F_145 ( T_8 V_76 )
{
return ( V_76 & V_347 ) &&
! ( V_76 & V_350 ) ;
}
static T_14
F_146 ( T_3 V_76 )
{
if ( V_76 == V_343 )
return V_354 | V_355 ;
else if ( V_76 == V_338 )
return V_355 ;
else if ( V_76 == V_340 )
return V_356 | V_355 |
V_354 ;
return 0 ;
}
static char *
F_147 ( T_3 * V_252 , T_3 V_76 )
{
struct V_357 * V_40 ;
V_40 = F_47 ( sizeof( struct V_357 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_358 . V_359 = F_69 ( * ( ( T_5 * ) V_252 ) ) ;
V_40 -> V_358 . V_360 = F_69 ( * ( ( T_5 * ) ( V_252 + 8 ) ) ) ;
V_40 -> V_358 . V_361 = F_146 ( V_76 ) ;
V_40 -> V_362 . V_193 = F_85 ( F_148
( struct V_357 , V_358 ) ) ;
V_40 -> V_362 . V_194 = F_68 ( sizeof( struct V_363 ) ) ;
V_40 -> V_362 . V_364 = F_85 ( F_148
( struct V_357 , V_365 ) ) ;
V_40 -> V_362 . V_366 = F_85 ( 4 ) ;
V_40 -> V_365 [ 0 ] = 'R' ;
V_40 -> V_365 [ 1 ] = 'q' ;
V_40 -> V_365 [ 2 ] = 'L' ;
V_40 -> V_365 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static char *
F_149 ( T_3 * V_252 , T_3 V_76 )
{
struct V_367 * V_40 ;
V_40 = F_47 ( sizeof( struct V_367 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_358 . V_359 = F_69 ( * ( ( T_5 * ) V_252 ) ) ;
V_40 -> V_358 . V_360 = F_69 ( * ( ( T_5 * ) ( V_252 + 8 ) ) ) ;
V_40 -> V_358 . V_361 = F_146 ( V_76 ) ;
V_40 -> V_362 . V_193 = F_85 ( F_148
( struct V_367 , V_358 ) ) ;
V_40 -> V_362 . V_194 = F_68 ( sizeof( struct V_368 ) ) ;
V_40 -> V_362 . V_364 = F_85 ( F_148
( struct V_367 , V_365 ) ) ;
V_40 -> V_362 . V_366 = F_85 ( 4 ) ;
V_40 -> V_365 [ 0 ] = 'R' ;
V_40 -> V_365 [ 1 ] = 'q' ;
V_40 -> V_365 [ 2 ] = 'L' ;
V_40 -> V_365 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static T_4
F_150 ( void * V_40 , unsigned int * V_153 )
{
struct V_357 * V_369 = (struct V_357 * ) V_40 ;
* V_153 = 0 ;
if ( V_369 -> V_358 . V_370 & V_371 )
return V_339 ;
return F_35 ( V_369 -> V_358 . V_361 ) ;
}
static T_4
F_151 ( void * V_40 , unsigned int * V_153 )
{
struct V_367 * V_369 = (struct V_367 * ) V_40 ;
* V_153 = F_13 ( V_369 -> V_358 . V_372 ) ;
if ( V_369 -> V_358 . V_370 & V_371 )
return V_339 ;
return F_35 ( V_369 -> V_358 . V_361 ) ;
}
static unsigned int
F_152 ( struct V_204 * V_204 )
{
return F_19 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_153 ( struct V_146 * V_147 )
{
return ! V_147 -> V_373 ;
}
static void
F_154 ( struct V_374 * V_375 , struct V_376 * V_377 )
{
struct V_27 * V_28 =
(struct V_27 * ) V_377 -> V_378 [ 1 ] . V_379 ;
unsigned int V_380 = F_114 ( V_377 -> V_378 [ 0 ] . V_379 ) ;
memset ( V_375 , 0 , sizeof( struct V_374 ) ) ;
V_375 -> V_43 = V_44 ;
V_375 -> V_381 = F_68 ( V_380 ) ;
V_375 -> V_50 = F_85 ( 0x01 ) ;
F_155 ( & V_375 -> V_382 , V_383 ) ;
memcpy ( & V_375 -> V_384 , & V_28 -> V_384 , 8 ) ;
F_156 ( V_375 , sizeof( struct V_374 ) - 4 ) ;
F_156 ( V_375 , V_380 ) ;
}
static struct V_385 *
F_157 ( struct V_376 * V_386 , T_3 * V_387 )
{
unsigned int V_388 = V_386 -> V_389 + V_386 -> V_390 + 1 ;
unsigned int V_391 = sizeof( struct V_374 ) - 24 ;
struct V_385 * V_392 ;
unsigned int V_105 ;
unsigned int V_393 ;
V_392 = F_158 ( V_388 , sizeof( struct V_385 ) , V_104 ) ;
if ( ! V_392 )
return NULL ;
F_159 ( V_392 , V_388 ) ;
F_160 ( & V_392 [ 0 ] , V_386 -> V_378 [ 0 ] . V_379 + 24 , V_391 ) ;
for ( V_105 = 1 ; V_105 < V_386 -> V_389 ; V_105 ++ )
F_160 ( & V_392 [ V_105 ] , V_386 -> V_378 [ V_105 ] . V_379 ,
V_386 -> V_378 [ V_105 ] . V_394 ) ;
for ( V_393 = 0 ; V_105 < V_388 - 1 ; V_105 ++ , V_393 ++ ) {
unsigned int V_169 = ( V_393 < V_386 -> V_390 - 1 ) ? V_386 -> V_395
: V_386 -> V_396 ;
F_161 ( & V_392 [ V_105 ] , V_386 -> V_397 [ V_393 ] , V_169 , 0 ) ;
}
F_160 ( & V_392 [ V_388 - 1 ] , V_387 , V_398 ) ;
return V_392 ;
}
static void F_162 ( struct V_399 * V_400 , int V_401 )
{
struct V_402 * V_403 = V_400 -> V_99 ;
if ( V_401 == - V_404 )
return;
V_403 -> V_401 = V_401 ;
F_163 ( & V_403 -> V_405 ) ;
}
static int
F_164 ( struct V_1 * V_2 , T_1 V_406 , int V_407 , T_3 * V_408 )
{
struct V_54 * V_55 ;
T_3 * V_409 ;
F_4 ( & V_280 ) ;
F_24 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_55 -> V_410 != V_406 )
continue;
V_409 = V_407 ? V_55 -> V_411 :
V_55 -> V_412 ;
memcpy ( V_408 , V_409 , V_413 ) ;
F_6 ( & V_280 ) ;
return 0 ;
}
F_6 ( & V_280 ) ;
return 1 ;
}
static int
F_165 ( struct V_1 * V_2 , struct V_376 * V_386 , int V_407 )
{
struct V_374 * V_375 =
(struct V_374 * ) V_386 -> V_378 [ 0 ] . V_379 ;
unsigned int V_391 = sizeof( struct V_374 ) - 24 ;
int V_14 = 0 ;
struct V_385 * V_392 ;
T_3 V_387 [ V_398 ] = {} ;
T_3 V_408 [ V_413 ] ;
struct V_414 * V_400 ;
char * V_415 ;
unsigned int V_416 ;
struct V_402 V_417 = { 0 , } ;
struct V_418 * V_419 ;
unsigned int V_420 = F_35 ( V_375 -> V_381 ) ;
F_166 ( & V_417 . V_405 ) ;
V_14 = F_164 ( V_2 , V_375 -> V_384 , V_407 , V_408 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_78 , V_298 ,
V_407 ? L_79 : L_80 ) ;
return 0 ;
}
V_14 = F_167 ( V_2 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_81 , V_298 ) ;
return V_14 ;
}
V_419 = V_407 ? V_2 -> V_421 . V_422 :
V_2 -> V_421 . V_423 ;
V_14 = F_168 ( V_419 , V_408 , V_413 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_82 , V_298 , V_14 ) ;
return V_14 ;
}
V_14 = F_169 ( V_419 , V_398 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_83 , V_298 , V_14 ) ;
return V_14 ;
}
V_400 = F_170 ( V_419 , V_104 ) ;
if ( ! V_400 ) {
F_2 ( V_8 , L_84 , V_298 ) ;
return - V_97 ;
}
if ( ! V_407 ) {
memcpy ( V_387 , & V_375 -> V_424 , V_398 ) ;
V_420 += V_398 ;
}
V_392 = F_157 ( V_386 , V_387 ) ;
if ( ! V_392 ) {
F_2 ( V_8 , L_85 , V_298 ) ;
V_14 = - V_97 ;
goto V_425;
}
V_416 = F_171 ( V_419 ) ;
V_415 = F_47 ( V_416 , V_104 ) ;
if ( ! V_415 ) {
F_2 ( V_8 , L_86 , V_298 ) ;
V_14 = - V_97 ;
goto V_426;
}
V_415 [ 0 ] = 3 ;
memcpy ( V_415 + 1 , ( char * ) V_375 -> V_382 , V_383 ) ;
F_172 ( V_400 , V_392 , V_392 , V_420 , V_415 ) ;
F_173 ( V_400 , V_391 ) ;
F_174 ( V_400 , V_427 ,
F_162 , & V_417 ) ;
V_14 = V_407 ? F_175 ( V_400 ) : F_176 ( V_400 ) ;
if ( V_14 == - V_404 || V_14 == - V_428 ) {
F_177 ( & V_417 . V_405 ) ;
V_14 = V_417 . V_401 ;
}
if ( ! V_14 && V_407 )
memcpy ( & V_375 -> V_424 , V_387 , V_398 ) ;
F_36 ( V_415 ) ;
V_426:
F_36 ( V_392 ) ;
V_425:
F_36 ( V_400 ) ;
return V_14 ;
}
static int
F_178 ( struct V_1 * V_2 , struct V_376 * V_429 ,
struct V_376 * V_377 )
{
struct V_201 * V_202 ;
struct V_430 * * V_431 ;
struct V_374 * V_375 ;
unsigned int V_432 = V_377 -> V_390 ;
int V_105 ;
int V_14 = - V_97 ;
V_431 = F_158 ( V_432 , sizeof( struct V_430 * ) , V_104 ) ;
if ( ! V_431 )
return V_14 ;
V_429 -> V_397 = V_431 ;
V_429 -> V_390 = V_377 -> V_390 ;
V_429 -> V_395 = V_377 -> V_395 ;
V_429 -> V_396 = V_377 -> V_396 ;
for ( V_105 = 0 ; V_105 < V_432 ; V_105 ++ ) {
V_431 [ V_105 ] = F_179 ( V_104 | V_433 ) ;
if ( ! V_431 [ V_105 ] )
goto V_434;
}
V_202 = F_158 ( V_377 -> V_389 , sizeof( struct V_201 ) , V_104 ) ;
if ( ! V_202 )
goto V_434;
memcpy ( & V_202 [ 1 ] , & V_377 -> V_378 [ 1 ] ,
sizeof( struct V_201 ) * ( V_377 -> V_389 - 1 ) ) ;
V_429 -> V_378 = V_202 ;
V_429 -> V_389 = V_377 -> V_389 ;
V_375 = F_67 ( sizeof( struct V_374 ) , V_104 ) ;
if ( ! V_375 )
goto V_435;
F_154 ( V_375 , V_377 ) ;
V_429 -> V_378 [ 0 ] . V_379 = V_375 ;
V_429 -> V_378 [ 0 ] . V_394 = sizeof( struct V_374 ) ;
for ( V_105 = 0 ; V_105 < V_432 ; V_105 ++ ) {
char * V_436 = F_180 ( V_429 -> V_397 [ V_105 ] ) ;
char * V_437 = F_180 ( V_377 -> V_397 [ V_105 ] ) ;
unsigned int V_169 = ( V_105 < V_432 - 1 ) ? V_429 -> V_395 :
V_429 -> V_396 ;
memcpy ( V_436 , V_437 , V_169 ) ;
F_181 ( V_429 -> V_397 [ V_105 ] ) ;
F_181 ( V_377 -> V_397 [ V_105 ] ) ;
}
V_14 = F_165 ( V_2 , V_429 , 1 ) ;
F_2 ( V_9 , L_87 , V_14 ) ;
if ( V_14 )
goto V_438;
return V_14 ;
V_438:
F_36 ( V_375 ) ;
V_435:
F_36 ( V_202 ) ;
V_434:
for ( V_105 = V_105 - 1 ; V_105 >= 0 ; V_105 -- )
F_182 ( V_431 [ V_105 ] ) ;
F_36 ( V_431 ) ;
return V_14 ;
}
static void
F_183 ( struct V_376 * V_386 )
{
int V_105 = V_386 -> V_390 - 1 ;
for (; V_105 >= 0 ; V_105 -- )
F_182 ( V_386 -> V_397 [ V_105 ] ) ;
F_36 ( V_386 -> V_397 ) ;
F_36 ( V_386 -> V_378 [ 0 ] . V_379 ) ;
F_36 ( V_386 -> V_378 ) ;
}
static int
F_184 ( void * V_40 )
{
struct V_374 * V_439 = V_40 ;
return V_439 -> V_43 == V_44 ;
}
static int
F_185 ( struct V_1 * V_2 , char * V_40 ,
unsigned int V_440 , struct V_430 * * V_431 ,
unsigned int V_432 , unsigned int V_441 )
{
struct V_201 V_202 [ 2 ] ;
struct V_376 V_386 = { NULL } ;
struct V_442 * V_443 ;
int V_14 ;
V_202 [ 0 ] . V_379 = V_40 ;
V_202 [ 0 ] . V_394 = sizeof( struct V_374 ) ;
V_202 [ 1 ] . V_379 = V_40 + sizeof( struct V_374 ) ;
V_202 [ 1 ] . V_394 = V_440 ;
V_386 . V_378 = V_202 ;
V_386 . V_389 = 2 ;
V_386 . V_397 = V_431 ;
V_386 . V_390 = V_432 ;
V_386 . V_395 = V_444 ;
V_386 . V_396 = ( V_441 % V_444 ) ? : V_444 ;
V_14 = F_165 ( V_2 , & V_386 , 0 ) ;
F_2 ( V_9 , L_88 , V_14 ) ;
if ( V_14 )
return V_14 ;
memmove ( V_40 + 4 , V_202 [ 1 ] . V_379 , V_440 ) ;
V_443 = (struct V_442 * ) V_40 ;
V_443 -> V_445 = F_186 ( V_440 + V_441 ) ;
V_2 -> V_446 = V_440 + V_441 + 4 ;
return V_14 ;
}
static int
F_187 ( struct V_1 * V_2 , struct V_430 * * V_431 ,
unsigned int V_432 , unsigned int V_169 )
{
int V_105 ;
int V_248 ;
for ( V_105 = 0 ; V_105 < V_432 ; V_105 ++ ) {
struct V_430 * V_430 = V_431 [ V_105 ] ;
T_15 V_447 ;
V_447 = V_169 ;
if ( V_169 >= V_444 ) {
V_447 = V_444 ;
V_169 -= V_447 ;
} else {
F_188 ( V_430 , V_169 , V_444 - V_169 ) ;
V_169 = 0 ;
}
V_248 = F_189 ( V_2 , V_430 , V_447 ) ;
if ( V_248 < 0 )
return V_248 ;
V_2 -> V_446 += V_248 ;
}
return 0 ;
}
static int
F_190 ( struct V_430 * * V_431 , unsigned int V_432 , unsigned int V_448 ,
unsigned int V_449 , struct V_450 * * V_451 )
{
struct V_450 * V_452 ;
int V_105 ;
V_452 = F_191 ( V_432 , sizeof( struct V_450 ) , V_104 ) ;
if ( ! V_452 )
return - V_97 ;
for ( V_105 = 0 ; V_105 < V_432 ; V_105 ++ ) {
V_452 [ V_105 ] . V_453 = V_431 [ V_105 ] ;
V_452 [ V_105 ] . V_454 = ( V_105 == 0 ) ? V_449 : 0 ;
V_452 [ V_105 ] . V_455 = F_19 (unsigned int, PAGE_SIZE, data_size) ;
V_448 -= V_452 [ V_105 ] . V_455 ;
}
if ( V_448 != 0 ) {
F_2 ( V_8 , L_89 , V_298 ) ;
F_36 ( V_452 ) ;
return - V_187 ;
}
* V_451 = V_452 ;
return 0 ;
}
static int
F_192 ( struct V_1 * V_2 , struct V_25 * V_26 ,
char * V_40 , unsigned int V_456 , struct V_430 * * V_431 ,
unsigned int V_432 , unsigned int V_441 )
{
unsigned int V_457 ;
unsigned int V_458 ;
unsigned int V_449 ;
unsigned int V_459 ;
unsigned int V_460 ;
struct V_461 * V_462 = V_26 -> V_463 ;
struct V_27 * V_28 = F_12 ( V_40 ) ;
struct V_450 * V_452 = NULL ;
struct V_464 V_465 ;
struct V_201 V_202 ;
int V_248 ;
if ( V_28 -> V_48 != V_466 ) {
F_2 ( V_8 , L_90 ) ;
return - V_467 ;
}
if ( V_2 -> V_16 -> V_468 &&
V_2 -> V_16 -> V_468 ( V_40 ) ) {
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_469 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_470 &&
V_2 -> V_16 -> V_470 ( V_40 , V_2 , 0 ) )
return - 1 ;
V_462 -> V_417 = V_2 -> V_16 -> V_471 ( V_40 , false ) ;
if ( V_462 -> V_417 != 0 ) {
F_2 ( V_9 , L_91 ,
V_298 , V_462 -> V_417 ) ;
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
V_457 = V_2 -> V_16 -> V_472 ( V_40 ) + 4 ;
V_458 = V_2 -> V_16 -> V_473 ( V_40 ) ;
if ( V_457 < V_2 -> V_474 -> V_475 ) {
F_2 ( V_9 , L_92 ,
V_298 , V_457 ) ;
V_457 = V_2 -> V_474 -> V_475 ;
} else if ( V_457 > V_476 ) {
F_2 ( V_9 , L_93 ,
V_298 , V_457 ) ;
V_462 -> V_417 = - V_187 ;
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
V_460 = V_457 - V_2 -> V_474 -> V_475 ;
if ( V_456 <= V_457 ) {
V_459 = V_460 / V_444 ;
V_449 = V_460 % V_444 ;
if ( V_459 != 0 ) {
F_2 ( V_9 , L_94 ,
V_298 , V_457 ) ;
V_462 -> V_417 = - V_187 ;
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
if ( V_458 > V_441 - V_460 ) {
V_462 -> V_417 = - V_187 ;
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
V_462 -> V_417 = F_190 ( V_431 , V_432 , V_441 ,
V_449 , & V_452 ) ;
if ( V_462 -> V_417 != 0 ) {
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
F_194 ( & V_465 , V_477 | V_478 , V_452 , V_432 , V_458 ) ;
} else if ( V_456 >= V_457 + V_458 ) {
F_195 ( V_432 > 0 , L_95 ) ;
V_202 . V_379 = V_40 + V_457 ;
V_202 . V_394 = V_458 ;
F_196 ( & V_465 , V_477 | V_479 , & V_202 , 1 , V_458 ) ;
} else {
F_195 ( 1 , L_96 ) ;
V_462 -> V_417 = - V_187 ;
F_193 ( V_26 , V_462 -> V_417 ) ;
return 0 ;
}
V_462 -> V_202 [ 0 ] . V_379 = V_40 ;
V_462 -> V_202 [ 0 ] . V_394 = 4 ;
V_462 -> V_202 [ 1 ] . V_379 = V_40 + 4 ;
V_462 -> V_202 [ 1 ] . V_394 = V_2 -> V_474 -> V_475 - 4 ;
F_2 ( V_9 , L_97 ,
V_462 -> V_202 [ 0 ] . V_379 , V_2 -> V_474 -> V_475 ) ;
V_248 = V_462 -> V_480 ( V_2 , V_462 , & V_465 ) ;
F_36 ( V_452 ) ;
if ( V_248 < 0 )
return V_248 ;
F_193 ( V_26 , false ) ;
return V_248 ;
}
static int
F_197 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_481 ;
struct V_374 * V_375 = (struct V_374 * ) V_40 ;
unsigned int V_432 ;
struct V_430 * * V_431 ;
unsigned int V_169 ;
unsigned int V_482 = F_114 ( V_40 ) + 4 ;
int V_14 ;
int V_105 = 0 ;
V_169 = F_19 (unsigned int, buflen, server->vals->read_rsp_size - 4 +
sizeof(struct smb2_transform_hdr)) - F_198 ( V_2 ) + 1 ;
V_14 = F_199 ( V_2 , V_40 + F_198 ( V_2 ) - 1 , V_169 ) ;
if ( V_14 < 0 )
return V_14 ;
V_2 -> V_446 += V_14 ;
V_169 = F_35 ( V_375 -> V_381 ) + 4 -
V_2 -> V_474 -> V_475 ;
V_432 = F_20 ( V_169 , V_444 ) ;
V_431 = F_158 ( V_432 , sizeof( struct V_430 * ) , V_104 ) ;
if ( ! V_431 ) {
V_14 = - V_97 ;
goto V_483;
}
for (; V_105 < V_432 ; V_105 ++ ) {
V_431 [ V_105 ] = F_179 ( V_104 | V_433 ) ;
if ( ! V_431 [ V_105 ] ) {
V_14 = - V_97 ;
goto V_483;
}
}
V_14 = F_187 ( V_2 , V_431 , V_432 , V_169 ) ;
if ( V_14 )
goto V_484;
V_14 = F_200 ( V_2 ) ;
if ( V_14 )
goto V_484;
V_14 = F_185 ( V_2 , V_40 , V_2 -> V_474 -> V_475 - 4 ,
V_431 , V_432 , V_169 ) ;
if ( V_14 )
goto V_484;
* V_26 = F_22 ( V_2 , V_40 ) ;
if ( * V_26 == NULL )
F_2 ( V_9 , L_98 ) ;
else {
F_2 ( V_9 , L_99 ) ;
( * V_26 ) -> V_485 = true ;
V_14 = F_192 ( V_2 , * V_26 , V_40 ,
V_2 -> V_474 -> V_475 ,
V_431 , V_432 , V_169 ) ;
}
V_484:
for ( V_105 = V_105 - 1 ; V_105 >= 0 ; V_105 -- )
F_182 ( V_431 [ V_105 ] ) ;
F_36 ( V_431 ) ;
return V_14 ;
V_483:
F_200 ( V_2 ) ;
goto V_484;
}
static int
F_201 ( struct V_1 * V_2 ,
struct V_25 * * V_26 )
{
int V_248 ;
char * V_40 = V_2 -> V_481 ;
unsigned int V_486 = F_114 ( V_40 ) ;
unsigned int V_487 ;
struct V_25 * V_488 ;
if ( V_486 + 4 > V_476 ) {
V_2 -> V_489 = true ;
memcpy ( V_2 -> V_490 , V_40 , V_2 -> V_446 ) ;
V_40 = V_2 -> V_490 ;
}
V_248 = F_199 ( V_2 , V_40 + F_198 ( V_2 ) - 1 ,
V_486 - F_198 ( V_2 ) + 1 + 4 ) ;
if ( V_248 < 0 )
return V_248 ;
V_2 -> V_446 += V_248 ;
V_487 = V_486 + 4 - sizeof( struct V_374 ) ;
V_248 = F_185 ( V_2 , V_40 , V_487 , NULL , 0 , 0 ) ;
if ( V_248 )
return V_248 ;
V_488 = F_22 ( V_2 , V_40 ) ;
if ( V_488 == NULL )
F_2 ( V_9 , L_98 ) ;
else {
F_2 ( V_9 , L_99 ) ;
V_488 -> V_485 = true ;
}
* V_26 = V_488 ;
if ( V_488 && V_488 -> V_491 )
return V_488 -> V_491 ( V_2 , V_488 ) ;
return F_202 ( V_2 , V_488 ) ;
}
static int
F_203 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_481 ;
unsigned int V_486 = F_114 ( V_40 ) ;
struct V_374 * V_375 = (struct V_374 * ) V_40 ;
unsigned int V_380 = F_35 ( V_375 -> V_381 ) ;
if ( V_486 + 4 < sizeof( struct V_374 ) +
sizeof( struct V_27 ) ) {
F_2 ( V_8 , L_100 ,
V_486 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_469 ) ;
return - V_492 ;
}
if ( V_486 + 4 < V_380 + sizeof( struct V_374 ) ) {
F_2 ( V_8 , L_101 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_469 ) ;
return - V_492 ;
}
if ( V_486 + 4 > V_493 + F_204 ( V_2 ) )
return F_197 ( V_2 , V_26 ) ;
return F_201 ( V_2 , V_26 ) ;
}
int
F_205 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
char * V_40 = V_2 -> V_489 ? V_2 -> V_490 : V_2 -> V_481 ;
return F_192 ( V_2 , V_26 , V_40 , F_114 ( V_40 ) + 4 ,
NULL , 0 , 0 ) ;
}
