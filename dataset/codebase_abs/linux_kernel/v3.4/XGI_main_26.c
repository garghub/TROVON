static void F_1 ( void )
{
T_1 V_1 , V_2 ;
F_2 ( V_3 , 0x05 , 0x86 ) ;
for ( V_1 = 0 ; V_1 < 0x4f ; V_1 ++ ) {
V_2 = F_3 ( V_3 , V_1 ) ;
F_4 ( L_1 , V_1 ) ;
F_4 ( L_2 , V_2 ) ;
}
for ( V_1 = 0 ; V_1 < 0xF0 ; V_1 ++ ) {
V_2 = F_3 ( V_4 , V_1 ) ;
F_4 ( L_3 , V_1 ) ;
F_4 ( L_4 , V_2 ) ;
}
}
static inline void F_1 ( void )
{
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char V_9 , unsigned char V_10 )
{
unsigned short V_11 = V_9 ;
unsigned short V_12 = 0 , V_13 = 0 ;
unsigned short V_14 = 0 ;
int Clock ;
F_6 ( V_8 -> V_15 , V_6 ) ;
V_14 = F_7 ( V_8 , V_11 ,
V_12 , V_6 ) ;
V_13 = V_6 -> V_16 [ V_14 ] . V_17 ;
Clock = V_6 -> V_18 [ V_13 ] . CLOCK * 1000 ;
return Clock ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char V_9 , unsigned char V_10 ,
T_2 * V_19 , T_2 * V_20 , T_2 * V_21 ,
T_2 * V_22 , T_2 * V_23 , T_2 * V_24 , T_2 * V_25 ,
T_2 * V_26 )
{
unsigned short V_11 = V_9 ;
unsigned short V_12 = 0 , V_27 = 0 ;
unsigned short V_14 = 0 ;
unsigned short V_28 , V_29 , V_30 , V_31 , V_32 , V_33 ;
unsigned short V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
unsigned char V_40 , V_41 , V_42 ;
unsigned long V_43 ;
int V_44 , V_45 , V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ;
F_6 ( V_8 -> V_15 , V_6 ) ;
V_14 = F_7 ( V_8 , V_11 ,
V_12 , V_6 ) ;
V_27 = V_6 -> V_16 [ V_14 ] . V_52 ;
V_40 = V_6 -> V_53 [ V_27 ] . V_54 [ 5 ] ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 0 ] ;
V_39 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_40 & 0x03 ) << 8 ) ;
V_44 = V_39 + 5 ;
V_38 = ( V_6 -> V_16 [ V_14 ] . V_55 >> 3 ) - 1 ;
V_48 = V_38 + 1 ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 3 ] ;
V_36 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_40 & 0xC0 ) << 2 ) ;
V_49 = V_36 - V_48 - 3 ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 1 ] ;
V_37 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_40 & 0x30 ) << 4 ) ;
V_40 = V_6 -> V_53 [ V_27 ] . V_54 [ 6 ] ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 2 ] ;
V_42 = V_6 -> V_53 [ V_27 ] . V_54 [ 4 ] ;
V_35 = ( V_41 & 0x1f ) | ( ( unsigned short ) ( V_42 & 0x80 ) >> 2 )
| ( ( unsigned short ) ( V_40 & 0x03 ) << 6 ) ;
V_34 = ( V_42 & 0x1f ) | ( ( V_40 & 0x04 ) << 3 ) ;
V_50 = V_35 - ( ( V_48 - 1 ) & 255 ) ;
V_45 = ( V_50 > 0 ) ? V_50 : ( V_50 + 256 ) ;
V_50 = V_34 - ( ( V_48 + V_49 + 3 ) & 63 ) ;
V_46 = ( V_50 > 0 ) ? V_50 : ( V_50 + 64 ) ;
V_47 = V_45 - V_49 - V_46 ;
* V_19 = V_47 * 8 ;
* V_20 = V_49 * 8 ;
* V_23 = V_46 * 8 ;
V_40 = V_6 -> V_53 [ V_27 ] . V_54 [ 14 ] ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 8 ] ;
V_42 = V_6 -> V_53 [ V_27 ] . V_54 [ 9 ] ;
V_33 = ( V_41 & 0xFF ) | ( ( unsigned short ) ( V_42 & 0x01 ) << 8 )
| ( ( unsigned short ) ( V_42 & 0x20 ) << 4 )
| ( ( unsigned short ) ( V_40 & 0x01 ) << 10 ) ;
V_44 = V_33 + 2 ;
V_32 = V_6 -> V_16 [ V_14 ] . V_56 - 1 ;
V_48 = V_32 + 1 ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 10 ] ;
V_30 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_42 & 0x04 ) << 6 )
| ( ( unsigned short ) ( V_42 & 0x80 ) << 2 )
| ( ( unsigned short ) ( V_40 & 0x08 ) << 7 ) ;
V_49 = V_30 + 1 - V_48 ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 12 ] ;
V_43 = ( V_6 -> V_53 [ V_27 ] . V_54 [ 14 ] & 0x80 ) << 5 ;
V_31 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_42 & 0x08 ) << 5 )
| ( ( unsigned short ) ( V_43 & 0x20 ) << 4 )
| ( ( unsigned short ) ( V_40 & 0x04 ) << 8 ) ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 13 ] ;
V_29 = ( V_41 & 0xff ) | ( ( unsigned short ) ( V_40 & 0x10 ) << 4 ) ;
V_50 = V_29 - ( ( V_48 - 1 ) & 511 ) ;
V_45 = ( V_50 > 0 ) ? V_50 : ( V_50 + 512 ) ;
V_41 = V_6 -> V_53 [ V_27 ] . V_54 [ 11 ] ;
V_28 = ( V_41 & 0x0f ) | ( ( V_40 & 0x20 ) >> 1 ) ;
V_50 = V_28 - ( ( V_48 + V_49 - 1 ) & 31 ) ;
V_46 = ( V_50 > 0 ) ? V_50 : ( V_50 + 32 ) ;
V_47 = V_45 - V_49 - V_46 ;
* V_21 = V_47 ;
* V_22 = V_49 ;
* V_24 = V_46 ;
if ( V_6 -> V_16 [ V_14 ] . V_57 & 0x8000 )
* V_25 &= ~ V_58 ;
else
* V_25 |= V_58 ;
if ( V_6 -> V_16 [ V_14 ] . V_57 & 0x4000 )
* V_25 &= ~ V_59 ;
else
* V_25 |= V_59 ;
* V_26 = V_60 ;
if ( V_6 -> V_16 [ V_14 ] . V_57 & 0x0080 )
* V_26 = V_61 ;
else {
V_51 = 0 ;
while ( V_6 -> V_62 [ V_51 ] . V_63 != 0xff ) {
if ( V_6 -> V_62 [ V_51 ] . V_63 ==
V_6 -> V_16 [ V_14 ] . V_64 ) {
if ( V_6 -> V_62 [ V_51 ] . V_65 &
V_66 ) {
* V_26 = V_67 ;
}
break;
}
V_51 ++ ;
}
}
return 1 ;
}
static void F_9 ( struct V_5 * V_6 , unsigned long V_68 )
{
V_6 -> V_69 = V_68 ;
V_6 -> V_70 = V_68 + 0x14 ;
V_6 -> V_71 = V_68 + 0x24 ;
V_6 -> V_72 = V_68 + 0x10 ;
V_6 -> V_73 = V_68 + 0x1e ;
V_6 -> V_74 = V_68 + 0x12 ;
V_6 -> V_75 = V_68 + 0x1a ;
V_6 -> V_76 = V_68 + 0x16 ;
V_6 -> V_77 = V_68 + 0x17 ;
V_6 -> V_78 = V_68 + 0x18 ;
V_6 -> V_79 = V_68 + 0x19 ;
V_6 -> V_80 = V_68 + 0x2A ;
V_6 -> V_81 = V_68 + V_82 ;
V_6 -> V_83 = V_68 + V_84 ;
V_6 -> V_85 = V_68 + V_86 ;
V_6 -> V_87 = V_68 + V_88 ;
V_6 -> V_89 = V_68 + V_88 + 2 ;
}
static int F_10 ( struct V_90 * V_91 )
{
int V_92 = 0 ;
int V_93 = 0 ;
V_92 = 0 ;
while ( ( V_94 [ V_93 ] . V_95 != 0 )
&& ( V_94 [ V_93 ] . V_96
<= V_91 -> V_97 . V_98 ) ) {
if ( ( V_94 [ V_93 ] . V_96
== V_91 -> V_97 . V_98 )
&& ( V_94 [ V_93 ] . V_99
== V_91 -> V_97 . V_100 )
&& ( V_94 [ V_93 ] . V_101 == 8 ) ) {
V_92 = 1 ;
break;
}
V_93 ++ ;
}
if ( ! V_92 )
V_93 = - 1 ;
return V_93 ;
}
static void F_11 ( struct V_90 * V_91 ,
const char * V_102 )
{
int V_1 = 0 , V_51 = 0 , V_103 ;
while ( V_94 [ V_1 ] . V_95 != 0 ) {
V_103 = F_12 ( strlen ( V_102 ) , strlen ( V_94 [ V_1 ] . V_102 ) ) ;
if ( ! strncmp ( V_102 , V_94 [ V_1 ] . V_102 , V_103 ) ) {
V_91 -> V_104 = V_1 ;
V_51 = 1 ;
break;
}
V_1 ++ ;
}
if ( ! V_51 )
F_13 ( L_5 , V_102 ) ;
}
static void F_14 ( struct V_90 * V_91 ,
unsigned int V_105 )
{
int V_1 = 0 , V_51 = 0 ;
if ( V_105 == 0 )
goto V_106;
V_105 &= 0x1dff ;
while ( V_94 [ V_1 ] . V_95 != 0 ) {
if ( ( V_94 [ V_1 ] . V_107 == V_105 ) ||
( V_94 [ V_1 ] . V_108 == V_105 ) ) {
V_91 -> V_104 = V_1 ;
V_51 = 1 ;
break;
}
V_1 ++ ;
}
V_106:
if ( ! V_51 )
F_13 ( L_6 , V_105 ) ;
}
static int F_15 ( struct V_90 * V_91 , int V_109 )
{
T_3 V_96 , V_99 ;
struct V_7 * V_110 = & V_91 -> V_110 ;
if ( V_91 -> V_111 == V_112 ) {
if ( V_91 -> V_113 == V_114 ) {
V_96 = V_91 -> V_97 . V_98 ;
V_99 = V_91 -> V_97 . V_100 ;
if ( V_94 [ V_109 ] . V_96 > V_96 )
return - 1 ;
if ( V_94 [ V_109 ] . V_99 > V_99 )
return - 1 ;
if ( ( V_94 [ V_109 ] . V_96 < V_96 ) &&
( V_94 [ V_109 ] . V_99 < V_99 ) ) {
if ( V_94 [ V_109 ] . V_101 > 8 )
return - 1 ;
}
}
return V_109 ;
}
if ( V_91 -> V_111 == V_115 )
return V_109 ;
if ( ! ( V_94 [ V_109 ] . V_116 & V_117 ) )
return - 1 ;
switch ( V_91 -> V_113 ) {
case V_114 :
switch ( V_110 -> V_118 ) {
case V_119 :
V_96 = 640 ;
V_99 = 480 ;
break;
case V_120 :
V_96 = 800 ;
V_99 = 600 ;
break;
case V_121 :
V_96 = 1024 ;
V_99 = 600 ;
break;
case V_122 :
V_96 = 1024 ;
V_99 = 768 ;
break;
case V_123 :
V_96 = 1152 ;
V_99 = 768 ;
break;
case V_124 :
V_96 = 1280 ;
V_99 = 960 ;
break;
case V_125 :
V_96 = 1280 ;
V_99 = 768 ;
break;
case V_126 :
V_96 = 1280 ;
V_99 = 1024 ;
break;
case V_127 :
V_96 = 1400 ;
V_99 = 1050 ;
break;
case V_128 :
V_96 = 1600 ;
V_99 = 1200 ;
break;
default:
V_96 = 0 ;
V_99 = 0 ;
break;
}
if ( V_94 [ V_109 ] . V_96 > V_96 )
return - 1 ;
if ( V_94 [ V_109 ] . V_99 > V_99 )
return - 1 ;
if ( ( V_110 -> V_129 == 0x01 ) ||
( V_110 -> V_129 == 0x05 ) ) {
switch ( V_94 [ V_109 ] . V_96 ) {
case 512 :
if ( V_94 [ V_109 ] . V_99 != 512 )
return - 1 ;
if ( V_110 -> V_118 == V_121 )
return - 1 ;
break;
case 640 :
if ( ( V_94 [ V_109 ] . V_99 != 400 )
&& ( V_94 [ V_109 ] . V_99
!= 480 ) )
return - 1 ;
break;
case 800 :
if ( V_94 [ V_109 ] . V_99 != 600 )
return - 1 ;
break;
case 1024 :
if ( ( V_94 [ V_109 ] . V_99 != 600 ) &&
( V_94 [ V_109 ] . V_99 != 768 ) )
return - 1 ;
if ( ( V_94 [ V_109 ] . V_99 == 600 ) &&
( V_110 -> V_118 != V_121 ) )
return - 1 ;
break;
case 1152 :
if ( ( V_94 [ V_109 ] . V_99 ) != 768 )
return - 1 ;
if ( V_110 -> V_118 != V_123 )
return - 1 ;
break;
case 1280 :
if ( ( V_94 [ V_109 ] . V_99 != 768 ) &&
( V_94 [ V_109 ] . V_99 != 1024 ) )
return - 1 ;
if ( ( V_94 [ V_109 ] . V_99 == 768 ) &&
( V_110 -> V_118 != V_125 ) )
return - 1 ;
break;
case 1400 :
if ( V_94 [ V_109 ] . V_99 != 1050 )
return - 1 ;
break;
case 1600 :
if ( V_94 [ V_109 ] . V_99 != 1200 )
return - 1 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_94 [ V_109 ] . V_96 ) {
case 512 :
if ( V_94 [ V_109 ] . V_99 != 512 )
return - 1 ;
break;
case 640 :
if ( ( V_94 [ V_109 ] . V_99 != 400 ) &&
( V_94 [ V_109 ] . V_99 != 480 ) )
return - 1 ;
break;
case 800 :
if ( V_94 [ V_109 ] . V_99 != 600 )
return - 1 ;
break;
case 1024 :
if ( V_94 [ V_109 ] . V_99 != 768 )
return - 1 ;
break;
case 1280 :
if ( ( V_94 [ V_109 ] . V_99 != 960 ) &&
( V_94 [ V_109 ] . V_99 != 1024 ) )
return - 1 ;
if ( V_94 [ V_109 ] . V_99 == 960 ) {
if ( V_110 -> V_118 ==
V_127 )
return - 1 ;
}
break;
case 1400 :
if ( V_94 [ V_109 ] . V_99 != 1050 )
return - 1 ;
break;
case 1600 :
if ( V_94 [ V_109 ] . V_99 != 1200 )
return - 1 ;
break;
default:
return - 1 ;
}
}
break;
case V_130 :
switch ( V_94 [ V_109 ] . V_96 ) {
case 512 :
case 640 :
case 800 :
break;
case 720 :
if ( V_91 -> V_131 == V_132 ) {
if ( V_94 [ V_109 ] . V_99 != 480 )
return - 1 ;
} else if ( V_91 -> V_131 == V_133 ) {
if ( V_94 [ V_109 ] . V_99 != 576 )
return - 1 ;
}
if ( V_91 -> V_134 == V_135 ||
V_91 -> V_134 == V_136 ) {
return - 1 ;
}
break;
case 1024 :
if ( V_91 -> V_131 == V_132 ) {
if ( V_94 [ V_109 ] . V_101 == 32 )
return - 1 ;
}
break;
default:
return - 1 ;
}
break;
case V_137 :
if ( V_94 [ V_109 ] . V_96 > 1280 )
return - 1 ;
break;
case V_138 :
break;
}
return V_109 ;
}
static void F_16 ( const char * V_102 )
{
int V_1 = 0 ;
if ( V_102 == NULL )
return;
while ( V_139 [ V_1 ] . V_140 != - 1 ) {
if ( ! strcmp ( V_102 , V_139 [ V_1 ] . V_102 ) ) {
V_141 = V_139 [ V_1 ] . V_140 ;
V_142 = V_139 [ V_1 ] . V_143 ;
break;
}
V_1 ++ ;
}
if ( V_141 < 0 )
F_13 ( L_7 , V_102 ) ;
}
static T_1 F_17 ( struct V_90 * V_91 ,
unsigned int V_144 )
{
T_3 V_96 , V_99 ;
int V_1 = 0 ;
V_96 = V_94 [ V_91 -> V_104 ] . V_96 ;
V_99 = V_94 [ V_91 -> V_104 ] . V_99 ;
V_91 -> V_145 = 0 ;
while ( ( V_146 [ V_1 ] . V_147 != 0 ) && ( V_146 [ V_1 ] . V_96 <= V_96 ) ) {
if ( ( V_146 [ V_1 ] . V_96 == V_96 ) &&
( V_146 [ V_1 ] . V_99 == V_99 ) ) {
if ( V_146 [ V_1 ] . V_148 == V_144 ) {
V_91 -> V_145 = V_146 [ V_1 ] . V_147 ;
break;
} else if ( V_146 [ V_1 ] . V_148 > V_144 ) {
if ( ( V_146 [ V_1 ] . V_148 - V_144 ) <= 3 ) {
F_18 ( L_8 ,
V_144 , V_146 [ V_1 ] . V_148 ) ;
V_91 -> V_145 =
V_146 [ V_1 ] . V_147 ;
V_91 -> V_149 =
V_146 [ V_1 ] . V_148 ;
} else if ( ( ( V_144 - V_146 [ V_1 - 1 ] . V_148 )
<= 2 ) && ( V_146 [ V_1 ] . V_147
!= 1 ) ) {
F_18 ( L_9 ,
V_144 , V_146 [ V_1 - 1 ] . V_148 ) ;
V_91 -> V_145 =
V_146 [ V_1 - 1 ] . V_147 ;
V_91 -> V_149 =
V_146 [ V_1 - 1 ] . V_148 ;
}
break;
} else if ( ( V_144 - V_146 [ V_1 ] . V_148 ) <= 2 ) {
F_18 ( L_9 ,
V_144 , V_146 [ V_1 ] . V_148 ) ;
V_91 -> V_145 = V_146 [ V_1 ] . V_147 ;
break;
}
}
V_1 ++ ;
}
if ( V_91 -> V_145 > 0 ) {
return V_91 -> V_145 ;
} else {
F_13 ( L_10 ,
V_144 , V_96 , V_99 ) ;
return 0 ;
}
}
static void F_19 ( const char * V_102 )
{
int V_1 = 0 ;
if ( V_102 == NULL )
return;
while ( V_150 [ V_1 ] . V_140 != - 1 ) {
if ( ! strcmp ( V_102 , V_150 [ V_1 ] . V_102 ) ) {
V_151 = V_150 [ V_1 ] . V_140 ;
break;
}
V_1 ++ ;
}
}
static void F_20 ( struct V_90 * V_91 ,
struct V_152 * V_153 )
{
switch ( V_153 -> V_154 ) {
case 8 :
V_153 -> V_155 . V_156 = V_153 -> V_157 . V_156 = V_153 -> V_158 . V_156 = 0 ;
V_153 -> V_155 . V_159 = V_153 -> V_157 . V_159 = V_153 -> V_158 . V_159 = 6 ;
V_91 -> V_160 = 256 ;
break;
case 16 :
V_153 -> V_155 . V_156 = 11 ;
V_153 -> V_155 . V_159 = 5 ;
V_153 -> V_157 . V_156 = 5 ;
V_153 -> V_157 . V_159 = 6 ;
V_153 -> V_158 . V_156 = 0 ;
V_153 -> V_158 . V_159 = 5 ;
V_153 -> V_161 . V_156 = 0 ;
V_153 -> V_161 . V_159 = 0 ;
V_91 -> V_160 = 16 ;
break;
case 32 :
V_153 -> V_155 . V_156 = 16 ;
V_153 -> V_155 . V_159 = 8 ;
V_153 -> V_157 . V_156 = 8 ;
V_153 -> V_157 . V_159 = 8 ;
V_153 -> V_158 . V_156 = 0 ;
V_153 -> V_158 . V_159 = 8 ;
V_153 -> V_161 . V_156 = 24 ;
V_153 -> V_161 . V_159 = 8 ;
V_91 -> V_160 = 16 ;
break;
}
}
static void F_21 ( struct V_90 * V_91 )
{
T_1 V_162 = 0 , V_163 = 0 ;
V_163 = F_3 ( V_4 , 0x31 ) ;
V_163 &= ~ 0x60 ;
switch ( V_91 -> V_113 ) {
case V_137 :
V_162 = ( V_164 | V_165 ) ;
V_163 |= V_166 ;
break;
case V_114 :
V_162 = ( V_167 | V_165 ) ;
V_163 |= V_166 ;
break;
case V_130 :
if ( V_91 -> V_131 == V_168 )
V_162 = ( V_169
| V_165 ) ;
else if ( V_91 -> V_170 == V_171 )
V_162 = ( V_172
| V_165 ) ;
else if ( V_91 -> V_170 == V_173 )
V_162 = ( V_174
| V_165 ) ;
else if ( V_91 -> V_170 == V_175 )
V_162 = ( V_176
| V_165 ) ;
V_163 |= V_166 ;
if ( V_151 == 1 || V_91 -> V_131 == V_133 )
V_163 |= 0x01 ;
else
V_163 &= ~ 0x01 ;
break;
default:
V_162 = 0x00 ;
V_163 |= ( V_166 | V_177 ) ;
}
F_2 ( V_4 , V_178 , V_162 ) ;
F_2 ( V_4 , V_179 , V_163 ) ;
F_2 ( V_4 , V_180 ,
( V_91 -> V_145 & 0x0F ) ) ;
}
static void F_22 ( struct V_90 * V_91 )
{
T_1 V_2 ;
unsigned char V_181 = 1 ;
if ( V_91 -> V_182 == 8 ) {
if ( ( V_91 -> V_134 == V_183 ) ||
( V_91 -> V_134 == V_135 ) ) {
V_181 = 0 ;
}
if ( V_91 -> V_113 == V_114 )
V_181 = 0 ;
}
if ( V_91 -> V_134 != V_184 ) {
V_2 = F_3 ( V_185 , 0x00 ) ;
if ( ( V_2 & 0x50 ) == 0x10 )
V_181 = 0 ;
} else {
V_186 = 0 ;
}
V_2 = F_3 ( V_4 , 0x17 ) ;
if ( ( V_186 ) && ( V_181 ) )
V_2 &= ~ 0x80 ;
else
V_2 |= 0x80 ;
F_2 ( V_4 , 0x17 , V_2 ) ;
F_23 ( V_3 , V_187 , ~ 0x04 ) ;
if ( V_91 -> V_113 == V_130 &&
V_91 -> V_134 == V_188 ) {
V_2 = F_3 ( V_189 , 0x01 ) ;
if ( V_2 < 0xB0 ) {
int V_190 ;
switch ( V_91 -> V_191 ) {
case 320 :
V_190 = ( V_91 -> V_131 ==
V_132 ) ? 4 : 12 ;
break;
case 640 :
V_190 = ( V_91 -> V_131 ==
V_132 ) ? 5 : 13 ;
break;
case 720 :
V_190 = ( V_91 -> V_131 ==
V_132 ) ? 6 : 14 ;
break;
case 800 :
V_190 = ( V_91 -> V_131 ==
V_132 ) ? 7 : 15 ;
break;
default:
V_190 = 0 ;
V_192 = - 1 ;
break;
}
F_24 ( V_185 ,
V_193 ,
0x01 ) ;
if ( V_91 -> V_131 == V_132 ) {
F_23 ( V_194 , 0x3a , 0x1f ) ;
if ( V_91 -> V_170 == V_171 ) {
F_23 ( V_194 , 0x30 , 0xdf ) ;
} else if ( V_91 -> V_170
== V_173 ) {
F_24 ( V_194 , 0x30 , 0x20 ) ;
switch ( V_91 -> V_191 ) {
case 640 :
F_2 ( V_194 ,
0x35 ,
0xEB ) ;
F_2 ( V_194 ,
0x36 ,
0x04 ) ;
F_2 ( V_194 ,
0x37 ,
0x25 ) ;
F_2 ( V_194 ,
0x38 ,
0x18 ) ;
break;
case 720 :
F_2 ( V_194 ,
0x35 ,
0xEE ) ;
F_2 ( V_194 ,
0x36 ,
0x0C ) ;
F_2 ( V_194 ,
0x37 ,
0x22 ) ;
F_2 ( V_194 ,
0x38 ,
0x08 ) ;
break;
case 800 :
F_2 ( V_194 ,
0x35 ,
0xEB ) ;
F_2 ( V_194 ,
0x36 ,
0x15 ) ;
F_2 ( V_194 ,
0x37 ,
0x25 ) ;
F_2 ( V_194 ,
0x38 ,
0xF6 ) ;
break;
}
}
} else if ( V_91 -> V_131 == V_133 ) {
F_23 ( V_194 , 0x3A , 0x1F ) ;
if ( V_91 -> V_170 == V_171 ) {
F_23 ( V_194 , 0x30 , 0xDF ) ;
} else if ( V_91 -> V_170
== V_173 ) {
F_24 ( V_194 , 0x30 , 0x20 ) ;
switch ( V_91 -> V_191 ) {
case 640 :
F_2 ( V_194 ,
0x35 ,
0xF1 ) ;
F_2 ( V_194 ,
0x36 ,
0xF7 ) ;
F_2 ( V_194 ,
0x37 ,
0x1F ) ;
F_2 ( V_194 ,
0x38 ,
0x32 ) ;
break;
case 720 :
F_2 ( V_194 ,
0x35 ,
0xF3 ) ;
F_2 ( V_194 ,
0x36 ,
0x00 ) ;
F_2 ( V_194 ,
0x37 ,
0x1D ) ;
F_2 ( V_194 ,
0x38 ,
0x20 ) ;
break;
case 800 :
F_2 ( V_194 ,
0x35 ,
0xFC ) ;
F_2 ( V_194 ,
0x36 ,
0xFB ) ;
F_2 ( V_194 ,
0x37 ,
0x14 ) ;
F_2 ( V_194 ,
0x38 ,
0x2A ) ;
break;
}
}
}
if ( ( V_192 >= 0 ) && ( V_192 <= 7 ) ) {
F_18 ( L_11 ,
V_190 , V_192 ,
V_195 [ V_190 ] .
V_192 [ V_192 ] [ 0 ] ,
V_195 [ V_190 ] .
V_192 [ V_192 ] [ 1 ] ,
V_195 [ V_190 ] .
V_192 [ V_192 ] [ 2 ] ,
V_195 [ V_190 ] .
V_192 [ V_192 ] [ 3 ]
) ;
F_2 (
V_194 ,
0x35 ,
( V_195 [ V_190 ] .
V_192 [ V_192 ] [ 0 ] ) ) ;
F_2 (
V_194 ,
0x36 ,
( V_195 [ V_190 ] .
V_192 [ V_192 ] [ 1 ] ) ) ;
F_2 (
V_194 ,
0x37 ,
( V_195 [ V_190 ] .
V_192 [ V_192 ] [ 2 ] ) ) ;
F_2 (
V_194 ,
0x38 ,
( V_195 [ V_190 ] .
V_192 [ V_192 ] [ 3 ] ) ) ;
}
}
}
}
static int F_25 ( struct V_152 * V_153 , int V_196 ,
struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
struct V_7 * V_110 = & V_91 -> V_110 ;
unsigned int V_200 = V_153 -> V_19 + V_153 -> V_96 + V_153 -> V_20
+ V_153 -> V_23 ;
unsigned int V_201 = V_153 -> V_21 + V_153 -> V_99 + V_153 -> V_22
+ V_153 -> V_24 ;
#if F_26 ( V_202 )
T_1 V_40 , V_41 ;
#endif
unsigned int V_203 = 0 , V_204 = 0 ;
int V_92 = 0 ;
int V_205 ;
F_27 ( L_12 ) ;
V_198 -> V_153 . V_206 = V_153 -> V_206 ;
V_198 -> V_153 . V_207 = V_153 -> V_207 ;
V_198 -> V_153 . V_154 = V_153 -> V_154 ;
if ( ( V_153 -> V_26 & V_208 ) == V_60 )
V_201 <<= 1 ;
else if ( ( V_153 -> V_26 & V_208 ) == V_67 )
V_201 <<= 2 ;
else if ( ( V_153 -> V_26 & V_208 ) == V_61 ) {
}
if ( ! V_200 || ! V_201 ) {
F_18 ( L_13 ) ;
return - V_209 ;
} F_28 ( L_14 ,
V_153 -> V_210 , V_200 , V_201 ) ;
if ( V_153 -> V_210 && V_200 && V_201 ) {
V_203 = 1000000000 / V_153 -> V_210 ;
V_204 = ( V_203 * 1000 ) / V_200 ;
V_91 -> V_149 = ( unsigned int ) ( V_204 * 2
/ V_201 ) ;
} else {
V_91 -> V_149 = 60 ;
}
F_28 ( L_15 ,
V_153 -> V_96 ,
V_153 -> V_99 ,
V_153 -> V_154 ,
V_91 -> V_149 ) ;
V_205 = V_91 -> V_104 ;
V_91 -> V_104 = 0 ;
while ( ( V_94 [ V_91 -> V_104 ] . V_95 != 0 ) &&
( V_94 [ V_91 -> V_104 ] . V_96 <= V_153 -> V_96 ) ) {
if ( ( V_94 [ V_91 -> V_104 ] . V_96 == V_153 -> V_96 ) &&
( V_94 [ V_91 -> V_104 ] . V_99 == V_153 -> V_99 ) &&
( V_94 [ V_91 -> V_104 ] . V_101
== V_153 -> V_154 ) ) {
V_92 = 1 ;
break;
}
V_91 -> V_104 ++ ;
}
if ( V_92 )
V_91 -> V_104 = F_15 ( V_91 ,
V_91 -> V_104 ) ;
else
V_91 -> V_104 = - 1 ;
if ( V_91 -> V_104 < 0 ) {
F_29 ( L_16 ,
V_153 -> V_96 , V_153 -> V_99 , V_153 -> V_154 ) ;
V_91 -> V_104 = V_205 ;
return - V_209 ;
}
if ( F_17 ( V_91 ,
V_91 -> V_149 ) == 0 ) {
V_91 -> V_145 =
V_94 [ V_91 -> V_104 ] . V_145 ;
V_91 -> V_149 = 60 ;
}
if ( V_196 ) {
F_21 ( V_91 ) ;
if ( F_30 ( V_91 , V_110 ,
V_94 [ V_91 -> V_104 ] . V_95 )
== 0 ) {
F_29 ( L_17 ,
V_94 [ V_91 -> V_104 ] . V_95 ) ;
return - V_209 ;
}
V_198 -> V_211 . V_212 = ( ( V_198 -> V_153 . V_206
* V_198 -> V_153 . V_154 ) >> 6 ) ;
F_2 ( V_3 , V_213 , V_214 ) ;
F_2 ( V_4 , 0x13 , ( V_198 -> V_211 . V_212 & 0x00ff ) ) ;
F_2 ( V_3 ,
0x0E ,
( V_198 -> V_211 . V_212 & 0xff00 ) >> 8 ) ;
F_22 ( V_91 ) ;
F_18 ( L_18 ,
V_94 [ V_91 -> V_104 ] . V_96 ,
V_94 [ V_91 -> V_104 ] . V_99 ,
V_94 [ V_91 -> V_104 ] . V_101 ,
V_91 -> V_149 ) ;
V_91 -> V_182 = V_94 [ V_91 -> V_104 ] . V_101 ;
V_91 -> V_215 = V_198 -> V_153 . V_206 ;
V_91 -> V_191 =
V_94 [ V_91 -> V_104 ] . V_96 ;
V_91 -> V_216 = V_198 -> V_153 . V_207 ;
V_91 -> V_217 =
V_94 [ V_91 -> V_104 ] . V_99 ;
V_91 -> V_218 = V_91 -> V_219 = 0 ;
V_91 -> V_220 = V_198 -> V_153 . V_206
* ( V_91 -> V_182 >> 3 ) ;
switch ( V_91 -> V_182 ) {
case 8 :
V_91 -> V_221 = 0x0000 ;
V_91 -> V_222 = 0x00000000 ;
V_91 -> V_160 = 256 ;
#if F_26 ( V_202 )
V_41 = F_3 ( V_4 , 0x4D ) ;
F_2 ( V_4 , 0x4D , ( V_41 & 0xE0 ) ) ;
#endif
break;
case 16 :
V_91 -> V_221 = 0x8000 ;
V_91 -> V_222 = 0x00010000 ;
#if F_26 ( V_202 )
V_41 = F_3 ( V_4 , 0x4D ) ;
F_2 ( V_4 , 0x4D , ( ( V_41 & 0xE0 ) | 0x0B ) ) ;
#endif
V_91 -> V_160 = 16 ;
break;
case 32 :
V_91 -> V_221 = 0xC000 ;
V_91 -> V_222 = 0x00020000 ;
V_91 -> V_160 = 16 ;
#if F_26 ( V_202 )
V_41 = F_3 ( V_4 , 0x4D ) ;
F_2 ( V_4 , 0x4D , ( ( V_41 & 0xE0 ) | 0x15 ) ) ;
#endif
break;
default:
V_91 -> V_160 = 16 ;
F_29 ( L_19 ,
V_91 -> V_182 ) ;
break;
}
}
F_20 ( V_91 , V_153 ) ;
F_27 ( L_20 ) ;
F_1 () ;
return 0 ;
}
static int F_31 ( struct V_152 * V_153 , struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
unsigned int V_223 ;
V_223 = V_153 -> V_224 * V_198 -> V_153 . V_206 + V_153 -> V_225 ;
switch ( V_198 -> V_153 . V_154 ) {
case 16 :
V_223 >>= 1 ;
break;
case 32 :
break;
case 8 :
default:
V_223 >>= 2 ;
break;
}
F_2 ( V_3 , V_213 , V_214 ) ;
F_2 ( V_4 , 0x0D , V_223 & 0xFF ) ;
F_2 ( V_4 , 0x0C , ( V_223 >> 8 ) & 0xFF ) ;
F_2 ( V_3 , 0x0D , ( V_223 >> 16 ) & 0xFF ) ;
F_2 ( V_3 , 0x37 , ( V_223 >> 24 ) & 0x03 ) ;
F_32 ( V_3 , 0x37 , 0xDF , ( V_223 >> 21 ) & 0x04 ) ;
if ( V_91 -> V_113 != V_138 ) {
F_24 ( V_185 , V_193 , 0x01 ) ;
F_2 ( V_185 , 0x06 , ( V_223 & 0xFF ) ) ;
F_2 ( V_185 , 0x05 , ( ( V_223 >> 8 ) & 0xFF ) ) ;
F_2 ( V_185 , 0x04 , ( ( V_223 >> 16 ) & 0xFF ) ) ;
F_32 ( V_185 ,
0x02 ,
0x7F ,
( ( V_223 >> 24 ) & 0x01 ) << 7 ) ;
}
return 0 ;
}
static int F_33 ( struct V_197 * V_198 , int V_226 )
{
return 0 ;
}
static int F_34 ( struct V_197 * V_198 , int V_226 )
{
return 0 ;
}
static int F_35 ( const struct V_152 * V_153 )
{
int V_227 = 16 ;
switch ( V_153 -> V_154 ) {
case 8 :
V_227 = 256 ;
break;
case 16 :
V_227 = 16 ;
break;
case 32 :
V_227 = 16 ;
break;
}
return V_227 ;
}
static int F_36 ( unsigned V_228 , unsigned V_155 , unsigned V_157 ,
unsigned V_158 , unsigned V_161 , struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
if ( V_228 >= F_35 ( & V_198 -> V_153 ) )
return 1 ;
switch ( V_198 -> V_153 . V_154 ) {
case 8 :
F_37 ( V_228 , V_229 ) ;
F_37 ( ( V_155 >> 10 ) , V_230 ) ;
F_37 ( ( V_157 >> 10 ) , V_230 ) ;
F_37 ( ( V_158 >> 10 ) , V_230 ) ;
if ( V_91 -> V_113 != V_138 ) {
F_37 ( V_228 , V_231 ) ;
F_37 ( ( V_155 >> 8 ) , V_232 ) ;
F_37 ( ( V_157 >> 8 ) , V_232 ) ;
F_37 ( ( V_158 >> 8 ) , V_232 ) ;
}
break;
case 16 :
( ( T_2 * ) ( V_198 -> V_233 ) ) [ V_228 ] = ( ( V_155 & 0xf800 ) )
| ( ( V_157 & 0xfc00 ) >> 5 ) | ( ( V_158 & 0xf800 )
>> 11 ) ;
break;
case 32 :
V_155 >>= 8 ;
V_157 >>= 8 ;
V_158 >>= 8 ;
( ( T_2 * ) ( V_198 -> V_233 ) ) [ V_228 ] = ( V_155 << 16 ) | ( V_157
<< 8 ) | ( V_158 ) ;
break;
}
return 0 ;
}
static int F_38 ( struct V_234 * V_211 , int V_235 ,
struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
F_27 ( L_21 ) ;
memset ( V_211 , 0 , sizeof( struct V_234 ) ) ;
V_211 -> V_236 = V_91 -> V_237 ;
V_211 -> V_238 = V_91 -> V_239 ;
V_211 -> type = V_240 ;
V_211 -> V_241 = 0 ;
if ( V_91 -> V_182 == 8 )
V_211 -> V_242 = V_243 ;
else
V_211 -> V_242 = V_244 ;
V_211 -> V_245 = 0 ;
if ( V_246 )
V_211 -> V_247 = 1 ;
V_211 -> V_248 = 0 ;
V_211 -> V_212 = V_91 -> V_220 ;
V_211 -> V_249 = V_91 -> V_250 ;
V_211 -> V_251 = V_91 -> V_252 ;
V_211 -> V_253 = V_254 ;
F_27 ( L_22 ) ;
return 0 ;
}
static int F_39 ( struct V_197 * V_198 )
{
int V_255 ;
V_255 = F_25 ( & V_198 -> V_153 , 1 , V_198 ) ;
if ( V_255 )
return V_255 ;
F_38 ( & V_198 -> V_211 , - 1 , V_198 ) ;
return 0 ;
}
static int F_40 ( struct V_152 * V_153 , struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
unsigned int V_200 = V_153 -> V_19 + V_153 -> V_96 + V_153 -> V_20
+ V_153 -> V_23 ;
unsigned int V_201 = 0 ;
unsigned int V_203 = 0 , V_204 = 0 ;
int V_92 = 0 ;
int V_149 , V_256 ;
F_27 ( L_23 ) ;
if ( ( V_153 -> V_26 & V_208 ) == V_60 ) {
V_201 = V_153 -> V_21 + V_153 -> V_99 + V_153 -> V_22
+ V_153 -> V_24 ;
V_201 <<= 1 ;
} else if ( ( V_153 -> V_26 & V_208 ) == V_67 ) {
V_201 = V_153 -> V_21 + V_153 -> V_99 + V_153 -> V_22
+ V_153 -> V_24 ;
V_201 <<= 2 ;
} else if ( ( V_153 -> V_26 & V_208 ) == V_61 ) {
V_201 = V_153 -> V_21 + ( V_153 -> V_99 / 2 )
+ V_153 -> V_22 + V_153 -> V_24 ;
} else
V_201 = V_153 -> V_21 + V_153 -> V_99 + V_153 -> V_22
+ V_153 -> V_24 ;
if ( ! ( V_200 ) || ! ( V_201 ) )
F_41 ( L_24 ) ;
if ( V_153 -> V_210 && V_200 && V_201 ) {
V_203 = 1000000000 / V_153 -> V_210 ;
V_204 = ( V_203 * 1000 ) / V_200 ;
V_91 -> V_149 =
( unsigned int ) ( V_204 * 2 / V_201 ) ;
F_28 (
L_25
L_26 ,
V_257 , V_153 -> V_210 , V_200 , V_201 ,
V_257 , V_203 , V_204 , V_91 -> V_149 ) ;
} else {
V_91 -> V_149 = 60 ;
}
if ( ( V_153 -> V_96 == 1024 ) && ( V_153 -> V_99 == 600 ) )
V_149 = 60 ;
V_256 = 0 ;
while ( ( V_94 [ V_256 ] . V_95 != 0 ) &&
( V_94 [ V_256 ] . V_96 <= V_153 -> V_96 ) ) {
if ( ( V_94 [ V_256 ] . V_96 == V_153 -> V_96 ) &&
( V_94 [ V_256 ] . V_99 == V_153 -> V_99 ) &&
( V_94 [ V_256 ] . V_101 == V_153 -> V_154 ) ) {
if ( F_15 ( V_91 , V_256 ) > 0 ) {
V_92 = 1 ;
break;
}
}
V_256 ++ ;
}
if ( ! V_92 ) {
F_29 ( L_27 ,
V_153 -> V_96 , V_153 -> V_99 , V_153 -> V_154 ) ;
V_256 = 0 ;
while ( V_94 [ V_256 ] . V_95 != 0 ) {
if ( ( V_153 -> V_96 <= V_94 [ V_256 ] . V_96 ) &&
( V_153 -> V_99 <= V_94 [ V_256 ] . V_99 ) &&
( V_153 -> V_154 ==
V_94 [ V_256 ] . V_101 ) ) {
if ( F_15 ( V_91 ,
V_256 ) > 0 ) {
V_92 = 1 ;
break;
}
}
V_256 ++ ;
}
if ( V_92 ) {
V_153 -> V_96 = V_94 [ V_256 ] . V_96 ;
V_153 -> V_99 = V_94 [ V_256 ] . V_99 ;
F_28 ( L_28 ,
V_153 -> V_96 , V_153 -> V_99 , V_153 -> V_154 ) ;
} else {
F_29 ( L_29 ,
V_153 -> V_96 , V_153 -> V_99 , V_153 -> V_154 ) ;
return - V_209 ;
}
}
F_20 ( V_91 , V_153 ) ;
if ( V_153 -> V_225 < 0 )
V_153 -> V_225 = 0 ;
if ( V_153 -> V_224 < 0 )
V_153 -> V_224 = 0 ;
if ( ! V_246 ) {
if ( V_153 -> V_96 != V_153 -> V_206 )
V_153 -> V_206 = V_153 -> V_96 ;
if ( V_153 -> V_99 != V_153 -> V_207 )
V_153 -> V_207 = V_153 -> V_99 ;
}
if ( V_153 -> V_225 > V_153 -> V_206 - V_153 -> V_96 )
V_153 -> V_225 = V_153 -> V_206 - V_153 -> V_96 - 1 ;
if ( V_153 -> V_224 > V_153 -> V_207 - V_153 -> V_99 )
V_153 -> V_224 = V_153 -> V_207 - V_153 -> V_99 - 1 ;
V_153 -> V_155 . V_258 =
V_153 -> V_157 . V_258 =
V_153 -> V_158 . V_258 =
V_153 -> V_161 . V_156 = V_153 -> V_161 . V_159 = V_153 -> V_161 . V_258 = 0 ;
F_27 ( L_30 ) ;
return 0 ;
}
static int F_42 ( struct V_152 * V_153 ,
struct V_197 * V_198 )
{
int V_255 ;
if ( V_153 -> V_225 > ( V_198 -> V_153 . V_206 - V_198 -> V_153 . V_96 ) )
return - V_209 ;
if ( V_153 -> V_224 > ( V_198 -> V_153 . V_207 - V_198 -> V_153 . V_99 ) )
return - V_209 ;
if ( V_153 -> V_26 & V_259 ) {
if ( V_153 -> V_224 < 0 || V_153 -> V_224 >= V_198 -> V_153 . V_207
|| V_153 -> V_225 )
return - V_209 ;
} else {
if ( V_153 -> V_225 + V_198 -> V_153 . V_96 > V_198 -> V_153 . V_206
|| V_153 -> V_224 + V_198 -> V_153 . V_99
> V_198 -> V_153 . V_207 )
return - V_209 ;
}
V_255 = F_31 ( V_153 , V_198 ) ;
if ( V_255 < 0 )
return V_255 ;
V_198 -> V_153 . V_225 = V_153 -> V_225 ;
V_198 -> V_153 . V_224 = V_153 -> V_224 ;
if ( V_153 -> V_26 & V_259 )
V_198 -> V_153 . V_26 |= V_259 ;
else
V_198 -> V_153 . V_26 &= ~ V_259 ;
return 0 ;
}
static int F_43 ( int V_260 , struct V_197 * V_198 )
{
struct V_90 * V_91 = V_198 -> V_199 ;
T_1 V_2 ;
V_2 = F_3 ( V_4 , 0x17 ) ;
if ( V_260 > 0 )
V_2 &= 0x7f ;
else
V_2 |= 0x80 ;
F_2 ( V_4 , 0x17 , V_2 ) ;
F_2 ( V_3 , 0x00 , 0x01 ) ;
F_2 ( V_3 , 0x00 , 0x03 ) ;
return 0 ;
}
static int F_44 ( struct V_90 * V_91 )
{
T_1 V_261 , V_262 ;
T_1 V_2 = 0 ;
if ( V_91 -> V_111 == V_115 )
F_2 ( V_3 , V_263 , 0x51 ) ;
V_2 = F_3 ( V_3 , V_263 ) ;
switch ( ( V_2 & V_264 ) >> 4 ) {
case V_265 :
V_91 -> V_239 = 0x100000 ;
break;
case V_266 :
V_91 -> V_239 = 0x200000 ;
break;
case V_267 :
V_91 -> V_239 = 0x400000 ;
break;
case V_268 :
V_91 -> V_239 = 0x800000 ;
break;
case V_269 :
V_91 -> V_239 = 0x1000000 ;
break;
case V_270 :
V_91 -> V_239 = 0x2000000 ;
break;
case V_271 :
V_91 -> V_239 = 0x4000000 ;
break;
case V_272 :
V_91 -> V_239 = 0x8000000 ;
break;
case V_273 :
V_91 -> V_239 = 0x10000000 ;
break;
default:
return - 1 ;
}
V_262 = ( V_2 & 0x0c ) >> 2 ;
switch ( V_91 -> V_111 ) {
case V_274 :
case V_112 :
case V_115 :
V_261 = 1 ;
break;
case V_275 :
if ( V_2 & 0x04 )
V_261 = 2 ;
else
V_261 = 1 ;
break;
case V_276 :
if ( V_262 == 1 )
V_261 = 2 ;
else if ( V_262 == 2 )
V_261 = 3 ;
else if ( V_262 == 3 )
V_261 = 4 ;
else
V_261 = 1 ;
break;
case V_277 :
default:
if ( V_262 == 2 )
V_261 = 2 ;
else if ( V_262 == 3 )
V_261 = 3 ;
else
V_261 = 1 ;
break;
}
V_91 -> V_239 = V_91 -> V_239 * V_261 ;
F_13 ( L_31 ,
V_2 ,
V_91 -> V_239 , V_261 ) ;
return 0 ;
}
static void F_45 ( struct V_90 * V_91 )
{
T_1 V_278 , V_50 = 0 ;
V_91 -> V_170 = V_91 -> V_131 = 0 ;
switch ( V_91 -> V_134 ) {
case V_135 :
case V_136 :
break;
case V_188 :
case V_279 :
break;
}
V_278 = F_3 ( V_4 , V_280 ) ;
if ( ( V_278 & V_281 ) && ! V_186 )
V_186 = 0 ;
else {
if ( V_278 & 0x5F )
V_186 = 1 ;
else
V_186 = 0 ;
}
if ( ! V_91 -> V_282 ) {
if ( V_278 & V_283 )
V_91 -> V_113 = V_130 ;
else if ( V_278 & V_284 )
V_91 -> V_113 = V_114 ;
else if ( V_278 & V_285 )
V_91 -> V_113 = V_137 ;
else
V_91 -> V_113 = V_138 ;
}
if ( V_142 != - 1 )
V_91 -> V_170 = V_142 ;
else if ( V_278 & V_286 ) {
V_91 -> V_131 = V_168 ;
V_91 -> V_170 = V_171 ;
} else if ( V_278 & V_287 )
V_91 -> V_170 = V_171 ;
else if ( V_278 & V_288 )
V_91 -> V_170 = V_173 ;
else if ( V_278 & V_289 )
V_91 -> V_170 = V_175 ;
if ( V_91 -> V_131 == 0 ) {
V_50 = F_3 ( V_4 , 0x38 ) ;
if ( V_50 & 0x10 )
V_91 -> V_131 = V_133 ;
else
V_91 -> V_131 = V_132 ;
}
if ( V_290 != - 1 ) {
if ( V_290 )
V_186 = 0 ;
else
V_186 = 1 ;
}
}
static int F_46 ( struct V_90 * V_91 )
{
T_1 V_291 ;
V_291 = F_3 ( V_189 , 0x00 ) ;
switch ( V_291 ) {
case 0x01 :
V_91 -> V_134 = V_188 ;
break;
case 0x02 :
V_91 -> V_134 = V_279 ;
break;
default:
V_91 -> V_134 = V_184 ;
return 0 ;
}
return 1 ;
}
static void F_47 ( struct V_90 * V_91 )
{
T_1 V_2 ;
if ( ! F_46 ( V_91 ) ) {
V_2 = F_3 ( V_4 , V_292 ) ;
switch ( ( V_2 & V_293 ) >> 1 ) {
case V_294 :
V_91 -> V_134 = V_183 ;
break;
case V_295 :
V_91 -> V_134 = V_135 ;
break;
default:
break;
}
}
}
static int T_4 F_48 ( char * V_296 , int V_297 )
{
unsigned long V_298 ;
if ( F_49 ( V_296 + V_297 , 0 , & V_298 ) < 0 || V_298 > V_299 ) {
F_29 ( L_32 , V_296 ) ;
return 0 ;
}
return V_298 ;
}
static int T_4 F_50 ( char * V_300 )
{
char * V_301 ;
if ( ! V_300 || ! * V_300 )
return 0 ;
F_13 ( L_33 , V_300 ) ;
while ( ( V_301 = F_51 ( & V_300 , L_34 ) ) != NULL ) {
if ( ! * V_301 )
continue;
if ( ! strncmp ( V_301 , L_35 , 5 ) ) {
V_302 = V_301 + 5 ;
} else if ( ! strncmp ( V_301 , L_36 , 5 ) ) {
V_303 = F_48 ( V_301 , 5 ) ;
} else if ( ! strncmp ( V_301 , L_37 , 6 ) ) {
V_149 = F_48 ( V_301 , 6 ) ;
} else if ( ! strncmp ( V_301 , L_38 , 5 ) ) {
V_149 = F_48 ( V_301 , 5 ) ;
} else if ( ! strncmp ( V_301 , L_39 , 7 ) ) {
V_186 = 1 ;
} else if ( ! strncmp ( V_301 , L_40 , 7 ) ) {
V_192 = F_48 ( V_301 , 7 ) ;
} else if ( ! strncmp ( V_301 , L_41 , 14 ) ) {
F_16 ( V_301 + 14 ) ;
} else if ( ! strncmp ( V_301 , L_42 , 10 ) ) {
V_290 = F_48 ( V_301 , 10 ) ;
} else if ( ! strncmp ( V_301 , L_43 , 7 ) ) {
F_19 ( V_301 + 7 ) ;
} else if ( ! strncmp ( V_301 , L_44 , 11 ) ) {
F_19 ( V_301 + 7 ) ;
} else if ( ! strncmp ( V_301 , L_45 , 4 ) ) {
V_304 = 1 ;
V_141 = V_114 ;
} else if ( ! strncmp ( V_301 , L_46 , 6 ) ) {
V_246 = 0 ;
} else {
V_302 = V_301 ;
}
}
return 0 ;
}
static int T_5 F_52 ( struct V_305 * V_306 ,
const struct V_307 * V_308 )
{
T_1 V_2 , V_309 ;
T_1 V_310 , V_311 ;
int V_312 ;
struct V_197 * V_197 ;
struct V_90 * V_91 ;
struct V_7 * V_110 ;
V_197 = F_53 ( sizeof( * V_91 ) , & V_306 -> V_313 ) ;
if ( ! V_197 )
return - V_314 ;
V_91 = V_197 -> V_199 ;
V_110 = & V_91 -> V_110 ;
V_91 -> V_197 = V_197 ;
V_91 -> V_315 = V_306 -> V_316 ;
F_54 ( V_306 ,
V_317 ,
& V_91 -> V_318 ) ;
V_110 -> V_319 = V_91 -> V_318 ;
V_91 -> V_320 = V_306 -> V_321 -> V_322 ;
V_91 -> V_323 = F_55 ( V_306 -> V_324 ) ;
V_91 -> V_325 = F_56 ( V_306 -> V_324 ) ;
V_91 -> V_326 = V_306 -> V_327 ;
V_91 -> V_328 = V_306 -> V_329 ;
V_91 -> V_237 = F_57 ( V_306 , 0 ) ;
V_91 -> V_250 = F_57 ( V_306 , 1 ) ;
V_91 -> V_252 = F_58 ( V_306 , 1 ) ;
V_91 -> V_330 = F_57 ( V_306 , 2 ) + 0x30 ;
V_110 -> V_331 = ( unsigned char * ) V_91 -> V_330 ;
F_13 ( L_47 ,
( unsigned long ) F_57 ( V_306 , 2 ) ,
V_91 -> V_332 . V_69 ) ;
if ( F_59 ( V_306 ) ) {
V_312 = - V_333 ;
goto error;
}
if ( V_141 != - 1 ) {
V_91 -> V_113 = V_141 ;
V_91 -> V_282 = true ;
}
F_9 ( & V_91 -> V_332 , ( unsigned long ) V_110 -> V_331 ) ;
F_2 ( V_3 , V_213 , V_214 ) ;
V_309 = F_3 ( V_3 , V_213 ) ;
if ( V_309 != 0xa1 ) {
F_29 ( L_48 ) ;
V_312 = - V_333 ;
goto error;
}
switch ( V_91 -> V_315 ) {
case V_334 :
F_24 ( V_4 , V_335 , V_336 ) ;
V_310 = F_3 ( V_4 , V_337 ) ;
if ( V_310 & V_338 )
V_91 -> V_111 = V_112 ;
else
V_91 -> V_111 = V_274 ;
break;
case V_339 :
V_91 -> V_111 = V_277 ;
break;
case V_340 :
V_91 -> V_111 = V_341 ;
break;
case V_342 :
V_91 -> V_111 = V_275 ;
break;
case V_343 :
V_91 -> V_111 = V_115 ;
break;
default:
V_312 = - V_344 ;
goto error;
}
F_13 ( L_49 , V_91 -> V_111 ) ;
V_110 -> V_15 = V_91 -> V_111 ;
if ( F_44 ( V_91 ) ) {
F_29 ( L_50 ) ;
V_312 = - V_344 ;
goto error;
}
F_24 ( V_3 ,
V_345 ,
( V_346 | V_347 ) ) ;
F_24 ( V_3 , V_348 , V_349 ) ;
V_110 -> V_350 = V_91 -> V_239 ;
if ( ! F_60 ( V_91 -> V_237 ,
V_91 -> V_239 ,
L_51 ) ) {
F_29 ( L_52 ,
V_91 -> V_239 ) ;
F_29 ( L_53 ) ;
F_29 ( L_54 ) ;
V_312 = - V_344 ;
goto error;
}
if ( ! F_60 ( V_91 -> V_250 ,
V_91 -> V_252 ,
L_55 ) ) {
F_29 ( L_56 ) ;
V_312 = - V_344 ;
goto V_351;
}
V_91 -> V_352 = V_110 -> V_353 =
F_61 ( V_91 -> V_237 , V_91 -> V_239 ) ;
V_91 -> V_354 = F_61 ( V_91 -> V_250 ,
V_91 -> V_252 ) ;
F_13 ( L_57 ,
V_91 -> V_237 ,
V_91 -> V_352 ,
V_91 -> V_239 / 1024 ) ;
F_13 ( L_58 ,
V_91 -> V_250 , V_91 -> V_354 ,
V_91 -> V_252 / 1024 ) ;
F_62 ( V_306 , V_91 ) ;
if ( ! F_63 ( V_306 ) )
F_29 ( L_59 ) ;
V_91 -> V_355 = ( unsigned int ) 0 ;
V_91 -> V_134 = V_184 ;
if ( ( V_91 -> V_111 == V_274 ) ||
( V_91 -> V_111 == V_115 ) ) {
V_91 -> V_134 = V_184 ;
} else if ( V_91 -> V_111 == V_112 ) {
V_311 = F_3 ( V_4 , 0x38 ) ;
if ( ( V_311 & 0xE0 ) == 0xC0 )
V_91 -> V_113 = V_114 ;
else if ( ( V_311 & 0xE0 ) == 0x60 )
V_91 -> V_134 = V_136 ;
else
V_91 -> V_134 = V_184 ;
} else {
F_47 ( V_91 ) ;
}
V_110 -> V_356 = V_357 ;
V_110 -> V_129 = 0 ;
switch ( V_91 -> V_134 ) {
case V_188 :
V_2 = F_3 ( V_189 , 0x01 ) ;
if ( V_2 >= 0xE0 ) {
V_110 -> V_356 = V_358 ;
F_13 ( L_60 , V_2 ) ;
} else if ( V_2 >= 0xD0 ) {
V_110 -> V_356 = V_359 ;
F_13 ( L_61 , V_2 ) ;
}
else {
V_110 -> V_356 = V_360 ;
F_13 ( L_62 ) ;
}
break;
case V_279 :
V_2 = F_3 ( V_189 , 0x01 ) ;
if ( V_2 >= 0xE0 ) {
V_110 -> V_356 = V_358 ;
F_13 ( L_60 , V_2 ) ;
} else if ( V_2 >= 0xD0 ) {
V_110 -> V_356 = V_359 ;
F_13 ( L_60 , V_2 ) ;
} else if ( V_2 >= 0xB0 ) {
V_309 = F_3 ( V_189 , 0x23 ) ;
V_110 -> V_356 = V_361 ;
} else {
V_110 -> V_356 = V_362 ;
F_13 ( L_63 ) ;
}
break;
case V_183 :
V_110 -> V_129 = 0x1 ;
F_13 ( L_64 ) ;
break;
case V_363 :
V_110 -> V_129 = 0x2 ;
F_13 ( L_65 ) ;
break;
case V_136 :
V_110 -> V_129 = 0x4 ;
F_13 ( L_66 ) ;
break;
case V_135 :
V_110 -> V_129 = 0x5 ;
F_13 ( L_67 ) ;
break;
default:
F_13 ( L_68 ) ;
break;
}
if ( V_91 -> V_134 != V_184 )
F_45 ( V_91 ) ;
else if ( V_91 -> V_111 != V_112 )
V_91 -> V_113 = V_138 ;
if ( V_91 -> V_113 == V_114 ) {
if ( ! V_304 ) {
V_2 = F_3 ( V_4 , V_364 ) ;
V_2 &= 0x0f ;
V_110 -> V_118 = V_365 [ V_2 ] ;
}
}
if ( ( V_110 -> V_356 == V_361 ) ||
( V_110 -> V_356 == V_359 ) ||
( V_110 -> V_356 == V_358 ) ) {
int V_262 ;
V_262 = F_3 ( V_4 , 0x34 ) ;
if ( V_262 <= 0x13 ) {
V_262 = F_3 ( V_4 , 0x38 ) ;
if ( ( V_262 & 0x03 ) == 0x03 ) {
} else {
V_262 = F_3 ( V_4 , 0x35 ) ;
if ( V_262 & 0x01 ) {
} else {
V_262 = F_3 ( V_4 ,
0x30 ) ;
if ( V_262 & 0x20 ) {
V_262 = F_3 (
V_185 , 0x13 ) ;
}
}
}
}
}
V_91 -> V_104 = - 1 ;
if ( V_302 )
F_11 ( V_91 , V_302 ) ;
else if ( V_303 != - 1 )
F_14 ( V_91 , V_303 ) ;
if ( V_91 -> V_104 >= 0 )
V_91 -> V_104 =
F_15 ( V_91 , V_91 -> V_104 ) ;
if ( V_91 -> V_104 < 0 ) {
if ( V_91 -> V_113 == V_114 &&
V_91 -> V_111 == V_112 )
V_91 -> V_104 =
F_10 ( V_91 ) ;
else
V_91 -> V_104 = V_366 ;
}
if ( V_91 -> V_104 < 0 ) {
F_64 ( & V_306 -> V_313 , L_69 ) ;
goto V_367;
}
V_91 -> V_149 = V_149 ;
if ( V_91 -> V_149 == 0 )
V_91 -> V_149 = 60 ;
if ( F_17 ( V_91 ,
V_91 -> V_149 ) == 0 ) {
V_91 -> V_145 =
V_94 [ V_91 -> V_104 ] . V_145 ;
V_91 -> V_149 = 60 ;
}
V_91 -> V_182 = V_94 [ V_91 -> V_104 ] . V_101 ;
V_91 -> V_215 =
V_91 -> V_191 =
V_94 [ V_91 -> V_104 ] . V_96 ;
V_91 -> V_216 =
V_91 -> V_217 =
V_94 [ V_91 -> V_104 ] . V_99 ;
V_91 -> V_218 = V_91 -> V_219 = 0 ;
V_91 -> V_220 =
V_91 -> V_191 *
( V_91 -> V_182 >> 3 ) ;
switch ( V_91 -> V_182 ) {
case 8 :
V_91 -> V_221 = 0x0000 ;
V_91 -> V_222 = 0x00000000 ;
V_91 -> V_160 = 256 ;
break;
case 16 :
V_91 -> V_221 = 0x8000 ;
V_91 -> V_222 = 0x00010000 ;
V_91 -> V_160 = 16 ;
break;
case 32 :
V_91 -> V_221 = 0xC000 ;
V_91 -> V_222 = 0x00020000 ;
V_91 -> V_160 = 16 ;
break;
default:
V_91 -> V_160 = 16 ;
F_13 ( L_70 ,
V_91 -> V_182 ) ;
break;
}
F_13 ( L_71 ,
V_91 -> V_191 ,
V_91 -> V_217 ,
V_91 -> V_182 ,
V_91 -> V_149 ) ;
V_197 -> V_153 . V_155 . V_159 = 8 ;
V_197 -> V_153 . V_157 . V_159 = 8 ;
V_197 -> V_153 . V_158 . V_159 = 8 ;
V_197 -> V_153 . V_368 = V_369 ;
V_197 -> V_153 . V_370 = - 1 ;
V_197 -> V_153 . V_371 = - 1 ;
V_197 -> V_153 . V_26 = V_60 ;
V_197 -> V_153 . V_96 = V_91 -> V_191 ;
V_197 -> V_153 . V_206 = V_91 -> V_191 ;
V_197 -> V_153 . V_99 = V_91 -> V_217 ;
V_197 -> V_153 . V_207 = V_91 -> V_217 ;
V_197 -> V_153 . V_154 = V_91 -> V_182 ;
F_20 ( V_91 , & V_197 -> V_153 ) ;
V_197 -> V_153 . V_210 = ( T_2 ) ( 1000000000 /
F_5 ( & V_91 -> V_332 ,
V_110 ,
V_94 [ V_91 -> V_104 ] . V_95 ,
V_91 -> V_145 ) ) ;
if ( F_8 ( & V_91 -> V_332 , V_110 ,
V_94 [ V_91 -> V_104 ] . V_95 ,
V_91 -> V_145 ,
& V_197 -> V_153 . V_19 ,
& V_197 -> V_153 . V_20 ,
& V_197 -> V_153 . V_21 ,
& V_197 -> V_153 . V_22 ,
& V_197 -> V_153 . V_23 ,
& V_197 -> V_153 . V_24 ,
& V_197 -> V_153 . V_25 ,
& V_197 -> V_153 . V_26 ) ) {
if ( ( V_197 -> V_153 . V_26 & V_208 ) ==
V_61 ) {
V_197 -> V_153 . V_99 <<= 1 ;
V_197 -> V_153 . V_207 <<= 1 ;
} else if ( ( V_197 -> V_153 . V_26 & V_208 ) ==
V_67 ) {
V_197 -> V_153 . V_210 >>= 1 ;
V_197 -> V_153 . V_99 >>= 1 ;
V_197 -> V_153 . V_207 >>= 1 ;
}
}
strncpy ( V_197 -> V_211 . V_372 , L_72 , sizeof( V_197 -> V_211 . V_372 ) - 1 ) ;
V_197 -> V_211 . type = V_240 ;
V_197 -> V_211 . V_245 = 1 ;
V_197 -> V_211 . V_247 = 1 ;
V_197 -> V_373 = V_374 ;
V_197 -> V_375 = V_91 -> V_352 ;
V_197 -> V_376 = & V_377 ;
F_38 ( & V_197 -> V_211 , - 1 , V_197 ) ;
V_197 -> V_233 = V_91 -> V_233 ;
F_65 ( & V_197 -> V_378 , 256 , 0 ) ;
#ifdef F_66
V_91 -> V_355 = F_67 ( V_91 -> V_237 ,
V_91 -> V_239 , V_379 , 1 ) ;
if ( V_91 -> V_355 >= 0 )
V_332 ( & V_306 -> V_313 , L_73 ) ;
#endif
if ( F_68 ( V_197 ) < 0 ) {
V_312 = - V_209 ;
goto V_380;
}
F_1 () ;
return 0 ;
V_380:
#ifdef F_66
if ( V_91 -> V_355 >= 0 )
F_69 ( V_91 -> V_355 , V_91 -> V_237 ,
V_91 -> V_239 ) ;
#endif
V_367:
F_70 ( V_91 -> V_354 ) ;
F_70 ( V_91 -> V_352 ) ;
F_71 ( V_91 -> V_250 , V_91 -> V_252 ) ;
V_351:
F_71 ( V_91 -> V_237 , V_91 -> V_239 ) ;
error:
F_72 ( V_197 ) ;
return V_312 ;
}
static void T_6 F_73 ( struct V_305 * V_306 )
{
struct V_90 * V_91 = F_74 ( V_306 ) ;
struct V_197 * V_197 = V_91 -> V_197 ;
F_75 ( V_197 ) ;
#ifdef F_66
if ( V_91 -> V_355 >= 0 )
F_69 ( V_91 -> V_355 , V_91 -> V_237 ,
V_91 -> V_239 ) ;
#endif
F_70 ( V_91 -> V_354 ) ;
F_70 ( V_91 -> V_352 ) ;
F_71 ( V_91 -> V_250 , V_91 -> V_252 ) ;
F_71 ( V_91 -> V_237 , V_91 -> V_239 ) ;
F_72 ( V_197 ) ;
F_62 ( V_306 , NULL ) ;
}
static int T_4 F_76 ( void )
{
char * V_381 = NULL ;
if ( V_382 != NULL )
F_16 ( V_382 ) ;
if ( F_77 ( L_74 , & V_381 ) )
return - V_344 ;
F_50 ( V_381 ) ;
return F_78 ( & V_383 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_383 ) ;
F_28 ( L_75 ) ;
}
