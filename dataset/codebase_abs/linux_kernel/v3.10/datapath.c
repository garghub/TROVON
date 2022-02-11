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
F_22 ( ( V_27 struct V_28 * ) V_16 -> V_29 ) ;
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
int V_47 ;
V_43 = F_39 ( V_16 -> V_30 ) ;
error = F_40 ( V_2 , V_39 -> V_33 , & V_45 , & V_47 ) ;
if ( F_41 ( error ) ) {
F_42 ( V_2 ) ;
return;
}
V_41 = F_43 ( F_44 ( V_16 -> V_29 ) , & V_45 , V_47 ) ;
if ( F_41 ( ! V_41 ) ) {
struct V_48 V_49 ;
V_49 . V_50 = V_51 ;
V_49 . V_45 = & V_45 ;
V_49 . V_52 = NULL ;
V_49 . V_53 = V_39 -> V_54 ;
F_45 ( V_16 , V_2 , & V_49 ) ;
F_46 ( V_2 ) ;
V_46 = & V_43 -> V_55 ;
goto V_56;
}
F_47 ( V_2 ) -> V_41 = V_41 ;
V_46 = & V_43 -> V_57 ;
F_48 ( F_47 ( V_2 ) -> V_41 , V_2 ) ;
F_49 ( V_16 , V_2 ) ;
V_56:
F_50 ( & V_43 -> V_58 ) ;
( * V_46 ) ++ ;
F_51 ( & V_43 -> V_58 ) ;
}
int F_45 ( struct V_13 * V_16 , struct V_1 * V_2 ,
const struct V_48 * V_59 )
{
struct V_42 * V_43 ;
int V_15 ;
int V_60 ;
if ( V_59 -> V_53 == 0 ) {
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
const struct V_48 * V_59 )
{
unsigned short V_64 = F_55 ( V_2 ) -> V_64 ;
struct V_48 V_65 ;
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
const struct V_76 * V_52 )
{
T_3 V_77 = F_61 ( sizeof( struct V_78 ) )
+ F_59 ( V_2 -> V_79 )
+ F_59 ( F_58 () ) ;
if ( V_52 )
V_77 += F_62 ( V_52 -> V_80 ) ;
return V_77 ;
}
static int F_53 ( struct V_14 * V_14 , int V_15 ,
struct V_1 * V_2 ,
const struct V_48 * V_59 )
{
struct V_78 * V_49 ;
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
goto V_56;
}
V_81 = F_68 ( F_60 ( V_2 , V_59 -> V_52 ) , V_83 ) ;
if ( ! V_81 ) {
V_60 = - V_84 ;
goto V_56;
}
V_49 = F_69 ( V_81 , 0 , 0 , & V_89 ,
0 , V_59 -> V_50 ) ;
V_49 -> V_15 = V_15 ;
V_82 = F_70 ( V_81 , V_90 ) ;
F_71 ( V_59 -> V_45 , V_81 ) ;
F_72 ( V_81 , V_82 ) ;
if ( V_59 -> V_52 )
F_73 ( V_81 , V_91 ,
V_80 ( V_59 -> V_52 ) ,
F_74 ( V_59 -> V_52 ) ) ;
V_82 = F_75 ( V_81 , V_92 , V_2 -> V_79 ) ;
F_76 ( V_2 , F_74 ( V_82 ) ) ;
F_77 ( V_81 , V_49 ) ;
V_60 = F_78 ( V_14 , V_81 , V_59 -> V_53 ) ;
V_56:
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
F_83 ( V_93 ) ;
return 0 ;
}
static int F_84 ( const struct V_76 * V_96 ,
const struct V_44 * V_45 , int V_97 )
{
const struct V_76 * V_98 [ V_99 + 1 ] ;
const struct V_76 * V_100 , * V_101 ;
const struct V_76 * V_102 ;
int V_103 ;
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
F_85 (a, attr, rem) {
int type = F_86 ( V_102 ) ;
if ( ! type || type > V_99 || V_98 [ type ] )
return - V_104 ;
V_98 [ type ] = V_102 ;
}
if ( V_103 )
return - V_104 ;
V_100 = V_98 [ V_105 ] ;
if ( ! V_100 || V_80 ( V_100 ) != sizeof( V_106 ) )
return - V_104 ;
V_101 = V_98 [ V_107 ] ;
if ( ! V_101 || ( V_80 ( V_101 ) && V_80 ( V_101 ) < V_108 ) )
return - V_104 ;
return F_87 ( V_101 , V_45 , V_97 + 1 ) ;
}
static int F_88 ( const struct V_44 * V_109 )
{
if ( V_109 -> V_110 . type == F_89 ( V_111 ) ) {
if ( V_109 -> V_112 . V_113 . V_114 || V_109 -> V_112 . V_113 . V_115 )
return 0 ;
} else if ( V_109 -> V_110 . type == F_89 ( V_116 ) ) {
if ( V_109 -> V_117 . V_113 . V_114 || V_109 -> V_117 . V_113 . V_115 )
return 0 ;
}
return - V_104 ;
}
static int F_90 ( const struct V_76 * V_102 ,
const struct V_44 * V_109 )
{
const struct V_76 * V_118 = F_74 ( V_102 ) ;
int V_119 = F_86 ( V_118 ) ;
if ( F_59 ( V_80 ( V_118 ) ) != V_80 ( V_102 ) )
return - V_104 ;
if ( V_119 > V_120 ||
V_80 ( V_118 ) != V_121 [ V_119 ] )
return - V_104 ;
switch ( V_119 ) {
const struct V_122 * V_123 ;
const struct V_124 * V_125 ;
case V_126 :
case V_127 :
case V_128 :
break;
case V_129 :
if ( V_109 -> V_110 . type != F_89 ( V_111 ) )
return - V_104 ;
if ( ! V_109 -> V_72 . V_130 )
return - V_104 ;
V_123 = F_74 ( V_118 ) ;
if ( V_123 -> V_131 != V_109 -> V_72 . V_130 )
return - V_104 ;
if ( V_123 -> V_132 != V_109 -> V_72 . V_73 )
return - V_104 ;
break;
case V_133 :
if ( V_109 -> V_110 . type != F_89 ( V_116 ) )
return - V_104 ;
if ( ! V_109 -> V_72 . V_130 )
return - V_104 ;
V_125 = F_74 ( V_118 ) ;
if ( V_125 -> V_134 != V_109 -> V_72 . V_130 )
return - V_104 ;
if ( V_125 -> V_135 != V_109 -> V_72 . V_73 )
return - V_104 ;
if ( F_91 ( V_125 -> V_136 ) & 0xFFF00000 )
return - V_104 ;
break;
case V_137 :
if ( V_109 -> V_72 . V_130 != V_138 )
return - V_104 ;
return F_88 ( V_109 ) ;
case V_139 :
if ( V_109 -> V_72 . V_130 != V_140 )
return - V_104 ;
return F_88 ( V_109 ) ;
default:
return - V_104 ;
}
return 0 ;
}
static int F_92 ( const struct V_76 * V_96 )
{
static const struct V_141 V_142 [ V_143 + 1 ] = {
[ V_144 ] = { . type = V_145 } ,
[ V_146 ] = { . type = V_147 } ,
} ;
struct V_76 * V_102 [ V_143 + 1 ] ;
int error ;
error = F_93 ( V_102 , V_143 ,
V_96 , V_142 ) ;
if ( error )
return error ;
if ( ! V_102 [ V_144 ] ||
! F_94 ( V_102 [ V_144 ] ) )
return - V_104 ;
return 0 ;
}
static int F_87 ( const struct V_76 * V_96 ,
const struct V_44 * V_45 , int V_97 )
{
const struct V_76 * V_102 ;
int V_103 , V_60 ;
if ( V_97 >= V_148 )
return - V_149 ;
F_85 (a, attr, rem) {
static const V_106 V_150 [ V_151 + 1 ] = {
[ V_152 ] = sizeof( V_106 ) ,
[ V_153 ] = ( V_106 ) - 1 ,
[ V_154 ] = sizeof( struct V_155 ) ,
[ V_156 ] = 0 ,
[ V_157 ] = ( V_106 ) - 1 ,
[ V_158 ] = ( V_106 ) - 1
} ;
const struct V_155 * V_159 ;
int type = F_86 ( V_102 ) ;
if ( type > V_151 ||
( V_150 [ type ] != V_80 ( V_102 ) &&
V_150 [ type ] != ( V_106 ) - 1 ) )
return - V_104 ;
switch ( type ) {
case V_160 :
return - V_104 ;
case V_153 :
V_60 = F_92 ( V_102 ) ;
if ( V_60 )
return V_60 ;
break;
case V_152 :
if ( F_94 ( V_102 ) >= V_161 )
return - V_104 ;
break;
case V_156 :
break;
case V_154 :
V_159 = F_74 ( V_102 ) ;
if ( V_159 -> V_162 != F_89 ( V_163 ) )
return - V_104 ;
if ( ! ( V_159 -> V_86 & F_89 ( V_164 ) ) )
return - V_104 ;
break;
case V_157 :
V_60 = F_90 ( V_102 , V_45 ) ;
if ( V_60 )
return V_60 ;
break;
case V_158 :
V_60 = F_84 ( V_102 , V_45 , V_97 ) ;
if ( V_60 )
return V_60 ;
break;
default:
return - V_104 ;
}
}
if ( V_103 > 0 )
return - V_104 ;
return 0 ;
}
static void F_95 ( struct V_40 * V_41 )
{
V_41 -> V_165 = 0 ;
V_41 -> V_166 = 0 ;
V_41 -> V_167 = 0 ;
V_41 -> V_168 = 0 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_170 * V_171 ;
struct V_1 * V_172 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_173 * V_110 ;
int V_79 ;
int V_60 ;
int V_47 ;
V_60 = - V_104 ;
if ( ! V_102 [ V_92 ] || ! V_102 [ V_90 ] ||
! V_102 [ V_174 ] )
goto V_60;
V_79 = V_80 ( V_102 [ V_92 ] ) ;
V_172 = F_97 ( V_175 + V_79 , V_10 ) ;
V_60 = - V_84 ;
if ( ! V_172 )
goto V_60;
F_98 ( V_172 , V_175 ) ;
F_99 ( F_100 ( V_172 , V_79 ) , V_102 [ V_92 ] , V_79 ) ;
F_101 ( V_172 ) ;
V_110 = F_102 ( V_172 ) ;
if ( F_103 ( V_110 -> V_176 ) >= V_177 )
V_172 -> V_178 = V_110 -> V_176 ;
else
V_172 -> V_178 = F_89 ( V_179 ) ;
V_41 = F_104 () ;
V_60 = F_57 ( V_41 ) ;
if ( F_32 ( V_41 ) )
goto V_180;
V_60 = F_40 ( V_172 , - 1 , & V_41 -> V_45 , & V_47 ) ;
if ( V_60 )
goto V_181;
V_60 = F_105 ( & V_41 -> V_45 . V_182 . V_183 ,
& V_41 -> V_45 . V_182 . V_184 ,
& V_41 -> V_45 . V_182 . V_185 ,
V_102 [ V_90 ] ) ;
if ( V_60 )
goto V_181;
V_60 = F_87 ( V_102 [ V_174 ] , & V_41 -> V_45 , 0 ) ;
if ( V_60 )
goto V_181;
V_41 -> V_186 = F_106 ( & V_41 -> V_45 , V_47 ) ;
V_171 = F_107 ( V_102 [ V_174 ] ) ;
V_60 = F_57 ( V_171 ) ;
if ( F_32 ( V_171 ) )
goto V_181;
F_82 ( V_41 -> V_187 , V_171 ) ;
F_47 ( V_172 ) -> V_41 = V_41 ;
V_172 -> V_183 = V_41 -> V_45 . V_182 . V_183 ;
V_172 -> V_188 = V_41 -> V_45 . V_182 . V_184 ;
F_11 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
V_60 = - V_62 ;
if ( ! V_16 )
goto V_190;
F_109 () ;
V_60 = F_49 ( V_16 , V_172 ) ;
F_110 () ;
F_14 () ;
F_111 ( V_41 ) ;
return V_60 ;
V_190:
F_14 () ;
V_181:
F_111 ( V_41 ) ;
V_180:
F_42 ( V_172 ) ;
V_60:
return V_60 ;
}
static void F_112 ( struct V_13 * V_16 , struct V_191 * V_43 )
{
int V_192 ;
struct V_28 * V_29 = F_80 ( V_16 -> V_29 ) ;
V_43 -> V_193 = F_113 ( V_29 ) ;
V_43 -> V_57 = V_43 -> V_55 = V_43 -> V_63 = 0 ;
F_114 (i) {
const struct V_42 * V_194 ;
struct V_42 V_195 ;
unsigned int V_196 ;
V_194 = F_115 ( V_16 -> V_30 , V_192 ) ;
do {
V_196 = F_116 ( & V_194 -> V_58 ) ;
V_195 = * V_194 ;
} while ( F_117 ( & V_194 -> V_58 , V_196 ) );
V_43 -> V_57 += V_195 . V_57 ;
V_43 -> V_55 += V_195 . V_55 ;
V_43 -> V_63 += V_195 . V_63 ;
}
}
static T_3 F_118 ( const struct V_170 * V_171 )
{
return F_61 ( sizeof( struct V_78 ) )
+ F_59 ( F_58 () )
+ F_59 ( sizeof( struct V_197 ) )
+ F_59 ( 1 )
+ F_59 ( 8 )
+ F_59 ( V_171 -> V_198 ) ;
}
static int F_119 ( struct V_40 * V_41 , struct V_13 * V_16 ,
struct V_1 * V_2 , V_106 V_53 ,
V_106 V_199 , V_106 V_200 , T_4 V_50 )
{
const int V_201 = V_2 -> V_79 ;
const struct V_170 * V_187 ;
struct V_197 V_43 ;
struct V_78 * V_78 ;
struct V_76 * V_82 ;
unsigned long V_165 ;
T_4 V_166 ;
int V_60 ;
V_187 = F_80 ( V_41 -> V_187 ) ;
V_78 = F_69 ( V_2 , V_53 , V_199 , & V_202 , V_200 , V_50 ) ;
if ( ! V_78 )
return - V_203 ;
V_78 -> V_15 = F_17 ( V_16 ) ;
V_82 = F_70 ( V_2 , V_204 ) ;
if ( ! V_82 )
goto V_205;
V_60 = F_71 ( & V_41 -> V_45 , V_2 ) ;
if ( V_60 )
goto error;
F_72 ( V_2 , V_82 ) ;
F_120 ( & V_41 -> V_206 ) ;
V_165 = V_41 -> V_165 ;
V_43 . V_207 = V_41 -> V_167 ;
V_43 . V_208 = V_41 -> V_168 ;
V_166 = V_41 -> V_166 ;
F_121 ( & V_41 -> V_206 ) ;
if ( V_165 &&
F_122 ( V_2 , V_209 , F_123 ( V_165 ) ) )
goto V_205;
if ( V_43 . V_207 &&
F_124 ( V_2 , V_210 ,
sizeof( struct V_197 ) , & V_43 ) )
goto V_205;
if ( V_166 &&
F_125 ( V_2 , V_211 , V_166 ) )
goto V_205;
V_60 = F_124 ( V_2 , V_212 , V_187 -> V_198 ,
V_187 -> V_101 ) ;
if ( V_60 < 0 && V_201 )
goto error;
return F_77 ( V_2 , V_78 ) ;
V_205:
V_60 = - V_203 ;
error:
F_126 ( V_2 , V_78 ) ;
return V_60 ;
}
static struct V_1 * F_127 ( struct V_40 * V_41 )
{
const struct V_170 * V_187 ;
V_187 = F_80 ( V_41 -> V_187 ) ;
return F_68 ( F_118 ( V_187 ) , V_10 ) ;
}
static struct V_1 * F_128 ( struct V_40 * V_41 ,
struct V_13 * V_16 ,
V_106 V_53 , V_106 V_199 , T_4 V_50 )
{
struct V_1 * V_2 ;
int V_213 ;
V_2 = F_127 ( V_41 ) ;
if ( ! V_2 )
return F_129 ( - V_84 ) ;
V_213 = F_119 ( V_41 , V_16 , V_2 , V_53 , V_199 , 0 , V_50 ) ;
F_130 ( V_213 < 0 ) ;
return V_2 ;
}
static int F_131 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_44 V_45 ;
struct V_40 * V_41 ;
struct V_1 * V_214 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
int error ;
int V_47 ;
error = - V_104 ;
if ( ! V_102 [ V_204 ] )
goto error;
error = F_132 ( & V_45 , & V_47 , V_102 [ V_204 ] ) ;
if ( error )
goto error;
if ( V_102 [ V_212 ] ) {
error = F_87 ( V_102 [ V_212 ] , & V_45 , 0 ) ;
if ( error )
goto error;
} else if ( V_4 -> V_215 -> V_50 == V_216 ) {
error = - V_104 ;
goto error;
}
F_4 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
error = - V_62 ;
if ( ! V_16 )
goto V_217;
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_43 ( V_29 , & V_45 , V_47 ) ;
if ( ! V_41 ) {
struct V_170 * V_171 ;
error = - V_218 ;
if ( V_4 -> V_215 -> V_50 == V_219 )
goto V_217;
if ( F_133 ( V_29 ) ) {
struct V_28 * V_94 ;
V_94 = F_134 ( V_29 ) ;
if ( ! F_32 ( V_94 ) ) {
F_82 ( V_16 -> V_29 , V_94 ) ;
F_83 ( V_29 ) ;
V_29 = F_80 ( V_16 -> V_29 ) ;
}
}
V_41 = F_104 () ;
if ( F_32 ( V_41 ) ) {
error = F_57 ( V_41 ) ;
goto V_217;
}
V_41 -> V_45 = V_45 ;
F_95 ( V_41 ) ;
V_171 = F_107 ( V_102 [ V_212 ] ) ;
error = F_57 ( V_171 ) ;
if ( F_32 ( V_171 ) )
goto V_220;
F_82 ( V_41 -> V_187 , V_171 ) ;
V_41 -> V_186 = F_106 ( & V_45 , V_47 ) ;
F_135 ( V_29 , V_41 ) ;
V_214 = F_128 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_221 ,
V_216 ) ;
} else {
struct V_170 * V_222 ;
struct V_76 * V_223 ;
error = - V_224 ;
if ( V_4 -> V_215 -> V_50 == V_216 &&
V_4 -> V_9 -> V_225 & ( V_226 | V_227 ) )
goto V_217;
V_222 = F_80 ( V_41 -> V_187 ) ;
V_223 = V_102 [ V_212 ] ;
if ( V_223 &&
( V_222 -> V_198 != V_80 ( V_223 ) ||
memcmp ( V_222 -> V_101 , F_74 ( V_223 ) ,
V_222 -> V_198 ) ) ) {
struct V_170 * V_228 ;
V_228 = F_107 ( V_223 ) ;
error = F_57 ( V_228 ) ;
if ( F_32 ( V_228 ) )
goto V_217;
F_82 ( V_41 -> V_187 , V_228 ) ;
F_136 ( V_222 ) ;
}
V_214 = F_128 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_216 ) ;
if ( V_102 [ V_229 ] ) {
F_120 ( & V_41 -> V_206 ) ;
F_95 ( V_41 ) ;
F_121 ( & V_41 -> V_206 ) ;
}
}
F_6 () ;
if ( ! F_32 ( V_214 ) )
F_1 ( V_214 , V_4 , & V_230 ) ;
else
F_137 ( F_108 ( V_2 -> V_189 ) -> V_231 , 0 ,
V_230 . V_8 , F_57 ( V_214 ) ) ;
return 0 ;
V_220:
F_111 ( V_41 ) ;
V_217:
F_6 () ;
error:
return error ;
}
static int F_138 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_44 V_45 ;
struct V_1 * V_214 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
int V_60 ;
int V_47 ;
if ( ! V_102 [ V_204 ] )
return - V_104 ;
V_60 = F_132 ( & V_45 , & V_47 , V_102 [ V_204 ] ) ;
if ( V_60 )
return V_60 ;
F_4 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
V_60 = - V_62 ;
goto V_232;
}
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_43 ( V_29 , & V_45 , V_47 ) ;
if ( ! V_41 ) {
V_60 = - V_218 ;
goto V_232;
}
V_214 = F_128 ( V_41 , V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_216 ) ;
if ( F_32 ( V_214 ) ) {
V_60 = F_57 ( V_214 ) ;
goto V_232;
}
F_6 () ;
return F_139 ( V_214 , V_4 ) ;
V_232:
F_6 () ;
return V_60 ;
}
static int F_140 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_44 V_45 ;
struct V_1 * V_214 ;
struct V_40 * V_41 ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
int V_60 ;
int V_47 ;
F_4 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
V_60 = - V_62 ;
goto V_232;
}
if ( ! V_102 [ V_204 ] ) {
V_60 = F_79 ( V_16 ) ;
goto V_232;
}
V_60 = F_132 ( & V_45 , & V_47 , V_102 [ V_204 ] ) ;
if ( V_60 )
goto V_232;
V_29 = F_80 ( V_16 -> V_29 ) ;
V_41 = F_43 ( V_29 , & V_45 , V_47 ) ;
if ( ! V_41 ) {
V_60 = - V_218 ;
goto V_232;
}
V_214 = F_127 ( V_41 ) ;
if ( ! V_214 ) {
V_60 = - V_84 ;
goto V_232;
}
F_141 ( V_29 , V_41 ) ;
V_60 = F_119 ( V_41 , V_16 , V_214 , V_4 -> V_7 ,
V_4 -> V_221 , 0 , V_233 ) ;
F_130 ( V_60 < 0 ) ;
F_142 ( V_41 ) ;
F_6 () ;
F_1 ( V_214 , V_4 , & V_230 ) ;
return 0 ;
V_232:
F_6 () ;
return V_60 ;
}
static int F_143 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_78 * V_78 = F_144 ( F_145 ( V_235 -> V_236 ) ) ;
struct V_13 * V_16 ;
struct V_28 * V_29 ;
F_4 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
if ( ! V_16 ) {
F_6 () ;
return - V_62 ;
}
V_29 = F_80 ( V_16 -> V_29 ) ;
for (; ; ) {
struct V_40 * V_41 ;
V_106 V_237 , V_238 ;
V_237 = V_235 -> args [ 0 ] ;
V_238 = V_235 -> args [ 1 ] ;
V_41 = F_146 ( V_29 , & V_237 , & V_238 ) ;
if ( ! V_41 )
break;
if ( F_119 ( V_41 , V_16 , V_2 ,
F_147 ( V_235 -> V_2 ) . V_53 ,
V_235 -> V_236 -> V_239 , V_240 ,
V_216 ) < 0 )
break;
V_235 -> args [ 0 ] = V_237 ;
V_235 -> args [ 1 ] = V_238 ;
}
F_6 () ;
return V_2 -> V_79 ;
}
static T_3 F_148 ( void )
{
T_3 V_241 = F_61 ( sizeof( struct V_78 ) ) ;
V_241 += F_59 ( V_242 ) ;
V_241 += F_59 ( sizeof( struct V_191 ) ) ;
return V_241 ;
}
static int F_149 ( struct V_13 * V_16 , struct V_1 * V_2 ,
V_106 V_53 , V_106 V_199 , V_106 V_200 , T_4 V_50 )
{
struct V_78 * V_78 ;
struct V_191 V_243 ;
int V_60 ;
V_78 = F_69 ( V_2 , V_53 , V_199 , & V_244 ,
V_200 , V_50 ) ;
if ( ! V_78 )
goto error;
V_78 -> V_15 = F_17 ( V_16 ) ;
F_11 () ;
V_60 = F_150 ( V_2 , V_245 , F_15 ( V_16 ) ) ;
F_14 () ;
if ( V_60 )
goto V_205;
F_112 ( V_16 , & V_243 ) ;
if ( F_124 ( V_2 , V_246 , sizeof( struct V_191 ) , & V_243 ) )
goto V_205;
return F_77 ( V_2 , V_78 ) ;
V_205:
F_126 ( V_2 , V_78 ) ;
error:
return - V_203 ;
}
static struct V_1 * F_151 ( struct V_13 * V_16 , V_106 V_53 ,
V_106 V_199 , T_4 V_50 )
{
struct V_1 * V_2 ;
int V_213 ;
V_2 = F_68 ( F_148 () , V_10 ) ;
if ( ! V_2 )
return F_129 ( - V_84 ) ;
V_213 = F_149 ( V_16 , V_2 , V_53 , V_199 , 0 , V_50 ) ;
if ( V_213 < 0 ) {
F_42 ( V_2 ) ;
return F_129 ( V_213 ) ;
}
return V_2 ;
}
static struct V_13 * F_152 ( struct V_14 * V_14 ,
struct V_78 * V_78 ,
struct V_76 * V_102 [ V_247 + 1 ] )
{
struct V_13 * V_16 ;
if ( ! V_102 [ V_245 ] )
V_16 = F_10 ( V_14 , V_78 -> V_15 ) ;
else {
struct V_19 * V_19 ;
F_11 () ;
V_19 = F_153 ( V_14 , F_74 ( V_102 [ V_245 ] ) ) ;
V_16 = V_19 && V_19 -> V_33 == V_20 ? V_19 -> V_16 : NULL ;
F_14 () ;
}
return V_16 ? V_16 : F_129 ( - V_62 ) ;
}
static int F_154 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_36 V_37 ;
struct V_1 * V_214 ;
struct V_13 * V_16 ;
struct V_19 * V_19 ;
struct V_248 * V_248 ;
int V_60 , V_192 ;
V_60 = - V_104 ;
if ( ! V_102 [ V_245 ] || ! V_102 [ V_249 ] )
goto V_60;
F_4 () ;
V_60 = - V_84 ;
V_16 = F_155 ( sizeof( * V_16 ) , V_10 ) ;
if ( V_16 == NULL )
goto V_217;
F_156 ( V_16 , F_157 ( F_108 ( V_2 -> V_189 ) ) ) ;
V_60 = - V_84 ;
F_82 ( V_16 -> V_29 , F_81 ( V_95 ) ) ;
if ( ! V_16 -> V_29 )
goto V_250;
V_16 -> V_30 = F_158 ( struct V_42 ) ;
if ( ! V_16 -> V_30 ) {
V_60 = - V_84 ;
goto V_251;
}
V_16 -> V_31 = F_159 ( V_34 * sizeof( struct V_32 ) ,
V_10 ) ;
if ( ! V_16 -> V_31 ) {
V_60 = - V_84 ;
goto V_252;
}
for ( V_192 = 0 ; V_192 < V_34 ; V_192 ++ )
F_160 ( & V_16 -> V_31 [ V_192 ] ) ;
V_37 . V_253 = F_74 ( V_102 [ V_245 ] ) ;
V_37 . type = V_254 ;
V_37 . V_255 = NULL ;
V_37 . V_16 = V_16 ;
V_37 . V_33 = V_20 ;
V_37 . V_54 = F_94 ( V_102 [ V_249 ] ) ;
V_19 = F_30 ( & V_37 ) ;
if ( F_32 ( V_19 ) ) {
V_60 = F_57 ( V_19 ) ;
if ( V_60 == - V_256 )
V_60 = - V_224 ;
goto V_257;
}
V_214 = F_151 ( V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_258 ) ;
V_60 = F_57 ( V_214 ) ;
if ( F_32 ( V_214 ) )
goto V_259;
V_248 = F_161 ( F_25 ( V_16 ) , V_260 ) ;
F_162 ( & V_16 -> V_261 , & V_248 -> V_262 ) ;
F_6 () ;
F_1 ( V_214 , V_4 , & V_263 ) ;
return 0 ;
V_259:
F_34 ( F_163 ( V_16 , V_20 ) ) ;
V_257:
F_26 ( V_16 -> V_31 ) ;
V_252:
F_23 ( V_16 -> V_30 ) ;
V_251:
F_22 ( F_80 ( V_16 -> V_29 ) ) ;
V_250:
F_24 ( F_25 ( V_16 ) ) ;
F_26 ( V_16 ) ;
V_217:
F_6 () ;
V_60:
return V_60 ;
}
static void F_164 ( struct V_13 * V_16 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_34 ; V_192 ++ ) {
struct V_19 * V_19 ;
struct V_264 * V_265 ;
F_165 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_33 != V_20 )
F_34 ( V_19 ) ;
}
F_166 ( & V_16 -> V_261 ) ;
F_34 ( F_163 ( V_16 , V_20 ) ) ;
F_167 ( & V_16 -> V_26 , F_20 ) ;
}
static int F_168 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_214 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_152 ( F_108 ( V_2 -> V_189 ) , V_4 -> V_169 , V_4 -> V_98 ) ;
V_60 = F_57 ( V_16 ) ;
if ( F_32 ( V_16 ) )
goto V_232;
V_214 = F_151 ( V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_266 ) ;
V_60 = F_57 ( V_214 ) ;
if ( F_32 ( V_214 ) )
goto V_232;
F_164 ( V_16 ) ;
F_6 () ;
F_1 ( V_214 , V_4 , & V_263 ) ;
return 0 ;
V_232:
F_6 () ;
return V_60 ;
}
static int F_169 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_214 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_152 ( F_108 ( V_2 -> V_189 ) , V_4 -> V_169 , V_4 -> V_98 ) ;
V_60 = F_57 ( V_16 ) ;
if ( F_32 ( V_16 ) )
goto V_232;
V_214 = F_151 ( V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_258 ) ;
if ( F_32 ( V_214 ) ) {
V_60 = F_57 ( V_214 ) ;
F_137 ( F_108 ( V_2 -> V_189 ) -> V_231 , 0 ,
V_263 . V_8 , V_60 ) ;
V_60 = 0 ;
goto V_232;
}
F_6 () ;
F_1 ( V_214 , V_4 , & V_263 ) ;
return 0 ;
V_232:
F_6 () ;
return V_60 ;
}
static int F_170 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_214 ;
struct V_13 * V_16 ;
int V_60 ;
F_4 () ;
V_16 = F_152 ( F_108 ( V_2 -> V_189 ) , V_4 -> V_169 , V_4 -> V_98 ) ;
if ( F_32 ( V_16 ) ) {
V_60 = F_57 ( V_16 ) ;
goto V_232;
}
V_214 = F_151 ( V_16 , V_4 -> V_7 ,
V_4 -> V_221 , V_258 ) ;
if ( F_32 ( V_214 ) ) {
V_60 = F_57 ( V_214 ) ;
goto V_232;
}
F_6 () ;
return F_139 ( V_214 , V_4 ) ;
V_232:
F_6 () ;
return V_60 ;
}
static int F_171 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_248 * V_248 = F_161 ( F_108 ( V_2 -> V_189 ) , V_260 ) ;
struct V_13 * V_16 ;
int V_267 = V_235 -> args [ 0 ] ;
int V_192 = 0 ;
F_4 () ;
F_172 (dp, &ovs_net->dps, list_node) {
if ( V_192 >= V_267 &&
F_149 ( V_16 , V_2 , F_147 ( V_235 -> V_2 ) . V_53 ,
V_235 -> V_236 -> V_239 , V_240 ,
V_258 ) < 0 )
break;
V_192 ++ ;
}
F_6 () ;
V_235 -> args [ 0 ] = V_192 ;
return V_2 -> V_79 ;
}
static int F_173 ( struct V_19 * V_19 , struct V_1 * V_2 ,
V_106 V_53 , V_106 V_199 , V_106 V_200 , T_4 V_50 )
{
struct V_78 * V_78 ;
struct V_268 V_269 ;
int V_60 ;
V_78 = F_69 ( V_2 , V_53 , V_199 , & V_270 ,
V_200 , V_50 ) ;
if ( ! V_78 )
return - V_203 ;
V_78 -> V_15 = F_17 ( V_19 -> V_16 ) ;
if ( F_174 ( V_2 , V_271 , V_19 -> V_33 ) ||
F_174 ( V_2 , V_272 , V_19 -> V_21 -> type ) ||
F_150 ( V_2 , V_273 , V_19 -> V_21 -> V_22 ( V_19 ) ) ||
F_174 ( V_2 , V_274 , V_19 -> V_54 ) )
goto V_205;
F_175 ( V_19 , & V_269 ) ;
if ( F_124 ( V_2 , V_275 , sizeof( struct V_268 ) ,
& V_269 ) )
goto V_205;
V_60 = F_176 ( V_19 , V_2 ) ;
if ( V_60 == - V_203 )
goto error;
return F_77 ( V_2 , V_78 ) ;
V_205:
V_60 = - V_203 ;
error:
F_126 ( V_2 , V_78 ) ;
return V_60 ;
}
struct V_1 * F_177 ( struct V_19 * V_19 , V_106 V_53 ,
V_106 V_199 , T_4 V_50 )
{
struct V_1 * V_2 ;
int V_213 ;
V_2 = F_178 ( V_276 , V_83 ) ;
if ( ! V_2 )
return F_129 ( - V_84 ) ;
V_213 = F_173 ( V_19 , V_2 , V_53 , V_199 , 0 , V_50 ) ;
F_130 ( V_213 < 0 ) ;
return V_2 ;
}
static struct V_19 * F_179 ( struct V_14 * V_14 ,
struct V_78 * V_78 ,
struct V_76 * V_102 [ V_277 + 1 ] )
{
struct V_13 * V_16 ;
struct V_19 * V_19 ;
if ( V_102 [ V_273 ] ) {
V_19 = F_153 ( V_14 , F_74 ( V_102 [ V_273 ] ) ) ;
if ( ! V_19 )
return F_129 ( - V_62 ) ;
if ( V_78 -> V_15 &&
V_78 -> V_15 != F_17 ( V_19 -> V_16 ) )
return F_129 ( - V_62 ) ;
return V_19 ;
} else if ( V_102 [ V_271 ] ) {
V_106 V_33 = F_94 ( V_102 [ V_271 ] ) ;
if ( V_33 >= V_161 )
return F_129 ( - V_88 ) ;
V_16 = F_10 ( V_14 , V_78 -> V_15 ) ;
if ( ! V_16 )
return F_129 ( - V_62 ) ;
V_19 = F_16 ( V_16 , V_33 ) ;
if ( ! V_19 )
return F_129 ( - V_62 ) ;
return V_19 ;
} else
return F_129 ( - V_104 ) ;
}
static int F_180 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_36 V_37 ;
struct V_1 * V_214 ;
struct V_19 * V_19 ;
struct V_13 * V_16 ;
V_106 V_33 ;
int V_60 ;
V_60 = - V_104 ;
if ( ! V_102 [ V_273 ] || ! V_102 [ V_272 ] ||
! V_102 [ V_274 ] )
goto exit;
F_4 () ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
V_60 = - V_62 ;
if ( ! V_16 )
goto V_278;
if ( V_102 [ V_271 ] ) {
V_33 = F_94 ( V_102 [ V_271 ] ) ;
V_60 = - V_88 ;
if ( V_33 >= V_161 )
goto V_278;
V_19 = F_163 ( V_16 , V_33 ) ;
V_60 = - V_256 ;
if ( V_19 )
goto V_278;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_161 ) {
V_60 = - V_88 ;
goto V_278;
}
V_19 = F_163 ( V_16 , V_33 ) ;
if ( ! V_19 )
break;
}
}
V_37 . V_253 = F_74 ( V_102 [ V_273 ] ) ;
V_37 . type = F_94 ( V_102 [ V_272 ] ) ;
V_37 . V_255 = V_102 [ V_279 ] ;
V_37 . V_16 = V_16 ;
V_37 . V_33 = V_33 ;
V_37 . V_54 = F_94 ( V_102 [ V_274 ] ) ;
V_19 = F_30 ( & V_37 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_278;
V_60 = 0 ;
V_214 = F_177 ( V_19 , V_4 -> V_7 , V_4 -> V_221 ,
V_280 ) ;
if ( F_32 ( V_214 ) ) {
V_60 = F_57 ( V_214 ) ;
F_34 ( V_19 ) ;
goto V_278;
}
F_1 ( V_214 , V_4 , & V_281 ) ;
V_278:
F_6 () ;
exit:
return V_60 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_1 * V_214 ;
struct V_19 * V_19 ;
int V_60 ;
F_4 () ;
V_19 = F_179 ( F_108 ( V_2 -> V_189 ) , V_4 -> V_169 , V_102 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_278;
V_60 = 0 ;
if ( V_102 [ V_272 ] &&
F_94 ( V_102 [ V_272 ] ) != V_19 -> V_21 -> type )
V_60 = - V_104 ;
V_214 = F_178 ( V_276 , V_10 ) ;
if ( ! V_214 ) {
V_60 = - V_84 ;
goto V_278;
}
if ( ! V_60 && V_102 [ V_279 ] )
V_60 = F_182 ( V_19 , V_102 [ V_279 ] ) ;
if ( V_60 )
goto V_282;
if ( V_102 [ V_274 ] )
V_19 -> V_54 = F_94 ( V_102 [ V_274 ] ) ;
V_60 = F_173 ( V_19 , V_214 , V_4 -> V_7 ,
V_4 -> V_221 , 0 , V_280 ) ;
F_130 ( V_60 < 0 ) ;
F_6 () ;
F_1 ( V_214 , V_4 , & V_281 ) ;
return 0 ;
F_183 () ;
return 0 ;
V_282:
F_42 ( V_214 ) ;
V_278:
F_6 () ;
return V_60 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_1 * V_214 ;
struct V_19 * V_19 ;
int V_60 ;
F_4 () ;
V_19 = F_179 ( F_108 ( V_2 -> V_189 ) , V_4 -> V_169 , V_102 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_278;
if ( V_19 -> V_33 == V_20 ) {
V_60 = - V_104 ;
goto V_278;
}
V_214 = F_177 ( V_19 , V_4 -> V_7 , V_4 -> V_221 ,
V_283 ) ;
V_60 = F_57 ( V_214 ) ;
if ( F_32 ( V_214 ) )
goto V_278;
V_60 = 0 ;
F_34 ( V_19 ) ;
F_1 ( V_214 , V_4 , & V_281 ) ;
V_278:
F_6 () ;
return V_60 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_76 * * V_102 = V_4 -> V_98 ;
struct V_78 * V_78 = V_4 -> V_169 ;
struct V_1 * V_214 ;
struct V_19 * V_19 ;
int V_60 ;
F_11 () ;
V_19 = F_179 ( F_108 ( V_2 -> V_189 ) , V_78 , V_102 ) ;
V_60 = F_57 ( V_19 ) ;
if ( F_32 ( V_19 ) )
goto V_278;
V_214 = F_177 ( V_19 , V_4 -> V_7 , V_4 -> V_221 ,
V_280 ) ;
V_60 = F_57 ( V_214 ) ;
if ( F_32 ( V_214 ) )
goto V_278;
F_14 () ;
return F_139 ( V_214 , V_4 ) ;
V_278:
F_14 () ;
return V_60 ;
}
static int F_186 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_78 * V_78 = F_144 ( F_145 ( V_235 -> V_236 ) ) ;
struct V_13 * V_16 ;
int V_237 = V_235 -> args [ 0 ] , V_267 = V_235 -> args [ 1 ] ;
int V_192 , V_284 = 0 ;
V_16 = F_10 ( F_108 ( V_2 -> V_189 ) , V_78 -> V_15 ) ;
if ( ! V_16 )
return - V_62 ;
F_11 () ;
for ( V_192 = V_237 ; V_192 < V_34 ; V_192 ++ ) {
struct V_19 * V_19 ;
V_284 = 0 ;
F_29 (vport, &dp->ports[i], dp_hash_node) {
if ( V_284 >= V_267 &&
F_173 ( V_19 , V_2 ,
F_147 ( V_235 -> V_2 ) . V_53 ,
V_235 -> V_236 -> V_239 ,
V_240 ,
V_280 ) < 0 )
goto V_56;
V_284 ++ ;
}
V_267 = 0 ;
}
V_56:
F_14 () ;
V_235 -> args [ 0 ] = V_192 ;
V_235 -> args [ 1 ] = V_284 ;
return V_2 -> V_79 ;
}
static void F_187 ( int V_285 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_285 ; V_192 ++ )
F_188 ( V_286 [ V_192 ] . V_287 ) ;
}
static int F_189 ( void )
{
int V_288 ;
int V_60 ;
int V_192 ;
V_288 = 0 ;
for ( V_192 = 0 ; V_192 < F_190 ( V_286 ) ; V_192 ++ ) {
const struct V_289 * V_290 = & V_286 [ V_192 ] ;
V_60 = F_191 ( V_290 -> V_287 , V_290 -> V_21 ,
V_290 -> V_291 ) ;
if ( V_60 )
goto error;
V_288 ++ ;
if ( V_290 -> V_292 ) {
V_60 = F_192 ( V_290 -> V_287 , V_290 -> V_292 ) ;
if ( V_60 )
goto error;
}
}
return 0 ;
error:
F_187 ( V_288 ) ;
return V_60 ;
}
static void F_193 ( struct V_293 * V_294 )
{
struct V_13 * V_16 ;
struct V_14 * V_14 ;
F_4 () ;
F_194 () ;
F_195 (net) {
struct V_248 * V_248 = F_161 ( V_14 , V_260 ) ;
F_172 (dp, &ovs_net->dps, list_node) {
struct V_28 * V_93 = F_80 ( V_16 -> V_29 ) ;
struct V_28 * V_94 ;
V_94 = F_196 ( V_93 ) ;
if ( ! F_32 ( V_94 ) ) {
F_82 ( V_16 -> V_29 , V_94 ) ;
F_83 ( V_93 ) ;
}
}
}
F_183 () ;
F_6 () ;
F_197 ( & V_295 , V_296 ) ;
}
static int T_5 F_198 ( struct V_14 * V_14 )
{
struct V_248 * V_248 = F_161 ( V_14 , V_260 ) ;
F_199 ( & V_248 -> V_262 ) ;
F_200 ( & V_248 -> V_297 , V_298 ) ;
return 0 ;
}
static void T_6 F_201 ( struct V_14 * V_14 )
{
struct V_13 * V_16 , * V_299 ;
struct V_248 * V_248 = F_161 ( V_14 , V_260 ) ;
F_4 () ;
F_202 (dp, dp_next, &ovs_net->dps, list_node)
F_164 ( V_16 ) ;
F_6 () ;
F_203 ( & V_248 -> V_297 ) ;
}
static int T_7 F_204 ( void )
{
int V_60 ;
F_205 ( sizeof( struct V_300 ) > F_206 ( struct V_1 , V_235 ) ) ;
F_207 ( L_1 ) ;
V_60 = F_208 () ;
if ( V_60 )
goto error;
V_60 = F_209 () ;
if ( V_60 )
goto V_301;
V_60 = F_210 ( & V_302 ) ;
if ( V_60 )
goto V_303;
V_60 = F_211 ( & V_304 ) ;
if ( V_60 )
goto V_305;
V_60 = F_189 () ;
if ( V_60 < 0 )
goto V_306;
F_197 ( & V_295 , V_296 ) ;
return 0 ;
V_306:
F_212 ( & V_304 ) ;
V_305:
F_213 ( & V_302 ) ;
V_303:
F_214 () ;
V_301:
F_215 () ;
error:
return V_60 ;
}
static void F_216 ( void )
{
F_217 ( & V_295 ) ;
F_187 ( F_190 ( V_286 ) ) ;
F_212 ( & V_304 ) ;
F_213 ( & V_302 ) ;
F_218 () ;
F_214 () ;
F_215 () ;
}
