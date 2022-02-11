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
if ( V_21 == V_39 )
V_11 |= V_40 | V_41 ;
}
F_2 ( V_11 , & V_2 -> V_42 ) ;
V_11 = 0 ;
if ( V_21 == V_36 ) {
if ( V_23 ) {
V_11 |= ( V_43 |
V_44 ) ;
} else {
V_11 |= ( V_45 |
V_44 ) ;
}
} else {
V_11 |= ( V_46 |
V_47 ) ;
}
F_2 ( V_11 , & V_2 -> V_48 ) ;
F_2 ( 0xffffffff , & V_2 -> V_49 ) ;
F_6 ( V_2 , V_24 , true ) ;
return 0 ;
}
static void F_8 ( struct V_19 * V_20 )
{
V_20 -> V_50 = false ;
V_20 -> V_25 = false ;
V_20 -> V_27 = false ;
V_20 -> V_51 = V_52 ;
V_20 -> V_32 = V_53 ;
V_20 -> V_34 = V_54 ;
}
static T_3 F_9 ( T_6 V_55 )
{
T_6 V_56 , V_57 ;
T_3 V_58 = 0 ;
T_2 V_59 , V_60 ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ ) {
V_56 = V_55 & ( T_6 ) 0x01 ;
V_55 >>= 1 ;
for ( V_60 = 0 ; V_60 < 7 ; V_60 ++ ) {
V_57 = V_55 & ( T_6 ) 0x01 ;
V_56 ^= V_57 ;
V_55 >>= 1 ;
}
V_58 |= ( V_56 << ( 5 - V_59 ) ) ;
}
return V_58 ;
}
static void F_10 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
T_5 V_65 ;
if ( F_11 ( ! V_62 -> V_66 ) )
return;
V_65 = V_67 ;
if ( ! V_64 )
V_65 |= V_68 ;
else {
switch ( V_64 -> V_22 ) {
case 10 :
break;
case 100 :
V_65 |= V_69 ;
break;
case 1000 :
default:
V_65 |= V_70 ;
break;
}
if ( ! V_64 -> V_71 )
V_65 |= V_72 ;
}
F_12 ( V_62 -> V_66 , V_73 , V_65 ) ;
V_65 = V_74 ;
F_12 ( V_62 -> V_66 , V_75 , V_65 ) ;
F_12 ( V_62 -> V_66 , V_76 , V_77 ) ;
F_12 ( V_62 -> V_66 , V_78 , V_79 ) ;
if ( ! V_64 )
V_65 = V_80 | V_81 ;
else
V_65 = V_80 & ~ V_82 ;
F_12 ( V_62 -> V_66 , 0x0 , V_65 ) ;
}
static void F_13 ( struct V_61 * V_62 )
{
T_5 V_65 ;
V_65 = V_83 ;
F_12 ( V_62 -> V_66 , V_75 , V_65 ) ;
F_12 ( V_62 -> V_66 , V_76 , V_84 ) ;
F_12 ( V_62 -> V_66 , V_78 , V_85 ) ;
V_65 = V_80 | V_81 ;
F_12 ( V_62 -> V_66 , 0x0 , V_65 ) ;
}
static int F_14 ( struct V_61 * V_62 )
{
if ( V_62 -> V_86 == 0 ) {
F_15 ( L_1 ) ;
return - V_87 ;
}
if ( ! V_62 -> V_88 ) {
F_15 ( L_2 ) ;
return - V_87 ;
}
if ( ! V_62 -> V_89 ) {
F_16 ( L_3 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_17 ( enum V_90 V_91 )
{
T_3 V_92 ;
switch ( V_91 ) {
case V_93 :
V_92 = V_94 ;
break;
case V_95 :
V_92 = V_96 ;
break;
case V_97 :
V_92 = V_98 ;
break;
case V_99 :
V_92 = V_100 ;
break;
default:
V_92 = 0 ;
break;
}
return V_92 ;
}
static void F_18 ( void * V_101 )
{
struct V_61 * V_62 = (struct V_61 * ) V_101 ;
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_102 , V_18 ;
V_102 = F_4 ( & V_2 -> V_49 ) ;
V_18 = F_4 ( & V_2 -> V_18 ) ;
V_102 &= ( ( V_18 & V_103 ) >> 16 ) ;
F_2 ( V_102 , & V_2 -> V_49 ) ;
if ( V_102 & V_104 )
V_62 -> V_88 ( V_62 -> V_105 , V_97 ) ;
if ( V_102 & V_106 )
V_62 -> V_88 ( V_62 -> V_105 , V_93 ) ;
if ( V_102 & V_107 )
V_62 -> V_88 ( V_62 -> V_105 , V_95 ) ;
}
static void F_19 ( void * V_101 )
{
struct V_61 * V_62 = (struct V_61 * ) V_101 ;
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_102 , V_18 ;
V_102 = F_4 ( & V_2 -> V_49 ) ;
V_18 = F_4 ( & V_2 -> V_18 ) ;
V_102 &= ( ( V_18 & V_103 ) >> 16 ) ;
F_2 ( V_102 , & V_2 -> V_49 ) ;
if ( V_102 & V_108 )
V_62 -> V_88 ( V_62 -> V_105 ,
V_99 ) ;
}
static void F_20 ( struct V_61 * V_62 )
{
F_21 ( V_62 -> V_109 , V_110 , V_62 -> V_111 ,
V_112 ) ;
F_21 ( V_62 -> V_109 , V_110 , V_62 -> V_111 ,
V_113 ) ;
F_22 ( V_62 -> V_114 ) ;
V_62 -> V_114 = NULL ;
F_22 ( V_62 -> V_115 ) ;
V_62 -> V_115 = NULL ;
}
static bool F_23 ( struct V_19 * V_116 )
{
if ( ! V_116 )
return true ;
return false ;
}
int F_24 ( struct V_61 * V_62 , enum V_117 V_118 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_118 & V_120 )
V_11 |= V_121 ;
if ( V_118 & V_122 )
V_11 |= V_123 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_25 ( struct V_61 * V_62 , enum V_117 V_118 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_118 & V_120 )
V_11 &= ~ V_121 ;
if ( V_118 & V_122 )
V_11 &= ~ V_123 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_26 ( struct V_61 * V_62 , bool V_124 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_124 )
V_11 |= V_26 ;
else
V_11 &= ~ V_26 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_27 ( struct V_61 * V_62 , T_5 V_22 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_42 ) ;
V_11 &= ~ V_125 ;
if ( V_62 -> V_21 == V_39 ) {
V_11 &= ~ V_41 ;
V_11 &= ~ V_126 ;
V_11 |= V_127 ;
switch ( V_22 ) {
case V_128 :
V_11 |= V_129 ;
break;
case V_130 :
V_11 |= V_131 ;
break;
case V_132 :
V_11 |= V_133 ;
break;
default:
break;
}
}
F_2 ( V_11 , & V_2 -> V_42 ) ;
return 0 ;
}
int F_28 ( struct V_61 * V_62 , T_5 V_124 )
{
if ( F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_62 -> V_119 -> V_32 = V_124 ;
return 0 ;
}
int F_29 ( struct V_61 * V_62 , bool V_17 )
{
if ( F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_62 -> V_119 -> V_50 = V_17 ;
return 0 ;
}
int F_30 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
if ( F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_62 -> V_119 -> V_64 = V_64 ;
return 0 ;
}
int F_31 ( struct V_61 * V_62 , T_2 V_134 ,
T_5 V_135 , T_5 V_136 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_48 ) ;
F_32 ( V_11 ) ;
F_2 ( V_11 , & V_2 -> V_48 ) ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
V_11 &= ~ V_137 ;
V_134 = 0 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
V_11 = F_4 ( & V_2 -> V_34 [ V_134 / 2 ] ) ;
if ( V_134 % 2 )
V_11 &= V_138 ;
else
V_11 &= V_139 ;
V_11 |= ( ( T_3 ) V_135 << ( 16 * ( V_134 % 2 ) ) ) ;
F_2 ( V_11 , & V_2 -> V_34 [ V_134 / 2 ] ) ;
V_11 = F_4 ( & V_2 -> V_35 [ V_134 / 2 ] ) ;
if ( V_134 % 2 )
V_11 &= V_140 ;
else
V_11 &= V_141 ;
V_11 |= ( ( T_3 ) V_136 << ( 16 * ( V_134 % 2 ) ) ) ;
F_2 ( V_11 , & V_2 -> V_35 [ V_134 / 2 ] ) ;
return 0 ;
}
int F_33 ( struct V_61 * V_62 , bool V_142 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
T_3 V_11 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_11 = F_4 ( & V_2 -> V_13 ) ;
if ( V_142 )
V_11 &= ~ V_28 ;
else
V_11 |= V_28 ;
F_2 ( V_11 , & V_2 -> V_13 ) ;
return 0 ;
}
int F_34 ( struct V_61 * V_62 , T_7 * V_143 )
{
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
F_1 ( V_62 -> V_2 , ( T_2 * ) ( * V_143 ) , 0 ) ;
return 0 ;
}
int F_35 ( struct V_61 * V_62 , T_7 * V_55 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
struct V_144 * V_145 ;
T_3 V_146 ;
T_6 V_86 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_86 = F_36 ( * V_55 ) ;
if ( ! ( V_86 & V_147 ) ) {
F_15 ( L_4 ) ;
return - V_87 ;
}
V_146 = F_9 ( V_86 ) & V_148 ;
V_145 = F_37 ( sizeof( * V_145 ) , V_149 ) ;
if ( ! V_145 )
return - V_150 ;
V_145 -> V_86 = V_86 ;
F_38 ( & V_145 -> V_151 ) ;
F_39 ( & V_145 -> V_151 ,
& V_62 -> V_114 -> V_152 [ V_146 ] ) ;
F_2 ( V_146 | V_153 , & V_2 -> V_154 ) ;
return 0 ;
}
int F_40 ( struct V_61 * V_62 , T_7 * V_55 )
{
struct V_1 T_1 * V_2 = V_62 -> V_2 ;
struct V_144 * V_145 = NULL ;
struct V_155 * V_156 ;
T_3 V_146 ;
T_6 V_86 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_86 = F_36 ( * V_55 ) ;
V_146 = F_9 ( V_86 ) & V_148 ;
F_41 (pos, &memac->multicast_addr_hash->lsts[hash]) {
V_145 = F_42 ( V_156 ) ;
if ( V_145 -> V_86 == V_86 ) {
F_43 ( & V_145 -> V_151 ) ;
F_44 ( V_145 ) ;
break;
}
}
if ( F_45 ( & V_62 -> V_114 -> V_152 [ V_146 ] ) )
F_2 ( V_146 & ~ V_153 , & V_2 -> V_154 ) ;
return 0 ;
}
int F_46 ( struct V_61 * V_62 ,
enum V_90 V_91 , bool V_17 )
{
T_3 V_92 = 0 ;
if ( ! F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_92 = F_17 ( V_91 ) ;
if ( V_92 ) {
if ( V_17 )
V_62 -> V_24 |= V_92 ;
else
V_62 -> V_24 &= ~ V_92 ;
} else {
F_15 ( L_5 ) ;
return - V_87 ;
}
F_6 ( V_62 -> V_2 , V_92 , V_17 ) ;
return 0 ;
}
int F_47 ( struct V_61 * V_62 )
{
struct V_19 * V_119 ;
T_2 V_59 ;
T_7 V_55 ;
bool V_23 = false ;
struct V_63 * V_64 ;
int V_157 ;
T_3 V_158 = 0 ;
if ( F_23 ( V_62 -> V_119 ) )
return - V_87 ;
V_157 = F_14 ( V_62 ) ;
if ( V_157 )
return V_157 ;
V_119 = V_62 -> V_119 ;
if ( V_62 -> V_159 . V_160 == 6 && V_62 -> V_159 . V_161 == 4 )
V_23 = true ;
if ( V_119 -> V_50 ) {
V_157 = F_3 ( V_62 -> V_2 ) ;
if ( V_157 ) {
F_15 ( L_6 ) ;
return V_157 ;
}
}
F_48 ( V_62 -> V_86 , V_55 ) ;
F_1 ( V_62 -> V_2 , ( T_2 * ) V_55 , 0 ) ;
V_64 = V_119 -> V_64 ;
F_7 ( V_62 -> V_2 , V_62 -> V_119 , V_62 -> V_21 ,
V_62 -> V_162 , V_23 , V_62 -> V_24 ) ;
if ( ( V_62 -> V_159 . V_160 == 6 ) &&
( ( V_62 -> V_159 . V_161 == 0 ) ||
( V_62 -> V_159 . V_161 == 3 ) ) ) {
V_158 = F_4 ( & V_62 -> V_2 -> V_13 ) ;
V_158 &= ~ V_31 ;
F_2 ( V_158 , & V_62 -> V_2 -> V_13 ) ;
}
if ( V_62 -> V_21 == V_163 ) {
if ( V_62 -> V_164 )
F_13 ( V_62 ) ;
else
F_10 ( V_62 , V_64 ) ;
} else if ( V_62 -> V_21 == V_165 ) {
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
T_2 V_166 , V_167 ;
V_167 = V_62 -> V_66 -> V_168 . V_86 ;
V_166 = ( T_2 ) ( ( V_167 << 2 ) | V_59 ) ;
V_62 -> V_66 -> V_168 . V_86 = V_166 ;
if ( V_62 -> V_164 )
F_13 ( V_62 ) ;
else
F_10 ( V_62 , V_64 ) ;
V_62 -> V_66 -> V_168 . V_86 = V_167 ;
}
}
V_157 = F_49 ( V_62 -> V_109 , V_62 -> V_111 ,
V_119 -> V_32 ) ;
if ( V_157 ) {
F_15 ( L_7 ) ;
return V_157 ;
}
V_62 -> V_114 = F_50 ( V_169 ) ;
if ( ! V_62 -> V_114 ) {
F_20 ( V_62 ) ;
F_15 ( L_8 ) ;
return - V_150 ;
}
V_62 -> V_115 = F_50 ( V_169 ) ;
if ( ! V_62 -> V_115 ) {
F_20 ( V_62 ) ;
F_15 ( L_8 ) ;
return - V_150 ;
}
F_51 ( V_62 -> V_109 , V_110 , V_62 -> V_111 ,
V_112 , F_18 , V_62 ) ;
F_51 ( V_62 -> V_109 , V_110 , V_62 -> V_111 ,
V_113 , F_19 , V_62 ) ;
F_44 ( V_119 ) ;
V_62 -> V_119 = NULL ;
return 0 ;
}
int F_52 ( struct V_61 * V_62 )
{
F_20 ( V_62 ) ;
if ( V_62 -> V_66 )
F_53 ( & V_62 -> V_66 -> V_168 . V_170 ) ;
F_44 ( V_62 -> V_119 ) ;
F_44 ( V_62 ) ;
return 0 ;
}
struct V_61 * F_54 ( struct V_171 * V_172 )
{
struct V_61 * V_62 ;
struct V_19 * V_119 ;
void T_1 * V_173 ;
V_173 = V_172 -> V_173 ;
V_62 = F_55 ( sizeof( * V_62 ) , V_149 ) ;
if ( ! V_62 )
return NULL ;
V_119 = F_55 ( sizeof( * V_119 ) , V_149 ) ;
if ( ! V_119 ) {
F_52 ( V_62 ) ;
return NULL ;
}
V_62 -> V_119 = V_119 ;
F_8 ( V_119 ) ;
V_62 -> V_86 = F_36 ( V_172 -> V_86 ) ;
V_62 -> V_2 = V_173 ;
V_62 -> V_162 = V_172 -> V_162 ;
V_62 -> V_21 = V_172 -> V_21 ;
V_62 -> V_111 = V_172 -> V_111 ;
V_62 -> V_24 = ( V_98 | V_94 |
V_96 | V_100 ) ;
V_62 -> V_88 = V_172 -> V_88 ;
V_62 -> V_89 = V_172 -> V_89 ;
V_62 -> V_105 = V_172 -> V_105 ;
V_62 -> V_109 = V_172 -> V_109 ;
V_62 -> V_164 = V_172 -> V_164 ;
F_56 ( V_62 -> V_109 , & V_62 -> V_159 ) ;
if ( V_62 -> V_21 == V_163 ||
V_62 -> V_21 == V_165 ) {
if ( ! V_172 -> V_174 ) {
F_15 ( L_9 ) ;
F_52 ( V_62 ) ;
return NULL ;
}
V_62 -> V_66 = F_57 ( V_172 -> V_174 ) ;
if ( ! V_62 -> V_66 ) {
F_15 ( L_10 ) ;
F_52 ( V_62 ) ;
return NULL ;
}
}
return V_62 ;
}
