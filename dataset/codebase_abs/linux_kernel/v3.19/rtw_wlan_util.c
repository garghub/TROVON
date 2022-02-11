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
inline T_1 F_14 ( struct V_21 * V_58 )
{
return F_12 ( V_58 ) -> V_61 ;
}
inline void F_15 ( struct V_21 * V_58 , T_1 V_62 )
{
F_12 ( V_58 ) -> V_61 = V_62 ;
}
inline T_1 F_16 ( struct V_21 * V_58 )
{
return F_12 ( V_58 ) -> V_63 ;
}
inline void F_17 ( struct V_21 * V_58 , T_1 V_64 )
{
F_12 ( V_58 ) -> V_63 = V_64 ;
}
void F_18 ( struct V_21 * V_22 , unsigned char V_65 )
{
F_19 ( & F_12 ( V_22 ) -> V_66 ) ;
F_13 ( V_22 , V_65 ) ;
F_20 ( V_22 , V_65 ) ;
F_21 ( & F_12 ( V_22 ) -> V_66 ) ;
}
static void F_22 ( struct V_21 * V_22 , unsigned short V_67 ,
unsigned char V_68 )
{
F_19 ( & F_12 ( V_22 ) -> V_69 ) ;
F_15 ( V_22 , V_67 ) ;
F_17 ( V_22 , V_68 ) ;
F_23 ( V_22 , (enum V_70 ) V_67 ,
V_68 ) ;
F_21 ( & F_12 ( V_22 ) -> V_69 ) ;
}
void F_24 ( struct V_21 * V_22 , unsigned char V_65 ,
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
F_19 ( & F_12 ( V_22 ) -> V_66 ) ;
F_13 ( V_22 , V_65 ) ;
F_15 ( V_22 , V_67 ) ;
F_17 ( V_22 , V_68 ) ;
F_20 ( V_22 , V_71 ) ;
F_21 ( & F_12 ( V_22 ) -> V_66 ) ;
F_22 ( V_22 , V_67 , V_68 ) ;
}
inline T_1 * F_25 ( struct V_75 * V_76 )
{
return V_76 -> V_77 ;
}
bool F_26 ( struct V_21 * V_22 )
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
bool F_27 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_27 -> V_78 & V_79 &&
( V_27 -> V_78 & 0x03 ) == V_81 )
return true ;
else
return false ;
}
bool F_28 ( struct V_21 * V_22 )
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
unsigned int F_29 ( unsigned int V_86 )
{
if ( ( V_86 << 2 ) < V_87 )
return V_87 ;
else if ( ( V_86 << 2 ) > V_88 )
return V_88 ;
else
return V_86 << 2 ;
}
void F_30 ( struct V_21 * V_22 , T_1 V_89 )
{
unsigned char V_90 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_91 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
F_31 ( V_22 , V_89 , 0 , V_90 , V_91 ) ;
}
int F_32 ( struct V_21 * V_22 )
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
void F_33 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_34 ( V_22 ) ;
memset ( V_27 -> V_84 , 0 , sizeof( V_27 -> V_84 ) ) ;
}
int F_35 ( struct V_21 * V_22 , const T_1 * V_94 )
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
void F_36 ( struct V_21 * V_22 )
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
V_110 = F_37 ( V_27 -> V_101 . V_121 [ V_3 ] . V_125 ) ;
V_111 = V_105 | ( V_106 << 8 ) | ( V_107 << 12 ) | ( V_110 << 16 ) ;
switch ( V_103 ) {
case 0x0 :
F_38 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_39 ( 1 ) : 0 ) ;
V_112 [ V_126 ] = V_111 ;
break;
case 0x1 :
F_40 ( V_22 , V_111 ) ;
V_112 [ V_127 ] = V_111 ;
break;
case 0x2 :
F_41 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_39 ( 2 ) : 0 ) ;
V_112 [ V_128 ] = V_111 ;
break;
case 0x3 :
F_42 ( V_22 , V_111 ) ;
V_109 |= ( V_104 ? F_39 ( 3 ) : 0 ) ;
V_112 [ V_129 ] = V_111 ;
break;
}
F_43 ( L_1 , V_103 , V_104 , V_111 ) ;
}
if ( V_22 -> V_119 . V_130 == 1 )
F_44 ( V_22 , V_109 ) ;
else
V_22 -> V_97 . V_109 = V_109 ;
V_113 [ 0 ] = 0 ; V_113 [ 1 ] = 1 ; V_113 [ 2 ] = 2 ; V_113 [ 3 ] = 3 ;
if ( V_118 -> V_131 == 1 ) {
T_2 V_132 , V_133 , V_134 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_132 = V_3 + 1 ; V_132 < 4 ; V_132 ++ ) {
if ( ( V_112 [ V_132 ] & 0xFFFF ) < ( V_112 [ V_3 ] & 0xFFFF ) ) {
V_134 = true ;
} else if ( ( V_112 [ V_132 ] & 0xFFFF ) ==
( V_112 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_112 [ V_132 ] >> 16 ) > ( V_112 [ V_3 ] >> 16 ) )
V_134 = true ;
}
if ( V_134 ) {
V_133 = V_112 [ V_3 ] ;
V_112 [ V_3 ] = V_112 [ V_132 ] ;
V_112 [ V_132 ] = V_133 ;
V_133 = V_113 [ V_3 ] ;
V_113 [ V_3 ] = V_113 [ V_132 ] ;
V_113 [ V_132 ] = V_133 ;
V_134 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_115 -> V_135 [ V_3 ] = V_113 [ V_3 ] ;
F_43 ( L_2 , V_3 ,
V_115 -> V_135 [ V_3 ] ) ;
}
}
static void F_45 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_136 * V_137 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_117 * V_138 = & V_22 -> V_119 ;
struct V_139 * V_140 = & V_96 -> V_141 ;
unsigned char V_142 ;
unsigned char V_143 ;
if ( ! V_94 )
return;
if ( ! V_140 -> V_144 )
return;
if ( V_94 [ 1 ] != sizeof( struct V_136 ) )
return;
V_137 = (struct V_136 * ) ( V_94 + 2 ) ;
if ( ( V_137 -> V_145 & V_146 ) &&
V_138 -> V_147 ) {
V_142 = V_148 ;
switch ( V_137 -> V_145 & V_149 ) {
case V_150 :
V_143 = V_74 ;
break;
case V_151 :
V_143 = V_152 ;
break;
default:
V_143 = V_73 ;
break;
}
} else {
V_142 = V_72 ;
V_143 = V_73 ;
}
if ( V_142 != V_24 -> V_153 ||
V_143 != V_24 -> V_154 ) {
V_27 -> V_155 = true ;
V_24 -> V_153 = V_142 ;
V_24 -> V_154 = V_143 ;
F_46 ( V_22 , V_94 ) ;
} else
V_27 -> V_155 = false ;
if ( V_27 -> V_155 ) {
struct V_156 * V_157 ;
struct V_75 * V_158 = & V_27 -> V_159 ;
struct V_160 * V_161 = & V_22 -> V_162 ;
V_157 = F_47 ( V_161 , V_158 -> V_77 ) ;
if ( V_157 ) {
struct V_139 * V_163 = & V_157 -> V_141 ;
if ( V_163 -> V_144 ) {
V_163 -> V_67 = V_24 -> V_153 ;
V_163 -> V_164 =
V_24 -> V_154 ;
} else {
V_163 -> V_67 = V_72 ;
V_163 -> V_164 =
V_73 ;
}
}
}
}
void F_48 ( struct V_21 * V_22 , const T_1 * V_94 )
{
unsigned int V_3 ;
T_1 V_165 ;
T_1 V_166 , V_167 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_139 * V_140 = & V_96 -> V_141 ;
struct V_168 * V_169 ;
T_1 * V_170 ;
if ( ! V_94 )
return;
if ( ! V_140 -> V_144 )
return;
V_27 -> V_171 = 1 ;
V_169 = & V_27 -> V_172 ;
V_170 = ( T_1 * ) V_169 ;
for ( V_3 = 0 ; V_3 < V_94 [ 1 ] ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_170 [ V_3 ] &= V_94 [ V_3 + 2 ] ;
} else {
if ( ( V_169 -> V_173 &
V_174 ) >
( V_94 [ V_3 + 2 ] & V_174 ) )
V_166 = V_94 [ V_3 + 2 ] &
V_174 ;
else
V_166 = V_169 -> V_173 &
V_174 ;
if ( ( V_169 -> V_173 &
V_175 ) >
( V_94 [ V_3 + 2 ] & V_175 ) )
V_167 = V_169 -> V_173 &
V_175 ;
else
V_167 = V_94 [ V_3 + 2 ] &
V_175 ;
V_169 -> V_173 =
V_166 | V_167 ;
}
}
V_165 = F_49 ( V_22 ) ;
for ( V_3 = 0 ; V_3 < V_176 ; V_3 ++ ) {
if ( V_165 == V_177 || V_165 == V_178 )
V_169 -> V_179 . V_180 [ V_3 ] &= V_181 [ V_3 ] ;
else
V_169 -> V_179 . V_180 [ V_3 ] &= V_182 [ V_3 ] ;
}
}
void F_46 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_139 * V_140 = & V_96 -> V_141 ;
if ( ! V_94 )
return;
if ( ! V_140 -> V_144 )
return;
if ( V_94 [ 1 ] != sizeof( struct V_136 ) )
return;
V_27 -> V_183 = 1 ;
memcpy ( & V_27 -> V_184 , V_94 + 2 , V_94 [ 1 ] ) ;
}
void F_50 ( struct V_21 * V_22 )
{
unsigned char V_166 ;
unsigned char V_167 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_43 ( L_3 , V_185 ) ;
if ( V_27 -> V_183 && V_27 -> V_171 )
V_27 -> V_30 = 1 ;
else {
V_27 -> V_30 = 0 ;
return;
}
V_166 = V_27 -> V_172 . V_173 &
V_174 ;
V_167 =
( V_27 -> V_172 . V_173 &
V_175 ) >> 2 ;
F_51 ( V_22 , V_167 ) ;
F_52 ( V_22 , V_166 ) ;
}
void F_53 ( struct V_21 * V_22 , const T_1 * V_94 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_94 [ 1 ] > 1 )
return;
V_27 -> V_186 = 1 ;
memcpy ( & V_27 -> V_187 , V_94 + 2 , V_94 [ 1 ] ) ;
}
void F_54 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
struct V_117 * V_118 = & V_22 -> V_119 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_118 -> V_188 ) {
case 0 :
V_157 -> V_189 = 0 ;
V_157 -> V_190 = 0 ;
break;
case 1 :
if ( V_118 -> V_191 == V_192 ) {
V_157 -> V_189 = 1 ;
V_157 -> V_190 = 0 ;
} else {
V_157 -> V_189 = 0 ;
V_157 -> V_190 = 1 ;
}
break;
case 2 :
default:
if ( V_27 -> V_186 && V_27 -> V_187 & F_39 ( 1 ) ) {
if ( V_118 -> V_191 == V_192 ) {
V_157 -> V_189 = 1 ;
V_157 -> V_190 = 0 ;
} else {
V_157 -> V_189 = 0 ;
V_157 -> V_190 = 1 ;
}
} else {
V_157 -> V_189 = 0 ;
V_157 -> V_190 = 0 ;
}
break;
}
}
int F_55 ( struct V_21 * V_53 ,
struct V_193 * V_194 , T_2 V_195 )
{
struct V_196 * V_158 = & V_53 -> V_97 . V_158 ;
struct V_136 * V_197 ;
unsigned short V_198 ;
T_1 V_199 , V_200 ;
int V_201 = 0 , V_202 = 0 , V_203 = 0 , V_204 ;
int V_205 , V_206 , V_207 ;
const T_1 * V_94 , * V_208 ;
if ( ! F_26 ( V_53 ) )
return V_209 ;
if ( F_56 ( ! F_57 ( V_194 -> V_210 ) ) ) {
F_58 ( V_211 L_4 ,
V_185 ) ;
return V_100 ;
}
if ( ! F_59 ( V_158 -> V_159 . V_77 , V_194 -> V_212 ) ) {
F_43 ( L_5
MAC_FMT MAC_FMT L_6 , __func__, MAC_ARG(mgmt->bssid),
MAC_ARG(cur_network->network.MacAddress)) ;
return V_100 ;
}
V_205 = V_195 - F_60 ( struct V_193 , V_213 . V_214 . V_215 ) ;
V_94 = F_61 ( V_216 , V_194 -> V_213 . V_214 . V_215 ,
V_205 ) ;
if ( V_94 )
V_200 = V_94 [ 2 ] ;
else {
V_94 = F_61 ( V_217 ,
V_194 -> V_213 . V_214 . V_215 , V_205 ) ;
if ( V_94 && V_94 [ 1 ] > 0 ) {
V_197 = (struct V_136 * ) ( V_94 + 2 ) ;
V_200 = V_197 -> V_218 ;
} else {
F_43 ( L_7
L_8 , V_185 ) ;
V_200 = V_53 -> V_25 . V_29 ;
}
}
if ( V_200 != V_53 -> V_25 . V_29 ) {
F_43 ( L_9 ,
V_185 , V_200 ,
V_53 -> V_25 . V_29 ) ;
goto V_219;
}
V_94 = F_61 ( V_220 , V_194 -> V_213 . V_214 . V_215 , V_205 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_208 = V_94 + 2 ;
V_206 = V_94 [ 1 ] ;
} else {
F_43 ( L_10 ,
V_185 ) ;
V_208 = NULL ;
V_206 = 0 ;
}
F_62 ( V_221 , V_222 ,
( L_11
L_12 , V_185 ,
V_208 , V_206 , V_158 -> V_159 . V_223 . V_208 ,
V_158 -> V_159 . V_223 . V_206 ) ) ;
if ( V_206 != V_158 -> V_159 . V_223 . V_206 || V_206 > 32 ||
( V_206 &&
memcmp ( V_208 , V_158 -> V_159 . V_223 . V_208 , V_206 ) ) ) {
F_43 ( L_13 , V_185 ) ;
goto V_219;
}
V_198 = F_37 ( V_194 -> V_213 . V_214 . V_224 ) ;
if ( V_198 & V_225 )
V_207 = 1 ;
else
V_207 = 0 ;
F_62 ( V_221 , V_222 ,
( L_14
L_15 , V_185 , V_158 -> V_159 . V_226 , V_207 ) ) ;
if ( V_158 -> V_159 . V_226 != V_207 ) {
F_43 ( L_16 , V_185 ) ;
goto V_219;
}
V_94 = F_61 ( V_227 , V_194 -> V_213 . V_214 . V_215 , V_205 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_199 = V_228 ;
if ( V_94 && V_94 [ 1 ] ) {
V_204 = F_63 ( V_94 , V_94 [ 1 ] + 2 , & V_201 ,
& V_202 , & V_203 ) ;
if ( V_204 == V_209 )
F_62 ( V_221 , V_222 ,
( L_17
L_18
L_19 , V_185 , V_202 ,
V_201 , V_203 ) ) ;
}
} else {
V_94 = F_64 ( V_229 ,
V_230 ,
V_194 -> V_213 . V_214 . V_215 , V_205 ) ;
if ( V_94 && V_94 [ 1 ] ) {
V_199 = V_231 ;
V_204 = F_65 ( V_94 , V_94 [ 1 ] + 2 , & V_201 ,
& V_202 , & V_203 ) ;
if ( V_204 == V_209 )
F_62 ( V_221 , V_222 ,
( L_17
L_20
L_21 , V_185 , V_202 ,
V_201 , V_203 ) ) ;
} else {
if ( V_207 )
V_199 = V_232 ;
else
V_199 = V_233 ;
}
}
if ( V_158 -> V_234 . V_235 != V_199 ) {
F_43 ( L_22 , V_185 ) ;
goto V_219;
}
if ( V_199 == V_231 || V_199 == V_228 ) {
F_62 ( V_221 , V_236 ,
( L_23 , V_185 ,
V_158 -> V_234 . V_201 , V_201 ) ) ;
if ( V_202 != V_158 -> V_234 . V_202 ||
V_201 != V_158 -> V_234 . V_201 ) {
F_43 ( L_24
L_25 ,
V_185 , V_202 ,
V_158 -> V_234 . V_202 ,
V_201 ,
V_158 -> V_234 . V_201 ) ;
goto V_219;
}
if ( V_203 != V_158 -> V_234 . V_203 ) {
F_43 ( L_26
L_27 , V_185 ) ;
goto V_219;
}
}
return V_209 ;
V_219:
return V_100 ;
}
void F_66 ( struct V_21 * V_22 ,
struct V_193 * V_194 ,
T_4 V_195 , struct V_156 * V_157 )
{
unsigned int V_47 ;
const T_1 * V_94 ;
V_47 = V_195 - F_60 ( struct V_193 , V_213 . V_214 . V_215 ) ;
V_94 = F_61 ( V_217 , V_194 -> V_213 . V_214 . V_215 ,
V_47 ) ;
if ( V_94 )
F_45 ( V_22 , V_94 ) ;
V_94 = F_61 ( V_237 , V_194 -> V_213 . V_214 . V_215 , V_47 ) ;
if ( V_94 ) {
F_53 ( V_22 , V_94 ) ;
F_54 ( V_22 , V_157 ) ;
}
}
bool F_67 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_158 = & V_27 -> V_159 ;
const T_1 * V_94 ;
if ( V_158 -> V_238 & V_225 ) {
for ( V_3 = 0 ; V_3 < V_27 -> V_159 . V_239 ; ) {
V_94 = V_27 -> V_159 . V_240 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_241 :
if ( ! memcmp ( V_94 + 2 , V_242 , 4 ) &&
! memcmp ( V_94 + 2 + 12 , V_243 , 4 ) )
return true ;
break;
case V_227 :
if ( ! memcmp ( V_94 + 2 + 8 , V_244 , 4 ) )
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
bool F_68 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_95 * V_96 = & V_22 -> V_97 ;
struct V_75 * V_158 = & V_96 -> V_158 . V_159 ;
const T_1 * V_94 ;
if ( V_158 -> V_238 & V_225 ) {
for ( V_3 = 0 ; V_3 < V_158 -> V_239 ; ) {
V_94 = V_158 -> V_240 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_241 :
if ( ! memcmp ( V_94 + 2 , V_242 , 4 ) &&
( ! memcmp ( V_94 + 2 + 12 ,
V_245 , 4 ) ||
! memcmp ( V_94 + 2 + 16 ,
V_245 , 4 ) ) )
return false ;
break;
case V_227 :
if ( ! memcmp ( V_94 + 2 + 8 ,
V_246 , 4 ) ||
! memcmp ( V_94 + 2 + 12 ,
V_246 , 4 ) )
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
bool F_69 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_158 = & V_27 -> V_159 ;
const T_1 * V_94 ;
if ( V_158 -> V_238 & V_225 ) {
for ( V_3 = 0 ; V_3 < V_27 -> V_159 . V_239 ; ) {
V_94 = V_27 -> V_159 . V_240 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_241 :
if ( ! memcmp ( V_94 + 2 , V_242 , 4 ) )
return false ;
break;
case V_227 :
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
static int F_70 ( unsigned char V_1 )
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
unsigned int F_71 ( unsigned char * V_247 , unsigned int V_248 )
{
unsigned int V_3 , V_249 ;
unsigned int V_250 = 0 ;
V_249 = ( V_248 > V_44 ) ? V_44 : V_248 ;
for ( V_3 = 0 ; V_3 < V_249 ; V_3 ++ ) {
if ( ( * ( V_247 + V_3 ) ) & 0x80 )
V_250 |= 0x1 << F_70 ( * ( V_247 + V_3 ) ) ;
}
return V_250 ;
}
unsigned int F_72 ( unsigned char * V_247 , unsigned int V_248 )
{
unsigned int V_3 , V_249 ;
unsigned int V_250 = 0 ;
V_249 = ( V_248 > V_44 ) ? V_44 : V_248 ;
for ( V_3 = 0 ; V_3 < V_249 ; V_3 ++ )
V_250 |= 0x1 << F_70 ( * ( V_247 + V_3 ) ) ;
return V_250 ;
}
unsigned int F_73 ( struct V_168 * V_251 )
{
unsigned int V_250 = 0 ;
V_250 = V_251 -> V_179 . V_180 [ 0 ] << 12 |
V_251 -> V_179 . V_180 [ 1 ] << 20 ;
return V_250 ;
}
int F_74 ( struct V_21 * V_22 ,
struct V_168 * V_251 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
unsigned char V_252 ;
if ( ! V_27 -> V_30 )
return V_100 ;
if ( V_27 -> V_253 == V_254 )
return V_100 ;
V_252 = ( V_24 -> V_153 & V_148 ) ? 6 : 5 ;
if ( V_251 -> V_255 & F_75 ( 0x1 << V_252 ) )
return V_209 ;
else
return V_100 ;
}
unsigned char F_76 ( T_2 V_250 )
{
int V_3 ;
unsigned char V_256 = 0 ;
for ( V_3 = 27 ; V_3 >= 0 ; V_3 -- ) {
if ( V_250 & F_39 ( V_3 ) ) {
V_256 = V_3 ;
break;
}
}
return V_256 ;
}
void F_77 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
F_78 ( V_157 , 0 ) ;
}
static void F_79 ( struct V_21 * V_22 ,
struct V_156 * V_157 )
{
F_77 ( V_22 , V_157 ) ;
}
void F_80 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
F_79 ( V_22 , V_157 ) ;
}
void F_81 ( struct V_21 * V_22 , T_1 V_257 )
{
unsigned char V_258 [ V_55 ] ;
memset ( V_258 , 0 , V_55 ) ;
if ( V_257 == V_6 ) {
memcpy ( V_258 , V_259 , 4 ) ;
} else if ( V_257 & V_6 ) {
memcpy ( V_258 , V_260 , 7 ) ;
} else {
memcpy ( V_258 , V_261 , 3 ) ;
}
if ( V_257 & V_6 )
F_82 ( V_22 , V_32 ) ;
else
F_82 ( V_22 , V_36 ) ;
F_83 ( V_22 , V_258 ) ;
}
unsigned char F_84 ( T_1 * V_262 , T_4 V_47 )
{
int V_3 ;
T_1 V_263 ;
T_1 V_264 ;
const T_1 * V_94 ;
V_263 = 0 ;
V_264 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 ; ) {
V_94 = V_262 + V_3 ;
switch ( V_94 [ 0 ] ) {
case V_241 :
if ( ! memcmp ( V_94 + 2 , V_265 , 3 ) ||
! memcmp ( V_94 + 2 , V_266 , 3 ) ) {
F_43 ( L_28 ) ;
return V_267 ;
} else if ( ! memcmp ( V_94 + 2 , V_268 , 3 ) ||
! memcmp ( V_94 + 2 , V_269 , 3 ) ) {
F_43 ( L_29 ) ;
return V_270 ;
} else if ( ! memcmp ( V_94 + 2 , V_271 , 3 ) ) {
F_43 ( L_30 ) ;
return V_272 ;
} else if ( ! memcmp ( V_94 + 2 , V_273 , 3 ) ) {
if ( ! V_264 )
V_264 = 1 ;
else {
F_43 ( L_31 ) ;
return V_254 ;
}
} else if ( ! memcmp ( V_94 + 2 , V_274 , 3 ) ) {
F_43 ( L_32 ) ;
return V_275 ;
} else if ( ! memcmp ( V_94 + 2 , V_276 , 3 ) ) {
F_43 ( L_33 ) ;
return V_277 ;
} else if ( ! memcmp ( V_94 + 2 , V_278 , 3 ) ) {
F_43 ( L_34 ) ;
return V_279 ;
} else if ( ! memcmp ( V_94 + 2 , V_280 , 3 ) ) {
V_263 = 1 ;
if ( V_264 ) {
F_43 ( L_35 ) ;
return V_281 ;
} else
F_43 ( L_36 ) ;
} else
break;
default:
break;
}
V_3 += ( V_94 [ 1 ] + 2 ) ;
}
if ( V_264 && ! V_263 ) {
F_43 ( L_31 ) ;
return V_254 ;
} else if ( V_264 && V_263 ) {
F_43 ( L_35 ) ;
return V_281 ;
} else {
F_43 ( L_37 ) ;
return V_282 ;
}
}
void F_85 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_27 -> V_253 ) {
case V_272 :
V_27 -> V_283 = 1 ;
V_27 -> V_284 = 0 ;
break;
case V_254 :
V_27 -> V_283 = 0 ;
V_27 -> V_284 = 1 ;
F_86 ( V_22 , ( T_2 )
~ V_285 ) ;
break;
case V_277 :
F_86 ( V_22 , ( T_2 )
~ V_285 ) ;
break;
default:
V_27 -> V_283 = 0 ;
V_27 -> V_284 = 1 ;
break;
}
}
void F_87 ( struct V_21 * V_53 , T_3 V_286 )
{
struct V_23 * V_24 = & V_53 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_286 & V_287 ) {
if ( V_27 -> V_288 != V_289 ) {
V_27 -> V_288 = V_289 ;
F_88 ( V_53 , true ) ;
}
} else {
if ( V_27 -> V_288 != V_290 ) {
V_27 -> V_288 = V_290 ;
F_88 ( V_53 , false ) ;
}
}
if ( V_286 & V_291 ) {
V_27 -> V_123 = V_292 ;
} else {
if ( V_24 -> V_120 &
( V_9 | V_13 ) ) {
if ( V_286 & V_293 ) {
if ( V_27 -> V_123 != V_294 )
V_27 -> V_123 = V_294 ;
} else {
if ( V_27 -> V_123 != V_292 )
V_27 -> V_123 =
V_292 ;
}
} else if ( V_24 -> V_120 &
( V_8 | V_14 ) ) {
V_27 -> V_123 = V_294 ;
} else {
V_27 -> V_123 = V_292 ;
}
}
F_89 ( V_53 , V_27 -> V_123 ) ;
}
void F_90 ( struct V_21 * V_22 )
{
int V_2 , V_4 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_75 * V_158 = & V_27 -> V_159 ;
unsigned char * V_1 = V_158 -> V_295 ;
V_2 = F_91 ( V_158 -> V_295 ) ;
if ( ( V_27 -> V_183 ) && ( V_27 -> V_171 ) )
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
V_4 & V_22 -> V_119 . V_296 ;
F_92 ( V_22 , 0x08 , 0x08 , 0x0a , 0x0a ) ;
if ( V_24 -> V_120 & V_6 )
F_82 ( V_22 , V_32 ) ;
else
F_82 ( V_22 , V_36 ) ;
}
void F_93 ( struct V_21 * V_22 , T_2 V_92 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_24 -> V_120 & V_6 ) {
memcpy ( ( V_27 -> V_84 [ V_92 ] . V_295 ) ,
V_259 , 4 ) ;
} else {
memcpy ( V_27 -> V_84 [ V_92 ] . V_295 ,
V_261 , 3 ) ;
}
}
int F_94 ( struct V_21 * V_22 , T_1 * V_297 ,
T_4 V_298 , int V_299 )
{
int V_300 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
const T_1 * V_94 ;
V_94 = F_61 ( V_301 , V_297 , V_298 ) ;
if ( ! V_94 )
return V_100 ;
memcpy ( V_27 -> V_84 [ V_299 ] . V_295 , V_94 + 2 , V_94 [ 1 ] ) ;
V_300 = V_94 [ 1 ] ;
V_94 = F_61 ( V_302 , V_297 , V_298 ) ;
if ( V_94 )
memcpy ( V_27 -> V_84 [ V_299 ] . V_295 +
V_300 , V_94 + 2 , V_94 [ 1 ] ) ;
return V_209 ;
}
void F_95 ( struct V_21 * V_22 ,
T_1 * V_303 , T_1 * V_304 )
{
struct V_156 * V_157 ;
T_3 V_305 , V_306 , V_307 ;
struct V_308 * V_309 ;
struct V_160 * V_161 = & V_22 -> V_162 ;
struct V_310 * V_311 = (struct V_310 * ) V_303 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
V_157 = F_47 ( V_161 , V_304 ) ;
if ( V_157 ) {
V_306 = F_37 ( V_311 -> V_312 ) >> 4 ;
V_307 = F_37 ( V_311 -> V_313 ) ;
V_305 = ( V_307 >> 2 ) & 0x0f ;
V_309 = & V_157 -> V_314 [ V_305 ] ;
V_309 -> V_315 = 0xffff ;
V_309 -> V_316 = ( V_27 -> V_317 == true ) ?
true : false ;
}
}
