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
if ( ! V_93 )
return;
F_14 ( V_2 , V_93 -> V_95 ) ;
F_11 ( V_2 , 1 ) ;
}
void F_25 ( struct V_1 * V_2 , T_2 V_96 )
{
if ( F_26 ( & V_2 -> V_97 ,
& V_2 -> V_98 ) )
return;
if ( ( V_96 & F_27 ( 0 ) ) &&
( V_2 -> V_99 & V_100 ) )
F_22 ( V_2 ) ;
}
static int F_28 ( struct V_101 * V_102 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_29 ( V_102 ,
struct V_1 , V_89 ) ;
if ( ! ( V_2 -> V_99 & V_100 ) )
return - V_103 ;
F_14 ( V_2 , V_93 -> V_95 ) ;
if ( V_102 -> V_104 & V_105 ) {
if ( V_2 -> V_99 & V_100 )
F_11 ( V_2 , 1 ) ;
F_13 ( V_2 , 1 ) ;
F_30 ( V_102 ) ;
}
return 0 ;
}
static int F_31 ( struct V_106 * V_107 , int V_19 )
{
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_101 * V_89 = & V_2 -> V_89 ;
int V_108 = 0 ;
if ( V_2 -> V_109 == V_110 ) {
if ( V_19 == V_110 )
return 0 ;
F_33 ( V_4 , V_111 ) ;
}
switch ( V_19 ) {
case V_112 :
F_16 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_99 & V_100 &&
! ( V_89 -> V_104 & V_113 ) )
break;
F_34 ( & V_2 -> V_98 , 0 ) ;
if ( V_2 -> V_99 & V_100 )
F_11 ( V_2 , 1 ) ;
F_13 ( V_2 , 1 ) ;
F_30 ( V_89 ) ;
break;
case V_110 :
if ( V_2 -> V_109 == V_110 )
return 0 ;
if ( F_35 ( & V_107 -> V_114 , & V_2 -> V_97 ,
& V_2 -> V_98 ) )
V_108 = - V_115 ;
if ( V_2 -> V_99 & V_100 )
F_11 ( V_2 , 0 ) ;
F_13 ( V_2 , 0 ) ;
F_36 ( V_4 , V_111 ) ;
F_30 ( V_89 ) ;
break;
}
V_2 -> V_109 = V_19 ;
return V_108 ;
}
static struct V_31 *
F_37 ( struct V_1 * V_2 ,
struct V_116 * V_117 , unsigned int V_118 ,
enum V_119 V_120 )
{
if ( V_120 == V_121 )
return F_38 ( & V_2 -> V_122 , V_117 , V_118 ) ;
return & V_2 -> V_35 [ V_118 ] ;
}
static void
F_39 ( struct V_1 * V_2 ,
struct V_116 * V_117 , unsigned int V_118 ,
struct V_31 * V_123 ,
enum V_119 V_120 )
{
struct V_31 * V_32 ;
unsigned int V_82 = V_123 -> V_82 ;
unsigned int V_85 = V_123 -> V_85 ;
unsigned int V_124 ;
switch ( V_118 ) {
case V_36 :
for ( V_124 = 0 ; V_124 < F_40 ( V_125 ) ; V_124 ++ ) {
if ( V_123 -> V_41 == V_125 [ V_124 ] )
break;
}
if ( V_124 >= F_40 ( V_125 ) )
V_123 -> V_41 = V_52 ;
V_123 -> V_82 = F_41 ( T_2 , V_82 , 1 , 8192 ) ;
V_123 -> V_85 = F_41 ( T_2 , V_85 , 1 , 8192 ) ;
break;
case V_87 :
V_32 = F_37 ( V_2 , V_117 , V_36 ,
V_120 ) ;
memcpy ( V_123 , V_32 , sizeof( * V_123 ) ) ;
V_123 -> V_82 = F_41 ( T_2 , V_82 , 32 , ( V_123 -> V_82 + 15 ) & ~ 15 ) ;
V_123 -> V_82 &= ~ 15 ;
V_123 -> V_85 = F_41 ( T_2 , V_85 , 32 , V_123 -> V_85 ) ;
break;
case V_126 :
V_32 = F_37 ( V_2 , V_117 , V_36 ,
V_120 ) ;
memcpy ( V_123 , V_32 , sizeof( * V_123 ) ) ;
V_123 -> V_82 = F_41 ( T_2 , V_82 , 32 , V_123 -> V_82 ) ;
V_123 -> V_85 = F_41 ( T_2 , V_85 , 32 , V_123 -> V_85 ) ;
break;
}
V_123 -> V_127 = V_128 ;
V_123 -> V_129 = V_130 ;
}
static int F_42 ( struct V_106 * V_107 ,
struct V_116 * V_117 ,
struct V_131 * V_41 )
{
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_31 * V_32 ;
switch ( V_41 -> V_118 ) {
case V_36 :
if ( V_41 -> V_132 >= F_40 ( V_125 ) )
return - V_133 ;
V_41 -> V_41 = V_125 [ V_41 -> V_132 ] ;
break;
case V_87 :
case V_126 :
if ( V_41 -> V_132 != 0 )
return - V_133 ;
V_32 = F_37 ( V_2 , V_117 , V_36 ,
V_41 -> V_120 ) ;
V_41 -> V_41 = V_32 -> V_41 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_43 ( struct V_106 * V_107 ,
struct V_116 * V_117 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_31 V_32 ;
if ( V_135 -> V_132 != 0 )
return - V_133 ;
V_32 . V_41 = V_135 -> V_41 ;
V_32 . V_82 = 1 ;
V_32 . V_85 = 1 ;
F_39 ( V_2 , V_117 , V_135 -> V_118 , & V_32 , V_135 -> V_120 ) ;
V_135 -> V_136 = V_32 . V_82 ;
V_135 -> V_137 = V_32 . V_85 ;
if ( V_32 . V_41 != V_135 -> V_41 )
return - V_133 ;
V_32 . V_41 = V_135 -> V_41 ;
V_32 . V_82 = - 1 ;
V_32 . V_85 = - 1 ;
F_39 ( V_2 , V_117 , V_135 -> V_118 , & V_32 , V_135 -> V_120 ) ;
V_135 -> V_138 = V_32 . V_82 ;
V_135 -> V_139 = V_32 . V_85 ;
return 0 ;
}
static int F_44 ( struct V_106 * V_107 ,
struct V_116 * V_117 ,
struct V_140 * V_123 )
{
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_31 * V_32 ;
V_32 = F_37 ( V_2 , V_117 , V_123 -> V_118 , V_123 -> V_120 ) ;
if ( ! V_32 )
return - V_133 ;
V_123 -> V_32 = * V_32 ;
return 0 ;
}
static int F_45 ( struct V_106 * V_107 ,
struct V_116 * V_117 ,
struct V_140 * V_123 )
{
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_31 * V_32 ;
V_32 = F_37 ( V_2 , V_117 , V_123 -> V_118 , V_123 -> V_120 ) ;
if ( ! V_32 )
return - V_133 ;
F_39 ( V_2 , V_117 , V_123 -> V_118 , & V_123 -> V_32 , V_123 -> V_120 ) ;
* V_32 = V_123 -> V_32 ;
if ( V_123 -> V_118 == V_36 ) {
V_32 = F_37 ( V_2 , V_117 ,
V_87 ,
V_123 -> V_120 ) ;
* V_32 = V_123 -> V_32 ;
F_39 ( V_2 , V_117 , V_87 ,
V_32 , V_123 -> V_120 ) ;
V_32 = F_37 ( V_2 , V_117 ,
V_126 ,
V_123 -> V_120 ) ;
* V_32 = V_123 -> V_32 ;
F_39 ( V_2 , V_117 , V_126 , V_32 ,
V_123 -> V_120 ) ;
}
return 0 ;
}
static int F_46 ( struct V_106 * V_107 ,
struct V_141 * V_142 ,
struct V_140 * V_143 ,
struct V_140 * V_144 )
{
if ( V_143 -> V_32 . V_82 != V_144 -> V_32 . V_82 ||
V_143 -> V_32 . V_85 != V_144 -> V_32 . V_85 )
return - V_145 ;
if ( V_143 -> V_32 . V_41 != V_144 -> V_32 . V_41 )
return - V_145 ;
return 0 ;
}
static int F_47 ( struct V_106 * V_107 ,
struct V_146 * V_147 )
{
struct V_140 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_118 = V_36 ;
V_32 . V_120 = V_147 ? V_121 : V_148 ;
V_32 . V_32 . V_41 = V_52 ;
V_32 . V_32 . V_82 = 4096 ;
V_32 . V_32 . V_85 = 4096 ;
F_45 ( V_107 , V_147 ? V_147 -> V_118 : NULL , & V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_149 * V_114 ,
const struct V_150 * V_151 ,
const struct V_150 * V_152 , T_2 V_153 )
{
struct V_106 * V_107 = F_49 ( V_114 ) ;
struct V_1 * V_2 = F_32 ( V_107 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_132 = V_151 -> V_132 ;
if ( F_50 ( V_152 -> V_114 ) )
V_132 |= 2 << 16 ;
switch ( V_132 ) {
case V_36 | 2 << 16 :
if ( ! ( V_153 & V_154 ) ) {
V_2 -> V_34 = V_155 ;
break;
}
if ( V_2 -> V_34 != V_155 )
return - V_156 ;
if ( V_152 -> V_114 == & V_4 -> V_157 . V_122 . V_114 )
V_2 -> V_34 = V_158 ;
else if ( V_152 -> V_114 == & V_4 -> V_159 . V_122 . V_114 )
V_2 -> V_34 = V_160 ;
break;
case V_87 :
if ( V_153 & V_154 ) {
if ( V_2 -> V_99 & ~ V_100 )
return - V_156 ;
V_2 -> V_99 |= V_100 ;
} else {
V_2 -> V_99 &= ~ V_100 ;
}
break;
case V_126 | 2 << 16 :
if ( V_153 & V_154 ) {
if ( V_2 -> V_99 & ~ V_161 )
return - V_156 ;
V_2 -> V_99 |= V_161 ;
} else {
V_2 -> V_99 &= ~ V_161 ;
}
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = & V_2 -> V_122 ;
struct V_150 * V_162 = V_2 -> V_162 ;
struct V_149 * V_163 = & V_107 -> V_114 ;
int V_108 ;
V_2 -> V_34 = V_155 ;
F_52 ( V_107 , & V_164 ) ;
V_107 -> V_165 = & V_166 ;
F_53 ( V_107 -> V_167 , L_3 , sizeof( V_107 -> V_167 ) ) ;
V_107 -> V_168 = F_54 ( 16 ) ;
F_55 ( V_107 , V_2 ) ;
V_107 -> V_153 |= V_169 ;
V_162 [ V_36 ] . V_153 = V_170 ;
V_162 [ V_87 ] . V_153 = V_171 ;
V_162 [ V_126 ] . V_153 = V_171 ;
V_163 -> V_172 = & V_173 ;
V_108 = F_56 ( V_163 , V_174 , V_162 ) ;
if ( V_108 < 0 )
return V_108 ;
F_47 ( V_107 , NULL ) ;
V_2 -> V_89 . type = V_175 ;
V_2 -> V_89 . V_172 = & V_176 ;
V_2 -> V_89 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_89 . V_177 = F_57 ( 4096 * 4096 ) * 3 ;
V_2 -> V_89 . V_178 = 32 ;
V_2 -> V_89 . V_179 = 1 ;
V_2 -> V_89 . V_180 = 0x1ffe0 ;
return F_58 ( & V_2 -> V_89 , L_4 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_122 ) ;
F_61 ( & V_2 -> V_89 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
int V_108 ;
V_108 = F_63 ( V_182 , & V_2 -> V_122 ) ;
if ( V_108 < 0 )
goto error;
V_108 = F_64 ( & V_2 -> V_89 , V_182 ) ;
if ( V_108 < 0 )
goto error;
return 0 ;
error:
F_59 ( V_2 ) ;
return V_108 ;
}
int F_65 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_109 = V_110 ;
F_66 ( & V_2 -> V_97 ) ;
return F_51 ( V_2 ) ;
}
int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
return F_68 ( & V_2 -> V_122 . V_114 ,
V_87 ,
& V_2 -> V_89 . V_102 . V_114 , 0 , 0 ) ;
}
void F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_70 ( & V_2 -> V_122 . V_114 ) ;
}
