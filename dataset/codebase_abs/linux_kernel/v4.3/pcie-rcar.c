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
T_2 V_48 ;
T_1 V_13 ;
F_4 ( V_8 , 0x00000000 , F_23 ( V_45 ) ) ;
V_41 = F_24 ( V_47 ) ;
V_13 = ( F_25 ( V_41 ) / V_49 ) - 1 ;
F_4 ( V_8 , V_13 << 7 , F_26 ( V_45 ) ) ;
if ( V_47 -> V_50 & V_51 )
V_48 = F_27 ( V_47 -> V_52 ) ;
else
V_48 = V_47 -> V_52 ;
F_4 ( V_8 , F_28 ( V_48 ) , F_29 ( V_45 ) ) ;
F_4 ( V_8 , F_30 ( V_48 ) & ~ 0x7F ,
F_31 ( V_45 ) ) ;
V_13 = V_53 ;
if ( V_47 -> V_50 & V_51 )
V_13 |= V_54 ;
F_4 ( V_8 , V_13 , F_23 ( V_45 ) ) ;
}
static int F_32 ( int V_55 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_46 * V_47 ;
int V_56 ;
V_8 -> V_26 = - 1 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_47 = & V_8 -> V_47 [ V_56 ] ;
if ( ! V_47 -> V_50 )
continue;
F_22 ( V_56 , V_8 ) ;
if ( V_47 -> V_50 & V_51 ) {
T_3 V_58 = F_27 ( V_47 -> V_52 ) ;
F_33 ( V_55 * V_59 , V_58 ) ;
} else
F_34 ( & V_6 -> V_60 , V_47 ) ;
}
F_34 ( & V_6 -> V_60 , & V_8 -> V_61 ) ;
return 1 ;
}
static void F_35 ( struct V_4 * V_8 )
{
struct V_62 * V_63 = F_36 ( V_8 -> V_20 ) ;
V_64 . V_65 = 1 ;
V_64 . V_7 = ( void * * ) & V_8 ;
#ifdef F_37
V_64 . V_66 = & V_8 -> V_67 . V_3 ;
#endif
F_38 ( & V_63 -> V_20 , & V_64 ) ;
}
static int F_39 ( struct V_4 * V_8 )
{
unsigned int V_68 = 100 ;
while ( V_68 -- ) {
if ( F_6 ( V_8 , V_69 ) & V_70 )
return 0 ;
F_40 ( 100 ) ;
}
F_41 ( V_8 -> V_20 , L_3 ) ;
return - V_71 ;
}
static void F_42 ( struct V_4 * V_8 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 , unsigned int V_14 )
{
unsigned long V_75 ;
V_75 = V_76 |
( ( V_72 & 1 ) << V_77 ) |
( ( V_74 & 0xf ) << V_78 ) |
( ( V_73 & 0xff ) << V_79 ) ;
F_4 ( V_8 , V_14 , V_80 ) ;
F_4 ( V_8 , V_75 , V_69 ) ;
F_39 ( V_8 ) ;
F_4 ( V_8 , 0 , V_80 ) ;
F_4 ( V_8 , 0 , V_69 ) ;
F_39 ( V_8 ) ;
}
static int F_43 ( struct V_4 * V_8 )
{
unsigned int V_68 = 10 ;
while ( V_68 -- ) {
if ( ( F_6 ( V_8 , V_81 ) & V_82 ) )
return 0 ;
F_44 ( 5 ) ;
}
return - V_71 ;
}
static int F_45 ( struct V_4 * V_8 )
{
int V_83 ;
F_4 ( V_8 , 0 , V_84 ) ;
F_4 ( V_8 , 1 , V_85 ) ;
F_4 ( V_8 , V_86 << 16 , V_87 ) ;
F_8 ( V_8 , F_18 ( V_88 ) , 0xff , 1 ) ;
F_8 ( V_8 , F_18 ( V_89 ) , 0xff , 1 ) ;
F_8 ( V_8 , F_46 ( 0 ) , 0xff , V_90 ) ;
F_8 ( V_8 , F_46 ( V_91 ) ,
V_92 , V_93 << 4 ) ;
F_8 ( V_8 , F_18 ( V_94 ) , 0x7f ,
V_95 ) ;
F_8 ( V_8 , F_46 ( V_96 ) , V_97 ,
V_97 ) ;
F_8 ( V_8 , F_46 ( V_98 ) , V_99 , 0 ) ;
F_8 ( V_8 , V_100 + 1 , 0x3f , 50 ) ;
F_8 ( V_8 , F_47 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_48 ( F_37 ) )
F_4 ( V_8 , 0x801f0000 , V_101 ) ;
F_4 ( V_8 , V_102 , V_84 ) ;
V_83 = F_43 ( V_8 ) ;
if ( V_83 )
return V_83 ;
F_8 ( V_8 , V_103 , 0 , 0xF << 8 ) ;
F_49 () ;
return 0 ;
}
static int F_50 ( struct V_4 * V_8 )
{
unsigned int V_68 = 10 ;
F_42 ( V_8 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_42 ( V_8 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_42 ( V_8 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_42 ( V_8 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_42 ( V_8 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_42 ( V_8 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_42 ( V_8 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_42 ( V_8 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_42 ( V_8 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_42 ( V_8 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_42 ( V_8 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_42 ( V_8 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_42 ( V_8 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_42 ( V_8 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_42 ( V_8 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_68 -- ) {
if ( F_6 ( V_8 , V_104 ) )
return F_45 ( V_8 ) ;
F_44 ( 5 ) ;
}
return - V_71 ;
}
static int F_51 ( struct V_1 * V_3 )
{
int V_67 ;
F_52 ( & V_3 -> V_105 ) ;
V_67 = F_53 ( V_3 -> V_106 , V_107 ) ;
if ( V_67 < V_107 )
F_54 ( V_67 , V_3 -> V_106 ) ;
else
V_67 = - V_108 ;
F_55 ( & V_3 -> V_105 ) ;
return V_67 ;
}
static void F_56 ( struct V_1 * V_3 , unsigned long V_109 )
{
F_52 ( & V_3 -> V_105 ) ;
F_57 ( V_109 , V_3 -> V_106 ) ;
F_55 ( & V_3 -> V_105 ) ;
}
static T_4 F_58 ( int V_109 , void * V_14 )
{
struct V_4 * V_8 = V_14 ;
struct V_1 * V_67 = & V_8 -> V_67 ;
unsigned long V_10 ;
V_10 = F_6 ( V_8 , V_110 ) ;
if ( ! V_10 )
return V_111 ;
while ( V_10 ) {
unsigned int V_22 = F_59 ( & V_10 , 32 ) ;
unsigned int V_109 ;
F_4 ( V_8 , 1 << V_22 , V_110 ) ;
V_109 = F_60 ( V_67 -> V_112 , V_22 ) ;
if ( V_109 ) {
if ( F_61 ( V_22 , V_67 -> V_106 ) )
F_62 ( V_109 ) ;
else
F_63 ( V_8 -> V_20 , L_4 ) ;
} else {
F_20 ( V_8 -> V_20 , L_5 ) ;
}
V_10 = F_6 ( V_8 , V_110 ) ;
}
return V_113 ;
}
static int F_64 ( struct V_2 * V_3 , struct V_114 * V_63 ,
struct V_115 * V_116 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
struct V_4 * V_8 = F_2 ( V_3 , struct V_4 , V_67 . V_3 ) ;
struct V_117 V_118 ;
unsigned int V_109 ;
int V_119 ;
V_119 = F_51 ( V_67 ) ;
if ( V_119 < 0 )
return V_119 ;
V_109 = F_65 ( V_67 -> V_112 , V_119 ) ;
if ( ! V_109 ) {
F_56 ( V_67 , V_119 ) ;
return - V_120 ;
}
F_66 ( V_109 , V_116 ) ;
V_118 . V_121 = F_6 ( V_8 , V_122 ) & ~ V_123 ;
V_118 . V_124 = F_6 ( V_8 , V_125 ) ;
V_118 . V_14 = V_119 ;
F_67 ( V_109 , & V_118 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 , unsigned int V_109 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
struct V_126 * V_127 = F_69 ( V_109 ) ;
F_56 ( V_67 , V_127 -> V_119 ) ;
}
static int F_70 ( struct V_128 * V_112 , unsigned int V_109 ,
T_5 V_119 )
{
F_71 ( V_109 , & V_129 , V_130 ) ;
F_72 ( V_109 , V_112 -> V_131 ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_8 )
{
struct V_62 * V_63 = F_36 ( V_8 -> V_20 ) ;
struct V_1 * V_67 = & V_8 -> V_67 ;
unsigned long V_11 ;
int V_83 ;
F_74 ( & V_67 -> V_105 ) ;
V_67 -> V_3 . V_20 = V_8 -> V_20 ;
V_67 -> V_3 . V_132 = F_64 ;
V_67 -> V_3 . V_133 = F_68 ;
V_67 -> V_112 = F_75 ( V_8 -> V_20 -> V_134 , V_107 ,
& V_135 , & V_67 -> V_3 ) ;
if ( ! V_67 -> V_112 ) {
F_41 ( & V_63 -> V_20 , L_6 ) ;
return - V_136 ;
}
V_83 = F_76 ( & V_63 -> V_20 , V_67 -> V_137 , F_58 ,
V_138 , V_129 . V_139 , V_8 ) ;
if ( V_83 < 0 ) {
F_41 ( & V_63 -> V_20 , L_7 , V_83 ) ;
goto V_83;
}
V_83 = F_76 ( & V_63 -> V_20 , V_67 -> V_140 , F_58 ,
V_138 , V_129 . V_139 , V_8 ) ;
if ( V_83 < 0 ) {
F_41 ( & V_63 -> V_20 , L_7 , V_83 ) ;
goto V_83;
}
V_67 -> V_141 = F_77 ( V_142 , 0 ) ;
V_11 = F_78 ( ( void * ) V_67 -> V_141 ) ;
F_4 ( V_8 , V_11 | V_123 , V_122 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
F_4 ( V_8 , 0xffffffff , V_143 ) ;
return 0 ;
V_83:
F_79 ( V_67 -> V_112 ) ;
return V_83 ;
}
static int F_80 ( struct V_62 * V_63 ,
struct V_4 * V_8 )
{
struct V_46 V_47 ;
int V_83 , V_56 ;
V_83 = F_81 ( V_63 -> V_20 . V_134 , 0 , & V_47 ) ;
if ( V_83 )
return V_83 ;
V_8 -> V_144 = F_82 ( & V_63 -> V_20 , L_8 ) ;
if ( F_83 ( V_8 -> V_144 ) ) {
F_41 ( V_8 -> V_20 , L_9 ) ;
return F_84 ( V_8 -> V_144 ) ;
}
V_83 = F_85 ( V_8 -> V_144 ) ;
if ( V_83 )
goto V_145;
V_8 -> V_146 = F_82 ( & V_63 -> V_20 , L_10 ) ;
if ( F_83 ( V_8 -> V_146 ) ) {
F_41 ( V_8 -> V_20 , L_11 ) ;
V_83 = F_84 ( V_8 -> V_146 ) ;
goto V_145;
}
V_83 = F_85 ( V_8 -> V_146 ) ;
if ( V_83 )
goto V_147;
V_56 = F_86 ( V_63 -> V_20 . V_134 , 0 ) ;
if ( ! V_56 ) {
F_41 ( V_8 -> V_20 , L_12 ) ;
V_83 = - V_148 ;
goto V_147;
}
V_8 -> V_67 . V_137 = V_56 ;
V_56 = F_86 ( V_63 -> V_20 . V_134 , 1 ) ;
if ( ! V_56 ) {
F_41 ( V_8 -> V_20 , L_12 ) ;
V_83 = - V_148 ;
goto V_147;
}
V_8 -> V_67 . V_140 = V_56 ;
V_8 -> V_11 = F_87 ( & V_63 -> V_20 , & V_47 ) ;
if ( F_83 ( V_8 -> V_11 ) ) {
V_83 = F_84 ( V_8 -> V_11 ) ;
goto V_147;
}
return 0 ;
V_147:
F_88 ( V_8 -> V_146 ) ;
V_145:
F_88 ( V_8 -> V_144 ) ;
return V_83 ;
}
static int F_89 ( struct V_4 * V_8 ,
struct V_149 * V_150 ,
int * V_22 )
{
T_6 V_151 = V_150 -> V_50 ;
T_6 V_152 = V_150 -> V_152 ;
T_6 V_153 = V_150 -> V_152 + V_150 -> V_41 ;
T_6 V_154 = V_150 -> V_154 ;
T_1 V_50 = V_155 | V_156 ;
T_6 V_13 ;
T_6 V_41 ;
int V_157 = * V_22 ;
if ( V_151 & V_158 )
V_50 |= V_159 ;
if ( V_152 > 0 ) {
unsigned long V_160 = F_90 ( V_152 ) ;
T_6 V_161 = 1ULL << V_160 ;
V_41 = F_91 ( V_150 -> V_41 , V_161 ) ;
} else {
V_41 = V_150 -> V_41 ;
}
V_41 = F_91 ( V_41 , 1ULL << 32 ) ;
V_13 = F_25 ( V_41 ) - 1 ;
V_13 &= ~ 0xf ;
while ( V_152 < V_153 ) {
F_4 ( V_8 , F_30 ( V_154 ) , F_92 ( V_157 ) ) ;
F_4 ( V_8 , F_30 ( V_152 ) , F_93 ( V_157 ) ) ;
F_4 ( V_8 , F_30 ( V_13 ) | V_50 , F_94 ( V_157 ) ) ;
F_4 ( V_8 , F_28 ( V_154 ) , F_92 ( V_157 + 1 ) ) ;
F_4 ( V_8 , F_28 ( V_152 ) , F_93 ( V_157 + 1 ) ) ;
F_4 ( V_8 , 0 , F_94 ( V_157 + 1 ) ) ;
V_154 += V_41 ;
V_152 += V_41 ;
V_157 += 2 ;
if ( V_157 > V_162 ) {
F_41 ( V_8 -> V_20 , L_13 ) ;
return - V_120 ;
}
}
* V_22 = V_157 ;
return 0 ;
}
static int F_95 ( struct V_163 * V_164 ,
struct V_165 * V_166 )
{
const int V_167 = 3 , V_168 = 2 ;
int V_169 ;
V_164 -> V_166 = V_166 ;
V_164 -> V_170 = F_96 ( V_166 ) ;
V_164 -> V_171 = V_164 -> V_170 + V_167 + V_168 ;
V_164 -> V_150 = F_97 ( V_166 , L_14 , & V_169 ) ;
if ( ! V_164 -> V_150 )
return - V_148 ;
V_164 -> V_172 = V_164 -> V_150 + V_169 / sizeof( V_173 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_8 ,
struct V_165 * V_171 )
{
struct V_149 V_150 ;
struct V_163 V_164 ;
int V_22 = 0 ;
int V_83 ;
if ( F_95 ( & V_164 , V_171 ) )
return - V_120 ;
F_99 (&parser, &range) {
T_6 V_172 = V_150 . V_152 + V_150 . V_41 - 1 ;
F_20 ( V_8 -> V_20 , L_15 ,
V_150 . V_50 , V_150 . V_152 , V_172 , V_150 . V_154 ) ;
V_83 = F_89 ( V_8 , & V_150 , & V_22 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static int F_100 ( struct V_62 * V_63 )
{
struct V_4 * V_8 ;
unsigned int V_14 ;
struct V_149 V_150 ;
struct V_163 V_164 ;
const struct V_174 * V_175 ;
int V_83 , V_45 = 0 ;
int (* F_101)( struct V_4 * );
V_8 = F_102 ( & V_63 -> V_20 , sizeof( * V_8 ) , V_142 ) ;
if ( ! V_8 )
return - V_136 ;
V_8 -> V_20 = & V_63 -> V_20 ;
F_103 ( V_63 , V_8 ) ;
if ( F_104 ( V_63 -> V_20 . V_134 , & V_8 -> V_61 ) ) {
F_41 ( & V_63 -> V_20 , L_16 ) ;
return - V_120 ;
}
if ( F_105 ( & V_164 , V_63 -> V_20 . V_134 ) ) {
F_41 ( & V_63 -> V_20 , L_17 ) ;
return - V_120 ;
}
V_83 = F_80 ( V_63 , V_8 ) ;
if ( V_83 < 0 ) {
F_41 ( & V_63 -> V_20 , L_18 , V_83 ) ;
return V_83 ;
}
F_99 (&parser, &range) {
V_83 = F_106 ( & V_150 , V_63 -> V_20 . V_134 ,
& V_8 -> V_47 [ V_45 ++ ] ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_45 > V_57 )
break;
}
V_83 = F_98 ( V_8 , V_63 -> V_20 . V_134 ) ;
if ( V_83 )
return V_83 ;
if ( F_48 ( F_37 ) ) {
V_83 = F_73 ( V_8 ) ;
if ( V_83 < 0 ) {
F_41 ( & V_63 -> V_20 ,
L_19 ,
V_83 ) ;
return V_83 ;
}
}
V_175 = F_107 ( V_176 , V_8 -> V_20 ) ;
if ( ! V_175 || ! V_175 -> V_14 )
return - V_120 ;
F_101 = V_175 -> V_14 ;
V_83 = F_101 ( V_8 ) ;
if ( V_83 ) {
F_63 ( & V_63 -> V_20 , L_20 ) ;
return 0 ;
}
V_14 = F_6 ( V_8 , V_177 ) ;
F_63 ( & V_63 -> V_20 , L_21 , ( V_14 >> 20 ) & 0x3f ) ;
F_35 ( V_8 ) ;
return 0 ;
}
