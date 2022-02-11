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
static void F_21 ( int V_42 , struct V_4 * V_5 )
{
struct V_43 * V_44 = & V_5 -> V_44 [ V_42 ] ;
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
static int F_31 ( struct V_52 * V_43 , struct V_4 * V_5 )
{
struct V_43 * V_44 ;
int V_53 ;
V_5 -> V_23 = V_5 -> V_54 . V_49 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_44 = & V_5 -> V_44 [ V_53 ] ;
if ( ! V_44 -> V_47 )
continue;
F_21 ( V_53 , V_5 ) ;
if ( V_44 -> V_47 & V_48 ) {
T_3 V_56 = F_26 ( V_44 -> V_49 ) ;
F_32 ( V_57 , V_56 ) ;
V_57 += V_58 ;
}
F_33 ( V_43 , V_44 ) ;
}
F_33 ( V_43 , & V_5 -> V_54 ) ;
return 1 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_14 * V_15 , * V_59 ;
F_35 ( V_44 ) ;
F_31 ( & V_44 , V_5 ) ;
if ( ! F_36 ( V_60 ) )
F_37 ( V_61 | V_62 ) ;
if ( F_38 ( V_63 ) )
V_15 = F_39 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_64 , V_5 , & V_44 , & V_5 -> V_65 . V_3 ) ;
else
V_15 = F_40 ( V_5 -> V_17 , V_5 -> V_23 ,
& V_64 , V_5 , & V_44 ) ;
if ( ! V_15 ) {
F_41 ( V_5 -> V_17 , L_3 ) ;
return - V_66 ;
}
F_42 ( V_67 , V_68 ) ;
if ( ! F_36 ( V_60 ) ) {
F_43 ( V_15 ) ;
F_44 ( V_15 ) ;
F_45 (child, &bus->children, node)
F_46 ( V_59 ) ;
}
F_47 ( V_15 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
unsigned int V_69 = 100 ;
while ( V_69 -- ) {
if ( F_5 ( V_5 , V_70 ) & V_71 )
return 0 ;
F_49 ( 100 ) ;
}
F_41 ( V_5 -> V_17 , L_4 ) ;
return - V_72 ;
}
static void F_50 ( struct V_4 * V_5 ,
unsigned int V_73 , unsigned int V_74 ,
unsigned int V_75 , unsigned int V_11 )
{
unsigned long V_76 ;
V_76 = V_77 |
( ( V_73 & 1 ) << V_78 ) |
( ( V_75 & 0xf ) << V_79 ) |
( ( V_74 & 0xff ) << V_80 ) ;
F_3 ( V_5 , V_11 , V_81 ) ;
F_3 ( V_5 , V_76 , V_70 ) ;
F_48 ( V_5 ) ;
F_3 ( V_5 , 0 , V_81 ) ;
F_3 ( V_5 , 0 , V_70 ) ;
F_48 ( V_5 ) ;
}
static int F_51 ( struct V_4 * V_5 )
{
unsigned int V_69 = 10 ;
while ( V_69 -- ) {
if ( ( F_5 ( V_5 , V_82 ) & V_83 ) )
return 0 ;
F_52 ( 5 ) ;
}
return - V_72 ;
}
static int F_53 ( struct V_4 * V_5 )
{
int V_84 ;
F_3 ( V_5 , 0 , V_85 ) ;
F_3 ( V_5 , 1 , V_86 ) ;
F_3 ( V_5 , V_87 << 16 , V_88 ) ;
F_7 ( V_5 , F_17 ( V_89 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_17 ( V_90 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_54 ( 0 ) , 0xff , V_91 ) ;
F_7 ( V_5 , F_54 ( V_92 ) ,
V_93 , V_94 << 4 ) ;
F_7 ( V_5 , F_17 ( V_95 ) , 0x7f ,
V_96 ) ;
F_7 ( V_5 , F_54 ( V_97 ) , V_98 ,
V_98 ) ;
F_7 ( V_5 , F_54 ( V_99 ) , V_100 , 0 ) ;
F_7 ( V_5 , V_101 + 1 , 0x3f , 50 ) ;
F_7 ( V_5 , F_55 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_38 ( V_63 ) )
F_3 ( V_5 , 0x801f0000 , V_102 ) ;
F_3 ( V_5 , V_103 , V_85 ) ;
V_84 = F_51 ( V_5 ) ;
if ( V_84 )
return V_84 ;
F_7 ( V_5 , V_104 , 0 , 0xF << 8 ) ;
F_56 () ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
unsigned int V_69 = 10 ;
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
while ( V_69 -- ) {
if ( F_5 ( V_5 , V_105 ) )
return F_53 ( V_5 ) ;
F_52 ( 5 ) ;
}
return - V_72 ;
}
static int F_58 ( struct V_1 * V_3 )
{
int V_65 ;
F_59 ( & V_3 -> V_106 ) ;
V_65 = F_60 ( V_3 -> V_107 , V_108 ) ;
if ( V_65 < V_108 )
F_61 ( V_65 , V_3 -> V_107 ) ;
else
V_65 = - V_109 ;
F_62 ( & V_3 -> V_106 ) ;
return V_65 ;
}
static void F_63 ( struct V_1 * V_3 , unsigned long V_110 )
{
F_59 ( & V_3 -> V_106 ) ;
F_64 ( V_110 , V_3 -> V_107 ) ;
F_62 ( & V_3 -> V_106 ) ;
}
static T_4 F_65 ( int V_110 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
struct V_1 * V_65 = & V_5 -> V_65 ;
unsigned long V_7 ;
V_7 = F_5 ( V_5 , V_111 ) ;
if ( ! V_7 )
return V_112 ;
while ( V_7 ) {
unsigned int V_19 = F_66 ( & V_7 , 32 ) ;
unsigned int V_110 ;
F_3 ( V_5 , 1 << V_19 , V_111 ) ;
V_110 = F_67 ( V_65 -> V_113 , V_19 ) ;
if ( V_110 ) {
if ( F_68 ( V_19 , V_65 -> V_107 ) )
F_69 ( V_110 ) ;
else
F_70 ( V_5 -> V_17 , L_5 ) ;
} else {
F_19 ( V_5 -> V_17 , L_6 ) ;
}
V_7 = F_5 ( V_5 , V_111 ) ;
}
return V_114 ;
}
static int F_71 ( struct V_2 * V_3 , struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_1 * V_65 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_65 . V_3 ) ;
struct V_119 V_120 ;
unsigned int V_110 ;
int V_121 ;
V_121 = F_58 ( V_65 ) ;
if ( V_121 < 0 )
return V_121 ;
V_110 = F_72 ( V_65 -> V_113 , V_121 ) ;
if ( ! V_110 ) {
F_63 ( V_65 , V_121 ) ;
return - V_122 ;
}
F_73 ( V_110 , V_118 ) ;
V_120 . V_123 = F_5 ( V_5 , V_124 ) & ~ V_125 ;
V_120 . V_126 = F_5 ( V_5 , V_127 ) ;
V_120 . V_11 = V_121 ;
F_74 ( V_110 , & V_120 ) ;
return 0 ;
}
static void F_75 ( struct V_2 * V_3 , unsigned int V_110 )
{
struct V_1 * V_65 = F_1 ( V_3 ) ;
struct V_128 * V_129 = F_76 ( V_110 ) ;
F_63 ( V_65 , V_129 -> V_121 ) ;
}
static int F_77 ( struct V_130 * V_113 , unsigned int V_110 ,
T_5 V_121 )
{
F_78 ( V_110 , & V_131 , V_132 ) ;
F_79 ( V_110 , V_113 -> V_133 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 )
{
struct V_134 * V_116 = F_81 ( V_5 -> V_17 ) ;
struct V_1 * V_65 = & V_5 -> V_65 ;
unsigned long V_8 ;
int V_84 ;
F_82 ( & V_65 -> V_106 ) ;
V_65 -> V_3 . V_17 = V_5 -> V_17 ;
V_65 -> V_3 . V_135 = F_71 ;
V_65 -> V_3 . V_136 = F_75 ;
V_65 -> V_113 = F_83 ( V_5 -> V_17 -> V_137 , V_108 ,
& V_138 , & V_65 -> V_3 ) ;
if ( ! V_65 -> V_113 ) {
F_41 ( & V_116 -> V_17 , L_7 ) ;
return - V_139 ;
}
V_84 = F_84 ( & V_116 -> V_17 , V_65 -> V_140 , F_65 ,
V_141 , V_131 . V_142 , V_5 ) ;
if ( V_84 < 0 ) {
F_41 ( & V_116 -> V_17 , L_8 , V_84 ) ;
goto V_84;
}
V_84 = F_84 ( & V_116 -> V_17 , V_65 -> V_143 , F_65 ,
V_141 , V_131 . V_142 , V_5 ) ;
if ( V_84 < 0 ) {
F_41 ( & V_116 -> V_17 , L_8 , V_84 ) ;
goto V_84;
}
V_65 -> V_144 = F_85 ( V_145 , 0 ) ;
V_8 = F_86 ( ( void * ) V_65 -> V_144 ) ;
F_3 ( V_5 , V_8 | V_125 , V_124 ) ;
F_3 ( V_5 , 0 , V_127 ) ;
F_3 ( V_5 , 0xffffffff , V_146 ) ;
return 0 ;
V_84:
F_87 ( V_65 -> V_113 ) ;
return V_84 ;
}
static int F_88 ( struct V_134 * V_116 ,
struct V_4 * V_5 )
{
struct V_43 V_44 ;
int V_84 , V_53 ;
V_84 = F_89 ( V_116 -> V_17 . V_137 , 0 , & V_44 ) ;
if ( V_84 )
return V_84 ;
V_5 -> V_147 = F_90 ( & V_116 -> V_17 , L_9 ) ;
if ( F_91 ( V_5 -> V_147 ) ) {
F_41 ( V_5 -> V_17 , L_10 ) ;
return F_92 ( V_5 -> V_147 ) ;
}
V_84 = F_93 ( V_5 -> V_147 ) ;
if ( V_84 )
goto V_148;
V_5 -> V_149 = F_90 ( & V_116 -> V_17 , L_11 ) ;
if ( F_91 ( V_5 -> V_149 ) ) {
F_41 ( V_5 -> V_17 , L_12 ) ;
V_84 = F_92 ( V_5 -> V_149 ) ;
goto V_148;
}
V_84 = F_93 ( V_5 -> V_149 ) ;
if ( V_84 )
goto V_150;
V_53 = F_94 ( V_116 -> V_17 . V_137 , 0 ) ;
if ( ! V_53 ) {
F_41 ( V_5 -> V_17 , L_13 ) ;
V_84 = - V_151 ;
goto V_150;
}
V_5 -> V_65 . V_140 = V_53 ;
V_53 = F_94 ( V_116 -> V_17 . V_137 , 1 ) ;
if ( ! V_53 ) {
F_41 ( V_5 -> V_17 , L_13 ) ;
V_84 = - V_151 ;
goto V_150;
}
V_5 -> V_65 . V_143 = V_53 ;
V_5 -> V_8 = F_95 ( & V_116 -> V_17 , & V_44 ) ;
if ( F_91 ( V_5 -> V_8 ) ) {
V_84 = F_92 ( V_5 -> V_8 ) ;
goto V_150;
}
return 0 ;
V_150:
F_96 ( V_5 -> V_149 ) ;
V_148:
F_96 ( V_5 -> V_147 ) ;
return V_84 ;
}
static int F_97 ( struct V_4 * V_5 ,
struct V_152 * V_153 ,
int * V_19 )
{
T_6 V_154 = V_153 -> V_47 ;
T_6 V_155 = V_153 -> V_155 ;
T_6 V_156 = V_153 -> V_155 + V_153 -> V_38 ;
T_6 V_157 = V_153 -> V_157 ;
T_1 V_47 = V_158 | V_159 ;
T_6 V_10 ;
T_6 V_38 ;
int V_160 = * V_19 ;
if ( V_154 & V_161 )
V_47 |= V_162 ;
if ( V_155 > 0 ) {
unsigned long V_163 = F_98 ( V_155 ) ;
T_6 V_164 = 1ULL << V_163 ;
V_38 = F_99 ( V_153 -> V_38 , V_164 ) ;
} else {
V_38 = V_153 -> V_38 ;
}
V_38 = F_99 ( V_38 , 1ULL << 32 ) ;
V_10 = F_24 ( V_38 ) - 1 ;
V_10 &= ~ 0xf ;
while ( V_155 < V_156 ) {
F_3 ( V_5 , F_29 ( V_157 ) , F_100 ( V_160 ) ) ;
F_3 ( V_5 , F_29 ( V_155 ) , F_101 ( V_160 ) ) ;
F_3 ( V_5 , F_29 ( V_10 ) | V_47 , F_102 ( V_160 ) ) ;
F_3 ( V_5 , F_27 ( V_157 ) , F_100 ( V_160 + 1 ) ) ;
F_3 ( V_5 , F_27 ( V_155 ) , F_101 ( V_160 + 1 ) ) ;
F_3 ( V_5 , 0 , F_102 ( V_160 + 1 ) ) ;
V_157 += V_38 ;
V_155 += V_38 ;
V_160 += 2 ;
if ( V_160 > V_165 ) {
F_41 ( V_5 -> V_17 , L_14 ) ;
return - V_122 ;
}
}
* V_19 = V_160 ;
return 0 ;
}
static int F_103 ( struct V_166 * V_167 ,
struct V_168 * V_169 )
{
const int V_170 = 3 , V_171 = 2 ;
int V_172 ;
V_167 -> V_169 = V_169 ;
V_167 -> V_173 = F_104 ( V_169 ) ;
V_167 -> V_174 = V_167 -> V_173 + V_170 + V_171 ;
V_167 -> V_153 = F_105 ( V_169 , L_15 , & V_172 ) ;
if ( ! V_167 -> V_153 )
return - V_151 ;
V_167 -> V_175 = V_167 -> V_153 + V_172 / sizeof( V_176 ) ;
return 0 ;
}
static int F_106 ( struct V_4 * V_5 ,
struct V_168 * V_174 )
{
struct V_152 V_153 ;
struct V_166 V_167 ;
int V_19 = 0 ;
int V_84 ;
if ( F_103 ( & V_167 , V_174 ) )
return - V_122 ;
F_107 (&parser, &range) {
T_6 V_175 = V_153 . V_155 + V_153 . V_38 - 1 ;
F_19 ( V_5 -> V_17 , L_16 ,
V_153 . V_47 , V_153 . V_155 , V_175 , V_153 . V_157 ) ;
V_84 = F_97 ( V_5 , & V_153 , & V_19 ) ;
if ( V_84 )
return V_84 ;
}
return 0 ;
}
static int F_108 ( struct V_134 * V_116 )
{
struct V_4 * V_5 ;
unsigned int V_11 ;
struct V_152 V_153 ;
struct V_166 V_167 ;
const struct V_177 * V_178 ;
int V_84 , V_42 = 0 ;
int (* F_109)( struct V_4 * );
V_5 = F_110 ( & V_116 -> V_17 , sizeof( * V_5 ) , V_145 ) ;
if ( ! V_5 )
return - V_139 ;
V_5 -> V_17 = & V_116 -> V_17 ;
F_111 ( V_116 , V_5 ) ;
if ( F_112 ( V_116 -> V_17 . V_137 , & V_5 -> V_54 ) ) {
F_41 ( & V_116 -> V_17 , L_17 ) ;
return - V_122 ;
}
if ( F_113 ( & V_167 , V_116 -> V_17 . V_137 ) ) {
F_41 ( & V_116 -> V_17 , L_18 ) ;
return - V_122 ;
}
V_84 = F_88 ( V_116 , V_5 ) ;
if ( V_84 < 0 ) {
F_41 ( & V_116 -> V_17 , L_19 , V_84 ) ;
return V_84 ;
}
F_107 (&parser, &range) {
V_84 = F_114 ( & V_153 , V_116 -> V_17 . V_137 ,
& V_5 -> V_44 [ V_42 ++ ] ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_42 > V_55 )
break;
}
V_84 = F_106 ( V_5 , V_116 -> V_17 . V_137 ) ;
if ( V_84 )
return V_84 ;
if ( F_38 ( V_63 ) ) {
V_84 = F_80 ( V_5 ) ;
if ( V_84 < 0 ) {
F_41 ( & V_116 -> V_17 ,
L_20 ,
V_84 ) ;
return V_84 ;
}
}
V_178 = F_115 ( V_179 , V_5 -> V_17 ) ;
if ( ! V_178 || ! V_178 -> V_11 )
return - V_122 ;
F_109 = V_178 -> V_11 ;
V_84 = F_109 ( V_5 ) ;
if ( V_84 ) {
F_70 ( & V_116 -> V_17 , L_21 ) ;
return 0 ;
}
V_11 = F_5 ( V_5 , V_180 ) ;
F_70 ( & V_116 -> V_17 , L_22 , ( V_11 >> 20 ) & 0x3f ) ;
return F_34 ( V_5 ) ;
}
