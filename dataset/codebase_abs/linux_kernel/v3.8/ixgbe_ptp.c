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
V_65 . type = V_66 ;
if ( ! V_2 -> V_67 )
return;
switch ( V_4 -> V_18 . type ) {
case V_19 :
V_64 ( V_2 -> V_67 , & V_65 ) ;
break;
default:
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
unsigned long V_68 = V_2 -> V_69 - V_70 ;
struct V_53 V_54 ;
if ( ( V_2 -> V_16 & V_71 ) &&
( V_68 >= V_72 ) ) {
F_18 ( & V_2 -> V_40 , & V_54 ) ;
V_2 -> V_69 = V_70 ;
}
}
static int F_23 ( struct V_73 * V_74 , int V_75 )
{
struct V_76 V_77 ;
T_6 V_78 ;
unsigned int type , V_79 ;
if ( V_75 == V_80 )
return 0 ;
type = F_24 ( V_74 , V_81 ) ;
if ( F_25 ( V_75 == V_82 ) )
return type & V_83 ;
switch ( type ) {
case V_84 :
F_26 ( V_74 , V_85 , & V_77 , sizeof( V_77 ) ) ;
V_79 = V_86 + ( V_77 . V_87 << 2 ) + V_88 + V_89 ;
break;
case V_90 :
V_79 = V_91 + V_89 ;
break;
default:
return 0 ;
}
if ( V_74 -> V_92 < V_79 )
return 0 ;
F_26 ( V_74 , V_79 , & V_78 , sizeof( V_78 ) ) ;
switch ( V_75 ) {
case V_93 :
return ( V_78 == V_94 ) ;
break;
case V_95 :
return ( V_78 == V_96 ) ;
break;
default:
return 0 ;
}
}
void F_27 ( struct V_97 * V_98 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_99 V_100 ;
T_2 V_101 = 0 , V_14 ;
T_1 V_102 ;
unsigned long V_50 ;
if ( ! V_98 || ! V_98 -> V_2 )
return;
V_2 = V_98 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_102 = F_4 ( V_4 , V_103 ) ;
V_101 |= ( T_2 ) F_4 ( V_4 , V_104 ) ;
V_101 |= ( T_2 ) F_4 ( V_4 , V_105 ) << 32 ;
if ( ! ( V_102 & V_106 ) )
return;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_101 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_107 = F_28 ( V_14 ) ;
F_29 ( V_74 , & V_100 ) ;
}
void F_30 ( struct V_97 * V_98 ,
union V_108 * V_109 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_99 * V_100 ;
T_2 V_101 = 0 , V_14 ;
T_1 V_110 ;
unsigned long V_50 ;
if ( ! V_98 || ! V_98 -> V_2 )
return;
V_2 = V_98 -> V_2 ;
V_4 = & V_2 -> V_4 ;
if ( F_25 ( ! F_23 ( V_74 , V_2 -> V_111 ) ) )
return;
V_110 = F_4 ( V_4 , V_112 ) ;
if ( ! ( V_110 & V_113 ) )
return;
V_101 |= ( T_2 ) F_4 ( V_4 , V_114 ) ;
V_101 |= ( T_2 ) F_4 ( V_4 , V_115 ) << 32 ;
if ( F_31 ( ! F_32 ( V_109 , V_116 ) ) )
return;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_101 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_100 = F_33 ( V_74 ) ;
V_100 -> V_107 = F_28 ( V_14 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_117 * V_118 , int V_119 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_120 V_121 ;
T_1 V_122 = V_123 ;
T_1 V_124 = V_125 ;
T_1 V_126 = V_127 << 16 ;
bool V_128 = false ;
T_1 V_101 ;
if ( F_35 ( & V_121 , V_118 -> V_129 , sizeof( V_121 ) ) )
return - V_130 ;
if ( V_121 . V_50 )
return - V_131 ;
switch ( V_121 . V_132 ) {
case V_133 :
V_122 = 0 ;
case V_134 :
break;
default:
return - V_135 ;
}
switch ( V_121 . V_75 ) {
case V_80 :
V_124 = 0 ;
V_126 = 0 ;
break;
case V_93 :
V_124 |= V_136 ;
V_126 |= V_94 ;
break;
case V_95 :
V_124 |= V_136 ;
V_126 |= V_96 ;
break;
case V_82 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_124 |= V_145 ;
V_128 = true ;
V_121 . V_75 = V_82 ;
break;
case V_146 :
case V_147 :
default:
V_121 . V_75 = V_80 ;
return - V_135 ;
}
if ( V_4 -> V_18 . type == V_148 ) {
if ( V_124 | V_122 )
return - V_135 ;
return 0 ;
}
V_2 -> V_111 = V_121 . V_75 ;
if ( V_128 )
F_2 ( V_4 , F_36 ( V_149 ) ,
( V_150 |
V_151 |
V_152 ) ) ;
else
F_2 ( V_4 , F_36 ( V_149 ) , 0 ) ;
V_101 = F_4 ( V_4 , V_103 ) ;
V_101 &= ~ V_123 ;
V_101 |= V_122 ;
F_2 ( V_4 , V_103 , V_101 ) ;
V_101 = F_4 ( V_4 , V_112 ) ;
V_101 &= ~ ( V_125 | V_153 ) ;
V_101 |= V_124 ;
F_2 ( V_4 , V_112 , V_101 ) ;
F_2 ( V_4 , V_154 , V_126 ) ;
F_3 ( V_4 ) ;
V_101 = F_4 ( V_4 , V_105 ) ;
V_101 = F_4 ( V_4 , V_115 ) ;
return F_37 ( V_118 -> V_129 , & V_121 , sizeof( V_121 ) ) ?
- V_130 : 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_43 = 0 ;
T_1 V_5 = 0 ;
unsigned long V_50 ;
switch ( V_2 -> V_155 ) {
case V_156 :
V_43 = V_157 ;
V_5 = V_158 ;
break;
case V_159 :
V_43 = V_160 ;
V_5 = V_161 ;
break;
case V_162 :
default:
V_43 = V_163 ;
V_5 = V_164 ;
break;
}
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
V_43 >>= V_165 ;
V_5 -= V_165 ;
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
return;
}
F_11 ( V_2 -> V_45 ) = V_43 ;
F_10 () ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_6 . V_166 = F_7 ;
V_2 -> V_6 . V_167 = F_39 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_168 = 1 ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_50 ;
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
F_38 ( V_2 ) ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_41 ( F_42 () ) ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_169 * V_170 = V_2 -> V_170 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
snprintf ( V_2 -> V_40 . V_171 , 16 , L_1 , V_170 -> V_171 ) ;
V_2 -> V_40 . V_172 = V_173 ;
V_2 -> V_40 . V_174 = 250000000 ;
V_2 -> V_40 . V_175 = 0 ;
V_2 -> V_40 . V_176 = 0 ;
V_2 -> V_40 . V_177 = 0 ;
V_2 -> V_40 . V_178 = 1 ;
V_2 -> V_40 . V_179 = F_9 ;
V_2 -> V_40 . V_180 = F_13 ;
V_2 -> V_40 . V_181 = F_18 ;
V_2 -> V_40 . V_182 = F_19 ;
V_2 -> V_40 . V_183 = F_20 ;
break;
case V_47 :
snprintf ( V_2 -> V_40 . V_171 , 16 , L_1 , V_170 -> V_171 ) ;
V_2 -> V_40 . V_172 = V_173 ;
V_2 -> V_40 . V_174 = 250000000 ;
V_2 -> V_40 . V_175 = 0 ;
V_2 -> V_40 . V_176 = 0 ;
V_2 -> V_40 . V_177 = 0 ;
V_2 -> V_40 . V_178 = 0 ;
V_2 -> V_40 . V_179 = F_9 ;
V_2 -> V_40 . V_180 = F_13 ;
V_2 -> V_40 . V_181 = F_18 ;
V_2 -> V_40 . V_182 = F_19 ;
V_2 -> V_40 . V_183 = F_20 ;
break;
default:
V_2 -> V_67 = NULL ;
return;
}
if ( F_44 ( V_81 , F_45 ( V_81 ) ) )
F_46 ( L_2 ) ;
F_47 ( & V_2 -> V_52 ) ;
V_2 -> V_67 = F_48 ( & V_2 -> V_40 ,
& V_2 -> V_184 -> V_185 ) ;
if ( F_49 ( V_2 -> V_67 ) ) {
V_2 -> V_67 = NULL ;
F_50 ( L_3 ) ;
} else
F_51 ( L_4 , V_170 -> V_171 ) ;
F_40 ( V_2 ) ;
V_2 -> V_16 |= V_71 ;
return;
}
void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_16 &= ~ ( V_71 |
V_17 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_67 ) {
F_53 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_51 ( L_5 ,
V_2 -> V_170 -> V_171 ) ;
}
}
