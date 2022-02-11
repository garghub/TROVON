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
struct V_14 * V_15 , * V_75 ;
F_41 ( V_44 ) ;
F_35 ( V_5 ) ;
F_31 ( & V_44 , V_5 ) ;
F_42 ( V_76 | V_77 ) ;
if ( F_43 ( V_78 ) )
V_15 = F_44 ( V_17 , V_5 -> V_23 ,
& V_79 , V_5 , & V_44 , & V_5 -> V_80 . V_3 ) ;
else
V_15 = F_45 ( V_17 , V_5 -> V_23 ,
& V_79 , V_5 , & V_44 ) ;
if ( ! V_15 ) {
F_36 ( V_17 , L_9 ) ;
return - V_81 ;
}
F_46 ( V_82 , V_83 ) ;
F_47 ( V_15 ) ;
F_48 ( V_15 ) ;
F_49 (child, &bus->children, node)
F_50 ( V_75 ) ;
F_51 ( V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
unsigned int V_59 = 100 ;
while ( V_59 -- ) {
if ( F_5 ( V_5 , V_84 ) & V_85 )
return 0 ;
F_53 ( 100 ) ;
}
F_36 ( V_17 , L_10 ) ;
return - V_86 ;
}
static void F_54 ( struct V_4 * V_5 ,
unsigned int V_87 , unsigned int V_88 ,
unsigned int V_89 , unsigned int V_11 )
{
unsigned long V_90 ;
V_90 = V_91 |
( ( V_87 & 1 ) << V_92 ) |
( ( V_89 & 0xf ) << V_93 ) |
( ( V_88 & 0xff ) << V_94 ) ;
F_3 ( V_5 , V_11 , V_95 ) ;
F_3 ( V_5 , V_90 , V_84 ) ;
F_52 ( V_5 ) ;
F_3 ( V_5 , 0 , V_95 ) ;
F_3 ( V_5 , 0 , V_84 ) ;
F_52 ( V_5 ) ;
}
static int F_55 ( struct V_4 * V_5 )
{
unsigned int V_59 = 10 ;
while ( V_59 -- ) {
if ( ( F_5 ( V_5 , V_96 ) & V_97 ) )
return 0 ;
F_38 ( 5 ) ;
}
return - V_86 ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_98 ;
F_3 ( V_5 , 0 , V_99 ) ;
F_3 ( V_5 , 1 , V_100 ) ;
F_3 ( V_5 , V_101 << 16 , V_102 ) ;
F_7 ( V_5 , F_17 ( V_103 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_17 ( V_104 ) , 0xff , 1 ) ;
F_7 ( V_5 , F_57 ( 0 ) , 0xff , V_105 ) ;
F_7 ( V_5 , F_57 ( V_106 ) ,
V_107 , V_108 << 4 ) ;
F_7 ( V_5 , F_17 ( V_109 ) , 0x7f ,
V_110 ) ;
F_7 ( V_5 , F_57 ( V_111 ) , V_112 ,
V_112 ) ;
F_7 ( V_5 , F_57 ( V_113 ) , V_114 , 0 ) ;
F_7 ( V_5 , V_115 + 1 , 0x3f , 50 ) ;
F_7 ( V_5 , F_58 ( 0 ) , 0xfff00000 , 0 ) ;
if ( F_43 ( V_78 ) )
F_3 ( V_5 , 0x801f0000 , V_116 ) ;
F_3 ( V_5 , V_117 , V_99 ) ;
V_98 = F_55 ( V_5 ) ;
if ( V_98 )
return V_98 ;
F_7 ( V_5 , V_118 , 0 , 0xF << 8 ) ;
F_59 () ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 )
{
unsigned int V_59 = 10 ;
F_54 ( V_5 , 0 , 0x42 , 0x1 , 0x0EC34191 ) ;
F_54 ( V_5 , 1 , 0x42 , 0x1 , 0x0EC34180 ) ;
F_54 ( V_5 , 0 , 0x43 , 0x1 , 0x00210188 ) ;
F_54 ( V_5 , 1 , 0x43 , 0x1 , 0x00210188 ) ;
F_54 ( V_5 , 0 , 0x44 , 0x1 , 0x015C0014 ) ;
F_54 ( V_5 , 1 , 0x44 , 0x1 , 0x015C0014 ) ;
F_54 ( V_5 , 1 , 0x4C , 0x1 , 0x786174A0 ) ;
F_54 ( V_5 , 1 , 0x4D , 0x1 , 0x048000BB ) ;
F_54 ( V_5 , 0 , 0x51 , 0x1 , 0x079EC062 ) ;
F_54 ( V_5 , 0 , 0x52 , 0x1 , 0x20000000 ) ;
F_54 ( V_5 , 1 , 0x52 , 0x1 , 0x20000000 ) ;
F_54 ( V_5 , 1 , 0x56 , 0x1 , 0x00003806 ) ;
F_54 ( V_5 , 0 , 0x60 , 0x1 , 0x004B03A5 ) ;
F_54 ( V_5 , 0 , 0x64 , 0x1 , 0x3F0F1F0F ) ;
F_54 ( V_5 , 0 , 0x66 , 0x1 , 0x00008000 ) ;
while ( V_59 -- ) {
if ( F_5 ( V_5 , V_119 ) )
return F_56 ( V_5 ) ;
F_38 ( 5 ) ;
}
return - V_86 ;
}
static int F_61 ( struct V_4 * V_5 )
{
F_3 ( V_5 , 0x000f0030 , V_120 ) ;
F_3 ( V_5 , 0x00381203 , V_121 ) ;
F_3 ( V_5 , 0x00000001 , V_122 ) ;
F_3 ( V_5 , 0x00000006 , V_122 ) ;
F_3 ( V_5 , 0x000f0054 , V_120 ) ;
F_3 ( V_5 , 0x13802007 , V_121 ) ;
F_3 ( V_5 , 0x00000001 , V_122 ) ;
F_3 ( V_5 , 0x00000006 , V_122 ) ;
return F_56 ( V_5 ) ;
}
static int F_62 ( struct V_1 * V_3 )
{
int V_80 ;
F_63 ( & V_3 -> V_123 ) ;
V_80 = F_64 ( V_3 -> V_124 , V_125 ) ;
if ( V_80 < V_125 )
F_65 ( V_80 , V_3 -> V_124 ) ;
else
V_80 = - V_126 ;
F_66 ( & V_3 -> V_123 ) ;
return V_80 ;
}
static int F_67 ( struct V_1 * V_3 , int V_127 )
{
int V_80 ;
F_63 ( & V_3 -> V_123 ) ;
V_80 = F_68 ( V_3 -> V_124 , V_125 ,
F_69 ( V_127 ) ) ;
F_66 ( & V_3 -> V_123 ) ;
return V_80 ;
}
static void F_70 ( struct V_1 * V_3 , unsigned long V_128 )
{
F_63 ( & V_3 -> V_123 ) ;
F_71 ( V_128 , V_3 -> V_124 ) ;
F_66 ( & V_3 -> V_123 ) ;
}
static T_3 F_72 ( int V_128 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
struct V_1 * V_80 = & V_5 -> V_80 ;
struct V_58 * V_17 = V_5 -> V_17 ;
unsigned long V_7 ;
V_7 = F_5 ( V_5 , V_129 ) ;
if ( ! V_7 )
return V_130 ;
while ( V_7 ) {
unsigned int V_19 = F_73 ( & V_7 , 32 ) ;
unsigned int V_128 ;
F_3 ( V_5 , 1 << V_19 , V_129 ) ;
V_128 = F_74 ( V_80 -> V_131 , V_19 ) ;
if ( V_128 ) {
if ( F_75 ( V_19 , V_80 -> V_124 ) )
F_76 ( V_128 ) ;
else
F_39 ( V_17 , L_11 ) ;
} else {
F_19 ( V_17 , L_12 ) ;
}
V_7 = F_5 ( V_5 , V_129 ) ;
}
return V_132 ;
}
static int F_77 ( struct V_2 * V_3 , struct V_133 * V_134 ,
struct V_135 * V_136 )
{
struct V_1 * V_80 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_80 . V_3 ) ;
struct V_137 V_138 ;
unsigned int V_128 ;
int V_139 ;
V_139 = F_62 ( V_80 ) ;
if ( V_139 < 0 )
return V_139 ;
V_128 = F_74 ( V_80 -> V_131 , V_139 ) ;
if ( ! V_128 ) {
F_70 ( V_80 , V_139 ) ;
return - V_140 ;
}
F_78 ( V_128 , V_136 ) ;
V_138 . V_141 = F_5 ( V_5 , V_142 ) & ~ V_143 ;
V_138 . V_144 = F_5 ( V_5 , V_145 ) ;
V_138 . V_11 = V_139 ;
F_79 ( V_128 , & V_138 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_133 * V_134 , int V_146 , int type )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_80 . V_3 ) ;
struct V_1 * V_80 = F_1 ( V_3 ) ;
struct V_135 * V_136 ;
struct V_137 V_138 ;
unsigned int V_128 ;
int V_139 ;
int V_55 ;
if ( type == V_147 )
return - V_140 ;
F_81 ( ! F_82 ( & V_134 -> V_17 . V_148 ) ) ;
V_136 = F_83 ( V_134 -> V_17 . V_148 . V_149 , struct V_135 , V_150 ) ;
V_139 = F_67 ( V_80 , V_146 ) ;
if ( V_139 < 0 )
return - V_126 ;
V_128 = F_74 ( V_80 -> V_131 , V_139 ) ;
if ( ! V_128 )
return - V_126 ;
for ( V_55 = 0 ; V_55 < V_146 ; V_55 ++ ) {
if ( F_84 ( V_128 , V_55 , V_136 ) ) {
return - V_140 ;
}
}
V_136 -> V_151 = V_146 ;
V_136 -> V_152 . V_153 = F_69 ( V_146 ) ;
V_138 . V_141 = F_5 ( V_5 , V_142 ) & ~ V_143 ;
V_138 . V_144 = F_5 ( V_5 , V_145 ) ;
V_138 . V_11 = V_139 ;
F_79 ( V_128 , & V_138 ) ;
return 0 ;
}
static void F_85 ( struct V_2 * V_3 , unsigned int V_128 )
{
struct V_1 * V_80 = F_1 ( V_3 ) ;
struct V_154 * V_155 = F_86 ( V_128 ) ;
F_70 ( V_80 , V_155 -> V_139 ) ;
}
static int F_87 ( struct V_156 * V_131 , unsigned int V_128 ,
T_4 V_139 )
{
F_88 ( V_128 , & V_157 , V_158 ) ;
F_89 ( V_128 , V_131 -> V_159 ) ;
return 0 ;
}
static int F_90 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
struct V_1 * V_80 = & V_5 -> V_80 ;
unsigned long V_8 ;
int V_98 , V_55 ;
F_91 ( & V_80 -> V_123 ) ;
V_80 -> V_3 . V_17 = V_17 ;
V_80 -> V_3 . V_160 = F_77 ;
V_80 -> V_3 . V_161 = F_80 ;
V_80 -> V_3 . V_162 = F_85 ;
V_80 -> V_131 = F_92 ( V_17 -> V_163 , V_125 ,
& V_164 , & V_80 -> V_3 ) ;
if ( ! V_80 -> V_131 ) {
F_36 ( V_17 , L_13 ) ;
return - V_165 ;
}
for ( V_55 = 0 ; V_55 < V_125 ; V_55 ++ )
F_93 ( V_80 -> V_131 , V_55 ) ;
V_98 = F_94 ( V_17 , V_80 -> V_166 , F_72 ,
V_167 | V_168 ,
V_157 . V_169 , V_5 ) ;
if ( V_98 < 0 ) {
F_36 ( V_17 , L_14 , V_98 ) ;
goto V_98;
}
V_98 = F_94 ( V_17 , V_80 -> V_170 , F_72 ,
V_167 | V_168 ,
V_157 . V_169 , V_5 ) ;
if ( V_98 < 0 ) {
F_36 ( V_17 , L_14 , V_98 ) ;
goto V_98;
}
V_80 -> V_171 = F_95 ( V_172 , 0 ) ;
V_8 = F_96 ( ( void * ) V_80 -> V_171 ) ;
F_3 ( V_5 , V_8 | V_143 , V_142 ) ;
F_3 ( V_5 , 0 , V_145 ) ;
F_3 ( V_5 , 0xffffffff , V_173 ) ;
return 0 ;
V_98:
F_97 ( V_80 -> V_131 ) ;
return V_98 ;
}
static int F_98 ( struct V_4 * V_5 )
{
struct V_58 * V_17 = V_5 -> V_17 ;
struct V_43 V_44 ;
int V_98 , V_55 ;
V_98 = F_99 ( V_17 -> V_163 , 0 , & V_44 ) ;
if ( V_98 )
return V_98 ;
V_5 -> V_8 = F_100 ( V_17 , & V_44 ) ;
if ( F_101 ( V_5 -> V_8 ) )
return F_102 ( V_5 -> V_8 ) ;
V_5 -> V_174 = F_103 ( V_17 , L_15 ) ;
if ( F_101 ( V_5 -> V_174 ) ) {
F_36 ( V_17 , L_16 ) ;
return F_102 ( V_5 -> V_174 ) ;
}
V_98 = F_104 ( V_5 -> V_174 ) ;
if ( V_98 )
return V_98 ;
V_5 -> V_175 = F_103 ( V_17 , L_17 ) ;
if ( F_101 ( V_5 -> V_175 ) ) {
F_36 ( V_17 , L_18 ) ;
V_98 = F_102 ( V_5 -> V_175 ) ;
goto V_176;
}
V_98 = F_104 ( V_5 -> V_175 ) ;
if ( V_98 )
goto V_176;
V_55 = F_105 ( V_17 -> V_163 , 0 ) ;
if ( ! V_55 ) {
F_36 ( V_17 , L_19 ) ;
V_98 = - V_177 ;
goto V_178;
}
V_5 -> V_80 . V_166 = V_55 ;
V_55 = F_105 ( V_17 -> V_163 , 1 ) ;
if ( ! V_55 ) {
F_36 ( V_17 , L_19 ) ;
V_98 = - V_177 ;
goto V_178;
}
V_5 -> V_80 . V_170 = V_55 ;
return 0 ;
V_178:
F_106 ( V_5 -> V_175 ) ;
V_176:
F_106 ( V_5 -> V_174 ) ;
return V_98 ;
}
static int F_107 ( struct V_4 * V_5 ,
struct V_179 * V_180 ,
int * V_19 )
{
T_5 V_181 = V_180 -> V_47 ;
T_5 V_182 = V_180 -> V_182 ;
T_5 V_183 = V_180 -> V_182 + V_180 -> V_38 ;
T_5 V_184 = V_180 -> V_184 ;
T_1 V_47 = V_185 | V_186 ;
T_5 V_10 ;
T_5 V_38 ;
int V_187 = * V_19 ;
if ( V_181 & V_188 )
V_47 |= V_189 ;
if ( V_182 > 0 ) {
unsigned long V_190 = F_108 ( V_182 ) ;
T_5 V_191 = 1ULL << V_190 ;
V_38 = F_109 ( V_180 -> V_38 , V_191 ) ;
} else {
V_38 = V_180 -> V_38 ;
}
V_38 = F_109 ( V_38 , 1ULL << 32 ) ;
V_10 = F_24 ( V_38 ) - 1 ;
V_10 &= ~ 0xf ;
while ( V_182 < V_183 ) {
F_3 ( V_5 , F_29 ( V_184 ) ,
F_110 ( V_187 ) ) ;
F_3 ( V_5 , F_29 ( V_182 ) , F_111 ( V_187 ) ) ;
F_3 ( V_5 , F_29 ( V_10 ) | V_47 ,
F_112 ( V_187 ) ) ;
F_3 ( V_5 , F_27 ( V_184 ) ,
F_110 ( V_187 + 1 ) ) ;
F_3 ( V_5 , F_27 ( V_182 ) ,
F_111 ( V_187 + 1 ) ) ;
F_3 ( V_5 , 0 , F_112 ( V_187 + 1 ) ) ;
V_184 += V_38 ;
V_182 += V_38 ;
V_187 += 2 ;
if ( V_187 > V_192 ) {
F_36 ( V_5 -> V_17 , L_20 ) ;
return - V_140 ;
}
}
* V_19 = V_187 ;
return 0 ;
}
static int F_113 ( struct V_193 * V_194 ,
struct V_195 * V_196 )
{
const int V_197 = 3 , V_198 = 2 ;
int V_199 ;
V_194 -> V_196 = V_196 ;
V_194 -> V_200 = F_114 ( V_196 ) ;
V_194 -> V_201 = V_194 -> V_200 + V_197 + V_198 ;
V_194 -> V_180 = F_115 ( V_196 , L_21 , & V_199 ) ;
if ( ! V_194 -> V_180 )
return - V_177 ;
V_194 -> V_202 = V_194 -> V_180 + V_199 / sizeof( V_203 ) ;
return 0 ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_195 * V_201 )
{
struct V_179 V_180 ;
struct V_193 V_194 ;
int V_19 = 0 ;
int V_98 ;
if ( F_113 ( & V_194 , V_201 ) )
return - V_140 ;
F_117 (&parser, &range) {
T_5 V_202 = V_180 . V_182 + V_180 . V_38 - 1 ;
F_19 ( V_5 -> V_17 , L_22 ,
V_180 . V_47 , V_180 . V_182 , V_202 , V_180 . V_184 ) ;
V_98 = F_107 ( V_5 , & V_180 , & V_19 ) ;
if ( V_98 )
return V_98 ;
}
return 0 ;
}
static int F_118 ( struct V_4 * V_53 )
{
int V_98 ;
struct V_58 * V_17 = V_53 -> V_17 ;
struct V_195 * V_201 = V_17 -> V_163 ;
T_2 V_204 ;
struct V_54 * V_42 , * V_205 ;
V_98 = F_119 ( V_201 , 0 , 0xff , & V_53 -> V_206 ,
& V_204 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_120 ( V_17 , & V_53 -> V_206 ) ;
if ( V_98 )
goto V_207;
F_121 (win, tmp, &pci->resources) {
struct V_43 * V_44 = V_42 -> V_44 ;
if ( F_33 ( V_44 ) == V_48 ) {
V_98 = F_122 ( V_44 , V_204 ) ;
if ( V_98 ) {
F_123 ( V_17 , L_23 ,
V_98 , V_44 ) ;
F_124 ( V_42 ) ;
}
}
}
return 0 ;
V_207:
F_125 ( & V_53 -> V_206 ) ;
return V_98 ;
}
static int F_126 ( struct V_208 * V_134 )
{
struct V_58 * V_17 = & V_134 -> V_17 ;
struct V_4 * V_5 ;
unsigned int V_11 ;
const struct V_209 * V_210 ;
int V_98 ;
int (* F_127)( struct V_4 * );
V_5 = F_128 ( V_17 , sizeof( * V_5 ) , V_172 ) ;
if ( ! V_5 )
return - V_165 ;
V_5 -> V_17 = V_17 ;
F_129 ( & V_5 -> V_206 ) ;
F_118 ( V_5 ) ;
V_98 = F_98 ( V_5 ) ;
if ( V_98 < 0 ) {
F_36 ( V_17 , L_24 , V_98 ) ;
return V_98 ;
}
V_98 = F_116 ( V_5 , V_17 -> V_163 ) ;
if ( V_98 )
return V_98 ;
V_210 = F_130 ( V_211 , V_17 ) ;
if ( ! V_210 || ! V_210 -> V_11 )
return - V_140 ;
F_127 = V_210 -> V_11 ;
F_131 ( V_17 ) ;
V_98 = F_132 ( V_17 ) ;
if ( V_98 < 0 ) {
F_36 ( V_17 , L_25 ) ;
goto V_212;
}
V_98 = F_127 ( V_5 ) ;
if ( V_98 ) {
F_39 ( V_17 , L_26 ) ;
V_98 = 0 ;
goto V_213;
}
V_11 = F_5 ( V_5 , V_66 ) ;
F_39 ( V_17 , L_27 , ( V_11 >> 20 ) & 0x3f ) ;
if ( F_43 ( V_78 ) ) {
V_98 = F_90 ( V_5 ) ;
if ( V_98 < 0 ) {
F_36 ( V_17 ,
L_28 ,
V_98 ) ;
goto V_213;
}
}
V_98 = F_40 ( V_5 ) ;
if ( V_98 )
goto V_213;
return 0 ;
V_213:
F_133 ( V_17 ) ;
V_212:
F_134 ( V_17 ) ;
return V_98 ;
}
