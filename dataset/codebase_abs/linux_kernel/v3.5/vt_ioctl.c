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
static void V_11 ( struct V_11 * V_18 )
{
unsigned long V_7 ;
F_7 ( & V_18 -> V_13 ) ;
V_18 -> V_16 = 0 ;
F_2 ( & V_9 , V_7 ) ;
F_8 ( & V_18 -> V_13 , & V_10 ) ;
F_5 ( & V_9 , V_7 ) ;
F_9 ( V_17 , V_18 -> V_16 ) ;
F_2 ( & V_9 , V_7 ) ;
F_10 ( & V_18 -> V_13 ) ;
F_5 ( & V_9 , V_7 ) ;
}
static int F_11 ( struct V_19 T_1 * V_1 )
{
struct V_11 V_18 ;
if ( F_12 ( & V_18 . V_1 , V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
if ( V_18 . V_1 . V_1 & ~ V_21 )
return - V_22 ;
V_11 ( & V_18 ) ;
if ( V_18 . V_16 ) {
if ( F_13 ( V_1 , & V_18 . V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
return 0 ;
}
return - V_23 ;
}
int F_14 ( int V_24 )
{
struct V_11 V_18 ;
do {
if ( V_24 == V_25 + 1 )
break;
V_18 . V_1 . V_1 = V_26 ;
V_11 ( & V_18 ) ;
if ( V_18 . V_16 == 0 )
return - V_23 ;
} while ( V_18 . V_1 . V_15 != V_24 );
return 0 ;
}
static inline int
F_15 ( int V_27 , struct V_28 T_1 * V_29 , int V_30 , struct V_31 * V_32 )
{
struct V_28 V_33 ;
int V_34 ;
if ( F_12 ( & V_33 , V_29 , sizeof( struct V_28 ) ) )
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
return F_16 ( V_45 [ V_25 ] . V_46 , V_32 ) ;
case V_47 : {
V_32 -> V_32 = V_48 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = V_33 . V_44 ;
V_34 = F_16 ( V_45 [ V_25 ] . V_46 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_41 = V_32 -> V_40 ;
V_33 . V_42 = V_32 -> V_42 ;
if ( F_13 ( V_29 , & V_33 , sizeof( struct V_28 ) ) )
return - V_20 ;
return 0 ;
}
}
return - V_22 ;
}
static inline int
F_17 ( int V_27 , struct V_49 T_1 * V_50 , int V_30 , struct V_51 * V_52 )
{
struct V_49 V_53 ;
if ( F_12 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
if ( V_53 . V_54 )
if ( ! F_18 ( V_55 , V_53 . V_54 ,
V_53 . V_56 * sizeof( struct V_57 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_58 :
if ( ! V_30 )
return - V_36 ;
return F_19 ( V_52 , V_53 . V_56 , V_53 . V_54 ) ;
case V_59 :
if ( ! V_30 && V_25 != V_52 -> V_60 )
return - V_36 ;
return F_20 ( V_52 , V_53 . V_56 , & ( V_50 -> V_56 ) , V_53 . V_54 ) ;
}
return 0 ;
}
int F_21 ( struct V_61 * V_62 ,
unsigned int V_27 , unsigned long V_63 )
{
struct V_51 * V_52 = V_62 -> V_64 ;
struct V_31 V_32 ;
unsigned int V_65 ;
unsigned char V_66 ;
unsigned int V_67 ;
void T_1 * V_68 = ( void T_1 * ) V_63 ;
int V_34 , V_30 ;
int V_69 = 0 ;
V_65 = V_52 -> V_60 ;
if ( ! F_22 ( V_65 ) ) {
V_69 = - V_70 ;
goto V_71;
}
V_30 = 0 ;
if ( V_72 -> signal -> V_62 == V_62 || F_23 ( V_73 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_74 :
V_69 = F_24 ( V_62 , V_63 ) ;
break;
case V_75 :
if ( ! V_30 )
return - V_36 ;
if ( V_63 )
V_63 = V_76 / V_63 ;
F_25 ( V_63 , 0 ) ;
break;
case V_77 :
if ( ! V_30 )
return - V_36 ;
{
unsigned int V_78 , V_79 ;
V_78 = V_80 * ( ( V_63 >> 16 ) & 0xffff ) / 1000 ;
V_79 = V_78 ? ( V_63 & 0xffff ) : 0 ;
if ( V_79 )
V_79 = V_76 / V_79 ;
F_25 ( V_79 , V_78 ) ;
break;
}
case V_81 :
V_66 = V_82 ;
V_69 = F_26 ( V_66 , ( char T_1 * ) V_63 ) ;
break;
#ifdef F_27
case V_83 :
case V_84 :
if ( V_63 < V_85 || V_63 > V_86 ) {
V_69 = - V_22 ;
break;
}
V_69 = F_28 ( V_63 , 1 , ( V_27 == V_83 ) ) ? - V_87 : 0 ;
break;
case V_88 :
case V_89 :
V_69 = F_28 ( V_85 , V_90 ,
( V_27 == V_88 ) ) ? - V_87 : 0 ;
break;
#endif
case V_91 :
{
struct V_92 V_93 ;
if ( ! F_23 ( V_73 ) )
return - V_36 ;
if ( F_12 ( & V_93 , V_68 , sizeof( struct V_92 ) ) ) {
V_69 = - V_20 ;
break;
}
V_69 = F_29 ( & V_93 ) ;
if ( V_69 )
break;
if ( F_13 ( V_68 , & V_93 , sizeof( struct V_92 ) ) )
V_69 = - V_20 ;
break;
}
case V_94 :
if ( ! V_30 )
return - V_36 ;
switch ( V_63 ) {
case V_95 :
break;
case V_96 :
case V_97 :
V_63 = V_98 ;
case V_98 :
break;
default:
V_69 = - V_22 ;
goto V_71;
}
if ( V_52 -> V_99 == ( unsigned char ) V_63 )
break;
V_52 -> V_99 = ( unsigned char ) V_63 ;
if ( V_65 != V_25 )
break;
F_30 () ;
if ( V_63 == V_98 )
F_31 ( 1 ) ;
else
F_32 ( 1 ) ;
F_33 () ;
break;
case V_100 :
V_67 = V_52 -> V_99 ;
goto V_101;
case V_102 :
case V_103 :
V_69 = - V_22 ;
break;
case V_104 :
if ( ! V_30 )
return - V_36 ;
V_69 = F_34 ( V_65 , V_63 ) ;
if ( V_69 == 0 )
F_35 ( V_62 ) ;
break;
case V_105 :
V_67 = F_36 ( V_65 ) ;
V_69 = F_26 ( V_67 , ( int T_1 * ) V_63 ) ;
break;
case V_106 :
V_69 = F_37 ( V_65 , V_63 ) ;
break;
case V_107 :
V_67 = F_38 ( V_65 ) ;
V_101:
V_69 = F_26 ( V_67 , ( int T_1 * ) V_63 ) ;
break;
case V_108 :
case V_109 :
if( ! F_23 ( V_73 ) )
V_30 = 0 ;
V_69 = F_39 ( V_27 , V_68 , V_30 ) ;
break;
case V_110 :
case V_111 :
V_69 = F_40 ( V_27 , V_68 , V_30 , V_65 ) ;
break;
case V_112 :
case V_113 :
V_69 = F_41 ( V_27 , V_68 , V_30 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_69 = F_42 ( V_27 , V_68 , V_30 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_69 = F_43 ( V_65 , V_27 , V_63 , V_30 ) ;
break;
case V_122 :
{
if ( ! V_30 || ! F_23 ( V_123 ) )
return - V_36 ;
if ( ! F_44 ( V_63 ) || V_63 < 1 || V_63 == V_124 )
V_69 = - V_22 ;
else {
F_45 ( & V_125 . V_126 ) ;
F_46 ( V_125 . V_127 ) ;
V_125 . V_127 = F_47 ( F_48 ( V_72 ) ) ;
V_125 . V_128 = V_63 ;
F_49 ( & V_125 . V_126 ) ;
}
break;
}
case V_129 :
{
struct V_130 V_53 ;
if ( ! V_30 )
return - V_36 ;
if ( F_12 ( & V_53 , V_68 , sizeof( struct V_130 ) ) ) {
V_69 = - V_20 ;
goto V_71;
}
if ( V_53 . V_131 != V_132 && V_53 . V_131 != V_133 ) {
V_69 = - V_22 ;
goto V_71;
}
F_30 () ;
V_52 -> V_130 = V_53 ;
V_52 -> V_130 . V_134 = 0 ;
F_46 ( V_52 -> V_135 ) ;
V_52 -> V_135 = F_47 ( F_48 ( V_72 ) ) ;
V_52 -> V_136 = - 1 ;
F_33 () ;
break;
}
case V_137 :
{
struct V_130 V_53 ;
int V_138 ;
F_30 () ;
memcpy ( & V_53 , & V_52 -> V_130 , sizeof( struct V_130 ) ) ;
F_33 () ;
V_138 = F_13 ( V_68 , & V_53 , sizeof( struct V_130 ) ) ;
if ( V_138 )
V_69 = - V_20 ;
break;
}
case V_139 :
{
struct V_140 T_1 * V_141 = V_68 ;
unsigned short V_142 , V_143 ;
if ( F_26 ( V_25 + 1 , & V_141 -> V_144 ) )
V_69 = - V_20 ;
else {
V_142 = 1 ;
for ( V_34 = 0 , V_143 = 2 ; V_34 < V_145 && V_143 ;
++ V_34 , V_143 <<= 1 )
if ( F_50 ( V_34 ) )
V_142 |= V_143 ;
V_69 = F_26 ( V_142 , & V_141 -> V_146 ) ;
}
break;
}
case V_147 :
for ( V_34 = 0 ; V_34 < V_145 ; ++ V_34 )
if ( ! F_50 ( V_34 ) )
break;
V_67 = V_34 < V_145 ? ( V_34 + 1 ) : - 1 ;
goto V_101;
case V_148 :
if ( ! V_30 )
return - V_36 ;
if ( V_63 == 0 || V_63 > V_145 )
V_69 = - V_87 ;
else {
V_63 -- ;
F_30 () ;
V_69 = F_51 ( V_63 ) ;
F_33 () ;
if ( V_69 )
break;
F_52 ( V_63 ) ;
}
break;
case V_149 :
{
struct V_150 V_151 ;
if ( ! V_30 )
return - V_36 ;
if ( F_12 ( & V_151 , (struct V_150 T_1 * ) V_63 ,
sizeof( struct V_150 ) ) ) {
V_69 = - V_20 ;
goto V_71;
}
if ( V_151 . V_65 == 0 || V_151 . V_65 > V_145 )
V_69 = - V_87 ;
else {
V_151 . V_65 -- ;
F_30 () ;
V_69 = F_51 ( V_151 . V_65 ) ;
if ( V_69 == 0 ) {
struct V_51 * V_152 ;
V_152 = V_45 [ V_151 . V_65 ] . V_46 ;
V_152 -> V_130 = V_151 . V_131 ;
V_152 -> V_130 . V_134 = 0 ;
F_46 ( V_152 -> V_135 ) ;
V_152 -> V_135 = F_47 ( F_48 ( V_72 ) ) ;
}
F_33 () ;
if ( V_69 )
break;
F_52 ( V_151 . V_65 ) ;
}
break;
}
case V_153 :
if ( ! V_30 )
return - V_36 ;
if ( V_63 == 0 || V_63 > V_145 )
V_69 = - V_87 ;
else
V_69 = F_14 ( V_63 ) ;
break;
case V_154 :
if ( ! V_30 )
return - V_36 ;
F_30 () ;
if ( V_52 -> V_130 . V_131 != V_133 ) {
F_33 () ;
V_69 = - V_22 ;
break;
}
if ( V_52 -> V_136 >= 0 ) {
if ( V_63 == 0 )
V_52 -> V_136 = - 1 ;
else {
int V_155 ;
V_155 = V_52 -> V_136 ;
V_52 -> V_136 = - 1 ;
V_69 = F_51 ( V_155 ) ;
if ( V_69 ) {
F_33 () ;
break;
}
F_53 ( V_45 [ V_155 ] . V_46 ) ;
}
} else {
if ( V_63 != V_156 )
V_69 = - V_22 ;
}
F_33 () ;
break;
case V_157 :
if ( V_63 > V_145 ) {
V_69 = - V_87 ;
break;
}
if ( V_63 == 0 ) {
F_30 () ;
for ( V_34 = 1 ; V_34 < V_145 ; V_34 ++ )
if ( ! F_54 ( V_34 ) )
F_55 ( V_34 ) ;
F_33 () ;
} else {
V_63 -- ;
if ( F_54 ( V_63 ) )
V_69 = - V_158 ;
else if ( V_63 ) {
F_30 () ;
F_55 ( V_63 ) ;
F_33 () ;
}
}
break;
case V_159 :
{
struct V_160 T_1 * V_161 = V_68 ;
struct V_51 * V_52 ;
T_2 V_162 , V_163 ;
if ( ! V_30 )
return - V_36 ;
if ( F_56 ( V_162 , & V_161 -> V_164 ) ||
F_56 ( V_163 , & V_161 -> V_165 ) )
V_69 = - V_20 ;
else {
F_30 () ;
for ( V_34 = 0 ; V_34 < V_145 ; V_34 ++ ) {
V_52 = V_45 [ V_34 ] . V_46 ;
if ( V_52 ) {
V_52 -> V_166 = 1 ;
F_57 ( V_45 [ V_34 ] . V_46 , V_163 , V_162 ) ;
}
}
F_33 () ;
}
break;
}
case V_167 :
{
struct V_168 T_1 * V_169 = V_68 ;
T_2 V_162 , V_163 , V_170 , V_171 , V_172 , V_173 ;
if ( ! V_30 )
return - V_36 ;
if ( ! F_18 ( V_174 , V_169 ,
sizeof( struct V_168 ) ) ) {
V_69 = - V_20 ;
break;
}
F_58 ( V_162 , & V_169 -> V_164 ) ;
F_58 ( V_163 , & V_169 -> V_165 ) ;
F_58 ( V_170 , & V_169 -> V_175 ) ;
F_58 ( V_171 , & V_169 -> V_176 ) ;
F_58 ( V_172 , & V_169 -> V_177 ) ;
F_58 ( V_173 , & V_169 -> V_178 ) ;
V_170 = V_170 ? V_170 : V_52 -> V_179 ;
if ( V_171 ) {
if ( V_162 ) {
if ( V_162 != V_170 / V_171 ) {
V_69 = - V_22 ;
break;
}
} else
V_162 = V_170 / V_171 ;
}
if ( V_172 && V_173 ) {
if ( V_163 ) {
if ( V_163 != V_172 / V_173 ) {
V_69 = - V_22 ;
break;
}
} else
V_163 = V_172 / V_173 ;
}
if ( V_171 > 32 ) {
V_69 = - V_22 ;
break;
}
for ( V_34 = 0 ; V_34 < V_145 ; V_34 ++ ) {
if ( ! V_45 [ V_34 ] . V_46 )
continue;
F_30 () ;
if ( V_170 )
V_45 [ V_34 ] . V_46 -> V_179 = V_170 ;
if ( V_171 )
V_45 [ V_34 ] . V_46 -> V_180 . V_40 = V_171 ;
V_45 [ V_34 ] . V_46 -> V_166 = 1 ;
F_57 ( V_45 [ V_34 ] . V_46 , V_163 , V_162 ) ;
F_33 () ;
}
break;
}
case V_181 : {
if ( ! V_30 )
return - V_36 ;
V_32 . V_32 = V_37 ;
V_32 . V_7 = V_38 | V_182 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 0 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_68 ;
V_69 = F_16 ( V_45 [ V_25 ] . V_46 , & V_32 ) ;
break;
}
case V_183 : {
V_32 . V_32 = V_48 ;
V_32 . V_7 = V_38 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 32 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_68 ;
V_69 = F_16 ( V_45 [ V_25 ] . V_46 , & V_32 ) ;
break;
}
case V_184 :
if ( ! V_30 )
V_69 = - V_36 ;
else
V_69 = F_59 ( V_68 ) ;
break;
case V_185 :
V_69 = F_60 ( V_68 ) ;
break;
case V_35 :
case V_47 :
V_69 = F_15 ( V_27 , V_68 , V_30 , & V_32 ) ;
break;
case V_186 :
{
if ( ! V_30 )
return - V_36 ;
#ifdef F_61
V_69 = - V_187 ;
break;
#else
{
V_32 . V_32 = V_188 ;
V_32 . V_43 = NULL ;
V_69 = F_16 ( V_45 [ V_25 ] . V_46 , & V_32 ) ;
if ( V_69 )
break;
F_30 () ;
F_62 ( V_45 [ V_25 ] . V_46 ) ;
F_33 () ;
break;
}
#endif
}
case V_189 : {
if ( F_12 ( & V_32 , V_68 , sizeof( V_32 ) ) ) {
V_69 = - V_20 ;
break;
}
if ( ! V_30 && V_32 . V_32 != V_48 )
return - V_36 ;
V_69 = F_16 ( V_52 , & V_32 ) ;
if ( V_69 )
break;
if ( F_13 ( V_68 , & V_32 , sizeof( V_32 ) ) )
V_69 = - V_20 ;
break;
}
case V_190 :
if ( ! V_30 )
V_69 = - V_36 ;
else
V_69 = F_63 ( V_68 ) ;
break;
case V_191 :
V_69 = F_64 ( V_68 ) ;
break;
case V_192 :
if ( ! V_30 )
V_69 = - V_36 ;
else
V_69 = F_65 ( V_68 ) ;
break;
case V_193 :
V_69 = F_66 ( V_68 ) ;
break;
case V_194 :
{ struct V_195 V_196 ;
if ( ! V_30 )
return - V_36 ;
V_69 = F_12 ( & V_196 , V_68 , sizeof( struct V_195 ) ) ;
if ( V_69 )
V_69 = - V_20 ;
else
F_67 ( V_52 , & V_196 ) ;
break;
}
case V_58 :
case V_59 :
V_69 = F_17 ( V_27 , V_68 , V_30 , V_52 ) ;
break;
case V_197 :
if ( ! F_23 ( V_73 ) )
return - V_36 ;
V_198 = 1 ;
break;
case V_199 :
if ( ! F_23 ( V_73 ) )
return - V_36 ;
V_198 = 0 ;
break;
case V_200 :
V_69 = F_26 ( V_52 -> V_201 ,
( unsigned short T_1 * ) V_63 ) ;
break;
case V_202 :
V_69 = F_11 ( (struct V_19 T_1 * ) V_63 ) ;
break;
default:
V_69 = - V_70 ;
}
V_71:
return V_69 ;
}
void F_68 ( struct V_51 * V_52 )
{
V_52 -> V_99 = V_98 ;
F_69 ( V_52 -> V_60 ) ;
V_52 -> V_130 . V_131 = V_132 ;
V_52 -> V_130 . V_203 = 0 ;
V_52 -> V_130 . V_204 = 0 ;
V_52 -> V_130 . V_205 = 0 ;
V_52 -> V_130 . V_134 = 0 ;
F_46 ( V_52 -> V_135 ) ;
V_52 -> V_135 = NULL ;
V_52 -> V_136 = - 1 ;
if ( ! F_70 () )
F_71 ( V_52 ) ;
}
void F_72 ( struct V_206 * V_207 )
{
struct V_52 * V_208 =
F_73 ( V_207 , struct V_52 , V_209 ) ;
struct V_51 * V_52 ;
struct V_61 * V_62 ;
F_30 () ;
V_52 = V_208 -> V_46 ;
if ( V_52 ) {
V_62 = V_52 -> V_210 . V_62 ;
if ( V_62 )
F_74 ( V_62 ) ;
F_68 ( V_52 ) ;
}
F_33 () ;
}
static inline int
F_75 ( int V_27 , struct V_211 T_1 * V_29 ,
int V_30 , struct V_31 * V_32 )
{
struct V_211 V_33 ;
int V_34 ;
if ( F_12 ( & V_33 , V_29 , sizeof( struct V_211 ) ) )
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
V_32 -> V_43 = F_76 ( V_33 . V_44 ) ;
return F_16 ( V_45 [ V_25 ] . V_46 , V_32 ) ;
case V_47 :
V_32 -> V_32 = V_48 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = F_76 ( V_33 . V_44 ) ;
V_34 = F_16 ( V_45 [ V_25 ] . V_46 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_41 = V_32 -> V_40 ;
V_33 . V_42 = V_32 -> V_42 ;
if ( F_13 ( V_29 , & V_33 , sizeof( struct V_211 ) ) )
return - V_20 ;
return 0 ;
}
return - V_22 ;
}
static inline int
F_77 ( struct V_212 T_1 * V_213 ,
int V_30 , struct V_31 * V_32 , struct V_51 * V_52 )
{
int V_34 ;
if ( F_12 ( V_32 , V_213 , sizeof( struct V_212 ) ) )
return - V_20 ;
if ( ! V_30 && V_32 -> V_32 != V_48 )
return - V_36 ;
V_32 -> V_43 = F_76 ( ( (struct V_212 * ) V_32 ) -> V_43 ) ;
V_34 = F_16 ( V_52 , V_32 ) ;
if ( V_34 )
return V_34 ;
( (struct V_212 * ) V_32 ) -> V_43 = ( unsigned long ) V_32 -> V_43 ;
if ( F_13 ( V_213 , V_32 , sizeof( struct V_212 ) ) )
return - V_20 ;
return 0 ;
}
static inline int
F_78 ( unsigned int V_27 , struct V_214 T_1 * V_50 ,
int V_30 , struct V_51 * V_52 )
{
struct V_214 V_53 ;
struct V_57 T_1 * V_215 ;
if ( F_12 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
V_215 = F_76 ( V_53 . V_54 ) ;
if ( V_215 )
if ( ! F_18 ( V_55 , V_215 ,
V_53 . V_56 * sizeof( struct V_57 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_58 :
if ( ! V_30 )
return - V_36 ;
return F_19 ( V_52 , V_53 . V_56 , V_215 ) ;
case V_59 :
if ( ! V_30 && V_25 != V_52 -> V_60 )
return - V_36 ;
return F_20 ( V_52 , V_53 . V_56 , & ( V_50 -> V_56 ) , V_215 ) ;
}
return 0 ;
}
long F_79 ( struct V_61 * V_62 ,
unsigned int V_27 , unsigned long V_63 )
{
struct V_51 * V_52 = V_62 -> V_64 ;
struct V_31 V_32 ;
unsigned int V_65 ;
void T_1 * V_68 = ( void T_1 * ) V_63 ;
int V_30 ;
int V_69 = 0 ;
V_65 = V_52 -> V_60 ;
if ( ! F_22 ( V_65 ) ) {
V_69 = - V_70 ;
goto V_71;
}
V_30 = 0 ;
if ( V_72 -> signal -> V_62 == V_62 || F_23 ( V_73 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_35 :
case V_47 :
V_69 = F_75 ( V_27 , V_68 , V_30 , & V_32 ) ;
break;
case V_189 :
V_69 = F_77 ( V_68 , V_30 , & V_32 , V_52 ) ;
break;
case V_58 :
case V_59 :
V_69 = F_78 ( V_27 , V_68 , V_30 , V_52 ) ;
break;
case V_75 :
case V_77 :
#ifdef F_27
case V_83 :
case V_84 :
#endif
case V_94 :
case V_102 :
case V_103 :
case V_104 :
case V_106 :
case V_119 :
case V_121 :
case V_122 :
case V_148 :
case V_153 :
case V_154 :
case V_157 :
case V_159 :
case V_167 :
goto V_216;
default:
V_63 = ( unsigned long ) F_76 ( V_63 ) ;
goto V_216;
}
V_71:
return V_69 ;
V_216:
return F_21 ( V_62 , V_27 , V_63 ) ;
}
static void F_53 ( struct V_51 * V_52 )
{
unsigned char V_217 ;
int V_2 = V_25 ;
V_218 = V_25 ;
V_217 = V_45 [ V_25 ] . V_46 -> V_99 ;
F_80 ( V_52 ) ;
if ( V_217 != V_52 -> V_99 ) {
if ( V_52 -> V_99 == V_98 )
F_31 ( 1 ) ;
else
F_32 ( 1 ) ;
}
if ( V_52 -> V_130 . V_131 == V_133 ) {
if ( F_81 ( V_52 -> V_135 , V_52 -> V_130 . V_205 , 1 ) != 0 ) {
F_68 ( V_52 ) ;
if ( V_217 != V_52 -> V_99 ) {
if ( V_52 -> V_99 == V_98 )
F_31 ( 1 ) ;
else
F_32 ( 1 ) ;
}
}
}
F_1 ( V_26 , V_2 , V_52 -> V_60 ) ;
return;
}
void F_82 ( struct V_51 * V_219 )
{
struct V_51 * V_52 ;
if ( ! V_219 || V_219 -> V_60 == V_25 || V_198 )
return;
V_52 = V_45 [ V_25 ] . V_46 ;
if ( V_52 -> V_130 . V_131 == V_133 ) {
V_52 -> V_136 = V_219 -> V_60 ;
if ( F_81 ( V_52 -> V_135 , V_52 -> V_130 . V_204 , 1 ) == 0 ) {
return;
}
F_68 ( V_52 ) ;
}
if ( V_52 -> V_99 == V_95 )
return;
F_53 ( V_219 ) ;
}
int F_83 ( unsigned int V_220 , int V_221 )
{
int V_222 ;
F_30 () ;
if ( V_223 ) {
F_33 () ;
return 0 ;
}
V_222 = V_25 ;
if ( V_221 && F_51 ( V_220 ) ) {
F_33 () ;
return - V_224 ;
}
if ( F_52 ( V_220 ) ) {
F_33 () ;
return - V_225 ;
}
F_33 () ;
if ( F_14 ( V_220 + 1 ) ) {
F_84 ( L_1 ) ;
return - V_23 ;
}
return V_222 ;
}
void F_85 ( int V_226 )
{
F_30 () ;
V_223 = ! V_226 ;
F_33 () ;
}
