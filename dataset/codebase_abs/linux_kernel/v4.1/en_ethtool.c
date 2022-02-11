static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_2 -> V_6 [ V_3 ] -> V_7 = V_2 -> V_8 ;
V_2 -> V_6 [ V_3 ] -> V_9 = V_2 -> V_10 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
if ( V_2 -> V_12 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_2 -> V_14 [ V_3 ] -> V_7 = V_2 -> V_15 ;
V_2 -> V_14 [ V_3 ] -> V_9 = V_2 -> V_16 ;
V_2 -> V_17 [ V_3 ] = V_18 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_14 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
return V_4 ;
}
static void
F_3 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_5 ( V_22 -> V_25 , V_26 , sizeof( V_22 -> V_25 ) ) ;
F_5 ( V_22 -> V_27 , V_28 L_1 V_29 L_2 ,
sizeof( V_22 -> V_27 ) ) ;
snprintf ( V_22 -> V_30 , sizeof( V_22 -> V_30 ) ,
L_3 ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 >> 32 ) ,
( V_31 ) ( ( V_24 -> V_20 -> V_32 . V_33 >> 16 ) & 0xffff ) ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 & 0xffff ) ) ;
F_5 ( V_22 -> V_34 , F_6 ( V_24 -> V_20 -> V_35 -> V_36 ) ,
sizeof( V_22 -> V_34 ) ) ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_39 = 0 ;
}
static T_1 F_7 ( struct V_19 * V_20 )
{
return ( (struct V_1 * ) F_4 ( V_20 ) ) -> V_40 ;
}
static void F_8 ( struct V_19 * V_20 , T_1 V_41 )
{
( (struct V_1 * ) F_4 ( V_20 ) ) -> V_40 = V_41 ;
}
static void F_9 ( struct V_19 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_42 ) ;
int V_4 = 0 ;
T_2 V_45 = 0 ;
T_2 V_46 ;
if ( ( V_2 -> V_47 < 1 ) || ( V_2 -> V_47 > 2 ) ) {
F_10 ( V_2 , L_4 ) ;
return;
}
V_46 = ( V_2 -> V_47 == 1 ) ? V_48 :
V_49 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_46 ) ) {
V_44 -> V_51 = 0 ;
V_44 -> V_52 = 0 ;
return;
}
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_45 , V_2 -> V_47 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_4 ) ;
return;
}
if ( V_45 & V_53 )
V_44 -> V_51 = V_54 ;
else
V_44 -> V_51 = 0 ;
if ( V_45 & V_55 )
V_44 -> V_52 = V_54 ;
else
V_44 -> V_52 = 0 ;
}
static int F_12 ( struct V_19 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_42 ) ;
T_2 V_45 = 0 ;
int V_4 = 0 ;
T_2 V_46 ;
if ( ( V_2 -> V_47 < 1 ) || ( V_2 -> V_47 > 2 ) )
return - V_56 ;
V_46 = ( V_2 -> V_47 == 1 ) ? V_48 :
V_49 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_46 ) )
return - V_56 ;
if ( V_44 -> V_51 & ~ V_54 )
return - V_57 ;
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_45 , V_2 -> V_47 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_5 ) ;
return V_4 ;
}
if ( V_44 -> V_52 & V_54 ) {
V_45 |= V_58 | V_55 |
V_53 ;
} else {
V_45 &= ~ ( V_55 | V_53 ) ;
V_45 |= V_58 ;
}
V_4 = F_13 ( V_2 -> V_24 -> V_20 , V_45 , V_2 -> V_47 ) ;
if ( V_4 )
F_10 ( V_2 , L_6 ) ;
return V_4 ;
}
static inline void F_14 ( struct V_59 * V_60 ,
unsigned long * V_61 ,
int V_62 )
{
V_60 -> V_63 = 0 ;
V_60 -> V_64 = ! F_15 ( V_61 , V_62 ) ;
V_60 -> V_62 = V_60 -> V_64 ? F_16 ( V_61 , V_62 )
: V_62 ;
V_60 -> V_61 = V_61 ;
}
static inline int F_17 ( struct V_59 * V_60 )
{
return ! V_60 -> V_64 ? 1 : F_18 ( V_60 -> V_63 , V_60 -> V_61 ) ;
}
static inline int F_19 ( struct V_59 * V_60 )
{
return V_60 -> V_63 ++ ;
}
static inline unsigned int
F_20 ( struct V_59 * V_60 )
{
return V_60 -> V_62 ;
}
static int F_21 ( struct V_19 * V_20 , int V_65 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_59 V_66 ;
F_14 ( & V_66 , V_2 -> V_61 . V_67 , V_68 ) ;
switch ( V_65 ) {
case V_69 :
return F_20 ( & V_66 ) +
( V_2 -> V_5 * 2 ) +
#ifdef F_22
( V_2 -> V_13 * 5 ) ;
#else
( V_2 -> V_13 * 2 ) ;
#endif
case V_70 :
return V_71 - ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50
& V_72 ) * 2 ;
case V_73 :
return F_23 ( V_74 ) ;
default:
return - V_56 ;
}
}
static void F_24 ( struct V_19 * V_20 ,
struct V_75 * V_76 , T_3 * V_77 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_78 = 0 ;
int V_3 ;
struct V_59 V_66 ;
F_14 ( & V_66 , V_2 -> V_61 . V_67 , V_68 ) ;
F_25 ( & V_2 -> V_79 ) ;
for ( V_3 = 0 ; V_3 < V_80 ; V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] = ( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_81 ; V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] = ( ( unsigned long * ) & V_2 -> V_82 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_83 ;
V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] =
( ( T_2 * ) & V_2 -> V_84 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] = ( ( T_2 * ) & V_2 -> V_86 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_87 ;
V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] =
( ( T_2 * ) & V_2 -> V_88 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_89 ; V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] = ( ( T_2 * ) & V_2 -> V_90 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ , F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
V_77 [ V_78 ++ ] = ( ( unsigned long * ) & V_2 -> V_92 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_77 [ V_78 ++ ] = V_2 -> V_93 [ V_3 ] -> V_94 ;
V_77 [ V_78 ++ ] = V_2 -> V_93 [ V_3 ] -> V_95 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_77 [ V_78 ++ ] = V_2 -> V_96 [ V_3 ] -> V_94 ;
V_77 [ V_78 ++ ] = V_2 -> V_96 [ V_3 ] -> V_95 ;
#ifdef F_22
V_77 [ V_78 ++ ] = V_2 -> V_96 [ V_3 ] -> V_97 ;
V_77 [ V_78 ++ ] = V_2 -> V_96 [ V_3 ] -> V_98 ;
V_77 [ V_78 ++ ] = V_2 -> V_96 [ V_3 ] -> V_99 ;
#endif
}
F_26 ( & V_2 -> V_79 ) ;
}
static void F_27 ( struct V_19 * V_20 ,
struct V_100 * V_101 , T_2 * V_102 )
{
F_28 ( V_20 , & V_101 -> V_50 , V_102 ) ;
}
static void F_29 ( struct V_19 * V_20 ,
T_4 V_103 , T_5 * V_77 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_78 = 0 ;
int V_3 , V_104 = 0 ;
struct V_59 V_66 ;
F_14 ( & V_66 , V_2 -> V_61 . V_67 , V_68 ) ;
switch ( V_103 ) {
case V_70 :
for ( V_3 = 0 ; V_3 < V_71 - 2 ; V_3 ++ )
strcpy ( V_77 + V_3 * V_105 , V_106 [ V_3 ] ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_72 )
for (; V_3 < V_71 ; V_3 ++ )
strcpy ( V_77 + V_3 * V_105 , V_106 [ V_3 ] ) ;
break;
case V_69 :
for ( V_3 = 0 ; V_3 < V_80 ; V_3 ++ , V_104 ++ ,
F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
strcpy ( V_77 + ( V_78 ++ ) * V_105 ,
V_107 [ V_104 ] ) ;
for ( V_3 = 0 ; V_3 < V_81 ; V_3 ++ , V_104 ++ ,
F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
strcpy ( V_77 + ( V_78 ++ ) * V_105 ,
V_107 [ V_104 ] ) ;
for ( V_3 = 0 ; V_3 < V_108 ; V_3 ++ , V_104 ++ ,
F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
strcpy ( V_77 + ( V_78 ++ ) * V_105 ,
V_107 [ V_104 ] ) ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ , V_104 ++ ,
F_19 ( & V_66 ) )
if ( F_17 ( & V_66 ) )
strcpy ( V_77 + ( V_78 ++ ) * V_105 ,
V_107 [ V_104 ] ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_7 , V_3 ) ;
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_9 , V_3 ) ;
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_10 , V_3 ) ;
#ifdef F_22
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_11 , V_3 ) ;
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_12 , V_3 ) ;
sprintf ( V_77 + ( V_78 ++ ) * V_105 ,
L_13 , V_3 ) ;
#endif
}
break;
case V_73 :
for ( V_3 = 0 ; V_3 < F_23 ( V_74 ) ; V_3 ++ )
strcpy ( V_77 + V_3 * V_105 ,
V_74 [ V_3 ] ) ;
break;
}
}
static T_1 F_30 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_109 = V_110 ;
if ( ( V_24 -> V_20 -> V_32 . V_111 & V_112 ) &&
( V_2 -> V_113 . V_50 & V_114 ) )
V_109 = V_115 ;
return V_109 ;
}
static T_1 F_31 ( struct V_116 * V_117 )
{
T_1 V_118 = F_32 ( V_117 -> V_119 ) ;
if ( V_118 & ( F_33 ( V_120 )
| F_33 ( V_121 )
| F_33 ( V_122 ) ) ) {
return V_123 ;
}
if ( V_118 & ( F_33 ( V_124 )
| F_33 ( V_125 )
| F_33 ( V_126 )
| F_33 ( V_127 )
| F_33 ( V_128 )
| F_33 ( V_129 ) ) ) {
return V_130 ;
}
if ( V_118 & ( F_33 ( V_131 )
| F_33 ( V_132 )
| F_33 ( V_133 )
| F_33 ( V_134 )
| F_33 ( V_135 )
| F_33 ( V_136 ) ) ) {
return V_137 ;
}
return 0 ;
}
static T_1 F_34 ( struct V_116 * V_117 )
{
T_1 V_118 = F_32 ( V_117 -> V_138 ) ;
if ( ! V_118 )
V_118 = F_32 ( V_117 -> V_119 ) ;
if ( V_118 & ( F_33 ( V_120 )
| F_33 ( V_121 )
| F_33 ( V_122 ) ) ) {
return V_139 ;
}
if ( V_118 & ( F_33 ( V_125 )
| F_33 ( V_126 )
| F_33 ( V_128 )
| F_33 ( V_129 ) ) ) {
return V_140 ;
}
if ( V_118 & ( F_33 ( V_124 )
| F_33 ( V_141 )
| F_33 ( V_127 ) ) ) {
return V_142 ;
}
if ( V_118 & ( F_33 ( V_131 )
| F_33 ( V_132 )
| F_33 ( V_133 )
| F_33 ( V_134 )
| F_33 ( V_135 )
| F_33 ( V_136 ) ) ) {
return V_143 ;
}
return V_144 ;
}
static T_1 F_35 ( T_1 V_118 , enum V_145 V_146 )
{
int V_3 ;
T_1 V_147 = 0 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
if ( V_118 & F_33 ( V_3 ) )
V_147 |= V_149 [ V_3 ] [ V_146 ] ;
}
return V_147 ;
}
static T_1 F_36 ( T_1 V_147 , enum V_145 V_146 )
{
int V_3 ;
T_1 V_150 = 0 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
if ( V_149 [ V_3 ] [ V_146 ] & V_147 )
V_150 |= 1 << V_3 ;
}
return V_150 ;
}
static T_1 F_37 ( T_1 V_151 )
{
int V_3 ;
T_1 V_150 = 0 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
if ( V_149 [ V_3 ] [ V_152 ] == V_151 )
V_150 |= 1 << V_3 ;
}
return V_150 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_116 V_117 ;
T_1 V_118 ;
int V_155 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_156 = V_2 -> V_47 ;
V_117 . V_157 = V_158 ;
V_155 = F_39 ( V_2 -> V_24 -> V_20 ,
V_159 , & V_117 ) ;
if ( V_155 ) {
F_40 ( V_2 , L_14 ,
V_155 ) ;
return V_155 ;
}
F_41 ( V_160 , V_2 , L_15 ,
V_117 . V_157 ) ;
F_41 ( V_160 , V_2 , L_16 ,
F_32 ( V_117 . V_119 ) ) ;
F_41 ( V_160 , V_2 , L_17 ,
F_32 ( V_117 . V_161 ) ) ;
F_41 ( V_160 , V_2 , L_18 ,
F_32 ( V_117 . V_138 ) ) ;
F_41 ( V_160 , V_2 , L_19 ,
F_32 ( V_117 . V_162 ) ) ;
V_154 -> V_51 = 0 ;
V_154 -> V_163 = 0 ;
V_154 -> V_51 |= F_31 ( & V_117 ) ;
V_118 = F_32 ( V_117 . V_119 ) ;
V_154 -> V_51 |= F_35 ( V_118 , V_164 ) ;
V_118 = F_32 ( V_117 . V_161 ) ;
V_154 -> V_163 |= F_35 ( V_118 , V_165 ) ;
V_154 -> V_51 |= V_166 | V_167 ;
V_154 -> V_163 |= ( V_2 -> V_168 -> V_169 ) ? V_170 : 0 ;
V_154 -> V_163 |= ( V_2 -> V_168 -> V_169 ^ V_2 -> V_168 -> V_171 ) ?
V_172 : 0 ;
V_154 -> V_47 = F_34 ( & V_117 ) ;
V_154 -> V_173 = ( V_123 & V_154 -> V_51 ) ?
V_174 : V_175 ;
if ( F_30 ( V_20 ) ) {
V_154 -> V_51 |= V_176 ;
V_154 -> V_163 |= V_177 ;
}
V_154 -> V_109 = ( V_2 -> V_113 . V_50 & V_178 ) ?
V_115 : V_110 ;
V_118 = F_32 ( V_117 . V_162 ) ;
V_154 -> V_179 = F_35 ( V_118 , V_165 ) ;
V_154 -> V_179 |= ( V_2 -> V_113 . V_50 & V_178 ) ?
V_177 : 0 ;
V_154 -> V_180 = 0 ;
V_154 -> V_181 = 0 ;
V_154 -> V_182 = 0 ;
V_154 -> V_183 = 0 ;
V_154 -> V_184 = V_185 ;
V_154 -> V_186 = V_187 ;
return V_155 ;
}
static void F_42 ( struct V_19 * V_20 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_188 ;
V_154 -> V_109 = V_110 ;
V_154 -> V_51 = V_189 ;
V_154 -> V_163 = V_190 ;
V_188 = V_2 -> V_113 . V_173 ;
if ( V_188 > 0 && V_188 <= 0xC ) {
V_154 -> V_47 = V_140 ;
V_154 -> V_173 = V_174 ;
V_154 -> V_51 |= V_130 ;
V_154 -> V_163 |= V_191 ;
} else if ( V_188 == 0x80 || V_188 == 0 ) {
V_154 -> V_47 = V_139 ;
V_154 -> V_173 = V_175 ;
V_154 -> V_51 |= V_123 ;
V_154 -> V_163 |= V_192 ;
} else {
V_154 -> V_47 = - 1 ;
V_154 -> V_173 = - 1 ;
}
}
static int F_43 ( struct V_19 * V_20 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_155 = - V_57 ;
if ( F_44 ( V_2 -> V_24 , V_2 -> V_47 ) )
return - V_193 ;
F_41 ( V_160 , V_2 , L_20 ,
V_2 -> V_113 . V_50 & V_178 ,
V_2 -> V_113 . V_50 & V_114 ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_111 & V_194 )
V_155 = F_38 ( V_20 , V_154 ) ;
if ( V_155 )
F_42 ( V_20 , V_154 ) ;
if ( F_45 ( V_20 ) ) {
F_46 ( V_154 , V_2 -> V_113 . V_195 ) ;
V_154 -> V_196 = V_197 ;
} else {
F_46 ( V_154 , V_198 ) ;
V_154 -> V_196 = V_199 ;
}
return 0 ;
}
static T_6 F_47 ( struct V_1 * V_2 , T_1 V_151 ,
T_6 V_200 )
{
T_6 V_201 = 0 ;
if ( ! V_151 ) {
V_201 = V_200 ;
F_48 ( V_2 , L_21 ,
F_32 ( V_200 ) ) ;
} else {
T_1 V_202 = F_37 ( V_151 ) ;
V_201 = F_49 ( V_202 ) & V_200 ;
F_48 ( V_2 , L_22 , V_151 ) ;
}
return V_201 ;
}
static int F_50 ( struct V_19 * V_20 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_116 V_117 ;
T_6 V_201 ;
int V_155 ;
T_1 V_203 = F_36 ( V_154 -> V_163 , V_165 ) ;
int V_151 = F_51 ( V_154 ) ;
F_41 ( V_160 , V_2 , L_23 ,
V_151 , V_154 -> V_163 , V_154 -> V_109 , V_154 -> V_196 ) ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_111 & V_194 ) ||
( V_154 -> V_196 == V_204 ) )
return - V_57 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_156 = V_2 -> V_47 ;
V_117 . V_157 = V_158 ;
V_155 = F_39 ( V_2 -> V_24 -> V_20 ,
V_159 , & V_117 ) ;
if ( V_155 ) {
F_40 ( V_2 , L_24 ,
V_155 ) ;
return 0 ;
}
V_201 = V_154 -> V_109 == V_115 ?
F_49 ( V_203 ) :
F_47 ( V_2 , V_151 ,
V_117 . V_119 ) ;
V_201 &= V_117 . V_119 ;
if ( ! V_201 ) {
F_40 ( V_2 , L_25 ) ;
return - V_57 ;
}
if ( V_201 == V_117 . V_161 )
return 0 ;
F_41 ( V_160 , V_2 , L_26 ,
F_32 ( V_201 ) ) ;
V_117 . V_161 = V_201 ;
V_155 = F_39 ( V_2 -> V_24 -> V_20 , V_205 ,
& V_117 ) ;
if ( V_155 ) {
F_40 ( V_2 , L_27 ,
F_32 ( V_117 . V_161 ) , V_155 ) ;
return V_155 ;
}
F_52 ( & V_2 -> V_24 -> V_206 ) ;
if ( V_2 -> V_11 ) {
F_40 ( V_2 , L_28 ) ;
F_53 ( V_20 , 1 ) ;
if ( F_54 ( V_20 ) )
F_10 ( V_2 , L_29 , V_2 -> V_47 ) ;
}
F_55 ( & V_2 -> V_24 -> V_206 ) ;
return 0 ;
}
static int F_56 ( struct V_19 * V_20 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_208 -> V_209 = V_2 -> V_10 ;
V_208 -> V_210 = V_2 -> V_8 ;
V_208 -> V_211 = V_2 -> V_212 ;
V_208 -> V_213 = V_2 -> V_16 ;
V_208 -> V_214 = V_2 -> V_15 ;
V_208 -> V_215 = V_2 -> V_215 ;
V_208 -> V_216 = V_2 -> V_217 ;
V_208 -> V_218 = V_2 -> V_218 ;
V_208 -> V_219 = V_2 -> V_220 ;
V_208 -> V_221 = V_2 -> V_222 ;
V_208 -> V_223 = V_2 -> V_12 ;
return 0 ;
}
static int F_57 ( struct V_19 * V_20 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ! V_208 -> V_211 )
return - V_57 ;
V_2 -> V_15 = ( V_208 -> V_214 ==
V_18 ) ?
V_224 :
V_208 -> V_214 ;
V_2 -> V_16 = ( V_208 -> V_213 ==
V_18 ) ?
V_225 :
V_208 -> V_213 ;
if ( V_208 -> V_209 != V_2 -> V_10 ||
V_208 -> V_210 != V_2 -> V_8 ) {
V_2 -> V_10 = V_208 -> V_209 ;
V_2 -> V_8 = V_208 -> V_210 ;
}
V_2 -> V_215 = V_208 -> V_215 ;
V_2 -> V_217 = V_208 -> V_216 ;
V_2 -> V_218 = V_208 -> V_218 ;
V_2 -> V_220 = V_208 -> V_219 ;
V_2 -> V_222 = V_208 -> V_221 ;
V_2 -> V_12 = V_208 -> V_223 ;
V_2 -> V_212 = V_208 -> V_211 ;
return F_1 ( V_2 ) ;
}
static int F_58 ( struct V_19 * V_20 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 ;
if ( V_227 -> V_109 )
return - V_57 ;
V_2 -> V_168 -> V_169 = V_227 -> V_169 != 0 ;
V_2 -> V_168 -> V_171 = V_227 -> V_171 != 0 ;
V_4 = F_59 ( V_24 -> V_20 , V_2 -> V_47 ,
V_2 -> V_228 + V_229 ,
V_2 -> V_168 -> V_169 ,
V_2 -> V_168 -> V_230 ,
V_2 -> V_168 -> V_171 ,
V_2 -> V_168 -> V_231 ) ;
if ( V_4 )
F_10 ( V_2 , L_30 ) ;
else
F_60 ( V_24 -> V_20 , & V_2 -> V_61 ,
V_2 -> V_168 -> V_231 ,
V_2 -> V_168 -> V_171 ,
V_2 -> V_168 -> V_230 ,
V_2 -> V_168 -> V_169 ) ;
return V_4 ;
}
static void F_61 ( struct V_19 * V_20 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_227 -> V_169 = V_2 -> V_168 -> V_169 ;
V_227 -> V_171 = V_2 -> V_168 -> V_171 ;
}
static int F_62 ( struct V_19 * V_20 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_234 , V_235 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_233 -> V_236 || V_233 -> V_237 )
return - V_57 ;
V_234 = F_63 ( V_233 -> V_238 ) ;
V_234 = F_64 ( T_1 , V_234 , V_239 ) ;
V_234 = F_65 ( T_1 , V_234 , V_240 ) ;
V_235 = F_63 ( V_233 -> V_241 ) ;
V_235 = F_64 ( T_1 , V_235 , V_242 ) ;
V_235 = F_65 ( T_1 , V_235 , V_243 ) ;
if ( V_234 == ( V_2 -> V_11 ? V_2 -> V_96 [ 0 ] -> V_244 :
V_2 -> V_96 [ 0 ] -> V_245 ) &&
V_235 == V_2 -> V_93 [ 0 ] -> V_245 )
return 0 ;
F_52 ( & V_24 -> V_206 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_53 ( V_20 , 1 ) ;
}
F_66 ( V_2 ) ;
V_2 -> V_168 -> V_246 = V_235 ;
V_2 -> V_168 -> V_247 = V_234 ;
V_4 = F_67 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_248;
}
if ( V_11 ) {
V_4 = F_54 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_248:
F_55 ( & V_24 -> V_206 ) ;
return V_4 ;
}
static void F_68 ( struct V_19 * V_20 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_233 -> V_249 = V_240 ;
V_233 -> V_250 = V_243 ;
V_233 -> V_238 = V_2 -> V_11 ?
V_2 -> V_96 [ 0 ] -> V_244 : V_2 -> V_96 [ 0 ] -> V_245 ;
V_233 -> V_241 = V_2 -> V_93 [ 0 ] -> V_245 ;
}
static T_1 F_69 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_13 ;
}
static T_1 F_70 ( struct V_19 * V_42 )
{
return V_251 ;
}
static int F_71 ( struct V_19 * V_20 , T_7 V_252 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_252 == V_253 ) {
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_111 & V_254 ) )
return - V_57 ;
if ( ! ( V_20 -> V_255 & V_256 ) )
F_40 ( V_2 , L_33 ) ;
return 0 ;
} else if ( V_252 == V_257 ) {
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_111 & V_258 ) )
return - V_57 ;
if ( V_20 -> V_255 & V_256 )
F_40 ( V_2 , L_34 ) ;
return 0 ;
}
return - V_57 ;
}
static int F_72 ( struct V_19 * V_20 , T_1 * V_259 , T_7 * V_260 ,
T_7 * V_252 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_261 * V_262 = & V_2 -> V_262 ;
int V_263 ;
T_8 V_264 = V_2 -> V_13 ;
int V_4 = 0 ;
V_263 = V_2 -> V_168 -> V_263 ? : V_2 -> V_13 ;
V_263 = 1 << F_73 ( V_263 ) ;
while ( V_264 -- ) {
if ( ! V_259 )
break;
V_259 [ V_264 ] = V_262 -> V_265 [ V_264 % V_263 ] . V_266 -
V_262 -> V_267 ;
}
if ( V_260 )
memcpy ( V_260 , V_2 -> V_268 , V_251 ) ;
if ( V_252 )
* V_252 = V_2 -> V_269 ;
return V_4 ;
}
static int F_74 ( struct V_19 * V_20 , const T_1 * V_259 ,
const T_7 * V_260 , const T_7 V_252 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_263 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
if ( ! V_259 )
continue;
if ( V_3 > 0 && ! V_259 [ V_3 ] && ! V_263 )
V_263 = V_3 ;
if ( V_259 [ V_3 ] != ( V_3 % ( V_263 ? : V_2 -> V_13 ) ) )
return - V_57 ;
}
if ( ! V_263 )
V_263 = V_2 -> V_13 ;
if ( ! F_75 ( V_263 ) )
return - V_57 ;
if ( V_252 != V_270 ) {
V_4 = F_71 ( V_20 , V_252 ) ;
if ( V_4 )
return V_4 ;
}
F_52 ( & V_24 -> V_206 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_53 ( V_20 , 1 ) ;
}
if ( V_259 )
V_2 -> V_168 -> V_263 = V_263 ;
if ( V_260 )
memcpy ( V_2 -> V_268 , V_260 , V_251 ) ;
if ( V_252 != V_270 )
V_2 -> V_269 = V_252 ;
if ( V_11 ) {
V_4 = F_54 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
F_55 ( & V_24 -> V_206 ) ;
return V_4 ;
}
static int F_76 ( struct V_19 * V_20 ,
struct V_271 * V_154 )
{
struct V_272 * V_273 ;
struct V_274 * V_275 ;
struct V_276 * V_277 ;
if ( V_154 -> V_278 . V_279 >= V_280 )
return - V_57 ;
if ( V_154 -> V_278 . V_281 & V_282 ) {
if ( ! F_77 ( V_154 -> V_278 . V_283 . V_284 ) )
return - V_57 ;
}
switch ( V_154 -> V_278 . V_281 & ~ ( V_285 | V_282 ) ) {
case V_286 :
case V_287 :
if ( V_154 -> V_278 . V_288 . V_289 . V_290 )
return - V_57 ;
V_275 = & V_154 -> V_278 . V_288 . V_289 ;
if ( ! F_78 ( V_275 -> V_291 ) ||
! F_78 ( V_275 -> V_292 ) ||
! F_78 ( V_275 -> V_293 ) ||
! F_78 ( V_275 -> V_294 ) )
return - V_57 ;
break;
case V_295 :
V_273 = & V_154 -> V_278 . V_288 . V_296 ;
if ( V_273 -> V_297 || V_273 -> V_290 || V_273 -> V_298 ||
V_154 -> V_278 . V_299 . V_296 . V_300 != V_301 ||
( ! V_273 -> V_291 && ! V_273 -> V_292 ) ||
! F_78 ( V_273 -> V_291 ) ||
! F_78 ( V_273 -> V_292 ) )
return - V_57 ;
break;
case V_302 :
V_277 = & V_154 -> V_278 . V_288 . V_303 ;
if ( ! F_79 ( V_277 -> V_304 ) )
return - V_57 ;
if ( ! F_77 ( V_277 -> V_284 ) )
return - V_57 ;
if ( ! F_78 ( V_277 -> V_305 ) )
return - V_57 ;
break;
default:
return - V_57 ;
}
if ( ( V_154 -> V_278 . V_281 & V_285 ) ) {
if ( V_154 -> V_278 . V_283 . V_306 ||
! ( ( V_154 -> V_278 . V_283 . V_307 & F_80 ( V_308 ) ) ==
0 ||
( V_154 -> V_278 . V_283 . V_307 & F_80 ( V_308 ) ) ==
F_80 ( V_308 ) ) )
return - V_57 ;
if ( V_154 -> V_278 . V_283 . V_307 ) {
if ( F_81 ( V_154 -> V_278 . V_309 . V_307 ) >= V_310 )
return - V_57 ;
}
}
return 0 ;
}
static int F_82 ( struct V_271 * V_154 ,
struct V_311 * V_312 ,
struct V_313 * V_314 ,
unsigned char * V_315 )
{
int V_4 = 0 ;
T_9 V_316 = F_83 ( V_317 << 16 ) ;
V_314 -> V_318 = V_319 ;
memcpy ( V_314 -> V_320 . V_321 , & V_316 , V_322 ) ;
memcpy ( V_314 -> V_320 . V_323 , V_315 , V_322 ) ;
if ( ( V_154 -> V_278 . V_281 & V_285 ) &&
( V_154 -> V_278 . V_283 . V_307 & F_80 ( V_308 ) ) ) {
V_314 -> V_320 . V_324 = V_154 -> V_278 . V_309 . V_307 ;
V_314 -> V_320 . V_325 = F_80 ( V_308 ) ;
}
F_84 ( & V_314 -> V_326 , V_312 ) ;
return V_4 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_271 * V_154 ,
struct V_311 * V_312 ,
struct V_313 * V_314 ,
T_6 V_327 )
{
#ifdef F_86
unsigned char V_315 [ V_322 ] ;
if ( ! F_87 ( V_327 ) ) {
if ( V_154 -> V_278 . V_281 & V_282 )
memcpy ( & V_315 , V_154 -> V_278 . V_309 . V_284 , V_322 ) ;
else
memcpy ( & V_315 , V_2 -> V_20 -> V_328 , V_322 ) ;
} else {
F_88 ( V_327 , V_315 ) ;
}
return F_82 ( V_154 , V_312 , V_314 , & V_315 [ 0 ] ) ;
#else
return - V_57 ;
#endif
}
static int F_89 ( struct V_1 * V_2 ,
struct V_271 * V_154 ,
struct V_311 * V_329 )
{
int V_4 ;
struct V_313 * V_314 = NULL ;
struct V_313 * V_330 = NULL ;
struct V_272 * V_273 = & V_154 -> V_278 . V_288 . V_296 ;
V_330 = F_90 ( sizeof( * V_330 ) , V_331 ) ;
V_314 = F_90 ( sizeof( * V_314 ) , V_331 ) ;
if ( ! V_314 || ! V_330 ) {
V_4 = - V_193 ;
goto V_332;
}
V_4 = F_85 ( V_2 , V_154 , V_329 , V_314 ,
V_154 -> V_278 . V_299 .
V_296 . V_292 ) ;
if ( V_4 )
goto V_332;
V_330 -> V_318 = V_333 ;
V_330 -> V_334 . V_335 = V_154 -> V_278 . V_299 . V_296 . V_291 ;
if ( V_273 -> V_291 )
V_330 -> V_334 . V_336 = V_337 ;
V_330 -> V_334 . V_338 = V_154 -> V_278 . V_299 . V_296 . V_292 ;
if ( V_273 -> V_292 )
V_330 -> V_334 . V_339 = V_337 ;
F_84 ( & V_330 -> V_326 , V_329 ) ;
return 0 ;
V_332:
F_91 ( V_314 ) ;
F_91 ( V_330 ) ;
return V_4 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_271 * V_154 ,
struct V_311 * V_329 , int V_298 )
{
int V_4 ;
struct V_313 * V_314 = NULL ;
struct V_313 * V_330 = NULL ;
struct V_313 * V_340 = NULL ;
struct V_274 * V_275 = & V_154 -> V_278 . V_288 . V_289 ;
V_314 = F_90 ( sizeof( * V_314 ) , V_331 ) ;
V_330 = F_90 ( sizeof( * V_330 ) , V_331 ) ;
V_340 = F_90 ( sizeof( * V_340 ) , V_331 ) ;
if ( ! V_314 || ! V_330 || ! V_340 ) {
V_4 = - V_193 ;
goto V_332;
}
V_330 -> V_318 = V_333 ;
if ( V_298 == V_286 ) {
V_4 = F_85 ( V_2 , V_154 , V_329 ,
V_314 ,
V_154 -> V_278 . V_299 .
V_289 . V_292 ) ;
if ( V_4 )
goto V_332;
V_340 -> V_318 = V_341 ;
V_330 -> V_334 . V_335 = V_154 -> V_278 . V_299 . V_289 . V_291 ;
V_330 -> V_334 . V_338 = V_154 -> V_278 . V_299 . V_289 . V_292 ;
V_340 -> V_342 . V_343 = V_154 -> V_278 . V_299 . V_289 . V_293 ;
V_340 -> V_342 . V_344 = V_154 -> V_278 . V_299 . V_289 . V_294 ;
} else {
V_4 = F_85 ( V_2 , V_154 , V_329 ,
V_314 ,
V_154 -> V_278 . V_299 .
V_345 . V_292 ) ;
if ( V_4 )
goto V_332;
V_340 -> V_318 = V_346 ;
V_330 -> V_334 . V_335 = V_154 -> V_278 . V_299 . V_345 . V_291 ;
V_330 -> V_334 . V_338 = V_154 -> V_278 . V_299 . V_345 . V_292 ;
V_340 -> V_342 . V_343 = V_154 -> V_278 . V_299 . V_345 . V_293 ;
V_340 -> V_342 . V_344 = V_154 -> V_278 . V_299 . V_345 . V_294 ;
}
if ( V_275 -> V_291 )
V_330 -> V_334 . V_336 = V_337 ;
if ( V_275 -> V_292 )
V_330 -> V_334 . V_339 = V_337 ;
if ( V_275 -> V_293 )
V_340 -> V_342 . V_347 = V_348 ;
if ( V_275 -> V_294 )
V_340 -> V_342 . V_349 = V_348 ;
F_84 ( & V_330 -> V_326 , V_329 ) ;
F_84 ( & V_340 -> V_326 , V_329 ) ;
return 0 ;
V_332:
F_91 ( V_314 ) ;
F_91 ( V_330 ) ;
F_91 ( V_340 ) ;
return V_4 ;
}
static int F_93 ( struct V_19 * V_20 ,
struct V_271 * V_154 ,
struct V_311 * V_312 )
{
int V_4 ;
struct V_276 * V_350 ;
struct V_313 * V_314 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_4 = F_76 ( V_20 , V_154 ) ;
if ( V_4 )
return V_4 ;
switch ( V_154 -> V_278 . V_281 & ~ ( V_285 | V_282 ) ) {
case V_302 :
V_314 = F_90 ( sizeof( * V_314 ) , V_331 ) ;
if ( ! V_314 )
return - V_193 ;
V_350 = & V_154 -> V_278 . V_299 . V_303 ;
F_82 ( V_154 , V_312 , V_314 ,
& V_350 -> V_284 [ 0 ] ) ;
V_314 -> V_320 . V_351 = V_350 -> V_305 ;
if ( V_350 -> V_305 )
V_314 -> V_320 . V_352 = 1 ;
break;
case V_295 :
V_4 = F_89 ( V_2 , V_154 , V_312 ) ;
break;
case V_286 :
V_4 = F_92 ( V_2 , V_154 , V_312 , V_286 ) ;
break;
case V_287 :
V_4 = F_92 ( V_2 , V_154 , V_312 , V_287 ) ;
break;
}
return V_4 ;
}
static int F_94 ( struct V_19 * V_20 ,
struct V_271 * V_154 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_353 * V_354 ;
struct V_313 * V_355 , * V_356 ;
T_1 V_266 ;
T_2 V_357 ;
struct V_358 V_359 = {
. V_360 = V_361 ,
. V_362 = 0 ,
. V_363 = 1 ,
. V_364 = V_365 ,
} ;
V_359 . V_47 = V_2 -> V_47 ;
V_359 . V_366 = V_367 | V_154 -> V_278 . V_279 ;
F_95 ( & V_359 . V_326 ) ;
if ( V_154 -> V_278 . V_368 == V_369 )
V_266 = V_2 -> V_370 . V_266 ;
else if ( V_154 -> V_278 . V_368 & V_371 ) {
V_266 = V_154 -> V_278 . V_368 & ( V_371 - 1 ) ;
} else {
if ( V_154 -> V_278 . V_368 >= V_2 -> V_13 ) {
F_40 ( V_2 , L_35 ,
V_154 -> V_278 . V_368 ) ;
return - V_57 ;
}
V_266 = V_2 -> V_262 . V_265 [ V_154 -> V_278 . V_368 ] . V_266 ;
if ( ! V_266 ) {
F_40 ( V_2 , L_36 ,
V_154 -> V_278 . V_368 ) ;
return - V_57 ;
}
}
V_359 . V_266 = V_266 ;
V_4 = F_93 ( V_20 , V_154 , & V_359 . V_326 ) ;
if ( V_4 )
goto V_372;
V_354 = & V_2 -> V_373 [ V_154 -> V_278 . V_279 ] ;
if ( V_354 -> V_318 ) {
V_4 = F_96 ( V_2 -> V_24 -> V_20 , V_354 -> V_318 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_37 ,
V_154 -> V_278 . V_279 , V_354 -> V_318 ) ;
goto V_372;
}
V_354 -> V_318 = 0 ;
memset ( & V_354 -> V_374 , 0 ,
sizeof( struct V_375 ) ) ;
F_97 ( & V_354 -> V_326 ) ;
}
V_4 = F_98 ( V_2 -> V_24 -> V_20 , & V_359 , & V_357 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_38 ,
V_154 -> V_278 . V_279 ) ;
goto V_372;
}
V_354 -> V_318 = V_357 ;
memcpy ( & V_354 -> V_374 , & V_154 -> V_278 ,
sizeof( struct V_375 ) ) ;
F_84 ( & V_354 -> V_326 , & V_2 -> V_376 ) ;
V_372:
F_99 (spec, tmp_spec, &rule.list, list) {
F_97 ( & V_355 -> V_326 ) ;
F_91 ( V_355 ) ;
}
return V_4 ;
}
static int F_100 ( struct V_19 * V_20 ,
struct V_271 * V_154 )
{
int V_4 = 0 ;
struct V_353 * V_359 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_154 -> V_278 . V_279 >= V_280 )
return - V_57 ;
V_359 = & V_2 -> V_373 [ V_154 -> V_278 . V_279 ] ;
if ( ! V_359 -> V_318 ) {
V_4 = - V_377 ;
goto V_248;
}
V_4 = F_96 ( V_2 -> V_24 -> V_20 , V_359 -> V_318 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_39 ,
V_154 -> V_278 . V_279 , V_359 -> V_318 ) ;
goto V_248;
}
V_359 -> V_318 = 0 ;
memset ( & V_359 -> V_374 , 0 , sizeof( struct V_375 ) ) ;
F_97 ( & V_359 -> V_326 ) ;
V_248:
return V_4 ;
}
static int F_101 ( struct V_19 * V_20 , struct V_271 * V_154 ,
int V_378 )
{
int V_4 = 0 ;
struct V_353 * V_359 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_378 < 0 || V_378 >= V_280 )
return - V_57 ;
V_359 = & V_2 -> V_373 [ V_378 ] ;
if ( V_359 -> V_318 )
memcpy ( & V_154 -> V_278 , & V_359 -> V_374 ,
sizeof( struct V_375 ) ) ;
else
V_4 = - V_377 ;
return V_4 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_3 , V_379 = 0 ;
for ( V_3 = 0 ; V_3 < V_280 ; V_3 ++ ) {
if ( V_2 -> V_373 [ V_3 ] . V_318 )
V_379 ++ ;
}
return V_379 ;
}
static int F_103 ( struct V_19 * V_20 , struct V_271 * V_154 ,
T_1 * V_380 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 = 0 ;
int V_3 = 0 , V_366 = 0 ;
if ( ( V_154 -> V_154 == V_381 ||
V_154 -> V_154 == V_382 ||
V_154 -> V_154 == V_383 ) &&
( V_24 -> V_20 -> V_32 . V_384 !=
V_385 || ! V_2 -> V_11 ) )
return - V_57 ;
switch ( V_154 -> V_154 ) {
case V_386 :
V_154 -> V_77 = V_2 -> V_13 ;
break;
case V_381 :
V_154 -> V_387 = F_102 ( V_2 ) ;
break;
case V_382 :
V_4 = F_101 ( V_20 , V_154 , V_154 -> V_278 . V_279 ) ;
break;
case V_383 :
while ( ( ! V_4 || V_4 == - V_377 ) && V_366 < V_154 -> V_387 ) {
V_4 = F_101 ( V_20 , V_154 , V_3 ) ;
if ( ! V_4 )
V_380 [ V_366 ++ ] = V_3 ;
V_3 ++ ;
}
V_4 = 0 ;
break;
default:
V_4 = - V_56 ;
break;
}
return V_4 ;
}
static int F_104 ( struct V_19 * V_20 , struct V_271 * V_154 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_24 -> V_20 -> V_32 . V_384 !=
V_385 || ! V_2 -> V_11 )
return - V_57 ;
switch ( V_154 -> V_154 ) {
case V_388 :
V_4 = F_94 ( V_20 , V_154 ) ;
break;
case V_389 :
V_4 = F_100 ( V_20 , V_154 ) ;
break;
default:
F_40 ( V_2 , L_40 , V_154 -> V_154 ) ;
return - V_57 ;
}
return V_4 ;
}
static void F_105 ( struct V_19 * V_20 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_391 , 0 , sizeof( * V_391 ) ) ;
V_391 -> V_392 = V_393 ;
V_391 -> V_394 = V_395 ;
V_391 -> V_396 = V_2 -> V_13 ;
V_391 -> V_397 = V_2 -> V_5 / V_398 ;
}
static int F_106 ( struct V_19 * V_20 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_391 -> V_399 || V_391 -> V_400 ||
V_391 -> V_397 > V_395 ||
V_391 -> V_396 > V_393 ||
! V_391 -> V_397 || ! V_391 -> V_396 )
return - V_57 ;
F_52 ( & V_24 -> V_206 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_53 ( V_20 , 1 ) ;
}
F_66 ( V_2 ) ;
V_2 -> V_401 = V_391 -> V_397 ;
V_2 -> V_5 = V_391 -> V_397 * V_398 ;
V_2 -> V_13 = V_391 -> V_396 ;
V_4 = F_67 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_248;
}
F_107 ( V_20 , V_2 -> V_5 ) ;
F_108 ( V_20 , V_2 -> V_13 ) ;
if ( V_20 -> V_402 )
F_109 ( V_20 , V_398 ) ;
F_40 ( V_2 , L_41 , V_2 -> V_5 ) ;
F_40 ( V_2 , L_42 , V_2 -> V_13 ) ;
if ( V_11 ) {
V_4 = F_54 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_248:
F_55 ( & V_24 -> V_206 ) ;
return V_4 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_403 * V_404 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_155 ;
V_155 = F_111 ( V_20 , V_404 ) ;
if ( V_155 )
return V_155 ;
if ( V_24 -> V_20 -> V_32 . V_111 & V_405 ) {
V_404 -> V_406 |=
V_407 |
V_408 |
V_409 ;
V_404 -> V_410 =
( 1 << V_411 ) |
( 1 << V_412 ) ;
V_404 -> V_413 =
( 1 << V_414 ) |
( 1 << V_415 ) ;
if ( V_24 -> V_416 )
V_404 -> V_417 = F_112 ( V_24 -> V_416 ) ;
}
return V_155 ;
}
static int F_113 ( struct V_19 * V_20 , T_1 V_50 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
bool V_418 = ! ! ( V_50 & V_419 ) ;
bool V_420 = ! ! ( V_2 -> V_421 & V_419 ) ;
int V_3 ;
if ( V_418 == V_420 )
return 0 ;
if ( V_418 ) {
bool V_422 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_422 &= V_2 -> V_93 [ V_3 ] -> V_423 ;
if ( ! V_422 ) {
F_10 ( V_2 , L_43 ) ;
return - V_57 ;
}
V_2 -> V_421 |= V_419 ;
} else {
V_2 -> V_421 &= ~ V_419 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_2 -> V_93 [ V_3 ] -> V_424 = V_418 ;
F_48 ( V_2 , L_44 ,
V_418 ? L_45 : L_46 ) ;
return 0 ;
}
static T_1 F_114 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_421 ;
}
static int F_115 ( struct V_19 * V_20 ,
const struct V_425 * V_426 ,
void * V_77 )
{
const struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_155 = 0 ;
switch ( V_426 -> V_318 ) {
case V_427 :
* ( T_1 * ) V_77 = V_2 -> V_168 -> V_428 ;
break;
default:
V_155 = - V_57 ;
break;
}
return V_155 ;
}
static int F_116 ( struct V_19 * V_20 ,
const struct V_425 * V_426 ,
const void * V_77 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_41 , V_155 = 0 ;
switch ( V_426 -> V_318 ) {
case V_427 :
V_41 = * ( T_1 * ) V_77 ;
if ( V_41 < V_429 || V_41 > V_430 )
V_155 = - V_57 ;
else
V_2 -> V_168 -> V_428 = V_41 ;
break;
default:
V_155 = - V_57 ;
break;
}
return V_155 ;
}
static int F_117 ( struct V_19 * V_20 ,
struct V_431 * V_432 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_155 ;
T_7 V_77 [ 4 ] ;
V_155 = F_118 ( V_24 -> V_20 , V_2 -> V_47 ,
0 , 2 , V_77 ) ;
if ( V_155 < 2 )
return - V_433 ;
switch ( V_77 [ 0 ] ) {
case V_434 :
V_432 -> type = V_435 ;
V_432 -> V_436 = V_437 ;
break;
case V_438 :
if ( V_77 [ 1 ] >= 0x3 ) {
V_432 -> type = V_439 ;
V_432 -> V_436 = V_440 ;
} else {
V_432 -> type = V_435 ;
V_432 -> V_436 = V_437 ;
}
break;
case V_441 :
V_432 -> type = V_439 ;
V_432 -> V_436 = V_440 ;
break;
case V_442 :
V_432 -> type = V_443 ;
V_432 -> V_436 = V_444 ;
break;
default:
return - V_445 ;
}
return 0 ;
}
static int F_119 ( struct V_19 * V_20 ,
struct V_446 * V_447 ,
T_7 * V_77 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_448 = V_447 -> V_448 ;
int V_3 = 0 , V_155 ;
if ( V_447 -> V_449 == 0 )
return - V_57 ;
memset ( V_77 , 0 , V_447 -> V_449 ) ;
while ( V_3 < V_447 -> V_449 ) {
F_41 ( V_160 , V_2 ,
L_47 ,
V_3 , V_448 , V_447 -> V_449 - V_3 ) ;
V_155 = F_118 ( V_24 -> V_20 , V_2 -> V_47 ,
V_448 , V_447 -> V_449 - V_3 , V_77 + V_3 ) ;
if ( ! V_155 )
return 0 ;
if ( V_155 < 0 ) {
F_10 ( V_2 ,
L_48 ,
V_3 , V_448 , V_447 -> V_449 - V_3 , V_155 ) ;
return 0 ;
}
V_3 += V_155 ;
V_448 += V_155 ;
}
return 0 ;
}
static int F_120 ( struct V_19 * V_20 ,
enum V_450 V_451 )
{
int V_4 ;
V_31 V_452 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( ! ( V_24 -> V_20 -> V_32 . V_111 & V_453 ) )
return - V_56 ;
switch ( V_451 ) {
case V_454 :
V_452 = V_455 ;
break;
case V_456 :
V_452 = 0 ;
break;
default:
return - V_56 ;
}
V_4 = F_121 ( V_24 -> V_20 , V_2 -> V_47 , V_452 ) ;
return V_4 ;
}
