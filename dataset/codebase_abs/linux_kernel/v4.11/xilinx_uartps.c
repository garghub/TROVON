static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_5 = V_4 -> V_6 ;
unsigned int V_7 ;
unsigned int V_8 = 0 ;
unsigned int V_9 ;
unsigned int V_10 = 0 ;
char V_11 = V_12 ;
bool V_13 ;
V_13 = V_5 -> V_14 & V_15 ;
while ( ( F_2 ( V_4 -> V_16 + V_17 ) &
V_18 ) != V_18 ) {
if ( V_13 )
V_8 = F_2 ( V_4 -> V_16 + V_19 ) ;
V_7 = F_2 ( V_4 -> V_16 + V_20 ) ;
V_4 -> V_21 . V_22 ++ ;
if ( ! V_13 && ( V_2 & V_23 ) ) {
if ( ! V_7 ) {
V_4 -> V_24 |= V_25 ;
V_10 = 1 ;
continue;
}
}
if ( V_13 && ( V_8 & V_26 ) ) {
V_4 -> V_21 . V_27 ++ ;
V_11 = V_28 ;
if ( F_3 ( V_4 ) )
continue;
}
V_2 &= V_4 -> V_24 ;
V_2 &= ~ V_4 -> V_29 ;
V_9 = V_4 -> V_24 ;
V_9 &= ~ V_4 -> V_29 ;
if ( V_7 &&
( V_4 -> V_24 & V_25 ) ) {
V_4 -> V_24 &= ~ V_25 ;
V_4 -> V_21 . V_27 ++ ;
if ( F_3 ( V_4 ) )
continue;
}
if ( F_4 ( V_4 , V_7 ) )
continue;
if ( V_13 ) {
if ( ( V_8 & V_30 )
&& ( V_9 & V_31 ) ) {
V_4 -> V_21 . V_32 ++ ;
V_11 = V_33 ;
}
if ( ( V_8 & V_34 )
&& ( V_9 & V_31 ) ) {
V_4 -> V_21 . V_35 ++ ;
V_11 = V_36 ;
}
} else {
if ( V_2 & V_31 ) {
V_4 -> V_21 . V_32 ++ ;
V_11 = V_33 ;
}
if ( ( V_2 & V_23 ) &&
! V_10 ) {
V_4 -> V_21 . V_35 ++ ;
V_11 = V_36 ;
}
}
if ( V_2 & V_37 ) {
V_4 -> V_21 . V_38 ++ ;
F_5 ( & V_4 -> V_39 -> V_4 , 0 ,
V_40 ) ;
}
F_5 ( & V_4 -> V_39 -> V_4 , V_7 , V_11 ) ;
V_2 = 0 ;
}
F_6 ( & V_4 -> V_41 ) ;
F_7 ( & V_4 -> V_39 -> V_4 ) ;
F_8 ( & V_4 -> V_41 ) ;
}
static void F_9 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
unsigned int V_42 ;
if ( F_10 ( & V_4 -> V_39 -> V_43 ) ) {
F_11 ( V_44 , V_4 -> V_16 + V_45 ) ;
} else {
V_42 = V_4 -> V_46 ;
while ( V_42 && ! F_10 ( & V_4 -> V_39 -> V_43 ) &&
! ( F_2 ( V_4 -> V_16 + V_17 ) & V_47 ) ) {
F_11 (
V_4 -> V_39 -> V_43 . V_48 [ V_4 -> V_39 -> V_43 .
V_49 ] , V_4 -> V_16 + V_20 ) ;
V_4 -> V_21 . V_50 ++ ;
V_4 -> V_39 -> V_43 . V_49 =
( V_4 -> V_39 -> V_43 . V_49 + 1 ) &
( V_51 - 1 ) ;
V_42 -- ;
}
if ( F_12 (
& V_4 -> V_39 -> V_43 ) < V_52 )
F_13 ( V_4 ) ;
}
}
static T_1 F_14 ( int V_53 , void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
unsigned int V_2 ;
F_8 ( & V_4 -> V_41 ) ;
V_2 = F_2 ( V_4 -> V_16 + V_54 ) ;
F_11 ( V_2 , V_4 -> V_16 + V_54 ) ;
if ( V_2 & V_44 ) {
F_9 ( V_1 ) ;
V_2 &= ~ V_44 ;
}
if ( V_2 & V_55 )
F_1 ( V_1 , V_2 ) ;
F_6 ( & V_4 -> V_41 ) ;
return V_56 ;
}
static unsigned int F_15 ( unsigned int V_57 ,
unsigned int V_58 , T_2 * V_59 , T_2 * V_60 , int * V_61 )
{
T_2 V_62 , V_63 ;
unsigned int V_64 ;
unsigned int V_65 = 0 ;
unsigned int V_66 ;
unsigned int V_67 = ~ 0 ;
if ( V_58 < V_57 / ( ( V_68 + 1 ) * V_69 ) ) {
* V_61 = 1 ;
V_57 /= 8 ;
} else {
* V_61 = 0 ;
}
for ( V_63 = V_70 ; V_63 <= V_68 ; V_63 ++ ) {
V_62 = F_16 ( V_57 , V_58 * ( V_63 + 1 ) ) ;
if ( V_62 < 1 || V_62 > V_69 )
continue;
V_64 = V_57 / ( V_62 * ( V_63 + 1 ) ) ;
if ( V_58 > V_64 )
V_66 = V_58 - V_64 ;
else
V_66 = V_64 - V_58 ;
if ( V_67 > V_66 ) {
* V_59 = V_63 ;
* V_60 = V_62 ;
V_65 = V_64 ;
V_67 = V_66 ;
}
}
if ( ( ( V_67 * 100 ) / V_58 ) < 3 )
V_65 = V_58 ;
return V_65 ;
}
static unsigned int F_17 ( struct V_3 * V_4 ,
unsigned int V_58 )
{
unsigned int V_64 ;
T_2 V_62 = 0 , V_63 = 0 ;
T_2 V_71 ;
int V_61 ;
struct V_5 * V_5 = V_4 -> V_6 ;
V_64 = F_15 ( V_4 -> V_72 , V_58 , & V_63 , & V_62 ,
& V_61 ) ;
V_71 = F_2 ( V_4 -> V_16 + V_73 ) ;
if ( V_61 )
V_71 |= V_74 ;
else
V_71 &= ~ V_74 ;
F_11 ( V_71 , V_4 -> V_16 + V_73 ) ;
F_11 ( V_62 , V_4 -> V_16 + V_75 ) ;
F_11 ( V_63 , V_4 -> V_16 + V_76 ) ;
V_5 -> V_58 = V_58 ;
return V_64 ;
}
static int F_18 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_7 )
{
T_2 V_80 ;
struct V_3 * V_4 ;
int V_81 = 0 ;
struct V_82 * V_83 = V_7 ;
unsigned long V_84 = 0 ;
struct V_5 * V_5 = F_19 ( V_78 ) ;
V_4 = V_5 -> V_4 ;
if ( V_4 -> V_85 )
return V_86 ;
switch ( V_79 ) {
case V_87 :
{
T_2 V_63 , V_62 ;
int V_61 ;
if ( ! F_15 ( V_83 -> V_88 , V_5 -> V_58 ,
& V_63 , & V_62 , & V_61 ) ) {
F_20 ( V_4 -> V_89 , L_1 ) ;
return V_90 ;
}
F_21 ( & V_5 -> V_4 -> V_41 , V_84 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 |= V_92 | V_93 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
F_22 ( & V_5 -> V_4 -> V_41 , V_84 ) ;
return V_86 ;
}
case V_94 :
F_21 ( & V_5 -> V_4 -> V_41 , V_84 ) ;
V_81 = 1 ;
V_4 -> V_72 = V_83 -> V_88 ;
V_5 -> V_58 = F_17 ( V_5 -> V_4 ,
V_5 -> V_58 ) ;
case V_95 :
if ( ! V_81 )
F_21 ( & V_5 -> V_4 -> V_41 , V_84 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 |= V_96 | V_97 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
while ( F_2 ( V_4 -> V_16 + V_91 ) &
( V_96 | V_97 ) )
F_23 () ;
F_11 ( V_98 , V_4 -> V_16 + V_99 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 &= ~ ( V_92 | V_93 ) ;
V_80 |= V_100 | V_101 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
F_22 ( & V_5 -> V_4 -> V_41 , V_84 ) ;
return V_86 ;
default:
return V_102 ;
}
}
static void F_24 ( struct V_3 * V_4 )
{
unsigned int V_11 ;
if ( F_25 ( V_4 ) )
return;
V_11 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_11 &= ~ V_92 ;
V_11 |= V_100 ;
F_11 ( V_11 , V_4 -> V_16 + V_91 ) ;
if ( F_10 ( & V_4 -> V_39 -> V_43 ) )
return;
F_9 ( V_4 ) ;
F_11 ( V_44 , V_4 -> V_16 + V_54 ) ;
F_11 ( V_44 , V_4 -> V_16 + V_103 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
V_104 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_104 |= V_92 ;
F_11 ( V_104 , V_4 -> V_16 + V_91 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
F_11 ( V_105 , V_4 -> V_16 + V_45 ) ;
V_104 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_104 |= V_93 ;
F_11 ( V_104 , V_4 -> V_16 + V_91 ) ;
}
static unsigned int F_28 ( struct V_3 * V_4 )
{
unsigned int V_11 ;
V_11 = F_2 ( V_4 -> V_16 + V_17 ) &
V_106 ;
return V_11 ? V_107 : 0 ;
}
static void F_29 ( struct V_3 * V_4 , int V_108 )
{
unsigned int V_11 ;
unsigned long V_84 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
V_11 = F_2 ( V_4 -> V_16 + V_91 ) ;
if ( V_108 == - 1 )
F_11 ( V_109 | V_11 ,
V_4 -> V_16 + V_91 ) ;
else {
if ( ( V_11 & V_110 ) == 0 )
F_11 ( V_110 | V_11 ,
V_4 -> V_16 + V_91 ) ;
}
F_22 ( & V_4 -> V_41 , V_84 ) ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_111 * V_112 , struct V_111 * V_113 )
{
unsigned int V_114 = 0 ;
unsigned int V_58 , V_115 , V_116 ;
unsigned long V_84 ;
unsigned int V_80 , V_117 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
if ( ! ( F_2 ( V_4 -> V_16 + V_91 ) &
V_92 ) ) {
while ( ! ( F_2 ( V_4 -> V_16 + V_17 ) &
V_106 ) ) {
F_23 () ;
}
}
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 |= V_92 | V_93 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
V_115 = V_4 -> V_72 /
( ( V_68 + 1 ) * V_69 * 8 ) ;
V_116 = V_4 -> V_72 / ( V_70 + 1 ) ;
V_58 = F_31 ( V_4 , V_112 , V_113 , V_115 , V_116 ) ;
V_58 = F_17 ( V_4 , V_58 ) ;
if ( F_32 ( V_112 ) )
F_33 ( V_112 , V_58 , V_58 ) ;
F_34 ( V_4 , V_112 -> V_118 , V_58 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 |= V_96 | V_97 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
while ( F_2 ( V_4 -> V_16 + V_91 ) &
( V_96 | V_97 ) )
F_23 () ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 &= ~ ( V_92 | V_93 ) ;
V_80 |= V_100 | V_101 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
F_11 ( V_98 , V_4 -> V_16 + V_99 ) ;
V_4 -> V_24 = V_44 | V_119 |
V_37 | V_120 ;
V_4 -> V_29 = 0 ;
if ( V_112 -> V_121 & V_122 )
V_4 -> V_24 |= V_31 |
V_23 ;
if ( V_112 -> V_121 & V_123 )
V_4 -> V_29 |= V_31 |
V_23 | V_37 ;
if ( ( V_112 -> V_118 & V_124 ) == 0 )
V_4 -> V_29 |= V_119 |
V_120 | V_31 |
V_23 | V_37 ;
V_117 = F_2 ( V_4 -> V_16 + V_73 ) ;
switch ( V_112 -> V_118 & V_125 ) {
case V_126 :
V_114 |= V_127 ;
break;
case V_128 :
V_114 |= V_129 ;
break;
default:
case V_130 :
V_114 |= V_131 ;
V_112 -> V_118 &= ~ V_125 ;
V_112 -> V_118 |= V_130 ;
break;
}
if ( V_112 -> V_118 & V_132 )
V_114 |= V_133 ;
else
V_114 |= V_134 ;
if ( V_112 -> V_118 & V_135 ) {
if ( V_112 -> V_118 & V_136 ) {
if ( V_112 -> V_118 & V_137 )
V_114 |= V_138 ;
else
V_114 |= V_139 ;
} else {
if ( V_112 -> V_118 & V_137 )
V_114 |= V_140 ;
else
V_114 |= V_141 ;
}
} else {
V_114 |= V_142 ;
}
V_114 |= V_117 & 1 ;
F_11 ( V_114 , V_4 -> V_16 + V_73 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_6 ;
bool V_143 ;
int V_144 ;
unsigned long V_84 ;
unsigned int V_11 = 0 ;
V_143 = V_5 -> V_14 & V_15 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
F_11 ( V_92 | V_93 ,
V_4 -> V_16 + V_91 ) ;
F_11 ( V_96 | V_97 ,
V_4 -> V_16 + V_91 ) ;
while ( F_2 ( V_4 -> V_16 + V_91 ) &
( V_96 | V_97 ) )
F_23 () ;
V_11 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_11 &= V_93 ;
V_11 |= V_101 ;
F_11 ( V_11 , V_4 -> V_16 + V_91 ) ;
F_11 ( V_145 | V_134
| V_142 | V_131 ,
V_4 -> V_16 + V_73 ) ;
F_11 ( V_146 , V_4 -> V_16 + V_147 ) ;
F_11 ( V_98 , V_4 -> V_16 + V_99 ) ;
F_11 ( F_2 ( V_4 -> V_16 + V_54 ) ,
V_4 -> V_16 + V_54 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
V_144 = F_36 ( V_4 -> V_53 , F_14 , 0 , V_148 , V_4 ) ;
if ( V_144 ) {
F_37 ( V_4 -> V_89 , L_2 ,
V_4 -> V_53 , V_144 ) ;
return V_144 ;
}
if ( V_143 )
F_11 ( V_105 | V_25 ,
V_4 -> V_16 + V_103 ) ;
else
F_11 ( V_105 , V_4 -> V_16 + V_103 ) ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_84 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
V_11 = F_2 ( V_4 -> V_16 + V_149 ) ;
F_11 ( V_11 , V_4 -> V_16 + V_45 ) ;
F_11 ( 0xffffffff , V_4 -> V_16 + V_54 ) ;
F_11 ( V_92 | V_93 ,
V_4 -> V_16 + V_91 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
F_39 ( V_4 -> V_53 , V_4 ) ;
}
static const char * F_40 ( struct V_3 * V_4 )
{
return V_4 -> type == V_150 ? V_148 : NULL ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_151 * V_152 )
{
if ( V_152 -> type != V_153 && V_152 -> type != V_150 )
return - V_154 ;
if ( V_4 -> V_53 != V_152 -> V_53 )
return - V_154 ;
if ( V_152 -> V_155 != V_156 )
return - V_154 ;
if ( V_4 -> V_157 != V_152 -> V_4 )
return - V_154 ;
if ( V_152 -> V_158 != 0 )
return - V_154 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
if ( ! F_43 ( V_4 -> V_159 , V_160 ,
V_148 ) ) {
return - V_161 ;
}
V_4 -> V_16 = F_44 ( V_4 -> V_159 , V_160 ) ;
if ( ! V_4 -> V_16 ) {
F_37 ( V_4 -> V_89 , L_3 ) ;
F_45 ( V_4 -> V_159 , V_160 ) ;
return - V_161 ;
}
return 0 ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_45 ( V_4 -> V_159 , V_160 ) ;
F_47 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
}
static void F_48 ( struct V_3 * V_4 , int V_84 )
{
if ( V_84 & V_162 && F_42 ( V_4 ) == 0 )
V_4 -> type = V_150 ;
}
static unsigned int F_49 ( struct V_3 * V_4 )
{
return V_163 | V_164 | V_165 ;
}
static void F_50 ( struct V_3 * V_4 , unsigned int V_166 )
{
T_2 V_167 ;
T_2 V_117 ;
V_167 = F_2 ( V_4 -> V_16 + V_168 ) ;
V_117 = F_2 ( V_4 -> V_16 + V_73 ) ;
V_167 &= ~ ( V_169 | V_170 ) ;
V_117 &= ~ V_171 ;
if ( V_166 & V_172 )
V_167 |= V_169 ;
if ( V_166 & V_173 )
V_167 |= V_170 ;
if ( V_166 & V_174 )
V_117 |= V_175 ;
else
V_117 |= V_145 ;
F_11 ( V_167 , V_4 -> V_16 + V_168 ) ;
F_11 ( V_117 , V_4 -> V_16 + V_73 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
int V_176 ;
unsigned long V_84 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
if ( F_2 ( V_4 -> V_16 + V_17 ) & V_18 )
V_176 = V_177 ;
else
V_176 = ( unsigned char ) F_2 ( V_4 -> V_16 + V_20 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
return V_176 ;
}
static void F_52 ( struct V_3 * V_4 , unsigned char V_176 )
{
unsigned long V_84 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
while ( ! ( F_2 ( V_4 -> V_16 + V_17 ) & V_106 ) )
F_23 () ;
F_11 ( V_176 , V_4 -> V_16 + V_20 ) ;
while ( ! ( F_2 ( V_4 -> V_16 + V_17 ) & V_106 ) )
F_23 () ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
return;
}
static void F_53 ( struct V_3 * V_4 , unsigned int V_39 ,
unsigned int V_178 )
{
struct V_5 * V_5 = V_4 -> V_6 ;
switch ( V_39 ) {
case V_179 :
F_54 ( V_5 -> V_72 ) ;
F_54 ( V_5 -> V_180 ) ;
break;
default:
F_55 ( V_5 -> V_180 ) ;
F_55 ( V_5 -> V_72 ) ;
break;
}
}
static struct V_3 * F_56 ( int V_181 )
{
struct V_3 * V_4 ;
if ( V_182 [ V_181 ] . V_159 != 0 ) {
for ( V_181 = 0 ; V_181 < V_183 ; V_181 ++ )
if ( V_182 [ V_181 ] . V_159 == 0 )
break;
}
if ( V_181 >= V_183 )
return NULL ;
V_4 = & V_182 [ V_181 ] ;
F_57 ( & V_4 -> V_41 ) ;
V_4 -> V_16 = NULL ;
V_4 -> V_53 = 0 ;
V_4 -> type = V_153 ;
V_4 -> V_184 = V_185 ;
V_4 -> V_84 = V_186 ;
V_4 -> V_187 = & V_188 ;
V_4 -> V_46 = V_189 ;
V_4 -> line = V_181 ;
V_4 -> V_89 = NULL ;
return V_4 ;
}
static void F_58 ( struct V_3 * V_4 )
{
while ( ! ( F_2 ( V_4 -> V_16 + V_17 ) & V_106 ) )
F_59 () ;
}
static void F_60 ( struct V_3 * V_4 , int V_190 )
{
F_58 ( V_4 ) ;
F_11 ( V_190 , V_4 -> V_16 + V_20 ) ;
}
static void T_3 F_61 ( struct V_191 * V_192 , const char * V_193 ,
unsigned V_194 )
{
struct V_195 * V_89 = V_192 -> V_7 ;
F_62 ( & V_89 -> V_4 , V_193 , V_194 , F_60 ) ;
}
static int T_3 F_63 ( struct V_195 * V_196 ,
const char * V_197 )
{
struct V_3 * V_4 = & V_196 -> V_4 ;
if ( ! V_4 -> V_16 )
return - V_198 ;
F_11 ( V_100 | V_96 | V_97 ,
V_4 -> V_16 + V_91 ) ;
if ( V_196 -> V_58 ) {
T_2 V_62 = 0 , V_63 = 0 ;
T_2 V_199 ;
int V_61 ;
F_15 ( V_4 -> V_72 , V_196 -> V_58 ,
& V_63 , & V_62 , & V_61 ) ;
V_199 = V_142 ;
if ( V_61 )
V_199 |= V_74 ;
F_11 ( V_199 , V_4 -> V_16 + V_73 ) ;
F_11 ( V_62 , V_4 -> V_16 + V_75 ) ;
F_11 ( V_63 , V_4 -> V_16 + V_76 ) ;
}
V_196 -> V_192 -> V_200 = F_61 ;
return 0 ;
}
static void F_64 ( struct V_191 * V_201 , const char * V_193 ,
unsigned int V_202 )
{
struct V_3 * V_4 = & V_182 [ V_201 -> V_203 ] ;
unsigned long V_84 ;
unsigned int V_204 , V_205 ;
int V_81 = 1 ;
if ( V_4 -> V_206 )
V_81 = 0 ;
else if ( V_207 )
V_81 = F_65 ( & V_4 -> V_41 , V_84 ) ;
else
F_21 ( & V_4 -> V_41 , V_84 ) ;
V_204 = F_2 ( V_4 -> V_16 + V_149 ) ;
F_11 ( V_204 , V_4 -> V_16 + V_45 ) ;
V_205 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_205 &= ~ V_92 ;
V_205 |= V_100 ;
F_11 ( V_205 , V_4 -> V_16 + V_91 ) ;
F_62 ( V_4 , V_193 , V_202 , F_60 ) ;
F_58 ( V_4 ) ;
F_11 ( V_205 , V_4 -> V_16 + V_91 ) ;
F_11 ( V_204 , V_4 -> V_16 + V_103 ) ;
if ( V_81 )
F_22 ( & V_4 -> V_41 , V_84 ) ;
}
static int T_3 F_66 ( struct V_191 * V_201 , char * V_208 )
{
struct V_3 * V_4 = & V_182 [ V_201 -> V_203 ] ;
int V_58 = 9600 ;
int V_209 = 8 ;
int V_32 = 'n' ;
int V_210 = 'n' ;
if ( V_201 -> V_203 < 0 || V_201 -> V_203 >= V_183 )
return - V_154 ;
if ( ! V_4 -> V_16 ) {
F_67 ( L_4 V_211 L_5 ,
V_201 -> V_203 ) ;
return - V_198 ;
}
if ( V_208 )
F_68 ( V_208 , & V_58 , & V_32 , & V_209 , & V_210 ) ;
return F_69 ( V_4 , V_201 , V_58 , V_32 , V_209 , V_210 ) ;
}
static int T_3 F_70 ( void )
{
F_71 ( & V_212 ) ;
return 0 ;
}
static int F_72 ( struct V_196 * V_196 )
{
struct V_3 * V_4 = F_73 ( V_196 ) ;
struct V_213 * V_214 ;
struct V_196 * V_215 ;
int V_216 = 0 ;
V_214 = F_74 ( & V_4 -> V_39 -> V_4 ) ;
if ( V_214 ) {
V_215 = V_214 -> V_89 ;
V_216 = F_75 ( V_215 ) ;
F_76 ( V_214 ) ;
}
F_77 ( & V_217 , V_4 ) ;
if ( V_218 && ! V_216 ) {
struct V_5 * V_5 = V_4 -> V_6 ;
F_54 ( V_5 -> V_72 ) ;
F_54 ( V_5 -> V_180 ) ;
} else {
unsigned long V_84 = 0 ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
while ( ! ( F_2 ( V_4 -> V_16 + V_17 ) &
V_18 ) )
F_2 ( V_4 -> V_16 + V_20 ) ;
F_11 ( 1 , V_4 -> V_16 + V_147 ) ;
F_11 ( V_120 , V_4 -> V_16 + V_45 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
}
return 0 ;
}
static int F_78 ( struct V_196 * V_196 )
{
struct V_3 * V_4 = F_73 ( V_196 ) ;
unsigned long V_84 = 0 ;
T_2 V_80 ;
struct V_213 * V_214 ;
struct V_196 * V_215 ;
int V_216 = 0 ;
V_214 = F_74 ( & V_4 -> V_39 -> V_4 ) ;
if ( V_214 ) {
V_215 = V_214 -> V_89 ;
V_216 = F_75 ( V_215 ) ;
F_76 ( V_214 ) ;
}
if ( V_218 && ! V_216 ) {
struct V_5 * V_5 = V_4 -> V_6 ;
F_55 ( V_5 -> V_180 ) ;
F_55 ( V_5 -> V_72 ) ;
F_21 ( & V_4 -> V_41 , V_84 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 |= V_96 | V_97 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
while ( F_2 ( V_4 -> V_16 + V_91 ) &
( V_96 | V_97 ) )
F_23 () ;
F_11 ( V_98 , V_4 -> V_16 + V_99 ) ;
V_80 = F_2 ( V_4 -> V_16 + V_91 ) ;
V_80 &= ~ ( V_92 | V_93 ) ;
V_80 |= V_100 | V_101 ;
F_11 ( V_80 , V_4 -> V_16 + V_91 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
} else {
F_21 ( & V_4 -> V_41 , V_84 ) ;
F_11 ( V_146 , V_4 -> V_16 + V_147 ) ;
F_11 ( V_120 , V_4 -> V_16 + V_103 ) ;
F_22 ( & V_4 -> V_41 , V_84 ) ;
}
return F_79 ( & V_217 , V_4 ) ;
}
static int F_80 ( struct V_219 * V_220 )
{
int V_221 , V_181 , V_53 ;
struct V_3 * V_4 ;
struct V_222 * V_223 ;
struct V_5 * V_224 ;
const struct V_225 * V_226 ;
V_224 = F_81 ( & V_220 -> V_89 , sizeof( * V_224 ) ,
V_227 ) ;
if ( ! V_224 )
return - V_161 ;
V_226 = F_82 ( V_228 , V_220 -> V_89 . V_229 ) ;
if ( V_226 && V_226 -> V_7 ) {
const struct V_230 * V_7 = V_226 -> V_7 ;
V_224 -> V_14 = V_7 -> V_14 ;
}
V_224 -> V_180 = F_83 ( & V_220 -> V_89 , L_6 ) ;
if ( F_84 ( V_224 -> V_180 ) ) {
V_224 -> V_180 = F_83 ( & V_220 -> V_89 , L_7 ) ;
if ( ! F_84 ( V_224 -> V_180 ) )
F_37 ( & V_220 -> V_89 , L_8 ) ;
}
if ( F_84 ( V_224 -> V_180 ) ) {
F_37 ( & V_220 -> V_89 , L_9 ) ;
return F_85 ( V_224 -> V_180 ) ;
}
V_224 -> V_72 = F_83 ( & V_220 -> V_89 , L_10 ) ;
if ( F_84 ( V_224 -> V_72 ) ) {
V_224 -> V_72 = F_83 ( & V_220 -> V_89 , L_11 ) ;
if ( ! F_84 ( V_224 -> V_72 ) )
F_37 ( & V_220 -> V_89 , L_12 ) ;
}
if ( F_84 ( V_224 -> V_72 ) ) {
F_37 ( & V_220 -> V_89 , L_13 ) ;
return F_85 ( V_224 -> V_72 ) ;
}
V_221 = F_86 ( V_224 -> V_180 ) ;
if ( V_221 ) {
F_37 ( & V_220 -> V_89 , L_14 ) ;
return V_221 ;
}
V_221 = F_86 ( V_224 -> V_72 ) ;
if ( V_221 ) {
F_37 ( & V_220 -> V_89 , L_15 ) ;
goto V_231;
}
V_223 = F_87 ( V_220 , V_232 , 0 ) ;
if ( ! V_223 ) {
V_221 = - V_198 ;
goto V_233;
}
V_53 = F_88 ( V_220 , 0 ) ;
if ( V_53 <= 0 ) {
V_221 = - V_234 ;
goto V_233;
}
#ifdef F_89
V_224 -> V_235 . V_236 =
F_18 ;
if ( F_90 ( V_224 -> V_72 ,
& V_224 -> V_235 ) )
F_20 ( & V_220 -> V_89 , L_16 ) ;
#endif
V_181 = F_91 ( V_220 -> V_89 . V_229 , L_17 ) ;
if ( V_181 < 0 )
V_181 = 0 ;
V_4 = F_56 ( V_181 ) ;
if ( ! V_4 ) {
F_37 ( & V_220 -> V_89 , L_18 ) ;
V_221 = - V_198 ;
goto V_237;
}
V_4 -> V_159 = V_223 -> V_238 ;
V_4 -> V_53 = V_53 ;
V_4 -> V_89 = & V_220 -> V_89 ;
V_4 -> V_72 = F_92 ( V_224 -> V_72 ) ;
V_4 -> V_6 = V_224 ;
V_224 -> V_4 = V_4 ;
F_93 ( V_220 , V_4 ) ;
V_221 = F_94 ( & V_217 , V_4 ) ;
if ( V_221 ) {
F_37 ( & V_220 -> V_89 ,
L_19 , V_221 ) ;
goto V_237;
}
return 0 ;
V_237:
#ifdef F_89
F_95 ( V_224 -> V_72 ,
& V_224 -> V_235 ) ;
#endif
V_233:
F_96 ( V_224 -> V_72 ) ;
V_231:
F_96 ( V_224 -> V_180 ) ;
return V_221 ;
}
static int F_97 ( struct V_219 * V_220 )
{
struct V_3 * V_4 = F_98 ( V_220 ) ;
struct V_5 * V_224 = V_4 -> V_6 ;
int V_221 ;
#ifdef F_89
F_95 ( V_224 -> V_72 ,
& V_224 -> V_235 ) ;
#endif
V_221 = F_99 ( & V_217 , V_4 ) ;
V_4 -> V_159 = 0 ;
F_96 ( V_224 -> V_72 ) ;
F_96 ( V_224 -> V_180 ) ;
return V_221 ;
}
static int T_3 F_100 ( void )
{
int V_239 = 0 ;
V_239 = F_101 ( & V_217 ) ;
if ( V_239 )
return V_239 ;
V_239 = F_102 ( & V_240 ) ;
if ( V_239 )
F_103 ( & V_217 ) ;
return V_239 ;
}
static void T_4 F_104 ( void )
{
F_105 ( & V_240 ) ;
F_103 ( & V_217 ) ;
}
