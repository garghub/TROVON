static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0x14 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_18 , V_19 ;
struct V_20 * V_21 ;
F_1 ( V_2 ) ;
F_3 ( & V_2 -> V_22 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_23 = F_4 ( V_24 *
sizeof( struct V_20 ) + 4 ,
V_25 ) ;
if ( V_2 -> V_23 == NULL ) {
V_19 = V_26 ;
goto V_27;
}
V_2 -> V_28 = V_2 -> V_23 +
4 -
( ( V_29 ) ( V_2 -> V_23 ) & 3 ) ;
V_21 = (struct V_20 * ) V_2 -> V_28 ;
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ ) {
F_5 ( & ( V_21 -> V_30 ) ) ;
F_6 ( & ( V_21 -> V_30 ) ,
& ( V_2 -> V_22 . V_31 ) ) ;
V_21 -> V_32 = NULL ;
V_21 -> V_33 = V_34 ;
V_21 -> V_35 = V_2 -> V_36 ;
V_21 ++ ;
}
V_2 -> V_37 = V_24 ;
V_19 = V_38 ;
V_27:
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_23 ) ;
return 0 ;
}
void F_9 ( struct V_39 * V_35 )
{
struct V_1 * V_40 = & V_35 -> V_41 ;
V_40 -> V_36 = V_35 ;
F_2 ( V_40 ) ;
}
void F_10 ( struct V_39 * V_35 )
{
struct V_1 * V_40 = & V_35 -> V_41 ;
F_7 ( V_40 ) ;
}
static T_1 F_11 ( struct V_39 * V_42 , struct V_43 V_44 )
{
T_1 V_45 = 0 , V_46 = 0 ;
T_2 V_47 = V_44 . V_48 ;
T_3 V_49 = V_44 . V_50 ;
T_2 V_51 = V_44 . V_52 ;
V_45 = ( V_47 << 24 ) | ( V_49 << 8 ) | V_51 ;
if ( F_12 ( V_42 , V_45 ) )
F_13 ( V_42 , & V_46 , 1 ) ;
else
V_46 = 0 ;
return V_46 ;
}
static T_2 F_14 ( struct V_39 * V_42 ,
struct V_43 V_44 , T_1 V_50 )
{
T_1 V_45 = 0 ;
T_2 V_47 = V_44 . V_48 ;
T_1 V_49 = V_44 . V_50 ;
T_2 V_51 = V_44 . V_52 ;
F_13 ( V_42 , & V_50 , 0 ) ;
F_15 ( 100 ) ;
V_45 = ( V_47 << 24 ) | ( V_49 << 8 ) | V_51 ;
return F_12 ( V_42 , V_45 ) ;
}
T_1 F_16 ( struct V_39 * V_42 , T_3 V_53 )
{
T_2 V_54 = V_53 & 0x0003 ;
T_3 V_55 = V_53 & 0x0FFC ;
T_1 V_56 = 0 ;
struct V_43 V_44 ;
V_44 . V_48 = V_57 ;
V_44 . V_50 = V_55 ;
V_44 . V_52 = V_58 ;
V_56 = F_11 ( V_42 , V_44 ) ;
if ( V_54 != 0 ) {
T_1 V_59 = 0 ;
V_56 >>= ( V_54 * 8 ) ;
V_44 . V_50 += 4 ;
V_59 = F_11 ( V_42 , V_44 ) ;
V_59 <<= ( ( 4 - V_54 ) * 8 ) ;
V_56 |= V_59 ;
}
return V_56 ;
}
T_2 F_17 ( struct V_39 * V_42 , T_3 V_53 , T_1 V_50 )
{
T_2 V_54 = V_53 & 0x0003 ;
T_3 V_55 = V_53 & 0x0FFC ;
struct V_43 V_44 ;
V_44 . V_48 = V_57 ;
V_44 . V_50 = V_55 ;
V_44 . V_52 = V_60 ;
if ( V_54 != 0 ) {
T_1 V_61 = 0 ;
T_1 V_62 = V_50 ;
V_61 = F_16 ( V_42 , V_44 . V_50 ) ;
V_61 &= ( 0xFFFFFFFF >> ( ( 4 - V_54 ) * 8 ) ) ;
V_50 = V_61 | ( V_62 << ( V_54 * 8 ) ) ;
if ( F_14 ( V_42 , V_44 , V_50 ) == false )
return false ;
V_44 . V_50 += 4 ;
V_61 = F_16 ( V_42 , V_44 . V_50 ) ;
V_61 &= ( 0xFFFFFFFF << ( V_54 * 8 ) ) ;
V_50 = V_61 | ( V_62 >> ( ( 4 - V_54 ) * 8 ) ) ;
}
return F_14 ( V_42 , V_44 , V_50 ) ;
}
T_1 F_18 ( struct V_39 * V_42 , T_2 V_63 , T_2 V_53 )
{
T_3 V_64 = ( V_63 << 8 ) | V_53 ;
T_1 V_65 ;
struct V_43 V_44 ;
V_44 . V_48 = V_57 ;
V_44 . V_50 = V_64 ;
V_44 . V_52 = V_66 ;
V_65 = F_11 ( V_42 , V_44 ) ;
return V_65 ;
}
T_2 F_19 ( struct V_39 * V_42 , T_2 V_63 , T_2 V_53 , T_1 V_50 )
{
T_3 V_64 = ( V_63 << 8 ) | V_53 ;
struct V_43 V_44 ;
V_44 . V_48 = V_57 ;
V_44 . V_50 = V_64 ;
V_44 . V_52 = V_67 ;
return F_14 ( V_42 , V_44 , V_50 ) ;
}
static T_1 F_20 ( T_1 V_68 )
{
T_1 V_18 ;
for ( V_18 = 0 ; V_18 <= 31 ; V_18 ++ )
if ( ( ( V_68 >> V_18 ) & 0x1 ) == 1 )
break;
return V_18 ;
}
static T_1 F_21 ( struct V_39 * V_42 , T_3 V_53 , T_1 V_68 )
{
T_1 V_69 , V_70 , V_71 ;
V_69 = F_16 ( V_42 , V_53 ) ;
V_70 = F_20 ( V_68 ) ;
V_71 = ( V_69 & V_68 ) >> V_70 ;
return V_71 ;
}
static T_2 F_22 ( struct V_39 * V_42 ,
T_3 V_53 ,
T_1 V_68 ,
T_1 V_50 )
{
T_1 V_69 , V_70 , V_71 ;
if ( V_68 != V_72 ) {
V_69 = F_16 ( V_42 , V_53 ) ;
V_70 = F_20 ( V_68 ) ;
V_71 = ( ( V_69 & ( ~ V_68 ) ) | ( V_50 << V_70 ) ) ;
} else
V_71 = V_50 ;
return F_17 ( V_42 , V_53 , V_71 ) ;
}
static T_1 F_23 ( struct V_39 * V_42 , T_2 V_63 , T_2 V_53 ,
T_1 V_68 )
{
T_1 V_69 , V_70 , V_71 ;
V_69 = F_18 ( V_42 , V_63 , V_53 ) ;
V_70 = F_20 ( V_68 ) ;
V_71 = ( V_69 & V_68 ) >> V_70 ;
return V_71 ;
}
static T_2 F_24 ( struct V_39 * V_42 , T_2 V_63 , T_2 V_53 , T_1 V_68 ,
T_1 V_50 )
{
T_1 V_69 , V_70 , V_71 ;
if ( V_68 != V_72 ) {
V_69 = F_18 ( V_42 , V_63 , V_53 ) ;
V_70 = F_20 ( V_68 ) ;
V_71 = ( ( V_69 & ( ~ V_68 ) ) | ( V_50 << V_70 ) ) ;
} else
V_71 = V_50 ;
return F_19 ( V_42 , V_63 , V_53 , V_71 ) ;
}
void F_25 ( struct V_39 * V_42 )
{
struct V_73 * V_74 = & V_42 -> V_75 ;
struct V_76 * V_77 = NULL ;
struct V_78 * V_79 = NULL ;
T_3 V_80 = F_26 ( V_81 ) ;
V_77 = F_4 ( sizeof( * V_77 ) , V_25 ) ;
if ( V_77 == NULL )
return;
V_79 = F_4 ( sizeof( * V_79 ) , V_25 ) ;
if ( V_79 == NULL ) {
F_8 ( V_77 ) ;
return;
}
V_79 -> V_5 = V_42 -> V_41 . V_5 ;
F_27 ( V_77 , V_79 , V_80 ) ;
F_28 ( V_74 , V_77 ) ;
}
static void F_29 ( struct V_39 * V_42 , T_2 V_82 )
{
T_3 V_83 = 0 ;
V_83 = V_82 ;
F_22 ( V_42 , V_84 , V_85 , V_83 ) ;
}
static void F_30 ( struct V_39 * V_42 , T_2 V_82 )
{
T_1 V_83 = 0 ;
V_83 |= ( ( V_82 << 24 ) | ( V_82 << 16 ) | ( V_82 << 8 ) | V_82 ) ;
F_22 ( V_42 , V_86 , V_87 , V_83 ) ;
F_22 ( V_42 , V_88 , V_89 , V_83 ) ;
F_22 ( V_42 , V_90 , V_91 , V_83 ) ;
F_22 ( V_42 , V_92 , V_93 , V_83 ) ;
F_22 ( V_42 , V_94 , V_95 , V_83 ) ;
F_22 ( V_42 , V_96 , V_97 , V_83 ) ;
}
void F_31 ( struct V_39 * V_42 )
{
T_2 V_82 = V_42 -> V_41 . V_9 ;
F_29 ( V_42 , V_82 ) ;
F_30 ( V_42 , V_82 ) ;
}
void F_32 ( struct V_39 * V_42 , T_1 V_98 )
{
T_1 V_99 , V_100 , V_101 , V_102 ;
V_99 = ( V_98 & 0x000000ff ) ;
V_100 = ( ( V_98 & 0x0000ff00 ) >> 8 ) ;
V_101 = ( ( V_98 & 0x00ff0000 ) >> 16 ) ;
V_102 = ( V_101 << 8 | V_100 << 4 | V_99 ) ;
F_22 ( V_42 , V_103 ,
( V_104 | V_105 | V_106 ) , V_102 ) ;
}
void F_33 ( struct V_39 * V_42 )
{
T_2 V_63 = V_107 ;
T_2 V_53 = V_108 ;
T_1 V_50 ;
V_50 = ( V_42 -> V_41 . V_8 < 4 ) ? 0x4440 : 0xF200 ;
F_19 ( V_42 , V_63 , V_53 , V_50 ) ;
}
void F_34 ( struct V_39 * V_42 )
{
T_2 V_109 = 0 ;
T_2 V_110 = V_42 -> V_41 . V_111 ;
V_109 = F_35 ( V_42 , 0x10250203 ) ;
if ( V_110 == V_112 )
V_109 |= F_36 ( 2 ) ;
else
V_109 &= ~ ( F_36 ( 2 ) ) ;
F_37 ( V_42 , 0x10250203 , V_109 ) ;
switch ( V_110 ) {
case V_112 :
F_22 ( V_42 , V_113 , V_114 , 0x0 ) ;
F_22 ( V_42 , V_115 , V_114 , 0x0 ) ;
F_22 ( V_42 , V_116 , V_72 , 0x58 ) ;
break;
case V_117 :
F_22 ( V_42 , V_113 , V_114 , 0x1 ) ;
F_22 ( V_42 , V_115 , V_114 , 0x1 ) ;
F_22 ( V_42 , V_118 , V_119 ,
( V_120 >> 1 ) ) ;
F_22 ( V_42 , V_121 , 0xC00 ,
V_120 ) ;
F_22 ( V_42 , V_116 , V_72 , 0x18 ) ;
break;
default:
break;
}
switch ( V_110 ) {
case V_112 :
F_24 ( V_42 , V_107 , V_122 ,
F_36 ( 10 ) | F_36 ( 11 ) , 0x01 ) ;
break;
case V_117 :
F_24 ( V_42 , V_107 , V_122 ,
F_36 ( 10 ) | F_36 ( 11 ) , 0x00 ) ;
break;
default:
break;
}
}
void F_38 ( struct V_39 * V_42 )
{
T_1 V_123 = 0 , V_124 = 0 ;
T_2 V_125 = 0 ;
T_2 V_126 = 0 ;
T_1 V_127 = 0 ;
struct V_128 * V_129 ;
V_129 = (struct V_128 * ) & V_126 ;
switch ( V_42 -> V_41 . V_10 ) {
case V_11 :
F_22 ( V_42 , V_130 , 0xe , 2 ) ;
F_22 ( V_42 , V_131 , 0xe , 1 ) ;
V_123 = 0x3 ;
V_124 = 0x11111111 ;
V_129 -> V_132 = 0x8 ;
break;
case V_133 :
F_22 ( V_42 , V_130 , 0xe , 1 ) ;
F_22 ( V_42 , V_131 , 0xe , 2 ) ;
V_123 = 0x3 ;
V_124 = 0x22222222 ;
V_129 -> V_132 = 0x4 ;
break;
case V_13 :
F_22 ( V_42 , V_130 , 0xe , 2 ) ;
F_22 ( V_42 , V_131 , 0xe , 2 ) ;
V_123 = 0x3 ;
V_124 = 0x3321333 ;
V_129 -> V_132 = 0xC ;
break;
default:
break;
}
F_22 ( V_42 , V_134 , 0xffffffff , V_124 ) ;
F_22 ( V_42 , V_135 , 0x0000000f , V_123 ) ;
switch ( V_42 -> V_41 . V_12 ) {
case V_11 :
V_125 = 0x1 ;
V_129 -> V_136 = 0x0 ;
V_129 -> V_137 = 0x0 ;
break;
case V_133 :
V_125 = 0x2 ;
V_129 -> V_136 = 0x1 ;
V_129 -> V_137 = 0x1 ;
break;
case V_13 :
V_125 = 0x3 ;
V_129 -> V_136 = 0x0 ;
V_129 -> V_137 = 0x1 ;
break;
default:
break;
}
F_22 ( V_42 , V_138 , 0x0000000f ,
V_125 ) ;
F_22 ( V_42 , V_139 , 0x0000000f ,
V_125 ) ;
V_127 = V_126 ;
F_22 ( V_42 , V_140 , V_141 , V_127 ) ;
}
void F_39 ( struct V_39 * V_42 )
{
F_22 ( V_42 , V_142 , V_143 ,
V_42 -> V_41 . V_144 ) ;
}
static void F_40 ( struct V_39 * V_42 )
{
F_24 ( V_42 , V_107 , V_145 , V_146 , 0x60 ) ;
}
static T_1 F_41 ( struct V_39 * V_42 )
{
T_1 V_147 = 0 ;
V_147 = F_23 ( V_42 , V_107 , V_145 , 0x1F ) ;
return V_147 ;
}
void F_42 ( struct V_39 * V_42 , T_1 * V_50 )
{
F_40 ( V_42 ) ;
F_15 ( 1000 ) ;
* V_50 = F_41 ( V_42 ) ;
}
void F_43 ( struct V_39 * V_42 , T_2 V_148 )
{
if ( V_148 ) {
if ( ! F_21 ( V_42 , V_113 , V_149 ) )
F_22 ( V_42 , V_113 , V_149 , V_150 ) ;
F_22 ( V_42 , V_118 , V_151 , V_152 ) ;
F_22 ( V_42 , V_118 , V_153 , V_150 ) ;
F_22 ( V_42 , V_121 , V_154 , V_152 ) ;
F_22 ( V_42 , V_121 , V_155 , V_150 ) ;
F_22 ( V_42 , V_121 , V_156 , V_152 ) ;
} else {
F_22 ( V_42 , V_121 , V_154 , V_152 ) ;
F_22 ( V_42 , V_121 , V_155 ,
V_152 ) ;
F_22 ( V_42 , V_121 , V_156 , V_152 ) ;
F_15 ( 20 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x0 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x1 ) ;
}
}
void F_44 ( struct V_39 * V_42 , T_2 V_148 )
{
T_2 V_159 = V_42 -> V_41 . V_160 ;
switch ( V_42 -> V_41 . V_10 ) {
case V_133 :
V_159 = V_161 ;
break;
case V_11 :
default:
V_159 = V_107 ;
break;
}
if ( V_148 ) {
F_22 ( V_42 , V_113 , V_162 , V_152 ) ;
F_22 ( V_42 , V_113 , V_149 , V_152 ) ;
F_24 ( V_42 , V_159 , V_163 , V_146 ,
0xd4000 ) ;
F_15 ( 100 ) ;
F_24 ( V_42 , V_159 , V_164 , V_146 , 0x2001f ) ;
F_15 ( 100 ) ;
} else {
F_22 ( V_42 , V_113 , V_162 , V_150 ) ;
F_22 ( V_42 , V_113 , V_149 , V_150 ) ;
F_24 ( V_42 , V_159 , V_163 , V_146 ,
0x54000 ) ;
F_15 ( 100 ) ;
F_24 ( V_42 , V_159 , V_164 , V_146 , 0x30000 ) ;
F_15 ( 100 ) ;
}
}
void F_45 ( struct V_39 * V_42 , T_2 V_148 )
{
if ( V_148 ) {
if ( V_42 -> V_41 . V_8 <= V_165 ) {
if ( ! F_21 ( V_42 , V_113 , V_162 ) ) {
F_22 ( V_42 , V_113 , V_162 ,
V_150 ) ;
}
F_22 ( V_42 , V_121 , V_154 ,
V_152 ) ;
F_22 ( V_42 , V_121 , V_155 ,
V_152 ) ;
F_22 ( V_42 , V_121 , V_156 ,
V_152 ) ;
F_22 ( V_42 , V_118 , V_151 , 0x2 ) ;
F_22 ( V_42 , V_118 , V_153 ,
V_152 ) ;
F_22 ( V_42 , V_118 , V_166 , 0x0 ) ;
}
} else {
if ( V_42 -> V_41 . V_8 <= V_165 ) {
F_22 ( V_42 , V_118 , V_151 , 0x0 ) ;
F_22 ( V_42 , V_118 , V_153 ,
V_150 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x0 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x1 ) ;
}
}
}
static void F_46 ( struct V_39 * V_42 , T_2 V_148 )
{
T_1 V_167 ;
if ( V_148 ) {
if ( ! F_21 ( V_42 , V_113 , V_162 ) ) {
F_22 ( V_42 , V_113 , V_162 , V_150 ) ;
}
F_22 ( V_42 , V_121 , V_154 , V_152 ) ;
F_22 ( V_42 , V_121 , V_155 , V_152 ) ;
F_22 ( V_42 , V_121 , V_156 , V_152 ) ;
V_167 = V_42 -> V_41 . V_8 ;
F_22 ( V_42 , V_118 , V_166 , V_167 ) ;
F_22 ( V_42 , V_118 , V_151 , 0x2 ) ;
F_22 ( V_42 , V_118 , V_153 , V_150 ) ;
} else {
F_22 ( V_42 , V_118 , V_151 , 0x0 ) ;
F_22 ( V_42 , V_118 , V_153 , V_150 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x0 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x1 ) ;
}
}
static void F_47 ( struct V_39 * V_42 , T_2 V_148 )
{
if ( V_148 ) {
if ( ! F_21 ( V_42 , V_113 , V_149 ) ) {
F_22 ( V_42 , V_113 , V_149 , V_150 ) ;
}
F_22 ( V_42 , V_118 , V_151 , V_152 ) ;
F_22 ( V_42 , V_118 , V_153 , V_150 ) ;
F_22 ( V_42 , V_121 , V_154 , V_150 ) ;
F_22 ( V_42 , V_121 , V_155 , V_152 ) ;
F_22 ( V_42 , V_121 , V_156 , V_152 ) ;
} else {
F_22 ( V_42 , V_121 , V_154 , V_152 ) ;
F_22 ( V_42 , V_121 , V_155 ,
V_152 ) ;
F_22 ( V_42 , V_121 , V_156 , V_152 ) ;
F_15 ( 20 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x0 ) ;
F_22 ( V_42 , V_157 , V_158 , 0x1 ) ;
}
}
void F_48 ( struct V_39 * V_42 , T_2 V_148 )
{
if ( V_148 ) {
F_17 ( V_42 , V_168 ,
F_16 ( V_42 ,
V_168 ) & 0xFE1FFFFF ) ;
F_15 ( 100 ) ;
}
if ( V_42 -> V_41 . V_8 <= V_165 )
F_46 ( V_42 , V_148 ) ;
else if ( ( V_42 -> V_41 . V_8 >= V_169 ) &&
( V_42 -> V_41 . V_8 <= V_170 ) )
F_47 ( V_42 , V_148 ) ;
if ( ! V_148 )
F_17 ( V_42 , V_168 ,
F_16 ( V_42 ,
V_168 ) | 0x01E00000 ) ;
}
void F_49 ( struct V_39 * V_42 )
{
T_1 V_18 , V_171 = 0 ;
for ( V_18 = V_172 ; V_18 <= V_173 ; V_18 ++ ) {
V_171 = 0 ;
V_171 |= ( V_18 << 28 ) ;
V_171 |= 0x08000000 ;
F_50 ( V_42 , V_174 , V_171 ) ;
}
}
static T_1 F_51 ( struct V_39 * V_42 , T_1 V_175 )
{
T_1 V_171 = 0 , V_176 = 0 ;
T_1 V_177 ;
V_177 = V_175 << 28 ;
V_171 |= ( V_177 & 0xF0000000 ) ;
F_50 ( V_42 , V_174 , V_171 ) ;
V_176 = F_52 ( V_42 , V_174 ) & V_178 ;
return V_176 ;
}
T_1 F_53 ( struct V_39 * V_42 )
{
T_1 V_179 = 0 , V_180 = 0 , V_181 = 0 ;
V_179 = F_51 ( V_42 , V_182 ) ;
V_180 = F_51 ( V_42 , V_183 ) ;
V_181 = F_51 ( V_42 , V_184 ) ;
return V_179 + V_180 + V_181 ;
}
T_1 F_54 ( struct V_39 * V_42 )
{
T_1 V_179 = 0 , V_180 = 0 , V_181 = 0 ;
V_179 = F_51 ( V_42 , V_185 ) ;
V_180 = F_51 ( V_42 , V_186 ) ;
V_181 = F_51 ( V_42 , V_173 ) ;
return V_179 + V_180 + V_181 ;
}
