static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
unsigned int V_8 ;
char V_9 = V_10 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_6 = F_3 ( V_12 ) ;
if ( V_6 & V_13 ) {
while ( ! ( F_3 ( V_14 ) &
V_15 ) ) {
if ( ! F_3 ( V_16 ) ) {
V_4 -> V_17 |= V_18 ;
V_6 &= ~ V_13 ;
}
}
F_4 ( V_13 , V_12 ) ;
}
if ( V_6 & V_4 -> V_19 & V_20 )
V_6 &= ~ ( V_21 | V_22 ) ;
V_6 &= V_4 -> V_17 ;
V_6 &= ~ V_4 -> V_19 ;
if ( ( V_6 & V_22 ) ||
( V_6 & V_21 ) ) {
while ( ( F_3 ( V_14 ) &
V_15 ) != V_15 ) {
V_8 = F_3 ( V_16 ) ;
if ( V_8 && ( V_4 -> V_17 &
V_18 ) ) {
V_4 -> V_17 &= ~ V_18 ;
V_4 -> V_23 . V_24 ++ ;
if ( F_5 ( V_4 ) )
continue;
}
#ifdef F_6
if ( V_4 -> V_25 ) {
F_7 ( & V_4 -> V_11 ) ;
if ( F_8 ( V_4 ,
( unsigned char ) V_8 ) ) {
F_9 ( & V_4 -> V_11 ) ;
continue;
}
F_9 ( & V_4 -> V_11 ) ;
}
#endif
V_4 -> V_23 . V_26 ++ ;
if ( V_6 & V_20 ) {
V_4 -> V_23 . V_27 ++ ;
V_9 = V_28 ;
} else if ( V_6 & V_13 ) {
V_4 -> V_23 . V_29 ++ ;
V_9 = V_30 ;
} else if ( V_6 & V_31 )
V_4 -> V_23 . V_32 ++ ;
F_10 ( V_4 , V_6 , V_31 ,
V_8 , V_9 ) ;
}
F_7 ( & V_4 -> V_11 ) ;
F_11 ( & V_4 -> V_33 -> V_4 ) ;
F_9 ( & V_4 -> V_11 ) ;
}
if ( ( V_6 & V_34 ) == V_34 ) {
if ( F_12 ( & V_4 -> V_33 -> V_35 ) ) {
F_4 ( V_34 ,
V_36 ) ;
} else {
V_7 = V_4 -> V_37 ;
while ( V_7 -- ) {
if ( F_12 ( & V_4 -> V_33 -> V_35 ) )
break;
F_4 (
V_4 -> V_33 -> V_35 . V_38 [ V_4 -> V_33 -> V_35 .
V_39 ] , V_16 ) ;
V_4 -> V_23 . V_40 ++ ;
V_4 -> V_33 -> V_35 . V_39 =
( V_4 -> V_33 -> V_35 . V_39 + 1 ) & \
( V_41 - 1 ) ;
}
if ( F_13 (
& V_4 -> V_33 -> V_35 ) < V_42 )
F_14 ( V_4 ) ;
}
}
F_4 ( V_6 , V_12 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
return V_43 ;
}
static unsigned int F_16 ( unsigned int V_44 , unsigned int V_45 ,
T_2 * V_46 , T_2 * V_47 , int * V_48 )
{
T_2 V_49 , V_50 ;
unsigned int V_51 ;
unsigned int V_52 = 0 ;
unsigned int V_53 ;
unsigned int V_54 = ~ 0 ;
if ( V_45 < V_44 / ( ( V_55 + 1 ) * V_56 ) ) {
* V_48 = 1 ;
V_44 /= 8 ;
} else {
* V_48 = 0 ;
}
for ( V_50 = V_57 ; V_50 <= V_55 ; V_50 ++ ) {
V_49 = F_17 ( V_44 , V_45 * ( V_50 + 1 ) ) ;
if ( V_49 < 1 || V_49 > V_56 )
continue;
V_51 = V_44 / ( V_49 * ( V_50 + 1 ) ) ;
if ( V_45 > V_51 )
V_53 = V_45 - V_51 ;
else
V_53 = V_51 - V_45 ;
if ( V_54 > V_53 ) {
* V_46 = V_50 ;
* V_47 = V_49 ;
V_52 = V_51 ;
V_54 = V_53 ;
}
}
if ( ( ( V_54 * 100 ) / V_45 ) < 3 )
V_52 = V_45 ;
return V_52 ;
}
static unsigned int F_18 ( struct V_3 * V_4 ,
unsigned int V_45 )
{
unsigned int V_51 ;
T_2 V_49 = 0 , V_50 = 0 ;
T_2 V_58 ;
int V_48 ;
struct V_59 * V_59 = V_4 -> V_60 ;
V_51 = F_16 ( V_4 -> V_61 , V_45 , & V_50 , & V_49 ,
& V_48 ) ;
V_58 = F_3 ( V_62 ) ;
if ( V_48 )
V_58 |= V_63 ;
else
V_58 &= ~ V_63 ;
F_4 ( V_58 , V_62 ) ;
F_4 ( V_49 , V_64 ) ;
F_4 ( V_50 , V_65 ) ;
V_59 -> V_45 = V_45 ;
return V_51 ;
}
static int F_19 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_8 )
{
T_2 V_69 ;
struct V_3 * V_4 ;
int V_70 = 0 ;
struct V_71 * V_72 = V_8 ;
unsigned long V_5 = 0 ;
struct V_59 * V_59 = F_20 ( V_67 ) ;
V_4 = V_59 -> V_4 ;
if ( V_4 -> V_73 )
return V_74 ;
switch ( V_68 ) {
case V_75 :
{
T_2 V_50 ;
T_2 V_49 ;
int V_48 ;
if ( ! F_16 ( V_72 -> V_76 , V_59 -> V_45 ,
& V_50 , & V_49 , & V_48 ) )
return V_77 ;
F_2 ( & V_59 -> V_4 -> V_11 , V_5 ) ;
F_4 ( F_3 ( V_78 ) |
( V_79 | V_80 ) ,
V_78 ) ;
F_15 ( & V_59 -> V_4 -> V_11 , V_5 ) ;
return V_74 ;
}
case V_81 :
F_2 ( & V_59 -> V_4 -> V_11 , V_5 ) ;
V_70 = 1 ;
V_4 -> V_61 = V_72 -> V_76 ;
V_59 -> V_45 = F_18 ( V_59 -> V_4 ,
V_59 -> V_45 ) ;
case V_82 :
if ( ! V_70 )
F_2 ( & V_59 -> V_4 -> V_11 , V_5 ) ;
F_4 ( F_3 ( V_78 ) |
( V_83 | V_84 ) ,
V_78 ) ;
while ( F_3 ( V_78 ) &
( V_83 | V_84 ) )
F_21 () ;
F_4 ( V_85 , V_86 ) ;
V_69 = F_3 ( V_78 ) ;
F_4 (
( V_69 & ~ ( V_79 | V_80 ) ) |
( V_87 | V_88 ) ,
V_78 ) ;
F_15 ( & V_59 -> V_4 -> V_11 , V_5 ) ;
return V_74 ;
default:
return V_89 ;
}
}
static void F_22 ( struct V_3 * V_4 )
{
unsigned int V_9 , V_7 = V_4 -> V_37 ;
if ( F_12 ( & V_4 -> V_33 -> V_35 ) || F_23 ( V_4 ) )
return;
V_9 = F_3 ( V_78 ) ;
F_4 ( ( V_9 & ~ V_79 ) | V_87 ,
V_78 ) ;
while ( V_7 -- && ( ( F_3 ( V_14 )
& V_90 ) ) != V_90 ) {
if ( F_12 ( & V_4 -> V_33 -> V_35 ) )
break;
F_4 (
V_4 -> V_33 -> V_35 . V_38 [ V_4 -> V_33 -> V_35 . V_39 ] ,
V_16 ) ;
V_4 -> V_23 . V_40 ++ ;
V_4 -> V_33 -> V_35 . V_39 = ( V_4 -> V_33 -> V_35 . V_39 + 1 ) &
( V_41 - 1 ) ;
}
F_4 ( V_34 , V_12 ) ;
F_4 ( V_34 , V_91 ) ;
if ( F_13 ( & V_4 -> V_33 -> V_35 ) < V_42 )
F_14 ( V_4 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
unsigned int V_92 ;
V_92 = F_3 ( V_78 ) ;
V_92 |= V_79 ;
F_4 ( V_92 , V_78 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
unsigned int V_92 ;
V_92 = F_3 ( V_78 ) ;
V_92 |= V_80 ;
F_4 ( V_92 , V_78 ) ;
}
static unsigned int F_26 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
V_9 = F_3 ( V_12 ) & V_34 ;
return V_9 ? V_93 : 0 ;
}
static void F_27 ( struct V_3 * V_4 , int V_94 )
{
unsigned int V_9 ;
unsigned long V_5 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_9 = F_3 ( V_78 ) ;
if ( V_94 == - 1 )
F_4 ( V_95 | V_9 ,
V_78 ) ;
else {
if ( ( V_9 & V_96 ) == 0 )
F_4 ( V_96 | V_9 ,
V_78 ) ;
}
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_97 * V_98 , struct V_97 * V_99 )
{
unsigned int V_100 = 0 ;
unsigned int V_45 , V_101 , V_102 ;
unsigned long V_5 ;
unsigned int V_69 , V_103 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
while ( ( F_3 ( V_14 ) &
V_15 ) != V_15 ) {
F_3 ( V_16 ) ;
}
F_4 ( F_3 ( V_78 ) |
( V_79 | V_80 ) ,
V_78 ) ;
V_101 = V_4 -> V_61 / ( ( V_55 + 1 ) * V_56 * 8 ) ;
V_102 = V_4 -> V_61 / ( V_57 + 1 ) ;
V_45 = F_29 ( V_4 , V_98 , V_99 , V_101 , V_102 ) ;
V_45 = F_18 ( V_4 , V_45 ) ;
if ( F_30 ( V_98 ) )
F_31 ( V_98 , V_45 , V_45 ) ;
F_32 ( V_4 , V_98 -> V_104 , V_45 ) ;
F_4 ( F_3 ( V_78 ) |
( V_83 | V_84 ) ,
V_78 ) ;
V_69 = F_3 ( V_78 ) ;
F_4 (
( V_69 & ~ ( V_79 | V_80 ) )
| ( V_87 | V_88 ) ,
V_78 ) ;
F_4 ( V_85 , V_86 ) ;
V_4 -> V_17 = V_34 | V_21 |
V_31 | V_22 ;
V_4 -> V_19 = 0 ;
if ( V_98 -> V_105 & V_106 )
V_4 -> V_17 |= V_20 |
V_13 ;
if ( V_98 -> V_105 & V_107 )
V_4 -> V_19 |= V_20 |
V_13 | V_31 ;
if ( ( V_98 -> V_104 & V_108 ) == 0 )
V_4 -> V_19 |= V_21 |
V_22 | V_20 |
V_13 | V_31 ;
V_103 = F_3 ( V_62 ) ;
switch ( V_98 -> V_104 & V_109 ) {
case V_110 :
V_100 |= V_111 ;
break;
case V_112 :
V_100 |= V_113 ;
break;
default:
case V_114 :
V_100 |= V_115 ;
V_98 -> V_104 &= ~ V_109 ;
V_98 -> V_104 |= V_114 ;
break;
}
if ( V_98 -> V_104 & V_116 )
V_100 |= V_117 ;
else
V_100 |= V_118 ;
if ( V_98 -> V_104 & V_119 ) {
if ( V_98 -> V_104 & V_120 ) {
if ( V_98 -> V_104 & V_121 )
V_100 |= V_122 ;
else
V_100 |= V_123 ;
} else {
if ( V_98 -> V_104 & V_121 )
V_100 |= V_124 ;
else
V_100 |= V_125 ;
}
} else {
V_100 |= V_126 ;
}
V_100 |= V_103 & 1 ;
F_4 ( V_100 , V_62 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static int F_33 ( struct V_3 * V_4 )
{
unsigned int V_127 = 0 , V_9 = 0 ;
V_127 = F_34 ( V_4 -> V_1 , F_1 , 0 , V_128 ,
( void * ) V_4 ) ;
if ( V_127 )
return V_127 ;
F_4 ( V_79 | V_80 ,
V_78 ) ;
F_4 ( V_83 | V_84 ,
V_78 ) ;
V_9 = F_3 ( V_78 ) ;
F_4 ( ( V_9 & ~ ( V_79 | V_80 ) )
| ( V_87 | V_88 |
V_96 ) , V_78 ) ;
F_4 ( V_129 | V_118
| V_126 | V_115 ,
V_62 ) ;
F_4 ( V_130 , V_131 ) ;
F_4 ( V_85 , V_86 ) ;
F_4 ( F_3 ( V_12 ) , V_12 ) ;
F_4 ( V_34 | V_20 |
V_13 | V_31 |
V_21 | V_22 , V_91 ) ;
return V_127 ;
}
static void F_35 ( struct V_3 * V_4 )
{
int V_9 ;
V_9 = F_3 ( V_132 ) ;
F_4 ( V_9 , V_36 ) ;
F_4 ( V_79 | V_80 ,
V_78 ) ;
F_36 ( V_4 -> V_1 , V_4 ) ;
}
static const char * F_37 ( struct V_3 * V_4 )
{
return V_4 -> type == V_133 ? V_128 : NULL ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_134 * V_135 )
{
if ( V_135 -> type != V_136 && V_135 -> type != V_133 )
return - V_137 ;
if ( V_4 -> V_1 != V_135 -> V_1 )
return - V_137 ;
if ( V_135 -> V_138 != V_139 )
return - V_137 ;
if ( V_4 -> V_140 != V_135 -> V_4 )
return - V_137 ;
if ( V_135 -> V_141 != 0 )
return - V_137 ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 )
{
if ( ! F_40 ( V_4 -> V_142 , V_143 ,
V_128 ) ) {
return - V_144 ;
}
V_4 -> V_145 = F_41 ( V_4 -> V_142 , V_143 ) ;
if ( ! V_4 -> V_145 ) {
F_42 ( V_4 -> V_146 , L_1 ) ;
F_43 ( V_4 -> V_142 , V_143 ) ;
return - V_144 ;
}
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
F_43 ( V_4 -> V_142 , V_143 ) ;
F_45 ( V_4 -> V_145 ) ;
V_4 -> V_145 = NULL ;
}
static void F_46 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_147 && F_39 ( V_4 ) == 0 )
V_4 -> type = V_133 ;
}
static unsigned int F_47 ( struct V_3 * V_4 )
{
return V_148 | V_149 | V_150 ;
}
static void F_48 ( struct V_3 * V_4 , unsigned int V_151 )
{
}
static void F_49 ( struct V_3 * V_4 )
{
}
static int F_50 ( struct V_3 * V_4 )
{
T_2 V_152 ;
int V_153 ;
V_152 = F_3 ( V_132 ) ;
F_4 ( V_152 , V_36 ) ;
if ( F_3 ( V_14 ) & V_15 )
V_153 = V_154 ;
else
V_153 = ( unsigned char ) F_3 ( V_16 ) ;
F_4 ( V_152 , V_91 ) ;
return V_153 ;
}
static void F_51 ( struct V_3 * V_4 , unsigned char V_153 )
{
T_2 V_152 ;
V_152 = F_3 ( V_132 ) ;
F_4 ( V_152 , V_36 ) ;
while ( ! ( F_3 ( V_14 ) & V_155 ) )
F_21 () ;
F_4 ( V_153 , V_16 ) ;
while ( ! ( F_3 ( V_14 ) & V_155 ) )
F_21 () ;
F_4 ( V_152 , V_91 ) ;
return;
}
static struct V_3 * F_52 ( void )
{
struct V_3 * V_4 ;
int V_156 ;
for ( V_156 = 0 ; V_156 < V_157 ; V_156 ++ )
if ( V_158 [ V_156 ] . V_142 == 0 )
break;
if ( V_156 >= V_157 )
return NULL ;
V_4 = & V_158 [ V_156 ] ;
F_53 ( & V_4 -> V_11 ) ;
V_4 -> V_145 = NULL ;
V_4 -> V_140 = 1 ;
V_4 -> V_1 = 0 ;
V_4 -> type = V_136 ;
V_4 -> V_159 = V_160 ;
V_4 -> V_5 = V_161 ;
V_4 -> V_162 = & V_163 ;
V_4 -> V_37 = V_164 ;
V_4 -> line = V_156 ;
V_4 -> V_146 = NULL ;
return V_4 ;
}
static void F_54 ( struct V_3 * V_4 )
{
while ( ( F_3 ( V_14 ) & V_155 )
!= V_155 )
F_55 () ;
}
static void F_56 ( struct V_3 * V_4 , int V_165 )
{
F_54 ( V_4 ) ;
F_4 ( V_165 , V_16 ) ;
}
static void F_57 ( struct V_166 * V_167 , const char * V_168 ,
unsigned int V_169 )
{
struct V_3 * V_4 = & V_158 [ V_167 -> V_170 ] ;
unsigned long V_5 ;
unsigned int V_152 , V_171 ;
int V_70 = 1 ;
if ( V_172 )
V_70 = F_58 ( & V_4 -> V_11 , V_5 ) ;
else
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_152 = F_3 ( V_132 ) ;
F_4 ( V_152 , V_36 ) ;
V_171 = F_3 ( V_78 ) ;
F_4 ( ( V_171 & ~ V_79 ) | V_87 ,
V_78 ) ;
F_59 ( V_4 , V_168 , V_169 , F_56 ) ;
F_54 ( V_4 ) ;
F_4 ( V_171 , V_78 ) ;
F_4 ( ~ V_152 , V_36 ) ;
F_4 ( V_152 , V_91 ) ;
if ( V_70 )
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static int T_3 F_60 ( struct V_166 * V_167 , char * V_173 )
{
struct V_3 * V_4 = & V_158 [ V_167 -> V_170 ] ;
int V_45 = 9600 ;
int V_174 = 8 ;
int V_27 = 'n' ;
int V_175 = 'n' ;
if ( V_167 -> V_170 < 0 || V_167 -> V_170 >= V_157 )
return - V_137 ;
if ( ! V_4 -> V_142 ) {
F_61 ( L_2 , V_167 -> V_170 ) ;
return - V_176 ;
}
if ( V_173 )
F_62 ( V_173 , & V_45 , & V_27 , & V_174 , & V_175 ) ;
return F_63 ( V_4 , V_167 , V_45 , V_27 , V_174 , V_175 ) ;
}
static int T_3 F_64 ( void )
{
F_65 ( & V_177 ) ;
return 0 ;
}
static int F_66 ( struct V_178 * V_178 )
{
struct V_3 * V_4 = F_67 ( V_178 ) ;
struct V_179 * V_180 ;
struct V_178 * V_181 ;
int V_182 = 0 ;
V_180 = F_68 ( & V_4 -> V_33 -> V_4 ) ;
if ( V_180 ) {
V_181 = V_180 -> V_146 ;
V_182 = F_69 ( V_181 ) ;
F_70 ( V_180 ) ;
}
F_71 ( & V_183 , V_4 ) ;
if ( V_184 && ! V_182 ) {
struct V_59 * V_59 = V_4 -> V_60 ;
F_72 ( V_59 -> V_185 ) ;
F_72 ( V_59 -> V_186 ) ;
} else {
unsigned long V_5 = 0 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
while ( ! ( F_3 ( V_14 ) & V_15 ) )
F_3 ( V_16 ) ;
F_4 ( 1 , V_131 ) ;
F_4 ( V_22 , V_36 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
return 0 ;
}
static int F_73 ( struct V_178 * V_178 )
{
struct V_3 * V_4 = F_67 ( V_178 ) ;
unsigned long V_5 = 0 ;
T_2 V_69 ;
struct V_179 * V_180 ;
struct V_178 * V_181 ;
int V_182 = 0 ;
V_180 = F_68 ( & V_4 -> V_33 -> V_4 ) ;
if ( V_180 ) {
V_181 = V_180 -> V_146 ;
V_182 = F_69 ( V_181 ) ;
F_70 ( V_180 ) ;
}
if ( V_184 && ! V_182 ) {
struct V_59 * V_59 = V_4 -> V_60 ;
F_74 ( V_59 -> V_186 ) ;
F_74 ( V_59 -> V_185 ) ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
F_4 ( F_3 ( V_78 ) |
( V_83 | V_84 ) ,
V_78 ) ;
while ( F_3 ( V_78 ) &
( V_83 | V_84 ) )
F_21 () ;
F_4 ( V_85 , V_86 ) ;
V_69 = F_3 ( V_78 ) ;
F_4 (
( V_69 & ~ ( V_79 | V_80 ) ) |
( V_87 | V_88 ) ,
V_78 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
} else {
F_2 ( & V_4 -> V_11 , V_5 ) ;
F_4 ( V_130 , V_131 ) ;
F_4 ( V_22 , V_91 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
return F_75 ( & V_183 , V_4 ) ;
}
static int F_76 ( struct V_187 * V_188 )
{
int V_189 ;
struct V_3 * V_4 ;
struct V_190 * V_191 , * V_192 ;
struct V_59 * V_193 ;
V_193 = F_77 ( & V_188 -> V_146 , sizeof( * V_193 ) ,
V_194 ) ;
if ( ! V_193 )
return - V_144 ;
V_193 -> V_186 = F_78 ( & V_188 -> V_146 , L_3 ) ;
if ( F_79 ( V_193 -> V_186 ) ) {
F_42 ( & V_188 -> V_146 , L_4 ) ;
return F_80 ( V_193 -> V_186 ) ;
}
V_193 -> V_185 = F_78 ( & V_188 -> V_146 , L_5 ) ;
if ( F_79 ( V_193 -> V_185 ) ) {
F_42 ( & V_188 -> V_146 , L_6 ) ;
return F_80 ( V_193 -> V_185 ) ;
}
V_189 = F_81 ( V_193 -> V_186 ) ;
if ( V_189 ) {
F_42 ( & V_188 -> V_146 , L_7 ) ;
return V_189 ;
}
V_189 = F_81 ( V_193 -> V_185 ) ;
if ( V_189 ) {
F_42 ( & V_188 -> V_146 , L_8 ) ;
goto V_195;
}
V_191 = F_82 ( V_188 , V_196 , 0 ) ;
if ( ! V_191 ) {
V_189 = - V_176 ;
goto V_197;
}
V_192 = F_82 ( V_188 , V_198 , 0 ) ;
if ( ! V_192 ) {
V_189 = - V_176 ;
goto V_197;
}
#ifdef F_83
V_193 -> V_199 . V_200 =
F_19 ;
if ( F_84 ( V_193 -> V_185 ,
& V_193 -> V_199 ) )
F_85 ( & V_188 -> V_146 , L_9 ) ;
#endif
V_4 = F_52 () ;
if ( ! V_4 ) {
F_42 ( & V_188 -> V_146 , L_10 ) ;
V_189 = - V_176 ;
goto V_201;
} else {
V_4 -> V_142 = V_191 -> V_202 ;
V_4 -> V_1 = V_192 -> V_202 ;
V_4 -> V_146 = & V_188 -> V_146 ;
V_4 -> V_61 = F_86 ( V_193 -> V_185 ) ;
V_4 -> V_60 = V_193 ;
V_193 -> V_4 = V_4 ;
F_87 ( V_188 , V_4 ) ;
V_189 = F_88 ( & V_183 , V_4 ) ;
if ( V_189 ) {
F_42 ( & V_188 -> V_146 ,
L_11 , V_189 ) ;
goto V_201;
}
return 0 ;
}
V_201:
#ifdef F_83
F_89 ( V_193 -> V_185 ,
& V_193 -> V_199 ) ;
#endif
V_197:
F_90 ( V_193 -> V_185 ) ;
V_195:
F_90 ( V_193 -> V_186 ) ;
return V_189 ;
}
static int F_91 ( struct V_187 * V_188 )
{
struct V_3 * V_4 = F_92 ( V_188 ) ;
struct V_59 * V_193 = V_4 -> V_60 ;
int V_189 ;
#ifdef F_83
F_89 ( V_193 -> V_185 ,
& V_193 -> V_199 ) ;
#endif
V_189 = F_93 ( & V_183 , V_4 ) ;
V_4 -> V_142 = 0 ;
F_90 ( V_193 -> V_185 ) ;
F_90 ( V_193 -> V_186 ) ;
return V_189 ;
}
static int T_3 F_94 ( void )
{
int V_127 = 0 ;
V_127 = F_95 ( & V_183 ) ;
if ( V_127 )
return V_127 ;
V_127 = F_96 ( & V_203 ) ;
if ( V_127 )
F_97 ( & V_183 ) ;
return V_127 ;
}
static void T_4 F_98 ( void )
{
F_99 ( & V_203 ) ;
F_97 ( & V_183 ) ;
}
