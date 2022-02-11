static inline int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return - V_6 ;
default:
return - V_7 ;
}
}
static int F_2 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
bool V_12 )
{
struct V_10 V_13 , V_3 , V_14 , V_15 , V_16 , * V_17 [ 6 ] ;
unsigned int V_18 = 0 , V_19 = 0 ;
T_1 type = V_2 -> V_20 . type & ~ F_3 ( V_9 -> V_21 , V_22 ) ;
F_4 ( & V_13 , & V_2 -> V_20 , sizeof( V_2 -> V_20 ) ) ;
V_17 [ V_18 ++ ] = & V_13 ;
if ( type == F_3 ( V_9 -> V_21 , V_23 ) ) {
F_4 ( & V_14 , V_2 -> V_24 -> V_14 , V_2 -> V_24 -> V_25 ) ;
V_17 [ V_18 ++ ] = & V_14 ;
}
if ( V_12 ) {
if ( V_2 -> V_20 . type & F_3 ( V_9 -> V_21 , V_22 ) )
V_17 [ V_18 ++ ] = V_11 ;
else
V_17 [ V_18 + V_19 ++ ] = V_11 ;
}
if ( type == F_3 ( V_9 -> V_21 , V_23 ) ) {
F_4 ( & V_15 , V_2 -> V_24 -> V_15 , V_26 ) ;
V_17 [ V_18 + V_19 ++ ] = & V_15 ;
F_4 ( & V_16 , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_16 ;
}
F_4 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_3 ;
return F_5 ( V_9 , V_17 , V_18 , V_19 , V_2 , V_28 ) ;
}
static inline void F_6 ( struct V_29 * V_24 )
{
struct V_1 * V_2 = F_7 ( V_24 ) ;
struct V_30 * V_31 = V_24 -> V_32 -> V_33 ;
int error = F_1 ( V_2 ) ;
if ( V_24 -> V_34 == V_35 ) {
V_24 -> V_36 = F_8 ( V_31 -> V_21 , V_2 -> V_27 . V_37 ) ;
V_24 -> V_38 = F_8 ( V_31 -> V_21 , V_2 -> V_27 . V_38 ) ;
V_24 -> V_39 = F_8 ( V_31 -> V_21 , V_2 -> V_27 . V_39 ) ;
} else if ( V_24 -> V_34 == V_40 ) {
V_24 -> V_39 = ( error != 0 ) ;
}
F_9 ( V_24 , error ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_30 * V_31 = V_9 -> V_21 -> V_41 ;
bool V_42 = false ;
int V_43 = V_9 -> V_44 ;
struct V_1 * V_2 ;
unsigned long V_45 ;
unsigned int V_46 ;
F_11 ( & V_31 -> V_47 [ V_43 ] . V_48 , V_45 ) ;
do {
F_12 ( V_9 ) ;
while ( ( V_2 = F_13 ( V_31 -> V_47 [ V_43 ] . V_9 , & V_46 ) ) != NULL ) {
F_14 ( V_2 -> V_24 ) ;
V_42 = true ;
}
if ( F_15 ( F_16 ( V_9 ) ) )
break;
} while ( ! F_17 ( V_9 ) );
if ( V_42 )
F_18 ( V_31 -> V_49 -> V_50 , true ) ;
F_19 ( & V_31 -> V_47 [ V_43 ] . V_48 , V_45 ) ;
}
static int F_20 ( struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_30 * V_31 = V_52 -> V_50 -> V_33 ;
struct V_29 * V_24 = V_54 -> V_55 ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
unsigned long V_45 ;
unsigned int V_56 ;
int V_43 = V_52 -> V_57 ;
int V_58 ;
bool V_59 = false ;
F_21 ( V_24 -> V_60 + 2 > V_31 -> V_61 ) ;
V_2 -> V_24 = V_24 ;
if ( V_24 -> V_62 & V_63 ) {
V_2 -> V_20 . type = F_3 ( V_31 -> V_21 , V_64 ) ;
V_2 -> V_20 . V_65 = 0 ;
V_2 -> V_20 . V_66 = F_3 ( V_31 -> V_21 , F_22 ( V_2 -> V_24 ) ) ;
} else {
switch ( V_24 -> V_34 ) {
case V_67 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_65 = F_23 ( V_31 -> V_21 , F_24 ( V_2 -> V_24 ) ) ;
V_2 -> V_20 . V_66 = F_3 ( V_31 -> V_21 , F_22 ( V_2 -> V_24 ) ) ;
break;
case V_35 :
V_2 -> V_20 . type = F_3 ( V_31 -> V_21 , V_23 ) ;
V_2 -> V_20 . V_65 = 0 ;
V_2 -> V_20 . V_66 = F_3 ( V_31 -> V_21 , F_22 ( V_2 -> V_24 ) ) ;
break;
case V_40 :
V_2 -> V_20 . type = F_3 ( V_31 -> V_21 , V_68 ) ;
V_2 -> V_20 . V_65 = 0 ;
V_2 -> V_20 . V_66 = F_3 ( V_31 -> V_21 , F_22 ( V_2 -> V_24 ) ) ;
break;
default:
F_25 () ;
}
}
F_26 ( V_24 ) ;
V_56 = F_27 ( V_52 -> V_50 , V_2 -> V_24 , V_2 -> V_69 ) ;
if ( V_56 ) {
if ( F_28 ( V_2 -> V_24 ) == V_70 )
V_2 -> V_20 . type |= F_3 ( V_31 -> V_21 , V_22 ) ;
else
V_2 -> V_20 . type |= F_3 ( V_31 -> V_21 , V_71 ) ;
}
F_11 ( & V_31 -> V_47 [ V_43 ] . V_48 , V_45 ) ;
V_58 = F_2 ( V_31 -> V_47 [ V_43 ] . V_9 , V_2 , V_2 -> V_69 , V_56 ) ;
if ( V_58 ) {
F_29 ( V_31 -> V_47 [ V_43 ] . V_9 ) ;
F_30 ( V_52 ) ;
F_19 ( & V_31 -> V_47 [ V_43 ] . V_48 , V_45 ) ;
if ( V_58 == - V_72 || V_58 == - V_73 )
return V_74 ;
return V_75 ;
}
if ( V_54 -> V_76 && F_31 ( V_31 -> V_47 [ V_43 ] . V_9 ) )
V_59 = true ;
F_19 ( & V_31 -> V_47 [ V_43 ] . V_48 , V_45 ) ;
if ( V_59 )
F_32 ( V_31 -> V_47 [ V_43 ] . V_9 ) ;
return V_77 ;
}
static int F_33 ( struct V_78 * V_49 , char * V_79 )
{
struct V_30 * V_31 = V_49 -> V_80 ;
struct V_29 * V_24 ;
struct V_81 * V_81 ;
int V_58 ;
V_81 = F_34 ( V_31 -> V_49 -> V_50 , V_79 , V_82 ,
V_83 ) ;
if ( F_35 ( V_81 ) )
return F_36 ( V_81 ) ;
V_24 = F_37 ( V_31 -> V_49 -> V_50 , V_81 , V_83 ) ;
if ( F_35 ( V_24 ) ) {
F_38 ( V_81 ) ;
return F_36 ( V_24 ) ;
}
V_24 -> V_34 = V_40 ;
V_58 = F_39 ( V_31 -> V_49 -> V_50 , V_31 -> V_49 , V_24 , false ) ;
F_40 ( V_24 ) ;
return V_58 ;
}
static int F_41 ( struct V_84 * V_85 , T_2 V_86 ,
unsigned int V_14 , unsigned long V_87 )
{
struct V_78 * V_49 = V_85 -> V_88 ;
struct V_30 * V_31 = V_49 -> V_80 ;
if ( ! F_42 ( V_31 -> V_21 , V_89 ) )
return - V_6 ;
return F_43 ( V_85 , V_86 , V_14 ,
( void V_90 * ) V_87 ) ;
}
static int F_44 ( struct V_84 * V_54 , struct V_91 * V_92 )
{
struct V_30 * V_31 = V_54 -> V_88 -> V_80 ;
if ( F_42 ( V_31 -> V_21 , V_93 ) ) {
F_45 ( V_31 -> V_21 , struct V_94 ,
V_95 . V_96 , & V_92 -> V_96 ) ;
F_45 ( V_31 -> V_21 , struct V_94 ,
V_95 . V_97 , & V_92 -> V_97 ) ;
F_45 ( V_31 -> V_21 , struct V_94 ,
V_95 . V_98 , & V_92 -> V_98 ) ;
} else {
V_92 -> V_97 = 1 << 6 ;
V_92 -> V_98 = 1 << 5 ;
V_92 -> V_96 = F_46 ( V_54 -> V_88 ) >> 11 ;
}
return 0 ;
}
static int F_47 ( int V_44 )
{
return V_44 << V_99 ;
}
static int F_48 ( int V_100 )
{
return V_100 >> V_99 ;
}
static T_3 F_49 ( struct V_101 * V_102 ,
struct V_103 * V_104 , char * V_105 )
{
struct V_78 * V_49 = F_50 ( V_102 ) ;
int V_58 ;
F_51 ( V_106 < V_82 ) ;
V_105 [ V_82 ] = '\0' ;
V_58 = F_33 ( V_49 , V_105 ) ;
if ( ! V_58 )
return strlen ( V_105 ) ;
if ( V_58 == - V_7 )
return 0 ;
return V_58 ;
}
static void F_52 ( struct V_107 * V_108 )
{
struct V_30 * V_31 =
F_53 ( V_108 , struct V_30 , V_109 ) ;
struct V_110 * V_21 = V_31 -> V_21 ;
struct V_111 * V_32 = V_31 -> V_49 -> V_50 ;
char V_112 [ 10 ] , V_113 [ 10 ] ;
char * V_114 [] = { L_1 , NULL } ;
T_4 V_115 , V_116 ;
F_45 ( V_21 , struct V_94 , V_115 , & V_115 ) ;
if ( ( V_117 ) V_115 != V_115 ) {
F_54 ( & V_21 -> V_102 , L_2 ,
( unsigned long long ) V_115 ) ;
V_115 = ( V_117 ) - 1 ;
}
V_116 = V_115 * F_55 ( V_32 ) ;
F_56 ( V_116 , V_118 , V_112 , sizeof( V_112 ) ) ;
F_56 ( V_116 , V_119 , V_113 , sizeof( V_113 ) ) ;
F_57 ( & V_21 -> V_102 ,
L_3 ,
( unsigned long long ) V_115 ,
F_55 ( V_32 ) ,
V_113 , V_112 ) ;
F_58 ( V_31 -> V_49 , V_115 ) ;
F_59 ( V_31 -> V_49 ) ;
F_60 ( & F_61 ( V_31 -> V_49 ) -> V_120 , V_121 , V_114 ) ;
}
static void F_62 ( struct V_110 * V_21 )
{
struct V_30 * V_31 = V_21 -> V_41 ;
F_63 ( V_122 , & V_31 -> V_109 ) ;
}
static int F_64 ( struct V_30 * V_31 )
{
int V_58 = 0 ;
int V_123 ;
T_5 * * V_124 ;
const char * * V_125 ;
struct V_8 * * V_47 ;
unsigned short V_126 ;
struct V_110 * V_21 = V_31 -> V_21 ;
V_58 = F_65 ( V_21 , V_127 ,
struct V_94 , V_128 ,
& V_126 ) ;
if ( V_58 )
V_126 = 1 ;
V_31 -> V_47 = F_66 ( sizeof( * V_31 -> V_47 ) * V_126 , V_83 ) ;
if ( ! V_31 -> V_47 ) {
V_58 = - V_72 ;
goto V_129;
}
V_125 = F_66 ( sizeof( * V_125 ) * V_126 , V_83 ) ;
if ( ! V_125 )
goto V_130;
V_124 = F_66 ( sizeof( * V_124 ) * V_126 , V_83 ) ;
if ( ! V_124 )
goto V_131;
V_47 = F_66 ( sizeof( * V_47 ) * V_126 , V_83 ) ;
if ( ! V_47 )
goto V_132;
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
V_124 [ V_123 ] = F_10 ;
snprintf ( V_31 -> V_47 [ V_123 ] . V_133 , V_134 , L_4 , V_123 ) ;
V_125 [ V_123 ] = V_31 -> V_47 [ V_123 ] . V_133 ;
}
V_58 = V_21 -> V_135 -> V_136 ( V_21 , V_126 , V_47 , V_124 , V_125 ) ;
if ( V_58 )
goto V_137;
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
F_67 ( & V_31 -> V_47 [ V_123 ] . V_48 ) ;
V_31 -> V_47 [ V_123 ] . V_9 = V_47 [ V_123 ] ;
}
V_31 -> V_126 = V_126 ;
V_137:
F_68 ( V_47 ) ;
V_132:
F_68 ( V_124 ) ;
V_131:
F_68 ( V_125 ) ;
V_130:
if ( V_58 )
F_68 ( V_31 -> V_47 ) ;
V_129:
return V_58 ;
}
static int F_69 ( char * V_138 , int V_44 , char * V_105 , int V_139 )
{
const int V_140 = 'z' - 'a' + 1 ;
char * V_141 = V_105 + strlen ( V_138 ) ;
char * V_142 = V_105 + V_139 ;
char * V_143 ;
int V_144 ;
V_143 = V_142 - 1 ;
* V_143 = '\0' ;
V_144 = V_140 ;
do {
if ( V_143 == V_141 )
return - V_145 ;
* -- V_143 = 'a' + ( V_44 % V_144 ) ;
V_44 = ( V_44 / V_144 ) - 1 ;
} while ( V_44 >= 0 );
memmove ( V_141 , V_143 , V_142 - V_143 ) ;
memcpy ( V_105 , V_138 , strlen ( V_138 ) ) ;
return 0 ;
}
static int F_70 ( struct V_110 * V_21 )
{
T_6 V_146 ;
int V_58 ;
V_58 = F_65 ( V_21 , V_147 ,
struct V_94 , V_148 ,
& V_146 ) ;
if ( V_58 )
V_146 = F_42 ( V_21 , V_149 ) ||
F_42 ( V_21 , V_150 ) ;
return V_146 ;
}
static void F_71 ( struct V_110 * V_21 )
{
T_6 V_146 = F_70 ( V_21 ) ;
struct V_30 * V_31 = V_21 -> V_41 ;
if ( V_146 )
F_72 ( V_31 -> V_49 -> V_50 , V_63 ) ;
else
F_72 ( V_31 -> V_49 -> V_50 , 0 ) ;
F_59 ( V_31 -> V_49 ) ;
}
static T_3
F_73 ( struct V_101 * V_102 , struct V_103 * V_104 ,
const char * V_105 , T_7 V_151 )
{
struct V_78 * V_49 = F_50 ( V_102 ) ;
struct V_30 * V_31 = V_49 -> V_80 ;
struct V_110 * V_21 = V_31 -> V_21 ;
int V_123 ;
F_21 ( ! F_42 ( V_31 -> V_21 , V_147 ) ) ;
for ( V_123 = F_74 ( V_152 ) ; -- V_123 >= 0 ; )
if ( F_75 ( V_105 , V_152 [ V_123 ] ) )
break;
if ( V_123 < 0 )
return - V_145 ;
F_76 ( V_21 , F_77 ( struct V_94 , V_148 ) , V_123 ) ;
F_71 ( V_21 ) ;
return V_151 ;
}
static T_3
F_78 ( struct V_101 * V_102 , struct V_103 * V_104 ,
char * V_105 )
{
struct V_78 * V_49 = F_50 ( V_102 ) ;
struct V_30 * V_31 = V_49 -> V_80 ;
T_6 V_146 = F_70 ( V_31 -> V_21 ) ;
F_21 ( V_146 >= F_74 ( V_152 ) ) ;
return snprintf ( V_105 , 40 , L_5 , V_152 [ V_146 ] ) ;
}
static int F_79 ( void * V_87 , struct V_29 * V_55 ,
unsigned int V_153 , unsigned int V_154 ,
unsigned int V_155 )
{
struct V_30 * V_31 = V_87 ;
struct V_1 * V_2 = F_7 ( V_55 ) ;
F_80 ( V_2 -> V_69 , V_31 -> V_61 ) ;
return 0 ;
}
static int F_81 ( struct V_110 * V_21 )
{
struct V_30 * V_31 ;
struct V_111 * V_32 ;
int V_58 , V_44 ;
T_4 V_156 ;
T_8 V_157 , V_158 , V_61 , V_159 ;
T_9 V_160 ;
T_6 V_161 , V_162 ;
if ( ! V_21 -> V_135 -> V_163 ) {
F_82 ( & V_21 -> V_102 , L_6 ,
V_164 ) ;
return - V_145 ;
}
V_58 = F_83 ( & V_165 , 0 , F_48 ( 1 << V_166 ) ,
V_83 ) ;
if ( V_58 < 0 )
goto V_129;
V_44 = V_58 ;
V_58 = F_65 ( V_21 , V_167 ,
struct V_94 , V_168 ,
& V_61 ) ;
if ( V_58 || ! V_61 )
V_61 = 1 ;
V_61 += 2 ;
V_21 -> V_41 = V_31 = F_66 ( sizeof( * V_31 ) , V_83 ) ;
if ( ! V_31 ) {
V_58 = - V_72 ;
goto V_169;
}
V_31 -> V_21 = V_21 ;
V_31 -> V_61 = V_61 ;
F_84 ( & V_31 -> V_109 , F_52 ) ;
V_58 = F_64 ( V_31 ) ;
if ( V_58 )
goto V_170;
V_31 -> V_49 = F_85 ( 1 << V_99 ) ;
if ( ! V_31 -> V_49 ) {
V_58 = - V_72 ;
goto V_171;
}
if ( ! V_172 ) {
V_172 = V_31 -> V_47 [ 0 ] . V_9 -> V_173 ;
if ( ! F_42 ( V_21 , V_174 ) )
V_172 /= 2 ;
}
memset ( & V_31 -> V_175 , 0 , sizeof( V_31 -> V_175 ) ) ;
V_31 -> V_175 . V_176 = & V_177 ;
V_31 -> V_175 . V_178 = V_172 ;
V_31 -> V_175 . V_155 = V_179 ;
V_31 -> V_175 . V_45 = V_180 ;
V_31 -> V_175 . V_181 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_61 ;
V_31 -> V_175 . V_182 = V_31 ;
V_31 -> V_175 . V_183 = V_31 -> V_126 ;
V_58 = F_86 ( & V_31 -> V_175 ) ;
if ( V_58 )
goto V_184;
V_32 = V_31 -> V_49 -> V_50 = F_87 ( & V_31 -> V_175 ) ;
if ( F_35 ( V_32 ) ) {
V_58 = - V_72 ;
goto V_185;
}
V_32 -> V_33 = V_31 ;
F_69 ( L_7 , V_44 , V_31 -> V_49 -> V_186 , V_187 ) ;
V_31 -> V_49 -> V_188 = V_188 ;
V_31 -> V_49 -> V_189 = F_47 ( V_44 ) ;
V_31 -> V_49 -> V_80 = V_31 ;
V_31 -> V_49 -> V_190 = & V_191 ;
V_31 -> V_49 -> V_192 = & V_21 -> V_102 ;
V_31 -> V_44 = V_44 ;
F_71 ( V_21 ) ;
if ( F_42 ( V_21 , V_193 ) )
F_88 ( V_31 -> V_49 , 1 ) ;
F_45 ( V_21 , struct V_94 , V_115 , & V_156 ) ;
if ( ( V_117 ) V_156 != V_156 ) {
F_54 ( & V_21 -> V_102 , L_2 ,
( unsigned long long ) V_156 ) ;
V_156 = ( V_117 ) - 1 ;
}
F_58 ( V_31 -> V_49 , V_156 ) ;
F_89 ( V_32 , V_31 -> V_61 - 2 ) ;
F_90 ( V_32 , V_194 ) ;
F_91 ( V_32 , - 1U ) ;
V_58 = F_65 ( V_21 , V_195 ,
struct V_94 , V_196 , & V_157 ) ;
if ( ! V_58 )
F_92 ( V_32 , V_157 ) ;
else
F_92 ( V_32 , - 1U ) ;
V_58 = F_65 ( V_21 , V_197 ,
struct V_94 , V_158 ,
& V_158 ) ;
if ( ! V_58 )
F_93 ( V_32 , V_158 ) ;
else
V_158 = F_55 ( V_32 ) ;
V_58 = F_65 ( V_21 , V_198 ,
struct V_94 , V_161 ,
& V_161 ) ;
if ( ! V_58 && V_161 )
F_94 ( V_32 ,
V_158 * ( 1 << V_161 ) ) ;
V_58 = F_65 ( V_21 , V_198 ,
struct V_94 , V_162 ,
& V_162 ) ;
if ( ! V_58 && V_162 )
F_95 ( V_32 , V_158 * V_162 ) ;
V_58 = F_65 ( V_21 , V_198 ,
struct V_94 , V_160 ,
& V_160 ) ;
if ( ! V_58 && V_160 )
F_96 ( V_32 , V_158 * V_160 ) ;
V_58 = F_65 ( V_21 , V_198 ,
struct V_94 , V_159 ,
& V_159 ) ;
if ( ! V_58 && V_159 )
F_97 ( V_32 , V_158 * V_159 ) ;
F_98 ( V_21 ) ;
F_99 ( V_31 -> V_49 ) ;
V_58 = F_100 ( F_61 ( V_31 -> V_49 ) , & V_199 ) ;
if ( V_58 )
goto V_200;
if ( F_42 ( V_21 , V_147 ) )
V_58 = F_100 ( F_61 ( V_31 -> V_49 ) ,
& V_201 ) ;
else
V_58 = F_100 ( F_61 ( V_31 -> V_49 ) ,
& V_202 ) ;
if ( V_58 )
goto V_200;
return 0 ;
V_200:
F_101 ( V_31 -> V_49 ) ;
F_102 ( V_31 -> V_49 -> V_50 ) ;
V_185:
F_103 ( & V_31 -> V_175 ) ;
V_184:
F_104 ( V_31 -> V_49 ) ;
V_171:
V_21 -> V_135 -> V_203 ( V_21 ) ;
V_170:
F_68 ( V_31 ) ;
V_169:
F_105 ( & V_165 , V_44 ) ;
V_129:
return V_58 ;
}
static void F_106 ( struct V_110 * V_21 )
{
struct V_30 * V_31 = V_21 -> V_41 ;
int V_44 = V_31 -> V_44 ;
int V_204 ;
F_107 ( & V_31 -> V_109 ) ;
F_101 ( V_31 -> V_49 ) ;
F_102 ( V_31 -> V_49 -> V_50 ) ;
F_103 ( & V_31 -> V_175 ) ;
V_21 -> V_135 -> V_205 ( V_21 ) ;
V_204 = F_108 ( & F_61 ( V_31 -> V_49 ) -> V_120 . V_206 . V_207 ) ;
F_104 ( V_31 -> V_49 ) ;
V_21 -> V_135 -> V_203 ( V_21 ) ;
F_68 ( V_31 -> V_47 ) ;
F_68 ( V_31 ) ;
if ( V_204 == 1 )
F_105 ( & V_165 , V_44 ) ;
}
static int F_109 ( struct V_110 * V_21 )
{
struct V_30 * V_31 = V_21 -> V_41 ;
V_21 -> V_135 -> V_205 ( V_21 ) ;
F_107 ( & V_31 -> V_109 ) ;
F_110 ( V_31 -> V_49 -> V_50 ) ;
V_21 -> V_135 -> V_203 ( V_21 ) ;
return 0 ;
}
static int F_111 ( struct V_110 * V_21 )
{
struct V_30 * V_31 = V_21 -> V_41 ;
int V_208 ;
V_208 = F_64 ( V_21 -> V_41 ) ;
if ( V_208 )
return V_208 ;
F_98 ( V_21 ) ;
F_18 ( V_31 -> V_49 -> V_50 , true ) ;
return 0 ;
}
static int T_10 F_112 ( void )
{
int error ;
V_122 = F_113 ( L_8 , 0 , 0 ) ;
if ( ! V_122 )
return - V_72 ;
V_188 = F_114 ( 0 , L_9 ) ;
if ( V_188 < 0 ) {
error = V_188 ;
goto V_209;
}
error = F_115 ( & V_30 ) ;
if ( error )
goto V_210;
return 0 ;
V_210:
F_116 ( V_188 , L_9 ) ;
V_209:
F_117 ( V_122 ) ;
return error ;
}
static void T_11 F_118 ( void )
{
F_119 ( & V_30 ) ;
F_116 ( V_188 , L_9 ) ;
F_117 ( V_122 ) ;
}
