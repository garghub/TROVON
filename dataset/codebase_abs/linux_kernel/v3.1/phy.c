enum V_1 F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static enum V_5
F_2 ( struct V_2 * V_3 ,
struct V_6 T_1 * V_7 )
{
T_2 V_8 ;
V_3 -> V_9 = V_7 ;
F_3 ( V_10 ,
& V_3 -> V_9 -> V_11 ) ;
V_8 = F_4 ( & V_3 -> V_9 -> V_12 ) ;
V_8 |= F_5 ( V_13 ) ;
F_3 ( V_8 , & V_3 -> V_9 -> V_12 ) ;
return V_14 ;
}
static enum V_5
F_6 ( struct V_2 * V_3 ,
struct V_15 T_1 * V_7 )
{
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
int V_20 = V_3 -> V_21 ;
struct V_22 * V_23 = & V_17 -> V_24 . V_25 [ V_20 ] ;
struct V_26 * V_27 =
& V_17 -> V_28 . V_25 [ V_20 ] ;
T_2 V_29 ;
struct V_30 V_31 ;
T_2 V_32 = 0 ;
T_2 V_33 = 0 ;
T_2 V_34 , V_35 ;
T_2 V_36 = 0 ;
T_2 V_37 = 0 ;
V_3 -> V_38 = V_7 ;
#define F_7 0x01
F_3 ( F_8 ( V_39 ) |
F_8 ( V_40 ) |
F_8 ( V_41 ) |
F_8 ( V_42 ) |
F_9 ( V_43 , F_7 ) ,
& V_3 -> V_38 -> V_44 ) ;
F_3 ( 0xFEDCBA98 ,
& V_3 -> V_38 -> V_45 ) ;
F_3 ( V_20 , & V_3 -> V_38 -> V_46 ) ;
F_3 ( V_27 -> V_47 . V_48 ,
& V_3 -> V_38 -> V_49 ) ;
F_3 ( V_27 -> V_47 . V_50 ,
& V_3 -> V_38 -> V_51 ) ;
F_3 ( 0 , & V_3 -> V_38 -> V_52 ) ;
F_3 ( F_10 ( V_53 , V_20 ) ,
& V_3 -> V_38 -> V_52 ) ;
V_29 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_29 |= F_11 ( V_54 ) ;
F_3 ( V_29 ,
& V_3 -> V_38 -> V_29 ) ;
V_31 . V_55 = 0 ;
V_31 . V_56 = 1 ;
V_31 . V_57 = 1 ;
V_31 . V_58 = 1 ;
V_31 . V_59 = 1 ;
if ( V_17 -> V_28 . V_60 . V_61 == true ) {
V_31 . V_62 = 1 ;
V_31 . V_63 = 1 ;
V_31 . V_64 = 1 ;
}
V_32 = V_31 . V_55 ;
while ( V_32 != 0 ) {
if ( V_32 & 0x1 )
V_33 ++ ;
V_32 >>= 1 ;
}
if ( ( V_33 % 2 ) != 0 )
V_31 . V_65 = 1 ;
F_3 ( V_31 . V_55 , & V_3 -> V_38 -> V_66 ) ;
F_3 ( F_12 ( V_67 ,
V_23 -> V_68 ) ,
& V_3 -> V_38 -> V_69 ) ;
V_36 = F_13 ( V_70 ,
V_23 -> V_71 ) ;
V_36 |= F_13 ( V_72 ,
V_23 -> V_73 ) ;
F_3 ( V_36 , & V_3 -> V_38 -> V_74 ) ;
F_3 ( 0x02108421 ,
& V_3 -> V_38 -> V_75 ) ;
V_34 = F_14 ( V_76 ,
( V_77 ) V_17 -> V_24 . V_78 ) ;
switch ( V_23 -> V_79 ) {
case V_80 :
V_35 = V_81 ;
break;
case V_82 :
V_35 = V_83 ;
break;
default:
V_35 = V_84 ;
break;
}
V_34 |= F_14 ( V_85 , V_35 ) ;
F_3 ( V_34 , & V_3 -> V_38 -> V_86 ) ;
V_37 = F_4 ( & V_3 -> V_38 -> V_87 ) ;
V_37 &= ~ F_15 ( V_88 , 0xFF ) ;
V_37 |= F_15 ( V_88 , 0x3B ) ;
F_3 ( V_37 , & V_3 -> V_38 -> V_87 ) ;
if ( F_16 ( V_17 -> V_89 ) ) {
F_3 ( V_90 ,
& V_3 -> V_38 -> V_91 ) ;
}
F_3 ( 0 , & V_3 -> V_38 -> V_92 ) ;
F_17 ( & V_3 -> V_93 , V_94 ) ;
return V_14 ;
}
static void F_18 ( unsigned long V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
struct V_2 * V_3 = F_19 ( V_97 , F_20 ( * V_3 ) , V_98 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
unsigned long V_99 ;
F_21 ( & V_17 -> V_100 , V_99 ) ;
if ( V_97 -> V_101 )
goto V_102;
F_22 ( F_23 ( V_3 ) ,
L_1
L_2 ,
V_103 ,
V_3 ) ;
F_17 ( & V_3 -> V_93 , V_104 ) ;
V_102:
F_24 ( & V_17 -> V_100 , V_99 ) ;
}
struct V_105 * F_25 ( struct V_2 * V_3 )
{
struct V_105 * V_106 = V_3 -> V_18 ;
if ( V_106 -> V_107 == V_108 )
return NULL ;
return V_3 -> V_18 ;
}
void F_26 (
struct V_2 * V_3 ,
struct V_105 * V_106 )
{
V_3 -> V_18 = V_106 ;
if ( V_3 -> V_109 ) {
V_3 -> V_109 = false ;
F_27 ( V_3 -> V_18 , V_3 ) ;
}
}
enum V_5 F_28 ( struct V_2 * V_3 ,
struct V_6 T_1 * V_110 ,
struct V_15 T_1 * V_111 )
{
F_2 ( V_3 , V_110 ) ;
F_6 ( V_3 , V_111 ) ;
F_17 ( & V_3 -> V_93 , V_94 ) ;
return V_14 ;
}
void F_29 ( struct V_2 * V_3 , T_2 V_112 )
{
T_2 V_8 ;
F_3 ( V_112 , & V_3 -> V_9 -> V_11 ) ;
V_8 = F_4 ( & V_3 -> V_9 -> V_12 ) ;
V_8 |= F_5 ( V_113 ) ;
F_3 ( V_8 , & V_3 -> V_9 -> V_12 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
T_2 V_114 ;
V_114 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_114 |= F_11 ( V_115 ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
F_29 ( V_3 , V_10 ) ;
}
void F_31 ( struct V_2 * V_3 )
{
T_2 V_114 ;
V_114 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_114 &= ~ F_11 ( V_115 ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
}
void F_32 ( struct V_2 * V_3 , struct V_116 * V_117 )
{
V_117 -> V_48 = F_4 ( & V_3 -> V_38 -> V_49 ) ;
V_117 -> V_50 = F_4 ( & V_3 -> V_38 -> V_51 ) ;
}
void F_33 ( struct V_2 * V_3 , struct V_116 * V_117 )
{
struct V_118 * V_119 ;
V_119 = & V_3 -> V_120 . V_119 ;
memcpy ( V_117 , V_119 -> V_121 , V_122 ) ;
}
void F_34 ( struct V_2 * V_3 , struct V_123 * V_124 )
{
V_124 -> V_55 = F_4 ( & V_3 -> V_38 -> V_44 ) ;
}
enum V_5 F_35 ( struct V_2 * V_3 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
if ( V_126 != V_94 ) {
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
F_17 ( & V_3 -> V_93 , V_104 ) ;
return V_14 ;
}
enum V_5 F_36 ( struct V_2 * V_3 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
switch ( V_126 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
break;
default:
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
F_17 ( & V_3 -> V_93 , V_94 ) ;
return V_14 ;
}
enum V_5 F_37 ( struct V_2 * V_3 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
if ( V_126 != V_138 ) {
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
F_17 ( & V_3 -> V_93 , V_139 ) ;
return V_14 ;
}
enum V_5 F_38 ( struct V_2 * V_3 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
switch ( V_126 ) {
case V_132 : {
T_2 V_140 ;
V_140 = F_4 ( & V_3 -> V_38 -> V_69 ) ;
V_140 |= F_39 ( V_141 ) ;
F_3 ( V_140 , & V_3 -> V_38 -> V_69 ) ;
F_17 ( & V_3 -> V_93 , V_137 ) ;
return V_14 ;
}
case V_133 : {
T_2 V_114 ;
V_114 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_114 &=
~ ( F_11 ( V_142 ) | F_11 ( V_143 ) ) ;
V_114 |= F_11 ( V_54 ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
V_114 &= ~ F_11 ( V_54 ) ;
V_114 |= F_11 ( V_143 ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
F_17 ( & V_3 -> V_93 , V_134 ) ;
return V_14 ;
}
default:
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
}
static void F_40 ( struct V_2 * V_3 )
{
T_2 V_144 ;
V_144 = F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_144 |= F_11 ( V_142 ) ;
F_3 ( V_144 ,
& V_3 -> V_38 -> V_29 ) ;
F_17 ( & V_3 -> V_93 , V_131 ) ;
V_3 -> V_145 = V_146 ;
}
static void F_41 ( struct V_2 * V_3 )
{
F_17 ( & V_3 -> V_93 , V_133 ) ;
V_3 -> V_145 = V_147 ;
}
static void F_42 ( struct V_2 * V_3 ,
enum V_1 V_148 ,
T_2 V_149 )
{
V_3 -> V_4 = V_148 ;
F_17 ( & V_3 -> V_93 , V_149 ) ;
}
enum V_5 F_43 ( struct V_2 * V_3 , T_2 V_150 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
switch ( V_126 ) {
case V_130 :
switch ( F_44 ( V_150 ) ) {
case V_151 :
F_40 ( V_3 ) ;
V_3 -> V_152 = true ;
break;
case V_153 :
F_41 ( V_3 ) ;
V_3 -> V_152 = true ;
break;
default:
F_22 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 ,
V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_131 :
switch ( F_44 ( V_150 ) ) {
case V_151 :
break;
case V_155 :
case V_156 :
F_42 ( V_3 , V_157 ,
V_158 ) ;
break;
case V_159 :
case V_160 :
F_42 ( V_3 , V_161 ,
V_158 ) ;
break;
case V_162 :
case V_163 :
F_42 ( V_3 , V_164 ,
V_158 ) ;
break;
case V_153 :
F_41 ( V_3 ) ;
break;
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 , V_150 ) ;
return V_154 ;
break;
}
return V_14 ;
case V_158 :
switch ( F_44 ( V_150 ) ) {
case V_151 :
F_40 ( V_3 ) ;
break;
case V_153 :
F_41 ( V_3 ) ;
break;
case V_166 :
case V_165 :
case V_167 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 , V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_132 :
switch ( F_44 ( V_150 ) ) {
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_6
L_7 ,
V_103 ,
V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_133 :
switch ( F_44 ( V_150 ) ) {
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
case V_153 :
break;
case V_151 :
F_40 ( V_3 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 , V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_134 :
switch ( F_44 ( V_150 ) ) {
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
case V_153 :
break;
case V_168 :
V_3 -> V_145 = V_147 ;
F_17 ( & V_3 -> V_93 , V_135 ) ;
break;
case V_151 :
F_40 ( V_3 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 ,
V_150 ) ;
return V_154 ; ;
}
return V_14 ;
case V_135 :
switch ( F_44 ( V_150 ) ) {
case V_168 :
break;
case V_169 :
case V_170 :
F_42 ( V_3 , V_157 ,
V_136 ) ;
break;
case V_171 :
case V_172 :
F_42 ( V_3 , V_161 ,
V_136 ) ;
break;
case V_173 :
case V_174 :
F_42 ( V_3 , V_164 ,
V_136 ) ;
break;
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
case V_151 :
F_40 ( V_3 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 , V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_136 :
switch ( F_44 ( V_150 ) ) {
case V_168 :
F_17 ( & V_3 -> V_93 , V_135 ) ;
break;
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_4
L_5 ,
V_103 ,
V_150 ) ;
return V_154 ;
}
return V_14 ;
case V_138 :
switch ( F_44 ( V_150 ) ) {
case V_165 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
case V_175 :
if ( F_25 ( V_3 ) != NULL )
F_27 ( V_3 -> V_18 , V_3 ) ;
else
V_3 -> V_109 = true ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_8
L_5 ,
V_103 , V_3 , V_150 ) ;
return V_128 ;
}
return V_14 ;
case V_139 :
switch ( F_44 ( V_150 ) ) {
case V_176 :
F_17 ( & V_3 -> V_93 , V_104 ) ;
break;
default:
F_45 ( F_23 ( V_3 ) ,
L_9
L_5 ,
V_103 , V_3 , V_150 ) ;
return V_128 ;
break;
}
return V_14 ;
default:
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
}
enum V_5 F_46 ( struct V_2 * V_3 , T_2 V_177 )
{
enum V_125 V_126 = V_3 -> V_93 . V_127 ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
enum V_5 V_178 ;
unsigned long V_99 ;
switch ( V_126 ) {
case V_158 : {
T_2 * V_179 ;
struct V_118 V_119 ;
V_178 = F_47 ( & V_17 -> V_180 ,
V_177 ,
( void * * ) & V_179 ) ;
if ( V_178 != V_14 )
return V_178 ;
F_48 ( & V_119 , V_179 , sizeof( V_119 ) / sizeof( T_2 ) ) ;
if ( V_119 . V_181 == 0 ) {
T_2 V_126 ;
F_21 ( & V_3 -> V_182 . V_183 , V_99 ) ;
memcpy ( & V_3 -> V_120 . V_119 , & V_119 , sizeof( V_119 ) ) ;
F_24 ( & V_3 -> V_182 . V_183 , V_99 ) ;
if ( V_119 . V_184 ) {
V_126 = V_137 ;
} else {
V_126 = V_132 ;
}
F_17 ( & V_3 -> V_93 , V_126 ) ;
V_178 = V_14 ;
} else
F_45 ( F_23 ( V_3 ) ,
L_4
L_10 ,
V_103 , V_177 ) ;
F_49 ( V_17 , V_177 ) ;
return V_178 ;
}
case V_136 : {
struct V_185 * V_186 ;
T_2 * V_187 ;
V_178 = F_47 ( & V_17 -> V_180 ,
V_177 ,
( void * * ) & V_186 ) ;
if ( V_178 != V_14 )
return V_178 ;
if ( ( V_186 -> V_188 == V_189 ) &&
! ( V_186 -> V_190 & V_191 ) ) {
F_50 ( & V_17 -> V_180 ,
V_177 ,
( void * * ) & V_187 ) ;
F_21 ( & V_3 -> V_182 . V_183 , V_99 ) ;
F_51 ( & V_3 -> V_120 . V_192 ,
V_186 ,
V_187 ) ;
F_24 ( & V_3 -> V_182 . V_183 , V_99 ) ;
F_17 ( & V_3 -> V_93 , V_137 ) ;
V_178 = V_14 ;
} else
F_45 ( F_23 ( V_3 ) ,
L_4
L_10 ,
V_103 , V_177 ) ;
F_49 ( V_17 , V_177 ) ;
return V_178 ;
}
default:
F_22 ( F_23 ( V_3 ) ,
L_3 , V_103 , V_126 ) ;
return V_128 ;
}
}
static void F_52 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_17 ( & V_3 -> V_93 , V_130 ) ;
}
static void F_53 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_54 ( V_17 , V_3 ) ;
}
static void F_55 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_56 ( V_17 , V_3 ) ;
}
static void F_57 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_54 ( V_17 , V_3 ) ;
}
static void F_58 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_56 ( V_17 , V_3 ) ;
}
static void F_59 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_60 ( & V_3 -> V_98 , V_194 ) ;
}
static void F_61 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_62 ( & V_3 -> V_98 ) ;
}
static void F_63 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_60 ( & V_3 -> V_98 , V_194 ) ;
}
static void F_64 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_62 ( & V_3 -> V_98 ) ;
}
static void F_65 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
if ( F_66 ( V_3 -> V_18 , V_3 ) ) {
F_31 ( V_3 ) ;
F_60 ( & V_3 -> V_98 ,
V_195 ) ;
} else
V_3 -> V_152 = false ;
}
static void F_67 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_62 ( & V_3 -> V_98 ) ;
}
static void F_68 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_17 ( & V_3 -> V_93 , V_138 ) ;
}
static void F_69 (
struct V_2 * V_3 )
{
T_2 V_114 ;
T_2 V_196 ;
V_114 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_114 |=
( F_11 ( V_54 ) |
F_11 ( V_115 ) |
F_11 ( V_142 ) ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
V_196 = F_4 ( & V_3 -> V_38 -> V_69 ) ;
V_196 &= ~ F_39 ( V_141 ) ;
F_3 ( V_196 , & V_3 -> V_38 -> V_69 ) ;
}
static void F_70 (
struct V_2 * V_3 )
{
T_2 V_114 ;
V_114 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_114 |= F_11 ( V_143 ) ;
V_114 &=
~ ( F_11 ( V_54 ) |
F_11 ( V_197 ) ) ;
F_3 ( V_114 ,
& V_3 -> V_38 -> V_29 ) ;
}
static void F_71 (
struct V_2 * V_3 )
{
T_2 V_198 ;
V_198 =
F_4 ( & V_3 -> V_38 -> V_29 ) ;
V_198 |=
( F_11 ( V_197 ) |
F_11 ( V_54 ) ) ;
F_3 ( V_198 ,
& V_3 -> V_38 -> V_29 ) ;
V_198 |= F_11 ( V_143 ) ;
V_198 &= ~ F_11 ( V_54 ) ;
F_3 ( V_198 ,
& V_3 -> V_38 -> V_29 ) ;
}
static void F_72 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_105 * V_106 = V_3 -> V_18 ;
struct V_16 * V_17 = V_106 -> V_19 ;
F_62 ( & V_3 -> V_98 ) ;
F_69 ( V_3 ) ;
if ( V_3 -> V_93 . V_199 != V_200 )
F_73 ( V_17 , F_25 ( V_3 ) , V_3 ) ;
}
static void F_74 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_105 * V_106 = V_3 -> V_18 ;
struct V_16 * V_17 = V_106 -> V_19 ;
F_69 ( V_3 ) ;
F_70 ( V_3 ) ;
V_3 -> V_145 = V_201 ;
V_3 -> V_109 = false ;
if ( V_3 -> V_93 . V_199 == V_138 )
F_73 ( V_17 , F_25 ( V_3 ) , V_3 ) ;
F_17 ( & V_3 -> V_93 , V_129 ) ;
}
static void F_75 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
struct V_105 * V_106 = V_3 -> V_18 ;
struct V_16 * V_17 = V_106 -> V_19 ;
F_76 ( V_17 , F_25 ( V_3 ) , V_3 ) ;
}
static void F_77 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_30 ( V_3 ) ;
}
static void F_78 ( struct V_193 * V_93 )
{
struct V_2 * V_3 = F_19 ( V_93 , F_20 ( * V_3 ) , V_93 ) ;
F_79 ( V_3 -> V_18 , V_3 , false ) ;
if ( V_3 -> V_145 == V_146 ) {
F_71 ( V_3 ) ;
} else {
F_17 ( & V_3 -> V_93 , V_104 ) ;
}
}
void F_80 ( struct V_2 * V_3 ,
struct V_105 * V_106 , V_77 V_21 )
{
F_81 ( & V_3 -> V_93 , V_202 , V_200 ) ;
V_3 -> V_18 = V_106 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_109 = false ;
V_3 -> V_145 = V_201 ;
V_3 -> V_38 = NULL ;
V_3 -> V_4 = V_203 ;
F_82 ( & V_3 -> V_98 , F_18 ) ;
}
void F_83 ( struct V_2 * V_3 , struct V_16 * V_17 , int V_204 )
{
struct V_205 * V_206 = & V_17 -> V_28 ;
T_3 V_207 ;
T_4 V_121 ;
V_207 = V_206 -> V_25 [ V_204 ] . V_47 . V_48 ;
V_207 <<= 32 ;
V_207 |= V_206 -> V_25 [ V_204 ] . V_47 . V_50 ;
V_121 = F_84 ( V_207 ) ;
memcpy ( V_3 -> V_121 , & V_121 , sizeof( V_121 ) ) ;
V_3 -> V_105 = NULL ;
V_3 -> V_182 . V_208 = 0 ;
V_3 -> V_182 . V_209 = V_204 ;
V_3 -> V_182 . V_121 = & V_3 -> V_121 [ 0 ] ;
V_3 -> V_182 . V_120 = ( V_77 * ) & V_3 -> V_120 ;
V_3 -> V_182 . V_210 = & V_17 -> V_211 ;
V_3 -> V_182 . V_212 = V_3 ;
V_3 -> V_182 . V_208 = 1 ;
V_3 -> V_182 . V_213 = V_214 ;
V_3 -> V_182 . V_215 = V_216 ;
V_3 -> V_182 . V_217 = 0 ;
V_3 -> V_182 . type = V_218 ;
V_3 -> V_182 . V_219 = V_220 ;
V_3 -> V_182 . V_221 = V_222 ;
V_3 -> V_182 . V_223 = V_203 ;
memset ( & V_3 -> V_120 , 0 , sizeof( V_3 -> V_120 ) ) ;
}
int F_85 ( struct V_224 * V_182 ,
enum V_225 V_226 ,
void * V_227 )
{
int V_228 = 0 ;
struct V_2 * V_3 = V_182 -> V_212 ;
struct V_105 * V_106 = V_3 -> V_105 ;
struct V_16 * V_17 = V_182 -> V_210 -> V_229 ;
unsigned long V_99 ;
F_22 ( & V_17 -> V_89 -> V_230 ,
L_11 ,
V_103 , V_182 , V_226 , V_227 , V_3 , V_106 ) ;
switch ( V_226 ) {
case V_231 :
F_21 ( & V_17 -> V_100 , V_99 ) ;
F_36 ( V_3 ) ;
F_24 ( & V_17 -> V_100 , V_99 ) ;
break;
case V_232 :
F_21 ( & V_17 -> V_100 , V_99 ) ;
F_36 ( V_3 ) ;
F_35 ( V_3 ) ;
F_24 ( & V_17 -> V_100 , V_99 ) ;
break;
case V_233 :
if ( ! V_106 )
return - V_234 ;
V_228 = F_86 ( V_17 , V_106 , V_3 ) ;
break;
default:
F_22 ( & V_17 -> V_89 -> V_230 ,
L_12 ,
V_103 , V_182 , V_226 ) ;
V_228 = - V_235 ;
break;
}
return V_228 ;
}
