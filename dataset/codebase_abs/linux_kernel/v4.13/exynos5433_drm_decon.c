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
V_5 = V_9 ;
if ( V_2 -> V_10 & V_11 )
V_5 |= V_12 ;
else
V_5 |= V_13 | V_14 ;
F_3 ( V_5 , V_2 -> V_6 + V_15 ) ;
F_5 ( V_2 -> V_16 ) ;
if ( ! ( V_2 -> V_10 & V_17 ) )
F_5 ( V_2 -> V_18 ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! ( V_2 -> V_10 & V_17 ) )
F_7 ( V_2 -> V_18 ) ;
F_7 ( V_2 -> V_16 ) ;
F_3 ( 0 , V_2 -> V_6 + V_15 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , bool V_19 )
{
T_1 V_20 , V_21 , V_22 , V_23 = 2 ;
V_20 = F_2 ( V_2 -> V_6 + V_24 ) ;
do {
V_22 = F_2 ( V_2 -> V_6 + V_25 ) ;
V_21 = V_20 ;
V_20 = F_2 ( V_2 -> V_6 + V_24 ) ;
} while ( V_20 != V_21 && -- V_23 );
if ( ! V_20 )
return 0 ;
switch ( V_22 & ( V_26 | V_27 ) ) {
case V_28 :
if ( ! ( V_2 -> V_10 & V_11 ) )
-- V_20 ;
break;
case V_29 :
-- V_20 ;
break;
case V_27 :
case V_30 :
if ( V_19 )
-- V_20 ;
break;
default:
break;
}
return V_20 ;
}
static T_1 F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
return F_8 ( V_2 , false ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_10 & ( V_11 | V_17 ) ) )
return;
if ( ! ( V_2 -> V_10 & V_17 ) ) {
F_3 ( V_31 | V_32 |
V_33 | V_34 ,
V_2 -> V_6 + V_35 ) ;
return;
}
F_3 ( V_31 | V_32 | V_36
| V_37 , V_2 -> V_6 + V_35 ) ;
if ( F_11 ( V_2 -> V_38 , V_39 ,
V_40 , ~ 0 ) )
F_12 ( L_1 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = & V_8 -> V_43 . V_44 ;
bool V_45 = false ;
T_1 V_5 ;
if ( V_2 -> V_10 & V_46 ) {
V_42 -> V_47 = V_42 -> V_48 + 10 ;
V_42 -> V_49 = V_42 -> V_50 - 92 ;
V_42 -> V_51 = V_42 -> V_52 + 1 ;
V_42 -> V_53 = V_42 -> V_51 + 1 ;
if ( V_42 -> V_54 & V_55 )
V_45 = true ;
}
F_10 ( V_2 ) ;
V_5 = V_56 ;
if ( V_45 )
V_5 |= V_57 ;
if ( V_2 -> V_10 & V_11 ) {
V_5 |= V_58 ;
} else {
V_5 |= V_59 ;
}
F_3 ( V_5 , V_2 -> V_6 + V_60 ) ;
if ( V_45 )
V_5 = F_14 ( V_42 -> V_61 / 2 - 1 ) |
F_15 ( V_42 -> V_62 - 1 ) ;
else
V_5 = F_14 ( V_42 -> V_61 - 1 ) |
F_15 ( V_42 -> V_62 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_63 ) ;
if ( ! ( V_2 -> V_10 & V_11 ) ) {
int V_64 = V_42 -> V_65 - V_42 -> V_53 ;
int V_66 = V_42 -> V_51 - V_42 -> V_52 ;
if ( V_45 )
V_64 = V_64 / 2 - 1 ;
V_5 = F_16 ( V_64 - 1 ) | F_17 ( V_66 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_67 ) ;
V_5 = F_18 (
V_42 -> V_53 - V_42 -> V_51 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_68 ) ;
V_5 = F_19 (
V_42 -> V_50 - V_42 -> V_49 - 1 ) |
F_20 (
V_42 -> V_47 - V_42 -> V_48 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_69 ) ;
V_5 = F_21 (
V_42 -> V_49 - V_42 -> V_47 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_70 ) ;
}
F_1 ( V_2 , V_71 , V_72 | V_73 , ~ 0 ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_76 ,
struct V_77 * V_78 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_23 ( V_76 ) ) ;
V_5 &= ~ V_79 ;
switch ( V_78 -> V_80 -> V_80 ) {
case V_81 :
V_5 |= V_82 ;
V_5 |= V_83 ;
V_5 |= V_84 ;
break;
case V_85 :
V_5 |= V_86 ;
V_5 |= V_83 ;
V_5 |= V_84 ;
break;
case V_87 :
V_5 |= V_88 ;
V_5 |= V_89 ;
V_5 |= V_84 ;
break;
case V_90 :
V_5 |= V_91 ;
V_5 |= V_89 | V_92 | V_93 ;
V_5 |= V_84 ;
break;
default:
F_12 ( L_2 ) ;
return;
}
F_24 ( L_3 , V_78 -> V_80 -> V_94 [ 0 ] * 8 ) ;
if ( V_78 -> V_95 < V_96 ) {
V_5 &= ~ V_97 ;
V_5 |= V_98 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_23 ( V_76 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_99 )
{
F_1 ( V_2 , V_100 , V_101 ,
V_99 ? ~ 0 : 0 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_25 ( V_2 , true ) ;
}
static void F_27 ( struct V_7 * V_8 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 =
F_28 ( V_103 -> V_43 . V_105 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_77 * V_78 = V_105 -> V_43 . V_78 ;
unsigned int V_76 = V_103 -> V_106 ;
unsigned int V_107 = V_78 -> V_80 -> V_94 [ 0 ] ;
unsigned int V_108 = V_78 -> V_109 [ 0 ] ;
T_2 V_110 = F_29 ( V_78 , 0 ) ;
T_1 V_5 ;
if ( V_8 -> V_43 . V_44 . V_54 & V_55 ) {
V_5 = F_30 ( V_105 -> V_8 . V_111 ) |
F_31 ( V_105 -> V_8 . V_112 / 2 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_76 ) ) ;
V_5 = F_30 ( V_105 -> V_8 . V_111 + V_105 -> V_8 . V_113 - 1 ) |
F_31 ( ( V_105 -> V_8 . V_112 + V_105 -> V_8 . V_114 ) / 2 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_76 ) ) ;
} else {
V_5 = F_30 ( V_105 -> V_8 . V_111 ) | F_31 ( V_105 -> V_8 . V_112 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_76 ) ) ;
V_5 = F_30 ( V_105 -> V_8 . V_111 + V_105 -> V_8 . V_113 - 1 ) |
F_31 ( V_105 -> V_8 . V_112 + V_105 -> V_8 . V_114 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_76 ) ) ;
}
V_5 = F_34 ( 0x0 ) | F_35 ( 0x0 ) |
F_36 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_76 ) ) ;
V_5 = F_34 ( 0x0 ) | F_35 ( 0x0 ) |
F_36 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_38 ( V_76 ) ) ;
F_3 ( V_110 , V_2 -> V_6 + F_39 ( V_76 ) ) ;
V_5 = V_110 + V_108 * V_105 -> V_115 . V_114 ;
F_3 ( V_5 , V_2 -> V_6 + F_40 ( V_76 ) ) ;
if ( ! ( V_2 -> V_10 & V_46 ) )
V_5 = F_41 ( V_108 - V_105 -> V_8 . V_113 * V_107 , 27 , 14 )
| F_41 ( V_105 -> V_8 . V_113 * V_107 , 13 , 0 ) ;
else
V_5 = F_41 ( V_108 - V_105 -> V_8 . V_113 * V_107 , 29 , 15 )
| F_41 ( V_105 -> V_8 . V_113 * V_107 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_42 ( V_76 ) ) ;
F_22 ( V_2 , V_76 , V_78 ) ;
F_1 ( V_2 , F_23 ( V_76 ) , V_116 , ~ 0 ) ;
}
static void F_43 ( struct V_7 * V_8 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_76 = V_103 -> V_106 ;
F_1 ( V_2 , F_23 ( V_76 ) , V_116 , 0 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_54 ;
F_45 ( & V_2 -> V_117 , V_54 ) ;
F_25 ( V_2 , false ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
V_2 -> V_118 = F_8 ( V_2 , true ) ;
F_46 ( V_8 ) ;
F_47 ( & V_2 -> V_117 , V_54 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
unsigned long V_54 ;
F_3 ( 0 , V_2 -> V_6 + V_71 ) ;
for ( V_119 = 2000 ; V_119 ; -- V_119 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_71 ) & V_120 )
break;
F_49 ( 10 ) ;
}
F_3 ( V_121 , V_2 -> V_6 + V_71 ) ;
for ( V_119 = 2000 ; V_119 ; -- V_119 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_71 ) & V_121 )
break;
F_49 ( 10 ) ;
}
F_50 ( V_119 == 0 , L_4 ) ;
F_45 ( & V_2 -> V_117 , V_54 ) ;
V_2 -> V_118 = 0 ;
F_47 ( & V_2 -> V_117 , V_54 ) ;
if ( ! ( V_2 -> V_10 & V_46 ) )
return;
F_3 ( V_122 | V_123 , V_2 -> V_6 + V_71 ) ;
F_1 ( V_2 , V_124 ,
V_125 | V_126 , ~ 0 ) ;
F_3 ( V_127 , V_2 -> V_6 + V_25 ) ;
F_3 ( V_128 | V_129 | V_130 ,
V_2 -> V_6 + V_131 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_52 ( V_2 -> V_132 ) ;
F_53 ( V_8 , true ) ;
F_48 ( V_2 ) ;
F_13 ( V_2 -> V_8 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_133 ;
if ( ! ( V_2 -> V_10 & V_17 ) )
F_55 ( V_2 -> V_18 ) ;
F_55 ( V_2 -> V_16 ) ;
for ( V_133 = V_2 -> V_134 ; V_133 < V_135 ; V_133 ++ )
F_43 ( V_8 , & V_2 -> V_136 [ V_133 ] ) ;
F_48 ( V_2 ) ;
F_53 ( V_8 , false ) ;
F_56 ( V_2 -> V_132 ) ;
}
static T_3 F_57 ( int V_16 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
F_1 ( V_2 , V_35 , V_138 , ~ 0 ) ;
return V_139 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_76 , V_133 , V_140 ;
F_24 ( L_5 , __FILE__ ) ;
for ( V_133 = 0 ; V_133 < F_59 ( V_141 ) ; V_133 ++ ) {
V_140 = F_60 ( V_2 -> V_142 [ V_133 ] ) ;
if ( V_140 < 0 )
goto V_143;
}
F_25 ( V_2 , true ) ;
for ( V_76 = 0 ; V_76 < V_135 ; V_76 ++ )
F_1 ( V_2 , F_23 ( V_76 ) , V_116 , 0 ) ;
F_25 ( V_2 , false ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
F_61 ( 50 ) ;
V_143:
while ( -- V_133 >= 0 )
F_62 ( V_2 -> V_142 [ V_133 ] ) ;
}
static int F_63 ( struct V_144 * V_132 , struct V_144 * V_145 , void * V_146 )
{
struct V_1 * V_2 = F_64 ( V_132 ) ;
struct V_147 * V_148 = V_146 ;
struct V_102 * V_149 ;
enum V_150 V_10 ;
unsigned int V_76 ;
int V_140 ;
V_2 -> V_148 = V_148 ;
V_148 -> V_151 = 0xffffffff ;
for ( V_76 = V_2 -> V_134 ; V_76 < V_135 ; V_76 ++ ) {
int V_152 = ( V_76 == V_2 -> V_134 ) ? 0 : V_76 ;
V_2 -> V_153 [ V_76 ] . V_154 = V_155 ;
V_2 -> V_153 [ V_76 ] . V_156 = F_59 ( V_155 ) ;
V_2 -> V_153 [ V_76 ] . V_157 = V_76 ;
V_2 -> V_153 [ V_76 ] . type = V_158 [ V_152 ] ;
V_140 = F_65 ( V_148 , & V_2 -> V_136 [ V_76 ] , V_76 ,
& V_2 -> V_153 [ V_76 ] ) ;
if ( V_140 )
return V_140 ;
}
V_149 = & V_2 -> V_136 [ V_2 -> V_134 ] ;
V_10 = ( V_2 -> V_10 & V_46 ) ? V_159
: V_160 ;
V_2 -> V_8 = F_66 ( V_148 , & V_149 -> V_43 ,
V_10 , & V_161 , V_2 ) ;
if ( F_67 ( V_2 -> V_8 ) )
return F_68 ( V_2 -> V_8 ) ;
F_58 ( V_2 -> V_8 ) ;
return F_69 ( V_148 , V_132 ) ;
}
static void F_70 ( struct V_144 * V_132 , struct V_144 * V_145 , void * V_146 )
{
struct V_1 * V_2 = F_64 ( V_132 ) ;
F_54 ( V_2 -> V_8 ) ;
F_71 ( V_2 -> V_148 , V_2 -> V_132 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_73 ( & V_2 -> V_117 ) ;
V_20 = F_8 ( V_2 , true ) ;
if ( V_20 != V_2 -> V_118 ) {
if ( ( V_162 ) ( V_20 - V_2 -> V_118 ) > 0 )
F_74 ( & V_2 -> V_8 -> V_43 ) ;
V_2 -> V_118 = V_20 ;
}
F_75 ( & V_2 -> V_117 ) ;
}
static T_3 F_76 ( int V_16 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_163 ) ;
V_5 &= V_164 | V_165 ;
if ( V_5 ) {
F_3 ( V_5 , V_2 -> V_6 + V_163 ) ;
if ( V_2 -> V_10 & V_46 ) {
V_5 = F_2 ( V_2 -> V_6 + V_60 ) ;
V_5 &= V_57 | V_166 ;
if ( V_5 ==
( V_57 | V_166 ) )
return V_139 ;
}
F_72 ( V_2 ) ;
}
return V_139 ;
}
static int F_77 ( struct V_144 * V_132 )
{
struct V_1 * V_2 = F_64 ( V_132 ) ;
int V_133 = F_59 ( V_141 ) ;
while ( -- V_133 >= 0 )
F_62 ( V_2 -> V_142 [ V_133 ] ) ;
return 0 ;
}
static int F_78 ( struct V_144 * V_132 )
{
struct V_1 * V_2 = F_64 ( V_132 ) ;
int V_133 , V_140 ;
for ( V_133 = 0 ; V_133 < F_59 ( V_141 ) ; V_133 ++ ) {
V_140 = F_60 ( V_2 -> V_142 [ V_133 ] ) ;
if ( V_140 < 0 )
goto V_143;
}
return 0 ;
V_143:
while ( -- V_133 >= 0 )
F_62 ( V_2 -> V_142 [ V_133 ] ) ;
return V_140 ;
}
static int F_79 ( struct V_1 * V_2 , const char * V_167 ,
T_4 V_168 , unsigned long int V_54 , bool V_169 )
{
struct V_170 * V_171 = F_80 ( V_2 -> V_132 ) ;
int V_140 , V_16 = F_81 ( V_171 , V_167 ) ;
if ( V_16 < 0 ) {
if ( V_16 == - V_172 )
return V_16 ;
if ( V_169 )
F_82 ( V_2 -> V_132 , L_6 , V_167 ) ;
else
V_16 = 0 ;
return V_16 ;
}
F_83 ( V_16 , V_173 ) ;
V_140 = F_84 ( V_2 -> V_132 , V_16 , V_168 , V_54 , L_7 , V_2 ) ;
if ( V_140 < 0 ) {
F_82 ( V_2 -> V_132 , L_8 , V_167 ) ;
return V_140 ;
}
return V_16 ;
}
static int F_85 ( struct V_170 * V_171 )
{
struct V_144 * V_132 = & V_171 -> V_132 ;
struct V_1 * V_2 ;
struct V_174 * V_175 ;
int V_140 ;
int V_133 ;
V_2 = F_86 ( V_132 , sizeof( * V_2 ) , V_176 ) ;
if ( ! V_2 )
return - V_177 ;
V_2 -> V_132 = V_132 ;
V_2 -> V_10 = ( unsigned long ) F_87 ( V_132 ) ;
F_88 ( & V_2 -> V_117 ) ;
if ( V_2 -> V_10 & V_46 ) {
V_2 -> V_134 = 1 ;
} else if ( F_89 ( V_132 -> V_178 , L_9 ) ) {
V_2 -> V_10 |= V_11 ;
}
for ( V_133 = 0 ; V_133 < F_59 ( V_141 ) ; V_133 ++ ) {
struct V_179 * V_179 ;
V_179 = F_90 ( V_2 -> V_132 , V_141 [ V_133 ] ) ;
if ( F_67 ( V_179 ) )
return F_68 ( V_179 ) ;
V_2 -> V_142 [ V_133 ] = V_179 ;
}
V_175 = F_91 ( V_171 , V_180 , 0 ) ;
if ( ! V_175 ) {
F_82 ( V_132 , L_10 ) ;
return - V_181 ;
}
V_2 -> V_6 = F_92 ( V_132 , V_175 ) ;
if ( F_67 ( V_2 -> V_6 ) ) {
F_82 ( V_132 , L_11 ) ;
return F_68 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_10 & V_11 ) {
V_140 = F_79 ( V_2 , L_12 , F_76 , 0 , true ) ;
if ( V_140 < 0 )
return V_140 ;
V_2 -> V_16 = V_140 ;
V_140 = F_79 ( V_2 , L_13 , F_57 ,
V_182 , false ) ;
if ( V_140 < 0 )
return V_140 ;
if ( V_140 ) {
V_2 -> V_18 = V_140 ;
V_2 -> V_10 &= ~ V_17 ;
}
} else {
V_140 = F_79 ( V_2 , L_14 , F_76 , 0 , true ) ;
if ( V_140 < 0 )
return V_140 ;
V_2 -> V_16 = V_140 ;
}
if ( V_2 -> V_10 & V_17 ) {
V_2 -> V_38 = F_93 ( V_132 -> V_178 ,
L_15 ) ;
if ( F_67 ( V_2 -> V_38 ) ) {
F_82 ( V_132 , L_16 ) ;
return F_68 ( V_2 -> V_38 ) ;
}
}
F_94 ( V_171 , V_2 ) ;
F_95 ( V_132 ) ;
V_140 = F_96 ( V_132 , & V_183 ) ;
if ( V_140 )
goto V_184;
return 0 ;
V_184:
F_97 ( V_132 ) ;
return V_140 ;
}
static int F_98 ( struct V_170 * V_171 )
{
F_97 ( & V_171 -> V_132 ) ;
F_99 ( & V_171 -> V_132 , & V_183 ) ;
return 0 ;
}
