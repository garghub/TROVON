void F_1 ( unsigned int V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 , * V_6 ;
unsigned long V_7 ;
int V_8 = 0 ;
F_2 ( & V_9 , V_7 ) ;
V_6 = & V_10 ;
F_3 (pos, head) {
struct V_11 * V_12 = F_4 ( V_5 ,
struct V_11 , V_13 ) ;
if ( ! ( V_12 -> V_1 . V_1 & V_1 ) )
continue;
V_12 -> V_1 . V_1 = V_1 ;
V_12 -> V_1 . V_14 = V_2 + 1 ;
V_12 -> V_1 . V_15 = V_3 + 1 ;
V_8 = 1 ;
V_12 -> V_16 = 1 ;
}
F_5 ( & V_9 , V_7 ) ;
if ( V_8 )
F_6 ( & V_17 ) ;
}
static void F_7 ( struct V_11 * V_18 )
{
unsigned long V_7 ;
F_8 ( & V_18 -> V_13 ) ;
V_18 -> V_16 = 0 ;
F_2 ( & V_9 , V_7 ) ;
F_9 ( & V_18 -> V_13 , & V_10 ) ;
F_5 ( & V_9 , V_7 ) ;
}
static void F_10 ( struct V_11 * V_18 )
{
F_11 ( V_17 , V_18 -> V_16 ) ;
}
static void F_12 ( struct V_11 * V_18 )
{
unsigned long V_7 ;
F_2 ( & V_9 , V_7 ) ;
F_13 ( & V_18 -> V_13 ) ;
F_5 ( & V_9 , V_7 ) ;
}
static void V_11 ( struct V_11 * V_18 )
{
F_7 ( V_18 ) ;
F_10 ( V_18 ) ;
F_12 ( V_18 ) ;
}
static int F_14 ( struct V_19 T_1 * V_1 )
{
struct V_11 V_18 ;
if ( F_15 ( & V_18 . V_1 , V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
if ( V_18 . V_1 . V_1 & ~ V_21 )
return - V_22 ;
V_11 ( & V_18 ) ;
if ( V_18 . V_16 ) {
if ( F_16 ( V_1 , & V_18 . V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
return 0 ;
}
return - V_23 ;
}
int F_17 ( int V_24 )
{
struct V_11 V_18 ;
do {
V_18 . V_1 . V_1 = V_25 ;
F_7 ( & V_18 ) ;
if ( V_24 == V_26 + 1 ) {
F_12 ( & V_18 ) ;
break;
}
F_10 ( & V_18 ) ;
F_12 ( & V_18 ) ;
if ( V_18 . V_16 == 0 )
return - V_23 ;
} while ( V_18 . V_1 . V_15 != V_24 );
return 0 ;
}
static inline int
F_18 ( int V_27 , struct V_28 T_1 * V_29 , int V_30 , struct V_31 * V_32 )
{
struct V_28 V_33 ;
int V_34 ;
if ( F_15 ( & V_33 , V_29 , sizeof( struct V_28 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_35 :
if ( ! V_30 )
return - V_36 ;
V_32 -> V_32 = V_37 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = V_33 . V_44 ;
return F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
case V_47 : {
V_32 -> V_32 = V_48 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = V_33 . V_44 ;
V_34 = F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_41 = V_32 -> V_40 ;
V_33 . V_42 = V_32 -> V_42 ;
if ( F_16 ( V_29 , & V_33 , sizeof( struct V_28 ) ) )
return - V_20 ;
return 0 ;
}
}
return - V_22 ;
}
static inline int
F_20 ( int V_27 , struct V_49 T_1 * V_50 , int V_30 , struct V_51 * V_52 )
{
struct V_49 V_53 ;
if ( F_15 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
if ( V_53 . V_54 )
if ( ! F_21 ( V_55 , V_53 . V_54 ,
V_53 . V_56 * sizeof( struct V_57 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_58 :
if ( ! V_30 )
return - V_36 ;
return F_22 ( V_52 , V_53 . V_56 , V_53 . V_54 ) ;
case V_59 :
if ( ! V_30 && V_26 != V_52 -> V_60 )
return - V_36 ;
return F_23 ( V_52 , V_53 . V_56 , & ( V_50 -> V_56 ) , V_53 . V_54 ) ;
}
return 0 ;
}
static int F_24 ( unsigned int V_60 )
{
struct V_51 * V_52 = NULL ;
int V_61 = 0 ;
F_25 () ;
if ( F_26 ( V_60 ) )
V_61 = - V_62 ;
else if ( V_60 )
V_52 = F_27 ( V_60 ) ;
F_28 () ;
if ( V_52 && V_60 >= V_63 ) {
F_29 ( & V_52 -> V_64 ) ;
F_30 ( V_52 ) ;
}
return V_61 ;
}
static void F_31 ( void )
{
struct V_51 * V_52 [ V_65 ] ;
int V_34 ;
F_25 () ;
for ( V_34 = 1 ; V_34 < V_65 ; V_34 ++ )
if ( ! F_26 ( V_34 ) )
V_52 [ V_34 ] = F_27 ( V_34 ) ;
else
V_52 [ V_34 ] = NULL ;
F_28 () ;
for ( V_34 = 1 ; V_34 < V_65 ; V_34 ++ ) {
if ( V_52 [ V_34 ] && V_34 >= V_63 ) {
F_29 ( & V_52 [ V_34 ] -> V_64 ) ;
F_30 ( V_52 [ V_34 ] ) ;
}
}
}
int F_32 ( struct V_66 * V_67 ,
unsigned int V_27 , unsigned long V_68 )
{
struct V_51 * V_52 = V_67 -> V_69 ;
struct V_31 V_32 ;
unsigned int V_70 ;
unsigned char V_71 ;
unsigned int V_72 ;
void T_1 * V_73 = ( void T_1 * ) V_68 ;
int V_34 , V_30 ;
int V_61 = 0 ;
V_70 = V_52 -> V_60 ;
if ( ! F_33 ( V_70 ) ) {
V_61 = - V_74 ;
goto V_75;
}
V_30 = 0 ;
if ( V_76 -> signal -> V_67 == V_67 || F_34 ( V_77 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_78 :
V_61 = F_35 ( V_67 , V_68 ) ;
break;
case V_79 :
if ( ! V_30 )
return - V_36 ;
if ( V_68 )
V_68 = V_80 / V_68 ;
F_36 ( V_68 , 0 ) ;
break;
case V_81 :
if ( ! V_30 )
return - V_36 ;
{
unsigned int V_82 , V_83 ;
V_82 = V_84 * ( ( V_68 >> 16 ) & 0xffff ) / 1000 ;
V_83 = V_82 ? ( V_68 & 0xffff ) : 0 ;
if ( V_83 )
V_83 = V_80 / V_83 ;
F_36 ( V_83 , V_82 ) ;
break;
}
case V_85 :
V_71 = V_86 ;
V_61 = F_37 ( V_71 , ( char T_1 * ) V_68 ) ;
break;
#ifdef F_38
case V_87 :
case V_88 :
if ( V_68 < V_89 || V_68 > V_90 ) {
V_61 = - V_22 ;
break;
}
V_61 = F_39 ( V_68 , 1 , ( V_27 == V_87 ) ) ? - V_91 : 0 ;
break;
case V_92 :
case V_93 :
V_61 = F_39 ( V_89 , V_94 ,
( V_27 == V_92 ) ) ? - V_91 : 0 ;
break;
#endif
case V_95 :
{
struct V_96 V_97 ;
if ( ! F_34 ( V_77 ) )
return - V_36 ;
if ( F_15 ( & V_97 , V_73 , sizeof( struct V_96 ) ) ) {
V_61 = - V_20 ;
break;
}
V_61 = F_40 ( & V_97 ) ;
if ( V_61 )
break;
if ( F_16 ( V_73 , & V_97 , sizeof( struct V_96 ) ) )
V_61 = - V_20 ;
break;
}
case V_98 :
if ( ! V_30 )
return - V_36 ;
switch ( V_68 ) {
case V_99 :
break;
case V_100 :
case V_101 :
V_68 = V_102 ;
case V_102 :
break;
default:
V_61 = - V_22 ;
goto V_75;
}
if ( V_52 -> V_103 == ( unsigned char ) V_68 )
break;
V_52 -> V_103 = ( unsigned char ) V_68 ;
if ( V_70 != V_26 )
break;
F_25 () ;
if ( V_68 == V_102 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
F_28 () ;
break;
case V_104 :
V_72 = V_52 -> V_103 ;
goto V_105;
case V_106 :
case V_107 :
V_61 = - V_22 ;
break;
case V_108 :
if ( ! V_30 )
return - V_36 ;
V_61 = F_43 ( V_70 , V_68 ) ;
if ( V_61 == 0 )
F_44 ( V_67 ) ;
break;
case V_109 :
V_72 = F_45 ( V_70 ) ;
V_61 = F_37 ( V_72 , ( int T_1 * ) V_68 ) ;
break;
case V_110 :
V_61 = F_46 ( V_70 , V_68 ) ;
break;
case V_111 :
V_72 = F_47 ( V_70 ) ;
V_105:
V_61 = F_37 ( V_72 , ( int T_1 * ) V_68 ) ;
break;
case V_112 :
case V_113 :
if( ! F_34 ( V_77 ) )
V_30 = 0 ;
V_61 = F_48 ( V_27 , V_73 , V_30 ) ;
break;
case V_114 :
case V_115 :
V_61 = F_49 ( V_27 , V_73 , V_30 , V_70 ) ;
break;
case V_116 :
case V_117 :
V_61 = F_50 ( V_27 , V_73 , V_30 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_61 = F_51 ( V_27 , V_73 , V_30 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_61 = F_52 ( V_70 , V_27 , V_68 , V_30 ) ;
break;
case V_126 :
{
if ( ! V_30 || ! F_34 ( V_127 ) )
return - V_36 ;
if ( ! F_53 ( V_68 ) || V_68 < 1 || V_68 == V_128 )
V_61 = - V_22 ;
else {
F_54 ( & V_129 . V_130 ) ;
F_55 ( V_129 . V_131 ) ;
V_129 . V_131 = F_56 ( F_57 ( V_76 ) ) ;
V_129 . V_132 = V_68 ;
F_58 ( & V_129 . V_130 ) ;
}
break;
}
case V_133 :
{
struct V_134 V_53 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_53 , V_73 , sizeof( struct V_134 ) ) ) {
V_61 = - V_20 ;
goto V_75;
}
if ( V_53 . V_135 != V_136 && V_53 . V_135 != V_137 ) {
V_61 = - V_22 ;
goto V_75;
}
F_25 () ;
V_52 -> V_134 = V_53 ;
V_52 -> V_134 . V_138 = 0 ;
F_55 ( V_52 -> V_139 ) ;
V_52 -> V_139 = F_56 ( F_57 ( V_76 ) ) ;
V_52 -> V_140 = - 1 ;
F_28 () ;
break;
}
case V_141 :
{
struct V_134 V_53 ;
int V_142 ;
F_25 () ;
memcpy ( & V_53 , & V_52 -> V_134 , sizeof( struct V_134 ) ) ;
F_28 () ;
V_142 = F_16 ( V_73 , & V_53 , sizeof( struct V_134 ) ) ;
if ( V_142 )
V_61 = - V_20 ;
break;
}
case V_143 :
{
struct V_144 T_1 * V_145 = V_73 ;
unsigned short V_146 , V_147 ;
if ( F_37 ( V_26 + 1 , & V_145 -> V_148 ) )
V_61 = - V_20 ;
else {
V_146 = 1 ;
for ( V_34 = 0 , V_147 = 2 ; V_34 < V_65 && V_147 ;
++ V_34 , V_147 <<= 1 )
if ( F_59 ( V_34 ) )
V_146 |= V_147 ;
V_61 = F_37 ( V_146 , & V_145 -> V_149 ) ;
}
break;
}
case V_150 :
for ( V_34 = 0 ; V_34 < V_65 ; ++ V_34 )
if ( ! F_59 ( V_34 ) )
break;
V_72 = V_34 < V_65 ? ( V_34 + 1 ) : - 1 ;
goto V_105;
case V_151 :
if ( ! V_30 )
return - V_36 ;
if ( V_68 == 0 || V_68 > V_65 )
V_61 = - V_91 ;
else {
V_68 -- ;
F_25 () ;
V_61 = F_60 ( V_68 ) ;
F_28 () ;
if ( V_61 )
break;
F_61 ( V_68 ) ;
}
break;
case V_152 :
{
struct V_153 V_154 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_154 , (struct V_153 T_1 * ) V_68 ,
sizeof( struct V_153 ) ) ) {
V_61 = - V_20 ;
goto V_75;
}
if ( V_154 . V_70 == 0 || V_154 . V_70 > V_65 )
V_61 = - V_91 ;
else {
V_154 . V_70 -- ;
F_25 () ;
V_61 = F_60 ( V_154 . V_70 ) ;
if ( V_61 == 0 ) {
struct V_51 * V_155 ;
V_155 = V_45 [ V_154 . V_70 ] . V_46 ;
V_155 -> V_134 = V_154 . V_135 ;
V_155 -> V_134 . V_138 = 0 ;
F_55 ( V_155 -> V_139 ) ;
V_155 -> V_139 = F_56 ( F_57 ( V_76 ) ) ;
}
F_28 () ;
if ( V_61 )
break;
F_61 ( V_154 . V_70 ) ;
}
break;
}
case V_156 :
if ( ! V_30 )
return - V_36 ;
if ( V_68 == 0 || V_68 > V_65 )
V_61 = - V_91 ;
else
V_61 = F_17 ( V_68 ) ;
break;
case V_157 :
if ( ! V_30 )
return - V_36 ;
F_25 () ;
if ( V_52 -> V_134 . V_135 != V_137 ) {
F_28 () ;
V_61 = - V_22 ;
break;
}
if ( V_52 -> V_140 >= 0 ) {
if ( V_68 == 0 )
V_52 -> V_140 = - 1 ;
else {
int V_158 ;
V_158 = V_52 -> V_140 ;
V_52 -> V_140 = - 1 ;
V_61 = F_60 ( V_158 ) ;
if ( V_61 ) {
F_28 () ;
break;
}
F_62 ( V_45 [ V_158 ] . V_46 ) ;
}
} else {
if ( V_68 != V_159 )
V_61 = - V_22 ;
}
F_28 () ;
break;
case V_160 :
if ( V_68 > V_65 ) {
V_61 = - V_91 ;
break;
}
if ( V_68 == 0 )
F_31 () ;
else
V_61 = F_24 ( -- V_68 ) ;
break;
case V_161 :
{
struct V_162 T_1 * V_163 = V_73 ;
struct V_51 * V_52 ;
T_2 V_164 , V_165 ;
if ( ! V_30 )
return - V_36 ;
if ( F_63 ( V_164 , & V_163 -> V_166 ) ||
F_63 ( V_165 , & V_163 -> V_167 ) )
V_61 = - V_20 ;
else {
F_25 () ;
for ( V_34 = 0 ; V_34 < V_65 ; V_34 ++ ) {
V_52 = V_45 [ V_34 ] . V_46 ;
if ( V_52 ) {
V_52 -> V_168 = 1 ;
F_64 ( V_45 [ V_34 ] . V_46 , V_165 , V_164 ) ;
}
}
F_28 () ;
}
break;
}
case V_169 :
{
struct V_170 T_1 * V_171 = V_73 ;
T_2 V_164 , V_165 , V_172 , V_173 , V_174 , V_175 ;
if ( ! V_30 )
return - V_36 ;
if ( ! F_21 ( V_176 , V_171 ,
sizeof( struct V_170 ) ) ) {
V_61 = - V_20 ;
break;
}
F_65 ( V_164 , & V_171 -> V_166 ) ;
F_65 ( V_165 , & V_171 -> V_167 ) ;
F_65 ( V_172 , & V_171 -> V_177 ) ;
F_65 ( V_173 , & V_171 -> V_178 ) ;
F_65 ( V_174 , & V_171 -> V_179 ) ;
F_65 ( V_175 , & V_171 -> V_180 ) ;
V_172 = V_172 ? V_172 : V_52 -> V_181 ;
if ( V_173 ) {
if ( V_164 ) {
if ( V_164 != V_172 / V_173 ) {
V_61 = - V_22 ;
break;
}
} else
V_164 = V_172 / V_173 ;
}
if ( V_174 && V_175 ) {
if ( V_165 ) {
if ( V_165 != V_174 / V_175 ) {
V_61 = - V_22 ;
break;
}
} else
V_165 = V_174 / V_175 ;
}
if ( V_173 > 32 ) {
V_61 = - V_22 ;
break;
}
for ( V_34 = 0 ; V_34 < V_65 ; V_34 ++ ) {
if ( ! V_45 [ V_34 ] . V_46 )
continue;
F_25 () ;
if ( V_172 )
V_45 [ V_34 ] . V_46 -> V_181 = V_172 ;
if ( V_173 )
V_45 [ V_34 ] . V_46 -> V_182 . V_40 = V_173 ;
V_45 [ V_34 ] . V_46 -> V_168 = 1 ;
F_64 ( V_45 [ V_34 ] . V_46 , V_165 , V_164 ) ;
F_28 () ;
}
break;
}
case V_183 : {
if ( ! V_30 )
return - V_36 ;
V_32 . V_32 = V_37 ;
V_32 . V_7 = V_38 | V_184 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 0 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_73 ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_185 : {
V_32 . V_32 = V_48 ;
V_32 . V_7 = V_38 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 32 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_73 ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_186 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_66 ( V_73 ) ;
break;
case V_187 :
V_61 = F_67 ( V_73 ) ;
break;
case V_35 :
case V_47 :
V_61 = F_18 ( V_27 , V_73 , V_30 , & V_32 ) ;
break;
case V_188 :
{
if ( ! V_30 )
return - V_36 ;
#ifdef F_68
V_61 = - V_189 ;
break;
#else
{
V_32 . V_32 = V_190 ;
V_32 . V_43 = NULL ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
if ( V_61 )
break;
F_25 () ;
F_69 ( V_45 [ V_26 ] . V_46 ) ;
F_28 () ;
break;
}
#endif
}
case V_191 : {
if ( F_15 ( & V_32 , V_73 , sizeof( V_32 ) ) ) {
V_61 = - V_20 ;
break;
}
if ( ! V_30 && V_32 . V_32 != V_48 )
return - V_36 ;
V_61 = F_19 ( V_52 , & V_32 ) ;
if ( V_61 )
break;
if ( F_16 ( V_73 , & V_32 , sizeof( V_32 ) ) )
V_61 = - V_20 ;
break;
}
case V_192 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_70 ( V_73 ) ;
break;
case V_193 :
V_61 = F_71 ( V_73 ) ;
break;
case V_194 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_72 ( V_73 ) ;
break;
case V_195 :
V_61 = F_73 ( V_73 ) ;
break;
case V_196 :
{ struct V_197 V_198 ;
if ( ! V_30 )
return - V_36 ;
V_61 = F_15 ( & V_198 , V_73 , sizeof( struct V_197 ) ) ;
if ( V_61 )
V_61 = - V_20 ;
else
F_74 ( V_52 , & V_198 ) ;
break;
}
case V_58 :
case V_59 :
V_61 = F_20 ( V_27 , V_73 , V_30 , V_52 ) ;
break;
case V_199 :
if ( ! F_34 ( V_77 ) )
return - V_36 ;
V_200 = 1 ;
break;
case V_201 :
if ( ! F_34 ( V_77 ) )
return - V_36 ;
V_200 = 0 ;
break;
case V_202 :
V_61 = F_37 ( V_52 -> V_203 ,
( unsigned short T_1 * ) V_68 ) ;
break;
case V_204 :
V_61 = F_14 ( (struct V_19 T_1 * ) V_68 ) ;
break;
default:
V_61 = - V_74 ;
}
V_75:
return V_61 ;
}
void F_75 ( struct V_51 * V_52 )
{
V_52 -> V_103 = V_102 ;
F_76 ( V_52 -> V_60 ) ;
V_52 -> V_134 . V_135 = V_136 ;
V_52 -> V_134 . V_205 = 0 ;
V_52 -> V_134 . V_206 = 0 ;
V_52 -> V_134 . V_207 = 0 ;
V_52 -> V_134 . V_138 = 0 ;
F_55 ( V_52 -> V_139 ) ;
V_52 -> V_139 = NULL ;
V_52 -> V_140 = - 1 ;
if ( ! F_77 () )
F_78 ( V_52 ) ;
}
void F_79 ( struct V_208 * V_209 )
{
struct V_52 * V_210 =
F_80 ( V_209 , struct V_52 , V_211 ) ;
struct V_51 * V_52 ;
struct V_66 * V_67 ;
F_25 () ;
V_52 = V_210 -> V_46 ;
if ( V_52 ) {
V_67 = V_52 -> V_64 . V_67 ;
if ( V_67 )
F_81 ( V_67 ) ;
F_75 ( V_52 ) ;
}
F_28 () ;
}
static inline int
F_82 ( int V_27 , struct V_212 T_1 * V_29 ,
int V_30 , struct V_31 * V_32 )
{
struct V_212 V_33 ;
int V_34 ;
if ( F_15 ( & V_33 , V_29 , sizeof( struct V_212 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_35 :
if ( ! V_30 )
return - V_36 ;
V_32 -> V_32 = V_37 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = F_83 ( V_33 . V_44 ) ;
return F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
case V_47 :
V_32 -> V_32 = V_48 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = F_83 ( V_33 . V_44 ) ;
V_34 = F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_41 = V_32 -> V_40 ;
V_33 . V_42 = V_32 -> V_42 ;
if ( F_16 ( V_29 , & V_33 , sizeof( struct V_212 ) ) )
return - V_20 ;
return 0 ;
}
return - V_22 ;
}
static inline int
F_84 ( struct V_213 T_1 * V_214 ,
int V_30 , struct V_31 * V_32 , struct V_51 * V_52 )
{
int V_34 ;
if ( F_15 ( V_32 , V_214 , sizeof( struct V_213 ) ) )
return - V_20 ;
if ( ! V_30 && V_32 -> V_32 != V_48 )
return - V_36 ;
V_32 -> V_43 = F_83 ( ( (struct V_213 * ) V_32 ) -> V_43 ) ;
V_34 = F_19 ( V_52 , V_32 ) ;
if ( V_34 )
return V_34 ;
( (struct V_213 * ) V_32 ) -> V_43 = ( unsigned long ) V_32 -> V_43 ;
if ( F_16 ( V_214 , V_32 , sizeof( struct V_213 ) ) )
return - V_20 ;
return 0 ;
}
static inline int
F_85 ( unsigned int V_27 , struct V_215 T_1 * V_50 ,
int V_30 , struct V_51 * V_52 )
{
struct V_215 V_53 ;
struct V_57 T_1 * V_216 ;
if ( F_15 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
V_216 = F_83 ( V_53 . V_54 ) ;
if ( V_216 )
if ( ! F_21 ( V_55 , V_216 ,
V_53 . V_56 * sizeof( struct V_57 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_58 :
if ( ! V_30 )
return - V_36 ;
return F_22 ( V_52 , V_53 . V_56 , V_216 ) ;
case V_59 :
if ( ! V_30 && V_26 != V_52 -> V_60 )
return - V_36 ;
return F_23 ( V_52 , V_53 . V_56 , & ( V_50 -> V_56 ) , V_216 ) ;
}
return 0 ;
}
long F_86 ( struct V_66 * V_67 ,
unsigned int V_27 , unsigned long V_68 )
{
struct V_51 * V_52 = V_67 -> V_69 ;
struct V_31 V_32 ;
unsigned int V_70 ;
void T_1 * V_73 = ( void T_1 * ) V_68 ;
int V_30 ;
int V_61 = 0 ;
V_70 = V_52 -> V_60 ;
if ( ! F_33 ( V_70 ) ) {
V_61 = - V_74 ;
goto V_75;
}
V_30 = 0 ;
if ( V_76 -> signal -> V_67 == V_67 || F_34 ( V_77 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_35 :
case V_47 :
V_61 = F_82 ( V_27 , V_73 , V_30 , & V_32 ) ;
break;
case V_191 :
V_61 = F_84 ( V_73 , V_30 , & V_32 , V_52 ) ;
break;
case V_58 :
case V_59 :
V_61 = F_85 ( V_27 , V_73 , V_30 , V_52 ) ;
break;
case V_79 :
case V_81 :
#ifdef F_38
case V_87 :
case V_88 :
#endif
case V_98 :
case V_106 :
case V_107 :
case V_108 :
case V_110 :
case V_123 :
case V_125 :
case V_126 :
case V_151 :
case V_156 :
case V_157 :
case V_160 :
case V_161 :
case V_169 :
goto V_217;
default:
V_68 = ( unsigned long ) F_83 ( V_68 ) ;
goto V_217;
}
V_75:
return V_61 ;
V_217:
return F_32 ( V_67 , V_27 , V_68 ) ;
}
static void F_62 ( struct V_51 * V_52 )
{
unsigned char V_218 ;
int V_2 = V_26 ;
V_219 = V_26 ;
V_218 = V_45 [ V_26 ] . V_46 -> V_103 ;
F_87 ( V_52 ) ;
if ( V_218 != V_52 -> V_103 ) {
if ( V_52 -> V_103 == V_102 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
}
if ( V_52 -> V_134 . V_135 == V_137 ) {
if ( F_88 ( V_52 -> V_139 , V_52 -> V_134 . V_207 , 1 ) != 0 ) {
F_75 ( V_52 ) ;
if ( V_218 != V_52 -> V_103 ) {
if ( V_52 -> V_103 == V_102 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
}
}
}
F_1 ( V_25 , V_2 , V_52 -> V_60 ) ;
return;
}
void F_89 ( struct V_51 * V_220 )
{
struct V_51 * V_52 ;
if ( ! V_220 || V_220 -> V_60 == V_26 || V_200 )
return;
V_52 = V_45 [ V_26 ] . V_46 ;
if ( V_52 -> V_134 . V_135 == V_137 ) {
V_52 -> V_140 = V_220 -> V_60 ;
if ( F_88 ( V_52 -> V_139 , V_52 -> V_134 . V_206 , 1 ) == 0 ) {
return;
}
F_75 ( V_52 ) ;
}
if ( V_52 -> V_103 == V_99 )
return;
F_62 ( V_220 ) ;
}
int F_90 ( unsigned int V_221 , int V_222 )
{
int V_223 ;
F_25 () ;
if ( V_224 ) {
F_28 () ;
return 0 ;
}
V_223 = V_26 ;
if ( V_222 && F_60 ( V_221 ) ) {
F_28 () ;
return - V_225 ;
}
if ( F_61 ( V_221 ) ) {
F_28 () ;
return - V_226 ;
}
F_28 () ;
if ( F_17 ( V_221 + 1 ) ) {
F_91 ( L_1 ) ;
return - V_23 ;
}
return V_223 ;
}
void F_92 ( int V_227 )
{
F_25 () ;
V_224 = ! V_227 ;
F_28 () ;
}
