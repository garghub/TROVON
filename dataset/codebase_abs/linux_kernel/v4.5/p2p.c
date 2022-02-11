static bool F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
if ( V_1 == NULL )
return false ;
V_4 = (struct V_3 * ) V_1 ;
if ( V_2 < sizeof( struct V_3 ) - 1 )
return false ;
if ( V_4 -> V_5 == V_6 &&
V_4 -> V_7 == V_8 &&
V_4 -> V_9 == V_10 &&
memcmp ( V_4 -> V_11 , V_12 , V_13 ) == 0 )
return true ;
return false ;
}
static bool F_2 ( void * V_1 , T_1 V_2 )
{
struct V_14 * V_15 ;
if ( V_1 == NULL )
return false ;
V_15 = (struct V_14 * ) V_1 ;
if ( V_2 < sizeof( struct V_14 ) - 1 )
return false ;
if ( V_15 -> V_5 == V_16 &&
V_15 -> type == V_10 &&
memcmp ( V_15 -> V_11 , V_12 , V_13 ) == 0 )
return true ;
return false ;
}
static bool F_3 ( void * V_1 , T_1 V_2 )
{
struct V_17 * V_18 ;
if ( V_1 == NULL )
return false ;
V_18 = (struct V_17 * ) V_1 ;
if ( V_2 < sizeof( struct V_17 ) - 1 )
return false ;
if ( V_18 -> V_5 != V_19 )
return false ;
if ( V_18 -> V_7 == V_20 ||
V_18 -> V_7 == V_21 ||
V_18 -> V_7 == V_22 ||
V_18 -> V_7 == V_23 )
return true ;
return false ;
}
static void F_4 ( bool V_24 , void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_17 * V_18 ;
if ( ! V_1 || V_2 <= 2 )
return;
if ( F_1 ( V_1 , V_2 ) ) {
V_4 = (struct V_3 * ) V_1 ;
switch ( V_4 -> V_25 ) {
case V_26 :
F_5 ( V_27 , L_1 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_28 :
F_5 ( V_27 , L_4 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_29 :
F_5 ( V_27 , L_5 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_30 :
F_5 ( V_27 , L_6 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_31 :
F_5 ( V_27 , L_7 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_32 :
F_5 ( V_27 , L_8 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_33 :
F_5 ( V_27 , L_9 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_34 :
F_5 ( V_27 , L_10 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_35 :
F_5 ( V_27 , L_11 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
default:
F_5 ( V_27 , L_12 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
}
} else if ( F_2 ( V_1 , V_2 ) ) {
V_15 = (struct V_14 * ) V_1 ;
switch ( V_15 -> V_25 ) {
case V_36 :
F_5 ( V_27 , L_13 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_37 :
F_5 ( V_27 , L_14 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_38 :
F_5 ( V_27 , L_15 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_39 :
F_5 ( V_27 , L_16 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
default:
F_5 ( V_27 , L_17 ,
( V_24 ) ? L_2 : L_3 ) ;
}
} else if ( F_3 ( V_1 , V_2 ) ) {
V_18 = (struct V_17 * ) V_1 ;
switch ( V_18 -> V_7 ) {
case V_20 :
F_5 ( V_27 , L_18 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_21 :
F_5 ( V_27 , L_19 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_22 :
F_5 ( V_27 , L_20 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
case V_23 :
F_5 ( V_27 , L_21 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
default:
F_5 ( V_27 , L_22 ,
( V_24 ) ? L_2 : L_3 ) ;
break;
}
}
}
static void F_4 ( bool V_24 , void * V_1 , T_1 V_2 )
{
}
static int F_6 ( struct V_40 * V_41 , T_2 * V_42 )
{
T_3 V_43 = 0 ;
F_7 ( V_41 , V_44 , 1 ) ;
F_8 ( V_41 , L_23 , 1 ) ;
F_7 ( V_41 , V_45 , 1 ) ;
F_8 ( V_41 , L_24 , 0 ) ;
V_43 = F_9 ( V_41 , L_25 , V_42 ,
V_46 ) ;
if ( V_43 )
F_10 ( L_26 , V_43 ) ;
return V_43 ;
}
static void F_11 ( struct V_47 * V_48 , T_2 * V_49 )
{
struct V_40 * V_50 = V_48 -> V_51 [ V_52 ] . V_53 -> V_41 ;
bool V_54 = false ;
if ( ! V_49 || F_12 ( V_49 ) ) {
V_49 = V_50 -> V_55 ;
V_54 = true ;
}
memcpy ( V_48 -> V_49 , V_49 , V_46 ) ;
if ( V_54 )
V_48 -> V_49 [ 0 ] |= 0x02 ;
memcpy ( V_48 -> V_56 , V_48 -> V_49 , V_46 ) ;
V_48 -> V_56 [ 0 ] |= 0x02 ;
V_48 -> V_56 [ 4 ] ^= 0x80 ;
}
static bool F_13 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_60 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_58 -> V_62 ; V_61 ++ ) {
if ( V_60 [ V_61 ] . V_63 != V_64 )
continue;
F_5 ( V_65 , L_27 , V_60 [ V_61 ] . V_66 ) ;
if ( ! memcmp ( V_67 , V_60 [ V_61 ] . V_66 ,
V_64 ) )
return true ;
}
return false ;
}
static T_3 F_14 ( struct V_40 * V_41 , T_2 V_68 ,
T_4 V_69 , T_4 V_70 )
{
struct V_71 V_72 ;
T_3 V_43 = 0 ;
F_5 ( V_27 , L_28 ) ;
V_72 . V_68 = V_68 ;
V_72 . V_73 = F_15 ( V_69 ) ;
V_72 . V_74 = F_15 ( V_70 ) ;
V_43 = F_16 ( V_41 , L_29 , & V_72 ,
sizeof( V_72 ) ) ;
return V_43 ;
}
static T_3 F_17 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
F_5 ( V_27 , L_28 ) ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
( void ) F_14 ( V_53 -> V_41 , V_77 , 0 , 0 ) ;
V_53 = V_48 -> V_51 [ V_52 ] . V_53 ;
( void ) F_8 ( V_53 -> V_41 , L_24 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
T_3 V_43 = 0 ;
F_5 ( V_27 , L_28 ) ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_30 ) ;
V_43 = - V_78 ;
goto exit;
}
if ( F_19 ( V_79 , & V_48 -> V_80 ) ) {
F_5 ( V_65 , L_31 ) ;
goto exit;
}
V_53 = V_48 -> V_51 [ V_52 ] . V_53 ;
V_43 = F_8 ( V_53 -> V_41 , L_24 , 1 ) ;
if ( V_43 < 0 ) {
F_10 ( L_32 ) ;
goto exit;
}
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
V_43 = F_14 ( V_53 -> V_41 , V_77 , 0 , 0 ) ;
if ( V_43 < 0 ) {
F_10 ( L_33 ) ;
goto exit;
}
V_43 = F_20 ( V_53 -> V_41 , L_34 , V_81 ) ;
if ( V_43 < 0 ) {
F_10 ( L_35 , V_43 ) ;
goto exit;
}
F_21 ( V_79 , & V_48 -> V_80 ) ;
exit:
return V_43 ;
}
static T_3 F_22 ( struct V_47 * V_48 , T_1 V_82 ,
T_4 V_83 [] , T_3 V_84 ,
enum V_85 V_86 )
{
T_3 V_43 = 0 ;
T_3 V_87 = F_23 ( struct V_88 ,
V_89 . V_90 . V_91 ) ;
T_3 V_92 ;
T_3 V_93 ;
T_1 V_61 ;
T_2 * V_94 ;
struct V_75 * V_53 ;
struct V_88 * V_95 ;
struct V_96 * V_97 ;
V_87 += V_82 * sizeof( V_98 ) ;
V_94 = F_24 ( V_87 , V_99 ) ;
if ( ! V_94 )
return - V_100 ;
V_53 = V_48 -> V_51 [ V_86 ] . V_53 ;
if ( V_53 == NULL ) {
F_10 ( L_36 , V_86 ) ;
V_43 = - V_101 ;
goto exit;
}
V_95 = (struct V_88 * ) V_94 ;
V_97 = & V_95 -> V_89 . V_90 ;
switch ( V_84 ) {
case V_102 :
break;
case V_77 :
V_97 -> V_103 . V_104 =
F_25 ( V_64 ) ;
memcpy ( V_97 -> V_103 . V_105 , V_67 ,
V_64 ) ;
break;
default:
F_10 ( L_37 , V_84 ) ;
V_43 = - V_101 ;
goto exit;
}
F_14 ( V_53 -> V_41 , V_84 , 0 , 0 ) ;
V_95 -> type = 'E' ;
V_97 -> V_86 = V_106 ;
if ( V_48 -> V_107 -> V_108 )
V_97 -> V_109 = 0 ;
else
V_97 -> V_109 = 1 ;
F_26 ( V_97 -> V_110 ) ;
V_97 -> V_111 = F_25 ( V_112 ) ;
if ( V_82 == V_113 || V_82 == ( V_113 + 1 ) )
V_93 = V_114 ;
else if ( V_82 == V_115 )
V_93 = V_116 ;
else if ( F_27 ( V_48 -> V_107 , V_117 ) )
V_93 = - 1 ;
else
V_93 = V_118 ;
if ( V_82 == 1 ) {
V_93 = V_119 ;
V_92 = V_93 / V_120 ;
} else {
V_92 = V_93 / V_121 ;
}
if ( V_92 <= 0 )
V_92 = 1 ;
F_5 ( V_65 , L_38 , V_92 , V_93 ) ;
V_97 -> V_122 = F_25 ( V_93 ) ;
V_97 -> V_92 = F_25 ( V_92 ) ;
V_97 -> V_123 = F_25 ( - 1 ) ;
V_97 -> V_124 = F_25 ( V_82 &
V_125 ) ;
for ( V_61 = 0 ; V_61 < V_82 ; V_61 ++ )
V_97 -> V_91 [ V_61 ] = F_15 ( V_83 [ V_61 ] ) ;
V_95 -> V_89 . V_126 = F_25 ( V_127 ) ;
V_95 -> V_89 . V_7 = F_15 ( V_128 ) ;
V_95 -> V_89 . V_129 = F_15 ( 0x1234 ) ;
V_43 = F_16 ( V_53 -> V_41 , L_39 , V_94 , V_87 ) ;
if ( ! V_43 )
F_21 ( V_130 , & V_48 -> V_107 -> V_131 ) ;
exit:
F_28 ( V_94 ) ;
return V_43 ;
}
static T_3 F_29 ( struct V_132 * V_107 ,
struct V_40 * V_41 ,
struct V_57 * V_58 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
T_3 V_133 = 0 ;
T_3 V_84 = V_77 ;
struct V_75 * V_53 ;
struct V_134 * V_135 = NULL ;
int V_61 , V_136 = 0 ;
T_4 * V_83 ;
F_5 ( V_27 , L_28 ) ;
if ( ! V_58 ) {
V_133 = - V_101 ;
goto exit;
}
if ( V_58 -> V_137 ) {
V_83 = F_30 ( V_58 -> V_137 , sizeof( * V_83 ) ,
V_99 ) ;
if ( ! V_83 ) {
V_133 = - V_100 ;
goto exit;
}
V_53 = V_48 -> V_51 [ V_138 ] . V_53 ;
if ( V_53 )
V_135 = V_53 -> V_139 . V_140 ;
if ( V_58 -> V_137 == 3 &&
V_58 -> V_141 [ 0 ] -> V_142 == V_143 &&
V_58 -> V_141 [ 1 ] -> V_142 == V_144 &&
V_58 -> V_141 [ 2 ] -> V_142 == V_145 ) {
V_84 = V_102 ;
F_5 ( V_65 , L_40 ) ;
} else if ( V_135 != NULL &&
V_53 -> V_139 . V_146 == V_147 ) {
F_5 ( V_65 , L_41 ) ;
V_84 = V_102 ;
} else {
F_5 ( V_65 , L_42 ) ;
}
for ( V_61 = 0 ; V_61 < V_58 -> V_137 ; V_61 ++ ) {
struct V_148 * V_149 = V_58 -> V_141 [ V_61 ] ;
if ( V_149 -> V_150 & ( V_151 |
V_152 ) )
continue;
V_83 [ V_61 ] = F_31 ( & V_48 -> V_107 -> V_153 ,
V_149 ) ;
F_5 ( V_65 , L_43 ,
V_136 , V_149 -> V_142 , V_83 [ V_61 ] ) ;
V_136 ++ ;
}
V_133 = F_22 ( V_48 , V_136 , V_83 , V_84 ,
V_76 ) ;
F_28 ( V_83 ) ;
}
exit:
if ( V_133 )
F_10 ( L_44 , V_133 ) ;
return V_133 ;
}
static T_3 F_32 ( const T_2 * V_154 , T_1 V_155 )
{
T_2 V_156 [ 5 ] ;
T_3 V_157 ;
T_3 V_133 ;
V_133 = F_33 ( V_154 , V_155 ,
V_158 ,
V_156 , sizeof( V_156 ) ) ;
if ( V_133 < 0 )
return V_133 ;
V_157 = ( T_3 ) V_156 [ 3 + 1 ] ;
if ( V_157 == V_143 ||
V_157 == V_144 ||
V_157 == V_145 ) {
F_5 ( V_65 , L_45 , V_157 ) ;
return V_157 ;
}
return - V_78 ;
}
int F_34 ( struct V_159 * V_159 ,
struct V_57 * V_58 ,
struct V_75 * V_53 )
{
struct V_132 * V_107 = F_35 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
int V_133 = 0 ;
if ( F_13 ( V_58 ) ) {
V_133 = F_32 ( V_58 -> V_154 ,
V_58 -> V_155 ) ;
if ( V_133 < 0 )
return V_133 ;
V_48 -> V_160 . V_161 = V_133 ;
F_36 ( V_162 , & V_48 -> V_80 ) ;
F_5 ( V_65 , L_46 ) ;
V_133 = F_18 ( V_48 ) ;
if ( V_133 )
return V_133 ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
V_107 -> V_163 . V_164 = F_29 ;
}
V_133 = F_37 ( V_53 , V_165 ,
V_58 -> V_154 , V_58 -> V_155 ) ;
return V_133 ;
}
static T_3
F_38 ( struct V_47 * V_48 , T_4 V_166 , T_1 V_167 )
{
struct V_75 * V_53 ;
struct V_168 V_169 ;
T_3 V_133 = 0 ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_47 ) ;
V_133 = - V_78 ;
goto exit;
}
if ( F_19 ( V_170 , & V_48 -> V_80 ) ) {
F_10 ( L_48 ) ;
goto exit;
}
V_169 . V_171 = V_166 ;
V_169 . V_172 = V_173 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
V_133 = F_14 ( V_53 -> V_41 , V_175 ,
V_169 . V_73 , ( T_4 ) V_167 ) ;
if ( ! V_133 ) {
F_21 ( V_170 , & V_48 -> V_80 ) ;
V_48 -> V_176 ++ ;
}
exit:
return V_133 ;
}
int F_39 ( struct V_159 * V_159 , struct V_177 * V_139 ,
struct V_148 * V_166 ,
unsigned int V_167 , T_5 * V_178 )
{
struct V_132 * V_107 = F_35 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
T_3 V_133 ;
T_4 V_179 ;
V_179 = F_40 ( V_166 -> V_180 ) ;
F_5 ( V_27 , L_49 , V_179 ,
V_167 ) ;
V_133 = F_18 ( V_48 ) ;
if ( V_133 )
goto exit;
V_133 = F_38 ( V_48 , V_179 , V_167 ) ;
if ( V_133 )
goto exit;
memcpy ( & V_48 -> V_181 , V_166 , sizeof( * V_166 ) ) ;
* V_178 = V_48 -> V_176 ;
F_41 ( V_139 , * V_178 , V_166 , V_167 , V_99 ) ;
exit:
return V_133 ;
}
int F_42 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
F_5 ( V_27 , L_50 ) ;
if ( F_43 ( V_170 ,
& V_48 -> V_80 ) ) {
if ( F_43 ( V_187 ,
& V_48 -> V_80 ) ) {
F_36 ( V_188 ,
& V_48 -> V_80 ) ;
F_5 ( V_65 , L_51 ) ;
F_44 ( & V_48 -> V_189 ) ;
}
F_45 ( & V_41 -> V_53 -> V_139 ,
V_48 -> V_176 ,
& V_48 -> V_181 ,
V_99 ) ;
}
return 0 ;
}
void F_46 ( struct V_40 * V_41 )
{
if ( ! V_41 )
return;
F_14 ( V_41 , V_77 , 0 , 0 ) ;
F_42 ( V_41 , NULL , NULL ) ;
}
static T_3 F_47 ( struct V_47 * V_48 , T_4 V_166 )
{
T_3 V_133 ;
T_1 V_190 ;
T_4 * V_191 ;
T_1 V_61 ;
struct V_168 V_169 ;
F_5 ( V_27 , L_50 ) ;
if ( V_166 )
V_190 = V_115 ;
else
V_190 = V_113 ;
V_191 = F_24 ( V_190 * sizeof( * V_191 ) ,
V_99 ) ;
if ( V_191 == NULL ) {
F_10 ( L_52 ) ;
V_133 = - V_100 ;
goto exit;
}
V_169 . V_172 = V_173 ;
if ( V_166 ) {
V_169 . V_171 = V_166 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
for ( V_61 = 0 ; V_61 < V_190 ; V_61 ++ )
V_191 [ V_61 ] = V_169 . V_73 ;
} else {
V_169 . V_171 = V_143 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
V_191 [ 0 ] = V_169 . V_73 ;
V_169 . V_171 = V_144 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
V_191 [ 1 ] = V_169 . V_73 ;
V_169 . V_171 = V_145 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
V_191 [ 2 ] = V_169 . V_73 ;
}
V_133 = F_22 ( V_48 , V_190 , V_191 ,
V_102 , V_76 ) ;
F_28 ( V_191 ) ;
exit:
return V_133 ;
}
static void F_48 ( struct V_192 * V_193 )
{
struct V_160 * V_160 = F_49 ( V_193 , struct V_160 , V_194 ) ;
struct V_47 * V_48 = F_49 ( V_160 ,
struct V_47 ,
V_160 ) ;
T_3 V_133 ;
if ( ! V_160 -> V_195 )
return;
if ( V_160 -> V_196 && V_160 -> V_161 )
V_133 = F_38 ( V_48 , V_160 -> V_161 ,
100 * ( 1 + F_50 () % 3 ) ) ;
else
V_133 = F_47 ( V_48 , V_160 -> V_197 ) ;
if ( V_133 ) {
F_10 ( L_53 , V_133 ) ;
if ( F_19 ( V_198 ,
& V_48 -> V_80 ) )
F_44 ( & V_160 -> V_199 ) ;
}
}
static T_3 F_51 ( struct V_47 * V_48 )
{
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_75 * V_200 ;
unsigned long V_167 ;
T_3 V_201 ;
F_5 ( V_27 , L_50 ) ;
V_200 = V_48 -> V_51 [ V_52 ] . V_53 ;
F_52 ( & V_160 -> V_199 ) ;
F_21 ( V_198 , & V_48 -> V_80 ) ;
V_160 -> V_195 = true ;
V_160 -> V_202 = V_203 ;
V_201 = 0 ;
V_167 = F_53 ( V_204 ) ;
while ( ( V_201 < V_205 ) &&
( V_160 -> V_202 == V_203 ) ) {
V_160 -> V_196 = false ;
F_5 ( V_27 , L_54 ,
V_201 ) ;
F_54 ( & V_160 -> V_194 ) ;
F_55 ( & V_160 -> V_199 , V_167 ) ;
if ( ( V_160 -> V_202 != V_203 ) ||
( ! F_19 ( V_198 ,
& V_48 -> V_80 ) ) )
break;
if ( V_160 -> V_161 ) {
F_5 ( V_27 , L_55 ,
V_160 -> V_161 ) ;
V_160 -> V_196 = true ;
F_54 ( & V_160 -> V_194 ) ;
F_55 ( & V_160 -> V_199 ,
V_167 ) ;
}
if ( ( V_160 -> V_202 != V_203 ) ||
( ! F_19 ( V_198 ,
& V_48 -> V_80 ) ) )
break;
V_201 ++ ;
if ( F_19 ( V_117 , & V_200 -> V_206 ) ||
F_19 ( V_207 , & V_200 -> V_206 ) )
F_56 ( V_208 ) ;
}
F_5 ( V_27 , L_56 ,
V_160 -> V_202 ) ;
V_160 -> V_195 = false ;
F_36 ( V_198 , & V_48 -> V_80 ) ;
return V_160 -> V_202 ;
}
bool F_57 ( struct V_132 * V_107 ,
struct V_209 * V_210 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_168 V_169 ;
T_2 * V_154 ;
T_3 V_133 ;
T_2 V_211 [ V_46 ] ;
if ( ! F_19 ( V_198 , & V_48 -> V_80 ) )
return false ;
if ( V_210 == NULL ) {
F_5 ( V_27 , L_57 ) ;
if ( V_160 -> V_202 == V_203 )
F_44 ( & V_160 -> V_199 ) ;
return true ;
}
V_154 = ( ( T_2 * ) V_210 ) + F_58 ( V_210 -> V_212 ) ;
memset ( V_211 , 0 , sizeof( V_211 ) ) ;
V_133 = F_33 ( V_154 , F_59 ( V_210 -> V_213 ) ,
V_214 ,
V_211 , sizeof( V_211 ) ) ;
if ( V_133 < 0 )
V_133 = F_33 ( V_154 , F_59 ( V_210 -> V_213 ) ,
V_215 ,
V_211 , sizeof( V_211 ) ) ;
if ( ( V_133 >= 0 ) &&
( F_60 ( V_211 , V_160 -> V_216 ) ) ) {
if ( ! V_210 -> V_217 ) {
V_169 . V_73 = F_58 ( V_210 -> V_69 ) ;
V_107 -> V_153 . V_218 ( & V_169 ) ;
V_210 -> V_217 = V_169 . V_171 ;
}
V_160 -> V_202 = V_210 -> V_217 ;
F_5 ( V_27 , L_58 ,
V_160 -> V_216 , V_160 -> V_202 ) ;
F_44 ( & V_160 -> V_199 ) ;
}
return true ;
}
static void
F_61 ( struct V_132 * V_107 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_40 * V_41 = V_107 -> V_163 . V_41 ;
if ( F_19 ( V_219 , & V_48 -> V_80 ) &&
( F_19 ( V_220 , & V_48 -> V_80 ) ||
F_19 ( V_221 , & V_48 -> V_80 ) ) ) {
F_5 ( V_27 , L_59 ) ;
if ( V_48 -> V_222 )
F_62 ( V_107 , V_41 , true , true ) ;
} else if ( F_19 ( V_187 ,
& V_48 -> V_80 ) ) {
F_5 ( V_27 , L_60 ) ;
F_62 ( V_107 , V_41 , true , true ) ;
}
}
static bool
F_63 ( struct V_47 * V_48 , T_2 * V_223 )
{
struct V_132 * V_107 = V_48 -> V_107 ;
struct V_40 * V_41 ;
F_5 ( V_27 , L_50 ) ;
if ( ! F_19 ( V_188 , & V_48 -> V_80 ) ||
! V_48 -> V_224 )
return false ;
F_5 ( V_27 , L_61 ) ;
V_41 = V_48 -> V_51 [ V_76 ] . V_53 -> V_41 ;
if ( memcmp ( V_223 , V_41 -> V_55 , V_46 ) < 0 ) {
F_5 ( V_65 , L_62 ) ;
V_48 -> V_225 = true ;
if ( F_43 ( V_198 ,
& V_48 -> V_80 ) )
F_44 ( & V_48 -> V_160 . V_199 ) ;
if ( F_43 ( V_188 ,
& V_48 -> V_80 ) )
F_61 ( V_107 ) ;
return false ;
}
F_5 ( V_65 , L_63 ) ;
return true ;
}
int F_64 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_177 * V_139 ;
T_1 V_226 = V_183 -> V_227 - sizeof( struct V_228 ) ;
struct V_228 * V_229 = (struct V_228 * ) V_184 ;
T_2 * V_1 = ( T_2 * ) ( V_229 + 1 ) ;
struct V_3 * V_15 ;
struct V_17 * V_18 ;
struct V_168 V_169 ;
struct V_230 * V_231 ;
T_3 V_232 ;
T_4 V_233 ;
T_2 V_7 ;
V_169 . V_73 = F_65 ( V_229 -> V_69 ) ;
V_107 -> V_153 . V_218 ( & V_169 ) ;
F_5 ( V_65 , L_64 , V_41 -> V_53 -> V_234 ) ;
V_233 = ( V_235 & V_236 ) >> 4 ;
if ( ( V_41 -> V_53 -> V_234 & F_66 ( V_233 ) ) == 0 )
return 0 ;
F_4 ( false , V_1 , V_226 ) ;
V_7 = V_237 ;
if ( F_1 ( V_1 , V_226 ) ) {
V_15 = (struct V_3 * ) V_1 ;
V_7 = V_15 -> V_25 ;
if ( ( V_7 == V_26 ) &&
( F_63 ( V_48 , ( T_2 * ) V_183 -> V_238 ) ) ) {
if ( F_19 ( V_198 ,
& V_48 -> V_80 ) &&
( F_60 ( V_160 -> V_216 , V_183 -> V_238 ) ) ) {
V_160 -> V_202 = V_169 . V_171 ;
F_5 ( V_65 , L_65 ,
V_160 -> V_202 ) ;
F_44 ( & V_160 -> V_199 ) ;
}
return 0 ;
}
if ( ( V_7 == V_29 ) ||
( V_7 == V_35 ) )
F_67 ( V_41 , 1 ) ;
if ( V_7 == V_29 ) {
F_5 ( V_27 , L_46 ) ;
F_36 ( V_162 , & V_48 -> V_80 ) ;
}
} else if ( F_3 ( V_1 , V_226 ) ) {
V_18 = (struct V_17 * ) V_1 ;
V_7 = V_18 -> V_7 ;
}
if ( F_19 ( V_188 , & V_48 -> V_80 ) &&
( V_48 -> V_239 == V_7 ) ) {
F_5 ( V_27 , L_66 , V_7 ) ;
F_36 ( V_188 ,
& V_48 -> V_80 ) ;
F_61 ( V_107 ) ;
}
V_231 = F_24 ( F_23 ( struct V_230 , V_240 ) +
V_226 , V_99 ) ;
if ( ! V_231 ) {
F_10 ( L_67 ) ;
return - V_100 ;
}
memcpy ( V_231 -> V_241 , V_41 -> V_55 , V_46 ) ;
F_68 ( V_41 , V_242 , V_231 -> V_110 ,
V_46 ) ;
memcpy ( V_231 -> V_243 , V_183 -> V_238 , V_46 ) ;
V_231 -> V_244 = F_15 ( V_235 ) ;
memcpy ( & V_231 -> V_240 , V_1 , V_226 ) ;
V_226 += F_23 ( struct V_230 , V_240 ) ;
V_232 = F_69 ( V_169 . V_171 ,
V_169 . V_245 == V_246 ?
V_247 :
V_248 ) ;
V_139 = & V_41 -> V_53 -> V_139 ;
F_70 ( V_139 , V_232 , 0 , ( T_2 * ) V_231 , V_226 , 0 ) ;
F_28 ( V_231 ) ;
return 0 ;
}
int F_71 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
F_5 ( V_65 , L_68 ,
V_183 -> V_249 == V_250 ?
L_69 : L_70 ,
V_183 -> V_80 ) ;
if ( ! F_19 ( V_219 , & V_48 -> V_80 ) )
return 0 ;
if ( V_183 -> V_249 == V_251 ) {
if ( V_183 -> V_80 == V_252 )
F_21 ( V_220 ,
& V_48 -> V_80 ) ;
else {
F_21 ( V_221 , & V_48 -> V_80 ) ;
F_61 ( V_107 ) ;
}
} else {
F_44 ( & V_48 -> V_253 ) ;
}
return 0 ;
}
static T_3 F_72 ( struct V_47 * V_48 ,
struct V_254 * V_255 )
{
struct V_75 * V_53 ;
T_3 V_133 = 0 ;
T_3 V_256 = 0 ;
F_5 ( V_27 , L_50 ) ;
F_52 ( & V_48 -> V_253 ) ;
F_36 ( V_220 , & V_48 -> V_80 ) ;
F_36 ( V_221 , & V_48 -> V_80 ) ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
V_133 = F_16 ( V_53 -> V_41 , L_71 , V_255 ,
sizeof( * V_255 ) ) ;
if ( V_133 ) {
F_10 ( L_72 ) ;
goto exit;
}
V_48 -> V_222 = F_59 ( V_255 -> V_166 ) ;
V_48 -> V_257 = V_258 ;
V_256 = F_55 ( & V_48 -> V_253 ,
V_259 ) ;
if ( F_19 ( V_220 , & V_48 -> V_80 ) ) {
F_5 ( V_27 , L_73 ) ;
} else {
V_133 = - V_260 ;
F_5 ( V_27 , L_74 ) ;
}
F_36 ( V_220 , & V_48 -> V_80 ) ;
F_36 ( V_221 , & V_48 -> V_80 ) ;
exit:
return V_133 ;
}
static T_3 F_73 ( struct V_132 * V_107 ,
struct V_254 * V_255 ,
struct V_261 * V_262 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_263 * V_264 ;
struct V_3 * V_15 ;
T_3 V_133 = 0 ;
T_4 V_155 ;
V_264 = & V_255 -> V_264 ;
V_15 = (struct V_3 * ) ( V_264 -> V_184 ) ;
V_262 -> V_265 = true ;
switch ( V_15 -> V_25 ) {
case V_26 :
F_5 ( V_27 , L_75 ) ;
F_21 ( V_162 , & V_48 -> V_80 ) ;
V_262 -> V_266 = 0 ;
V_262 -> V_267 = true ;
V_48 -> V_239 = V_15 -> V_25 + 1 ;
V_48 -> V_224 = true ;
V_255 -> V_268 = F_25 ( V_269 ) ;
break;
case V_28 :
V_48 -> V_239 = V_15 -> V_25 + 1 ;
V_255 -> V_268 = F_25 ( V_269 ) ;
break;
case V_29 :
F_5 ( V_27 , L_46 ) ;
F_36 ( V_162 , & V_48 -> V_80 ) ;
V_262 -> V_266 = 1 ;
V_255 -> V_268 = F_25 ( V_270 ) ;
V_262 -> V_265 = false ;
break;
case V_30 :
V_262 -> V_267 = true ;
V_48 -> V_239 = V_15 -> V_25 + 1 ;
V_255 -> V_268 = F_25 ( V_269 ) ;
break;
case V_31 :
V_255 -> V_268 = F_25 ( V_270 ) ;
V_262 -> V_265 = false ;
break;
case V_32 :
V_262 -> V_267 = true ;
V_48 -> V_239 = V_15 -> V_25 + 1 ;
V_255 -> V_268 = F_25 ( V_271 ) ;
break;
case V_33 :
V_255 -> V_268 = F_25 ( V_270 ) ;
V_262 -> V_265 = false ;
break;
case V_34 :
V_155 = F_58 ( V_264 -> V_272 ) -
F_23 ( struct V_3 , V_273 ) ;
if ( F_33 ( & V_15 -> V_273 [ 0 ] , V_155 ,
V_274 ,
NULL , 0 ) < 0 )
V_262 -> V_267 = true ;
V_262 -> V_266 = 0 ;
V_48 -> V_239 = V_15 -> V_25 + 1 ;
V_255 -> V_268 = F_25 ( V_269 ) ;
break;
case V_35 :
V_48 -> V_239 = V_26 ;
V_255 -> V_268 = F_25 ( V_269 ) ;
V_262 -> V_265 = false ;
break;
default:
F_10 ( L_76 ,
V_15 -> V_25 ) ;
V_133 = - V_101 ;
}
return V_133 ;
}
bool F_74 ( struct V_132 * V_107 ,
struct V_134 * V_275 ,
struct V_254 * V_255 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_40 * V_41 = F_75 ( V_275 ) ;
struct V_263 * V_264 ;
struct V_261 V_262 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
T_4 V_276 ;
bool V_277 = false ;
T_2 V_5 ;
T_2 V_7 ;
T_3 V_278 ;
T_3 V_279 ;
T_6 V_280 ;
V_264 = & V_255 -> V_264 ;
V_276 = F_58 ( V_264 -> V_272 ) ;
F_4 ( true , V_264 -> V_184 , V_276 ) ;
V_255 -> V_268 = F_25 ( V_281 ) ;
V_5 = V_264 -> V_184 [ V_282 ] ;
V_7 = V_264 -> V_184 [ V_283 ] ;
V_48 -> V_239 = V_237 ;
V_48 -> V_224 = false ;
V_262 . V_266 = - 1 ;
V_262 . V_267 = false ;
V_262 . V_265 = false ;
if ( F_1 ( V_264 -> V_184 , V_276 ) ) {
if ( F_73 ( V_107 , V_255 , & V_262 ) ) {
F_10 ( L_77 ) ;
}
} else if ( F_3 ( V_264 -> V_184 ,
V_276 ) ) {
if ( V_7 == V_20 ||
V_7 == V_22 ) {
V_262 . V_267 = true ;
V_48 -> V_239 = V_7 + 1 ;
V_255 -> V_268 =
F_25 ( V_269 ) ;
} else if ( V_7 == V_21 ||
V_7 == V_23 ) {
V_255 -> V_268 =
F_25 ( V_270 ) ;
} else {
F_10 ( L_78 , V_7 ) ;
goto exit;
}
} else if ( F_2 ( V_264 -> V_184 ,
V_276 ) ) {
} else {
F_10 ( L_79 ,
V_5 , V_7 ) ;
return false ;
}
if ( F_19 ( V_207 ,
& V_48 -> V_51 [ V_52 ] . V_53 -> V_206 ) )
F_56 ( 50 ) ;
if ( F_19 ( V_130 , & V_107 -> V_131 ) )
F_76 ( V_107 ) ;
memcpy ( V_160 -> V_216 , V_264 -> V_241 , V_46 ) ;
if ( V_262 . V_266 == 0 )
F_67 ( V_41 , 0 ) ;
if ( V_48 -> V_239 != V_237 ) {
F_21 ( V_188 , & V_48 -> V_80 ) ;
}
V_48 -> V_222 = 0 ;
F_21 ( V_219 , & V_48 -> V_80 ) ;
if ( V_262 . V_267 &&
F_77 ( F_59 ( V_255 -> V_166 ) ) &&
V_48 -> V_51 [ V_76 ] . V_53 -> V_284 . V_285 ) {
V_160 = & V_48 -> V_160 ;
V_160 -> V_197 = F_59 ( V_255 -> V_166 ) ;
if ( F_51 ( V_48 ) ==
V_203 ) {
F_10 ( L_80 ) ;
goto exit;
}
F_62 ( V_107 , V_41 , true , true ) ;
V_255 -> V_166 = F_25 ( V_160 -> V_202 ) ;
}
V_278 = 0 ;
while ( ! V_48 -> V_225 &&
( V_277 == false ) && ( V_278 < V_286 ) ) {
V_277 = ! F_72 ( V_48 , V_255 ) ;
V_278 ++ ;
}
if ( V_277 == false ) {
F_10 ( L_81 , V_278 ) ;
F_36 ( V_162 , & V_48 -> V_80 ) ;
}
exit:
F_36 ( V_219 , & V_48 -> V_80 ) ;
if ( V_277 && V_262 . V_265 && ! V_48 -> V_225 &&
F_19 ( V_188 , & V_48 -> V_80 ) &&
V_48 -> V_222 == V_160 -> V_161 ) {
V_280 = F_78 ( V_258 - V_48 -> V_257 ) ;
if ( F_59 ( V_255 -> V_268 ) > V_280 )
V_279 = F_59 ( V_255 -> V_268 ) -
V_280 ;
else
V_279 = 0 ;
if ( V_279 > 50 ) {
F_21 ( V_187 ,
& V_48 -> V_80 ) ;
F_5 ( V_65 , L_82 ,
F_59 ( V_255 -> V_268 ) ,
V_279 ) ;
V_279 += 100 ;
if ( ! F_38 ( V_48 ,
V_48 -> V_222 ,
V_279 ) ) {
unsigned long V_167 ;
V_279 += 100 ;
V_167 = F_53 ( V_279 ) ;
F_55 ( & V_48 -> V_189 ,
V_167 ) ;
}
F_36 ( V_187 ,
& V_48 -> V_80 ) ;
}
}
if ( V_48 -> V_225 ) {
V_48 -> V_225 = false ;
V_277 = true ;
}
F_36 ( V_188 , & V_48 -> V_80 ) ;
if ( V_262 . V_266 == 1 )
F_67 ( V_41 , 1 ) ;
return V_277 ;
}
T_3 F_79 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_75 * V_53 = V_41 -> V_53 ;
struct V_228 * V_229 = (struct V_228 * ) V_184 ;
T_4 V_69 = F_65 ( V_229 -> V_69 ) ;
struct V_168 V_169 ;
T_2 * V_231 ;
T_1 V_226 ;
T_3 V_232 ;
T_4 V_233 ;
F_5 ( V_65 , L_83 , V_183 -> V_249 ,
V_183 -> V_287 ) ;
V_169 . V_73 = F_65 ( V_229 -> V_69 ) ;
V_107 -> V_153 . V_218 ( & V_169 ) ;
if ( F_19 ( V_198 , & V_48 -> V_80 ) &&
( F_60 ( V_160 -> V_216 , V_183 -> V_238 ) ) ) {
V_160 -> V_202 = V_169 . V_171 ;
F_5 ( V_65 , L_84 ,
V_160 -> V_202 ) ;
F_44 ( & V_160 -> V_199 ) ;
}
if ( V_183 -> V_288 == 0 )
return 0 ;
if ( F_19 ( V_162 , & V_48 -> V_80 ) ) {
F_5 ( V_65 , L_85 ) ;
return 0 ;
}
F_5 ( V_65 , L_86 , V_53 -> V_234 ) ;
V_233 = ( V_289 & V_236 ) >> 4 ;
if ( ( V_53 -> V_234 & F_66 ( V_233 ) ) == 0 )
return 0 ;
V_231 = ( T_2 * ) ( V_229 + 1 ) ;
V_226 = V_183 -> V_227 - sizeof( * V_229 ) ;
V_232 = F_69 ( V_169 . V_171 ,
V_169 . V_245 == V_246 ?
V_247 :
V_248 ) ;
F_70 ( & V_53 -> V_139 , V_232 , 0 , V_231 , V_226 , 0 ) ;
F_5 ( V_65 , L_87 ,
V_226 , V_183 -> V_227 , V_69 , V_232 ) ;
return 0 ;
}
static void F_80 ( struct V_47 * V_48 ,
T_4 * V_69 )
{
struct V_40 * V_41 ;
T_2 V_55 [ V_46 ] ;
struct V_168 V_169 ;
struct V_209 * V_210 ;
T_2 * V_290 ;
V_41 = V_48 -> V_51 [ V_52 ] . V_53 -> V_41 ;
if ( F_68 ( V_41 , V_242 , V_55 ,
V_46 ) == 0 ) {
V_290 = F_24 ( V_291 , V_99 ) ;
if ( V_290 != NULL ) {
* ( V_292 * ) V_290 = F_25 ( V_291 ) ;
if ( F_68 ( V_41 , V_293 ,
V_290 , V_291 ) == 0 ) {
V_210 = (struct V_209 * ) ( V_290 + 4 ) ;
* V_69 = F_58 ( V_210 -> V_69 ) ;
F_28 ( V_290 ) ;
return;
}
F_28 ( V_290 ) ;
}
}
V_169 . V_171 = V_294 ;
V_169 . V_172 = V_173 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
* V_69 = V_169 . V_73 ;
}
int F_81 ( struct V_132 * V_107 ,
enum V_295 V_296 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
struct V_297 V_298 ;
T_3 V_133 ;
T_4 V_69 ;
F_5 ( V_27 , L_50 ) ;
V_53 = V_48 -> V_51 [ V_52 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_88 ) ;
return - V_78 ;
}
F_62 ( V_107 , V_53 -> V_41 , true , true ) ;
V_53 = V_48 -> V_51 [ V_138 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_89 ) ;
return - V_78 ;
}
F_67 ( V_53 -> V_41 , 0 ) ;
F_80 ( V_48 , & V_69 ) ;
V_298 . type = F_15 ( ( T_4 ) V_296 ) ;
V_298 . V_73 = F_15 ( V_69 ) ;
memcpy ( V_298 . V_238 , V_48 -> V_56 , sizeof( V_298 . V_238 ) ) ;
F_82 ( V_107 , V_53 ) ;
V_133 = F_9 ( V_53 -> V_41 , L_90 , & V_298 ,
sizeof( V_298 ) ) ;
if ( V_133 ) {
F_10 ( L_91 , V_133 ) ;
F_82 ( V_107 , NULL ) ;
return V_133 ;
}
V_133 = F_83 ( V_107 , V_299 ,
V_300 ) ;
F_82 ( V_107 , NULL ) ;
if ( ! V_133 ) {
F_10 ( L_92 ) ;
return - V_260 ;
}
V_133 = F_7 ( V_53 -> V_41 , V_301 ,
V_302 ) ;
return V_133 ;
}
static int F_84 ( struct V_47 * V_48 ,
struct V_40 * V_41 , T_2 V_303 [ V_46 ] ,
enum V_295 V_146 )
{
struct V_297 V_298 ;
int V_133 ;
T_4 V_69 ;
F_80 ( V_48 , & V_69 ) ;
memcpy ( V_298 . V_238 , V_303 , V_46 ) ;
V_298 . type = F_15 ( ( T_4 ) V_146 ) ;
V_298 . V_73 = F_15 ( V_69 ) ;
V_133 = F_9 ( V_41 , L_93 , & V_298 ,
sizeof( V_298 ) ) ;
if ( V_133 )
return V_133 ;
return V_133 ;
}
static int F_85 ( struct V_75 * V_53 )
{
struct V_132 * V_107 = F_86 ( & V_53 -> V_139 ) ;
struct V_134 * V_304 = F_87 ( V_107 ) ;
struct V_40 * V_41 = F_75 ( V_304 ) ;
T_2 * V_238 = V_53 -> V_139 . V_140 -> V_49 ;
return F_9 ( V_41 , L_94 , V_238 , V_46 ) ;
}
static int F_88 ( struct V_75 * V_53 )
{
struct V_132 * V_107 = F_86 ( & V_53 -> V_139 ) ;
struct V_134 * V_304 = F_87 ( V_107 ) ;
struct V_40 * V_41 = F_75 ( V_304 ) ;
T_2 * V_238 = V_53 -> V_139 . V_140 -> V_49 ;
return F_9 ( V_41 , L_95 , V_238 , V_46 ) ;
}
static struct V_177 * F_89 ( struct V_47 * V_48 ,
struct V_159 * V_159 ,
T_2 * V_238 )
{
struct V_75 * V_305 ;
struct V_40 * V_306 ;
struct V_40 * V_50 ;
int V_133 ;
T_1 V_288 ;
if ( V_48 -> V_51 [ V_76 ] . V_53 )
return F_90 ( - V_307 ) ;
V_305 = F_91 ( V_48 -> V_107 , V_308 ,
false ) ;
if ( F_92 ( V_305 ) ) {
F_10 ( L_96 ) ;
return (struct V_177 * ) V_305 ;
}
V_50 = V_48 -> V_51 [ V_52 ] . V_53 -> V_41 ;
F_11 ( V_48 , V_238 ) ;
F_6 ( V_50 , V_48 -> V_49 ) ;
F_82 ( V_48 -> V_107 , V_305 ) ;
F_93 ( V_50 , true ) ;
V_133 = F_8 ( V_50 , L_24 , 1 ) ;
if ( V_133 < 0 ) {
F_10 ( L_32 ) ;
F_93 ( V_50 , false ) ;
F_82 ( V_48 -> V_107 , NULL ) ;
goto V_309;
}
V_133 = F_83 ( V_48 -> V_107 , V_310 ,
V_300 ) ;
F_82 ( V_48 -> V_107 , NULL ) ;
F_93 ( V_50 , false ) ;
if ( ! V_133 ) {
F_10 ( L_97 ) ;
V_133 = - V_260 ;
goto V_309;
}
V_306 = V_305 -> V_41 ;
V_48 -> V_51 [ V_76 ] . V_53 = V_305 ;
memcpy ( V_306 -> V_55 , V_48 -> V_49 , V_46 ) ;
memcpy ( & V_305 -> V_139 . V_311 , V_48 -> V_49 , sizeof( V_48 -> V_49 ) ) ;
V_133 = F_94 ( V_50 , L_98 , & V_288 ) ;
if ( V_133 < 0 ) {
F_10 ( L_99 ) ;
goto V_309;
}
F_95 ( V_306 -> V_288 != V_288 ) ;
F_96 ( & V_48 -> V_253 ) ;
F_97 ( & V_48 -> V_160 . V_194 , F_48 ) ;
F_96 ( & V_48 -> V_160 . V_199 ) ;
F_96 ( & V_48 -> V_189 ) ;
return & V_305 -> V_139 ;
V_309:
F_98 ( V_305 ) ;
return F_90 ( V_133 ) ;
}
struct V_177 * F_99 ( struct V_159 * V_159 , const char * V_312 ,
unsigned char V_313 ,
enum V_314 type , T_1 * V_150 ,
struct V_315 * V_316 )
{
struct V_132 * V_107 = F_35 ( V_159 ) ;
struct V_40 * V_41 = F_75 ( F_87 ( V_107 ) ) ;
struct V_75 * V_53 ;
enum V_295 V_146 ;
int V_133 ;
if ( F_100 ( V_107 ) )
return F_90 ( - V_317 ) ;
F_5 ( V_65 , L_100 , V_312 , type ) ;
switch ( type ) {
case V_318 :
V_146 = V_319 ;
break;
case V_147 :
V_146 = V_320 ;
break;
case V_308 :
return F_89 ( & V_107 -> V_48 , V_159 ,
V_316 -> V_321 ) ;
default:
return F_90 ( - V_322 ) ;
}
V_53 = F_91 ( V_107 , type , false ) ;
if ( F_92 ( V_53 ) )
return (struct V_177 * ) V_53 ;
F_82 ( V_107 , V_53 ) ;
V_133 = F_84 ( & V_107 -> V_48 , V_41 , V_107 -> V_48 . V_56 ,
V_146 ) ;
if ( V_133 ) {
F_82 ( V_107 , NULL ) ;
goto V_309;
}
V_133 = F_83 ( V_107 , V_310 ,
V_300 ) ;
F_82 ( V_107 , NULL ) ;
if ( ! V_133 ) {
F_10 ( L_97 ) ;
V_133 = - V_260 ;
goto V_309;
}
V_41 = V_53 -> V_41 ;
if ( ! V_41 ) {
F_10 ( L_101 ) ;
V_133 = - V_323 ;
goto V_309;
}
strncpy ( V_41 -> V_275 -> V_312 , V_312 , sizeof( V_41 -> V_275 -> V_312 ) - 1 ) ;
V_41 -> V_275 -> V_313 = V_313 ;
V_133 = F_101 ( V_41 , true ) ;
if ( V_133 ) {
F_10 ( L_102 ) ;
goto V_309;
}
V_107 -> V_48 . V_51 [ V_138 ] . V_53 = V_53 ;
F_8 ( V_41 , L_103 , 1 ) ;
if ( V_146 == V_320 ) {
F_7 ( V_41 , V_301 ,
V_302 ) ;
}
return & V_41 -> V_53 -> V_139 ;
V_309:
F_98 ( V_53 ) ;
return F_90 ( V_133 ) ;
}
int F_102 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_103 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
bool V_324 = false ;
int V_133 ;
F_5 ( V_27 , L_104 ) ;
V_53 = F_49 ( V_139 , struct V_75 , V_139 ) ;
F_82 ( V_107 , V_53 ) ;
switch ( V_53 -> V_139 . V_146 ) {
case V_318 :
if ( F_19 ( V_325 , & V_53 -> V_206 ) )
V_324 = true ;
break;
case V_147 :
if ( ! F_85 ( V_53 ) )
V_324 = true ;
break;
case V_308 :
if ( ! V_48 -> V_51 [ V_76 ] . V_53 )
return 0 ;
F_46 ( V_53 -> V_41 ) ;
F_17 ( V_48 ) ;
default:
return - V_326 ;
}
F_36 ( V_162 , & V_48 -> V_80 ) ;
F_5 ( V_65 , L_46 ) ;
if ( V_324 )
F_55 ( & V_107 -> V_327 ,
V_328 ) ;
V_133 = 0 ;
if ( V_53 -> V_139 . V_146 != V_308 ) {
F_104 ( V_53 ) ;
V_133 = F_88 ( V_53 ) ;
}
if ( ! V_133 ) {
V_133 = F_83 ( V_107 , V_329 ,
V_300 ) ;
if ( ! V_133 )
V_133 = - V_260 ;
else
V_133 = 0 ;
}
if ( V_133 )
F_105 ( V_53 -> V_41 ) ;
F_82 ( V_107 , NULL ) ;
if ( V_53 -> V_139 . V_146 != V_308 )
V_48 -> V_51 [ V_138 ] . V_53 = NULL ;
return V_133 ;
}
void F_106 ( struct V_40 * V_41 )
{
struct V_132 * V_107 ;
struct V_75 * V_53 ;
F_5 ( V_65 , L_105 ) ;
V_53 = V_41 -> V_53 ;
V_107 = F_86 ( & V_53 -> V_139 ) ;
V_107 -> V_48 . V_51 [ V_76 ] . V_53 = NULL ;
F_107 () ;
F_108 ( & V_53 -> V_139 ) ;
F_109 () ;
F_98 ( V_53 ) ;
}
int F_110 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_35 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
int V_133 ;
V_53 = F_49 ( V_139 , struct V_75 , V_139 ) ;
F_111 ( & V_107 -> V_330 ) ;
V_133 = F_18 ( V_48 ) ;
if ( ! V_133 )
F_21 ( V_331 , & V_53 -> V_206 ) ;
F_112 ( & V_107 -> V_330 ) ;
return V_133 ;
}
void F_113 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_35 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
V_53 = F_49 ( V_139 , struct V_75 , V_139 ) ;
if ( V_48 -> V_51 [ V_76 ] . V_53 == V_53 ) {
F_111 ( & V_107 -> V_330 ) ;
( void ) F_14 ( V_53 -> V_41 ,
V_77 , 0 , 0 ) ;
F_76 ( V_107 ) ;
F_36 ( V_331 , & V_53 -> V_206 ) ;
F_112 ( & V_107 -> V_330 ) ;
}
}
T_3 F_114 ( struct V_132 * V_107 , bool V_332 )
{
struct V_47 * V_48 ;
struct V_40 * V_50 ;
T_3 V_133 = 0 ;
void * V_333 ;
V_48 = & V_107 -> V_48 ;
V_48 -> V_107 = V_107 ;
V_50 = F_115 ( V_107 -> V_334 , 0 ) ;
V_48 -> V_51 [ V_52 ] . V_53 = V_50 -> V_53 ;
if ( V_332 ) {
V_333 = F_89 ( V_48 , NULL , NULL ) ;
if ( F_92 ( V_333 ) ) {
F_10 ( L_106 ) ;
V_133 = F_116 ( V_333 ) ;
}
} else {
V_48 -> V_335 = true ;
}
return V_133 ;
}
void F_117 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
if ( V_53 != NULL ) {
F_46 ( V_53 -> V_41 ) ;
F_17 ( V_48 ) ;
F_105 ( V_53 -> V_41 ) ;
}
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
