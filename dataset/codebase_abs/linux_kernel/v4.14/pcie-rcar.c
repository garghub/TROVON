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
static void F_35 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
unsigned int V_59 = 1000 ;
T_1 V_60 ;
if ( ( F_5 ( V_5 , V_61 ) & V_62 ) != V_63 )
return;
if ( F_5 ( V_5 , V_64 ) & V_65 ) {
F_36 ( V_17 , L_3 ) ;
return;
}
V_60 = F_5 ( V_5 , V_66 ) ;
if ( ( V_60 & V_62 ) == V_63 )
goto V_67;
F_7 ( V_5 , F_37 ( 12 ) , V_68 ,
V_69 ) ;
F_7 ( V_5 , V_70 , V_71 , 0 ) ;
if ( V_60 & ( V_72 | V_73 | V_74 ) )
F_3 ( V_5 , V_60 , V_66 ) ;
F_7 ( V_5 , V_64 , V_65 , V_65 ) ;
while ( V_59 -- ) {
V_60 = F_5 ( V_5 , V_66 ) ;
if ( V_60 & V_72 ) {
F_3 ( V_5 , V_60 , V_66 ) ;
if ( V_60 & V_74 )
F_36 ( V_17 , L_4 ) ;
goto V_67;
}
F_38 ( 1 ) ;
} ;
F_36 ( V_17 , L_5 ) ;
V_67:
F_39 ( V_17 , L_6 ,
( V_60 & V_62 ) == V_63 ? L_7 : L_8 ) ;
}
static int F_40 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
struct V_75 * V_76 = F_41 ( V_5 ) ;
struct V_14 * V_15 , * V_77 ;
int V_40 ;
F_35 ( V_5 ) ;
F_31 ( & V_76 -> V_78 , V_5 ) ;
F_42 ( V_79 | V_80 ) ;
V_76 -> V_17 . V_28 = V_17 ;
V_76 -> V_39 = V_5 ;
V_76 -> V_81 = V_5 -> V_23 ;
V_76 -> V_82 = & V_83 ;
V_76 -> V_84 = V_85 ;
V_76 -> V_86 = V_87 ;
if ( F_43 ( V_88 ) )
V_76 -> V_89 = & V_5 -> V_89 . V_3 ;
V_40 = F_44 ( V_76 ) ;
if ( V_40 < 0 )
return V_40 ;
V_15 = V_76 -> V_15 ;
F_45 ( V_15 ) ;
F_46 ( V_15 ) ;
F_47 (child, &bus->children, node)
F_48 ( V_77 ) ;
F_49 ( V_15 ) ;
return 0 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
unsigned int V_59 = 100 ;
while ( V_59 -- ) {
if ( F_5 ( V_5 , V_90 ) & V_91 )
return 0 ;
F_51 ( 100 ) ;
}
F_36 ( V_17 , L_9 ) ;
return - V_92 ;
}
static void F_52 ( struct V_4 * V_5 ,
unsigned int V_93 , unsigned int V_94 ,
unsigned int V_95 , unsigned int V_11 )
{
unsigned long V_96 ;
V_96 = V_97 |
( ( V_93 & 1 ) << V_98 ) |
( ( V_95 & 0xf ) << V_99 ) |
( ( V_94 & 0xff ) << V_100 ) ;
F_3 ( V_5 , V_11 , V_101 ) ;
F_3 ( V_5 , V_96 , V_90 ) ;
F_50 ( V_5 ) ;
F_3 ( V_5 , 0 , V_101 ) ;
F_3 ( V_5 , 0 , V_90 ) ;
F_50 ( V_5 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
unsigned int V_59 = 10 ;
while ( V_59 -- ) {
if ( ( F_5 ( V_5 , V_102 ) & V_103 ) )
return 0 ;
F_38 ( 5 ) ;
}
return - V_92 ;
}
static int F_54 ( struct V_4 * V_5 )
{
int V_104 ;
F_3 ( V_5 , 0 , V_105 ) ;
F_3 ( V_5 , 1 , V_106 ) ;
F_3 ( V_5 , V_107 << 16 , V_108 ) ;
F_7 ( V_5 , F_17 ( V_109 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_17 ( V_110 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_55 ( 0 ) , 0xff , V_111 ) ;
F_7 ( V_5 , F_55 ( V_112 ) ,
V_113 , V_114 << 4 ) ;
F_7 ( V_5 , F_17 ( V_115 ) , 0x7f ,
V_116 ) ;
F_7 ( V_5 , F_55 ( V_117 ) , V_118 ,
V_118 ) ;
F_7 ( V_5 , F_55 ( V_119 ) , V_120 , 0 ) ;
F_7 ( V_5 , V_121 + 1 , 0x3f , 50 ) ;
F_7 ( V_5 , F_56 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_43 ( V_88 ) )
F_3 ( V_5 , 0x801f0000 , V_122 ) ;
F_3 ( V_5 , V_123 , V_105 ) ;
V_104 = F_53 ( V_5 ) ;
if ( V_104 )
return V_104 ;
F_7 ( V_5 , V_124 , 0 , 0xF << 8 ) ;
F_57 () ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
unsigned int V_59 = 10 ;
F_52 ( V_5 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_52 ( V_5 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_52 ( V_5 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_52 ( V_5 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_52 ( V_5 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_52 ( V_5 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_52 ( V_5 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_52 ( V_5 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_52 ( V_5 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_52 ( V_5 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_52 ( V_5 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_52 ( V_5 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_52 ( V_5 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_52 ( V_5 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_52 ( V_5 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_59 -- ) {
if ( F_5 ( V_5 , V_125 ) )
return F_54 ( V_5 ) ;
F_38 ( 5 ) ;
}
return - V_92 ;
}
static int F_59 ( struct V_4 * V_5 )
{
F_3 ( V_5 , 0x000f0030 , V_126 ) ;
F_3 ( V_5 , 0x00381203 , V_127 ) ;
F_3 ( V_5 , 0x00000001 , V_128 ) ;
F_3 ( V_5 , 0x00000006 , V_128 ) ;
F_3 ( V_5 , 0x000f0054 , V_126 ) ;
F_3 ( V_5 , 0x13802007 , V_127 ) ;
F_3 ( V_5 , 0x00000001 , V_128 ) ;
F_3 ( V_5 , 0x00000006 , V_128 ) ;
return F_54 ( V_5 ) ;
}
static int F_60 ( struct V_1 * V_3 )
{
int V_89 ;
F_61 ( & V_3 -> V_129 ) ;
V_89 = F_62 ( V_3 -> V_130 , V_131 ) ;
if ( V_89 < V_131 )
F_63 ( V_89 , V_3 -> V_130 ) ;
else
V_89 = - V_132 ;
F_64 ( & V_3 -> V_129 ) ;
return V_89 ;
}
static int F_65 ( struct V_1 * V_3 , int V_133 )
{
int V_89 ;
F_61 ( & V_3 -> V_129 ) ;
V_89 = F_66 ( V_3 -> V_130 , V_131 ,
F_67 ( V_133 ) ) ;
F_64 ( & V_3 -> V_129 ) ;
return V_89 ;
}
static void F_68 ( struct V_1 * V_3 , unsigned long V_134 )
{
F_61 ( & V_3 -> V_129 ) ;
F_69 ( V_134 , V_3 -> V_130 ) ;
F_64 ( & V_3 -> V_129 ) ;
}
static T_3 F_70 ( int V_134 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
struct V_1 * V_89 = & V_5 -> V_89 ;
struct V_58 * V_17 = V_5 -> V_17 ;
unsigned long V_7 ;
V_7 = F_5 ( V_5 , V_135 ) ;
if ( ! V_7 )
return V_136 ;
while ( V_7 ) {
unsigned int V_19 = F_71 ( & V_7 , 32 ) ;
unsigned int V_134 ;
F_3 ( V_5 , 1 << V_19 , V_135 ) ;
V_134 = F_72 ( V_89 -> V_137 , V_19 ) ;
if ( V_134 ) {
if ( F_73 ( V_19 , V_89 -> V_130 ) )
F_74 ( V_134 ) ;
else
F_39 ( V_17 , L_10 ) ;
} else {
F_19 ( V_17 , L_11 ) ;
}
V_7 = F_5 ( V_5 , V_135 ) ;
}
return V_138 ;
}
static int F_75 ( struct V_2 * V_3 , struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_89 . V_3 ) ;
struct V_143 V_144 ;
unsigned int V_134 ;
int V_145 ;
V_145 = F_60 ( V_89 ) ;
if ( V_145 < 0 )
return V_145 ;
V_134 = F_72 ( V_89 -> V_137 , V_145 ) ;
if ( ! V_134 ) {
F_68 ( V_89 , V_145 ) ;
return - V_146 ;
}
F_76 ( V_134 , V_142 ) ;
V_144 . V_147 = F_5 ( V_5 , V_148 ) & ~ V_149 ;
V_144 . V_150 = F_5 ( V_5 , V_151 ) ;
V_144 . V_11 = V_145 ;
F_77 ( V_134 , & V_144 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_139 * V_140 , int V_152 , int type )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_89 . V_3 ) ;
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_141 * V_142 ;
struct V_143 V_144 ;
unsigned int V_134 ;
int V_145 ;
int V_55 ;
if ( type == V_153 )
return - V_146 ;
F_79 ( ! F_80 ( & V_140 -> V_17 . V_154 ) ) ;
V_142 = F_81 ( V_140 -> V_17 . V_154 . V_155 , struct V_141 , V_156 ) ;
V_145 = F_65 ( V_89 , V_152 ) ;
if ( V_145 < 0 )
return - V_132 ;
V_134 = F_72 ( V_89 -> V_137 , V_145 ) ;
if ( ! V_134 )
return - V_132 ;
for ( V_55 = 0 ; V_55 < V_152 ; V_55 ++ ) {
if ( F_82 ( V_134 , V_55 , V_142 ) ) {
return - V_146 ;
}
}
V_142 -> V_157 = V_152 ;
V_142 -> V_158 . V_159 = F_67 ( V_152 ) ;
V_144 . V_147 = F_5 ( V_5 , V_148 ) & ~ V_149 ;
V_144 . V_150 = F_5 ( V_5 , V_151 ) ;
V_144 . V_11 = V_145 ;
F_77 ( V_134 , & V_144 ) ;
return 0 ;
}
static void F_83 ( struct V_2 * V_3 , unsigned int V_134 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_160 * V_161 = F_84 ( V_134 ) ;
F_68 ( V_89 , V_161 -> V_145 ) ;
}
static int F_85 ( struct V_162 * V_137 , unsigned int V_134 ,
T_4 V_145 )
{
F_86 ( V_134 , & V_163 , V_164 ) ;
F_87 ( V_134 , V_137 -> V_165 ) ;
return 0 ;
}
static int F_88 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
struct V_1 * V_89 = & V_5 -> V_89 ;
unsigned long V_8 ;
int V_104 , V_55 ;
F_89 ( & V_89 -> V_129 ) ;
V_89 -> V_3 . V_17 = V_17 ;
V_89 -> V_3 . V_166 = F_75 ;
V_89 -> V_3 . V_167 = F_78 ;
V_89 -> V_3 . V_168 = F_83 ;
V_89 -> V_137 = F_90 ( V_17 -> V_169 , V_131 ,
& V_170 , & V_89 -> V_3 ) ;
if ( ! V_89 -> V_137 ) {
F_36 ( V_17 , L_12 ) ;
return - V_171 ;
}
for ( V_55 = 0 ; V_55 < V_131 ; V_55 ++ )
F_91 ( V_89 -> V_137 , V_55 ) ;
V_104 = F_92 ( V_17 , V_89 -> V_172 , F_70 ,
V_173 | V_174 ,
V_163 . V_175 , V_5 ) ;
if ( V_104 < 0 ) {
F_36 ( V_17 , L_13 , V_104 ) ;
goto V_104;
}
V_104 = F_92 ( V_17 , V_89 -> V_176 , F_70 ,
V_173 | V_174 ,
V_163 . V_175 , V_5 ) ;
if ( V_104 < 0 ) {
F_36 ( V_17 , L_13 , V_104 ) ;
goto V_104;
}
V_89 -> V_177 = F_93 ( V_178 , 0 ) ;
V_8 = F_94 ( ( void * ) V_89 -> V_177 ) ;
F_3 ( V_5 , V_8 | V_149 , V_148 ) ;
F_3 ( V_5 , 0 , V_151 ) ;
F_3 ( V_5 , 0xffffffff , V_179 ) ;
return 0 ;
V_104:
F_95 ( V_89 -> V_137 ) ;
return V_104 ;
}
static int F_96 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
struct V_43 V_44 ;
int V_104 , V_55 ;
V_104 = F_97 ( V_17 -> V_169 , 0 , & V_44 ) ;
if ( V_104 )
return V_104 ;
V_5 -> V_8 = F_98 ( V_17 , & V_44 ) ;
if ( F_99 ( V_5 -> V_8 ) )
return F_100 ( V_5 -> V_8 ) ;
V_5 -> V_180 = F_101 ( V_17 , L_14 ) ;
if ( F_99 ( V_5 -> V_180 ) ) {
F_36 ( V_17 , L_15 ) ;
return F_100 ( V_5 -> V_180 ) ;
}
V_104 = F_102 ( V_5 -> V_180 ) ;
if ( V_104 )
return V_104 ;
V_5 -> V_181 = F_101 ( V_17 , L_16 ) ;
if ( F_99 ( V_5 -> V_181 ) ) {
F_36 ( V_17 , L_17 ) ;
V_104 = F_100 ( V_5 -> V_181 ) ;
goto V_182;
}
V_104 = F_102 ( V_5 -> V_181 ) ;
if ( V_104 )
goto V_182;
V_55 = F_103 ( V_17 -> V_169 , 0 ) ;
if ( ! V_55 ) {
F_36 ( V_17 , L_18 ) ;
V_104 = - V_183 ;
goto V_184;
}
V_5 -> V_89 . V_172 = V_55 ;
V_55 = F_103 ( V_17 -> V_169 , 1 ) ;
if ( ! V_55 ) {
F_36 ( V_17 , L_18 ) ;
V_104 = - V_183 ;
goto V_184;
}
V_5 -> V_89 . V_176 = V_55 ;
return 0 ;
V_184:
F_104 ( V_5 -> V_181 ) ;
V_182:
F_104 ( V_5 -> V_180 ) ;
return V_104 ;
}
static int F_105 ( struct V_4 * V_5 ,
struct V_185 * V_186 ,
int * V_19 )
{
T_5 V_187 = V_186 -> V_47 ;
T_5 V_188 = V_186 -> V_188 ;
T_5 V_189 = V_186 -> V_188 + V_186 -> V_38 ;
T_5 V_190 = V_186 -> V_190 ;
T_1 V_47 = V_191 | V_192 ;
T_5 V_10 ;
T_5 V_38 ;
int V_193 = * V_19 ;
if ( V_187 & V_194 )
V_47 |= V_195 ;
if ( V_188 > 0 ) {
unsigned long V_196 = F_106 ( V_188 ) ;
T_5 V_197 = 1ULL << V_196 ;
V_38 = F_107 ( V_186 -> V_38 , V_197 ) ;
} else {
V_38 = V_186 -> V_38 ;
}
V_38 = F_107 ( V_38 , 1ULL << 32 ) ;
V_10 = F_24 ( V_38 ) - 1 ;
V_10 &= ~ 0xf ;
while ( V_188 < V_189 ) {
F_3 ( V_5 , F_29 ( V_190 ) ,
F_108 ( V_193 ) ) ;
F_3 ( V_5 , F_29 ( V_188 ) , F_109 ( V_193 ) ) ;
F_3 ( V_5 , F_29 ( V_10 ) | V_47 ,
F_110 ( V_193 ) ) ;
F_3 ( V_5 , F_27 ( V_190 ) ,
F_108 ( V_193 + 1 ) ) ;
F_3 ( V_5 , F_27 ( V_188 ) ,
F_109 ( V_193 + 1 ) ) ;
F_3 ( V_5 , 0 , F_110 ( V_193 + 1 ) ) ;
V_190 += V_38 ;
V_188 += V_38 ;
V_193 += 2 ;
if ( V_193 > V_198 ) {
F_36 ( V_5 -> V_17 , L_19 ) ;
return - V_146 ;
}
}
* V_19 = V_193 ;
return 0 ;
}
static int F_111 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
const int V_203 = 3 , V_204 = 2 ;
int V_205 ;
V_200 -> V_202 = V_202 ;
V_200 -> V_206 = F_112 ( V_202 ) ;
V_200 -> V_207 = V_200 -> V_206 + V_203 + V_204 ;
V_200 -> V_186 = F_113 ( V_202 , L_20 , & V_205 ) ;
if ( ! V_200 -> V_186 )
return - V_183 ;
V_200 -> V_208 = V_200 -> V_186 + V_205 / sizeof( V_209 ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_201 * V_207 )
{
struct V_185 V_186 ;
struct V_199 V_200 ;
int V_19 = 0 ;
int V_104 ;
if ( F_111 ( & V_200 , V_207 ) )
return - V_146 ;
F_115 (&parser, &range) {
T_5 V_208 = V_186 . V_188 + V_186 . V_38 - 1 ;
F_19 ( V_5 -> V_17 , L_21 ,
V_186 . V_47 , V_186 . V_188 , V_208 , V_186 . V_190 ) ;
V_104 = F_105 ( V_5 , & V_186 , & V_19 ) ;
if ( V_104 )
return V_104 ;
}
return 0 ;
}
static int F_116 ( struct V_4 * V_53 )
{
int V_104 ;
struct V_58 * V_17 = V_53 -> V_17 ;
struct V_201 * V_207 = V_17 -> V_169 ;
T_2 V_210 ;
struct V_54 * V_42 , * V_211 ;
V_104 = F_117 ( V_207 , 0 , 0xff , & V_53 -> V_212 ,
& V_210 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_118 ( V_17 , & V_53 -> V_212 ) ;
if ( V_104 )
goto V_213;
F_119 (win, tmp, &pci->resources) {
struct V_43 * V_44 = V_42 -> V_44 ;
if ( F_33 ( V_44 ) == V_48 ) {
V_104 = F_120 ( V_44 , V_210 ) ;
if ( V_104 ) {
F_121 ( V_17 , L_22 ,
V_104 , V_44 ) ;
F_122 ( V_42 ) ;
}
}
}
return 0 ;
V_213:
F_123 ( & V_53 -> V_212 ) ;
return V_104 ;
}
static int F_124 ( struct V_214 * V_140 )
{
struct V_58 * V_17 = & V_140 -> V_17 ;
struct V_4 * V_5 ;
unsigned int V_11 ;
int V_104 ;
int (* F_125)( struct V_4 * );
struct V_75 * V_76 ;
V_76 = F_126 ( sizeof( * V_5 ) ) ;
if ( ! V_76 )
return - V_171 ;
V_5 = F_127 ( V_76 ) ;
V_5 -> V_17 = V_17 ;
F_128 ( & V_5 -> V_212 ) ;
F_116 ( V_5 ) ;
V_104 = F_96 ( V_5 ) ;
if ( V_104 < 0 ) {
F_36 ( V_17 , L_23 , V_104 ) ;
goto V_215;
}
V_104 = F_114 ( V_5 , V_17 -> V_169 ) ;
if ( V_104 )
goto V_215;
F_129 ( V_17 ) ;
V_104 = F_130 ( V_17 ) ;
if ( V_104 < 0 ) {
F_36 ( V_17 , L_24 ) ;
goto V_216;
}
F_125 = F_131 ( V_17 ) ;
V_104 = F_125 ( V_5 ) ;
if ( V_104 ) {
F_39 ( V_17 , L_25 ) ;
V_104 = - V_217 ;
goto V_218;
}
V_11 = F_5 ( V_5 , V_66 ) ;
F_39 ( V_17 , L_26 , ( V_11 >> 20 ) & 0x3f ) ;
if ( F_43 ( V_88 ) ) {
V_104 = F_88 ( V_5 ) ;
if ( V_104 < 0 ) {
F_36 ( V_17 ,
L_27 ,
V_104 ) ;
goto V_218;
}
}
V_104 = F_40 ( V_5 ) ;
if ( V_104 )
goto V_218;
return 0 ;
V_218:
F_132 ( V_17 ) ;
V_216:
F_133 ( V_17 ) ;
V_215:
F_134 ( V_76 ) ;
F_123 ( & V_5 -> V_212 ) ;
return V_104 ;
}
