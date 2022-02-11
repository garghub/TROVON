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
switch ( V_27 ) {
case V_54 :
if ( ! V_30 )
return - V_36 ;
return F_21 ( V_52 , V_53 . V_55 , V_53 . V_56 ) ;
case V_57 :
if ( ! V_30 && V_26 != V_52 -> V_58 )
return - V_36 ;
return F_22 ( V_52 , V_53 . V_55 , & ( V_50 -> V_55 ) , V_53 . V_56 ) ;
}
return 0 ;
}
static int F_23 ( unsigned int V_58 )
{
struct V_51 * V_52 = NULL ;
int V_59 = 0 ;
F_24 () ;
if ( F_25 ( V_58 ) )
V_59 = - V_60 ;
else if ( V_58 )
V_52 = F_26 ( V_58 ) ;
F_27 () ;
if ( V_52 && V_58 >= V_61 ) {
F_28 ( & V_52 -> V_62 ) ;
F_29 ( V_52 ) ;
}
return V_59 ;
}
static void F_30 ( void )
{
struct V_51 * V_52 [ V_63 ] ;
int V_34 ;
F_24 () ;
for ( V_34 = 1 ; V_34 < V_63 ; V_34 ++ )
if ( ! F_25 ( V_34 ) )
V_52 [ V_34 ] = F_26 ( V_34 ) ;
else
V_52 [ V_34 ] = NULL ;
F_27 () ;
for ( V_34 = 1 ; V_34 < V_63 ; V_34 ++ ) {
if ( V_52 [ V_34 ] && V_34 >= V_61 ) {
F_28 ( & V_52 [ V_34 ] -> V_62 ) ;
F_29 ( V_52 [ V_34 ] ) ;
}
}
}
int F_31 ( struct V_64 * V_65 ,
unsigned int V_27 , unsigned long V_66 )
{
struct V_51 * V_52 = V_65 -> V_67 ;
struct V_31 V_32 ;
unsigned int V_68 ;
unsigned char V_69 ;
unsigned int V_70 ;
void T_1 * V_71 = ( void T_1 * ) V_66 ;
int V_34 , V_30 ;
int V_59 = 0 ;
V_68 = V_52 -> V_58 ;
if ( ! F_32 ( V_68 ) ) {
V_59 = - V_72 ;
goto V_73;
}
V_30 = 0 ;
if ( V_74 -> signal -> V_65 == V_65 || F_33 ( V_75 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_76 :
V_59 = F_34 ( V_65 , V_66 ) ;
break;
case V_77 :
if ( ! V_30 )
return - V_36 ;
if ( V_66 )
V_66 = V_78 / V_66 ;
F_35 ( V_66 , 0 ) ;
break;
case V_79 :
if ( ! V_30 )
return - V_36 ;
{
unsigned int V_80 , V_81 ;
V_80 = F_36 ( ( V_66 >> 16 ) & 0xffff ) ;
V_81 = V_80 ? ( V_66 & 0xffff ) : 0 ;
if ( V_81 )
V_81 = V_78 / V_81 ;
F_35 ( V_81 , V_80 ) ;
break;
}
case V_82 :
V_69 = V_83 ;
V_59 = F_37 ( V_69 , ( char T_1 * ) V_66 ) ;
break;
#ifdef F_38
case V_84 :
case V_85 :
if ( V_66 < V_86 || V_66 > V_87 ) {
V_59 = - V_22 ;
break;
}
V_59 = F_39 ( V_66 , 1 , ( V_27 == V_84 ) ) ? - V_88 : 0 ;
break;
case V_89 :
case V_90 :
V_59 = F_39 ( V_86 , V_91 ,
( V_27 == V_89 ) ) ? - V_88 : 0 ;
break;
#endif
case V_92 :
{
struct V_93 V_94 ;
if ( ! F_33 ( V_75 ) )
return - V_36 ;
if ( F_15 ( & V_94 , V_71 , sizeof( struct V_93 ) ) ) {
V_59 = - V_20 ;
break;
}
V_59 = F_40 ( & V_94 ) ;
if ( V_59 )
break;
if ( F_16 ( V_71 , & V_94 , sizeof( struct V_93 ) ) )
V_59 = - V_20 ;
break;
}
case V_95 :
if ( ! V_30 )
return - V_36 ;
switch ( V_66 ) {
case V_96 :
break;
case V_97 :
case V_98 :
V_66 = V_99 ;
case V_99 :
break;
default:
V_59 = - V_22 ;
goto V_73;
}
if ( V_52 -> V_100 == ( unsigned char ) V_66 )
break;
V_52 -> V_100 = ( unsigned char ) V_66 ;
if ( V_68 != V_26 )
break;
F_24 () ;
if ( V_66 == V_99 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
F_27 () ;
break;
case V_101 :
V_70 = V_52 -> V_100 ;
goto V_102;
case V_103 :
case V_104 :
V_59 = - V_22 ;
break;
case V_105 :
if ( ! V_30 )
return - V_36 ;
V_59 = F_43 ( V_68 , V_66 ) ;
if ( V_59 == 0 )
F_44 ( V_65 ) ;
break;
case V_106 :
V_70 = F_45 ( V_68 ) ;
V_59 = F_37 ( V_70 , ( int T_1 * ) V_66 ) ;
break;
case V_107 :
V_59 = F_46 ( V_68 , V_66 ) ;
break;
case V_108 :
V_70 = F_47 ( V_68 ) ;
V_102:
V_59 = F_37 ( V_70 , ( int T_1 * ) V_66 ) ;
break;
case V_109 :
case V_110 :
if( ! F_33 ( V_75 ) )
V_30 = 0 ;
V_59 = F_48 ( V_27 , V_71 , V_30 ) ;
break;
case V_111 :
case V_112 :
V_59 = F_49 ( V_27 , V_71 , V_30 , V_68 ) ;
break;
case V_113 :
case V_114 :
V_59 = F_50 ( V_27 , V_71 , V_30 ) ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_59 = F_51 ( V_27 , V_71 , V_30 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_59 = F_52 ( V_68 , V_27 , V_66 , V_30 ) ;
break;
case V_123 :
{
if ( ! V_30 || ! F_33 ( V_124 ) )
return - V_36 ;
if ( ! F_53 ( V_66 ) || V_66 < 1 || V_66 == V_125 )
V_59 = - V_22 ;
else {
F_54 ( & V_126 . V_127 ) ;
F_55 ( V_126 . V_128 ) ;
V_126 . V_128 = F_56 ( F_57 ( V_74 ) ) ;
V_126 . V_129 = V_66 ;
F_58 ( & V_126 . V_127 ) ;
}
break;
}
case V_130 :
{
struct V_131 V_53 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_53 , V_71 , sizeof( struct V_131 ) ) ) {
V_59 = - V_20 ;
goto V_73;
}
if ( V_53 . V_132 != V_133 && V_53 . V_132 != V_134 ) {
V_59 = - V_22 ;
goto V_73;
}
F_24 () ;
V_52 -> V_131 = V_53 ;
V_52 -> V_131 . V_135 = 0 ;
F_55 ( V_52 -> V_136 ) ;
V_52 -> V_136 = F_56 ( F_57 ( V_74 ) ) ;
V_52 -> V_137 = - 1 ;
F_27 () ;
break;
}
case V_138 :
{
struct V_131 V_53 ;
int V_139 ;
F_24 () ;
memcpy ( & V_53 , & V_52 -> V_131 , sizeof( struct V_131 ) ) ;
F_27 () ;
V_139 = F_16 ( V_71 , & V_53 , sizeof( struct V_131 ) ) ;
if ( V_139 )
V_59 = - V_20 ;
break;
}
case V_140 :
{
struct V_141 T_1 * V_142 = V_71 ;
unsigned short V_143 , V_144 ;
if ( F_37 ( V_26 + 1 , & V_142 -> V_145 ) )
V_59 = - V_20 ;
else {
V_143 = 1 ;
for ( V_34 = 0 , V_144 = 2 ; V_34 < V_63 && V_144 ;
++ V_34 , V_144 <<= 1 )
if ( F_59 ( V_34 ) )
V_143 |= V_144 ;
V_59 = F_37 ( V_143 , & V_142 -> V_146 ) ;
}
break;
}
case V_147 :
for ( V_34 = 0 ; V_34 < V_63 ; ++ V_34 )
if ( ! F_59 ( V_34 ) )
break;
V_70 = V_34 < V_63 ? ( V_34 + 1 ) : - 1 ;
goto V_102;
case V_148 :
if ( ! V_30 )
return - V_36 ;
if ( V_66 == 0 || V_66 > V_63 )
V_59 = - V_88 ;
else {
V_66 -- ;
F_24 () ;
V_59 = F_60 ( V_66 ) ;
F_27 () ;
if ( V_59 )
break;
F_61 ( V_66 ) ;
}
break;
case V_149 :
{
struct V_150 V_151 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_151 , (struct V_150 T_1 * ) V_66 ,
sizeof( struct V_150 ) ) ) {
V_59 = - V_20 ;
goto V_73;
}
if ( V_151 . V_68 == 0 || V_151 . V_68 > V_63 )
V_59 = - V_88 ;
else {
V_151 . V_68 -- ;
F_24 () ;
V_59 = F_60 ( V_151 . V_68 ) ;
if ( V_59 == 0 ) {
struct V_51 * V_152 ;
V_152 = V_45 [ V_151 . V_68 ] . V_46 ;
V_152 -> V_131 = V_151 . V_132 ;
V_152 -> V_131 . V_135 = 0 ;
F_55 ( V_152 -> V_136 ) ;
V_152 -> V_136 = F_56 ( F_57 ( V_74 ) ) ;
}
F_27 () ;
if ( V_59 )
break;
F_61 ( V_151 . V_68 ) ;
}
break;
}
case V_153 :
if ( ! V_30 )
return - V_36 ;
if ( V_66 == 0 || V_66 > V_63 )
V_59 = - V_88 ;
else
V_59 = F_17 ( V_66 ) ;
break;
case V_154 :
if ( ! V_30 )
return - V_36 ;
F_24 () ;
if ( V_52 -> V_131 . V_132 != V_134 ) {
F_27 () ;
V_59 = - V_22 ;
break;
}
if ( V_52 -> V_137 >= 0 ) {
if ( V_66 == 0 )
V_52 -> V_137 = - 1 ;
else {
int V_155 ;
V_155 = V_52 -> V_137 ;
V_52 -> V_137 = - 1 ;
V_59 = F_60 ( V_155 ) ;
if ( V_59 ) {
F_27 () ;
break;
}
F_62 ( V_45 [ V_155 ] . V_46 ) ;
}
} else {
if ( V_66 != V_156 )
V_59 = - V_22 ;
}
F_27 () ;
break;
case V_157 :
if ( V_66 > V_63 ) {
V_59 = - V_88 ;
break;
}
if ( V_66 == 0 )
F_30 () ;
else
V_59 = F_23 ( -- V_66 ) ;
break;
case V_158 :
{
struct V_159 T_1 * V_160 = V_71 ;
struct V_51 * V_52 ;
T_2 V_161 , V_162 ;
if ( ! V_30 )
return - V_36 ;
if ( F_63 ( V_161 , & V_160 -> V_163 ) ||
F_63 ( V_162 , & V_160 -> V_164 ) )
V_59 = - V_20 ;
else {
F_24 () ;
for ( V_34 = 0 ; V_34 < V_63 ; V_34 ++ ) {
V_52 = V_45 [ V_34 ] . V_46 ;
if ( V_52 ) {
V_52 -> V_165 = 1 ;
F_64 ( V_45 [ V_34 ] . V_46 , V_162 , V_161 ) ;
}
}
F_27 () ;
}
break;
}
case V_166 :
{
struct V_167 T_1 * V_168 = V_71 ;
T_2 V_161 , V_162 , V_169 , V_170 , V_171 , V_172 ;
if ( ! V_30 )
return - V_36 ;
if ( ! F_65 ( V_173 , V_168 ,
sizeof( struct V_167 ) ) ) {
V_59 = - V_20 ;
break;
}
F_66 ( V_161 , & V_168 -> V_163 ) ;
F_66 ( V_162 , & V_168 -> V_164 ) ;
F_66 ( V_169 , & V_168 -> V_174 ) ;
F_66 ( V_170 , & V_168 -> V_175 ) ;
F_66 ( V_171 , & V_168 -> V_176 ) ;
F_66 ( V_172 , & V_168 -> V_177 ) ;
V_169 = V_169 ? V_169 : V_52 -> V_178 ;
if ( V_170 ) {
if ( V_161 ) {
if ( V_161 != V_169 / V_170 ) {
V_59 = - V_22 ;
break;
}
} else
V_161 = V_169 / V_170 ;
}
if ( V_171 && V_172 ) {
if ( V_162 ) {
if ( V_162 != V_171 / V_172 ) {
V_59 = - V_22 ;
break;
}
} else
V_162 = V_171 / V_172 ;
}
if ( V_170 > 32 ) {
V_59 = - V_22 ;
break;
}
for ( V_34 = 0 ; V_34 < V_63 ; V_34 ++ ) {
if ( ! V_45 [ V_34 ] . V_46 )
continue;
F_24 () ;
if ( V_169 )
V_45 [ V_34 ] . V_46 -> V_178 = V_169 ;
if ( V_170 )
V_45 [ V_34 ] . V_46 -> V_179 . V_40 = V_170 ;
V_45 [ V_34 ] . V_46 -> V_165 = 1 ;
F_64 ( V_45 [ V_34 ] . V_46 , V_162 , V_161 ) ;
F_27 () ;
}
break;
}
case V_180 : {
if ( ! V_30 )
return - V_36 ;
V_32 . V_32 = V_37 ;
V_32 . V_7 = V_38 | V_181 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 0 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_71 ;
V_59 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_182 : {
V_32 . V_32 = V_48 ;
V_32 . V_7 = V_38 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 32 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_71 ;
V_59 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_183 :
if ( ! V_30 )
V_59 = - V_36 ;
else
V_59 = F_67 ( V_71 ) ;
break;
case V_184 :
V_59 = F_68 ( V_71 ) ;
break;
case V_35 :
case V_47 :
V_59 = F_18 ( V_27 , V_71 , V_30 , & V_32 ) ;
break;
case V_185 :
{
if ( ! V_30 )
return - V_36 ;
#ifdef F_69
V_59 = - V_186 ;
break;
#else
{
V_32 . V_32 = V_187 ;
V_32 . V_43 = NULL ;
V_59 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
if ( V_59 )
break;
F_24 () ;
F_70 ( V_45 [ V_26 ] . V_46 ) ;
F_27 () ;
break;
}
#endif
}
case V_188 : {
if ( F_15 ( & V_32 , V_71 , sizeof( V_32 ) ) ) {
V_59 = - V_20 ;
break;
}
if ( ! V_30 && V_32 . V_32 != V_48 )
return - V_36 ;
V_59 = F_19 ( V_52 , & V_32 ) ;
if ( V_59 )
break;
if ( F_16 ( V_71 , & V_32 , sizeof( V_32 ) ) )
V_59 = - V_20 ;
break;
}
case V_189 :
if ( ! V_30 )
V_59 = - V_36 ;
else
V_59 = F_71 ( V_71 ) ;
break;
case V_190 :
V_59 = F_72 ( V_71 ) ;
break;
case V_191 :
if ( ! V_30 )
V_59 = - V_36 ;
else
V_59 = F_73 ( V_71 ) ;
break;
case V_192 :
V_59 = F_74 ( V_71 ) ;
break;
case V_193 :
if ( ! V_30 )
return - V_36 ;
F_75 ( V_52 ) ;
break;
case V_54 :
case V_57 :
V_59 = F_20 ( V_27 , V_71 , V_30 , V_52 ) ;
break;
case V_194 :
if ( ! F_33 ( V_75 ) )
return - V_36 ;
V_195 = 1 ;
break;
case V_196 :
if ( ! F_33 ( V_75 ) )
return - V_36 ;
V_195 = 0 ;
break;
case V_197 :
V_59 = F_37 ( V_52 -> V_198 ,
( unsigned short T_1 * ) V_66 ) ;
break;
case V_199 :
V_59 = F_14 ( (struct V_19 T_1 * ) V_66 ) ;
break;
default:
V_59 = - V_72 ;
}
V_73:
return V_59 ;
}
void F_76 ( struct V_51 * V_52 )
{
V_52 -> V_100 = V_99 ;
F_77 ( V_52 -> V_58 ) ;
V_52 -> V_131 . V_132 = V_133 ;
V_52 -> V_131 . V_200 = 0 ;
V_52 -> V_131 . V_201 = 0 ;
V_52 -> V_131 . V_202 = 0 ;
V_52 -> V_131 . V_135 = 0 ;
F_55 ( V_52 -> V_136 ) ;
V_52 -> V_136 = NULL ;
V_52 -> V_137 = - 1 ;
if ( ! F_78 () )
F_79 ( V_52 ) ;
}
void F_80 ( struct V_203 * V_204 )
{
struct V_52 * V_205 =
F_81 ( V_204 , struct V_52 , V_206 ) ;
struct V_51 * V_52 ;
struct V_64 * V_65 ;
F_24 () ;
V_52 = V_205 -> V_46 ;
if ( V_52 ) {
V_65 = V_52 -> V_62 . V_65 ;
if ( V_65 )
F_82 ( V_65 ) ;
F_76 ( V_52 ) ;
}
F_27 () ;
}
static inline int
F_83 ( int V_27 , struct V_207 T_1 * V_29 ,
int V_30 , struct V_31 * V_32 )
{
struct V_207 V_33 ;
int V_34 ;
if ( F_15 ( & V_33 , V_29 , sizeof( struct V_207 ) ) )
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
V_32 -> V_43 = F_84 ( V_33 . V_44 ) ;
return F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
case V_47 :
V_32 -> V_32 = V_48 ;
V_32 -> V_7 = V_38 ;
V_32 -> V_39 = 8 ;
V_32 -> V_40 = V_33 . V_41 ;
V_32 -> V_42 = V_33 . V_42 ;
V_32 -> V_43 = F_84 ( V_33 . V_44 ) ;
V_34 = F_19 ( V_45 [ V_26 ] . V_46 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_33 . V_41 = V_32 -> V_40 ;
V_33 . V_42 = V_32 -> V_42 ;
if ( F_16 ( V_29 , & V_33 , sizeof( struct V_207 ) ) )
return - V_20 ;
return 0 ;
}
return - V_22 ;
}
static inline int
F_85 ( struct V_208 T_1 * V_209 ,
int V_30 , struct V_31 * V_32 , struct V_51 * V_52 )
{
int V_34 ;
if ( F_15 ( V_32 , V_209 , sizeof( struct V_208 ) ) )
return - V_20 ;
if ( ! V_30 && V_32 -> V_32 != V_48 )
return - V_36 ;
V_32 -> V_43 = F_84 ( ( (struct V_208 * ) V_32 ) -> V_43 ) ;
V_34 = F_19 ( V_52 , V_32 ) ;
if ( V_34 )
return V_34 ;
( (struct V_208 * ) V_32 ) -> V_43 = ( unsigned long ) V_32 -> V_43 ;
if ( F_16 ( V_209 , V_32 , sizeof( struct V_208 ) ) )
return - V_20 ;
return 0 ;
}
static inline int
F_86 ( unsigned int V_27 , struct V_210 T_1 * V_50 ,
int V_30 , struct V_51 * V_52 )
{
struct V_210 V_53 ;
struct V_211 T_1 * V_212 ;
if ( F_15 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
V_212 = F_84 ( V_53 . V_56 ) ;
switch ( V_27 ) {
case V_54 :
if ( ! V_30 )
return - V_36 ;
return F_21 ( V_52 , V_53 . V_55 , V_212 ) ;
case V_57 :
if ( ! V_30 && V_26 != V_52 -> V_58 )
return - V_36 ;
return F_22 ( V_52 , V_53 . V_55 , & ( V_50 -> V_55 ) , V_212 ) ;
}
return 0 ;
}
long F_87 ( struct V_64 * V_65 ,
unsigned int V_27 , unsigned long V_66 )
{
struct V_51 * V_52 = V_65 -> V_67 ;
struct V_31 V_32 ;
unsigned int V_68 ;
void T_1 * V_71 = ( void T_1 * ) V_66 ;
int V_30 ;
int V_59 = 0 ;
V_68 = V_52 -> V_58 ;
if ( ! F_32 ( V_68 ) ) {
V_59 = - V_72 ;
goto V_73;
}
V_30 = 0 ;
if ( V_74 -> signal -> V_65 == V_65 || F_33 ( V_75 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_35 :
case V_47 :
V_59 = F_83 ( V_27 , V_71 , V_30 , & V_32 ) ;
break;
case V_188 :
V_59 = F_85 ( V_71 , V_30 , & V_32 , V_52 ) ;
break;
case V_54 :
case V_57 :
V_59 = F_86 ( V_27 , V_71 , V_30 , V_52 ) ;
break;
case V_77 :
case V_79 :
#ifdef F_38
case V_84 :
case V_85 :
#endif
case V_95 :
case V_103 :
case V_104 :
case V_105 :
case V_107 :
case V_120 :
case V_122 :
case V_123 :
case V_148 :
case V_153 :
case V_154 :
case V_157 :
case V_158 :
case V_166 :
goto V_213;
default:
V_66 = ( unsigned long ) F_84 ( V_66 ) ;
goto V_213;
}
V_73:
return V_59 ;
V_213:
return F_31 ( V_65 , V_27 , V_66 ) ;
}
static void F_62 ( struct V_51 * V_52 )
{
unsigned char V_214 ;
int V_2 = V_26 ;
V_215 = V_26 ;
V_214 = V_45 [ V_26 ] . V_46 -> V_100 ;
F_88 ( V_52 ) ;
if ( V_214 != V_52 -> V_100 ) {
if ( V_52 -> V_100 == V_99 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
}
if ( V_52 -> V_131 . V_132 == V_134 ) {
if ( F_89 ( V_52 -> V_136 , V_52 -> V_131 . V_202 , 1 ) != 0 ) {
F_76 ( V_52 ) ;
if ( V_214 != V_52 -> V_100 ) {
if ( V_52 -> V_100 == V_99 )
F_41 ( 1 ) ;
else
F_42 ( 1 ) ;
}
}
}
F_1 ( V_25 , V_2 , V_52 -> V_58 ) ;
return;
}
void F_90 ( struct V_51 * V_216 )
{
struct V_51 * V_52 ;
if ( ! V_216 || V_216 -> V_58 == V_26 || V_195 )
return;
V_52 = V_45 [ V_26 ] . V_46 ;
if ( V_52 -> V_131 . V_132 == V_134 ) {
V_52 -> V_137 = V_216 -> V_58 ;
if ( F_89 ( V_52 -> V_136 , V_52 -> V_131 . V_201 , 1 ) == 0 ) {
return;
}
F_76 ( V_52 ) ;
}
if ( V_52 -> V_100 == V_96 )
return;
F_62 ( V_216 ) ;
}
int F_91 ( unsigned int V_217 , int V_218 )
{
int V_219 ;
F_24 () ;
if ( V_220 ) {
F_27 () ;
return 0 ;
}
V_219 = V_26 ;
if ( V_218 && F_60 ( V_217 ) ) {
F_27 () ;
return - V_221 ;
}
if ( F_61 ( V_217 ) ) {
F_27 () ;
return - V_222 ;
}
F_27 () ;
if ( F_17 ( V_217 + 1 ) ) {
F_92 ( L_1 ) ;
return - V_23 ;
}
return V_219 ;
}
void F_93 ( int V_223 )
{
F_24 () ;
V_220 = ! V_223 ;
F_27 () ;
}
