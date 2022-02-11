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
struct V_1 * V_2 ;
unsigned long V_41 ;
unsigned int V_42 ;
F_9 ( & V_37 -> V_43 , V_41 ) ;
do {
F_10 ( V_9 ) ;
while ( ( V_2 = F_11 ( V_37 -> V_9 , & V_42 ) ) != NULL ) {
F_12 ( V_2 -> V_23 ) ;
V_40 = true ;
}
if ( F_13 ( F_14 ( V_9 ) ) )
break;
} while ( ! F_15 ( V_9 ) );
if ( V_40 )
F_16 ( V_37 -> V_44 -> V_45 , true ) ;
F_17 ( & V_37 -> V_43 , V_41 ) ;
}
static int F_18 ( struct V_46 * V_47 , struct V_28 * V_23 )
{
struct V_36 * V_37 = V_47 -> V_45 -> V_48 ;
struct V_1 * V_2 = F_6 ( V_23 ) ;
unsigned long V_41 ;
unsigned int V_49 ;
const bool V_50 = ( V_23 -> V_51 & V_52 ) != 0 ;
int V_53 ;
bool V_54 = false ;
F_19 ( V_23 -> V_55 + 2 > V_37 -> V_56 ) ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_51 & V_57 ) {
V_2 -> V_20 . type = V_58 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_20 ( V_2 -> V_23 ) ;
} else {
switch ( V_23 -> V_29 ) {
case V_61 :
V_2 -> V_20 . type = 0 ;
V_2 -> V_20 . V_59 = F_21 ( V_2 -> V_23 ) ;
V_2 -> V_20 . V_60 = F_20 ( V_2 -> V_23 ) ;
break;
case V_30 :
V_2 -> V_20 . type = V_22 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_20 ( V_2 -> V_23 ) ;
break;
case V_35 :
V_2 -> V_20 . type = V_62 ;
V_2 -> V_20 . V_59 = 0 ;
V_2 -> V_20 . V_60 = F_20 ( V_2 -> V_23 ) ;
break;
default:
F_22 () ;
}
}
V_49 = F_23 ( V_47 -> V_45 , V_2 -> V_23 , V_2 -> V_63 ) ;
if ( V_49 ) {
if ( F_24 ( V_2 -> V_23 ) == V_64 )
V_2 -> V_20 . type |= V_21 ;
else
V_2 -> V_20 . type |= V_65 ;
}
F_9 ( & V_37 -> V_43 , V_41 ) ;
V_53 = F_2 ( V_37 -> V_9 , V_2 , V_2 -> V_63 , V_49 ) ;
if ( V_53 ) {
F_25 ( V_37 -> V_9 ) ;
F_26 ( V_47 ) ;
F_17 ( & V_37 -> V_43 , V_41 ) ;
if ( V_53 == - V_66 || V_53 == - V_67 )
return V_68 ;
return V_69 ;
}
if ( V_50 && F_27 ( V_37 -> V_9 ) )
V_54 = true ;
F_17 ( & V_37 -> V_43 , V_41 ) ;
if ( V_54 )
F_28 ( V_37 -> V_9 ) ;
return V_70 ;
}
static int F_29 ( struct V_71 * V_44 , char * V_72 )
{
struct V_36 * V_37 = V_44 -> V_73 ;
struct V_28 * V_23 ;
struct V_74 * V_74 ;
int V_53 ;
V_74 = F_30 ( V_37 -> V_44 -> V_45 , V_72 , V_75 ,
V_76 ) ;
if ( F_31 ( V_74 ) )
return F_32 ( V_74 ) ;
V_23 = F_33 ( V_37 -> V_44 -> V_45 , V_74 , V_76 ) ;
if ( F_31 ( V_23 ) ) {
F_34 ( V_74 ) ;
return F_32 ( V_23 ) ;
}
V_23 -> V_29 = V_35 ;
V_53 = F_35 ( V_37 -> V_44 -> V_45 , V_37 -> V_44 , V_23 , false ) ;
F_36 ( V_23 ) ;
return V_53 ;
}
static int F_37 ( struct V_77 * V_78 , T_1 V_79 ,
unsigned int V_14 , unsigned long V_80 )
{
struct V_71 * V_44 = V_78 -> V_81 ;
struct V_36 * V_37 = V_44 -> V_73 ;
if ( ! F_38 ( V_37 -> V_38 , V_82 ) )
return - V_6 ;
return F_39 ( V_78 , V_79 , V_14 ,
( void V_83 * ) V_80 ) ;
}
static int F_40 ( struct V_77 * V_84 , struct V_85 * V_86 )
{
struct V_36 * V_37 = V_84 -> V_81 -> V_73 ;
if ( F_38 ( V_37 -> V_38 , V_87 ) ) {
F_41 ( V_37 -> V_38 , struct V_88 ,
V_89 . V_90 , & V_86 -> V_90 ) ;
F_41 ( V_37 -> V_38 , struct V_88 ,
V_89 . V_91 , & V_86 -> V_91 ) ;
F_41 ( V_37 -> V_38 , struct V_88 ,
V_89 . V_92 , & V_86 -> V_92 ) ;
} else {
V_86 -> V_91 = 1 << 6 ;
V_86 -> V_92 = 1 << 5 ;
V_86 -> V_90 = F_42 ( V_84 -> V_81 ) >> 11 ;
}
return 0 ;
}
static int F_43 ( int V_93 )
{
return V_93 << V_94 ;
}
static int F_44 ( int V_95 )
{
return V_95 >> V_94 ;
}
static T_2 F_45 ( struct V_96 * V_97 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_71 * V_44 = F_46 ( V_97 ) ;
int V_53 ;
F_47 ( V_101 < V_75 ) ;
V_100 [ V_75 ] = '\0' ;
V_53 = F_29 ( V_44 , V_100 ) ;
if ( ! V_53 )
return strlen ( V_100 ) ;
if ( V_53 == - V_7 )
return 0 ;
return V_53 ;
}
static void F_48 ( struct V_102 * V_103 )
{
struct V_36 * V_37 =
F_49 ( V_103 , struct V_36 , V_104 ) ;
struct V_105 * V_38 = V_37 -> V_38 ;
struct V_106 * V_107 = V_37 -> V_44 -> V_45 ;
char V_108 [ 10 ] , V_109 [ 10 ] ;
char * V_110 [] = { L_1 , NULL } ;
T_3 V_111 , V_112 ;
F_50 ( & V_37 -> V_113 ) ;
if ( ! V_37 -> V_114 )
goto V_115;
F_41 ( V_38 , struct V_88 , V_111 , & V_111 ) ;
if ( ( V_116 ) V_111 != V_111 ) {
F_51 ( & V_38 -> V_97 , L_2 ,
( unsigned long long ) V_111 ) ;
V_111 = ( V_116 ) - 1 ;
}
V_112 = V_111 * F_52 ( V_107 ) ;
F_53 ( V_112 , V_117 , V_108 , sizeof( V_108 ) ) ;
F_53 ( V_112 , V_118 , V_109 , sizeof( V_109 ) ) ;
F_54 ( & V_38 -> V_97 ,
L_3 ,
( unsigned long long ) V_111 ,
F_52 ( V_107 ) ,
V_109 , V_108 ) ;
F_55 ( V_37 -> V_44 , V_111 ) ;
F_56 ( V_37 -> V_44 ) ;
F_57 ( & F_58 ( V_37 -> V_44 ) -> V_119 , V_120 , V_110 ) ;
V_115:
F_59 ( & V_37 -> V_113 ) ;
}
static void F_60 ( struct V_105 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
F_61 ( V_121 , & V_37 -> V_104 ) ;
}
static int F_62 ( struct V_36 * V_37 )
{
int V_53 = 0 ;
V_37 -> V_9 = F_63 ( V_37 -> V_38 , F_8 , L_4 ) ;
if ( F_31 ( V_37 -> V_9 ) )
V_53 = F_32 ( V_37 -> V_9 ) ;
return V_53 ;
}
static int F_64 ( char * V_122 , int V_93 , char * V_100 , int V_123 )
{
const int V_124 = 'z' - 'a' + 1 ;
char * V_125 = V_100 + strlen ( V_122 ) ;
char * V_126 = V_100 + V_123 ;
char * V_127 ;
int V_128 ;
V_127 = V_126 - 1 ;
* V_127 = '\0' ;
V_128 = V_124 ;
do {
if ( V_127 == V_125 )
return - V_129 ;
* -- V_127 = 'a' + ( V_93 % V_128 ) ;
V_93 = ( V_93 / V_128 ) - 1 ;
} while ( V_93 >= 0 );
memmove ( V_125 , V_127 , V_126 - V_127 ) ;
memcpy ( V_100 , V_122 , strlen ( V_122 ) ) ;
return 0 ;
}
static int F_65 ( struct V_105 * V_38 )
{
T_4 V_130 ;
int V_53 ;
V_53 = F_66 ( V_38 , V_131 ,
struct V_88 , V_132 ,
& V_130 ) ;
if ( V_53 )
V_130 = F_38 ( V_38 , V_133 ) ;
return V_130 ;
}
static void F_67 ( struct V_105 * V_38 )
{
T_4 V_130 = F_65 ( V_38 ) ;
struct V_36 * V_37 = V_38 -> V_39 ;
if ( V_130 )
F_68 ( V_37 -> V_44 -> V_45 , V_57 ) ;
else
F_68 ( V_37 -> V_44 -> V_45 , 0 ) ;
F_56 ( V_37 -> V_44 ) ;
}
static T_2
F_69 ( struct V_96 * V_97 , struct V_98 * V_99 ,
const char * V_100 , T_5 V_134 )
{
struct V_71 * V_44 = F_46 ( V_97 ) ;
struct V_36 * V_37 = V_44 -> V_73 ;
struct V_105 * V_38 = V_37 -> V_38 ;
int V_135 ;
F_19 ( ! F_38 ( V_37 -> V_38 , V_131 ) ) ;
for ( V_135 = F_70 ( V_136 ) ; -- V_135 >= 0 ; )
if ( F_71 ( V_100 , V_136 [ V_135 ] ) )
break;
if ( V_135 < 0 )
return - V_129 ;
F_72 ( V_38 , F_73 ( struct V_88 , V_132 ) , V_135 ) ;
F_67 ( V_38 ) ;
return V_134 ;
}
static T_2
F_74 ( struct V_96 * V_97 , struct V_98 * V_99 ,
char * V_100 )
{
struct V_71 * V_44 = F_46 ( V_97 ) ;
struct V_36 * V_37 = V_44 -> V_73 ;
T_4 V_130 = F_65 ( V_37 -> V_38 ) ;
F_19 ( V_130 >= F_70 ( V_136 ) ) ;
return snprintf ( V_100 , 40 , L_5 , V_136 [ V_130 ] ) ;
}
static int F_75 ( void * V_80 , struct V_28 * V_137 ,
unsigned int V_138 , unsigned int V_139 ,
unsigned int V_140 )
{
struct V_36 * V_37 = V_80 ;
struct V_1 * V_2 = F_6 ( V_137 ) ;
F_76 ( V_2 -> V_63 , V_37 -> V_56 ) ;
return 0 ;
}
static int F_77 ( struct V_105 * V_38 )
{
struct V_36 * V_37 ;
struct V_106 * V_107 ;
int V_53 , V_93 ;
T_3 V_141 ;
T_6 V_142 , V_143 , V_56 , V_144 ;
T_7 V_145 ;
T_4 V_146 , V_147 ;
V_53 = F_78 ( & V_148 , 0 , F_44 ( 1 << V_149 ) ,
V_76 ) ;
if ( V_53 < 0 )
goto V_150;
V_93 = V_53 ;
V_53 = F_66 ( V_38 , V_151 ,
struct V_88 , V_152 ,
& V_56 ) ;
if ( V_53 || ! V_56 )
V_56 = 1 ;
V_56 += 2 ;
V_38 -> V_39 = V_37 = F_79 ( sizeof( * V_37 ) , V_76 ) ;
if ( ! V_37 ) {
V_53 = - V_66 ;
goto V_153;
}
V_37 -> V_38 = V_38 ;
V_37 -> V_56 = V_56 ;
F_80 ( & V_37 -> V_113 ) ;
F_81 ( & V_37 -> V_104 , F_48 ) ;
V_37 -> V_114 = true ;
V_53 = F_62 ( V_37 ) ;
if ( V_53 )
goto V_154;
F_82 ( & V_37 -> V_43 ) ;
V_37 -> V_44 = F_83 ( 1 << V_94 ) ;
if ( ! V_37 -> V_44 ) {
V_53 = - V_66 ;
goto V_155;
}
if ( ! V_156 ) {
V_156 = V_37 -> V_9 -> V_157 ;
if ( ! F_38 ( V_38 , V_158 ) )
V_156 /= 2 ;
}
memset ( & V_37 -> V_159 , 0 , sizeof( V_37 -> V_159 ) ) ;
V_37 -> V_159 . V_160 = & V_161 ;
V_37 -> V_159 . V_162 = 1 ;
V_37 -> V_159 . V_163 = V_156 ;
V_37 -> V_159 . V_140 = V_164 ;
V_37 -> V_159 . V_41 = V_165 ;
V_37 -> V_159 . V_166 =
sizeof( struct V_1 ) +
sizeof( struct V_10 ) * V_56 ;
V_37 -> V_159 . V_167 = V_37 ;
V_53 = F_84 ( & V_37 -> V_159 ) ;
if ( V_53 )
goto V_168;
V_107 = V_37 -> V_44 -> V_45 = F_85 ( & V_37 -> V_159 ) ;
if ( ! V_107 ) {
V_53 = - V_66 ;
goto V_169;
}
V_107 -> V_48 = V_37 ;
F_64 ( L_6 , V_93 , V_37 -> V_44 -> V_170 , V_171 ) ;
V_37 -> V_44 -> V_172 = V_172 ;
V_37 -> V_44 -> V_173 = F_43 ( V_93 ) ;
V_37 -> V_44 -> V_73 = V_37 ;
V_37 -> V_44 -> V_174 = & V_175 ;
V_37 -> V_44 -> V_176 = & V_38 -> V_97 ;
V_37 -> V_93 = V_93 ;
F_67 ( V_38 ) ;
if ( F_38 ( V_38 , V_177 ) )
F_86 ( V_37 -> V_44 , 1 ) ;
F_41 ( V_38 , struct V_88 , V_111 , & V_141 ) ;
if ( ( V_116 ) V_141 != V_141 ) {
F_51 ( & V_38 -> V_97 , L_2 ,
( unsigned long long ) V_141 ) ;
V_141 = ( V_116 ) - 1 ;
}
F_55 ( V_37 -> V_44 , V_141 ) ;
F_87 ( V_107 , V_37 -> V_56 - 2 ) ;
F_88 ( V_107 , V_178 ) ;
F_89 ( V_107 , - 1U ) ;
V_53 = F_66 ( V_38 , V_179 ,
struct V_88 , V_180 , & V_142 ) ;
if ( ! V_53 )
F_90 ( V_107 , V_142 ) ;
else
F_90 ( V_107 , - 1U ) ;
V_53 = F_66 ( V_38 , V_181 ,
struct V_88 , V_143 ,
& V_143 ) ;
if ( ! V_53 )
F_91 ( V_107 , V_143 ) ;
else
V_143 = F_52 ( V_107 ) ;
V_53 = F_66 ( V_38 , V_182 ,
struct V_88 , V_146 ,
& V_146 ) ;
if ( ! V_53 && V_146 )
F_92 ( V_107 ,
V_143 * ( 1 << V_146 ) ) ;
V_53 = F_66 ( V_38 , V_182 ,
struct V_88 , V_147 ,
& V_147 ) ;
if ( ! V_53 && V_147 )
F_93 ( V_107 , V_143 * V_147 ) ;
V_53 = F_66 ( V_38 , V_182 ,
struct V_88 , V_145 ,
& V_145 ) ;
if ( ! V_53 && V_145 )
F_94 ( V_107 , V_143 * V_145 ) ;
V_53 = F_66 ( V_38 , V_182 ,
struct V_88 , V_144 ,
& V_144 ) ;
if ( ! V_53 && V_144 )
F_95 ( V_107 , V_143 * V_144 ) ;
F_96 ( V_37 -> V_44 ) ;
V_53 = F_97 ( F_58 ( V_37 -> V_44 ) , & V_183 ) ;
if ( V_53 )
goto V_184;
if ( F_38 ( V_38 , V_131 ) )
V_53 = F_97 ( F_58 ( V_37 -> V_44 ) ,
& V_185 ) ;
else
V_53 = F_97 ( F_58 ( V_37 -> V_44 ) ,
& V_186 ) ;
if ( V_53 )
goto V_184;
return 0 ;
V_184:
F_98 ( V_37 -> V_44 ) ;
F_99 ( V_37 -> V_44 -> V_45 ) ;
V_169:
F_100 ( & V_37 -> V_159 ) ;
V_168:
F_101 ( V_37 -> V_44 ) ;
V_155:
V_38 -> V_187 -> V_188 ( V_38 ) ;
V_154:
F_102 ( V_37 ) ;
V_153:
F_103 ( & V_148 , V_93 ) ;
V_150:
return V_53 ;
}
static void F_104 ( struct V_105 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_93 = V_37 -> V_93 ;
int V_189 ;
F_50 ( & V_37 -> V_113 ) ;
V_37 -> V_114 = false ;
F_59 ( & V_37 -> V_113 ) ;
F_98 ( V_37 -> V_44 ) ;
F_99 ( V_37 -> V_44 -> V_45 ) ;
F_100 ( & V_37 -> V_159 ) ;
V_38 -> V_187 -> V_190 ( V_38 ) ;
F_105 ( & V_37 -> V_104 ) ;
V_189 = F_106 ( & F_58 ( V_37 -> V_44 ) -> V_119 . V_191 . V_192 ) ;
F_101 ( V_37 -> V_44 ) ;
V_38 -> V_187 -> V_188 ( V_38 ) ;
F_102 ( V_37 ) ;
if ( V_189 == 1 )
F_103 ( & V_148 , V_93 ) ;
}
static int F_107 ( struct V_105 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
V_38 -> V_187 -> V_190 ( V_38 ) ;
F_50 ( & V_37 -> V_113 ) ;
V_37 -> V_114 = false ;
F_59 ( & V_37 -> V_113 ) ;
F_105 ( & V_37 -> V_104 ) ;
F_108 ( V_37 -> V_44 -> V_45 ) ;
V_38 -> V_187 -> V_188 ( V_38 ) ;
return 0 ;
}
static int F_109 ( struct V_105 * V_38 )
{
struct V_36 * V_37 = V_38 -> V_39 ;
int V_193 ;
V_37 -> V_114 = true ;
V_193 = F_62 ( V_38 -> V_39 ) ;
if ( ! V_193 )
F_16 ( V_37 -> V_44 -> V_45 , true ) ;
return V_193 ;
}
static int T_8 F_110 ( void )
{
int error ;
V_121 = F_111 ( L_7 , 0 , 0 ) ;
if ( ! V_121 )
return - V_66 ;
V_172 = F_112 ( 0 , L_8 ) ;
if ( V_172 < 0 ) {
error = V_172 ;
goto V_194;
}
error = F_113 ( & V_36 ) ;
if ( error )
goto V_195;
return 0 ;
V_195:
F_114 ( V_172 , L_8 ) ;
V_194:
F_115 ( V_121 ) ;
return error ;
}
static void T_9 F_116 ( void )
{
F_114 ( V_172 , L_8 ) ;
F_117 ( & V_36 ) ;
F_115 ( V_121 ) ;
}
