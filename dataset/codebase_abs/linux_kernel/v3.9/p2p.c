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
static T_2 F_6 ( T_2 V_40 )
{
T_2 V_41 ;
V_41 = V_40 & V_42 ;
if ( V_40 <= V_43 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
V_41 |= V_46 ;
V_41 |= V_47 ;
return V_41 ;
}
static int F_7 ( struct V_48 * V_49 , T_3 * V_50 )
{
T_4 V_51 = 0 ;
F_8 ( V_49 , L_23 , 1 ) ;
V_51 = F_9 ( V_49 , L_24 , V_50 ,
V_52 ) ;
if ( V_51 )
F_10 ( L_25 , V_51 ) ;
return V_51 ;
}
static void F_11 ( struct V_53 * V_54 )
{
struct V_48 * V_55 = V_54 -> V_56 [ V_57 ] . V_58 -> V_49 ;
struct V_48 * V_59 = V_54 -> V_56 [ V_60 ] . V_58 -> V_49 ;
memcpy ( V_54 -> V_61 , V_55 -> V_62 , V_52 ) ;
V_54 -> V_61 [ 0 ] |= 0x02 ;
memcpy ( V_59 -> V_62 , V_54 -> V_61 , V_52 ) ;
memcpy ( V_54 -> V_63 , V_54 -> V_61 , V_52 ) ;
V_54 -> V_63 [ 4 ] ^= 0x80 ;
}
static bool F_12 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_67 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_65 -> V_69 ; V_68 ++ ) {
if ( V_67 [ V_68 ] . V_70 != V_71 )
continue;
F_5 ( V_72 , L_26 , V_67 [ V_68 ] . V_73 ) ;
if ( ! memcmp ( V_74 , V_67 [ V_68 ] . V_73 ,
V_71 ) )
return true ;
}
return false ;
}
static T_4 F_13 ( struct V_48 * V_49 , T_3 V_75 ,
T_2 V_41 , T_2 V_76 )
{
struct V_77 V_78 ;
T_4 V_51 = 0 ;
F_5 ( V_27 , L_27 ) ;
V_78 . V_75 = V_75 ;
V_78 . V_79 = F_14 ( V_41 ) ;
V_78 . V_80 = F_14 ( V_76 ) ;
V_51 = F_15 ( V_49 , L_28 , & V_78 ,
sizeof( V_78 ) ) ;
return V_51 ;
}
static T_4 F_16 ( struct V_53 * V_54 )
{
struct V_81 * V_58 ;
F_5 ( V_27 , L_27 ) ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
( void ) F_13 ( V_58 -> V_49 , V_82 , 0 , 0 ) ;
V_58 = V_54 -> V_56 [ V_57 ] . V_58 ;
( void ) F_8 ( V_58 -> V_49 , L_29 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_53 * V_54 )
{
struct V_81 * V_58 ;
T_4 V_51 = 0 ;
F_5 ( V_27 , L_27 ) ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
if ( ! V_58 ) {
F_10 ( L_30 ) ;
V_51 = - V_83 ;
goto exit;
}
if ( F_18 ( V_84 , & V_54 -> V_85 ) ) {
F_5 ( V_72 , L_31 ) ;
goto exit;
}
V_58 = V_54 -> V_56 [ V_57 ] . V_58 ;
V_51 = F_8 ( V_58 -> V_49 , L_29 , 1 ) ;
if ( V_51 < 0 ) {
F_10 ( L_32 ) ;
goto exit;
}
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
V_51 = F_13 ( V_58 -> V_49 , V_82 , 0 , 0 ) ;
if ( V_51 < 0 ) {
F_10 ( L_33 ) ;
goto exit;
}
V_51 = F_19 ( V_58 -> V_49 , L_34 , V_86 ) ;
if ( V_51 < 0 ) {
F_10 ( L_35 , V_51 ) ;
goto exit;
}
F_20 ( V_84 , & V_54 -> V_85 ) ;
exit:
return V_51 ;
}
static T_4 F_21 ( struct V_53 * V_54 , T_1 V_87 ,
T_2 V_88 [] , T_4 V_89 , T_2 V_7 ,
enum V_90 V_91 )
{
T_4 V_51 = 0 ;
T_4 V_92 = F_22 ( struct V_93 ,
V_94 . V_95 . V_96 ) ;
T_4 V_97 ;
T_4 V_98 ;
T_1 V_68 ;
T_3 * V_99 ;
struct V_81 * V_58 ;
struct V_93 * V_100 ;
struct V_101 * V_102 ;
struct V_103 V_73 ;
V_92 += V_87 * sizeof( V_104 ) ;
V_99 = F_23 ( V_92 , V_105 ) ;
if ( ! V_99 )
return - V_106 ;
V_58 = V_54 -> V_56 [ V_91 ] . V_58 ;
if ( V_58 == NULL ) {
F_10 ( L_36 , V_91 ) ;
V_51 = - V_107 ;
goto exit;
}
switch ( V_89 ) {
case V_108 :
V_73 . V_109 = 0 ;
memset ( V_73 . V_110 , 0 , sizeof( V_73 . V_110 ) ) ;
break;
case V_82 :
V_73 . V_109 = V_71 ;
memcpy ( V_73 . V_110 , V_74 , V_73 . V_109 ) ;
break;
default:
F_10 ( L_37 , V_89 ) ;
V_51 = - V_107 ;
goto exit;
}
F_13 ( V_58 -> V_49 , V_89 , 0 , 0 ) ;
V_100 = (struct V_93 * ) V_99 ;
V_100 -> type = 'E' ;
V_102 = & V_100 -> V_94 . V_95 ;
V_102 -> V_91 = V_111 ;
if ( V_54 -> V_112 -> V_113 )
V_102 -> V_114 = 0 ;
else
V_102 -> V_114 = 1 ;
memset ( & V_102 -> V_115 , 0xFF , V_52 ) ;
if ( V_73 . V_109 )
memcpy ( V_102 -> V_116 . V_110 , V_73 . V_110 , V_73 . V_109 ) ;
V_102 -> V_116 . V_109 = F_24 ( V_73 . V_109 ) ;
V_102 -> V_117 = F_24 ( V_118 ) ;
if ( V_87 == V_119 || V_87 == ( V_119 + 1 ) )
V_98 = V_120 ;
else if ( V_87 == V_121 )
V_98 = V_122 ;
else if ( F_25 ( V_54 -> V_112 , V_123 ) )
V_98 = - 1 ;
else
V_98 = V_124 ;
if ( V_87 == 1 ) {
V_98 = V_125 ;
V_97 = V_98 / V_126 ;
} else {
V_97 = V_98 / V_127 ;
}
if ( V_97 <= 0 )
V_97 = 1 ;
F_5 ( V_72 , L_38 , V_97 , V_98 ) ;
V_102 -> V_128 = F_24 ( V_98 ) ;
V_102 -> V_97 = F_24 ( V_97 ) ;
V_102 -> V_129 = F_24 ( - 1 ) ;
V_102 -> V_130 = F_24 ( V_87 &
V_131 ) ;
for ( V_68 = 0 ; V_68 < V_87 ; V_68 ++ )
V_102 -> V_96 [ V_68 ] = F_14 ( V_88 [ V_68 ] ) ;
V_100 -> V_94 . V_132 = F_24 ( V_133 ) ;
V_100 -> V_94 . V_7 = F_14 ( V_7 ) ;
V_100 -> V_94 . V_134 = F_14 ( 0x1234 ) ;
V_51 = F_15 ( V_58 -> V_49 , L_39 , V_99 , V_92 ) ;
if ( ! V_51 )
F_20 ( V_135 , & V_54 -> V_112 -> V_136 ) ;
exit:
F_26 ( V_99 ) ;
return V_51 ;
}
static T_4 F_27 ( struct V_137 * V_112 ,
struct V_138 * V_139 ,
struct V_64 * V_65 ,
T_2 V_7 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
T_4 V_140 = 0 ;
T_4 V_89 = V_82 ;
struct V_81 * V_58 ;
struct V_138 * V_141 = NULL ;
int V_68 , V_142 = 0 ;
T_2 * V_88 ;
F_5 ( V_27 , L_27 ) ;
if ( ! V_65 ) {
V_140 = - V_107 ;
goto exit;
}
if ( V_65 -> V_143 ) {
V_88 = F_28 ( V_65 -> V_143 , sizeof( * V_88 ) ,
V_105 ) ;
if ( ! V_88 ) {
V_140 = - V_106 ;
goto exit;
}
V_58 = V_54 -> V_56 [ V_144 ] . V_58 ;
if ( V_58 )
V_141 = V_58 -> V_145 . V_146 ;
if ( V_65 -> V_143 == 3 &&
V_65 -> V_147 [ 0 ] -> V_148 == V_149 &&
V_65 -> V_147 [ 1 ] -> V_148 == V_150 &&
V_65 -> V_147 [ 2 ] -> V_148 == V_151 ) {
V_89 = V_108 ;
F_5 ( V_72 , L_40 ) ;
} else if ( V_141 != NULL && V_58 -> V_152 == V_153 ) {
F_5 ( V_72 , L_41 ) ;
V_89 = V_108 ;
} else {
F_5 ( V_72 , L_42 ) ;
}
for ( V_68 = 0 ; V_68 < V_65 -> V_143 ; V_68 ++ ) {
struct V_154 * V_155 = V_65 -> V_147 [ V_68 ] ;
if ( V_155 -> V_156 & ( V_157 |
V_158 ) )
continue;
V_88 [ V_68 ] = F_29 ( V_155 ) ;
F_5 ( V_72 , L_43 ,
V_142 , V_155 -> V_148 , V_88 [ V_68 ] ) ;
V_142 ++ ;
}
V_140 = F_21 ( V_54 , V_142 , V_88 , V_89 ,
V_7 , V_60 ) ;
}
exit:
if ( V_140 )
F_10 ( L_44 , V_140 ) ;
return V_140 ;
}
static T_4 F_30 ( const T_3 * V_159 , T_1 V_160 )
{
T_3 V_161 [ 5 ] ;
T_4 V_162 ;
T_4 V_140 ;
V_140 = F_31 ( V_159 , V_160 ,
V_163 ,
V_161 , sizeof( V_161 ) ) ;
if ( V_140 < 0 )
return V_140 ;
V_162 = ( T_4 ) V_161 [ 3 + 1 ] ;
if ( V_162 == V_149 ||
V_162 == V_150 ||
V_162 == V_151 ) {
F_5 ( V_72 , L_45 , V_162 ) ;
return V_162 ;
}
return - V_83 ;
}
int F_32 ( struct V_164 * V_164 ,
struct V_64 * V_65 ,
struct V_81 * V_58 )
{
struct V_137 * V_112 = F_33 ( V_164 ) ;
struct V_53 * V_54 = & V_112 -> V_54 ;
int V_140 = 0 ;
if ( F_12 ( V_65 ) ) {
V_140 = F_30 ( V_65 -> V_159 ,
V_65 -> V_160 ) ;
if ( V_140 < 0 )
return V_140 ;
V_54 -> V_165 . V_166 = V_140 ;
F_34 ( V_167 , & V_54 -> V_85 ) ;
F_5 ( V_72 , L_46 ) ;
V_140 = F_17 ( V_54 ) ;
if ( V_140 )
return V_140 ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
V_112 -> V_168 . V_169 = F_27 ;
}
V_140 = F_35 ( V_58 , V_170 ,
V_65 -> V_159 , V_65 -> V_160 ) ;
return V_140 ;
}
static T_4
F_36 ( struct V_53 * V_54 , T_2 V_40 , T_1 V_171 )
{
struct V_81 * V_58 ;
T_4 V_140 = 0 ;
T_2 V_41 ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
if ( ! V_58 ) {
F_10 ( L_47 ) ;
V_140 = - V_83 ;
goto exit;
}
if ( F_18 ( V_172 , & V_54 -> V_85 ) ) {
F_10 ( L_48 ) ;
goto exit;
}
V_41 = F_6 ( V_40 ) ;
V_140 = F_13 ( V_58 -> V_49 , V_173 ,
V_41 , ( T_2 ) V_171 ) ;
if ( ! V_140 ) {
F_20 ( V_172 , & V_54 -> V_85 ) ;
V_54 -> V_174 ++ ;
}
exit:
return V_140 ;
}
int F_37 ( struct V_164 * V_164 , struct V_175 * V_145 ,
struct V_154 * V_40 ,
unsigned int V_171 , T_5 * V_176 )
{
struct V_137 * V_112 = F_33 ( V_164 ) ;
struct V_53 * V_54 = & V_112 -> V_54 ;
T_4 V_140 ;
T_2 V_177 ;
V_177 = F_38 ( V_40 -> V_178 ) ;
F_5 ( V_27 , L_49 , V_177 ,
V_171 ) ;
V_140 = F_17 ( V_54 ) ;
if ( V_140 )
goto exit;
V_140 = F_36 ( V_54 , V_177 , V_171 ) ;
if ( V_140 )
goto exit;
memcpy ( & V_54 -> V_179 , V_40 , sizeof( * V_40 ) ) ;
* V_176 = V_54 -> V_174 ;
F_39 ( V_145 , * V_176 , V_40 , V_171 , V_105 ) ;
exit:
return V_140 ;
}
int F_40 ( struct V_48 * V_49 ,
const struct V_180 * V_181 ,
void * V_182 )
{
struct V_137 * V_112 = V_49 -> V_183 -> V_184 ;
struct V_53 * V_54 = & V_112 -> V_54 ;
F_5 ( V_27 , L_50 ) ;
if ( F_41 ( V_172 ,
& V_54 -> V_85 ) ) {
if ( F_41 ( V_185 ,
& V_54 -> V_85 ) ) {
F_34 ( V_186 ,
& V_54 -> V_85 ) ;
F_5 ( V_72 , L_51 ) ;
F_42 ( & V_54 -> V_187 ) ;
}
F_43 ( & V_49 -> V_58 -> V_145 ,
V_54 -> V_174 ,
& V_54 -> V_179 ,
V_105 ) ;
}
return 0 ;
}
void F_44 ( struct V_48 * V_49 )
{
if ( ! V_49 )
return;
F_13 ( V_49 , V_82 , 0 , 0 ) ;
F_40 ( V_49 , NULL , NULL ) ;
}
static T_4 F_45 ( struct V_53 * V_54 , T_2 V_40 )
{
T_4 V_140 ;
T_1 V_188 ;
T_2 * V_189 ;
T_1 V_68 ;
F_5 ( V_27 , L_50 ) ;
if ( V_40 )
V_188 = V_121 ;
else
V_188 = V_119 ;
V_189 = F_23 ( V_188 * sizeof( * V_189 ) ,
V_105 ) ;
if ( V_189 == NULL ) {
F_10 ( L_52 ) ;
V_140 = - V_106 ;
goto exit;
}
if ( V_40 ) {
for ( V_68 = 0 ; V_68 < V_188 ; V_68 ++ )
V_189 [ V_68 ] =
F_6 ( V_40 ) ;
} else {
V_189 [ 0 ] = F_6 ( V_149 ) ;
V_189 [ 1 ] = F_6 ( V_150 ) ;
V_189 [ 2 ] = F_6 ( V_151 ) ;
}
V_140 = F_21 ( V_54 , V_188 , V_189 ,
V_108 , V_190 ,
V_60 ) ;
F_26 ( V_189 ) ;
exit:
return V_140 ;
}
static void F_46 ( struct V_191 * V_192 )
{
struct V_165 * V_165 = F_47 ( V_192 , struct V_165 , V_193 ) ;
struct V_53 * V_54 = F_47 ( V_165 ,
struct V_53 ,
V_165 ) ;
T_4 V_140 ;
if ( ! V_165 -> V_194 )
return;
if ( V_165 -> V_195 && V_165 -> V_166 )
V_140 = F_36 ( V_54 , V_165 -> V_166 ,
100 * ( 1 + ( F_48 () % 3 ) ) ) ;
else
V_140 = F_45 ( V_54 , V_165 -> V_196 ) ;
if ( V_140 ) {
F_10 ( L_53 , V_140 ) ;
if ( F_18 ( V_197 ,
& V_54 -> V_85 ) )
F_42 ( & V_165 -> V_198 ) ;
}
}
static T_4 F_49 ( struct V_53 * V_54 )
{
struct V_165 * V_165 = & V_54 -> V_165 ;
struct V_81 * V_199 ;
unsigned long V_171 ;
T_4 V_200 ;
F_5 ( V_27 , L_50 ) ;
V_199 = V_54 -> V_56 [ V_57 ] . V_58 ;
F_50 ( V_165 -> V_198 ) ;
F_20 ( V_197 , & V_54 -> V_85 ) ;
V_165 -> V_194 = true ;
V_165 -> V_201 = V_202 ;
V_200 = 0 ;
V_171 = F_51 ( V_203 ) ;
while ( ( V_200 < V_204 ) &&
( V_165 -> V_201 == V_202 ) ) {
V_165 -> V_195 = false ;
F_5 ( V_27 , L_54 ,
V_200 ) ;
F_52 ( & V_165 -> V_193 ) ;
F_53 ( & V_165 -> V_198 , V_171 ) ;
if ( ( V_165 -> V_201 != V_202 ) ||
( ! F_18 ( V_197 ,
& V_54 -> V_85 ) ) )
break;
if ( V_165 -> V_166 ) {
F_5 ( V_27 , L_55 ,
V_165 -> V_166 ) ;
V_165 -> V_195 = true ;
F_52 ( & V_165 -> V_193 ) ;
F_53 ( & V_165 -> V_198 ,
V_171 ) ;
}
if ( ( V_165 -> V_201 != V_202 ) ||
( ! F_18 ( V_197 ,
& V_54 -> V_85 ) ) )
break;
V_200 ++ ;
if ( F_18 ( V_123 , & V_199 -> V_205 ) ||
F_18 ( V_206 , & V_199 -> V_205 ) )
F_54 ( V_207 ) ;
}
F_5 ( V_27 , L_56 ,
V_165 -> V_201 ) ;
V_165 -> V_194 = false ;
F_34 ( V_197 , & V_54 -> V_85 ) ;
return V_165 -> V_201 ;
}
bool F_55 ( struct V_137 * V_112 ,
struct V_208 * V_209 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_165 * V_165 = & V_54 -> V_165 ;
T_3 * V_159 ;
T_4 V_140 ;
T_3 V_210 [ V_52 ] ;
if ( ! F_18 ( V_197 , & V_54 -> V_85 ) )
return false ;
if ( V_209 == NULL ) {
F_5 ( V_27 , L_57 ) ;
if ( V_165 -> V_201 == V_202 )
F_42 ( & V_165 -> V_198 ) ;
return true ;
}
V_159 = ( ( T_3 * ) V_209 ) + F_56 ( V_209 -> V_211 ) ;
memset ( V_210 , 0 , sizeof( V_210 ) ) ;
V_140 = F_31 ( V_159 , F_57 ( V_209 -> V_212 ) ,
V_213 ,
V_210 , sizeof( V_210 ) ) ;
if ( V_140 < 0 )
V_140 = F_31 ( V_159 , F_57 ( V_209 -> V_212 ) ,
V_214 ,
V_210 , sizeof( V_210 ) ) ;
if ( ( V_140 >= 0 ) &&
( ! memcmp ( V_210 , V_165 -> V_215 , V_52 ) ) ) {
V_165 -> V_201 = V_209 -> V_216 ? V_209 -> V_216 :
F_58 ( F_56 ( V_209 -> V_41 ) ) ;
F_5 ( V_27 , L_58 ,
V_165 -> V_215 , V_165 -> V_201 ) ;
F_42 ( & V_165 -> V_198 ) ;
}
return true ;
}
static void
F_59 ( struct V_137 * V_112 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_138 * V_139 = V_112 -> V_168 . V_139 ;
if ( F_18 ( V_217 , & V_54 -> V_85 ) &&
( F_18 ( V_218 , & V_54 -> V_85 ) ||
F_18 ( V_219 , & V_54 -> V_85 ) ) ) {
F_5 ( V_27 , L_59 ) ;
if ( V_54 -> V_220 )
F_60 ( V_112 , V_139 , true , true ) ;
} else if ( F_18 ( V_185 ,
& V_54 -> V_85 ) ) {
F_5 ( V_27 , L_60 ) ;
F_60 ( V_112 , V_139 , true , true ) ;
}
}
static bool
F_61 ( struct V_53 * V_54 , T_3 * V_221 )
{
struct V_137 * V_112 = V_54 -> V_112 ;
struct V_48 * V_49 ;
F_5 ( V_27 , L_50 ) ;
if ( ! F_18 ( V_186 , & V_54 -> V_85 ) ||
! V_54 -> V_222 )
return false ;
F_5 ( V_27 , L_61 ) ;
V_49 = V_54 -> V_56 [ V_60 ] . V_58 -> V_49 ;
if ( memcmp ( V_221 , V_49 -> V_62 , V_52 ) < 0 ) {
F_5 ( V_72 , L_62 ) ;
V_54 -> V_223 = true ;
if ( F_41 ( V_197 ,
& V_54 -> V_85 ) )
F_42 ( & V_54 -> V_165 . V_198 ) ;
if ( F_41 ( V_186 ,
& V_54 -> V_85 ) )
F_59 ( V_112 ) ;
return false ;
}
F_5 ( V_72 , L_63 ) ;
return true ;
}
int F_62 ( struct V_48 * V_49 ,
const struct V_180 * V_181 ,
void * V_182 )
{
struct V_137 * V_112 = V_49 -> V_183 -> V_184 ;
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_165 * V_165 = & V_54 -> V_165 ;
struct V_175 * V_145 ;
T_1 V_224 = V_181 -> V_225 - sizeof( struct V_226 ) ;
struct V_226 * V_227 = (struct V_226 * ) V_182 ;
T_3 * V_1 = ( T_3 * ) ( V_227 + 1 ) ;
struct V_3 * V_15 ;
struct V_17 * V_18 ;
T_2 V_41 = F_63 ( V_227 -> V_41 ) ;
struct V_228 * V_229 ;
T_4 V_230 ;
T_2 V_231 ;
T_3 V_7 ;
F_5 ( V_72 , L_64 , V_49 -> V_58 -> V_232 ) ;
V_231 = ( V_233 & V_234 ) >> 4 ;
if ( ( V_49 -> V_58 -> V_232 & F_64 ( V_231 ) ) == 0 )
return 0 ;
F_4 ( false , V_1 , V_224 ) ;
V_7 = V_235 ;
if ( F_1 ( V_1 , V_224 ) ) {
V_15 = (struct V_3 * ) V_1 ;
V_7 = V_15 -> V_25 ;
if ( ( V_7 == V_26 ) &&
( F_61 ( V_54 , ( T_3 * ) V_181 -> V_236 ) ) ) {
if ( F_18 ( V_197 ,
& V_54 -> V_85 ) &&
( memcmp ( V_165 -> V_215 , V_181 -> V_236 ,
V_52 ) == 0 ) ) {
V_165 -> V_201 = F_58 ( V_41 ) ;
F_5 ( V_72 , L_65 ,
V_165 -> V_201 ) ;
F_42 ( & V_165 -> V_198 ) ;
}
return 0 ;
}
if ( ( V_7 == V_29 ) ||
( V_7 == V_35 ) )
F_65 ( V_49 -> V_139 , 1 ) ;
if ( V_7 == V_29 ) {
F_5 ( V_27 , L_46 ) ;
F_34 ( V_167 , & V_54 -> V_85 ) ;
}
} else if ( F_3 ( V_1 , V_224 ) ) {
V_18 = (struct V_17 * ) V_1 ;
V_7 = V_18 -> V_7 ;
}
if ( F_18 ( V_186 , & V_54 -> V_85 ) &&
( V_54 -> V_237 == V_7 ) ) {
F_5 ( V_27 , L_66 , V_7 ) ;
F_34 ( V_186 ,
& V_54 -> V_85 ) ;
F_59 ( V_112 ) ;
}
V_229 = F_23 ( F_22 ( struct V_228 , V_238 ) +
V_224 , V_105 ) ;
if ( ! V_229 ) {
F_10 ( L_67 ) ;
return - V_106 ;
}
memcpy ( V_229 -> V_239 , V_49 -> V_62 , V_52 ) ;
F_66 ( V_49 , V_240 , V_229 -> V_115 ,
V_52 ) ;
memcpy ( V_229 -> V_241 , V_181 -> V_236 , V_52 ) ;
V_229 -> V_242 = F_14 ( V_233 ) ;
memcpy ( & V_229 -> V_238 , V_1 , V_224 ) ;
V_224 += F_22 ( struct V_228 , V_238 ) ;
V_230 = F_67 ( F_58 ( V_41 ) ,
F_68 ( V_41 ) ?
V_243 :
V_244 ) ;
V_145 = V_49 -> V_139 -> V_245 ;
F_69 ( V_145 , V_230 , 0 , ( T_3 * ) V_229 , V_224 ,
V_246 ) ;
F_26 ( V_229 ) ;
return 0 ;
}
int F_70 ( struct V_48 * V_49 ,
const struct V_180 * V_181 ,
void * V_182 )
{
struct V_137 * V_112 = V_49 -> V_183 -> V_184 ;
struct V_53 * V_54 = & V_112 -> V_54 ;
F_5 ( V_72 , L_68 ,
V_181 -> V_247 == V_248 ?
L_69 : L_70 ,
V_181 -> V_85 ) ;
if ( ! F_18 ( V_217 , & V_54 -> V_85 ) )
return 0 ;
if ( V_181 -> V_247 == V_249 ) {
if ( V_181 -> V_85 == V_250 )
F_20 ( V_218 ,
& V_54 -> V_85 ) ;
else {
F_20 ( V_219 , & V_54 -> V_85 ) ;
F_59 ( V_112 ) ;
}
} else {
F_42 ( & V_54 -> V_251 ) ;
}
return 0 ;
}
static T_4 F_71 ( struct V_53 * V_54 ,
struct V_252 * V_253 )
{
struct V_81 * V_58 ;
T_4 V_140 = 0 ;
T_4 V_254 = 0 ;
F_5 ( V_27 , L_50 ) ;
F_50 ( V_54 -> V_251 ) ;
F_34 ( V_218 , & V_54 -> V_85 ) ;
F_34 ( V_219 , & V_54 -> V_85 ) ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
V_140 = F_15 ( V_58 -> V_49 , L_71 , V_253 ,
sizeof( * V_253 ) ) ;
if ( V_140 ) {
F_10 ( L_72 ) ;
goto exit;
}
V_54 -> V_220 = F_57 ( V_253 -> V_40 ) ;
V_54 -> V_255 = V_256 ;
V_254 = F_53 ( & V_54 -> V_251 ,
F_51 ( V_257 ) ) ;
if ( F_18 ( V_218 , & V_54 -> V_85 ) ) {
F_5 ( V_27 , L_73 ) ;
} else {
V_140 = - V_258 ;
F_5 ( V_27 , L_74 ) ;
}
F_34 ( V_218 , & V_54 -> V_85 ) ;
F_34 ( V_219 , & V_54 -> V_85 ) ;
exit:
return V_140 ;
}
static T_4 F_72 ( struct V_137 * V_112 ,
struct V_252 * V_253 ,
struct V_259 * V_260 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_261 * V_262 ;
struct V_3 * V_15 ;
T_4 V_140 = 0 ;
T_2 V_160 ;
V_262 = & V_253 -> V_262 ;
V_15 = (struct V_3 * ) ( V_262 -> V_182 ) ;
V_260 -> V_263 = true ;
switch ( V_15 -> V_25 ) {
case V_26 :
F_5 ( V_27 , L_75 ) ;
F_20 ( V_167 , & V_54 -> V_85 ) ;
V_260 -> V_264 = 0 ;
V_260 -> V_265 = true ;
V_54 -> V_237 = V_15 -> V_25 + 1 ;
V_54 -> V_222 = true ;
V_253 -> V_266 = F_24 ( V_267 ) ;
break;
case V_28 :
V_54 -> V_237 = V_15 -> V_25 + 1 ;
V_253 -> V_266 = F_24 ( V_267 ) ;
break;
case V_29 :
F_5 ( V_27 , L_46 ) ;
F_34 ( V_167 , & V_54 -> V_85 ) ;
V_260 -> V_264 = 1 ;
V_253 -> V_266 = F_24 ( V_268 ) ;
V_260 -> V_263 = false ;
break;
case V_30 :
V_260 -> V_265 = true ;
V_54 -> V_237 = V_15 -> V_25 + 1 ;
V_253 -> V_266 = F_24 ( V_267 ) ;
break;
case V_31 :
V_253 -> V_266 = F_24 ( V_268 ) ;
V_260 -> V_263 = false ;
break;
case V_32 :
V_260 -> V_265 = true ;
V_54 -> V_237 = V_15 -> V_25 + 1 ;
V_253 -> V_266 = F_24 ( V_269 ) ;
break;
case V_33 :
V_253 -> V_266 = F_24 ( V_268 ) ;
V_260 -> V_263 = false ;
break;
case V_34 :
V_160 = F_56 ( V_262 -> V_270 ) -
F_22 ( struct V_3 , V_271 ) ;
if ( F_31 ( & V_15 -> V_271 [ 0 ] , V_160 ,
V_272 ,
NULL , 0 ) < 0 )
V_260 -> V_265 = true ;
V_260 -> V_264 = 0 ;
V_54 -> V_237 = V_15 -> V_25 + 1 ;
V_253 -> V_266 = F_24 ( V_267 ) ;
break;
case V_35 :
V_54 -> V_237 = V_26 ;
V_253 -> V_266 = F_24 ( V_267 ) ;
V_260 -> V_263 = false ;
break;
default:
F_10 ( L_76 ,
V_15 -> V_25 ) ;
V_140 = - V_107 ;
}
return V_140 ;
}
bool F_73 ( struct V_137 * V_112 ,
struct V_138 * V_139 ,
struct V_252 * V_253 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_261 * V_262 ;
struct V_259 V_260 ;
struct V_165 * V_165 = & V_54 -> V_165 ;
T_2 V_273 ;
bool V_274 = false ;
T_3 V_5 ;
T_3 V_7 ;
T_4 V_275 ;
T_4 V_276 ;
T_6 V_277 ;
V_262 = & V_253 -> V_262 ;
V_273 = F_56 ( V_262 -> V_270 ) ;
F_4 ( true , V_262 -> V_182 , V_273 ) ;
V_253 -> V_266 = F_24 ( V_278 ) ;
V_5 = V_262 -> V_182 [ V_279 ] ;
V_7 = V_262 -> V_182 [ V_280 ] ;
V_54 -> V_237 = V_235 ;
V_54 -> V_222 = false ;
V_260 . V_264 = - 1 ;
V_260 . V_265 = false ;
V_260 . V_263 = false ;
if ( F_1 ( V_262 -> V_182 , V_273 ) ) {
if ( F_72 ( V_112 , V_253 , & V_260 ) ) {
F_10 ( L_77 ) ;
}
} else if ( F_3 ( V_262 -> V_182 ,
V_273 ) ) {
if ( V_7 == V_20 ||
V_7 == V_22 ) {
V_260 . V_265 = true ;
V_54 -> V_237 = V_7 + 1 ;
V_253 -> V_266 =
F_24 ( V_267 ) ;
} else if ( V_7 == V_21 ||
V_7 == V_23 ) {
V_253 -> V_266 =
F_24 ( V_268 ) ;
} else {
F_10 ( L_78 , V_7 ) ;
goto exit;
}
} else if ( F_2 ( V_262 -> V_182 ,
V_273 ) ) {
} else {
F_10 ( L_79 ,
V_5 , V_7 ) ;
return false ;
}
if ( F_18 ( V_206 ,
& V_54 -> V_56 [ V_57 ] . V_58 -> V_205 ) )
F_54 ( 50 ) ;
if ( F_18 ( V_135 , & V_112 -> V_136 ) )
F_74 ( V_112 ) ;
memcpy ( V_165 -> V_215 , V_262 -> V_239 , V_52 ) ;
if ( V_260 . V_264 == 0 )
F_65 ( V_139 , 0 ) ;
if ( V_54 -> V_237 != V_235 ) {
F_20 ( V_186 , & V_54 -> V_85 ) ;
}
V_54 -> V_220 = 0 ;
F_20 ( V_217 , & V_54 -> V_85 ) ;
if ( V_260 . V_265 &&
F_75 ( F_57 ( V_253 -> V_40 ) ) &&
V_54 -> V_56 [ V_60 ] . V_58 -> V_281 . V_282 ) {
V_165 = & V_54 -> V_165 ;
V_165 -> V_196 = F_57 ( V_253 -> V_40 ) ;
if ( F_49 ( V_54 ) ==
V_202 ) {
F_10 ( L_80 ) ;
goto exit;
}
F_60 ( V_112 , V_139 , true , true ) ;
V_253 -> V_40 = F_24 ( V_165 -> V_201 ) ;
}
V_275 = 0 ;
while ( ! V_54 -> V_223 &&
( V_274 == false ) && ( V_275 < V_283 ) ) {
V_274 = ! F_71 ( V_54 , V_253 ) ;
V_275 ++ ;
}
if ( V_274 == false ) {
F_10 ( L_81 , V_275 ) ;
F_34 ( V_167 , & V_54 -> V_85 ) ;
}
exit:
F_34 ( V_217 , & V_54 -> V_85 ) ;
if ( V_274 && V_260 . V_263 && ! V_54 -> V_223 &&
F_18 ( V_186 , & V_54 -> V_85 ) &&
V_54 -> V_220 == V_165 -> V_166 ) {
V_277 = F_76 ( V_256 - V_54 -> V_255 ) ;
if ( F_57 ( V_253 -> V_266 ) > V_277 )
V_276 = F_57 ( V_253 -> V_266 ) -
V_277 ;
else
V_276 = 0 ;
if ( V_276 > 50 ) {
F_20 ( V_185 ,
& V_54 -> V_85 ) ;
F_5 ( V_72 , L_82 ,
F_57 ( V_253 -> V_266 ) ,
V_276 ) ;
V_276 += 100 ;
if ( ! F_36 ( V_54 ,
V_54 -> V_220 ,
V_276 ) ) {
unsigned long V_171 ;
V_276 += 100 ;
V_171 = F_51 ( V_276 ) ;
F_53 ( & V_54 -> V_187 ,
V_171 ) ;
}
F_34 ( V_185 ,
& V_54 -> V_85 ) ;
}
}
if ( V_54 -> V_223 ) {
V_54 -> V_223 = false ;
V_274 = true ;
}
F_34 ( V_186 , & V_54 -> V_85 ) ;
if ( V_260 . V_264 == 1 )
F_65 ( V_139 , 1 ) ;
return V_274 ;
}
T_4 F_77 ( struct V_48 * V_49 ,
const struct V_180 * V_181 ,
void * V_182 )
{
struct V_137 * V_112 = V_49 -> V_183 -> V_184 ;
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_165 * V_165 = & V_54 -> V_165 ;
struct V_175 * V_145 ;
struct V_81 * V_58 = V_49 -> V_58 ;
struct V_226 * V_227 = (struct V_226 * ) V_182 ;
T_2 V_41 = F_63 ( V_227 -> V_41 ) ;
T_3 * V_229 ;
T_1 V_224 ;
T_4 V_230 ;
T_2 V_231 ;
F_5 ( V_72 , L_83 , V_181 -> V_247 ,
V_181 -> V_284 ) ;
if ( F_18 ( V_197 , & V_54 -> V_85 ) &&
( memcmp ( V_165 -> V_215 , V_181 -> V_236 , V_52 ) == 0 ) ) {
V_165 -> V_201 = F_58 ( V_41 ) ;
F_5 ( V_72 , L_84 ,
V_165 -> V_201 ) ;
F_42 ( & V_165 -> V_198 ) ;
}
if ( V_181 -> V_285 == 0 )
return 0 ;
if ( F_18 ( V_167 , & V_54 -> V_85 ) ) {
F_5 ( V_72 , L_85 ) ;
return 0 ;
}
F_5 ( V_72 , L_86 , V_58 -> V_232 ) ;
V_231 = ( V_286 & V_234 ) >> 4 ;
if ( ( V_58 -> V_232 & F_64 ( V_231 ) ) == 0 )
return 0 ;
V_229 = ( T_3 * ) ( V_227 + 1 ) ;
V_224 = V_181 -> V_225 - sizeof( * V_227 ) ;
V_230 = F_67 ( F_58 ( V_41 ) ,
F_68 ( V_41 ) ?
V_243 :
V_244 ) ;
V_145 = V_49 -> V_139 -> V_245 ;
F_69 ( V_145 , V_230 , 0 , V_229 , V_224 , V_246 ) ;
F_5 ( V_72 , L_87 ,
V_224 , V_181 -> V_225 , V_41 , V_230 ) ;
return 0 ;
}
T_4 F_78 ( struct V_137 * V_112 )
{
struct V_48 * V_55 ;
struct V_48 * V_59 ;
struct V_81 * V_287 ;
struct V_53 * V_54 ;
struct V_288 * V_183 ;
T_4 V_289 ;
T_4 V_140 = 0 ;
V_54 = & V_112 -> V_54 ;
V_54 -> V_112 = V_112 ;
V_183 = V_112 -> V_290 ;
V_55 = V_183 -> V_291 [ 0 ] ;
V_59 = V_183 -> V_291 [ 1 ] ;
V_54 -> V_56 [ V_57 ] . V_58 = V_55 -> V_58 ;
if ( V_59 ) {
V_287 = F_79 ( V_112 , V_292 ,
false ) ;
if ( F_80 ( V_287 ) ) {
F_10 ( L_88 ) ;
V_140 = - V_106 ;
goto exit;
}
V_287 -> V_49 = V_59 ;
V_59 -> V_58 = V_287 ;
V_287 -> V_145 . V_146 = V_59 -> V_139 ;
V_59 -> V_139 -> V_245 = & V_287 -> V_145 ;
F_81 ( V_59 -> V_139 , F_82 ( V_112 -> V_164 ) ) ;
V_54 -> V_56 [ V_60 ] . V_58 = V_287 ;
F_11 ( V_54 ) ;
F_7 ( V_55 , V_54 -> V_61 ) ;
V_140 = F_8 ( V_55 , L_29 , 1 ) ;
if ( V_140 < 0 ) {
F_10 ( L_32 ) ;
F_83 ( V_287 ) ;
goto exit;
}
V_140 = F_84 ( V_55 , L_89 , & V_289 ) ;
if ( V_140 < 0 ) {
F_10 ( L_90 ) ;
F_83 ( V_287 ) ;
goto exit;
}
if ( V_59 -> V_289 != V_289 ) {
F_10 ( L_91 ,
V_289 , V_59 -> V_289 ) ;
F_83 ( V_287 ) ;
goto exit;
}
F_85 ( & V_54 -> V_251 ) ;
F_86 ( & V_54 -> V_165 . V_193 , F_46 ) ;
F_85 ( & V_54 -> V_165 . V_198 ) ;
F_85 ( & V_54 -> V_187 ) ;
}
exit:
return V_140 ;
}
void F_87 ( struct V_53 * V_54 )
{
struct V_81 * V_58 ;
V_58 = V_54 -> V_56 [ V_60 ] . V_58 ;
if ( V_58 != NULL ) {
F_44 ( V_58 -> V_49 ) ;
F_16 ( V_54 ) ;
F_83 ( V_58 ) ;
V_54 -> V_56 [ V_60 ] . V_58 = NULL ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
}
static void F_88 ( struct V_53 * V_54 ,
T_2 * V_41 )
{
struct V_48 * V_49 ;
struct V_293 V_294 ;
T_4 V_140 ;
V_49 = V_54 -> V_56 [ V_57 ] . V_58 -> V_49 ;
* V_41 = 11 & V_42 ;
V_140 = F_66 ( V_49 , V_295 , & V_294 , sizeof( V_294 ) ) ;
if ( ! V_140 ) {
* V_41 = F_57 ( V_294 . V_296 ) & V_42 ;
if ( * V_41 < V_43 )
* V_41 |= V_44 ;
else
* V_41 |= V_45 ;
}
* V_41 |= V_46 | V_47 ;
}
int F_89 ( struct V_137 * V_112 ,
enum V_297 V_298 )
{
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_81 * V_58 ;
struct V_299 V_300 ;
T_4 V_140 ;
T_2 V_41 ;
F_5 ( V_27 , L_50 ) ;
V_58 = V_54 -> V_56 [ V_57 ] . V_58 ;
if ( ! V_58 ) {
F_10 ( L_92 ) ;
return - V_83 ;
}
F_60 ( V_112 , V_58 -> V_49 -> V_139 , true , true ) ;
V_58 = V_54 -> V_56 [ V_144 ] . V_58 ;
if ( ! V_58 ) {
F_10 ( L_93 ) ;
return - V_83 ;
}
F_65 ( V_58 -> V_49 -> V_139 , 0 ) ;
F_88 ( V_54 , & V_41 ) ;
V_300 . type = F_14 ( ( T_2 ) V_298 ) ;
V_300 . V_79 = F_14 ( V_41 ) ;
memcpy ( V_300 . V_236 , V_54 -> V_63 , sizeof( V_300 . V_236 ) ) ;
F_90 ( V_112 , V_58 ) ;
V_140 = F_9 ( V_58 -> V_49 , L_94 , & V_300 ,
sizeof( V_300 ) ) ;
if ( V_140 ) {
F_10 ( L_95 , V_140 ) ;
F_90 ( V_112 , NULL ) ;
return V_140 ;
}
V_140 = F_91 ( V_112 , V_301 ,
F_51 ( 1500 ) ) ;
F_90 ( V_112 , NULL ) ;
if ( ! V_140 ) {
F_10 ( L_96 ) ;
return - V_258 ;
}
V_140 = F_92 ( V_58 -> V_49 , V_302 ,
V_303 ) ;
return V_140 ;
}
static int F_93 ( struct V_53 * V_54 ,
struct V_48 * V_49 , T_3 V_304 [ V_52 ] ,
enum V_297 V_305 )
{
struct V_299 V_300 ;
int V_140 ;
T_2 V_41 ;
F_88 ( V_54 , & V_41 ) ;
memcpy ( V_300 . V_236 , V_304 , V_52 ) ;
V_300 . type = F_14 ( ( T_2 ) V_305 ) ;
V_300 . V_79 = F_14 ( V_41 ) ;
V_140 = F_9 ( V_49 , L_97 , & V_300 ,
sizeof( V_300 ) ) ;
if ( V_140 )
return V_140 ;
return V_140 ;
}
static int F_94 ( struct V_81 * V_58 )
{
struct V_137 * V_112 = F_95 ( & V_58 -> V_145 ) ;
struct V_138 * V_306 = F_96 ( V_112 ) ;
struct V_48 * V_49 = F_97 ( V_306 ) ;
T_3 * V_236 = V_58 -> V_145 . V_146 -> V_61 ;
return F_9 ( V_49 , L_98 , V_236 , V_52 ) ;
}
static int F_98 ( struct V_81 * V_58 )
{
struct V_137 * V_112 = F_95 ( & V_58 -> V_145 ) ;
struct V_138 * V_306 = F_96 ( V_112 ) ;
struct V_48 * V_49 = F_97 ( V_306 ) ;
T_3 * V_236 = V_58 -> V_145 . V_146 -> V_61 ;
return F_9 ( V_49 , L_99 , V_236 , V_52 ) ;
}
struct V_175 * F_99 ( struct V_164 * V_164 , const char * V_307 ,
enum V_308 type , T_1 * V_156 ,
struct V_309 * V_310 )
{
struct V_137 * V_112 = F_33 ( V_164 ) ;
struct V_48 * V_49 = F_97 ( F_96 ( V_112 ) ) ;
struct V_81 * V_58 ;
enum V_297 V_305 ;
enum V_311 V_152 ;
int V_140 ;
if ( F_100 ( V_112 ) )
return F_101 ( - V_312 ) ;
F_5 ( V_72 , L_100 , V_307 , type ) ;
switch ( type ) {
case V_313 :
V_305 = V_314 ;
V_152 = V_315 ;
break;
case V_316 :
V_305 = V_317 ;
V_152 = V_153 ;
break;
default:
return F_101 ( - V_318 ) ;
}
V_58 = F_79 ( V_112 , type , false ) ;
if ( F_80 ( V_58 ) )
return (struct V_175 * ) V_58 ;
F_90 ( V_112 , V_58 ) ;
V_140 = F_93 ( & V_112 -> V_54 , V_49 , V_112 -> V_54 . V_63 ,
V_305 ) ;
if ( V_140 ) {
F_90 ( V_112 , NULL ) ;
goto V_319;
}
V_140 = F_91 ( V_112 , V_320 ,
F_51 ( 1500 ) ) ;
F_90 ( V_112 , NULL ) ;
if ( ! V_140 ) {
F_10 ( L_101 ) ;
V_140 = - V_258 ;
goto V_319;
}
V_49 = V_58 -> V_49 ;
if ( ! V_49 ) {
F_10 ( L_102 ) ;
V_140 = - V_321 ;
goto V_319;
}
strncpy ( V_49 -> V_139 -> V_307 , V_307 , sizeof( V_49 -> V_139 -> V_307 ) - 1 ) ;
V_140 = F_102 ( V_49 , true ) ;
if ( V_140 ) {
F_10 ( L_103 ) ;
goto V_319;
}
V_112 -> V_54 . V_56 [ V_144 ] . V_58 = V_58 ;
F_8 ( V_49 , L_104 , 1 ) ;
if ( V_305 == V_317 ) {
F_92 ( V_49 , V_302 ,
V_303 ) ;
}
return & V_49 -> V_58 -> V_145 ;
V_319:
F_83 ( V_58 ) ;
return F_101 ( V_140 ) ;
}
int F_103 ( struct V_164 * V_164 , struct V_175 * V_145 )
{
struct V_137 * V_112 = F_104 ( V_164 ) ;
struct V_53 * V_54 = & V_112 -> V_54 ;
struct V_81 * V_58 ;
unsigned long V_322 = F_51 ( 1500 ) ;
bool V_323 = false ;
int V_140 ;
F_5 ( V_27 , L_105 ) ;
V_58 = F_47 ( V_145 , struct V_81 , V_145 ) ;
switch ( V_58 -> V_145 . V_305 ) {
case V_313 :
if ( F_18 ( V_324 , & V_58 -> V_205 ) )
V_323 = true ;
break;
case V_316 :
if ( ! F_94 ( V_58 ) )
V_323 = true ;
break;
case V_292 :
default:
return - V_325 ;
break;
}
F_34 ( V_167 , & V_54 -> V_85 ) ;
F_5 ( V_72 , L_46 ) ;
if ( V_323 )
F_53 ( & V_112 -> V_326 ,
F_51 ( 500 ) ) ;
F_105 ( V_58 ) ;
F_90 ( V_112 , V_58 ) ;
V_140 = F_98 ( V_58 ) ;
if ( ! V_140 ) {
V_140 = F_91 ( V_112 , V_327 ,
V_322 ) ;
if ( ! V_140 )
V_140 = - V_258 ;
else
V_140 = 0 ;
}
F_90 ( V_112 , NULL ) ;
F_83 ( V_58 ) ;
V_54 -> V_56 [ V_144 ] . V_58 = NULL ;
return V_140 ;
}
