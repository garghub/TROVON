static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
unsigned int V_8 ;
char V_9 = V_10 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_6 = F_3 ( V_4 -> V_12 + V_13 ) ;
if ( V_6 & V_14 ) {
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_16 ) ) {
if ( ! F_3 ( V_4 -> V_12 + V_17 ) ) {
V_4 -> V_18 |= V_19 ;
V_6 &= ~ V_14 ;
}
}
F_4 ( V_14 ,
V_4 -> V_12 + V_13 ) ;
}
if ( V_6 & V_4 -> V_20 & V_21 )
V_6 &= ~ ( V_22 | V_23 ) ;
V_6 &= V_4 -> V_18 ;
V_6 &= ~ V_4 -> V_20 ;
if ( ( V_6 & V_23 ) ||
( V_6 & V_22 ) ) {
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_16 ) ) {
V_8 = F_3 ( V_4 -> V_12 + V_17 ) ;
if ( V_8 && ( V_4 -> V_18 &
V_19 ) ) {
V_4 -> V_18 &= ~ V_19 ;
V_4 -> V_24 . V_25 ++ ;
if ( F_5 ( V_4 ) )
continue;
}
#ifdef F_6
if ( V_4 -> V_26 ) {
F_7 ( & V_4 -> V_11 ) ;
if ( F_8 ( V_4 ,
( unsigned char ) V_8 ) ) {
F_9 ( & V_4 -> V_11 ) ;
continue;
}
F_9 ( & V_4 -> V_11 ) ;
}
#endif
V_4 -> V_24 . V_27 ++ ;
if ( V_6 & V_21 ) {
V_4 -> V_24 . V_28 ++ ;
V_9 = V_29 ;
} else if ( V_6 & V_14 ) {
V_4 -> V_24 . V_30 ++ ;
V_9 = V_31 ;
} else if ( V_6 & V_32 ) {
V_4 -> V_24 . V_33 ++ ;
}
F_10 ( V_4 , V_6 , V_32 ,
V_8 , V_9 ) ;
}
F_7 ( & V_4 -> V_11 ) ;
F_11 ( & V_4 -> V_34 -> V_4 ) ;
F_9 ( & V_4 -> V_11 ) ;
}
if ( ( V_6 & V_35 ) == V_35 ) {
if ( F_12 ( & V_4 -> V_34 -> V_36 ) ) {
F_4 ( V_35 ,
V_4 -> V_12 + V_37 ) ;
} else {
V_7 = V_4 -> V_38 ;
while ( V_7 -- ) {
if ( F_12 ( & V_4 -> V_34 -> V_36 ) )
break;
F_4 ( V_4 -> V_34 -> V_36 . V_39 [
V_4 -> V_34 -> V_36 . V_40 ] ,
V_4 -> V_12 + V_17 ) ;
V_4 -> V_24 . V_41 ++ ;
V_4 -> V_34 -> V_36 . V_40 =
( V_4 -> V_34 -> V_36 . V_40 + 1 ) &
( V_42 - 1 ) ;
}
if ( F_13 (
& V_4 -> V_34 -> V_36 ) < V_43 )
F_14 ( V_4 ) ;
}
}
F_4 ( V_6 , V_4 -> V_12 + V_13 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
return V_44 ;
}
static unsigned int F_16 ( unsigned int V_45 ,
unsigned int V_46 , T_2 * V_47 , T_2 * V_48 , int * V_49 )
{
T_2 V_50 , V_51 ;
unsigned int V_52 ;
unsigned int V_53 = 0 ;
unsigned int V_54 ;
unsigned int V_55 = ~ 0 ;
if ( V_46 < V_45 / ( ( V_56 + 1 ) * V_57 ) ) {
* V_49 = 1 ;
V_45 /= 8 ;
} else {
* V_49 = 0 ;
}
for ( V_51 = V_58 ; V_51 <= V_56 ; V_51 ++ ) {
V_50 = F_17 ( V_45 , V_46 * ( V_51 + 1 ) ) ;
if ( V_50 < 1 || V_50 > V_57 )
continue;
V_52 = V_45 / ( V_50 * ( V_51 + 1 ) ) ;
if ( V_46 > V_52 )
V_54 = V_46 - V_52 ;
else
V_54 = V_52 - V_46 ;
if ( V_55 > V_54 ) {
* V_47 = V_51 ;
* V_48 = V_50 ;
V_53 = V_52 ;
V_55 = V_54 ;
}
}
if ( ( ( V_55 * 100 ) / V_46 ) < 3 )
V_53 = V_46 ;
return V_53 ;
}
static unsigned int F_18 ( struct V_3 * V_4 ,
unsigned int V_46 )
{
unsigned int V_52 ;
T_2 V_50 = 0 , V_51 = 0 ;
T_2 V_59 ;
int V_49 ;
struct V_60 * V_60 = V_4 -> V_61 ;
V_52 = F_16 ( V_4 -> V_62 , V_46 , & V_51 , & V_50 ,
& V_49 ) ;
V_59 = F_3 ( V_4 -> V_12 + V_63 ) ;
if ( V_49 )
V_59 |= V_64 ;
else
V_59 &= ~ V_64 ;
F_4 ( V_59 , V_4 -> V_12 + V_63 ) ;
F_4 ( V_50 , V_4 -> V_12 + V_65 ) ;
F_4 ( V_51 , V_4 -> V_12 + V_66 ) ;
V_60 -> V_46 = V_46 ;
return V_52 ;
}
static int F_19 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_8 )
{
T_2 V_70 ;
struct V_3 * V_4 ;
int V_71 = 0 ;
struct V_72 * V_73 = V_8 ;
unsigned long V_5 = 0 ;
struct V_60 * V_60 = F_20 ( V_68 ) ;
V_4 = V_60 -> V_4 ;
if ( V_4 -> V_74 )
return V_75 ;
switch ( V_69 ) {
case V_76 :
{
T_2 V_51 , V_50 ;
int V_49 ;
if ( ! F_16 ( V_73 -> V_77 , V_60 -> V_46 ,
& V_51 , & V_50 , & V_49 ) ) {
F_21 ( V_4 -> V_78 , L_1 ) ;
return V_79 ;
}
F_2 ( & V_60 -> V_4 -> V_11 , V_5 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 |= V_81 | V_82 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
F_15 ( & V_60 -> V_4 -> V_11 , V_5 ) ;
return V_75 ;
}
case V_83 :
F_2 ( & V_60 -> V_4 -> V_11 , V_5 ) ;
V_71 = 1 ;
V_4 -> V_62 = V_73 -> V_77 ;
V_60 -> V_46 = F_18 ( V_60 -> V_4 ,
V_60 -> V_46 ) ;
case V_84 :
if ( ! V_71 )
F_2 ( & V_60 -> V_4 -> V_11 , V_5 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 |= V_85 | V_86 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
while ( F_3 ( V_4 -> V_12 + V_80 ) &
( V_85 | V_86 ) )
F_22 () ;
F_4 ( V_87 , V_4 -> V_12 + V_88 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 &= ~ ( V_81 | V_82 ) ;
V_70 |= V_89 | V_90 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
F_15 ( & V_60 -> V_4 -> V_11 , V_5 ) ;
return V_75 ;
default:
return V_91 ;
}
}
static void F_23 ( struct V_3 * V_4 )
{
unsigned int V_9 , V_7 = V_4 -> V_38 ;
if ( F_12 ( & V_4 -> V_34 -> V_36 ) || F_24 ( V_4 ) )
return;
V_9 = F_3 ( V_4 -> V_12 + V_80 ) ;
F_4 ( ( V_9 & ~ V_81 ) | V_89 ,
V_4 -> V_12 + V_80 ) ;
while ( V_7 -- && ( ( F_3 ( V_4 -> V_12 + V_15 ) &
V_92 ) ) != V_92 ) {
if ( F_12 ( & V_4 -> V_34 -> V_36 ) )
break;
F_4 ( V_4 -> V_34 -> V_36 . V_39 [ V_4 -> V_34 -> V_36 . V_40 ] ,
V_4 -> V_12 + V_17 ) ;
V_4 -> V_24 . V_41 ++ ;
V_4 -> V_34 -> V_36 . V_40 = ( V_4 -> V_34 -> V_36 . V_40 + 1 ) &
( V_42 - 1 ) ;
}
F_4 ( V_35 , V_4 -> V_12 + V_13 ) ;
F_4 ( V_35 , V_4 -> V_12 + V_93 ) ;
if ( F_13 ( & V_4 -> V_34 -> V_36 ) < V_43 )
F_14 ( V_4 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
unsigned int V_94 ;
V_94 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_94 |= V_81 ;
F_4 ( V_94 , V_4 -> V_12 + V_80 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
unsigned int V_94 ;
V_94 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_94 |= V_82 ;
F_4 ( V_94 , V_4 -> V_12 + V_80 ) ;
}
static unsigned int F_27 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
V_9 = F_3 ( V_4 -> V_12 + V_15 ) &
V_95 ;
return V_9 ? V_96 : 0 ;
}
static void F_28 ( struct V_3 * V_4 , int V_97 )
{
unsigned int V_9 ;
unsigned long V_5 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_9 = F_3 ( V_4 -> V_12 + V_80 ) ;
if ( V_97 == - 1 )
F_4 ( V_98 | V_9 ,
V_4 -> V_12 + V_80 ) ;
else {
if ( ( V_9 & V_99 ) == 0 )
F_4 ( V_99 | V_9 ,
V_4 -> V_12 + V_80 ) ;
}
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static void F_29 ( struct V_3 * V_4 ,
struct V_100 * V_101 , struct V_100 * V_102 )
{
unsigned int V_103 = 0 ;
unsigned int V_46 , V_104 , V_105 ;
unsigned long V_5 ;
unsigned int V_70 , V_106 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
if ( ! ( F_3 ( V_4 -> V_12 + V_80 ) &
V_81 ) ) {
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_95 ) ) {
F_22 () ;
}
}
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 |= V_81 | V_82 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
V_104 = V_4 -> V_62 /
( ( V_56 + 1 ) * V_57 * 8 ) ;
V_105 = V_4 -> V_62 / ( V_58 + 1 ) ;
V_46 = F_30 ( V_4 , V_101 , V_102 , V_104 , V_105 ) ;
V_46 = F_18 ( V_4 , V_46 ) ;
if ( F_31 ( V_101 ) )
F_32 ( V_101 , V_46 , V_46 ) ;
F_33 ( V_4 , V_101 -> V_107 , V_46 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 |= V_85 | V_86 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 &= ~ ( V_81 | V_82 ) ;
V_70 |= V_89 | V_90 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
F_4 ( V_87 , V_4 -> V_12 + V_88 ) ;
V_4 -> V_18 = V_35 | V_22 |
V_32 | V_23 ;
V_4 -> V_20 = 0 ;
if ( V_101 -> V_108 & V_109 )
V_4 -> V_18 |= V_21 |
V_14 ;
if ( V_101 -> V_108 & V_110 )
V_4 -> V_20 |= V_21 |
V_14 | V_32 ;
if ( ( V_101 -> V_107 & V_111 ) == 0 )
V_4 -> V_20 |= V_22 |
V_23 | V_21 |
V_14 | V_32 ;
V_106 = F_3 ( V_4 -> V_12 + V_63 ) ;
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
F_4 ( V_103 , V_4 -> V_12 + V_63 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
unsigned int V_130 = 0 , V_9 = 0 ;
V_130 = F_35 ( V_4 -> V_1 , F_1 , 0 , V_131 ,
( void * ) V_4 ) ;
if ( V_130 )
return V_130 ;
F_4 ( V_81 | V_82 ,
V_4 -> V_12 + V_80 ) ;
F_4 ( V_85 | V_86 ,
V_4 -> V_12 + V_80 ) ;
V_9 = F_3 ( V_4 -> V_12 + V_80 ) ;
F_4 ( ( V_9 & ~ ( V_81 | V_82 ) )
| ( V_89 | V_90 |
V_99 ) ,
V_4 -> V_12 + V_80 ) ;
F_4 ( V_132 | V_121
| V_129 | V_118 ,
V_4 -> V_12 + V_63 ) ;
F_4 ( V_133 , V_4 -> V_12 + V_134 ) ;
F_4 ( V_87 , V_4 -> V_12 + V_88 ) ;
F_4 ( F_3 ( V_4 -> V_12 + V_13 ) ,
V_4 -> V_12 + V_13 ) ;
F_4 ( V_35 | V_21 |
V_14 | V_32 |
V_22 | V_23 ,
V_4 -> V_12 + V_93 ) ;
return V_130 ;
}
static void F_36 ( struct V_3 * V_4 )
{
int V_9 ;
V_9 = F_3 ( V_4 -> V_12 + V_135 ) ;
F_4 ( V_9 , V_4 -> V_12 + V_37 ) ;
F_4 ( V_81 | V_82 ,
V_4 -> V_12 + V_80 ) ;
F_37 ( V_4 -> V_1 , V_4 ) ;
}
static const char * F_38 ( struct V_3 * V_4 )
{
return V_4 -> type == V_136 ? V_131 : NULL ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_137 * V_138 )
{
if ( V_138 -> type != V_139 && V_138 -> type != V_136 )
return - V_140 ;
if ( V_4 -> V_1 != V_138 -> V_1 )
return - V_140 ;
if ( V_138 -> V_141 != V_142 )
return - V_140 ;
if ( V_4 -> V_143 != V_138 -> V_4 )
return - V_140 ;
if ( V_138 -> V_144 != 0 )
return - V_140 ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 )
{
if ( ! F_41 ( V_4 -> V_145 , V_146 ,
V_131 ) ) {
return - V_147 ;
}
V_4 -> V_12 = F_42 ( V_4 -> V_145 , V_146 ) ;
if ( ! V_4 -> V_12 ) {
F_43 ( V_4 -> V_78 , L_2 ) ;
F_44 ( V_4 -> V_145 , V_146 ) ;
return - V_147 ;
}
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
F_44 ( V_4 -> V_145 , V_146 ) ;
F_46 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
static void F_47 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_148 && F_40 ( V_4 ) == 0 )
V_4 -> type = V_136 ;
}
static unsigned int F_48 ( struct V_3 * V_4 )
{
return V_149 | V_150 | V_151 ;
}
static void F_49 ( struct V_3 * V_4 , unsigned int V_152 )
{
T_2 V_153 ;
V_153 = F_3 ( V_4 -> V_12 + V_154 ) ;
V_153 &= ~ ( V_155 | V_156 ) ;
if ( V_152 & V_157 )
V_153 |= V_155 ;
if ( V_152 & V_158 )
V_153 |= V_156 ;
F_4 ( V_153 , V_4 -> V_12 + V_154 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
T_2 V_159 ;
int V_160 ;
V_159 = F_3 ( V_4 -> V_12 + V_135 ) ;
F_4 ( V_159 , V_4 -> V_12 + V_37 ) ;
if ( F_3 ( V_4 -> V_12 + V_15 ) & V_16 )
V_160 = V_161 ;
else
V_160 = ( unsigned char ) F_3 (
V_4 -> V_12 + V_17 ) ;
F_4 ( V_159 , V_4 -> V_12 + V_93 ) ;
return V_160 ;
}
static void F_51 ( struct V_3 * V_4 , unsigned char V_160 )
{
T_2 V_159 ;
V_159 = F_3 ( V_4 -> V_12 + V_135 ) ;
F_4 ( V_159 , V_4 -> V_12 + V_37 ) ;
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_95 ) )
F_22 () ;
F_4 ( V_160 , V_4 -> V_12 + V_17 ) ;
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_95 ) )
F_22 () ;
F_4 ( V_159 , V_4 -> V_12 + V_93 ) ;
return;
}
static struct V_3 * F_52 ( int V_162 )
{
struct V_3 * V_4 ;
if ( V_163 [ V_162 ] . V_145 != 0 ) {
for ( V_162 = 0 ; V_162 < V_164 ; V_162 ++ )
if ( V_163 [ V_162 ] . V_145 == 0 )
break;
}
if ( V_162 >= V_164 )
return NULL ;
V_4 = & V_163 [ V_162 ] ;
F_53 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = NULL ;
V_4 -> V_1 = 0 ;
V_4 -> type = V_139 ;
V_4 -> V_165 = V_166 ;
V_4 -> V_5 = V_167 ;
V_4 -> V_168 = & V_169 ;
V_4 -> V_38 = V_170 ;
V_4 -> line = V_162 ;
V_4 -> V_78 = NULL ;
return V_4 ;
}
static void F_54 ( struct V_3 * V_4 )
{
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_95 ) )
F_55 () ;
}
static void F_56 ( struct V_3 * V_4 , int V_171 )
{
F_54 ( V_4 ) ;
F_4 ( V_171 , V_4 -> V_12 + V_17 ) ;
}
static void T_3 F_57 ( struct V_172 * V_173 , const char * V_174 ,
unsigned V_175 )
{
struct V_176 * V_78 = V_173 -> V_8 ;
F_58 ( & V_78 -> V_4 , V_174 , V_175 , F_56 ) ;
}
static int T_3 F_59 ( struct V_176 * V_177 ,
const char * V_178 )
{
if ( ! V_177 -> V_4 . V_12 )
return - V_179 ;
V_177 -> V_173 -> V_180 = F_57 ;
return 0 ;
}
static void F_60 ( struct V_172 * V_181 , const char * V_174 ,
unsigned int V_182 )
{
struct V_3 * V_4 = & V_163 [ V_181 -> V_183 ] ;
unsigned long V_5 ;
unsigned int V_159 , V_184 ;
int V_71 = 1 ;
if ( V_185 )
V_71 = F_61 ( & V_4 -> V_11 , V_5 ) ;
else
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_159 = F_3 ( V_4 -> V_12 + V_135 ) ;
F_4 ( V_159 , V_4 -> V_12 + V_37 ) ;
V_184 = F_3 ( V_4 -> V_12 + V_80 ) ;
F_4 ( ( V_184 & ~ V_81 ) | V_89 ,
V_4 -> V_12 + V_80 ) ;
F_58 ( V_4 , V_174 , V_182 , F_56 ) ;
F_54 ( V_4 ) ;
F_4 ( V_184 , V_4 -> V_12 + V_80 ) ;
F_4 ( V_159 , V_4 -> V_12 + V_93 ) ;
if ( V_71 )
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
static int T_3 F_62 ( struct V_172 * V_181 , char * V_186 )
{
struct V_3 * V_4 = & V_163 [ V_181 -> V_183 ] ;
int V_46 = 9600 ;
int V_187 = 8 ;
int V_28 = 'n' ;
int V_188 = 'n' ;
if ( V_181 -> V_183 < 0 || V_181 -> V_183 >= V_164 )
return - V_140 ;
if ( ! V_4 -> V_12 ) {
F_63 ( L_3 V_189 L_4 ,
V_181 -> V_183 ) ;
return - V_179 ;
}
if ( V_186 )
F_64 ( V_186 , & V_46 , & V_28 , & V_187 , & V_188 ) ;
return F_65 ( V_4 , V_181 , V_46 , V_28 , V_187 , V_188 ) ;
}
static int T_3 F_66 ( void )
{
F_67 ( & V_190 ) ;
return 0 ;
}
static int F_68 ( struct V_177 * V_177 )
{
struct V_3 * V_4 = F_69 ( V_177 ) ;
struct V_191 * V_192 ;
struct V_177 * V_193 ;
int V_194 = 0 ;
V_192 = F_70 ( & V_4 -> V_34 -> V_4 ) ;
if ( V_192 ) {
V_193 = V_192 -> V_78 ;
V_194 = F_71 ( V_193 ) ;
F_72 ( V_192 ) ;
}
F_73 ( & V_195 , V_4 ) ;
if ( V_196 && ! V_194 ) {
struct V_60 * V_60 = V_4 -> V_61 ;
F_74 ( V_60 -> V_62 ) ;
F_74 ( V_60 -> V_197 ) ;
} else {
unsigned long V_5 = 0 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
while ( ! ( F_3 ( V_4 -> V_12 + V_15 ) &
V_16 ) )
F_3 ( V_4 -> V_12 + V_17 ) ;
F_4 ( 1 , V_4 -> V_12 + V_134 ) ;
F_4 ( V_23 ,
V_4 -> V_12 + V_37 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
return 0 ;
}
static int F_75 ( struct V_177 * V_177 )
{
struct V_3 * V_4 = F_69 ( V_177 ) ;
unsigned long V_5 = 0 ;
T_2 V_70 ;
struct V_191 * V_192 ;
struct V_177 * V_193 ;
int V_194 = 0 ;
V_192 = F_70 ( & V_4 -> V_34 -> V_4 ) ;
if ( V_192 ) {
V_193 = V_192 -> V_78 ;
V_194 = F_71 ( V_193 ) ;
F_72 ( V_192 ) ;
}
if ( V_196 && ! V_194 ) {
struct V_60 * V_60 = V_4 -> V_61 ;
F_76 ( V_60 -> V_197 ) ;
F_76 ( V_60 -> V_62 ) ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 |= V_85 | V_86 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
while ( F_3 ( V_4 -> V_12 + V_80 ) &
( V_85 | V_86 ) )
F_22 () ;
F_4 ( V_87 , V_4 -> V_12 + V_88 ) ;
V_70 = F_3 ( V_4 -> V_12 + V_80 ) ;
V_70 &= ~ ( V_81 | V_82 ) ;
V_70 |= V_89 | V_90 ;
F_4 ( V_70 , V_4 -> V_12 + V_80 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
} else {
F_2 ( & V_4 -> V_11 , V_5 ) ;
F_4 ( V_133 ,
V_4 -> V_12 + V_134 ) ;
F_4 ( V_23 ,
V_4 -> V_12 + V_93 ) ;
F_15 ( & V_4 -> V_11 , V_5 ) ;
}
return F_77 ( & V_195 , V_4 ) ;
}
static int F_78 ( struct V_198 * V_199 )
{
int V_200 , V_162 , V_1 ;
struct V_3 * V_4 ;
struct V_201 * V_202 ;
struct V_60 * V_203 ;
V_203 = F_79 ( & V_199 -> V_78 , sizeof( * V_203 ) ,
V_204 ) ;
if ( ! V_203 )
return - V_147 ;
V_203 -> V_197 = F_80 ( & V_199 -> V_78 , L_5 ) ;
if ( F_81 ( V_203 -> V_197 ) ) {
V_203 -> V_197 = F_80 ( & V_199 -> V_78 , L_6 ) ;
if ( ! F_81 ( V_203 -> V_197 ) )
F_43 ( & V_199 -> V_78 , L_7 ) ;
}
if ( F_81 ( V_203 -> V_197 ) ) {
F_43 ( & V_199 -> V_78 , L_8 ) ;
return F_82 ( V_203 -> V_197 ) ;
}
V_203 -> V_62 = F_80 ( & V_199 -> V_78 , L_9 ) ;
if ( F_81 ( V_203 -> V_62 ) ) {
V_203 -> V_62 = F_80 ( & V_199 -> V_78 , L_10 ) ;
if ( ! F_81 ( V_203 -> V_62 ) )
F_43 ( & V_199 -> V_78 , L_11 ) ;
}
if ( F_81 ( V_203 -> V_62 ) ) {
F_43 ( & V_199 -> V_78 , L_12 ) ;
return F_82 ( V_203 -> V_62 ) ;
}
V_200 = F_83 ( V_203 -> V_197 ) ;
if ( V_200 ) {
F_43 ( & V_199 -> V_78 , L_13 ) ;
return V_200 ;
}
V_200 = F_83 ( V_203 -> V_62 ) ;
if ( V_200 ) {
F_43 ( & V_199 -> V_78 , L_14 ) ;
goto V_205;
}
V_202 = F_84 ( V_199 , V_206 , 0 ) ;
if ( ! V_202 ) {
V_200 = - V_179 ;
goto V_207;
}
V_1 = F_85 ( V_199 , 0 ) ;
if ( V_1 <= 0 ) {
V_200 = - V_208 ;
goto V_207;
}
#ifdef F_86
V_203 -> V_209 . V_210 =
F_19 ;
if ( F_87 ( V_203 -> V_62 ,
& V_203 -> V_209 ) )
F_21 ( & V_199 -> V_78 , L_15 ) ;
#endif
V_162 = F_88 ( V_199 -> V_78 . V_211 , L_16 ) ;
if ( V_162 < 0 )
V_162 = 0 ;
V_4 = F_52 ( V_162 ) ;
if ( ! V_4 ) {
F_43 ( & V_199 -> V_78 , L_17 ) ;
V_200 = - V_179 ;
goto V_212;
} else {
V_4 -> V_145 = V_202 -> V_213 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_78 = & V_199 -> V_78 ;
V_4 -> V_62 = F_89 ( V_203 -> V_62 ) ;
V_4 -> V_61 = V_203 ;
V_203 -> V_4 = V_4 ;
F_90 ( V_199 , V_4 ) ;
V_200 = F_91 ( & V_195 , V_4 ) ;
if ( V_200 ) {
F_43 ( & V_199 -> V_78 ,
L_18 , V_200 ) ;
goto V_212;
}
return 0 ;
}
V_212:
#ifdef F_86
F_92 ( V_203 -> V_62 ,
& V_203 -> V_209 ) ;
#endif
V_207:
F_93 ( V_203 -> V_62 ) ;
V_205:
F_93 ( V_203 -> V_197 ) ;
return V_200 ;
}
static int F_94 ( struct V_198 * V_199 )
{
struct V_3 * V_4 = F_95 ( V_199 ) ;
struct V_60 * V_203 = V_4 -> V_61 ;
int V_200 ;
#ifdef F_86
F_92 ( V_203 -> V_62 ,
& V_203 -> V_209 ) ;
#endif
V_200 = F_96 ( & V_195 , V_4 ) ;
V_4 -> V_145 = 0 ;
F_93 ( V_203 -> V_62 ) ;
F_93 ( V_203 -> V_197 ) ;
return V_200 ;
}
static int T_3 F_97 ( void )
{
int V_130 = 0 ;
V_130 = F_98 ( & V_195 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_99 ( & V_214 ) ;
if ( V_130 )
F_100 ( & V_195 ) ;
return V_130 ;
}
static void T_4 F_101 ( void )
{
F_102 ( & V_214 ) ;
F_100 ( & V_195 ) ;
}
