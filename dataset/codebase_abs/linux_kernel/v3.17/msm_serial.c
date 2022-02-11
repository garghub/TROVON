static inline void F_1 ( struct V_1 * V_2 )
{
while ( ! ( F_2 ( V_2 , V_3 ) & V_4 ) ) {
if ( F_2 ( V_2 , V_5 ) & V_6 )
break;
F_3 ( 1 ) ;
}
F_4 ( V_2 , V_7 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 &= ~ V_11 ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 |= V_11 ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 &= ~ ( V_13 | V_14 ) ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 |= V_15 ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_19 -> V_2 ;
unsigned int V_20 ;
int V_21 = 0 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
if ( ( F_2 ( V_2 , V_3 ) & V_22 ) ) {
V_2 -> V_23 . V_24 ++ ;
F_11 ( V_18 , 0 , V_25 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
}
if ( V_16 & V_14 ) {
V_21 = F_2 ( V_2 , V_27 ) -
V_9 -> V_28 ;
V_9 -> V_28 = 0 ;
} else {
V_21 = 4 * ( F_2 ( V_2 , V_29 ) ) ;
V_9 -> V_28 += V_21 ;
}
V_2 -> V_23 . V_30 += V_21 ;
while ( V_21 > 0 ) {
unsigned char V_31 [ 4 ] ;
V_20 = F_2 ( V_2 , V_3 ) ;
if ( ( V_20 & V_32 ) == 0 ) {
V_9 -> V_28 -= V_21 ;
break;
}
F_12 ( V_2 -> V_33 + V_34 , V_31 , 1 ) ;
if ( V_20 & V_35 ) {
V_2 -> V_23 . V_36 ++ ;
if ( F_13 ( V_2 ) )
continue;
} else if ( V_20 & V_37 )
V_2 -> V_23 . V_38 ++ ;
F_14 ( V_18 , V_31 , F_15 ( V_21 , 4 ) ) ;
V_21 -= 4 ;
}
F_16 ( & V_2 -> V_39 ) ;
F_17 ( V_18 ) ;
F_18 ( & V_2 -> V_39 ) ;
if ( V_16 & ( V_14 ) )
F_4 ( V_2 , V_40 , V_8 ) ;
F_4 ( V_2 , 0xFFFFFF , V_41 ) ;
F_4 ( V_2 , V_42 , V_8 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_19 -> V_2 ;
unsigned int V_20 ;
if ( ( F_2 ( V_2 , V_3 ) & V_22 ) ) {
V_2 -> V_23 . V_24 ++ ;
F_11 ( V_18 , 0 , V_25 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
}
while ( ( V_20 = F_2 ( V_2 , V_3 ) ) & V_32 ) {
unsigned int V_43 ;
char V_44 = V_45 ;
V_43 = F_2 ( V_2 , V_46 ) ;
if ( V_20 & V_35 ) {
V_2 -> V_23 . V_36 ++ ;
if ( F_13 ( V_2 ) )
continue;
} else if ( V_20 & V_37 ) {
V_2 -> V_23 . V_38 ++ ;
} else {
V_2 -> V_23 . V_30 ++ ;
}
V_20 &= V_2 -> V_47 ;
if ( V_20 & V_35 ) {
V_44 = V_48 ;
} else if ( V_20 & V_37 ) {
V_44 = V_49 ;
}
if ( ! F_20 ( V_2 , V_43 ) )
F_11 ( V_18 , V_43 , V_44 ) ;
}
F_16 ( & V_2 -> V_39 ) ;
F_17 ( V_18 ) ;
F_18 ( & V_2 -> V_39 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_21 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 , V_21 , V_50 ) ;
F_2 ( V_2 , V_50 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = & V_2 -> V_19 -> V_52 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_53 , V_54 ;
unsigned int V_55 = 0 ;
void T_1 * V_56 ;
if ( V_9 -> V_57 )
V_56 = V_2 -> V_33 + V_58 ;
else
V_56 = V_2 -> V_33 + V_59 ;
V_53 = F_23 ( V_52 ) ;
V_53 = F_24 ( V_53 , ( unsigned int ) V_60 - V_52 -> V_61 ,
V_2 -> V_62 ) ;
if ( V_2 -> V_63 ) {
if ( V_9 -> V_57 )
F_21 ( V_2 , V_53 + 1 ) ;
F_25 ( V_56 , & V_2 -> V_63 , 1 ) ;
V_2 -> V_23 . V_64 ++ ;
V_2 -> V_63 = 0 ;
} else if ( V_53 && V_9 -> V_57 ) {
F_21 ( V_2 , V_53 ) ;
}
while ( V_55 < V_53 ) {
int V_65 ;
char V_31 [ 4 ] = { 0 } ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_66 ) )
break;
if ( V_9 -> V_57 )
V_54 = F_15 ( V_53 - V_55 ,
( unsigned int ) sizeof( V_31 ) ) ;
else
V_54 = 1 ;
for ( V_65 = 0 ; V_65 < V_54 ; V_65 ++ ) {
V_31 [ V_65 ] = V_52 -> V_31 [ V_52 -> V_61 + V_65 ] ;
V_2 -> V_23 . V_64 ++ ;
}
F_26 ( V_56 , V_31 , 1 ) ;
V_52 -> V_61 = ( V_52 -> V_61 + V_54 ) & ( V_60 - 1 ) ;
V_55 += V_54 ;
}
if ( F_27 ( V_52 ) )
F_5 ( V_2 ) ;
if ( F_23 ( V_52 ) < V_67 )
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_68 , V_8 ) ;
V_2 -> V_23 . V_69 ++ ;
F_30 ( & V_2 -> V_19 -> V_2 . V_70 ) ;
}
static T_2 F_31 ( int V_71 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_16 ;
F_18 ( & V_2 -> V_39 ) ;
V_16 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_16 & ( V_13 | V_14 ) ) {
if ( V_9 -> V_57 )
F_10 ( V_2 , V_16 ) ;
else
F_19 ( V_2 ) ;
}
if ( V_16 & V_11 )
F_22 ( V_2 ) ;
if ( V_16 & V_15 )
F_29 ( V_2 ) ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
F_16 ( & V_2 -> V_39 ) ;
return V_74 ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , V_3 ) & V_4 ) ? V_75 : 0 ;
}
static unsigned int F_33 ( struct V_1 * V_2 )
{
return V_76 | V_77 | V_78 | V_79 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
F_4 ( V_2 , V_80 , V_8 ) ;
F_4 ( V_2 , V_81 , V_8 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
F_4 ( V_2 , V_82 , V_8 ) ;
F_4 ( V_2 , V_68 , V_8 ) ;
F_4 ( V_2 , V_83 , V_8 ) ;
if ( V_9 -> V_57 )
F_4 ( V_2 , 0 , V_84 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_85 )
{
unsigned int V_86 ;
V_86 = F_2 ( V_2 , V_87 ) ;
if ( ! ( V_85 & V_79 ) ) {
V_86 &= ~ V_88 ;
F_4 ( V_2 , V_86 , V_87 ) ;
F_4 ( V_2 , V_89 , V_8 ) ;
} else {
V_86 |= V_88 ;
F_4 ( V_2 , V_86 , V_87 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , int V_90 )
{
if ( V_90 )
F_4 ( V_2 , V_91 , V_8 ) ;
else
F_4 ( V_2 , V_92 , V_8 ) ;
}
static const struct V_93 *
F_37 ( struct V_1 * V_2 , unsigned int V_94 )
{
unsigned int V_65 , V_95 ;
const struct V_93 * V_96 ;
static const struct V_93 V_97 [] = {
{ 1536 , 0x00 , 1 } ,
{ 768 , 0x11 , 1 } ,
{ 384 , 0x22 , 1 } ,
{ 192 , 0x33 , 1 } ,
{ 96 , 0x44 , 1 } ,
{ 48 , 0x55 , 1 } ,
{ 32 , 0x66 , 1 } ,
{ 24 , 0x77 , 1 } ,
{ 16 , 0x88 , 1 } ,
{ 12 , 0x99 , 6 } ,
{ 8 , 0xaa , 6 } ,
{ 6 , 0xbb , 6 } ,
{ 4 , 0xcc , 6 } ,
{ 3 , 0xdd , 8 } ,
{ 2 , 0xee , 16 } ,
{ 1 , 0xff , 31 } ,
} ;
V_95 = F_38 ( V_2 , V_94 ) ;
for ( V_65 = 0 , V_96 = V_97 ; V_65 < F_39 ( V_97 ) ; V_65 ++ , V_96 ++ )
if ( V_96 -> V_95 <= V_95 )
break;
return V_96 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_94 )
{
unsigned int V_98 , V_99 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
const struct V_93 * V_96 ;
V_96 = F_37 ( V_2 , V_94 ) ;
if ( V_9 -> V_57 )
F_4 ( V_2 , V_80 , V_8 ) ;
F_4 ( V_2 , V_96 -> V_100 , V_101 ) ;
V_98 = V_96 -> V_98 ;
V_99 = V_102 & V_98 ;
V_99 |= V_103 ;
V_99 |= V_104 & ( V_98 << 2 ) ;
F_4 ( V_2 , V_99 , V_105 ) ;
V_99 = ( V_2 -> V_62 * 3 ) / 4 ;
F_4 ( V_2 , V_99 , V_29 ) ;
F_4 ( V_2 , 10 , V_106 ) ;
if ( V_9 -> V_57 ) {
F_4 ( V_2 , V_40 , V_8 ) ;
F_4 ( V_2 , 0xFFFFFF , V_41 ) ;
F_4 ( V_2 , V_42 , V_8 ) ;
}
return V_94 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
F_42 ( V_9 -> V_107 ) ;
F_42 ( V_9 -> V_108 ) ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_109 , V_110 ;
int V_111 ;
snprintf ( V_9 -> V_112 , sizeof( V_9 -> V_112 ) ,
L_1 , V_2 -> line ) ;
V_111 = F_45 ( V_2 -> V_71 , F_31 , V_113 ,
V_9 -> V_112 , V_2 ) ;
if ( F_46 ( V_111 ) )
return V_111 ;
F_41 ( V_2 ) ;
if ( F_47 ( V_2 -> V_62 > 12 ) )
V_110 = V_2 -> V_62 - 12 ;
else
V_110 = V_2 -> V_62 ;
V_109 = F_2 ( V_2 , V_87 ) ;
V_109 &= ~ V_114 ;
V_109 &= ~ V_115 ;
V_109 |= V_114 & ( V_110 << 2 ) ;
V_109 |= V_115 & V_110 ;
F_4 ( V_2 , V_109 , V_87 ) ;
V_109 = F_2 ( V_2 , V_105 ) ;
if ( F_46 ( ! V_109 ) ) {
V_109 |= V_103 ;
V_109 |= V_102 ;
F_4 ( V_2 , V_109 , V_105 ) ;
}
V_109 = 0 ;
if ( ! V_2 -> V_116 || ( V_2 -> V_116 && ! ( V_2 -> V_116 -> V_117 & V_118 ) ) ) {
F_4 ( V_2 , V_119 , V_8 ) ;
F_34 ( V_2 ) ;
V_109 = V_120 ;
}
V_109 |= V_121 ;
F_4 ( V_2 , V_109 , V_8 ) ;
if ( V_9 -> V_57 )
F_4 ( V_2 , V_102 , V_105 ) ;
V_9 -> V_10 = V_13 | V_14 |
V_122 ;
if ( V_9 -> V_57 ) {
F_4 ( V_2 , 0xFFFFFF , V_41 ) ;
F_4 ( V_2 , V_40 , V_8 ) ;
F_4 ( V_2 , V_42 , V_8 ) ;
}
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 = 0 ;
F_4 ( V_2 , 0 , V_12 ) ;
F_49 ( V_9 -> V_107 ) ;
F_50 ( V_2 -> V_71 , V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_123 * V_124 ,
struct V_123 * V_125 )
{
unsigned long V_117 ;
unsigned int V_94 , V_86 ;
F_52 ( & V_2 -> V_39 , V_117 ) ;
V_94 = F_53 ( V_2 , V_124 , V_125 , 300 , 115200 ) ;
V_94 = F_40 ( V_2 , V_94 ) ;
if ( F_54 ( V_124 ) )
F_55 ( V_124 , V_94 , V_94 ) ;
V_86 = F_2 ( V_2 , V_126 ) ;
V_86 &= ~ V_127 ;
if ( V_124 -> V_128 & V_129 ) {
if ( V_124 -> V_128 & V_130 )
V_86 |= V_131 ;
else if ( V_124 -> V_128 & V_132 )
V_86 |= V_133 ;
else
V_86 |= V_134 ;
}
V_86 &= ~ V_135 ;
switch ( V_124 -> V_128 & V_136 ) {
case V_137 :
V_86 |= V_138 ;
break;
case V_139 :
V_86 |= V_140 ;
break;
case V_141 :
V_86 |= V_142 ;
break;
case V_143 :
default:
V_86 |= V_144 ;
break;
}
V_86 &= ~ ( V_145 | V_146 ) ;
if ( V_124 -> V_128 & V_147 )
V_86 |= V_146 ;
else
V_86 |= V_145 ;
F_4 ( V_2 , V_86 , V_126 ) ;
V_86 = F_2 ( V_2 , V_87 ) ;
V_86 &= ~ ( V_148 | V_88 ) ;
if ( V_124 -> V_128 & V_149 ) {
V_86 |= V_148 ;
V_86 |= V_88 ;
}
F_4 ( V_2 , V_86 , V_87 ) ;
V_2 -> V_47 = 0 ;
if ( V_124 -> V_150 & V_151 )
V_2 -> V_47 |= V_37 ;
if ( V_124 -> V_150 & ( V_152 | V_153 | V_154 ) )
V_2 -> V_47 |= V_35 ;
F_56 ( V_2 , V_124 -> V_128 , V_94 ) ;
F_57 ( & V_2 -> V_39 , V_117 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
return L_2 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_155 * V_156 = F_60 ( V_2 -> V_157 ) ;
struct V_158 * V_159 ;
T_3 V_160 ;
V_159 = F_61 ( V_156 , V_161 , 0 ) ;
if ( F_46 ( ! V_159 ) )
return;
V_160 = F_62 ( V_159 ) ;
F_63 ( V_2 -> V_162 , V_160 ) ;
F_64 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_155 * V_156 = F_60 ( V_2 -> V_157 ) ;
struct V_158 * V_159 ;
T_3 V_160 ;
int V_111 ;
V_159 = F_61 ( V_156 , V_161 , 0 ) ;
if ( F_46 ( ! V_159 ) )
return - V_163 ;
V_160 = F_62 ( V_159 ) ;
if ( ! F_66 ( V_2 -> V_162 , V_160 , L_3 ) )
return - V_164 ;
V_2 -> V_33 = F_67 ( V_2 -> V_162 , V_160 ) ;
if ( ! V_2 -> V_33 ) {
V_111 = - V_164 ;
goto V_165;
}
return 0 ;
V_165:
F_63 ( V_2 -> V_162 , V_160 ) ;
return V_111 ;
}
static void F_68 ( struct V_1 * V_2 , int V_117 )
{
int V_111 ;
if ( V_117 & V_166 ) {
V_2 -> type = V_167 ;
V_111 = F_65 ( V_2 ) ;
if ( V_111 )
return;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_168 * V_169 )
{
if ( F_46 ( V_169 -> type != V_170 && V_169 -> type != V_167 ) )
return - V_171 ;
if ( F_46 ( V_2 -> V_71 != V_169 -> V_71 ) )
return - V_171 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_172 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
switch ( V_19 ) {
case 0 :
F_42 ( V_9 -> V_107 ) ;
F_42 ( V_9 -> V_108 ) ;
break;
case 3 :
F_49 ( V_9 -> V_107 ) ;
F_49 ( V_9 -> V_108 ) ;
break;
default:
F_71 ( V_173 L_4 , V_19 ) ;
}
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
if ( V_9 -> V_57 >= V_174 )
F_4 ( V_2 , V_175 , V_84 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_176 = V_9 -> V_57 ? V_34 : V_46 ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_32 ) )
return V_177 ;
else
return F_2 ( V_2 , V_176 ) & 0xff ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_43 ;
static T_4 V_178 ;
static int V_21 ;
unsigned char * V_179 = ( unsigned char * ) & V_178 ;
if ( V_21 ) {
V_43 = V_179 [ sizeof( V_178 ) - V_21 ] ;
V_21 -- ;
} else if ( ! ( F_2 ( V_2 , V_3 ) & V_32 ) ) {
V_21 = F_2 ( V_2 , V_180 ) ;
V_21 = ( V_21 >> V_181 ) & V_182 ;
if ( V_21 ) {
F_4 ( V_2 , V_183 , V_8 ) ;
V_178 = F_2 ( V_2 , V_34 ) ;
V_43 = V_179 [ 0 ] ;
V_21 -- ;
} else {
V_43 = V_177 ;
}
} else {
V_178 = F_2 ( V_2 , V_34 ) ;
V_43 = V_179 [ 0 ] ;
V_21 = sizeof( V_178 ) - 1 ;
}
return V_43 ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_4 V_10 ;
int V_43 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_10 = F_2 ( V_2 , V_12 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_9 -> V_57 == V_184 )
V_43 = F_74 ( V_2 ) ;
else
V_43 = F_73 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_12 ) ;
return V_43 ;
}
static void F_76 ( struct V_1 * V_2 , unsigned char V_43 )
{
T_4 V_10 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_10 = F_2 ( V_2 , V_12 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_9 -> V_57 )
F_21 ( V_2 , 1 ) ;
while ( ! ( F_2 ( V_2 , V_3 ) & V_66 ) )
F_77 () ;
F_4 ( V_2 , V_43 , V_9 -> V_57 ? V_58 : V_59 ) ;
while ( ! ( F_2 ( V_2 , V_3 ) & V_66 ) )
F_77 () ;
F_4 ( V_2 , V_10 , V_12 ) ;
return;
}
static inline struct V_1 * F_78 ( unsigned int line )
{
return & V_185 [ line ] . V_186 ;
}
static void F_79 ( struct V_187 * V_188 , const char * V_189 ,
unsigned int V_21 )
{
int V_65 ;
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_190 = 0 ;
bool V_191 = false ;
void T_1 * V_56 ;
F_80 ( V_188 -> V_192 < 0 || V_188 -> V_192 >= V_193 ) ;
V_2 = F_78 ( V_188 -> V_192 ) ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 -> V_57 )
V_56 = V_2 -> V_33 + V_58 ;
else
V_56 = V_2 -> V_33 + V_59 ;
for ( V_65 = 0 ; V_65 < V_21 ; V_65 ++ )
if ( V_189 [ V_65 ] == '\n' )
V_190 ++ ;
V_21 += V_190 ;
F_18 ( & V_2 -> V_39 ) ;
if ( V_9 -> V_57 )
F_21 ( V_2 , V_21 ) ;
V_65 = 0 ;
while ( V_65 < V_21 ) {
int V_194 ;
unsigned int V_54 ;
char V_31 [ 4 ] = { 0 } ;
if ( V_9 -> V_57 )
V_54 = F_15 ( V_21 - V_65 , ( unsigned int ) sizeof( V_31 ) ) ;
else
V_54 = 1 ;
for ( V_194 = 0 ; V_194 < V_54 ; V_194 ++ ) {
char V_43 = * V_189 ;
if ( V_43 == '\n' && ! V_191 ) {
V_31 [ V_194 ] = '\r' ;
V_194 ++ ;
V_191 = true ;
}
if ( V_194 < V_54 ) {
V_31 [ V_194 ] = V_43 ;
V_189 ++ ;
V_191 = false ;
}
}
while ( ! ( F_2 ( V_2 , V_3 ) & V_66 ) )
F_77 () ;
F_26 ( V_56 , V_31 , 1 ) ;
V_65 += V_54 ;
}
F_16 ( & V_2 -> V_39 ) ;
}
static int T_5 F_81 ( struct V_187 * V_188 , char * V_195 )
{
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_94 = 0 , V_196 , V_197 , V_198 ;
if ( F_46 ( V_188 -> V_192 >= V_193 || V_188 -> V_192 < 0 ) )
return - V_163 ;
V_2 = F_78 ( V_188 -> V_192 ) ;
V_9 = F_6 ( V_2 ) ;
if ( F_46 ( ! V_2 -> V_33 ) )
return - V_163 ;
F_41 ( V_2 ) ;
if ( V_195 )
F_82 ( V_195 , & V_94 , & V_198 , & V_197 , & V_196 ) ;
V_197 = 8 ;
V_198 = 'n' ;
V_196 = 'n' ;
F_4 ( V_2 , V_144 | V_145 ,
V_126 ) ;
if ( V_94 < 300 || V_94 > 115200 )
V_94 = 115200 ;
F_40 ( V_2 , V_94 ) ;
F_34 ( V_2 ) ;
if ( V_9 -> V_57 ) {
F_4 ( V_2 , V_119 , V_8 ) ;
F_4 ( V_2 , V_120 , V_8 ) ;
}
F_71 ( V_199 L_5 , V_2 -> line ) ;
return F_83 ( V_2 , V_188 , V_94 , V_198 , V_197 , V_196 ) ;
}
static int F_84 ( struct V_155 * V_156 )
{
struct V_9 * V_9 ;
struct V_158 * V_158 ;
struct V_1 * V_2 ;
const struct V_200 * V_201 ;
int V_71 ;
if ( V_156 -> V_201 == - 1 )
V_156 -> V_201 = F_85 ( & V_202 ) - 1 ;
if ( F_46 ( V_156 -> V_201 < 0 || V_156 -> V_201 >= V_193 ) )
return - V_163 ;
F_71 ( V_199 L_6 , V_156 -> V_201 ) ;
V_2 = F_78 ( V_156 -> V_201 ) ;
V_2 -> V_157 = & V_156 -> V_157 ;
V_9 = F_6 ( V_2 ) ;
V_201 = F_86 ( V_203 , & V_156 -> V_157 ) ;
if ( V_201 )
V_9 -> V_57 = ( unsigned long ) V_201 -> V_109 ;
else
V_9 -> V_57 = 0 ;
V_9 -> V_107 = F_87 ( & V_156 -> V_157 , L_7 ) ;
if ( F_88 ( V_9 -> V_107 ) )
return F_89 ( V_9 -> V_107 ) ;
if ( V_9 -> V_57 ) {
V_9 -> V_108 = F_87 ( & V_156 -> V_157 , L_8 ) ;
if ( F_88 ( V_9 -> V_108 ) )
return F_89 ( V_9 -> V_108 ) ;
F_90 ( V_9 -> V_107 , 1843200 ) ;
}
V_2 -> V_204 = F_91 ( V_9 -> V_107 ) ;
F_71 ( V_199 L_9 , V_2 -> V_204 ) ;
V_158 = F_61 ( V_156 , V_161 , 0 ) ;
if ( F_46 ( ! V_158 ) )
return - V_163 ;
V_2 -> V_162 = V_158 -> V_205 ;
V_71 = F_92 ( V_156 , 0 ) ;
if ( F_46 ( V_71 < 0 ) )
return - V_163 ;
V_2 -> V_71 = V_71 ;
F_93 ( V_156 , V_2 ) ;
return F_94 ( & V_206 , V_2 ) ;
}
static int F_95 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = F_96 ( V_156 ) ;
F_97 ( & V_206 , V_2 ) ;
return 0 ;
}
static int T_5 F_98 ( void )
{
int V_111 ;
V_111 = F_99 ( & V_206 ) ;
if ( F_46 ( V_111 ) )
return V_111 ;
V_111 = F_100 ( & V_207 ) ;
if ( F_46 ( V_111 ) )
F_101 ( & V_206 ) ;
F_71 ( V_199 L_10 ) ;
return V_111 ;
}
static void T_6 F_102 ( void )
{
#ifdef F_103
F_104 ( & V_208 ) ;
#endif
F_105 ( & V_207 ) ;
F_101 ( & V_206 ) ;
}
