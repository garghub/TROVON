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
F_4 ( & V_36 ) ;
F_22 (mid, &server->pending_mid_q, qhead) {
if ( ( V_25 -> V_25 == V_40 ) &&
( V_25 -> V_42 == V_43 ) &&
( V_25 -> V_44 == V_39 -> V_45 ) ) {
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
struct V_26 * V_46 = (struct V_26 * ) V_38 ;
F_2 ( V_8 , L_3 ,
V_46 -> V_45 , V_46 -> V_47 , V_46 -> V_48 , V_46 -> V_41 ,
V_46 -> V_49 ) ;
F_2 ( V_8 , L_4 , V_46 , F_25 ( V_46 ) ) ;
#endif
}
static bool
F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_50 == 0 ;
}
static int
F_27 ( const unsigned int V_51 , struct V_52 * V_53 )
{
int V_14 ;
V_53 -> V_2 -> V_37 = 0 ;
V_14 = F_28 ( V_51 , V_53 ) ;
if ( V_14 == - V_54 )
V_14 = - V_55 ;
return V_14 ;
}
static unsigned int
F_29 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_53 -> V_2 ;
unsigned int V_60 ;
V_60 = V_59 -> V_60 ? V_59 -> V_60 : V_61 ;
V_60 = F_17 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_62 & V_63 ) )
V_60 = F_17 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_60 ;
}
static unsigned int
F_30 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_53 -> V_2 ;
unsigned int V_64 ;
V_64 = V_59 -> V_64 ? V_59 -> V_64 : V_61 ;
V_64 = F_17 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_62 & V_63 ) )
V_64 = F_17 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_64 ;
}
static int
F_31 ( const unsigned int V_51 , struct V_56 * V_57 )
{
int V_14 ;
unsigned int V_65 = 0 ;
struct V_66 * V_67 ;
V_14 = F_32 ( V_51 , V_57 , V_68 , V_68 ,
V_69 , true ,
NULL , 0 ,
( char * * ) & V_67 , & V_65 ) ;
if ( V_14 != 0 )
F_2 ( V_8 , L_5 , V_14 ) ;
else if ( V_65 < sizeof( struct V_66 ) ) {
F_2 ( V_8 , L_6 ) ;
V_14 = - V_70 ;
} else {
F_2 ( V_9 , L_7 ,
F_33 ( V_67 -> V_71 ) ) ;
F_2 ( V_9 , L_8 ,
F_21 ( V_67 -> V_72 ) ) ;
}
return V_14 ;
}
static void
F_34 ( const unsigned int V_51 , struct V_56 * V_57 )
{
int V_14 ;
T_2 V_73 = 0 ;
T_3 V_74 = V_75 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = & V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , & V_73 , & V_74 , NULL , NULL ) ;
if ( V_14 )
return;
#ifdef F_36
F_31 ( V_51 , V_57 ) ;
#endif
F_37 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_88 ) ;
F_37 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_89 ) ;
F_37 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_90 ) ;
F_38 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ) ;
return;
}
static void
F_39 ( const unsigned int V_51 , struct V_56 * V_57 )
{
int V_14 ;
T_2 V_73 = 0 ;
T_3 V_74 = V_75 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = & V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , & V_73 , & V_74 , NULL , NULL ) ;
if ( V_14 )
return;
F_37 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_88 ) ;
F_37 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_89 ) ;
F_38 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ) ;
return;
}
static int
F_40 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_91 * V_92 , const char * V_93 )
{
int V_14 ;
T_2 * V_94 ;
T_4 V_74 = V_75 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
V_94 = F_41 ( V_93 , V_92 ) ;
if ( ! V_94 )
return - V_95 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = & V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , V_94 , & V_74 , NULL , NULL ) ;
if ( V_14 ) {
F_42 ( V_94 ) ;
return V_14 ;
}
V_14 = F_38 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ) ;
F_42 ( V_94 ) ;
return V_14 ;
}
static int
F_43 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_91 * V_92 , const char * V_93 ,
T_5 * V_96 , T_6 * V_97 )
{
* V_96 = F_21 ( V_97 -> V_98 ) ;
return 0 ;
}
static int
F_44 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_78 * V_79 , T_6 * V_97 )
{
int V_14 ;
struct V_99 * V_100 ;
V_100 = F_45 ( sizeof( struct V_99 ) + V_101 * 2 ,
V_102 ) ;
if ( V_100 == NULL )
return - V_95 ;
V_14 = F_46 ( V_51 , V_57 , V_79 -> V_86 , V_79 -> V_87 ,
V_100 ) ;
if ( ! V_14 )
F_47 ( V_97 , V_100 ) ;
F_42 ( V_100 ) ;
return V_14 ;
}
static bool
F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_49 ( struct V_56 * V_57 )
{
#ifdef F_50
int V_103 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ ) {
F_51 ( & V_57 -> V_105 . V_106 . V_107 [ V_103 ] , 0 ) ;
F_51 ( & V_57 -> V_105 . V_106 . V_108 [ V_103 ] , 0 ) ;
}
#endif
}
static void
F_52 ( struct V_109 * V_110 , struct V_56 * V_57 )
{
F_53 ( V_110 , L_9 ) ;
if ( V_57 -> V_62 & V_111 )
F_53 ( V_110 , L_10 ) ;
if ( V_57 -> V_62 & V_112 )
F_53 ( V_110 , L_11 ) ;
if ( V_57 -> V_62 & V_113 )
F_53 ( V_110 , L_12 ) ;
if ( V_57 -> V_62 & V_114 )
F_53 ( V_110 , L_13 ) ;
if ( V_57 -> V_62 & V_115 )
F_53 ( V_110 , L_14 ) ;
if ( V_57 -> V_62 == 0 )
F_53 ( V_110 , L_15 ) ;
if ( V_57 -> V_116 & V_117 )
F_53 ( V_110 , L_16 ) ;
if ( V_57 -> V_116 & V_118 )
F_53 ( V_110 , L_17 ) ;
if ( V_57 -> V_116 & V_119 )
F_53 ( V_110 , L_18 ) ;
if ( V_57 -> V_116 & V_120 )
F_53 ( V_110 , L_19 ) ;
F_54 ( V_110 , L_20 , V_57 -> V_121 ) ;
if ( V_57 -> V_122 )
F_54 ( V_110 , L_21 ,
V_57 -> V_122 ) ;
}
static void
F_55 ( struct V_109 * V_110 , struct V_56 * V_57 )
{
#ifdef F_50
T_7 * V_123 = V_57 -> V_105 . V_106 . V_107 ;
T_7 * V_124 = V_57 -> V_105 . V_106 . V_108 ;
F_54 ( V_110 , L_22 ,
F_56 ( & V_123 [ V_125 ] ) ,
F_56 ( & V_124 [ V_125 ] ) ) ;
F_54 ( V_110 , L_23 ,
F_56 ( & V_123 [ V_126 ] ) ,
F_56 ( & V_124 [ V_126 ] ) ) ;
F_54 ( V_110 , L_24 ,
F_56 ( & V_123 [ V_127 ] ) ,
F_56 ( & V_124 [ V_127 ] ) ) ;
F_54 ( V_110 , L_25 ,
F_56 ( & V_123 [ V_128 ] ) ,
F_56 ( & V_124 [ V_128 ] ) ) ;
F_54 ( V_110 , L_26 ,
F_56 ( & V_123 [ V_129 ] ) ,
F_56 ( & V_124 [ V_129 ] ) ) ;
F_54 ( V_110 , L_27 ,
F_56 ( & V_123 [ V_130 ] ) ,
F_56 ( & V_124 [ V_130 ] ) ) ;
F_54 ( V_110 , L_28 ,
F_56 ( & V_123 [ V_131 ] ) ,
F_56 ( & V_124 [ V_131 ] ) ) ;
F_54 ( V_110 , L_29 ,
F_56 ( & V_123 [ V_132 ] ) ,
F_56 ( & V_124 [ V_132 ] ) ) ;
F_54 ( V_110 , L_30 ,
F_56 ( & V_123 [ V_133 ] ) ,
F_56 ( & V_124 [ V_133 ] ) ) ;
F_54 ( V_110 , L_31 ,
F_56 ( & V_123 [ V_134 ] ) ,
F_56 ( & V_124 [ V_134 ] ) ) ;
F_54 ( V_110 , L_32 ,
F_56 ( & V_123 [ V_135 ] ) ,
F_56 ( & V_124 [ V_135 ] ) ) ;
F_54 ( V_110 , L_33 ,
F_56 ( & V_123 [ V_136 ] ) ,
F_56 ( & V_124 [ V_136 ] ) ) ;
F_54 ( V_110 , L_34 ,
F_56 ( & V_123 [ V_137 ] ) ,
F_56 ( & V_124 [ V_137 ] ) ) ;
F_54 ( V_110 , L_35 ,
F_56 ( & V_123 [ V_138 ] ) ,
F_56 ( & V_124 [ V_138 ] ) ) ;
F_54 ( V_110 , L_36 ,
F_56 ( & V_123 [ V_139 ] ) ,
F_56 ( & V_124 [ V_139 ] ) ) ;
F_54 ( V_110 , L_37 ,
F_56 ( & V_123 [ V_140 ] ) ,
F_56 ( & V_124 [ V_140 ] ) ) ;
F_54 ( V_110 , L_38 ,
F_56 ( & V_123 [ V_141 ] ) ,
F_56 ( & V_124 [ V_141 ] ) ) ;
F_54 ( V_110 , L_39 ,
F_56 ( & V_123 [ V_142 ] ) ,
F_56 ( & V_124 [ V_142 ] ) ) ;
F_54 ( V_110 , L_40 ,
F_56 ( & V_123 [ V_143 ] ) ,
F_56 ( & V_124 [ V_143 ] ) ) ;
#endif
}
static void
F_57 ( struct V_144 * V_145 , struct V_78 * V_79 , T_8 V_74 )
{
struct V_146 * V_147 = F_58 ( F_59 ( V_145 -> V_148 ) ) ;
struct V_1 * V_2 = F_60 ( V_145 -> V_149 ) -> V_53 -> V_2 ;
V_145 -> V_79 . V_86 = V_79 -> V_86 ;
V_145 -> V_79 . V_87 = V_79 -> V_87 ;
V_2 -> V_16 -> V_150 ( V_147 , V_74 , V_79 -> V_151 ,
& V_79 -> V_152 ) ;
V_147 -> V_153 = F_61 ( V_147 ) ;
}
static void
F_62 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_78 * V_79 )
{
F_38 ( V_51 , V_57 , V_79 -> V_86 , V_79 -> V_87 ) ;
}
static int
F_63 ( const unsigned int V_51 , struct V_56 * V_57 ,
T_5 V_86 , T_5 V_87 ,
struct V_154 * V_155 )
{
int V_14 ;
unsigned int V_65 ;
struct V_156 * V_157 ;
V_14 = F_32 ( V_51 , V_57 , V_86 , V_87 ,
V_158 , true ,
NULL , 0 ,
( char * * ) & V_157 , & V_65 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_41 , V_14 ) ;
goto V_159;
}
if ( V_65 < sizeof( struct V_156 ) ) {
F_2 ( V_8 , L_42 ) ;
V_14 = - V_70 ;
goto V_159;
}
memcpy ( V_155 -> V_160 , V_157 -> V_161 , V_162 ) ;
V_159:
F_42 ( V_157 ) ;
return V_14 ;
}
static int
F_64 ( const unsigned int V_51 ,
struct V_144 * V_163 ,
struct V_144 * V_164 , T_5 V_165 ,
T_5 V_166 , T_5 V_167 )
{
int V_14 ;
unsigned int V_65 ;
struct V_154 * V_155 ;
struct V_168 * V_169 = NULL ;
struct V_56 * V_57 ;
int V_170 = 0 ;
bool V_171 = false ;
V_155 = F_65 ( sizeof( struct V_154 ) , V_102 ) ;
if ( V_155 == NULL )
return - V_95 ;
F_2 ( V_9 , L_43 ) ;
V_14 = F_63 ( V_51 , F_60 ( V_163 -> V_149 ) ,
V_163 -> V_79 . V_86 ,
V_163 -> V_79 . V_87 , V_155 ) ;
if ( V_14 )
goto V_172;
V_155 -> V_173 = F_66 ( 1 ) ;
V_155 -> V_174 = 0 ;
V_155 -> V_175 = 0 ;
V_57 = F_60 ( V_164 -> V_149 ) ;
while ( V_166 > 0 ) {
V_155 -> V_176 = F_67 ( V_165 ) ;
V_155 -> V_177 = F_67 ( V_167 ) ;
V_155 -> V_178 =
F_66 ( F_17 ( V_179 , V_166 , V_57 -> V_180 ) ) ;
V_14 = F_32 ( V_51 , V_57 , V_164 -> V_79 . V_86 ,
V_164 -> V_79 . V_87 , V_181 ,
true , ( char * ) V_155 ,
sizeof( struct V_154 ) , ( char * * ) & V_169 ,
& V_65 ) ;
if ( V_14 == 0 ) {
if ( V_65 !=
sizeof( struct V_168 ) ) {
F_2 ( V_8 , L_44 ) ;
V_14 = - V_182 ;
goto V_172;
}
if ( V_169 -> V_183 == 0 ) {
F_2 ( V_9 , L_45 ) ;
V_14 = - V_182 ;
goto V_172;
}
if ( F_33 ( V_169 -> V_183 ) >
F_33 ( V_155 -> V_178 ) ) {
F_2 ( V_8 , L_46 ) ;
V_14 = - V_182 ;
goto V_172;
}
if ( F_33 ( V_169 -> V_184 ) != 1 ) {
F_2 ( V_8 , L_47 ) ;
V_14 = - V_182 ;
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
} else if ( V_14 == - V_70 ) {
if ( V_65 != sizeof( struct V_168 ) )
goto V_172;
F_2 ( V_9 , L_49 ,
F_33 ( V_169 -> V_184 ) ,
F_33 ( V_169 -> V_185 ) ,
F_33 ( V_169 -> V_183 ) ) ;
if ( ( V_170 != 0 ) || V_171 )
goto V_172;
if ( F_33 ( V_169 -> V_185 ) <
V_57 -> V_180 )
V_57 -> V_180 =
F_33 ( V_169 -> V_185 ) ;
else
goto V_172;
V_171 = true ;
} else
goto V_172;
}
V_172:
F_42 ( V_155 ) ;
return V_14 ;
}
static int
F_68 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_78 * V_79 )
{
return F_69 ( V_51 , V_57 , V_79 -> V_86 , V_79 -> V_87 ) ;
}
static unsigned int
F_70 ( char * V_38 )
{
struct V_186 * V_187 = (struct V_186 * ) V_38 ;
return V_187 -> V_188 ;
}
static unsigned int
F_71 ( char * V_38 )
{
struct V_186 * V_187 = (struct V_186 * ) V_38 ;
return F_33 ( V_187 -> V_189 ) ;
}
static int
F_72 ( const unsigned int V_51 , struct V_78 * V_190 ,
struct V_191 * V_192 , unsigned int * V_193 ,
char * * V_38 , int * V_194 )
{
V_192 -> V_86 = V_190 -> V_86 ;
V_192 -> V_87 = V_190 -> V_87 ;
return F_73 ( V_51 , V_192 , V_193 , V_38 , V_194 ) ;
}
static int
F_74 ( const unsigned int V_51 , struct V_78 * V_190 ,
struct V_191 * V_192 , unsigned int * V_195 ,
struct V_196 * V_197 , unsigned long V_198 )
{
V_192 -> V_86 = V_190 -> V_86 ;
V_192 -> V_87 = V_190 -> V_87 ;
return F_75 ( V_51 , V_192 , V_195 , V_197 , V_198 ) ;
}
static bool F_76 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_144 * V_145 , struct V_199 * V_199 , T_4 V_200 )
{
struct V_146 * V_201 ;
int V_14 ;
V_201 = F_58 ( V_199 ) ;
if ( ( V_201 -> V_202 & V_203 ) && V_200 )
return true ;
if ( ! ( V_201 -> V_202 & V_203 ) && ! V_200 )
return true ;
if ( V_57 -> V_204 )
return false ;
V_14 = F_32 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 , V_205 ,
true , & V_200 , 1 , NULL , NULL ) ;
if ( V_14 ) {
V_57 -> V_204 = true ;
F_2 ( V_9 , L_50 , V_14 ) ;
return false ;
}
if ( V_200 )
V_201 -> V_202 |= V_203 ;
else
V_201 -> V_202 &= ( ~ V_203 ) ;
return true ;
}
static int
F_77 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_144 * V_145 , T_1 V_29 , bool V_206 )
{
T_9 V_207 = F_67 ( V_29 ) ;
struct V_199 * V_199 ;
V_199 = F_59 ( V_145 -> V_148 ) ;
if ( ! V_206 && ( V_29 > V_199 -> V_208 + 8192 ) ) {
T_4 V_209 = 1 ;
F_76 ( V_51 , V_57 , V_145 , V_199 , V_209 ) ;
}
return F_78 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 , V_145 -> V_210 , & V_207 , false ) ;
}
static int
F_79 ( const unsigned int V_51 ,
struct V_144 * V_163 ,
struct V_144 * V_164 , T_5 V_165 ,
T_5 V_166 , T_5 V_167 )
{
int V_14 ;
unsigned int V_65 ;
char * V_169 = NULL ;
struct V_211 V_212 ;
struct V_56 * V_57 = F_60 ( V_164 -> V_149 ) ;
if ( ( F_33 ( V_57 -> V_213 . V_214 ) &
V_215 ) == 0 )
return - V_216 ;
V_212 . V_217 = V_163 -> V_79 . V_87 ;
V_212 . V_218 = V_163 -> V_79 . V_86 ;
V_212 . V_219 = F_67 ( V_165 ) ;
V_212 . V_220 = F_67 ( V_167 ) ;
V_212 . V_221 = F_67 ( V_166 ) ;
F_2 ( V_9 , L_51 ,
V_165 , V_167 , V_166 ) ;
V_14 = F_77 ( V_51 , V_57 , V_164 , V_167 + V_166 , false ) ;
if ( V_14 )
goto V_222;
V_14 = F_32 ( V_51 , V_57 , V_164 -> V_79 . V_86 ,
V_164 -> V_79 . V_87 ,
V_223 ,
true , ( char * ) & V_212 ,
sizeof( struct V_211 ) ,
( char * * ) & V_169 ,
& V_65 ) ;
if ( V_65 > 0 )
F_2 ( V_9 , L_52 ) ;
V_222:
return V_14 ;
}
static int
F_80 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_144 * V_145 )
{
return F_81 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 ) ;
}
static int
F_82 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_144 * V_145 )
{
struct V_224 V_225 ;
char * V_169 = NULL ;
unsigned int V_65 ;
V_225 . V_226 = F_83 ( V_227 ) ;
V_225 . V_48 = 0 ;
V_225 . V_174 = 0 ;
return F_32 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 ,
V_228 ,
true , ( char * ) & V_225 ,
sizeof( struct V_224 ) ,
( char * * ) & V_169 ,
& V_65 ) ;
}
static int
F_84 ( const unsigned int V_51 , struct V_56 * V_57 ,
const char * V_229 , struct V_91 * V_92 ,
struct V_78 * V_79 , T_10 V_230 ,
struct V_231 * V_232 )
{
T_2 * V_94 ;
int V_14 ;
T_4 V_74 = V_75 ;
struct V_76 V_77 ;
V_94 = F_41 ( V_229 , V_92 ) ;
if ( ! V_94 )
return - V_95 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 | V_233 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , V_94 , & V_74 , NULL , NULL ) ;
F_42 ( V_94 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_53 ) ;
return V_14 ;
}
V_232 -> V_234 = 0 ;
V_232 -> V_235 = 0 ;
V_14 = F_85 ( V_51 , V_57 , V_79 -> V_86 ,
V_79 -> V_87 , 0 , V_232 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_54 ) ;
F_38 ( V_51 , V_57 , V_79 -> V_86 , V_79 -> V_87 ) ;
}
return V_14 ;
}
static int
F_86 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_78 * V_79 , T_10 V_230 ,
struct V_231 * V_232 )
{
return F_85 ( V_51 , V_57 , V_79 -> V_86 ,
V_79 -> V_87 , 0 , V_232 ) ;
}
static int
F_87 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_78 * V_79 )
{
return F_38 ( V_51 , V_57 , V_79 -> V_86 , V_79 -> V_87 ) ;
}
static bool
F_88 ( char * V_38 , struct V_1 * V_2 , int V_236 )
{
struct V_26 * V_39 = (struct V_26 * ) V_38 ;
if ( V_39 -> V_47 != V_237 )
return false ;
if ( ! V_236 ) {
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 += F_11 ( V_39 -> V_28 ) ;
F_5 ( & V_2 -> V_15 ) ;
F_6 ( & V_2 -> V_21 ) ;
}
return true ;
}
static int
F_89 ( struct V_56 * V_57 , struct V_78 * V_79 ,
struct V_146 * V_147 )
{
if ( V_57 -> V_53 -> V_2 -> V_62 & V_238 )
return F_90 ( 0 , V_57 , V_147 -> V_239 ,
F_91 ( V_147 ) ) ;
return F_92 ( 0 , V_57 , V_79 -> V_86 ,
V_79 -> V_87 ,
F_93 ( V_147 ) ? 1 : 0 ) ;
}
static int
F_94 ( const unsigned int V_51 , struct V_56 * V_57 ,
struct V_240 * V_38 )
{
int V_14 ;
T_2 V_73 = 0 ;
T_3 V_74 = V_75 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = & V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , & V_73 , & V_74 , NULL , NULL ) ;
if ( V_14 )
return V_14 ;
V_38 -> V_241 = V_242 ;
V_14 = F_95 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ,
V_38 ) ;
F_38 ( V_51 , V_57 , V_79 . V_86 , V_79 . V_87 ) ;
return V_14 ;
}
static bool
F_96 ( struct V_144 * V_243 , struct V_144 * V_244 )
{
return V_243 -> V_79 . V_86 == V_244 -> V_79 . V_86 &&
V_243 -> V_79 . V_87 == V_244 -> V_79 . V_87 ;
}
static int
F_97 ( const unsigned int V_51 , struct V_144 * V_145 , T_1 V_245 ,
T_1 V_236 , T_8 type , int V_246 , int V_247 , bool V_248 )
{
if ( V_247 && ! V_246 )
type = V_249 ;
return F_98 ( V_51 , F_60 ( V_145 -> V_149 ) ,
V_145 -> V_79 . V_86 , V_145 -> V_79 . V_87 ,
V_250 -> V_251 , V_236 , V_245 , type , V_248 ) ;
}
static void
F_99 ( struct V_199 * V_199 , struct V_78 * V_79 )
{
memcpy ( V_79 -> V_239 , F_58 ( V_199 ) -> V_239 , V_252 ) ;
}
static void
F_100 ( struct V_199 * V_199 , struct V_78 * V_79 )
{
memcpy ( F_58 ( V_199 ) -> V_239 , V_79 -> V_239 , V_252 ) ;
}
static void
F_101 ( struct V_78 * V_79 )
{
F_102 ( V_79 -> V_239 , V_252 ) ;
}
static int
F_103 ( const unsigned int V_51 , struct V_56 * V_57 ,
const char * V_93 , char * * V_253 ,
struct V_91 * V_92 )
{
int V_14 ;
T_2 * V_94 ;
T_4 V_74 = V_75 ;
struct V_76 V_77 ;
struct V_78 V_79 ;
struct V_254 * V_255 = NULL ;
struct V_256 * V_257 ;
unsigned int V_258 , V_259 ;
F_2 ( V_9 , L_55 , V_260 , V_93 ) ;
V_94 = F_41 ( V_93 , V_92 ) ;
if ( ! V_94 )
return - V_95 ;
V_77 . V_57 = V_57 ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_83 ;
V_77 . V_84 = 0 ;
V_77 . V_79 = & V_79 ;
V_77 . V_85 = false ;
V_14 = F_35 ( V_51 , & V_77 , V_94 , & V_74 , NULL , & V_255 ) ;
if ( ! V_14 || ! V_255 ) {
F_42 ( V_94 ) ;
return - V_34 ;
}
V_14 = 0 ;
V_257 = (struct V_256 * ) V_255 -> V_261 ;
V_258 = F_11 ( V_257 -> V_262 ) ;
V_259 = F_11 ( V_257 -> V_263 ) ;
* V_253 = F_104 (
( char * ) V_257 -> V_264 + V_259 ,
V_258 , true , V_92 -> V_265 ) ;
if ( ! ( * V_253 ) ) {
F_42 ( V_94 ) ;
return - V_95 ;
}
F_105 ( * V_253 , '/' ) ;
F_2 ( V_9 , L_56 , V_260 , * V_253 ) ;
F_42 ( V_94 ) ;
return V_14 ;
}
static long F_106 ( struct V_266 * V_266 , struct V_56 * V_57 ,
T_11 V_245 , T_11 V_166 , bool V_267 )
{
struct V_199 * V_199 ;
struct V_146 * V_201 ;
struct V_144 * V_145 = V_266 -> V_268 ;
struct V_269 V_270 ;
long V_14 ;
unsigned int V_51 ;
V_51 = F_107 () ;
V_199 = F_59 ( V_145 -> V_148 ) ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_93 ( V_201 ) )
if ( V_267 == false )
return - V_216 ;
if ( ! ( V_201 -> V_202 & V_203 ) )
return - V_216 ;
if ( V_267 == false )
if ( F_108 ( V_199 ) < V_245 + V_166 )
return - V_216 ;
F_2 ( V_9 , L_57 , V_245 , V_166 ) ;
V_270 . V_271 = F_67 ( V_245 ) ;
V_270 . V_272 = F_67 ( V_245 + V_166 ) ;
V_14 = F_32 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 , V_273 ,
true , ( char * ) & V_270 ,
sizeof( struct V_269 ) , NULL , NULL ) ;
F_109 ( V_51 ) ;
return V_14 ;
}
static long F_110 ( struct V_266 * V_266 , struct V_56 * V_57 ,
T_11 V_245 , T_11 V_166 )
{
struct V_199 * V_199 ;
struct V_146 * V_201 ;
struct V_144 * V_145 = V_266 -> V_268 ;
struct V_269 V_270 ;
long V_14 ;
unsigned int V_51 ;
T_4 V_209 = 1 ;
V_51 = F_107 () ;
V_199 = F_59 ( V_145 -> V_148 ) ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_76 ( V_51 , V_57 , V_145 , V_199 , V_209 ) )
return - V_216 ;
F_2 ( V_9 , L_57 , V_245 , V_166 ) ;
V_270 . V_271 = F_67 ( V_245 ) ;
V_270 . V_272 = F_67 ( V_245 + V_166 ) ;
V_14 = F_32 ( V_51 , V_57 , V_145 -> V_79 . V_86 ,
V_145 -> V_79 . V_87 , V_273 ,
true , ( char * ) & V_270 ,
sizeof( struct V_269 ) , NULL , NULL ) ;
F_109 ( V_51 ) ;
return V_14 ;
}
static long F_111 ( struct V_266 * V_266 , struct V_56 * V_57 ,
T_11 V_274 , T_11 V_166 , bool V_267 )
{
struct V_199 * V_199 ;
struct V_146 * V_201 ;
struct V_144 * V_145 = V_266 -> V_268 ;
long V_14 = - V_216 ;
unsigned int V_51 ;
V_51 = F_107 () ;
V_199 = F_59 ( V_145 -> V_148 ) ;
V_201 = F_58 ( V_199 ) ;
if ( ! F_93 ( V_201 ) )
if ( V_267 == false )
return - V_216 ;
if ( ( V_201 -> V_202 & V_203 ) == 0 ) {
if ( V_267 == true )
return 0 ;
else if ( F_108 ( V_199 ) >= V_274 + V_166 )
return 0 ;
else
return - V_216 ;
}
if ( ( V_267 == true ) || ( F_108 ( V_199 ) >= V_274 + V_166 ) ) {
if ( ( V_274 > 8192 ) || ( V_274 + V_166 + 8192 < F_108 ( V_199 ) ) )
return - V_216 ;
V_14 = F_76 ( V_51 , V_57 , V_145 , V_199 , false ) ;
}
F_109 ( V_51 ) ;
return V_14 ;
}
static long F_112 ( struct V_266 * V_266 , struct V_56 * V_57 , int V_275 ,
T_11 V_274 , T_11 V_166 )
{
if ( V_275 & V_276 )
return F_110 ( V_266 , V_57 , V_274 , V_166 ) ;
else if ( V_275 & V_277 ) {
if ( V_275 & V_278 )
return F_106 ( V_266 , V_57 , V_274 , V_166 , true ) ;
return F_106 ( V_266 , V_57 , V_274 , V_166 , false ) ;
} else if ( V_275 == V_278 )
return F_111 ( V_266 , V_57 , V_274 , V_166 , true ) ;
else if ( V_275 == 0 )
return F_111 ( V_266 , V_57 , V_274 , V_166 , false ) ;
return - V_216 ;
}
static void
F_113 ( struct V_1 * V_2 ,
struct V_146 * V_147 , bool V_279 )
{
if ( V_279 )
V_2 -> V_16 -> V_150 ( V_147 , V_280 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_150 ( V_147 , 0 , 0 , NULL ) ;
}
static void
F_114 ( struct V_146 * V_147 , T_8 V_74 ,
unsigned int V_151 , bool * V_152 )
{
V_74 &= 0xFF ;
if ( V_74 == V_281 )
return;
if ( V_74 == V_282 ) {
V_147 -> V_74 = V_283 ;
F_2 ( V_9 , L_58 ,
& V_147 -> V_284 ) ;
} else if ( V_74 == V_285 ) {
V_147 -> V_74 = V_286 ;
F_2 ( V_9 , L_59 ,
& V_147 -> V_284 ) ;
} else if ( V_74 == V_280 ) {
V_147 -> V_74 = V_287 ;
F_2 ( V_9 , L_60 ,
& V_147 -> V_284 ) ;
} else
V_147 -> V_74 = 0 ;
}
static void
F_115 ( struct V_146 * V_147 , T_8 V_74 ,
unsigned int V_151 , bool * V_152 )
{
char V_288 [ 5 ] = { 0 } ;
V_74 &= 0xFF ;
if ( V_74 == V_281 )
return;
V_147 -> V_74 = 0 ;
if ( V_74 & V_289 ) {
V_147 -> V_74 |= V_287 ;
strcat ( V_288 , L_61 ) ;
}
if ( V_74 & V_290 ) {
V_147 -> V_74 |= V_291 ;
strcat ( V_288 , L_62 ) ;
}
if ( V_74 & V_292 ) {
V_147 -> V_74 |= V_293 ;
strcat ( V_288 , L_63 ) ;
}
if ( ! V_147 -> V_74 )
strcat ( V_288 , L_64 ) ;
F_2 ( V_9 , L_65 , V_288 ,
& V_147 -> V_284 ) ;
}
static void
F_116 ( struct V_146 * V_147 , T_8 V_74 ,
unsigned int V_151 , bool * V_152 )
{
unsigned int V_294 = V_147 -> V_74 ;
F_115 ( V_147 , V_74 , V_151 , V_152 ) ;
if ( V_152 ) {
* V_152 = false ;
if ( V_294 == V_287 ) {
if ( V_147 -> V_74 == V_287 &&
( V_151 - V_147 -> V_151 > 0 ) )
* V_152 = true ;
else if ( V_147 -> V_74 == V_295 &&
( V_151 - V_147 -> V_151 > 1 ) )
* V_152 = true ;
else if ( V_147 -> V_74 == V_283 &&
( V_151 - V_147 -> V_151 > 1 ) )
* V_152 = true ;
else if ( V_147 -> V_74 == 0 &&
( V_151 - V_147 -> V_151 > 0 ) )
* V_152 = true ;
} else if ( V_294 == V_295 ) {
if ( V_147 -> V_74 == V_295 &&
( V_151 - V_147 -> V_151 > 0 ) )
* V_152 = true ;
else if ( V_147 -> V_74 == V_283 &&
( V_151 - V_147 -> V_151 > 1 ) )
* V_152 = true ;
}
V_147 -> V_151 = V_151 ;
}
}
static bool
F_117 ( T_8 V_74 )
{
return V_74 == V_280 ;
}
static bool
F_118 ( T_8 V_74 )
{
return ( V_74 & V_289 ) &&
! ( V_74 & V_292 ) ;
}
static T_12
F_119 ( T_3 V_74 )
{
if ( V_74 == V_285 )
return V_296 | V_297 ;
else if ( V_74 == V_280 )
return V_297 ;
else if ( V_74 == V_282 )
return V_298 | V_297 |
V_296 ;
return 0 ;
}
static char *
F_120 ( T_3 * V_239 , T_3 V_74 )
{
struct V_299 * V_38 ;
V_38 = F_45 ( sizeof( struct V_299 ) , V_102 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_300 . V_301 = F_67 ( * ( ( T_5 * ) V_239 ) ) ;
V_38 -> V_300 . V_302 = F_67 ( * ( ( T_5 * ) ( V_239 + 8 ) ) ) ;
V_38 -> V_300 . V_303 = F_119 ( V_74 ) ;
V_38 -> V_304 . V_188 = F_83 ( F_121
( struct V_299 , V_300 ) ) ;
V_38 -> V_304 . V_189 = F_66 ( sizeof( struct V_305 ) ) ;
V_38 -> V_304 . V_306 = F_83 ( F_121
( struct V_299 , V_307 ) ) ;
V_38 -> V_304 . V_308 = F_83 ( 4 ) ;
V_38 -> V_307 [ 0 ] = 'R' ;
V_38 -> V_307 [ 1 ] = 'q' ;
V_38 -> V_307 [ 2 ] = 'L' ;
V_38 -> V_307 [ 3 ] = 's' ;
return ( char * ) V_38 ;
}
static char *
F_122 ( T_3 * V_239 , T_3 V_74 )
{
struct V_309 * V_38 ;
V_38 = F_45 ( sizeof( struct V_309 ) , V_102 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_300 . V_301 = F_67 ( * ( ( T_5 * ) V_239 ) ) ;
V_38 -> V_300 . V_302 = F_67 ( * ( ( T_5 * ) ( V_239 + 8 ) ) ) ;
V_38 -> V_300 . V_303 = F_119 ( V_74 ) ;
V_38 -> V_304 . V_188 = F_83 ( F_121
( struct V_309 , V_300 ) ) ;
V_38 -> V_304 . V_189 = F_66 ( sizeof( struct V_310 ) ) ;
V_38 -> V_304 . V_306 = F_83 ( F_121
( struct V_309 , V_307 ) ) ;
V_38 -> V_304 . V_308 = F_83 ( 4 ) ;
V_38 -> V_307 [ 0 ] = 'R' ;
V_38 -> V_307 [ 1 ] = 'q' ;
V_38 -> V_307 [ 2 ] = 'L' ;
V_38 -> V_307 [ 3 ] = 's' ;
return ( char * ) V_38 ;
}
static T_4
F_123 ( void * V_38 , unsigned int * V_151 )
{
struct V_299 * V_311 = (struct V_299 * ) V_38 ;
* V_151 = 0 ;
if ( V_311 -> V_300 . V_312 & V_313 )
return V_281 ;
return F_33 ( V_311 -> V_300 . V_303 ) ;
}
static T_4
F_124 ( void * V_38 , unsigned int * V_151 )
{
struct V_309 * V_311 = (struct V_309 * ) V_38 ;
* V_151 = F_11 ( V_311 -> V_300 . V_314 ) ;
if ( V_311 -> V_300 . V_312 & V_313 )
return V_281 ;
return F_33 ( V_311 -> V_300 . V_303 ) ;
}
static unsigned int
F_125 ( struct V_199 * V_199 )
{
return F_17 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_126 ( struct V_144 * V_145 )
{
return ! V_145 -> V_315 ;
}
