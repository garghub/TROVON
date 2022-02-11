static T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( V_5 & V_8 [ V_6 ] ) {
V_2 -> V_9 [ V_6 ] ( V_2 -> V_10 [ V_6 ] ) ;
V_7 |= V_8 [ V_6 ] ;
}
}
return V_7 ;
}
static T_1 F_4 ( struct V_1 * V_2 , int V_11 )
{
F_2 ( & V_2 -> V_12 ) ;
return V_13 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_14 ) ;
return V_15 ;
}
static T_1 F_6 ( struct V_16 * V_17 )
{
int V_18 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_18 = F_7 ( V_2 -> V_20 + V_21 ) ;
if ( ! ( V_18 & 0x00000800 ) ) {
F_8 ( V_17 -> V_22 , L_1
L_2 , V_18 ) ;
}
return V_23 ;
}
static T_1 F_9 ( struct V_16 * V_17 )
{
int V_18 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_18 = F_7 ( V_2 -> V_20 + V_21 ) ;
if ( ! ( V_18 & 0x00000800 ) )
F_8 ( V_17 -> V_22 , L_3
L_2 , V_18 ) ;
return V_24 ;
}
static T_1 F_10 ( struct V_16 * V_17 ,
int V_5 )
{
int V_25 , V_6 , V_7 = 0 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
for ( V_6 = 7 ; V_6 > 0 ; V_6 -- ) {
if ( V_5 & ( 1 << V_6 ) ) {
V_25 = F_7 ( V_2 -> V_20 +
V_26 [ V_6 ] ) & 0xff ;
F_11 ( V_17 , V_6 , V_25 ) ;
V_7 |= ( 1 << V_6 ) ;
}
}
return V_7 ;
}
static T_2 F_12 ( int V_27 , void * V_28 )
{
T_1 V_5 , V_29 , V_7 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
V_17 = V_28 ;
V_2 = V_17 -> V_19 ;
V_29 = F_7 ( V_2 -> V_20 + V_30 ) ;
V_5 = F_7 ( V_2 -> V_20 + V_31 ) ;
V_5 &= V_29 ;
if ( F_13 ( ! V_5 ) )
return V_32 ;
if ( V_5 & V_4 )
V_7 |= F_1 ( V_2 ) ;
if ( V_5 & ( V_33 | V_34 | V_35 |
V_36 ) )
V_7 |= F_3 ( V_2 , V_5 ) ;
if ( V_5 & V_13 )
V_7 |= F_4 ( V_2 , V_5 ) ;
if ( V_5 & V_15 )
V_7 |= F_5 ( V_2 ) ;
if ( V_5 & V_23 )
V_7 |= F_6 ( V_17 ) ;
if ( V_5 & V_24 )
V_7 |= F_9 ( V_17 ) ;
if ( V_5 & ( V_37 | V_38 |
V_39 | V_40 |
V_41 | V_42 |
V_43 ) )
V_7 |= F_10 ( V_17 , V_5 ) ;
F_14 ( V_7 , V_2 -> V_20 + V_31 ) ;
return V_44 ;
}
static int F_15 ( struct V_16 * V_17 )
{
int V_45 , V_46 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_48 = F_16 ( V_17 -> V_22 ) ;
F_14 ( 0 , V_2 -> V_20 + V_49 ) ;
F_14 ( 0 , V_2 -> V_20 + V_30 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_20 + V_31 ) ;
V_45 = F_17 ( V_48 -> V_27 , F_12 , V_50 ,
V_51 , V_17 ) ;
if ( V_45 ) {
F_8 ( & V_48 -> V_52 , L_4 ,
V_48 -> V_27 ) ;
return V_45 ;
}
F_14 ( 0 , V_2 -> V_20 + V_53 ) ;
F_14 ( 0 , V_2 -> V_20 + V_54 ) ;
F_14 ( 0 , V_2 -> V_20 + V_55 ) ;
V_46 = V_56 | V_57 | V_58 |
V_59 | V_15 |
V_23 | V_24 | V_4 ;
F_14 ( V_46 , V_2 -> V_20 + V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_16 * V_17 ;
F_14 ( 0 , V_2 -> V_20 + V_49 ) ;
F_14 ( 0 , V_2 -> V_20 + V_30 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_20 + V_31 ) ;
V_17 = F_19 ( ( void * ) V_2 , struct V_16 ,
V_19 ) ;
F_20 ( V_48 -> V_27 , V_17 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_60 )
{
T_1 V_46 ;
V_46 = F_7 ( V_2 -> V_20 + V_31 ) ;
if ( V_46 & ( 1 << V_60 ) )
return 0 ;
else
return 1 ;
}
static void F_22 ( struct V_16 * V_17 , int V_60 ,
int V_61 , int V_62 )
{
struct V_47 * V_48 ;
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_46 = F_7 ( V_2 -> V_20 + V_30 ) ;
if ( V_61 == 0 )
V_46 &= ~ V_63 [ V_60 ] ;
else
V_46 |= V_63 [ V_60 ] ;
F_14 ( V_46 , V_2 -> V_20 + V_30 ) ;
if ( ( V_61 == 0 ) && ( V_62 != 0 ) ) {
V_48 = F_16 ( V_17 -> V_22 ) ;
F_23 ( V_48 -> V_27 ) ;
}
}
static int F_24 ( struct V_16 * V_17 , int V_60 ,
int V_64 )
{
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
if ( V_64 & 1 )
return - V_65 ;
F_25 ( & V_2 -> V_66 ) ;
V_46 = F_7 ( V_2 -> V_20 + V_49 ) ;
F_14 ( V_64 << 24 , V_2 -> V_20 + V_67 ) ;
V_46 = V_46 | ( 1 << ( V_60 + 24 ) ) ;
F_14 ( V_46 , V_2 -> V_20 + V_49 ) ;
F_26 ( V_2 -> V_14 ,
F_21 ( V_2 , V_60 ) ) ;
V_46 = F_7 ( V_2 -> V_20 + V_49 ) ;
V_46 = V_46 & ~ ( 1 << ( V_60 + 24 ) ) ;
F_14 ( V_46 , V_2 -> V_20 + V_49 ) ;
F_27 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_28 ( struct V_68 * V_69 , int V_70 ,
unsigned long long V_71 , unsigned long long V_72 ,
T_3 V_73 , T_1 V_74 , T_1 V_75 )
{
unsigned int V_6 , V_76 = 0 , V_77 ;
unsigned int V_78 = 0 ;
unsigned int V_79 , V_80 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
V_17 = V_69 -> V_22 ;
V_2 = V_17 -> V_19 ;
V_6 = V_69 -> V_81 ;
switch ( V_74 ) {
case V_82 :
V_76 |= V_83 ;
break;
case V_84 :
V_76 |= V_85 ;
break;
case V_86 :
V_76 |= V_87 ;
break;
case V_88 :
V_76 |= V_89 ;
break;
case V_90 :
V_76 |= V_91 ;
break;
case V_92 :
case V_93 :
case V_94 :
case V_95 :
default:
F_8 ( V_17 -> V_22 , L_5 ) ;
return - V_65 ;
break;
}
V_79 = V_71 + V_72 ;
V_80 = V_73 - V_71 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_77 = 0x1000 ;
else
V_77 = 0x10000 ;
if ( V_71 & ( V_77 - 1 ) ) {
F_8 ( V_17 -> V_22 , L_6
L_7 ) ;
return - V_65 ;
}
if ( V_79 & ( V_77 - 1 ) ) {
F_8 ( V_17 -> V_22 , L_8
L_7 ) ;
return - V_65 ;
}
if ( V_80 & ( V_77 - 1 ) ) {
F_8 ( V_17 -> V_22 , L_9
L_7 ) ;
return - V_65 ;
}
V_78 = F_7 ( V_2 -> V_20 + V_96 [ V_6 ] ) ;
V_78 &= ~ V_97 ;
F_14 ( V_78 , V_2 -> V_20 + V_96 [ V_6 ] ) ;
F_14 ( V_71 , V_2 -> V_20 + V_98 [ V_6 ] ) ;
F_14 ( V_79 , V_2 -> V_20 + V_99 [ V_6 ] ) ;
F_14 ( V_80 , V_2 -> V_20 + V_100 [ V_6 ] ) ;
V_78 &= ~ V_101 ;
V_78 |= V_76 ;
V_78 &= ~ ( V_102 | V_103 ) ;
if ( V_75 & V_104 )
V_78 |= V_105 ;
if ( V_75 & V_106 )
V_78 |= V_107 ;
if ( V_75 & V_108 )
V_78 |= V_109 ;
if ( V_75 & V_110 )
V_78 |= V_111 ;
F_14 ( V_78 , V_2 -> V_20 + V_96 [ V_6 ] ) ;
if ( V_70 )
V_78 |= V_97 ;
F_14 ( V_78 , V_2 -> V_20 + V_96 [ V_6 ] ) ;
return 0 ;
}
static int F_29 ( struct V_68 * V_69 , int * V_70 ,
unsigned long long * V_71 , unsigned long long * V_72 ,
T_3 * V_73 , T_1 * V_74 , T_1 * V_75 )
{
unsigned int V_6 , V_77 = 0 , V_112 = 0 ;
unsigned long long V_79 , V_80 ;
struct V_1 * V_2 ;
V_2 = V_69 -> V_22 -> V_19 ;
V_6 = V_69 -> V_81 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_77 = 0x1000 ;
else
V_77 = 0x10000 ;
V_112 = F_7 ( V_2 -> V_20 + V_96 [ V_6 ] ) ;
* V_71 = F_7 ( V_2 -> V_20 + V_98 [ V_6 ] ) ;
V_79 = F_7 ( V_2 -> V_20 + V_99 [ V_6 ] ) ;
V_80 = F_7 ( V_2 -> V_20 + V_100 [ V_6 ] ) ;
* V_73 = ( T_3 ) * V_71 + V_80 ;
* V_72 = ( unsigned long long ) ( ( V_79 - * V_71 ) + V_77 ) ;
* V_70 = 0 ;
* V_74 = 0 ;
* V_75 = 0 ;
if ( V_112 & V_97 )
* V_70 = 1 ;
if ( ( V_112 & V_101 ) == V_83 )
* V_74 = V_82 ;
if ( ( V_112 & V_101 ) == V_85 )
* V_74 = V_84 ;
if ( ( V_112 & V_101 ) == V_87 )
* V_74 = V_86 ;
if ( ( V_112 & V_101 ) == V_89 )
* V_74 = V_88 ;
if ( ( V_112 & V_101 ) == V_91 )
* V_74 = V_90 ;
if ( V_112 & V_105 )
* V_75 |= V_104 ;
if ( V_112 & V_107 )
* V_75 |= V_106 ;
if ( V_112 & V_109 )
* V_75 |= V_108 ;
if ( V_112 & V_111 )
* V_75 |= V_110 ;
return 0 ;
}
static int F_30 ( struct V_113 * V_69 ,
unsigned long long V_72 )
{
unsigned long long V_114 ;
int V_115 = 0 ;
struct V_47 * V_48 ;
struct V_16 * V_17 ;
V_17 = V_69 -> V_22 ;
if ( V_17 -> V_22 == NULL ) {
F_8 ( V_17 -> V_22 , L_10 ) ;
return - V_65 ;
}
V_48 = F_16 ( V_17 -> V_22 ) ;
V_114 = ( unsigned long long ) ( V_69 -> V_116 . V_117 -
V_69 -> V_116 . V_118 ) ;
if ( V_114 == ( V_72 - 1 ) )
return 0 ;
if ( V_114 != 0 ) {
F_31 ( V_69 -> V_119 ) ;
V_69 -> V_119 = NULL ;
F_32 ( V_69 -> V_116 . V_120 ) ;
F_33 ( & V_69 -> V_116 ) ;
memset ( & V_69 -> V_116 , 0 , sizeof( struct V_121 ) ) ;
}
if ( V_69 -> V_116 . V_120 == NULL ) {
V_69 -> V_116 . V_120 = F_34 ( V_122 + 3 , V_123 ) ;
if ( V_69 -> V_116 . V_120 == NULL ) {
F_8 ( V_17 -> V_22 , L_11
L_12 ) ;
V_115 = - V_124 ;
goto V_125;
}
}
sprintf ( ( char * ) V_69 -> V_116 . V_120 , L_13 ,
V_17 -> V_120 , V_69 -> V_81 ) ;
V_69 -> V_116 . V_118 = 0 ;
V_69 -> V_116 . V_117 = ( unsigned long ) V_72 ;
V_69 -> V_116 . V_126 = V_127 ;
V_115 = F_35 ( V_48 -> V_128 ,
& V_69 -> V_116 , V_72 , 0x10000 , V_129 ,
0 , NULL , NULL ) ;
if ( V_115 ) {
F_8 ( V_17 -> V_22 , L_14
L_15 ,
V_69 -> V_81 , ( unsigned long ) V_72 ,
( unsigned long ) V_69 -> V_116 . V_118 ) ;
goto V_130;
}
V_69 -> V_119 = F_36 (
V_69 -> V_116 . V_118 , V_72 ) ;
if ( V_69 -> V_119 == NULL ) {
F_8 ( V_17 -> V_22 , L_16 ) ;
V_115 = - V_124 ;
goto V_131;
}
return 0 ;
V_131:
F_33 ( & V_69 -> V_116 ) ;
V_130:
F_32 ( V_69 -> V_116 . V_120 ) ;
memset ( & V_69 -> V_116 , 0 , sizeof( struct V_121 ) ) ;
V_125:
return V_115 ;
}
static void F_37 ( struct V_113 * V_69 )
{
F_31 ( V_69 -> V_119 ) ;
V_69 -> V_119 = NULL ;
F_33 ( & V_69 -> V_116 ) ;
F_32 ( V_69 -> V_116 . V_120 ) ;
memset ( & V_69 -> V_116 , 0 , sizeof( struct V_121 ) ) ;
}
static int F_38 ( struct V_113 * V_69 , int V_70 ,
unsigned long long V_71 , unsigned long long V_72 , T_1 V_74 ,
T_1 V_75 , T_1 V_132 )
{
int V_115 = 0 ;
unsigned int V_6 , V_77 = 0 ;
unsigned int V_78 = 0 ;
unsigned long long V_133 , V_134 , V_73 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
V_17 = V_69 -> V_22 ;
V_2 = V_17 -> V_19 ;
V_6 = V_69 -> V_81 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_77 = 0x1000 ;
else
V_77 = 0x10000 ;
if ( V_71 & ( V_77 - 1 ) ) {
F_8 ( V_17 -> V_22 , L_17
L_7 ) ;
V_115 = - V_65 ;
goto V_135;
}
if ( V_72 & ( V_77 - 1 ) ) {
F_8 ( V_17 -> V_22 , L_17
L_7 ) ;
V_115 = - V_65 ;
goto V_135;
}
F_39 ( & V_69 -> V_136 ) ;
V_115 = F_30 ( V_69 , V_72 ) ;
if ( V_115 ) {
F_40 ( & V_69 -> V_136 ) ;
F_8 ( V_17 -> V_22 , L_18
L_19 ) ;
V_115 = - V_124 ;
goto V_137;
}
V_73 = ( unsigned long long ) V_69 -> V_116 . V_118 ;
V_133 = V_73 + V_72 ;
V_134 = V_71 - V_73 ;
V_78 = F_7 ( V_2 -> V_20 + V_138 [ V_6 ] ) ;
V_78 &= ~ V_139 ;
F_14 ( V_78 , V_2 -> V_20 + V_138 [ V_6 ] ) ;
V_78 &= ~ V_140 ;
if ( V_75 & V_141 )
V_78 |= V_142 ;
if ( V_75 & V_143 )
V_78 |= V_144 ;
V_78 &= ~ V_145 ;
switch ( V_132 ) {
case V_146 :
V_78 |= V_147 ;
break;
case V_148 :
V_78 |= V_149 ;
break;
case V_150 :
V_78 |= V_151 ;
break;
case V_152 :
V_78 |= V_153 ;
break;
default:
F_40 ( & V_69 -> V_136 ) ;
F_8 ( V_17 -> V_22 , L_20 ) ;
V_115 = - V_65 ;
goto V_154;
break;
}
V_78 &= ~ V_155 ;
switch ( V_74 ) {
case V_82 :
V_78 |= V_156 ;
break;
case V_84 :
V_78 |= V_157 ;
break;
case V_86 :
V_78 |= V_158 ;
break;
case V_93 :
V_78 |= V_159 ;
break;
case V_88 :
V_78 |= V_160 ;
break;
case V_90 :
V_78 |= V_161 ;
break;
case V_92 :
case V_94 :
case V_95 :
default:
F_40 ( & V_69 -> V_136 ) ;
F_8 ( V_17 -> V_22 , L_5 ) ;
V_115 = - V_65 ;
goto V_162;
break;
}
V_78 &= ~ ( V_163 | V_164 ) ;
if ( V_75 & V_104 )
V_78 |= V_165 ;
if ( V_75 & V_108 )
V_78 |= V_166 ;
F_14 ( V_73 , V_2 -> V_20 + V_167 [ V_6 ] ) ;
F_14 ( V_133 , V_2 -> V_20 + V_168 [ V_6 ] ) ;
F_14 ( V_134 , V_2 -> V_20 + V_169 [ V_6 ] ) ;
F_14 ( V_78 , V_2 -> V_20 + V_138 [ V_6 ] ) ;
if ( V_70 )
V_78 |= V_139 ;
F_14 ( V_78 , V_2 -> V_20 + V_138 [ V_6 ] ) ;
F_40 ( & V_69 -> V_136 ) ;
return 0 ;
V_162:
V_154:
F_37 ( V_69 ) ;
V_137:
V_135:
return V_115 ;
}
static int F_41 ( struct V_113 * V_69 ,
int * V_70 , unsigned long long * V_71 , unsigned long long * V_72 ,
T_1 * V_74 , T_1 * V_75 , T_1 * V_132 )
{
unsigned int V_6 , V_112 ;
unsigned long long V_73 , V_133 , V_134 ;
struct V_1 * V_2 ;
V_2 = V_69 -> V_22 -> V_19 ;
V_6 = V_69 -> V_81 ;
V_112 = F_7 ( V_2 -> V_20 + V_138 [ V_6 ] ) ;
V_73 = F_7 ( V_2 -> V_20 + V_167 [ V_6 ] ) ;
V_134 = F_7 ( V_2 -> V_20 + V_169 [ V_6 ] ) ;
V_133 = F_7 ( V_2 -> V_20 + V_168 [ V_6 ] ) ;
* V_71 = V_73 + V_134 ;
* V_72 = ( unsigned long long ) ( V_133 - V_73 ) ;
* V_70 = 0 ;
* V_74 = 0 ;
* V_75 = 0 ;
* V_132 = 0 ;
if ( V_112 & V_139 )
* V_70 = 1 ;
switch ( V_112 & V_155 ) {
case V_156 :
* V_74 = V_82 ;
break;
case V_157 :
* V_74 = V_84 ;
break;
case V_158 :
* V_74 = V_86 ;
break;
case V_159 :
* V_74 = V_93 ;
break;
case V_160 :
* V_74 = V_88 ;
break;
case V_161 :
* V_74 = V_90 ;
break;
}
if ( V_112 & V_142 )
* V_75 |= V_141 ;
else
* V_75 |= V_170 ;
if ( V_112 & V_165 )
* V_75 |= V_104 ;
else
* V_75 |= V_106 ;
if ( V_112 & V_166 )
* V_75 = V_108 ;
else
* V_75 = V_110 ;
switch ( V_112 & V_145 ) {
case V_147 :
* V_132 = V_146 ;
break;
case V_149 :
* V_132 = V_148 ;
break;
case V_151 :
* V_132 = V_150 ;
break;
case V_153 :
* V_132 = V_152 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_113 * V_69 , int * V_70 ,
unsigned long long * V_71 , unsigned long long * V_72 , T_1 * V_74 ,
T_1 * V_75 , T_1 * V_132 )
{
int V_115 ;
F_39 ( & V_69 -> V_136 ) ;
V_115 = F_41 ( V_69 , V_70 , V_71 , V_72 , V_74 ,
V_75 , V_132 ) ;
F_40 ( & V_69 -> V_136 ) ;
return V_115 ;
}
static T_4 F_43 ( struct V_113 * V_69 ,
void * V_171 , T_5 V_172 , T_6 V_173 )
{
T_4 V_115 ;
void T_7 * V_76 = V_69 -> V_119 + V_173 ;
unsigned int V_174 = 0 ;
unsigned int V_175 ;
if ( V_172 == 0 )
return 0 ;
F_39 ( & V_69 -> V_136 ) ;
if ( ( V_176 ) V_76 & 0x1 ) {
* ( V_177 * ) V_171 = F_44 ( V_76 ) ;
V_174 += 1 ;
if ( V_174 == V_172 )
goto V_178;
}
if ( ( V_176 ) ( V_76 + V_174 ) & 0x2 ) {
if ( ( V_172 - V_174 ) < 2 ) {
* ( V_177 * ) ( V_171 + V_174 ) = F_44 ( V_76 + V_174 ) ;
V_174 += 1 ;
goto V_178;
} else {
* ( V_179 * ) ( V_171 + V_174 ) = F_45 ( V_76 + V_174 ) ;
V_174 += 2 ;
}
}
V_175 = ( V_172 - V_174 ) & ~ 0x3 ;
while ( V_174 < V_175 ) {
* ( T_1 * ) ( V_171 + V_174 ) = F_7 ( V_76 + V_174 ) ;
V_174 += 4 ;
}
if ( ( V_172 - V_174 ) & 0x2 ) {
* ( V_179 * ) ( V_171 + V_174 ) = F_45 ( V_76 + V_174 ) ;
V_174 += 2 ;
}
if ( ( V_172 - V_174 ) & 0x1 ) {
* ( V_177 * ) ( V_171 + V_174 ) = F_44 ( V_76 + V_174 ) ;
V_174 += 1 ;
}
V_178:
V_115 = V_172 ;
F_40 ( & V_69 -> V_136 ) ;
return V_115 ;
}
static T_4 F_46 ( struct V_113 * V_69 ,
void * V_171 , T_5 V_172 , T_6 V_173 )
{
T_4 V_115 ;
void T_7 * V_76 = V_69 -> V_119 + V_173 ;
unsigned int V_174 = 0 ;
unsigned int V_175 ;
if ( V_172 == 0 )
return 0 ;
F_39 ( & V_69 -> V_136 ) ;
if ( ( V_176 ) V_76 & 0x1 ) {
F_47 ( * ( V_177 * ) V_171 , V_76 ) ;
V_174 += 1 ;
if ( V_174 == V_172 )
goto V_178;
}
if ( ( V_176 ) ( V_76 + V_174 ) & 0x2 ) {
if ( ( V_172 - V_174 ) < 2 ) {
F_47 ( * ( V_177 * ) ( V_171 + V_174 ) , V_76 + V_174 ) ;
V_174 += 1 ;
goto V_178;
} else {
F_48 ( * ( V_179 * ) ( V_171 + V_174 ) , V_76 + V_174 ) ;
V_174 += 2 ;
}
}
V_175 = ( V_172 - V_174 ) & ~ 0x3 ;
while ( V_174 < V_175 ) {
F_14 ( * ( T_1 * ) ( V_171 + V_174 ) , V_76 + V_174 ) ;
V_174 += 4 ;
}
if ( ( V_172 - V_174 ) & 0x2 ) {
F_48 ( * ( V_179 * ) ( V_171 + V_174 ) , V_76 + V_174 ) ;
V_174 += 2 ;
}
if ( ( V_172 - V_174 ) & 0x1 ) {
F_47 ( * ( V_177 * ) ( V_171 + V_174 ) , V_76 + V_174 ) ;
V_174 += 1 ;
}
V_178:
V_115 = V_172 ;
F_40 ( & V_69 -> V_136 ) ;
return V_115 ;
}
static unsigned int F_49 ( struct V_113 * V_69 ,
unsigned int V_180 , unsigned int V_181 , unsigned int V_182 ,
T_6 V_173 )
{
T_1 V_45 ;
V_176 V_183 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_184 * V_52 ;
V_2 = V_69 -> V_22 -> V_19 ;
V_52 = V_69 -> V_22 -> V_22 ;
V_6 = V_69 -> V_81 ;
F_25 ( & V_2 -> V_185 ) ;
F_39 ( & V_69 -> V_136 ) ;
V_183 = ( V_176 ) V_69 -> V_119 + V_173 ;
if ( V_183 & 0x3 ) {
F_8 ( V_52 , L_21 ) ;
V_45 = - V_65 ;
goto V_178;
}
F_14 ( 0 , V_2 -> V_20 + V_186 ) ;
F_14 ( V_180 , V_2 -> V_20 + V_187 ) ;
F_14 ( V_181 , V_2 -> V_20 + V_188 ) ;
F_14 ( V_182 , V_2 -> V_20 + V_189 ) ;
F_14 ( V_183 , V_2 -> V_20 + V_190 ) ;
F_14 ( V_191 , V_2 -> V_20 + V_186 ) ;
V_45 = F_7 ( V_69 -> V_119 + V_173 ) ;
F_14 ( 0 , V_2 -> V_20 + V_186 ) ;
V_178:
F_40 ( & V_69 -> V_136 ) ;
F_27 ( & V_2 -> V_185 ) ;
return V_45 ;
}
static int F_50 ( struct V_192 * V_193 ,
struct V_194 * V_195 , struct V_194 * V_196 , T_5 V_172 )
{
struct V_197 * V_198 , * V_199 ;
struct V_200 * V_201 ;
struct V_202 * V_203 ;
T_3 V_204 ;
int V_115 = 0 ;
struct V_184 * V_52 ;
V_52 = V_193 -> V_22 -> V_22 -> V_22 ;
V_198 = F_34 ( sizeof( struct V_197 ) , V_205 ) ;
if ( V_198 == NULL ) {
F_8 ( V_52 , L_22
L_23 ) ;
V_115 = - V_124 ;
goto V_206;
}
if ( ( unsigned long ) & V_198 -> V_207 & V_208 ) {
F_8 ( V_52 , L_24
L_25 , & V_198 -> V_207 ) ;
V_115 = - V_65 ;
goto V_209;
}
memset ( & V_198 -> V_207 , 0 , sizeof( struct V_210 ) ) ;
if ( V_196 -> type == V_211 ) {
V_198 -> V_207 . V_212 |= V_213 ;
V_203 = V_196 -> V_214 ;
V_201 = V_195 -> V_214 ;
} else {
V_203 = V_195 -> V_214 ;
V_201 = V_196 -> V_214 ;
}
if ( ( V_203 -> V_74 & ~ ( V_82 | V_84 | V_86 | V_88 |
V_90 ) ) != 0 ) {
F_8 ( V_52 , L_26 ) ;
V_115 = - V_65 ;
goto V_162;
}
if ( ( V_203 -> V_75 & ~ ( V_170 | V_141 | V_104 | V_106 |
V_108 | V_110 ) ) != 0 ) {
F_8 ( V_52 , L_26 ) ;
V_115 = - V_65 ;
goto V_215;
}
if ( ! ( ( ( V_195 -> type == V_216 ) && ( V_196 -> type == V_211 ) ) ||
( ( V_195 -> type == V_211 ) && ( V_196 -> type == V_216 ) ) ) ) {
F_8 ( V_52 , L_27
L_28 ) ;
V_115 = - V_65 ;
goto V_217;
}
if ( V_203 -> V_75 & V_141 )
V_198 -> V_207 . V_212 |= V_218 ;
switch ( V_203 -> V_132 ) {
case V_146 :
V_198 -> V_207 . V_212 |= V_219 ;
break;
case V_148 :
V_198 -> V_207 . V_212 |= V_220 ;
break;
case V_150 :
V_198 -> V_207 . V_212 |= V_221 ;
break;
case V_152 :
V_198 -> V_207 . V_212 |= V_222 ;
break;
default:
F_8 ( V_52 , L_20 ) ;
return - V_65 ;
}
switch ( V_203 -> V_74 ) {
case V_82 :
V_198 -> V_207 . V_212 |= V_223 ;
break;
case V_84 :
V_198 -> V_207 . V_212 |= V_224 ;
break;
case V_86 :
V_198 -> V_207 . V_212 |= V_225 ;
break;
case V_88 :
V_198 -> V_207 . V_212 |= V_226 ;
break;
case V_90 :
V_198 -> V_207 . V_212 |= V_227 ;
break;
default:
F_8 ( V_52 , L_5 ) ;
return - V_65 ;
break;
}
if ( V_203 -> V_75 & V_104 )
V_198 -> V_207 . V_212 |= V_228 ;
if ( V_203 -> V_75 & V_108 )
V_198 -> V_207 . V_212 |= V_229 ;
V_198 -> V_207 . V_230 = V_172 ;
V_198 -> V_207 . V_231 = V_201 -> V_232 ;
V_198 -> V_207 . V_233 = V_203 -> V_232 ;
V_198 -> V_207 . V_234 = V_235 ;
F_51 ( & V_198 -> V_193 , & V_193 -> V_236 ) ;
if ( V_198 -> V_193 . V_199 != & V_193 -> V_236 ) {
V_199 = F_52 ( V_198 -> V_193 . V_199 , struct V_197 ,
V_193 ) ;
V_204 = F_53 ( & V_198 -> V_207 ) ;
V_199 -> V_207 . V_234 = V_204 & ~ V_208 ;
}
return 0 ;
V_215:
V_162:
V_217:
V_209:
F_32 ( V_198 ) ;
V_206:
return V_115 ;
}
static int F_54 ( struct V_16 * V_17 )
{
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_46 = F_7 ( V_2 -> V_20 + V_21 ) ;
if ( V_46 & V_237 )
return 0 ;
else
return 1 ;
}
static int F_55 ( struct V_192 * V_193 )
{
struct V_238 * V_239 ;
struct V_197 * V_198 ;
int V_115 ;
T_3 V_240 ;
T_1 V_18 ;
struct V_184 * V_52 ;
struct V_1 * V_2 ;
V_239 = V_193 -> V_22 ;
V_2 = V_239 -> V_22 -> V_19 ;
V_52 = V_239 -> V_22 -> V_22 ;
F_25 ( & V_239 -> V_241 ) ;
if ( ! ( F_56 ( & V_239 -> V_242 ) ) ) {
F_27 ( & V_239 -> V_241 ) ;
return - V_243 ;
} else {
F_57 ( & V_193 -> V_193 , & V_239 -> V_242 ) ;
}
V_198 = F_58 ( & V_193 -> V_236 , struct V_197 ,
V_193 ) ;
V_240 = F_53 ( & V_198 -> V_207 ) ;
F_27 ( & V_239 -> V_241 ) ;
F_14 ( 0 , V_2 -> V_20 + V_244 ) ;
F_14 ( V_240 & ~ V_208 , V_2 -> V_20 + V_245 ) ;
V_18 = F_7 ( V_2 -> V_20 + V_21 ) ;
V_18 &= ( V_246 | V_247 ) ;
V_18 |= ( V_248 | V_249 | V_250 |
V_251 | V_252 | V_253 |
V_254 ) ;
F_14 ( V_18 , V_2 -> V_20 + V_21 ) ;
V_18 |= V_255 ;
F_14 ( V_18 , V_2 -> V_20 + V_21 ) ;
V_115 = F_26 ( V_2 -> V_3 ,
F_54 ( V_239 -> V_22 ) ) ;
if ( V_115 ) {
V_18 = F_7 ( V_2 -> V_20 + V_21 ) ;
F_14 ( V_18 | V_256 , V_2 -> V_20 + V_21 ) ;
F_59 ( V_2 -> V_3 ,
F_54 ( V_239 -> V_22 ) ) ;
V_115 = - V_257 ;
goto exit;
}
V_18 = F_7 ( V_2 -> V_20 + V_21 ) ;
if ( V_18 & ( V_252 | V_253 |
V_254 ) ) {
F_8 ( V_52 , L_29 , V_18 ) ;
V_18 = F_7 ( V_2 -> V_20 + V_258 ) ;
V_115 = - V_259 ;
}
exit:
F_25 ( & V_239 -> V_241 ) ;
F_60 ( & V_193 -> V_193 ) ;
F_27 ( & V_239 -> V_241 ) ;
return V_115 ;
}
static int F_61 ( struct V_192 * V_193 )
{
struct V_260 * V_261 , * V_262 ;
struct V_197 * V_198 ;
F_62 (pos, temp, &list->entries) {
F_60 ( V_261 ) ;
V_198 = F_52 ( V_261 , struct V_197 , V_193 ) ;
F_32 ( V_198 ) ;
}
return 0 ;
}
static int F_63 ( struct V_263 * V_264 ,
unsigned long long V_265 , T_1 V_74 , T_1 V_75 )
{
T_1 V_266 , V_267 = 0 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_184 * V_52 ;
V_2 = V_264 -> V_22 -> V_19 ;
V_52 = V_264 -> V_22 -> V_22 ;
V_266 = ( T_1 ) V_265 ;
if ( V_266 & 0xffff ) {
F_8 ( V_52 , L_30
L_31 ) ;
return - V_65 ;
}
F_25 ( & V_264 -> V_241 ) ;
for ( V_6 = 0 ; V_6 < V_264 -> V_268 ; V_6 ++ ) {
if ( V_2 -> V_9 [ V_6 ] != NULL ) {
F_27 ( & V_264 -> V_241 ) ;
F_8 ( V_52 , L_32
L_33 ) ;
return - V_243 ;
}
}
switch ( V_74 ) {
case V_82 :
V_267 |= V_269 ;
break;
case V_84 :
V_267 |= V_270 ;
break;
case V_86 :
V_267 |= V_271 ;
break;
default:
F_27 ( & V_264 -> V_241 ) ;
F_8 ( V_52 , L_5 ) ;
return - V_65 ;
break;
}
if ( V_75 & V_104 )
V_267 |= V_272 ;
if ( V_75 & V_106 )
V_267 |= V_273 ;
if ( V_75 & V_108 )
V_267 |= V_274 ;
if ( V_75 & V_110 )
V_267 |= V_275 ;
F_14 ( V_265 , V_2 -> V_20 + V_276 ) ;
F_14 ( V_267 , V_2 -> V_20 + V_277 ) ;
F_27 ( & V_264 -> V_241 ) ;
return 0 ;
}
static int F_64 ( struct V_263 * V_264 ,
unsigned long long * V_265 , T_1 * V_74 , T_1 * V_75 )
{
T_1 V_267 , V_70 = 0 ;
struct V_1 * V_2 ;
V_2 = V_264 -> V_22 -> V_19 ;
F_25 ( & V_264 -> V_241 ) ;
* V_265 = ( unsigned long long ) F_7 ( V_2 -> V_20 + V_276 ) ;
V_267 = F_7 ( V_2 -> V_20 + V_277 ) ;
if ( V_267 & V_278 )
V_70 = 1 ;
if ( ( V_267 & V_279 ) == V_269 )
* V_74 = V_82 ;
if ( ( V_267 & V_279 ) == V_270 )
* V_74 = V_84 ;
if ( ( V_267 & V_279 ) == V_271 )
* V_74 = V_86 ;
* V_75 = 0 ;
if ( V_267 & V_272 )
* V_75 |= V_104 ;
if ( V_267 & V_273 )
* V_75 |= V_106 ;
if ( V_267 & V_274 )
* V_75 |= V_108 ;
if ( V_267 & V_275 )
* V_75 |= V_110 ;
F_27 ( & V_264 -> V_241 ) ;
return V_70 ;
}
static int F_65 ( struct V_263 * V_264 , int V_280 ,
void (* F_66)( void * ) , void * V_281 )
{
T_1 V_267 , V_46 ;
struct V_1 * V_2 ;
struct V_184 * V_52 ;
V_2 = V_264 -> V_22 -> V_19 ;
V_52 = V_264 -> V_22 -> V_22 ;
F_25 ( & V_264 -> V_241 ) ;
V_267 = F_7 ( V_2 -> V_20 + V_277 ) ;
if ( ( V_267 & ( V_274 | V_275 ) ) == 0 ) {
F_27 ( & V_264 -> V_241 ) ;
F_8 ( V_52 , L_34 ) ;
return - V_65 ;
}
if ( V_2 -> V_9 [ V_280 ] != NULL ) {
F_27 ( & V_264 -> V_241 ) ;
F_8 ( V_52 , L_35 ) ;
return - V_243 ;
}
V_2 -> V_9 [ V_280 ] = F_66 ;
V_2 -> V_10 [ V_280 ] = V_281 ;
V_46 = F_7 ( V_2 -> V_20 + V_30 ) ;
V_46 |= V_8 [ V_280 ] ;
F_14 ( V_46 , V_2 -> V_20 + V_30 ) ;
if ( ( V_267 & V_278 ) == 0 ) {
V_267 |= V_278 ;
F_14 ( V_267 , V_2 -> V_20 + V_277 ) ;
}
F_27 ( & V_264 -> V_241 ) ;
return 0 ;
}
static int F_67 ( struct V_263 * V_264 , int V_280 )
{
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = V_264 -> V_22 -> V_19 ;
F_25 ( & V_264 -> V_241 ) ;
V_46 = F_7 ( V_2 -> V_20 + V_30 ) ;
V_46 &= ~ V_8 [ V_280 ] ;
F_14 ( V_46 , V_2 -> V_20 + V_30 ) ;
F_14 ( V_8 [ V_280 ] ,
V_2 -> V_20 + V_31 ) ;
V_2 -> V_9 [ V_280 ] = NULL ;
V_2 -> V_10 [ V_280 ] = NULL ;
if ( ( V_46 & ( V_33 | V_34 | V_35 |
V_36 ) ) == 0 ) {
V_46 = F_7 ( V_2 -> V_20 + V_277 ) ;
V_46 &= ~ V_278 ;
F_14 ( V_46 , V_2 -> V_20 + V_277 ) ;
}
F_27 ( & V_264 -> V_241 ) ;
return 0 ;
}
static int F_68 ( struct V_16 * V_17 )
{
T_1 V_282 = 0 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
if ( ! V_283 ) {
V_282 = F_7 ( V_2 -> V_20 + V_284 ) ;
V_282 = ( ( V_282 & V_285 ) >> 27 ) ;
} else
V_282 = V_283 ;
return ( int ) V_282 ;
}
static void * F_69 ( struct V_184 * V_22 , T_5 V_72 ,
T_3 * V_286 )
{
struct V_47 * V_48 ;
V_48 = F_16 ( V_22 ) ;
return F_70 ( V_48 , V_72 , V_286 ) ;
}
static void F_71 ( struct V_184 * V_22 , T_5 V_72 ,
void * V_287 , T_3 V_286 )
{
struct V_47 * V_48 ;
V_48 = F_16 ( V_22 ) ;
F_72 ( V_48 , V_72 , V_287 , V_286 ) ;
}
static int F_73 ( struct V_16 * V_17 ,
struct V_47 * V_48 )
{
unsigned int V_288 ;
int V_46 , V_282 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_282 = F_68 ( V_17 ) ;
if ( V_283 )
F_14 ( V_283 << 27 , V_2 -> V_20 + V_284 ) ;
F_74 ( & V_48 -> V_52 , L_36 , V_282 ) ;
if ( V_282 == 0 ) {
F_8 ( & V_48 -> V_52 , L_37
L_38 ) ;
return - V_65 ;
}
V_2 -> V_289 = F_75 ( V_48 , V_290 ,
& V_2 -> V_291 ) ;
if ( V_2 -> V_289 == NULL ) {
F_8 ( & V_48 -> V_52 , L_39
L_40 ) ;
return - V_124 ;
}
V_288 = V_282 * ( 512 * 1024 ) ;
F_14 ( V_2 -> V_291 - V_288 , V_2 -> V_20 + V_292 ) ;
V_46 = F_7 ( V_2 -> V_20 + V_293 ) ;
V_46 |= V_294 ;
F_14 ( V_46 , V_2 -> V_20 + V_293 ) ;
return 0 ;
}
static void F_76 ( struct V_16 * V_17 ,
struct V_47 * V_48 )
{
T_1 V_46 ;
struct V_1 * V_2 ;
V_2 = V_17 -> V_19 ;
V_46 = F_7 ( V_2 -> V_20 + V_293 ) ;
V_46 &= ~ V_294 ;
F_14 ( V_46 , V_2 -> V_20 + V_293 ) ;
F_14 ( 0 , V_2 -> V_20 + V_292 ) ;
F_72 ( V_48 , V_290 , V_2 -> V_289 ,
V_2 -> V_291 ) ;
}
static int F_77 ( struct V_47 * V_48 , const struct V_295 * V_296 )
{
int V_115 , V_6 ;
T_1 V_281 ;
struct V_260 * V_261 = NULL , * V_297 ;
struct V_16 * V_17 ;
struct V_1 * V_298 ;
struct V_113 * V_299 ;
struct V_68 * V_300 ;
struct V_238 * V_301 ;
struct V_263 * V_264 ;
V_17 = F_78 ( sizeof( struct V_16 ) , V_205 ) ;
if ( V_17 == NULL ) {
F_8 ( & V_48 -> V_52 , L_41
L_23 ) ;
V_115 = - V_124 ;
goto V_302;
}
F_79 ( V_17 ) ;
V_298 = F_78 ( sizeof( struct V_1 ) , V_205 ) ;
if ( V_298 == NULL ) {
F_8 ( & V_48 -> V_52 , L_41
L_23 ) ;
V_115 = - V_124 ;
goto V_303;
}
V_17 -> V_19 = V_298 ;
V_115 = F_80 ( V_48 ) ;
if ( V_115 ) {
F_8 ( & V_48 -> V_52 , L_42 ) ;
goto V_304;
}
V_115 = F_81 ( V_48 , V_51 ) ;
if ( V_115 ) {
F_8 ( & V_48 -> V_52 , L_43 ) ;
goto V_130;
}
V_298 -> V_20 = F_36 ( F_82 ( V_48 , 0 ) ,
4096 ) ;
if ( ! V_298 -> V_20 ) {
F_8 ( & V_48 -> V_52 , L_44 ) ;
V_115 = - V_259 ;
goto V_131;
}
V_281 = F_7 ( V_298 -> V_20 + V_305 ) & 0x0000FFFF ;
if ( V_281 != V_306 ) {
F_8 ( & V_48 -> V_52 , L_45 ) ;
V_115 = - V_259 ;
goto V_307;
}
F_83 ( & V_298 -> V_3 ) ;
F_83 ( & V_298 -> V_14 ) ;
F_84 ( & V_298 -> V_66 ) ;
F_84 ( & V_298 -> V_185 ) ;
V_17 -> V_22 = & V_48 -> V_52 ;
strcpy ( V_17 -> V_120 , V_51 ) ;
V_115 = F_15 ( V_17 ) ;
if ( V_115 != 0 ) {
F_8 ( & V_48 -> V_52 , L_46 ) ;
goto V_308;
}
for ( V_6 = 0 ; V_6 < V_309 ; V_6 ++ ) {
V_299 = F_34 ( sizeof( struct V_113 ) ,
V_205 ) ;
if ( V_299 == NULL ) {
F_8 ( & V_48 -> V_52 , L_47
L_48 ) ;
V_115 = - V_124 ;
goto V_310;
}
V_299 -> V_22 = V_17 ;
F_85 ( & V_299 -> V_136 ) ;
V_299 -> V_311 = 0 ;
V_299 -> V_81 = V_6 ;
V_299 -> V_312 = V_82 | V_84 | V_86 |
V_93 | V_88 | V_90 ;
V_299 -> V_313 = V_170 | V_141 | V_143 |
V_104 | V_106 | V_108 | V_110 ;
V_299 -> V_314 = V_146 | V_148 | V_150 | V_152 ;
memset ( & V_299 -> V_116 , 0 ,
sizeof( struct V_121 ) ) ;
V_299 -> V_119 = NULL ;
F_51 ( & V_299 -> V_193 ,
& V_17 -> V_315 ) ;
}
for ( V_6 = 0 ; V_6 < V_316 ; V_6 ++ ) {
V_300 = F_34 ( sizeof( struct V_68 ) ,
V_205 ) ;
if ( V_300 == NULL ) {
F_8 ( & V_48 -> V_52 , L_47
L_49 ) ;
V_115 = - V_124 ;
goto V_317;
}
V_300 -> V_22 = V_17 ;
F_84 ( & V_300 -> V_241 ) ;
V_300 -> V_311 = 0 ;
V_300 -> V_81 = V_6 ;
V_300 -> V_312 = V_84 | V_86 | V_88 |
V_90 ;
if ( V_6 == 0 || V_6 == 4 )
V_300 -> V_312 |= V_82 ;
V_300 -> V_313 = V_170 | V_141 | V_143 |
V_104 | V_106 | V_108 | V_110 ;
F_51 ( & V_300 -> V_193 ,
& V_17 -> V_318 ) ;
}
for ( V_6 = 0 ; V_6 < V_319 ; V_6 ++ ) {
V_301 = F_34 ( sizeof( struct V_238 ) ,
V_205 ) ;
if ( V_301 == NULL ) {
F_8 ( & V_48 -> V_52 , L_47
L_50 ) ;
V_115 = - V_124 ;
goto V_320;
}
V_301 -> V_22 = V_17 ;
F_84 ( & V_301 -> V_241 ) ;
V_301 -> V_311 = 0 ;
V_301 -> V_81 = V_6 ;
V_301 -> V_321 = V_322 |
V_323 ;
F_86 ( & V_301 -> V_324 ) ;
F_86 ( & V_301 -> V_242 ) ;
F_51 ( & V_301 -> V_193 ,
& V_17 -> V_325 ) ;
}
V_264 = F_34 ( sizeof( struct V_263 ) , V_205 ) ;
if ( V_264 == NULL ) {
F_8 ( & V_48 -> V_52 , L_47
L_51 ) ;
V_115 = - V_124 ;
goto V_326;
}
V_264 -> V_22 = V_17 ;
F_84 ( & V_264 -> V_241 ) ;
V_264 -> V_311 = 0 ;
V_264 -> V_81 = 1 ;
V_264 -> V_268 = 4 ;
F_51 ( & V_264 -> V_193 , & V_17 -> V_327 ) ;
V_17 -> V_328 = F_29 ;
V_17 -> V_329 = F_28 ;
V_17 -> V_330 = F_42 ;
V_17 -> V_331 = F_38 ;
V_17 -> V_332 = F_43 ;
V_17 -> V_333 = F_46 ;
V_17 -> V_334 = F_49 ;
V_17 -> V_335 = F_50 ;
V_17 -> V_336 = F_55 ;
V_17 -> V_337 = F_61 ;
V_17 -> V_338 = F_22 ;
V_17 -> V_339 = F_24 ;
V_17 -> V_340 = F_63 ;
V_17 -> V_341 = F_64 ;
V_17 -> V_342 = F_65 ;
V_17 -> V_343 = F_67 ;
V_17 -> V_344 = F_68 ;
V_17 -> V_345 = F_69 ;
V_17 -> V_346 = F_71 ;
V_281 = F_7 ( V_298 -> V_20 + V_347 ) ;
F_74 ( & V_48 -> V_52 , L_52 ,
( V_281 & V_348 ) ? L_53 : L_54 ) ;
F_74 ( & V_48 -> V_52 , L_55 ,
F_68 ( V_17 ) ) ;
if ( F_73 ( V_17 , V_48 ) )
F_8 ( & V_48 -> V_52 , L_56 ) ;
V_115 = F_87 ( V_17 ) ;
if ( V_115 != 0 ) {
F_8 ( & V_48 -> V_52 , L_57 ) ;
goto V_349;
}
F_88 ( V_48 , V_17 ) ;
return 0 ;
V_349:
F_76 ( V_17 , V_48 ) ;
V_326:
F_62 (pos, n, &ca91cx42_bridge->lm_resources) {
V_264 = F_52 ( V_261 , struct V_263 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_264 ) ;
}
V_320:
F_62 (pos, n, &ca91cx42_bridge->dma_resources) {
V_301 = F_52 ( V_261 , struct V_238 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_301 ) ;
}
V_317:
F_62 (pos, n, &ca91cx42_bridge->slave_resources) {
V_300 = F_52 ( V_261 , struct V_68 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_300 ) ;
}
V_310:
F_62 (pos, n, &ca91cx42_bridge->master_resources) {
V_299 = F_52 ( V_261 , struct V_113 ,
V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_299 ) ;
}
F_18 ( V_298 , V_48 ) ;
V_308:
V_307:
F_31 ( V_298 -> V_20 ) ;
V_131:
F_89 ( V_48 ) ;
V_130:
F_90 ( V_48 ) ;
V_304:
F_32 ( V_298 ) ;
V_303:
F_32 ( V_17 ) ;
V_302:
return V_115 ;
}
static void F_91 ( struct V_47 * V_48 )
{
struct V_260 * V_261 = NULL , * V_297 ;
struct V_113 * V_299 ;
struct V_68 * V_300 ;
struct V_238 * V_301 ;
struct V_263 * V_264 ;
struct V_1 * V_2 ;
struct V_16 * V_17 = F_92 ( V_48 ) ;
V_2 = V_17 -> V_19 ;
F_14 ( 0 , V_2 -> V_20 + V_30 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_350 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_351 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_352 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_353 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_354 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_355 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_356 ) ;
F_14 ( 0x00800000 , V_2 -> V_20 + V_357 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_358 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_359 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_360 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_361 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_362 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_363 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_364 ) ;
F_14 ( 0x00F00000 , V_2 -> V_20 + V_365 ) ;
F_93 ( V_17 ) ;
F_76 ( V_17 , V_48 ) ;
F_62 (pos, n, &ca91cx42_bridge->lm_resources) {
V_264 = F_52 ( V_261 , struct V_263 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_264 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->dma_resources) {
V_301 = F_52 ( V_261 , struct V_238 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_301 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->slave_resources) {
V_300 = F_52 ( V_261 , struct V_68 , V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_300 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->master_resources) {
V_299 = F_52 ( V_261 , struct V_113 ,
V_193 ) ;
F_60 ( V_261 ) ;
F_32 ( V_299 ) ;
}
F_18 ( V_2 , V_48 ) ;
F_31 ( V_2 -> V_20 ) ;
F_89 ( V_48 ) ;
F_90 ( V_48 ) ;
F_32 ( V_17 ) ;
}
