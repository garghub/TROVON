static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_5 ( V_4 , V_8 ) ;
F_5 ( V_4 , V_9 ) ;
F_5 ( V_4 , V_10 ) ;
F_5 ( V_4 , V_11 ) ;
F_5 ( V_4 , V_12 ) ;
F_5 ( V_4 , V_13 ) ;
F_5 ( V_4 , V_14 ) ;
F_5 ( V_4 , V_15 ) ;
F_5 ( V_4 , F_6 ( 0 ) ) ;
F_5 ( V_4 , V_16 ) ;
F_7 ( V_4 , V_17 ) ;
F_7 ( V_4 , V_18 ) ;
F_7 ( V_4 , F_8 ( 0 ) ) ;
F_7 ( V_4 , F_9 ( 0 ) ) ;
F_7 ( V_4 , F_10 ( 0 ) ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 , V_20 , V_21 ,
V_22 , V_19 ? V_22 : 0 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 , V_20 , V_21 ,
V_23 , V_19 ? V_23 : 0 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_4 , V_20 , V_25 ,
( V_24 >> ( 16 + 5 ) ) & V_26 ) ;
F_15 ( V_4 , V_20 , V_27 ,
( V_24 >> 5 ) & V_28 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_2 V_33 = 0 ;
F_17 ( V_4 , V_2 -> V_34 ) ;
V_32 = & V_2 -> V_35 [ V_36 ] ;
F_18 ( V_4 , V_37 , V_38 ,
V_39 | V_40 ) ;
switch ( V_32 -> V_41 ) {
case V_42 :
case V_43 :
F_12 ( V_4 , V_20 , V_44 ,
V_45 | V_46 |
V_47 ,
V_48 ) ;
F_12 ( V_4 , V_37 , V_49 ,
V_50 , V_51 ) ;
break;
case V_52 :
V_33 = V_53 |
V_54 |
V_55 |
V_56 ;
goto V_57;
case V_58 :
V_33 = V_59 |
V_60 |
V_61 |
V_62 ;
goto V_57;
case V_63 :
V_33 = V_64 |
V_65 |
V_66 |
V_67 ;
goto V_57;
case V_68 :
V_33 = V_69 |
V_70 |
V_71 |
V_72 ;
V_57:
F_18 ( V_4 , V_37 , V_49 ,
V_51 ) ;
F_12 ( V_4 , V_20 , V_44 ,
V_45 | V_46 |
V_47 , V_73 |
V_74 ) ;
V_30 = F_19 ( V_32 -> V_41 ) ;
F_12 ( V_4 , V_20 , V_75 ,
V_76 ,
F_20 ( V_30 -> V_77 ) ) ;
F_15 ( V_4 , V_20 , V_78 ,
V_33 ) ;
break;
}
F_15 ( V_4 , V_20 , V_79 , 0 & V_80 ) ;
F_15 ( V_4 , V_20 , V_81 ,
( V_32 -> V_82 - 1 ) & V_83 ) ;
F_15 ( V_4 , V_20 , V_84 ,
( V_32 -> V_85 - 1 ) & V_86 ) ;
F_15 ( V_4 , V_20 , F_21 ( 0 ) ,
V_32 -> V_85 - 1 ) ;
V_32 = & V_2 -> V_35 [ V_87 ] ;
F_15 ( V_4 , V_20 , V_88 ,
( V_2 -> V_89 . V_90 >> 5 ) &
V_91 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
if ( F_23 ( & V_2 -> V_89 . V_94 ) )
return;
F_11 ( V_2 , 0 ) ;
V_93 = F_24 ( & V_2 -> V_89 ) ;
if ( V_93 == NULL )
return;
F_14 ( V_2 , V_93 -> V_95 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_96 * V_97 =
F_26 ( & V_2 -> V_98 . V_99 ) ;
if ( V_97 -> V_100 )
F_27 ( & V_97 -> V_101 ) ;
if ( V_2 -> V_102 & V_103 )
F_22 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_104 )
{
if ( F_29 ( & V_2 -> V_105 ,
& V_2 -> V_106 ) )
return;
if ( V_104 & F_30 ( 0 ) )
F_25 ( V_2 ) ;
}
static int F_31 ( struct V_107 * V_108 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_32 ( V_108 ,
struct V_1 , V_89 ) ;
if ( ! ( V_2 -> V_102 & V_103 ) )
return - V_109 ;
F_14 ( V_2 , V_93 -> V_95 ) ;
if ( V_108 -> V_110 & V_111 ) {
if ( V_2 -> V_102 & V_103 )
F_11 ( V_2 , 1 ) ;
F_13 ( V_2 , 1 ) ;
F_33 ( V_108 ) ;
}
return 0 ;
}
static int F_34 ( struct V_112 * V_113 , int V_19 )
{
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_107 * V_89 = & V_2 -> V_89 ;
int V_114 = 0 ;
if ( V_2 -> V_115 == V_116 ) {
if ( V_19 == V_116 )
return 0 ;
F_36 ( V_4 , V_117 ) ;
}
switch ( V_19 ) {
case V_118 :
F_16 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_102 & V_103 &&
! ( V_89 -> V_110 & V_119 ) )
break;
F_37 ( & V_2 -> V_106 , 0 ) ;
if ( V_2 -> V_102 & V_103 )
F_11 ( V_2 , 1 ) ;
F_13 ( V_2 , 1 ) ;
F_33 ( V_89 ) ;
break;
case V_116 :
if ( V_2 -> V_115 == V_116 )
return 0 ;
if ( F_38 ( & V_113 -> V_99 , & V_2 -> V_105 ,
& V_2 -> V_106 ) )
V_114 = - V_120 ;
if ( V_2 -> V_102 & V_103 )
F_11 ( V_2 , 0 ) ;
F_13 ( V_2 , 0 ) ;
F_39 ( V_4 , V_117 ) ;
F_33 ( V_89 ) ;
break;
}
V_2 -> V_115 = V_19 ;
return V_114 ;
}
static struct V_31 *
F_40 ( struct V_1 * V_2 ,
struct V_121 * V_122 , unsigned int V_123 ,
enum V_124 V_125 )
{
if ( V_125 == V_126 )
return F_41 ( V_122 , V_123 ) ;
else
return & V_2 -> V_35 [ V_123 ] ;
}
static void
F_42 ( struct V_1 * V_2 ,
struct V_121 * V_122 , unsigned int V_123 ,
struct V_31 * V_127 ,
enum V_124 V_125 )
{
struct V_31 * V_32 ;
unsigned int V_82 = V_127 -> V_82 ;
unsigned int V_85 = V_127 -> V_85 ;
unsigned int V_128 ;
switch ( V_123 ) {
case V_36 :
for ( V_128 = 0 ; V_128 < F_43 ( V_129 ) ; V_128 ++ ) {
if ( V_127 -> V_41 == V_129 [ V_128 ] )
break;
}
if ( V_128 >= F_43 ( V_129 ) )
V_127 -> V_41 = V_52 ;
V_127 -> V_82 = F_44 ( T_2 , V_82 , 1 , 8192 ) ;
V_127 -> V_85 = F_44 ( T_2 , V_85 , 1 , 8192 ) ;
break;
case V_87 :
V_32 = F_40 ( V_2 , V_122 , V_36 ,
V_125 ) ;
memcpy ( V_127 , V_32 , sizeof( * V_127 ) ) ;
V_127 -> V_82 = F_44 ( T_2 , V_82 , 32 , ( V_127 -> V_82 + 15 ) & ~ 15 ) ;
V_127 -> V_82 &= ~ 15 ;
V_127 -> V_85 = F_44 ( T_2 , V_85 , 32 , V_127 -> V_85 ) ;
break;
case V_130 :
V_32 = F_40 ( V_2 , V_122 , V_36 ,
V_125 ) ;
memcpy ( V_127 , V_32 , sizeof( * V_127 ) ) ;
V_127 -> V_82 = F_44 ( T_2 , V_82 , 32 , V_127 -> V_82 ) ;
V_127 -> V_85 = F_44 ( T_2 , V_85 , 32 , V_127 -> V_85 ) ;
break;
}
V_127 -> V_131 = V_132 ;
V_127 -> V_133 = V_134 ;
}
static int F_45 ( struct V_112 * V_113 ,
struct V_121 * V_122 ,
struct V_135 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_31 * V_32 ;
switch ( V_41 -> V_123 ) {
case V_36 :
if ( V_41 -> V_136 >= F_43 ( V_129 ) )
return - V_137 ;
V_41 -> V_41 = V_129 [ V_41 -> V_136 ] ;
break;
case V_87 :
case V_130 :
if ( V_41 -> V_136 != 0 )
return - V_137 ;
V_32 = F_40 ( V_2 , V_122 , V_36 ,
V_126 ) ;
V_41 -> V_41 = V_32 -> V_41 ;
break;
default:
return - V_137 ;
}
return 0 ;
}
static int F_46 ( struct V_112 * V_113 ,
struct V_121 * V_122 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_31 V_32 ;
if ( V_139 -> V_136 != 0 )
return - V_137 ;
V_32 . V_41 = V_139 -> V_41 ;
V_32 . V_82 = 1 ;
V_32 . V_85 = 1 ;
F_42 ( V_2 , V_122 , V_139 -> V_123 , & V_32 ,
V_126 ) ;
V_139 -> V_140 = V_32 . V_82 ;
V_139 -> V_141 = V_32 . V_85 ;
if ( V_32 . V_41 != V_139 -> V_41 )
return - V_137 ;
V_32 . V_41 = V_139 -> V_41 ;
V_32 . V_82 = - 1 ;
V_32 . V_85 = - 1 ;
F_42 ( V_2 , V_122 , V_139 -> V_123 , & V_32 ,
V_126 ) ;
V_139 -> V_142 = V_32 . V_82 ;
V_139 -> V_143 = V_32 . V_85 ;
return 0 ;
}
static int F_47 ( struct V_112 * V_113 , struct V_121 * V_122 ,
struct V_144 * V_127 )
{
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_31 * V_32 ;
V_32 = F_40 ( V_2 , V_122 , V_127 -> V_123 , V_127 -> V_125 ) ;
if ( V_32 == NULL )
return - V_137 ;
V_127 -> V_32 = * V_32 ;
return 0 ;
}
static int F_48 ( struct V_112 * V_113 , struct V_121 * V_122 ,
struct V_144 * V_127 )
{
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_31 * V_32 ;
V_32 = F_40 ( V_2 , V_122 , V_127 -> V_123 , V_127 -> V_125 ) ;
if ( V_32 == NULL )
return - V_137 ;
F_42 ( V_2 , V_122 , V_127 -> V_123 , & V_127 -> V_32 , V_127 -> V_125 ) ;
* V_32 = V_127 -> V_32 ;
if ( V_127 -> V_123 == V_36 ) {
V_32 = F_40 ( V_2 , V_122 ,
V_87 ,
V_127 -> V_125 ) ;
* V_32 = V_127 -> V_32 ;
F_42 ( V_2 , V_122 , V_87 ,
V_32 , V_127 -> V_125 ) ;
V_32 = F_40 ( V_2 , V_122 ,
V_130 ,
V_127 -> V_125 ) ;
* V_32 = V_127 -> V_32 ;
F_42 ( V_2 , V_122 , V_130 , V_32 ,
V_127 -> V_125 ) ;
}
return 0 ;
}
static int F_49 ( struct V_112 * V_113 ,
struct V_145 * V_146 ,
struct V_144 * V_147 ,
struct V_144 * V_148 )
{
if ( V_147 -> V_32 . V_82 != V_148 -> V_32 . V_82 ||
V_147 -> V_32 . V_85 != V_148 -> V_32 . V_85 )
return - V_149 ;
if ( V_147 -> V_32 . V_41 != V_148 -> V_32 . V_41 )
return - V_149 ;
return 0 ;
}
static int F_50 ( struct V_112 * V_113 ,
struct V_121 * V_122 )
{
struct V_144 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_123 = V_36 ;
V_32 . V_125 = V_122 ? V_126 : V_150 ;
V_32 . V_32 . V_41 = V_52 ;
V_32 . V_32 . V_82 = 4096 ;
V_32 . V_32 . V_85 = 4096 ;
F_48 ( V_113 , V_122 , & V_32 ) ;
return 0 ;
}
static int F_51 ( struct V_151 * V_99 ,
const struct V_152 * V_153 ,
const struct V_152 * V_154 , T_2 V_155 )
{
struct V_112 * V_113 = F_52 ( V_99 ) ;
struct V_1 * V_2 = F_35 ( V_113 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_153 -> V_136 | F_53 ( V_154 -> V_99 ) ) {
case V_36 | V_156 :
if ( ! ( V_155 & V_157 ) ) {
V_2 -> V_34 = V_158 ;
break;
}
if ( V_2 -> V_34 != V_158 )
return - V_159 ;
if ( V_154 -> V_99 == & V_4 -> V_160 . V_98 . V_99 )
V_2 -> V_34 = V_161 ;
else if ( V_154 -> V_99 == & V_4 -> V_162 . V_98 . V_99 )
V_2 -> V_34 = V_163 ;
break;
case V_87 | V_164 :
if ( V_155 & V_157 ) {
if ( V_2 -> V_102 & ~ V_103 )
return - V_159 ;
V_2 -> V_102 |= V_103 ;
} else {
V_2 -> V_102 &= ~ V_103 ;
}
break;
case V_130 | V_156 :
if ( V_155 & V_157 ) {
if ( V_2 -> V_102 & ~ V_165 )
return - V_159 ;
V_2 -> V_102 |= V_165 ;
} else {
V_2 -> V_102 &= ~ V_165 ;
}
break;
default:
return - V_137 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_112 * V_113 = & V_2 -> V_98 ;
struct V_152 * V_166 = V_2 -> V_166 ;
struct V_151 * V_167 = & V_113 -> V_99 ;
int V_114 ;
V_2 -> V_34 = V_158 ;
F_55 ( V_113 , & V_168 ) ;
V_113 -> V_169 = & V_170 ;
F_56 ( V_113 -> V_171 , L_3 , sizeof( V_113 -> V_171 ) ) ;
V_113 -> V_172 = 1 << 16 ;
F_57 ( V_113 , V_2 ) ;
V_113 -> V_155 |= V_173 ;
V_166 [ V_36 ] . V_155 = V_174 ;
V_166 [ V_87 ] . V_155 = V_175 ;
V_166 [ V_130 ] . V_155 = V_175 ;
V_167 -> V_176 = & V_177 ;
V_114 = F_58 ( V_167 , V_178 , V_166 , 0 ) ;
if ( V_114 < 0 )
return V_114 ;
F_50 ( V_113 , NULL ) ;
V_2 -> V_89 . type = V_179 ;
V_2 -> V_89 . V_176 = & V_180 ;
V_2 -> V_89 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_89 . V_181 = F_59 ( 4096 * 4096 ) * 3 ;
V_2 -> V_89 . V_182 = 32 ;
V_2 -> V_89 . V_183 = 1 ;
V_2 -> V_89 . V_184 = 0x1ffe0 ;
V_114 = F_60 ( & V_2 -> V_89 , L_4 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_61 ( & V_2 -> V_98 . V_99 ,
V_87 ,
& V_2 -> V_89 . V_108 . V_99 , 0 , 0 ) ;
if ( V_114 < 0 )
return V_114 ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_98 . V_99 ) ;
F_64 ( & V_2 -> V_98 ) ;
F_65 ( & V_2 -> V_89 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
int V_114 ;
V_114 = F_67 ( V_186 , & V_2 -> V_98 ) ;
if ( V_114 < 0 )
goto error;
V_114 = F_68 ( & V_2 -> V_89 , V_186 ) ;
if ( V_114 < 0 )
goto error;
return 0 ;
error:
F_62 ( V_2 ) ;
return V_114 ;
}
int F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_115 = V_116 ;
F_70 ( & V_2 -> V_105 ) ;
return F_54 ( V_2 ) ;
}
void F_71 ( struct V_3 * V_4 )
{
}
