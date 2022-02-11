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
T_1 V_54 ;
unsigned long V_50 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_18 ( & V_2 -> V_30 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
V_53 -> V_55 = F_6 ( V_14 , 1000000000ULL , & V_54 ) ;
V_53 -> V_56 = V_54 ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
unsigned long V_50 ;
V_14 = V_53 -> V_55 * 1000000000ULL ;
V_14 += V_53 -> V_56 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
F_20 ( & V_2 -> V_30 , & V_2 -> V_6 , V_14 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 ,
struct V_57 * V_58 , int V_59 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
if ( V_58 -> type == V_60 ) {
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
if ( V_59 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_1 ( V_2 ) ;
return 0 ;
default:
break;
}
}
return - V_61 ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_62 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_63 V_64 ;
V_64 . type = V_65 ;
if ( ! V_2 -> V_66 )
return;
switch ( V_4 -> V_18 . type ) {
case V_19 :
V_63 ( V_2 -> V_66 , & V_64 ) ;
break;
default:
break;
}
}
void F_23 ( struct V_1 * V_2 )
{
bool V_67 = F_24 ( V_2 -> V_68 +
V_69 ) ;
struct V_52 V_53 ;
if ( V_67 ) {
F_17 ( & V_2 -> V_40 , & V_53 ) ;
V_2 -> V_68 = V_70 ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_71 = F_4 ( V_4 , V_72 ) ;
unsigned long V_73 ;
if ( ! ( V_71 & V_74 ) ) {
V_2 -> V_75 = V_70 ;
return;
}
V_73 = V_2 -> V_75 ;
if ( F_26 ( V_2 -> V_76 , V_73 ) )
V_73 = V_2 -> V_76 ;
if ( F_24 ( V_73 + 5 * V_77 ) ) {
F_4 ( V_4 , V_78 ) ;
V_2 -> V_75 = V_70 ;
F_27 ( V_79 , L_1 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_80 V_81 ;
T_2 V_82 = 0 , V_14 ;
unsigned long V_50 ;
V_82 |= ( T_2 ) F_4 ( V_4 , V_83 ) ;
V_82 |= ( T_2 ) F_4 ( V_4 , V_84 ) << 32 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_82 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_85 = F_29 ( V_14 ) ;
F_30 ( V_2 -> V_86 , & V_81 ) ;
F_31 ( V_2 -> V_86 ) ;
V_2 -> V_86 = NULL ;
F_32 ( V_87 , & V_2 -> V_88 ) ;
}
static void F_33 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_8 ( V_90 , struct V_1 ,
V_91 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_67 = F_24 ( V_2 -> V_92 +
V_93 ) ;
T_1 V_94 ;
if ( V_67 ) {
F_31 ( V_2 -> V_86 ) ;
V_2 -> V_86 = NULL ;
F_32 ( V_87 , & V_2 -> V_88 ) ;
F_27 ( V_79 , L_2 ) ;
return;
}
V_94 = F_4 ( V_4 , V_95 ) ;
if ( V_94 & V_96 )
F_28 ( V_2 ) ;
else
F_34 ( & V_2 -> V_91 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_80 * V_81 ;
T_2 V_82 = 0 , V_14 ;
T_1 V_71 ;
unsigned long V_50 ;
V_71 = F_4 ( V_4 , V_72 ) ;
if ( ! ( V_71 & V_74 ) )
return;
V_82 |= ( T_2 ) F_4 ( V_4 , V_99 ) ;
V_82 |= ( T_2 ) F_4 ( V_4 , V_78 ) << 32 ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_82 ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
V_81 = F_36 ( V_98 ) ;
V_81 -> V_85 = F_29 ( V_14 ) ;
V_2 -> V_76 = V_70 ;
}
int F_37 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_102 * V_103 = & V_2 -> V_104 ;
return F_38 ( V_101 -> V_105 , V_103 ,
sizeof( * V_103 ) ) ? - V_106 : 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_107 = V_108 ;
T_1 V_109 = V_110 ;
T_1 V_111 = V_112 << 16 ;
bool V_113 = false ;
T_1 V_82 ;
if ( V_103 -> V_50 )
return - V_114 ;
switch ( V_103 -> V_115 ) {
case V_116 :
V_107 = 0 ;
case V_117 :
break;
default:
return - V_118 ;
}
switch ( V_103 -> V_119 ) {
case V_120 :
V_109 = 0 ;
V_111 = 0 ;
break;
case V_121 :
V_109 |= V_122 ;
V_111 |= V_123 ;
break;
case V_124 :
V_109 |= V_122 ;
V_111 |= V_125 ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_109 |= V_135 ;
V_113 = true ;
V_103 -> V_119 = V_126 ;
break;
case V_136 :
case V_137 :
default:
V_103 -> V_119 = V_120 ;
return - V_118 ;
}
if ( V_4 -> V_18 . type == V_138 ) {
if ( V_109 | V_107 )
return - V_118 ;
return 0 ;
}
if ( V_113 )
F_2 ( V_4 , F_40 ( V_139 ) ,
( V_140 |
V_141 |
V_142 ) ) ;
else
F_2 ( V_4 , F_40 ( V_139 ) , 0 ) ;
V_82 = F_4 ( V_4 , V_95 ) ;
V_82 &= ~ V_108 ;
V_82 |= V_107 ;
F_2 ( V_4 , V_95 , V_82 ) ;
V_82 = F_4 ( V_4 , V_72 ) ;
V_82 &= ~ ( V_110 | V_143 ) ;
V_82 |= V_109 ;
F_2 ( V_4 , V_72 , V_82 ) ;
F_2 ( V_4 , V_144 , V_111 ) ;
F_3 ( V_4 ) ;
V_82 = F_4 ( V_4 , V_84 ) ;
V_82 = F_4 ( V_4 , V_78 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_102 V_103 ;
int V_145 ;
if ( F_42 ( & V_103 , V_101 -> V_105 , sizeof( V_103 ) ) )
return - V_106 ;
V_145 = F_39 ( V_2 , & V_103 ) ;
if ( V_145 )
return V_145 ;
memcpy ( & V_2 -> V_104 , & V_103 ,
sizeof( V_2 -> V_104 ) ) ;
return F_38 ( V_101 -> V_105 , & V_103 , sizeof( V_103 ) ) ?
- V_106 : 0 ;
}
void F_43 ( struct V_1 * V_2 )
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
F_14 ( & V_2 -> V_51 , V_50 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_6 . V_157 = F_7 ;
V_2 -> V_6 . V_158 = F_44 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_159 = 1 ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_50 ;
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
F_39 ( V_2 , & V_2 -> V_104 ) ;
F_43 ( V_2 ) ;
F_14 ( & V_2 -> V_51 , V_50 ) ;
F_20 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_46 ( F_47 () ) ) ;
F_16 ( & V_2 -> V_51 , V_50 ) ;
F_1 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_160 * V_161 = V_2 -> V_161 ;
long V_145 ;
if ( ! F_49 ( V_2 -> V_66 ) )
return 0 ;
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
V_2 -> V_40 . V_172 = F_17 ;
V_2 -> V_40 . V_173 = F_19 ;
V_2 -> V_40 . V_174 = F_21 ;
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
V_2 -> V_40 . V_172 = F_17 ;
V_2 -> V_40 . V_173 = F_19 ;
V_2 -> V_40 . V_174 = F_21 ;
break;
default:
V_2 -> V_66 = NULL ;
return - V_175 ;
}
V_2 -> V_66 = F_50 ( & V_2 -> V_40 ,
& V_2 -> V_176 -> V_177 ) ;
if ( F_51 ( V_2 -> V_66 ) ) {
V_145 = F_52 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
F_53 ( L_4 ) ;
return V_145 ;
} else
F_54 ( L_5 , V_161 -> V_162 ) ;
V_2 -> V_104 . V_119 = V_120 ;
V_2 -> V_104 . V_115 = V_116 ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_51 ) ;
if ( F_48 ( V_2 ) )
return;
F_57 ( & V_2 -> V_91 , F_33 ) ;
F_45 ( V_2 ) ;
F_58 ( V_178 , & V_2 -> V_88 ) ;
return;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ! F_60 ( V_178 , & V_2 -> V_88 ) )
return;
F_2 ( & V_2 -> V_4 , V_20 , 0x0 ) ;
F_61 ( & V_2 -> V_91 ) ;
if ( V_2 -> V_86 ) {
F_31 ( V_2 -> V_86 ) ;
V_2 -> V_86 = NULL ;
F_32 ( V_87 , & V_2 -> V_88 ) ;
}
}
void F_62 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
if ( V_2 -> V_66 ) {
F_63 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
F_54 ( L_6 ,
V_2 -> V_161 -> V_162 ) ;
}
}
