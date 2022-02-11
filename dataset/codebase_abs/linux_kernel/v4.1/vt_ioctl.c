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
V_82 = F_37 ( ( V_68 >> 16 ) & 0xffff ) ;
V_83 = V_82 ? ( V_68 & 0xffff ) : 0 ;
if ( V_83 )
V_83 = V_80 / V_83 ;
F_36 ( V_83 , V_82 ) ;
break;
}
case V_84 :
V_71 = V_85 ;
V_61 = F_38 ( V_71 , ( char T_1 * ) V_68 ) ;
break;
#ifdef F_39
case V_86 :
case V_87 :
if ( V_68 < V_88 || V_68 > V_89 ) {
V_61 = - V_22 ;
break;
}
V_61 = F_40 ( V_68 , 1 , ( V_27 == V_86 ) ) ? - V_90 : 0 ;
break;
case V_91 :
case V_92 :
V_61 = F_40 ( V_88 , V_93 ,
( V_27 == V_91 ) ) ? - V_90 : 0 ;
break;
#endif
case V_94 :
{
struct V_95 V_96 ;
if ( ! F_34 ( V_77 ) )
return - V_36 ;
if ( F_15 ( & V_96 , V_73 , sizeof( struct V_95 ) ) ) {
V_61 = - V_20 ;
break;
}
V_61 = F_41 ( & V_96 ) ;
if ( V_61 )
break;
if ( F_16 ( V_73 , & V_96 , sizeof( struct V_95 ) ) )
V_61 = - V_20 ;
break;
}
case V_97 :
if ( ! V_30 )
return - V_36 ;
switch ( V_68 ) {
case V_98 :
break;
case V_99 :
case V_100 :
V_68 = V_101 ;
case V_101 :
break;
default:
V_61 = - V_22 ;
goto V_75;
}
if ( V_52 -> V_102 == ( unsigned char ) V_68 )
break;
V_52 -> V_102 = ( unsigned char ) V_68 ;
if ( V_70 != V_26 )
break;
F_25 () ;
if ( V_68 == V_101 )
F_42 ( 1 ) ;
else
F_43 ( 1 ) ;
F_28 () ;
break;
case V_103 :
V_72 = V_52 -> V_102 ;
goto V_104;
case V_105 :
case V_106 :
V_61 = - V_22 ;
break;
case V_107 :
if ( ! V_30 )
return - V_36 ;
V_61 = F_44 ( V_70 , V_68 ) ;
if ( V_61 == 0 )
F_45 ( V_67 ) ;
break;
case V_108 :
V_72 = F_46 ( V_70 ) ;
V_61 = F_38 ( V_72 , ( int T_1 * ) V_68 ) ;
break;
case V_109 :
V_61 = F_47 ( V_70 , V_68 ) ;
break;
case V_110 :
V_72 = F_48 ( V_70 ) ;
V_104:
V_61 = F_38 ( V_72 , ( int T_1 * ) V_68 ) ;
break;
case V_111 :
case V_112 :
if( ! F_34 ( V_77 ) )
V_30 = 0 ;
V_61 = F_49 ( V_27 , V_73 , V_30 ) ;
break;
case V_113 :
case V_114 :
V_61 = F_50 ( V_27 , V_73 , V_30 , V_70 ) ;
break;
case V_115 :
case V_116 :
V_61 = F_51 ( V_27 , V_73 , V_30 ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_61 = F_52 ( V_27 , V_73 , V_30 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_61 = F_53 ( V_70 , V_27 , V_68 , V_30 ) ;
break;
case V_125 :
{
if ( ! V_30 || ! F_34 ( V_126 ) )
return - V_36 ;
if ( ! F_54 ( V_68 ) || V_68 < 1 || V_68 == V_127 )
V_61 = - V_22 ;
else {
F_55 ( & V_128 . V_129 ) ;
F_56 ( V_128 . V_130 ) ;
V_128 . V_130 = F_57 ( F_58 ( V_76 ) ) ;
V_128 . V_131 = V_68 ;
F_59 ( & V_128 . V_129 ) ;
}
break;
}
case V_132 :
{
struct V_133 V_53 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_53 , V_73 , sizeof( struct V_133 ) ) ) {
V_61 = - V_20 ;
goto V_75;
}
if ( V_53 . V_134 != V_135 && V_53 . V_134 != V_136 ) {
V_61 = - V_22 ;
goto V_75;
}
F_25 () ;
V_52 -> V_133 = V_53 ;
V_52 -> V_133 . V_137 = 0 ;
F_56 ( V_52 -> V_138 ) ;
V_52 -> V_138 = F_57 ( F_58 ( V_76 ) ) ;
V_52 -> V_139 = - 1 ;
F_28 () ;
break;
}
case V_140 :
{
struct V_133 V_53 ;
int V_141 ;
F_25 () ;
memcpy ( & V_53 , & V_52 -> V_133 , sizeof( struct V_133 ) ) ;
F_28 () ;
V_141 = F_16 ( V_73 , & V_53 , sizeof( struct V_133 ) ) ;
if ( V_141 )
V_61 = - V_20 ;
break;
}
case V_142 :
{
struct V_143 T_1 * V_144 = V_73 ;
unsigned short V_145 , V_146 ;
if ( F_38 ( V_26 + 1 , & V_144 -> V_147 ) )
V_61 = - V_20 ;
else {
V_145 = 1 ;
for ( V_34 = 0 , V_146 = 2 ; V_34 < V_65 && V_146 ;
++ V_34 , V_146 <<= 1 )
if ( F_60 ( V_34 ) )
V_145 |= V_146 ;
V_61 = F_38 ( V_145 , & V_144 -> V_148 ) ;
}
break;
}
case V_149 :
for ( V_34 = 0 ; V_34 < V_65 ; ++ V_34 )
if ( ! F_60 ( V_34 ) )
break;
V_72 = V_34 < V_65 ? ( V_34 + 1 ) : - 1 ;
goto V_104;
case V_150 :
if ( ! V_30 )
return - V_36 ;
if ( V_68 == 0 || V_68 > V_65 )
V_61 = - V_90 ;
else {
V_68 -- ;
F_25 () ;
V_61 = F_61 ( V_68 ) ;
F_28 () ;
if ( V_61 )
break;
F_62 ( V_68 ) ;
}
break;
case V_151 :
{
struct V_152 V_153 ;
if ( ! V_30 )
return - V_36 ;
if ( F_15 ( & V_153 , (struct V_152 T_1 * ) V_68 ,
sizeof( struct V_152 ) ) ) {
V_61 = - V_20 ;
goto V_75;
}
if ( V_153 . V_70 == 0 || V_153 . V_70 > V_65 )
V_61 = - V_90 ;
else {
V_153 . V_70 -- ;
F_25 () ;
V_61 = F_61 ( V_153 . V_70 ) ;
if ( V_61 == 0 ) {
struct V_51 * V_154 ;
V_154 = V_45 [ V_153 . V_70 ] . V_46 ;
V_154 -> V_133 = V_153 . V_134 ;
V_154 -> V_133 . V_137 = 0 ;
F_56 ( V_154 -> V_138 ) ;
V_154 -> V_138 = F_57 ( F_58 ( V_76 ) ) ;
}
F_28 () ;
if ( V_61 )
break;
F_62 ( V_153 . V_70 ) ;
}
break;
}
case V_155 :
if ( ! V_30 )
return - V_36 ;
if ( V_68 == 0 || V_68 > V_65 )
V_61 = - V_90 ;
else
V_61 = F_17 ( V_68 ) ;
break;
case V_156 :
if ( ! V_30 )
return - V_36 ;
F_25 () ;
if ( V_52 -> V_133 . V_134 != V_136 ) {
F_28 () ;
V_61 = - V_22 ;
break;
}
if ( V_52 -> V_139 >= 0 ) {
if ( V_68 == 0 )
V_52 -> V_139 = - 1 ;
else {
int V_157 ;
V_157 = V_52 -> V_139 ;
V_52 -> V_139 = - 1 ;
V_61 = F_61 ( V_157 ) ;
if ( V_61 ) {
F_28 () ;
break;
}
F_63 ( V_45 [ V_157 ] . V_46 ) ;
}
} else {
if ( V_68 != V_158 )
V_61 = - V_22 ;
}
F_28 () ;
break;
case V_159 :
if ( V_68 > V_65 ) {
V_61 = - V_90 ;
break;
}
if ( V_68 == 0 )
F_31 () ;
else
V_61 = F_24 ( -- V_68 ) ;
break;
case V_160 :
{
struct V_161 T_1 * V_162 = V_73 ;
struct V_51 * V_52 ;
T_2 V_163 , V_164 ;
if ( ! V_30 )
return - V_36 ;
if ( F_64 ( V_163 , & V_162 -> V_165 ) ||
F_64 ( V_164 , & V_162 -> V_166 ) )
V_61 = - V_20 ;
else {
F_25 () ;
for ( V_34 = 0 ; V_34 < V_65 ; V_34 ++ ) {
V_52 = V_45 [ V_34 ] . V_46 ;
if ( V_52 ) {
V_52 -> V_167 = 1 ;
F_65 ( V_45 [ V_34 ] . V_46 , V_164 , V_163 ) ;
}
}
F_28 () ;
}
break;
}
case V_168 :
{
struct V_169 T_1 * V_170 = V_73 ;
T_2 V_163 , V_164 , V_171 , V_172 , V_173 , V_174 ;
if ( ! V_30 )
return - V_36 ;
if ( ! F_21 ( V_175 , V_170 ,
sizeof( struct V_169 ) ) ) {
V_61 = - V_20 ;
break;
}
F_66 ( V_163 , & V_170 -> V_165 ) ;
F_66 ( V_164 , & V_170 -> V_166 ) ;
F_66 ( V_171 , & V_170 -> V_176 ) ;
F_66 ( V_172 , & V_170 -> V_177 ) ;
F_66 ( V_173 , & V_170 -> V_178 ) ;
F_66 ( V_174 , & V_170 -> V_179 ) ;
V_171 = V_171 ? V_171 : V_52 -> V_180 ;
if ( V_172 ) {
if ( V_163 ) {
if ( V_163 != V_171 / V_172 ) {
V_61 = - V_22 ;
break;
}
} else
V_163 = V_171 / V_172 ;
}
if ( V_173 && V_174 ) {
if ( V_164 ) {
if ( V_164 != V_173 / V_174 ) {
V_61 = - V_22 ;
break;
}
} else
V_164 = V_173 / V_174 ;
}
if ( V_172 > 32 ) {
V_61 = - V_22 ;
break;
}
for ( V_34 = 0 ; V_34 < V_65 ; V_34 ++ ) {
if ( ! V_45 [ V_34 ] . V_46 )
continue;
F_25 () ;
if ( V_171 )
V_45 [ V_34 ] . V_46 -> V_180 = V_171 ;
if ( V_172 )
V_45 [ V_34 ] . V_46 -> V_181 . V_40 = V_172 ;
V_45 [ V_34 ] . V_46 -> V_167 = 1 ;
F_65 ( V_45 [ V_34 ] . V_46 , V_164 , V_163 ) ;
F_28 () ;
}
break;
}
case V_182 : {
if ( ! V_30 )
return - V_36 ;
V_32 . V_32 = V_37 ;
V_32 . V_7 = V_38 | V_183 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 0 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_73 ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_184 : {
V_32 . V_32 = V_48 ;
V_32 . V_7 = V_38 ;
V_32 . V_39 = 8 ;
V_32 . V_40 = 32 ;
V_32 . V_42 = 256 ;
V_32 . V_43 = V_73 ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
break;
}
case V_185 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_67 ( V_73 ) ;
break;
case V_186 :
V_61 = F_68 ( V_73 ) ;
break;
case V_35 :
case V_47 :
V_61 = F_18 ( V_27 , V_73 , V_30 , & V_32 ) ;
break;
case V_187 :
{
if ( ! V_30 )
return - V_36 ;
#ifdef F_69
V_61 = - V_188 ;
break;
#else
{
V_32 . V_32 = V_189 ;
V_32 . V_43 = NULL ;
V_61 = F_19 ( V_45 [ V_26 ] . V_46 , & V_32 ) ;
if ( V_61 )
break;
F_25 () ;
F_70 ( V_45 [ V_26 ] . V_46 ) ;
F_28 () ;
break;
}
#endif
}
case V_190 : {
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
case V_191 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_71 ( V_73 ) ;
break;
case V_192 :
V_61 = F_72 ( V_73 ) ;
break;
case V_193 :
if ( ! V_30 )
V_61 = - V_36 ;
else
V_61 = F_73 ( V_73 ) ;
break;
case V_194 :
V_61 = F_74 ( V_73 ) ;
break;
case V_195 :
{ struct V_196 V_197 ;
if ( ! V_30 )
return - V_36 ;
V_61 = F_15 ( & V_197 , V_73 , sizeof( struct V_196 ) ) ;
if ( V_61 )
V_61 = - V_20 ;
else
F_75 ( V_52 , & V_197 ) ;
break;
}
case V_58 :
case V_59 :
V_61 = F_20 ( V_27 , V_73 , V_30 , V_52 ) ;
break;
case V_198 :
if ( ! F_34 ( V_77 ) )
return - V_36 ;
V_199 = 1 ;
break;
case V_200 :
if ( ! F_34 ( V_77 ) )
return - V_36 ;
V_199 = 0 ;
break;
case V_201 :
V_61 = F_38 ( V_52 -> V_202 ,
( unsigned short T_1 * ) V_68 ) ;
break;
case V_203 :
V_61 = F_14 ( (struct V_19 T_1 * ) V_68 ) ;
break;
default:
V_61 = - V_74 ;
}
V_75:
return V_61 ;
}
void F_76 ( struct V_51 * V_52 )
{
V_52 -> V_102 = V_101 ;
F_77 ( V_52 -> V_60 ) ;
V_52 -> V_133 . V_134 = V_135 ;
V_52 -> V_133 . V_204 = 0 ;
V_52 -> V_133 . V_205 = 0 ;
V_52 -> V_133 . V_206 = 0 ;
V_52 -> V_133 . V_137 = 0 ;
F_56 ( V_52 -> V_138 ) ;
V_52 -> V_138 = NULL ;
V_52 -> V_139 = - 1 ;
if ( ! F_78 () )
F_79 ( V_52 ) ;
}
void F_80 ( struct V_207 * V_208 )
{
struct V_52 * V_209 =
F_81 ( V_208 , struct V_52 , V_210 ) ;
struct V_51 * V_52 ;
struct V_66 * V_67 ;
F_25 () ;
V_52 = V_209 -> V_46 ;
if ( V_52 ) {
V_67 = V_52 -> V_64 . V_67 ;
if ( V_67 )
F_82 ( V_67 ) ;
F_76 ( V_52 ) ;
}
F_28 () ;
}
static inline int
F_83 ( int V_27 , struct V_211 T_1 * V_29 ,
int V_30 , struct V_31 * V_32 )
{
struct V_211 V_33 ;
int V_34 ;
if ( F_15 ( & V_33 , V_29 , sizeof( struct V_211 ) ) )
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
if ( F_16 ( V_29 , & V_33 , sizeof( struct V_211 ) ) )
return - V_20 ;
return 0 ;
}
return - V_22 ;
}
static inline int
F_85 ( struct V_212 T_1 * V_213 ,
int V_30 , struct V_31 * V_32 , struct V_51 * V_52 )
{
int V_34 ;
if ( F_15 ( V_32 , V_213 , sizeof( struct V_212 ) ) )
return - V_20 ;
if ( ! V_30 && V_32 -> V_32 != V_48 )
return - V_36 ;
V_32 -> V_43 = F_84 ( ( (struct V_212 * ) V_32 ) -> V_43 ) ;
V_34 = F_19 ( V_52 , V_32 ) ;
if ( V_34 )
return V_34 ;
( (struct V_212 * ) V_32 ) -> V_43 = ( unsigned long ) V_32 -> V_43 ;
if ( F_16 ( V_213 , V_32 , sizeof( struct V_212 ) ) )
return - V_20 ;
return 0 ;
}
static inline int
F_86 ( unsigned int V_27 , struct V_214 T_1 * V_50 ,
int V_30 , struct V_51 * V_52 )
{
struct V_214 V_53 ;
struct V_57 T_1 * V_215 ;
if ( F_15 ( & V_53 , V_50 , sizeof V_53 ) )
return - V_20 ;
V_215 = F_84 ( V_53 . V_54 ) ;
if ( V_215 )
if ( ! F_21 ( V_55 , V_215 ,
V_53 . V_56 * sizeof( struct V_57 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_58 :
if ( ! V_30 )
return - V_36 ;
return F_22 ( V_52 , V_53 . V_56 , V_215 ) ;
case V_59 :
if ( ! V_30 && V_26 != V_52 -> V_60 )
return - V_36 ;
return F_23 ( V_52 , V_53 . V_56 , & ( V_50 -> V_56 ) , V_215 ) ;
}
return 0 ;
}
long F_87 ( struct V_66 * V_67 ,
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
V_61 = F_83 ( V_27 , V_73 , V_30 , & V_32 ) ;
break;
case V_190 :
V_61 = F_85 ( V_73 , V_30 , & V_32 , V_52 ) ;
break;
case V_58 :
case V_59 :
V_61 = F_86 ( V_27 , V_73 , V_30 , V_52 ) ;
break;
case V_79 :
case V_81 :
#ifdef F_39
case V_86 :
case V_87 :
#endif
case V_97 :
case V_105 :
case V_106 :
case V_107 :
case V_109 :
case V_122 :
case V_124 :
case V_125 :
case V_150 :
case V_155 :
case V_156 :
case V_159 :
case V_160 :
case V_168 :
goto V_216;
default:
V_68 = ( unsigned long ) F_84 ( V_68 ) ;
goto V_216;
}
V_75:
return V_61 ;
V_216:
return F_32 ( V_67 , V_27 , V_68 ) ;
}
static void F_63 ( struct V_51 * V_52 )
{
unsigned char V_217 ;
int V_2 = V_26 ;
V_218 = V_26 ;
V_217 = V_45 [ V_26 ] . V_46 -> V_102 ;
F_88 ( V_52 ) ;
if ( V_217 != V_52 -> V_102 ) {
if ( V_52 -> V_102 == V_101 )
F_42 ( 1 ) ;
else
F_43 ( 1 ) ;
}
if ( V_52 -> V_133 . V_134 == V_136 ) {
if ( F_89 ( V_52 -> V_138 , V_52 -> V_133 . V_206 , 1 ) != 0 ) {
F_76 ( V_52 ) ;
if ( V_217 != V_52 -> V_102 ) {
if ( V_52 -> V_102 == V_101 )
F_42 ( 1 ) ;
else
F_43 ( 1 ) ;
}
}
}
F_1 ( V_25 , V_2 , V_52 -> V_60 ) ;
return;
}
void F_90 ( struct V_51 * V_219 )
{
struct V_51 * V_52 ;
if ( ! V_219 || V_219 -> V_60 == V_26 || V_199 )
return;
V_52 = V_45 [ V_26 ] . V_46 ;
if ( V_52 -> V_133 . V_134 == V_136 ) {
V_52 -> V_139 = V_219 -> V_60 ;
if ( F_89 ( V_52 -> V_138 , V_52 -> V_133 . V_205 , 1 ) == 0 ) {
return;
}
F_76 ( V_52 ) ;
}
if ( V_52 -> V_102 == V_98 )
return;
F_63 ( V_219 ) ;
}
int F_91 ( unsigned int V_220 , int V_221 )
{
int V_222 ;
F_25 () ;
if ( V_223 ) {
F_28 () ;
return 0 ;
}
V_222 = V_26 ;
if ( V_221 && F_61 ( V_220 ) ) {
F_28 () ;
return - V_224 ;
}
if ( F_62 ( V_220 ) ) {
F_28 () ;
return - V_225 ;
}
F_28 () ;
if ( F_17 ( V_220 + 1 ) ) {
F_92 ( L_1 ) ;
return - V_23 ;
}
return V_222 ;
}
void F_93 ( int V_226 )
{
F_25 () ;
V_223 = ! V_226 ;
F_28 () ;
}
