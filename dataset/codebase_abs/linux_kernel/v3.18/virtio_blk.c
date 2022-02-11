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
static int F_18 ( struct V_49 * V_50 , struct V_28 * V_23 ,
bool V_51 )
{
struct V_36 * V_37 = V_50 -> V_48 -> V_52 ;
struct V_1 * V_2 = F_6 ( V_23 ) ;
unsigned long V_43 ;
unsigned int V_53 ;
int V_41 = V_50 -> V_54 ;
int V_55 ;
bool V_56 = false ;
F_19 ( V_23 -> V_57 + 2 > V_37 -> V_58 ) ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_59 & V_60 ) {
V_2 -> V_20 . type = V_61 ;
V_2 -> V_20 . V_62 = 0 ;
V_2 -> V_20 . V_63 = F_20 ( V_2 -> V_23 ) ;
} else {
switch ( V_23 -> V_29 ) {
case V_64 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_62 = F_21 ( V_2 -> V_23 ) ;
V_2 -> V_20 . V_63 = F_20 ( V_2 -> V_23 ) ;
break;
case V_30 :
V_2 -> V_20 . type = V_22 ;
V_2 -> V_20 . V_62 = 0 ;
V_2 -> V_20 . V_63 = F_20 ( V_2 -> V_23 ) ;
break;
case V_35 :
V_2 -> V_20 . type = V_65 ;
V_2 -> V_20 . V_62 = 0 ;
V_2 -> V_20 . V_63 = F_20 ( V_2 -> V_23 ) ;
break;
default:
F_22 () ;
}
}
F_23 ( V_23 ) ;
V_53 = F_24 ( V_50 -> V_48 , V_2 -> V_23 , V_2 -> V_66 ) ;
if ( V_53 ) {
if ( F_25 ( V_2 -> V_23 ) == V_67 )
V_2 -> V_20 . type |= V_21 ;
else
V_2 -> V_20 . type |= V_68 ;
}
F_9 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
V_55 = F_2 ( V_37 -> V_45 [ V_41 ] . V_9 , V_2 , V_2 -> V_66 , V_53 ) ;
if ( V_55 ) {
F_26 ( V_37 -> V_45 [ V_41 ] . V_9 ) ;
F_27 ( V_50 ) ;
F_17 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
if ( V_55 == - V_69 || V_55 == - V_70 )
return V_71 ;
return V_72 ;
}
if ( V_51 && F_28 ( V_37 -> V_45 [ V_41 ] . V_9 ) )
V_56 = true ;
F_17 ( & V_37 -> V_45 [ V_41 ] . V_46 , V_43 ) ;
if ( V_56 )
F_29 ( V_37 -> V_45 [ V_41 ] . V_9 ) ;
return V_73 ;
}
static int F_30 ( struct V_74 * V_47 , char * V_75 )
{
struct V_36 * V_37 = V_47 -> V_76 ;
struct V_28 * V_23 ;
struct V_77 * V_77 ;
int V_55 ;
V_77 = F_31 ( V_37 -> V_47 -> V_48 , V_75 , V_78 ,
V_79 ) ;
if ( F_32 ( V_77 ) )
return F_33 ( V_77 ) ;
V_23 = F_34 ( V_37 -> V_47 -> V_48 , V_77 , V_79 ) ;
if ( F_32 ( V_23 ) ) {
F_35 ( V_77 ) ;
return F_33 ( V_23 ) ;
}
V_23 -> V_29 = V_35 ;
V_55 = F_36 ( V_37 -> V_47 -> V_48 , V_37 -> V_47 , V_23 , false ) ;
F_37 ( V_23 ) ;
return V_55 ;
}
static int F_38 ( struct V_80 * V_81 , T_1 V_82 ,
unsigned int V_14 , unsigned long V_83 )
{
struct V_74 * V_47 = V_81 -> V_84 ;
struct V_36 * V_37 = V_47 -> V_76 ;
if ( ! F_39 ( V_37 -> V_38 , V_85 ) )
return - V_6 ;
return F_40 ( V_81 , V_82 , V_14 ,
( void V_86 * ) V_83 ) ;
}
static int F_41 ( struct V_80 * V_87 , struct V_88 * V_89 )
{
struct V_36 * V_37 = V_87 -> V_84 -> V_76 ;
if ( F_39 ( V_37 -> V_38 , V_90 ) ) {
F_42 ( V_37 -> V_38 , struct V_91 ,
V_92 . V_93 , & V_89 -> V_93 ) ;
F_42 ( V_37 -> V_38 , struct V_91 ,
V_92 . V_94 , & V_89 -> V_94 ) ;
F_42 ( V_37 -> V_38 , struct V_91 ,
V_92 . V_95 , & V_89 -> V_95 ) ;
} else {
V_89 -> V_94 = 1 << 6 ;
V_89 -> V_95 = 1 << 5 ;
V_89 -> V_93 = F_43 ( V_87 -> V_84 ) >> 11 ;
}
return 0 ;
}
static int F_44 ( int V_42 )
{
return V_42 << V_96 ;
}
static int F_45 ( int V_97 )
{
return V_97 >> V_96 ;
}
static T_2 F_46 ( struct V_98 * V_99 ,
struct V_100 * V_101 , char * V_102 )
{
struct V_74 * V_47 = F_47 ( V_99 ) ;
int V_55 ;
F_48 ( V_103 < V_78 ) ;
V_102 [ V_78 ] = '\0' ;
V_55 = F_30 ( V_47 , V_102 ) ;
if ( ! V_55 )
return strlen ( V_102 ) ;
if ( V_55 == - V_7 )
return 0 ;
return V_55 ;
}
static void F_49 ( struct V_104 * V_105 )
{
struct V_36 * V_37 =
F_50 ( V_105 , struct V_36 , V_106 ) ;
struct V_107 * V_38 = V_37 -> V_38 ;
struct V_108 * V_109 = V_37 -> V_47 -> V_48 ;
char V_110 [ 10 ] , V_111 [ 10 ] ;
char * V_112 [] = { L_1 , NULL } ;
T_3 V_113 , V_114 ;
F_42 ( V_38 , struct V_91 , V_113 , & V_113 ) ;
if ( ( V_115 ) V_113 != V_113 ) {
F_51 ( & V_38 -> V_99 , L_2 ,
( unsigned long long ) V_113 ) ;
V_113 = ( V_115 ) - 1 ;
}
V_114 = V_113 * F_52 ( V_109 ) ;
F_53 ( V_114 , V_116 , V_110 , sizeof( V_110 ) ) ;
F_53 ( V_114 , V_117 , V_111 , sizeof( V_111 ) ) ;
F_54 ( & V_38 -> V_99 ,
L_3 ,
( unsigned long long ) V_113 ,
F_52 ( V_109 ) ,
V_111 , V_110 ) ;
F_55 ( V_37 -> V_47 , V_113 ) ;
F_56 ( V_37 -> V_47 ) ;
F_57 ( & F_58 ( V_37 -> V_47 ) -> V_118 , V_119 , V_112 ) ;
}
static void F_59 ( struct V_107 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
F_60 ( V_120 , & V_37 -> V_106 ) ;
}
static int F_61 ( struct V_36 * V_37 )
{
int V_55 = 0 ;
int V_121 ;
T_4 * * V_122 ;
const char * * V_123 ;
struct V_8 * * V_45 ;
unsigned short V_124 ;
struct V_107 * V_38 = V_37 -> V_38 ;
V_55 = F_62 ( V_38 , V_125 ,
struct V_91 , V_126 ,
& V_124 ) ;
if ( V_55 )
V_124 = 1 ;
V_37 -> V_45 = F_63 ( sizeof( * V_37 -> V_45 ) * V_124 , V_79 ) ;
if ( ! V_37 -> V_45 ) {
V_55 = - V_69 ;
goto V_127;
}
V_123 = F_63 ( sizeof( * V_123 ) * V_124 , V_79 ) ;
if ( ! V_123 )
goto V_128;
V_122 = F_63 ( sizeof( * V_122 ) * V_124 , V_79 ) ;
if ( ! V_122 )
goto V_129;
V_45 = F_63 ( sizeof( * V_45 ) * V_124 , V_79 ) ;
if ( ! V_45 )
goto V_130;
for ( V_121 = 0 ; V_121 < V_124 ; V_121 ++ ) {
V_122 [ V_121 ] = F_8 ;
snprintf ( V_37 -> V_45 [ V_121 ] . V_131 , V_132 , L_4 , V_121 ) ;
V_123 [ V_121 ] = V_37 -> V_45 [ V_121 ] . V_131 ;
}
V_55 = V_38 -> V_133 -> V_134 ( V_38 , V_124 , V_45 , V_122 , V_123 ) ;
if ( V_55 )
goto V_135;
for ( V_121 = 0 ; V_121 < V_124 ; V_121 ++ ) {
F_64 ( & V_37 -> V_45 [ V_121 ] . V_46 ) ;
V_37 -> V_45 [ V_121 ] . V_9 = V_45 [ V_121 ] ;
}
V_37 -> V_124 = V_124 ;
V_135:
F_65 ( V_45 ) ;
V_130:
F_65 ( V_122 ) ;
V_129:
F_65 ( V_123 ) ;
V_128:
if ( V_55 )
F_65 ( V_37 -> V_45 ) ;
V_127:
return V_55 ;
}
static int F_66 ( char * V_136 , int V_42 , char * V_102 , int V_137 )
{
const int V_138 = 'z' - 'a' + 1 ;
char * V_139 = V_102 + strlen ( V_136 ) ;
char * V_140 = V_102 + V_137 ;
char * V_141 ;
int V_142 ;
V_141 = V_140 - 1 ;
* V_141 = '\0' ;
V_142 = V_138 ;
do {
if ( V_141 == V_139 )
return - V_143 ;
* -- V_141 = 'a' + ( V_42 % V_142 ) ;
V_42 = ( V_42 / V_142 ) - 1 ;
} while ( V_42 >= 0 );
memmove ( V_139 , V_141 , V_140 - V_141 ) ;
memcpy ( V_102 , V_136 , strlen ( V_136 ) ) ;
return 0 ;
}
static int F_67 ( struct V_107 * V_38 )
{
T_5 V_144 ;
int V_55 ;
V_55 = F_62 ( V_38 , V_145 ,
struct V_91 , V_146 ,
& V_144 ) ;
if ( V_55 )
V_144 = F_39 ( V_38 , V_147 ) ;
return V_144 ;
}
static void F_68 ( struct V_107 * V_38 )
{
T_5 V_144 = F_67 ( V_38 ) ;
struct V_36 * V_37 = V_38 -> V_39 ;
if ( V_144 )
F_69 ( V_37 -> V_47 -> V_48 , V_60 ) ;
else
F_69 ( V_37 -> V_47 -> V_48 , 0 ) ;
F_56 ( V_37 -> V_47 ) ;
}
static T_2
F_70 ( struct V_98 * V_99 , struct V_100 * V_101 ,
const char * V_102 , T_6 V_148 )
{
struct V_74 * V_47 = F_47 ( V_99 ) ;
struct V_36 * V_37 = V_47 -> V_76 ;
struct V_107 * V_38 = V_37 -> V_38 ;
int V_121 ;
F_19 ( ! F_39 ( V_37 -> V_38 , V_145 ) ) ;
for ( V_121 = F_71 ( V_149 ) ; -- V_121 >= 0 ; )
if ( F_72 ( V_102 , V_149 [ V_121 ] ) )
break;
if ( V_121 < 0 )
return - V_143 ;
F_73 ( V_38 , F_74 ( struct V_91 , V_146 ) , V_121 ) ;
F_68 ( V_38 ) ;
return V_148 ;
}
static T_2
F_75 ( struct V_98 * V_99 , struct V_100 * V_101 ,
char * V_102 )
{
struct V_74 * V_47 = F_47 ( V_99 ) ;
struct V_36 * V_37 = V_47 -> V_76 ;
T_5 V_144 = F_67 ( V_37 -> V_38 ) ;
F_19 ( V_144 >= F_71 ( V_149 ) ) ;
return snprintf ( V_102 , 40 , L_5 , V_149 [ V_144 ] ) ;
}
static int F_76 ( void * V_83 , struct V_28 * V_150 ,
unsigned int V_151 , unsigned int V_152 ,
unsigned int V_153 )
{
struct V_36 * V_37 = V_83 ;
struct V_1 * V_2 = F_6 ( V_150 ) ;
F_77 ( V_2 -> V_66 , V_37 -> V_58 ) ;
return 0 ;
}
static int F_78 ( struct V_107 * V_38 )
{
struct V_36 * V_37 ;
struct V_108 * V_109 ;
int V_55 , V_42 ;
T_3 V_154 ;
T_7 V_155 , V_156 , V_58 , V_157 ;
T_8 V_158 ;
T_5 V_159 , V_160 ;
V_55 = F_79 ( & V_161 , 0 , F_45 ( 1 << V_162 ) ,
V_79 ) ;
if ( V_55 < 0 )
goto V_127;
V_42 = V_55 ;
V_55 = F_62 ( V_38 , V_163 ,
struct V_91 , V_164 ,
& V_58 ) ;
if ( V_55 || ! V_58 )
V_58 = 1 ;
V_58 += 2 ;
V_38 -> V_39 = V_37 = F_63 ( sizeof( * V_37 ) , V_79 ) ;
if ( ! V_37 ) {
V_55 = - V_69 ;
goto V_165;
}
V_37 -> V_38 = V_38 ;
V_37 -> V_58 = V_58 ;
F_80 ( & V_37 -> V_106 , F_49 ) ;
V_55 = F_61 ( V_37 ) ;
if ( V_55 )
goto V_166;
V_37 -> V_47 = F_81 ( 1 << V_96 ) ;
if ( ! V_37 -> V_47 ) {
V_55 = - V_69 ;
goto V_167;
}
if ( ! V_168 ) {
V_168 = V_37 -> V_45 [ 0 ] . V_9 -> V_169 ;
if ( ! F_39 ( V_38 , V_170 ) )
V_168 /= 2 ;
}
memset ( & V_37 -> V_171 , 0 , sizeof( V_37 -> V_171 ) ) ;
V_37 -> V_171 . V_172 = & V_173 ;
V_37 -> V_171 . V_174 = V_168 ;
V_37 -> V_171 . V_153 = V_175 ;
V_37 -> V_171 . V_43 = V_176 ;
V_37 -> V_171 . V_177 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_58 ;
V_37 -> V_171 . V_178 = V_37 ;
V_37 -> V_171 . V_179 = V_37 -> V_124 ;
V_55 = F_82 ( & V_37 -> V_171 ) ;
if ( V_55 )
goto V_180;
V_109 = V_37 -> V_47 -> V_48 = F_83 ( & V_37 -> V_171 ) ;
if ( ! V_109 ) {
V_55 = - V_69 ;
goto V_181;
}
V_109 -> V_52 = V_37 ;
F_66 ( L_6 , V_42 , V_37 -> V_47 -> V_182 , V_183 ) ;
V_37 -> V_47 -> V_184 = V_184 ;
V_37 -> V_47 -> V_185 = F_44 ( V_42 ) ;
V_37 -> V_47 -> V_76 = V_37 ;
V_37 -> V_47 -> V_186 = & V_187 ;
V_37 -> V_47 -> V_188 = & V_38 -> V_99 ;
V_37 -> V_42 = V_42 ;
F_68 ( V_38 ) ;
if ( F_39 ( V_38 , V_189 ) )
F_84 ( V_37 -> V_47 , 1 ) ;
F_42 ( V_38 , struct V_91 , V_113 , & V_154 ) ;
if ( ( V_115 ) V_154 != V_154 ) {
F_51 ( & V_38 -> V_99 , L_2 ,
( unsigned long long ) V_154 ) ;
V_154 = ( V_115 ) - 1 ;
}
F_55 ( V_37 -> V_47 , V_154 ) ;
F_85 ( V_109 , V_37 -> V_58 - 2 ) ;
F_86 ( V_109 , V_190 ) ;
F_87 ( V_109 , - 1U ) ;
V_55 = F_62 ( V_38 , V_191 ,
struct V_91 , V_192 , & V_155 ) ;
if ( ! V_55 )
F_88 ( V_109 , V_155 ) ;
else
F_88 ( V_109 , - 1U ) ;
V_55 = F_62 ( V_38 , V_193 ,
struct V_91 , V_156 ,
& V_156 ) ;
if ( ! V_55 )
F_89 ( V_109 , V_156 ) ;
else
V_156 = F_52 ( V_109 ) ;
V_55 = F_62 ( V_38 , V_194 ,
struct V_91 , V_159 ,
& V_159 ) ;
if ( ! V_55 && V_159 )
F_90 ( V_109 ,
V_156 * ( 1 << V_159 ) ) ;
V_55 = F_62 ( V_38 , V_194 ,
struct V_91 , V_160 ,
& V_160 ) ;
if ( ! V_55 && V_160 )
F_91 ( V_109 , V_156 * V_160 ) ;
V_55 = F_62 ( V_38 , V_194 ,
struct V_91 , V_158 ,
& V_158 ) ;
if ( ! V_55 && V_158 )
F_92 ( V_109 , V_156 * V_158 ) ;
V_55 = F_62 ( V_38 , V_194 ,
struct V_91 , V_157 ,
& V_157 ) ;
if ( ! V_55 && V_157 )
F_93 ( V_109 , V_156 * V_157 ) ;
F_94 ( V_38 ) ;
F_95 ( V_37 -> V_47 ) ;
V_55 = F_96 ( F_58 ( V_37 -> V_47 ) , & V_195 ) ;
if ( V_55 )
goto V_196;
if ( F_39 ( V_38 , V_145 ) )
V_55 = F_96 ( F_58 ( V_37 -> V_47 ) ,
& V_197 ) ;
else
V_55 = F_96 ( F_58 ( V_37 -> V_47 ) ,
& V_198 ) ;
if ( V_55 )
goto V_196;
return 0 ;
V_196:
F_97 ( V_37 -> V_47 ) ;
F_98 ( V_37 -> V_47 -> V_48 ) ;
V_181:
F_99 ( & V_37 -> V_171 ) ;
V_180:
F_100 ( V_37 -> V_47 ) ;
V_167:
V_38 -> V_133 -> V_199 ( V_38 ) ;
V_166:
F_65 ( V_37 ) ;
V_165:
F_101 ( & V_161 , V_42 ) ;
V_127:
return V_55 ;
}
static void F_102 ( struct V_107 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_42 = V_37 -> V_42 ;
int V_200 ;
F_103 ( & V_37 -> V_106 ) ;
F_97 ( V_37 -> V_47 ) ;
F_98 ( V_37 -> V_47 -> V_48 ) ;
F_99 ( & V_37 -> V_171 ) ;
V_38 -> V_133 -> V_201 ( V_38 ) ;
V_200 = F_104 ( & F_58 ( V_37 -> V_47 ) -> V_118 . V_202 . V_203 ) ;
F_100 ( V_37 -> V_47 ) ;
V_38 -> V_133 -> V_199 ( V_38 ) ;
F_65 ( V_37 -> V_45 ) ;
F_65 ( V_37 ) ;
if ( V_200 == 1 )
F_101 ( & V_161 , V_42 ) ;
}
static int F_105 ( struct V_107 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
V_38 -> V_133 -> V_201 ( V_38 ) ;
F_103 ( & V_37 -> V_106 ) ;
F_106 ( V_37 -> V_47 -> V_48 ) ;
V_38 -> V_133 -> V_199 ( V_38 ) ;
return 0 ;
}
static int F_107 ( struct V_107 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_204 ;
V_204 = F_61 ( V_38 -> V_39 ) ;
if ( V_204 )
return V_204 ;
F_94 ( V_38 ) ;
F_16 ( V_37 -> V_47 -> V_48 , true ) ;
return 0 ;
}
static int T_9 F_108 ( void )
{
int error ;
V_120 = F_109 ( L_7 , 0 , 0 ) ;
if ( ! V_120 )
return - V_69 ;
V_184 = F_110 ( 0 , L_8 ) ;
if ( V_184 < 0 ) {
error = V_184 ;
goto V_205;
}
error = F_111 ( & V_36 ) ;
if ( error )
goto V_206;
return 0 ;
V_206:
F_112 ( V_184 , L_8 ) ;
V_205:
F_113 ( V_120 ) ;
return error ;
}
static void T_10 F_114 ( void )
{
F_112 ( V_184 , L_8 ) ;
F_115 ( & V_36 ) ;
F_113 ( V_120 ) ;
}
