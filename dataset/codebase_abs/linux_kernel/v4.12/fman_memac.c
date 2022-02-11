static void F_1 ( struct V_1 T_1 * V_2 , T_2 * V_3 ,
T_2 V_4 )
{
T_3 V_5 , V_6 ;
V_5 = ( T_3 ) ( V_3 [ 0 ] | V_3 [ 1 ] << 8 | V_3 [ 2 ] << 16 | V_3 [ 3 ] << 24 ) ;
V_6 = ( T_3 ) ( V_3 [ 4 ] | V_3 [ 5 ] << 8 ) ;
if ( V_4 == 0 ) {
F_2 ( V_5 , & V_2 -> V_7 . V_8 ) ;
F_2 ( V_6 , & V_2 -> V_7 . V_9 ) ;
} else {
F_2 ( V_5 , & V_2 -> V_10 [ V_4 - 1 ] . V_8 ) ;
F_2 ( V_6 , & V_2 -> V_10 [ V_4 - 1 ] . V_9 ) ;
}
}
static int F_3 ( struct V_1 T_1 * V_2 )
{
T_3 V_11 ;
int V_12 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
V_11 |= V_14 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
V_12 = 100 ;
do {
F_5 ( 1 ) ;
} while ( ( F_4 ( & V_2 -> V_13 ) & V_14 ) &&
-- V_12 );
if ( V_12 == 0 )
return - V_15 ;
return 0 ;
}
static void F_6 ( struct V_1 T_1 * V_2 , T_3 V_16 ,
bool V_17 )
{
T_3 V_11 ;
V_11 = F_4 ( & V_2 -> V_18 ) ;
if ( V_17 )
V_11 |= V_16 ;
else
V_11 &= ~ V_16 ;
F_2 ( V_11 , & V_2 -> V_18 ) ;
}
static int F_7 ( struct V_1 T_1 * V_2 , struct V_19 * V_20 ,
T_4 V_21 , T_5 V_22 , bool V_23 ,
T_3 V_24 )
{
T_3 V_11 ;
V_11 = 0 ;
if ( V_20 -> V_25 )
V_11 |= V_26 ;
if ( V_20 -> V_27 )
V_11 |= V_28 ;
V_11 |= V_29 ;
V_11 |= V_30 ;
V_11 |= V_31 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
F_2 ( ( T_3 ) V_20 -> V_32 , & V_2 -> V_33 ) ;
F_2 ( ( T_3 ) V_20 -> V_34 , & V_2 -> V_34 [ 0 ] ) ;
F_2 ( ( T_3 ) 0 , & V_2 -> V_35 [ 0 ] ) ;
V_11 = 0 ;
switch ( V_21 ) {
case V_36 :
V_11 |= V_37 ;
break;
default:
V_11 |= V_38 ;
if ( V_21 == V_39 ||
V_21 == V_40 ||
V_21 == V_41 ||
V_21 == V_42 )
V_11 |= V_43 | V_44 ;
}
F_2 ( V_11 , & V_2 -> V_45 ) ;
V_11 = 0 ;
if ( V_21 == V_36 ) {
if ( V_23 ) {
V_11 |= ( V_46 |
V_47 ) ;
} else {
V_11 |= ( V_48 |
V_47 ) ;
}
} else {
V_11 |= ( V_49 |
V_50 ) ;
}
F_2 ( V_11 , & V_2 -> V_51 ) ;
F_2 ( 0xffffffff , & V_2 -> V_52 ) ;
F_6 ( V_2 , V_24 , true ) ;
return 0 ;
}
static void F_8 ( struct V_19 * V_20 )
{
V_20 -> V_53 = false ;
V_20 -> V_25 = false ;
V_20 -> V_27 = false ;
V_20 -> V_54 = V_55 ;
V_20 -> V_32 = V_56 ;
V_20 -> V_34 = V_57 ;
}
static T_3 F_9 ( T_6 V_58 )
{
T_6 V_59 , V_60 ;
T_3 V_61 = 0 ;
T_2 V_62 , V_63 ;
for ( V_62 = 0 ; V_62 < 6 ; V_62 ++ ) {
V_59 = V_58 & ( T_6 ) 0x01 ;
V_58 >>= 1 ;
for ( V_63 = 0 ; V_63 < 7 ; V_63 ++ ) {
V_60 = V_58 & ( T_6 ) 0x01 ;
V_59 ^= V_60 ;
V_58 >>= 1 ;
}
V_61 |= ( V_59 << ( 5 - V_62 ) ) ;
}
return V_61 ;
}
static void F_10 ( struct V_64 * V_65 ,
struct V_66 * V_67 )
{
T_5 V_68 ;
if ( F_11 ( ! V_65 -> V_69 ) )
return;
V_68 = V_70 ;
if ( ! V_67 )
V_68 |= V_71 ;
else {
switch ( V_67 -> V_22 ) {
case 10 :
break;
case 100 :
V_68 |= V_72 ;
break;
case 1000 :
default:
V_68 |= V_73 ;
break;
}
if ( ! V_67 -> V_74 )
V_68 |= V_75 ;
}
F_12 ( V_65 -> V_69 , V_76 , V_68 ) ;
V_68 = V_77 ;
F_12 ( V_65 -> V_69 , V_78 , V_68 ) ;
F_12 ( V_65 -> V_69 , V_79 , V_80 ) ;
F_12 ( V_65 -> V_69 , V_81 , V_82 ) ;
if ( ! V_67 )
V_68 = V_83 | V_84 ;
else
V_68 = V_83 & ~ V_85 ;
F_12 ( V_65 -> V_69 , 0x0 , V_68 ) ;
}
static void F_13 ( struct V_64 * V_65 )
{
T_5 V_68 ;
V_68 = V_86 ;
F_12 ( V_65 -> V_69 , V_78 , V_68 ) ;
F_12 ( V_65 -> V_69 , V_79 , V_87 ) ;
F_12 ( V_65 -> V_69 , V_81 , V_88 ) ;
V_68 = V_83 | V_84 ;
F_12 ( V_65 -> V_69 , 0x0 , V_68 ) ;
}
static int F_14 ( struct V_64 * V_65 )
{
if ( V_65 -> V_89 == 0 ) {
F_15 ( L_1 ) ;
return - V_90 ;
}
if ( ! V_65 -> V_91 ) {
F_15 ( L_2 ) ;
return - V_90 ;
}
if ( ! V_65 -> V_92 ) {
F_16 ( L_3 ) ;
return - V_90 ;
}
return 0 ;
}
static int F_17 ( enum V_93 V_94 )
{
T_3 V_95 ;
switch ( V_94 ) {
case V_96 :
V_95 = V_97 ;
break;
case V_98 :
V_95 = V_99 ;
break;
case V_100 :
V_95 = V_101 ;
break;
case V_102 :
V_95 = V_103 ;
break;
default:
V_95 = 0 ;
break;
}
return V_95 ;
}
static void F_18 ( void * V_104 )
{
struct V_64 * V_65 = (struct V_64 * ) V_104 ;
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_105 , V_18 ;
V_105 = F_4 ( & V_2 -> V_52 ) ;
V_18 = F_4 ( & V_2 -> V_18 ) ;
V_105 &= ( ( V_18 & V_106 ) >> 16 ) ;
F_2 ( V_105 , & V_2 -> V_52 ) ;
if ( V_105 & V_107 )
V_65 -> V_91 ( V_65 -> V_108 , V_100 ) ;
if ( V_105 & V_109 )
V_65 -> V_91 ( V_65 -> V_108 , V_96 ) ;
if ( V_105 & V_110 )
V_65 -> V_91 ( V_65 -> V_108 , V_98 ) ;
}
static void F_19 ( void * V_104 )
{
struct V_64 * V_65 = (struct V_64 * ) V_104 ;
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_105 , V_18 ;
V_105 = F_4 ( & V_2 -> V_52 ) ;
V_18 = F_4 ( & V_2 -> V_18 ) ;
V_105 &= ( ( V_18 & V_106 ) >> 16 ) ;
F_2 ( V_105 , & V_2 -> V_52 ) ;
if ( V_105 & V_111 )
V_65 -> V_91 ( V_65 -> V_108 ,
V_102 ) ;
}
static void F_20 ( struct V_64 * V_65 )
{
F_21 ( V_65 -> V_112 , V_113 , V_65 -> V_114 ,
V_115 ) ;
F_21 ( V_65 -> V_112 , V_113 , V_65 -> V_114 ,
V_116 ) ;
F_22 ( V_65 -> V_117 ) ;
V_65 -> V_117 = NULL ;
F_22 ( V_65 -> V_118 ) ;
V_65 -> V_118 = NULL ;
}
static bool F_23 ( struct V_19 * V_119 )
{
if ( ! V_119 )
return true ;
return false ;
}
int F_24 ( struct V_64 * V_65 , enum V_120 V_121 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_121 & V_123 )
V_11 |= V_124 ;
if ( V_121 & V_125 )
V_11 |= V_126 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_25 ( struct V_64 * V_65 , enum V_120 V_121 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_121 & V_123 )
V_11 &= ~ V_124 ;
if ( V_121 & V_125 )
V_11 &= ~ V_126 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_26 ( struct V_64 * V_65 , bool V_127 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_127 )
V_11 |= V_26 ;
else
V_11 &= ~ V_26 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_27 ( struct V_64 * V_65 , T_5 V_22 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_45 ) ;
V_11 &= ~ V_128 ;
if ( V_65 -> V_21 == V_39 ) {
V_11 &= ~ V_44 ;
V_11 &= ~ V_129 ;
V_11 |= V_130 ;
switch ( V_22 ) {
case V_131 :
V_11 |= V_132 ;
break;
case V_133 :
V_11 |= V_134 ;
break;
case V_135 :
V_11 |= V_136 ;
break;
default:
break;
}
}
F_2 ( V_11 , & V_2 -> V_45 ) ;
return 0 ;
}
int F_28 ( struct V_64 * V_65 , T_5 V_127 )
{
if ( F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_65 -> V_122 -> V_32 = V_127 ;
return 0 ;
}
int F_29 ( struct V_64 * V_65 , bool V_17 )
{
if ( F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_65 -> V_122 -> V_53 = V_17 ;
return 0 ;
}
int F_30 ( struct V_64 * V_65 ,
struct V_66 * V_67 )
{
if ( F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_65 -> V_122 -> V_67 = V_67 ;
return 0 ;
}
int F_31 ( struct V_64 * V_65 , T_2 V_137 ,
T_5 V_138 , T_5 V_139 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_51 ) ;
F_32 ( V_11 ) ;
F_2 ( V_11 , & V_2 -> V_51 ) ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
V_11 &= ~ V_140 ;
V_137 = 0 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
V_11 = F_4 ( & V_2 -> V_34 [ V_137 / 2 ] ) ;
if ( V_137 % 2 )
V_11 &= V_141 ;
else
V_11 &= V_142 ;
V_11 |= ( ( T_3 ) V_138 << ( 16 * ( V_137 % 2 ) ) ) ;
F_2 ( V_11 , & V_2 -> V_34 [ V_137 / 2 ] ) ;
V_11 = F_4 ( & V_2 -> V_35 [ V_137 / 2 ] ) ;
if ( V_137 % 2 )
V_11 &= V_143 ;
else
V_11 &= V_144 ;
V_11 |= ( ( T_3 ) V_139 << ( 16 * ( V_137 % 2 ) ) ) ;
F_2 ( V_11 , & V_2 -> V_35 [ V_137 / 2 ] ) ;
return 0 ;
}
int F_33 ( struct V_64 * V_65 , bool V_145 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_145 )
V_11 &= ~ V_28 ;
else
V_11 |= V_28 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_34 ( struct V_64 * V_65 , T_7 * V_146 )
{
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
F_1 ( V_65 -> V_2 , ( T_2 * ) ( * V_146 ) , 0 ) ;
return 0 ;
}
int F_35 ( struct V_64 * V_65 , T_7 * V_58 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
struct V_147 * V_148 ;
T_3 V_149 ;
T_6 V_89 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_89 = F_36 ( * V_58 ) ;
if ( ! ( V_89 & V_150 ) ) {
F_15 ( L_4 ) ;
return - V_90 ;
}
V_149 = F_9 ( V_89 ) & V_151 ;
V_148 = F_37 ( sizeof( * V_148 ) , V_152 ) ;
if ( ! V_148 )
return - V_153 ;
V_148 -> V_89 = V_89 ;
F_38 ( & V_148 -> V_154 ) ;
F_39 ( & V_148 -> V_154 ,
& V_65 -> V_117 -> V_155 [ V_149 ] ) ;
F_2 ( V_149 | V_156 , & V_2 -> V_157 ) ;
return 0 ;
}
int F_40 ( struct V_64 * V_65 , T_7 * V_58 )
{
struct V_1 T_1 * V_2 = V_65 -> V_2 ;
struct V_147 * V_148 = NULL ;
struct V_158 * V_159 ;
T_3 V_149 ;
T_6 V_89 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_89 = F_36 ( * V_58 ) ;
V_149 = F_9 ( V_89 ) & V_151 ;
F_41 (pos, &memac->multicast_addr_hash->lsts[hash]) {
V_148 = F_42 ( V_159 ) ;
if ( V_148 -> V_89 == V_89 ) {
F_43 ( & V_148 -> V_154 ) ;
F_44 ( V_148 ) ;
break;
}
}
if ( F_45 ( & V_65 -> V_117 -> V_155 [ V_149 ] ) )
F_2 ( V_149 & ~ V_156 , & V_2 -> V_157 ) ;
return 0 ;
}
int F_46 ( struct V_64 * V_65 ,
enum V_93 V_94 , bool V_17 )
{
T_3 V_95 = 0 ;
if ( ! F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_95 = F_17 ( V_94 ) ;
if ( V_95 ) {
if ( V_17 )
V_65 -> V_24 |= V_95 ;
else
V_65 -> V_24 &= ~ V_95 ;
} else {
F_15 ( L_5 ) ;
return - V_90 ;
}
F_6 ( V_65 -> V_2 , V_95 , V_17 ) ;
return 0 ;
}
int F_47 ( struct V_64 * V_65 )
{
struct V_19 * V_122 ;
T_2 V_62 ;
T_7 V_58 ;
bool V_23 = false ;
struct V_66 * V_67 ;
int V_160 ;
T_3 V_161 = 0 ;
if ( F_23 ( V_65 -> V_122 ) )
return - V_90 ;
V_160 = F_14 ( V_65 ) ;
if ( V_160 )
return V_160 ;
V_122 = V_65 -> V_122 ;
if ( V_65 -> V_162 . V_163 == 6 && V_65 -> V_162 . V_164 == 4 )
V_23 = true ;
if ( V_122 -> V_53 ) {
V_160 = F_3 ( V_65 -> V_2 ) ;
if ( V_160 ) {
F_15 ( L_6 ) ;
return V_160 ;
}
}
F_48 ( V_65 -> V_89 , V_58 ) ;
F_1 ( V_65 -> V_2 , ( T_2 * ) V_58 , 0 ) ;
V_67 = V_122 -> V_67 ;
F_7 ( V_65 -> V_2 , V_65 -> V_122 , V_65 -> V_21 ,
V_65 -> V_165 , V_23 , V_65 -> V_24 ) ;
if ( ( V_65 -> V_162 . V_163 == 6 ) &&
( ( V_65 -> V_162 . V_164 == 0 ) ||
( V_65 -> V_162 . V_164 == 3 ) ) ) {
V_161 = F_4 ( & V_65 -> V_2 -> V_13 ) ;
V_161 &= ~ V_31 ;
F_2 ( V_161 , & V_65 -> V_2 -> V_13 ) ;
}
if ( V_65 -> V_21 == V_166 ) {
if ( V_65 -> V_167 )
F_13 ( V_65 ) ;
else
F_10 ( V_65 , V_67 ) ;
} else if ( V_65 -> V_21 == V_168 ) {
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_2 V_169 , V_170 ;
V_170 = V_65 -> V_69 -> V_171 . V_89 ;
V_169 = ( T_2 ) ( ( V_170 << 2 ) | V_62 ) ;
V_65 -> V_69 -> V_171 . V_89 = V_169 ;
if ( V_65 -> V_167 )
F_13 ( V_65 ) ;
else
F_10 ( V_65 , V_67 ) ;
V_65 -> V_69 -> V_171 . V_89 = V_170 ;
}
}
V_160 = F_49 ( V_65 -> V_112 , V_65 -> V_114 ,
V_122 -> V_32 ) ;
if ( V_160 ) {
F_15 ( L_7 ) ;
return V_160 ;
}
V_65 -> V_117 = F_50 ( V_172 ) ;
if ( ! V_65 -> V_117 ) {
F_20 ( V_65 ) ;
F_15 ( L_8 ) ;
return - V_153 ;
}
V_65 -> V_118 = F_50 ( V_172 ) ;
if ( ! V_65 -> V_118 ) {
F_20 ( V_65 ) ;
F_15 ( L_8 ) ;
return - V_153 ;
}
F_51 ( V_65 -> V_112 , V_113 , V_65 -> V_114 ,
V_115 , F_18 , V_65 ) ;
F_51 ( V_65 -> V_112 , V_113 , V_65 -> V_114 ,
V_116 , F_19 , V_65 ) ;
F_44 ( V_122 ) ;
V_65 -> V_122 = NULL ;
return 0 ;
}
int F_52 ( struct V_64 * V_65 )
{
F_20 ( V_65 ) ;
if ( V_65 -> V_69 )
F_53 ( & V_65 -> V_69 -> V_171 . V_173 ) ;
F_44 ( V_65 -> V_122 ) ;
F_44 ( V_65 ) ;
return 0 ;
}
struct V_64 * F_54 ( struct V_174 * V_175 )
{
struct V_64 * V_65 ;
struct V_19 * V_122 ;
void T_1 * V_176 ;
V_176 = V_175 -> V_176 ;
V_65 = F_55 ( sizeof( * V_65 ) , V_152 ) ;
if ( ! V_65 )
return NULL ;
V_122 = F_55 ( sizeof( * V_122 ) , V_152 ) ;
if ( ! V_122 ) {
F_52 ( V_65 ) ;
return NULL ;
}
V_65 -> V_122 = V_122 ;
F_8 ( V_122 ) ;
V_65 -> V_89 = F_36 ( V_175 -> V_89 ) ;
V_65 -> V_2 = V_176 ;
V_65 -> V_165 = V_175 -> V_165 ;
V_65 -> V_21 = V_175 -> V_21 ;
V_65 -> V_114 = V_175 -> V_114 ;
V_65 -> V_24 = ( V_101 | V_97 |
V_99 | V_103 ) ;
V_65 -> V_91 = V_175 -> V_91 ;
V_65 -> V_92 = V_175 -> V_92 ;
V_65 -> V_108 = V_175 -> V_108 ;
V_65 -> V_112 = V_175 -> V_112 ;
V_65 -> V_167 = V_175 -> V_167 ;
F_56 ( V_65 -> V_112 , & V_65 -> V_162 ) ;
if ( V_65 -> V_21 == V_166 ||
V_65 -> V_21 == V_168 ) {
if ( ! V_175 -> V_177 ) {
F_15 ( L_9 ) ;
F_52 ( V_65 ) ;
return NULL ;
}
V_65 -> V_69 = F_57 ( V_175 -> V_177 ) ;
if ( ! V_65 -> V_69 ) {
F_15 ( L_10 ) ;
F_52 ( V_65 ) ;
return NULL ;
}
}
return V_65 ;
}
