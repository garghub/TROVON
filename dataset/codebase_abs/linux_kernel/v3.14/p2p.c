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
V_43 = F_9 ( V_41 , L_24 , V_42 ,
V_46 ) ;
if ( V_43 )
F_10 ( L_25 , V_43 ) ;
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
F_5 ( V_65 , L_26 , V_60 [ V_61 ] . V_66 ) ;
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
F_5 ( V_27 , L_27 ) ;
V_72 . V_68 = V_68 ;
V_72 . V_73 = F_15 ( V_69 ) ;
V_72 . V_74 = F_15 ( V_70 ) ;
V_43 = F_16 ( V_41 , L_28 , & V_72 ,
sizeof( V_72 ) ) ;
return V_43 ;
}
static T_3 F_17 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
F_5 ( V_27 , L_27 ) ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
( void ) F_14 ( V_53 -> V_41 , V_77 , 0 , 0 ) ;
V_53 = V_48 -> V_51 [ V_52 ] . V_53 ;
( void ) F_8 ( V_53 -> V_41 , L_29 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
T_3 V_43 = 0 ;
F_5 ( V_27 , L_27 ) ;
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
V_43 = F_8 ( V_53 -> V_41 , L_29 , 1 ) ;
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
T_4 V_83 [] , T_3 V_84 , T_4 V_7 ,
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
struct V_98 V_66 ;
V_87 += V_82 * sizeof( V_99 ) ;
V_94 = F_24 ( V_87 , V_100 ) ;
if ( ! V_94 )
return - V_101 ;
V_53 = V_48 -> V_51 [ V_86 ] . V_53 ;
if ( V_53 == NULL ) {
F_10 ( L_36 , V_86 ) ;
V_43 = - V_102 ;
goto exit;
}
switch ( V_84 ) {
case V_103 :
V_66 . V_104 = 0 ;
memset ( V_66 . V_105 , 0 , sizeof( V_66 . V_105 ) ) ;
break;
case V_77 :
V_66 . V_104 = V_64 ;
memcpy ( V_66 . V_105 , V_67 , V_66 . V_104 ) ;
break;
default:
F_10 ( L_37 , V_84 ) ;
V_43 = - V_102 ;
goto exit;
}
F_14 ( V_53 -> V_41 , V_84 , 0 , 0 ) ;
V_95 = (struct V_88 * ) V_94 ;
V_95 -> type = 'E' ;
V_97 = & V_95 -> V_89 . V_90 ;
V_97 -> V_86 = V_106 ;
if ( V_48 -> V_107 -> V_108 )
V_97 -> V_109 = 0 ;
else
V_97 -> V_109 = 1 ;
memset ( & V_97 -> V_110 , 0xFF , V_46 ) ;
if ( V_66 . V_104 )
memcpy ( V_97 -> V_111 . V_105 , V_66 . V_105 , V_66 . V_104 ) ;
V_97 -> V_111 . V_104 = F_25 ( V_66 . V_104 ) ;
V_97 -> V_112 = F_25 ( V_113 ) ;
if ( V_82 == V_114 || V_82 == ( V_114 + 1 ) )
V_93 = V_115 ;
else if ( V_82 == V_116 )
V_93 = V_117 ;
else if ( F_26 ( V_48 -> V_107 , V_118 ) )
V_93 = - 1 ;
else
V_93 = V_119 ;
if ( V_82 == 1 ) {
V_93 = V_120 ;
V_92 = V_93 / V_121 ;
} else {
V_92 = V_93 / V_122 ;
}
if ( V_92 <= 0 )
V_92 = 1 ;
F_5 ( V_65 , L_38 , V_92 , V_93 ) ;
V_97 -> V_123 = F_25 ( V_93 ) ;
V_97 -> V_92 = F_25 ( V_92 ) ;
V_97 -> V_124 = F_25 ( - 1 ) ;
V_97 -> V_125 = F_25 ( V_82 &
V_126 ) ;
for ( V_61 = 0 ; V_61 < V_82 ; V_61 ++ )
V_97 -> V_91 [ V_61 ] = F_15 ( V_83 [ V_61 ] ) ;
V_95 -> V_89 . V_127 = F_25 ( V_128 ) ;
V_95 -> V_89 . V_7 = F_15 ( V_7 ) ;
V_95 -> V_89 . V_129 = F_15 ( 0x1234 ) ;
V_43 = F_16 ( V_53 -> V_41 , L_39 , V_94 , V_87 ) ;
if ( ! V_43 )
F_21 ( V_130 , & V_48 -> V_107 -> V_131 ) ;
exit:
F_27 ( V_94 ) ;
return V_43 ;
}
static T_3 F_28 ( struct V_132 * V_107 ,
struct V_40 * V_41 ,
struct V_57 * V_58 ,
T_4 V_7 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
T_3 V_133 = 0 ;
T_3 V_84 = V_77 ;
struct V_75 * V_53 ;
struct V_134 * V_135 = NULL ;
int V_61 , V_136 = 0 ;
T_4 * V_83 ;
F_5 ( V_27 , L_27 ) ;
if ( ! V_58 ) {
V_133 = - V_102 ;
goto exit;
}
if ( V_58 -> V_137 ) {
V_83 = F_29 ( V_58 -> V_137 , sizeof( * V_83 ) ,
V_100 ) ;
if ( ! V_83 ) {
V_133 = - V_101 ;
goto exit;
}
V_53 = V_48 -> V_51 [ V_138 ] . V_53 ;
if ( V_53 )
V_135 = V_53 -> V_139 . V_140 ;
if ( V_58 -> V_137 == 3 &&
V_58 -> V_141 [ 0 ] -> V_142 == V_143 &&
V_58 -> V_141 [ 1 ] -> V_142 == V_144 &&
V_58 -> V_141 [ 2 ] -> V_142 == V_145 ) {
V_84 = V_103 ;
F_5 ( V_65 , L_40 ) ;
} else if ( V_135 != NULL && V_53 -> V_146 == V_147 ) {
F_5 ( V_65 , L_41 ) ;
V_84 = V_103 ;
} else {
F_5 ( V_65 , L_42 ) ;
}
for ( V_61 = 0 ; V_61 < V_58 -> V_137 ; V_61 ++ ) {
struct V_148 * V_149 = V_58 -> V_141 [ V_61 ] ;
if ( V_149 -> V_150 & ( V_151 |
V_152 ) )
continue;
V_83 [ V_61 ] = F_30 ( & V_48 -> V_107 -> V_153 ,
V_149 ) ;
F_5 ( V_65 , L_43 ,
V_136 , V_149 -> V_142 , V_83 [ V_61 ] ) ;
V_136 ++ ;
}
V_133 = F_22 ( V_48 , V_136 , V_83 , V_84 ,
V_7 , V_76 ) ;
F_27 ( V_83 ) ;
}
exit:
if ( V_133 )
F_10 ( L_44 , V_133 ) ;
return V_133 ;
}
static T_3 F_31 ( const T_2 * V_154 , T_1 V_155 )
{
T_2 V_156 [ 5 ] ;
T_3 V_157 ;
T_3 V_133 ;
V_133 = F_32 ( V_154 , V_155 ,
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
int F_33 ( struct V_159 * V_159 ,
struct V_57 * V_58 ,
struct V_75 * V_53 )
{
struct V_132 * V_107 = F_34 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
int V_133 = 0 ;
if ( F_13 ( V_58 ) ) {
V_133 = F_31 ( V_58 -> V_154 ,
V_58 -> V_155 ) ;
if ( V_133 < 0 )
return V_133 ;
V_48 -> V_160 . V_161 = V_133 ;
F_35 ( V_162 , & V_48 -> V_80 ) ;
F_5 ( V_65 , L_46 ) ;
V_133 = F_18 ( V_48 ) ;
if ( V_133 )
return V_133 ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
V_107 -> V_163 . V_164 = F_28 ;
}
V_133 = F_36 ( V_53 , V_165 ,
V_58 -> V_154 , V_58 -> V_155 ) ;
return V_133 ;
}
static T_3
F_37 ( struct V_47 * V_48 , T_4 V_166 , T_1 V_167 )
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
int F_38 ( struct V_159 * V_159 , struct V_177 * V_139 ,
struct V_148 * V_166 ,
unsigned int V_167 , T_5 * V_178 )
{
struct V_132 * V_107 = F_34 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
T_3 V_133 ;
T_4 V_179 ;
V_179 = F_39 ( V_166 -> V_180 ) ;
F_5 ( V_27 , L_49 , V_179 ,
V_167 ) ;
V_133 = F_18 ( V_48 ) ;
if ( V_133 )
goto exit;
V_133 = F_37 ( V_48 , V_179 , V_167 ) ;
if ( V_133 )
goto exit;
memcpy ( & V_48 -> V_181 , V_166 , sizeof( * V_166 ) ) ;
* V_178 = V_48 -> V_176 ;
F_40 ( V_139 , * V_178 , V_166 , V_167 , V_100 ) ;
exit:
return V_133 ;
}
int F_41 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
F_5 ( V_27 , L_50 ) ;
if ( F_42 ( V_170 ,
& V_48 -> V_80 ) ) {
if ( F_42 ( V_187 ,
& V_48 -> V_80 ) ) {
F_35 ( V_188 ,
& V_48 -> V_80 ) ;
F_5 ( V_65 , L_51 ) ;
F_43 ( & V_48 -> V_189 ) ;
}
F_44 ( & V_41 -> V_53 -> V_139 ,
V_48 -> V_176 ,
& V_48 -> V_181 ,
V_100 ) ;
}
return 0 ;
}
void F_45 ( struct V_40 * V_41 )
{
if ( ! V_41 )
return;
F_14 ( V_41 , V_77 , 0 , 0 ) ;
F_41 ( V_41 , NULL , NULL ) ;
}
static T_3 F_46 ( struct V_47 * V_48 , T_4 V_166 )
{
T_3 V_133 ;
T_1 V_190 ;
T_4 * V_191 ;
T_1 V_61 ;
struct V_168 V_169 ;
F_5 ( V_27 , L_50 ) ;
if ( V_166 )
V_190 = V_116 ;
else
V_190 = V_114 ;
V_191 = F_24 ( V_190 * sizeof( * V_191 ) ,
V_100 ) ;
if ( V_191 == NULL ) {
F_10 ( L_52 ) ;
V_133 = - V_101 ;
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
V_103 , V_192 ,
V_76 ) ;
F_27 ( V_191 ) ;
exit:
return V_133 ;
}
static void F_47 ( struct V_193 * V_194 )
{
struct V_160 * V_160 = F_48 ( V_194 , struct V_160 , V_195 ) ;
struct V_47 * V_48 = F_48 ( V_160 ,
struct V_47 ,
V_160 ) ;
T_3 V_133 ;
if ( ! V_160 -> V_196 )
return;
if ( V_160 -> V_197 && V_160 -> V_161 )
V_133 = F_37 ( V_48 , V_160 -> V_161 ,
100 * ( 1 + F_49 () % 3 ) ) ;
else
V_133 = F_46 ( V_48 , V_160 -> V_198 ) ;
if ( V_133 ) {
F_10 ( L_53 , V_133 ) ;
if ( F_19 ( V_199 ,
& V_48 -> V_80 ) )
F_43 ( & V_160 -> V_200 ) ;
}
}
static T_3 F_50 ( struct V_47 * V_48 )
{
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_75 * V_201 ;
unsigned long V_167 ;
T_3 V_202 ;
F_5 ( V_27 , L_50 ) ;
V_201 = V_48 -> V_51 [ V_52 ] . V_53 ;
F_51 ( & V_160 -> V_200 ) ;
F_21 ( V_199 , & V_48 -> V_80 ) ;
V_160 -> V_196 = true ;
V_160 -> V_203 = V_204 ;
V_202 = 0 ;
V_167 = F_52 ( V_205 ) ;
while ( ( V_202 < V_206 ) &&
( V_160 -> V_203 == V_204 ) ) {
V_160 -> V_197 = false ;
F_5 ( V_27 , L_54 ,
V_202 ) ;
F_53 ( & V_160 -> V_195 ) ;
F_54 ( & V_160 -> V_200 , V_167 ) ;
if ( ( V_160 -> V_203 != V_204 ) ||
( ! F_19 ( V_199 ,
& V_48 -> V_80 ) ) )
break;
if ( V_160 -> V_161 ) {
F_5 ( V_27 , L_55 ,
V_160 -> V_161 ) ;
V_160 -> V_197 = true ;
F_53 ( & V_160 -> V_195 ) ;
F_54 ( & V_160 -> V_200 ,
V_167 ) ;
}
if ( ( V_160 -> V_203 != V_204 ) ||
( ! F_19 ( V_199 ,
& V_48 -> V_80 ) ) )
break;
V_202 ++ ;
if ( F_19 ( V_118 , & V_201 -> V_207 ) ||
F_19 ( V_208 , & V_201 -> V_207 ) )
F_55 ( V_209 ) ;
}
F_5 ( V_27 , L_56 ,
V_160 -> V_203 ) ;
V_160 -> V_196 = false ;
F_35 ( V_199 , & V_48 -> V_80 ) ;
return V_160 -> V_203 ;
}
bool F_56 ( struct V_132 * V_107 ,
struct V_210 * V_211 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_168 V_169 ;
T_2 * V_154 ;
T_3 V_133 ;
T_2 V_212 [ V_46 ] ;
if ( ! F_19 ( V_199 , & V_48 -> V_80 ) )
return false ;
if ( V_211 == NULL ) {
F_5 ( V_27 , L_57 ) ;
if ( V_160 -> V_203 == V_204 )
F_43 ( & V_160 -> V_200 ) ;
return true ;
}
V_154 = ( ( T_2 * ) V_211 ) + F_57 ( V_211 -> V_213 ) ;
memset ( V_212 , 0 , sizeof( V_212 ) ) ;
V_133 = F_32 ( V_154 , F_58 ( V_211 -> V_214 ) ,
V_215 ,
V_212 , sizeof( V_212 ) ) ;
if ( V_133 < 0 )
V_133 = F_32 ( V_154 , F_58 ( V_211 -> V_214 ) ,
V_216 ,
V_212 , sizeof( V_212 ) ) ;
if ( ( V_133 >= 0 ) &&
( F_59 ( V_212 , V_160 -> V_217 ) ) ) {
if ( ! V_211 -> V_218 ) {
V_169 . V_73 = F_57 ( V_211 -> V_69 ) ;
V_107 -> V_153 . V_219 ( & V_169 ) ;
V_211 -> V_218 = V_169 . V_171 ;
}
V_160 -> V_203 = V_211 -> V_218 ;
F_5 ( V_27 , L_58 ,
V_160 -> V_217 , V_160 -> V_203 ) ;
F_43 ( & V_160 -> V_200 ) ;
}
return true ;
}
static void
F_60 ( struct V_132 * V_107 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_40 * V_41 = V_107 -> V_163 . V_41 ;
if ( F_19 ( V_220 , & V_48 -> V_80 ) &&
( F_19 ( V_221 , & V_48 -> V_80 ) ||
F_19 ( V_222 , & V_48 -> V_80 ) ) ) {
F_5 ( V_27 , L_59 ) ;
if ( V_48 -> V_223 )
F_61 ( V_107 , V_41 , true , true ) ;
} else if ( F_19 ( V_187 ,
& V_48 -> V_80 ) ) {
F_5 ( V_27 , L_60 ) ;
F_61 ( V_107 , V_41 , true , true ) ;
}
}
static bool
F_62 ( struct V_47 * V_48 , T_2 * V_224 )
{
struct V_132 * V_107 = V_48 -> V_107 ;
struct V_40 * V_41 ;
F_5 ( V_27 , L_50 ) ;
if ( ! F_19 ( V_188 , & V_48 -> V_80 ) ||
! V_48 -> V_225 )
return false ;
F_5 ( V_27 , L_61 ) ;
V_41 = V_48 -> V_51 [ V_76 ] . V_53 -> V_41 ;
if ( memcmp ( V_224 , V_41 -> V_55 , V_46 ) < 0 ) {
F_5 ( V_65 , L_62 ) ;
V_48 -> V_226 = true ;
if ( F_42 ( V_199 ,
& V_48 -> V_80 ) )
F_43 ( & V_48 -> V_160 . V_200 ) ;
if ( F_42 ( V_188 ,
& V_48 -> V_80 ) )
F_60 ( V_107 ) ;
return false ;
}
F_5 ( V_65 , L_63 ) ;
return true ;
}
int F_63 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_177 * V_139 ;
T_1 V_227 = V_183 -> V_228 - sizeof( struct V_229 ) ;
struct V_229 * V_230 = (struct V_229 * ) V_184 ;
T_2 * V_1 = ( T_2 * ) ( V_230 + 1 ) ;
struct V_3 * V_15 ;
struct V_17 * V_18 ;
struct V_168 V_169 ;
struct V_231 * V_232 ;
T_3 V_233 ;
T_4 V_234 ;
T_2 V_7 ;
V_169 . V_73 = F_64 ( V_230 -> V_69 ) ;
V_107 -> V_153 . V_219 ( & V_169 ) ;
F_5 ( V_65 , L_64 , V_41 -> V_53 -> V_235 ) ;
V_234 = ( V_236 & V_237 ) >> 4 ;
if ( ( V_41 -> V_53 -> V_235 & F_65 ( V_234 ) ) == 0 )
return 0 ;
F_4 ( false , V_1 , V_227 ) ;
V_7 = V_238 ;
if ( F_1 ( V_1 , V_227 ) ) {
V_15 = (struct V_3 * ) V_1 ;
V_7 = V_15 -> V_25 ;
if ( ( V_7 == V_26 ) &&
( F_62 ( V_48 , ( T_2 * ) V_183 -> V_239 ) ) ) {
if ( F_19 ( V_199 ,
& V_48 -> V_80 ) &&
( F_59 ( V_160 -> V_217 , V_183 -> V_239 ) ) ) {
V_160 -> V_203 = V_169 . V_171 ;
F_5 ( V_65 , L_65 ,
V_160 -> V_203 ) ;
F_43 ( & V_160 -> V_200 ) ;
}
return 0 ;
}
if ( ( V_7 == V_29 ) ||
( V_7 == V_35 ) )
F_66 ( V_41 , 1 ) ;
if ( V_7 == V_29 ) {
F_5 ( V_27 , L_46 ) ;
F_35 ( V_162 , & V_48 -> V_80 ) ;
}
} else if ( F_3 ( V_1 , V_227 ) ) {
V_18 = (struct V_17 * ) V_1 ;
V_7 = V_18 -> V_7 ;
}
if ( F_19 ( V_188 , & V_48 -> V_80 ) &&
( V_48 -> V_240 == V_7 ) ) {
F_5 ( V_27 , L_66 , V_7 ) ;
F_35 ( V_188 ,
& V_48 -> V_80 ) ;
F_60 ( V_107 ) ;
}
V_232 = F_24 ( F_23 ( struct V_231 , V_241 ) +
V_227 , V_100 ) ;
if ( ! V_232 ) {
F_10 ( L_67 ) ;
return - V_101 ;
}
memcpy ( V_232 -> V_242 , V_41 -> V_55 , V_46 ) ;
F_67 ( V_41 , V_243 , V_232 -> V_110 ,
V_46 ) ;
memcpy ( V_232 -> V_244 , V_183 -> V_239 , V_46 ) ;
V_232 -> V_245 = F_15 ( V_236 ) ;
memcpy ( & V_232 -> V_241 , V_1 , V_227 ) ;
V_227 += F_23 ( struct V_231 , V_241 ) ;
V_233 = F_68 ( V_169 . V_171 ,
V_169 . V_246 == V_247 ?
V_248 :
V_249 ) ;
V_139 = & V_41 -> V_53 -> V_139 ;
F_69 ( V_139 , V_233 , 0 , ( T_2 * ) V_232 , V_227 , 0 ,
V_250 ) ;
F_27 ( V_232 ) ;
return 0 ;
}
int F_70 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
F_5 ( V_65 , L_68 ,
V_183 -> V_251 == V_252 ?
L_69 : L_70 ,
V_183 -> V_80 ) ;
if ( ! F_19 ( V_220 , & V_48 -> V_80 ) )
return 0 ;
if ( V_183 -> V_251 == V_253 ) {
if ( V_183 -> V_80 == V_254 )
F_21 ( V_221 ,
& V_48 -> V_80 ) ;
else {
F_21 ( V_222 , & V_48 -> V_80 ) ;
F_60 ( V_107 ) ;
}
} else {
F_43 ( & V_48 -> V_255 ) ;
}
return 0 ;
}
static T_3 F_71 ( struct V_47 * V_48 ,
struct V_256 * V_257 )
{
struct V_75 * V_53 ;
T_3 V_133 = 0 ;
T_3 V_258 = 0 ;
F_5 ( V_27 , L_50 ) ;
F_51 ( & V_48 -> V_255 ) ;
F_35 ( V_221 , & V_48 -> V_80 ) ;
F_35 ( V_222 , & V_48 -> V_80 ) ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
V_133 = F_16 ( V_53 -> V_41 , L_71 , V_257 ,
sizeof( * V_257 ) ) ;
if ( V_133 ) {
F_10 ( L_72 ) ;
goto exit;
}
V_48 -> V_223 = F_58 ( V_257 -> V_166 ) ;
V_48 -> V_259 = V_260 ;
V_258 = F_54 ( & V_48 -> V_255 ,
F_52 ( V_261 ) ) ;
if ( F_19 ( V_221 , & V_48 -> V_80 ) ) {
F_5 ( V_27 , L_73 ) ;
} else {
V_133 = - V_262 ;
F_5 ( V_27 , L_74 ) ;
}
F_35 ( V_221 , & V_48 -> V_80 ) ;
F_35 ( V_222 , & V_48 -> V_80 ) ;
exit:
return V_133 ;
}
static T_3 F_72 ( struct V_132 * V_107 ,
struct V_256 * V_257 ,
struct V_263 * V_264 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_265 * V_266 ;
struct V_3 * V_15 ;
T_3 V_133 = 0 ;
T_4 V_155 ;
V_266 = & V_257 -> V_266 ;
V_15 = (struct V_3 * ) ( V_266 -> V_184 ) ;
V_264 -> V_267 = true ;
switch ( V_15 -> V_25 ) {
case V_26 :
F_5 ( V_27 , L_75 ) ;
F_21 ( V_162 , & V_48 -> V_80 ) ;
V_264 -> V_268 = 0 ;
V_264 -> V_269 = true ;
V_48 -> V_240 = V_15 -> V_25 + 1 ;
V_48 -> V_225 = true ;
V_257 -> V_270 = F_25 ( V_271 ) ;
break;
case V_28 :
V_48 -> V_240 = V_15 -> V_25 + 1 ;
V_257 -> V_270 = F_25 ( V_271 ) ;
break;
case V_29 :
F_5 ( V_27 , L_46 ) ;
F_35 ( V_162 , & V_48 -> V_80 ) ;
V_264 -> V_268 = 1 ;
V_257 -> V_270 = F_25 ( V_272 ) ;
V_264 -> V_267 = false ;
break;
case V_30 :
V_264 -> V_269 = true ;
V_48 -> V_240 = V_15 -> V_25 + 1 ;
V_257 -> V_270 = F_25 ( V_271 ) ;
break;
case V_31 :
V_257 -> V_270 = F_25 ( V_272 ) ;
V_264 -> V_267 = false ;
break;
case V_32 :
V_264 -> V_269 = true ;
V_48 -> V_240 = V_15 -> V_25 + 1 ;
V_257 -> V_270 = F_25 ( V_273 ) ;
break;
case V_33 :
V_257 -> V_270 = F_25 ( V_272 ) ;
V_264 -> V_267 = false ;
break;
case V_34 :
V_155 = F_57 ( V_266 -> V_274 ) -
F_23 ( struct V_3 , V_275 ) ;
if ( F_32 ( & V_15 -> V_275 [ 0 ] , V_155 ,
V_276 ,
NULL , 0 ) < 0 )
V_264 -> V_269 = true ;
V_264 -> V_268 = 0 ;
V_48 -> V_240 = V_15 -> V_25 + 1 ;
V_257 -> V_270 = F_25 ( V_271 ) ;
break;
case V_35 :
V_48 -> V_240 = V_26 ;
V_257 -> V_270 = F_25 ( V_271 ) ;
V_264 -> V_267 = false ;
break;
default:
F_10 ( L_76 ,
V_15 -> V_25 ) ;
V_133 = - V_102 ;
}
return V_133 ;
}
bool F_73 ( struct V_132 * V_107 ,
struct V_134 * V_277 ,
struct V_256 * V_257 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_40 * V_41 = F_74 ( V_277 ) ;
struct V_265 * V_266 ;
struct V_263 V_264 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
T_4 V_278 ;
bool V_279 = false ;
T_2 V_5 ;
T_2 V_7 ;
T_3 V_280 ;
T_3 V_281 ;
T_6 V_282 ;
V_266 = & V_257 -> V_266 ;
V_278 = F_57 ( V_266 -> V_274 ) ;
F_4 ( true , V_266 -> V_184 , V_278 ) ;
V_257 -> V_270 = F_25 ( V_283 ) ;
V_5 = V_266 -> V_184 [ V_284 ] ;
V_7 = V_266 -> V_184 [ V_285 ] ;
V_48 -> V_240 = V_238 ;
V_48 -> V_225 = false ;
V_264 . V_268 = - 1 ;
V_264 . V_269 = false ;
V_264 . V_267 = false ;
if ( F_1 ( V_266 -> V_184 , V_278 ) ) {
if ( F_72 ( V_107 , V_257 , & V_264 ) ) {
F_10 ( L_77 ) ;
}
} else if ( F_3 ( V_266 -> V_184 ,
V_278 ) ) {
if ( V_7 == V_20 ||
V_7 == V_22 ) {
V_264 . V_269 = true ;
V_48 -> V_240 = V_7 + 1 ;
V_257 -> V_270 =
F_25 ( V_271 ) ;
} else if ( V_7 == V_21 ||
V_7 == V_23 ) {
V_257 -> V_270 =
F_25 ( V_272 ) ;
} else {
F_10 ( L_78 , V_7 ) ;
goto exit;
}
} else if ( F_2 ( V_266 -> V_184 ,
V_278 ) ) {
} else {
F_10 ( L_79 ,
V_5 , V_7 ) ;
return false ;
}
if ( F_19 ( V_208 ,
& V_48 -> V_51 [ V_52 ] . V_53 -> V_207 ) )
F_55 ( 50 ) ;
if ( F_19 ( V_130 , & V_107 -> V_131 ) )
F_75 ( V_107 ) ;
memcpy ( V_160 -> V_217 , V_266 -> V_242 , V_46 ) ;
if ( V_264 . V_268 == 0 )
F_66 ( V_41 , 0 ) ;
if ( V_48 -> V_240 != V_238 ) {
F_21 ( V_188 , & V_48 -> V_80 ) ;
}
V_48 -> V_223 = 0 ;
F_21 ( V_220 , & V_48 -> V_80 ) ;
if ( V_264 . V_269 &&
F_76 ( F_58 ( V_257 -> V_166 ) ) &&
V_48 -> V_51 [ V_76 ] . V_53 -> V_286 . V_287 ) {
V_160 = & V_48 -> V_160 ;
V_160 -> V_198 = F_58 ( V_257 -> V_166 ) ;
if ( F_50 ( V_48 ) ==
V_204 ) {
F_10 ( L_80 ) ;
goto exit;
}
F_61 ( V_107 , V_41 , true , true ) ;
V_257 -> V_166 = F_25 ( V_160 -> V_203 ) ;
}
V_280 = 0 ;
while ( ! V_48 -> V_226 &&
( V_279 == false ) && ( V_280 < V_288 ) ) {
V_279 = ! F_71 ( V_48 , V_257 ) ;
V_280 ++ ;
}
if ( V_279 == false ) {
F_10 ( L_81 , V_280 ) ;
F_35 ( V_162 , & V_48 -> V_80 ) ;
}
exit:
F_35 ( V_220 , & V_48 -> V_80 ) ;
if ( V_279 && V_264 . V_267 && ! V_48 -> V_226 &&
F_19 ( V_188 , & V_48 -> V_80 ) &&
V_48 -> V_223 == V_160 -> V_161 ) {
V_282 = F_77 ( V_260 - V_48 -> V_259 ) ;
if ( F_58 ( V_257 -> V_270 ) > V_282 )
V_281 = F_58 ( V_257 -> V_270 ) -
V_282 ;
else
V_281 = 0 ;
if ( V_281 > 50 ) {
F_21 ( V_187 ,
& V_48 -> V_80 ) ;
F_5 ( V_65 , L_82 ,
F_58 ( V_257 -> V_270 ) ,
V_281 ) ;
V_281 += 100 ;
if ( ! F_37 ( V_48 ,
V_48 -> V_223 ,
V_281 ) ) {
unsigned long V_167 ;
V_281 += 100 ;
V_167 = F_52 ( V_281 ) ;
F_54 ( & V_48 -> V_189 ,
V_167 ) ;
}
F_35 ( V_187 ,
& V_48 -> V_80 ) ;
}
}
if ( V_48 -> V_226 ) {
V_48 -> V_226 = false ;
V_279 = true ;
}
F_35 ( V_188 , & V_48 -> V_80 ) ;
if ( V_264 . V_268 == 1 )
F_66 ( V_41 , 1 ) ;
return V_279 ;
}
T_3 F_78 ( struct V_40 * V_41 ,
const struct V_182 * V_183 ,
void * V_184 )
{
struct V_132 * V_107 = V_41 -> V_185 -> V_186 ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_160 * V_160 = & V_48 -> V_160 ;
struct V_75 * V_53 = V_41 -> V_53 ;
struct V_229 * V_230 = (struct V_229 * ) V_184 ;
T_4 V_69 = F_64 ( V_230 -> V_69 ) ;
struct V_168 V_169 ;
T_2 * V_232 ;
T_1 V_227 ;
T_3 V_233 ;
T_4 V_234 ;
F_5 ( V_65 , L_83 , V_183 -> V_251 ,
V_183 -> V_289 ) ;
V_169 . V_73 = F_64 ( V_230 -> V_69 ) ;
V_107 -> V_153 . V_219 ( & V_169 ) ;
if ( F_19 ( V_199 , & V_48 -> V_80 ) &&
( F_59 ( V_160 -> V_217 , V_183 -> V_239 ) ) ) {
V_160 -> V_203 = V_169 . V_171 ;
F_5 ( V_65 , L_84 ,
V_160 -> V_203 ) ;
F_43 ( & V_160 -> V_200 ) ;
}
if ( V_183 -> V_290 == 0 )
return 0 ;
if ( F_19 ( V_162 , & V_48 -> V_80 ) ) {
F_5 ( V_65 , L_85 ) ;
return 0 ;
}
F_5 ( V_65 , L_86 , V_53 -> V_235 ) ;
V_234 = ( V_291 & V_237 ) >> 4 ;
if ( ( V_53 -> V_235 & F_65 ( V_234 ) ) == 0 )
return 0 ;
V_232 = ( T_2 * ) ( V_230 + 1 ) ;
V_227 = V_183 -> V_228 - sizeof( * V_230 ) ;
V_233 = F_68 ( V_169 . V_171 ,
V_169 . V_246 == V_247 ?
V_248 :
V_249 ) ;
F_69 ( & V_53 -> V_139 , V_233 , 0 , V_232 , V_227 , 0 ,
V_250 ) ;
F_5 ( V_65 , L_87 ,
V_227 , V_183 -> V_228 , V_69 , V_233 ) ;
return 0 ;
}
T_3 F_79 ( struct V_132 * V_107 )
{
struct V_40 * V_50 ;
struct V_40 * V_292 ;
struct V_75 * V_293 ;
struct V_47 * V_48 ;
struct V_294 * V_185 ;
T_3 V_295 ;
T_3 V_133 = 0 ;
V_48 = & V_107 -> V_48 ;
V_48 -> V_107 = V_107 ;
V_185 = V_107 -> V_296 ;
V_50 = V_185 -> V_297 [ 0 ] ;
V_292 = V_185 -> V_297 [ 1 ] ;
V_48 -> V_51 [ V_52 ] . V_53 = V_50 -> V_53 ;
if ( V_292 ) {
V_293 = F_80 ( V_107 , V_298 ,
false ) ;
if ( F_81 ( V_293 ) ) {
F_10 ( L_88 ) ;
V_133 = - V_101 ;
goto exit;
}
V_293 -> V_41 = V_292 ;
V_292 -> V_53 = V_293 ;
V_293 -> V_139 . V_140 = V_292 -> V_277 ;
V_292 -> V_277 -> V_299 = & V_293 -> V_139 ;
F_82 ( V_292 -> V_277 , F_83 ( V_107 -> V_159 ) ) ;
V_48 -> V_51 [ V_76 ] . V_53 = V_293 ;
F_11 ( V_48 , NULL ) ;
memcpy ( V_292 -> V_55 , V_48 -> V_49 , V_46 ) ;
F_6 ( V_50 , V_48 -> V_49 ) ;
V_133 = F_8 ( V_50 , L_29 , 1 ) ;
if ( V_133 < 0 ) {
F_10 ( L_32 ) ;
F_84 ( V_293 ) ;
goto exit;
}
V_133 = F_85 ( V_50 , L_89 , & V_295 ) ;
if ( V_133 < 0 ) {
F_10 ( L_90 ) ;
F_84 ( V_293 ) ;
goto exit;
}
if ( V_292 -> V_295 != V_295 ) {
F_10 ( L_91 ,
V_295 , V_292 -> V_295 ) ;
F_84 ( V_293 ) ;
goto exit;
}
F_86 ( & V_48 -> V_255 ) ;
F_87 ( & V_48 -> V_160 . V_195 , F_47 ) ;
F_86 ( & V_48 -> V_160 . V_200 ) ;
F_86 ( & V_48 -> V_189 ) ;
}
exit:
return V_133 ;
}
void F_88 ( struct V_47 * V_48 )
{
struct V_75 * V_53 ;
V_53 = V_48 -> V_51 [ V_76 ] . V_53 ;
if ( V_53 != NULL ) {
F_45 ( V_53 -> V_41 ) ;
F_17 ( V_48 ) ;
F_84 ( V_53 ) ;
V_48 -> V_51 [ V_76 ] . V_53 = NULL ;
}
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
static void F_89 ( struct V_47 * V_48 ,
T_4 * V_69 )
{
struct V_40 * V_41 ;
T_2 V_55 [ V_46 ] ;
struct V_168 V_169 ;
struct V_210 * V_211 ;
T_2 * V_300 ;
V_41 = V_48 -> V_51 [ V_52 ] . V_53 -> V_41 ;
if ( F_67 ( V_41 , V_243 , V_55 ,
V_46 ) == 0 ) {
V_300 = F_24 ( V_301 , V_100 ) ;
if ( V_300 != NULL ) {
* ( V_302 * ) V_300 = F_25 ( V_301 ) ;
if ( F_67 ( V_41 , V_303 ,
V_300 , V_301 ) == 0 ) {
V_211 = (struct V_210 * ) ( V_300 + 4 ) ;
* V_69 = F_57 ( V_211 -> V_69 ) ;
F_27 ( V_300 ) ;
return;
}
F_27 ( V_300 ) ;
}
}
V_169 . V_171 = V_304 ;
V_169 . V_172 = V_173 ;
V_48 -> V_107 -> V_153 . V_174 ( & V_169 ) ;
* V_69 = V_169 . V_73 ;
}
int F_90 ( struct V_132 * V_107 ,
enum V_305 V_306 )
{
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
struct V_307 V_308 ;
T_3 V_133 ;
T_4 V_69 ;
F_5 ( V_27 , L_50 ) ;
V_53 = V_48 -> V_51 [ V_52 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_92 ) ;
return - V_78 ;
}
F_61 ( V_107 , V_53 -> V_41 , true , true ) ;
V_53 = V_48 -> V_51 [ V_138 ] . V_53 ;
if ( ! V_53 ) {
F_10 ( L_93 ) ;
return - V_78 ;
}
F_66 ( V_53 -> V_41 , 0 ) ;
F_89 ( V_48 , & V_69 ) ;
V_308 . type = F_15 ( ( T_4 ) V_306 ) ;
V_308 . V_73 = F_15 ( V_69 ) ;
memcpy ( V_308 . V_239 , V_48 -> V_56 , sizeof( V_308 . V_239 ) ) ;
F_91 ( V_107 , V_53 ) ;
V_133 = F_9 ( V_53 -> V_41 , L_94 , & V_308 ,
sizeof( V_308 ) ) ;
if ( V_133 ) {
F_10 ( L_95 , V_133 ) ;
F_91 ( V_107 , NULL ) ;
return V_133 ;
}
V_133 = F_92 ( V_107 , V_309 ,
F_52 ( 1500 ) ) ;
F_91 ( V_107 , NULL ) ;
if ( ! V_133 ) {
F_10 ( L_96 ) ;
return - V_262 ;
}
V_133 = F_7 ( V_53 -> V_41 , V_310 ,
V_311 ) ;
return V_133 ;
}
static int F_93 ( struct V_47 * V_48 ,
struct V_40 * V_41 , T_2 V_312 [ V_46 ] ,
enum V_305 V_313 )
{
struct V_307 V_308 ;
int V_133 ;
T_4 V_69 ;
F_89 ( V_48 , & V_69 ) ;
memcpy ( V_308 . V_239 , V_312 , V_46 ) ;
V_308 . type = F_15 ( ( T_4 ) V_313 ) ;
V_308 . V_73 = F_15 ( V_69 ) ;
V_133 = F_9 ( V_41 , L_97 , & V_308 ,
sizeof( V_308 ) ) ;
if ( V_133 )
return V_133 ;
return V_133 ;
}
static int F_94 ( struct V_75 * V_53 )
{
struct V_132 * V_107 = F_95 ( & V_53 -> V_139 ) ;
struct V_134 * V_314 = F_96 ( V_107 ) ;
struct V_40 * V_41 = F_74 ( V_314 ) ;
T_2 * V_239 = V_53 -> V_139 . V_140 -> V_49 ;
return F_9 ( V_41 , L_98 , V_239 , V_46 ) ;
}
static int F_97 ( struct V_75 * V_53 )
{
struct V_132 * V_107 = F_95 ( & V_53 -> V_139 ) ;
struct V_134 * V_314 = F_96 ( V_107 ) ;
struct V_40 * V_41 = F_74 ( V_314 ) ;
T_2 * V_239 = V_53 -> V_139 . V_140 -> V_49 ;
return F_9 ( V_41 , L_99 , V_239 , V_46 ) ;
}
static struct V_177 * F_98 ( struct V_47 * V_48 ,
struct V_159 * V_159 ,
T_2 * V_239 )
{
struct V_75 * V_293 ;
struct V_40 * V_292 ;
struct V_40 * V_50 ;
int V_133 ;
T_1 V_295 ;
if ( V_48 -> V_51 [ V_76 ] . V_53 )
return F_99 ( - V_315 ) ;
V_293 = F_80 ( V_48 -> V_107 , V_298 ,
false ) ;
if ( F_81 ( V_293 ) ) {
F_10 ( L_88 ) ;
return (struct V_177 * ) V_293 ;
}
V_50 = V_48 -> V_51 [ V_52 ] . V_53 -> V_41 ;
F_11 ( V_48 , V_239 ) ;
F_6 ( V_50 , V_48 -> V_49 ) ;
F_91 ( V_48 -> V_107 , V_293 ) ;
V_133 = F_8 ( V_50 , L_29 , 1 ) ;
if ( V_133 < 0 ) {
F_10 ( L_32 ) ;
F_91 ( V_48 -> V_107 , NULL ) ;
goto V_316;
}
V_133 = F_92 ( V_48 -> V_107 , V_317 ,
F_52 ( 1500 ) ) ;
F_91 ( V_48 -> V_107 , NULL ) ;
if ( ! V_133 ) {
F_10 ( L_100 ) ;
V_133 = - V_262 ;
goto V_316;
}
V_292 = V_293 -> V_41 ;
V_48 -> V_51 [ V_76 ] . V_53 = V_293 ;
memcpy ( V_292 -> V_55 , V_48 -> V_49 , V_46 ) ;
memcpy ( & V_293 -> V_139 . V_318 , V_48 -> V_49 , sizeof( V_48 -> V_49 ) ) ;
V_133 = F_85 ( V_50 , L_89 , & V_295 ) ;
if ( V_133 < 0 ) {
F_10 ( L_90 ) ;
goto V_316;
}
F_100 ( V_292 -> V_295 != V_295 ) ;
F_86 ( & V_48 -> V_255 ) ;
F_87 ( & V_48 -> V_160 . V_195 , F_47 ) ;
F_86 ( & V_48 -> V_160 . V_200 ) ;
F_86 ( & V_48 -> V_189 ) ;
return & V_293 -> V_139 ;
V_316:
F_84 ( V_293 ) ;
return F_99 ( V_133 ) ;
}
static void F_101 ( struct V_47 * V_48 ,
struct V_75 * V_53 )
{
F_102 ( & V_53 -> V_139 ) ;
V_48 -> V_51 [ V_76 ] . V_53 = NULL ;
F_84 ( V_53 ) ;
}
struct V_177 * F_103 ( struct V_159 * V_159 , const char * V_319 ,
enum V_320 type , T_1 * V_150 ,
struct V_321 * V_322 )
{
struct V_132 * V_107 = F_34 ( V_159 ) ;
struct V_40 * V_41 = F_74 ( F_96 ( V_107 ) ) ;
struct V_75 * V_53 ;
enum V_305 V_313 ;
enum V_323 V_146 ;
int V_133 ;
if ( F_104 ( V_107 ) )
return F_99 ( - V_324 ) ;
F_5 ( V_65 , L_101 , V_319 , type ) ;
switch ( type ) {
case V_325 :
V_313 = V_326 ;
V_146 = V_327 ;
break;
case V_328 :
V_313 = V_329 ;
V_146 = V_147 ;
break;
case V_298 :
return F_98 ( & V_107 -> V_48 , V_159 ,
V_322 -> V_330 ) ;
default:
return F_99 ( - V_331 ) ;
}
V_53 = F_80 ( V_107 , type , false ) ;
if ( F_81 ( V_53 ) )
return (struct V_177 * ) V_53 ;
F_91 ( V_107 , V_53 ) ;
V_133 = F_93 ( & V_107 -> V_48 , V_41 , V_107 -> V_48 . V_56 ,
V_313 ) ;
if ( V_133 ) {
F_91 ( V_107 , NULL ) ;
goto V_316;
}
V_133 = F_92 ( V_107 , V_317 ,
F_52 ( 1500 ) ) ;
F_91 ( V_107 , NULL ) ;
if ( ! V_133 ) {
F_10 ( L_100 ) ;
V_133 = - V_262 ;
goto V_316;
}
V_41 = V_53 -> V_41 ;
if ( ! V_41 ) {
F_10 ( L_102 ) ;
V_133 = - V_332 ;
goto V_316;
}
strncpy ( V_41 -> V_277 -> V_319 , V_319 , sizeof( V_41 -> V_277 -> V_319 ) - 1 ) ;
V_133 = F_105 ( V_41 , true ) ;
if ( V_133 ) {
F_10 ( L_103 ) ;
goto V_316;
}
V_107 -> V_48 . V_51 [ V_138 ] . V_53 = V_53 ;
F_8 ( V_41 , L_104 , 1 ) ;
if ( V_313 == V_329 ) {
F_7 ( V_41 , V_310 ,
V_311 ) ;
}
return & V_41 -> V_53 -> V_139 ;
V_316:
F_84 ( V_53 ) ;
return F_99 ( V_133 ) ;
}
int F_106 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_107 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
unsigned long V_333 = F_52 ( 1500 ) ;
bool V_334 = false ;
int V_133 ;
F_5 ( V_27 , L_105 ) ;
V_53 = F_48 ( V_139 , struct V_75 , V_139 ) ;
switch ( V_53 -> V_139 . V_313 ) {
case V_325 :
if ( F_19 ( V_335 , & V_53 -> V_207 ) )
V_334 = true ;
break;
case V_328 :
if ( ! F_94 ( V_53 ) )
V_334 = true ;
break;
case V_298 :
F_101 ( V_48 , V_53 ) ;
return 0 ;
default:
return - V_336 ;
break;
}
F_35 ( V_162 , & V_48 -> V_80 ) ;
F_5 ( V_65 , L_46 ) ;
if ( V_334 )
F_54 ( & V_107 -> V_337 ,
F_52 ( 500 ) ) ;
F_108 ( V_53 ) ;
F_91 ( V_107 , V_53 ) ;
V_133 = F_97 ( V_53 ) ;
if ( ! V_133 ) {
V_133 = F_92 ( V_107 , V_338 ,
V_333 ) ;
if ( ! V_133 )
V_133 = - V_262 ;
else
V_133 = 0 ;
}
F_91 ( V_107 , NULL ) ;
V_48 -> V_51 [ V_138 ] . V_53 = NULL ;
return V_133 ;
}
int F_109 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_34 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
int V_133 ;
V_53 = F_48 ( V_139 , struct V_75 , V_139 ) ;
F_110 ( & V_107 -> V_339 ) ;
V_133 = F_18 ( V_48 ) ;
if ( ! V_133 )
F_21 ( V_340 , & V_53 -> V_207 ) ;
F_111 ( & V_107 -> V_339 ) ;
return V_133 ;
}
void F_112 ( struct V_159 * V_159 , struct V_177 * V_139 )
{
struct V_132 * V_107 = F_34 ( V_159 ) ;
struct V_47 * V_48 = & V_107 -> V_48 ;
struct V_75 * V_53 ;
V_53 = F_48 ( V_139 , struct V_75 , V_139 ) ;
F_110 ( & V_107 -> V_339 ) ;
( void ) F_17 ( V_48 ) ;
F_75 ( V_107 ) ;
F_35 ( V_340 , & V_53 -> V_207 ) ;
F_111 ( & V_107 -> V_339 ) ;
}
