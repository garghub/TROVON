static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_7 = 0 ;
V_7 |= ( T_2 ) F_3 ( V_6 , V_8 ) ;
V_7 |= ( T_2 ) F_3 ( V_6 , V_9 ) << 32 ;
return V_7 ;
}
static int F_4 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_14 ;
T_4 V_15 , V_16 ;
int V_17 = 0 ;
if ( V_12 < 0 ) {
V_17 = 1 ;
V_12 = - V_12 ;
}
F_5 () ;
V_16 = F_6 ( V_4 -> V_18 ) ;
V_14 = V_16 ;
V_14 *= V_12 ;
V_15 = F_7 ( V_14 , 1000000000ULL ) ;
V_16 = V_17 ? ( V_16 - V_15 ) : ( V_16 + V_15 ) ;
switch ( V_6 -> V_19 . type ) {
case V_20 :
F_8 ( V_6 , V_21 , V_16 ) ;
break;
case V_22 :
F_8 ( V_6 , V_21 ,
( 1 << V_23 ) |
V_16 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , T_5 V_24 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
unsigned long V_25 ;
T_2 V_26 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_26 = F_11 ( & V_4 -> V_28 ) ;
V_26 += V_24 ;
F_12 ( & V_4 -> V_28 ,
& V_4 -> V_2 ,
V_26 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , struct V_29 * V_30 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
T_2 V_31 ;
T_4 V_32 ;
unsigned long V_25 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_11 ( & V_4 -> V_28 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
V_30 -> V_33 = F_15 ( V_31 , 1000000000ULL , & V_32 ) ;
V_30 -> V_34 = V_32 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
const struct V_29 * V_30 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
T_2 V_31 ;
unsigned long V_25 ;
V_31 = V_30 -> V_33 * 1000000000ULL ;
V_31 += V_30 -> V_34 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
F_12 ( & V_4 -> V_28 , & V_4 -> V_2 , V_31 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
if ( V_36 -> type == V_38 ) {
switch ( V_4 -> V_6 . V_19 . type ) {
case V_20 :
if ( V_37 )
V_4 -> V_39 |= V_40 ;
else
V_4 -> V_39 &=
~ V_40 ;
return 0 ;
default:
break;
}
}
return - V_41 ;
}
void F_18 ( struct V_3 * V_4 , T_4 V_42 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_43 V_44 ;
V_44 . type = V_45 ;
if ( ! V_4 -> V_46 ||
! ( V_4 -> V_39 & V_40 ) )
return;
if ( F_19 ( V_42 & V_47 ) ) {
switch ( V_6 -> V_19 . type ) {
case V_20 :
V_43 ( V_4 -> V_46 , & V_44 ) ;
break;
default:
break;
}
}
}
static void F_20 ( struct V_5 * V_6 , int V_48 )
{
T_4 V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ;
T_2 V_55 = 0 ;
T_4 V_56 ;
switch ( V_6 -> V_19 . type ) {
case V_20 :
V_49 = F_3 ( V_6 , V_57 ) ;
V_49 |= ( V_58 |
V_59 ) ;
V_50 = ( V_60 |
V_61 |
V_62 ) ;
V_51 = ( T_4 ) ( V_63 << V_48 ) ;
V_52 = ( T_4 ) ( ( V_63 << V_48 ) >> 32 ) ;
V_55 |= ( T_2 ) F_3 ( V_6 , V_8 ) ;
V_55 |= ( T_2 ) F_3 ( V_6 , V_9 ) << 32 ;
V_55 >>= V_48 ;
F_15 ( V_55 , V_63 , & V_56 ) ;
V_55 += ( V_63 - V_56 ) ;
V_55 <<= V_48 ;
V_53 = ( T_4 ) V_55 ;
V_54 = ( T_4 ) ( V_55 >> 32 ) ;
F_8 ( V_6 , V_64 , V_51 ) ;
F_8 ( V_6 , V_65 , V_52 ) ;
F_8 ( V_6 , V_66 , V_53 ) ;
F_8 ( V_6 , V_67 , V_54 ) ;
F_8 ( V_6 , V_57 , V_49 ) ;
F_8 ( V_6 , V_68 , V_50 ) ;
F_8 ( V_6 , V_69 , V_47 ) ;
break;
default:
break;
}
}
static void F_21 ( struct V_5 * V_6 )
{
F_8 ( V_6 , V_70 , V_47 ) ;
F_8 ( V_6 , V_68 , 0 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
unsigned long V_71 = V_4 -> V_72 - V_73 ;
struct V_29 V_30 ;
if ( ( V_4 -> V_39 & V_74 ) &&
( V_71 >= V_75 ) ) {
F_14 ( & V_4 -> V_13 , & V_30 ) ;
V_4 -> V_72 = V_73 ;
}
}
static int F_23 ( struct V_76 * V_77 , int V_78 )
{
struct V_79 V_80 ;
T_6 V_81 ;
unsigned int type , V_82 ;
if ( V_78 == V_83 )
return 0 ;
type = F_24 ( V_77 , V_84 ) ;
if ( F_25 ( V_78 == V_85 ) )
return type & V_86 ;
switch ( type ) {
case V_87 :
F_26 ( V_77 , V_88 , & V_80 , sizeof( V_80 ) ) ;
V_82 = V_89 + ( V_80 . V_90 << 2 ) + V_91 + V_92 ;
break;
case V_93 :
V_82 = V_94 + V_92 ;
break;
default:
return 0 ;
}
if ( V_77 -> V_95 < V_82 )
return 0 ;
F_26 ( V_77 , V_82 , & V_81 , sizeof( V_81 ) ) ;
switch ( V_78 ) {
case V_96 :
return ( V_81 == V_97 ) ;
break;
case V_98 :
return ( V_81 == V_99 ) ;
break;
default:
return 0 ;
}
}
void F_27 ( struct V_100 * V_101 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_102 V_103 ;
T_2 V_104 = 0 , V_31 ;
T_4 V_105 ;
unsigned long V_25 ;
if ( ! V_101 || ! V_101 -> V_4 )
return;
V_4 = V_101 -> V_4 ;
V_6 = & V_4 -> V_6 ;
V_105 = F_3 ( V_6 , V_106 ) ;
V_104 |= ( T_2 ) F_3 ( V_6 , V_107 ) ;
V_104 |= ( T_2 ) F_3 ( V_6 , V_108 ) << 32 ;
if ( ! ( V_105 & V_109 ) )
return;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_28 ( & V_4 -> V_28 , V_104 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_110 = F_29 ( V_31 ) ;
F_30 ( V_77 , & V_103 ) ;
}
void F_31 ( struct V_100 * V_101 ,
union V_111 * V_112 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_102 * V_103 ;
T_2 V_104 = 0 , V_31 ;
T_4 V_113 ;
unsigned long V_25 ;
if ( ! V_101 || ! V_101 -> V_4 )
return;
V_4 = V_101 -> V_4 ;
V_6 = & V_4 -> V_6 ;
V_113 = F_3 ( V_6 , V_114 ) ;
if ( F_25 ( ! ( V_113 & V_115 ) ||
! F_23 ( V_77 , V_4 -> V_116 ) ) )
return;
V_104 |= ( T_2 ) F_3 ( V_6 , V_117 ) ;
V_104 |= ( T_2 ) F_3 ( V_6 , V_118 ) << 32 ;
if ( F_19 ( ! F_32 ( V_112 , V_119 ) ) )
return;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_28 ( & V_4 -> V_28 , V_104 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
V_103 = F_33 ( V_77 ) ;
V_103 -> V_110 = F_29 ( V_31 ) ;
}
int F_34 ( struct V_3 * V_4 ,
struct V_120 * V_121 , int V_122 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_123 V_124 ;
T_4 V_125 = V_126 ;
T_4 V_127 = V_128 ;
T_4 V_129 = 0 ;
bool V_130 = false ;
bool V_131 = false ;
T_4 V_104 ;
if ( F_35 ( & V_124 , V_121 -> V_132 , sizeof( V_124 ) ) )
return - V_133 ;
if ( V_124 . V_25 )
return - V_134 ;
switch ( V_124 . V_135 ) {
case V_136 :
V_125 = 0 ;
case V_137 :
break;
default:
return - V_138 ;
}
switch ( V_124 . V_78 ) {
case V_83 :
V_127 = 0 ;
break;
case V_96 :
V_127 |= V_139 ;
V_129 = V_97 ;
V_130 = true ;
break;
case V_98 :
V_127 |= V_139 ;
V_129 = V_99 ;
V_130 = true ;
break;
case V_85 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_127 |= V_148 ;
V_131 = true ;
V_130 = true ;
V_124 . V_78 = V_85 ;
break;
case V_149 :
case V_150 :
default:
V_124 . V_78 = V_83 ;
return - V_138 ;
}
if ( V_6 -> V_19 . type == V_151 ) {
if ( V_127 | V_125 )
return - V_138 ;
return 0 ;
}
V_4 -> V_116 = V_124 . V_78 ;
if ( V_131 )
F_8 ( V_6 , F_36 ( 3 ) ,
( V_152 |
V_153 |
V_154 ) ) ;
else
F_8 ( V_6 , F_36 ( 3 ) , 0 ) ;
#define F_37 319
if ( V_130 ) {
T_4 V_155 = ( V_156
| V_157
| V_158 ) ;
V_155 |= ( ( V_159
& V_160
& V_161 )
<< V_162 ) ;
F_8 ( V_6 , F_38 ( 3 ) ,
( 3 << V_163 |
V_164 ) ) ;
F_8 ( V_6 , F_39 ( 3 ) ,
( F_40 ( F_37 ) |
F_40 ( F_37 ) << 16 ) ) ;
F_8 ( V_6 , F_41 ( 3 ) , V_155 ) ;
V_129 |= F_37 << 16 ;
} else {
F_8 ( V_6 , F_41 ( 3 ) , 0 ) ;
}
V_104 = F_3 ( V_6 , V_106 ) ;
V_104 &= ~ V_126 ;
V_104 |= V_125 ;
F_8 ( V_6 , V_106 , V_104 ) ;
V_104 = F_3 ( V_6 , V_114 ) ;
V_104 &= ~ ( V_128 | V_165 ) ;
V_104 |= V_127 ;
F_8 ( V_6 , V_114 , V_104 ) ;
F_8 ( V_6 , V_166 , V_129 ) ;
F_42 ( V_6 ) ;
V_104 = F_3 ( V_6 , V_108 ) ;
V_104 = F_3 ( V_6 , V_118 ) ;
return F_43 ( V_121 -> V_132 , & V_124 , sizeof( V_124 ) ) ?
- V_133 : 0 ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_4 V_16 = 0 ;
T_4 V_167 = 0 ;
T_4 V_48 = 0 ;
T_4 V_168 ;
unsigned long V_25 ;
switch ( V_4 -> V_169 ) {
case V_170 :
case V_171 :
case V_172 :
V_168 = V_4 -> V_169 ;
break;
default:
V_168 = V_172 ;
break;
}
V_167 = F_3 ( V_6 , V_21 ) ;
if ( V_4 -> V_168 == V_168 && V_167 )
return;
F_21 ( V_6 ) ;
switch ( V_168 ) {
case V_170 :
V_16 = V_173 ;
V_48 = V_174 ;
break;
case V_171 :
V_16 = V_175 ;
V_48 = V_176 ;
break;
case V_172 :
V_16 = V_177 ;
V_48 = V_178 ;
break;
}
switch ( V_6 -> V_19 . type ) {
case V_20 :
F_8 ( V_6 , V_21 , V_16 ) ;
break;
case V_22 :
V_16 >>= V_179 ;
V_48 -= V_179 ;
F_8 ( V_6 , V_21 ,
( 1 << V_23 ) |
V_16 ) ;
break;
default:
return;
}
F_8 ( V_6 , V_8 , 0x00000000 ) ;
F_8 ( V_6 , V_9 , 0x00000000 ) ;
F_42 ( V_6 ) ;
F_20 ( V_6 , V_48 ) ;
V_4 -> V_168 = V_168 ;
F_6 ( V_4 -> V_18 ) = V_16 ;
F_5 () ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
memset ( & V_4 -> V_2 , 0 , sizeof( V_4 -> V_2 ) ) ;
V_4 -> V_2 . V_180 = F_1 ;
V_4 -> V_2 . V_181 = F_45 ( 64 ) ;
V_4 -> V_2 . V_48 = V_48 ;
V_4 -> V_2 . V_182 = 1 ;
F_12 ( & V_4 -> V_28 , & V_4 -> V_2 ,
F_46 ( F_47 () ) ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_183 * V_184 = V_4 -> V_184 ;
switch ( V_4 -> V_6 . V_19 . type ) {
case V_20 :
snprintf ( V_4 -> V_13 . V_185 , 16 , L_1 , V_184 -> V_186 ) ;
V_4 -> V_13 . V_187 = V_188 ;
V_4 -> V_13 . V_189 = 250000000 ;
V_4 -> V_13 . V_190 = 0 ;
V_4 -> V_13 . V_191 = 0 ;
V_4 -> V_13 . V_192 = 0 ;
V_4 -> V_13 . V_193 = 1 ;
V_4 -> V_13 . V_194 = F_4 ;
V_4 -> V_13 . V_195 = F_9 ;
V_4 -> V_13 . V_196 = F_14 ;
V_4 -> V_13 . V_197 = F_16 ;
V_4 -> V_13 . V_198 = F_17 ;
break;
case V_22 :
snprintf ( V_4 -> V_13 . V_185 , 16 , L_1 , V_184 -> V_186 ) ;
V_4 -> V_13 . V_187 = V_188 ;
V_4 -> V_13 . V_189 = 250000000 ;
V_4 -> V_13 . V_190 = 0 ;
V_4 -> V_13 . V_191 = 0 ;
V_4 -> V_13 . V_192 = 0 ;
V_4 -> V_13 . V_193 = 0 ;
V_4 -> V_13 . V_194 = F_4 ;
V_4 -> V_13 . V_195 = F_9 ;
V_4 -> V_13 . V_196 = F_14 ;
V_4 -> V_13 . V_197 = F_16 ;
V_4 -> V_13 . V_198 = F_17 ;
break;
default:
V_4 -> V_46 = NULL ;
return;
}
if ( F_49 ( V_84 , F_50 ( V_84 ) ) )
F_51 ( L_2 ) ;
F_52 ( & V_4 -> V_27 ) ;
F_44 ( V_4 ) ;
V_4 -> V_39 |= V_74 ;
V_4 -> V_46 = F_53 ( & V_4 -> V_13 ) ;
if ( F_54 ( V_4 -> V_46 ) ) {
V_4 -> V_46 = NULL ;
F_55 ( L_3 ) ;
} else
F_56 ( L_4 , V_184 -> V_185 ) ;
return;
}
void F_57 ( struct V_3 * V_4 )
{
F_21 ( & V_4 -> V_6 ) ;
V_4 -> V_39 &= ~ V_74 ;
if ( V_4 -> V_46 ) {
F_58 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
F_56 ( L_5 ,
V_4 -> V_184 -> V_185 ) ;
}
}
