static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , unsigned long V_6 ,
unsigned long V_7 )
{
F_4 ( V_6 , V_5 -> V_8 + V_7 ) ;
}
static unsigned long F_5 ( struct V_4 * V_5 ,
unsigned long V_7 )
{
return F_6 ( V_5 -> V_8 + V_7 ) ;
}
static void F_7 ( struct V_4 * V_5 , int V_9 , T_1 V_10 , T_1 V_11 )
{
int V_12 = 8 * ( V_9 & 3 ) ;
T_1 V_6 = F_5 ( V_5 , V_9 & ~ 3 ) ;
V_6 &= ~ ( V_10 << V_12 ) ;
V_6 |= V_11 << V_12 ;
F_3 ( V_5 , V_6 , V_9 & ~ 3 ) ;
}
static T_1 F_8 ( struct V_4 * V_5 , int V_9 )
{
int V_12 = 8 * ( V_9 & 3 ) ;
T_1 V_6 = F_5 ( V_5 , V_9 & ~ 3 ) ;
return V_6 >> V_12 ;
}
static int F_9 ( struct V_4 * V_5 ,
unsigned char V_13 , struct V_14 * V_15 ,
unsigned int V_16 , int V_9 , T_1 * V_11 )
{
int V_17 , V_18 , V_7 , V_19 ;
V_17 = F_10 ( V_16 ) ;
V_18 = F_11 ( V_16 ) ;
V_7 = V_9 & ~ 3 ;
V_19 = V_7 / 4 ;
if ( F_12 ( V_15 ) ) {
if ( V_17 != 0 )
return V_20 ;
if ( V_13 == V_21 ) {
* V_11 = F_5 ( V_5 , F_13 ( V_19 ) ) ;
} else {
if ( F_12 ( V_15 ) && ( V_7 == V_22 ) )
V_5 -> V_23 = * V_11 & 0xff ;
F_3 ( V_5 , * V_11 , F_13 ( V_19 ) ) ;
}
return V_24 ;
}
if ( V_5 -> V_23 < 0 )
return V_20 ;
F_3 ( V_5 , F_5 ( V_5 , V_25 ) , V_25 ) ;
F_3 ( V_5 , F_14 ( V_15 -> V_26 ) |
F_15 ( V_17 ) | F_16 ( V_18 ) | V_7 , V_27 ) ;
if ( V_15 -> V_28 -> V_26 == V_5 -> V_23 )
F_3 ( V_5 , V_29 | V_30 , V_31 ) ;
else
F_3 ( V_5 , V_29 | V_32 , V_31 ) ;
if ( F_5 ( V_5 , V_25 ) & V_33 )
return V_20 ;
if ( F_8 ( V_5 , F_17 ( V_34 ) ) &
( V_35 | V_36 ) )
return V_20 ;
if ( V_13 == V_21 )
* V_11 = F_5 ( V_5 , V_37 ) ;
else
F_3 ( V_5 , * V_11 , V_37 ) ;
F_3 ( V_5 , 0 , V_31 ) ;
return V_24 ;
}
static int F_18 ( struct V_14 * V_15 , unsigned int V_16 ,
int V_9 , int V_38 , T_1 * V_6 )
{
struct V_4 * V_5 = V_15 -> V_39 ;
int V_40 ;
V_40 = F_9 ( V_5 , V_21 ,
V_15 , V_16 , V_9 , V_6 ) ;
if ( V_40 != V_24 ) {
* V_6 = 0xffffffff ;
return V_40 ;
}
if ( V_38 == 1 )
* V_6 = ( * V_6 >> ( 8 * ( V_9 & 3 ) ) ) & 0xff ;
else if ( V_38 == 2 )
* V_6 = ( * V_6 >> ( 8 * ( V_9 & 2 ) ) ) & 0xffff ;
F_19 ( & V_15 -> V_17 , L_1 ,
V_15 -> V_26 , V_16 , V_9 , V_38 , ( unsigned long ) * V_6 ) ;
return V_40 ;
}
static int F_20 ( struct V_14 * V_15 , unsigned int V_16 ,
int V_9 , int V_38 , T_1 V_6 )
{
struct V_4 * V_5 = V_15 -> V_39 ;
int V_12 , V_40 ;
T_1 V_11 ;
V_40 = F_9 ( V_5 , V_21 ,
V_15 , V_16 , V_9 , & V_11 ) ;
if ( V_40 != V_24 )
return V_40 ;
F_19 ( & V_15 -> V_17 , L_2 ,
V_15 -> V_26 , V_16 , V_9 , V_38 , ( unsigned long ) V_6 ) ;
if ( V_38 == 1 ) {
V_12 = 8 * ( V_9 & 3 ) ;
V_11 &= ~ ( 0xff << V_12 ) ;
V_11 |= ( ( V_6 & 0xff ) << V_12 ) ;
} else if ( V_38 == 2 ) {
V_12 = 8 * ( V_9 & 2 ) ;
V_11 &= ~ ( 0xffff << V_12 ) ;
V_11 |= ( ( V_6 & 0xffff ) << V_12 ) ;
} else
V_11 = V_6 ;
V_40 = F_9 ( V_5 , V_41 ,
V_15 , V_16 , V_9 , & V_11 ) ;
return V_40 ;
}
static void F_21 ( int V_42 , struct V_4 * V_5 ,
struct V_43 * V_44 )
{
T_2 V_38 ;
T_2 V_45 ;
T_1 V_10 ;
F_3 ( V_5 , 0x00000000 , F_22 ( V_42 ) ) ;
V_38 = F_23 ( V_44 ) ;
V_10 = ( F_24 ( V_38 ) / V_46 ) - 1 ;
F_3 ( V_5 , V_10 << 7 , F_25 ( V_42 ) ) ;
if ( V_44 -> V_47 & V_48 )
V_45 = F_26 ( V_44 -> V_49 ) ;
else
V_45 = V_44 -> V_49 ;
F_3 ( V_5 , F_27 ( V_45 ) , F_28 ( V_42 ) ) ;
F_3 ( V_5 , F_29 ( V_45 ) & ~ 0x7F ,
F_30 ( V_42 ) ) ;
V_10 = V_50 ;
if ( V_44 -> V_47 & V_48 )
V_10 |= V_51 ;
F_3 ( V_5 , V_10 , F_22 ( V_42 ) ) ;
}
static int F_31 ( struct V_52 * V_43 , struct V_4 * V_53 )
{
struct V_54 * V_42 ;
int V_55 = 0 ;
F_32 (win, &pci->resources) {
struct V_43 * V_44 = V_42 -> V_44 ;
if ( ! V_44 -> V_47 )
continue;
switch ( F_33 ( V_44 ) ) {
case V_48 :
case V_56 :
F_21 ( V_55 , V_53 , V_44 ) ;
V_55 ++ ;
break;
case V_57 :
V_53 -> V_23 = V_44 -> V_49 ;
break;
default:
continue;
}
F_34 ( V_43 , V_44 ) ;
}
return 1 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_14 * V_15 , * V_58 ;
F_36 ( V_44 ) ;
F_31 ( & V_44 , V_5 ) ;
if ( ! F_37 ( V_59 ) )
F_38 ( V_60 | V_61 ) ;
if ( F_39 ( V_62 ) )
V_15 = F_40 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_63 , V_5 , & V_44 , & V_5 -> V_64 . V_3 ) ;
else
V_15 = F_41 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_63 , V_5 , & V_44 ) ;
if ( ! V_15 ) {
F_42 ( V_5 -> V_17 , L_3 ) ;
return - V_65 ;
}
F_43 ( V_66 , V_67 ) ;
if ( ! F_37 ( V_59 ) ) {
F_44 ( V_15 ) ;
F_45 ( V_15 ) ;
F_46 (child, &bus->children, node)
F_47 ( V_58 ) ;
}
F_48 ( V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 )
{
unsigned int V_68 = 100 ;
while ( V_68 -- ) {
if ( F_5 ( V_5 , V_69 ) & V_70 )
return 0 ;
F_50 ( 100 ) ;
}
F_42 ( V_5 -> V_17 , L_4 ) ;
return - V_71 ;
}
static void F_51 ( struct V_4 * V_5 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 , unsigned int V_11 )
{
unsigned long V_75 ;
V_75 = V_76 |
( ( V_72 & 1 ) << V_77 ) |
( ( V_74 & 0xf ) << V_78 ) |
( ( V_73 & 0xff ) << V_79 ) ;
F_3 ( V_5 , V_11 , V_80 ) ;
F_3 ( V_5 , V_75 , V_69 ) ;
F_49 ( V_5 ) ;
F_3 ( V_5 , 0 , V_80 ) ;
F_3 ( V_5 , 0 , V_69 ) ;
F_49 ( V_5 ) ;
}
static int F_52 ( struct V_4 * V_5 )
{
unsigned int V_68 = 10 ;
while ( V_68 -- ) {
if ( ( F_5 ( V_5 , V_81 ) & V_82 ) )
return 0 ;
F_53 ( 5 ) ;
}
return - V_71 ;
}
static int F_54 ( struct V_4 * V_5 )
{
int V_83 ;
F_3 ( V_5 , 0 , V_84 ) ;
F_3 ( V_5 , 1 , V_85 ) ;
F_3 ( V_5 , V_86 << 16 , V_87 ) ;
F_7 ( V_5 , F_17 ( V_88 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_17 ( V_89 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_55 ( 0 ) , 0xff , V_90 ) ;
F_7 ( V_5 , F_55 ( V_91 ) ,
V_92 , V_93 << 4 ) ;
F_7 ( V_5 , F_17 ( V_94 ) , 0x7f ,
V_95 ) ;
F_7 ( V_5 , F_55 ( V_96 ) , V_97 ,
V_97 ) ;
F_7 ( V_5 , F_55 ( V_98 ) , V_99 , 0 ) ;
F_7 ( V_5 , V_100 + 1 , 0x3f , 50 ) ;
F_7 ( V_5 , F_56 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_39 ( V_62 ) )
F_3 ( V_5 , 0x801f0000 , V_101 ) ;
F_3 ( V_5 , V_102 , V_84 ) ;
V_83 = F_52 ( V_5 ) ;
if ( V_83 )
return V_83 ;
F_7 ( V_5 , V_103 , 0 , 0xF << 8 ) ;
F_57 () ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
unsigned int V_68 = 10 ;
F_51 ( V_5 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_51 ( V_5 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_51 ( V_5 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_51 ( V_5 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_51 ( V_5 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_51 ( V_5 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_51 ( V_5 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_51 ( V_5 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_51 ( V_5 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_51 ( V_5 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_51 ( V_5 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_51 ( V_5 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_51 ( V_5 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_51 ( V_5 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_51 ( V_5 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_68 -- ) {
if ( F_5 ( V_5 , V_104 ) )
return F_54 ( V_5 ) ;
F_53 ( 5 ) ;
}
return - V_71 ;
}
static int F_59 ( struct V_4 * V_5 )
{
F_3 ( V_5 , 0x000f0030 , V_105 ) ;
F_3 ( V_5 , 0x00381203 , V_106 ) ;
F_3 ( V_5 , 0x00000001 , V_107 ) ;
F_3 ( V_5 , 0x00000006 , V_107 ) ;
F_3 ( V_5 , 0x000f0054 , V_105 ) ;
F_3 ( V_5 , 0x13802007 , V_106 ) ;
F_3 ( V_5 , 0x00000001 , V_107 ) ;
F_3 ( V_5 , 0x00000006 , V_107 ) ;
return F_54 ( V_5 ) ;
}
static int F_60 ( struct V_1 * V_3 )
{
int V_64 ;
F_61 ( & V_3 -> V_108 ) ;
V_64 = F_62 ( V_3 -> V_109 , V_110 ) ;
if ( V_64 < V_110 )
F_63 ( V_64 , V_3 -> V_109 ) ;
else
V_64 = - V_111 ;
F_64 ( & V_3 -> V_108 ) ;
return V_64 ;
}
static void F_65 ( struct V_1 * V_3 , unsigned long V_112 )
{
F_61 ( & V_3 -> V_108 ) ;
F_66 ( V_112 , V_3 -> V_109 ) ;
F_64 ( & V_3 -> V_108 ) ;
}
static T_3 F_67 ( int V_112 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
struct V_1 * V_64 = & V_5 -> V_64 ;
unsigned long V_7 ;
V_7 = F_5 ( V_5 , V_113 ) ;
if ( ! V_7 )
return V_114 ;
while ( V_7 ) {
unsigned int V_19 = F_68 ( & V_7 , 32 ) ;
unsigned int V_112 ;
F_3 ( V_5 , 1 << V_19 , V_113 ) ;
V_112 = F_69 ( V_64 -> V_115 , V_19 ) ;
if ( V_112 ) {
if ( F_70 ( V_19 , V_64 -> V_109 ) )
F_71 ( V_112 ) ;
else
F_72 ( V_5 -> V_17 , L_5 ) ;
} else {
F_19 ( V_5 -> V_17 , L_6 ) ;
}
V_7 = F_5 ( V_5 , V_113 ) ;
}
return V_116 ;
}
static int F_73 ( struct V_2 * V_3 , struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_64 . V_3 ) ;
struct V_121 V_122 ;
unsigned int V_112 ;
int V_123 ;
V_123 = F_60 ( V_64 ) ;
if ( V_123 < 0 )
return V_123 ;
V_112 = F_74 ( V_64 -> V_115 , V_123 ) ;
if ( ! V_112 ) {
F_65 ( V_64 , V_123 ) ;
return - V_124 ;
}
F_75 ( V_112 , V_120 ) ;
V_122 . V_125 = F_5 ( V_5 , V_126 ) & ~ V_127 ;
V_122 . V_128 = F_5 ( V_5 , V_129 ) ;
V_122 . V_11 = V_123 ;
F_76 ( V_112 , & V_122 ) ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 , unsigned int V_112 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_130 * V_131 = F_78 ( V_112 ) ;
F_65 ( V_64 , V_131 -> V_123 ) ;
}
static int F_79 ( struct V_132 * V_115 , unsigned int V_112 ,
T_4 V_123 )
{
F_80 ( V_112 , & V_133 , V_134 ) ;
F_81 ( V_112 , V_115 -> V_135 ) ;
return 0 ;
}
static int F_82 ( struct V_4 * V_5 )
{
struct V_136 * V_118 = F_83 ( V_5 -> V_17 ) ;
struct V_1 * V_64 = & V_5 -> V_64 ;
unsigned long V_8 ;
int V_83 ;
F_84 ( & V_64 -> V_108 ) ;
V_64 -> V_3 . V_17 = V_5 -> V_17 ;
V_64 -> V_3 . V_137 = F_73 ;
V_64 -> V_3 . V_138 = F_77 ;
V_64 -> V_115 = F_85 ( V_5 -> V_17 -> V_139 , V_110 ,
& V_140 , & V_64 -> V_3 ) ;
if ( ! V_64 -> V_115 ) {
F_42 ( & V_118 -> V_17 , L_7 ) ;
return - V_141 ;
}
V_83 = F_86 ( & V_118 -> V_17 , V_64 -> V_142 , F_67 ,
V_143 | V_144 ,
V_133 . V_145 , V_5 ) ;
if ( V_83 < 0 ) {
F_42 ( & V_118 -> V_17 , L_8 , V_83 ) ;
goto V_83;
}
V_83 = F_86 ( & V_118 -> V_17 , V_64 -> V_146 , F_67 ,
V_143 | V_144 ,
V_133 . V_145 , V_5 ) ;
if ( V_83 < 0 ) {
F_42 ( & V_118 -> V_17 , L_8 , V_83 ) ;
goto V_83;
}
V_64 -> V_147 = F_87 ( V_148 , 0 ) ;
V_8 = F_88 ( ( void * ) V_64 -> V_147 ) ;
F_3 ( V_5 , V_8 | V_127 , V_126 ) ;
F_3 ( V_5 , 0 , V_129 ) ;
F_3 ( V_5 , 0xffffffff , V_149 ) ;
return 0 ;
V_83:
F_89 ( V_64 -> V_115 ) ;
return V_83 ;
}
static int F_90 ( struct V_136 * V_118 ,
struct V_4 * V_5 )
{
struct V_43 V_44 ;
int V_83 , V_55 ;
V_83 = F_91 ( V_118 -> V_17 . V_139 , 0 , & V_44 ) ;
if ( V_83 )
return V_83 ;
V_5 -> V_150 = F_92 ( & V_118 -> V_17 , L_9 ) ;
if ( F_93 ( V_5 -> V_150 ) ) {
F_42 ( V_5 -> V_17 , L_10 ) ;
return F_94 ( V_5 -> V_150 ) ;
}
V_83 = F_95 ( V_5 -> V_150 ) ;
if ( V_83 )
goto V_151;
V_5 -> V_152 = F_92 ( & V_118 -> V_17 , L_11 ) ;
if ( F_93 ( V_5 -> V_152 ) ) {
F_42 ( V_5 -> V_17 , L_12 ) ;
V_83 = F_94 ( V_5 -> V_152 ) ;
goto V_151;
}
V_83 = F_95 ( V_5 -> V_152 ) ;
if ( V_83 )
goto V_153;
V_55 = F_96 ( V_118 -> V_17 . V_139 , 0 ) ;
if ( ! V_55 ) {
F_42 ( V_5 -> V_17 , L_13 ) ;
V_83 = - V_154 ;
goto V_153;
}
V_5 -> V_64 . V_142 = V_55 ;
V_55 = F_96 ( V_118 -> V_17 . V_139 , 1 ) ;
if ( ! V_55 ) {
F_42 ( V_5 -> V_17 , L_13 ) ;
V_83 = - V_154 ;
goto V_153;
}
V_5 -> V_64 . V_146 = V_55 ;
V_5 -> V_8 = F_97 ( & V_118 -> V_17 , & V_44 ) ;
if ( F_93 ( V_5 -> V_8 ) ) {
V_83 = F_94 ( V_5 -> V_8 ) ;
goto V_153;
}
return 0 ;
V_153:
F_98 ( V_5 -> V_152 ) ;
V_151:
F_98 ( V_5 -> V_150 ) ;
return V_83 ;
}
static int F_99 ( struct V_4 * V_5 ,
struct V_155 * V_156 ,
int * V_19 )
{
T_5 V_157 = V_156 -> V_47 ;
T_5 V_158 = V_156 -> V_158 ;
T_5 V_159 = V_156 -> V_158 + V_156 -> V_38 ;
T_5 V_160 = V_156 -> V_160 ;
T_1 V_47 = V_161 | V_162 ;
T_5 V_10 ;
T_5 V_38 ;
int V_163 = * V_19 ;
if ( V_157 & V_164 )
V_47 |= V_165 ;
if ( V_158 > 0 ) {
unsigned long V_166 = F_100 ( V_158 ) ;
T_5 V_167 = 1ULL << V_166 ;
V_38 = F_101 ( V_156 -> V_38 , V_167 ) ;
} else {
V_38 = V_156 -> V_38 ;
}
V_38 = F_101 ( V_38 , 1ULL << 32 ) ;
V_10 = F_24 ( V_38 ) - 1 ;
V_10 &= ~ 0xf ;
while ( V_158 < V_159 ) {
F_3 ( V_5 , F_29 ( V_160 ) , F_102 ( V_163 ) ) ;
F_3 ( V_5 , F_29 ( V_158 ) , F_103 ( V_163 ) ) ;
F_3 ( V_5 , F_29 ( V_10 ) | V_47 , F_104 ( V_163 ) ) ;
F_3 ( V_5 , F_27 ( V_160 ) , F_102 ( V_163 + 1 ) ) ;
F_3 ( V_5 , F_27 ( V_158 ) , F_103 ( V_163 + 1 ) ) ;
F_3 ( V_5 , 0 , F_104 ( V_163 + 1 ) ) ;
V_160 += V_38 ;
V_158 += V_38 ;
V_163 += 2 ;
if ( V_163 > V_168 ) {
F_42 ( V_5 -> V_17 , L_14 ) ;
return - V_124 ;
}
}
* V_19 = V_163 ;
return 0 ;
}
static int F_105 ( struct V_169 * V_170 ,
struct V_171 * V_172 )
{
const int V_173 = 3 , V_174 = 2 ;
int V_175 ;
V_170 -> V_172 = V_172 ;
V_170 -> V_176 = F_106 ( V_172 ) ;
V_170 -> V_177 = V_170 -> V_176 + V_173 + V_174 ;
V_170 -> V_156 = F_107 ( V_172 , L_15 , & V_175 ) ;
if ( ! V_170 -> V_156 )
return - V_154 ;
V_170 -> V_178 = V_170 -> V_156 + V_175 / sizeof( V_179 ) ;
return 0 ;
}
static int F_108 ( struct V_4 * V_5 ,
struct V_171 * V_177 )
{
struct V_155 V_156 ;
struct V_169 V_170 ;
int V_19 = 0 ;
int V_83 ;
if ( F_105 ( & V_170 , V_177 ) )
return - V_124 ;
F_109 (&parser, &range) {
T_5 V_178 = V_156 . V_158 + V_156 . V_38 - 1 ;
F_19 ( V_5 -> V_17 , L_16 ,
V_156 . V_47 , V_156 . V_158 , V_178 , V_156 . V_160 ) ;
V_83 = F_99 ( V_5 , & V_156 , & V_19 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static void F_110 ( struct V_4 * V_53 )
{
F_111 ( & V_53 -> V_180 ) ;
}
static int F_112 ( struct V_4 * V_53 )
{
int V_83 ;
struct V_181 * V_17 = V_53 -> V_17 ;
struct V_171 * V_177 = V_17 -> V_139 ;
T_2 V_182 ;
struct V_54 * V_42 ;
V_83 = F_113 ( V_177 , 0 , 0xff , & V_53 -> V_180 , & V_182 ) ;
if ( V_83 )
return V_83 ;
F_32 (win, &pci->resources) {
struct V_43 * V_28 , * V_44 = V_42 -> V_44 ;
switch ( F_33 ( V_44 ) ) {
case V_48 :
V_28 = & V_183 ;
V_83 = F_114 ( V_44 , V_182 ) ;
if ( V_83 ) {
F_115 ( V_17 , L_17 ,
V_83 , V_44 ) ;
continue;
}
break;
case V_56 :
V_28 = & V_184 ;
break;
case V_57 :
default:
continue;
}
V_83 = F_116 ( V_17 , V_28 , V_44 ) ;
if ( V_83 )
goto V_185;
}
return 0 ;
V_185:
F_110 ( V_53 ) ;
return V_83 ;
}
static int F_117 ( struct V_136 * V_118 )
{
struct V_4 * V_5 ;
unsigned int V_11 ;
const struct V_186 * V_187 ;
int V_83 ;
int (* F_118)( struct V_4 * );
V_5 = F_119 ( & V_118 -> V_17 , sizeof( * V_5 ) , V_148 ) ;
if ( ! V_5 )
return - V_141 ;
V_5 -> V_17 = & V_118 -> V_17 ;
F_120 ( V_118 , V_5 ) ;
F_121 ( & V_5 -> V_180 ) ;
F_112 ( V_5 ) ;
V_83 = F_90 ( V_118 , V_5 ) ;
if ( V_83 < 0 ) {
F_42 ( & V_118 -> V_17 , L_18 , V_83 ) ;
return V_83 ;
}
V_83 = F_108 ( V_5 , V_118 -> V_17 . V_139 ) ;
if ( V_83 )
return V_83 ;
V_187 = F_122 ( V_188 , V_5 -> V_17 ) ;
if ( ! V_187 || ! V_187 -> V_11 )
return - V_124 ;
F_118 = V_187 -> V_11 ;
F_123 ( V_5 -> V_17 ) ;
V_83 = F_124 ( V_5 -> V_17 ) ;
if ( V_83 < 0 ) {
F_42 ( V_5 -> V_17 , L_19 ) ;
goto V_189;
}
V_83 = F_118 ( V_5 ) ;
if ( V_83 ) {
F_72 ( & V_118 -> V_17 , L_20 ) ;
V_83 = 0 ;
goto V_190;
}
V_11 = F_5 ( V_5 , V_191 ) ;
F_72 ( & V_118 -> V_17 , L_21 , ( V_11 >> 20 ) & 0x3f ) ;
if ( F_39 ( V_62 ) ) {
V_83 = F_82 ( V_5 ) ;
if ( V_83 < 0 ) {
F_42 ( & V_118 -> V_17 ,
L_22 ,
V_83 ) ;
goto V_190;
}
}
V_83 = F_35 ( V_5 ) ;
if ( V_83 )
goto V_190;
return 0 ;
V_190:
F_125 ( V_5 -> V_17 ) ;
V_189:
F_126 ( V_5 -> V_17 ) ;
return V_83 ;
}
