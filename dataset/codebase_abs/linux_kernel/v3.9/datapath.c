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
struct V_21 * V_24 ;
V_24 = F_17 ( V_4 , V_22 ) ;
F_19 (vport, head, dp_hash_node) {
if ( V_7 -> V_22 == V_22 )
return V_7 ;
}
return NULL ;
}
static struct V_7 * F_20 ( const struct V_25 * V_26 )
{
struct V_7 * V_7 ;
V_7 = F_21 ( V_26 ) ;
if ( ! F_22 ( V_7 ) ) {
struct V_1 * V_4 = V_26 -> V_4 ;
struct V_21 * V_24 = F_17 ( V_4 , V_7 -> V_22 ) ;
F_23 ( & V_7 -> V_27 , V_24 ) ;
}
return V_7 ;
}
void F_24 ( struct V_7 * V_28 )
{
F_25 () ;
F_26 ( & V_28 -> V_27 ) ;
F_27 ( V_28 ) ;
}
void F_28 ( struct V_7 * V_28 , struct V_29 * V_30 )
{
struct V_1 * V_4 = V_28 -> V_4 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 V_36 ;
T_2 * V_37 ;
int error ;
int V_38 ;
V_34 = F_29 ( V_4 -> V_19 ) ;
error = F_30 ( V_30 , V_28 -> V_22 , & V_36 , & V_38 ) ;
if ( F_31 ( error ) ) {
F_32 ( V_30 ) ;
return;
}
V_32 = F_33 ( F_34 ( V_4 -> V_18 ) , & V_36 , V_38 ) ;
if ( F_31 ( ! V_32 ) ) {
struct V_39 V_40 ;
V_40 . V_41 = V_42 ;
V_40 . V_36 = & V_36 ;
V_40 . V_43 = NULL ;
V_40 . V_44 = V_28 -> V_45 ;
F_35 ( V_4 , V_30 , & V_40 ) ;
F_36 ( V_30 ) ;
V_37 = & V_34 -> V_46 ;
goto V_47;
}
F_37 ( V_30 ) -> V_32 = V_32 ;
V_37 = & V_34 -> V_48 ;
F_38 ( F_37 ( V_30 ) -> V_32 , V_30 ) ;
F_39 ( V_4 , V_30 ) ;
V_47:
F_40 ( & V_34 -> V_49 ) ;
( * V_37 ) ++ ;
F_41 ( & V_34 -> V_49 ) ;
}
int F_35 ( struct V_1 * V_4 , struct V_29 * V_30 ,
const struct V_39 * V_50 )
{
struct V_33 * V_34 ;
int V_3 ;
int V_51 ;
if ( V_50 -> V_44 == 0 ) {
V_51 = - V_52 ;
goto V_51;
}
V_3 = F_8 ( V_4 ) ;
if ( ! V_3 ) {
V_51 = - V_53 ;
goto V_51;
}
if ( ! F_42 ( V_30 ) )
V_51 = F_43 ( F_15 ( V_4 ) , V_3 , V_30 , V_50 ) ;
else
V_51 = F_44 ( F_15 ( V_4 ) , V_3 , V_30 , V_50 ) ;
if ( V_51 )
goto V_51;
return 0 ;
V_51:
V_34 = F_29 ( V_4 -> V_19 ) ;
F_40 ( & V_34 -> V_49 ) ;
V_34 -> V_54 ++ ;
F_41 ( & V_34 -> V_49 ) ;
return V_51 ;
}
static int F_44 ( struct V_2 * V_2 , int V_3 ,
struct V_29 * V_30 ,
const struct V_39 * V_50 )
{
unsigned short V_55 = F_45 ( V_30 ) -> V_55 ;
struct V_39 V_56 ;
struct V_35 V_57 ;
struct V_29 * V_58 , * V_59 ;
int V_51 ;
V_58 = F_46 ( V_30 , V_60 | V_61 , false ) ;
if ( F_22 ( V_58 ) )
return F_47 ( V_58 ) ;
V_30 = V_58 ;
do {
V_51 = F_43 ( V_2 , V_3 , V_30 , V_50 ) ;
if ( V_51 )
break;
if ( V_30 == V_58 && V_55 & V_62 ) {
V_57 = * V_50 -> V_36 ;
V_57 . V_63 . V_64 = V_65 ;
V_56 = * V_50 ;
V_56 . V_36 = & V_57 ;
V_50 = & V_56 ;
}
} while ( ( V_30 = V_30 -> V_66 ) );
V_30 = V_58 ;
do {
V_59 = V_30 -> V_66 ;
if ( V_51 )
F_32 ( V_30 ) ;
else
F_36 ( V_30 ) ;
} while ( ( V_30 = V_59 ) );
return V_51 ;
}
static int F_43 ( struct V_2 * V_2 , int V_3 ,
struct V_29 * V_30 ,
const struct V_39 * V_50 )
{
struct V_67 * V_40 ;
struct V_29 * V_59 = NULL ;
struct V_29 * V_68 ;
struct V_69 * V_70 ;
unsigned int V_71 ;
int V_51 ;
if ( F_48 ( V_30 ) ) {
V_59 = F_49 ( V_30 , V_72 ) ;
if ( ! V_59 )
return - V_73 ;
V_59 = F_50 ( V_59 , F_51 ( V_59 ) ) ;
if ( ! V_59 )
return - V_73 ;
V_59 -> V_74 = 0 ;
V_30 = V_59 ;
}
if ( F_52 ( V_30 -> V_71 ) > V_75 ) {
V_51 = - V_76 ;
goto V_47;
}
V_71 = sizeof( struct V_67 ) ;
V_71 += F_53 ( V_30 -> V_71 ) ;
V_71 += F_53 ( V_77 ) ;
if ( V_50 -> V_41 == V_78 )
V_71 += F_53 ( 8 ) ;
V_68 = F_54 ( V_71 , V_72 ) ;
if ( ! V_68 ) {
V_51 = - V_73 ;
goto V_47;
}
V_40 = F_55 ( V_68 , 0 , 0 , & V_79 ,
0 , V_50 -> V_41 ) ;
V_40 -> V_3 = V_3 ;
V_70 = F_56 ( V_68 , V_80 ) ;
F_57 ( V_50 -> V_36 , V_68 ) ;
F_58 ( V_68 , V_70 ) ;
if ( V_50 -> V_43 )
F_59 ( V_68 , V_81 ,
F_60 ( V_50 -> V_43 ) ) ;
V_70 = F_61 ( V_68 , V_82 , V_30 -> V_71 ) ;
F_62 ( V_30 , F_63 ( V_70 ) ) ;
F_64 ( V_68 , V_40 ) ;
V_51 = F_65 ( V_2 , V_68 , V_50 -> V_44 ) ;
V_47:
F_32 ( V_59 ) ;
return V_51 ;
}
static int F_66 ( struct V_1 * V_4 )
{
struct V_17 * V_83 ;
struct V_17 * V_84 ;
V_83 = F_67 ( V_4 -> V_18 ) ;
V_84 = F_68 ( V_85 ) ;
if ( ! V_84 )
return - V_73 ;
F_69 ( V_4 -> V_18 , V_84 ) ;
F_70 ( V_83 ) ;
return 0 ;
}
static int F_71 ( const struct V_69 * V_86 ,
const struct V_35 * V_36 , int V_87 )
{
const struct V_69 * V_88 [ V_89 + 1 ] ;
const struct V_69 * V_90 , * V_91 ;
const struct V_69 * V_92 ;
int V_93 ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
F_72 (a, attr, rem) {
int type = F_73 ( V_92 ) ;
if ( ! type || type > V_89 || V_88 [ type ] )
return - V_94 ;
V_88 [ type ] = V_92 ;
}
if ( V_93 )
return - V_94 ;
V_90 = V_88 [ V_95 ] ;
if ( ! V_90 || F_74 ( V_90 ) != sizeof( V_96 ) )
return - V_94 ;
V_91 = V_88 [ V_97 ] ;
if ( ! V_91 || ( F_74 ( V_91 ) && F_74 ( V_91 ) < V_98 ) )
return - V_94 ;
return F_75 ( V_91 , V_36 , V_87 + 1 ) ;
}
static int F_76 ( const struct V_35 * V_99 )
{
if ( V_99 -> V_100 . type == F_77 ( V_101 ) ) {
if ( V_99 -> V_102 . V_103 . V_104 || V_99 -> V_102 . V_103 . V_105 )
return 0 ;
} else if ( V_99 -> V_100 . type == F_77 ( V_106 ) ) {
if ( V_99 -> V_107 . V_103 . V_104 || V_99 -> V_107 . V_103 . V_105 )
return 0 ;
}
return - V_94 ;
}
static int F_78 ( const struct V_69 * V_92 ,
const struct V_35 * V_99 )
{
const struct V_69 * V_108 = F_63 ( V_92 ) ;
int V_109 = F_73 ( V_108 ) ;
if ( F_53 ( F_74 ( V_108 ) ) != F_74 ( V_92 ) )
return - V_94 ;
if ( V_109 > V_110 ||
F_74 ( V_108 ) != V_111 [ V_109 ] )
return - V_94 ;
switch ( V_109 ) {
const struct V_112 * V_113 ;
const struct V_114 * V_115 ;
case V_116 :
case V_117 :
case V_118 :
break;
case V_119 :
if ( V_99 -> V_100 . type != F_77 ( V_101 ) )
return - V_94 ;
if ( ! V_99 -> V_63 . V_120 )
return - V_94 ;
V_113 = F_63 ( V_108 ) ;
if ( V_113 -> V_121 != V_99 -> V_63 . V_120 )
return - V_94 ;
if ( V_113 -> V_122 != V_99 -> V_63 . V_64 )
return - V_94 ;
break;
case V_123 :
if ( V_99 -> V_100 . type != F_77 ( V_106 ) )
return - V_94 ;
if ( ! V_99 -> V_63 . V_120 )
return - V_94 ;
V_115 = F_63 ( V_108 ) ;
if ( V_115 -> V_124 != V_99 -> V_63 . V_120 )
return - V_94 ;
if ( V_115 -> V_125 != V_99 -> V_63 . V_64 )
return - V_94 ;
if ( F_79 ( V_115 -> V_126 ) & 0xFFF00000 )
return - V_94 ;
break;
case V_127 :
if ( V_99 -> V_63 . V_120 != V_128 )
return - V_94 ;
return F_76 ( V_99 ) ;
case V_129 :
if ( V_99 -> V_63 . V_120 != V_130 )
return - V_94 ;
return F_76 ( V_99 ) ;
default:
return - V_94 ;
}
return 0 ;
}
static int F_80 ( const struct V_69 * V_86 )
{
static const struct V_131 V_132 [ V_133 + 1 ] = {
[ V_134 ] = { . type = V_135 } ,
[ V_136 ] = { . type = V_137 } ,
} ;
struct V_69 * V_92 [ V_133 + 1 ] ;
int error ;
error = F_81 ( V_92 , V_133 ,
V_86 , V_132 ) ;
if ( error )
return error ;
if ( ! V_92 [ V_134 ] ||
! F_82 ( V_92 [ V_134 ] ) )
return - V_94 ;
return 0 ;
}
static int F_75 ( const struct V_69 * V_86 ,
const struct V_35 * V_36 , int V_87 )
{
const struct V_69 * V_92 ;
int V_93 , V_51 ;
if ( V_87 >= V_138 )
return - V_139 ;
F_72 (a, attr, rem) {
static const V_96 V_140 [ V_141 + 1 ] = {
[ V_142 ] = sizeof( V_96 ) ,
[ V_143 ] = ( V_96 ) - 1 ,
[ V_144 ] = sizeof( struct V_145 ) ,
[ V_146 ] = 0 ,
[ V_147 ] = ( V_96 ) - 1 ,
[ V_148 ] = ( V_96 ) - 1
} ;
const struct V_145 * V_149 ;
int type = F_73 ( V_92 ) ;
if ( type > V_141 ||
( V_140 [ type ] != F_74 ( V_92 ) &&
V_140 [ type ] != ( V_96 ) - 1 ) )
return - V_94 ;
switch ( type ) {
case V_150 :
return - V_94 ;
case V_143 :
V_51 = F_80 ( V_92 ) ;
if ( V_51 )
return V_51 ;
break;
case V_142 :
if ( F_82 ( V_92 ) >= V_151 )
return - V_94 ;
break;
case V_146 :
break;
case V_144 :
V_149 = F_63 ( V_92 ) ;
if ( V_149 -> V_152 != F_77 ( V_153 ) )
return - V_94 ;
if ( ! ( V_149 -> V_74 & F_77 ( V_154 ) ) )
return - V_94 ;
break;
case V_147 :
V_51 = F_78 ( V_92 , V_36 ) ;
if ( V_51 )
return V_51 ;
break;
case V_148 :
V_51 = F_71 ( V_92 , V_36 , V_87 ) ;
if ( V_51 )
return V_51 ;
break;
default:
return - V_94 ;
}
}
if ( V_93 > 0 )
return - V_94 ;
return 0 ;
}
static void F_83 ( struct V_31 * V_32 )
{
V_32 -> V_155 = 0 ;
V_32 -> V_156 = 0 ;
V_32 -> V_157 = 0 ;
V_32 -> V_158 = 0 ;
}
static int F_84 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_162 * V_163 ;
struct V_29 * V_164 ;
struct V_31 * V_32 ;
struct V_1 * V_4 ;
struct V_165 * V_100 ;
int V_71 ;
int V_51 ;
int V_38 ;
V_51 = - V_94 ;
if ( ! V_92 [ V_82 ] || ! V_92 [ V_80 ] ||
! V_92 [ V_166 ] ||
F_74 ( V_92 [ V_82 ] ) < V_167 )
goto V_51;
V_71 = F_74 ( V_92 [ V_82 ] ) ;
V_164 = F_85 ( V_168 + V_71 , V_169 ) ;
V_51 = - V_73 ;
if ( ! V_164 )
goto V_51;
F_86 ( V_164 , V_168 ) ;
memcpy ( F_87 ( V_164 , V_71 ) , F_63 ( V_92 [ V_82 ] ) , V_71 ) ;
F_88 ( V_164 ) ;
V_100 = F_89 ( V_164 ) ;
if ( F_90 ( V_100 -> V_170 ) >= 1536 )
V_164 -> V_171 = V_100 -> V_170 ;
else
V_164 -> V_171 = F_77 ( V_172 ) ;
V_32 = F_91 () ;
V_51 = F_47 ( V_32 ) ;
if ( F_22 ( V_32 ) )
goto V_173;
V_51 = F_30 ( V_164 , - 1 , & V_32 -> V_36 , & V_38 ) ;
if ( V_51 )
goto V_174;
V_51 = F_92 ( & V_32 -> V_36 . V_175 . V_176 ,
& V_32 -> V_36 . V_175 . V_177 ,
& V_32 -> V_36 . V_175 . V_178 ,
V_92 [ V_80 ] ) ;
if ( V_51 )
goto V_174;
V_51 = F_75 ( V_92 [ V_166 ] , & V_32 -> V_36 , 0 ) ;
if ( V_51 )
goto V_174;
V_32 -> V_179 = F_93 ( & V_32 -> V_36 , V_38 ) ;
V_163 = F_94 ( V_92 [ V_166 ] ) ;
V_51 = F_47 ( V_163 ) ;
if ( F_22 ( V_163 ) )
goto V_174;
F_69 ( V_32 -> V_180 , V_163 ) ;
F_37 ( V_164 ) -> V_32 = V_32 ;
V_164 -> V_176 = V_32 -> V_36 . V_175 . V_176 ;
V_164 -> V_181 = V_32 -> V_36 . V_175 . V_177 ;
F_2 () ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
V_51 = - V_53 ;
if ( ! V_4 )
goto V_183;
F_96 () ;
V_51 = F_39 ( V_4 , V_164 ) ;
F_97 () ;
F_5 () ;
F_98 ( V_32 ) ;
return V_51 ;
V_183:
F_5 () ;
V_174:
F_98 ( V_32 ) ;
V_173:
F_32 ( V_164 ) ;
V_51:
return V_51 ;
}
static void F_99 ( struct V_1 * V_4 , struct V_184 * V_34 )
{
int V_185 ;
struct V_17 * V_18 = F_67 ( V_4 -> V_18 ) ;
V_34 -> V_186 = F_100 ( V_18 ) ;
V_34 -> V_48 = V_34 -> V_46 = V_34 -> V_54 = 0 ;
F_101 (i) {
const struct V_33 * V_187 ;
struct V_33 V_188 ;
unsigned int V_189 ;
V_187 = F_102 ( V_4 -> V_19 , V_185 ) ;
do {
V_189 = F_103 ( & V_187 -> V_49 ) ;
V_188 = * V_187 ;
} while ( F_104 ( & V_187 -> V_49 , V_189 ) );
V_34 -> V_48 += V_188 . V_48 ;
V_34 -> V_46 += V_188 . V_46 ;
V_34 -> V_54 += V_188 . V_54 ;
}
}
static int F_105 ( struct V_31 * V_32 , struct V_1 * V_4 ,
struct V_29 * V_30 , V_96 V_44 ,
V_96 V_190 , V_96 V_191 , T_3 V_41 )
{
const int V_192 = V_30 -> V_71 ;
const struct V_162 * V_180 ;
struct V_193 V_34 ;
struct V_67 * V_67 ;
struct V_69 * V_70 ;
unsigned long V_155 ;
T_3 V_156 ;
int V_51 ;
V_180 = F_106 ( V_32 -> V_180 ,
F_107 () ) ;
V_67 = F_55 ( V_30 , V_44 , V_190 , & V_194 , V_191 , V_41 ) ;
if ( ! V_67 )
return - V_195 ;
V_67 -> V_3 = F_8 ( V_4 ) ;
V_70 = F_56 ( V_30 , V_196 ) ;
if ( ! V_70 )
goto V_197;
V_51 = F_57 ( & V_32 -> V_36 , V_30 ) ;
if ( V_51 )
goto error;
F_58 ( V_30 , V_70 ) ;
F_108 ( & V_32 -> V_198 ) ;
V_155 = V_32 -> V_155 ;
V_34 . V_199 = V_32 -> V_157 ;
V_34 . V_200 = V_32 -> V_158 ;
V_156 = V_32 -> V_156 ;
F_109 ( & V_32 -> V_198 ) ;
if ( V_155 &&
F_59 ( V_30 , V_201 , F_110 ( V_155 ) ) )
goto V_197;
if ( V_34 . V_199 &&
F_111 ( V_30 , V_202 ,
sizeof( struct V_193 ) , & V_34 ) )
goto V_197;
if ( V_156 &&
F_112 ( V_30 , V_203 , V_156 ) )
goto V_197;
V_51 = F_111 ( V_30 , V_204 , V_180 -> V_205 ,
V_180 -> V_91 ) ;
if ( V_51 < 0 && V_192 )
goto error;
return F_64 ( V_30 , V_67 ) ;
V_197:
V_51 = - V_195 ;
error:
F_113 ( V_30 , V_67 ) ;
return V_51 ;
}
static struct V_29 * F_114 ( struct V_31 * V_32 )
{
const struct V_162 * V_180 ;
int V_71 ;
V_180 = F_106 ( V_32 -> V_180 ,
F_107 () ) ;
V_71 = F_53 ( V_77 ) ;
V_71 += F_53 ( V_180 -> V_205 ) ;
V_71 += F_53 ( sizeof( struct V_193 ) ) ;
V_71 += F_53 ( 1 ) ;
V_71 += F_53 ( 8 ) ;
V_71 += F_115 ( sizeof( struct V_67 ) ) ;
return F_54 ( V_71 , V_169 ) ;
}
static struct V_29 * F_116 ( struct V_31 * V_32 ,
struct V_1 * V_4 ,
V_96 V_44 , V_96 V_190 , T_3 V_41 )
{
struct V_29 * V_30 ;
int V_206 ;
V_30 = F_114 ( V_32 ) ;
if ( ! V_30 )
return F_117 ( - V_73 ) ;
V_206 = F_105 ( V_32 , V_4 , V_30 , V_44 , V_190 , 0 , V_41 ) ;
F_118 ( V_206 < 0 ) ;
return V_30 ;
}
static int F_119 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_35 V_36 ;
struct V_31 * V_32 ;
struct V_29 * V_207 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int error ;
int V_38 ;
error = - V_94 ;
if ( ! V_92 [ V_196 ] )
goto error;
error = F_120 ( & V_36 , & V_38 , V_92 [ V_196 ] ) ;
if ( error )
goto error;
if ( V_92 [ V_204 ] ) {
error = F_75 ( V_92 [ V_204 ] , & V_36 , 0 ) ;
if ( error )
goto error;
} else if ( V_160 -> V_208 -> V_41 == V_209 ) {
error = - V_94 ;
goto error;
}
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
error = - V_53 ;
if ( ! V_4 )
goto error;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_32 = F_33 ( V_18 , & V_36 , V_38 ) ;
if ( ! V_32 ) {
struct V_162 * V_163 ;
error = - V_210 ;
if ( V_160 -> V_208 -> V_41 == V_211 )
goto error;
if ( F_121 ( V_18 ) ) {
struct V_17 * V_84 ;
V_84 = F_122 ( V_18 ) ;
if ( ! F_22 ( V_84 ) ) {
F_69 ( V_4 -> V_18 , V_84 ) ;
F_70 ( V_18 ) ;
V_18 = F_67 ( V_4 -> V_18 ) ;
}
}
V_32 = F_91 () ;
if ( F_22 ( V_32 ) ) {
error = F_47 ( V_32 ) ;
goto error;
}
V_32 -> V_36 = V_36 ;
F_83 ( V_32 ) ;
V_163 = F_94 ( V_92 [ V_204 ] ) ;
error = F_47 ( V_163 ) ;
if ( F_22 ( V_163 ) )
goto V_212;
F_69 ( V_32 -> V_180 , V_163 ) ;
V_32 -> V_179 = F_93 ( & V_36 , V_38 ) ;
F_123 ( V_18 , V_32 ) ;
V_207 = F_116 ( V_32 , V_4 , V_160 -> V_213 ,
V_160 -> V_214 ,
V_209 ) ;
} else {
struct V_162 * V_215 ;
struct V_69 * V_216 ;
error = - V_217 ;
if ( V_160 -> V_208 -> V_41 == V_209 &&
V_160 -> V_218 -> V_219 & ( V_220 | V_221 ) )
goto error;
V_215 = F_106 ( V_32 -> V_180 ,
F_107 () ) ;
V_216 = V_92 [ V_204 ] ;
if ( V_216 &&
( V_215 -> V_205 != F_74 ( V_216 ) ||
memcmp ( V_215 -> V_91 , F_63 ( V_216 ) ,
V_215 -> V_205 ) ) ) {
struct V_162 * V_222 ;
V_222 = F_94 ( V_216 ) ;
error = F_47 ( V_222 ) ;
if ( F_22 ( V_222 ) )
goto error;
F_69 ( V_32 -> V_180 , V_222 ) ;
F_124 ( V_215 ) ;
}
V_207 = F_116 ( V_32 , V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_209 ) ;
if ( V_92 [ V_223 ] ) {
F_108 ( & V_32 -> V_198 ) ;
F_83 ( V_32 ) ;
F_109 ( & V_32 -> V_198 ) ;
}
}
if ( ! F_22 ( V_207 ) )
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_224 . V_225 , V_160 -> V_218 ,
V_169 ) ;
else
F_127 ( F_95 ( V_30 -> V_182 ) -> V_226 , 0 ,
V_224 . V_225 , F_47 ( V_207 ) ) ;
return 0 ;
V_212:
F_98 ( V_32 ) ;
error:
return error ;
}
static int F_128 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_35 V_36 ;
struct V_29 * V_207 ;
struct V_31 * V_32 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_51 ;
int V_38 ;
if ( ! V_92 [ V_196 ] )
return - V_94 ;
V_51 = F_120 ( & V_36 , & V_38 , V_92 [ V_196 ] ) ;
if ( V_51 )
return V_51 ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
if ( ! V_4 )
return - V_53 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_32 = F_33 ( V_18 , & V_36 , V_38 ) ;
if ( ! V_32 )
return - V_210 ;
V_207 = F_116 ( V_32 , V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_209 ) ;
if ( F_22 ( V_207 ) )
return F_47 ( V_207 ) ;
return F_129 ( V_207 , V_160 ) ;
}
static int F_130 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_35 V_36 ;
struct V_29 * V_207 ;
struct V_31 * V_32 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_51 ;
int V_38 ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
if ( ! V_4 )
return - V_53 ;
if ( ! V_92 [ V_196 ] )
return F_66 ( V_4 ) ;
V_51 = F_120 ( & V_36 , & V_38 , V_92 [ V_196 ] ) ;
if ( V_51 )
return V_51 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_32 = F_33 ( V_18 , & V_36 , V_38 ) ;
if ( ! V_32 )
return - V_210 ;
V_207 = F_114 ( V_32 ) ;
if ( ! V_207 )
return - V_73 ;
F_131 ( V_18 , V_32 ) ;
V_51 = F_105 ( V_32 , V_4 , V_207 , V_160 -> V_213 ,
V_160 -> V_214 , 0 , V_227 ) ;
F_118 ( V_51 < 0 ) ;
F_132 ( V_32 ) ;
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_224 . V_225 , V_160 -> V_218 , V_169 ) ;
return 0 ;
}
static int F_133 ( struct V_29 * V_30 , struct V_228 * V_229 )
{
struct V_67 * V_67 = F_134 ( F_135 ( V_229 -> V_230 ) ) ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
if ( ! V_4 )
return - V_53 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
for (; ; ) {
struct V_31 * V_32 ;
V_96 V_231 , V_232 ;
V_231 = V_229 -> args [ 0 ] ;
V_232 = V_229 -> args [ 1 ] ;
V_32 = F_136 ( V_18 , & V_231 , & V_232 ) ;
if ( ! V_32 )
break;
if ( F_105 ( V_32 , V_4 , V_30 ,
F_137 ( V_229 -> V_30 ) . V_44 ,
V_229 -> V_230 -> V_233 , V_234 ,
V_209 ) < 0 )
break;
V_229 -> args [ 0 ] = V_231 ;
V_229 -> args [ 1 ] = V_232 ;
}
return V_30 -> V_71 ;
}
static int F_138 ( struct V_1 * V_4 , struct V_29 * V_30 ,
V_96 V_44 , V_96 V_190 , V_96 V_191 , T_3 V_41 )
{
struct V_67 * V_67 ;
struct V_184 V_235 ;
int V_51 ;
V_67 = F_55 ( V_30 , V_44 , V_190 , & V_236 ,
V_191 , V_41 ) ;
if ( ! V_67 )
goto error;
V_67 -> V_3 = F_8 ( V_4 ) ;
F_2 () ;
V_51 = F_139 ( V_30 , V_237 , F_6 ( V_4 ) ) ;
F_5 () ;
if ( V_51 )
goto V_197;
F_99 ( V_4 , & V_235 ) ;
if ( F_111 ( V_30 , V_238 , sizeof( struct V_184 ) , & V_235 ) )
goto V_197;
return F_64 ( V_30 , V_67 ) ;
V_197:
F_113 ( V_30 , V_67 ) ;
error:
return - V_195 ;
}
static struct V_29 * F_140 ( struct V_1 * V_4 , V_96 V_44 ,
V_96 V_190 , T_3 V_41 )
{
struct V_29 * V_30 ;
int V_206 ;
V_30 = F_141 ( V_239 , V_169 ) ;
if ( ! V_30 )
return F_117 ( - V_73 ) ;
V_206 = F_138 ( V_4 , V_30 , V_44 , V_190 , 0 , V_41 ) ;
if ( V_206 < 0 ) {
F_32 ( V_30 ) ;
return F_117 ( V_206 ) ;
}
return V_30 ;
}
static struct V_1 * F_142 ( struct V_2 * V_2 ,
struct V_67 * V_67 ,
struct V_69 * V_92 [ V_240 + 1 ] )
{
struct V_1 * V_4 ;
if ( ! V_92 [ V_237 ] )
V_4 = F_1 ( V_2 , V_67 -> V_3 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_143 ( V_2 , F_63 ( V_92 [ V_237 ] ) ) ;
V_4 = V_7 && V_7 -> V_22 == V_8 ? V_7 -> V_4 : NULL ;
F_5 () ;
}
return V_4 ? V_4 : F_117 ( - V_53 ) ;
}
static int F_144 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_25 V_26 ;
struct V_29 * V_207 ;
struct V_1 * V_4 ;
struct V_7 * V_7 ;
struct V_241 * V_241 ;
int V_51 , V_185 ;
V_51 = - V_94 ;
if ( ! V_92 [ V_237 ] || ! V_92 [ V_242 ] )
goto V_51;
F_145 () ;
V_51 = - V_73 ;
V_4 = F_146 ( sizeof( * V_4 ) , V_169 ) ;
if ( V_4 == NULL )
goto V_243;
F_147 ( V_4 , F_148 ( F_95 ( V_30 -> V_182 ) ) ) ;
V_51 = - V_73 ;
F_69 ( V_4 -> V_18 , F_68 ( V_85 ) ) ;
if ( ! V_4 -> V_18 )
goto V_244;
V_4 -> V_19 = F_149 ( struct V_33 ) ;
if ( ! V_4 -> V_19 ) {
V_51 = - V_73 ;
goto V_245;
}
V_4 -> V_20 = F_150 ( V_23 * sizeof( struct V_21 ) ,
V_169 ) ;
if ( ! V_4 -> V_20 ) {
V_51 = - V_73 ;
goto V_246;
}
for ( V_185 = 0 ; V_185 < V_23 ; V_185 ++ )
F_151 ( & V_4 -> V_20 [ V_185 ] ) ;
V_26 . V_247 = F_63 ( V_92 [ V_237 ] ) ;
V_26 . type = V_248 ;
V_26 . V_249 = NULL ;
V_26 . V_4 = V_4 ;
V_26 . V_22 = V_8 ;
V_26 . V_45 = F_82 ( V_92 [ V_242 ] ) ;
V_7 = F_20 ( & V_26 ) ;
if ( F_22 ( V_7 ) ) {
V_51 = F_47 ( V_7 ) ;
if ( V_51 == - V_250 )
V_51 = - V_217 ;
goto V_251;
}
V_207 = F_140 ( V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_252 ) ;
V_51 = F_47 ( V_207 ) ;
if ( F_22 ( V_207 ) )
goto V_253;
V_241 = F_152 ( F_15 ( V_4 ) , V_254 ) ;
F_153 ( & V_4 -> V_255 , & V_241 -> V_256 ) ;
F_154 () ;
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_257 . V_225 , V_160 -> V_218 ,
V_169 ) ;
return 0 ;
V_253:
F_24 ( F_155 ( V_4 , V_8 ) ) ;
V_251:
F_16 ( V_4 -> V_20 ) ;
V_246:
F_13 ( V_4 -> V_19 ) ;
V_245:
F_12 ( F_67 ( V_4 -> V_18 ) ) ;
V_244:
F_14 ( F_15 ( V_4 ) ) ;
F_16 ( V_4 ) ;
V_243:
F_154 () ;
V_51:
return V_51 ;
}
static void F_156 ( struct V_1 * V_4 )
{
int V_185 ;
F_145 () ;
for ( V_185 = 0 ; V_185 < V_23 ; V_185 ++ ) {
struct V_7 * V_7 ;
struct V_258 * V_259 ;
F_157 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_7 -> V_22 != V_8 )
F_24 ( V_7 ) ;
}
F_158 ( & V_4 -> V_255 ) ;
F_24 ( F_155 ( V_4 , V_8 ) ) ;
F_154 () ;
F_159 ( & V_4 -> V_15 , F_10 ) ;
}
static int F_160 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_29 * V_207 ;
struct V_1 * V_4 ;
int V_51 ;
V_4 = F_142 ( F_95 ( V_30 -> V_182 ) , V_160 -> V_161 , V_160 -> V_88 ) ;
V_51 = F_47 ( V_4 ) ;
if ( F_22 ( V_4 ) )
return V_51 ;
V_207 = F_140 ( V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_260 ) ;
V_51 = F_47 ( V_207 ) ;
if ( F_22 ( V_207 ) )
return V_51 ;
F_156 ( V_4 ) ;
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_257 . V_225 , V_160 -> V_218 ,
V_169 ) ;
return 0 ;
}
static int F_161 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_29 * V_207 ;
struct V_1 * V_4 ;
int V_51 ;
V_4 = F_142 ( F_95 ( V_30 -> V_182 ) , V_160 -> V_161 , V_160 -> V_88 ) ;
if ( F_22 ( V_4 ) )
return F_47 ( V_4 ) ;
V_207 = F_140 ( V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_252 ) ;
if ( F_22 ( V_207 ) ) {
V_51 = F_47 ( V_207 ) ;
F_127 ( F_95 ( V_30 -> V_182 ) -> V_226 , 0 ,
V_257 . V_225 , V_51 ) ;
return 0 ;
}
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_257 . V_225 , V_160 -> V_218 ,
V_169 ) ;
return 0 ;
}
static int F_162 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_29 * V_207 ;
struct V_1 * V_4 ;
V_4 = F_142 ( F_95 ( V_30 -> V_182 ) , V_160 -> V_161 , V_160 -> V_88 ) ;
if ( F_22 ( V_4 ) )
return F_47 ( V_4 ) ;
V_207 = F_140 ( V_4 , V_160 -> V_213 ,
V_160 -> V_214 , V_252 ) ;
if ( F_22 ( V_207 ) )
return F_47 ( V_207 ) ;
return F_129 ( V_207 , V_160 ) ;
}
static int F_163 ( struct V_29 * V_30 , struct V_228 * V_229 )
{
struct V_241 * V_241 = F_152 ( F_95 ( V_30 -> V_182 ) , V_254 ) ;
struct V_1 * V_4 ;
int V_261 = V_229 -> args [ 0 ] ;
int V_185 = 0 ;
F_164 (dp, &ovs_net->dps, list_node) {
if ( V_185 >= V_261 &&
F_138 ( V_4 , V_30 , F_137 ( V_229 -> V_30 ) . V_44 ,
V_229 -> V_230 -> V_233 , V_234 ,
V_252 ) < 0 )
break;
V_185 ++ ;
}
V_229 -> args [ 0 ] = V_185 ;
return V_30 -> V_71 ;
}
static int F_165 ( struct V_7 * V_7 , struct V_29 * V_30 ,
V_96 V_44 , V_96 V_190 , V_96 V_191 , T_3 V_41 )
{
struct V_67 * V_67 ;
struct V_262 V_263 ;
int V_51 ;
V_67 = F_55 ( V_30 , V_44 , V_190 , & V_264 ,
V_191 , V_41 ) ;
if ( ! V_67 )
return - V_195 ;
V_67 -> V_3 = F_8 ( V_7 -> V_4 ) ;
if ( F_166 ( V_30 , V_265 , V_7 -> V_22 ) ||
F_166 ( V_30 , V_266 , V_7 -> V_9 -> type ) ||
F_139 ( V_30 , V_267 , V_7 -> V_9 -> V_10 ( V_7 ) ) ||
F_166 ( V_30 , V_268 , V_7 -> V_45 ) )
goto V_197;
F_167 ( V_7 , & V_263 ) ;
if ( F_111 ( V_30 , V_269 , sizeof( struct V_262 ) ,
& V_263 ) )
goto V_197;
V_51 = F_168 ( V_7 , V_30 ) ;
if ( V_51 == - V_195 )
goto error;
return F_64 ( V_30 , V_67 ) ;
V_197:
V_51 = - V_195 ;
error:
F_113 ( V_30 , V_67 ) ;
return V_51 ;
}
struct V_29 * F_169 ( struct V_7 * V_7 , V_96 V_44 ,
V_96 V_190 , T_3 V_41 )
{
struct V_29 * V_30 ;
int V_206 ;
V_30 = F_141 ( V_239 , V_72 ) ;
if ( ! V_30 )
return F_117 ( - V_73 ) ;
V_206 = F_165 ( V_7 , V_30 , V_44 , V_190 , 0 , V_41 ) ;
F_118 ( V_206 < 0 ) ;
return V_30 ;
}
static struct V_7 * F_170 ( struct V_2 * V_2 ,
struct V_67 * V_67 ,
struct V_69 * V_92 [ V_270 + 1 ] )
{
struct V_1 * V_4 ;
struct V_7 * V_7 ;
if ( V_92 [ V_267 ] ) {
V_7 = F_143 ( V_2 , F_63 ( V_92 [ V_267 ] ) ) ;
if ( ! V_7 )
return F_117 ( - V_53 ) ;
if ( V_67 -> V_3 &&
V_67 -> V_3 != F_8 ( V_7 -> V_4 ) )
return F_117 ( - V_53 ) ;
return V_7 ;
} else if ( V_92 [ V_265 ] ) {
V_96 V_22 = F_82 ( V_92 [ V_265 ] ) ;
if ( V_22 >= V_151 )
return F_117 ( - V_76 ) ;
V_4 = F_1 ( V_2 , V_67 -> V_3 ) ;
if ( ! V_4 )
return F_117 ( - V_53 ) ;
V_7 = F_7 ( V_4 , V_22 ) ;
if ( ! V_7 )
return F_117 ( - V_210 ) ;
return V_7 ;
} else
return F_117 ( - V_94 ) ;
}
static int F_171 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_25 V_26 ;
struct V_29 * V_207 ;
struct V_7 * V_7 ;
struct V_1 * V_4 ;
V_96 V_22 ;
int V_51 ;
V_51 = - V_94 ;
if ( ! V_92 [ V_267 ] || ! V_92 [ V_266 ] ||
! V_92 [ V_268 ] )
goto exit;
F_145 () ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
V_51 = - V_53 ;
if ( ! V_4 )
goto V_271;
if ( V_92 [ V_265 ] ) {
V_22 = F_82 ( V_92 [ V_265 ] ) ;
V_51 = - V_76 ;
if ( V_22 >= V_151 )
goto V_271;
V_7 = F_7 ( V_4 , V_22 ) ;
V_51 = - V_250 ;
if ( V_7 )
goto V_271;
} else {
for ( V_22 = 1 ; ; V_22 ++ ) {
if ( V_22 >= V_151 ) {
V_51 = - V_76 ;
goto V_271;
}
V_7 = F_155 ( V_4 , V_22 ) ;
if ( ! V_7 )
break;
}
}
V_26 . V_247 = F_63 ( V_92 [ V_267 ] ) ;
V_26 . type = F_82 ( V_92 [ V_266 ] ) ;
V_26 . V_249 = V_92 [ V_272 ] ;
V_26 . V_4 = V_4 ;
V_26 . V_22 = V_22 ;
V_26 . V_45 = F_82 ( V_92 [ V_268 ] ) ;
V_7 = F_20 ( & V_26 ) ;
V_51 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_271;
V_51 = 0 ;
V_207 = F_169 ( V_7 , V_160 -> V_213 , V_160 -> V_214 ,
V_273 ) ;
if ( F_22 ( V_207 ) ) {
V_51 = F_47 ( V_207 ) ;
F_24 ( V_7 ) ;
goto V_271;
}
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_274 . V_225 , V_160 -> V_218 , V_169 ) ;
V_271:
F_154 () ;
exit:
return V_51 ;
}
static int F_172 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_29 * V_207 ;
struct V_7 * V_7 ;
int V_51 ;
F_145 () ;
V_7 = F_170 ( F_95 ( V_30 -> V_182 ) , V_160 -> V_161 , V_92 ) ;
V_51 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_271;
V_51 = 0 ;
if ( V_92 [ V_266 ] &&
F_82 ( V_92 [ V_266 ] ) != V_7 -> V_9 -> type )
V_51 = - V_94 ;
V_207 = F_141 ( V_239 , V_169 ) ;
if ( ! V_207 ) {
V_51 = - V_73 ;
goto V_271;
}
if ( ! V_51 && V_92 [ V_272 ] )
V_51 = F_173 ( V_7 , V_92 [ V_272 ] ) ;
if ( V_51 )
goto V_275;
if ( V_92 [ V_268 ] )
V_7 -> V_45 = F_82 ( V_92 [ V_268 ] ) ;
V_51 = F_165 ( V_7 , V_207 , V_160 -> V_213 ,
V_160 -> V_214 , 0 , V_273 ) ;
F_118 ( V_51 < 0 ) ;
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_274 . V_225 , V_160 -> V_218 , V_169 ) ;
F_154 () ;
return 0 ;
V_275:
F_32 ( V_207 ) ;
V_271:
F_154 () ;
return V_51 ;
}
static int F_174 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_29 * V_207 ;
struct V_7 * V_7 ;
int V_51 ;
F_145 () ;
V_7 = F_170 ( F_95 ( V_30 -> V_182 ) , V_160 -> V_161 , V_92 ) ;
V_51 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_271;
if ( V_7 -> V_22 == V_8 ) {
V_51 = - V_94 ;
goto V_271;
}
V_207 = F_169 ( V_7 , V_160 -> V_213 , V_160 -> V_214 ,
V_276 ) ;
V_51 = F_47 ( V_207 ) ;
if ( F_22 ( V_207 ) )
goto V_271;
V_51 = 0 ;
F_24 ( V_7 ) ;
F_125 ( V_207 , F_126 ( V_160 ) , V_160 -> V_213 ,
V_274 . V_225 , V_160 -> V_218 , V_169 ) ;
V_271:
F_154 () ;
return V_51 ;
}
static int F_175 ( struct V_29 * V_30 , struct V_159 * V_160 )
{
struct V_69 * * V_92 = V_160 -> V_88 ;
struct V_67 * V_67 = V_160 -> V_161 ;
struct V_29 * V_207 ;
struct V_7 * V_7 ;
int V_51 ;
F_2 () ;
V_7 = F_170 ( F_95 ( V_30 -> V_182 ) , V_67 , V_92 ) ;
V_51 = F_47 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_271;
V_207 = F_169 ( V_7 , V_160 -> V_213 , V_160 -> V_214 ,
V_273 ) ;
V_51 = F_47 ( V_207 ) ;
if ( F_22 ( V_207 ) )
goto V_271;
F_5 () ;
return F_129 ( V_207 , V_160 ) ;
V_271:
F_5 () ;
return V_51 ;
}
static int F_176 ( struct V_29 * V_30 , struct V_228 * V_229 )
{
struct V_67 * V_67 = F_134 ( F_135 ( V_229 -> V_230 ) ) ;
struct V_1 * V_4 ;
int V_231 = V_229 -> args [ 0 ] , V_261 = V_229 -> args [ 1 ] ;
int V_185 , V_277 = 0 ;
V_4 = F_1 ( F_95 ( V_30 -> V_182 ) , V_67 -> V_3 ) ;
if ( ! V_4 )
return - V_53 ;
F_2 () ;
for ( V_185 = V_231 ; V_185 < V_23 ; V_185 ++ ) {
struct V_7 * V_7 ;
V_277 = 0 ;
F_19 (vport, &dp->ports[i], dp_hash_node) {
if ( V_277 >= V_261 &&
F_165 ( V_7 , V_30 ,
F_137 ( V_229 -> V_30 ) . V_44 ,
V_229 -> V_230 -> V_233 ,
V_234 ,
V_273 ) < 0 )
goto V_47;
V_277 ++ ;
}
V_261 = 0 ;
}
V_47:
F_5 () ;
V_229 -> args [ 0 ] = V_185 ;
V_229 -> args [ 1 ] = V_277 ;
return V_30 -> V_71 ;
}
static void F_177 ( int V_278 )
{
int V_185 ;
for ( V_185 = 0 ; V_185 < V_278 ; V_185 ++ )
F_178 ( V_279 [ V_185 ] . V_280 ) ;
}
static int F_179 ( void )
{
int V_281 ;
int V_51 ;
int V_185 ;
V_281 = 0 ;
for ( V_185 = 0 ; V_185 < F_180 ( V_279 ) ; V_185 ++ ) {
const struct V_282 * V_283 = & V_279 [ V_185 ] ;
V_51 = F_181 ( V_283 -> V_280 , V_283 -> V_9 ,
V_283 -> V_284 ) ;
if ( V_51 )
goto error;
V_281 ++ ;
if ( V_283 -> V_285 ) {
V_51 = F_182 ( V_283 -> V_280 , V_283 -> V_285 ) ;
if ( V_51 )
goto error;
}
}
return 0 ;
error:
F_177 ( V_281 ) ;
return V_51 ;
}
static void F_183 ( struct V_286 * V_287 )
{
struct V_1 * V_4 ;
struct V_2 * V_2 ;
F_184 () ;
F_145 () ;
F_185 (net) {
struct V_241 * V_241 = F_152 ( V_2 , V_254 ) ;
F_164 (dp, &ovs_net->dps, list_node) {
struct V_17 * V_83 = F_67 ( V_4 -> V_18 ) ;
struct V_17 * V_84 ;
V_84 = F_186 ( V_83 ) ;
if ( ! F_22 ( V_84 ) ) {
F_69 ( V_4 -> V_18 , V_84 ) ;
F_70 ( V_83 ) ;
}
}
}
F_154 () ;
F_187 () ;
F_188 ( & V_288 , V_289 ) ;
}
static int T_4 F_189 ( struct V_2 * V_2 )
{
struct V_241 * V_241 = F_152 ( V_2 , V_254 ) ;
F_190 ( & V_241 -> V_256 ) ;
return 0 ;
}
static void T_5 F_191 ( struct V_2 * V_2 )
{
struct V_241 * V_241 = F_152 ( V_2 , V_254 ) ;
struct V_1 * V_4 , * V_290 ;
F_184 () ;
F_192 (dp, dp_next, &ovs_net->dps, list_node)
F_156 ( V_4 ) ;
F_187 () ;
}
static int T_6 F_193 ( void )
{
int V_51 ;
F_194 ( sizeof( struct V_291 ) > F_195 ( struct V_29 , V_229 ) ) ;
F_196 ( L_1 ) ;
V_51 = F_197 () ;
if ( V_51 )
goto error;
V_51 = F_198 () ;
if ( V_51 )
goto V_292;
V_51 = F_199 ( & V_293 ) ;
if ( V_51 )
goto V_294;
V_51 = F_200 ( & V_295 ) ;
if ( V_51 )
goto V_296;
V_51 = F_179 () ;
if ( V_51 < 0 )
goto V_297;
F_188 ( & V_288 , V_289 ) ;
return 0 ;
V_297:
F_201 ( & V_295 ) ;
V_296:
F_202 ( & V_293 ) ;
V_294:
F_203 () ;
V_292:
F_204 () ;
error:
return V_51 ;
}
static void F_205 ( void )
{
F_206 ( & V_288 ) ;
F_177 ( F_180 ( V_279 ) ) ;
F_201 ( & V_295 ) ;
F_202 ( & V_293 ) ;
F_207 () ;
F_203 () ;
F_204 () ;
}
