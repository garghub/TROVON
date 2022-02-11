void F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
union {
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
} V_10 ;
V_10 . V_9 = V_3 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_10 . V_6 -> V_13 = V_4 ;
F_2 ( F_3 ( & V_10 . V_6 -> V_13 ) ) ;
break;
case V_14 :
V_10 . V_8 -> V_13 = V_4 ;
F_2 ( F_3 ( & V_10 . V_8 -> V_13 ) ) ;
break;
default:
F_4 ( L_1 ) ;
F_5 () ;
}
F_6 () ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
union {
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
} V_10 ;
F_8 () ;
V_10 . V_9 = V_3 ;
switch ( V_2 -> V_11 ) {
case V_12 :
F_2 ( F_3 ( & V_10 . V_6 -> V_13 ) ) ;
return V_10 . V_6 -> V_13 ;
case V_14 :
F_2 ( F_3 ( & V_10 . V_8 -> V_13 ) ) ;
return V_10 . V_8 -> V_13 ;
default:
F_4 ( L_1 ) ;
F_5 () ;
return 0 ;
}
}
static void * F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_17 ,
int V_4 )
{
unsigned int V_18 , V_19 ;
union {
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
} V_10 ;
V_18 = V_17 / V_16 -> V_20 ;
V_19 = V_17 % V_16 -> V_20 ;
V_10 . V_9 = V_16 -> V_21 [ V_18 ] . V_22 +
( V_19 * V_16 -> V_23 ) ;
if ( V_4 != F_7 ( V_2 , V_10 . V_9 ) )
return NULL ;
return V_10 . V_9 ;
}
static inline void * F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_4 )
{
return F_9 ( V_2 , V_16 , V_16 -> V_24 , V_4 ) ;
}
static inline void * F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_4 )
{
unsigned int V_25 = V_16 -> V_24 ? V_16 -> V_24 - 1 : V_16 -> V_26 ;
return F_9 ( V_2 , V_16 , V_25 , V_4 ) ;
}
static inline void F_12 ( struct V_15 * V_27 )
{
V_27 -> V_24 = V_27 -> V_24 != V_27 -> V_26 ? V_27 -> V_24 + 1 : 0 ;
}
static inline struct V_1 * F_13 ( struct V_28 * V_29 )
{
return (struct V_1 * ) V_29 ;
}
static void F_14 ( struct V_28 * V_29 )
{
F_15 ( & V_29 -> V_30 ) ;
F_16 ( F_17 ( & V_29 -> V_31 ) ) ;
F_16 ( F_17 ( & V_29 -> V_32 ) ) ;
if ( ! F_18 ( V_29 , V_33 ) ) {
F_4 ( L_2 , V_29 ) ;
return;
}
F_19 ( V_29 ) ;
}
static int F_20 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_36 * V_40 )
{
struct V_28 * V_29 ;
struct V_41 * V_42 ;
V_29 = V_39 -> V_43 ;
if ( V_35 -> V_44 == V_45 )
goto V_46;
if ( ! F_21 ( F_22 ( V_37 ) , F_23 ( V_29 ) ) )
goto V_46;
V_35 = F_24 ( V_35 , V_47 ) ;
if ( V_35 == NULL )
goto V_48;
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
V_42 = & F_27 ( V_35 ) -> V_49 . V_50 ;
F_28 ( V_35 , V_35 -> V_51 - F_29 ( V_35 ) ) ;
V_42 -> V_52 = V_37 -> type ;
F_30 ( V_42 -> V_53 , V_37 -> V_54 , sizeof( V_42 -> V_53 ) ) ;
V_42 -> V_55 = V_35 -> V_56 ;
if ( F_31 ( V_29 , V_35 ) == 0 )
return 0 ;
V_46:
F_32 ( V_35 ) ;
V_48:
return 0 ;
}
static int F_33 ( struct V_57 * V_58 , struct V_59 * V_28 ,
struct V_60 * V_61 , T_1 V_62 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_41 * V_63 = (struct V_41 * ) V_61 -> V_64 ;
struct V_34 * V_35 = NULL ;
struct V_36 * V_37 ;
T_2 V_65 = 0 ;
int V_66 ;
if ( V_63 ) {
if ( V_61 -> V_67 < sizeof( struct V_68 ) )
return - V_69 ;
if ( V_61 -> V_67 == sizeof( struct V_41 ) )
V_65 = V_63 -> V_55 ;
} else
return - V_70 ;
V_63 -> V_53 [ 13 ] = 0 ;
V_71:
F_34 () ;
V_37 = F_35 ( F_23 ( V_29 ) , V_63 -> V_53 ) ;
V_66 = - V_72 ;
if ( V_37 == NULL )
goto V_73;
V_66 = - V_74 ;
if ( ! ( V_37 -> V_75 & V_76 ) )
goto V_73;
V_66 = - V_77 ;
if ( V_62 > V_37 -> V_78 + V_37 -> V_79 + V_80 )
goto V_73;
if ( ! V_35 ) {
T_1 V_81 = F_36 ( V_37 ) ;
unsigned int V_82 = V_37 -> V_83 ? V_37 -> V_79 : 0 ;
F_37 () ;
V_35 = F_38 ( V_29 , V_62 + V_81 , 0 , V_84 ) ;
if ( V_35 == NULL )
return - V_85 ;
F_39 ( V_35 , V_81 ) ;
F_40 ( V_35 ) ;
if ( V_82 ) {
V_35 -> V_51 -= V_82 ;
V_35 -> V_86 -= V_82 ;
if ( V_62 < V_82 )
F_40 ( V_35 ) ;
}
V_66 = F_41 ( F_42 ( V_35 , V_62 ) , V_61 -> V_87 , V_62 ) ;
if ( V_66 )
goto V_88;
goto V_71;
}
if ( V_62 > ( V_37 -> V_78 + V_37 -> V_79 ) ) {
struct V_89 * V_90 ;
F_43 ( V_35 ) ;
V_90 = F_44 ( V_35 ) ;
if ( V_90 -> V_91 != F_45 ( V_92 ) ) {
V_66 = - V_77 ;
goto V_73;
}
}
V_35 -> V_56 = V_65 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_93 = V_29 -> V_94 ;
V_35 -> V_95 = V_29 -> V_96 ;
V_66 = F_46 ( V_29 , & F_47 ( V_35 ) -> V_97 ) ;
if ( V_66 < 0 )
goto V_73;
F_48 ( V_35 ) ;
F_37 () ;
return V_62 ;
V_73:
F_37 () ;
V_88:
F_32 ( V_35 ) ;
return V_66 ;
}
static inline unsigned int F_49 ( const struct V_34 * V_35 ,
const struct V_28 * V_29 ,
unsigned int V_98 )
{
struct V_99 * V_100 ;
F_34 () ;
V_100 = F_50 ( V_29 -> V_99 ) ;
if ( V_100 != NULL )
V_98 = F_51 ( V_100 , V_35 ) ;
F_37 () ;
return V_98 ;
}
static int F_52 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_36 * V_40 )
{
struct V_28 * V_29 ;
struct V_101 * V_102 ;
struct V_1 * V_2 ;
T_3 * V_103 = V_35 -> V_51 ;
int V_104 = V_35 -> V_62 ;
unsigned int V_105 , V_98 ;
if ( V_35 -> V_44 == V_45 )
goto V_106;
V_29 = V_39 -> V_43 ;
V_2 = F_13 ( V_29 ) ;
if ( ! F_21 ( F_22 ( V_37 ) , F_23 ( V_29 ) ) )
goto V_106;
V_35 -> V_37 = V_37 ;
if ( V_37 -> V_83 ) {
if ( V_29 -> V_107 != V_108 )
F_28 ( V_35 , V_35 -> V_51 - F_29 ( V_35 ) ) ;
else if ( V_35 -> V_44 == V_109 ) {
F_53 ( V_35 , F_54 ( V_35 ) ) ;
}
}
V_105 = V_35 -> V_62 ;
V_98 = F_49 ( V_35 , V_29 , V_105 ) ;
if ( ! V_98 )
goto V_110;
if ( V_105 > V_98 )
V_105 = V_98 ;
if ( F_17 ( & V_29 -> V_31 ) + V_35 -> V_111 >=
( unsigned ) V_29 -> V_112 )
goto V_113;
if ( F_55 ( V_35 ) ) {
struct V_34 * V_114 = F_56 ( V_35 , V_47 ) ;
if ( V_114 == NULL )
goto V_113;
if ( V_103 != V_35 -> V_51 ) {
V_35 -> V_51 = V_103 ;
V_35 -> V_62 = V_104 ;
}
F_32 ( V_35 ) ;
V_35 = V_114 ;
}
F_57 ( sizeof( * F_27 ( V_35 ) ) + V_115 - 8 >
sizeof( V_35 -> V_116 ) ) ;
V_102 = & F_27 ( V_35 ) -> V_49 . V_117 ;
V_102 -> V_118 = V_119 ;
V_102 -> V_120 = V_37 -> type ;
V_102 -> V_121 = V_35 -> V_56 ;
V_102 -> V_122 = V_35 -> V_44 ;
if ( F_58 ( V_2 -> V_123 ) )
V_102 -> V_124 = V_40 -> V_125 ;
else
V_102 -> V_124 = V_37 -> V_125 ;
V_102 -> V_126 = F_59 ( V_35 , V_102 -> V_127 ) ;
F_27 ( V_35 ) -> V_128 = V_35 -> V_62 ;
if ( F_60 ( V_35 , V_105 ) )
goto V_113;
F_61 ( V_35 , V_29 ) ;
V_35 -> V_37 = NULL ;
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
F_62 ( & V_29 -> V_129 . V_130 ) ;
V_2 -> V_131 . V_132 ++ ;
V_35 -> V_133 = F_17 ( & V_29 -> V_134 ) ;
F_63 ( & V_29 -> V_129 , V_35 ) ;
F_64 ( & V_29 -> V_129 . V_130 ) ;
V_29 -> V_135 ( V_29 , V_35 -> V_62 ) ;
return 0 ;
V_113:
V_2 -> V_131 . V_136 = F_65 ( & V_29 -> V_134 ) ;
V_110:
if ( V_103 != V_35 -> V_51 && F_55 ( V_35 ) ) {
V_35 -> V_51 = V_103 ;
V_35 -> V_62 = V_104 ;
}
V_106:
F_66 ( V_35 ) ;
return 0 ;
}
static int F_67 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_36 * V_40 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_101 * V_102 ;
union {
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
} V_10 ;
T_3 * V_103 = V_35 -> V_51 ;
int V_104 = V_35 -> V_62 ;
unsigned int V_105 , V_98 ;
unsigned long V_4 = V_137 | V_138 ;
unsigned short V_139 , V_140 , V_141 ;
struct V_34 * V_142 = NULL ;
struct V_143 V_144 ;
struct V_145 V_146 ;
struct V_147 * V_148 = F_68 ( V_35 ) ;
if ( V_35 -> V_44 == V_45 )
goto V_106;
V_29 = V_39 -> V_43 ;
V_2 = F_13 ( V_29 ) ;
if ( ! F_21 ( F_22 ( V_37 ) , F_23 ( V_29 ) ) )
goto V_106;
if ( V_37 -> V_83 ) {
if ( V_29 -> V_107 != V_108 )
F_28 ( V_35 , V_35 -> V_51 - F_29 ( V_35 ) ) ;
else if ( V_35 -> V_44 == V_109 ) {
F_53 ( V_35 , F_54 ( V_35 ) ) ;
}
}
if ( V_35 -> V_149 == V_150 )
V_4 |= V_151 ;
V_105 = V_35 -> V_62 ;
V_98 = F_49 ( V_35 , V_29 , V_105 ) ;
if ( ! V_98 )
goto V_110;
if ( V_105 > V_98 )
V_105 = V_98 ;
if ( V_29 -> V_107 == V_108 ) {
V_139 = V_140 = F_69 ( V_2 -> V_152 ) + 16 +
V_2 -> V_153 ;
} else {
unsigned V_154 = F_54 ( V_35 ) ;
V_140 = F_69 ( V_2 -> V_152 +
( V_154 < 16 ? 16 : V_154 ) ) +
V_2 -> V_153 ;
V_139 = V_140 - V_154 ;
}
if ( V_139 + V_105 > V_2 -> V_155 . V_23 ) {
if ( V_2 -> V_156 &&
F_17 ( & V_29 -> V_31 ) + V_35 -> V_111 <
( unsigned ) V_29 -> V_112 ) {
if ( F_55 ( V_35 ) ) {
V_142 = F_56 ( V_35 , V_47 ) ;
} else {
V_142 = F_70 ( V_35 ) ;
V_103 = V_35 -> V_51 ;
}
if ( V_142 )
F_61 ( V_142 , V_29 ) ;
}
V_105 = V_2 -> V_155 . V_23 - V_139 ;
if ( ( int ) V_105 < 0 )
V_105 = 0 ;
}
F_62 ( & V_29 -> V_129 . V_130 ) ;
V_10 . V_9 = F_10 ( V_2 , & V_2 -> V_155 , V_157 ) ;
if ( ! V_10 . V_9 )
goto V_158;
F_12 ( & V_2 -> V_155 ) ;
V_2 -> V_131 . V_132 ++ ;
if ( V_142 ) {
V_4 |= V_159 ;
F_63 ( & V_29 -> V_129 , V_142 ) ;
}
if ( ! V_2 -> V_131 . V_136 )
V_4 &= ~ V_137 ;
F_64 ( & V_29 -> V_129 . V_130 ) ;
F_71 ( V_35 , 0 , V_10 . V_9 + V_139 , V_105 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_10 . V_6 -> V_160 = V_35 -> V_62 ;
V_10 . V_6 -> V_161 = V_105 ;
V_10 . V_6 -> V_162 = V_139 ;
V_10 . V_6 -> V_163 = V_140 ;
if ( ( V_2 -> V_164 & V_165 )
&& V_148 -> V_166 . V_167 )
V_144 = F_72 ( V_148 -> V_166 ) ;
else if ( ( V_2 -> V_164 & V_168 )
&& V_148 -> V_169 . V_167 )
V_144 = F_72 ( V_148 -> V_169 ) ;
else if ( V_35 -> V_170 . V_167 )
V_144 = F_72 ( V_35 -> V_170 ) ;
else
F_73 ( & V_144 ) ;
V_10 . V_6 -> V_171 = V_144 . V_172 ;
V_10 . V_6 -> V_173 = V_144 . V_174 ;
V_141 = sizeof( * V_10 . V_6 ) ;
break;
case V_14 :
V_10 . V_8 -> V_160 = V_35 -> V_62 ;
V_10 . V_8 -> V_161 = V_105 ;
V_10 . V_8 -> V_162 = V_139 ;
V_10 . V_8 -> V_163 = V_140 ;
if ( ( V_2 -> V_164 & V_165 )
&& V_148 -> V_166 . V_167 )
V_146 = F_74 ( V_148 -> V_166 ) ;
else if ( ( V_2 -> V_164 & V_168 )
&& V_148 -> V_169 . V_167 )
V_146 = F_74 ( V_148 -> V_169 ) ;
else if ( V_35 -> V_170 . V_167 )
V_146 = F_74 ( V_35 -> V_170 ) ;
else
F_75 ( & V_146 ) ;
V_10 . V_8 -> V_171 = V_146 . V_172 ;
V_10 . V_8 -> V_175 = V_146 . V_176 ;
if ( F_76 ( V_35 ) ) {
V_10 . V_8 -> V_177 = F_77 ( V_35 ) ;
V_4 |= V_178 ;
} else {
V_10 . V_8 -> V_177 = 0 ;
}
V_10 . V_8 -> V_179 = 0 ;
V_141 = sizeof( * V_10 . V_8 ) ;
break;
default:
F_5 () ;
}
V_102 = V_10 . V_9 + F_69 ( V_141 ) ;
V_102 -> V_126 = F_59 ( V_35 , V_102 -> V_127 ) ;
V_102 -> V_118 = V_119 ;
V_102 -> V_120 = V_37 -> type ;
V_102 -> V_121 = V_35 -> V_56 ;
V_102 -> V_122 = V_35 -> V_44 ;
if ( F_58 ( V_2 -> V_123 ) )
V_102 -> V_124 = V_40 -> V_125 ;
else
V_102 -> V_124 = V_37 -> V_125 ;
F_1 ( V_2 , V_10 . V_9 , V_4 ) ;
F_78 () ;
#if V_180 == 1
{
T_3 * V_181 , * V_182 ;
V_182 = ( T_3 * ) F_79 ( ( unsigned long ) V_10 . V_9 + V_139 + V_105 ) ;
for ( V_181 = V_10 . V_9 ; V_181 < V_182 ; V_181 += V_183 )
F_2 ( F_3 ( V_181 ) ) ;
}
#endif
V_29 -> V_135 ( V_29 , 0 ) ;
V_110:
if ( V_103 != V_35 -> V_51 && F_55 ( V_35 ) ) {
V_35 -> V_51 = V_103 ;
V_35 -> V_62 = V_104 ;
}
V_106:
F_32 ( V_35 ) ;
return 0 ;
V_158:
V_2 -> V_131 . V_136 ++ ;
F_64 ( & V_29 -> V_129 . V_130 ) ;
V_29 -> V_135 ( V_29 , 0 ) ;
F_32 ( V_142 ) ;
goto V_110;
}
static void F_80 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_13 ( V_35 -> V_29 ) ;
void * V_184 ;
F_81 ( V_35 == NULL ) ;
if ( F_82 ( V_2 -> V_185 . V_21 ) ) {
V_184 = F_47 ( V_35 ) -> V_186 ;
F_81 ( F_7 ( V_2 , V_184 ) != V_187 ) ;
F_81 ( F_17 ( & V_2 -> V_185 . V_188 ) == 0 ) ;
F_83 ( & V_2 -> V_185 . V_188 ) ;
F_1 ( V_2 , V_184 , V_189 ) ;
}
F_84 ( V_35 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_34 * V_35 ,
void * V_3 , struct V_36 * V_37 , int V_190 ,
T_2 V_65 , unsigned char * V_191 )
{
union {
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
} V_184 ;
int V_192 , V_193 , V_62 , V_160 , V_194 , V_195 ;
struct V_59 * V_28 = V_2 -> V_29 . V_196 ;
struct V_197 * V_197 ;
void * V_51 ;
int V_66 ;
V_184 . V_9 = V_3 ;
V_35 -> V_56 = V_65 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_93 = V_2 -> V_29 . V_94 ;
V_35 -> V_95 = V_2 -> V_29 . V_96 ;
F_47 ( V_35 ) -> V_186 = V_184 . V_9 ;
switch ( V_2 -> V_11 ) {
case V_14 :
V_160 = V_184 . V_8 -> V_160 ;
break;
default:
V_160 = V_184 . V_6 -> V_160 ;
break;
}
if ( F_58 ( V_160 > V_190 ) ) {
F_4 ( L_3 , V_160 , V_190 ) ;
return - V_77 ;
}
F_39 ( V_35 , F_36 ( V_37 ) ) ;
F_40 ( V_35 ) ;
V_51 = V_184 . V_9 + V_2 -> V_152 - sizeof( struct V_101 ) ;
V_192 = V_160 ;
if ( V_28 -> type == V_108 ) {
V_66 = F_86 ( V_35 , V_37 , F_87 ( V_65 ) , V_191 ,
NULL , V_160 ) ;
if ( F_58 ( V_66 < 0 ) )
return - V_69 ;
} else if ( V_37 -> V_79 ) {
if ( F_58 ( V_160 <= V_37 -> V_79 ) ) {
F_4 ( L_4 ,
V_160 , V_37 -> V_79 ) ;
return - V_69 ;
}
F_28 ( V_35 , V_37 -> V_79 ) ;
V_66 = F_88 ( V_35 , 0 , V_51 ,
V_37 -> V_79 ) ;
if ( F_58 ( V_66 ) )
return V_66 ;
V_51 += V_37 -> V_79 ;
V_192 -= V_37 -> V_79 ;
}
V_66 = - V_198 ;
V_193 = F_89 ( V_51 ) ;
V_195 = V_183 - V_193 ;
V_62 = ( ( V_192 > V_195 ) ? V_195 : V_192 ) ;
V_35 -> V_199 = V_192 ;
V_35 -> V_62 += V_192 ;
V_35 -> V_111 += V_192 ;
F_90 ( V_192 , & V_2 -> V_29 . V_32 ) ;
while ( F_82 ( V_192 ) ) {
V_194 = F_47 ( V_35 ) -> V_194 ;
if ( F_58 ( V_194 >= V_200 ) ) {
F_4 ( L_5 ,
V_200 ) ;
return - V_198 ;
}
V_197 = F_3 ( V_51 ) ;
V_51 += V_62 ;
F_2 ( V_197 ) ;
F_91 ( V_197 ) ;
F_92 ( V_35 , V_194 , V_197 , V_193 , V_62 ) ;
V_192 -= V_62 ;
V_193 = 0 ;
V_195 = V_183 ;
V_62 = ( ( V_192 > V_195 ) ? V_195 : V_192 ) ;
}
return V_160 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
T_2 V_65 ;
int V_125 , V_66 , V_201 = 0 ;
void * V_184 ;
struct V_101 * V_63 = (struct V_101 * ) V_61 -> V_64 ;
int V_160 , V_190 ;
unsigned char * V_191 ;
int V_202 = 0 ;
int V_4 = 0 ;
F_94 ( & V_2 -> V_203 ) ;
V_66 = - V_204 ;
if ( V_63 == NULL ) {
V_125 = V_2 -> V_125 ;
V_65 = V_2 -> V_205 ;
V_191 = NULL ;
} else {
V_66 = - V_69 ;
if ( V_61 -> V_67 < sizeof( struct V_101 ) )
goto V_46;
if ( V_61 -> V_67 < ( V_63 -> V_126
+ F_95 ( struct V_101 ,
V_127 ) ) )
goto V_46;
V_125 = V_63 -> V_124 ;
V_65 = V_63 -> V_121 ;
V_191 = V_63 -> V_127 ;
}
V_37 = F_96 ( F_23 ( & V_2 -> V_29 ) , V_125 ) ;
V_66 = - V_206 ;
if ( F_58 ( V_37 == NULL ) )
goto V_46;
V_201 = V_37 -> V_79 ;
V_66 = - V_74 ;
if ( F_58 ( ! ( V_37 -> V_75 & V_76 ) ) )
goto V_207;
V_190 = V_2 -> V_185 . V_23
- ( V_2 -> V_152 - sizeof( struct V_101 ) ) ;
if ( V_190 > V_37 -> V_78 + V_201 )
V_190 = V_37 -> V_78 + V_201 ;
do {
V_184 = F_10 ( V_2 , & V_2 -> V_185 ,
V_208 ) ;
if ( F_58 ( V_184 == NULL ) ) {
F_97 () ;
continue;
}
V_4 = V_208 ;
V_35 = F_98 ( & V_2 -> V_29 ,
F_99 ( V_37 )
+ sizeof( struct V_101 ) ,
0 , & V_66 ) ;
if ( F_58 ( V_35 == NULL ) )
goto V_209;
V_160 = F_85 ( V_2 , V_35 , V_184 , V_37 , V_190 , V_65 ,
V_191 ) ;
if ( F_58 ( V_160 < 0 ) ) {
if ( V_2 -> V_210 ) {
F_1 ( V_2 , V_184 ,
V_189 ) ;
F_12 ( & V_2 -> V_185 ) ;
F_32 ( V_35 ) ;
continue;
} else {
V_4 = V_211 ;
V_66 = V_160 ;
goto V_209;
}
}
V_35 -> V_212 = F_80 ;
F_1 ( V_2 , V_184 , V_187 ) ;
F_100 ( & V_2 -> V_185 . V_188 ) ;
V_4 = V_208 ;
V_66 = F_48 ( V_35 ) ;
if ( F_58 ( V_66 > 0 ) ) {
V_66 = F_101 ( V_66 ) ;
if ( V_66 && F_7 ( V_2 , V_184 ) ==
V_189 ) {
V_35 = NULL ;
goto V_209;
}
V_66 = 0 ;
}
F_12 ( & V_2 -> V_185 ) ;
V_202 += V_160 ;
} while ( F_82 ( ( V_184 != NULL ) ||
( ( ! ( V_61 -> V_213 & V_214 ) ) &&
( F_17 ( & V_2 -> V_185 . V_188 ) ) ) )
);
V_66 = V_202 ;
goto V_207;
V_209:
F_1 ( V_2 , V_184 , V_4 ) ;
F_32 ( V_35 ) ;
V_207:
F_102 ( V_37 ) ;
V_46:
F_103 ( & V_2 -> V_203 ) ;
return V_66 ;
}
static inline struct V_34 * F_104 ( struct V_28 * V_29 , T_1 V_215 ,
T_1 V_201 , T_1 V_62 ,
T_1 V_216 , int V_217 ,
int * V_66 )
{
struct V_34 * V_35 ;
if ( V_215 + V_62 < V_183 || ! V_216 )
V_216 = V_62 ;
V_35 = F_105 ( V_29 , V_215 + V_216 , V_62 - V_216 , V_217 ,
V_66 ) ;
if ( ! V_35 )
return NULL ;
F_39 ( V_35 , V_201 ) ;
F_42 ( V_35 , V_216 ) ;
V_35 -> V_199 = V_62 - V_216 ;
V_35 -> V_62 += V_62 - V_216 ;
return V_35 ;
}
static int F_106 ( struct V_59 * V_28 ,
struct V_60 * V_61 , T_1 V_62 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_101 * V_63 = (struct V_101 * ) V_61 -> V_64 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
T_2 V_65 ;
unsigned char * V_191 ;
int V_125 , V_66 , V_201 = 0 ;
struct V_218 V_219 = { 0 } ;
int V_193 = 0 ;
int V_220 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
unsigned short V_221 = 0 ;
if ( V_63 == NULL ) {
V_125 = V_2 -> V_125 ;
V_65 = V_2 -> V_205 ;
V_191 = NULL ;
} else {
V_66 = - V_69 ;
if ( V_61 -> V_67 < sizeof( struct V_101 ) )
goto V_46;
if ( V_61 -> V_67 < ( V_63 -> V_126 + F_95 ( struct V_101 , V_127 ) ) )
goto V_46;
V_125 = V_63 -> V_124 ;
V_65 = V_63 -> V_121 ;
V_191 = V_63 -> V_127 ;
}
V_37 = F_96 ( F_23 ( V_29 ) , V_125 ) ;
V_66 = - V_206 ;
if ( V_37 == NULL )
goto V_73;
if ( V_28 -> type == V_222 )
V_201 = V_37 -> V_79 ;
V_66 = - V_74 ;
if ( ! ( V_37 -> V_75 & V_76 ) )
goto V_73;
if ( V_2 -> V_223 ) {
V_220 = sizeof( V_219 ) ;
V_66 = - V_69 ;
if ( V_62 < V_220 )
goto V_73;
V_62 -= V_220 ;
V_66 = F_41 ( ( void * ) & V_219 , V_61 -> V_87 ,
V_220 ) ;
if ( V_66 < 0 )
goto V_73;
if ( ( V_219 . V_75 & V_224 ) &&
( V_219 . V_225 + V_219 . V_226 + 2 >
V_219 . V_227 ) )
V_219 . V_227 = V_219 . V_225 +
V_219 . V_226 + 2 ;
V_66 = - V_69 ;
if ( V_219 . V_227 > V_62 )
goto V_73;
if ( V_219 . V_221 != V_228 ) {
switch ( V_219 . V_221 & ~ V_229 ) {
case V_230 :
V_221 = V_231 ;
break;
case V_232 :
V_221 = V_233 ;
break;
case V_234 :
V_221 = V_235 ;
break;
default:
goto V_73;
}
if ( V_219 . V_221 & V_229 )
V_221 |= V_236 ;
if ( V_219 . V_237 == 0 )
goto V_73;
}
}
V_66 = - V_77 ;
if ( ! V_221 && ( V_62 > V_37 -> V_78 + V_201 + V_80 ) )
goto V_73;
V_66 = - V_85 ;
V_35 = F_104 ( V_29 , F_99 ( V_37 ) ,
F_36 ( V_37 ) , V_62 , V_219 . V_227 ,
V_61 -> V_213 & V_214 , & V_66 ) ;
if ( V_35 == NULL )
goto V_73;
F_107 ( V_35 , V_201 ) ;
V_66 = - V_69 ;
if ( V_28 -> type == V_108 &&
( V_193 = F_86 ( V_35 , V_37 , F_87 ( V_65 ) , V_191 , NULL , V_62 ) ) < 0 )
goto V_88;
V_66 = F_108 ( V_35 , V_193 , V_61 -> V_87 , 0 , V_62 ) ;
if ( V_66 )
goto V_88;
V_66 = F_46 ( V_29 , & F_47 ( V_35 ) -> V_97 ) ;
if ( V_66 < 0 )
goto V_88;
if ( ! V_221 && ( V_62 > V_37 -> V_78 + V_201 ) ) {
struct V_89 * V_90 ;
F_43 ( V_35 ) ;
V_90 = F_44 ( V_35 ) ;
if ( V_90 -> V_91 != F_45 ( V_92 ) ) {
V_66 = - V_77 ;
goto V_88;
}
}
V_35 -> V_56 = V_65 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_93 = V_29 -> V_94 ;
V_35 -> V_95 = V_29 -> V_96 ;
if ( V_2 -> V_223 ) {
if ( V_219 . V_75 & V_224 ) {
if ( ! F_109 ( V_35 , V_219 . V_225 ,
V_219 . V_226 ) ) {
V_66 = - V_69 ;
goto V_88;
}
}
F_47 ( V_35 ) -> V_237 = V_219 . V_237 ;
F_47 ( V_35 ) -> V_221 = V_221 ;
F_47 ( V_35 ) -> V_221 |= V_238 ;
F_47 ( V_35 ) -> V_239 = 0 ;
V_62 += V_220 ;
}
V_66 = F_48 ( V_35 ) ;
if ( V_66 > 0 && ( V_66 = F_101 ( V_66 ) ) != 0 )
goto V_73;
F_102 ( V_37 ) ;
return V_62 ;
V_88:
F_32 ( V_35 ) ;
V_73:
if ( V_37 )
F_102 ( V_37 ) ;
V_46:
return V_66 ;
}
static int F_110 ( struct V_57 * V_58 , struct V_59 * V_28 ,
struct V_60 * V_61 , T_1 V_62 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
if ( V_2 -> V_185 . V_21 )
return F_93 ( V_2 , V_61 ) ;
else
return F_106 ( V_28 , V_61 , V_62 ) ;
}
static int F_111 ( struct V_59 * V_28 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 ;
struct V_240 * V_240 ;
struct V_241 V_242 ;
if ( ! V_29 )
return 0 ;
V_240 = F_23 ( V_29 ) ;
V_2 = F_13 ( V_29 ) ;
F_112 ( & V_240 -> V_243 . V_244 ) ;
F_113 ( V_29 ) ;
F_114 ( V_240 , V_29 -> V_245 , - 1 ) ;
F_115 ( & V_240 -> V_243 . V_244 ) ;
F_62 ( & V_2 -> V_246 ) ;
if ( V_2 -> V_247 ) {
V_2 -> V_247 = 0 ;
V_2 -> V_205 = 0 ;
F_116 ( & V_2 -> V_248 ) ;
F_117 ( V_29 ) ;
}
F_64 ( & V_2 -> V_246 ) ;
F_118 ( V_29 ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
if ( V_2 -> V_155 . V_21 )
F_119 ( V_29 , & V_242 , 1 , 0 ) ;
if ( V_2 -> V_185 . V_21 )
F_119 ( V_29 , & V_242 , 1 , 1 ) ;
F_120 () ;
F_121 ( V_29 ) ;
V_28 -> V_29 = NULL ;
F_15 ( & V_29 -> V_129 ) ;
F_122 ( V_29 ) ;
F_123 ( V_29 ) ;
return 0 ;
}
static int F_124 ( struct V_28 * V_29 , struct V_36 * V_37 , T_2 V_56 )
{
struct V_1 * V_2 = F_13 ( V_29 ) ;
F_125 ( V_29 ) ;
F_62 ( & V_2 -> V_246 ) ;
if ( V_2 -> V_247 ) {
F_117 ( V_29 ) ;
V_2 -> V_247 = 0 ;
V_2 -> V_205 = 0 ;
F_64 ( & V_2 -> V_246 ) ;
F_126 ( & V_2 -> V_248 ) ;
F_62 ( & V_2 -> V_246 ) ;
}
V_2 -> V_205 = V_56 ;
V_2 -> V_248 . type = V_56 ;
V_2 -> V_248 . V_37 = V_37 ;
V_2 -> V_125 = V_37 ? V_37 -> V_125 : 0 ;
if ( V_56 == 0 )
goto V_73;
if ( ! V_37 || ( V_37 -> V_75 & V_76 ) ) {
F_127 ( & V_2 -> V_248 ) ;
F_128 ( V_29 ) ;
V_2 -> V_247 = 1 ;
} else {
V_29 -> V_249 = V_74 ;
if ( ! F_18 ( V_29 , V_33 ) )
V_29 -> V_250 ( V_29 ) ;
}
V_73:
F_64 ( & V_2 -> V_246 ) ;
F_129 ( V_29 ) ;
return 0 ;
}
static int F_130 ( struct V_59 * V_28 , struct V_68 * V_251 ,
int V_252 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
char V_54 [ 15 ] ;
struct V_36 * V_37 ;
int V_66 = - V_72 ;
if ( V_252 != sizeof( struct V_68 ) )
return - V_69 ;
F_30 ( V_54 , V_251 -> V_253 , sizeof( V_54 ) ) ;
V_37 = F_131 ( F_23 ( V_29 ) , V_54 ) ;
if ( V_37 ) {
V_66 = F_124 ( V_29 , V_37 , F_13 ( V_29 ) -> V_205 ) ;
F_102 ( V_37 ) ;
}
return V_66 ;
}
static int F_132 ( struct V_59 * V_28 , struct V_68 * V_251 , int V_252 )
{
struct V_101 * V_102 = (struct V_101 * ) V_251 ;
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_36 * V_37 = NULL ;
int V_66 ;
if ( V_252 < sizeof( struct V_101 ) )
return - V_69 ;
if ( V_102 -> V_118 != V_119 )
return - V_69 ;
if ( V_102 -> V_124 ) {
V_66 = - V_72 ;
V_37 = F_96 ( F_23 ( V_29 ) , V_102 -> V_124 ) ;
if ( V_37 == NULL )
goto V_46;
}
V_66 = F_124 ( V_29 , V_37 , V_102 -> V_121 ? : F_13 ( V_29 ) -> V_205 ) ;
if ( V_37 )
F_102 ( V_37 ) ;
V_46:
return V_66 ;
}
static int F_133 ( struct V_240 * V_240 , struct V_59 * V_28 , int V_56 ,
int V_254 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
T_2 V_65 = ( V_255 T_2 ) V_56 ;
int V_66 ;
if ( ! F_134 ( V_256 ) )
return - V_257 ;
if ( V_28 -> type != V_108 && V_28 -> type != V_222 &&
V_28 -> type != V_258 )
return - V_259 ;
V_28 -> V_260 = V_261 ;
V_66 = - V_85 ;
V_29 = F_135 ( V_240 , V_262 , V_84 , & V_263 ) ;
if ( V_29 == NULL )
goto V_46;
V_28 -> V_264 = & V_265 ;
if ( V_28 -> type == V_258 )
V_28 -> V_264 = & V_266 ;
F_136 ( V_28 , V_29 ) ;
V_2 = F_13 ( V_29 ) ;
V_29 -> V_267 = V_262 ;
V_2 -> V_205 = V_65 ;
V_29 -> V_268 = F_14 ;
F_137 ( V_29 ) ;
F_138 ( & V_2 -> V_246 ) ;
F_139 ( & V_2 -> V_203 ) ;
V_2 -> V_248 . V_269 = F_52 ;
if ( V_28 -> type == V_258 )
V_2 -> V_248 . V_269 = F_20 ;
V_2 -> V_248 . V_43 = V_29 ;
if ( V_65 ) {
V_2 -> V_248 . type = V_65 ;
F_127 ( & V_2 -> V_248 ) ;
F_128 ( V_29 ) ;
V_2 -> V_247 = 1 ;
}
F_112 ( & V_240 -> V_243 . V_244 ) ;
F_140 ( V_29 , & V_240 -> V_243 . V_270 ) ;
F_114 ( V_240 , & V_263 , 1 ) ;
F_115 ( & V_240 -> V_243 . V_244 ) ;
return 0 ;
V_46:
return V_66 ;
}
static int F_141 ( struct V_28 * V_29 , struct V_60 * V_61 , int V_62 )
{
struct V_271 * V_272 ;
struct V_34 * V_35 , * V_273 ;
int V_274 , V_66 ;
V_66 = - V_275 ;
V_35 = F_142 ( & V_29 -> V_30 ) ;
if ( V_35 == NULL )
goto V_46;
V_274 = V_35 -> V_62 ;
if ( V_274 > V_62 ) {
V_61 -> V_213 |= V_276 ;
V_274 = V_62 ;
}
V_66 = F_143 ( V_35 , 0 , V_61 -> V_87 , V_274 ) ;
if ( V_66 )
goto V_277;
F_144 ( V_61 , V_29 , V_35 ) ;
V_272 = F_145 ( V_35 ) ;
F_146 ( V_61 , V_278 , V_279 ,
sizeof( V_272 -> V_280 ) , & V_272 -> V_280 ) ;
V_61 -> V_213 |= V_281 ;
V_66 = V_274 ;
F_112 ( & V_29 -> V_30 . V_130 ) ;
V_29 -> V_249 = 0 ;
if ( ( V_273 = F_147 ( & V_29 -> V_30 ) ) != NULL ) {
V_29 -> V_249 = F_145 ( V_273 ) -> V_280 . V_282 ;
F_115 ( & V_29 -> V_30 . V_130 ) ;
V_29 -> V_250 ( V_29 ) ;
} else
F_115 ( & V_29 -> V_30 . V_130 ) ;
V_277:
F_32 ( V_35 ) ;
V_46:
return V_66 ;
}
static int F_148 ( struct V_57 * V_58 , struct V_59 * V_28 ,
struct V_60 * V_61 , T_1 V_62 , int V_75 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_34 * V_35 ;
int V_274 , V_66 ;
struct V_101 * V_102 ;
int V_220 = 0 ;
V_66 = - V_69 ;
if ( V_75 & ~ ( V_283 | V_214 | V_276 | V_284 | V_281 ) )
goto V_46;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_75 & V_281 ) {
V_66 = F_141 ( V_29 , V_61 , V_62 ) ;
goto V_46;
}
V_35 = F_149 ( V_29 , V_75 , V_75 & V_214 , & V_66 ) ;
if ( V_35 == NULL )
goto V_46;
if ( F_13 ( V_29 ) -> V_223 ) {
struct V_218 V_219 = { 0 } ;
V_66 = - V_69 ;
V_220 = sizeof( V_219 ) ;
if ( V_62 < V_220 )
goto V_88;
V_62 -= V_220 ;
if ( F_150 ( V_35 ) ) {
struct V_285 * V_286 = F_47 ( V_35 ) ;
V_219 . V_227 = F_151 ( V_35 ) ;
V_219 . V_237 = V_286 -> V_237 ;
if ( V_286 -> V_221 & V_231 )
V_219 . V_221 = V_230 ;
else if ( V_286 -> V_221 & V_233 )
V_219 . V_221 = V_232 ;
else if ( V_286 -> V_221 & V_235 )
V_219 . V_221 = V_234 ;
else if ( V_286 -> V_221 & V_287 )
goto V_88;
else
F_5 () ;
if ( V_286 -> V_221 & V_236 )
V_219 . V_221 |= V_229 ;
} else
V_219 . V_221 = V_228 ;
if ( V_35 -> V_149 == V_150 ) {
V_219 . V_75 = V_224 ;
V_219 . V_225 = F_152 ( V_35 ) ;
V_219 . V_226 = V_35 -> V_226 ;
}
V_66 = F_153 ( V_61 -> V_87 , ( void * ) & V_219 ,
V_220 ) ;
if ( V_66 < 0 )
goto V_88;
}
V_102 = & F_27 ( V_35 ) -> V_49 . V_117 ;
if ( V_28 -> type == V_258 )
V_61 -> V_67 = sizeof( struct V_41 ) ;
else
V_61 -> V_67 = V_102 -> V_126 + F_95 ( struct V_101 , V_127 ) ;
V_274 = V_35 -> V_62 ;
if ( V_274 > V_62 ) {
V_274 = V_62 ;
V_61 -> V_213 |= V_276 ;
}
V_66 = F_143 ( V_35 , 0 , V_61 -> V_87 , V_274 ) ;
if ( V_66 )
goto V_88;
F_154 ( V_61 , V_29 , V_35 ) ;
if ( V_61 -> V_64 )
memcpy ( V_61 -> V_64 , & F_27 ( V_35 ) -> V_49 ,
V_61 -> V_67 ) ;
if ( F_13 ( V_29 ) -> V_288 ) {
struct V_289 V_290 ;
V_290 . V_13 = V_138 ;
if ( V_35 -> V_149 == V_150 )
V_290 . V_13 |= V_151 ;
V_290 . V_160 = F_27 ( V_35 ) -> V_128 ;
V_290 . V_161 = V_35 -> V_62 ;
V_290 . V_162 = 0 ;
V_290 . V_163 = F_54 ( V_35 ) ;
if ( F_76 ( V_35 ) ) {
V_290 . V_177 = F_77 ( V_35 ) ;
V_290 . V_13 |= V_178 ;
} else {
V_290 . V_177 = 0 ;
}
V_290 . V_179 = 0 ;
F_146 ( V_61 , V_278 , V_291 , sizeof( V_290 ) , & V_290 ) ;
}
V_66 = V_220 + ( ( V_75 & V_276 ) ? V_35 -> V_62 : V_274 ) ;
V_88:
F_155 ( V_29 , V_35 ) ;
V_46:
return V_66 ;
}
static int F_156 ( struct V_59 * V_28 , struct V_68 * V_251 ,
int * V_292 , int V_293 )
{
struct V_36 * V_37 ;
struct V_28 * V_29 = V_28 -> V_29 ;
if ( V_293 )
return - V_294 ;
V_251 -> V_295 = V_119 ;
F_34 () ;
V_37 = F_157 ( F_23 ( V_29 ) , F_13 ( V_29 ) -> V_125 ) ;
if ( V_37 )
strncpy ( V_251 -> V_253 , V_37 -> V_54 , 14 ) ;
else
memset ( V_251 -> V_253 , 0 , 14 ) ;
F_37 () ;
* V_292 = sizeof( * V_251 ) ;
return 0 ;
}
static int F_158 ( struct V_59 * V_28 , struct V_68 * V_251 ,
int * V_292 , int V_293 )
{
struct V_36 * V_37 ;
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
F_159 ( struct V_101 * , V_102 , V_251 ) ;
if ( V_293 )
return - V_294 ;
V_102 -> V_118 = V_119 ;
V_102 -> V_124 = V_2 -> V_125 ;
V_102 -> V_121 = V_2 -> V_205 ;
V_102 -> V_122 = 0 ;
F_34 () ;
V_37 = F_157 ( F_23 ( V_29 ) , V_2 -> V_125 ) ;
if ( V_37 ) {
V_102 -> V_120 = V_37 -> type ;
V_102 -> V_126 = V_37 -> V_252 ;
memcpy ( V_102 -> V_127 , V_37 -> V_296 , V_37 -> V_252 ) ;
} else {
V_102 -> V_120 = 0 ;
V_102 -> V_126 = 0 ;
}
F_37 () ;
* V_292 = F_95 ( struct V_101 , V_127 ) + V_102 -> V_126 ;
return 0 ;
}
static int F_160 ( struct V_36 * V_37 , struct V_297 * V_298 ,
int V_299 )
{
switch ( V_298 -> type ) {
case V_300 :
if ( V_298 -> V_301 != V_37 -> V_252 )
return - V_69 ;
if ( V_299 > 0 )
return F_161 ( V_37 , V_298 -> V_191 ) ;
else
return F_162 ( V_37 , V_298 -> V_191 ) ;
break;
case V_302 :
return F_163 ( V_37 , V_299 ) ;
break;
case V_303 :
return F_164 ( V_37 , V_299 ) ;
break;
case V_304 :
if ( V_298 -> V_301 != V_37 -> V_252 )
return - V_69 ;
if ( V_299 > 0 )
return F_165 ( V_37 , V_298 -> V_191 ) ;
else
return F_166 ( V_37 , V_298 -> V_191 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_167 ( struct V_36 * V_37 , struct V_297 * V_298 , int V_299 )
{
for ( ; V_298 ; V_298 = V_298 -> V_305 ) {
if ( V_298 -> V_125 == V_37 -> V_125 )
F_160 ( V_37 , V_298 , V_299 ) ;
}
}
static int F_168 ( struct V_28 * V_29 , struct V_306 * V_307 )
{
struct V_1 * V_2 = F_13 ( V_29 ) ;
struct V_297 * V_308 , * V_298 ;
struct V_36 * V_37 ;
int V_66 ;
F_169 () ;
V_66 = - V_72 ;
V_37 = F_170 ( F_23 ( V_29 ) , V_307 -> V_309 ) ;
if ( ! V_37 )
goto V_310;
V_66 = - V_69 ;
if ( V_307 -> V_311 > V_37 -> V_252 )
goto V_310;
V_66 = - V_85 ;
V_298 = F_171 ( sizeof( * V_298 ) , V_84 ) ;
if ( V_298 == NULL )
goto V_310;
V_66 = 0 ;
for ( V_308 = V_2 -> V_312 ; V_308 ; V_308 = V_308 -> V_305 ) {
if ( V_308 -> V_125 == V_307 -> V_309 &&
V_308 -> type == V_307 -> V_313 &&
V_308 -> V_301 == V_307 -> V_311 &&
memcmp ( V_308 -> V_191 , V_307 -> V_314 , V_308 -> V_301 ) == 0 ) {
V_308 -> V_315 ++ ;
F_172 ( V_298 ) ;
goto V_310;
}
}
V_298 -> type = V_307 -> V_313 ;
V_298 -> V_125 = V_307 -> V_309 ;
V_298 -> V_301 = V_307 -> V_311 ;
memcpy ( V_298 -> V_191 , V_307 -> V_314 , V_298 -> V_301 ) ;
V_298 -> V_315 = 1 ;
V_298 -> V_305 = V_2 -> V_312 ;
V_2 -> V_312 = V_298 ;
V_66 = F_160 ( V_37 , V_298 , 1 ) ;
if ( V_66 ) {
V_2 -> V_312 = V_298 -> V_305 ;
F_172 ( V_298 ) ;
}
V_310:
F_173 () ;
return V_66 ;
}
static int F_174 ( struct V_28 * V_29 , struct V_306 * V_307 )
{
struct V_297 * V_308 , * * V_316 ;
F_169 () ;
for ( V_316 = & F_13 ( V_29 ) -> V_312 ; ( V_308 = * V_316 ) != NULL ; V_316 = & V_308 -> V_305 ) {
if ( V_308 -> V_125 == V_307 -> V_309 &&
V_308 -> type == V_307 -> V_313 &&
V_308 -> V_301 == V_307 -> V_311 &&
memcmp ( V_308 -> V_191 , V_307 -> V_314 , V_308 -> V_301 ) == 0 ) {
if ( -- V_308 -> V_315 == 0 ) {
struct V_36 * V_37 ;
* V_316 = V_308 -> V_305 ;
V_37 = F_170 ( F_23 ( V_29 ) , V_308 -> V_125 ) ;
if ( V_37 )
F_160 ( V_37 , V_308 , - 1 ) ;
F_172 ( V_308 ) ;
}
F_173 () ;
return 0 ;
}
}
F_173 () ;
return - V_317 ;
}
static void F_118 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_13 ( V_29 ) ;
struct V_297 * V_308 ;
if ( ! V_2 -> V_312 )
return;
F_169 () ;
while ( ( V_308 = V_2 -> V_312 ) != NULL ) {
struct V_36 * V_37 ;
V_2 -> V_312 = V_308 -> V_305 ;
V_37 = F_170 ( F_23 ( V_29 ) , V_308 -> V_125 ) ;
if ( V_37 != NULL )
F_160 ( V_37 , V_308 , - 1 ) ;
F_172 ( V_308 ) ;
}
F_173 () ;
}
static int
F_175 ( struct V_59 * V_28 , int V_318 , int V_319 , char T_4 * V_320 , unsigned int V_321 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
int V_322 ;
if ( V_318 != V_278 )
return - V_323 ;
switch ( V_319 ) {
case V_324 :
case V_325 :
{
struct V_306 V_307 ;
int V_62 = V_321 ;
memset ( & V_307 , 0 , sizeof( V_307 ) ) ;
if ( V_62 < sizeof( struct V_326 ) )
return - V_69 ;
if ( V_62 > sizeof( V_307 ) )
V_62 = sizeof( V_307 ) ;
if ( F_176 ( & V_307 , V_320 , V_62 ) )
return - V_198 ;
if ( V_62 < ( V_307 . V_311 + F_95 ( struct V_326 , V_314 ) ) )
return - V_69 ;
if ( V_319 == V_324 )
V_322 = F_168 ( V_29 , & V_307 ) ;
else
V_322 = F_174 ( V_29 , & V_307 ) ;
return V_322 ;
}
case V_327 :
case V_328 :
{
struct V_241 V_242 ;
if ( V_321 < sizeof( V_242 ) )
return - V_69 ;
if ( F_13 ( V_29 ) -> V_223 )
return - V_69 ;
if ( F_176 ( & V_242 , V_320 , sizeof( V_242 ) ) )
return - V_198 ;
return F_119 ( V_29 , & V_242 , 0 , V_319 == V_328 ) ;
}
case V_329 :
{
int V_330 ;
if ( V_321 != sizeof( V_330 ) )
return - V_69 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
F_13 ( V_29 ) -> V_156 = V_330 ;
return 0 ;
}
case V_331 :
{
int V_330 ;
if ( V_321 != sizeof( V_330 ) )
return - V_69 ;
if ( V_2 -> V_155 . V_21 || V_2 -> V_185 . V_21 )
return - V_204 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
switch ( V_330 ) {
case V_12 :
case V_14 :
V_2 -> V_11 = V_330 ;
return 0 ;
default:
return - V_69 ;
}
}
case V_332 :
{
unsigned int V_330 ;
if ( V_321 != sizeof( V_330 ) )
return - V_69 ;
if ( V_2 -> V_155 . V_21 || V_2 -> V_185 . V_21 )
return - V_204 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_153 = V_330 ;
return 0 ;
}
case V_333 :
{
unsigned int V_330 ;
if ( V_321 != sizeof( V_330 ) )
return - V_69 ;
if ( V_2 -> V_155 . V_21 || V_2 -> V_185 . V_21 )
return - V_204 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_210 = ! ! V_330 ;
return 0 ;
}
case V_291 :
{
int V_330 ;
if ( V_321 < sizeof( V_330 ) )
return - V_69 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_288 = ! ! V_330 ;
return 0 ;
}
case V_334 :
{
int V_330 ;
if ( V_321 < sizeof( V_330 ) )
return - V_69 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_123 = ! ! V_330 ;
return 0 ;
}
case V_335 :
{
int V_330 ;
if ( V_28 -> type != V_222 )
return - V_69 ;
if ( V_2 -> V_155 . V_21 || V_2 -> V_185 . V_21 )
return - V_204 ;
if ( V_321 < sizeof( V_330 ) )
return - V_69 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_223 = ! ! V_330 ;
return 0 ;
}
case V_336 :
{
int V_330 ;
if ( V_321 != sizeof( V_330 ) )
return - V_69 ;
if ( F_176 ( & V_330 , V_320 , sizeof( V_330 ) ) )
return - V_198 ;
V_2 -> V_164 = V_330 ;
return 0 ;
}
default:
return - V_323 ;
}
}
static int F_177 ( struct V_59 * V_28 , int V_318 , int V_319 ,
char T_4 * V_320 , int T_4 * V_321 )
{
int V_62 ;
int V_330 ;
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
void * V_51 ;
struct V_337 V_338 ;
if ( V_318 != V_278 )
return - V_323 ;
if ( F_178 ( V_62 , V_321 ) )
return - V_198 ;
if ( V_62 < 0 )
return - V_69 ;
switch ( V_319 ) {
case V_339 :
if ( V_62 > sizeof( struct V_337 ) )
V_62 = sizeof( struct V_337 ) ;
F_112 ( & V_29 -> V_129 . V_130 ) ;
V_338 = V_2 -> V_131 ;
memset ( & V_2 -> V_131 , 0 , sizeof( V_338 ) ) ;
F_115 ( & V_29 -> V_129 . V_130 ) ;
V_338 . V_132 += V_338 . V_136 ;
V_51 = & V_338 ;
break;
case V_291 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
V_330 = V_2 -> V_288 ;
V_51 = & V_330 ;
break;
case V_334 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
V_330 = V_2 -> V_123 ;
V_51 = & V_330 ;
break;
case V_335 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
V_330 = V_2 -> V_223 ;
V_51 = & V_330 ;
break;
case V_331 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
V_330 = V_2 -> V_11 ;
V_51 = & V_330 ;
break;
case V_340 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
if ( F_176 ( & V_330 , V_320 , V_62 ) )
return - V_198 ;
switch ( V_330 ) {
case V_12 :
V_330 = sizeof( struct V_5 ) ;
break;
case V_14 :
V_330 = sizeof( struct V_7 ) ;
break;
default:
return - V_69 ;
}
V_51 = & V_330 ;
break;
case V_332 :
if ( V_62 > sizeof( unsigned int ) )
V_62 = sizeof( unsigned int ) ;
V_330 = V_2 -> V_153 ;
V_51 = & V_330 ;
break;
case V_333 :
if ( V_62 > sizeof( unsigned int ) )
V_62 = sizeof( unsigned int ) ;
V_330 = V_2 -> V_210 ;
V_51 = & V_330 ;
break;
case V_336 :
if ( V_62 > sizeof( int ) )
V_62 = sizeof( int ) ;
V_330 = V_2 -> V_164 ;
V_51 = & V_330 ;
break;
default:
return - V_323 ;
}
if ( F_179 ( V_62 , V_321 ) )
return - V_198 ;
if ( F_180 ( V_320 , V_51 , V_62 ) )
return - V_198 ;
return 0 ;
}
static int F_181 ( struct V_341 * V_342 , unsigned long V_61 , void * V_51 )
{
struct V_28 * V_29 ;
struct V_343 * V_344 ;
struct V_36 * V_37 = V_51 ;
struct V_240 * V_240 = F_22 ( V_37 ) ;
F_34 () ;
F_182 (sk, node, &net->packet.sklist) {
struct V_1 * V_2 = F_13 ( V_29 ) ;
switch ( V_61 ) {
case V_345 :
if ( V_2 -> V_312 )
F_167 ( V_37 , V_2 -> V_312 , - 1 ) ;
case V_346 :
if ( V_37 -> V_125 == V_2 -> V_125 ) {
F_62 ( & V_2 -> V_246 ) ;
if ( V_2 -> V_247 ) {
F_116 ( & V_2 -> V_248 ) ;
F_117 ( V_29 ) ;
V_2 -> V_247 = 0 ;
V_29 -> V_249 = V_74 ;
if ( ! F_18 ( V_29 , V_33 ) )
V_29 -> V_250 ( V_29 ) ;
}
if ( V_61 == V_345 ) {
V_2 -> V_125 = - 1 ;
V_2 -> V_248 . V_37 = NULL ;
}
F_64 ( & V_2 -> V_246 ) ;
}
break;
case V_347 :
if ( V_37 -> V_125 == V_2 -> V_125 ) {
F_62 ( & V_2 -> V_246 ) ;
if ( V_2 -> V_205 && ! V_2 -> V_247 ) {
F_127 ( & V_2 -> V_248 ) ;
F_128 ( V_29 ) ;
V_2 -> V_247 = 1 ;
}
F_64 ( & V_2 -> V_246 ) ;
}
break;
}
}
F_37 () ;
return V_348 ;
}
static int F_183 ( struct V_59 * V_28 , unsigned int V_349 ,
unsigned long V_350 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
switch ( V_349 ) {
case V_351 :
{
int V_352 = F_184 ( V_29 ) ;
return F_179 ( V_352 , ( int T_4 * ) V_350 ) ;
}
case V_353 :
{
struct V_34 * V_35 ;
int V_352 = 0 ;
F_112 ( & V_29 -> V_129 . V_130 ) ;
V_35 = F_147 ( & V_29 -> V_129 ) ;
if ( V_35 )
V_352 = V_35 -> V_62 ;
F_115 ( & V_29 -> V_129 . V_130 ) ;
return F_179 ( V_352 , ( int T_4 * ) V_350 ) ;
}
case V_354 :
return F_185 ( V_29 , (struct V_143 T_4 * ) V_350 ) ;
case V_355 :
return F_186 ( V_29 , (struct V_145 T_4 * ) V_350 ) ;
#ifdef F_187
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
return V_370 . V_371 ( V_28 , V_349 , V_350 ) ;
#endif
default:
return - V_372 ;
}
return 0 ;
}
static unsigned int F_188 ( struct V_373 * V_373 , struct V_59 * V_28 ,
T_5 * V_374 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
unsigned int V_375 = F_189 ( V_373 , V_28 , V_374 ) ;
F_112 ( & V_29 -> V_129 . V_130 ) ;
if ( V_2 -> V_155 . V_21 ) {
if ( ! F_11 ( V_2 , & V_2 -> V_155 , V_157 ) )
V_375 |= V_376 | V_377 ;
}
F_115 ( & V_29 -> V_129 . V_130 ) ;
F_112 ( & V_29 -> V_378 . V_130 ) ;
if ( V_2 -> V_185 . V_21 ) {
if ( F_10 ( V_2 , & V_2 -> V_185 , V_189 ) )
V_375 |= V_379 | V_380 ;
}
F_115 ( & V_29 -> V_378 . V_130 ) ;
return V_375 ;
}
static void F_190 ( struct V_381 * V_382 )
{
struct V_373 * V_373 = V_382 -> V_383 ;
struct V_59 * V_28 = V_373 -> V_384 ;
struct V_28 * V_29 = V_28 -> V_29 ;
if ( V_29 )
F_100 ( & F_13 ( V_29 ) -> V_385 ) ;
}
static void F_191 ( struct V_381 * V_382 )
{
struct V_373 * V_373 = V_382 -> V_383 ;
struct V_59 * V_28 = V_373 -> V_384 ;
struct V_28 * V_29 = V_28 -> V_29 ;
if ( V_29 )
F_83 ( & F_13 ( V_29 ) -> V_385 ) ;
}
static void F_192 ( struct V_386 * V_21 , unsigned int V_387 ,
unsigned int V_62 )
{
int V_298 ;
for ( V_298 = 0 ; V_298 < V_62 ; V_298 ++ ) {
if ( F_82 ( V_21 [ V_298 ] . V_22 ) ) {
if ( F_193 ( V_21 [ V_298 ] . V_22 ) )
F_194 ( V_21 [ V_298 ] . V_22 ) ;
else
F_195 ( ( unsigned long ) V_21 [ V_298 ] . V_22 ,
V_387 ) ;
V_21 [ V_298 ] . V_22 = NULL ;
}
}
F_172 ( V_21 ) ;
}
static inline char * F_196 ( unsigned long V_387 )
{
char * V_22 = NULL ;
T_6 V_388 = V_84 | V_389 |
V_390 | V_391 | V_392 ;
V_22 = ( char * ) F_197 ( V_388 , V_387 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_198 ( ( 1 << V_387 ) * V_183 ) ;
if ( V_22 )
return V_22 ;
V_388 &= ~ V_392 ;
V_22 = ( char * ) F_197 ( V_388 , V_387 ) ;
if ( V_22 )
return V_22 ;
return NULL ;
}
static struct V_386 * F_199 ( struct V_241 * V_242 , int V_387 )
{
unsigned int V_393 = V_242 -> V_394 ;
struct V_386 * V_21 ;
int V_298 ;
V_21 = F_200 ( V_393 , sizeof( struct V_386 ) , V_84 ) ;
if ( F_58 ( ! V_21 ) )
goto V_46;
for ( V_298 = 0 ; V_298 < V_393 ; V_298 ++ ) {
V_21 [ V_298 ] . V_22 = F_196 ( V_387 ) ;
if ( F_58 ( ! V_21 [ V_298 ] . V_22 ) )
goto V_395;
}
V_46:
return V_21 ;
V_395:
F_192 ( V_21 , V_387 , V_393 ) ;
V_21 = NULL ;
goto V_46;
}
static int F_119 ( struct V_28 * V_29 , struct V_241 * V_242 ,
int V_396 , int V_185 )
{
struct V_386 * V_21 = NULL ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
int V_397 , V_387 = 0 ;
struct V_15 * V_16 ;
struct V_398 * V_399 ;
T_2 V_205 ;
int V_66 ;
V_16 = V_185 ? & V_2 -> V_185 : & V_2 -> V_155 ;
V_399 = V_185 ? & V_29 -> V_378 : & V_29 -> V_129 ;
V_66 = - V_204 ;
if ( ! V_396 ) {
if ( F_17 ( & V_2 -> V_385 ) )
goto V_46;
if ( F_17 ( & V_16 -> V_188 ) )
goto V_46;
}
if ( V_242 -> V_394 ) {
V_66 = - V_204 ;
if ( F_58 ( V_16 -> V_21 ) )
goto V_46;
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_152 = V_400 ;
break;
case V_14 :
V_2 -> V_152 = V_401 ;
break;
}
V_66 = - V_69 ;
if ( F_58 ( ( int ) V_242 -> V_402 <= 0 ) )
goto V_46;
if ( F_58 ( V_242 -> V_402 & ( V_183 - 1 ) ) )
goto V_46;
if ( F_58 ( V_242 -> V_403 < V_2 -> V_152 +
V_2 -> V_153 ) )
goto V_46;
if ( F_58 ( V_242 -> V_403 & ( V_404 - 1 ) ) )
goto V_46;
V_16 -> V_20 = V_242 -> V_402 / V_242 -> V_403 ;
if ( F_58 ( V_16 -> V_20 <= 0 ) )
goto V_46;
if ( F_58 ( ( V_16 -> V_20 * V_242 -> V_394 ) !=
V_242 -> V_405 ) )
goto V_46;
V_66 = - V_406 ;
V_387 = F_201 ( V_242 -> V_402 ) ;
V_21 = F_199 ( V_242 , V_387 ) ;
if ( F_58 ( ! V_21 ) )
goto V_46;
}
else {
V_66 = - V_69 ;
if ( F_58 ( V_242 -> V_405 ) )
goto V_46;
}
F_125 ( V_29 ) ;
F_62 ( & V_2 -> V_246 ) ;
V_397 = V_2 -> V_247 ;
V_205 = V_2 -> V_205 ;
if ( V_397 ) {
F_116 ( & V_2 -> V_248 ) ;
V_2 -> V_205 = 0 ;
V_2 -> V_247 = 0 ;
F_117 ( V_29 ) ;
}
F_64 ( & V_2 -> V_246 ) ;
F_120 () ;
V_66 = - V_204 ;
F_94 ( & V_2 -> V_203 ) ;
if ( V_396 || F_17 ( & V_2 -> V_385 ) == 0 ) {
V_66 = 0 ;
F_112 ( & V_399 -> V_130 ) ;
F_202 ( V_16 -> V_21 , V_21 ) ;
V_16 -> V_26 = ( V_242 -> V_405 - 1 ) ;
V_16 -> V_24 = 0 ;
V_16 -> V_23 = V_242 -> V_403 ;
F_115 ( & V_399 -> V_130 ) ;
F_202 ( V_16 -> V_407 , V_387 ) ;
F_202 ( V_16 -> V_408 , V_242 -> V_394 ) ;
V_16 -> V_409 = V_242 -> V_402 / V_183 ;
V_2 -> V_248 . V_269 = ( V_2 -> V_155 . V_21 ) ?
F_67 : F_52 ;
F_15 ( V_399 ) ;
if ( F_17 ( & V_2 -> V_385 ) )
F_4 ( L_6 ,
F_17 ( & V_2 -> V_385 ) ) ;
}
F_103 ( & V_2 -> V_203 ) ;
F_62 ( & V_2 -> V_246 ) ;
if ( V_397 && ! V_2 -> V_247 ) {
F_128 ( V_29 ) ;
V_2 -> V_247 = 1 ;
V_2 -> V_205 = V_205 ;
F_127 ( & V_2 -> V_248 ) ;
}
F_64 ( & V_2 -> V_246 ) ;
F_129 ( V_29 ) ;
if ( V_21 )
F_192 ( V_21 , V_387 , V_242 -> V_394 ) ;
V_46:
return V_66 ;
}
static int F_203 ( struct V_373 * V_373 , struct V_59 * V_28 ,
struct V_381 * V_382 )
{
struct V_28 * V_29 = V_28 -> V_29 ;
struct V_1 * V_2 = F_13 ( V_29 ) ;
unsigned long V_410 , V_411 ;
struct V_15 * V_16 ;
unsigned long V_181 ;
int V_66 = - V_69 ;
int V_298 ;
if ( V_382 -> V_412 )
return - V_69 ;
F_94 ( & V_2 -> V_203 ) ;
V_411 = 0 ;
for ( V_16 = & V_2 -> V_155 ; V_16 <= & V_2 -> V_185 ; V_16 ++ ) {
if ( V_16 -> V_21 ) {
V_411 += V_16 -> V_408
* V_16 -> V_409
* V_183 ;
}
}
if ( V_411 == 0 )
goto V_46;
V_410 = V_382 -> V_413 - V_382 -> V_414 ;
if ( V_410 != V_411 )
goto V_46;
V_181 = V_382 -> V_414 ;
for ( V_16 = & V_2 -> V_155 ; V_16 <= & V_2 -> V_185 ; V_16 ++ ) {
if ( V_16 -> V_21 == NULL )
continue;
for ( V_298 = 0 ; V_298 < V_16 -> V_408 ; V_298 ++ ) {
struct V_197 * V_197 ;
void * V_415 = V_16 -> V_21 [ V_298 ] . V_22 ;
int V_416 ;
for ( V_416 = 0 ; V_416 < V_16 -> V_409 ; V_416 ++ ) {
V_197 = F_3 ( V_415 ) ;
V_66 = F_204 ( V_382 , V_181 , V_197 ) ;
if ( F_58 ( V_66 ) )
goto V_46;
V_181 += V_183 ;
V_415 += V_183 ;
}
}
}
F_100 ( & V_2 -> V_385 ) ;
V_382 -> V_417 = & V_418 ;
V_66 = 0 ;
V_46:
F_103 ( & V_2 -> V_203 ) ;
return V_66 ;
}
static void * F_205 ( struct V_419 * V_420 , T_7 * V_421 )
__acquires( T_8 )
{
struct V_240 * V_240 = F_206 ( V_420 ) ;
F_34 () ;
return F_207 ( & V_240 -> V_243 . V_270 , * V_421 ) ;
}
static void * F_208 ( struct V_419 * V_420 , void * V_422 , T_7 * V_421 )
{
struct V_240 * V_240 = F_206 ( V_420 ) ;
return F_209 ( V_422 , & V_240 -> V_243 . V_270 , V_421 ) ;
}
static void F_210 ( struct V_419 * V_420 , void * V_422 )
__releases( T_8 )
{
F_37 () ;
}
static int F_211 ( struct V_419 * V_420 , void * V_422 )
{
if ( V_422 == V_423 )
F_212 ( V_420 , L_7 ) ;
else {
struct V_28 * V_424 = F_213 ( V_422 ) ;
const struct V_1 * V_2 = F_13 ( V_424 ) ;
F_214 ( V_420 ,
L_8 ,
V_424 ,
F_17 ( & V_424 -> V_425 ) ,
V_424 -> V_107 ,
F_87 ( V_2 -> V_205 ) ,
V_2 -> V_125 ,
V_2 -> V_247 ,
F_17 ( & V_424 -> V_31 ) ,
F_215 ( V_424 ) ,
F_216 ( V_424 ) ) ;
}
return 0 ;
}
static int F_217 ( struct V_426 * V_426 , struct V_373 * V_373 )
{
return F_218 ( V_426 , V_373 , & V_427 ,
sizeof( struct V_428 ) ) ;
}
static int T_9 F_219 ( struct V_240 * V_240 )
{
F_138 ( & V_240 -> V_243 . V_244 ) ;
F_220 ( & V_240 -> V_243 . V_270 ) ;
if ( ! F_221 ( V_240 , L_9 , 0 , & V_429 ) )
return - V_406 ;
return 0 ;
}
static void T_10 F_222 ( struct V_240 * V_240 )
{
F_223 ( V_240 , L_9 ) ;
}
static void T_11 F_224 ( void )
{
F_225 ( & V_430 ) ;
F_226 ( & V_431 ) ;
F_227 ( V_262 ) ;
F_228 ( & V_263 ) ;
}
static int T_12 F_229 ( void )
{
int V_432 = F_230 ( & V_263 , 0 ) ;
if ( V_432 != 0 )
goto V_46;
F_231 ( & V_433 ) ;
F_232 ( & V_431 ) ;
F_233 ( & V_430 ) ;
V_46:
return V_432 ;
}
