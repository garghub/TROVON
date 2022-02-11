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
return F_12 ( ( (struct V_27 * ) V_26 -> V_28 ) -> V_29 ) ;
}
static int
F_13 ( struct V_1 * V_2 , unsigned int V_30 ,
unsigned int * V_31 , unsigned int * V_3 )
{
int V_14 = 0 ;
unsigned int V_32 ;
F_4 ( & V_2 -> V_15 ) ;
while ( 1 ) {
if ( V_2 -> V_3 <= 0 ) {
F_6 ( & V_2 -> V_15 ) ;
F_14 ( V_2 ) ;
V_14 = F_15 ( V_2 -> V_22 ,
F_16 ( V_2 , & V_2 -> V_3 ) ) ;
F_17 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_4 ( & V_2 -> V_15 ) ;
} else {
if ( V_2 -> V_33 == V_34 ) {
F_6 ( & V_2 -> V_15 ) ;
return - V_35 ;
}
V_32 = V_2 -> V_3 ;
if ( V_32 == 1 ) {
* V_31 = V_36 ;
* V_3 = 0 ;
break;
}
V_32 -- ;
* V_31 = F_18 (unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE) ;
* V_3 = F_19 ( * V_31 , V_36 ) ;
V_2 -> V_3 -= * V_3 ;
V_2 -> V_19 ++ ;
break;
}
}
F_6 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static T_1
F_20 ( struct V_1 * V_2 )
{
T_1 V_26 ;
F_4 ( & V_37 ) ;
V_26 = V_2 -> V_38 ++ ;
F_6 ( & V_37 ) ;
return V_26 ;
}
static struct V_25 *
F_21 ( struct V_1 * V_2 , char * V_39 )
{
struct V_25 * V_26 ;
struct V_27 * V_40 = (struct V_27 * ) V_39 ;
T_1 V_41 = F_22 ( V_40 -> V_42 ) ;
if ( V_40 -> V_43 == V_44 ) {
F_2 ( V_8 , L_4 ) ;
return NULL ;
}
F_4 ( & V_37 ) ;
F_23 (mid, &server->pending_mid_q, qhead) {
if ( ( V_26 -> V_26 == V_41 ) &&
( V_26 -> V_45 == V_46 ) &&
( V_26 -> V_47 == V_40 -> V_48 ) ) {
F_6 ( & V_37 ) ;
return V_26 ;
}
}
F_6 ( & V_37 ) ;
return NULL ;
}
static void
F_24 ( void * V_39 )
{
#ifdef F_25
struct V_27 * V_49 = (struct V_27 * ) V_39 ;
F_2 ( V_8 , L_5 ,
V_49 -> V_48 , V_49 -> V_50 , V_49 -> V_51 , V_49 -> V_42 ,
V_49 -> V_52 ) ;
F_2 ( V_8 , L_6 , V_49 , F_26 ( V_49 ) ) ;
#endif
}
static bool
F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_53 == 0 ;
}
static int
F_28 ( const unsigned int V_54 , struct V_55 * V_56 )
{
int V_14 ;
V_56 -> V_2 -> V_38 = 0 ;
V_14 = F_29 ( V_54 , V_56 ) ;
if ( V_14 == - V_57 )
V_14 = - V_58 ;
return V_14 ;
}
static unsigned int
F_30 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_1 * V_2 = V_60 -> V_56 -> V_2 ;
unsigned int V_63 ;
V_63 = V_62 -> V_63 ? V_62 -> V_63 : V_64 ;
V_63 = F_18 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_65 & V_66 ) )
V_63 = F_18 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_63 ;
}
static unsigned int
F_31 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_1 * V_2 = V_60 -> V_56 -> V_2 ;
unsigned int V_67 ;
V_67 = V_62 -> V_67 ? V_62 -> V_67 : V_64 ;
V_67 = F_18 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_65 & V_66 ) )
V_67 = F_18 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_67 ;
}
static int
F_32 ( const unsigned int V_54 , struct V_59 * V_60 )
{
int V_14 ;
unsigned int V_68 = 0 ;
struct V_69 * V_70 ;
V_14 = F_33 ( V_54 , V_60 , V_71 , V_71 ,
V_72 , true ,
NULL , 0 ,
( char * * ) & V_70 , & V_68 ) ;
if ( V_14 != 0 )
F_2 ( V_8 , L_7 , V_14 ) ;
else if ( V_68 < sizeof( struct V_69 ) ) {
F_2 ( V_8 , L_8 ) ;
V_14 = - V_73 ;
} else {
F_2 ( V_9 , L_9 ,
F_34 ( V_70 -> V_74 ) ) ;
F_2 ( V_9 , L_10 ,
F_22 ( V_70 -> V_75 ) ) ;
}
F_35 ( V_70 ) ;
return V_14 ;
}
static void
F_36 ( const unsigned int V_54 , struct V_59 * V_60 )
{
int V_14 ;
T_2 V_76 = 0 ;
T_3 V_77 = V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = & V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , & V_76 , & V_77 , NULL , NULL ) ;
if ( V_14 )
return;
#ifdef F_38
F_32 ( V_54 , V_60 ) ;
#endif
F_39 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_91 ) ;
F_39 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_92 ) ;
F_39 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_93 ) ;
F_40 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ) ;
return;
}
static void
F_41 ( const unsigned int V_54 , struct V_59 * V_60 )
{
int V_14 ;
T_2 V_76 = 0 ;
T_3 V_77 = V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = & V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , & V_76 , & V_77 , NULL , NULL ) ;
if ( V_14 )
return;
F_39 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_91 ) ;
F_39 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_92 ) ;
F_40 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ) ;
return;
}
static int
F_42 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_94 * V_95 , const char * V_96 )
{
int V_14 ;
T_2 * V_97 ;
T_4 V_77 = V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
V_97 = F_43 ( V_96 , V_95 ) ;
if ( ! V_97 )
return - V_98 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = & V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , V_97 , & V_77 , NULL , NULL ) ;
if ( V_14 ) {
F_35 ( V_97 ) ;
return V_14 ;
}
V_14 = F_40 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ) ;
F_35 ( V_97 ) ;
return V_14 ;
}
static int
F_44 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_94 * V_95 , const char * V_96 ,
T_5 * V_99 , T_6 * V_100 )
{
* V_99 = F_22 ( V_100 -> V_101 ) ;
return 0 ;
}
static int
F_45 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_81 * V_82 , T_6 * V_100 )
{
int V_14 ;
struct V_102 * V_103 ;
V_103 = F_46 ( sizeof( struct V_102 ) + V_104 * 2 ,
V_105 ) ;
if ( V_103 == NULL )
return - V_98 ;
V_14 = F_47 ( V_54 , V_60 , V_82 -> V_89 , V_82 -> V_90 ,
V_103 ) ;
if ( ! V_14 )
F_48 ( V_100 , V_103 ) ;
F_35 ( V_103 ) ;
return V_14 ;
}
static bool
F_49 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_50 ( struct V_59 * V_60 )
{
#ifdef F_51
int V_106 ;
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ ) {
F_52 ( & V_60 -> V_108 . V_109 . V_110 [ V_106 ] , 0 ) ;
F_52 ( & V_60 -> V_108 . V_109 . V_111 [ V_106 ] , 0 ) ;
}
#endif
}
static void
F_53 ( struct V_112 * V_113 , struct V_59 * V_60 )
{
F_54 ( V_113 , L_11 ) ;
if ( V_60 -> V_65 & V_114 )
F_54 ( V_113 , L_12 ) ;
if ( V_60 -> V_65 & V_115 )
F_54 ( V_113 , L_13 ) ;
if ( V_60 -> V_65 & V_116 )
F_54 ( V_113 , L_14 ) ;
if ( V_60 -> V_65 & V_117 )
F_54 ( V_113 , L_15 ) ;
if ( V_60 -> V_65 & V_118 )
F_54 ( V_113 , L_16 ) ;
if ( V_60 -> V_65 == 0 )
F_54 ( V_113 , L_17 ) ;
if ( V_60 -> V_119 & V_120 )
F_54 ( V_113 , L_18 ) ;
if ( V_60 -> V_119 & V_121 )
F_54 ( V_113 , L_19 ) ;
if ( V_60 -> V_119 & V_122 )
F_54 ( V_113 , L_20 ) ;
if ( V_60 -> V_119 & V_123 )
F_54 ( V_113 , L_21 ) ;
F_55 ( V_113 , L_22 , V_60 -> V_124 ) ;
if ( V_60 -> V_125 )
F_55 ( V_113 , L_23 ,
V_60 -> V_125 ) ;
}
static void
F_56 ( struct V_112 * V_113 , struct V_59 * V_60 )
{
#ifdef F_51
T_7 * V_126 = V_60 -> V_108 . V_109 . V_110 ;
T_7 * V_127 = V_60 -> V_108 . V_109 . V_111 ;
F_55 ( V_113 , L_24 ,
F_57 ( & V_126 [ V_128 ] ) ,
F_57 ( & V_127 [ V_128 ] ) ) ;
F_55 ( V_113 , L_25 ,
F_57 ( & V_126 [ V_129 ] ) ,
F_57 ( & V_127 [ V_129 ] ) ) ;
F_55 ( V_113 , L_26 ,
F_57 ( & V_126 [ V_130 ] ) ,
F_57 ( & V_127 [ V_130 ] ) ) ;
F_55 ( V_113 , L_27 ,
F_57 ( & V_126 [ V_131 ] ) ,
F_57 ( & V_127 [ V_131 ] ) ) ;
F_55 ( V_113 , L_28 ,
F_57 ( & V_126 [ V_132 ] ) ,
F_57 ( & V_127 [ V_132 ] ) ) ;
F_55 ( V_113 , L_29 ,
F_57 ( & V_126 [ V_133 ] ) ,
F_57 ( & V_127 [ V_133 ] ) ) ;
F_55 ( V_113 , L_30 ,
F_57 ( & V_126 [ V_134 ] ) ,
F_57 ( & V_127 [ V_134 ] ) ) ;
F_55 ( V_113 , L_31 ,
F_57 ( & V_126 [ V_135 ] ) ,
F_57 ( & V_127 [ V_135 ] ) ) ;
F_55 ( V_113 , L_32 ,
F_57 ( & V_126 [ V_136 ] ) ,
F_57 ( & V_127 [ V_136 ] ) ) ;
F_55 ( V_113 , L_33 ,
F_57 ( & V_126 [ V_137 ] ) ,
F_57 ( & V_127 [ V_137 ] ) ) ;
F_55 ( V_113 , L_34 ,
F_57 ( & V_126 [ V_138 ] ) ,
F_57 ( & V_127 [ V_138 ] ) ) ;
F_55 ( V_113 , L_35 ,
F_57 ( & V_126 [ V_139 ] ) ,
F_57 ( & V_127 [ V_139 ] ) ) ;
F_55 ( V_113 , L_36 ,
F_57 ( & V_126 [ V_140 ] ) ,
F_57 ( & V_127 [ V_140 ] ) ) ;
F_55 ( V_113 , L_37 ,
F_57 ( & V_126 [ V_141 ] ) ,
F_57 ( & V_127 [ V_141 ] ) ) ;
F_55 ( V_113 , L_38 ,
F_57 ( & V_126 [ V_142 ] ) ,
F_57 ( & V_127 [ V_142 ] ) ) ;
F_55 ( V_113 , L_39 ,
F_57 ( & V_126 [ V_143 ] ) ,
F_57 ( & V_127 [ V_143 ] ) ) ;
F_55 ( V_113 , L_40 ,
F_57 ( & V_126 [ V_144 ] ) ,
F_57 ( & V_127 [ V_144 ] ) ) ;
F_55 ( V_113 , L_41 ,
F_57 ( & V_126 [ V_145 ] ) ,
F_57 ( & V_127 [ V_145 ] ) ) ;
F_55 ( V_113 , L_42 ,
F_57 ( & V_126 [ V_146 ] ) ,
F_57 ( & V_127 [ V_146 ] ) ) ;
#endif
}
static void
F_58 ( struct V_147 * V_148 , struct V_81 * V_82 , T_8 V_77 )
{
struct V_149 * V_150 = F_59 ( F_60 ( V_148 -> V_151 ) ) ;
struct V_1 * V_2 = F_61 ( V_148 -> V_152 ) -> V_56 -> V_2 ;
V_148 -> V_82 . V_89 = V_82 -> V_89 ;
V_148 -> V_82 . V_90 = V_82 -> V_90 ;
V_2 -> V_16 -> V_153 ( V_150 , V_77 , V_82 -> V_154 ,
& V_82 -> V_155 ) ;
V_150 -> V_156 = F_62 ( V_150 ) ;
memcpy ( V_148 -> V_82 . V_157 , V_82 -> V_157 , 16 ) ;
}
static void
F_63 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_81 * V_82 )
{
F_40 ( V_54 , V_60 , V_82 -> V_89 , V_82 -> V_90 ) ;
}
static int
F_64 ( const unsigned int V_54 , struct V_59 * V_60 ,
T_5 V_89 , T_5 V_90 ,
struct V_158 * V_159 )
{
int V_14 ;
unsigned int V_68 ;
struct V_160 * V_161 ;
V_14 = F_33 ( V_54 , V_60 , V_89 , V_90 ,
V_162 , true ,
NULL , 0 ,
( char * * ) & V_161 , & V_68 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_43 , V_14 ) ;
goto V_163;
}
if ( V_68 < sizeof( struct V_160 ) ) {
F_2 ( V_8 , L_44 ) ;
V_14 = - V_73 ;
goto V_163;
}
memcpy ( V_159 -> V_164 , V_161 -> V_165 , V_166 ) ;
V_163:
F_35 ( V_161 ) ;
return V_14 ;
}
static int
F_65 ( const unsigned int V_54 ,
struct V_147 * V_167 ,
struct V_147 * V_168 , T_5 V_169 ,
T_5 V_170 , T_5 V_171 )
{
int V_14 ;
unsigned int V_68 ;
struct V_158 * V_159 ;
struct V_172 * V_173 = NULL ;
struct V_59 * V_60 ;
int V_174 = 0 ;
bool V_175 = false ;
V_159 = F_66 ( sizeof( struct V_158 ) , V_105 ) ;
if ( V_159 == NULL )
return - V_98 ;
F_2 ( V_9 , L_45 ) ;
V_14 = F_64 ( V_54 , F_61 ( V_167 -> V_152 ) ,
V_167 -> V_82 . V_89 ,
V_167 -> V_82 . V_90 , V_159 ) ;
if ( V_14 )
goto V_176;
V_159 -> V_177 = F_67 ( 1 ) ;
V_159 -> V_178 = 0 ;
V_159 -> V_179 = 0 ;
V_60 = F_61 ( V_168 -> V_152 ) ;
while ( V_170 > 0 ) {
V_159 -> V_180 = F_68 ( V_169 ) ;
V_159 -> V_181 = F_68 ( V_171 ) ;
V_159 -> V_182 =
F_67 ( F_18 ( V_183 , V_170 , V_60 -> V_184 ) ) ;
V_14 = F_33 ( V_54 , V_60 , V_168 -> V_82 . V_89 ,
V_168 -> V_82 . V_90 , V_185 ,
true , ( char * ) V_159 ,
sizeof( struct V_158 ) , ( char * * ) & V_173 ,
& V_68 ) ;
if ( V_14 == 0 ) {
if ( V_68 !=
sizeof( struct V_172 ) ) {
F_2 ( V_8 , L_46 ) ;
V_14 = - V_186 ;
goto V_176;
}
if ( V_173 -> V_187 == 0 ) {
F_2 ( V_9 , L_47 ) ;
V_14 = - V_186 ;
goto V_176;
}
if ( F_34 ( V_173 -> V_187 ) >
F_34 ( V_159 -> V_182 ) ) {
F_2 ( V_8 , L_48 ) ;
V_14 = - V_186 ;
goto V_176;
}
if ( F_34 ( V_173 -> V_188 ) != 1 ) {
F_2 ( V_8 , L_49 ) ;
V_14 = - V_186 ;
goto V_176;
}
V_174 ++ ;
V_169 += F_34 ( V_173 -> V_187 ) ;
V_171 += F_34 ( V_173 -> V_187 ) ;
V_170 -= F_34 ( V_173 -> V_187 ) ;
F_2 ( V_9 , L_50 ,
F_34 ( V_173 -> V_188 ) ,
F_34 ( V_173 -> V_189 ) ,
F_34 ( V_173 -> V_187 ) ) ;
} else if ( V_14 == - V_73 ) {
if ( V_68 != sizeof( struct V_172 ) )
goto V_176;
F_2 ( V_9 , L_51 ,
F_34 ( V_173 -> V_188 ) ,
F_34 ( V_173 -> V_189 ) ,
F_34 ( V_173 -> V_187 ) ) ;
if ( ( V_174 != 0 ) || V_175 )
goto V_176;
if ( F_34 ( V_173 -> V_189 ) <
V_60 -> V_184 )
V_60 -> V_184 =
F_34 ( V_173 -> V_189 ) ;
else
goto V_176;
V_175 = true ;
} else
goto V_176;
}
V_176:
F_35 ( V_159 ) ;
F_35 ( V_173 ) ;
return V_14 ;
}
static int
F_69 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_81 * V_82 )
{
return F_70 ( V_54 , V_60 , V_82 -> V_89 , V_82 -> V_90 ) ;
}
static unsigned int
F_71 ( char * V_39 )
{
struct V_190 * V_191 = (struct V_190 * ) V_39 ;
return V_191 -> V_192 ;
}
static unsigned int
F_72 ( char * V_39 )
{
struct V_190 * V_191 = (struct V_190 * ) V_39 ;
return F_34 ( V_191 -> V_193 ) ;
}
static int
F_73 ( const unsigned int V_54 , struct V_81 * V_194 ,
struct V_195 * V_196 , unsigned int * V_197 ,
char * * V_39 , int * V_198 )
{
V_196 -> V_89 = V_194 -> V_89 ;
V_196 -> V_90 = V_194 -> V_90 ;
return F_74 ( V_54 , V_196 , V_197 , V_39 , V_198 ) ;
}
static int
F_75 ( const unsigned int V_54 , struct V_81 * V_194 ,
struct V_195 * V_196 , unsigned int * V_199 ,
struct V_200 * V_201 , unsigned long V_202 )
{
V_196 -> V_89 = V_194 -> V_89 ;
V_196 -> V_90 = V_194 -> V_90 ;
return F_76 ( V_54 , V_196 , V_199 , V_201 , V_202 ) ;
}
static bool F_77 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_147 * V_148 , struct V_203 * V_203 , T_4 V_204 )
{
struct V_149 * V_205 ;
int V_14 ;
V_205 = F_59 ( V_203 ) ;
if ( ( V_205 -> V_206 & V_207 ) && V_204 )
return true ;
if ( ! ( V_205 -> V_206 & V_207 ) && ! V_204 )
return true ;
if ( V_60 -> V_208 )
return false ;
V_14 = F_33 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 , V_209 ,
true , & V_204 , 1 , NULL , NULL ) ;
if ( V_14 ) {
V_60 -> V_208 = true ;
F_2 ( V_9 , L_52 , V_14 ) ;
return false ;
}
if ( V_204 )
V_205 -> V_206 |= V_207 ;
else
V_205 -> V_206 &= ( ~ V_207 ) ;
return true ;
}
static int
F_78 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_147 * V_148 , T_1 V_30 , bool V_210 )
{
T_9 V_211 = F_68 ( V_30 ) ;
struct V_203 * V_203 ;
V_203 = F_60 ( V_148 -> V_151 ) ;
if ( ! V_210 && ( V_30 > V_203 -> V_212 + 8192 ) ) {
T_4 V_213 = 1 ;
F_77 ( V_54 , V_60 , V_148 , V_203 , V_213 ) ;
}
return F_79 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 , V_148 -> V_214 , & V_211 , false ) ;
}
static int
F_80 ( const unsigned int V_54 ,
struct V_147 * V_167 ,
struct V_147 * V_168 , T_5 V_169 ,
T_5 V_170 , T_5 V_171 )
{
int V_14 ;
unsigned int V_68 ;
struct V_215 V_216 ;
struct V_59 * V_60 = F_61 ( V_168 -> V_152 ) ;
if ( ( F_34 ( V_60 -> V_217 . V_218 ) &
V_219 ) == 0 )
return - V_220 ;
V_216 . V_221 = V_167 -> V_82 . V_90 ;
V_216 . V_222 = V_167 -> V_82 . V_89 ;
V_216 . V_223 = F_68 ( V_169 ) ;
V_216 . V_224 = F_68 ( V_171 ) ;
V_216 . V_225 = F_68 ( V_170 ) ;
F_2 ( V_9 , L_53 ,
V_169 , V_171 , V_170 ) ;
V_14 = F_78 ( V_54 , V_60 , V_168 , V_171 + V_170 , false ) ;
if ( V_14 )
goto V_226;
V_14 = F_33 ( V_54 , V_60 , V_168 -> V_82 . V_89 ,
V_168 -> V_82 . V_90 ,
V_227 ,
true , ( char * ) & V_216 ,
sizeof( struct V_215 ) ,
NULL ,
& V_68 ) ;
if ( V_68 > 0 )
F_2 ( V_9 , L_54 ) ;
V_226:
return V_14 ;
}
static int
F_81 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_147 * V_148 )
{
return F_82 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 ) ;
}
static int
F_83 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_147 * V_148 )
{
struct V_228 V_229 ;
unsigned int V_68 ;
V_229 . V_230 = F_84 ( V_231 ) ;
V_229 . V_51 = 0 ;
V_229 . V_178 = 0 ;
return F_33 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 ,
V_232 ,
true , ( char * ) & V_229 ,
sizeof( struct V_228 ) ,
NULL ,
& V_68 ) ;
}
static int
F_85 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_147 * V_148 , void T_10 * V_233 )
{
char * V_173 = NULL ;
unsigned int V_68 = 0 ;
int V_14 ;
struct V_234 V_235 ;
V_14 = F_33 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 ,
V_236 ,
true , NULL , 0 ,
( char * * ) & V_173 ,
& V_68 ) ;
F_2 ( V_9 , L_55 ,
V_14 , V_68 ) ;
if ( V_14 )
return V_14 ;
if ( V_68 && ( V_233 != NULL ) && ( V_173 != NULL ) ) {
if ( F_86 ( & V_235 , V_233 ,
sizeof( struct V_234 ) ) ) {
V_14 = - V_237 ;
F_35 ( V_173 ) ;
return V_14 ;
}
if ( V_235 . V_238 < sizeof( struct V_234 ) ) {
V_14 = - V_239 ;
return V_14 ;
}
if ( V_68 > V_235 . V_238 )
V_68 = V_235 . V_238 ;
if ( F_87 ( V_233 , V_173 , V_68 ) )
V_14 = - V_237 ;
}
F_35 ( V_173 ) ;
return V_14 ;
}
static int
F_88 ( const unsigned int V_54 , struct V_59 * V_60 ,
const char * V_240 , struct V_94 * V_95 ,
struct V_81 * V_82 , T_11 V_241 ,
struct V_242 * V_243 )
{
T_2 * V_97 ;
int V_14 ;
T_4 V_77 = V_78 ;
struct V_79 V_80 ;
V_97 = F_43 ( V_240 , V_95 ) ;
if ( ! V_97 )
return - V_98 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 | V_244 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , V_97 , & V_77 , NULL , NULL ) ;
F_35 ( V_97 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_56 ) ;
return V_14 ;
}
V_243 -> V_245 = 0 ;
V_243 -> V_246 = 0 ;
V_14 = F_89 ( V_54 , V_60 , V_82 -> V_89 ,
V_82 -> V_90 , 0 , V_243 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_57 ) ;
F_40 ( V_54 , V_60 , V_82 -> V_89 , V_82 -> V_90 ) ;
}
return V_14 ;
}
static int
F_90 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_81 * V_82 , T_11 V_241 ,
struct V_242 * V_243 )
{
return F_89 ( V_54 , V_60 , V_82 -> V_89 ,
V_82 -> V_90 , 0 , V_243 ) ;
}
static int
F_91 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_81 * V_82 )
{
return F_40 ( V_54 , V_60 , V_82 -> V_89 , V_82 -> V_90 ) ;
}
static bool
F_92 ( char * V_39 , struct V_1 * V_2 , int V_247 )
{
struct V_27 * V_40 = (struct V_27 * ) V_39 ;
if ( V_40 -> V_50 != V_248 )
return false ;
if ( ! V_247 ) {
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 += F_12 ( V_40 -> V_29 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_22 ) ;
}
return true ;
}
static int
F_93 ( struct V_59 * V_60 , struct V_81 * V_82 ,
struct V_149 * V_150 )
{
if ( V_60 -> V_56 -> V_2 -> V_65 & V_249 )
return F_94 ( 0 , V_60 , V_150 -> V_250 ,
F_95 ( V_150 ) ) ;
return F_96 ( 0 , V_60 , V_82 -> V_89 ,
V_82 -> V_90 ,
F_97 ( V_150 ) ? 1 : 0 ) ;
}
static int
F_98 ( const unsigned int V_54 , struct V_59 * V_60 ,
struct V_251 * V_39 )
{
int V_14 ;
T_2 V_76 = 0 ;
T_3 V_77 = V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = & V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , & V_76 , & V_77 , NULL , NULL ) ;
if ( V_14 )
return V_14 ;
V_39 -> V_252 = V_253 ;
V_14 = F_99 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ,
V_39 ) ;
F_40 ( V_54 , V_60 , V_82 . V_89 , V_82 . V_90 ) ;
return V_14 ;
}
static bool
F_100 ( struct V_147 * V_254 , struct V_147 * V_255 )
{
return V_254 -> V_82 . V_89 == V_255 -> V_82 . V_89 &&
V_254 -> V_82 . V_90 == V_255 -> V_82 . V_90 ;
}
static int
F_101 ( const unsigned int V_54 , struct V_147 * V_148 , T_1 V_256 ,
T_1 V_247 , T_8 type , int V_257 , int V_258 , bool V_259 )
{
if ( V_258 && ! V_257 )
type = V_260 ;
return F_102 ( V_54 , F_61 ( V_148 -> V_152 ) ,
V_148 -> V_82 . V_89 , V_148 -> V_82 . V_90 ,
V_261 -> V_262 , V_247 , V_256 , type , V_259 ) ;
}
static void
F_103 ( struct V_203 * V_203 , struct V_81 * V_82 )
{
memcpy ( V_82 -> V_250 , F_59 ( V_203 ) -> V_250 , V_263 ) ;
}
static void
F_104 ( struct V_203 * V_203 , struct V_81 * V_82 )
{
memcpy ( F_59 ( V_203 ) -> V_250 , V_82 -> V_250 , V_263 ) ;
}
static void
F_105 ( struct V_81 * V_82 )
{
F_106 ( V_82 -> V_250 ) ;
}
static int
F_107 ( const unsigned int V_54 , struct V_59 * V_60 ,
const char * V_96 , char * * V_264 ,
struct V_94 * V_95 )
{
int V_14 ;
T_2 * V_97 ;
T_4 V_77 = V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
struct V_265 * V_266 = NULL ;
struct V_267 * V_268 ;
unsigned int V_269 ;
unsigned int V_270 ;
unsigned int V_271 ;
unsigned int V_272 ;
F_2 ( V_9 , L_58 , V_273 , V_96 ) ;
V_97 = F_43 ( V_96 , V_95 ) ;
if ( ! V_97 )
return - V_98 ;
V_80 . V_60 = V_60 ;
V_80 . V_83 = V_84 ;
V_80 . V_85 = V_86 ;
V_80 . V_87 = 0 ;
V_80 . V_82 = & V_82 ;
V_80 . V_88 = false ;
V_14 = F_37 ( V_54 , & V_80 , V_97 , & V_77 , NULL , & V_266 ) ;
if ( ! V_14 || ! V_266 ) {
F_35 ( V_97 ) ;
return - V_35 ;
}
if ( F_34 ( V_266 -> V_225 ) < sizeof( struct V_267 ) ||
F_108 ( V_266 ) + 4 < V_274 ) {
F_35 ( V_97 ) ;
return - V_35 ;
}
V_14 = 0 ;
V_268 = (struct V_267 * ) V_266 -> V_275 ;
V_269 = F_12 ( V_268 -> V_276 ) ;
V_270 = F_12 ( V_268 -> V_277 ) ;
V_271 = F_12 ( V_268 -> V_278 ) ;
V_272 = F_12 ( V_268 -> V_279 ) ;
if ( F_108 ( V_266 ) + 4 <
V_274 + V_270 + V_269 ) {
F_35 ( V_97 ) ;
return - V_35 ;
}
if ( F_108 ( V_266 ) + 4 <
V_274 + V_272 + V_271 ) {
F_35 ( V_97 ) ;
return - V_35 ;
}
* V_264 = F_109 (
( char * ) V_268 -> V_280 + V_270 ,
V_269 , true , V_95 -> V_281 ) ;
if ( ! ( * V_264 ) ) {
F_35 ( V_97 ) ;
return - V_98 ;
}
F_110 ( * V_264 , '/' ) ;
F_2 ( V_9 , L_59 , V_273 , * V_264 ) ;
F_35 ( V_97 ) ;
return V_14 ;
}
static long F_111 ( struct V_282 * V_282 , struct V_59 * V_60 ,
T_12 V_256 , T_12 V_170 , bool V_283 )
{
struct V_203 * V_203 ;
struct V_149 * V_205 ;
struct V_147 * V_148 = V_282 -> V_284 ;
struct V_285 V_286 ;
long V_14 ;
unsigned int V_54 ;
V_54 = F_112 () ;
V_203 = F_60 ( V_148 -> V_151 ) ;
V_205 = F_59 ( V_203 ) ;
if ( ! F_97 ( V_205 ) )
if ( V_283 == false )
return - V_220 ;
if ( ! ( V_205 -> V_206 & V_207 ) )
return - V_220 ;
if ( V_283 == false )
if ( F_113 ( V_203 ) < V_256 + V_170 )
return - V_220 ;
F_2 ( V_9 , L_60 , V_256 , V_170 ) ;
V_286 . V_287 = F_68 ( V_256 ) ;
V_286 . V_288 = F_68 ( V_256 + V_170 ) ;
V_14 = F_33 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 , V_289 ,
true , ( char * ) & V_286 ,
sizeof( struct V_285 ) , NULL , NULL ) ;
F_114 ( V_54 ) ;
return V_14 ;
}
static long F_115 ( struct V_282 * V_282 , struct V_59 * V_60 ,
T_12 V_256 , T_12 V_170 )
{
struct V_203 * V_203 ;
struct V_149 * V_205 ;
struct V_147 * V_148 = V_282 -> V_284 ;
struct V_285 V_286 ;
long V_14 ;
unsigned int V_54 ;
T_4 V_213 = 1 ;
V_54 = F_112 () ;
V_203 = F_60 ( V_148 -> V_151 ) ;
V_205 = F_59 ( V_203 ) ;
if ( ! F_77 ( V_54 , V_60 , V_148 , V_203 , V_213 ) )
return - V_220 ;
F_2 ( V_9 , L_60 , V_256 , V_170 ) ;
V_286 . V_287 = F_68 ( V_256 ) ;
V_286 . V_288 = F_68 ( V_256 + V_170 ) ;
V_14 = F_33 ( V_54 , V_60 , V_148 -> V_82 . V_89 ,
V_148 -> V_82 . V_90 , V_289 ,
true , ( char * ) & V_286 ,
sizeof( struct V_285 ) , NULL , NULL ) ;
F_114 ( V_54 ) ;
return V_14 ;
}
static long F_116 ( struct V_282 * V_282 , struct V_59 * V_60 ,
T_12 V_290 , T_12 V_170 , bool V_283 )
{
struct V_203 * V_203 ;
struct V_149 * V_205 ;
struct V_147 * V_148 = V_282 -> V_284 ;
long V_14 = - V_220 ;
unsigned int V_54 ;
V_54 = F_112 () ;
V_203 = F_60 ( V_148 -> V_151 ) ;
V_205 = F_59 ( V_203 ) ;
if ( ! F_97 ( V_205 ) )
if ( V_283 == false )
return - V_220 ;
if ( ( V_205 -> V_206 & V_207 ) == 0 ) {
if ( V_283 == true )
return 0 ;
else if ( F_113 ( V_203 ) >= V_290 + V_170 )
return 0 ;
else
return - V_220 ;
}
if ( ( V_283 == true ) || ( F_113 ( V_203 ) >= V_290 + V_170 ) ) {
if ( ( V_290 > 8192 ) || ( V_290 + V_170 + 8192 < F_113 ( V_203 ) ) )
return - V_220 ;
V_14 = F_77 ( V_54 , V_60 , V_148 , V_203 , false ) ;
}
F_114 ( V_54 ) ;
return V_14 ;
}
static long F_117 ( struct V_282 * V_282 , struct V_59 * V_60 , int V_291 ,
T_12 V_290 , T_12 V_170 )
{
if ( V_291 & V_292 )
return F_115 ( V_282 , V_60 , V_290 , V_170 ) ;
else if ( V_291 & V_293 ) {
if ( V_291 & V_294 )
return F_111 ( V_282 , V_60 , V_290 , V_170 , true ) ;
return F_111 ( V_282 , V_60 , V_290 , V_170 , false ) ;
} else if ( V_291 == V_294 )
return F_116 ( V_282 , V_60 , V_290 , V_170 , true ) ;
else if ( V_291 == 0 )
return F_116 ( V_282 , V_60 , V_290 , V_170 , false ) ;
return - V_220 ;
}
static void
F_118 ( struct V_1 * V_2 ,
struct V_149 * V_150 , bool V_295 )
{
if ( V_295 )
V_2 -> V_16 -> V_153 ( V_150 , V_296 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_153 ( V_150 , 0 , 0 , NULL ) ;
}
static void
F_119 ( struct V_149 * V_150 , T_8 V_77 ,
unsigned int V_154 , bool * V_155 )
{
V_77 &= 0xFF ;
if ( V_77 == V_297 )
return;
if ( V_77 == V_298 ) {
V_150 -> V_77 = V_299 ;
F_2 ( V_9 , L_61 ,
& V_150 -> V_300 ) ;
} else if ( V_77 == V_301 ) {
V_150 -> V_77 = V_302 ;
F_2 ( V_9 , L_62 ,
& V_150 -> V_300 ) ;
} else if ( V_77 == V_296 ) {
V_150 -> V_77 = V_303 ;
F_2 ( V_9 , L_63 ,
& V_150 -> V_300 ) ;
} else
V_150 -> V_77 = 0 ;
}
static void
F_120 ( struct V_149 * V_150 , T_8 V_77 ,
unsigned int V_154 , bool * V_155 )
{
char V_304 [ 5 ] = { 0 } ;
V_77 &= 0xFF ;
if ( V_77 == V_297 )
return;
V_150 -> V_77 = 0 ;
if ( V_77 & V_305 ) {
V_150 -> V_77 |= V_303 ;
strcat ( V_304 , L_64 ) ;
}
if ( V_77 & V_306 ) {
V_150 -> V_77 |= V_307 ;
strcat ( V_304 , L_65 ) ;
}
if ( V_77 & V_308 ) {
V_150 -> V_77 |= V_309 ;
strcat ( V_304 , L_66 ) ;
}
if ( ! V_150 -> V_77 )
strcat ( V_304 , L_67 ) ;
F_2 ( V_9 , L_68 , V_304 ,
& V_150 -> V_300 ) ;
}
static void
F_121 ( struct V_149 * V_150 , T_8 V_77 ,
unsigned int V_154 , bool * V_155 )
{
unsigned int V_310 = V_150 -> V_77 ;
F_120 ( V_150 , V_77 , V_154 , V_155 ) ;
if ( V_155 ) {
* V_155 = false ;
if ( V_310 == V_303 ) {
if ( V_150 -> V_77 == V_303 &&
( V_154 - V_150 -> V_154 > 0 ) )
* V_155 = true ;
else if ( V_150 -> V_77 == V_311 &&
( V_154 - V_150 -> V_154 > 1 ) )
* V_155 = true ;
else if ( V_150 -> V_77 == V_299 &&
( V_154 - V_150 -> V_154 > 1 ) )
* V_155 = true ;
else if ( V_150 -> V_77 == 0 &&
( V_154 - V_150 -> V_154 > 0 ) )
* V_155 = true ;
} else if ( V_310 == V_311 ) {
if ( V_150 -> V_77 == V_311 &&
( V_154 - V_150 -> V_154 > 0 ) )
* V_155 = true ;
else if ( V_150 -> V_77 == V_299 &&
( V_154 - V_150 -> V_154 > 1 ) )
* V_155 = true ;
}
V_150 -> V_154 = V_154 ;
}
}
static bool
F_122 ( T_8 V_77 )
{
return V_77 == V_296 ;
}
static bool
F_123 ( T_8 V_77 )
{
return ( V_77 & V_305 ) &&
! ( V_77 & V_308 ) ;
}
static T_13
F_124 ( T_3 V_77 )
{
if ( V_77 == V_301 )
return V_312 | V_313 ;
else if ( V_77 == V_296 )
return V_313 ;
else if ( V_77 == V_298 )
return V_314 | V_313 |
V_312 ;
return 0 ;
}
static char *
F_125 ( T_3 * V_250 , T_3 V_77 )
{
struct V_315 * V_39 ;
V_39 = F_46 ( sizeof( struct V_315 ) , V_105 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_316 . V_317 = F_68 ( * ( ( T_5 * ) V_250 ) ) ;
V_39 -> V_316 . V_318 = F_68 ( * ( ( T_5 * ) ( V_250 + 8 ) ) ) ;
V_39 -> V_316 . V_319 = F_124 ( V_77 ) ;
V_39 -> V_320 . V_192 = F_84 ( F_126
( struct V_315 , V_316 ) ) ;
V_39 -> V_320 . V_193 = F_67 ( sizeof( struct V_321 ) ) ;
V_39 -> V_320 . V_322 = F_84 ( F_126
( struct V_315 , V_323 ) ) ;
V_39 -> V_320 . V_324 = F_84 ( 4 ) ;
V_39 -> V_323 [ 0 ] = 'R' ;
V_39 -> V_323 [ 1 ] = 'q' ;
V_39 -> V_323 [ 2 ] = 'L' ;
V_39 -> V_323 [ 3 ] = 's' ;
return ( char * ) V_39 ;
}
static char *
F_127 ( T_3 * V_250 , T_3 V_77 )
{
struct V_325 * V_39 ;
V_39 = F_46 ( sizeof( struct V_325 ) , V_105 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_316 . V_317 = F_68 ( * ( ( T_5 * ) V_250 ) ) ;
V_39 -> V_316 . V_318 = F_68 ( * ( ( T_5 * ) ( V_250 + 8 ) ) ) ;
V_39 -> V_316 . V_319 = F_124 ( V_77 ) ;
V_39 -> V_320 . V_192 = F_84 ( F_126
( struct V_325 , V_316 ) ) ;
V_39 -> V_320 . V_193 = F_67 ( sizeof( struct V_326 ) ) ;
V_39 -> V_320 . V_322 = F_84 ( F_126
( struct V_325 , V_323 ) ) ;
V_39 -> V_320 . V_324 = F_84 ( 4 ) ;
V_39 -> V_323 [ 0 ] = 'R' ;
V_39 -> V_323 [ 1 ] = 'q' ;
V_39 -> V_323 [ 2 ] = 'L' ;
V_39 -> V_323 [ 3 ] = 's' ;
return ( char * ) V_39 ;
}
static T_4
F_128 ( void * V_39 , unsigned int * V_154 )
{
struct V_315 * V_327 = (struct V_315 * ) V_39 ;
* V_154 = 0 ;
if ( V_327 -> V_316 . V_328 & V_329 )
return V_297 ;
return F_34 ( V_327 -> V_316 . V_319 ) ;
}
static T_4
F_129 ( void * V_39 , unsigned int * V_154 )
{
struct V_325 * V_327 = (struct V_325 * ) V_39 ;
* V_154 = F_12 ( V_327 -> V_316 . V_330 ) ;
if ( V_327 -> V_316 . V_328 & V_329 )
return V_297 ;
return F_34 ( V_327 -> V_316 . V_319 ) ;
}
static unsigned int
F_130 ( struct V_203 * V_203 )
{
return F_18 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_131 ( struct V_147 * V_148 )
{
return ! V_148 -> V_331 ;
}
