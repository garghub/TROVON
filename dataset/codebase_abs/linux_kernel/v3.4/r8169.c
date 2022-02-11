static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 . V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 , T_1 V_7 )
{
int V_8 = F_6 ( V_6 ) ;
if ( V_8 ) {
T_1 V_9 ;
F_7 ( V_6 , V_8 + V_10 , & V_9 ) ;
V_9 = ( V_9 & ~ V_11 ) | V_7 ;
F_8 ( V_6 , V_8 + V_10 , V_9 ) ;
}
}
static T_2 F_9 ( struct V_1 * V_2 , T_3 V_12 , T_1 V_13 )
{
void T_4 * V_14 = V_2 -> V_15 ;
int V_16 ;
F_10 ( V_17 , ( ( T_2 ) V_12 & 0x0f ) << 12 | ( V_13 & 0x0fff ) ) ;
for ( V_16 = 0 ; V_16 < 20 ; V_16 ++ ) {
F_11 ( 100 ) ;
if ( F_12 ( V_17 ) & V_18 )
break;
}
return F_12 ( V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_12 , T_1 V_13 , T_2 V_20 )
{
void T_4 * V_14 = V_2 -> V_15 ;
int V_16 ;
F_10 ( V_19 , V_20 ) ;
F_10 ( V_17 , V_18 | ( ( T_2 ) V_12 & 0x0f ) << 12 | ( V_13 & 0x0fff ) ) ;
for ( V_16 = 0 ; V_16 < 20 ; V_16 ++ ) {
F_11 ( 100 ) ;
if ( ( F_12 ( V_17 ) & V_18 ) == 0 )
break;
}
}
static void F_14 ( struct V_1 * V_2 , T_3 V_21 )
{
void T_4 * V_14 = V_2 -> V_15 ;
int V_16 ;
F_15 ( V_22 , V_21 ) ;
F_10 ( V_23 , 0x800010e8 ) ;
F_16 ( 2 ) ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
F_11 ( 100 ) ;
if ( ! ( F_12 ( V_23 ) & V_24 ) )
break;
}
F_13 ( V_2 , 0x1 , 0x30 , 0x00000001 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
return ( V_2 -> V_25 == V_26 ) ? 0xb8 : 0x10 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_16 ;
F_14 ( V_2 , V_27 ) ;
V_13 = F_17 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
F_16 ( 10 ) ;
if ( F_9 ( V_2 , 0x0f , V_13 ) & 0x00000800 )
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_16 ;
F_14 ( V_2 , V_28 ) ;
V_13 = F_17 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
F_16 ( 10 ) ;
if ( ( F_9 ( V_2 , 0x0f , V_13 ) & 0x00000800 ) == 0 )
break;
}
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_13 = F_17 ( V_2 ) ;
return ( F_9 ( V_2 , 0x0f , V_13 ) & 0x00008000 ) ? 1 : 0 ;
}
static void F_21 ( void T_4 * V_14 , int V_29 , int V_30 )
{
int V_16 ;
F_10 ( V_31 , 0x80000000 | ( V_29 & 0x1f ) << 16 | ( V_30 & 0xffff ) ) ;
for ( V_16 = 20 ; V_16 > 0 ; V_16 -- ) {
if ( ! ( F_12 ( V_31 ) & 0x80000000 ) )
break;
F_11 ( 25 ) ;
}
F_11 ( 20 ) ;
}
static int F_22 ( void T_4 * V_14 , int V_29 )
{
int V_16 , V_30 = - 1 ;
F_10 ( V_31 , 0x0 | ( V_29 & 0x1f ) << 16 ) ;
for ( V_16 = 20 ; V_16 > 0 ; V_16 -- ) {
if ( F_12 ( V_31 ) & 0x80000000 ) {
V_30 = F_12 ( V_31 ) & 0xffff ;
break;
}
F_11 ( 25 ) ;
}
F_11 ( 20 ) ;
return V_30 ;
}
static void F_23 ( void T_4 * V_14 , int V_29 , T_2 V_20 )
{
int V_16 ;
F_10 ( V_19 , V_20 |
( ( V_29 & V_32 ) << V_33 ) ) ;
F_10 ( V_17 , V_34 ) ;
F_10 ( V_35 , 0 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
F_24 ( 1 ) ;
if ( ! ( F_12 ( V_17 ) & V_18 ) )
break;
}
}
static void F_25 ( void T_4 * V_14 , int V_29 , int V_30 )
{
F_23 ( V_14 , V_29 , V_36 |
( V_30 & V_37 ) ) ;
}
static int F_26 ( void T_4 * V_14 , int V_29 )
{
int V_16 ;
F_23 ( V_14 , V_29 , V_38 ) ;
F_24 ( 1 ) ;
F_10 ( V_17 , V_39 ) ;
F_10 ( V_35 , 0 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
F_24 ( 1 ) ;
if ( F_12 ( V_17 ) & V_18 )
break;
}
return F_12 ( V_19 ) & V_37 ;
}
static void F_27 ( void T_4 * V_14 )
{
F_10 ( 0xd0 , F_12 ( 0xd0 ) & ~ V_40 ) ;
}
static void F_28 ( void T_4 * V_14 )
{
F_10 ( 0xd0 , F_12 ( 0xd0 ) | V_40 ) ;
}
static void F_29 ( void T_4 * V_14 , int V_29 , int V_30 )
{
F_27 ( V_14 ) ;
F_21 ( V_14 , V_29 , V_30 ) ;
F_28 ( V_14 ) ;
}
static int F_30 ( void T_4 * V_14 , int V_29 )
{
int V_30 ;
F_27 ( V_14 ) ;
V_30 = F_22 ( V_14 , V_29 ) ;
F_28 ( V_14 ) ;
return V_30 ;
}
static void F_31 ( struct V_1 * V_2 , int V_41 , T_2 V_42 )
{
V_2 -> V_43 . V_44 ( V_2 -> V_15 , V_41 , V_42 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_41 )
{
return V_2 -> V_43 . V_45 ( V_2 -> V_15 , V_41 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_29 , int V_30 )
{
F_31 ( V_2 , V_29 , F_32 ( V_2 , V_29 ) | V_30 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_29 , int V_46 , int V_47 )
{
int V_42 ;
V_42 = F_32 ( V_2 , V_29 ) ;
F_31 ( V_2 , V_29 , ( V_42 | V_46 ) & ~ V_47 ) ;
}
static void F_35 ( struct V_48 * V_49 , int V_50 , int V_41 ,
int V_42 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_31 ( V_2 , V_41 , V_42 ) ;
}
static int F_37 ( struct V_48 * V_49 , int V_50 , int V_41 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
return F_32 ( V_2 , V_41 ) ;
}
static void F_38 ( void T_4 * V_14 , int V_29 , int V_30 )
{
unsigned int V_16 ;
F_10 ( V_51 , V_52 | ( V_30 & V_53 ) |
( V_29 & V_54 ) << V_55 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_12 ( V_51 ) & V_56 ) )
break;
F_11 ( 10 ) ;
}
}
static T_1 F_39 ( void T_4 * V_14 , int V_29 )
{
T_1 V_30 = 0xffff ;
unsigned int V_16 ;
F_10 ( V_51 , ( V_29 & V_54 ) << V_55 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( F_12 ( V_51 ) & V_56 ) {
V_30 = F_12 ( V_51 ) & V_53 ;
break;
}
F_11 ( 10 ) ;
}
return V_30 ;
}
static void F_40 ( void T_4 * V_14 , int V_57 , int V_30 )
{
unsigned int V_16 ;
F_10 ( V_58 , V_30 ) ;
F_10 ( V_59 , V_60 | ( V_57 & V_61 ) |
V_62 << V_63 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_12 ( V_59 ) & V_64 ) )
break;
F_11 ( 10 ) ;
}
}
static T_2 F_41 ( void T_4 * V_14 , int V_57 )
{
T_2 V_30 = ~ 0x00 ;
unsigned int V_16 ;
F_10 ( V_59 , ( V_57 & V_61 ) |
V_62 << V_63 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( F_12 ( V_59 ) & V_64 ) {
V_30 = F_12 ( V_58 ) ;
break;
}
F_11 ( 10 ) ;
}
return V_30 ;
}
static
void F_42 ( void T_4 * V_14 , int V_57 , T_2 V_12 , T_2 V_42 , int type )
{
unsigned int V_16 ;
F_43 ( ( V_57 & 3 ) || ( V_12 == 0 ) ) ;
F_10 ( V_22 , V_42 ) ;
F_10 ( V_23 , V_65 | type | V_12 | V_57 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_12 ( V_23 ) & V_24 ) )
break;
F_11 ( 100 ) ;
}
}
static T_2 F_44 ( void T_4 * V_14 , int V_57 , int type )
{
T_2 V_30 = ~ 0x00 ;
unsigned int V_16 ;
F_10 ( V_23 , V_66 | type | V_67 | V_57 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( F_12 ( V_23 ) & V_24 ) {
V_30 = F_12 ( V_22 ) ;
break;
}
F_11 ( 100 ) ;
}
return V_30 ;
}
static void
F_45 ( void T_4 * V_14 , int V_57 , T_2 V_12 , T_2 V_46 , T_2 V_47 , int type )
{
T_2 V_42 ;
V_42 = F_44 ( V_14 , V_57 , type ) ;
F_42 ( V_14 , V_57 , V_12 , ( V_42 & ~ V_47 ) | V_46 , type ) ;
}
static void F_46 ( void T_4 * V_14 ,
const struct V_68 * V_69 , int V_70 )
{
while ( V_70 -- > 0 ) {
F_42 ( V_14 , V_69 -> V_57 , V_69 -> V_12 , V_69 -> V_42 , V_71 ) ;
V_69 ++ ;
}
}
static T_3 F_47 ( void T_4 * V_14 , int V_29 )
{
T_3 V_30 = 0xff ;
unsigned int V_16 ;
F_10 ( V_72 , ( V_29 & V_73 ) << V_74 ) ;
for ( V_16 = 0 ; V_16 < 300 ; V_16 ++ ) {
if ( F_12 ( V_72 ) & V_75 ) {
V_30 = F_12 ( V_72 ) & V_76 ;
break;
}
F_11 ( 100 ) ;
}
return V_30 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
return F_49 ( V_77 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_78 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_51 ( V_77 , V_78 ) ;
F_52 () ;
}
static void F_53 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_51 ( V_79 , 0 ) ;
F_52 () ;
}
static void F_54 ( struct V_1 * V_2 , T_1 V_78 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_51 ( V_79 , V_78 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_54 ( V_2 , V_80 | V_2 -> V_81 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_53 ( V_2 ) ;
F_50 ( V_2 , V_80 | V_2 -> V_81 ) ;
F_57 ( V_82 ) ;
}
static unsigned int F_58 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
return F_12 ( V_83 ) & V_84 ;
}
static unsigned int F_59 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , V_85 ) & V_86 ;
}
static unsigned int F_60 ( void T_4 * V_14 )
{
return F_12 ( V_83 ) & V_87 ;
}
static unsigned int F_61 ( void T_4 * V_14 )
{
return F_57 ( V_88 ) & V_89 ;
}
static void F_62 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_10 ( V_83 , F_12 ( V_83 ) | V_84 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
V_42 = F_32 ( V_2 , V_85 ) | V_86 ;
F_31 ( V_2 , V_85 , V_42 & 0xffff ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
struct V_48 * V_49 = V_2 -> V_49 ;
if ( ! F_65 ( V_49 ) )
return;
if ( V_2 -> V_25 == V_90 ) {
if ( F_57 ( V_88 ) & V_91 ) {
F_42 ( V_14 , 0x1bc , V_67 ,
0x00000011 , V_71 ) ;
F_42 ( V_14 , 0x1dc , V_67 ,
0x00000005 , V_71 ) ;
} else if ( F_57 ( V_88 ) & V_92 ) {
F_42 ( V_14 , 0x1bc , V_67 ,
0x0000001f , V_71 ) ;
F_42 ( V_14 , 0x1dc , V_67 ,
0x00000005 , V_71 ) ;
} else {
F_42 ( V_14 , 0x1bc , V_67 ,
0x0000001f , V_71 ) ;
F_42 ( V_14 , 0x1dc , V_67 ,
0x0000003f , V_71 ) ;
}
F_45 ( V_14 , 0xdc , V_93 , 0x00 , 0x01 ,
V_71 ) ;
F_45 ( V_14 , 0xdc , V_93 , 0x01 , 0x00 ,
V_71 ) ;
} else if ( V_2 -> V_25 == V_94 ||
V_2 -> V_25 == V_95 ) {
if ( F_57 ( V_88 ) & V_91 ) {
F_42 ( V_14 , 0x1bc , V_67 ,
0x00000011 , V_71 ) ;
F_42 ( V_14 , 0x1dc , V_67 ,
0x00000005 , V_71 ) ;
} else {
F_42 ( V_14 , 0x1bc , V_67 ,
0x0000001f , V_71 ) ;
F_42 ( V_14 , 0x1dc , V_67 ,
0x0000003f , V_71 ) ;
}
}
}
static void F_66 ( struct V_48 * V_49 ,
struct V_1 * V_2 ,
void T_4 * V_14 , bool V_96 )
{
if ( V_2 -> V_97 ( V_14 ) ) {
F_64 ( V_2 ) ;
if ( V_96 )
F_67 ( & V_2 -> V_5 -> V_49 ) ;
F_68 ( V_49 ) ;
if ( F_69 () )
F_70 ( V_2 , V_98 , V_49 , L_1 ) ;
} else {
F_71 ( V_49 ) ;
F_70 ( V_2 , V_99 , V_49 , L_2 ) ;
if ( V_96 )
F_72 ( & V_2 -> V_5 -> V_49 , 5000 ) ;
}
}
static void F_73 ( struct V_48 * V_49 ,
struct V_1 * V_2 ,
void T_4 * V_14 )
{
F_66 ( V_49 , V_2 , V_14 , false ) ;
}
static T_2 F_74 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
T_3 V_100 ;
T_2 V_101 = 0 ;
V_100 = F_57 ( V_102 ) ;
if ( ! ( V_100 & V_103 ) )
return 0 ;
V_100 = F_57 ( V_104 ) ;
if ( V_100 & V_105 )
V_101 |= V_106 ;
if ( V_100 & V_107 )
V_101 |= V_108 ;
V_100 = F_57 ( V_109 ) ;
if ( V_100 & V_110 )
V_101 |= V_111 ;
if ( V_100 & V_112 )
V_101 |= V_113 ;
if ( V_100 & V_114 )
V_101 |= V_115 ;
return V_101 ;
}
static void F_75 ( struct V_48 * V_49 , struct V_116 * V_117 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_1 ( V_2 ) ;
V_117 -> V_118 = V_119 ;
V_117 -> V_101 = F_74 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 , T_2 V_101 )
{
void T_4 * V_14 = V_2 -> V_15 ;
unsigned int V_16 ;
static const struct {
T_2 V_120 ;
T_1 V_13 ;
T_3 V_12 ;
} V_121 [] = {
{ V_119 , V_102 , V_103 } ,
{ V_106 , V_104 , V_105 } ,
{ V_108 , V_104 , V_107 } ,
{ V_111 , V_109 , V_110 } ,
{ V_113 , V_109 , V_112 } ,
{ V_115 , V_109 , V_114 } ,
{ V_119 , V_109 , V_122 }
} ;
F_15 ( V_123 , V_124 ) ;
for ( V_16 = 0 ; V_16 < F_77 ( V_121 ) ; V_16 ++ ) {
T_3 V_100 = F_57 ( V_121 [ V_16 ] . V_13 ) & ~ V_121 [ V_16 ] . V_12 ;
if ( V_101 & V_121 [ V_16 ] . V_120 )
V_100 |= V_121 [ V_16 ] . V_12 ;
F_15 ( V_121 [ V_16 ] . V_13 , V_100 ) ;
}
F_15 ( V_123 , V_125 ) ;
}
static int F_78 ( struct V_48 * V_49 , struct V_116 * V_117 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_1 ( V_2 ) ;
if ( V_117 -> V_101 )
V_2 -> V_126 |= V_127 ;
else
V_2 -> V_126 &= ~ V_127 ;
F_76 ( V_2 , V_117 -> V_101 ) ;
F_3 ( V_2 ) ;
F_79 ( & V_2 -> V_5 -> V_49 , V_117 -> V_101 ) ;
return 0 ;
}
static const char * F_80 ( struct V_1 * V_2 )
{
return V_128 [ V_2 -> V_25 ] . V_129 ;
}
static void F_81 ( struct V_48 * V_49 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_132 * V_132 = V_2 -> V_132 ;
F_82 ( V_131 -> V_133 , V_134 , sizeof( V_131 -> V_133 ) ) ;
F_82 ( V_131 -> V_135 , V_136 , sizeof( V_131 -> V_135 ) ) ;
F_82 ( V_131 -> V_137 , F_83 ( V_2 -> V_5 ) , sizeof( V_131 -> V_137 ) ) ;
F_84 ( sizeof( V_131 -> V_138 ) < sizeof( V_132 -> V_135 ) ) ;
if ( ! F_85 ( V_132 ) )
F_82 ( V_131 -> V_138 , V_132 -> V_135 ,
sizeof( V_131 -> V_138 ) ) ;
}
static int F_86 ( struct V_48 * V_49 )
{
return V_139 ;
}
static int F_87 ( struct V_48 * V_49 ,
T_3 V_140 , T_1 V_141 , T_3 V_142 , T_2 V_143 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
int V_144 = 0 ;
T_2 V_13 ;
V_13 = F_12 ( V_83 ) ;
if ( ( V_140 == V_145 ) && ( V_141 == V_146 ) &&
( V_142 == V_147 ) ) {
F_10 ( V_83 , V_13 & ~ ( V_148 | V_149 ) ) ;
} else if ( V_140 == V_150 )
F_10 ( V_83 , V_13 | V_148 | V_149 ) ;
else {
F_88 ( V_2 , V_151 , V_49 ,
L_3 ) ;
V_144 = - V_152 ;
}
return V_144 ;
}
static int F_89 ( struct V_48 * V_49 ,
T_3 V_140 , T_1 V_141 , T_3 V_142 , T_2 V_153 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
int V_154 , V_155 ;
int V_156 = - V_157 ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
if ( V_140 == V_150 ) {
int V_158 ;
V_158 = F_32 ( V_2 , V_159 ) ;
V_158 &= ~ ( V_160 | V_161 |
V_162 | V_163 ) ;
if ( V_153 & V_164 )
V_158 |= V_160 ;
if ( V_153 & V_165 )
V_158 |= V_161 ;
if ( V_153 & V_166 )
V_158 |= V_162 ;
if ( V_153 & V_167 )
V_158 |= V_163 ;
V_158 |= V_168 | V_169 ;
V_154 = F_32 ( V_2 , V_170 ) ;
V_154 &= ~ ( V_171 | V_172 ) ;
if ( V_2 -> V_173 . V_174 ) {
if ( V_153 & V_175 )
V_154 |= V_172 ;
if ( V_153 & V_176 )
V_154 |= V_171 ;
} else if ( V_153 & ( V_175 |
V_176 ) ) {
F_70 ( V_2 , V_151 , V_49 ,
L_4 ) ;
goto V_177;
}
V_155 = V_178 | V_179 ;
F_31 ( V_2 , V_159 , V_158 ) ;
F_31 ( V_2 , V_170 , V_154 ) ;
} else {
V_154 = 0 ;
if ( V_141 == V_180 )
V_155 = 0 ;
else if ( V_141 == V_181 )
V_155 = V_182 ;
else
goto V_177;
if ( V_142 == V_147 )
V_155 |= V_183 ;
}
F_31 ( V_2 , V_85 , V_155 ) ;
if ( V_2 -> V_25 == V_184 ||
V_2 -> V_25 == V_185 ) {
if ( ( V_141 == V_181 ) && ( V_140 != V_150 ) ) {
F_31 ( V_2 , 0x17 , 0x2138 ) ;
F_31 ( V_2 , 0x0e , 0x0260 ) ;
} else {
F_31 ( V_2 , 0x17 , 0x2108 ) ;
F_31 ( V_2 , 0x0e , 0x0000 ) ;
}
}
V_156 = 0 ;
V_177:
return V_156 ;
}
static int F_90 ( struct V_48 * V_49 ,
T_3 V_140 , T_1 V_141 , T_3 V_142 , T_2 V_186 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
int V_144 ;
V_144 = V_2 -> V_187 ( V_49 , V_140 , V_141 , V_142 , V_186 ) ;
if ( V_144 < 0 )
goto V_177;
if ( F_65 ( V_49 ) && ( V_140 == V_150 ) &&
( V_186 & V_176 ) ) {
F_91 ( & V_2 -> V_188 , V_189 + V_190 ) ;
}
V_177:
return V_144 ;
}
static int F_92 ( struct V_48 * V_49 , struct V_191 * V_21 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
int V_144 ;
F_93 ( & V_2 -> V_188 ) ;
F_1 ( V_2 ) ;
V_144 = F_90 ( V_49 , V_21 -> V_140 , F_94 ( V_21 ) ,
V_21 -> V_142 , V_21 -> V_186 ) ;
F_3 ( V_2 ) ;
return V_144 ;
}
static T_5 F_95 ( struct V_48 * V_49 ,
T_5 V_126 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( V_49 -> V_192 > V_193 )
V_126 &= ~ V_194 ;
if ( V_49 -> V_192 > V_195 &&
! V_128 [ V_2 -> V_25 ] . V_196 )
V_126 &= ~ V_197 ;
return V_126 ;
}
static void F_96 ( struct V_48 * V_49 ,
T_5 V_126 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
T_5 V_198 = V_126 ^ V_49 -> V_126 ;
void T_4 * V_14 = V_2 -> V_15 ;
if ( ! ( V_198 & ( V_199 | V_200 | V_201 ) ) )
return;
if ( V_198 & ( V_200 | V_201 ) ) {
if ( V_126 & V_200 )
V_2 -> V_202 |= V_203 ;
else
V_2 -> V_202 &= ~ V_203 ;
if ( V_49 -> V_126 & V_201 )
V_2 -> V_202 |= V_204 ;
else
V_2 -> V_202 &= ~ V_204 ;
F_51 ( V_205 , V_2 -> V_202 ) ;
F_49 ( V_205 ) ;
}
if ( V_198 & V_199 ) {
int V_206 = ( F_12 ( V_207 ) & ~ ( V_208 | V_209 ) ) ;
if ( V_126 & V_199 )
V_206 |= ( V_208 | V_209 ) ;
F_10 ( V_207 , V_206 ) ;
}
}
static int F_97 ( struct V_48 * V_49 ,
T_5 V_126 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_1 ( V_2 ) ;
F_96 ( V_49 , V_126 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static inline T_2 F_98 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
return ( F_99 ( V_211 ) ) ?
V_212 | F_100 ( F_101 ( V_211 ) ) : 0x00 ;
}
static void F_102 ( struct V_213 * V_214 , struct V_210 * V_211 )
{
T_2 V_215 = F_103 ( V_214 -> V_215 ) ;
if ( V_215 & V_216 )
F_104 ( V_211 , F_100 ( V_215 & 0xffff ) ) ;
V_214 -> V_215 = 0 ;
}
static int F_105 ( struct V_48 * V_49 , struct V_191 * V_21 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
T_2 V_217 ;
V_21 -> V_118 =
V_218 | V_219 | V_220 ;
V_21 -> V_221 = V_222 ;
V_21 -> V_223 = V_224 ;
V_217 = F_12 ( V_83 ) ;
V_21 -> V_186 = ( V_217 & V_148 ) ? V_225 : 0 ;
V_21 -> V_140 = ! ! ( V_217 & V_148 ) ;
F_106 ( V_21 , V_146 ) ;
V_21 -> V_142 = V_147 ;
return 0 ;
}
static int F_107 ( struct V_48 * V_49 , struct V_191 * V_21 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
return F_108 ( & V_2 -> V_173 , V_21 ) ;
}
static int F_109 ( struct V_48 * V_49 , struct V_191 * V_21 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
int V_156 ;
F_1 ( V_2 ) ;
V_156 = V_2 -> V_226 ( V_49 , V_21 ) ;
F_3 ( V_2 ) ;
return V_156 ;
}
static void F_110 ( struct V_48 * V_49 , struct V_227 * V_228 ,
void * V_46 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( V_228 -> V_70 > V_139 )
V_228 -> V_70 = V_139 ;
F_1 ( V_2 ) ;
F_111 ( V_46 , V_2 -> V_15 , V_228 -> V_70 ) ;
F_3 ( V_2 ) ;
}
static T_2 F_112 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
return V_2 -> V_229 ;
}
static void F_113 ( struct V_48 * V_49 , T_2 V_30 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
V_2 -> V_229 = V_30 ;
}
static int F_114 ( struct V_48 * V_49 , int V_230 )
{
switch ( V_230 ) {
case V_231 :
return F_77 ( V_232 ) ;
default:
return - V_152 ;
}
}
static void F_115 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_233 * V_234 = & V_2 -> V_5 -> V_49 ;
struct V_235 * V_236 ;
T_6 V_237 ;
T_2 V_21 ;
int V_238 = 1000 ;
if ( ( F_57 ( V_82 ) & V_239 ) == 0 )
return;
V_236 = F_116 ( V_234 , sizeof( * V_236 ) , & V_237 , V_240 ) ;
if ( ! V_236 )
return;
F_10 ( V_241 , ( V_242 ) V_237 >> 32 ) ;
V_21 = ( V_242 ) V_237 & F_117 ( 32 ) ;
F_10 ( V_243 , V_21 ) ;
F_10 ( V_243 , V_21 | V_244 ) ;
while ( V_238 -- ) {
if ( ( F_12 ( V_243 ) & V_244 ) == 0 ) {
memcpy ( & V_2 -> V_236 , V_236 , sizeof( * V_236 ) ) ;
break;
}
F_11 ( 10 ) ;
}
F_10 ( V_243 , 0 ) ;
F_10 ( V_241 , 0 ) ;
F_118 ( V_234 , sizeof( * V_236 ) , V_236 , V_237 ) ;
}
static void F_119 ( struct V_48 * V_49 ,
struct V_245 * V_246 , V_242 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_120 () ;
F_115 ( V_49 ) ;
V_20 [ 0 ] = F_121 ( V_2 -> V_236 . V_247 ) ;
V_20 [ 1 ] = F_121 ( V_2 -> V_236 . V_248 ) ;
V_20 [ 2 ] = F_121 ( V_2 -> V_236 . V_249 ) ;
V_20 [ 3 ] = F_103 ( V_2 -> V_236 . V_250 ) ;
V_20 [ 4 ] = F_122 ( V_2 -> V_236 . V_251 ) ;
V_20 [ 5 ] = F_122 ( V_2 -> V_236 . V_252 ) ;
V_20 [ 6 ] = F_103 ( V_2 -> V_236 . V_253 ) ;
V_20 [ 7 ] = F_103 ( V_2 -> V_236 . V_254 ) ;
V_20 [ 8 ] = F_121 ( V_2 -> V_236 . V_255 ) ;
V_20 [ 9 ] = F_121 ( V_2 -> V_236 . V_256 ) ;
V_20 [ 10 ] = F_103 ( V_2 -> V_236 . V_257 ) ;
V_20 [ 11 ] = F_122 ( V_2 -> V_236 . V_258 ) ;
V_20 [ 12 ] = F_122 ( V_2 -> V_236 . V_259 ) ;
}
static void F_123 ( struct V_48 * V_49 , T_2 V_260 , T_3 * V_20 )
{
switch( V_260 ) {
case V_231 :
memcpy ( V_20 , * V_232 , sizeof( V_232 ) ) ;
break;
}
}
static void F_124 ( struct V_1 * V_2 ,
struct V_48 * V_49 , T_3 V_261 )
{
void T_4 * V_14 = V_2 -> V_15 ;
static const struct V_262 {
T_2 V_12 ;
T_2 V_42 ;
int V_25 ;
} V_263 [] = {
{ 0x7cf00000 , 0x48100000 , V_95 } ,
{ 0x7cf00000 , 0x48000000 , V_94 } ,
{ 0x7c800000 , 0x2c800000 , V_90 } ,
{ 0x7cf00000 , 0x2c200000 , V_264 } ,
{ 0x7cf00000 , 0x2c100000 , V_265 } ,
{ 0x7c800000 , 0x2c000000 , V_264 } ,
{ 0x7cf00000 , 0x28300000 , V_266 } ,
{ 0x7cf00000 , 0x28100000 , V_267 } ,
{ 0x7c800000 , 0x28000000 , V_266 } ,
{ 0x7cf00000 , 0x28800000 , V_268 } ,
{ 0x7cf00000 , 0x28a00000 , V_269 } ,
{ 0x7cf00000 , 0x28b00000 , V_26 } ,
{ 0x7cf00000 , 0x3cb00000 , V_270 } ,
{ 0x7cf00000 , 0x3c900000 , V_271 } ,
{ 0x7cf00000 , 0x3c800000 , V_272 } ,
{ 0x7c800000 , 0x3c800000 , V_270 } ,
{ 0x7cf00000 , 0x3c000000 , V_273 } ,
{ 0x7cf00000 , 0x3c200000 , V_274 } ,
{ 0x7cf00000 , 0x3c300000 , V_275 } ,
{ 0x7cf00000 , 0x3c400000 , V_276 } ,
{ 0x7c800000 , 0x3c000000 , V_276 } ,
{ 0x7cf00000 , 0x38000000 , V_277 } ,
{ 0x7cf00000 , 0x38500000 , V_278 } ,
{ 0x7c800000 , 0x38000000 , V_278 } ,
{ 0x7c800000 , 0x30000000 , V_279 } ,
{ 0x7cf00000 , 0x40b00000 , V_280 } ,
{ 0x7cf00000 , 0x40a00000 , V_280 } ,
{ 0x7cf00000 , 0x40900000 , V_281 } ,
{ 0x7c800000 , 0x40800000 , V_280 } ,
{ 0x7cf00000 , 0x34a00000 , V_282 } ,
{ 0x7cf00000 , 0x24a00000 , V_282 } ,
{ 0x7cf00000 , 0x34900000 , V_283 } ,
{ 0x7cf00000 , 0x24900000 , V_283 } ,
{ 0x7cf00000 , 0x34800000 , V_284 } ,
{ 0x7cf00000 , 0x24800000 , V_284 } ,
{ 0x7cf00000 , 0x34000000 , V_285 } ,
{ 0x7cf00000 , 0x34300000 , V_286 } ,
{ 0x7cf00000 , 0x34200000 , V_287 } ,
{ 0x7c800000 , 0x34800000 , V_282 } ,
{ 0x7c800000 , 0x24800000 , V_282 } ,
{ 0x7c800000 , 0x34000000 , V_287 } ,
{ 0xfc800000 , 0x38800000 , V_288 } ,
{ 0xfc800000 , 0x30800000 , V_289 } ,
{ 0xfc800000 , 0x98000000 , V_290 } ,
{ 0xfc800000 , 0x18000000 , V_291 } ,
{ 0xfc800000 , 0x10000000 , V_292 } ,
{ 0xfc800000 , 0x04000000 , V_185 } ,
{ 0xfc800000 , 0x00800000 , V_184 } ,
{ 0xfc800000 , 0x00000000 , V_293 } ,
{ 0x00000000 , 0x00000000 , V_294 }
} ;
const struct V_262 * V_46 = V_263 ;
T_2 V_13 ;
V_13 = F_12 ( V_295 ) ;
while ( ( V_13 & V_46 -> V_12 ) != V_46 -> V_42 )
V_46 ++ ;
V_2 -> V_25 = V_46 -> V_25 ;
if ( V_2 -> V_25 == V_294 ) {
F_125 ( V_2 , V_296 , V_49 ,
L_5 ) ;
V_2 -> V_25 = V_261 ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
F_127 ( L_6 , V_2 -> V_25 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
const struct V_297 * V_228 , int V_70 )
{
while ( V_70 -- > 0 ) {
F_31 ( V_2 , V_228 -> V_13 , V_228 -> V_42 ) ;
V_228 ++ ;
}
}
static bool F_129 ( struct V_1 * V_2 , struct V_132 * V_132 )
{
const struct V_298 * V_299 = V_132 -> V_299 ;
struct V_300 * V_300 = (struct V_300 * ) V_299 -> V_20 ;
struct V_301 * V_302 = & V_132 -> V_303 ;
char * V_135 = V_132 -> V_135 ;
bool V_156 = false ;
if ( V_299 -> V_304 < V_305 )
goto V_177;
if ( ! V_300 -> V_306 ) {
T_7 V_16 , V_304 , V_307 ;
T_3 V_308 = 0 ;
if ( V_299 -> V_304 < sizeof( * V_300 ) )
goto V_177;
for ( V_16 = 0 ; V_16 < V_299 -> V_304 ; V_16 ++ )
V_308 += V_299 -> V_20 [ V_16 ] ;
if ( V_308 != 0 )
goto V_177;
V_307 = F_103 ( V_300 -> V_309 ) ;
if ( V_307 > V_299 -> V_304 )
goto V_177;
V_304 = F_103 ( V_300 -> V_310 ) ;
if ( V_304 > ( V_299 -> V_304 - V_307 ) / V_305 )
goto V_177;
memcpy ( V_135 , V_300 -> V_135 , V_311 ) ;
V_302 -> V_312 = ( V_313 * ) ( V_299 -> V_20 + V_307 ) ;
V_302 -> V_304 = V_304 ;
} else {
if ( V_299 -> V_304 % V_305 )
goto V_177;
F_82 ( V_135 , F_80 ( V_2 ) , V_311 ) ;
V_302 -> V_312 = ( V_313 * ) V_299 -> V_20 ;
V_302 -> V_304 = V_299 -> V_304 / V_305 ;
}
V_135 [ V_311 - 1 ] = 0 ;
V_156 = true ;
V_177:
return V_156 ;
}
static bool F_130 ( struct V_1 * V_2 , struct V_48 * V_49 ,
struct V_301 * V_302 )
{
bool V_156 = false ;
T_7 V_314 ;
for ( V_314 = 0 ; V_314 < V_302 -> V_304 ; V_314 ++ ) {
T_2 V_315 = F_103 ( V_302 -> V_312 [ V_314 ] ) ;
T_2 V_316 = ( V_315 & 0x0fff0000 ) >> 16 ;
switch( V_315 & 0xf0000000 ) {
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
break;
case V_325 :
if ( V_316 > V_314 ) {
F_131 ( V_2 , V_98 , V_2 -> V_49 ,
L_7 ) ;
goto V_177;
}
break;
case V_326 :
if ( V_314 + 2 >= V_302 -> V_304 ) {
F_131 ( V_2 , V_98 , V_2 -> V_49 ,
L_7 ) ;
goto V_177;
}
break;
case V_327 :
case V_328 :
case V_329 :
if ( V_314 + 1 + V_316 >= V_302 -> V_304 ) {
F_131 ( V_2 , V_98 , V_2 -> V_49 ,
L_7 ) ;
goto V_177;
}
break;
case V_330 :
case V_331 :
case V_332 :
default:
F_131 ( V_2 , V_98 , V_2 -> V_49 ,
L_8 , V_315 ) ;
goto V_177;
}
}
V_156 = true ;
V_177:
return V_156 ;
}
static int F_132 ( struct V_1 * V_2 , struct V_132 * V_132 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
int V_156 = - V_157 ;
if ( ! F_129 ( V_2 , V_132 ) ) {
F_131 ( V_2 , V_98 , V_49 , L_9 ) ;
goto V_177;
}
if ( F_130 ( V_2 , V_49 , & V_132 -> V_303 ) )
V_156 = 0 ;
V_177:
return V_156 ;
}
static void F_133 ( struct V_1 * V_2 , struct V_132 * V_132 )
{
struct V_301 * V_302 = & V_132 -> V_303 ;
T_2 V_333 , V_334 ;
T_7 V_314 ;
V_333 = V_334 = 0 ;
for ( V_314 = 0 ; V_314 < V_302 -> V_304 ; ) {
T_2 V_315 = F_103 ( V_302 -> V_312 [ V_314 ] ) ;
T_2 V_20 = V_315 & 0x0000ffff ;
T_2 V_316 = ( V_315 & 0x0fff0000 ) >> 16 ;
if ( ! V_315 )
break;
switch( V_315 & 0xf0000000 ) {
case V_317 :
V_333 = F_32 ( V_2 , V_316 ) ;
V_334 ++ ;
V_314 ++ ;
break;
case V_318 :
V_333 |= V_20 ;
V_314 ++ ;
break;
case V_319 :
V_333 &= V_20 ;
V_314 ++ ;
break;
case V_325 :
V_314 -= V_316 ;
break;
case V_320 :
V_333 = F_47 ( V_2 -> V_15 , V_316 ) ;
V_314 ++ ;
break;
case V_321 :
V_334 = 0 ;
V_314 ++ ;
break;
case V_322 :
F_31 ( V_2 , V_316 , V_20 ) ;
V_314 ++ ;
break;
case V_326 :
V_314 += ( V_334 == V_20 ) ? 2 : 1 ;
break;
case V_327 :
if ( V_333 == V_20 )
V_314 += V_316 ;
V_314 ++ ;
break;
case V_328 :
if ( V_333 != V_20 )
V_314 += V_316 ;
V_314 ++ ;
break;
case V_323 :
F_31 ( V_2 , V_316 , V_333 ) ;
V_314 ++ ;
break;
case V_329 :
V_314 += V_316 + 1 ;
break;
case V_324 :
F_24 ( V_20 ) ;
V_314 ++ ;
break;
case V_330 :
case V_331 :
case V_332 :
default:
F_134 () ;
}
}
}
static void F_135 ( struct V_1 * V_2 )
{
if ( ! F_85 ( V_2 -> V_132 ) ) {
F_136 ( V_2 -> V_132 -> V_299 ) ;
F_137 ( V_2 -> V_132 ) ;
}
V_2 -> V_132 = V_335 ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_132 * V_132 = V_2 -> V_132 ;
if ( ! F_85 ( V_132 ) )
F_133 ( V_2 , V_132 ) ;
}
static void F_139 ( struct V_1 * V_2 , T_3 V_13 , T_1 V_42 )
{
if ( F_32 ( V_2 , V_13 ) != V_42 )
F_88 ( V_2 , V_336 , V_2 -> V_49 , L_10 ) ;
else
F_138 ( V_2 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0002 } ,
{ 0x01 , 0x90d0 } ,
{ 0x1f , 0x0000 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( ( V_6 -> V_338 != V_339 ) ||
( V_6 -> V_340 != 0xe000 ) )
return;
F_31 ( V_2 , 0x1f , 0x0001 ) ;
F_31 ( V_2 , 0x10 , 0xf01b ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_142 ( V_2 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_31 ( V_2 , 0x1f , 0x0001 ) ;
F_33 ( V_2 , 0x16 , 1 << 0 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0001 } ,
{ 0x10 , 0xf41b } ,
{ 0x1f , 0x0000 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0000 } ,
{ 0x1d , 0x0f00 } ,
{ 0x1f , 0x0002 } ,
{ 0x0c , 0x1ec8 } ,
{ 0x1f , 0x0000 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0001 } ,
{ 0x1d , 0x3d98 } ,
{ 0x1f , 0x0000 }
} ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_33 ( V_2 , 0x14 , 1 << 5 ) ;
F_33 ( V_2 , 0x0d , 1 << 5 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_33 ( V_2 , 0x14 , 1 << 5 ) ;
F_33 ( V_2 , 0x0d , 1 << 5 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_33 ( V_2 , 0x16 , 1 << 0 ) ;
F_33 ( V_2 , 0x14 , 1 << 5 ) ;
F_33 ( V_2 , 0x0d , 1 << 5 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_33 ( V_2 , 0x16 , 1 << 0 ) ;
F_33 ( V_2 , 0x14 , 1 << 5 ) ;
F_33 ( V_2 , 0x0d , 1 << 5 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
static const struct V_297 V_341 [] = {
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
void T_4 * V_14 = V_2 -> V_15 ;
F_128 ( V_2 , V_341 , F_77 ( V_341 ) ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_34 ( V_2 , 0x0b , 0x0010 , 0x00ef ) ;
F_34 ( V_2 , 0x0c , 0xa200 , 0x5d00 ) ;
if ( F_47 ( V_14 , 0x01 ) == 0xb1 ) {
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_42 ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
V_42 = F_32 ( V_2 , 0x0d ) ;
if ( ( V_42 & 0x00ff ) != 0x006c ) {
static const T_2 V_342 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_16 ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
V_42 &= 0xff00 ;
for ( V_16 = 0 ; V_16 < F_77 ( V_342 ) ; V_16 ++ )
F_31 ( V_2 , 0x0d , V_42 | V_342 [ V_16 ] ) ;
}
} else {
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x6662 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x6662 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_33 ( V_2 , 0x0d , 0x0300 ) ;
F_33 ( V_2 , 0x0f , 0x0010 ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_34 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_34 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x001b ) ;
F_139 ( V_2 , V_343 , 0xbf00 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
static const struct V_297 V_341 [] = {
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
void T_4 * V_14 = V_2 -> V_15 ;
F_128 ( V_2 , V_341 , F_77 ( V_341 ) ) ;
if ( F_47 ( V_14 , 0x01 ) == 0xb1 ) {
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x669a } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x669a } ,
{ 0x1f , 0x0002 }
} ;
int V_42 ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
V_42 = F_32 ( V_2 , 0x0d ) ;
if ( ( V_42 & 0x00ff ) != 0x006c ) {
static const T_2 V_342 [] = {
0x0065 , 0x0066 , 0x0067 , 0x0068 ,
0x0069 , 0x006a , 0x006b , 0x006c
} ;
int V_16 ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
V_42 &= 0xff00 ;
for ( V_16 = 0 ; V_16 < F_77 ( V_342 ) ; V_16 ++ )
F_31 ( V_2 , 0x0d , V_42 | V_342 [ V_16 ] ) ;
}
} else {
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0002 } ,
{ 0x05 , 0x2642 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8330 } ,
{ 0x06 , 0x2642 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_34 ( V_2 , 0x02 , 0x0100 , 0x0600 ) ;
F_34 ( V_2 , 0x03 , 0x0000 , 0xe000 ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_33 ( V_2 , 0x0f , 0x0017 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x001b ) ;
F_139 ( V_2 , V_343 , 0xb300 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0001 } ,
{ 0x17 , 0x0cc0 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x002d } ,
{ 0x18 , 0x0040 } ,
{ 0x1f , 0x0000 }
} ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_33 ( V_2 , 0x0d , 1 << 5 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_138 ( V_2 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x0023 ) ;
F_34 ( V_2 , 0x17 , 0x0006 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_34 ( V_2 , 0x08 , 0x8000 , 0x7f00 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x002d ) ;
F_34 ( V_2 , 0x18 , 0x0050 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_34 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b86 ) ;
F_34 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b85 ) ;
F_34 ( V_2 , 0x06 , 0x0000 , 0x2000 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x0020 ) ;
F_34 ( V_2 , 0x15 , 0x0000 , 0x1100 ) ;
F_31 ( V_2 , 0x1f , 0x0006 ) ;
F_31 ( V_2 , 0x00 , 0x5a00 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x0d , 0x0007 ) ;
F_31 ( V_2 , 0x0e , 0x003c ) ;
F_31 ( V_2 , 0x0d , 0x4007 ) ;
F_31 ( V_2 , 0x0e , 0x0000 ) ;
F_31 ( V_2 , 0x0d , 0x0000 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_138 ( V_2 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b80 ) ;
F_34 ( V_2 , 0x17 , 0x0006 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0004 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x002d ) ;
F_34 ( V_2 , 0x18 , 0x0010 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_34 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b86 ) ;
F_34 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b85 ) ;
F_34 ( V_2 , 0x06 , 0x4000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_45 ( V_2 -> V_15 , 0x1b0 , V_67 , 0x0000 , 0x0003 ,
V_71 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b85 ) ;
F_34 ( V_2 , 0x06 , 0x0000 , 0x2000 ) ;
F_31 ( V_2 , 0x1f , 0x0004 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x0020 ) ;
F_34 ( V_2 , 0x15 , 0x0000 , 0x0100 ) ;
F_31 ( V_2 , 0x1f , 0x0002 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x0d , 0x0007 ) ;
F_31 ( V_2 , 0x0e , 0x003c ) ;
F_31 ( V_2 , 0x0d , 0x4007 ) ;
F_31 ( V_2 , 0x0e , 0x0000 ) ;
F_31 ( V_2 , 0x0d , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0003 ) ;
F_34 ( V_2 , 0x19 , 0x0000 , 0x0001 ) ;
F_34 ( V_2 , 0x10 , 0x0000 , 0x0400 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0003 } ,
{ 0x09 , 0xa20f } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8b55 } ,
{ 0x06 , 0x0000 } ,
{ 0x05 , 0x8b5e } ,
{ 0x06 , 0x0000 } ,
{ 0x05 , 0x8b67 } ,
{ 0x06 , 0x0000 } ,
{ 0x05 , 0x8b70 } ,
{ 0x06 , 0x0000 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0007 } ,
{ 0x1e , 0x0078 } ,
{ 0x17 , 0x0000 } ,
{ 0x19 , 0x00fb } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0005 } ,
{ 0x05 , 0x8b79 } ,
{ 0x06 , 0xaa00 } ,
{ 0x1f , 0x0000 } ,
{ 0x1f , 0x0003 } ,
{ 0x01 , 0x328a } ,
{ 0x1f , 0x0000 }
} ;
F_138 ( V_2 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b80 ) ;
F_34 ( V_2 , 0x06 , 0x0006 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x002d ) ;
F_34 ( V_2 , 0x18 , 0x0010 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_34 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b86 ) ;
F_34 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b85 ) ;
F_34 ( V_2 , 0x06 , 0x4000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_138 ( V_2 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b80 ) ;
F_34 ( V_2 , 0x06 , 0x0006 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0007 ) ;
F_31 ( V_2 , 0x1e , 0x002d ) ;
F_34 ( V_2 , 0x18 , 0x0010 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_34 ( V_2 , 0x14 , 0x8000 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0005 ) ;
F_31 ( V_2 , 0x05 , 0x8b86 ) ;
F_34 ( V_2 , 0x06 , 0x0001 , 0x0000 ) ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
{ 0x1f , 0x0003 } ,
{ 0x08 , 0x441d } ,
{ 0x01 , 0x9100 } ,
{ 0x1f , 0x0000 }
} ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_33 ( V_2 , 0x11 , 1 << 12 ) ;
F_33 ( V_2 , 0x19 , 1 << 13 ) ;
F_33 ( V_2 , 0x10 , 1 << 15 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
static const struct V_297 V_337 [] = {
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
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , 0x18 , 0x0310 ) ;
F_16 ( 100 ) ;
F_138 ( V_2 ) ;
F_128 ( V_2 , V_337 , F_77 ( V_337 ) ) ;
}
static void F_163 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_126 ( V_2 ) ;
switch ( V_2 -> V_25 ) {
case V_293 :
break;
case V_184 :
case V_185 :
F_140 ( V_2 ) ;
break;
case V_292 :
F_141 ( V_2 ) ;
break;
case V_291 :
F_143 ( V_2 ) ;
break;
case V_290 :
F_144 ( V_2 ) ;
break;
case V_284 :
case V_283 :
case V_282 :
F_161 ( V_2 ) ;
break;
case V_279 :
F_145 ( V_2 ) ;
break;
case V_277 :
F_146 ( V_2 ) ;
break;
case V_278 :
F_146 ( V_2 ) ;
break;
case V_272 :
F_147 ( V_2 ) ;
break;
case V_273 :
F_149 ( V_2 ) ;
break;
case V_274 :
F_150 ( V_2 ) ;
break;
case V_275 :
F_151 ( V_2 ) ;
break;
case V_276 :
F_152 ( V_2 ) ;
break;
case V_271 :
case V_270 :
F_148 ( V_2 ) ;
break;
case V_267 :
F_153 ( V_2 ) ;
break;
case V_266 :
F_154 ( V_2 ) ;
break;
case V_268 :
F_155 ( V_2 ) ;
break;
case V_269 :
F_156 ( V_2 ) ;
break;
case V_281 :
case V_280 :
F_162 ( V_2 ) ;
break;
case V_26 :
break;
case V_265 :
case V_264 :
F_157 ( V_2 ) ;
break;
case V_90 :
F_158 ( V_2 ) ;
break;
case V_94 :
F_159 ( V_2 ) ;
break;
case V_95 :
F_160 ( V_2 ) ;
break;
default:
break;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_344 * V_188 = & V_2 -> V_188 ;
void T_4 * V_14 = V_2 -> V_15 ;
unsigned long V_345 = V_190 ;
assert ( V_2 -> V_25 > V_293 ) ;
if ( V_2 -> V_346 ( V_2 ) ) {
V_345 = V_347 / 10 ;
goto V_348;
}
if ( V_2 -> V_97 ( V_14 ) )
return;
F_88 ( V_2 , V_151 , V_2 -> V_49 , L_11 ) ;
V_2 -> V_349 ( V_2 ) ;
V_348:
F_91 ( V_188 , V_189 + V_345 ) ;
}
static void F_165 ( struct V_1 * V_2 , enum V_350 V_351 )
{
if ( ! F_166 ( V_351 , V_2 -> V_3 . V_352 ) )
F_167 ( & V_2 -> V_3 . V_353 ) ;
}
static void F_168 ( unsigned long V_354 )
{
struct V_48 * V_49 = (struct V_48 * ) V_354 ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_165 ( V_2 , V_355 ) ;
}
static void F_169 ( struct V_5 * V_6 , struct V_48 * V_49 ,
void T_4 * V_14 )
{
F_170 ( V_14 ) ;
F_171 ( V_6 ) ;
F_172 ( V_6 ) ;
F_173 ( V_6 ) ;
F_174 ( V_49 ) ;
}
static void F_175 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
unsigned int V_16 ;
V_2 -> V_349 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! V_2 -> V_346 ( V_2 ) )
return;
F_16 ( 1 ) ;
}
F_131 ( V_2 , V_151 , V_49 , L_12 ) ;
}
static bool F_176 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
return ( V_2 -> V_25 == V_293 ) &&
( F_57 ( V_88 ) & V_356 ) ;
}
static void F_177 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_163 ( V_49 ) ;
if ( V_2 -> V_25 <= V_290 ) {
F_127 ( L_13 ) ;
F_15 ( 0x82 , 0x01 ) ;
}
F_178 ( V_2 -> V_5 , V_357 , 0x40 ) ;
if ( V_2 -> V_25 <= V_290 )
F_178 ( V_2 -> V_5 , V_358 , 0x08 ) ;
if ( V_2 -> V_25 == V_184 ) {
F_127 ( L_13 ) ;
F_15 ( 0x82 , 0x01 ) ;
F_127 ( L_14 ) ;
F_31 ( V_2 , 0x0b , 0x0000 ) ;
}
F_175 ( V_49 , V_2 ) ;
F_90 ( V_49 , V_150 , V_146 , V_147 ,
V_164 | V_165 |
V_166 | V_167 |
( V_2 -> V_173 . V_174 ?
V_175 |
V_176 : 0 ) ) ;
if ( F_176 ( V_2 ) )
F_70 ( V_2 , V_151 , V_49 , L_15 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_3 * V_57 )
{
void T_4 * V_14 = V_2 -> V_15 ;
T_2 V_359 ;
T_2 V_360 ;
V_360 = V_57 [ 0 ] | ( V_57 [ 1 ] << 8 ) | ( V_57 [ 2 ] << 16 ) | ( V_57 [ 3 ] << 24 ) ;
V_359 = V_57 [ 4 ] | ( V_57 [ 5 ] << 8 ) ;
F_1 ( V_2 ) ;
F_15 ( V_123 , V_124 ) ;
F_10 ( V_361 , V_359 ) ;
F_12 ( V_361 ) ;
F_10 ( V_362 , V_360 ) ;
F_12 ( V_362 ) ;
if ( V_2 -> V_25 == V_90 ) {
const struct V_68 V_363 [] = {
{ . V_57 = 0xe0 , V_67 , . V_42 = V_360 } ,
{ . V_57 = 0xe4 , V_67 , . V_42 = V_359 } ,
{ . V_57 = 0xf0 , V_67 , . V_42 = V_360 << 16 } ,
{ . V_57 = 0xf4 , V_67 , . V_42 = V_359 << 16 |
V_360 >> 16 } ,
} ;
F_46 ( V_14 , V_363 , F_77 ( V_363 ) ) ;
}
F_15 ( V_123 , V_125 ) ;
F_3 ( V_2 ) ;
}
static int F_180 ( struct V_48 * V_49 , void * V_46 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_364 * V_57 = V_46 ;
if ( ! F_181 ( V_57 -> V_365 ) )
return - V_366 ;
memcpy ( V_49 -> V_367 , V_57 -> V_365 , V_49 -> V_368 ) ;
F_179 ( V_2 , V_49 -> V_367 ) ;
return 0 ;
}
static int F_182 ( struct V_48 * V_49 , struct V_369 * V_370 , int V_21 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_371 * V_20 = F_183 ( V_370 ) ;
return F_65 ( V_49 ) ? V_2 -> V_372 ( V_2 , V_20 , V_21 ) : - V_373 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_371 * V_20 , int V_21 )
{
switch ( V_21 ) {
case V_374 :
V_20 -> V_50 = 32 ;
return 0 ;
case V_375 :
V_20 -> V_376 = F_32 ( V_2 , V_20 -> V_377 & 0x1f ) ;
return 0 ;
case V_378 :
F_31 ( V_2 , V_20 -> V_377 & 0x1f , V_20 -> V_379 ) ;
return 0 ;
}
return - V_152 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_371 * V_20 , int V_21 )
{
return - V_152 ;
}
static void F_186 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
if ( V_2 -> V_126 & V_380 ) {
F_187 ( V_6 ) ;
V_2 -> V_126 &= ~ V_380 ;
}
}
static void T_8 F_188 ( struct V_1 * V_2 )
{
struct V_43 * V_381 = & V_2 -> V_43 ;
switch ( V_2 -> V_25 ) {
case V_268 :
V_381 -> V_44 = F_25 ;
V_381 -> V_45 = F_26 ;
break;
case V_269 :
case V_26 :
V_381 -> V_44 = F_29 ;
V_381 -> V_45 = F_30 ;
break;
default:
V_381 -> V_44 = F_21 ;
V_381 -> V_45 = F_22 ;
break;
}
}
static void F_189 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
switch ( V_2 -> V_25 ) {
case V_281 :
case V_280 :
case V_265 :
case V_264 :
case V_90 :
F_10 ( V_207 , F_12 ( V_207 ) |
V_382 | V_383 | V_384 ) ;
break;
default:
break;
}
}
static bool F_190 ( struct V_1 * V_2 )
{
if ( ! ( F_74 ( V_2 ) & V_119 ) )
return false ;
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , V_85 , 0x0000 ) ;
F_189 ( V_2 ) ;
return true ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , V_85 , V_385 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x1f , 0x0000 ) ;
F_31 ( V_2 , V_85 , V_178 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
if ( F_190 ( V_2 ) )
return;
F_191 ( V_2 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
F_192 ( V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_25 ) {
case V_279 :
case V_277 :
case V_278 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_271 :
case V_270 :
case V_267 :
case V_266 :
case V_268 :
case V_269 :
case V_26 :
F_31 ( V_2 , 0x0e , 0x0000 ) ;
break;
default:
break;
}
F_31 ( V_2 , V_85 , V_178 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0x1f , 0x0000 ) ;
switch ( V_2 -> V_25 ) {
case V_265 :
case V_264 :
F_31 ( V_2 , V_85 , V_178 | V_385 ) ;
break;
case V_279 :
case V_277 :
case V_278 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_271 :
case V_270 :
case V_267 :
case V_266 :
case V_268 :
case V_269 :
case V_26 :
F_31 ( V_2 , 0x0e , 0x0200 ) ;
default:
F_31 ( V_2 , V_85 , V_385 ) ;
break;
}
}
static void F_197 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
if ( ( V_2 -> V_25 == V_268 ||
V_2 -> V_25 == V_269 ||
V_2 -> V_25 == V_26 ) &&
F_20 ( V_2 ) ) {
return;
}
if ( ( V_2 -> V_25 == V_271 ||
V_2 -> V_25 == V_270 ) &&
( F_49 ( V_205 ) & V_386 ) ) {
return;
}
if ( V_2 -> V_25 == V_265 ||
V_2 -> V_25 == V_264 )
F_38 ( V_14 , 0x19 , 0xff64 ) ;
if ( F_190 ( V_2 ) )
return;
F_196 ( V_2 ) ;
switch ( V_2 -> V_25 ) {
case V_267 :
case V_266 :
case V_268 :
case V_269 :
case V_26 :
case V_265 :
case V_264 :
F_15 ( V_387 , F_57 ( V_387 ) & ~ 0x80 ) ;
break;
}
}
static void F_198 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
if ( ( V_2 -> V_25 == V_268 ||
V_2 -> V_25 == V_269 ||
V_2 -> V_25 == V_26 ) &&
F_20 ( V_2 ) ) {
return;
}
switch ( V_2 -> V_25 ) {
case V_267 :
case V_266 :
case V_268 :
case V_269 :
case V_26 :
case V_265 :
case V_264 :
F_15 ( V_387 , F_57 ( V_387 ) | 0x80 ) ;
break;
}
F_195 ( V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 ,
void (* F_200)( struct V_1 * ) )
{
if ( F_200 )
F_200 ( V_2 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
F_199 ( V_2 , V_2 -> V_388 . V_389 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
F_199 ( V_2 , V_2 -> V_388 . V_390 ) ;
}
static void T_8 F_203 ( struct V_1 * V_2 )
{
struct V_388 * V_381 = & V_2 -> V_388 ;
switch ( V_2 -> V_25 ) {
case V_284 :
case V_283 :
case V_282 :
case V_286 :
case V_287 :
case V_281 :
case V_280 :
V_381 -> V_389 = F_193 ;
V_381 -> V_390 = F_194 ;
break;
case V_279 :
case V_277 :
case V_278 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_271 :
case V_270 :
case V_267 :
case V_266 :
case V_268 :
case V_269 :
case V_26 :
case V_265 :
case V_264 :
case V_90 :
case V_94 :
case V_95 :
V_381 -> V_389 = F_197 ;
V_381 -> V_390 = F_198 ;
break;
default:
V_381 -> V_389 = NULL ;
V_381 -> V_390 = NULL ;
break;
}
}
static void F_204 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
switch ( V_2 -> V_25 ) {
case V_293 :
case V_184 :
case V_185 :
case V_292 :
case V_291 :
case V_290 :
case V_286 :
case V_279 :
case V_277 :
case V_285 :
case V_289 :
case V_288 :
case V_287 :
case V_278 :
F_10 ( V_207 , V_391 | V_392 ) ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_271 :
case V_270 :
F_10 ( V_207 , V_393 | V_394 | V_392 ) ;
break;
default:
F_10 ( V_207 , V_393 | V_392 ) ;
break;
}
}
static void F_205 ( struct V_1 * V_2 )
{
V_2 -> V_395 = V_2 -> V_396 = V_2 -> V_397 = V_2 -> V_398 = 0 ;
}
static void F_206 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_123 , V_124 ) ;
F_199 ( V_2 , V_2 -> V_399 . V_400 ) ;
F_15 ( V_123 , V_125 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_123 , V_124 ) ;
F_199 ( V_2 , V_2 -> V_399 . V_401 ) ;
F_15 ( V_123 , V_125 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_104 , F_57 ( V_104 ) | V_402 ) ;
F_15 ( V_403 , F_57 ( V_403 ) | V_404 ) ;
F_5 ( V_2 -> V_5 , 0x2 << V_405 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_402 ) ;
F_15 ( V_403 , F_57 ( V_403 ) & ~ V_404 ) ;
F_5 ( V_2 -> V_5 , 0x5 << V_405 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_104 , F_57 ( V_104 ) | V_402 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_402 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_406 , 0x3f ) ;
F_15 ( V_104 , F_57 ( V_104 ) | V_402 ) ;
F_15 ( V_403 , F_57 ( V_403 ) | 0x01 ) ;
F_5 ( V_2 -> V_5 , 0x2 << V_405 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_406 , 0x0c ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_402 ) ;
F_15 ( V_403 , F_57 ( V_403 ) & ~ 0x01 ) ;
F_5 ( V_2 -> V_5 , 0x5 << V_405 ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_5 ,
( 0x2 << V_405 ) | V_407 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_5 ,
( 0x5 << V_405 ) | V_407 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_214 ( V_2 ) ;
F_15 ( V_403 , F_57 ( V_403 ) | ( 1 << 0 ) ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_215 ( V_2 ) ;
F_15 ( V_403 , F_57 ( V_403 ) & ~ ( 1 << 0 ) ) ;
}
static void T_8 F_218 ( struct V_1 * V_2 )
{
struct V_399 * V_381 = & V_2 -> V_399 ;
switch ( V_2 -> V_25 ) {
case V_279 :
V_381 -> V_401 = F_215 ;
V_381 -> V_400 = F_214 ;
break;
case V_277 :
case V_278 :
V_381 -> V_401 = F_217 ;
V_381 -> V_400 = F_216 ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_271 :
case V_270 :
case V_267 :
case V_266 :
V_381 -> V_401 = F_209 ;
V_381 -> V_400 = F_208 ;
break;
case V_268 :
case V_269 :
V_381 -> V_401 = F_211 ;
V_381 -> V_400 = F_210 ;
break;
case V_26 :
case V_265 :
case V_264 :
case V_90 :
V_381 -> V_401 = F_213 ;
V_381 -> V_400 = F_212 ;
break;
default:
V_381 -> V_401 = NULL ;
V_381 -> V_400 = NULL ;
break;
}
}
static void F_219 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
int V_16 ;
F_15 ( V_82 , V_408 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ( F_57 ( V_82 ) & V_408 ) == 0 )
break;
F_11 ( 100 ) ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_132 * V_132 ;
const char * V_409 ;
int V_156 = - V_410 ;
V_409 = F_80 ( V_2 ) ;
if ( ! V_409 )
goto V_411;
V_132 = F_221 ( sizeof( * V_132 ) , V_240 ) ;
if ( ! V_132 )
goto V_412;
V_156 = F_222 ( & V_132 -> V_299 , V_409 , & V_2 -> V_5 -> V_49 ) ;
if ( V_156 < 0 )
goto V_413;
V_156 = F_132 ( V_2 , V_132 ) ;
if ( V_156 < 0 )
goto V_414;
V_2 -> V_132 = V_132 ;
V_177:
return;
V_414:
F_136 ( V_132 -> V_299 ) ;
V_413:
F_137 ( V_132 ) ;
V_412:
F_88 ( V_2 , V_98 , V_2 -> V_49 , L_16 ,
V_409 , V_156 ) ;
V_411:
V_2 -> V_132 = NULL ;
goto V_177;
}
static void F_223 ( struct V_1 * V_2 )
{
if ( F_224 ( V_2 -> V_132 ) )
F_220 ( V_2 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_10 ( V_207 , F_12 ( V_207 ) & ~ V_415 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_56 ( V_2 ) ;
F_225 ( V_2 ) ;
if ( V_2 -> V_25 == V_268 ||
V_2 -> V_25 == V_269 ||
V_2 -> V_25 == V_26 ) {
while ( F_57 ( V_416 ) & V_417 )
F_11 ( 20 ) ;
} else if ( V_2 -> V_25 == V_90 ||
V_2 -> V_25 == V_94 ||
V_2 -> V_25 == V_95 ) {
F_15 ( V_82 , F_57 ( V_82 ) | V_418 ) ;
while ( ! ( F_12 ( V_295 ) & V_419 ) )
F_11 ( 100 ) ;
} else {
F_15 ( V_82 , F_57 ( V_82 ) | V_418 ) ;
F_11 ( 100 ) ;
}
F_219 ( V_2 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
F_10 ( V_295 , ( V_420 << V_421 ) |
( V_422 << V_423 ) ) ;
}
static void F_228 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
V_2 -> V_424 ( V_49 ) ;
F_55 ( V_2 ) ;
}
static void F_229 ( struct V_1 * V_2 ,
void T_4 * V_14 )
{
F_10 ( V_425 , ( ( V_242 ) V_2 -> V_426 ) >> 32 ) ;
F_10 ( V_427 , ( ( V_242 ) V_2 -> V_426 ) & F_117 ( 32 ) ) ;
F_10 ( V_428 , ( ( V_242 ) V_2 -> V_429 ) >> 32 ) ;
F_10 ( V_430 , ( ( V_242 ) V_2 -> V_429 ) & F_117 ( 32 ) ) ;
}
static T_1 F_230 ( void T_4 * V_14 )
{
T_1 V_21 ;
V_21 = F_49 ( V_205 ) ;
F_51 ( V_205 , V_21 ) ;
return V_21 ;
}
static void F_231 ( void T_4 * V_14 , unsigned int V_431 )
{
F_51 ( V_432 , V_431 + 1 ) ;
}
static void F_232 ( void T_4 * V_14 , unsigned V_25 )
{
static const struct V_433 {
T_2 V_25 ;
T_2 V_434 ;
T_2 V_42 ;
} V_435 [] = {
{ V_291 , V_436 , 0x000fff00 } ,
{ V_291 , V_437 , 0x000fffff } ,
{ V_290 , V_436 , 0x00ffff00 } ,
{ V_290 , V_437 , 0x00ffffff }
} ;
const struct V_433 * V_46 = V_435 ;
unsigned int V_16 ;
T_2 V_434 ;
V_434 = F_57 ( V_438 ) & V_437 ;
for ( V_16 = 0 ; V_16 < F_77 ( V_435 ) ; V_16 ++ , V_46 ++ ) {
if ( ( V_46 -> V_25 == V_25 ) && ( V_46 -> V_434 == V_434 ) ) {
F_10 ( 0x7c , V_46 -> V_42 ) ;
break;
}
}
}
static void F_233 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
T_2 V_439 [ 2 ] ;
int V_440 ;
T_2 V_206 = 0 ;
if ( V_49 -> V_352 & V_441 ) {
F_125 ( V_2 , V_151 , V_49 , L_17 ) ;
V_440 =
V_382 | V_383 | V_384 |
V_442 ;
V_439 [ 1 ] = V_439 [ 0 ] = 0xffffffff ;
} else if ( ( F_234 ( V_49 ) > V_443 ) ||
( V_49 -> V_352 & V_444 ) ) {
V_440 = V_382 | V_383 | V_384 ;
V_439 [ 1 ] = V_439 [ 0 ] = 0xffffffff ;
} else {
struct V_445 * V_446 ;
V_440 = V_382 | V_384 ;
V_439 [ 1 ] = V_439 [ 0 ] = 0 ;
F_235 (ha, dev) {
int V_447 = F_236 ( V_448 , V_446 -> V_57 ) >> 26 ;
V_439 [ V_447 >> 5 ] |= 1 << ( V_447 & 31 ) ;
V_440 |= V_383 ;
}
}
if ( V_49 -> V_126 & V_199 )
V_440 |= ( V_208 | V_209 ) ;
V_206 = ( F_12 ( V_207 ) & ~ V_415 ) | V_440 ;
if ( V_2 -> V_25 > V_290 ) {
T_2 V_20 = V_439 [ 0 ] ;
V_439 [ 0 ] = F_237 ( V_439 [ 1 ] ) ;
V_439 [ 1 ] = F_237 ( V_20 ) ;
}
F_10 ( V_449 + 4 , V_439 [ 1 ] ) ;
F_10 ( V_449 + 0 , V_439 [ 0 ] ) ;
F_10 ( V_207 , V_206 ) ;
}
static void F_238 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_2 -> V_25 == V_291 ) {
F_51 ( V_205 , F_49 ( V_205 ) | V_450 ) ;
F_178 ( V_6 , V_358 , 0x08 ) ;
}
F_15 ( V_123 , V_124 ) ;
if ( V_2 -> V_25 == V_293 ||
V_2 -> V_25 == V_184 ||
V_2 -> V_25 == V_185 ||
V_2 -> V_25 == V_292 )
F_15 ( V_82 , V_451 | V_239 ) ;
F_204 ( V_2 ) ;
F_15 ( V_452 , V_453 ) ;
F_231 ( V_14 , V_431 ) ;
if ( V_2 -> V_25 == V_293 ||
V_2 -> V_25 == V_184 ||
V_2 -> V_25 == V_185 ||
V_2 -> V_25 == V_292 )
F_227 ( V_2 ) ;
V_2 -> V_202 |= F_230 ( V_14 ) | V_450 ;
if ( V_2 -> V_25 == V_184 ||
V_2 -> V_25 == V_185 ) {
F_127 ( L_18
L_19 ) ;
V_2 -> V_202 |= ( 1 << 14 ) ;
}
F_51 ( V_205 , V_2 -> V_202 ) ;
F_232 ( V_14 , V_2 -> V_25 ) ;
F_51 ( V_454 , 0x0000 ) ;
F_229 ( V_2 , V_14 ) ;
if ( V_2 -> V_25 != V_293 &&
V_2 -> V_25 != V_184 &&
V_2 -> V_25 != V_185 &&
V_2 -> V_25 != V_292 ) {
F_15 ( V_82 , V_451 | V_239 ) ;
F_227 ( V_2 ) ;
}
F_15 ( V_123 , V_125 ) ;
F_57 ( V_79 ) ;
F_10 ( V_455 , 0 ) ;
F_233 ( V_49 ) ;
F_51 ( V_456 , F_49 ( V_456 ) & 0xF000 ) ;
}
static void F_239 ( void T_4 * V_14 , T_2 V_78 )
{
T_2 V_457 ;
V_457 = F_41 ( V_14 , 0x070c ) & 0x00ffffff ;
F_40 ( V_14 , 0x070c , V_457 | V_78 ) ;
}
static void F_240 ( void T_4 * V_14 )
{
F_239 ( V_14 , 0x17000000 ) ;
}
static void F_241 ( void T_4 * V_14 )
{
F_239 ( V_14 , 0x27000000 ) ;
}
static void F_242 ( void T_4 * V_14 , const struct V_458 * V_363 , int V_70 )
{
T_1 V_459 ;
while ( V_70 -- > 0 ) {
V_459 = ( F_39 ( V_14 , V_363 -> V_460 ) & ~ V_363 -> V_12 ) | V_363 -> V_78 ;
F_38 ( V_14 , V_363 -> V_460 , V_459 ) ;
V_363 ++ ;
}
}
static void F_243 ( struct V_5 * V_6 )
{
int V_8 = F_6 ( V_6 ) ;
if ( V_8 ) {
T_1 V_9 ;
F_7 ( V_6 , V_8 + V_461 , & V_9 ) ;
V_9 &= ~ V_462 ;
F_8 ( V_6 , V_8 + V_461 , V_9 ) ;
}
}
static void F_244 ( struct V_5 * V_6 )
{
int V_8 = F_6 ( V_6 ) ;
if ( V_8 ) {
T_1 V_9 ;
F_7 ( V_6 , V_8 + V_461 , & V_9 ) ;
V_9 |= V_462 ;
F_8 ( V_6 , V_8 + V_461 , V_9 ) ;
}
}
static void F_245 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
F_51 ( V_205 , F_49 ( V_205 ) & ~ V_464 ) ;
F_5 ( V_6 ,
( 0x5 << V_405 ) | V_407 ) ;
}
static void F_246 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_245 ( V_14 , V_6 ) ;
F_15 ( V_406 , V_465 ) ;
F_15 ( V_403 , F_57 ( V_403 ) & ~ ( 1 << 0 ) ) ;
}
static void F_247 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_15 ( V_102 , F_57 ( V_102 ) | V_466 ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_243 ( V_6 ) ;
F_51 ( V_205 , F_49 ( V_205 ) & ~ V_464 ) ;
}
static void F_248 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_467 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0042 } ,
{ 0x06 , 0x0080 , 0x0000 } ,
{ 0x07 , 0 , 0x2000 }
} ;
F_241 ( V_14 ) ;
F_242 ( V_14 , V_467 , F_77 ( V_467 ) ) ;
F_247 ( V_14 , V_6 ) ;
}
static void F_249 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_241 ( V_14 ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_51 ( V_205 , F_49 ( V_205 ) & ~ V_464 ) ;
}
static void F_250 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_241 ( V_14 ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
F_15 ( V_468 , 0x20 ) ;
F_15 ( V_406 , V_465 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_51 ( V_205 , F_49 ( V_205 ) & ~ V_464 ) ;
}
static void F_251 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_469 [] = {
{ 0x02 , 0x0800 , 0x1000 } ,
{ 0x03 , 0 , 0x0002 } ,
{ 0x06 , 0x0080 , 0x0000 }
} ;
F_241 ( V_14 ) ;
F_15 ( V_468 , 0x06 | V_470 | V_471 ) ;
F_242 ( V_14 , V_469 , F_77 ( V_469 ) ) ;
F_247 ( V_14 , V_6 ) ;
}
static void F_252 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_472 [] = {
{ 0x01 , 0 , 0x0001 } ,
{ 0x03 , 0x0400 , 0x0220 }
} ;
F_241 ( V_14 ) ;
F_242 ( V_14 , V_472 , F_77 ( V_472 ) ) ;
F_247 ( V_14 , V_6 ) ;
}
static void F_253 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_252 ( V_14 , V_6 ) ;
}
static void F_254 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_241 ( V_14 ) ;
F_247 ( V_14 , V_6 ) ;
}
static void F_255 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_241 ( V_14 ) ;
F_243 ( V_6 ) ;
F_15 ( V_406 , V_465 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_51 ( V_205 , F_49 ( V_205 ) & ~ V_464 ) ;
}
static void F_256 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_240 ( V_14 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_15 ( V_406 , V_465 ) ;
F_243 ( V_6 ) ;
}
static void F_257 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_473 [] = {
{ 0x0b , ~ 0 , 0x48 } ,
{ 0x19 , 0x20 , 0x50 } ,
{ 0x0c , ~ 0 , 0x20 }
} ;
int V_16 ;
F_240 ( V_14 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_15 ( V_406 , V_465 ) ;
for ( V_16 = 0 ; V_16 < F_77 ( V_473 ) ; V_16 ++ ) {
const struct V_458 * V_363 = V_473 + V_16 ;
T_1 V_459 ;
V_459 = F_39 ( V_14 , V_363 -> V_460 ) ;
F_38 ( V_14 , 0x03 , ( V_459 & V_363 -> V_12 ) | V_363 -> V_78 ) ;
}
F_244 ( V_6 ) ;
}
static void F_258 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_474 [] = {
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
F_241 ( V_14 ) ;
F_242 ( V_14 , V_474 , F_77 ( V_474 ) ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_15 ( V_406 , V_465 ) ;
F_243 ( V_6 ) ;
F_10 ( V_475 , F_12 ( V_475 ) | V_476 ) ;
F_10 ( V_475 , F_12 ( V_475 ) & ~ V_476 ) ;
F_15 ( V_109 , F_57 ( V_109 ) & ~ V_477 ) ;
}
static void F_259 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_478 [] = {
{ 0x09 , 0x0000 , 0x0080 } ,
{ 0x19 , 0x0000 , 0x0224 }
} ;
F_240 ( V_14 ) ;
F_242 ( V_14 , V_478 , F_77 ( V_478 ) ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_42 ( V_14 , 0xc0 , V_479 , 0x0000 , V_71 ) ;
F_42 ( V_14 , 0xb8 , V_479 , 0x0000 , V_71 ) ;
F_42 ( V_14 , 0xc8 , V_67 , 0x00100002 , V_71 ) ;
F_42 ( V_14 , 0xe8 , V_67 , 0x00100006 , V_71 ) ;
F_42 ( V_14 , 0xcc , V_67 , 0x00000050 , V_71 ) ;
F_42 ( V_14 , 0xd0 , V_67 , 0x07ff0060 , V_71 ) ;
F_45 ( V_14 , 0x1b0 , V_93 , 0x10 , 0x00 , V_71 ) ;
F_45 ( V_14 , 0x0d4 , V_479 , 0x0c00 , 0xff00 ,
V_71 ) ;
F_15 ( V_406 , V_480 ) ;
F_243 ( V_6 ) ;
F_10 ( V_295 , F_12 ( V_295 ) | V_481 ) ;
F_15 ( V_482 , F_57 ( V_482 ) & ~ V_483 ) ;
F_15 ( V_484 , F_57 ( V_484 ) & ~ 0x07 ) ;
F_15 ( V_485 , F_57 ( V_485 ) | V_486 ) ;
F_10 ( V_475 , F_12 ( V_475 ) | V_487 ) ;
F_15 ( V_109 , F_57 ( V_109 ) & ~ V_477 ) ;
}
static void F_260 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_488 [] = {
{ 0x06 , 0x00c0 , 0x0020 } ,
{ 0x08 , 0x0001 , 0x0002 } ,
{ 0x09 , 0x0000 , 0x0080 } ,
{ 0x19 , 0x0000 , 0x0224 }
} ;
F_240 ( V_14 ) ;
F_242 ( V_14 , V_488 , F_77 ( V_488 ) ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_42 ( V_14 , 0xc0 , V_479 , 0x0000 , V_71 ) ;
F_42 ( V_14 , 0xb8 , V_479 , 0x0000 , V_71 ) ;
F_42 ( V_14 , 0xc8 , V_67 , 0x00100002 , V_71 ) ;
F_42 ( V_14 , 0xe8 , V_67 , 0x00100006 , V_71 ) ;
F_45 ( V_14 , 0xdc , V_93 , 0x00 , 0x01 , V_71 ) ;
F_45 ( V_14 , 0xdc , V_93 , 0x01 , 0x00 , V_71 ) ;
F_45 ( V_14 , 0x1b0 , V_93 , 0x10 , 0x00 , V_71 ) ;
F_45 ( V_14 , 0x1d0 , V_93 , 0x10 , 0x00 , V_71 ) ;
F_42 ( V_14 , 0xcc , V_67 , 0x00000050 , V_71 ) ;
F_42 ( V_14 , 0xd0 , V_67 , 0x00000060 , V_71 ) ;
F_45 ( V_14 , 0x0d4 , V_479 , 0x0c00 , 0xff00 ,
V_71 ) ;
F_15 ( V_406 , V_480 ) ;
F_243 ( V_6 ) ;
F_10 ( V_295 , F_12 ( V_295 ) | V_481 ) ;
F_15 ( V_482 , F_57 ( V_482 ) & ~ V_483 ) ;
F_15 ( V_484 , F_57 ( V_484 ) & ~ 0x07 ) ;
F_15 ( V_485 , F_57 ( V_485 ) | V_486 ) ;
F_10 ( V_475 , F_12 ( V_475 ) | V_487 ) ;
F_15 ( V_109 , F_57 ( V_109 ) & ~ V_477 ) ;
}
static void F_261 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_5 ;
F_15 ( V_123 , V_124 ) ;
F_15 ( V_406 , V_465 ) ;
F_231 ( V_14 , V_431 ) ;
V_2 -> V_202 |= F_49 ( V_205 ) | V_489 | V_490 ;
F_51 ( V_205 , V_2 -> V_202 ) ;
F_51 ( V_454 , 0x5151 ) ;
if ( V_2 -> V_25 == V_279 ) {
V_2 -> V_81 |= V_491 | V_492 ;
V_2 -> V_81 &= ~ V_493 ;
}
F_229 ( V_2 , V_14 ) ;
F_233 ( V_49 ) ;
F_10 ( V_295 , ( V_420 << V_421 ) |
( V_422 << V_423 ) ) ;
F_57 ( V_79 ) ;
switch ( V_2 -> V_25 ) {
case V_279 :
F_245 ( V_14 , V_6 ) ;
break;
case V_277 :
case V_278 :
F_246 ( V_14 , V_6 ) ;
break;
case V_272 :
F_248 ( V_14 , V_6 ) ;
break;
case V_273 :
F_251 ( V_14 , V_6 ) ;
break;
case V_274 :
F_252 ( V_14 , V_6 ) ;
break;
case V_275 :
F_253 ( V_14 , V_6 ) ;
break;
case V_276 :
F_254 ( V_14 , V_6 ) ;
break;
case V_271 :
F_249 ( V_14 , V_6 ) ;
break;
case V_270 :
F_250 ( V_14 , V_6 ) ;
break;
case V_267 :
case V_266 :
case V_268 :
F_255 ( V_14 , V_6 ) ;
break;
case V_269 :
F_257 ( V_14 , V_6 ) ;
break;
case V_26 :
F_256 ( V_14 , V_6 ) ;
break;
case V_265 :
case V_264 :
F_258 ( V_14 , V_6 ) ;
break;
case V_90 :
F_259 ( V_14 , V_6 ) ;
break;
case V_94 :
case V_95 :
F_260 ( V_14 , V_6 ) ;
break;
default:
F_262 (KERN_ERR PFX L_20 ,
dev->name, tp->mac_version) ;
break;
}
F_15 ( V_82 , V_451 | V_239 ) ;
F_15 ( V_123 , V_125 ) ;
F_51 ( V_456 , F_49 ( V_456 ) & 0xF000 ) ;
}
static void F_263 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_494 [] = {
{ 0x01 , 0 , 0x6e65 } ,
{ 0x02 , 0 , 0x091f } ,
{ 0x03 , 0 , 0xc2f9 } ,
{ 0x06 , 0 , 0xafb5 } ,
{ 0x07 , 0 , 0x0e00 } ,
{ 0x19 , 0 , 0xec80 } ,
{ 0x01 , 0 , 0x2e65 } ,
{ 0x01 , 0 , 0x6e65 }
} ;
T_3 V_495 ;
F_241 ( V_14 ) ;
F_15 ( V_468 , V_470 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_15 ( V_102 ,
V_496 | V_497 | V_466 | V_498 | V_499 | V_500 | V_103 ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
V_495 = F_57 ( V_102 ) ;
if ( ( V_495 & V_497 ) && ( V_495 & V_496 ) )
F_15 ( V_102 , V_495 & ~ V_497 ) ;
F_242 ( V_14 , V_494 , F_77 ( V_494 ) ) ;
}
static void F_264 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_241 ( V_14 ) ;
F_5 ( V_6 , 0x5 << V_405 ) ;
F_15 ( V_102 , V_498 | V_499 | V_500 | V_103 ) ;
F_15 ( V_104 , F_57 ( V_104 ) & ~ V_463 ) ;
}
static void F_265 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_264 ( V_14 , V_6 ) ;
F_38 ( V_14 , 0x03 , 0xc2f9 ) ;
}
static void F_266 ( void T_4 * V_14 , struct V_5 * V_6 )
{
static const struct V_458 V_501 [] = {
{ 0x07 , 0 , 0x4000 } ,
{ 0x19 , 0 , 0x0200 } ,
{ 0x19 , 0 , 0x0020 } ,
{ 0x1e , 0 , 0x2000 } ,
{ 0x03 , 0 , 0x0001 } ,
{ 0x19 , 0 , 0x0100 } ,
{ 0x19 , 0 , 0x0004 } ,
{ 0x0a , 0 , 0x0020 }
} ;
F_10 ( V_502 , F_12 ( V_502 ) | 0x002800 ) ;
F_10 ( V_502 , F_12 ( V_502 ) & ~ 0x010000 ) ;
F_15 ( V_482 , F_57 ( V_482 ) | V_503 | V_504 ) ;
F_15 ( V_485 , F_57 ( V_485 ) | V_486 ) ;
F_242 ( V_14 , V_501 , F_77 ( V_501 ) ) ;
}
static void F_267 ( void T_4 * V_14 , struct V_5 * V_6 )
{
F_266 ( V_14 , V_6 ) ;
F_38 ( V_14 , 0x1e , F_39 ( V_14 , 0x1e ) | 0x8000 ) ;
}
static void F_268 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_2 -> V_25 >= V_280 )
V_2 -> V_81 &= ~ V_491 ;
if ( V_2 -> V_25 == V_285 ||
V_2 -> V_25 == V_287 ) {
int V_8 = F_6 ( V_6 ) ;
if ( V_8 ) {
F_8 ( V_6 , V_8 + V_10 ,
V_407 ) ;
}
}
F_15 ( V_123 , V_124 ) ;
switch ( V_2 -> V_25 ) {
case V_284 :
F_263 ( V_14 , V_6 ) ;
break;
case V_283 :
F_265 ( V_14 , V_6 ) ;
break;
case V_282 :
F_264 ( V_14 , V_6 ) ;
break;
case V_281 :
F_266 ( V_14 , V_6 ) ;
break;
case V_280 :
F_267 ( V_14 , V_6 ) ;
break;
}
F_15 ( V_123 , V_125 ) ;
F_15 ( V_406 , V_465 ) ;
F_231 ( V_14 , V_431 ) ;
V_2 -> V_202 &= ~ V_505 ;
F_51 ( V_205 , V_2 -> V_202 ) ;
F_51 ( V_454 , 0x0000 ) ;
F_229 ( V_2 , V_14 ) ;
F_15 ( V_82 , V_451 | V_239 ) ;
F_227 ( V_2 ) ;
F_57 ( V_79 ) ;
F_233 ( V_49 ) ;
F_51 ( V_456 , F_49 ( V_456 ) & 0xf000 ) ;
}
static int F_269 ( struct V_48 * V_49 , int V_506 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( V_506 < V_507 ||
V_506 > V_128 [ V_2 -> V_25 ] . V_508 )
return - V_157 ;
if ( V_506 > V_509 )
F_206 ( V_2 ) ;
else
F_207 ( V_2 ) ;
V_49 -> V_192 = V_506 ;
F_270 ( V_49 ) ;
return 0 ;
}
static inline void F_271 ( struct V_213 * V_214 )
{
V_214 -> V_57 = F_272 ( 0x0badbadbadbadbadull ) ;
V_214 -> V_510 &= ~ F_273 ( V_511 | V_512 ) ;
}
static void F_274 ( struct V_1 * V_2 ,
void * * V_513 , struct V_213 * V_214 )
{
F_275 ( & V_2 -> V_5 -> V_49 , F_121 ( V_214 -> V_57 ) , V_431 ,
V_514 ) ;
F_137 ( * V_513 ) ;
* V_513 = NULL ;
F_271 ( V_214 ) ;
}
static inline void F_276 ( struct V_213 * V_214 , T_2 V_431 )
{
T_2 V_515 = F_103 ( V_214 -> V_510 ) & V_516 ;
V_214 -> V_510 = F_273 ( V_511 | V_515 | V_431 ) ;
}
static inline void F_277 ( struct V_213 * V_214 , T_6 V_517 ,
T_2 V_431 )
{
V_214 -> V_57 = F_272 ( V_517 ) ;
F_278 () ;
F_276 ( V_214 , V_431 ) ;
}
static inline void * F_279 ( void * V_20 )
{
return ( void * ) F_280 ( ( long ) V_20 , 16 ) ;
}
static struct V_210 * F_281 ( struct V_1 * V_2 ,
struct V_213 * V_214 )
{
void * V_20 ;
T_6 V_517 ;
struct V_233 * V_234 = & V_2 -> V_5 -> V_49 ;
struct V_48 * V_49 = V_2 -> V_49 ;
int V_518 = V_49 -> V_49 . V_519 ? F_282 ( V_49 -> V_49 . V_519 ) : - 1 ;
V_20 = F_283 ( V_431 , V_240 , V_518 ) ;
if ( ! V_20 )
return NULL ;
if ( F_279 ( V_20 ) != V_20 ) {
F_137 ( V_20 ) ;
V_20 = F_283 ( V_431 + 15 , V_240 , V_518 ) ;
if ( ! V_20 )
return NULL ;
}
V_517 = F_284 ( V_234 , F_279 ( V_20 ) , V_431 ,
V_514 ) ;
if ( F_285 ( F_286 ( V_234 , V_517 ) ) ) {
if ( F_69 () )
F_131 ( V_2 , V_520 , V_2 -> V_49 , L_21 ) ;
goto V_521;
}
F_277 ( V_214 , V_517 , V_431 ) ;
return V_20 ;
V_521:
F_137 ( V_20 ) ;
return NULL ;
}
static void F_287 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_522 ; V_16 ++ ) {
if ( V_2 -> V_523 [ V_16 ] ) {
F_274 ( V_2 , V_2 -> V_523 + V_16 ,
V_2 -> V_524 + V_16 ) ;
}
}
}
static inline void F_288 ( struct V_213 * V_214 )
{
V_214 -> V_510 |= F_273 ( V_516 ) ;
}
static int F_289 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_522 ; V_16 ++ ) {
void * V_20 ;
if ( V_2 -> V_523 [ V_16 ] )
continue;
V_20 = F_281 ( V_2 , V_2 -> V_524 + V_16 ) ;
if ( ! V_20 ) {
F_271 ( V_2 -> V_524 + V_16 ) ;
goto V_521;
}
V_2 -> V_523 [ V_16 ] = V_20 ;
}
F_288 ( V_2 -> V_524 + V_522 - 1 ) ;
return 0 ;
V_521:
F_287 ( V_2 ) ;
return - V_410 ;
}
static int F_290 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_205 ( V_2 ) ;
memset ( V_2 -> V_525 , 0x0 , V_526 * sizeof( struct V_527 ) ) ;
memset ( V_2 -> V_523 , 0x0 , V_522 * sizeof( void * ) ) ;
return F_289 ( V_2 ) ;
}
static void F_291 ( struct V_233 * V_234 , struct V_527 * V_525 ,
struct V_528 * V_214 )
{
unsigned int V_70 = V_525 -> V_70 ;
F_275 ( V_234 , F_121 ( V_214 -> V_57 ) , V_70 , V_529 ) ;
V_214 -> V_510 = 0x00 ;
V_214 -> V_215 = 0x00 ;
V_214 -> V_57 = 0x00 ;
V_525 -> V_70 = 0 ;
}
static void F_292 ( struct V_1 * V_2 , T_2 V_307 ,
unsigned int V_530 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_530 ; V_16 ++ ) {
unsigned int V_531 = ( V_307 + V_16 ) % V_526 ;
struct V_527 * V_525 = V_2 -> V_525 + V_531 ;
unsigned int V_70 = V_525 -> V_70 ;
if ( V_70 ) {
struct V_210 * V_211 = V_525 -> V_211 ;
F_291 ( & V_2 -> V_5 -> V_49 , V_525 ,
V_2 -> V_532 + V_531 ) ;
if ( V_211 ) {
V_2 -> V_49 -> V_246 . V_533 ++ ;
F_293 ( V_211 ) ;
V_525 -> V_211 = NULL ;
}
}
}
}
static void F_294 ( struct V_1 * V_2 )
{
F_292 ( V_2 , V_2 -> V_395 , V_526 ) ;
V_2 -> V_397 = V_2 -> V_395 = 0 ;
F_295 ( V_2 -> V_49 ) ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
int V_16 ;
F_297 ( & V_2 -> V_534 ) ;
F_298 ( V_49 ) ;
F_299 () ;
F_226 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_522 ; V_16 ++ )
F_276 ( V_2 -> V_524 + V_16 , V_431 ) ;
F_294 ( V_2 ) ;
F_205 ( V_2 ) ;
F_300 ( & V_2 -> V_534 ) ;
F_228 ( V_49 ) ;
F_301 ( V_49 ) ;
F_73 ( V_49 , V_2 , V_2 -> V_15 ) ;
}
static void F_302 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_165 ( V_2 , V_535 ) ;
}
static int F_303 ( struct V_1 * V_2 , struct V_210 * V_211 ,
T_2 * V_536 )
{
struct V_537 * V_131 = F_304 ( V_211 ) ;
unsigned int V_538 , V_531 ;
struct V_528 * V_539 ( V_540 ) ;
struct V_233 * V_234 = & V_2 -> V_5 -> V_49 ;
V_531 = V_2 -> V_397 ;
for ( V_538 = 0 ; V_538 < V_131 -> V_541 ; V_538 ++ ) {
const T_9 * V_542 = V_131 -> V_543 + V_538 ;
T_6 V_517 ;
T_2 V_217 , V_70 ;
void * V_57 ;
V_531 = ( V_531 + 1 ) % V_526 ;
V_540 = V_2 -> V_532 + V_531 ;
V_70 = F_305 ( V_542 ) ;
V_57 = F_306 ( V_542 ) ;
V_517 = F_284 ( V_234 , V_57 , V_70 , V_529 ) ;
if ( F_285 ( F_286 ( V_234 , V_517 ) ) ) {
if ( F_69 () )
F_131 ( V_2 , V_520 , V_2 -> V_49 ,
L_22 ) ;
goto V_521;
}
V_217 = V_536 [ 0 ] | V_70 |
( V_516 * ! ( ( V_531 + 1 ) % V_526 ) ) ;
V_540 -> V_510 = F_273 ( V_217 ) ;
V_540 -> V_215 = F_273 ( V_536 [ 1 ] ) ;
V_540 -> V_57 = F_272 ( V_517 ) ;
V_2 -> V_525 [ V_531 ] . V_70 = V_70 ;
}
if ( V_538 ) {
V_2 -> V_525 [ V_531 ] . V_211 = V_211 ;
V_540 -> V_510 |= F_273 ( V_544 ) ;
}
return V_538 ;
V_521:
F_292 ( V_2 , V_2 -> V_397 + 1 , V_538 ) ;
return - V_545 ;
}
static inline void F_307 ( struct V_1 * V_2 ,
struct V_210 * V_211 , T_2 * V_536 )
{
const struct V_546 * V_131 = V_547 + V_2 -> V_548 ;
T_2 V_549 = F_304 ( V_211 ) -> V_550 ;
int V_460 = V_131 -> V_551 ;
if ( V_549 ) {
V_536 [ 0 ] |= V_552 ;
V_536 [ V_460 ] |= F_308 ( V_549 , V_193 ) << V_131 -> V_553 ;
} else if ( V_211 -> V_554 == V_555 ) {
const struct V_556 * V_557 = F_309 ( V_211 ) ;
if ( V_557 -> V_558 == V_559 )
V_536 [ V_460 ] |= V_131 -> V_308 . V_560 ;
else if ( V_557 -> V_558 == V_561 )
V_536 [ V_460 ] |= V_131 -> V_308 . V_562 ;
else
F_310 ( 1 ) ;
}
}
static T_10 F_311 ( struct V_210 * V_211 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
unsigned int V_531 = V_2 -> V_397 % V_526 ;
struct V_528 * V_540 = V_2 -> V_532 + V_531 ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_233 * V_234 = & V_2 -> V_5 -> V_49 ;
T_6 V_517 ;
T_2 V_217 , V_70 ;
T_2 V_536 [ 2 ] ;
int V_543 ;
if ( F_285 ( ! F_312 ( V_2 , F_304 ( V_211 ) -> V_541 ) ) ) {
F_131 ( V_2 , V_520 , V_49 , L_23 ) ;
goto V_563;
}
if ( F_285 ( F_103 ( V_540 -> V_510 ) & V_511 ) )
goto V_563;
V_70 = F_313 ( V_211 ) ;
V_517 = F_284 ( V_234 , V_211 -> V_20 , V_70 , V_529 ) ;
if ( F_285 ( F_286 ( V_234 , V_517 ) ) ) {
if ( F_69 () )
F_131 ( V_2 , V_520 , V_49 , L_24 ) ;
goto V_564;
}
V_2 -> V_525 [ V_531 ] . V_70 = V_70 ;
V_540 -> V_57 = F_272 ( V_517 ) ;
V_536 [ 1 ] = F_273 ( F_98 ( V_2 , V_211 ) ) ;
V_536 [ 0 ] = V_511 ;
F_307 ( V_2 , V_211 , V_536 ) ;
V_543 = F_303 ( V_2 , V_211 , V_536 ) ;
if ( V_543 < 0 )
goto V_565;
else if ( V_543 )
V_536 [ 0 ] |= V_566 ;
else {
V_536 [ 0 ] |= V_566 | V_544 ;
V_2 -> V_525 [ V_531 ] . V_211 = V_211 ;
}
V_540 -> V_215 = F_273 ( V_536 [ 1 ] ) ;
F_314 ( V_49 , V_211 -> V_70 ) ;
F_315 ( V_211 ) ;
F_278 () ;
V_217 = V_536 [ 0 ] | V_70 | ( V_516 * ! ( ( V_531 + 1 ) % V_526 ) ) ;
V_540 -> V_510 = F_273 ( V_217 ) ;
V_2 -> V_397 += V_543 + 1 ;
F_278 () ;
F_15 ( V_416 , V_417 ) ;
F_52 () ;
if ( ! F_312 ( V_2 , V_567 ) ) {
F_316 () ;
F_298 ( V_49 ) ;
F_317 () ;
if ( F_312 ( V_2 , V_567 ) )
F_301 ( V_49 ) ;
}
return V_568 ;
V_565:
F_291 ( V_234 , V_2 -> V_525 + V_531 , V_540 ) ;
V_564:
F_293 ( V_211 ) ;
V_49 -> V_246 . V_533 ++ ;
return V_568 ;
V_563:
F_298 ( V_49 ) ;
V_49 -> V_246 . V_533 ++ ;
return V_569 ;
}
static void F_318 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_5 * V_6 = V_2 -> V_5 ;
T_1 V_570 , V_571 ;
F_7 ( V_6 , V_572 , & V_571 ) ;
F_7 ( V_6 , V_573 , & V_570 ) ;
F_131 ( V_2 , V_574 , V_49 , L_25 ,
V_571 , V_570 ) ;
if ( V_6 -> V_575 )
V_571 &= ~ V_576 ;
else
V_571 |= V_577 | V_576 ;
F_8 ( V_6 , V_572 , V_571 ) ;
F_8 ( V_6 , V_573 ,
V_570 & ( V_578 |
V_579 | V_580 |
V_581 | V_582 ) ) ;
if ( ( V_2 -> V_202 & V_583 ) && ! V_2 -> V_396 && ! V_2 -> V_398 ) {
void T_4 * V_14 = V_2 -> V_15 ;
F_70 ( V_2 , V_574 , V_49 , L_26 ) ;
V_2 -> V_202 &= ~ V_583 ;
F_51 ( V_205 , V_2 -> V_202 ) ;
V_49 -> V_126 &= ~ V_584 ;
}
F_226 ( V_2 ) ;
F_165 ( V_2 , V_535 ) ;
}
static void F_319 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
struct V_585 * V_586 = & V_2 -> V_586 ;
unsigned int V_395 , V_587 ;
struct V_588 V_589 = { 0 , 0 } ;
V_395 = V_2 -> V_395 ;
F_320 () ;
V_587 = V_2 -> V_397 - V_395 ;
while ( V_587 > 0 ) {
unsigned int V_531 = V_395 % V_526 ;
struct V_527 * V_525 = V_2 -> V_525 + V_531 ;
T_2 V_217 ;
F_321 () ;
V_217 = F_103 ( V_2 -> V_532 [ V_531 ] . V_510 ) ;
if ( V_217 & V_511 )
break;
F_291 ( & V_2 -> V_5 -> V_49 , V_525 ,
V_2 -> V_532 + V_531 ) ;
if ( V_217 & V_544 ) {
struct V_210 * V_211 = V_525 -> V_211 ;
V_589 . V_590 ++ ;
V_589 . V_591 += V_211 -> V_70 ;
F_293 ( V_211 ) ;
V_525 -> V_211 = NULL ;
}
V_395 ++ ;
V_587 -- ;
}
F_322 ( & V_586 -> V_592 ) ;
V_586 -> V_590 += V_589 . V_590 ;
V_586 -> V_591 += V_589 . V_591 ;
F_323 ( & V_586 -> V_592 ) ;
F_324 ( V_49 , V_589 . V_590 , V_589 . V_591 ) ;
if ( V_2 -> V_395 != V_395 ) {
V_2 -> V_395 = V_395 ;
F_317 () ;
if ( F_325 ( V_49 ) &&
F_312 ( V_2 , V_567 ) ) {
F_301 ( V_49 ) ;
}
if ( V_2 -> V_397 != V_395 ) {
void T_4 * V_14 = V_2 -> V_15 ;
F_15 ( V_416 , V_417 ) ;
}
}
}
static inline int F_326 ( T_2 V_217 )
{
return ( V_217 & ( V_566 | V_544 ) ) != ( V_566 | V_544 ) ;
}
static inline void F_327 ( struct V_210 * V_211 , T_2 V_510 )
{
T_2 V_217 = V_510 & V_593 ;
if ( ( ( V_217 == V_594 ) && ! ( V_510 & V_595 ) ) ||
( ( V_217 == V_596 ) && ! ( V_510 & V_597 ) ) )
V_211 -> V_554 = V_598 ;
else
F_328 ( V_211 ) ;
}
static struct V_210 * F_329 ( void * V_20 ,
struct V_1 * V_2 ,
int V_599 ,
T_6 V_57 )
{
struct V_210 * V_211 ;
struct V_233 * V_234 = & V_2 -> V_5 -> V_49 ;
V_20 = F_279 ( V_20 ) ;
F_330 ( V_234 , V_57 , V_599 , V_514 ) ;
F_331 ( V_20 ) ;
V_211 = F_332 ( V_2 -> V_49 , V_599 ) ;
if ( V_211 )
memcpy ( V_211 -> V_20 , V_20 , V_599 ) ;
F_333 ( V_234 , V_57 , V_599 , V_514 ) ;
return V_211 ;
}
static int F_334 ( struct V_48 * V_49 , struct V_1 * V_2 , T_2 V_600 )
{
unsigned int V_398 , V_601 ;
unsigned int V_334 ;
V_398 = V_2 -> V_398 ;
V_601 = V_522 + V_2 -> V_396 - V_398 ;
V_601 = F_308 ( V_601 , V_600 ) ;
for (; V_601 > 0 ; V_601 -- , V_398 ++ ) {
unsigned int V_531 = V_398 % V_522 ;
struct V_213 * V_214 = V_2 -> V_524 + V_531 ;
T_2 V_217 ;
F_321 () ;
V_217 = F_103 ( V_214 -> V_510 ) & V_2 -> V_602 ;
if ( V_217 & V_511 )
break;
if ( F_285 ( V_217 & V_603 ) ) {
F_70 ( V_2 , V_604 , V_49 , L_27 ,
V_217 ) ;
V_49 -> V_246 . V_250 ++ ;
if ( V_217 & ( V_605 | V_606 ) )
V_49 -> V_246 . V_607 ++ ;
if ( V_217 & V_608 )
V_49 -> V_246 . V_609 ++ ;
if ( V_217 & V_610 ) {
F_165 ( V_2 , V_535 ) ;
V_49 -> V_246 . V_611 ++ ;
}
if ( ( V_217 & ( V_606 | V_608 ) ) &&
! ( V_217 & ( V_605 | V_610 ) ) &&
( V_49 -> V_126 & V_199 ) )
goto V_612;
F_276 ( V_214 , V_431 ) ;
} else {
struct V_210 * V_211 ;
T_6 V_57 ;
int V_599 ;
V_612:
V_57 = F_121 ( V_214 -> V_57 ) ;
if ( F_335 ( ! ( V_49 -> V_126 & V_613 ) ) )
V_599 = ( V_217 & 0x00003fff ) - 4 ;
else
V_599 = V_217 & 0x00003fff ;
if ( F_285 ( F_326 ( V_217 ) ) ) {
V_49 -> V_246 . V_614 ++ ;
V_49 -> V_246 . V_607 ++ ;
F_276 ( V_214 , V_431 ) ;
continue;
}
V_211 = F_329 ( V_2 -> V_523 [ V_531 ] ,
V_2 , V_599 , V_57 ) ;
F_276 ( V_214 , V_431 ) ;
if ( ! V_211 ) {
V_49 -> V_246 . V_614 ++ ;
continue;
}
F_327 ( V_211 , V_217 ) ;
F_336 ( V_211 , V_599 ) ;
V_211 -> V_558 = F_337 ( V_211 , V_49 ) ;
F_102 ( V_214 , V_211 ) ;
F_338 ( & V_2 -> V_534 , V_211 ) ;
F_322 ( & V_2 -> V_615 . V_592 ) ;
V_2 -> V_615 . V_590 ++ ;
V_2 -> V_615 . V_591 += V_599 ;
F_323 ( & V_2 -> V_615 . V_592 ) ;
}
if ( ( V_214 -> V_215 & F_273 ( 0xfffe000 ) ) &&
( V_2 -> V_25 == V_291 ) ) {
V_214 -> V_215 = 0 ;
V_398 ++ ;
}
}
V_334 = V_398 - V_2 -> V_398 ;
V_2 -> V_398 = V_398 ;
V_2 -> V_396 += V_334 ;
return V_334 ;
}
static T_11 F_339 ( int V_616 , void * V_617 )
{
struct V_48 * V_49 = V_617 ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
int V_618 = 0 ;
T_1 V_217 ;
V_217 = F_48 ( V_2 ) ;
if ( V_217 && V_217 != 0xffff ) {
V_217 &= V_80 | V_2 -> V_81 ;
if ( V_217 ) {
V_618 = 1 ;
F_53 ( V_2 ) ;
F_340 ( & V_2 -> V_534 ) ;
}
}
return F_341 ( V_618 ) ;
}
static void F_342 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
T_1 V_217 ;
V_217 = F_48 ( V_2 ) & V_2 -> V_81 ;
F_50 ( V_2 , V_217 ) ;
if ( F_285 ( V_217 & V_491 ) ) {
switch ( V_2 -> V_25 ) {
case V_279 :
F_298 ( V_49 ) ;
F_343 ( V_535 , V_2 -> V_3 . V_352 ) ;
default:
break;
}
}
if ( F_285 ( V_217 & V_619 ) )
F_318 ( V_49 ) ;
if ( V_217 & V_620 )
F_66 ( V_49 , V_2 , V_2 -> V_15 , true ) ;
F_297 ( & V_2 -> V_534 ) ;
F_53 ( V_2 ) ;
F_300 ( & V_2 -> V_534 ) ;
F_340 ( & V_2 -> V_534 ) ;
}
static void F_344 ( struct V_621 * V_353 )
{
static const struct {
int V_622 ;
void (* V_315)( struct V_1 * );
} V_623 [] = {
{ V_624 , F_342 } ,
{ V_535 , F_296 } ,
{ V_355 , F_164 }
} ;
struct V_1 * V_2 =
F_345 ( V_353 , struct V_1 , V_3 . V_353 ) ;
struct V_48 * V_49 = V_2 -> V_49 ;
int V_16 ;
F_1 ( V_2 ) ;
if ( ! F_65 ( V_49 ) ||
! F_346 ( V_625 , V_2 -> V_3 . V_352 ) )
goto V_626;
for ( V_16 = 0 ; V_16 < F_77 ( V_623 ) ; V_16 ++ ) {
bool V_627 ;
V_627 = F_347 ( V_623 [ V_16 ] . V_622 , V_2 -> V_3 . V_352 ) ;
if ( V_627 )
V_623 [ V_16 ] . V_315 ( V_2 ) ;
}
V_626:
F_3 ( V_2 ) ;
}
static int F_348 ( struct V_628 * V_534 , int V_600 )
{
struct V_1 * V_2 = F_345 ( V_534 , struct V_1 , V_534 ) ;
struct V_48 * V_49 = V_2 -> V_49 ;
T_1 V_629 = V_80 | V_2 -> V_81 ;
int V_630 = 0 ;
T_1 V_217 ;
V_217 = F_48 ( V_2 ) ;
F_50 ( V_2 , V_217 & ~ V_2 -> V_81 ) ;
if ( V_217 & V_631 )
V_630 = F_334 ( V_49 , V_2 , ( T_2 ) V_600 ) ;
if ( V_217 & V_632 )
F_319 ( V_49 , V_2 ) ;
if ( V_217 & V_2 -> V_81 ) {
V_629 &= ~ V_2 -> V_81 ;
F_165 ( V_2 , V_624 ) ;
}
if ( V_630 < V_600 ) {
F_349 ( V_534 ) ;
F_54 ( V_2 , V_629 ) ;
F_52 () ;
}
return V_630 ;
}
static void F_350 ( struct V_48 * V_49 , void T_4 * V_14 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( V_2 -> V_25 > V_290 )
return;
V_49 -> V_246 . V_633 += ( F_12 ( V_455 ) & 0xffffff ) ;
F_10 ( V_455 , 0 ) ;
}
static void F_351 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
F_93 ( & V_2 -> V_188 ) ;
F_297 ( & V_2 -> V_534 ) ;
F_298 ( V_49 ) ;
F_226 ( V_2 ) ;
F_350 ( V_49 , V_14 ) ;
F_299 () ;
F_294 ( V_2 ) ;
F_287 ( V_2 ) ;
F_201 ( V_2 ) ;
}
static int F_352 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_5 * V_6 = V_2 -> V_5 ;
F_353 ( & V_6 -> V_49 ) ;
F_115 ( V_49 ) ;
F_1 ( V_2 ) ;
F_354 ( V_625 , V_2 -> V_3 . V_352 ) ;
F_351 ( V_49 ) ;
F_3 ( V_2 ) ;
F_355 ( V_6 -> V_616 , V_49 ) ;
F_118 ( & V_6 -> V_49 , V_634 , V_2 -> V_524 ,
V_2 -> V_429 ) ;
F_118 ( & V_6 -> V_49 , V_635 , V_2 -> V_532 ,
V_2 -> V_426 ) ;
V_2 -> V_532 = NULL ;
V_2 -> V_524 = NULL ;
F_356 ( & V_6 -> V_49 ) ;
return 0 ;
}
static void F_357 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_339 ( V_2 -> V_5 -> V_616 , V_49 ) ;
}
static int F_358 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_5 ;
int V_636 = - V_410 ;
F_353 ( & V_6 -> V_49 ) ;
V_2 -> V_532 = F_116 ( & V_6 -> V_49 , V_635 ,
& V_2 -> V_426 , V_240 ) ;
if ( ! V_2 -> V_532 )
goto V_637;
V_2 -> V_524 = F_116 ( & V_6 -> V_49 , V_634 ,
& V_2 -> V_429 , V_240 ) ;
if ( ! V_2 -> V_524 )
goto V_638;
V_636 = F_290 ( V_49 ) ;
if ( V_636 < 0 )
goto V_639;
F_359 ( & V_2 -> V_3 . V_353 , F_344 ) ;
F_317 () ;
F_223 ( V_2 ) ;
V_636 = F_360 ( V_6 -> V_616 , F_339 ,
( V_2 -> V_126 & V_380 ) ? 0 : V_640 ,
V_49 -> V_409 , V_49 ) ;
if ( V_636 < 0 )
goto V_641;
F_1 ( V_2 ) ;
F_343 ( V_625 , V_2 -> V_3 . V_352 ) ;
F_300 ( & V_2 -> V_534 ) ;
F_177 ( V_49 , V_2 ) ;
F_96 ( V_49 , V_49 -> V_126 ) ;
F_202 ( V_2 ) ;
F_228 ( V_49 ) ;
F_361 ( V_49 ) ;
F_3 ( V_2 ) ;
V_2 -> V_642 = 0 ;
F_362 ( & V_6 -> V_49 ) ;
F_73 ( V_49 , V_2 , V_14 ) ;
V_177:
return V_636 ;
V_641:
F_135 ( V_2 ) ;
F_287 ( V_2 ) ;
V_639:
F_118 ( & V_6 -> V_49 , V_634 , V_2 -> V_524 ,
V_2 -> V_429 ) ;
V_2 -> V_524 = NULL ;
V_638:
F_118 ( & V_6 -> V_49 , V_635 , V_2 -> V_532 ,
V_2 -> V_426 ) ;
V_2 -> V_532 = NULL ;
V_637:
F_362 ( & V_6 -> V_49 ) ;
goto V_177;
}
static struct V_643 *
F_363 ( struct V_48 * V_49 , struct V_643 * V_246 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
void T_4 * V_14 = V_2 -> V_15 ;
unsigned int V_307 ;
if ( F_65 ( V_49 ) )
F_350 ( V_49 , V_14 ) ;
do {
V_307 = F_364 ( & V_2 -> V_615 . V_592 ) ;
V_246 -> V_248 = V_2 -> V_615 . V_590 ;
V_246 -> V_644 = V_2 -> V_615 . V_591 ;
} while ( F_365 ( & V_2 -> V_615 . V_592 , V_307 ) );
do {
V_307 = F_364 ( & V_2 -> V_586 . V_592 ) ;
V_246 -> V_247 = V_2 -> V_586 . V_590 ;
V_246 -> V_645 = V_2 -> V_586 . V_591 ;
} while ( F_365 ( & V_2 -> V_586 . V_592 , V_307 ) );
V_246 -> V_614 = V_49 -> V_246 . V_614 ;
V_246 -> V_533 = V_49 -> V_246 . V_533 ;
V_246 -> V_607 = V_49 -> V_246 . V_607 ;
V_246 -> V_250 = V_49 -> V_246 . V_250 ;
V_246 -> V_609 = V_49 -> V_246 . V_609 ;
V_246 -> V_611 = V_49 -> V_246 . V_611 ;
V_246 -> V_633 = V_49 -> V_246 . V_633 ;
return V_246 ;
}
static void F_366 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( ! F_65 ( V_49 ) )
return;
F_367 ( V_49 ) ;
F_298 ( V_49 ) ;
F_1 ( V_2 ) ;
F_297 ( & V_2 -> V_534 ) ;
F_354 ( V_625 , V_2 -> V_3 . V_352 ) ;
F_3 ( V_2 ) ;
F_201 ( V_2 ) ;
}
static int F_368 ( struct V_233 * V_233 )
{
struct V_5 * V_6 = F_369 ( V_233 ) ;
struct V_48 * V_49 = F_370 ( V_6 ) ;
F_366 ( V_49 ) ;
return 0 ;
}
static void F_371 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_372 ( V_49 ) ;
F_202 ( V_2 ) ;
F_1 ( V_2 ) ;
F_300 ( & V_2 -> V_534 ) ;
F_343 ( V_625 , V_2 -> V_3 . V_352 ) ;
F_3 ( V_2 ) ;
F_165 ( V_2 , V_535 ) ;
}
static int F_373 ( struct V_233 * V_233 )
{
struct V_5 * V_6 = F_369 ( V_233 ) ;
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
F_177 ( V_49 , V_2 ) ;
if ( F_65 ( V_49 ) )
F_371 ( V_49 ) ;
return 0 ;
}
static int F_374 ( struct V_233 * V_233 )
{
struct V_5 * V_6 = F_369 ( V_233 ) ;
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( ! V_2 -> V_532 )
return 0 ;
F_1 ( V_2 ) ;
V_2 -> V_642 = F_74 ( V_2 ) ;
F_76 ( V_2 , V_119 ) ;
F_3 ( V_2 ) ;
F_366 ( V_49 ) ;
return 0 ;
}
static int F_375 ( struct V_233 * V_233 )
{
struct V_5 * V_6 = F_369 ( V_233 ) ;
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( ! V_2 -> V_532 )
return 0 ;
F_1 ( V_2 ) ;
F_76 ( V_2 , V_2 -> V_642 ) ;
V_2 -> V_642 = 0 ;
F_3 ( V_2 ) ;
F_177 ( V_49 , V_2 ) ;
F_371 ( V_49 ) ;
return 0 ;
}
static int F_376 ( struct V_233 * V_233 )
{
struct V_5 * V_6 = F_369 ( V_233 ) ;
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
return V_2 -> V_532 ? - V_646 : 0 ;
}
static void F_377 ( struct V_1 * V_2 )
{
void T_4 * V_14 = V_2 -> V_15 ;
switch ( V_2 -> V_25 ) {
case V_279 :
case V_277 :
case V_278 :
F_378 ( V_2 -> V_5 ) ;
F_15 ( V_82 , V_239 ) ;
F_57 ( V_82 ) ;
break;
default:
break;
}
}
static void F_379 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
struct V_233 * V_234 = & V_6 -> V_49 ;
F_353 ( V_234 ) ;
F_366 ( V_49 ) ;
F_179 ( V_2 , V_49 -> V_647 ) ;
F_226 ( V_2 ) ;
if ( V_648 == V_649 ) {
if ( F_74 ( V_2 ) & V_119 ) {
F_189 ( V_2 ) ;
F_377 ( V_2 ) ;
}
F_380 ( V_6 , true ) ;
F_381 ( V_6 , V_650 ) ;
}
F_362 ( V_234 ) ;
}
static void T_12 F_382 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_370 ( V_6 ) ;
struct V_1 * V_2 = F_36 ( V_49 ) ;
if ( V_2 -> V_25 == V_268 ||
V_2 -> V_25 == V_269 ||
V_2 -> V_25 == V_26 ) {
F_19 ( V_2 ) ;
}
F_383 ( & V_2 -> V_3 . V_353 ) ;
F_384 ( V_49 ) ;
F_135 ( V_2 ) ;
if ( F_385 ( V_6 ) )
F_386 ( & V_6 -> V_49 ) ;
F_179 ( V_2 , V_49 -> V_647 ) ;
F_186 ( V_6 , V_2 ) ;
F_169 ( V_6 , V_49 , V_2 -> V_15 ) ;
F_387 ( V_6 , NULL ) ;
}
static unsigned F_388 ( struct V_1 * V_2 ,
const struct V_651 * V_121 )
{
void T_4 * V_14 = V_2 -> V_15 ;
unsigned V_652 = 0 ;
T_3 V_653 ;
V_653 = F_57 ( V_438 ) & ~ V_654 ;
if ( V_121 -> V_126 & V_380 ) {
if ( F_389 ( V_2 -> V_5 ) ) {
F_70 ( V_2 , V_336 , V_2 -> V_49 , L_28 ) ;
} else {
V_653 |= V_654 ;
V_652 = V_380 ;
}
}
if ( V_2 -> V_25 <= V_290 )
F_15 ( V_438 , V_653 ) ;
return V_652 ;
}
static int T_8
F_390 ( struct V_5 * V_6 , const struct V_655 * V_656 )
{
const struct V_651 * V_121 = V_657 + V_656 -> V_658 ;
const unsigned int V_659 = V_121 -> V_659 ;
struct V_1 * V_2 ;
struct V_660 * V_173 ;
struct V_48 * V_49 ;
void T_4 * V_14 ;
int V_661 , V_16 ;
int V_156 ;
if ( F_391 ( & V_662 ) ) {
F_262 ( V_663 L_29 ,
V_134 , V_136 ) ;
}
V_49 = F_392 ( sizeof ( * V_2 ) ) ;
if ( ! V_49 ) {
V_156 = - V_410 ;
goto V_177;
}
F_393 ( V_49 , & V_6 -> V_49 ) ;
V_49 -> V_664 = & V_665 ;
V_2 = F_36 ( V_49 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_229 = F_394 ( V_662 . V_229 , V_666 ) ;
V_173 = & V_2 -> V_173 ;
V_173 -> V_49 = V_49 ;
V_173 -> V_667 = F_37 ;
V_173 -> V_668 = F_35 ;
V_173 -> V_669 = 0x1f ;
V_173 -> V_670 = 0x1f ;
V_173 -> V_174 = ! ! ( V_121 -> V_126 & V_671 ) ;
F_395 ( V_6 , V_672 | V_673 |
V_674 ) ;
V_156 = F_396 ( V_6 ) ;
if ( V_156 < 0 ) {
F_131 ( V_2 , V_296 , V_49 , L_30 ) ;
goto V_675;
}
if ( F_397 ( V_6 ) < 0 )
F_70 ( V_2 , V_296 , V_49 , L_31 ) ;
if ( ! ( F_398 ( V_6 , V_659 ) & V_676 ) ) {
F_131 ( V_2 , V_296 , V_49 ,
L_32 ,
V_659 ) ;
V_156 = - V_373 ;
goto V_677;
}
if ( F_399 ( V_6 , V_659 ) < V_139 ) {
F_131 ( V_2 , V_296 , V_49 ,
L_33 ) ;
V_156 = - V_373 ;
goto V_677;
}
V_156 = F_400 ( V_6 , V_134 ) ;
if ( V_156 < 0 ) {
F_131 ( V_2 , V_296 , V_49 , L_34 ) ;
goto V_677;
}
V_2 -> V_202 = V_203 ;
if ( ( sizeof( T_6 ) > 4 ) &&
! F_401 ( V_6 , F_117 ( 64 ) ) && V_678 ) {
V_2 -> V_202 |= V_583 ;
V_49 -> V_126 |= V_584 ;
} else {
V_156 = F_401 ( V_6 , F_117 ( 32 ) ) ;
if ( V_156 < 0 ) {
F_131 ( V_2 , V_296 , V_49 , L_35 ) ;
goto V_679;
}
}
V_14 = F_402 ( F_403 ( V_6 , V_659 ) , V_139 ) ;
if ( ! V_14 ) {
F_131 ( V_2 , V_296 , V_49 , L_36 ) ;
V_156 = - V_545 ;
goto V_679;
}
V_2 -> V_15 = V_14 ;
if ( ! F_404 ( V_6 ) )
F_70 ( V_2 , V_296 , V_49 , L_37 ) ;
F_124 ( V_2 , V_49 , V_121 -> V_680 ) ;
F_204 ( V_2 ) ;
F_53 ( V_2 ) ;
F_219 ( V_2 ) ;
F_50 ( V_2 , 0xffff ) ;
F_405 ( V_6 ) ;
if ( V_2 -> V_25 == V_291 )
V_2 -> V_202 |= V_204 ;
F_188 ( V_2 ) ;
F_203 ( V_2 ) ;
F_218 ( V_2 ) ;
F_126 ( V_2 ) ;
V_661 = V_2 -> V_25 ;
V_2 -> V_548 = V_128 [ V_661 ] . V_548 ;
F_15 ( V_123 , V_124 ) ;
F_15 ( V_102 , F_57 ( V_102 ) | V_103 ) ;
F_15 ( V_109 , F_57 ( V_109 ) & V_681 ) ;
if ( ( F_57 ( V_104 ) & ( V_105 | V_107 ) ) != 0 )
V_2 -> V_126 |= V_127 ;
if ( ( F_57 ( V_109 ) & ( V_110 | V_112 | V_114 ) ) != 0 )
V_2 -> V_126 |= V_127 ;
V_2 -> V_126 |= F_388 ( V_2 , V_121 ) ;
F_15 ( V_123 , V_125 ) ;
if ( F_176 ( V_2 ) ) {
V_2 -> V_187 = F_87 ;
V_2 -> V_226 = F_105 ;
V_2 -> V_349 = F_62 ;
V_2 -> V_346 = F_58 ;
V_2 -> V_97 = F_60 ;
V_2 -> V_372 = F_185 ;
} else {
V_2 -> V_187 = F_89 ;
V_2 -> V_226 = F_107 ;
V_2 -> V_349 = F_63 ;
V_2 -> V_346 = F_59 ;
V_2 -> V_97 = F_61 ;
V_2 -> V_372 = F_184 ;
}
F_406 ( & V_2 -> V_3 . V_4 ) ;
for ( V_16 = 0 ; V_16 < V_448 ; V_16 ++ )
V_49 -> V_367 [ V_16 ] = F_57 ( V_362 + V_16 ) ;
memcpy ( V_49 -> V_647 , V_49 -> V_367 , V_49 -> V_368 ) ;
F_407 ( V_49 , & V_682 ) ;
V_49 -> V_683 = V_684 ;
F_408 ( V_49 , & V_2 -> V_534 , F_348 , V_685 ) ;
V_49 -> V_126 |= V_200 |
V_686 | V_201 ;
V_49 -> V_687 = V_688 | V_197 | V_689 |
V_200 | V_686 | V_201 ;
V_49 -> V_690 = V_688 | V_197 | V_689 |
V_584 ;
if ( V_2 -> V_25 == V_291 )
V_49 -> V_687 &= ~ V_201 ;
V_49 -> V_687 |= V_199 ;
V_49 -> V_687 |= V_613 ;
V_2 -> V_424 = V_121 -> V_424 ;
V_2 -> V_81 = V_121 -> V_81 ;
V_2 -> V_602 = ( V_2 -> V_25 != V_293 ) ?
~ ( V_691 | V_610 ) : ~ 0 ;
F_409 ( & V_2 -> V_188 ) ;
V_2 -> V_188 . V_20 = ( unsigned long ) V_49 ;
V_2 -> V_188 . V_692 = F_168 ;
V_2 -> V_132 = V_335 ;
V_156 = F_410 ( V_49 ) ;
if ( V_156 < 0 )
goto V_693;
F_387 ( V_6 , V_49 ) ;
F_70 ( V_2 , V_296 , V_49 , L_38 ,
V_128 [ V_661 ] . V_409 , V_14 , V_49 -> V_367 ,
( T_2 ) ( F_12 ( V_295 ) & 0x9cf0f8ff ) , V_6 -> V_616 ) ;
if ( V_128 [ V_661 ] . V_508 != V_195 ) {
F_70 ( V_2 , V_296 , V_49 , L_39
L_40 ,
V_128 [ V_661 ] . V_508 ,
V_128 [ V_661 ] . V_196 ? L_41 : L_42 ) ;
}
if ( V_2 -> V_25 == V_268 ||
V_2 -> V_25 == V_269 ||
V_2 -> V_25 == V_26 ) {
F_18 ( V_2 ) ;
}
F_79 ( & V_6 -> V_49 , V_2 -> V_126 & V_127 ) ;
if ( F_385 ( V_6 ) )
F_362 ( & V_6 -> V_49 ) ;
F_71 ( V_49 ) ;
V_177:
return V_156 ;
V_693:
F_186 ( V_6 , V_2 ) ;
F_170 ( V_14 ) ;
V_679:
F_171 ( V_6 ) ;
V_677:
F_172 ( V_6 ) ;
F_173 ( V_6 ) ;
V_675:
F_174 ( V_49 ) ;
goto V_177;
}
static int T_13 F_411 ( void )
{
return F_412 ( & V_694 ) ;
}
static void T_14 F_413 ( void )
{
F_414 ( & V_694 ) ;
}
