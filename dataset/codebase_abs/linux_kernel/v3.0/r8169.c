static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_4 )
{
void T_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_2 ( V_8 , ( ( T_1 ) V_3 & 0x0f ) << 12 | ( V_4 & 0x0fff ) ) ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
F_3 ( 100 ) ;
if ( F_4 ( V_8 ) & V_9 )
break;
}
return F_4 ( V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_4 , T_1 V_11 )
{
void T_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_2 ( V_10 , V_11 ) ;
F_2 ( V_8 , V_9 | ( ( T_1 ) V_3 & 0x0f ) << 12 | ( V_4 & 0x0fff ) ) ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
F_3 ( 100 ) ;
if ( ( F_4 ( V_8 ) & V_9 ) == 0 )
break;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 V_12 )
{
void T_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_7 ( V_13 , V_12 ) ;
F_2 ( V_14 , 0x800010e8 ) ;
F_8 ( 2 ) ;
for ( V_7 = 0 ; V_7 < 5 ; V_7 ++ ) {
F_3 ( 100 ) ;
if ( ! ( F_4 ( V_14 ) & V_15 ) )
break;
}
F_5 ( V_2 , 0x1 , 0x30 , 0x00000001 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
return ( V_2 -> V_16 == V_17 ) ? 0xb8 : 0x10 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_3 V_4 ;
int V_7 ;
F_6 ( V_2 , V_18 ) ;
V_4 = F_9 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ ) {
F_8 ( 10 ) ;
if ( F_1 ( V_2 , 0x0f , V_4 ) & 0x00000800 )
break;
}
}
static void F_11 ( struct V_1 * V_2 )
{
T_3 V_4 ;
int V_7 ;
F_6 ( V_2 , V_19 ) ;
V_4 = F_9 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ ) {
F_8 ( 10 ) ;
if ( ( F_1 ( V_2 , 0x0f , V_4 ) & 0x00000800 ) == 0 )
break;
}
}
static int F_12 ( struct V_1 * V_2 )
{
T_3 V_4 = F_9 ( V_2 ) ;
return ( F_1 ( V_2 , 0x0f , V_4 ) & 0x00008000 ) ? 1 : 0 ;
}
static void F_13 ( void T_4 * V_5 , int V_20 , int V_21 )
{
int V_7 ;
F_2 ( V_22 , 0x80000000 | ( V_20 & 0x1f ) << 16 | ( V_21 & 0xffff ) ) ;
for ( V_7 = 20 ; V_7 > 0 ; V_7 -- ) {
if ( ! ( F_4 ( V_22 ) & 0x80000000 ) )
break;
F_3 ( 25 ) ;
}
F_3 ( 20 ) ;
}
static int F_14 ( void T_4 * V_5 , int V_20 )
{
int V_7 , V_21 = - 1 ;
F_2 ( V_22 , 0x0 | ( V_20 & 0x1f ) << 16 ) ;
for ( V_7 = 20 ; V_7 > 0 ; V_7 -- ) {
if ( F_4 ( V_22 ) & 0x80000000 ) {
V_21 = F_4 ( V_22 ) & 0xffff ;
break;
}
F_3 ( 25 ) ;
}
F_3 ( 20 ) ;
return V_21 ;
}
static void F_15 ( void T_4 * V_5 , int V_20 , T_1 V_11 )
{
int V_7 ;
F_2 ( V_10 , V_11 |
( ( V_20 & V_23 ) << V_24 ) ) ;
F_2 ( V_8 , V_25 ) ;
F_2 ( V_26 , 0 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
F_16 ( 1 ) ;
if ( ! ( F_4 ( V_8 ) & V_9 ) )
break;
}
}
static void F_17 ( void T_4 * V_5 , int V_20 , int V_21 )
{
F_15 ( V_5 , V_20 , V_27 |
( V_21 & V_28 ) ) ;
}
static int F_18 ( void T_4 * V_5 , int V_20 )
{
int V_7 ;
F_15 ( V_5 , V_20 , V_29 ) ;
F_16 ( 1 ) ;
F_2 ( V_8 , V_30 ) ;
F_2 ( V_26 , 0 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
F_16 ( 1 ) ;
if ( F_4 ( V_8 ) & V_9 )
break;
}
return F_4 ( V_10 ) & V_28 ;
}
static void F_19 ( void T_4 * V_5 )
{
F_2 ( 0xd0 , F_4 ( 0xd0 ) & ~ V_31 ) ;
}
static void F_20 ( void T_4 * V_5 )
{
F_2 ( 0xd0 , F_4 ( 0xd0 ) | V_31 ) ;
}
static void F_21 ( void T_4 * V_5 , int V_20 , int V_21 )
{
F_19 ( V_5 ) ;
F_13 ( V_5 , V_20 , V_21 ) ;
F_20 ( V_5 ) ;
}
static int F_22 ( void T_4 * V_5 , int V_20 )
{
int V_21 ;
F_19 ( V_5 ) ;
V_21 = F_14 ( V_5 , V_20 ) ;
F_20 ( V_5 ) ;
return V_21 ;
}
static void F_23 ( struct V_1 * V_2 , int V_32 , T_1 V_33 )
{
V_2 -> V_34 . V_35 ( V_2 -> V_6 , V_32 , V_33 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_32 )
{
return V_2 -> V_34 . V_36 ( V_2 -> V_6 , V_32 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
F_23 ( V_2 , V_20 , F_24 ( V_2 , V_20 ) | V_21 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_20 , int V_37 , int V_38 )
{
int V_33 ;
V_33 = F_24 ( V_2 , V_20 ) ;
F_23 ( V_2 , V_20 , ( V_33 | V_37 ) & ~ V_38 ) ;
}
static void F_27 ( struct V_39 * V_40 , int V_41 , int V_32 ,
int V_33 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_23 ( V_2 , V_32 , V_33 ) ;
}
static int F_29 ( struct V_39 * V_40 , int V_41 , int V_32 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
return F_24 ( V_2 , V_32 ) ;
}
static void F_30 ( void T_4 * V_5 , int V_20 , int V_21 )
{
unsigned int V_7 ;
F_2 ( V_42 , V_43 | ( V_21 & V_44 ) |
( V_20 & V_45 ) << V_46 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ! ( F_4 ( V_42 ) & V_47 ) )
break;
F_3 ( 10 ) ;
}
}
static T_3 F_31 ( void T_4 * V_5 , int V_20 )
{
T_3 V_21 = 0xffff ;
unsigned int V_7 ;
F_2 ( V_42 , ( V_20 & V_45 ) << V_46 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( F_4 ( V_42 ) & V_47 ) {
V_21 = F_4 ( V_42 ) & V_44 ;
break;
}
F_3 ( 10 ) ;
}
return V_21 ;
}
static void F_32 ( void T_4 * V_5 , int V_48 , int V_21 )
{
unsigned int V_7 ;
F_2 ( V_49 , V_21 ) ;
F_2 ( V_50 , V_51 | ( V_48 & V_52 ) |
V_53 << V_54 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ! ( F_4 ( V_50 ) & V_55 ) )
break;
F_3 ( 10 ) ;
}
}
static T_1 F_33 ( void T_4 * V_5 , int V_48 )
{
T_1 V_21 = ~ 0x00 ;
unsigned int V_7 ;
F_2 ( V_50 , ( V_48 & V_52 ) |
V_53 << V_54 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( F_4 ( V_50 ) & V_55 ) {
V_21 = F_4 ( V_49 ) ;
break;
}
F_3 ( 10 ) ;
}
return V_21 ;
}
static T_2 F_34 ( void T_4 * V_5 , int V_20 )
{
T_2 V_21 = 0xff ;
unsigned int V_7 ;
F_2 ( V_56 , ( V_20 & V_57 ) << V_58 ) ;
for ( V_7 = 0 ; V_7 < 300 ; V_7 ++ ) {
if ( F_4 ( V_56 ) & V_59 ) {
V_21 = F_4 ( V_56 ) & V_60 ;
break;
}
F_3 ( 100 ) ;
}
return V_21 ;
}
static void F_35 ( void T_4 * V_5 )
{
F_36 ( V_61 , 0x0000 ) ;
F_36 ( V_62 , 0xffff ) ;
}
static void F_37 ( void T_4 * V_5 )
{
F_7 ( V_63 , 0x00 ) ;
F_35 ( V_5 ) ;
F_38 ( V_64 ) ;
}
static unsigned int F_39 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
return F_4 ( V_65 ) & V_66 ;
}
static unsigned int F_40 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , V_67 ) & V_68 ;
}
static unsigned int F_41 ( void T_4 * V_5 )
{
return F_4 ( V_65 ) & V_69 ;
}
static unsigned int F_42 ( void T_4 * V_5 )
{
return F_43 ( V_70 ) & V_71 ;
}
static void F_44 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_65 , F_4 ( V_65 ) | V_66 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
V_33 = F_24 ( V_2 , V_67 ) | V_68 ;
F_23 ( V_2 , V_67 , V_33 & 0xffff ) ;
}
static void F_46 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 , bool V_72 )
{
unsigned long V_73 ;
F_47 ( & V_2 -> V_74 , V_73 ) ;
if ( V_2 -> V_75 ( V_5 ) ) {
if ( V_72 )
F_48 ( & V_2 -> V_76 -> V_40 ) ;
F_49 ( V_40 ) ;
if ( F_50 () )
F_51 ( V_2 , V_77 , V_40 , L_1 ) ;
} else {
F_52 ( V_40 ) ;
F_51 ( V_2 , V_78 , V_40 , L_2 ) ;
if ( V_72 )
F_53 ( & V_2 -> V_76 -> V_40 , 100 ) ;
}
F_54 ( & V_2 -> V_74 , V_73 ) ;
}
static void F_55 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 )
{
F_46 ( V_40 , V_2 , V_5 , false ) ;
}
static T_1 F_56 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
T_2 V_79 ;
T_1 V_80 = 0 ;
V_79 = F_43 ( V_81 ) ;
if ( ! ( V_79 & V_82 ) )
return 0 ;
V_79 = F_43 ( V_83 ) ;
if ( V_79 & V_84 )
V_80 |= V_85 ;
if ( V_79 & V_86 )
V_80 |= V_87 ;
V_79 = F_43 ( V_88 ) ;
if ( V_79 & V_89 )
V_80 |= V_90 ;
if ( V_79 & V_91 )
V_80 |= V_92 ;
if ( V_79 & V_93 )
V_80 |= V_94 ;
return V_80 ;
}
static void F_57 ( struct V_39 * V_40 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_58 ( & V_2 -> V_74 ) ;
V_96 -> V_97 = V_98 ;
V_96 -> V_80 = F_56 ( V_2 ) ;
F_59 ( & V_2 -> V_74 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_80 )
{
void T_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
static const struct {
T_1 V_99 ;
T_3 V_4 ;
T_2 V_3 ;
} V_100 [] = {
{ V_98 , V_81 , V_82 } ,
{ V_85 , V_83 , V_84 } ,
{ V_87 , V_83 , V_86 } ,
{ V_90 , V_88 , V_89 } ,
{ V_92 , V_88 , V_91 } ,
{ V_94 , V_88 , V_93 } ,
{ V_98 , V_88 , V_101 }
} ;
F_7 ( V_102 , V_103 ) ;
for ( V_7 = 0 ; V_7 < F_61 ( V_100 ) ; V_7 ++ ) {
T_2 V_79 = F_43 ( V_100 [ V_7 ] . V_4 ) & ~ V_100 [ V_7 ] . V_3 ;
if ( V_80 & V_100 [ V_7 ] . V_99 )
V_79 |= V_100 [ V_7 ] . V_3 ;
F_7 ( V_100 [ V_7 ] . V_4 , V_79 ) ;
}
F_7 ( V_102 , V_104 ) ;
}
static int F_62 ( struct V_39 * V_40 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_58 ( & V_2 -> V_74 ) ;
if ( V_96 -> V_80 )
V_2 -> V_105 |= V_106 ;
else
V_2 -> V_105 &= ~ V_106 ;
F_60 ( V_2 , V_96 -> V_80 ) ;
F_59 ( & V_2 -> V_74 ) ;
F_63 ( & V_2 -> V_76 -> V_40 , V_96 -> V_80 ) ;
return 0 ;
}
static const char * F_64 ( struct V_1 * V_2 )
{
return V_107 [ V_2 -> V_16 ] . V_108 ;
}
static void F_65 ( struct V_39 * V_40 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
strcpy ( V_110 -> V_111 , V_112 ) ;
strcpy ( V_110 -> V_113 , V_114 ) ;
strcpy ( V_110 -> V_115 , F_66 ( V_2 -> V_76 ) ) ;
strncpy ( V_110 -> V_116 , F_67 ( V_2 -> V_117 ) ? L_3 :
F_64 ( V_2 ) , sizeof( V_110 -> V_116 ) - 1 ) ;
}
static int F_68 ( struct V_39 * V_40 )
{
return V_118 ;
}
static int F_69 ( struct V_39 * V_40 ,
T_2 V_119 , T_3 V_120 , T_2 V_121 , T_1 V_122 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_123 = 0 ;
T_1 V_4 ;
V_4 = F_4 ( V_65 ) ;
if ( ( V_119 == V_124 ) && ( V_120 == V_125 ) &&
( V_121 == V_126 ) ) {
F_2 ( V_65 , V_4 & ~ ( V_127 | V_128 ) ) ;
} else if ( V_119 == V_129 )
F_2 ( V_65 , V_4 | V_127 | V_128 ) ;
else {
F_70 ( V_2 , V_130 , V_40 ,
L_4 ) ;
V_123 = - V_131 ;
}
return V_123 ;
}
static int F_71 ( struct V_39 * V_40 ,
T_2 V_119 , T_3 V_120 , T_2 V_121 , T_1 V_132 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_133 , V_134 ;
int V_135 = - V_136 ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
if ( V_119 == V_129 ) {
int V_137 ;
V_137 = F_24 ( V_2 , V_138 ) ;
V_137 &= ~ ( V_139 | V_140 |
V_141 | V_142 ) ;
if ( V_132 & V_143 )
V_137 |= V_139 ;
if ( V_132 & V_144 )
V_137 |= V_140 ;
if ( V_132 & V_145 )
V_137 |= V_141 ;
if ( V_132 & V_146 )
V_137 |= V_142 ;
V_137 |= V_147 | V_148 ;
V_133 = F_24 ( V_2 , V_149 ) ;
V_133 &= ~ ( V_150 | V_151 ) ;
if ( V_2 -> V_152 . V_153 ) {
if ( V_132 & V_154 )
V_133 |= V_151 ;
if ( V_132 & V_155 )
V_133 |= V_150 ;
} else if ( V_132 & ( V_154 |
V_155 ) ) {
F_51 ( V_2 , V_130 , V_40 ,
L_5 ) ;
goto V_156;
}
V_134 = V_157 | V_158 ;
F_23 ( V_2 , V_138 , V_137 ) ;
F_23 ( V_2 , V_149 , V_133 ) ;
} else {
V_133 = 0 ;
if ( V_120 == V_159 )
V_134 = 0 ;
else if ( V_120 == V_160 )
V_134 = V_161 ;
else
goto V_156;
if ( V_121 == V_126 )
V_134 |= V_162 ;
}
F_23 ( V_2 , V_67 , V_134 ) ;
if ( V_2 -> V_16 == V_163 ||
V_2 -> V_16 == V_164 ) {
if ( ( V_120 == V_160 ) && ( V_119 != V_129 ) ) {
F_23 ( V_2 , 0x17 , 0x2138 ) ;
F_23 ( V_2 , 0x0e , 0x0260 ) ;
} else {
F_23 ( V_2 , 0x17 , 0x2108 ) ;
F_23 ( V_2 , 0x0e , 0x0000 ) ;
}
}
V_135 = 0 ;
V_156:
return V_135 ;
}
static int F_72 ( struct V_39 * V_40 ,
T_2 V_119 , T_3 V_120 , T_2 V_121 , T_1 V_165 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_123 ;
V_123 = V_2 -> V_166 ( V_40 , V_119 , V_120 , V_121 , V_165 ) ;
if ( V_123 < 0 )
goto V_156;
if ( F_73 ( V_40 ) && ( V_119 == V_129 ) &&
( V_165 & V_155 ) ) {
F_74 ( & V_2 -> V_167 , V_168 + V_169 ) ;
}
V_156:
return V_123 ;
}
static int F_75 ( struct V_39 * V_40 , struct V_170 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_73 ;
int V_123 ;
F_76 ( & V_2 -> V_167 ) ;
F_47 ( & V_2 -> V_74 , V_73 ) ;
V_123 = F_72 ( V_40 , V_12 -> V_119 , F_77 ( V_12 ) ,
V_12 -> V_121 , V_12 -> V_165 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
return V_123 ;
}
static T_1 F_78 ( struct V_39 * V_40 , T_1 V_105 )
{
if ( V_40 -> V_171 > V_172 )
V_105 &= ~ V_173 ;
return V_105 ;
}
static int F_79 ( struct V_39 * V_40 , T_1 V_105 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_73 ;
F_47 ( & V_2 -> V_74 , V_73 ) ;
if ( V_105 & V_174 )
V_2 -> V_175 |= V_176 ;
else
V_2 -> V_175 &= ~ V_176 ;
if ( V_40 -> V_105 & V_177 )
V_2 -> V_175 |= V_178 ;
else
V_2 -> V_175 &= ~ V_178 ;
F_36 ( V_64 , V_2 -> V_175 ) ;
F_38 ( V_64 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
return 0 ;
}
static inline T_1 F_80 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
return ( F_81 ( V_180 ) ) ?
V_181 | F_82 ( F_83 ( V_180 ) ) : 0x00 ;
}
static void F_84 ( struct V_182 * V_183 , struct V_179 * V_180 )
{
T_1 V_184 = F_85 ( V_183 -> V_184 ) ;
if ( V_184 & V_185 )
F_86 ( V_180 , F_82 ( V_184 & 0xffff ) ) ;
V_183 -> V_184 = 0 ;
}
static int F_87 ( struct V_39 * V_40 , struct V_170 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
T_1 V_186 ;
V_12 -> V_97 =
V_187 | V_188 | V_189 ;
V_12 -> V_190 = V_191 ;
V_12 -> V_192 = V_193 ;
V_186 = F_4 ( V_65 ) ;
V_12 -> V_165 = ( V_186 & V_127 ) ? V_194 : 0 ;
V_12 -> V_119 = ! ! ( V_186 & V_127 ) ;
F_88 ( V_12 , V_125 ) ;
V_12 -> V_121 = V_126 ;
return 0 ;
}
static int F_89 ( struct V_39 * V_40 , struct V_170 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
return F_90 ( & V_2 -> V_152 , V_12 ) ;
}
static int F_91 ( struct V_39 * V_40 , struct V_170 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_73 ;
int V_135 ;
F_47 ( & V_2 -> V_74 , V_73 ) ;
V_135 = V_2 -> V_195 ( V_40 , V_12 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
return V_135 ;
}
static void F_92 ( struct V_39 * V_40 , struct V_196 * V_197 ,
void * V_37 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_73 ;
if ( V_197 -> V_198 > V_118 )
V_197 -> V_198 = V_118 ;
F_47 ( & V_2 -> V_74 , V_73 ) ;
F_93 ( V_37 , V_2 -> V_6 , V_197 -> V_198 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
}
static T_1 F_94 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
return V_2 -> V_199 ;
}
static void F_95 ( struct V_39 * V_40 , T_1 V_21 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
V_2 -> V_199 = V_21 ;
}
static int F_96 ( struct V_39 * V_40 , int V_200 )
{
switch ( V_200 ) {
case V_201 :
return F_61 ( V_202 ) ;
default:
return - V_131 ;
}
}
static void F_97 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_203 * V_204 = & V_2 -> V_76 -> V_40 ;
struct V_205 * V_206 ;
T_5 V_207 ;
T_1 V_12 ;
int V_208 = 1000 ;
if ( ( F_43 ( V_63 ) & V_209 ) == 0 )
return;
V_206 = F_98 ( V_204 , sizeof( * V_206 ) , & V_207 , V_210 ) ;
if ( ! V_206 )
return;
F_2 ( V_211 , ( V_212 ) V_207 >> 32 ) ;
V_12 = ( V_212 ) V_207 & F_99 ( 32 ) ;
F_2 ( V_213 , V_12 ) ;
F_2 ( V_213 , V_12 | V_214 ) ;
while ( V_208 -- ) {
if ( ( F_4 ( V_213 ) & V_214 ) == 0 ) {
memcpy ( & V_2 -> V_206 , V_206 , sizeof( * V_206 ) ) ;
break;
}
F_3 ( 10 ) ;
}
F_2 ( V_213 , 0 ) ;
F_2 ( V_211 , 0 ) ;
F_100 ( V_204 , sizeof( * V_206 ) , V_206 , V_207 ) ;
}
static void F_101 ( struct V_39 * V_40 ,
struct V_215 * V_216 , V_212 * V_11 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_102 () ;
F_97 ( V_40 ) ;
V_11 [ 0 ] = F_103 ( V_2 -> V_206 . V_217 ) ;
V_11 [ 1 ] = F_103 ( V_2 -> V_206 . V_218 ) ;
V_11 [ 2 ] = F_103 ( V_2 -> V_206 . V_219 ) ;
V_11 [ 3 ] = F_85 ( V_2 -> V_206 . V_220 ) ;
V_11 [ 4 ] = F_104 ( V_2 -> V_206 . V_221 ) ;
V_11 [ 5 ] = F_104 ( V_2 -> V_206 . V_222 ) ;
V_11 [ 6 ] = F_85 ( V_2 -> V_206 . V_223 ) ;
V_11 [ 7 ] = F_85 ( V_2 -> V_206 . V_224 ) ;
V_11 [ 8 ] = F_103 ( V_2 -> V_206 . V_225 ) ;
V_11 [ 9 ] = F_103 ( V_2 -> V_206 . V_226 ) ;
V_11 [ 10 ] = F_85 ( V_2 -> V_206 . V_227 ) ;
V_11 [ 11 ] = F_104 ( V_2 -> V_206 . V_228 ) ;
V_11 [ 12 ] = F_104 ( V_2 -> V_206 . V_229 ) ;
}
static void F_105 ( struct V_39 * V_40 , T_1 V_230 , T_2 * V_11 )
{
switch( V_230 ) {
case V_201 :
memcpy ( V_11 , * V_202 , sizeof( V_202 ) ) ;
break;
}
}
static void F_106 ( struct V_1 * V_2 ,
struct V_39 * V_40 , T_2 V_231 )
{
void T_4 * V_5 = V_2 -> V_6 ;
static const struct V_232 {
T_1 V_3 ;
T_1 V_33 ;
int V_16 ;
} V_233 [] = {
{ 0x7cf00000 , 0x2c200000 , V_234 } ,
{ 0x7cf00000 , 0x2c100000 , V_235 } ,
{ 0x7c800000 , 0x2c000000 , V_234 } ,
{ 0x7cf00000 , 0x28300000 , V_236 } ,
{ 0x7cf00000 , 0x28100000 , V_237 } ,
{ 0x7c800000 , 0x28000000 , V_236 } ,
{ 0x7cf00000 , 0x28800000 , V_238 } ,
{ 0x7cf00000 , 0x28a00000 , V_239 } ,
{ 0x7cf00000 , 0x28b00000 , V_17 } ,
{ 0x7cf00000 , 0x3cb00000 , V_240 } ,
{ 0x7cf00000 , 0x3c900000 , V_241 } ,
{ 0x7cf00000 , 0x3c800000 , V_242 } ,
{ 0x7c800000 , 0x3c800000 , V_240 } ,
{ 0x7cf00000 , 0x3c000000 , V_243 } ,
{ 0x7cf00000 , 0x3c200000 , V_244 } ,
{ 0x7cf00000 , 0x3c300000 , V_245 } ,
{ 0x7cf00000 , 0x3c400000 , V_246 } ,
{ 0x7c800000 , 0x3c000000 , V_246 } ,
{ 0x7cf00000 , 0x38000000 , V_247 } ,
{ 0x7cf00000 , 0x38500000 , V_248 } ,
{ 0x7c800000 , 0x38000000 , V_248 } ,
{ 0x7c800000 , 0x30000000 , V_249 } ,
{ 0x7cf00000 , 0x40b00000 , V_250 } ,
{ 0x7cf00000 , 0x40a00000 , V_250 } ,
{ 0x7cf00000 , 0x40900000 , V_251 } ,
{ 0x7c800000 , 0x40800000 , V_250 } ,
{ 0x7cf00000 , 0x34a00000 , V_252 } ,
{ 0x7cf00000 , 0x24a00000 , V_252 } ,
{ 0x7cf00000 , 0x34900000 , V_253 } ,
{ 0x7cf00000 , 0x24900000 , V_253 } ,
{ 0x7cf00000 , 0x34800000 , V_254 } ,
{ 0x7cf00000 , 0x24800000 , V_254 } ,
{ 0x7cf00000 , 0x34000000 , V_255 } ,
{ 0x7cf00000 , 0x34300000 , V_256 } ,
{ 0x7cf00000 , 0x34200000 , V_257 } ,
{ 0x7c800000 , 0x34800000 , V_252 } ,
{ 0x7c800000 , 0x24800000 , V_252 } ,
{ 0x7c800000 , 0x34000000 , V_257 } ,
{ 0xfc800000 , 0x38800000 , V_258 } ,
{ 0xfc800000 , 0x30800000 , V_259 } ,
{ 0xfc800000 , 0x98000000 , V_260 } ,
{ 0xfc800000 , 0x18000000 , V_261 } ,
{ 0xfc800000 , 0x10000000 , V_262 } ,
{ 0xfc800000 , 0x04000000 , V_164 } ,
{ 0xfc800000 , 0x00800000 , V_163 } ,
{ 0xfc800000 , 0x00000000 , V_263 } ,
{ 0x00000000 , 0x00000000 , V_264 }
} ;
const struct V_232 * V_37 = V_233 ;
T_1 V_4 ;
V_4 = F_4 ( V_265 ) ;
while ( ( V_4 & V_37 -> V_3 ) != V_37 -> V_33 )
V_37 ++ ;
V_2 -> V_16 = V_37 -> V_16 ;
if ( V_2 -> V_16 == V_264 ) {
F_107 ( V_2 , V_266 , V_40 ,
L_6 ) ;
V_2 -> V_16 = V_231 ;
}
}
static void F_108 ( struct V_1 * V_2 )
{
F_109 ( L_7 , V_2 -> V_16 ) ;
}
static void F_110 ( struct V_1 * V_2 ,
const struct V_267 * V_197 , int V_198 )
{
while ( V_198 -- > 0 ) {
F_23 ( V_2 , V_197 -> V_4 , V_197 -> V_33 ) ;
V_197 ++ ;
}
}
static void
F_111 ( struct V_1 * V_2 , const struct V_268 * V_117 )
{
T_6 * V_269 = ( T_6 * ) V_117 -> V_11 ;
struct V_39 * V_40 = V_2 -> V_40 ;
T_7 V_270 , V_271 = V_117 -> V_272 / sizeof( * V_269 ) ;
T_1 V_273 , V_274 ;
if ( V_117 -> V_272 % sizeof( * V_269 ) ) {
F_112 ( V_2 , V_266 , V_40 , L_8 , V_117 -> V_272 ) ;
return;
}
for ( V_270 = 0 ; V_270 < V_271 ; V_270 ++ ) {
T_1 V_275 = F_85 ( V_269 [ V_270 ] ) ;
T_1 V_276 = ( V_275 & 0x0fff0000 ) >> 16 ;
switch( V_275 & 0xf0000000 ) {
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
break;
case V_285 :
if ( V_276 > V_270 ) {
F_112 ( V_2 , V_266 , V_2 -> V_40 ,
L_9 ) ;
return;
}
break;
case V_286 :
if ( V_270 + 2 >= V_271 ) {
F_112 ( V_2 , V_266 , V_2 -> V_40 ,
L_9 ) ;
return;
}
break;
case V_287 :
case V_288 :
case V_289 :
if ( V_270 + 1 + V_276 >= V_271 ) {
F_112 ( V_2 , V_266 , V_2 -> V_40 ,
L_9 ) ;
return;
}
break;
case V_290 :
case V_291 :
case V_292 :
default:
F_112 ( V_2 , V_266 , V_2 -> V_40 ,
L_10 , V_275 ) ;
return;
}
}
V_273 = 0 ;
V_274 = 0 ;
for ( V_270 = 0 ; V_270 < V_271 ; ) {
T_1 V_275 = F_85 ( V_269 [ V_270 ] ) ;
T_1 V_11 = V_275 & 0x0000ffff ;
T_1 V_276 = ( V_275 & 0x0fff0000 ) >> 16 ;
if ( ! V_275 )
break;
switch( V_275 & 0xf0000000 ) {
case V_277 :
V_273 = F_24 ( V_2 , V_276 ) ;
V_274 ++ ;
V_270 ++ ;
break;
case V_278 :
V_273 |= V_11 ;
V_270 ++ ;
break;
case V_279 :
V_273 &= V_11 ;
V_270 ++ ;
break;
case V_285 :
V_270 -= V_276 ;
break;
case V_280 :
V_273 = F_34 ( V_2 -> V_6 , V_276 ) ;
V_270 ++ ;
break;
case V_281 :
V_274 = 0 ;
V_270 ++ ;
break;
case V_282 :
F_23 ( V_2 , V_276 , V_11 ) ;
V_270 ++ ;
break;
case V_286 :
V_270 += ( V_274 == V_11 ) ? 2 : 1 ;
break;
case V_287 :
if ( V_273 == V_11 )
V_270 += V_276 ;
V_270 ++ ;
break;
case V_288 :
if ( V_273 != V_11 )
V_270 += V_276 ;
V_270 ++ ;
break;
case V_283 :
F_23 ( V_2 , V_276 , V_273 ) ;
V_270 ++ ;
break;
case V_289 :
V_270 += V_276 + 1 ;
break;
case V_284 :
F_16 ( V_11 ) ;
V_270 ++ ;
break;
case V_290 :
case V_291 :
case V_292 :
default:
F_113 () ;
}
}
}
static void F_114 ( struct V_1 * V_2 )
{
if ( ! F_67 ( V_2 -> V_117 ) )
F_115 ( V_2 -> V_117 ) ;
V_2 -> V_117 = V_293 ;
}
static void F_116 ( struct V_1 * V_2 )
{
const struct V_268 * V_117 = V_2 -> V_117 ;
if ( ! F_67 ( V_117 ) )
F_111 ( V_2 , V_117 ) ;
}
static void F_117 ( struct V_1 * V_2 , T_2 V_4 , T_3 V_33 )
{
if ( F_24 ( V_2 , V_4 ) != V_33 )
F_70 ( V_2 , V_294 , V_2 -> V_40 , L_11 ) ;
else
F_116 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x06 , 0x006e } ,
{ 0x08 , 0x0708 } ,
{ 0x15 , 0x4000 } ,
{ 0x18 , 0x65c7 } ,
{ 0x1f , 0x0001 } ,
{ 0x03 , 0x00a1 } ,
{ 0x02 , 0x0008 } ,
{ 0x01 , 0x0120 } ,
{ 0x00 , 0x1000 } ,
{ 0x04 , 0x0800 } ,
{ 0x04 , 0x0000 } ,
{ 0x03 , 0xff41 } ,
{ 0x02 , 0xdf60 } ,
{ 0x01 , 0x0140 } ,
{ 0x00 , 0x0077 } ,
{ 0x04 , 0x7800 } ,
{ 0x04 , 0x7000 } ,
{ 0x03 , 0x802f } ,
{ 0x02 , 0x4f02 } ,
{ 0x01 , 0x0409 } ,
{ 0x00 , 0xf0f9 } ,
{ 0x04 , 0x9800 } ,
{ 0x04 , 0x9000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0xff95 } ,
{ 0x00 , 0xba00 } ,
{ 0x04 , 0xa800 } ,
{ 0x04 , 0xa000 } ,
{ 0x03 , 0xff41 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0x0140 } ,
{ 0x00 , 0x00bb } ,
{ 0x04 , 0xb800 } ,
{ 0x04 , 0xb000 } ,
{ 0x03 , 0xdf41 } ,
{ 0x02 , 0xdc60 } ,
{ 0x01 , 0x6340 } ,
{ 0x00 , 0x007d } ,
{ 0x04 , 0xd800 } ,
{ 0x04 , 0xd000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0x100a } ,
{ 0x00 , 0xa0ff } ,
{ 0x04 , 0xf800 } ,
{ 0x04 , 0xf000 } ,
{ 0x1f , 0x0000 } ,
{ 0x0b , 0x0000 } ,
{ 0x00 , 0x9200 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x01 , 0x90d0 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_76 * V_296 = V_2 -> V_76 ;
T_3 V_297 , V_298 ;
F_121 ( V_296 , V_299 , & V_297 ) ;
F_121 ( V_296 , V_300 , & V_298 ) ;
if ( ( V_297 != V_301 ) || ( V_298 != 0xe000 ) )
return;
F_23 ( V_2 , 0x1f , 0x0001 ) ;
F_23 ( V_2 , 0x10 , 0xf01b ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x04 , 0x0000 } ,
{ 0x03 , 0x00a1 } ,
{ 0x02 , 0x0008 } ,
{ 0x01 , 0x0120 } ,
{ 0x00 , 0x1000 } ,
{ 0x04 , 0x0800 } ,
{ 0x04 , 0x9000 } ,
{ 0x03 , 0x802f } ,
{ 0x02 , 0x4f02 } ,
{ 0x01 , 0x0409 } ,
{ 0x00 , 0xf099 } ,
{ 0x04 , 0x9800 } ,
{ 0x04 , 0xa000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0xff95 } ,
{ 0x00 , 0xba00 } ,
{ 0x04 , 0xa800 } ,
{ 0x04 , 0xf000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0x101a } ,
{ 0x00 , 0xa0ff } ,
{ 0x04 , 0xf800 } ,
{ 0x04 , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x10 , 0xf41b } ,
{ 0x14 , 0xfb54 } ,
{ 0x18 , 0xf5c7 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_120 ( V_2 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x04 , 0x0000 } ,
{ 0x03 , 0x00a1 } ,
{ 0x02 , 0x0008 } ,
{ 0x01 , 0x0120 } ,
{ 0x00 , 0x1000 } ,
{ 0x04 , 0x0800 } ,
{ 0x04 , 0x9000 } ,
{ 0x03 , 0x802f } ,
{ 0x02 , 0x4f02 } ,
{ 0x01 , 0x0409 } ,
{ 0x00 , 0xf099 } ,
{ 0x04 , 0x9800 } ,
{ 0x04 , 0xa000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0xff95 } ,
{ 0x00 , 0xba00 } ,
{ 0x04 , 0xa800 } ,
{ 0x04 , 0xf000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0x101a } ,
{ 0x00 , 0xa0ff } ,
{ 0x04 , 0xf800 } ,
{ 0x04 , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x0b , 0x8480 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x18 , 0x67c7 } ,
{ 0x04 , 0x2000 } ,
{ 0x03 , 0x002f } ,
{ 0x02 , 0x4360 } ,
{ 0x01 , 0x0109 } ,
{ 0x00 , 0x3022 } ,
{ 0x04 , 0x2800 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0001 ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0000 } ,
{ 0x1d , 0x0f00 } ,
{ 0x1f , 0x0002 } ,
{ 0x0c , 0x1ec8 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x1d , 0x3d98 } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x12 , 0x2300 } ,
{ 0x1f , 0x0002 } ,
{ 0x00 , 0x88d4 } ,
{ 0x01 , 0x82b1 } ,
{ 0x03 , 0x7002 } ,
{ 0x08 , 0x9e30 } ,
{ 0x09 , 0x01f0 } ,
{ 0x0a , 0x5500 } ,
{ 0x0c , 0x00c8 } ,
{ 0x1f , 0x0003 } ,
{ 0x12 , 0xc096 } ,
{ 0x16 , 0x000a } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x09 , 0x2000 } ,
{ 0x09 , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x12 , 0x2300 } ,
{ 0x03 , 0x802f } ,
{ 0x02 , 0x4f02 } ,
{ 0x01 , 0x0409 } ,
{ 0x00 , 0xf099 } ,
{ 0x04 , 0x9800 } ,
{ 0x04 , 0x9000 } ,
{ 0x1d , 0x3d98 } ,
{ 0x1f , 0x0002 } ,
{ 0x0c , 0x7eb8 } ,
{ 0x06 , 0x0761 } ,
{ 0x1f , 0x0003 } ,
{ 0x16 , 0x0f0a } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x12 , 0x2300 } ,
{ 0x1d , 0x3d98 } ,
{ 0x1f , 0x0002 } ,
{ 0x0c , 0x7eb8 } ,
{ 0x06 , 0x5461 } ,
{ 0x1f , 0x0003 } ,
{ 0x16 , 0x0f0a } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_130 ( V_2 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
static const struct V_267 V_302 [] = {
{ 0x1f , 0x0001 } ,
{ 0x06 , 0x4064 } ,
{ 0x07 , 0x2863 } ,
{ 0x08 , 0x059c } ,
{ 0x09 , 0x26b4 } ,
{ 0x0a , 0x6a19 } ,
{ 0x0b , 0xdcc8 } ,
{ 0x10 , 0xf06d } ,
{ 0x14 , 0x7f68 } ,
{ 0x18 , 0x7fd9 } ,
{ 0x1c , 0xf0ff } ,
{ 0x1d , 0x3d9c } ,
{ 0x1f , 0x0003 } ,
{ 0x12 , 0xf49f } ,
{ 0x13 , 0x070b } ,
{ 0x1a , 0x05ad } ,
{ 0x14 , 0x94c0 } ,
{ 0x1f , 0x0002 } ,
{ 0x06 , 0x5561 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8332 } ,
{ 0x06 , 0x5561 } ,
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0000 } ,
{ 0x0d , 0xf880 }
} ;
void T_4 * V_5 = V_2 -> V_6 ;
F_110 ( V_2 , V_302 , F_61 ( V_302 ) ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x0b , 0x0010 , 0x00ef ) ;
F_26 ( V_2 , 0x0c , 0xa200 , 0x5d00 ) ;
if ( F_34 ( V_5 , 0x01 ) == 0xb1 ) {
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_33 ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
V_33 = F_24 ( V_2 , 0x0d ) ;
if ( ( V_33 & 0x00ff ) != 0x006c ) {
static const T_1 V_303 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_7 ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
V_33 &= 0xff00 ;
for ( V_7 = 0 ; V_7 < F_61 ( V_303 ) ; V_7 ++ )
F_23 ( V_2 , 0x0d , V_33 | V_303 [ V_7 ] ) ;
}
} else {
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x6662 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x6662 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_25 ( V_2 , 0x0d , 0x0300 ) ;
F_25 ( V_2 , 0x0f , 0x0010 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_26 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x001b ) ;
F_117 ( V_2 , V_304 , 0xbf00 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
static const struct V_267 V_302 [] = {
{ 0x1f , 0x0001 } ,
{ 0x06 , 0x4064 } ,
{ 0x07 , 0x2863 } ,
{ 0x08 , 0x059c } ,
{ 0x09 , 0x26b4 } ,
{ 0x0a , 0x6a19 } ,
{ 0x0b , 0xdcc8 } ,
{ 0x10 , 0xf06d } ,
{ 0x14 , 0x7f68 } ,
{ 0x18 , 0x7fd9 } ,
{ 0x1c , 0xf0ff } ,
{ 0x1d , 0x3d9c } ,
{ 0x1f , 0x0003 } ,
{ 0x12 , 0xf49f } ,
{ 0x13 , 0x070b } ,
{ 0x1a , 0x05ad } ,
{ 0x14 , 0x94c0 } ,
{ 0x1f , 0x0002 } ,
{ 0x06 , 0x5561 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8332 } ,
{ 0x06 , 0x5561 } ,
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0000 } ,
{ 0x0d , 0xf880 }
} ;
void T_4 * V_5 = V_2 -> V_6 ;
F_110 ( V_2 , V_302 , F_61 ( V_302 ) ) ;
if ( F_34 ( V_5 , 0x01 ) == 0xb1 ) {
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_33 ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
V_33 = F_24 ( V_2 , 0x0d ) ;
if ( ( V_33 & 0x00ff ) != 0x006c ) {
static const T_1 V_303 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_7 ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
V_33 &= 0xff00 ;
for ( V_7 = 0 ; V_7 < F_61 ( V_303 ) ; V_7 ++ )
F_23 ( V_2 , 0x0d , V_33 | V_303 [ V_7 ] ) ;
}
} else {
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x2642 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x2642 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_26 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_25 ( V_2 , 0x0f , 0x0017 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x001b ) ;
F_117 ( V_2 , V_304 , 0xb300 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0002 } ,
{ 0x10 , 0x0008 } ,
{ 0x0d , 0x006c } ,
{ 0x1f , 0x0000 } ,
{ 0x0d , 0xf880 } ,
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0001 } ,
{ 0x0b , 0xa4d8 } ,
{ 0x09 , 0x281c } ,
{ 0x07 , 0x2883 } ,
{ 0x0a , 0x6b35 } ,
{ 0x1d , 0x3da4 } ,
{ 0x1c , 0xeffd } ,
{ 0x14 , 0x7f52 } ,
{ 0x18 , 0x7fc6 } ,
{ 0x08 , 0x0601 } ,
{ 0x06 , 0x4063 } ,
{ 0x10 , 0xf074 } ,
{ 0x1f , 0x0003 } ,
{ 0x13 , 0x0789 } ,
{ 0x12 , 0xf4bd } ,
{ 0x1a , 0x04fd } ,
{ 0x14 , 0x84b0 } ,
{ 0x1f , 0x0000 } ,
{ 0x00 , 0x9200 } ,
{ 0x1f , 0x0005 } ,
{ 0x01 , 0x0340 } ,
{ 0x1f , 0x0001 } ,
{ 0x04 , 0x4000 } ,
{ 0x03 , 0x1d21 } ,
{ 0x02 , 0x0c32 } ,
{ 0x01 , 0x0200 } ,
{ 0x00 , 0x5554 } ,
{ 0x04 , 0x4800 } ,
{ 0x04 , 0x4000 } ,
{ 0x04 , 0xf000 } ,
{ 0x03 , 0xdf01 } ,
{ 0x02 , 0xdf20 } ,
{ 0x01 , 0x101a } ,
{ 0x00 , 0xa0ff } ,
{ 0x04 , 0xf800 } ,
{ 0x04 , 0xf000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x0023 } ,
{ 0x16 , 0x0000 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x002d } ,
{ 0x18 , 0x0040 } ,
{ 0x1f , 0x0000 }
} ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8b80 } ,
{ 0x06 , 0xc896 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x0b , 0x6c20 } ,
{ 0x07 , 0x2872 } ,
{ 0x1c , 0xefff } ,
{ 0x1f , 0x0003 } ,
{ 0x14 , 0x6420 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x002f } ,
{ 0x15 , 0x1919 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x00ac } ,
{ 0x18 , 0x0006 } ,
{ 0x1f , 0x0000 }
} ;
F_116 ( V_2 ) ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
F_23 ( V_2 , 0x1f , 0x0007 ) ;
F_23 ( V_2 , 0x1e , 0x0023 ) ;
F_26 ( V_2 , 0x17 , 0x0006 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x08 , 0x8000 , 0x7f00 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0007 ) ;
F_23 ( V_2 , 0x1e , 0x002d ) ;
F_26 ( V_2 , 0x18 , 0x0050 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_26 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b86 ) ;
F_26 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b85 ) ;
F_26 ( V_2 , 0x06 , 0x0000 , 0x2000 ) ;
F_23 ( V_2 , 0x1f , 0x0007 ) ;
F_23 ( V_2 , 0x1e , 0x0020 ) ;
F_26 ( V_2 , 0x15 , 0x0000 , 0x1100 ) ;
F_23 ( V_2 , 0x1f , 0x0006 ) ;
F_23 ( V_2 , 0x00 , 0x5a00 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x0d , 0x0007 ) ;
F_23 ( V_2 , 0x0e , 0x003c ) ;
F_23 ( V_2 , 0x0d , 0x4007 ) ;
F_23 ( V_2 , 0x0e , 0x0000 ) ;
F_23 ( V_2 , 0x0d , 0x0000 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0003 } ,
{ 0x08 , 0x441d } ,
{ 0x01 , 0x9100 } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_25 ( V_2 , 0x11 , 1 << 12 ) ;
F_25 ( V_2 , 0x19 , 1 << 13 ) ;
F_25 ( V_2 , 0x10 , 1 << 15 ) ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
static const struct V_267 V_295 [] = {
{ 0x1f , 0x0005 } ,
{ 0x1a , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0004 } ,
{ 0x1c , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0001 } ,
{ 0x15 , 0x7701 } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x18 , 0x0310 ) ;
F_8 ( 100 ) ;
F_116 ( V_2 ) ;
F_110 ( V_2 , V_295 , F_61 ( V_295 ) ) ;
}
static void F_139 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_108 ( V_2 ) ;
switch ( V_2 -> V_16 ) {
case V_263 :
break;
case V_163 :
case V_164 :
F_118 ( V_2 ) ;
break;
case V_262 :
F_119 ( V_2 ) ;
break;
case V_261 :
F_122 ( V_2 ) ;
break;
case V_260 :
F_123 ( V_2 ) ;
break;
case V_254 :
case V_253 :
case V_252 :
F_137 ( V_2 ) ;
break;
case V_249 :
F_124 ( V_2 ) ;
break;
case V_247 :
F_125 ( V_2 ) ;
break;
case V_248 :
F_125 ( V_2 ) ;
break;
case V_242 :
F_126 ( V_2 ) ;
break;
case V_243 :
F_128 ( V_2 ) ;
break;
case V_244 :
F_129 ( V_2 ) ;
break;
case V_245 :
F_130 ( V_2 ) ;
break;
case V_246 :
F_131 ( V_2 ) ;
break;
case V_241 :
case V_240 :
F_127 ( V_2 ) ;
break;
case V_237 :
F_132 ( V_2 ) ;
break;
case V_236 :
F_133 ( V_2 ) ;
break;
case V_238 :
F_134 ( V_2 ) ;
break;
case V_239 :
F_135 ( V_2 ) ;
break;
case V_251 :
case V_250 :
F_138 ( V_2 ) ;
break;
case V_17 :
break;
case V_235 :
case V_234 :
F_136 ( V_2 ) ;
break;
default:
break;
}
}
static void F_140 ( unsigned long V_305 )
{
struct V_39 * V_40 = (struct V_39 * ) V_305 ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_306 * V_167 = & V_2 -> V_167 ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_307 = V_169 ;
assert ( V_2 -> V_16 > V_263 ) ;
F_58 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_308 ( V_2 ) ) {
V_307 = V_309 / 10 ;
goto V_310;
}
if ( V_2 -> V_75 ( V_5 ) )
goto V_311;
F_70 ( V_2 , V_130 , V_40 , L_12 ) ;
V_2 -> V_312 ( V_2 ) ;
V_310:
F_74 ( V_167 , V_168 + V_307 ) ;
V_311:
F_59 ( & V_2 -> V_74 ) ;
}
static void F_141 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_76 * V_296 = V_2 -> V_76 ;
F_142 ( V_296 -> V_313 ) ;
F_143 ( V_296 -> V_313 , V_40 ) ;
F_144 ( V_296 -> V_313 ) ;
}
static void F_145 ( struct V_76 * V_296 , struct V_39 * V_40 ,
void T_4 * V_5 )
{
F_146 ( V_5 ) ;
F_147 ( V_296 ) ;
F_148 ( V_296 ) ;
F_149 ( V_296 ) ;
F_150 ( V_40 ) ;
}
static void F_151 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
unsigned int V_7 ;
V_2 -> V_312 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ! V_2 -> V_308 ( V_2 ) )
return;
F_8 ( 1 ) ;
}
F_112 ( V_2 , V_130 , V_40 , L_13 ) ;
}
static void F_152 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_139 ( V_40 ) ;
if ( V_2 -> V_16 <= V_260 ) {
F_109 ( L_14 ) ;
F_7 ( 0x82 , 0x01 ) ;
}
F_153 ( V_2 -> V_76 , V_314 , 0x40 ) ;
if ( V_2 -> V_16 <= V_260 )
F_153 ( V_2 -> V_76 , V_315 , 0x08 ) ;
if ( V_2 -> V_16 == V_163 ) {
F_109 ( L_14 ) ;
F_7 ( 0x82 , 0x01 ) ;
F_109 ( L_15 ) ;
F_23 ( V_2 , 0x0b , 0x0000 ) ;
}
F_151 ( V_40 , V_2 ) ;
F_72 ( V_40 , V_129 , V_125 , V_126 ,
V_143 | V_144 |
V_145 | V_146 |
( V_2 -> V_152 . V_153 ?
V_154 |
V_155 : 0 ) ) ;
if ( F_43 ( V_70 ) & V_316 )
F_51 ( V_2 , V_130 , V_40 , L_16 ) ;
}
static void F_154 ( struct V_1 * V_2 , T_2 * V_48 )
{
void T_4 * V_5 = V_2 -> V_6 ;
T_1 V_317 ;
T_1 V_318 ;
V_318 = V_48 [ 0 ] | ( V_48 [ 1 ] << 8 ) | ( V_48 [ 2 ] << 16 ) | ( V_48 [ 3 ] << 24 ) ;
V_317 = V_48 [ 4 ] | ( V_48 [ 5 ] << 8 ) ;
F_58 ( & V_2 -> V_74 ) ;
F_7 ( V_102 , V_103 ) ;
F_2 ( V_319 , V_317 ) ;
F_4 ( V_319 ) ;
F_2 ( V_320 , V_318 ) ;
F_4 ( V_320 ) ;
F_7 ( V_102 , V_104 ) ;
F_59 ( & V_2 -> V_74 ) ;
}
static int F_155 ( struct V_39 * V_40 , void * V_37 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_321 * V_48 = V_37 ;
if ( ! F_156 ( V_48 -> V_322 ) )
return - V_323 ;
memcpy ( V_40 -> V_324 , V_48 -> V_322 , V_40 -> V_325 ) ;
F_154 ( V_2 , V_40 -> V_324 ) ;
return 0 ;
}
static int F_157 ( struct V_39 * V_40 , struct V_326 * V_327 , int V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_328 * V_11 = F_158 ( V_327 ) ;
return F_73 ( V_40 ) ? V_2 -> V_329 ( V_2 , V_11 , V_12 ) : - V_330 ;
}
static int F_159 ( struct V_1 * V_2 ,
struct V_328 * V_11 , int V_12 )
{
switch ( V_12 ) {
case V_331 :
V_11 -> V_41 = 32 ;
return 0 ;
case V_332 :
V_11 -> V_333 = F_24 ( V_2 , V_11 -> V_334 & 0x1f ) ;
return 0 ;
case V_335 :
F_23 ( V_2 , V_11 -> V_334 & 0x1f , V_11 -> V_336 ) ;
return 0 ;
}
return - V_131 ;
}
static int F_160 ( struct V_1 * V_2 , struct V_328 * V_11 , int V_12 )
{
return - V_131 ;
}
static unsigned F_161 ( struct V_76 * V_296 , void T_4 * V_5 ,
const struct V_337 * V_100 )
{
unsigned V_338 = 0 ;
T_2 V_339 ;
V_339 = F_43 ( V_340 ) & ~ V_341 ;
if ( V_100 -> V_105 & V_342 ) {
if ( F_162 ( V_296 ) ) {
F_163 ( & V_296 -> V_40 , L_17 ) ;
} else {
V_339 |= V_341 ;
V_338 = V_342 ;
}
}
F_7 ( V_340 , V_339 ) ;
return V_338 ;
}
static void F_164 ( struct V_76 * V_296 , struct V_1 * V_2 )
{
if ( V_2 -> V_105 & V_342 ) {
F_165 ( V_296 ) ;
V_2 -> V_105 &= ~ V_342 ;
}
}
static void T_8 F_166 ( struct V_1 * V_2 )
{
struct V_34 * V_343 = & V_2 -> V_34 ;
switch ( V_2 -> V_16 ) {
case V_238 :
V_343 -> V_35 = F_17 ;
V_343 -> V_36 = F_18 ;
break;
case V_239 :
case V_17 :
V_343 -> V_35 = F_21 ;
V_343 -> V_36 = F_22 ;
break;
default:
V_343 -> V_35 = F_13 ;
V_343 -> V_36 = F_14 ;
break;
}
}
static void F_167 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_67 , V_344 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_67 , V_157 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) & V_98 ) {
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_67 , 0x0000 ) ;
return;
}
F_167 ( V_2 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
F_168 ( V_2 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_16 ) {
case V_249 :
case V_247 :
case V_248 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_241 :
case V_240 :
case V_237 :
case V_236 :
case V_238 :
case V_239 :
case V_17 :
F_23 ( V_2 , 0x0e , 0x0000 ) ;
break;
default:
break;
}
F_23 ( V_2 , V_67 , V_157 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_16 ) {
case V_235 :
case V_234 :
F_23 ( V_2 , V_67 , V_157 | V_344 ) ;
break;
case V_249 :
case V_247 :
case V_248 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_241 :
case V_240 :
case V_237 :
case V_236 :
case V_238 :
case V_239 :
case V_17 :
F_23 ( V_2 , 0x0e , 0x0200 ) ;
default:
F_23 ( V_2 , V_67 , V_344 ) ;
break;
}
}
static void F_173 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
if ( ( V_2 -> V_16 == V_238 ||
V_2 -> V_16 == V_239 ||
V_2 -> V_16 == V_17 ) &&
F_12 ( V_2 ) ) {
return;
}
if ( ( V_2 -> V_16 == V_241 ||
V_2 -> V_16 == V_240 ) &&
( F_38 ( V_64 ) & V_345 ) ) {
return;
}
if ( V_2 -> V_16 == V_235 ||
V_2 -> V_16 == V_234 )
F_30 ( V_5 , 0x19 , 0xff64 ) ;
if ( F_56 ( V_2 ) & V_98 ) {
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_67 , 0x0000 ) ;
F_2 ( V_346 , F_4 ( V_346 ) |
V_347 | V_348 | V_349 ) ;
return;
}
F_172 ( V_2 ) ;
switch ( V_2 -> V_16 ) {
case V_237 :
case V_236 :
case V_238 :
case V_239 :
case V_17 :
case V_235 :
case V_234 :
F_7 ( V_350 , F_43 ( V_350 ) & ~ 0x80 ) ;
break;
}
}
static void F_174 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
if ( ( V_2 -> V_16 == V_238 ||
V_2 -> V_16 == V_239 ||
V_2 -> V_16 == V_17 ) &&
F_12 ( V_2 ) ) {
return;
}
switch ( V_2 -> V_16 ) {
case V_237 :
case V_236 :
case V_238 :
case V_239 :
case V_17 :
case V_235 :
case V_234 :
F_7 ( V_350 , F_43 ( V_350 ) | 0x80 ) ;
break;
}
F_171 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 ,
void (* F_176)( struct V_1 * ) )
{
if ( F_176 )
F_176 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
F_175 ( V_2 , V_2 -> V_351 . V_352 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_175 ( V_2 , V_2 -> V_351 . V_353 ) ;
}
static void T_8 F_179 ( struct V_1 * V_2 )
{
struct V_351 * V_343 = & V_2 -> V_351 ;
switch ( V_2 -> V_16 ) {
case V_254 :
case V_253 :
case V_252 :
case V_256 :
case V_257 :
case V_251 :
case V_250 :
V_343 -> V_352 = F_169 ;
V_343 -> V_353 = F_170 ;
break;
case V_249 :
case V_247 :
case V_248 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_241 :
case V_240 :
case V_237 :
case V_236 :
case V_238 :
case V_239 :
case V_17 :
case V_235 :
case V_234 :
V_343 -> V_352 = F_173 ;
V_343 -> V_353 = F_174 ;
break;
default:
V_343 -> V_352 = NULL ;
V_343 -> V_353 = NULL ;
break;
}
}
static void F_180 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_7 ( V_63 , V_354 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ( F_43 ( V_63 ) & V_354 ) == 0 )
break;
F_181 ( 1 ) ;
}
}
static int T_8
F_182 ( struct V_76 * V_296 , const struct V_355 * V_356 )
{
const struct V_337 * V_100 = V_357 + V_356 -> V_358 ;
const unsigned int V_359 = V_100 -> V_359 ;
struct V_1 * V_2 ;
struct V_360 * V_152 ;
struct V_39 * V_40 ;
void T_4 * V_5 ;
int V_361 , V_7 ;
int V_135 ;
if ( F_183 ( & V_362 ) ) {
F_184 ( V_363 L_18 ,
V_112 , V_114 ) ;
}
V_40 = F_185 ( sizeof ( * V_2 ) ) ;
if ( ! V_40 ) {
if ( F_183 ( & V_362 ) )
F_186 ( & V_296 -> V_40 , L_19 ) ;
V_135 = - V_364 ;
goto V_156;
}
F_187 ( V_40 , & V_296 -> V_40 ) ;
V_40 -> V_365 = & V_366 ;
V_2 = F_28 ( V_40 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_76 = V_296 ;
V_2 -> V_199 = F_188 ( V_362 . V_199 , V_367 ) ;
V_152 = & V_2 -> V_152 ;
V_152 -> V_40 = V_40 ;
V_152 -> V_368 = F_29 ;
V_152 -> V_369 = F_27 ;
V_152 -> V_370 = 0x1f ;
V_152 -> V_371 = 0x1f ;
V_152 -> V_153 = ! ! ( V_100 -> V_105 & V_372 ) ;
F_189 ( V_296 , V_373 | V_374 |
V_375 ) ;
V_135 = F_190 ( V_296 ) ;
if ( V_135 < 0 ) {
F_112 ( V_2 , V_266 , V_40 , L_20 ) ;
goto V_376;
}
if ( F_191 ( V_296 ) < 0 )
F_51 ( V_2 , V_266 , V_40 , L_21 ) ;
if ( ! ( F_192 ( V_296 , V_359 ) & V_377 ) ) {
F_112 ( V_2 , V_266 , V_40 ,
L_22 ,
V_359 ) ;
V_135 = - V_330 ;
goto V_378;
}
if ( F_193 ( V_296 , V_359 ) < V_118 ) {
F_112 ( V_2 , V_266 , V_40 ,
L_23 ) ;
V_135 = - V_330 ;
goto V_378;
}
V_135 = F_194 ( V_296 , V_112 ) ;
if ( V_135 < 0 ) {
F_112 ( V_2 , V_266 , V_40 , L_24 ) ;
goto V_378;
}
V_2 -> V_175 = V_176 ;
if ( ( sizeof( T_5 ) > 4 ) &&
! F_195 ( V_296 , F_99 ( 64 ) ) && V_379 ) {
V_2 -> V_175 |= V_380 ;
V_40 -> V_105 |= V_381 ;
} else {
V_135 = F_195 ( V_296 , F_99 ( 32 ) ) ;
if ( V_135 < 0 ) {
F_112 ( V_2 , V_266 , V_40 , L_25 ) ;
goto V_382;
}
}
V_5 = F_196 ( F_197 ( V_296 , V_359 ) , V_118 ) ;
if ( ! V_5 ) {
F_112 ( V_2 , V_266 , V_40 , L_26 ) ;
V_135 = - V_383 ;
goto V_382;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_384 = F_198 ( V_296 , V_385 ) ;
if ( ! V_2 -> V_384 )
F_51 ( V_2 , V_266 , V_40 , L_27 ) ;
F_36 ( V_61 , 0x0000 ) ;
F_180 ( V_2 ) ;
F_36 ( V_62 , 0xffff ) ;
F_199 ( V_296 ) ;
F_106 ( V_2 , V_40 , V_100 -> V_386 ) ;
if ( V_2 -> V_16 == V_261 )
V_2 -> V_175 |= V_178 ;
F_166 ( V_2 ) ;
F_179 ( V_2 ) ;
F_108 ( V_2 ) ;
V_361 = V_2 -> V_16 ;
V_2 -> V_387 = V_107 [ V_361 ] . V_387 ;
F_7 ( V_102 , V_103 ) ;
F_7 ( V_81 , F_43 ( V_81 ) | V_82 ) ;
F_7 ( V_88 , F_43 ( V_88 ) & V_388 ) ;
if ( ( F_43 ( V_83 ) & ( V_84 | V_86 ) ) != 0 )
V_2 -> V_105 |= V_106 ;
if ( ( F_43 ( V_88 ) & ( V_89 | V_91 | V_93 ) ) != 0 )
V_2 -> V_105 |= V_106 ;
V_2 -> V_105 |= F_161 ( V_296 , V_5 , V_100 ) ;
F_7 ( V_102 , V_104 ) ;
if ( ( V_2 -> V_16 <= V_260 ) &&
( F_43 ( V_70 ) & V_316 ) ) {
V_2 -> V_166 = F_69 ;
V_2 -> V_195 = F_87 ;
V_2 -> V_312 = F_44 ;
V_2 -> V_308 = F_39 ;
V_2 -> V_75 = F_41 ;
V_2 -> V_329 = F_160 ;
} else {
V_2 -> V_166 = F_71 ;
V_2 -> V_195 = F_89 ;
V_2 -> V_312 = F_45 ;
V_2 -> V_308 = F_40 ;
V_2 -> V_75 = F_42 ;
V_2 -> V_329 = F_159 ;
}
F_200 ( & V_2 -> V_74 ) ;
for ( V_7 = 0 ; V_7 < V_389 ; V_7 ++ )
V_40 -> V_324 [ V_7 ] = F_43 ( V_320 + V_7 ) ;
memcpy ( V_40 -> V_390 , V_40 -> V_324 , V_40 -> V_325 ) ;
F_201 ( V_40 , & V_391 ) ;
V_40 -> V_392 = V_393 ;
V_40 -> V_313 = V_296 -> V_313 ;
V_40 -> V_394 = ( unsigned long ) V_5 ;
F_202 ( V_40 , & V_2 -> V_395 , V_396 , V_397 ) ;
V_40 -> V_105 |= V_174 |
V_398 | V_177 ;
V_40 -> V_399 = V_400 | V_401 | V_402 |
V_174 | V_398 | V_177 ;
V_40 -> V_403 = V_400 | V_401 | V_402 |
V_381 ;
if ( V_2 -> V_16 == V_261 )
V_40 -> V_399 &= ~ V_177 ;
V_2 -> V_404 = 0xffff ;
V_2 -> V_405 = V_100 -> V_405 ;
V_2 -> V_406 = V_100 -> V_406 ;
V_2 -> V_407 = V_100 -> V_407 ;
F_203 ( & V_2 -> V_167 ) ;
V_2 -> V_167 . V_11 = ( unsigned long ) V_40 ;
V_2 -> V_167 . V_408 = F_140 ;
V_2 -> V_117 = V_293 ;
V_135 = F_204 ( V_40 ) ;
if ( V_135 < 0 )
goto V_409;
F_205 ( V_296 , V_40 ) ;
F_51 ( V_2 , V_266 , V_40 , L_28 ,
V_107 [ V_361 ] . V_410 , V_40 -> V_394 , V_40 -> V_324 ,
( T_1 ) ( F_4 ( V_265 ) & 0x9cf0f8ff ) , V_40 -> V_313 ) ;
if ( V_2 -> V_16 == V_238 ||
V_2 -> V_16 == V_239 ||
V_2 -> V_16 == V_17 ) {
F_10 ( V_2 ) ;
}
F_63 ( & V_296 -> V_40 , V_2 -> V_105 & V_106 ) ;
if ( F_206 ( V_296 ) )
F_207 ( & V_296 -> V_40 ) ;
F_52 ( V_40 ) ;
V_156:
return V_135 ;
V_409:
F_164 ( V_296 , V_2 ) ;
F_146 ( V_5 ) ;
V_382:
F_147 ( V_296 ) ;
V_378:
F_148 ( V_296 ) ;
F_149 ( V_296 ) ;
V_376:
F_150 ( V_40 ) ;
goto V_156;
}
static void T_9 F_208 ( struct V_76 * V_296 )
{
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( V_2 -> V_16 == V_238 ||
V_2 -> V_16 == V_239 ||
V_2 -> V_16 == V_17 ) {
F_11 ( V_2 ) ;
}
F_210 ( & V_2 -> V_411 ) ;
F_211 ( V_40 ) ;
F_114 ( V_2 ) ;
if ( F_206 ( V_296 ) )
F_212 ( & V_296 -> V_40 ) ;
F_154 ( V_2 , V_40 -> V_390 ) ;
F_164 ( V_296 , V_2 ) ;
F_145 ( V_296 , V_40 , V_2 -> V_6 ) ;
F_205 ( V_296 , NULL ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
if ( F_214 ( V_2 -> V_117 ) ) {
const char * V_410 ;
V_410 = F_64 ( V_2 ) ;
if ( V_410 ) {
int V_135 ;
V_135 = F_215 ( & V_2 -> V_117 , V_410 , & V_2 -> V_76 -> V_40 ) ;
if ( V_135 >= 0 )
return;
F_70 ( V_2 , V_77 , V_2 -> V_40 , L_29
L_30 , V_410 , V_135 ) ;
}
V_2 -> V_117 = NULL ;
}
}
static int F_216 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_76 * V_296 = V_2 -> V_76 ;
int V_412 = - V_364 ;
F_217 ( & V_296 -> V_40 ) ;
V_2 -> V_413 = F_98 ( & V_296 -> V_40 , V_414 ,
& V_2 -> V_415 , V_210 ) ;
if ( ! V_2 -> V_413 )
goto V_416;
V_2 -> V_417 = F_98 ( & V_296 -> V_40 , V_418 ,
& V_2 -> V_419 , V_210 ) ;
if ( ! V_2 -> V_417 )
goto V_420;
V_412 = F_218 ( V_40 ) ;
if ( V_412 < 0 )
goto V_421;
F_219 ( & V_2 -> V_411 , NULL ) ;
F_220 () ;
F_213 ( V_2 ) ;
V_412 = F_221 ( V_40 -> V_313 , F_143 ,
( V_2 -> V_105 & V_342 ) ? 0 : V_422 ,
V_40 -> V_410 , V_40 ) ;
if ( V_412 < 0 )
goto V_423;
F_222 ( & V_2 -> V_395 ) ;
F_152 ( V_40 , V_2 ) ;
F_79 ( V_40 , V_40 -> V_105 ) ;
F_178 ( V_2 ) ;
F_223 ( V_40 ) ;
V_2 -> V_424 = 0 ;
F_207 ( & V_296 -> V_40 ) ;
F_55 ( V_40 , V_2 , V_5 ) ;
V_156:
return V_412 ;
V_423:
F_114 ( V_2 ) ;
F_224 ( V_2 ) ;
V_421:
F_100 ( & V_296 -> V_40 , V_418 , V_2 -> V_417 ,
V_2 -> V_419 ) ;
V_2 -> V_417 = NULL ;
V_420:
F_100 ( & V_296 -> V_40 , V_414 , V_2 -> V_413 ,
V_2 -> V_415 ) ;
V_2 -> V_413 = NULL ;
V_416:
F_207 ( & V_296 -> V_40 ) ;
goto V_156;
}
static void F_225 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_35 ( V_5 ) ;
if ( V_2 -> V_16 == V_238 ||
V_2 -> V_16 == V_239 ||
V_2 -> V_16 == V_17 ) {
while ( F_43 ( V_425 ) & V_426 )
F_3 ( 20 ) ;
}
F_7 ( V_63 , V_354 ) ;
F_43 ( V_63 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
T_1 V_100 = V_427 ;
V_100 |= ( F_4 ( V_346 ) & V_428 ) ;
F_2 ( V_346 , V_100 ) ;
F_2 ( V_265 , ( V_429 << V_430 ) |
( V_431 << V_432 ) ) ;
}
static void F_223 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_180 ( V_2 ) ;
V_2 -> V_405 ( V_40 ) ;
F_227 ( V_40 ) ;
}
static void F_228 ( struct V_1 * V_2 ,
void T_4 * V_5 )
{
F_2 ( V_433 , ( ( V_212 ) V_2 -> V_415 ) >> 32 ) ;
F_2 ( V_434 , ( ( V_212 ) V_2 -> V_415 ) & F_99 ( 32 ) ) ;
F_2 ( V_435 , ( ( V_212 ) V_2 -> V_419 ) >> 32 ) ;
F_2 ( V_436 , ( ( V_212 ) V_2 -> V_419 ) & F_99 ( 32 ) ) ;
}
static T_3 F_229 ( void T_4 * V_5 )
{
T_3 V_12 ;
V_12 = F_38 ( V_64 ) ;
F_36 ( V_64 , V_12 ) ;
return V_12 ;
}
static void F_230 ( void T_4 * V_5 , unsigned int V_437 )
{
F_36 ( V_438 , V_437 + 1 ) ;
}
static void F_231 ( void T_4 * V_5 , unsigned V_16 )
{
static const struct V_439 {
T_1 V_16 ;
T_1 V_440 ;
T_1 V_33 ;
} V_441 [] = {
{ V_261 , V_442 , 0x000fff00 } ,
{ V_261 , V_443 , 0x000fffff } ,
{ V_260 , V_442 , 0x00ffff00 } ,
{ V_260 , V_443 , 0x00ffffff }
} ;
const struct V_439 * V_37 = V_441 ;
unsigned int V_7 ;
T_1 V_440 ;
V_440 = F_43 ( V_340 ) & V_443 ;
for ( V_7 = 0 ; V_7 < F_61 ( V_441 ) ; V_7 ++ , V_37 ++ ) {
if ( ( V_37 -> V_16 == V_16 ) && ( V_37 -> V_440 == V_440 ) ) {
F_2 ( 0x7c , V_37 -> V_33 ) ;
break;
}
}
}
static void F_232 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_76 * V_296 = V_2 -> V_76 ;
if ( V_2 -> V_16 == V_261 ) {
F_36 ( V_64 , F_38 ( V_64 ) | V_444 ) ;
F_153 ( V_296 , V_315 , 0x08 ) ;
}
F_7 ( V_102 , V_103 ) ;
if ( V_2 -> V_16 == V_263 ||
V_2 -> V_16 == V_163 ||
V_2 -> V_16 == V_164 ||
V_2 -> V_16 == V_262 )
F_7 ( V_63 , V_445 | V_209 ) ;
F_7 ( V_446 , V_447 ) ;
F_230 ( V_5 , V_437 ) ;
if ( V_2 -> V_16 == V_263 ||
V_2 -> V_16 == V_163 ||
V_2 -> V_16 == V_164 ||
V_2 -> V_16 == V_262 )
F_226 ( V_2 ) ;
V_2 -> V_175 |= F_229 ( V_5 ) | V_444 ;
if ( V_2 -> V_16 == V_163 ||
V_2 -> V_16 == V_164 ) {
F_109 ( L_31
L_32 ) ;
V_2 -> V_175 |= ( 1 << 14 ) ;
}
F_36 ( V_64 , V_2 -> V_175 ) ;
F_231 ( V_5 , V_2 -> V_16 ) ;
F_36 ( V_448 , 0x0000 ) ;
F_228 ( V_2 , V_5 ) ;
if ( V_2 -> V_16 != V_263 &&
V_2 -> V_16 != V_163 &&
V_2 -> V_16 != V_164 &&
V_2 -> V_16 != V_262 ) {
F_7 ( V_63 , V_445 | V_209 ) ;
F_226 ( V_2 ) ;
}
F_7 ( V_102 , V_104 ) ;
F_43 ( V_61 ) ;
F_2 ( V_449 , 0 ) ;
F_233 ( V_40 ) ;
F_36 ( V_450 , F_38 ( V_450 ) & 0xF000 ) ;
F_36 ( V_61 , V_2 -> V_406 ) ;
}
static void F_234 ( struct V_76 * V_296 , T_3 V_451 )
{
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_452 = V_2 -> V_384 ;
if ( V_452 ) {
T_3 V_453 ;
F_121 ( V_296 , V_452 + V_454 , & V_453 ) ;
V_453 = ( V_453 & ~ V_455 ) | V_451 ;
F_235 ( V_296 , V_452 + V_454 , V_453 ) ;
}
}
static void F_236 ( void T_4 * V_5 , T_1 V_456 )
{
T_1 V_457 ;
V_457 = F_33 ( V_5 , 0x070c ) & 0x00ffffff ;
F_32 ( V_5 , 0x070c , V_457 | V_456 ) ;
}
static void F_237 ( void T_4 * V_5 )
{
F_236 ( V_5 , 0x17000000 ) ;
}
static void F_238 ( void T_4 * V_5 )
{
F_236 ( V_5 , 0x27000000 ) ;
}
static void F_239 ( void T_4 * V_5 , const struct V_458 * V_459 , int V_198 )
{
T_3 V_460 ;
while ( V_198 -- > 0 ) {
V_460 = ( F_31 ( V_5 , V_459 -> V_461 ) & ~ V_459 -> V_3 ) | V_459 -> V_456 ;
F_30 ( V_5 , V_459 -> V_461 , V_460 ) ;
V_459 ++ ;
}
}
static void F_240 ( struct V_76 * V_296 )
{
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_452 = V_2 -> V_384 ;
if ( V_452 ) {
T_3 V_453 ;
F_121 ( V_296 , V_452 + V_462 , & V_453 ) ;
V_453 &= ~ V_463 ;
F_235 ( V_296 , V_452 + V_462 , V_453 ) ;
}
}
static void F_241 ( struct V_76 * V_296 )
{
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_452 = V_2 -> V_384 ;
if ( V_452 ) {
T_3 V_453 ;
F_121 ( V_296 , V_452 + V_462 , & V_453 ) ;
V_453 |= V_463 ;
F_235 ( V_296 , V_452 + V_462 , V_453 ) ;
}
}
static void F_242 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
F_36 ( V_64 , F_38 ( V_64 ) & ~ V_465 ) ;
F_234 ( V_296 ,
( 0x5 << V_466 ) | V_467 ) ;
}
static void F_243 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_242 ( V_5 , V_296 ) ;
F_7 ( V_468 , V_469 ) ;
F_7 ( V_470 , F_43 ( V_470 ) & ~ ( 1 << 0 ) ) ;
}
static void F_244 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_7 ( V_81 , F_43 ( V_81 ) | V_471 ) ;
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_240 ( V_296 ) ;
F_36 ( V_64 , F_38 ( V_64 ) & ~ V_465 ) ;
}
static void F_245 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_472 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0042 } ,
{ 0x06 , 0x0080 , 0x0000 } ,
{ 0x07 , 0 , 0x2000 }
} ;
F_238 ( V_5 ) ;
F_239 ( V_5 , V_472 , F_61 ( V_472 ) ) ;
F_244 ( V_5 , V_296 ) ;
}
static void F_246 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_238 ( V_5 ) ;
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_36 ( V_64 , F_38 ( V_64 ) & ~ V_465 ) ;
}
static void F_247 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_238 ( V_5 ) ;
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
F_7 ( V_473 , 0x20 ) ;
F_7 ( V_468 , V_469 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_36 ( V_64 , F_38 ( V_64 ) & ~ V_465 ) ;
}
static void F_248 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_474 [] = {
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0002 } ,
{ 0x06 , 0x0080 , 0x0000 }
} ;
F_238 ( V_5 ) ;
F_7 ( V_473 , 0x06 | V_475 | V_476 ) ;
F_239 ( V_5 , V_474 , F_61 ( V_474 ) ) ;
F_244 ( V_5 , V_296 ) ;
}
static void F_249 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_477 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x03 , 0x0400 , 0x0220 }
} ;
F_238 ( V_5 ) ;
F_239 ( V_5 , V_477 , F_61 ( V_477 ) ) ;
F_244 ( V_5 , V_296 ) ;
}
static void F_250 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_249 ( V_5 , V_296 ) ;
}
static void F_251 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_238 ( V_5 ) ;
F_244 ( V_5 , V_296 ) ;
}
static void F_252 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_238 ( V_5 ) ;
F_240 ( V_296 ) ;
F_7 ( V_468 , V_469 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_36 ( V_64 , F_38 ( V_64 ) & ~ V_465 ) ;
}
static void F_253 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_237 ( V_5 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_7 ( V_468 , V_469 ) ;
F_240 ( V_296 ) ;
}
static void F_254 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_478 [] = {
{ 0x0b , ~ 0 , 0x48 } ,
{ 0x19 , 0x20 , 0x50 } ,
{ 0x0c , ~ 0 , 0x20 }
} ;
int V_7 ;
F_237 ( V_5 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_7 ( V_468 , V_469 ) ;
for ( V_7 = 0 ; V_7 < F_61 ( V_478 ) ; V_7 ++ ) {
const struct V_458 * V_459 = V_478 + V_7 ;
T_3 V_460 ;
V_460 = F_31 ( V_5 , V_459 -> V_461 ) ;
F_30 ( V_5 , 0x03 , ( V_460 & V_459 -> V_3 ) | V_459 -> V_456 ) ;
}
F_241 ( V_296 ) ;
}
static void F_255 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_479 [] = {
{ 0x00 , 0x0200 , 0x0100 } ,
{ 0x00 , 0x0000 , 0x0004 } ,
{ 0x06 , 0x0002 , 0x0001 } ,
{ 0x06 , 0x0000 , 0x0030 } ,
{ 0x07 , 0x0000 , 0x2000 } ,
{ 0x00 , 0x0000 , 0x0020 } ,
{ 0x03 , 0x5800 , 0x2000 } ,
{ 0x03 , 0x0000 , 0x0001 } ,
{ 0x01 , 0x0800 , 0x1000 } ,
{ 0x07 , 0x0000 , 0x4000 } ,
{ 0x1e , 0x0000 , 0x2000 } ,
{ 0x19 , 0xffff , 0xfe6c } ,
{ 0x0a , 0x0000 , 0x0040 }
} ;
F_238 ( V_5 ) ;
F_239 ( V_5 , V_479 , F_61 ( V_479 ) ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_7 ( V_468 , V_469 ) ;
F_240 ( V_296 ) ;
F_2 ( V_480 , F_4 ( V_480 ) | V_481 ) ;
F_2 ( V_480 , F_4 ( V_480 ) & ~ V_481 ) ;
F_7 ( V_88 , F_43 ( V_88 ) & ~ V_482 ) ;
}
static void F_256 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_76 * V_296 = V_2 -> V_76 ;
F_7 ( V_102 , V_103 ) ;
F_7 ( V_468 , V_469 ) ;
F_230 ( V_5 , V_437 ) ;
V_2 -> V_175 |= F_38 ( V_64 ) | V_483 | V_484 ;
F_36 ( V_64 , V_2 -> V_175 ) ;
F_36 ( V_448 , 0x5151 ) ;
if ( V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_246 ) {
V_2 -> V_406 |= V_485 | V_486 ;
V_2 -> V_406 &= ~ V_487 ;
}
F_228 ( V_2 , V_5 ) ;
F_233 ( V_40 ) ;
F_2 ( V_265 , ( V_429 << V_430 ) |
( V_431 << V_432 ) ) ;
F_43 ( V_61 ) ;
switch ( V_2 -> V_16 ) {
case V_249 :
F_242 ( V_5 , V_296 ) ;
break;
case V_247 :
case V_248 :
F_243 ( V_5 , V_296 ) ;
break;
case V_242 :
F_245 ( V_5 , V_296 ) ;
break;
case V_243 :
F_248 ( V_5 , V_296 ) ;
break;
case V_244 :
F_249 ( V_5 , V_296 ) ;
break;
case V_245 :
F_250 ( V_5 , V_296 ) ;
break;
case V_246 :
F_251 ( V_5 , V_296 ) ;
break;
case V_241 :
F_246 ( V_5 , V_296 ) ;
break;
case V_240 :
F_247 ( V_5 , V_296 ) ;
break;
case V_237 :
case V_236 :
case V_238 :
F_252 ( V_5 , V_296 ) ;
break;
case V_239 :
F_254 ( V_5 , V_296 ) ;
break;
case V_17 :
F_253 ( V_5 , V_296 ) ;
break;
case V_235 :
case V_234 :
F_255 ( V_5 , V_296 ) ;
break;
default:
F_184 (KERN_ERR PFX L_33 ,
dev->name, tp->mac_version) ;
break;
}
F_7 ( V_63 , V_445 | V_209 ) ;
F_7 ( V_102 , V_104 ) ;
F_36 ( V_450 , F_38 ( V_450 ) & 0xF000 ) ;
F_36 ( V_61 , V_2 -> V_406 ) ;
}
static void F_257 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_488 [] = {
{ 0x01 , 0 , 0x6e65 } ,
{ 0x02 , 0 , 0x091f } ,
{ 0x03 , 0 , 0xc2f9 } ,
{ 0x06 , 0 , 0xafb5 } ,
{ 0x07 , 0 , 0x0e00 } ,
{ 0x19 , 0 , 0xec80 } ,
{ 0x01 , 0 , 0x2e65 } ,
{ 0x01 , 0 , 0x6e65 }
} ;
T_2 V_489 ;
F_238 ( V_5 ) ;
F_7 ( V_473 , V_475 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_7 ( V_81 ,
V_490 | V_491 | V_471 | V_492 | V_493 | V_494 | V_82 ) ;
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
V_489 = F_43 ( V_81 ) ;
if ( ( V_489 & V_491 ) && ( V_489 & V_490 ) )
F_7 ( V_81 , V_489 & ~ V_491 ) ;
F_239 ( V_5 , V_488 , F_61 ( V_488 ) ) ;
}
static void F_258 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_238 ( V_5 ) ;
F_234 ( V_296 , 0x5 << V_466 ) ;
F_7 ( V_81 , V_492 | V_493 | V_494 | V_82 ) ;
F_7 ( V_83 , F_43 ( V_83 ) & ~ V_464 ) ;
}
static void F_259 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_258 ( V_5 , V_296 ) ;
F_30 ( V_5 , 0x03 , 0xc2f9 ) ;
}
static void F_260 ( void T_4 * V_5 , struct V_76 * V_296 )
{
static const struct V_458 V_495 [] = {
{ 0x07 , 0 , 0x4000 } ,
{ 0x19 , 0 , 0x0200 } ,
{ 0x19 , 0 , 0x0020 } ,
{ 0x1e , 0 , 0x2000 } ,
{ 0x03 , 0 , 0x0001 } ,
{ 0x19 , 0 , 0x0100 } ,
{ 0x19 , 0 , 0x0004 } ,
{ 0x0a , 0 , 0x0020 }
} ;
F_2 ( V_496 , F_4 ( V_496 ) | 0x002800 ) ;
F_2 ( V_496 , F_4 ( V_496 ) & ~ 0x010000 ) ;
F_7 ( V_497 , F_43 ( V_497 ) | V_498 | V_499 ) ;
F_7 ( V_500 , F_43 ( V_500 ) | V_501 ) ;
F_239 ( V_5 , V_495 , F_61 ( V_495 ) ) ;
}
static void F_261 ( void T_4 * V_5 , struct V_76 * V_296 )
{
F_260 ( V_5 , V_296 ) ;
F_30 ( V_5 , 0x1e , F_31 ( V_5 , 0x1e ) | 0x8000 ) ;
}
static void F_262 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_76 * V_296 = V_2 -> V_76 ;
if ( V_2 -> V_16 == V_255 ||
V_2 -> V_16 == V_257 ) {
int V_452 = V_2 -> V_384 ;
if ( V_452 ) {
F_235 ( V_296 , V_452 + V_454 ,
V_467 ) ;
}
}
F_7 ( V_102 , V_103 ) ;
switch ( V_2 -> V_16 ) {
case V_254 :
F_257 ( V_5 , V_296 ) ;
break;
case V_253 :
F_259 ( V_5 , V_296 ) ;
break;
case V_252 :
F_258 ( V_5 , V_296 ) ;
break;
case V_251 :
F_260 ( V_5 , V_296 ) ;
break;
case V_250 :
F_261 ( V_5 , V_296 ) ;
break;
}
F_7 ( V_102 , V_104 ) ;
F_7 ( V_468 , V_469 ) ;
F_230 ( V_5 , V_437 ) ;
V_2 -> V_175 &= ~ V_502 ;
F_36 ( V_64 , V_2 -> V_175 ) ;
F_36 ( V_448 , 0x0000 ) ;
F_228 ( V_2 , V_5 ) ;
F_7 ( V_63 , V_445 | V_209 ) ;
F_226 ( V_2 ) ;
F_43 ( V_61 ) ;
F_233 ( V_40 ) ;
F_36 ( V_450 , F_38 ( V_450 ) & 0xf000 ) ;
F_36 ( V_61 , V_2 -> V_406 ) ;
}
static int F_263 ( struct V_39 * V_40 , int V_503 )
{
if ( V_503 < V_504 || V_503 > V_505 )
return - V_136 ;
V_40 -> V_171 = V_503 ;
F_264 ( V_40 ) ;
return 0 ;
}
static inline void F_265 ( struct V_182 * V_183 )
{
V_183 -> V_48 = F_266 ( 0x0badbadbadbadbadull ) ;
V_183 -> V_506 &= ~ F_267 ( V_507 | V_508 ) ;
}
static void F_268 ( struct V_1 * V_2 ,
void * * V_509 , struct V_182 * V_183 )
{
F_269 ( & V_2 -> V_76 -> V_40 , F_103 ( V_183 -> V_48 ) , V_437 ,
V_510 ) ;
F_270 ( * V_509 ) ;
* V_509 = NULL ;
F_265 ( V_183 ) ;
}
static inline void F_271 ( struct V_182 * V_183 , T_1 V_437 )
{
T_1 V_511 = F_85 ( V_183 -> V_506 ) & V_512 ;
V_183 -> V_506 = F_267 ( V_507 | V_511 | V_437 ) ;
}
static inline void F_272 ( struct V_182 * V_183 , T_5 V_513 ,
T_1 V_437 )
{
V_183 -> V_48 = F_266 ( V_513 ) ;
F_273 () ;
F_271 ( V_183 , V_437 ) ;
}
static inline void * F_274 ( void * V_11 )
{
return ( void * ) F_275 ( ( long ) V_11 , 16 ) ;
}
static struct V_179 * F_276 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
void * V_11 ;
T_5 V_513 ;
struct V_203 * V_204 = & V_2 -> V_76 -> V_40 ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_514 = V_40 -> V_40 . V_515 ? F_277 ( V_40 -> V_40 . V_515 ) : - 1 ;
V_11 = F_278 ( V_437 , V_210 , V_514 ) ;
if ( ! V_11 )
return NULL ;
if ( F_274 ( V_11 ) != V_11 ) {
F_270 ( V_11 ) ;
V_11 = F_278 ( V_437 + 15 , V_210 , V_514 ) ;
if ( ! V_11 )
return NULL ;
}
V_513 = F_279 ( V_204 , F_274 ( V_11 ) , V_437 ,
V_510 ) ;
if ( F_280 ( F_281 ( V_204 , V_513 ) ) ) {
if ( F_50 () )
F_112 ( V_2 , V_516 , V_2 -> V_40 , L_34 ) ;
goto V_517;
}
F_272 ( V_183 , V_513 , V_437 ) ;
return V_11 ;
V_517:
F_270 ( V_11 ) ;
return NULL ;
}
static void F_224 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_518 ; V_7 ++ ) {
if ( V_2 -> V_519 [ V_7 ] ) {
F_268 ( V_2 , V_2 -> V_519 + V_7 ,
V_2 -> V_417 + V_7 ) ;
}
}
}
static inline void F_282 ( struct V_182 * V_183 )
{
V_183 -> V_506 |= F_267 ( V_512 ) ;
}
static int F_283 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_518 ; V_7 ++ ) {
void * V_11 ;
if ( V_2 -> V_519 [ V_7 ] )
continue;
V_11 = F_276 ( V_2 , V_2 -> V_417 + V_7 ) ;
if ( ! V_11 ) {
F_265 ( V_2 -> V_417 + V_7 ) ;
goto V_517;
}
V_2 -> V_519 [ V_7 ] = V_11 ;
}
F_282 ( V_2 -> V_417 + V_518 - 1 ) ;
return 0 ;
V_517:
F_224 ( V_2 ) ;
return - V_364 ;
}
static void F_284 ( struct V_1 * V_2 )
{
V_2 -> V_520 = V_2 -> V_521 = V_2 -> V_522 = V_2 -> V_523 = 0 ;
}
static int F_218 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_284 ( V_2 ) ;
memset ( V_2 -> V_524 , 0x0 , V_525 * sizeof( struct V_526 ) ) ;
memset ( V_2 -> V_519 , 0x0 , V_518 * sizeof( void * ) ) ;
return F_283 ( V_2 ) ;
}
static void F_285 ( struct V_203 * V_204 , struct V_526 * V_524 ,
struct V_527 * V_183 )
{
unsigned int V_198 = V_524 -> V_198 ;
F_269 ( V_204 , F_103 ( V_183 -> V_48 ) , V_198 , V_528 ) ;
V_183 -> V_506 = 0x00 ;
V_183 -> V_184 = 0x00 ;
V_183 -> V_48 = 0x00 ;
V_524 -> V_198 = 0 ;
}
static void F_286 ( struct V_1 * V_2 , T_1 V_529 ,
unsigned int V_530 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_530 ; V_7 ++ ) {
unsigned int V_531 = ( V_529 + V_7 ) % V_525 ;
struct V_526 * V_524 = V_2 -> V_524 + V_531 ;
unsigned int V_198 = V_524 -> V_198 ;
if ( V_198 ) {
struct V_179 * V_180 = V_524 -> V_180 ;
F_285 ( & V_2 -> V_76 -> V_40 , V_524 ,
V_2 -> V_413 + V_531 ) ;
if ( V_180 ) {
V_2 -> V_40 -> V_216 . V_532 ++ ;
F_287 ( V_180 ) ;
V_524 -> V_180 = NULL ;
}
}
}
}
static void F_288 ( struct V_1 * V_2 )
{
F_286 ( V_2 , V_2 -> V_520 , V_525 ) ;
V_2 -> V_522 = V_2 -> V_520 = 0 ;
}
static void F_289 ( struct V_39 * V_40 , T_10 V_411 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_290 ( & V_2 -> V_411 , V_411 ) ;
F_291 ( & V_2 -> V_411 , 4 ) ;
}
static void F_292 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
F_293 ( V_40 -> V_313 ) ;
F_294 ( & V_2 -> V_395 ) ;
F_35 ( V_5 ) ;
V_2 -> V_404 = 0xffff ;
F_36 ( V_61 , V_2 -> V_406 ) ;
F_222 ( & V_2 -> V_395 ) ;
}
static void F_295 ( struct V_533 * V_534 )
{
struct V_1 * V_2 =
F_296 ( V_534 , struct V_1 , V_411 . V_534 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_123 ;
F_297 () ;
if ( ! F_73 ( V_40 ) )
goto V_311;
F_292 ( V_40 ) ;
F_298 ( V_40 ) ;
V_123 = F_216 ( V_40 ) ;
if ( F_280 ( V_123 < 0 ) ) {
if ( F_50 () )
F_112 ( V_2 , V_516 , V_40 ,
L_35 ,
V_123 ) ;
F_289 ( V_40 , F_295 ) ;
}
V_311:
F_299 () ;
}
static void F_300 ( struct V_533 * V_534 )
{
struct V_1 * V_2 =
F_296 ( V_534 , struct V_1 , V_411 . V_534 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_7 ;
F_297 () ;
if ( ! F_73 ( V_40 ) )
goto V_311;
F_292 ( V_40 ) ;
for ( V_7 = 0 ; V_7 < V_518 ; V_7 ++ )
F_271 ( V_2 -> V_417 + V_7 , V_437 ) ;
F_288 ( V_2 ) ;
F_284 ( V_2 ) ;
F_223 ( V_40 ) ;
F_301 ( V_40 ) ;
F_55 ( V_40 , V_2 , V_2 -> V_6 ) ;
V_311:
F_299 () ;
}
static void F_302 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_225 ( V_2 ) ;
F_289 ( V_40 , F_300 ) ;
}
static int F_303 ( struct V_1 * V_2 , struct V_179 * V_180 ,
T_1 * V_535 )
{
struct V_536 * V_110 = F_304 ( V_180 ) ;
unsigned int V_537 , V_531 ;
struct V_527 * V_538 ( V_539 ) ;
struct V_203 * V_204 = & V_2 -> V_76 -> V_40 ;
V_531 = V_2 -> V_522 ;
for ( V_537 = 0 ; V_537 < V_110 -> V_540 ; V_537 ++ ) {
T_11 * V_541 = V_110 -> V_542 + V_537 ;
T_5 V_513 ;
T_1 V_186 , V_198 ;
void * V_48 ;
V_531 = ( V_531 + 1 ) % V_525 ;
V_539 = V_2 -> V_413 + V_531 ;
V_198 = V_541 -> V_272 ;
V_48 = ( ( void * ) F_305 ( V_541 -> V_543 ) ) + V_541 -> V_544 ;
V_513 = F_279 ( V_204 , V_48 , V_198 , V_528 ) ;
if ( F_280 ( F_281 ( V_204 , V_513 ) ) ) {
if ( F_50 () )
F_112 ( V_2 , V_516 , V_2 -> V_40 ,
L_36 ) ;
goto V_517;
}
V_186 = V_535 [ 0 ] | V_198 |
( V_512 * ! ( ( V_531 + 1 ) % V_525 ) ) ;
V_539 -> V_506 = F_267 ( V_186 ) ;
V_539 -> V_184 = F_267 ( V_535 [ 1 ] ) ;
V_539 -> V_48 = F_266 ( V_513 ) ;
V_2 -> V_524 [ V_531 ] . V_198 = V_198 ;
}
if ( V_537 ) {
V_2 -> V_524 [ V_531 ] . V_180 = V_180 ;
V_539 -> V_506 |= F_267 ( V_545 ) ;
}
return V_537 ;
V_517:
F_286 ( V_2 , V_2 -> V_522 + 1 , V_537 ) ;
return - V_383 ;
}
static inline void F_306 ( struct V_1 * V_2 ,
struct V_179 * V_180 , T_1 * V_535 )
{
const struct V_546 * V_110 = V_547 + V_2 -> V_387 ;
T_1 V_548 = F_304 ( V_180 ) -> V_549 ;
int V_461 = V_110 -> V_550 ;
if ( V_548 ) {
V_535 [ 0 ] |= V_551 ;
V_535 [ V_461 ] |= F_307 ( V_548 , V_172 ) << V_110 -> V_552 ;
} else if ( V_180 -> V_553 == V_554 ) {
const struct V_555 * V_556 = F_308 ( V_180 ) ;
if ( V_556 -> V_557 == V_558 )
V_535 [ V_461 ] |= V_110 -> V_559 . V_560 ;
else if ( V_556 -> V_557 == V_561 )
V_535 [ V_461 ] |= V_110 -> V_559 . V_562 ;
else
F_309 ( 1 ) ;
}
}
static T_12 F_310 ( struct V_179 * V_180 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned int V_531 = V_2 -> V_522 % V_525 ;
struct V_527 * V_539 = V_2 -> V_413 + V_531 ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_203 * V_204 = & V_2 -> V_76 -> V_40 ;
T_5 V_513 ;
T_1 V_186 , V_198 ;
T_1 V_535 [ 2 ] ;
int V_542 ;
if ( F_280 ( F_311 ( V_2 ) < F_304 ( V_180 ) -> V_540 ) ) {
F_112 ( V_2 , V_516 , V_40 , L_37 ) ;
goto V_563;
}
if ( F_280 ( F_85 ( V_539 -> V_506 ) & V_507 ) )
goto V_563;
V_198 = F_312 ( V_180 ) ;
V_513 = F_279 ( V_204 , V_180 -> V_11 , V_198 , V_528 ) ;
if ( F_280 ( F_281 ( V_204 , V_513 ) ) ) {
if ( F_50 () )
F_112 ( V_2 , V_516 , V_40 , L_38 ) ;
goto V_564;
}
V_2 -> V_524 [ V_531 ] . V_198 = V_198 ;
V_539 -> V_48 = F_266 ( V_513 ) ;
V_535 [ 1 ] = F_267 ( F_80 ( V_2 , V_180 ) ) ;
V_535 [ 0 ] = V_507 ;
F_306 ( V_2 , V_180 , V_535 ) ;
V_542 = F_303 ( V_2 , V_180 , V_535 ) ;
if ( V_542 < 0 )
goto V_565;
else if ( V_542 )
V_535 [ 0 ] |= V_566 ;
else {
V_535 [ 0 ] |= V_566 | V_545 ;
V_2 -> V_524 [ V_531 ] . V_180 = V_180 ;
}
V_539 -> V_184 = F_267 ( V_535 [ 1 ] ) ;
F_273 () ;
V_186 = V_535 [ 0 ] | V_198 | ( V_512 * ! ( ( V_531 + 1 ) % V_525 ) ) ;
V_539 -> V_506 = F_267 ( V_186 ) ;
V_2 -> V_522 += V_542 + 1 ;
F_273 () ;
F_7 ( V_425 , V_426 ) ;
if ( F_311 ( V_2 ) < V_567 ) {
F_313 ( V_40 ) ;
F_314 () ;
if ( F_311 ( V_2 ) >= V_567 )
F_301 ( V_40 ) ;
}
return V_568 ;
V_565:
F_285 ( V_204 , V_2 -> V_524 + V_531 , V_539 ) ;
V_564:
F_287 ( V_180 ) ;
V_40 -> V_216 . V_532 ++ ;
return V_568 ;
V_563:
F_313 ( V_40 ) ;
V_40 -> V_216 . V_532 ++ ;
return V_569 ;
}
static void F_315 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_76 * V_296 = V_2 -> V_76 ;
T_3 V_570 , V_571 ;
F_121 ( V_296 , V_572 , & V_571 ) ;
F_121 ( V_296 , V_573 , & V_570 ) ;
F_112 ( V_2 , V_574 , V_40 , L_39 ,
V_571 , V_570 ) ;
if ( V_296 -> V_575 )
V_571 &= ~ V_576 ;
else
V_571 |= V_577 | V_576 ;
F_235 ( V_296 , V_572 , V_571 ) ;
F_235 ( V_296 , V_573 ,
V_570 & ( V_578 |
V_579 | V_580 |
V_581 | V_582 ) ) ;
if ( ( V_2 -> V_175 & V_380 ) && ! V_2 -> V_521 && ! V_2 -> V_523 ) {
void T_4 * V_5 = V_2 -> V_6 ;
F_51 ( V_2 , V_574 , V_40 , L_40 ) ;
V_2 -> V_175 &= ~ V_380 ;
F_36 ( V_64 , V_2 -> V_175 ) ;
V_40 -> V_105 &= ~ V_381 ;
}
F_225 ( V_2 ) ;
F_289 ( V_40 , F_295 ) ;
}
static void F_316 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 )
{
unsigned int V_520 , V_583 ;
V_520 = V_2 -> V_520 ;
F_314 () ;
V_583 = V_2 -> V_522 - V_520 ;
while ( V_583 > 0 ) {
unsigned int V_531 = V_520 % V_525 ;
struct V_526 * V_524 = V_2 -> V_524 + V_531 ;
T_1 V_186 ;
F_317 () ;
V_186 = F_85 ( V_2 -> V_413 [ V_531 ] . V_506 ) ;
if ( V_186 & V_507 )
break;
F_285 ( & V_2 -> V_76 -> V_40 , V_524 ,
V_2 -> V_413 + V_531 ) ;
if ( V_186 & V_545 ) {
V_40 -> V_216 . V_217 ++ ;
V_40 -> V_216 . V_584 += V_524 -> V_180 -> V_198 ;
F_287 ( V_524 -> V_180 ) ;
V_524 -> V_180 = NULL ;
}
V_520 ++ ;
V_583 -- ;
}
if ( V_2 -> V_520 != V_520 ) {
V_2 -> V_520 = V_520 ;
F_318 () ;
if ( F_319 ( V_40 ) &&
( F_311 ( V_2 ) >= V_567 ) ) {
F_301 ( V_40 ) ;
}
F_314 () ;
if ( V_2 -> V_522 != V_520 )
F_7 ( V_425 , V_426 ) ;
}
}
static inline int F_320 ( T_1 V_186 )
{
return ( V_186 & ( V_566 | V_545 ) ) != ( V_566 | V_545 ) ;
}
static inline void F_321 ( struct V_179 * V_180 , T_1 V_506 )
{
T_1 V_186 = V_506 & V_585 ;
if ( ( ( V_186 == V_586 ) && ! ( V_506 & V_587 ) ) ||
( ( V_186 == V_588 ) && ! ( V_506 & V_589 ) ) )
V_180 -> V_553 = V_590 ;
else
F_322 ( V_180 ) ;
}
static struct V_179 * F_323 ( void * V_11 ,
struct V_1 * V_2 ,
int V_591 ,
T_5 V_48 )
{
struct V_179 * V_180 ;
struct V_203 * V_204 = & V_2 -> V_76 -> V_40 ;
V_11 = F_274 ( V_11 ) ;
F_324 ( V_204 , V_48 , V_591 , V_510 ) ;
F_325 ( V_11 ) ;
V_180 = F_326 ( V_2 -> V_40 , V_591 ) ;
if ( V_180 )
memcpy ( V_180 -> V_11 , V_11 , V_591 ) ;
F_327 ( V_204 , V_48 , V_591 , V_510 ) ;
return V_180 ;
}
static int F_328 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 , T_1 V_592 )
{
unsigned int V_523 , V_593 ;
unsigned int V_274 ;
V_523 = V_2 -> V_523 ;
V_593 = V_518 + V_2 -> V_521 - V_523 ;
V_593 = F_307 ( V_593 , V_592 ) ;
for (; V_593 > 0 ; V_593 -- , V_523 ++ ) {
unsigned int V_531 = V_523 % V_518 ;
struct V_182 * V_183 = V_2 -> V_417 + V_531 ;
T_1 V_186 ;
F_317 () ;
V_186 = F_85 ( V_183 -> V_506 ) ;
if ( V_186 & V_507 )
break;
if ( F_280 ( V_186 & V_594 ) ) {
F_51 ( V_2 , V_595 , V_40 , L_41 ,
V_186 ) ;
V_40 -> V_216 . V_220 ++ ;
if ( V_186 & ( V_596 | V_597 ) )
V_40 -> V_216 . V_598 ++ ;
if ( V_186 & V_599 )
V_40 -> V_216 . V_600 ++ ;
if ( V_186 & V_601 ) {
F_289 ( V_40 , F_300 ) ;
V_40 -> V_216 . V_602 ++ ;
}
F_271 ( V_183 , V_437 ) ;
} else {
struct V_179 * V_180 ;
T_5 V_48 = F_103 ( V_183 -> V_48 ) ;
int V_591 = ( V_186 & 0x00001FFF ) - 4 ;
if ( F_280 ( F_320 ( V_186 ) ) ) {
V_40 -> V_216 . V_603 ++ ;
V_40 -> V_216 . V_598 ++ ;
F_271 ( V_183 , V_437 ) ;
continue;
}
V_180 = F_323 ( V_2 -> V_519 [ V_531 ] ,
V_2 , V_591 , V_48 ) ;
F_271 ( V_183 , V_437 ) ;
if ( ! V_180 ) {
V_40 -> V_216 . V_603 ++ ;
continue;
}
F_321 ( V_180 , V_186 ) ;
F_329 ( V_180 , V_591 ) ;
V_180 -> V_557 = F_330 ( V_180 , V_40 ) ;
F_84 ( V_183 , V_180 ) ;
F_331 ( & V_2 -> V_395 , V_180 ) ;
V_40 -> V_216 . V_604 += V_591 ;
V_40 -> V_216 . V_218 ++ ;
}
if ( ( V_183 -> V_184 & F_267 ( 0xfffe000 ) ) &&
( V_2 -> V_16 == V_261 ) ) {
V_183 -> V_184 = 0 ;
V_523 ++ ;
}
}
V_274 = V_523 - V_2 -> V_523 ;
V_2 -> V_523 = V_523 ;
V_2 -> V_521 += V_274 ;
return V_274 ;
}
static T_13 F_143 ( int V_313 , void * V_605 )
{
struct V_39 * V_40 = V_605 ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_606 = 0 ;
int V_186 ;
V_186 = F_38 ( V_62 ) ;
while ( V_186 && V_186 != 0xffff ) {
V_606 = 1 ;
if ( F_280 ( ! F_73 ( V_40 ) ) ) {
F_37 ( V_5 ) ;
break;
}
if ( F_280 ( V_186 & V_485 ) ) {
switch ( V_2 -> V_16 ) {
case V_249 :
case V_246 :
case V_236 :
F_313 ( V_40 ) ;
F_302 ( V_40 ) ;
goto V_607;
case V_248 :
case V_243 :
case V_244 :
case V_245 :
case V_241 :
case V_240 :
case V_238 :
case V_239 :
case V_17 :
case V_247 :
case V_237 :
if ( V_186 == V_485 )
goto V_607;
break;
default:
break;
}
}
if ( F_280 ( V_186 & V_608 ) ) {
F_315 ( V_40 ) ;
break;
}
if ( V_186 & V_609 )
F_46 ( V_40 , V_2 , V_5 , true ) ;
F_314 () ;
if ( V_186 & V_2 -> V_404 & V_2 -> V_407 ) {
F_36 ( V_61 , V_2 -> V_406 & ~ V_2 -> V_407 ) ;
V_2 -> V_404 = ~ V_2 -> V_407 ;
if ( F_332 ( F_333 ( & V_2 -> V_395 ) ) )
F_334 ( & V_2 -> V_395 ) ;
else
F_51 ( V_2 , V_574 , V_40 ,
L_42 , V_186 ) ;
}
F_36 ( V_62 ,
( V_186 & V_485 ) ? ( V_186 | V_487 ) : V_186 ) ;
V_186 = F_38 ( V_62 ) ;
}
V_607:
return F_335 ( V_606 ) ;
}
static int V_396 ( struct V_610 * V_395 , int V_592 )
{
struct V_1 * V_2 = F_296 ( V_395 , struct V_1 , V_395 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_611 ;
V_611 = F_328 ( V_40 , V_2 , V_5 , ( T_1 ) V_592 ) ;
F_316 ( V_40 , V_2 , V_5 ) ;
if ( V_611 < V_592 ) {
F_336 ( V_395 ) ;
V_2 -> V_404 = 0xffff ;
F_273 () ;
F_36 ( V_61 , V_2 -> V_406 ) ;
}
return V_611 ;
}
static void F_337 ( struct V_39 * V_40 , void T_4 * V_5 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( V_2 -> V_16 > V_260 )
return;
V_40 -> V_216 . V_612 += ( F_4 ( V_449 ) & 0xffffff ) ;
F_2 ( V_449 , 0 ) ;
}
static void F_338 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
F_76 ( & V_2 -> V_167 ) ;
F_313 ( V_40 ) ;
F_294 ( & V_2 -> V_395 ) ;
F_58 ( & V_2 -> V_74 ) ;
F_37 ( V_5 ) ;
F_337 ( V_40 , V_5 ) ;
F_59 ( & V_2 -> V_74 ) ;
F_293 ( V_40 -> V_313 ) ;
F_339 () ;
F_288 ( V_2 ) ;
F_224 ( V_2 ) ;
F_177 ( V_2 ) ;
}
static int F_298 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_76 * V_296 = V_2 -> V_76 ;
F_217 ( & V_296 -> V_40 ) ;
F_97 ( V_40 ) ;
F_338 ( V_40 ) ;
F_340 ( V_40 -> V_313 , V_40 ) ;
F_100 ( & V_296 -> V_40 , V_418 , V_2 -> V_417 ,
V_2 -> V_419 ) ;
F_100 ( & V_296 -> V_40 , V_414 , V_2 -> V_413 ,
V_2 -> V_415 ) ;
V_2 -> V_413 = NULL ;
V_2 -> V_417 = NULL ;
F_341 ( & V_296 -> V_40 ) ;
return 0 ;
}
static void F_233 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_73 ;
T_1 V_613 [ 2 ] ;
int V_614 ;
T_1 V_615 = 0 ;
if ( V_40 -> V_73 & V_616 ) {
F_107 ( V_2 , V_130 , V_40 , L_43 ) ;
V_614 =
V_347 | V_348 | V_349 |
V_617 ;
V_613 [ 1 ] = V_613 [ 0 ] = 0xffffffff ;
} else if ( ( F_342 ( V_40 ) > V_618 ) ||
( V_40 -> V_73 & V_619 ) ) {
V_614 = V_347 | V_348 | V_349 ;
V_613 [ 1 ] = V_613 [ 0 ] = 0xffffffff ;
} else {
struct V_620 * V_621 ;
V_614 = V_347 | V_349 ;
V_613 [ 1 ] = V_613 [ 0 ] = 0 ;
F_343 (ha, dev) {
int V_622 = F_344 ( V_623 , V_621 -> V_48 ) >> 26 ;
V_613 [ V_622 >> 5 ] |= 1 << ( V_622 & 31 ) ;
V_614 |= V_348 ;
}
}
F_47 ( & V_2 -> V_74 , V_73 ) ;
V_615 = V_427 | V_614 |
( F_4 ( V_346 ) & V_428 ) ;
if ( V_2 -> V_16 > V_260 ) {
T_1 V_11 = V_613 [ 0 ] ;
V_613 [ 0 ] = F_345 ( V_613 [ 1 ] ) ;
V_613 [ 1 ] = F_345 ( V_11 ) ;
}
F_2 ( V_624 + 4 , V_613 [ 1 ] ) ;
F_2 ( V_624 + 0 , V_613 [ 0 ] ) ;
F_2 ( V_346 , V_615 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
}
static struct V_625 * F_346 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_73 ;
if ( F_73 ( V_40 ) ) {
F_47 ( & V_2 -> V_74 , V_73 ) ;
F_337 ( V_40 , V_5 ) ;
F_54 ( & V_2 -> V_74 , V_73 ) ;
}
return & V_40 -> V_216 ;
}
static void F_347 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! F_73 ( V_40 ) )
return;
F_177 ( V_2 ) ;
F_348 ( V_40 ) ;
F_313 ( V_40 ) ;
}
static int F_349 ( struct V_203 * V_203 )
{
struct V_76 * V_296 = F_350 ( V_203 ) ;
struct V_39 * V_40 = F_209 ( V_296 ) ;
F_347 ( V_40 ) ;
return 0 ;
}
static void F_351 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_352 ( V_40 ) ;
F_178 ( V_2 ) ;
F_289 ( V_40 , F_300 ) ;
}
static int F_353 ( struct V_203 * V_203 )
{
struct V_76 * V_296 = F_350 ( V_203 ) ;
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_152 ( V_40 , V_2 ) ;
if ( F_73 ( V_40 ) )
F_351 ( V_40 ) ;
return 0 ;
}
static int F_354 ( struct V_203 * V_203 )
{
struct V_76 * V_296 = F_350 ( V_203 ) ;
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! V_2 -> V_413 )
return 0 ;
F_58 ( & V_2 -> V_74 ) ;
V_2 -> V_424 = F_56 ( V_2 ) ;
F_60 ( V_2 , V_98 ) ;
F_59 ( & V_2 -> V_74 ) ;
F_347 ( V_40 ) ;
return 0 ;
}
static int F_355 ( struct V_203 * V_203 )
{
struct V_76 * V_296 = F_350 ( V_203 ) ;
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! V_2 -> V_413 )
return 0 ;
F_58 ( & V_2 -> V_74 ) ;
F_60 ( V_2 , V_2 -> V_424 ) ;
V_2 -> V_424 = 0 ;
F_59 ( & V_2 -> V_74 ) ;
F_152 ( V_40 , V_2 ) ;
F_351 ( V_40 ) ;
return 0 ;
}
static int F_356 ( struct V_203 * V_203 )
{
struct V_76 * V_296 = F_350 ( V_203 ) ;
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
return V_2 -> V_413 ? - V_626 : 0 ;
}
static void F_357 ( struct V_76 * V_296 )
{
struct V_39 * V_40 = F_209 ( V_296 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
F_347 ( V_40 ) ;
F_154 ( V_2 , V_40 -> V_390 ) ;
F_58 ( & V_2 -> V_74 ) ;
F_37 ( V_5 ) ;
F_59 ( & V_2 -> V_74 ) ;
if ( V_627 == V_628 ) {
if ( V_2 -> V_105 & V_106 ) {
F_358 ( V_296 ) ;
F_7 ( V_63 , V_209 ) ;
F_43 ( V_63 ) ;
}
F_359 ( V_296 , true ) ;
F_360 ( V_296 , V_629 ) ;
}
}
static int T_14 F_361 ( void )
{
return F_362 ( & V_630 ) ;
}
static void T_15 F_363 ( void )
{
F_364 ( & V_630 ) ;
}
