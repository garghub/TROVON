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
return V_58 ;
default:
return - V_62 ;
}
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_63 , T_5 * V_64 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
const struct V_55 * V_56 ;
int V_57 , V_58 ;
switch ( V_63 ) {
case V_59 :
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_60 ; V_57 ++ ) {
V_56 = & V_61 [ V_57 ] ;
if ( V_2 -> V_4 &&
! F_27 ( V_56 -> type ) )
continue;
memcpy ( V_64 + V_58 * V_65 , V_56 -> V_66 ,
V_65 ) ;
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
T_5 V_67 = 0 ;
T_1 V_8 = 0 ;
char * V_68 ;
V_56 = & V_61 [ V_57 ] ;
switch ( V_56 -> type ) {
case V_50 :
case V_53 :
continue;
case V_69 :
case V_70 :
case V_71 :
if ( V_2 -> V_4 )
continue;
if ( V_56 -> type != V_69 )
V_67 = V_72 ;
V_8 = F_31 ( V_2 , V_73 + V_58 + V_67 ) ;
break;
case V_51 :
V_8 = F_17 ( V_2 , V_56 -> V_74 ) ;
if ( V_8 == ~ 0 )
F_19 ( V_2 , 0 , V_56 -> V_74 ) ;
break;
case V_52 :
V_8 = F_32 ( V_2 , V_56 -> V_74 ) ;
if ( V_8 == ~ 0 )
F_33 ( V_2 , 0 , V_56 -> V_74 ) ;
break;
}
V_58 += V_56 -> V_75 ;
V_68 = ( char * ) V_2 + V_56 -> V_76 ;
* ( T_1 * ) V_68 = V_8 ;
}
F_34 ( V_2 , V_77 , V_2 -> V_78 , L_3 ) ;
}
static void F_35 ( struct V_21 * V_22 ,
struct V_79 * V_80 , T_6 * V_64 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
int V_57 , V_58 ;
if ( F_36 ( V_22 ) )
F_30 ( V_2 ) ;
for ( V_57 = 0 , V_58 = 0 ; V_57 < V_60 ; V_57 ++ ) {
const struct V_55 * V_56 ;
char * V_68 ;
V_56 = & V_61 [ V_57 ] ;
if ( V_56 -> type == V_50 )
V_68 = ( char * ) & V_22 -> V_80 ;
else
V_68 = ( char * ) V_2 ;
V_68 += V_56 -> V_76 ;
V_64 [ V_58 ] = * ( unsigned long * ) V_68 ;
V_58 ++ ;
}
}
static void F_37 ( struct V_21 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_82 -> V_83 = V_84 | V_85 ;
V_82 -> V_86 = V_2 -> V_86 ;
if ( ! ( V_2 -> V_86 & V_85 ) )
return;
V_24 = F_31 ( V_2 , V_87 ) ;
F_38 ( V_24 , & V_82 -> V_88 [ 0 ] ) ;
V_24 = F_31 ( V_2 , V_89 ) ;
F_39 ( V_24 , & V_82 -> V_88 [ 2 ] ) ;
}
static int F_40 ( struct V_21 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
T_1 V_83 = V_84 | V_85 ;
if ( ! F_41 ( V_91 ) )
return - V_93 ;
if ( V_82 -> V_86 & ~ V_83 )
return - V_94 ;
if ( V_82 -> V_86 & V_85 ) {
F_42 ( V_2 , F_43 ( & V_82 -> V_88 [ 0 ] ) ,
V_87 ) ;
F_42 ( V_2 , F_44 ( & V_82 -> V_88 [ 2 ] ) ,
V_89 ) ;
}
if ( V_82 -> V_86 ) {
F_45 ( V_91 , 1 ) ;
if ( V_2 -> V_95 )
F_46 ( V_2 -> V_96 ) ;
V_2 -> V_95 = 0 ;
} else {
F_45 ( V_91 , 0 ) ;
if ( ! V_2 -> V_95 )
F_47 ( V_2 -> V_96 ) ;
V_2 -> V_95 = 1 ;
}
V_2 -> V_86 = V_82 -> V_86 ;
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , F_49 ( 0 ) ) ;
V_98 -> V_99 = ( V_24 >> V_100 ) * 8192 / 1000 ;
V_98 -> V_101 = V_24 & V_102 ;
V_24 = F_1 ( V_2 , V_103 ) ;
V_98 -> V_104 = ( V_24 >> V_105 ) * 8192 / 1000 ;
V_98 -> V_106 = V_24 & V_107 ;
return 0 ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
T_1 V_24 ;
if ( V_98 -> V_101 > V_102 ||
V_98 -> V_99 > ( V_108 * 8 ) + 1 ||
V_98 -> V_106 > V_107 ||
V_98 -> V_104 > ( V_109 * 8 ) + 1 )
return - V_94 ;
if ( ( V_98 -> V_99 == 0 && V_98 -> V_101 == 0 ) ||
( V_98 -> V_104 == 0 && V_98 -> V_106 == 0 ) )
return - V_94 ;
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ ) {
V_24 = F_21 ( V_2 , F_49 ( V_57 ) ) ;
V_24 &= ~ ( V_102 |
V_108 << V_100 ) ;
V_24 |= V_98 -> V_101 ;
V_24 |= F_51 ( V_98 -> V_99 * 1000 , 8192 ) <<
V_100 ;
F_12 ( V_2 , V_24 , F_49 ( V_57 ) ) ;
}
V_24 = F_1 ( V_2 , V_103 ) ;
V_24 &= ~ ( V_107 |
V_109 << V_105 ) ;
V_24 |= V_98 -> V_106 ;
V_24 |= F_51 ( V_98 -> V_104 * 1000 , 8192 ) <<
V_105 ;
F_3 ( V_2 , V_24 , V_103 ) ;
return 0 ;
}
static void F_52 ( struct V_111 * V_112 )
{
F_53 ( V_112 -> V_113 ) ;
V_112 -> V_113 = NULL ;
F_54 ( V_112 , V_114 , 0 ) ;
}
static struct V_115 * F_55 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
struct V_21 * V_116 = V_2 -> V_78 ;
struct V_115 * V_113 , * V_117 ;
T_3 V_118 ;
V_113 = F_56 ( V_2 -> V_78 , V_119 ) ;
if ( ! V_113 ) {
V_2 -> V_120 . V_121 ++ ;
F_57 ( V_2 , V_122 , V_116 , L_4 ) ;
return NULL ;
}
V_118 = F_58 ( V_91 , V_113 -> V_64 ,
V_119 , V_123 ) ;
if ( F_59 ( V_91 , V_118 ) ) {
V_2 -> V_120 . V_124 ++ ;
F_53 ( V_113 ) ;
F_57 ( V_2 , V_122 , V_116 , L_5 ) ;
return NULL ;
}
V_117 = V_112 -> V_113 ;
if ( F_60 ( V_117 ) )
F_61 ( V_91 , F_62 ( V_112 , V_114 ) ,
V_119 , V_123 ) ;
V_112 -> V_113 = V_113 ;
F_54 ( V_112 , V_114 , V_118 ) ;
F_7 ( V_2 , V_112 -> V_125 , V_118 ) ;
F_34 ( V_2 , V_126 , V_116 , L_6 ) ;
return V_117 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
struct V_115 * V_113 ;
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_127 ; V_57 ++ ) {
V_112 = & V_2 -> V_128 [ V_57 ] ;
V_113 = F_55 ( V_2 , V_112 ) ;
if ( V_113 )
F_64 ( V_113 ) ;
if ( ! V_112 -> V_113 )
return - V_129 ;
}
return 0 ;
}
static unsigned int F_65 ( struct V_1 * V_2 ,
unsigned int V_130 )
{
struct V_21 * V_116 = V_2 -> V_78 ;
unsigned int V_131 = 0 , V_132 ;
struct V_111 * V_112 ;
struct V_115 * V_113 ;
unsigned int V_133 ;
T_7 V_134 , V_135 ;
struct V_136 * V_137 ;
if ( ! V_2 -> V_4 )
V_133 = F_1 ( V_2 , V_138 ) ;
else
V_133 = F_1 ( V_2 , V_139 ) ;
V_133 &= V_140 ;
if ( V_133 < V_2 -> V_141 )
V_132 = ( V_142 + 1 ) -
V_2 -> V_141 + V_133 ;
else
V_132 = V_133 - V_2 -> V_141 ;
F_34 ( V_2 , V_126 , V_116 ,
L_7 ,
V_133 , V_2 -> V_141 , V_132 ) ;
while ( ( V_131 < V_132 ) && ( V_131 < V_130 ) ) {
V_112 = & V_2 -> V_128 [ V_2 -> V_143 ] ;
V_113 = F_55 ( V_2 , V_112 ) ;
if ( F_66 ( ! V_113 ) ) {
F_57 ( V_2 , V_122 , V_116 , L_8 ) ;
V_116 -> V_80 . V_144 ++ ;
V_116 -> V_80 . V_145 ++ ;
goto V_146;
}
V_137 = (struct V_136 * ) V_113 -> V_64 ;
V_134 = ( V_137 -> V_147 >> V_148 ) & V_149 ;
V_135 = ( V_137 -> V_147 >> V_150 ) &
V_151 ;
F_34 ( V_2 , V_126 , V_116 ,
L_9 ,
V_133 , V_2 -> V_141 , V_2 -> V_143 ,
V_134 , V_135 ) ;
if ( F_66 ( V_134 > V_119 ) ) {
F_57 ( V_2 , V_126 , V_116 , L_10 ) ;
V_116 -> V_80 . V_152 ++ ;
V_116 -> V_80 . V_145 ++ ;
F_53 ( V_113 ) ;
goto V_146;
}
if ( F_66 ( ! ( V_135 & V_153 ) || ! ( V_135 & V_154 ) ) ) {
F_57 ( V_2 , V_126 , V_116 , L_11 ) ;
V_116 -> V_80 . V_144 ++ ;
V_116 -> V_80 . V_145 ++ ;
F_53 ( V_113 ) ;
goto V_146;
}
if ( F_66 ( V_135 & ( V_155 | V_156 ) ) ) {
F_57 ( V_2 , V_122 , V_116 , L_12 ) ;
if ( V_135 & V_156 )
V_116 -> V_80 . V_157 ++ ;
V_116 -> V_80 . V_144 ++ ;
V_116 -> V_80 . V_145 ++ ;
F_53 ( V_113 ) ;
goto V_146;
}
F_67 ( V_113 , V_134 ) ;
if ( F_60 ( V_135 & V_158 ) )
V_113 -> V_159 = V_160 ;
F_68 ( V_113 , sizeof( * V_137 ) + 2 ) ;
V_134 -= ( sizeof( * V_137 ) + 2 ) ;
if ( V_2 -> V_29 ) {
F_69 ( V_113 , V_134 - V_161 ) ;
V_134 -= V_161 ;
}
V_113 -> V_162 = F_70 ( V_113 , V_116 ) ;
V_116 -> V_80 . V_163 ++ ;
V_116 -> V_80 . V_164 += V_134 ;
F_71 ( & V_2 -> V_165 , V_113 ) ;
V_146:
V_131 ++ ;
V_2 -> V_143 ++ ;
if ( V_2 -> V_143 == V_2 -> V_127 )
V_2 -> V_143 = 0 ;
}
return V_131 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
unsigned int * V_166 ,
unsigned int * V_167 )
{
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
struct V_21 * V_116 = V_2 -> V_78 ;
if ( V_112 -> V_113 ) {
V_116 -> V_80 . V_168 += V_112 -> V_113 -> V_134 ;
* V_166 += V_112 -> V_113 -> V_134 ;
F_61 ( V_91 , F_62 ( V_112 , V_114 ) ,
F_73 ( V_112 , V_169 ) ,
V_170 ) ;
V_116 -> V_80 . V_171 ++ ;
( * V_167 ) ++ ;
F_52 ( V_112 ) ;
} else if ( F_62 ( V_112 , V_114 ) ) {
V_116 -> V_80 . V_168 += F_73 ( V_112 , V_169 ) ;
F_74 ( V_91 , F_62 ( V_112 , V_114 ) ,
F_73 ( V_112 , V_169 ) , V_170 ) ;
F_54 ( V_112 , V_114 , 0 ) ;
}
}
static unsigned int F_75 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_21 * V_116 = V_2 -> V_78 ;
unsigned int V_174 , V_175 , V_176 , V_177 ;
unsigned int V_167 = 0 , V_166 = 0 ;
struct V_111 * V_112 ;
T_1 V_178 ;
V_178 = F_21 ( V_2 , F_76 ( V_173 -> V_179 ) ) ;
V_174 = ( V_178 >> V_180 ) & V_181 ;
V_173 -> V_133 = ( V_178 & V_182 ) ;
V_175 = V_173 -> V_174 ;
V_177 = V_173 -> V_183 ;
V_174 &= ( V_177 - 1 ) ;
if ( V_174 >= V_175 )
V_176 = V_174 - V_175 ;
else
V_176 = V_177 - V_175 + V_174 ;
F_34 ( V_2 , V_184 , V_116 ,
L_13 ,
V_173 -> V_179 , V_174 , V_176 , V_175 ) ;
while ( V_176 -- > 0 ) {
V_112 = V_173 -> V_185 + V_175 ;
F_72 ( V_2 , V_112 , & V_166 , & V_167 ) ;
V_173 -> V_186 ++ ;
V_175 ++ ;
V_175 &= ( V_177 - 1 ) ;
}
V_173 -> V_174 = V_174 ;
F_34 ( V_2 , V_184 , V_116 ,
L_14 ,
V_173 -> V_179 , V_173 -> V_174 , V_167 , V_166 ) ;
return V_167 ;
}
static unsigned int F_77 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_187 * V_188 ;
unsigned int V_189 ;
unsigned long V_190 ;
V_188 = F_78 ( V_2 -> V_78 , V_173 -> V_179 ) ;
F_79 ( & V_173 -> V_191 , V_190 ) ;
V_189 = F_75 ( V_2 , V_173 ) ;
if ( V_189 )
F_80 ( V_188 ) ;
F_81 ( & V_173 -> V_191 , V_190 ) ;
return V_189 ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
unsigned long V_190 ;
F_79 ( & V_173 -> V_191 , V_190 ) ;
F_75 ( V_2 , V_173 ) ;
F_81 ( & V_173 -> V_191 , V_190 ) ;
}
static int F_83 ( struct V_192 * V_165 , int V_130 )
{
struct V_172 * V_173 =
F_84 ( V_165 , struct V_172 , V_165 ) ;
unsigned int V_193 = 0 ;
V_193 = F_77 ( V_173 -> V_2 , V_173 ) ;
if ( V_193 == 0 ) {
F_85 ( V_165 ) ;
if ( ! V_173 -> V_2 -> V_4 )
F_86 ( V_173 -> V_2 , F_6 ( V_173 -> V_179 ) ) ;
else
F_87 ( V_173 -> V_2 , F_6 ( V_173 -> V_179 +
V_194 ) ) ;
return 0 ;
}
return V_130 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned int V_195 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_78 -> V_110 ; V_195 ++ )
F_77 ( V_2 , & V_2 -> V_196 [ V_195 ] ) ;
}
static int F_89 ( struct V_192 * V_165 , int V_130 )
{
struct V_1 * V_2 =
F_84 ( V_165 , struct V_1 , V_165 ) ;
unsigned int V_193 = 0 ;
V_193 = F_65 ( V_2 , V_130 ) ;
V_2 -> V_141 += V_193 ;
V_2 -> V_141 &= V_142 ;
if ( ! V_2 -> V_4 )
F_3 ( V_2 , V_2 -> V_141 , V_139 ) ;
else
F_3 ( V_2 , V_2 -> V_141 << 16 , V_139 ) ;
if ( V_193 < V_130 ) {
F_90 ( V_165 , V_193 ) ;
F_87 ( V_2 , V_197 ) ;
}
return V_193 ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_92 ( V_2 , V_198 ) ;
V_24 = F_31 ( V_2 , V_199 ) ;
V_24 &= ~ V_200 ;
F_42 ( V_2 , V_24 , V_199 ) ;
F_34 ( V_2 , V_82 , V_2 -> V_78 , L_15 ) ;
}
static T_8 F_93 ( int V_201 , void * V_202 )
{
struct V_21 * V_22 = V_202 ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_172 * V_203 ;
unsigned int V_173 , V_204 ;
V_2 -> V_205 = F_94 ( V_2 , V_206 ) &
~ F_94 ( V_2 , V_207 ) ;
F_95 ( V_2 , V_2 -> V_205 , V_208 ) ;
if ( F_66 ( V_2 -> V_205 == 0 ) ) {
F_96 ( V_2 -> V_78 , L_16 ) ;
return V_209 ;
}
if ( V_2 -> V_205 & V_197 ) {
if ( F_60 ( F_97 ( & V_2 -> V_165 ) ) ) {
F_92 ( V_2 , V_197 ) ;
F_98 ( & V_2 -> V_165 ) ;
}
}
if ( V_2 -> V_205 & V_210 )
F_88 ( V_2 ) ;
if ( V_2 -> V_205 & V_198 ) {
F_99 ( V_2 -> V_78 , L_17 ) ;
F_91 ( V_2 ) ;
}
if ( ! V_2 -> V_4 )
goto V_211;
for ( V_173 = 0 ; V_173 < V_22 -> V_110 ; V_173 ++ ) {
V_204 = F_6 ( V_173 + V_194 ) ;
if ( ! ( V_2 -> V_205 & V_204 ) )
continue;
V_203 = & V_2 -> V_196 [ V_173 ] ;
if ( F_60 ( F_97 ( & V_203 -> V_165 ) ) ) {
F_92 ( V_2 , V_204 ) ;
F_100 ( & V_203 -> V_165 ) ;
}
}
V_211:
return V_212 ;
}
static T_8 F_101 ( int V_201 , void * V_202 )
{
struct V_21 * V_22 = V_202 ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_172 * V_203 ;
unsigned int V_173 ;
V_2 -> V_213 = F_102 ( V_2 , V_206 ) &
~ F_102 ( V_2 , V_207 ) ;
F_103 ( V_2 , 0xffffffff , V_208 ) ;
if ( F_66 ( V_2 -> V_213 == 0 ) ) {
F_96 ( V_2 -> V_78 , L_18 ) ;
return V_209 ;
}
for ( V_173 = 0 ; V_173 < V_22 -> V_110 ; V_173 ++ ) {
if ( ! ( V_2 -> V_213 & F_6 ( V_173 ) ) )
continue;
V_203 = & V_2 -> V_196 [ V_173 ] ;
if ( F_60 ( F_97 ( & V_203 -> V_165 ) ) ) {
F_104 ( V_2 , F_6 ( V_173 ) ) ;
F_98 ( & V_203 -> V_165 ) ;
}
}
return V_212 ;
}
static T_8 F_105 ( int V_201 , void * V_202 )
{
struct V_1 * V_2 = V_202 ;
F_106 ( & V_2 -> V_92 -> V_22 , 0 ) ;
return V_212 ;
}
static void F_107 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_108 ( V_2 -> V_214 ) ;
F_93 ( V_2 -> V_214 , V_2 ) ;
F_109 ( V_2 -> V_214 ) ;
if ( ! V_2 -> V_4 ) {
F_108 ( V_2 -> V_215 ) ;
F_101 ( V_2 -> V_215 , V_2 ) ;
F_109 ( V_2 -> V_215 ) ;
}
}
static struct V_115 * F_110 ( struct V_115 * V_113 ,
struct V_21 * V_22 )
{
struct V_115 * V_216 ;
struct V_217 * V_218 ;
T_1 V_219 ;
T_5 V_220 ;
T_7 V_221 ;
T_7 V_222 ;
if ( F_66 ( F_111 ( V_113 ) < sizeof( * V_218 ) ) ) {
V_216 = F_112 ( V_113 , sizeof( * V_218 ) ) ;
F_64 ( V_113 ) ;
if ( ! V_216 ) {
V_22 -> V_80 . V_223 ++ ;
V_22 -> V_80 . V_224 ++ ;
return NULL ;
}
V_113 = V_216 ;
}
V_218 = (struct V_217 * ) F_113 ( V_113 , sizeof( * V_218 ) ) ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
if ( V_113 -> V_159 == V_225 ) {
V_222 = F_114 ( V_113 -> V_162 ) ;
switch ( V_222 ) {
case V_226 :
V_220 = F_115 ( V_113 ) -> V_162 ;
break;
case V_227 :
V_220 = F_116 ( V_113 ) -> V_228 ;
break;
default:
return V_113 ;
}
V_221 = F_117 ( V_113 ) - sizeof( * V_218 ) ;
V_219 = ( V_221 + V_113 -> V_229 ) & V_230 ;
V_219 |= ( V_221 << V_231 ) ;
if ( V_220 == V_232 || V_220 == V_233 ) {
V_219 |= V_234 ;
if ( V_220 == V_233 && V_222 == V_226 )
V_219 |= V_235 ;
} else {
V_219 = 0 ;
}
V_218 -> V_236 = V_219 ;
}
return V_113 ;
}
static T_9 F_118 ( struct V_115 * V_113 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
struct V_172 * V_173 ;
struct V_111 * V_112 ;
struct V_187 * V_188 ;
struct V_16 * V_17 ;
unsigned int V_237 ;
unsigned long V_190 ;
T_3 V_118 ;
T_1 V_238 ;
T_7 V_239 ;
int V_40 ;
V_239 = F_119 ( V_113 ) ;
V_188 = F_78 ( V_22 , V_239 ) ;
V_173 = & V_2 -> V_196 [ V_239 ] ;
F_79 ( & V_173 -> V_191 , V_190 ) ;
if ( F_66 ( V_173 -> V_186 == 0 ) ) {
F_120 ( V_188 ) ;
F_121 ( V_22 , L_19 , V_239 ) ;
V_40 = V_240 ;
goto V_211;
}
if ( F_122 ( V_113 , V_241 + V_242 ) ) {
V_40 = V_243 ;
goto V_211;
}
if ( V_2 -> V_32 ) {
V_113 = F_110 ( V_113 , V_22 ) ;
if ( ! V_113 ) {
V_40 = V_243 ;
goto V_211;
}
}
V_237 = V_113 -> V_134 ;
V_118 = F_58 ( V_91 , V_113 -> V_64 , V_237 , V_170 ) ;
if ( F_59 ( V_91 , V_118 ) ) {
V_2 -> V_120 . V_244 ++ ;
F_57 ( V_2 , V_245 , V_22 , L_20 ,
V_113 -> V_64 , V_237 ) ;
V_40 = V_243 ;
goto V_211;
}
V_112 = & V_173 -> V_185 [ V_173 -> V_246 ] ;
V_112 -> V_113 = V_113 ;
F_54 ( V_112 , V_114 , V_118 ) ;
F_123 ( V_112 , V_169 , V_237 ) ;
V_17 = V_173 -> V_247 ;
V_17 -> V_20 = F_10 ( V_118 ) ;
V_238 = F_9 ( V_118 ) & V_13 ;
V_238 |= ( V_237 << V_148 ) ;
V_238 |= ( V_154 | V_153 | V_248 ) <<
V_150 ;
if ( V_113 -> V_159 == V_225 )
V_238 |= ( V_158 << V_150 ) ;
V_173 -> V_246 ++ ;
if ( V_173 -> V_246 == V_173 -> V_183 )
V_173 -> V_246 = 0 ;
V_173 -> V_186 -- ;
F_124 () ;
V_17 -> V_19 = V_238 ;
F_124 () ;
F_11 ( V_2 , V_17 , V_173 -> V_179 ) ;
if ( V_173 -> V_186 == 0 )
F_120 ( V_188 ) ;
F_34 ( V_2 , V_249 , V_22 , L_21 ,
V_173 -> V_179 , V_173 -> V_186 , V_173 -> V_246 ) ;
V_40 = V_243 ;
V_211:
F_81 ( & V_173 -> V_191 , V_190 ) ;
return V_40 ;
}
static void F_125 ( struct V_21 * V_22 )
{
F_96 ( V_22 , L_22 ) ;
F_126 ( V_22 ) ;
V_22 -> V_80 . V_223 ++ ;
F_127 ( V_22 ) ;
}
static void F_128 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_250 * V_251 = V_22 -> V_251 ;
unsigned int V_38 = 0 ;
T_1 V_252 = 0 , V_24 ;
if ( V_2 -> V_253 != V_251 -> V_254 ) {
V_38 = 1 ;
V_2 -> V_253 = V_251 -> V_254 ;
}
if ( V_2 -> V_255 != V_251 -> V_256 ) {
V_38 = 1 ;
V_2 -> V_255 = V_251 -> V_256 ;
}
if ( V_2 -> V_4 )
goto V_211;
switch ( V_251 -> V_257 ) {
case V_258 :
V_252 = V_259 ;
break;
case V_260 :
V_252 = V_261 ;
break;
case V_262 :
V_252 = V_263 ;
break;
case V_264 :
V_252 = V_265 ;
break;
default:
break;
}
V_252 <<= V_266 ;
if ( V_251 -> V_256 == V_267 )
V_252 |= V_268 ;
if ( V_2 -> V_269 != V_251 -> V_270 ) {
V_38 = 1 ;
V_2 -> V_269 = V_251 -> V_270 ;
}
if ( ! V_251 -> V_270 )
V_252 |= V_271 | V_272 ;
if ( ! V_38 )
return;
if ( V_251 -> V_254 ) {
V_24 = F_31 ( V_2 , V_273 ) ;
V_24 &= ~ ( ( V_274 << V_266 ) |
V_268 | V_271 |
V_272 ) ;
V_24 |= V_252 ;
F_42 ( V_2 , V_24 , V_273 ) ;
}
V_211:
if ( V_38 )
F_129 ( V_251 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
unsigned int V_179 )
{
struct V_172 * V_173 = & V_2 -> V_196 [ V_179 ] ;
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
T_10 V_183 ;
void * V_68 ;
T_1 V_24 ;
V_183 = 256 ;
V_68 = F_131 ( V_91 , sizeof( struct V_16 ) , & V_173 -> V_275 ,
V_276 ) ;
if ( ! V_68 ) {
F_57 ( V_2 , V_77 , V_2 -> V_78 , L_23 ) ;
return - V_129 ;
}
V_173 -> V_185 = F_132 ( V_183 , sizeof( struct V_111 ) , V_276 ) ;
if ( ! V_173 -> V_185 ) {
F_57 ( V_2 , V_77 , V_2 -> V_78 , L_24 ) ;
return - V_129 ;
}
F_133 ( & V_173 -> V_191 ) ;
V_173 -> V_2 = V_2 ;
F_134 ( V_2 -> V_78 , & V_173 -> V_165 , F_83 , 64 ) ;
V_173 -> V_179 = V_179 ;
V_173 -> V_183 = V_183 ;
V_173 -> V_277 = V_173 -> V_183 ;
V_173 -> V_247 = V_68 ;
V_173 -> V_186 = V_173 -> V_183 ;
V_173 -> V_246 = 0 ;
F_12 ( V_2 , V_278 , F_135 ( V_179 ) ) ;
F_12 ( V_2 , 0 , F_136 ( V_179 ) ) ;
F_12 ( V_2 , 1 , F_49 ( V_179 ) ) ;
F_12 ( V_2 , 0 , F_76 ( V_179 ) ) ;
F_12 ( V_2 , V_279 , F_137 ( V_179 ) ) ;
F_12 ( V_2 , 0 , F_138 ( V_179 ) ) ;
F_12 ( V_2 , V_173 -> V_183 |
1 << V_280 ,
F_139 ( V_179 ) ) ;
V_24 = F_21 ( V_2 , V_281 ) ;
V_24 |= ( 1 << V_179 ) ;
F_12 ( V_2 , V_24 , V_281 ) ;
F_140 ( & V_173 -> V_165 ) ;
F_34 ( V_2 , V_77 , V_2 -> V_78 ,
L_25 ,
V_173 -> V_183 , V_173 -> V_247 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 ,
unsigned int V_179 )
{
struct V_172 * V_173 = & V_2 -> V_196 [ V_179 ] ;
struct V_90 * V_91 = & V_2 -> V_92 -> V_22 ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , V_282 ) ;
if ( ! ( V_24 & V_283 ) )
F_96 ( V_2 -> V_78 , L_26 ) ;
if ( ! V_173 -> V_185 )
return;
F_142 ( & V_173 -> V_165 ) ;
F_143 ( & V_173 -> V_165 ) ;
F_82 ( V_2 , V_173 ) ;
F_144 ( V_173 -> V_185 ) ;
V_173 -> V_185 = NULL ;
if ( V_173 -> V_275 ) {
F_145 ( V_91 , sizeof( struct V_16 ) ,
V_173 -> V_247 , V_173 -> V_275 ) ;
V_173 -> V_275 = 0 ;
}
V_173 -> V_183 = 0 ;
V_173 -> V_277 = 0 ;
F_34 ( V_2 , V_77 , V_2 -> V_78 , L_27 ) ;
}
static inline int F_146 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
unsigned int V_284 = 1000 ;
T_1 V_24 ;
V_24 = F_1 ( V_2 , V_285 ) ;
if ( V_48 )
V_24 |= V_286 ;
else
V_24 &= ~ V_286 ;
F_3 ( V_2 , V_24 , V_285 ) ;
do {
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ! ( V_24 & V_287 ) == ! V_48 )
return 0 ;
F_147 ( 1000 , 2000 ) ;
} while ( V_284 -- > 0 );
F_121 ( V_2 -> V_78 , L_28 ) ;
return - V_288 ;
}
static inline int F_148 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
unsigned int V_284 = 1000 ;
T_1 V_24 ;
V_24 = F_21 ( V_2 , V_35 ) ;
if ( V_48 )
V_24 |= F_5 ( V_2 , V_289 ) ;
else
V_24 &= ~ F_5 ( V_2 , V_289 ) ;
F_12 ( V_2 , V_24 , V_35 ) ;
do {
V_24 = F_21 ( V_2 , V_282 ) ;
if ( ! ! ( V_24 & V_283 ) == ! V_48 )
return 0 ;
F_147 ( 1000 , 2000 ) ;
} while ( V_284 -- > 0 );
F_121 ( V_2 -> V_78 , L_29 ) ;
return - V_288 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
T_1 V_24 ;
int V_40 ;
int V_57 ;
V_2 -> V_127 = V_2 -> V_290 / V_291 ;
V_2 -> V_292 = V_2 -> V_6 + V_7 ;
V_2 -> V_141 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_128 = F_132 ( V_2 -> V_127 , sizeof( struct V_111 ) ,
V_276 ) ;
if ( ! V_2 -> V_128 ) {
F_57 ( V_2 , V_77 , V_2 -> V_78 , L_24 ) ;
return - V_129 ;
}
for ( V_57 = 0 ; V_57 < V_2 -> V_127 ; V_57 ++ ) {
V_112 = V_2 -> V_128 + V_57 ;
V_112 -> V_125 = V_2 -> V_292 + V_57 * V_293 ;
}
V_40 = F_63 ( V_2 ) ;
if ( V_40 ) {
F_57 ( V_2 , V_77 , V_2 -> V_78 , L_30 ) ;
return V_40 ;
}
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ( V_24 & V_287 ) )
F_146 ( V_2 , 0 ) ;
F_3 ( V_2 , 0 , V_294 ) ;
F_3 ( V_2 , 0 , V_295 ) ;
F_3 ( V_2 , 0 , V_138 ) ;
F_3 ( V_2 , 0 , V_139 ) ;
F_3 ( V_2 , V_2 -> V_127 << V_296 |
V_119 , V_297 ) ;
F_3 ( V_2 , 0 , V_298 ) ;
F_3 ( V_2 , 0 , V_299 ) ;
F_3 ( V_2 , 0 , V_300 ) ;
F_3 ( V_2 , V_2 -> V_290 - 1 , V_301 ) ;
F_3 ( V_2 , 1 , V_103 ) ;
F_34 ( V_2 , V_77 , V_2 -> V_78 ,
L_31 ,
V_2 -> V_127 , V_2 -> V_292 ) ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
unsigned int V_57 ;
T_1 V_24 ;
V_24 = F_1 ( V_2 , V_5 ) ;
if ( ! ( V_24 & V_287 ) )
F_96 ( V_2 -> V_78 , L_32 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_127 ; V_57 ++ ) {
V_112 = & V_2 -> V_128 [ V_57 ] ;
if ( F_62 ( V_112 , V_114 ) )
F_61 ( & V_2 -> V_92 -> V_22 ,
F_62 ( V_112 , V_114 ) ,
V_119 , V_123 ) ;
F_52 ( V_112 ) ;
}
F_144 ( V_2 -> V_128 ) ;
V_2 -> V_128 = NULL ;
F_34 ( V_2 , V_77 , V_2 -> V_78 , L_33 ) ;
}
static void F_151 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
T_1 V_24 ;
if ( V_2 -> V_4 )
return;
V_24 = F_31 ( V_2 , V_273 ) ;
if ( V_22 -> V_190 & V_302 )
V_24 |= V_303 ;
else
V_24 &= ~ V_303 ;
F_42 ( V_2 , V_24 , V_273 ) ;
if ( V_22 -> V_190 & V_304 )
return;
}
static inline void F_152 ( struct V_1 * V_2 ,
T_1 V_305 , unsigned int V_48 )
{
T_1 V_24 ;
if ( ! V_2 -> V_4 ) {
V_24 = F_31 ( V_2 , V_273 ) ;
if ( V_48 )
V_24 |= V_305 ;
else
V_24 &= ~ V_305 ;
F_42 ( V_2 , V_24 , V_273 ) ;
} else {
V_24 = F_153 ( V_2 , V_306 ) ;
if ( V_48 )
V_24 |= V_305 ;
else
V_24 &= ~ V_305 ;
F_154 ( V_2 , V_24 , V_306 ) ;
}
if ( V_48 == 0 )
F_147 ( 1000 , 2000 ) ;
}
static inline void F_155 ( struct V_1 * V_2 )
{
T_1 V_24 ;
if ( V_2 -> V_4 )
return;
V_24 = F_31 ( V_2 , V_273 ) ;
V_24 |= V_307 ;
F_42 ( V_2 , V_24 , V_273 ) ;
F_156 ( 10 ) ;
V_24 = F_31 ( V_2 , V_273 ) ;
V_24 &= ~ V_307 ;
F_42 ( V_2 , V_24 , V_273 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
unsigned char * V_12 )
{
T_1 V_308 = ( V_12 [ 0 ] << 24 ) | ( V_12 [ 1 ] << 16 ) | ( V_12 [ 2 ] << 8 ) |
V_12 [ 3 ] ;
T_1 V_309 = ( V_12 [ 4 ] << 8 ) | V_12 [ 5 ] ;
if ( ! V_2 -> V_4 ) {
F_42 ( V_2 , V_308 , V_310 ) ;
F_42 ( V_2 , V_309 , V_311 ) ;
} else {
F_154 ( V_2 , V_308 , V_312 ) ;
F_154 ( V_2 , V_309 , V_313 ) ;
}
}
static void F_158 ( struct V_1 * V_2 )
{
F_159 ( V_2 , V_314 , V_315 ) ;
F_159 ( V_2 , V_316 , V_317 ) ;
F_160 ( 1 ) ;
F_159 ( V_2 , 0 , V_315 ) ;
F_159 ( V_2 , 0 , V_317 ) ;
}
static int F_161 ( struct V_21 * V_22 , void * V_68 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_318 * V_12 = V_68 ;
if ( ! F_162 ( V_12 -> V_319 ) )
return - V_94 ;
memcpy ( V_22 -> V_320 , V_12 -> V_319 , V_22 -> V_321 ) ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_157 ( V_2 , V_22 -> V_320 ) ;
return 0 ;
}
static void F_163 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_140 ( & V_2 -> V_165 ) ;
F_87 ( V_2 , V_197 | V_210 ) ;
F_164 ( V_22 -> V_251 ) ;
if ( ! V_2 -> V_4 )
F_86 ( V_2 , 0xffffffff ) ;
else
F_87 ( V_2 , V_322 ) ;
F_165 ( V_22 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
T_1 V_24 ;
V_24 = F_32 ( V_2 , V_323 ) ;
V_24 |= V_324 | V_325 ;
if ( V_2 -> V_4 ) {
V_24 &= ~ V_326 ;
V_24 |= V_327 ;
}
F_33 ( V_2 , V_24 , V_323 ) ;
}
static inline void F_167 ( struct V_1 * V_2 )
{
F_92 ( V_2 , 0xffffffff ) ;
F_95 ( V_2 , 0xffffffff , V_208 ) ;
if ( ! V_2 -> V_4 ) {
F_104 ( V_2 , 0xffffffff ) ;
F_103 ( V_2 , 0xffffffff , V_208 ) ;
}
}
static inline void F_168 ( struct V_1 * V_2 )
{
T_1 T_11 V_24 ;
if ( F_18 ( V_2 -> V_78 ) ) {
V_24 = F_153 ( V_2 , V_306 ) ;
V_24 &= ~ ( V_328 << V_329 ) ;
V_24 |= V_242 << V_329 ;
F_154 ( V_2 , V_24 , V_306 ) ;
}
}
static int F_169 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
struct V_250 * V_251 ;
unsigned int V_57 ;
int V_40 ;
F_155 ( V_2 ) ;
F_158 ( V_2 ) ;
F_152 ( V_2 , V_330 | V_331 , 0 ) ;
F_166 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_42 ( V_2 , V_332 , V_333 ) ;
else
F_168 ( V_2 ) ;
F_157 ( V_2 , V_22 -> V_320 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_29 = ! ! ( F_31 ( V_2 , V_273 ) & V_334 ) ;
else
V_2 -> V_29 = ! ! ( F_153 ( V_2 , V_306 ) &
V_335 ) ;
V_251 = F_170 ( V_22 , V_2 -> V_336 , F_128 ,
0 , V_2 -> V_337 ) ;
if ( ! V_251 ) {
F_121 ( V_22 , L_34 ) ;
return - V_338 ;
}
V_2 -> V_255 = - 1 ;
V_2 -> V_253 = - 1 ;
V_2 -> V_269 = - 1 ;
F_167 ( V_2 ) ;
V_40 = F_171 ( V_2 -> V_214 , F_93 , 0 , V_22 -> V_339 , V_22 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_35 ) ;
goto V_340;
}
if ( ! V_2 -> V_4 ) {
V_40 = F_171 ( V_2 -> V_215 , F_101 , 0 ,
V_22 -> V_339 , V_22 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_36 ) ;
goto V_341;
}
}
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ ) {
V_40 = F_130 ( V_2 , V_57 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_37 ,
V_57 ) ;
goto V_342;
}
}
F_12 ( V_2 , V_343 , V_282 ) ;
V_40 = F_149 ( V_2 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_38 ) ;
goto V_344;
}
V_40 = F_146 ( V_2 , 1 ) ;
if ( V_40 )
goto V_344;
V_40 = F_148 ( V_2 , 1 ) ;
if ( V_40 )
goto V_345;
F_152 ( V_2 , V_330 | V_331 , 1 ) ;
F_163 ( V_22 ) ;
return 0 ;
V_345:
F_92 ( V_2 , V_197 | V_210 ) ;
V_344:
F_150 ( V_2 ) ;
V_342:
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ )
F_141 ( V_2 , V_57 ) ;
if ( ! V_2 -> V_4 )
F_172 ( V_2 -> V_215 , V_22 ) ;
V_341:
F_172 ( V_2 -> V_214 , V_22 ) ;
V_340:
F_173 ( V_251 ) ;
return V_40 ;
}
static void F_174 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
F_175 ( V_22 ) ;
F_142 ( & V_2 -> V_165 ) ;
F_176 ( V_22 -> V_251 ) ;
F_167 ( V_2 ) ;
}
static int F_177 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
int V_40 ;
F_174 ( V_22 ) ;
F_152 ( V_2 , V_330 , 0 ) ;
V_40 = F_148 ( V_2 , 0 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_39 ) ;
return V_40 ;
}
F_147 ( 2000 , 3000 ) ;
V_40 = F_146 ( V_2 , 0 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_40 ) ;
return V_40 ;
}
F_152 ( V_2 , V_331 , 0 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ )
F_141 ( V_2 , V_57 ) ;
F_150 ( V_2 ) ;
F_172 ( V_2 -> V_214 , V_22 ) ;
if ( ! V_2 -> V_4 )
F_172 ( V_2 -> V_215 , V_22 ) ;
F_173 ( V_22 -> V_251 ) ;
return 0 ;
}
static int F_178 ( struct V_346 * V_92 )
{
const struct V_347 * V_348 ;
const struct V_349 * V_350 = NULL ;
struct V_1 * V_2 ;
struct V_351 * V_352 ;
struct V_21 * V_22 ;
const void * V_353 ;
struct V_354 * V_355 ;
T_1 V_188 , V_356 ;
int V_40 ;
V_352 = V_92 -> V_22 . V_357 ;
V_355 = F_179 ( V_92 , V_358 , 0 ) ;
V_350 = F_180 ( V_359 , V_352 ) ;
if ( ! V_350 || ! V_350 -> V_64 )
return - V_94 ;
V_348 = V_350 -> V_64 ;
if ( F_181 ( V_352 , L_41 , & V_188 ) )
V_188 = V_360 ;
if ( F_181 ( V_352 , L_42 , & V_356 ) )
V_356 = 1 ;
if ( ! V_188 || V_188 > V_360 )
return - V_94 ;
V_22 = F_182 ( sizeof( * V_2 ) , V_188 , V_356 ) ;
if ( ! V_22 )
return - V_129 ;
V_2 = F_16 ( V_22 ) ;
V_2 -> V_196 = F_183 ( & V_92 -> V_22 , V_188 ,
sizeof( struct V_172 ) ,
V_276 ) ;
if ( ! V_2 -> V_196 )
return - V_129 ;
V_2 -> V_4 = V_348 -> V_4 ;
V_2 -> V_290 = V_348 -> V_290 ;
V_2 -> V_214 = F_184 ( V_92 , 0 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_215 = F_184 ( V_92 , 1 ) ;
V_2 -> V_96 = F_184 ( V_92 , 2 ) ;
if ( V_2 -> V_214 <= 0 || ( V_2 -> V_215 <= 0 && ! V_2 -> V_4 ) ) {
F_185 ( & V_92 -> V_22 , L_43 ) ;
V_40 = - V_94 ;
goto V_361;
}
V_2 -> V_6 = F_186 ( & V_92 -> V_22 , V_355 ) ;
if ( F_187 ( V_2 -> V_6 ) ) {
V_40 = F_188 ( V_2 -> V_6 ) ;
goto V_361;
}
V_2 -> V_78 = V_22 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_337 = F_189 ( V_352 ) ;
if ( V_2 -> V_337 < 0 )
V_2 -> V_337 = V_362 ;
if ( F_190 ( V_352 ) ) {
V_40 = F_191 ( V_352 ) ;
if ( V_40 ) {
F_185 ( & V_92 -> V_22 , L_44 ) ;
goto V_361;
}
V_2 -> V_336 = V_352 ;
}
V_353 = F_192 ( V_352 ) ;
if ( ! V_353 || ! F_162 ( V_353 ) ) {
F_193 ( & V_92 -> V_22 , L_45 ) ;
F_194 ( V_22 ) ;
} else {
F_195 ( V_22 -> V_320 , V_353 ) ;
}
F_196 ( V_22 , & V_92 -> V_22 ) ;
F_197 ( & V_92 -> V_22 , V_22 ) ;
V_22 -> V_363 = & V_364 ;
V_22 -> V_365 = & V_366 ;
F_198 ( V_22 , & V_2 -> V_165 , F_89 , 64 ) ;
V_22 -> V_367 |= V_26 | V_368 |
V_33 | V_34 ;
V_2 -> V_95 = 1 ;
V_40 = F_199 ( & V_92 -> V_22 , V_2 -> V_96 ,
F_105 , 0 , V_22 -> V_339 , V_2 ) ;
if ( ! V_40 )
F_200 ( & V_92 -> V_22 , 1 ) ;
F_201 ( sizeof( struct V_217 ) != 8 ) ;
V_22 -> V_369 += sizeof( struct V_217 ) ;
F_202 ( V_22 ) ;
V_40 = F_203 ( V_22 ) ;
if ( V_40 ) {
F_185 ( & V_92 -> V_22 , L_46 ) ;
goto V_370;
}
V_2 -> V_371 = F_204 ( V_2 , V_372 ) & V_373 ;
F_205 ( & V_92 -> V_22 ,
L_47 V_374
L_48 ,
V_2 -> V_4 ? L_49 : L_50 ,
( V_2 -> V_371 >> 8 ) & 0xff , V_2 -> V_371 & 0xff ,
V_2 -> V_6 , V_2 -> V_214 , V_2 -> V_215 , V_188 , V_356 ) ;
return 0 ;
V_370:
if ( F_190 ( V_352 ) )
F_206 ( V_352 ) ;
V_361:
F_207 ( V_22 ) ;
return V_40 ;
}
static int F_208 ( struct V_346 * V_92 )
{
struct V_21 * V_22 = F_209 ( & V_92 -> V_22 ) ;
struct V_351 * V_352 = V_92 -> V_22 . V_357 ;
F_210 ( V_22 ) ;
if ( F_190 ( V_352 ) )
F_206 ( V_352 ) ;
F_207 ( V_22 ) ;
F_197 ( & V_92 -> V_22 , NULL ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
struct V_21 * V_116 = V_2 -> V_78 ;
unsigned int V_284 = 1000 ;
T_1 V_24 ;
V_24 = F_31 ( V_2 , V_199 ) ;
V_24 |= V_200 ;
V_24 &= ~ V_375 ;
if ( V_2 -> V_86 & V_85 )
V_24 |= V_375 ;
F_42 ( V_2 , V_24 , V_199 ) ;
do {
V_24 = F_32 ( V_2 , V_376 ) ;
if ( V_24 & V_377 )
break;
F_156 ( 10 ) ;
} while ( V_284 -- > 0 );
if ( ! V_284 ) {
V_24 = F_31 ( V_2 , V_199 ) ;
V_24 &= ~ V_200 ;
F_42 ( V_2 , V_24 , V_199 ) ;
F_57 ( V_2 , V_82 , V_116 , L_51 ) ;
return - V_288 ;
}
F_152 ( V_2 , V_330 , 1 ) ;
F_87 ( V_2 , V_198 ) ;
F_34 ( V_2 , V_82 , V_116 , L_52 ) ;
return 0 ;
}
static int F_212 ( struct V_90 * V_11 )
{
struct V_21 * V_22 = F_209 ( V_11 ) ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
int V_40 = 0 ;
T_1 V_24 ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_174 ( V_22 ) ;
F_213 ( V_22 -> V_251 ) ;
F_214 ( V_22 ) ;
F_152 ( V_2 , V_330 , 0 ) ;
V_40 = F_146 ( V_2 , 0 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_53 ) ;
return V_40 ;
}
if ( V_2 -> V_25 ) {
V_24 = F_17 ( V_2 , V_27 ) ;
V_24 &= ~ V_28 ;
F_19 ( V_2 , V_24 , V_27 ) ;
}
if ( ! V_2 -> V_86 )
F_159 ( V_2 , V_314 , V_315 ) ;
V_40 = F_148 ( V_2 , 0 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_54 ) ;
return V_40 ;
}
F_147 ( 2000 , 3000 ) ;
F_152 ( V_2 , V_331 , 0 ) ;
F_159 ( V_2 , V_316 , V_317 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ )
F_141 ( V_2 , V_57 ) ;
F_150 ( V_2 ) ;
if ( F_215 ( V_11 ) && V_2 -> V_86 )
V_40 = F_211 ( V_2 ) ;
return V_40 ;
}
static int F_216 ( struct V_90 * V_11 )
{
struct V_21 * V_22 = F_209 ( V_11 ) ;
struct V_1 * V_2 = F_16 ( V_22 ) ;
unsigned int V_57 ;
T_1 V_24 ;
int V_40 ;
if ( ! F_36 ( V_22 ) )
return 0 ;
F_155 ( V_2 ) ;
F_91 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ ) {
V_40 = F_130 ( V_2 , V_57 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_37 ,
V_57 ) ;
goto V_378;
}
}
F_12 ( V_2 , V_343 , V_282 ) ;
V_40 = F_149 ( V_2 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_38 ) ;
goto V_344;
}
F_217 ( V_22 ) ;
F_159 ( V_2 , 0 , V_315 ) ;
V_40 = F_146 ( V_2 , 1 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_55 ) ;
goto V_344;
}
if ( V_2 -> V_25 ) {
V_24 = F_17 ( V_2 , V_27 ) ;
V_24 |= V_28 ;
F_19 ( V_2 , V_24 , V_27 ) ;
}
F_166 ( V_2 ) ;
if ( ! V_2 -> V_4 )
F_42 ( V_2 , V_332 , V_333 ) ;
else
F_168 ( V_2 ) ;
F_157 ( V_2 , V_22 -> V_320 ) ;
F_152 ( V_2 , V_330 , 1 ) ;
F_159 ( V_2 , 0 , V_317 ) ;
F_152 ( V_2 , V_331 , 1 ) ;
V_40 = F_148 ( V_2 , 1 ) ;
if ( V_40 ) {
F_121 ( V_22 , L_54 ) ;
goto V_344;
}
F_218 ( V_22 -> V_251 ) ;
F_163 ( V_22 ) ;
return 0 ;
V_344:
F_150 ( V_2 ) ;
V_378:
for ( V_57 = 0 ; V_57 < V_22 -> V_110 ; V_57 ++ )
F_141 ( V_2 , V_57 ) ;
return V_40 ;
}
