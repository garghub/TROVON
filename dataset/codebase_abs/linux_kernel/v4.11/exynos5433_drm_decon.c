static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
V_5 = ( V_5 & V_4 ) | ( F_2 ( V_2 -> V_6 + V_3 ) & ~ V_4 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return - V_11 ;
if ( ! F_6 ( V_12 , & V_2 -> V_10 ) ) {
V_5 = V_13 ;
if ( V_2 -> V_14 & V_15 )
V_5 |= V_16 ;
else
V_5 |= V_17 | V_18 ;
F_3 ( V_5 , V_2 -> V_6 + V_19 ) ;
}
return 0 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_3 ( 0 , V_2 -> V_6 + V_19 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , bool V_20 )
{
T_1 V_21 , V_22 , V_23 , V_24 = 2 ;
V_21 = F_2 ( V_2 -> V_6 + V_25 ) ;
do {
V_23 = F_2 ( V_2 -> V_6 + V_26 ) ;
V_22 = V_21 ;
V_21 = F_2 ( V_2 -> V_6 + V_25 ) ;
} while ( V_21 != V_22 && -- V_24 );
if ( ! V_21 )
return 0 ;
switch ( V_23 & ( V_27 | V_28 ) ) {
case V_29 :
if ( ! ( V_2 -> V_14 & V_15 ) )
-- V_21 ;
break;
case V_30 :
-- V_21 ;
break;
case V_28 :
case V_31 :
if ( V_20 )
-- V_21 ;
break;
default:
break;
}
return V_21 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_14 & ( V_15 | V_32 ) ) )
return;
if ( ! ( V_2 -> V_14 & V_32 ) ) {
F_3 ( V_33 | V_34 |
V_35 | V_36 ,
V_2 -> V_6 + V_37 ) ;
return;
}
F_3 ( V_33 | V_34 | V_38
| V_39 , V_2 -> V_6 + V_37 ) ;
if ( F_11 ( V_2 -> V_40 , V_41 ,
V_42 , ~ 0 ) )
F_12 ( L_1 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_43 * V_44 = & V_8 -> V_45 . V_46 ;
bool V_47 = false ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( V_2 -> V_14 & V_48 ) {
V_44 -> V_49 = V_44 -> V_50 + 10 ;
V_44 -> V_51 = V_44 -> V_52 - 92 ;
V_44 -> V_53 = V_44 -> V_54 + 1 ;
V_44 -> V_55 = V_44 -> V_53 + 1 ;
if ( V_44 -> V_10 & V_56 )
V_47 = true ;
}
F_10 ( V_2 ) ;
V_5 = V_57 ;
if ( V_47 )
V_5 |= V_58 ;
if ( V_2 -> V_14 & V_15 ) {
V_5 |= V_59 ;
} else {
V_5 |= V_60 ;
}
F_3 ( V_5 , V_2 -> V_6 + V_61 ) ;
if ( V_47 )
V_5 = F_14 ( V_44 -> V_62 / 2 - 1 ) |
F_15 ( V_44 -> V_63 - 1 ) ;
else
V_5 = F_14 ( V_44 -> V_62 - 1 ) |
F_15 ( V_44 -> V_63 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_64 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) ) {
int V_65 = V_44 -> V_66 - V_44 -> V_55 ;
int V_67 = V_44 -> V_53 - V_44 -> V_54 ;
if ( V_47 )
V_65 = V_65 / 2 - 1 ;
V_5 = F_16 ( V_65 - 1 ) | F_17 ( V_67 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_68 ) ;
V_5 = F_18 (
V_44 -> V_55 - V_44 -> V_53 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_69 ) ;
V_5 = F_19 (
V_44 -> V_52 - V_44 -> V_51 - 1 ) |
F_20 (
V_44 -> V_49 - V_44 -> V_50 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_70 ) ;
V_5 = F_21 (
V_44 -> V_51 - V_44 -> V_49 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_71 ) ;
}
F_1 ( V_2 , V_72 , V_73 | V_74 , ~ 0 ) ;
F_1 ( V_2 , V_75 , V_76 , ~ 0 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_77 ,
struct V_78 * V_79 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_23 ( V_77 ) ) ;
V_5 &= ~ V_80 ;
switch ( V_79 -> V_81 -> V_81 ) {
case V_82 :
V_5 |= V_83 ;
V_5 |= V_84 ;
V_5 |= V_85 ;
break;
case V_86 :
V_5 |= V_87 ;
V_5 |= V_84 ;
V_5 |= V_85 ;
break;
case V_88 :
V_5 |= V_89 ;
V_5 |= V_90 ;
V_5 |= V_85 ;
break;
case V_91 :
V_5 |= V_92 ;
V_5 |= V_90 | V_93 | V_94 ;
V_5 |= V_85 ;
break;
default:
F_12 ( L_2 ) ;
return;
}
F_24 ( L_3 , V_79 -> V_81 -> V_95 [ 0 ] * 8 ) ;
if ( V_79 -> V_96 < V_97 ) {
V_5 &= ~ V_98 ;
V_5 |= V_99 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_23 ( V_77 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_77 ,
bool V_100 )
{
F_1 ( V_2 , V_101 , F_26 ( V_77 ) ,
V_100 ? ~ 0 : 0 ) ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_102 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_102 = V_2 -> V_103 ; V_102 < V_104 ; V_102 ++ )
F_25 ( V_2 , V_102 , true ) ;
}
static void F_28 ( struct V_7 * V_8 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 =
F_29 ( V_106 -> V_45 . V_108 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_78 * V_79 = V_108 -> V_45 . V_79 ;
unsigned int V_77 = V_106 -> V_109 ;
unsigned int V_110 = V_79 -> V_81 -> V_95 [ 0 ] ;
unsigned int V_111 = V_79 -> V_112 [ 0 ] ;
T_2 V_113 = F_30 ( V_79 , 0 ) ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( V_8 -> V_45 . V_46 . V_10 & V_56 ) {
V_5 = F_31 ( V_108 -> V_8 . V_114 ) |
F_32 ( V_108 -> V_8 . V_115 / 2 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_77 ) ) ;
V_5 = F_31 ( V_108 -> V_8 . V_114 + V_108 -> V_8 . V_116 - 1 ) |
F_32 ( ( V_108 -> V_8 . V_115 + V_108 -> V_8 . V_117 ) / 2 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_34 ( V_77 ) ) ;
} else {
V_5 = F_31 ( V_108 -> V_8 . V_114 ) | F_32 ( V_108 -> V_8 . V_115 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_77 ) ) ;
V_5 = F_31 ( V_108 -> V_8 . V_114 + V_108 -> V_8 . V_116 - 1 ) |
F_32 ( V_108 -> V_8 . V_115 + V_108 -> V_8 . V_117 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_34 ( V_77 ) ) ;
}
V_5 = F_35 ( 0x0 ) | F_36 ( 0x0 ) |
F_37 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_38 ( V_77 ) ) ;
V_5 = F_35 ( 0x0 ) | F_36 ( 0x0 ) |
F_37 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_39 ( V_77 ) ) ;
F_3 ( V_113 , V_2 -> V_6 + F_40 ( V_77 ) ) ;
V_5 = V_113 + V_111 * V_108 -> V_118 . V_117 ;
F_3 ( V_5 , V_2 -> V_6 + F_41 ( V_77 ) ) ;
if ( ! ( V_2 -> V_14 & V_48 ) )
V_5 = F_42 ( V_111 - V_108 -> V_8 . V_116 * V_110 , 27 , 14 )
| F_42 ( V_108 -> V_8 . V_116 * V_110 , 13 , 0 ) ;
else
V_5 = F_42 ( V_111 - V_108 -> V_8 . V_116 * V_110 , 29 , 15 )
| F_42 ( V_108 -> V_8 . V_116 * V_110 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_43 ( V_77 ) ) ;
F_22 ( V_2 , V_77 , V_79 ) ;
F_1 ( V_2 , F_23 ( V_77 ) , V_119 , ~ 0 ) ;
F_44 ( V_120 , & V_2 -> V_10 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_77 = V_106 -> V_109 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_1 ( V_2 , F_23 ( V_77 ) , V_119 , 0 ) ;
F_44 ( V_120 , & V_2 -> V_10 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_10 ;
int V_102 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_47 ( & V_2 -> V_121 , V_10 ) ;
for ( V_102 = V_2 -> V_103 ; V_102 < V_104 ; V_102 ++ )
F_25 ( V_2 , V_102 , false ) ;
if ( F_8 ( V_120 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_75 , V_76 , ~ 0 ) ;
if ( V_2 -> V_14 & V_15 )
F_44 ( V_122 , & V_2 -> V_10 ) ;
V_2 -> V_123 = F_9 ( V_2 , true ) ;
F_48 ( V_8 ) ;
F_49 ( & V_2 -> V_121 , V_10 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned int V_124 ;
unsigned long V_10 ;
F_3 ( 0 , V_2 -> V_6 + V_72 ) ;
for ( V_124 = 2000 ; V_124 ; -- V_124 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_72 ) & V_125 )
break;
F_51 ( 10 ) ;
}
F_3 ( V_126 , V_2 -> V_6 + V_72 ) ;
for ( V_124 = 2000 ; V_124 ; -- V_124 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_72 ) & V_126 )
break;
F_51 ( 10 ) ;
}
F_52 ( V_124 == 0 , L_4 ) ;
F_47 ( & V_2 -> V_121 , V_10 ) ;
V_2 -> V_123 = 0 ;
F_49 ( & V_2 -> V_121 , V_10 ) ;
if ( ! ( V_2 -> V_14 & V_48 ) )
return;
F_3 ( V_127 | V_128 , V_2 -> V_6 + V_72 ) ;
F_1 ( V_2 , V_129 ,
V_130 | V_131 , ~ 0 ) ;
F_3 ( V_132 , V_2 -> V_6 + V_26 ) ;
F_3 ( V_133 | V_134 | V_135 ,
V_2 -> V_6 + V_136 ) ;
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_8 ( V_9 , & V_2 -> V_10 ) )
return;
F_54 ( V_2 -> V_137 ) ;
F_55 ( V_8 , true ) ;
F_44 ( V_138 , & V_2 -> V_10 ) ;
F_50 ( V_2 ) ;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_4 ( V_2 -> V_8 ) ;
F_13 ( V_2 -> V_8 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_102 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_102 = V_2 -> V_103 ; V_102 < V_104 ; V_102 ++ )
F_45 ( V_8 , & V_2 -> V_139 [ V_102 ] ) ;
F_50 ( V_2 ) ;
F_57 ( V_138 , & V_2 -> V_10 ) ;
F_55 ( V_8 , false ) ;
F_58 ( V_2 -> V_137 ) ;
F_44 ( V_9 , & V_2 -> V_10 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_5 ( V_138 , & V_2 -> V_10 ) ||
( V_2 -> V_14 & V_32 ) )
return;
if ( F_8 ( V_122 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_37 , V_140 , ~ 0 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_77 , V_102 , V_141 ;
F_24 ( L_5 , __FILE__ ) ;
for ( V_102 = 0 ; V_102 < F_61 ( V_142 ) ; V_102 ++ ) {
V_141 = F_62 ( V_2 -> V_143 [ V_102 ] ) ;
if ( V_141 < 0 )
goto V_144;
}
for ( V_77 = 0 ; V_77 < V_104 ; V_77 ++ ) {
F_25 ( V_2 , V_77 , true ) ;
F_1 ( V_2 , F_23 ( V_77 ) , V_119 , 0 ) ;
F_25 ( V_2 , V_77 , false ) ;
}
F_1 ( V_2 , V_75 , V_76 , ~ 0 ) ;
F_63 ( 50 ) ;
V_144:
while ( -- V_102 >= 0 )
F_64 ( V_2 -> V_143 [ V_102 ] ) ;
}
static int F_65 ( struct V_145 * V_137 , struct V_145 * V_146 , void * V_147 )
{
struct V_1 * V_2 = F_66 ( V_137 ) ;
struct V_148 * V_149 = V_147 ;
struct V_150 * V_151 = V_149 -> V_152 ;
struct V_105 * V_153 ;
enum V_154 V_14 ;
unsigned int V_77 ;
int V_141 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_155 = V_151 -> V_155 ++ ;
for ( V_77 = V_2 -> V_103 ; V_77 < V_104 ; V_77 ++ ) {
int V_156 = ( V_77 == V_2 -> V_103 ) ? 0 : V_77 ;
V_2 -> V_157 [ V_77 ] . V_158 = V_159 ;
V_2 -> V_157 [ V_77 ] . V_160 = F_61 ( V_159 ) ;
V_2 -> V_157 [ V_77 ] . V_161 = V_77 ;
V_2 -> V_157 [ V_77 ] . type = V_162 [ V_156 ] ;
V_141 = F_67 ( V_149 , & V_2 -> V_139 [ V_77 ] , V_77 ,
1 << V_2 -> V_155 , & V_2 -> V_157 [ V_77 ] ) ;
if ( V_141 )
return V_141 ;
}
V_153 = & V_2 -> V_139 [ V_2 -> V_103 ] ;
V_14 = ( V_2 -> V_14 & V_48 ) ? V_163
: V_164 ;
V_2 -> V_8 = F_68 ( V_149 , & V_153 -> V_45 ,
V_2 -> V_155 , V_14 ,
& V_165 , V_2 ) ;
if ( F_69 ( V_2 -> V_8 ) ) {
V_141 = F_70 ( V_2 -> V_8 ) ;
goto V_144;
}
F_60 ( V_2 -> V_8 ) ;
V_141 = F_71 ( V_149 , V_137 ) ;
if ( V_141 )
goto V_144;
return V_141 ;
V_144:
V_151 -> V_155 -- ;
return V_141 ;
}
static void F_72 ( struct V_145 * V_137 , struct V_145 * V_146 , void * V_147 )
{
struct V_1 * V_2 = F_66 ( V_137 ) ;
F_56 ( V_2 -> V_8 ) ;
F_73 ( V_2 -> V_149 , V_2 -> V_137 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_75 ( & V_2 -> V_121 ) ;
V_21 = F_9 ( V_2 , true ) ;
if ( V_21 != V_2 -> V_123 ) {
if ( ( V_166 ) ( V_21 - V_2 -> V_123 ) > 0 )
F_76 ( & V_2 -> V_8 -> V_45 ) ;
V_2 -> V_123 = V_21 ;
}
F_77 ( & V_2 -> V_121 ) ;
}
static T_3 F_78 ( int V_167 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
T_1 V_5 ;
if ( ! F_5 ( V_138 , & V_2 -> V_10 ) )
goto V_169;
V_5 = F_2 ( V_2 -> V_6 + V_170 ) ;
V_5 &= V_171 | V_172 ;
if ( V_5 ) {
F_3 ( V_5 , V_2 -> V_6 + V_170 ) ;
if ( V_2 -> V_14 & V_48 ) {
V_5 = F_2 ( V_2 -> V_6 + V_61 ) ;
V_5 &= V_58 | V_173 ;
if ( V_5 ==
( V_58 | V_173 ) )
return V_174 ;
}
F_74 ( V_2 ) ;
}
V_169:
return V_174 ;
}
static int F_79 ( struct V_145 * V_137 )
{
struct V_1 * V_2 = F_66 ( V_137 ) ;
int V_102 = F_61 ( V_142 ) ;
while ( -- V_102 >= 0 )
F_64 ( V_2 -> V_143 [ V_102 ] ) ;
return 0 ;
}
static int F_80 ( struct V_145 * V_137 )
{
struct V_1 * V_2 = F_66 ( V_137 ) ;
int V_102 , V_141 ;
for ( V_102 = 0 ; V_102 < F_61 ( V_142 ) ; V_102 ++ ) {
V_141 = F_62 ( V_2 -> V_143 [ V_102 ] ) ;
if ( V_141 < 0 )
goto V_144;
}
return 0 ;
V_144:
while ( -- V_102 >= 0 )
F_64 ( V_2 -> V_143 [ V_102 ] ) ;
return V_141 ;
}
static int F_81 ( struct V_175 * V_176 )
{
struct V_145 * V_137 = & V_176 -> V_137 ;
struct V_1 * V_2 ;
struct V_177 * V_178 ;
int V_141 ;
int V_102 ;
V_2 = F_82 ( V_137 , sizeof( * V_2 ) , V_179 ) ;
if ( ! V_2 )
return - V_180 ;
F_83 ( V_9 , & V_2 -> V_10 ) ;
V_2 -> V_137 = V_137 ;
V_2 -> V_14 = ( unsigned long ) F_84 ( V_137 ) ;
F_85 ( & V_2 -> V_121 ) ;
if ( V_2 -> V_14 & V_48 ) {
V_2 -> V_103 = 1 ;
} else if ( F_86 ( V_137 -> V_181 , L_6 ) ) {
V_2 -> V_14 |= V_15 ;
}
if ( V_2 -> V_14 & V_32 ) {
V_2 -> V_40 = F_87 ( V_137 -> V_181 ,
L_7 ) ;
if ( F_69 ( V_2 -> V_40 ) ) {
F_88 ( V_137 , L_8 ) ;
return F_70 ( V_2 -> V_40 ) ;
}
}
for ( V_102 = 0 ; V_102 < F_61 ( V_142 ) ; V_102 ++ ) {
struct V_182 * V_182 ;
V_182 = F_89 ( V_2 -> V_137 , V_142 [ V_102 ] ) ;
if ( F_69 ( V_182 ) )
return F_70 ( V_182 ) ;
V_2 -> V_143 [ V_102 ] = V_182 ;
}
V_178 = F_90 ( V_176 , V_183 , 0 ) ;
if ( ! V_178 ) {
F_88 ( V_137 , L_9 ) ;
return - V_184 ;
}
V_2 -> V_6 = F_91 ( V_137 , V_178 ) ;
if ( F_69 ( V_2 -> V_6 ) ) {
F_88 ( V_137 , L_10 ) ;
return F_70 ( V_2 -> V_6 ) ;
}
V_178 = F_92 ( V_176 , V_185 ,
( V_2 -> V_14 & V_15 ) ? L_11 : L_12 ) ;
if ( ! V_178 ) {
F_88 ( V_137 , L_13 ) ;
return - V_184 ;
}
V_141 = F_93 ( V_137 , V_178 -> V_186 , F_78 , 0 ,
L_14 , V_2 ) ;
if ( V_141 < 0 ) {
F_88 ( V_137 , L_15 ) ;
return V_141 ;
}
F_94 ( V_176 , V_2 ) ;
F_95 ( V_137 ) ;
V_141 = F_96 ( V_137 , & V_187 ) ;
if ( V_141 )
goto V_188;
return 0 ;
V_188:
F_97 ( V_137 ) ;
return V_141 ;
}
static int F_98 ( struct V_175 * V_176 )
{
F_97 ( & V_176 -> V_137 ) ;
F_99 ( & V_176 -> V_137 , & V_187 ) ;
return 0 ;
}
