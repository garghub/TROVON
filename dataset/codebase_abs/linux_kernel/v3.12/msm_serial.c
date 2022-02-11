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
F_4 ( V_2 , V_79 , V_8 ) ;
F_4 ( V_2 , V_80 , V_8 ) ;
F_4 ( V_2 , V_26 , V_8 ) ;
F_4 ( V_2 , V_81 , V_8 ) ;
F_4 ( V_2 , V_67 , V_8 ) ;
F_4 ( V_2 , V_82 , V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_83 )
{
unsigned int V_84 ;
V_84 = F_2 ( V_2 , V_85 ) ;
if ( ! ( V_83 & V_78 ) ) {
V_84 &= ~ V_86 ;
F_4 ( V_2 , V_84 , V_85 ) ;
F_4 ( V_2 , V_87 , V_8 ) ;
} else {
V_84 |= V_86 ;
F_4 ( V_2 , V_84 , V_85 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , int V_88 )
{
if ( V_88 )
F_4 ( V_2 , V_89 , V_8 ) ;
else
F_4 ( V_2 , V_90 , V_8 ) ;
}
static const struct V_91 *
F_34 ( struct V_1 * V_2 , unsigned int V_92 )
{
unsigned int V_62 , V_93 ;
const struct V_91 * V_94 ;
static const struct V_91 V_95 [] = {
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
V_93 = F_35 ( V_2 , V_92 ) ;
for ( V_62 = 0 , V_94 = V_95 ; V_62 < F_36 ( V_95 ) ; V_62 ++ , V_94 ++ )
if ( V_94 -> V_93 <= V_93 )
break;
return V_94 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_92 )
{
unsigned int V_96 , V_97 ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
const struct V_91 * V_94 ;
V_94 = F_34 ( V_2 , V_92 ) ;
if ( V_9 -> V_58 )
F_4 ( V_2 , V_79 , V_8 ) ;
F_4 ( V_2 , V_94 -> V_98 , V_99 ) ;
V_96 = V_94 -> V_96 ;
V_97 = V_100 & V_96 ;
V_97 |= V_101 ;
V_97 |= V_102 & ( V_96 << 2 ) ;
F_4 ( V_2 , V_97 , V_103 ) ;
V_97 = ( V_2 -> V_56 * 3 ) / 4 ;
F_4 ( V_2 , V_97 , V_29 ) ;
F_4 ( V_2 , 10 , V_104 ) ;
if ( V_9 -> V_58 ) {
F_4 ( V_2 , V_39 , V_8 ) ;
F_4 ( V_2 , 0xFFFFFF , V_40 ) ;
F_4 ( V_2 , V_41 , V_8 ) ;
}
return V_92 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
F_39 ( V_9 -> V_105 ) ;
F_39 ( V_9 -> V_106 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
unsigned int V_107 , V_108 ;
int V_109 ;
snprintf ( V_9 -> V_110 , sizeof( V_9 -> V_110 ) ,
L_1 , V_2 -> line ) ;
V_109 = F_42 ( V_2 -> V_70 , F_28 , V_111 ,
V_9 -> V_110 , V_2 ) ;
if ( F_43 ( V_109 ) )
return V_109 ;
F_38 ( V_2 ) ;
if ( F_44 ( V_2 -> V_56 > 12 ) )
V_108 = V_2 -> V_56 - 12 ;
else
V_108 = V_2 -> V_56 ;
V_107 = F_2 ( V_2 , V_85 ) ;
V_107 &= ~ V_112 ;
V_107 &= ~ V_113 ;
V_107 |= V_112 & ( V_108 << 2 ) ;
V_107 |= V_113 & V_108 ;
F_4 ( V_2 , V_107 , V_85 ) ;
V_107 = F_2 ( V_2 , V_103 ) ;
if ( F_43 ( ! V_107 ) ) {
V_107 |= V_101 ;
V_107 |= V_100 ;
F_4 ( V_2 , V_107 , V_103 ) ;
}
V_107 = 0 ;
if ( ! V_2 -> V_114 || ( V_2 -> V_114 && ! ( V_2 -> V_114 -> V_115 & V_116 ) ) ) {
F_4 ( V_2 , V_117 , V_8 ) ;
F_31 ( V_2 ) ;
V_107 = V_118 ;
}
V_107 |= V_119 ;
F_4 ( V_2 , V_107 , V_8 ) ;
if ( V_9 -> V_58 )
F_4 ( V_2 , V_100 , V_103 ) ;
V_9 -> V_10 = V_13 | V_14 |
V_120 ;
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
F_46 ( V_9 -> V_105 ) ;
F_47 ( V_2 -> V_70 , V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_121 * V_122 ,
struct V_121 * V_123 )
{
unsigned long V_115 ;
unsigned int V_92 , V_84 ;
F_49 ( & V_2 -> V_38 , V_115 ) ;
V_92 = F_50 ( V_2 , V_122 , V_123 , 300 , 115200 ) ;
V_92 = F_37 ( V_2 , V_92 ) ;
if ( F_51 ( V_122 ) )
F_52 ( V_122 , V_92 , V_92 ) ;
V_84 = F_2 ( V_2 , V_124 ) ;
V_84 &= ~ V_125 ;
if ( V_122 -> V_126 & V_127 ) {
if ( V_122 -> V_126 & V_128 )
V_84 |= V_129 ;
else if ( V_122 -> V_126 & V_130 )
V_84 |= V_131 ;
else
V_84 |= V_132 ;
}
V_84 &= ~ V_133 ;
switch ( V_122 -> V_126 & V_134 ) {
case V_135 :
V_84 |= V_136 ;
break;
case V_137 :
V_84 |= V_138 ;
break;
case V_139 :
V_84 |= V_140 ;
break;
case V_141 :
default:
V_84 |= V_142 ;
break;
}
V_84 &= ~ ( V_143 | V_144 ) ;
if ( V_122 -> V_126 & V_145 )
V_84 |= V_144 ;
else
V_84 |= V_143 ;
F_4 ( V_2 , V_84 , V_124 ) ;
V_84 = F_2 ( V_2 , V_85 ) ;
V_84 &= ~ ( V_146 | V_86 ) ;
if ( V_122 -> V_126 & V_147 ) {
V_84 |= V_146 ;
V_84 |= V_86 ;
}
F_4 ( V_2 , V_84 , V_85 ) ;
V_2 -> V_45 = 0 ;
if ( V_122 -> V_148 & V_149 )
V_2 -> V_45 |= V_36 ;
if ( V_122 -> V_148 & ( V_150 | V_151 ) )
V_2 -> V_45 |= V_34 ;
F_53 ( V_2 , V_122 -> V_126 , V_92 ) ;
F_54 ( & V_2 -> V_38 , V_115 ) ;
}
static const char * F_55 ( struct V_1 * V_2 )
{
return L_2 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = F_57 ( V_2 -> V_154 ) ;
struct V_9 * V_9 = F_6 ( V_2 ) ;
struct V_155 * V_156 ;
struct V_155 * V_157 ;
T_2 V_158 ;
V_156 = F_58 ( V_153 , V_159 , 0 ) ;
if ( F_43 ( ! V_156 ) )
return;
V_158 = F_59 ( V_156 ) ;
F_60 ( V_2 -> V_160 , V_158 ) ;
F_61 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
if ( V_9 -> V_162 ) {
F_62 ( V_163 ,
V_9 -> V_162 + V_164 ) ;
V_157 = F_58 ( V_153 , V_159 , 1 ) ;
if ( F_43 ( ! V_157 ) )
return;
V_158 = F_59 ( V_157 ) ;
F_60 ( V_157 -> V_165 , V_158 ) ;
F_61 ( V_9 -> V_162 ) ;
V_9 -> V_162 = NULL ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
struct V_152 * V_153 = F_57 ( V_2 -> V_154 ) ;
struct V_155 * V_156 ;
struct V_155 * V_157 ;
T_2 V_158 ;
int V_109 ;
V_156 = F_58 ( V_153 , V_159 , 0 ) ;
if ( F_43 ( ! V_156 ) )
return - V_166 ;
V_158 = F_59 ( V_156 ) ;
if ( ! F_64 ( V_2 -> V_160 , V_158 , L_3 ) )
return - V_167 ;
V_2 -> V_161 = F_65 ( V_2 -> V_160 , V_158 ) ;
if ( ! V_2 -> V_161 ) {
V_109 = - V_167 ;
goto V_168;
}
V_157 = F_58 ( V_153 , V_159 , 1 ) ;
if ( V_157 ) {
V_158 = F_59 ( V_157 ) ;
if ( ! F_64 ( V_157 -> V_165 , V_158 ,
L_3 ) ) {
V_109 = - V_167 ;
goto V_169;
}
V_9 -> V_162 = F_65 ( V_157 -> V_165 , V_158 ) ;
if ( ! V_9 -> V_162 ) {
V_109 = - V_167 ;
goto V_170;
}
}
return 0 ;
V_170:
F_60 ( V_157 -> V_165 , V_158 ) ;
V_169:
F_61 ( V_2 -> V_161 ) ;
V_168:
F_60 ( V_2 -> V_160 , V_158 ) ;
return V_109 ;
}
static void F_66 ( struct V_1 * V_2 , int V_115 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
int V_109 ;
if ( V_115 & V_171 ) {
V_2 -> type = V_172 ;
V_109 = F_63 ( V_2 ) ;
if ( V_109 )
return;
}
if ( V_9 -> V_162 )
F_62 ( V_173 ,
V_9 -> V_162 + V_164 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_174 * V_175 )
{
if ( F_43 ( V_175 -> type != V_176 && V_175 -> type != V_172 ) )
return - V_177 ;
if ( F_43 ( V_2 -> V_70 != V_175 -> V_70 ) )
return - V_177 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_178 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
switch ( V_19 ) {
case 0 :
F_39 ( V_9 -> V_105 ) ;
F_39 ( V_9 -> V_106 ) ;
break;
case 3 :
F_46 ( V_9 -> V_105 ) ;
F_46 ( V_9 -> V_106 ) ;
break;
default:
F_69 ( V_179 L_4 , V_19 ) ;
}
}
static inline struct V_1 * F_70 ( unsigned int line )
{
return & V_180 [ line ] . V_181 ;
}
static void F_71 ( struct V_182 * V_183 , const char * V_184 ,
unsigned int V_21 )
{
int V_62 ;
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_185 = 0 ;
bool V_186 = false ;
F_72 ( V_183 -> V_187 < 0 || V_183 -> V_187 >= V_188 ) ;
V_2 = F_70 ( V_183 -> V_187 ) ;
V_9 = F_6 ( V_2 ) ;
for ( V_62 = 0 ; V_62 < V_21 ; V_62 ++ )
if ( V_184 [ V_62 ] == '\n' )
V_185 ++ ;
V_21 += V_185 ;
F_16 ( & V_2 -> V_38 ) ;
if ( V_9 -> V_58 )
F_19 ( V_2 , V_21 ) ;
V_62 = 0 ;
while ( V_62 < V_21 ) {
int V_189 ;
unsigned int V_52 ;
char V_63 [ 4 ] = { 0 } ;
unsigned int * V_64 = ( unsigned int * ) & V_63 ;
if ( V_9 -> V_58 )
V_52 = F_23 ( V_21 - V_62 , ( unsigned int ) sizeof( V_63 ) ) ;
else
V_52 = 1 ;
for ( V_189 = 0 ; V_189 < V_52 ; V_189 ++ ) {
char V_31 = * V_184 ;
if ( V_31 == '\n' && ! V_186 ) {
V_63 [ V_189 ] = '\r' ;
V_189 ++ ;
V_186 = true ;
}
if ( V_189 < V_52 ) {
V_63 [ V_189 ] = V_31 ;
V_184 ++ ;
V_186 = false ;
}
}
while ( ! ( F_2 ( V_2 , V_3 ) & V_65 ) )
F_73 () ;
F_4 ( V_2 , * V_64 , V_9 -> V_58 ? V_59 : V_60 ) ;
V_62 += V_52 ;
}
F_14 ( & V_2 -> V_38 ) ;
}
static int T_3 F_74 ( struct V_182 * V_183 , char * V_190 )
{
struct V_1 * V_2 ;
struct V_9 * V_9 ;
int V_92 , V_191 , V_192 , V_193 ;
if ( F_43 ( V_183 -> V_187 >= V_188 || V_183 -> V_187 < 0 ) )
return - V_166 ;
V_2 = F_70 ( V_183 -> V_187 ) ;
V_9 = F_6 ( V_2 ) ;
if ( F_43 ( ! V_2 -> V_161 ) )
return - V_166 ;
F_38 ( V_2 ) ;
if ( V_190 )
F_75 ( V_190 , & V_92 , & V_193 , & V_192 , & V_191 ) ;
V_192 = 8 ;
V_193 = 'n' ;
V_191 = 'n' ;
F_4 ( V_2 , V_142 | V_143 ,
V_124 ) ;
if ( V_92 < 300 || V_92 > 115200 )
V_92 = 115200 ;
F_37 ( V_2 , V_92 ) ;
F_31 ( V_2 ) ;
if ( V_9 -> V_58 ) {
F_4 ( V_2 , V_117 , V_8 ) ;
F_4 ( V_2 , V_118 , V_8 ) ;
}
F_69 ( V_194 L_5 , V_2 -> line ) ;
return F_76 ( V_2 , V_183 , V_92 , V_193 , V_192 , V_191 ) ;
}
static int T_3 F_77 ( struct V_152 * V_153 )
{
struct V_9 * V_9 ;
struct V_155 * V_155 ;
struct V_1 * V_2 ;
int V_70 ;
if ( V_153 -> V_195 == - 1 )
V_153 -> V_195 = F_78 ( & V_196 ) - 1 ;
if ( F_43 ( V_153 -> V_195 < 0 || V_153 -> V_195 >= V_188 ) )
return - V_166 ;
F_69 ( V_194 L_6 , V_153 -> V_195 ) ;
V_2 = F_70 ( V_153 -> V_195 ) ;
V_2 -> V_154 = & V_153 -> V_154 ;
V_9 = F_6 ( V_2 ) ;
if ( F_79 ( V_197 , & V_153 -> V_154 ) )
V_9 -> V_58 = 1 ;
else
V_9 -> V_58 = 0 ;
V_9 -> V_105 = F_80 ( & V_153 -> V_154 , L_7 ) ;
if ( F_81 ( V_9 -> V_105 ) )
return F_82 ( V_9 -> V_105 ) ;
if ( V_9 -> V_58 ) {
V_9 -> V_106 = F_80 ( & V_153 -> V_154 , L_8 ) ;
if ( F_81 ( V_9 -> V_106 ) )
return F_82 ( V_9 -> V_106 ) ;
F_83 ( V_9 -> V_105 , 1843200 ) ;
}
V_2 -> V_198 = F_84 ( V_9 -> V_105 ) ;
F_69 ( V_194 L_9 , V_2 -> V_198 ) ;
V_155 = F_58 ( V_153 , V_159 , 0 ) ;
if ( F_43 ( ! V_155 ) )
return - V_166 ;
V_2 -> V_160 = V_155 -> V_165 ;
V_70 = F_85 ( V_153 , 0 ) ;
if ( F_43 ( V_70 < 0 ) )
return - V_166 ;
V_2 -> V_70 = V_70 ;
F_86 ( V_153 , V_2 ) ;
return F_87 ( & V_199 , V_2 ) ;
}
static int F_88 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_89 ( V_153 ) ;
F_90 ( & V_199 , V_2 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_109 ;
V_109 = F_92 ( & V_199 ) ;
if ( F_43 ( V_109 ) )
return V_109 ;
V_109 = F_93 ( & V_200 , F_77 ) ;
if ( F_43 ( V_109 ) )
F_94 ( & V_199 ) ;
F_69 ( V_194 L_10 ) ;
return V_109 ;
}
static void T_4 F_95 ( void )
{
#ifdef F_96
F_97 ( & V_201 ) ;
#endif
F_98 ( & V_200 ) ;
F_94 ( & V_199 ) ;
}
