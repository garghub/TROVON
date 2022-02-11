static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
F_2 () ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 ) {
struct V_7 * V_7 = F_4 ( V_6 ) ;
if ( V_7 )
V_4 = V_7 -> V_4 ;
}
F_5 () ;
return V_4 ;
}
const char * F_6 ( const struct V_1 * V_4 )
{
struct V_7 * V_7 = F_7 ( V_4 , V_8 ) ;
return V_7 -> V_9 -> V_10 ( V_7 ) ;
}
static int F_8 ( struct V_1 * V_4 )
{
struct V_7 * V_11 ;
int V_12 ;
F_2 () ;
V_11 = F_9 ( V_4 , V_8 ) ;
if ( V_11 )
V_12 = V_11 -> V_9 -> V_13 ( V_11 ) ;
else
V_12 = 0 ;
F_5 () ;
return V_12 ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_4 = F_11 ( V_15 , struct V_1 , V_15 ) ;
F_12 ( ( V_16 struct V_17 * ) V_4 -> V_18 ) ;
F_13 ( V_4 -> V_19 ) ;
F_14 ( F_15 ( V_4 ) ) ;
F_16 ( V_4 -> V_20 ) ;
F_16 ( V_4 ) ;
}
static struct V_21 * F_17 ( const struct V_1 * V_4 ,
T_1 V_22 )
{
return & V_4 -> V_20 [ V_22 & ( V_23 - 1 ) ] ;
}
struct V_7 * F_18 ( const struct V_1 * V_4 , T_1 V_22 )
{
struct V_7 * V_7 ;
struct V_24 * V_25 ;
struct V_21 * V_26 ;
V_26 = F_17 ( V_4 , V_22 ) ;
F_19 (vport, n, head, dp_hash_node) {
if ( V_7 -> V_22 == V_22 )
return V_7 ;
}
return NULL ;
}
static struct V_7 * F_20 ( const struct V_27 * V_28 )
{
struct V_7 * V_7 ;
V_7 = F_21 ( V_28 ) ;
if ( ! F_22 ( V_7 ) ) {
struct V_1 * V_4 = V_28 -> V_4 ;
struct V_21 * V_26 = F_17 ( V_4 , V_7 -> V_22 ) ;
F_23 ( & V_7 -> V_29 , V_26 ) ;
}
return V_7 ;
}
void F_24 ( struct V_7 * V_30 )
{
F_25 () ;
F_26 ( & V_30 -> V_29 ) ;
F_27 ( V_30 ) ;
}
void F_28 ( struct V_7 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_4 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 ;
T_2 * V_39 ;
int error ;
int V_40 ;
V_36 = F_29 ( V_4 -> V_19 ) ;
error = F_30 ( V_32 , V_30 -> V_22 , & V_38 , & V_40 ) ;
if ( F_31 ( error ) ) {
F_32 ( V_32 ) ;
return;
}
V_34 = F_33 ( F_34 ( V_4 -> V_18 ) , & V_38 , V_40 ) ;
if ( F_31 ( ! V_34 ) ) {
struct V_41 V_42 ;
V_42 . V_43 = V_44 ;
V_42 . V_38 = & V_38 ;
V_42 . V_45 = NULL ;
V_42 . V_46 = V_30 -> V_47 ;
F_35 ( V_4 , V_32 , & V_42 ) ;
F_36 ( V_32 ) ;
V_39 = & V_36 -> V_48 ;
goto V_49;
}
F_37 ( V_32 ) -> V_34 = V_34 ;
V_39 = & V_36 -> V_50 ;
F_38 ( F_37 ( V_32 ) -> V_34 , V_32 ) ;
F_39 ( V_4 , V_32 ) ;
V_49:
F_40 ( & V_36 -> V_51 ) ;
( * V_39 ) ++ ;
F_41 ( & V_36 -> V_51 ) ;
}
int F_35 ( struct V_1 * V_4 , struct V_31 * V_32 ,
const struct V_41 * V_52 )
{
struct V_35 * V_36 ;
int V_3 ;
int V_53 ;
if ( V_52 -> V_46 == 0 ) {
V_53 = - V_54 ;
goto V_53;
}
V_3 = F_8 ( V_4 ) ;
if ( ! V_3 ) {
V_53 = - V_55 ;
goto V_53;
}
if ( ! F_42 ( V_32 ) )
V_53 = F_43 ( F_15 ( V_4 ) , V_3 , V_32 , V_52 ) ;
else
V_53 = F_44 ( F_15 ( V_4 ) , V_3 , V_32 , V_52 ) ;
if ( V_53 )
goto V_53;
return 0 ;
V_53:
V_36 = F_29 ( V_4 -> V_19 ) ;
F_40 ( & V_36 -> V_51 ) ;
V_36 -> V_56 ++ ;
F_41 ( & V_36 -> V_51 ) ;
return V_53 ;
}
static int F_44 ( struct V_2 * V_2 , int V_3 ,
struct V_31 * V_32 ,
const struct V_41 * V_52 )
{
unsigned short V_57 = F_45 ( V_32 ) -> V_57 ;
struct V_41 V_58 ;
struct V_37 V_59 ;
struct V_31 * V_60 , * V_61 ;
int V_53 ;
V_60 = F_46 ( V_32 , V_62 | V_63 ) ;
if ( F_22 ( V_60 ) )
return F_47 ( V_60 ) ;
V_32 = V_60 ;
do {
V_53 = F_43 ( V_2 , V_3 , V_32 , V_52 ) ;
if ( V_53 )
break;
if ( V_32 == V_60 && V_57 & V_64 ) {
V_59 = * V_52 -> V_38 ;
V_59 . V_65 . V_66 = V_67 ;
V_58 = * V_52 ;
V_58 . V_38 = & V_59 ;
V_52 = & V_58 ;
}
} while ( ( V_32 = V_32 -> V_68 ) );
V_32 = V_60 ;
do {
V_61 = V_32 -> V_68 ;
if ( V_53 )
F_32 ( V_32 ) ;
else
F_36 ( V_32 ) ;
} while ( ( V_32 = V_61 ) );
return V_53 ;
}
static int F_43 ( struct V_2 * V_2 , int V_3 ,
struct V_31 * V_32 ,
const struct V_41 * V_52 )
{
struct V_69 * V_42 ;
struct V_31 * V_61 = NULL ;
struct V_31 * V_70 ;
struct V_71 * V_72 ;
unsigned int V_73 ;
int V_53 ;
if ( F_48 ( V_32 ) ) {
V_61 = F_49 ( V_32 , V_74 ) ;
if ( ! V_61 )
return - V_75 ;
V_61 = F_50 ( V_61 , F_51 ( V_61 ) ) ;
if ( ! V_61 )
return - V_75 ;
V_61 -> V_76 = 0 ;
V_32 = V_61 ;
}
if ( F_52 ( V_32 -> V_73 ) > V_77 ) {
V_53 = - V_78 ;
goto V_49;
}
V_73 = sizeof( struct V_69 ) ;
V_73 += F_53 ( V_32 -> V_73 ) ;
V_73 += F_53 ( V_79 ) ;
if ( V_52 -> V_43 == V_80 )
V_73 += F_53 ( 8 ) ;
V_70 = F_54 ( V_73 , V_74 ) ;
if ( ! V_70 ) {
V_53 = - V_75 ;
goto V_49;
}
V_42 = F_55 ( V_70 , 0 , 0 , & V_81 ,
0 , V_52 -> V_43 ) ;
V_42 -> V_3 = V_3 ;
V_72 = F_56 ( V_70 , V_82 ) ;
F_57 ( V_52 -> V_38 , V_70 ) ;
F_58 ( V_70 , V_72 ) ;
if ( V_52 -> V_45 )
F_59 ( V_70 , V_83 ,
F_60 ( V_52 -> V_45 ) ) ;
V_72 = F_61 ( V_70 , V_84 , V_32 -> V_73 ) ;
F_62 ( V_32 , F_63 ( V_72 ) ) ;
V_53 = F_64 ( V_2 , V_70 , V_52 -> V_46 ) ;
V_49:
F_32 ( V_61 ) ;
return V_53 ;
}
static int F_65 ( struct V_1 * V_4 )
{
struct V_17 * V_85 ;
struct V_17 * V_86 ;
V_85 = F_66 ( V_4 -> V_18 ) ;
V_86 = F_67 ( V_87 ) ;
if ( ! V_86 )
return - V_75 ;
F_68 ( V_4 -> V_18 , V_86 ) ;
F_69 ( V_85 ) ;
return 0 ;
}
static int F_70 ( const struct V_71 * V_88 ,
const struct V_37 * V_38 , int V_89 )
{
const struct V_71 * V_90 [ V_91 + 1 ] ;
const struct V_71 * V_92 , * V_93 ;
const struct V_71 * V_94 ;
int V_95 ;
memset ( V_90 , 0 , sizeof( V_90 ) ) ;
F_71 (a, attr, rem) {
int type = F_72 ( V_94 ) ;
if ( ! type || type > V_91 || V_90 [ type ] )
return - V_96 ;
V_90 [ type ] = V_94 ;
}
if ( V_95 )
return - V_96 ;
V_92 = V_90 [ V_97 ] ;
if ( ! V_92 || F_73 ( V_92 ) != sizeof( V_98 ) )
return - V_96 ;
V_93 = V_90 [ V_99 ] ;
if ( ! V_93 || ( F_73 ( V_93 ) && F_73 ( V_93 ) < V_100 ) )
return - V_96 ;
return F_74 ( V_93 , V_38 , V_89 + 1 ) ;
}
static int F_75 ( const struct V_37 * V_101 )
{
if ( V_101 -> V_102 . type == F_76 ( V_103 ) ) {
if ( V_101 -> V_104 . V_105 . V_106 || V_101 -> V_104 . V_105 . V_107 )
return 0 ;
} else if ( V_101 -> V_102 . type == F_76 ( V_108 ) ) {
if ( V_101 -> V_109 . V_105 . V_106 || V_101 -> V_109 . V_105 . V_107 )
return 0 ;
}
return - V_96 ;
}
static int F_77 ( const struct V_71 * V_94 ,
const struct V_37 * V_101 )
{
const struct V_71 * V_110 = F_63 ( V_94 ) ;
int V_111 = F_72 ( V_110 ) ;
if ( F_53 ( F_73 ( V_110 ) ) != F_73 ( V_94 ) )
return - V_96 ;
if ( V_111 > V_112 ||
F_73 ( V_110 ) != V_113 [ V_111 ] )
return - V_96 ;
switch ( V_111 ) {
const struct V_114 * V_115 ;
const struct V_116 * V_117 ;
case V_118 :
case V_119 :
case V_120 :
break;
case V_121 :
if ( V_101 -> V_102 . type != F_76 ( V_103 ) )
return - V_96 ;
if ( ! V_101 -> V_65 . V_122 )
return - V_96 ;
V_115 = F_63 ( V_110 ) ;
if ( V_115 -> V_123 != V_101 -> V_65 . V_122 )
return - V_96 ;
if ( V_115 -> V_124 != V_101 -> V_65 . V_66 )
return - V_96 ;
break;
case V_125 :
if ( V_101 -> V_102 . type != F_76 ( V_108 ) )
return - V_96 ;
if ( ! V_101 -> V_65 . V_122 )
return - V_96 ;
V_117 = F_63 ( V_110 ) ;
if ( V_117 -> V_126 != V_101 -> V_65 . V_122 )
return - V_96 ;
if ( V_117 -> V_127 != V_101 -> V_65 . V_66 )
return - V_96 ;
if ( F_78 ( V_117 -> V_128 ) & 0xFFF00000 )
return - V_96 ;
break;
case V_129 :
if ( V_101 -> V_65 . V_122 != V_130 )
return - V_96 ;
return F_75 ( V_101 ) ;
case V_131 :
if ( V_101 -> V_65 . V_122 != V_132 )
return - V_96 ;
return F_75 ( V_101 ) ;
default:
return - V_96 ;
}
return 0 ;
}
static int F_79 ( const struct V_71 * V_88 )
{
static const struct V_133 V_134 [ V_135 + 1 ] = {
[ V_136 ] = { . type = V_137 } ,
[ V_138 ] = { . type = V_139 } ,
} ;
struct V_71 * V_94 [ V_135 + 1 ] ;
int error ;
error = F_80 ( V_94 , V_135 ,
V_88 , V_134 ) ;
if ( error )
return error ;
if ( ! V_94 [ V_136 ] ||
! F_81 ( V_94 [ V_136 ] ) )
return - V_96 ;
return 0 ;
}
static int F_74 ( const struct V_71 * V_88 ,
const struct V_37 * V_38 , int V_89 )
{
const struct V_71 * V_94 ;
int V_95 , V_53 ;
if ( V_89 >= V_140 )
return - V_141 ;
F_71 (a, attr, rem) {
static const V_98 V_142 [ V_143 + 1 ] = {
[ V_144 ] = sizeof( V_98 ) ,
[ V_145 ] = ( V_98 ) - 1 ,
[ V_146 ] = sizeof( struct V_147 ) ,
[ V_148 ] = 0 ,
[ V_149 ] = ( V_98 ) - 1 ,
[ V_150 ] = ( V_98 ) - 1
} ;
const struct V_147 * V_151 ;
int type = F_72 ( V_94 ) ;
if ( type > V_143 ||
( V_142 [ type ] != F_73 ( V_94 ) &&
V_142 [ type ] != ( V_98 ) - 1 ) )
return - V_96 ;
switch ( type ) {
case V_152 :
return - V_96 ;
case V_145 :
V_53 = F_79 ( V_94 ) ;
if ( V_53 )
return V_53 ;
break;
case V_144 :
if ( F_81 ( V_94 ) >= V_153 )
return - V_96 ;
break;
case V_148 :
break;
case V_146 :
V_151 = F_63 ( V_94 ) ;
if ( V_151 -> V_154 != F_76 ( V_155 ) )
return - V_96 ;
if ( ! ( V_151 -> V_76 & F_76 ( V_156 ) ) )
return - V_96 ;
break;
case V_149 :
V_53 = F_77 ( V_94 , V_38 ) ;
if ( V_53 )
return V_53 ;
break;
case V_150 :
V_53 = F_70 ( V_94 , V_38 , V_89 ) ;
if ( V_53 )
return V_53 ;
break;
default:
return - V_96 ;
}
}
if ( V_95 > 0 )
return - V_96 ;
return 0 ;
}
static void F_82 ( struct V_33 * V_34 )
{
V_34 -> V_157 = 0 ;
V_34 -> V_158 = 0 ;
V_34 -> V_159 = 0 ;
V_34 -> V_160 = 0 ;
}
static int F_83 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_164 * V_165 ;
struct V_31 * V_166 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_167 * V_102 ;
int V_73 ;
int V_53 ;
int V_40 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_84 ] || ! V_94 [ V_82 ] ||
! V_94 [ V_168 ] ||
F_73 ( V_94 [ V_84 ] ) < V_169 )
goto V_53;
V_73 = F_73 ( V_94 [ V_84 ] ) ;
V_166 = F_84 ( V_170 + V_73 , V_171 ) ;
V_53 = - V_75 ;
if ( ! V_166 )
goto V_53;
F_85 ( V_166 , V_170 ) ;
memcpy ( F_86 ( V_166 , V_73 ) , F_63 ( V_94 [ V_84 ] ) , V_73 ) ;
F_87 ( V_166 ) ;
V_102 = F_88 ( V_166 ) ;
if ( F_89 ( V_102 -> V_172 ) >= 1536 )
V_166 -> V_173 = V_102 -> V_172 ;
else
V_166 -> V_173 = F_76 ( V_174 ) ;
V_34 = F_90 () ;
V_53 = F_47 ( V_34 ) ;
if ( F_22 ( V_34 ) )
goto V_175;
V_53 = F_30 ( V_166 , - 1 , & V_34 -> V_38 , & V_40 ) ;
if ( V_53 )
goto V_176;
V_53 = F_91 ( & V_34 -> V_38 . V_177 . V_178 ,
& V_34 -> V_38 . V_177 . V_179 ,
& V_34 -> V_38 . V_177 . V_180 ,
V_94 [ V_82 ] ) ;
if ( V_53 )
goto V_176;
V_53 = F_74 ( V_94 [ V_168 ] , & V_34 -> V_38 , 0 ) ;
if ( V_53 )
goto V_176;
V_34 -> V_181 = F_92 ( & V_34 -> V_38 , V_40 ) ;
V_165 = F_93 ( V_94 [ V_168 ] ) ;
V_53 = F_47 ( V_165 ) ;
if ( F_22 ( V_165 ) )
goto V_176;
F_68 ( V_34 -> V_182 , V_165 ) ;
F_37 ( V_166 ) -> V_34 = V_34 ;
V_166 -> V_178 = V_34 -> V_38 . V_177 . V_178 ;
V_166 -> V_183 = V_34 -> V_38 . V_177 . V_179 ;
F_2 () ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
V_53 = - V_55 ;
if ( ! V_4 )
goto V_185;
F_95 () ;
V_53 = F_39 ( V_4 , V_166 ) ;
F_96 () ;
F_5 () ;
F_97 ( V_34 ) ;
return V_53 ;
V_185:
F_5 () ;
V_176:
F_97 ( V_34 ) ;
V_175:
F_32 ( V_166 ) ;
V_53:
return V_53 ;
}
static void F_98 ( struct V_1 * V_4 , struct V_186 * V_36 )
{
int V_187 ;
struct V_17 * V_18 = F_66 ( V_4 -> V_18 ) ;
V_36 -> V_188 = F_99 ( V_18 ) ;
V_36 -> V_50 = V_36 -> V_48 = V_36 -> V_56 = 0 ;
F_100 (i) {
const struct V_35 * V_189 ;
struct V_35 V_190 ;
unsigned int V_191 ;
V_189 = F_101 ( V_4 -> V_19 , V_187 ) ;
do {
V_191 = F_102 ( & V_189 -> V_51 ) ;
V_190 = * V_189 ;
} while ( F_103 ( & V_189 -> V_51 , V_191 ) );
V_36 -> V_50 += V_190 . V_50 ;
V_36 -> V_48 += V_190 . V_48 ;
V_36 -> V_56 += V_190 . V_56 ;
}
}
static int F_104 ( struct V_33 * V_34 , struct V_1 * V_4 ,
struct V_31 * V_32 , V_98 V_46 ,
V_98 V_192 , V_98 V_193 , T_3 V_43 )
{
const int V_194 = V_32 -> V_73 ;
const struct V_164 * V_182 ;
struct V_195 V_36 ;
struct V_69 * V_69 ;
struct V_71 * V_72 ;
unsigned long V_157 ;
T_3 V_158 ;
int V_53 ;
V_182 = F_105 ( V_34 -> V_182 ,
F_106 () ) ;
V_69 = F_55 ( V_32 , V_46 , V_192 , & V_196 , V_193 , V_43 ) ;
if ( ! V_69 )
return - V_197 ;
V_69 -> V_3 = F_8 ( V_4 ) ;
V_72 = F_56 ( V_32 , V_198 ) ;
if ( ! V_72 )
goto V_199;
V_53 = F_57 ( & V_34 -> V_38 , V_32 ) ;
if ( V_53 )
goto error;
F_58 ( V_32 , V_72 ) ;
F_107 ( & V_34 -> V_200 ) ;
V_157 = V_34 -> V_157 ;
V_36 . V_201 = V_34 -> V_159 ;
V_36 . V_202 = V_34 -> V_160 ;
V_158 = V_34 -> V_158 ;
F_108 ( & V_34 -> V_200 ) ;
if ( V_157 &&
F_59 ( V_32 , V_203 , F_109 ( V_157 ) ) )
goto V_199;
if ( V_36 . V_201 &&
F_110 ( V_32 , V_204 ,
sizeof( struct V_195 ) , & V_36 ) )
goto V_199;
if ( V_158 &&
F_111 ( V_32 , V_205 , V_158 ) )
goto V_199;
V_53 = F_110 ( V_32 , V_206 , V_182 -> V_207 ,
V_182 -> V_93 ) ;
if ( V_53 < 0 && V_194 )
goto error;
return F_112 ( V_32 , V_69 ) ;
V_199:
V_53 = - V_197 ;
error:
F_113 ( V_32 , V_69 ) ;
return V_53 ;
}
static struct V_31 * F_114 ( struct V_33 * V_34 )
{
const struct V_164 * V_182 ;
int V_73 ;
V_182 = F_105 ( V_34 -> V_182 ,
F_106 () ) ;
V_73 = F_53 ( V_79 ) ;
V_73 += F_53 ( V_182 -> V_207 ) ;
V_73 += F_53 ( sizeof( struct V_195 ) ) ;
V_73 += F_53 ( 1 ) ;
V_73 += F_53 ( 8 ) ;
V_73 += F_115 ( sizeof( struct V_69 ) ) ;
return F_54 ( V_73 , V_171 ) ;
}
static struct V_31 * F_116 ( struct V_33 * V_34 ,
struct V_1 * V_4 ,
V_98 V_46 , V_98 V_192 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_208 ;
V_32 = F_114 ( V_34 ) ;
if ( ! V_32 )
return F_117 ( - V_75 ) ;
V_208 = F_104 ( V_34 , V_4 , V_32 , V_46 , V_192 , 0 , V_43 ) ;
F_118 ( V_208 < 0 ) ;
return V_32 ;
}
static int F_119 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_37 V_38 ;
struct V_33 * V_34 ;
struct V_31 * V_209 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int error ;
int V_40 ;
error = - V_96 ;
if ( ! V_94 [ V_198 ] )
goto error;
error = F_120 ( & V_38 , & V_40 , V_94 [ V_198 ] ) ;
if ( error )
goto error;
if ( V_94 [ V_206 ] ) {
error = F_74 ( V_94 [ V_206 ] , & V_38 , 0 ) ;
if ( error )
goto error;
} else if ( V_162 -> V_210 -> V_43 == V_211 ) {
error = - V_96 ;
goto error;
}
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
error = - V_55 ;
if ( ! V_4 )
goto error;
V_18 = F_66 ( V_4 -> V_18 ) ;
V_34 = F_33 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 ) {
struct V_164 * V_165 ;
error = - V_212 ;
if ( V_162 -> V_210 -> V_43 == V_213 )
goto error;
if ( F_121 ( V_18 ) ) {
struct V_17 * V_86 ;
V_86 = F_122 ( V_18 ) ;
if ( ! F_22 ( V_86 ) ) {
F_68 ( V_4 -> V_18 , V_86 ) ;
F_69 ( V_18 ) ;
V_18 = F_66 ( V_4 -> V_18 ) ;
}
}
V_34 = F_90 () ;
if ( F_22 ( V_34 ) ) {
error = F_47 ( V_34 ) ;
goto error;
}
V_34 -> V_38 = V_38 ;
F_82 ( V_34 ) ;
V_165 = F_93 ( V_94 [ V_206 ] ) ;
error = F_47 ( V_165 ) ;
if ( F_22 ( V_165 ) )
goto V_214;
F_68 ( V_34 -> V_182 , V_165 ) ;
V_34 -> V_181 = F_92 ( & V_38 , V_40 ) ;
F_123 ( V_18 , V_34 ) ;
V_209 = F_116 ( V_34 , V_4 , V_162 -> V_215 ,
V_162 -> V_216 ,
V_211 ) ;
} else {
struct V_164 * V_217 ;
struct V_71 * V_218 ;
error = - V_219 ;
if ( V_162 -> V_210 -> V_43 == V_211 &&
V_162 -> V_220 -> V_221 & ( V_222 | V_223 ) )
goto error;
V_217 = F_105 ( V_34 -> V_182 ,
F_106 () ) ;
V_218 = V_94 [ V_206 ] ;
if ( V_218 &&
( V_217 -> V_207 != F_73 ( V_218 ) ||
memcmp ( V_217 -> V_93 , F_63 ( V_218 ) ,
V_217 -> V_207 ) ) ) {
struct V_164 * V_224 ;
V_224 = F_93 ( V_218 ) ;
error = F_47 ( V_224 ) ;
if ( F_22 ( V_224 ) )
goto error;
F_68 ( V_34 -> V_182 , V_224 ) ;
F_124 ( V_217 ) ;
}
V_209 = F_116 ( V_34 , V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_211 ) ;
if ( V_94 [ V_225 ] ) {
F_107 ( & V_34 -> V_200 ) ;
F_82 ( V_34 ) ;
F_108 ( & V_34 -> V_200 ) ;
}
}
if ( ! F_22 ( V_209 ) )
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_226 . V_227 , V_162 -> V_220 ,
V_171 ) ;
else
F_127 ( F_94 ( V_32 -> V_184 ) -> V_228 , 0 ,
V_226 . V_227 , F_47 ( V_209 ) ) ;
return 0 ;
V_214:
F_97 ( V_34 ) ;
error:
return error ;
}
static int F_128 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_37 V_38 ;
struct V_31 * V_209 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_53 ;
int V_40 ;
if ( ! V_94 [ V_198 ] )
return - V_96 ;
V_53 = F_120 ( & V_38 , & V_40 , V_94 [ V_198 ] ) ;
if ( V_53 )
return V_53 ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
V_18 = F_66 ( V_4 -> V_18 ) ;
V_34 = F_33 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 )
return - V_212 ;
V_209 = F_116 ( V_34 , V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_211 ) ;
if ( F_22 ( V_209 ) )
return F_47 ( V_209 ) ;
return F_129 ( V_209 , V_162 ) ;
}
static int F_130 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_37 V_38 ;
struct V_31 * V_209 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_53 ;
int V_40 ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
if ( ! V_94 [ V_198 ] )
return F_65 ( V_4 ) ;
V_53 = F_120 ( & V_38 , & V_40 , V_94 [ V_198 ] ) ;
if ( V_53 )
return V_53 ;
V_18 = F_66 ( V_4 -> V_18 ) ;
V_34 = F_33 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 )
return - V_212 ;
V_209 = F_114 ( V_34 ) ;
if ( ! V_209 )
return - V_75 ;
F_131 ( V_18 , V_34 ) ;
V_53 = F_104 ( V_34 , V_4 , V_209 , V_162 -> V_215 ,
V_162 -> V_216 , 0 , V_229 ) ;
F_118 ( V_53 < 0 ) ;
F_132 ( V_34 ) ;
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_226 . V_227 , V_162 -> V_220 , V_171 ) ;
return 0 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_230 * V_231 )
{
struct V_69 * V_69 = F_134 ( F_135 ( V_231 -> V_232 ) ) ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
V_18 = F_66 ( V_4 -> V_18 ) ;
for (; ; ) {
struct V_33 * V_34 ;
V_98 V_233 , V_234 ;
V_233 = V_231 -> args [ 0 ] ;
V_234 = V_231 -> args [ 1 ] ;
V_34 = F_136 ( V_18 , & V_233 , & V_234 ) ;
if ( ! V_34 )
break;
if ( F_104 ( V_34 , V_4 , V_32 ,
F_137 ( V_231 -> V_32 ) . V_46 ,
V_231 -> V_232 -> V_235 , V_236 ,
V_211 ) < 0 )
break;
V_231 -> args [ 0 ] = V_233 ;
V_231 -> args [ 1 ] = V_234 ;
}
return V_32 -> V_73 ;
}
static int F_138 ( struct V_1 * V_4 , struct V_31 * V_32 ,
V_98 V_46 , V_98 V_192 , V_98 V_193 , T_3 V_43 )
{
struct V_69 * V_69 ;
struct V_186 V_237 ;
int V_53 ;
V_69 = F_55 ( V_32 , V_46 , V_192 , & V_238 ,
V_193 , V_43 ) ;
if ( ! V_69 )
goto error;
V_69 -> V_3 = F_8 ( V_4 ) ;
F_2 () ;
V_53 = F_139 ( V_32 , V_239 , F_6 ( V_4 ) ) ;
F_5 () ;
if ( V_53 )
goto V_199;
F_98 ( V_4 , & V_237 ) ;
if ( F_110 ( V_32 , V_240 , sizeof( struct V_186 ) , & V_237 ) )
goto V_199;
return F_112 ( V_32 , V_69 ) ;
V_199:
F_113 ( V_32 , V_69 ) ;
error:
return - V_197 ;
}
static struct V_31 * F_140 ( struct V_1 * V_4 , V_98 V_46 ,
V_98 V_192 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_208 ;
V_32 = F_141 ( V_241 , V_171 ) ;
if ( ! V_32 )
return F_117 ( - V_75 ) ;
V_208 = F_138 ( V_4 , V_32 , V_46 , V_192 , 0 , V_43 ) ;
if ( V_208 < 0 ) {
F_32 ( V_32 ) ;
return F_117 ( V_208 ) ;
}
return V_32 ;
}
static struct V_1 * F_142 ( struct V_2 * V_2 ,
struct V_69 * V_69 ,
struct V_71 * V_94 [ V_242 + 1 ] )
{
struct V_1 * V_4 ;
if ( ! V_94 [ V_239 ] )
V_4 = F_1 ( V_2 , V_69 -> V_3 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_143 ( V_2 , F_63 ( V_94 [ V_239 ] ) ) ;
V_4 = V_7 && V_7 -> V_22 == V_8 ? V_7 -> V_4 : NULL ;
F_5 () ;
}
return V_4 ? V_4 : F_117 ( - V_55 ) ;
}
static int F_144 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_27 V_28 ;
struct V_31 * V_209 ;
struct V_1 * V_4 ;
struct V_7 * V_7 ;
struct V_243 * V_243 ;
int V_53 , V_187 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_239 ] || ! V_94 [ V_244 ] )
goto V_53;
F_145 () ;
V_53 = - V_75 ;
V_4 = F_146 ( sizeof( * V_4 ) , V_171 ) ;
if ( V_4 == NULL )
goto V_245;
F_147 ( V_4 , F_148 ( F_94 ( V_32 -> V_184 ) ) ) ;
V_53 = - V_75 ;
F_68 ( V_4 -> V_18 , F_67 ( V_87 ) ) ;
if ( ! V_4 -> V_18 )
goto V_246;
V_4 -> V_19 = F_149 ( struct V_35 ) ;
if ( ! V_4 -> V_19 ) {
V_53 = - V_75 ;
goto V_247;
}
V_4 -> V_20 = F_150 ( V_23 * sizeof( struct V_21 ) ,
V_171 ) ;
if ( ! V_4 -> V_20 ) {
V_53 = - V_75 ;
goto V_248;
}
for ( V_187 = 0 ; V_187 < V_23 ; V_187 ++ )
F_151 ( & V_4 -> V_20 [ V_187 ] ) ;
V_28 . V_249 = F_63 ( V_94 [ V_239 ] ) ;
V_28 . type = V_250 ;
V_28 . V_251 = NULL ;
V_28 . V_4 = V_4 ;
V_28 . V_22 = V_8 ;
V_28 . V_47 = F_81 ( V_94 [ V_244 ] ) ;
V_7 = F_20 ( & V_28 ) ;
if ( F_22 ( V_7 ) ) {
V_53 = F_47 ( V_7 ) ;
if ( V_53 == - V_252 )
V_53 = - V_219 ;
goto V_253;
}
V_209 = F_140 ( V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_254 ) ;
V_53 = F_47 ( V_209 ) ;
if ( F_22 ( V_209 ) )
goto V_255;
V_243 = F_152 ( F_15 ( V_4 ) , V_256 ) ;
F_153 ( & V_4 -> V_257 , & V_243 -> V_258 ) ;
F_154 () ;
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_259 . V_227 , V_162 -> V_220 ,
V_171 ) ;
return 0 ;
V_255:
F_24 ( F_155 ( V_4 , V_8 ) ) ;
V_253:
F_16 ( V_4 -> V_20 ) ;
V_248:
F_13 ( V_4 -> V_19 ) ;
V_247:
F_12 ( F_66 ( V_4 -> V_18 ) ) ;
V_246:
F_14 ( F_15 ( V_4 ) ) ;
F_16 ( V_4 ) ;
V_245:
F_154 () ;
V_53:
return V_53 ;
}
static void F_156 ( struct V_1 * V_4 )
{
int V_187 ;
F_145 () ;
for ( V_187 = 0 ; V_187 < V_23 ; V_187 ++ ) {
struct V_7 * V_7 ;
struct V_24 * V_260 , * V_25 ;
F_157 (vport, node, n, &dp->ports[i], dp_hash_node)
if ( V_7 -> V_22 != V_8 )
F_24 ( V_7 ) ;
}
F_158 ( & V_4 -> V_257 ) ;
F_24 ( F_155 ( V_4 , V_8 ) ) ;
F_154 () ;
F_159 ( & V_4 -> V_15 , F_10 ) ;
}
static int F_160 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_31 * V_209 ;
struct V_1 * V_4 ;
int V_53 ;
V_4 = F_142 ( F_94 ( V_32 -> V_184 ) , V_162 -> V_163 , V_162 -> V_90 ) ;
V_53 = F_47 ( V_4 ) ;
if ( F_22 ( V_4 ) )
return V_53 ;
V_209 = F_140 ( V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_261 ) ;
V_53 = F_47 ( V_209 ) ;
if ( F_22 ( V_209 ) )
return V_53 ;
F_156 ( V_4 ) ;
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_259 . V_227 , V_162 -> V_220 ,
V_171 ) ;
return 0 ;
}
static int F_161 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_31 * V_209 ;
struct V_1 * V_4 ;
int V_53 ;
V_4 = F_142 ( F_94 ( V_32 -> V_184 ) , V_162 -> V_163 , V_162 -> V_90 ) ;
if ( F_22 ( V_4 ) )
return F_47 ( V_4 ) ;
V_209 = F_140 ( V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_254 ) ;
if ( F_22 ( V_209 ) ) {
V_53 = F_47 ( V_209 ) ;
F_127 ( F_94 ( V_32 -> V_184 ) -> V_228 , 0 ,
V_259 . V_227 , V_53 ) ;
return 0 ;
}
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_259 . V_227 , V_162 -> V_220 ,
V_171 ) ;
return 0 ;
}
static int F_162 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_31 * V_209 ;
struct V_1 * V_4 ;
V_4 = F_142 ( F_94 ( V_32 -> V_184 ) , V_162 -> V_163 , V_162 -> V_90 ) ;
if ( F_22 ( V_4 ) )
return F_47 ( V_4 ) ;
V_209 = F_140 ( V_4 , V_162 -> V_215 ,
V_162 -> V_216 , V_254 ) ;
if ( F_22 ( V_209 ) )
return F_47 ( V_209 ) ;
return F_129 ( V_209 , V_162 ) ;
}
static int F_163 ( struct V_31 * V_32 , struct V_230 * V_231 )
{
struct V_243 * V_243 = F_152 ( F_94 ( V_32 -> V_184 ) , V_256 ) ;
struct V_1 * V_4 ;
int V_262 = V_231 -> args [ 0 ] ;
int V_187 = 0 ;
F_164 (dp, &ovs_net->dps, list_node) {
if ( V_187 >= V_262 &&
F_138 ( V_4 , V_32 , F_137 ( V_231 -> V_32 ) . V_46 ,
V_231 -> V_232 -> V_235 , V_236 ,
V_254 ) < 0 )
break;
V_187 ++ ;
}
V_231 -> args [ 0 ] = V_187 ;
return V_32 -> V_73 ;
}
static int F_165 ( struct V_7 * V_7 , struct V_31 * V_32 ,
V_98 V_46 , V_98 V_192 , V_98 V_193 , T_3 V_43 )
{
struct V_69 * V_69 ;
struct V_263 V_264 ;
int V_53 ;
V_69 = F_55 ( V_32 , V_46 , V_192 , & V_265 ,
V_193 , V_43 ) ;
if ( ! V_69 )
return - V_197 ;
V_69 -> V_3 = F_8 ( V_7 -> V_4 ) ;
if ( F_166 ( V_32 , V_266 , V_7 -> V_22 ) ||
F_166 ( V_32 , V_267 , V_7 -> V_9 -> type ) ||
F_139 ( V_32 , V_268 , V_7 -> V_9 -> V_10 ( V_7 ) ) ||
F_166 ( V_32 , V_269 , V_7 -> V_47 ) )
goto V_199;
F_167 ( V_7 , & V_264 ) ;
if ( F_110 ( V_32 , V_270 , sizeof( struct V_263 ) ,
& V_264 ) )
goto V_199;
V_53 = F_168 ( V_7 , V_32 ) ;
if ( V_53 == - V_197 )
goto error;
return F_112 ( V_32 , V_69 ) ;
V_199:
V_53 = - V_197 ;
error:
F_113 ( V_32 , V_69 ) ;
return V_53 ;
}
struct V_31 * F_169 ( struct V_7 * V_7 , V_98 V_46 ,
V_98 V_192 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_208 ;
V_32 = F_141 ( V_241 , V_74 ) ;
if ( ! V_32 )
return F_117 ( - V_75 ) ;
V_208 = F_165 ( V_7 , V_32 , V_46 , V_192 , 0 , V_43 ) ;
if ( V_208 < 0 ) {
F_32 ( V_32 ) ;
return F_117 ( V_208 ) ;
}
return V_32 ;
}
static struct V_7 * F_170 ( struct V_2 * V_2 ,
struct V_69 * V_69 ,
struct V_71 * V_94 [ V_271 + 1 ] )
{
struct V_1 * V_4 ;
struct V_7 * V_7 ;
if ( V_94 [ V_268 ] ) {
V_7 = F_143 ( V_2 , F_63 ( V_94 [ V_268 ] ) ) ;
if ( ! V_7 )
return F_117 ( - V_55 ) ;
if ( V_69 -> V_3 &&
V_69 -> V_3 != F_8 ( V_7 -> V_4 ) )
return F_117 ( - V_55 ) ;
return V_7 ;
} else if ( V_94 [ V_266 ] ) {
V_98 V_22 = F_81 ( V_94 [ V_266 ] ) ;
if ( V_22 >= V_153 )
return F_117 ( - V_78 ) ;
V_4 = F_1 ( V_2 , V_69 -> V_3 ) ;
if ( ! V_4 )
return F_117 ( - V_55 ) ;
V_7 = F_7 ( V_4 , V_22 ) ;
if ( ! V_7 )
return F_117 ( - V_212 ) ;
return V_7 ;
} else
return F_117 ( - V_96 ) ;
}
static int F_171 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_27 V_28 ;
struct V_31 * V_209 ;
struct V_7 * V_7 ;
struct V_1 * V_4 ;
V_98 V_22 ;
int V_53 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_268 ] || ! V_94 [ V_267 ] ||
! V_94 [ V_269 ] )
goto exit;
F_145 () ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
V_53 = - V_55 ;
if ( ! V_4 )
goto V_272;
if ( V_94 [ V_266 ] ) {
V_22 = F_81 ( V_94 [ V_266 ] ) ;
V_53 = - V_78 ;
if ( V_22 >= V_153 )
goto V_272;
V_7 = F_7 ( V_4 , V_22 ) ;
V_53 = - V_252 ;
if ( V_7 )
goto V_272;
} else {
for ( V_22 = 1 ; ; V_22 ++ ) {
if ( V_22 >= V_153 ) {
V_53 = - V_78 ;
goto V_272;
}
V_7 = F_155 ( V_4 , V_22 ) ;
if ( ! V_7 )
break;
}
}
V_28 . V_249 = F_63 ( V_94 [ V_268 ] ) ;
V_28 . type = F_81 ( V_94 [ V_267 ] ) ;
V_28 . V_251 = V_94 [ V_273 ] ;
V_28 . V_4 = V_4 ;
V_28 . V_22 = V_22 ;
V_28 . V_47 = F_81 ( V_94 [ V_269 ] ) ;
V_7 = F_20 ( & V_28 ) ;
V_53 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_272;
V_209 = F_169 ( V_7 , V_162 -> V_215 , V_162 -> V_216 ,
V_274 ) ;
if ( F_22 ( V_209 ) ) {
V_53 = F_47 ( V_209 ) ;
F_24 ( V_7 ) ;
goto V_272;
}
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_275 . V_227 , V_162 -> V_220 , V_171 ) ;
V_272:
F_154 () ;
exit:
return V_53 ;
}
static int F_172 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_31 * V_209 ;
struct V_7 * V_7 ;
int V_53 ;
F_145 () ;
V_7 = F_170 ( F_94 ( V_32 -> V_184 ) , V_162 -> V_163 , V_94 ) ;
V_53 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_272;
V_53 = 0 ;
if ( V_94 [ V_267 ] &&
F_81 ( V_94 [ V_267 ] ) != V_7 -> V_9 -> type )
V_53 = - V_96 ;
if ( ! V_53 && V_94 [ V_273 ] )
V_53 = F_173 ( V_7 , V_94 [ V_273 ] ) ;
if ( V_53 )
goto V_272;
if ( V_94 [ V_269 ] )
V_7 -> V_47 = F_81 ( V_94 [ V_269 ] ) ;
V_209 = F_169 ( V_7 , V_162 -> V_215 , V_162 -> V_216 ,
V_274 ) ;
if ( F_22 ( V_209 ) ) {
F_127 ( F_94 ( V_32 -> V_184 ) -> V_228 , 0 ,
V_275 . V_227 , F_47 ( V_209 ) ) ;
goto V_272;
}
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_275 . V_227 , V_162 -> V_220 , V_171 ) ;
V_272:
F_154 () ;
return V_53 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_31 * V_209 ;
struct V_7 * V_7 ;
int V_53 ;
F_145 () ;
V_7 = F_170 ( F_94 ( V_32 -> V_184 ) , V_162 -> V_163 , V_94 ) ;
V_53 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_272;
if ( V_7 -> V_22 == V_8 ) {
V_53 = - V_96 ;
goto V_272;
}
V_209 = F_169 ( V_7 , V_162 -> V_215 , V_162 -> V_216 ,
V_276 ) ;
V_53 = F_47 ( V_209 ) ;
if ( F_22 ( V_209 ) )
goto V_272;
F_24 ( V_7 ) ;
F_125 ( V_209 , F_126 ( V_162 ) , V_162 -> V_215 ,
V_275 . V_227 , V_162 -> V_220 , V_171 ) ;
V_272:
F_154 () ;
return V_53 ;
}
static int F_175 ( struct V_31 * V_32 , struct V_161 * V_162 )
{
struct V_71 * * V_94 = V_162 -> V_90 ;
struct V_69 * V_69 = V_162 -> V_163 ;
struct V_31 * V_209 ;
struct V_7 * V_7 ;
int V_53 ;
F_2 () ;
V_7 = F_170 ( F_94 ( V_32 -> V_184 ) , V_69 , V_94 ) ;
V_53 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_272;
V_209 = F_169 ( V_7 , V_162 -> V_215 , V_162 -> V_216 ,
V_274 ) ;
V_53 = F_47 ( V_209 ) ;
if ( F_22 ( V_209 ) )
goto V_272;
F_5 () ;
return F_129 ( V_209 , V_162 ) ;
V_272:
F_5 () ;
return V_53 ;
}
static int F_176 ( struct V_31 * V_32 , struct V_230 * V_231 )
{
struct V_69 * V_69 = F_134 ( F_135 ( V_231 -> V_232 ) ) ;
struct V_1 * V_4 ;
int V_233 = V_231 -> args [ 0 ] , V_262 = V_231 -> args [ 1 ] ;
int V_187 , V_277 = 0 ;
V_4 = F_1 ( F_94 ( V_32 -> V_184 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
F_2 () ;
for ( V_187 = V_233 ; V_187 < V_23 ; V_187 ++ ) {
struct V_7 * V_7 ;
struct V_24 * V_25 ;
V_277 = 0 ;
F_19 (vport, n, &dp->ports[i], dp_hash_node) {
if ( V_277 >= V_262 &&
F_165 ( V_7 , V_32 ,
F_137 ( V_231 -> V_32 ) . V_46 ,
V_231 -> V_232 -> V_235 ,
V_236 ,
V_274 ) < 0 )
goto V_49;
V_277 ++ ;
}
V_262 = 0 ;
}
V_49:
F_5 () ;
V_231 -> args [ 0 ] = V_187 ;
V_231 -> args [ 1 ] = V_277 ;
return V_32 -> V_73 ;
}
static void F_177 ( int V_278 )
{
int V_187 ;
for ( V_187 = 0 ; V_187 < V_278 ; V_187 ++ )
F_178 ( V_279 [ V_187 ] . V_280 ) ;
}
static int F_179 ( void )
{
int V_281 ;
int V_53 ;
int V_187 ;
V_281 = 0 ;
for ( V_187 = 0 ; V_187 < F_180 ( V_279 ) ; V_187 ++ ) {
const struct V_282 * V_283 = & V_279 [ V_187 ] ;
V_53 = F_181 ( V_283 -> V_280 , V_283 -> V_9 ,
V_283 -> V_284 ) ;
if ( V_53 )
goto error;
V_281 ++ ;
if ( V_283 -> V_285 ) {
V_53 = F_182 ( V_283 -> V_280 , V_283 -> V_285 ) ;
if ( V_53 )
goto error;
}
}
return 0 ;
error:
F_177 ( V_281 ) ;
return V_53 ;
}
static void F_183 ( struct V_286 * V_287 )
{
struct V_1 * V_4 ;
struct V_2 * V_2 ;
F_184 () ;
F_145 () ;
F_185 (net) {
struct V_243 * V_243 = F_152 ( V_2 , V_256 ) ;
F_164 (dp, &ovs_net->dps, list_node) {
struct V_17 * V_85 = F_66 ( V_4 -> V_18 ) ;
struct V_17 * V_86 ;
V_86 = F_186 ( V_85 ) ;
if ( ! F_22 ( V_86 ) ) {
F_68 ( V_4 -> V_18 , V_86 ) ;
F_69 ( V_85 ) ;
}
}
}
F_154 () ;
F_187 () ;
F_188 ( & V_288 , V_289 ) ;
}
static int T_4 F_189 ( struct V_2 * V_2 )
{
struct V_243 * V_243 = F_152 ( V_2 , V_256 ) ;
F_190 ( & V_243 -> V_258 ) ;
return 0 ;
}
static void T_5 F_191 ( struct V_2 * V_2 )
{
struct V_243 * V_243 = F_152 ( V_2 , V_256 ) ;
struct V_1 * V_4 , * V_290 ;
F_184 () ;
F_192 (dp, dp_next, &ovs_net->dps, list_node)
F_156 ( V_4 ) ;
F_187 () ;
}
static int T_6 F_193 ( void )
{
struct V_31 * V_291 ;
int V_53 ;
F_194 ( sizeof( struct V_292 ) > sizeof( V_291 -> V_231 ) ) ;
F_195 ( L_1 ) ;
V_53 = F_196 () ;
if ( V_53 )
goto error;
V_53 = F_197 () ;
if ( V_53 )
goto V_293;
V_53 = F_198 ( & V_294 ) ;
if ( V_53 )
goto V_295;
V_53 = F_199 ( & V_296 ) ;
if ( V_53 )
goto V_297;
V_53 = F_179 () ;
if ( V_53 < 0 )
goto V_298;
F_188 ( & V_288 , V_289 ) ;
return 0 ;
V_298:
F_200 ( & V_296 ) ;
V_297:
F_201 ( & V_294 ) ;
V_295:
F_202 () ;
V_293:
F_203 () ;
error:
return V_53 ;
}
static void F_204 ( void )
{
F_205 ( & V_288 ) ;
F_177 ( F_180 ( V_279 ) ) ;
F_200 ( & V_296 ) ;
F_201 ( & V_294 ) ;
F_206 () ;
F_202 () ;
F_203 () ;
}
