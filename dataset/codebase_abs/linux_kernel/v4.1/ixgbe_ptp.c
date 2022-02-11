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
F_14 ( & V_2 -> V_51 , V_50 ) ;
F_15 ( & V_2 -> V_30 , V_49 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 , struct V_52 * V_53 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
unsigned long V_50 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_18 ( & V_2 -> V_30 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
* V_53 = F_19 ( V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
unsigned long V_50 ;
V_14 = F_21 ( V_53 ) ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
F_22 ( & V_2 -> V_30 , & V_2 -> V_6 , V_14 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 ,
struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
if ( V_55 -> type == V_57 ) {
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
if ( V_56 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_1 ( V_2 ) ;
return 0 ;
default:
break;
}
}
return - V_58 ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_60 V_61 ;
V_61 . type = V_62 ;
if ( ! V_2 -> V_63 )
return;
switch ( V_4 -> V_18 . type ) {
case V_19 :
V_60 ( V_2 -> V_63 , & V_61 ) ;
break;
default:
break;
}
}
void F_25 ( struct V_1 * V_2 )
{
bool V_64 = F_26 ( V_2 -> V_65 +
V_66 ) ;
struct V_52 V_53 ;
if ( V_64 ) {
F_17 ( & V_2 -> V_40 , & V_53 ) ;
V_2 -> V_65 = V_67 ;
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_68 = F_4 ( V_4 , V_69 ) ;
unsigned long V_70 ;
if ( ! ( V_68 & V_71 ) ) {
V_2 -> V_72 = V_67 ;
return;
}
V_70 = V_2 -> V_72 ;
if ( F_28 ( V_2 -> V_73 , V_70 ) )
V_70 = V_2 -> V_73 ;
if ( F_26 ( V_70 + 5 * V_74 ) ) {
F_4 ( V_4 , V_75 ) ;
V_2 -> V_72 = V_67 ;
F_29 ( V_76 , L_1 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_77 V_78 ;
T_2 V_79 = 0 , V_14 ;
unsigned long V_50 ;
V_79 |= ( T_2 ) F_4 ( V_4 , V_80 ) ;
V_79 |= ( T_2 ) F_4 ( V_4 , V_81 ) << 32 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_79 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_82 = F_31 ( V_14 ) ;
F_32 ( V_2 -> V_83 , & V_78 ) ;
F_33 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
F_34 ( V_84 , & V_2 -> V_85 ) ;
}
static void F_35 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_8 ( V_87 , struct V_1 ,
V_88 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_64 = F_26 ( V_2 -> V_89 +
V_90 ) ;
T_1 V_91 ;
if ( V_64 ) {
F_33 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
F_34 ( V_84 , & V_2 -> V_85 ) ;
F_29 ( V_76 , L_2 ) ;
return;
}
V_91 = F_4 ( V_4 , V_92 ) ;
if ( V_91 & V_93 )
F_30 ( V_2 ) ;
else
F_36 ( & V_2 -> V_88 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_77 * V_78 ;
T_2 V_79 = 0 , V_14 ;
T_1 V_68 ;
unsigned long V_50 ;
V_68 = F_4 ( V_4 , V_69 ) ;
if ( ! ( V_68 & V_71 ) )
return;
V_79 |= ( T_2 ) F_4 ( V_4 , V_96 ) ;
V_79 |= ( T_2 ) F_4 ( V_4 , V_75 ) << 32 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_79 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
V_78 = F_38 ( V_95 ) ;
V_78 -> V_82 = F_31 ( V_14 ) ;
V_2 -> V_73 = V_67 ;
}
int F_39 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_99 * V_100 = & V_2 -> V_101 ;
return F_40 ( V_98 -> V_102 , V_100 ,
sizeof( * V_100 ) ) ? - V_103 : 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_104 = V_105 ;
T_1 V_106 = V_107 ;
T_1 V_108 = V_109 << 16 ;
bool V_110 = false ;
T_1 V_79 ;
if ( V_100 -> V_50 )
return - V_111 ;
switch ( V_100 -> V_112 ) {
case V_113 :
V_104 = 0 ;
case V_114 :
break;
default:
return - V_115 ;
}
switch ( V_100 -> V_116 ) {
case V_117 :
V_106 = 0 ;
V_108 = 0 ;
break;
case V_118 :
V_106 |= V_119 ;
V_108 |= V_120 ;
break;
case V_121 :
V_106 |= V_119 ;
V_108 |= V_122 ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_106 |= V_132 ;
V_110 = true ;
V_100 -> V_116 = V_123 ;
break;
case V_133 :
case V_134 :
default:
V_100 -> V_116 = V_117 ;
return - V_115 ;
}
if ( V_4 -> V_18 . type == V_135 ) {
if ( V_106 | V_104 )
return - V_115 ;
return 0 ;
}
if ( V_110 )
F_2 ( V_4 , F_42 ( V_136 ) ,
( V_137 |
V_138 |
V_139 ) ) ;
else
F_2 ( V_4 , F_42 ( V_136 ) , 0 ) ;
V_79 = F_4 ( V_4 , V_92 ) ;
V_79 &= ~ V_105 ;
V_79 |= V_104 ;
F_2 ( V_4 , V_92 , V_79 ) ;
V_79 = F_4 ( V_4 , V_69 ) ;
V_79 &= ~ ( V_107 | V_140 ) ;
V_79 |= V_106 ;
F_2 ( V_4 , V_69 , V_79 ) ;
F_2 ( V_4 , V_141 , V_108 ) ;
F_3 ( V_4 ) ;
V_79 = F_4 ( V_4 , V_81 ) ;
V_79 = F_4 ( V_4 , V_75 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_99 V_100 ;
int V_142 ;
if ( F_44 ( & V_100 , V_98 -> V_102 , sizeof( V_100 ) ) )
return - V_103 ;
V_142 = F_41 ( V_2 , & V_100 ) ;
if ( V_142 )
return V_142 ;
memcpy ( & V_2 -> V_101 , & V_100 ,
sizeof( V_2 -> V_101 ) ) ;
return F_40 ( V_98 -> V_102 , & V_100 , sizeof( V_100 ) ) ?
- V_103 : 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_43 = 0 ;
T_1 V_5 = 0 ;
unsigned long V_50 ;
switch ( V_2 -> V_143 ) {
case V_144 :
V_43 = V_145 ;
V_5 = V_146 ;
break;
case V_147 :
V_43 = V_148 ;
V_5 = V_149 ;
break;
case V_150 :
default:
V_43 = V_151 ;
V_5 = V_152 ;
break;
}
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
V_43 >>= V_153 ;
V_5 -= V_153 ;
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
return;
}
F_11 ( V_2 -> V_45 ) = V_43 ;
F_10 () ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_6 . V_154 = F_7 ;
V_2 -> V_6 . V_155 = F_46 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_156 = 1 ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_50 ;
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
F_41 ( V_2 , & V_2 -> V_101 ) ;
F_45 ( V_2 ) ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
F_22 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_48 ( F_49 () ) ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
F_1 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_157 * V_158 = V_2 -> V_158 ;
long V_142 ;
if ( ! F_51 ( V_2 -> V_63 ) )
return 0 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
snprintf ( V_2 -> V_40 . V_159 ,
sizeof( V_2 -> V_40 . V_159 ) ,
L_3 , V_158 -> V_159 ) ;
V_2 -> V_40 . V_160 = V_161 ;
V_2 -> V_40 . V_162 = 250000000 ;
V_2 -> V_40 . V_163 = 0 ;
V_2 -> V_40 . V_164 = 0 ;
V_2 -> V_40 . V_165 = 0 ;
V_2 -> V_40 . V_166 = 1 ;
V_2 -> V_40 . V_167 = F_9 ;
V_2 -> V_40 . V_168 = F_13 ;
V_2 -> V_40 . V_169 = F_17 ;
V_2 -> V_40 . V_170 = F_20 ;
V_2 -> V_40 . V_171 = F_23 ;
break;
case V_47 :
snprintf ( V_2 -> V_40 . V_159 ,
sizeof( V_2 -> V_40 . V_159 ) ,
L_3 , V_158 -> V_159 ) ;
V_2 -> V_40 . V_160 = V_161 ;
V_2 -> V_40 . V_162 = 250000000 ;
V_2 -> V_40 . V_163 = 0 ;
V_2 -> V_40 . V_164 = 0 ;
V_2 -> V_40 . V_165 = 0 ;
V_2 -> V_40 . V_166 = 0 ;
V_2 -> V_40 . V_167 = F_9 ;
V_2 -> V_40 . V_168 = F_13 ;
V_2 -> V_40 . V_169 = F_17 ;
V_2 -> V_40 . V_170 = F_20 ;
V_2 -> V_40 . V_171 = F_23 ;
break;
default:
V_2 -> V_63 = NULL ;
return - V_172 ;
}
V_2 -> V_63 = F_52 ( & V_2 -> V_40 ,
& V_2 -> V_173 -> V_174 ) ;
if ( F_53 ( V_2 -> V_63 ) ) {
V_142 = F_54 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
F_55 ( L_4 ) ;
return V_142 ;
} else
F_56 ( L_5 , V_158 -> V_159 ) ;
V_2 -> V_101 . V_116 = V_117 ;
V_2 -> V_101 . V_112 = V_113 ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_51 ) ;
if ( F_50 ( V_2 ) )
return;
F_59 ( & V_2 -> V_88 , F_35 ) ;
F_47 ( V_2 ) ;
F_60 ( V_175 , & V_2 -> V_85 ) ;
return;
}
void F_61 ( struct V_1 * V_2 )
{
if ( ! F_62 ( V_175 , & V_2 -> V_85 ) )
return;
F_2 ( & V_2 -> V_4 , V_20 , 0x0 ) ;
F_63 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_83 ) {
F_33 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
F_34 ( V_84 , & V_2 -> V_85 ) ;
}
}
void F_64 ( struct V_1 * V_2 )
{
F_61 ( V_2 ) ;
if ( V_2 -> V_63 ) {
F_65 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
F_56 ( L_6 ,
V_2 -> V_158 -> V_159 ) ;
}
}
