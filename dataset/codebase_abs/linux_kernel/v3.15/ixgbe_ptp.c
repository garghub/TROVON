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
bool V_68 = F_23 ( V_2 -> V_69 +
V_70 ) ;
struct V_53 V_54 ;
if ( V_68 ) {
F_18 ( & V_2 -> V_40 , & V_54 ) ;
V_2 -> V_69 = V_71 ;
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_72 = F_4 ( V_4 , V_73 ) ;
unsigned long V_74 ;
if ( ! ( V_72 & V_75 ) ) {
V_2 -> V_76 = V_71 ;
return;
}
V_74 = V_2 -> V_76 ;
if ( F_25 ( V_2 -> V_77 , V_74 ) )
V_74 = V_2 -> V_77 ;
if ( F_23 ( V_74 + 5 * V_78 ) ) {
F_4 ( V_4 , V_79 ) ;
V_2 -> V_76 = V_71 ;
F_26 ( V_80 , L_1 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_81 V_82 ;
T_2 V_83 = 0 , V_14 ;
unsigned long V_50 ;
V_83 |= ( T_2 ) F_4 ( V_4 , V_84 ) ;
V_83 |= ( T_2 ) F_4 ( V_4 , V_85 ) << 32 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_83 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_86 = F_28 ( V_14 ) ;
F_29 ( V_2 -> V_87 , & V_82 ) ;
F_30 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
F_31 ( V_88 , & V_2 -> V_89 ) ;
}
static void F_32 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_8 ( V_91 , struct V_1 ,
V_92 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_68 = F_23 ( V_2 -> V_93 +
V_94 ) ;
T_1 V_95 ;
if ( V_68 ) {
F_30 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
F_31 ( V_88 , & V_2 -> V_89 ) ;
F_26 ( V_80 , L_2 ) ;
return;
}
V_95 = F_4 ( V_4 , V_96 ) ;
if ( V_95 & V_97 )
F_27 ( V_2 ) ;
else
F_33 ( & V_2 -> V_92 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_81 * V_82 ;
T_2 V_83 = 0 , V_14 ;
T_1 V_72 ;
unsigned long V_50 ;
V_72 = F_4 ( V_4 , V_73 ) ;
if ( ! ( V_72 & V_75 ) )
return;
V_83 |= ( T_2 ) F_4 ( V_4 , V_100 ) ;
V_83 |= ( T_2 ) F_4 ( V_4 , V_79 ) << 32 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_83 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_82 = F_35 ( V_99 ) ;
V_82 -> V_86 = F_28 ( V_14 ) ;
V_2 -> V_77 = V_71 ;
}
int F_36 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
struct V_103 * V_104 = & V_2 -> V_105 ;
return F_37 ( V_102 -> V_106 , V_104 ,
sizeof( * V_104 ) ) ? - V_107 : 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_103 V_104 ;
T_1 V_108 = V_109 ;
T_1 V_110 = V_111 ;
T_1 V_112 = V_113 << 16 ;
bool V_114 = false ;
T_1 V_83 ;
if ( F_39 ( & V_104 , V_102 -> V_106 , sizeof( V_104 ) ) )
return - V_107 ;
if ( V_104 . V_50 )
return - V_115 ;
switch ( V_104 . V_116 ) {
case V_117 :
V_108 = 0 ;
case V_118 :
break;
default:
return - V_119 ;
}
switch ( V_104 . V_120 ) {
case V_121 :
V_110 = 0 ;
V_112 = 0 ;
break;
case V_122 :
V_110 |= V_123 ;
V_112 |= V_124 ;
break;
case V_125 :
V_110 |= V_123 ;
V_112 |= V_126 ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
V_110 |= V_136 ;
V_114 = true ;
V_104 . V_120 = V_127 ;
break;
case V_137 :
case V_138 :
default:
V_104 . V_120 = V_121 ;
return - V_119 ;
}
if ( V_4 -> V_18 . type == V_139 ) {
if ( V_110 | V_108 )
return - V_119 ;
return 0 ;
}
if ( V_114 )
F_2 ( V_4 , F_40 ( V_140 ) ,
( V_141 |
V_142 |
V_143 ) ) ;
else
F_2 ( V_4 , F_40 ( V_140 ) , 0 ) ;
V_83 = F_4 ( V_4 , V_96 ) ;
V_83 &= ~ V_109 ;
V_83 |= V_108 ;
F_2 ( V_4 , V_96 , V_83 ) ;
V_83 = F_4 ( V_4 , V_73 ) ;
V_83 &= ~ ( V_111 | V_144 ) ;
V_83 |= V_110 ;
F_2 ( V_4 , V_73 , V_83 ) ;
F_2 ( V_4 , V_145 , V_112 ) ;
F_3 ( V_4 ) ;
V_83 = F_4 ( V_4 , V_85 ) ;
V_83 = F_4 ( V_4 , V_79 ) ;
memcpy ( & V_2 -> V_105 , & V_104 ,
sizeof( V_2 -> V_105 ) ) ;
return F_37 ( V_102 -> V_106 , & V_104 , sizeof( V_104 ) ) ?
- V_107 : 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_43 = 0 ;
T_1 V_5 = 0 ;
unsigned long V_50 ;
switch ( V_2 -> V_146 ) {
case V_147 :
V_43 = V_148 ;
V_5 = V_149 ;
break;
case V_150 :
V_43 = V_151 ;
V_5 = V_152 ;
break;
case V_153 :
default:
V_43 = V_154 ;
V_5 = V_155 ;
break;
}
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
V_43 >>= V_156 ;
V_5 -= V_156 ;
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
V_2 -> V_6 . V_157 = F_7 ;
V_2 -> V_6 . V_158 = F_42 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_159 = 1 ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_50 ;
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
memset ( & V_2 -> V_105 , 0 , sizeof( V_2 -> V_105 ) ) ;
F_41 ( V_2 ) ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_44 ( F_45 () ) ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
snprintf ( V_2 -> V_40 . V_162 ,
sizeof( V_2 -> V_40 . V_162 ) ,
L_3 , V_161 -> V_162 ) ;
V_2 -> V_40 . V_163 = V_164 ;
V_2 -> V_40 . V_165 = 250000000 ;
V_2 -> V_40 . V_166 = 0 ;
V_2 -> V_40 . V_167 = 0 ;
V_2 -> V_40 . V_168 = 0 ;
V_2 -> V_40 . V_169 = 1 ;
V_2 -> V_40 . V_170 = F_9 ;
V_2 -> V_40 . V_171 = F_13 ;
V_2 -> V_40 . V_172 = F_18 ;
V_2 -> V_40 . V_173 = F_19 ;
V_2 -> V_40 . V_174 = F_20 ;
break;
case V_47 :
snprintf ( V_2 -> V_40 . V_162 ,
sizeof( V_2 -> V_40 . V_162 ) ,
L_3 , V_161 -> V_162 ) ;
V_2 -> V_40 . V_163 = V_164 ;
V_2 -> V_40 . V_165 = 250000000 ;
V_2 -> V_40 . V_166 = 0 ;
V_2 -> V_40 . V_167 = 0 ;
V_2 -> V_40 . V_168 = 0 ;
V_2 -> V_40 . V_169 = 0 ;
V_2 -> V_40 . V_170 = F_9 ;
V_2 -> V_40 . V_171 = F_13 ;
V_2 -> V_40 . V_172 = F_18 ;
V_2 -> V_40 . V_173 = F_19 ;
V_2 -> V_40 . V_174 = F_20 ;
break;
default:
V_2 -> V_67 = NULL ;
return;
}
F_47 ( & V_2 -> V_52 ) ;
F_48 ( & V_2 -> V_92 , F_32 ) ;
V_2 -> V_67 = F_49 ( & V_2 -> V_40 ,
& V_2 -> V_175 -> V_176 ) ;
if ( F_50 ( V_2 -> V_67 ) ) {
V_2 -> V_67 = NULL ;
F_51 ( L_4 ) ;
} else
F_52 ( L_5 , V_161 -> V_162 ) ;
F_43 ( V_2 ) ;
F_53 ( V_177 , & V_2 -> V_89 ) ;
return;
}
void F_54 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_177 , & V_2 -> V_89 ) )
return;
V_2 -> V_16 &= ~ V_17 ;
F_1 ( V_2 ) ;
F_56 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_87 ) {
F_30 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
F_31 ( V_88 , & V_2 -> V_89 ) ;
}
if ( V_2 -> V_67 ) {
F_57 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_52 ( L_6 ,
V_2 -> V_161 -> V_162 ) ;
}
}
