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
unsigned int V_31 ;
V_20 = F_2 ( V_2 , V_3 ) ;
if ( ( V_20 & V_32 ) == 0 ) {
V_9 -> V_28 -= V_21 ;
break;
}
V_31 = F_2 ( V_2 , V_33 ) ;
if ( V_20 & V_34 ) {
V_2 -> V_23 . V_35 ++ ;
if ( F_12 ( V_2 ) )
continue;
} else if ( V_20 & V_36 )
V_2 -> V_23 . V_37 ++ ;
F_13 ( V_18 , ( char * ) & V_31 ,
( V_21 > 4 ) ? 4 : V_21 ) ;
V_21 -= 4 ;
}
F_14 ( & V_2 -> V_38 ) ;
F_15 ( V_18 ) ;
F_16 ( & V_2 -> V_38 ) ;
if ( V_16 & ( V_14 ) )
F_4 ( V_2 , V_39 , V_8 ) ;
F_4 ( V_2 , 0xFFFFFF , V_40 ) ;
F_4 ( V_2 , V_41 , V_8 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_19 -> V_2 ;
unsigned int V_20 ;
if ( ( F_2 ( V_2 , V_3 ) & V_22 ) ) {
V_2 -> V_23 . V_24 ++ ;
F_11 ( V_18 , 0 , V_25 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
}
while ( ( V_20 = F_2 ( V_2 , V_3 ) ) & V_32 ) {
unsigned int V_31 ;
char V_42 = V_43 ;
V_31 = F_2 ( V_2 , V_44 ) ;
if ( V_20 & V_34 ) {
V_2 -> V_23 . V_35 ++ ;
if ( F_12 ( V_2 ) )
continue;
} else if ( V_20 & V_36 ) {
V_2 -> V_23 . V_37 ++ ;
} else {
V_2 -> V_23 . V_30 ++ ;
}
V_20 &= V_2 -> V_45 ;
if ( V_20 & V_34 ) {
V_42 = V_46 ;
} else if ( V_20 & V_36 ) {
V_42 = V_47 ;
}
if ( ! F_18 ( V_2 , V_31 ) )
F_11 ( V_18 , V_31 , V_42 ) ;
}
F_14 ( & V_2 -> V_38 ) ;
F_15 ( V_18 ) ;
F_16 ( & V_2 -> V_38 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_21 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 , V_21 , V_48 ) ;
F_2 ( V_2 , V_48 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_19 -> V_50 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_51 , V_52 ;
unsigned int V_53 = 0 ;
V_51 = F_21 ( V_50 ) ;
V_51 = F_22 ( V_51 , ( unsigned int ) V_54 - V_50 -> V_55 ,
V_2 -> V_56 ) ;
if ( V_2 -> V_57 ) {
if ( V_9 -> V_58 )
F_19 ( V_2 , V_51 + 1 ) ;
F_4 ( V_2 , V_2 -> V_57 ,
V_9 -> V_58 ? V_59 : V_60 ) ;
V_2 -> V_23 . V_61 ++ ;
V_2 -> V_57 = 0 ;
} else if ( V_51 && V_9 -> V_58 ) {
F_19 ( V_2 , V_51 ) ;
}
while ( V_53 < V_51 ) {
int V_62 ;
char V_63 [ 4 ] = { 0 } ;
unsigned int * V_64 = ( unsigned int * ) & V_63 ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_65 ) )
break;
if ( V_9 -> V_58 )
V_52 = F_23 ( V_51 - V_53 ,
( unsigned int ) sizeof( V_63 ) ) ;
else
V_52 = 1 ;
for ( V_62 = 0 ; V_62 < V_52 ; V_62 ++ ) {
V_63 [ V_62 ] = V_50 -> V_63 [ V_50 -> V_55 + V_62 ] ;
V_2 -> V_23 . V_61 ++ ;
}
F_4 ( V_2 , * V_64 , V_9 -> V_58 ? V_59 : V_60 ) ;
V_50 -> V_55 = ( V_50 -> V_55 + V_52 ) & ( V_54 - 1 ) ;
V_53 += V_52 ;
}
if ( F_24 ( V_50 ) )
F_5 ( V_2 ) ;
if ( F_21 ( V_50 ) < V_66 )
F_25 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_67 , V_8 ) ;
V_2 -> V_23 . V_68 ++ ;
F_27 ( & V_2 -> V_19 -> V_2 . V_69 ) ;
}
static T_1 F_28 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_16 ;
F_16 ( & V_2 -> V_38 ) ;
V_16 = F_2 ( V_2 , V_72 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_16 & ( V_13 | V_14 ) ) {
if ( V_9 -> V_58 )
F_10 ( V_2 , V_16 ) ;
else
F_17 ( V_2 ) ;
}
if ( V_16 & V_11 )
F_20 ( V_2 ) ;
if ( V_16 & V_15 )
F_26 ( V_2 ) ;
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
F_14 ( & V_2 -> V_38 ) ;
return V_73 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , V_3 ) & V_4 ) ? V_74 : 0 ;
}
static unsigned int F_30 ( struct V_1 * V_2 )
{
return V_75 | V_76 | V_77 | V_78 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
F_4 ( V_2 , V_79 , V_8 ) ;
F_4 ( V_2 , V_80 , V_8 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
F_4 ( V_2 , V_81 , V_8 ) ;
F_4 ( V_2 , V_67 , V_8 ) ;
F_4 ( V_2 , V_82 , V_8 ) ;
if ( V_9 -> V_58 )
F_4 ( V_2 , 0 , V_83 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_84 )
{
unsigned int V_85 ;
V_85 = F_2 ( V_2 , V_86 ) ;
if ( ! ( V_84 & V_78 ) ) {
V_85 &= ~ V_87 ;
F_4 ( V_2 , V_85 , V_86 ) ;
F_4 ( V_2 , V_88 , V_8 ) ;
} else {
V_85 |= V_87 ;
F_4 ( V_2 , V_85 , V_86 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , int V_89 )
{
if ( V_89 )
F_4 ( V_2 , V_90 , V_8 ) ;
else
F_4 ( V_2 , V_91 , V_8 ) ;
}
static const struct V_92 *
F_34 ( struct V_1 * V_2 , unsigned int V_93 )
{
unsigned int V_62 , V_94 ;
const struct V_92 * V_95 ;
static const struct V_92 V_96 [] = {
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
V_94 = F_35 ( V_2 , V_93 ) ;
for ( V_62 = 0 , V_95 = V_96 ; V_62 < F_36 ( V_96 ) ; V_62 ++ , V_95 ++ )
if ( V_95 -> V_94 <= V_94 )
break;
return V_95 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_93 )
{
unsigned int V_97 , V_98 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
const struct V_92 * V_95 ;
V_95 = F_34 ( V_2 , V_93 ) ;
if ( V_9 -> V_58 )
F_4 ( V_2 , V_79 , V_8 ) ;
F_4 ( V_2 , V_95 -> V_99 , V_100 ) ;
V_97 = V_95 -> V_97 ;
V_98 = V_101 & V_97 ;
V_98 |= V_102 ;
V_98 |= V_103 & ( V_97 << 2 ) ;
F_4 ( V_2 , V_98 , V_104 ) ;
V_98 = ( V_2 -> V_56 * 3 ) / 4 ;
F_4 ( V_2 , V_98 , V_29 ) ;
F_4 ( V_2 , 10 , V_105 ) ;
if ( V_9 -> V_58 ) {
F_4 ( V_2 , V_39 , V_8 ) ;
F_4 ( V_2 , 0xFFFFFF , V_40 ) ;
F_4 ( V_2 , V_41 , V_8 ) ;
}
return V_93 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
F_39 ( V_9 -> V_106 ) ;
F_39 ( V_9 -> V_107 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_108 , V_109 ;
int V_110 ;
snprintf ( V_9 -> V_111 , sizeof( V_9 -> V_111 ) ,
L_1 , V_2 -> line ) ;
V_110 = F_42 ( V_2 -> V_70 , F_28 , V_112 ,
V_9 -> V_111 , V_2 ) ;
if ( F_43 ( V_110 ) )
return V_110 ;
F_38 ( V_2 ) ;
if ( F_44 ( V_2 -> V_56 > 12 ) )
V_109 = V_2 -> V_56 - 12 ;
else
V_109 = V_2 -> V_56 ;
V_108 = F_2 ( V_2 , V_86 ) ;
V_108 &= ~ V_113 ;
V_108 &= ~ V_114 ;
V_108 |= V_113 & ( V_109 << 2 ) ;
V_108 |= V_114 & V_109 ;
F_4 ( V_2 , V_108 , V_86 ) ;
V_108 = F_2 ( V_2 , V_104 ) ;
if ( F_43 ( ! V_108 ) ) {
V_108 |= V_102 ;
V_108 |= V_101 ;
F_4 ( V_2 , V_108 , V_104 ) ;
}
V_108 = 0 ;
if ( ! V_2 -> V_115 || ( V_2 -> V_115 && ! ( V_2 -> V_115 -> V_116 & V_117 ) ) ) {
F_4 ( V_2 , V_118 , V_8 ) ;
F_31 ( V_2 ) ;
V_108 = V_119 ;
}
V_108 |= V_120 ;
F_4 ( V_2 , V_108 , V_8 ) ;
if ( V_9 -> V_58 )
F_4 ( V_2 , V_101 , V_104 ) ;
V_9 -> V_10 = V_13 | V_14 |
V_121 ;
if ( V_9 -> V_58 ) {
F_4 ( V_2 , 0xFFFFFF , V_40 ) ;
F_4 ( V_2 , V_39 , V_8 ) ;
F_4 ( V_2 , V_41 , V_8 ) ;
}
F_4 ( V_2 , V_9 -> V_10 , V_12 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_9 -> V_10 = 0 ;
F_4 ( V_2 , 0 , V_12 ) ;
F_46 ( V_9 -> V_106 ) ;
F_47 ( V_2 -> V_70 , V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_122 * V_124 )
{
unsigned long V_116 ;
unsigned int V_93 , V_85 ;
F_49 ( & V_2 -> V_38 , V_116 ) ;
V_93 = F_50 ( V_2 , V_123 , V_124 , 300 , 115200 ) ;
V_93 = F_37 ( V_2 , V_93 ) ;
if ( F_51 ( V_123 ) )
F_52 ( V_123 , V_93 , V_93 ) ;
V_85 = F_2 ( V_2 , V_125 ) ;
V_85 &= ~ V_126 ;
if ( V_123 -> V_127 & V_128 ) {
if ( V_123 -> V_127 & V_129 )
V_85 |= V_130 ;
else if ( V_123 -> V_127 & V_131 )
V_85 |= V_132 ;
else
V_85 |= V_133 ;
}
V_85 &= ~ V_134 ;
switch ( V_123 -> V_127 & V_135 ) {
case V_136 :
V_85 |= V_137 ;
break;
case V_138 :
V_85 |= V_139 ;
break;
case V_140 :
V_85 |= V_141 ;
break;
case V_142 :
default:
V_85 |= V_143 ;
break;
}
V_85 &= ~ ( V_144 | V_145 ) ;
if ( V_123 -> V_127 & V_146 )
V_85 |= V_145 ;
else
V_85 |= V_144 ;
F_4 ( V_2 , V_85 , V_125 ) ;
V_85 = F_2 ( V_2 , V_86 ) ;
V_85 &= ~ ( V_147 | V_87 ) ;
if ( V_123 -> V_127 & V_148 ) {
V_85 |= V_147 ;
V_85 |= V_87 ;
}
F_4 ( V_2 , V_85 , V_86 ) ;
V_2 -> V_45 = 0 ;
if ( V_123 -> V_149 & V_150 )
V_2 -> V_45 |= V_36 ;
if ( V_123 -> V_149 & ( V_151 | V_152 ) )
V_2 -> V_45 |= V_34 ;
F_53 ( V_2 , V_123 -> V_127 , V_93 ) ;
F_54 ( & V_2 -> V_38 , V_116 ) ;
}
static const char * F_55 ( struct V_1 * V_2 )
{
return L_2 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = F_57 ( V_2 -> V_155 ) ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
struct V_156 * V_157 ;
struct V_156 * V_158 ;
T_2 V_159 ;
V_157 = F_58 ( V_154 , V_160 , 0 ) ;
if ( F_43 ( ! V_157 ) )
return;
V_159 = F_59 ( V_157 ) ;
F_60 ( V_2 -> V_161 , V_159 ) ;
F_61 ( V_2 -> V_162 ) ;
V_2 -> V_162 = NULL ;
if ( V_9 -> V_163 ) {
F_62 ( V_164 ,
V_9 -> V_163 + V_165 ) ;
V_158 = F_58 ( V_154 , V_160 , 1 ) ;
if ( F_43 ( ! V_158 ) )
return;
V_159 = F_59 ( V_158 ) ;
F_60 ( V_158 -> V_166 , V_159 ) ;
F_61 ( V_9 -> V_163 ) ;
V_9 -> V_163 = NULL ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
struct V_153 * V_154 = F_57 ( V_2 -> V_155 ) ;
struct V_156 * V_157 ;
struct V_156 * V_158 ;
T_2 V_159 ;
int V_110 ;
V_157 = F_58 ( V_154 , V_160 , 0 ) ;
if ( F_43 ( ! V_157 ) )
return - V_167 ;
V_159 = F_59 ( V_157 ) ;
if ( ! F_64 ( V_2 -> V_161 , V_159 , L_3 ) )
return - V_168 ;
V_2 -> V_162 = F_65 ( V_2 -> V_161 , V_159 ) ;
if ( ! V_2 -> V_162 ) {
V_110 = - V_168 ;
goto V_169;
}
V_158 = F_58 ( V_154 , V_160 , 1 ) ;
if ( V_158 ) {
V_159 = F_59 ( V_158 ) ;
if ( ! F_64 ( V_158 -> V_166 , V_159 ,
L_3 ) ) {
V_110 = - V_168 ;
goto V_170;
}
V_9 -> V_163 = F_65 ( V_158 -> V_166 , V_159 ) ;
if ( ! V_9 -> V_163 ) {
V_110 = - V_168 ;
goto V_171;
}
}
return 0 ;
V_171:
F_60 ( V_158 -> V_166 , V_159 ) ;
V_170:
F_61 ( V_2 -> V_162 ) ;
V_169:
F_60 ( V_2 -> V_161 , V_159 ) ;
return V_110 ;
}
static void F_66 ( struct V_1 * V_2 , int V_116 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
int V_110 ;
if ( V_116 & V_172 ) {
V_2 -> type = V_173 ;
V_110 = F_63 ( V_2 ) ;
if ( V_110 )
return;
}
if ( V_9 -> V_163 )
F_62 ( V_174 ,
V_9 -> V_163 + V_165 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_175 * V_176 )
{
if ( F_43 ( V_176 -> type != V_177 && V_176 -> type != V_173 ) )
return - V_178 ;
if ( F_43 ( V_2 -> V_70 != V_176 -> V_70 ) )
return - V_178 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_179 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
switch ( V_19 ) {
case 0 :
F_39 ( V_9 -> V_106 ) ;
F_39 ( V_9 -> V_107 ) ;
break;
case 3 :
F_46 ( V_9 -> V_106 ) ;
F_46 ( V_9 -> V_107 ) ;
break;
default:
F_69 ( V_180 L_4 , V_19 ) ;
}
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
if ( V_9 -> V_58 >= V_181 )
F_4 ( V_2 , V_182 , V_83 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_183 = V_9 -> V_58 ? V_33 : V_44 ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_32 ) )
return V_184 ;
else
return F_2 ( V_2 , V_183 ) & 0xff ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_31 ;
static T_3 V_185 ;
static int V_21 ;
unsigned char * V_186 = ( unsigned char * ) & V_185 ;
if ( V_21 ) {
V_31 = V_186 [ sizeof( V_185 ) - V_21 ] ;
V_21 -- ;
} else if ( ! ( F_2 ( V_2 , V_3 ) & V_32 ) ) {
V_21 = F_2 ( V_2 , V_187 ) ;
V_21 = ( V_21 >> V_188 ) & V_189 ;
if ( V_21 ) {
F_4 ( V_2 , V_190 , V_8 ) ;
V_185 = F_2 ( V_2 , V_33 ) ;
V_31 = V_186 [ 0 ] ;
V_21 -- ;
} else {
V_31 = V_184 ;
}
} else {
V_185 = F_2 ( V_2 , V_33 ) ;
V_31 = V_186 [ 0 ] ;
V_21 = sizeof( V_185 ) - 1 ;
}
return V_31 ;
}
static int F_73 ( struct V_1 * V_2 )
{
T_3 V_10 ;
int V_31 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_10 = F_2 ( V_2 , V_12 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_9 -> V_58 == V_191 )
V_31 = F_72 ( V_2 ) ;
else
V_31 = F_71 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_12 ) ;
return V_31 ;
}
static void F_74 ( struct V_1 * V_2 , unsigned char V_31 )
{
T_3 V_10 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
V_10 = F_2 ( V_2 , V_12 ) ;
F_4 ( V_2 , 0 , V_12 ) ;
if ( V_9 -> V_58 )
F_19 ( V_2 , 1 ) ;
while ( ! ( F_2 ( V_2 , V_3 ) & V_65 ) )
F_75 () ;
F_4 ( V_2 , V_31 , V_9 -> V_58 ? V_59 : V_60 ) ;
while ( ! ( F_2 ( V_2 , V_3 ) & V_65 ) )
F_75 () ;
F_4 ( V_2 , V_10 , V_12 ) ;
return;
}
static inline struct V_1 * F_76 ( unsigned int line )
{
return & V_192 [ line ] . V_193 ;
}
static void F_77 ( struct V_194 * V_195 , const char * V_196 ,
unsigned int V_21 )
{
int V_62 ;
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_197 = 0 ;
bool V_198 = false ;
F_78 ( V_195 -> V_199 < 0 || V_195 -> V_199 >= V_200 ) ;
V_2 = F_76 ( V_195 -> V_199 ) ;
V_9 = F_6 ( V_2 ) ;
for ( V_62 = 0 ; V_62 < V_21 ; V_62 ++ )
if ( V_196 [ V_62 ] == '\n' )
V_197 ++ ;
V_21 += V_197 ;
F_16 ( & V_2 -> V_38 ) ;
if ( V_9 -> V_58 )
F_19 ( V_2 , V_21 ) ;
V_62 = 0 ;
while ( V_62 < V_21 ) {
int V_201 ;
unsigned int V_52 ;
char V_63 [ 4 ] = { 0 } ;
unsigned int * V_64 = ( unsigned int * ) & V_63 ;
if ( V_9 -> V_58 )
V_52 = F_23 ( V_21 - V_62 , ( unsigned int ) sizeof( V_63 ) ) ;
else
V_52 = 1 ;
for ( V_201 = 0 ; V_201 < V_52 ; V_201 ++ ) {
char V_31 = * V_196 ;
if ( V_31 == '\n' && ! V_198 ) {
V_63 [ V_201 ] = '\r' ;
V_201 ++ ;
V_198 = true ;
}
if ( V_201 < V_52 ) {
V_63 [ V_201 ] = V_31 ;
V_196 ++ ;
V_198 = false ;
}
}
while ( ! ( F_2 ( V_2 , V_3 ) & V_65 ) )
F_75 () ;
F_4 ( V_2 , * V_64 , V_9 -> V_58 ? V_59 : V_60 ) ;
V_62 += V_52 ;
}
F_14 ( & V_2 -> V_38 ) ;
}
static int T_4 F_79 ( struct V_194 * V_195 , char * V_202 )
{
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_93 , V_203 , V_204 , V_205 ;
if ( F_43 ( V_195 -> V_199 >= V_200 || V_195 -> V_199 < 0 ) )
return - V_167 ;
V_2 = F_76 ( V_195 -> V_199 ) ;
V_9 = F_6 ( V_2 ) ;
if ( F_43 ( ! V_2 -> V_162 ) )
return - V_167 ;
F_38 ( V_2 ) ;
if ( V_202 )
F_80 ( V_202 , & V_93 , & V_205 , & V_204 , & V_203 ) ;
V_204 = 8 ;
V_205 = 'n' ;
V_203 = 'n' ;
F_4 ( V_2 , V_143 | V_144 ,
V_125 ) ;
if ( V_93 < 300 || V_93 > 115200 )
V_93 = 115200 ;
F_37 ( V_2 , V_93 ) ;
F_31 ( V_2 ) ;
if ( V_9 -> V_58 ) {
F_4 ( V_2 , V_118 , V_8 ) ;
F_4 ( V_2 , V_119 , V_8 ) ;
}
F_69 ( V_206 L_5 , V_2 -> line ) ;
return F_81 ( V_2 , V_195 , V_93 , V_205 , V_204 , V_203 ) ;
}
static int T_4 F_82 ( struct V_153 * V_154 )
{
struct V_9 * V_9 ;
struct V_156 * V_156 ;
struct V_1 * V_2 ;
const struct V_207 * V_208 ;
int V_70 ;
if ( V_154 -> V_208 == - 1 )
V_154 -> V_208 = F_83 ( & V_209 ) - 1 ;
if ( F_43 ( V_154 -> V_208 < 0 || V_154 -> V_208 >= V_200 ) )
return - V_167 ;
F_69 ( V_206 L_6 , V_154 -> V_208 ) ;
V_2 = F_76 ( V_154 -> V_208 ) ;
V_2 -> V_155 = & V_154 -> V_155 ;
V_9 = F_6 ( V_2 ) ;
V_208 = F_84 ( V_210 , & V_154 -> V_155 ) ;
if ( V_208 )
V_9 -> V_58 = ( unsigned long ) V_208 -> V_108 ;
else
V_9 -> V_58 = 0 ;
V_9 -> V_106 = F_85 ( & V_154 -> V_155 , L_7 ) ;
if ( F_86 ( V_9 -> V_106 ) )
return F_87 ( V_9 -> V_106 ) ;
if ( V_9 -> V_58 ) {
V_9 -> V_107 = F_85 ( & V_154 -> V_155 , L_8 ) ;
if ( F_86 ( V_9 -> V_107 ) )
return F_87 ( V_9 -> V_107 ) ;
F_88 ( V_9 -> V_106 , 1843200 ) ;
}
V_2 -> V_211 = F_89 ( V_9 -> V_106 ) ;
F_69 ( V_206 L_9 , V_2 -> V_211 ) ;
V_156 = F_58 ( V_154 , V_160 , 0 ) ;
if ( F_43 ( ! V_156 ) )
return - V_167 ;
V_2 -> V_161 = V_156 -> V_166 ;
V_70 = F_90 ( V_154 , 0 ) ;
if ( F_43 ( V_70 < 0 ) )
return - V_167 ;
V_2 -> V_70 = V_70 ;
F_91 ( V_154 , V_2 ) ;
return F_92 ( & V_212 , V_2 ) ;
}
static int F_93 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_94 ( V_154 ) ;
F_95 ( & V_212 , V_2 ) ;
return 0 ;
}
static int T_4 F_96 ( void )
{
int V_110 ;
V_110 = F_97 ( & V_212 ) ;
if ( F_43 ( V_110 ) )
return V_110 ;
V_110 = F_98 ( & V_213 , F_82 ) ;
if ( F_43 ( V_110 ) )
F_99 ( & V_212 ) ;
F_69 ( V_206 L_10 ) ;
return V_110 ;
}
static void T_5 F_100 ( void )
{
#ifdef F_101
F_102 ( & V_214 ) ;
#endif
F_103 ( & V_213 ) ;
F_99 ( & V_212 ) ;
}
