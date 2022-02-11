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
V_36 = F_29 ( V_4 -> V_19 , F_30 () ) ;
error = F_31 ( V_32 , V_30 -> V_22 , & V_38 , & V_40 ) ;
if ( F_32 ( error ) ) {
F_33 ( V_32 ) ;
return;
}
V_34 = F_34 ( F_35 ( V_4 -> V_18 ) , & V_38 , V_40 ) ;
if ( F_32 ( ! V_34 ) ) {
struct V_41 V_42 ;
V_42 . V_43 = V_44 ;
V_42 . V_38 = & V_38 ;
V_42 . V_45 = NULL ;
V_42 . V_46 = V_30 -> V_47 ;
F_36 ( V_4 , V_32 , & V_42 ) ;
F_37 ( V_32 ) ;
V_39 = & V_36 -> V_48 ;
goto V_49;
}
F_38 ( V_32 ) -> V_34 = V_34 ;
V_39 = & V_36 -> V_50 ;
F_39 ( F_38 ( V_32 ) -> V_34 , V_32 ) ;
F_40 ( V_4 , V_32 ) ;
V_49:
F_41 ( & V_36 -> V_51 ) ;
( * V_39 ) ++ ;
F_42 ( & V_36 -> V_51 ) ;
}
int F_36 ( struct V_1 * V_4 , struct V_31 * V_32 ,
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
if ( ! F_43 ( V_32 ) )
V_53 = F_44 ( F_15 ( V_4 ) , V_3 , V_32 , V_52 ) ;
else
V_53 = F_45 ( F_15 ( V_4 ) , V_3 , V_32 , V_52 ) ;
if ( V_53 )
goto V_53;
return 0 ;
V_53:
V_36 = F_29 ( V_4 -> V_19 , F_30 () ) ;
F_41 ( & V_36 -> V_51 ) ;
V_36 -> V_56 ++ ;
F_42 ( & V_36 -> V_51 ) ;
return V_53 ;
}
static int F_45 ( struct V_2 * V_2 , int V_3 ,
struct V_31 * V_32 ,
const struct V_41 * V_52 )
{
unsigned short V_57 = F_46 ( V_32 ) -> V_57 ;
struct V_41 V_58 ;
struct V_37 V_59 ;
struct V_31 * V_60 , * V_61 ;
int V_53 ;
V_60 = F_47 ( V_32 , V_62 | V_63 ) ;
if ( F_22 ( V_60 ) )
return F_48 ( V_60 ) ;
V_32 = V_60 ;
do {
V_53 = F_44 ( V_2 , V_3 , V_32 , V_52 ) ;
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
F_33 ( V_32 ) ;
else
F_37 ( V_32 ) ;
} while ( ( V_32 = V_61 ) );
return V_53 ;
}
static int F_44 ( struct V_2 * V_2 , int V_3 ,
struct V_31 * V_32 ,
const struct V_41 * V_52 )
{
struct V_69 * V_42 ;
struct V_31 * V_61 = NULL ;
struct V_31 * V_70 ;
struct V_71 * V_72 ;
unsigned int V_73 ;
int V_53 ;
if ( F_49 ( V_32 ) ) {
V_61 = F_50 ( V_32 , V_74 ) ;
if ( ! V_61 )
return - V_75 ;
V_61 = F_51 ( V_61 , F_52 ( V_61 ) ) ;
if ( ! V_61 )
return - V_75 ;
V_61 -> V_76 = 0 ;
V_32 = V_61 ;
}
if ( F_53 ( V_32 -> V_73 ) > V_77 ) {
V_53 = - V_78 ;
goto V_49;
}
V_73 = sizeof( struct V_69 ) ;
V_73 += F_54 ( V_32 -> V_73 ) ;
V_73 += F_54 ( V_79 ) ;
if ( V_52 -> V_43 == V_80 )
V_73 += F_54 ( 8 ) ;
V_70 = F_55 ( V_73 , V_74 ) ;
if ( ! V_70 ) {
V_53 = - V_75 ;
goto V_49;
}
V_42 = F_56 ( V_70 , 0 , 0 , & V_81 ,
0 , V_52 -> V_43 ) ;
V_42 -> V_3 = V_3 ;
V_72 = F_57 ( V_70 , V_82 ) ;
F_58 ( V_52 -> V_38 , V_70 ) ;
F_59 ( V_70 , V_72 ) ;
if ( V_52 -> V_45 )
F_60 ( V_70 , V_83 ,
F_61 ( V_52 -> V_45 ) ) ;
V_72 = F_62 ( V_70 , V_84 , V_32 -> V_73 ) ;
F_63 ( V_32 , F_64 ( V_72 ) ) ;
V_53 = F_65 ( V_2 , V_70 , V_52 -> V_46 ) ;
V_49:
F_33 ( V_61 ) ;
return V_53 ;
}
static int F_66 ( struct V_1 * V_4 )
{
struct V_17 * V_85 ;
struct V_17 * V_86 ;
V_85 = F_67 ( V_4 -> V_18 ) ;
V_86 = F_68 ( V_87 ) ;
if ( ! V_86 )
return - V_75 ;
F_69 ( V_4 -> V_18 , V_86 ) ;
F_70 ( V_85 ) ;
return 0 ;
}
static int F_71 ( const struct V_71 * V_88 ,
const struct V_37 * V_38 , int V_89 )
{
const struct V_71 * V_90 [ V_91 + 1 ] ;
const struct V_71 * V_92 , * V_93 ;
const struct V_71 * V_94 ;
int V_95 ;
memset ( V_90 , 0 , sizeof( V_90 ) ) ;
F_72 (a, attr, rem) {
int type = F_73 ( V_94 ) ;
if ( ! type || type > V_91 || V_90 [ type ] )
return - V_96 ;
V_90 [ type ] = V_94 ;
}
if ( V_95 )
return - V_96 ;
V_92 = V_90 [ V_97 ] ;
if ( ! V_92 || F_74 ( V_92 ) != sizeof( V_98 ) )
return - V_96 ;
V_93 = V_90 [ V_99 ] ;
if ( ! V_93 || ( F_74 ( V_93 ) && F_74 ( V_93 ) < V_100 ) )
return - V_96 ;
return F_75 ( V_93 , V_38 , V_89 + 1 ) ;
}
static int F_76 ( const struct V_37 * V_101 )
{
if ( V_101 -> V_102 . type == F_77 ( V_103 ) ) {
if ( V_101 -> V_104 . V_105 . V_106 || V_101 -> V_104 . V_105 . V_107 )
return 0 ;
} else if ( V_101 -> V_102 . type == F_77 ( V_108 ) ) {
if ( V_101 -> V_109 . V_105 . V_106 || V_101 -> V_109 . V_105 . V_107 )
return 0 ;
}
return - V_96 ;
}
static int F_78 ( const struct V_71 * V_94 ,
const struct V_37 * V_101 )
{
const struct V_71 * V_110 = F_64 ( V_94 ) ;
int V_111 = F_73 ( V_110 ) ;
if ( F_54 ( F_74 ( V_110 ) ) != F_74 ( V_94 ) )
return - V_96 ;
if ( V_111 > V_112 ||
F_74 ( V_110 ) != V_113 [ V_111 ] )
return - V_96 ;
switch ( V_111 ) {
const struct V_114 * V_115 ;
case V_116 :
case V_117 :
break;
case V_118 :
if ( V_101 -> V_102 . type != F_77 ( V_103 ) )
return - V_96 ;
if ( ! V_101 -> V_65 . V_119 )
return - V_96 ;
V_115 = F_64 ( V_110 ) ;
if ( V_115 -> V_120 != V_101 -> V_65 . V_119 )
return - V_96 ;
if ( V_115 -> V_121 != V_101 -> V_65 . V_66 )
return - V_96 ;
break;
case V_122 :
if ( V_101 -> V_65 . V_119 != V_123 )
return - V_96 ;
return F_76 ( V_101 ) ;
case V_124 :
if ( V_101 -> V_65 . V_119 != V_125 )
return - V_96 ;
return F_76 ( V_101 ) ;
default:
return - V_96 ;
}
return 0 ;
}
static int F_79 ( const struct V_71 * V_88 )
{
static const struct V_126 V_127 [ V_128 + 1 ] = {
[ V_129 ] = { . type = V_130 } ,
[ V_131 ] = { . type = V_132 } ,
} ;
struct V_71 * V_94 [ V_128 + 1 ] ;
int error ;
error = F_80 ( V_94 , V_128 ,
V_88 , V_127 ) ;
if ( error )
return error ;
if ( ! V_94 [ V_129 ] ||
! F_81 ( V_94 [ V_129 ] ) )
return - V_96 ;
return 0 ;
}
static int F_75 ( const struct V_71 * V_88 ,
const struct V_37 * V_38 , int V_89 )
{
const struct V_71 * V_94 ;
int V_95 , V_53 ;
if ( V_89 >= V_133 )
return - V_134 ;
F_72 (a, attr, rem) {
static const V_98 V_135 [ V_136 + 1 ] = {
[ V_137 ] = sizeof( V_98 ) ,
[ V_138 ] = ( V_98 ) - 1 ,
[ V_139 ] = sizeof( struct V_140 ) ,
[ V_141 ] = 0 ,
[ V_142 ] = ( V_98 ) - 1 ,
[ V_143 ] = ( V_98 ) - 1
} ;
const struct V_140 * V_144 ;
int type = F_73 ( V_94 ) ;
if ( type > V_136 ||
( V_135 [ type ] != F_74 ( V_94 ) &&
V_135 [ type ] != ( V_98 ) - 1 ) )
return - V_96 ;
switch ( type ) {
case V_145 :
return - V_96 ;
case V_138 :
V_53 = F_79 ( V_94 ) ;
if ( V_53 )
return V_53 ;
break;
case V_137 :
if ( F_81 ( V_94 ) >= V_146 )
return - V_96 ;
break;
case V_141 :
break;
case V_139 :
V_144 = F_64 ( V_94 ) ;
if ( V_144 -> V_147 != F_77 ( V_148 ) )
return - V_96 ;
if ( ! ( V_144 -> V_76 & F_77 ( V_149 ) ) )
return - V_96 ;
break;
case V_142 :
V_53 = F_78 ( V_94 , V_38 ) ;
if ( V_53 )
return V_53 ;
break;
case V_143 :
V_53 = F_71 ( V_94 , V_38 , V_89 ) ;
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
V_34 -> V_150 = 0 ;
V_34 -> V_151 = 0 ;
V_34 -> V_152 = 0 ;
V_34 -> V_153 = 0 ;
}
static int F_83 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_157 * V_158 ;
struct V_31 * V_159 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_160 * V_102 ;
int V_73 ;
int V_53 ;
int V_40 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_84 ] || ! V_94 [ V_82 ] ||
! V_94 [ V_161 ] ||
F_74 ( V_94 [ V_84 ] ) < V_162 )
goto V_53;
V_73 = F_74 ( V_94 [ V_84 ] ) ;
V_159 = F_84 ( V_163 + V_73 , V_164 ) ;
V_53 = - V_75 ;
if ( ! V_159 )
goto V_53;
F_85 ( V_159 , V_163 ) ;
memcpy ( F_86 ( V_159 , V_73 ) , F_64 ( V_94 [ V_84 ] ) , V_73 ) ;
F_87 ( V_159 ) ;
V_102 = F_88 ( V_159 ) ;
if ( F_89 ( V_102 -> V_165 ) >= 1536 )
V_159 -> V_166 = V_102 -> V_165 ;
else
V_159 -> V_166 = F_77 ( V_167 ) ;
V_34 = F_90 () ;
V_53 = F_48 ( V_34 ) ;
if ( F_22 ( V_34 ) )
goto V_168;
V_53 = F_31 ( V_159 , - 1 , & V_34 -> V_38 , & V_40 ) ;
if ( V_53 )
goto V_169;
V_53 = F_91 ( & V_34 -> V_38 . V_170 . V_171 ,
& V_34 -> V_38 . V_170 . V_172 ,
V_94 [ V_82 ] ) ;
if ( V_53 )
goto V_169;
V_53 = F_75 ( V_94 [ V_161 ] , & V_34 -> V_38 , 0 ) ;
if ( V_53 )
goto V_169;
V_34 -> V_173 = F_92 ( & V_34 -> V_38 , V_40 ) ;
V_158 = F_93 ( V_94 [ V_161 ] ) ;
V_53 = F_48 ( V_158 ) ;
if ( F_22 ( V_158 ) )
goto V_169;
F_69 ( V_34 -> V_174 , V_158 ) ;
F_38 ( V_159 ) -> V_34 = V_34 ;
V_159 -> V_171 = V_34 -> V_38 . V_170 . V_171 ;
F_2 () ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
V_53 = - V_55 ;
if ( ! V_4 )
goto V_176;
F_95 () ;
V_53 = F_40 ( V_4 , V_159 ) ;
F_96 () ;
F_5 () ;
F_97 ( V_34 ) ;
return V_53 ;
V_176:
F_5 () ;
V_169:
F_97 ( V_34 ) ;
V_168:
F_33 ( V_159 ) ;
V_53:
return V_53 ;
}
static void F_98 ( struct V_1 * V_4 , struct V_177 * V_36 )
{
int V_178 ;
struct V_17 * V_18 = F_67 ( V_4 -> V_18 ) ;
V_36 -> V_179 = F_99 ( V_18 ) ;
V_36 -> V_50 = V_36 -> V_48 = V_36 -> V_56 = 0 ;
F_100 (i) {
const struct V_35 * V_180 ;
struct V_35 V_181 ;
unsigned int V_182 ;
V_180 = F_29 ( V_4 -> V_19 , V_178 ) ;
do {
V_182 = F_101 ( & V_180 -> V_51 ) ;
V_181 = * V_180 ;
} while ( F_102 ( & V_180 -> V_51 , V_182 ) );
V_36 -> V_50 += V_181 . V_50 ;
V_36 -> V_48 += V_181 . V_48 ;
V_36 -> V_56 += V_181 . V_56 ;
}
}
static int F_103 ( struct V_33 * V_34 , struct V_1 * V_4 ,
struct V_31 * V_32 , V_98 V_46 ,
V_98 V_183 , V_98 V_184 , T_3 V_43 )
{
const int V_185 = V_32 -> V_73 ;
const struct V_157 * V_174 ;
struct V_186 V_36 ;
struct V_69 * V_69 ;
struct V_71 * V_72 ;
unsigned long V_150 ;
T_3 V_151 ;
int V_53 ;
V_174 = F_104 ( V_34 -> V_174 ,
F_105 () ) ;
V_69 = F_56 ( V_32 , V_46 , V_183 , & V_187 , V_184 , V_43 ) ;
if ( ! V_69 )
return - V_188 ;
V_69 -> V_3 = F_8 ( V_4 ) ;
V_72 = F_57 ( V_32 , V_189 ) ;
if ( ! V_72 )
goto V_190;
V_53 = F_58 ( & V_34 -> V_38 , V_32 ) ;
if ( V_53 )
goto error;
F_59 ( V_32 , V_72 ) ;
F_106 ( & V_34 -> V_191 ) ;
V_150 = V_34 -> V_150 ;
V_36 . V_192 = V_34 -> V_152 ;
V_36 . V_193 = V_34 -> V_153 ;
V_151 = V_34 -> V_151 ;
F_107 ( & V_34 -> V_191 ) ;
if ( V_150 &&
F_60 ( V_32 , V_194 , F_108 ( V_150 ) ) )
goto V_190;
if ( V_36 . V_192 &&
F_109 ( V_32 , V_195 ,
sizeof( struct V_186 ) , & V_36 ) )
goto V_190;
if ( V_151 &&
F_110 ( V_32 , V_196 , V_151 ) )
goto V_190;
V_53 = F_109 ( V_32 , V_197 , V_174 -> V_198 ,
V_174 -> V_93 ) ;
if ( V_53 < 0 && V_185 )
goto error;
return F_111 ( V_32 , V_69 ) ;
V_190:
V_53 = - V_188 ;
error:
F_112 ( V_32 , V_69 ) ;
return V_53 ;
}
static struct V_31 * F_113 ( struct V_33 * V_34 )
{
const struct V_157 * V_174 ;
int V_73 ;
V_174 = F_104 ( V_34 -> V_174 ,
F_105 () ) ;
V_73 = F_54 ( V_79 ) ;
V_73 += F_54 ( V_174 -> V_198 ) ;
V_73 += F_54 ( sizeof( struct V_186 ) ) ;
V_73 += F_54 ( 1 ) ;
V_73 += F_54 ( 8 ) ;
V_73 += F_114 ( sizeof( struct V_69 ) ) ;
return F_55 ( V_73 , V_164 ) ;
}
static struct V_31 * F_115 ( struct V_33 * V_34 ,
struct V_1 * V_4 ,
V_98 V_46 , V_98 V_183 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_199 ;
V_32 = F_113 ( V_34 ) ;
if ( ! V_32 )
return F_116 ( - V_75 ) ;
V_199 = F_103 ( V_34 , V_4 , V_32 , V_46 , V_183 , 0 , V_43 ) ;
F_117 ( V_199 < 0 ) ;
return V_32 ;
}
static int F_118 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_37 V_38 ;
struct V_33 * V_34 ;
struct V_31 * V_200 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int error ;
int V_40 ;
error = - V_96 ;
if ( ! V_94 [ V_189 ] )
goto error;
error = F_119 ( & V_38 , & V_40 , V_94 [ V_189 ] ) ;
if ( error )
goto error;
if ( V_94 [ V_197 ] ) {
error = F_75 ( V_94 [ V_197 ] , & V_38 , 0 ) ;
if ( error )
goto error;
} else if ( V_155 -> V_201 -> V_43 == V_202 ) {
error = - V_96 ;
goto error;
}
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
error = - V_55 ;
if ( ! V_4 )
goto error;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_34 = F_34 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 ) {
struct V_157 * V_158 ;
error = - V_203 ;
if ( V_155 -> V_201 -> V_43 == V_204 )
goto error;
if ( F_120 ( V_18 ) ) {
struct V_17 * V_86 ;
V_86 = F_121 ( V_18 ) ;
if ( ! F_22 ( V_86 ) ) {
F_69 ( V_4 -> V_18 , V_86 ) ;
F_70 ( V_18 ) ;
V_18 = F_67 ( V_4 -> V_18 ) ;
}
}
V_34 = F_90 () ;
if ( F_22 ( V_34 ) ) {
error = F_48 ( V_34 ) ;
goto error;
}
V_34 -> V_38 = V_38 ;
F_82 ( V_34 ) ;
V_158 = F_93 ( V_94 [ V_197 ] ) ;
error = F_48 ( V_158 ) ;
if ( F_22 ( V_158 ) )
goto V_205;
F_69 ( V_34 -> V_174 , V_158 ) ;
V_34 -> V_173 = F_92 ( & V_38 , V_40 ) ;
F_122 ( V_18 , V_34 ) ;
V_200 = F_115 ( V_34 , V_4 , V_155 -> V_206 ,
V_155 -> V_207 ,
V_202 ) ;
} else {
struct V_157 * V_208 ;
struct V_71 * V_209 ;
error = - V_210 ;
if ( V_155 -> V_201 -> V_43 == V_202 &&
V_155 -> V_211 -> V_212 & ( V_213 | V_214 ) )
goto error;
V_208 = F_104 ( V_34 -> V_174 ,
F_105 () ) ;
V_209 = V_94 [ V_197 ] ;
if ( V_209 &&
( V_208 -> V_198 != F_74 ( V_209 ) ||
memcmp ( V_208 -> V_93 , F_64 ( V_209 ) ,
V_208 -> V_198 ) ) ) {
struct V_157 * V_215 ;
V_215 = F_93 ( V_209 ) ;
error = F_48 ( V_215 ) ;
if ( F_22 ( V_215 ) )
goto error;
F_69 ( V_34 -> V_174 , V_215 ) ;
F_123 ( V_208 ) ;
}
V_200 = F_115 ( V_34 , V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_202 ) ;
if ( V_94 [ V_216 ] ) {
F_106 ( & V_34 -> V_191 ) ;
F_82 ( V_34 ) ;
F_107 ( & V_34 -> V_191 ) ;
}
}
if ( ! F_22 ( V_200 ) )
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_217 . V_218 , V_155 -> V_211 ,
V_164 ) ;
else
F_126 ( F_94 ( V_32 -> V_175 ) -> V_219 , 0 ,
V_217 . V_218 , F_48 ( V_200 ) ) ;
return 0 ;
V_205:
F_97 ( V_34 ) ;
error:
return error ;
}
static int F_127 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_37 V_38 ;
struct V_31 * V_200 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_53 ;
int V_40 ;
if ( ! V_94 [ V_189 ] )
return - V_96 ;
V_53 = F_119 ( & V_38 , & V_40 , V_94 [ V_189 ] ) ;
if ( V_53 )
return V_53 ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_34 = F_34 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 )
return - V_203 ;
V_200 = F_115 ( V_34 , V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_202 ) ;
if ( F_22 ( V_200 ) )
return F_48 ( V_200 ) ;
return F_128 ( V_200 , V_155 ) ;
}
static int F_129 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_37 V_38 ;
struct V_31 * V_200 ;
struct V_33 * V_34 ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
int V_53 ;
int V_40 ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
if ( ! V_94 [ V_189 ] )
return F_66 ( V_4 ) ;
V_53 = F_119 ( & V_38 , & V_40 , V_94 [ V_189 ] ) ;
if ( V_53 )
return V_53 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
V_34 = F_34 ( V_18 , & V_38 , V_40 ) ;
if ( ! V_34 )
return - V_203 ;
V_200 = F_113 ( V_34 ) ;
if ( ! V_200 )
return - V_75 ;
F_130 ( V_18 , V_34 ) ;
V_53 = F_103 ( V_34 , V_4 , V_200 , V_155 -> V_206 ,
V_155 -> V_207 , 0 , V_220 ) ;
F_117 ( V_53 < 0 ) ;
F_131 ( V_34 ) ;
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_217 . V_218 , V_155 -> V_211 , V_164 ) ;
return 0 ;
}
static int F_132 ( struct V_31 * V_32 , struct V_221 * V_222 )
{
struct V_69 * V_69 = F_133 ( F_134 ( V_222 -> V_223 ) ) ;
struct V_1 * V_4 ;
struct V_17 * V_18 ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
V_18 = F_67 ( V_4 -> V_18 ) ;
for (; ; ) {
struct V_33 * V_34 ;
V_98 V_224 , V_225 ;
V_224 = V_222 -> args [ 0 ] ;
V_225 = V_222 -> args [ 1 ] ;
V_34 = F_135 ( V_18 , & V_224 , & V_225 ) ;
if ( ! V_34 )
break;
if ( F_103 ( V_34 , V_4 , V_32 ,
F_136 ( V_222 -> V_32 ) . V_46 ,
V_222 -> V_223 -> V_226 , V_227 ,
V_202 ) < 0 )
break;
V_222 -> args [ 0 ] = V_224 ;
V_222 -> args [ 1 ] = V_225 ;
}
return V_32 -> V_73 ;
}
static int F_137 ( struct V_1 * V_4 , struct V_31 * V_32 ,
V_98 V_46 , V_98 V_183 , V_98 V_184 , T_3 V_43 )
{
struct V_69 * V_69 ;
struct V_177 V_228 ;
int V_53 ;
V_69 = F_56 ( V_32 , V_46 , V_183 , & V_229 ,
V_184 , V_43 ) ;
if ( ! V_69 )
goto error;
V_69 -> V_3 = F_8 ( V_4 ) ;
F_2 () ;
V_53 = F_138 ( V_32 , V_230 , F_6 ( V_4 ) ) ;
F_5 () ;
if ( V_53 )
goto V_190;
F_98 ( V_4 , & V_228 ) ;
if ( F_109 ( V_32 , V_231 , sizeof( struct V_177 ) , & V_228 ) )
goto V_190;
return F_111 ( V_32 , V_69 ) ;
V_190:
F_112 ( V_32 , V_69 ) ;
error:
return - V_188 ;
}
static struct V_31 * F_139 ( struct V_1 * V_4 , V_98 V_46 ,
V_98 V_183 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_199 ;
V_32 = F_140 ( V_232 , V_164 ) ;
if ( ! V_32 )
return F_116 ( - V_75 ) ;
V_199 = F_137 ( V_4 , V_32 , V_46 , V_183 , 0 , V_43 ) ;
if ( V_199 < 0 ) {
F_33 ( V_32 ) ;
return F_116 ( V_199 ) ;
}
return V_32 ;
}
static struct V_1 * F_141 ( struct V_2 * V_2 ,
struct V_69 * V_69 ,
struct V_71 * V_94 [ V_233 + 1 ] )
{
struct V_1 * V_4 ;
if ( ! V_94 [ V_230 ] )
V_4 = F_1 ( V_2 , V_69 -> V_3 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_142 ( V_2 , F_64 ( V_94 [ V_230 ] ) ) ;
V_4 = V_7 && V_7 -> V_22 == V_8 ? V_7 -> V_4 : NULL ;
F_5 () ;
}
return V_4 ? V_4 : F_116 ( - V_55 ) ;
}
static int F_143 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_27 V_28 ;
struct V_31 * V_200 ;
struct V_1 * V_4 ;
struct V_7 * V_7 ;
struct V_234 * V_234 ;
int V_53 , V_178 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_230 ] || ! V_94 [ V_235 ] )
goto V_53;
F_144 () ;
V_53 = - V_75 ;
V_4 = F_145 ( sizeof( * V_4 ) , V_164 ) ;
if ( V_4 == NULL )
goto V_236;
F_146 ( V_4 , F_147 ( F_94 ( V_32 -> V_175 ) ) ) ;
V_53 = - V_75 ;
F_69 ( V_4 -> V_18 , F_68 ( V_87 ) ) ;
if ( ! V_4 -> V_18 )
goto V_237;
V_4 -> V_19 = F_148 ( struct V_35 ) ;
if ( ! V_4 -> V_19 ) {
V_53 = - V_75 ;
goto V_238;
}
V_4 -> V_20 = F_149 ( V_23 * sizeof( struct V_21 ) ,
V_164 ) ;
if ( ! V_4 -> V_20 ) {
V_53 = - V_75 ;
goto V_239;
}
for ( V_178 = 0 ; V_178 < V_23 ; V_178 ++ )
F_150 ( & V_4 -> V_20 [ V_178 ] ) ;
V_28 . V_240 = F_64 ( V_94 [ V_230 ] ) ;
V_28 . type = V_241 ;
V_28 . V_242 = NULL ;
V_28 . V_4 = V_4 ;
V_28 . V_22 = V_8 ;
V_28 . V_47 = F_81 ( V_94 [ V_235 ] ) ;
V_7 = F_20 ( & V_28 ) ;
if ( F_22 ( V_7 ) ) {
V_53 = F_48 ( V_7 ) ;
if ( V_53 == - V_243 )
V_53 = - V_210 ;
goto V_244;
}
V_200 = F_139 ( V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_245 ) ;
V_53 = F_48 ( V_200 ) ;
if ( F_22 ( V_200 ) )
goto V_246;
V_234 = F_151 ( F_15 ( V_4 ) , V_247 ) ;
F_152 ( & V_4 -> V_248 , & V_234 -> V_249 ) ;
F_153 () ;
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_250 . V_218 , V_155 -> V_211 ,
V_164 ) ;
return 0 ;
V_246:
F_24 ( F_154 ( V_4 , V_8 ) ) ;
V_244:
F_16 ( V_4 -> V_20 ) ;
V_239:
F_13 ( V_4 -> V_19 ) ;
V_238:
F_12 ( F_67 ( V_4 -> V_18 ) ) ;
V_237:
F_14 ( F_15 ( V_4 ) ) ;
F_16 ( V_4 ) ;
V_236:
F_153 () ;
V_53:
return V_53 ;
}
static void F_155 ( struct V_1 * V_4 )
{
int V_178 ;
F_144 () ;
for ( V_178 = 0 ; V_178 < V_23 ; V_178 ++ ) {
struct V_7 * V_7 ;
struct V_24 * V_251 , * V_25 ;
F_156 (vport, node, n, &dp->ports[i], dp_hash_node)
if ( V_7 -> V_22 != V_8 )
F_24 ( V_7 ) ;
}
F_157 ( & V_4 -> V_248 ) ;
F_24 ( F_154 ( V_4 , V_8 ) ) ;
F_153 () ;
F_158 ( & V_4 -> V_15 , F_10 ) ;
}
static int F_159 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_31 * V_200 ;
struct V_1 * V_4 ;
int V_53 ;
V_4 = F_141 ( F_94 ( V_32 -> V_175 ) , V_155 -> V_156 , V_155 -> V_90 ) ;
V_53 = F_48 ( V_4 ) ;
if ( F_22 ( V_4 ) )
return V_53 ;
V_200 = F_139 ( V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_252 ) ;
V_53 = F_48 ( V_200 ) ;
if ( F_22 ( V_200 ) )
return V_53 ;
F_155 ( V_4 ) ;
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_250 . V_218 , V_155 -> V_211 ,
V_164 ) ;
return 0 ;
}
static int F_160 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_31 * V_200 ;
struct V_1 * V_4 ;
int V_53 ;
V_4 = F_141 ( F_94 ( V_32 -> V_175 ) , V_155 -> V_156 , V_155 -> V_90 ) ;
if ( F_22 ( V_4 ) )
return F_48 ( V_4 ) ;
V_200 = F_139 ( V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_245 ) ;
if ( F_22 ( V_200 ) ) {
V_53 = F_48 ( V_200 ) ;
F_126 ( F_94 ( V_32 -> V_175 ) -> V_219 , 0 ,
V_250 . V_218 , V_53 ) ;
return 0 ;
}
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_250 . V_218 , V_155 -> V_211 ,
V_164 ) ;
return 0 ;
}
static int F_161 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_31 * V_200 ;
struct V_1 * V_4 ;
V_4 = F_141 ( F_94 ( V_32 -> V_175 ) , V_155 -> V_156 , V_155 -> V_90 ) ;
if ( F_22 ( V_4 ) )
return F_48 ( V_4 ) ;
V_200 = F_139 ( V_4 , V_155 -> V_206 ,
V_155 -> V_207 , V_245 ) ;
if ( F_22 ( V_200 ) )
return F_48 ( V_200 ) ;
return F_128 ( V_200 , V_155 ) ;
}
static int F_162 ( struct V_31 * V_32 , struct V_221 * V_222 )
{
struct V_234 * V_234 = F_151 ( F_94 ( V_32 -> V_175 ) , V_247 ) ;
struct V_1 * V_4 ;
int V_253 = V_222 -> args [ 0 ] ;
int V_178 = 0 ;
F_163 (dp, &ovs_net->dps, list_node) {
if ( V_178 >= V_253 &&
F_137 ( V_4 , V_32 , F_136 ( V_222 -> V_32 ) . V_46 ,
V_222 -> V_223 -> V_226 , V_227 ,
V_245 ) < 0 )
break;
V_178 ++ ;
}
V_222 -> args [ 0 ] = V_178 ;
return V_32 -> V_73 ;
}
static int F_164 ( struct V_7 * V_7 , struct V_31 * V_32 ,
V_98 V_46 , V_98 V_183 , V_98 V_184 , T_3 V_43 )
{
struct V_69 * V_69 ;
struct V_254 V_255 ;
int V_53 ;
V_69 = F_56 ( V_32 , V_46 , V_183 , & V_256 ,
V_184 , V_43 ) ;
if ( ! V_69 )
return - V_188 ;
V_69 -> V_3 = F_8 ( V_7 -> V_4 ) ;
if ( F_165 ( V_32 , V_257 , V_7 -> V_22 ) ||
F_165 ( V_32 , V_258 , V_7 -> V_9 -> type ) ||
F_138 ( V_32 , V_259 , V_7 -> V_9 -> V_10 ( V_7 ) ) ||
F_165 ( V_32 , V_260 , V_7 -> V_47 ) )
goto V_190;
F_166 ( V_7 , & V_255 ) ;
if ( F_109 ( V_32 , V_261 , sizeof( struct V_254 ) ,
& V_255 ) )
goto V_190;
V_53 = F_167 ( V_7 , V_32 ) ;
if ( V_53 == - V_188 )
goto error;
return F_111 ( V_32 , V_69 ) ;
V_190:
V_53 = - V_188 ;
error:
F_112 ( V_32 , V_69 ) ;
return V_53 ;
}
struct V_31 * F_168 ( struct V_7 * V_7 , V_98 V_46 ,
V_98 V_183 , T_3 V_43 )
{
struct V_31 * V_32 ;
int V_199 ;
V_32 = F_140 ( V_232 , V_74 ) ;
if ( ! V_32 )
return F_116 ( - V_75 ) ;
V_199 = F_164 ( V_7 , V_32 , V_46 , V_183 , 0 , V_43 ) ;
if ( V_199 < 0 ) {
F_33 ( V_32 ) ;
return F_116 ( V_199 ) ;
}
return V_32 ;
}
static struct V_7 * F_169 ( struct V_2 * V_2 ,
struct V_69 * V_69 ,
struct V_71 * V_94 [ V_262 + 1 ] )
{
struct V_1 * V_4 ;
struct V_7 * V_7 ;
if ( V_94 [ V_259 ] ) {
V_7 = F_142 ( V_2 , F_64 ( V_94 [ V_259 ] ) ) ;
if ( ! V_7 )
return F_116 ( - V_55 ) ;
if ( V_69 -> V_3 &&
V_69 -> V_3 != F_8 ( V_7 -> V_4 ) )
return F_116 ( - V_55 ) ;
return V_7 ;
} else if ( V_94 [ V_257 ] ) {
V_98 V_22 = F_81 ( V_94 [ V_257 ] ) ;
if ( V_22 >= V_146 )
return F_116 ( - V_78 ) ;
V_4 = F_1 ( V_2 , V_69 -> V_3 ) ;
if ( ! V_4 )
return F_116 ( - V_55 ) ;
V_7 = F_7 ( V_4 , V_22 ) ;
if ( ! V_7 )
return F_116 ( - V_203 ) ;
return V_7 ;
} else
return F_116 ( - V_96 ) ;
}
static int F_170 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_27 V_28 ;
struct V_31 * V_200 ;
struct V_7 * V_7 ;
struct V_1 * V_4 ;
V_98 V_22 ;
int V_53 ;
V_53 = - V_96 ;
if ( ! V_94 [ V_259 ] || ! V_94 [ V_258 ] ||
! V_94 [ V_260 ] )
goto exit;
F_144 () ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
V_53 = - V_55 ;
if ( ! V_4 )
goto V_263;
if ( V_94 [ V_257 ] ) {
V_22 = F_81 ( V_94 [ V_257 ] ) ;
V_53 = - V_78 ;
if ( V_22 >= V_146 )
goto V_263;
V_7 = F_7 ( V_4 , V_22 ) ;
V_53 = - V_243 ;
if ( V_7 )
goto V_263;
} else {
for ( V_22 = 1 ; ; V_22 ++ ) {
if ( V_22 >= V_146 ) {
V_53 = - V_78 ;
goto V_263;
}
V_7 = F_154 ( V_4 , V_22 ) ;
if ( ! V_7 )
break;
}
}
V_28 . V_240 = F_64 ( V_94 [ V_259 ] ) ;
V_28 . type = F_81 ( V_94 [ V_258 ] ) ;
V_28 . V_242 = V_94 [ V_264 ] ;
V_28 . V_4 = V_4 ;
V_28 . V_22 = V_22 ;
V_28 . V_47 = F_81 ( V_94 [ V_260 ] ) ;
V_7 = F_20 ( & V_28 ) ;
V_53 = F_48 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_263;
V_200 = F_168 ( V_7 , V_155 -> V_206 , V_155 -> V_207 ,
V_265 ) ;
if ( F_22 ( V_200 ) ) {
V_53 = F_48 ( V_200 ) ;
F_24 ( V_7 ) ;
goto V_263;
}
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_266 . V_218 , V_155 -> V_211 , V_164 ) ;
V_263:
F_153 () ;
exit:
return V_53 ;
}
static int F_171 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_31 * V_200 ;
struct V_7 * V_7 ;
int V_53 ;
F_144 () ;
V_7 = F_169 ( F_94 ( V_32 -> V_175 ) , V_155 -> V_156 , V_94 ) ;
V_53 = F_48 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_263;
V_53 = 0 ;
if ( V_94 [ V_258 ] &&
F_81 ( V_94 [ V_258 ] ) != V_7 -> V_9 -> type )
V_53 = - V_96 ;
if ( ! V_53 && V_94 [ V_264 ] )
V_53 = F_172 ( V_7 , V_94 [ V_264 ] ) ;
if ( V_53 )
goto V_263;
if ( V_94 [ V_260 ] )
V_7 -> V_47 = F_81 ( V_94 [ V_260 ] ) ;
V_200 = F_168 ( V_7 , V_155 -> V_206 , V_155 -> V_207 ,
V_265 ) ;
if ( F_22 ( V_200 ) ) {
F_126 ( F_94 ( V_32 -> V_175 ) -> V_219 , 0 ,
V_266 . V_218 , F_48 ( V_200 ) ) ;
goto V_263;
}
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_266 . V_218 , V_155 -> V_211 , V_164 ) ;
V_263:
F_153 () ;
return V_53 ;
}
static int F_173 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_31 * V_200 ;
struct V_7 * V_7 ;
int V_53 ;
F_144 () ;
V_7 = F_169 ( F_94 ( V_32 -> V_175 ) , V_155 -> V_156 , V_94 ) ;
V_53 = F_48 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_263;
if ( V_7 -> V_22 == V_8 ) {
V_53 = - V_96 ;
goto V_263;
}
V_200 = F_168 ( V_7 , V_155 -> V_206 , V_155 -> V_207 ,
V_267 ) ;
V_53 = F_48 ( V_200 ) ;
if ( F_22 ( V_200 ) )
goto V_263;
F_24 ( V_7 ) ;
F_124 ( V_200 , F_125 ( V_155 ) , V_155 -> V_206 ,
V_266 . V_218 , V_155 -> V_211 , V_164 ) ;
V_263:
F_153 () ;
return V_53 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_154 * V_155 )
{
struct V_71 * * V_94 = V_155 -> V_90 ;
struct V_69 * V_69 = V_155 -> V_156 ;
struct V_31 * V_200 ;
struct V_7 * V_7 ;
int V_53 ;
F_2 () ;
V_7 = F_169 ( F_94 ( V_32 -> V_175 ) , V_69 , V_94 ) ;
V_53 = F_48 ( V_7 ) ;
if ( F_22 ( V_7 ) )
goto V_263;
V_200 = F_168 ( V_7 , V_155 -> V_206 , V_155 -> V_207 ,
V_265 ) ;
V_53 = F_48 ( V_200 ) ;
if ( F_22 ( V_200 ) )
goto V_263;
F_5 () ;
return F_128 ( V_200 , V_155 ) ;
V_263:
F_5 () ;
return V_53 ;
}
static int F_175 ( struct V_31 * V_32 , struct V_221 * V_222 )
{
struct V_69 * V_69 = F_133 ( F_134 ( V_222 -> V_223 ) ) ;
struct V_1 * V_4 ;
int V_224 = V_222 -> args [ 0 ] , V_253 = V_222 -> args [ 1 ] ;
int V_178 , V_268 = 0 ;
V_4 = F_1 ( F_94 ( V_32 -> V_175 ) , V_69 -> V_3 ) ;
if ( ! V_4 )
return - V_55 ;
F_2 () ;
for ( V_178 = V_224 ; V_178 < V_23 ; V_178 ++ ) {
struct V_7 * V_7 ;
struct V_24 * V_25 ;
V_268 = 0 ;
F_19 (vport, n, &dp->ports[i], dp_hash_node) {
if ( V_268 >= V_253 &&
F_164 ( V_7 , V_32 ,
F_136 ( V_222 -> V_32 ) . V_46 ,
V_222 -> V_223 -> V_226 ,
V_227 ,
V_265 ) < 0 )
goto V_49;
V_268 ++ ;
}
V_253 = 0 ;
}
V_49:
F_5 () ;
V_222 -> args [ 0 ] = V_178 ;
V_222 -> args [ 1 ] = V_268 ;
return V_32 -> V_73 ;
}
static void F_176 ( int V_269 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_269 ; V_178 ++ )
F_177 ( V_270 [ V_178 ] . V_271 ) ;
}
static int F_178 ( void )
{
int V_272 ;
int V_53 ;
int V_178 ;
V_272 = 0 ;
for ( V_178 = 0 ; V_178 < F_179 ( V_270 ) ; V_178 ++ ) {
const struct V_273 * V_274 = & V_270 [ V_178 ] ;
V_53 = F_180 ( V_274 -> V_271 , V_274 -> V_9 ,
V_274 -> V_275 ) ;
if ( V_53 )
goto error;
V_272 ++ ;
if ( V_274 -> V_276 ) {
V_53 = F_181 ( V_274 -> V_271 , V_274 -> V_276 ) ;
if ( V_53 )
goto error;
}
}
return 0 ;
error:
F_176 ( V_272 ) ;
return V_53 ;
}
static void F_182 ( struct V_277 * V_278 )
{
struct V_1 * V_4 ;
struct V_2 * V_2 ;
F_183 () ;
F_144 () ;
F_184 (net) {
struct V_234 * V_234 = F_151 ( V_2 , V_247 ) ;
F_163 (dp, &ovs_net->dps, list_node) {
struct V_17 * V_85 = F_67 ( V_4 -> V_18 ) ;
struct V_17 * V_86 ;
V_86 = F_185 ( V_85 ) ;
if ( ! F_22 ( V_86 ) ) {
F_69 ( V_4 -> V_18 , V_86 ) ;
F_70 ( V_85 ) ;
}
}
}
F_153 () ;
F_186 () ;
F_187 ( & V_279 , V_280 ) ;
}
static int T_4 F_188 ( struct V_2 * V_2 )
{
struct V_234 * V_234 = F_151 ( V_2 , V_247 ) ;
F_189 ( & V_234 -> V_249 ) ;
return 0 ;
}
static void T_5 F_190 ( struct V_2 * V_2 )
{
struct V_234 * V_234 = F_151 ( V_2 , V_247 ) ;
struct V_1 * V_4 , * V_281 ;
F_183 () ;
F_191 (dp, dp_next, &ovs_net->dps, list_node)
F_155 ( V_4 ) ;
F_186 () ;
}
static int T_6 F_192 ( void )
{
struct V_31 * V_282 ;
int V_53 ;
F_193 ( sizeof( struct V_283 ) > sizeof( V_282 -> V_222 ) ) ;
F_194 ( L_1 ) ;
V_53 = F_195 () ;
if ( V_53 )
goto error;
V_53 = F_196 () ;
if ( V_53 )
goto V_284;
V_53 = F_197 ( & V_285 ) ;
if ( V_53 )
goto V_286;
V_53 = F_198 ( & V_287 ) ;
if ( V_53 )
goto V_288;
V_53 = F_178 () ;
if ( V_53 < 0 )
goto V_289;
F_187 ( & V_279 , V_280 ) ;
return 0 ;
V_289:
F_199 ( & V_287 ) ;
V_288:
F_200 ( & V_285 ) ;
V_286:
F_201 () ;
V_284:
F_202 () ;
error:
return V_53 ;
}
static void F_203 ( void )
{
F_204 ( & V_279 ) ;
F_176 ( F_179 ( V_270 ) ) ;
F_199 ( & V_287 ) ;
F_200 ( & V_285 ) ;
F_205 () ;
F_201 () ;
F_202 () ;
}
