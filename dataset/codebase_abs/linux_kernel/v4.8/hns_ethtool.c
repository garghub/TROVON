static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_4 -> V_6 ;
struct V_7 * V_8 ;
V_8 = V_4 -> V_9 ;
if ( V_4 -> V_10 ) {
if ( ! F_3 ( V_4 -> V_10 ) )
V_5 = V_4 -> V_10 -> V_6 ;
else
V_5 = 0 ;
}
if ( V_8 -> V_11 && V_8 -> V_11 -> V_12 && V_8 -> V_11 -> V_12 -> V_13 )
V_5 = V_5 && V_8 -> V_11 -> V_12 -> V_13 ( V_8 ) ;
else
V_5 = 0 ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_16 , V_17 , V_18 , V_19 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
if ( ! V_21 || ! V_21 -> V_22 . V_23 ) {
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_25 ;
return;
}
F_5 ( V_21 , V_27 , V_28 ) ;
V_18 = F_6 ( V_21 , V_29 ) ;
V_16 = F_7 ( V_18 , V_30 , V_31 ) ;
V_18 = F_6 ( V_21 , V_32 ) ;
V_17 = F_8 ( V_18 , V_33 ) ;
V_19 = F_8 ( V_18 , V_34 ) ;
F_5 ( V_21 , V_27 , V_35 ) ;
switch ( V_16 ) {
case 0x0 :
V_15 -> V_24 = V_36 ;
break;
case 0x1 :
V_15 -> V_24 = V_37 ;
break;
case 0x3 :
V_15 -> V_24 = V_38 ;
break;
default:
V_15 -> V_24 = V_25 ;
break;
}
if ( ! V_19 )
V_15 -> V_26 = V_25 ;
else if ( V_17 )
V_15 -> V_26 = V_37 ;
else
V_15 -> V_26 = V_36 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_5 ;
int V_39 ;
T_2 V_40 ;
T_3 V_41 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_42 ;
V_8 = V_4 -> V_9 ;
if ( ! V_8 -> V_11 || ! V_8 -> V_11 -> V_12 || ! V_8 -> V_11 -> V_12 -> V_43 )
return - V_42 ;
V_39 = V_8 -> V_11 -> V_12 -> V_43 ( V_8 , NULL , & V_41 , & V_40 ) ;
if ( V_39 < 0 ) {
F_10 ( V_2 , L_1 , V_44 ) ;
return - V_45 ;
}
V_15 -> V_46 = false ;
F_11 ( V_15 , V_41 ) ;
V_15 -> V_40 = V_40 ;
if ( V_4 -> V_10 )
( void ) F_12 ( V_4 -> V_10 , V_15 ) ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 ) {
F_11 ( V_15 , ( T_1 ) V_47 ) ;
V_15 -> V_40 = V_48 ;
}
if ( V_15 -> V_46 )
V_15 -> V_49 |= V_50 ;
V_15 -> V_51 |= V_8 -> V_52 ;
if ( V_8 -> V_53 == V_54 ) {
V_15 -> V_51 |= V_55 ;
V_15 -> V_49 |= V_56 ;
} else if ( V_8 -> V_53 == V_57 ) {
V_15 -> V_51 |= V_58 ;
V_15 -> V_49 |= V_59 ;
}
switch ( V_8 -> V_60 ) {
case V_61 :
V_15 -> V_62 = V_63 ;
break;
case V_64 :
V_15 -> V_62 = V_65 ;
break;
case V_66 :
default:
break;
}
if ( ! ( F_13 ( V_4 -> V_67 ) && V_8 -> V_68 == V_69 ) )
V_15 -> V_51 |= V_70 ;
V_15 -> V_71 = V_72 ;
V_15 -> V_73 = ( V_74 | V_75 ) ;
F_4 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_41 ;
if ( ! F_15 ( V_2 ) )
return - V_42 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_9 -> V_11 ||
! V_4 -> V_9 -> V_11 -> V_12 )
return - V_76 ;
V_8 = V_4 -> V_9 ;
V_41 = F_16 ( V_15 ) ;
if ( V_8 -> V_53 == V_57 ) {
if ( V_15 -> V_46 == V_77 || V_41 != V_78 ||
V_15 -> V_40 != V_79 )
return - V_45 ;
} else if ( V_8 -> V_53 == V_54 ) {
if ( ! V_4 -> V_10 && V_15 -> V_46 == V_77 )
return - V_45 ;
if ( V_41 == V_80 && V_15 -> V_40 == V_81 )
return - V_45 ;
if ( V_4 -> V_10 )
return F_17 ( V_4 -> V_10 , V_15 ) ;
if ( ( V_41 != V_82 && V_41 != V_83 &&
V_41 != V_80 ) || ( V_15 -> V_40 != V_81 &&
V_15 -> V_40 != V_79 ) )
return - V_45 ;
} else {
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
if ( V_8 -> V_11 -> V_12 -> V_85 ) {
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , ( int ) V_41 , V_15 -> V_40 ) ;
return 0 ;
}
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
static int F_18 ( struct V_20 * V_21 , T_2 V_86 )
{
#define F_19 0
#define F_20 BIT(11)
#define F_21 BIT(14)
T_3 V_87 = 0 ;
if ( V_21 -> V_88 )
return - V_84 ;
if ( V_86 ) {
F_5 ( V_21 , V_27 , 2 ) ;
F_5 ( V_21 , 21 , 0x1046 ) ;
F_5 ( V_21 , V_27 , 0 ) ;
F_5 ( V_21 , 9 , 0x1F00 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , 0 , 0x9140 ) ;
F_5 ( V_21 , V_27 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x418 ) ;
F_5 ( V_21 , 7 , 0x20C ) ;
F_5 ( V_21 , V_27 , 0 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 |= F_21 ;
V_87 &= ~ F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
} else {
F_5 ( V_21 , V_27 , 0xFA ) ;
F_5 ( V_21 , 1 , 0x400 ) ;
F_5 ( V_21 , 7 , 0x200 ) ;
F_5 ( V_21 , V_27 , 0 ) ;
F_5 ( V_21 , 9 , 0xF00 ) ;
V_87 = F_6 ( V_21 , F_19 ) ;
V_87 &= ~ F_21 ;
V_87 |= F_20 ;
F_5 ( V_21 , F_19 , V_87 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_89 ,
enum V_90 V_91 )
{
int V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
struct V_7 * V_8 = V_4 -> V_9 ;
switch ( V_91 ) {
case V_92 :
if ( ( V_21 ) && ( ! V_21 -> V_88 ) ) {
V_39 = F_18 ( V_21 , 0x1 ) ;
V_39 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
}
break;
case V_94 :
if ( ( V_8 -> V_11 -> V_12 -> V_93 ) &&
( V_4 -> V_9 -> V_53 != V_57 ) )
V_39 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_95 :
if ( V_8 -> V_11 -> V_12 -> V_93 )
V_39 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_96 :
if ( ( V_21 ) && ( ! V_21 -> V_88 ) )
V_39 |= F_18 ( V_21 , 0x0 ) ;
if ( V_8 -> V_11 -> V_12 -> V_93 ) {
if ( V_4 -> V_9 -> V_53 != V_57 )
V_39 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_94 , 0x0 ) ;
V_39 |= V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_95 , 0x0 ) ;
}
break;
default:
V_39 = - V_45 ;
break;
}
return V_39 ;
}
static int F_23 ( struct V_1 * V_89 ,
enum V_90 V_97 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_41 , V_40 ;
int V_39 ;
F_24 ( V_89 ) ;
V_39 = F_22 ( V_89 , V_97 ) ;
if ( V_39 )
return V_39 ;
F_25 ( 200 ) ;
V_39 = V_8 -> V_11 -> V_12 -> V_98 ? V_8 -> V_11 -> V_12 -> V_98 ( V_8 ) : 0 ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_9 -> V_53 != V_57 )
V_41 = 1000 ;
else
V_41 = 10000 ;
V_40 = 1 ;
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , V_41 , V_40 ) ;
return 0 ;
}
static void F_26 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_1 * V_89 ;
struct V_3 * V_4 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_101 * V_107 ;
unsigned int V_108 ;
int V_109 ;
T_1 V_110 ;
char V_111 [ 33 ] ;
if ( ! V_100 ) {
V_89 = V_102 -> V_11 ;
V_4 = F_2 ( V_89 ) ;
V_108 = V_102 -> V_112 ;
memset ( V_102 -> V_113 , 0xFF , V_108 ) ;
if ( ( ! F_13 ( V_4 -> V_67 ) ) &&
( V_4 -> V_9 -> V_68 == V_114 ) ) {
memcpy ( V_102 -> V_113 , V_89 -> V_115 , 6 ) ;
V_102 -> V_113 [ 5 ] += 0x1f ;
}
V_108 &= ~ 1ul ;
memset ( & V_102 -> V_113 [ V_108 / 2 ] , 0xAA , V_108 / 2 - 1 ) ;
memset ( & V_102 -> V_113 [ V_108 / 2 + 10 ] , 0xBE ,
V_108 / 2 - 11 ) ;
memset ( & V_102 -> V_113 [ V_108 / 2 + 12 ] , 0xAF ,
V_108 / 2 - 13 ) ;
return;
}
V_104 = V_100 -> V_104 ;
V_89 = V_100 -> V_116 . V_11 ;
if ( F_27 ( V_104 ) ) {
V_106 = F_28 ( V_89 , V_100 -> V_117 ) ;
F_29 ( V_106 ) ;
return;
}
V_108 = V_102 -> V_112 ;
V_108 &= ~ 1ul ;
V_107 = F_30 ( V_102 , V_118 ) ;
F_31 ( V_102 ) ;
V_102 = V_107 ;
V_109 = 0 ;
if ( * ( V_102 -> V_113 + 10 ) == 0xFF ) {
if ( ( * ( V_102 -> V_113 + V_108 / 2 + 10 ) == 0xBE ) &&
( * ( V_102 -> V_113 + V_108 / 2 + 12 ) == 0xAF ) )
V_109 = 1 ;
}
if ( V_109 ) {
V_89 -> V_119 . V_120 ++ ;
V_89 -> V_119 . V_121 += V_102 -> V_112 ;
} else {
V_89 -> V_119 . V_122 ++ ;
for ( V_110 = 0 ; V_110 < V_102 -> V_112 ; V_110 ++ ) {
snprintf ( V_111 + V_110 % 16 * 2 , 3 ,
L_3 , * ( V_102 -> V_113 + V_110 ) ) ;
if ( ( V_110 % 16 == 15 ) || ( V_110 == V_102 -> V_112 - 1 ) )
F_32 ( L_4 , V_111 ) ;
}
}
F_31 ( V_102 ) ;
}
static int F_33 ( struct V_3 * V_4 ,
int V_123 , int V_124 , int V_125 )
{
int V_110 , V_39 ;
struct V_99 * V_100 ;
struct V_1 * V_89 = V_4 -> V_126 ;
unsigned long V_120 = V_89 -> V_119 . V_120 ;
unsigned long V_121 = V_89 -> V_119 . V_121 ;
unsigned long V_122 = V_89 -> V_119 . V_122 ;
for ( V_110 = V_123 ; V_110 <= V_124 ; V_110 ++ ) {
V_100 = & V_4 -> V_100 [ V_110 ] ;
( void ) V_100 -> V_127 ( V_100 ,
V_125 , F_26 ) ;
}
V_39 = ( int ) ( V_89 -> V_119 . V_120 - V_120 ) ;
V_89 -> V_119 . V_120 = V_120 ;
V_89 -> V_119 . V_121 = V_121 ;
V_89 -> V_119 . V_122 = V_122 ;
return V_39 ;
}
static int F_34 ( struct V_1 * V_89 ,
enum V_90 V_97 )
{
#define F_35 1
#define F_36 0
#define F_37 128
#define F_38 1
#define F_39 2
#define F_40 3
#define F_41 4
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_110 , V_128 , V_129 , V_130 , V_131 = 0 ;
unsigned int V_132 ;
T_4 V_133 ;
struct V_101 * V_102 ;
V_132 = F_37 ;
V_102 = F_42 ( V_132 , V_134 ) ;
if ( ! V_102 )
return F_38 ;
( void ) F_43 ( V_102 , V_132 ) ;
V_102 -> V_11 = V_89 ;
F_26 ( NULL , V_102 ) ;
V_102 -> V_135 = F_36 ;
V_129 = 1 ;
for ( V_128 = 0 ; V_128 < V_129 ; V_128 ++ ) {
V_130 = 0 ;
for ( V_110 = 0 ; V_110 < F_35 ; V_110 ++ ) {
( void ) F_44 ( V_102 ) ;
V_133 = ( T_4 ) F_45 (
V_89 , V_102 ,
& F_46 ( V_4 , V_102 -> V_135 ) ) ;
if ( V_133 == V_136 )
V_130 ++ ;
else
break;
}
if ( V_130 != F_35 ) {
V_131 = F_39 ;
F_47 ( V_4 -> V_11 , L_5 ,
V_137 [ V_97 ] , V_130 ,
F_35 ) ;
break;
}
F_25 ( 100 ) ;
V_130 = F_33 ( V_4 ,
V_8 -> V_138 , V_8 -> V_138 * 2 - 1 ,
F_35 ) ;
if ( V_130 != F_35 ) {
V_131 = F_40 ;
F_47 ( V_4 -> V_11 , L_6 ,
V_137 [ V_97 ] , V_130 ,
F_35 ) ;
break;
}
( void ) F_33 ( V_4 ,
F_36 , F_36 ,
F_35 ) ;
}
F_48 ( V_102 ) ;
return V_131 ;
}
static int F_49 ( struct V_1 * V_89 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_39 ;
V_39 = F_22 ( V_89 , V_96 ) ;
if ( V_39 )
F_10 ( V_89 , L_7 ,
V_44 ,
V_39 ) ;
if ( V_8 -> V_11 -> V_12 -> V_139 )
V_8 -> V_11 -> V_12 -> V_139 ( V_8 ) ;
F_50 ( 10000 , 20000 ) ;
( void ) F_33 ( V_4 , 0 , V_8 -> V_138 - 1 , 256 ) ;
F_24 ( V_89 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_89 ,
struct V_140 * V_141 , T_5 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
bool V_142 = F_15 ( V_89 ) ;
#define F_52 3
int V_143 [ F_52 ] [ 2 ] ;
int V_110 ;
int V_144 = 0 ;
V_143 [ 0 ] [ 0 ] = V_94 ;
V_143 [ 0 ] [ 1 ] = ( V_4 -> V_9 -> V_53 != V_57 ) ;
V_143 [ 1 ] [ 0 ] = V_95 ;
V_143 [ 1 ] [ 1 ] = 1 ;
V_143 [ 2 ] [ 0 ] = V_92 ;
V_143 [ 2 ] [ 1 ] = ( ( ! ! ( V_4 -> V_9 -> V_21 ) ) &&
( V_4 -> V_9 -> V_53 != V_57 ) ) ;
if ( V_141 -> V_145 == V_146 ) {
F_53 ( V_147 , & V_4 -> V_148 ) ;
if ( V_142 )
( void ) F_54 ( V_89 ) ;
for ( V_110 = 0 ; V_110 < F_52 ; V_110 ++ ) {
if ( ! V_143 [ V_110 ] [ 1 ] )
continue;
V_113 [ V_144 ] = F_23 ( V_89 ,
(enum V_90 ) V_143 [ V_110 ] [ 0 ] ) ;
if ( ! V_113 [ V_144 ] ) {
V_113 [ V_144 ] = F_34 (
V_89 , (enum V_90 ) V_143 [ V_110 ] [ 0 ] ) ;
( void ) F_49 ( V_89 ) ;
}
if ( V_113 [ V_144 ] )
V_141 -> V_145 |= V_149 ;
V_144 ++ ;
}
F_24 ( V_4 -> V_126 ) ;
F_55 ( V_147 , & V_4 -> V_148 ) ;
if ( V_142 )
( void ) F_56 ( V_89 ) ;
}
( void ) F_57 ( 4 * 1000 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
strncpy ( V_151 -> V_152 , V_153 ,
sizeof( V_151 -> V_152 ) ) ;
V_151 -> V_152 [ sizeof( V_151 -> V_152 ) - 1 ] = '\0' ;
strncpy ( V_151 -> V_154 , V_155 , sizeof( V_151 -> V_154 ) ) ;
V_151 -> V_154 [ sizeof( V_151 -> V_154 ) - 1 ] = '\0' ;
strncpy ( V_151 -> V_156 , V_4 -> V_11 -> V_23 -> V_157 ,
sizeof( V_151 -> V_156 ) ) ;
V_151 -> V_156 [ V_158 - 1 ] = '\0' ;
strncpy ( V_151 -> V_159 , L_8 , V_160 ) ;
V_151 -> V_161 = 0 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
struct V_165 * V_166 ;
T_1 V_167 = 0 ;
V_166 = V_4 -> V_9 -> V_168 [ 0 ] ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_169 )
V_12 -> V_169 ( V_166 , & V_167 ) ;
V_163 -> V_170 = V_167 ;
V_163 -> V_171 = V_167 ;
V_163 -> V_172 = V_166 -> V_173 . V_174 ;
V_163 -> V_175 = V_166 -> V_176 . V_174 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_177 * V_163 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_178 )
V_12 -> V_178 ( V_4 -> V_9 , & V_163 -> V_46 ,
& V_163 -> V_179 , & V_163 -> V_180 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_177 * V_163 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_164 * V_12 ;
V_8 = V_4 -> V_9 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_181 )
return - V_42 ;
return V_12 -> V_181 ( V_4 -> V_9 , V_163 -> V_46 ,
V_163 -> V_179 , V_163 -> V_180 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_183 -> V_184 = 1 ;
V_183 -> V_185 = 1 ;
if ( ( ! V_12 -> V_186 ) ||
( ! V_12 -> V_187 ) )
return - V_42 ;
V_12 -> V_186 ( V_4 -> V_9 ,
& V_183 -> V_188 ,
& V_183 -> V_189 ) ;
V_12 -> V_187 (
V_4 -> V_9 ,
& V_183 -> V_190 ,
& V_183 -> V_191 ) ;
V_12 -> V_192 ( V_4 -> V_9 ,
& V_183 -> V_193 ,
& V_183 -> V_194 ,
& V_183 -> V_195 ,
& V_183 -> V_196 ,
& V_183 -> V_197 ,
& V_183 -> V_198 ,
& V_183 -> V_199 ,
& V_183 -> V_200 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
int V_39 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_183 -> V_188 != V_183 -> V_189 )
return - V_45 ;
if ( V_183 -> V_191 != V_183 -> V_190 )
return - V_45 ;
if ( ( ! V_12 -> V_201 ) ||
( ! V_12 -> V_202 ) )
return - V_42 ;
V_39 = V_12 -> V_201 ( V_4 -> V_9 ,
V_183 -> V_189 ) ;
if ( V_39 )
return V_39 ;
V_39 = V_12 -> V_202 (
V_4 -> V_9 ,
V_183 -> V_191 ) ;
return V_39 ;
}
void F_64 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_204 -> V_205 = V_4 -> V_9 -> V_138 ;
V_204 -> V_206 = V_4 -> V_9 -> V_138 ;
V_204 -> V_207 = V_4 -> V_9 -> V_138 ;
V_204 -> V_208 = V_4 -> V_9 -> V_138 ;
}
void F_65 ( struct V_1 * V_126 ,
struct V_209 * V_119 , T_5 * V_113 )
{
T_5 * V_210 = V_113 ;
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
const struct V_211 * V_212 ;
struct V_211 V_213 ;
if ( ! V_8 -> V_11 -> V_12 -> V_214 || ! V_8 -> V_11 -> V_12 -> V_215 ) {
F_10 ( V_126 , L_9 ) ;
return;
}
V_8 -> V_11 -> V_12 -> V_215 ( V_8 , & V_126 -> V_119 ) ;
V_212 = F_66 ( V_126 , & V_213 ) ;
V_210 [ 0 ] = V_212 -> V_120 ;
V_210 [ 1 ] = V_212 -> V_216 ;
V_210 [ 2 ] = V_212 -> V_121 ;
V_210 [ 3 ] = V_212 -> V_217 ;
V_210 [ 4 ] = V_212 -> V_218 ;
V_210 [ 5 ] = V_212 -> V_219 ;
V_210 [ 6 ] = V_212 -> V_220 ;
V_210 [ 7 ] = V_212 -> V_221 ;
V_210 [ 8 ] = V_212 -> V_222 ;
V_210 [ 9 ] = V_212 -> V_223 ;
V_210 [ 10 ] = V_212 -> V_224 ;
V_210 [ 11 ] = V_212 -> V_225 ;
V_210 [ 12 ] = V_212 -> V_122 ;
V_210 [ 13 ] = V_212 -> V_226 ;
V_210 [ 14 ] = V_212 -> V_227 ;
V_210 [ 15 ] = V_212 -> V_228 ;
V_210 [ 16 ] = V_212 -> V_229 ;
V_210 [ 17 ] = V_212 -> V_230 ;
V_210 [ 18 ] = V_212 -> V_231 ;
V_210 [ 19 ] = V_212 -> V_232 ;
V_210 [ 20 ] = V_212 -> V_233 ;
V_210 [ 21 ] = V_212 -> V_234 ;
V_210 [ 22 ] = V_212 -> V_235 ;
V_210 [ 23 ] = V_126 -> V_220 . V_236 ;
V_210 [ 24 ] = V_126 -> V_221 . V_236 ;
V_210 [ 25 ] = V_4 -> V_237 ;
V_8 -> V_11 -> V_12 -> V_214 ( V_8 , & V_210 [ 26 ] ) ;
}
void F_67 ( struct V_1 * V_126 , T_1 V_238 , T_2 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
char * V_111 = ( char * ) V_113 ;
if ( ! V_8 -> V_11 -> V_12 -> V_239 ) {
F_10 ( V_126 , L_10 ) ;
return;
}
if ( V_238 == V_240 ) {
if ( V_4 -> V_9 -> V_53 != V_57 ) {
memcpy ( V_111 , V_137 [ V_94 ] ,
V_241 ) ;
V_111 += V_241 ;
}
memcpy ( V_111 , V_137 [ V_95 ] ,
V_241 ) ;
V_111 += V_241 ;
if ( ( V_4 -> V_10 ) && ( ! V_4 -> V_10 -> V_88 ) )
memcpy ( V_111 , V_137 [ V_92 ] ,
V_241 ) ;
} else {
snprintf ( V_111 , V_241 , L_11 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_12 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_13 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_14 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_15 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_16 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_17 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_18 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_19 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_20 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_21 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_22 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_23 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_24 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_25 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_26 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_27 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_28 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_29 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_30 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_31 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_32 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_33 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_34 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_35 ) ;
V_111 = V_111 + V_241 ;
snprintf ( V_111 , V_241 , L_36 ) ;
V_111 = V_111 + V_241 ;
V_8 -> V_11 -> V_12 -> V_239 ( V_8 , V_238 , ( T_2 * ) V_111 ) ;
}
}
int F_68 ( struct V_1 * V_126 , int V_238 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_164 * V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_242 ) {
F_10 ( V_126 , L_37 ) ;
return - V_243 ;
}
if ( V_238 == V_240 ) {
T_1 V_244 = ( sizeof( V_137 ) / V_241 ) ;
if ( V_4 -> V_9 -> V_53 == V_57 )
V_244 -- ;
if ( ( ! V_4 -> V_10 ) || ( V_4 -> V_10 -> V_88 ) )
V_244 -- ;
return V_244 ;
} else {
return ( V_245 + V_12 -> V_242 ( V_8 , V_238 ) ) ;
}
}
int F_69 ( struct V_1 * V_126 , int V_246 )
{
int V_18 ;
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_20 * V_21 = V_4 -> V_10 ;
V_18 = F_5 ( V_21 , V_27 , V_247 ) ;
V_18 |= F_5 ( V_21 , V_248 , V_246 ) ;
V_18 |= F_5 ( V_21 , V_27 , V_35 ) ;
if ( V_18 ) {
F_10 ( V_126 , L_38 ) ;
return V_18 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_126 , enum V_249 V_148 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_20 * V_21 = V_4 -> V_10 ;
int V_39 ;
if ( V_21 )
switch ( V_148 ) {
case V_250 :
V_39 = F_5 ( V_21 , V_27 ,
V_247 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_251 = F_6 ( V_21 , V_248 ) ;
V_39 = F_5 ( V_21 , V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
return 2 ;
case V_252 :
V_39 = F_69 ( V_126 , V_253 ) ;
if ( V_39 )
return V_39 ;
break;
case V_254 :
V_39 = F_69 ( V_126 , V_255 ) ;
if ( V_39 )
return V_39 ;
break;
case V_256 :
V_39 = F_5 ( V_21 , V_27 ,
V_247 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 , V_248 ,
V_4 -> V_251 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_5 ( V_21 , V_27 ,
V_35 ) ;
if ( V_39 )
return V_39 ;
break;
default:
return - V_45 ;
}
else
switch ( V_148 ) {
case V_250 :
return V_8 -> V_11 -> V_12 -> V_257 ( V_8 , V_258 ) ;
case V_252 :
return V_8 -> V_11 -> V_12 -> V_257 ( V_8 , V_259 ) ;
case V_254 :
return V_8 -> V_11 -> V_12 -> V_257 ( V_8 , V_260 ) ;
case V_256 :
return V_8 -> V_11 -> V_12 -> V_257 ( V_8 , V_261 ) ;
default:
return - V_45 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , struct V_262 * V_15 ,
void * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_15 -> V_152 = V_263 ;
if ( ! V_12 -> V_264 ) {
F_10 ( V_2 , L_39 ) ;
return;
}
V_12 -> V_264 ( V_4 -> V_9 , V_113 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_1 V_265 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_164 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_12 -> V_266 ) {
F_10 ( V_2 , L_40 ) ;
return - V_243 ;
}
V_265 = V_12 -> V_266 ( V_4 -> V_9 ) ;
if ( V_265 > 0 )
return V_265 * sizeof( T_1 ) ;
else
return V_265 ;
}
static int F_73 ( struct V_1 * V_126 )
{
int V_39 = 0 ;
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_20 * V_10 = V_4 -> V_10 ;
if ( F_15 ( V_126 ) ) {
if ( V_10 )
V_39 = F_74 ( V_10 ) ;
}
return V_39 ;
}
static T_1
F_75 ( struct V_1 * V_126 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_164 * V_12 ;
if ( F_13 ( V_4 -> V_67 ) ) {
F_10 ( V_126 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_267 ( V_4 -> V_9 ) ;
}
static T_1
F_76 ( struct V_1 * V_126 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_164 * V_12 ;
if ( F_13 ( V_4 -> V_67 ) ) {
F_10 ( V_126 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_268 ( V_4 -> V_9 ) ;
}
static int
F_77 ( struct V_1 * V_126 , T_1 * V_269 , T_2 * V_270 , T_2 * V_271 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_164 * V_12 ;
if ( F_13 ( V_4 -> V_67 ) ) {
F_10 ( V_126 ,
L_41 ) ;
return - V_243 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_269 )
return 0 ;
return V_12 -> V_272 ( V_4 -> V_9 , V_269 , V_270 , V_271 ) ;
}
static int
F_78 ( struct V_1 * V_126 , const T_1 * V_269 , const T_2 * V_270 ,
const T_2 V_271 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
struct V_164 * V_12 ;
if ( F_13 ( V_4 -> V_67 ) ) {
F_10 ( V_126 ,
L_41 ) ;
return - V_243 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_270 ||
( V_271 != V_273 && V_271 != V_274 ) )
return - V_243 ;
if ( ! V_269 )
return 0 ;
return V_12 -> V_275 ( V_4 -> V_9 , V_269 , V_270 , V_271 ) ;
}
static int F_79 ( struct V_1 * V_126 ,
struct V_276 * V_15 ,
T_1 * V_277 )
{
struct V_3 * V_4 = F_2 ( V_126 ) ;
switch ( V_15 -> V_15 ) {
case V_278 :
V_15 -> V_113 = V_4 -> V_9 -> V_138 ;
break;
default:
return - V_243 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_89 )
{
V_89 -> V_279 = & V_280 ;
}
