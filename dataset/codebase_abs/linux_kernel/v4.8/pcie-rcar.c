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
F_37 ( V_59 | V_60 ) ;
if ( F_38 ( V_61 ) )
V_15 = F_39 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_62 , V_5 , & V_44 , & V_5 -> V_63 . V_3 ) ;
else
V_15 = F_40 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_62 , V_5 , & V_44 ) ;
if ( ! V_15 ) {
F_41 ( V_5 -> V_17 , L_3 ) ;
return - V_64 ;
}
F_42 ( V_65 , V_66 ) ;
F_43 ( V_15 ) ;
F_44 ( V_15 ) ;
F_45 (child, &bus->children, node)
F_46 ( V_58 ) ;
F_47 ( V_15 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
unsigned int V_67 = 100 ;
while ( V_67 -- ) {
if ( F_5 ( V_5 , V_68 ) & V_69 )
return 0 ;
F_49 ( 100 ) ;
}
F_41 ( V_5 -> V_17 , L_4 ) ;
return - V_70 ;
}
static void F_50 ( struct V_4 * V_5 ,
unsigned int V_71 , unsigned int V_72 ,
unsigned int V_73 , unsigned int V_11 )
{
unsigned long V_74 ;
V_74 = V_75 |
( ( V_71 & 1 ) << V_76 ) |
( ( V_73 & 0xf ) << V_77 ) |
( ( V_72 & 0xff ) << V_78 ) ;
F_3 ( V_5 , V_11 , V_79 ) ;
F_3 ( V_5 , V_74 , V_68 ) ;
F_48 ( V_5 ) ;
F_3 ( V_5 , 0 , V_79 ) ;
F_3 ( V_5 , 0 , V_68 ) ;
F_48 ( V_5 ) ;
}
static int F_51 ( struct V_4 * V_5 )
{
unsigned int V_67 = 10 ;
while ( V_67 -- ) {
if ( ( F_5 ( V_5 , V_80 ) & V_81 ) )
return 0 ;
F_52 ( 5 ) ;
}
return - V_70 ;
}
static int F_53 ( struct V_4 * V_5 )
{
int V_82 ;
F_3 ( V_5 , 0 , V_83 ) ;
F_3 ( V_5 , 1 , V_84 ) ;
F_3 ( V_5 , V_85 << 16 , V_86 ) ;
F_7 ( V_5 , F_17 ( V_87 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_17 ( V_88 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_54 ( 0 ) , 0xff , V_89 ) ;
F_7 ( V_5 , F_54 ( V_90 ) ,
V_91 , V_92 << 4 ) ;
F_7 ( V_5 , F_17 ( V_93 ) , 0x7f ,
V_94 ) ;
F_7 ( V_5 , F_54 ( V_95 ) , V_96 ,
V_96 ) ;
F_7 ( V_5 , F_54 ( V_97 ) , V_98 , 0 ) ;
F_7 ( V_5 , V_99 + 1 , 0x3f , 50 ) ;
F_7 ( V_5 , F_55 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_38 ( V_61 ) )
F_3 ( V_5 , 0x801f0000 , V_100 ) ;
F_3 ( V_5 , V_101 , V_83 ) ;
V_82 = F_51 ( V_5 ) ;
if ( V_82 )
return V_82 ;
F_7 ( V_5 , V_102 , 0 , 0xF << 8 ) ;
F_56 () ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
unsigned int V_67 = 10 ;
F_50 ( V_5 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_50 ( V_5 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_50 ( V_5 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_50 ( V_5 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_50 ( V_5 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_50 ( V_5 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_50 ( V_5 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_50 ( V_5 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_50 ( V_5 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_50 ( V_5 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_50 ( V_5 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_50 ( V_5 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_50 ( V_5 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_50 ( V_5 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_50 ( V_5 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_67 -- ) {
if ( F_5 ( V_5 , V_103 ) )
return F_53 ( V_5 ) ;
F_52 ( 5 ) ;
}
return - V_70 ;
}
static int F_58 ( struct V_4 * V_5 )
{
F_3 ( V_5 , 0x000f0030 , V_104 ) ;
F_3 ( V_5 , 0x00381203 , V_105 ) ;
F_3 ( V_5 , 0x00000001 , V_106 ) ;
F_3 ( V_5 , 0x00000006 , V_106 ) ;
F_3 ( V_5 , 0x000f0054 , V_104 ) ;
F_3 ( V_5 , 0x13802007 , V_105 ) ;
F_3 ( V_5 , 0x00000001 , V_106 ) ;
F_3 ( V_5 , 0x00000006 , V_106 ) ;
return F_53 ( V_5 ) ;
}
static int F_59 ( struct V_1 * V_3 )
{
int V_63 ;
F_60 ( & V_3 -> V_107 ) ;
V_63 = F_61 ( V_3 -> V_108 , V_109 ) ;
if ( V_63 < V_109 )
F_62 ( V_63 , V_3 -> V_108 ) ;
else
V_63 = - V_110 ;
F_63 ( & V_3 -> V_107 ) ;
return V_63 ;
}
static void F_64 ( struct V_1 * V_3 , unsigned long V_111 )
{
F_60 ( & V_3 -> V_107 ) ;
F_65 ( V_111 , V_3 -> V_108 ) ;
F_63 ( & V_3 -> V_107 ) ;
}
static T_3 F_66 ( int V_111 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
struct V_1 * V_63 = & V_5 -> V_63 ;
unsigned long V_7 ;
V_7 = F_5 ( V_5 , V_112 ) ;
if ( ! V_7 )
return V_113 ;
while ( V_7 ) {
unsigned int V_19 = F_67 ( & V_7 , 32 ) ;
unsigned int V_111 ;
F_3 ( V_5 , 1 << V_19 , V_112 ) ;
V_111 = F_68 ( V_63 -> V_114 , V_19 ) ;
if ( V_111 ) {
if ( F_69 ( V_19 , V_63 -> V_108 ) )
F_70 ( V_111 ) ;
else
F_71 ( V_5 -> V_17 , L_5 ) ;
} else {
F_19 ( V_5 -> V_17 , L_6 ) ;
}
V_7 = F_5 ( V_5 , V_112 ) ;
}
return V_115 ;
}
static int F_72 ( struct V_2 * V_3 , struct V_116 * V_117 ,
struct V_118 * V_119 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_63 . V_3 ) ;
struct V_120 V_121 ;
unsigned int V_111 ;
int V_122 ;
V_122 = F_59 ( V_63 ) ;
if ( V_122 < 0 )
return V_122 ;
V_111 = F_73 ( V_63 -> V_114 , V_122 ) ;
if ( ! V_111 ) {
F_64 ( V_63 , V_122 ) ;
return - V_123 ;
}
F_74 ( V_111 , V_119 ) ;
V_121 . V_124 = F_5 ( V_5 , V_125 ) & ~ V_126 ;
V_121 . V_127 = F_5 ( V_5 , V_128 ) ;
V_121 . V_11 = V_122 ;
F_75 ( V_111 , & V_121 ) ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 , unsigned int V_111 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_129 * V_130 = F_77 ( V_111 ) ;
F_64 ( V_63 , V_130 -> V_122 ) ;
}
static int F_78 ( struct V_131 * V_114 , unsigned int V_111 ,
T_4 V_122 )
{
F_79 ( V_111 , & V_132 , V_133 ) ;
F_80 ( V_111 , V_114 -> V_134 ) ;
return 0 ;
}
static int F_81 ( struct V_4 * V_5 )
{
struct V_135 * V_117 = F_82 ( V_5 -> V_17 ) ;
struct V_1 * V_63 = & V_5 -> V_63 ;
unsigned long V_8 ;
int V_82 ;
F_83 ( & V_63 -> V_107 ) ;
V_63 -> V_3 . V_17 = V_5 -> V_17 ;
V_63 -> V_3 . V_136 = F_72 ;
V_63 -> V_3 . V_137 = F_76 ;
V_63 -> V_114 = F_84 ( V_5 -> V_17 -> V_138 , V_109 ,
& V_139 , & V_63 -> V_3 ) ;
if ( ! V_63 -> V_114 ) {
F_41 ( & V_117 -> V_17 , L_7 ) ;
return - V_140 ;
}
V_82 = F_85 ( & V_117 -> V_17 , V_63 -> V_141 , F_66 ,
V_142 | V_143 ,
V_132 . V_144 , V_5 ) ;
if ( V_82 < 0 ) {
F_41 ( & V_117 -> V_17 , L_8 , V_82 ) ;
goto V_82;
}
V_82 = F_85 ( & V_117 -> V_17 , V_63 -> V_145 , F_66 ,
V_142 | V_143 ,
V_132 . V_144 , V_5 ) ;
if ( V_82 < 0 ) {
F_41 ( & V_117 -> V_17 , L_8 , V_82 ) ;
goto V_82;
}
V_63 -> V_146 = F_86 ( V_147 , 0 ) ;
V_8 = F_87 ( ( void * ) V_63 -> V_146 ) ;
F_3 ( V_5 , V_8 | V_126 , V_125 ) ;
F_3 ( V_5 , 0 , V_128 ) ;
F_3 ( V_5 , 0xffffffff , V_148 ) ;
return 0 ;
V_82:
F_88 ( V_63 -> V_114 ) ;
return V_82 ;
}
static int F_89 ( struct V_135 * V_117 ,
struct V_4 * V_5 )
{
struct V_43 V_44 ;
int V_82 , V_55 ;
V_82 = F_90 ( V_117 -> V_17 . V_138 , 0 , & V_44 ) ;
if ( V_82 )
return V_82 ;
V_5 -> V_149 = F_91 ( & V_117 -> V_17 , L_9 ) ;
if ( F_92 ( V_5 -> V_149 ) ) {
F_41 ( V_5 -> V_17 , L_10 ) ;
return F_93 ( V_5 -> V_149 ) ;
}
V_82 = F_94 ( V_5 -> V_149 ) ;
if ( V_82 )
goto V_150;
V_5 -> V_151 = F_91 ( & V_117 -> V_17 , L_11 ) ;
if ( F_92 ( V_5 -> V_151 ) ) {
F_41 ( V_5 -> V_17 , L_12 ) ;
V_82 = F_93 ( V_5 -> V_151 ) ;
goto V_150;
}
V_82 = F_94 ( V_5 -> V_151 ) ;
if ( V_82 )
goto V_152;
V_55 = F_95 ( V_117 -> V_17 . V_138 , 0 ) ;
if ( ! V_55 ) {
F_41 ( V_5 -> V_17 , L_13 ) ;
V_82 = - V_153 ;
goto V_152;
}
V_5 -> V_63 . V_141 = V_55 ;
V_55 = F_95 ( V_117 -> V_17 . V_138 , 1 ) ;
if ( ! V_55 ) {
F_41 ( V_5 -> V_17 , L_13 ) ;
V_82 = - V_153 ;
goto V_152;
}
V_5 -> V_63 . V_145 = V_55 ;
V_5 -> V_8 = F_96 ( & V_117 -> V_17 , & V_44 ) ;
if ( F_92 ( V_5 -> V_8 ) ) {
V_82 = F_93 ( V_5 -> V_8 ) ;
goto V_152;
}
return 0 ;
V_152:
F_97 ( V_5 -> V_151 ) ;
V_150:
F_97 ( V_5 -> V_149 ) ;
return V_82 ;
}
static int F_98 ( struct V_4 * V_5 ,
struct V_154 * V_155 ,
int * V_19 )
{
T_5 V_156 = V_155 -> V_47 ;
T_5 V_157 = V_155 -> V_157 ;
T_5 V_158 = V_155 -> V_157 + V_155 -> V_38 ;
T_5 V_159 = V_155 -> V_159 ;
T_1 V_47 = V_160 | V_161 ;
T_5 V_10 ;
T_5 V_38 ;
int V_162 = * V_19 ;
if ( V_156 & V_163 )
V_47 |= V_164 ;
if ( V_157 > 0 ) {
unsigned long V_165 = F_99 ( V_157 ) ;
T_5 V_166 = 1ULL << V_165 ;
V_38 = F_100 ( V_155 -> V_38 , V_166 ) ;
} else {
V_38 = V_155 -> V_38 ;
}
V_38 = F_100 ( V_38 , 1ULL << 32 ) ;
V_10 = F_24 ( V_38 ) - 1 ;
V_10 &= ~ 0xf ;
while ( V_157 < V_158 ) {
F_3 ( V_5 , F_29 ( V_159 ) , F_101 ( V_162 ) ) ;
F_3 ( V_5 , F_29 ( V_157 ) , F_102 ( V_162 ) ) ;
F_3 ( V_5 , F_29 ( V_10 ) | V_47 , F_103 ( V_162 ) ) ;
F_3 ( V_5 , F_27 ( V_159 ) , F_101 ( V_162 + 1 ) ) ;
F_3 ( V_5 , F_27 ( V_157 ) , F_102 ( V_162 + 1 ) ) ;
F_3 ( V_5 , 0 , F_103 ( V_162 + 1 ) ) ;
V_159 += V_38 ;
V_157 += V_38 ;
V_162 += 2 ;
if ( V_162 > V_167 ) {
F_41 ( V_5 -> V_17 , L_14 ) ;
return - V_123 ;
}
}
* V_19 = V_162 ;
return 0 ;
}
static int F_104 ( struct V_168 * V_169 ,
struct V_170 * V_171 )
{
const int V_172 = 3 , V_173 = 2 ;
int V_174 ;
V_169 -> V_171 = V_171 ;
V_169 -> V_175 = F_105 ( V_171 ) ;
V_169 -> V_176 = V_169 -> V_175 + V_172 + V_173 ;
V_169 -> V_155 = F_106 ( V_171 , L_15 , & V_174 ) ;
if ( ! V_169 -> V_155 )
return - V_153 ;
V_169 -> V_177 = V_169 -> V_155 + V_174 / sizeof( V_178 ) ;
return 0 ;
}
static int F_107 ( struct V_4 * V_5 ,
struct V_170 * V_176 )
{
struct V_154 V_155 ;
struct V_168 V_169 ;
int V_19 = 0 ;
int V_82 ;
if ( F_104 ( & V_169 , V_176 ) )
return - V_123 ;
F_108 (&parser, &range) {
T_5 V_177 = V_155 . V_157 + V_155 . V_38 - 1 ;
F_19 ( V_5 -> V_17 , L_16 ,
V_155 . V_47 , V_155 . V_157 , V_177 , V_155 . V_159 ) ;
V_82 = F_98 ( V_5 , & V_155 , & V_19 ) ;
if ( V_82 )
return V_82 ;
}
return 0 ;
}
static int F_109 ( struct V_4 * V_53 )
{
int V_82 ;
struct V_179 * V_17 = V_53 -> V_17 ;
struct V_170 * V_176 = V_17 -> V_138 ;
T_2 V_180 ;
struct V_54 * V_42 ;
V_82 = F_110 ( V_176 , 0 , 0xff , & V_53 -> V_181 , & V_180 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_111 ( V_17 , & V_53 -> V_181 ) ;
if ( V_82 )
goto V_182;
F_32 (win, &pci->resources) {
struct V_43 * V_44 = V_42 -> V_44 ;
if ( F_33 ( V_44 ) == V_48 ) {
V_82 = F_112 ( V_44 , V_180 ) ;
if ( V_82 )
F_113 ( V_17 , L_17 ,
V_82 , V_44 ) ;
}
}
return 0 ;
V_182:
F_114 ( & V_53 -> V_181 ) ;
return V_82 ;
}
static int F_115 ( struct V_135 * V_117 )
{
struct V_4 * V_5 ;
unsigned int V_11 ;
const struct V_183 * V_184 ;
int V_82 ;
int (* F_116)( struct V_4 * );
V_5 = F_117 ( & V_117 -> V_17 , sizeof( * V_5 ) , V_147 ) ;
if ( ! V_5 )
return - V_140 ;
V_5 -> V_17 = & V_117 -> V_17 ;
F_118 ( V_117 , V_5 ) ;
F_119 ( & V_5 -> V_181 ) ;
F_109 ( V_5 ) ;
V_82 = F_89 ( V_117 , V_5 ) ;
if ( V_82 < 0 ) {
F_41 ( & V_117 -> V_17 , L_18 , V_82 ) ;
return V_82 ;
}
V_82 = F_107 ( V_5 , V_117 -> V_17 . V_138 ) ;
if ( V_82 )
return V_82 ;
V_184 = F_120 ( V_185 , V_5 -> V_17 ) ;
if ( ! V_184 || ! V_184 -> V_11 )
return - V_123 ;
F_116 = V_184 -> V_11 ;
F_121 ( V_5 -> V_17 ) ;
V_82 = F_122 ( V_5 -> V_17 ) ;
if ( V_82 < 0 ) {
F_41 ( V_5 -> V_17 , L_19 ) ;
goto V_186;
}
V_82 = F_116 ( V_5 ) ;
if ( V_82 ) {
F_71 ( & V_117 -> V_17 , L_20 ) ;
V_82 = 0 ;
goto V_187;
}
V_11 = F_5 ( V_5 , V_188 ) ;
F_71 ( & V_117 -> V_17 , L_21 , ( V_11 >> 20 ) & 0x3f ) ;
if ( F_38 ( V_61 ) ) {
V_82 = F_81 ( V_5 ) ;
if ( V_82 < 0 ) {
F_41 ( & V_117 -> V_17 ,
L_22 ,
V_82 ) ;
goto V_187;
}
}
V_82 = F_35 ( V_5 ) ;
if ( V_82 )
goto V_187;
return 0 ;
V_187:
F_123 ( V_5 -> V_17 ) ;
V_186:
F_124 ( V_5 -> V_17 ) ;
return V_82 ;
}
