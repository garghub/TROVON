static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return false ;
default:
break;
}
return true ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_12 :
return true ;
default:
break;
}
return false ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_4 :
case V_6 :
case V_7 :
return true ;
default:
break;
}
return false ;
}
static void F_4 ( struct V_13 * V_14 , int V_15 )
{
unsigned int V_16 = 0 , div = V_14 -> V_17 / V_15 ;
if ( ! ( div / 16 ) ) {
V_16 = V_18 ;
div = ( V_14 -> V_17 * 2 ) / V_15 ;
}
if ( ! ( div / 16 ) ) {
V_16 = V_19 ;
div = ( V_14 -> V_17 * 4 ) / V_15 ;
}
F_5 ( V_14 -> V_20 , V_21 ,
( ( div / 16 ) >> 8 ) & 0xff ) ;
F_5 ( V_14 -> V_20 , V_22 , ( div / 16 ) & 0xff ) ;
F_5 ( V_14 -> V_20 , V_23 , ( div % 16 ) | V_16 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
int V_24 = 1000 ;
if ( ! ( V_14 -> V_25 -> V_26 & V_27 ) ) {
unsigned int V_28 = 0 ;
while ( V_24 -- ) {
F_7 ( V_14 -> V_20 , V_7 , & V_28 ) ;
if ( V_28 & V_29 )
break;
}
}
}
static int F_8 ( unsigned long V_30 , long * V_31 )
{
long V_32 = V_30 % ( 115200 * 16 ) ;
if ( ( * V_31 < 0 ) || ( * V_31 > V_32 ) ) {
* V_31 = V_32 ;
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_13 * V_14 )
{
unsigned int div , V_33 , V_34 = 0 ;
long V_31 = - 1 ;
unsigned long V_35 , V_36 , V_37 = V_14 -> V_25 -> V_38 ;
F_8 ( V_14 -> V_25 -> V_38 , & V_31 ) ;
for ( div = 1 ; ( div <= 63 ) && V_31 ; div ++ ) {
V_35 = F_10 ( V_14 -> V_25 -> V_38 , div ) ;
V_36 = V_35 * 6 ;
if ( ( V_35 >= 500000 ) && ( V_35 <= 800000 ) )
if ( ! F_8 ( V_36 , & V_31 ) ) {
V_34 = ( 0 << 6 ) | div ;
V_37 = V_36 ;
}
V_36 = V_35 * 48 ;
if ( ( V_35 >= 850000 ) && ( V_35 <= 1200000 ) )
if ( ! F_8 ( V_36 , & V_31 ) ) {
V_34 = ( 1 << 6 ) | div ;
V_37 = V_36 ;
}
V_36 = V_35 * 96 ;
if ( ( V_35 >= 425000 ) && ( V_35 <= 1000000 ) )
if ( ! F_8 ( V_36 , & V_31 ) ) {
V_34 = ( 2 << 6 ) | div ;
V_37 = V_36 ;
}
V_36 = V_35 * 144 ;
if ( ( V_35 >= 390000 ) && ( V_35 <= 667000 ) )
if ( ! F_8 ( V_36 , & V_31 ) ) {
V_34 = ( 3 << 6 ) | div ;
V_37 = V_36 ;
}
}
if ( V_14 -> V_25 -> V_26 & V_27 )
V_33 = V_39 ;
else
V_33 = V_40 ;
if ( V_34 ) {
V_33 |= V_41 ;
F_5 ( V_14 -> V_20 , V_42 , V_34 ) ;
} else
V_33 |= V_43 ;
F_5 ( V_14 -> V_20 , V_44 , V_33 ) ;
if ( V_34 )
F_6 ( V_14 ) ;
F_11 ( V_14 -> V_45 . V_2 , L_1 , V_37 ) ;
return ( int ) V_37 ;
}
static void F_12 ( struct V_13 * V_14 , unsigned int V_46 )
{
unsigned int V_28 = 0 , V_47 = 0 , V_48 ;
struct V_49 * V_50 = F_13 ( & V_14 -> V_45 . V_51 -> V_45 ) ;
if ( ! V_50 )
return;
if ( F_14 ( V_46 >= V_52 ) ) {
F_15 ( V_14 -> V_45 . V_2 , L_2 , V_46 ) ;
V_46 = V_52 ;
}
F_11 ( V_14 -> V_45 . V_2 , L_3 , V_46 ) ;
while ( V_46 -- ) {
F_7 ( V_14 -> V_20 , V_11 , & V_47 ) ;
F_7 ( V_14 -> V_20 , V_5 , & V_28 ) ;
V_28 &= V_53 | V_54 |
V_55 | V_56 ;
V_14 -> V_45 . V_57 . V_58 ++ ;
V_48 = V_59 ;
if ( F_14 ( V_28 ) ) {
if ( V_28 & V_56 ) {
V_14 -> V_45 . V_57 . V_60 ++ ;
if ( F_16 ( & V_14 -> V_45 ) )
continue;
} else if ( V_28 & V_53 )
V_14 -> V_45 . V_57 . V_61 ++ ;
else if ( V_28 & V_54 )
V_14 -> V_45 . V_57 . V_62 ++ ;
else if ( V_28 & V_55 )
V_14 -> V_45 . V_57 . V_63 ++ ;
V_28 &= V_14 -> V_45 . V_64 ;
if ( V_28 & V_56 )
V_48 = V_65 ;
else if ( V_28 & V_53 )
V_48 = V_66 ;
else if ( V_28 & V_54 )
V_48 = V_67 ;
else if ( V_28 & V_55 )
V_48 = V_68 ;
}
if ( F_17 ( V_14 -> V_45 , V_47 ) )
continue;
if ( V_28 & V_14 -> V_45 . V_69 )
continue;
F_18 ( & V_14 -> V_45 , V_28 , V_55 ,
V_47 , V_48 ) ;
}
F_19 ( V_50 ) ;
F_20 ( V_50 ) ;
}
static void F_21 ( struct V_13 * V_14 )
{
struct V_70 * V_71 = & V_14 -> V_45 . V_51 -> V_71 ;
unsigned int V_72 = 0 , V_73 ;
if ( F_14 ( V_14 -> V_45 . V_74 ) ) {
F_5 ( V_14 -> V_20 , V_75 , V_14 -> V_45 . V_74 ) ;
V_14 -> V_45 . V_57 . V_76 ++ ;
V_14 -> V_45 . V_74 = 0 ;
return;
}
if ( F_22 ( V_71 ) || F_23 ( & V_14 -> V_45 ) )
return;
V_73 = F_24 ( V_71 ) ;
if ( F_25 ( V_73 ) ) {
F_7 ( V_14 -> V_20 , V_8 , & V_72 ) ;
V_72 = V_52 - V_72 ;
V_73 = ( V_73 > V_72 ) ? V_72 : V_73 ;
F_11 ( V_14 -> V_45 . V_2 , L_4 , V_73 ) ;
V_14 -> V_45 . V_57 . V_76 += V_73 ;
while ( V_73 -- ) {
F_5 ( V_14 -> V_20 , V_75 ,
V_71 -> V_77 [ V_71 -> V_78 ] ) ;
V_71 -> V_78 = ( V_71 -> V_78 + 1 ) & ( V_79 - 1 ) ;
} ;
}
if ( F_24 ( V_71 ) < V_80 )
F_26 ( & V_14 -> V_45 ) ;
}
static T_1 F_27 ( int V_81 , void * V_82 )
{
struct V_13 * V_14 = (struct V_13 * ) V_82 ;
unsigned int V_83 = 0 , V_84 = 0 , V_46 = 0 ;
F_28 ( & V_14 -> V_85 ) ;
for (; ; ) {
F_7 ( V_14 -> V_20 , V_4 , & V_83 ) ;
F_7 ( V_14 -> V_20 , V_5 , & V_84 ) ;
F_7 ( V_14 -> V_20 , V_9 , & V_46 ) ;
if ( ! V_83 && ! ( V_84 & V_86 ) && ! V_46 )
break;
F_11 ( V_14 -> V_45 . V_2 , L_5 , V_83 ) ;
if ( V_46 )
F_12 ( V_14 , V_46 ) ;
if ( V_83 & V_87 )
F_21 ( V_14 ) ;
if ( V_83 & V_88 )
F_29 ( & V_14 -> V_45 ,
! ! ( V_84 & V_89 ) ) ;
}
F_30 ( & V_14 -> V_85 ) ;
return V_90 ;
}
static void F_31 ( struct V_91 * V_92 )
{
struct V_13 * V_14 = F_32 ( V_92 , struct V_13 , V_93 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_21 ( V_14 ) ;
F_30 ( & V_14 -> V_85 ) ;
}
static void F_33 ( struct V_94 * V_45 )
{
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
F_34 ( V_14 -> V_95 , & V_14 -> V_93 ) ;
}
static void F_35 ( struct V_94 * V_45 )
{
}
static void F_36 ( struct V_94 * V_45 )
{
}
static unsigned int F_37 ( struct V_94 * V_45 )
{
unsigned int V_96 = 0 ;
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_7 ( V_14 -> V_20 , V_8 , & V_96 ) ;
F_30 ( & V_14 -> V_85 ) ;
return V_96 ? 0 : V_97 ;
}
static void F_38 ( struct V_94 * V_45 )
{
}
static unsigned int F_39 ( struct V_94 * V_45 )
{
return V_98 | V_99 ;
}
static void F_40 ( struct V_94 * V_45 , unsigned int V_100 )
{
}
static void F_41 ( struct V_94 * V_45 , int V_101 )
{
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_102 ,
V_103 ,
V_101 ? V_103 : 0 ) ;
F_30 ( & V_14 -> V_85 ) ;
}
static void F_43 ( struct V_94 * V_45 ,
struct V_104 * V_105 ,
struct V_104 * V_106 )
{
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
unsigned int V_107 , V_108 = 0 ;
int V_15 ;
F_28 ( & V_14 -> V_85 ) ;
V_105 -> V_109 &= ~ V_110 ;
V_105 -> V_111 &= ~ V_112 ;
switch ( V_105 -> V_109 & V_113 ) {
case V_114 :
V_107 = V_115 ;
break;
case V_116 :
V_107 = V_117 ;
break;
case V_118 :
V_107 = V_119 ;
break;
case V_120 :
default:
V_107 = V_121 ;
break;
}
if ( V_105 -> V_109 & V_122 ) {
V_107 |= V_123 ;
if ( ! ( V_105 -> V_109 & V_124 ) )
V_107 |= V_125 ;
}
if ( V_105 -> V_109 & V_126 )
V_107 |= V_127 ;
F_5 ( V_14 -> V_20 , V_102 , V_107 ) ;
V_45 -> V_64 = V_55 ;
if ( V_105 -> V_111 & V_128 )
V_45 -> V_64 |= V_53 |
V_54 ;
if ( V_105 -> V_111 & ( V_129 | V_130 ) )
V_45 -> V_64 |= V_56 ;
V_45 -> V_69 = 0 ;
if ( V_105 -> V_111 & V_131 )
V_45 -> V_69 |= V_56 ;
if ( ! ( V_105 -> V_109 & V_132 ) )
V_45 -> V_69 |= V_53 |
V_55 |
V_54 |
V_56 ;
F_5 ( V_14 -> V_20 , V_133 , V_105 -> V_134 [ V_135 ] ) ;
F_5 ( V_14 -> V_20 , V_136 , V_105 -> V_134 [ V_137 ] ) ;
if ( V_105 -> V_109 & V_138 )
V_108 |= V_139 |
V_140 ;
if ( V_105 -> V_111 & V_141 )
V_108 |= V_142 |
V_143 ;
if ( V_105 -> V_111 & V_144 )
V_108 |= V_145 |
V_143 ;
F_5 ( V_14 -> V_20 , V_146 , V_108 ) ;
V_15 = F_44 ( V_45 , V_105 , V_106 ,
V_45 -> V_17 / 16 / 0xffff ,
V_45 -> V_17 / 4 ) ;
F_4 ( V_14 , V_15 ) ;
F_45 ( V_45 , V_105 -> V_109 , V_15 ) ;
F_30 ( & V_14 -> V_85 ) ;
}
static int F_46 ( struct V_94 * V_45 )
{
unsigned int V_96 , line = V_45 -> line ;
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
if ( V_14 -> V_25 -> V_147 )
V_14 -> V_25 -> V_147 ( 0 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_4 ( V_14 , 9600 ) ;
V_96 = V_121 ;
F_5 ( V_14 -> V_20 , V_102 , V_96 ) ;
F_42 ( V_14 -> V_20 , V_148 ,
V_149 ,
( V_14 -> V_25 -> V_150 [ line ] & V_151 )
? V_149 : 0 ) ;
V_96 = V_152 ;
if ( V_14 -> V_25 -> V_150 [ line ] & V_153 )
V_96 |= V_154 ;
if ( V_14 -> V_25 -> V_150 [ line ] & V_155 )
V_96 |= V_156 ;
V_96 |= V_157 ;
F_5 ( V_14 -> V_20 , V_158 , V_96 ) ;
V_96 = F_47 ( 16 ) | F_48 ( 64 ) ;
F_5 ( V_14 -> V_20 , V_159 , V_96 ) ;
V_96 = F_49 ( 48 ) | F_50 ( 96 ) ;
F_5 ( V_14 -> V_20 , V_160 , V_96 ) ;
F_5 ( V_14 -> V_20 , V_161 , 0 ) ;
V_96 = V_86 ;
F_5 ( V_14 -> V_20 , V_162 , V_96 ) ;
F_42 ( V_14 -> V_20 , V_158 ,
V_157 , 0 ) ;
F_7 ( V_14 -> V_20 , V_4 , & V_96 ) ;
V_96 = V_88 ;
V_96 |= V_163 | V_87 ;
F_5 ( V_14 -> V_20 , V_164 , V_96 ) ;
F_30 ( & V_14 -> V_85 ) ;
return 0 ;
}
static void F_51 ( struct V_94 * V_45 )
{
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_5 ( V_14 -> V_20 , V_164 , 0 ) ;
F_30 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_25 -> V_147 )
V_14 -> V_25 -> V_147 ( 1 ) ;
}
static const char * F_52 ( struct V_94 * V_45 )
{
struct V_13 * V_14 = F_32 ( V_45 , struct V_13 , V_45 ) ;
return ( V_45 -> type == V_165 ) ? V_14 -> V_166 : NULL ;
}
static int F_53 ( struct V_94 * V_45 )
{
return 0 ;
}
static void F_54 ( struct V_94 * V_45 )
{
}
static void F_55 ( struct V_94 * V_45 , int V_167 )
{
if ( V_167 & V_168 )
V_45 -> type = V_165 ;
}
static int F_56 ( struct V_94 * V_45 , struct V_169 * V_170 )
{
if ( ( V_170 -> type == V_171 ) || ( V_170 -> type == V_165 ) )
return 0 ;
if ( V_170 -> V_81 == V_45 -> V_81 )
return 0 ;
return - V_172 ;
}
static int F_57 ( struct V_173 * V_174 , T_2 V_51 )
{
int V_175 ;
struct V_13 * V_14 = F_58 ( & V_174 -> V_2 ) ;
F_11 ( & V_174 -> V_2 , L_6 ) ;
V_175 = F_59 ( & V_14 -> V_176 , & V_14 -> V_45 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_148 ,
V_177 ,
V_177 ) ;
F_30 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_25 -> V_147 )
V_14 -> V_25 -> V_147 ( 1 ) ;
return V_175 ;
}
static int F_60 ( struct V_173 * V_174 )
{
struct V_13 * V_14 = F_58 ( & V_174 -> V_2 ) ;
F_11 ( & V_174 -> V_2 , L_7 ) ;
if ( V_14 -> V_25 -> V_147 )
V_14 -> V_25 -> V_147 ( 0 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_148 ,
V_177 ,
0 ) ;
F_6 ( V_14 ) ;
F_30 ( & V_14 -> V_85 ) ;
return F_61 ( & V_14 -> V_176 , & V_14 -> V_45 ) ;
}
static int F_62 ( struct V_178 * V_179 , unsigned V_180 )
{
unsigned int V_96 = 0 ;
struct V_13 * V_14 = F_32 ( V_179 , struct V_13 , V_181 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_7 ( V_14 -> V_20 , V_12 , & V_96 ) ;
F_30 ( & V_14 -> V_85 ) ;
return ! ! ( ( V_96 >> 4 ) & ( 1 << V_180 ) ) ;
}
static void F_63 ( struct V_178 * V_179 , unsigned V_180 , int V_182 )
{
struct V_13 * V_14 = F_32 ( V_179 , struct V_13 , V_181 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_12 , 1 << V_180 , V_182 ?
1 << V_180 : 0 ) ;
F_30 ( & V_14 -> V_85 ) ;
}
static int F_64 ( struct V_178 * V_179 , unsigned V_180 )
{
struct V_13 * V_14 = F_32 ( V_179 , struct V_13 , V_181 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_183 , 1 << V_180 , 0 ) ;
F_30 ( & V_14 -> V_85 ) ;
return 0 ;
}
static int F_65 ( struct V_178 * V_179 ,
unsigned V_180 , int V_182 )
{
struct V_13 * V_14 = F_32 ( V_179 , struct V_13 , V_181 ) ;
F_28 ( & V_14 -> V_85 ) ;
F_42 ( V_14 -> V_20 , V_183 , 1 << V_180 ,
1 << V_180 ) ;
F_42 ( V_14 -> V_20 , V_12 , 1 << V_180 , V_182 ?
1 << V_180 : 0 ) ;
F_30 ( & V_14 -> V_85 ) ;
return 0 ;
}
static int F_66 ( struct V_173 * V_174 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 = & V_174 -> V_2 ;
int V_184 = F_67 ( V_174 ) -> V_185 ;
struct V_186 * V_25 = V_2 -> V_187 ;
unsigned int V_96 = 0 ;
int V_175 ;
if ( V_174 -> V_81 <= 0 ) {
F_68 ( V_2 , L_8 ) ;
return - V_188 ;
}
V_14 = F_69 ( V_2 , sizeof( struct V_13 ) , V_189 ) ;
if ( ! V_14 ) {
F_68 ( V_2 , L_9 ) ;
return - V_190 ;
}
F_70 ( V_2 , V_14 ) ;
if ( ! V_25 ) {
F_15 ( V_2 , L_10 ) ;
V_25 = & V_191 ;
}
V_14 -> V_25 = V_25 ;
switch ( V_184 ) {
case V_192 :
V_14 -> V_166 = L_11 ;
V_14 -> V_193 = 4 ;
V_14 -> V_176 . V_194 = 1 ;
V_14 -> V_195 . V_196 = 0x1f ;
break;
case V_197 :
V_14 -> V_166 = L_12 ;
V_14 -> V_193 = 4 ;
V_14 -> V_176 . V_194 = 1 ;
V_14 -> V_195 . V_196 = 0x1e ;
break;
default:
F_68 ( V_2 , L_13 , V_184 ) ;
return - V_188 ;
}
if ( ( V_25 -> V_26 & V_27 ) &&
( ( V_25 -> V_38 < 500000 ) || ( V_25 -> V_38 > 35000000 ) ) )
goto V_198;
if ( ! ( V_25 -> V_26 & V_27 ) &&
( ( V_25 -> V_38 < 1000000 ) || ( V_25 -> V_38 > 4000000 ) ) )
goto V_198;
F_71 ( & V_14 -> V_85 ) ;
V_174 -> V_16 = V_199 ;
V_174 -> V_200 = 8 ;
V_174 -> V_201 = 26000000 ;
F_72 ( V_174 ) ;
V_14 -> V_195 . V_202 = 8 ;
V_14 -> V_195 . V_203 = 8 ;
V_14 -> V_195 . V_204 = 0x00 ;
V_14 -> V_195 . V_205 = 0x80 ;
V_14 -> V_195 . V_206 = V_207 ;
V_14 -> V_195 . V_208 = F_1 ;
V_14 -> V_195 . V_209 = F_2 ;
V_14 -> V_195 . V_210 = F_3 ;
V_14 -> V_20 = F_73 ( V_174 , & V_14 -> V_195 ) ;
if ( F_74 ( V_14 -> V_20 ) ) {
V_175 = F_75 ( V_14 -> V_20 ) ;
F_68 ( V_2 , L_14 ) ;
goto V_211;
}
V_175 = F_5 ( V_14 -> V_20 , V_158 , V_212 ) ;
if ( V_175 ) {
F_68 ( V_2 , L_15 ) ;
goto V_211;
}
F_5 ( V_14 -> V_20 , V_158 , 0 ) ;
switch ( V_184 ) {
case V_192 :
F_7 ( V_14 -> V_20 , V_10 , & V_96 ) ;
if ( ( ( V_96 & V_213 ) != V_214 ) ) {
F_68 ( V_2 , L_16 ,
V_14 -> V_166 , V_96 ) ;
V_175 = - V_215 ;
goto V_211;
}
break;
case V_197 :
F_7 ( V_14 -> V_20 , V_44 , & V_96 ) ;
if ( V_96 != ( V_39 |
V_43 ) ) {
F_68 ( V_2 , L_17 , V_14 -> V_166 ) ;
V_175 = - V_215 ;
goto V_211;
}
break;
}
if ( V_25 -> V_216 )
V_25 -> V_216 () ;
if ( V_25 -> V_147 )
V_25 -> V_147 ( 0 ) ;
V_14 -> V_17 = F_9 ( V_14 ) ;
F_5 ( V_14 -> V_20 , V_164 , 0 ) ;
V_96 = V_217 ;
if ( V_25 -> V_26 & V_218 )
V_96 = V_219 ;
F_5 ( V_14 -> V_20 , V_148 , V_96 ) ;
V_175 = F_76 ( V_2 , V_174 -> V_81 , NULL , F_27 ,
V_220 | V_221 ,
F_77 ( V_2 ) , V_14 ) ;
if ( V_175 ) {
F_68 ( V_2 , L_18 , V_174 -> V_81 ) ;
goto V_211;
}
V_14 -> V_176 . V_222 = V_223 ;
V_14 -> V_176 . V_224 = F_77 ( V_2 ) ;
V_14 -> V_176 . F_77 = L_19 ;
V_14 -> V_176 . V_225 = V_226 ;
V_14 -> V_176 . V_227 = V_228 ;
V_175 = F_78 ( & V_14 -> V_176 ) ;
if ( V_175 ) {
F_68 ( V_2 , L_20 ) ;
goto V_211;
}
V_14 -> V_95 = F_79 ( F_77 ( V_2 ) ) ;
F_80 ( & V_14 -> V_93 , F_31 ) ;
V_14 -> V_45 . line = 0 ;
V_14 -> V_45 . V_2 = V_2 ;
V_14 -> V_45 . V_81 = V_174 -> V_81 ;
V_14 -> V_45 . type = V_165 ;
V_14 -> V_45 . V_229 = V_52 ;
V_14 -> V_45 . V_167 = V_230 | V_231 ;
V_14 -> V_45 . V_232 = V_233 ;
V_14 -> V_45 . V_234 = ( void V_235 * ) 0xffffffff ;
V_14 -> V_45 . V_17 = V_14 -> V_17 ;
V_14 -> V_45 . V_236 = & V_237 ;
F_81 ( & V_14 -> V_176 , & V_14 -> V_45 ) ;
#ifdef F_82
if ( V_25 -> V_238 ) {
V_14 -> V_181 . V_222 = V_223 ;
V_14 -> V_181 . V_2 = V_2 ;
V_14 -> V_181 . V_239 = F_77 ( V_2 ) ;
V_14 -> V_181 . V_240 = F_64 ;
V_14 -> V_181 . V_241 = F_62 ;
V_14 -> V_181 . V_242 = F_65 ;
V_14 -> V_181 . V_243 = F_63 ;
V_14 -> V_181 . V_244 = V_25 -> V_238 ;
V_14 -> V_181 . V_245 = V_14 -> V_193 ;
V_14 -> V_181 . V_246 = 1 ;
if ( F_83 ( & V_14 -> V_181 ) ) {
V_14 -> V_181 . V_244 = 0 ;
}
} else
F_84 ( V_2 , L_21 ) ;
#endif
if ( V_25 -> V_147 )
V_25 -> V_147 ( 1 ) ;
return 0 ;
V_198:
F_68 ( V_2 , L_22 ) ;
V_175 = - V_172 ;
V_211:
F_70 ( V_2 , NULL ) ;
return V_175 ;
}
static int F_85 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = & V_174 -> V_2 ;
struct V_13 * V_14 = F_58 ( V_2 ) ;
int V_175 = 0 ;
F_11 ( V_2 , L_23 ) ;
F_86 ( V_2 , V_14 -> V_45 . V_81 , V_14 ) ;
F_87 ( V_14 -> V_95 ) ;
F_88 ( & V_14 -> V_176 , & V_14 -> V_45 ) ;
F_89 ( & V_14 -> V_176 ) ;
#ifdef F_82
if ( V_14 -> V_25 -> V_238 ) {
V_175 = F_90 ( & V_14 -> V_181 ) ;
if ( V_175 )
F_68 ( V_2 , L_24 , V_175 ) ;
}
#endif
F_70 ( V_2 , NULL ) ;
if ( V_14 -> V_25 -> V_147 )
V_14 -> V_25 -> V_147 ( 1 ) ;
if ( V_14 -> V_25 -> exit )
V_14 -> V_25 -> exit () ;
return V_175 ;
}
