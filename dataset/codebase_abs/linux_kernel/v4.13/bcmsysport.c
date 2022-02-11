static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 && V_3 >= V_5 )
V_3 += 4 ;
return F_2 ( V_2 -> V_6 + V_7 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_3 )
{
if ( V_2 -> V_4 && V_3 >= V_5 )
V_3 += 4 ;
F_4 ( V_8 , V_2 -> V_6 + V_7 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( ! V_2 -> V_4 ) {
return F_6 ( V_9 ) ;
} else {
if ( V_9 >= V_10 )
return F_6 ( V_9 + 1 ) ;
else
return F_6 ( V_9 ) ;
}
}
static inline void F_7 ( struct V_1 * V_2 ,
void T_2 * V_11 ,
T_3 V_12 )
{
#ifdef F_8
F_4 ( F_9 ( V_12 ) & V_13 ,
V_11 + V_14 ) ;
#endif
F_4 ( F_10 ( V_12 ) , V_11 + V_15 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
unsigned int V_18 )
{
F_12 ( V_2 , V_17 -> V_19 , F_13 ( V_18 ) ) ;
F_12 ( V_2 , V_17 -> V_20 , F_14 ( V_18 ) ) ;
}
static int F_15 ( struct V_21 * V_22 ,
T_4 V_23 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_2 -> V_25 = ! ! ( V_23 & V_26 ) ;
V_24 = F_17 ( V_2 , V_27 ) ;
if ( V_2 -> V_25 )
V_24 |= V_28 ;
else
V_24 &= ~ V_28 ;
if ( V_2 -> V_25 && V_2 -> V_29 )
V_24 |= V_30 ;
else
V_24 &= ~ V_30 ;
if ( F_18 ( V_22 ) )
V_24 |= V_31 ;
else
V_24 &= ~ V_31 ;
F_19 ( V_2 , V_24 , V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 ,
T_4 V_23 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_2 -> V_32 = ! ! ( V_23 & ( V_33 | V_34 ) ) ;
V_24 = F_21 ( V_2 , V_35 ) ;
if ( V_2 -> V_32 )
V_24 |= F_5 ( V_2 , V_36 ) ;
else
V_24 &= ~ F_5 ( V_2 , V_36 ) ;
F_12 ( V_2 , V_24 , V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 ,
T_4 V_37 )
{
T_4 V_38 = V_37 ^ V_22 -> V_37 ;
T_4 V_23 = V_22 -> V_39 ;
int V_40 = 0 ;
if ( V_38 & V_26 )
V_40 = F_15 ( V_22 , V_23 ) ;
if ( V_38 & ( V_33 | V_34 ) )
V_40 = F_20 ( V_22 , V_23 ) ;
return V_40 ;
}
static void F_23 ( struct V_21 * V_22 ,
struct V_41 * V_42 )
{
F_24 ( V_42 -> V_43 , V_44 , sizeof( V_42 -> V_43 ) ) ;
F_24 ( V_42 -> V_45 , L_1 , sizeof( V_42 -> V_45 ) ) ;
F_24 ( V_42 -> V_46 , L_2 , sizeof( V_42 -> V_46 ) ) ;
}
static T_1 F_25 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
return V_2 -> V_47 ;
}
static void F_26 ( struct V_21 * V_22 , T_1 V_48 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
V_2 -> V_47 = V_48 ;
}
static inline bool F_27 ( enum V_49 type )
{
switch ( type ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return true ;
default:
return false ;
}
}
static int F_28 ( struct V_21 * V_22 , int V_54 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
const struct V_55 * V_56 ;
unsigned int V_57 , V_58 ;
switch ( V_54 ) {
case V_59 :
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_60 ; V_57 ++ ) {
V_56 = & V_61 [ V_57 ] ;
if ( V_2 -> V_4 &&
! F_27 ( V_56 -> type ) )
continue;
V_58 ++ ;
}
return V_58 + V_22 -> V_62 * V_63 ;
default:
return - V_64 ;
}
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_65 , T_5 * V_66 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
const struct V_55 * V_56 ;
char V_67 [ 128 ] ;
int V_57 , V_58 ;
switch ( V_65 ) {
case V_59 :
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_60 ; V_57 ++ ) {
V_56 = & V_61 [ V_57 ] ;
if ( V_2 -> V_4 &&
! F_27 ( V_56 -> type ) )
continue;
memcpy ( V_66 + V_58 * V_68 , V_56 -> V_69 ,
V_68 ) ;
V_58 ++ ;
}
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ ) {
snprintf ( V_67 , sizeof( V_67 ) , L_3 , V_57 ) ;
memcpy ( V_66 + V_58 * V_68 , V_67 ,
V_68 ) ;
V_58 ++ ;
snprintf ( V_67 , sizeof( V_67 ) , L_4 , V_57 ) ;
memcpy ( V_66 + V_58 * V_68 , V_67 ,
V_68 ) ;
V_58 ++ ;
}
break;
default:
break;
}
}
static void F_30 ( struct V_1 * V_2 )
{
int V_57 , V_58 = 0 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
const struct V_55 * V_56 ;
T_5 V_70 = 0 ;
T_1 V_8 = 0 ;
char * V_71 ;
V_56 = & V_61 [ V_57 ] ;
switch ( V_56 -> type ) {
case V_50 :
case V_53 :
continue;
case V_72 :
case V_73 :
case V_74 :
if ( V_2 -> V_4 )
continue;
if ( V_56 -> type != V_72 )
V_70 = V_75 ;
V_8 = F_31 ( V_2 , V_76 + V_58 + V_70 ) ;
break;
case V_51 :
V_8 = F_17 ( V_2 , V_56 -> V_77 ) ;
if ( V_8 == ~ 0 )
F_19 ( V_2 , 0 , V_56 -> V_77 ) ;
break;
case V_52 :
V_8 = F_32 ( V_2 , V_56 -> V_77 ) ;
if ( V_8 == ~ 0 )
F_33 ( V_2 , 0 , V_56 -> V_77 ) ;
break;
}
V_58 += V_56 -> V_78 ;
V_71 = ( char * ) V_2 + V_56 -> V_79 ;
* ( T_1 * ) V_71 = V_8 ;
}
F_34 ( V_2 , V_80 , V_2 -> V_81 , L_5 ) ;
}
static void F_35 ( struct V_21 * V_22 ,
struct V_82 * V_83 , T_6 * V_66 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_84 * V_85 ;
int V_57 , V_58 ;
if ( F_36 ( V_22 ) )
F_30 ( V_2 ) ;
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_60 ; V_57 ++ ) {
const struct V_55 * V_56 ;
char * V_71 ;
V_56 = & V_61 [ V_57 ] ;
if ( V_56 -> type == V_50 )
V_71 = ( char * ) & V_22 -> V_83 ;
else
V_71 = ( char * ) V_2 ;
if ( V_2 -> V_4 && ! F_27 ( V_56 -> type ) )
continue;
V_71 += V_56 -> V_79 ;
V_66 [ V_58 ] = * ( unsigned long * ) V_71 ;
V_58 ++ ;
}
V_58 = F_28 ( V_22 , V_59 ) -
V_22 -> V_62 * V_63 ;
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ ) {
V_85 = & V_2 -> V_86 [ V_57 ] ;
V_66 [ V_58 ] = V_85 -> V_87 ;
V_58 ++ ;
V_66 [ V_58 ] = V_85 -> V_88 ;
V_58 ++ ;
}
}
static void F_37 ( struct V_21 * V_22 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_90 -> V_91 = V_92 | V_93 ;
V_90 -> V_94 = V_2 -> V_94 ;
if ( ! ( V_2 -> V_94 & V_93 ) )
return;
V_24 = F_31 ( V_2 , V_95 ) ;
F_38 ( V_24 , & V_90 -> V_96 [ 0 ] ) ;
V_24 = F_31 ( V_2 , V_97 ) ;
F_39 ( V_24 , & V_90 -> V_96 [ 2 ] ) ;
}
static int F_40 ( struct V_21 * V_22 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
T_1 V_91 = V_92 | V_93 ;
if ( ! F_41 ( V_99 ) )
return - V_101 ;
if ( V_90 -> V_94 & ~ V_91 )
return - V_102 ;
if ( V_90 -> V_94 & V_93 ) {
F_42 ( V_2 , F_43 ( & V_90 -> V_96 [ 0 ] ) ,
V_95 ) ;
F_42 ( V_2 , F_44 ( & V_90 -> V_96 [ 2 ] ) ,
V_97 ) ;
}
if ( V_90 -> V_94 ) {
F_45 ( V_99 , 1 ) ;
if ( V_2 -> V_103 )
F_46 ( V_2 -> V_104 ) ;
V_2 -> V_103 = 0 ;
} else {
F_45 ( V_99 , 0 ) ;
if ( ! V_2 -> V_103 )
F_47 ( V_2 -> V_104 ) ;
V_2 -> V_103 = 1 ;
}
V_2 -> V_94 = V_90 -> V_94 ;
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , F_49 ( 0 ) ) ;
V_106 -> V_107 = ( V_24 >> V_108 ) * 8192 / 1000 ;
V_106 -> V_109 = V_24 & V_110 ;
V_24 = F_1 ( V_2 , V_111 ) ;
V_106 -> V_112 = ( V_24 >> V_113 ) * 8192 / 1000 ;
V_106 -> V_114 = V_24 & V_115 ;
return 0 ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
T_1 V_24 ;
if ( V_106 -> V_109 > V_110 ||
V_106 -> V_107 > ( V_116 * 8 ) + 1 ||
V_106 -> V_114 > V_115 ||
V_106 -> V_112 > ( V_117 * 8 ) + 1 )
return - V_102 ;
if ( ( V_106 -> V_107 == 0 && V_106 -> V_109 == 0 ) ||
( V_106 -> V_112 == 0 && V_106 -> V_114 == 0 ) )
return - V_102 ;
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ ) {
V_24 = F_21 ( V_2 , F_49 ( V_57 ) ) ;
V_24 &= ~ ( V_110 |
V_116 << V_108 ) ;
V_24 |= V_106 -> V_109 ;
V_24 |= F_51 ( V_106 -> V_107 * 1000 , 8192 ) <<
V_108 ;
F_12 ( V_2 , V_24 , F_49 ( V_57 ) ) ;
}
V_24 = F_1 ( V_2 , V_111 ) ;
V_24 &= ~ ( V_115 |
V_117 << V_113 ) ;
V_24 |= V_106 -> V_114 ;
V_24 |= F_51 ( V_106 -> V_112 * 1000 , 8192 ) <<
V_113 ;
F_3 ( V_2 , V_24 , V_111 ) ;
return 0 ;
}
static void F_52 ( struct V_118 * V_119 )
{
F_53 ( V_119 -> V_120 ) ;
V_119 -> V_120 = NULL ;
F_54 ( V_119 , V_121 , 0 ) ;
}
static struct V_122 * F_55 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
struct V_21 * V_123 = V_2 -> V_81 ;
struct V_122 * V_120 , * V_124 ;
T_3 V_125 ;
V_120 = F_56 ( V_2 -> V_81 , V_126 ) ;
if ( ! V_120 ) {
V_2 -> V_127 . V_128 ++ ;
F_57 ( V_2 , V_129 , V_123 , L_6 ) ;
return NULL ;
}
V_125 = F_58 ( V_99 , V_120 -> V_66 ,
V_126 , V_130 ) ;
if ( F_59 ( V_99 , V_125 ) ) {
V_2 -> V_127 . V_131 ++ ;
F_60 ( V_120 ) ;
F_57 ( V_2 , V_129 , V_123 , L_7 ) ;
return NULL ;
}
V_124 = V_119 -> V_120 ;
if ( F_61 ( V_124 ) )
F_62 ( V_99 , F_63 ( V_119 , V_121 ) ,
V_126 , V_130 ) ;
V_119 -> V_120 = V_120 ;
F_54 ( V_119 , V_121 , V_125 ) ;
F_7 ( V_2 , V_119 -> V_132 , V_125 ) ;
F_34 ( V_2 , V_133 , V_123 , L_8 ) ;
return V_124 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
struct V_122 * V_120 ;
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_134 ; V_57 ++ ) {
V_119 = & V_2 -> V_135 [ V_57 ] ;
V_120 = F_55 ( V_2 , V_119 ) ;
if ( V_120 )
F_65 ( V_120 ) ;
if ( ! V_119 -> V_120 )
return - V_136 ;
}
return 0 ;
}
static unsigned int F_66 ( struct V_1 * V_2 ,
unsigned int V_137 )
{
struct V_21 * V_123 = V_2 -> V_81 ;
unsigned int V_138 = 0 , V_139 ;
struct V_118 * V_119 ;
struct V_122 * V_120 ;
unsigned int V_140 ;
T_7 V_141 , V_142 ;
struct V_143 * V_144 ;
F_67 ( V_2 , V_145 , V_146 ) ;
if ( ! V_2 -> V_4 )
V_140 = F_1 ( V_2 , V_147 ) ;
else
V_140 = F_1 ( V_2 , V_148 ) ;
V_140 &= V_149 ;
V_139 = ( V_140 - V_2 -> V_150 ) & V_151 ;
F_34 ( V_2 , V_133 , V_123 ,
L_9 ,
V_140 , V_2 -> V_150 , V_139 ) ;
while ( ( V_138 < V_139 ) && ( V_138 < V_137 ) ) {
V_119 = & V_2 -> V_135 [ V_2 -> V_152 ] ;
V_120 = F_55 ( V_2 , V_119 ) ;
if ( F_68 ( ! V_120 ) ) {
F_57 ( V_2 , V_129 , V_123 , L_10 ) ;
V_123 -> V_83 . V_153 ++ ;
V_123 -> V_83 . V_154 ++ ;
goto V_155;
}
V_144 = (struct V_143 * ) V_120 -> V_66 ;
V_141 = ( V_144 -> V_156 >> V_157 ) & V_158 ;
V_142 = ( V_144 -> V_156 >> V_159 ) &
V_160 ;
F_34 ( V_2 , V_133 , V_123 ,
L_11 ,
V_140 , V_2 -> V_150 , V_2 -> V_152 ,
V_141 , V_142 ) ;
if ( F_68 ( V_141 > V_126 ) ) {
F_57 ( V_2 , V_133 , V_123 , L_12 ) ;
V_123 -> V_83 . V_161 ++ ;
V_123 -> V_83 . V_154 ++ ;
F_60 ( V_120 ) ;
goto V_155;
}
if ( F_68 ( ! ( V_142 & V_162 ) || ! ( V_142 & V_163 ) ) ) {
F_57 ( V_2 , V_133 , V_123 , L_13 ) ;
V_123 -> V_83 . V_153 ++ ;
V_123 -> V_83 . V_154 ++ ;
F_60 ( V_120 ) ;
goto V_155;
}
if ( F_68 ( V_142 & ( V_164 | V_165 ) ) ) {
F_57 ( V_2 , V_129 , V_123 , L_14 ) ;
if ( V_142 & V_165 )
V_123 -> V_83 . V_166 ++ ;
V_123 -> V_83 . V_153 ++ ;
V_123 -> V_83 . V_154 ++ ;
F_60 ( V_120 ) ;
goto V_155;
}
F_69 ( V_120 , V_141 ) ;
if ( F_61 ( V_142 & V_167 ) )
V_120 -> V_168 = V_169 ;
F_70 ( V_120 , sizeof( * V_144 ) + 2 ) ;
V_141 -= ( sizeof( * V_144 ) + 2 ) ;
if ( V_2 -> V_29 ) {
F_71 ( V_120 , V_141 - V_170 ) ;
V_141 -= V_170 ;
}
V_120 -> V_171 = F_72 ( V_120 , V_123 ) ;
V_123 -> V_83 . V_172 ++ ;
V_123 -> V_83 . V_173 += V_141 ;
F_73 ( & V_2 -> V_174 , V_120 ) ;
V_155:
V_138 ++ ;
V_2 -> V_152 ++ ;
if ( V_2 -> V_152 == V_2 -> V_134 )
V_2 -> V_152 = 0 ;
}
return V_138 ;
}
static void F_74 ( struct V_84 * V_85 ,
struct V_118 * V_119 ,
unsigned int * V_175 ,
unsigned int * V_176 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
if ( V_119 -> V_120 ) {
V_85 -> V_88 += V_119 -> V_120 -> V_141 ;
* V_175 += V_119 -> V_120 -> V_141 ;
F_62 ( V_99 , F_63 ( V_119 , V_121 ) ,
F_75 ( V_119 , V_177 ) ,
V_178 ) ;
V_85 -> V_87 ++ ;
( * V_176 ) ++ ;
F_52 ( V_119 ) ;
} else if ( F_63 ( V_119 , V_121 ) ) {
V_85 -> V_88 += F_75 ( V_119 , V_177 ) ;
F_76 ( V_99 , F_63 ( V_119 , V_121 ) ,
F_75 ( V_119 , V_177 ) , V_178 ) ;
F_54 ( V_119 , V_121 , 0 ) ;
}
}
static unsigned int F_77 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_21 * V_123 = V_2 -> V_81 ;
unsigned int V_179 , V_180 , V_181 , V_182 ;
unsigned int V_176 = 0 , V_175 = 0 ;
struct V_118 * V_119 ;
T_1 V_183 ;
if ( ! V_85 -> V_2 -> V_4 )
F_78 ( V_85 -> V_2 , F_6 ( V_85 -> V_184 ) , V_146 ) ;
else
F_67 ( V_85 -> V_2 , F_6 ( V_85 -> V_184 +
V_185 ) , V_146 ) ;
V_183 = F_21 ( V_2 , F_79 ( V_85 -> V_184 ) ) ;
V_179 = ( V_183 >> V_186 ) & V_187 ;
V_85 -> V_140 = ( V_183 & V_188 ) ;
V_180 = V_85 -> V_179 ;
V_182 = V_85 -> V_189 ;
V_179 &= ( V_182 - 1 ) ;
if ( V_179 >= V_180 )
V_181 = V_179 - V_180 ;
else
V_181 = V_182 - V_180 + V_179 ;
F_34 ( V_2 , V_190 , V_123 ,
L_15 ,
V_85 -> V_184 , V_179 , V_181 , V_180 ) ;
while ( V_181 -- > 0 ) {
V_119 = V_85 -> V_191 + V_180 ;
F_74 ( V_85 , V_119 , & V_175 , & V_176 ) ;
V_85 -> V_192 ++ ;
V_180 ++ ;
V_180 &= ( V_182 - 1 ) ;
}
V_85 -> V_179 = V_179 ;
F_34 ( V_2 , V_190 , V_123 ,
L_16 ,
V_85 -> V_184 , V_85 -> V_179 , V_176 , V_175 ) ;
return V_176 ;
}
static unsigned int F_80 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_193 * V_194 ;
unsigned int V_195 ;
unsigned long V_196 ;
V_194 = F_81 ( V_2 -> V_81 , V_85 -> V_184 ) ;
F_82 ( & V_85 -> V_197 , V_196 ) ;
V_195 = F_77 ( V_2 , V_85 ) ;
if ( V_195 )
F_83 ( V_194 ) ;
F_84 ( & V_85 -> V_197 , V_196 ) ;
return V_195 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
unsigned long V_196 ;
F_82 ( & V_85 -> V_197 , V_196 ) ;
F_77 ( V_2 , V_85 ) ;
F_84 ( & V_85 -> V_197 , V_196 ) ;
}
static int F_86 ( struct V_198 * V_174 , int V_137 )
{
struct V_84 * V_85 =
F_87 ( V_174 , struct V_84 , V_174 ) ;
unsigned int V_199 = 0 ;
V_199 = F_80 ( V_85 -> V_2 , V_85 ) ;
if ( V_199 == 0 ) {
F_88 ( V_174 ) ;
if ( ! V_85 -> V_2 -> V_4 )
F_89 ( V_85 -> V_2 , F_6 ( V_85 -> V_184 ) ) ;
else
F_90 ( V_85 -> V_2 , F_6 ( V_85 -> V_184 +
V_185 ) ) ;
return 0 ;
}
return V_137 ;
}
static void F_91 ( struct V_1 * V_2 )
{
unsigned int V_200 ;
for ( V_200 = 0 ; V_200 < V_2 -> V_81 -> V_62 ; V_200 ++ )
F_80 ( V_2 , & V_2 -> V_86 [ V_200 ] ) ;
}
static int F_92 ( struct V_198 * V_174 , int V_137 )
{
struct V_1 * V_2 =
F_87 ( V_174 , struct V_1 , V_174 ) ;
unsigned int V_199 = 0 ;
V_199 = F_66 ( V_2 , V_137 ) ;
V_2 -> V_150 += V_199 ;
V_2 -> V_150 &= V_151 ;
if ( ! V_2 -> V_4 )
F_3 ( V_2 , V_2 -> V_150 , V_148 ) ;
else
F_3 ( V_2 , V_2 -> V_150 << 16 , V_148 ) ;
if ( V_199 < V_137 ) {
F_93 ( V_174 , V_199 ) ;
F_90 ( V_2 , V_145 ) ;
}
return V_199 ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_95 ( V_2 , V_201 ) ;
V_24 = F_31 ( V_2 , V_202 ) ;
V_24 &= ~ V_203 ;
F_42 ( V_2 , V_24 , V_202 ) ;
F_34 ( V_2 , V_90 , V_2 -> V_81 , L_17 ) ;
}
static T_8 F_96 ( int V_204 , void * V_205 )
{
struct V_21 * V_22 = V_205 ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_84 * V_206 ;
unsigned int V_85 , V_207 ;
V_2 -> V_208 = F_97 ( V_2 , V_209 ) &
~ F_97 ( V_2 , V_210 ) ;
F_67 ( V_2 , V_2 -> V_208 , V_146 ) ;
if ( F_68 ( V_2 -> V_208 == 0 ) ) {
F_98 ( V_2 -> V_81 , L_18 ) ;
return V_211 ;
}
if ( V_2 -> V_208 & V_145 ) {
if ( F_61 ( F_99 ( & V_2 -> V_174 ) ) ) {
F_95 ( V_2 , V_145 ) ;
F_100 ( & V_2 -> V_174 ) ;
}
}
if ( V_2 -> V_208 & V_212 )
F_91 ( V_2 ) ;
if ( V_2 -> V_208 & V_201 ) {
F_101 ( V_2 -> V_81 , L_19 ) ;
F_94 ( V_2 ) ;
}
if ( ! V_2 -> V_4 )
goto V_213;
for ( V_85 = 0 ; V_85 < V_22 -> V_62 ; V_85 ++ ) {
V_207 = F_6 ( V_85 + V_185 ) ;
if ( ! ( V_2 -> V_208 & V_207 ) )
continue;
V_206 = & V_2 -> V_86 [ V_85 ] ;
if ( F_61 ( F_99 ( & V_206 -> V_174 ) ) ) {
F_95 ( V_2 , V_207 ) ;
F_102 ( & V_206 -> V_174 ) ;
}
}
V_213:
return V_214 ;
}
static T_8 F_103 ( int V_204 , void * V_205 )
{
struct V_21 * V_22 = V_205 ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_84 * V_206 ;
unsigned int V_85 ;
V_2 -> V_215 = F_104 ( V_2 , V_209 ) &
~ F_104 ( V_2 , V_210 ) ;
F_78 ( V_2 , 0xffffffff , V_146 ) ;
if ( F_68 ( V_2 -> V_215 == 0 ) ) {
F_98 ( V_2 -> V_81 , L_20 ) ;
return V_211 ;
}
for ( V_85 = 0 ; V_85 < V_22 -> V_62 ; V_85 ++ ) {
if ( ! ( V_2 -> V_215 & F_6 ( V_85 ) ) )
continue;
V_206 = & V_2 -> V_86 [ V_85 ] ;
if ( F_61 ( F_99 ( & V_206 -> V_174 ) ) ) {
F_105 ( V_2 , F_6 ( V_85 ) ) ;
F_100 ( & V_206 -> V_174 ) ;
}
}
return V_214 ;
}
static T_8 F_106 ( int V_204 , void * V_205 )
{
struct V_1 * V_2 = V_205 ;
F_107 ( & V_2 -> V_100 -> V_22 , 0 ) ;
return V_214 ;
}
static void F_108 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_109 ( V_2 -> V_216 ) ;
F_96 ( V_2 -> V_216 , V_2 ) ;
F_110 ( V_2 -> V_216 ) ;
if ( ! V_2 -> V_4 ) {
F_109 ( V_2 -> V_217 ) ;
F_103 ( V_2 -> V_217 , V_2 ) ;
F_110 ( V_2 -> V_217 ) ;
}
}
static struct V_122 * F_111 ( struct V_122 * V_120 ,
struct V_21 * V_22 )
{
struct V_122 * V_218 ;
struct V_219 * V_220 ;
T_1 V_221 ;
T_5 V_222 ;
T_7 V_223 ;
T_7 V_224 ;
if ( F_68 ( F_112 ( V_120 ) < sizeof( * V_220 ) ) ) {
V_218 = F_113 ( V_120 , sizeof( * V_220 ) ) ;
F_65 ( V_120 ) ;
if ( ! V_218 ) {
V_22 -> V_83 . V_225 ++ ;
V_22 -> V_83 . V_226 ++ ;
return NULL ;
}
V_120 = V_218 ;
}
V_220 = F_114 ( V_120 , sizeof( * V_220 ) ) ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
if ( V_120 -> V_168 == V_227 ) {
V_224 = F_115 ( V_120 -> V_171 ) ;
switch ( V_224 ) {
case V_228 :
V_222 = F_116 ( V_120 ) -> V_171 ;
break;
case V_229 :
V_222 = F_117 ( V_120 ) -> V_230 ;
break;
default:
return V_120 ;
}
V_223 = F_118 ( V_120 ) - sizeof( * V_220 ) ;
V_221 = ( V_223 + V_120 -> V_231 ) & V_232 ;
V_221 |= ( V_223 << V_233 ) ;
if ( V_222 == V_234 || V_222 == V_235 ) {
V_221 |= V_236 ;
if ( V_222 == V_235 && V_224 == V_228 )
V_221 |= V_237 ;
} else {
V_221 = 0 ;
}
V_220 -> V_238 = V_221 ;
}
return V_120 ;
}
static T_9 F_119 ( struct V_122 * V_120 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
struct V_84 * V_85 ;
struct V_118 * V_119 ;
struct V_193 * V_194 ;
struct V_16 * V_17 ;
unsigned int V_239 ;
unsigned long V_196 ;
T_3 V_125 ;
T_1 V_240 ;
T_7 V_241 ;
int V_40 ;
V_241 = F_120 ( V_120 ) ;
V_194 = F_81 ( V_22 , V_241 ) ;
V_85 = & V_2 -> V_86 [ V_241 ] ;
F_82 ( & V_85 -> V_197 , V_196 ) ;
if ( F_68 ( V_85 -> V_192 == 0 ) ) {
F_121 ( V_194 ) ;
F_122 ( V_22 , L_21 , V_241 ) ;
V_40 = V_242 ;
goto V_213;
}
if ( F_123 ( V_120 , V_243 + V_244 ) ) {
V_40 = V_245 ;
goto V_213;
}
if ( V_2 -> V_32 ) {
V_120 = F_111 ( V_120 , V_22 ) ;
if ( ! V_120 ) {
V_40 = V_245 ;
goto V_213;
}
}
V_239 = V_120 -> V_141 ;
V_125 = F_58 ( V_99 , V_120 -> V_66 , V_239 , V_178 ) ;
if ( F_59 ( V_99 , V_125 ) ) {
V_2 -> V_127 . V_246 ++ ;
F_57 ( V_2 , V_247 , V_22 , L_22 ,
V_120 -> V_66 , V_239 ) ;
V_40 = V_245 ;
goto V_213;
}
V_119 = & V_85 -> V_191 [ V_85 -> V_248 ] ;
V_119 -> V_120 = V_120 ;
F_54 ( V_119 , V_121 , V_125 ) ;
F_124 ( V_119 , V_177 , V_239 ) ;
V_17 = V_85 -> V_249 ;
V_17 -> V_20 = F_10 ( V_125 ) ;
V_240 = F_9 ( V_125 ) & V_13 ;
V_240 |= ( V_239 << V_157 ) ;
V_240 |= ( V_163 | V_162 | V_250 ) <<
V_159 ;
if ( V_120 -> V_168 == V_227 )
V_240 |= ( V_167 << V_159 ) ;
V_85 -> V_248 ++ ;
if ( V_85 -> V_248 == V_85 -> V_189 )
V_85 -> V_248 = 0 ;
V_85 -> V_192 -- ;
F_125 () ;
V_17 -> V_19 = V_240 ;
F_125 () ;
F_11 ( V_2 , V_17 , V_85 -> V_184 ) ;
if ( V_85 -> V_192 == 0 )
F_121 ( V_194 ) ;
F_34 ( V_2 , V_251 , V_22 , L_23 ,
V_85 -> V_184 , V_85 -> V_192 , V_85 -> V_248 ) ;
V_40 = V_245 ;
V_213:
F_84 ( & V_85 -> V_197 , V_196 ) ;
return V_40 ;
}
static void F_126 ( struct V_21 * V_22 )
{
F_98 ( V_22 , L_24 ) ;
F_127 ( V_22 ) ;
V_22 -> V_83 . V_225 ++ ;
F_128 ( V_22 ) ;
}
static void F_129 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_252 * V_253 = V_22 -> V_253 ;
unsigned int V_38 = 0 ;
T_1 V_254 = 0 , V_24 ;
if ( V_2 -> V_255 != V_253 -> V_256 ) {
V_38 = 1 ;
V_2 -> V_255 = V_253 -> V_256 ;
}
if ( V_2 -> V_257 != V_253 -> V_258 ) {
V_38 = 1 ;
V_2 -> V_257 = V_253 -> V_258 ;
}
if ( V_2 -> V_4 )
goto V_213;
switch ( V_253 -> V_259 ) {
case V_260 :
V_254 = V_261 ;
break;
case V_262 :
V_254 = V_263 ;
break;
case V_264 :
V_254 = V_265 ;
break;
case V_266 :
V_254 = V_267 ;
break;
default:
break;
}
V_254 <<= V_268 ;
if ( V_253 -> V_258 == V_269 )
V_254 |= V_270 ;
if ( V_2 -> V_271 != V_253 -> V_272 ) {
V_38 = 1 ;
V_2 -> V_271 = V_253 -> V_272 ;
}
if ( ! V_253 -> V_272 )
V_254 |= V_273 | V_274 ;
if ( ! V_38 )
return;
if ( V_253 -> V_256 ) {
V_24 = F_31 ( V_2 , V_275 ) ;
V_24 &= ~ ( ( V_276 << V_268 ) |
V_270 | V_273 |
V_274 ) ;
V_24 |= V_254 ;
F_42 ( V_2 , V_24 , V_275 ) ;
}
V_213:
if ( V_38 )
F_130 ( V_253 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
unsigned int V_184 )
{
struct V_84 * V_85 = & V_2 -> V_86 [ V_184 ] ;
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
T_10 V_189 ;
void * V_71 ;
T_1 V_24 ;
V_189 = 256 ;
V_71 = F_132 ( V_99 , sizeof( struct V_16 ) , & V_85 -> V_277 ,
V_278 ) ;
if ( ! V_71 ) {
F_57 ( V_2 , V_80 , V_2 -> V_81 , L_25 ) ;
return - V_136 ;
}
V_85 -> V_191 = F_133 ( V_189 , sizeof( struct V_118 ) , V_278 ) ;
if ( ! V_85 -> V_191 ) {
F_134 ( V_99 , sizeof( struct V_16 ) ,
V_85 -> V_249 , V_85 -> V_277 ) ;
F_57 ( V_2 , V_80 , V_2 -> V_81 , L_26 ) ;
return - V_136 ;
}
F_135 ( & V_85 -> V_197 ) ;
V_85 -> V_2 = V_2 ;
F_136 ( V_2 -> V_81 , & V_85 -> V_174 , F_86 , 64 ) ;
V_85 -> V_184 = V_184 ;
V_85 -> V_189 = V_189 ;
V_85 -> V_279 = V_85 -> V_189 ;
V_85 -> V_249 = V_71 ;
V_85 -> V_192 = V_85 -> V_189 ;
V_85 -> V_248 = 0 ;
F_12 ( V_2 , V_280 , F_137 ( V_184 ) ) ;
F_12 ( V_2 , 0 , F_138 ( V_184 ) ) ;
F_12 ( V_2 , 1 , F_49 ( V_184 ) ) ;
F_12 ( V_2 , 0 , F_79 ( V_184 ) ) ;
F_12 ( V_2 , V_281 , F_139 ( V_184 ) ) ;
F_12 ( V_2 , 0 , F_140 ( V_184 ) ) ;
F_12 ( V_2 , V_85 -> V_189 |
1 << V_282 ,
F_141 ( V_184 ) ) ;
V_24 = F_21 ( V_2 , V_283 ) ;
V_24 |= ( 1 << V_184 ) ;
F_12 ( V_2 , V_24 , V_283 ) ;
F_142 ( & V_85 -> V_174 ) ;
F_34 ( V_2 , V_80 , V_2 -> V_81 ,
L_27 ,
V_85 -> V_189 , V_85 -> V_249 ) ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 ,
unsigned int V_184 )
{
struct V_84 * V_85 = & V_2 -> V_86 [ V_184 ] ;
struct V_98 * V_99 = & V_2 -> V_100 -> V_22 ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , V_284 ) ;
if ( ! ( V_24 & V_285 ) )
F_98 ( V_2 -> V_81 , L_28 ) ;
if ( ! V_85 -> V_191 )
return;
F_144 ( & V_85 -> V_174 ) ;
F_145 ( & V_85 -> V_174 ) ;
F_85 ( V_2 , V_85 ) ;
F_146 ( V_85 -> V_191 ) ;
V_85 -> V_191 = NULL ;
if ( V_85 -> V_277 ) {
F_134 ( V_99 , sizeof( struct V_16 ) ,
V_85 -> V_249 , V_85 -> V_277 ) ;
V_85 -> V_277 = 0 ;
}
V_85 -> V_189 = 0 ;
V_85 -> V_279 = 0 ;
F_34 ( V_2 , V_80 , V_2 -> V_81 , L_29 ) ;
}
static inline int F_147 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
unsigned int V_286 = 1000 ;
T_1 V_24 ;
V_24 = F_1 ( V_2 , V_287 ) ;
if ( V_48 )
V_24 |= V_288 ;
else
V_24 &= ~ V_288 ;
F_3 ( V_2 , V_24 , V_287 ) ;
do {
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ! ( V_24 & V_289 ) == ! V_48 )
return 0 ;
F_148 ( 1000 , 2000 ) ;
} while ( V_286 -- > 0 );
F_122 ( V_2 -> V_81 , L_30 ) ;
return - V_290 ;
}
static inline int F_149 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
unsigned int V_286 = 1000 ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , V_35 ) ;
if ( V_48 )
V_24 |= F_5 ( V_2 , V_291 ) ;
else
V_24 &= ~ F_5 ( V_2 , V_291 ) ;
F_12 ( V_2 , V_24 , V_35 ) ;
do {
V_24 = F_21 ( V_2 , V_284 ) ;
if ( ! ! ( V_24 & V_285 ) == ! V_48 )
return 0 ;
F_148 ( 1000 , 2000 ) ;
} while ( V_286 -- > 0 );
F_122 ( V_2 -> V_81 , L_31 ) ;
return - V_290 ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
T_1 V_24 ;
int V_40 ;
int V_57 ;
V_2 -> V_134 = V_2 -> V_292 / V_293 ;
V_2 -> V_294 = V_2 -> V_6 + V_7 ;
V_2 -> V_150 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_135 = F_133 ( V_2 -> V_134 , sizeof( struct V_118 ) ,
V_278 ) ;
if ( ! V_2 -> V_135 ) {
F_57 ( V_2 , V_80 , V_2 -> V_81 , L_26 ) ;
return - V_136 ;
}
for ( V_57 = 0 ; V_57 < V_2 -> V_134 ; V_57 ++ ) {
V_119 = V_2 -> V_135 + V_57 ;
V_119 -> V_132 = V_2 -> V_294 + V_57 * V_295 ;
}
V_40 = F_64 ( V_2 ) ;
if ( V_40 ) {
F_57 ( V_2 , V_80 , V_2 -> V_81 , L_32 ) ;
return V_40 ;
}
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ( V_24 & V_289 ) )
F_147 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 , V_296 ) ;
F_3 ( V_2 , 0 , V_297 ) ;
F_3 ( V_2 , 0 , V_147 ) ;
F_3 ( V_2 , 0 , V_148 ) ;
F_3 ( V_2 , V_2 -> V_134 << V_298 |
V_126 , V_299 ) ;
F_3 ( V_2 , 0 , V_300 ) ;
F_3 ( V_2 , 0 , V_301 ) ;
F_3 ( V_2 , 0 , V_302 ) ;
F_3 ( V_2 , V_2 -> V_292 - 1 , V_303 ) ;
F_3 ( V_2 , 1 , V_111 ) ;
F_34 ( V_2 , V_80 , V_2 -> V_81 ,
L_33 ,
V_2 -> V_134 , V_2 -> V_294 ) ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
unsigned int V_57 ;
T_1 V_24 ;
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ( V_24 & V_289 ) )
F_98 ( V_2 -> V_81 , L_34 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_134 ; V_57 ++ ) {
V_119 = & V_2 -> V_135 [ V_57 ] ;
if ( F_63 ( V_119 , V_121 ) )
F_62 ( & V_2 -> V_100 -> V_22 ,
F_63 ( V_119 , V_121 ) ,
V_126 , V_130 ) ;
F_52 ( V_119 ) ;
}
F_146 ( V_2 -> V_135 ) ;
V_2 -> V_135 = NULL ;
F_34 ( V_2 , V_80 , V_2 -> V_81 , L_35 ) ;
}
static void F_152 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
if ( V_2 -> V_4 )
return;
V_24 = F_31 ( V_2 , V_275 ) ;
if ( V_22 -> V_196 & V_304 )
V_24 |= V_305 ;
else
V_24 &= ~ V_305 ;
F_42 ( V_2 , V_24 , V_275 ) ;
if ( V_22 -> V_196 & V_306 )
return;
}
static inline void F_153 ( struct V_1 * V_2 ,
T_1 V_307 , unsigned int V_48 )
{
T_1 V_24 ;
if ( ! V_2 -> V_4 ) {
V_24 = F_31 ( V_2 , V_275 ) ;
if ( V_48 )
V_24 |= V_307 ;
else
V_24 &= ~ V_307 ;
F_42 ( V_2 , V_24 , V_275 ) ;
} else {
V_24 = F_154 ( V_2 , V_308 ) ;
if ( V_48 )
V_24 |= V_307 ;
else
V_24 &= ~ V_307 ;
F_155 ( V_2 , V_24 , V_308 ) ;
}
if ( V_48 == 0 )
F_148 ( 1000 , 2000 ) ;
}
static inline void F_156 ( struct V_1 * V_2 )
{
T_1 V_24 ;
if ( V_2 -> V_4 )
return;
V_24 = F_31 ( V_2 , V_275 ) ;
V_24 |= V_309 ;
F_42 ( V_2 , V_24 , V_275 ) ;
F_157 ( 10 ) ;
V_24 = F_31 ( V_2 , V_275 ) ;
V_24 &= ~ V_309 ;
F_42 ( V_2 , V_24 , V_275 ) ;
}
static void F_158 ( struct V_1 * V_2 ,
unsigned char * V_12 )
{
T_1 V_310 = ( V_12 [ 0 ] << 24 ) | ( V_12 [ 1 ] << 16 ) | ( V_12 [ 2 ] << 8 ) |
V_12 [ 3 ] ;
T_1 V_311 = ( V_12 [ 4 ] << 8 ) | V_12 [ 5 ] ;
if ( ! V_2 -> V_4 ) {
F_42 ( V_2 , V_310 , V_312 ) ;
F_42 ( V_2 , V_311 , V_313 ) ;
} else {
F_155 ( V_2 , V_310 , V_314 ) ;
F_155 ( V_2 , V_311 , V_315 ) ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
F_160 ( V_2 , V_316 , V_317 ) ;
F_160 ( V_2 , V_318 , V_319 ) ;
F_161 ( 1 ) ;
F_160 ( V_2 , 0 , V_317 ) ;
F_160 ( V_2 , 0 , V_319 ) ;
}
static int F_162 ( struct V_21 * V_22 , void * V_71 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_320 * V_12 = V_71 ;
if ( ! F_163 ( V_12 -> V_321 ) )
return - V_102 ;
memcpy ( V_22 -> V_322 , V_12 -> V_321 , V_22 -> V_323 ) ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_158 ( V_2 , V_22 -> V_322 ) ;
return 0 ;
}
static struct V_324 * F_164 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned long V_325 = 0 , V_326 = 0 ;
struct V_84 * V_85 ;
unsigned int V_200 ;
for ( V_200 = 0 ; V_200 < V_22 -> V_62 ; V_200 ++ ) {
V_85 = & V_2 -> V_86 [ V_200 ] ;
V_325 += V_85 -> V_88 ;
V_326 += V_85 -> V_87 ;
}
V_22 -> V_83 . V_325 = V_325 ;
V_22 -> V_83 . V_326 = V_326 ;
return & V_22 -> V_83 ;
}
static void F_165 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_142 ( & V_2 -> V_174 ) ;
F_90 ( V_2 , V_145 | V_212 ) ;
F_166 ( V_22 -> V_253 ) ;
if ( ! V_2 -> V_4 )
F_89 ( V_2 , 0xffffffff ) ;
else
F_90 ( V_2 , V_327 ) ;
F_167 ( V_22 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
T_1 V_24 ;
V_24 = F_32 ( V_2 , V_328 ) ;
V_24 |= V_329 | V_330 ;
if ( V_2 -> V_4 ) {
V_24 &= ~ V_331 ;
V_24 |= V_332 ;
}
F_33 ( V_2 , V_24 , V_328 ) ;
}
static inline void F_169 ( struct V_1 * V_2 )
{
F_95 ( V_2 , 0xffffffff ) ;
F_67 ( V_2 , 0xffffffff , V_146 ) ;
if ( ! V_2 -> V_4 ) {
F_105 ( V_2 , 0xffffffff ) ;
F_78 ( V_2 , 0xffffffff , V_146 ) ;
}
}
static inline void F_170 ( struct V_1 * V_2 )
{
T_1 T_11 V_24 ;
if ( F_18 ( V_2 -> V_81 ) ) {
V_24 = F_154 ( V_2 , V_308 ) ;
V_24 &= ~ ( V_333 << V_334 ) ;
V_24 |= V_244 << V_334 ;
F_155 ( V_2 , V_24 , V_308 ) ;
}
}
static int F_171 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_252 * V_253 ;
unsigned int V_57 ;
int V_40 ;
F_156 ( V_2 ) ;
F_159 ( V_2 ) ;
F_153 ( V_2 , V_335 | V_336 , 0 ) ;
F_168 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_42 ( V_2 , V_337 , V_338 ) ;
else
F_170 ( V_2 ) ;
F_158 ( V_2 , V_22 -> V_322 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_29 = ! ! ( F_31 ( V_2 , V_275 ) & V_339 ) ;
else
V_2 -> V_29 = ! ! ( F_154 ( V_2 , V_308 ) &
V_340 ) ;
V_253 = F_172 ( V_22 , V_2 -> V_341 , F_129 ,
0 , V_2 -> V_342 ) ;
if ( ! V_253 ) {
F_122 ( V_22 , L_36 ) ;
return - V_343 ;
}
V_2 -> V_257 = - 1 ;
V_2 -> V_255 = - 1 ;
V_2 -> V_271 = - 1 ;
F_169 ( V_2 ) ;
V_40 = F_173 ( V_2 -> V_216 , F_96 , 0 , V_22 -> V_344 , V_22 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_37 ) ;
goto V_345;
}
if ( ! V_2 -> V_4 ) {
V_40 = F_173 ( V_2 -> V_217 , F_103 , 0 ,
V_22 -> V_344 , V_22 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_38 ) ;
goto V_346;
}
}
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ ) {
V_40 = F_131 ( V_2 , V_57 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_39 ,
V_57 ) ;
goto V_347;
}
}
F_12 ( V_2 , V_348 , V_284 ) ;
V_40 = F_150 ( V_2 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_40 ) ;
goto V_349;
}
V_40 = F_147 ( V_2 , 1 ) ;
if ( V_40 )
goto V_349;
V_40 = F_149 ( V_2 , 1 ) ;
if ( V_40 )
goto V_350;
F_153 ( V_2 , V_335 | V_336 , 1 ) ;
F_165 ( V_22 ) ;
return 0 ;
V_350:
F_95 ( V_2 , V_145 | V_212 ) ;
V_349:
F_151 ( V_2 ) ;
V_347:
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ )
F_143 ( V_2 , V_57 ) ;
if ( ! V_2 -> V_4 )
F_174 ( V_2 -> V_217 , V_22 ) ;
V_346:
F_174 ( V_2 -> V_216 , V_22 ) ;
V_345:
F_175 ( V_253 ) ;
return V_40 ;
}
static void F_176 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_177 ( V_22 ) ;
F_144 ( & V_2 -> V_174 ) ;
F_178 ( V_22 -> V_253 ) ;
F_169 ( V_2 ) ;
}
static int F_179 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
int V_40 ;
F_176 ( V_22 ) ;
F_153 ( V_2 , V_335 , 0 ) ;
V_40 = F_149 ( V_2 , 0 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_41 ) ;
return V_40 ;
}
F_148 ( 2000 , 3000 ) ;
V_40 = F_147 ( V_2 , 0 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_42 ) ;
return V_40 ;
}
F_153 ( V_2 , V_336 , 0 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ )
F_143 ( V_2 , V_57 ) ;
F_151 ( V_2 ) ;
F_174 ( V_2 -> V_216 , V_22 ) ;
if ( ! V_2 -> V_4 )
F_174 ( V_2 -> V_217 , V_22 ) ;
F_175 ( V_22 -> V_253 ) ;
return 0 ;
}
static int F_180 ( struct V_351 * V_100 )
{
const struct V_352 * V_353 ;
const struct V_354 * V_355 = NULL ;
struct V_1 * V_2 ;
struct V_356 * V_357 ;
struct V_21 * V_22 ;
const void * V_358 ;
struct V_359 * V_360 ;
T_1 V_194 , V_361 ;
int V_40 ;
V_357 = V_100 -> V_22 . V_362 ;
V_360 = F_181 ( V_100 , V_363 , 0 ) ;
V_355 = F_182 ( V_364 , V_357 ) ;
if ( ! V_355 || ! V_355 -> V_66 )
return - V_102 ;
V_353 = V_355 -> V_66 ;
if ( F_183 ( V_357 , L_43 , & V_194 ) )
V_194 = V_365 ;
if ( F_183 ( V_357 , L_44 , & V_361 ) )
V_361 = 1 ;
if ( ! V_194 || V_194 > V_365 )
return - V_102 ;
V_22 = F_184 ( sizeof( * V_2 ) , V_194 , V_361 ) ;
if ( ! V_22 )
return - V_136 ;
V_2 = F_16 ( V_22 ) ;
V_2 -> V_86 = F_185 ( & V_100 -> V_22 , V_194 ,
sizeof( struct V_84 ) ,
V_278 ) ;
if ( ! V_2 -> V_86 )
return - V_136 ;
V_2 -> V_4 = V_353 -> V_4 ;
V_2 -> V_292 = V_353 -> V_292 ;
V_2 -> V_216 = F_186 ( V_100 , 0 ) ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_217 = F_186 ( V_100 , 1 ) ;
V_2 -> V_104 = F_186 ( V_100 , 2 ) ;
} else {
V_2 -> V_104 = F_186 ( V_100 , 1 ) ;
}
if ( V_2 -> V_216 <= 0 || ( V_2 -> V_217 <= 0 && ! V_2 -> V_4 ) ) {
F_187 ( & V_100 -> V_22 , L_45 ) ;
V_40 = - V_102 ;
goto V_366;
}
V_2 -> V_6 = F_188 ( & V_100 -> V_22 , V_360 ) ;
if ( F_189 ( V_2 -> V_6 ) ) {
V_40 = F_190 ( V_2 -> V_6 ) ;
goto V_366;
}
V_2 -> V_81 = V_22 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_342 = F_191 ( V_357 ) ;
if ( V_2 -> V_342 < 0 )
V_2 -> V_342 = V_367 ;
if ( F_192 ( V_357 ) ) {
V_40 = F_193 ( V_357 ) ;
if ( V_40 ) {
F_187 ( & V_100 -> V_22 , L_46 ) ;
goto V_366;
}
V_2 -> V_341 = V_357 ;
}
V_358 = F_194 ( V_357 ) ;
if ( ! V_358 || ! F_163 ( V_358 ) ) {
F_195 ( & V_100 -> V_22 , L_47 ) ;
F_196 ( V_22 ) ;
} else {
F_197 ( V_22 -> V_322 , V_358 ) ;
}
F_198 ( V_22 , & V_100 -> V_22 ) ;
F_199 ( & V_100 -> V_22 , V_22 ) ;
V_22 -> V_368 = & V_369 ;
V_22 -> V_370 = & V_371 ;
F_200 ( V_22 , & V_2 -> V_174 , F_92 , 64 ) ;
V_22 -> V_372 |= V_26 | V_373 |
V_33 | V_34 ;
V_2 -> V_103 = 1 ;
V_40 = F_201 ( & V_100 -> V_22 , V_2 -> V_104 ,
F_106 , 0 , V_22 -> V_344 , V_2 ) ;
if ( ! V_40 )
F_202 ( & V_100 -> V_22 , 1 ) ;
F_203 ( sizeof( struct V_219 ) != 8 ) ;
V_22 -> V_374 += sizeof( struct V_219 ) ;
F_204 ( V_22 ) ;
V_40 = F_205 ( V_22 ) ;
if ( V_40 ) {
F_187 ( & V_100 -> V_22 , L_48 ) ;
goto V_375;
}
V_2 -> V_376 = F_206 ( V_2 , V_377 ) & V_378 ;
F_207 ( & V_100 -> V_22 ,
L_49 V_379
L_50 ,
V_2 -> V_4 ? L_51 : L_52 ,
( V_2 -> V_376 >> 8 ) & 0xff , V_2 -> V_376 & 0xff ,
V_2 -> V_6 , V_2 -> V_216 , V_2 -> V_217 , V_194 , V_361 ) ;
return 0 ;
V_375:
if ( F_192 ( V_357 ) )
F_208 ( V_357 ) ;
V_366:
F_209 ( V_22 ) ;
return V_40 ;
}
static int F_210 ( struct V_351 * V_100 )
{
struct V_21 * V_22 = F_211 ( & V_100 -> V_22 ) ;
struct V_356 * V_357 = V_100 -> V_22 . V_362 ;
F_212 ( V_22 ) ;
if ( F_192 ( V_357 ) )
F_208 ( V_357 ) ;
F_209 ( V_22 ) ;
F_199 ( & V_100 -> V_22 , NULL ) ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_21 * V_123 = V_2 -> V_81 ;
unsigned int V_286 = 1000 ;
T_1 V_24 ;
V_24 = F_31 ( V_2 , V_202 ) ;
V_24 |= V_203 ;
V_24 &= ~ V_380 ;
if ( V_2 -> V_94 & V_93 )
V_24 |= V_380 ;
F_42 ( V_2 , V_24 , V_202 ) ;
do {
V_24 = F_32 ( V_2 , V_381 ) ;
if ( V_24 & V_382 )
break;
F_157 ( 10 ) ;
} while ( V_286 -- > 0 );
if ( ! V_286 ) {
V_24 = F_31 ( V_2 , V_202 ) ;
V_24 &= ~ V_203 ;
F_42 ( V_2 , V_24 , V_202 ) ;
F_57 ( V_2 , V_90 , V_123 , L_53 ) ;
return - V_290 ;
}
F_153 ( V_2 , V_335 , 1 ) ;
F_90 ( V_2 , V_201 ) ;
F_34 ( V_2 , V_90 , V_123 , L_54 ) ;
return 0 ;
}
static int F_214 ( struct V_98 * V_11 )
{
struct V_21 * V_22 = F_211 ( V_11 ) ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
int V_40 = 0 ;
T_1 V_24 ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_176 ( V_22 ) ;
F_215 ( V_22 -> V_253 ) ;
F_216 ( V_22 ) ;
F_153 ( V_2 , V_335 , 0 ) ;
V_40 = F_147 ( V_2 , 0 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_55 ) ;
return V_40 ;
}
if ( V_2 -> V_25 ) {
V_24 = F_17 ( V_2 , V_27 ) ;
V_24 &= ~ V_28 ;
F_19 ( V_2 , V_24 , V_27 ) ;
}
if ( ! V_2 -> V_94 )
F_160 ( V_2 , V_316 , V_317 ) ;
V_40 = F_149 ( V_2 , 0 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_56 ) ;
return V_40 ;
}
F_148 ( 2000 , 3000 ) ;
F_153 ( V_2 , V_336 , 0 ) ;
F_160 ( V_2 , V_318 , V_319 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ )
F_143 ( V_2 , V_57 ) ;
F_151 ( V_2 ) ;
if ( F_217 ( V_11 ) && V_2 -> V_94 )
V_40 = F_213 ( V_2 ) ;
return V_40 ;
}
static int F_218 ( struct V_98 * V_11 )
{
struct V_21 * V_22 = F_211 ( V_11 ) ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
T_1 V_24 ;
int V_40 ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_156 ( V_2 ) ;
F_94 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ ) {
V_40 = F_131 ( V_2 , V_57 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_39 ,
V_57 ) ;
goto V_383;
}
}
F_12 ( V_2 , V_348 , V_284 ) ;
V_40 = F_150 ( V_2 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_40 ) ;
goto V_349;
}
F_219 ( V_22 ) ;
F_160 ( V_2 , 0 , V_317 ) ;
V_40 = F_147 ( V_2 , 1 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_57 ) ;
goto V_349;
}
if ( V_2 -> V_25 ) {
V_24 = F_17 ( V_2 , V_27 ) ;
V_24 |= V_28 ;
F_19 ( V_2 , V_24 , V_27 ) ;
}
F_168 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_42 ( V_2 , V_337 , V_338 ) ;
else
F_170 ( V_2 ) ;
F_158 ( V_2 , V_22 -> V_322 ) ;
F_153 ( V_2 , V_335 , 1 ) ;
F_160 ( V_2 , 0 , V_319 ) ;
F_153 ( V_2 , V_336 , 1 ) ;
V_40 = F_149 ( V_2 , 1 ) ;
if ( V_40 ) {
F_122 ( V_22 , L_56 ) ;
goto V_349;
}
F_220 ( V_22 -> V_253 ) ;
F_165 ( V_22 ) ;
return 0 ;
V_349:
F_151 ( V_2 ) ;
V_383:
for ( V_57 = 0 ; V_57 < V_22 -> V_62 ; V_57 ++ )
F_143 ( V_2 , V_57 ) ;
return V_40 ;
}
