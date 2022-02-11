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
static T_1
F_12 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_4 ( & V_28 ) ;
V_24 = V_2 -> V_29 ++ ;
F_5 ( & V_28 ) ;
return V_24 ;
}
static struct V_23 *
F_13 ( struct V_1 * V_2 , char * V_30 )
{
struct V_23 * V_24 ;
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
F_4 ( & V_28 ) ;
F_14 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_31 -> V_32 ) &&
( V_24 -> V_33 == V_34 ) &&
( V_24 -> V_35 == V_31 -> V_36 ) ) {
F_5 ( & V_28 ) ;
return V_24 ;
}
}
F_5 ( & V_28 ) ;
return NULL ;
}
static void
F_15 ( void * V_30 )
{
#ifdef F_16
struct V_25 * V_37 = (struct V_25 * ) V_30 ;
F_2 ( V_8 , L_3 ,
V_37 -> V_36 , V_37 -> V_38 , V_37 -> V_39 , V_37 -> V_32 ,
V_37 -> V_40 ) ;
F_2 ( V_8 , L_4 , V_37 , F_17 ( V_37 ) ) ;
#endif
}
static bool
F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == 0 ;
}
static int
F_19 ( const unsigned int V_42 , struct V_43 * V_44 )
{
int V_13 ;
V_44 -> V_2 -> V_29 = 0 ;
V_13 = F_20 ( V_42 , V_44 ) ;
if ( V_13 == - V_45 )
V_13 = - V_46 ;
return V_13 ;
}
static unsigned int
F_21 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_51 ;
V_51 = V_50 -> V_51 ? V_50 -> V_51 : V_52 ;
V_51 = F_22 (unsigned int, wsize, server->max_write) ;
V_51 = F_22 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_51 ;
}
static unsigned int
F_23 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_53 ;
V_53 = V_50 -> V_53 ? V_50 -> V_53 : V_52 ;
V_53 = F_22 (unsigned int, rsize, server->max_read) ;
V_53 = F_22 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_53 ;
}
static int
F_24 ( const unsigned int V_42 , struct V_47 * V_48 )
{
int V_13 ;
unsigned int V_54 = 0 ;
struct V_55 * V_56 ;
V_13 = F_25 ( V_42 , V_48 , V_57 , V_57 ,
V_58 , true ,
NULL , 0 ,
( char * * ) & V_56 , & V_54 ) ;
if ( ( V_13 == 0 ) && ( V_54 > 0 ) ) {
F_2 ( V_9 , L_5 ,
F_26 ( V_56 -> V_59 ) ) ;
F_2 ( V_9 , L_6 ,
F_27 ( V_56 -> V_60 ) ) ;
} else
F_2 ( V_8 , L_7 , V_13 ) ;
return V_13 ;
}
static void
F_28 ( const unsigned int V_42 , struct V_47 * V_48 )
{
int V_13 ;
T_2 V_61 = 0 ;
T_3 V_62 = V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = & V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , & V_61 , & V_62 , NULL , NULL ) ;
if ( V_13 )
return;
#ifdef F_30
F_24 ( V_42 , V_48 ) ;
#endif
F_31 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_76 ) ;
F_31 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_77 ) ;
F_31 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_78 ) ;
F_32 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ) ;
return;
}
static void
F_33 ( const unsigned int V_42 , struct V_47 * V_48 )
{
int V_13 ;
T_2 V_61 = 0 ;
T_3 V_62 = V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = & V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , & V_61 , & V_62 , NULL , NULL ) ;
if ( V_13 )
return;
F_31 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_76 ) ;
F_31 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_77 ) ;
F_32 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ) ;
return;
}
static int
F_34 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_79 * V_80 , const char * V_81 )
{
int V_13 ;
T_2 * V_82 ;
T_4 V_62 = V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
V_82 = F_35 ( V_81 , V_80 ) ;
if ( ! V_82 )
return - V_83 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = & V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , V_82 , & V_62 , NULL , NULL ) ;
if ( V_13 ) {
F_36 ( V_82 ) ;
return V_13 ;
}
V_13 = F_32 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ) ;
F_36 ( V_82 ) ;
return V_13 ;
}
static int
F_37 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_79 * V_80 , const char * V_81 ,
T_5 * V_84 , T_6 * V_85 )
{
* V_84 = F_27 ( V_85 -> V_86 ) ;
return 0 ;
}
static int
F_38 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_66 * V_67 , T_6 * V_85 )
{
int V_13 ;
struct V_87 * V_88 ;
V_88 = F_39 ( sizeof( struct V_87 ) + V_89 * 2 ,
V_90 ) ;
if ( V_88 == NULL )
return - V_83 ;
V_13 = F_40 ( V_42 , V_48 , V_67 -> V_74 , V_67 -> V_75 ,
V_88 ) ;
if ( ! V_13 )
F_41 ( V_85 , V_88 ) ;
F_36 ( V_88 ) ;
return V_13 ;
}
static bool
F_42 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_43 ( struct V_47 * V_48 )
{
#ifdef F_44
int V_91 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
F_45 ( & V_48 -> V_93 . V_94 . V_95 [ V_91 ] , 0 ) ;
F_45 ( & V_48 -> V_93 . V_94 . V_96 [ V_91 ] , 0 ) ;
}
#endif
}
static void
F_46 ( struct V_97 * V_98 , struct V_47 * V_48 )
{
F_47 ( V_98 , L_8 ) ;
if ( V_48 -> V_99 & V_100 )
F_47 ( V_98 , L_9 ) ;
if ( V_48 -> V_99 & V_101 )
F_47 ( V_98 , L_10 ) ;
if ( V_48 -> V_99 & V_102 )
F_47 ( V_98 , L_11 ) ;
if ( V_48 -> V_99 & V_103 )
F_47 ( V_98 , L_12 ) ;
if ( V_48 -> V_99 & V_104 )
F_47 ( V_98 , L_13 ) ;
if ( V_48 -> V_99 == 0 )
F_47 ( V_98 , L_14 ) ;
if ( V_48 -> V_105 & V_106 )
F_47 ( V_98 , L_15 ) ;
if ( V_48 -> V_105 & V_107 )
F_47 ( V_98 , L_16 ) ;
if ( V_48 -> V_105 & V_108 )
F_47 ( V_98 , L_17 ) ;
if ( V_48 -> V_105 & V_109 )
F_47 ( V_98 , L_18 ) ;
F_48 ( V_98 , L_19 , V_48 -> V_110 ) ;
if ( V_48 -> V_111 )
F_48 ( V_98 , L_20 ,
V_48 -> V_111 ) ;
}
static void
F_49 ( struct V_97 * V_98 , struct V_47 * V_48 )
{
#ifdef F_44
T_7 * V_112 = V_48 -> V_93 . V_94 . V_95 ;
T_7 * V_113 = V_48 -> V_93 . V_94 . V_96 ;
F_48 ( V_98 , L_21 ,
F_50 ( & V_112 [ V_114 ] ) ,
F_50 ( & V_113 [ V_114 ] ) ) ;
F_48 ( V_98 , L_22 ,
F_50 ( & V_112 [ V_115 ] ) ,
F_50 ( & V_113 [ V_115 ] ) ) ;
F_48 ( V_98 , L_23 ,
F_50 ( & V_112 [ V_116 ] ) ,
F_50 ( & V_113 [ V_116 ] ) ) ;
F_48 ( V_98 , L_24 ,
F_50 ( & V_112 [ V_117 ] ) ,
F_50 ( & V_113 [ V_117 ] ) ) ;
F_48 ( V_98 , L_25 ,
F_50 ( & V_112 [ V_118 ] ) ,
F_50 ( & V_113 [ V_118 ] ) ) ;
F_48 ( V_98 , L_26 ,
F_50 ( & V_112 [ V_119 ] ) ,
F_50 ( & V_113 [ V_119 ] ) ) ;
F_48 ( V_98 , L_27 ,
F_50 ( & V_112 [ V_120 ] ) ,
F_50 ( & V_113 [ V_120 ] ) ) ;
F_48 ( V_98 , L_28 ,
F_50 ( & V_112 [ V_121 ] ) ,
F_50 ( & V_113 [ V_121 ] ) ) ;
F_48 ( V_98 , L_29 ,
F_50 ( & V_112 [ V_122 ] ) ,
F_50 ( & V_113 [ V_122 ] ) ) ;
F_48 ( V_98 , L_30 ,
F_50 ( & V_112 [ V_123 ] ) ,
F_50 ( & V_113 [ V_123 ] ) ) ;
F_48 ( V_98 , L_31 ,
F_50 ( & V_112 [ V_124 ] ) ,
F_50 ( & V_113 [ V_124 ] ) ) ;
F_48 ( V_98 , L_32 ,
F_50 ( & V_112 [ V_125 ] ) ,
F_50 ( & V_113 [ V_125 ] ) ) ;
F_48 ( V_98 , L_33 ,
F_50 ( & V_112 [ V_126 ] ) ,
F_50 ( & V_113 [ V_126 ] ) ) ;
F_48 ( V_98 , L_34 ,
F_50 ( & V_112 [ V_127 ] ) ,
F_50 ( & V_113 [ V_127 ] ) ) ;
F_48 ( V_98 , L_35 ,
F_50 ( & V_112 [ V_128 ] ) ,
F_50 ( & V_113 [ V_128 ] ) ) ;
F_48 ( V_98 , L_36 ,
F_50 ( & V_112 [ V_129 ] ) ,
F_50 ( & V_113 [ V_129 ] ) ) ;
F_48 ( V_98 , L_37 ,
F_50 ( & V_112 [ V_130 ] ) ,
F_50 ( & V_113 [ V_130 ] ) ) ;
F_48 ( V_98 , L_38 ,
F_50 ( & V_112 [ V_131 ] ) ,
F_50 ( & V_113 [ V_131 ] ) ) ;
F_48 ( V_98 , L_39 ,
F_50 ( & V_112 [ V_132 ] ) ,
F_50 ( & V_113 [ V_132 ] ) ) ;
#endif
}
static void
F_51 ( struct V_133 * V_134 , struct V_66 * V_67 , T_8 V_62 )
{
struct V_135 * V_136 = F_52 ( V_134 -> V_137 -> V_138 ) ;
struct V_1 * V_2 = F_53 ( V_134 -> V_139 ) -> V_44 -> V_2 ;
V_134 -> V_67 . V_74 = V_67 -> V_74 ;
V_134 -> V_67 . V_75 = V_67 -> V_75 ;
V_2 -> V_15 -> V_140 ( V_136 , V_62 , V_67 -> V_141 ,
& V_67 -> V_142 ) ;
V_136 -> V_143 = F_54 ( V_136 ) ;
}
static void
F_55 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_66 * V_67 )
{
F_32 ( V_42 , V_48 , V_67 -> V_74 , V_67 -> V_75 ) ;
}
static int
F_56 ( const unsigned int V_42 , struct V_47 * V_48 ,
T_5 V_74 , T_5 V_75 ,
struct V_144 * V_145 )
{
int V_13 ;
unsigned int V_54 ;
struct V_146 * V_147 ;
V_13 = F_25 ( V_42 , V_48 , V_74 , V_75 ,
V_148 , true ,
NULL , 0 ,
( char * * ) & V_147 , & V_54 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_40 , V_13 ) ;
goto V_149;
}
if ( V_54 < sizeof( struct V_146 ) ) {
F_2 ( V_8 , L_41 ) ;
V_13 = - V_150 ;
goto V_149;
}
memcpy ( V_145 -> V_151 , V_147 -> V_152 , V_153 ) ;
V_149:
F_36 ( V_147 ) ;
return V_13 ;
}
static int
F_57 ( const unsigned int V_42 ,
struct V_133 * V_154 ,
struct V_133 * V_155 , T_5 V_156 ,
T_5 V_157 , T_5 V_158 )
{
int V_13 ;
unsigned int V_54 ;
struct V_144 * V_145 ;
struct V_159 * V_160 = NULL ;
struct V_47 * V_48 ;
int V_161 = 0 ;
bool V_162 = false ;
V_145 = F_58 ( sizeof( struct V_144 ) , V_90 ) ;
if ( V_145 == NULL )
return - V_83 ;
F_2 ( V_9 , L_42 ) ;
V_13 = F_56 ( V_42 , F_53 ( V_154 -> V_139 ) ,
V_154 -> V_67 . V_74 ,
V_154 -> V_67 . V_75 , V_145 ) ;
if ( V_13 )
goto V_163;
V_145 -> V_164 = F_59 ( 1 ) ;
V_145 -> V_165 = 0 ;
V_145 -> V_166 = 0 ;
V_48 = F_53 ( V_155 -> V_139 ) ;
while ( V_157 > 0 ) {
V_145 -> V_167 = F_60 ( V_156 ) ;
V_145 -> V_168 = F_60 ( V_158 ) ;
V_145 -> V_169 =
F_61 ( F_22 ( V_170 , V_157 , V_48 -> V_171 ) ) ;
V_13 = F_25 ( V_42 , V_48 , V_155 -> V_67 . V_74 ,
V_155 -> V_67 . V_75 , V_172 ,
true , ( char * ) V_145 ,
sizeof( struct V_144 ) , ( char * * ) & V_160 ,
& V_54 ) ;
if ( V_13 == 0 ) {
if ( V_54 !=
sizeof( struct V_159 ) ) {
F_2 ( V_8 , L_43 ) ;
V_13 = - V_173 ;
goto V_163;
}
if ( V_160 -> V_174 == 0 ) {
F_2 ( V_9 , L_44 ) ;
V_13 = - V_173 ;
goto V_163;
}
if ( F_26 ( V_160 -> V_174 ) >
F_26 ( V_145 -> V_169 ) ) {
F_2 ( V_8 , L_45 ) ;
V_13 = - V_173 ;
goto V_163;
}
if ( F_26 ( V_160 -> V_175 ) != 1 ) {
F_2 ( V_8 , L_46 ) ;
V_13 = - V_173 ;
goto V_163;
}
V_161 ++ ;
V_156 += F_26 ( V_160 -> V_174 ) ;
V_158 += F_26 ( V_160 -> V_174 ) ;
V_157 -= F_26 ( V_160 -> V_174 ) ;
F_2 ( V_9 , L_47 ,
F_26 ( V_160 -> V_175 ) ,
F_26 ( V_160 -> V_176 ) ,
F_26 ( V_160 -> V_174 ) ) ;
} else if ( V_13 == - V_150 ) {
if ( V_54 != sizeof( struct V_159 ) )
goto V_163;
F_2 ( V_9 , L_48 ,
F_26 ( V_160 -> V_175 ) ,
F_26 ( V_160 -> V_176 ) ,
F_26 ( V_160 -> V_174 ) ) ;
if ( ( V_161 != 0 ) || V_162 )
goto V_163;
if ( F_26 ( V_160 -> V_176 ) <
V_48 -> V_171 )
V_48 -> V_171 =
F_26 ( V_160 -> V_176 ) ;
else
goto V_163;
V_162 = true ;
}
}
V_163:
F_36 ( V_145 ) ;
return V_13 ;
}
static int
F_62 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_66 * V_67 )
{
return F_63 ( V_42 , V_48 , V_67 -> V_74 , V_67 -> V_75 ) ;
}
static unsigned int
F_64 ( char * V_30 )
{
struct V_177 * V_178 = (struct V_177 * ) V_30 ;
return V_178 -> V_179 ;
}
static unsigned int
F_65 ( char * V_30 )
{
struct V_177 * V_178 = (struct V_177 * ) V_30 ;
return F_26 ( V_178 -> V_180 ) ;
}
static int
F_66 ( const unsigned int V_42 , struct V_133 * V_134 ,
struct V_181 * V_182 , unsigned int * V_183 ,
char * * V_30 , int * V_184 )
{
V_182 -> V_74 = V_134 -> V_67 . V_74 ;
V_182 -> V_75 = V_134 -> V_67 . V_75 ;
return F_67 ( V_42 , V_182 , V_183 , V_30 , V_184 ) ;
}
static int
F_68 ( const unsigned int V_42 , struct V_133 * V_134 ,
struct V_181 * V_182 , unsigned int * V_185 ,
struct V_186 * V_187 , unsigned long V_188 )
{
V_182 -> V_74 = V_134 -> V_67 . V_74 ;
V_182 -> V_75 = V_134 -> V_67 . V_75 ;
return F_69 ( V_42 , V_182 , V_185 , V_187 , V_188 ) ;
}
static int
F_70 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_133 * V_134 , T_1 V_189 , bool V_190 )
{
T_9 V_191 = F_60 ( V_189 ) ;
return F_71 ( V_42 , V_48 , V_134 -> V_67 . V_74 ,
V_134 -> V_67 . V_75 , V_134 -> V_192 , & V_191 ) ;
}
static int
F_72 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_133 * V_134 )
{
return F_73 ( V_42 , V_48 , V_134 -> V_67 . V_74 ,
V_134 -> V_67 . V_75 ) ;
}
static int
F_74 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_193 , struct V_79 * V_80 ,
struct V_66 * V_67 , T_10 V_194 ,
struct V_195 * V_196 )
{
T_2 * V_82 ;
int V_13 ;
T_4 V_62 = V_63 ;
struct V_64 V_65 ;
V_82 = F_35 ( V_193 , V_80 ) ;
if ( ! V_82 )
return - V_83 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 | V_197 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , V_82 , & V_62 , NULL , NULL ) ;
F_36 ( V_82 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_49 ) ;
return V_13 ;
}
V_196 -> V_198 = 0 ;
V_196 -> V_199 = 0 ;
V_13 = F_75 ( V_42 , V_48 , V_67 -> V_74 ,
V_67 -> V_75 , 0 , V_196 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_50 ) ;
F_32 ( V_42 , V_48 , V_67 -> V_74 , V_67 -> V_75 ) ;
}
return V_13 ;
}
static int
F_76 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_66 * V_67 , T_10 V_194 ,
struct V_195 * V_196 )
{
return F_75 ( V_42 , V_48 , V_67 -> V_74 ,
V_67 -> V_75 , 0 , V_196 ) ;
}
static int
F_77 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_66 * V_67 )
{
return F_32 ( V_42 , V_48 , V_67 -> V_74 , V_67 -> V_75 ) ;
}
static bool
F_78 ( char * V_30 , struct V_1 * V_2 , int V_200 )
{
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
if ( V_31 -> V_38 != V_201 )
return false ;
if ( ! V_200 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_31 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_79 ( struct V_47 * V_48 , struct V_66 * V_67 ,
struct V_135 * V_136 )
{
if ( V_48 -> V_44 -> V_2 -> V_99 & V_202 )
return F_80 ( 0 , V_48 , V_136 -> V_203 ,
F_81 ( V_136 ) ) ;
return F_82 ( 0 , V_48 , V_67 -> V_74 ,
V_67 -> V_75 ,
F_83 ( V_136 ) ? 1 : 0 ) ;
}
static int
F_84 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_204 * V_30 )
{
int V_13 ;
T_2 V_61 = 0 ;
T_3 V_62 = V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = & V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , & V_61 , & V_62 , NULL , NULL ) ;
if ( V_13 )
return V_13 ;
V_30 -> V_205 = V_206 ;
V_13 = F_85 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ,
V_30 ) ;
F_32 ( V_42 , V_48 , V_67 . V_74 , V_67 . V_75 ) ;
return V_13 ;
}
static bool
F_86 ( struct V_133 * V_207 , struct V_133 * V_208 )
{
return V_207 -> V_67 . V_74 == V_208 -> V_67 . V_74 &&
V_207 -> V_67 . V_75 == V_208 -> V_67 . V_75 ;
}
static int
F_87 ( const unsigned int V_42 , struct V_133 * V_134 , T_1 V_209 ,
T_1 V_200 , T_8 type , int V_210 , int V_211 , bool V_212 )
{
if ( V_211 && ! V_210 )
type = V_213 ;
return F_88 ( V_42 , F_53 ( V_134 -> V_139 ) ,
V_134 -> V_67 . V_74 , V_134 -> V_67 . V_75 ,
V_214 -> V_215 , V_200 , V_209 , type , V_212 ) ;
}
static void
F_89 ( struct V_216 * V_216 , struct V_66 * V_67 )
{
memcpy ( V_67 -> V_203 , F_52 ( V_216 ) -> V_203 , V_217 ) ;
}
static void
F_90 ( struct V_216 * V_216 , struct V_66 * V_67 )
{
memcpy ( F_52 ( V_216 ) -> V_203 , V_67 -> V_203 , V_217 ) ;
}
static void
F_91 ( struct V_66 * V_67 )
{
F_92 ( V_67 -> V_203 , V_217 ) ;
}
static int
F_93 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_81 , char * * V_218 ,
struct V_79 * V_80 )
{
int V_13 ;
T_2 * V_82 ;
T_4 V_62 = V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
struct V_219 * V_220 = NULL ;
struct V_221 * V_222 ;
unsigned int V_223 , V_224 ;
F_2 ( V_9 , L_51 , V_225 , V_81 ) ;
V_82 = F_35 ( V_81 , V_80 ) ;
if ( ! V_82 )
return - V_83 ;
V_65 . V_48 = V_48 ;
V_65 . V_68 = V_69 ;
V_65 . V_70 = V_71 ;
V_65 . V_72 = 0 ;
V_65 . V_67 = & V_67 ;
V_65 . V_73 = false ;
V_13 = F_29 ( V_42 , & V_65 , V_82 , & V_62 , NULL , & V_220 ) ;
if ( ! V_13 || ! V_220 ) {
F_36 ( V_82 ) ;
return - V_226 ;
}
V_13 = 0 ;
V_222 = (struct V_221 * ) V_220 -> V_227 ;
V_223 = F_11 ( V_222 -> V_228 ) ;
V_224 = F_11 ( V_222 -> V_229 ) ;
* V_218 = F_94 (
( char * ) V_222 -> V_230 + V_224 ,
V_223 , true , V_80 -> V_231 ) ;
if ( ! ( * V_218 ) ) {
F_36 ( V_82 ) ;
return - V_83 ;
}
F_95 ( * V_218 , '/' ) ;
F_2 ( V_9 , L_52 , V_225 , * V_218 ) ;
F_36 ( V_82 ) ;
return V_13 ;
}
static void
F_96 ( struct V_135 * V_136 , T_8 V_62 ,
unsigned int V_141 , bool * V_142 )
{
V_62 &= 0xFF ;
if ( V_62 == V_232 )
return;
if ( V_62 == V_233 ) {
V_136 -> V_62 = V_234 ;
F_2 ( V_9 , L_53 ,
& V_136 -> V_235 ) ;
} else if ( V_62 == V_236 ) {
V_136 -> V_62 = V_237 ;
F_2 ( V_9 , L_54 ,
& V_136 -> V_235 ) ;
} else if ( V_62 == V_238 ) {
V_136 -> V_62 = V_239 ;
F_2 ( V_9 , L_55 ,
& V_136 -> V_235 ) ;
} else
V_136 -> V_62 = 0 ;
}
static void
F_97 ( struct V_135 * V_136 , T_8 V_62 ,
unsigned int V_141 , bool * V_142 )
{
char V_240 [ 5 ] = { 0 } ;
V_62 &= 0xFF ;
if ( V_62 == V_232 )
return;
V_136 -> V_62 = 0 ;
if ( V_62 & V_241 ) {
V_136 -> V_62 |= V_239 ;
strcat ( V_240 , L_56 ) ;
}
if ( V_62 & V_242 ) {
V_136 -> V_62 |= V_243 ;
strcat ( V_240 , L_57 ) ;
}
if ( V_62 & V_244 ) {
V_136 -> V_62 |= V_245 ;
strcat ( V_240 , L_58 ) ;
}
if ( ! V_136 -> V_62 )
strcat ( V_240 , L_59 ) ;
F_2 ( V_9 , L_60 , V_240 ,
& V_136 -> V_235 ) ;
}
static void
F_98 ( struct V_135 * V_136 , T_8 V_62 ,
unsigned int V_141 , bool * V_142 )
{
unsigned int V_246 = V_136 -> V_62 ;
F_97 ( V_136 , V_62 , V_141 , V_142 ) ;
if ( V_142 ) {
* V_142 = false ;
if ( V_246 == V_239 ) {
if ( V_136 -> V_62 == V_239 &&
( V_141 - V_136 -> V_141 > 0 ) )
* V_142 = true ;
else if ( V_136 -> V_62 == V_247 &&
( V_141 - V_136 -> V_141 > 1 ) )
* V_142 = true ;
else if ( V_136 -> V_62 == V_234 &&
( V_141 - V_136 -> V_141 > 1 ) )
* V_142 = true ;
else if ( V_136 -> V_62 == 0 &&
( V_141 - V_136 -> V_141 > 0 ) )
* V_142 = true ;
} else if ( V_246 == V_247 ) {
if ( V_136 -> V_62 == V_247 &&
( V_141 - V_136 -> V_141 > 0 ) )
* V_142 = true ;
else if ( V_136 -> V_62 == V_234 &&
( V_141 - V_136 -> V_141 > 1 ) )
* V_142 = true ;
}
V_136 -> V_141 = V_141 ;
}
}
static bool
F_99 ( T_8 V_62 )
{
return V_62 == V_238 ;
}
static bool
F_100 ( T_8 V_62 )
{
return ( V_62 & V_241 ) &&
! ( V_62 & V_244 ) ;
}
static T_11
F_101 ( T_3 V_62 )
{
if ( V_62 == V_236 )
return V_248 | V_249 ;
else if ( V_62 == V_238 )
return V_249 ;
else if ( V_62 == V_233 )
return V_250 | V_249 |
V_248 ;
return 0 ;
}
static char *
F_102 ( T_3 * V_203 , T_3 V_62 )
{
struct V_251 * V_30 ;
V_30 = F_39 ( sizeof( struct V_251 ) , V_90 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_252 . V_253 = F_60 ( * ( ( T_5 * ) V_203 ) ) ;
V_30 -> V_252 . V_254 = F_60 ( * ( ( T_5 * ) ( V_203 + 8 ) ) ) ;
V_30 -> V_252 . V_255 = F_101 ( V_62 ) ;
V_30 -> V_256 . V_179 = F_103 ( F_104
( struct V_251 , V_252 ) ) ;
V_30 -> V_256 . V_180 = F_61 ( sizeof( struct V_257 ) ) ;
V_30 -> V_256 . V_258 = F_103 ( F_104
( struct V_251 , V_259 ) ) ;
V_30 -> V_256 . V_260 = F_103 ( 4 ) ;
V_30 -> V_259 [ 0 ] = 'R' ;
V_30 -> V_259 [ 1 ] = 'q' ;
V_30 -> V_259 [ 2 ] = 'L' ;
V_30 -> V_259 [ 3 ] = 's' ;
return ( char * ) V_30 ;
}
static char *
F_105 ( T_3 * V_203 , T_3 V_62 )
{
struct V_261 * V_30 ;
V_30 = F_39 ( sizeof( struct V_261 ) , V_90 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_252 . V_253 = F_60 ( * ( ( T_5 * ) V_203 ) ) ;
V_30 -> V_252 . V_254 = F_60 ( * ( ( T_5 * ) ( V_203 + 8 ) ) ) ;
V_30 -> V_252 . V_255 = F_101 ( V_62 ) ;
V_30 -> V_256 . V_179 = F_103 ( F_104
( struct V_261 , V_252 ) ) ;
V_30 -> V_256 . V_180 = F_61 ( sizeof( struct V_262 ) ) ;
V_30 -> V_256 . V_258 = F_103 ( F_104
( struct V_261 , V_259 ) ) ;
V_30 -> V_256 . V_260 = F_103 ( 4 ) ;
V_30 -> V_259 [ 0 ] = 'R' ;
V_30 -> V_259 [ 1 ] = 'q' ;
V_30 -> V_259 [ 2 ] = 'L' ;
V_30 -> V_259 [ 3 ] = 's' ;
return ( char * ) V_30 ;
}
static T_4
F_106 ( void * V_30 , unsigned int * V_141 )
{
struct V_251 * V_263 = (struct V_251 * ) V_30 ;
* V_141 = 0 ;
if ( V_263 -> V_252 . V_264 & V_265 )
return V_232 ;
return F_26 ( V_263 -> V_252 . V_255 ) ;
}
static T_4
F_107 ( void * V_30 , unsigned int * V_141 )
{
struct V_261 * V_263 = (struct V_261 * ) V_30 ;
* V_141 = F_11 ( V_263 -> V_252 . V_266 ) ;
if ( V_263 -> V_252 . V_264 & V_265 )
return V_232 ;
return F_26 ( V_263 -> V_252 . V_255 ) ;
}
