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
if ( F_13 ( V_46 >= V_49 ) ) {
F_14 ( V_14 -> V_45 . V_2 , L_2 , V_46 ) ;
V_46 = V_49 ;
}
F_11 ( V_14 -> V_45 . V_2 , L_3 , V_46 ) ;
while ( V_46 -- ) {
F_7 ( V_14 -> V_20 , V_11 , & V_47 ) ;
F_7 ( V_14 -> V_20 , V_5 , & V_28 ) ;
V_28 &= V_50 | V_51 |
V_52 | V_53 ;
V_14 -> V_45 . V_54 . V_55 ++ ;
V_48 = V_56 ;
if ( F_13 ( V_28 ) ) {
if ( V_28 & V_53 ) {
V_14 -> V_45 . V_54 . V_57 ++ ;
if ( F_15 ( & V_14 -> V_45 ) )
continue;
} else if ( V_28 & V_50 )
V_14 -> V_45 . V_54 . V_58 ++ ;
else if ( V_28 & V_51 )
V_14 -> V_45 . V_54 . V_59 ++ ;
else if ( V_28 & V_52 )
V_14 -> V_45 . V_54 . V_60 ++ ;
V_28 &= V_14 -> V_45 . V_61 ;
if ( V_28 & V_53 )
V_48 = V_62 ;
else if ( V_28 & V_50 )
V_48 = V_63 ;
else if ( V_28 & V_51 )
V_48 = V_64 ;
else if ( V_28 & V_52 )
V_48 = V_65 ;
}
if ( F_16 ( V_14 -> V_45 , V_47 ) )
continue;
if ( V_28 & V_14 -> V_45 . V_66 )
continue;
F_17 ( & V_14 -> V_45 , V_28 , V_52 ,
V_47 , V_48 ) ;
}
F_18 ( & V_14 -> V_45 . V_67 -> V_45 ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
struct V_68 * V_69 = & V_14 -> V_45 . V_67 -> V_69 ;
unsigned int V_70 = 0 , V_71 ;
if ( F_13 ( V_14 -> V_45 . V_72 ) ) {
F_5 ( V_14 -> V_20 , V_73 , V_14 -> V_45 . V_72 ) ;
V_14 -> V_45 . V_54 . V_74 ++ ;
V_14 -> V_45 . V_72 = 0 ;
return;
}
if ( F_20 ( V_69 ) || F_21 ( & V_14 -> V_45 ) )
return;
V_71 = F_22 ( V_69 ) ;
if ( F_23 ( V_71 ) ) {
F_7 ( V_14 -> V_20 , V_8 , & V_70 ) ;
V_70 = V_49 - V_70 ;
V_71 = ( V_71 > V_70 ) ? V_70 : V_71 ;
F_11 ( V_14 -> V_45 . V_2 , L_4 , V_71 ) ;
V_14 -> V_45 . V_54 . V_74 += V_71 ;
while ( V_71 -- ) {
F_5 ( V_14 -> V_20 , V_73 ,
V_69 -> V_75 [ V_69 -> V_76 ] ) ;
V_69 -> V_76 = ( V_69 -> V_76 + 1 ) & ( V_77 - 1 ) ;
} ;
}
if ( F_22 ( V_69 ) < V_78 )
F_24 ( & V_14 -> V_45 ) ;
}
static T_1 F_25 ( int V_79 , void * V_80 )
{
struct V_13 * V_14 = (struct V_13 * ) V_80 ;
unsigned int V_81 = 0 , V_82 = 0 , V_46 = 0 ;
F_26 ( & V_14 -> V_83 ) ;
for (; ; ) {
F_7 ( V_14 -> V_20 , V_4 , & V_81 ) ;
F_7 ( V_14 -> V_20 , V_5 , & V_82 ) ;
F_7 ( V_14 -> V_20 , V_9 , & V_46 ) ;
if ( ! V_81 && ! ( V_82 & V_84 ) && ! V_46 )
break;
F_11 ( V_14 -> V_45 . V_2 , L_5 , V_81 ) ;
if ( V_46 )
F_12 ( V_14 , V_46 ) ;
if ( V_81 & V_85 )
F_19 ( V_14 ) ;
if ( V_81 & V_86 )
F_27 ( & V_14 -> V_45 ,
! ! ( V_82 & V_87 ) ) ;
}
F_28 ( & V_14 -> V_83 ) ;
return V_88 ;
}
static void F_29 ( struct V_89 * V_90 )
{
struct V_13 * V_14 = F_30 ( V_90 , struct V_13 , V_91 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_19 ( V_14 ) ;
F_28 ( & V_14 -> V_83 ) ;
}
static void F_31 ( struct V_92 * V_45 )
{
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
F_32 ( V_14 -> V_93 , & V_14 -> V_91 ) ;
}
static void F_33 ( struct V_92 * V_45 )
{
}
static void F_34 ( struct V_92 * V_45 )
{
}
static unsigned int F_35 ( struct V_92 * V_45 )
{
unsigned int V_94 = 0 ;
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_7 ( V_14 -> V_20 , V_8 , & V_94 ) ;
F_28 ( & V_14 -> V_83 ) ;
return V_94 ? 0 : V_95 ;
}
static void F_36 ( struct V_92 * V_45 )
{
}
static unsigned int F_37 ( struct V_92 * V_45 )
{
return V_96 | V_97 ;
}
static void F_38 ( struct V_92 * V_45 , unsigned int V_98 )
{
}
static void F_39 ( struct V_92 * V_45 , int V_99 )
{
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_100 ,
V_101 ,
V_99 ? V_101 : 0 ) ;
F_28 ( & V_14 -> V_83 ) ;
}
static void F_41 ( struct V_92 * V_45 ,
struct V_102 * V_103 ,
struct V_102 * V_104 )
{
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
unsigned int V_105 , V_106 = 0 ;
int V_15 ;
F_26 ( & V_14 -> V_83 ) ;
V_103 -> V_107 &= ~ V_108 ;
V_103 -> V_109 &= ~ V_110 ;
switch ( V_103 -> V_107 & V_111 ) {
case V_112 :
V_105 = V_113 ;
break;
case V_114 :
V_105 = V_115 ;
break;
case V_116 :
V_105 = V_117 ;
break;
case V_118 :
default:
V_105 = V_119 ;
break;
}
if ( V_103 -> V_107 & V_120 ) {
V_105 |= V_121 ;
if ( ! ( V_103 -> V_107 & V_122 ) )
V_105 |= V_123 ;
}
if ( V_103 -> V_107 & V_124 )
V_105 |= V_125 ;
F_5 ( V_14 -> V_20 , V_100 , V_105 ) ;
V_45 -> V_61 = V_52 ;
if ( V_103 -> V_109 & V_126 )
V_45 -> V_61 |= V_50 |
V_51 ;
if ( V_103 -> V_109 & ( V_127 | V_128 ) )
V_45 -> V_61 |= V_53 ;
V_45 -> V_66 = 0 ;
if ( V_103 -> V_109 & V_129 )
V_45 -> V_66 |= V_53 ;
if ( ! ( V_103 -> V_107 & V_130 ) )
V_45 -> V_66 |= V_50 |
V_52 |
V_51 |
V_53 ;
F_5 ( V_14 -> V_20 , V_131 , V_103 -> V_132 [ V_133 ] ) ;
F_5 ( V_14 -> V_20 , V_134 , V_103 -> V_132 [ V_135 ] ) ;
if ( V_103 -> V_107 & V_136 )
V_106 |= V_137 |
V_138 ;
if ( V_103 -> V_109 & V_139 )
V_106 |= V_140 |
V_141 ;
if ( V_103 -> V_109 & V_142 )
V_106 |= V_143 |
V_141 ;
F_5 ( V_14 -> V_20 , V_144 , V_106 ) ;
V_15 = F_42 ( V_45 , V_103 , V_104 ,
V_45 -> V_17 / 16 / 0xffff ,
V_45 -> V_17 / 4 ) ;
F_4 ( V_14 , V_15 ) ;
F_43 ( V_45 , V_103 -> V_107 , V_15 ) ;
F_28 ( & V_14 -> V_83 ) ;
}
static int F_44 ( struct V_92 * V_45 )
{
unsigned int V_94 , line = V_45 -> line ;
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
if ( V_14 -> V_25 -> V_145 )
V_14 -> V_25 -> V_145 ( 0 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_4 ( V_14 , 9600 ) ;
V_94 = V_119 ;
F_5 ( V_14 -> V_20 , V_100 , V_94 ) ;
F_40 ( V_14 -> V_20 , V_146 ,
V_147 ,
( V_14 -> V_25 -> V_148 [ line ] & V_149 )
? V_147 : 0 ) ;
V_94 = V_150 ;
if ( V_14 -> V_25 -> V_148 [ line ] & V_151 )
V_94 |= V_152 ;
if ( V_14 -> V_25 -> V_148 [ line ] & V_153 )
V_94 |= V_154 ;
V_94 |= V_155 ;
F_5 ( V_14 -> V_20 , V_156 , V_94 ) ;
V_94 = F_45 ( 16 ) | F_46 ( 64 ) ;
F_5 ( V_14 -> V_20 , V_157 , V_94 ) ;
V_94 = F_47 ( 48 ) | F_48 ( 96 ) ;
F_5 ( V_14 -> V_20 , V_158 , V_94 ) ;
F_5 ( V_14 -> V_20 , V_159 , 0 ) ;
V_94 = V_84 ;
F_5 ( V_14 -> V_20 , V_160 , V_94 ) ;
F_40 ( V_14 -> V_20 , V_156 ,
V_155 , 0 ) ;
F_7 ( V_14 -> V_20 , V_4 , & V_94 ) ;
V_94 = V_86 ;
V_94 |= V_161 | V_85 ;
F_5 ( V_14 -> V_20 , V_162 , V_94 ) ;
F_28 ( & V_14 -> V_83 ) ;
return 0 ;
}
static void F_49 ( struct V_92 * V_45 )
{
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_5 ( V_14 -> V_20 , V_162 , 0 ) ;
F_28 ( & V_14 -> V_83 ) ;
if ( V_14 -> V_25 -> V_145 )
V_14 -> V_25 -> V_145 ( 1 ) ;
}
static const char * F_50 ( struct V_92 * V_45 )
{
struct V_13 * V_14 = F_30 ( V_45 , struct V_13 , V_45 ) ;
return ( V_45 -> type == V_163 ) ? V_14 -> V_164 : NULL ;
}
static int F_51 ( struct V_92 * V_45 )
{
return 0 ;
}
static void F_52 ( struct V_92 * V_45 )
{
}
static void F_53 ( struct V_92 * V_45 , int V_165 )
{
if ( V_165 & V_166 )
V_45 -> type = V_163 ;
}
static int F_54 ( struct V_92 * V_45 , struct V_167 * V_168 )
{
if ( ( V_168 -> type == V_169 ) || ( V_168 -> type == V_163 ) )
return 0 ;
if ( V_168 -> V_79 == V_45 -> V_79 )
return 0 ;
return - V_170 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_171 ;
struct V_13 * V_14 = F_56 ( V_2 ) ;
F_11 ( V_2 , L_6 ) ;
V_171 = F_57 ( & V_14 -> V_172 , & V_14 -> V_45 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_146 ,
V_173 ,
V_173 ) ;
F_28 ( & V_14 -> V_83 ) ;
if ( V_14 -> V_25 -> V_145 )
V_14 -> V_25 -> V_145 ( 1 ) ;
return V_171 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_56 ( V_2 ) ;
F_11 ( V_2 , L_7 ) ;
if ( V_14 -> V_25 -> V_145 )
V_14 -> V_25 -> V_145 ( 0 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_146 ,
V_173 ,
0 ) ;
F_6 ( V_14 ) ;
F_28 ( & V_14 -> V_83 ) ;
return F_59 ( & V_14 -> V_172 , & V_14 -> V_45 ) ;
}
static int F_60 ( struct V_174 * V_175 , unsigned V_176 )
{
unsigned int V_94 = 0 ;
struct V_13 * V_14 = F_30 ( V_175 , struct V_13 , V_177 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_7 ( V_14 -> V_20 , V_12 , & V_94 ) ;
F_28 ( & V_14 -> V_83 ) ;
return ! ! ( ( V_94 >> 4 ) & ( 1 << V_176 ) ) ;
}
static void F_61 ( struct V_174 * V_175 , unsigned V_176 , int V_178 )
{
struct V_13 * V_14 = F_30 ( V_175 , struct V_13 , V_177 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_12 , 1 << V_176 , V_178 ?
1 << V_176 : 0 ) ;
F_28 ( & V_14 -> V_83 ) ;
}
static int F_62 ( struct V_174 * V_175 , unsigned V_176 )
{
struct V_13 * V_14 = F_30 ( V_175 , struct V_13 , V_177 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_179 , 1 << V_176 , 0 ) ;
F_28 ( & V_14 -> V_83 ) ;
return 0 ;
}
static int F_63 ( struct V_174 * V_175 ,
unsigned V_176 , int V_178 )
{
struct V_13 * V_14 = F_30 ( V_175 , struct V_13 , V_177 ) ;
F_26 ( & V_14 -> V_83 ) ;
F_40 ( V_14 -> V_20 , V_179 , 1 << V_176 ,
1 << V_176 ) ;
F_40 ( V_14 -> V_20 , V_12 , 1 << V_176 , V_178 ?
1 << V_176 : 0 ) ;
F_28 ( & V_14 -> V_83 ) ;
return 0 ;
}
static int F_64 ( struct V_180 * V_181 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 = & V_181 -> V_2 ;
int V_182 = F_65 ( V_181 ) -> V_183 ;
struct V_184 * V_25 = V_2 -> V_185 ;
unsigned int V_94 = 0 ;
int V_171 ;
if ( V_181 -> V_79 <= 0 ) {
F_66 ( V_2 , L_8 ) ;
return - V_186 ;
}
V_14 = F_67 ( V_2 , sizeof( struct V_13 ) , V_187 ) ;
if ( ! V_14 ) {
F_66 ( V_2 , L_9 ) ;
return - V_188 ;
}
F_68 ( V_2 , V_14 ) ;
if ( ! V_25 ) {
F_14 ( V_2 , L_10 ) ;
V_25 = & V_189 ;
}
V_14 -> V_25 = V_25 ;
switch ( V_182 ) {
case V_190 :
V_14 -> V_164 = L_11 ;
V_14 -> V_191 = 4 ;
V_14 -> V_172 . V_192 = 1 ;
V_14 -> V_193 . V_194 = 0x1f ;
break;
case V_195 :
V_14 -> V_164 = L_12 ;
V_14 -> V_191 = 4 ;
V_14 -> V_172 . V_192 = 1 ;
V_14 -> V_193 . V_194 = 0x1e ;
break;
default:
F_66 ( V_2 , L_13 , V_182 ) ;
return - V_186 ;
}
if ( ( V_25 -> V_26 & V_27 ) &&
( ( V_25 -> V_38 < 500000 ) || ( V_25 -> V_38 > 35000000 ) ) )
goto V_196;
if ( ! ( V_25 -> V_26 & V_27 ) &&
( ( V_25 -> V_38 < 1000000 ) || ( V_25 -> V_38 > 4000000 ) ) )
goto V_196;
F_69 ( & V_14 -> V_83 ) ;
V_181 -> V_16 = V_197 ;
V_181 -> V_198 = 8 ;
V_181 -> V_199 = 26000000 ;
F_70 ( V_181 ) ;
V_14 -> V_193 . V_200 = 8 ;
V_14 -> V_193 . V_201 = 8 ;
V_14 -> V_193 . V_202 = 0x00 ;
V_14 -> V_193 . V_203 = 0x80 ;
V_14 -> V_193 . V_204 = V_205 ;
V_14 -> V_193 . V_206 = F_1 ;
V_14 -> V_193 . V_207 = F_2 ;
V_14 -> V_193 . V_208 = F_3 ;
V_14 -> V_20 = F_71 ( V_181 , & V_14 -> V_193 ) ;
if ( F_72 ( V_14 -> V_20 ) ) {
V_171 = F_73 ( V_14 -> V_20 ) ;
F_66 ( V_2 , L_14 ) ;
goto V_209;
}
V_171 = F_5 ( V_14 -> V_20 , V_156 , V_210 ) ;
if ( V_171 ) {
F_66 ( V_2 , L_15 ) ;
goto V_209;
}
F_5 ( V_14 -> V_20 , V_156 , 0 ) ;
switch ( V_182 ) {
case V_190 :
F_7 ( V_14 -> V_20 , V_10 , & V_94 ) ;
if ( ( ( V_94 & V_211 ) != V_212 ) ) {
F_66 ( V_2 , L_16 ,
V_14 -> V_164 , V_94 ) ;
V_171 = - V_213 ;
goto V_209;
}
break;
case V_195 :
F_7 ( V_14 -> V_20 , V_44 , & V_94 ) ;
if ( V_94 != ( V_39 |
V_43 ) ) {
F_66 ( V_2 , L_17 , V_14 -> V_164 ) ;
V_171 = - V_213 ;
goto V_209;
}
break;
}
if ( V_25 -> V_214 )
V_25 -> V_214 () ;
if ( V_25 -> V_145 )
V_25 -> V_145 ( 0 ) ;
V_14 -> V_17 = F_9 ( V_14 ) ;
F_5 ( V_14 -> V_20 , V_162 , 0 ) ;
V_94 = V_215 ;
if ( V_25 -> V_26 & V_216 )
V_94 = V_217 ;
F_5 ( V_14 -> V_20 , V_146 , V_94 ) ;
V_171 = F_74 ( V_2 , V_181 -> V_79 , NULL , F_25 ,
V_218 | V_219 ,
F_75 ( V_2 ) , V_14 ) ;
if ( V_171 ) {
F_66 ( V_2 , L_18 , V_181 -> V_79 ) ;
goto V_209;
}
V_14 -> V_172 . V_220 = V_221 ;
V_14 -> V_172 . V_222 = F_75 ( V_2 ) ;
V_14 -> V_172 . F_75 = L_19 ;
V_14 -> V_172 . V_223 = V_224 ;
V_14 -> V_172 . V_225 = V_226 ;
V_171 = F_76 ( & V_14 -> V_172 ) ;
if ( V_171 ) {
F_66 ( V_2 , L_20 ) ;
goto V_209;
}
V_14 -> V_93 = F_77 ( F_75 ( V_2 ) ) ;
F_78 ( & V_14 -> V_91 , F_29 ) ;
V_14 -> V_45 . line = 0 ;
V_14 -> V_45 . V_2 = V_2 ;
V_14 -> V_45 . V_79 = V_181 -> V_79 ;
V_14 -> V_45 . type = V_163 ;
V_14 -> V_45 . V_227 = V_49 ;
V_14 -> V_45 . V_165 = V_228 | V_229 ;
V_14 -> V_45 . V_230 = V_231 ;
V_14 -> V_45 . V_232 = ( void V_233 * ) 0xffffffff ;
V_14 -> V_45 . V_17 = V_14 -> V_17 ;
V_14 -> V_45 . V_234 = & V_235 ;
F_79 ( & V_14 -> V_172 , & V_14 -> V_45 ) ;
#ifdef F_80
if ( V_25 -> V_236 ) {
V_14 -> V_177 . V_220 = V_221 ;
V_14 -> V_177 . V_2 = V_2 ;
V_14 -> V_177 . V_237 = F_75 ( V_2 ) ;
V_14 -> V_177 . V_238 = F_62 ;
V_14 -> V_177 . V_239 = F_60 ;
V_14 -> V_177 . V_240 = F_63 ;
V_14 -> V_177 . V_241 = F_61 ;
V_14 -> V_177 . V_242 = V_25 -> V_236 ;
V_14 -> V_177 . V_243 = V_14 -> V_191 ;
V_14 -> V_177 . V_244 = 1 ;
if ( F_81 ( & V_14 -> V_177 ) ) {
V_14 -> V_177 . V_242 = 0 ;
}
} else
F_82 ( V_2 , L_21 ) ;
#endif
if ( V_25 -> V_145 )
V_25 -> V_145 ( 1 ) ;
return 0 ;
V_196:
F_66 ( V_2 , L_22 ) ;
V_171 = - V_170 ;
V_209:
F_68 ( V_2 , NULL ) ;
return V_171 ;
}
static int F_83 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = & V_181 -> V_2 ;
struct V_13 * V_14 = F_56 ( V_2 ) ;
int V_171 = 0 ;
F_11 ( V_2 , L_23 ) ;
F_84 ( V_2 , V_14 -> V_45 . V_79 , V_14 ) ;
F_85 ( V_14 -> V_93 ) ;
F_86 ( & V_14 -> V_172 , & V_14 -> V_45 ) ;
F_87 ( & V_14 -> V_172 ) ;
#ifdef F_80
if ( V_14 -> V_25 -> V_236 ) {
V_171 = F_88 ( & V_14 -> V_177 ) ;
if ( V_171 )
F_66 ( V_2 , L_24 , V_171 ) ;
}
#endif
F_68 ( V_2 , NULL ) ;
if ( V_14 -> V_25 -> V_145 )
V_14 -> V_25 -> V_145 ( 1 ) ;
if ( V_14 -> V_25 -> exit )
V_14 -> V_25 -> exit () ;
return V_171 ;
}
