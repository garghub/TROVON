static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ;
}
static void F_4 ( struct V_4 * V_8 , unsigned long V_9 ,
unsigned long V_10 )
{
F_5 ( V_9 , V_8 -> V_11 + V_10 ) ;
}
static unsigned long F_6 ( struct V_4 * V_8 ,
unsigned long V_10 )
{
return F_7 ( V_8 -> V_11 + V_10 ) ;
}
static void F_8 ( struct V_4 * V_8 , int V_12 , T_1 V_13 , T_1 V_14 )
{
int V_15 = 8 * ( V_12 & 3 ) ;
T_1 V_9 = F_6 ( V_8 , V_12 & ~ 3 ) ;
V_9 &= ~ ( V_13 << V_15 ) ;
V_9 |= V_14 << V_15 ;
F_4 ( V_8 , V_9 , V_12 & ~ 3 ) ;
}
static T_1 F_9 ( struct V_4 * V_8 , int V_12 )
{
int V_15 = 8 * ( V_12 & 3 ) ;
T_1 V_9 = F_6 ( V_8 , V_12 & ~ 3 ) ;
return V_9 >> V_15 ;
}
static int F_10 ( struct V_4 * V_8 ,
unsigned char V_16 , struct V_17 * V_18 ,
unsigned int V_19 , int V_12 , T_1 * V_14 )
{
int V_20 , V_21 , V_10 , V_22 ;
V_20 = F_11 ( V_19 ) ;
V_21 = F_12 ( V_19 ) ;
V_10 = V_12 & ~ 3 ;
V_22 = V_10 / 4 ;
if ( F_13 ( V_18 ) ) {
if ( V_20 != 0 )
return V_23 ;
if ( V_16 == V_24 ) {
* V_14 = F_6 ( V_8 , F_14 ( V_22 ) ) ;
} else {
if ( F_13 ( V_18 ) && ( V_10 == V_25 ) )
V_8 -> V_26 = * V_14 & 0xff ;
F_4 ( V_8 , * V_14 , F_14 ( V_22 ) ) ;
}
return V_27 ;
}
if ( V_8 -> V_26 < 0 )
return V_23 ;
F_4 ( V_8 , F_6 ( V_8 , V_28 ) , V_28 ) ;
F_4 ( V_8 , F_15 ( V_18 -> V_29 ) |
F_16 ( V_20 ) | F_17 ( V_21 ) | V_10 , V_30 ) ;
if ( V_18 -> V_31 -> V_29 == V_8 -> V_26 )
F_4 ( V_8 , V_32 | V_33 , V_34 ) ;
else
F_4 ( V_8 , V_32 | V_35 , V_34 ) ;
if ( F_6 ( V_8 , V_28 ) & V_36 )
return V_23 ;
if ( F_9 ( V_8 , F_18 ( V_37 ) ) &
( V_38 | V_39 ) )
return V_23 ;
if ( V_16 == V_24 )
* V_14 = F_6 ( V_8 , V_40 ) ;
else
F_4 ( V_8 , * V_14 , V_40 ) ;
F_4 ( V_8 , 0 , V_34 ) ;
return V_27 ;
}
static int F_19 ( struct V_17 * V_18 , unsigned int V_19 ,
int V_12 , int V_41 , T_1 * V_9 )
{
struct V_4 * V_8 = F_3 ( V_18 -> V_42 ) ;
int V_43 ;
V_43 = F_10 ( V_8 , V_24 ,
V_18 , V_19 , V_12 , V_9 ) ;
if ( V_43 != V_27 ) {
* V_9 = 0xffffffff ;
return V_43 ;
}
if ( V_41 == 1 )
* V_9 = ( * V_9 >> ( 8 * ( V_12 & 3 ) ) ) & 0xff ;
else if ( V_41 == 2 )
* V_9 = ( * V_9 >> ( 8 * ( V_12 & 2 ) ) ) & 0xffff ;
F_20 ( & V_18 -> V_20 , L_1 ,
V_18 -> V_29 , V_19 , V_12 , V_41 , ( unsigned long ) * V_9 ) ;
return V_43 ;
}
static int F_21 ( struct V_17 * V_18 , unsigned int V_19 ,
int V_12 , int V_41 , T_1 V_9 )
{
struct V_4 * V_8 = F_3 ( V_18 -> V_42 ) ;
int V_15 , V_43 ;
T_1 V_14 ;
V_43 = F_10 ( V_8 , V_24 ,
V_18 , V_19 , V_12 , & V_14 ) ;
if ( V_43 != V_27 )
return V_43 ;
F_20 ( & V_18 -> V_20 , L_2 ,
V_18 -> V_29 , V_19 , V_12 , V_41 , ( unsigned long ) V_9 ) ;
if ( V_41 == 1 ) {
V_15 = 8 * ( V_12 & 3 ) ;
V_14 &= ~ ( 0xff << V_15 ) ;
V_14 |= ( ( V_9 & 0xff ) << V_15 ) ;
} else if ( V_41 == 2 ) {
V_15 = 8 * ( V_12 & 2 ) ;
V_14 &= ~ ( 0xffff << V_15 ) ;
V_14 |= ( ( V_9 & 0xffff ) << V_15 ) ;
} else
V_14 = V_9 ;
V_43 = F_10 ( V_8 , V_44 ,
V_18 , V_19 , V_12 , & V_14 ) ;
return V_43 ;
}
static void F_22 ( int V_45 , struct V_4 * V_8 )
{
struct V_46 * V_47 = & V_8 -> V_47 [ V_45 ] ;
T_2 V_41 ;
T_1 V_13 ;
F_4 ( V_8 , 0x00000000 , F_23 ( V_45 ) ) ;
V_41 = F_24 ( V_47 ) ;
V_13 = ( F_25 ( V_41 ) / V_48 ) - 1 ;
F_4 ( V_8 , V_13 << 7 , F_26 ( V_45 ) ) ;
F_4 ( V_8 , F_27 ( V_47 -> V_49 ) , F_28 ( V_45 ) ) ;
F_4 ( V_8 , F_29 ( V_47 -> V_49 ) , F_30 ( V_45 ) ) ;
V_13 = V_50 ;
if ( V_47 -> V_51 & V_52 )
V_13 |= V_53 ;
F_4 ( V_8 , V_13 , F_23 ( V_45 ) ) ;
}
static int F_31 ( int V_54 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_46 * V_47 ;
int V_55 ;
V_8 -> V_26 = - 1 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_47 = & V_8 -> V_47 [ V_55 ] ;
if ( ! V_47 -> V_51 )
continue;
F_22 ( V_55 , V_8 ) ;
if ( V_47 -> V_51 & V_52 )
F_32 ( V_54 * V_57 , V_47 -> V_49 ) ;
else
F_33 ( & V_6 -> V_58 , V_47 ) ;
}
F_33 ( & V_6 -> V_58 , & V_8 -> V_59 ) ;
return 1 ;
}
static void F_34 ( struct V_17 * V_18 )
{
if ( F_35 ( V_60 ) ) {
struct V_4 * V_8 = F_3 ( V_18 -> V_42 ) ;
V_18 -> V_61 = & V_8 -> V_61 . V_3 ;
}
}
static void F_36 ( struct V_4 * V_8 )
{
struct V_62 * V_63 = F_37 ( V_8 -> V_20 ) ;
V_64 . V_65 = 1 ;
V_64 . V_7 = ( void * * ) & V_8 ;
F_38 ( & V_63 -> V_20 , & V_64 ) ;
#ifdef F_39
V_64 . V_66 ++ ;
#endif
}
static int F_40 ( struct V_4 * V_8 )
{
unsigned int V_67 = 100 ;
while ( V_67 -- ) {
if ( F_6 ( V_8 , V_68 ) & V_69 )
return 0 ;
F_41 ( 100 ) ;
}
F_42 ( V_8 -> V_20 , L_3 ) ;
return - V_70 ;
}
static void F_43 ( struct V_4 * V_8 ,
unsigned int V_71 , unsigned int V_72 ,
unsigned int V_73 , unsigned int V_14 )
{
unsigned long V_74 ;
V_74 = V_75 |
( ( V_71 & 1 ) << V_76 ) |
( ( V_73 & 0xf ) << V_77 ) |
( ( V_72 & 0xff ) << V_78 ) ;
F_4 ( V_8 , V_14 , V_79 ) ;
F_4 ( V_8 , V_74 , V_68 ) ;
F_40 ( V_8 ) ;
F_4 ( V_8 , 0 , V_79 ) ;
F_4 ( V_8 , 0 , V_68 ) ;
F_40 ( V_8 ) ;
}
static int F_44 ( struct V_4 * V_8 )
{
unsigned int V_67 = 10 ;
while ( V_67 -- ) {
if ( ( F_6 ( V_8 , V_80 ) & V_81 ) )
return 0 ;
F_45 ( 5 ) ;
}
return - V_70 ;
}
static int F_46 ( struct V_4 * V_8 )
{
int V_82 ;
F_4 ( V_8 , 0 , V_83 ) ;
F_4 ( V_8 , 1 , V_84 ) ;
F_4 ( V_8 , V_85 << 16 , V_86 ) ;
F_8 ( V_8 , F_18 ( V_87 ) , 0xff , 1 ) ;
F_8 ( V_8 , F_18 ( V_88 ) , 0xff , 1 ) ;
F_8 ( V_8 , F_47 ( 0 ) , 0xff , V_89 ) ;
F_8 ( V_8 , F_47 ( V_90 ) ,
V_91 , V_92 << 4 ) ;
F_8 ( V_8 , F_18 ( V_93 ) , 0x7f ,
V_94 ) ;
F_8 ( V_8 , F_47 ( V_95 ) , V_96 ,
V_96 ) ;
F_8 ( V_8 , F_47 ( V_97 ) , V_98 , 0 ) ;
F_8 ( V_8 , V_99 + 1 , 0x3f , 50 ) ;
F_8 ( V_8 , F_48 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_35 ( V_60 ) )
F_4 ( V_8 , 0x101f0000 , V_100 ) ;
F_4 ( V_8 , V_101 , V_83 ) ;
V_82 = F_44 ( V_8 ) ;
if ( V_82 )
return V_82 ;
F_8 ( V_8 , V_102 , 0 , 0xF << 8 ) ;
F_49 () ;
return 0 ;
}
static int F_50 ( struct V_4 * V_8 )
{
unsigned int V_67 = 10 ;
F_43 ( V_8 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_43 ( V_8 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_43 ( V_8 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_43 ( V_8 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_43 ( V_8 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_43 ( V_8 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_43 ( V_8 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_43 ( V_8 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_43 ( V_8 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_43 ( V_8 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_43 ( V_8 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_43 ( V_8 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_43 ( V_8 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_43 ( V_8 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_43 ( V_8 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_67 -- ) {
if ( F_6 ( V_8 , V_103 ) )
return F_46 ( V_8 ) ;
F_45 ( 5 ) ;
}
return - V_70 ;
}
static int F_51 ( struct V_1 * V_3 )
{
int V_61 ;
F_52 ( & V_3 -> V_104 ) ;
V_61 = F_53 ( V_3 -> V_105 , V_106 ) ;
if ( V_61 < V_106 )
F_54 ( V_61 , V_3 -> V_105 ) ;
else
V_61 = - V_107 ;
F_55 ( & V_3 -> V_104 ) ;
return V_61 ;
}
static void F_56 ( struct V_1 * V_3 , unsigned long V_108 )
{
F_52 ( & V_3 -> V_104 ) ;
F_57 ( V_108 , V_3 -> V_105 ) ;
F_55 ( & V_3 -> V_104 ) ;
}
static T_3 F_58 ( int V_108 , void * V_14 )
{
struct V_4 * V_8 = V_14 ;
struct V_1 * V_61 = & V_8 -> V_61 ;
unsigned long V_10 ;
V_10 = F_6 ( V_8 , V_109 ) ;
if ( ! V_10 )
return V_110 ;
while ( V_10 ) {
unsigned int V_22 = F_59 ( & V_10 , 32 ) ;
unsigned int V_108 ;
F_4 ( V_8 , 1 << V_22 , V_109 ) ;
V_108 = F_60 ( V_61 -> V_66 , V_22 ) ;
if ( V_108 ) {
if ( F_61 ( V_22 , V_61 -> V_105 ) )
F_62 ( V_108 ) ;
else
F_63 ( V_8 -> V_20 , L_4 ) ;
} else {
F_20 ( V_8 -> V_20 , L_5 ) ;
}
V_10 = F_6 ( V_8 , V_109 ) ;
}
return V_111 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_112 * V_63 ,
struct V_113 * V_114 )
{
struct V_1 * V_61 = F_1 ( V_3 ) ;
struct V_4 * V_8 = F_2 ( V_3 , struct V_4 , V_61 . V_3 ) ;
struct V_115 V_116 ;
unsigned int V_108 ;
int V_117 ;
V_117 = F_51 ( V_61 ) ;
if ( V_117 < 0 )
return V_117 ;
V_108 = F_65 ( V_61 -> V_66 , V_117 ) ;
if ( ! V_108 ) {
F_56 ( V_61 , V_117 ) ;
return - V_118 ;
}
F_66 ( V_108 , V_114 ) ;
V_116 . V_119 = F_6 ( V_8 , V_120 ) & ~ V_121 ;
V_116 . V_122 = F_6 ( V_8 , V_123 ) ;
V_116 . V_14 = V_117 ;
F_67 ( V_108 , & V_116 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 , unsigned int V_108 )
{
struct V_1 * V_61 = F_1 ( V_3 ) ;
struct V_124 * V_125 = F_69 ( V_108 ) ;
F_56 ( V_61 , V_125 -> V_117 ) ;
}
static int F_70 ( struct V_126 * V_66 , unsigned int V_108 ,
T_4 V_117 )
{
F_71 ( V_108 , & V_127 , V_128 ) ;
F_72 ( V_108 , V_66 -> V_129 ) ;
F_73 ( V_108 , V_130 ) ;
return 0 ;
}
static int F_74 ( struct V_4 * V_8 )
{
struct V_62 * V_63 = F_37 ( V_8 -> V_20 ) ;
struct V_1 * V_61 = & V_8 -> V_61 ;
unsigned long V_11 ;
int V_82 ;
F_75 ( & V_61 -> V_104 ) ;
V_61 -> V_3 . V_20 = V_8 -> V_20 ;
V_61 -> V_3 . V_131 = F_64 ;
V_61 -> V_3 . V_132 = F_68 ;
V_61 -> V_66 = F_76 ( V_8 -> V_20 -> V_133 , V_106 ,
& V_134 , & V_61 -> V_3 ) ;
if ( ! V_61 -> V_66 ) {
F_42 ( & V_63 -> V_20 , L_6 ) ;
return - V_135 ;
}
V_82 = F_77 ( & V_63 -> V_20 , V_61 -> V_136 , F_58 ,
V_137 , V_127 . V_138 , V_8 ) ;
if ( V_82 < 0 ) {
F_42 ( & V_63 -> V_20 , L_7 , V_82 ) ;
goto V_82;
}
V_82 = F_77 ( & V_63 -> V_20 , V_61 -> V_139 , F_58 ,
V_137 , V_127 . V_138 , V_8 ) ;
if ( V_82 < 0 ) {
F_42 ( & V_63 -> V_20 , L_7 , V_82 ) ;
goto V_82;
}
V_61 -> V_140 = F_78 ( V_141 , 0 ) ;
V_11 = F_79 ( ( void * ) V_61 -> V_140 ) ;
F_4 ( V_8 , V_11 | V_121 , V_120 ) ;
F_4 ( V_8 , 0 , V_123 ) ;
F_4 ( V_8 , 0xffffffff , V_142 ) ;
return 0 ;
V_82:
F_80 ( V_61 -> V_66 ) ;
return V_82 ;
}
static int F_81 ( struct V_62 * V_63 ,
struct V_4 * V_8 )
{
struct V_46 V_47 ;
int V_82 , V_55 ;
V_82 = F_82 ( V_63 -> V_20 . V_133 , 0 , & V_47 ) ;
if ( V_82 )
return V_82 ;
V_8 -> V_143 = F_83 ( & V_63 -> V_20 , L_8 ) ;
if ( F_84 ( V_8 -> V_143 ) ) {
F_42 ( V_8 -> V_20 , L_9 ) ;
return F_85 ( V_8 -> V_143 ) ;
}
V_82 = F_86 ( V_8 -> V_143 ) ;
if ( V_82 )
goto V_144;
V_8 -> V_145 = F_83 ( & V_63 -> V_20 , L_10 ) ;
if ( F_84 ( V_8 -> V_145 ) ) {
F_42 ( V_8 -> V_20 , L_11 ) ;
V_82 = F_85 ( V_8 -> V_145 ) ;
goto V_144;
}
V_82 = F_86 ( V_8 -> V_145 ) ;
if ( V_82 )
goto V_146;
V_55 = F_87 ( V_63 -> V_20 . V_133 , 0 ) ;
if ( V_55 < 0 ) {
F_42 ( V_8 -> V_20 , L_12 ) ;
V_82 = - V_147 ;
goto V_146;
}
V_8 -> V_61 . V_136 = V_55 ;
V_55 = F_87 ( V_63 -> V_20 . V_133 , 1 ) ;
if ( V_55 < 0 ) {
F_42 ( V_8 -> V_20 , L_12 ) ;
V_82 = - V_147 ;
goto V_146;
}
V_8 -> V_61 . V_139 = V_55 ;
V_8 -> V_11 = F_88 ( & V_63 -> V_20 , & V_47 ) ;
if ( F_84 ( V_8 -> V_11 ) ) {
V_82 = F_85 ( V_8 -> V_11 ) ;
goto V_146;
}
return 0 ;
V_146:
F_89 ( V_8 -> V_145 ) ;
V_144:
F_89 ( V_8 -> V_143 ) ;
return V_82 ;
}
static int F_90 ( struct V_4 * V_8 ,
struct V_148 * V_149 ,
int * V_22 )
{
T_5 V_150 = V_149 -> V_51 ;
T_5 V_151 = V_149 -> V_151 ;
T_5 V_152 = V_149 -> V_151 + V_149 -> V_41 ;
T_5 V_153 = V_149 -> V_153 ;
T_1 V_51 = V_154 | V_155 ;
T_5 V_13 ;
T_5 V_41 ;
int V_156 = * V_22 ;
if ( V_150 & V_157 )
V_51 |= V_158 ;
if ( V_151 > 0 ) {
unsigned long V_159 = F_91 ( V_151 ) ;
T_5 V_160 = 1ULL << V_159 ;
V_41 = F_92 ( V_149 -> V_41 , V_160 ) ;
} else {
V_41 = V_149 -> V_41 ;
}
V_41 = F_92 ( V_41 , 1ULL << 32 ) ;
V_13 = F_25 ( V_41 ) - 1 ;
V_13 &= ~ 0xf ;
while ( V_151 < V_152 ) {
F_4 ( V_8 , F_29 ( V_153 ) , F_93 ( V_156 ) ) ;
F_4 ( V_8 , F_29 ( V_151 ) , F_94 ( V_156 ) ) ;
F_4 ( V_8 , F_29 ( V_13 ) | V_51 , F_95 ( V_156 ) ) ;
F_4 ( V_8 , F_27 ( V_153 ) , F_93 ( V_156 + 1 ) ) ;
F_4 ( V_8 , F_27 ( V_151 ) , F_94 ( V_156 + 1 ) ) ;
F_4 ( V_8 , 0 , F_95 ( V_156 + 1 ) ) ;
V_153 += V_41 ;
V_151 += V_41 ;
V_156 += 2 ;
if ( V_156 > V_161 ) {
F_42 ( V_8 -> V_20 , L_13 ) ;
return - V_118 ;
}
}
* V_22 = V_156 ;
return 0 ;
}
static int F_96 ( struct V_162 * V_163 ,
struct V_164 * V_165 )
{
const int V_166 = 3 , V_167 = 2 ;
int V_168 ;
V_163 -> V_165 = V_165 ;
V_163 -> V_169 = F_97 ( V_165 ) ;
V_163 -> V_170 = V_163 -> V_169 + V_166 + V_167 ;
V_163 -> V_149 = F_98 ( V_165 , L_14 , & V_168 ) ;
if ( ! V_163 -> V_149 )
return - V_147 ;
V_163 -> V_171 = V_163 -> V_149 + V_168 / sizeof( V_172 ) ;
return 0 ;
}
static int F_99 ( struct V_4 * V_8 ,
struct V_164 * V_170 )
{
struct V_148 V_149 ;
struct V_162 V_163 ;
int V_22 = 0 ;
int V_82 ;
if ( F_96 ( & V_163 , V_170 ) )
return - V_118 ;
F_100 (&parser, &range) {
T_5 V_171 = V_149 . V_151 + V_149 . V_41 - 1 ;
F_20 ( V_8 -> V_20 , L_15 ,
V_149 . V_51 , V_149 . V_151 , V_171 , V_149 . V_153 ) ;
V_82 = F_90 ( V_8 , & V_149 , & V_22 ) ;
if ( V_82 )
return V_82 ;
}
return 0 ;
}
static int F_101 ( struct V_62 * V_63 )
{
struct V_4 * V_8 ;
unsigned int V_14 ;
struct V_148 V_149 ;
struct V_162 V_163 ;
const struct V_173 * V_174 ;
int V_82 , V_45 = 0 ;
int (* F_102)( struct V_4 * );
V_8 = F_103 ( & V_63 -> V_20 , sizeof( * V_8 ) , V_141 ) ;
if ( ! V_8 )
return - V_135 ;
V_8 -> V_20 = & V_63 -> V_20 ;
F_104 ( V_63 , V_8 ) ;
if ( F_105 ( V_63 -> V_20 . V_133 , & V_8 -> V_59 ) ) {
F_42 ( & V_63 -> V_20 , L_16 ) ;
return - V_118 ;
}
if ( F_106 ( & V_163 , V_63 -> V_20 . V_133 ) ) {
F_42 ( & V_63 -> V_20 , L_17 ) ;
return - V_118 ;
}
V_82 = F_81 ( V_63 , V_8 ) ;
if ( V_82 < 0 ) {
F_42 ( & V_63 -> V_20 , L_18 , V_82 ) ;
return V_82 ;
}
F_100 (&parser, &range) {
F_107 ( & V_149 , V_63 -> V_20 . V_133 ,
& V_8 -> V_47 [ V_45 ++ ] ) ;
if ( V_45 > V_56 )
break;
}
V_82 = F_99 ( V_8 , V_63 -> V_20 . V_133 ) ;
if ( V_82 )
return V_82 ;
if ( F_35 ( V_60 ) ) {
V_82 = F_74 ( V_8 ) ;
if ( V_82 < 0 ) {
F_42 ( & V_63 -> V_20 ,
L_19 ,
V_82 ) ;
return V_82 ;
}
}
V_174 = F_108 ( V_175 , V_8 -> V_20 ) ;
if ( ! V_174 || ! V_174 -> V_14 )
return - V_118 ;
F_102 = V_174 -> V_14 ;
V_82 = F_102 ( V_8 ) ;
if ( V_82 ) {
F_63 ( & V_63 -> V_20 , L_20 ) ;
return 0 ;
}
V_14 = F_6 ( V_8 , V_176 ) ;
F_63 ( & V_63 -> V_20 , L_21 , ( V_14 >> 20 ) & 0x3f ) ;
F_36 ( V_8 ) ;
return 0 ;
}
