static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & V_4 ) {
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) &
V_7 ) ) {
if ( ! F_2 ( V_2 -> V_5 + V_8 ) ) {
V_2 -> V_9 |= V_10 ;
V_3 &= ~ V_4 ;
}
}
F_3 ( V_4 , V_2 -> V_5 + V_11 ) ;
}
if ( V_3 & V_2 -> V_12 & V_13 )
V_3 &= ~ ( V_14 | V_15 ) ;
V_3 &= V_2 -> V_9 ;
V_3 &= ~ V_2 -> V_12 ;
if ( ! ( V_3 & ( V_15 | V_14 ) ) )
return;
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) & V_7 ) ) {
T_1 V_16 ;
char V_17 = V_18 ;
V_16 = F_2 ( V_2 -> V_5 + V_8 ) ;
if ( V_16 && ( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_9 &= ~ V_10 ;
V_2 -> V_19 . V_20 ++ ;
if ( F_4 ( V_2 ) )
continue;
}
if ( F_5 ( V_2 , V_16 ) )
continue;
V_2 -> V_19 . V_21 ++ ;
if ( V_3 & V_13 ) {
V_2 -> V_19 . V_22 ++ ;
V_17 = V_23 ;
} else if ( V_3 & V_4 ) {
V_2 -> V_19 . V_24 ++ ;
V_17 = V_25 ;
} else if ( V_3 & V_26 ) {
V_2 -> V_19 . V_27 ++ ;
}
F_6 ( V_2 , V_3 , V_26 ,
V_16 , V_17 ) ;
}
F_7 ( & V_2 -> V_28 -> V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
if ( F_9 ( & V_2 -> V_28 -> V_30 ) ) {
F_3 ( V_31 , V_2 -> V_5 + V_32 ) ;
return;
}
V_29 = V_2 -> V_33 ;
while ( V_29 && ! F_9 ( & V_2 -> V_28 -> V_30 ) &&
! ( F_2 ( V_2 -> V_5 + V_6 ) & V_34 ) ) {
F_3 ( V_2 -> V_28 -> V_30 . V_35 [ V_2 -> V_28 -> V_30 . V_36 ] ,
V_2 -> V_5 + V_8 ) ;
V_2 -> V_19 . V_37 ++ ;
V_2 -> V_28 -> V_30 . V_36 =
( V_2 -> V_28 -> V_30 . V_36 + 1 ) & ( V_38 - 1 ) ;
V_29 -- ;
}
if ( F_10 ( & V_2 -> V_28 -> V_30 ) < V_39 )
F_11 ( V_2 ) ;
}
static T_2 F_12 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
unsigned long V_42 ;
unsigned int V_3 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_11 ) ;
if ( V_3 & V_44 )
F_1 ( V_2 , V_3 ) ;
if ( ( V_3 & V_31 ) == V_31 )
F_8 ( V_2 ) ;
F_3 ( V_3 , V_2 -> V_5 + V_11 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
return V_45 ;
}
static unsigned int F_15 ( unsigned int V_46 ,
unsigned int V_47 , T_1 * V_48 , T_1 * V_49 , int * V_50 )
{
T_1 V_51 , V_52 ;
unsigned int V_53 ;
unsigned int V_54 = 0 ;
unsigned int V_55 ;
unsigned int V_56 = ~ 0 ;
if ( V_47 < V_46 / ( ( V_57 + 1 ) * V_58 ) ) {
* V_50 = 1 ;
V_46 /= 8 ;
} else {
* V_50 = 0 ;
}
for ( V_52 = V_59 ; V_52 <= V_57 ; V_52 ++ ) {
V_51 = F_16 ( V_46 , V_47 * ( V_52 + 1 ) ) ;
if ( V_51 < 1 || V_51 > V_58 )
continue;
V_53 = V_46 / ( V_51 * ( V_52 + 1 ) ) ;
if ( V_47 > V_53 )
V_55 = V_47 - V_53 ;
else
V_55 = V_53 - V_47 ;
if ( V_56 > V_55 ) {
* V_48 = V_52 ;
* V_49 = V_51 ;
V_54 = V_53 ;
V_56 = V_55 ;
}
}
if ( ( ( V_56 * 100 ) / V_47 ) < 3 )
V_54 = V_47 ;
return V_54 ;
}
static unsigned int F_17 ( struct V_1 * V_2 ,
unsigned int V_47 )
{
unsigned int V_53 ;
T_1 V_51 = 0 , V_52 = 0 ;
T_1 V_60 ;
int V_50 ;
struct V_61 * V_61 = V_2 -> V_62 ;
V_53 = F_15 ( V_2 -> V_63 , V_47 , & V_52 , & V_51 ,
& V_50 ) ;
V_60 = F_2 ( V_2 -> V_5 + V_64 ) ;
if ( V_50 )
V_60 |= V_65 ;
else
V_60 &= ~ V_65 ;
F_3 ( V_60 , V_2 -> V_5 + V_64 ) ;
F_3 ( V_51 , V_2 -> V_5 + V_66 ) ;
F_3 ( V_52 , V_2 -> V_5 + V_67 ) ;
V_61 -> V_47 = V_47 ;
return V_53 ;
}
static int F_18 ( struct V_68 * V_69 ,
unsigned long V_70 , void * V_16 )
{
T_1 V_71 ;
struct V_1 * V_2 ;
int V_72 = 0 ;
struct V_73 * V_74 = V_16 ;
unsigned long V_42 = 0 ;
struct V_61 * V_61 = F_19 ( V_69 ) ;
V_2 = V_61 -> V_2 ;
if ( V_2 -> V_75 )
return V_76 ;
switch ( V_70 ) {
case V_77 :
{
T_1 V_52 , V_51 ;
int V_50 ;
if ( ! F_15 ( V_74 -> V_78 , V_61 -> V_47 ,
& V_52 , & V_51 , & V_50 ) ) {
F_20 ( V_2 -> V_79 , L_1 ) ;
return V_80 ;
}
F_13 ( & V_61 -> V_2 -> V_43 , V_42 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 |= V_82 | V_83 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
F_14 ( & V_61 -> V_2 -> V_43 , V_42 ) ;
return V_76 ;
}
case V_84 :
F_13 ( & V_61 -> V_2 -> V_43 , V_42 ) ;
V_72 = 1 ;
V_2 -> V_63 = V_74 -> V_78 ;
V_61 -> V_47 = F_17 ( V_61 -> V_2 ,
V_61 -> V_47 ) ;
case V_85 :
if ( ! V_72 )
F_13 ( & V_61 -> V_2 -> V_43 , V_42 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 |= V_86 | V_87 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
while ( F_2 ( V_2 -> V_5 + V_81 ) &
( V_86 | V_87 ) )
F_21 () ;
F_3 ( V_88 , V_2 -> V_5 + V_89 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 &= ~ ( V_82 | V_83 ) ;
V_71 |= V_90 | V_91 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
F_14 ( & V_61 -> V_2 -> V_43 , V_42 ) ;
return V_76 ;
default:
return V_92 ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned int V_17 ;
if ( F_23 ( V_2 ) )
return;
V_17 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_17 &= ~ V_82 ;
V_17 |= V_90 ;
F_3 ( V_17 , V_2 -> V_5 + V_81 ) ;
if ( F_9 ( & V_2 -> V_28 -> V_30 ) )
return;
F_8 ( V_2 ) ;
F_3 ( V_31 , V_2 -> V_5 + V_11 ) ;
F_3 ( V_31 , V_2 -> V_5 + V_93 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_94 ;
V_94 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_94 |= V_82 ;
F_3 ( V_94 , V_2 -> V_5 + V_81 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_94 ;
F_3 ( V_44 , V_2 -> V_5 + V_32 ) ;
V_94 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_94 |= V_83 ;
F_3 ( V_94 , V_2 -> V_5 + V_81 ) ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
unsigned int V_17 ;
V_17 = F_2 ( V_2 -> V_5 + V_6 ) &
V_95 ;
return V_17 ? V_96 : 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_97 )
{
unsigned int V_17 ;
unsigned long V_42 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_81 ) ;
if ( V_97 == - 1 )
F_3 ( V_98 | V_17 ,
V_2 -> V_5 + V_81 ) ;
else {
if ( ( V_17 & V_99 ) == 0 )
F_3 ( V_99 | V_17 ,
V_2 -> V_5 + V_81 ) ;
}
F_14 ( & V_2 -> V_43 , V_42 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_100 * V_101 , struct V_100 * V_102 )
{
unsigned int V_103 = 0 ;
unsigned int V_47 , V_104 , V_105 ;
unsigned long V_42 ;
unsigned int V_71 , V_106 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
if ( ! ( F_2 ( V_2 -> V_5 + V_81 ) &
V_82 ) ) {
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) &
V_95 ) ) {
F_21 () ;
}
}
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 |= V_82 | V_83 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
V_104 = V_2 -> V_63 /
( ( V_57 + 1 ) * V_58 * 8 ) ;
V_105 = V_2 -> V_63 / ( V_59 + 1 ) ;
V_47 = F_29 ( V_2 , V_101 , V_102 , V_104 , V_105 ) ;
V_47 = F_17 ( V_2 , V_47 ) ;
if ( F_30 ( V_101 ) )
F_31 ( V_101 , V_47 , V_47 ) ;
F_32 ( V_2 , V_101 -> V_107 , V_47 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 |= V_86 | V_87 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 &= ~ ( V_82 | V_83 ) ;
V_71 |= V_90 | V_91 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
F_3 ( V_88 , V_2 -> V_5 + V_89 ) ;
V_2 -> V_9 = V_31 | V_14 |
V_26 | V_15 ;
V_2 -> V_12 = 0 ;
if ( V_101 -> V_108 & V_109 )
V_2 -> V_9 |= V_13 |
V_4 ;
if ( V_101 -> V_108 & V_110 )
V_2 -> V_12 |= V_13 |
V_4 | V_26 ;
if ( ( V_101 -> V_107 & V_111 ) == 0 )
V_2 -> V_12 |= V_14 |
V_15 | V_13 |
V_4 | V_26 ;
V_106 = F_2 ( V_2 -> V_5 + V_64 ) ;
switch ( V_101 -> V_107 & V_112 ) {
case V_113 :
V_103 |= V_114 ;
break;
case V_115 :
V_103 |= V_116 ;
break;
default:
case V_117 :
V_103 |= V_118 ;
V_101 -> V_107 &= ~ V_112 ;
V_101 -> V_107 |= V_117 ;
break;
}
if ( V_101 -> V_107 & V_119 )
V_103 |= V_120 ;
else
V_103 |= V_121 ;
if ( V_101 -> V_107 & V_122 ) {
if ( V_101 -> V_107 & V_123 ) {
if ( V_101 -> V_107 & V_124 )
V_103 |= V_125 ;
else
V_103 |= V_126 ;
} else {
if ( V_101 -> V_107 & V_124 )
V_103 |= V_127 ;
else
V_103 |= V_128 ;
}
} else {
V_103 |= V_129 ;
}
V_103 |= V_106 & 1 ;
F_3 ( V_103 , V_2 -> V_5 + V_64 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_130 ;
unsigned long V_42 ;
unsigned int V_17 = 0 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
F_3 ( V_82 | V_83 ,
V_2 -> V_5 + V_81 ) ;
F_3 ( V_86 | V_87 ,
V_2 -> V_5 + V_81 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_17 &= V_83 ;
V_17 |= V_91 ;
F_3 ( V_17 , V_2 -> V_5 + V_81 ) ;
F_3 ( V_131 | V_121
| V_129 | V_118 ,
V_2 -> V_5 + V_64 ) ;
F_3 ( V_132 , V_2 -> V_5 + V_133 ) ;
F_3 ( V_88 , V_2 -> V_5 + V_89 ) ;
F_3 ( F_2 ( V_2 -> V_5 + V_11 ) ,
V_2 -> V_5 + V_11 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
V_130 = F_34 ( V_2 -> V_40 , F_12 , 0 , V_134 , V_2 ) ;
if ( V_130 ) {
F_35 ( V_2 -> V_79 , L_2 ,
V_2 -> V_40 , V_130 ) ;
return V_130 ;
}
F_3 ( V_44 , V_2 -> V_5 + V_93 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_17 ;
unsigned long V_42 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_135 ) ;
F_3 ( V_17 , V_2 -> V_5 + V_32 ) ;
F_3 ( 0xffffffff , V_2 -> V_5 + V_11 ) ;
F_3 ( V_82 | V_83 ,
V_2 -> V_5 + V_81 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
F_37 ( V_2 -> V_40 , V_2 ) ;
}
static const char * F_38 ( struct V_1 * V_2 )
{
return V_2 -> type == V_136 ? V_134 : NULL ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
if ( V_138 -> type != V_139 && V_138 -> type != V_136 )
return - V_140 ;
if ( V_2 -> V_40 != V_138 -> V_40 )
return - V_140 ;
if ( V_138 -> V_141 != V_142 )
return - V_140 ;
if ( V_2 -> V_143 != V_138 -> V_2 )
return - V_140 ;
if ( V_138 -> V_144 != 0 )
return - V_140 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( ! F_41 ( V_2 -> V_145 , V_146 ,
V_134 ) ) {
return - V_147 ;
}
V_2 -> V_5 = F_42 ( V_2 -> V_145 , V_146 ) ;
if ( ! V_2 -> V_5 ) {
F_35 ( V_2 -> V_79 , L_3 ) ;
F_43 ( V_2 -> V_145 , V_146 ) ;
return - V_147 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_145 , V_146 ) ;
F_45 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_46 ( struct V_1 * V_2 , int V_42 )
{
if ( V_42 & V_148 && F_40 ( V_2 ) == 0 )
V_2 -> type = V_136 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
return V_149 | V_150 | V_151 ;
}
static void F_48 ( struct V_1 * V_2 , unsigned int V_152 )
{
T_1 V_153 ;
V_153 = F_2 ( V_2 -> V_5 + V_154 ) ;
V_153 &= ~ ( V_155 | V_156 ) ;
if ( V_152 & V_157 )
V_153 |= V_155 ;
if ( V_152 & V_158 )
V_153 |= V_156 ;
F_3 ( V_153 , V_2 -> V_5 + V_154 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_159 ;
unsigned long V_42 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
if ( F_2 ( V_2 -> V_5 + V_6 ) & V_7 )
V_159 = V_160 ;
else
V_159 = ( unsigned char ) F_2 ( V_2 -> V_5 + V_8 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
return V_159 ;
}
static void F_50 ( struct V_1 * V_2 , unsigned char V_159 )
{
unsigned long V_42 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) & V_95 ) )
F_21 () ;
F_3 ( V_159 , V_2 -> V_5 + V_8 ) ;
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) & V_95 ) )
F_21 () ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
return;
}
static struct V_1 * F_51 ( int V_161 )
{
struct V_1 * V_2 ;
if ( V_162 [ V_161 ] . V_145 != 0 ) {
for ( V_161 = 0 ; V_161 < V_163 ; V_161 ++ )
if ( V_162 [ V_161 ] . V_145 == 0 )
break;
}
if ( V_161 >= V_163 )
return NULL ;
V_2 = & V_162 [ V_161 ] ;
F_52 ( & V_2 -> V_43 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_40 = 0 ;
V_2 -> type = V_139 ;
V_2 -> V_164 = V_165 ;
V_2 -> V_42 = V_166 ;
V_2 -> V_167 = & V_168 ;
V_2 -> V_33 = V_169 ;
V_2 -> line = V_161 ;
V_2 -> V_79 = NULL ;
return V_2 ;
}
static void F_53 ( struct V_1 * V_2 )
{
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) & V_95 ) )
F_54 () ;
}
static void F_55 ( struct V_1 * V_2 , int V_170 )
{
F_53 ( V_2 ) ;
F_3 ( V_170 , V_2 -> V_5 + V_8 ) ;
}
static void T_3 F_56 ( struct V_171 * V_172 , const char * V_173 ,
unsigned V_174 )
{
struct V_175 * V_79 = V_172 -> V_16 ;
F_57 ( & V_79 -> V_2 , V_173 , V_174 , F_55 ) ;
}
static int T_3 F_58 ( struct V_175 * V_176 ,
const char * V_177 )
{
if ( ! V_176 -> V_2 . V_5 )
return - V_178 ;
V_176 -> V_172 -> V_179 = F_56 ;
return 0 ;
}
static void F_59 ( struct V_171 * V_180 , const char * V_173 ,
unsigned int V_181 )
{
struct V_1 * V_2 = & V_162 [ V_180 -> V_182 ] ;
unsigned long V_42 ;
unsigned int V_183 , V_184 ;
int V_72 = 1 ;
if ( V_2 -> V_185 )
V_72 = 0 ;
else if ( V_186 )
V_72 = F_60 ( & V_2 -> V_43 , V_42 ) ;
else
F_13 ( & V_2 -> V_43 , V_42 ) ;
V_183 = F_2 ( V_2 -> V_5 + V_135 ) ;
F_3 ( V_183 , V_2 -> V_5 + V_32 ) ;
V_184 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_184 &= ~ V_82 ;
V_184 |= V_90 ;
F_3 ( V_184 , V_2 -> V_5 + V_81 ) ;
F_57 ( V_2 , V_173 , V_181 , F_55 ) ;
F_53 ( V_2 ) ;
F_3 ( V_184 , V_2 -> V_5 + V_81 ) ;
F_3 ( V_183 , V_2 -> V_5 + V_93 ) ;
if ( V_72 )
F_14 ( & V_2 -> V_43 , V_42 ) ;
}
static int T_3 F_61 ( struct V_171 * V_180 , char * V_187 )
{
struct V_1 * V_2 = & V_162 [ V_180 -> V_182 ] ;
int V_47 = 9600 ;
int V_188 = 8 ;
int V_22 = 'n' ;
int V_189 = 'n' ;
if ( V_180 -> V_182 < 0 || V_180 -> V_182 >= V_163 )
return - V_140 ;
if ( ! V_2 -> V_5 ) {
F_62 ( L_4 V_190 L_5 ,
V_180 -> V_182 ) ;
return - V_178 ;
}
if ( V_187 )
F_63 ( V_187 , & V_47 , & V_22 , & V_188 , & V_189 ) ;
return F_64 ( V_2 , V_180 , V_47 , V_22 , V_188 , V_189 ) ;
}
static int T_3 F_65 ( void )
{
F_66 ( & V_191 ) ;
return 0 ;
}
static int F_67 ( struct V_176 * V_176 )
{
struct V_1 * V_2 = F_68 ( V_176 ) ;
struct V_192 * V_193 ;
struct V_176 * V_194 ;
int V_195 = 0 ;
V_193 = F_69 ( & V_2 -> V_28 -> V_2 ) ;
if ( V_193 ) {
V_194 = V_193 -> V_79 ;
V_195 = F_70 ( V_194 ) ;
F_71 ( V_193 ) ;
}
F_72 ( & V_196 , V_2 ) ;
if ( V_197 && ! V_195 ) {
struct V_61 * V_61 = V_2 -> V_62 ;
F_73 ( V_61 -> V_63 ) ;
F_73 ( V_61 -> V_198 ) ;
} else {
unsigned long V_42 = 0 ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
while ( ! ( F_2 ( V_2 -> V_5 + V_6 ) &
V_7 ) )
F_2 ( V_2 -> V_5 + V_8 ) ;
F_3 ( 1 , V_2 -> V_5 + V_133 ) ;
F_3 ( V_15 , V_2 -> V_5 + V_32 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
}
return 0 ;
}
static int F_74 ( struct V_176 * V_176 )
{
struct V_1 * V_2 = F_68 ( V_176 ) ;
unsigned long V_42 = 0 ;
T_1 V_71 ;
struct V_192 * V_193 ;
struct V_176 * V_194 ;
int V_195 = 0 ;
V_193 = F_69 ( & V_2 -> V_28 -> V_2 ) ;
if ( V_193 ) {
V_194 = V_193 -> V_79 ;
V_195 = F_70 ( V_194 ) ;
F_71 ( V_193 ) ;
}
if ( V_197 && ! V_195 ) {
struct V_61 * V_61 = V_2 -> V_62 ;
F_75 ( V_61 -> V_198 ) ;
F_75 ( V_61 -> V_63 ) ;
F_13 ( & V_2 -> V_43 , V_42 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 |= V_86 | V_87 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
while ( F_2 ( V_2 -> V_5 + V_81 ) &
( V_86 | V_87 ) )
F_21 () ;
F_3 ( V_88 , V_2 -> V_5 + V_89 ) ;
V_71 = F_2 ( V_2 -> V_5 + V_81 ) ;
V_71 &= ~ ( V_82 | V_83 ) ;
V_71 |= V_90 | V_91 ;
F_3 ( V_71 , V_2 -> V_5 + V_81 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
} else {
F_13 ( & V_2 -> V_43 , V_42 ) ;
F_3 ( V_132 , V_2 -> V_5 + V_133 ) ;
F_3 ( V_15 , V_2 -> V_5 + V_93 ) ;
F_14 ( & V_2 -> V_43 , V_42 ) ;
}
return F_76 ( & V_196 , V_2 ) ;
}
static int F_77 ( struct V_199 * V_200 )
{
int V_201 , V_161 , V_40 ;
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_61 * V_204 ;
V_204 = F_78 ( & V_200 -> V_79 , sizeof( * V_204 ) ,
V_205 ) ;
if ( ! V_204 )
return - V_147 ;
V_204 -> V_198 = F_79 ( & V_200 -> V_79 , L_6 ) ;
if ( F_80 ( V_204 -> V_198 ) ) {
V_204 -> V_198 = F_79 ( & V_200 -> V_79 , L_7 ) ;
if ( ! F_80 ( V_204 -> V_198 ) )
F_35 ( & V_200 -> V_79 , L_8 ) ;
}
if ( F_80 ( V_204 -> V_198 ) ) {
F_35 ( & V_200 -> V_79 , L_9 ) ;
return F_81 ( V_204 -> V_198 ) ;
}
V_204 -> V_63 = F_79 ( & V_200 -> V_79 , L_10 ) ;
if ( F_80 ( V_204 -> V_63 ) ) {
V_204 -> V_63 = F_79 ( & V_200 -> V_79 , L_11 ) ;
if ( ! F_80 ( V_204 -> V_63 ) )
F_35 ( & V_200 -> V_79 , L_12 ) ;
}
if ( F_80 ( V_204 -> V_63 ) ) {
F_35 ( & V_200 -> V_79 , L_13 ) ;
return F_81 ( V_204 -> V_63 ) ;
}
V_201 = F_82 ( V_204 -> V_198 ) ;
if ( V_201 ) {
F_35 ( & V_200 -> V_79 , L_14 ) ;
return V_201 ;
}
V_201 = F_82 ( V_204 -> V_63 ) ;
if ( V_201 ) {
F_35 ( & V_200 -> V_79 , L_15 ) ;
goto V_206;
}
V_203 = F_83 ( V_200 , V_207 , 0 ) ;
if ( ! V_203 ) {
V_201 = - V_178 ;
goto V_208;
}
V_40 = F_84 ( V_200 , 0 ) ;
if ( V_40 <= 0 ) {
V_201 = - V_209 ;
goto V_208;
}
#ifdef F_85
V_204 -> V_210 . V_211 =
F_18 ;
if ( F_86 ( V_204 -> V_63 ,
& V_204 -> V_210 ) )
F_20 ( & V_200 -> V_79 , L_16 ) ;
#endif
V_161 = F_87 ( V_200 -> V_79 . V_212 , L_17 ) ;
if ( V_161 < 0 )
V_161 = 0 ;
V_2 = F_51 ( V_161 ) ;
if ( ! V_2 ) {
F_35 ( & V_200 -> V_79 , L_18 ) ;
V_201 = - V_178 ;
goto V_213;
}
V_2 -> V_145 = V_203 -> V_214 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_79 = & V_200 -> V_79 ;
V_2 -> V_63 = F_88 ( V_204 -> V_63 ) ;
V_2 -> V_62 = V_204 ;
V_204 -> V_2 = V_2 ;
F_89 ( V_200 , V_2 ) ;
V_201 = F_90 ( & V_196 , V_2 ) ;
if ( V_201 ) {
F_35 ( & V_200 -> V_79 ,
L_19 , V_201 ) ;
goto V_213;
}
return 0 ;
V_213:
#ifdef F_85
F_91 ( V_204 -> V_63 ,
& V_204 -> V_210 ) ;
#endif
V_208:
F_92 ( V_204 -> V_63 ) ;
V_206:
F_92 ( V_204 -> V_198 ) ;
return V_201 ;
}
static int F_93 ( struct V_199 * V_200 )
{
struct V_1 * V_2 = F_94 ( V_200 ) ;
struct V_61 * V_204 = V_2 -> V_62 ;
int V_201 ;
#ifdef F_85
F_91 ( V_204 -> V_63 ,
& V_204 -> V_210 ) ;
#endif
V_201 = F_95 ( & V_196 , V_2 ) ;
V_2 -> V_145 = 0 ;
F_92 ( V_204 -> V_63 ) ;
F_92 ( V_204 -> V_198 ) ;
return V_201 ;
}
static int T_3 F_96 ( void )
{
int V_215 = 0 ;
V_215 = F_97 ( & V_196 ) ;
if ( V_215 )
return V_215 ;
V_215 = F_98 ( & V_216 ) ;
if ( V_215 )
F_99 ( & V_196 ) ;
return V_215 ;
}
static void T_4 F_100 ( void )
{
F_101 ( & V_216 ) ;
F_99 ( & V_196 ) ;
}
