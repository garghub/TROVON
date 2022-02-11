static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 - ( V_2 -> V_4 - V_2 -> V_5 ) ) ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_4 - V_2 -> V_5 ) ;
}
static int F_3 (
struct V_6 * V_7 ,
struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_8 > F_1 ( V_2 ) ) {
F_4 ( V_10 , V_11 , V_10 -> V_12 ,
L_1 ) ;
F_5 ( V_10 -> V_12 , V_7 -> V_13 ) ;
V_2 -> V_14 . V_15 = 1 ;
if ( V_2 -> V_14 . V_16 )
V_10 -> V_17 . V_18 ( V_7 , V_2 ) ;
return V_19 ;
}
return 0 ;
}
static void F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
if ( F_7 ( V_21 ) )
V_23 -> V_24 = F_8 ( V_21 ) ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_25 ;
if ( ! F_10 ( V_23 -> V_26 ,
V_27 ,
V_28 ) )
return 0 ;
V_25 = F_11 ( V_21 , 0 ) ;
if ( V_25 )
return V_25 ;
V_23 -> V_29 = F_12 ( V_21 ) + F_13 ( V_21 ) ;
V_23 -> V_30 = F_13 ( V_21 ) ;
V_23 -> V_31 = V_21 -> V_32 - V_23 -> V_29 ;
V_23 -> V_33 = F_14 ( V_21 ) -> V_34 ;
F_15 ( L_2 , V_23 -> V_29 ) ;
F_15 ( L_3 ,
V_23 -> V_30 , V_23 -> V_31 ) ;
F_15 ( L_4 , V_23 -> V_33 ) ;
V_23 -> V_35 = F_14 ( V_21 ) -> V_36 ;
V_23 -> V_37 += ( V_23 -> V_35 - 1 ) * V_23 -> V_29 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
if ( V_21 -> V_38 != V_39 )
return 0 ;
if ( ! F_17 ( V_21 ) )
return 0 ;
return 1 ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_40 * V_41 ;
unsigned int V_42 ;
unsigned int V_32 ;
unsigned int V_43 ;
V_23 -> V_21 = V_21 ;
V_42 = 0 ;
V_23 -> V_44 = 0 ;
V_23 -> V_35 = 1 ;
V_23 -> V_37 = V_21 -> V_32 ;
if ( F_16 ( V_21 ) ) {
if ( F_14 ( V_21 ) -> V_34 != V_2 -> V_14 . V_45 ) {
V_42 = 1 ;
V_23 -> V_44 ++ ;
}
V_23 -> V_44 ++ ;
V_23 -> V_26 = F_19 (
V_23 -> V_26 ,
V_27 ,
V_28 ,
1 ) ;
V_23 -> V_26 = F_19 (
V_23 -> V_26 ,
V_46 ,
V_47 ,
1 ) ;
} else if ( V_21 -> V_38 == V_39 )
V_23 -> V_26 = F_19 (
V_23 -> V_26 ,
V_46 ,
V_47 ,
1 ) ;
if ( F_7 ( V_21 ) ) {
if ( F_8 ( V_21 ) != V_2 -> V_14 . V_48 )
if ( ! V_42 ) {
V_42 = 1 ;
V_23 -> V_44 ++ ;
}
V_23 -> V_26 = F_19 (
V_23 -> V_26 ,
V_49 ,
V_50 ,
1 ) ;
}
for ( V_32 = F_20 ( V_21 ) ; V_32 ; ) {
V_23 -> V_44 ++ ;
V_32 -= F_21 (unsigned int, len, XLGMAC_TX_MAX_BUF_SIZE) ;
}
for ( V_43 = 0 ; V_43 < F_14 ( V_21 ) -> V_51 ; V_43 ++ ) {
V_41 = & F_14 ( V_21 ) -> V_52 [ V_43 ] ;
for ( V_32 = F_22 ( V_41 ) ; V_32 ; ) {
V_23 -> V_44 ++ ;
V_32 -= F_21 (unsigned int, len, XLGMAC_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_23 ( struct V_53 * V_12 , unsigned int V_54 )
{
unsigned int V_55 ;
if ( V_54 > V_56 ) {
F_24 ( V_12 , L_5 ) ;
return - V_57 ;
}
V_55 = V_54 + V_58 + V_59 + V_60 ;
V_55 = F_25 ( V_55 , V_61 , V_62 ) ;
V_55 = ( V_55 + V_63 - 1 ) &
~ ( V_63 - 1 ) ;
return V_55 ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_64 * V_17 = & V_10 -> V_17 ;
struct V_6 * V_7 ;
enum V_65 V_66 ;
unsigned int V_43 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( V_7 -> V_69 && V_7 -> V_70 )
V_66 = V_71 ;
else if ( V_7 -> V_69 )
V_66 = V_72 ;
else if ( V_7 -> V_70 )
V_66 = V_73 ;
else
continue;
V_17 -> V_74 ( V_7 , V_66 ) ;
}
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_64 * V_17 = & V_10 -> V_17 ;
struct V_6 * V_7 ;
enum V_65 V_66 ;
unsigned int V_43 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( V_7 -> V_69 && V_7 -> V_70 )
V_66 = V_71 ;
else if ( V_7 -> V_69 )
V_66 = V_72 ;
else if ( V_7 -> V_70 )
V_66 = V_73 ;
else
continue;
V_17 -> V_75 ( V_7 , V_66 ) ;
}
}
static T_1 F_28 ( int V_76 , void * V_77 )
{
unsigned int V_78 , V_79 , V_80 ;
struct V_9 * V_10 = V_77 ;
struct V_6 * V_7 ;
struct V_64 * V_17 ;
unsigned int V_43 , V_81 , V_82 ;
V_17 = & V_10 -> V_17 ;
V_78 = F_29 ( V_10 -> V_83 + V_84 ) ;
if ( ! V_78 )
return V_85 ;
F_30 ( V_10 , V_86 , V_10 -> V_12 , L_6 , V_78 ) ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ ) {
if ( ! ( V_78 & ( 1 << V_43 ) ) )
continue;
V_7 = V_10 -> V_67 + V_43 ;
V_79 = F_29 ( F_31 ( V_7 , V_87 ) ) ;
F_30 ( V_10 , V_86 , V_10 -> V_12 , L_7 ,
V_43 , V_79 ) ;
V_81 = F_10 ( V_79 , V_88 ,
V_89 ) ;
V_82 = F_10 ( V_79 , V_90 ,
V_91 ) ;
if ( ! V_10 -> V_92 && ( V_81 || V_82 ) ) {
if ( F_32 ( & V_10 -> V_93 ) ) {
F_27 ( V_10 ) ;
V_10 -> V_94 . V_95 ++ ;
F_33 ( & V_10 -> V_93 ) ;
}
}
if ( F_10 ( V_79 , V_96 ,
V_97 ) )
V_10 -> V_94 . V_98 ++ ;
if ( F_10 ( V_79 , V_99 ,
V_100 ) )
V_10 -> V_94 . V_101 ++ ;
if ( F_10 ( V_79 , V_102 ,
V_103 ) )
V_10 -> V_94 . V_104 ++ ;
if ( F_10 ( V_79 , V_105 ,
V_106 ) )
V_10 -> V_94 . V_107 ++ ;
if ( F_10 ( V_79 , V_108 ,
V_109 ) ) {
V_10 -> V_94 . V_110 ++ ;
F_34 ( & V_10 -> V_111 ) ;
}
F_35 ( V_79 , F_31 ( V_7 , V_87 ) ) ;
}
if ( F_10 ( V_78 , V_112 ,
V_113 ) ) {
V_80 = F_29 ( V_10 -> V_83 + V_114 ) ;
if ( F_10 ( V_80 , V_115 ,
V_116 ) )
V_17 -> V_117 ( V_10 ) ;
if ( F_10 ( V_80 , V_118 ,
V_119 ) )
V_17 -> V_120 ( V_10 ) ;
}
return V_85 ;
}
static T_1 F_36 ( int V_76 , void * V_77 )
{
struct V_6 * V_7 = V_77 ;
if ( F_32 ( & V_7 -> V_93 ) ) {
F_37 ( V_7 -> V_121 ) ;
F_33 ( & V_7 -> V_93 ) ;
}
return V_85 ;
}
static void F_38 ( unsigned long V_77 )
{
struct V_6 * V_7 = (struct V_6 * ) V_77 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_122 * V_93 ;
V_93 = ( V_10 -> V_92 ) ? & V_7 -> V_93 : & V_10 -> V_93 ;
if ( F_32 ( V_93 ) ) {
if ( V_10 -> V_92 )
F_37 ( V_7 -> V_121 ) ;
else
F_27 ( V_10 ) ;
V_10 -> V_94 . V_123 ++ ;
F_39 ( V_93 ) ;
}
V_7 -> V_124 = 0 ;
}
static void F_40 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( ! V_7 -> V_69 )
break;
F_41 ( & V_7 -> V_125 , F_38 ,
( unsigned long ) V_7 ) ;
}
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( ! V_7 -> V_69 )
break;
F_43 ( & V_7 -> V_125 ) ;
}
}
static void F_44 ( struct V_9 * V_10 , unsigned int V_126 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
if ( V_10 -> V_92 ) {
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( V_126 )
F_45 ( V_10 -> V_12 , & V_7 -> V_93 ,
V_127 ,
V_128 ) ;
F_46 ( & V_7 -> V_93 ) ;
}
} else {
if ( V_126 )
F_45 ( V_10 -> V_12 , & V_10 -> V_93 ,
V_129 , V_128 ) ;
F_46 ( & V_10 -> V_93 ) ;
}
}
static void F_47 ( struct V_9 * V_10 , unsigned int V_130 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
if ( V_10 -> V_92 ) {
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
F_48 ( & V_7 -> V_93 ) ;
if ( V_130 )
F_49 ( & V_7 -> V_93 ) ;
}
} else {
F_48 ( & V_10 -> V_93 ) ;
if ( V_130 )
F_49 ( & V_10 -> V_93 ) ;
}
}
static int F_50 ( struct V_9 * V_10 )
{
struct V_53 * V_12 = V_10 -> V_12 ;
struct V_6 * V_7 ;
unsigned int V_43 ;
int V_25 ;
V_25 = F_51 ( V_10 -> V_131 , V_10 -> V_132 , F_28 ,
V_133 , V_12 -> V_134 , V_10 ) ;
if ( V_25 ) {
F_24 ( V_12 , L_8 ,
V_10 -> V_132 ) ;
return V_25 ;
}
if ( ! V_10 -> V_92 )
return 0 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
snprintf ( V_7 -> V_135 ,
sizeof( V_7 -> V_135 ) - 1 ,
L_9 , F_52 ( V_12 ) ,
V_7 -> V_13 ) ;
V_25 = F_51 ( V_10 -> V_131 , V_7 -> V_121 ,
F_36 , 0 ,
V_7 -> V_135 , V_7 ) ;
if ( V_25 ) {
F_24 ( V_12 , L_8 ,
V_7 -> V_121 ) ;
goto V_136;
}
}
return 0 ;
V_136:
for ( V_43 -- , V_7 -- ; V_43 < V_10 -> V_68 ; V_43 -- , V_7 -- )
F_53 ( V_10 -> V_131 , V_7 -> V_121 , V_7 ) ;
F_53 ( V_10 -> V_131 , V_10 -> V_132 , V_10 ) ;
return V_25 ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
F_53 ( V_10 -> V_131 , V_10 -> V_132 , V_10 ) ;
if ( ! V_10 -> V_92 )
return;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ )
F_53 ( V_10 -> V_131 , V_7 -> V_121 , V_7 ) ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_137 * V_138 = & V_10 -> V_138 ;
struct V_139 * V_140 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned int V_43 , V_141 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
V_2 = V_7 -> V_69 ;
if ( ! V_2 )
break;
for ( V_141 = 0 ; V_141 < V_2 -> V_3 ; V_141 ++ ) {
V_140 = F_56 ( V_2 , V_141 ) ;
V_138 -> V_142 ( V_10 , V_140 ) ;
}
}
}
static void F_57 ( struct V_9 * V_10 )
{
struct V_137 * V_138 = & V_10 -> V_138 ;
struct V_139 * V_140 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned int V_43 , V_141 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
V_2 = V_7 -> V_70 ;
if ( ! V_2 )
break;
for ( V_141 = 0 ; V_141 < V_2 -> V_3 ; V_141 ++ ) {
V_140 = F_56 ( V_2 , V_141 ) ;
V_138 -> V_142 ( V_10 , V_140 ) ;
}
}
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_64 * V_17 = & V_10 -> V_17 ;
struct V_53 * V_12 = V_10 -> V_12 ;
int V_25 ;
V_17 -> V_143 ( V_10 ) ;
F_44 ( V_10 , 1 ) ;
V_25 = F_50 ( V_10 ) ;
if ( V_25 )
goto V_144;
V_17 -> V_145 ( V_10 ) ;
V_17 -> V_146 ( V_10 ) ;
F_59 ( V_12 ) ;
return 0 ;
V_144:
F_47 ( V_10 , 1 ) ;
V_17 -> exit ( V_10 ) ;
return V_25 ;
}
static void F_60 ( struct V_9 * V_10 )
{
struct V_64 * V_17 = & V_10 -> V_17 ;
struct V_53 * V_12 = V_10 -> V_12 ;
struct V_6 * V_7 ;
struct V_147 * V_148 ;
unsigned int V_43 ;
F_61 ( V_12 ) ;
F_42 ( V_10 ) ;
V_17 -> V_149 ( V_10 ) ;
V_17 -> V_150 ( V_10 ) ;
F_54 ( V_10 ) ;
F_47 ( V_10 , 1 ) ;
V_17 -> exit ( V_10 ) ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
if ( ! V_7 -> V_69 )
continue;
V_148 = F_62 ( V_12 , V_7 -> V_13 ) ;
F_63 ( V_148 ) ;
}
}
static void F_64 ( struct V_9 * V_10 )
{
if ( ! F_65 ( V_10 -> V_12 ) )
return;
F_60 ( V_10 ) ;
F_55 ( V_10 ) ;
F_57 ( V_10 ) ;
F_58 ( V_10 ) ;
}
static void F_66 ( struct V_151 * V_152 )
{
struct V_9 * V_10 = F_67 ( V_152 ,
struct V_9 ,
V_111 ) ;
F_68 () ;
F_64 ( V_10 ) ;
F_69 () ;
}
static int F_70 ( struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_137 * V_138 ;
int V_25 ;
V_138 = & V_10 -> V_138 ;
V_25 = F_23 ( V_12 , V_12 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_10 -> V_55 = V_25 ;
V_25 = V_138 -> V_153 ( V_10 ) ;
if ( V_25 )
return V_25 ;
F_72 ( & V_10 -> V_111 , F_66 ) ;
F_40 ( V_10 ) ;
V_25 = F_58 ( V_10 ) ;
if ( V_25 )
goto V_154;
return 0 ;
V_154:
V_138 -> V_155 ( V_10 ) ;
return V_25 ;
}
static int F_73 ( struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_137 * V_138 ;
V_138 = & V_10 -> V_138 ;
F_60 ( V_10 ) ;
V_138 -> V_155 ( V_10 ) ;
return 0 ;
}
static void F_74 ( struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
F_75 ( V_12 , L_10 ) ;
F_34 ( & V_10 -> V_111 ) ;
}
static int F_76 ( struct V_20 * V_21 , struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_22 * V_156 ;
struct V_137 * V_138 ;
struct V_6 * V_7 ;
struct V_64 * V_17 ;
struct V_147 * V_148 ;
struct V_1 * V_2 ;
int V_25 ;
V_138 = & V_10 -> V_138 ;
V_17 = & V_10 -> V_17 ;
F_15 ( L_11 , V_21 -> V_32 ) ;
V_7 = V_10 -> V_67 + V_21 -> V_157 ;
V_148 = F_62 ( V_12 , V_7 -> V_13 ) ;
V_2 = V_7 -> V_69 ;
V_156 = & V_2 -> V_23 ;
if ( V_21 -> V_32 == 0 ) {
F_77 ( V_10 , V_158 , V_12 ,
L_12 ) ;
F_78 ( V_21 ) ;
return V_159 ;
}
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
F_18 ( V_10 , V_2 , V_21 , V_156 ) ;
V_25 = F_3 ( V_7 , V_2 ,
V_156 -> V_44 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_9 ( V_21 , V_156 ) ;
if ( V_25 ) {
F_77 ( V_10 , V_158 , V_12 ,
L_13 ) ;
F_78 ( V_21 ) ;
return V_25 ;
}
F_6 ( V_21 , V_156 ) ;
if ( ! V_138 -> V_160 ( V_7 , V_21 ) ) {
F_78 ( V_21 ) ;
return V_159 ;
}
F_79 ( V_148 , V_156 -> V_37 ) ;
V_17 -> V_161 ( V_7 ) ;
if ( F_80 ( V_10 ) )
F_81 ( V_12 , V_21 , true ) ;
F_3 ( V_7 , V_2 , V_162 ) ;
return V_159 ;
}
static void F_82 ( struct V_53 * V_12 ,
struct V_163 * V_164 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_165 * V_166 = & V_10 -> V_94 ;
V_10 -> V_17 . V_167 ( V_10 ) ;
V_164 -> V_168 = V_166 -> V_169 ;
V_164 -> V_170 = V_166 -> V_171 ;
V_164 -> V_172 = V_166 -> V_169 -
V_166 -> V_173 -
V_166 -> V_174 -
V_166 -> V_175 ;
V_164 -> V_176 = V_166 -> V_174 ;
V_164 -> V_177 = V_166 -> V_178 ;
V_164 -> V_179 = V_166 -> V_180 ;
V_164 -> V_181 = V_166 -> V_182 ;
V_164 -> V_35 = V_166 -> V_183 ;
V_164 -> V_37 = V_166 -> V_184 ;
V_164 -> V_185 = V_166 -> V_183 - V_166 -> V_186 ;
V_164 -> V_187 = V_12 -> V_94 . V_187 ;
}
static int F_83 ( struct V_53 * V_12 , void * V_188 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_64 * V_17 = & V_10 -> V_17 ;
struct V_189 * V_190 = V_188 ;
if ( ! F_84 ( V_190 -> V_191 ) )
return - V_192 ;
memcpy ( V_12 -> V_193 , V_190 -> V_191 , V_12 -> V_194 ) ;
V_17 -> V_195 ( V_10 , V_12 -> V_193 ) ;
return 0 ;
}
static int F_85 ( struct V_53 * V_12 ,
struct V_196 * V_196 , int V_197 )
{
if ( ! F_65 ( V_12 ) )
return - V_198 ;
return 0 ;
}
static int F_86 ( struct V_53 * V_12 , int V_54 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
int V_25 ;
V_25 = F_23 ( V_12 , V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_10 -> V_55 = V_25 ;
V_12 -> V_54 = V_54 ;
F_64 ( V_10 ) ;
return 0 ;
}
static int F_87 ( struct V_53 * V_12 ,
T_2 V_199 ,
T_3 V_200 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_64 * V_17 = & V_10 -> V_17 ;
F_88 ( V_200 , V_10 -> V_201 ) ;
V_17 -> V_202 ( V_10 ) ;
return 0 ;
}
static int F_89 ( struct V_53 * V_12 ,
T_2 V_199 ,
T_3 V_200 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_64 * V_17 = & V_10 -> V_17 ;
F_90 ( V_200 , V_10 -> V_201 ) ;
V_17 -> V_202 ( V_10 ) ;
return 0 ;
}
static void F_91 ( struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_6 * V_7 ;
unsigned int V_43 ;
if ( V_10 -> V_92 ) {
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ )
F_36 ( V_7 -> V_121 , V_7 ) ;
} else {
F_92 ( V_10 -> V_132 ) ;
F_28 ( V_10 -> V_132 , V_10 ) ;
F_93 ( V_10 -> V_132 ) ;
}
}
static int F_94 ( struct V_53 * V_12 ,
T_4 V_203 )
{
T_4 V_204 , V_205 , V_206 , V_207 ;
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_64 * V_17 = & V_10 -> V_17 ;
int V_25 = 0 ;
V_204 = V_10 -> V_208 & V_209 ;
V_205 = V_10 -> V_208 & V_210 ;
V_206 = V_10 -> V_208 & V_211 ;
V_207 = V_10 -> V_208 & V_212 ;
if ( ( V_203 & V_209 ) && ! V_204 )
V_25 = V_17 -> V_213 ( V_10 ) ;
else if ( ! ( V_203 & V_209 ) && V_204 )
V_25 = V_17 -> V_214 ( V_10 ) ;
if ( V_25 )
return V_25 ;
if ( ( V_203 & V_210 ) && ! V_205 )
V_17 -> V_215 ( V_10 ) ;
else if ( ! ( V_203 & V_210 ) && V_205 )
V_17 -> V_216 ( V_10 ) ;
if ( ( V_203 & V_211 ) && ! V_206 )
V_17 -> V_217 ( V_10 ) ;
else if ( ! ( V_203 & V_211 ) && V_206 )
V_17 -> V_218 ( V_10 ) ;
if ( ( V_203 & V_212 ) && ! V_207 )
V_17 -> V_219 ( V_10 ) ;
else if ( ! ( V_203 & V_212 ) && V_207 )
V_17 -> V_220 ( V_10 ) ;
V_10 -> V_208 = V_203 ;
return 0 ;
}
static void F_95 ( struct V_53 * V_12 )
{
struct V_9 * V_10 = F_71 ( V_12 ) ;
struct V_64 * V_17 = & V_10 -> V_17 ;
V_17 -> V_221 ( V_10 ) ;
}
const struct V_222 * F_96 ( void )
{
return & V_223 ;
}
static void F_97 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_70 ;
struct V_139 * V_140 ;
struct V_137 * V_138 ;
struct V_64 * V_17 ;
V_138 = & V_10 -> V_138 ;
V_17 = & V_10 -> V_17 ;
while ( V_2 -> V_5 != V_2 -> V_4 ) {
V_140 = F_56 ( V_2 , V_2 -> V_5 ) ;
V_138 -> V_142 ( V_10 , V_140 ) ;
if ( V_138 -> V_224 ( V_10 , V_2 , V_140 ) )
break;
V_17 -> V_225 ( V_10 , V_140 , V_2 -> V_5 ) ;
V_2 -> V_5 ++ ;
}
F_98 () ;
V_140 = F_56 ( V_2 , V_2 -> V_5 - 1 ) ;
F_35 ( F_99 ( V_140 -> V_226 ) ,
F_31 ( V_7 , V_227 ) ) ;
}
static struct V_20 * F_100 ( struct V_9 * V_10 ,
struct V_122 * V_93 ,
struct V_139 * V_140 ,
unsigned int V_32 )
{
unsigned int V_228 ;
struct V_20 * V_21 ;
T_5 * V_229 ;
V_21 = F_101 ( V_93 , V_140 -> V_230 . V_231 . V_232 ) ;
if ( ! V_21 )
return NULL ;
F_102 ( V_10 -> V_131 , V_140 -> V_230 . V_231 . V_233 ,
V_140 -> V_230 . V_231 . V_234 ,
V_140 -> V_230 . V_231 . V_232 ,
V_235 ) ;
V_229 = F_103 ( V_140 -> V_230 . V_231 . V_236 . V_237 ) +
V_140 -> V_230 . V_231 . V_236 . V_238 ;
V_228 = ( V_140 -> V_230 . V_239 ) ? V_140 -> V_230 . V_239 : V_32 ;
V_228 = F_104 ( V_140 -> V_230 . V_231 . V_232 , V_228 ) ;
F_105 ( V_21 , V_229 , V_228 ) ;
F_106 ( V_21 , V_228 ) ;
V_32 -= V_228 ;
if ( V_32 ) {
F_102 ( V_10 -> V_131 ,
V_140 -> V_230 . V_240 . V_233 ,
V_140 -> V_230 . V_240 . V_234 ,
V_140 -> V_230 . V_240 . V_232 ,
V_235 ) ;
F_107 ( V_21 , F_14 ( V_21 ) -> V_51 ,
V_140 -> V_230 . V_240 . V_236 . V_237 ,
V_140 -> V_230 . V_240 . V_236 . V_238 ,
V_32 , V_140 -> V_230 . V_240 . V_232 ) ;
V_140 -> V_230 . V_240 . V_236 . V_237 = NULL ;
}
return V_21 ;
}
static int F_108 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_69 ;
struct V_53 * V_12 = V_10 -> V_12 ;
unsigned int V_35 = 0 , V_37 = 0 ;
struct V_139 * V_140 ;
struct V_241 * V_242 ;
struct V_137 * V_138 ;
struct V_64 * V_17 ;
struct V_147 * V_148 ;
int V_243 = 0 ;
unsigned int V_4 ;
V_138 = & V_10 -> V_138 ;
V_17 = & V_10 -> V_17 ;
if ( ! V_2 )
return 0 ;
V_4 = V_2 -> V_4 ;
F_109 () ;
V_148 = F_62 ( V_12 , V_7 -> V_13 ) ;
while ( ( V_243 < V_244 ) &&
( V_2 -> V_5 != V_4 ) ) {
V_140 = F_56 ( V_2 , V_2 -> V_5 ) ;
V_242 = V_140 -> V_242 ;
if ( ! V_17 -> V_245 ( V_242 ) )
break;
F_110 () ;
if ( F_111 ( V_10 ) )
F_112 ( V_10 , V_2 , V_2 -> V_5 , 1 , 0 ) ;
if ( V_17 -> V_246 ( V_242 ) ) {
V_35 += V_140 -> V_14 . V_247 ;
V_37 += V_140 -> V_14 . V_248 ;
}
V_138 -> V_142 ( V_10 , V_140 ) ;
V_17 -> V_249 ( V_140 ) ;
V_243 ++ ;
V_2 -> V_5 ++ ;
}
if ( ! V_243 )
return 0 ;
F_113 ( V_148 , V_35 , V_37 ) ;
if ( ( V_2 -> V_14 . V_15 == 1 ) &&
( F_1 ( V_2 ) > V_250 ) ) {
V_2 -> V_14 . V_15 = 0 ;
F_114 ( V_148 ) ;
}
F_15 ( L_14 , V_243 ) ;
return V_243 ;
}
static int F_115 ( struct V_6 * V_7 , int V_251 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_70 ;
struct V_53 * V_12 = V_10 -> V_12 ;
unsigned int V_32 , V_252 , V_253 ;
unsigned int V_254 , V_255 ;
struct V_139 * V_140 ;
struct V_22 * V_23 ;
unsigned int V_256 , error ;
struct V_64 * V_17 ;
unsigned int V_257 = 0 ;
struct V_122 * V_93 ;
struct V_20 * V_21 ;
int V_258 = 0 ;
V_17 = & V_10 -> V_17 ;
if ( ! V_2 )
return 0 ;
V_256 = 0 ;
V_254 = 0 ;
V_93 = ( V_10 -> V_92 ) ? & V_7 -> V_93 : & V_10 -> V_93 ;
V_140 = F_56 ( V_2 , V_2 -> V_4 ) ;
V_23 = & V_2 -> V_23 ;
while ( V_258 < V_251 ) {
if ( ! V_257 && V_140 -> V_259 ) {
V_21 = V_140 -> V_260 . V_21 ;
error = V_140 -> V_260 . error ;
V_32 = V_140 -> V_260 . V_32 ;
} else {
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_21 = NULL ;
error = 0 ;
V_32 = 0 ;
}
V_261:
V_140 = F_56 ( V_2 , V_2 -> V_4 ) ;
if ( F_2 ( V_2 ) > V_262 )
F_97 ( V_7 ) ;
if ( V_17 -> V_263 ( V_7 ) )
break;
V_257 ++ ;
V_2 -> V_4 ++ ;
V_256 = F_10 (
V_23 -> V_26 ,
V_264 ,
V_265 ) ;
V_254 = F_10 (
V_23 -> V_26 ,
V_266 ,
V_267 ) ;
V_255 = F_10 (
V_23 -> V_26 ,
V_268 ,
V_269 ) ;
if ( ( V_256 || V_254 ) && error )
goto V_261;
if ( error || V_23 -> V_270 ) {
if ( V_23 -> V_270 )
F_77 ( V_10 , V_271 , V_12 ,
L_15 ) ;
F_116 ( V_21 ) ;
goto V_272;
}
if ( ! V_255 ) {
V_252 = V_140 -> V_230 . V_32 - V_32 ;
V_32 += V_252 ;
if ( V_252 && ! V_21 ) {
V_21 = F_100 ( V_10 , V_93 , V_140 ,
V_252 ) ;
if ( ! V_21 )
error = 1 ;
} else if ( V_252 ) {
F_102 (
V_10 -> V_131 ,
V_140 -> V_230 . V_240 . V_233 ,
V_140 -> V_230 . V_240 . V_234 ,
V_140 -> V_230 . V_240 . V_232 ,
V_235 ) ;
F_107 (
V_21 , F_14 ( V_21 ) -> V_51 ,
V_140 -> V_230 . V_240 . V_236 . V_237 ,
V_140 -> V_230 . V_240 . V_236 . V_238 ,
V_252 ,
V_140 -> V_230 . V_240 . V_232 ) ;
V_140 -> V_230 . V_240 . V_236 . V_237 = NULL ;
}
}
if ( V_256 || V_254 )
goto V_261;
if ( ! V_21 )
goto V_272;
V_253 = V_12 -> V_54 + V_58 ;
if ( ! ( V_12 -> V_203 & V_211 ) &&
( V_21 -> V_273 == F_117 ( V_274 ) ) )
V_253 += V_60 ;
if ( V_21 -> V_32 > V_253 ) {
F_77 ( V_10 , V_271 , V_12 ,
L_16 ) ;
F_116 ( V_21 ) ;
goto V_272;
}
if ( F_80 ( V_10 ) )
F_81 ( V_12 , V_21 , false ) ;
F_118 ( V_21 ) ;
if ( F_10 ( V_23 -> V_26 ,
V_275 ,
V_276 ) )
V_21 -> V_38 = V_277 ;
if ( F_10 ( V_23 -> V_26 ,
V_278 ,
V_279 ) ) {
F_119 ( V_21 , F_117 ( V_274 ) ,
V_23 -> V_24 ) ;
V_10 -> V_94 . V_280 ++ ;
}
if ( F_10 ( V_23 -> V_26 ,
V_281 ,
V_282 ) )
F_120 ( V_21 , V_23 -> V_283 ,
V_23 -> V_284 ) ;
V_21 -> V_131 = V_12 ;
V_21 -> V_273 = F_121 ( V_21 , V_12 ) ;
F_122 ( V_21 , V_7 -> V_13 ) ;
F_123 ( V_93 , V_21 ) ;
V_272:
V_258 ++ ;
}
if ( V_257 && ( V_256 || V_254 ) ) {
V_140 = F_56 ( V_2 , V_2 -> V_4 ) ;
V_140 -> V_259 = 1 ;
V_140 -> V_260 . V_21 = V_21 ;
V_140 -> V_260 . V_32 = V_32 ;
V_140 -> V_260 . error = error ;
}
F_15 ( L_17 , V_258 ) ;
return V_258 ;
}
static int V_127 ( struct V_122 * V_93 , int V_251 )
{
struct V_6 * V_7 = F_67 ( V_93 ,
struct V_6 ,
V_93 ) ;
int V_243 = 0 ;
F_15 ( L_18 , V_251 ) ;
F_108 ( V_7 ) ;
V_243 = F_115 ( V_7 , V_251 ) ;
if ( V_243 < V_251 ) {
F_124 ( V_93 , V_243 ) ;
F_93 ( V_7 -> V_121 ) ;
}
F_15 ( L_19 , V_243 ) ;
return V_243 ;
}
static int V_129 ( struct V_122 * V_93 , int V_251 )
{
struct V_9 * V_10 = F_67 ( V_93 ,
struct V_9 ,
V_93 ) ;
struct V_6 * V_7 ;
int V_243 , V_285 ;
int V_286 ;
unsigned int V_43 ;
F_15 ( L_18 , V_251 ) ;
V_243 = 0 ;
V_286 = V_251 / V_10 -> V_287 ;
do {
V_285 = V_243 ;
V_7 = V_10 -> V_67 ;
for ( V_43 = 0 ; V_43 < V_10 -> V_68 ; V_43 ++ , V_7 ++ ) {
F_108 ( V_7 ) ;
if ( V_286 > ( V_251 - V_243 ) )
V_286 = V_251 - V_243 ;
V_243 += F_115 ( V_7 , V_286 ) ;
}
} while ( ( V_243 < V_251 ) && ( V_243 != V_285 ) );
if ( V_243 < V_251 ) {
F_124 ( V_93 , V_243 ) ;
F_26 ( V_10 ) ;
}
F_15 ( L_19 , V_243 ) ;
return V_243 ;
}
