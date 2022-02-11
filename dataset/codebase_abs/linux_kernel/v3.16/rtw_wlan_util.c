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
void F_11 ( struct V_21 * V_22 , T_1 type )
{
F_12 ( V_22 , type ) ;
}
inline T_1 F_13 ( struct V_21 * V_58 )
{
return F_14 ( V_58 ) -> V_59 ;
}
inline void F_15 ( struct V_21 * V_58 , T_1 V_60 )
{
F_14 ( V_58 ) -> V_59 = V_60 ;
}
inline T_1 F_16 ( struct V_21 * V_58 )
{
return F_14 ( V_58 ) -> V_61 ;
}
inline void F_17 ( struct V_21 * V_58 , T_1 V_62 )
{
F_14 ( V_58 ) -> V_61 = V_62 ;
}
inline T_1 F_18 ( struct V_21 * V_58 )
{
return F_14 ( V_58 ) -> V_63 ;
}
inline void F_19 ( struct V_21 * V_58 , T_1 V_64 )
{
F_14 ( V_58 ) -> V_63 = V_64 ;
}
void F_20 ( struct V_21 * V_22 , unsigned char V_65 )
{
F_21 ( & F_14 ( V_22 ) -> V_66 ) ;
F_15 ( V_22 , V_65 ) ;
F_22 ( V_22 , V_65 ) ;
F_23 ( & F_14 ( V_22 ) -> V_66 ) ;
}
static void F_24 ( struct V_21 * V_22 , unsigned short V_67 ,
unsigned char V_68 )
{
F_21 ( & F_14 ( V_22 ) -> V_69 ) ;
F_17 ( V_22 , V_67 ) ;
F_19 ( V_22 , V_68 ) ;
F_25 ( V_22 , (enum V_70 ) V_67 ,
V_68 ) ;
F_23 ( & F_14 ( V_22 ) -> V_69 ) ;
}
void F_26 ( struct V_21 * V_22 , unsigned char V_65 ,
unsigned char V_68 , unsigned short V_67 )
{
T_1 V_71 ;
if ( V_22 -> V_72 )
F_27 ( L_1 ,
V_73 , V_65 , V_68 , V_67 ) ;
if ( V_67 == V_74 ||
V_68 == V_75 ) {
V_71 = V_65 ;
} else {
if ( V_68 == V_76 ) {
V_71 = V_65 + 2 ;
} else {
V_71 = V_65 - 2 ;
}
}
F_21 ( & F_14 ( V_22 ) -> V_66 ) ;
F_15 ( V_22 , V_65 ) ;
F_17 ( V_22 , V_67 ) ;
F_19 ( V_22 , V_68 ) ;
F_22 ( V_22 , V_71 ) ;
F_23 ( & F_14 ( V_22 ) -> V_66 ) ;
F_24 ( V_22 , V_67 , V_68 ) ;
}
inline T_1 * F_28 ( struct V_77 * V_78 )
{
return V_78 -> V_79 ;
}
T_3 F_29 ( struct V_77 * V_80 )
{
unsigned short V_31 ;
memcpy ( & V_31 , F_30 ( V_80 -> V_81 ) , 2 ) ;
return F_31 ( V_31 ) ;
}
bool F_32 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
if ( ! V_22 )
return false ;
V_24 = & V_22 -> V_25 ;
V_27 = & V_24 -> V_28 ;
if ( V_27 -> V_82 & V_83 &&
( V_27 -> V_82 & 0x03 ) == V_84 )
return true ;
else
return false ;
}
bool F_33 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_27 -> V_82 & V_83 &&
( V_27 -> V_82 & 0x03 ) == V_85 )
return true ;
else
return false ;
}
bool F_34 ( struct V_21 * V_22 )
{
unsigned int V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_3 = V_86 ; V_3 < V_87 ; V_3 ++ ) {
if ( V_27 -> V_88 [ V_3 ] . V_89 == 1 )
return false ;
}
return true ;
}
unsigned int F_35 ( unsigned int V_90 )
{
if ( ( V_90 << 2 ) < V_91 )
return V_91 ;
else if ( ( V_90 << 2 ) > V_92 )
return V_92 ;
else
return V_90 << 2 ;
}
void F_36 ( struct V_21 * V_22 )
{
F_37 ( V_22 ) ;
}
void F_38 ( struct V_21 * V_22 , T_1 V_93 )
{
unsigned char V_94 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_95 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
F_39 ( V_22 , V_93 , 0 , V_94 , V_95 ) ;
}
int F_40 ( struct V_21 * V_22 )
{
unsigned int V_96 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
for ( V_96 = V_86 ; V_96 < V_87 ; V_96 ++ ) {
if ( V_27 -> V_88 [ V_96 ] . V_89 == 0 ) {
V_27 -> V_88 [ V_96 ] . V_89 = 1 ;
V_27 -> V_88 [ V_96 ] . V_97 = 0 ;
break;
}
}
return V_96 ;
}
void F_41 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_37 ( V_22 ) ;
memset ( V_27 -> V_88 , 0 , sizeof( V_27 -> V_88 ) ) ;
}
int F_42 ( struct V_21 * V_22 , T_1 * V_98 )
{
struct V_99 * V_100 = & V_22 -> V_101 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_100 -> V_102 == 0 ) {
V_27 -> V_103 = 0 ;
return V_104 ;
}
V_27 -> V_103 = 1 ;
memcpy ( & V_27 -> V_105 , V_98 + 2 + 6 ,
sizeof( struct V_106 ) ) ;
return true ;
}
void F_43 ( struct V_21 * V_22 )
{
T_1 V_107 , V_108 , V_109 , V_110 , V_111 , V_112 ;
T_1 V_113 ;
T_3 V_114 ;
T_2 V_115 , V_3 ;
T_2 V_116 [ 4 ] , V_117 [ 4 ] ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_118 * V_119 = & V_22 -> V_120 ;
struct V_121 * V_122 = & V_22 -> V_123 ;
if ( V_27 -> V_103 == 0 ) {
V_22 -> V_101 . V_113 = 0 ;
return;
}
V_113 = 0 ;
if ( V_24 -> V_124 == V_6 )
V_112 = 10 ;
else
V_112 = 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_107 = ( V_27 -> V_105 . V_125 [ V_3 ] . V_126 >> 5 ) & 0x03 ;
V_108 = ( V_27 -> V_105 . V_125 [ V_3 ] . V_126 >> 4 ) & 0x01 ;
V_109 = ( V_27 -> V_105 . V_125 [ V_3 ] . V_126 & 0x0f ) *
V_27 -> V_127 + V_112 ;
V_110 = V_27 -> V_105 . V_125 [ V_3 ] . V_128 & 0x0f ;
V_111 = ( V_27 -> V_105 . V_125 [ V_3 ] . V_128 & 0xf0 ) >> 4 ;
V_114 = F_31 ( V_27 -> V_105 . V_125 [ V_3 ] . V_129 ) ;
V_115 = V_109 | ( V_110 << 8 ) | ( V_111 << 12 ) | ( V_114 << 16 ) ;
switch ( V_107 ) {
case 0x0 :
F_44 ( V_22 , V_115 ) ;
V_113 |= ( V_108 ? F_45 ( 1 ) : 0 ) ;
V_116 [ V_130 ] = V_115 ;
break;
case 0x1 :
F_46 ( V_22 , V_115 ) ;
V_116 [ V_131 ] = V_115 ;
break;
case 0x2 :
F_47 ( V_22 , V_115 ) ;
V_113 |= ( V_108 ? F_45 ( 2 ) : 0 ) ;
V_116 [ V_132 ] = V_115 ;
break;
case 0x3 :
F_48 ( V_22 , V_115 ) ;
V_113 |= ( V_108 ? F_45 ( 3 ) : 0 ) ;
V_116 [ V_133 ] = V_115 ;
break;
}
F_27 ( L_2 , V_107 , V_108 , V_115 ) ;
}
if ( V_22 -> V_123 . V_134 == 1 )
F_49 ( V_22 , V_113 ) ;
else
V_22 -> V_101 . V_113 = V_113 ;
V_117 [ 0 ] = 0 ; V_117 [ 1 ] = 1 ; V_117 [ 2 ] = 2 ; V_117 [ 3 ] = 3 ;
if ( V_122 -> V_135 == 1 ) {
T_2 V_136 , V_137 , V_138 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_136 = V_3 + 1 ; V_136 < 4 ; V_136 ++ ) {
if ( ( V_116 [ V_136 ] & 0xFFFF ) < ( V_116 [ V_3 ] & 0xFFFF ) ) {
V_138 = true ;
} else if ( ( V_116 [ V_136 ] & 0xFFFF ) ==
( V_116 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_116 [ V_136 ] >> 16 ) > ( V_116 [ V_3 ] >> 16 ) )
V_138 = true ;
}
if ( V_138 ) {
V_137 = V_116 [ V_3 ] ;
V_116 [ V_3 ] = V_116 [ V_136 ] ;
V_116 [ V_136 ] = V_137 ;
V_137 = V_117 [ V_3 ] ;
V_117 [ V_3 ] = V_117 [ V_136 ] ;
V_117 [ V_136 ] = V_137 ;
V_138 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_119 -> V_139 [ V_3 ] = V_117 [ V_3 ] ;
F_27 ( L_3 , V_3 ,
V_119 -> V_139 [ V_3 ] ) ;
}
return;
}
static void F_50 ( struct V_21 * V_22 , T_1 * V_98 )
{
struct V_140 * V_141 ;
struct V_99 * V_100 = & V_22 -> V_101 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_121 * V_142 = & V_22 -> V_123 ;
struct V_143 * V_144 = & V_100 -> V_145 ;
unsigned char V_146 ;
unsigned char V_147 ;
if ( ! V_98 )
return;
if ( ! V_144 -> V_148 )
return;
if ( V_98 [ 1 ] > sizeof( struct V_140 ) )
return;
V_141 = (struct V_140 * ) ( V_98 + 2 ) ;
if ( ( V_141 -> V_149 [ 0 ] & F_45 ( 2 ) ) && V_142 -> V_150 ) {
V_146 = V_151 ;
switch ( V_141 -> V_149 [ 0 ] & 0x3 ) {
case 1 :
V_147 = V_76 ;
break;
case 3 :
V_147 = V_152 ;
break;
default:
V_147 = V_75 ;
break;
}
} else {
V_146 = V_74 ;
V_147 = V_75 ;
}
if ( V_146 != V_24 -> V_153 ||
V_147 != V_24 -> V_154 ) {
V_27 -> V_155 = true ;
V_24 -> V_153 = V_146 ;
V_24 -> V_154 = V_147 ;
F_51 ( V_22 , V_98 ) ;
} else
V_27 -> V_155 = false ;
if ( V_27 -> V_155 ) {
struct V_156 * V_157 ;
struct V_77 * V_158 = & V_27 -> V_159 ;
struct V_160 * V_161 = & V_22 -> V_162 ;
V_157 = F_52 ( V_161 , V_158 -> V_79 ) ;
if ( V_157 ) {
struct V_143 * V_163 = & V_157 -> V_145 ;
if ( V_163 -> V_148 ) {
V_163 -> V_67 = V_24 -> V_153 ;
V_163 -> V_164 =
V_24 -> V_154 ;
} else {
V_163 -> V_67 = V_74 ;
V_163 -> V_164 =
V_75 ;
}
}
}
}
void F_53 ( struct V_21 * V_22 , T_1 * V_98 )
{
unsigned int V_3 ;
T_1 V_165 ;
T_1 V_166 , V_167 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_99 * V_100 = & V_22 -> V_101 ;
struct V_143 * V_144 = & V_100 -> V_145 ;
if ( ! V_98 )
return;
if ( V_144 -> V_148 == false )
return;
V_27 -> V_168 = 1 ;
for ( V_3 = 0 ; V_3 < V_98 [ 1 ] ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_27 -> V_169 . V_170 . V_171 [ V_3 ] &= V_98 [ V_3 + 2 ] ;
} else {
if ( ( V_27 -> V_169 . V_170 . V_172 . V_173 & 0x3 ) > ( V_98 [ V_3 + 2 ] & 0x3 ) )
V_166 = V_98 [ V_3 + 2 ] & 0x3 ;
else
V_166 = V_27 -> V_169 . V_170 . V_172 . V_173 & 0x3 ;
if ( ( V_27 -> V_169 . V_170 . V_172 . V_173 & 0x1c ) > ( V_98 [ V_3 + 2 ] & 0x1c ) )
V_167 = V_27 -> V_169 . V_170 . V_172 . V_173 & 0x1c ;
else
V_167 = V_98 [ V_3 + 2 ] & 0x1c ;
V_27 -> V_169 . V_170 . V_172 . V_173 =
V_166 | V_167 ;
}
}
V_27 -> V_169 . V_170 . V_172 . V_174 =
F_31 ( V_27 -> V_169 . V_170 . V_172 . V_174 ) ;
V_27 -> V_169 . V_170 . V_172 . V_175 =
F_31 ( V_27 -> V_169 . V_170 . V_172 . V_175 ) ;
V_165 = F_54 ( V_22 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_165 == V_176 || V_165 == V_177 )
V_27 -> V_169 . V_170 . V_172 . V_178 [ V_3 ] &=
V_179 [ V_3 ] ;
else
V_27 -> V_169 . V_170 . V_172 . V_178 [ V_3 ] &=
V_180 [ V_3 ] ;
}
return;
}
void F_51 ( struct V_21 * V_22 , T_1 * V_98 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_99 * V_100 = & V_22 -> V_101 ;
struct V_143 * V_144 = & V_100 -> V_145 ;
if ( ! V_98 )
return;
if ( V_144 -> V_148 == false )
return;
if ( V_98 [ 1 ] > sizeof( struct V_140 ) )
return;
V_27 -> V_181 = 1 ;
memcpy ( & V_27 -> V_182 , V_98 + 2 , V_98 [ 1 ] ) ;
return;
}
void F_55 ( struct V_21 * V_22 )
{
unsigned char V_166 ;
unsigned char V_167 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
F_27 ( L_4 , V_73 ) ;
if ( V_27 -> V_181 && V_27 -> V_168 )
V_27 -> V_30 = 1 ;
else {
V_27 -> V_30 = 0 ;
return;
}
V_166 = V_27 -> V_169 . V_170 . V_172 . V_173 & 0x03 ;
V_167 =
( V_27 -> V_169 . V_170 . V_172 . V_173 & 0x1c ) >> 2 ;
F_56 ( V_22 , V_167 ) ;
F_57 ( V_22 , V_166 ) ;
}
void F_58 ( struct V_21 * V_22 , T_1 * V_98 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_98 [ 1 ] > 1 )
return;
V_27 -> V_183 = 1 ;
memcpy ( & V_27 -> V_184 , V_98 + 2 , V_98 [ 1 ] ) ;
}
void F_59 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
struct V_121 * V_122 = & V_22 -> V_123 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_122 -> V_185 ) {
case 0 :
V_157 -> V_186 = 0 ;
V_157 -> V_187 = 0 ;
break;
case 1 :
if ( V_122 -> V_188 == 1 ) {
V_157 -> V_186 = 1 ;
V_157 -> V_187 = 0 ;
} else {
V_157 -> V_186 = 0 ;
V_157 -> V_187 = 1 ;
}
break;
case 2 :
default:
if ( V_27 -> V_183 && V_27 -> V_184 & F_45 ( 1 ) ) {
if ( V_122 -> V_188 == 1 ) {
V_157 -> V_186 = 1 ;
V_157 -> V_187 = 0 ;
} else {
V_157 -> V_186 = 0 ;
V_157 -> V_187 = 1 ;
}
} else {
V_157 -> V_186 = 0 ;
V_157 -> V_187 = 0 ;
}
break;
}
}
int F_60 ( struct V_21 * V_53 ,
struct V_189 * V_190 , T_2 V_191 )
{
struct V_192 * V_158 = & V_53 -> V_101 . V_158 ;
struct V_140 * V_193 ;
struct V_194 * V_195 ;
struct V_77 * V_196 ;
unsigned short V_197 ;
T_3 V_198 = 0 , V_199 = 0 ;
T_1 V_200 ;
int V_201 = 0 , V_202 = 0 , V_203 = 0 , V_204 ;
T_2 V_205 ;
unsigned short V_206 ;
unsigned char V_207 ;
int V_47 , V_208 , V_209 ;
const T_1 * V_98 ;
T_1 * V_210 ;
if ( F_32 ( V_53 ) == false )
return true ;
if ( F_61 ( ! F_62 ( V_190 -> V_211 ) ) ) {
F_63 ( V_212 L_5 ,
V_73 ) ;
return false ;
}
V_47 = V_191 - sizeof( struct V_213 ) ;
if ( V_47 > V_214 ) {
F_27 ( L_6 , V_73 ) ;
return V_104 ;
}
if ( memcmp ( V_158 -> V_159 . V_79 , V_190 -> V_196 , 6 ) ) {
F_27 ( L_7
L_8 MAC_FMT MAC_FMT,
MAC_ARG(mgmt->bssid),
MAC_ARG(cur_network->network.MacAddress)) ;
return true ;
}
V_196 = F_64 ( sizeof( struct V_77 ) , V_215 ) ;
if ( ! V_196 )
return V_104 ;
V_196 -> V_216 = 1 ;
V_196 -> V_217 = F_65 ( struct V_77 , V_81 ) + V_47 ;
V_196 -> V_218 = V_47 ;
memcpy ( V_196 -> V_81 , & V_190 -> V_170 , V_47 ) ;
V_209 = F_65 ( struct V_189 , V_170 . V_219 . V_220 ) -
F_65 ( struct V_189 , V_170 ) ;
V_210 = V_196 -> V_81 + V_209 ;
V_208 = V_191 - V_209 ;
V_98 = F_66 ( V_221 , V_210 , V_208 ) ;
if ( V_98 && V_98 [ 1 ] > 0 ) {
V_195 = (struct V_194 * ) ( V_98 + 2 ) ;
V_206 = V_195 -> V_222 ;
} else {
V_195 = NULL ;
V_206 = 0 ;
}
V_98 = F_66 ( V_223 , V_210 , V_208 ) ;
if ( V_98 && V_98 [ 1 ] > 0 ) {
V_193 = (struct V_140 * ) ( V_98 + 2 ) ;
V_207 = V_193 -> V_149 [ 0 ] ;
} else {
V_193 = NULL ;
V_207 = 0 ;
}
if ( V_206 != V_158 -> V_224 . V_206 ||
( ( V_207 & 0x03 ) !=
( V_158 -> V_224 . V_207 & 0x03 ) ) ) {
F_27 ( L_9 ,
V_73 , V_206 , V_207 ) ;
F_27 ( L_10 ,
V_73 , V_158 -> V_224 . V_206 ,
V_158 -> V_224 . V_207 ) ;
F_27 ( L_11 , V_73 ) ;
V_158 -> V_224 . V_206 = V_206 ;
V_158 -> V_224 . V_207 = V_207 ;
}
V_98 = F_66 ( V_225 , V_210 , V_208 ) ;
if ( V_98 )
V_205 = V_98 [ 2 ] ;
else {
V_98 = F_66 ( V_223 , V_210 , V_208 ) ;
if ( V_193 )
V_205 = V_193 -> V_226 ;
else {
F_27 ( L_12
L_13 , V_73 ) ;
V_205 = V_53 -> V_25 . V_29 ;
}
}
if ( V_205 != V_53 -> V_25 . V_29 ) {
F_27 ( L_14 ,
V_73 , V_205 ,
V_53 -> V_25 . V_29 ) ;
goto V_227;
}
V_98 = F_66 ( V_228 , V_210 , V_208 ) ;
if ( V_98 && V_98 [ 1 ] ) {
memcpy ( V_196 -> V_229 . V_230 , V_98 + 2 , V_98 [ 1 ] ) ;
V_196 -> V_229 . V_231 = V_98 [ 1 ] ;
} else {
F_27 ( L_15 ,
V_73 ) ;
V_196 -> V_229 . V_231 = 0 ;
V_196 -> V_229 . V_230 [ 0 ] = '\0' ;
}
F_67 ( V_232 , V_233 ,
( L_16
L_17 , V_73 ,
V_196 -> V_229 . V_230 , V_196 -> V_229 . V_231 ,
V_158 -> V_159 . V_229 . V_230 ,
V_158 -> V_159 . V_229 . V_231 ) ) ;
if ( memcmp ( V_196 -> V_229 . V_230 , V_158 -> V_159 . V_229 . V_230 , 32 ) ||
V_196 -> V_229 . V_231 != V_158 -> V_159 . V_229 . V_231 ) {
if ( V_196 -> V_229 . V_230 [ 0 ] != '\0' &&
V_196 -> V_229 . V_231 != 0 ) {
F_27 ( L_18 ,
V_73 ) ;
goto V_227;
}
}
V_197 = F_68 ( V_196 ) ;
if ( V_197 & F_45 ( 4 ) )
V_196 -> V_234 = 1 ;
else
V_196 -> V_234 = 0 ;
F_67 ( V_232 , V_233 ,
( L_19
L_20 , V_73 , V_158 -> V_159 . V_234 ,
V_196 -> V_234 ) ) ;
if ( V_158 -> V_159 . V_234 != V_196 -> V_234 ) {
F_27 ( L_21 , V_73 ) ;
goto V_227;
}
F_69 ( V_196 -> V_81 , V_196 -> V_218 , NULL , & V_199 , NULL ,
& V_198 ) ;
if ( V_199 > 0 )
V_200 = V_235 ;
else if ( V_198 > 0 )
V_200 = V_236 ;
else {
if ( V_196 -> V_234 )
V_200 = V_237 ;
else
V_200 = V_238 ;
}
if ( V_158 -> V_224 . V_200 != V_200 ) {
F_27 ( L_22 , V_73 ) ;
goto V_227;
}
if ( V_200 == V_236 ||
V_200 == V_235 ) {
V_98 = F_70 ( V_239 ,
V_240 ,
V_210 , V_208 ) ;
if ( V_98 && V_98 [ 1 ] > 0 ) {
V_204 = F_71 ( V_98 , V_98 [ 1 ] + 2 , & V_201 ,
& V_202 , & V_203 ) ;
if ( V_204 == V_241 )
F_67 ( V_232 , V_233 ,
( L_23
L_24
L_25 , V_73 , V_202 ,
V_201 , V_203 ) ) ;
} else {
V_98 = F_66 ( V_242 , V_210 , V_208 ) ;
if ( V_98 && V_98 [ 1 ] > 0 ) {
V_204 = F_72 ( V_98 , V_98 [ 1 ] + 2 ,
& V_201 ,
& V_202 ,
& V_203 ) ;
if ( V_204 == V_241 )
F_67 ( V_232 ,
V_233 ,
( L_26
L_27
L_28 ,
V_73 , V_202 ,
V_201 , V_203 ) ) ;
}
}
F_67 ( V_232 , V_243 ,
( L_29 , V_73 ,
V_158 -> V_224 . V_201 , V_201 ) ) ;
if ( V_202 != V_158 -> V_224 . V_202 ||
V_201 != V_158 -> V_224 . V_201 ) {
F_27 ( L_30
L_31 ,
V_73 , V_202 ,
V_158 -> V_224 . V_202 ,
V_201 ,
V_158 -> V_224 . V_201 ) ;
goto V_227;
}
if ( V_203 != V_158 -> V_224 . V_203 ) {
F_27 ( L_32
L_33 , V_73 ) ;
goto V_227;
}
}
F_73 ( V_196 ) ;
return V_241 ;
V_227:
F_73 ( V_196 ) ;
return V_104 ;
}
void F_74 ( struct V_21 * V_22 , T_1 * V_244 ,
T_4 V_191 , struct V_156 * V_157 )
{
unsigned int V_3 ;
unsigned int V_47 ;
T_1 * V_98 ;
V_47 = V_191 -
( V_245 + sizeof( struct V_213 ) ) ;
for ( V_3 = 0 ; V_3 < V_47 ; ) {
V_98 = ( T_1 * ) ( V_244 + ( V_245 + sizeof( struct V_213 ) ) + V_3 ) ;
switch ( V_98 [ 0 ] ) {
case V_223 :
F_50 ( V_22 , V_98 ) ;
break;
case V_246 :
F_58 ( V_22 , V_98 ) ;
F_59 ( V_22 , V_157 ) ;
break;
default:
break;
}
V_3 += ( V_98 [ 1 ] + 2 ) ;
}
}
bool F_75 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_77 * V_158 = & V_27 -> V_159 ;
const T_1 * V_98 ;
int V_247 ;
V_247 = F_65 ( struct V_189 , V_170 . V_219 . V_220 ) -
F_65 ( struct V_189 , V_170 . V_219 ) ;
if ( F_68 ( V_158 ) & V_248 ) {
for ( V_3 = V_247 ; V_3 < V_27 -> V_159 . V_218 ; ) {
V_98 = V_27 -> V_159 . V_81 + V_3 ;
switch ( V_98 [ 0 ] ) {
case V_249 :
if ( ! memcmp ( V_98 + 2 , V_250 , 4 ) &&
! memcmp ( V_98 + 2 + 12 , V_251 , 4 ) )
return true ;
break;
case V_242 :
if ( ! memcmp ( V_98 + 2 + 8 , V_252 , 4 ) )
return true ;
break;
default:
break;
}
V_3 += ( V_98 [ 1 ] + 2 ) ;
}
return false ;
} else
return false ;
}
bool F_76 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_99 * V_100 = & V_22 -> V_101 ;
struct V_77 * V_158 = & V_100 -> V_158 . V_159 ;
const T_1 * V_98 ;
int V_247 ;
V_247 = F_65 ( struct V_189 , V_170 . V_219 . V_220 ) -
F_65 ( struct V_189 , V_170 . V_219 ) ;
if ( F_68 ( V_158 ) & V_248 ) {
for ( V_3 = V_247 ; V_3 < V_158 -> V_218 ; ) {
V_98 = V_158 -> V_81 + V_3 ;
switch ( V_98 [ 0 ] ) {
case V_249 :
if ( ! memcmp ( V_98 + 2 , V_250 , 4 ) &&
( ! memcmp ( V_98 + 2 + 12 ,
V_253 , 4 ) ||
! memcmp ( V_98 + 2 + 16 ,
V_253 , 4 ) ) )
return false ;
break;
case V_242 :
if ( ! memcmp ( V_98 + 2 + 8 ,
V_254 , 4 ) ||
! memcmp ( V_98 + 2 + 12 ,
V_254 , 4 ) )
return false ;
default:
break;
}
V_3 += ( V_98 [ 1 ] + 2 ) ;
}
return true ;
} else {
return false ;
}
}
bool F_77 ( struct V_21 * V_22 )
{
T_2 V_3 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_77 * V_158 = & V_27 -> V_159 ;
const T_1 * V_98 ;
int V_247 ;
V_247 = F_65 ( struct V_189 , V_170 . V_219 . V_220 ) -
F_65 ( struct V_189 , V_170 . V_219 ) ;
if ( F_68 ( V_158 ) & V_248 ) {
for ( V_3 = V_247 ; V_3 < V_27 -> V_159 . V_218 ; ) {
V_98 = V_27 -> V_159 . V_81 + V_3 ;
switch ( V_98 [ 0 ] ) {
case V_249 :
if ( ! memcmp ( V_98 + 2 , V_250 , 4 ) )
return false ;
break;
case V_242 :
return false ;
default:
break;
}
V_3 += ( V_98 [ 1 ] + 2 ) ;
}
return true ;
} else
return false ;
}
static int F_78 ( unsigned char V_1 )
{
int V_117 = 0 ;
V_1 = V_1 & 0x7f ;
switch ( V_1 ) {
case 54 * 2 :
V_117 = 11 ;
break;
case 48 * 2 :
V_117 = 10 ;
break;
case 36 * 2 :
V_117 = 9 ;
break;
case 24 * 2 :
V_117 = 8 ;
break;
case 18 * 2 :
V_117 = 7 ;
break;
case 12 * 2 :
V_117 = 6 ;
break;
case 9 * 2 :
V_117 = 5 ;
break;
case 6 * 2 :
V_117 = 4 ;
break;
case 11 * 2 :
V_117 = 3 ;
break;
case 11 :
V_117 = 2 ;
break;
case 2 * 2 :
V_117 = 1 ;
break;
case 1 * 2 :
V_117 = 0 ;
break;
}
return V_117 ;
}
unsigned int F_79 ( unsigned char * V_255 , unsigned int V_256 )
{
unsigned int V_3 , V_257 ;
unsigned int V_258 = 0 ;
V_257 = ( V_256 > V_44 ) ? V_44 : V_256 ;
for ( V_3 = 0 ; V_3 < V_257 ; V_3 ++ ) {
if ( ( * ( V_255 + V_3 ) ) & 0x80 )
V_258 |= 0x1 << F_78 ( * ( V_255 + V_3 ) ) ;
}
return V_258 ;
}
unsigned int F_80 ( unsigned char * V_255 , unsigned int V_256 )
{
unsigned int V_3 , V_257 ;
unsigned int V_258 = 0 ;
V_257 = ( V_256 > V_44 ) ? V_44 : V_256 ;
for ( V_3 = 0 ; V_3 < V_257 ; V_3 ++ )
V_258 |= 0x1 << F_78 ( * ( V_255 + V_3 ) ) ;
return V_258 ;
}
unsigned int F_81 ( struct V_259 * V_260 )
{
unsigned int V_258 = 0 ;
V_258 = V_260 -> V_170 . V_172 . V_178 [ 0 ] << 12 |
V_260 -> V_170 . V_172 . V_178 [ 1 ] << 20 ;
return V_258 ;
}
int F_82 ( struct V_21 * V_22 ,
struct V_259 * V_260 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
unsigned char V_261 ;
if ( ! V_27 -> V_30 )
return V_104 ;
if ( V_27 -> V_262 == V_263 )
return V_104 ;
V_261 = ( V_24 -> V_153 & V_151 ) ? 6 : 5 ;
if ( V_260 -> V_170 . V_172 . V_174 & ( 0x1 << V_261 ) )
return V_241 ;
else
return V_104 ;
}
unsigned char F_83 ( T_2 V_258 )
{
int V_3 ;
unsigned char V_264 = 0 ;
for ( V_3 = 27 ; V_3 >= 0 ; V_3 -- ) {
if ( V_258 & F_45 ( V_3 ) ) {
V_264 = V_3 ;
break;
}
}
return V_264 ;
}
void F_84 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
F_85 ( V_157 , 0 ) ;
}
static void F_86 ( struct V_21 * V_22 ,
struct V_156 * V_157 )
{
F_84 ( V_22 , V_157 ) ;
}
void F_87 ( struct V_21 * V_22 , struct V_156 * V_157 )
{
F_86 ( V_22 , V_157 ) ;
}
void F_88 ( struct V_21 * V_22 , T_1 V_265 )
{
unsigned char V_266 [ V_55 ] ;
memset ( V_266 , 0 , V_55 ) ;
if ( V_265 == V_6 ) {
memcpy ( V_266 , V_267 , 4 ) ;
} else if ( V_265 & V_6 ) {
memcpy ( V_266 , V_268 , 7 ) ;
} else {
memcpy ( V_266 , V_269 , 3 ) ;
}
if ( V_265 & V_6 )
F_89 ( V_22 , V_32 ) ;
else
F_89 ( V_22 , V_36 ) ;
F_90 ( V_22 , V_266 ) ;
}
unsigned char F_91 ( T_1 * V_244 , T_4 V_47 )
{
int V_3 , V_247 ;
T_1 V_270 ;
T_1 V_271 ;
const T_1 * V_98 ;
V_270 = 0 ;
V_271 = 0 ;
V_247 = F_65 ( struct V_189 , V_170 . V_219 . V_220 ) -
F_65 ( struct V_189 , V_170 . V_219 ) ;
for ( V_3 = V_247 ; V_3 < V_47 ; ) {
V_98 = V_244 + V_3 ;
switch ( V_98 [ 0 ] ) {
case V_249 :
if ( ! memcmp ( V_98 + 2 , V_272 , 3 ) ||
! memcmp ( V_98 + 2 , V_273 , 3 ) ) {
F_27 ( L_34 ) ;
return V_274 ;
} else if ( ! memcmp ( V_98 + 2 , V_275 , 3 ) ||
! memcmp ( V_98 + 2 , V_276 , 3 ) ||
! memcmp ( V_98 + 2 , V_276 , 3 ) ) {
F_27 ( L_35 ) ;
return V_277 ;
} else if ( ! memcmp ( V_98 + 2 , V_278 , 3 ) ) {
F_27 ( L_36 ) ;
return V_279 ;
} else if ( ! memcmp ( V_98 + 2 , V_280 , 3 ) ) {
if ( ! V_271 )
V_271 = 1 ;
else {
F_27 ( L_37 ) ;
return V_263 ;
}
} else if ( ! memcmp ( V_98 + 2 , V_281 , 3 ) ) {
F_27 ( L_38 ) ;
return V_282 ;
} else if ( ! memcmp ( V_98 + 2 , V_283 , 3 ) ) {
F_27 ( L_39 ) ;
return V_284 ;
} else if ( ! memcmp ( V_98 + 2 , V_285 , 3 ) ) {
F_27 ( L_40 ) ;
return V_286 ;
} else if ( ! memcmp ( V_98 + 2 , V_287 , 3 ) ) {
V_270 = 1 ;
if ( V_271 ) {
F_27 ( L_41 ) ;
return V_288 ;
} else
F_27 ( L_42 ) ;
} else
break;
default:
break;
}
V_3 += ( V_98 [ 1 ] + 2 ) ;
}
if ( V_271 && ! V_270 ) {
F_27 ( L_37 ) ;
return V_263 ;
} else if ( V_271 && V_270 ) {
F_27 ( L_41 ) ;
return V_288 ;
} else {
F_27 ( L_43 ) ;
return V_289 ;
}
}
void F_92 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
switch ( V_27 -> V_262 ) {
case V_279 :
V_27 -> V_290 = 1 ;
V_27 -> V_291 = 0 ;
break;
case V_263 :
V_27 -> V_290 = 0 ;
V_27 -> V_291 = 1 ;
F_93 ( V_22 , ( T_2 )
~ V_292 ) ;
break;
case V_284 :
F_93 ( V_22 , ( T_2 )
~ V_292 ) ;
break;
default:
V_27 -> V_290 = 0 ;
V_27 -> V_291 = 1 ;
break;
}
}
void F_94 ( struct V_21 * V_53 , T_3 V_293 )
{
struct V_23 * V_24 = & V_53 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_293 & V_294 ) {
if ( V_27 -> V_295 != V_296 ) {
V_27 -> V_295 = V_296 ;
F_95 ( V_53 , true ) ;
}
} else {
if ( V_27 -> V_295 != V_297 ) {
V_27 -> V_295 = V_297 ;
F_95 ( V_53 , false ) ;
}
}
if ( V_293 & V_298 ) {
V_27 -> V_127 = V_299 ;
} else {
if ( V_24 -> V_124 &
( V_9 | V_13 ) ) {
if ( V_293 & V_300 ) {
if ( V_27 -> V_127 != V_301 )
V_27 -> V_127 = V_301 ;
} else {
if ( V_27 -> V_127 != V_299 )
V_27 -> V_127 =
V_299 ;
}
} else if ( V_24 -> V_124 &
( V_8 | V_14 ) ) {
V_27 -> V_127 = V_301 ;
} else {
V_27 -> V_127 = V_299 ;
}
}
F_96 ( V_53 , V_27 -> V_127 ) ;
}
void F_97 ( struct V_21 * V_22 )
{
int V_2 , V_4 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
struct V_77 * V_158 = & V_27 -> V_159 ;
unsigned char * V_1 = V_158 -> V_302 ;
V_2 = F_98 ( V_158 -> V_302 ) ;
if ( ( V_27 -> V_181 ) && ( V_27 -> V_168 ) )
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
V_24 -> V_124 =
V_4 & V_22 -> V_123 . V_303 ;
F_99 ( V_22 , 0x08 , 0x08 , 0x0a , 0x0a ) ;
if ( V_24 -> V_124 & V_6 )
F_89 ( V_22 , V_32 ) ;
else
F_89 ( V_22 , V_36 ) ;
}
void F_100 ( struct V_21 * V_22 , T_2 V_96 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
if ( V_24 -> V_124 & V_6 ) {
memcpy ( ( V_27 -> V_88 [ V_96 ] . V_302 ) ,
V_267 , 4 ) ;
} else {
memcpy ( V_27 -> V_88 [ V_96 ] . V_302 ,
V_269 , 3 ) ;
}
}
int F_101 ( struct V_21 * V_22 , T_1 * V_304 ,
T_4 V_305 , int V_306 )
{
int V_307 = 0 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
const T_1 * V_98 ;
V_98 = F_66 ( V_308 , V_304 , V_305 ) ;
if ( ! V_98 )
return V_104 ;
memcpy ( V_27 -> V_88 [ V_306 ] . V_302 , V_98 + 2 , V_98 [ 1 ] ) ;
V_307 = V_98 [ 1 ] ;
V_98 = F_66 ( V_309 , V_304 , V_305 ) ;
if ( V_98 )
memcpy ( V_27 -> V_88 [ V_306 ] . V_302 +
V_307 , V_98 + 2 , V_98 [ 1 ] ) ;
return V_241 ;
}
void F_102 ( struct V_21 * V_22 ,
T_1 * V_310 , T_1 * V_311 )
{
struct V_156 * V_157 ;
T_3 V_312 , V_313 , V_314 ;
struct V_315 * V_316 ;
struct V_160 * V_161 = & V_22 -> V_162 ;
struct V_317 * V_318 = (struct V_317 * ) V_310 ;
struct V_23 * V_24 = & V_22 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
V_157 = F_52 ( V_161 , V_311 ) ;
if ( V_157 ) {
V_313 = F_31 ( V_318 -> V_319 ) >> 4 ;
V_314 = F_31 ( V_318 -> V_320 ) ;
V_312 = ( V_314 >> 2 ) & 0x0f ;
V_316 = & V_157 -> V_321 [ V_312 ] ;
V_316 -> V_322 = 0xffff ;
V_316 -> V_323 = ( V_27 -> V_324 == true ) ?
true : false ;
}
}
int F_103 ( struct V_21 * V_58 , bool V_325 )
{
int V_89 = V_241 ;
if ( V_325 ) {
if ( V_326 == NULL ) {
V_326 = V_58 ;
F_27 ( L_44
L_45 , V_73 ) ;
} else {
V_58 -> V_327 = V_326 ;
V_326 -> V_327 = V_58 ;
V_326 = NULL ;
F_27 ( L_46
L_47 , V_73 ) ;
}
} else
V_326 = NULL ;
return V_89 ;
}
