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
static int F_2 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_10 * V_11 , bool V_12 )
{
struct V_10 V_13 , V_3 , V_14 , V_15 , V_16 , * V_17 [ 6 ] ;
unsigned int V_18 = 0 , V_19 = 0 ;
F_3 ( & V_13 , & V_2 -> V_20 , sizeof( V_2 -> V_20 ) ) ;
V_17 [ V_18 ++ ] = & V_13 ;
F_3 ( & V_14 , V_2 -> V_21 . V_14 , V_2 -> V_21 . V_22 ) ;
V_17 [ V_18 ++ ] = & V_14 ;
if ( V_12 ) {
if ( V_2 -> V_20 . type & F_4 ( V_9 -> V_23 , V_24 ) )
V_17 [ V_18 ++ ] = V_11 ;
else
V_17 [ V_18 + V_19 ++ ] = V_11 ;
}
F_3 ( & V_15 , V_2 -> V_15 , V_25 ) ;
V_17 [ V_18 + V_19 ++ ] = & V_15 ;
F_3 ( & V_16 , & V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_16 ;
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_3 ;
return F_5 ( V_9 , V_17 , V_18 , V_19 , V_2 , V_27 ) ;
}
static inline void F_6 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_7 ( V_29 ) ;
struct V_30 * V_31 = V_29 -> V_32 -> V_33 ;
struct V_34 * V_21 = & V_2 -> V_21 ;
V_21 -> V_35 = F_8 ( V_31 -> V_23 , V_2 -> V_26 . V_36 ) ;
V_21 -> V_37 = F_8 ( V_31 -> V_23 , V_2 -> V_26 . V_37 ) ;
V_29 -> V_38 = F_8 ( V_31 -> V_23 , V_2 -> V_26 . V_38 ) ;
}
static int F_9 ( struct V_39 * V_40 , T_1 V_41 ,
unsigned int V_14 , unsigned long V_42 )
{
struct V_43 * V_44 = V_40 -> V_45 ;
struct V_30 * V_31 = V_44 -> V_46 ;
if ( ! F_10 ( V_31 -> V_23 , V_47 ) )
return - V_6 ;
return F_11 ( V_40 , V_41 , V_14 ,
( void V_48 * ) V_42 ) ;
}
static inline int F_2 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_10 * V_11 ,
bool V_12 )
{
return - V_7 ;
}
static inline void F_6 ( struct V_28 * V_29 )
{
}
static int F_12 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_10 * V_11 , bool V_12 )
{
struct V_10 V_13 , V_3 , * V_17 [ 3 ] ;
unsigned int V_18 = 0 , V_19 = 0 ;
F_3 ( & V_13 , & V_2 -> V_20 , sizeof( V_2 -> V_20 ) ) ;
V_17 [ V_18 ++ ] = & V_13 ;
if ( V_12 ) {
if ( V_2 -> V_20 . type & F_4 ( V_9 -> V_23 , V_24 ) )
V_17 [ V_18 ++ ] = V_11 ;
else
V_17 [ V_18 + V_19 ++ ] = V_11 ;
}
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_17 [ V_18 + V_19 ++ ] = & V_3 ;
return F_5 ( V_9 , V_17 , V_18 , V_19 , V_2 , V_27 ) ;
}
static inline void F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_7 ( V_29 ) ;
int error = F_1 ( V_2 ) ;
switch ( F_14 ( V_29 ) ) {
case V_49 :
case V_50 :
F_6 ( V_29 ) ;
break;
case V_51 :
V_29 -> V_38 = ( error != 0 ) ;
break;
}
F_15 ( V_29 , error ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_30 * V_31 = V_9 -> V_23 -> V_52 ;
bool V_53 = false ;
int V_54 = V_9 -> V_55 ;
struct V_1 * V_2 ;
unsigned long V_56 ;
unsigned int V_57 ;
F_17 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
do {
F_18 ( V_9 ) ;
while ( ( V_2 = F_19 ( V_31 -> V_58 [ V_54 ] . V_9 , & V_57 ) ) != NULL ) {
struct V_28 * V_29 = F_20 ( V_2 ) ;
F_21 ( V_29 , V_29 -> V_38 ) ;
V_53 = true ;
}
if ( F_22 ( F_23 ( V_9 ) ) )
break;
} while ( ! F_24 ( V_9 ) );
if ( V_53 )
F_25 ( V_31 -> V_44 -> V_60 , true ) ;
F_26 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
}
static int F_27 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_30 * V_31 = V_62 -> V_60 -> V_33 ;
struct V_28 * V_29 = V_64 -> V_65 ;
struct V_1 * V_2 = F_7 ( V_29 ) ;
unsigned long V_56 ;
unsigned int V_66 ;
int V_54 = V_62 -> V_67 ;
int V_68 ;
bool V_69 = false ;
T_2 type ;
F_28 ( V_29 -> V_70 + 2 > V_31 -> V_71 ) ;
switch ( F_14 ( V_29 ) ) {
case V_72 :
case V_73 :
type = 0 ;
break;
case V_74 :
type = V_75 ;
break;
case V_49 :
case V_50 :
type = V_76 ;
break;
case V_51 :
type = V_77 ;
break;
default:
F_29 ( 1 ) ;
return V_78 ;
}
V_2 -> V_20 . type = F_4 ( V_31 -> V_23 , type ) ;
V_2 -> V_20 . V_79 = type ?
0 : F_30 ( V_31 -> V_23 , F_31 ( V_29 ) ) ;
V_2 -> V_20 . V_80 = F_4 ( V_31 -> V_23 , F_32 ( V_29 ) ) ;
F_33 ( V_29 ) ;
V_66 = F_34 ( V_62 -> V_60 , V_29 , V_2 -> V_81 ) ;
if ( V_66 ) {
if ( F_35 ( V_29 ) == V_82 )
V_2 -> V_20 . type |= F_4 ( V_31 -> V_23 , V_24 ) ;
else
V_2 -> V_20 . type |= F_4 ( V_31 -> V_23 , V_83 ) ;
}
F_17 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( F_14 ( V_29 ) == V_49 || F_14 ( V_29 ) == V_50 )
V_68 = F_2 ( V_31 -> V_58 [ V_54 ] . V_9 , V_2 , V_2 -> V_81 , V_66 ) ;
else
V_68 = F_12 ( V_31 -> V_58 [ V_54 ] . V_9 , V_2 , V_2 -> V_81 , V_66 ) ;
if ( V_68 ) {
F_36 ( V_31 -> V_58 [ V_54 ] . V_9 ) ;
F_37 ( V_62 ) ;
F_26 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( V_68 == - V_84 || V_68 == - V_85 )
return V_86 ;
return V_78 ;
}
if ( V_64 -> V_87 && F_38 ( V_31 -> V_58 [ V_54 ] . V_9 ) )
V_69 = true ;
F_26 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( V_69 )
F_39 ( V_31 -> V_58 [ V_54 ] . V_9 ) ;
return V_88 ;
}
static int F_40 ( struct V_43 * V_44 , char * V_89 )
{
struct V_30 * V_31 = V_44 -> V_46 ;
struct V_90 * V_32 = V_31 -> V_44 -> V_60 ;
struct V_28 * V_29 ;
int V_68 ;
V_29 = F_41 ( V_32 , V_51 , V_91 ) ;
if ( F_42 ( V_29 ) )
return F_43 ( V_29 ) ;
V_68 = F_44 ( V_32 , V_29 , V_89 , V_92 , V_91 ) ;
if ( V_68 )
goto V_93;
V_68 = F_45 ( V_31 -> V_44 -> V_60 , V_31 -> V_44 , V_29 , false ) ;
V_93:
F_46 ( V_29 ) ;
return V_68 ;
}
static int F_47 ( struct V_39 * V_64 , struct V_94 * V_95 )
{
struct V_30 * V_31 = V_64 -> V_45 -> V_46 ;
if ( F_10 ( V_31 -> V_23 , V_96 ) ) {
F_48 ( V_31 -> V_23 , struct V_97 ,
V_98 . V_99 , & V_95 -> V_99 ) ;
F_48 ( V_31 -> V_23 , struct V_97 ,
V_98 . V_100 , & V_95 -> V_100 ) ;
F_48 ( V_31 -> V_23 , struct V_97 ,
V_98 . V_101 , & V_95 -> V_101 ) ;
} else {
V_95 -> V_100 = 1 << 6 ;
V_95 -> V_101 = 1 << 5 ;
V_95 -> V_99 = F_49 ( V_64 -> V_45 ) >> 11 ;
}
return 0 ;
}
static int F_50 ( int V_55 )
{
return V_55 << V_102 ;
}
static int F_51 ( int V_103 )
{
return V_103 >> V_102 ;
}
static T_3 F_52 ( struct V_104 * V_105 ,
struct V_106 * V_107 , char * V_108 )
{
struct V_43 * V_44 = F_53 ( V_105 ) ;
int V_68 ;
F_54 ( V_109 < V_92 ) ;
V_108 [ V_92 ] = '\0' ;
V_68 = F_40 ( V_44 , V_108 ) ;
if ( ! V_68 )
return strlen ( V_108 ) ;
if ( V_68 == - V_7 )
return 0 ;
return V_68 ;
}
static void F_55 ( struct V_110 * V_111 )
{
struct V_30 * V_31 =
F_56 ( V_111 , struct V_30 , V_112 ) ;
struct V_113 * V_23 = V_31 -> V_23 ;
struct V_90 * V_32 = V_31 -> V_44 -> V_60 ;
char V_114 [ 10 ] , V_115 [ 10 ] ;
char * V_116 [] = { L_1 , NULL } ;
T_4 V_117 ;
F_48 ( V_23 , struct V_97 , V_117 , & V_117 ) ;
if ( ( V_118 ) V_117 != V_117 ) {
F_57 ( & V_23 -> V_105 , L_2 ,
( unsigned long long ) V_117 ) ;
V_117 = ( V_118 ) - 1 ;
}
F_58 ( V_117 , F_59 ( V_32 ) ,
V_119 , V_114 , sizeof( V_114 ) ) ;
F_58 ( V_117 , F_59 ( V_32 ) ,
V_120 , V_115 , sizeof( V_115 ) ) ;
F_60 ( & V_23 -> V_105 ,
L_3 ,
( unsigned long long ) V_117 ,
F_59 ( V_32 ) ,
V_115 , V_114 ) ;
F_61 ( V_31 -> V_44 , V_117 ) ;
F_62 ( V_31 -> V_44 ) ;
F_63 ( & F_64 ( V_31 -> V_44 ) -> V_121 , V_122 , V_116 ) ;
}
static void F_65 ( struct V_113 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
F_66 ( V_123 , & V_31 -> V_112 ) ;
}
static int F_67 ( struct V_30 * V_31 )
{
int V_68 ;
int V_124 ;
T_5 * * V_125 ;
const char * * V_126 ;
struct V_8 * * V_58 ;
unsigned short V_127 ;
struct V_113 * V_23 = V_31 -> V_23 ;
struct V_128 V_129 = { 0 , } ;
V_68 = F_68 ( V_23 , V_130 ,
struct V_97 , V_131 ,
& V_127 ) ;
if ( V_68 )
V_127 = 1 ;
V_31 -> V_58 = F_69 ( V_127 , sizeof( * V_31 -> V_58 ) , V_91 ) ;
if ( ! V_31 -> V_58 )
return - V_84 ;
V_126 = F_69 ( V_127 , sizeof( * V_126 ) , V_91 ) ;
V_125 = F_69 ( V_127 , sizeof( * V_125 ) , V_91 ) ;
V_58 = F_69 ( V_127 , sizeof( * V_58 ) , V_91 ) ;
if ( ! V_126 || ! V_125 || ! V_58 ) {
V_68 = - V_84 ;
goto V_93;
}
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
V_125 [ V_124 ] = F_16 ;
snprintf ( V_31 -> V_58 [ V_124 ] . V_132 , V_133 , L_4 , V_124 ) ;
V_126 [ V_124 ] = V_31 -> V_58 [ V_124 ] . V_132 ;
}
V_68 = V_23 -> V_134 -> V_135 ( V_23 , V_127 , V_58 , V_125 , V_126 ,
& V_129 ) ;
if ( V_68 )
goto V_93;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
F_70 ( & V_31 -> V_58 [ V_124 ] . V_59 ) ;
V_31 -> V_58 [ V_124 ] . V_9 = V_58 [ V_124 ] ;
}
V_31 -> V_127 = V_127 ;
V_93:
F_71 ( V_58 ) ;
F_71 ( V_125 ) ;
F_71 ( V_126 ) ;
if ( V_68 )
F_71 ( V_31 -> V_58 ) ;
return V_68 ;
}
static int F_72 ( char * V_136 , int V_55 , char * V_108 , int V_137 )
{
const int V_138 = 'z' - 'a' + 1 ;
char * V_139 = V_108 + strlen ( V_136 ) ;
char * V_140 = V_108 + V_137 ;
char * V_141 ;
int V_142 ;
V_141 = V_140 - 1 ;
* V_141 = '\0' ;
V_142 = V_138 ;
do {
if ( V_141 == V_139 )
return - V_143 ;
* -- V_141 = 'a' + ( V_55 % V_142 ) ;
V_55 = ( V_55 / V_142 ) - 1 ;
} while ( V_55 >= 0 );
memmove ( V_139 , V_141 , V_140 - V_141 ) ;
memcpy ( V_108 , V_136 , strlen ( V_136 ) ) ;
return 0 ;
}
static int F_73 ( struct V_113 * V_23 )
{
T_6 V_144 ;
int V_68 ;
V_68 = F_68 ( V_23 , V_145 ,
struct V_97 , V_146 ,
& V_144 ) ;
if ( V_68 )
V_144 = F_10 ( V_23 , V_147 ) ;
return V_144 ;
}
static void F_74 ( struct V_113 * V_23 )
{
T_6 V_144 = F_73 ( V_23 ) ;
struct V_30 * V_31 = V_23 -> V_52 ;
F_75 ( V_31 -> V_44 -> V_60 , V_144 , false ) ;
F_62 ( V_31 -> V_44 ) ;
}
static T_3
F_76 ( struct V_104 * V_105 , struct V_106 * V_107 ,
const char * V_108 , T_7 V_148 )
{
struct V_43 * V_44 = F_53 ( V_105 ) ;
struct V_30 * V_31 = V_44 -> V_46 ;
struct V_113 * V_23 = V_31 -> V_23 ;
int V_124 ;
F_28 ( ! F_10 ( V_31 -> V_23 , V_145 ) ) ;
for ( V_124 = F_77 ( V_149 ) ; -- V_124 >= 0 ; )
if ( F_78 ( V_108 , V_149 [ V_124 ] ) )
break;
if ( V_124 < 0 )
return - V_143 ;
F_79 ( V_23 , F_80 ( struct V_97 , V_146 ) , V_124 ) ;
F_74 ( V_23 ) ;
return V_148 ;
}
static T_3
F_81 ( struct V_104 * V_105 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_43 * V_44 = F_53 ( V_105 ) ;
struct V_30 * V_31 = V_44 -> V_46 ;
T_6 V_144 = F_73 ( V_31 -> V_23 ) ;
F_28 ( V_144 >= F_77 ( V_149 ) ) ;
return snprintf ( V_108 , 40 , L_5 , V_149 [ V_144 ] ) ;
}
static int F_82 ( void * V_42 , struct V_28 * V_65 ,
unsigned int V_150 , unsigned int V_151 ,
unsigned int V_152 )
{
struct V_30 * V_31 = V_42 ;
struct V_1 * V_2 = F_7 ( V_65 ) ;
#ifdef F_83
V_2 -> V_21 . V_15 = V_2 -> V_15 ;
#endif
F_84 ( V_2 -> V_81 , V_31 -> V_71 ) ;
return 0 ;
}
static int F_85 ( struct V_153 * V_154 )
{
struct V_30 * V_31 = V_154 -> V_155 ;
return F_86 ( V_154 , V_31 -> V_23 , 0 ) ;
}
static int F_87 ( struct V_113 * V_23 )
{
struct V_30 * V_31 ;
struct V_90 * V_32 ;
int V_68 , V_55 ;
T_4 V_156 ;
T_2 V_157 , V_158 , V_71 , V_159 ;
T_8 V_160 ;
T_6 V_161 , V_162 ;
if ( ! V_23 -> V_134 -> V_163 ) {
F_88 ( & V_23 -> V_105 , L_6 ,
V_164 ) ;
return - V_143 ;
}
V_68 = F_89 ( & V_165 , 0 , F_51 ( 1 << V_166 ) ,
V_91 ) ;
if ( V_68 < 0 )
goto V_93;
V_55 = V_68 ;
V_68 = F_68 ( V_23 , V_167 ,
struct V_97 , V_168 ,
& V_71 ) ;
if ( V_68 || ! V_71 )
V_71 = 1 ;
V_71 += 2 ;
V_23 -> V_52 = V_31 = F_90 ( sizeof( * V_31 ) , V_91 ) ;
if ( ! V_31 ) {
V_68 = - V_84 ;
goto V_169;
}
V_31 -> V_23 = V_23 ;
V_31 -> V_71 = V_71 ;
F_91 ( & V_31 -> V_112 , F_55 ) ;
V_68 = F_67 ( V_31 ) ;
if ( V_68 )
goto V_170;
V_31 -> V_44 = F_92 ( 1 << V_102 ) ;
if ( ! V_31 -> V_44 ) {
V_68 = - V_84 ;
goto V_171;
}
if ( ! V_172 ) {
V_172 = V_31 -> V_58 [ 0 ] . V_9 -> V_173 ;
if ( ! F_10 ( V_23 , V_174 ) )
V_172 /= 2 ;
}
memset ( & V_31 -> V_175 , 0 , sizeof( V_31 -> V_175 ) ) ;
V_31 -> V_175 . V_176 = & V_177 ;
V_31 -> V_175 . V_178 = V_172 ;
V_31 -> V_175 . V_152 = V_179 ;
V_31 -> V_175 . V_56 = V_180 ;
V_31 -> V_175 . V_181 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_71 ;
V_31 -> V_175 . V_155 = V_31 ;
V_31 -> V_175 . V_182 = V_31 -> V_127 ;
V_68 = F_93 ( & V_31 -> V_175 ) ;
if ( V_68 )
goto V_183;
V_32 = F_94 ( & V_31 -> V_175 ) ;
if ( F_42 ( V_32 ) ) {
V_68 = - V_84 ;
goto V_184;
}
V_31 -> V_44 -> V_60 = V_32 ;
V_32 -> V_33 = V_31 ;
F_72 ( L_7 , V_55 , V_31 -> V_44 -> V_185 , V_186 ) ;
V_31 -> V_44 -> V_187 = V_187 ;
V_31 -> V_44 -> V_188 = F_50 ( V_55 ) ;
V_31 -> V_44 -> V_46 = V_31 ;
V_31 -> V_44 -> V_189 = & V_190 ;
V_31 -> V_44 -> V_56 |= V_191 ;
V_31 -> V_55 = V_55 ;
F_74 ( V_23 ) ;
if ( F_10 ( V_23 , V_192 ) )
F_95 ( V_31 -> V_44 , 1 ) ;
F_48 ( V_23 , struct V_97 , V_117 , & V_156 ) ;
if ( ( V_118 ) V_156 != V_156 ) {
F_57 ( & V_23 -> V_105 , L_2 ,
( unsigned long long ) V_156 ) ;
V_156 = ( V_118 ) - 1 ;
}
F_61 ( V_31 -> V_44 , V_156 ) ;
F_96 ( V_32 , V_31 -> V_71 - 2 ) ;
F_97 ( V_32 , V_193 ) ;
F_98 ( V_32 , - 1U ) ;
V_68 = F_68 ( V_23 , V_194 ,
struct V_97 , V_195 , & V_157 ) ;
if ( ! V_68 )
F_99 ( V_32 , V_157 ) ;
else
F_99 ( V_32 , - 1U ) ;
V_68 = F_68 ( V_23 , V_196 ,
struct V_97 , V_158 ,
& V_158 ) ;
if ( ! V_68 )
F_100 ( V_32 , V_158 ) ;
else
V_158 = F_59 ( V_32 ) ;
V_68 = F_68 ( V_23 , V_197 ,
struct V_97 , V_161 ,
& V_161 ) ;
if ( ! V_68 && V_161 )
F_101 ( V_32 ,
V_158 * ( 1 << V_161 ) ) ;
V_68 = F_68 ( V_23 , V_197 ,
struct V_97 , V_162 ,
& V_162 ) ;
if ( ! V_68 && V_162 )
F_102 ( V_32 , V_158 * V_162 ) ;
V_68 = F_68 ( V_23 , V_197 ,
struct V_97 , V_160 ,
& V_160 ) ;
if ( ! V_68 && V_160 )
F_103 ( V_32 , V_158 * V_160 ) ;
V_68 = F_68 ( V_23 , V_197 ,
struct V_97 , V_159 ,
& V_159 ) ;
if ( ! V_68 && V_159 )
F_104 ( V_32 , V_158 * V_159 ) ;
F_105 ( V_23 ) ;
F_106 ( & V_23 -> V_105 , V_31 -> V_44 ) ;
V_68 = F_107 ( F_64 ( V_31 -> V_44 ) , & V_198 ) ;
if ( V_68 )
goto V_199;
if ( F_10 ( V_23 , V_145 ) )
V_68 = F_107 ( F_64 ( V_31 -> V_44 ) ,
& V_200 ) ;
else
V_68 = F_107 ( F_64 ( V_31 -> V_44 ) ,
& V_201 ) ;
if ( V_68 )
goto V_199;
return 0 ;
V_199:
F_108 ( V_31 -> V_44 ) ;
F_109 ( V_31 -> V_44 -> V_60 ) ;
V_184:
F_110 ( & V_31 -> V_175 ) ;
V_183:
F_111 ( V_31 -> V_44 ) ;
V_171:
V_23 -> V_134 -> V_202 ( V_23 ) ;
V_170:
F_71 ( V_31 ) ;
V_169:
F_112 ( & V_165 , V_55 ) ;
V_93:
return V_68 ;
}
static void F_113 ( struct V_113 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
int V_55 = V_31 -> V_55 ;
int V_203 ;
F_114 ( & V_31 -> V_112 ) ;
F_108 ( V_31 -> V_44 ) ;
F_109 ( V_31 -> V_44 -> V_60 ) ;
F_110 ( & V_31 -> V_175 ) ;
V_23 -> V_134 -> V_204 ( V_23 ) ;
V_203 = F_115 ( & F_64 ( V_31 -> V_44 ) -> V_121 . V_205 ) ;
F_111 ( V_31 -> V_44 ) ;
V_23 -> V_134 -> V_202 ( V_23 ) ;
F_71 ( V_31 -> V_58 ) ;
F_71 ( V_31 ) ;
if ( V_203 == 1 )
F_112 ( & V_165 , V_55 ) ;
}
static int F_116 ( struct V_113 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
V_23 -> V_134 -> V_204 ( V_23 ) ;
F_114 ( & V_31 -> V_112 ) ;
F_117 ( V_31 -> V_44 -> V_60 ) ;
V_23 -> V_134 -> V_202 ( V_23 ) ;
return 0 ;
}
static int F_118 ( struct V_113 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
int V_206 ;
V_206 = F_67 ( V_23 -> V_52 ) ;
if ( V_206 )
return V_206 ;
F_105 ( V_23 ) ;
F_25 ( V_31 -> V_44 -> V_60 , true ) ;
return 0 ;
}
static int T_9 F_119 ( void )
{
int error ;
V_123 = F_120 ( L_8 , 0 , 0 ) ;
if ( ! V_123 )
return - V_84 ;
V_187 = F_121 ( 0 , L_9 ) ;
if ( V_187 < 0 ) {
error = V_187 ;
goto V_207;
}
error = F_122 ( & V_30 ) ;
if ( error )
goto V_208;
return 0 ;
V_208:
F_123 ( V_187 , L_9 ) ;
V_207:
F_124 ( V_123 ) ;
return error ;
}
static void T_10 F_125 ( void )
{
F_126 ( & V_30 ) ;
F_123 ( V_187 , L_9 ) ;
F_124 ( V_123 ) ;
}
