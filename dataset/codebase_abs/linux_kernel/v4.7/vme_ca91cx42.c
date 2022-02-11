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
V_2 -> V_9 [ V_6 ] ( V_6 ) ;
V_7 |= V_8 [ V_6 ] ;
}
}
return V_7 ;
}
static T_1 F_4 ( struct V_1 * V_2 , int V_10 )
{
F_2 ( & V_2 -> V_11 ) ;
return V_12 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_13 ) ;
return V_14 ;
}
static T_1 F_6 ( struct V_15 * V_16 )
{
int V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( ! ( V_17 & 0x00000800 ) ) {
F_8 ( V_16 -> V_21 , L_1
L_2 , V_17 ) ;
}
return V_22 ;
}
static T_1 F_9 ( struct V_15 * V_16 )
{
int V_17 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( ! ( V_17 & 0x00000800 ) )
F_8 ( V_16 -> V_21 , L_3
L_2 , V_17 ) ;
return V_23 ;
}
static T_1 F_10 ( struct V_15 * V_16 ,
int V_5 )
{
int V_24 , V_6 , V_7 = 0 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
for ( V_6 = 7 ; V_6 > 0 ; V_6 -- ) {
if ( V_5 & ( 1 << V_6 ) ) {
V_24 = F_7 ( V_2 -> V_19 +
V_25 [ V_6 ] ) & 0xff ;
F_11 ( V_16 , V_6 , V_24 ) ;
V_7 |= ( 1 << V_6 ) ;
}
}
return V_7 ;
}
static T_2 F_12 ( int V_26 , void * V_27 )
{
T_1 V_5 , V_28 , V_7 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = V_27 ;
V_2 = V_16 -> V_18 ;
V_28 = F_7 ( V_2 -> V_19 + V_29 ) ;
V_5 = F_7 ( V_2 -> V_19 + V_30 ) ;
V_5 &= V_28 ;
if ( F_13 ( ! V_5 ) )
return V_31 ;
if ( V_5 & V_4 )
V_7 |= F_1 ( V_2 ) ;
if ( V_5 & ( V_32 | V_33 | V_34 |
V_35 ) )
V_7 |= F_3 ( V_2 , V_5 ) ;
if ( V_5 & V_12 )
V_7 |= F_4 ( V_2 , V_5 ) ;
if ( V_5 & V_14 )
V_7 |= F_5 ( V_2 ) ;
if ( V_5 & V_22 )
V_7 |= F_6 ( V_16 ) ;
if ( V_5 & V_23 )
V_7 |= F_9 ( V_16 ) ;
if ( V_5 & ( V_36 | V_37 |
V_38 | V_39 |
V_40 | V_41 |
V_42 ) )
V_7 |= F_10 ( V_16 , V_5 ) ;
F_14 ( V_7 , V_2 -> V_19 + V_30 ) ;
return V_43 ;
}
static int F_15 ( struct V_15 * V_16 )
{
int V_44 , V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_47 = F_16 ( V_16 -> V_21 ) ;
F_14 ( 0 , V_2 -> V_19 + V_48 ) ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_19 + V_30 ) ;
V_44 = F_17 ( V_47 -> V_26 , F_12 , V_49 ,
V_50 , V_16 ) ;
if ( V_44 ) {
F_8 ( & V_47 -> V_51 , L_4 ,
V_47 -> V_26 ) ;
return V_44 ;
}
F_14 ( 0 , V_2 -> V_19 + V_52 ) ;
F_14 ( 0 , V_2 -> V_19 + V_53 ) ;
F_14 ( 0 , V_2 -> V_19 + V_54 ) ;
V_45 = V_55 | V_56 | V_57 |
V_58 | V_14 |
V_22 | V_23 | V_4 ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 ;
F_14 ( 0 , V_2 -> V_19 + V_48 ) ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_19 + V_30 ) ;
V_16 = F_19 ( ( void * ) V_2 , struct V_15 ,
V_18 ) ;
F_20 ( V_47 -> V_26 , V_16 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_59 )
{
T_1 V_45 ;
V_45 = F_7 ( V_2 -> V_19 + V_30 ) ;
if ( V_45 & ( 1 << V_59 ) )
return 0 ;
else
return 1 ;
}
static void F_22 ( struct V_15 * V_16 , int V_59 ,
int V_60 , int V_61 )
{
struct V_46 * V_47 ;
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
if ( V_60 == 0 )
V_45 &= ~ V_62 [ V_59 ] ;
else
V_45 |= V_62 [ V_59 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
if ( ( V_60 == 0 ) && ( V_61 != 0 ) ) {
V_47 = F_16 ( V_16 -> V_21 ) ;
F_23 ( V_47 -> V_26 ) ;
}
}
static int F_24 ( struct V_15 * V_16 , int V_59 ,
int V_63 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
if ( V_63 & 1 )
return - V_64 ;
F_25 ( & V_2 -> V_65 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_48 ) ;
F_14 ( V_63 << 24 , V_2 -> V_19 + V_66 ) ;
V_45 = V_45 | ( 1 << ( V_59 + 24 ) ) ;
F_14 ( V_45 , V_2 -> V_19 + V_48 ) ;
F_26 ( V_2 -> V_13 ,
F_21 ( V_2 , V_59 ) ) ;
V_45 = F_7 ( V_2 -> V_19 + V_48 ) ;
V_45 = V_45 & ~ ( 1 << ( V_59 + 24 ) ) ;
F_14 ( V_45 , V_2 -> V_19 + V_48 ) ;
F_27 ( & V_2 -> V_65 ) ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 , int V_69 ,
unsigned long long V_70 , unsigned long long V_71 ,
T_3 V_72 , T_1 V_73 , T_1 V_74 )
{
unsigned int V_6 , V_75 = 0 , V_76 ;
unsigned int V_77 = 0 ;
unsigned int V_78 , V_79 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = V_68 -> V_21 ;
V_2 = V_16 -> V_18 ;
V_6 = V_68 -> V_80 ;
switch ( V_73 ) {
case V_81 :
V_75 |= V_82 ;
break;
case V_83 :
V_75 |= V_84 ;
break;
case V_85 :
V_75 |= V_86 ;
break;
case V_87 :
V_75 |= V_88 ;
break;
case V_89 :
V_75 |= V_90 ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
default:
F_8 ( V_16 -> V_21 , L_5 ) ;
return - V_64 ;
break;
}
V_78 = V_70 + V_71 ;
V_79 = V_72 - V_70 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_76 = 0x1000 ;
else
V_76 = 0x10000 ;
if ( V_70 & ( V_76 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_6
L_7 ) ;
return - V_64 ;
}
if ( V_78 & ( V_76 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_8
L_7 ) ;
return - V_64 ;
}
if ( V_79 & ( V_76 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_9
L_7 ) ;
return - V_64 ;
}
V_77 = F_7 ( V_2 -> V_19 + V_95 [ V_6 ] ) ;
V_77 &= ~ V_96 ;
F_14 ( V_77 , V_2 -> V_19 + V_95 [ V_6 ] ) ;
F_14 ( V_70 , V_2 -> V_19 + V_97 [ V_6 ] ) ;
F_14 ( V_78 , V_2 -> V_19 + V_98 [ V_6 ] ) ;
F_14 ( V_79 , V_2 -> V_19 + V_99 [ V_6 ] ) ;
V_77 &= ~ V_100 ;
V_77 |= V_75 ;
V_77 &= ~ ( V_101 | V_102 ) ;
if ( V_74 & V_103 )
V_77 |= V_104 ;
if ( V_74 & V_105 )
V_77 |= V_106 ;
if ( V_74 & V_107 )
V_77 |= V_108 ;
if ( V_74 & V_109 )
V_77 |= V_110 ;
F_14 ( V_77 , V_2 -> V_19 + V_95 [ V_6 ] ) ;
if ( V_69 )
V_77 |= V_96 ;
F_14 ( V_77 , V_2 -> V_19 + V_95 [ V_6 ] ) ;
return 0 ;
}
static int F_29 ( struct V_67 * V_68 , int * V_69 ,
unsigned long long * V_70 , unsigned long long * V_71 ,
T_3 * V_72 , T_1 * V_73 , T_1 * V_74 )
{
unsigned int V_6 , V_76 = 0 , V_111 = 0 ;
unsigned long long V_78 , V_79 ;
struct V_1 * V_2 ;
V_2 = V_68 -> V_21 -> V_18 ;
V_6 = V_68 -> V_80 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_76 = 0x1000 ;
else
V_76 = 0x10000 ;
V_111 = F_7 ( V_2 -> V_19 + V_95 [ V_6 ] ) ;
* V_70 = F_7 ( V_2 -> V_19 + V_97 [ V_6 ] ) ;
V_78 = F_7 ( V_2 -> V_19 + V_98 [ V_6 ] ) ;
V_79 = F_7 ( V_2 -> V_19 + V_99 [ V_6 ] ) ;
* V_72 = ( T_3 ) V_70 + V_79 ;
* V_71 = ( unsigned long long ) ( ( V_78 - * V_70 ) + V_76 ) ;
* V_69 = 0 ;
* V_73 = 0 ;
* V_74 = 0 ;
if ( V_111 & V_96 )
* V_69 = 1 ;
if ( ( V_111 & V_100 ) == V_82 )
* V_73 = V_81 ;
if ( ( V_111 & V_100 ) == V_84 )
* V_73 = V_83 ;
if ( ( V_111 & V_100 ) == V_86 )
* V_73 = V_85 ;
if ( ( V_111 & V_100 ) == V_88 )
* V_73 = V_87 ;
if ( ( V_111 & V_100 ) == V_90 )
* V_73 = V_89 ;
if ( V_111 & V_104 )
* V_74 |= V_103 ;
if ( V_111 & V_106 )
* V_74 |= V_105 ;
if ( V_111 & V_108 )
* V_74 |= V_107 ;
if ( V_111 & V_110 )
* V_74 |= V_109 ;
return 0 ;
}
static int F_30 ( struct V_112 * V_68 ,
unsigned long long V_71 )
{
unsigned long long V_113 ;
int V_114 = 0 ;
struct V_46 * V_47 ;
struct V_15 * V_16 ;
V_16 = V_68 -> V_21 ;
if ( V_16 -> V_21 == NULL ) {
F_8 ( V_16 -> V_21 , L_10 ) ;
return - V_64 ;
}
V_47 = F_16 ( V_16 -> V_21 ) ;
V_113 = ( unsigned long long ) ( V_68 -> V_115 . V_116 -
V_68 -> V_115 . V_117 ) ;
if ( V_113 == ( V_71 - 1 ) )
return 0 ;
if ( V_113 != 0 ) {
F_31 ( V_68 -> V_118 ) ;
V_68 -> V_118 = NULL ;
F_32 ( V_68 -> V_115 . V_119 ) ;
F_33 ( & V_68 -> V_115 ) ;
memset ( & V_68 -> V_115 , 0 , sizeof( struct V_120 ) ) ;
}
if ( V_68 -> V_115 . V_119 == NULL ) {
V_68 -> V_115 . V_119 = F_34 ( V_121 + 3 , V_122 ) ;
if ( V_68 -> V_115 . V_119 == NULL ) {
F_8 ( V_16 -> V_21 , L_11
L_12 ) ;
V_114 = - V_123 ;
goto V_124;
}
}
sprintf ( ( char * ) V_68 -> V_115 . V_119 , L_13 ,
V_16 -> V_119 , V_68 -> V_80 ) ;
V_68 -> V_115 . V_117 = 0 ;
V_68 -> V_115 . V_116 = ( unsigned long ) V_71 ;
V_68 -> V_115 . V_125 = V_126 ;
V_114 = F_35 ( V_47 -> V_127 ,
& V_68 -> V_115 , V_71 , 0x10000 , V_128 ,
0 , NULL , NULL ) ;
if ( V_114 ) {
F_8 ( V_16 -> V_21 , L_14
L_15 ,
V_68 -> V_80 , ( unsigned long ) V_71 ,
( unsigned long ) V_68 -> V_115 . V_117 ) ;
goto V_129;
}
V_68 -> V_118 = F_36 (
V_68 -> V_115 . V_117 , V_71 ) ;
if ( V_68 -> V_118 == NULL ) {
F_8 ( V_16 -> V_21 , L_16 ) ;
V_114 = - V_123 ;
goto V_130;
}
return 0 ;
V_130:
F_33 ( & V_68 -> V_115 ) ;
V_129:
F_32 ( V_68 -> V_115 . V_119 ) ;
memset ( & V_68 -> V_115 , 0 , sizeof( struct V_120 ) ) ;
V_124:
return V_114 ;
}
static void F_37 ( struct V_112 * V_68 )
{
F_31 ( V_68 -> V_118 ) ;
V_68 -> V_118 = NULL ;
F_33 ( & V_68 -> V_115 ) ;
F_32 ( V_68 -> V_115 . V_119 ) ;
memset ( & V_68 -> V_115 , 0 , sizeof( struct V_120 ) ) ;
}
static int F_38 ( struct V_112 * V_68 , int V_69 ,
unsigned long long V_70 , unsigned long long V_71 , T_1 V_73 ,
T_1 V_74 , T_1 V_131 )
{
int V_114 = 0 ;
unsigned int V_6 , V_76 = 0 ;
unsigned int V_77 = 0 ;
unsigned long long V_132 , V_133 , V_72 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = V_68 -> V_21 ;
V_2 = V_16 -> V_18 ;
V_6 = V_68 -> V_80 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_76 = 0x1000 ;
else
V_76 = 0x10000 ;
if ( V_70 & ( V_76 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_17
L_7 ) ;
V_114 = - V_64 ;
goto V_134;
}
if ( V_71 & ( V_76 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_17
L_7 ) ;
V_114 = - V_64 ;
goto V_134;
}
F_39 ( & V_68 -> V_135 ) ;
V_114 = F_30 ( V_68 , V_71 ) ;
if ( V_114 ) {
F_40 ( & V_68 -> V_135 ) ;
F_8 ( V_16 -> V_21 , L_18
L_19 ) ;
V_114 = - V_123 ;
goto V_136;
}
V_72 = ( unsigned long long ) V_68 -> V_115 . V_117 ;
V_132 = V_72 + V_71 ;
V_133 = V_70 - V_72 ;
V_77 = F_7 ( V_2 -> V_19 + V_137 [ V_6 ] ) ;
V_77 &= ~ V_138 ;
F_14 ( V_77 , V_2 -> V_19 + V_137 [ V_6 ] ) ;
V_77 &= ~ V_139 ;
if ( V_74 & V_140 )
V_77 |= V_141 ;
if ( V_74 & V_142 )
V_77 |= V_143 ;
V_77 &= ~ V_144 ;
switch ( V_131 ) {
case V_145 :
V_77 |= V_146 ;
break;
case V_147 :
V_77 |= V_148 ;
break;
case V_149 :
V_77 |= V_150 ;
break;
case V_151 :
V_77 |= V_152 ;
break;
default:
F_40 ( & V_68 -> V_135 ) ;
F_8 ( V_16 -> V_21 , L_20 ) ;
V_114 = - V_64 ;
goto V_153;
break;
}
V_77 &= ~ V_154 ;
switch ( V_73 ) {
case V_81 :
V_77 |= V_155 ;
break;
case V_83 :
V_77 |= V_156 ;
break;
case V_85 :
V_77 |= V_157 ;
break;
case V_92 :
V_77 |= V_158 ;
break;
case V_87 :
V_77 |= V_159 ;
break;
case V_89 :
V_77 |= V_160 ;
break;
case V_91 :
case V_93 :
case V_94 :
default:
F_40 ( & V_68 -> V_135 ) ;
F_8 ( V_16 -> V_21 , L_5 ) ;
V_114 = - V_64 ;
goto V_161;
break;
}
V_77 &= ~ ( V_162 | V_163 ) ;
if ( V_74 & V_103 )
V_77 |= V_164 ;
if ( V_74 & V_107 )
V_77 |= V_165 ;
F_14 ( V_72 , V_2 -> V_19 + V_166 [ V_6 ] ) ;
F_14 ( V_132 , V_2 -> V_19 + V_167 [ V_6 ] ) ;
F_14 ( V_133 , V_2 -> V_19 + V_168 [ V_6 ] ) ;
F_14 ( V_77 , V_2 -> V_19 + V_137 [ V_6 ] ) ;
if ( V_69 )
V_77 |= V_138 ;
F_14 ( V_77 , V_2 -> V_19 + V_137 [ V_6 ] ) ;
F_40 ( & V_68 -> V_135 ) ;
return 0 ;
V_161:
V_153:
F_37 ( V_68 ) ;
V_136:
V_134:
return V_114 ;
}
static int F_41 ( struct V_112 * V_68 ,
int * V_69 , unsigned long long * V_70 , unsigned long long * V_71 ,
T_1 * V_73 , T_1 * V_74 , T_1 * V_131 )
{
unsigned int V_6 , V_111 ;
unsigned long long V_72 , V_132 , V_133 ;
struct V_1 * V_2 ;
V_2 = V_68 -> V_21 -> V_18 ;
V_6 = V_68 -> V_80 ;
V_111 = F_7 ( V_2 -> V_19 + V_137 [ V_6 ] ) ;
V_72 = F_7 ( V_2 -> V_19 + V_166 [ V_6 ] ) ;
V_133 = F_7 ( V_2 -> V_19 + V_168 [ V_6 ] ) ;
V_132 = F_7 ( V_2 -> V_19 + V_167 [ V_6 ] ) ;
* V_70 = V_72 + V_133 ;
* V_71 = ( unsigned long long ) ( V_132 - V_72 ) ;
* V_69 = 0 ;
* V_73 = 0 ;
* V_74 = 0 ;
* V_131 = 0 ;
if ( V_111 & V_138 )
* V_69 = 1 ;
switch ( V_111 & V_154 ) {
case V_155 :
* V_73 = V_81 ;
break;
case V_156 :
* V_73 = V_83 ;
break;
case V_157 :
* V_73 = V_85 ;
break;
case V_158 :
* V_73 = V_92 ;
break;
case V_159 :
* V_73 = V_87 ;
break;
case V_160 :
* V_73 = V_89 ;
break;
}
if ( V_111 & V_141 )
* V_74 |= V_140 ;
else
* V_74 |= V_169 ;
if ( V_111 & V_164 )
* V_74 |= V_103 ;
else
* V_74 |= V_105 ;
if ( V_111 & V_165 )
* V_74 = V_107 ;
else
* V_74 = V_109 ;
switch ( V_111 & V_144 ) {
case V_146 :
* V_131 = V_145 ;
break;
case V_148 :
* V_131 = V_147 ;
break;
case V_150 :
* V_131 = V_149 ;
break;
case V_152 :
* V_131 = V_151 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_112 * V_68 , int * V_69 ,
unsigned long long * V_70 , unsigned long long * V_71 , T_1 * V_73 ,
T_1 * V_74 , T_1 * V_131 )
{
int V_114 ;
F_39 ( & V_68 -> V_135 ) ;
V_114 = F_41 ( V_68 , V_69 , V_70 , V_71 , V_73 ,
V_74 , V_131 ) ;
F_40 ( & V_68 -> V_135 ) ;
return V_114 ;
}
static T_4 F_43 ( struct V_112 * V_68 ,
void * V_170 , T_5 V_171 , T_6 V_172 )
{
T_4 V_114 ;
void T_7 * V_75 = V_68 -> V_118 + V_172 ;
unsigned int V_173 = 0 ;
unsigned int V_174 ;
if ( V_171 == 0 )
return 0 ;
F_39 ( & V_68 -> V_135 ) ;
if ( ( V_175 ) V_75 & 0x1 ) {
* ( V_176 * ) V_170 = F_44 ( V_75 ) ;
V_173 += 1 ;
if ( V_173 == V_171 )
goto V_177;
}
if ( ( V_175 ) ( V_75 + V_173 ) & 0x2 ) {
if ( ( V_171 - V_173 ) < 2 ) {
* ( V_176 * ) ( V_170 + V_173 ) = F_44 ( V_75 + V_173 ) ;
V_173 += 1 ;
goto V_177;
} else {
* ( V_178 * ) ( V_170 + V_173 ) = F_45 ( V_75 + V_173 ) ;
V_173 += 2 ;
}
}
V_174 = ( V_171 - V_173 ) & ~ 0x3 ;
while ( V_173 < V_174 ) {
* ( T_1 * ) ( V_170 + V_173 ) = F_7 ( V_75 + V_173 ) ;
V_173 += 4 ;
}
if ( ( V_171 - V_173 ) & 0x2 ) {
* ( V_178 * ) ( V_170 + V_173 ) = F_45 ( V_75 + V_173 ) ;
V_173 += 2 ;
}
if ( ( V_171 - V_173 ) & 0x1 ) {
* ( V_176 * ) ( V_170 + V_173 ) = F_44 ( V_75 + V_173 ) ;
V_173 += 1 ;
}
V_177:
V_114 = V_171 ;
F_40 ( & V_68 -> V_135 ) ;
return V_114 ;
}
static T_4 F_46 ( struct V_112 * V_68 ,
void * V_170 , T_5 V_171 , T_6 V_172 )
{
T_4 V_114 ;
void T_7 * V_75 = V_68 -> V_118 + V_172 ;
unsigned int V_173 = 0 ;
unsigned int V_174 ;
if ( V_171 == 0 )
return 0 ;
F_39 ( & V_68 -> V_135 ) ;
if ( ( V_175 ) V_75 & 0x1 ) {
F_47 ( * ( V_176 * ) V_170 , V_75 ) ;
V_173 += 1 ;
if ( V_173 == V_171 )
goto V_177;
}
if ( ( V_175 ) ( V_75 + V_173 ) & 0x2 ) {
if ( ( V_171 - V_173 ) < 2 ) {
F_47 ( * ( V_176 * ) ( V_170 + V_173 ) , V_75 + V_173 ) ;
V_173 += 1 ;
goto V_177;
} else {
F_48 ( * ( V_178 * ) ( V_170 + V_173 ) , V_75 + V_173 ) ;
V_173 += 2 ;
}
}
V_174 = ( V_171 - V_173 ) & ~ 0x3 ;
while ( V_173 < V_174 ) {
F_14 ( * ( T_1 * ) ( V_170 + V_173 ) , V_75 + V_173 ) ;
V_173 += 4 ;
}
if ( ( V_171 - V_173 ) & 0x2 ) {
F_48 ( * ( V_178 * ) ( V_170 + V_173 ) , V_75 + V_173 ) ;
V_173 += 2 ;
}
if ( ( V_171 - V_173 ) & 0x1 ) {
F_47 ( * ( V_176 * ) ( V_170 + V_173 ) , V_75 + V_173 ) ;
V_173 += 1 ;
}
V_177:
V_114 = V_171 ;
F_40 ( & V_68 -> V_135 ) ;
return V_114 ;
}
static unsigned int F_49 ( struct V_112 * V_68 ,
unsigned int V_179 , unsigned int V_180 , unsigned int V_181 ,
T_6 V_172 )
{
T_1 V_44 ;
V_175 V_182 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_183 * V_51 ;
V_2 = V_68 -> V_21 -> V_18 ;
V_51 = V_68 -> V_21 -> V_21 ;
V_6 = V_68 -> V_80 ;
F_25 ( & V_2 -> V_184 ) ;
F_39 ( & V_68 -> V_135 ) ;
V_182 = ( V_175 ) V_68 -> V_118 + V_172 ;
if ( V_182 & 0x3 ) {
F_8 ( V_51 , L_21 ) ;
V_44 = - V_64 ;
goto V_177;
}
F_14 ( 0 , V_2 -> V_19 + V_185 ) ;
F_14 ( V_179 , V_2 -> V_19 + V_186 ) ;
F_14 ( V_180 , V_2 -> V_19 + V_187 ) ;
F_14 ( V_181 , V_2 -> V_19 + V_188 ) ;
F_14 ( V_182 , V_2 -> V_19 + V_189 ) ;
F_14 ( V_190 , V_2 -> V_19 + V_185 ) ;
V_44 = F_7 ( V_68 -> V_118 + V_172 ) ;
F_14 ( 0 , V_2 -> V_19 + V_185 ) ;
V_177:
F_40 ( & V_68 -> V_135 ) ;
F_27 ( & V_2 -> V_184 ) ;
return V_44 ;
}
static int F_50 ( struct V_191 * V_192 ,
struct V_193 * V_194 , struct V_193 * V_195 , T_5 V_171 )
{
struct V_196 * V_197 , * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
T_3 V_203 ;
int V_114 = 0 ;
struct V_183 * V_51 ;
V_51 = V_192 -> V_21 -> V_21 -> V_21 ;
V_197 = F_34 ( sizeof( struct V_196 ) , V_204 ) ;
if ( V_197 == NULL ) {
F_8 ( V_51 , L_22
L_23 ) ;
V_114 = - V_123 ;
goto V_205;
}
if ( ( unsigned long ) & V_197 -> V_206 & V_207 ) {
F_8 ( V_51 , L_24
L_25 , & V_197 -> V_206 ) ;
V_114 = - V_64 ;
goto V_208;
}
memset ( & V_197 -> V_206 , 0 , sizeof( struct V_209 ) ) ;
if ( V_195 -> type == V_210 ) {
V_197 -> V_206 . V_211 |= V_212 ;
V_202 = V_195 -> V_213 ;
V_200 = V_194 -> V_213 ;
} else {
V_202 = V_194 -> V_213 ;
V_200 = V_195 -> V_213 ;
}
if ( ( V_202 -> V_73 & ~ ( V_81 | V_83 | V_85 | V_87 |
V_89 ) ) != 0 ) {
F_8 ( V_51 , L_26 ) ;
V_114 = - V_64 ;
goto V_161;
}
if ( ( V_202 -> V_74 & ~ ( V_169 | V_140 | V_103 | V_105 |
V_107 | V_109 ) ) != 0 ) {
F_8 ( V_51 , L_26 ) ;
V_114 = - V_64 ;
goto V_214;
}
if ( ! ( ( ( V_194 -> type == V_215 ) && ( V_195 -> type == V_210 ) ) ||
( ( V_194 -> type == V_210 ) && ( V_195 -> type == V_215 ) ) ) ) {
F_8 ( V_51 , L_27
L_28 ) ;
V_114 = - V_64 ;
goto V_216;
}
if ( V_202 -> V_74 & V_140 )
V_197 -> V_206 . V_211 |= V_217 ;
switch ( V_202 -> V_131 ) {
case V_145 :
V_197 -> V_206 . V_211 |= V_218 ;
break;
case V_147 :
V_197 -> V_206 . V_211 |= V_219 ;
break;
case V_149 :
V_197 -> V_206 . V_211 |= V_220 ;
break;
case V_151 :
V_197 -> V_206 . V_211 |= V_221 ;
break;
default:
F_8 ( V_51 , L_20 ) ;
return - V_64 ;
}
switch ( V_202 -> V_73 ) {
case V_81 :
V_197 -> V_206 . V_211 |= V_222 ;
break;
case V_83 :
V_197 -> V_206 . V_211 |= V_223 ;
break;
case V_85 :
V_197 -> V_206 . V_211 |= V_224 ;
break;
case V_87 :
V_197 -> V_206 . V_211 |= V_225 ;
break;
case V_89 :
V_197 -> V_206 . V_211 |= V_226 ;
break;
default:
F_8 ( V_51 , L_5 ) ;
return - V_64 ;
break;
}
if ( V_202 -> V_74 & V_103 )
V_197 -> V_206 . V_211 |= V_227 ;
if ( V_202 -> V_74 & V_107 )
V_197 -> V_206 . V_211 |= V_228 ;
V_197 -> V_206 . V_229 = V_171 ;
V_197 -> V_206 . V_230 = V_200 -> V_231 ;
V_197 -> V_206 . V_232 = V_202 -> V_231 ;
V_197 -> V_206 . V_233 = V_234 ;
F_51 ( & V_197 -> V_192 , & V_192 -> V_235 ) ;
if ( V_197 -> V_192 . V_198 != & V_192 -> V_235 ) {
V_198 = F_52 ( V_197 -> V_192 . V_198 , struct V_196 ,
V_192 ) ;
V_203 = F_53 ( & V_197 -> V_206 ) ;
V_198 -> V_206 . V_233 = V_203 & ~ V_207 ;
}
return 0 ;
V_214:
V_161:
V_216:
V_208:
F_32 ( V_197 ) ;
V_205:
return V_114 ;
}
static int F_54 ( struct V_15 * V_16 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( V_45 & V_236 )
return 0 ;
else
return 1 ;
}
static int F_55 ( struct V_191 * V_192 )
{
struct V_237 * V_238 ;
struct V_196 * V_197 ;
int V_114 ;
T_3 V_239 ;
T_1 V_17 ;
struct V_183 * V_51 ;
struct V_1 * V_2 ;
V_238 = V_192 -> V_21 ;
V_2 = V_238 -> V_21 -> V_18 ;
V_51 = V_238 -> V_21 -> V_21 ;
F_25 ( & V_238 -> V_240 ) ;
if ( ! ( F_56 ( & V_238 -> V_241 ) ) ) {
F_27 ( & V_238 -> V_240 ) ;
return - V_242 ;
} else {
F_57 ( & V_192 -> V_192 , & V_238 -> V_241 ) ;
}
V_197 = F_58 ( & V_192 -> V_235 , struct V_196 ,
V_192 ) ;
V_239 = F_53 ( & V_197 -> V_206 ) ;
F_27 ( & V_238 -> V_240 ) ;
F_14 ( 0 , V_2 -> V_19 + V_243 ) ;
F_14 ( V_239 & ~ V_207 , V_2 -> V_19 + V_244 ) ;
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
V_17 &= ( V_245 | V_246 ) ;
V_17 |= ( V_247 | V_248 | V_249 |
V_250 | V_251 | V_252 |
V_253 ) ;
F_14 ( V_17 , V_2 -> V_19 + V_20 ) ;
V_17 |= V_254 ;
F_14 ( V_17 , V_2 -> V_19 + V_20 ) ;
V_114 = F_26 ( V_2 -> V_3 ,
F_54 ( V_238 -> V_21 ) ) ;
if ( V_114 ) {
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
F_14 ( V_17 | V_255 , V_2 -> V_19 + V_20 ) ;
F_59 ( V_2 -> V_3 ,
F_54 ( V_238 -> V_21 ) ) ;
V_114 = - V_256 ;
goto exit;
}
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( V_17 & ( V_251 | V_252 |
V_253 ) ) {
F_8 ( V_51 , L_29 , V_17 ) ;
V_17 = F_7 ( V_2 -> V_19 + V_257 ) ;
V_114 = - V_258 ;
}
exit:
F_25 ( & V_238 -> V_240 ) ;
F_60 ( & V_192 -> V_192 ) ;
F_27 ( & V_238 -> V_240 ) ;
return V_114 ;
}
static int F_61 ( struct V_191 * V_192 )
{
struct V_259 * V_260 , * V_261 ;
struct V_196 * V_197 ;
F_62 (pos, temp, &list->entries) {
F_60 ( V_260 ) ;
V_197 = F_52 ( V_260 , struct V_196 , V_192 ) ;
F_32 ( V_197 ) ;
}
return 0 ;
}
static int F_63 ( struct V_262 * V_263 ,
unsigned long long V_264 , T_1 V_73 , T_1 V_74 )
{
T_1 V_265 , V_266 = 0 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_183 * V_51 ;
V_2 = V_263 -> V_21 -> V_18 ;
V_51 = V_263 -> V_21 -> V_21 ;
V_265 = ( T_1 ) V_264 ;
if ( V_265 & 0xffff ) {
F_8 ( V_51 , L_30
L_31 ) ;
return - V_64 ;
}
F_25 ( & V_263 -> V_240 ) ;
for ( V_6 = 0 ; V_6 < V_263 -> V_267 ; V_6 ++ ) {
if ( V_2 -> V_9 [ V_6 ] != NULL ) {
F_27 ( & V_263 -> V_240 ) ;
F_8 ( V_51 , L_32
L_33 ) ;
return - V_242 ;
}
}
switch ( V_73 ) {
case V_81 :
V_266 |= V_268 ;
break;
case V_83 :
V_266 |= V_269 ;
break;
case V_85 :
V_266 |= V_270 ;
break;
default:
F_27 ( & V_263 -> V_240 ) ;
F_8 ( V_51 , L_5 ) ;
return - V_64 ;
break;
}
if ( V_74 & V_103 )
V_266 |= V_271 ;
if ( V_74 & V_105 )
V_266 |= V_272 ;
if ( V_74 & V_107 )
V_266 |= V_273 ;
if ( V_74 & V_109 )
V_266 |= V_274 ;
F_14 ( V_264 , V_2 -> V_19 + V_275 ) ;
F_14 ( V_266 , V_2 -> V_19 + V_276 ) ;
F_27 ( & V_263 -> V_240 ) ;
return 0 ;
}
static int F_64 ( struct V_262 * V_263 ,
unsigned long long * V_264 , T_1 * V_73 , T_1 * V_74 )
{
T_1 V_266 , V_69 = 0 ;
struct V_1 * V_2 ;
V_2 = V_263 -> V_21 -> V_18 ;
F_25 ( & V_263 -> V_240 ) ;
* V_264 = ( unsigned long long ) F_7 ( V_2 -> V_19 + V_275 ) ;
V_266 = F_7 ( V_2 -> V_19 + V_276 ) ;
if ( V_266 & V_277 )
V_69 = 1 ;
if ( ( V_266 & V_278 ) == V_268 )
* V_73 = V_81 ;
if ( ( V_266 & V_278 ) == V_269 )
* V_73 = V_83 ;
if ( ( V_266 & V_278 ) == V_270 )
* V_73 = V_85 ;
* V_74 = 0 ;
if ( V_266 & V_271 )
* V_74 |= V_103 ;
if ( V_266 & V_272 )
* V_74 |= V_105 ;
if ( V_266 & V_273 )
* V_74 |= V_107 ;
if ( V_266 & V_274 )
* V_74 |= V_109 ;
F_27 ( & V_263 -> V_240 ) ;
return V_69 ;
}
static int F_65 ( struct V_262 * V_263 , int V_279 ,
void (* F_66)( int ) )
{
T_1 V_266 , V_45 ;
struct V_1 * V_2 ;
struct V_183 * V_51 ;
V_2 = V_263 -> V_21 -> V_18 ;
V_51 = V_263 -> V_21 -> V_21 ;
F_25 ( & V_263 -> V_240 ) ;
V_266 = F_7 ( V_2 -> V_19 + V_276 ) ;
if ( ( V_266 & ( V_273 | V_274 ) ) == 0 ) {
F_27 ( & V_263 -> V_240 ) ;
F_8 ( V_51 , L_34 ) ;
return - V_64 ;
}
if ( V_2 -> V_9 [ V_279 ] != NULL ) {
F_27 ( & V_263 -> V_240 ) ;
F_8 ( V_51 , L_35 ) ;
return - V_242 ;
}
V_2 -> V_9 [ V_279 ] = F_66 ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
V_45 |= V_8 [ V_279 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
if ( ( V_266 & V_277 ) == 0 ) {
V_266 |= V_277 ;
F_14 ( V_266 , V_2 -> V_19 + V_276 ) ;
}
F_27 ( & V_263 -> V_240 ) ;
return 0 ;
}
static int F_67 ( struct V_262 * V_263 , int V_279 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_263 -> V_21 -> V_18 ;
F_25 ( & V_263 -> V_240 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
V_45 &= ~ V_8 [ V_279 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
F_14 ( V_8 [ V_279 ] ,
V_2 -> V_19 + V_30 ) ;
V_2 -> V_9 [ V_279 ] = NULL ;
if ( ( V_45 & ( V_32 | V_33 | V_34 |
V_35 ) ) == 0 ) {
V_45 = F_7 ( V_2 -> V_19 + V_276 ) ;
V_45 &= ~ V_277 ;
F_14 ( V_45 , V_2 -> V_19 + V_276 ) ;
}
F_27 ( & V_263 -> V_240 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 )
{
T_1 V_280 = 0 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
if ( ! V_281 ) {
V_280 = F_7 ( V_2 -> V_19 + V_282 ) ;
V_280 = ( ( V_280 & V_283 ) >> 27 ) ;
} else
V_280 = V_281 ;
return ( int ) V_280 ;
}
static void * F_69 ( struct V_183 * V_21 , T_5 V_71 ,
T_3 * V_284 )
{
struct V_46 * V_47 ;
V_47 = F_16 ( V_21 ) ;
return F_70 ( V_47 , V_71 , V_284 ) ;
}
static void F_71 ( struct V_183 * V_21 , T_5 V_71 ,
void * V_285 , T_3 V_284 )
{
struct V_46 * V_47 ;
V_47 = F_16 ( V_21 ) ;
F_72 ( V_47 , V_71 , V_285 , V_284 ) ;
}
static int F_73 ( struct V_15 * V_16 ,
struct V_46 * V_47 )
{
unsigned int V_286 ;
int V_45 , V_280 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_280 = F_68 ( V_16 ) ;
if ( V_281 )
F_14 ( V_281 << 27 , V_2 -> V_19 + V_282 ) ;
F_74 ( & V_47 -> V_51 , L_36 , V_280 ) ;
if ( V_280 == 0 ) {
F_8 ( & V_47 -> V_51 , L_37
L_38 ) ;
return - V_64 ;
}
V_2 -> V_287 = F_75 ( V_47 , V_288 ,
& V_2 -> V_289 ) ;
if ( V_2 -> V_287 == NULL ) {
F_8 ( & V_47 -> V_51 , L_39
L_40 ) ;
return - V_123 ;
}
V_286 = V_280 * ( 512 * 1024 ) ;
F_14 ( V_2 -> V_289 - V_286 , V_2 -> V_19 + V_290 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_291 ) ;
V_45 |= V_292 ;
F_14 ( V_45 , V_2 -> V_19 + V_291 ) ;
return 0 ;
}
static void F_76 ( struct V_15 * V_16 ,
struct V_46 * V_47 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_291 ) ;
V_45 &= ~ V_292 ;
F_14 ( V_45 , V_2 -> V_19 + V_291 ) ;
F_14 ( 0 , V_2 -> V_19 + V_290 ) ;
F_72 ( V_47 , V_288 , V_2 -> V_287 ,
V_2 -> V_289 ) ;
}
static int F_77 ( struct V_46 * V_47 , const struct V_293 * V_294 )
{
int V_114 , V_6 ;
T_1 V_295 ;
struct V_259 * V_260 = NULL , * V_296 ;
struct V_15 * V_16 ;
struct V_1 * V_297 ;
struct V_112 * V_298 ;
struct V_67 * V_299 ;
struct V_237 * V_300 ;
struct V_262 * V_263 ;
V_16 = F_78 ( sizeof( struct V_15 ) , V_204 ) ;
if ( V_16 == NULL ) {
F_8 ( & V_47 -> V_51 , L_41
L_23 ) ;
V_114 = - V_123 ;
goto V_301;
}
F_79 ( V_16 ) ;
V_297 = F_78 ( sizeof( struct V_1 ) , V_204 ) ;
if ( V_297 == NULL ) {
F_8 ( & V_47 -> V_51 , L_41
L_23 ) ;
V_114 = - V_123 ;
goto V_302;
}
V_16 -> V_18 = V_297 ;
V_114 = F_80 ( V_47 ) ;
if ( V_114 ) {
F_8 ( & V_47 -> V_51 , L_42 ) ;
goto V_303;
}
V_114 = F_81 ( V_47 , V_50 ) ;
if ( V_114 ) {
F_8 ( & V_47 -> V_51 , L_43 ) ;
goto V_129;
}
V_297 -> V_19 = F_36 ( F_82 ( V_47 , 0 ) ,
4096 ) ;
if ( ! V_297 -> V_19 ) {
F_8 ( & V_47 -> V_51 , L_44 ) ;
V_114 = - V_258 ;
goto V_130;
}
V_295 = F_7 ( V_297 -> V_19 + V_304 ) & 0x0000FFFF ;
if ( V_295 != V_305 ) {
F_8 ( & V_47 -> V_51 , L_45 ) ;
V_114 = - V_258 ;
goto V_306;
}
F_83 ( & V_297 -> V_3 ) ;
F_83 ( & V_297 -> V_13 ) ;
F_84 ( & V_297 -> V_65 ) ;
F_84 ( & V_297 -> V_184 ) ;
V_16 -> V_21 = & V_47 -> V_51 ;
strcpy ( V_16 -> V_119 , V_50 ) ;
V_114 = F_15 ( V_16 ) ;
if ( V_114 != 0 ) {
F_8 ( & V_47 -> V_51 , L_46 ) ;
goto V_307;
}
for ( V_6 = 0 ; V_6 < V_308 ; V_6 ++ ) {
V_298 = F_34 ( sizeof( struct V_112 ) ,
V_204 ) ;
if ( V_298 == NULL ) {
F_8 ( & V_47 -> V_51 , L_47
L_48 ) ;
V_114 = - V_123 ;
goto V_309;
}
V_298 -> V_21 = V_16 ;
F_85 ( & V_298 -> V_135 ) ;
V_298 -> V_310 = 0 ;
V_298 -> V_80 = V_6 ;
V_298 -> V_311 = V_81 | V_83 | V_85 |
V_92 | V_87 | V_89 ;
V_298 -> V_312 = V_169 | V_140 | V_142 |
V_103 | V_105 | V_107 | V_109 ;
V_298 -> V_313 = V_145 | V_147 | V_149 | V_151 ;
memset ( & V_298 -> V_115 , 0 ,
sizeof( struct V_120 ) ) ;
V_298 -> V_118 = NULL ;
F_51 ( & V_298 -> V_192 ,
& V_16 -> V_314 ) ;
}
for ( V_6 = 0 ; V_6 < V_315 ; V_6 ++ ) {
V_299 = F_34 ( sizeof( struct V_67 ) ,
V_204 ) ;
if ( V_299 == NULL ) {
F_8 ( & V_47 -> V_51 , L_47
L_49 ) ;
V_114 = - V_123 ;
goto V_316;
}
V_299 -> V_21 = V_16 ;
F_84 ( & V_299 -> V_240 ) ;
V_299 -> V_310 = 0 ;
V_299 -> V_80 = V_6 ;
V_299 -> V_311 = V_83 | V_85 | V_87 |
V_89 ;
if ( V_6 == 0 || V_6 == 4 )
V_299 -> V_311 |= V_81 ;
V_299 -> V_312 = V_169 | V_140 | V_142 |
V_103 | V_105 | V_107 | V_109 ;
F_51 ( & V_299 -> V_192 ,
& V_16 -> V_317 ) ;
}
for ( V_6 = 0 ; V_6 < V_318 ; V_6 ++ ) {
V_300 = F_34 ( sizeof( struct V_237 ) ,
V_204 ) ;
if ( V_300 == NULL ) {
F_8 ( & V_47 -> V_51 , L_47
L_50 ) ;
V_114 = - V_123 ;
goto V_319;
}
V_300 -> V_21 = V_16 ;
F_84 ( & V_300 -> V_240 ) ;
V_300 -> V_310 = 0 ;
V_300 -> V_80 = V_6 ;
V_300 -> V_320 = V_321 |
V_322 ;
F_86 ( & V_300 -> V_323 ) ;
F_86 ( & V_300 -> V_241 ) ;
F_51 ( & V_300 -> V_192 ,
& V_16 -> V_324 ) ;
}
V_263 = F_34 ( sizeof( struct V_262 ) , V_204 ) ;
if ( V_263 == NULL ) {
F_8 ( & V_47 -> V_51 , L_47
L_51 ) ;
V_114 = - V_123 ;
goto V_325;
}
V_263 -> V_21 = V_16 ;
F_84 ( & V_263 -> V_240 ) ;
V_263 -> V_310 = 0 ;
V_263 -> V_80 = 1 ;
V_263 -> V_267 = 4 ;
F_51 ( & V_263 -> V_192 , & V_16 -> V_326 ) ;
V_16 -> V_327 = F_29 ;
V_16 -> V_328 = F_28 ;
V_16 -> V_329 = F_42 ;
V_16 -> V_330 = F_38 ;
V_16 -> V_331 = F_43 ;
V_16 -> V_332 = F_46 ;
V_16 -> V_333 = F_49 ;
V_16 -> V_334 = F_50 ;
V_16 -> V_335 = F_55 ;
V_16 -> V_336 = F_61 ;
V_16 -> V_337 = F_22 ;
V_16 -> V_338 = F_24 ;
V_16 -> V_339 = F_63 ;
V_16 -> V_340 = F_64 ;
V_16 -> V_341 = F_65 ;
V_16 -> V_342 = F_67 ;
V_16 -> V_343 = F_68 ;
V_16 -> V_344 = F_69 ;
V_16 -> V_345 = F_71 ;
V_295 = F_7 ( V_297 -> V_19 + V_346 ) ;
F_74 ( & V_47 -> V_51 , L_52 ,
( V_295 & V_347 ) ? L_53 : L_54 ) ;
F_74 ( & V_47 -> V_51 , L_55 ,
F_68 ( V_16 ) ) ;
if ( F_73 ( V_16 , V_47 ) )
F_8 ( & V_47 -> V_51 , L_56 ) ;
V_114 = F_87 ( V_16 ) ;
if ( V_114 != 0 ) {
F_8 ( & V_47 -> V_51 , L_57 ) ;
goto V_348;
}
F_88 ( V_47 , V_16 ) ;
return 0 ;
V_348:
F_76 ( V_16 , V_47 ) ;
V_325:
F_62 (pos, n, &ca91cx42_bridge->lm_resources) {
V_263 = F_52 ( V_260 , struct V_262 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_263 ) ;
}
V_319:
F_62 (pos, n, &ca91cx42_bridge->dma_resources) {
V_300 = F_52 ( V_260 , struct V_237 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_300 ) ;
}
V_316:
F_62 (pos, n, &ca91cx42_bridge->slave_resources) {
V_299 = F_52 ( V_260 , struct V_67 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_299 ) ;
}
V_309:
F_62 (pos, n, &ca91cx42_bridge->master_resources) {
V_298 = F_52 ( V_260 , struct V_112 ,
V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_298 ) ;
}
F_18 ( V_297 , V_47 ) ;
V_307:
V_306:
F_31 ( V_297 -> V_19 ) ;
V_130:
F_89 ( V_47 ) ;
V_129:
F_90 ( V_47 ) ;
V_303:
F_32 ( V_297 ) ;
V_302:
F_32 ( V_16 ) ;
V_301:
return V_114 ;
}
static void F_91 ( struct V_46 * V_47 )
{
struct V_259 * V_260 = NULL , * V_296 ;
struct V_112 * V_298 ;
struct V_67 * V_299 ;
struct V_237 * V_300 ;
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_15 * V_16 = F_92 ( V_47 ) ;
V_2 = V_16 -> V_18 ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_349 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_350 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_351 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_352 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_353 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_354 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_355 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_356 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_357 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_358 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_359 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_360 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_361 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_362 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_363 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_364 ) ;
F_93 ( V_16 ) ;
F_76 ( V_16 , V_47 ) ;
F_62 (pos, n, &ca91cx42_bridge->lm_resources) {
V_263 = F_52 ( V_260 , struct V_262 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_263 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->dma_resources) {
V_300 = F_52 ( V_260 , struct V_237 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_300 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->slave_resources) {
V_299 = F_52 ( V_260 , struct V_67 , V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_299 ) ;
}
F_62 (pos, n, &ca91cx42_bridge->master_resources) {
V_298 = F_52 ( V_260 , struct V_112 ,
V_192 ) ;
F_60 ( V_260 ) ;
F_32 ( V_298 ) ;
}
F_18 ( V_2 , V_47 ) ;
F_31 ( V_2 -> V_19 ) ;
F_89 ( V_47 ) ;
F_90 ( V_47 ) ;
F_32 ( V_16 ) ;
}
