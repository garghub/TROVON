static enum V_1 F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static void F_2 ( struct V_2 * V_3 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_8 ;
T_1 V_9 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_10 . V_11 ; V_8 ++ ) {
if ( ! ( ( 1 << V_8 ) & V_3 -> V_12 ) )
continue;
V_9 = F_4 ( V_7 , F_5 ( V_8 ) ) ;
V_9 |= ( 1 << V_5 ) ;
F_6 ( V_7 , V_9 , F_5 ( V_8 ) ) ;
}
}
static void F_7 ( struct V_6 * V_7 , int V_13 )
{
T_1 V_9 , V_14 ;
switch ( V_13 ) {
case 8 :
V_14 = V_15 ;
break;
case 7 :
V_14 = V_16 ;
break;
case 5 :
V_14 = V_17 ;
break;
default:
V_14 = 0 ;
break;
}
V_9 = F_4 ( V_7 , V_18 ) ;
V_9 |= V_14 ;
F_6 ( V_7 , V_9 , V_18 ) ;
V_9 = F_4 ( V_7 , V_19 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_19 ) ;
V_9 = F_4 ( V_7 , V_20 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_20 ) ;
}
static void F_8 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_8 ;
T_1 V_9 , V_21 ;
if ( V_7 -> type == V_22 )
V_21 = V_23 ;
else
V_21 = V_24 ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 &= ~ F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
V_9 = F_4 ( V_7 , V_26 ) ;
V_9 |= ( V_27 | V_28 | V_29 ) ;
V_9 &= ~ ( V_30 | V_31 ) ;
F_6 ( V_7 , V_9 , V_26 ) ;
F_6 ( V_7 , V_32 , V_33 ) ;
V_9 = F_4 ( V_7 , V_34 ) ;
V_9 |= V_35 ;
F_6 ( V_7 , V_9 , V_34 ) ;
V_9 = F_4 ( V_7 , F_10 ( V_13 ) ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
V_9 |= V_8 << ( V_37 * V_8 ) ;
F_6 ( V_7 , V_9 , F_10 ( V_13 ) ) ;
F_7 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , V_21 ) ;
V_9 |= ( V_38 | V_39 ) ;
F_6 ( V_7 , V_9 , V_21 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_13 , bool V_40 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_41 ) ;
if ( V_40 )
V_9 |= 1 << V_13 ;
else
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_41 ) ;
}
static void F_12 ( struct V_2 * V_3 , bool V_40 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_13 ( V_7 , V_42 ) ;
if ( V_40 ) {
V_9 |= V_43 ;
V_9 &= ~ ( V_44 | V_45 | V_46 ) ;
F_14 ( V_7 , V_9 , V_42 ) ;
F_15 ( 21 ) ;
V_9 = F_13 ( V_7 , V_42 ) ;
V_9 &= ~ V_43 ;
} else {
V_9 |= V_44 | V_45 | V_43 ;
F_14 ( V_7 , V_9 , V_42 ) ;
F_16 ( 1 ) ;
V_9 |= V_46 ;
}
F_14 ( V_7 , V_9 , V_42 ) ;
if ( ! V_40 ) {
V_9 = F_13 ( V_7 , F_17 ( 0 ) ) ;
V_9 |= V_47 ;
F_14 ( V_7 , V_9 , F_17 ( 0 ) ) ;
}
}
static inline void F_18 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_48 ;
switch ( V_13 ) {
case 7 :
V_48 = V_49 ;
break;
case 0 :
F_19 ( V_7 , F_20 ( V_50 ) ) ;
return;
default:
V_48 = F_21 ( V_13 ) ;
break;
}
F_22 ( V_7 , F_20 ( V_48 ) ) ;
}
static inline void F_23 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_48 ;
switch ( V_13 ) {
case 7 :
V_48 = V_49 ;
break;
case 0 :
F_24 ( V_7 , F_20 ( V_50 ) ) ;
F_25 ( V_7 , F_20 ( V_50 ) , V_51 ) ;
return;
default:
V_48 = F_21 ( V_13 ) ;
break;
}
F_26 ( V_7 , F_20 ( V_48 ) ) ;
F_27 ( V_7 , F_20 ( V_48 ) , V_51 ) ;
}
static int F_28 ( struct V_2 * V_3 , int V_13 ,
struct V_52 * V_53 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_54 -> V_55 -> V_56 ;
unsigned int V_8 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 &= ~ F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
if ( V_7 -> V_57 & F_29 ( V_13 ) )
F_7 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_10 ( V_13 ) ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
V_9 |= V_8 << ( V_37 * V_8 ) ;
F_6 ( V_7 , V_9 , F_10 ( V_13 ) ) ;
F_6 ( V_7 , 0 , F_30 ( V_13 ) ) ;
if ( V_7 -> V_58 & 1 << V_13 && V_7 -> V_10 . V_59 == 1 ) {
F_12 ( V_3 , true ) ;
if ( V_53 ) {
V_53 -> V_60 = V_61 ;
F_31 ( V_53 ) ;
}
}
if ( V_13 == V_7 -> V_62 )
F_18 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_5 ( V_13 ) ) ;
V_9 &= ~ V_63 ;
V_9 |= ( 1 << V_13 ) ;
V_9 |= V_7 -> V_64 -> V_65 [ V_13 ] . V_66 ;
F_6 ( V_7 , V_9 , F_5 ( V_13 ) ) ;
F_2 ( V_3 , V_5 ) ;
if ( V_7 -> V_67 [ V_13 ] . V_68 . V_69 )
F_11 ( V_3 , V_13 , true ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 , int V_13 ,
struct V_52 * V_53 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_48 , V_9 ;
if ( V_7 -> V_70 & ( 1 << V_13 ) )
return;
if ( V_13 == V_7 -> V_62 )
F_23 ( V_7 , V_13 ) ;
if ( V_7 -> V_58 & 1 << V_13 && V_7 -> V_10 . V_59 == 1 )
F_12 ( V_3 , false ) ;
if ( F_33 ( V_3 , V_13 ) )
V_48 = V_26 ;
else
V_48 = F_30 ( V_13 ) ;
V_9 = F_4 ( V_7 , V_48 ) ;
V_9 |= V_30 | V_31 ;
F_6 ( V_7 , V_9 , V_48 ) ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 |= F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
}
static int F_34 ( struct V_2 * V_3 , int V_13 ,
struct V_52 * V_53 )
{
int V_71 ;
V_71 = F_35 ( V_53 , 0 ) ;
if ( V_71 )
return 0 ;
F_11 ( V_3 , V_13 , true ) ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 , int V_13 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_72 * V_74 = & V_7 -> V_67 [ V_13 ] . V_68 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_75 ) ;
V_73 -> V_69 = V_74 -> V_69 ;
V_73 -> V_76 = ! ! ( V_9 & ( 1 << V_13 ) ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , int V_13 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_72 * V_74 = & V_7 -> V_67 [ V_13 ] . V_68 ;
V_74 -> V_69 = V_73 -> V_69 ;
F_11 ( V_3 , V_13 , V_73 -> V_69 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , int V_77 , int V_78 ,
int V_79 , T_3 V_14 )
{
int V_71 = 0 ;
T_1 V_9 ;
V_9 = F_13 ( V_7 , V_80 ) ;
V_9 |= V_81 ;
F_14 ( V_7 , V_9 , V_80 ) ;
V_9 = 0x70 ;
V_9 <<= 2 ;
F_6 ( V_7 , V_78 , V_9 ) ;
V_9 = 0x80 << 8 | V_79 << 1 ;
V_9 <<= 2 ;
if ( V_77 )
V_71 = F_4 ( V_7 , V_9 ) ;
else
F_6 ( V_7 , V_14 , V_9 ) ;
V_9 = F_13 ( V_7 , V_80 ) ;
V_9 &= ~ V_81 ;
F_14 ( V_7 , V_9 , V_80 ) ;
return V_71 & 0xffff ;
}
static int F_39 ( struct V_82 * V_83 , int V_78 , int V_79 )
{
struct V_6 * V_7 = V_83 -> V_7 ;
if ( V_78 == V_84 && V_7 -> V_85 & F_29 ( V_78 ) )
return F_38 ( V_7 , 1 , V_78 , V_79 , 0 ) ;
else
return F_40 ( V_7 -> V_86 , V_78 , V_79 ) ;
}
static int F_41 ( struct V_82 * V_83 , int V_78 , int V_79 ,
T_3 V_14 )
{
struct V_6 * V_7 = V_83 -> V_7 ;
if ( V_78 == V_84 && V_7 -> V_85 & F_29 ( V_78 ) )
F_38 ( V_7 , 0 , V_78 , V_79 , V_14 ) ;
else
F_42 ( V_7 -> V_86 , V_78 , V_79 , V_14 ) ;
return 0 ;
}
static T_4 F_43 ( int V_87 , void * V_88 )
{
struct V_6 * V_7 = V_88 ;
V_7 -> V_89 = F_44 ( V_7 , V_90 ) &
~ V_7 -> V_91 ;
F_25 ( V_7 , V_7 -> V_89 , V_51 ) ;
return V_92 ;
}
static T_4 F_45 ( int V_87 , void * V_88 )
{
struct V_6 * V_7 = V_88 ;
V_7 -> V_93 = F_46 ( V_7 , V_90 ) &
~ V_7 -> V_94 ;
F_27 ( V_7 , V_7 -> V_93 , V_51 ) ;
if ( V_7 -> V_93 & F_47 ( V_49 ) )
V_7 -> V_67 [ 7 ] . V_95 = 1 ;
if ( V_7 -> V_93 & F_48 ( V_49 ) )
V_7 -> V_67 [ 7 ] . V_95 = 0 ;
return V_92 ;
}
static int F_49 ( struct V_6 * V_7 )
{
unsigned int V_96 = 1000 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_97 ) ;
V_9 |= V_98 | V_99 | V_100 ;
F_6 ( V_7 , V_9 , V_97 ) ;
do {
V_9 = F_4 ( V_7 , V_97 ) ;
if ( ! ( V_9 & V_98 ) )
break;
F_50 ( 1000 , 2000 ) ;
} while ( V_96 -- > 0 );
if ( V_96 == 0 )
return - V_101 ;
return 0 ;
}
static void F_51 ( struct V_6 * V_7 )
{
F_24 ( V_7 , 0xffffffff ) ;
F_25 ( V_7 , 0xffffffff , V_51 ) ;
F_26 ( V_7 , 0xffffffff ) ;
F_27 ( V_7 , 0xffffffff , V_51 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
struct V_102 * V_103 )
{
struct V_102 * V_13 ;
int V_104 ;
unsigned int V_105 ;
V_7 -> V_62 = - 1 ;
F_53 (dn, port) {
if ( F_54 ( V_13 , L_1 , & V_105 ) )
continue;
V_104 = F_55 ( V_13 ) ;
if ( V_104 < 0 )
continue;
if ( V_104 == V_106 )
V_7 -> V_58 |= 1 << V_105 ;
if ( V_104 == V_107 )
V_7 -> V_62 = V_105 ;
if ( F_56 ( V_13 , L_2 ) )
V_7 -> V_57 |= 1 << V_105 ;
}
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_102 * V_103 ;
static int V_56 ;
int V_108 ;
V_103 = F_58 ( NULL , NULL , L_3 ) ;
V_7 -> V_86 = F_59 ( V_103 ) ;
if ( ! V_7 -> V_86 )
return - V_109 ;
F_60 ( & V_7 -> V_86 -> V_64 ) ;
V_7 -> V_110 = V_103 ;
V_7 -> V_111 = F_61 ( V_3 -> V_64 ) ;
if ( ! V_7 -> V_111 )
return - V_112 ;
V_7 -> V_111 -> V_7 = V_7 ;
V_7 -> V_111 -> V_113 = L_4 ;
V_7 -> V_111 -> V_114 = F_39 ;
V_7 -> V_111 -> V_115 = F_41 ;
snprintf ( V_7 -> V_111 -> V_116 , V_117 , L_5 ,
V_56 ++ ) ;
V_7 -> V_111 -> V_64 . V_118 = V_103 ;
if ( F_62 ( L_6 ) )
V_7 -> V_85 |= ( 1 << V_84 ) ;
else
V_7 -> V_85 = 0 ;
V_3 -> V_119 = V_7 -> V_85 ;
V_3 -> V_111 = V_7 -> V_111 ;
V_7 -> V_111 -> V_120 = V_3 -> V_64 -> V_120 ;
V_7 -> V_111 -> V_121 = ~ V_7 -> V_85 ;
if ( V_103 )
V_108 = F_63 ( V_7 -> V_111 , V_103 ) ;
else
V_108 = F_64 ( V_7 -> V_111 ) ;
if ( V_108 )
F_65 ( V_103 ) ;
return V_108 ;
}
static void F_66 ( struct V_6 * V_7 )
{
F_67 ( V_7 -> V_111 ) ;
if ( V_7 -> V_110 )
F_65 ( V_7 -> V_110 ) ;
}
static T_1 F_68 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return V_7 -> V_10 . V_122 ;
}
static void F_69 ( struct V_2 * V_3 , int V_13 ,
struct V_52 * V_123 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_72 * V_74 = & V_7 -> V_67 [ V_13 ] . V_68 ;
T_1 V_124 = 0 , V_125 ;
const char * V_126 = NULL ;
T_1 V_9 , V_21 ;
if ( V_7 -> type == V_22 )
V_21 = F_70 ( V_13 ) ;
else
V_21 = F_71 ( V_13 ) ;
switch ( V_123 -> V_127 ) {
case V_128 :
V_126 = L_7 ;
V_124 = 1 ;
case V_129 :
if ( ! V_126 )
V_126 = L_8 ;
V_125 = V_130 ;
break;
case V_131 :
V_126 = L_9 ;
V_125 = V_132 ;
break;
case V_133 :
V_126 = L_10 ;
V_125 = V_134 ;
break;
default:
goto V_135;
}
if ( ! V_123 -> V_95 ) {
V_9 = F_13 ( V_7 , F_72 ( V_13 ) ) ;
V_9 &= ~ V_136 ;
F_14 ( V_7 , V_9 , F_72 ( V_13 ) ) ;
goto V_135;
}
V_9 = F_13 ( V_7 , F_72 ( V_13 ) ) ;
V_9 &= ~ V_137 ;
V_9 &= ~ ( V_138 << V_139 ) ;
V_9 &= ~ ( V_140 | V_141 ) ;
V_9 |= V_125 | V_136 ;
if ( V_124 )
V_9 |= V_137 ;
if ( V_123 -> V_142 ) {
if ( V_123 -> V_143 )
V_9 |= V_141 ;
V_9 |= V_140 ;
}
F_14 ( V_7 , V_9 , F_72 ( V_13 ) ) ;
F_73 ( L_11 , V_13 , V_126 ) ;
V_135:
V_9 = V_144 ;
switch ( V_123 -> V_145 ) {
case V_146 :
V_9 |= V_147 << V_148 ;
break;
case V_149 :
V_9 |= V_150 << V_148 ;
break;
}
if ( V_123 -> V_95 )
V_9 |= V_39 ;
if ( V_123 -> V_151 == V_152 )
V_9 |= V_153 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ! V_123 -> V_154 )
V_74 -> V_69 = F_34 ( V_3 , V_13 , V_123 ) ;
}
static void F_74 ( struct V_2 * V_3 , int V_13 ,
struct V_155 * V_156 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_151 , V_142 , V_21 ;
T_1 V_9 ;
if ( V_7 -> type == V_22 )
V_21 = F_70 ( V_13 ) ;
else
V_21 = F_71 ( V_13 ) ;
V_151 = F_4 ( V_7 , V_157 ) ;
V_142 = F_4 ( V_7 , V_158 ) ;
V_156 -> V_95 = 0 ;
if ( V_13 == V_7 -> V_62 ) {
V_156 -> V_95 = V_7 -> V_67 [ V_13 ] . V_95 ;
if ( ! V_156 -> V_95 )
F_75 ( V_3 -> V_65 [ V_13 ] . V_159 ) ;
V_156 -> V_151 = 1 ;
} else {
V_156 -> V_95 = 1 ;
V_156 -> V_151 = ! ! ( V_151 & ( 1 << V_13 ) ) ;
}
V_9 = F_4 ( V_7 , V_21 ) ;
V_9 |= V_144 ;
if ( V_156 -> V_95 )
V_9 |= V_39 ;
else
V_9 &= ~ V_39 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ( V_142 & ( 1 << V_13 ) ) &&
( V_142 & ( 1 << ( V_13 + V_160 ) ) ) ) {
V_156 -> V_143 = 1 ;
V_156 -> V_142 = 1 ;
}
if ( V_142 & ( 1 << V_13 ) )
V_156 -> V_142 = 1 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_51 ( V_7 ) ;
for ( V_13 = 0 ; V_13 < V_161 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 ||
F_33 ( V_3 , V_13 ) )
F_32 ( V_3 , V_13 , NULL ) ;
}
return 0 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
int V_71 ;
V_71 = F_49 ( V_7 ) ;
if ( V_71 ) {
F_78 ( L_12 , V_162 ) ;
return V_71 ;
}
if ( V_7 -> V_10 . V_59 == 1 )
F_12 ( V_3 , true ) ;
for ( V_13 = 0 ; V_13 < V_161 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_28 ( V_3 , V_13 , NULL ) ;
else if ( F_33 ( V_3 , V_13 ) )
F_8 ( V_3 , V_13 ) ;
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 , int V_13 ,
struct V_163 * V_164 )
{
struct V_165 * V_74 = V_3 -> V_54 -> V_55 -> V_159 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_163 V_166 ;
V_74 -> V_167 -> V_168 ( V_74 , & V_166 ) ;
V_164 -> V_169 = V_166 . V_169 ;
memset ( & V_164 -> V_170 , 0 , sizeof( V_164 -> V_170 ) ) ;
if ( V_166 . V_171 & V_172 )
memcpy ( & V_164 -> V_170 , V_166 . V_170 , sizeof( V_164 -> V_170 ) ) ;
if ( V_7 -> V_70 & ( 1 << V_13 ) )
V_164 -> V_171 = V_166 . V_171 ;
else
V_164 -> V_171 = 0 ;
}
static int F_80 ( struct V_2 * V_3 , int V_13 ,
struct V_163 * V_164 )
{
struct V_165 * V_74 = V_3 -> V_54 -> V_55 -> V_159 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_54 -> V_55 -> V_56 ;
struct V_163 V_166 ;
V_74 -> V_167 -> V_168 ( V_74 , & V_166 ) ;
if ( V_164 -> V_171 & ~ V_166 . V_169 )
return - V_173 ;
if ( V_164 -> V_171 )
V_7 -> V_70 |= ( 1 << V_13 ) ;
else
V_7 -> V_70 &= ~ ( 1 << V_13 ) ;
if ( V_7 -> V_70 && V_7 -> V_70 != ( 1 << V_5 ) )
V_7 -> V_70 |= ( 1 << V_5 ) ;
else
V_7 -> V_70 &= ~ ( 1 << V_5 ) ;
return V_74 -> V_167 -> V_174 ( V_74 , V_164 ) ;
}
static int F_81 ( struct V_6 * V_7 )
{
unsigned int V_96 = 10 ;
T_1 V_9 ;
do {
V_9 = F_4 ( V_7 , V_175 ) ;
if ( ! ( V_9 & V_176 ) )
return 0 ;
F_50 ( 1000 , 2000 ) ;
} while ( V_96 -- );
return - V_101 ;
}
static int F_82 ( struct V_6 * V_7 , T_5 V_77 )
{
F_6 ( V_7 , V_176 | V_77 , V_175 ) ;
return F_81 ( V_7 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_82 ( V_7 , V_177 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ! ( ( 1 << V_13 ) & V_3 -> V_12 ) )
continue;
F_6 ( V_7 , 1 , F_84 ( V_13 ) ) ;
}
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_28 ( V_3 , V_13 , NULL ) ;
else if ( F_33 ( V_3 , V_13 ) )
F_8 ( V_3 , V_13 ) ;
else
F_32 ( V_3 , V_13 , NULL ) ;
}
F_83 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_5 * V_14 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_88 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_3 * V_14 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_89 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_1 * V_14 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_90 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_6 * V_14 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
* V_14 = F_91 ( V_7 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_92 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_5 V_180 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
F_6 ( V_7 , V_180 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_93 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_3 V_180 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
F_6 ( V_7 , V_180 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_94 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_1 V_180 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
F_6 ( V_7 , V_180 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_95 ( struct V_178 * V_64 , T_5 V_179 , T_5 V_9 ,
T_6 V_180 )
{
struct V_6 * V_7 = V_64 -> V_7 ;
F_96 ( V_7 , V_180 , F_87 ( V_179 , V_9 ) ) ;
return 0 ;
}
static int F_97 ( struct V_181 * V_182 )
{
const char * V_183 [ V_184 ] = V_185 ;
struct V_102 * V_103 = V_182 -> V_64 . V_118 ;
const struct V_186 * V_187 = NULL ;
const struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_6 * V_7 ;
struct V_178 * V_64 ;
struct V_2 * V_3 ;
void T_7 * * V_194 ;
struct V_195 * V_196 ;
unsigned int V_8 ;
T_1 V_9 , V_197 ;
int V_71 ;
V_7 = F_98 ( & V_182 -> V_64 , sizeof( * V_7 ) , V_198 ) ;
if ( ! V_7 )
return - V_112 ;
V_193 = F_98 ( & V_182 -> V_64 , sizeof( * V_193 ) , V_198 ) ;
if ( ! V_193 )
return - V_112 ;
V_64 = F_99 ( & V_182 -> V_64 , & V_199 , V_7 ) ;
if ( ! V_64 )
return - V_112 ;
V_191 = F_98 ( & V_182 -> V_64 , sizeof( * V_191 ) , V_198 ) ;
if ( ! V_191 )
return - V_112 ;
V_187 = F_100 ( V_200 , V_103 ) ;
if ( ! V_187 || ! V_187 -> V_189 )
return - V_173 ;
V_189 = V_187 -> V_189 ;
V_7 -> type = V_189 -> type ;
V_7 -> V_201 = V_189 -> V_201 ;
V_7 -> V_202 = V_189 -> V_202 ;
V_7 -> V_203 = V_189 -> V_203 ;
V_191 -> V_204 = V_7 -> type ;
V_64 -> V_191 = V_191 ;
V_7 -> V_64 = V_64 ;
V_3 = V_64 -> V_3 ;
V_3 -> V_193 = & V_205 ;
V_3 -> V_206 = V_36 ;
F_101 ( & V_182 -> V_64 , V_7 ) ;
F_102 ( & V_7 -> V_207 ) ;
F_103 ( & V_7 -> V_208 ) ;
F_103 ( & V_7 -> V_209 . V_210 ) ;
F_104 ( 0 , V_7 -> V_209 . V_211 ) ;
F_52 ( V_7 , V_103 -> V_212 ) ;
V_7 -> V_213 = F_105 ( V_103 , 0 ) ;
V_7 -> V_214 = F_105 ( V_103 , 1 ) ;
V_194 = & V_7 -> V_215 ;
for ( V_8 = 0 ; V_8 < V_184 ; V_8 ++ ) {
V_196 = F_106 ( V_182 , V_216 , V_8 ) ;
* V_194 = F_107 ( & V_182 -> V_64 , V_196 ) ;
if ( F_108 ( * V_194 ) ) {
F_78 ( L_13 , V_183 [ V_8 ] ) ;
return F_109 ( * V_194 ) ;
}
V_194 ++ ;
}
V_71 = F_49 ( V_7 ) ;
if ( V_71 ) {
F_78 ( L_14 , V_71 ) ;
return V_71 ;
}
V_71 = F_57 ( V_3 ) ;
if ( V_71 ) {
F_78 ( L_15 ) ;
return V_71 ;
}
V_71 = F_110 ( V_7 ) ;
if ( V_71 ) {
F_78 ( L_16 ) ;
goto V_217;
}
F_51 ( V_7 ) ;
V_71 = F_111 ( & V_182 -> V_64 , V_7 -> V_213 , F_43 , 0 ,
L_17 , V_7 ) ;
if ( V_71 < 0 ) {
F_78 ( L_18 ) ;
goto V_217;
}
V_71 = F_111 ( & V_182 -> V_64 , V_7 -> V_214 , F_45 , 0 ,
L_19 , V_7 ) ;
if ( V_71 < 0 ) {
F_78 ( L_20 ) ;
goto V_217;
}
V_9 = F_4 ( V_7 , V_218 ) ;
V_9 |= V_219 ;
F_6 ( V_7 , V_9 , V_218 ) ;
V_9 &= ~ V_219 ;
F_6 ( V_7 , V_9 , V_218 ) ;
V_7 -> V_10 . V_11 = F_4 ( V_7 , V_220 ) + 1 ;
if ( V_7 -> V_10 . V_11 > V_161 )
V_7 -> V_10 . V_11 = V_161 ;
if ( F_54 ( V_103 , L_21 ,
& V_7 -> V_10 . V_59 ) )
V_7 -> V_10 . V_59 = 1 ;
V_197 = F_13 ( V_7 , V_221 ) ;
V_7 -> V_10 . V_222 = ( V_197 >> V_223 ) &
V_224 ;
V_7 -> V_10 . V_225 = ( V_197 & V_226 ) ;
V_197 = F_13 ( V_7 , V_227 ) ;
V_7 -> V_10 . V_122 = V_197 & V_228 ;
V_71 = F_112 ( V_64 ) ;
if ( V_71 )
goto V_217;
F_73 ( L_22 ,
V_7 -> V_10 . V_222 >> 8 , V_7 -> V_10 . V_222 & 0xff ,
V_7 -> V_10 . V_225 >> 8 , V_7 -> V_10 . V_225 & 0xff ,
V_7 -> V_215 , V_7 -> V_213 , V_7 -> V_214 ) ;
return 0 ;
V_217:
F_66 ( V_7 ) ;
return V_71 ;
}
static int F_113 ( struct V_181 * V_182 )
{
struct V_6 * V_7 = F_114 ( V_182 ) ;
V_7 -> V_70 = 0 ;
F_76 ( V_7 -> V_64 -> V_3 ) ;
F_115 ( V_7 -> V_64 -> V_3 ) ;
F_66 ( V_7 ) ;
return 0 ;
}
static void F_116 ( struct V_181 * V_182 )
{
struct V_6 * V_7 = F_114 ( V_182 ) ;
if ( V_7 -> V_10 . V_59 == 1 )
F_12 ( V_7 -> V_64 -> V_3 , true ) ;
}
static int F_117 ( struct V_229 * V_64 )
{
struct V_181 * V_182 = F_118 ( V_64 ) ;
struct V_6 * V_7 = F_114 ( V_182 ) ;
return F_119 ( V_7 -> V_64 -> V_3 ) ;
}
static int F_120 ( struct V_229 * V_64 )
{
struct V_181 * V_182 = F_118 ( V_64 ) ;
struct V_6 * V_7 = F_114 ( V_182 ) ;
return F_121 ( V_7 -> V_64 -> V_3 ) ;
}
