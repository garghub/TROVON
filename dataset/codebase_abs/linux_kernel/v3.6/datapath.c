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
unsigned short V_53 = F_41 ( V_28 ) -> V_53 ;
struct V_37 V_54 ;
struct V_33 V_55 ;
struct V_27 * V_56 , * V_57 ;
int V_49 ;
V_56 = F_42 ( V_28 , V_58 | V_59 ) ;
if ( F_17 ( V_56 ) )
return F_43 ( V_56 ) ;
V_28 = V_56 ;
do {
V_49 = F_39 ( V_2 , V_28 , V_48 ) ;
if ( V_49 )
break;
if ( V_28 == V_56 && V_53 & V_60 ) {
V_55 = * V_48 -> V_34 ;
V_55 . V_61 . V_62 = V_63 ;
V_54 = * V_48 ;
V_54 . V_34 = & V_55 ;
V_48 = & V_54 ;
}
} while ( ( V_28 = V_28 -> V_64 ) );
V_28 = V_56 ;
do {
V_57 = V_28 -> V_64 ;
if ( V_49 )
F_29 ( V_28 ) ;
else
F_32 ( V_28 ) ;
} while ( ( V_28 = V_57 ) );
return V_49 ;
}
static int F_39 ( int V_2 , struct V_27 * V_28 ,
const struct V_37 * V_48 )
{
struct V_65 * V_38 ;
struct V_27 * V_57 = NULL ;
struct V_27 * V_66 ;
struct V_67 * V_68 ;
unsigned int V_69 ;
int V_49 ;
if ( F_44 ( V_28 ) ) {
V_57 = F_45 ( V_28 , V_70 ) ;
if ( ! V_57 )
return - V_71 ;
V_57 = F_46 ( V_57 , F_47 ( V_57 ) ) ;
if ( ! V_57 )
return - V_71 ;
V_57 -> V_72 = 0 ;
V_28 = V_57 ;
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
F_29 ( V_57 ) ;
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
static int F_70 ( const struct V_33 * V_97 )
{
if ( V_97 -> V_98 . type == F_71 ( V_99 ) ) {
if ( V_97 -> V_100 . V_101 . V_102 || V_97 -> V_100 . V_101 . V_103 )
return 0 ;
} else if ( V_97 -> V_98 . type == F_71 ( V_104 ) ) {
if ( V_97 -> V_105 . V_101 . V_102 || V_97 -> V_105 . V_101 . V_103 )
return 0 ;
}
return - V_92 ;
}
static int F_72 ( const struct V_67 * V_90 ,
const struct V_33 * V_97 )
{
const struct V_67 * V_106 = F_59 ( V_90 ) ;
int V_107 = F_67 ( V_106 ) ;
if ( F_49 ( F_68 ( V_106 ) ) != F_68 ( V_90 ) )
return - V_92 ;
if ( V_107 > V_108 ||
F_68 ( V_106 ) != V_109 [ V_107 ] )
return - V_92 ;
switch ( V_107 ) {
const struct V_110 * V_111 ;
case V_112 :
case V_113 :
break;
case V_114 :
if ( V_97 -> V_98 . type != F_71 ( V_99 ) )
return - V_92 ;
if ( ! V_97 -> V_61 . V_115 )
return - V_92 ;
V_111 = F_59 ( V_106 ) ;
if ( V_111 -> V_116 != V_97 -> V_61 . V_115 )
return - V_92 ;
if ( V_111 -> V_117 != V_97 -> V_61 . V_62 )
return - V_92 ;
break;
case V_118 :
if ( V_97 -> V_61 . V_115 != V_119 )
return - V_92 ;
return F_70 ( V_97 ) ;
case V_120 :
if ( V_97 -> V_61 . V_115 != V_121 )
return - V_92 ;
return F_70 ( V_97 ) ;
default:
return - V_92 ;
}
return 0 ;
}
static int F_73 ( const struct V_67 * V_84 )
{
static const struct V_122 V_123 [ V_124 + 1 ] = {
[ V_125 ] = { . type = V_126 } ,
[ V_127 ] = { . type = V_128 } ,
} ;
struct V_67 * V_90 [ V_124 + 1 ] ;
int error ;
error = F_74 ( V_90 , V_124 ,
V_84 , V_123 ) ;
if ( error )
return error ;
if ( ! V_90 [ V_125 ] ||
! F_75 ( V_90 [ V_125 ] ) )
return - V_92 ;
return 0 ;
}
static int F_69 ( const struct V_67 * V_84 ,
const struct V_33 * V_34 , int V_85 )
{
const struct V_67 * V_90 ;
int V_91 , V_49 ;
if ( V_85 >= V_129 )
return - V_130 ;
F_66 (a, attr, rem) {
static const V_94 V_131 [ V_132 + 1 ] = {
[ V_133 ] = sizeof( V_94 ) ,
[ V_134 ] = ( V_94 ) - 1 ,
[ V_135 ] = sizeof( struct V_136 ) ,
[ V_137 ] = 0 ,
[ V_138 ] = ( V_94 ) - 1 ,
[ V_139 ] = ( V_94 ) - 1
} ;
const struct V_136 * V_140 ;
int type = F_67 ( V_90 ) ;
if ( type > V_132 ||
( V_131 [ type ] != F_68 ( V_90 ) &&
V_131 [ type ] != ( V_94 ) - 1 ) )
return - V_92 ;
switch ( type ) {
case V_141 :
return - V_92 ;
case V_134 :
V_49 = F_73 ( V_90 ) ;
if ( V_49 )
return V_49 ;
break;
case V_133 :
if ( F_75 ( V_90 ) >= V_142 )
return - V_92 ;
break;
case V_137 :
break;
case V_135 :
V_140 = F_59 ( V_90 ) ;
if ( V_140 -> V_143 != F_71 ( V_144 ) )
return - V_92 ;
if ( ! ( V_140 -> V_72 & F_71 ( V_145 ) ) )
return - V_92 ;
break;
case V_138 :
V_49 = F_72 ( V_90 , V_34 ) ;
if ( V_49 )
return V_49 ;
break;
case V_139 :
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
static void F_76 ( struct V_29 * V_30 )
{
V_30 -> V_146 = 0 ;
V_30 -> V_147 = 0 ;
V_30 -> V_148 = 0 ;
V_30 -> V_149 = 0 ;
}
static int F_77 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_153 * V_154 ;
struct V_27 * V_155 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_156 * V_98 ;
int V_69 ;
int V_49 ;
int V_36 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_80 ] || ! V_90 [ V_78 ] ||
! V_90 [ V_157 ] ||
F_68 ( V_90 [ V_80 ] ) < V_158 )
goto V_49;
V_69 = F_68 ( V_90 [ V_80 ] ) ;
V_155 = F_78 ( V_159 + V_69 , V_160 ) ;
V_49 = - V_71 ;
if ( ! V_155 )
goto V_49;
F_79 ( V_155 , V_159 ) ;
memcpy ( F_80 ( V_155 , V_69 ) , F_59 ( V_90 [ V_80 ] ) , V_69 ) ;
F_81 ( V_155 ) ;
V_98 = F_82 ( V_155 ) ;
if ( F_83 ( V_98 -> V_161 ) >= 1536 )
V_155 -> V_162 = V_98 -> V_161 ;
else
V_155 -> V_162 = F_71 ( V_163 ) ;
V_30 = F_84 () ;
V_49 = F_43 ( V_30 ) ;
if ( F_17 ( V_30 ) )
goto V_164;
V_49 = F_27 ( V_155 , - 1 , & V_30 -> V_34 , & V_36 ) ;
if ( V_49 )
goto V_165;
V_49 = F_85 ( & V_30 -> V_34 . V_166 . V_167 ,
& V_30 -> V_34 . V_166 . V_168 ,
V_90 [ V_78 ] ) ;
if ( V_49 )
goto V_165;
V_49 = F_69 ( V_90 [ V_157 ] , & V_30 -> V_34 , 0 ) ;
if ( V_49 )
goto V_165;
V_30 -> V_169 = F_86 ( & V_30 -> V_34 , V_36 ) ;
V_154 = F_87 ( V_90 [ V_157 ] ) ;
V_49 = F_43 ( V_154 ) ;
if ( F_17 ( V_154 ) )
goto V_165;
F_18 ( V_30 -> V_170 , V_154 ) ;
F_33 ( V_155 ) -> V_30 = V_30 ;
V_155 -> V_167 = V_30 -> V_34 . V_166 . V_167 ;
F_2 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_171;
F_88 () ;
V_49 = F_35 ( V_3 , V_155 ) ;
F_89 () ;
F_5 () ;
F_90 ( V_30 ) ;
return V_49 ;
V_171:
F_5 () ;
V_165:
F_90 ( V_30 ) ;
V_164:
F_29 ( V_155 ) ;
V_49:
return V_49 ;
}
static void F_91 ( struct V_1 * V_3 , struct V_172 * V_32 )
{
int V_173 ;
struct V_18 * V_19 = F_62 ( V_3 -> V_19 ) ;
V_32 -> V_174 = F_92 ( V_19 ) ;
V_32 -> V_46 = V_32 -> V_44 = V_32 -> V_52 = 0 ;
F_93 (i) {
const struct V_31 * V_175 ;
struct V_31 V_176 ;
unsigned int V_177 ;
V_175 = F_25 ( V_3 -> V_20 , V_173 ) ;
do {
V_177 = F_94 ( & V_175 -> V_47 ) ;
V_176 = * V_175 ;
} while ( F_95 ( & V_175 -> V_47 , V_177 ) );
V_32 -> V_46 += V_176 . V_46 ;
V_32 -> V_44 += V_176 . V_44 ;
V_32 -> V_52 += V_176 . V_52 ;
}
}
static int F_96 ( struct V_29 * V_30 , struct V_1 * V_3 ,
struct V_27 * V_28 , V_94 V_42 ,
V_94 V_178 , V_94 V_179 , T_2 V_39 )
{
const int V_180 = V_28 -> V_69 ;
const struct V_153 * V_170 ;
struct V_181 V_32 ;
struct V_65 * V_65 ;
struct V_67 * V_68 ;
unsigned long V_146 ;
T_2 V_147 ;
int V_49 ;
V_170 = F_97 ( V_30 -> V_170 ,
F_98 () ) ;
V_65 = F_51 ( V_28 , V_42 , V_178 , & V_182 , V_179 , V_39 ) ;
if ( ! V_65 )
return - V_183 ;
V_65 -> V_2 = F_8 ( V_3 ) ;
V_68 = F_52 ( V_28 , V_184 ) ;
if ( ! V_68 )
goto V_185;
V_49 = F_53 ( & V_30 -> V_34 , V_28 ) ;
if ( V_49 )
goto error;
F_54 ( V_28 , V_68 ) ;
F_99 ( & V_30 -> V_186 ) ;
V_146 = V_30 -> V_146 ;
V_32 . V_187 = V_30 -> V_148 ;
V_32 . V_188 = V_30 -> V_149 ;
V_147 = V_30 -> V_147 ;
F_100 ( & V_30 -> V_186 ) ;
if ( V_146 &&
F_55 ( V_28 , V_189 , F_101 ( V_146 ) ) )
goto V_185;
if ( V_32 . V_187 &&
F_102 ( V_28 , V_190 ,
sizeof( struct V_181 ) , & V_32 ) )
goto V_185;
if ( V_147 &&
F_103 ( V_28 , V_191 , V_147 ) )
goto V_185;
V_49 = F_102 ( V_28 , V_192 , V_170 -> V_193 ,
V_170 -> V_89 ) ;
if ( V_49 < 0 && V_180 )
goto error;
return F_104 ( V_28 , V_65 ) ;
V_185:
V_49 = - V_183 ;
error:
F_105 ( V_28 , V_65 ) ;
return V_49 ;
}
static struct V_27 * F_106 ( struct V_29 * V_30 )
{
const struct V_153 * V_170 ;
int V_69 ;
V_170 = F_97 ( V_30 -> V_170 ,
F_98 () ) ;
V_69 = F_49 ( V_75 ) ;
V_69 += F_49 ( V_170 -> V_193 ) ;
V_69 += F_49 ( sizeof( struct V_181 ) ) ;
V_69 += F_49 ( 1 ) ;
V_69 += F_49 ( 8 ) ;
V_69 += F_107 ( sizeof( struct V_65 ) ) ;
return F_50 ( V_69 , V_160 ) ;
}
static struct V_27 * F_108 ( struct V_29 * V_30 ,
struct V_1 * V_3 ,
V_94 V_42 , V_94 V_178 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_194 ;
V_28 = F_106 ( V_30 ) ;
if ( ! V_28 )
return F_109 ( - V_71 ) ;
V_194 = F_96 ( V_30 , V_3 , V_28 , V_42 , V_178 , 0 , V_39 ) ;
F_110 ( V_194 < 0 ) ;
return V_28 ;
}
static int F_111 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_33 V_34 ;
struct V_29 * V_30 ;
struct V_27 * V_195 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int error ;
int V_36 ;
error = - V_92 ;
if ( ! V_90 [ V_184 ] )
goto error;
error = F_112 ( & V_34 , & V_36 , V_90 [ V_184 ] ) ;
if ( error )
goto error;
if ( V_90 [ V_192 ] ) {
error = F_69 ( V_90 [ V_192 ] , & V_34 , 0 ) ;
if ( error )
goto error;
} else if ( V_151 -> V_196 -> V_39 == V_197 ) {
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
struct V_153 * V_154 ;
error = - V_198 ;
if ( V_151 -> V_196 -> V_39 == V_199 )
goto error;
if ( F_113 ( V_19 ) ) {
struct V_18 * V_82 ;
V_82 = F_114 ( V_19 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_19 ) ;
V_19 = F_62 ( V_3 -> V_19 ) ;
}
}
V_30 = F_84 () ;
if ( F_17 ( V_30 ) ) {
error = F_43 ( V_30 ) ;
goto error;
}
V_30 -> V_34 = V_34 ;
F_76 ( V_30 ) ;
V_154 = F_87 ( V_90 [ V_192 ] ) ;
error = F_43 ( V_154 ) ;
if ( F_17 ( V_154 ) )
goto V_200;
F_18 ( V_30 -> V_170 , V_154 ) ;
V_30 -> V_169 = F_86 ( & V_34 , V_36 ) ;
F_115 ( V_19 , V_30 ) ;
V_195 = F_108 ( V_30 , V_3 , V_151 -> V_201 ,
V_151 -> V_202 ,
V_197 ) ;
} else {
struct V_153 * V_203 ;
struct V_67 * V_204 ;
error = - V_205 ;
if ( V_151 -> V_196 -> V_39 == V_197 &&
V_151 -> V_206 -> V_207 & ( V_208 | V_209 ) )
goto error;
V_203 = F_97 ( V_30 -> V_170 ,
F_98 () ) ;
V_204 = V_90 [ V_192 ] ;
if ( V_204 &&
( V_203 -> V_193 != F_68 ( V_204 ) ||
memcmp ( V_203 -> V_89 , F_59 ( V_204 ) ,
V_203 -> V_193 ) ) ) {
struct V_153 * V_210 ;
V_210 = F_87 ( V_204 ) ;
error = F_43 ( V_210 ) ;
if ( F_17 ( V_210 ) )
goto error;
F_18 ( V_30 -> V_170 , V_210 ) ;
F_116 ( V_203 ) ;
}
V_195 = F_108 ( V_30 , V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_197 ) ;
if ( V_90 [ V_211 ] ) {
F_99 ( & V_30 -> V_186 ) ;
F_76 ( V_30 ) ;
F_100 ( & V_30 -> V_186 ) ;
}
}
if ( ! F_17 ( V_195 ) )
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_212 . V_213 , V_151 -> V_206 ,
V_160 ) ;
else
F_119 ( V_6 . V_214 , 0 ,
V_212 . V_213 , F_43 ( V_195 ) ) ;
return 0 ;
V_200:
F_90 ( V_30 ) ;
error:
return error ;
}
static int F_120 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_33 V_34 ;
struct V_27 * V_195 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_184 ] )
return - V_92 ;
V_49 = F_112 ( & V_34 , & V_36 , V_90 [ V_184 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_198 ;
V_195 = F_108 ( V_30 , V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_197 ) ;
if ( F_17 ( V_195 ) )
return F_43 ( V_195 ) ;
return F_121 ( V_195 , V_151 ) ;
}
static int F_122 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_33 V_34 ;
struct V_27 * V_195 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_184 ] )
return F_61 ( V_65 -> V_2 ) ;
V_49 = F_112 ( & V_34 , & V_36 , V_90 [ V_184 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_198 ;
V_195 = F_106 ( V_30 ) ;
if ( ! V_195 )
return - V_71 ;
F_123 ( V_19 , V_30 ) ;
V_49 = F_96 ( V_30 , V_3 , V_195 , V_151 -> V_201 ,
V_151 -> V_202 , 0 , V_215 ) ;
F_110 ( V_49 < 0 ) ;
F_124 ( V_30 ) ;
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_212 . V_213 , V_151 -> V_206 , V_160 ) ;
return 0 ;
}
static int F_125 ( struct V_27 * V_28 , struct V_216 * V_217 )
{
struct V_65 * V_65 = F_126 ( F_127 ( V_217 -> V_218 ) ) ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
for (; ; ) {
struct V_29 * V_30 ;
V_94 V_219 , V_220 ;
V_219 = V_217 -> args [ 0 ] ;
V_220 = V_217 -> args [ 1 ] ;
V_30 = F_128 ( V_19 , & V_219 , & V_220 ) ;
if ( ! V_30 )
break;
if ( F_96 ( V_30 , V_3 , V_28 ,
F_129 ( V_217 -> V_28 ) . V_42 ,
V_217 -> V_218 -> V_221 , V_222 ,
V_197 ) < 0 )
break;
V_217 -> args [ 0 ] = V_219 ;
V_217 -> args [ 1 ] = V_220 ;
}
return V_28 -> V_69 ;
}
static int F_130 ( struct V_1 * V_3 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_178 , V_94 V_179 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_172 V_223 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_178 , & V_224 ,
V_179 , V_39 ) ;
if ( ! V_65 )
goto error;
V_65 -> V_2 = F_8 ( V_3 ) ;
F_2 () ;
V_49 = F_131 ( V_28 , V_225 , F_6 ( V_3 ) ) ;
F_5 () ;
if ( V_49 )
goto V_185;
F_91 ( V_3 , & V_223 ) ;
if ( F_102 ( V_28 , V_226 , sizeof( struct V_172 ) , & V_223 ) )
goto V_185;
return F_104 ( V_28 , V_65 ) ;
V_185:
F_105 ( V_28 , V_65 ) ;
error:
return - V_183 ;
}
static struct V_27 * F_132 ( struct V_1 * V_3 , V_94 V_42 ,
V_94 V_178 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_194 ;
V_28 = F_133 ( V_227 , V_160 ) ;
if ( ! V_28 )
return F_109 ( - V_71 ) ;
V_194 = F_130 ( V_3 , V_28 , V_42 , V_178 , 0 , V_39 ) ;
if ( V_194 < 0 ) {
F_29 ( V_28 ) ;
return F_109 ( V_194 ) ;
}
return V_28 ;
}
static struct V_1 * F_134 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_228 + 1 ] )
{
struct V_1 * V_3 ;
if ( ! V_90 [ V_225 ] )
V_3 = F_1 ( V_65 -> V_2 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_135 ( F_59 ( V_90 [ V_225 ] ) ) ;
V_3 = V_7 && V_7 -> V_23 == V_9 ? V_7 -> V_3 : NULL ;
F_5 () ;
}
return V_3 ? V_3 : F_109 ( - V_51 ) ;
}
static int F_136 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_21 V_22 ;
struct V_27 * V_195 ;
struct V_1 * V_3 ;
struct V_7 * V_7 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_225 ] || ! V_90 [ V_229 ] )
goto V_49;
F_137 () ;
V_49 = - V_51 ;
if ( ! F_138 ( V_230 ) )
goto V_231;
V_49 = - V_71 ;
V_3 = F_139 ( sizeof( * V_3 ) , V_160 ) ;
if ( V_3 == NULL )
goto V_232;
F_140 ( & V_3 -> V_25 ) ;
V_49 = - V_71 ;
F_18 ( V_3 -> V_19 , F_63 ( V_83 ) ) ;
if ( ! V_3 -> V_19 )
goto V_233;
V_3 -> V_20 = F_141 ( struct V_31 ) ;
if ( ! V_3 -> V_20 ) {
V_49 = - V_71 ;
goto V_234;
}
V_22 . V_235 = F_59 ( V_90 [ V_225 ] ) ;
V_22 . type = V_236 ;
V_22 . V_237 = NULL ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_9 ;
V_22 . V_43 = F_75 ( V_90 [ V_229 ] ) ;
V_7 = F_15 ( & V_22 ) ;
if ( F_17 ( V_7 ) ) {
V_49 = F_43 ( V_7 ) ;
if ( V_49 == - V_238 )
V_49 = - V_205 ;
goto V_239;
}
V_195 = F_132 ( V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_240 ) ;
V_49 = F_43 ( V_195 ) ;
if ( F_17 ( V_195 ) )
goto V_241;
F_142 ( & V_3 -> V_242 , & V_243 ) ;
F_143 () ;
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_244 . V_213 , V_151 -> V_206 ,
V_160 ) ;
return 0 ;
V_241:
F_20 ( F_144 ( V_3 -> V_8 [ V_9 ] ) ) ;
V_239:
F_13 ( V_3 -> V_20 ) ;
V_234:
F_12 ( F_62 ( V_3 -> V_19 ) ) ;
V_233:
F_14 ( V_3 ) ;
V_232:
F_145 ( V_230 ) ;
V_231:
F_143 () ;
V_49:
return V_49 ;
}
static int F_146 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_7 * V_7 , * V_245 ;
struct V_27 * V_195 ;
struct V_1 * V_3 ;
int V_49 ;
F_137 () ;
V_3 = F_134 ( V_151 -> V_152 , V_151 -> V_86 ) ;
V_49 = F_43 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_246;
V_195 = F_132 ( V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_247 ) ;
V_49 = F_43 ( V_195 ) ;
if ( F_17 ( V_195 ) )
goto V_246;
F_147 (vport, next_vport, &dp->port_list, node)
if ( V_7 -> V_23 != V_9 )
F_20 ( V_7 ) ;
F_22 ( & V_3 -> V_242 ) ;
F_20 ( F_144 ( V_3 -> V_8 [ V_9 ] ) ) ;
F_143 () ;
F_148 ( & V_3 -> V_16 , F_10 ) ;
F_145 ( V_230 ) ;
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_244 . V_213 , V_151 -> V_206 ,
V_160 ) ;
return 0 ;
V_246:
F_143 () ;
return V_49 ;
}
static int F_149 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_27 * V_195 ;
struct V_1 * V_3 ;
int V_49 ;
V_3 = F_134 ( V_151 -> V_152 , V_151 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_43 ( V_3 ) ;
V_195 = F_132 ( V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_240 ) ;
if ( F_17 ( V_195 ) ) {
V_49 = F_43 ( V_195 ) ;
F_119 ( V_6 . V_214 , 0 ,
V_244 . V_213 , V_49 ) ;
return 0 ;
}
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_244 . V_213 , V_151 -> V_206 ,
V_160 ) ;
return 0 ;
}
static int F_150 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_27 * V_195 ;
struct V_1 * V_3 ;
V_3 = F_134 ( V_151 -> V_152 , V_151 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_43 ( V_3 ) ;
V_195 = F_132 ( V_3 , V_151 -> V_201 ,
V_151 -> V_202 , V_240 ) ;
if ( F_17 ( V_195 ) )
return F_43 ( V_195 ) ;
return F_121 ( V_195 , V_151 ) ;
}
static int F_151 ( struct V_27 * V_28 , struct V_216 * V_217 )
{
struct V_1 * V_3 ;
int V_248 = V_217 -> args [ 0 ] ;
int V_173 = 0 ;
F_152 (dp, &dps, list_node) {
if ( V_173 >= V_248 &&
F_130 ( V_3 , V_28 , F_129 ( V_217 -> V_28 ) . V_42 ,
V_217 -> V_218 -> V_221 , V_222 ,
V_240 ) < 0 )
break;
V_173 ++ ;
}
V_217 -> args [ 0 ] = V_173 ;
return V_28 -> V_69 ;
}
static int F_153 ( struct V_7 * V_7 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_178 , V_94 V_179 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_249 V_250 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_178 , & V_251 ,
V_179 , V_39 ) ;
if ( ! V_65 )
return - V_183 ;
V_65 -> V_2 = F_8 ( V_7 -> V_3 ) ;
if ( F_154 ( V_28 , V_252 , V_7 -> V_23 ) ||
F_154 ( V_28 , V_253 , V_7 -> V_10 -> type ) ||
F_131 ( V_28 , V_254 , V_7 -> V_10 -> V_11 ( V_7 ) ) ||
F_154 ( V_28 , V_255 , V_7 -> V_43 ) )
goto V_185;
F_155 ( V_7 , & V_250 ) ;
if ( F_102 ( V_28 , V_256 , sizeof( struct V_249 ) ,
& V_250 ) )
goto V_185;
V_49 = F_156 ( V_7 , V_28 ) ;
if ( V_49 == - V_183 )
goto error;
return F_104 ( V_28 , V_65 ) ;
V_185:
V_49 = - V_183 ;
error:
F_105 ( V_28 , V_65 ) ;
return V_49 ;
}
struct V_27 * F_157 ( struct V_7 * V_7 , V_94 V_42 ,
V_94 V_178 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_194 ;
V_28 = F_133 ( V_227 , V_70 ) ;
if ( ! V_28 )
return F_109 ( - V_71 ) ;
V_194 = F_153 ( V_7 , V_28 , V_42 , V_178 , 0 , V_39 ) ;
if ( V_194 < 0 ) {
F_29 ( V_28 ) ;
return F_109 ( V_194 ) ;
}
return V_28 ;
}
static struct V_7 * F_158 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_257 + 1 ] )
{
struct V_1 * V_3 ;
struct V_7 * V_7 ;
if ( V_90 [ V_254 ] ) {
V_7 = F_135 ( F_59 ( V_90 [ V_254 ] ) ) ;
if ( ! V_7 )
return F_109 ( - V_51 ) ;
if ( V_65 -> V_2 &&
V_65 -> V_2 != F_8 ( V_7 -> V_3 ) )
return F_109 ( - V_51 ) ;
return V_7 ;
} else if ( V_90 [ V_252 ] ) {
V_94 V_23 = F_75 ( V_90 [ V_252 ] ) ;
if ( V_23 >= V_142 )
return F_109 ( - V_74 ) ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return F_109 ( - V_51 ) ;
V_7 = F_7 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
return F_109 ( - V_198 ) ;
return V_7 ;
} else
return F_109 ( - V_92 ) ;
}
static int F_159 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_21 V_22 ;
struct V_27 * V_195 ;
struct V_7 * V_7 ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_254 ] || ! V_90 [ V_253 ] ||
! V_90 [ V_255 ] )
goto exit;
F_137 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_246;
if ( V_90 [ V_252 ] ) {
V_23 = F_75 ( V_90 [ V_252 ] ) ;
V_49 = - V_74 ;
if ( V_23 >= V_142 )
goto V_246;
V_7 = F_144 ( V_3 -> V_8 [ V_23 ] ) ;
V_49 = - V_238 ;
if ( V_7 )
goto V_246;
} else {
for ( V_23 = 1 ; ; V_23 ++ ) {
if ( V_23 >= V_142 ) {
V_49 = - V_74 ;
goto V_246;
}
V_7 = F_144 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
break;
}
}
V_22 . V_235 = F_59 ( V_90 [ V_254 ] ) ;
V_22 . type = F_75 ( V_90 [ V_253 ] ) ;
V_22 . V_237 = V_90 [ V_258 ] ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_23 ;
V_22 . V_43 = F_75 ( V_90 [ V_255 ] ) ;
V_7 = F_15 ( & V_22 ) ;
V_49 = F_43 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_246;
V_195 = F_157 ( V_7 , V_151 -> V_201 , V_151 -> V_202 ,
V_259 ) ;
if ( F_17 ( V_195 ) ) {
V_49 = F_43 ( V_195 ) ;
F_20 ( V_7 ) ;
goto V_246;
}
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_260 . V_213 , V_151 -> V_206 , V_160 ) ;
V_246:
F_143 () ;
exit:
return V_49 ;
}
static int F_160 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_27 * V_195 ;
struct V_7 * V_7 ;
int V_49 ;
F_137 () ;
V_7 = F_158 ( V_151 -> V_152 , V_90 ) ;
V_49 = F_43 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_246;
V_49 = 0 ;
if ( V_90 [ V_253 ] &&
F_75 ( V_90 [ V_253 ] ) != V_7 -> V_10 -> type )
V_49 = - V_92 ;
if ( ! V_49 && V_90 [ V_258 ] )
V_49 = F_161 ( V_7 , V_90 [ V_258 ] ) ;
if ( V_49 )
goto V_246;
if ( V_90 [ V_255 ] )
V_7 -> V_43 = F_75 ( V_90 [ V_255 ] ) ;
V_195 = F_157 ( V_7 , V_151 -> V_201 , V_151 -> V_202 ,
V_259 ) ;
if ( F_17 ( V_195 ) ) {
F_119 ( V_6 . V_214 , 0 ,
V_260 . V_213 , F_43 ( V_195 ) ) ;
goto V_246;
}
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_260 . V_213 , V_151 -> V_206 , V_160 ) ;
V_246:
F_143 () ;
return V_49 ;
}
static int F_162 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_27 * V_195 ;
struct V_7 * V_7 ;
int V_49 ;
F_137 () ;
V_7 = F_158 ( V_151 -> V_152 , V_90 ) ;
V_49 = F_43 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_246;
if ( V_7 -> V_23 == V_9 ) {
V_49 = - V_92 ;
goto V_246;
}
V_195 = F_157 ( V_7 , V_151 -> V_201 , V_151 -> V_202 ,
V_261 ) ;
V_49 = F_43 ( V_195 ) ;
if ( F_17 ( V_195 ) )
goto V_246;
F_20 ( V_7 ) ;
F_117 ( V_195 , F_118 ( V_151 ) , V_151 -> V_201 ,
V_260 . V_213 , V_151 -> V_206 , V_160 ) ;
V_246:
F_143 () ;
return V_49 ;
}
static int F_163 ( struct V_27 * V_28 , struct V_150 * V_151 )
{
struct V_67 * * V_90 = V_151 -> V_86 ;
struct V_65 * V_65 = V_151 -> V_152 ;
struct V_27 * V_195 ;
struct V_7 * V_7 ;
int V_49 ;
F_2 () ;
V_7 = F_158 ( V_65 , V_90 ) ;
V_49 = F_43 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_246;
V_195 = F_157 ( V_7 , V_151 -> V_201 , V_151 -> V_202 ,
V_259 ) ;
V_49 = F_43 ( V_195 ) ;
if ( F_17 ( V_195 ) )
goto V_246;
F_5 () ;
return F_121 ( V_195 , V_151 ) ;
V_246:
F_5 () ;
return V_49 ;
}
static int F_164 ( struct V_27 * V_28 , struct V_216 * V_217 )
{
struct V_65 * V_65 = F_126 ( F_127 ( V_217 -> V_218 ) ) ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_194 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
F_2 () ;
for ( V_23 = V_217 -> args [ 0 ] ; V_23 < V_142 ; V_23 ++ ) {
struct V_7 * V_7 ;
V_7 = F_9 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
continue;
if ( F_153 ( V_7 , V_28 , F_129 ( V_217 -> V_28 ) . V_42 ,
V_217 -> V_218 -> V_221 , V_222 ,
V_259 ) < 0 )
break;
}
F_5 () ;
V_217 -> args [ 0 ] = V_23 ;
V_194 = V_28 -> V_69 ;
return V_194 ;
}
static void F_165 ( struct V_262 * V_263 )
{
struct V_1 * V_3 ;
F_166 () ;
F_152 (dp, &dps, list_node) {
struct V_18 * V_81 = F_62 ( V_3 -> V_19 ) ;
struct V_18 * V_82 ;
V_82 = F_167 ( V_81 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_81 ) ;
}
}
F_168 () ;
F_169 ( & V_264 , V_265 ) ;
}
static void F_170 ( int V_266 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_266 ; V_173 ++ )
F_171 ( V_267 [ V_173 ] . V_268 ) ;
}
static int F_172 ( void )
{
int V_269 ;
int V_49 ;
int V_173 ;
V_269 = 0 ;
for ( V_173 = 0 ; V_173 < F_173 ( V_267 ) ; V_173 ++ ) {
const struct V_270 * V_271 = & V_267 [ V_173 ] ;
V_49 = F_174 ( V_271 -> V_268 , V_271 -> V_10 ,
V_271 -> V_272 ) ;
if ( V_49 )
goto error;
V_269 ++ ;
if ( V_271 -> V_273 ) {
V_49 = F_175 ( V_271 -> V_268 , V_271 -> V_273 ) ;
if ( V_49 )
goto error;
}
}
return 0 ;
error:
F_170 ( V_269 ) ;
return V_49 ;
}
static int T_3 F_176 ( void )
{
struct V_27 * V_274 ;
int V_49 ;
F_177 ( sizeof( struct V_275 ) > sizeof( V_274 -> V_217 ) ) ;
F_178 ( L_1 ) ;
V_49 = F_179 () ;
if ( V_49 )
goto error;
V_49 = F_180 () ;
if ( V_49 )
goto V_276;
V_49 = F_181 ( & V_277 ) ;
if ( V_49 )
goto V_278;
V_49 = F_172 () ;
if ( V_49 < 0 )
goto V_279;
F_169 ( & V_264 , V_265 ) ;
return 0 ;
V_279:
F_182 ( & V_277 ) ;
V_278:
F_183 () ;
V_276:
F_184 () ;
error:
return V_49 ;
}
static void F_185 ( void )
{
F_186 ( & V_264 ) ;
F_187 () ;
F_170 ( F_173 ( V_267 ) ) ;
F_182 ( & V_277 ) ;
F_183 () ;
F_184 () ;
}
