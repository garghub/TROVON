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
V_3 -> V_37 = V_7 ;
#define F_7 0x01
F_3 ( F_8 ( V_38 ) |
F_8 ( V_39 ) |
F_8 ( V_40 ) |
F_8 ( V_41 ) |
F_9 ( V_42 , F_7 ) ,
& V_3 -> V_37 -> V_43 ) ;
F_3 ( 0xFEDCBA98 ,
& V_3 -> V_37 -> V_44 ) ;
F_3 ( V_20 , & V_3 -> V_37 -> V_45 ) ;
F_3 ( V_27 -> V_46 . V_47 ,
& V_3 -> V_37 -> V_48 ) ;
F_3 ( V_27 -> V_46 . V_49 ,
& V_3 -> V_37 -> V_50 ) ;
F_3 ( 0 , & V_3 -> V_37 -> V_51 ) ;
F_3 ( F_10 ( V_52 , V_20 ) ,
& V_3 -> V_37 -> V_51 ) ;
V_29 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_29 |= F_11 ( V_53 ) ;
F_3 ( V_29 ,
& V_3 -> V_37 -> V_29 ) ;
V_31 . V_54 = 0 ;
V_31 . V_55 = 1 ;
V_31 . V_56 = 1 ;
V_31 . V_57 = 1 ;
V_31 . V_58 = 1 ;
if ( V_17 -> V_28 . V_59 . V_60 == true ) {
V_31 . V_61 = 1 ;
V_31 . V_62 = 1 ;
V_31 . V_63 = 1 ;
}
V_32 = V_31 . V_54 ;
while ( V_32 != 0 ) {
if ( V_32 & 0x1 )
V_33 ++ ;
V_32 >>= 1 ;
}
if ( ( V_33 % 2 ) != 0 )
V_31 . V_64 = 1 ;
F_3 ( V_31 . V_54 , & V_3 -> V_37 -> V_65 ) ;
F_3 ( F_12 ( V_66 ,
V_23 -> V_67 ) ,
& V_3 -> V_37 -> V_68 ) ;
V_36 = F_13 ( V_69 ,
V_23 -> V_70 ) ;
V_36 |= F_13 ( V_71 ,
V_23 -> V_72 ) ;
F_3 ( V_36 , & V_3 -> V_37 -> V_73 ) ;
F_3 ( 0x02108421 ,
& V_3 -> V_37 -> V_74 ) ;
V_34 = F_14 ( V_75 ,
( V_76 ) V_17 -> V_24 . V_77 ) ;
switch ( V_23 -> V_78 ) {
case V_79 :
V_35 = V_80 ;
break;
case V_81 :
V_35 = V_82 ;
break;
default:
V_35 = V_83 ;
break;
}
V_34 |= F_14 ( V_84 , V_35 ) ;
F_3 ( V_34 , & V_3 -> V_37 -> V_85 ) ;
if ( F_15 ( V_17 -> V_86 ) ) {
F_3 ( V_87 ,
& V_3 -> V_37 -> V_88 ) ;
}
F_3 ( 0 , & V_3 -> V_37 -> V_89 ) ;
F_16 ( & V_3 -> V_90 , V_91 ) ;
return V_14 ;
}
static void F_17 ( unsigned long V_92 )
{
struct V_93 * V_94 = (struct V_93 * ) V_92 ;
struct V_2 * V_3 = F_18 ( V_94 , F_19 ( * V_3 ) , V_95 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
unsigned long V_96 ;
F_20 ( & V_17 -> V_97 , V_96 ) ;
if ( V_94 -> V_98 )
goto V_99;
F_21 ( F_22 ( V_3 ) ,
L_1
L_2 ,
V_100 ,
V_3 ) ;
F_16 ( & V_3 -> V_90 , V_101 ) ;
V_99:
F_23 ( & V_17 -> V_97 , V_96 ) ;
}
struct V_102 * F_24 ( struct V_2 * V_3 )
{
struct V_102 * V_103 = V_3 -> V_18 ;
if ( V_103 -> V_104 == V_105 )
return NULL ;
return V_3 -> V_18 ;
}
void F_25 (
struct V_2 * V_3 ,
struct V_102 * V_103 )
{
V_3 -> V_18 = V_103 ;
if ( V_3 -> V_106 ) {
V_3 -> V_106 = false ;
F_26 ( V_3 -> V_18 , V_3 ) ;
}
}
enum V_5 F_27 ( struct V_2 * V_3 ,
struct V_6 T_1 * V_107 ,
struct V_15 T_1 * V_108 )
{
F_2 ( V_3 , V_107 ) ;
F_6 ( V_3 , V_108 ) ;
F_16 ( & V_3 -> V_90 , V_91 ) ;
return V_14 ;
}
void F_28 ( struct V_2 * V_3 , T_2 V_109 )
{
T_2 V_8 ;
F_3 ( V_109 , & V_3 -> V_9 -> V_11 ) ;
V_8 = F_4 ( & V_3 -> V_9 -> V_12 ) ;
V_8 |= F_5 ( V_110 ) ;
F_3 ( V_8 , & V_3 -> V_9 -> V_12 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
T_2 V_111 ;
V_111 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_111 |= F_11 ( V_112 ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
F_28 ( V_3 , V_10 ) ;
}
void F_30 ( struct V_2 * V_3 )
{
T_2 V_111 ;
V_111 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_111 &= ~ F_11 ( V_112 ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
}
void F_31 ( struct V_2 * V_3 , struct V_113 * V_114 )
{
V_114 -> V_47 = F_4 ( & V_3 -> V_37 -> V_48 ) ;
V_114 -> V_49 = F_4 ( & V_3 -> V_37 -> V_50 ) ;
}
void F_32 ( struct V_2 * V_3 , struct V_113 * V_114 )
{
struct V_115 * V_116 ;
V_116 = & V_3 -> V_117 . V_116 ;
memcpy ( V_114 , V_116 -> V_118 , V_119 ) ;
}
void F_33 ( struct V_2 * V_3 , struct V_120 * V_121 )
{
V_121 -> V_54 = F_4 ( & V_3 -> V_37 -> V_43 ) ;
}
enum V_5 F_34 ( struct V_2 * V_3 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
if ( V_123 != V_91 ) {
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
F_16 ( & V_3 -> V_90 , V_101 ) ;
return V_14 ;
}
enum V_5 F_35 ( struct V_2 * V_3 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
switch ( V_123 ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
break;
default:
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
F_16 ( & V_3 -> V_90 , V_91 ) ;
return V_14 ;
}
enum V_5 F_36 ( struct V_2 * V_3 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
if ( V_123 != V_135 ) {
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
F_16 ( & V_3 -> V_90 , V_136 ) ;
return V_14 ;
}
enum V_5 F_37 ( struct V_2 * V_3 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
switch ( V_123 ) {
case V_129 : {
T_2 V_137 ;
V_137 = F_4 ( & V_3 -> V_37 -> V_68 ) ;
V_137 |= F_38 ( V_138 ) ;
F_3 ( V_137 , & V_3 -> V_37 -> V_68 ) ;
F_16 ( & V_3 -> V_90 , V_134 ) ;
return V_14 ;
}
case V_130 : {
T_2 V_111 ;
V_111 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_111 &=
~ ( F_11 ( V_139 ) | F_11 ( V_140 ) ) ;
V_111 |= F_11 ( V_53 ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
V_111 &= ~ F_11 ( V_53 ) ;
V_111 |= F_11 ( V_140 ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
F_16 ( & V_3 -> V_90 , V_131 ) ;
return V_14 ;
}
default:
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
}
static void F_39 ( struct V_2 * V_3 )
{
T_2 V_141 ;
V_141 = F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_141 |= F_11 ( V_139 ) ;
F_3 ( V_141 ,
& V_3 -> V_37 -> V_29 ) ;
F_16 ( & V_3 -> V_90 , V_128 ) ;
V_3 -> V_142 = V_143 ;
}
static void F_40 ( struct V_2 * V_3 )
{
F_16 ( & V_3 -> V_90 , V_130 ) ;
V_3 -> V_142 = V_144 ;
}
static void F_41 ( struct V_2 * V_3 ,
enum V_1 V_145 ,
T_2 V_146 )
{
V_3 -> V_4 = V_145 ;
F_16 ( & V_3 -> V_90 , V_146 ) ;
}
enum V_5 F_42 ( struct V_2 * V_3 , T_2 V_147 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
switch ( V_123 ) {
case V_127 :
switch ( F_43 ( V_147 ) ) {
case V_148 :
F_39 ( V_3 ) ;
V_3 -> V_149 = true ;
break;
case V_150 :
F_40 ( V_3 ) ;
V_3 -> V_149 = true ;
break;
default:
F_21 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 ,
V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_128 :
switch ( F_43 ( V_147 ) ) {
case V_148 :
break;
case V_152 :
case V_153 :
F_41 ( V_3 , V_154 ,
V_155 ) ;
break;
case V_156 :
case V_157 :
F_41 ( V_3 , V_158 ,
V_155 ) ;
break;
case V_159 :
case V_160 :
F_41 ( V_3 , V_161 ,
V_155 ) ;
break;
case V_150 :
F_40 ( V_3 ) ;
break;
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 , V_147 ) ;
return V_151 ;
break;
}
return V_14 ;
case V_155 :
switch ( F_43 ( V_147 ) ) {
case V_148 :
F_39 ( V_3 ) ;
break;
case V_150 :
F_40 ( V_3 ) ;
break;
case V_163 :
case V_162 :
case V_164 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 , V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_129 :
switch ( F_43 ( V_147 ) ) {
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_6
L_7 ,
V_100 ,
V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_130 :
switch ( F_43 ( V_147 ) ) {
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
case V_150 :
break;
case V_148 :
F_39 ( V_3 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 , V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_131 :
switch ( F_43 ( V_147 ) ) {
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
case V_150 :
break;
case V_165 :
V_3 -> V_142 = V_144 ;
F_16 ( & V_3 -> V_90 , V_132 ) ;
break;
case V_148 :
F_39 ( V_3 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 ,
V_147 ) ;
return V_151 ; ;
}
return V_14 ;
case V_132 :
switch ( F_43 ( V_147 ) ) {
case V_165 :
break;
case V_166 :
case V_167 :
F_41 ( V_3 , V_154 ,
V_133 ) ;
break;
case V_168 :
case V_169 :
F_41 ( V_3 , V_158 ,
V_133 ) ;
break;
case V_170 :
case V_171 :
F_41 ( V_3 , V_161 ,
V_133 ) ;
break;
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
case V_148 :
F_39 ( V_3 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 , V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_133 :
switch ( F_43 ( V_147 ) ) {
case V_165 :
F_16 ( & V_3 -> V_90 , V_132 ) ;
break;
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_4
L_5 ,
V_100 ,
V_147 ) ;
return V_151 ;
}
return V_14 ;
case V_135 :
switch ( F_43 ( V_147 ) ) {
case V_162 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
case V_172 :
if ( F_24 ( V_3 ) != NULL )
F_26 ( V_3 -> V_18 , V_3 ) ;
else
V_3 -> V_106 = true ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_8
L_5 ,
V_100 , V_3 , V_147 ) ;
return V_125 ;
}
return V_14 ;
case V_136 :
switch ( F_43 ( V_147 ) ) {
case V_173 :
F_16 ( & V_3 -> V_90 , V_101 ) ;
break;
default:
F_44 ( F_22 ( V_3 ) ,
L_9
L_5 ,
V_100 , V_3 , V_147 ) ;
return V_125 ;
break;
}
return V_14 ;
default:
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
}
enum V_5 F_45 ( struct V_2 * V_3 , T_2 V_174 )
{
enum V_122 V_123 = V_3 -> V_90 . V_124 ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
enum V_5 V_175 ;
unsigned long V_96 ;
switch ( V_123 ) {
case V_155 : {
T_2 * V_176 ;
struct V_115 V_116 ;
V_175 = F_46 ( & V_17 -> V_177 ,
V_174 ,
( void * * ) & V_176 ) ;
if ( V_175 != V_14 )
return V_175 ;
F_47 ( & V_116 , V_176 , sizeof( V_116 ) / sizeof( T_2 ) ) ;
if ( V_116 . V_178 == 0 ) {
T_2 V_123 ;
F_20 ( & V_3 -> V_179 . V_180 , V_96 ) ;
memcpy ( & V_3 -> V_117 . V_116 , & V_116 , sizeof( V_116 ) ) ;
F_23 ( & V_3 -> V_179 . V_180 , V_96 ) ;
if ( V_116 . V_181 ) {
V_123 = V_134 ;
} else {
V_123 = V_129 ;
}
F_16 ( & V_3 -> V_90 , V_123 ) ;
V_175 = V_14 ;
} else
F_44 ( F_22 ( V_3 ) ,
L_4
L_10 ,
V_100 , V_174 ) ;
F_48 ( V_17 , V_174 ) ;
return V_175 ;
}
case V_133 : {
struct V_182 * V_183 ;
T_2 * V_184 ;
V_175 = F_46 ( & V_17 -> V_177 ,
V_174 ,
( void * * ) & V_183 ) ;
if ( V_175 != V_14 )
return V_175 ;
if ( ( V_183 -> V_185 == V_186 ) &&
! ( V_183 -> V_187 & V_188 ) ) {
F_49 ( & V_17 -> V_177 ,
V_174 ,
( void * * ) & V_184 ) ;
F_20 ( & V_3 -> V_179 . V_180 , V_96 ) ;
F_50 ( & V_3 -> V_117 . V_189 ,
V_183 ,
V_184 ) ;
F_23 ( & V_3 -> V_179 . V_180 , V_96 ) ;
F_16 ( & V_3 -> V_90 , V_134 ) ;
V_175 = V_14 ;
} else
F_44 ( F_22 ( V_3 ) ,
L_4
L_10 ,
V_100 , V_174 ) ;
F_48 ( V_17 , V_174 ) ;
return V_175 ;
}
default:
F_21 ( F_22 ( V_3 ) ,
L_3 , V_100 , V_123 ) ;
return V_125 ;
}
}
static void F_51 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_16 ( & V_3 -> V_90 , V_127 ) ;
}
static void F_52 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_53 ( V_17 , V_3 ) ;
}
static void F_54 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_55 ( V_17 , V_3 ) ;
}
static void F_56 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_53 ( V_17 , V_3 ) ;
}
static void F_57 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
F_55 ( V_17 , V_3 ) ;
}
static void F_58 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_59 ( & V_3 -> V_95 , V_191 ) ;
}
static void F_60 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_61 ( & V_3 -> V_95 ) ;
}
static void F_62 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_59 ( & V_3 -> V_95 , V_191 ) ;
}
static void F_63 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_61 ( & V_3 -> V_95 ) ;
}
static void F_64 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
if ( F_65 ( V_3 -> V_18 , V_3 ) ) {
F_30 ( V_3 ) ;
F_59 ( & V_3 -> V_95 ,
V_192 ) ;
} else
V_3 -> V_149 = false ;
}
static void F_66 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_61 ( & V_3 -> V_95 ) ;
}
static void F_67 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_16 ( & V_3 -> V_90 , V_135 ) ;
}
static void F_68 (
struct V_2 * V_3 )
{
T_2 V_111 ;
T_2 V_193 ;
V_111 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_111 |=
( F_11 ( V_53 ) |
F_11 ( V_112 ) |
F_11 ( V_139 ) ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
V_193 = F_4 ( & V_3 -> V_37 -> V_68 ) ;
V_193 &= ~ F_38 ( V_138 ) ;
F_3 ( V_193 , & V_3 -> V_37 -> V_68 ) ;
}
static void F_69 (
struct V_2 * V_3 )
{
T_2 V_111 ;
V_111 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_111 |= F_11 ( V_140 ) ;
V_111 &=
~ ( F_11 ( V_53 ) |
F_11 ( V_194 ) ) ;
F_3 ( V_111 ,
& V_3 -> V_37 -> V_29 ) ;
}
static void F_70 (
struct V_2 * V_3 )
{
T_2 V_195 ;
V_195 =
F_4 ( & V_3 -> V_37 -> V_29 ) ;
V_195 |=
( F_11 ( V_194 ) |
F_11 ( V_53 ) ) ;
F_3 ( V_195 ,
& V_3 -> V_37 -> V_29 ) ;
V_195 |= F_11 ( V_140 ) ;
V_195 &= ~ F_11 ( V_53 ) ;
F_3 ( V_195 ,
& V_3 -> V_37 -> V_29 ) ;
}
static void F_71 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_102 * V_103 = V_3 -> V_18 ;
struct V_16 * V_17 = V_103 -> V_19 ;
F_61 ( & V_3 -> V_95 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_90 . V_196 != V_197 )
F_72 ( V_17 , F_24 ( V_3 ) , V_3 ) ;
}
static void F_73 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_102 * V_103 = V_3 -> V_18 ;
struct V_16 * V_17 = V_103 -> V_19 ;
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
V_3 -> V_142 = V_198 ;
V_3 -> V_106 = false ;
if ( V_3 -> V_90 . V_196 == V_135 )
F_72 ( V_17 , F_24 ( V_3 ) , V_3 ) ;
F_16 ( & V_3 -> V_90 , V_126 ) ;
}
static void F_74 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
struct V_102 * V_103 = V_3 -> V_18 ;
struct V_16 * V_17 = V_103 -> V_19 ;
F_75 ( V_17 , F_24 ( V_3 ) , V_3 ) ;
}
static void F_76 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_29 ( V_3 ) ;
}
static void F_77 ( struct V_190 * V_90 )
{
struct V_2 * V_3 = F_18 ( V_90 , F_19 ( * V_3 ) , V_90 ) ;
F_78 ( V_3 -> V_18 , V_3 , false ) ;
if ( V_3 -> V_142 == V_143 ) {
F_70 ( V_3 ) ;
} else {
F_16 ( & V_3 -> V_90 , V_101 ) ;
}
}
void F_79 ( struct V_2 * V_3 ,
struct V_102 * V_103 , V_76 V_21 )
{
F_80 ( & V_3 -> V_90 , V_199 , V_197 ) ;
V_3 -> V_18 = V_103 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_106 = false ;
V_3 -> V_142 = V_198 ;
V_3 -> V_37 = NULL ;
V_3 -> V_4 = V_200 ;
F_81 ( & V_3 -> V_95 , F_17 ) ;
}
void F_82 ( struct V_2 * V_3 , struct V_16 * V_17 , int V_201 )
{
struct V_202 * V_203 = & V_17 -> V_28 ;
T_3 V_204 ;
T_4 V_118 ;
V_204 = V_203 -> V_25 [ V_201 ] . V_46 . V_47 ;
V_204 <<= 32 ;
V_204 |= V_203 -> V_25 [ V_201 ] . V_46 . V_49 ;
V_118 = F_83 ( V_204 ) ;
memcpy ( V_3 -> V_118 , & V_118 , sizeof( V_118 ) ) ;
V_3 -> V_102 = NULL ;
V_3 -> V_179 . V_205 = 0 ;
V_3 -> V_179 . V_206 = V_201 ;
V_3 -> V_179 . V_118 = & V_3 -> V_118 [ 0 ] ;
V_3 -> V_179 . V_117 = ( V_76 * ) & V_3 -> V_117 ;
V_3 -> V_179 . V_207 = & V_17 -> V_208 ;
V_3 -> V_179 . V_209 = V_3 ;
V_3 -> V_179 . V_205 = 1 ;
V_3 -> V_179 . V_210 = V_211 ;
V_3 -> V_179 . V_212 = V_213 ;
V_3 -> V_179 . V_214 = 0 ;
V_3 -> V_179 . type = V_215 ;
V_3 -> V_179 . V_216 = V_217 ;
V_3 -> V_179 . V_218 = V_219 ;
V_3 -> V_179 . V_220 = V_200 ;
memset ( & V_3 -> V_117 , 0 , sizeof( V_3 -> V_117 ) ) ;
}
int F_84 ( struct V_221 * V_179 ,
enum V_222 V_223 ,
void * V_224 )
{
int V_225 = 0 ;
struct V_2 * V_3 = V_179 -> V_209 ;
struct V_102 * V_103 = V_3 -> V_102 ;
struct V_16 * V_17 = V_179 -> V_207 -> V_226 ;
unsigned long V_96 ;
F_21 ( & V_17 -> V_86 -> V_227 ,
L_11 ,
V_100 , V_179 , V_223 , V_224 , V_3 , V_103 ) ;
switch ( V_223 ) {
case V_228 :
F_20 ( & V_17 -> V_97 , V_96 ) ;
F_35 ( V_3 ) ;
F_23 ( & V_17 -> V_97 , V_96 ) ;
break;
case V_229 :
F_20 ( & V_17 -> V_97 , V_96 ) ;
F_35 ( V_3 ) ;
F_34 ( V_3 ) ;
F_23 ( & V_17 -> V_97 , V_96 ) ;
break;
case V_230 :
if ( ! V_103 )
return - V_231 ;
V_225 = F_85 ( V_17 , V_103 , V_3 ) ;
break;
default:
F_21 ( & V_17 -> V_86 -> V_227 ,
L_12 ,
V_100 , V_179 , V_223 ) ;
V_225 = - V_232 ;
break;
}
return V_225 ;
}
