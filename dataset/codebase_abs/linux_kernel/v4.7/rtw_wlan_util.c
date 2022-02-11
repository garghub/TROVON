int F_1 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( ( ( V_1 [ V_3 ] ) & 0x7f ) == 2 || ( ( V_1 [ V_3 ] ) & 0x7f ) == 4 ||
( ( V_1 [ V_3 ] ) & 0x7f ) == 11 || ( ( V_1 [ V_3 ] ) & 0x7f ) == 22 )
return true ;
}
return false ;
}
int F_2 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( ( ( V_1 [ V_3 ] ) & 0x7f ) != 2 && ( ( V_1 [ V_3 ] ) & 0x7f ) != 4 &&
( ( V_1 [ V_3 ] ) & 0x7f ) != 11 && ( ( V_1 [ V_3 ] ) & 0x7f ) != 22 )
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
T_1 F_4 ( struct V_21 * V_22 ,
unsigned char * V_1 , int V_2 )
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
if ( V_31 != 0xff && V_31 != 0xfe ) {
if ( V_1 == F_5 ( V_31 ) )
return true ;
}
}
return false ;
}
static unsigned int F_7 ( struct V_21 * V_22 ,
unsigned char * V_46 )
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
void F_8 ( struct V_21 * V_22 ,
unsigned char * V_50 , int * V_51 )
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
inline T_1 F_11 ( struct V_21 * V_58 )
{
return F_12 ( V_58 ) -> V_59 ;
}
inline void F_13 ( struct V_21 * V_58 , T_1 V_60 )
{
F_12 ( V_58 ) -> V_59 = V_60 ;
}
inline void F_14 ( struct V_21 * V_58 , T_1 V_61 )
{
F_12 ( V_58 ) -> V_62 = V_61 ;
}
inline void F_15 ( struct V_21 * V_58 , T_1 V_63 )
{
F_12 ( V_58 ) -> V_64 = V_63 ;
}
void F_16 ( struct V_21 * V_22 , unsigned char V_65 )
{
F_17 ( & F_12 ( V_22 ) -> V_66 ) ;
F_13 ( V_22 , V_65 ) ;
F_18 ( V_22 , V_65 ) ;
F_19 ( & F_12 ( V_22 ) -> V_66 ) ;
}
static void F_20 ( struct V_21 * V_22 , unsigned short V_67 ,
unsigned char V_68 )
{
F_17 ( & F_12 ( V_22 ) -> V_69 ) ;
F_14 ( V_22 , V_67 ) ;
F_15 ( V_22 , V_68 ) ;
F_21 ( V_22 , (enum V_70 ) V_67 ,
V_68 ) ;
F_19 ( & F_12 ( V_22 ) -> V_69 ) ;
}
void F_22 ( struct V_21 * V_22 , unsigned char V_65 ,
unsigned char V_68 , unsigned short V_67 )
{
T_1 V_71 ;
if ( V_67 == V_72 ||
V_68 == V_73 ) {
V_71 = V_65 ;
} else {
if ( V_68 == V_74 ) {
V_71 = V_65 + 2 ;
} else {
V_71 = V_65 - 2 ;
}
}
F_17 ( & F_12 ( V_22 ) -> V_66 ) ;
F_13 ( V_22 , V_65 ) ;
F_14 ( V_22 , V_67 ) ;
F_15 ( V_22 , V_68 ) ;
F_18 ( V_22 , V_71 ) ;
F_19 ( & F_12 ( V_22 ) -> V_66 ) ;
F_20 ( V_22 , V_67 , V_68 ) ;
}
inline T_1 * F_23 ( struct V_75 * V_76 )
{
return V_76 -> V_77 ;
}
bool F_24 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_22 )
return false ;
V_24 = & V_22 -> V_25 ;
V_27 = & V_24 -> V_28 ;
if ( V_27 -> V_78 & V_79 &&
( V_27 -> V_78 & 0x03 ) == V_80 )
return true ;
else
return false ;
}
bool F_25 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_27 -> V_78 & V_79 &&
( V_27 -> V_78 & 0x03 ) == V_81 )
return true ;
else
return false ;
}
bool F_26 ( struct V_21 * V_22 )
{
unsigned int V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_3 = V_82 ; V_3 < V_83 ; V_3 ++ ) {
if ( V_27 -> V_84 [ V_3 ] . V_85 == 1 )
return false ;
}
return true ;
}
unsigned int F_27 ( unsigned int V_86 )
{
if ( ( V_86 << 2 ) < V_87 )
return V_87 ;
else if ( ( V_86 << 2 ) > V_88 )
return V_88 ;
else
return V_86 << 2 ;
}
void F_28 ( struct V_21 * V_22 , T_1 V_89 )
{
unsigned char V_90 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_91 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
F_29 ( V_22 , V_89 , 0 , V_90 , V_91 ) ;
}
int F_30 ( struct V_21 * V_22 )
{
unsigned int V_92 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_92 = V_82 ; V_92 < V_83 ; V_92 ++ ) {
if ( V_27 -> V_84 [ V_92 ] . V_85 == 0 ) {
V_27 -> V_84 [ V_92 ] . V_85 = 1 ;
V_27 -> V_84 [ V_92 ] . V_93 = 0 ;
break;
}
}
return V_92 ;
}
void F_31 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_32 ( V_22 ) ;
memset ( V_27 -> V_84 , 0 , sizeof( V_27 -> V_84 ) ) ;
}
int F_33 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_96 -> V_98 == 0 ) {
V_27 -> V_99 = 0 ;
return V_100 ;
}
V_27 -> V_99 = 1 ;
memcpy ( & V_27 -> V_101 , V_94 + 2 + 6 ,
sizeof( struct V_102 ) ) ;
return true ;
}
void F_34 ( struct V_21 * V_22 )
{
T_1 V_103 , V_104 , V_105 , V_106 , V_107 , V_108 ;
T_1 V_109 ;
T_3 V_110 ;
T_2 V_111 , V_3 ;
T_2 V_112 [ 4 ] , V_113 [ 4 ] ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_114 * V_115 = & V_22 -> V_116 ;
struct V_117 * V_118 = & V_22 -> V_119 ;
if ( V_27 -> V_99 == 0 ) {
V_22 -> V_97 . V_109 = 0 ;
return;
}
V_109 = 0 ;
if ( V_24 -> V_120 == V_6 )
V_108 = 10 ;
else
V_108 = 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_103 = ( V_27 -> V_101 . V_121 [ V_3 ] . V_122 >> 5 ) & 0x03 ;
V_104 = ( V_27 -> V_101 . V_121 [ V_3 ] . V_122 >> 4 ) & 0x01 ;
V_105 = ( V_27 -> V_101 . V_121 [ V_3 ] . V_122 & 0x0f ) *
V_27 -> V_123 + V_108 ;
V_106 = V_27 -> V_101 . V_121 [ V_3 ] . V_124 & 0x0f ;
V_107 = ( V_27 -> V_101 . V_121 [ V_3 ] . V_124 & 0xf0 ) >> 4 ;
V_110 = F_35 ( V_27 -> V_101 . V_121 [ V_3 ] . V_125 ) ;
V_111 = V_105 | ( V_106 << 8 ) | ( V_107 << 12 ) | ( V_110 << 16 ) ;
switch ( V_103 ) {
case 0x0 :
F_36 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_37 ( 1 ) : 0 ) ;
V_112 [ V_126 ] = V_111 ;
break;
case 0x1 :
F_38 ( V_22 , V_111 ) ;
V_112 [ V_127 ] = V_111 ;
break;
case 0x2 :
F_39 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_37 ( 2 ) : 0 ) ;
V_112 [ V_128 ] = V_111 ;
break;
case 0x3 :
F_40 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_37 ( 3 ) : 0 ) ;
V_112 [ V_129 ] = V_111 ;
break;
}
F_41 ( L_1 , V_103 , V_104 , V_111 ) ;
}
if ( V_22 -> V_119 . V_130 == 1 )
F_42 ( V_22 , V_109 ) ;
else
V_22 -> V_97 . V_109 = V_109 ;
V_113 [ 0 ] = 0 ; V_113 [ 1 ] = 1 ; V_113 [ 2 ] = 2 ; V_113 [ 3 ] = 3 ;
if ( V_118 -> V_131 == 1 ) {
T_2 V_132 , V_133 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_132 = V_3 + 1 ; V_132 < 4 ; V_132 ++ ) {
if ( ( V_112 [ V_132 ] & 0xFFFF ) < ( V_112 [ V_3 ] & 0xFFFF ) ) {
V_133 = true ;
} else if ( ( V_112 [ V_132 ] & 0xFFFF ) ==
( V_112 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_112 [ V_132 ] >> 16 ) > ( V_112 [ V_3 ] >> 16 ) )
V_133 = true ;
}
if ( V_133 ) {
F_43 ( V_112 [ V_3 ] , V_112 [ V_132 ] ) ;
F_43 ( V_113 [ V_3 ] , V_113 [ V_132 ] ) ;
V_133 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_115 -> V_134 [ V_3 ] = V_113 [ V_3 ] ;
F_41 ( L_2 , V_3 ,
V_115 -> V_134 [ V_3 ] ) ;
}
}
static void F_44 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_135 * V_136 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_117 * V_137 = & V_22 -> V_119 ;
struct V_138 * V_139 = & V_96 -> V_140 ;
unsigned char V_141 ;
unsigned char V_142 ;
if ( ! V_94 )
return;
if ( ! V_139 -> V_143 )
return;
if ( V_94 [ 1 ] != sizeof( struct V_135 ) )
return;
V_136 = (struct V_135 * ) ( V_94 + 2 ) ;
if ( ( V_136 -> V_144 & V_145 ) &&
V_137 -> V_146 ) {
V_141 = V_147 ;
switch ( V_136 -> V_144 & V_148 ) {
case V_149 :
V_142 = V_74 ;
break;
case V_150 :
V_142 = V_151 ;
break;
default:
V_142 = V_73 ;
break;
}
} else {
V_141 = V_72 ;
V_142 = V_73 ;
}
if ( V_141 != V_24 -> V_152 ||
V_142 != V_24 -> V_153 ) {
V_27 -> V_154 = true ;
V_24 -> V_152 = V_141 ;
V_24 -> V_153 = V_142 ;
F_45 ( V_22 , V_94 ) ;
} else
V_27 -> V_154 = false ;
if ( V_27 -> V_154 ) {
struct V_155 * V_156 ;
struct V_75 * V_157 = & V_27 -> V_158 ;
struct V_159 * V_160 = & V_22 -> V_161 ;
V_156 = F_46 ( V_160 , V_157 -> V_77 ) ;
if ( V_156 ) {
struct V_138 * V_162 = & V_156 -> V_140 ;
if ( V_162 -> V_143 ) {
V_162 -> V_67 = V_24 -> V_152 ;
V_162 -> V_163 =
V_24 -> V_153 ;
} else {
V_162 -> V_67 = V_72 ;
V_162 -> V_163 =
V_73 ;
}
}
}
}
void F_47 ( struct V_21 * V_22 , const T_1 * V_94 )
{
unsigned int V_3 ;
T_1 V_164 ;
T_1 V_165 , V_166 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_138 * V_139 = & V_96 -> V_140 ;
struct V_167 * V_168 ;
T_1 * V_169 ;
if ( ! V_94 )
return;
if ( ! V_139 -> V_143 )
return;
V_27 -> V_170 = 1 ;
V_168 = & V_27 -> V_171 ;
V_169 = ( T_1 * ) V_168 ;
for ( V_3 = 0 ; V_3 < V_94 [ 1 ] ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_169 [ V_3 ] &= V_94 [ V_3 + 2 ] ;
} else {
if ( ( V_168 -> V_172 &
V_173 ) >
( V_94 [ V_3 + 2 ] & V_173 ) )
V_165 = V_94 [ V_3 + 2 ] &
V_173 ;
else
V_165 = V_168 -> V_172 &
V_173 ;
if ( ( V_168 -> V_172 &
V_174 ) >
( V_94 [ V_3 + 2 ] & V_174 ) )
V_166 = V_168 -> V_172 &
V_174 ;
else
V_166 = V_94 [ V_3 + 2 ] &
V_174 ;
V_168 -> V_172 =
V_165 | V_166 ;
}
}
V_164 = F_48 ( V_22 ) ;
for ( V_3 = 0 ; V_3 < V_175 ; V_3 ++ ) {
if ( V_164 == V_176 || V_164 == V_177 )
V_168 -> V_178 . V_179 [ V_3 ] &= V_180 [ V_3 ] ;
else
V_168 -> V_178 . V_179 [ V_3 ] &= V_181 [ V_3 ] ;
}
}
void F_45 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_138 * V_139 = & V_96 -> V_140 ;
if ( ! V_94 )
return;
if ( ! V_139 -> V_143 )
return;
if ( V_94 [ 1 ] != sizeof( struct V_135 ) )
return;
V_27 -> V_182 = 1 ;
memcpy ( & V_27 -> V_183 , V_94 + 2 , V_94 [ 1 ] ) ;
}
void F_49 ( struct V_21 * V_22 )
{
unsigned char V_165 ;
unsigned char V_166 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_41 ( L_3 , V_184 ) ;
if ( V_27 -> V_182 && V_27 -> V_170 )
V_27 -> V_30 = 1 ;
else {
V_27 -> V_30 = 0 ;
return;
}
V_165 = V_27 -> V_171 . V_172 &
V_173 ;
V_166 =
( V_27 -> V_171 . V_172 &
V_174 ) >> 2 ;
F_50 ( V_22 , V_166 ) ;
F_51 ( V_22 , V_165 ) ;
}
void F_52 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_94 [ 1 ] > 1 )
return;
V_27 -> V_185 = 1 ;
memcpy ( & V_27 -> V_186 , V_94 + 2 , V_94 [ 1 ] ) ;
}
void F_53 ( struct V_21 * V_22 , struct V_155 * V_156 )
{
struct V_117 * V_118 = & V_22 -> V_119 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_118 -> V_187 ) {
case 0 :
V_156 -> V_188 = 0 ;
V_156 -> V_189 = 0 ;
break;
case 1 :
if ( V_118 -> V_190 == V_191 ) {
V_156 -> V_188 = 1 ;
V_156 -> V_189 = 0 ;
} else {
V_156 -> V_188 = 0 ;
V_156 -> V_189 = 1 ;
}
break;
case 2 :
default:
if ( V_27 -> V_185 && V_27 -> V_186 & F_37 ( 1 ) ) {
if ( V_118 -> V_190 == V_191 ) {
V_156 -> V_188 = 1 ;
V_156 -> V_189 = 0 ;
} else {
V_156 -> V_188 = 0 ;
V_156 -> V_189 = 1 ;
}
} else {
V_156 -> V_188 = 0 ;
V_156 -> V_189 = 0 ;
}
break;
}
}
int F_54 ( struct V_21 * V_53 ,
struct V_192 * V_193 , T_2 V_194 )
{
struct V_195 * V_157 = & V_53 -> V_97 . V_157 ;
struct V_135 * V_196 ;
unsigned short V_197 ;
T_1 V_198 , V_199 ;
int V_200 = 0 , V_201 = 0 , V_202 = 0 , V_203 ;
int V_204 , V_205 , V_206 ;
const T_1 * V_94 , * V_207 ;
if ( ! F_24 ( V_53 ) )
return V_208 ;
if ( F_55 ( ! F_56 ( V_193 -> V_209 ) ) ) {
F_57 ( V_210 L_4 ,
V_184 ) ;
return V_100 ;
}
if ( ! F_58 ( V_157 -> V_158 . V_77 , V_193 -> V_211 ) ) {
F_41 ( L_5 ,
V_184 , V_193 -> V_211 ,
V_157 -> V_158 . V_77 ) ;
return V_100 ;
}
V_204 = V_194 - F_59 ( struct V_192 , V_212 . V_213 . V_214 ) ;
V_94 = F_60 ( V_215 , V_193 -> V_212 . V_213 . V_214 ,
V_204 ) ;
if ( V_94 )
V_199 = V_94 [ 2 ] ;
else {
V_94 = F_60 ( V_216 ,
V_193 -> V_212 . V_213 . V_214 , V_204 ) ;
if ( V_94 && V_94 [ 1 ] > 0 ) {
V_196 = (struct V_135 * ) ( V_94 + 2 ) ;
V_199 = V_196 -> V_217 ;
} else {
F_41 ( L_6
L_7 , V_184 ) ;
V_199 = V_53 -> V_25 . V_29 ;
}
}
if ( V_199 != V_53 -> V_25 . V_29 ) {
F_41 ( L_8 ,
V_184 , V_199 ,
V_53 -> V_25 . V_29 ) ;
goto V_218;
}
V_94 = F_60 ( V_219 , V_193 -> V_212 . V_213 . V_214 , V_204 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_207 = V_94 + 2 ;
V_205 = V_94 [ 1 ] ;
} else {
F_41 ( L_9 ,
V_184 ) ;
V_207 = NULL ;
V_205 = 0 ;
}
F_61 ( V_220 , V_221 ,
L_10 ,
V_184 , V_207 , V_205 , V_157 -> V_158 . V_222 . V_207 ,
V_157 -> V_158 . V_222 . V_205 ) ;
if ( V_205 != V_157 -> V_158 . V_222 . V_205 || V_205 > 32 ||
( V_205 &&
memcmp ( V_207 , V_157 -> V_158 . V_222 . V_207 , V_205 ) ) ) {
F_41 ( L_11 , V_184 ) ;
goto V_218;
}
V_197 = F_35 ( V_193 -> V_212 . V_213 . V_223 ) ;
if ( V_197 & V_224 )
V_206 = 1 ;
else
V_206 = 0 ;
F_61 ( V_220 , V_221 ,
L_12 ,
V_184 , V_157 -> V_158 . V_225 , V_206 ) ;
if ( V_157 -> V_158 . V_225 != V_206 ) {
F_41 ( L_13 , V_184 ) ;
goto V_218;
}
V_94 = F_60 ( V_226 , V_193 -> V_212 . V_213 . V_214 , V_204 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_198 = V_227 ;
if ( V_94 && V_94 [ 1 ] ) {
V_203 = F_62 ( V_94 , V_94 [ 1 ] + 2 , & V_200 ,
& V_201 , & V_202 ) ;
if ( V_203 == V_208 )
F_61 ( V_220 , V_221 ,
L_14 ,
V_184 , V_201 ,
V_200 , V_202 ) ;
}
} else {
V_94 = F_63 ( V_228 ,
V_229 ,
V_193 -> V_212 . V_213 . V_214 , V_204 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_198 = V_230 ;
V_203 = F_64 ( V_94 , V_94 [ 1 ] + 2 , & V_200 ,
& V_201 , & V_202 ) ;
if ( V_203 == V_208 )
F_61 ( V_220 , V_221 ,
L_15 ,
V_184 , V_201 ,
V_200 , V_202 ) ;
} else {
if ( V_206 )
V_198 = V_231 ;
else
V_198 = V_232 ;
}
}
if ( V_157 -> V_233 . V_234 != V_198 ) {
F_41 ( L_16 , V_184 ) ;
goto V_218;
}
if ( V_198 == V_230 || V_198 == V_227 ) {
F_61 ( V_220 , V_235 ,
L_17 , V_184 ,
V_157 -> V_233 . V_200 , V_200 ) ;
if ( V_201 != V_157 -> V_233 . V_201 ||
V_200 != V_157 -> V_233 . V_200 ) {
F_41 ( L_18
L_19 ,
V_184 , V_201 ,
V_157 -> V_233 . V_201 ,
V_200 ,
V_157 -> V_233 . V_200 ) ;
goto V_218;
}
if ( V_202 != V_157 -> V_233 . V_202 ) {
F_41 ( L_20
L_21 , V_184 ) ;
goto V_218;
}
}
return V_208 ;
V_218:
return V_100 ;
}
void F_65 ( struct V_21 * V_22 ,
struct V_192 * V_193 ,
T_4 V_194 , struct V_155 * V_156 )
{
unsigned int V_47 ;
const T_1 * V_94 ;
V_47 = V_194 - F_59 ( struct V_192 , V_212 . V_213 . V_214 ) ;
V_94 = F_60 ( V_216 , V_193 -> V_212 . V_213 . V_214 ,
V_47 ) ;
if ( V_94 )
F_44 ( V_22 , V_94 ) ;
V_94 = F_60 ( V_236 , V_193 -> V_212 . V_213 . V_214 , V_47 ) ;
if ( V_94 ) {
F_52 ( V_22 , V_94 ) ;
F_53 ( V_22 , V_156 ) ;
}
}
bool F_66 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_157 = & V_27 -> V_158 ;
const T_1 * V_94 ;
if ( V_157 -> V_237 & V_224 ) {
for ( V_3 = 0 ; V_3 < V_27 -> V_158 . V_238 ; ) {
V_94 = V_27 -> V_158 . V_239 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_240 :
if ( ! memcmp ( V_94 + 2 , V_241 , 4 ) &&
! memcmp ( V_94 + 2 + 12 , V_242 , 4 ) )
return true ;
break;
case V_226 :
if ( ! memcmp ( V_94 + 2 + 8 , V_243 , 4 ) )
return true ;
break;
default:
break;
}
V_3 += ( V_94 [ 1 ] + 2 ) ;
}
return false ;
} else
return false ;
}
bool F_67 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_75 * V_157 = & V_96 -> V_157 . V_158 ;
const T_1 * V_94 ;
if ( V_157 -> V_237 & V_224 ) {
for ( V_3 = 0 ; V_3 < V_157 -> V_238 ; ) {
V_94 = V_157 -> V_239 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_240 :
if ( ! memcmp ( V_94 + 2 , V_241 , 4 ) &&
( ! memcmp ( V_94 + 2 + 12 ,
V_244 , 4 ) ||
! memcmp ( V_94 + 2 + 16 ,
V_244 , 4 ) ) )
return false ;
break;
case V_226 :
if ( ! memcmp ( V_94 + 2 + 8 ,
V_245 , 4 ) ||
! memcmp ( V_94 + 2 + 12 ,
V_245 , 4 ) )
return false ;
default:
break;
}
V_3 += ( V_94 [ 1 ] + 2 ) ;
}
return true ;
} else {
return false ;
}
}
bool F_68 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_157 = & V_27 -> V_158 ;
const T_1 * V_94 ;
if ( V_157 -> V_237 & V_224 ) {
for ( V_3 = 0 ; V_3 < V_27 -> V_158 . V_238 ; ) {
V_94 = V_27 -> V_158 . V_239 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_240 :
if ( ! memcmp ( V_94 + 2 , V_241 , 4 ) )
return false ;
break;
case V_226 :
return false ;
default:
break;
}
V_3 += ( V_94 [ 1 ] + 2 ) ;
}
return true ;
} else
return false ;
}
static int F_69 ( unsigned char V_1 )
{
int V_113 = 0 ;
V_1 = V_1 & 0x7f ;
switch ( V_1 ) {
case 54 * 2 :
V_113 = 11 ;
break;
case 48 * 2 :
V_113 = 10 ;
break;
case 36 * 2 :
V_113 = 9 ;
break;
case 24 * 2 :
V_113 = 8 ;
break;
case 18 * 2 :
V_113 = 7 ;
break;
case 12 * 2 :
V_113 = 6 ;
break;
case 9 * 2 :
V_113 = 5 ;
break;
case 6 * 2 :
V_113 = 4 ;
break;
case 11 * 2 :
V_113 = 3 ;
break;
case 11 :
V_113 = 2 ;
break;
case 2 * 2 :
V_113 = 1 ;
break;
case 1 * 2 :
V_113 = 0 ;
break;
}
return V_113 ;
}
unsigned int F_70 ( unsigned char * V_246 , unsigned int V_247 )
{
unsigned int V_3 , V_248 ;
unsigned int V_249 = 0 ;
V_248 = ( V_247 > V_44 ) ? V_44 : V_247 ;
for ( V_3 = 0 ; V_3 < V_248 ; V_3 ++ ) {
if ( ( * ( V_246 + V_3 ) ) & 0x80 )
V_249 |= 0x1 << F_69 ( * ( V_246 + V_3 ) ) ;
}
return V_249 ;
}
unsigned int F_71 ( unsigned char * V_246 , unsigned int V_247 )
{
unsigned int V_3 , V_248 ;
unsigned int V_249 = 0 ;
V_248 = ( V_247 > V_44 ) ? V_44 : V_247 ;
for ( V_3 = 0 ; V_3 < V_248 ; V_3 ++ )
V_249 |= 0x1 << F_69 ( * ( V_246 + V_3 ) ) ;
return V_249 ;
}
unsigned int F_72 ( struct V_167 * V_250 )
{
unsigned int V_249 ;
V_249 = V_250 -> V_178 . V_179 [ 0 ] << 12 |
V_250 -> V_178 . V_179 [ 1 ] << 20 ;
return V_249 ;
}
int F_73 ( struct V_21 * V_22 ,
struct V_167 * V_250 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
unsigned char V_251 ;
if ( ! V_27 -> V_30 )
return V_100 ;
if ( V_27 -> V_252 == V_253 )
return V_100 ;
V_251 = ( V_24 -> V_152 & V_147 ) ? 6 : 5 ;
if ( V_250 -> V_254 & F_74 ( 0x1 << V_251 ) )
return V_208 ;
else
return V_100 ;
}
unsigned char F_75 ( T_2 V_249 )
{
int V_3 ;
unsigned char V_255 = 0 ;
for ( V_3 = 27 ; V_3 >= 0 ; V_3 -- ) {
if ( V_249 & F_37 ( V_3 ) ) {
V_255 = V_3 ;
break;
}
}
return V_255 ;
}
void F_76 ( struct V_21 * V_22 , struct V_155 * V_156 )
{
F_77 ( V_156 , 0 ) ;
}
static void F_78 ( struct V_21 * V_22 ,
struct V_155 * V_156 )
{
F_76 ( V_22 , V_156 ) ;
}
void F_79 ( struct V_21 * V_22 , struct V_155 * V_156 )
{
F_78 ( V_22 , V_156 ) ;
}
void F_80 ( struct V_21 * V_22 , T_1 V_256 )
{
unsigned char V_257 [ V_55 ] ;
memset ( V_257 , 0 , V_55 ) ;
if ( V_256 == V_6 ) {
memcpy ( V_257 , V_258 , 4 ) ;
} else if ( V_256 & V_6 ) {
memcpy ( V_257 , V_259 , 7 ) ;
} else {
memcpy ( V_257 , V_260 , 3 ) ;
}
if ( V_256 & V_6 )
F_81 ( V_22 , V_32 ) ;
else
F_81 ( V_22 , V_36 ) ;
F_82 ( V_22 , V_257 ) ;
}
unsigned char F_83 ( T_1 * V_261 , T_4 V_47 )
{
int V_3 ;
T_1 V_262 ;
T_1 V_263 ;
const T_1 * V_94 ;
V_262 = 0 ;
V_263 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 ; ) {
V_94 = V_261 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_240 :
if ( ! memcmp ( V_94 + 2 , V_264 , 3 ) ||
! memcmp ( V_94 + 2 , V_265 , 3 ) ) {
F_41 ( L_22 ) ;
return V_266 ;
} else if ( ! memcmp ( V_94 + 2 , V_267 , 3 ) ||
! memcmp ( V_94 + 2 , V_268 , 3 ) ) {
F_41 ( L_23 ) ;
return V_269 ;
} else if ( ! memcmp ( V_94 + 2 , V_270 , 3 ) ) {
F_41 ( L_24 ) ;
return V_271 ;
} else if ( ! memcmp ( V_94 + 2 , V_272 , 3 ) ) {
if ( ! V_263 )
V_263 = 1 ;
else {
F_41 ( L_25 ) ;
return V_253 ;
}
} else if ( ! memcmp ( V_94 + 2 , V_273 , 3 ) ) {
F_41 ( L_26 ) ;
return V_274 ;
} else if ( ! memcmp ( V_94 + 2 , V_275 , 3 ) ) {
F_41 ( L_27 ) ;
return V_276 ;
} else if ( ! memcmp ( V_94 + 2 , V_277 , 3 ) ) {
F_41 ( L_28 ) ;
return V_278 ;
} else if ( ! memcmp ( V_94 + 2 , V_279 , 3 ) ) {
V_262 = 1 ;
if ( V_263 ) {
F_41 ( L_29 ) ;
return V_280 ;
} else
F_41 ( L_30 ) ;
} else
break;
default:
break;
}
V_3 += ( V_94 [ 1 ] + 2 ) ;
}
if ( V_263 && ! V_262 ) {
F_41 ( L_25 ) ;
return V_253 ;
} else if ( V_263 && V_262 ) {
F_41 ( L_29 ) ;
return V_280 ;
} else {
F_41 ( L_31 ) ;
return V_281 ;
}
}
void F_84 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_27 -> V_252 ) {
case V_271 :
V_27 -> V_282 = 1 ;
V_27 -> V_283 = 0 ;
break;
case V_253 :
V_27 -> V_282 = 0 ;
V_27 -> V_283 = 1 ;
F_85 ( V_22 , ( T_2 )
~ V_284 ) ;
break;
case V_276 :
F_85 ( V_22 , ( T_2 )
~ V_284 ) ;
break;
default:
V_27 -> V_282 = 0 ;
V_27 -> V_283 = 1 ;
break;
}
}
void F_86 ( struct V_21 * V_53 , T_3 V_285 )
{
struct V_23 * V_24 = & V_53 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_285 & V_286 ) {
if ( V_27 -> V_287 != V_288 ) {
V_27 -> V_287 = V_288 ;
F_87 ( V_53 , true ) ;
}
} else {
if ( V_27 -> V_287 != V_289 ) {
V_27 -> V_287 = V_289 ;
F_87 ( V_53 , false ) ;
}
}
if ( V_285 & V_290 ) {
V_27 -> V_123 = V_291 ;
} else {
if ( V_24 -> V_120 &
( V_9 | V_13 ) ) {
if ( V_285 & V_292 ) {
if ( V_27 -> V_123 != V_293 )
V_27 -> V_123 = V_293 ;
} else {
if ( V_27 -> V_123 != V_291 )
V_27 -> V_123 =
V_291 ;
}
} else if ( V_24 -> V_120 &
( V_8 | V_14 ) ) {
V_27 -> V_123 = V_293 ;
} else {
V_27 -> V_123 = V_291 ;
}
}
F_88 ( V_53 , V_27 -> V_123 ) ;
}
void F_89 ( struct V_21 * V_22 )
{
int V_2 , V_4 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_157 = & V_27 -> V_158 ;
unsigned char * V_1 = V_157 -> V_294 ;
V_2 = F_90 ( V_157 -> V_294 ) ;
if ( ( V_27 -> V_182 ) && ( V_27 -> V_170 ) )
V_27 -> V_30 = 1 ;
if ( V_24 -> V_29 > 14 ) {
if ( V_27 -> V_30 )
V_4 = V_14 ;
V_4 |= V_8 ;
} else {
if ( V_27 -> V_30 )
V_4 = V_13 ;
if ( F_2 ( V_1 , V_2 ) == true )
V_4 |= V_6 ;
else if ( F_1 ( V_1 , V_2 ) == true )
V_4 |= V_11 ;
else
V_4 |= V_9 ;
}
V_24 -> V_120 =
V_4 & V_22 -> V_119 . V_295 ;
F_91 ( V_22 , 0x08 , 0x08 , 0x0a , 0x0a ) ;
if ( V_24 -> V_120 & V_6 )
F_81 ( V_22 , V_32 ) ;
else
F_81 ( V_22 , V_36 ) ;
}
void F_92 ( struct V_21 * V_22 , T_2 V_92 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_24 -> V_120 & V_6 ) {
memcpy ( ( V_27 -> V_84 [ V_92 ] . V_294 ) ,
V_258 , 4 ) ;
} else {
memcpy ( V_27 -> V_84 [ V_92 ] . V_294 ,
V_260 , 3 ) ;
}
}
int F_93 ( struct V_21 * V_22 , T_1 * V_296 ,
T_4 V_297 , int V_298 )
{
int V_299 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
const T_1 * V_94 ;
V_94 = F_60 ( V_300 , V_296 , V_297 ) ;
if ( ! V_94 )
return V_100 ;
memcpy ( V_27 -> V_84 [ V_298 ] . V_294 , V_94 + 2 , V_94 [ 1 ] ) ;
V_299 = V_94 [ 1 ] ;
V_94 = F_60 ( V_301 , V_296 , V_297 ) ;
if ( V_94 )
memcpy ( V_27 -> V_84 [ V_298 ] . V_294 +
V_299 , V_94 + 2 , V_94 [ 1 ] ) ;
return V_208 ;
}
void F_94 ( struct V_21 * V_22 ,
T_1 * V_302 , T_1 * V_303 )
{
struct V_155 * V_156 ;
T_3 V_304 , V_305 , V_306 ;
struct V_307 * V_308 ;
struct V_159 * V_160 = & V_22 -> V_161 ;
struct V_309 * V_310 = (struct V_309 * ) V_302 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
V_156 = F_46 ( V_160 , V_303 ) ;
if ( V_156 ) {
V_305 = F_35 ( V_310 -> V_311 ) >> 4 ;
V_306 = F_35 ( V_310 -> V_312 ) ;
V_304 = ( V_306 >> 2 ) & 0x0f ;
V_308 = & V_156 -> V_313 [ V_304 ] ;
V_308 -> V_314 = 0xffff ;
V_308 -> V_315 = ( V_27 -> V_316 == true ) ?
true : false ;
}
}
