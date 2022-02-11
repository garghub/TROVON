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
V_47 = F_16 ( V_16 -> V_21 , struct V_46 , V_48 ) ;
F_17 ( & V_16 -> V_49 ) ;
F_18 ( & V_16 -> V_50 ) ;
F_14 ( 0 , V_2 -> V_19 + V_51 ) ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_19 + V_30 ) ;
V_44 = F_19 ( V_47 -> V_26 , F_12 , V_52 ,
V_53 , V_16 ) ;
if ( V_44 ) {
F_8 ( & V_47 -> V_48 , L_4 ,
V_47 -> V_26 ) ;
return V_44 ;
}
F_14 ( 0 , V_2 -> V_19 + V_54 ) ;
F_14 ( 0 , V_2 -> V_19 + V_55 ) ;
F_14 ( 0 , V_2 -> V_19 + V_56 ) ;
V_45 = V_57 | V_58 | V_59 |
V_60 | V_14 |
V_22 | V_23 | V_4 ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 ;
F_14 ( 0 , V_2 -> V_19 + V_51 ) ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00FFFFFF , V_2 -> V_19 + V_30 ) ;
V_16 = F_16 ( ( void * ) V_2 , struct V_15 ,
V_18 ) ;
F_21 ( V_47 -> V_26 , V_16 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_61 )
{
T_1 V_45 ;
V_45 = F_7 ( V_2 -> V_19 + V_30 ) ;
if ( V_45 & ( 1 << V_61 ) )
return 0 ;
else
return 1 ;
}
static void F_23 ( struct V_15 * V_16 , int V_61 ,
int V_62 , int V_63 )
{
struct V_46 * V_47 ;
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
if ( V_62 == 0 )
V_45 &= ~ V_64 [ V_61 ] ;
else
V_45 |= V_64 [ V_61 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
if ( ( V_62 == 0 ) && ( V_63 != 0 ) ) {
V_47 = F_16 ( V_16 -> V_21 , struct V_46 ,
V_48 ) ;
F_24 ( V_47 -> V_26 ) ;
}
}
static int F_25 ( struct V_15 * V_16 , int V_61 ,
int V_65 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
if ( V_65 & 1 )
return - V_66 ;
F_26 ( & V_2 -> V_67 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_51 ) ;
F_14 ( V_65 << 24 , V_2 -> V_19 + V_68 ) ;
V_45 = V_45 | ( 1 << ( V_61 + 24 ) ) ;
F_14 ( V_45 , V_2 -> V_19 + V_51 ) ;
F_27 ( V_2 -> V_13 ,
F_22 ( V_2 , V_61 ) ) ;
V_45 = F_7 ( V_2 -> V_19 + V_51 ) ;
V_45 = V_45 & ~ ( 1 << ( V_61 + 24 ) ) ;
F_14 ( V_45 , V_2 -> V_19 + V_51 ) ;
F_28 ( & V_2 -> V_67 ) ;
return 0 ;
}
static int F_29 ( struct V_69 * V_70 , int V_71 ,
unsigned long long V_72 , unsigned long long V_73 ,
T_3 V_74 , T_1 V_75 , T_1 V_76 )
{
unsigned int V_6 , V_77 = 0 , V_78 ;
unsigned int V_79 = 0 ;
unsigned int V_80 , V_81 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = V_70 -> V_21 ;
V_2 = V_16 -> V_18 ;
V_6 = V_70 -> V_82 ;
switch ( V_75 ) {
case V_83 :
V_77 |= V_84 ;
break;
case V_85 :
V_77 |= V_86 ;
break;
case V_87 :
V_77 |= V_88 ;
break;
case V_89 :
V_77 |= V_90 ;
break;
case V_91 :
V_77 |= V_92 ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
default:
F_8 ( V_16 -> V_21 , L_5 ) ;
return - V_66 ;
break;
}
V_80 = V_72 + V_73 ;
V_81 = V_74 - V_72 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_78 = 0x1000 ;
else
V_78 = 0x10000 ;
if ( V_72 & ( V_78 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_6
L_7 ) ;
return - V_66 ;
}
if ( V_80 & ( V_78 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_8
L_7 ) ;
return - V_66 ;
}
if ( V_81 & ( V_78 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_9
L_7 ) ;
return - V_66 ;
}
V_79 = F_7 ( V_2 -> V_19 + V_97 [ V_6 ] ) ;
V_79 &= ~ V_98 ;
F_14 ( V_79 , V_2 -> V_19 + V_97 [ V_6 ] ) ;
F_14 ( V_72 , V_2 -> V_19 + V_99 [ V_6 ] ) ;
F_14 ( V_80 , V_2 -> V_19 + V_100 [ V_6 ] ) ;
F_14 ( V_81 , V_2 -> V_19 + V_101 [ V_6 ] ) ;
V_79 &= ~ V_102 ;
V_79 |= V_77 ;
V_79 &= ~ ( V_103 | V_104 ) ;
if ( V_76 & V_105 )
V_79 |= V_106 ;
if ( V_76 & V_107 )
V_79 |= V_108 ;
if ( V_76 & V_109 )
V_79 |= V_110 ;
if ( V_76 & V_111 )
V_79 |= V_112 ;
F_14 ( V_79 , V_2 -> V_19 + V_97 [ V_6 ] ) ;
if ( V_71 )
V_79 |= V_98 ;
F_14 ( V_79 , V_2 -> V_19 + V_97 [ V_6 ] ) ;
return 0 ;
}
static int F_30 ( struct V_69 * V_70 , int * V_71 ,
unsigned long long * V_72 , unsigned long long * V_73 ,
T_3 * V_74 , T_1 * V_75 , T_1 * V_76 )
{
unsigned int V_6 , V_78 = 0 , V_113 = 0 ;
unsigned long long V_80 , V_81 ;
struct V_1 * V_2 ;
V_2 = V_70 -> V_21 -> V_18 ;
V_6 = V_70 -> V_82 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_78 = 0x1000 ;
else
V_78 = 0x10000 ;
V_113 = F_7 ( V_2 -> V_19 + V_97 [ V_6 ] ) ;
* V_72 = F_7 ( V_2 -> V_19 + V_99 [ V_6 ] ) ;
V_80 = F_7 ( V_2 -> V_19 + V_100 [ V_6 ] ) ;
V_81 = F_7 ( V_2 -> V_19 + V_101 [ V_6 ] ) ;
* V_74 = ( T_3 ) V_72 + V_81 ;
* V_73 = ( unsigned long long ) ( ( V_80 - * V_72 ) + V_78 ) ;
* V_71 = 0 ;
* V_75 = 0 ;
* V_76 = 0 ;
if ( V_113 & V_98 )
* V_71 = 1 ;
if ( ( V_113 & V_102 ) == V_84 )
* V_75 = V_83 ;
if ( ( V_113 & V_102 ) == V_86 )
* V_75 = V_85 ;
if ( ( V_113 & V_102 ) == V_88 )
* V_75 = V_87 ;
if ( ( V_113 & V_102 ) == V_90 )
* V_75 = V_89 ;
if ( ( V_113 & V_102 ) == V_92 )
* V_75 = V_91 ;
if ( V_113 & V_106 )
* V_76 |= V_105 ;
if ( V_113 & V_108 )
* V_76 |= V_107 ;
if ( V_113 & V_110 )
* V_76 |= V_109 ;
if ( V_113 & V_112 )
* V_76 |= V_111 ;
return 0 ;
}
static int F_31 ( struct V_114 * V_70 ,
unsigned long long V_73 )
{
unsigned long long V_115 ;
int V_116 = 0 ;
struct V_46 * V_47 ;
struct V_15 * V_16 ;
V_16 = V_70 -> V_21 ;
if ( V_16 -> V_21 == NULL ) {
F_8 ( V_16 -> V_21 , L_10 ) ;
return - V_66 ;
}
V_47 = F_16 ( V_16 -> V_21 , struct V_46 , V_48 ) ;
V_115 = ( unsigned long long ) ( V_70 -> V_117 . V_118 -
V_70 -> V_117 . V_119 ) ;
if ( V_115 == ( V_73 - 1 ) )
return 0 ;
if ( V_115 != 0 ) {
F_32 ( V_70 -> V_120 ) ;
V_70 -> V_120 = NULL ;
F_33 ( V_70 -> V_117 . V_121 ) ;
F_34 ( & V_70 -> V_117 ) ;
memset ( & V_70 -> V_117 , 0 , sizeof( struct V_122 ) ) ;
}
if ( V_70 -> V_117 . V_121 == NULL ) {
V_70 -> V_117 . V_121 = F_35 ( V_123 + 3 , V_124 ) ;
if ( V_70 -> V_117 . V_121 == NULL ) {
F_8 ( V_16 -> V_21 , L_11
L_12 ) ;
V_116 = - V_125 ;
goto V_126;
}
}
sprintf ( ( char * ) V_70 -> V_117 . V_121 , L_13 ,
V_16 -> V_121 , V_70 -> V_82 ) ;
V_70 -> V_117 . V_119 = 0 ;
V_70 -> V_117 . V_118 = ( unsigned long ) V_73 ;
V_70 -> V_117 . V_127 = V_128 ;
V_116 = F_36 ( V_47 -> V_129 ,
& V_70 -> V_117 , V_73 , V_73 , V_130 ,
0 , NULL , NULL ) ;
if ( V_116 ) {
F_8 ( V_16 -> V_21 , L_14
L_15 ,
V_70 -> V_82 , ( unsigned long ) V_73 ,
( unsigned long ) V_70 -> V_117 . V_119 ) ;
goto V_131;
}
V_70 -> V_120 = F_37 (
V_70 -> V_117 . V_119 , V_73 ) ;
if ( V_70 -> V_120 == NULL ) {
F_8 ( V_16 -> V_21 , L_16 ) ;
V_116 = - V_125 ;
goto V_132;
}
return 0 ;
V_132:
F_34 ( & V_70 -> V_117 ) ;
V_131:
F_33 ( V_70 -> V_117 . V_121 ) ;
memset ( & V_70 -> V_117 , 0 , sizeof( struct V_122 ) ) ;
V_126:
return V_116 ;
}
static void F_38 ( struct V_114 * V_70 )
{
F_32 ( V_70 -> V_120 ) ;
V_70 -> V_120 = NULL ;
F_34 ( & V_70 -> V_117 ) ;
F_33 ( V_70 -> V_117 . V_121 ) ;
memset ( & V_70 -> V_117 , 0 , sizeof( struct V_122 ) ) ;
}
static int F_39 ( struct V_114 * V_70 , int V_71 ,
unsigned long long V_72 , unsigned long long V_73 , T_1 V_75 ,
T_1 V_76 , T_1 V_133 )
{
int V_116 = 0 ;
unsigned int V_6 , V_78 = 0 ;
unsigned int V_79 = 0 ;
unsigned long long V_134 , V_135 , V_74 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = V_70 -> V_21 ;
V_2 = V_16 -> V_18 ;
V_6 = V_70 -> V_82 ;
if ( ( V_6 == 0 ) || ( V_6 == 4 ) )
V_78 = 0x1000 ;
else
V_78 = 0x10000 ;
if ( V_72 & ( V_78 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_17
L_7 ) ;
V_116 = - V_66 ;
goto V_136;
}
if ( V_73 & ( V_78 - 1 ) ) {
F_8 ( V_16 -> V_21 , L_17
L_7 ) ;
V_116 = - V_66 ;
goto V_136;
}
F_40 ( & V_70 -> V_137 ) ;
V_116 = F_31 ( V_70 , V_73 ) ;
if ( V_116 ) {
F_41 ( & V_70 -> V_137 ) ;
F_8 ( V_16 -> V_21 , L_18
L_19 ) ;
V_116 = - V_125 ;
goto V_138;
}
V_74 = ( unsigned long long ) V_70 -> V_117 . V_119 ;
V_134 = V_74 + V_73 ;
V_135 = V_72 - V_74 ;
V_79 = F_7 ( V_2 -> V_19 + V_139 [ V_6 ] ) ;
V_79 &= ~ V_140 ;
F_14 ( V_79 , V_2 -> V_19 + V_139 [ V_6 ] ) ;
V_79 &= ~ V_141 ;
if ( V_76 & V_142 )
V_79 |= V_143 ;
if ( V_76 & V_144 )
V_79 |= V_145 ;
V_79 &= ~ V_146 ;
switch ( V_133 ) {
case V_147 :
V_79 |= V_148 ;
break;
case V_149 :
V_79 |= V_150 ;
break;
case V_151 :
V_79 |= V_152 ;
break;
case V_153 :
V_79 |= V_154 ;
break;
default:
F_41 ( & V_70 -> V_137 ) ;
F_8 ( V_16 -> V_21 , L_20 ) ;
V_116 = - V_66 ;
goto V_155;
break;
}
V_79 &= ~ V_156 ;
switch ( V_75 ) {
case V_83 :
V_79 |= V_157 ;
break;
case V_85 :
V_79 |= V_158 ;
break;
case V_87 :
V_79 |= V_159 ;
break;
case V_94 :
V_79 |= V_160 ;
break;
case V_89 :
V_79 |= V_161 ;
break;
case V_91 :
V_79 |= V_162 ;
break;
case V_93 :
case V_95 :
case V_96 :
default:
F_41 ( & V_70 -> V_137 ) ;
F_8 ( V_16 -> V_21 , L_5 ) ;
V_116 = - V_66 ;
goto V_163;
break;
}
V_79 &= ~ ( V_164 | V_165 ) ;
if ( V_76 & V_105 )
V_79 |= V_166 ;
if ( V_76 & V_109 )
V_79 |= V_167 ;
F_14 ( V_74 , V_2 -> V_19 + V_168 [ V_6 ] ) ;
F_14 ( V_134 , V_2 -> V_19 + V_169 [ V_6 ] ) ;
F_14 ( V_135 , V_2 -> V_19 + V_170 [ V_6 ] ) ;
F_14 ( V_79 , V_2 -> V_19 + V_139 [ V_6 ] ) ;
if ( V_71 )
V_79 |= V_140 ;
F_14 ( V_79 , V_2 -> V_19 + V_139 [ V_6 ] ) ;
F_41 ( & V_70 -> V_137 ) ;
return 0 ;
V_163:
V_155:
F_38 ( V_70 ) ;
V_138:
V_136:
return V_116 ;
}
static int F_42 ( struct V_114 * V_70 ,
int * V_71 , unsigned long long * V_72 , unsigned long long * V_73 ,
T_1 * V_75 , T_1 * V_76 , T_1 * V_133 )
{
unsigned int V_6 , V_113 ;
unsigned long long V_74 , V_134 , V_135 ;
struct V_1 * V_2 ;
V_2 = V_70 -> V_21 -> V_18 ;
V_6 = V_70 -> V_82 ;
V_113 = F_7 ( V_2 -> V_19 + V_139 [ V_6 ] ) ;
V_74 = F_7 ( V_2 -> V_19 + V_168 [ V_6 ] ) ;
V_135 = F_7 ( V_2 -> V_19 + V_170 [ V_6 ] ) ;
V_134 = F_7 ( V_2 -> V_19 + V_169 [ V_6 ] ) ;
* V_72 = V_74 + V_135 ;
* V_73 = ( unsigned long long ) ( V_134 - V_74 ) ;
* V_71 = 0 ;
* V_75 = 0 ;
* V_76 = 0 ;
* V_133 = 0 ;
if ( V_113 & V_140 )
* V_71 = 1 ;
switch ( V_113 & V_156 ) {
case V_157 :
* V_75 = V_83 ;
break;
case V_158 :
* V_75 = V_85 ;
break;
case V_159 :
* V_75 = V_87 ;
break;
case V_160 :
* V_75 = V_94 ;
break;
case V_161 :
* V_75 = V_89 ;
break;
case V_162 :
* V_75 = V_91 ;
break;
}
if ( V_113 & V_143 )
* V_76 |= V_142 ;
else
* V_76 |= V_171 ;
if ( V_113 & V_166 )
* V_76 |= V_105 ;
else
* V_76 |= V_107 ;
if ( V_113 & V_167 )
* V_76 = V_109 ;
else
* V_76 = V_111 ;
switch ( V_113 & V_146 ) {
case V_148 :
* V_133 = V_147 ;
break;
case V_150 :
* V_133 = V_149 ;
break;
case V_152 :
* V_133 = V_151 ;
break;
case V_154 :
* V_133 = V_153 ;
break;
}
return 0 ;
}
static int F_43 ( struct V_114 * V_70 , int * V_71 ,
unsigned long long * V_72 , unsigned long long * V_73 , T_1 * V_75 ,
T_1 * V_76 , T_1 * V_133 )
{
int V_116 ;
F_40 ( & V_70 -> V_137 ) ;
V_116 = F_42 ( V_70 , V_71 , V_72 , V_73 , V_75 ,
V_76 , V_133 ) ;
F_41 ( & V_70 -> V_137 ) ;
return V_116 ;
}
static T_4 F_44 ( struct V_114 * V_70 ,
void * V_172 , T_5 V_173 , T_6 V_174 )
{
T_4 V_116 ;
void T_7 * V_77 = V_70 -> V_120 + V_174 ;
unsigned int V_175 = 0 ;
unsigned int V_176 ;
if ( V_173 == 0 )
return 0 ;
F_40 ( & V_70 -> V_137 ) ;
if ( ( V_177 ) V_77 & 0x1 ) {
* ( V_178 * ) V_172 = F_45 ( V_77 ) ;
V_175 += 1 ;
if ( V_175 == V_173 )
goto V_179;
}
if ( ( V_177 ) ( V_77 + V_175 ) & 0x2 ) {
if ( ( V_173 - V_175 ) < 2 ) {
* ( V_178 * ) ( V_172 + V_175 ) = F_45 ( V_77 + V_175 ) ;
V_175 += 1 ;
goto V_179;
} else {
* ( V_180 * ) ( V_172 + V_175 ) = F_46 ( V_77 + V_175 ) ;
V_175 += 2 ;
}
}
V_176 = ( V_173 - V_175 ) & ~ 0x3 ;
while ( V_175 < V_176 ) {
* ( T_1 * ) ( V_172 + V_175 ) = F_7 ( V_77 + V_175 ) ;
V_175 += 4 ;
}
if ( ( V_173 - V_175 ) & 0x2 ) {
* ( V_180 * ) ( V_172 + V_175 ) = F_46 ( V_77 + V_175 ) ;
V_175 += 2 ;
}
if ( ( V_173 - V_175 ) & 0x1 ) {
* ( V_178 * ) ( V_172 + V_175 ) = F_45 ( V_77 + V_175 ) ;
V_175 += 1 ;
}
V_179:
V_116 = V_173 ;
F_41 ( & V_70 -> V_137 ) ;
return V_116 ;
}
static T_4 F_47 ( struct V_114 * V_70 ,
void * V_172 , T_5 V_173 , T_6 V_174 )
{
T_4 V_116 ;
void T_7 * V_77 = V_70 -> V_120 + V_174 ;
unsigned int V_175 = 0 ;
unsigned int V_176 ;
if ( V_173 == 0 )
return 0 ;
F_40 ( & V_70 -> V_137 ) ;
if ( ( V_177 ) V_77 & 0x1 ) {
F_48 ( * ( V_178 * ) V_172 , V_77 ) ;
V_175 += 1 ;
if ( V_175 == V_173 )
goto V_179;
}
if ( ( V_177 ) ( V_77 + V_175 ) & 0x2 ) {
if ( ( V_173 - V_175 ) < 2 ) {
F_48 ( * ( V_178 * ) ( V_172 + V_175 ) , V_77 + V_175 ) ;
V_175 += 1 ;
goto V_179;
} else {
F_49 ( * ( V_180 * ) ( V_172 + V_175 ) , V_77 + V_175 ) ;
V_175 += 2 ;
}
}
V_176 = ( V_173 - V_175 ) & ~ 0x3 ;
while ( V_175 < V_176 ) {
F_14 ( * ( T_1 * ) ( V_172 + V_175 ) , V_77 + V_175 ) ;
V_175 += 4 ;
}
if ( ( V_173 - V_175 ) & 0x2 ) {
F_49 ( * ( V_180 * ) ( V_172 + V_175 ) , V_77 + V_175 ) ;
V_175 += 2 ;
}
if ( ( V_173 - V_175 ) & 0x1 ) {
F_48 ( * ( V_178 * ) ( V_172 + V_175 ) , V_77 + V_175 ) ;
V_175 += 1 ;
}
V_179:
V_116 = V_173 ;
F_41 ( & V_70 -> V_137 ) ;
return V_116 ;
}
static unsigned int F_50 ( struct V_114 * V_70 ,
unsigned int V_181 , unsigned int V_182 , unsigned int V_183 ,
T_6 V_174 )
{
T_1 V_44 ;
V_177 V_184 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_185 * V_48 ;
V_2 = V_70 -> V_21 -> V_18 ;
V_48 = V_70 -> V_21 -> V_21 ;
V_6 = V_70 -> V_82 ;
F_26 ( & V_2 -> V_186 ) ;
F_40 ( & V_70 -> V_137 ) ;
V_184 = ( V_177 ) V_70 -> V_120 + V_174 ;
if ( V_184 & 0x3 ) {
F_8 ( V_48 , L_21 ) ;
V_44 = - V_66 ;
goto V_179;
}
F_14 ( 0 , V_2 -> V_19 + V_187 ) ;
F_14 ( V_181 , V_2 -> V_19 + V_188 ) ;
F_14 ( V_182 , V_2 -> V_19 + V_189 ) ;
F_14 ( V_183 , V_2 -> V_19 + V_190 ) ;
F_14 ( V_184 , V_2 -> V_19 + V_191 ) ;
F_14 ( V_192 , V_2 -> V_19 + V_187 ) ;
V_44 = F_7 ( V_70 -> V_120 + V_174 ) ;
F_14 ( 0 , V_2 -> V_19 + V_187 ) ;
V_179:
F_41 ( & V_70 -> V_137 ) ;
F_28 ( & V_2 -> V_186 ) ;
return V_44 ;
}
static int F_51 ( struct V_193 * V_194 ,
struct V_195 * V_196 , struct V_195 * V_197 , T_5 V_173 )
{
struct V_198 * V_199 , * V_200 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
T_3 V_205 ;
int V_116 = 0 ;
struct V_185 * V_48 ;
V_48 = V_194 -> V_21 -> V_21 -> V_21 ;
V_199 = F_35 ( sizeof( struct V_198 ) , V_206 ) ;
if ( V_199 == NULL ) {
F_8 ( V_48 , L_22
L_23 ) ;
V_116 = - V_125 ;
goto V_207;
}
if ( ( unsigned long ) & V_199 -> V_208 & V_209 ) {
F_8 ( V_48 , L_24
L_25 , & V_199 -> V_208 ) ;
V_116 = - V_66 ;
goto V_210;
}
memset ( & V_199 -> V_208 , 0 , sizeof( struct V_211 ) ) ;
if ( V_197 -> type == V_212 ) {
V_199 -> V_208 . V_213 |= V_214 ;
V_204 = V_197 -> V_215 ;
V_202 = V_196 -> V_215 ;
} else {
V_204 = V_196 -> V_215 ;
V_202 = V_197 -> V_215 ;
}
if ( ( V_204 -> V_75 & ~ ( V_83 | V_85 | V_87 | V_89 |
V_91 ) ) != 0 ) {
F_8 ( V_48 , L_26 ) ;
V_116 = - V_66 ;
goto V_163;
}
if ( ( V_204 -> V_76 & ~ ( V_171 | V_142 | V_105 | V_107 |
V_109 | V_111 ) ) != 0 ) {
F_8 ( V_48 , L_26 ) ;
V_116 = - V_66 ;
goto V_216;
}
if ( ! ( ( ( V_196 -> type == V_217 ) && ( V_197 -> type == V_212 ) ) ||
( ( V_196 -> type == V_212 ) && ( V_197 -> type == V_217 ) ) ) ) {
F_8 ( V_48 , L_27
L_28 ) ;
V_116 = - V_66 ;
goto V_218;
}
if ( V_204 -> V_76 & V_142 )
V_199 -> V_208 . V_213 |= V_219 ;
switch ( V_204 -> V_133 ) {
case V_147 :
V_199 -> V_208 . V_213 |= V_220 ;
break;
case V_149 :
V_199 -> V_208 . V_213 |= V_221 ;
break;
case V_151 :
V_199 -> V_208 . V_213 |= V_222 ;
break;
case V_153 :
V_199 -> V_208 . V_213 |= V_223 ;
break;
default:
F_8 ( V_48 , L_20 ) ;
return - V_66 ;
}
switch ( V_204 -> V_75 ) {
case V_83 :
V_199 -> V_208 . V_213 |= V_224 ;
break;
case V_85 :
V_199 -> V_208 . V_213 |= V_225 ;
break;
case V_87 :
V_199 -> V_208 . V_213 |= V_226 ;
break;
case V_89 :
V_199 -> V_208 . V_213 |= V_227 ;
break;
case V_91 :
V_199 -> V_208 . V_213 |= V_228 ;
break;
default:
F_8 ( V_48 , L_5 ) ;
return - V_66 ;
break;
}
if ( V_204 -> V_76 & V_105 )
V_199 -> V_208 . V_213 |= V_229 ;
if ( V_204 -> V_76 & V_109 )
V_199 -> V_208 . V_213 |= V_230 ;
V_199 -> V_208 . V_231 = V_173 ;
V_199 -> V_208 . V_232 = V_202 -> V_233 ;
V_199 -> V_208 . V_234 = V_204 -> V_233 ;
V_199 -> V_208 . V_235 = V_236 ;
F_52 ( & V_199 -> V_194 , & V_194 -> V_237 ) ;
if ( V_199 -> V_194 . V_200 != & V_194 -> V_237 ) {
V_200 = F_53 ( V_199 -> V_194 . V_200 , struct V_198 ,
V_194 ) ;
V_205 = F_54 ( & V_199 -> V_208 ) ;
V_200 -> V_208 . V_235 = V_205 & ~ V_209 ;
}
return 0 ;
V_216:
V_163:
V_218:
V_210:
F_33 ( V_199 ) ;
V_207:
return V_116 ;
}
static int F_55 ( struct V_15 * V_16 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( V_45 & V_238 )
return 0 ;
else
return 1 ;
}
static int F_56 ( struct V_193 * V_194 )
{
struct V_239 * V_240 ;
struct V_198 * V_199 ;
int V_116 ;
T_3 V_241 ;
T_1 V_17 ;
struct V_185 * V_48 ;
struct V_1 * V_2 ;
V_240 = V_194 -> V_21 ;
V_2 = V_240 -> V_21 -> V_18 ;
V_48 = V_240 -> V_21 -> V_21 ;
F_26 ( & V_240 -> V_242 ) ;
if ( ! ( F_57 ( & V_240 -> V_243 ) ) ) {
F_28 ( & V_240 -> V_242 ) ;
return - V_244 ;
} else {
F_58 ( & V_194 -> V_194 , & V_240 -> V_243 ) ;
}
V_199 = F_59 ( & V_194 -> V_237 , struct V_198 ,
V_194 ) ;
V_241 = F_54 ( & V_199 -> V_208 ) ;
F_28 ( & V_240 -> V_242 ) ;
F_14 ( 0 , V_2 -> V_19 + V_245 ) ;
F_14 ( V_241 & ~ V_209 , V_2 -> V_19 + V_246 ) ;
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
V_17 &= ( V_247 | V_248 ) ;
V_17 |= ( V_249 | V_250 | V_251 |
V_252 | V_253 | V_254 |
V_255 ) ;
F_14 ( V_17 , V_2 -> V_19 + V_20 ) ;
V_17 |= V_256 ;
F_14 ( V_17 , V_2 -> V_19 + V_20 ) ;
V_116 = F_27 ( V_2 -> V_3 ,
F_55 ( V_240 -> V_21 ) ) ;
if ( V_116 ) {
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
F_14 ( V_17 | V_257 , V_2 -> V_19 + V_20 ) ;
F_60 ( V_2 -> V_3 ,
F_55 ( V_240 -> V_21 ) ) ;
V_116 = - V_258 ;
goto exit;
}
V_17 = F_7 ( V_2 -> V_19 + V_20 ) ;
if ( V_17 & ( V_253 | V_254 |
V_255 ) ) {
F_8 ( V_48 , L_29 , V_17 ) ;
V_17 = F_7 ( V_2 -> V_19 + V_259 ) ;
V_116 = - V_260 ;
}
exit:
F_26 ( & V_240 -> V_242 ) ;
F_61 ( & V_194 -> V_194 ) ;
F_28 ( & V_240 -> V_242 ) ;
return V_116 ;
}
static int F_62 ( struct V_193 * V_194 )
{
struct V_261 * V_262 , * V_263 ;
struct V_198 * V_199 ;
F_63 (pos, temp, &list->entries) {
F_61 ( V_262 ) ;
V_199 = F_53 ( V_262 , struct V_198 , V_194 ) ;
F_33 ( V_199 ) ;
}
return 0 ;
}
static int F_64 ( struct V_264 * V_265 ,
unsigned long long V_266 , T_1 V_75 , T_1 V_76 )
{
T_1 V_267 , V_268 = 0 ;
int V_6 ;
struct V_1 * V_2 ;
struct V_185 * V_48 ;
V_2 = V_265 -> V_21 -> V_18 ;
V_48 = V_265 -> V_21 -> V_21 ;
V_267 = ( T_1 ) V_266 ;
if ( V_267 & 0xffff ) {
F_8 ( V_48 , L_30
L_31 ) ;
return - V_66 ;
}
F_26 ( & V_265 -> V_242 ) ;
for ( V_6 = 0 ; V_6 < V_265 -> V_269 ; V_6 ++ ) {
if ( V_2 -> V_9 [ V_6 ] != NULL ) {
F_28 ( & V_265 -> V_242 ) ;
F_8 ( V_48 , L_32
L_33 ) ;
return - V_244 ;
}
}
switch ( V_75 ) {
case V_83 :
V_268 |= V_270 ;
break;
case V_85 :
V_268 |= V_271 ;
break;
case V_87 :
V_268 |= V_272 ;
break;
default:
F_28 ( & V_265 -> V_242 ) ;
F_8 ( V_48 , L_5 ) ;
return - V_66 ;
break;
}
if ( V_76 & V_105 )
V_268 |= V_273 ;
if ( V_76 & V_107 )
V_268 |= V_274 ;
if ( V_76 & V_109 )
V_268 |= V_275 ;
if ( V_76 & V_111 )
V_268 |= V_276 ;
F_14 ( V_266 , V_2 -> V_19 + V_277 ) ;
F_14 ( V_268 , V_2 -> V_19 + V_278 ) ;
F_28 ( & V_265 -> V_242 ) ;
return 0 ;
}
static int F_65 ( struct V_264 * V_265 ,
unsigned long long * V_266 , T_1 * V_75 , T_1 * V_76 )
{
T_1 V_268 , V_71 = 0 ;
struct V_1 * V_2 ;
V_2 = V_265 -> V_21 -> V_18 ;
F_26 ( & V_265 -> V_242 ) ;
* V_266 = ( unsigned long long ) F_7 ( V_2 -> V_19 + V_277 ) ;
V_268 = F_7 ( V_2 -> V_19 + V_278 ) ;
if ( V_268 & V_279 )
V_71 = 1 ;
if ( ( V_268 & V_280 ) == V_270 )
* V_75 = V_83 ;
if ( ( V_268 & V_280 ) == V_271 )
* V_75 = V_85 ;
if ( ( V_268 & V_280 ) == V_272 )
* V_75 = V_87 ;
* V_76 = 0 ;
if ( V_268 & V_273 )
* V_76 |= V_105 ;
if ( V_268 & V_274 )
* V_76 |= V_107 ;
if ( V_268 & V_275 )
* V_76 |= V_109 ;
if ( V_268 & V_276 )
* V_76 |= V_111 ;
F_28 ( & V_265 -> V_242 ) ;
return V_71 ;
}
static int F_66 ( struct V_264 * V_265 , int V_281 ,
void (* F_67)( int ) )
{
T_1 V_268 , V_45 ;
struct V_1 * V_2 ;
struct V_185 * V_48 ;
V_2 = V_265 -> V_21 -> V_18 ;
V_48 = V_265 -> V_21 -> V_21 ;
F_26 ( & V_265 -> V_242 ) ;
V_268 = F_7 ( V_2 -> V_19 + V_278 ) ;
if ( ( V_268 & ( V_275 | V_276 ) ) == 0 ) {
F_28 ( & V_265 -> V_242 ) ;
F_8 ( V_48 , L_34 ) ;
return - V_66 ;
}
if ( V_2 -> V_9 [ V_281 ] != NULL ) {
F_28 ( & V_265 -> V_242 ) ;
F_8 ( V_48 , L_35 ) ;
return - V_244 ;
}
V_2 -> V_9 [ V_281 ] = F_67 ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
V_45 |= V_8 [ V_281 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
if ( ( V_268 & V_279 ) == 0 ) {
V_268 |= V_279 ;
F_14 ( V_268 , V_2 -> V_19 + V_278 ) ;
}
F_28 ( & V_265 -> V_242 ) ;
return 0 ;
}
static int F_68 ( struct V_264 * V_265 , int V_281 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_265 -> V_21 -> V_18 ;
F_26 ( & V_265 -> V_242 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_29 ) ;
V_45 &= ~ V_8 [ V_281 ] ;
F_14 ( V_45 , V_2 -> V_19 + V_29 ) ;
F_14 ( V_8 [ V_281 ] ,
V_2 -> V_19 + V_30 ) ;
V_2 -> V_9 [ V_281 ] = NULL ;
if ( ( V_45 & ( V_32 | V_33 | V_34 |
V_35 ) ) == 0 ) {
V_45 = F_7 ( V_2 -> V_19 + V_278 ) ;
V_45 &= ~ V_279 ;
F_14 ( V_45 , V_2 -> V_19 + V_278 ) ;
}
F_28 ( & V_265 -> V_242 ) ;
return 0 ;
}
static int F_69 ( struct V_15 * V_16 )
{
T_1 V_282 = 0 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
if ( ! V_283 ) {
V_282 = F_7 ( V_2 -> V_19 + V_284 ) ;
V_282 = ( ( V_282 & V_285 ) >> 27 ) ;
} else
V_282 = V_283 ;
return ( int ) V_282 ;
}
static void * F_70 ( struct V_185 * V_21 , T_5 V_73 ,
T_3 * V_286 )
{
struct V_46 * V_47 ;
V_47 = F_16 ( V_21 , struct V_46 , V_48 ) ;
return F_71 ( V_47 , V_73 , V_286 ) ;
}
static void F_72 ( struct V_185 * V_21 , T_5 V_73 ,
void * V_287 , T_3 V_286 )
{
struct V_46 * V_47 ;
V_47 = F_16 ( V_21 , struct V_46 , V_48 ) ;
F_73 ( V_47 , V_73 , V_287 , V_286 ) ;
}
static int F_74 ( struct V_15 * V_16 ,
struct V_46 * V_47 )
{
unsigned int V_288 ;
int V_45 , V_282 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_282 = F_69 ( V_16 ) ;
if ( V_283 )
F_14 ( V_283 << 27 , V_2 -> V_19 + V_284 ) ;
F_75 ( & V_47 -> V_48 , L_36 , V_282 ) ;
if ( V_282 == 0 ) {
F_8 ( & V_47 -> V_48 , L_37
L_38 ) ;
return - V_66 ;
}
V_2 -> V_289 = F_76 ( V_47 , V_290 ,
& V_2 -> V_291 ) ;
if ( V_2 -> V_289 == NULL ) {
F_8 ( & V_47 -> V_48 , L_39
L_40 ) ;
return - V_125 ;
}
V_288 = V_282 * ( 512 * 1024 ) ;
F_14 ( V_2 -> V_291 - V_288 , V_2 -> V_19 + V_292 ) ;
V_45 = F_7 ( V_2 -> V_19 + V_293 ) ;
V_45 |= V_294 ;
F_14 ( V_45 , V_2 -> V_19 + V_293 ) ;
return 0 ;
}
static void F_77 ( struct V_15 * V_16 ,
struct V_46 * V_47 )
{
T_1 V_45 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_18 ;
V_45 = F_7 ( V_2 -> V_19 + V_293 ) ;
V_45 &= ~ V_294 ;
F_14 ( V_45 , V_2 -> V_19 + V_293 ) ;
F_14 ( 0 , V_2 -> V_19 + V_292 ) ;
F_73 ( V_47 , V_290 , V_2 -> V_289 ,
V_2 -> V_291 ) ;
}
static int F_78 ( struct V_46 * V_47 , const struct V_295 * V_296 )
{
int V_116 , V_6 ;
T_1 V_297 ;
struct V_261 * V_262 = NULL , * V_298 ;
struct V_15 * V_16 ;
struct V_1 * V_299 ;
struct V_114 * V_300 ;
struct V_69 * V_301 ;
struct V_239 * V_302 ;
struct V_264 * V_265 ;
V_16 = F_79 ( sizeof( struct V_15 ) , V_206 ) ;
if ( V_16 == NULL ) {
F_8 ( & V_47 -> V_48 , L_41
L_23 ) ;
V_116 = - V_125 ;
goto V_303;
}
V_299 = F_79 ( sizeof( struct V_1 ) , V_206 ) ;
if ( V_299 == NULL ) {
F_8 ( & V_47 -> V_48 , L_41
L_23 ) ;
V_116 = - V_125 ;
goto V_304;
}
V_16 -> V_18 = V_299 ;
V_116 = F_80 ( V_47 ) ;
if ( V_116 ) {
F_8 ( & V_47 -> V_48 , L_42 ) ;
goto V_305;
}
V_116 = F_81 ( V_47 , V_53 ) ;
if ( V_116 ) {
F_8 ( & V_47 -> V_48 , L_43 ) ;
goto V_131;
}
V_299 -> V_19 = F_37 ( F_82 ( V_47 , 0 ) ,
4096 ) ;
if ( ! V_299 -> V_19 ) {
F_8 ( & V_47 -> V_48 , L_44 ) ;
V_116 = - V_260 ;
goto V_132;
}
V_297 = F_7 ( V_299 -> V_19 + V_306 ) & 0x0000FFFF ;
if ( V_297 != V_307 ) {
F_8 ( & V_47 -> V_48 , L_45 ) ;
V_116 = - V_260 ;
goto V_308;
}
F_83 ( & V_299 -> V_3 ) ;
F_83 ( & V_299 -> V_13 ) ;
F_18 ( & V_299 -> V_67 ) ;
F_18 ( & V_299 -> V_186 ) ;
V_16 -> V_21 = & V_47 -> V_48 ;
strcpy ( V_16 -> V_121 , V_53 ) ;
V_116 = F_15 ( V_16 ) ;
if ( V_116 != 0 ) {
F_8 ( & V_47 -> V_48 , L_46 ) ;
goto V_309;
}
F_17 ( & V_16 -> V_310 ) ;
for ( V_6 = 0 ; V_6 < V_311 ; V_6 ++ ) {
V_300 = F_35 ( sizeof( struct V_114 ) ,
V_206 ) ;
if ( V_300 == NULL ) {
F_8 ( & V_47 -> V_48 , L_47
L_48 ) ;
V_116 = - V_125 ;
goto V_312;
}
V_300 -> V_21 = V_16 ;
F_84 ( & V_300 -> V_137 ) ;
V_300 -> V_313 = 0 ;
V_300 -> V_82 = V_6 ;
V_300 -> V_314 = V_83 | V_85 | V_87 |
V_94 | V_89 | V_91 ;
V_300 -> V_315 = V_171 | V_142 | V_144 |
V_105 | V_107 | V_109 | V_111 ;
V_300 -> V_316 = V_147 | V_149 | V_151 | V_153 ;
memset ( & V_300 -> V_117 , 0 ,
sizeof( struct V_122 ) ) ;
V_300 -> V_120 = NULL ;
F_52 ( & V_300 -> V_194 ,
& V_16 -> V_310 ) ;
}
F_17 ( & V_16 -> V_317 ) ;
for ( V_6 = 0 ; V_6 < V_318 ; V_6 ++ ) {
V_301 = F_35 ( sizeof( struct V_69 ) ,
V_206 ) ;
if ( V_301 == NULL ) {
F_8 ( & V_47 -> V_48 , L_47
L_49 ) ;
V_116 = - V_125 ;
goto V_319;
}
V_301 -> V_21 = V_16 ;
F_18 ( & V_301 -> V_242 ) ;
V_301 -> V_313 = 0 ;
V_301 -> V_82 = V_6 ;
V_301 -> V_314 = V_85 | V_87 | V_89 |
V_91 ;
if ( V_6 == 0 || V_6 == 4 )
V_301 -> V_314 |= V_83 ;
V_301 -> V_315 = V_171 | V_142 | V_144 |
V_105 | V_107 | V_109 | V_111 ;
F_52 ( & V_301 -> V_194 ,
& V_16 -> V_317 ) ;
}
F_17 ( & V_16 -> V_320 ) ;
for ( V_6 = 0 ; V_6 < V_321 ; V_6 ++ ) {
V_302 = F_35 ( sizeof( struct V_239 ) ,
V_206 ) ;
if ( V_302 == NULL ) {
F_8 ( & V_47 -> V_48 , L_47
L_50 ) ;
V_116 = - V_125 ;
goto V_322;
}
V_302 -> V_21 = V_16 ;
F_18 ( & V_302 -> V_242 ) ;
V_302 -> V_313 = 0 ;
V_302 -> V_82 = V_6 ;
V_302 -> V_323 = V_324 |
V_325 ;
F_17 ( & V_302 -> V_326 ) ;
F_17 ( & V_302 -> V_243 ) ;
F_52 ( & V_302 -> V_194 ,
& V_16 -> V_320 ) ;
}
F_17 ( & V_16 -> V_327 ) ;
V_265 = F_35 ( sizeof( struct V_264 ) , V_206 ) ;
if ( V_265 == NULL ) {
F_8 ( & V_47 -> V_48 , L_47
L_51 ) ;
V_116 = - V_125 ;
goto V_328;
}
V_265 -> V_21 = V_16 ;
F_18 ( & V_265 -> V_242 ) ;
V_265 -> V_313 = 0 ;
V_265 -> V_82 = 1 ;
V_265 -> V_269 = 4 ;
F_52 ( & V_265 -> V_194 , & V_16 -> V_327 ) ;
V_16 -> V_329 = F_30 ;
V_16 -> V_330 = F_29 ;
V_16 -> V_331 = F_43 ;
V_16 -> V_332 = F_39 ;
V_16 -> V_333 = F_44 ;
V_16 -> V_334 = F_47 ;
V_16 -> V_335 = F_50 ;
V_16 -> V_336 = F_51 ;
V_16 -> V_337 = F_56 ;
V_16 -> V_338 = F_62 ;
V_16 -> V_339 = F_23 ;
V_16 -> V_340 = F_25 ;
V_16 -> V_341 = F_64 ;
V_16 -> V_342 = F_65 ;
V_16 -> V_343 = F_66 ;
V_16 -> V_344 = F_68 ;
V_16 -> V_345 = F_69 ;
V_16 -> V_346 = F_70 ;
V_16 -> V_347 = F_72 ;
V_297 = F_7 ( V_299 -> V_19 + V_348 ) ;
F_75 ( & V_47 -> V_48 , L_52 ,
( V_297 & V_349 ) ? L_53 : L_54 ) ;
F_75 ( & V_47 -> V_48 , L_55 ,
F_69 ( V_16 ) ) ;
if ( F_74 ( V_16 , V_47 ) )
F_8 ( & V_47 -> V_48 , L_56 ) ;
V_116 = F_85 ( V_16 ) ;
if ( V_116 != 0 ) {
F_8 ( & V_47 -> V_48 , L_57 ) ;
goto V_350;
}
F_86 ( V_47 , V_16 ) ;
return 0 ;
V_350:
F_77 ( V_16 , V_47 ) ;
V_328:
F_63 (pos, n, &ca91cx42_bridge->lm_resources) {
V_265 = F_53 ( V_262 , struct V_264 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_265 ) ;
}
V_322:
F_63 (pos, n, &ca91cx42_bridge->dma_resources) {
V_302 = F_53 ( V_262 , struct V_239 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_302 ) ;
}
V_319:
F_63 (pos, n, &ca91cx42_bridge->slave_resources) {
V_301 = F_53 ( V_262 , struct V_69 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_301 ) ;
}
V_312:
F_63 (pos, n, &ca91cx42_bridge->master_resources) {
V_300 = F_53 ( V_262 , struct V_114 ,
V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_300 ) ;
}
F_20 ( V_299 , V_47 ) ;
V_309:
V_308:
F_32 ( V_299 -> V_19 ) ;
V_132:
F_87 ( V_47 ) ;
V_131:
F_88 ( V_47 ) ;
V_305:
F_33 ( V_299 ) ;
V_304:
F_33 ( V_16 ) ;
V_303:
return V_116 ;
}
static void F_89 ( struct V_46 * V_47 )
{
struct V_261 * V_262 = NULL , * V_298 ;
struct V_114 * V_300 ;
struct V_69 * V_301 ;
struct V_239 * V_302 ;
struct V_264 * V_265 ;
struct V_1 * V_2 ;
struct V_15 * V_16 = F_90 ( V_47 ) ;
V_2 = V_16 -> V_18 ;
F_14 ( 0 , V_2 -> V_19 + V_29 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_351 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_352 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_353 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_354 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_355 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_356 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_357 ) ;
F_14 ( 0x00800000 , V_2 -> V_19 + V_358 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_359 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_360 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_361 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_362 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_363 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_364 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_365 ) ;
F_14 ( 0x00F00000 , V_2 -> V_19 + V_366 ) ;
F_91 ( V_16 ) ;
F_77 ( V_16 , V_47 ) ;
F_63 (pos, n, &ca91cx42_bridge->lm_resources) {
V_265 = F_53 ( V_262 , struct V_264 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_265 ) ;
}
F_63 (pos, n, &ca91cx42_bridge->dma_resources) {
V_302 = F_53 ( V_262 , struct V_239 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_302 ) ;
}
F_63 (pos, n, &ca91cx42_bridge->slave_resources) {
V_301 = F_53 ( V_262 , struct V_69 , V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_301 ) ;
}
F_63 (pos, n, &ca91cx42_bridge->master_resources) {
V_300 = F_53 ( V_262 , struct V_114 ,
V_194 ) ;
F_61 ( V_262 ) ;
F_33 ( V_300 ) ;
}
F_20 ( V_2 , V_47 ) ;
F_32 ( V_2 -> V_19 ) ;
F_87 ( V_47 ) ;
F_88 ( V_47 ) ;
F_33 ( V_16 ) ;
}
