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
V_21 -> V_38 = F_8 ( V_31 -> V_23 , V_2 -> V_26 . V_39 ) ;
}
static int F_9 ( struct V_40 * V_41 , T_1 V_42 ,
unsigned int V_14 , unsigned long V_43 )
{
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_30 * V_31 = V_45 -> V_47 ;
if ( ! F_10 ( V_31 -> V_23 , V_48 ) )
return - V_6 ;
return F_11 ( V_41 , V_42 , V_14 ,
( void V_49 * ) V_43 ) ;
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
switch ( F_14 ( V_29 ) ) {
case V_50 :
case V_51 :
F_6 ( V_29 ) ;
break;
}
F_15 ( V_29 , F_1 ( V_2 ) ) ;
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
F_21 ( V_29 ) ;
V_53 = true ;
}
if ( F_22 ( F_23 ( V_9 ) ) )
break;
} while ( ! F_24 ( V_9 ) );
if ( V_53 )
F_25 ( V_31 -> V_45 -> V_60 , true ) ;
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
case V_50 :
case V_51 :
type = V_76 ;
break;
case V_77 :
type = V_78 ;
break;
default:
F_29 ( 1 ) ;
return V_79 ;
}
V_2 -> V_20 . type = F_4 ( V_31 -> V_23 , type ) ;
V_2 -> V_20 . V_80 = type ?
0 : F_30 ( V_31 -> V_23 , F_31 ( V_29 ) ) ;
V_2 -> V_20 . V_81 = F_4 ( V_31 -> V_23 , F_32 ( V_29 ) ) ;
F_33 ( V_29 ) ;
V_66 = F_34 ( V_62 -> V_60 , V_29 , V_2 -> V_82 ) ;
if ( V_66 ) {
if ( F_35 ( V_29 ) == V_83 )
V_2 -> V_20 . type |= F_4 ( V_31 -> V_23 , V_24 ) ;
else
V_2 -> V_20 . type |= F_4 ( V_31 -> V_23 , V_84 ) ;
}
F_17 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( F_14 ( V_29 ) == V_50 || F_14 ( V_29 ) == V_51 )
V_68 = F_2 ( V_31 -> V_58 [ V_54 ] . V_9 , V_2 , V_2 -> V_82 , V_66 ) ;
else
V_68 = F_12 ( V_31 -> V_58 [ V_54 ] . V_9 , V_2 , V_2 -> V_82 , V_66 ) ;
if ( V_68 ) {
F_36 ( V_31 -> V_58 [ V_54 ] . V_9 ) ;
F_37 ( V_62 ) ;
F_26 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( V_68 == - V_85 || V_68 == - V_86 )
return V_87 ;
return V_79 ;
}
if ( V_64 -> V_88 && F_38 ( V_31 -> V_58 [ V_54 ] . V_9 ) )
V_69 = true ;
F_26 ( & V_31 -> V_58 [ V_54 ] . V_59 , V_56 ) ;
if ( V_69 )
F_39 ( V_31 -> V_58 [ V_54 ] . V_9 ) ;
return V_89 ;
}
static int F_40 ( struct V_44 * V_45 , char * V_90 )
{
struct V_30 * V_31 = V_45 -> V_47 ;
struct V_91 * V_32 = V_31 -> V_45 -> V_60 ;
struct V_28 * V_29 ;
int V_68 ;
V_29 = F_41 ( V_32 , V_77 , V_92 ) ;
if ( F_42 ( V_29 ) )
return F_43 ( V_29 ) ;
V_68 = F_44 ( V_32 , V_29 , V_90 , V_93 , V_92 ) ;
if ( V_68 )
goto V_94;
F_45 ( V_31 -> V_45 -> V_60 , V_31 -> V_45 , V_29 , false ) ;
V_68 = F_1 ( F_7 ( V_29 ) ) ;
V_94:
F_46 ( V_29 ) ;
return V_68 ;
}
static int F_47 ( struct V_40 * V_64 , struct V_95 * V_96 )
{
struct V_30 * V_31 = V_64 -> V_46 -> V_47 ;
if ( F_10 ( V_31 -> V_23 , V_97 ) ) {
F_48 ( V_31 -> V_23 , struct V_98 ,
V_99 . V_100 , & V_96 -> V_100 ) ;
F_48 ( V_31 -> V_23 , struct V_98 ,
V_99 . V_101 , & V_96 -> V_101 ) ;
F_48 ( V_31 -> V_23 , struct V_98 ,
V_99 . V_102 , & V_96 -> V_102 ) ;
} else {
V_96 -> V_101 = 1 << 6 ;
V_96 -> V_102 = 1 << 5 ;
V_96 -> V_100 = F_49 ( V_64 -> V_46 ) >> 11 ;
}
return 0 ;
}
static int F_50 ( int V_55 )
{
return V_55 << V_103 ;
}
static int F_51 ( int V_104 )
{
return V_104 >> V_103 ;
}
static T_3 F_52 ( struct V_105 * V_106 ,
struct V_107 * V_108 , char * V_109 )
{
struct V_44 * V_45 = F_53 ( V_106 ) ;
int V_68 ;
F_54 ( V_110 < V_93 ) ;
V_109 [ V_93 ] = '\0' ;
V_68 = F_40 ( V_45 , V_109 ) ;
if ( ! V_68 )
return strlen ( V_109 ) ;
if ( V_68 == - V_7 )
return 0 ;
return V_68 ;
}
static void F_55 ( struct V_111 * V_112 )
{
struct V_30 * V_31 =
F_56 ( V_112 , struct V_30 , V_113 ) ;
struct V_114 * V_23 = V_31 -> V_23 ;
struct V_91 * V_32 = V_31 -> V_45 -> V_60 ;
char V_115 [ 10 ] , V_116 [ 10 ] ;
char * V_117 [] = { L_1 , NULL } ;
T_4 V_118 ;
F_48 ( V_23 , struct V_98 , V_118 , & V_118 ) ;
if ( ( V_119 ) V_118 != V_118 ) {
F_57 ( & V_23 -> V_106 , L_2 ,
( unsigned long long ) V_118 ) ;
V_118 = ( V_119 ) - 1 ;
}
F_58 ( V_118 , F_59 ( V_32 ) ,
V_120 , V_115 , sizeof( V_115 ) ) ;
F_58 ( V_118 , F_59 ( V_32 ) ,
V_121 , V_116 , sizeof( V_116 ) ) ;
F_60 ( & V_23 -> V_106 ,
L_3 ,
( unsigned long long ) V_118 ,
F_59 ( V_32 ) ,
V_116 , V_115 ) ;
F_61 ( V_31 -> V_45 , V_118 ) ;
F_62 ( V_31 -> V_45 ) ;
F_63 ( & F_64 ( V_31 -> V_45 ) -> V_122 , V_123 , V_117 ) ;
}
static void F_65 ( struct V_114 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
F_66 ( V_124 , & V_31 -> V_113 ) ;
}
static int F_67 ( struct V_30 * V_31 )
{
int V_68 ;
int V_125 ;
T_5 * * V_126 ;
const char * * V_127 ;
struct V_8 * * V_58 ;
unsigned short V_128 ;
struct V_114 * V_23 = V_31 -> V_23 ;
struct V_129 V_130 = { 0 , } ;
V_68 = F_68 ( V_23 , V_131 ,
struct V_98 , V_132 ,
& V_128 ) ;
if ( V_68 )
V_128 = 1 ;
V_31 -> V_58 = F_69 ( V_128 , sizeof( * V_31 -> V_58 ) , V_92 ) ;
if ( ! V_31 -> V_58 )
return - V_85 ;
V_127 = F_69 ( V_128 , sizeof( * V_127 ) , V_92 ) ;
V_126 = F_69 ( V_128 , sizeof( * V_126 ) , V_92 ) ;
V_58 = F_69 ( V_128 , sizeof( * V_58 ) , V_92 ) ;
if ( ! V_127 || ! V_126 || ! V_58 ) {
V_68 = - V_85 ;
goto V_94;
}
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_126 [ V_125 ] = F_16 ;
snprintf ( V_31 -> V_58 [ V_125 ] . V_133 , V_134 , L_4 , V_125 ) ;
V_127 [ V_125 ] = V_31 -> V_58 [ V_125 ] . V_133 ;
}
V_68 = F_70 ( V_23 , V_128 , V_58 , V_126 , V_127 , & V_130 ) ;
if ( V_68 )
goto V_94;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
F_71 ( & V_31 -> V_58 [ V_125 ] . V_59 ) ;
V_31 -> V_58 [ V_125 ] . V_9 = V_58 [ V_125 ] ;
}
V_31 -> V_128 = V_128 ;
V_94:
F_72 ( V_58 ) ;
F_72 ( V_126 ) ;
F_72 ( V_127 ) ;
if ( V_68 )
F_72 ( V_31 -> V_58 ) ;
return V_68 ;
}
static int F_73 ( char * V_135 , int V_55 , char * V_109 , int V_136 )
{
const int V_137 = 'z' - 'a' + 1 ;
char * V_138 = V_109 + strlen ( V_135 ) ;
char * V_139 = V_109 + V_136 ;
char * V_140 ;
int V_141 ;
V_140 = V_139 - 1 ;
* V_140 = '\0' ;
V_141 = V_137 ;
do {
if ( V_140 == V_138 )
return - V_142 ;
* -- V_140 = 'a' + ( V_55 % V_141 ) ;
V_55 = ( V_55 / V_141 ) - 1 ;
} while ( V_55 >= 0 );
memmove ( V_138 , V_140 , V_139 - V_140 ) ;
memcpy ( V_109 , V_135 , strlen ( V_135 ) ) ;
return 0 ;
}
static int F_74 ( struct V_114 * V_23 )
{
T_6 V_143 ;
int V_68 ;
V_68 = F_68 ( V_23 , V_144 ,
struct V_98 , V_145 ,
& V_143 ) ;
if ( V_68 )
V_143 = F_10 ( V_23 , V_146 ) ;
return V_143 ;
}
static void F_75 ( struct V_114 * V_23 )
{
T_6 V_143 = F_74 ( V_23 ) ;
struct V_30 * V_31 = V_23 -> V_52 ;
F_76 ( V_31 -> V_45 -> V_60 , V_143 , false ) ;
F_62 ( V_31 -> V_45 ) ;
}
static T_3
F_77 ( struct V_105 * V_106 , struct V_107 * V_108 ,
const char * V_109 , T_7 V_147 )
{
struct V_44 * V_45 = F_53 ( V_106 ) ;
struct V_30 * V_31 = V_45 -> V_47 ;
struct V_114 * V_23 = V_31 -> V_23 ;
int V_125 ;
F_28 ( ! F_10 ( V_31 -> V_23 , V_144 ) ) ;
for ( V_125 = F_78 ( V_148 ) ; -- V_125 >= 0 ; )
if ( F_79 ( V_109 , V_148 [ V_125 ] ) )
break;
if ( V_125 < 0 )
return - V_142 ;
F_80 ( V_23 , F_81 ( struct V_98 , V_145 ) , V_125 ) ;
F_75 ( V_23 ) ;
return V_147 ;
}
static T_3
F_82 ( struct V_105 * V_106 , struct V_107 * V_108 ,
char * V_109 )
{
struct V_44 * V_45 = F_53 ( V_106 ) ;
struct V_30 * V_31 = V_45 -> V_47 ;
T_6 V_143 = F_74 ( V_31 -> V_23 ) ;
F_28 ( V_143 >= F_78 ( V_148 ) ) ;
return snprintf ( V_109 , 40 , L_5 , V_148 [ V_143 ] ) ;
}
static int F_83 ( struct V_149 * V_150 , struct V_28 * V_65 ,
unsigned int V_151 , unsigned int V_152 )
{
struct V_30 * V_31 = V_150 -> V_153 ;
struct V_1 * V_2 = F_7 ( V_65 ) ;
#ifdef F_84
V_2 -> V_21 . V_15 = V_2 -> V_15 ;
#endif
F_85 ( V_2 -> V_82 , V_31 -> V_71 ) ;
return 0 ;
}
static int F_86 ( struct V_149 * V_150 )
{
struct V_30 * V_31 = V_150 -> V_153 ;
return F_87 ( V_150 , V_31 -> V_23 , 0 ) ;
}
static int F_88 ( struct V_114 * V_23 )
{
struct V_30 * V_31 ;
struct V_91 * V_32 ;
int V_68 , V_55 ;
T_4 V_154 ;
T_2 V_155 , V_156 , V_71 , V_157 ;
T_8 V_158 ;
T_6 V_159 , V_160 ;
if ( ! V_23 -> V_161 -> V_162 ) {
F_89 ( & V_23 -> V_106 , L_6 ,
V_163 ) ;
return - V_142 ;
}
V_68 = F_90 ( & V_164 , 0 , F_51 ( 1 << V_165 ) ,
V_92 ) ;
if ( V_68 < 0 )
goto V_94;
V_55 = V_68 ;
V_68 = F_68 ( V_23 , V_166 ,
struct V_98 , V_167 ,
& V_71 ) ;
if ( V_68 || ! V_71 )
V_71 = 1 ;
V_71 += 2 ;
V_23 -> V_52 = V_31 = F_91 ( sizeof( * V_31 ) , V_92 ) ;
if ( ! V_31 ) {
V_68 = - V_85 ;
goto V_168;
}
V_31 -> V_23 = V_23 ;
V_31 -> V_71 = V_71 ;
F_92 ( & V_31 -> V_113 , F_55 ) ;
V_68 = F_67 ( V_31 ) ;
if ( V_68 )
goto V_169;
V_31 -> V_45 = F_93 ( 1 << V_103 ) ;
if ( ! V_31 -> V_45 ) {
V_68 = - V_85 ;
goto V_170;
}
if ( ! V_171 ) {
V_171 = V_31 -> V_58 [ 0 ] . V_9 -> V_172 ;
if ( ! F_10 ( V_23 , V_173 ) )
V_171 /= 2 ;
}
memset ( & V_31 -> V_174 , 0 , sizeof( V_31 -> V_174 ) ) ;
V_31 -> V_174 . V_175 = & V_176 ;
V_31 -> V_174 . V_177 = V_171 ;
V_31 -> V_174 . V_152 = V_178 ;
V_31 -> V_174 . V_56 = V_179 ;
V_31 -> V_174 . V_180 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_71 ;
V_31 -> V_174 . V_153 = V_31 ;
V_31 -> V_174 . V_181 = V_31 -> V_128 ;
V_68 = F_94 ( & V_31 -> V_174 ) ;
if ( V_68 )
goto V_182;
V_32 = F_95 ( & V_31 -> V_174 ) ;
if ( F_42 ( V_32 ) ) {
V_68 = - V_85 ;
goto V_183;
}
V_31 -> V_45 -> V_60 = V_32 ;
V_32 -> V_33 = V_31 ;
F_73 ( L_7 , V_55 , V_31 -> V_45 -> V_184 , V_185 ) ;
V_31 -> V_45 -> V_186 = V_186 ;
V_31 -> V_45 -> V_187 = F_50 ( V_55 ) ;
V_31 -> V_45 -> V_47 = V_31 ;
V_31 -> V_45 -> V_188 = & V_189 ;
V_31 -> V_45 -> V_56 |= V_190 ;
V_31 -> V_55 = V_55 ;
F_75 ( V_23 ) ;
if ( F_10 ( V_23 , V_191 ) )
F_96 ( V_31 -> V_45 , 1 ) ;
F_48 ( V_23 , struct V_98 , V_118 , & V_154 ) ;
if ( ( V_119 ) V_154 != V_154 ) {
F_57 ( & V_23 -> V_106 , L_2 ,
( unsigned long long ) V_154 ) ;
V_154 = ( V_119 ) - 1 ;
}
F_61 ( V_31 -> V_45 , V_154 ) ;
F_97 ( V_32 , V_31 -> V_71 - 2 ) ;
F_98 ( V_32 , V_192 ) ;
F_99 ( V_32 , - 1U ) ;
V_68 = F_68 ( V_23 , V_193 ,
struct V_98 , V_194 , & V_155 ) ;
if ( ! V_68 )
F_100 ( V_32 , V_155 ) ;
else
F_100 ( V_32 , - 1U ) ;
V_68 = F_68 ( V_23 , V_195 ,
struct V_98 , V_156 ,
& V_156 ) ;
if ( ! V_68 )
F_101 ( V_32 , V_156 ) ;
else
V_156 = F_59 ( V_32 ) ;
V_68 = F_68 ( V_23 , V_196 ,
struct V_98 , V_159 ,
& V_159 ) ;
if ( ! V_68 && V_159 )
F_102 ( V_32 ,
V_156 * ( 1 << V_159 ) ) ;
V_68 = F_68 ( V_23 , V_196 ,
struct V_98 , V_160 ,
& V_160 ) ;
if ( ! V_68 && V_160 )
F_103 ( V_32 , V_156 * V_160 ) ;
V_68 = F_68 ( V_23 , V_196 ,
struct V_98 , V_158 ,
& V_158 ) ;
if ( ! V_68 && V_158 )
F_104 ( V_32 , V_156 * V_158 ) ;
V_68 = F_68 ( V_23 , V_196 ,
struct V_98 , V_157 ,
& V_157 ) ;
if ( ! V_68 && V_157 )
F_105 ( V_32 , V_156 * V_157 ) ;
F_106 ( V_23 ) ;
F_107 ( & V_23 -> V_106 , V_31 -> V_45 ) ;
V_68 = F_108 ( F_64 ( V_31 -> V_45 ) , & V_197 ) ;
if ( V_68 )
goto V_198;
if ( F_10 ( V_23 , V_144 ) )
V_68 = F_108 ( F_64 ( V_31 -> V_45 ) ,
& V_199 ) ;
else
V_68 = F_108 ( F_64 ( V_31 -> V_45 ) ,
& V_200 ) ;
if ( V_68 )
goto V_198;
return 0 ;
V_198:
F_109 ( V_31 -> V_45 ) ;
F_110 ( V_31 -> V_45 -> V_60 ) ;
V_183:
F_111 ( & V_31 -> V_174 ) ;
V_182:
F_112 ( V_31 -> V_45 ) ;
V_170:
V_23 -> V_161 -> V_201 ( V_23 ) ;
V_169:
F_72 ( V_31 ) ;
V_168:
F_113 ( & V_164 , V_55 ) ;
V_94:
return V_68 ;
}
static void F_114 ( struct V_114 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
int V_55 = V_31 -> V_55 ;
int V_202 ;
F_115 ( & V_31 -> V_113 ) ;
F_109 ( V_31 -> V_45 ) ;
F_110 ( V_31 -> V_45 -> V_60 ) ;
F_111 ( & V_31 -> V_174 ) ;
V_23 -> V_161 -> V_203 ( V_23 ) ;
V_202 = F_116 ( & F_64 ( V_31 -> V_45 ) -> V_122 . V_204 ) ;
F_112 ( V_31 -> V_45 ) ;
V_23 -> V_161 -> V_201 ( V_23 ) ;
F_72 ( V_31 -> V_58 ) ;
F_72 ( V_31 ) ;
if ( V_202 == 1 )
F_113 ( & V_164 , V_55 ) ;
}
static int F_117 ( struct V_114 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
V_23 -> V_161 -> V_203 ( V_23 ) ;
F_115 ( & V_31 -> V_113 ) ;
F_118 ( V_31 -> V_45 -> V_60 ) ;
V_23 -> V_161 -> V_201 ( V_23 ) ;
return 0 ;
}
static int F_119 ( struct V_114 * V_23 )
{
struct V_30 * V_31 = V_23 -> V_52 ;
int V_205 ;
V_205 = F_67 ( V_23 -> V_52 ) ;
if ( V_205 )
return V_205 ;
F_106 ( V_23 ) ;
F_25 ( V_31 -> V_45 -> V_60 , true ) ;
return 0 ;
}
static int T_9 F_120 ( void )
{
int error ;
V_124 = F_121 ( L_8 , 0 , 0 ) ;
if ( ! V_124 )
return - V_85 ;
V_186 = F_122 ( 0 , L_9 ) ;
if ( V_186 < 0 ) {
error = V_186 ;
goto V_206;
}
error = F_123 ( & V_30 ) ;
if ( error )
goto V_207;
return 0 ;
V_207:
F_124 ( V_186 , L_9 ) ;
V_206:
F_125 ( V_124 ) ;
return error ;
}
static void T_10 F_126 ( void )
{
F_127 ( & V_30 ) ;
F_124 ( V_186 , L_9 ) ;
F_125 ( V_124 ) ;
}
