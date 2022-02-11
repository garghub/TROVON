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
if ( ! V_56 )
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
static int F_70 ( const struct V_33 * V_97 )
{
if ( V_97 -> V_98 . type == F_71 ( V_99 ) ) {
if ( V_97 -> V_100 . V_101 . V_102 && V_97 -> V_100 . V_101 . V_103 )
return 0 ;
} else if ( V_97 -> V_98 . type == F_71 ( V_104 ) ) {
if ( V_97 -> V_105 . V_101 . V_102 && V_97 -> V_105 . V_101 . V_103 )
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
if ( ! V_97 -> V_100 . V_115 . V_102 || ! V_97 -> V_100 . V_115 . V_103 )
return - V_92 ;
V_111 = F_59 ( V_106 ) ;
if ( V_111 -> V_116 != V_97 -> V_61 . V_117 )
return - V_92 ;
if ( V_111 -> V_118 != V_97 -> V_61 . V_62 )
return - V_92 ;
break;
case V_119 :
if ( V_97 -> V_61 . V_117 != V_120 )
return - V_92 ;
return F_70 ( V_97 ) ;
case V_121 :
if ( V_97 -> V_61 . V_117 != V_122 )
return - V_92 ;
return F_70 ( V_97 ) ;
default:
return - V_92 ;
}
return 0 ;
}
static int F_73 ( const struct V_67 * V_84 )
{
static const struct V_123 V_124 [ V_125 + 1 ] = {
[ V_126 ] = { . type = V_127 } ,
[ V_128 ] = { . type = V_129 } ,
} ;
struct V_67 * V_90 [ V_125 + 1 ] ;
int error ;
error = F_74 ( V_90 , V_125 ,
V_84 , V_124 ) ;
if ( error )
return error ;
if ( ! V_90 [ V_126 ] ||
! F_75 ( V_90 [ V_126 ] ) )
return - V_92 ;
return 0 ;
}
static int F_69 ( const struct V_67 * V_84 ,
const struct V_33 * V_34 , int V_85 )
{
const struct V_67 * V_90 ;
int V_91 , V_49 ;
if ( V_85 >= V_130 )
return - V_131 ;
F_66 (a, attr, rem) {
static const V_94 V_132 [ V_133 + 1 ] = {
[ V_134 ] = sizeof( V_94 ) ,
[ V_135 ] = ( V_94 ) - 1 ,
[ V_136 ] = sizeof( struct V_137 ) ,
[ V_138 ] = 0 ,
[ V_139 ] = ( V_94 ) - 1 ,
[ V_140 ] = ( V_94 ) - 1
} ;
const struct V_137 * V_141 ;
int type = F_67 ( V_90 ) ;
if ( type > V_133 ||
( V_132 [ type ] != F_68 ( V_90 ) &&
V_132 [ type ] != ( V_94 ) - 1 ) )
return - V_92 ;
switch ( type ) {
case V_142 :
return - V_92 ;
case V_135 :
V_49 = F_73 ( V_90 ) ;
if ( V_49 )
return V_49 ;
break;
case V_134 :
if ( F_75 ( V_90 ) >= V_143 )
return - V_92 ;
break;
case V_138 :
break;
case V_136 :
V_141 = F_59 ( V_90 ) ;
if ( V_141 -> V_144 != F_71 ( V_145 ) )
return - V_92 ;
if ( ! ( V_141 -> V_72 & F_71 ( V_146 ) ) )
return - V_92 ;
break;
case V_139 :
V_49 = F_72 ( V_90 , V_34 ) ;
if ( V_49 )
return V_49 ;
break;
case V_140 :
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
V_30 -> V_147 = 0 ;
V_30 -> V_148 = 0 ;
V_30 -> V_149 = 0 ;
V_30 -> V_150 = 0 ;
}
static int F_77 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_154 * V_155 ;
struct V_27 * V_156 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_157 * V_98 ;
int V_69 ;
int V_49 ;
int V_36 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_80 ] || ! V_90 [ V_78 ] ||
! V_90 [ V_158 ] ||
F_68 ( V_90 [ V_80 ] ) < V_159 )
goto V_49;
V_69 = F_68 ( V_90 [ V_80 ] ) ;
V_156 = F_78 ( V_160 + V_69 , V_161 ) ;
V_49 = - V_71 ;
if ( ! V_156 )
goto V_49;
F_79 ( V_156 , V_160 ) ;
memcpy ( F_80 ( V_156 , V_69 ) , F_59 ( V_90 [ V_80 ] ) , V_69 ) ;
F_81 ( V_156 ) ;
V_98 = F_82 ( V_156 ) ;
if ( F_83 ( V_98 -> V_162 ) >= 1536 )
V_156 -> V_163 = V_98 -> V_162 ;
else
V_156 -> V_163 = F_71 ( V_164 ) ;
V_30 = F_84 () ;
V_49 = F_42 ( V_30 ) ;
if ( F_17 ( V_30 ) )
goto V_165;
V_49 = F_27 ( V_156 , - 1 , & V_30 -> V_34 , & V_36 ) ;
if ( V_49 )
goto V_166;
V_49 = F_85 ( & V_30 -> V_34 . V_167 . V_168 ,
& V_30 -> V_34 . V_167 . V_169 ,
V_90 [ V_78 ] ) ;
if ( V_49 )
goto V_166;
V_49 = F_69 ( V_90 [ V_158 ] , & V_30 -> V_34 , 0 ) ;
if ( V_49 )
goto V_166;
V_30 -> V_170 = F_86 ( & V_30 -> V_34 , V_36 ) ;
V_155 = F_87 ( V_90 [ V_158 ] ) ;
V_49 = F_42 ( V_155 ) ;
if ( F_17 ( V_155 ) )
goto V_166;
F_18 ( V_30 -> V_171 , V_155 ) ;
F_33 ( V_156 ) -> V_30 = V_30 ;
V_156 -> V_168 = V_30 -> V_34 . V_167 . V_168 ;
F_2 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_172;
F_88 () ;
V_49 = F_35 ( V_3 , V_156 ) ;
F_89 () ;
F_5 () ;
F_90 ( V_30 ) ;
return V_49 ;
V_172:
F_5 () ;
V_166:
F_90 ( V_30 ) ;
V_165:
F_29 ( V_156 ) ;
V_49:
return V_49 ;
}
static void F_91 ( struct V_1 * V_3 , struct V_173 * V_32 )
{
int V_174 ;
struct V_18 * V_19 = F_62 ( V_3 -> V_19 ) ;
V_32 -> V_175 = F_92 ( V_19 ) ;
V_32 -> V_46 = V_32 -> V_44 = V_32 -> V_52 = 0 ;
F_93 (i) {
const struct V_31 * V_176 ;
struct V_31 V_177 ;
unsigned int V_178 ;
V_176 = F_25 ( V_3 -> V_20 , V_174 ) ;
do {
V_178 = F_94 ( & V_176 -> V_47 ) ;
V_177 = * V_176 ;
} while ( F_95 ( & V_176 -> V_47 , V_178 ) );
V_32 -> V_46 += V_177 . V_46 ;
V_32 -> V_44 += V_177 . V_44 ;
V_32 -> V_52 += V_177 . V_52 ;
}
}
static int F_96 ( struct V_29 * V_30 , struct V_1 * V_3 ,
struct V_27 * V_28 , V_94 V_42 ,
V_94 V_179 , V_94 V_180 , T_2 V_39 )
{
const int V_181 = V_28 -> V_69 ;
const struct V_154 * V_171 ;
struct V_182 V_32 ;
struct V_65 * V_65 ;
struct V_67 * V_68 ;
unsigned long V_147 ;
T_2 V_148 ;
int V_49 ;
V_171 = F_97 ( V_30 -> V_171 ,
F_98 () ) ;
V_65 = F_51 ( V_28 , V_42 , V_179 , & V_183 , V_180 , V_39 ) ;
if ( ! V_65 )
return - V_184 ;
V_65 -> V_2 = F_8 ( V_3 ) ;
V_68 = F_52 ( V_28 , V_185 ) ;
if ( ! V_68 )
goto V_186;
V_49 = F_53 ( & V_30 -> V_34 , V_28 ) ;
if ( V_49 )
goto error;
F_54 ( V_28 , V_68 ) ;
F_99 ( & V_30 -> V_187 ) ;
V_147 = V_30 -> V_147 ;
V_32 . V_188 = V_30 -> V_149 ;
V_32 . V_189 = V_30 -> V_150 ;
V_148 = V_30 -> V_148 ;
F_100 ( & V_30 -> V_187 ) ;
if ( V_147 )
F_101 ( V_28 , V_190 , F_102 ( V_147 ) ) ;
if ( V_32 . V_188 )
F_103 ( V_28 , V_191 ,
sizeof( struct V_182 ) , & V_32 ) ;
if ( V_148 )
F_104 ( V_28 , V_192 , V_148 ) ;
V_49 = F_105 ( V_28 , V_193 , V_171 -> V_194 ,
V_171 -> V_89 ) ;
if ( V_49 < 0 && V_181 )
goto error;
return F_106 ( V_28 , V_65 ) ;
V_186:
V_49 = - V_184 ;
error:
F_107 ( V_28 , V_65 ) ;
return V_49 ;
}
static struct V_27 * F_108 ( struct V_29 * V_30 )
{
const struct V_154 * V_171 ;
int V_69 ;
V_171 = F_97 ( V_30 -> V_171 ,
F_98 () ) ;
V_69 = F_49 ( V_75 ) ;
V_69 += F_49 ( V_171 -> V_194 ) ;
V_69 += F_49 ( sizeof( struct V_182 ) ) ;
V_69 += F_49 ( 1 ) ;
V_69 += F_49 ( 8 ) ;
V_69 += F_109 ( sizeof( struct V_65 ) ) ;
return F_50 ( V_69 , V_161 ) ;
}
static struct V_27 * F_110 ( struct V_29 * V_30 ,
struct V_1 * V_3 ,
V_94 V_42 , V_94 V_179 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_195 ;
V_28 = F_108 ( V_30 ) ;
if ( ! V_28 )
return F_111 ( - V_71 ) ;
V_195 = F_96 ( V_30 , V_3 , V_28 , V_42 , V_179 , 0 , V_39 ) ;
F_112 ( V_195 < 0 ) ;
return V_28 ;
}
static int F_113 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_33 V_34 ;
struct V_29 * V_30 ;
struct V_27 * V_196 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int error ;
int V_36 ;
error = - V_92 ;
if ( ! V_90 [ V_185 ] )
goto error;
error = F_114 ( & V_34 , & V_36 , V_90 [ V_185 ] ) ;
if ( error )
goto error;
if ( V_90 [ V_193 ] ) {
error = F_69 ( V_90 [ V_193 ] , & V_34 , 0 ) ;
if ( error )
goto error;
} else if ( V_152 -> V_197 -> V_39 == V_198 ) {
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
struct V_154 * V_155 ;
error = - V_199 ;
if ( V_152 -> V_197 -> V_39 == V_200 )
goto error;
if ( F_115 ( V_19 ) ) {
struct V_18 * V_82 ;
V_82 = F_116 ( V_19 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_19 ) ;
V_19 = F_62 ( V_3 -> V_19 ) ;
}
}
V_30 = F_84 () ;
if ( F_17 ( V_30 ) ) {
error = F_42 ( V_30 ) ;
goto error;
}
V_30 -> V_34 = V_34 ;
F_76 ( V_30 ) ;
V_155 = F_87 ( V_90 [ V_193 ] ) ;
error = F_42 ( V_155 ) ;
if ( F_17 ( V_155 ) )
goto V_201;
F_18 ( V_30 -> V_171 , V_155 ) ;
V_30 -> V_170 = F_86 ( & V_34 , V_36 ) ;
F_117 ( V_19 , V_30 ) ;
V_196 = F_110 ( V_30 , V_3 , V_152 -> V_202 ,
V_152 -> V_203 ,
V_198 ) ;
} else {
struct V_154 * V_204 ;
struct V_67 * V_205 ;
error = - V_206 ;
if ( V_152 -> V_197 -> V_39 == V_198 &&
V_152 -> V_207 -> V_208 & ( V_209 | V_210 ) )
goto error;
V_204 = F_97 ( V_30 -> V_171 ,
F_98 () ) ;
V_205 = V_90 [ V_193 ] ;
if ( V_205 &&
( V_204 -> V_194 != F_68 ( V_205 ) ||
memcmp ( V_204 -> V_89 , F_59 ( V_205 ) ,
V_204 -> V_194 ) ) ) {
struct V_154 * V_211 ;
V_211 = F_87 ( V_205 ) ;
error = F_42 ( V_211 ) ;
if ( F_17 ( V_211 ) )
goto error;
F_18 ( V_30 -> V_171 , V_211 ) ;
F_118 ( V_204 ) ;
}
V_196 = F_110 ( V_30 , V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_198 ) ;
if ( V_90 [ V_212 ] ) {
F_99 ( & V_30 -> V_187 ) ;
F_76 ( V_30 ) ;
F_100 ( & V_30 -> V_187 ) ;
}
}
if ( ! F_17 ( V_196 ) )
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_213 . V_214 , V_152 -> V_207 ,
V_161 ) ;
else
F_121 ( V_6 . V_215 , 0 ,
V_213 . V_214 , F_42 ( V_196 ) ) ;
return 0 ;
V_201:
F_90 ( V_30 ) ;
error:
return error ;
}
static int F_122 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_33 V_34 ;
struct V_27 * V_196 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_185 ] )
return - V_92 ;
V_49 = F_114 ( & V_34 , & V_36 , V_90 [ V_185 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_199 ;
V_196 = F_110 ( V_30 , V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_198 ) ;
if ( F_17 ( V_196 ) )
return F_42 ( V_196 ) ;
return F_123 ( V_196 , V_152 ) ;
}
static int F_124 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_33 V_34 ;
struct V_27 * V_196 ;
struct V_29 * V_30 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
int V_49 ;
int V_36 ;
if ( ! V_90 [ V_185 ] )
return F_61 ( V_65 -> V_2 ) ;
V_49 = F_114 ( & V_34 , & V_36 , V_90 [ V_185 ] ) ;
if ( V_49 )
return V_49 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
V_30 = F_30 ( V_19 , & V_34 , V_36 ) ;
if ( ! V_30 )
return - V_199 ;
V_196 = F_108 ( V_30 ) ;
if ( ! V_196 )
return - V_71 ;
F_125 ( V_19 , V_30 ) ;
V_49 = F_96 ( V_30 , V_3 , V_196 , V_152 -> V_202 ,
V_152 -> V_203 , 0 , V_216 ) ;
F_112 ( V_49 < 0 ) ;
F_126 ( V_30 ) ;
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_213 . V_214 , V_152 -> V_207 , V_161 ) ;
return 0 ;
}
static int F_127 ( struct V_27 * V_28 , struct V_217 * V_218 )
{
struct V_65 * V_65 = F_128 ( F_129 ( V_218 -> V_219 ) ) ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
V_19 = F_62 ( V_3 -> V_19 ) ;
for (; ; ) {
struct V_29 * V_30 ;
V_94 V_220 , V_221 ;
V_220 = V_218 -> args [ 0 ] ;
V_221 = V_218 -> args [ 1 ] ;
V_30 = F_130 ( V_19 , & V_220 , & V_221 ) ;
if ( ! V_30 )
break;
if ( F_96 ( V_30 , V_3 , V_28 ,
F_131 ( V_218 -> V_28 ) . V_42 ,
V_218 -> V_219 -> V_222 , V_223 ,
V_198 ) < 0 )
break;
V_218 -> args [ 0 ] = V_220 ;
V_218 -> args [ 1 ] = V_221 ;
}
return V_28 -> V_69 ;
}
static int F_132 ( struct V_1 * V_3 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_179 , V_94 V_180 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_173 V_224 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_179 , & V_225 ,
V_180 , V_39 ) ;
if ( ! V_65 )
goto error;
V_65 -> V_2 = F_8 ( V_3 ) ;
F_2 () ;
V_49 = F_133 ( V_28 , V_226 , F_6 ( V_3 ) ) ;
F_5 () ;
if ( V_49 )
goto V_186;
F_91 ( V_3 , & V_224 ) ;
F_103 ( V_28 , V_227 , sizeof( struct V_173 ) , & V_224 ) ;
return F_106 ( V_28 , V_65 ) ;
V_186:
F_107 ( V_28 , V_65 ) ;
error:
return - V_184 ;
}
static struct V_27 * F_134 ( struct V_1 * V_3 , V_94 V_42 ,
V_94 V_179 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_195 ;
V_28 = F_135 ( V_228 , V_161 ) ;
if ( ! V_28 )
return F_111 ( - V_71 ) ;
V_195 = F_132 ( V_3 , V_28 , V_42 , V_179 , 0 , V_39 ) ;
if ( V_195 < 0 ) {
F_29 ( V_28 ) ;
return F_111 ( V_195 ) ;
}
return V_28 ;
}
static struct V_1 * F_136 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_229 + 1 ] )
{
struct V_1 * V_3 ;
if ( ! V_90 [ V_226 ] )
V_3 = F_1 ( V_65 -> V_2 ) ;
else {
struct V_7 * V_7 ;
F_2 () ;
V_7 = F_137 ( F_59 ( V_90 [ V_226 ] ) ) ;
V_3 = V_7 && V_7 -> V_23 == V_9 ? V_7 -> V_3 : NULL ;
F_5 () ;
}
return V_3 ? V_3 : F_111 ( - V_51 ) ;
}
static int F_138 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_21 V_22 ;
struct V_27 * V_196 ;
struct V_1 * V_3 ;
struct V_7 * V_7 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_226 ] || ! V_90 [ V_230 ] )
goto V_49;
F_139 () ;
V_49 = - V_51 ;
if ( ! F_140 ( V_231 ) )
goto V_232;
V_49 = - V_71 ;
V_3 = F_141 ( sizeof( * V_3 ) , V_161 ) ;
if ( V_3 == NULL )
goto V_233;
F_142 ( & V_3 -> V_25 ) ;
V_49 = - V_71 ;
F_18 ( V_3 -> V_19 , F_63 ( V_83 ) ) ;
if ( ! V_3 -> V_19 )
goto V_234;
V_3 -> V_20 = F_143 ( struct V_31 ) ;
if ( ! V_3 -> V_20 ) {
V_49 = - V_71 ;
goto V_235;
}
V_22 . V_236 = F_59 ( V_90 [ V_226 ] ) ;
V_22 . type = V_237 ;
V_22 . V_238 = NULL ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_9 ;
V_22 . V_43 = F_75 ( V_90 [ V_230 ] ) ;
V_7 = F_15 ( & V_22 ) ;
if ( F_17 ( V_7 ) ) {
V_49 = F_42 ( V_7 ) ;
if ( V_49 == - V_239 )
V_49 = - V_206 ;
goto V_240;
}
V_196 = F_134 ( V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_241 ) ;
V_49 = F_42 ( V_196 ) ;
if ( F_17 ( V_196 ) )
goto V_242;
F_144 ( & V_3 -> V_243 , & V_244 ) ;
F_145 () ;
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_245 . V_214 , V_152 -> V_207 ,
V_161 ) ;
return 0 ;
V_242:
F_20 ( F_146 ( V_3 -> V_8 [ V_9 ] ) ) ;
V_240:
F_13 ( V_3 -> V_20 ) ;
V_235:
F_12 ( F_62 ( V_3 -> V_19 ) ) ;
V_234:
F_14 ( V_3 ) ;
V_233:
F_147 ( V_231 ) ;
V_232:
F_145 () ;
V_49:
return V_49 ;
}
static int F_148 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_7 * V_7 , * V_246 ;
struct V_27 * V_196 ;
struct V_1 * V_3 ;
int V_49 ;
F_139 () ;
V_3 = F_136 ( V_152 -> V_153 , V_152 -> V_86 ) ;
V_49 = F_42 ( V_3 ) ;
if ( F_17 ( V_3 ) )
goto V_247;
V_196 = F_134 ( V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_248 ) ;
V_49 = F_42 ( V_196 ) ;
if ( F_17 ( V_196 ) )
goto V_247;
F_149 (vport, next_vport, &dp->port_list, node)
if ( V_7 -> V_23 != V_9 )
F_20 ( V_7 ) ;
F_22 ( & V_3 -> V_243 ) ;
F_20 ( F_146 ( V_3 -> V_8 [ V_9 ] ) ) ;
F_145 () ;
F_150 ( & V_3 -> V_16 , F_10 ) ;
F_147 ( V_231 ) ;
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_245 . V_214 , V_152 -> V_207 ,
V_161 ) ;
return 0 ;
V_247:
F_145 () ;
return V_49 ;
}
static int F_151 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_27 * V_196 ;
struct V_1 * V_3 ;
int V_49 ;
V_3 = F_136 ( V_152 -> V_153 , V_152 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_42 ( V_3 ) ;
V_196 = F_134 ( V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_241 ) ;
if ( F_17 ( V_196 ) ) {
V_49 = F_42 ( V_196 ) ;
F_121 ( V_6 . V_215 , 0 ,
V_245 . V_214 , V_49 ) ;
return 0 ;
}
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_245 . V_214 , V_152 -> V_207 ,
V_161 ) ;
return 0 ;
}
static int F_152 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_27 * V_196 ;
struct V_1 * V_3 ;
V_3 = F_136 ( V_152 -> V_153 , V_152 -> V_86 ) ;
if ( F_17 ( V_3 ) )
return F_42 ( V_3 ) ;
V_196 = F_134 ( V_3 , V_152 -> V_202 ,
V_152 -> V_203 , V_241 ) ;
if ( F_17 ( V_196 ) )
return F_42 ( V_196 ) ;
return F_123 ( V_196 , V_152 ) ;
}
static int F_153 ( struct V_27 * V_28 , struct V_217 * V_218 )
{
struct V_1 * V_3 ;
int V_249 = V_218 -> args [ 0 ] ;
int V_174 = 0 ;
F_154 (dp, &dps, list_node) {
if ( V_174 >= V_249 &&
F_132 ( V_3 , V_28 , F_131 ( V_218 -> V_28 ) . V_42 ,
V_218 -> V_219 -> V_222 , V_223 ,
V_241 ) < 0 )
break;
V_174 ++ ;
}
V_218 -> args [ 0 ] = V_174 ;
return V_28 -> V_69 ;
}
static int F_155 ( struct V_7 * V_7 , struct V_27 * V_28 ,
V_94 V_42 , V_94 V_179 , V_94 V_180 , T_2 V_39 )
{
struct V_65 * V_65 ;
struct V_250 V_251 ;
int V_49 ;
V_65 = F_51 ( V_28 , V_42 , V_179 , & V_252 ,
V_180 , V_39 ) ;
if ( ! V_65 )
return - V_184 ;
V_65 -> V_2 = F_8 ( V_7 -> V_3 ) ;
F_156 ( V_28 , V_253 , V_7 -> V_23 ) ;
F_156 ( V_28 , V_254 , V_7 -> V_10 -> type ) ;
F_157 ( V_28 , V_255 , V_7 -> V_10 -> V_11 ( V_7 ) ) ;
F_156 ( V_28 , V_256 , V_7 -> V_43 ) ;
F_158 ( V_7 , & V_251 ) ;
F_103 ( V_28 , V_257 , sizeof( struct V_250 ) ,
& V_251 ) ;
V_49 = F_159 ( V_7 , V_28 ) ;
if ( V_49 == - V_184 )
goto error;
return F_106 ( V_28 , V_65 ) ;
V_186:
V_49 = - V_184 ;
error:
F_107 ( V_28 , V_65 ) ;
return V_49 ;
}
struct V_27 * F_160 ( struct V_7 * V_7 , V_94 V_42 ,
V_94 V_179 , T_2 V_39 )
{
struct V_27 * V_28 ;
int V_195 ;
V_28 = F_135 ( V_228 , V_70 ) ;
if ( ! V_28 )
return F_111 ( - V_71 ) ;
V_195 = F_155 ( V_7 , V_28 , V_42 , V_179 , 0 , V_39 ) ;
if ( V_195 < 0 ) {
F_29 ( V_28 ) ;
return F_111 ( V_195 ) ;
}
return V_28 ;
}
static struct V_7 * F_161 ( struct V_65 * V_65 ,
struct V_67 * V_90 [ V_258 + 1 ] )
{
struct V_1 * V_3 ;
struct V_7 * V_7 ;
if ( V_90 [ V_255 ] ) {
V_7 = F_137 ( F_59 ( V_90 [ V_255 ] ) ) ;
if ( ! V_7 )
return F_111 ( - V_51 ) ;
if ( V_65 -> V_2 &&
V_65 -> V_2 != F_8 ( V_7 -> V_3 ) )
return F_111 ( - V_51 ) ;
return V_7 ;
} else if ( V_90 [ V_253 ] ) {
V_94 V_23 = F_75 ( V_90 [ V_253 ] ) ;
if ( V_23 >= V_143 )
return F_111 ( - V_74 ) ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return F_111 ( - V_51 ) ;
V_7 = F_7 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
return F_111 ( - V_199 ) ;
return V_7 ;
} else
return F_111 ( - V_92 ) ;
}
static int F_162 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_21 V_22 ;
struct V_27 * V_196 ;
struct V_7 * V_7 ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_49 ;
V_49 = - V_92 ;
if ( ! V_90 [ V_255 ] || ! V_90 [ V_254 ] ||
! V_90 [ V_256 ] )
goto exit;
F_139 () ;
V_3 = F_1 ( V_65 -> V_2 ) ;
V_49 = - V_51 ;
if ( ! V_3 )
goto V_247;
if ( V_90 [ V_253 ] ) {
V_23 = F_75 ( V_90 [ V_253 ] ) ;
V_49 = - V_74 ;
if ( V_23 >= V_143 )
goto V_247;
V_7 = F_146 ( V_3 -> V_8 [ V_23 ] ) ;
V_49 = - V_239 ;
if ( V_7 )
goto V_247;
} else {
for ( V_23 = 1 ; ; V_23 ++ ) {
if ( V_23 >= V_143 ) {
V_49 = - V_74 ;
goto V_247;
}
V_7 = F_146 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
break;
}
}
V_22 . V_236 = F_59 ( V_90 [ V_255 ] ) ;
V_22 . type = F_75 ( V_90 [ V_254 ] ) ;
V_22 . V_238 = V_90 [ V_259 ] ;
V_22 . V_3 = V_3 ;
V_22 . V_23 = V_23 ;
V_22 . V_43 = F_75 ( V_90 [ V_256 ] ) ;
V_7 = F_15 ( & V_22 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_247;
V_196 = F_160 ( V_7 , V_152 -> V_202 , V_152 -> V_203 ,
V_260 ) ;
if ( F_17 ( V_196 ) ) {
V_49 = F_42 ( V_196 ) ;
F_20 ( V_7 ) ;
goto V_247;
}
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_261 . V_214 , V_152 -> V_207 , V_161 ) ;
V_247:
F_145 () ;
exit:
return V_49 ;
}
static int F_163 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_27 * V_196 ;
struct V_7 * V_7 ;
int V_49 ;
F_139 () ;
V_7 = F_161 ( V_152 -> V_153 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_247;
V_49 = 0 ;
if ( V_90 [ V_254 ] &&
F_75 ( V_90 [ V_254 ] ) != V_7 -> V_10 -> type )
V_49 = - V_92 ;
if ( ! V_49 && V_90 [ V_259 ] )
V_49 = F_164 ( V_7 , V_90 [ V_259 ] ) ;
if ( ! V_49 && V_90 [ V_256 ] )
V_7 -> V_43 = F_75 ( V_90 [ V_256 ] ) ;
V_196 = F_160 ( V_7 , V_152 -> V_202 , V_152 -> V_203 ,
V_260 ) ;
if ( F_17 ( V_196 ) ) {
F_121 ( V_6 . V_215 , 0 ,
V_261 . V_214 , F_42 ( V_196 ) ) ;
goto V_247;
}
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_261 . V_214 , V_152 -> V_207 , V_161 ) ;
V_247:
F_145 () ;
return V_49 ;
}
static int F_165 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_27 * V_196 ;
struct V_7 * V_7 ;
int V_49 ;
F_139 () ;
V_7 = F_161 ( V_152 -> V_153 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_247;
if ( V_7 -> V_23 == V_9 ) {
V_49 = - V_92 ;
goto V_247;
}
V_196 = F_160 ( V_7 , V_152 -> V_202 , V_152 -> V_203 ,
V_262 ) ;
V_49 = F_42 ( V_196 ) ;
if ( F_17 ( V_196 ) )
goto V_247;
F_20 ( V_7 ) ;
F_119 ( V_196 , F_120 ( V_152 ) , V_152 -> V_202 ,
V_261 . V_214 , V_152 -> V_207 , V_161 ) ;
V_247:
F_145 () ;
return V_49 ;
}
static int F_166 ( struct V_27 * V_28 , struct V_151 * V_152 )
{
struct V_67 * * V_90 = V_152 -> V_86 ;
struct V_65 * V_65 = V_152 -> V_153 ;
struct V_27 * V_196 ;
struct V_7 * V_7 ;
int V_49 ;
F_2 () ;
V_7 = F_161 ( V_65 , V_90 ) ;
V_49 = F_42 ( V_7 ) ;
if ( F_17 ( V_7 ) )
goto V_247;
V_196 = F_160 ( V_7 , V_152 -> V_202 , V_152 -> V_203 ,
V_260 ) ;
V_49 = F_42 ( V_196 ) ;
if ( F_17 ( V_196 ) )
goto V_247;
F_5 () ;
return F_123 ( V_196 , V_152 ) ;
V_247:
F_5 () ;
return V_49 ;
}
static int F_167 ( struct V_27 * V_28 , struct V_217 * V_218 )
{
struct V_65 * V_65 = F_128 ( F_129 ( V_218 -> V_219 ) ) ;
struct V_1 * V_3 ;
V_94 V_23 ;
int V_195 ;
V_3 = F_1 ( V_65 -> V_2 ) ;
if ( ! V_3 )
return - V_51 ;
F_2 () ;
for ( V_23 = V_218 -> args [ 0 ] ; V_23 < V_143 ; V_23 ++ ) {
struct V_7 * V_7 ;
V_7 = F_9 ( V_3 -> V_8 [ V_23 ] ) ;
if ( ! V_7 )
continue;
if ( F_155 ( V_7 , V_28 , F_131 ( V_218 -> V_28 ) . V_42 ,
V_218 -> V_219 -> V_222 , V_223 ,
V_260 ) < 0 )
break;
}
F_5 () ;
V_218 -> args [ 0 ] = V_23 ;
V_195 = V_28 -> V_69 ;
return V_195 ;
}
static void F_168 ( struct V_263 * V_264 )
{
struct V_1 * V_3 ;
F_169 () ;
F_154 (dp, &dps, list_node) {
struct V_18 * V_81 = F_62 ( V_3 -> V_19 ) ;
struct V_18 * V_82 ;
V_82 = F_170 ( V_81 ) ;
if ( ! F_17 ( V_82 ) ) {
F_18 ( V_3 -> V_19 , V_82 ) ;
F_64 ( V_81 ) ;
}
}
F_171 () ;
F_172 ( & V_265 , V_266 ) ;
}
static void F_173 ( int V_267 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_267 ; V_174 ++ )
F_174 ( V_268 [ V_174 ] . V_269 ) ;
}
static int F_175 ( void )
{
int V_270 ;
int V_49 ;
int V_174 ;
V_270 = 0 ;
for ( V_174 = 0 ; V_174 < F_176 ( V_268 ) ; V_174 ++ ) {
const struct V_271 * V_272 = & V_268 [ V_174 ] ;
V_49 = F_177 ( V_272 -> V_269 , V_272 -> V_10 ,
V_272 -> V_273 ) ;
if ( V_49 )
goto error;
V_270 ++ ;
if ( V_272 -> V_274 ) {
V_49 = F_178 ( V_272 -> V_269 , V_272 -> V_274 ) ;
if ( V_49 )
goto error;
}
}
return 0 ;
error:
F_173 ( V_270 ) ;
return V_49 ;
}
static int T_3 F_179 ( void )
{
struct V_27 * V_275 ;
int V_49 ;
F_180 ( sizeof( struct V_276 ) > sizeof( V_275 -> V_218 ) ) ;
F_181 ( L_1 ) ;
V_49 = F_182 () ;
if ( V_49 )
goto error;
V_49 = F_183 () ;
if ( V_49 )
goto V_277;
V_49 = F_184 ( & V_278 ) ;
if ( V_49 )
goto V_279;
V_49 = F_175 () ;
if ( V_49 < 0 )
goto V_280;
F_172 ( & V_265 , V_266 ) ;
return 0 ;
V_280:
F_185 ( & V_278 ) ;
V_279:
F_186 () ;
V_277:
F_187 () ;
error:
return V_49 ;
}
static void F_188 ( void )
{
F_189 ( & V_265 ) ;
F_190 () ;
F_173 ( F_176 ( V_268 ) ) ;
F_185 ( & V_278 ) ;
F_186 () ;
F_187 () ;
}
