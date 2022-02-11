static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( V_2 , F_3 ( V_4 ) , V_4 -> V_7 ,
V_6 -> V_8 , V_4 -> V_9 , V_10 ) ;
}
void F_4 ( void )
{
F_5 ( & V_11 ) ;
}
void F_6 ( void )
{
F_7 ( & V_11 ) ;
}
int F_8 ( void )
{
if ( V_12 )
return F_9 ( & V_11 ) ;
else
return 1 ;
}
static struct V_13 * F_10 ( struct V_14 * V_14 , int V_15 )
{
struct V_13 * V_16 = NULL ;
struct V_17 * V_18 ;
F_11 () ;
V_18 = F_12 ( V_14 , V_15 ) ;
if ( V_18 ) {
struct V_19 * V_19 = F_13 ( V_18 ) ;
if ( V_19 )
V_16 = V_19 -> V_16 ;
}
F_14 () ;
return V_16 ;
}
const char * F_15 ( const struct V_13 * V_16 )
{
struct V_19 * V_19 = F_16 ( V_16 , V_20 ) ;
return V_19 -> V_21 -> V_22 ( V_19 ) ;
}
static int F_17 ( struct V_13 * V_16 )
{
struct V_19 * V_23 ;
int V_24 ;
F_11 () ;
V_23 = F_18 ( V_16 , V_20 ) ;
if ( V_23 )
V_24 = F_19 ( V_23 ) -> V_18 -> V_24 ;
else
V_24 = 0 ;
F_14 () ;
return V_24 ;
}
static void F_20 ( struct V_25 * V_26 )
{
struct V_13 * V_16 = F_21 ( V_26 , struct V_13 , V_26 ) ;
F_22 ( ( V_27 struct V_28 * ) V_16 -> V_29 , false ) ;
F_23 ( V_16 -> V_30 ) ;
F_24 ( F_25 ( V_16 ) ) ;
F_26 ( V_16 -> V_31 ) ;
F_26 ( V_16 ) ;
}
static struct V_32 * F_27 ( const struct V_13 * V_16 ,
T_1 V_33 )
{
return & V_16 -> V_31 [ V_33 & ( V_34 - 1 ) ] ;
}
struct V_19 * F_28 ( const struct V_13 * V_16 , T_1 V_33 )
{
struct V_19 * V_19 ;
struct V_32 * V_35 ;
V_35 = F_27 ( V_16 , V_33 ) ;
F_29 (vport, head, dp_hash_node) {
if ( V_19 -> V_33 == V_33 )
return V_19 ;
}
return NULL ;
}
static struct V_19 * F_30 ( const struct V_36 * V_37 )
{
struct V_19 * V_19 ;
V_19 = F_31 ( V_37 ) ;
if ( ! F_32 ( V_19 ) ) {
struct V_13 * V_16 = V_37 -> V_16 ;
struct V_32 * V_35 = F_27 ( V_16 , V_19 -> V_33 ) ;
F_33 ( & V_19 -> V_38 , V_35 ) ;
}
return V_19 ;
}
void F_34 ( struct V_19 * V_39 )
{
F_35 () ;
F_36 ( & V_39 -> V_38 ) ;
F_37 ( V_39 ) ;
}
void F_38 ( struct V_19 * V_39 , struct V_1 * V_2 )
{
struct V_13 * V_16 = V_39 -> V_16 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 V_45 ;
T_2 * V_46 ;
int error ;
V_43 = F_39 ( V_16 -> V_30 ) ;
error = F_40 ( V_2 , V_39 -> V_33 , & V_45 ) ;
if ( F_41 ( error ) ) {
F_42 ( V_2 ) ;
return;
}
V_41 = F_43 ( F_44 ( V_16 -> V_29 ) , & V_45 ) ;
if ( F_41 ( ! V_41 ) ) {
struct V_47 V_48 ;
V_48 . V_49 = V_50 ;
V_48 . V_45 = & V_45 ;
V_48 . V_51 = NULL ;
V_48 . V_52 = V_39 -> V_53 ;
F_45 ( V_16 , V_2 , & V_48 ) ;
F_46 ( V_2 ) ;
V_46 = & V_43 -> V_54 ;
goto V_55;
}
F_47 ( V_2 ) -> V_41 = V_41 ;
F_47 ( V_2 ) -> V_56 = & V_45 ;
V_46 = & V_43 -> V_57 ;
F_48 ( F_47 ( V_2 ) -> V_41 , V_2 ) ;
F_49 ( V_16 , V_2 ) ;
V_55:
F_50 ( & V_43 -> V_58 ) ;
( * V_46 ) ++ ;
F_51 ( & V_43 -> V_58 ) ;
}
int F_45 ( struct V_13 * V_16 , struct V_1 * V_2 ,
const struct V_47 * V_59 )
{
struct V_42 * V_43 ;
int V_15 ;
int V_60 ;
if ( V_59 -> V_52 == 0 ) {
V_60 = - V_61 ;
goto V_60;
}
V_15 = F_17 ( V_16 ) ;
if ( ! V_15 ) {
V_60 = - V_62 ;
goto V_60;
}
if ( ! F_52 ( V_2 ) )
V_60 = F_53 ( F_25 ( V_16 ) , V_15 , V_2 , V_59 ) ;
else
V_60 = F_54 ( F_25 ( V_16 ) , V_15 , V_2 , V_59 ) ;
if ( V_60 )
goto V_60;
return 0 ;
V_60:
V_43 = F_39 ( V_16 -> V_30 ) ;
F_50 ( & V_43 -> V_58 ) ;
V_43 -> V_63 ++ ;
F_51 ( & V_43 -> V_58 ) ;
return V_60 ;
}
static int F_54 ( struct V_14 * V_14 , int V_15 ,
struct V_1 * V_2 ,
const struct V_47 * V_59 )
{
unsigned short V_64 = F_55 ( V_2 ) -> V_64 ;
struct V_47 V_65 ;
struct V_44 V_66 ;
struct V_1 * V_67 , * V_68 ;
int V_60 ;
V_67 = F_56 ( V_2 , V_69 | V_70 , false ) ;
if ( F_32 ( V_67 ) )
return F_57 ( V_67 ) ;
V_2 = V_67 ;
do {
V_60 = F_53 ( V_14 , V_15 , V_2 , V_59 ) ;
if ( V_60 )
break;
if ( V_2 == V_67 && V_64 & V_71 ) {
V_66 = * V_59 -> V_45 ;
V_66 . V_72 . V_73 = V_74 ;
V_65 = * V_59 ;
V_65 . V_45 = & V_66 ;
V_59 = & V_65 ;
}
} while ( ( V_2 = V_2 -> V_75 ) );
V_2 = V_67 ;
do {
V_68 = V_2 -> V_75 ;
if ( V_60 )
F_42 ( V_2 ) ;
else
F_46 ( V_2 ) ;
} while ( ( V_2 = V_68 ) );
return V_60 ;
}
static T_3 F_58 ( void )
{
return F_59 ( 4 )
+ F_59 ( 0 )
+ F_59 ( 8 )
+ F_59 ( 4 )
+ F_59 ( 4 )
+ F_59 ( 1 )
+ F_59 ( 1 )
+ F_59 ( 0 )
+ F_59 ( 0 )
+ F_59 ( 4 )
+ F_59 ( 4 )
+ F_59 ( 12 )
+ F_59 ( 2 )
+ F_59 ( 4 )
+ F_59 ( 0 )
+ F_59 ( 2 )
+ F_59 ( 40 )
+ F_59 ( 2 )
+ F_59 ( 28 ) ;
}
static T_3 F_60 ( const struct V_1 * V_2 ,
const struct V_76 * V_51 )
{
T_3 V_77 = F_61 ( sizeof( struct V_78 ) )
+ F_59 ( V_2 -> V_79 )
+ F_59 ( F_58 () ) ;
if ( V_51 )
V_77 += F_62 ( V_51 -> V_80 ) ;
return V_77 ;
}
static int F_53 ( struct V_14 * V_14 , int V_15 ,
struct V_1 * V_2 ,
const struct V_47 * V_59 )
{
struct V_78 * V_48 ;
struct V_1 * V_68 = NULL ;
struct V_1 * V_81 ;
struct V_76 * V_82 ;
int V_60 ;
if ( F_63 ( V_2 ) ) {
V_68 = F_64 ( V_2 , V_83 ) ;
if ( ! V_68 )
return - V_84 ;
V_68 = F_65 ( V_68 , V_68 -> V_85 , F_66 ( V_68 ) ) ;
if ( ! V_68 )
return - V_84 ;
V_68 -> V_86 = 0 ;
V_2 = V_68 ;
}
if ( F_67 ( V_2 -> V_79 ) > V_87 ) {
V_60 = - V_88 ;
goto V_55;
}
V_81 = F_68 ( F_60 ( V_2 , V_59 -> V_51 ) , V_83 ) ;
if ( ! V_81 ) {
V_60 = - V_84 ;
goto V_55;
}
V_48 = F_69 ( V_81 , 0 , 0 , & V_89 ,
0 , V_59 -> V_49 ) ;
V_48 -> V_15 = V_15 ;
V_82 = F_70 ( V_81 , V_90 ) ;
F_71 ( V_59 -> V_45 , V_59 -> V_45 , V_81 ) ;
F_72 ( V_81 , V_82 ) ;
if ( V_59 -> V_51 )
F_73 ( V_81 , V_91 ,
V_80 ( V_59 -> V_51 ) ,
F_74 ( V_59 -> V_51 ) ) ;
V_82 = F_75 ( V_81 , V_92 , V_2 -> V_79 ) ;
F_76 ( V_2 , F_74 ( V_82 ) ) ;
F_77 ( V_81 , V_48 ) ;
V_60 = F_78 ( V_14 , V_81 , V_59 -> V_52 ) ;
V_55:
F_42 ( V_68 ) ;
return V_60 ;
}
static int F_79 ( struct V_13 * V_16 )
{
struct V_28 * V_93 ;
struct V_28 * V_94 ;
V_93 = F_80 ( V_16 -> V_29 ) ;
V_94 = F_81 ( V_95 ) ;
if ( ! V_94 )
return - V_84 ;
F_82 ( V_16 -> V_29 , V_94 ) ;
F_22 ( V_93 , true ) ;
return 0 ;
}
static struct V_76 * F_83 ( struct V_96 * * V_97 , int V_98 )
{
struct V_96 * V_99 ;
int V_100 ;
int V_101 = F_62 ( V_98 ) ;
int V_102 = F_84 ( struct V_96 , V_103 ) +
( * V_97 ) -> V_104 ;
if ( V_101 <= ( F_85 ( * V_97 ) - V_102 ) )
goto V_55;
V_100 = F_85 ( * V_97 ) * 2 ;
if ( V_100 > V_105 ) {
if ( ( V_105 - V_102 ) < V_101 )
return F_86 ( - V_106 ) ;
V_100 = V_105 ;
}
V_99 = F_87 ( V_100 ) ;
if ( F_32 ( V_99 ) )
return ( void * ) V_99 ;
memcpy ( V_99 -> V_103 , ( * V_97 ) -> V_103 , ( * V_97 ) -> V_104 ) ;
V_99 -> V_104 = ( * V_97 ) -> V_104 ;
F_26 ( * V_97 ) ;
* V_97 = V_99 ;
V_55:
( * V_97 ) -> V_104 += V_101 ;
return (struct V_76 * ) ( ( unsigned char * ) ( * V_97 ) + V_102 ) ;
}
static int F_88 ( struct V_96 * * V_97 , int V_107 , void * V_108 , int V_79 )
{
struct V_76 * V_109 ;
V_109 = F_83 ( V_97 , F_67 ( V_79 ) ) ;
if ( F_32 ( V_109 ) )
return F_57 ( V_109 ) ;
V_109 -> V_110 = V_107 ;
V_109 -> V_80 = F_67 ( V_79 ) ;
if ( V_108 )
memcpy ( F_74 ( V_109 ) , V_108 , V_79 ) ;
memset ( ( unsigned char * ) V_109 + V_109 -> V_80 , 0 , F_89 ( V_79 ) ) ;
return 0 ;
}
static inline int F_90 ( struct V_96 * * V_97 , int V_107 )
{
int V_111 = ( * V_97 ) -> V_104 ;
int V_60 ;
V_60 = F_88 ( V_97 , V_107 , NULL , 0 ) ;
if ( V_60 )
return V_60 ;
return V_111 ;
}
static inline void F_91 ( struct V_96 * V_97 , int V_112 )
{
struct V_76 * V_109 = (struct V_76 * ) ( ( unsigned char * ) V_97 -> V_103 + V_112 ) ;
V_109 -> V_80 = V_97 -> V_104 - V_112 ;
}
static int F_92 ( const struct V_76 * V_113 ,
const struct V_44 * V_45 , int V_114 ,
struct V_96 * * V_97 )
{
const struct V_76 * V_115 [ V_116 + 1 ] ;
const struct V_76 * V_117 , * V_103 ;
const struct V_76 * V_109 ;
int V_118 , V_119 , V_60 , V_120 ;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
F_93 (a, attr, rem) {
int type = V_110 ( V_109 ) ;
if ( ! type || type > V_116 || V_115 [ type ] )
return - V_121 ;
V_115 [ type ] = V_109 ;
}
if ( V_118 )
return - V_121 ;
V_117 = V_115 [ V_122 ] ;
if ( ! V_117 || V_80 ( V_117 ) != sizeof( V_123 ) )
return - V_121 ;
V_103 = V_115 [ V_124 ] ;
if ( ! V_103 || ( V_80 ( V_103 ) && V_80 ( V_103 ) < V_125 ) )
return - V_121 ;
V_119 = F_90 ( V_97 , V_126 ) ;
if ( V_119 < 0 )
return V_119 ;
V_60 = F_88 ( V_97 , V_122 , F_74 ( V_117 ) , sizeof( V_123 ) ) ;
if ( V_60 )
return V_60 ;
V_120 = F_90 ( V_97 , V_124 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 = F_94 ( V_103 , V_45 , V_114 + 1 , V_97 ) ;
if ( V_60 )
return V_60 ;
F_91 ( * V_97 , V_120 ) ;
F_91 ( * V_97 , V_119 ) ;
return 0 ;
}
static int F_95 ( const struct V_44 * V_127 )
{
if ( V_127 -> V_128 . type == F_96 ( V_129 ) ) {
if ( V_127 -> V_130 . V_131 . V_132 || V_127 -> V_130 . V_131 . V_133 )
return 0 ;
} else if ( V_127 -> V_128 . type == F_96 ( V_134 ) ) {
if ( V_127 -> V_135 . V_131 . V_132 || V_127 -> V_135 . V_131 . V_133 )
return 0 ;
}
return - V_121 ;
}
static int F_97 ( const struct V_76 * V_113 ,
struct V_96 * * V_97 )
{
struct V_136 V_137 ;
struct V_44 V_45 ;
int V_60 , V_119 ;
F_98 ( & V_137 , & V_45 , NULL ) ;
V_60 = F_99 ( F_74 ( V_113 ) , & V_137 , false ) ;
if ( V_60 )
return V_60 ;
V_119 = F_90 ( V_97 , V_138 ) ;
if ( V_119 < 0 )
return V_119 ;
V_60 = F_88 ( V_97 , V_139 , & V_137 . V_45 -> V_140 ,
sizeof( V_137 . V_45 -> V_140 ) ) ;
F_91 ( * V_97 , V_119 ) ;
return V_60 ;
}
static int F_100 ( const struct V_76 * V_109 ,
const struct V_44 * V_127 ,
struct V_96 * * V_97 ,
bool * V_141 )
{
const struct V_76 * V_142 = F_74 ( V_109 ) ;
int V_143 = V_110 ( V_142 ) ;
if ( F_59 ( V_80 ( V_142 ) ) != V_80 ( V_109 ) )
return - V_121 ;
if ( V_143 > V_144 ||
( V_145 [ V_143 ] != V_80 ( V_142 ) &&
V_145 [ V_143 ] != - 1 ) )
return - V_121 ;
switch ( V_143 ) {
const struct V_146 * V_147 ;
const struct V_148 * V_149 ;
int V_60 ;
case V_150 :
case V_151 :
case V_152 :
break;
case V_153 :
* V_141 = true ;
V_60 = F_97 ( V_109 , V_97 ) ;
if ( V_60 )
return V_60 ;
break;
case V_154 :
if ( V_127 -> V_128 . type != F_96 ( V_129 ) )
return - V_121 ;
if ( ! V_127 -> V_72 . V_155 )
return - V_121 ;
V_147 = F_74 ( V_142 ) ;
if ( V_147 -> V_156 != V_127 -> V_72 . V_155 )
return - V_121 ;
if ( V_147 -> V_157 != V_127 -> V_72 . V_73 )
return - V_121 ;
break;
case V_158 :
if ( V_127 -> V_128 . type != F_96 ( V_134 ) )
return - V_121 ;
if ( ! V_127 -> V_72 . V_155 )
return - V_121 ;
V_149 = F_74 ( V_142 ) ;
if ( V_149 -> V_159 != V_127 -> V_72 . V_155 )
return - V_121 ;
if ( V_149 -> V_160 != V_127 -> V_72 . V_73 )
return - V_121 ;
if ( F_101 ( V_149 -> V_161 ) & 0xFFF00000 )
return - V_121 ;
break;
case V_162 :
if ( V_127 -> V_72 . V_155 != V_163 )
return - V_121 ;
return F_95 ( V_127 ) ;
case V_164 :
if ( V_127 -> V_72 . V_155 != V_165 )
return - V_121 ;
return F_95 ( V_127 ) ;
case V_166 :
if ( V_127 -> V_72 . V_155 != V_167 )
return - V_121 ;
return F_95 ( V_127 ) ;
default:
return - V_121 ;
}
return 0 ;
}
static int F_102 ( const struct V_76 * V_113 )
{
static const struct V_168 V_169 [ V_170 + 1 ] = {
[ V_171 ] = { . type = V_172 } ,
[ V_173 ] = { . type = V_174 } ,
} ;
struct V_76 * V_109 [ V_170 + 1 ] ;
int error ;
error = F_103 ( V_109 , V_170 ,
V_113 , V_169 ) ;
if ( error )
return error ;
if ( ! V_109 [ V_171 ] ||
! F_104 ( V_109 [ V_171 ] ) )
return - V_121 ;
return 0 ;
}
static int F_105 ( const struct V_76 * V_175 ,
struct V_96 * * V_97 )
{
int V_176 = F_62 ( V_175 -> V_80 ) ;
struct V_76 * V_177 ;
V_177 = F_83 ( V_97 , V_175 -> V_80 ) ;
if ( F_32 ( V_177 ) )
return F_57 ( V_177 ) ;
memcpy ( V_177 , V_175 , V_176 ) ;
return 0 ;
}
static int F_94 ( const struct V_76 * V_113 ,
const struct V_44 * V_45 ,
int V_114 ,
struct V_96 * * V_97 )
{
const struct V_76 * V_109 ;
int V_118 , V_60 ;
if ( V_114 >= V_178 )
return - V_179 ;
F_93 (a, attr, rem) {
static const V_123 V_180 [ V_181 + 1 ] = {
[ V_182 ] = sizeof( V_123 ) ,
[ V_183 ] = ( V_123 ) - 1 ,
[ V_184 ] = sizeof( struct V_185 ) ,
[ V_186 ] = 0 ,
[ V_138 ] = ( V_123 ) - 1 ,
[ V_126 ] = ( V_123 ) - 1
} ;
const struct V_185 * V_187 ;
int type = V_110 ( V_109 ) ;
bool V_188 ;
if ( type > V_181 ||
( V_180 [ type ] != V_80 ( V_109 ) &&
V_180 [ type ] != ( V_123 ) - 1 ) )
return - V_121 ;
V_188 = false ;
switch ( type ) {
case V_189 :
return - V_121 ;
case V_183 :
V_60 = F_102 ( V_109 ) ;
if ( V_60 )
return V_60 ;
break;
case V_182 :
if ( F_104 ( V_109 ) >= V_190 )
return - V_121 ;
break;
case V_186 :
break;
case V_184 :
V_187 = F_74 ( V_109 ) ;
if ( V_187 -> V_191 != F_96 ( V_192 ) )
return - V_121 ;
if ( ! ( V_187 -> V_86 & F_96 ( V_193 ) ) )
return - V_121 ;
break;
case V_138 :
V_60 = F_100 ( V_109 , V_45 , V_97 , & V_188 ) ;
if ( V_60 )
return V_60 ;
break;
case V_126 :
V_60 = F_92 ( V_109 , V_45 , V_114 , V_97 ) ;
if ( V_60 )
return V_60 ;
V_188 = true ;
break;
default:
return - V_121 ;
}
if ( ! V_188 ) {
V_60 = F_105 ( V_109 , V_97 ) ;
if ( V_60 )
return V_60 ;
}
}
if ( V_118 > 0 )
return - V_121 ;
return 0 ;
}
static void F_106 ( struct V_40 * V_41 )
{
V_41 -> V_111 = 0 ;
V_41 -> V_194 = 0 ;
V_41 -> V_195 = 0 ;
V_41 -> V_196 = 0 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_96 * V_99 ;
struct V_1 * V_198 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_199 * V_128 ;
int V_79 ;
int V_60 ;
V_60 = - V_121 ;
if ( ! V_109 [ V_92 ] || ! V_109 [ V_90 ] ||
! V_109 [ V_200 ] )
goto V_60;
V_79 = V_80 ( V_109 [ V_92 ] ) ;
V_198 = F_108 ( V_201 + V_79 , V_10 ) ;
V_60 = - V_84 ;
if ( ! V_198 )
goto V_60;
F_109 ( V_198 , V_201 ) ;
F_110 ( F_111 ( V_198 , V_79 ) , V_109 [ V_92 ] , V_79 ) ;
F_112 ( V_198 ) ;
V_128 = F_113 ( V_198 ) ;
if ( F_114 ( V_128 -> V_202 ) >= V_203 )
V_198 -> V_204 = V_128 -> V_202 ;
else
V_198 -> V_204 = F_96 ( V_205 ) ;
V_41 = F_115 () ;
V_60 = F_57 ( V_41 ) ;
if ( F_32 ( V_41 ) )
goto V_206;
V_60 = F_40 ( V_198 , - 1 , & V_41 -> V_45 ) ;
if ( V_60 )
goto V_207;
V_60 = F_116 ( V_41 , V_109 [ V_90 ] ) ;
if ( V_60 )
goto V_207;
V_99 = F_87 ( V_80 ( V_109 [ V_200 ] ) ) ;
V_60 = F_57 ( V_99 ) ;
if ( F_32 ( V_99 ) )
goto V_207;
V_60 = F_94 ( V_109 [ V_200 ] , & V_41 -> V_45 , 0 , & V_99 ) ;
F_82 ( V_41 -> V_208 , V_99 ) ;
if ( V_60 )
goto V_207;
F_47 ( V_198 ) -> V_41 = V_41 ;
F_47 ( V_198 ) -> V_56 = & V_41 -> V_45 ;
V_198 -> V_209 = V_41 -> V_45 . V_210 . V_209 ;
V_198 -> V_211 = V_41 -> V_45 . V_210 . V_212 ;
F_11 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
V_60 = - V_62 ;
if ( ! V_16 )
goto V_214;
F_118 () ;
V_60 = F_49 ( V_16 , V_198 ) ;
F_119 () ;
F_14 () ;
F_120 ( V_41 , false ) ;
return V_60 ;
V_214:
F_14 () ;
V_207:
F_120 ( V_41 , false ) ;
V_206:
F_42 ( V_198 ) ;
V_60:
return V_60 ;
}
static void F_121 ( struct V_13 * V_16 , struct V_215 * V_43 )
{
struct V_28 * V_29 ;
int V_216 ;
V_29 = F_122 ( V_16 -> V_29 , F_8 () ) ;
V_43 -> V_217 = F_123 ( V_29 ) ;
V_43 -> V_57 = V_43 -> V_54 = V_43 -> V_63 = 0 ;
F_124 (i) {
const struct V_42 * V_218 ;
struct V_42 V_219 ;
unsigned int V_119 ;
V_218 = F_125 ( V_16 -> V_30 , V_216 ) ;
do {
V_119 = F_126 ( & V_218 -> V_58 ) ;
V_219 = * V_218 ;
} while ( F_127 ( & V_218 -> V_58 , V_119 ) );
V_43 -> V_57 += V_219 . V_57 ;
V_43 -> V_54 += V_219 . V_54 ;
V_43 -> V_63 += V_219 . V_63 ;
}
}
static int F_128 ( const struct V_76 * V_113 , struct V_1 * V_2 )
{
const struct V_76 * V_109 ;
struct V_76 * V_119 ;
int V_60 = 0 , V_118 ;
V_119 = F_70 ( V_2 , V_126 ) ;
if ( ! V_119 )
return - V_106 ;
F_93 (a, attr, rem) {
int type = V_110 ( V_109 ) ;
struct V_76 * V_220 ;
switch ( type ) {
case V_122 :
if ( F_129 ( V_2 , V_122 , sizeof( V_123 ) , F_74 ( V_109 ) ) )
return - V_106 ;
break;
case V_124 :
V_220 = F_70 ( V_2 , V_124 ) ;
if ( ! V_220 )
return - V_106 ;
V_60 = F_130 ( F_74 ( V_109 ) , V_80 ( V_109 ) , V_2 ) ;
if ( V_60 )
return V_60 ;
F_72 ( V_2 , V_220 ) ;
break;
}
}
F_72 ( V_2 , V_119 ) ;
return V_60 ;
}
static int F_131 ( const struct V_76 * V_109 , struct V_1 * V_2 )
{
const struct V_76 * V_142 = F_74 ( V_109 ) ;
int V_143 = V_110 ( V_142 ) ;
struct V_76 * V_119 ;
int V_60 ;
switch ( V_143 ) {
case V_139 :
V_119 = F_70 ( V_2 , V_138 ) ;
if ( ! V_119 )
return - V_106 ;
V_60 = F_132 ( V_2 , F_74 ( V_142 ) ,
F_74 ( V_142 ) ) ;
if ( V_60 )
return V_60 ;
F_72 ( V_2 , V_119 ) ;
break;
default:
if ( F_129 ( V_2 , V_138 , V_80 ( V_109 ) , V_142 ) )
return - V_106 ;
break;
}
return 0 ;
}
static int F_130 ( const struct V_76 * V_113 , int V_79 , struct V_1 * V_2 )
{
const struct V_76 * V_109 ;
int V_118 , V_60 ;
F_133 (a, attr, len, rem) {
int type = V_110 ( V_109 ) ;
switch ( type ) {
case V_138 :
V_60 = F_131 ( V_109 , V_2 ) ;
if ( V_60 )
return V_60 ;
break;
case V_126 :
V_60 = F_128 ( V_109 , V_2 ) ;
if ( V_60 )
return V_60 ;
break;
default:
if ( F_129 ( V_2 , type , V_80 ( V_109 ) , F_74 ( V_109 ) ) )
return - V_106 ;
break;
}
}
return 0 ;
}
static T_3 F_134 ( const struct V_96 * V_99 )
{
return F_61 ( sizeof( struct V_78 ) )
+ F_59 ( F_58 () )
+ F_59 ( F_58 () )
+ F_59 ( sizeof( struct V_221 ) )
+ F_59 ( 1 )
+ F_59 ( 8 )
+ F_59 ( V_99 -> V_104 ) ;
}
static int F_135 ( struct V_40 * V_41 , struct V_13 * V_16 ,
struct V_1 * V_2 , V_123 V_52 ,
V_123 V_222 , V_123 V_223 , T_4 V_49 )
{
const int V_224 = V_2 -> V_79 ;
struct V_76 * V_119 ;
struct V_221 V_43 ;
struct V_78 * V_78 ;
struct V_76 * V_82 ;
unsigned long V_111 ;
T_4 V_194 ;
int V_60 ;
V_78 = F_69 ( V_2 , V_52 , V_222 , & V_225 , V_223 , V_49 ) ;
if ( ! V_78 )
return - V_106 ;
V_78 -> V_15 = F_17 ( V_16 ) ;
V_82 = F_70 ( V_2 , V_226 ) ;
if ( ! V_82 )
goto V_227;
V_60 = F_71 ( & V_41 -> V_228 ,
& V_41 -> V_228 , V_2 ) ;
if ( V_60 )
goto error;
F_72 ( V_2 , V_82 ) ;
V_82 = F_70 ( V_2 , V_229 ) ;
if ( ! V_82 )
goto V_227;
V_60 = F_71 ( & V_41 -> V_45 , & V_41 -> V_230 -> V_45 , V_2 ) ;
if ( V_60 )
goto error;
F_72 ( V_2 , V_82 ) ;
F_136 ( & V_41 -> V_231 ) ;
V_111 = V_41 -> V_111 ;
V_43 . V_232 = V_41 -> V_195 ;
V_43 . V_233 = V_41 -> V_196 ;
V_194 = V_41 -> V_194 ;
F_137 ( & V_41 -> V_231 ) ;
if ( V_111 &&
F_138 ( V_2 , V_234 , F_139 ( V_111 ) ) )
goto V_227;
if ( V_43 . V_232 &&
F_129 ( V_2 , V_235 ,
sizeof( struct V_221 ) , & V_43 ) )
goto V_227;
if ( V_194 &&
F_140 ( V_2 , V_236 , V_194 ) )
goto V_227;
V_119 = F_70 ( V_2 , V_237 ) ;
if ( V_119 ) {
const struct V_96 * V_208 ;
V_208 = F_122 ( V_41 -> V_208 ,
F_8 () ) ;
V_60 = F_130 ( V_208 -> V_103 , V_208 -> V_104 , V_2 ) ;
if ( ! V_60 )
F_72 ( V_2 , V_119 ) ;
else {
if ( V_224 )
goto error;
F_141 ( V_2 , V_119 ) ;
}
} else if ( V_224 )
goto V_227;
return F_77 ( V_2 , V_78 ) ;
V_227:
V_60 = - V_106 ;
error:
F_142 ( V_2 , V_78 ) ;
return V_60 ;
}
static struct V_1 * F_143 ( struct V_40 * V_41 )
{
const struct V_96 * V_208 ;
V_208 = F_80 ( V_41 -> V_208 ) ;
return F_68 ( F_134 ( V_208 ) , V_10 ) ;
}
static struct V_1 * F_144 ( struct V_40 * V_41 ,
struct V_13 * V_16 ,
V_123 V_52 , V_123 V_222 , T_4 V_49 )
{
struct V_1 * V_2 ;
int V_238 ;
V_2 = F_143 ( V_41 ) ;
if ( ! V_2 )
return F_86 ( - V_84 ) ;
V_238 = F_135 ( V_41 , V_16 , V_2 , V_52 , V_222 , 0 , V_49 ) ;
F_145 ( V_238 < 0 ) ;
return V_2 ;
}
static int F_146 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_44 V_45 , V_239 ;
struct V_40 * V_41 = NULL ;
struct V_240 V_230 ;
struct V_1 * V_241 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
struct V_96 * V_99 = NULL ;
struct V_136 V_137 ;
int error ;
error = - V_121 ;
if ( ! V_109 [ V_226 ] )
goto error;
F_98 ( & V_137 , & V_45 , & V_230 ) ;
error = F_147 ( & V_137 ,
V_109 [ V_226 ] , V_109 [ V_229 ] ) ;
if ( error )
goto error;
if ( V_109 [ V_237 ] ) {
V_99 = F_87 ( V_80 ( V_109 [ V_237 ] ) ) ;
error = F_57 ( V_99 ) ;
if ( F_32 ( V_99 ) )
goto error;
F_148 ( & V_239 , & V_45 , & V_230 ) ;
error = F_94 ( V_109 [ V_237 ] ,
& V_239 , 0 , & V_99 ) ;
if ( error ) {
F_149 ( L_1 ) ;
goto V_242;
}
} else if ( V_4 -> V_243 -> V_49 == V_244 ) {
error = - V_121 ;
goto error;
}
F_4 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
error = - V_62 ;
if ( ! V_16 )
goto V_245;
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_43 ( V_29 , & V_45 ) ;
if ( ! V_41 ) {
struct V_240 * V_246 ;
error = - V_247 ;
if ( V_4 -> V_243 -> V_49 == V_248 )
goto V_245;
if ( F_150 ( V_29 ) ) {
struct V_28 * V_94 ;
V_94 = F_151 ( V_29 ) ;
if ( ! F_32 ( V_94 ) ) {
F_82 ( V_16 -> V_29 , V_94 ) ;
F_22 ( V_29 , true ) ;
V_29 = F_80 ( V_16 -> V_29 ) ;
}
}
V_41 = F_115 () ;
if ( F_32 ( V_41 ) ) {
error = F_57 ( V_41 ) ;
goto V_245;
}
F_106 ( V_41 ) ;
V_41 -> V_45 = V_239 ;
V_41 -> V_228 = V_45 ;
V_246 = F_152 ( V_29 , & V_230 ) ;
if ( ! V_246 ) {
V_246 = F_153 () ;
if ( ! V_246 )
goto V_207;
V_246 -> V_45 = V_230 . V_45 ;
V_246 -> V_249 = V_230 . V_249 ;
F_154 ( V_29 , V_246 ) ;
}
F_155 ( V_246 ) ;
V_41 -> V_230 = V_246 ;
F_82 ( V_41 -> V_208 , V_99 ) ;
F_156 ( V_29 , V_41 ) ;
V_241 = F_144 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_244 ) ;
} else {
struct V_96 * V_251 ;
error = - V_252 ;
if ( V_4 -> V_243 -> V_49 == V_244 &&
V_4 -> V_9 -> V_253 & ( V_254 | V_255 ) )
goto V_245;
error = - V_121 ;
if ( ! F_157 ( V_41 , & V_45 , V_137 . V_249 . V_256 ) ) {
F_149 ( L_2 ) ;
goto V_245;
}
V_251 = F_80 ( V_41 -> V_208 ) ;
F_82 ( V_41 -> V_208 , V_99 ) ;
F_158 ( V_251 ) ;
V_241 = F_144 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_244 ) ;
if ( V_109 [ V_257 ] ) {
F_136 ( & V_41 -> V_231 ) ;
F_106 ( V_41 ) ;
F_137 ( & V_41 -> V_231 ) ;
}
}
F_6 () ;
if ( ! F_32 ( V_241 ) )
F_1 ( V_241 , V_4 , & V_258 ) ;
else
F_159 ( F_117 ( V_2 -> V_213 ) -> V_259 , 0 ,
V_258 . V_8 , F_57 ( V_241 ) ) ;
return 0 ;
V_207:
F_120 ( V_41 , false ) ;
V_245:
F_6 () ;
V_242:
F_26 ( V_99 ) ;
error:
return error ;
}
static int F_160 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_44 V_45 ;
struct V_1 * V_241 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
struct V_136 V_137 ;
int V_60 ;
if ( ! V_109 [ V_226 ] ) {
F_149 ( L_3 ) ;
return - V_121 ;
}
F_98 ( & V_137 , & V_45 , NULL ) ;
V_60 = F_147 ( & V_137 , V_109 [ V_226 ] , NULL ) ;
if ( V_60 )
return V_60 ;
F_4 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
V_60 = - V_62 ;
goto V_260;
}
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_161 ( V_29 , & V_137 ) ;
if ( ! V_41 ) {
V_60 = - V_247 ;
goto V_260;
}
V_241 = F_144 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_244 ) ;
if ( F_32 ( V_241 ) ) {
V_60 = F_57 ( V_241 ) ;
goto V_260;
}
F_6 () ;
return F_162 ( V_241 , V_4 ) ;
V_260:
F_6 () ;
return V_60 ;
}
static int F_163 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_44 V_45 ;
struct V_1 * V_241 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
struct V_136 V_137 ;
int V_60 ;
F_4 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
V_60 = - V_62 ;
goto V_260;
}
if ( ! V_109 [ V_226 ] ) {
V_60 = F_79 ( V_16 ) ;
goto V_260;
}
F_98 ( & V_137 , & V_45 , NULL ) ;
V_60 = F_147 ( & V_137 , V_109 [ V_226 ] , NULL ) ;
if ( V_60 )
goto V_260;
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_161 ( V_29 , & V_137 ) ;
if ( ! V_41 ) {
V_60 = - V_247 ;
goto V_260;
}
V_241 = F_143 ( V_41 ) ;
if ( ! V_241 ) {
V_60 = - V_84 ;
goto V_260;
}
F_164 ( V_29 , V_41 ) ;
V_60 = F_135 ( V_41 , V_16 , V_241 , V_4 -> V_7 ,
V_4 -> V_250 , 0 , V_261 ) ;
F_145 ( V_60 < 0 ) ;
F_120 ( V_41 , true ) ;
F_6 () ;
F_1 ( V_241 , V_4 , & V_258 ) ;
return 0 ;
V_260:
F_6 () ;
return V_60 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_262 * V_263 )
{
struct V_78 * V_78 = F_166 ( F_167 ( V_263 -> V_264 ) ) ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
F_11 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
F_14 () ;
return - V_62 ;
}
V_29 = F_44 ( V_16 -> V_29 ) ;
for (; ; ) {
struct V_40 * V_41 ;
V_123 V_265 , V_266 ;
V_265 = V_263 -> args [ 0 ] ;
V_266 = V_263 -> args [ 1 ] ;
V_41 = F_168 ( V_29 , & V_265 , & V_266 ) ;
if ( ! V_41 )
break;
if ( F_135 ( V_41 , V_16 , V_2 ,
F_169 ( V_263 -> V_2 ) . V_52 ,
V_263 -> V_264 -> V_267 , V_268 ,
V_244 ) < 0 )
break;
V_263 -> args [ 0 ] = V_265 ;
V_263 -> args [ 1 ] = V_266 ;
}
F_14 () ;
return V_2 -> V_79 ;
}
static T_3 F_170 ( void )
{
T_3 V_269 = F_61 ( sizeof( struct V_78 ) ) ;
V_269 += F_59 ( V_270 ) ;
V_269 += F_59 ( sizeof( struct V_215 ) ) ;
return V_269 ;
}
static int F_171 ( struct V_13 * V_16 , struct V_1 * V_2 ,
V_123 V_52 , V_123 V_222 , V_123 V_223 , T_4 V_49 )
{
struct V_78 * V_78 ;
struct V_215 V_271 ;
int V_60 ;
V_78 = F_69 ( V_2 , V_52 , V_222 , & V_272 ,
V_223 , V_49 ) ;
if ( ! V_78 )
goto error;
V_78 -> V_15 = F_17 ( V_16 ) ;
F_11 () ;
V_60 = F_172 ( V_2 , V_273 , F_15 ( V_16 ) ) ;
F_14 () ;
if ( V_60 )
goto V_227;
F_121 ( V_16 , & V_271 ) ;
if ( F_129 ( V_2 , V_274 , sizeof( struct V_215 ) , & V_271 ) )
goto V_227;
return F_77 ( V_2 , V_78 ) ;
V_227:
F_142 ( V_2 , V_78 ) ;
error:
return - V_106 ;
}
static struct V_1 * F_173 ( struct V_13 * V_16 , V_123 V_52 ,
V_123 V_222 , T_4 V_49 )
{
struct V_1 * V_2 ;
int V_238 ;
V_2 = F_68 ( F_170 () , V_10 ) ;
if ( ! V_2 )
return F_86 ( - V_84 ) ;
V_238 = F_171 ( V_16 , V_2 , V_52 , V_222 , 0 , V_49 ) ;
if ( V_238 < 0 ) {
F_42 ( V_2 ) ;
return F_86 ( V_238 ) ;
}
return V_2 ;
}
static struct V_13 * F_174 ( struct V_14 * V_14 ,
struct V_78 * V_78 ,
struct V_76 * V_109 [ V_275 + 1 ] )
{
struct V_13 * V_16 ;
if ( ! V_109 [ V_273 ] )
V_16 = F_10 ( V_14 , V_78 -> V_15 ) ;
else {
struct V_19 * V_19 ;
F_11 () ;
V_19 = F_175 ( V_14 , F_74 ( V_109 [ V_273 ] ) ) ;
V_16 = V_19 && V_19 -> V_33 == V_20 ? V_19 -> V_16 : NULL ;
F_14 () ;
}
return V_16 ? V_16 : F_86 ( - V_62 ) ;
}
static int F_176 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_36 V_37 ;
struct V_1 * V_241 ;
struct V_13 * V_16 ;
struct V_19 * V_19 ;
struct V_276 * V_276 ;
int V_60 , V_216 ;
V_60 = - V_121 ;
if ( ! V_109 [ V_273 ] || ! V_109 [ V_277 ] )
goto V_60;
F_4 () ;
V_60 = - V_84 ;
V_16 = F_177 ( sizeof( * V_16 ) , V_10 ) ;
if ( V_16 == NULL )
goto V_245;
F_178 ( V_16 , F_179 ( F_117 ( V_2 -> V_213 ) ) ) ;
V_60 = - V_84 ;
F_82 ( V_16 -> V_29 , F_81 ( V_95 ) ) ;
if ( ! V_16 -> V_29 )
goto V_278;
V_16 -> V_30 = F_180 ( struct V_42 ) ;
if ( ! V_16 -> V_30 ) {
V_60 = - V_84 ;
goto V_279;
}
V_16 -> V_31 = F_181 ( V_34 * sizeof( struct V_32 ) ,
V_10 ) ;
if ( ! V_16 -> V_31 ) {
V_60 = - V_84 ;
goto V_280;
}
for ( V_216 = 0 ; V_216 < V_34 ; V_216 ++ )
F_182 ( & V_16 -> V_31 [ V_216 ] ) ;
V_37 . V_281 = F_74 ( V_109 [ V_273 ] ) ;
V_37 . type = V_282 ;
V_37 . V_283 = NULL ;
V_37 . V_16 = V_16 ;
V_37 . V_33 = V_20 ;
V_37 . V_53 = F_104 ( V_109 [ V_277 ] ) ;
V_19 = F_30 ( & V_37 ) ;
if ( F_32 ( V_19 ) ) {
V_60 = F_57 ( V_19 ) ;
if ( V_60 == - V_284 )
V_60 = - V_252 ;
goto V_285;
}
V_241 = F_173 ( V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_286 ) ;
V_60 = F_57 ( V_241 ) ;
if ( F_32 ( V_241 ) )
goto V_287;
V_276 = F_183 ( F_25 ( V_16 ) , V_288 ) ;
F_184 ( & V_16 -> V_289 , & V_276 -> V_290 ) ;
F_6 () ;
F_1 ( V_241 , V_4 , & V_291 ) ;
return 0 ;
V_287:
F_34 ( F_185 ( V_16 , V_20 ) ) ;
V_285:
F_26 ( V_16 -> V_31 ) ;
V_280:
F_23 ( V_16 -> V_30 ) ;
V_279:
F_22 ( F_80 ( V_16 -> V_29 ) , false ) ;
V_278:
F_24 ( F_25 ( V_16 ) ) ;
F_26 ( V_16 ) ;
V_245:
F_6 () ;
V_60:
return V_60 ;
}
static void F_186 ( struct V_13 * V_16 )
{
int V_216 ;
for ( V_216 = 0 ; V_216 < V_34 ; V_216 ++ ) {
struct V_19 * V_19 ;
struct V_292 * V_293 ;
F_187 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_33 != V_20 )
F_34 ( V_19 ) ;
}
F_188 ( & V_16 -> V_289 ) ;
F_34 ( F_185 ( V_16 , V_20 ) ) ;
F_189 ( & V_16 -> V_26 , F_20 ) ;
}
static int F_190 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_241 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_174 ( F_117 ( V_2 -> V_213 ) , V_4 -> V_197 , V_4 -> V_115 ) ;
V_60 = F_57 ( V_16 ) ;
if ( F_32 ( V_16 ) )
goto V_260;
V_241 = F_173 ( V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_294 ) ;
V_60 = F_57 ( V_241 ) ;
if ( F_32 ( V_241 ) )
goto V_260;
F_186 ( V_16 ) ;
F_6 () ;
F_1 ( V_241 , V_4 , & V_291 ) ;
return 0 ;
V_260:
F_6 () ;
return V_60 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_241 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_174 ( F_117 ( V_2 -> V_213 ) , V_4 -> V_197 , V_4 -> V_115 ) ;
V_60 = F_57 ( V_16 ) ;
if ( F_32 ( V_16 ) )
goto V_260;
V_241 = F_173 ( V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_286 ) ;
if ( F_32 ( V_241 ) ) {
V_60 = F_57 ( V_241 ) ;
F_159 ( F_117 ( V_2 -> V_213 ) -> V_259 , 0 ,
V_291 . V_8 , V_60 ) ;
V_60 = 0 ;
goto V_260;
}
F_6 () ;
F_1 ( V_241 , V_4 , & V_291 ) ;
return 0 ;
V_260:
F_6 () ;
return V_60 ;
}
static int F_192 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_241 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_174 ( F_117 ( V_2 -> V_213 ) , V_4 -> V_197 , V_4 -> V_115 ) ;
if ( F_32 ( V_16 ) ) {
V_60 = F_57 ( V_16 ) ;
goto V_260;
}
V_241 = F_173 ( V_16 , V_4 -> V_7 ,
V_4 -> V_250 , V_286 ) ;
if ( F_32 ( V_241 ) ) {
V_60 = F_57 ( V_241 ) ;
goto V_260;
}
F_6 () ;
return F_162 ( V_241 , V_4 ) ;
V_260:
F_6 () ;
return V_60 ;
}
static int F_193 ( struct V_1 * V_2 , struct V_262 * V_263 )
{
struct V_276 * V_276 = F_183 ( F_117 ( V_2 -> V_213 ) , V_288 ) ;
struct V_13 * V_16 ;
int V_295 = V_263 -> args [ 0 ] ;
int V_216 = 0 ;
F_11 () ;
F_194 (dp, &ovs_net->dps, list_node) {
if ( V_216 >= V_295 &&
F_171 ( V_16 , V_2 , F_169 ( V_263 -> V_2 ) . V_52 ,
V_263 -> V_264 -> V_267 , V_268 ,
V_286 ) < 0 )
break;
V_216 ++ ;
}
F_14 () ;
V_263 -> args [ 0 ] = V_216 ;
return V_2 -> V_79 ;
}
static int F_195 ( struct V_19 * V_19 , struct V_1 * V_2 ,
V_123 V_52 , V_123 V_222 , V_123 V_223 , T_4 V_49 )
{
struct V_78 * V_78 ;
struct V_296 V_297 ;
int V_60 ;
V_78 = F_69 ( V_2 , V_52 , V_222 , & V_298 ,
V_223 , V_49 ) ;
if ( ! V_78 )
return - V_106 ;
V_78 -> V_15 = F_17 ( V_19 -> V_16 ) ;
if ( F_196 ( V_2 , V_299 , V_19 -> V_33 ) ||
F_196 ( V_2 , V_300 , V_19 -> V_21 -> type ) ||
F_172 ( V_2 , V_301 , V_19 -> V_21 -> V_22 ( V_19 ) ) ||
F_196 ( V_2 , V_302 , V_19 -> V_53 ) )
goto V_227;
F_197 ( V_19 , & V_297 ) ;
if ( F_129 ( V_2 , V_303 , sizeof( struct V_296 ) ,
& V_297 ) )
goto V_227;
V_60 = F_198 ( V_19 , V_2 ) ;
if ( V_60 == - V_106 )
goto error;
return F_77 ( V_2 , V_78 ) ;
V_227:
V_60 = - V_106 ;
error:
F_142 ( V_2 , V_78 ) ;
return V_60 ;
}
struct V_1 * F_199 ( struct V_19 * V_19 , V_123 V_52 ,
V_123 V_222 , T_4 V_49 )
{
struct V_1 * V_2 ;
int V_238 ;
V_2 = F_200 ( V_304 , V_83 ) ;
if ( ! V_2 )
return F_86 ( - V_84 ) ;
V_238 = F_195 ( V_19 , V_2 , V_52 , V_222 , 0 , V_49 ) ;
F_145 ( V_238 < 0 ) ;
return V_2 ;
}
static struct V_19 * F_201 ( struct V_14 * V_14 ,
struct V_78 * V_78 ,
struct V_76 * V_109 [ V_305 + 1 ] )
{
struct V_13 * V_16 ;
struct V_19 * V_19 ;
if ( V_109 [ V_301 ] ) {
V_19 = F_175 ( V_14 , F_74 ( V_109 [ V_301 ] ) ) ;
if ( ! V_19 )
return F_86 ( - V_62 ) ;
if ( V_78 -> V_15 &&
V_78 -> V_15 != F_17 ( V_19 -> V_16 ) )
return F_86 ( - V_62 ) ;
return V_19 ;
} else if ( V_109 [ V_299 ] ) {
V_123 V_33 = F_104 ( V_109 [ V_299 ] ) ;
if ( V_33 >= V_190 )
return F_86 ( - V_88 ) ;
V_16 = F_10 ( V_14 , V_78 -> V_15 ) ;
if ( ! V_16 )
return F_86 ( - V_62 ) ;
V_19 = F_16 ( V_16 , V_33 ) ;
if ( ! V_19 )
return F_86 ( - V_62 ) ;
return V_19 ;
} else
return F_86 ( - V_121 ) ;
}
static int F_202 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_36 V_37 ;
struct V_1 * V_241 ;
struct V_19 * V_19 ;
struct V_13 * V_16 ;
V_123 V_33 ;
int V_60 ;
V_60 = - V_121 ;
if ( ! V_109 [ V_301 ] || ! V_109 [ V_300 ] ||
! V_109 [ V_302 ] )
goto exit;
F_4 () ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
V_60 = - V_62 ;
if ( ! V_16 )
goto V_306;
if ( V_109 [ V_299 ] ) {
V_33 = F_104 ( V_109 [ V_299 ] ) ;
V_60 = - V_88 ;
if ( V_33 >= V_190 )
goto V_306;
V_19 = F_185 ( V_16 , V_33 ) ;
V_60 = - V_284 ;
if ( V_19 )
goto V_306;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_190 ) {
V_60 = - V_88 ;
goto V_306;
}
V_19 = F_185 ( V_16 , V_33 ) ;
if ( ! V_19 )
break;
}
}
V_37 . V_281 = F_74 ( V_109 [ V_301 ] ) ;
V_37 . type = F_104 ( V_109 [ V_300 ] ) ;
V_37 . V_283 = V_109 [ V_307 ] ;
V_37 . V_16 = V_16 ;
V_37 . V_33 = V_33 ;
V_37 . V_53 = F_104 ( V_109 [ V_302 ] ) ;
V_19 = F_30 ( & V_37 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_306;
V_60 = 0 ;
V_241 = F_199 ( V_19 , V_4 -> V_7 , V_4 -> V_250 ,
V_308 ) ;
if ( F_32 ( V_241 ) ) {
V_60 = F_57 ( V_241 ) ;
F_34 ( V_19 ) ;
goto V_306;
}
F_1 ( V_241 , V_4 , & V_309 ) ;
V_306:
F_6 () ;
exit:
return V_60 ;
}
static int F_203 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_1 * V_241 ;
struct V_19 * V_19 ;
int V_60 ;
F_4 () ;
V_19 = F_201 ( F_117 ( V_2 -> V_213 ) , V_4 -> V_197 , V_109 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_306;
if ( V_109 [ V_300 ] &&
F_104 ( V_109 [ V_300 ] ) != V_19 -> V_21 -> type ) {
V_60 = - V_121 ;
goto V_306;
}
V_241 = F_200 ( V_304 , V_10 ) ;
if ( ! V_241 ) {
V_60 = - V_84 ;
goto V_306;
}
if ( V_109 [ V_307 ] ) {
V_60 = F_204 ( V_19 , V_109 [ V_307 ] ) ;
if ( V_60 )
goto V_310;
}
if ( V_109 [ V_302 ] )
V_19 -> V_53 = F_104 ( V_109 [ V_302 ] ) ;
V_60 = F_195 ( V_19 , V_241 , V_4 -> V_7 ,
V_4 -> V_250 , 0 , V_308 ) ;
F_145 ( V_60 < 0 ) ;
F_6 () ;
F_1 ( V_241 , V_4 , & V_309 ) ;
return 0 ;
V_310:
F_42 ( V_241 ) ;
V_306:
F_6 () ;
return V_60 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_1 * V_241 ;
struct V_19 * V_19 ;
int V_60 ;
F_4 () ;
V_19 = F_201 ( F_117 ( V_2 -> V_213 ) , V_4 -> V_197 , V_109 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_306;
if ( V_19 -> V_33 == V_20 ) {
V_60 = - V_121 ;
goto V_306;
}
V_241 = F_199 ( V_19 , V_4 -> V_7 ,
V_4 -> V_250 , V_311 ) ;
V_60 = F_57 ( V_241 ) ;
if ( F_32 ( V_241 ) )
goto V_306;
V_60 = 0 ;
F_34 ( V_19 ) ;
F_1 ( V_241 , V_4 , & V_309 ) ;
V_306:
F_6 () ;
return V_60 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_109 = V_4 -> V_115 ;
struct V_78 * V_78 = V_4 -> V_197 ;
struct V_1 * V_241 ;
struct V_19 * V_19 ;
int V_60 ;
F_11 () ;
V_19 = F_201 ( F_117 ( V_2 -> V_213 ) , V_78 , V_109 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_306;
V_241 = F_199 ( V_19 , V_4 -> V_7 ,
V_4 -> V_250 , V_308 ) ;
V_60 = F_57 ( V_241 ) ;
if ( F_32 ( V_241 ) )
goto V_306;
F_14 () ;
return F_162 ( V_241 , V_4 ) ;
V_306:
F_14 () ;
return V_60 ;
}
static int F_207 ( struct V_1 * V_2 , struct V_262 * V_263 )
{
struct V_78 * V_78 = F_166 ( F_167 ( V_263 -> V_264 ) ) ;
struct V_13 * V_16 ;
int V_265 = V_263 -> args [ 0 ] , V_295 = V_263 -> args [ 1 ] ;
int V_216 , V_312 = 0 ;
V_16 = F_10 ( F_117 ( V_2 -> V_213 ) , V_78 -> V_15 ) ;
if ( ! V_16 )
return - V_62 ;
F_11 () ;
for ( V_216 = V_265 ; V_216 < V_34 ; V_216 ++ ) {
struct V_19 * V_19 ;
V_312 = 0 ;
F_29 (vport, &dp->ports[i], dp_hash_node) {
if ( V_312 >= V_295 &&
F_195 ( V_19 , V_2 ,
F_169 ( V_263 -> V_2 ) . V_52 ,
V_263 -> V_264 -> V_267 ,
V_268 ,
V_308 ) < 0 )
goto V_55;
V_312 ++ ;
}
V_295 = 0 ;
}
V_55:
F_14 () ;
V_263 -> args [ 0 ] = V_216 ;
V_263 -> args [ 1 ] = V_312 ;
return V_2 -> V_79 ;
}
static void F_208 ( int V_313 )
{
int V_216 ;
for ( V_216 = 0 ; V_216 < V_313 ; V_216 ++ )
F_209 ( V_314 [ V_216 ] . V_315 ) ;
}
static int F_210 ( void )
{
int V_316 ;
int V_60 ;
int V_216 ;
V_316 = 0 ;
for ( V_216 = 0 ; V_216 < F_211 ( V_314 ) ; V_216 ++ ) {
const struct V_317 * V_318 = & V_314 [ V_216 ] ;
V_60 = F_212 ( V_318 -> V_315 , V_318 -> V_21 ,
V_318 -> V_319 ) ;
if ( V_60 )
goto error;
V_316 ++ ;
if ( V_318 -> V_320 ) {
V_60 = F_213 ( V_318 -> V_315 , V_318 -> V_320 ) ;
if ( V_60 )
goto error;
}
}
return 0 ;
error:
F_208 ( V_316 ) ;
return V_60 ;
}
static void F_214 ( struct V_321 * V_322 )
{
struct V_13 * V_16 ;
struct V_14 * V_14 ;
F_4 () ;
F_215 () ;
F_216 (net) {
struct V_276 * V_276 = F_183 ( V_14 , V_288 ) ;
F_217 (dp, &ovs_net->dps, list_node) {
struct V_28 * V_93 = F_80 ( V_16 -> V_29 ) ;
struct V_28 * V_94 ;
V_94 = F_218 ( V_93 ) ;
if ( ! F_32 ( V_94 ) ) {
F_82 ( V_16 -> V_29 , V_94 ) ;
F_22 ( V_93 , true ) ;
}
}
}
F_219 () ;
F_6 () ;
F_220 ( & V_323 , V_324 ) ;
}
static int T_5 F_221 ( struct V_14 * V_14 )
{
struct V_276 * V_276 = F_183 ( V_14 , V_288 ) ;
F_222 ( & V_276 -> V_290 ) ;
F_223 ( & V_276 -> V_325 , V_326 ) ;
return 0 ;
}
static void T_6 F_224 ( struct V_14 * V_14 )
{
struct V_13 * V_16 , * V_327 ;
struct V_276 * V_276 = F_183 ( V_14 , V_288 ) ;
F_4 () ;
F_225 (dp, dp_next, &ovs_net->dps, list_node)
F_186 ( V_16 ) ;
F_6 () ;
F_226 ( & V_276 -> V_325 ) ;
}
static int T_7 F_227 ( void )
{
int V_60 ;
F_228 ( sizeof( struct V_328 ) > F_229 ( struct V_1 , V_263 ) ) ;
F_230 ( L_4 ) ;
V_60 = F_231 () ;
if ( V_60 )
goto error;
V_60 = F_232 () ;
if ( V_60 )
goto V_329;
V_60 = F_233 ( & V_330 ) ;
if ( V_60 )
goto V_331;
V_60 = F_234 ( & V_332 ) ;
if ( V_60 )
goto V_333;
V_60 = F_210 () ;
if ( V_60 < 0 )
goto V_334;
F_220 ( & V_323 , V_324 ) ;
return 0 ;
V_334:
F_235 ( & V_332 ) ;
V_333:
F_236 ( & V_330 ) ;
V_331:
F_237 () ;
V_329:
F_238 () ;
error:
return V_60 ;
}
static void F_239 ( void )
{
F_240 ( & V_323 ) ;
F_208 ( F_211 ( V_314 ) ) ;
F_235 ( & V_332 ) ;
F_236 ( & V_330 ) ;
F_241 () ;
F_237 () ;
F_238 () ;
}
