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
T_1 F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
T_1 V_7 , V_8 , V_9 = V_10 ;
F_4 ( V_4 , V_11 , ( T_1 * ) ( & V_8 ) ) ;
if ( V_8 == V_10 ) {
V_9 = V_10 ;
} else if ( F_5 ( V_6 -> V_12 ) ) {
if ( V_6 -> V_13 & 0xffc00000 )
V_9 = V_14 ;
} else if ( F_6 ( V_6 -> V_12 ) ) {
if ( V_6 -> V_13 & 0xfff00000 )
V_9 = V_14 ;
}
switch ( V_6 -> V_12 ) {
case V_15 :
V_7 = V_16 ;
break;
case V_17 :
case V_18 :
V_7 = V_19 ;
break;
case V_20 :
V_7 = V_21 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if ( V_9 == V_14 )
V_7 = V_26 ;
else
V_7 = V_27 ;
break;
case V_28 :
case V_29 :
if ( V_6 -> V_30 == V_31 ) {
if ( V_9 == V_14 )
V_7 = V_32 ;
else
V_7 = V_33 ;
} else {
if ( V_9 == V_14 )
V_7 = V_34 ;
else
V_7 = V_35 ;
}
break;
default:
V_7 = V_34 ;
break;
}
return V_7 ;
}
unsigned char F_7 ( unsigned char V_1 )
{
unsigned char V_36 = 0 ;
switch ( V_1 & 0x7f ) {
case 0 :
V_36 = V_37 ;
break;
case 1 :
V_36 = V_38 ;
break;
case 2 :
V_36 = V_39 ;
break;
case 3 :
V_36 = V_40 ;
break;
case 4 :
V_36 = V_41 ;
break;
case 5 :
V_36 = V_42 ;
break;
case 6 :
V_36 = V_43 ;
break;
case 7 :
V_36 = V_44 ;
break;
case 8 :
V_36 = V_45 ;
break;
case 9 :
V_36 = V_46 ;
break;
case 10 :
V_36 = V_47 ;
break;
case 11 :
V_36 = V_48 ;
break;
}
return V_36 ;
}
int F_8 ( struct V_4 * V_49 , unsigned char V_1 )
{
int V_3 ;
unsigned char V_36 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ ) {
V_36 = V_51 -> V_54 [ V_3 ] ;
if ( ( V_36 != 0xff ) && ( V_36 != 0xfe ) )
if ( V_1 == F_7 ( V_36 ) )
return true ;
}
return false ;
}
unsigned int F_9 ( struct V_4 * V_49 , unsigned char * V_55 )
{
int V_3 ;
unsigned char V_1 ;
unsigned int V_56 = 0 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ ) {
V_1 = V_51 -> V_57 [ V_3 ] ;
switch ( V_1 ) {
case 0xff :
return V_56 ;
case 0xfe :
continue;
default:
V_1 = F_7 ( V_1 ) ;
if ( F_8 ( V_49 , V_1 ) == true )
V_1 |= V_58 ;
V_55 [ V_56 ] = V_1 ;
V_56 ++ ;
break;
}
}
return V_56 ;
}
void F_10 ( struct V_4 * V_49 , unsigned char * V_59 , int * V_60 )
{
unsigned char V_61 [ V_53 ] ;
memset ( V_61 , 0 , V_53 ) ;
* V_60 = F_9 ( V_49 , V_61 ) ;
memcpy ( V_59 , V_61 , * V_60 ) ;
}
void F_11 ( T_1 * V_62 , T_2 V_63 )
{
T_1 V_64 = ( T_1 ) ( V_63 & 0xff ) ;
T_1 V_65 = ( T_1 ) ( ( V_63 >> 8 ) & 0xff ) ;
T_1 V_66 = ( T_1 ) ( ( V_63 >> 16 ) & 0xff ) ;
T_1 V_67 = ( T_1 ) ( ( V_63 >> 24 ) & 0xff ) ;
V_62 [ 0 ] &= V_64 ;
V_62 [ 1 ] &= V_65 ;
V_62 [ 2 ] &= V_66 ;
V_62 [ 3 ] &= V_67 ;
}
void F_12 ( struct V_4 * V_68 , T_1 * V_69 )
{
T_1 V_3 ;
T_1 V_1 ;
for ( V_3 = 0 ; V_3 < V_70 ; V_3 ++ ) {
V_1 = V_69 [ V_3 ] & 0x7f ;
switch ( V_1 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_43 :
case V_45 :
V_69 [ V_3 ] |= V_58 ;
break;
}
}
}
void F_13 ( T_1 * V_71 , T_2 V_72 )
{
T_1 V_3 ;
T_1 V_1 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
V_1 = V_71 [ V_3 ] & 0x7f ;
switch ( V_1 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_71 [ V_3 ] |= V_58 ;
break;
}
}
}
void F_14 ( struct V_4 * V_49 )
{
T_1 V_73 = true ;
F_15 ( V_49 , V_74 , ( T_1 * ) ( & V_73 ) ) ;
}
void F_16 ( struct V_4 * V_49 )
{
T_1 V_73 = false ;
F_15 ( V_49 , V_74 , ( T_1 * ) ( & V_73 ) ) ;
}
void F_17 ( struct V_4 * V_49 , T_2 V_75 , T_1 V_76 )
{
if ( V_76 == true )
F_15 ( V_49 , V_77 , ( T_1 * ) ( & V_75 ) ) ;
else
F_15 ( V_49 , V_78 , ( T_1 * ) ( & V_75 ) ) ;
}
static void F_18 ( struct V_4 * V_49 , T_1 type )
{
F_15 ( V_49 , V_79 , ( T_1 * ) ( & type ) ) ;
}
void F_19 ( struct V_4 * V_49 , T_1 type )
{
F_18 ( V_49 , type ) ;
}
inline T_1 F_20 ( struct V_4 * V_4 )
{
return F_21 ( V_4 ) -> V_80 ;
}
inline void F_22 ( struct V_4 * V_4 , T_1 V_81 )
{
#ifdef F_23
const int V_56 = 128 ;
char V_82 [ 128 ] = { 0 } ;
int V_83 = 0 ;
int V_3 = 0 ;
#endif
struct V_84 * V_85 = F_21 ( V_4 ) ;
if ( V_85 -> V_80 != V_81 ) {
V_85 -> V_86 = V_87 ;
#ifdef F_23
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_1 , V_81 ) ;
for ( V_3 = 0 ; V_3 < V_85 -> V_88 ; V_3 ++ ) {
struct V_4 * V_89 = V_85 -> V_90 [ V_3 ] ;
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_2 V_91 L_3 , F_24 ( V_89 ) ) ;
if ( V_89 -> V_52 . V_92 == V_81 )
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_4 ) ;
else
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_5 ) ;
if ( V_89 -> V_93 . V_94 == V_81 && ! F_25 ( & V_89 -> V_93 , V_95 ) )
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_6 ) ;
else
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_5 ) ;
V_83 += snprintf ( V_82 + V_83 , V_56 - V_83 , L_7 ) ;
}
F_26 ( V_96 L_8 , F_27 ( V_4 ) , V_82 ) ;
#endif
}
V_85 -> V_80 = V_81 ;
}
inline T_1 F_28 ( struct V_4 * V_4 )
{
return F_21 ( V_4 ) -> V_97 ;
}
inline void F_29 ( struct V_4 * V_4 , T_1 V_98 )
{
F_21 ( V_4 ) -> V_97 = V_98 ;
}
inline T_1 F_30 ( struct V_4 * V_4 )
{
return F_21 ( V_4 ) -> V_99 ;
}
inline void F_31 ( struct V_4 * V_4 , T_1 V_100 )
{
F_21 ( V_4 ) -> V_99 = V_100 ;
}
T_1 F_32 ( T_1 V_101 , T_1 V_102 , T_1 V_103 )
{
T_1 V_104 = V_101 ;
if ( V_102 == V_105 ) {
if ( ( V_101 == 36 ) || ( V_101 == 40 ) || ( V_101 == 44 ) || ( V_101 == 48 ) )
V_104 = 42 ;
if ( ( V_101 == 52 ) || ( V_101 == 56 ) || ( V_101 == 60 ) || ( V_101 == 64 ) )
V_104 = 58 ;
if ( ( V_101 == 100 ) || ( V_101 == 104 ) || ( V_101 == 108 ) || ( V_101 == 112 ) )
V_104 = 106 ;
if ( ( V_101 == 116 ) || ( V_101 == 120 ) || ( V_101 == 124 ) || ( V_101 == 128 ) )
V_104 = 122 ;
if ( ( V_101 == 132 ) || ( V_101 == 136 ) || ( V_101 == 140 ) || ( V_101 == 144 ) )
V_104 = 138 ;
if ( ( V_101 == 149 ) || ( V_101 == 153 ) || ( V_101 == 157 ) || ( V_101 == 161 ) )
V_104 = 155 ;
else if ( V_101 <= 14 )
V_104 = 7 ;
} else if ( V_102 == V_106 ) {
if ( V_103 == V_107 )
V_104 = V_101 + 2 ;
else
V_104 = V_101 - 2 ;
}
return V_104 ;
}
inline unsigned long F_33 ( struct V_4 * V_4 )
{
if ( V_4 -> V_52 . V_92 == F_21 ( V_4 ) -> V_80 )
return F_21 ( V_4 ) -> V_86 ;
else
return 0 ;
}
void F_34 ( struct V_4 * V_49 , unsigned char V_101 )
{
if ( F_35 ( & ( F_21 ( V_49 ) -> V_108 ) ) )
return;
F_22 ( V_49 , V_101 ) ;
F_36 ( V_49 , V_101 ) ;
F_37 ( & ( F_21 ( V_49 ) -> V_108 ) ) ;
}
void F_38 ( struct V_4 * V_49 , unsigned char V_101 , unsigned char V_109 , unsigned short V_110 )
{
T_1 V_104 , V_111 = V_112 ;
if ( V_49 -> V_113 )
F_26 ( L_9 , V_114 , V_101 , V_109 , V_110 ) ;
V_104 = F_32 ( V_101 , V_110 , V_109 ) ;
if ( V_110 == V_105 ) {
if ( V_104 > V_101 )
V_111 = V_107 ;
else if ( V_104 < V_101 )
V_111 = V_115 ;
else
V_111 = V_112 ;
}
if ( F_35 ( & ( F_21 ( V_49 ) -> V_108 ) ) )
return;
F_22 ( V_49 , V_101 ) ;
F_29 ( V_49 , V_110 ) ;
F_31 ( V_49 , V_109 ) ;
F_39 ( V_49 , V_104 , V_110 , V_109 , V_111 ) ;
F_37 ( & ( F_21 ( V_49 ) -> V_108 ) ) ;
}
T_3 T_1 * F_40 ( struct V_116 * V_117 )
{
return V_117 -> V_118 ;
}
T_4 F_41 ( struct V_116 * V_119 )
{
T_5 V_36 ;
memcpy ( ( unsigned char * ) & V_36 , F_42 ( V_119 -> V_120 ) , 2 ) ;
return F_43 ( V_36 ) ;
}
int F_44 ( struct V_4 * V_49 )
{
struct V_50 * V_51 ;
struct V_121 * V_122 ;
if ( ! V_49 )
return V_123 ;
V_51 = & V_49 -> V_52 ;
V_122 = & ( V_51 -> V_124 ) ;
if ( ( V_122 -> V_125 & V_126 ) && ( ( V_122 -> V_125 & 0x03 ) == V_127 ) )
return true ;
else
return V_123 ;
}
int F_45 ( struct V_4 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
if ( ( V_122 -> V_125 & V_126 ) && ( ( V_122 -> V_125 & 0x03 ) == V_128 ) )
return true ;
else
return V_123 ;
}
int F_46 ( struct V_4 * V_49 )
{
unsigned int V_3 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
for ( V_3 = V_129 ; V_3 < V_130 ; V_3 ++ ) {
if ( V_122 -> V_131 [ V_3 ] . V_132 == 1 )
return V_123 ;
}
return true ;
}
unsigned int F_47 ( unsigned int V_133 )
{
if ( ( V_133 << 2 ) < V_134 )
return V_134 ;
else if ( ( V_133 << 2 ) > V_135 )
return V_135 ;
else
return ( ( V_133 << 2 ) ) ;
}
void F_48 ( struct V_4 * V_49 )
{
struct V_84 * V_85 = F_21 ( V_49 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
F_15 ( V_49 , V_138 , NULL ) ;
F_49 ( & V_137 -> V_139 ) ;
V_137 -> V_140 = 0 ;
memset ( V_85 -> V_141 , 0 , sizeof( struct V_142 ) * V_143 ) ;
F_50 ( & V_137 -> V_139 ) ;
}
static T_2 F_51 ( struct V_4 * V_49 , T_2 V_144 )
{
T_2 V_145 = 0 , V_146 ;
V_146 = V_147 | V_144 ;
F_52 ( V_49 , V_148 , V_146 ) ;
do {
if ( 0 == ( F_53 ( V_49 , V_149 ) & V_147 ) )
break;
} while ( V_145 ++ < 100 );
return F_53 ( V_49 , V_150 ) ;
}
void F_54 ( struct V_4 * V_49 , T_1 V_151 , T_1 * V_152 )
{
T_2 V_153 , V_144 , V_146 ;
V_144 = V_151 << 3 ;
for ( V_153 = 0 ; V_153 < 6 ; V_153 ++ ) {
V_146 = F_51 ( V_49 , V_144 + V_153 ) ;
if ( V_153 > 1 )
memcpy ( V_152 + ( V_153 - 2 ) * 4 , & V_146 , 4 ) ;
}
}
void F_55 ( struct V_4 * V_49 , T_1 V_151 , T_4 V_154 , T_1 * V_155 , T_1 * V_156 )
{
unsigned int V_3 , V_36 , V_144 ;
int V_153 ;
T_2 V_157 [ 2 ] ;
V_144 = V_151 << 3 ;
for ( V_153 = 5 ; V_153 >= 0 ; V_153 -- ) {
switch ( V_153 ) {
case 0 :
V_36 = ( V_154 | ( V_155 [ 0 ] << 16 ) | ( V_155 [ 1 ] << 24 ) ) ;
break;
case 1 :
V_36 = ( V_155 [ 2 ] | ( V_155 [ 3 ] << 8 ) | ( V_155 [ 4 ] << 16 ) | ( V_155 [ 5 ] << 24 ) ) ;
break;
default:
V_3 = ( V_153 - 2 ) << 2 ;
V_36 = ( V_156 [ V_3 ] | ( V_156 [ V_3 + 1 ] << 8 ) | ( V_156 [ V_3 + 2 ] << 16 ) | ( V_156 [ V_3 + 3 ] << 24 ) ) ;
break;
}
V_157 [ 0 ] = V_36 ;
V_157 [ 1 ] = V_144 + ( unsigned int ) V_153 ;
F_15 ( V_49 , V_158 , ( T_1 * ) V_157 ) ;
}
}
void F_56 ( struct V_4 * V_49 , T_1 V_151 )
{
unsigned char V_159 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_160 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_55 ( V_49 , V_151 , 0 , V_159 , V_160 ) ;
}
inline void F_57 ( struct V_4 * V_4 , T_1 V_161 , T_4 V_154 , T_1 * V_155 , T_1 * V_156 )
{
F_55 ( V_4 , V_161 , V_154 , V_155 , V_156 ) ;
F_58 ( V_4 , V_161 , V_154 , V_155 , V_156 ) ;
}
inline void F_59 ( struct V_4 * V_4 , T_1 V_161 )
{
F_56 ( V_4 , V_161 ) ;
F_60 ( V_4 , V_161 ) ;
}
inline void F_61 ( struct V_4 * V_4 , T_1 V_161 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
struct V_142 V_162 ;
F_49 ( & V_137 -> V_139 ) ;
memcpy ( & V_162 , & V_85 -> V_141 [ V_161 ] , sizeof( struct V_142 ) ) ;
F_50 ( & V_137 -> V_139 ) ;
F_55 ( V_4 , V_161 , V_162 . V_154 , V_162 . V_155 , V_162 . V_156 ) ;
}
void F_58 ( struct V_4 * V_4 , T_1 V_161 , T_4 V_154 , T_1 * V_155 , T_1 * V_156 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
F_49 ( & V_137 -> V_139 ) ;
V_85 -> V_141 [ V_161 ] . V_154 = V_154 ;
memcpy ( V_85 -> V_141 [ V_161 ] . V_155 , V_155 , V_163 ) ;
memcpy ( V_85 -> V_141 [ V_161 ] . V_156 , V_156 , 16 ) ;
F_50 ( & V_137 -> V_139 ) ;
}
void F_60 ( struct V_4 * V_4 , T_1 V_161 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
F_49 ( & V_137 -> V_139 ) ;
memset ( & ( V_85 -> V_141 [ V_161 ] ) , 0 , sizeof( struct V_142 ) ) ;
F_50 ( & V_137 -> V_139 ) ;
}
static bool F_62 ( struct V_4 * V_4 , T_1 V_164 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
bool V_165 = false ;
if ( V_164 >= V_143 )
goto exit;
if ( ! ( V_137 -> V_140 & F_63 ( V_164 ) ) )
goto exit;
V_165 = ( V_85 -> V_141 [ V_164 ] . V_154 & V_166 ) ? true : false ;
exit:
return V_165 ;
}
static T_6 F_64 ( struct V_4 * V_4 , T_1 * V_144 , T_6 V_167 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
int V_3 ;
T_6 V_164 = - 1 ;
for ( V_3 = 0 ; V_3 < V_143 ; V_3 ++ ) {
if ( V_144 && memcmp ( V_85 -> V_141 [ V_3 ] . V_155 , V_144 , V_163 ) )
continue;
if ( V_167 >= 0 && V_167 != ( V_85 -> V_141 [ V_3 ] . V_154 & 0x03 ) )
continue;
V_164 = V_3 ;
break;
}
if ( V_144 )
F_26 ( V_96 L_10 V_168 L_11
, F_27 ( V_4 ) , F_65 ( V_144 ) , V_167 , V_164 ) ;
else
F_26 ( V_96 L_12
, F_27 ( V_4 ) , V_144 , V_167 , V_164 ) ;
return V_164 ;
}
T_6 F_66 ( struct V_4 * V_4 , T_1 * V_144 , T_6 V_167 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
T_6 V_164 = - 1 ;
F_49 ( & V_137 -> V_139 ) ;
V_164 = F_64 ( V_4 , V_144 , V_167 ) ;
F_50 ( & V_137 -> V_139 ) ;
return V_164 ;
}
T_6 F_67 ( struct V_4 * V_4 , struct V_5 * V_169 , T_1 V_167 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
T_6 V_164 = - 1 ;
struct V_121 * V_170 ;
F_49 ( & V_137 -> V_139 ) ;
V_170 = & V_4 -> V_52 . V_124 ;
if ( ( ( ( V_170 -> V_125 & 0x03 ) == V_171 ) || ( ( V_170 -> V_125 & 0x03 ) == V_128 ) )
&& ! V_169 ) {
if ( V_167 > 3 ) {
F_68 ( V_172 , V_96 L_13
, F_27 ( V_4 ) , V_167 ) ;
F_69 ( 1 ) ;
goto V_173;
}
V_164 = V_167 ;
} else {
int V_3 ;
T_1 * V_144 = V_169 ? V_169 -> V_174 : NULL ;
if ( ! V_169 ) {
if ( ! ( V_170 -> V_125 & V_126 ) ) {
goto V_173;
}
V_144 = F_70 ( & V_4 -> V_175 ) ;
}
V_3 = F_64 ( V_4 , V_144 , V_167 ) ;
if ( V_3 >= 0 ) {
if ( V_169 || F_62 ( V_4 , V_3 ) == true )
V_164 = V_3 ;
else
F_68 ( V_172 , V_96 L_14
, F_27 ( V_4 ) , V_167 ) ;
goto V_173;
}
for ( V_3 = 4 ; V_3 < V_143 ; V_3 ++ )
if ( ! ( V_137 -> V_140 & F_63 ( V_3 ) ) )
break;
if ( V_3 == V_143 ) {
if ( V_169 )
F_68 ( V_172 , V_96 L_15 V_168 L_16
, F_27 ( V_4 ) , F_65 ( V_169 -> V_174 ) , V_167 ) ;
else
F_68 ( V_172 , V_96 L_17
, F_27 ( V_4 ) , V_167 ) ;
F_69 ( 1 ) ;
goto V_173;
}
V_164 = V_3 ;
}
V_173:
if ( V_164 >= 0 && V_164 < 32 )
V_137 -> V_140 |= F_63 ( V_164 ) ;
F_50 ( & V_137 -> V_139 ) ;
return V_164 ;
}
void F_71 ( struct V_4 * V_4 , T_1 V_164 )
{
struct V_84 * V_85 = F_21 ( V_4 ) ;
struct V_136 * V_137 = & V_85 -> V_137 ;
F_49 ( & V_137 -> V_139 ) ;
if ( V_164 < V_143 )
V_137 -> V_140 &= ~ ( F_63 ( V_164 ) ) ;
F_50 ( & V_137 -> V_139 ) ;
}
int F_72 ( struct V_4 * V_49 )
{
unsigned int V_176 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
for ( V_176 = V_129 ; V_176 < V_130 ; V_176 ++ ) {
if ( V_122 -> V_131 [ V_176 ] . V_132 == 0 ) {
V_122 -> V_131 [ V_176 ] . V_132 = 1 ;
V_122 -> V_131 [ V_176 ] . V_177 = 0 ;
break;
}
}
return V_176 ;
}
void F_73 ( struct V_4 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
F_48 ( V_49 ) ;
F_15 ( V_49 , V_178 , ( T_1 * ) false ) ;
memset ( ( T_1 * ) ( V_122 -> V_131 ) , 0 , sizeof( V_122 -> V_131 ) ) ;
}
int F_74 ( struct V_4 * V_49 , struct V_179 * V_180 )
{
struct V_181 * V_182 = & ( V_49 -> V_175 ) ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
if ( V_182 -> V_183 . V_184 == 0 ) {
V_122 -> V_185 = 0 ;
return false ;
}
if ( ! memcmp ( & ( V_122 -> V_186 ) , ( V_180 -> V_187 + 6 ) , sizeof( struct V_188 ) ) )
return false ;
else
memcpy ( & ( V_122 -> V_186 ) , ( V_180 -> V_187 + 6 ) , sizeof( struct V_188 ) ) ;
V_122 -> V_185 = 1 ;
return true ;
}
void F_75 ( struct V_4 * V_49 )
{
T_1 V_189 , V_190 , V_191 , V_192 , V_193 , V_194 ;
T_1 V_195 ;
T_4 V_196 ;
T_2 V_197 , V_3 ;
T_2 V_198 [ 4 ] , V_199 [ 4 ] ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_200 * V_201 = & V_49 -> V_202 ;
struct V_203 * V_204 = & V_49 -> V_205 ;
V_195 = 0 ;
if ( V_51 -> V_206 & V_22 )
V_194 = 16 ;
else
V_194 = 10 ;
if ( V_122 -> V_185 == 0 ) {
V_49 -> V_175 . V_195 = 0 ;
V_191 = V_194 + ( 2 * V_122 -> V_207 ) ;
if ( V_51 -> V_206 & ( V_18 | V_17 ) ) {
V_192 = 4 ;
V_193 = 10 ;
} else if ( V_51 -> V_206 & V_15 ) {
V_192 = 5 ;
V_193 = 10 ;
} else {
V_192 = 4 ;
V_193 = 10 ;
}
V_196 = 0 ;
V_197 = V_191 | ( V_192 << 8 ) | ( V_193 << 12 ) | ( V_196 << 16 ) ;
F_15 ( V_49 , V_208 , ( T_1 * ) ( & V_197 ) ) ;
F_15 ( V_49 , V_209 , ( T_1 * ) ( & V_197 ) ) ;
F_15 ( V_49 , V_210 , ( T_1 * ) ( & V_197 ) ) ;
V_192 = 2 ;
V_193 = 3 ;
V_196 = 0x2f ;
V_197 = V_191 | ( V_192 << 8 ) | ( V_193 << 12 ) | ( V_196 << 16 ) ;
F_15 ( V_49 , V_211 , ( T_1 * ) ( & V_197 ) ) ;
} else{
V_198 [ 0 ] = V_198 [ 1 ] = V_198 [ 2 ] = V_198 [ 3 ] = 0 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_189 = ( V_122 -> V_186 . V_212 [ V_3 ] . V_213 >> 5 ) & 0x03 ;
V_190 = ( V_122 -> V_186 . V_212 [ V_3 ] . V_213 >> 4 ) & 0x01 ;
V_191 = ( V_122 -> V_186 . V_212 [ V_3 ] . V_213 & 0x0f ) * V_122 -> V_207 + V_194 ;
V_192 = ( V_122 -> V_186 . V_212 [ V_3 ] . V_214 & 0x0f ) ;
V_193 = ( V_122 -> V_186 . V_212 [ V_3 ] . V_214 & 0xf0 ) >> 4 ;
V_196 = F_43 ( V_122 -> V_186 . V_212 [ V_3 ] . V_215 ) ;
V_197 = V_191 | ( V_192 << 8 ) | ( V_193 << 12 ) | ( V_196 << 16 ) ;
switch ( V_189 ) {
case 0x0 :
F_15 ( V_49 , V_208 , ( T_1 * ) ( & V_197 ) ) ;
V_195 |= ( V_190 ? F_63 ( 1 ) : 0 ) ;
V_198 [ V_216 ] = V_197 ;
break;
case 0x1 :
F_15 ( V_49 , V_209 , ( T_1 * ) ( & V_197 ) ) ;
V_198 [ V_217 ] = V_197 ;
break;
case 0x2 :
F_15 ( V_49 , V_210 , ( T_1 * ) ( & V_197 ) ) ;
V_195 |= ( V_190 ? F_63 ( 2 ) : 0 ) ;
V_198 [ V_218 ] = V_197 ;
break;
case 0x3 :
F_15 ( V_49 , V_211 , ( T_1 * ) ( & V_197 ) ) ;
V_195 |= ( V_190 ? F_63 ( 3 ) : 0 ) ;
V_198 [ V_219 ] = V_197 ;
break;
}
F_26 ( L_18 , V_189 , V_190 , V_197 ) ;
}
if ( V_49 -> V_205 . V_220 == 1 )
F_15 ( V_49 , V_221 , ( T_1 * ) ( & V_195 ) ) ;
else
V_49 -> V_175 . V_195 = V_195 ;
V_199 [ 0 ] = 0 ; V_199 [ 1 ] = 1 ; V_199 [ 2 ] = 2 ; V_199 [ 3 ] = 3 ;
if ( V_204 -> V_222 == 1 ) {
T_2 V_153 , V_223 , V_224 = false ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_153 = V_3 + 1 ; V_153 < 4 ; V_153 ++ ) {
if ( ( V_198 [ V_153 ] & 0xFFFF ) < ( V_198 [ V_3 ] & 0xFFFF ) ) {
V_224 = true ;
} else if ( ( V_198 [ V_153 ] & 0xFFFF ) == ( V_198 [ V_3 ] & 0xFFFF ) ) {
if ( ( V_198 [ V_153 ] >> 16 ) > ( V_198 [ V_3 ] >> 16 ) )
V_224 = true ;
}
if ( V_224 ) {
V_223 = V_198 [ V_3 ] ;
V_198 [ V_3 ] = V_198 [ V_153 ] ;
V_198 [ V_153 ] = V_223 ;
V_223 = V_199 [ V_3 ] ;
V_199 [ V_3 ] = V_199 [ V_153 ] ;
V_199 [ V_153 ] = V_223 ;
V_224 = false ;
}
}
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_201 -> V_225 [ V_3 ] = V_199 [ V_3 ] ;
F_26 ( L_19 , V_3 , V_201 -> V_225 [ V_3 ] ) ;
}
}
}
static void F_76 ( struct V_4 * V_49 , struct V_179 * V_180 )
{
unsigned char V_226 ;
unsigned char V_227 ;
struct V_228 * V_229 ;
struct V_181 * V_182 = & ( V_49 -> V_175 ) ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_203 * V_230 = & V_49 -> V_205 ;
struct V_231 * V_232 = & V_182 -> V_233 ;
T_1 V_234 = 0 ;
if ( ! V_180 )
return;
if ( V_232 -> V_235 == false )
return;
if ( V_51 -> V_236 >= V_105 )
return;
if ( V_180 -> V_237 > sizeof( struct V_228 ) )
return;
V_229 = (struct V_228 * ) V_180 -> V_187 ;
if ( V_51 -> V_92 > 14 ) {
if ( ( V_230 -> V_30 & 0xf0 ) > 0 )
V_234 = 1 ;
} else
if ( ( V_230 -> V_30 & 0x0f ) > 0 )
V_234 = 1 ;
if ( ( V_229 -> V_238 [ 0 ] & F_63 ( 2 ) ) && V_234 ) {
V_226 = V_106 ;
switch ( V_229 -> V_238 [ 0 ] & 0x3 ) {
case 1 :
V_227 = V_107 ;
break;
case 3 :
V_227 = V_115 ;
break;
default:
V_226 = V_31 ;
V_227 = V_112 ;
break;
}
} else{
V_226 = V_31 ;
V_227 = V_112 ;
}
if ( ( V_226 != V_51 -> V_236 ) || ( V_227 != V_51 -> V_239 ) ) {
V_122 -> V_240 = true ;
V_51 -> V_236 = V_226 ;
V_51 -> V_239 = V_227 ;
F_77 ( V_49 , V_180 ) ;
} else
V_122 -> V_240 = false ;
if ( true == V_122 -> V_240 ) {
struct V_5 * V_6 ;
struct V_116 * V_241 = & ( V_122 -> V_242 ) ;
struct V_243 * V_244 = & V_49 -> V_245 ;
V_6 = F_78 ( V_244 , V_241 -> V_118 ) ;
if ( V_6 ) {
struct V_231 * V_246 = & V_6 -> V_233 ;
if ( V_246 -> V_235 ) {
V_6 -> V_30 = V_51 -> V_236 ;
V_246 -> V_247 = V_51 -> V_239 ;
} else{
V_6 -> V_30 = V_31 ;
V_246 -> V_247 = V_112 ;
}
F_79 ( V_49 , ( T_1 * ) V_6 ) ;
}
}
}
void F_80 ( struct V_4 * V_49 , struct V_179 * V_180 )
{
unsigned int V_3 ;
T_1 V_9 ;
T_1 V_248 , V_249 ;
T_1 V_250 = 0 , V_251 = 0 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_181 * V_182 = & V_49 -> V_175 ;
struct V_231 * V_232 = & V_182 -> V_233 ;
if ( V_180 == NULL )
return;
if ( V_232 -> V_235 == false )
return;
V_122 -> V_252 = 1 ;
for ( V_3 = 0 ; V_3 < ( V_180 -> V_237 ) ; V_3 ++ ) {
if ( V_3 != 2 ) {
V_122 -> V_253 . V_254 . V_255 [ V_3 ] &= ( V_180 -> V_187 [ V_3 ] ) ;
} else{
if ( ( V_122 -> V_253 . V_254 . V_256 . V_257 & 0x3 ) > ( V_180 -> V_187 [ V_3 ] & 0x3 ) )
V_248 = ( V_180 -> V_187 [ V_3 ] & 0x3 ) ;
else
V_248 = ( V_122 -> V_253 . V_254 . V_256 . V_257 & 0x3 ) ;
if ( ( V_122 -> V_253 . V_254 . V_256 . V_257 & 0x1c ) > ( V_180 -> V_187 [ V_3 ] & 0x1c ) )
V_249 = ( V_122 -> V_253 . V_254 . V_256 . V_257 & 0x1c ) ;
else
V_249 = ( V_180 -> V_187 [ V_3 ] & 0x1c ) ;
V_122 -> V_253 . V_254 . V_256 . V_257 = V_248 | V_249 ;
}
}
F_4 ( V_49 , V_11 , ( T_1 * ) ( & V_9 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_122 -> V_253 . V_254 . V_256 . V_258 [ V_3 ] &= V_51 -> V_259 [ V_3 ] ;
switch ( V_9 ) {
case V_10 :
case V_260 :
F_11 ( V_122 -> V_253 . V_254 . V_256 . V_258 , V_261 ) ;
break;
case V_14 :
default:
#ifdef F_81
if ( V_51 -> V_236 == V_106 && V_230 -> V_222 != 1 )
F_11 ( V_122 -> V_253 . V_254 . V_256 . V_258 , V_262 ) ;
else
F_11 ( V_122 -> V_253 . V_254 . V_256 . V_258 , V_263 ) ;
#else
F_11 ( V_122 -> V_253 . V_254 . V_256 . V_258 , V_263 ) ;
#endif
}
if ( F_82 ( V_182 , V_264 ) ) {
if ( F_83 ( V_232 -> V_265 , V_266 ) && F_84 ( V_180 -> V_187 ) ) {
F_85 ( V_251 , V_266 ) ;
F_26 ( L_20 ) ;
}
V_232 -> V_265 = V_251 ;
} else {
if ( F_83 ( V_232 -> V_267 , V_268 ) && F_86 ( V_180 -> V_187 ) ) {
F_85 ( V_250 , ( V_268 | V_269 ) ) ;
F_26 ( L_21 ) ;
}
V_232 -> V_267 = V_250 ;
if ( F_83 ( V_232 -> V_265 , V_266 ) && F_87 ( V_180 -> V_187 ) ) {
F_85 ( V_251 , ( V_266 | V_270 ) ) ;
F_26 ( L_22 ) ;
}
V_232 -> V_265 = V_251 ;
}
}
void F_77 ( struct V_4 * V_49 , struct V_179 * V_180 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_181 * V_182 = & V_49 -> V_175 ;
struct V_231 * V_232 = & V_182 -> V_233 ;
if ( V_180 == NULL )
return;
if ( V_232 -> V_235 == false )
return;
if ( V_180 -> V_237 > sizeof( struct V_228 ) )
return;
V_122 -> V_271 = 1 ;
memcpy ( & ( V_122 -> V_272 ) , V_180 -> V_187 , V_180 -> V_237 ) ;
return;
}
void F_88 ( struct V_4 * V_49 )
{
unsigned char V_248 ;
unsigned char V_249 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
F_26 ( L_23 , V_114 ) ;
if ( ( V_122 -> V_271 ) && ( V_122 -> V_252 ) ) {
V_122 -> V_273 = 1 ;
} else{
V_122 -> V_273 = 0 ;
return;
}
V_248 = V_122 -> V_253 . V_254 . V_256 . V_257 & 0x03 ;
V_249 = ( V_122 -> V_253 . V_254 . V_256 . V_257 & 0x1c ) >> 2 ;
F_15 ( V_49 , V_274 , ( T_1 * ) ( & V_249 ) ) ;
F_15 ( V_49 , V_275 , ( T_1 * ) ( & V_248 ) ) ;
}
void F_89 ( struct V_4 * V_49 , struct V_179 * V_180 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
if ( V_180 -> V_237 > 1 )
return;
V_122 -> V_276 = 1 ;
memcpy ( & ( V_122 -> V_277 ) , V_180 -> V_187 , V_180 -> V_237 ) ;
}
void F_90 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
struct V_203 * V_204 = & V_49 -> V_205 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
switch ( V_204 -> V_278 ) {
case 0 :
V_6 -> V_279 = 0 ;
V_6 -> V_280 = 0 ;
break;
case 1 :
if ( V_204 -> V_281 == 1 ) {
V_6 -> V_279 = 1 ;
V_6 -> V_280 = 0 ;
} else{
V_6 -> V_279 = 0 ;
V_6 -> V_280 = 1 ;
}
break;
case 2 :
default:
if ( ( V_122 -> V_276 ) && ( V_122 -> V_277 & F_63 ( 1 ) ) ) {
if ( V_204 -> V_281 == 1 ) {
V_6 -> V_279 = 1 ;
V_6 -> V_280 = 0 ;
} else{
V_6 -> V_279 = 0 ;
V_6 -> V_280 = 1 ;
}
} else{
V_6 -> V_279 = 0 ;
V_6 -> V_280 = 0 ;
}
break;
}
}
void F_91 ( struct V_5 * V_6 )
{
if ( V_6 -> V_233 . V_235 ) {
if ( F_83 ( V_6 -> V_233 . V_267 , V_268 ) )
V_6 -> V_282 = 1 ;
if ( F_83 ( V_6 -> V_233 . V_265 , V_266 ) )
V_6 -> V_283 = 1 ;
} else {
V_6 -> V_282 = 0 ;
V_6 -> V_283 = 0 ;
}
}
int F_92 ( struct V_4 * V_68 , T_1 * V_284 , T_2 V_285 )
{
unsigned int V_56 ;
unsigned char * V_286 ;
unsigned short V_287 , V_288 ;
struct V_289 * V_241 = & ( V_68 -> V_175 . V_241 ) ;
T_4 V_290 = 0 , V_291 = 0 ;
T_1 V_292 = 0 ;
struct V_116 * V_293 ;
int V_294 = 0 , V_295 = 0 , V_296 = 0 ;
unsigned char * V_297 ;
T_2 V_298 = 0 ;
T_1 * V_299 = F_93 ( V_284 ) ;
T_2 V_300 = 0 ;
struct V_228 * V_301 = NULL ;
struct V_302 * V_303 = NULL ;
T_2 V_304 ;
unsigned short V_305 ;
unsigned char V_306 ;
struct V_181 * V_182 = & V_68 -> V_175 ;
if ( F_44 ( V_68 ) == false )
return true ;
V_56 = V_285 - sizeof( struct V_307 ) ;
if ( V_56 > V_308 ) {
F_26 ( L_24 , V_114 ) ;
return V_123 ;
}
if ( memcmp ( V_241 -> V_242 . V_118 , V_299 , 6 ) ) {
F_26 ( L_25 MAC_FMT MAC_FMT,
MAC_ARG(pbssid), MAC_ARG(cur_network->network.MacAddress)) ;
return true ;
}
V_293 = (struct V_116 * ) F_94 ( sizeof( struct V_116 ) ) ;
if ( V_293 == NULL ) {
F_26 ( L_26 , V_114 ) ;
return true ;
}
if ( ( V_182 -> V_309 != 0 ) && ( F_95 ( V_87 - V_182 -> V_309 ) > V_310 ) ) {
V_182 -> V_309 = 0 ;
V_182 -> V_311 = 0 ;
}
V_288 = F_96 ( V_284 ) >> 4 ;
if ( V_288 == V_312 )
V_293 -> V_313 [ 0 ] = 1 ;
V_293 -> V_237 = sizeof( struct V_116 ) - V_308 + V_56 ;
V_293 -> V_314 = V_56 ;
memcpy ( V_293 -> V_120 , ( V_284 + sizeof( struct V_307 ) ) , V_293 -> V_314 ) ;
V_286 = F_97 ( V_293 -> V_120 + V_315 , V_316 , & V_56 , V_293 -> V_314 - V_315 ) ;
if ( V_286 && V_56 > 0 ) {
V_303 = (struct V_302 * ) ( V_286 + 2 ) ;
V_305 = F_43 ( V_303 -> V_317 ) ;
} else {
V_305 = 0 ;
}
V_286 = F_97 ( V_293 -> V_120 + V_315 , V_318 , & V_56 , V_293 -> V_314 - V_315 ) ;
if ( V_286 && V_56 > 0 ) {
V_301 = (struct V_228 * ) ( V_286 + 2 ) ;
V_306 = V_301 -> V_238 [ 0 ] ;
} else {
V_306 = 0 ;
}
if ( V_305 != V_241 -> V_319 . V_305 ||
( ( V_306 & 0x03 ) != ( V_241 -> V_319 . V_306 & 0x03 ) ) ) {
F_26 ( L_27 , V_114 ,
V_305 , V_306 ) ;
F_26 ( L_28 , V_114 ,
V_241 -> V_319 . V_305 , V_241 -> V_319 . V_306 ) ;
F_26 ( L_29 , V_114 ) ;
{
V_241 -> V_319 . V_305 = V_305 ;
V_241 -> V_319 . V_306 = V_306 ;
}
}
V_286 = F_97 ( V_293 -> V_120 + V_315 , V_320 , & V_56 , V_293 -> V_314 - V_315 ) ;
if ( V_286 ) {
V_304 = * ( V_286 + 2 ) ;
} else {
F_97 ( V_293 -> V_120 + V_315 , V_318 , & V_56 , V_293 -> V_314 - V_315 ) ;
if ( V_301 ) {
V_304 = V_301 -> V_321 ;
} else {
V_304 = V_68 -> V_52 . V_92 ;
}
}
if ( V_304 != V_68 -> V_52 . V_92 ) {
F_26 ( L_30 , V_114 ,
V_304 , V_68 -> V_52 . V_92 ) ;
goto V_322;
}
V_286 = F_97 ( V_293 -> V_120 + V_315 , V_323 , & V_56 , V_293 -> V_314 - V_315 ) ;
if ( V_286 == NULL ) {
F_26 ( L_31 , V_114 ) ;
V_300 = true ;
} else {
V_300 = false ;
}
if ( ( NULL != V_286 ) && ( false == V_300 && ( * ( V_286 + 1 ) ) ) ) {
memcpy ( V_293 -> V_324 . V_324 , ( V_286 + 2 ) , * ( V_286 + 1 ) ) ;
V_293 -> V_324 . V_325 = * ( V_286 + 1 ) ;
} else {
V_293 -> V_324 . V_325 = 0 ;
V_293 -> V_324 . V_324 [ 0 ] = '\0' ;
}
F_98 ( V_326 , V_327 , ( L_32
L_33 , V_114 , V_293 -> V_324 . V_324 ,
V_293 -> V_324 . V_325 , V_241 -> V_242 . V_324 . V_324 ,
V_241 -> V_242 . V_324 . V_325 ) ) ;
if ( memcmp ( V_293 -> V_324 . V_324 , V_241 -> V_242 . V_324 . V_324 , 32 ) ||
V_293 -> V_324 . V_325 != V_241 -> V_242 . V_324 . V_325 ) {
if ( V_293 -> V_324 . V_324 [ 0 ] != '\0' && V_293 -> V_324 . V_325 != 0 ) {
F_26 ( L_34 , V_114 ) ;
goto V_322;
}
}
V_287 = F_99 ( (struct V_116 * ) V_293 ) ;
if ( V_287 & F_63 ( 4 ) )
V_293 -> V_328 = 1 ;
else
V_293 -> V_328 = 0 ;
F_98 ( V_326 , V_327 ,
( L_35 ,
V_114 , V_241 -> V_242 . V_328 , V_293 -> V_328 ) ) ;
if ( V_241 -> V_242 . V_328 != V_293 -> V_328 ) {
F_26 ( L_36 , V_114 ) ;
goto V_322;
}
F_100 ( V_293 -> V_120 , V_293 -> V_314 , NULL , & V_291 , NULL , & V_290 ) ;
if ( V_291 > 0 ) {
V_292 = V_329 ;
} else if ( V_290 > 0 ) {
V_292 = V_330 ;
} else {
if ( V_293 -> V_328 )
V_292 = V_331 ;
}
if ( V_241 -> V_319 . V_292 != V_292 ) {
F_26 ( L_37 , V_114 ) ;
goto V_322;
}
if ( V_292 == V_330 || V_292 == V_329 ) {
V_297 = F_101 ( & V_293 -> V_120 [ 12 ] , & V_298 , V_293 -> V_314 - 12 ) ;
if ( V_297 && ( V_298 > 0 ) ) {
if ( V_332 == F_102 ( V_297 , V_298 + 2 , & V_294 , & V_295 , & V_296 ) ) {
F_98 ( V_326 , V_327 ,
( L_38 , V_114 ,
V_295 , V_294 , V_296 ) ) ;
}
} else {
V_297 = F_103 ( & V_293 -> V_120 [ 12 ] , & V_298 , V_293 -> V_314 - 12 ) ;
if ( V_297 && ( V_298 > 0 ) ) {
if ( V_332 == F_104 ( V_297 , V_298 + 2 , & V_294 , & V_295 , & V_296 ) ) {
F_98 ( V_326 , V_327 ,
( L_39 ,
V_114 , V_295 , V_294 , V_296 ) ) ;
}
}
}
F_98 ( V_326 , V_333 ,
( L_40 , V_114 , V_241 -> V_319 . V_294 , V_294 ) ) ;
if ( V_295 != V_241 -> V_319 . V_295 || V_294 != V_241 -> V_319 . V_294 ) {
F_26 ( L_41 , V_114 ,
V_295 , V_241 -> V_319 . V_295 ,
V_294 , V_241 -> V_319 . V_294 ) ;
goto V_322;
}
if ( V_296 != V_241 -> V_319 . V_296 ) {
F_26 ( L_42 , V_114 ) ;
goto V_322;
}
}
F_105 ( ( T_1 * ) V_293 ) ;
return V_332 ;
V_322:
F_105 ( ( T_1 * ) V_293 ) ;
if ( V_182 -> V_311 == 0 )
V_182 -> V_309 = V_87 ;
V_182 -> V_311 ++ ;
F_26 ( L_43 V_91 L_44 , V_114 , F_24 ( V_68 ) , V_182 -> V_311 , F_106 ( V_284 ) ) ;
if ( ( V_182 -> V_309 != 0 ) && ( F_95 ( V_87 - V_182 -> V_309 ) <= V_310 )
&& ( V_182 -> V_311 >= V_334 ) ) {
F_26 ( L_43 V_91 L_45 , V_114 , F_24 ( V_68 ) , V_182 -> V_311 ,
V_334 , F_95 ( V_87 - V_182 -> V_309 ) ) ;
V_182 -> V_309 = 0 ;
V_182 -> V_311 = 0 ;
return V_123 ;
}
return V_332 ;
}
void F_107 ( struct V_4 * V_49 , T_1 * V_284 , T_7 V_335 , struct V_5 * V_6 )
{
unsigned int V_3 ;
unsigned int V_56 ;
struct V_179 * V_180 ;
V_56 = V_335 - ( V_336 + V_337 ) ;
for ( V_3 = 0 ; V_3 < V_56 ; ) {
V_180 = (struct V_179 * ) ( V_284 + ( V_336 + V_337 ) + V_3 ) ;
switch ( V_180 -> V_338 ) {
case V_339 :
if ( ! memcmp ( V_180 -> V_187 , V_340 , 6 ) && V_180 -> V_237 == V_341 )
if ( F_74 ( V_49 , V_180 ) )
F_108 ( V_49 ) ;
break;
case V_342 :
F_76 ( V_49 , V_180 ) ;
break;
case V_343 :
F_89 ( V_49 , V_180 ) ;
F_90 ( V_49 , V_6 ) ;
break;
default:
break;
}
V_3 += ( V_180 -> V_237 + 2 ) ;
}
}
unsigned int F_109 ( struct V_4 * V_49 )
{
T_2 V_3 ;
struct V_179 * V_180 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_116 * V_241 = & ( V_122 -> V_242 ) ;
if ( F_99 ( (struct V_116 * ) V_241 ) & V_344 ) {
for ( V_3 = sizeof( struct V_345 ) ; V_3 < V_122 -> V_242 . V_314 ; ) {
V_180 = (struct V_179 * ) ( V_122 -> V_242 . V_120 + V_3 ) ;
switch ( V_180 -> V_338 ) {
case V_339 :
if ( ( ! memcmp ( V_180 -> V_187 , V_346 , 4 ) ) && ( ! memcmp ( ( V_180 -> V_187 + 12 ) , V_347 , 4 ) ) )
return true ;
break;
case V_348 :
if ( ! memcmp ( ( V_180 -> V_187 + 8 ) , V_349 , 4 ) )
return true ;
default:
break;
}
V_3 += ( V_180 -> V_237 + 2 ) ;
}
return false ;
} else
return false ;
}
int F_110 ( struct V_4 * V_49 , struct V_350 * V_351 , T_1 V_110 )
{
unsigned char V_352 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
if ( ! ( V_122 -> V_273 ) )
return V_123 ;
V_352 = ( V_110 & V_106 ) ? 6 : 5 ;
if ( F_43 ( V_351 -> V_254 . V_256 . V_353 ) & ( 0x1 << V_352 ) )
return V_332 ;
else
return V_123 ;
}
unsigned char F_111 ( T_2 V_63 )
{
int V_3 ;
unsigned char V_354 = 0 ;
for ( V_3 = 31 ; V_3 >= 0 ; V_3 -- ) {
if ( V_63 & F_63 ( V_3 ) ) {
V_354 = V_3 ;
break;
}
}
return V_354 ;
}
void F_112 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
F_113 ( V_6 , 0 ) ;
}
void F_114 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
F_112 ( V_49 , V_6 ) ;
}
void F_115 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
F_114 ( V_49 , V_6 ) ;
}
unsigned char F_116 ( T_1 * V_284 , T_7 V_56 )
{
unsigned int V_3 ;
struct V_179 * V_180 ;
for ( V_3 = sizeof( struct V_345 ) ; V_3 < V_56 ; ) {
V_180 = (struct V_179 * ) ( V_284 + V_3 ) ;
switch ( V_180 -> V_338 ) {
case V_339 :
if ( ( ! memcmp ( V_180 -> V_187 , V_355 , 3 ) ) || ( ! memcmp ( V_180 -> V_187 , V_356 , 3 ) ) ) {
F_26 ( L_46 ) ;
return V_357 ;
} else if ( ( ! memcmp ( V_180 -> V_187 , V_358 , 3 ) )
|| ( ! memcmp ( V_180 -> V_187 , V_359 , 3 ) )
|| ( ! memcmp ( V_180 -> V_187 , V_360 , 3 ) ) ) {
F_26 ( L_47 ) ;
return V_361 ;
} else if ( ! memcmp ( V_180 -> V_187 , V_362 , 3 ) ) {
F_26 ( L_48 ) ;
return V_363 ;
} else if ( ! memcmp ( V_180 -> V_187 , V_364 , 3 ) ) {
F_26 ( L_49 ) ;
return V_365 ;
} else if ( ! memcmp ( V_180 -> V_187 , V_366 , 3 ) ) {
F_26 ( L_50 ) ;
return V_367 ;
} else if ( ! memcmp ( V_180 -> V_187 , V_368 , 3 ) ) {
T_2 V_369 = V_370 ;
if ( V_180 -> V_237 >= 5 ) {
if ( V_180 -> V_187 [ 4 ] == 1 )
if ( V_180 -> V_187 [ 5 ] & V_371 )
V_369 = V_372 ;
if ( V_180 -> V_187 [ 5 ] & V_373 )
V_369 = V_374 ;
if ( V_180 -> V_187 [ 4 ] == 2 ) {
if ( V_180 -> V_187 [ 6 ] & V_375 ) {
V_369 = V_376 ;
F_26 ( L_51 ) ;
}
if ( V_180 -> V_187 [ 6 ] & V_377 ) {
V_369 = V_378 ;
F_26 ( L_52 ) ;
}
}
}
F_26 ( L_53 ) ;
return V_369 ;
} else if ( ! memcmp ( V_180 -> V_187 , V_379 , 3 ) ) {
F_26 ( L_54 ) ;
return V_380 ;
} else
break;
default:
break;
}
V_3 += ( V_180 -> V_237 + 2 ) ;
}
F_26 ( L_55 ) ;
return V_381 ;
}
void F_117 ( struct V_4 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
switch ( V_122 -> V_382 ) {
case V_363 :
V_122 -> V_383 = 1 ;
V_122 -> V_384 = 0 ;
break;
case V_365 :
V_122 -> V_383 = 0 ;
V_122 -> V_384 = 1 ;
F_17 ( V_49 , ( ~ V_385 ) , false ) ;
break;
case V_370 :
F_17 ( V_49 , ( ~ V_385 ) , false ) ;
break;
default:
V_122 -> V_383 = 0 ;
V_122 -> V_384 = 1 ;
break;
}
}
void F_118 ( struct V_4 * V_68 , T_4 V_386 )
{
struct V_50 * V_51 = & V_68 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
bool V_387 ;
{
if ( V_386 & V_388 ) {
if ( V_122 -> V_389 != V_390 ) {
V_387 = true ;
V_122 -> V_389 = V_390 ;
F_15 ( V_68 , V_391 , ( T_1 * ) & V_387 ) ;
}
} else{
if ( V_122 -> V_389 != V_392 ) {
V_387 = false ;
V_122 -> V_389 = V_392 ;
F_15 ( V_68 , V_391 , ( T_1 * ) & V_387 ) ;
}
}
}
if ( V_386 & V_393 )
V_122 -> V_207 = V_394 ;
else {
if ( V_51 -> V_206 & ( V_22 | V_17 | V_23 | V_395 ) )
V_122 -> V_207 = V_396 ;
else if ( V_51 -> V_206 & ( V_18 ) ) {
if ( ( V_386 & V_397 ) )
V_122 -> V_207 = V_396 ;
else
V_122 -> V_207 = V_394 ;
} else
V_122 -> V_207 = V_394 ;
}
F_15 ( V_68 , V_398 , & V_122 -> V_207 ) ;
}
void F_119 ( struct V_4 * V_49 )
{
int V_2 , V_399 = 0 ;
T_2 V_400 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_116 * V_241 = & ( V_122 -> V_242 ) ;
unsigned char * V_1 = V_241 -> V_401 ;
V_2 = F_120 ( V_241 -> V_401 ) ;
if ( ( V_122 -> V_271 ) && ( V_122 -> V_252 ) )
V_122 -> V_273 = 1 ;
if ( V_51 -> V_92 > 14 ) {
if ( V_122 -> V_402 )
V_399 = V_395 ;
else if ( V_122 -> V_273 )
V_399 = V_23 ;
V_399 |= V_17 ;
} else{
if ( V_122 -> V_402 )
V_399 = V_395 ;
else if ( V_122 -> V_273 )
V_399 = V_22 ;
if ( ( F_2 ( V_1 , V_2 ) ) == true )
V_399 |= V_15 ;
else if ( ( F_1 ( V_1 , V_2 ) ) == true )
V_399 |= V_20 ;
else
V_399 |= V_18 ;
}
V_51 -> V_206 = V_399 & V_49 -> V_205 . V_12 ;
V_400 = 0x0a0a0808 ;
V_49 -> V_403 . V_404 ( V_49 , V_405 , ( T_1 * ) & V_400 ) ;
V_49 -> V_403 . V_404 ( V_49 , V_406 , ( T_1 * ) & ( V_51 -> V_206 ) ) ;
if ( V_51 -> V_206 & V_15 )
F_121 ( V_49 , V_37 ) ;
else
F_121 ( V_49 , V_41 ) ;
}
void F_122 ( struct V_5 * V_6 , T_1 V_12 )
{
if ( F_123 ( V_12 ) ) {
memcpy ( V_6 -> V_71 , V_407 , 4 ) ;
V_6 -> V_72 = 4 ;
} else{
memcpy ( V_6 -> V_71 , V_408 , 3 ) ;
V_6 -> V_72 = 3 ;
}
}
int F_124 ( struct V_4 * V_49 , T_1 * V_409 , T_7 V_410 , int V_411 )
{
unsigned int V_412 ;
struct V_179 * V_180 ;
int V_413 = 0 ;
struct V_50 * V_51 = & ( V_49 -> V_52 ) ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
V_180 = (struct V_179 * ) F_97 ( V_409 , V_414 , & V_412 , V_410 ) ;
if ( V_180 == NULL )
return V_123 ;
memcpy ( V_122 -> V_131 [ V_411 ] . V_401 , V_180 -> V_187 , V_412 ) ;
V_413 = V_412 ;
V_180 = (struct V_179 * ) F_97 ( V_409 , V_415 , & V_412 , V_410 ) ;
if ( V_180 )
memcpy ( ( V_122 -> V_131 [ V_411 ] . V_401 + V_413 ) , V_180 -> V_187 , V_412 ) ;
return V_332 ;
}
void F_125 ( struct V_4 * V_49 , T_1 * V_416 , T_1 * V_144 )
{
struct V_5 * V_6 ;
T_4 V_417 , V_418 , V_419 ;
struct V_420 * V_421 ;
struct V_243 * V_244 = & V_49 -> V_245 ;
struct V_422 * V_423 = (struct V_422 * ) V_416 ;
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
V_6 = F_78 ( V_244 , V_144 ) ;
if ( V_6 ) {
V_418 = F_43 ( V_423 -> V_424 ) >> 4 ;
V_419 = F_43 ( V_423 -> V_425 ) ;
V_417 = ( V_419 >> 2 ) & 0x0f ;
V_421 = & V_6 -> V_426 [ V_417 ] ;
#ifdef F_126
V_421 -> V_427 = V_418 ;
#ifdef F_127
F_26 ( L_56 , V_114 , __LINE__ ,
V_421 -> V_427 , V_418 ) ;
#endif
#else
V_421 -> V_427 = 0xffff ;
#endif
V_421 -> V_76 = ( V_122 -> V_428 == true ) ? true : false ;
}
}
void F_128 ( struct V_50 * V_51 , T_1 * V_284 , T_7 V_56 )
{
T_1 * V_180 ;
T_8 * V_297 ;
V_180 = V_284 + sizeof( struct V_307 ) ;
V_297 = ( T_8 * ) V_180 ;
V_51 -> V_429 = F_129 ( * ( V_297 + 1 ) ) ;
V_51 -> V_429 = V_51 -> V_429 << 32 ;
V_51 -> V_429 |= F_129 ( * V_297 ) ;
}
void F_130 ( struct V_4 * V_49 , struct V_50 * V_51 )
{
F_15 ( V_49 , V_430 , NULL ) ;
}
void F_131 ( struct V_50 * V_51 , T_1 * V_284 , T_7 V_56 )
{
int V_3 ;
T_1 * V_180 ;
T_8 * V_297 ;
T_9 V_431 = 0 ;
T_2 V_432 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
V_51 -> V_433 ++ ;
V_180 = V_284 + sizeof( struct V_307 ) ;
V_297 = ( T_8 * ) V_180 ;
V_431 = F_129 ( * ( V_297 + 1 ) ) ;
V_431 = V_431 << 32 ;
V_431 |= F_129 ( * V_297 ) ;
V_432 = F_132 ( V_431 , ( V_122 -> V_133 * 1024 ) ) ;
V_432 = V_432 / 1000 ;
if ( V_432 >= 8 )
V_51 -> V_434 [ 8 ] ++ ;
else
V_51 -> V_434 [ V_432 ] ++ ;
if ( V_51 -> V_433 > 100 && ( V_51 -> V_435 == true ) ) {
T_1 V_436 , V_437 ;
T_1 V_438 , V_439 ;
V_436 = 0 ;
V_437 = 0 ;
V_438 = 0xff ;
V_439 = 0xff ;
F_26 ( L_57 , V_114 , V_51 -> V_433 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ ) {
V_51 -> V_440 [ V_3 ] = ( V_51 -> V_434 [ V_3 ] * 100 ) / V_51 -> V_433 ;
F_26 ( L_58 , V_114 , V_3 ,
V_51 -> V_434 [ V_3 ] , V_3 , V_51 -> V_440 [ V_3 ] ) ;
V_436 += V_51 -> V_440 [ V_3 ] ;
V_437 += V_51 -> V_440 [ V_3 ] ;
if ( V_436 > 20 && V_438 == 0xff ) {
V_438 = V_3 ;
F_26 ( L_59 , V_114 , V_438 ) ;
}
if ( V_437 > 80 && V_439 == 0xff ) {
V_439 = V_3 ;
F_26 ( L_60 , V_114 , V_439 ) ;
}
V_51 -> V_434 [ V_3 ] = 0 ;
V_51 -> V_440 [ V_3 ] = 0 ;
}
V_51 -> V_438 = V_438 ;
V_51 -> V_439 = V_439 ;
V_51 -> V_433 = 0 ;
}
}
void F_133 ( struct V_4 * V_49 )
{
F_134 ( V_49 ) ;
}
void F_135 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
int V_3 ;
T_1 V_441 [ V_163 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_84 * V_442 = F_21 ( V_49 ) ;
if ( ! memcmp ( V_6 -> V_174 , V_441 , V_163 ) )
return;
if ( ! memcmp ( V_6 -> V_174 , F_136 ( & V_49 -> V_443 ) , V_163 ) ) {
V_6 -> V_176 = V_130 ;
return;
}
F_49 ( & V_442 -> V_139 ) ;
for ( V_3 = 0 ; V_3 < V_130 ; V_3 ++ ) {
if ( V_442 -> V_444 [ V_3 ] == false ) {
V_442 -> V_444 [ V_3 ] = true ;
break;
}
}
F_50 ( & V_442 -> V_139 ) ;
if ( V_3 > ( V_130 - 1 ) ) {
V_6 -> V_176 = V_130 ;
F_26 ( L_61 ) ;
} else{
V_6 -> V_176 = V_3 ;
F_26 ( L_62 , V_114 , V_6 -> V_176 ) ;
}
}
void F_137 ( struct V_4 * V_49 , struct V_5 * V_6 )
{
T_1 V_441 [ V_163 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_84 * V_442 = F_21 ( V_49 ) ;
if ( ! memcmp ( V_6 -> V_174 , V_441 , V_163 ) )
return;
if ( ! memcmp ( V_6 -> V_174 , F_136 ( & V_49 -> V_443 ) , V_163 ) )
return;
F_49 ( & V_442 -> V_139 ) ;
if ( V_6 -> V_176 < V_130 && V_6 -> V_176 != 1 ) {
if ( V_442 -> V_444 [ V_6 -> V_176 ] == true ) {
F_26 ( L_62 , V_114 , V_6 -> V_176 ) ;
V_442 -> V_444 [ V_6 -> V_176 ] = false ;
V_6 -> V_176 = V_130 ;
}
}
F_50 ( & V_442 -> V_139 ) ;
}
T_1 F_138 ( struct V_4 * V_49 )
{
T_1 V_445 = 0 ;
struct V_84 * V_442 = F_21 ( V_49 ) ;
int V_3 ;
F_49 ( & V_442 -> V_139 ) ;
for ( V_3 = ( V_130 - 1 ) ; V_3 >= 0 ; V_3 -- ) {
if ( V_442 -> V_444 [ V_3 ] == true )
break;
}
V_445 = V_3 ;
F_50 ( & V_442 -> V_139 ) ;
return V_445 ;
}
struct V_4 * F_139 ( struct V_84 * V_85 )
{
if ( F_140 ( V_85 -> V_90 [ V_3 ] ) != V_446 )
return NULL ;
return V_85 -> V_90 ;
}
int F_141 ( struct V_447 * V_448 , int V_449 )
{
T_1 V_450 ;
T_1 V_451 ;
struct V_4 * V_4 = (struct V_4 * ) F_142 ( V_448 ) ;
struct V_452 * V_453 = F_143 ( V_4 ) ;
F_144 ( V_4 , V_454 ) ;
F_26 ( L_63 , V_453 -> V_455 ) ;
F_145 ( V_4 ) ;
V_451 = ( F_146 ( V_4 , V_456 + 2 ) & F_63 ( V_449 ) ) >> V_449 ;
if ( V_451 )
V_450 = ( F_146 ( V_4 , V_456 + 1 ) & F_63 ( V_449 ) ) >> V_449 ;
else
V_450 = ( F_146 ( V_4 , V_456 ) & F_63 ( V_449 ) ) >> V_449 ;
F_147 ( V_4 , V_454 ) ;
F_26 ( L_64 , V_114 , V_451 , V_450 ) ;
return V_450 ;
}
int F_148 ( struct V_447 * V_448 , int V_449 , bool V_457 )
{
T_1 V_451 = 0 ;
T_1 V_458 = - 1 ;
struct V_4 * V_4 = (struct V_4 * ) F_142 ( V_448 ) ;
if ( V_449 > 7 || V_449 < 4 ) {
F_26 ( L_65 , V_114 ) ;
return - 1 ;
}
F_144 ( V_4 , V_454 ) ;
F_145 ( V_4 ) ;
V_451 = ( F_146 ( V_4 , V_456 + 2 ) & F_63 ( V_449 ) ) >> V_449 ;
if ( V_451 ) {
if ( V_457 )
F_149 ( V_4 , V_456 + 1 , F_146 ( V_4 , V_456 + 1 ) | F_63 ( V_449 ) ) ;
else
F_149 ( V_4 , V_456 + 1 , F_146 ( V_4 , V_456 + 1 ) & ~ F_63 ( V_449 ) ) ;
F_26 ( L_66 , V_114 , V_456 + 1 , V_449 , V_457 ) ;
V_458 = 0 ;
} else{
F_26 ( L_67 , V_114 ) ;
V_458 = - 1 ;
}
F_147 ( V_4 , V_454 ) ;
return V_458 ;
}
int F_150 ( struct V_447 * V_448 , int V_449 , bool V_459 )
{
struct V_4 * V_4 = (struct V_4 * ) F_142 ( V_448 ) ;
if ( V_449 > 7 || V_449 < 4 ) {
F_26 ( L_65 , V_114 ) ;
return - 1 ;
}
F_26 ( L_68 , V_114 , V_449 , V_459 ) ;
F_144 ( V_4 , V_454 ) ;
F_145 ( V_4 ) ;
if ( V_459 )
F_149 ( V_4 , V_456 + 2 , F_146 ( V_4 , V_456 + 2 ) | F_63 ( V_449 ) ) ;
else
F_149 ( V_4 , V_456 + 2 , F_146 ( V_4 , V_456 + 2 ) & ~ F_63 ( V_449 ) ) ;
F_147 ( V_4 , V_454 ) ;
return 0 ;
}
void F_151 ( struct V_4 * V_49 , T_1 * V_460 )
{
struct V_50 * V_51 = & V_49 -> V_52 ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_461 * V_462 = V_49 -> V_463 -> V_464 ;
T_1 V_465 [ 4 ] ;
if ( ( V_122 -> V_125 & V_466 ) ||
V_122 -> V_125 & V_171 ) {
if ( V_462 != NULL ) {
struct V_467 * V_468 = V_462 -> V_469 ;
if ( V_468 != NULL ) {
V_465 [ 0 ] = V_468 -> V_470 & 0xFF ;
V_465 [ 1 ] = ( V_468 -> V_470 >> 8 ) & 0xFF ;
V_465 [ 2 ] = ( V_468 -> V_470 >> 16 ) & 0xFF ;
V_465 [ 3 ] = V_468 -> V_470 >> 24 ;
F_26 ( L_69 , V_114 ,
V_465 [ 0 ] , V_465 [ 1 ] , V_465 [ 2 ] , V_465 [ 3 ] ) ;
memcpy ( V_460 , V_465 , 4 ) ;
}
}
}
}
void F_152 ( struct V_4 * V_49 , T_1 * V_471 , T_1 * V_472 )
{
struct V_5 * V_6 ;
struct V_473 * V_474 = & V_49 -> V_475 ;
memset ( V_471 , 0 , 8 ) ;
if ( NULL == V_472 )
return;
V_6 = F_78 ( & V_49 -> V_245 , V_472 ) ;
F_26 ( L_70 ,
V_114 , V_472 [ 0 ] , V_472 [ 1 ] , V_472 [ 2 ] ,
V_472 [ 3 ] , V_472 [ 4 ] , V_472 [ 5 ] ) ;
if ( V_6 ) {
if ( V_474 -> V_476 != V_477 && V_6 -> V_478 . V_36 > 0 )
V_6 -> V_478 . V_36 -- ;
F_153 ( V_471 , V_6 -> V_478 , 0 ) ;
F_26 ( L_71
, V_114 , V_471 [ 0 ] , V_471 [ 1 ] ,
V_471 [ 2 ] , V_471 [ 3 ] , V_471 [ 4 ] ,
V_471 [ 5 ] , V_471 [ 6 ] , V_471 [ 7 ] ) ;
}
}
void F_154 ( struct V_4 * V_49 )
{
struct V_5 * V_6 ;
struct V_50 * V_51 = & ( V_49 -> V_52 ) ;
struct V_121 * V_122 = & ( V_51 -> V_124 ) ;
struct V_452 * V_453 = F_143 ( V_49 ) ;
struct V_473 * V_474 = & V_49 -> V_475 ;
V_6 = F_78 ( & V_49 -> V_245 ,
F_40 ( & V_122 -> V_242 ) ) ;
if ( V_6 ) {
if ( V_453 -> V_479 > V_6 -> V_478 . V_36 ) {
if ( V_474 -> V_476 != V_477 )
V_6 -> V_478 . V_36 = V_453 -> V_479 + 2 ;
} else {
F_26 ( L_72 , V_114 ) ;
V_6 -> V_478 . V_36 += 2 ;
}
F_26 ( L_73 , V_114 , V_6 -> V_478 . V_36 ) ;
}
}
