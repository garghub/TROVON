static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = NULL ;
struct V_4 * V_5 ;
F_2 () ;
V_5 = F_3 ( & V_6 , V_2 ) ;
if ( V_5 ) {
struct V_7 * V_7 = F_4 ( V_5 ) ;
if ( V_7 )
V_3 = V_7 -> V_3 ;
}
F_5 () ;
return V_3 ;
}
const char * F_6 ( const struct V_1 * V_3 )
{
struct V_7 * V_7 = F_7 ( V_3 -> V_8 [ V_9 ] ) ;
return V_7 -> V_10 -> V_11 ( V_7 ) ;
}
static int F_8 ( struct V_1 * V_3 )
{
struct V_7 * V_12 ;
int V_13 ;
F_2 () ;
V_12 = F_9 ( V_3 -> V_8 [ V_9 ] ) ;
if ( V_12 )
V_13 = V_12 -> V_10 -> V_14 ( V_12 ) ;
else
V_13 = 0 ;
F_5 () ;
return V_13 ;
}
static void F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_3 = F_11 ( V_16 , struct V_1 , V_16 ) ;
F_12 ( ( V_17 struct V_18 * ) V_3 -> V_19 ) ;
F_13 ( V_3 -> V_20 ) ;
F_14 ( V_3 ) ;
}
static struct V_7 * F_15 ( const struct V_21 * V_22 )
{
struct V_7 * V_7 ;
V_7 = F_16 ( V_22 ) ;
if ( ! F_17 ( V_7 ) ) {
struct V_1 * V_3 = V_22 -> V_3 ;
F_18 ( V_3 -> V_8 [ V_22 -> V_23 ] , V_7 ) ;
F_19 ( & V_7 -> V_24 , & V_3 -> V_25 ) ;
}
return V_7 ;
}
void F_20 ( struct V_7 * V_26 )
{
F_21 () ;
F_22 ( & V_26 -> V_24 ) ;
F_18 ( V_26 -> V_3 -> V_8 [ V_26 -> V_23 ] , NULL ) ;
F_23 ( V_26 ) ;
}
void F_24 ( struct V_7 * V_26 , struct V_27 * V_28 )
{
struct V_1 * V_3 = V_26 -> V_3 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
T_1 * V_35 ;
int error ;
int V_36 ;
V_32 = F_25 ( V_3 -> V_20 , F_26 () ) ;
error = F_27 ( V_28 , V_26 -> V_23 , & V_34 , & V_36 ) ;
if ( F_28 ( error ) ) {
F_29 ( V_28 ) ;
return;
}
V_30 = F_30 ( F_9 ( V_3 -> V_19 ) , & V_34 , V_36 ) ;
if ( F_28 ( ! V_30 ) ) {
struct V_37 V_38 ;
V_38 . V_39 = V_40 ;
V_38 . V_34 = & V_34 ;
V_38 . V_41 = NULL ;
V_38 . V_42 = V_26 -> V_43 ;
F_31 ( V_3 , V_28 , & V_38 ) ;
F_32 ( V_28 ) ;
V_35 = & V_32 -> V_44 ;
goto V_45;
}
F_33 ( V_28 ) -> V_30 = V_30 ;
V_35 = & V_32 -> V_46 ;
F_34 ( F_33 ( V_28 ) -> V_30 , V_28 ) ;
F_35 ( V_3 , V_28 ) ;
V_45:
F_36 ( & V_32 -> V_47 ) ;
( * V_35 ) ++ ;
F_37 ( & V_32 -> V_47 ) ;
}
int F_31 ( struct V_1 * V_3 , struct V_27 * V_28 ,
const struct V_37 * V_48 )
{
struct V_31 * V_32 ;
int V_2 ;
int V_49 ;
if ( V_48 -> V_42 == 0 ) {
V_49 = - V_50 ;
goto V_49;
}
V_2 = F_8 ( V_3 ) ;
if ( ! V_2 ) {
V_49 = - V_51 ;
goto V_49;
}
if ( ! F_38 ( V_28 ) )
V_49 = F_39 ( V_2 , V_28 , V_48 ) ;
else
V_49 = F_40 ( V_2 , V_28 , V_48 ) ;
if ( V_49 )
goto V_49;
return 0 ;
V_49:
V_32 = F_25 ( V_3 -> V_20 , F_26 () ) ;
F_36 ( & V_32 -> V_47 ) ;
V_32 -> V_52 ++ ;
F_37 ( & V_32 -> V_47 ) ;
return V_49 ;
}
static int F_40 ( int V_2 , struct V_27 * V_28 ,
const struct V_37 * V_48 )
{
struct V_37 V_53 ;
struct V_33 V_54 ;
struct V_27 * V_55 , * V_56 ;
int V_49 ;
V_55 = F_41 ( V_28 , V_57 | V_58 ) ;
if ( F_17 ( V_28 ) )
return F_42 ( V_28 ) ;
V_28 = V_55 ;
do {
V_49 = F_39 ( V_2 , V_28 , V_48 ) ;
if ( V_49 )
break;
if ( V_28 == V_55 && F_43 ( V_28 ) -> V_59 & V_60 ) {
V_54 = * V_48 -> V_34 ;
V_54 . V_61 . V_62 = V_63 ;
V_53 = * V_48 ;
V_53 . V_34 = & V_54 ;
V_48 = & V_53 ;
}
} while ( ( V_28 = V_28 -> V_64 ) );
V_28 = V_55 ;
do {
V_56 = V_28 -> V_64 ;
if ( V_49 )
F_29 ( V_28 ) ;
else
F_32 ( V_28 ) ;
} while ( ( V_28 = V_56 ) );
return V_49 ;
}
static int F_39 ( int V_2 , struct V_27 * V_28 ,
const struct V_37 * V_48 )
{
struct V_65 * V_38 ;
struct V_27 * V_56 = NULL ;
struct V_27 * V_66 ;
struct V_67 * V_68 ;
unsigned int V_69 ;
int V_49 ;
if ( F_44 ( V_28 ) ) {
V_56 = F_45 ( V_28 , V_70 ) ;
if ( ! V_56 )
return - V_71 ;
V_56 = F_46 ( V_56 , F_47 ( V_56 ) ) ;
if ( ! V_28 )
return - V_71 ;
V_56 -> V_72 = 0 ;
V_28 = V_56 ;
}
if ( F_48 ( V_28 -> V_69 ) > V_73 ) {
V_49 = - V_74 ;
goto V_45;
}
V_69 = sizeof( struct V_65 ) ;
V_69 += F_49 ( V_28 -> V_69 ) ;
V_69 += F_49 ( V_75 ) ;
if ( V_48 -> V_39 == V_76 )
V_69 += F_49 ( 8 ) ;
V_66 = F_50 ( V_69 , V_70 ) ;
if ( ! V_66 ) {
V_49 = - V_71 ;
goto V_45;
}
V_38 = F_51 ( V_66 , 0 , 0 , & V_77 ,
0 , V_48 -> V_39 ) ;
V_38 -> V_2 = V_2 ;
V_68 = F_52 ( V_66 , V_78 ) ;
F_53 ( V_48 -> V_34 , V_66 ) ;
F_54 ( V_66 , V_68 ) ;
if ( V_48 -> V_41 )
F_55 ( V_66 , V_79 ,
F_56 ( V_48 -> V_41 ) ) ;
V_68 = F_57 ( V_66 , V_80 , V_28 -> V_69 ) ;
F_58 ( V_28 , F_59 ( V_68 ) ) ;
V_49 = F_60 ( & V_6 , V_66 , V_48 -> V_42 ) ;
V_45:
F_29 ( V_56 ) ;
return V_49 ;
}
static int F_61 ( int V_2 )
{
struct V_18 * V_81 ;
struct V_18 * V_82 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_81 = F_62 ( V_3 -> V_19 ) ;
V_82 = F_63 ( V_83 ) ;
if ( ! V_82 )
return - V_71 ;
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_81 ) ;
return 0 ;
}
static int F_65 ( const struct V_67 * V_84 ,
const struct V_33 * V_34 , int V_85 )
{
const struct V_67 * V_86 [ V_87 + 1 ] ;
const struct V_67 * V_88 , * V_89 ;
const struct V_67 * V_90 ;
int V_91 ;
memset ( V_86 , 0 , sizeof( V_86 ) ) ;
F_66 (a, attr, rem) {
int type = F_67 ( V_90 ) ;
if ( ! type || type > V_87 || V_86 [ type ] )
return - V_92 ;
V_86 [ type ] = V_90 ;
}
if ( V_91 )
return - V_92 ;
V_88 = V_86 [ V_93 ] ;
if ( ! V_88 || F_68 ( V_88 ) != sizeof( V_94 ) )
return - V_92 ;
V_89 = V_86 [ V_95 ] ;
if ( ! V_89 || ( F_68 ( V_89 ) && F_68 ( V_89 ) < V_96 ) )
return - V_92 ;
return F_69 ( V_89 , V_34 , V_85 + 1 ) ;
}
static int F_70 ( const struct V_67 * V_90 ,
const struct V_33 * V_97 )
{
const struct V_67 * V_98 = F_59 ( V_90 ) ;
int V_99 = F_67 ( V_98 ) ;
if ( F_49 ( F_68 ( V_98 ) ) != F_68 ( V_90 ) )
return - V_92 ;
if ( V_99 > V_100 ||
F_68 ( V_98 ) != V_101 [ V_99 ] )
return - V_92 ;
switch ( V_99 ) {
const struct V_102 * V_103 ;
case V_104 :
case V_105 :
break;
case V_106 :
if ( V_97 -> V_107 . type != F_71 ( V_108 ) )
return - V_92 ;
if ( ! V_97 -> V_109 . V_110 . V_111 || ! V_97 -> V_109 . V_110 . V_112 )
return - V_92 ;
V_103 = F_59 ( V_98 ) ;
if ( V_103 -> V_113 != V_97 -> V_61 . V_114 )
return - V_92 ;
if ( V_103 -> V_115 != V_97 -> V_61 . V_62 )
return - V_92 ;
break;
case V_116 :
if ( V_97 -> V_61 . V_114 != V_117 )
return - V_92 ;
if ( ! V_97 -> V_109 . V_118 . V_111 || ! V_97 -> V_109 . V_118 . V_112 )
return - V_92 ;
break;
case V_119 :
if ( V_97 -> V_61 . V_114 != V_120 )
return - V_92 ;
if ( ! V_97 -> V_109 . V_118 . V_111 || ! V_97 -> V_109 . V_118 . V_112 )
return - V_92 ;
break;
default:
return - V_92 ;
}
return 0 ;
}
static int F_72 ( const struct V_67 * V_84 )
{
static const struct V_121 V_122 [ V_123 + 1 ] = {
[ V_124 ] = { . type = V_125 } ,
[ V_126 ] = { . type = V_127 } ,
} ;
struct V_67 * V_90 [ V_123 + 1 ] ;
int error ;
error = F_73 ( V_90 , V_123 ,
V_84 , V_122 ) ;
if ( error )
return error ;
if ( ! V_90 [ V_124 ] ||
! F_74 ( V_90 [ V_124 ] ) )
return - V_92 ;
return 0 ;
}
static int F_69 ( const struct V_67 * V_84 ,
const struct V_33 * V_34 , int V_85 )
{
const struct V_67 * V_90 ;
int V_91 , V_49 ;
if ( V_85 >= V_128 )
return - V_129 ;
F_66 (a, attr, rem) {
static const V_94 V_130 [ V_131 + 1 ] = {
[ V_132 ] = sizeof( V_94 ) ,
[ V_133 ] = ( V_94 ) - 1 ,
[ V_134 ] = sizeof( struct V_135 ) ,
[ V_136 ] = 0 ,
[ V_137 ] = ( V_94 ) - 1 ,
[ V_138 ] = ( V_94 ) - 1
} ;
const struct V_135 * V_139 ;
int type = F_67 ( V_90 ) ;
if ( type > V_131 ||
( V_130 [ type ] != F_68 ( V_90 ) &&
V_130 [ type ] != ( V_94 ) - 1 ) )
return - V_92 ;
switch ( type ) {
case V_140 :
return - V_92 ;
case V_133 :
V_49 = F_72 ( V_90 ) ;
if ( V_49 )
return V_49 ;
break;
case V_132 :
if ( F_74 ( V_90 ) >= V_141 )
return - V_92 ;
break;
case V_136 :
break;
case V_134 :
V_139 = F_59 ( V_90 ) ;
if ( V_139 -> V_142 != F_71 ( V_143 ) )
return - V_92 ;
if ( ! ( V_139 -> V_72 & F_71 ( V_144 ) ) )
return - V_92 ;
break;
case V_137 :
V_49 = F_70 ( V_90 , V_34 ) ;
if ( V_49 )
return V_49 ;
break;
case V_138 :
V_49 = F_65 ( V_90 , V_34 , V_85 ) ;
if ( V_49 )
return V_49 ;
break;
default:
return - V_92 ;
}
}
if ( V_91 > 0 )
return - V_92 ;
return 0 ;
}
static void F_75 ( struct V_29 * V_30 )
{
V_30 -> V_145 = 0 ;
V_30 -> V_146 = 0 ;
V_30 -> V_147 = 0 ;
V_30 -> V_148 = 0 ;
}
static int F_76 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_152 * V_153 ;
struct V_27 * V_154 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_155 * V_107 ;
int V_69 ;
int V_49 ;
int V_36 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_80 ] || ! V_90 [ V_78 ] ||
! V_90 [ V_156 ] ||
F_68 ( V_90 [ V_80 ] ) < V_157 )
goto V_49;
V_69 = F_68 ( V_90 [ V_80 ] ) ;
V_154 = F_77 ( V_158 + V_69 , V_159 ) ;
V_49 = - V_71 ;
if ( ! V_154 )
goto V_49;
F_78 ( V_154 , V_158 ) ;
memcpy ( F_79 ( V_154 , V_69 ) , F_59 ( V_90 [ V_80 ] ) , V_69 ) ;
F_80 ( V_154 ) ;
V_107 = F_81 ( V_154 ) ;
if ( F_82 ( V_107 -> V_160 ) >= 1536 )
V_154 -> V_161 = V_107 -> V_160 ;
else
V_154 -> V_161 = F_71 ( V_162 ) ;
V_30 = F_83 () ;
V_49 = F_42 ( V_30 ) ;
if ( F_17 ( V_30 ) )
goto V_163;
V_49 = F_27 ( V_154 , - 1 , & V_30 -> V_34 , & V_36 ) ;
if ( V_49 )
goto V_164;
V_49 = F_84 ( & V_30 -> V_34 . V_165 . V_166 ,
& V_30 -> V_34 . V_165 . V_167 ,
V_90 [ V_78 ] ) ;
if ( V_49 )
goto V_164;
V_49 = F_69 ( V_90 [ V_156 ] , & V_30 -> V_34 , 0 ) ;
if ( V_49 )
goto V_164;
V_30 -> V_168 = F_85 ( & V_30 -> V_34 , V_36 ) ;
V_153 = F_86 ( V_90 [ V_156 ] ) ;
V_49 = F_42 ( V_153 ) ;
if ( F_17 ( V_153 ) )
goto V_164;
F_18 ( V_30 -> V_169 , V_153 ) ;
F_33 ( V_154 ) -> V_30 = V_30 ;
V_154 -> V_166 = V_30 -> V_34 . V_165 . V_166 ;
F_2 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_170;
F_87 () ;
V_49 = F_35 ( V_3 , V_154 ) ;
F_88 () ;
F_5 () ;
F_89 ( V_30 ) ;
return V_49 ;
V_170:
F_5 () ;
V_164:
F_89 ( V_30 ) ;
V_163:
F_29 ( V_154 ) ;
V_49:
return V_49 ;
}
static void F_90 ( struct V_1 * V_3 , struct V_171 * V_32 )
{
int V_172 ;
struct V_18 * V_19 = F_62 ( V_3 -> V_19 ) ;
V_32 -> V_173 = F_91 ( V_19 ) ;
V_32 -> V_46 = V_32 -> V_44 = V_32 -> V_52 = 0 ;
F_92 (i) {
const struct V_31 * V_174 ;
struct V_31 V_175 ;
unsigned int V_176 ;
V_174 = F_25 ( V_3 -> V_20 , V_172 ) ;
do {
V_176 = F_93 ( & V_174 -> V_47 ) ;
V_175 = * V_174 ;
} while ( F_94 ( & V_174 -> V_47 , V_176 ) );
V_32 -> V_46 += V_175 . V_46 ;
V_32 -> V_44 += V_175 . V_44 ;
V_32 -> V_52 += V_175 . V_52 ;
}
}
static int F_95 ( struct V_29 * V_30 , struct V_1 * V_3 ,
struct V_27 * V_28 , V_94 V_42 ,
V_94 V_177 , V_94 V_178 , T_2 V_39 )
{
const int V_179 = V_28 -> V_69 ;
const struct V_152 * V_169 ;
struct V_180 V_32 ;
struct V_65 * V_65 ;
struct V_67 * V_68 ;
unsigned long V_145 ;
T_2 V_146 ;
int V_49 ;
V_169 = F_96 ( V_30 -> V_169 ,
F_97 () ) ;
V_65 = F_51 ( V_28 , V_42 , V_177 , & V_181 , V_178 , V_39 ) ;
if ( ! V_65 )
return - V_182 ;
V_65 -> V_2 = F_8 ( V_3 ) ;
V_68 = F_52 ( V_28 , V_183 ) ;
if ( ! V_68 )
goto V_184;
V_49 = F_53 ( & V_30 -> V_34 , V_28 ) ;
if ( V_49 )
goto error;
F_54 ( V_28 , V_68 ) ;
F_98 ( & V_30 -> V_185 ) ;
V_145 = V_30 -> V_145 ;
V_32 . V_186 = V_30 -> V_147 ;
V_32 . V_187 = V_30 -> V_148 ;
V_146 = V_30 -> V_146 ;
F_99 ( & V_30 -> V_185 ) ;
if ( V_145 )
F_100 ( V_28 , V_188 , F_101 ( V_145 ) ) ;
if ( V_32 . V_186 )
F_102 ( V_28 , V_189 ,
sizeof( struct V_180 ) , & V_32 ) ;
if ( V_146 )
F_103 ( V_28 , V_190 , V_146 ) ;
V_49 = F_104 ( V_28 , V_191 , V_169 -> V_192 ,
V_169 -> V_89 ) ;
if ( V_49 < 0 && V_179 )
goto error;
return F_105 ( V_28 , V_65 ) ;
V_184:
V_49 = - V_182 ;
error:
F_106 ( V_28 , V_65 ) ;
return V_49 ;
}
static struct V_27 * F_107 ( struct V_29 * V_30 )
{
const struct V_152 * V_169 ;
int V_69 ;
V_169 = F_96 ( V_30 -> V_169 ,
F_97 () ) ;
V_69 = F_49 ( V_75 ) ;
V_69 += F_49 ( V_169 -> V_192 ) ;
V_69 += F_49 ( sizeof( struct V_180 ) ) ;
V_69 += F_49 ( 1 ) ;
V_69 += F_49 ( 8 ) ;
V_69 += F_108 ( sizeof( struct V_65 ) ) ;
return F_50 ( V_69 , V_159 ) ;
}
static struct V_27 * F_109 ( struct V_29 * V_30 ,
struct V_1 * V_3 ,
V_94 V_42 , V_94 V_177 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_193 ;
V_28 = F_107 ( V_30 ) ;
if ( ! V_28 )
return F_110 ( - V_71 ) ;
V_193 = F_95 ( V_30 , V_3 , V_28 , V_42 , V_177 , 0 , V_39 ) ;
F_111 ( V_193 < 0 ) ;
return V_28 ;
}
static int F_112 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_33 V_34 ;
struct V_29 * V_30 ;
struct V_27 * V_194 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int error ;
int V_36 ;
error = - V_92 ;
if ( ! V_90 [ V_183 ] )
goto error;
error = F_113 ( & V_34 , & V_36 , V_90 [ V_183 ] ) ;
if ( error )
goto error;
if ( V_90 [ V_191 ] ) {
error = F_69 ( V_90 [ V_191 ] , & V_34 , 0 ) ;
if ( error )
goto error;
} else if ( V_150 -> V_195 -> V_39 == V_196 ) {
error = - V_92 ;
goto error;
}
V_3 = F_1 ( V_65 -> V_2 ) ;
error = - V_51 ;
if ( ! V_3 )
goto error;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 ) {
struct V_152 * V_153 ;
error = - V_197 ;
if ( V_150 -> V_195 -> V_39 == V_198 )
goto error;
if ( F_114 ( V_19 ) ) {
struct V_18 * V_82 ;
V_82 = F_115 ( V_19 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_19 ) ;
V_19 = F_62 ( V_3 -> V_19 ) ;
}
}
V_30 = F_83 () ;
if ( F_17 ( V_30 ) ) {
error = F_42 ( V_30 ) ;
goto error;
}
V_30 -> V_34 = V_34 ;
F_75 ( V_30 ) ;
V_153 = F_86 ( V_90 [ V_191 ] ) ;
error = F_42 ( V_153 ) ;
if ( F_17 ( V_153 ) )
goto V_199;
F_18 ( V_30 -> V_169 , V_153 ) ;
V_30 -> V_168 = F_85 ( & V_34 , V_36 ) ;
F_116 ( V_19 , V_30 ) ;
V_194 = F_109 ( V_30 , V_3 , V_150 -> V_200 ,
V_150 -> V_201 ,
V_196 ) ;
} else {
struct V_152 * V_202 ;
struct V_67 * V_203 ;
error = - V_204 ;
if ( V_150 -> V_195 -> V_39 == V_196 &&
V_150 -> V_205 -> V_206 & ( V_207 | V_208 ) )
goto error;
V_202 = F_96 ( V_30 -> V_169 ,
F_97 () ) ;
V_203 = V_90 [ V_191 ] ;
if ( V_203 &&
( V_202 -> V_192 != F_68 ( V_203 ) ||
memcmp ( V_202 -> V_89 , F_59 ( V_203 ) ,
V_202 -> V_192 ) ) ) {
struct V_152 * V_209 ;
V_209 = F_86 ( V_203 ) ;
error = F_42 ( V_209 ) ;
if ( F_17 ( V_209 ) )
goto error;
F_18 ( V_30 -> V_169 , V_209 ) ;
F_117 ( V_202 ) ;
}
V_194 = F_109 ( V_30 , V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_196 ) ;
if ( V_90 [ V_210 ] ) {
F_98 ( & V_30 -> V_185 ) ;
F_75 ( V_30 ) ;
F_99 ( & V_30 -> V_185 ) ;
}
}
if ( ! F_17 ( V_194 ) )
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_211 . V_212 , V_150 -> V_205 ,
V_159 ) ;
else
F_120 ( V_6 . V_213 , 0 ,
V_211 . V_212 , F_42 ( V_194 ) ) ;
return 0 ;
V_199:
F_89 ( V_30 ) ;
error:
return error ;
}
static int F_121 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_33 V_34 ;
struct V_27 * V_194 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_183 ] )
return - V_92 ;
V_49 = F_113 ( & V_34 , & V_36 , V_90 [ V_183 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_197 ;
V_194 = F_109 ( V_30 , V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_196 ) ;
if ( F_17 ( V_194 ) )
return F_42 ( V_194 ) ;
return F_122 ( V_194 , V_150 ) ;
}
static int F_123 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_33 V_34 ;
struct V_27 * V_194 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_183 ] )
return F_61 ( V_65 -> V_2 ) ;
V_49 = F_113 ( & V_34 , & V_36 , V_90 [ V_183 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_197 ;
V_194 = F_107 ( V_30 ) ;
if ( ! V_194 )
return - V_71 ;
F_124 ( V_19 , V_30 ) ;
V_49 = F_95 ( V_30 , V_3 , V_194 , V_150 -> V_200 ,
V_150 -> V_201 , 0 , V_214 ) ;
F_111 ( V_49 < 0 ) ;
F_125 ( V_30 ) ;
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_211 . V_212 , V_150 -> V_205 , V_159 ) ;
return 0 ;
}
static int F_126 ( struct V_27 * V_28 , struct V_215 * V_216 )
{
struct V_65 * V_65 = F_127 ( F_128 ( V_216 -> V_217 ) ) ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
for (; ; ) {
struct V_29 * V_30 ;
V_94 V_218 , V_219 ;
V_218 = V_216 -> args [ 0 ] ;
V_219 = V_216 -> args [ 1 ] ;
V_30 = F_129 ( V_19 , & V_218 , & V_219 ) ;
if ( ! V_30 )
break;
if ( F_95 ( V_30 , V_3 , V_28 ,
F_130 ( V_216 -> V_28 ) . V_42 ,
V_216 -> V_217 -> V_220 , V_221 ,
V_196 ) < 0 )
break;
V_216 -> args [ 0 ] = V_218 ;
V_216 -> args [ 1 ] = V_219 ;
}
return V_28 -> V_69 ;
}
static int F_131 ( struct V_1 * V_3 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_177 , V_94 V_178 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_171 V_222 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_177 , & V_223 ,
V_178 , V_39 ) ;
if ( ! V_65 )
goto error;
V_65 -> V_2 = F_8 ( V_3 ) ;
F_2 () ;
V_49 = F_132 ( V_28 , V_224 , F_6 ( V_3 ) ) ;
F_5 () ;
if ( V_49 )
goto V_184;
F_90 ( V_3 , & V_222 ) ;
F_102 ( V_28 , V_225 , sizeof( struct V_171 ) , & V_222 ) ;
return F_105 ( V_28 , V_65 ) ;
V_184:
F_106 ( V_28 , V_65 ) ;
error:
return - V_182 ;
}
static struct V_27 * F_133 ( struct V_1 * V_3 , V_94 V_42 ,
V_94 V_177 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_193 ;
V_28 = F_134 ( V_226 , V_159 ) ;
if ( ! V_28 )
return F_110 ( - V_71 ) ;
V_193 = F_131 ( V_3 , V_28 , V_42 , V_177 , 0 , V_39 ) ;
if ( V_193 < 0 ) {
F_29 ( V_28 ) ;
return F_110 ( V_193 ) ;
}
return V_28 ;
}
static struct V_1 * F_135 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_227 + 1 ] )
{
struct V_1 * V_3 ;
if ( ! V_90 [ V_224 ] )
V_3 = F_1 ( V_65 -> V_2 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_136 ( F_59 ( V_90 [ V_224 ] ) ) ;
V_3 = V_7 && V_7 -> V_23 == V_9 ? V_7 -> V_3 : NULL ;
F_5 () ;
}
return V_3 ? V_3 : F_110 ( - V_51 ) ;
}
static int F_137 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_21 V_22 ;
struct V_27 * V_194 ;
struct V_1 * V_3 ;
struct V_7 * V_7 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_224 ] || ! V_90 [ V_228 ] )
goto V_49;
F_138 () ;
V_49 = - V_51 ;
if ( ! F_139 ( V_229 ) )
goto V_230;
V_49 = - V_71 ;
V_3 = F_140 ( sizeof( * V_3 ) , V_159 ) ;
if ( V_3 == NULL )
goto V_231;
F_141 ( & V_3 -> V_25 ) ;
V_49 = - V_71 ;
F_18 ( V_3 -> V_19 , F_63 ( V_83 ) ) ;
if ( ! V_3 -> V_19 )
goto V_232;
V_3 -> V_20 = F_142 ( struct V_31 ) ;
if ( ! V_3 -> V_20 ) {
V_49 = - V_71 ;
goto V_233;
}
V_22 . V_234 = F_59 ( V_90 [ V_224 ] ) ;
V_22 . type = V_235 ;
V_22 . V_236 = NULL ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_9 ;
V_22 . V_43 = F_74 ( V_90 [ V_228 ] ) ;
V_7 = F_15 ( & V_22 ) ;
if ( F_17 ( V_7 ) ) {
V_49 = F_42 ( V_7 ) ;
if ( V_49 == - V_237 )
V_49 = - V_204 ;
goto V_238;
}
V_194 = F_133 ( V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_239 ) ;
V_49 = F_42 ( V_194 ) ;
if ( F_17 ( V_194 ) )
goto V_240;
F_143 ( & V_3 -> V_241 , & V_242 ) ;
F_144 () ;
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_243 . V_212 , V_150 -> V_205 ,
V_159 ) ;
return 0 ;
V_240:
F_20 ( F_145 ( V_3 -> V_8 [ V_9 ] ) ) ;
V_238:
F_13 ( V_3 -> V_20 ) ;
V_233:
F_12 ( F_62 ( V_3 -> V_19 ) ) ;
V_232:
F_14 ( V_3 ) ;
V_231:
F_146 ( V_229 ) ;
V_230:
F_144 () ;
V_49:
return V_49 ;
}
static int F_147 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_7 * V_7 , * V_244 ;
struct V_27 * V_194 ;
struct V_1 * V_3 ;
int V_49 ;
F_138 () ;
V_3 = F_135 ( V_150 -> V_151 , V_150 -> V_86 ) ;
V_49 = F_42 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_245;
V_194 = F_133 ( V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_246 ) ;
V_49 = F_42 ( V_194 ) ;
if ( F_17 ( V_194 ) )
goto V_245;
F_148 (vport, next_vport, &dp->port_list, node)
if ( V_7 -> V_23 != V_9 )
F_20 ( V_7 ) ;
F_22 ( & V_3 -> V_241 ) ;
F_20 ( F_145 ( V_3 -> V_8 [ V_9 ] ) ) ;
F_144 () ;
F_149 ( & V_3 -> V_16 , F_10 ) ;
F_146 ( V_229 ) ;
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_243 . V_212 , V_150 -> V_205 ,
V_159 ) ;
return 0 ;
V_245:
F_144 () ;
return V_49 ;
}
static int F_150 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_27 * V_194 ;
struct V_1 * V_3 ;
int V_49 ;
V_3 = F_135 ( V_150 -> V_151 , V_150 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_42 ( V_3 ) ;
V_194 = F_133 ( V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_239 ) ;
if ( F_17 ( V_194 ) ) {
V_49 = F_42 ( V_194 ) ;
F_120 ( V_6 . V_213 , 0 ,
V_243 . V_212 , V_49 ) ;
return 0 ;
}
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_243 . V_212 , V_150 -> V_205 ,
V_159 ) ;
return 0 ;
}
static int F_151 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_27 * V_194 ;
struct V_1 * V_3 ;
V_3 = F_135 ( V_150 -> V_151 , V_150 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_42 ( V_3 ) ;
V_194 = F_133 ( V_3 , V_150 -> V_200 ,
V_150 -> V_201 , V_239 ) ;
if ( F_17 ( V_194 ) )
return F_42 ( V_194 ) ;
return F_122 ( V_194 , V_150 ) ;
}
static int F_152 ( struct V_27 * V_28 , struct V_215 * V_216 )
{
struct V_1 * V_3 ;
int V_247 = V_216 -> args [ 0 ] ;
int V_172 = 0 ;
F_153 (dp, &dps, list_node) {
if ( V_172 >= V_247 &&
F_131 ( V_3 , V_28 , F_130 ( V_216 -> V_28 ) . V_42 ,
V_216 -> V_217 -> V_220 , V_221 ,
V_239 ) < 0 )
break;
V_172 ++ ;
}
V_216 -> args [ 0 ] = V_172 ;
return V_28 -> V_69 ;
}
static int F_154 ( struct V_7 * V_7 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_177 , V_94 V_178 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_248 V_249 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_177 , & V_250 ,
V_178 , V_39 ) ;
if ( ! V_65 )
return - V_182 ;
V_65 -> V_2 = F_8 ( V_7 -> V_3 ) ;
F_155 ( V_28 , V_251 , V_7 -> V_23 ) ;
F_155 ( V_28 , V_252 , V_7 -> V_10 -> type ) ;
F_156 ( V_28 , V_253 , V_7 -> V_10 -> V_11 ( V_7 ) ) ;
F_155 ( V_28 , V_254 , V_7 -> V_43 ) ;
F_157 ( V_7 , & V_249 ) ;
F_102 ( V_28 , V_255 , sizeof( struct V_248 ) ,
& V_249 ) ;
V_49 = F_158 ( V_7 , V_28 ) ;
if ( V_49 == - V_182 )
goto error;
return F_105 ( V_28 , V_65 ) ;
V_184:
V_49 = - V_182 ;
error:
F_106 ( V_28 , V_65 ) ;
return V_49 ;
}
struct V_27 * F_159 ( struct V_7 * V_7 , V_94 V_42 ,
V_94 V_177 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_193 ;
V_28 = F_134 ( V_226 , V_70 ) ;
if ( ! V_28 )
return F_110 ( - V_71 ) ;
V_193 = F_154 ( V_7 , V_28 , V_42 , V_177 , 0 , V_39 ) ;
if ( V_193 < 0 ) {
F_29 ( V_28 ) ;
return F_110 ( V_193 ) ;
}
return V_28 ;
}
static struct V_7 * F_160 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_256 + 1 ] )
{
struct V_1 * V_3 ;
struct V_7 * V_7 ;
if ( V_90 [ V_253 ] ) {
V_7 = F_136 ( F_59 ( V_90 [ V_253 ] ) ) ;
if ( ! V_7 )
return F_110 ( - V_51 ) ;
if ( V_65 -> V_2 &&
V_65 -> V_2 != F_8 ( V_7 -> V_3 ) )
return F_110 ( - V_51 ) ;
return V_7 ;
} else if ( V_90 [ V_251 ] ) {
V_94 V_23 = F_74 ( V_90 [ V_251 ] ) ;
if ( V_23 >= V_141 )
return F_110 ( - V_74 ) ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return F_110 ( - V_51 ) ;
V_7 = F_7 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
return F_110 ( - V_197 ) ;
return V_7 ;
} else
return F_110 ( - V_92 ) ;
}
static int F_161 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_21 V_22 ;
struct V_27 * V_194 ;
struct V_7 * V_7 ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_253 ] || ! V_90 [ V_252 ] ||
! V_90 [ V_254 ] )
goto exit;
F_138 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_245;
if ( V_90 [ V_251 ] ) {
V_23 = F_74 ( V_90 [ V_251 ] ) ;
V_49 = - V_74 ;
if ( V_23 >= V_141 )
goto V_245;
V_7 = F_145 ( V_3 -> V_8 [ V_23 ] ) ;
V_49 = - V_237 ;
if ( V_7 )
goto V_245;
} else {
for ( V_23 = 1 ; ; V_23 ++ ) {
if ( V_23 >= V_141 ) {
V_49 = - V_74 ;
goto V_245;
}
V_7 = F_145 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
break;
}
}
V_22 . V_234 = F_59 ( V_90 [ V_253 ] ) ;
V_22 . type = F_74 ( V_90 [ V_252 ] ) ;
V_22 . V_236 = V_90 [ V_257 ] ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_23 ;
V_22 . V_43 = F_74 ( V_90 [ V_254 ] ) ;
V_7 = F_15 ( & V_22 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_245;
V_194 = F_159 ( V_7 , V_150 -> V_200 , V_150 -> V_201 ,
V_258 ) ;
if ( F_17 ( V_194 ) ) {
V_49 = F_42 ( V_194 ) ;
F_20 ( V_7 ) ;
goto V_245;
}
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_259 . V_212 , V_150 -> V_205 , V_159 ) ;
V_245:
F_144 () ;
exit:
return V_49 ;
}
static int F_162 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_27 * V_194 ;
struct V_7 * V_7 ;
int V_49 ;
F_138 () ;
V_7 = F_160 ( V_150 -> V_151 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_245;
V_49 = 0 ;
if ( V_90 [ V_252 ] &&
F_74 ( V_90 [ V_252 ] ) != V_7 -> V_10 -> type )
V_49 = - V_92 ;
if ( ! V_49 && V_90 [ V_257 ] )
V_49 = F_163 ( V_7 , V_90 [ V_257 ] ) ;
if ( ! V_49 && V_90 [ V_254 ] )
V_7 -> V_43 = F_74 ( V_90 [ V_254 ] ) ;
V_194 = F_159 ( V_7 , V_150 -> V_200 , V_150 -> V_201 ,
V_258 ) ;
if ( F_17 ( V_194 ) ) {
V_49 = F_42 ( V_194 ) ;
F_120 ( V_6 . V_213 , 0 ,
V_259 . V_212 , V_49 ) ;
return 0 ;
}
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_259 . V_212 , V_150 -> V_205 , V_159 ) ;
V_245:
F_144 () ;
return V_49 ;
}
static int F_164 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_27 * V_194 ;
struct V_7 * V_7 ;
int V_49 ;
F_138 () ;
V_7 = F_160 ( V_150 -> V_151 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_245;
if ( V_7 -> V_23 == V_9 ) {
V_49 = - V_92 ;
goto V_245;
}
V_194 = F_159 ( V_7 , V_150 -> V_200 , V_150 -> V_201 ,
V_260 ) ;
V_49 = F_42 ( V_194 ) ;
if ( F_17 ( V_194 ) )
goto V_245;
F_20 ( V_7 ) ;
F_118 ( V_194 , F_119 ( V_150 ) , V_150 -> V_200 ,
V_259 . V_212 , V_150 -> V_205 , V_159 ) ;
V_245:
F_144 () ;
return V_49 ;
}
static int F_165 ( struct V_27 * V_28 , struct V_149 * V_150 )
{
struct V_67 * * V_90 = V_150 -> V_86 ;
struct V_65 * V_65 = V_150 -> V_151 ;
struct V_27 * V_194 ;
struct V_7 * V_7 ;
int V_49 ;
F_2 () ;
V_7 = F_160 ( V_65 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_245;
V_194 = F_159 ( V_7 , V_150 -> V_200 , V_150 -> V_201 ,
V_258 ) ;
V_49 = F_42 ( V_194 ) ;
if ( F_17 ( V_194 ) )
goto V_245;
F_5 () ;
return F_122 ( V_194 , V_150 ) ;
V_245:
F_5 () ;
return V_49 ;
}
static int F_166 ( struct V_27 * V_28 , struct V_215 * V_216 )
{
struct V_65 * V_65 = F_127 ( F_128 ( V_216 -> V_217 ) ) ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_193 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
F_2 () ;
for ( V_23 = V_216 -> args [ 0 ] ; V_23 < V_141 ; V_23 ++ ) {
struct V_7 * V_7 ;
V_7 = F_9 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
continue;
if ( F_154 ( V_7 , V_28 , F_130 ( V_216 -> V_28 ) . V_42 ,
V_216 -> V_217 -> V_220 , V_221 ,
V_258 ) < 0 )
break;
}
F_5 () ;
V_216 -> args [ 0 ] = V_23 ;
V_193 = V_28 -> V_69 ;
return V_193 ;
}
static void F_167 ( struct V_261 * V_262 )
{
struct V_1 * V_3 ;
F_168 () ;
F_153 (dp, &dps, list_node) {
struct V_18 * V_81 = F_62 ( V_3 -> V_19 ) ;
struct V_18 * V_82 ;
V_82 = F_169 ( V_81 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_81 ) ;
}
}
F_170 () ;
F_171 ( & V_263 , V_264 ) ;
}
static void F_172 ( int V_265 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_265 ; V_172 ++ )
F_173 ( V_266 [ V_172 ] . V_267 ) ;
}
static int F_174 ( void )
{
int V_268 ;
int V_49 ;
int V_172 ;
V_268 = 0 ;
for ( V_172 = 0 ; V_172 < F_175 ( V_266 ) ; V_172 ++ ) {
const struct V_269 * V_270 = & V_266 [ V_172 ] ;
V_49 = F_176 ( V_270 -> V_267 , V_270 -> V_10 ,
V_270 -> V_271 ) ;
if ( V_49 )
goto error;
V_268 ++ ;
if ( V_270 -> V_272 ) {
V_49 = F_177 ( V_270 -> V_267 , V_270 -> V_272 ) ;
if ( V_49 )
goto error;
}
}
return 0 ;
error:
F_172 ( V_268 ) ;
return V_49 ;
}
static int T_3 F_178 ( void )
{
struct V_27 * V_273 ;
int V_49 ;
F_179 ( sizeof( struct V_274 ) > sizeof( V_273 -> V_216 ) ) ;
F_180 ( L_1 ) ;
V_49 = F_181 () ;
if ( V_49 )
goto error;
V_49 = F_182 () ;
if ( V_49 )
goto V_275;
V_49 = F_183 ( & V_276 ) ;
if ( V_49 )
goto V_277;
V_49 = F_174 () ;
if ( V_49 < 0 )
goto V_278;
F_171 ( & V_263 , V_264 ) ;
return 0 ;
V_278:
F_184 ( & V_276 ) ;
V_277:
F_185 () ;
V_275:
F_186 () ;
error:
return V_49 ;
}
static void F_187 ( void )
{
F_188 ( & V_263 ) ;
F_189 () ;
F_172 ( F_175 ( V_266 ) ) ;
F_184 ( & V_276 ) ;
F_185 () ;
F_186 () ;
}
