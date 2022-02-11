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
static
void F_34 ( void T_4 * V_5 , int V_48 , T_1 V_3 , T_1 V_33 , int type )
{
unsigned int V_7 ;
F_35 ( ( V_48 & 3 ) || ( V_3 == 0 ) ) ;
F_2 ( V_13 , V_33 ) ;
F_2 ( V_14 , V_56 | type | V_3 | V_48 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ! ( F_4 ( V_14 ) & V_15 ) )
break;
F_3 ( 100 ) ;
}
}
static T_1 F_36 ( void T_4 * V_5 , int V_48 , int type )
{
T_1 V_21 = ~ 0x00 ;
unsigned int V_7 ;
F_2 ( V_14 , V_57 | type | V_58 | V_48 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( F_4 ( V_14 ) & V_15 ) {
V_21 = F_4 ( V_13 ) ;
break;
}
F_3 ( 100 ) ;
}
return V_21 ;
}
static void
F_37 ( void T_4 * V_5 , int V_48 , T_1 V_3 , T_1 V_37 , T_1 V_38 , int type )
{
T_1 V_33 ;
V_33 = F_36 ( V_5 , V_48 , type ) ;
F_34 ( V_5 , V_48 , V_3 , ( V_33 & ~ V_38 ) | V_37 , type ) ;
}
static void F_38 ( void T_4 * V_5 ,
const struct V_59 * V_60 , int V_61 )
{
while ( V_61 -- > 0 ) {
F_34 ( V_5 , V_60 -> V_48 , V_60 -> V_3 , V_60 -> V_33 , V_62 ) ;
V_60 ++ ;
}
}
static T_2 F_39 ( void T_4 * V_5 , int V_20 )
{
T_2 V_21 = 0xff ;
unsigned int V_7 ;
F_2 ( V_63 , ( V_20 & V_64 ) << V_65 ) ;
for ( V_7 = 0 ; V_7 < 300 ; V_7 ++ ) {
if ( F_4 ( V_63 ) & V_66 ) {
V_21 = F_4 ( V_63 ) & V_67 ;
break;
}
F_3 ( 100 ) ;
}
return V_21 ;
}
static void F_40 ( void T_4 * V_5 )
{
F_41 ( V_68 , 0x0000 ) ;
F_41 ( V_69 , 0xffff ) ;
}
static unsigned int F_42 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
return F_4 ( V_70 ) & V_71 ;
}
static unsigned int F_43 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , V_72 ) & V_73 ;
}
static unsigned int F_44 ( void T_4 * V_5 )
{
return F_4 ( V_70 ) & V_74 ;
}
static unsigned int F_45 ( void T_4 * V_5 )
{
return F_46 ( V_75 ) & V_76 ;
}
static void F_47 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_70 , F_4 ( V_70 ) | V_71 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
V_33 = F_24 ( V_2 , V_72 ) | V_73 ;
F_23 ( V_2 , V_72 , V_33 & 0xffff ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
struct V_39 * V_40 = V_2 -> V_40 ;
if ( ! F_50 ( V_40 ) )
return;
if ( V_2 -> V_16 == V_77 ) {
if ( F_46 ( V_75 ) & V_78 ) {
F_34 ( V_5 , 0x1bc , V_58 ,
0x00000011 , V_62 ) ;
F_34 ( V_5 , 0x1dc , V_58 ,
0x00000005 , V_62 ) ;
} else if ( F_46 ( V_75 ) & V_79 ) {
F_34 ( V_5 , 0x1bc , V_58 ,
0x0000001f , V_62 ) ;
F_34 ( V_5 , 0x1dc , V_58 ,
0x00000005 , V_62 ) ;
} else {
F_34 ( V_5 , 0x1bc , V_58 ,
0x0000001f , V_62 ) ;
F_34 ( V_5 , 0x1dc , V_58 ,
0x0000003f , V_62 ) ;
}
F_37 ( V_5 , 0xdc , V_80 , 0x00 , 0x01 ,
V_62 ) ;
F_37 ( V_5 , 0xdc , V_80 , 0x01 , 0x00 ,
V_62 ) ;
}
}
static void F_51 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 , bool V_81 )
{
unsigned long V_82 ;
F_52 ( & V_2 -> V_83 , V_82 ) ;
if ( V_2 -> V_84 ( V_5 ) ) {
F_49 ( V_2 ) ;
if ( V_81 )
F_53 ( & V_2 -> V_85 -> V_40 ) ;
F_54 ( V_40 ) ;
if ( F_55 () )
F_56 ( V_2 , V_86 , V_40 , L_1 ) ;
} else {
F_57 ( V_40 ) ;
F_56 ( V_2 , V_87 , V_40 , L_2 ) ;
if ( V_81 )
F_58 ( & V_2 -> V_85 -> V_40 , 100 ) ;
}
F_59 ( & V_2 -> V_83 , V_82 ) ;
}
static void F_60 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 )
{
F_51 ( V_40 , V_2 , V_5 , false ) ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
T_2 V_88 ;
T_1 V_89 = 0 ;
V_88 = F_46 ( V_90 ) ;
if ( ! ( V_88 & V_91 ) )
return 0 ;
V_88 = F_46 ( V_92 ) ;
if ( V_88 & V_93 )
V_89 |= V_94 ;
if ( V_88 & V_95 )
V_89 |= V_96 ;
V_88 = F_46 ( V_97 ) ;
if ( V_88 & V_98 )
V_89 |= V_99 ;
if ( V_88 & V_100 )
V_89 |= V_101 ;
if ( V_88 & V_102 )
V_89 |= V_103 ;
return V_89 ;
}
static void F_62 ( struct V_39 * V_40 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_63 ( & V_2 -> V_83 ) ;
V_105 -> V_106 = V_107 ;
V_105 -> V_89 = F_61 ( V_2 ) ;
F_64 ( & V_2 -> V_83 ) ;
}
static void F_65 ( struct V_1 * V_2 , T_1 V_89 )
{
void T_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
static const struct {
T_1 V_108 ;
T_3 V_4 ;
T_2 V_3 ;
} V_109 [] = {
{ V_107 , V_90 , V_91 } ,
{ V_94 , V_92 , V_93 } ,
{ V_96 , V_92 , V_95 } ,
{ V_99 , V_97 , V_98 } ,
{ V_101 , V_97 , V_100 } ,
{ V_103 , V_97 , V_102 } ,
{ V_107 , V_97 , V_110 }
} ;
F_7 ( V_111 , V_112 ) ;
for ( V_7 = 0 ; V_7 < F_66 ( V_109 ) ; V_7 ++ ) {
T_2 V_88 = F_46 ( V_109 [ V_7 ] . V_4 ) & ~ V_109 [ V_7 ] . V_3 ;
if ( V_89 & V_109 [ V_7 ] . V_108 )
V_88 |= V_109 [ V_7 ] . V_3 ;
F_7 ( V_109 [ V_7 ] . V_4 , V_88 ) ;
}
F_7 ( V_111 , V_113 ) ;
}
static int F_67 ( struct V_39 * V_40 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_63 ( & V_2 -> V_83 ) ;
if ( V_105 -> V_89 )
V_2 -> V_114 |= V_115 ;
else
V_2 -> V_114 &= ~ V_115 ;
F_65 ( V_2 , V_105 -> V_89 ) ;
F_64 ( & V_2 -> V_83 ) ;
F_68 ( & V_2 -> V_85 -> V_40 , V_105 -> V_89 ) ;
return 0 ;
}
static const char * F_69 ( struct V_1 * V_2 )
{
return V_116 [ V_2 -> V_16 ] . V_117 ;
}
static void F_70 ( struct V_39 * V_40 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_120 * V_120 = V_2 -> V_120 ;
strcpy ( V_119 -> V_121 , V_122 ) ;
strcpy ( V_119 -> V_123 , V_124 ) ;
strcpy ( V_119 -> V_125 , F_71 ( V_2 -> V_85 ) ) ;
F_72 ( sizeof( V_119 -> V_126 ) < sizeof( V_120 -> V_123 ) ) ;
strcpy ( V_119 -> V_126 , F_73 ( V_120 ) ? L_3 :
V_120 -> V_123 ) ;
}
static int F_74 ( struct V_39 * V_40 )
{
return V_127 ;
}
static int F_75 ( struct V_39 * V_40 ,
T_2 V_128 , T_3 V_129 , T_2 V_130 , T_1 V_131 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_132 = 0 ;
T_1 V_4 ;
V_4 = F_4 ( V_70 ) ;
if ( ( V_128 == V_133 ) && ( V_129 == V_134 ) &&
( V_130 == V_135 ) ) {
F_2 ( V_70 , V_4 & ~ ( V_136 | V_137 ) ) ;
} else if ( V_128 == V_138 )
F_2 ( V_70 , V_4 | V_136 | V_137 ) ;
else {
F_76 ( V_2 , V_139 , V_40 ,
L_4 ) ;
V_132 = - V_140 ;
}
return V_132 ;
}
static int F_77 ( struct V_39 * V_40 ,
T_2 V_128 , T_3 V_129 , T_2 V_130 , T_1 V_141 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_142 , V_143 ;
int V_144 = - V_145 ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
if ( V_128 == V_138 ) {
int V_146 ;
V_146 = F_24 ( V_2 , V_147 ) ;
V_146 &= ~ ( V_148 | V_149 |
V_150 | V_151 ) ;
if ( V_141 & V_152 )
V_146 |= V_148 ;
if ( V_141 & V_153 )
V_146 |= V_149 ;
if ( V_141 & V_154 )
V_146 |= V_150 ;
if ( V_141 & V_155 )
V_146 |= V_151 ;
V_146 |= V_156 | V_157 ;
V_142 = F_24 ( V_2 , V_158 ) ;
V_142 &= ~ ( V_159 | V_160 ) ;
if ( V_2 -> V_161 . V_162 ) {
if ( V_141 & V_163 )
V_142 |= V_160 ;
if ( V_141 & V_164 )
V_142 |= V_159 ;
} else if ( V_141 & ( V_163 |
V_164 ) ) {
F_56 ( V_2 , V_139 , V_40 ,
L_5 ) ;
goto V_165;
}
V_143 = V_166 | V_167 ;
F_23 ( V_2 , V_147 , V_146 ) ;
F_23 ( V_2 , V_158 , V_142 ) ;
} else {
V_142 = 0 ;
if ( V_129 == V_168 )
V_143 = 0 ;
else if ( V_129 == V_169 )
V_143 = V_170 ;
else
goto V_165;
if ( V_130 == V_135 )
V_143 |= V_171 ;
}
F_23 ( V_2 , V_72 , V_143 ) ;
if ( V_2 -> V_16 == V_172 ||
V_2 -> V_16 == V_173 ) {
if ( ( V_129 == V_169 ) && ( V_128 != V_138 ) ) {
F_23 ( V_2 , 0x17 , 0x2138 ) ;
F_23 ( V_2 , 0x0e , 0x0260 ) ;
} else {
F_23 ( V_2 , 0x17 , 0x2108 ) ;
F_23 ( V_2 , 0x0e , 0x0000 ) ;
}
}
V_144 = 0 ;
V_165:
return V_144 ;
}
static int F_78 ( struct V_39 * V_40 ,
T_2 V_128 , T_3 V_129 , T_2 V_130 , T_1 V_174 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_132 ;
V_132 = V_2 -> V_175 ( V_40 , V_128 , V_129 , V_130 , V_174 ) ;
if ( V_132 < 0 )
goto V_165;
if ( F_50 ( V_40 ) && ( V_128 == V_138 ) &&
( V_174 & V_164 ) ) {
F_79 ( & V_2 -> V_176 , V_177 + V_178 ) ;
}
V_165:
return V_132 ;
}
static int F_80 ( struct V_39 * V_40 , struct V_179 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_82 ;
int V_132 ;
F_81 ( & V_2 -> V_176 ) ;
F_52 ( & V_2 -> V_83 , V_82 ) ;
V_132 = F_78 ( V_40 , V_12 -> V_128 , F_82 ( V_12 ) ,
V_12 -> V_130 , V_12 -> V_174 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
return V_132 ;
}
static T_1 F_83 ( struct V_39 * V_40 , T_1 V_114 )
{
if ( V_40 -> V_180 > V_181 )
V_114 &= ~ V_182 ;
return V_114 ;
}
static int F_84 ( struct V_39 * V_40 , T_1 V_114 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_82 ;
F_52 ( & V_2 -> V_83 , V_82 ) ;
if ( V_114 & V_183 )
V_2 -> V_184 |= V_185 ;
else
V_2 -> V_184 &= ~ V_185 ;
if ( V_40 -> V_114 & V_186 )
V_2 -> V_184 |= V_187 ;
else
V_2 -> V_184 &= ~ V_187 ;
F_41 ( V_188 , V_2 -> V_184 ) ;
F_85 ( V_188 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
return 0 ;
}
static inline T_1 F_86 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return ( F_87 ( V_190 ) ) ?
V_191 | F_88 ( F_89 ( V_190 ) ) : 0x00 ;
}
static void F_90 ( struct V_192 * V_193 , struct V_189 * V_190 )
{
T_1 V_194 = F_91 ( V_193 -> V_194 ) ;
if ( V_194 & V_195 )
F_92 ( V_190 , F_88 ( V_194 & 0xffff ) ) ;
V_193 -> V_194 = 0 ;
}
static int F_93 ( struct V_39 * V_40 , struct V_179 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
T_1 V_196 ;
V_12 -> V_106 =
V_197 | V_198 | V_199 ;
V_12 -> V_200 = V_201 ;
V_12 -> V_202 = V_203 ;
V_196 = F_4 ( V_70 ) ;
V_12 -> V_174 = ( V_196 & V_136 ) ? V_204 : 0 ;
V_12 -> V_128 = ! ! ( V_196 & V_136 ) ;
F_94 ( V_12 , V_134 ) ;
V_12 -> V_130 = V_135 ;
return 0 ;
}
static int F_95 ( struct V_39 * V_40 , struct V_179 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
return F_96 ( & V_2 -> V_161 , V_12 ) ;
}
static int F_97 ( struct V_39 * V_40 , struct V_179 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_82 ;
int V_144 ;
F_52 ( & V_2 -> V_83 , V_82 ) ;
V_144 = V_2 -> V_205 ( V_40 , V_12 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
return V_144 ;
}
static void F_98 ( struct V_39 * V_40 , struct V_206 * V_207 ,
void * V_37 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned long V_82 ;
if ( V_207 -> V_61 > V_127 )
V_207 -> V_61 = V_127 ;
F_52 ( & V_2 -> V_83 , V_82 ) ;
F_99 ( V_37 , V_2 -> V_6 , V_207 -> V_61 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
}
static T_1 F_100 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
return V_2 -> V_208 ;
}
static void F_101 ( struct V_39 * V_40 , T_1 V_21 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
V_2 -> V_208 = V_21 ;
}
static int F_102 ( struct V_39 * V_40 , int V_209 )
{
switch ( V_209 ) {
case V_210 :
return F_66 ( V_211 ) ;
default:
return - V_140 ;
}
}
static void F_103 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_212 * V_213 = & V_2 -> V_85 -> V_40 ;
struct V_214 * V_215 ;
T_5 V_216 ;
T_1 V_12 ;
int V_217 = 1000 ;
if ( ( F_46 ( V_218 ) & V_219 ) == 0 )
return;
V_215 = F_104 ( V_213 , sizeof( * V_215 ) , & V_216 , V_220 ) ;
if ( ! V_215 )
return;
F_2 ( V_221 , ( V_222 ) V_216 >> 32 ) ;
V_12 = ( V_222 ) V_216 & F_105 ( 32 ) ;
F_2 ( V_223 , V_12 ) ;
F_2 ( V_223 , V_12 | V_224 ) ;
while ( V_217 -- ) {
if ( ( F_4 ( V_223 ) & V_224 ) == 0 ) {
memcpy ( & V_2 -> V_215 , V_215 , sizeof( * V_215 ) ) ;
break;
}
F_3 ( 10 ) ;
}
F_2 ( V_223 , 0 ) ;
F_2 ( V_221 , 0 ) ;
F_106 ( V_213 , sizeof( * V_215 ) , V_215 , V_216 ) ;
}
static void F_107 ( struct V_39 * V_40 ,
struct V_225 * V_226 , V_222 * V_11 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_108 () ;
F_103 ( V_40 ) ;
V_11 [ 0 ] = F_109 ( V_2 -> V_215 . V_227 ) ;
V_11 [ 1 ] = F_109 ( V_2 -> V_215 . V_228 ) ;
V_11 [ 2 ] = F_109 ( V_2 -> V_215 . V_229 ) ;
V_11 [ 3 ] = F_91 ( V_2 -> V_215 . V_230 ) ;
V_11 [ 4 ] = F_110 ( V_2 -> V_215 . V_231 ) ;
V_11 [ 5 ] = F_110 ( V_2 -> V_215 . V_232 ) ;
V_11 [ 6 ] = F_91 ( V_2 -> V_215 . V_233 ) ;
V_11 [ 7 ] = F_91 ( V_2 -> V_215 . V_234 ) ;
V_11 [ 8 ] = F_109 ( V_2 -> V_215 . V_235 ) ;
V_11 [ 9 ] = F_109 ( V_2 -> V_215 . V_236 ) ;
V_11 [ 10 ] = F_91 ( V_2 -> V_215 . V_237 ) ;
V_11 [ 11 ] = F_110 ( V_2 -> V_215 . V_238 ) ;
V_11 [ 12 ] = F_110 ( V_2 -> V_215 . V_239 ) ;
}
static void F_111 ( struct V_39 * V_40 , T_1 V_240 , T_2 * V_11 )
{
switch( V_240 ) {
case V_210 :
memcpy ( V_11 , * V_211 , sizeof( V_211 ) ) ;
break;
}
}
static void F_112 ( struct V_1 * V_2 ,
struct V_39 * V_40 , T_2 V_241 )
{
void T_4 * V_5 = V_2 -> V_6 ;
static const struct V_242 {
T_1 V_3 ;
T_1 V_33 ;
int V_16 ;
} V_243 [] = {
{ 0x7c800000 , 0x2c800000 , V_77 } ,
{ 0x7cf00000 , 0x2c200000 , V_244 } ,
{ 0x7cf00000 , 0x2c100000 , V_245 } ,
{ 0x7c800000 , 0x2c000000 , V_244 } ,
{ 0x7cf00000 , 0x28300000 , V_246 } ,
{ 0x7cf00000 , 0x28100000 , V_247 } ,
{ 0x7c800000 , 0x28000000 , V_246 } ,
{ 0x7cf00000 , 0x28800000 , V_248 } ,
{ 0x7cf00000 , 0x28a00000 , V_249 } ,
{ 0x7cf00000 , 0x28b00000 , V_17 } ,
{ 0x7cf00000 , 0x3cb00000 , V_250 } ,
{ 0x7cf00000 , 0x3c900000 , V_251 } ,
{ 0x7cf00000 , 0x3c800000 , V_252 } ,
{ 0x7c800000 , 0x3c800000 , V_250 } ,
{ 0x7cf00000 , 0x3c000000 , V_253 } ,
{ 0x7cf00000 , 0x3c200000 , V_254 } ,
{ 0x7cf00000 , 0x3c300000 , V_255 } ,
{ 0x7cf00000 , 0x3c400000 , V_256 } ,
{ 0x7c800000 , 0x3c000000 , V_256 } ,
{ 0x7cf00000 , 0x38000000 , V_257 } ,
{ 0x7cf00000 , 0x38500000 , V_258 } ,
{ 0x7c800000 , 0x38000000 , V_258 } ,
{ 0x7c800000 , 0x30000000 , V_259 } ,
{ 0x7cf00000 , 0x40b00000 , V_260 } ,
{ 0x7cf00000 , 0x40a00000 , V_260 } ,
{ 0x7cf00000 , 0x40900000 , V_261 } ,
{ 0x7c800000 , 0x40800000 , V_260 } ,
{ 0x7cf00000 , 0x34a00000 , V_262 } ,
{ 0x7cf00000 , 0x24a00000 , V_262 } ,
{ 0x7cf00000 , 0x34900000 , V_263 } ,
{ 0x7cf00000 , 0x24900000 , V_263 } ,
{ 0x7cf00000 , 0x34800000 , V_264 } ,
{ 0x7cf00000 , 0x24800000 , V_264 } ,
{ 0x7cf00000 , 0x34000000 , V_265 } ,
{ 0x7cf00000 , 0x34300000 , V_266 } ,
{ 0x7cf00000 , 0x34200000 , V_267 } ,
{ 0x7c800000 , 0x34800000 , V_262 } ,
{ 0x7c800000 , 0x24800000 , V_262 } ,
{ 0x7c800000 , 0x34000000 , V_267 } ,
{ 0xfc800000 , 0x38800000 , V_268 } ,
{ 0xfc800000 , 0x30800000 , V_269 } ,
{ 0xfc800000 , 0x98000000 , V_270 } ,
{ 0xfc800000 , 0x18000000 , V_271 } ,
{ 0xfc800000 , 0x10000000 , V_272 } ,
{ 0xfc800000 , 0x04000000 , V_173 } ,
{ 0xfc800000 , 0x00800000 , V_172 } ,
{ 0xfc800000 , 0x00000000 , V_273 } ,
{ 0x00000000 , 0x00000000 , V_274 }
} ;
const struct V_242 * V_37 = V_243 ;
T_1 V_4 ;
V_4 = F_4 ( V_275 ) ;
while ( ( V_4 & V_37 -> V_3 ) != V_37 -> V_33 )
V_37 ++ ;
V_2 -> V_16 = V_37 -> V_16 ;
if ( V_2 -> V_16 == V_274 ) {
F_113 ( V_2 , V_276 , V_40 ,
L_6 ) ;
V_2 -> V_16 = V_241 ;
}
}
static void F_114 ( struct V_1 * V_2 )
{
F_115 ( L_7 , V_2 -> V_16 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
const struct V_277 * V_207 , int V_61 )
{
while ( V_61 -- > 0 ) {
F_23 ( V_2 , V_207 -> V_4 , V_207 -> V_33 ) ;
V_207 ++ ;
}
}
static bool F_117 ( struct V_1 * V_2 , struct V_120 * V_120 )
{
const struct V_278 * V_279 = V_120 -> V_279 ;
struct V_280 * V_280 = (struct V_280 * ) V_279 -> V_11 ;
struct V_281 * V_282 = & V_120 -> V_283 ;
char * V_123 = V_120 -> V_123 ;
bool V_144 = false ;
if ( V_279 -> V_284 < V_285 )
goto V_165;
if ( ! V_280 -> V_286 ) {
T_6 V_7 , V_284 , V_287 ;
T_2 V_288 = 0 ;
if ( V_279 -> V_284 < sizeof( * V_280 ) )
goto V_165;
for ( V_7 = 0 ; V_7 < V_279 -> V_284 ; V_7 ++ )
V_288 += V_279 -> V_11 [ V_7 ] ;
if ( V_288 != 0 )
goto V_165;
V_287 = F_91 ( V_280 -> V_289 ) ;
if ( V_287 > V_279 -> V_284 )
goto V_165;
V_284 = F_91 ( V_280 -> V_290 ) ;
if ( V_284 > ( V_279 -> V_284 - V_287 ) / V_285 )
goto V_165;
memcpy ( V_123 , V_280 -> V_123 , V_291 ) ;
V_282 -> V_292 = ( V_293 * ) ( V_279 -> V_11 + V_287 ) ;
V_282 -> V_284 = V_284 ;
} else {
if ( V_279 -> V_284 % V_285 )
goto V_165;
F_118 ( V_123 , F_69 ( V_2 ) , V_291 ) ;
V_282 -> V_292 = ( V_293 * ) V_279 -> V_11 ;
V_282 -> V_284 = V_279 -> V_284 / V_285 ;
}
V_123 [ V_291 - 1 ] = 0 ;
V_144 = true ;
V_165:
return V_144 ;
}
static bool F_119 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_281 * V_282 )
{
bool V_144 = false ;
T_6 V_294 ;
for ( V_294 = 0 ; V_294 < V_282 -> V_284 ; V_294 ++ ) {
T_1 V_295 = F_91 ( V_282 -> V_292 [ V_294 ] ) ;
T_1 V_296 = ( V_295 & 0x0fff0000 ) >> 16 ;
switch( V_295 & 0xf0000000 ) {
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
break;
case V_305 :
if ( V_296 > V_294 ) {
F_120 ( V_2 , V_86 , V_2 -> V_40 ,
L_8 ) ;
goto V_165;
}
break;
case V_306 :
if ( V_294 + 2 >= V_282 -> V_284 ) {
F_120 ( V_2 , V_86 , V_2 -> V_40 ,
L_8 ) ;
goto V_165;
}
break;
case V_307 :
case V_308 :
case V_309 :
if ( V_294 + 1 + V_296 >= V_282 -> V_284 ) {
F_120 ( V_2 , V_86 , V_2 -> V_40 ,
L_8 ) ;
goto V_165;
}
break;
case V_310 :
case V_311 :
case V_312 :
default:
F_120 ( V_2 , V_86 , V_2 -> V_40 ,
L_9 , V_295 ) ;
goto V_165;
}
}
V_144 = true ;
V_165:
return V_144 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_120 * V_120 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
int V_144 = - V_145 ;
if ( ! F_117 ( V_2 , V_120 ) ) {
F_120 ( V_2 , V_86 , V_40 , L_10 ) ;
goto V_165;
}
if ( F_119 ( V_2 , V_40 , & V_120 -> V_283 ) )
V_144 = 0 ;
V_165:
return V_144 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_120 * V_120 )
{
struct V_281 * V_282 = & V_120 -> V_283 ;
T_1 V_313 , V_314 ;
T_6 V_294 ;
V_313 = V_314 = 0 ;
for ( V_294 = 0 ; V_294 < V_282 -> V_284 ; ) {
T_1 V_295 = F_91 ( V_282 -> V_292 [ V_294 ] ) ;
T_1 V_11 = V_295 & 0x0000ffff ;
T_1 V_296 = ( V_295 & 0x0fff0000 ) >> 16 ;
if ( ! V_295 )
break;
switch( V_295 & 0xf0000000 ) {
case V_297 :
V_313 = F_24 ( V_2 , V_296 ) ;
V_314 ++ ;
V_294 ++ ;
break;
case V_298 :
V_313 |= V_11 ;
V_294 ++ ;
break;
case V_299 :
V_313 &= V_11 ;
V_294 ++ ;
break;
case V_305 :
V_294 -= V_296 ;
break;
case V_300 :
V_313 = F_39 ( V_2 -> V_6 , V_296 ) ;
V_294 ++ ;
break;
case V_301 :
V_314 = 0 ;
V_294 ++ ;
break;
case V_302 :
F_23 ( V_2 , V_296 , V_11 ) ;
V_294 ++ ;
break;
case V_306 :
V_294 += ( V_314 == V_11 ) ? 2 : 1 ;
break;
case V_307 :
if ( V_313 == V_11 )
V_294 += V_296 ;
V_294 ++ ;
break;
case V_308 :
if ( V_313 != V_11 )
V_294 += V_296 ;
V_294 ++ ;
break;
case V_303 :
F_23 ( V_2 , V_296 , V_313 ) ;
V_294 ++ ;
break;
case V_309 :
V_294 += V_296 + 1 ;
break;
case V_304 :
F_16 ( V_11 ) ;
V_294 ++ ;
break;
case V_310 :
case V_311 :
case V_312 :
default:
F_123 () ;
}
}
}
static void F_124 ( struct V_1 * V_2 )
{
if ( ! F_73 ( V_2 -> V_120 ) ) {
F_125 ( V_2 -> V_120 -> V_279 ) ;
F_126 ( V_2 -> V_120 ) ;
}
V_2 -> V_120 = V_315 ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_120 * V_120 = V_2 -> V_120 ;
if ( ! F_73 ( V_120 ) )
F_122 ( V_2 , V_120 ) ;
}
static void F_128 ( struct V_1 * V_2 , T_2 V_4 , T_3 V_33 )
{
if ( F_24 ( V_2 , V_4 ) != V_33 )
F_76 ( V_2 , V_316 , V_2 -> V_40 , L_11 ) ;
else
F_127 ( V_2 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0002 } ,
{ 0x01 , 0x90d0 } ,
{ 0x1f , 0x0000 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_85 * V_318 = V_2 -> V_85 ;
if ( ( V_318 -> V_319 != V_320 ) ||
( V_318 -> V_321 != 0xe000 ) )
return;
F_23 ( V_2 , 0x1f , 0x0001 ) ;
F_23 ( V_2 , 0x10 , 0xf01b ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_131 ( V_2 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0001 ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0001 } ,
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0000 } ,
{ 0x1d , 0x0f00 } ,
{ 0x1f , 0x0002 } ,
{ 0x0c , 0x1ec8 } ,
{ 0x1f , 0x0000 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0001 } ,
{ 0x1d , 0x3d98 } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_25 ( V_2 , 0x16 , 1 << 0 ) ;
F_25 ( V_2 , 0x14 , 1 << 5 ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_140 ( V_2 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
static const struct V_277 V_322 [] = {
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
F_116 ( V_2 , V_322 , F_66 ( V_322 ) ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x0b , 0x0010 , 0x00ef ) ;
F_26 ( V_2 , 0x0c , 0xa200 , 0x5d00 ) ;
if ( F_39 ( V_5 , 0x01 ) == 0xb1 ) {
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_33 ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
V_33 = F_24 ( V_2 , 0x0d ) ;
if ( ( V_33 & 0x00ff ) != 0x006c ) {
static const T_1 V_323 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_7 ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
V_33 &= 0xff00 ;
for ( V_7 = 0 ; V_7 < F_66 ( V_323 ) ; V_7 ++ )
F_23 ( V_2 , 0x0d , V_33 | V_323 [ V_7 ] ) ;
}
} else {
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x6662 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x6662 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_25 ( V_2 , 0x0d , 0x0300 ) ;
F_25 ( V_2 , 0x0f , 0x0010 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_26 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x001b ) ;
F_128 ( V_2 , V_324 , 0xbf00 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
static const struct V_277 V_322 [] = {
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
F_116 ( V_2 , V_322 , F_66 ( V_322 ) ) ;
if ( F_39 ( V_5 , 0x01 ) == 0xb1 ) {
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_33 ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
V_33 = F_24 ( V_2 , 0x0d ) ;
if ( ( V_33 & 0x00ff ) != 0x006c ) {
static const T_1 V_323 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_7 ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
V_33 &= 0xff00 ;
for ( V_7 = 0 ; V_7 < F_66 ( V_323 ) ; V_7 ++ )
F_23 ( V_2 , 0x0d , V_33 | V_323 [ V_7 ] ) ;
}
} else {
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x2642 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x2642 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_26 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_26 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_25 ( V_2 , 0x0f , 0x0017 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x001b ) ;
F_128 ( V_2 , V_324 , 0xb300 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x002d } ,
{ 0x18 , 0x0040 } ,
{ 0x1f , 0x0000 }
} ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_25 ( V_2 , 0x0d , 1 << 5 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_127 ( V_2 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
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
static void F_147 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0004 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x00ac } ,
{ 0x18 , 0x0006 } ,
{ 0x1f , 0x0002 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0003 } ,
{ 0x09 , 0xa20f } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8b5b } ,
{ 0x06 , 0x9222 } ,
{ 0x05 , 0x8b6d } ,
{ 0x06 , 0x8000 } ,
{ 0x05 , 0x8b76 } ,
{ 0x06 , 0x8000 } ,
{ 0x1f , 0x0000 }
} ;
F_127 ( V_2 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b80 ) ;
F_26 ( V_2 , 0x17 , 0x0006 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0004 ) ;
F_23 ( V_2 , 0x1f , 0x0007 ) ;
F_23 ( V_2 , 0x1e , 0x002d ) ;
F_26 ( V_2 , 0x18 , 0x0010 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_26 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b86 ) ;
F_26 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b85 ) ;
F_26 ( V_2 , 0x06 , 0x4000 , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_37 ( V_2 -> V_6 , 0x1b0 , V_58 , 0x0000 , 0x0003 ,
V_62 ) ;
F_23 ( V_2 , 0x1f , 0x0005 ) ;
F_23 ( V_2 , 0x05 , 0x8b85 ) ;
F_26 ( V_2 , 0x06 , 0x0000 , 0x2000 ) ;
F_23 ( V_2 , 0x1f , 0x0004 ) ;
F_23 ( V_2 , 0x1f , 0x0007 ) ;
F_23 ( V_2 , 0x1e , 0x0020 ) ;
F_26 ( V_2 , 0x15 , 0x0000 , 0x0100 ) ;
F_23 ( V_2 , 0x1f , 0x0002 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , 0x0d , 0x0007 ) ;
F_23 ( V_2 , 0x0e , 0x003c ) ;
F_23 ( V_2 , 0x0d , 0x4007 ) ;
F_23 ( V_2 , 0x0e , 0x0000 ) ;
F_23 ( V_2 , 0x0d , 0x0000 ) ;
F_23 ( V_2 , 0x1f , 0x0003 ) ;
F_26 ( V_2 , 0x19 , 0x0000 , 0x0001 ) ;
F_26 ( V_2 , 0x10 , 0x0000 , 0x0400 ) ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
{ 0x1f , 0x0003 } ,
{ 0x08 , 0x441d } ,
{ 0x01 , 0x9100 } ,
{ 0x1f , 0x0000 }
} ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_25 ( V_2 , 0x11 , 1 << 12 ) ;
F_25 ( V_2 , 0x19 , 1 << 13 ) ;
F_25 ( V_2 , 0x10 , 1 << 15 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
static const struct V_277 V_317 [] = {
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
F_127 ( V_2 ) ;
F_116 ( V_2 , V_317 , F_66 ( V_317 ) ) ;
}
static void F_150 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_114 ( V_2 ) ;
switch ( V_2 -> V_16 ) {
case V_273 :
break;
case V_172 :
case V_173 :
F_129 ( V_2 ) ;
break;
case V_272 :
F_130 ( V_2 ) ;
break;
case V_271 :
F_132 ( V_2 ) ;
break;
case V_270 :
F_133 ( V_2 ) ;
break;
case V_264 :
case V_263 :
case V_262 :
F_148 ( V_2 ) ;
break;
case V_259 :
F_134 ( V_2 ) ;
break;
case V_257 :
F_135 ( V_2 ) ;
break;
case V_258 :
F_135 ( V_2 ) ;
break;
case V_252 :
F_136 ( V_2 ) ;
break;
case V_253 :
F_138 ( V_2 ) ;
break;
case V_254 :
F_139 ( V_2 ) ;
break;
case V_255 :
F_140 ( V_2 ) ;
break;
case V_256 :
F_141 ( V_2 ) ;
break;
case V_251 :
case V_250 :
F_137 ( V_2 ) ;
break;
case V_247 :
F_142 ( V_2 ) ;
break;
case V_246 :
F_143 ( V_2 ) ;
break;
case V_248 :
F_144 ( V_2 ) ;
break;
case V_249 :
F_145 ( V_2 ) ;
break;
case V_261 :
case V_260 :
F_149 ( V_2 ) ;
break;
case V_17 :
break;
case V_245 :
case V_244 :
F_146 ( V_2 ) ;
break;
case V_77 :
F_147 ( V_2 ) ;
break;
default:
break;
}
}
static void F_151 ( unsigned long V_325 )
{
struct V_39 * V_40 = (struct V_39 * ) V_325 ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_326 * V_176 = & V_2 -> V_176 ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_327 = V_178 ;
assert ( V_2 -> V_16 > V_273 ) ;
F_63 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_328 ( V_2 ) ) {
V_327 = V_329 / 10 ;
goto V_330;
}
if ( V_2 -> V_84 ( V_5 ) )
goto V_331;
F_76 ( V_2 , V_139 , V_40 , L_12 ) ;
V_2 -> V_332 ( V_2 ) ;
V_330:
F_79 ( V_176 , V_177 + V_327 ) ;
V_331:
F_64 ( & V_2 -> V_83 ) ;
}
static void F_152 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_85 * V_318 = V_2 -> V_85 ;
F_153 ( V_318 -> V_333 ) ;
F_154 ( V_318 -> V_333 , V_40 ) ;
F_155 ( V_318 -> V_333 ) ;
}
static void F_156 ( struct V_85 * V_318 , struct V_39 * V_40 ,
void T_4 * V_5 )
{
F_157 ( V_5 ) ;
F_158 ( V_318 ) ;
F_159 ( V_318 ) ;
F_160 ( V_318 ) ;
F_161 ( V_40 ) ;
}
static void F_162 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
unsigned int V_7 ;
V_2 -> V_332 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ! V_2 -> V_328 ( V_2 ) )
return;
F_8 ( 1 ) ;
}
F_120 ( V_2 , V_139 , V_40 , L_13 ) ;
}
static bool F_163 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
return ( V_2 -> V_16 == V_273 ) &&
( F_46 ( V_75 ) & V_334 ) ;
}
static void F_164 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_150 ( V_40 ) ;
if ( V_2 -> V_16 <= V_270 ) {
F_115 ( L_14 ) ;
F_7 ( 0x82 , 0x01 ) ;
}
F_165 ( V_2 -> V_85 , V_335 , 0x40 ) ;
if ( V_2 -> V_16 <= V_270 )
F_165 ( V_2 -> V_85 , V_336 , 0x08 ) ;
if ( V_2 -> V_16 == V_172 ) {
F_115 ( L_14 ) ;
F_7 ( 0x82 , 0x01 ) ;
F_115 ( L_15 ) ;
F_23 ( V_2 , 0x0b , 0x0000 ) ;
}
F_162 ( V_40 , V_2 ) ;
F_78 ( V_40 , V_138 , V_134 , V_135 ,
V_152 | V_153 |
V_154 | V_155 |
( V_2 -> V_161 . V_162 ?
V_163 |
V_164 : 0 ) ) ;
if ( F_163 ( V_2 ) )
F_56 ( V_2 , V_139 , V_40 , L_16 ) ;
}
static void F_166 ( struct V_1 * V_2 , T_2 * V_48 )
{
void T_4 * V_5 = V_2 -> V_6 ;
T_1 V_337 ;
T_1 V_338 ;
V_338 = V_48 [ 0 ] | ( V_48 [ 1 ] << 8 ) | ( V_48 [ 2 ] << 16 ) | ( V_48 [ 3 ] << 24 ) ;
V_337 = V_48 [ 4 ] | ( V_48 [ 5 ] << 8 ) ;
F_63 ( & V_2 -> V_83 ) ;
F_7 ( V_111 , V_112 ) ;
F_2 ( V_339 , V_337 ) ;
F_4 ( V_339 ) ;
F_2 ( V_340 , V_338 ) ;
F_4 ( V_340 ) ;
if ( V_2 -> V_16 == V_77 ) {
const struct V_59 V_341 [] = {
{ . V_48 = 0xe0 , V_58 , . V_33 = V_338 } ,
{ . V_48 = 0xe4 , V_58 , . V_33 = V_337 } ,
{ . V_48 = 0xf0 , V_58 , . V_33 = V_338 << 16 } ,
{ . V_48 = 0xf4 , V_58 , . V_33 = V_337 << 16 |
V_338 >> 16 } ,
} ;
F_38 ( V_5 , V_341 , F_66 ( V_341 ) ) ;
}
F_7 ( V_111 , V_113 ) ;
F_64 ( & V_2 -> V_83 ) ;
}
static int F_167 ( struct V_39 * V_40 , void * V_37 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_342 * V_48 = V_37 ;
if ( ! F_168 ( V_48 -> V_343 ) )
return - V_344 ;
memcpy ( V_40 -> V_345 , V_48 -> V_343 , V_40 -> V_346 ) ;
F_166 ( V_2 , V_40 -> V_345 ) ;
return 0 ;
}
static int F_169 ( struct V_39 * V_40 , struct V_347 * V_348 , int V_12 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_349 * V_11 = F_170 ( V_348 ) ;
return F_50 ( V_40 ) ? V_2 -> V_350 ( V_2 , V_11 , V_12 ) : - V_351 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_349 * V_11 , int V_12 )
{
switch ( V_12 ) {
case V_352 :
V_11 -> V_41 = 32 ;
return 0 ;
case V_353 :
V_11 -> V_354 = F_24 ( V_2 , V_11 -> V_355 & 0x1f ) ;
return 0 ;
case V_356 :
F_23 ( V_2 , V_11 -> V_355 & 0x1f , V_11 -> V_357 ) ;
return 0 ;
}
return - V_140 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_349 * V_11 , int V_12 )
{
return - V_140 ;
}
static unsigned F_173 ( struct V_85 * V_318 , void T_4 * V_5 ,
const struct V_358 * V_109 )
{
unsigned V_359 = 0 ;
T_2 V_360 ;
V_360 = F_46 ( V_361 ) & ~ V_362 ;
if ( V_109 -> V_114 & V_363 ) {
if ( F_174 ( V_318 ) ) {
F_175 ( & V_318 -> V_40 , L_17 ) ;
} else {
V_360 |= V_362 ;
V_359 = V_363 ;
}
}
F_7 ( V_361 , V_360 ) ;
return V_359 ;
}
static void F_176 ( struct V_85 * V_318 , struct V_1 * V_2 )
{
if ( V_2 -> V_114 & V_363 ) {
F_177 ( V_318 ) ;
V_2 -> V_114 &= ~ V_363 ;
}
}
static void T_7 F_178 ( struct V_1 * V_2 )
{
struct V_34 * V_364 = & V_2 -> V_34 ;
switch ( V_2 -> V_16 ) {
case V_248 :
V_364 -> V_35 = F_17 ;
V_364 -> V_36 = F_18 ;
break;
case V_249 :
case V_17 :
V_364 -> V_35 = F_21 ;
V_364 -> V_36 = F_22 ;
break;
default:
V_364 -> V_35 = F_13 ;
V_364 -> V_36 = F_14 ;
break;
}
}
static void F_179 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
switch ( V_2 -> V_16 ) {
case V_261 :
case V_260 :
case V_245 :
case V_244 :
case V_77 :
F_2 ( V_365 , F_4 ( V_365 ) |
V_366 | V_367 | V_368 ) ;
break;
default:
break;
}
}
static bool F_180 ( struct V_1 * V_2 )
{
if ( ! ( F_61 ( V_2 ) & V_107 ) )
return false ;
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_72 , 0x0000 ) ;
F_179 ( V_2 ) ;
return true ;
}
static void F_181 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_72 , V_369 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
F_23 ( V_2 , V_72 , V_166 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
if ( F_180 ( V_2 ) )
return;
F_181 ( V_2 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_16 ) {
case V_259 :
case V_257 :
case V_258 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_251 :
case V_250 :
case V_247 :
case V_246 :
case V_248 :
case V_249 :
case V_17 :
F_23 ( V_2 , 0x0e , 0x0000 ) ;
break;
default:
break;
}
F_23 ( V_2 , V_72 , V_166 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_16 ) {
case V_245 :
case V_244 :
F_23 ( V_2 , V_72 , V_166 | V_369 ) ;
break;
case V_259 :
case V_257 :
case V_258 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_251 :
case V_250 :
case V_247 :
case V_246 :
case V_248 :
case V_249 :
case V_17 :
F_23 ( V_2 , 0x0e , 0x0200 ) ;
default:
F_23 ( V_2 , V_72 , V_369 ) ;
break;
}
}
static void F_187 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
if ( ( V_2 -> V_16 == V_248 ||
V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_17 ) &&
F_12 ( V_2 ) ) {
return;
}
if ( ( V_2 -> V_16 == V_251 ||
V_2 -> V_16 == V_250 ) &&
( F_85 ( V_188 ) & V_370 ) ) {
return;
}
if ( V_2 -> V_16 == V_245 ||
V_2 -> V_16 == V_244 )
F_30 ( V_5 , 0x19 , 0xff64 ) ;
if ( F_180 ( V_2 ) )
return;
F_186 ( V_2 ) ;
switch ( V_2 -> V_16 ) {
case V_247 :
case V_246 :
case V_248 :
case V_249 :
case V_17 :
case V_245 :
case V_244 :
F_7 ( V_371 , F_46 ( V_371 ) & ~ 0x80 ) ;
break;
}
}
static void F_188 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
if ( ( V_2 -> V_16 == V_248 ||
V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_17 ) &&
F_12 ( V_2 ) ) {
return;
}
switch ( V_2 -> V_16 ) {
case V_247 :
case V_246 :
case V_248 :
case V_249 :
case V_17 :
case V_245 :
case V_244 :
F_7 ( V_371 , F_46 ( V_371 ) | 0x80 ) ;
break;
}
F_185 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
void (* F_190)( struct V_1 * ) )
{
if ( F_190 )
F_190 ( V_2 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_189 ( V_2 , V_2 -> V_372 . V_373 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_189 ( V_2 , V_2 -> V_372 . V_374 ) ;
}
static void T_7 F_193 ( struct V_1 * V_2 )
{
struct V_372 * V_364 = & V_2 -> V_372 ;
switch ( V_2 -> V_16 ) {
case V_264 :
case V_263 :
case V_262 :
case V_266 :
case V_267 :
case V_261 :
case V_260 :
V_364 -> V_373 = F_183 ;
V_364 -> V_374 = F_184 ;
break;
case V_259 :
case V_257 :
case V_258 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_251 :
case V_250 :
case V_247 :
case V_246 :
case V_248 :
case V_249 :
case V_17 :
case V_245 :
case V_244 :
case V_77 :
V_364 -> V_373 = F_187 ;
V_364 -> V_374 = F_188 ;
break;
default:
V_364 -> V_373 = NULL ;
V_364 -> V_374 = NULL ;
break;
}
}
static void F_194 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
switch ( V_2 -> V_16 ) {
case V_273 :
case V_172 :
case V_173 :
case V_272 :
case V_271 :
case V_270 :
case V_266 :
case V_259 :
case V_257 :
case V_265 :
case V_269 :
case V_268 :
case V_267 :
case V_258 :
F_2 ( V_365 , V_375 | V_376 ) ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_251 :
case V_250 :
F_2 ( V_365 , V_377 | V_378 | V_376 ) ;
break;
default:
F_2 ( V_365 , V_377 | V_376 ) ;
break;
}
}
static void F_195 ( struct V_1 * V_2 )
{
V_2 -> V_379 = V_2 -> V_380 = V_2 -> V_381 = V_2 -> V_382 = 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_7 ( V_218 , V_383 ) ;
for ( V_7 = 0 ; V_7 < 100 ; V_7 ++ ) {
if ( ( F_46 ( V_218 ) & V_383 ) == 0 )
break;
F_3 ( 100 ) ;
}
F_195 ( V_2 ) ;
}
static int T_7
F_197 ( struct V_85 * V_318 , const struct V_384 * V_385 )
{
const struct V_358 * V_109 = V_386 + V_385 -> V_387 ;
const unsigned int V_388 = V_109 -> V_388 ;
struct V_1 * V_2 ;
struct V_389 * V_161 ;
struct V_39 * V_40 ;
void T_4 * V_5 ;
int V_390 , V_7 ;
int V_144 ;
if ( F_198 ( & V_391 ) ) {
F_199 ( V_392 L_18 ,
V_122 , V_124 ) ;
}
V_40 = F_200 ( sizeof ( * V_2 ) ) ;
if ( ! V_40 ) {
if ( F_198 ( & V_391 ) )
F_201 ( & V_318 -> V_40 , L_19 ) ;
V_144 = - V_393 ;
goto V_165;
}
F_202 ( V_40 , & V_318 -> V_40 ) ;
V_40 -> V_394 = & V_395 ;
V_2 = F_28 ( V_40 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_85 = V_318 ;
V_2 -> V_208 = F_203 ( V_391 . V_208 , V_396 ) ;
V_161 = & V_2 -> V_161 ;
V_161 -> V_40 = V_40 ;
V_161 -> V_397 = F_29 ;
V_161 -> V_398 = F_27 ;
V_161 -> V_399 = 0x1f ;
V_161 -> V_400 = 0x1f ;
V_161 -> V_162 = ! ! ( V_109 -> V_114 & V_401 ) ;
F_204 ( V_318 , V_402 | V_403 |
V_404 ) ;
V_144 = F_205 ( V_318 ) ;
if ( V_144 < 0 ) {
F_120 ( V_2 , V_276 , V_40 , L_20 ) ;
goto V_405;
}
if ( F_206 ( V_318 ) < 0 )
F_56 ( V_2 , V_276 , V_40 , L_21 ) ;
if ( ! ( F_207 ( V_318 , V_388 ) & V_406 ) ) {
F_120 ( V_2 , V_276 , V_40 ,
L_22 ,
V_388 ) ;
V_144 = - V_351 ;
goto V_407;
}
if ( F_208 ( V_318 , V_388 ) < V_127 ) {
F_120 ( V_2 , V_276 , V_40 ,
L_23 ) ;
V_144 = - V_351 ;
goto V_407;
}
V_144 = F_209 ( V_318 , V_122 ) ;
if ( V_144 < 0 ) {
F_120 ( V_2 , V_276 , V_40 , L_24 ) ;
goto V_407;
}
V_2 -> V_184 = V_185 ;
if ( ( sizeof( T_5 ) > 4 ) &&
! F_210 ( V_318 , F_105 ( 64 ) ) && V_408 ) {
V_2 -> V_184 |= V_409 ;
V_40 -> V_114 |= V_410 ;
} else {
V_144 = F_210 ( V_318 , F_105 ( 32 ) ) ;
if ( V_144 < 0 ) {
F_120 ( V_2 , V_276 , V_40 , L_25 ) ;
goto V_411;
}
}
V_5 = F_211 ( F_212 ( V_318 , V_388 ) , V_127 ) ;
if ( ! V_5 ) {
F_120 ( V_2 , V_276 , V_40 , L_26 ) ;
V_144 = - V_412 ;
goto V_411;
}
V_2 -> V_6 = V_5 ;
if ( ! F_213 ( V_318 ) )
F_56 ( V_2 , V_276 , V_40 , L_27 ) ;
F_112 ( V_2 , V_40 , V_109 -> V_413 ) ;
F_194 ( V_2 ) ;
F_41 ( V_68 , 0x0000 ) ;
F_196 ( V_2 ) ;
F_41 ( V_69 , 0xffff ) ;
F_214 ( V_318 ) ;
if ( V_2 -> V_16 == V_271 )
V_2 -> V_184 |= V_187 ;
F_178 ( V_2 ) ;
F_193 ( V_2 ) ;
F_114 ( V_2 ) ;
V_390 = V_2 -> V_16 ;
V_2 -> V_414 = V_116 [ V_390 ] . V_414 ;
F_7 ( V_111 , V_112 ) ;
F_7 ( V_90 , F_46 ( V_90 ) | V_91 ) ;
F_7 ( V_97 , F_46 ( V_97 ) & V_415 ) ;
if ( ( F_46 ( V_92 ) & ( V_93 | V_95 ) ) != 0 )
V_2 -> V_114 |= V_115 ;
if ( ( F_46 ( V_97 ) & ( V_98 | V_100 | V_102 ) ) != 0 )
V_2 -> V_114 |= V_115 ;
V_2 -> V_114 |= F_173 ( V_318 , V_5 , V_109 ) ;
F_7 ( V_111 , V_113 ) ;
if ( F_163 ( V_2 ) ) {
V_2 -> V_175 = F_75 ;
V_2 -> V_205 = F_93 ;
V_2 -> V_332 = F_47 ;
V_2 -> V_328 = F_42 ;
V_2 -> V_84 = F_44 ;
V_2 -> V_350 = F_172 ;
} else {
V_2 -> V_175 = F_77 ;
V_2 -> V_205 = F_95 ;
V_2 -> V_332 = F_48 ;
V_2 -> V_328 = F_43 ;
V_2 -> V_84 = F_45 ;
V_2 -> V_350 = F_171 ;
}
F_215 ( & V_2 -> V_83 ) ;
for ( V_7 = 0 ; V_7 < V_416 ; V_7 ++ )
V_40 -> V_345 [ V_7 ] = F_46 ( V_340 + V_7 ) ;
memcpy ( V_40 -> V_417 , V_40 -> V_345 , V_40 -> V_346 ) ;
F_216 ( V_40 , & V_418 ) ;
V_40 -> V_419 = V_420 ;
V_40 -> V_333 = V_318 -> V_333 ;
V_40 -> V_421 = ( unsigned long ) V_5 ;
F_217 ( V_40 , & V_2 -> V_422 , V_423 , V_424 ) ;
V_40 -> V_114 |= V_183 |
V_425 | V_186 ;
V_40 -> V_426 = V_427 | V_428 | V_429 |
V_183 | V_425 | V_186 ;
V_40 -> V_430 = V_427 | V_428 | V_429 |
V_410 ;
if ( V_2 -> V_16 == V_271 )
V_40 -> V_426 &= ~ V_186 ;
V_2 -> V_431 = 0xffff ;
V_2 -> V_432 = V_109 -> V_432 ;
V_2 -> V_433 = V_109 -> V_433 ;
V_2 -> V_434 = V_109 -> V_434 ;
V_2 -> V_435 = ( V_2 -> V_16 != V_273 ) ?
~ ( V_436 | V_437 ) : ~ 0 ;
F_218 ( & V_2 -> V_176 ) ;
V_2 -> V_176 . V_11 = ( unsigned long ) V_40 ;
V_2 -> V_176 . V_438 = F_151 ;
V_2 -> V_120 = V_315 ;
V_144 = F_219 ( V_40 ) ;
if ( V_144 < 0 )
goto V_439;
F_220 ( V_318 , V_40 ) ;
F_56 ( V_2 , V_276 , V_40 , L_28 ,
V_116 [ V_390 ] . V_440 , V_40 -> V_421 , V_40 -> V_345 ,
( T_1 ) ( F_4 ( V_275 ) & 0x9cf0f8ff ) , V_40 -> V_333 ) ;
if ( V_2 -> V_16 == V_248 ||
V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_17 ) {
F_10 ( V_2 ) ;
}
F_68 ( & V_318 -> V_40 , V_2 -> V_114 & V_115 ) ;
if ( F_221 ( V_318 ) )
F_222 ( & V_318 -> V_40 ) ;
F_57 ( V_40 ) ;
V_165:
return V_144 ;
V_439:
F_176 ( V_318 , V_2 ) ;
F_157 ( V_5 ) ;
V_411:
F_158 ( V_318 ) ;
V_407:
F_159 ( V_318 ) ;
F_160 ( V_318 ) ;
V_405:
F_161 ( V_40 ) ;
goto V_165;
}
static void T_8 F_223 ( struct V_85 * V_318 )
{
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( V_2 -> V_16 == V_248 ||
V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_17 ) {
F_11 ( V_2 ) ;
}
F_225 ( & V_2 -> V_441 ) ;
F_226 ( V_40 ) ;
F_124 ( V_2 ) ;
if ( F_221 ( V_318 ) )
F_227 ( & V_318 -> V_40 ) ;
F_166 ( V_2 , V_40 -> V_417 ) ;
F_176 ( V_318 , V_2 ) ;
F_156 ( V_318 , V_40 , V_2 -> V_6 ) ;
F_220 ( V_318 , NULL ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_120 * V_120 ;
const char * V_440 ;
int V_144 = - V_393 ;
V_440 = F_69 ( V_2 ) ;
if ( ! V_440 )
goto V_442;
V_120 = F_229 ( sizeof( * V_120 ) , V_220 ) ;
if ( ! V_120 )
goto V_443;
V_144 = F_230 ( & V_120 -> V_279 , V_440 , & V_2 -> V_85 -> V_40 ) ;
if ( V_144 < 0 )
goto V_444;
V_144 = F_121 ( V_2 , V_120 ) ;
if ( V_144 < 0 )
goto V_445;
V_2 -> V_120 = V_120 ;
V_165:
return;
V_445:
F_125 ( V_120 -> V_279 ) ;
V_444:
F_126 ( V_120 ) ;
V_443:
F_76 ( V_2 , V_86 , V_2 -> V_40 , L_29 ,
V_440 , V_144 ) ;
V_442:
V_2 -> V_120 = NULL ;
goto V_165;
}
static void F_231 ( struct V_1 * V_2 )
{
if ( F_232 ( V_2 -> V_120 ) )
F_228 ( V_2 ) ;
}
static int F_233 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_85 * V_318 = V_2 -> V_85 ;
int V_446 = - V_393 ;
F_234 ( & V_318 -> V_40 ) ;
V_2 -> V_447 = F_104 ( & V_318 -> V_40 , V_448 ,
& V_2 -> V_449 , V_220 ) ;
if ( ! V_2 -> V_447 )
goto V_450;
V_2 -> V_451 = F_104 ( & V_318 -> V_40 , V_452 ,
& V_2 -> V_453 , V_220 ) ;
if ( ! V_2 -> V_451 )
goto V_454;
V_446 = F_235 ( V_40 ) ;
if ( V_446 < 0 )
goto V_455;
F_236 ( & V_2 -> V_441 , NULL ) ;
F_237 () ;
F_231 ( V_2 ) ;
V_446 = F_238 ( V_40 -> V_333 , F_154 ,
( V_2 -> V_114 & V_363 ) ? 0 : V_456 ,
V_40 -> V_440 , V_40 ) ;
if ( V_446 < 0 )
goto V_457;
F_239 ( & V_2 -> V_422 ) ;
F_164 ( V_40 , V_2 ) ;
F_84 ( V_40 , V_40 -> V_114 ) ;
F_192 ( V_2 ) ;
F_240 ( V_40 ) ;
V_2 -> V_458 = 0 ;
F_222 ( & V_318 -> V_40 ) ;
F_60 ( V_40 , V_2 , V_5 ) ;
V_165:
return V_446 ;
V_457:
F_124 ( V_2 ) ;
F_241 ( V_2 ) ;
V_455:
F_106 ( & V_318 -> V_40 , V_452 , V_2 -> V_451 ,
V_2 -> V_453 ) ;
V_2 -> V_451 = NULL ;
V_454:
F_106 ( & V_318 -> V_40 , V_448 , V_2 -> V_447 ,
V_2 -> V_449 ) ;
V_2 -> V_447 = NULL ;
V_450:
F_222 ( & V_318 -> V_40 ) ;
goto V_165;
}
static void F_242 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_365 , F_4 ( V_365 ) & ~ V_459 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_40 ( V_5 ) ;
F_242 ( V_2 ) ;
if ( V_2 -> V_16 == V_248 ||
V_2 -> V_16 == V_249 ||
V_2 -> V_16 == V_17 ) {
while ( F_46 ( V_460 ) & V_461 )
F_3 ( 20 ) ;
} else if ( V_2 -> V_16 == V_77 ) {
F_7 ( V_218 , F_46 ( V_218 ) | V_462 ) ;
while ( ! ( F_4 ( V_275 ) & V_463 ) )
F_3 ( 100 ) ;
} else {
F_7 ( V_218 , F_46 ( V_218 ) | V_462 ) ;
F_3 ( 100 ) ;
}
F_196 ( V_2 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_275 , ( V_464 << V_465 ) |
( V_466 << V_467 ) ) ;
}
static void F_240 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
V_2 -> V_432 ( V_40 ) ;
F_245 ( V_40 ) ;
}
static void F_246 ( struct V_1 * V_2 ,
void T_4 * V_5 )
{
F_2 ( V_468 , ( ( V_222 ) V_2 -> V_449 ) >> 32 ) ;
F_2 ( V_469 , ( ( V_222 ) V_2 -> V_449 ) & F_105 ( 32 ) ) ;
F_2 ( V_470 , ( ( V_222 ) V_2 -> V_453 ) >> 32 ) ;
F_2 ( V_471 , ( ( V_222 ) V_2 -> V_453 ) & F_105 ( 32 ) ) ;
}
static T_3 F_247 ( void T_4 * V_5 )
{
T_3 V_12 ;
V_12 = F_85 ( V_188 ) ;
F_41 ( V_188 , V_12 ) ;
return V_12 ;
}
static void F_248 ( void T_4 * V_5 , unsigned int V_472 )
{
F_41 ( V_473 , V_472 + 1 ) ;
}
static void F_249 ( void T_4 * V_5 , unsigned V_16 )
{
static const struct V_474 {
T_1 V_16 ;
T_1 V_475 ;
T_1 V_33 ;
} V_476 [] = {
{ V_271 , V_477 , 0x000fff00 } ,
{ V_271 , V_478 , 0x000fffff } ,
{ V_270 , V_477 , 0x00ffff00 } ,
{ V_270 , V_478 , 0x00ffffff }
} ;
const struct V_474 * V_37 = V_476 ;
unsigned int V_7 ;
T_1 V_475 ;
V_475 = F_46 ( V_361 ) & V_478 ;
for ( V_7 = 0 ; V_7 < F_66 ( V_476 ) ; V_7 ++ , V_37 ++ ) {
if ( ( V_37 -> V_16 == V_16 ) && ( V_37 -> V_475 == V_475 ) ) {
F_2 ( 0x7c , V_37 -> V_33 ) ;
break;
}
}
}
static void F_250 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_85 * V_318 = V_2 -> V_85 ;
if ( V_2 -> V_16 == V_271 ) {
F_41 ( V_188 , F_85 ( V_188 ) | V_479 ) ;
F_165 ( V_318 , V_336 , 0x08 ) ;
}
F_7 ( V_111 , V_112 ) ;
if ( V_2 -> V_16 == V_273 ||
V_2 -> V_16 == V_172 ||
V_2 -> V_16 == V_173 ||
V_2 -> V_16 == V_272 )
F_7 ( V_218 , V_480 | V_219 ) ;
F_194 ( V_2 ) ;
F_7 ( V_481 , V_482 ) ;
F_248 ( V_5 , V_472 ) ;
if ( V_2 -> V_16 == V_273 ||
V_2 -> V_16 == V_172 ||
V_2 -> V_16 == V_173 ||
V_2 -> V_16 == V_272 )
F_244 ( V_2 ) ;
V_2 -> V_184 |= F_247 ( V_5 ) | V_479 ;
if ( V_2 -> V_16 == V_172 ||
V_2 -> V_16 == V_173 ) {
F_115 ( L_30
L_31 ) ;
V_2 -> V_184 |= ( 1 << 14 ) ;
}
F_41 ( V_188 , V_2 -> V_184 ) ;
F_249 ( V_5 , V_2 -> V_16 ) ;
F_41 ( V_483 , 0x0000 ) ;
F_246 ( V_2 , V_5 ) ;
if ( V_2 -> V_16 != V_273 &&
V_2 -> V_16 != V_172 &&
V_2 -> V_16 != V_173 &&
V_2 -> V_16 != V_272 ) {
F_7 ( V_218 , V_480 | V_219 ) ;
F_244 ( V_2 ) ;
}
F_7 ( V_111 , V_113 ) ;
F_46 ( V_68 ) ;
F_2 ( V_484 , 0 ) ;
F_251 ( V_40 ) ;
F_41 ( V_485 , F_85 ( V_485 ) & 0xF000 ) ;
F_41 ( V_68 , V_2 -> V_433 ) ;
}
static void F_252 ( struct V_85 * V_318 , T_3 V_486 )
{
int V_487 = F_253 ( V_318 ) ;
if ( V_487 ) {
T_3 V_488 ;
F_254 ( V_318 , V_487 + V_489 , & V_488 ) ;
V_488 = ( V_488 & ~ V_490 ) | V_486 ;
F_255 ( V_318 , V_487 + V_489 , V_488 ) ;
}
}
static void F_256 ( void T_4 * V_5 , T_1 V_491 )
{
T_1 V_492 ;
V_492 = F_33 ( V_5 , 0x070c ) & 0x00ffffff ;
F_32 ( V_5 , 0x070c , V_492 | V_491 ) ;
}
static void F_257 ( void T_4 * V_5 )
{
F_256 ( V_5 , 0x17000000 ) ;
}
static void F_258 ( void T_4 * V_5 )
{
F_256 ( V_5 , 0x27000000 ) ;
}
static void F_259 ( void T_4 * V_5 , const struct V_493 * V_341 , int V_61 )
{
T_3 V_494 ;
while ( V_61 -- > 0 ) {
V_494 = ( F_31 ( V_5 , V_341 -> V_495 ) & ~ V_341 -> V_3 ) | V_341 -> V_491 ;
F_30 ( V_5 , V_341 -> V_495 , V_494 ) ;
V_341 ++ ;
}
}
static void F_260 ( struct V_85 * V_318 )
{
int V_487 = F_253 ( V_318 ) ;
if ( V_487 ) {
T_3 V_488 ;
F_254 ( V_318 , V_487 + V_496 , & V_488 ) ;
V_488 &= ~ V_497 ;
F_255 ( V_318 , V_487 + V_496 , V_488 ) ;
}
}
static void F_261 ( struct V_85 * V_318 )
{
int V_487 = F_253 ( V_318 ) ;
if ( V_487 ) {
T_3 V_488 ;
F_254 ( V_318 , V_487 + V_496 , & V_488 ) ;
V_488 |= V_497 ;
F_255 ( V_318 , V_487 + V_496 , V_488 ) ;
}
}
static void F_262 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
F_41 ( V_188 , F_85 ( V_188 ) & ~ V_499 ) ;
F_252 ( V_318 ,
( 0x5 << V_500 ) | V_501 ) ;
}
static void F_263 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_262 ( V_5 , V_318 ) ;
F_7 ( V_502 , V_503 ) ;
F_7 ( V_504 , F_46 ( V_504 ) & ~ ( 1 << 0 ) ) ;
}
static void F_264 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_7 ( V_90 , F_46 ( V_90 ) | V_505 ) ;
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_260 ( V_318 ) ;
F_41 ( V_188 , F_85 ( V_188 ) & ~ V_499 ) ;
}
static void F_265 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_506 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0042 } ,
{ 0x06 , 0x0080 , 0x0000 } ,
{ 0x07 , 0 , 0x2000 }
} ;
F_258 ( V_5 ) ;
F_259 ( V_5 , V_506 , F_66 ( V_506 ) ) ;
F_264 ( V_5 , V_318 ) ;
}
static void F_266 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_258 ( V_5 ) ;
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_41 ( V_188 , F_85 ( V_188 ) & ~ V_499 ) ;
}
static void F_267 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_258 ( V_5 ) ;
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
F_7 ( V_507 , 0x20 ) ;
F_7 ( V_502 , V_503 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_41 ( V_188 , F_85 ( V_188 ) & ~ V_499 ) ;
}
static void F_268 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_508 [] = {
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0002 } ,
{ 0x06 , 0x0080 , 0x0000 }
} ;
F_258 ( V_5 ) ;
F_7 ( V_507 , 0x06 | V_509 | V_510 ) ;
F_259 ( V_5 , V_508 , F_66 ( V_508 ) ) ;
F_264 ( V_5 , V_318 ) ;
}
static void F_269 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_511 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x03 , 0x0400 , 0x0220 }
} ;
F_258 ( V_5 ) ;
F_259 ( V_5 , V_511 , F_66 ( V_511 ) ) ;
F_264 ( V_5 , V_318 ) ;
}
static void F_270 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_269 ( V_5 , V_318 ) ;
}
static void F_271 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_258 ( V_5 ) ;
F_264 ( V_5 , V_318 ) ;
}
static void F_272 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_258 ( V_5 ) ;
F_260 ( V_318 ) ;
F_7 ( V_502 , V_503 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_41 ( V_188 , F_85 ( V_188 ) & ~ V_499 ) ;
}
static void F_273 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_257 ( V_5 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_7 ( V_502 , V_503 ) ;
F_260 ( V_318 ) ;
}
static void F_274 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_512 [] = {
{ 0x0b , ~ 0 , 0x48 } ,
{ 0x19 , 0x20 , 0x50 } ,
{ 0x0c , ~ 0 , 0x20 }
} ;
int V_7 ;
F_257 ( V_5 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_7 ( V_502 , V_503 ) ;
for ( V_7 = 0 ; V_7 < F_66 ( V_512 ) ; V_7 ++ ) {
const struct V_493 * V_341 = V_512 + V_7 ;
T_3 V_494 ;
V_494 = F_31 ( V_5 , V_341 -> V_495 ) ;
F_30 ( V_5 , 0x03 , ( V_494 & V_341 -> V_3 ) | V_341 -> V_491 ) ;
}
F_261 ( V_318 ) ;
}
static void F_275 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_513 [] = {
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
F_258 ( V_5 ) ;
F_259 ( V_5 , V_513 , F_66 ( V_513 ) ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_7 ( V_502 , V_503 ) ;
F_260 ( V_318 ) ;
F_2 ( V_514 , F_4 ( V_514 ) | V_515 ) ;
F_2 ( V_514 , F_4 ( V_514 ) & ~ V_515 ) ;
F_7 ( V_97 , F_46 ( V_97 ) & ~ V_516 ) ;
}
static void F_276 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_517 [] = {
{ 0x09 , 0x0000 , 0x0080 } ,
{ 0x19 , 0x0000 , 0x0224 }
} ;
F_257 ( V_5 ) ;
F_259 ( V_5 , V_517 , F_66 ( V_517 ) ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_34 ( V_5 , 0xc0 , V_518 , 0x0000 , V_62 ) ;
F_34 ( V_5 , 0xb8 , V_518 , 0x0000 , V_62 ) ;
F_34 ( V_5 , 0xc8 , V_58 , 0x00100002 , V_62 ) ;
F_34 ( V_5 , 0xe8 , V_58 , 0x00100006 , V_62 ) ;
F_34 ( V_5 , 0xcc , V_58 , 0x00000050 , V_62 ) ;
F_34 ( V_5 , 0xd0 , V_58 , 0x07ff0060 , V_62 ) ;
F_37 ( V_5 , 0x1b0 , V_80 , 0x10 , 0x00 , V_62 ) ;
F_37 ( V_5 , 0x0d4 , V_518 , 0x0c00 , 0xff00 ,
V_62 ) ;
F_7 ( V_502 , 0x27 ) ;
F_260 ( V_318 ) ;
F_2 ( V_275 , F_4 ( V_275 ) | V_519 ) ;
F_7 ( V_520 , F_46 ( V_520 ) & ~ V_521 ) ;
F_7 ( V_522 , F_46 ( V_522 ) & ~ 0x07 ) ;
F_7 ( V_523 , F_46 ( V_523 ) | V_524 ) ;
F_2 ( V_514 , F_4 ( V_514 ) | V_525 ) ;
F_7 ( V_97 , F_46 ( V_97 ) & ~ V_516 ) ;
}
static void F_277 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_85 * V_318 = V_2 -> V_85 ;
F_7 ( V_111 , V_112 ) ;
F_7 ( V_502 , V_503 ) ;
F_248 ( V_5 , V_472 ) ;
V_2 -> V_184 |= F_85 ( V_188 ) | V_526 | V_527 ;
F_41 ( V_188 , V_2 -> V_184 ) ;
F_41 ( V_483 , 0x5151 ) ;
if ( V_2 -> V_16 == V_259 ||
V_2 -> V_16 == V_256 ) {
V_2 -> V_433 |= V_528 | V_529 ;
V_2 -> V_433 &= ~ V_530 ;
}
F_246 ( V_2 , V_5 ) ;
F_251 ( V_40 ) ;
F_2 ( V_275 , ( V_464 << V_465 ) |
( V_466 << V_467 ) ) ;
F_46 ( V_68 ) ;
switch ( V_2 -> V_16 ) {
case V_259 :
F_262 ( V_5 , V_318 ) ;
break;
case V_257 :
case V_258 :
F_263 ( V_5 , V_318 ) ;
break;
case V_252 :
F_265 ( V_5 , V_318 ) ;
break;
case V_253 :
F_268 ( V_5 , V_318 ) ;
break;
case V_254 :
F_269 ( V_5 , V_318 ) ;
break;
case V_255 :
F_270 ( V_5 , V_318 ) ;
break;
case V_256 :
F_271 ( V_5 , V_318 ) ;
break;
case V_251 :
F_266 ( V_5 , V_318 ) ;
break;
case V_250 :
F_267 ( V_5 , V_318 ) ;
break;
case V_247 :
case V_246 :
case V_248 :
F_272 ( V_5 , V_318 ) ;
break;
case V_249 :
F_274 ( V_5 , V_318 ) ;
break;
case V_17 :
F_273 ( V_5 , V_318 ) ;
break;
case V_245 :
case V_244 :
F_275 ( V_5 , V_318 ) ;
break;
case V_77 :
F_276 ( V_5 , V_318 ) ;
break;
default:
F_199 (KERN_ERR PFX L_32 ,
dev->name, tp->mac_version) ;
break;
}
F_7 ( V_218 , V_480 | V_219 ) ;
F_7 ( V_111 , V_113 ) ;
F_41 ( V_485 , F_85 ( V_485 ) & 0xF000 ) ;
F_41 ( V_68 , V_2 -> V_433 ) ;
}
static void F_278 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_531 [] = {
{ 0x01 , 0 , 0x6e65 } ,
{ 0x02 , 0 , 0x091f } ,
{ 0x03 , 0 , 0xc2f9 } ,
{ 0x06 , 0 , 0xafb5 } ,
{ 0x07 , 0 , 0x0e00 } ,
{ 0x19 , 0 , 0xec80 } ,
{ 0x01 , 0 , 0x2e65 } ,
{ 0x01 , 0 , 0x6e65 }
} ;
T_2 V_532 ;
F_258 ( V_5 ) ;
F_7 ( V_507 , V_509 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_7 ( V_90 ,
V_533 | V_534 | V_505 | V_535 | V_536 | V_537 | V_91 ) ;
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
V_532 = F_46 ( V_90 ) ;
if ( ( V_532 & V_534 ) && ( V_532 & V_533 ) )
F_7 ( V_90 , V_532 & ~ V_534 ) ;
F_259 ( V_5 , V_531 , F_66 ( V_531 ) ) ;
}
static void F_279 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_258 ( V_5 ) ;
F_252 ( V_318 , 0x5 << V_500 ) ;
F_7 ( V_90 , V_535 | V_536 | V_537 | V_91 ) ;
F_7 ( V_92 , F_46 ( V_92 ) & ~ V_498 ) ;
}
static void F_280 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_279 ( V_5 , V_318 ) ;
F_30 ( V_5 , 0x03 , 0xc2f9 ) ;
}
static void F_281 ( void T_4 * V_5 , struct V_85 * V_318 )
{
static const struct V_493 V_538 [] = {
{ 0x07 , 0 , 0x4000 } ,
{ 0x19 , 0 , 0x0200 } ,
{ 0x19 , 0 , 0x0020 } ,
{ 0x1e , 0 , 0x2000 } ,
{ 0x03 , 0 , 0x0001 } ,
{ 0x19 , 0 , 0x0100 } ,
{ 0x19 , 0 , 0x0004 } ,
{ 0x0a , 0 , 0x0020 }
} ;
F_2 ( V_539 , F_4 ( V_539 ) | 0x002800 ) ;
F_2 ( V_539 , F_4 ( V_539 ) & ~ 0x010000 ) ;
F_7 ( V_520 , F_46 ( V_520 ) | V_540 | V_541 ) ;
F_7 ( V_523 , F_46 ( V_523 ) | V_524 ) ;
F_259 ( V_5 , V_538 , F_66 ( V_538 ) ) ;
}
static void F_282 ( void T_4 * V_5 , struct V_85 * V_318 )
{
F_281 ( V_5 , V_318 ) ;
F_30 ( V_5 , 0x1e , F_31 ( V_5 , 0x1e ) | 0x8000 ) ;
}
static void F_283 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_85 * V_318 = V_2 -> V_85 ;
if ( V_2 -> V_16 == V_265 ||
V_2 -> V_16 == V_267 ) {
int V_487 = F_253 ( V_318 ) ;
if ( V_487 ) {
F_255 ( V_318 , V_487 + V_489 ,
V_501 ) ;
}
}
F_7 ( V_111 , V_112 ) ;
switch ( V_2 -> V_16 ) {
case V_264 :
F_278 ( V_5 , V_318 ) ;
break;
case V_263 :
F_280 ( V_5 , V_318 ) ;
break;
case V_262 :
F_279 ( V_5 , V_318 ) ;
break;
case V_261 :
F_281 ( V_5 , V_318 ) ;
break;
case V_260 :
F_282 ( V_5 , V_318 ) ;
break;
}
F_7 ( V_111 , V_113 ) ;
F_7 ( V_502 , V_503 ) ;
F_248 ( V_5 , V_472 ) ;
V_2 -> V_184 &= ~ V_542 ;
F_41 ( V_188 , V_2 -> V_184 ) ;
F_41 ( V_483 , 0x0000 ) ;
F_246 ( V_2 , V_5 ) ;
F_7 ( V_218 , V_480 | V_219 ) ;
F_244 ( V_2 ) ;
F_46 ( V_68 ) ;
F_251 ( V_40 ) ;
F_41 ( V_485 , F_85 ( V_485 ) & 0xf000 ) ;
F_41 ( V_68 , V_2 -> V_433 ) ;
}
static int F_284 ( struct V_39 * V_40 , int V_543 )
{
if ( V_543 < V_544 || V_543 > V_545 )
return - V_145 ;
V_40 -> V_180 = V_543 ;
F_285 ( V_40 ) ;
return 0 ;
}
static inline void F_286 ( struct V_192 * V_193 )
{
V_193 -> V_48 = F_287 ( 0x0badbadbadbadbadull ) ;
V_193 -> V_546 &= ~ F_288 ( V_547 | V_548 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
void * * V_549 , struct V_192 * V_193 )
{
F_290 ( & V_2 -> V_85 -> V_40 , F_109 ( V_193 -> V_48 ) , V_472 ,
V_550 ) ;
F_126 ( * V_549 ) ;
* V_549 = NULL ;
F_286 ( V_193 ) ;
}
static inline void F_291 ( struct V_192 * V_193 , T_1 V_472 )
{
T_1 V_551 = F_91 ( V_193 -> V_546 ) & V_552 ;
V_193 -> V_546 = F_288 ( V_547 | V_551 | V_472 ) ;
}
static inline void F_292 ( struct V_192 * V_193 , T_5 V_553 ,
T_1 V_472 )
{
V_193 -> V_48 = F_287 ( V_553 ) ;
F_293 () ;
F_291 ( V_193 , V_472 ) ;
}
static inline void * F_294 ( void * V_11 )
{
return ( void * ) F_295 ( ( long ) V_11 , 16 ) ;
}
static struct V_189 * F_296 ( struct V_1 * V_2 ,
struct V_192 * V_193 )
{
void * V_11 ;
T_5 V_553 ;
struct V_212 * V_213 = & V_2 -> V_85 -> V_40 ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_554 = V_40 -> V_40 . V_555 ? F_297 ( V_40 -> V_40 . V_555 ) : - 1 ;
V_11 = F_298 ( V_472 , V_220 , V_554 ) ;
if ( ! V_11 )
return NULL ;
if ( F_294 ( V_11 ) != V_11 ) {
F_126 ( V_11 ) ;
V_11 = F_298 ( V_472 + 15 , V_220 , V_554 ) ;
if ( ! V_11 )
return NULL ;
}
V_553 = F_299 ( V_213 , F_294 ( V_11 ) , V_472 ,
V_550 ) ;
if ( F_300 ( F_301 ( V_213 , V_553 ) ) ) {
if ( F_55 () )
F_120 ( V_2 , V_556 , V_2 -> V_40 , L_33 ) ;
goto V_557;
}
F_292 ( V_193 , V_553 , V_472 ) ;
return V_11 ;
V_557:
F_126 ( V_11 ) ;
return NULL ;
}
static void F_241 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_558 ; V_7 ++ ) {
if ( V_2 -> V_559 [ V_7 ] ) {
F_289 ( V_2 , V_2 -> V_559 + V_7 ,
V_2 -> V_451 + V_7 ) ;
}
}
}
static inline void F_302 ( struct V_192 * V_193 )
{
V_193 -> V_546 |= F_288 ( V_552 ) ;
}
static int F_303 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_558 ; V_7 ++ ) {
void * V_11 ;
if ( V_2 -> V_559 [ V_7 ] )
continue;
V_11 = F_296 ( V_2 , V_2 -> V_451 + V_7 ) ;
if ( ! V_11 ) {
F_286 ( V_2 -> V_451 + V_7 ) ;
goto V_557;
}
V_2 -> V_559 [ V_7 ] = V_11 ;
}
F_302 ( V_2 -> V_451 + V_558 - 1 ) ;
return 0 ;
V_557:
F_241 ( V_2 ) ;
return - V_393 ;
}
static int F_235 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_195 ( V_2 ) ;
memset ( V_2 -> V_560 , 0x0 , V_561 * sizeof( struct V_562 ) ) ;
memset ( V_2 -> V_559 , 0x0 , V_558 * sizeof( void * ) ) ;
return F_303 ( V_2 ) ;
}
static void F_304 ( struct V_212 * V_213 , struct V_562 * V_560 ,
struct V_563 * V_193 )
{
unsigned int V_61 = V_560 -> V_61 ;
F_290 ( V_213 , F_109 ( V_193 -> V_48 ) , V_61 , V_564 ) ;
V_193 -> V_546 = 0x00 ;
V_193 -> V_194 = 0x00 ;
V_193 -> V_48 = 0x00 ;
V_560 -> V_61 = 0 ;
}
static void F_305 ( struct V_1 * V_2 , T_1 V_287 ,
unsigned int V_565 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_565 ; V_7 ++ ) {
unsigned int V_566 = ( V_287 + V_7 ) % V_561 ;
struct V_562 * V_560 = V_2 -> V_560 + V_566 ;
unsigned int V_61 = V_560 -> V_61 ;
if ( V_61 ) {
struct V_189 * V_190 = V_560 -> V_190 ;
F_304 ( & V_2 -> V_85 -> V_40 , V_560 ,
V_2 -> V_447 + V_566 ) ;
if ( V_190 ) {
V_2 -> V_40 -> V_226 . V_567 ++ ;
F_306 ( V_190 ) ;
V_560 -> V_190 = NULL ;
}
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
F_305 ( V_2 , V_2 -> V_379 , V_561 ) ;
V_2 -> V_381 = V_2 -> V_379 = 0 ;
}
static void F_308 ( struct V_39 * V_40 , T_9 V_441 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_309 ( & V_2 -> V_441 , V_441 ) ;
F_310 ( & V_2 -> V_441 , 4 ) ;
}
static void F_311 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
F_312 ( V_40 -> V_333 ) ;
F_313 ( & V_2 -> V_422 ) ;
F_40 ( V_5 ) ;
V_2 -> V_431 = 0xffff ;
F_41 ( V_68 , V_2 -> V_433 ) ;
F_239 ( & V_2 -> V_422 ) ;
}
static void F_314 ( struct V_568 * V_569 )
{
struct V_1 * V_2 =
F_315 ( V_569 , struct V_1 , V_441 . V_569 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_132 ;
F_316 () ;
if ( ! F_50 ( V_40 ) )
goto V_331;
F_311 ( V_40 ) ;
F_317 ( V_40 ) ;
V_132 = F_233 ( V_40 ) ;
if ( F_300 ( V_132 < 0 ) ) {
if ( F_55 () )
F_120 ( V_2 , V_556 , V_40 ,
L_34 ,
V_132 ) ;
F_308 ( V_40 , F_314 ) ;
}
V_331:
F_318 () ;
}
static void F_319 ( struct V_568 * V_569 )
{
struct V_1 * V_2 =
F_315 ( V_569 , struct V_1 , V_441 . V_569 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
int V_7 ;
F_316 () ;
if ( ! F_50 ( V_40 ) )
goto V_331;
F_311 ( V_40 ) ;
for ( V_7 = 0 ; V_7 < V_558 ; V_7 ++ )
F_291 ( V_2 -> V_451 + V_7 , V_472 ) ;
F_307 ( V_2 ) ;
F_243 ( V_2 ) ;
F_240 ( V_40 ) ;
F_320 ( V_40 ) ;
F_60 ( V_40 , V_2 , V_2 -> V_6 ) ;
V_331:
F_318 () ;
}
static void F_321 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_243 ( V_2 ) ;
F_308 ( V_40 , F_319 ) ;
}
static int F_322 ( struct V_1 * V_2 , struct V_189 * V_190 ,
T_1 * V_570 )
{
struct V_571 * V_119 = F_323 ( V_190 ) ;
unsigned int V_572 , V_566 ;
struct V_563 * V_573 ( V_574 ) ;
struct V_212 * V_213 = & V_2 -> V_85 -> V_40 ;
V_566 = V_2 -> V_381 ;
for ( V_572 = 0 ; V_572 < V_119 -> V_575 ; V_572 ++ ) {
T_10 * V_576 = V_119 -> V_577 + V_572 ;
T_5 V_553 ;
T_1 V_196 , V_61 ;
void * V_48 ;
V_566 = ( V_566 + 1 ) % V_561 ;
V_574 = V_2 -> V_447 + V_566 ;
V_61 = V_576 -> V_284 ;
V_48 = ( ( void * ) F_324 ( V_576 -> V_578 ) ) + V_576 -> V_579 ;
V_553 = F_299 ( V_213 , V_48 , V_61 , V_564 ) ;
if ( F_300 ( F_301 ( V_213 , V_553 ) ) ) {
if ( F_55 () )
F_120 ( V_2 , V_556 , V_2 -> V_40 ,
L_35 ) ;
goto V_557;
}
V_196 = V_570 [ 0 ] | V_61 |
( V_552 * ! ( ( V_566 + 1 ) % V_561 ) ) ;
V_574 -> V_546 = F_288 ( V_196 ) ;
V_574 -> V_194 = F_288 ( V_570 [ 1 ] ) ;
V_574 -> V_48 = F_287 ( V_553 ) ;
V_2 -> V_560 [ V_566 ] . V_61 = V_61 ;
}
if ( V_572 ) {
V_2 -> V_560 [ V_566 ] . V_190 = V_190 ;
V_574 -> V_546 |= F_288 ( V_580 ) ;
}
return V_572 ;
V_557:
F_305 ( V_2 , V_2 -> V_381 + 1 , V_572 ) ;
return - V_412 ;
}
static inline void F_325 ( struct V_1 * V_2 ,
struct V_189 * V_190 , T_1 * V_570 )
{
const struct V_581 * V_119 = V_582 + V_2 -> V_414 ;
T_1 V_583 = F_323 ( V_190 ) -> V_584 ;
int V_495 = V_119 -> V_585 ;
if ( V_583 ) {
V_570 [ 0 ] |= V_586 ;
V_570 [ V_495 ] |= F_326 ( V_583 , V_181 ) << V_119 -> V_587 ;
} else if ( V_190 -> V_588 == V_589 ) {
const struct V_590 * V_591 = F_327 ( V_190 ) ;
if ( V_591 -> V_592 == V_593 )
V_570 [ V_495 ] |= V_119 -> V_288 . V_594 ;
else if ( V_591 -> V_592 == V_595 )
V_570 [ V_495 ] |= V_119 -> V_288 . V_596 ;
else
F_328 ( 1 ) ;
}
}
static T_11 F_329 ( struct V_189 * V_190 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
unsigned int V_566 = V_2 -> V_381 % V_561 ;
struct V_563 * V_574 = V_2 -> V_447 + V_566 ;
void T_4 * V_5 = V_2 -> V_6 ;
struct V_212 * V_213 = & V_2 -> V_85 -> V_40 ;
T_5 V_553 ;
T_1 V_196 , V_61 ;
T_1 V_570 [ 2 ] ;
int V_577 ;
if ( F_300 ( F_330 ( V_2 ) < F_323 ( V_190 ) -> V_575 ) ) {
F_120 ( V_2 , V_556 , V_40 , L_36 ) ;
goto V_597;
}
if ( F_300 ( F_91 ( V_574 -> V_546 ) & V_547 ) )
goto V_597;
V_61 = F_331 ( V_190 ) ;
V_553 = F_299 ( V_213 , V_190 -> V_11 , V_61 , V_564 ) ;
if ( F_300 ( F_301 ( V_213 , V_553 ) ) ) {
if ( F_55 () )
F_120 ( V_2 , V_556 , V_40 , L_37 ) ;
goto V_598;
}
V_2 -> V_560 [ V_566 ] . V_61 = V_61 ;
V_574 -> V_48 = F_287 ( V_553 ) ;
V_570 [ 1 ] = F_288 ( F_86 ( V_2 , V_190 ) ) ;
V_570 [ 0 ] = V_547 ;
F_325 ( V_2 , V_190 , V_570 ) ;
V_577 = F_322 ( V_2 , V_190 , V_570 ) ;
if ( V_577 < 0 )
goto V_599;
else if ( V_577 )
V_570 [ 0 ] |= V_600 ;
else {
V_570 [ 0 ] |= V_600 | V_580 ;
V_2 -> V_560 [ V_566 ] . V_190 = V_190 ;
}
V_574 -> V_194 = F_288 ( V_570 [ 1 ] ) ;
F_293 () ;
V_196 = V_570 [ 0 ] | V_61 | ( V_552 * ! ( ( V_566 + 1 ) % V_561 ) ) ;
V_574 -> V_546 = F_288 ( V_196 ) ;
V_2 -> V_381 += V_577 + 1 ;
F_293 () ;
F_7 ( V_460 , V_461 ) ;
if ( F_330 ( V_2 ) < V_601 ) {
F_332 ( V_40 ) ;
F_333 () ;
if ( F_330 ( V_2 ) >= V_601 )
F_320 ( V_40 ) ;
}
return V_602 ;
V_599:
F_304 ( V_213 , V_2 -> V_560 + V_566 , V_574 ) ;
V_598:
F_306 ( V_190 ) ;
V_40 -> V_226 . V_567 ++ ;
return V_602 ;
V_597:
F_332 ( V_40 ) ;
V_40 -> V_226 . V_567 ++ ;
return V_603 ;
}
static void F_334 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_85 * V_318 = V_2 -> V_85 ;
T_3 V_604 , V_605 ;
F_254 ( V_318 , V_606 , & V_605 ) ;
F_254 ( V_318 , V_607 , & V_604 ) ;
F_120 ( V_2 , V_608 , V_40 , L_38 ,
V_605 , V_604 ) ;
if ( V_318 -> V_609 )
V_605 &= ~ V_610 ;
else
V_605 |= V_611 | V_610 ;
F_255 ( V_318 , V_606 , V_605 ) ;
F_255 ( V_318 , V_607 ,
V_604 & ( V_612 |
V_613 | V_614 |
V_615 | V_616 ) ) ;
if ( ( V_2 -> V_184 & V_409 ) && ! V_2 -> V_380 && ! V_2 -> V_382 ) {
void T_4 * V_5 = V_2 -> V_6 ;
F_56 ( V_2 , V_608 , V_40 , L_39 ) ;
V_2 -> V_184 &= ~ V_409 ;
F_41 ( V_188 , V_2 -> V_184 ) ;
V_40 -> V_114 &= ~ V_410 ;
}
F_243 ( V_2 ) ;
F_308 ( V_40 , F_314 ) ;
}
static void F_335 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 )
{
unsigned int V_379 , V_617 ;
V_379 = V_2 -> V_379 ;
F_333 () ;
V_617 = V_2 -> V_381 - V_379 ;
while ( V_617 > 0 ) {
unsigned int V_566 = V_379 % V_561 ;
struct V_562 * V_560 = V_2 -> V_560 + V_566 ;
T_1 V_196 ;
F_336 () ;
V_196 = F_91 ( V_2 -> V_447 [ V_566 ] . V_546 ) ;
if ( V_196 & V_547 )
break;
F_304 ( & V_2 -> V_85 -> V_40 , V_560 ,
V_2 -> V_447 + V_566 ) ;
if ( V_196 & V_580 ) {
V_40 -> V_226 . V_227 ++ ;
V_40 -> V_226 . V_618 += V_560 -> V_190 -> V_61 ;
F_306 ( V_560 -> V_190 ) ;
V_560 -> V_190 = NULL ;
}
V_379 ++ ;
V_617 -- ;
}
if ( V_2 -> V_379 != V_379 ) {
V_2 -> V_379 = V_379 ;
F_337 () ;
if ( F_338 ( V_40 ) &&
( F_330 ( V_2 ) >= V_601 ) ) {
F_320 ( V_40 ) ;
}
F_333 () ;
if ( V_2 -> V_381 != V_379 )
F_7 ( V_460 , V_461 ) ;
}
}
static inline int F_339 ( T_1 V_196 )
{
return ( V_196 & ( V_600 | V_580 ) ) != ( V_600 | V_580 ) ;
}
static inline void F_340 ( struct V_189 * V_190 , T_1 V_546 )
{
T_1 V_196 = V_546 & V_619 ;
if ( ( ( V_196 == V_620 ) && ! ( V_546 & V_621 ) ) ||
( ( V_196 == V_622 ) && ! ( V_546 & V_623 ) ) )
V_190 -> V_588 = V_624 ;
else
F_341 ( V_190 ) ;
}
static struct V_189 * F_342 ( void * V_11 ,
struct V_1 * V_2 ,
int V_625 ,
T_5 V_48 )
{
struct V_189 * V_190 ;
struct V_212 * V_213 = & V_2 -> V_85 -> V_40 ;
V_11 = F_294 ( V_11 ) ;
F_343 ( V_213 , V_48 , V_625 , V_550 ) ;
F_344 ( V_11 ) ;
V_190 = F_345 ( V_2 -> V_40 , V_625 ) ;
if ( V_190 )
memcpy ( V_190 -> V_11 , V_11 , V_625 ) ;
F_346 ( V_213 , V_48 , V_625 , V_550 ) ;
return V_190 ;
}
static int F_347 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
void T_4 * V_5 , T_1 V_626 )
{
unsigned int V_382 , V_627 ;
unsigned int V_314 ;
V_382 = V_2 -> V_382 ;
V_627 = V_558 + V_2 -> V_380 - V_382 ;
V_627 = F_326 ( V_627 , V_626 ) ;
for (; V_627 > 0 ; V_627 -- , V_382 ++ ) {
unsigned int V_566 = V_382 % V_558 ;
struct V_192 * V_193 = V_2 -> V_451 + V_566 ;
T_1 V_196 ;
F_336 () ;
V_196 = F_91 ( V_193 -> V_546 ) & V_2 -> V_435 ;
if ( V_196 & V_547 )
break;
if ( F_300 ( V_196 & V_628 ) ) {
F_56 ( V_2 , V_629 , V_40 , L_40 ,
V_196 ) ;
V_40 -> V_226 . V_230 ++ ;
if ( V_196 & ( V_630 | V_631 ) )
V_40 -> V_226 . V_632 ++ ;
if ( V_196 & V_633 )
V_40 -> V_226 . V_634 ++ ;
if ( V_196 & V_437 ) {
F_308 ( V_40 , F_319 ) ;
V_40 -> V_226 . V_635 ++ ;
}
F_291 ( V_193 , V_472 ) ;
} else {
struct V_189 * V_190 ;
T_5 V_48 = F_109 ( V_193 -> V_48 ) ;
int V_625 = ( V_196 & 0x00001FFF ) - 4 ;
if ( F_300 ( F_339 ( V_196 ) ) ) {
V_40 -> V_226 . V_636 ++ ;
V_40 -> V_226 . V_632 ++ ;
F_291 ( V_193 , V_472 ) ;
continue;
}
V_190 = F_342 ( V_2 -> V_559 [ V_566 ] ,
V_2 , V_625 , V_48 ) ;
F_291 ( V_193 , V_472 ) ;
if ( ! V_190 ) {
V_40 -> V_226 . V_636 ++ ;
continue;
}
F_340 ( V_190 , V_196 ) ;
F_348 ( V_190 , V_625 ) ;
V_190 -> V_592 = F_349 ( V_190 , V_40 ) ;
F_90 ( V_193 , V_190 ) ;
F_350 ( & V_2 -> V_422 , V_190 ) ;
V_40 -> V_226 . V_637 += V_625 ;
V_40 -> V_226 . V_228 ++ ;
}
if ( ( V_193 -> V_194 & F_288 ( 0xfffe000 ) ) &&
( V_2 -> V_16 == V_271 ) ) {
V_193 -> V_194 = 0 ;
V_382 ++ ;
}
}
V_314 = V_382 - V_2 -> V_382 ;
V_2 -> V_382 = V_382 ;
V_2 -> V_380 += V_314 ;
return V_314 ;
}
static T_12 F_154 ( int V_333 , void * V_638 )
{
struct V_39 * V_40 = V_638 ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_639 = 0 ;
int V_196 ;
V_196 = F_85 ( V_69 ) ;
while ( V_196 && V_196 != 0xffff ) {
V_639 = 1 ;
if ( F_300 ( ! F_50 ( V_40 ) ) ) {
F_243 ( V_2 ) ;
break;
}
if ( F_300 ( V_196 & V_528 ) ) {
switch ( V_2 -> V_16 ) {
case V_259 :
case V_256 :
case V_246 :
F_332 ( V_40 ) ;
F_321 ( V_40 ) ;
goto V_640;
case V_258 :
case V_253 :
case V_254 :
case V_255 :
case V_251 :
case V_250 :
case V_248 :
case V_249 :
case V_17 :
case V_257 :
case V_247 :
if ( V_196 == V_528 )
goto V_640;
break;
default:
break;
}
}
if ( F_300 ( V_196 & V_641 ) ) {
F_334 ( V_40 ) ;
break;
}
if ( V_196 & V_642 )
F_51 ( V_40 , V_2 , V_5 , true ) ;
F_333 () ;
if ( V_196 & V_2 -> V_431 & V_2 -> V_434 ) {
F_41 ( V_68 , V_2 -> V_433 & ~ V_2 -> V_434 ) ;
V_2 -> V_431 = ~ V_2 -> V_434 ;
if ( F_351 ( F_352 ( & V_2 -> V_422 ) ) )
F_353 ( & V_2 -> V_422 ) ;
else
F_56 ( V_2 , V_608 , V_40 ,
L_41 , V_196 ) ;
}
F_41 ( V_69 ,
( V_196 & V_528 ) ? ( V_196 | V_530 ) : V_196 ) ;
V_196 = F_85 ( V_69 ) ;
}
V_640:
return F_354 ( V_639 ) ;
}
static int V_423 ( struct V_643 * V_422 , int V_626 )
{
struct V_1 * V_2 = F_315 ( V_422 , struct V_1 , V_422 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
void T_4 * V_5 = V_2 -> V_6 ;
int V_644 ;
V_644 = F_347 ( V_40 , V_2 , V_5 , ( T_1 ) V_626 ) ;
F_335 ( V_40 , V_2 , V_5 ) ;
if ( V_644 < V_626 ) {
F_355 ( V_422 ) ;
V_2 -> V_431 = 0xffff ;
F_293 () ;
F_41 ( V_68 , V_2 -> V_433 ) ;
}
return V_644 ;
}
static void F_356 ( struct V_39 * V_40 , void T_4 * V_5 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( V_2 -> V_16 > V_270 )
return;
V_40 -> V_226 . V_645 += ( F_4 ( V_484 ) & 0xffffff ) ;
F_2 ( V_484 , 0 ) ;
}
static void F_357 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
F_81 ( & V_2 -> V_176 ) ;
F_332 ( V_40 ) ;
F_313 ( & V_2 -> V_422 ) ;
F_63 ( & V_2 -> V_83 ) ;
F_243 ( V_2 ) ;
F_356 ( V_40 , V_5 ) ;
F_64 ( & V_2 -> V_83 ) ;
F_312 ( V_40 -> V_333 ) ;
F_358 () ;
F_307 ( V_2 ) ;
F_241 ( V_2 ) ;
F_191 ( V_2 ) ;
}
static int F_317 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
struct V_85 * V_318 = V_2 -> V_85 ;
F_234 ( & V_318 -> V_40 ) ;
F_103 ( V_40 ) ;
F_357 ( V_40 ) ;
F_359 ( V_40 -> V_333 , V_40 ) ;
F_106 ( & V_318 -> V_40 , V_452 , V_2 -> V_451 ,
V_2 -> V_453 ) ;
F_106 ( & V_318 -> V_40 , V_448 , V_2 -> V_447 ,
V_2 -> V_449 ) ;
V_2 -> V_447 = NULL ;
V_2 -> V_451 = NULL ;
F_360 ( & V_318 -> V_40 ) ;
return 0 ;
}
static void F_251 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_82 ;
T_1 V_646 [ 2 ] ;
int V_647 ;
T_1 V_648 = 0 ;
if ( V_40 -> V_82 & V_649 ) {
F_113 ( V_2 , V_139 , V_40 , L_42 ) ;
V_647 =
V_366 | V_367 | V_368 |
V_650 ;
V_646 [ 1 ] = V_646 [ 0 ] = 0xffffffff ;
} else if ( ( F_361 ( V_40 ) > V_651 ) ||
( V_40 -> V_82 & V_652 ) ) {
V_647 = V_366 | V_367 | V_368 ;
V_646 [ 1 ] = V_646 [ 0 ] = 0xffffffff ;
} else {
struct V_653 * V_654 ;
V_647 = V_366 | V_368 ;
V_646 [ 1 ] = V_646 [ 0 ] = 0 ;
F_362 (ha, dev) {
int V_655 = F_363 ( V_656 , V_654 -> V_48 ) >> 26 ;
V_646 [ V_655 >> 5 ] |= 1 << ( V_655 & 31 ) ;
V_647 |= V_367 ;
}
}
F_52 ( & V_2 -> V_83 , V_82 ) ;
V_648 = ( F_4 ( V_365 ) & ~ V_459 ) | V_647 ;
if ( V_2 -> V_16 > V_270 ) {
T_1 V_11 = V_646 [ 0 ] ;
V_646 [ 0 ] = F_364 ( V_646 [ 1 ] ) ;
V_646 [ 1 ] = F_364 ( V_11 ) ;
}
F_2 ( V_657 + 4 , V_646 [ 1 ] ) ;
F_2 ( V_657 + 0 , V_646 [ 0 ] ) ;
F_2 ( V_365 , V_648 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
}
static struct V_658 * F_365 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
void T_4 * V_5 = V_2 -> V_6 ;
unsigned long V_82 ;
if ( F_50 ( V_40 ) ) {
F_52 ( & V_2 -> V_83 , V_82 ) ;
F_356 ( V_40 , V_5 ) ;
F_59 ( & V_2 -> V_83 , V_82 ) ;
}
return & V_40 -> V_226 ;
}
static void F_366 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! F_50 ( V_40 ) )
return;
F_191 ( V_2 ) ;
F_367 ( V_40 ) ;
F_332 ( V_40 ) ;
}
static int F_368 ( struct V_212 * V_212 )
{
struct V_85 * V_318 = F_369 ( V_212 ) ;
struct V_39 * V_40 = F_224 ( V_318 ) ;
F_366 ( V_40 ) ;
return 0 ;
}
static void F_370 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_371 ( V_40 ) ;
F_192 ( V_2 ) ;
F_308 ( V_40 , F_319 ) ;
}
static int F_372 ( struct V_212 * V_212 )
{
struct V_85 * V_318 = F_369 ( V_212 ) ;
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_164 ( V_40 , V_2 ) ;
if ( F_50 ( V_40 ) )
F_370 ( V_40 ) ;
return 0 ;
}
static int F_373 ( struct V_212 * V_212 )
{
struct V_85 * V_318 = F_369 ( V_212 ) ;
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! V_2 -> V_447 )
return 0 ;
F_63 ( & V_2 -> V_83 ) ;
V_2 -> V_458 = F_61 ( V_2 ) ;
F_65 ( V_2 , V_107 ) ;
F_64 ( & V_2 -> V_83 ) ;
F_366 ( V_40 ) ;
return 0 ;
}
static int F_374 ( struct V_212 * V_212 )
{
struct V_85 * V_318 = F_369 ( V_212 ) ;
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
if ( ! V_2 -> V_447 )
return 0 ;
F_63 ( & V_2 -> V_83 ) ;
F_65 ( V_2 , V_2 -> V_458 ) ;
V_2 -> V_458 = 0 ;
F_64 ( & V_2 -> V_83 ) ;
F_164 ( V_40 , V_2 ) ;
F_370 ( V_40 ) ;
return 0 ;
}
static int F_375 ( struct V_212 * V_212 )
{
struct V_85 * V_318 = F_369 ( V_212 ) ;
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
return V_2 -> V_447 ? - V_659 : 0 ;
}
static void F_376 ( struct V_1 * V_2 )
{
void T_4 * V_5 = V_2 -> V_6 ;
switch ( V_2 -> V_16 ) {
case V_259 :
case V_257 :
case V_258 :
F_377 ( V_2 -> V_85 ) ;
F_7 ( V_218 , V_219 ) ;
F_46 ( V_218 ) ;
break;
default:
break;
}
}
static void F_378 ( struct V_85 * V_318 )
{
struct V_39 * V_40 = F_224 ( V_318 ) ;
struct V_1 * V_2 = F_28 ( V_40 ) ;
F_366 ( V_40 ) ;
F_166 ( V_2 , V_40 -> V_417 ) ;
F_63 ( & V_2 -> V_83 ) ;
F_243 ( V_2 ) ;
F_64 ( & V_2 -> V_83 ) ;
if ( V_660 == V_661 ) {
if ( F_61 ( V_2 ) & V_107 ) {
F_179 ( V_2 ) ;
F_376 ( V_2 ) ;
}
F_379 ( V_318 , true ) ;
F_380 ( V_318 , V_662 ) ;
}
}
static int T_13 F_381 ( void )
{
return F_382 ( & V_663 ) ;
}
static void T_14 F_383 ( void )
{
F_384 ( & V_663 ) ;
}
