static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = (struct V_8 * ) & V_4 -> V_10 [ 0 ] ;
unsigned char error = V_6 -> V_11 [ V_12 ] ;
if( error & V_13 ) {
V_9 -> V_14 = 0x70 | V_15 ;
V_9 -> V_16 = 0xb ;
V_9 -> V_17 = V_18 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
} else if ( error & V_21 ) {
V_9 -> V_14 = 0x70 | V_15 ;
V_9 -> V_16 = 0xb ;
V_9 -> V_17 = V_18 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
} else if ( error & V_22 ) {
V_9 -> V_14 = 0x70 | V_15 ;
V_9 -> V_16 = 0xb ;
V_9 -> V_17 = V_23 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
} else if ( error & V_24 ) {
V_9 -> V_14 = 0x70 | V_15 ;
V_9 -> V_16 = 0xb ;
V_9 -> V_17 = V_25 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
} else {
V_9 -> V_14 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = 0 ;
V_9 -> V_19 = 0 ;
V_9 -> V_20 = 0 ;
}
}
static void F_2 ( struct V_5 * V_6 ,
enum V_26 V_27 , void * V_28 , unsigned V_29 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
if ( V_28 )
F_3 ( & V_6 -> V_30 , V_28 , V_29 ) ;
V_4 -> V_31 = V_27 ;
V_4 -> V_32 . V_33 . V_34 = V_28 ? & V_6 -> V_30 : NULL ;
V_4 -> V_32 . V_35 = V_29 ;
V_4 -> V_32 . V_33 . V_36 = V_28 ? 1 : 0 ;
}
static void F_4 ( struct V_3 * V_4 , unsigned V_29 )
{
V_4 -> V_32 . V_35 = V_29 ;
}
static int F_5 ( struct V_1 * V_2 , int V_37 ,
void * V_38 , int V_39 )
{
union V_40 V_41 ;
static struct V_42 V_43 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_3 * V_4 = & V_6 -> V_4 ;
int V_44 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_4 -> V_45 = V_6 -> V_45 ;
V_4 -> V_46 = & V_43 ;
V_41 . V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_41 . V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_41 . V_47 . V_53 = 1 ;
switch ( V_37 ) {
case V_54 :
F_6 ( V_2 , L_1 ) ;
V_41 . V_47 . V_55 = V_56 | V_57 ;
V_41 . V_47 . V_58 =
V_59 | V_60 |
V_61 | V_62 ;
F_2 ( V_6 , V_63 , V_38 , V_39 ) ;
break;
case V_64 :
F_6 ( V_2 , L_2 , V_39 ) ;
V_41 . V_47 . V_55 = V_65 | V_57 |
V_66 | V_67 |
V_68 ;
V_41 . V_47 . V_58 = V_69 ;
V_41 . V_70 . V_71 = V_39 ;
F_2 ( V_6 , V_72 , NULL , 0 ) ;
break;
case V_73 :
F_6 ( V_2 , L_3 ) ;
V_41 . V_47 . V_55 = V_65 | V_57 |
V_66 | V_67 ;
V_41 . V_47 . V_58 = V_74 ;
V_41 . V_70 . V_75 = V_76 ;
F_2 ( V_6 , V_72 , NULL , 0 ) ;
break;
case V_77 :
F_6 ( V_2 , L_4 ) ;
V_41 . V_47 . V_55 = V_65 | V_57 |
V_66 | V_67 ;
V_41 . V_47 . V_58 = V_74 ;
V_41 . V_70 . V_75 = V_78 ;
F_2 ( V_6 , V_72 , NULL , 0 ) ;
break;
case V_79 :
F_6 ( V_2 , L_5 ) ;
V_41 . V_47 . V_55 = V_65 | V_68 ;
V_41 . V_47 . V_58 = V_69 | V_80 ;
V_41 . V_70 . V_71 = V_6 -> V_81 ;
V_41 . V_70 . V_82 = V_83 ;
F_2 ( V_6 , V_72 , NULL , 0 ) ;
break;
case V_84 :
F_6 ( V_2 , L_6 ) ;
V_41 . V_47 . V_58 = V_80 ;
V_41 . V_70 . V_82 = V_85 ;
F_2 ( V_6 , V_63 , V_6 -> V_86 ,
V_87 * 2 ) ;
break;
default:
F_6 ( V_2 , L_7 , V_37 ) ;
return V_88 ;
}
memcpy ( V_4 -> V_45 , & V_41 , sizeof( V_41 . V_47 ) ) ;
V_4 -> V_89 = sizeof( V_41 . V_47 ) ;
V_44 = F_7 ( V_4 , V_2 ) ;
if ( V_44 == V_90 )
V_44 = V_91 ;
else {
F_6 ( V_2 , L_8 ,
V_37 , V_44 ) ;
V_44 = V_88 ;
}
return V_44 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
int V_92 = V_91 ;
int V_93 ;
F_6 ( V_2 , L_9 ) ;
V_93 = F_5 ( V_2 , V_54 ,
V_6 -> V_94 , sizeof( V_6 -> V_11 ) ) ;
if ( V_93 != V_95 ) {
F_6 ( V_2 , L_10 ) ;
V_92 = V_88 ;
} else {
memcpy ( V_6 -> V_11 , V_6 -> V_94 , sizeof( V_6 -> V_11 ) ) ;
F_6 ( V_2 , L_11 ,
V_6 -> V_11 [ V_12 ] ) ;
}
return V_92 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_40 * V_96 )
{
int V_97 = 0 ;
int V_93 ;
int V_98 ;
memcpy ( V_4 -> V_45 , V_96 , sizeof( V_96 -> V_47 ) ) ;
V_4 -> V_89 = sizeof( V_96 -> V_47 ) ;
V_93 = F_7 ( V_4 , V_2 ) ;
if ( F_10 ( V_99 , & V_2 -> V_100 ) ) {
F_6 ( V_2 , L_12 ) ;
goto V_101;
}
switch ( V_93 ) {
case V_90 :
V_4 -> V_98 = V_102 ;
break;
case V_103 :
F_6 ( V_2 , L_13 ) ;
V_4 -> V_98 = V_104 ;
return;
case V_105 :
F_6 ( V_2 , L_14 ) ;
V_97 = 1 ;
break;
case V_106 :
F_6 ( V_2 , L_15 ) ;
V_4 -> V_98 = V_107 << 16 ;
return;
default:
F_6 ( V_2 , L_16 ) ;
V_4 -> V_98 = V_107 << 16 ;
return;
}
if ( ( F_11 ( V_4 ) > 0 ) &&
! ( ( V_4 -> V_45 [ 0 ] == V_108 ) ||
( V_4 -> V_45 [ 0 ] == V_109 ) ||
( V_4 -> V_45 [ 0 ] == V_110 ) ||
( V_4 -> V_45 [ 0 ] == V_111 ) ||
( V_4 -> V_45 [ 0 ] == V_112 ) ) ) {
F_6 ( V_2 , L_17 ) ;
V_97 = 1 ;
}
if ( V_97 ) {
V_98 = F_8 ( V_2 ) ;
if ( F_10 ( V_99 , & V_2 -> V_100 ) ) {
F_6 ( V_2 , L_18 ) ;
goto V_101;
}
if ( V_98 == V_91 ) {
F_1 ( V_2 , V_4 ) ;
V_4 -> V_98 = V_104 ;
if ( ( V_4 -> V_10 [ 2 ] & 0xf ) == 0x0 )
V_4 -> V_98 = V_102 ;
} else {
V_4 -> V_98 = V_107 << 16 ;
}
}
if ( V_93 == V_105 )
V_4 -> V_98 = V_104 ;
return;
V_101:
V_4 -> V_98 = V_113 << 16 ;
F_12 ( V_114 , & V_2 -> V_100 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
F_6 ( V_2 , L_19 ,
V_6 -> V_49 . V_115 ) ;
F_6 ( V_2 , L_20 ,
V_6 -> V_49 . V_116 ) ;
F_6 ( V_2 , L_21 ,
V_6 -> V_49 . V_117 ) ;
F_6 ( V_2 , L_22 ,
( V_6 -> V_49 . V_118 & V_119 ) >> 6 ) ;
F_6 ( V_2 , L_23 ,
V_6 -> V_49 . V_118 & V_120 ) ;
F_6 ( V_2 , L_24 ,
V_6 -> V_49 . V_118 & V_121 ) ;
F_6 ( V_2 , L_25 ,
V_6 -> V_49 . V_118 & V_122 ) ;
F_6 ( V_2 , L_26 ,
V_6 -> V_49 . V_50 ) ;
F_6 ( V_2 , L_27 ,
V_6 -> V_49 . V_52 ) ;
F_6 ( V_2 , L_28 ,
V_6 -> V_49 . V_123 & V_124 ) ;
F_6 ( V_2 , L_29 ,
V_6 -> V_49 . V_123 & V_125 ) ;
F_6 ( V_2 , L_30 ,
V_6 -> V_49 . V_123 & V_126 ) ;
F_6 ( V_2 , L_31 ,
V_6 -> V_49 . V_123 & V_127 ) ;
F_6 ( V_2 , L_32 ,
V_6 -> V_49 . V_123 & V_128 ) ;
F_6 ( V_2 , L_33 ,
V_6 -> V_49 . V_123 & V_129 ) ;
F_6 ( V_2 , L_34 ,
V_6 -> V_49 . V_123 & V_130 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
int V_92 = V_91 ;
int V_98 ;
#ifdef F_15
F_6 ( V_2 , L_35 ) ;
F_6 ( V_2 , L_36 ) ;
F_13 ( V_2 , V_6 ) ;
#endif
V_98 = F_16 (
V_2 ,
V_2 -> V_131 ,
0x01 ,
V_132 | V_133 | V_134 ,
0x0000 ,
0x0002 ,
( void * ) & V_6 -> V_49 ,
sizeof( V_6 -> V_49 ) ) ;
if ( V_98 >= 0 ) {
F_6 ( V_2 , L_37 ) ;
} else {
F_6 ( V_2 , L_38 ) ;
V_92 = V_88 ;
}
F_6 ( V_2 , L_39 , V_92 ) ;
return V_92 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
int V_92 = V_91 ;
int V_98 ;
F_6 ( V_2 , L_40 ) ;
V_98 = F_16 (
V_2 ,
V_2 -> V_135 ,
0x02 ,
V_132 | V_133 | V_136 ,
0x0000 ,
0x0002 ,
( void * ) & V_6 -> V_49 ,
sizeof( V_6 -> V_49 ) ) ;
if ( V_98 >= 0 ) {
F_6 ( V_2 , L_41 ) ;
#ifdef F_15
F_13 ( V_2 , V_6 ) ;
#endif
} else {
F_6 ( V_2 , L_42 ) ;
V_92 = V_88 ;
}
F_6 ( V_2 , L_43 , V_92 ) ;
return V_92 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
int V_93 ;
F_6 ( V_2 , L_44 ) ;
V_93 = F_5 ( V_2 , V_79 , NULL , 0 ) ;
if ( V_93 != V_95 ) {
F_6 ( V_2 , L_45 ) ;
V_92 = V_88 ;
}
F_6 ( V_2 , L_46 , V_92 ) ;
return V_92 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
int V_93 ;
F_6 ( V_2 , L_47 ) ;
V_93 = F_5 ( V_2 , V_73 , NULL , 0 ) ;
if ( V_93 != V_95 ) {
F_6 ( V_2 , L_48 ) ;
V_92 = V_88 ;
} else {
F_20 ( 10 ) ;
V_93 = F_5 ( V_2 , V_77 , NULL , 0 ) ;
if ( V_93 != V_95 ) {
F_6 ( V_2 , L_49 ) ;
V_92 = V_88 ;
} else {
F_20 ( 50 ) ;
}
}
F_6 ( V_2 , L_50 , V_92 ) ;
return V_92 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned char V_137 ,
int V_138 )
{
int V_44 = V_91 ;
unsigned long V_139 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
unsigned char * V_140 = V_6 -> V_94 ;
int V_141 = 0 ;
if ( V_138 )
V_139 = V_142 + V_143 * V_144 ;
else
V_139 = V_142 + V_145 * V_144 ;
while( 1 ) {
V_44 = F_5 ( V_2 , V_64 , NULL , V_137 ) ;
if ( V_44 != V_91 )
break;
V_44 = F_5 ( V_2 , V_54 ,
V_140 , 8 ) ;
if ( V_44 != V_91 )
break;
if ( ! V_138 ) {
if ( V_140 [ V_146 ] & V_147 ) {
F_6 ( V_2 , L_51 ,
V_137 == V_148 ?
L_52 : L_53 ) ;
} else {
F_6 ( V_2 , L_54 ,
V_137 == V_148 ?
L_52 : L_53 ) ;
break;
}
}
else if ( V_140 [ V_146 ] &
( V_147 | V_149 | V_150 ) ) {
F_6 ( V_2 , L_55 ) ;
}
else if ( V_140 [ V_146 ] & V_151 ) {
F_6 ( V_2 , L_56 ) ;
V_6 -> V_152 |= V_153 ;
V_6 -> V_81 = V_137 ;
break;
}
else if ( V_140 [ V_154 ] == 0xEB &&
V_140 [ V_155 ] == 0x14 ) {
if ( ( V_137 & V_156 ) &&
! V_141 ) {
F_6 ( V_2 , L_57 ) ;
V_141 = 1 ;
V_137 = V_148 ;
} else {
F_6 ( V_2 , L_58 ) ;
V_6 -> V_81 = V_137 ;
V_44 = F_18 ( V_2 ) ;
break;
}
} else {
F_6 ( V_2 , L_59 ) ;
break;
}
if ( F_22 ( V_142 , V_139 ) ) {
if ( ! V_138 )
F_6 ( V_2 , L_60 ) ;
else
F_6 ( V_2 , L_61 ) ;
break;
}
}
return V_44 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
int V_92 = V_91 ;
F_6 ( V_2 , L_62 ) ;
V_92 = F_17 ( V_2 ) ;
if ( V_92 == V_91 ) {
int V_157 ;
V_92 = F_21 ( V_2 , V_148 , 0 ) ;
if ( V_92 == V_91 )
V_92 = F_21 ( V_2 , V_156 , 0 ) ;
if ( V_92 == V_91 ) {
V_92 = F_19 ( V_2 ) ;
if ( V_92 == V_91 )
V_92 = F_21 ( V_2 , V_148 , 1 ) ;
}
V_157 = ( V_6 -> V_81 & V_156 ) ? 1 : 0 ;
if ( ! ( V_6 -> V_49 . V_118 & V_120 ) ) {
F_6 ( V_2 , L_63 ,
V_157 ) ;
V_6 -> V_49 . V_118 &= 0x3f ;
V_6 -> V_49 . V_118 |= ( V_157 << 6 ) ;
V_92 = F_14 ( V_2 ) ;
}
}
F_6 ( V_2 , L_64 , V_92 ) ;
return ( V_92 ) ;
}
static void F_24 ( T_1 * V_86 )
{
#ifndef F_25
# ifdef F_26
int V_158 ;
for ( V_158 = 0 ; V_158 < V_87 ; V_158 ++ )
V_86 [ V_158 ] = F_27 ( V_86 [ V_158 ] ) ;
# else
# error "Please fix <asm/byteorder.h>"
# endif
#endif
}
static void F_28 ( struct V_1 * V_2 , T_1 * V_86 )
{
F_6 ( V_2 , L_65 ) ;
F_6 ( V_2 , L_66 , V_86 [ V_159 ] ) ;
F_6 ( V_2 , L_67 , V_86 [ V_160 ] ) ;
F_6 ( V_2 , L_68 , V_86 [ V_161 ] ) ;
F_6 ( V_2 , L_69 , V_86 [ 4 ] ) ;
F_6 ( V_2 , L_70 , V_86 [ 5 ] ) ;
F_6 ( V_2 , L_71 , V_86 [ V_162 ] ) ;
F_6 ( V_2 , L_72 , * ( char * ) & V_86 [ V_163 ] ) ;
F_6 ( V_2 , L_73 , V_86 [ 20 ] ) ;
F_6 ( V_2 , L_74 , V_86 [ V_164 ] ) ;
F_6 ( V_2 , L_75 , V_86 [ 22 ] ) ;
F_6 ( V_2 , L_76 , * ( char * ) & V_86 [ V_165 ] ) ;
F_6 ( V_2 , L_77 , * ( char * ) & V_86 [ V_166 ] ) ;
F_6 ( V_2 , L_78 , V_86 [ V_167 ] & 0xff ) ;
F_6 ( V_2 , L_79 , V_86 [ V_168 ] ) ;
F_6 ( V_2 , L_80 , V_86 [ V_169 ] >> 8 ) ;
F_6 ( V_2 , L_81 , V_86 [ V_170 ] >> 8 ) ;
F_6 ( V_2 , L_82 , V_86 [ V_171 ] >> 8 ) ;
F_6 ( V_2 , L_83 , V_86 [ V_172 ] ) ;
F_6 ( V_2 , L_84 , V_86 [ V_173 ] ) ;
F_6 ( V_2 , L_85 , V_86 [ V_174 ] ) ;
F_6 ( V_2 , L_86 , V_86 [ V_175 ] ) ;
F_6 ( V_2 , L_87 , F_29 ( V_86 , 57 ) ) ;
F_6 ( V_2 , L_88 , V_86 [ V_176 ] & 0xff ) ;
F_6 ( V_2 , L_89 , F_29 ( V_86 , V_177 ) ) ;
F_6 ( V_2 , L_90 , V_86 [ V_178 ] ) ;
F_6 ( V_2 , L_91 , V_86 [ V_179 ] ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
int V_92 = V_91 ;
T_1 * V_86 = V_6 -> V_86 ;
F_6 ( V_2 , L_92 ) ;
V_6 -> V_81 = V_148 ;
V_92 = F_23 ( V_2 ) ;
if ( V_92 == V_91 ) {
int V_93 ;
if ( V_6 -> V_152 & V_153 ) {
V_93 = F_5 ( V_2 , V_84 ,
V_86 , V_87 * 2 ) ;
if ( V_93 != V_95 ) {
F_6 ( V_2 , L_93 ) ;
V_92 = V_88 ;
} else {
int V_158 ;
T_2 * V_180 ;
T_3 * V_181 ;
F_24 ( V_86 ) ;
F_28 ( V_2 , V_86 ) ;
memset ( & V_6 -> V_182 , 0 , sizeof( V_6 -> V_182 ) ) ;
V_6 -> V_182 . V_183 = V_184 ;
V_6 -> V_182 . V_185 = 0x1F ;
if ( V_86 [ V_178 ] & V_186 ) {
V_6 -> V_182 . V_187 = V_188 ;
V_6 -> V_152 |= V_189 ;
}
V_180 = ( T_2 * ) & V_86 [ V_166 ] ;
V_181 = ( T_3 * ) V_6 -> V_182 . V_190 ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ )
V_181 [ V_158 ] = F_31 ( V_180 [ V_158 ] ) ;
V_180 = ( T_2 * ) & V_86 [ V_166 + 8 / 2 ] ;
V_181 = ( T_3 * ) V_6 -> V_182 . V_191 ;
for ( V_158 = 0 ; V_158 < 8 ; V_158 ++ )
V_181 [ V_158 ] = F_31 ( V_180 [ V_158 ] ) ;
V_180 = ( T_2 * ) & V_86 [ V_165 ] ;
V_181 = ( T_3 * ) V_6 -> V_182 . V_192 ;
for ( V_158 = 0 ; V_158 < 2 ; V_158 ++ )
V_181 [ V_158 ] = F_31 ( V_180 [ V_158 ] ) ;
if ( V_86 [ V_179 ] & V_186 ) {
F_6 ( V_2 , L_94 ) ;
V_6 -> V_152 |= V_193 ;
}
else
V_6 -> V_152 &= ~ V_193 ;
}
} else {
V_2 -> V_194 = L_95 ;
V_2 -> V_195 = V_196 ;
F_6 ( V_2 , L_96 ,
V_2 -> V_194 ) ;
V_2 -> V_197 ( V_6 ) ;
F_32 ( V_6 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_197 = NULL ;
}
}
F_6 ( V_2 , L_97 , V_92 ) ;
return ( V_92 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_1 * V_2 ,
union V_40 * V_96 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
T_1 * V_86 = V_6 -> V_86 ;
int V_198 = 1 ;
unsigned char V_199 , V_200 ;
unsigned short V_201 ;
unsigned long V_202 ;
unsigned long V_203 ;
unsigned char V_204 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memset ( V_96 , 0 , sizeof( union V_40 ) ) ;
switch ( V_4 -> V_45 [ 0 ] ) {
case V_109 :
F_6 ( V_2 , L_98 ) ;
F_34 ( ( unsigned char * ) & V_6 -> V_182 ,
sizeof( V_6 -> V_182 ) , V_4 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
break;
case V_110 :
F_6 ( V_2 , L_99 ) ;
F_34 ( V_204 , sizeof( V_204 ) , V_4 ) ;
if ( V_6 -> V_152 & V_193 )
{
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 = V_80 ;
V_96 -> V_70 . V_82 = V_205 ;
F_4 ( V_4 , 0 ) ;
} else {
F_6 ( V_2 , L_100 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
}
break;
case V_206 :
F_6 ( V_2 , L_101 ) ;
if ( V_6 -> V_152 & V_193 )
{
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 = V_80 ;
V_96 -> V_70 . V_82 = V_205 ;
F_4 ( V_4 , 0 ) ;
} else {
F_6 ( V_2 , L_100 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
}
break;
case V_207 :
{
unsigned long V_208 ;
struct V_209 V_210 ;
F_6 ( V_2 , L_102 ) ;
if ( F_35 ( V_86 ) )
V_208 = F_29 ( V_86 , V_177 ) - 1 ;
else
V_208 = ( V_86 [ V_161 ] * V_86 [ V_160 ] *
V_86 [ V_162 ] ) - 1 ;
V_210 . V_211 = F_36 ( V_208 ) ;
V_210 . V_212 = F_36 ( 0x200 ) ;
F_34 ( ( unsigned char * ) & V_210 ,
sizeof( V_210 ) , V_4 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
}
break;
case V_213 :
F_6 ( V_2 , L_103 ) ;
V_202 = F_37 ( * ( V_214 * ) & V_4 -> V_45 [ 2 ] ) ;
V_203 = ( unsigned long ) V_4 -> V_45 [ 7 ] << 8 | ( unsigned long ) V_4 -> V_45 [ 8 ] ;
if ( F_35 ( V_86 ) ) {
V_199 = ( unsigned char ) ( V_202 ) ;
V_201 = ( unsigned short ) ( V_202 >> 8 ) ;
V_200 = V_215 | ( unsigned char ) ( V_202 >> 24 & 0x0F ) ;
} else {
V_199 = ( V_216 ) ( ( V_202 % V_86 [ V_162 ] ) + 1 ) ;
V_201 = ( T_1 ) ( V_202 / ( V_86 [ V_162 ] *
V_86 [ V_161 ] ) ) ;
V_200 = ( V_216 ) ( ( V_202 / V_86 [ V_162 ] ) %
V_86 [ V_161 ] ) ;
}
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 =
V_217 | V_218 |
V_59 | V_60 |
V_69 | V_80 ;
V_96 -> V_70 . V_219 = ( unsigned char ) V_203 ;
V_96 -> V_70 . V_220 = V_199 ;
V_96 -> V_70 . V_221 = ( unsigned char ) ( V_201 >> 8 ) ;
V_96 -> V_70 . V_222 = ( unsigned char ) V_201 ;
V_96 -> V_70 . V_71 = ( V_200 | V_148 ) ;
V_96 -> V_70 . V_82 = V_223 ;
break;
case V_224 :
F_6 ( V_2 , L_104 ) ;
V_202 = F_37 ( * ( V_214 * ) & V_4 -> V_45 [ 2 ] ) ;
V_203 = ( unsigned long ) V_4 -> V_45 [ 7 ] << 8 | ( unsigned long ) V_4 -> V_45 [ 8 ] ;
if ( F_35 ( V_86 ) ) {
V_199 = ( unsigned char ) ( V_202 ) ;
V_201 = ( unsigned short ) ( V_202 >> 8 ) ;
V_200 = V_215 | ( unsigned char ) ( V_202 >> 24 & 0x0F ) ;
} else {
V_199 = ( V_216 ) ( ( V_202 % V_86 [ V_162 ] ) + 1 ) ;
V_201 = ( T_1 ) ( V_202 / ( V_86 [ V_162 ] *
V_86 [ V_161 ] ) ) ;
V_200 = ( V_216 ) ( ( V_202 / V_86 [ V_162 ] ) %
V_86 [ V_161 ] ) ;
}
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 =
V_217 | V_218 |
V_59 | V_60 |
V_69 | V_80 ;
V_96 -> V_70 . V_219 = ( unsigned char ) V_203 ;
V_96 -> V_70 . V_220 = V_199 ;
V_96 -> V_70 . V_221 = ( unsigned char ) ( V_201 >> 8 ) ;
V_96 -> V_70 . V_222 = ( unsigned char ) V_201 ;
V_96 -> V_70 . V_71 = ( V_200 | V_148 ) ;
V_96 -> V_70 . V_82 = V_225 ;
break;
case V_226 :
F_6 ( V_2 , L_105 ) ;
if ( V_6 -> V_152 & V_189 ) {
F_6 ( V_2 , L_106 ,
V_4 -> V_45 [ 4 ] ) ;
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 = V_80 ;
V_96 -> V_70 . V_82 = ( V_4 -> V_45 [ 4 ] & 0x1 ) ?
V_227 : V_228 ;
F_4 ( V_4 , 0 ) ;
} else {
F_6 ( V_2 , L_107 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
}
break;
case V_229 :
F_6 ( V_2 , L_108 ) ;
F_6 ( V_2 , L_106 , V_4 -> V_45 [ 4 ] ) ;
if ( ( V_4 -> V_45 [ 4 ] & 0x3 ) == 0x2 ) {
F_6 ( V_2 , L_109 ) ;
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 0 ;
V_96 -> V_47 . V_58 = V_80 ;
V_96 -> V_70 . V_82 = V_230 ;
} else if ( ( V_4 -> V_45 [ 4 ] & 0x3 ) == 0x1 ) {
F_6 ( V_2 , L_110 ) ;
V_96 -> V_47 . V_48 = V_6 -> V_49 . V_50 ;
V_96 -> V_47 . V_51 = V_6 -> V_49 . V_52 ;
V_96 -> V_47 . V_53 = 1 ;
V_96 -> V_47 . V_58 = V_80 ;
V_96 -> V_70 . V_82 = V_205 ;
F_4 ( V_4 , 0 ) ;
} else {
F_6 ( V_2 , L_111 ) ;
V_4 -> V_98 = V_102 ;
V_198 = 0 ;
}
break;
default:
F_6 ( V_2 , L_112 ,
V_4 -> V_45 [ 0 ] ) ;
V_4 -> V_98 = V_107 << 16 ;
V_198 = 0 ;
break;
}
return ( V_198 ) ;
}
static void F_38 ( void * V_231 )
{
struct V_5 * V_6 = (struct V_5 * ) V_231 ;
if ( V_6 ) {
F_32 ( V_6 -> V_86 ) ;
F_32 ( V_6 -> V_94 ) ;
F_32 ( V_6 -> V_4 . V_10 ) ;
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
struct V_5 * V_6 ;
V_6 = F_40 ( sizeof( struct V_5 ) , V_232 ) ;
if ( ! V_6 )
V_92 = V_88 ;
else {
V_6 -> V_86 = F_40 ( V_87 * 2 , V_232 ) ;
V_6 -> V_94 = F_41 ( sizeof( V_6 -> V_11 ) , V_232 ) ;
V_6 -> V_4 . V_10 =
F_41 ( V_233 , V_232 ) ;
if ( ! V_6 -> V_86 || ! V_6 -> V_94 || ! V_6 -> V_4 . V_10 ) {
F_38 ( V_6 ) ;
F_32 ( V_6 ) ;
V_92 = V_88 ;
}
}
if ( V_92 == V_91 ) {
V_2 -> V_7 = V_6 ;
V_2 -> V_197 = F_38 ;
}
return V_92 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_6 ( V_2 , L_113 ) ;
if ( F_39 ( V_2 ) == V_88 ) {
F_6 ( V_2 , L_114 ) ;
} else {
if ( F_30 ( V_2 ) != V_91 )
F_6 ( V_2 , L_115 ) ;
else
F_6 ( V_2 , L_116 ) ;
}
return 0 ;
}
static void F_43 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_198 = 1 , V_234 ;
union V_40 V_96 ;
if ( V_2 -> V_7 == NULL )
F_6 ( V_2 , L_117 ) ;
F_44 ( V_4 , 0 ) ;
V_234 = F_45 ( V_4 ) ;
V_198 = F_33 ( V_4 , V_2 , & V_96 ) ;
if ( V_198 )
F_9 ( V_2 , V_4 , & V_96 ) ;
F_4 ( V_4 , V_234 ) ;
}
static int F_46 ( struct V_235 * V_236 ,
const struct V_237 * V_86 )
{
struct V_1 * V_2 ;
int V_98 ;
V_98 = F_47 ( & V_2 , V_236 , V_86 ,
( V_86 - V_238 ) + V_239 ,
& V_240 ) ;
if ( V_98 )
return V_98 ;
V_2 -> V_194 = L_118 ;
V_2 -> V_195 = F_43 ;
V_98 = F_48 ( V_2 ) ;
return V_98 ;
}
