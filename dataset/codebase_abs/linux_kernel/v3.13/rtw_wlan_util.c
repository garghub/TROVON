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
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
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
static unsigned char F_5 ( unsigned char V_1 )
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
static int F_6 ( struct V_21 * V_22 , unsigned char V_1 )
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
static unsigned int F_7 ( struct V_21 * V_22 , unsigned char * V_46 )
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
F_9 ( V_52 , 0 , V_44 ) ;
* V_51 = F_7 ( V_22 , V_52 ) ;
memcpy ( V_50 , V_52 , * V_51 ) ;
}
void F_10 ( struct V_21 * V_53 , T_1 * V_54 )
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
}
}
}
void F_11 ( T_1 * V_56 , T_2 V_57 )
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
void F_12 ( struct V_21 * V_22 )
{
T_1 V_58 = true ;
F_13 ( V_22 , V_59 , ( T_1 * ) ( & V_58 ) ) ;
}
void F_14 ( struct V_21 * V_22 )
{
T_1 V_58 = false ;
F_13 ( V_22 , V_59 , ( T_1 * ) ( & V_58 ) ) ;
}
void F_15 ( struct V_21 * V_22 , T_2 V_60 , T_1 V_61 )
{
if ( V_61 )
F_13 ( V_22 , V_62 , ( T_1 * ) ( & V_60 ) ) ;
else
F_13 ( V_22 , V_63 , ( T_1 * ) ( & V_60 ) ) ;
}
static void F_16 ( struct V_21 * V_22 , T_1 type )
{
F_13 ( V_22 , V_64 , ( T_1 * ) ( & type ) ) ;
}
void F_17 ( struct V_21 * V_22 , T_1 type )
{
F_16 ( V_22 , type ) ;
}
inline T_1 F_18 ( struct V_21 * V_21 )
{
return V_21 -> V_25 . V_65 ;
}
inline void F_19 ( struct V_21 * V_21 , T_1 V_66 )
{
V_21 -> V_25 . V_65 = V_66 ;
}
inline T_1 F_20 ( struct V_21 * V_21 )
{
return V_21 -> V_25 . V_67 ;
}
inline void F_21 ( struct V_21 * V_21 , T_1 V_68 )
{
V_21 -> V_25 . V_67 = V_68 ;
}
inline T_1 F_22 ( struct V_21 * V_21 )
{
return V_21 -> V_25 . V_69 ;
}
inline void F_23 ( struct V_21 * V_21 , T_1 V_70 )
{
V_21 -> V_25 . V_69 = V_70 ;
}
void F_24 ( struct V_21 * V_22 , unsigned char V_71 )
{
F_19 ( V_22 , V_71 ) ;
F_25 ( V_22 , V_71 ) ;
}
void F_26 ( struct V_21 * V_22 , unsigned short V_72 ,
unsigned char V_73 )
{
F_21 ( V_22 , V_72 ) ;
F_23 ( V_22 , V_73 ) ;
F_27 ( V_22 , (enum V_74 ) V_72 , V_73 ) ;
}
void F_28 ( struct V_21 * V_22 , unsigned char V_71 , unsigned char V_73 , unsigned short V_72 )
{
T_1 V_75 ;
if ( V_22 -> V_76 )
F_29 ( L_1 , V_77 , V_71 , V_73 , V_72 ) ;
if ( ( V_72 == V_78 ) ||
( V_73 == V_79 ) ) {
V_75 = V_71 ;
} else {
if ( V_73 == V_80 ) {
V_75 = V_71 + 2 ;
} else {
V_75 = V_71 - 2 ;
}
}
F_19 ( V_22 , V_71 ) ;
F_21 ( V_22 , V_72 ) ;
F_23 ( V_22 , V_73 ) ;
F_25 ( V_22 , V_75 ) ;
F_26 ( V_22 , V_72 , V_73 ) ;
}
int F_30 ( unsigned short V_81 )
{
if ( V_81 & F_31 ( 0 ) )
return V_82 ;
else if ( V_81 & F_31 ( 1 ) )
return V_83 ;
else
return 0 ;
}
T_3 T_1 * F_32 ( struct V_84 * V_85 )
{
return V_85 -> V_86 ;
}
T_4 F_33 ( struct V_84 * V_87 )
{
T_5 V_31 ;
memcpy ( ( unsigned char * ) & V_31 , F_34 ( V_87 -> V_88 ) , 2 ) ;
return F_35 ( V_31 ) ;
}
int F_36 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_22 )
return V_89 ;
V_24 = & V_22 -> V_25 ;
V_27 = & ( V_24 -> V_28 ) ;
if ( ( V_27 -> V_90 & V_91 ) && ( ( V_27 -> V_90 & 0x03 ) == V_92 ) )
return true ;
else
return V_89 ;
}
int F_37 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
if ( ( V_27 -> V_90 & V_91 ) && ( ( V_27 -> V_90 & 0x03 ) == V_83 ) )
return true ;
else
return V_89 ;
}
int F_38 ( struct V_21 * V_22 )
{
unsigned int V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
for ( V_3 = V_93 ; V_3 < V_94 ; V_3 ++ ) {
if ( V_27 -> V_95 [ V_3 ] . V_96 == 1 )
return V_89 ;
}
return true ;
}
unsigned int F_39 ( unsigned int V_97 )
{
if ( ( V_97 << 2 ) < V_98 )
return V_98 ;
else if ( ( V_97 << 2 ) > V_99 )
return V_99 ;
else
return V_97 << 2 ;
}
void F_40 ( struct V_21 * V_53 , T_1 V_100 )
{
F_13 ( V_53 , V_101 , ( T_1 * ) ( & V_100 ) ) ;
}
void F_41 ( struct V_21 * V_22 )
{
F_13 ( V_22 , V_102 , NULL ) ;
}
void F_42 ( struct V_21 * V_22 , T_1 V_103 , T_4 V_104 , T_1 * V_105 , T_1 * V_106 )
{
unsigned int V_3 , V_31 , V_107 ;
int V_108 ;
T_2 V_109 [ 2 ] ;
V_107 = V_103 << 3 ;
for ( V_108 = 5 ; V_108 >= 0 ; V_108 -- ) {
switch ( V_108 ) {
case 0 :
V_31 = ( V_104 | ( V_105 [ 0 ] << 16 ) | ( V_105 [ 1 ] << 24 ) ) ;
break;
case 1 :
V_31 = ( V_105 [ 2 ] | ( V_105 [ 3 ] << 8 ) | ( V_105 [ 4 ] << 16 ) | ( V_105 [ 5 ] << 24 ) ) ;
break;
default:
V_3 = ( V_108 - 2 ) << 2 ;
V_31 = ( V_106 [ V_3 ] | ( V_106 [ V_3 + 1 ] << 8 ) | ( V_106 [ V_3 + 2 ] << 16 ) | ( V_106 [ V_3 + 3 ] << 24 ) ) ;
break;
}
V_109 [ 0 ] = V_31 ;
V_109 [ 1 ] = V_107 + ( unsigned int ) V_108 ;
F_13 ( V_22 , V_110 , ( T_1 * ) V_109 ) ;
}
}
void F_43 ( struct V_21 * V_22 , T_1 V_103 )
{
unsigned char V_111 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_112 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_42 ( V_22 , V_103 , 0 , V_111 , V_112 ) ;
}
int F_44 ( struct V_21 * V_22 )
{
unsigned int V_113 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
for ( V_113 = V_93 ; V_113 < V_94 ; V_113 ++ ) {
if ( V_27 -> V_95 [ V_113 ] . V_96 == 0 ) {
V_27 -> V_95 [ V_113 ] . V_96 = 1 ;
V_27 -> V_95 [ V_113 ] . V_114 = 0 ;
break;
}
}
return V_113 ;
}
void F_45 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
F_13 ( V_22 , V_102 , NULL ) ;
F_9 ( ( T_1 * ) ( V_27 -> V_95 ) , 0 , sizeof( V_27 -> V_95 ) ) ;
}
int F_46 ( struct V_21 * V_22 , struct V_115 * V_116 )
{
struct V_117 * V_118 = & ( V_22 -> V_119 ) ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
if ( V_118 -> V_120 . V_121 == 0 ) {
V_27 -> V_122 = 0 ;
return V_89 ;
}
V_27 -> V_122 = 1 ;
memcpy ( & ( V_27 -> V_123 ) , ( V_116 -> V_124 + 6 ) , sizeof( struct V_125 ) ) ;
return true ;
}
void F_47 ( struct V_21 * V_22 )
{
T_1 V_126 , V_127 , V_128 , V_129 , V_130 , V_131 ;
T_1 V_132 ;
T_4 V_133 ;
T_2 V_134 , V_3 ;
T_2 V_135 [ 4 ] , V_136 [ 4 ] ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_137 * V_138 = & V_22 -> V_139 ;
struct V_140 * V_141 = & V_22 -> V_142 ;
if ( V_27 -> V_122 == 0 ) {
V_22 -> V_119 . V_132 = 0 ;
return;
}
V_132 = 0 ;
if ( V_24 -> V_143 == V_6 )
V_131 = 10 ;
else
V_131 = 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_126 = ( V_27 -> V_123 . V_144 [ V_3 ] . V_145 >> 5 ) & 0x03 ;
V_127 = ( V_27 -> V_123 . V_144 [ V_3 ] . V_145 >> 4 ) & 0x01 ;
V_128 = ( V_27 -> V_123 . V_144 [ V_3 ] . V_145 & 0x0f ) * V_27 -> V_146 + V_131 ;
V_129 = ( V_27 -> V_123 . V_144 [ V_3 ] . V_147 & 0x0f ) ;
V_130 = ( V_27 -> V_123 . V_144 [ V_3 ] . V_147 & 0xf0 ) >> 4 ;
V_133 = F_35 ( V_27 -> V_123 . V_144 [ V_3 ] . V_148 ) ;
V_134 = V_128 | ( V_129 << 8 ) | ( V_130 << 12 ) | ( V_133 << 16 ) ;
switch ( V_126 ) {
case 0x0 :
F_13 ( V_22 , V_149 , ( T_1 * ) ( & V_134 ) ) ;
V_132 |= ( V_127 ? F_31 ( 1 ) : 0 ) ;
V_135 [ V_150 ] = V_134 ;
break;
case 0x1 :
F_13 ( V_22 , V_151 , ( T_1 * ) ( & V_134 ) ) ;
V_135 [ V_152 ] = V_134 ;
break;
case 0x2 :
F_13 ( V_22 , V_153 , ( T_1 * ) ( & V_134 ) ) ;
V_132 |= ( V_127 ? F_31 ( 2 ) : 0 ) ;
V_135 [ V_154 ] = V_134 ;
break;
case 0x3 :
F_13 ( V_22 , V_155 , ( T_1 * ) ( & V_134 ) ) ;
V_132 |= ( V_127 ? F_31 ( 3 ) : 0 ) ;
V_135 [ V_156 ] = V_134 ;
break;
}
F_29 ( L_2 , V_126 , V_127 , V_134 ) ;
}
if ( V_22 -> V_142 . V_157 == 1 )
F_13 ( V_22 , V_158 , ( T_1 * ) ( & V_132 ) ) ;
else
V_22 -> V_119 . V_132 = V_132 ;
V_136 [ 0 ] = 0 ; V_136 [ 1 ] = 1 ; V_136 [ 2 ] = 2 ; V_136 [ 3 ] = 3 ;
if ( V_141 -> V_159 == 1 ) {
T_2 V_108 , V_160 , V_161 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_108 = V_3 + 1 ; V_108 < 4 ; V_108 ++ ) {
if ( ( V_135 [ V_108 ] & 0xFFFF ) < ( V_135 [ V_3 ] & 0xFFFF ) ) {
V_161 = true ;
} else if ( ( V_135 [ V_108 ] & 0xFFFF ) == ( V_135 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_135 [ V_108 ] >> 16 ) > ( V_135 [ V_3 ] >> 16 ) )
V_161 = true ;
}
if ( V_161 ) {
V_160 = V_135 [ V_3 ] ;
V_135 [ V_3 ] = V_135 [ V_108 ] ;
V_135 [ V_108 ] = V_160 ;
V_160 = V_136 [ V_3 ] ;
V_136 [ V_3 ] = V_136 [ V_108 ] ;
V_136 [ V_108 ] = V_160 ;
V_161 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_138 -> V_162 [ V_3 ] = V_136 [ V_3 ] ;
F_29 ( L_3 , V_3 , V_138 -> V_162 [ V_3 ] ) ;
}
return;
}
static void F_48 ( struct V_21 * V_22 , struct V_115 * V_116 )
{
unsigned char V_163 ;
unsigned char V_164 ;
struct V_165 * V_166 ;
struct V_117 * V_118 = & ( V_22 -> V_119 ) ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_140 * V_167 = & V_22 -> V_142 ;
struct V_168 * V_169 = & V_118 -> V_170 ;
if ( ! V_116 )
return;
if ( ! V_169 )
return;
if ( V_116 -> V_171 > sizeof( struct V_165 ) )
return;
V_166 = (struct V_165 * ) V_116 -> V_124 ;
if ( ( V_166 -> V_172 [ 0 ] & F_31 ( 2 ) ) && V_167 -> V_173 ) {
V_163 = V_174 ;
switch ( V_166 -> V_172 [ 0 ] & 0x3 ) {
case 1 :
V_164 = V_80 ;
break;
case 3 :
V_164 = V_175 ;
break;
default:
V_164 = V_79 ;
break;
}
} else {
V_163 = V_78 ;
V_164 = V_79 ;
}
if ( ( V_163 != V_24 -> V_176 ) ||
( V_164 != V_24 -> V_177 ) ) {
V_27 -> V_178 = true ;
V_24 -> V_176 = V_163 ;
V_24 -> V_177 = V_164 ;
F_49 ( V_22 , V_116 ) ;
} else {
V_27 -> V_178 = false ;
}
if ( V_27 -> V_178 ) {
struct V_179 * V_180 ;
struct V_84 * V_181 = & ( V_27 -> V_182 ) ;
struct V_183 * V_184 = & V_22 -> V_185 ;
V_180 = F_50 ( V_184 , V_181 -> V_86 ) ;
if ( V_180 ) {
struct V_168 * V_186 = & V_180 -> V_170 ;
if ( V_186 -> V_187 ) {
V_186 -> V_72 = V_24 -> V_176 ;
V_186 -> V_188 = V_24 -> V_177 ;
} else {
V_186 -> V_72 = V_78 ;
V_186 -> V_188 = V_79 ;
}
}
}
}
void F_51 ( struct V_21 * V_22 , struct V_115 * V_116 )
{
unsigned int V_3 ;
T_1 V_189 ;
T_1 V_190 , V_191 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_117 * V_118 = & V_22 -> V_119 ;
struct V_168 * V_169 = & V_118 -> V_170 ;
if ( V_116 == NULL )
return;
if ( ! V_169 -> V_187 )
return;
V_27 -> V_192 = 1 ;
for ( V_3 = 0 ; V_3 < ( V_116 -> V_171 ) ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_27 -> V_193 . V_194 . V_195 [ V_3 ] &= ( V_116 -> V_124 [ V_3 ] ) ;
} else {
if ( ( V_27 -> V_193 . V_194 . V_196 . V_197 & 0x3 ) > ( V_116 -> V_124 [ V_3 ] & 0x3 ) )
V_190 = ( V_116 -> V_124 [ V_3 ] & 0x3 ) ;
else
V_190 = ( V_27 -> V_193 . V_194 . V_196 . V_197 & 0x3 ) ;
if ( ( V_27 -> V_193 . V_194 . V_196 . V_197 & 0x1c ) > ( V_116 -> V_124 [ V_3 ] & 0x1c ) )
V_191 = ( V_27 -> V_193 . V_194 . V_196 . V_197 & 0x1c ) ;
else
V_191 = ( V_116 -> V_124 [ V_3 ] & 0x1c ) ;
V_27 -> V_193 . V_194 . V_196 . V_197 = V_190 | V_191 ;
}
}
F_52 ( V_22 , V_198 , ( T_1 * ) ( & V_189 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( V_189 == V_199 ) || ( V_189 == V_200 ) )
V_27 -> V_193 . V_194 . V_196 . V_201 [ V_3 ] &= V_202 [ V_3 ] ;
else
V_27 -> V_193 . V_194 . V_196 . V_201 [ V_3 ] &= V_203 [ V_3 ] ;
}
return;
}
void F_49 ( struct V_21 * V_22 , struct V_115 * V_116 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_117 * V_118 = & V_22 -> V_119 ;
struct V_168 * V_169 = & V_118 -> V_170 ;
if ( V_116 == NULL )
return;
if ( ! V_169 -> V_187 )
return;
if ( V_116 -> V_171 > sizeof( struct V_165 ) )
return;
V_27 -> V_204 = 1 ;
memcpy ( & ( V_27 -> V_205 ) , V_116 -> V_124 , V_116 -> V_171 ) ;
return;
}
void F_53 ( struct V_21 * V_22 )
{
unsigned char V_190 ;
unsigned char V_191 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
F_29 ( L_4 , V_77 ) ;
if ( ( V_27 -> V_204 ) && ( V_27 -> V_192 ) ) {
V_27 -> V_30 = 1 ;
} else {
V_27 -> V_30 = 0 ;
return;
}
V_190 = V_27 -> V_193 . V_194 . V_196 . V_197 & 0x03 ;
V_191 = ( V_27 -> V_193 . V_194 . V_196 . V_197 & 0x1c ) >> 2 ;
F_13 ( V_22 , V_206 , ( T_1 * ) ( & V_191 ) ) ;
F_13 ( V_22 , V_207 , ( T_1 * ) ( & V_190 ) ) ;
}
void F_54 ( struct V_21 * V_22 , struct V_115 * V_116 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
if ( V_116 -> V_171 > 1 )
return;
V_27 -> V_208 = 1 ;
memcpy ( & ( V_27 -> V_209 ) , V_116 -> V_124 , V_116 -> V_171 ) ;
}
void F_55 ( struct V_21 * V_22 , struct V_179 * V_180 )
{
struct V_140 * V_141 = & V_22 -> V_142 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
switch ( V_141 -> V_210 ) {
case 0 :
V_180 -> V_211 = 0 ;
V_180 -> V_212 = 0 ;
break;
case 1 :
if ( V_141 -> V_213 == 1 ) {
V_180 -> V_211 = 1 ;
V_180 -> V_212 = 0 ;
} else {
V_180 -> V_211 = 0 ;
V_180 -> V_212 = 1 ;
}
break;
case 2 :
default:
if ( ( V_27 -> V_208 ) && ( V_27 -> V_209 & F_31 ( 1 ) ) ) {
if ( V_141 -> V_213 == 1 ) {
V_180 -> V_211 = 1 ;
V_180 -> V_212 = 0 ;
} else {
V_180 -> V_211 = 0 ;
V_180 -> V_212 = 1 ;
}
} else {
V_180 -> V_211 = 0 ;
V_180 -> V_212 = 0 ;
}
break;
}
}
int F_56 ( struct V_21 * V_53 , T_1 * V_214 , T_2 V_215 )
{
unsigned int V_47 ;
unsigned char * V_216 ;
unsigned short V_217 , V_218 ;
struct V_219 * V_181 = & ( V_53 -> V_119 . V_181 ) ;
T_4 V_220 = 0 , V_221 = 0 ;
T_1 V_222 = 0 ;
struct V_84 * V_223 ;
int V_224 = 0 , V_225 = 0 , V_226 = 0 ;
unsigned char * V_227 ;
T_2 V_228 = 0 ;
T_1 * V_229 = F_57 ( V_214 ) ;
T_2 V_230 = 0 ;
struct V_165 * V_231 = NULL ;
struct V_232 * V_233 = NULL ;
T_2 V_234 ;
unsigned short V_235 ;
unsigned char V_236 ;
if ( F_36 ( V_53 ) == false )
return true ;
V_47 = V_215 - sizeof( struct V_237 ) ;
if ( V_47 > V_238 ) {
F_29 ( L_5 , V_77 ) ;
return V_89 ;
}
if ( F_58 ( V_181 -> V_182 . V_86 , V_229 , 6 ) == false ) {
F_29 ( L_6 ,
( V_229 ) , ( V_181 -> V_182 . V_86 ) ) ;
return true ;
}
V_223 = (struct V_84 * ) F_59 ( sizeof( struct V_84 ) ) ;
V_218 = F_60 ( V_214 ) >> 4 ;
if ( V_218 == V_239 )
V_223 -> V_240 [ 0 ] = 1 ;
V_223 -> V_171 = sizeof( struct V_84 ) - V_238 + V_47 ;
V_223 -> V_241 = V_47 ;
memcpy ( V_223 -> V_88 , ( V_214 + sizeof( struct V_237 ) ) , V_223 -> V_241 ) ;
V_216 = F_61 ( V_223 -> V_88 + V_242 , V_243 , & V_47 , V_223 -> V_241 - V_242 ) ;
if ( V_216 && V_47 > 0 ) {
V_233 = (struct V_232 * ) ( V_216 + 2 ) ;
V_235 = V_233 -> V_244 ;
} else {
V_235 = 0 ;
}
V_216 = F_61 ( V_223 -> V_88 + V_242 , V_245 , & V_47 , V_223 -> V_241 - V_242 ) ;
if ( V_216 && V_47 > 0 ) {
V_231 = (struct V_165 * ) ( V_216 + 2 ) ;
V_236 = V_231 -> V_172 [ 0 ] ;
} else {
V_236 = 0 ;
}
if ( V_235 != V_181 -> V_246 . V_235 ||
( ( V_236 & 0x03 ) != ( V_181 -> V_246 . V_236 & 0x03 ) ) ) {
F_29 ( L_7 , V_77 ,
V_235 , V_236 ) ;
F_29 ( L_8 , V_77 ,
V_181 -> V_246 . V_235 , V_181 -> V_246 . V_236 ) ;
F_29 ( L_9 , V_77 ) ;
V_181 -> V_246 . V_235 = V_235 ;
V_181 -> V_246 . V_236 = V_236 ;
}
V_216 = F_61 ( V_223 -> V_88 + V_242 , V_247 , & V_47 , V_223 -> V_241 - V_242 ) ;
if ( V_216 ) {
V_234 = * ( V_216 + 2 ) ;
} else {
V_216 = F_61 ( V_223 -> V_88 + V_242 , V_245 , & V_47 , V_223 -> V_241 - V_242 ) ;
if ( V_231 ) {
V_234 = V_231 -> V_248 ;
} else {
F_29 ( L_10 , V_77 ) ;
V_234 = V_53 -> V_25 . V_29 ;
}
}
if ( V_234 != V_53 -> V_25 . V_29 ) {
F_29 ( L_11 , V_77 ,
V_234 , V_53 -> V_25 . V_29 ) ;
goto V_249;
}
V_216 = F_61 ( V_223 -> V_88 + V_242 , V_250 , & V_47 , V_223 -> V_241 - V_242 ) ;
if ( V_216 == NULL ) {
F_29 ( L_12 , V_77 ) ;
V_230 = true ;
} else {
V_230 = false ;
}
if ( ( NULL != V_216 ) && ( false == V_230 && ( * ( V_216 + 1 ) ) ) ) {
memcpy ( V_223 -> V_251 . V_251 , ( V_216 + 2 ) , * ( V_216 + 1 ) ) ;
V_223 -> V_251 . V_252 = * ( V_216 + 1 ) ;
} else {
V_223 -> V_251 . V_252 = 0 ;
V_223 -> V_251 . V_251 [ 0 ] = '\0' ;
}
F_62 ( V_253 , V_254 , ( L_13
L_14 , V_77 , V_223 -> V_251 . V_251 ,
V_223 -> V_251 . V_252 , V_181 -> V_182 . V_251 . V_251 ,
V_181 -> V_182 . V_251 . V_252 ) ) ;
if ( ! F_58 ( V_223 -> V_251 . V_251 , V_181 -> V_182 . V_251 . V_251 , 32 ) ||
V_223 -> V_251 . V_252 != V_181 -> V_182 . V_251 . V_252 ) {
if ( V_223 -> V_251 . V_251 [ 0 ] != '\0' && V_223 -> V_251 . V_252 != 0 ) {
F_29 ( L_15 , V_77 ) ;
goto V_249;
}
}
V_217 = F_63 ( (struct V_84 * ) V_223 ) ;
if ( V_217 & F_31 ( 4 ) )
V_223 -> V_255 = 1 ;
else
V_223 -> V_255 = 0 ;
F_62 ( V_253 , V_254 ,
( L_16 ,
V_77 , V_181 -> V_182 . V_255 , V_223 -> V_255 ) ) ;
if ( V_181 -> V_182 . V_255 != V_223 -> V_255 ) {
F_29 ( L_17 , V_77 ) ;
goto V_249;
}
F_64 ( V_223 -> V_88 , V_223 -> V_241 , NULL , & V_221 , NULL , & V_220 ) ;
if ( V_221 > 0 ) {
V_222 = V_256 ;
} else if ( V_220 > 0 ) {
V_222 = V_257 ;
} else {
if ( V_223 -> V_255 )
V_222 = V_258 ;
}
if ( V_181 -> V_246 . V_222 != V_222 ) {
F_29 ( L_18 , V_77 ) ;
goto V_249;
}
if ( V_222 == V_257 || V_222 == V_256 ) {
V_227 = F_65 ( & V_223 -> V_88 [ 12 ] , & V_228 , V_223 -> V_241 - 12 ) ;
if ( V_227 && ( V_228 > 0 ) ) {
if ( V_259 == F_66 ( V_227 , V_228 + 2 , & V_224 , & V_225 , & V_226 ) ) {
F_62 ( V_253 , V_254 ,
( L_19 , V_77 ,
V_225 , V_224 , V_226 ) ) ;
}
} else {
V_227 = F_67 ( & V_223 -> V_88 [ 12 ] , & V_228 , V_223 -> V_241 - 12 ) ;
if ( V_227 && ( V_228 > 0 ) ) {
if ( V_259 == F_68 ( V_227 , V_228 + 2 , & V_224 , & V_225 , & V_226 ) ) {
F_62 ( V_253 , V_254 ,
( L_20 ,
V_77 , V_225 , V_224 , V_226 ) ) ;
}
}
}
F_62 ( V_253 , V_260 ,
( L_21 , V_77 , V_181 -> V_246 . V_224 , V_224 ) ) ;
if ( V_225 != V_181 -> V_246 . V_225 || V_224 != V_181 -> V_246 . V_224 ) {
F_29 ( L_22 , V_77 ,
V_225 , V_181 -> V_246 . V_225 ,
V_224 , V_181 -> V_246 . V_224 ) ;
goto V_249;
}
if ( V_226 != V_181 -> V_246 . V_226 ) {
F_29 ( L_23 , V_77 ) ;
goto V_249;
}
}
F_69 ( V_223 ) ;
V_261 ;
return V_259 ;
V_249:
F_69 ( V_223 ) ;
V_261 ;
return V_89 ;
}
void F_70 ( struct V_21 * V_22 , T_1 * V_214 , T_6 V_262 , struct V_179 * V_180 )
{
unsigned int V_3 ;
unsigned int V_47 ;
struct V_115 * V_116 ;
V_47 = V_262 - ( V_263 + V_264 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; ) {
V_116 = (struct V_115 * ) ( V_214 + ( V_263 + V_264 ) + V_3 ) ;
switch ( V_116 -> V_265 ) {
case V_266 :
F_48 ( V_22 , V_116 ) ;
break;
case V_267 :
F_54 ( V_22 , V_116 ) ;
F_55 ( V_22 , V_180 ) ;
break;
default:
break;
}
V_3 += ( V_116 -> V_171 + 2 ) ;
}
}
unsigned int F_71 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_115 * V_116 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_84 * V_181 = & ( V_27 -> V_182 ) ;
if ( F_63 ( (struct V_84 * ) V_181 ) & V_268 ) {
for ( V_3 = sizeof( struct V_269 ) ; V_3 < V_27 -> V_182 . V_241 ; ) {
V_116 = (struct V_115 * ) ( V_27 -> V_182 . V_88 + V_3 ) ;
switch ( V_116 -> V_265 ) {
case V_270 :
if ( ( F_58 ( V_116 -> V_124 , V_271 , 4 ) ) && ( F_58 ( ( V_116 -> V_124 + 12 ) , V_272 , 4 ) ) )
return true ;
break;
case V_273 :
if ( F_58 ( ( V_116 -> V_124 + 8 ) , V_274 , 4 ) )
return true ;
default:
break;
}
V_3 += ( V_116 -> V_171 + 2 ) ;
}
return false ;
} else {
return false ;
}
}
unsigned int F_72 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_115 * V_116 ;
struct V_117 * V_118 = & V_22 -> V_119 ;
struct V_84 * V_181 = & V_118 -> V_181 . V_182 ;
if ( F_63 ( (struct V_84 * ) V_181 ) & V_268 ) {
for ( V_3 = sizeof( struct V_269 ) ; V_3 < V_181 -> V_241 ; ) {
V_116 = (struct V_115 * ) ( V_181 -> V_88 + V_3 ) ;
switch ( V_116 -> V_265 ) {
case V_270 :
if ( F_58 ( V_116 -> V_124 , V_271 , 4 ) &&
( ( F_58 ( ( V_116 -> V_124 + 12 ) , V_275 , 4 ) ) ||
( F_58 ( ( V_116 -> V_124 + 16 ) , V_275 , 4 ) ) ) )
return false ;
break;
case V_273 :
if ( ( F_58 ( ( V_116 -> V_124 + 8 ) , V_276 , 4 ) ) ||
( F_58 ( ( V_116 -> V_124 + 12 ) , V_276 , 4 ) ) )
return false ;
default:
break;
}
V_3 += ( V_116 -> V_171 + 2 ) ;
}
return true ;
} else {
return false ;
}
}
unsigned int F_73 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_115 * V_116 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_84 * V_181 = & ( V_27 -> V_182 ) ;
if ( F_63 ( (struct V_84 * ) V_181 ) & V_268 ) {
for ( V_3 = sizeof( struct V_269 ) ; V_3 < V_27 -> V_182 . V_241 ; ) {
V_116 = (struct V_115 * ) ( V_27 -> V_182 . V_88 + V_3 ) ;
switch ( V_116 -> V_265 ) {
case V_270 :
if ( F_58 ( V_116 -> V_124 , V_271 , 4 ) )
return false ;
break;
case V_273 :
return false ;
default:
break;
}
V_3 += ( V_116 -> V_171 + 2 ) ;
}
return true ;
} else {
return false ;
}
}
int F_74 ( unsigned char V_1 )
{
int V_136 = 0 ;
V_1 = V_1 & 0x7f ;
switch ( V_1 ) {
case 54 * 2 :
V_136 = 11 ;
break;
case 48 * 2 :
V_136 = 10 ;
break;
case 36 * 2 :
V_136 = 9 ;
break;
case 24 * 2 :
V_136 = 8 ;
break;
case 18 * 2 :
V_136 = 7 ;
break;
case 12 * 2 :
V_136 = 6 ;
break;
case 9 * 2 :
V_136 = 5 ;
break;
case 6 * 2 :
V_136 = 4 ;
break;
case 11 * 2 :
V_136 = 3 ;
break;
case 11 :
V_136 = 2 ;
break;
case 2 * 2 :
V_136 = 1 ;
break;
case 1 * 2 :
V_136 = 0 ;
break;
}
return V_136 ;
}
unsigned int F_75 ( unsigned char * V_277 , unsigned int V_278 )
{
unsigned int V_3 , V_279 ;
unsigned int V_280 = 0 ;
V_279 = ( V_278 > V_44 ) ? V_44 : V_278 ;
for ( V_3 = 0 ; V_3 < V_279 ; V_3 ++ ) {
if ( ( * ( V_277 + V_3 ) ) & 0x80 )
V_280 |= 0x1 << F_74 ( * ( V_277 + V_3 ) ) ;
}
return V_280 ;
}
unsigned int F_76 ( unsigned char * V_277 , unsigned int V_278 )
{
unsigned int V_3 , V_279 ;
unsigned int V_280 = 0 ;
V_279 = ( V_278 > V_44 ) ? V_44 : V_278 ;
for ( V_3 = 0 ; V_3 < V_279 ; V_3 ++ )
V_280 |= 0x1 << F_74 ( * ( V_277 + V_3 ) ) ;
return V_280 ;
}
unsigned int F_77 ( struct V_281 * V_282 )
{
unsigned int V_280 = 0 ;
V_280 = ( ( V_282 -> V_194 . V_196 . V_201 [ 0 ] << 12 ) | ( V_282 -> V_194 . V_196 . V_201 [ 1 ] << 20 ) ) ;
return V_280 ;
}
int F_78 ( struct V_21 * V_22 , struct V_281 * V_282 )
{
unsigned char V_283 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
if ( ! ( V_27 -> V_30 ) )
return V_89 ;
if ( ( V_27 -> V_284 == V_285 ) )
return V_89 ;
V_283 = ( V_24 -> V_176 & V_174 ) ? 6 : 5 ;
if ( F_79 ( V_282 -> V_194 . V_196 . V_286 ) & ( 0x1 << V_283 ) )
return V_259 ;
else
return V_89 ;
}
unsigned char F_80 ( T_2 V_280 )
{
int V_3 ;
unsigned char V_287 = 0 ;
for ( V_3 = 27 ; V_3 >= 0 ; V_3 -- ) {
if ( V_280 & F_31 ( V_3 ) ) {
V_287 = V_3 ;
break;
}
}
return V_287 ;
}
void F_81 ( struct V_21 * V_22 , T_2 V_113 )
{
F_82 ( V_22 , V_113 , 0 ) ;
}
static void F_83 ( struct V_21 * V_22 , T_2 V_113 )
{
F_81 ( V_22 , V_113 ) ;
}
void F_84 ( struct V_21 * V_22 , struct V_179 * V_180 )
{
F_83 ( V_22 , V_180 -> V_113 ) ;
}
void F_85 ( struct V_21 * V_22 , T_1 V_288 )
{
unsigned char V_289 [ V_55 ] ;
#ifdef F_86
struct V_290 * V_291 = & V_22 -> V_292 ;
if ( ! F_87 ( V_291 , V_293 ) )
return;
#endif
F_9 ( V_289 , 0 , V_55 ) ;
if ( ( V_288 & V_6 ) && ( V_288 == V_6 ) )
memcpy ( V_289 , V_294 , 4 ) ;
else if ( V_288 & V_6 )
memcpy ( V_289 , V_295 , 7 ) ;
else
memcpy ( V_289 , V_296 , 3 ) ;
if ( V_288 & V_6 )
F_88 ( V_22 , V_32 ) ;
else
F_88 ( V_22 , V_36 ) ;
F_13 ( V_22 , V_297 , V_289 ) ;
}
unsigned char F_89 ( T_1 * V_214 , T_6 V_47 )
{
unsigned int V_3 ;
struct V_115 * V_116 ;
T_1 V_298 ;
T_1 V_299 ;
V_298 = 0 ;
V_299 = 0 ;
for ( V_3 = sizeof( struct V_269 ) ; V_3 < V_47 ; ) {
V_116 = (struct V_115 * ) ( V_214 + V_3 ) ;
switch ( V_116 -> V_265 ) {
case V_270 :
if ( ( F_58 ( V_116 -> V_124 , V_300 , 3 ) ) ||
( F_58 ( V_116 -> V_124 , V_301 , 3 ) ) ) {
F_29 ( L_24 ) ;
return V_302 ;
} else if ( ( F_58 ( V_116 -> V_124 , V_303 , 3 ) ) ||
( F_58 ( V_116 -> V_124 , V_304 , 3 ) ) ||
( F_58 ( V_116 -> V_124 , V_304 , 3 ) ) ) {
F_29 ( L_25 ) ;
return V_305 ;
} else if ( F_58 ( V_116 -> V_124 , V_306 , 3 ) ) {
F_29 ( L_26 ) ;
return V_307 ;
} else if ( F_58 ( V_116 -> V_124 , V_308 , 3 ) ) {
if ( ! V_299 ) {
V_299 = 1 ;
} else {
F_29 ( L_27 ) ;
return V_285 ;
}
} else if ( F_58 ( V_116 -> V_124 , V_309 , 3 ) ) {
F_29 ( L_28 ) ;
return V_310 ;
} else if ( F_58 ( V_116 -> V_124 , V_311 , 3 ) ) {
F_29 ( L_29 ) ;
return V_312 ;
} else if ( F_58 ( V_116 -> V_124 , V_313 , 3 ) ) {
F_29 ( L_30 ) ;
return V_314 ;
} else if ( F_58 ( V_116 -> V_124 , V_315 , 3 ) ) {
V_298 = 1 ;
if ( V_299 ) {
F_29 ( L_31 ) ;
return V_316 ;
} else {
F_29 ( L_32 ) ;
}
} else {
break;
}
default:
break;
}
V_3 += ( V_116 -> V_171 + 2 ) ;
}
if ( V_299 && ! V_298 ) {
F_29 ( L_27 ) ;
return V_285 ;
} else if ( V_299 && V_298 ) {
F_29 ( L_31 ) ;
return V_316 ;
} else {
F_29 ( L_33 ) ;
return V_317 ;
}
}
void F_90 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
switch ( V_27 -> V_284 ) {
case V_307 :
V_27 -> V_318 = 1 ;
V_27 -> V_319 = 0 ;
break;
case V_285 :
V_27 -> V_318 = 0 ;
V_27 -> V_319 = 1 ;
F_15 ( V_22 , ( ~ V_320 ) , false ) ;
break;
case V_312 :
F_15 ( V_22 , ( ~ V_320 ) , false ) ;
break;
default:
V_27 -> V_318 = 0 ;
V_27 -> V_319 = 1 ;
break;
}
}
void F_91 ( struct V_21 * V_53 , T_4 V_321 )
{
struct V_23 * V_24 = & V_53 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
bool V_322 ;
if ( V_321 & V_323 ) {
if ( V_27 -> V_324 != V_325 ) {
V_322 = true ;
V_27 -> V_324 = V_325 ;
F_13 ( V_53 , V_326 , ( T_1 * ) & V_322 ) ;
}
} else {
if ( V_27 -> V_324 != V_327 ) {
V_322 = false ;
V_27 -> V_324 = V_327 ;
F_13 ( V_53 , V_326 , ( T_1 * ) & V_322 ) ;
}
}
if ( V_321 & V_328 ) {
V_27 -> V_146 = V_329 ;
} else {
if ( V_24 -> V_143 & ( V_9 | V_13 ) ) {
if ( V_321 & V_330 ) {
if ( V_27 -> V_146 != V_331 )
V_27 -> V_146 = V_331 ;
} else {
if ( V_27 -> V_146 != V_329 )
V_27 -> V_146 = V_329 ;
}
} else if ( V_24 -> V_143 & ( V_8 | V_14 ) ) {
V_27 -> V_146 = V_331 ;
} else {
V_27 -> V_146 = V_329 ;
}
}
F_13 ( V_53 , V_332 , & V_27 -> V_146 ) ;
}
void F_92 ( struct V_21 * V_22 )
{
int V_2 , V_4 = 0 ;
T_2 V_333 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
struct V_84 * V_181 = & ( V_27 -> V_182 ) ;
unsigned char * V_1 = V_181 -> V_334 ;
V_2 = F_93 ( V_181 -> V_334 ) ;
if ( ( V_27 -> V_204 ) && ( V_27 -> V_192 ) )
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
V_24 -> V_143 = V_4 & V_22 -> V_142 . V_335 ;
V_333 = 0x0a0a0808 ;
V_22 -> V_336 . V_337 ( V_22 , V_338 , ( T_1 * ) & V_333 ) ;
if ( V_24 -> V_143 & V_6 )
F_88 ( V_22 , V_32 ) ;
else
F_88 ( V_22 , V_36 ) ;
}
void F_94 ( struct V_21 * V_22 , T_2 V_113 )
{
struct V_23 * V_24 = & ( V_22 -> V_25 ) ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
if ( V_24 -> V_143 & V_6 ) {
memcpy ( ( V_27 -> V_95 [ V_113 ] . V_334 ) , V_294 , 4 ) ;
} else {
memcpy ( ( V_27 -> V_95 [ V_113 ] . V_334 ) , V_296 , 3 ) ;
}
}
int F_95 ( struct V_21 * V_22 , T_1 * V_339 , T_6 V_340 , int V_341 )
{
unsigned int V_342 ;
struct V_115 * V_116 ;
int V_343 = 0 ;
struct V_23 * V_24 = & ( V_22 -> V_25 ) ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
V_116 = (struct V_115 * ) F_61 ( V_339 , V_344 , & V_342 , V_340 ) ;
if ( V_116 == NULL )
return V_89 ;
memcpy ( V_27 -> V_95 [ V_341 ] . V_334 , V_116 -> V_124 , V_342 ) ;
V_343 = V_342 ;
V_116 = (struct V_115 * ) F_61 ( V_339 , V_345 , & V_342 , V_340 ) ;
if ( V_116 )
memcpy ( ( V_27 -> V_95 [ V_341 ] . V_334 + V_343 ) , V_116 -> V_124 , V_342 ) ;
return V_259 ;
}
void F_96 ( struct V_21 * V_22 , T_1 * V_346 , T_1 * V_107 )
{
struct V_179 * V_180 ;
T_4 V_347 ;
T_4 V_348 ;
struct V_349 * V_350 ;
struct V_183 * V_184 = & V_22 -> V_185 ;
struct V_351 * V_352 = (struct V_351 * ) V_346 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & ( V_24 -> V_28 ) ;
V_180 = F_50 ( V_184 , V_107 ) ;
if ( V_180 ) {
V_348 = F_35 ( V_352 -> V_353 ) ;
V_347 = ( V_348 >> 2 ) & 0x0f ;
V_350 = & V_180 -> V_354 [ V_347 ] ;
V_350 -> V_355 = 0xffff ;
V_350 -> V_61 = ( V_27 -> V_356 ) ? true : false ;
}
}
void F_97 ( struct V_23 * V_24 , T_1 * V_214 , T_6 V_47 )
{
T_1 * V_116 ;
T_7 * V_227 ;
V_116 = V_214 + sizeof( struct V_237 ) ;
V_227 = ( T_7 * ) V_116 ;
V_24 -> V_357 = F_98 ( * ( V_227 + 1 ) ) ;
V_24 -> V_357 = V_24 -> V_357 << 32 ;
V_24 -> V_357 |= F_98 ( * V_227 ) ;
}
void F_99 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
F_13 ( V_22 , V_358 , NULL ) ;
}
void F_100 ( struct V_21 * V_22 )
{
F_101 ( V_22 ) ;
}
int F_102 ( struct V_21 * V_21 , bool V_359 )
{
int V_96 = V_259 ;
if ( V_359 ) {
if ( V_360 == NULL ) {
V_360 = V_21 ;
F_29 ( L_34 , V_77 ) ;
} else {
V_21 -> V_361 = V_360 ;
V_360 -> V_361 = V_21 ;
V_360 = NULL ;
F_29 ( L_35 , V_77 ) ;
}
} else {
V_360 = NULL ;
}
return V_96 ;
}
