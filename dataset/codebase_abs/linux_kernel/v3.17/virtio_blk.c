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
int type = V_2 -> V_20 . type & ~ V_21 ;
F_3 ( & V_13 , & V_2 -> V_20 , sizeof( V_2 -> V_20 ) ) ;
V_17 [ V_18 ++ ] = & V_13 ;
if ( type == V_22 ) {
F_3 ( & V_14 , V_2 -> V_23 -> V_14 , V_2 -> V_23 -> V_24 ) ;
V_17 [ V_18 ++ ] = & V_14 ;
}
if ( V_12 ) {
if ( V_2 -> V_20 . type & V_21 )
V_17 [ V_18 ++ ] = V_11 ;
else
V_17 [ V_18 + V_19 ++ ] = V_11 ;
}
if ( type == V_22 ) {
F_3 ( & V_15 , V_2 -> V_23 -> V_15 , V_25 ) ;
V_17 [ V_18 + V_19 ++ ] = & V_15 ;
F_3 ( & V_16 , & V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_16 ;
}
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_3 ;
return F_4 ( V_9 , V_17 , V_18 , V_19 , V_2 , V_27 ) ;
}
static inline void F_5 ( struct V_28 * V_23 )
{
struct V_1 * V_2 = F_6 ( V_23 ) ;
int error = F_1 ( V_2 ) ;
if ( V_23 -> V_29 == V_30 ) {
V_23 -> V_31 = V_2 -> V_26 . V_32 ;
V_23 -> V_33 = V_2 -> V_26 . V_33 ;
V_23 -> V_34 = V_2 -> V_26 . V_34 ;
} else if ( V_23 -> V_29 == V_35 ) {
V_23 -> V_34 = ( error != 0 ) ;
}
F_7 ( V_23 , error ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_36 * V_37 = V_9 -> V_38 -> V_39 ;
bool V_40 = false ;
int V_41 = V_9 -> V_42 ;
struct V_1 * V_2 ;
unsigned long V_43 ;
unsigned int V_44 ;
F_9 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
do {
F_10 ( V_9 ) ;
while ( ( V_2 = F_11 ( V_37 -> V_45 [ V_41 ] . V_9 , & V_44 ) ) != NULL ) {
F_12 ( V_2 -> V_23 ) ;
V_40 = true ;
}
if ( F_13 ( F_14 ( V_9 ) ) )
break;
} while ( ! F_15 ( V_9 ) );
if ( V_40 )
F_16 ( V_37 -> V_47 -> V_48 , true ) ;
F_17 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
}
static int F_18 ( struct V_49 * V_50 , struct V_28 * V_23 )
{
struct V_36 * V_37 = V_50 -> V_48 -> V_51 ;
struct V_1 * V_2 = F_6 ( V_23 ) ;
unsigned long V_43 ;
unsigned int V_52 ;
int V_41 = V_50 -> V_53 ;
const bool V_54 = ( V_23 -> V_55 & V_56 ) != 0 ;
int V_57 ;
bool V_58 = false ;
F_19 ( V_23 -> V_59 + 2 > V_37 -> V_60 ) ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_55 & V_61 ) {
V_2 -> V_20 . type = V_62 ;
V_2 -> V_20 . V_63 = 0 ;
V_2 -> V_20 . V_64 = F_20 ( V_2 -> V_23 ) ;
} else {
switch ( V_23 -> V_29 ) {
case V_65 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_63 = F_21 ( V_2 -> V_23 ) ;
V_2 -> V_20 . V_64 = F_20 ( V_2 -> V_23 ) ;
break;
case V_30 :
V_2 -> V_20 . type = V_22 ;
V_2 -> V_20 . V_63 = 0 ;
V_2 -> V_20 . V_64 = F_20 ( V_2 -> V_23 ) ;
break;
case V_35 :
V_2 -> V_20 . type = V_66 ;
V_2 -> V_20 . V_63 = 0 ;
V_2 -> V_20 . V_64 = F_20 ( V_2 -> V_23 ) ;
break;
default:
F_22 () ;
}
}
V_52 = F_23 ( V_50 -> V_48 , V_2 -> V_23 , V_2 -> V_67 ) ;
if ( V_52 ) {
if ( F_24 ( V_2 -> V_23 ) == V_68 )
V_2 -> V_20 . type |= V_21 ;
else
V_2 -> V_20 . type |= V_69 ;
}
F_9 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
V_57 = F_2 ( V_37 -> V_45 [ V_41 ] . V_9 , V_2 , V_2 -> V_67 , V_52 ) ;
if ( V_57 ) {
F_25 ( V_37 -> V_45 [ V_41 ] . V_9 ) ;
F_26 ( V_50 ) ;
F_17 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
if ( V_57 == - V_70 || V_57 == - V_71 )
return V_72 ;
return V_73 ;
}
if ( V_54 && F_27 ( V_37 -> V_45 [ V_41 ] . V_9 ) )
V_58 = true ;
F_17 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
if ( V_58 )
F_28 ( V_37 -> V_45 [ V_41 ] . V_9 ) ;
return V_74 ;
}
static int F_29 ( struct V_75 * V_47 , char * V_76 )
{
struct V_36 * V_37 = V_47 -> V_77 ;
struct V_28 * V_23 ;
struct V_78 * V_78 ;
int V_57 ;
V_78 = F_30 ( V_37 -> V_47 -> V_48 , V_76 , V_79 ,
V_80 ) ;
if ( F_31 ( V_78 ) )
return F_32 ( V_78 ) ;
V_23 = F_33 ( V_37 -> V_47 -> V_48 , V_78 , V_80 ) ;
if ( F_31 ( V_23 ) ) {
F_34 ( V_78 ) ;
return F_32 ( V_23 ) ;
}
V_23 -> V_29 = V_35 ;
V_57 = F_35 ( V_37 -> V_47 -> V_48 , V_37 -> V_47 , V_23 , false ) ;
F_36 ( V_23 ) ;
return V_57 ;
}
static int F_37 ( struct V_81 * V_82 , T_1 V_83 ,
unsigned int V_14 , unsigned long V_84 )
{
struct V_75 * V_47 = V_82 -> V_85 ;
struct V_36 * V_37 = V_47 -> V_77 ;
if ( ! F_38 ( V_37 -> V_38 , V_86 ) )
return - V_6 ;
return F_39 ( V_82 , V_83 , V_14 ,
( void V_87 * ) V_84 ) ;
}
static int F_40 ( struct V_81 * V_88 , struct V_89 * V_90 )
{
struct V_36 * V_37 = V_88 -> V_85 -> V_77 ;
if ( F_38 ( V_37 -> V_38 , V_91 ) ) {
F_41 ( V_37 -> V_38 , struct V_92 ,
V_93 . V_94 , & V_90 -> V_94 ) ;
F_41 ( V_37 -> V_38 , struct V_92 ,
V_93 . V_95 , & V_90 -> V_95 ) ;
F_41 ( V_37 -> V_38 , struct V_92 ,
V_93 . V_96 , & V_90 -> V_96 ) ;
} else {
V_90 -> V_95 = 1 << 6 ;
V_90 -> V_96 = 1 << 5 ;
V_90 -> V_94 = F_42 ( V_88 -> V_85 ) >> 11 ;
}
return 0 ;
}
static int F_43 ( int V_42 )
{
return V_42 << V_97 ;
}
static int F_44 ( int V_98 )
{
return V_98 >> V_97 ;
}
static T_2 F_45 ( struct V_99 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_75 * V_47 = F_46 ( V_100 ) ;
int V_57 ;
F_47 ( V_104 < V_79 ) ;
V_103 [ V_79 ] = '\0' ;
V_57 = F_29 ( V_47 , V_103 ) ;
if ( ! V_57 )
return strlen ( V_103 ) ;
if ( V_57 == - V_7 )
return 0 ;
return V_57 ;
}
static void F_48 ( struct V_105 * V_106 )
{
struct V_36 * V_37 =
F_49 ( V_106 , struct V_36 , V_107 ) ;
struct V_108 * V_38 = V_37 -> V_38 ;
struct V_109 * V_110 = V_37 -> V_47 -> V_48 ;
char V_111 [ 10 ] , V_112 [ 10 ] ;
char * V_113 [] = { L_1 , NULL } ;
T_3 V_114 , V_115 ;
F_50 ( & V_37 -> V_116 ) ;
if ( ! V_37 -> V_117 )
goto V_118;
F_41 ( V_38 , struct V_92 , V_114 , & V_114 ) ;
if ( ( V_119 ) V_114 != V_114 ) {
F_51 ( & V_38 -> V_100 , L_2 ,
( unsigned long long ) V_114 ) ;
V_114 = ( V_119 ) - 1 ;
}
V_115 = V_114 * F_52 ( V_110 ) ;
F_53 ( V_115 , V_120 , V_111 , sizeof( V_111 ) ) ;
F_53 ( V_115 , V_121 , V_112 , sizeof( V_112 ) ) ;
F_54 ( & V_38 -> V_100 ,
L_3 ,
( unsigned long long ) V_114 ,
F_52 ( V_110 ) ,
V_112 , V_111 ) ;
F_55 ( V_37 -> V_47 , V_114 ) ;
F_56 ( V_37 -> V_47 ) ;
F_57 ( & F_58 ( V_37 -> V_47 ) -> V_122 , V_123 , V_113 ) ;
V_118:
F_59 ( & V_37 -> V_116 ) ;
}
static void F_60 ( struct V_108 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
F_61 ( V_124 , & V_37 -> V_107 ) ;
}
static int F_62 ( struct V_36 * V_37 )
{
int V_57 = 0 ;
int V_125 ;
T_4 * * V_126 ;
const char * * V_127 ;
struct V_8 * * V_45 ;
unsigned short V_128 ;
struct V_108 * V_38 = V_37 -> V_38 ;
V_57 = F_63 ( V_38 , V_129 ,
struct V_92 , V_130 ,
& V_128 ) ;
if ( V_57 )
V_128 = 1 ;
V_37 -> V_45 = F_64 ( sizeof( * V_37 -> V_45 ) * V_128 , V_80 ) ;
if ( ! V_37 -> V_45 ) {
V_57 = - V_70 ;
goto V_131;
}
V_127 = F_64 ( sizeof( * V_127 ) * V_128 , V_80 ) ;
if ( ! V_127 )
goto V_132;
V_126 = F_64 ( sizeof( * V_126 ) * V_128 , V_80 ) ;
if ( ! V_126 )
goto V_133;
V_45 = F_64 ( sizeof( * V_45 ) * V_128 , V_80 ) ;
if ( ! V_45 )
goto V_134;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_126 [ V_125 ] = F_8 ;
snprintf ( V_37 -> V_45 [ V_125 ] . V_135 , V_136 , L_4 , V_125 ) ;
V_127 [ V_125 ] = V_37 -> V_45 [ V_125 ] . V_135 ;
}
V_57 = V_38 -> V_137 -> V_138 ( V_38 , V_128 , V_45 , V_126 , V_127 ) ;
if ( V_57 )
goto V_139;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
F_65 ( & V_37 -> V_45 [ V_125 ] . V_46 ) ;
V_37 -> V_45 [ V_125 ] . V_9 = V_45 [ V_125 ] ;
}
V_37 -> V_128 = V_128 ;
V_139:
F_66 ( V_45 ) ;
V_134:
F_66 ( V_126 ) ;
V_133:
F_66 ( V_127 ) ;
V_132:
if ( V_57 )
F_66 ( V_37 -> V_45 ) ;
V_131:
return V_57 ;
}
static int F_67 ( char * V_140 , int V_42 , char * V_103 , int V_141 )
{
const int V_142 = 'z' - 'a' + 1 ;
char * V_143 = V_103 + strlen ( V_140 ) ;
char * V_144 = V_103 + V_141 ;
char * V_145 ;
int V_146 ;
V_145 = V_144 - 1 ;
* V_145 = '\0' ;
V_146 = V_142 ;
do {
if ( V_145 == V_143 )
return - V_147 ;
* -- V_145 = 'a' + ( V_42 % V_146 ) ;
V_42 = ( V_42 / V_146 ) - 1 ;
} while ( V_42 >= 0 );
memmove ( V_143 , V_145 , V_144 - V_145 ) ;
memcpy ( V_103 , V_140 , strlen ( V_140 ) ) ;
return 0 ;
}
static int F_68 ( struct V_108 * V_38 )
{
T_5 V_148 ;
int V_57 ;
V_57 = F_63 ( V_38 , V_149 ,
struct V_92 , V_150 ,
& V_148 ) ;
if ( V_57 )
V_148 = F_38 ( V_38 , V_151 ) ;
return V_148 ;
}
static void F_69 ( struct V_108 * V_38 )
{
T_5 V_148 = F_68 ( V_38 ) ;
struct V_36 * V_37 = V_38 -> V_39 ;
if ( V_148 )
F_70 ( V_37 -> V_47 -> V_48 , V_61 ) ;
else
F_70 ( V_37 -> V_47 -> V_48 , 0 ) ;
F_56 ( V_37 -> V_47 ) ;
}
static T_2
F_71 ( struct V_99 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_6 V_152 )
{
struct V_75 * V_47 = F_46 ( V_100 ) ;
struct V_36 * V_37 = V_47 -> V_77 ;
struct V_108 * V_38 = V_37 -> V_38 ;
int V_125 ;
F_19 ( ! F_38 ( V_37 -> V_38 , V_149 ) ) ;
for ( V_125 = F_72 ( V_153 ) ; -- V_125 >= 0 ; )
if ( F_73 ( V_103 , V_153 [ V_125 ] ) )
break;
if ( V_125 < 0 )
return - V_147 ;
F_74 ( V_38 , F_75 ( struct V_92 , V_150 ) , V_125 ) ;
F_69 ( V_38 ) ;
return V_152 ;
}
static T_2
F_76 ( struct V_99 * V_100 , struct V_101 * V_102 ,
char * V_103 )
{
struct V_75 * V_47 = F_46 ( V_100 ) ;
struct V_36 * V_37 = V_47 -> V_77 ;
T_5 V_148 = F_68 ( V_37 -> V_38 ) ;
F_19 ( V_148 >= F_72 ( V_153 ) ) ;
return snprintf ( V_103 , 40 , L_5 , V_153 [ V_148 ] ) ;
}
static int F_77 ( void * V_84 , struct V_28 * V_154 ,
unsigned int V_155 , unsigned int V_156 ,
unsigned int V_157 )
{
struct V_36 * V_37 = V_84 ;
struct V_1 * V_2 = F_6 ( V_154 ) ;
F_78 ( V_2 -> V_67 , V_37 -> V_60 ) ;
return 0 ;
}
static int F_79 ( struct V_108 * V_38 )
{
struct V_36 * V_37 ;
struct V_109 * V_110 ;
int V_57 , V_42 ;
T_3 V_158 ;
T_7 V_159 , V_160 , V_60 , V_161 ;
T_8 V_162 ;
T_5 V_163 , V_164 ;
V_57 = F_80 ( & V_165 , 0 , F_44 ( 1 << V_166 ) ,
V_80 ) ;
if ( V_57 < 0 )
goto V_131;
V_42 = V_57 ;
V_57 = F_63 ( V_38 , V_167 ,
struct V_92 , V_168 ,
& V_60 ) ;
if ( V_57 || ! V_60 )
V_60 = 1 ;
V_60 += 2 ;
V_38 -> V_39 = V_37 = F_64 ( sizeof( * V_37 ) , V_80 ) ;
if ( ! V_37 ) {
V_57 = - V_70 ;
goto V_169;
}
V_37 -> V_38 = V_38 ;
V_37 -> V_60 = V_60 ;
F_81 ( & V_37 -> V_116 ) ;
F_82 ( & V_37 -> V_107 , F_48 ) ;
V_37 -> V_117 = true ;
V_57 = F_62 ( V_37 ) ;
if ( V_57 )
goto V_170;
V_37 -> V_47 = F_83 ( 1 << V_97 ) ;
if ( ! V_37 -> V_47 ) {
V_57 = - V_70 ;
goto V_171;
}
if ( ! V_172 ) {
V_172 = V_37 -> V_45 [ 0 ] . V_9 -> V_173 ;
if ( ! F_38 ( V_38 , V_174 ) )
V_172 /= 2 ;
}
memset ( & V_37 -> V_175 , 0 , sizeof( V_37 -> V_175 ) ) ;
V_37 -> V_175 . V_176 = & V_177 ;
V_37 -> V_175 . V_178 = V_172 ;
V_37 -> V_175 . V_157 = V_179 ;
V_37 -> V_175 . V_43 = V_180 ;
V_37 -> V_175 . V_181 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_60 ;
V_37 -> V_175 . V_182 = V_37 ;
V_37 -> V_175 . V_183 = V_37 -> V_128 ;
V_57 = F_84 ( & V_37 -> V_175 ) ;
if ( V_57 )
goto V_184;
V_110 = V_37 -> V_47 -> V_48 = F_85 ( & V_37 -> V_175 ) ;
if ( ! V_110 ) {
V_57 = - V_70 ;
goto V_185;
}
V_110 -> V_51 = V_37 ;
F_67 ( L_6 , V_42 , V_37 -> V_47 -> V_186 , V_187 ) ;
V_37 -> V_47 -> V_188 = V_188 ;
V_37 -> V_47 -> V_189 = F_43 ( V_42 ) ;
V_37 -> V_47 -> V_77 = V_37 ;
V_37 -> V_47 -> V_190 = & V_191 ;
V_37 -> V_47 -> V_192 = & V_38 -> V_100 ;
V_37 -> V_42 = V_42 ;
F_69 ( V_38 ) ;
if ( F_38 ( V_38 , V_193 ) )
F_86 ( V_37 -> V_47 , 1 ) ;
F_41 ( V_38 , struct V_92 , V_114 , & V_158 ) ;
if ( ( V_119 ) V_158 != V_158 ) {
F_51 ( & V_38 -> V_100 , L_2 ,
( unsigned long long ) V_158 ) ;
V_158 = ( V_119 ) - 1 ;
}
F_55 ( V_37 -> V_47 , V_158 ) ;
F_87 ( V_110 , V_37 -> V_60 - 2 ) ;
F_88 ( V_110 , V_194 ) ;
F_89 ( V_110 , - 1U ) ;
V_57 = F_63 ( V_38 , V_195 ,
struct V_92 , V_196 , & V_159 ) ;
if ( ! V_57 )
F_90 ( V_110 , V_159 ) ;
else
F_90 ( V_110 , - 1U ) ;
V_57 = F_63 ( V_38 , V_197 ,
struct V_92 , V_160 ,
& V_160 ) ;
if ( ! V_57 )
F_91 ( V_110 , V_160 ) ;
else
V_160 = F_52 ( V_110 ) ;
V_57 = F_63 ( V_38 , V_198 ,
struct V_92 , V_163 ,
& V_163 ) ;
if ( ! V_57 && V_163 )
F_92 ( V_110 ,
V_160 * ( 1 << V_163 ) ) ;
V_57 = F_63 ( V_38 , V_198 ,
struct V_92 , V_164 ,
& V_164 ) ;
if ( ! V_57 && V_164 )
F_93 ( V_110 , V_160 * V_164 ) ;
V_57 = F_63 ( V_38 , V_198 ,
struct V_92 , V_162 ,
& V_162 ) ;
if ( ! V_57 && V_162 )
F_94 ( V_110 , V_160 * V_162 ) ;
V_57 = F_63 ( V_38 , V_198 ,
struct V_92 , V_161 ,
& V_161 ) ;
if ( ! V_57 && V_161 )
F_95 ( V_110 , V_160 * V_161 ) ;
F_96 ( V_37 -> V_47 ) ;
V_57 = F_97 ( F_58 ( V_37 -> V_47 ) , & V_199 ) ;
if ( V_57 )
goto V_200;
if ( F_38 ( V_38 , V_149 ) )
V_57 = F_97 ( F_58 ( V_37 -> V_47 ) ,
& V_201 ) ;
else
V_57 = F_97 ( F_58 ( V_37 -> V_47 ) ,
& V_202 ) ;
if ( V_57 )
goto V_200;
return 0 ;
V_200:
F_98 ( V_37 -> V_47 ) ;
F_99 ( V_37 -> V_47 -> V_48 ) ;
V_185:
F_100 ( & V_37 -> V_175 ) ;
V_184:
F_101 ( V_37 -> V_47 ) ;
V_171:
V_38 -> V_137 -> V_203 ( V_38 ) ;
V_170:
F_66 ( V_37 ) ;
V_169:
F_102 ( & V_165 , V_42 ) ;
V_131:
return V_57 ;
}
static void F_103 ( struct V_108 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_42 = V_37 -> V_42 ;
int V_204 ;
F_50 ( & V_37 -> V_116 ) ;
V_37 -> V_117 = false ;
F_59 ( & V_37 -> V_116 ) ;
F_98 ( V_37 -> V_47 ) ;
F_99 ( V_37 -> V_47 -> V_48 ) ;
F_100 ( & V_37 -> V_175 ) ;
V_38 -> V_137 -> V_205 ( V_38 ) ;
F_104 ( & V_37 -> V_107 ) ;
V_204 = F_105 ( & F_58 ( V_37 -> V_47 ) -> V_122 . V_206 . V_207 ) ;
F_101 ( V_37 -> V_47 ) ;
V_38 -> V_137 -> V_203 ( V_38 ) ;
F_66 ( V_37 -> V_45 ) ;
F_66 ( V_37 ) ;
if ( V_204 == 1 )
F_102 ( & V_165 , V_42 ) ;
}
static int F_106 ( struct V_108 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
V_38 -> V_137 -> V_205 ( V_38 ) ;
F_50 ( & V_37 -> V_116 ) ;
V_37 -> V_117 = false ;
F_59 ( & V_37 -> V_116 ) ;
F_104 ( & V_37 -> V_107 ) ;
F_107 ( V_37 -> V_47 -> V_48 ) ;
V_38 -> V_137 -> V_203 ( V_38 ) ;
return 0 ;
}
static int F_108 ( struct V_108 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_208 ;
V_37 -> V_117 = true ;
V_208 = F_62 ( V_38 -> V_39 ) ;
if ( ! V_208 )
F_16 ( V_37 -> V_47 -> V_48 , true ) ;
return V_208 ;
}
static int T_9 F_109 ( void )
{
int error ;
V_124 = F_110 ( L_7 , 0 , 0 ) ;
if ( ! V_124 )
return - V_70 ;
V_188 = F_111 ( 0 , L_8 ) ;
if ( V_188 < 0 ) {
error = V_188 ;
goto V_209;
}
error = F_112 ( & V_36 ) ;
if ( error )
goto V_210;
return 0 ;
V_210:
F_113 ( V_188 , L_8 ) ;
V_209:
F_114 ( V_124 ) ;
return error ;
}
static void T_10 F_115 ( void )
{
F_113 ( V_188 , L_8 ) ;
F_116 ( & V_36 ) ;
F_114 ( V_124 ) ;
}
