int F_1 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( ( ( ( V_1 [ V_3 ] ) & 0x7f ) == 2 ) || ( ( ( V_1 [ V_3 ] ) & 0x7f ) == 4 ) ||
( ( ( V_1 [ V_3 ] ) & 0x7f ) == 11 ) || ( ( ( V_1 [ V_3 ] ) & 0x7f ) == 22 ) )
return true ;
}
return false ;
}
int F_2 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( ( ( ( V_1 [ V_3 ] ) & 0x7f ) != 2 ) && ( ( ( V_1 [ V_3 ] ) & 0x7f ) != 4 ) &&
( ( ( V_1 [ V_3 ] ) & 0x7f ) != 11 ) && ( ( ( V_1 [ V_3 ] ) & 0x7f ) != 22 ) )
return false ;
}
return true ;
}
unsigned char F_3 ( unsigned char V_4 )
{
unsigned char V_5 ;
switch ( V_4 ) {
case V_6 :
V_5 = V_7 ;
break;
case V_8 :
case V_9 :
V_5 = V_10 ;
break;
case V_11 :
V_5 = V_12 ;
break;
case V_13 :
case V_14 :
V_5 = V_15 ;
break;
case V_16 :
case V_17 :
V_5 = V_18 ;
break;
case V_19 :
V_5 = V_20 ;
break;
default:
V_5 = V_12 ;
break;
}
return V_5 ;
}
T_1 F_4 ( struct V_21 * V_22 , unsigned char * V_1 , int V_2 )
{
T_1 V_4 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_24 -> V_29 > 14 ) {
if ( V_27 -> V_30 )
V_4 = V_14 ;
V_4 |= V_8 ;
} else {
if ( V_27 -> V_30 )
V_4 = V_13 ;
if ( ( F_2 ( V_1 , V_2 ) ) == true )
V_4 |= V_6 ;
else if ( ( F_1 ( V_1 , V_2 ) ) == true )
V_4 |= V_11 ;
else
V_4 |= V_9 ;
}
return V_4 ;
}
unsigned char F_5 ( unsigned char V_1 )
{
unsigned char V_31 = 0 ;
switch ( V_1 & 0x7f ) {
case 0 :
V_31 = V_32 ;
break;
case 1 :
V_31 = V_33 ;
break;
case 2 :
V_31 = V_34 ;
break;
case 3 :
V_31 = V_35 ;
break;
case 4 :
V_31 = V_36 ;
break;
case 5 :
V_31 = V_37 ;
break;
case 6 :
V_31 = V_38 ;
break;
case 7 :
V_31 = V_39 ;
break;
case 8 :
V_31 = V_40 ;
break;
case 9 :
V_31 = V_41 ;
break;
case 10 :
V_31 = V_42 ;
break;
case 11 :
V_31 = V_43 ;
break;
}
return V_31 ;
}
int F_6 ( struct V_21 * V_22 , unsigned char V_1 )
{
int V_3 ;
unsigned char V_31 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
V_31 = V_24 -> V_45 [ V_3 ] ;
if ( ( V_31 != 0xff ) && ( V_31 != 0xfe ) ) {
if ( V_1 == F_5 ( V_31 ) )
return true ;
}
}
return false ;
}
unsigned int F_7 ( struct V_21 * V_22 , unsigned char * V_46 )
{
int V_3 ;
unsigned char V_1 ;
unsigned int V_47 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
V_1 = V_24 -> V_48 [ V_3 ] ;
switch ( V_1 ) {
case 0xff :
return V_47 ;
case 0xfe :
continue;
default:
V_1 = F_5 ( V_1 ) ;
if ( F_6 ( V_22 , V_1 ) == true )
V_1 |= V_49 ;
V_46 [ V_47 ] = V_1 ;
V_47 ++ ;
break;
}
}
return V_47 ;
}
void F_8 ( struct V_21 * V_22 , unsigned char * V_50 , int * V_51 )
{
unsigned char V_52 [ V_44 ] ;
memset ( V_52 , 0 , V_44 ) ;
* V_51 = F_7 ( V_22 , V_52 ) ;
memcpy ( V_50 , V_52 , * V_51 ) ;
}
void F_9 ( struct V_21 * V_53 , T_1 * V_54 )
{
T_1 V_3 ;
T_1 V_1 ;
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
V_1 = V_54 [ V_3 ] & 0x7f ;
switch ( V_1 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_38 :
case V_40 :
V_54 [ V_3 ] |= V_49 ;
break;
default:
break;
}
}
}
void F_10 ( T_1 * V_56 , T_2 V_57 )
{
T_1 V_3 ;
T_1 V_1 ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ ) {
V_1 = V_56 [ V_3 ] & 0x7f ;
switch ( V_1 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
V_56 [ V_3 ] |= V_49 ;
break;
}
}
}
void F_11 ( struct V_21 * V_22 )
{
T_1 V_58 = true ;
F_12 ( V_22 , V_59 , ( T_1 * ) ( & V_58 ) ) ;
}
void F_13 ( struct V_21 * V_22 )
{
T_1 V_58 = false ;
F_12 ( V_22 , V_59 , ( T_1 * ) ( & V_58 ) ) ;
}
void F_14 ( struct V_21 * V_22 , unsigned long V_60 , T_1 V_61 )
{
if ( V_61 == true )
F_12 ( V_22 , V_62 , ( T_1 * ) ( & V_60 ) ) ;
else
F_12 ( V_22 , V_63 , ( T_1 * ) ( & V_60 ) ) ;
}
static void F_15 ( struct V_21 * V_22 , T_1 type )
{
F_12 ( V_22 , V_64 , ( T_1 * ) ( & type ) ) ;
}
void F_16 ( struct V_21 * V_22 , T_1 type )
{
F_15 ( V_22 , type ) ;
}
inline T_1 F_17 ( struct V_21 * V_65 )
{
return F_18 ( V_65 ) -> V_66 ;
}
inline void F_19 ( struct V_21 * V_65 , T_1 V_67 )
{
F_18 ( V_65 ) -> V_66 = V_67 ;
}
inline T_1 F_20 ( struct V_21 * V_65 )
{
return F_18 ( V_65 ) -> V_68 ;
}
inline void F_21 ( struct V_21 * V_65 , T_1 V_69 )
{
F_18 ( V_65 ) -> V_68 = V_69 ;
}
inline T_1 F_22 ( struct V_21 * V_65 )
{
return F_18 ( V_65 ) -> V_70 ;
}
inline void F_23 ( struct V_21 * V_65 , T_1 V_71 )
{
F_18 ( V_65 ) -> V_70 = V_71 ;
}
void F_24 ( struct V_21 * V_22 , unsigned char V_72 )
{
F_25 ( & F_18 ( V_22 ) -> V_73 ) ;
F_19 ( V_22 , V_72 ) ;
F_26 ( V_22 , V_72 ) ;
F_27 ( & F_18 ( V_22 ) -> V_73 ) ;
}
void F_28 ( struct V_21 * V_22 , unsigned short V_74 , unsigned char V_75 )
{
F_25 ( & F_18 ( V_22 ) -> V_76 ) ;
F_21 ( V_22 , V_74 ) ;
F_23 ( V_22 , V_75 ) ;
F_29 ( V_22 , (enum V_77 ) V_74 ,
V_75 ) ;
F_27 ( & F_18 ( V_22 ) -> V_76 ) ;
}
void F_30 ( struct V_21 * V_22 , unsigned char V_72 ,
unsigned char V_75 , unsigned short V_74 )
{
T_1 V_78 ;
if ( V_22 -> V_79 )
F_31 ( L_1 , V_80 , V_72 , V_75 , V_74 ) ;
if ( ( V_74 == V_81 ) ||
( V_75 == V_82 ) ) {
V_78 = V_72 ;
} else {
if ( V_75 == V_83 ) {
V_78 = V_72 + 2 ;
} else {
V_78 = V_72 - 2 ;
}
}
F_25 ( & F_18 ( V_22 ) -> V_73 ) ;
F_19 ( V_22 , V_72 ) ;
F_21 ( V_22 , V_74 ) ;
F_23 ( V_22 , V_75 ) ;
F_26 ( V_22 , V_78 ) ;
F_27 ( & F_18 ( V_22 ) -> V_73 ) ;
F_28 ( V_22 , V_74 , V_75 ) ;
}
int F_32 ( unsigned short V_84 )
{
if ( V_84 & F_33 ( 0 ) )
return V_85 ;
else if ( V_84 & F_33 ( 1 ) )
return V_86 ;
return 0 ;
}
inline T_1 * F_34 ( struct V_87 * V_88 )
{
return V_88 -> V_89 ;
}
T_3 F_35 ( struct V_87 * V_90 )
{
unsigned short V_31 ;
memcpy ( ( unsigned char * ) & V_31 , F_36 ( V_90 -> V_91 ) , 2 ) ;
return F_37 ( V_31 ) ;
}
int F_38 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_22 )
return V_92 ;
V_24 = & V_22 -> V_25 ;
V_27 = & V_24 -> V_28 ;
if ( ( V_27 -> V_93 & V_94 ) && ( ( V_27 -> V_93 & 0x03 ) == V_95 ) )
return true ;
else
return V_92 ;
}
int F_39 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( ( V_27 -> V_93 & V_94 ) &&
( ( V_27 -> V_93 & 0x03 ) == V_86 ) )
return true ;
else
return V_92 ;
}
int F_40 ( struct V_21 * V_22 )
{
unsigned int V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_3 = V_96 ; V_3 < V_97 ; V_3 ++ ) {
if ( V_27 -> V_98 [ V_3 ] . V_99 == 1 )
return V_92 ;
}
return true ;
}
unsigned int F_41 ( unsigned int V_100 )
{
if ( ( V_100 << 2 ) < V_101 )
return V_101 ;
else if ( ( V_100 << 2 ) > V_102 )
return V_102 ;
else
return V_100 << 2 ;
}
void F_42 ( struct V_21 * V_53 , T_1 V_103 )
{
F_12 ( V_53 , V_104 , ( T_1 * ) ( & V_103 ) ) ;
}
void F_43 ( struct V_21 * V_22 )
{
F_12 ( V_22 , V_105 , NULL ) ;
}
void F_44 ( struct V_21 * V_22 , T_1 V_106 , T_3 V_107 , T_1 * V_108 , T_1 * V_109 )
{
unsigned int V_3 , V_31 , V_110 ;
int V_111 ;
T_2 V_112 [ 2 ] ;
V_110 = V_106 << 3 ;
for ( V_111 = 5 ; V_111 >= 0 ; V_111 -- ) {
switch ( V_111 ) {
case 0 :
V_31 = ( V_107 | ( V_108 [ 0 ] << 16 ) | ( V_108 [ 1 ] << 24 ) ) ;
break;
case 1 :
V_31 = ( V_108 [ 2 ] | ( V_108 [ 3 ] << 8 ) | ( V_108 [ 4 ] << 16 ) | ( V_108 [ 5 ] << 24 ) ) ;
break;
default:
V_3 = ( V_111 - 2 ) << 2 ;
V_31 = ( V_109 [ V_3 ] | ( V_109 [ V_3 + 1 ] << 8 ) | ( V_109 [ V_3 + 2 ] << 16 ) | ( V_109 [ V_3 + 3 ] << 24 ) ) ;
break;
}
V_112 [ 0 ] = V_31 ;
V_112 [ 1 ] = V_110 + ( unsigned int ) V_111 ;
F_12 ( V_22 , V_113 , ( T_1 * ) V_112 ) ;
}
}
void F_45 ( struct V_21 * V_22 , T_1 V_106 )
{
unsigned char V_114 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_115 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_44 ( V_22 , V_106 , 0 , V_114 , V_115 ) ;
}
int F_46 ( struct V_21 * V_22 )
{
unsigned int V_116 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_116 = V_96 ; V_116 < V_97 ; V_116 ++ ) {
if ( V_27 -> V_98 [ V_116 ] . V_99 == 0 ) {
V_27 -> V_98 [ V_116 ] . V_99 = 1 ;
V_27 -> V_98 [ V_116 ] . V_117 = 0 ;
break;
}
}
return V_116 ;
}
void F_47 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_12 ( V_22 , V_105 , NULL ) ;
memset ( ( T_1 * ) ( V_27 -> V_98 ) , 0 , sizeof( V_27 -> V_98 ) ) ;
}
int F_48 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_120 * V_121 ;
T_1 V_122 [ V_123 ] = { 0x00 } ;
T_2 V_124 = 0 ;
V_121 = & V_22 -> V_125 ;
if ( F_49 ( ( T_1 * ) V_119 , V_119 -> V_126 , V_122 , & V_124 ) ) {
T_1 V_127 [ 10 ] = { 0x00 } ;
T_2 V_128 = 0 ;
F_31 ( L_2 , V_80 ) ;
F_50 ( V_122 , V_124 , V_129 , V_127 , & V_128 ) ;
if ( V_128 ) {
V_121 -> V_130 -> V_131 = F_51 ( V_127 + 2 ) ;
F_31 ( L_3 , V_80 , V_121 -> V_130 -> V_131 ) ;
return true ;
}
} else {
F_31 ( L_4 , V_80 ) ;
}
return V_92 ;
}
int F_52 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_132 * V_133 = & V_22 -> V_134 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_133 -> V_135 . V_136 == 0 ) {
V_27 -> V_137 = 0 ;
return V_92 ;
}
V_27 -> V_137 = 1 ;
memcpy ( & V_27 -> V_138 , ( V_119 -> V_139 + 6 ) ,
sizeof( struct V_140 ) ) ;
return true ;
}
void F_53 ( struct V_21 * V_22 )
{
T_1 V_141 , V_142 , V_143 , V_144 , V_145 , V_146 ;
T_1 V_147 ;
T_3 V_148 ;
T_2 V_149 , V_3 ;
T_2 V_150 [ 4 ] , V_151 [ 4 ] ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_152 * V_153 = & V_22 -> V_154 ;
struct V_155 * V_156 = & V_22 -> V_157 ;
if ( V_27 -> V_137 == 0 ) {
V_22 -> V_134 . V_147 = 0 ;
return;
}
V_147 = 0 ;
if ( V_24 -> V_158 == V_6 )
V_146 = 10 ;
else
V_146 = 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_141 = ( V_27 -> V_138 . V_159 [ V_3 ] . V_160 >> 5 ) & 0x03 ;
V_142 = ( V_27 -> V_138 . V_159 [ V_3 ] . V_160 >> 4 ) & 0x01 ;
V_143 = ( V_27 -> V_138 . V_159 [ V_3 ] . V_160 & 0x0f ) * V_27 -> V_161 + V_146 ;
V_144 = ( V_27 -> V_138 . V_159 [ V_3 ] . V_162 & 0x0f ) ;
V_145 = ( V_27 -> V_138 . V_159 [ V_3 ] . V_162 & 0xf0 ) >> 4 ;
V_148 = F_37 ( V_27 -> V_138 . V_159 [ V_3 ] . V_163 ) ;
V_149 = V_143 | ( V_144 << 8 ) | ( V_145 << 12 ) | ( V_148 << 16 ) ;
switch ( V_141 ) {
case 0x0 :
F_12 ( V_22 , V_164 , ( T_1 * ) ( & V_149 ) ) ;
V_147 |= ( V_142 ? F_33 ( 1 ) : 0 ) ;
V_150 [ V_165 ] = V_149 ;
break;
case 0x1 :
F_12 ( V_22 , V_166 , ( T_1 * ) ( & V_149 ) ) ;
V_150 [ V_167 ] = V_149 ;
break;
case 0x2 :
F_12 ( V_22 , V_168 , ( T_1 * ) ( & V_149 ) ) ;
V_147 |= ( V_142 ? F_33 ( 2 ) : 0 ) ;
V_150 [ V_169 ] = V_149 ;
break;
case 0x3 :
F_12 ( V_22 , V_170 , ( T_1 * ) ( & V_149 ) ) ;
V_147 |= ( V_142 ? F_33 ( 3 ) : 0 ) ;
V_150 [ V_171 ] = V_149 ;
break;
}
F_31 ( L_5 , V_141 , V_142 , V_149 ) ;
}
if ( V_22 -> V_157 . V_172 == 1 )
F_12 ( V_22 , V_173 , ( T_1 * ) ( & V_147 ) ) ;
else
V_22 -> V_134 . V_147 = V_147 ;
V_151 [ 0 ] = 0 ; V_151 [ 1 ] = 1 ; V_151 [ 2 ] = 2 ; V_151 [ 3 ] = 3 ;
if ( V_156 -> V_174 == 1 ) {
T_2 V_111 , V_175 , V_176 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_111 = V_3 + 1 ; V_111 < 4 ; V_111 ++ ) {
if ( ( V_150 [ V_111 ] & 0xFFFF ) < ( V_150 [ V_3 ] & 0xFFFF ) ) {
V_176 = true ;
} else if ( ( V_150 [ V_111 ] & 0xFFFF ) == ( V_150 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_150 [ V_111 ] >> 16 ) > ( V_150 [ V_3 ] >> 16 ) )
V_176 = true ;
}
if ( V_176 ) {
V_175 = V_150 [ V_3 ] ;
V_150 [ V_3 ] = V_150 [ V_111 ] ;
V_150 [ V_111 ] = V_175 ;
V_175 = V_151 [ V_3 ] ;
V_151 [ V_3 ] = V_151 [ V_111 ] ;
V_151 [ V_111 ] = V_175 ;
V_176 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_153 -> V_177 [ V_3 ] = V_151 [ V_3 ] ;
F_31 ( L_6 , V_3 , V_153 -> V_177 [ V_3 ] ) ;
}
return;
}
static void F_54 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_178 * V_179 ;
struct V_132 * V_133 = & V_22 -> V_134 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_155 * V_180 = & V_22 -> V_157 ;
struct V_181 * V_182 = & V_133 -> V_183 ;
unsigned char V_184 ;
unsigned char V_185 ;
if ( ! V_119 )
return;
if ( ! V_182 -> V_186 )
return;
if ( V_119 -> V_126 > sizeof( struct V_178 ) )
return;
V_179 = (struct V_178 * ) V_119 -> V_139 ;
if ( ( V_179 -> V_187 [ 0 ] & F_33 ( 2 ) ) && V_180 -> V_188 ) {
V_184 = V_189 ;
switch ( V_179 -> V_187 [ 0 ] & 0x3 ) {
case 1 :
V_185 = V_83 ;
break;
case 3 :
V_185 = V_190 ;
break;
default:
V_185 = V_82 ;
break;
}
} else {
V_184 = V_81 ;
V_185 = V_82 ;
}
if ( ( V_184 != V_24 -> V_191 ) ||
( V_185 != V_24 -> V_192 ) ) {
V_27 -> V_193 = true ;
V_24 -> V_191 = V_184 ;
V_24 -> V_192 = V_185 ;
F_55 ( V_22 , V_119 ) ;
} else {
V_27 -> V_193 = false ;
}
if ( V_27 -> V_193 ) {
struct V_194 * V_195 ;
struct V_87 * V_196 = & V_27 -> V_197 ;
struct V_198 * V_199 = & V_22 -> V_200 ;
V_195 = F_56 ( V_199 , V_196 -> V_89 ) ;
if ( V_195 ) {
struct V_181 * V_201 = & V_195 -> V_183 ;
if ( V_201 -> V_186 ) {
V_201 -> V_74 = V_24 -> V_191 ;
V_201 -> V_202 = V_24 -> V_192 ;
} else {
V_201 -> V_74 = V_81 ;
V_201 -> V_202 = V_82 ;
}
}
}
}
void F_57 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
unsigned int V_3 ;
T_1 V_203 ;
T_1 V_204 , V_205 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_132 * V_133 = & V_22 -> V_134 ;
struct V_181 * V_182 = & V_133 -> V_183 ;
if ( V_119 == NULL ) return;
if ( V_182 -> V_186 == false ) return;
V_27 -> V_206 = 1 ;
for ( V_3 = 0 ; V_3 < ( V_119 -> V_126 ) ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_27 -> V_207 . V_208 . V_209 [ V_3 ] &= ( V_119 -> V_139 [ V_3 ] ) ;
} else {
if ( ( V_27 -> V_207 . V_208 . V_210 . V_211 & 0x3 ) > ( V_119 -> V_139 [ V_3 ] & 0x3 ) )
V_204 = ( V_119 -> V_139 [ V_3 ] & 0x3 ) ;
else
V_204 = ( V_27 -> V_207 . V_208 . V_210 . V_211 & 0x3 ) ;
if ( ( V_27 -> V_207 . V_208 . V_210 . V_211 & 0x1c ) > ( V_119 -> V_139 [ V_3 ] & 0x1c ) )
V_205 = ( V_27 -> V_207 . V_208 . V_210 . V_211 & 0x1c ) ;
else
V_205 = ( V_119 -> V_139 [ V_3 ] & 0x1c ) ;
V_27 -> V_207 . V_208 . V_210 . V_211 = V_204 | V_205 ;
}
}
V_27 -> V_207 . V_208 . V_210 . V_212 = F_37 ( V_27 -> V_207 . V_208 . V_210 . V_212 ) ;
V_27 -> V_207 . V_208 . V_210 . V_213 = F_37 ( V_27 -> V_207 . V_208 . V_210 . V_213 ) ;
F_58 ( V_22 , V_214 , ( T_1 * ) ( & V_203 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( V_203 == V_215 ) || ( V_203 == V_216 ) )
V_27 -> V_207 . V_208 . V_210 . V_217 [ V_3 ] &= V_218 [ V_3 ] ;
else
V_27 -> V_207 . V_208 . V_210 . V_217 [ V_3 ] &= V_219 [ V_3 ] ;
}
return;
}
void F_55 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_132 * V_133 = & V_22 -> V_134 ;
struct V_181 * V_182 = & V_133 -> V_183 ;
if ( V_119 == NULL ) return;
if ( V_182 -> V_186 == false ) return;
if ( V_119 -> V_126 > sizeof( struct V_178 ) )
return;
V_27 -> V_220 = 1 ;
memcpy ( & V_27 -> V_221 , V_119 -> V_139 , V_119 -> V_126 ) ;
return;
}
void F_59 ( struct V_21 * V_22 )
{
unsigned char V_204 ;
unsigned char V_205 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_31 ( L_7 , V_80 ) ;
if ( ( V_27 -> V_220 ) && ( V_27 -> V_206 ) ) {
V_27 -> V_30 = 1 ;
} else {
V_27 -> V_30 = 0 ;
return;
}
V_204 = V_27 -> V_207 . V_208 . V_210 . V_211 & 0x03 ;
V_205 = ( V_27 -> V_207 . V_208 . V_210 . V_211 & 0x1c ) >> 2 ;
F_12 ( V_22 , V_222 , ( T_1 * ) ( & V_205 ) ) ;
F_12 ( V_22 , V_223 , ( T_1 * ) ( & V_204 ) ) ;
}
void F_60 ( struct V_21 * V_22 , struct V_118 * V_119 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_119 -> V_126 > 1 )
return;
V_27 -> V_224 = 1 ;
memcpy ( & V_27 -> V_225 , V_119 -> V_139 , V_119 -> V_126 ) ;
}
void F_61 ( struct V_21 * V_22 , struct V_194 * V_195 )
{
struct V_155 * V_156 = & V_22 -> V_157 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_156 -> V_226 ) {
case 0 :
V_195 -> V_227 = 0 ;
V_195 -> V_228 = 0 ;
break;
case 1 :
if ( V_156 -> V_229 == 1 ) {
V_195 -> V_227 = 1 ;
V_195 -> V_228 = 0 ;
} else {
V_195 -> V_227 = 0 ;
V_195 -> V_228 = 1 ;
}
break;
case 2 :
default:
if ( ( V_27 -> V_224 ) && ( V_27 -> V_225 & F_33 ( 1 ) ) ) {
if ( V_156 -> V_229 == 1 ) {
V_195 -> V_227 = 1 ;
V_195 -> V_228 = 0 ;
} else {
V_195 -> V_227 = 0 ;
V_195 -> V_228 = 1 ;
}
} else {
V_195 -> V_227 = 0 ;
V_195 -> V_228 = 0 ;
}
break;
}
}
int F_62 ( struct V_21 * V_53 , T_1 * V_230 , T_2 V_231 )
{
unsigned int V_47 ;
unsigned char * V_232 ;
unsigned short V_233 ;
struct V_234 * V_196 = & V_53 -> V_134 . V_196 ;
T_3 V_235 = 0 , V_236 = 0 ;
T_1 V_237 = 0 ;
struct V_87 * V_238 ;
int V_239 = 0 , V_240 = 0 , V_241 = 0 ;
unsigned char * V_242 ;
T_2 V_243 = 0 ;
T_2 V_244 = 0 ;
struct V_178 * V_245 = NULL ;
struct V_246 * V_247 = NULL ;
T_2 V_248 ;
unsigned short V_249 ;
unsigned char V_250 ;
struct V_251 * V_252 = (struct V_251 * ) V_230 ;
T_1 * V_253 = V_252 -> V_254 ;
if ( F_38 ( V_53 ) == false )
return true ;
V_47 = V_231 - sizeof( struct V_255 ) ;
if ( V_47 > V_256 ) {
F_31 ( L_8 , V_80 ) ;
return V_92 ;
}
if ( memcmp ( V_196 -> V_197 . V_89 , V_253 , 6 ) ) {
F_31 ( L_9 MAC_FMT MAC_FMT,
MAC_ARG(pbssid), MAC_ARG(cur_network->network.MacAddress)) ;
return true ;
}
V_238 = (struct V_87 * ) F_63 ( sizeof( struct V_87 ) ,
V_257 ) ;
if ( F_64 ( V_252 -> V_258 ) )
V_238 -> V_259 = 1 ;
V_238 -> V_126 = sizeof( struct V_87 ) - V_256 + V_47 ;
V_238 -> V_260 = V_47 ;
memcpy ( V_238 -> V_91 , ( V_230 + sizeof( struct V_255 ) ) , V_238 -> V_260 ) ;
V_232 = F_65 ( V_238 -> V_91 + V_261 , V_262 , & V_47 , V_238 -> V_260 - V_261 ) ;
if ( V_232 && V_47 > 0 ) {
V_247 = (struct V_246 * ) ( V_232 + 2 ) ;
V_249 = V_247 -> V_263 ;
} else {
V_249 = 0 ;
}
V_232 = F_65 ( V_238 -> V_91 + V_261 , V_264 , & V_47 , V_238 -> V_260 - V_261 ) ;
if ( V_232 && V_47 > 0 ) {
V_245 = (struct V_178 * ) ( V_232 + 2 ) ;
V_250 = V_245 -> V_187 [ 0 ] ;
} else {
V_250 = 0 ;
}
if ( V_249 != V_196 -> V_265 . V_249 ||
( ( V_250 & 0x03 ) != ( V_196 -> V_265 . V_250 & 0x03 ) ) ) {
F_31 ( L_10 , V_80 ,
V_249 , V_250 ) ;
F_31 ( L_11 , V_80 ,
V_196 -> V_265 . V_249 , V_196 -> V_265 . V_250 ) ;
F_31 ( L_12 , V_80 ) ;
V_196 -> V_265 . V_249 = V_249 ;
V_196 -> V_265 . V_250 = V_250 ;
}
V_232 = F_65 ( V_238 -> V_91 + V_261 , V_266 , & V_47 , V_238 -> V_260 - V_261 ) ;
if ( V_232 ) {
V_248 = * ( V_232 + 2 ) ;
} else {
V_232 = F_65 ( V_238 -> V_91 + V_261 , V_264 , & V_47 , V_238 -> V_260 - V_261 ) ;
if ( V_245 ) {
V_248 = V_245 -> V_267 ;
} else {
F_31 ( L_13 , V_80 ) ;
V_248 = V_53 -> V_25 . V_29 ;
}
}
if ( V_248 != V_53 -> V_25 . V_29 ) {
F_31 ( L_14 , V_80 ,
V_248 , V_53 -> V_25 . V_29 ) ;
goto V_268;
}
if ( ( V_232 = F_65 ( V_238 -> V_91 + V_261 , V_269 , & V_47 , V_238 -> V_260 - V_261 ) ) == NULL ) {
F_31 ( L_15 , V_80 ) ;
V_244 = true ;
} else {
V_244 = false ;
}
if ( ( NULL != V_232 ) && ( false == V_244 && ( * ( V_232 + 1 ) ) ) ) {
memcpy ( V_238 -> V_270 . V_271 , ( V_232 + 2 ) , * ( V_232 + 1 ) ) ;
V_238 -> V_270 . V_272 = * ( V_232 + 1 ) ;
} else {
V_238 -> V_270 . V_272 = 0 ;
V_238 -> V_270 . V_271 [ 0 ] = '\0' ;
}
F_66 ( V_273 , V_274 ,
( L_16
L_17 , V_80 ,
V_238 -> V_270 . V_271 , V_238 -> V_270 . V_272 ,
V_196 -> V_197 . V_270 . V_271 ,
V_196 -> V_197 . V_270 . V_272 ) ) ;
if ( memcmp ( V_238 -> V_270 . V_271 , V_196 -> V_197 . V_270 . V_271 , 32 ) ||
V_238 -> V_270 . V_272 != V_196 -> V_197 . V_270 . V_272 ) {
if ( V_238 -> V_270 . V_271 [ 0 ] != '\0' &&
V_238 -> V_270 . V_272 != 0 ) {
F_31 ( L_18 ,
V_80 ) ;
goto V_268;
}
}
V_233 = F_67 ( (struct V_87 * ) V_238 ) ;
if ( V_233 & F_33 ( 4 ) )
V_238 -> V_275 = 1 ;
else
V_238 -> V_275 = 0 ;
F_66 ( V_273 , V_274 ,
( L_19 ,
V_80 , V_196 -> V_197 . V_275 , V_238 -> V_275 ) ) ;
if ( V_196 -> V_197 . V_275 != V_238 -> V_275 ) {
F_31 ( L_20 , V_80 ) ;
goto V_268;
}
F_68 ( V_238 -> V_91 , V_238 -> V_260 , NULL , & V_236 , NULL , & V_235 ) ;
if ( V_236 > 0 ) {
V_237 = V_276 ;
} else if ( V_235 > 0 ) {
V_237 = V_277 ;
} else {
if ( V_238 -> V_275 )
V_237 = V_278 ;
}
if ( V_196 -> V_265 . V_237 != V_237 ) {
F_31 ( L_21 , V_80 ) ;
goto V_268;
}
if ( V_237 == V_277 || V_237 == V_276 ) {
V_242 = F_69 ( & V_238 -> V_91 [ 12 ] , & V_243 , V_238 -> V_260 - 12 ) ;
if ( V_242 && ( V_243 > 0 ) ) {
if ( V_279 == F_70 ( V_242 , V_243 + 2 , & V_239 , & V_240 , & V_241 ) ) {
F_66 ( V_273 , V_274 ,
( L_22 , V_80 ,
V_240 , V_239 , V_241 ) ) ;
}
} else {
V_242 = F_71 ( & V_238 -> V_91 [ 12 ] , & V_243 , V_238 -> V_260 - 12 ) ;
if ( V_242 && ( V_243 > 0 ) ) {
if ( V_279 == F_72 ( V_242 , V_243 + 2 , & V_239 , & V_240 , & V_241 ) ) {
F_66 ( V_273 , V_274 ,
( L_23 ,
V_80 , V_240 , V_239 , V_241 ) ) ;
}
}
}
F_66 ( V_273 , V_280 ,
( L_24 , V_80 , V_196 -> V_265 . V_239 , V_239 ) ) ;
if ( V_240 != V_196 -> V_265 . V_240 || V_239 != V_196 -> V_265 . V_239 ) {
F_31 ( L_25 , V_80 ,
V_240 , V_196 -> V_265 . V_240 ,
V_239 , V_196 -> V_265 . V_239 ) ;
goto V_268;
}
if ( V_241 != V_196 -> V_265 . V_241 ) {
F_31 ( L_26 , V_80 ) ;
goto V_268;
}
}
F_73 ( V_238 ) ;
return V_279 ;
V_268:
F_73 ( V_238 ) ;
return V_92 ;
}
void F_74 ( struct V_21 * V_22 , T_1 * V_230 , T_4 V_281 , struct V_194 * V_195 )
{
unsigned int V_3 ;
unsigned int V_47 ;
struct V_118 * V_119 ;
V_47 = V_281 -
( V_282 + sizeof( struct V_255 ) ) ;
for ( V_3 = 0 ; V_3 < V_47 ; ) {
V_119 = (struct V_118 * ) ( V_230 + ( V_282 + sizeof( struct V_255 ) ) + V_3 ) ;
switch ( V_119 -> V_283 ) {
case V_284 :
F_54 ( V_22 , V_119 ) ;
break;
case V_285 :
F_60 ( V_22 , V_119 ) ;
F_61 ( V_22 , V_195 ) ;
break;
default:
break;
}
V_3 += ( V_119 -> V_126 + 2 ) ;
}
}
unsigned int F_75 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_118 * V_119 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_87 * V_196 = & V_27 -> V_197 ;
if ( F_67 ( (struct V_87 * ) V_196 ) & V_286 ) {
for ( V_3 = sizeof( struct V_287 ) ; V_3 < V_27 -> V_197 . V_260 ; ) {
V_119 = (struct V_118 * ) ( V_27 -> V_197 . V_91 + V_3 ) ;
switch ( V_119 -> V_283 ) {
case V_288 :
if ( ( ! memcmp ( V_119 -> V_139 , V_289 , 4 ) ) && ( ! memcmp ( ( V_119 -> V_139 + 12 ) , V_290 , 4 ) ) )
return true ;
break;
case V_291 :
if ( ! memcmp ( ( V_119 -> V_139 + 8 ) , V_292 , 4 ) )
return true ;
break;
default:
break;
}
V_3 += ( V_119 -> V_126 + 2 ) ;
}
return false ;
} else {
return false ;
}
}
unsigned int F_76 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_118 * V_119 ;
struct V_132 * V_133 = & V_22 -> V_134 ;
struct V_87 * V_196 = & V_133 -> V_196 . V_197 ;
if ( F_67 ( (struct V_87 * ) V_196 ) & V_286 ) {
for ( V_3 = sizeof( struct V_287 ) ; V_3 < V_196 -> V_260 ; ) {
V_119 = (struct V_118 * ) ( V_196 -> V_91 + V_3 ) ;
switch ( V_119 -> V_283 ) {
case V_288 :
if ( ! memcmp ( V_119 -> V_139 , V_289 , 4 ) &&
( ( ! memcmp ( ( V_119 -> V_139 + 12 ) , V_293 , 4 ) ) ||
( ! memcmp ( ( V_119 -> V_139 + 16 ) , V_293 , 4 ) ) ) )
return false ;
break;
case V_291 :
if ( ( ! memcmp ( ( V_119 -> V_139 + 8 ) , V_294 , 4 ) ) ||
( ! memcmp ( ( V_119 -> V_139 + 12 ) , V_294 , 4 ) ) )
return false ;
default:
break;
}
V_3 += ( V_119 -> V_126 + 2 ) ;
}
return true ;
} else {
return false ;
}
}
unsigned int F_77 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_118 * V_119 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_87 * V_196 = & V_27 -> V_197 ;
if ( F_67 ( (struct V_87 * ) V_196 ) & V_286 ) {
for ( V_3 = sizeof( struct V_287 ) ; V_3 < V_27 -> V_197 . V_260 ; ) {
V_119 = (struct V_118 * ) ( V_27 -> V_197 . V_91 + V_3 ) ;
switch ( V_119 -> V_283 ) {
case V_288 :
if ( ! memcmp ( V_119 -> V_139 , V_289 , 4 ) )
return false ;
break;
case V_291 :
return false ;
default:
break;
}
V_3 += ( V_119 -> V_126 + 2 ) ;
}
return true ;
} else {
return false ;
}
}
int F_78 ( unsigned char V_1 )
{
int V_151 = 0 ;
V_1 = V_1 & 0x7f ;
switch ( V_1 ) {
case 54 * 2 :
V_151 = 11 ;
break;
case 48 * 2 :
V_151 = 10 ;
break;
case 36 * 2 :
V_151 = 9 ;
break;
case 24 * 2 :
V_151 = 8 ;
break;
case 18 * 2 :
V_151 = 7 ;
break;
case 12 * 2 :
V_151 = 6 ;
break;
case 9 * 2 :
V_151 = 5 ;
break;
case 6 * 2 :
V_151 = 4 ;
break;
case 11 * 2 :
V_151 = 3 ;
break;
case 11 :
V_151 = 2 ;
break;
case 2 * 2 :
V_151 = 1 ;
break;
case 1 * 2 :
V_151 = 0 ;
break;
}
return V_151 ;
}
unsigned int F_79 ( unsigned char * V_295 , unsigned int V_296 )
{
unsigned int V_3 , V_297 ;
unsigned int V_298 = 0 ;
V_297 = ( V_296 > V_44 ) ? V_44 : V_296 ;
for ( V_3 = 0 ; V_3 < V_297 ; V_3 ++ ) {
if ( ( * ( V_295 + V_3 ) ) & 0x80 )
V_298 |= 0x1 << F_78 ( * ( V_295 + V_3 ) ) ;
}
return V_298 ;
}
unsigned int F_80 ( unsigned char * V_295 , unsigned int V_296 )
{
unsigned int V_3 , V_297 ;
unsigned int V_298 = 0 ;
V_297 = ( V_296 > V_44 ) ? V_44 : V_296 ;
for ( V_3 = 0 ; V_3 < V_297 ; V_3 ++ )
V_298 |= 0x1 << F_78 ( * ( V_295 + V_3 ) ) ;
return V_298 ;
}
unsigned int F_81 ( struct V_299 * V_300 )
{
unsigned int V_298 = 0 ;
V_298 = ( ( V_300 -> V_208 . V_210 . V_217 [ 0 ] << 12 ) | ( V_300 -> V_208 . V_210 . V_217 [ 1 ] << 20 ) ) ;
return V_298 ;
}
int F_82 ( struct V_21 * V_22 ,
struct V_299 * V_300 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
unsigned char V_301 ;
if ( ! ( V_27 -> V_30 ) )
return V_92 ;
if ( ( V_27 -> V_302 == V_303 ) )
return V_92 ;
V_301 = ( V_24 -> V_191 & V_189 ) ? 6 : 5 ;
if ( V_300 -> V_208 . V_210 . V_212 & ( 0x1 << V_301 ) )
return V_279 ;
else
return V_92 ;
}
unsigned char F_83 ( T_2 V_298 )
{
int V_3 ;
unsigned char V_304 = 0 ;
for ( V_3 = 27 ; V_3 >= 0 ; V_3 -- ) {
if ( V_298 & F_33 ( V_3 ) ) {
V_304 = V_3 ;
break;
}
}
return V_304 ;
}
unsigned char F_84 ( struct V_299 * V_300 )
{
int V_3 , V_305 ;
V_305 = ( V_300 -> V_208 . V_210 . V_217 [ 0 ] | ( V_300 -> V_208 . V_210 . V_217 [ 1 ] << 8 ) ) ;
for ( V_3 = 15 ; V_3 >= 0 ; V_3 -- ) {
if ( V_305 & ( 0x1 << V_3 ) )
break;
}
return V_3 ;
}
void F_85 ( struct V_21 * V_22 , struct V_194 * V_195 )
{
F_86 ( V_195 , 0 ) ;
}
void F_87 ( struct V_21 * V_22 , struct V_194 * V_195 )
{
F_85 ( V_22 , V_195 ) ;
}
void F_88 ( struct V_21 * V_22 , struct V_194 * V_195 )
{
F_87 ( V_22 , V_195 ) ;
}
void F_89 ( struct V_21 * V_22 , T_1 V_306 )
{
unsigned char V_307 [ V_55 ] ;
#ifdef F_90
struct V_120 * V_121 = & V_22 -> V_125 ;
if ( ! F_91 ( V_121 , V_308 ) )
return;
#endif
memset ( V_307 , 0 , V_55 ) ;
if ( ( V_306 & V_6 ) && ( V_306 == V_6 ) ) {
memcpy ( V_307 , V_309 , 4 ) ;
} else if ( V_306 & V_6 ) {
memcpy ( V_307 , V_310 , 7 ) ;
} else {
memcpy ( V_307 , V_311 , 3 ) ;
}
if ( V_306 & V_6 )
F_92 ( V_22 , V_32 ) ;
else
F_92 ( V_22 , V_36 ) ;
F_12 ( V_22 , V_312 , V_307 ) ;
}
unsigned char F_93 ( T_1 * V_230 , T_4 V_47 )
{
unsigned int V_3 ;
struct V_118 * V_119 ;
T_1 V_313 ;
T_1 V_314 ;
V_313 = 0 ;
V_314 = 0 ;
for ( V_3 = sizeof( struct V_287 ) ; V_3 < V_47 ; ) {
V_119 = (struct V_118 * ) ( V_230 + V_3 ) ;
switch ( V_119 -> V_283 ) {
case V_288 :
if ( ( ! memcmp ( V_119 -> V_139 , V_315 , 3 ) ) ||
( ! memcmp ( V_119 -> V_139 , V_316 , 3 ) ) ) {
F_31 ( L_27 ) ;
return V_317 ;
} else if ( ( ! memcmp ( V_119 -> V_139 , V_318 , 3 ) ) ||
! memcmp ( V_119 -> V_139 , V_319 , 3 ) ||
! memcmp ( V_119 -> V_139 , V_319 , 3 ) ) {
F_31 ( L_28 ) ;
return V_320 ;
} else if ( ! memcmp ( V_119 -> V_139 , V_321 , 3 ) ) {
F_31 ( L_29 ) ;
return V_322 ;
} else if ( ! memcmp ( V_119 -> V_139 , V_323 , 3 ) ) {
if ( ! V_314 ) {
V_314 = 1 ;
} else {
F_31 ( L_30 ) ;
return V_303 ;
}
} else if ( ! memcmp ( V_119 -> V_139 , V_324 , 3 ) ) {
F_31 ( L_31 ) ;
return V_325 ;
} else if ( ! memcmp ( V_119 -> V_139 , V_326 , 3 ) ) {
F_31 ( L_32 ) ;
return V_327 ;
} else if ( ! memcmp ( V_119 -> V_139 , V_328 , 3 ) ) {
F_31 ( L_33 ) ;
return V_329 ;
} else if ( ! memcmp ( V_119 -> V_139 , V_330 , 3 ) ) {
V_313 = 1 ;
if ( V_314 ) {
F_31 ( L_34 ) ;
return V_331 ;
} else {
F_31 ( L_35 ) ;
}
} else {
break;
}
default:
break;
}
V_3 += ( V_119 -> V_126 + 2 ) ;
}
if ( V_314 && ! V_313 ) {
F_31 ( L_30 ) ;
return V_303 ;
} else if ( V_314 && V_313 ) {
F_31 ( L_34 ) ;
return V_331 ;
} else {
F_31 ( L_36 ) ;
return V_332 ;
}
}
void F_94 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_27 -> V_302 ) {
case V_322 :
V_27 -> V_333 = 1 ;
V_27 -> V_334 = 0 ;
break;
case V_303 :
V_27 -> V_333 = 0 ;
V_27 -> V_334 = 1 ;
F_14 ( V_22 , ~ V_335 ,
false ) ;
break;
case V_327 :
F_14 ( V_22 , ~ V_335 ,
false ) ;
break;
default:
V_27 -> V_333 = 0 ;
V_27 -> V_334 = 1 ;
break;
}
}
void F_95 ( struct V_21 * V_53 , T_3 V_336 )
{
struct V_23 * V_24 = & V_53 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
bool V_337 ;
if ( V_336 & V_338 ) {
if ( V_27 -> V_339 != V_340 ) {
V_337 = true ;
V_27 -> V_339 = V_340 ;
F_12 ( V_53 , V_341 , ( T_1 * ) & V_337 ) ;
}
} else {
if ( V_27 -> V_339 != V_342 ) {
V_337 = false ;
V_27 -> V_339 = V_342 ;
F_12 ( V_53 , V_341 , ( T_1 * ) & V_337 ) ;
}
}
if ( V_336 & V_343 ) {
V_27 -> V_161 = V_344 ;
} else {
if ( V_24 -> V_158 & ( V_9 | V_13 ) ) {
if ( V_336 & V_345 ) {
if ( V_27 -> V_161 != V_346 )
V_27 -> V_161 = V_346 ;
} else {
if ( V_27 -> V_161 != V_344 )
V_27 -> V_161 = V_344 ;
}
} else if ( V_24 -> V_158 & ( V_8 | V_14 ) ) {
V_27 -> V_161 = V_346 ;
} else {
V_27 -> V_161 = V_344 ;
}
}
F_12 ( V_53 , V_347 , & V_27 -> V_161 ) ;
}
void F_96 ( struct V_21 * V_22 )
{
int V_2 , V_4 = 0 ;
T_2 V_348 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_87 * V_196 = & V_27 -> V_197 ;
unsigned char * V_1 = V_196 -> V_349 ;
V_2 = F_97 ( V_196 -> V_349 ) ;
if ( ( V_27 -> V_220 ) && ( V_27 -> V_206 ) )
V_27 -> V_30 = 1 ;
if ( V_24 -> V_29 > 14 ) {
if ( V_27 -> V_30 )
V_4 = V_14 ;
V_4 |= V_8 ;
} else {
if ( V_27 -> V_30 )
V_4 = V_13 ;
if ( ( F_2 ( V_1 , V_2 ) ) == true )
V_4 |= V_6 ;
else if ( ( F_1 ( V_1 , V_2 ) ) == true )
V_4 |= V_11 ;
else
V_4 |= V_9 ;
}
V_24 -> V_158 = V_4 & V_22 -> V_157 . V_350 ;
V_348 = 0x0a0a0808 ;
V_22 -> V_351 . V_352 ( V_22 , V_353 , ( T_1 * ) & V_348 ) ;
if ( V_24 -> V_158 & V_6 )
F_92 ( V_22 , V_32 ) ;
else
F_92 ( V_22 , V_36 ) ;
}
void F_98 ( struct V_21 * V_22 , T_2 V_116 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_24 -> V_158 & V_6 ) {
memcpy ( ( V_27 -> V_98 [ V_116 ] . V_349 ) , V_309 , 4 ) ;
} else {
memcpy ( ( V_27 -> V_98 [ V_116 ] . V_349 ) , V_311 , 4 ) ;
}
}
int F_99 ( struct V_21 * V_22 , T_1 * V_354 , T_4 V_355 , int V_356 )
{
unsigned int V_357 ;
struct V_118 * V_119 ;
int V_358 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
V_119 = (struct V_118 * ) F_65 ( V_354 , V_359 , & V_357 , V_355 ) ;
if ( V_119 == NULL )
return V_92 ;
memcpy ( V_27 -> V_98 [ V_356 ] . V_349 , V_119 -> V_139 , V_357 ) ;
V_358 = V_357 ;
V_119 = (struct V_118 * ) F_65 ( V_354 , V_360 , & V_357 , V_355 ) ;
if ( V_119 )
memcpy ( ( V_27 -> V_98 [ V_356 ] . V_349 + V_358 ) , V_119 -> V_139 , V_357 ) ;
return V_279 ;
}
void F_100 ( struct V_21 * V_22 , T_1 * V_361 , T_1 * V_110 )
{
struct V_194 * V_195 ;
T_3 V_362 , V_363 , V_364 ;
struct V_365 * V_366 ;
struct V_198 * V_199 = & V_22 -> V_200 ;
struct V_367 * V_368 = (struct V_367 * ) V_361 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
V_195 = F_56 ( V_199 , V_110 ) ;
if ( V_195 ) {
V_363 = F_37 ( V_368 -> V_369 ) >> 4 ;
V_364 = F_37 ( V_368 -> V_370 ) ;
V_362 = ( V_364 >> 2 ) & 0x0f ;
V_366 = & V_195 -> V_371 [ V_362 ] ;
V_366 -> V_372 = 0xffff ;
V_366 -> V_61 = ( V_27 -> V_373 == true ) ? true : false ;
}
}
void F_101 ( struct V_23 * V_24 , T_1 * V_230 , T_4 V_47 )
{
T_1 * V_119 ;
T_2 * V_242 ;
V_119 = V_230 + sizeof( struct V_255 ) ;
V_242 = ( T_2 * ) V_119 ;
V_24 -> V_374 = F_102 ( * ( V_242 + 1 ) ) ;
V_24 -> V_374 = V_24 -> V_374 << 32 ;
V_24 -> V_374 |= F_102 ( * V_242 ) ;
}
void F_103 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
F_12 ( V_22 , V_375 , NULL ) ;
}
void F_104 ( struct V_21 * V_22 )
{
F_105 ( V_22 ) ;
}
int F_106 ( struct V_21 * V_65 , bool V_376 )
{
int V_99 = V_279 ;
if ( V_376 ) {
if ( V_377 == NULL ) {
V_377 = V_65 ;
F_31 ( L_37 , V_80 ) ;
} else {
V_65 -> V_378 = V_377 ;
V_377 -> V_378 = V_65 ;
V_377 = NULL ;
F_31 ( L_38 , V_80 ) ;
}
} else {
V_377 = NULL ;
}
return V_99 ;
}
