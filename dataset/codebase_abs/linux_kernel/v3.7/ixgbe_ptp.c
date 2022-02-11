static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
T_1 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
T_2 V_14 = 0 , V_15 = 0 ;
if ( ( V_2 -> V_16 & V_17 ) &&
( V_4 -> V_18 . type == V_19 ) ) {
F_2 ( V_4 , V_20 , 0x0 ) ;
F_3 ( V_4 ) ;
V_7 = F_4 ( V_4 , V_21 ) ;
V_7 |= ( V_22 |
V_23 ) ;
V_8 = ( V_24 |
V_25 |
V_26 ) ;
V_9 = ( T_1 ) ( V_27 << V_5 ) ;
V_10 = ( T_1 ) ( ( V_27 << V_5 ) >> 32 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_28 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_29 ) << 32 ;
V_14 = F_5 ( & V_2 -> V_30 , V_15 ) ;
F_6 ( V_14 , V_27 , & V_13 ) ;
V_15 += ( ( V_27 - ( T_2 ) V_13 ) << V_5 ) ;
V_11 = ( T_1 ) V_15 ;
V_12 = ( T_1 ) ( V_15 >> 32 ) ;
F_2 ( V_4 , V_31 , V_9 ) ;
F_2 ( V_4 , V_32 , V_10 ) ;
F_2 ( V_4 , V_33 , V_11 ) ;
F_2 ( V_4 , V_34 , V_12 ) ;
F_2 ( V_4 , V_21 , V_7 ) ;
F_2 ( V_4 , V_20 , V_8 ) ;
} else {
F_2 ( V_4 , V_20 , 0x0 ) ;
}
F_3 ( V_4 ) ;
}
static T_3 F_7 ( const struct V_35 * V_6 )
{
struct V_1 * V_2 =
F_8 ( V_6 , struct V_1 , V_6 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_36 = 0 ;
V_36 |= ( T_2 ) F_4 ( V_4 , V_28 ) ;
V_36 |= ( T_2 ) F_4 ( V_4 , V_29 ) << 32 ;
return V_36 ;
}
static int F_9 ( struct V_37 * V_38 , T_4 V_39 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_41 ;
T_1 V_42 , V_43 ;
int V_44 = 0 ;
if ( V_39 < 0 ) {
V_44 = 1 ;
V_39 = - V_39 ;
}
F_10 () ;
V_43 = F_11 ( V_2 -> V_45 ) ;
V_41 = V_43 ;
V_41 *= V_39 ;
V_42 = F_12 ( V_41 , 1000000000ULL ) ;
V_43 = V_44 ? ( V_43 - V_42 ) : ( V_43 + V_42 ) ;
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , T_5 V_49 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
unsigned long V_50 ;
T_2 V_51 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_51 = F_15 ( & V_2 -> V_30 ) ;
V_51 += V_49 ;
F_16 ( & V_2 -> V_30 ,
& V_2 -> V_6 ,
V_51 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
T_1 V_55 ;
unsigned long V_50 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_15 ( & V_2 -> V_30 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_54 -> V_56 = F_6 ( V_14 , 1000000000ULL , & V_55 ) ;
V_54 -> V_57 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 ,
const struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
unsigned long V_50 ;
V_14 = V_54 -> V_56 * 1000000000ULL ;
V_14 += V_54 -> V_57 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 , V_14 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_58 * V_59 , int V_60 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
if ( V_59 -> type == V_61 ) {
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
if ( V_60 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_1 ( V_2 ) ;
return 0 ;
default:
break;
}
}
return - V_62 ;
}
void F_21 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_64 V_65 ;
switch ( V_4 -> V_18 . type ) {
case V_19 :
V_64 ( V_2 -> V_66 , & V_65 ) ;
break;
default:
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
unsigned long V_67 = V_2 -> V_68 - V_69 ;
struct V_53 V_54 ;
if ( ( V_2 -> V_16 & V_70 ) &&
( V_67 >= V_71 ) ) {
F_18 ( & V_2 -> V_40 , & V_54 ) ;
V_2 -> V_68 = V_69 ;
}
}
static int F_23 ( struct V_72 * V_73 , int V_74 )
{
struct V_75 V_76 ;
T_6 V_77 ;
unsigned int type , V_78 ;
if ( V_74 == V_79 )
return 0 ;
type = F_24 ( V_73 , V_80 ) ;
if ( F_25 ( V_74 == V_81 ) )
return type & V_82 ;
switch ( type ) {
case V_83 :
F_26 ( V_73 , V_84 , & V_76 , sizeof( V_76 ) ) ;
V_78 = V_85 + ( V_76 . V_86 << 2 ) + V_87 + V_88 ;
break;
case V_89 :
V_78 = V_90 + V_88 ;
break;
default:
return 0 ;
}
if ( V_73 -> V_91 < V_78 )
return 0 ;
F_26 ( V_73 , V_78 , & V_77 , sizeof( V_77 ) ) ;
switch ( V_74 ) {
case V_92 :
return ( V_77 == V_93 ) ;
break;
case V_94 :
return ( V_77 == V_95 ) ;
break;
default:
return 0 ;
}
}
void F_27 ( struct V_96 * V_97 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_98 V_99 ;
T_2 V_100 = 0 , V_14 ;
T_1 V_101 ;
unsigned long V_50 ;
if ( ! V_97 || ! V_97 -> V_2 )
return;
V_2 = V_97 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_101 = F_4 ( V_4 , V_102 ) ;
V_100 |= ( T_2 ) F_4 ( V_4 , V_103 ) ;
V_100 |= ( T_2 ) F_4 ( V_4 , V_104 ) << 32 ;
if ( ! ( V_101 & V_105 ) )
return;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_100 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_106 = F_28 ( V_14 ) ;
F_29 ( V_73 , & V_99 ) ;
}
void F_30 ( struct V_96 * V_97 ,
union V_107 * V_108 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_98 * V_99 ;
T_2 V_100 = 0 , V_14 ;
T_1 V_109 ;
unsigned long V_50 ;
if ( ! V_97 || ! V_97 -> V_2 )
return;
V_2 = V_97 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_109 = F_4 ( V_4 , V_110 ) ;
if ( F_25 ( ! ( V_109 & V_111 ) ||
! F_23 ( V_73 , V_2 -> V_112 ) ) )
return;
V_100 |= ( T_2 ) F_4 ( V_4 , V_113 ) ;
V_100 |= ( T_2 ) F_4 ( V_4 , V_114 ) << 32 ;
if ( F_31 ( ! F_32 ( V_108 , V_115 ) ) )
return;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_100 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_99 = F_33 ( V_73 ) ;
V_99 -> V_106 = F_28 ( V_14 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_116 * V_117 , int V_118 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_119 V_120 ;
T_1 V_121 = V_122 ;
T_1 V_123 = V_124 ;
T_1 V_125 = 0 ;
bool V_126 = false ;
bool V_127 = false ;
T_1 V_100 ;
if ( F_35 ( & V_120 , V_117 -> V_128 , sizeof( V_120 ) ) )
return - V_129 ;
if ( V_120 . V_50 )
return - V_130 ;
switch ( V_120 . V_131 ) {
case V_132 :
V_121 = 0 ;
case V_133 :
break;
default:
return - V_134 ;
}
switch ( V_120 . V_74 ) {
case V_79 :
V_123 = 0 ;
break;
case V_92 :
V_123 |= V_135 ;
V_125 = V_93 ;
V_126 = true ;
break;
case V_94 :
V_123 |= V_135 ;
V_125 = V_95 ;
V_126 = true ;
break;
case V_81 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_123 |= V_144 ;
V_127 = true ;
V_126 = true ;
V_120 . V_74 = V_81 ;
break;
case V_145 :
case V_146 :
default:
V_120 . V_74 = V_79 ;
return - V_134 ;
}
if ( V_4 -> V_18 . type == V_147 ) {
if ( V_123 | V_121 )
return - V_134 ;
return 0 ;
}
V_2 -> V_112 = V_120 . V_74 ;
if ( V_127 )
F_2 ( V_4 , F_36 ( 3 ) ,
( V_148 |
V_149 |
V_150 ) ) ;
else
F_2 ( V_4 , F_36 ( 3 ) , 0 ) ;
#define F_37 319
if ( V_126 ) {
T_1 V_151 = ( V_152
| V_153
| V_154 ) ;
V_151 |= ( ( V_155
& V_156
& V_157 )
<< V_158 ) ;
F_2 ( V_4 , F_38 ( 3 ) ,
( 3 << V_159 |
V_160 ) ) ;
F_2 ( V_4 , F_39 ( 3 ) ,
( F_40 ( F_37 ) |
F_40 ( F_37 ) << 16 ) ) ;
F_2 ( V_4 , F_41 ( 3 ) , V_151 ) ;
V_125 |= F_37 << 16 ;
} else {
F_2 ( V_4 , F_41 ( 3 ) , 0 ) ;
}
V_100 = F_4 ( V_4 , V_102 ) ;
V_100 &= ~ V_122 ;
V_100 |= V_121 ;
F_2 ( V_4 , V_102 , V_100 ) ;
V_100 = F_4 ( V_4 , V_110 ) ;
V_100 &= ~ ( V_124 | V_161 ) ;
V_100 |= V_123 ;
F_2 ( V_4 , V_110 , V_100 ) ;
F_2 ( V_4 , V_162 , V_125 ) ;
F_3 ( V_4 ) ;
V_100 = F_4 ( V_4 , V_104 ) ;
V_100 = F_4 ( V_4 , V_114 ) ;
return F_42 ( V_117 -> V_128 , & V_120 , sizeof( V_120 ) ) ?
- V_129 : 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_43 = 0 ;
T_1 V_163 = 0 ;
T_1 V_5 = 0 ;
T_1 V_164 ;
unsigned long V_50 ;
switch ( V_2 -> V_165 ) {
case V_166 :
case V_167 :
case V_168 :
V_164 = V_2 -> V_165 ;
break;
default:
V_164 = V_168 ;
break;
}
V_163 = F_4 ( V_4 , V_46 ) ;
if ( V_2 -> V_164 == V_164 && V_163 )
return;
switch ( V_164 ) {
case V_166 :
V_43 = V_169 ;
V_5 = V_170 ;
break;
case V_167 :
V_43 = V_171 ;
V_5 = V_172 ;
break;
case V_168 :
V_43 = V_173 ;
V_5 = V_174 ;
break;
}
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
V_43 >>= V_175 ;
V_5 -= V_175 ;
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
return;
}
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
V_2 -> V_164 = V_164 ;
F_11 ( V_2 -> V_45 ) = V_43 ;
F_10 () ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_6 . V_176 = F_7 ;
V_2 -> V_6 . V_177 = F_44 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_178 = 1 ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_45 ( F_46 () ) ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_179 * V_180 = V_2 -> V_180 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
snprintf ( V_2 -> V_40 . V_181 , 16 , L_1 , V_180 -> V_182 ) ;
V_2 -> V_40 . V_183 = V_184 ;
V_2 -> V_40 . V_185 = 250000000 ;
V_2 -> V_40 . V_186 = 0 ;
V_2 -> V_40 . V_187 = 0 ;
V_2 -> V_40 . V_188 = 0 ;
V_2 -> V_40 . V_189 = 1 ;
V_2 -> V_40 . V_190 = F_9 ;
V_2 -> V_40 . V_191 = F_13 ;
V_2 -> V_40 . V_192 = F_18 ;
V_2 -> V_40 . V_193 = F_19 ;
V_2 -> V_40 . V_194 = F_20 ;
break;
case V_47 :
snprintf ( V_2 -> V_40 . V_181 , 16 , L_1 , V_180 -> V_182 ) ;
V_2 -> V_40 . V_183 = V_184 ;
V_2 -> V_40 . V_185 = 250000000 ;
V_2 -> V_40 . V_186 = 0 ;
V_2 -> V_40 . V_187 = 0 ;
V_2 -> V_40 . V_188 = 0 ;
V_2 -> V_40 . V_189 = 0 ;
V_2 -> V_40 . V_190 = F_9 ;
V_2 -> V_40 . V_191 = F_13 ;
V_2 -> V_40 . V_192 = F_18 ;
V_2 -> V_40 . V_193 = F_19 ;
V_2 -> V_40 . V_194 = F_20 ;
break;
default:
V_2 -> V_66 = NULL ;
return;
}
if ( F_48 ( V_80 , F_49 ( V_80 ) ) )
F_50 ( L_2 ) ;
F_51 ( & V_2 -> V_52 ) ;
F_43 ( V_2 ) ;
V_2 -> V_16 |= V_70 ;
V_2 -> V_66 = F_52 ( & V_2 -> V_40 ,
& V_2 -> V_195 -> V_196 ) ;
if ( F_53 ( V_2 -> V_66 ) ) {
V_2 -> V_66 = NULL ;
F_54 ( L_3 ) ;
} else
F_55 ( L_4 , V_180 -> V_181 ) ;
return;
}
void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_16 &= ~ ( V_70 |
V_17 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_66 ) {
F_57 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
F_55 ( L_5 ,
V_2 -> V_180 -> V_181 ) ;
}
}
