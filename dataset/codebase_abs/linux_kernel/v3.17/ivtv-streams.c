static void F_1 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = & V_2 -> V_5 [ type ] ;
struct V_6 * V_7 = V_4 -> V_7 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 = V_2 ;
V_4 -> type = type ;
V_4 -> V_8 = V_9 [ type ] . V_8 ;
V_4 -> V_10 = V_9 [ type ] . V_11 ;
if ( V_9 [ type ] . V_12 )
V_4 -> V_13 = V_14 ;
else
V_4 -> V_13 = V_9 [ type ] . V_13 ;
V_4 -> V_15 = V_2 -> V_16 [ type ] ;
if ( V_4 -> V_15 )
V_4 -> V_17 = ( V_2 -> V_18 . V_19 [ type ] * 1024 + V_4 -> V_15 - 1 ) / V_4 -> V_15 ;
F_2 ( & V_4 -> V_20 ) ;
F_3 ( & V_4 -> V_21 ) ;
V_4 -> V_22 = V_23 ;
F_4 ( & V_4 -> V_24 ) ;
F_4 ( & V_4 -> V_25 ) ;
F_4 ( & V_4 -> V_26 ) ;
F_4 ( & V_4 -> V_27 ) ;
F_4 ( & V_4 -> V_28 ) ;
}
static int F_5 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = & V_2 -> V_5 [ type ] ;
int V_29 = V_9 [ type ] . V_29 ;
int V_30 = V_2 -> V_31 + V_32 + V_29 ;
V_4 -> V_7 = NULL ;
V_4 -> V_2 = V_2 ;
V_4 -> type = type ;
V_4 -> V_8 = V_9 [ type ] . V_8 ;
if ( type == V_33 && ! ( V_2 -> V_34 & V_35 ) )
return 0 ;
if ( type >= V_36 && ! ( V_2 -> V_34 & V_37 ) )
return 0 ;
if ( V_9 [ type ] . V_13 != V_14 &&
V_2 -> V_18 . V_19 [ type ] == 0 ) {
F_6 ( L_1 , V_9 [ type ] . V_8 ) ;
return 0 ;
}
F_1 ( V_2 , type ) ;
V_4 -> V_7 = F_7 () ;
if ( V_4 -> V_7 == NULL ) {
F_8 ( L_2 , V_4 -> V_8 ) ;
return - V_38 ;
}
snprintf ( V_4 -> V_7 -> V_8 , sizeof( V_4 -> V_7 -> V_8 ) , L_3 ,
V_2 -> V_39 . V_8 , V_4 -> V_8 ) ;
V_4 -> V_7 -> V_30 = V_30 ;
V_4 -> V_7 -> V_39 = & V_2 -> V_39 ;
if ( V_9 [ type ] . V_11 &
( V_37 | V_40 ) )
V_4 -> V_7 -> V_41 = V_42 ;
V_4 -> V_7 -> V_43 = V_9 [ type ] . V_43 ;
V_4 -> V_7 -> V_44 = V_2 -> V_39 . V_44 ;
V_4 -> V_7 -> V_45 = V_46 ;
V_4 -> V_7 -> V_47 = V_48 ;
V_4 -> V_7 -> V_49 = & V_2 -> V_50 ;
if ( V_4 -> type == V_51 ) {
F_9 ( V_4 -> V_7 , V_52 ) ;
F_9 ( V_4 -> V_7 , V_53 ) ;
F_9 ( V_4 -> V_7 , V_54 ) ;
F_9 ( V_4 -> V_7 , V_55 ) ;
F_9 ( V_4 -> V_7 , V_56 ) ;
F_9 ( V_4 -> V_7 , V_57 ) ;
F_9 ( V_4 -> V_7 , V_58 ) ;
F_9 ( V_4 -> V_7 , V_59 ) ;
F_9 ( V_4 -> V_7 , V_60 ) ;
F_9 ( V_4 -> V_7 , V_61 ) ;
F_9 ( V_4 -> V_7 , V_62 ) ;
}
F_10 ( V_4 -> V_7 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int type ;
for ( type = 0 ; type < V_63 ; type ++ ) {
if ( F_5 ( V_2 , type ) )
break;
if ( V_2 -> V_5 [ type ] . V_7 == NULL )
continue;
if ( F_12 ( & V_2 -> V_5 [ type ] ) )
break;
}
if ( type == V_63 )
return 0 ;
F_13 ( V_2 , 0 ) ;
return - V_38 ;
}
static int F_14 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = & V_2 -> V_5 [ type ] ;
int V_64 = V_9 [ type ] . V_64 ;
const char * V_8 ;
int V_30 ;
if ( V_4 -> V_7 == NULL )
return 0 ;
V_30 = V_4 -> V_7 -> V_30 ;
if ( type != V_65 ) {
struct V_3 * V_66 = & V_2 -> V_5 [ V_65 ] ;
if ( V_66 -> V_7 )
V_30 = V_66 -> V_7 -> V_30 + V_9 [ type ] . V_29 ;
}
F_15 ( V_4 -> V_7 , V_4 ) ;
if ( F_16 ( V_4 -> V_7 , V_64 , V_30 ) ) {
F_8 ( L_4 ,
V_4 -> V_8 , V_30 ) ;
V_46 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
return - V_38 ;
}
V_8 = F_17 ( V_4 -> V_7 ) ;
switch ( V_64 ) {
case V_67 :
F_6 ( L_5 ,
V_8 , V_4 -> V_8 , V_2 -> V_18 . V_19 [ type ] ) ;
break;
case V_68 :
F_6 ( L_6 ,
V_8 , V_4 -> V_8 ) ;
break;
case V_69 :
if ( V_2 -> V_18 . V_19 [ type ] )
F_6 ( L_5 ,
V_8 , V_4 -> V_8 , V_2 -> V_18 . V_19 [ type ] ) ;
else
F_6 ( L_6 ,
V_8 , V_4 -> V_8 ) ;
break;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
int type ;
int V_70 = 0 ;
for ( type = 0 ; type < V_63 ; type ++ )
V_70 |= F_14 ( V_2 , type ) ;
if ( V_70 == 0 )
return 0 ;
F_13 ( V_2 , 1 ) ;
return - V_38 ;
}
void F_13 ( struct V_1 * V_2 , int V_71 )
{
int type ;
for ( type = 0 ; type < V_63 ; type ++ ) {
struct V_6 * V_7 = V_2 -> V_5 [ type ] . V_7 ;
V_2 -> V_5 [ type ] . V_7 = NULL ;
if ( V_7 == NULL )
continue;
F_19 ( & V_2 -> V_5 [ type ] ) ;
if ( V_71 )
F_20 ( V_7 ) ;
else
V_46 ( V_7 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
int V_72 = F_22 ( V_2 ) ;
T_1 V_73 [ V_74 ] ;
int V_75 ;
int V_76 ;
F_23 ( V_2 , V_77 , 5 , 0xffff , 0 , 0 , 0 , 0 ) ;
if ( V_72 )
F_24 ( V_2 -> V_78 , V_79 , V_80 , & V_2 -> V_79 . V_81 . V_82 . V_79 ) ;
else
F_24 ( V_2 -> V_78 , V_79 , V_83 , & V_2 -> V_79 . V_81 . V_82 . V_84 ) ;
if ( V_72 ) {
V_75 = V_2 -> V_79 . V_85 * 2 ;
} else {
V_75 = V_2 -> V_86 ? 24 : 38 ;
if ( V_2 -> V_86 && ( V_2 -> V_87 & V_88 ) )
V_75 += 2 ;
}
V_2 -> V_79 . V_89 = V_75 * ( V_72 ? V_2 -> V_79 . V_90 : V_2 -> V_79 . V_91 ) ;
V_73 [ 0 ] = V_72 | 0x02 | ( 0xbd << 8 ) ;
V_73 [ 1 ] = 1 ;
V_73 [ 2 ] = V_72 ? 4 : 4 * ( V_2 -> V_79 . V_90 / V_2 -> V_79 . V_89 ) ;
if ( V_2 -> V_87 & V_88 ) {
if ( V_72 ) {
V_73 [ 3 ] = 0x20602060 ;
V_73 [ 4 ] = 0x30703070 ;
} else {
V_73 [ 3 ] = 0xB0F0B0F0 ;
V_73 [ 4 ] = 0xA0E0A0E0 ;
}
V_73 [ 5 ] = V_75 ;
V_73 [ 6 ] = ( V_72 ? V_2 -> V_79 . V_90 : V_2 -> V_79 . V_91 ) ;
} else {
if ( V_72 ) {
V_73 [ 3 ] = 0x25256262 ;
V_73 [ 4 ] = 0x387F7F7F ;
} else {
V_73 [ 3 ] = 0xABABECEC ;
V_73 [ 4 ] = 0xB6F1F1F1 ;
}
V_73 [ 5 ] = V_75 ;
V_73 [ 6 ] = V_2 -> V_79 . V_89 / V_75 ;
}
F_25 (
L_7 ,
V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] , V_73 [ 5 ] , V_73 [ 6 ] ) ;
F_26 ( V_2 , V_92 , 7 , V_73 ) ;
V_2 -> V_79 . V_93 = V_73 [ 2 ] ;
V_2 -> V_79 . V_94 = V_73 [ 0 ] ;
if ( ! V_2 -> V_79 . V_94 )
V_2 -> V_79 . V_94 = 1 ;
F_25 ( L_8 ,
V_2 -> V_79 . V_93 , V_73 [ 1 ] , V_2 -> V_79 . V_94 ) ;
for ( V_76 = 2 ; V_76 <= 24 ; V_76 ++ ) {
int V_95 ;
if ( V_2 -> V_86 ) {
V_95 = V_76 >= 10 && V_76 < 22 ;
} else {
V_95 = V_76 >= 6 && V_76 < 24 ;
}
F_23 ( V_2 , V_77 , 5 , V_76 - 1 ,
V_95 , 0 , 0 , 0 ) ;
F_23 ( V_2 , V_77 , 5 , ( V_76 - 1 ) | 0x80000000 ,
V_95 , 0 , 0 , 0 ) ;
}
}
int F_27 ( struct V_3 * V_4 )
{
T_1 V_73 [ V_74 ] ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_96 = 0 , V_97 = 0 ;
int V_98 = 0 ;
if ( V_4 -> V_7 == NULL )
return - V_99 ;
F_25 ( L_9 , V_4 -> V_8 ) ;
switch ( V_4 -> type ) {
case V_65 :
V_96 = 0 ;
V_97 = 3 ;
if ( V_2 -> V_100 == V_101 ) {
F_28 ( V_2 , 0 ) ;
V_98 = 1 ;
}
V_2 -> V_102 = V_2 -> V_103 = 0 ;
V_2 -> V_104 = V_105 ;
V_2 -> V_106 = F_29 ( V_2 -> V_107 . V_108 ) ;
V_2 -> V_109 = 0 ;
break;
case V_110 :
if ( V_2 -> V_100 == V_101 ) {
V_96 = 2 ;
V_97 = 11 ;
break;
}
V_96 = 1 ;
V_97 = 1 ;
break;
case V_111 :
V_96 = 1 ;
V_97 = 2 ;
break;
case V_112 :
V_96 = 1 ;
V_97 = 4 ;
V_2 -> V_79 . V_113 = 0 ;
V_2 -> V_79 . V_114 = 0 ;
memset ( V_2 -> V_79 . V_115 ,
0 , sizeof( V_2 -> V_79 . V_115 ) ) ;
break;
default:
return - V_99 ;
}
V_4 -> V_97 = V_97 ;
V_4 -> V_116 = 0 ;
F_30 ( V_117 , & V_4 -> V_118 ) ;
if ( F_31 ( & V_2 -> V_119 ) == 0 ) {
int V_120 ;
F_23 ( V_2 , V_121 , 2 , 1 , 1 ) ;
F_23 ( V_2 , V_122 , 1 , 0 ) ;
F_23 ( V_2 , V_123 , 2 , 3 , ! V_2 -> V_124 ) ;
F_23 ( V_2 , V_123 , 2 , 8 , 0 ) ;
F_23 ( V_2 , V_123 , 2 , 4 , 1 ) ;
F_23 ( V_2 , V_123 , 1 , 12 ) ;
F_23 ( V_2 , V_125 , 12 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_2 -> V_126 -> V_127 & ( V_128 | V_129 ) )
V_120 = 0xF1 ;
else if ( V_2 -> V_126 -> V_127 & V_130 )
V_120 = 0xEF ;
else
V_120 = 0x140 ;
F_23 ( V_2 , V_131 , 2 , V_120 , V_120 ) ;
if ( V_2 -> V_34 & V_132 ) {
F_21 ( V_2 ) ;
}
F_32 ( V_2 , V_73 , V_133 , 2 , 7 , 400 ) ;
V_2 -> V_134 = V_73 [ 0 ] ;
V_2 -> V_135 = V_73 [ 1 ] ;
V_2 -> V_136 = 0 ;
V_2 -> V_137 = 0 ;
F_25 ( L_10 ,
V_2 -> V_134 , V_2 -> V_135 ) ;
F_33 ( & V_2 -> V_107 ) ;
if ( F_34 ( V_138 , & V_2 -> V_139 ) )
F_23 ( V_2 , V_140 , 1 ,
1 | ( F_29 ( V_2 -> V_107 . V_141 ) << 8 ) ) ;
}
if ( V_2 -> V_124 && ! F_35 ( V_142 , & V_2 -> V_139 ) ) {
F_23 ( V_2 , V_143 , 4 , 0 , 1 , V_144 , - 1 ) ;
F_36 ( V_2 , V_144 ) ;
}
if ( F_31 ( & V_2 -> V_119 ) == 0 ) {
F_37 ( V_2 , V_145 ) ;
F_30 ( V_146 , & V_2 -> V_139 ) ;
F_38 ( & V_2 -> V_107 , 1 ) ;
F_24 ( V_2 -> V_147 , V_148 , V_149 , 1 ) ;
F_24 ( V_2 -> V_78 , V_150 , V_149 , 0 ) ;
F_39 ( 300 , 0 ) ;
F_23 ( V_2 , V_151 , 0 ) ;
F_24 ( V_2 -> V_78 , V_150 , V_149 , 1 ) ;
}
if ( F_23 ( V_2 , V_152 , 2 , V_96 , V_97 ) )
{
F_40 ( L_11 ) ;
return - V_99 ;
}
if ( V_98 ) {
F_28 ( V_2 , 1 ) ;
}
if ( V_4 -> type == V_112 )
F_36 ( V_2 , V_153 ) ;
else
F_36 ( V_2 , V_145 ) ;
F_41 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
T_1 V_73 [ V_74 ] ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_154 ;
T_2 V_155 ;
T_2 V_156 ;
if ( V_4 -> V_7 == NULL )
return - V_99 ;
F_25 ( L_12 ) ;
V_155 = V_2 -> V_107 . V_155 ;
V_156 = V_2 -> V_107 . V_156 ;
F_23 ( V_2 , V_157 , 2 , V_2 -> V_158 , V_2 -> V_159 ) ;
F_23 ( V_2 , V_160 , 1 , 0 ) ;
F_23 ( V_2 , V_161 , 1 , 1 ) ;
F_32 ( V_2 , V_73 , V_162 , 1 , 1 ) ;
V_2 -> V_79 . V_163 = V_73 [ 0 ] ;
F_25 ( L_13 ,
V_2 -> V_79 . V_163 , V_73 [ 1 ] ) ;
switch ( V_4 -> type ) {
case V_164 :
if ( V_2 -> V_100 == V_101 ) {
V_154 = 1 ;
} else {
V_154 = 2 ;
V_155 = 720 ;
V_156 = V_2 -> V_165 ? 576 : 480 ;
}
F_25 ( L_14 , V_154 ) ;
break;
case V_36 :
default:
V_154 = 0 ;
break;
}
if ( F_23 ( V_2 , V_166 , 4 , V_154 ,
V_155 , V_156 , V_2 -> V_107 . V_167 ) ) {
F_40 ( L_15 ) ;
}
F_39 ( 10 , 0 ) ;
return F_43 ( V_2 , L_16 ) ;
}
int F_44 ( struct V_3 * V_4 , int V_168 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_169 ;
if ( V_4 -> V_7 == NULL )
return - V_99 ;
if ( F_35 ( V_170 , & V_4 -> V_118 ) )
return 0 ;
F_25 ( L_17 , V_4 -> V_8 , V_168 ) ;
V_169 = F_42 ( V_4 ) ;
if ( V_169 < 0 ) {
F_30 ( V_170 , & V_4 -> V_118 ) ;
return V_169 ;
}
F_23 ( V_2 , V_171 , 1 , 65536 ) ;
F_30 ( V_117 , & V_4 -> V_118 ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_174 ] . V_73 [ 0 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_174 ] . V_73 [ 1 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_174 ] . V_73 [ 2 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_174 ] . V_73 [ 3 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_175 ] . V_73 [ 0 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_175 ] . V_73 [ 1 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_175 ] . V_73 [ 2 ] ) ;
F_45 ( 0 , & V_2 -> V_172 . V_173 [ V_175 ] . V_73 [ 3 ] ) ;
F_23 ( V_2 , V_176 , 4 , 0 , 1 , V_177 , - 1 ) ;
F_23 ( V_2 , V_178 , 2 , V_168 , 0 ) ;
F_39 ( 10 , 0 ) ;
F_36 ( V_2 , V_179 ) ;
F_46 ( L_18 , V_2 -> V_180 ) ;
F_41 ( & V_2 -> V_181 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
int V_76 ;
for ( V_76 = V_63 - 1 ; V_76 >= 0 ; V_76 -- ) {
struct V_3 * V_4 = & V_2 -> V_5 [ V_76 ] ;
if ( V_4 -> V_7 == NULL )
continue;
if ( F_34 ( V_170 , & V_4 -> V_118 ) ) {
F_48 ( V_4 , 0 ) ;
}
}
}
int F_48 ( struct V_3 * V_4 , int V_182 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_49 ( V_183 , V_184 ) ;
int V_185 ;
int V_186 ;
if ( V_4 -> V_7 == NULL )
return - V_99 ;
F_25 ( L_19 ) ;
if ( V_4 -> type == V_187 )
return 0 ;
if ( F_31 ( & V_2 -> V_119 ) == 0 )
return 0 ;
switch ( V_4 -> type ) {
case V_110 :
V_185 = 1 ;
break;
case V_111 :
V_185 = 1 ;
break;
case V_112 :
V_185 = 1 ;
break;
case V_65 :
default:
V_185 = 0 ;
break;
}
if ( V_4 -> type == V_65 && V_182 ) {
V_186 = 0 ;
} else {
V_186 = 1 ;
}
F_23 ( V_2 , V_188 , 3 , V_186 , V_185 , V_4 -> V_97 ) ;
if ( ! F_34 ( V_189 , & V_4 -> V_118 ) ) {
if ( V_4 -> type == V_65 && V_182 ) {
unsigned long V_190 ;
unsigned long V_191 = V_105 ;
F_50 ( & V_2 -> V_192 , & V_183 ) ;
F_51 ( V_193 ) ;
while ( ! F_34 ( V_146 , & V_2 -> V_139 ) &&
F_52 ( V_105 ,
V_191 + F_53 ( 2000 ) ) ) {
F_54 ( F_53 ( 10 ) ) ;
}
V_190 = ( ( 1000 + V_194 / 2 ) / V_194 ) * ( V_105 - V_191 ) ;
if ( ! F_34 ( V_146 , & V_2 -> V_139 ) ) {
F_40 ( L_20 , V_4 -> V_8 ) ;
F_40 ( L_21 , V_4 -> V_8 , V_190 ) ;
} else {
F_25 ( L_22 , V_4 -> V_8 , V_190 ) ;
}
F_51 ( V_195 ) ;
F_55 ( & V_2 -> V_192 , & V_183 ) ;
F_56 ( V_117 , & V_4 -> V_118 ) ;
}
F_39 ( 100 , 0 ) ;
}
F_57 ( & V_2 -> V_119 ) ;
F_30 ( V_170 , & V_4 -> V_118 ) ;
if ( V_4 -> type == V_112 )
F_37 ( V_2 , V_153 ) ;
if ( F_31 ( & V_2 -> V_119 ) > 0 ) {
return 0 ;
}
F_38 ( & V_2 -> V_107 , 0 ) ;
F_37 ( V_2 , V_145 ) ;
F_58 ( & V_2 -> V_196 ) ;
if ( F_59 ( V_142 , & V_2 -> V_139 ) ) {
F_23 ( V_2 , V_143 , 4 , 0 , 0 , V_144 , - 1 ) ;
F_37 ( V_2 , V_144 ) ;
}
F_23 ( V_2 , V_188 , 3 , 1 , 2 , 7 ) ;
F_60 ( & V_4 -> V_21 ) ;
return 0 ;
}
int F_61 ( struct V_3 * V_4 , int V_197 , T_3 V_198 )
{
static const struct V_199 V_200 = {
. type = V_201 ,
} ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_4 -> V_7 == NULL )
return - V_99 ;
if ( V_4 -> type != V_164 && V_4 -> type != V_36 )
return - V_99 ;
if ( ! F_34 ( V_170 , & V_4 -> V_118 ) )
return 0 ;
F_25 ( L_23 , ( unsigned long long ) V_198 , V_197 ) ;
if ( ! ( V_197 & V_202 ) || V_198 ) {
T_1 V_203 = 0 ;
if ( V_198 ) {
F_23 ( V_2 , V_204 , 3 ,
0 , ( T_1 ) ( V_198 & 0xffffffff ) , ( T_1 ) ( V_198 >> 32 ) ) ;
}
while ( 1 ) {
T_1 V_73 [ V_74 ] ;
F_32 ( V_2 , V_73 , V_205 , 0 ) ;
if ( V_4 -> V_25 . V_17 + V_4 -> V_26 . V_17 == 0 ) {
if ( V_203 == V_73 [ 3 ] )
break;
V_203 = V_73 [ 3 ] ;
}
if ( F_39 ( 100 , 1 ) )
break;
}
}
F_23 ( V_2 , V_204 , 3 , V_197 & V_206 , 0 , 0 ) ;
F_23 ( V_2 , V_176 , 4 , 0 , 0 , V_177 , - 1 ) ;
F_37 ( V_2 , V_179 ) ;
F_58 ( & V_2 -> V_196 ) ;
F_30 ( V_207 , & V_4 -> V_118 ) ;
F_30 ( V_170 , & V_4 -> V_118 ) ;
F_62 ( V_4 ) ;
F_39 ( 40 , 0 ) ;
F_57 ( & V_2 -> V_181 ) ;
F_56 ( V_208 , & V_2 -> V_139 ) ;
F_60 ( & V_2 -> V_209 ) ;
F_63 ( V_4 -> V_7 , & V_200 ) ;
F_60 ( & V_4 -> V_21 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , int V_210 )
{
struct V_3 * V_211 = & V_2 -> V_5 [ V_110 ] ;
struct V_3 * V_212 = & V_2 -> V_5 [ V_164 ] ;
if ( V_211 -> V_7 == NULL || V_212 -> V_7 == NULL )
return - V_99 ;
F_25 ( L_24 ) ;
if ( V_210 ) {
if ( V_2 -> V_100 == V_101 ) {
return 0 ;
}
if ( F_64 ( V_2 , V_101 ) != V_101 )
return - V_213 ;
F_56 ( V_189 , & V_212 -> V_118 ) ;
F_56 ( V_170 , & V_212 -> V_118 ) ;
F_42 ( V_212 ) ;
F_23 ( V_2 , V_178 , 2 , 0 , 1 ) ;
F_41 ( & V_2 -> V_181 ) ;
if ( F_31 ( & V_2 -> V_119 ) == 0 ) {
F_33 ( & V_2 -> V_107 ) ;
F_38 ( & V_2 -> V_107 , 1 ) ;
}
F_23 ( V_2 , V_152 , 2 , 2 , 11 ) ;
F_41 ( & V_2 -> V_119 ) ;
return 0 ;
}
if ( V_2 -> V_100 != V_101 )
return 0 ;
F_23 ( V_2 , V_188 , 3 , 1 , 2 , 11 ) ;
F_23 ( V_2 , V_204 , 3 , 1 , 0 , 0 ) ;
F_57 ( & V_2 -> V_119 ) ;
F_57 ( & V_2 -> V_181 ) ;
F_30 ( V_189 , & V_212 -> V_118 ) ;
F_30 ( V_170 , & V_212 -> V_118 ) ;
V_2 -> V_100 = V_214 ;
if ( F_31 ( & V_2 -> V_119 ) == 0 )
F_38 ( & V_2 -> V_107 , 0 ) ;
return 0 ;
}
