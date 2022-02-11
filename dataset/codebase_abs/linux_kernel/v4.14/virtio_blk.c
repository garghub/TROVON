static inline T_1 F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
default:
return V_8 ;
}
}
static int F_2 ( struct V_9 * V_10 , struct V_1 * V_2 ,
struct V_11 * V_12 , bool V_13 )
{
struct V_11 V_14 , V_3 , V_15 , V_16 , V_17 , * V_18 [ 6 ] ;
unsigned int V_19 = 0 , V_20 = 0 ;
F_3 ( & V_14 , & V_2 -> V_21 , sizeof( V_2 -> V_21 ) ) ;
V_18 [ V_19 ++ ] = & V_14 ;
F_3 ( & V_15 , V_2 -> V_22 . V_15 , V_2 -> V_22 . V_23 ) ;
V_18 [ V_19 ++ ] = & V_15 ;
if ( V_13 ) {
if ( V_2 -> V_21 . type & F_4 ( V_10 -> V_24 , V_25 ) )
V_18 [ V_19 ++ ] = V_12 ;
else
V_18 [ V_19 + V_20 ++ ] = V_12 ;
}
F_3 ( & V_16 , V_2 -> V_16 , V_26 ) ;
V_18 [ V_19 + V_20 ++ ] = & V_16 ;
F_3 ( & V_17 , & V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) ;
V_18 [ V_19 + V_20 ++ ] = & V_17 ;
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_18 [ V_19 + V_20 ++ ] = & V_3 ;
return F_5 ( V_10 , V_18 , V_19 , V_20 , V_2 , V_28 ) ;
}
static inline void F_6 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_35 * V_22 = & V_2 -> V_22 ;
V_22 -> V_36 = F_8 ( V_32 -> V_24 , V_2 -> V_27 . V_37 ) ;
V_22 -> V_38 = F_8 ( V_32 -> V_24 , V_2 -> V_27 . V_38 ) ;
V_22 -> V_39 = F_8 ( V_32 -> V_24 , V_2 -> V_27 . V_40 ) ;
}
static int F_9 ( struct V_41 * V_42 , T_2 V_43 ,
unsigned int V_15 , unsigned long V_44 )
{
struct V_45 * V_46 = V_42 -> V_47 ;
struct V_31 * V_32 = V_46 -> V_48 ;
if ( ! F_10 ( V_32 -> V_24 , V_49 ) )
return - V_50 ;
return F_11 ( V_42 , V_43 , V_15 ,
( void V_51 * ) V_44 ) ;
}
static inline int F_2 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_11 * V_12 ,
bool V_13 )
{
return - V_52 ;
}
static inline void F_6 ( struct V_29 * V_30 )
{
}
static int F_12 ( struct V_9 * V_10 , struct V_1 * V_2 ,
struct V_11 * V_12 , bool V_13 )
{
struct V_11 V_14 , V_3 , * V_18 [ 3 ] ;
unsigned int V_19 = 0 , V_20 = 0 ;
F_3 ( & V_14 , & V_2 -> V_21 , sizeof( V_2 -> V_21 ) ) ;
V_18 [ V_19 ++ ] = & V_14 ;
if ( V_13 ) {
if ( V_2 -> V_21 . type & F_4 ( V_10 -> V_24 , V_25 ) )
V_18 [ V_19 ++ ] = V_12 ;
else
V_18 [ V_19 + V_20 ++ ] = V_12 ;
}
F_3 ( & V_3 , & V_2 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
V_18 [ V_19 + V_20 ++ ] = & V_3 ;
return F_5 ( V_10 , V_18 , V_19 , V_20 , V_2 , V_28 ) ;
}
static inline void F_13 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
switch ( F_14 ( V_30 ) ) {
case V_53 :
case V_54 :
F_6 ( V_30 ) ;
break;
}
F_15 ( V_30 , F_1 ( V_2 ) ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_24 -> V_55 ;
bool V_56 = false ;
int V_57 = V_10 -> V_58 ;
struct V_1 * V_2 ;
unsigned long V_59 ;
unsigned int V_60 ;
F_17 ( & V_32 -> V_61 [ V_57 ] . V_62 , V_59 ) ;
do {
F_18 ( V_10 ) ;
while ( ( V_2 = F_19 ( V_32 -> V_61 [ V_57 ] . V_10 , & V_60 ) ) != NULL ) {
struct V_29 * V_30 = F_20 ( V_2 ) ;
F_21 ( V_30 ) ;
V_56 = true ;
}
if ( F_22 ( F_23 ( V_10 ) ) )
break;
} while ( ! F_24 ( V_10 ) );
if ( V_56 )
F_25 ( V_32 -> V_46 -> V_63 , true ) ;
F_26 ( & V_32 -> V_61 [ V_57 ] . V_62 , V_59 ) ;
}
static T_1 F_27 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_31 * V_32 = V_65 -> V_63 -> V_34 ;
struct V_29 * V_30 = V_67 -> V_68 ;
struct V_1 * V_2 = F_7 ( V_30 ) ;
unsigned long V_59 ;
unsigned int V_69 ;
int V_57 = V_65 -> V_70 ;
int V_71 ;
bool V_72 = false ;
T_3 type ;
F_28 ( V_30 -> V_73 + 2 > V_32 -> V_74 ) ;
switch ( F_14 ( V_30 ) ) {
case V_75 :
case V_76 :
type = 0 ;
break;
case V_77 :
type = V_78 ;
break;
case V_53 :
case V_54 :
type = V_79 ;
break;
case V_80 :
type = V_81 ;
break;
default:
F_29 ( 1 ) ;
return V_8 ;
}
V_2 -> V_21 . type = F_4 ( V_32 -> V_24 , type ) ;
V_2 -> V_21 . V_82 = type ?
0 : F_30 ( V_32 -> V_24 , F_31 ( V_30 ) ) ;
V_2 -> V_21 . V_83 = F_4 ( V_32 -> V_24 , F_32 ( V_30 ) ) ;
F_33 ( V_30 ) ;
V_69 = F_34 ( V_65 -> V_63 , V_30 , V_2 -> V_84 ) ;
if ( V_69 ) {
if ( F_35 ( V_30 ) == V_85 )
V_2 -> V_21 . type |= F_4 ( V_32 -> V_24 , V_25 ) ;
else
V_2 -> V_21 . type |= F_4 ( V_32 -> V_24 , V_86 ) ;
}
F_17 ( & V_32 -> V_61 [ V_57 ] . V_62 , V_59 ) ;
if ( F_36 ( V_30 ) )
V_71 = F_2 ( V_32 -> V_61 [ V_57 ] . V_10 , V_2 , V_2 -> V_84 , V_69 ) ;
else
V_71 = F_12 ( V_32 -> V_61 [ V_57 ] . V_10 , V_2 , V_2 -> V_84 , V_69 ) ;
if ( V_71 ) {
F_37 ( V_32 -> V_61 [ V_57 ] . V_10 ) ;
F_38 ( V_65 ) ;
F_26 ( & V_32 -> V_61 [ V_57 ] . V_62 , V_59 ) ;
if ( V_71 == - V_87 || V_71 == - V_88 )
return V_89 ;
return V_8 ;
}
if ( V_67 -> V_90 && F_39 ( V_32 -> V_61 [ V_57 ] . V_10 ) )
V_72 = true ;
F_26 ( & V_32 -> V_61 [ V_57 ] . V_62 , V_59 ) ;
if ( V_72 )
F_40 ( V_32 -> V_61 [ V_57 ] . V_10 ) ;
return V_5 ;
}
static int F_41 ( struct V_45 * V_46 , char * V_91 )
{
struct V_31 * V_32 = V_46 -> V_48 ;
struct V_92 * V_33 = V_32 -> V_46 -> V_63 ;
struct V_29 * V_30 ;
int V_71 ;
V_30 = F_42 ( V_33 , V_80 , V_93 ) ;
if ( F_43 ( V_30 ) )
return F_44 ( V_30 ) ;
V_71 = F_45 ( V_33 , V_30 , V_91 , V_94 , V_93 ) ;
if ( V_71 )
goto V_95;
F_46 ( V_32 -> V_46 -> V_63 , V_32 -> V_46 , V_30 , false ) ;
V_71 = F_47 ( F_1 ( F_7 ( V_30 ) ) ) ;
V_95:
F_48 ( V_30 ) ;
return V_71 ;
}
static int F_49 ( struct V_41 * V_67 , struct V_96 * V_97 )
{
struct V_31 * V_32 = V_67 -> V_47 -> V_48 ;
if ( F_10 ( V_32 -> V_24 , V_98 ) ) {
F_50 ( V_32 -> V_24 , struct V_99 ,
V_100 . V_101 , & V_97 -> V_101 ) ;
F_50 ( V_32 -> V_24 , struct V_99 ,
V_100 . V_102 , & V_97 -> V_102 ) ;
F_50 ( V_32 -> V_24 , struct V_99 ,
V_100 . V_103 , & V_97 -> V_103 ) ;
} else {
V_97 -> V_102 = 1 << 6 ;
V_97 -> V_103 = 1 << 5 ;
V_97 -> V_101 = F_51 ( V_67 -> V_47 ) >> 11 ;
}
return 0 ;
}
static int F_52 ( int V_58 )
{
return V_58 << V_104 ;
}
static int F_53 ( int V_105 )
{
return V_105 >> V_104 ;
}
static T_4 F_54 ( struct V_106 * V_107 ,
struct V_108 * V_109 , char * V_110 )
{
struct V_45 * V_46 = F_55 ( V_107 ) ;
int V_71 ;
F_56 ( V_111 < V_94 ) ;
V_110 [ V_94 ] = '\0' ;
V_71 = F_41 ( V_46 , V_110 ) ;
if ( ! V_71 )
return strlen ( V_110 ) ;
if ( V_71 == - V_52 )
return 0 ;
return V_71 ;
}
static void F_57 ( struct V_112 * V_113 )
{
struct V_31 * V_32 =
F_58 ( V_113 , struct V_31 , V_114 ) ;
struct V_115 * V_24 = V_32 -> V_24 ;
struct V_92 * V_33 = V_32 -> V_46 -> V_63 ;
char V_116 [ 10 ] , V_117 [ 10 ] ;
char * V_118 [] = { L_1 , NULL } ;
unsigned long long V_119 ;
T_5 V_120 ;
F_50 ( V_24 , struct V_99 , V_120 , & V_120 ) ;
if ( ( V_121 ) V_120 != V_120 ) {
F_59 ( & V_24 -> V_107 , L_2 ,
( unsigned long long ) V_120 ) ;
V_120 = ( V_121 ) - 1 ;
}
V_119 = F_60 ( V_120 , F_61 ( V_33 ) >> 9 ) ;
F_62 ( V_119 , F_61 ( V_33 ) ,
V_122 , V_116 , sizeof( V_116 ) ) ;
F_62 ( V_119 , F_61 ( V_33 ) ,
V_123 , V_117 , sizeof( V_117 ) ) ;
F_63 ( & V_24 -> V_107 ,
L_3 ,
V_119 ,
F_61 ( V_33 ) ,
V_117 ,
V_116 ) ;
F_64 ( V_32 -> V_46 , V_120 ) ;
F_65 ( V_32 -> V_46 ) ;
F_66 ( & F_67 ( V_32 -> V_46 ) -> V_124 , V_125 , V_118 ) ;
}
static void F_68 ( struct V_115 * V_24 )
{
struct V_31 * V_32 = V_24 -> V_55 ;
F_69 ( V_126 , & V_32 -> V_114 ) ;
}
static int F_70 ( struct V_31 * V_32 )
{
int V_71 ;
int V_127 ;
T_6 * * V_128 ;
const char * * V_129 ;
struct V_9 * * V_61 ;
unsigned short V_130 ;
struct V_115 * V_24 = V_32 -> V_24 ;
struct V_131 V_132 = { 0 , } ;
V_71 = F_71 ( V_24 , V_133 ,
struct V_99 , V_134 ,
& V_130 ) ;
if ( V_71 )
V_130 = 1 ;
V_32 -> V_61 = F_72 ( V_130 , sizeof( * V_32 -> V_61 ) , V_93 ) ;
if ( ! V_32 -> V_61 )
return - V_87 ;
V_129 = F_72 ( V_130 , sizeof( * V_129 ) , V_93 ) ;
V_128 = F_72 ( V_130 , sizeof( * V_128 ) , V_93 ) ;
V_61 = F_72 ( V_130 , sizeof( * V_61 ) , V_93 ) ;
if ( ! V_129 || ! V_128 || ! V_61 ) {
V_71 = - V_87 ;
goto V_95;
}
for ( V_127 = 0 ; V_127 < V_130 ; V_127 ++ ) {
V_128 [ V_127 ] = F_16 ;
snprintf ( V_32 -> V_61 [ V_127 ] . V_135 , V_136 , L_4 , V_127 ) ;
V_129 [ V_127 ] = V_32 -> V_61 [ V_127 ] . V_135 ;
}
V_71 = F_73 ( V_24 , V_130 , V_61 , V_128 , V_129 , & V_132 ) ;
if ( V_71 )
goto V_95;
for ( V_127 = 0 ; V_127 < V_130 ; V_127 ++ ) {
F_74 ( & V_32 -> V_61 [ V_127 ] . V_62 ) ;
V_32 -> V_61 [ V_127 ] . V_10 = V_61 [ V_127 ] ;
}
V_32 -> V_130 = V_130 ;
V_95:
F_75 ( V_61 ) ;
F_75 ( V_128 ) ;
F_75 ( V_129 ) ;
if ( V_71 )
F_75 ( V_32 -> V_61 ) ;
return V_71 ;
}
static int F_76 ( char * V_137 , int V_58 , char * V_110 , int V_138 )
{
const int V_139 = 'z' - 'a' + 1 ;
char * V_140 = V_110 + strlen ( V_137 ) ;
char * V_141 = V_110 + V_138 ;
char * V_142 ;
int V_143 ;
V_142 = V_141 - 1 ;
* V_142 = '\0' ;
V_143 = V_139 ;
do {
if ( V_142 == V_140 )
return - V_144 ;
* -- V_142 = 'a' + ( V_58 % V_143 ) ;
V_58 = ( V_58 / V_143 ) - 1 ;
} while ( V_58 >= 0 );
memmove ( V_140 , V_142 , V_141 - V_142 ) ;
memcpy ( V_110 , V_137 , strlen ( V_137 ) ) ;
return 0 ;
}
static int F_77 ( struct V_115 * V_24 )
{
T_7 V_145 ;
int V_71 ;
V_71 = F_71 ( V_24 , V_146 ,
struct V_99 , V_147 ,
& V_145 ) ;
if ( V_71 )
V_145 = F_10 ( V_24 , V_148 ) ;
return V_145 ;
}
static void F_78 ( struct V_115 * V_24 )
{
T_7 V_145 = F_77 ( V_24 ) ;
struct V_31 * V_32 = V_24 -> V_55 ;
F_79 ( V_32 -> V_46 -> V_63 , V_145 , false ) ;
F_65 ( V_32 -> V_46 ) ;
}
static T_4
F_80 ( struct V_106 * V_107 , struct V_108 * V_109 ,
const char * V_110 , T_8 V_149 )
{
struct V_45 * V_46 = F_55 ( V_107 ) ;
struct V_31 * V_32 = V_46 -> V_48 ;
struct V_115 * V_24 = V_32 -> V_24 ;
int V_127 ;
F_28 ( ! F_10 ( V_32 -> V_24 , V_146 ) ) ;
V_127 = F_81 ( V_150 , V_110 ) ;
if ( V_127 < 0 )
return V_127 ;
F_82 ( V_24 , F_83 ( struct V_99 , V_147 ) , V_127 ) ;
F_78 ( V_24 ) ;
return V_149 ;
}
static T_4
F_84 ( struct V_106 * V_107 , struct V_108 * V_109 ,
char * V_110 )
{
struct V_45 * V_46 = F_55 ( V_107 ) ;
struct V_31 * V_32 = V_46 -> V_48 ;
T_7 V_145 = F_77 ( V_32 -> V_24 ) ;
F_28 ( V_145 >= F_85 ( V_150 ) ) ;
return snprintf ( V_110 , 40 , L_5 , V_150 [ V_145 ] ) ;
}
static int F_86 ( struct V_151 * V_152 , struct V_29 * V_68 ,
unsigned int V_153 , unsigned int V_154 )
{
struct V_31 * V_32 = V_152 -> V_155 ;
struct V_1 * V_2 = F_7 ( V_68 ) ;
#ifdef F_87
V_2 -> V_22 . V_16 = V_2 -> V_16 ;
#endif
F_88 ( V_2 -> V_84 , V_32 -> V_74 ) ;
return 0 ;
}
static int F_89 ( struct V_151 * V_152 )
{
struct V_31 * V_32 = V_152 -> V_155 ;
return F_90 ( V_152 , V_32 -> V_24 , 0 ) ;
}
static void F_91 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
F_92 ( & V_2 -> V_22 ) ;
}
static int F_93 ( struct V_115 * V_24 )
{
struct V_31 * V_32 ;
struct V_92 * V_33 ;
int V_71 , V_58 ;
T_5 V_156 ;
T_3 V_157 , V_158 , V_74 , V_159 ;
T_9 V_160 ;
T_7 V_161 , V_162 ;
if ( ! V_24 -> V_163 -> V_164 ) {
F_94 ( & V_24 -> V_107 , L_6 ,
V_165 ) ;
return - V_144 ;
}
V_71 = F_95 ( & V_166 , 0 , F_53 ( 1 << V_167 ) ,
V_93 ) ;
if ( V_71 < 0 )
goto V_95;
V_58 = V_71 ;
V_71 = F_71 ( V_24 , V_168 ,
struct V_99 , V_169 ,
& V_74 ) ;
if ( V_71 || ! V_74 )
V_74 = 1 ;
V_74 += 2 ;
V_24 -> V_55 = V_32 = F_96 ( sizeof( * V_32 ) , V_93 ) ;
if ( ! V_32 ) {
V_71 = - V_87 ;
goto V_170;
}
V_32 -> V_24 = V_24 ;
V_32 -> V_74 = V_74 ;
F_97 ( & V_32 -> V_114 , F_57 ) ;
V_71 = F_70 ( V_32 ) ;
if ( V_71 )
goto V_171;
V_32 -> V_46 = F_98 ( 1 << V_104 ) ;
if ( ! V_32 -> V_46 ) {
V_71 = - V_87 ;
goto V_172;
}
if ( ! V_173 ) {
V_173 = V_32 -> V_61 [ 0 ] . V_10 -> V_174 ;
if ( ! F_10 ( V_24 , V_175 ) )
V_173 /= 2 ;
}
memset ( & V_32 -> V_176 , 0 , sizeof( V_32 -> V_176 ) ) ;
V_32 -> V_176 . V_177 = & V_178 ;
V_32 -> V_176 . V_179 = V_173 ;
V_32 -> V_176 . V_154 = V_180 ;
V_32 -> V_176 . V_59 = V_181 ;
V_32 -> V_176 . V_182 =
sizeof( struct V_1 ) +
sizeof( struct V_11 ) * V_74 ;
V_32 -> V_176 . V_155 = V_32 ;
V_32 -> V_176 . V_183 = V_32 -> V_130 ;
V_71 = F_99 ( & V_32 -> V_176 ) ;
if ( V_71 )
goto V_184;
V_33 = F_100 ( & V_32 -> V_176 ) ;
if ( F_43 ( V_33 ) ) {
V_71 = - V_87 ;
goto V_185;
}
V_32 -> V_46 -> V_63 = V_33 ;
V_33 -> V_34 = V_32 ;
F_76 ( L_7 , V_58 , V_32 -> V_46 -> V_186 , V_187 ) ;
V_32 -> V_46 -> V_188 = V_188 ;
V_32 -> V_46 -> V_189 = F_52 ( V_58 ) ;
V_32 -> V_46 -> V_48 = V_32 ;
V_32 -> V_46 -> V_190 = & V_191 ;
V_32 -> V_46 -> V_59 |= V_192 ;
V_32 -> V_58 = V_58 ;
F_78 ( V_24 ) ;
if ( F_10 ( V_24 , V_193 ) )
F_101 ( V_32 -> V_46 , 1 ) ;
F_50 ( V_24 , struct V_99 , V_120 , & V_156 ) ;
if ( ( V_121 ) V_156 != V_156 ) {
F_59 ( & V_24 -> V_107 , L_2 ,
( unsigned long long ) V_156 ) ;
V_156 = ( V_121 ) - 1 ;
}
F_64 ( V_32 -> V_46 , V_156 ) ;
F_102 ( V_33 , V_32 -> V_74 - 2 ) ;
F_103 ( V_33 , - 1U ) ;
V_71 = F_71 ( V_24 , V_194 ,
struct V_99 , V_195 , & V_157 ) ;
if ( ! V_71 )
F_104 ( V_33 , V_157 ) ;
else
F_104 ( V_33 , - 1U ) ;
V_71 = F_71 ( V_24 , V_196 ,
struct V_99 , V_158 ,
& V_158 ) ;
if ( ! V_71 )
F_105 ( V_33 , V_158 ) ;
else
V_158 = F_61 ( V_33 ) ;
V_71 = F_71 ( V_24 , V_197 ,
struct V_99 , V_161 ,
& V_161 ) ;
if ( ! V_71 && V_161 )
F_106 ( V_33 ,
V_158 * ( 1 << V_161 ) ) ;
V_71 = F_71 ( V_24 , V_197 ,
struct V_99 , V_162 ,
& V_162 ) ;
if ( ! V_71 && V_162 )
F_107 ( V_33 , V_158 * V_162 ) ;
V_71 = F_71 ( V_24 , V_197 ,
struct V_99 , V_160 ,
& V_160 ) ;
if ( ! V_71 && V_160 )
F_108 ( V_33 , V_158 * V_160 ) ;
V_71 = F_71 ( V_24 , V_197 ,
struct V_99 , V_159 ,
& V_159 ) ;
if ( ! V_71 && V_159 )
F_109 ( V_33 , V_158 * V_159 ) ;
F_110 ( V_24 ) ;
F_111 ( & V_24 -> V_107 , V_32 -> V_46 ) ;
V_71 = F_112 ( F_67 ( V_32 -> V_46 ) , & V_198 ) ;
if ( V_71 )
goto V_199;
if ( F_10 ( V_24 , V_146 ) )
V_71 = F_112 ( F_67 ( V_32 -> V_46 ) ,
& V_200 ) ;
else
V_71 = F_112 ( F_67 ( V_32 -> V_46 ) ,
& V_201 ) ;
if ( V_71 )
goto V_199;
return 0 ;
V_199:
F_113 ( V_32 -> V_46 ) ;
F_114 ( V_32 -> V_46 -> V_63 ) ;
V_185:
F_115 ( & V_32 -> V_176 ) ;
V_184:
F_116 ( V_32 -> V_46 ) ;
V_172:
V_24 -> V_163 -> V_202 ( V_24 ) ;
V_171:
F_75 ( V_32 ) ;
V_170:
F_117 ( & V_166 , V_58 ) ;
V_95:
return V_71 ;
}
static void F_118 ( struct V_115 * V_24 )
{
struct V_31 * V_32 = V_24 -> V_55 ;
int V_58 = V_32 -> V_58 ;
int V_203 ;
F_119 ( & V_32 -> V_114 ) ;
F_113 ( V_32 -> V_46 ) ;
F_114 ( V_32 -> V_46 -> V_63 ) ;
F_115 ( & V_32 -> V_176 ) ;
V_24 -> V_163 -> V_204 ( V_24 ) ;
V_203 = F_120 ( & F_67 ( V_32 -> V_46 ) -> V_124 . V_205 ) ;
F_116 ( V_32 -> V_46 ) ;
V_24 -> V_163 -> V_202 ( V_24 ) ;
F_75 ( V_32 -> V_61 ) ;
F_75 ( V_32 ) ;
if ( V_203 == 1 )
F_117 ( & V_166 , V_58 ) ;
}
static int F_121 ( struct V_115 * V_24 )
{
struct V_31 * V_32 = V_24 -> V_55 ;
V_24 -> V_163 -> V_204 ( V_24 ) ;
F_119 ( & V_32 -> V_114 ) ;
F_122 ( V_32 -> V_46 -> V_63 ) ;
V_24 -> V_163 -> V_202 ( V_24 ) ;
return 0 ;
}
static int F_123 ( struct V_115 * V_24 )
{
struct V_31 * V_32 = V_24 -> V_55 ;
int V_206 ;
V_206 = F_70 ( V_24 -> V_55 ) ;
if ( V_206 )
return V_206 ;
F_110 ( V_24 ) ;
F_124 ( V_32 -> V_46 -> V_63 ) ;
return 0 ;
}
static int T_10 F_125 ( void )
{
int error ;
V_126 = F_126 ( L_8 , 0 , 0 ) ;
if ( ! V_126 )
return - V_87 ;
V_188 = F_127 ( 0 , L_9 ) ;
if ( V_188 < 0 ) {
error = V_188 ;
goto V_207;
}
error = F_128 ( & V_31 ) ;
if ( error )
goto V_208;
return 0 ;
V_208:
F_129 ( V_188 , L_9 ) ;
V_207:
F_130 ( V_126 ) ;
return error ;
}
static void T_11 F_131 ( void )
{
F_132 ( & V_31 ) ;
F_129 ( V_188 , L_9 ) ;
F_130 ( V_126 ) ;
}
