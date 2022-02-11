static inline T_1 F_1 ( T_2 * V_1 )
{
return 0xffffff & ( T_1 ) F_2 ( V_1 - 1 ) ;
}
static int F_3 ( struct V_2 * V_3 , void * V_4 ,
unsigned long V_5 )
{
int V_6 ;
void * V_7 = V_4 ;
T_3 V_8 = V_5 ;
T_3 V_9 ;
if ( V_3 -> V_10 > 0 ) {
struct V_11 V_12 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_10 ; V_6 ++ ) {
if ( F_4 ( & V_12 , V_3 -> V_13 +
V_6 * sizeof( struct V_11 ) ,
sizeof( struct V_11 ) ) )
return - V_14 ;
V_9 = F_5 ( V_8 , V_12 . V_15 ) ;
if ( F_6 ( V_12 . V_16 , V_7 , V_9 ) )
return - V_14 ;
V_7 += V_9 ;
V_8 -= V_9 ;
if ( V_8 == 0 )
break;
}
return 0 ;
}
if ( F_6 ( V_3 -> V_13 , V_4 , V_5 ) )
return - V_14 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , void * V_17 ,
unsigned long V_5 )
{
int V_6 ;
void * V_7 = V_17 ;
T_3 V_8 = V_5 ;
T_3 V_9 ;
if ( V_3 -> V_10 > 0 ) {
struct V_11 V_12 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_10 ; V_6 ++ ) {
if ( F_4 ( & V_12 , V_3 -> V_13 +
V_6 * sizeof( struct V_11 ) ,
sizeof( struct V_11 ) ) )
return - V_14 ;
V_9 = F_5 ( V_8 , V_12 . V_15 ) ;
if ( F_4 ( V_7 , V_12 . V_16 , V_9 ) )
return - V_14 ;
V_7 += V_9 ;
V_8 -= V_9 ;
if ( V_8 == 0 )
break;
}
return 0 ;
}
if ( F_4 ( V_17 , V_3 -> V_13 , V_5 ) )
return - V_14 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_2 V_18 , T_2 V_19 ,
T_2 V_20 , T_2 V_21 )
{
T_2 V_9 ;
T_2 V_22 [ V_23 ] ;
if ( F_9 ( V_18 ) ) {
V_3 -> V_18 = V_24 ;
V_3 -> V_25 = V_26 ;
V_3 -> V_27 = V_28 ;
V_3 -> V_29 = V_30 ;
V_3 -> V_31 = 0 ;
} else {
V_3 -> V_18 = V_18 ;
V_3 -> V_25 = V_18 >> 1 ;
V_3 -> V_27 = V_28 ;
V_3 -> V_29 = V_30 ;
memset ( V_22 , 0 , V_23 ) ;
V_22 [ 0 ] = V_32 ;
V_22 [ 1 ] = V_19 ;
V_22 [ 2 ] = V_20 ;
V_22 [ 3 ] = V_21 ;
V_9 = F_10 ( T_2 , V_3 -> V_33 , V_23 ) ;
V_3 -> V_31 = V_9 ;
if ( F_6 ( V_3 -> V_34 , V_22 , V_9 ) > 0 )
return - V_14 ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , int V_35 )
{
T_2 V_18 , V_19 , V_20 , V_21 ;
int V_36 ;
if ( V_35 < 0 )
return V_35 ;
switch ( V_35 & 0x7FF ) {
case V_37 :
V_18 = V_24 ;
V_19 = V_38 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_41 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_44 ;
V_21 = V_40 ;
break;
case V_45 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_46 ;
V_21 = V_40 ;
break;
case V_47 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_49 :
V_18 = V_50 ;
V_19 = V_51 ;
V_20 = V_52 ;
V_21 = V_53 ;
break;
case V_54 :
V_18 = V_42 ;
V_19 = V_55 ;
V_20 = V_56 ;
V_21 = V_40 ;
break;
case V_57 :
V_18 = V_50 ;
V_19 = V_51 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_58 :
V_18 = V_50 ;
V_19 = V_51 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_59 :
V_18 = V_50 ;
V_19 = V_51 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_60 :
V_18 = V_50 ;
V_19 = V_51 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_61 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_62 ;
V_21 = V_63 ;
break;
case V_64 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_65 ;
V_21 = V_40 ;
break;
case V_66 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
case V_67 :
V_18 = V_42 ;
V_19 = V_68 ;
V_20 = V_69 ;
V_21 = V_40 ;
break;
case V_70 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_71 ;
V_21 = V_72 ;
break;
case V_73 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_46 ;
V_21 = V_40 ;
break;
case V_74 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_75 ;
V_21 = V_40 ;
break;
case V_76 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_77 ;
V_21 = V_40 ;
break;
case V_78 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_79 ;
V_21 = V_80 ;
break;
case V_81 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_82 ;
V_21 = V_83 ;
break;
case V_84 :
V_18 = V_42 ;
V_19 = V_48 ;
V_20 = V_85 ;
V_21 = V_86 ;
break;
case V_87 :
V_18 = V_42 ;
V_19 = V_88 ;
V_20 = V_89 ;
V_21 = V_40 ;
break;
case V_90 :
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_62 ;
V_21 = V_63 ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
default:
V_18 = V_42 ;
V_19 = V_43 ;
V_20 = V_39 ;
V_21 = V_40 ;
break;
}
V_36 = F_8 ( V_3 , V_18 , V_19 , V_20 , V_21 ) ;
return V_36 ? V_36 : V_35 ;
}
static int F_12 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_105 ,
int V_106 )
{
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_109 * V_110 ;
int V_36 ;
int V_35 ;
int V_9 ;
T_2 V_111 = 0x02 ;
T_2 V_112 ;
T_2 V_113 = 0x01 << 1 ;
T_2 V_114 = sizeof( V_108 -> V_115 ) ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
if ( V_110 -> V_117 )
V_112 = 0x01 ;
else
V_112 = 0 ;
F_14 ( V_110 ) ;
memset ( V_105 , 0 , V_118 ) ;
V_105 [ 2 ] = V_119 ;
V_105 [ 3 ] = V_111 ;
V_105 [ 4 ] = V_120 ;
V_105 [ 5 ] = V_112 ;
V_105 [ 7 ] = V_113 ;
strncpy ( & V_105 [ 8 ] , L_1 , 8 ) ;
strncpy ( & V_105 [ 16 ] , V_108 -> V_121 , 16 ) ;
while ( V_108 -> V_115 [ V_114 - 1 ] == ' ' && V_114 > 4 )
V_114 -- ;
V_114 -= 4 ;
strncpy ( & V_105 [ 32 ] , V_108 -> V_115 + V_114 , 4 ) ;
V_9 = F_5 ( V_106 , V_118 ) ;
return F_3 ( V_3 , V_105 , V_9 ) ;
}
static int F_15 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_105 ,
int V_106 )
{
int V_9 ;
memset ( V_105 , 0 , V_118 ) ;
V_105 [ 1 ] = V_122 ;
V_105 [ 3 ] = V_123 ;
V_105 [ 4 ] = V_122 ;
V_105 [ 5 ] = V_124 ;
V_105 [ 6 ] = V_125 ;
V_105 [ 7 ] = V_126 ;
V_105 [ 8 ] = V_127 ;
V_105 [ 9 ] = V_128 ;
V_9 = F_5 ( V_106 , V_118 ) ;
return F_3 ( V_3 , V_105 , V_9 ) ;
}
static int F_16 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_105 ,
int V_106 )
{
struct V_107 * V_108 = V_104 -> V_108 ;
int V_9 ;
memset ( V_105 , 0 , V_118 ) ;
V_105 [ 1 ] = V_124 ;
V_105 [ 3 ] = V_129 ;
strncpy ( & V_105 [ 4 ] , V_108 -> V_130 , V_129 ) ;
V_9 = F_5 ( V_106 , V_118 ) ;
return F_3 ( V_3 , V_105 , V_9 ) ;
}
static int F_17 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_105 , int V_106 )
{
struct V_107 * V_108 = V_104 -> V_108 ;
int V_36 ;
int V_35 ;
int V_9 ;
T_4 V_131 = F_18 ( V_104 -> V_116 ) ;
memset ( V_105 , 0 , V_106 ) ;
V_105 [ 1 ] = V_125 ;
if ( F_19 ( & V_108 -> V_132 -> V_133 ) >= F_20 ( 1 , 1 ) ) {
struct V_109 * V_110 ;
void * V_134 ;
int V_135 ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_134 = V_110 -> V_136 ;
V_135 = sizeof( V_110 -> V_136 ) ;
if ( F_19 ( & V_108 -> V_132 -> V_133 ) >= F_20 ( 1 , 2 ) ) {
if ( F_21 ( V_134 , V_135 * 8 ) ) {
V_134 = V_110 -> V_137 ;
V_135 = sizeof( V_110 -> V_137 ) ;
}
}
if ( F_21 ( V_134 , V_135 * 8 ) ) {
F_14 ( V_110 ) ;
goto V_138;
}
V_105 [ 3 ] = 4 + V_135 ;
V_105 [ 4 ] = 0x01 ;
V_105 [ 5 ] = 0x02 ;
V_105 [ 6 ] = 0x00 ;
V_105 [ 7 ] = V_135 ;
memcpy ( & V_105 [ 8 ] , V_134 , V_135 ) ;
F_14 ( V_110 ) ;
} else {
V_138:
if ( V_106 < 72 ) {
return F_8 ( V_3 ,
V_42 ,
V_43 , V_46 ,
V_40 ) ;
}
V_105 [ 3 ] = 0x48 ;
V_105 [ 4 ] = 0x03 ;
V_105 [ 5 ] = 0x08 ;
V_105 [ 6 ] = 0x00 ;
V_105 [ 7 ] = 0x44 ;
sprintf ( & V_105 [ 8 ] , L_2 , F_22 ( V_108 -> V_108 ) -> V_139 ) ;
memcpy ( & V_105 [ 12 ] , V_108 -> V_121 , sizeof( V_108 -> V_121 ) ) ;
sprintf ( & V_105 [ 52 ] , L_2 , V_131 ) ;
memcpy ( & V_105 [ 56 ] , V_108 -> V_130 , sizeof( V_108 -> V_130 ) ) ;
}
V_9 = V_106 ;
return F_3 ( V_3 , V_105 , V_9 ) ;
}
static int F_23 ( struct V_103 * V_104 , struct V_2 * V_3 ,
int V_106 )
{
T_2 * V_105 ;
int V_36 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_140 * V_141 ;
struct V_109 * V_110 ;
int V_9 ;
T_2 V_142 = 0x80 ;
T_2 V_143 ;
T_2 V_144 [ 8 ] = { 0 , 0 , 2 , 1 , 4 , 6 , 5 , 7 } ;
T_2 V_145 , V_146 , V_147 , V_112 ;
T_2 V_148 = 0x20 ;
T_2 V_149 ;
T_2 V_150 = 0x01 ;
V_105 = F_24 ( V_151 , V_152 ) ;
if ( V_105 == NULL )
return - V_153 ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
goto V_154;
V_143 = V_144 [ V_110 -> V_155 & 0x07 ] << 3 ;
if ( V_110 -> V_117 )
V_112 = 0x01 ;
else
V_112 = 0 ;
F_14 ( V_110 ) ;
V_145 = V_112 << 2 ;
V_146 = V_112 << 1 ;
V_147 = V_112 ;
V_35 = F_25 ( V_108 , & V_141 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
goto V_154;
V_149 = V_141 -> V_156 ;
F_14 ( V_141 ) ;
memset ( V_105 , 0 , V_151 ) ;
V_105 [ 1 ] = V_126 ;
V_105 [ 2 ] = 0x00 ;
V_105 [ 3 ] = 0x3C ;
V_105 [ 4 ] = V_142 | V_143 | V_145 | V_146 | V_147 ;
V_105 [ 5 ] = V_148 ;
V_105 [ 6 ] = V_149 ;
V_105 [ 7 ] = V_150 ;
V_105 [ 8 ] = 0 ;
V_105 [ 9 ] = 0 ;
V_9 = F_5 ( V_106 , V_151 ) ;
V_36 = F_3 ( V_3 , V_105 , V_9 ) ;
V_154:
F_14 ( V_105 ) ;
return V_36 ;
}
static int F_26 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_105 , int V_106 )
{
T_4 V_157 = F_18 (
F_27 ( V_104 , F_28 ( V_104 -> V_158 ) ) ) ;
T_4 V_159 = F_18 ( V_104 -> V_158 -> V_160 . V_161 ) ;
T_4 V_162 = F_18 ( 0x100 ) ;
memset ( V_105 , 0 , V_118 ) ;
V_105 [ 1 ] = V_163 ;
V_105 [ 3 ] = 0x3c ;
memcpy ( & V_105 [ 8 ] , & V_157 , sizeof( T_1 ) ) ;
memcpy ( & V_105 [ 20 ] , & V_159 , sizeof( T_1 ) ) ;
if ( V_159 )
memcpy ( & V_105 [ 24 ] , & V_162 , sizeof( T_1 ) ) ;
return F_3 ( V_3 , V_105 , 0x3c ) ;
}
static int F_29 ( struct V_103 * V_104 , struct V_2 * V_3 ,
int V_106 )
{
T_2 * V_105 ;
int V_36 ;
int V_9 ;
V_105 = F_30 ( V_151 , V_152 ) ;
if ( V_105 == NULL ) {
V_36 = - V_153 ;
goto V_164;
}
V_105 [ 1 ] = V_127 ;
V_105 [ 2 ] = 0x00 ;
V_105 [ 3 ] = 0x3C ;
V_105 [ 4 ] = 0x00 ;
V_105 [ 5 ] = 0x01 ;
V_105 [ 6 ] = 0x00 ;
V_9 = F_5 ( V_106 , V_151 ) ;
V_36 = F_3 ( V_3 , V_105 , V_9 ) ;
F_14 ( V_105 ) ;
V_164:
return V_36 ;
}
static int F_31 ( struct V_103 * V_104 , struct V_2 * V_3 ,
int V_106 )
{
int V_36 ;
int V_9 ;
T_2 * V_165 ;
V_165 = F_30 ( V_166 , V_152 ) ;
if ( V_165 == NULL ) {
V_36 = - V_153 ;
goto V_164;
}
V_165 [ 0 ] = V_167 ;
V_165 [ 3 ] = V_168 ;
V_165 [ 4 ] = V_167 ;
V_165 [ 5 ] = V_169 ;
V_165 [ 6 ] = V_170 ;
V_9 = F_5 ( V_106 , V_166 ) ;
V_36 = F_3 ( V_3 , V_165 , V_9 ) ;
F_14 ( V_165 ) ;
V_164:
return V_36 ;
}
static int F_32 ( struct V_103 * V_104 ,
struct V_2 * V_3 , int V_106 )
{
int V_36 ;
int V_9 ;
T_2 * V_165 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_171 * V_172 ;
T_2 V_173 ;
T_5 V_174 ;
V_165 = F_30 ( V_175 , V_152 ) ;
if ( V_165 == NULL )
return - V_153 ;
V_36 = F_33 ( V_108 , & V_172 ) ;
if ( V_36 < 0 )
goto V_176;
if ( V_36 != V_37 ) {
V_173 = V_177 ;
} else {
V_174 = ( V_172 -> V_178 [ 1 ] << 8 ) +
( V_172 -> V_178 [ 0 ] ) ;
V_173 = V_174 - V_179 ;
}
F_14 ( V_172 ) ;
V_165 [ 0 ] = V_169 ;
V_165 [ 3 ] = V_180 ;
V_165 [ 6 ] = 0x23 ;
V_165 [ 7 ] = 0x04 ;
V_165 [ 10 ] = V_173 ;
V_9 = F_5 ( V_106 , V_175 ) ;
V_36 = F_3 ( V_3 , V_165 , V_9 ) ;
V_176:
F_14 ( V_165 ) ;
return V_36 ;
}
static int F_34 ( struct V_103 * V_104 , struct V_2 * V_3 ,
int V_106 )
{
int V_36 ;
int V_9 ;
T_2 * V_165 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_171 * V_172 ;
T_1 V_181 ;
T_2 V_182 , V_183 ;
T_5 V_174 ;
V_165 = F_30 ( V_184 , V_152 ) ;
if ( V_165 == NULL )
return - V_153 ;
V_36 = F_33 ( V_108 , & V_172 ) ;
if ( V_36 < 0 )
goto V_176;
if ( V_36 != V_37 ) {
V_182 = V_177 ;
} else {
V_174 = ( V_172 -> V_178 [ 1 ] << 8 ) +
( V_172 -> V_178 [ 0 ] ) ;
V_182 = V_174 - V_179 ;
}
F_14 ( V_172 ) ;
V_36 = F_35 ( V_108 , V_185 , 0 , 0 ,
& V_181 ) ;
if ( V_36 != V_37 )
V_183 = V_177 ;
else
V_183 = ( V_181 & 0xFFFF ) - V_179 ;
V_165 [ 0 ] = V_170 ;
V_165 [ 3 ] = V_186 ;
V_165 [ 6 ] = 0x01 ;
V_165 [ 7 ] = 0x02 ;
V_165 [ 9 ] = V_182 ;
V_165 [ 11 ] = 0x01 ;
V_165 [ 12 ] = 0x01 ;
V_165 [ 13 ] = 0x02 ;
V_165 [ 15 ] = V_183 ;
V_9 = F_5 ( V_106 , V_184 ) ;
V_36 = F_3 ( V_3 , V_165 , V_9 ) ;
V_176:
F_14 ( V_165 ) ;
return V_36 ;
}
static int F_36 ( T_2 * V_22 , int V_135 , T_2 V_187 , T_2 V_188 ,
T_5 V_189 , T_5 V_190 )
{
if ( ( V_187 && V_135 < 8 ) || ( ! V_187 && V_135 < 4 ) )
return - V_191 ;
if ( V_187 ) {
V_22 [ 0 ] = ( V_189 & 0xFF00 ) >> 8 ;
V_22 [ 1 ] = ( V_189 & 0x00FF ) ;
V_22 [ 3 ] = 0x10 ;
V_22 [ 4 ] = V_188 ;
V_22 [ 5 ] = V_192 ;
V_22 [ 6 ] = ( V_190 & 0xFF00 ) >> 8 ;
V_22 [ 7 ] = ( V_190 & 0x00FF ) ;
} else {
V_22 [ 0 ] = ( V_189 & 0x00FF ) ;
V_22 [ 2 ] = 0x10 ;
V_22 [ 3 ] = ( V_190 & 0x00FF ) ;
}
return 0 ;
}
static int F_37 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_22 , int V_135 , T_2 V_188 )
{
int V_36 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_109 * V_110 ;
T_2 V_193 ;
T_1 V_194 ;
if ( V_188 == 0 && V_135 < V_195 )
return - V_191 ;
else if ( V_188 > 0 && V_135 < V_196 )
return - V_191 ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_193 = ( V_110 -> V_193 ) & 0x0F ;
V_194 = ( 1 << ( V_110 -> V_197 [ V_193 ] . V_198 ) ) ;
if ( V_188 == 0 ) {
T_4 V_199 = F_18 ( F_38 ( V_110 -> V_200 ) ) ;
T_4 V_201 = F_18 ( V_194 & 0x00FFFFFF ) ;
memcpy ( V_22 , & V_199 , sizeof( T_1 ) ) ;
memcpy ( & V_22 [ 4 ] , & V_201 , sizeof( T_1 ) ) ;
} else {
T_6 V_199 = F_39 ( F_38 ( V_110 -> V_200 ) ) ;
T_4 V_201 = F_18 ( V_194 ) ;
memcpy ( V_22 , & V_199 , sizeof( V_202 ) ) ;
memcpy ( & V_22 [ 12 ] , & V_201 , sizeof( T_1 ) ) ;
}
F_14 ( V_110 ) ;
return V_36 ;
}
static int F_40 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_22 ,
int V_135 )
{
if ( V_135 < V_203 )
return - V_191 ;
V_22 [ 0 ] = V_204 ;
V_22 [ 1 ] = V_205 ;
V_22 [ 2 ] = 0x0E ;
V_22 [ 3 ] = 0x12 ;
V_22 [ 5 ] = 0x40 ;
V_22 [ 8 ] = 0xFF ;
V_22 [ 9 ] = 0xFF ;
return 0 ;
}
static int F_41 ( struct V_103 * V_104 ,
struct V_2 * V_3 ,
T_2 * V_22 , int V_135 )
{
int V_36 = 0 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
T_1 V_181 ;
T_2 V_156 ;
if ( V_135 < V_206 )
return - V_191 ;
V_35 = F_35 ( V_108 , V_207 , 0 , 0 ,
& V_181 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_156 = V_181 & 0x00000001 ;
V_22 [ 0 ] = V_208 ;
V_22 [ 1 ] = V_209 ;
V_22 [ 2 ] = V_156 << 2 ;
return 0 ;
}
static int F_42 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_22 ,
int V_135 )
{
if ( V_135 < V_210 )
return - V_191 ;
V_22 [ 0 ] = V_211 ;
V_22 [ 1 ] = V_212 ;
return 0 ;
}
static int F_43 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_22 ,
int V_135 )
{
if ( V_135 < V_213 )
return - V_191 ;
V_22 [ 0 ] = V_214 ;
V_22 [ 1 ] = V_215 ;
V_22 [ 2 ] = 0x88 ;
return 0 ;
}
static int F_44 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_22 , int V_135 )
{
int V_36 ;
T_5 V_216 = 0 ;
T_5 V_217 , V_218 , V_219 ;
V_217 = V_216 + V_206 ;
V_218 = V_217 + V_203 ;
V_219 = V_218 + V_210 ;
V_36 = F_41 ( V_104 , V_3 , & V_22 [ V_216 ] ,
V_206 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_40 ( V_104 , V_3 , & V_22 [ V_217 ] ,
V_203 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_42 ( V_104 , V_3 , & V_22 [ V_218 ] ,
V_210 ) ;
if ( V_36 )
return V_36 ;
return F_43 ( V_104 , V_3 , & V_22 [ V_219 ] ,
V_213 ) ;
}
static inline int F_45 ( T_2 V_220 , T_2 V_188 )
{
if ( V_220 == V_221 ) {
return 8 * ( V_188 + 1 ) * V_222 ;
} else {
return 0 ;
}
}
static int F_46 ( struct V_103 * V_104 ,
struct V_2 * V_3 , T_2 * V_223 ,
T_5 V_106 , T_2 V_187 ,
int (* F_47)
( struct V_103 * ,
struct V_2 * V_3 , T_2 * , int ) ,
T_5 V_224 )
{
int V_36 ;
int V_9 ;
T_2 * V_225 ;
T_2 V_220 , V_188 ;
T_5 V_226 ;
int V_227 ;
T_5 V_216 ;
T_5 V_190 , V_228 , V_189 ;
V_220 = ( V_223 [ 1 ] & V_229 ) >> V_230 ;
V_188 = ( V_223 [ 1 ] & V_231 ) >> V_232 ;
V_227 = V_187 ? V_233 : V_234 ;
V_190 = F_45 ( V_220 , V_188 ) ;
V_226 = V_227 + V_190 + V_224 ;
V_189 = 3 + ( 3 * V_187 ) + V_190 + V_224 ;
V_228 = V_227 ;
V_216 = V_228 + V_190 ;
V_225 = F_30 ( V_226 , V_152 ) ;
if ( V_225 == NULL ) {
V_36 = - V_153 ;
goto V_164;
}
V_36 = F_36 ( & V_225 [ 0 ] , V_227 , V_187 ,
V_188 , V_189 , V_190 ) ;
if ( V_36 )
goto V_235;
if ( V_190 > 0 ) {
V_36 = F_37 ( V_104 , V_3 ,
& V_225 [ V_228 ] ,
V_190 , V_188 ) ;
if ( V_36 )
goto V_235;
}
V_36 = F_47 ( V_104 , V_3 , & V_225 [ V_216 ] ,
V_224 ) ;
if ( V_36 )
goto V_235;
V_9 = F_5 ( V_106 , V_226 ) ;
V_36 = F_3 ( V_3 , V_225 , V_9 ) ;
V_235:
F_14 ( V_225 ) ;
V_164:
return V_36 ;
}
static void F_48 ( T_2 * V_225 , struct V_109 * V_110 ,
T_2 V_236 )
{
T_2 V_193 ;
T_1 V_194 ;
V_202 V_237 ;
T_2 V_238 ;
T_2 V_239 [ 4 ] = { 0 , 0 , 1 , 2 } ;
T_6 V_240 ;
T_4 V_241 ;
T_4 V_201 ;
V_193 = ( V_110 -> V_193 ) & 0x0F ;
V_194 = ( 1 << ( V_110 -> V_197 [ V_193 ] . V_198 ) ) ;
V_237 = F_49 ( & V_110 -> V_242 ) - 1 ;
( V_110 -> V_117 ) ? ( V_238 = 0x01 ) : ( V_238 = 0 ) ;
if ( ! V_236 ) {
if ( V_237 > 0xFFFFFFFF )
V_237 = 0xFFFFFFFF ;
V_241 = F_18 ( V_237 ) ;
V_201 = F_18 ( V_194 ) ;
memcpy ( V_225 , & V_241 , sizeof( T_1 ) ) ;
memcpy ( & V_225 [ 4 ] , & V_201 , sizeof( T_1 ) ) ;
} else {
V_240 = F_39 ( V_237 ) ;
V_201 = F_18 ( V_194 ) ;
memcpy ( V_225 , & V_240 , sizeof( V_202 ) ) ;
memcpy ( & V_225 [ 8 ] , & V_201 , sizeof( T_1 ) ) ;
V_225 [ 12 ] = ( V_239 [ V_110 -> V_117 & 0x3 ] << 1 ) | V_238 ;
}
}
static int F_50 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 V_243 , T_2 V_244 , T_2 V_245 )
{
int V_36 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_140 * V_141 ;
int V_246 ;
unsigned V_247 = 0 ;
V_35 = F_25 ( V_108 , & V_141 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_246 = F_51 ( V_248 , ( int ) ( V_141 -> V_249 - 1 ) ) ;
F_14 ( V_141 ) ;
switch ( V_243 ) {
case V_250 :
if ( V_244 == 0 && V_245 == 0x1 )
V_247 = V_248 ;
if ( V_244 == 0 && V_245 == 0x0 )
V_247 = V_246 ;
break;
case V_251 :
if ( V_244 == 0 )
V_247 = V_248 ;
break;
case V_252 :
if ( V_244 == 0x0 )
V_247 = V_253 ;
else if ( V_244 == 0x1 )
V_247 = V_254 ;
else if ( V_244 == 0x2 )
V_247 = V_255 ;
break;
case V_256 :
if ( V_244 == 0x0 )
V_247 = F_51 ( V_248 , ( V_246 - 2 ) ) ;
else if ( V_244 == 0x1 )
V_247 = F_51 ( V_248 , ( V_246 - 1 ) ) ;
break;
case V_257 :
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
V_35 = F_52 ( V_108 , V_258 , V_247 , 0 ,
NULL ) ;
return F_11 ( V_3 , V_35 ) ;
}
static int F_53 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 V_259 )
{
struct V_260 V_261 ;
int V_35 ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_262 . V_263 = V_264 ;
V_261 . V_262 . V_265 [ 0 ] = F_54 ( V_259 | V_266 ) ;
V_35 = F_55 ( V_104 -> V_158 , & V_261 , NULL , 0 ) ;
return F_11 ( V_3 , V_35 ) ;
}
static int F_56 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 V_263 , T_1 V_267 , T_1 V_268 ,
T_2 V_259 )
{
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_260 V_261 ;
if ( V_3 -> V_10 > 0 ) {
return F_8 ( V_3 ,
V_42 ,
V_43 ,
V_46 ,
V_40 ) ;
}
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_262 . V_263 = V_269 ;
V_261 . V_270 . V_271 = F_54 ( ( V_267 / V_272 ) - 1 ) ;
V_261 . V_270 . V_268 = F_54 ( V_268 / V_272 ) ;
V_35 = F_57 ( V_108 -> V_273 , & V_261 , NULL ,
V_3 -> V_13 , V_267 , NULL , 0 ) ;
return F_11 ( V_3 , V_35 ) ;
}
static inline void F_58 ( T_2 * V_274 , T_2 V_187 ,
T_5 * V_275 , T_2 * V_188 )
{
if ( V_187 ) {
* V_275 = ( V_274 [ V_276 ] << 8 ) +
V_274 [ V_276 + 1 ] ;
* V_188 = V_274 [ V_277 ] &
V_278 ;
} else {
* V_275 = V_274 [ V_279 ] ;
}
}
static void F_59 ( struct V_103 * V_104 , T_2 * V_274 ,
T_5 V_280 , T_5 V_275 , T_2 V_188 )
{
T_5 V_281 ;
V_281 = V_275 / ( ( V_188 == 0 ) ?
V_282 : V_283 ) ;
if ( V_188 == 0 ) {
V_104 -> V_284 =
( V_274 [ V_280 + 1 ] << 16 ) +
( V_274 [ V_280 + 2 ] << 8 ) +
( V_274 [ V_280 + 3 ] ) ;
V_104 -> V_285 =
( V_274 [ V_280 + 5 ] << 16 ) +
( V_274 [ V_280 + 6 ] << 8 ) +
( V_274 [ V_280 + 7 ] ) ;
} else {
V_104 -> V_284 =
( ( ( V_202 ) V_274 [ V_280 + 0 ] ) << 56 ) +
( ( ( V_202 ) V_274 [ V_280 + 1 ] ) << 48 ) +
( ( ( V_202 ) V_274 [ V_280 + 2 ] ) << 40 ) +
( ( ( V_202 ) V_274 [ V_280 + 3 ] ) << 32 ) +
( ( ( V_202 ) V_274 [ V_280 + 4 ] ) << 24 ) +
( ( ( V_202 ) V_274 [ V_280 + 5 ] ) << 16 ) +
( ( ( V_202 ) V_274 [ V_280 + 6 ] ) << 8 ) +
( ( V_202 ) V_274 [ V_280 + 7 ] ) ;
V_104 -> V_285 =
( V_274 [ V_280 + 12 ] << 24 ) +
( V_274 [ V_280 + 13 ] << 16 ) +
( V_274 [ V_280 + 14 ] << 8 ) +
( V_274 [ V_280 + 15 ] ) ;
}
}
static int F_60 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_286 , T_2 V_287 )
{
int V_36 = 0 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
unsigned V_288 ;
switch ( V_287 ) {
case V_208 :
V_288 = ( ( V_286 [ 2 ] & V_289 ) ? 1 : 0 ) ;
V_35 = F_52 ( V_108 , V_207 , V_288 ,
0 , NULL ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
break;
case V_204 :
break;
case V_211 :
if ( ( V_286 [ 2 ] & 0x01 ) != 0 || ( V_286 [ 3 ] & 0x0F ) != 0 ) {
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 ,
V_290 ,
V_40 ) ;
break;
}
break;
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
return V_36 ;
}
static int F_61 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 , T_5 V_291 , T_2 V_292 ,
T_2 V_293 , T_2 V_187 )
{
int V_36 ;
T_2 * V_274 ;
T_5 V_275 ;
T_2 V_188 = 0 ;
T_5 V_7 , V_294 ;
T_2 V_287 ;
T_5 V_295 ;
V_274 = F_24 ( V_291 , V_152 ) ;
if ( V_274 == NULL ) {
V_36 = - V_153 ;
goto V_296;
}
V_36 = F_7 ( V_3 , V_274 , V_291 ) ;
if ( V_36 )
goto V_164;
F_58 ( V_274 , V_187 , & V_275 , & V_188 ) ;
V_7 = ( V_187 ) ? ( V_297 ) : ( V_298 ) ;
if ( V_275 != 0 ) {
F_59 ( V_104 , V_274 , V_7 , V_275 , V_188 ) ;
V_7 += V_275 ;
}
V_294 = V_7 ;
do {
V_287 = V_274 [ V_7 ] & V_299 ;
V_295 = V_274 [ V_7 + 1 ] + 2 ;
if ( ( V_287 != V_208 ) &&
( V_287 != V_204 ) &&
( V_287 != V_211 ) ) {
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 ,
V_46 ,
V_40 ) ;
goto V_164;
}
V_7 += V_295 ;
} while ( V_7 < V_291 );
V_7 = V_294 ;
do {
V_287 = V_274 [ V_7 ] & V_299 ;
V_295 = V_274 [ V_7 + 1 ] + 2 ;
V_36 = F_60 ( V_104 , V_3 , & V_274 [ V_7 ] ,
V_287 ) ;
if ( V_36 )
break;
V_7 += V_295 ;
} while ( V_7 < V_291 );
V_164:
F_14 ( V_274 ) ;
V_296:
return V_36 ;
}
static int F_62 ( struct V_103 * V_104 ,
struct V_2 * V_3 )
{
int V_36 = 0 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
T_2 V_193 ;
if ( V_104 -> V_284 == 0 || V_104 -> V_285 == 0 ) {
struct V_109 * V_110 ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
if ( V_104 -> V_284 == 0 )
V_104 -> V_284 = F_38 ( V_110 -> V_200 ) ;
if ( V_104 -> V_285 == 0 ) {
V_193 = ( V_110 -> V_193 ) & 0x0F ;
V_104 -> V_285 =
( 1 << ( V_110 -> V_197 [ V_193 ] . V_198 ) ) ;
}
F_14 ( V_110 ) ;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_3 , T_2 V_135 ,
T_2 V_300 , T_2 * V_301 )
{
int V_36 ;
T_2 * V_274 ;
T_2 V_302 , V_303 ;
V_274 = F_24 ( V_135 , V_152 ) ;
if ( V_274 == NULL ) {
V_36 = - V_153 ;
goto V_296;
}
V_36 = F_7 ( V_3 , V_274 , V_135 ) ;
if ( V_36 )
goto V_164;
if ( ( V_274 [ V_304 ] &
V_305 ) != 0 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_164;
}
if ( V_135 == V_306 &&
( V_274 [ V_307 ] & 0x0F ) != 0 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_164;
}
V_302 = V_274 [ V_308 ] &
V_309 ;
V_303 = ( V_302 << 2 ) | V_300 ;
switch ( V_303 ) {
case 0 :
* V_301 = 0 ;
break;
case 2 :
* V_301 = 1 ;
break;
case 3 :
* V_301 = 2 ;
break;
case 7 :
* V_301 = 3 ;
break;
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
V_164:
F_14 ( V_274 ) ;
V_296:
return V_36 ;
}
static int F_64 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 V_310 )
{
int V_36 ;
int V_35 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_109 * V_110 ;
T_2 V_6 ;
T_2 V_193 , V_311 ;
T_2 V_312 = 0xFF ;
T_1 V_265 = 0 ;
struct V_260 V_261 ;
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_193 = ( V_110 -> V_193 ) & 0x0F ;
V_311 = V_110 -> V_311 ;
for ( V_6 = 0 ; V_6 < V_311 ; V_6 ++ ) {
if ( V_104 -> V_285 == ( 1 << ( V_110 -> V_197 [ V_6 ] . V_198 ) ) ) {
V_312 = V_6 ;
break;
}
}
if ( V_312 > 0x0F ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_290 ,
V_40 ) ;
}
if ( V_104 -> V_284 != F_38 ( V_110 -> V_200 ) ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_290 ,
V_40 ) ;
}
V_265 |= V_310 << 5 ;
V_265 |= V_312 & 0x0F ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_313 . V_263 = V_314 ;
V_261 . V_313 . V_315 = F_54 ( V_104 -> V_116 ) ;
V_261 . V_313 . V_265 = F_54 ( V_265 ) ;
V_35 = F_55 ( V_108 -> V_273 , & V_261 , NULL , 0 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
F_14 ( V_110 ) ;
return V_36 ;
}
static inline T_1 F_65 ( struct V_2 * V_3 ,
struct V_316 * V_317 ,
T_1 V_318 )
{
if ( V_3 -> V_10 > 0 )
return V_3 -> V_10 ;
else if ( V_317 -> V_9 > V_318 )
return ( ( V_317 -> V_9 - 1 ) / V_318 ) + 1 ;
else
return 1 ;
}
static T_5 F_66 ( struct V_103 * V_104 ,
struct V_316 * V_317 )
{
T_5 V_319 = 0 ;
if ( V_317 -> V_320 > 0 )
V_319 |= V_321 ;
return V_319 ;
}
static int F_67 ( struct V_103 * V_104 , struct V_2 * V_3 ,
struct V_316 * V_317 , T_2 V_322 )
{
int V_35 = V_37 ;
T_1 V_323 ;
V_202 V_324 ;
V_202 V_325 ;
T_1 V_326 ;
T_1 V_6 = 0 ;
V_202 V_327 = 0 ;
void T_7 * V_328 ;
struct V_260 V_261 ;
T_2 V_263 = ( V_322 ? V_329 : V_330 ) ;
T_5 V_319 ;
T_1 V_318 = F_28 ( V_104 -> V_158 ) ;
V_323 = F_65 ( V_3 , V_317 , V_318 ) ;
for ( V_6 = 0 ; V_6 < V_323 ; V_6 ++ ) {
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
if ( V_3 -> V_10 > 0 ) {
struct V_11 V_12 ;
V_326 = F_4 ( & V_12 , V_3 -> V_13 +
V_6 * sizeof( struct V_11 ) ,
sizeof( struct V_11 ) ) ;
if ( V_326 )
return - V_14 ;
V_324 = V_12 . V_15 ;
V_325 = V_324 >> V_104 -> V_331 ;
V_328 = V_12 . V_16 ;
} else {
V_325 = F_5 ( ( V_202 ) V_318 ,
( V_317 -> V_9 - V_327 ) ) ;
V_324 = V_325 << V_104 -> V_331 ;
V_328 = V_3 -> V_13 +
( ( 1 << V_104 -> V_331 ) * V_327 ) ;
}
V_261 . V_332 . V_263 = V_263 ;
V_261 . V_332 . V_315 = F_54 ( V_104 -> V_116 ) ;
V_261 . V_332 . V_333 = F_68 ( V_317 -> V_334 + V_327 ) ;
V_261 . V_332 . V_335 = F_69 ( V_325 - 1 ) ;
V_319 = F_66 ( V_104 , V_317 ) ;
V_261 . V_332 . V_319 = F_69 ( V_319 ) ;
if ( F_70 ( V_104 -> V_336 ) - V_325 <
V_317 -> V_334 + V_327 ) {
V_35 = V_64 ;
break;
}
V_35 = F_57 ( V_104 -> V_158 , & V_261 , NULL ,
V_328 , V_324 , NULL , 0 ) ;
if ( V_35 )
break;
V_327 += V_325 ;
}
return F_11 ( V_3 , V_35 ) ;
}
static int F_71 ( struct V_103 * V_104 , struct V_2 * V_3 , T_2 V_322 ,
T_2 * V_223 )
{
int V_36 = 0 ;
struct V_316 V_317 = { 0 , } ;
T_2 V_263 = V_223 [ 0 ] ;
V_202 V_337 ;
V_202 V_338 = 0 ;
struct V_11 V_12 ;
int V_6 ;
T_3 V_339 ;
switch ( V_263 ) {
case V_340 :
case V_341 :
break;
default:
V_317 . V_320 = V_223 [ 1 ] & 0x8 ;
V_317 . V_310 = ( V_223 [ 1 ] & 0xe0 ) >> 5 ;
if ( V_317 . V_310 && ! V_104 -> V_342 ) {
return F_8 ( V_3 ,
V_42 ,
V_43 ,
V_46 ,
V_40 ) ;
}
}
switch ( V_263 ) {
case V_340 :
case V_341 :
V_317 . V_334 = F_1 ( & V_223 [ 1 ] ) ;
V_317 . V_9 = V_223 [ 4 ] ;
if ( V_317 . V_9 == 0 )
V_317 . V_9 = 256 ;
break;
case V_343 :
case V_344 :
V_317 . V_334 = F_2 ( & V_223 [ 2 ] ) ;
V_317 . V_9 = F_72 ( & V_223 [ 7 ] ) ;
break;
case V_345 :
case V_346 :
V_317 . V_334 = F_2 ( & V_223 [ 2 ] ) ;
V_317 . V_9 = F_2 ( & V_223 [ 6 ] ) ;
break;
case V_347 :
case V_348 :
V_317 . V_334 = F_73 ( & V_223 [ 2 ] ) ;
V_317 . V_9 = F_2 ( & V_223 [ 10 ] ) ;
break;
default:
V_36 = - V_349 ;
goto V_296;
}
if ( V_3 -> V_10 > 0 ) {
for ( V_6 = 0 ; V_6 < V_3 -> V_10 ; V_6 ++ ) {
V_339 = F_4 ( & V_12 , V_3 -> V_13 +
V_6 * sizeof( struct V_11 ) ,
sizeof( struct V_11 ) ) ;
if ( V_339 )
return - V_14 ;
V_338 += V_12 . V_15 ;
if ( V_12 . V_15 % ( 1 << V_104 -> V_331 ) != 0 ) {
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 ,
V_290 ,
V_40 ) ;
goto V_296;
}
}
} else {
V_338 = V_3 -> V_350 ;
}
V_337 = F_5 ( ( ( V_202 ) V_3 -> V_350 ) , V_338 ) ;
if ( V_337 != ( V_317 . V_9 << V_104 -> V_331 ) ) {
V_36 = - V_191 ;
goto V_296;
}
if ( V_317 . V_9 == 0 )
goto V_296;
V_36 = F_67 ( V_104 , V_3 , & V_317 , V_322 ) ;
if ( V_36 )
goto V_296;
V_296:
return V_36 ;
}
static int F_74 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 = 0 ;
T_2 V_351 ;
T_2 V_287 ;
int V_106 ;
T_2 * V_105 ;
V_351 = V_223 [ 1 ] & 0x01 ;
V_287 = V_223 [ 2 ] ;
V_106 = F_72 ( & V_223 [ 3 ] ) ;
V_105 = F_24 ( F_51 ( V_106 , V_118 ) ,
V_152 ) ;
if ( V_105 == NULL ) {
V_36 = - V_153 ;
goto V_164;
}
if ( V_351 == 0 ) {
if ( V_287 == V_352 ) {
V_36 = F_12 ( V_104 , V_3 ,
V_105 , V_106 ) ;
} else {
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 ,
V_46 ,
V_40 ) ;
}
} else {
switch ( V_287 ) {
case V_353 :
V_36 = F_15 ( V_104 , V_3 ,
V_105 , V_106 ) ;
break;
case V_354 :
V_36 = F_16 ( V_104 , V_3 , V_105 ,
V_106 ) ;
break;
case V_355 :
V_36 = F_17 ( V_104 , V_3 , V_105 ,
V_106 ) ;
break;
case V_356 :
V_36 = F_23 ( V_104 , V_3 , V_106 ) ;
break;
case V_163 :
V_36 = F_26 ( V_104 , V_3 , V_105 ,
V_106 ) ;
break;
case V_357 :
V_36 = F_29 ( V_104 , V_3 , V_106 ) ;
break;
default:
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 ,
V_46 ,
V_40 ) ;
break;
}
}
F_14 ( V_105 ) ;
V_164:
return V_36 ;
}
static int F_75 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 ;
T_5 V_106 ;
T_2 V_243 ;
T_2 V_287 ;
if ( V_223 [ 1 ] != V_358 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
V_287 = V_223 [ 2 ] & V_359 ;
V_243 = ( V_223 [ 2 ] & V_360 ) >> V_361 ;
if ( V_243 != V_362 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
V_106 = F_72 ( & V_223 [ 7 ] ) ;
switch ( V_287 ) {
case V_167 :
V_36 = F_31 ( V_104 , V_3 , V_106 ) ;
break;
case V_169 :
V_36 = F_32 ( V_104 , V_3 , V_106 ) ;
break;
case V_170 :
V_36 = F_34 ( V_104 , V_3 , V_106 ) ;
break;
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
V_296:
return V_36 ;
}
static int F_76 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
T_2 V_187 = 0 ;
T_5 V_291 ;
T_2 V_363 ;
T_2 V_364 ;
V_363 = V_223 [ 1 ] & V_365 ;
V_364 = V_223 [ 1 ] & V_366 ;
if ( V_223 [ 0 ] == V_367 ) {
V_291 = V_223 [ 4 ] ;
} else {
V_291 = V_223 [ 7 ] ;
V_187 = 1 ;
}
if ( V_291 != 0 ) {
return F_61 ( V_104 , V_3 , V_223 , V_291 ,
V_363 , V_364 , V_187 ) ;
}
return 0 ;
}
static int F_77 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 = 0 ;
T_5 V_106 ;
T_2 V_187 = 0 ;
if ( V_223 [ 0 ] == V_368 ) {
V_106 = V_223 [ 4 ] ;
} else {
V_106 = F_72 ( & V_223 [ 7 ] ) ;
V_187 = 1 ;
}
if ( ( V_223 [ 2 ] & V_369 ) !=
V_370 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
switch ( V_223 [ 2 ] & V_371 ) {
case V_208 :
V_36 = F_46 ( V_104 , V_3 , V_223 , V_106 ,
V_187 ,
& F_41 ,
V_206 ) ;
break;
case V_204 :
V_36 = F_46 ( V_104 , V_3 , V_223 , V_106 ,
V_187 ,
& F_40 ,
V_203 ) ;
break;
case V_211 :
V_36 = F_46 ( V_104 , V_3 , V_223 , V_106 ,
V_187 ,
& F_42 ,
V_210 ) ;
break;
case V_214 :
V_36 = F_46 ( V_104 , V_3 , V_223 , V_106 ,
V_187 ,
& F_43 ,
V_213 ) ;
break;
case V_372 :
V_36 = F_46 ( V_104 , V_3 , V_223 , V_106 ,
V_187 ,
& F_44 ,
V_373 ) ;
break;
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
V_296:
return V_36 ;
}
static int F_78 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 , T_2 V_236 )
{
int V_36 ;
int V_35 ;
T_1 V_106 ;
T_1 V_226 ;
T_1 V_9 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_109 * V_110 ;
T_2 * V_225 ;
if ( V_236 ) {
V_106 = F_2 ( & V_223 [ 10 ] ) ;
V_226 = V_374 ;
} else {
V_106 = V_375 ;
V_226 = V_375 ;
}
V_35 = F_13 ( V_108 , V_104 -> V_116 , & V_110 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_225 = F_30 ( V_226 , V_152 ) ;
if ( V_225 == NULL ) {
V_36 = - V_153 ;
goto V_376;
}
F_48 ( V_225 , V_110 , V_236 ) ;
V_9 = F_5 ( V_106 , V_226 ) ;
V_36 = F_3 ( V_3 , V_225 , V_9 ) ;
F_14 ( V_225 ) ;
V_376:
F_14 ( V_110 ) ;
return V_36 ;
}
static int F_79 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 ;
int V_35 ;
T_1 V_106 , V_9 , V_226 ;
T_2 * V_225 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_140 * V_141 ;
T_1 V_377 , V_378 ;
T_2 V_379 = V_380 ;
T_4 V_201 ;
switch ( V_223 [ 2 ] ) {
default:
return F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
case V_381 :
case V_382 :
case V_383 :
V_35 = F_25 ( V_108 , & V_141 ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
if ( V_36 )
return V_36 ;
V_377 = F_80 ( V_141 -> V_384 ) * V_385 ;
V_226 = V_377 + V_386 ;
V_106 = F_2 ( & V_223 [ 6 ] ) ;
if ( V_106 < V_226 ) {
V_36 = F_8 ( V_3 ,
V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_376;
}
V_225 = F_30 ( V_226 , V_152 ) ;
if ( V_225 == NULL ) {
V_36 = - V_153 ;
goto V_376;
}
for ( V_378 = 0 ; V_378 < F_80 ( V_141 -> V_384 ) ; V_378 ++ ) {
T_6 V_131 = F_39 ( V_378 ) ;
memcpy ( & V_225 [ V_379 ] , & V_131 , sizeof( V_202 ) ) ;
V_379 += V_385 ;
}
V_201 = F_18 ( V_377 ) ;
memcpy ( V_225 , & V_201 , sizeof( T_1 ) ) ;
}
V_9 = F_5 ( V_106 , V_226 ) ;
V_36 = F_3 ( V_3 , V_225 , V_9 ) ;
F_14 ( V_225 ) ;
V_376:
F_14 ( V_141 ) ;
return V_36 ;
}
static int F_81 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 ;
T_2 V_106 , V_9 , V_226 ;
T_2 V_387 ;
T_2 * V_225 ;
V_387 = V_223 [ 1 ] & 0x01 ;
V_106 = V_223 [ 4 ] ;
V_226 = ( ( V_387 ) ? ( V_23 ) :
( V_388 ) ) ;
V_225 = F_30 ( V_226 , V_152 ) ;
if ( V_225 == NULL ) {
V_36 = - V_153 ;
goto V_296;
}
if ( V_387 ) {
V_225 [ 0 ] = V_32 ;
V_225 [ 1 ] = V_38 ;
V_225 [ 2 ] = V_39 ;
V_225 [ 3 ] = V_40 ;
} else {
V_225 [ 0 ] = V_389 ;
V_225 [ 2 ] = V_38 ;
V_225 [ 7 ] = V_390 ;
V_225 [ 12 ] = V_39 ;
V_225 [ 13 ] = V_40 ;
}
V_9 = F_5 ( V_106 , V_226 ) ;
V_36 = F_3 ( V_3 , V_225 , V_9 ) ;
F_14 ( V_225 ) ;
V_296:
return V_36 ;
}
static int F_82 ( struct V_103 * V_104 ,
struct V_2 * V_3 ,
T_2 * V_223 )
{
return F_8 ( V_3 , V_42 ,
V_43 , V_44 ,
V_40 ) ;
}
static int F_83 ( struct V_103 * V_104 ,
struct V_2 * V_3 )
{
int V_35 ;
struct V_260 V_261 ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_262 . V_263 = V_391 ;
V_261 . V_262 . V_315 = F_54 ( V_104 -> V_116 ) ;
V_35 = F_55 ( V_104 -> V_158 , & V_261 , NULL , 0 ) ;
return F_11 ( V_3 , V_35 ) ;
}
static int F_84 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
T_2 V_392 , V_244 , V_243 , V_393 , V_245 ;
V_392 = V_223 [ 1 ] & 0x01 ;
V_244 = V_223 [ 3 ] & 0x0f ;
V_243 = ( V_223 [ 4 ] & 0xf0 ) >> 4 ;
V_393 = V_223 [ 4 ] & 0x04 ;
V_245 = V_223 [ 4 ] & 0x01 ;
if ( V_392 != 0 ) {
return F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
} else {
if ( V_393 == 0 ) {
int V_36 = F_83 ( V_104 , V_3 ) ;
if ( V_36 )
return V_36 ;
}
return F_50 ( V_104 , V_3 , V_243 , V_244 , V_245 ) ;
}
}
static int F_85 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 ;
T_2 V_394 = 0 ;
T_2 V_301 = 0 ;
T_2 V_300 , V_395 , V_396 ;
V_300 = ( V_223 [ 1 ] & 0xc0 ) >> 6 ;
V_395 = V_223 [ 1 ] & 0x20 ;
V_396 = V_223 [ 1 ] & 0x10 ;
if ( V_396 != 0 ) {
if ( V_300 != 0 ) {
if ( V_395 == 0 )
V_394 = V_397 ;
else
V_394 = V_306 ;
}
} else if ( V_396 == 0 && V_300 != 0 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
if ( V_394 > 0 ) {
V_36 = F_63 ( V_3 , V_394 ,
V_300 , & V_301 ) ;
if ( V_36 )
goto V_296;
}
V_36 = F_53 ( V_104 , V_3 , 0 ) ;
V_36 = F_62 ( V_104 , V_3 ) ;
if ( V_36 )
goto V_296;
V_36 = F_64 ( V_104 , V_3 , V_301 ) ;
V_296:
return V_36 ;
}
static int F_86 ( struct V_103 * V_104 ,
struct V_2 * V_3 ,
T_2 * V_223 )
{
struct V_107 * V_108 = V_104 -> V_108 ;
if ( ! ( F_19 ( & V_108 -> V_132 -> V_398 ) & V_399 ) )
return F_8 ( V_3 , V_42 ,
V_68 , V_69 ,
V_40 ) ;
else
return F_8 ( V_3 , V_24 , V_38 , 0 , 0 ) ;
}
static int F_87 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
int V_36 = 0 ;
T_1 V_400 , V_401 ;
T_2 V_259 , V_402 ;
V_401 = F_1 ( & V_223 [ 6 ] ) ;
if ( V_401 % V_272 != 0 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
V_259 = V_223 [ 2 ] ;
if ( V_259 > V_403 ) {
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
goto V_296;
}
V_402 = V_223 [ 1 ] & 0x1f ;
V_400 = F_1 ( & V_223 [ 3 ] ) ;
switch ( V_402 ) {
case V_404 :
V_36 = F_56 ( V_104 , V_3 , V_269 ,
V_401 , V_400 ,
V_259 ) ;
if ( V_36 )
goto V_296;
V_36 = F_53 ( V_104 , V_3 , V_259 ) ;
break;
case V_405 :
V_36 = F_56 ( V_104 , V_3 , V_269 ,
V_401 , V_400 ,
V_259 ) ;
break;
case V_406 :
V_36 = F_53 ( V_104 , V_3 , V_259 ) ;
break;
default:
V_36 = F_8 ( V_3 , V_42 ,
V_43 , V_46 ,
V_40 ) ;
break;
}
V_296:
return V_36 ;
}
static int F_88 ( struct V_103 * V_104 , struct V_2 * V_3 ,
T_2 * V_223 )
{
struct V_407 * V_408 ;
struct V_409 * V_410 ;
struct V_260 V_261 ;
int V_6 , V_35 , V_36 ;
T_5 V_411 , V_412 ;
V_412 = F_72 ( & V_223 [ 7 ] ) ;
if ( ! V_412 )
return - V_191 ;
V_408 = F_24 ( V_412 , V_152 ) ;
if ( ! V_408 )
return - V_153 ;
V_36 = F_7 ( V_3 , V_408 , V_412 ) ;
if ( V_36 )
goto V_296;
V_411 = F_89 ( V_408 -> V_413 ) >> 4 ;
if ( ! V_411 || V_411 > 256 ) {
V_36 = - V_191 ;
goto V_296;
}
V_410 = F_90 ( V_411 , sizeof( * V_410 ) , V_152 ) ;
if ( ! V_410 ) {
V_36 = - V_153 ;
goto V_296;
}
for ( V_6 = 0 ; V_6 < V_411 ; V_6 ++ ) {
V_410 [ V_6 ] . V_414 = F_54 ( F_91 ( V_408 -> V_415 [ V_6 ] . V_414 ) ) ;
V_410 [ V_6 ] . V_333 = F_68 ( F_92 ( V_408 -> V_415 [ V_6 ] . V_333 ) ) ;
V_410 [ V_6 ] . V_416 = 0 ;
}
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_417 . V_263 = V_418 ;
V_261 . V_417 . V_315 = F_54 ( V_104 -> V_116 ) ;
V_261 . V_417 . V_419 = F_54 ( V_411 - 1 ) ;
V_261 . V_417 . V_420 = F_54 ( V_421 ) ;
V_35 = F_55 ( V_104 -> V_158 , & V_261 , V_410 ,
V_411 * sizeof( * V_410 ) ) ;
V_36 = F_11 ( V_3 , V_35 ) ;
F_14 ( V_410 ) ;
V_296:
F_14 ( V_408 ) ;
return V_36 ;
}
static int F_93 ( struct V_103 * V_104 , struct V_2 * V_3 )
{
T_2 V_223 [ V_422 ] ;
int V_326 ;
unsigned int V_263 ;
if ( V_3 -> V_423 == NULL )
return - V_424 ;
if ( F_4 ( V_223 , V_3 -> V_423 , V_3 -> V_425 ) )
return - V_14 ;
V_326 = F_11 ( V_3 , V_37 ) ;
if ( V_326 )
return V_326 ;
V_263 = V_223 [ 0 ] ;
switch ( V_263 ) {
case V_341 :
case V_344 :
case V_346 :
case V_348 :
V_326 = F_71 ( V_104 , V_3 , 0 , V_223 ) ;
break;
case V_340 :
case V_343 :
case V_345 :
case V_347 :
V_326 = F_71 ( V_104 , V_3 , 1 , V_223 ) ;
break;
case V_426 :
V_326 = F_74 ( V_104 , V_3 , V_223 ) ;
break;
case V_427 :
V_326 = F_75 ( V_104 , V_3 , V_223 ) ;
break;
case V_367 :
case V_428 :
V_326 = F_76 ( V_104 , V_3 , V_223 ) ;
break;
case V_368 :
case V_429 :
V_326 = F_77 ( V_104 , V_3 , V_223 ) ;
break;
case V_430 :
V_326 = F_78 ( V_104 , V_3 , V_223 , 0 ) ;
break;
case V_431 :
switch ( V_223 [ 1 ] ) {
case V_432 :
V_326 = F_78 ( V_104 , V_3 , V_223 , 1 ) ;
break;
default:
goto V_296;
}
break;
case V_433 :
V_326 = F_79 ( V_104 , V_3 , V_223 ) ;
break;
case V_434 :
V_326 = F_81 ( V_104 , V_3 , V_223 ) ;
break;
case V_435 :
case V_436 :
V_326 = F_82 ( V_104 , V_3 , V_223 ) ;
break;
case V_437 :
V_326 = F_84 ( V_104 , V_3 , V_223 ) ;
break;
case V_438 :
V_326 = F_83 ( V_104 , V_3 ) ;
break;
case V_439 :
V_326 = F_85 ( V_104 , V_3 , V_223 ) ;
break;
case V_440 :
V_326 = F_86 ( V_104 , V_3 , V_223 ) ;
break;
case V_441 :
V_326 = F_87 ( V_104 , V_3 , V_223 ) ;
break;
case V_442 :
V_326 = F_88 ( V_104 , V_3 , V_223 ) ;
break;
default:
V_296:
V_326 = F_8 ( V_3 , V_42 ,
V_43 , V_44 ,
V_40 ) ;
break;
}
return V_326 ;
}
int F_94 ( struct V_103 * V_104 , struct V_2 T_7 * V_443 )
{
struct V_2 V_3 ;
int V_326 ;
if ( ! F_95 ( V_444 ) )
return - V_445 ;
if ( F_4 ( & V_3 , V_443 , sizeof( V_3 ) ) )
return - V_14 ;
if ( V_3 . V_446 != 'S' )
return - V_191 ;
if ( V_3 . V_425 > V_422 )
return - V_191 ;
V_326 = F_93 ( V_104 , & V_3 ) ;
if ( V_326 < 0 )
return V_326 ;
if ( F_6 ( V_443 , & V_3 , sizeof( V_447 ) ) > 0 )
return - V_14 ;
return 0 ;
}
int F_96 ( int T_7 * V_448 )
{
return F_97 ( V_449 , V_448 ) ;
}
