static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = V_8 -> V_10 . V_11 . V_12 ;
return V_9 ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_13 , V_14 ;
T_1 V_15 ;
struct V_16 V_17 ;
T_1 V_18 = F_4 ( V_8 ) ;
T_1 V_19 = 1 ;
int V_20 ;
T_1 V_21 = ( F_5 ( V_22 ) & V_23 ) >> V_24 ;
V_20 = F_6 ( V_8 , V_25 ,
25000 , false , & V_17 ) ;
if ( V_20 )
return;
V_15 = F_7 ( V_26 ) ;
V_15 &= ~ ( V_27 | V_28 ) ;
if ( V_19 )
V_15 |= F_8 ( 1 ) ;
V_15 |= F_9 ( V_17 . V_29 ) ;
F_10 ( V_26 , V_15 ) ;
F_11 ( 500 , V_18 , 16 , & V_13 , & V_14 ) ;
F_12 ( V_30 , F_13 ( V_13 ) | F_14 ( V_14 ) ) ;
F_15 ( V_31 , F_16 ( V_13 ) , ~ V_32 ) ;
if ( V_9 -> V_33 && ( V_21 == 0 ) )
F_17 ( V_8 ) ;
}
static void F_18 ( struct V_7 * V_8 ,
bool V_34 )
{
T_1 V_35 ;
T_1 V_36 ;
if ( V_34 ) {
V_35 = F_19 ( V_37 ) ;
V_36 = F_19 ( V_38 ) ;
F_20 ( V_37 ,
( 0x00380000 & V_39 ) | ( V_35 & ~ V_39 ) ) ;
F_20 ( V_38 ,
( 0x0E000000 & V_40 ) | ( V_36 & ~ V_40 ) ) ;
F_12 ( V_41 , V_42 ) ;
} else {
F_12 ( V_41 , V_43 ) ;
V_35 = F_19 ( V_37 ) ;
V_36 = F_19 ( V_38 ) ;
F_20 ( V_37 ,
V_39 | ( V_35 & ~ V_39 ) ) ;
F_20 ( V_38 ,
V_40 | ( V_36 & ~ V_40 ) ) ;
}
}
static void F_21 ( struct V_7 * V_8 )
{
T_1 V_44 ;
const T_1 * V_45 = NULL ;
V_45 = & V_46 [ 0 ] ;
V_44 = sizeof( V_46 ) / ( 3 * sizeof( T_1 ) ) ;
F_22 ( V_8 , V_45 , V_44 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
bool V_34 )
{
if ( V_34 ) {
F_15 ( V_47 , V_48 , ~ V_48 ) ;
} else {
F_15 ( V_47 , 0 , ~ V_48 ) ;
F_15 ( V_47 , V_49 , ~ V_49 ) ;
F_15 ( V_47 , 0 , ~ V_49 ) ;
F_5 ( V_50 ) ;
}
}
static void F_22 ( struct V_7 * V_8 ,
const T_1 * V_45 , T_1 V_44 )
{
T_1 V_51 , V_52 = V_44 * 3 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 += 3 )
F_15 ( V_45 [ V_51 ] , V_45 [ V_51 + 1 ] , ~ V_45 [ V_51 + 2 ] ) ;
}
static void F_24 ( struct V_7 * V_8 ,
const T_1 * V_45 , T_1 V_44 )
{
T_1 V_51 , V_52 = V_44 * 2 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 += 2 )
F_12 ( V_45 [ V_51 ] , V_45 [ V_51 + 1 ] ) ;
}
static void F_17 ( struct V_7 * V_8 )
{
T_1 V_44 ;
const T_1 * V_45 = NULL ;
V_45 = & V_53 [ 0 ] ;
V_44 = sizeof( V_53 ) / ( 2 * sizeof( T_1 ) ) ;
F_24 ( V_8 , V_45 , V_44 ) ;
}
static void F_25 ( struct V_7 * V_8 ,
bool V_34 )
{
T_1 V_44 ;
const T_1 * V_45 = NULL ;
if ( V_34 ) {
V_45 = & V_54 [ 0 ] ;
V_44 = sizeof( V_54 ) / ( 3 * sizeof( T_1 ) ) ;
} else {
V_45 = & V_55 [ 0 ] ;
V_44 = sizeof( V_55 ) / ( 3 * sizeof( T_1 ) ) ;
}
F_22 ( V_8 , V_45 , V_44 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
bool V_34 )
{
if ( V_34 ) {
if ( F_7 ( V_56 ) & V_57 )
F_10 ( V_58 , ( F_7 ( V_58 ) | 0x01 ) ) ;
F_15 ( V_47 , V_59 , ~ V_59 ) ;
} else {
F_15 ( V_47 , 0 , ~ V_59 ) ;
F_5 ( V_50 ) ;
}
}
static void F_27 ( struct V_7 * V_8 ,
bool V_34 )
{
T_1 V_15 ;
if ( V_34 ) {
V_15 = F_7 ( V_60 ) ;
V_15 &= ~ V_61 ;
V_15 |= F_28 ( 1 ) ;
F_10 ( V_60 , V_15 ) ;
V_15 = F_7 ( V_62 ) ;
V_15 &= ~ V_63 ;
V_15 |= F_29 ( 1 ) ;
F_10 ( V_62 , V_15 ) ;
} else {
V_15 = F_7 ( V_62 ) ;
V_15 &= ~ V_63 ;
F_10 ( V_62 , V_15 ) ;
V_15 = F_7 ( V_60 ) ;
V_15 &= ~ V_61 ;
F_10 ( V_60 , V_15 ) ;
}
F_30 ( V_8 ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_64 )
F_32 ( V_8 ) ;
if ( V_9 -> V_65 )
F_21 ( V_8 ) ;
if ( V_9 -> V_66 )
F_3 ( V_8 ) ;
if ( V_9 -> V_65 ) {
F_25 ( V_8 , true ) ;
F_18 ( V_8 , true ) ;
}
if ( V_9 -> V_64 )
F_23 ( V_8 , true ) ;
if ( V_9 -> V_67 )
F_27 ( V_8 , true ) ;
if ( V_9 -> V_66 )
F_26 ( V_8 , true ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_66 )
F_26 ( V_8 , false ) ;
if ( V_9 -> V_67 )
F_27 ( V_8 , false ) ;
if ( V_9 -> V_64 )
F_23 ( V_8 , false ) ;
if ( V_9 -> V_65 ) {
F_18 ( V_8 , false ) ;
F_25 ( V_8 , false ) ;
}
}
static void F_34 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_69 )
{
struct V_16 V_17 ;
int V_20 ;
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_20 = F_6 ( V_8 , V_25 ,
V_69 , false , & V_17 ) ;
if ( V_20 )
return;
V_15 = F_7 ( V_72 + V_70 ) ;
V_15 &= ~ V_73 ;
V_15 |= F_35 ( V_17 . V_29 ) ;
F_10 ( V_72 + V_70 , V_15 ) ;
V_20 = F_6 ( V_8 , V_25 ,
V_69 / 2 , false , & V_17 ) ;
if ( V_20 )
return;
V_15 = F_7 ( V_74 + V_70 ) ;
V_15 &= ~ V_75 ;
V_15 |= F_36 ( V_17 . V_29 ) ;
F_10 ( V_74 + V_70 , V_15 ) ;
}
static void F_37 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_76 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_77 + V_70 ) ;
V_15 &= ~ V_78 ;
V_15 |= F_38 ( V_76 ) ;
F_10 ( V_77 + V_70 , V_15 ) ;
}
static void F_39 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_76 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_77 + V_70 ) ;
V_15 &= ~ V_79 ;
V_15 |= F_40 ( V_76 ) ;
F_10 ( V_77 + V_70 , V_15 ) ;
}
static void F_41 ( struct V_7 * V_8 , T_1 V_68 , T_1 V_80 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_81 = F_42 ( V_8 , & V_9 -> V_82 . V_83 , V_80 ) ;
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_72 + V_70 ) ;
V_15 &= ~ V_84 ;
V_15 |= F_43 ( V_81 ) ;
F_10 ( V_72 + V_70 , V_15 ) ;
V_15 = F_7 ( V_72 + V_70 ) ;
V_15 &= ~ V_85 ;
V_15 |= F_44 ( 0 ) ;
F_10 ( V_72 + V_70 , V_15 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_86 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_87 + V_70 ) ;
V_15 &= ~ V_88 ;
V_15 |= F_46 ( V_86 ) ;
F_10 ( V_87 + V_70 , V_15 ) ;
}
static void F_47 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_89 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_87 + V_70 ) ;
V_15 &= ~ V_90 ;
V_15 |= F_48 ( V_89 ) ;
F_10 ( V_87 + V_70 , V_15 ) ;
}
static void F_49 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_91 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_77 + V_70 ) ;
V_15 &= ~ V_92 ;
V_15 |= F_50 ( V_91 ) ;
F_10 ( V_77 + V_70 , V_15 ) ;
}
static void F_51 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_91 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_77 + V_70 ) ;
V_15 &= ~ V_93 ;
V_15 |= F_52 ( V_91 ) ;
F_10 ( V_77 + V_70 , V_15 ) ;
}
static void F_53 ( struct V_7 * V_8 ,
T_1 V_68 , T_1 V_94 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_95 + V_70 ) ;
V_15 &= ~ V_96 ;
V_15 |= F_54 ( V_94 ) ;
F_10 ( V_95 + V_70 , V_15 ) ;
}
static void F_55 ( struct V_7 * V_8 ,
struct V_97 * V_98 , T_1 V_68 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_68 >= V_99 )
return;
F_34 ( V_8 , V_68 , V_98 -> V_69 ) ;
F_41 ( V_8 , V_68 , V_98 -> V_100 ) ;
F_39 ( V_8 , V_68 , V_98 -> V_101 ) ;
F_37 ( V_8 , V_68 , V_98 -> V_102 ) ;
F_45 ( V_8 , V_68 , V_98 -> V_103 ) ;
F_47 ( V_8 , V_68 , V_98 -> V_89 ) ;
F_49 ( V_8 , V_68 , V_98 -> V_104 ) ;
F_51 ( V_8 , V_68 , V_98 -> V_105 ) ;
F_53 ( V_8 , V_68 , V_9 -> V_94 [ V_68 ] ) ;
}
static void F_56 ( struct V_7 * V_8 ,
T_1 V_68 , bool V_34 )
{
T_1 V_15 ;
T_1 V_70 = V_68 * V_71 ;
V_15 = F_7 ( V_72 + V_70 ) ;
V_15 &= ~ V_106 ;
if ( V_34 )
V_15 |= F_57 ( 1 ) ;
F_10 ( V_72 + V_70 , V_15 ) ;
}
static bool F_58 ( struct V_7 * V_8 )
{
if ( F_7 ( V_107 ) & F_59 ( 1 ) )
return true ;
else
return false ;
}
static void F_60 ( struct V_7 * V_8 )
{
T_1 V_15 = F_7 ( V_107 ) ;
V_15 &= ~ ( V_108 | V_109 | V_110 ) ;
V_15 |= F_59 ( 1 ) | F_61 ( 0 ) | F_62 ( 1 ) ;
F_10 ( V_107 , V_15 ) ;
F_15 ( V_111 , V_112 , ~ V_112 ) ;
F_15 ( V_113 , 0 , ~ V_114 ) ;
F_63 ( V_8 , true ) ;
}
static void F_64 ( struct V_7 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_115 ; V_51 ++ ) {
if ( F_5 ( V_47 ) & V_116 )
break;
F_65 ( 1 ) ;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_115 ; V_51 ++ ) {
if ( ( F_5 ( V_117 ) & V_118 ) == 0 )
break;
F_65 ( 1 ) ;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_115 ; V_51 ++ ) {
if ( ( F_5 ( V_117 ) & V_119 ) == 0 )
break;
F_65 ( 1 ) ;
}
}
static void F_66 ( struct V_7 * V_8 )
{
T_1 V_120 ;
F_15 ( V_113 , V_114 , ~ V_114 ) ;
V_120 = F_7 ( V_107 ) ;
V_120 &= ~ ( V_108 | V_110 ) ;
F_10 ( V_107 , V_120 ) ;
F_63 ( V_8 , false ) ;
}
static void F_67 ( struct V_7 * V_8 )
{
F_15 ( V_47 , 0 , ~ ( V_121 | V_122 ) ) ;
}
static void F_68 ( struct V_7 * V_8 )
{
F_15 ( V_47 , V_121 | V_122 ,
~ ( V_121 | V_122 ) ) ;
}
static void F_69 ( struct V_7 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_115 ; V_51 ++ ) {
if ( ( F_5 ( V_117 ) & V_119 ) == 0 )
break;
F_65 ( 1 ) ;
}
}
static void F_70 ( struct V_7 * V_8 )
{
F_56 ( V_8 , 0 , true ) ;
}
static void F_71 ( struct V_7 * V_8 )
{
F_72 ( V_8 , 0 ) ;
}
static void F_73 ( struct V_7 * V_8 )
{
F_74 ( V_8 ) ;
}
static void F_75 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
struct V_1 * V_125 = F_1 ( V_123 ) ;
struct V_1 * V_126 = F_1 ( V_124 ) ;
T_1 V_51 ;
T_1 V_127 = ( V_126 == NULL ) ? 1 : V_126 -> V_128 ;
for ( V_51 = 0 ; V_51 < V_125 -> V_128 ; V_51 ++ ) {
F_55 ( V_8 , & V_125 -> V_129 [ V_51 ] , V_51 ) ;
F_56 ( V_8 , V_51 , true ) ;
}
for ( V_51 = V_125 -> V_128 ; V_51 < V_127 ; V_51 ++ )
F_56 ( V_8 , V_51 , false ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_51 ;
F_55 ( V_8 , & V_9 -> V_130 , 0 ) ;
F_56 ( V_8 , 0 , true ) ;
for ( V_51 = 1 ; V_51 < 8 ; V_51 ++ )
F_56 ( V_8 , V_51 , false ) ;
}
static void F_77 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_131 = ( V_4 -> V_132 |
V_4 -> V_133 << 8 |
V_4 -> V_134 << 16 |
V_4 -> V_135 << 24 ) ;
F_10 ( V_136 , V_131 ) ;
}
static void F_78 ( struct V_7 * V_8 ,
T_1 V_137 )
{
T_1 V_13 , V_14 ;
T_1 V_138 = F_7 ( V_139 ) ;
T_1 V_140 ;
T_1 V_18 = F_4 ( V_8 ) ;
F_11 ( V_137 , V_18 , 16 , & V_13 , & V_14 ) ;
V_140 = ( V_13 + V_138 - 1 ) / V_138 ;
F_10 ( V_141 , V_140 ) ;
}
static bool F_79 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_142 == 0 ) && ( V_3 -> V_143 == 0 ) )
return true ;
else
return false ;
}
static bool F_80 ( struct V_2 * V_144 ,
struct V_2 * V_145 )
{
struct V_1 * V_146 = F_1 ( V_144 ) ;
struct V_1 * V_147 = F_1 ( V_145 ) ;
if ( ( V_144 -> V_142 == V_145 -> V_142 ) &&
( V_144 -> V_143 == V_145 -> V_143 ) &&
( V_146 -> V_132 == V_147 -> V_132 ) &&
( V_146 -> V_133 == V_147 -> V_133 ) &&
( V_146 -> V_134 == V_147 -> V_134 ) &&
( V_146 -> V_135 == V_147 -> V_135 ) )
return true ;
else
return false ;
}
static void F_81 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_66 ) {
F_26 ( V_8 , false ) ;
}
if ( V_9 -> V_148 ) {
if ( F_79 ( V_123 ) &&
! F_79 ( V_124 ) ) {
F_78 ( V_8 , 0 ) ;
} else if ( ! F_79 ( V_123 ) ) {
F_77 ( V_8 , V_123 ) ;
if ( F_79 ( V_124 ) ) {
T_1 V_149 = F_5 ( V_150 ) ;
V_149 &= 0xfffffffd ;
F_12 ( V_150 , V_149 ) ;
F_82 ( V_8 , V_123 -> V_142 , V_123 -> V_143 ) ;
F_78 ( V_8 , 3000 ) ;
}
}
F_83 ( V_8 ) ;
} else {
if ( F_79 ( V_123 ) ||
F_80 ( V_123 , V_124 ) )
return;
F_82 ( V_8 , V_123 -> V_142 , V_123 -> V_143 ) ;
}
if ( V_9 -> V_66 ) {
F_26 ( V_8 , true ) ;
}
}
static void F_84 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
struct V_1 * V_125 = F_1 ( V_123 ) ;
struct V_1 * V_151 = F_1 ( V_123 ) ;
if ( V_125 -> V_129 [ V_125 -> V_128 - 1 ] . V_69 >=
V_151 -> V_129 [ V_151 -> V_128 - 1 ] . V_69 )
return;
F_81 ( V_8 , V_123 , V_124 ) ;
}
static void F_85 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
struct V_1 * V_125 = F_1 ( V_123 ) ;
struct V_1 * V_151 = F_1 ( V_124 ) ;
if ( V_125 -> V_129 [ V_125 -> V_128 - 1 ] . V_69 <
V_151 -> V_129 [ V_151 -> V_128 - 1 ] . V_69 )
return;
F_81 ( V_8 , V_123 , V_124 ) ;
}
static void F_86 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
if ( ( V_124 -> V_152 != V_123 -> V_152 ) ||
( V_124 -> V_153 != V_123 -> V_153 ) ) {
if ( V_123 -> V_152 || V_123 -> V_153 )
F_87 ( V_8 , false ) ;
else
F_87 ( V_8 , true ) ;
F_88 ( V_8 , V_123 -> V_152 , V_123 -> V_153 ) ;
}
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_15 = F_7 ( V_154 ) ;
V_15 &= ~ ( V_155 | V_156 ) ;
V_15 |= F_90 ( ( V_9 -> V_157 + 49 ) * 8 ) ;
V_15 |= F_91 ( ( V_9 -> V_157 + 49 - V_9 -> V_82 . V_158 ) * 8 ) ;
F_10 ( V_154 , V_15 ) ;
}
static void F_92 ( struct V_7 * V_8 )
{
T_1 V_15 = F_7 ( V_159 ) ;
V_15 &= ~ V_160 ;
V_15 |= F_93 ( 1 ) ;
F_10 ( V_159 , V_15 ) ;
}
static void F_94 ( struct V_7 * V_8 )
{
T_1 V_13 , V_14 ;
T_1 V_138 = F_7 ( V_139 ) ;
T_1 V_161 ;
T_1 V_18 = F_4 ( V_8 ) ;
T_1 V_15 ;
F_11 ( 400 , V_18 , 16 , & V_13 , & V_14 ) ;
V_161 = ( V_13 + V_138 - 1 ) / V_138 ;
V_15 = F_7 ( V_60 ) ;
V_15 &= ~ V_162 ;
V_15 |= F_95 ( V_161 ) ;
F_10 ( V_60 , V_15 ) ;
}
static int F_96 ( struct V_7 * V_8 ,
int V_163 , int V_164 )
{
int V_165 = 0 * 1000 ;
int V_166 = 255 * 1000 ;
if ( V_165 < V_163 )
V_165 = V_163 ;
if ( V_166 > V_164 )
V_166 = V_164 ;
if ( V_166 < V_165 ) {
F_97 ( L_1 , V_165 , V_166 ) ;
return - V_167 ;
}
F_15 ( V_168 , F_98 ( 49 + ( V_166 / 1000 ) ) , ~ V_169 ) ;
F_15 ( V_168 , F_99 ( 49 + ( V_165 / 1000 ) ) , ~ V_170 ) ;
V_8 -> V_10 . V_11 . V_171 . V_163 = V_165 ;
V_8 -> V_10 . V_11 . V_171 . V_164 = V_166 ;
return 0 ;
}
static void F_100 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_125 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_172 = * V_3 ;
V_9 -> V_151 = * V_125 ;
V_9 -> V_172 . V_5 = & V_9 -> V_151 ;
}
static void F_101 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_125 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_173 = * V_3 ;
V_9 -> V_174 = * V_125 ;
V_9 -> V_173 . V_5 = & V_9 -> V_174 ;
}
void F_102 ( struct V_7 * V_8 , bool V_34 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_175 ) {
F_103 ( V_8 ) ;
F_104 ( V_8 , V_34 ) ;
F_105 ( V_8 ) ;
}
}
int F_106 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
F_103 ( V_8 ) ;
if ( F_58 ( V_8 ) ) {
F_105 ( V_8 ) ;
return - V_167 ;
}
F_76 ( V_8 ) ;
F_107 ( V_8 , 0x00C00033 ) ;
F_67 ( V_8 ) ;
if ( V_9 -> V_176 ) {
F_89 ( V_8 ) ;
F_92 ( V_8 ) ;
}
F_94 ( V_8 ) ;
F_60 ( V_8 ) ;
F_64 ( V_8 ) ;
F_104 ( V_8 , false ) ;
F_105 ( V_8 ) ;
F_100 ( V_8 , V_8 -> V_10 . V_11 . V_177 ) ;
return 0 ;
}
int F_108 ( struct V_7 * V_8 )
{
int V_20 ;
F_103 ( V_8 ) ;
F_31 ( V_8 ) ;
if ( V_8 -> V_178 . V_179 &&
F_109 ( V_8 -> V_10 . V_180 ) ) {
V_20 = F_96 ( V_8 , V_181 , V_182 ) ;
if ( V_20 ) {
F_105 ( V_8 ) ;
return V_20 ;
}
V_8 -> V_178 . V_183 = true ;
F_110 ( V_8 ) ;
}
F_105 ( V_8 ) ;
return 0 ;
}
void F_111 ( struct V_7 * V_8 )
{
F_103 ( V_8 ) ;
if ( ! F_58 ( V_8 ) ) {
F_105 ( V_8 ) ;
return;
}
F_104 ( V_8 , false ) ;
F_33 ( V_8 ) ;
F_112 ( V_8 ) ;
F_69 ( V_8 ) ;
F_66 ( V_8 ) ;
F_68 ( V_8 ) ;
F_105 ( V_8 ) ;
if ( V_8 -> V_178 . V_179 &&
F_109 ( V_8 -> V_10 . V_180 ) ) {
V_8 -> V_178 . V_183 = false ;
F_110 ( V_8 ) ;
}
F_100 ( V_8 , V_8 -> V_10 . V_11 . V_177 ) ;
}
static void F_113 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_184 =
( F_7 ( V_185 ) & V_186 ) >> V_187 ;
}
static void F_114 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_125 = F_1 ( V_3 ) ;
T_1 V_188 ;
if ( V_9 -> V_82 . V_189 ) {
V_188 = F_7 ( V_190 ) ;
V_188 &= ~ ( V_191 | V_192 | V_193 | V_194 ) ;
V_188 |= ( F_115 ( V_125 -> F_115 ) |
F_116 ( V_125 -> F_116 ) |
F_117 ( V_125 -> F_117 ) |
F_118 ( V_125 -> F_118 ) ) ;
F_10 ( V_190 , V_188 ) ;
}
}
int F_119 ( struct V_7 * V_8 ,
enum V_195 V_196 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_3 = & V_9 -> V_172 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_51 , V_20 ;
if ( V_4 -> V_128 <= 1 )
return 0 ;
if ( V_196 == V_197 ) {
return - V_167 ;
} else if ( V_196 == V_198 ) {
V_20 = F_120 ( V_8 , V_4 -> V_128 - 1 ) ;
if ( V_20 )
return V_20 ;
} else {
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
V_20 = F_120 ( V_8 , 0 ) ;
if ( V_20 )
return V_20 ;
}
}
V_8 -> V_10 . V_11 . V_199 = V_196 ;
return 0 ;
}
int F_121 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 V_174 = * V_8 -> V_10 . V_11 . V_174 ;
struct V_2 * V_125 = & V_174 ;
F_101 ( V_8 , V_125 ) ;
F_122 ( V_8 ,
& V_9 -> V_173 ,
& V_9 -> V_172 ) ;
return 0 ;
}
int F_123 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_125 = & V_9 -> V_173 ;
struct V_2 * V_126 = & V_9 -> V_172 ;
F_103 ( V_8 ) ;
if ( V_9 -> V_200 ) {
if ( V_9 -> V_175 )
F_104 ( V_8 , V_8 -> V_10 . V_11 . V_201 ) ;
F_84 ( V_8 , V_125 , V_126 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
F_69 ( V_8 ) ;
F_114 ( V_8 , V_125 ) ;
F_75 ( V_8 , V_125 , V_126 ) ;
F_71 ( V_8 ) ;
F_73 ( V_8 ) ;
F_85 ( V_8 , V_125 , V_126 ) ;
F_86 ( V_8 , V_125 , V_126 ) ;
}
F_105 ( V_8 ) ;
return 0 ;
}
void F_124 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_125 = & V_9 -> V_173 ;
F_100 ( V_8 , V_125 ) ;
}
void F_125 ( struct V_7 * V_8 )
{
F_103 ( V_8 ) ;
F_126 ( V_8 ) ;
F_127 ( V_8 , true ) ;
F_113 ( V_8 ) ;
F_105 ( V_8 ) ;
}
static T_2 F_128 ( struct V_7 * V_8 ,
T_1 V_202 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_81 = F_42 ( V_8 , & V_9 -> V_82 . V_83 , V_202 ) ;
T_1 V_203 = ( F_7 ( V_204 ) & V_205 ) ? 1 : 0 ;
T_1 V_206 = ( V_203 == 0 ) ? 1250 : 625 ;
T_1 V_207 = V_81 * V_206 + 50 ;
if ( V_207 > 155000 )
return 0 ;
return ( 155000 - V_207 ) / 100 ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_1 * V_4 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_4 -> V_128 = 1 ;
V_4 -> V_208 = 0 ;
V_4 -> V_209 = 0 ;
V_4 -> V_129 [ 0 ] = V_9 -> V_130 ;
}
static T_3 F_130 ( struct V_7 * V_8 , T_1 V_69 )
{
if ( V_69 < 20000 )
return 1 ;
return 0 ;
}
static void F_131 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_130 . V_69 = V_9 -> V_82 . V_210 ;
V_9 -> V_130 . V_100 = V_9 -> V_82 . V_211 ;
V_9 -> V_130 . V_102 = 0 ;
V_9 -> V_130 . V_101 = 0 ;
V_9 -> V_130 . V_103 = 1 ;
V_9 -> V_130 . V_89 = 0 ;
V_9 -> V_130 . V_104 = 0 ;
V_9 -> V_130 . V_105 = 0 ;
V_9 -> V_151 . V_128 = 1 ;
V_9 -> V_151 . V_129 [ 0 ] = V_9 -> V_130 ;
}
static T_3 F_132 ( struct V_7 * V_8 ,
T_1 V_69 , T_1 V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_51 ;
T_1 V_213 ;
T_1 V_214 = ( V_212 > V_215 ) ?
V_212 : V_215 ;
if ( V_69 < V_214 )
return 0 ;
if ( ! V_9 -> V_216 )
return 0 ;
for ( V_51 = V_217 ; ; V_51 -- ) {
V_213 = V_69 / F_133 ( V_51 ) ;
if ( V_213 >= V_214 || V_51 == 0 )
break;
}
return ( T_3 ) V_51 ;
}
static T_1 F_134 ( struct V_7 * V_8 ,
T_1 V_218 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_51 ;
for ( V_51 = 0 ; V_51 < V_9 -> V_82 . V_219 . V_220 ; V_51 ++ ) {
if ( V_9 -> V_82 . V_219 . V_221 [ V_51 ] . V_222 >= V_218 )
return V_9 -> V_82 . V_219 . V_221 [ V_51 ] . V_222 ;
}
if ( V_51 == V_9 -> V_82 . V_219 . V_220 )
F_97 ( L_2 ) ;
return 0 ;
}
static void F_135 ( struct V_7 * V_8 ,
struct V_1 * V_4 ,
struct V_1 * V_151 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_223 = V_9 -> V_82 . V_224 ;
T_1 V_225 ;
T_1 V_226 ;
T_1 V_227 = 0 ;
if ( V_151 ) {
V_225 = V_151 -> V_129 [ V_227 ] . V_100 ;
V_226 = V_151 -> V_129 [ V_227 ] . V_69 ;
} else {
V_225 = V_9 -> V_130 . V_100 ;
V_226 = V_9 -> V_130 . V_69 ;
}
V_4 -> V_129 [ 0 ] . V_100 = V_225 ;
if ( V_4 -> V_129 [ 0 ] . V_69 > V_226 )
V_4 -> V_129 [ 0 ] . V_69 = V_226 ;
V_4 -> V_129 [ 0 ] . V_102 =
F_132 ( V_8 , V_4 -> V_129 [ 0 ] . V_69 , V_223 ) ;
V_4 -> V_129 [ 0 ] . V_101 = V_4 -> V_129 [ 0 ] . V_102 ;
V_4 -> V_129 [ 0 ] . V_103 = 1 ;
V_4 -> V_129 [ 0 ] . V_89 = 0 ;
V_4 -> V_129 [ 0 ] . V_104 = 0 ;
V_4 -> V_129 [ 0 ] . V_105 =
F_130 ( V_8 , V_4 -> V_129 [ 0 ] . V_69 ) ;
}
static T_3 F_136 ( struct V_7 * V_8 ,
struct V_1 * V_4 , T_1 V_68 )
{
if ( V_4 == NULL || V_4 -> V_128 <= 1 )
return 0 ;
else if ( V_4 -> V_128 == 2 ) {
if ( V_68 == 0 )
return 0 ;
else
return 1 ;
} else {
if ( V_68 == 0 )
return 0 ;
else if ( V_4 -> V_129 [ V_68 ] . V_69 < 30000 )
return 0 ;
else
return 1 ;
}
}
static T_1 F_137 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_51 = 0 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( ( V_3 -> V_142 == V_9 -> V_82 . V_228 [ V_51 ] . V_142 ) &&
( V_3 -> V_143 == V_9 -> V_82 . V_228 [ V_51 ] . V_143 ) )
break;
}
if ( V_51 >= 4 ) {
F_97 ( L_3 ) ;
V_51 = 3 ;
}
return V_51 ;
}
static void F_138 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_229 = 0 ;
T_1 V_230 = 0 ;
if ( V_9 -> V_148 && F_139 ( V_3 -> V_231 , V_3 -> V_232 ) ) {
V_229 = F_137 ( V_8 , V_3 ) ;
switch( V_229 ) {
case 3 :
case 2 :
V_230 = 1 ;
break;
case 1 :
case 0 :
default:
V_230 = 0 ;
break;
}
V_4 -> V_132 =
V_9 -> V_82 . V_228 [ V_229 ] . V_233 ;
V_4 -> V_134 =
V_9 -> V_82 . V_228 [ V_229 ] . V_234 ;
V_4 -> V_133 =
V_9 -> V_82 . V_228 [ V_230 ] . V_233 ;
V_4 -> V_135 =
V_9 -> V_82 . V_228 [ V_230 ] . V_234 ;
}
}
static int F_140 ( struct V_7 * V_8 ,
T_1 V_152 , T_1 V_153 , T_2 * V_235 )
{
T_1 V_51 ;
int V_20 = - V_167 ;
struct V_236 * V_237 =
& V_8 -> V_10 . V_11 . V_238 . V_239 ;
if ( ( ( V_152 == 0 ) && ( V_153 == 0 ) ) ||
( V_237 && ( V_237 -> V_44 == 0 ) ) ) {
* V_235 = 0 ;
return 0 ;
}
for ( V_51 = 0 ; V_51 < V_237 -> V_44 ; V_51 ++ ) {
if ( ( V_152 <= V_237 -> V_221 [ V_51 ] . V_152 ) &&
( V_153 <= V_237 -> V_221 [ V_51 ] . V_153 ) ) {
* V_235 = V_237 -> V_221 [ V_51 ] . V_240 ;
V_20 = 0 ;
break;
}
}
if ( V_20 )
* V_235 = V_237 -> V_221 [ V_237 -> V_44 - 1 ] . V_240 ;
return V_20 ;
}
static void F_122 ( struct V_7 * V_8 ,
struct V_2 * V_123 ,
struct V_2 * V_124 )
{
struct V_1 * V_4 = F_1 ( V_123 ) ;
struct V_1 * V_151 = F_1 ( V_124 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_241 = 0 ;
T_1 V_224 = V_9 -> V_82 . V_224 ;
T_1 V_223 = V_9 -> V_82 . V_224 ;
T_1 V_51 ;
T_2 V_242 ;
bool V_243 ;
T_1 V_244 = V_8 -> V_10 . V_11 . V_245 ;
if ( V_123 -> V_231 & V_246 )
return F_135 ( V_8 , V_4 , V_151 ) ;
F_138 ( V_8 , V_123 ) ;
if ( V_123 -> V_247 ) {
V_123 -> V_152 = V_8 -> V_10 . V_11 . V_248 [ V_8 -> V_10 . V_11 . V_249 ] . V_152 ;
V_123 -> V_153 = V_8 -> V_10 . V_11 . V_248 [ V_8 -> V_10 . V_11 . V_249 ] . V_153 ;
} else {
V_123 -> V_152 = 0 ;
V_123 -> V_153 = 0 ;
}
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
if ( V_4 -> V_129 [ V_51 ] . V_100 < V_241 )
V_4 -> V_129 [ V_51 ] . V_100 = V_241 ;
if ( V_4 -> V_129 [ V_51 ] . V_69 < V_224 )
V_4 -> V_129 [ V_51 ] . V_69 =
F_134 ( V_8 , V_224 ) ;
if ( V_123 -> V_247 ) {
if ( V_4 -> V_129 [ V_51 ] . V_69 < V_8 -> V_10 . V_11 . V_248 [ V_8 -> V_10 . V_11 . V_249 ] . V_69 )
V_4 -> V_129 [ V_51 ] . V_69 = V_8 -> V_10 . V_11 . V_248 [ V_8 -> V_10 . V_11 . V_249 ] . V_69 ;
F_140 ( V_8 , V_123 -> V_152 , V_123 -> V_153 , & V_242 ) ;
if ( V_4 -> V_129 [ V_51 ] . V_100 < V_242 )
V_4 -> V_129 [ V_51 ] . V_100 = V_242 ;
}
V_4 -> V_129 [ V_51 ] . V_102 =
F_141 ( V_8 , V_4 -> V_129 [ V_51 ] . V_69 , V_223 ) ;
V_4 -> V_129 [ V_51 ] . V_101 = V_4 -> V_129 [ V_51 ] . V_102 ;
V_4 -> V_129 [ V_51 ] . V_103 = 1 ;
V_4 -> V_129 [ V_51 ] . V_89 = 0 ;
V_4 -> V_129 [ V_51 ] . V_104 =
F_136 ( V_8 , V_4 , V_51 ) ;
V_4 -> V_129 [ V_51 ] . V_105 =
F_130 ( V_8 , V_4 -> V_129 [ 0 ] . V_69 ) ;
}
if ( ( V_123 -> V_231 & ( V_250 | V_251 ) ) ||
( ( V_123 -> V_231 & V_252 ) == V_253 ) )
V_4 -> V_209 |= V_254 ;
if ( V_9 -> V_82 . V_189 ) {
V_4 -> F_115 = 0x1 ;
V_4 -> F_116 = 0x0 ;
V_4 -> F_117 = 0x2 ;
V_4 -> F_118 = 0x1 ;
if ( ( V_123 -> V_231 & ( V_250 | V_251 ) ) ||
( ( V_123 -> V_231 & V_252 ) == V_253 ) ) {
V_243 = ( ( V_123 -> V_231 & V_250 ) ||
( ( V_123 -> V_231 & V_251 ) &&
( V_9 -> V_82 . V_255 == 1 ) ) ) ;
V_243 = ( V_244 >= 3 ) || V_243 ;
V_4 -> F_115 = V_243 ? 0x2 : 0x3 ;
V_4 -> F_116 = 0x1 ;
V_4 -> F_117 = V_243 ? 0x2 : 0x3 ;
V_4 -> F_118 = 0x2 ;
V_4 -> V_129 [ V_4 -> V_128 - 1 ] . V_103 = 0 ;
}
}
}
static void F_142 ( struct V_7 * V_8 )
{
F_127 ( V_8 , false ) ;
}
static void F_143 ( struct V_7 * V_8 )
{
T_1 V_256 ;
T_1 V_244 = V_8 -> V_10 . V_11 . V_245 ;
T_4 V_257 = V_8 -> clock . V_258 / 100 ;
T_1 V_259 ;
V_256 =
( F_7 ( V_260 ) & V_261 ) >> V_262 ;
V_259 = ( T_1 ) ( ( 14213 * V_257 * V_257 * ( T_4 ) V_244 ) >>
( 32 - V_256 ) ) ;
F_10 ( V_263 , V_259 ) ;
}
void F_144 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_264 )
F_145 ( V_8 , true ) ;
F_143 ( V_8 ) ;
}
static void F_146 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_265 * V_266 ,
T_3 V_267 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_3 -> V_268 = F_147 ( V_266 -> V_269 ) ;
V_3 -> V_231 = F_148 ( V_266 -> V_270 ) ;
V_3 -> V_232 = F_148 ( V_266 -> V_271 ) ;
if ( V_272 < V_267 ) {
V_3 -> V_142 = F_147 ( V_266 -> V_273 ) ;
V_3 -> V_143 = F_147 ( V_266 -> V_274 ) ;
} else {
V_3 -> V_142 = 0 ;
V_3 -> V_143 = 0 ;
}
if ( V_3 -> V_231 & V_275 ) {
V_8 -> V_10 . V_11 . V_177 = V_3 ;
F_129 ( V_8 , V_4 ) ;
}
if ( V_3 -> V_231 & V_276 )
V_8 -> V_10 . V_11 . V_277 = V_3 ;
}
static void F_149 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_68 ,
union V_278 * V_279 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_97 * V_98 = & V_4 -> V_129 [ V_68 ] ;
T_1 V_69 ;
V_69 = F_148 ( V_279 -> V_280 . V_281 ) ;
V_69 |= V_279 -> V_280 . V_282 << 16 ;
V_98 -> V_69 = V_69 ;
V_98 -> V_100 = V_279 -> V_280 . V_283 ;
V_4 -> V_128 = V_68 + 1 ;
if ( V_9 -> V_216 ) {
V_98 -> V_102 = 5 ;
V_98 -> V_101 = 5 ;
}
}
static int F_150 ( struct V_7 * V_8 )
{
struct V_284 * V_285 = & V_8 -> V_285 ;
struct V_265 * V_266 ;
union V_286 * V_287 ;
int V_51 , V_288 , V_289 , V_290 , V_291 ;
union V_278 * V_279 ;
struct V_292 * V_293 ;
struct V_294 * V_295 ;
struct V_296 * V_297 ;
union V_298 * V_298 ;
int V_68 = F_151 ( V_299 , V_300 ) ;
T_2 V_301 ;
T_3 V_302 , V_303 ;
T_3 * V_304 ;
struct V_305 * V_4 ;
if ( ! F_152 ( V_285 -> V_306 , V_68 , NULL ,
& V_302 , & V_303 , & V_301 ) )
return - V_167 ;
V_298 = (union V_298 * ) ( V_285 -> V_306 -> V_307 + V_301 ) ;
V_293 = (struct V_292 * )
( V_285 -> V_306 -> V_307 + V_301 +
F_148 ( V_298 -> V_308 . V_309 ) ) ;
V_295 = (struct V_294 * )
( V_285 -> V_306 -> V_307 + V_301 +
F_148 ( V_298 -> V_308 . V_310 ) ) ;
V_297 = (struct V_296 * )
( V_285 -> V_306 -> V_307 + V_301 +
F_148 ( V_298 -> V_308 . V_311 ) ) ;
V_8 -> V_10 . V_11 . V_4 = F_153 ( sizeof( struct V_2 ) *
V_293 -> V_312 , V_313 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_314 ;
V_304 = ( T_3 * ) V_293 -> V_315 ;
for ( V_51 = 0 ; V_51 < V_293 -> V_312 ; V_51 ++ ) {
T_3 * V_316 ;
V_287 = (union V_286 * ) V_304 ;
V_290 = V_287 -> V_317 . V_318 ;
V_266 = (struct V_265 * )
& V_297 -> V_319 [ V_290 ] ;
if ( ! V_8 -> V_10 . V_287 [ V_51 ] . V_279 )
return - V_167 ;
V_4 = F_153 ( sizeof( struct V_305 ) , V_313 ) ;
if ( V_4 == NULL ) {
F_154 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_314 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_51 ] . V_5 = V_4 ;
V_289 = 0 ;
V_316 = ( T_3 * ) & V_287 -> V_317 . V_320 [ 0 ] ;
for ( V_288 = 0 ; V_288 < V_287 -> V_317 . V_321 ; V_288 ++ ) {
V_291 = V_316 [ V_288 ] ;
if ( V_291 >= V_295 -> V_312 )
continue;
if ( V_289 >= V_99 )
break;
V_279 = (union V_278 * )
( ( T_3 * ) & V_295 -> V_322 [ 0 ] +
( V_291 * V_295 -> V_323 ) ) ;
F_149 ( V_8 ,
& V_8 -> V_10 . V_11 . V_4 [ V_51 ] , V_289 ,
V_279 ) ;
V_289 ++ ;
}
F_146 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_51 ] ,
V_266 ,
V_297 -> V_323 ) ;
V_304 += 2 + V_287 -> V_317 . V_321 ;
}
V_8 -> V_10 . V_11 . V_324 = V_293 -> V_312 ;
for ( V_51 = 0 ; V_51 < V_325 ; V_51 ++ ) {
T_1 V_69 ;
V_291 = V_8 -> V_10 . V_11 . V_248 [ V_51 ] . V_326 ;
V_279 = (union V_278 * )
& V_295 -> V_322 [ V_291 * V_295 -> V_323 ] ;
V_69 = F_148 ( V_279 -> V_280 . V_281 ) ;
V_69 |= V_279 -> V_280 . V_282 << 16 ;
V_8 -> V_10 . V_11 . V_248 [ V_51 ] . V_69 = V_69 ;
V_8 -> V_10 . V_11 . V_248 [ V_51 ] . V_327 = 0 ;
}
return 0 ;
}
static T_1 F_155 ( struct V_7 * V_8 , T_3 V_328 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_76 ;
if ( V_328 >= 8 && V_328 <= 0x3f )
V_76 = V_328 * 25 ;
else if ( V_328 > 0x3f && V_328 <= 0x5f )
V_76 = ( V_328 - 64 ) * 50 + 1600 ;
else if ( V_328 > 0x5f && V_328 <= 0x7e )
V_76 = ( V_328 - 96 ) * 100 + 3200 ;
else if ( V_328 == 0x7f )
V_76 = 128 * 100 ;
else
return 10000 ;
return ( ( V_9 -> V_82 . V_329 * 100 ) + ( V_76 - 1 ) ) / V_76 ;
}
static int F_156 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_284 * V_285 = & V_8 -> V_285 ;
int V_68 = F_151 ( V_299 , V_330 ) ;
union V_331 * V_331 ;
T_3 V_302 , V_303 ;
T_2 V_301 ;
int V_51 ;
if ( F_152 ( V_285 -> V_306 , V_68 , NULL ,
& V_302 , & V_303 , & V_301 ) ) {
V_331 = (union V_331 * ) ( V_285 -> V_306 -> V_307 +
V_301 ) ;
if ( V_303 != 7 ) {
F_97 ( L_4 , V_302 , V_303 ) ;
return - V_167 ;
}
V_9 -> V_82 . V_210 = F_147 ( V_331 -> V_332 . V_333 ) ;
V_9 -> V_82 . V_224 = F_147 ( V_331 -> V_332 . V_334 ) ;
V_9 -> V_82 . V_335 = F_147 ( V_331 -> V_332 . V_336 ) ;
V_9 -> V_82 . V_329 = F_147 ( V_331 -> V_332 . V_337 ) ;
V_9 -> V_82 . V_211 =
F_148 ( V_331 -> V_332 . V_338 ) ;
if ( V_331 -> V_332 . V_339 == 0 )
V_9 -> V_82 . V_340 = 203 ;
else
V_9 -> V_82 . V_340 = V_331 -> V_332 . V_339 ;
if ( V_331 -> V_332 . V_341 == 0 )
V_9 -> V_82 . V_158 = 5 ;
else
V_9 -> V_82 . V_158 = V_331 -> V_332 . V_341 ;
if ( V_9 -> V_82 . V_340 <= V_9 -> V_82 . V_158 ) {
F_97 ( L_5 ) ;
}
if ( V_9 -> V_342 )
V_9 -> V_82 . V_189 = V_331 -> V_332 . V_343 ;
else
V_9 -> V_82 . V_189 = 0 ;
for ( V_51 = 0 ; V_51 < V_344 ; V_51 ++ ) {
V_9 -> V_82 . V_345 [ V_51 ] = F_147 ( V_331 -> V_332 . V_346 [ V_51 ] ) ;
V_9 -> V_82 . V_347 [ V_51 ] = F_147 ( V_331 -> V_332 . V_348 [ V_51 ] ) ;
}
V_9 -> V_82 . V_349 [ 0 ] = F_148 ( V_331 -> V_332 . V_350 ) ;
V_9 -> V_82 . V_349 [ 1 ] = F_148 ( V_331 -> V_332 . V_351 ) ;
V_9 -> V_82 . V_349 [ 2 ] = F_148 ( V_331 -> V_332 . V_352 ) ;
V_9 -> V_82 . V_349 [ 3 ] = F_148 ( V_331 -> V_332 . V_353 ) ;
if ( ! V_9 -> V_82 . V_189 ) {
for ( V_51 = 1 ; V_51 < V_344 ; V_51 ++ ) {
V_9 -> V_82 . V_345 [ V_51 ] = V_9 -> V_82 . V_345 [ 0 ] ;
V_9 -> V_82 . V_347 [ V_51 ] = V_9 -> V_82 . V_347 [ 0 ] ;
V_9 -> V_82 . V_349 [ V_51 ] = V_9 -> V_82 . V_349 [ 0 ] ;
}
}
V_9 -> V_82 . V_255 = V_331 -> V_332 . V_354 ;
F_157 ( V_8 ,
& V_9 -> V_82 . V_219 ,
V_331 -> V_332 . V_355 ) ;
F_158 ( V_8 , & V_9 -> V_82 . V_83 ,
V_331 -> V_332 . V_355 ) ;
V_9 -> V_82 . V_228 [ 0 ] . V_233 =
V_331 -> V_332 . V_356 ;
V_9 -> V_82 . V_228 [ 1 ] . V_233 =
V_331 -> V_332 . V_357 ;
V_9 -> V_82 . V_228 [ 2 ] . V_233 =
V_331 -> V_332 . V_358 ;
V_9 -> V_82 . V_228 [ 3 ] . V_233 =
V_331 -> V_332 . V_359 ;
V_9 -> V_82 . V_228 [ 0 ] . V_234 =
V_331 -> V_332 . V_360 ;
V_9 -> V_82 . V_228 [ 1 ] . V_234 =
V_331 -> V_332 . V_361 ;
V_9 -> V_82 . V_228 [ 2 ] . V_234 =
V_331 -> V_332 . V_362 ;
V_9 -> V_82 . V_228 [ 3 ] . V_234 =
V_331 -> V_332 . V_363 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_9 -> V_82 . V_228 [ V_51 ] . V_142 =
F_155 ( V_8 ,
V_9 -> V_82 . V_228 [ V_51 ] . V_233 ) ;
V_9 -> V_82 . V_228 [ V_51 ] . V_143 =
F_155 ( V_8 ,
V_9 -> V_82 . V_228 [ V_51 ] . V_234 ) ;
}
}
return 0 ;
}
int F_159 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_20 , V_51 ;
V_9 = F_153 ( sizeof( struct V_6 ) , V_313 ) ;
if ( V_9 == NULL )
return - V_314 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
for ( V_51 = 0 ; V_51 < V_99 ; V_51 ++ )
V_9 -> V_94 [ V_51 ] = V_364 ;
if ( V_365 == - 1 ) {
if ( V_8 -> V_366 -> V_367 == 0x1462 )
V_9 -> V_175 = true ;
else
V_9 -> V_175 = false ;
} else if ( V_365 == 0 ) {
V_9 -> V_175 = false ;
} else {
V_9 -> V_175 = true ;
}
V_9 -> V_342 = true ;
V_9 -> V_216 = true ;
V_9 -> V_66 = true ;
V_9 -> V_64 = true ;
V_9 -> V_65 = false ;
V_9 -> V_67 = false ;
V_9 -> V_33 = false ;
V_9 -> V_176 = true ;
V_9 -> V_264 = false ;
V_9 -> V_148 = true ;
V_20 = F_156 ( V_8 ) ;
if ( V_20 )
return V_20 ;
F_131 ( V_8 ) ;
V_20 = F_160 ( V_8 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_161 ( V_8 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_150 ( V_8 ) ;
if ( V_20 )
return V_20 ;
V_9 -> V_157 = V_9 -> V_82 . V_340 ;
V_9 -> V_200 = true ;
return 0 ;
}
void F_162 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
int V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_163 ( V_3 -> V_231 , V_3 -> V_232 ) ;
F_164 ( V_3 -> V_268 ) ;
F_165 ( L_6 , V_3 -> V_142 , V_3 -> V_143 ) ;
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
struct V_97 * V_98 = & V_4 -> V_129 [ V_51 ] ;
F_165 ( L_7 ,
V_51 , V_98 -> V_69 ,
F_128 ( V_8 , V_98 -> V_100 ) ) ;
}
F_166 ( V_8 , V_3 ) ;
}
void F_167 ( struct V_7 * V_8 ,
struct V_368 * V_369 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_3 = & V_9 -> V_172 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_97 * V_98 ;
T_1 V_227 =
( F_5 ( V_117 ) & V_119 ) >>
V_370 ;
if ( V_227 >= V_4 -> V_128 ) {
F_168 ( V_369 , L_8 , V_227 ) ;
} else {
V_98 = & V_4 -> V_129 [ V_227 ] ;
F_168 ( V_369 , L_9 , V_3 -> V_142 , V_3 -> V_143 ) ;
F_168 ( V_369 , L_10 ,
V_227 , V_98 -> V_69 ,
F_128 ( V_8 , V_98 -> V_100 ) ) ;
}
}
T_1 F_169 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_3 = & V_9 -> V_172 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_97 * V_98 ;
T_1 V_227 =
( F_5 ( V_117 ) & V_119 ) >>
V_370 ;
if ( V_227 >= V_4 -> V_128 ) {
return 0 ;
} else {
V_98 = & V_4 -> V_129 [ V_227 ] ;
return V_98 -> V_69 ;
}
}
T_1 F_170 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_82 . V_335 ;
}
void F_171 ( struct V_7 * V_8 )
{
int V_51 ;
F_142 ( V_8 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_10 . V_11 . V_324 ; V_51 ++ ) {
F_154 ( V_8 -> V_10 . V_11 . V_4 [ V_51 ] . V_5 ) ;
}
F_154 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_154 ( V_8 -> V_10 . V_11 . V_12 ) ;
F_172 ( V_8 ) ;
}
T_1 F_173 ( struct V_7 * V_8 , bool V_371 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_372 = F_1 ( & V_9 -> V_173 ) ;
if ( V_371 )
return V_372 -> V_129 [ 0 ] . V_69 ;
else
return V_372 -> V_129 [ V_372 -> V_128 - 1 ] . V_69 ;
}
T_1 F_174 ( struct V_7 * V_8 , bool V_371 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_82 . V_335 ;
}
