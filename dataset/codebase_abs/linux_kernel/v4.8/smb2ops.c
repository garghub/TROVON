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
V_2 -> V_18 -- ;
if ( V_2 -> V_18 == 0 && ( V_12 & V_19 ) != V_20 )
V_14 = F_1 ( V_2 ) ;
else if ( V_2 -> V_18 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_5 ( & V_2 -> V_15 ) ;
F_6 ( & V_2 -> V_21 ) ;
if ( V_14 )
F_7 ( V_2 ) ;
}
static void
F_8 ( struct V_1 * V_2 , const int V_13 )
{
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 = V_13 ;
F_5 ( & V_2 -> V_15 ) ;
}
static int *
F_9 ( struct V_1 * V_2 , const int V_12 )
{
switch ( V_12 ) {
case V_22 :
return & V_2 -> V_4 ;
case V_23 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_10 ( struct V_24 * V_25 )
{
return F_11 ( ( (struct V_26 * ) V_25 -> V_27 ) -> V_28 ) ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned int * V_30 , unsigned int * V_3 )
{
int V_14 = 0 ;
unsigned int V_31 ;
F_4 ( & V_2 -> V_15 ) ;
while ( 1 ) {
if ( V_2 -> V_3 <= 0 ) {
F_5 ( & V_2 -> V_15 ) ;
F_13 ( V_2 ) ;
V_14 = F_14 ( V_2 -> V_21 ,
F_15 ( V_2 , & V_2 -> V_3 ) ) ;
F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_4 ( & V_2 -> V_15 ) ;
} else {
if ( V_2 -> V_32 == V_33 ) {
F_5 ( & V_2 -> V_15 ) ;
return - V_34 ;
}
V_31 = V_2 -> V_3 ;
if ( V_31 == 1 ) {
* V_30 = V_35 ;
* V_3 = 0 ;
break;
}
V_31 -- ;
* V_30 = F_17 (unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE) ;
* V_3 = F_18 ( * V_30 , V_35 ) ;
V_2 -> V_3 -= * V_3 ;
V_2 -> V_18 ++ ;
break;
}
}
F_5 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static T_1
F_19 ( struct V_1 * V_2 )
{
T_1 V_25 ;
F_4 ( & V_36 ) ;
V_25 = V_2 -> V_37 ++ ;
F_5 ( & V_36 ) ;
return V_25 ;
}
static struct V_24 *
F_20 ( struct V_1 * V_2 , char * V_38 )
{
struct V_24 * V_25 ;
struct V_26 * V_39 = (struct V_26 * ) V_38 ;
T_1 V_40 = F_21 ( V_39 -> V_41 ) ;
if ( V_39 -> V_42 == V_43 ) {
F_2 ( V_8 , L_3 ) ;
return NULL ;
}
F_4 ( & V_36 ) ;
F_22 (mid, &server->pending_mid_q, qhead) {
if ( ( V_25 -> V_25 == V_40 ) &&
( V_25 -> V_44 == V_45 ) &&
( V_25 -> V_46 == V_39 -> V_47 ) ) {
F_5 ( & V_36 ) ;
return V_25 ;
}
}
F_5 ( & V_36 ) ;
return NULL ;
}
static void
F_23 ( void * V_38 )
{
#ifdef F_24
struct V_26 * V_48 = (struct V_26 * ) V_38 ;
F_2 ( V_8 , L_4 ,
V_48 -> V_47 , V_48 -> V_49 , V_48 -> V_50 , V_48 -> V_41 ,
V_48 -> V_51 ) ;
F_2 ( V_8 , L_5 , V_48 , F_25 ( V_48 ) ) ;
#endif
}
static bool
F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_52 == 0 ;
}
static int
F_27 ( const unsigned int V_53 , struct V_54 * V_55 )
{
int V_14 ;
V_55 -> V_2 -> V_37 = 0 ;
V_14 = F_28 ( V_53 , V_55 ) ;
if ( V_14 == - V_56 )
V_14 = - V_57 ;
return V_14 ;
}
static unsigned int
F_29 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_62 ;
V_62 = V_61 -> V_62 ? V_61 -> V_62 : V_63 ;
V_62 = F_17 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_62 = F_17 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_62 ;
}
static unsigned int
F_30 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_66 ;
V_66 = V_61 -> V_66 ? V_61 -> V_66 : V_63 ;
V_66 = F_17 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_66 = F_17 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_66 ;
}
static int
F_31 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
unsigned int V_67 = 0 ;
struct V_68 * V_69 ;
V_14 = F_32 ( V_53 , V_59 , V_70 , V_70 ,
V_71 , true ,
NULL , 0 ,
( char * * ) & V_69 , & V_67 ) ;
if ( V_14 != 0 )
F_2 ( V_8 , L_6 , V_14 ) ;
else if ( V_67 < sizeof( struct V_68 ) ) {
F_2 ( V_8 , L_7 ) ;
V_14 = - V_72 ;
} else {
F_2 ( V_9 , L_8 ,
F_33 ( V_69 -> V_73 ) ) ;
F_2 ( V_9 , L_9 ,
F_21 ( V_69 -> V_74 ) ) ;
}
return V_14 ;
}
static void
F_34 ( const unsigned int V_53 , struct V_58 * V_59 )
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
V_14 = F_35 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
#ifdef F_36
F_31 ( V_53 , V_59 ) ;
#endif
F_37 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_37 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_37 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_92 ) ;
F_38 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static void
F_39 ( const unsigned int V_53 , struct V_58 * V_59 )
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
V_14 = F_35 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
F_37 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_37 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_38 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static int
F_40 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_96 = F_41 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_35 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
if ( V_14 ) {
F_42 ( V_96 ) ;
return V_14 ;
}
V_14 = F_38 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
F_42 ( V_96 ) ;
return V_14 ;
}
static int
F_43 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 ,
T_5 * V_98 , T_6 * V_99 )
{
* V_98 = F_21 ( V_99 -> V_100 ) ;
return 0 ;
}
static int
F_44 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_6 * V_99 )
{
int V_14 ;
struct V_101 * V_102 ;
V_102 = F_45 ( sizeof( struct V_101 ) + V_103 * 2 ,
V_104 ) ;
if ( V_102 == NULL )
return - V_97 ;
V_14 = F_46 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ,
V_102 ) ;
if ( ! V_14 )
F_47 ( V_99 , V_102 ) ;
F_42 ( V_102 ) ;
return V_14 ;
}
static bool
F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_49 ( struct V_58 * V_59 )
{
#ifdef F_50
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
F_51 ( & V_59 -> V_107 . V_108 . V_109 [ V_105 ] , 0 ) ;
F_51 ( & V_59 -> V_107 . V_108 . V_110 [ V_105 ] , 0 ) ;
}
#endif
}
static void
F_52 ( struct V_111 * V_112 , struct V_58 * V_59 )
{
F_53 ( V_112 , L_10 ) ;
if ( V_59 -> V_64 & V_113 )
F_53 ( V_112 , L_11 ) ;
if ( V_59 -> V_64 & V_114 )
F_53 ( V_112 , L_12 ) ;
if ( V_59 -> V_64 & V_115 )
F_53 ( V_112 , L_13 ) ;
if ( V_59 -> V_64 & V_116 )
F_53 ( V_112 , L_14 ) ;
if ( V_59 -> V_64 & V_117 )
F_53 ( V_112 , L_15 ) ;
if ( V_59 -> V_64 == 0 )
F_53 ( V_112 , L_16 ) ;
if ( V_59 -> V_118 & V_119 )
F_53 ( V_112 , L_17 ) ;
if ( V_59 -> V_118 & V_120 )
F_53 ( V_112 , L_18 ) ;
if ( V_59 -> V_118 & V_121 )
F_53 ( V_112 , L_19 ) ;
if ( V_59 -> V_118 & V_122 )
F_53 ( V_112 , L_20 ) ;
F_54 ( V_112 , L_21 , V_59 -> V_123 ) ;
if ( V_59 -> V_124 )
F_54 ( V_112 , L_22 ,
V_59 -> V_124 ) ;
}
static void
F_55 ( struct V_111 * V_112 , struct V_58 * V_59 )
{
#ifdef F_50
T_7 * V_125 = V_59 -> V_107 . V_108 . V_109 ;
T_7 * V_126 = V_59 -> V_107 . V_108 . V_110 ;
F_54 ( V_112 , L_23 ,
F_56 ( & V_125 [ V_127 ] ) ,
F_56 ( & V_126 [ V_127 ] ) ) ;
F_54 ( V_112 , L_24 ,
F_56 ( & V_125 [ V_128 ] ) ,
F_56 ( & V_126 [ V_128 ] ) ) ;
F_54 ( V_112 , L_25 ,
F_56 ( & V_125 [ V_129 ] ) ,
F_56 ( & V_126 [ V_129 ] ) ) ;
F_54 ( V_112 , L_26 ,
F_56 ( & V_125 [ V_130 ] ) ,
F_56 ( & V_126 [ V_130 ] ) ) ;
F_54 ( V_112 , L_27 ,
F_56 ( & V_125 [ V_131 ] ) ,
F_56 ( & V_126 [ V_131 ] ) ) ;
F_54 ( V_112 , L_28 ,
F_56 ( & V_125 [ V_132 ] ) ,
F_56 ( & V_126 [ V_132 ] ) ) ;
F_54 ( V_112 , L_29 ,
F_56 ( & V_125 [ V_133 ] ) ,
F_56 ( & V_126 [ V_133 ] ) ) ;
F_54 ( V_112 , L_30 ,
F_56 ( & V_125 [ V_134 ] ) ,
F_56 ( & V_126 [ V_134 ] ) ) ;
F_54 ( V_112 , L_31 ,
F_56 ( & V_125 [ V_135 ] ) ,
F_56 ( & V_126 [ V_135 ] ) ) ;
F_54 ( V_112 , L_32 ,
F_56 ( & V_125 [ V_136 ] ) ,
F_56 ( & V_126 [ V_136 ] ) ) ;
F_54 ( V_112 , L_33 ,
F_56 ( & V_125 [ V_137 ] ) ,
F_56 ( & V_126 [ V_137 ] ) ) ;
F_54 ( V_112 , L_34 ,
F_56 ( & V_125 [ V_138 ] ) ,
F_56 ( & V_126 [ V_138 ] ) ) ;
F_54 ( V_112 , L_35 ,
F_56 ( & V_125 [ V_139 ] ) ,
F_56 ( & V_126 [ V_139 ] ) ) ;
F_54 ( V_112 , L_36 ,
F_56 ( & V_125 [ V_140 ] ) ,
F_56 ( & V_126 [ V_140 ] ) ) ;
F_54 ( V_112 , L_37 ,
F_56 ( & V_125 [ V_141 ] ) ,
F_56 ( & V_126 [ V_141 ] ) ) ;
F_54 ( V_112 , L_38 ,
F_56 ( & V_125 [ V_142 ] ) ,
F_56 ( & V_126 [ V_142 ] ) ) ;
F_54 ( V_112 , L_39 ,
F_56 ( & V_125 [ V_143 ] ) ,
F_56 ( & V_126 [ V_143 ] ) ) ;
F_54 ( V_112 , L_40 ,
F_56 ( & V_125 [ V_144 ] ) ,
F_56 ( & V_126 [ V_144 ] ) ) ;
F_54 ( V_112 , L_41 ,
F_56 ( & V_125 [ V_145 ] ) ,
F_56 ( & V_126 [ V_145 ] ) ) ;
#endif
}
static void
F_57 ( struct V_146 * V_147 , struct V_80 * V_81 , T_8 V_76 )
{
struct V_148 * V_149 = F_58 ( F_59 ( V_147 -> V_150 ) ) ;
struct V_1 * V_2 = F_60 ( V_147 -> V_151 ) -> V_55 -> V_2 ;
V_147 -> V_81 . V_88 = V_81 -> V_88 ;
V_147 -> V_81 . V_89 = V_81 -> V_89 ;
V_2 -> V_16 -> V_152 ( V_149 , V_76 , V_81 -> V_153 ,
& V_81 -> V_154 ) ;
V_149 -> V_155 = F_61 ( V_149 ) ;
}
static void
F_62 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
F_38 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static int
F_63 ( const unsigned int V_53 , struct V_58 * V_59 ,
T_5 V_88 , T_5 V_89 ,
struct V_156 * V_157 )
{
int V_14 ;
unsigned int V_67 ;
struct V_158 * V_159 ;
V_14 = F_32 ( V_53 , V_59 , V_88 , V_89 ,
V_160 , true ,
NULL , 0 ,
( char * * ) & V_159 , & V_67 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_42 , V_14 ) ;
goto V_161;
}
if ( V_67 < sizeof( struct V_158 ) ) {
F_2 ( V_8 , L_43 ) ;
V_14 = - V_72 ;
goto V_161;
}
memcpy ( V_157 -> V_162 , V_159 -> V_163 , V_164 ) ;
V_161:
F_42 ( V_159 ) ;
return V_14 ;
}
static int
F_64 ( const unsigned int V_53 ,
struct V_146 * V_165 ,
struct V_146 * V_166 , T_5 V_167 ,
T_5 V_168 , T_5 V_169 )
{
int V_14 ;
unsigned int V_67 ;
struct V_156 * V_157 ;
struct V_170 * V_171 = NULL ;
struct V_58 * V_59 ;
int V_172 = 0 ;
bool V_173 = false ;
V_157 = F_65 ( sizeof( struct V_156 ) , V_104 ) ;
if ( V_157 == NULL )
return - V_97 ;
F_2 ( V_9 , L_44 ) ;
V_14 = F_63 ( V_53 , F_60 ( V_165 -> V_151 ) ,
V_165 -> V_81 . V_88 ,
V_165 -> V_81 . V_89 , V_157 ) ;
if ( V_14 )
goto V_174;
V_157 -> V_175 = F_66 ( 1 ) ;
V_157 -> V_176 = 0 ;
V_157 -> V_177 = 0 ;
V_59 = F_60 ( V_166 -> V_151 ) ;
while ( V_168 > 0 ) {
V_157 -> V_178 = F_67 ( V_167 ) ;
V_157 -> V_179 = F_67 ( V_169 ) ;
V_157 -> V_180 =
F_66 ( F_17 ( V_181 , V_168 , V_59 -> V_182 ) ) ;
V_14 = F_32 ( V_53 , V_59 , V_166 -> V_81 . V_88 ,
V_166 -> V_81 . V_89 , V_183 ,
true , ( char * ) V_157 ,
sizeof( struct V_156 ) , ( char * * ) & V_171 ,
& V_67 ) ;
if ( V_14 == 0 ) {
if ( V_67 !=
sizeof( struct V_170 ) ) {
F_2 ( V_8 , L_45 ) ;
V_14 = - V_184 ;
goto V_174;
}
if ( V_171 -> V_185 == 0 ) {
F_2 ( V_9 , L_46 ) ;
V_14 = - V_184 ;
goto V_174;
}
if ( F_33 ( V_171 -> V_185 ) >
F_33 ( V_157 -> V_180 ) ) {
F_2 ( V_8 , L_47 ) ;
V_14 = - V_184 ;
goto V_174;
}
if ( F_33 ( V_171 -> V_186 ) != 1 ) {
F_2 ( V_8 , L_48 ) ;
V_14 = - V_184 ;
goto V_174;
}
V_172 ++ ;
V_167 += F_33 ( V_171 -> V_185 ) ;
V_169 += F_33 ( V_171 -> V_185 ) ;
V_168 -= F_33 ( V_171 -> V_185 ) ;
F_2 ( V_9 , L_49 ,
F_33 ( V_171 -> V_186 ) ,
F_33 ( V_171 -> V_187 ) ,
F_33 ( V_171 -> V_185 ) ) ;
} else if ( V_14 == - V_72 ) {
if ( V_67 != sizeof( struct V_170 ) )
goto V_174;
F_2 ( V_9 , L_50 ,
F_33 ( V_171 -> V_186 ) ,
F_33 ( V_171 -> V_187 ) ,
F_33 ( V_171 -> V_185 ) ) ;
if ( ( V_172 != 0 ) || V_173 )
goto V_174;
if ( F_33 ( V_171 -> V_187 ) <
V_59 -> V_182 )
V_59 -> V_182 =
F_33 ( V_171 -> V_187 ) ;
else
goto V_174;
V_173 = true ;
} else
goto V_174;
}
V_174:
F_42 ( V_157 ) ;
return V_14 ;
}
static int
F_68 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_69 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static unsigned int
F_70 ( char * V_38 )
{
struct V_188 * V_189 = (struct V_188 * ) V_38 ;
return V_189 -> V_190 ;
}
static unsigned int
F_71 ( char * V_38 )
{
struct V_188 * V_189 = (struct V_188 * ) V_38 ;
return F_33 ( V_189 -> V_191 ) ;
}
static int
F_72 ( const unsigned int V_53 , struct V_80 * V_192 ,
struct V_193 * V_194 , unsigned int * V_195 ,
char * * V_38 , int * V_196 )
{
V_194 -> V_88 = V_192 -> V_88 ;
V_194 -> V_89 = V_192 -> V_89 ;
return F_73 ( V_53 , V_194 , V_195 , V_38 , V_196 ) ;
}
static int
F_74 ( const unsigned int V_53 , struct V_80 * V_192 ,
struct V_193 * V_194 , unsigned int * V_197 ,
struct V_198 * V_199 , unsigned long V_200 )
{
V_194 -> V_88 = V_192 -> V_88 ;
V_194 -> V_89 = V_192 -> V_89 ;
return F_75 ( V_53 , V_194 , V_197 , V_199 , V_200 ) ;
}
static bool F_76 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 , struct V_201 * V_201 , T_4 V_202 )
{
struct V_148 * V_203 ;
int V_14 ;
V_203 = F_58 ( V_201 ) ;
if ( ( V_203 -> V_204 & V_205 ) && V_202 )
return true ;
if ( ! ( V_203 -> V_204 & V_205 ) && ! V_202 )
return true ;
if ( V_59 -> V_206 )
return false ;
V_14 = F_32 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_207 ,
true , & V_202 , 1 , NULL , NULL ) ;
if ( V_14 ) {
V_59 -> V_206 = true ;
F_2 ( V_9 , L_51 , V_14 ) ;
return false ;
}
if ( V_202 )
V_203 -> V_204 |= V_205 ;
else
V_203 -> V_204 &= ( ~ V_205 ) ;
return true ;
}
static int
F_77 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 , T_1 V_29 , bool V_208 )
{
T_9 V_209 = F_67 ( V_29 ) ;
struct V_201 * V_201 ;
V_201 = F_59 ( V_147 -> V_150 ) ;
if ( ! V_208 && ( V_29 > V_201 -> V_210 + 8192 ) ) {
T_4 V_211 = 1 ;
F_76 ( V_53 , V_59 , V_147 , V_201 , V_211 ) ;
}
return F_78 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_147 -> V_212 , & V_209 , false ) ;
}
static int
F_79 ( const unsigned int V_53 ,
struct V_146 * V_165 ,
struct V_146 * V_166 , T_5 V_167 ,
T_5 V_168 , T_5 V_169 )
{
int V_14 ;
unsigned int V_67 ;
char * V_171 = NULL ;
struct V_213 V_214 ;
struct V_58 * V_59 = F_60 ( V_166 -> V_151 ) ;
if ( ( F_33 ( V_59 -> V_215 . V_216 ) &
V_217 ) == 0 )
return - V_218 ;
V_214 . V_219 = V_165 -> V_81 . V_89 ;
V_214 . V_220 = V_165 -> V_81 . V_88 ;
V_214 . V_221 = F_67 ( V_167 ) ;
V_214 . V_222 = F_67 ( V_169 ) ;
V_214 . V_223 = F_67 ( V_168 ) ;
F_2 ( V_9 , L_52 ,
V_167 , V_169 , V_168 ) ;
V_14 = F_77 ( V_53 , V_59 , V_166 , V_169 + V_168 , false ) ;
if ( V_14 )
goto V_224;
V_14 = F_32 ( V_53 , V_59 , V_166 -> V_81 . V_88 ,
V_166 -> V_81 . V_89 ,
V_225 ,
true , ( char * ) & V_214 ,
sizeof( struct V_213 ) ,
( char * * ) & V_171 ,
& V_67 ) ;
if ( V_67 > 0 )
F_2 ( V_9 , L_53 ) ;
V_224:
return V_14 ;
}
static int
F_80 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 )
{
return F_81 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 ) ;
}
static int
F_82 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_146 * V_147 )
{
struct V_226 V_227 ;
char * V_171 = NULL ;
unsigned int V_67 ;
V_227 . V_228 = F_83 ( V_229 ) ;
V_227 . V_50 = 0 ;
V_227 . V_176 = 0 ;
return F_32 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 ,
V_230 ,
true , ( char * ) & V_227 ,
sizeof( struct V_226 ) ,
( char * * ) & V_171 ,
& V_67 ) ;
}
static int
F_84 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_231 , struct V_93 * V_94 ,
struct V_80 * V_81 , T_10 V_232 ,
struct V_233 * V_234 )
{
T_2 * V_96 ;
int V_14 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
V_96 = F_41 ( V_231 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 | V_235 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = V_81 ;
V_79 . V_87 = false ;
V_14 = F_35 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_42 ( V_96 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_54 ) ;
return V_14 ;
}
V_234 -> V_236 = 0 ;
V_234 -> V_237 = 0 ;
V_14 = F_85 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_234 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_55 ) ;
F_38 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
return V_14 ;
}
static int
F_86 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_10 V_232 ,
struct V_233 * V_234 )
{
return F_85 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_234 ) ;
}
static int
F_87 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_38 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static bool
F_88 ( char * V_38 , struct V_1 * V_2 , int V_238 )
{
struct V_26 * V_39 = (struct V_26 * ) V_38 ;
if ( V_39 -> V_49 != V_239 )
return false ;
if ( ! V_238 ) {
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 += F_11 ( V_39 -> V_28 ) ;
F_5 ( & V_2 -> V_15 ) ;
F_6 ( & V_2 -> V_21 ) ;
}
return true ;
}
static int
F_89 ( struct V_58 * V_59 , struct V_80 * V_81 ,
struct V_148 * V_149 )
{
if ( V_59 -> V_55 -> V_2 -> V_64 & V_240 )
return F_90 ( 0 , V_59 , V_149 -> V_241 ,
F_91 ( V_149 ) ) ;
return F_92 ( 0 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 ,
F_93 ( V_149 ) ? 1 : 0 ) ;
}
static int
F_94 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_242 * V_38 )
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
V_14 = F_35 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return V_14 ;
V_38 -> V_243 = V_244 ;
V_14 = F_95 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_38 ) ;
F_38 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return V_14 ;
}
static bool
F_96 ( struct V_146 * V_245 , struct V_146 * V_246 )
{
return V_245 -> V_81 . V_88 == V_246 -> V_81 . V_88 &&
V_245 -> V_81 . V_89 == V_246 -> V_81 . V_89 ;
}
static int
F_97 ( const unsigned int V_53 , struct V_146 * V_147 , T_1 V_247 ,
T_1 V_238 , T_8 type , int V_248 , int V_249 , bool V_250 )
{
if ( V_249 && ! V_248 )
type = V_251 ;
return F_98 ( V_53 , F_60 ( V_147 -> V_151 ) ,
V_147 -> V_81 . V_88 , V_147 -> V_81 . V_89 ,
V_252 -> V_253 , V_238 , V_247 , type , V_250 ) ;
}
static void
F_99 ( struct V_201 * V_201 , struct V_80 * V_81 )
{
memcpy ( V_81 -> V_241 , F_58 ( V_201 ) -> V_241 , V_254 ) ;
}
static void
F_100 ( struct V_201 * V_201 , struct V_80 * V_81 )
{
memcpy ( F_58 ( V_201 ) -> V_241 , V_81 -> V_241 , V_254 ) ;
}
static void
F_101 ( struct V_80 * V_81 )
{
F_102 ( V_81 -> V_241 , V_254 ) ;
}
static int
F_103 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_95 , char * * V_255 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_256 * V_257 = NULL ;
struct V_258 * V_259 ;
unsigned int V_260 ;
unsigned int V_261 ;
unsigned int V_262 ;
unsigned int V_263 ;
F_2 ( V_9 , L_56 , V_264 , V_95 ) ;
V_96 = F_41 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_35 ( V_53 , & V_79 , V_96 , & V_76 , NULL , & V_257 ) ;
if ( ! V_14 || ! V_257 ) {
F_42 ( V_96 ) ;
return - V_34 ;
}
if ( F_33 ( V_257 -> V_223 ) < sizeof( struct V_258 ) ||
F_104 ( V_257 ) + 4 < V_265 ) {
F_42 ( V_96 ) ;
return - V_34 ;
}
V_14 = 0 ;
V_259 = (struct V_258 * ) V_257 -> V_266 ;
V_260 = F_11 ( V_259 -> V_267 ) ;
V_261 = F_11 ( V_259 -> V_268 ) ;
V_262 = F_11 ( V_259 -> V_269 ) ;
V_263 = F_11 ( V_259 -> V_270 ) ;
if ( F_104 ( V_257 ) + 4 <
V_265 + V_261 + V_260 ) {
F_42 ( V_96 ) ;
return - V_34 ;
}
if ( F_104 ( V_257 ) + 4 <
V_265 + V_263 + V_262 ) {
F_42 ( V_96 ) ;
return - V_34 ;
}
* V_255 = F_105 (
( char * ) V_259 -> V_271 + V_261 ,
V_260 , true , V_94 -> V_272 ) ;
if ( ! ( * V_255 ) ) {
F_42 ( V_96 ) ;
return - V_97 ;
}
F_106 ( * V_255 , '/' ) ;
F_2 ( V_9 , L_57 , V_264 , * V_255 ) ;
F_42 ( V_96 ) ;
return V_14 ;
}
static long F_107 ( struct V_273 * V_273 , struct V_58 * V_59 ,
T_11 V_247 , T_11 V_168 , bool V_274 )
{
struct V_201 * V_201 ;
struct V_148 * V_203 ;
struct V_146 * V_147 = V_273 -> V_275 ;
struct V_276 V_277 ;
long V_14 ;
unsigned int V_53 ;
V_53 = F_108 () ;
V_201 = F_59 ( V_147 -> V_150 ) ;
V_203 = F_58 ( V_201 ) ;
if ( ! F_93 ( V_203 ) )
if ( V_274 == false )
return - V_218 ;
if ( ! ( V_203 -> V_204 & V_205 ) )
return - V_218 ;
if ( V_274 == false )
if ( F_109 ( V_201 ) < V_247 + V_168 )
return - V_218 ;
F_2 ( V_9 , L_58 , V_247 , V_168 ) ;
V_277 . V_278 = F_67 ( V_247 ) ;
V_277 . V_279 = F_67 ( V_247 + V_168 ) ;
V_14 = F_32 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_280 ,
true , ( char * ) & V_277 ,
sizeof( struct V_276 ) , NULL , NULL ) ;
F_110 ( V_53 ) ;
return V_14 ;
}
static long F_111 ( struct V_273 * V_273 , struct V_58 * V_59 ,
T_11 V_247 , T_11 V_168 )
{
struct V_201 * V_201 ;
struct V_148 * V_203 ;
struct V_146 * V_147 = V_273 -> V_275 ;
struct V_276 V_277 ;
long V_14 ;
unsigned int V_53 ;
T_4 V_211 = 1 ;
V_53 = F_108 () ;
V_201 = F_59 ( V_147 -> V_150 ) ;
V_203 = F_58 ( V_201 ) ;
if ( ! F_76 ( V_53 , V_59 , V_147 , V_201 , V_211 ) )
return - V_218 ;
F_2 ( V_9 , L_58 , V_247 , V_168 ) ;
V_277 . V_278 = F_67 ( V_247 ) ;
V_277 . V_279 = F_67 ( V_247 + V_168 ) ;
V_14 = F_32 ( V_53 , V_59 , V_147 -> V_81 . V_88 ,
V_147 -> V_81 . V_89 , V_280 ,
true , ( char * ) & V_277 ,
sizeof( struct V_276 ) , NULL , NULL ) ;
F_110 ( V_53 ) ;
return V_14 ;
}
static long F_112 ( struct V_273 * V_273 , struct V_58 * V_59 ,
T_11 V_281 , T_11 V_168 , bool V_274 )
{
struct V_201 * V_201 ;
struct V_148 * V_203 ;
struct V_146 * V_147 = V_273 -> V_275 ;
long V_14 = - V_218 ;
unsigned int V_53 ;
V_53 = F_108 () ;
V_201 = F_59 ( V_147 -> V_150 ) ;
V_203 = F_58 ( V_201 ) ;
if ( ! F_93 ( V_203 ) )
if ( V_274 == false )
return - V_218 ;
if ( ( V_203 -> V_204 & V_205 ) == 0 ) {
if ( V_274 == true )
return 0 ;
else if ( F_109 ( V_201 ) >= V_281 + V_168 )
return 0 ;
else
return - V_218 ;
}
if ( ( V_274 == true ) || ( F_109 ( V_201 ) >= V_281 + V_168 ) ) {
if ( ( V_281 > 8192 ) || ( V_281 + V_168 + 8192 < F_109 ( V_201 ) ) )
return - V_218 ;
V_14 = F_76 ( V_53 , V_59 , V_147 , V_201 , false ) ;
}
F_110 ( V_53 ) ;
return V_14 ;
}
static long F_113 ( struct V_273 * V_273 , struct V_58 * V_59 , int V_282 ,
T_11 V_281 , T_11 V_168 )
{
if ( V_282 & V_283 )
return F_111 ( V_273 , V_59 , V_281 , V_168 ) ;
else if ( V_282 & V_284 ) {
if ( V_282 & V_285 )
return F_107 ( V_273 , V_59 , V_281 , V_168 , true ) ;
return F_107 ( V_273 , V_59 , V_281 , V_168 , false ) ;
} else if ( V_282 == V_285 )
return F_112 ( V_273 , V_59 , V_281 , V_168 , true ) ;
else if ( V_282 == 0 )
return F_112 ( V_273 , V_59 , V_281 , V_168 , false ) ;
return - V_218 ;
}
static void
F_114 ( struct V_1 * V_2 ,
struct V_148 * V_149 , bool V_286 )
{
if ( V_286 )
V_2 -> V_16 -> V_152 ( V_149 , V_287 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_152 ( V_149 , 0 , 0 , NULL ) ;
}
static void
F_115 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
V_76 &= 0xFF ;
if ( V_76 == V_288 )
return;
if ( V_76 == V_289 ) {
V_149 -> V_76 = V_290 ;
F_2 ( V_9 , L_59 ,
& V_149 -> V_291 ) ;
} else if ( V_76 == V_292 ) {
V_149 -> V_76 = V_293 ;
F_2 ( V_9 , L_60 ,
& V_149 -> V_291 ) ;
} else if ( V_76 == V_287 ) {
V_149 -> V_76 = V_294 ;
F_2 ( V_9 , L_61 ,
& V_149 -> V_291 ) ;
} else
V_149 -> V_76 = 0 ;
}
static void
F_116 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
char V_295 [ 5 ] = { 0 } ;
V_76 &= 0xFF ;
if ( V_76 == V_288 )
return;
V_149 -> V_76 = 0 ;
if ( V_76 & V_296 ) {
V_149 -> V_76 |= V_294 ;
strcat ( V_295 , L_62 ) ;
}
if ( V_76 & V_297 ) {
V_149 -> V_76 |= V_298 ;
strcat ( V_295 , L_63 ) ;
}
if ( V_76 & V_299 ) {
V_149 -> V_76 |= V_300 ;
strcat ( V_295 , L_64 ) ;
}
if ( ! V_149 -> V_76 )
strcat ( V_295 , L_65 ) ;
F_2 ( V_9 , L_66 , V_295 ,
& V_149 -> V_291 ) ;
}
static void
F_117 ( struct V_148 * V_149 , T_8 V_76 ,
unsigned int V_153 , bool * V_154 )
{
unsigned int V_301 = V_149 -> V_76 ;
F_116 ( V_149 , V_76 , V_153 , V_154 ) ;
if ( V_154 ) {
* V_154 = false ;
if ( V_301 == V_294 ) {
if ( V_149 -> V_76 == V_294 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_302 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_290 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == 0 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
} else if ( V_301 == V_302 ) {
if ( V_149 -> V_76 == V_302 &&
( V_153 - V_149 -> V_153 > 0 ) )
* V_154 = true ;
else if ( V_149 -> V_76 == V_290 &&
( V_153 - V_149 -> V_153 > 1 ) )
* V_154 = true ;
}
V_149 -> V_153 = V_153 ;
}
}
static bool
F_118 ( T_8 V_76 )
{
return V_76 == V_287 ;
}
static bool
F_119 ( T_8 V_76 )
{
return ( V_76 & V_296 ) &&
! ( V_76 & V_299 ) ;
}
static T_12
F_120 ( T_3 V_76 )
{
if ( V_76 == V_292 )
return V_303 | V_304 ;
else if ( V_76 == V_287 )
return V_304 ;
else if ( V_76 == V_289 )
return V_305 | V_304 |
V_303 ;
return 0 ;
}
static char *
F_121 ( T_3 * V_241 , T_3 V_76 )
{
struct V_306 * V_38 ;
V_38 = F_45 ( sizeof( struct V_306 ) , V_104 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_307 . V_308 = F_67 ( * ( ( T_5 * ) V_241 ) ) ;
V_38 -> V_307 . V_309 = F_67 ( * ( ( T_5 * ) ( V_241 + 8 ) ) ) ;
V_38 -> V_307 . V_310 = F_120 ( V_76 ) ;
V_38 -> V_311 . V_190 = F_83 ( F_122
( struct V_306 , V_307 ) ) ;
V_38 -> V_311 . V_191 = F_66 ( sizeof( struct V_312 ) ) ;
V_38 -> V_311 . V_313 = F_83 ( F_122
( struct V_306 , V_314 ) ) ;
V_38 -> V_311 . V_315 = F_83 ( 4 ) ;
V_38 -> V_314 [ 0 ] = 'R' ;
V_38 -> V_314 [ 1 ] = 'q' ;
V_38 -> V_314 [ 2 ] = 'L' ;
V_38 -> V_314 [ 3 ] = 's' ;
return ( char * ) V_38 ;
}
static char *
F_123 ( T_3 * V_241 , T_3 V_76 )
{
struct V_316 * V_38 ;
V_38 = F_45 ( sizeof( struct V_316 ) , V_104 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_307 . V_308 = F_67 ( * ( ( T_5 * ) V_241 ) ) ;
V_38 -> V_307 . V_309 = F_67 ( * ( ( T_5 * ) ( V_241 + 8 ) ) ) ;
V_38 -> V_307 . V_310 = F_120 ( V_76 ) ;
V_38 -> V_311 . V_190 = F_83 ( F_122
( struct V_316 , V_307 ) ) ;
V_38 -> V_311 . V_191 = F_66 ( sizeof( struct V_317 ) ) ;
V_38 -> V_311 . V_313 = F_83 ( F_122
( struct V_316 , V_314 ) ) ;
V_38 -> V_311 . V_315 = F_83 ( 4 ) ;
V_38 -> V_314 [ 0 ] = 'R' ;
V_38 -> V_314 [ 1 ] = 'q' ;
V_38 -> V_314 [ 2 ] = 'L' ;
V_38 -> V_314 [ 3 ] = 's' ;
return ( char * ) V_38 ;
}
static T_4
F_124 ( void * V_38 , unsigned int * V_153 )
{
struct V_306 * V_318 = (struct V_306 * ) V_38 ;
* V_153 = 0 ;
if ( V_318 -> V_307 . V_319 & V_320 )
return V_288 ;
return F_33 ( V_318 -> V_307 . V_310 ) ;
}
static T_4
F_125 ( void * V_38 , unsigned int * V_153 )
{
struct V_316 * V_318 = (struct V_316 * ) V_38 ;
* V_153 = F_11 ( V_318 -> V_307 . V_321 ) ;
if ( V_318 -> V_307 . V_319 & V_320 )
return V_288 ;
return F_33 ( V_318 -> V_307 . V_310 ) ;
}
static unsigned int
F_126 ( struct V_201 * V_201 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_127 ( struct V_146 * V_147 )
{
return ! V_147 -> V_322 ;
}
