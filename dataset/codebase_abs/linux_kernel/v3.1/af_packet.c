static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static void F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_4 -> V_6 )
F_3 ( V_3 , V_4 ) ;
else
F_4 ( & V_4 -> V_7 ) ;
F_5 ( V_3 ) ;
V_4 -> V_5 = 1 ;
}
}
static void F_6 ( struct V_2 * V_3 , bool V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_5 = 0 ;
if ( V_4 -> V_6 )
F_7 ( V_3 , V_4 ) ;
else
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_3 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
F_12 ( & V_4 -> V_9 ) ;
}
}
static void F_13 ( struct V_2 * V_3 , bool V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
F_6 ( V_3 , V_8 ) ;
}
void F_14 ( struct V_1 * V_4 , void * V_10 , int V_11 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
V_17 . V_16 = V_10 ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_20 = V_11 ;
F_15 ( F_16 ( & V_17 . V_13 -> V_20 ) ) ;
break;
case V_21 :
V_17 . V_15 -> V_20 = V_11 ;
F_15 ( F_16 ( & V_17 . V_15 -> V_20 ) ) ;
break;
default:
F_17 ( L_1 ) ;
F_18 () ;
}
F_19 () ;
}
static int F_20 ( struct V_1 * V_4 , void * V_10 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
F_21 () ;
V_17 . V_16 = V_10 ;
switch ( V_4 -> V_18 ) {
case V_19 :
F_15 ( F_16 ( & V_17 . V_13 -> V_20 ) ) ;
return V_17 . V_13 -> V_20 ;
case V_21 :
F_15 ( F_16 ( & V_17 . V_15 -> V_20 ) ) ;
return V_17 . V_15 -> V_20 ;
default:
F_17 ( L_1 ) ;
F_18 () ;
return 0 ;
}
}
static void * F_22 ( struct V_1 * V_4 ,
struct V_22 * V_23 ,
unsigned int V_24 ,
int V_11 )
{
unsigned int V_25 , V_26 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
V_25 = V_24 / V_23 -> V_27 ;
V_26 = V_24 % V_23 -> V_27 ;
V_17 . V_16 = V_23 -> V_28 [ V_25 ] . V_29 +
( V_26 * V_23 -> V_30 ) ;
if ( V_11 != F_20 ( V_4 , V_17 . V_16 ) )
return NULL ;
return V_17 . V_16 ;
}
static inline void * F_23 ( struct V_1 * V_4 ,
struct V_22 * V_23 ,
int V_11 )
{
return F_22 ( V_4 , V_23 , V_23 -> V_31 , V_11 ) ;
}
static inline void * F_24 ( struct V_1 * V_4 ,
struct V_22 * V_23 ,
int V_11 )
{
unsigned int V_32 = V_23 -> V_31 ? V_23 -> V_31 - 1 : V_23 -> V_33 ;
return F_22 ( V_4 , V_23 , V_32 , V_11 ) ;
}
static inline void F_25 ( struct V_22 * V_34 )
{
V_34 -> V_31 = V_34 -> V_31 != V_34 -> V_33 ? V_34 -> V_31 + 1 : 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
F_27 ( & V_3 -> V_35 ) ;
F_28 ( F_29 ( & V_3 -> V_36 ) ) ;
F_28 ( F_29 ( & V_3 -> V_37 ) ) ;
if ( ! F_30 ( V_3 , V_38 ) ) {
F_17 ( L_2 , V_3 ) ;
return;
}
F_31 ( V_3 ) ;
}
static int F_32 ( struct V_39 * V_40 , unsigned int V_41 )
{
int V_42 = F_29 ( & V_40 -> V_43 ) + 1 ;
if ( V_42 >= V_41 )
V_42 = 0 ;
return V_42 ;
}
static struct V_2 * F_33 ( struct V_39 * V_40 , struct V_44 * V_45 , unsigned int V_41 )
{
T_1 V_46 , V_47 = V_45 -> V_48 ;
V_46 = ( ( V_49 ) V_47 * V_41 ) >> 32 ;
return V_40 -> V_50 [ V_46 ] ;
}
static struct V_2 * F_34 ( struct V_39 * V_40 , struct V_44 * V_45 , unsigned int V_41 )
{
int V_51 , V_52 ;
V_51 = F_29 ( & V_40 -> V_43 ) ;
while ( ( V_52 = F_35 ( & V_40 -> V_43 , V_51 ,
F_32 ( V_40 , V_41 ) ) ) != V_51 )
V_51 = V_52 ;
return V_40 -> V_50 [ V_51 ] ;
}
static struct V_2 * F_36 ( struct V_39 * V_40 , struct V_44 * V_45 , unsigned int V_41 )
{
unsigned int V_53 = F_37 () ;
return V_40 -> V_50 [ V_53 % V_41 ] ;
}
static struct V_44 * F_38 ( struct V_44 * V_45 )
{
#ifdef F_39
const struct V_54 * V_55 ;
T_1 V_56 ;
if ( V_45 -> V_57 != F_40 ( V_58 ) )
return V_45 ;
if ( ! F_41 ( V_45 , sizeof( struct V_54 ) ) )
return V_45 ;
V_55 = F_42 ( V_45 ) ;
if ( V_55 -> V_59 < 5 || V_55 -> V_60 != 4 )
return V_45 ;
if ( ! F_41 ( V_45 , V_55 -> V_59 * 4 ) )
return V_45 ;
V_55 = F_42 ( V_45 ) ;
V_56 = F_43 ( V_55 -> V_61 ) ;
if ( V_45 -> V_56 < V_56 || V_56 < ( V_55 -> V_59 * 4 ) )
return V_45 ;
if ( F_44 ( F_42 ( V_45 ) ) ) {
V_45 = F_45 ( V_45 , V_62 ) ;
if ( V_45 ) {
if ( F_46 ( V_45 , V_56 ) )
return V_45 ;
memset ( F_47 ( V_45 ) , 0 , sizeof( struct V_63 ) ) ;
if ( F_48 ( V_45 , V_64 ) )
return NULL ;
V_45 -> V_48 = 0 ;
}
}
#endif
return V_45 ;
}
static int F_49 ( struct V_44 * V_45 , struct V_65 * V_66 ,
struct V_67 * V_68 , struct V_65 * V_69 )
{
struct V_39 * V_40 = V_68 -> V_70 ;
unsigned int V_41 = V_40 -> V_71 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_50 ( F_51 ( V_66 ) , F_52 ( & V_40 -> V_72 ) ) ||
! V_41 ) {
F_53 ( V_45 ) ;
return 0 ;
}
switch ( V_40 -> type ) {
case V_73 :
default:
if ( V_40 -> V_74 ) {
V_45 = F_38 ( V_45 ) ;
if ( ! V_45 )
return 0 ;
}
F_54 ( V_45 ) ;
V_3 = F_33 ( V_40 , V_45 , V_41 ) ;
break;
case V_75 :
V_3 = F_34 ( V_40 , V_45 , V_41 ) ;
break;
case V_76 :
V_3 = F_36 ( V_40 , V_45 , V_41 ) ;
break;
}
V_4 = F_1 ( V_3 ) ;
return V_4 -> V_7 . V_77 ( V_45 , V_66 , & V_4 -> V_7 , V_69 ) ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_39 * V_40 = V_4 -> V_6 ;
F_12 ( & V_40 -> V_78 ) ;
V_40 -> V_50 [ V_40 -> V_71 ] = V_3 ;
F_19 () ;
V_40 -> V_71 ++ ;
F_10 ( & V_40 -> V_78 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_39 * V_40 = V_4 -> V_6 ;
int V_79 ;
F_12 ( & V_40 -> V_78 ) ;
for ( V_79 = 0 ; V_79 < V_40 -> V_71 ; V_79 ++ ) {
if ( V_40 -> V_50 [ V_79 ] == V_3 )
break;
}
F_55 ( V_79 >= V_40 -> V_71 ) ;
V_40 -> V_50 [ V_79 ] = V_40 -> V_50 [ V_40 -> V_71 - 1 ] ;
V_40 -> V_71 -- ;
F_10 ( & V_40 -> V_78 ) ;
}
static int F_56 ( struct V_2 * V_3 , T_2 V_80 , T_2 V_81 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_39 * V_40 , * V_82 ;
T_3 type = V_81 & 0xff ;
T_3 V_74 = ( V_81 & V_83 ) ? 1 : 0 ;
int V_84 ;
switch ( type ) {
case V_73 :
case V_75 :
case V_76 :
break;
default:
return - V_85 ;
}
if ( ! V_4 -> V_5 )
return - V_85 ;
if ( V_4 -> V_6 )
return - V_86 ;
F_57 ( & V_87 ) ;
V_82 = NULL ;
F_58 (f, &fanout_list, list) {
if ( V_40 -> V_80 == V_80 &&
F_52 ( & V_40 -> V_72 ) == F_59 ( V_3 ) ) {
V_82 = V_40 ;
break;
}
}
V_84 = - V_85 ;
if ( V_82 && V_82 -> V_74 != V_74 )
goto V_88;
if ( ! V_82 ) {
V_84 = - V_89 ;
V_82 = F_60 ( sizeof( * V_82 ) , V_90 ) ;
if ( ! V_82 )
goto V_88;
F_61 ( & V_82 -> V_72 , F_59 ( V_3 ) ) ;
V_82 -> V_80 = V_80 ;
V_82 -> type = type ;
V_82 -> V_74 = V_74 ;
F_62 ( & V_82 -> V_43 , 0 ) ;
F_63 ( & V_82 -> V_91 ) ;
F_64 ( & V_82 -> V_78 ) ;
F_62 ( & V_82 -> V_92 , 0 ) ;
V_82 -> V_7 . type = V_4 -> V_7 . type ;
V_82 -> V_7 . V_66 = V_4 -> V_7 . V_66 ;
V_82 -> V_7 . V_77 = F_49 ;
V_82 -> V_7 . V_70 = V_82 ;
F_4 ( & V_82 -> V_7 ) ;
F_65 ( & V_82 -> V_91 , & V_93 ) ;
}
V_84 = - V_85 ;
if ( V_82 -> type == type &&
V_82 -> V_7 . type == V_4 -> V_7 . type &&
V_82 -> V_7 . V_66 == V_4 -> V_7 . V_66 ) {
V_84 = - V_94 ;
if ( F_29 ( & V_82 -> V_92 ) < V_95 ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_82 ;
F_66 ( & V_82 -> V_92 ) ;
F_3 ( V_3 , V_4 ) ;
V_84 = 0 ;
}
}
V_88:
F_67 ( & V_87 ) ;
return V_84 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_39 * V_40 ;
V_40 = V_4 -> V_6 ;
if ( ! V_40 )
return;
V_4 -> V_6 = NULL ;
F_57 ( & V_87 ) ;
if ( F_69 ( & V_40 -> V_92 ) ) {
F_70 ( & V_40 -> V_91 ) ;
F_71 ( & V_40 -> V_7 ) ;
F_72 ( V_40 ) ;
}
F_67 ( & V_87 ) ;
}
static int F_73 ( struct V_44 * V_45 , struct V_65 * V_66 ,
struct V_67 * V_68 , struct V_65 * V_69 )
{
struct V_2 * V_3 ;
struct V_96 * V_97 ;
V_3 = V_68 -> V_70 ;
if ( V_45 -> V_98 == V_99 )
goto V_88;
if ( ! F_50 ( F_51 ( V_66 ) , F_59 ( V_3 ) ) )
goto V_88;
V_45 = F_45 ( V_45 , V_62 ) ;
if ( V_45 == NULL )
goto V_100;
F_74 ( V_45 ) ;
F_75 ( V_45 ) ;
V_97 = & F_76 ( V_45 ) -> V_101 . V_102 ;
F_77 ( V_45 , V_45 -> V_103 - F_78 ( V_45 ) ) ;
V_97 -> V_104 = V_66 -> type ;
F_79 ( V_97 -> V_105 , V_66 -> V_106 , sizeof( V_97 -> V_105 ) ) ;
V_97 -> V_107 = V_45 -> V_57 ;
if ( F_80 ( V_3 , V_45 ) == 0 )
return 0 ;
V_88:
F_53 ( V_45 ) ;
V_100:
return 0 ;
}
static int F_81 ( struct V_108 * V_109 , struct V_110 * V_2 ,
struct V_111 * V_112 , T_4 V_56 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_96 * V_113 = (struct V_96 * ) V_112 -> V_114 ;
struct V_44 * V_45 = NULL ;
struct V_65 * V_66 ;
T_5 V_115 = 0 ;
int V_84 ;
if ( V_113 ) {
if ( V_112 -> V_116 < sizeof( struct V_117 ) )
return - V_85 ;
if ( V_112 -> V_116 == sizeof( struct V_96 ) )
V_115 = V_113 -> V_107 ;
} else
return - V_118 ;
V_113 -> V_105 [ 13 ] = 0 ;
V_119:
F_82 () ;
V_66 = F_83 ( F_59 ( V_3 ) , V_113 -> V_105 ) ;
V_84 = - V_120 ;
if ( V_66 == NULL )
goto V_121;
V_84 = - V_122 ;
if ( ! ( V_66 -> V_123 & V_124 ) )
goto V_121;
V_84 = - V_125 ;
if ( V_56 > V_66 -> V_126 + V_66 -> V_127 + V_128 )
goto V_121;
if ( ! V_45 ) {
T_4 V_129 = F_84 ( V_66 ) ;
unsigned int V_130 = V_66 -> V_131 ? V_66 -> V_127 : 0 ;
F_85 () ;
V_45 = F_86 ( V_3 , V_56 + V_129 , 0 , V_90 ) ;
if ( V_45 == NULL )
return - V_132 ;
F_87 ( V_45 , V_129 ) ;
F_88 ( V_45 ) ;
if ( V_130 ) {
V_45 -> V_103 -= V_130 ;
V_45 -> V_133 -= V_130 ;
if ( V_56 < V_130 )
F_88 ( V_45 ) ;
}
V_84 = F_89 ( F_90 ( V_45 , V_56 ) , V_112 -> V_134 , V_56 ) ;
if ( V_84 )
goto V_135;
goto V_119;
}
if ( V_56 > ( V_66 -> V_126 + V_66 -> V_127 ) ) {
struct V_136 * V_137 ;
F_91 ( V_45 ) ;
V_137 = F_92 ( V_45 ) ;
if ( V_137 -> V_138 != F_40 ( V_139 ) ) {
V_84 = - V_125 ;
goto V_121;
}
}
V_45 -> V_57 = V_115 ;
V_45 -> V_66 = V_66 ;
V_45 -> V_140 = V_3 -> V_141 ;
V_45 -> V_142 = V_3 -> V_143 ;
V_84 = F_93 ( V_3 , & F_94 ( V_45 ) -> V_144 ) ;
if ( V_84 < 0 )
goto V_121;
F_95 ( V_45 ) ;
F_85 () ;
return V_56 ;
V_121:
F_85 () ;
V_135:
F_53 ( V_45 ) ;
return V_84 ;
}
static inline unsigned int F_96 ( const struct V_44 * V_45 ,
const struct V_2 * V_3 ,
unsigned int V_145 )
{
struct V_146 * V_147 ;
F_82 () ;
V_147 = F_97 ( V_3 -> V_146 ) ;
if ( V_147 != NULL )
V_145 = F_98 ( V_147 , V_45 ) ;
F_85 () ;
return V_145 ;
}
static int F_99 ( struct V_44 * V_45 , struct V_65 * V_66 ,
struct V_67 * V_68 , struct V_65 * V_69 )
{
struct V_2 * V_3 ;
struct V_148 * V_149 ;
struct V_1 * V_4 ;
T_3 * V_150 = V_45 -> V_103 ;
int V_151 = V_45 -> V_56 ;
unsigned int V_152 , V_145 ;
if ( V_45 -> V_98 == V_99 )
goto V_153;
V_3 = V_68 -> V_70 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_50 ( F_51 ( V_66 ) , F_59 ( V_3 ) ) )
goto V_153;
V_45 -> V_66 = V_66 ;
if ( V_66 -> V_131 ) {
if ( V_3 -> V_154 != V_155 )
F_77 ( V_45 , V_45 -> V_103 - F_78 ( V_45 ) ) ;
else if ( V_45 -> V_98 == V_156 ) {
F_100 ( V_45 , F_101 ( V_45 ) ) ;
}
}
V_152 = V_45 -> V_56 ;
V_145 = F_96 ( V_45 , V_3 , V_152 ) ;
if ( ! V_145 )
goto V_157;
if ( V_152 > V_145 )
V_152 = V_145 ;
if ( F_29 ( & V_3 -> V_36 ) + V_45 -> V_158 >=
( unsigned ) V_3 -> V_159 )
goto V_160;
if ( F_102 ( V_45 ) ) {
struct V_44 * V_161 = F_103 ( V_45 , V_62 ) ;
if ( V_161 == NULL )
goto V_160;
if ( V_150 != V_45 -> V_103 ) {
V_45 -> V_103 = V_150 ;
V_45 -> V_56 = V_151 ;
}
F_53 ( V_45 ) ;
V_45 = V_161 ;
}
F_104 ( sizeof( * F_76 ( V_45 ) ) + V_162 - 8 >
sizeof( V_45 -> V_163 ) ) ;
V_149 = & F_76 ( V_45 ) -> V_101 . V_164 ;
V_149 -> V_165 = V_166 ;
V_149 -> V_167 = V_66 -> type ;
V_149 -> V_168 = V_45 -> V_57 ;
V_149 -> V_169 = V_45 -> V_98 ;
if ( F_105 ( V_4 -> V_170 ) )
V_149 -> V_171 = V_69 -> V_172 ;
else
V_149 -> V_171 = V_66 -> V_172 ;
V_149 -> V_173 = F_106 ( V_45 , V_149 -> V_174 ) ;
F_76 ( V_45 ) -> V_175 = V_45 -> V_56 ;
if ( F_107 ( V_45 , V_152 ) )
goto V_160;
F_108 ( V_45 , V_3 ) ;
V_45 -> V_66 = NULL ;
F_74 ( V_45 ) ;
F_75 ( V_45 ) ;
F_12 ( & V_3 -> V_176 . V_78 ) ;
V_4 -> V_177 . V_178 ++ ;
V_45 -> V_179 = F_29 ( & V_3 -> V_180 ) ;
F_109 ( & V_3 -> V_176 , V_45 ) ;
F_10 ( & V_3 -> V_176 . V_78 ) ;
V_3 -> V_181 ( V_3 , V_45 -> V_56 ) ;
return 0 ;
V_160:
F_12 ( & V_3 -> V_176 . V_78 ) ;
V_4 -> V_177 . V_182 ++ ;
F_66 ( & V_3 -> V_180 ) ;
F_10 ( & V_3 -> V_176 . V_78 ) ;
V_157:
if ( V_150 != V_45 -> V_103 && F_102 ( V_45 ) ) {
V_45 -> V_103 = V_150 ;
V_45 -> V_56 = V_151 ;
}
V_153:
F_110 ( V_45 ) ;
return 0 ;
}
static int F_111 ( struct V_44 * V_45 , struct V_65 * V_66 ,
struct V_67 * V_68 , struct V_65 * V_69 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
struct V_148 * V_149 ;
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_17 ;
T_3 * V_150 = V_45 -> V_103 ;
int V_151 = V_45 -> V_56 ;
unsigned int V_152 , V_145 ;
unsigned long V_11 = V_183 | V_184 ;
unsigned short V_185 , V_186 , V_187 ;
struct V_44 * V_188 = NULL ;
struct V_189 V_190 ;
struct V_191 V_192 ;
struct V_193 * V_194 = F_112 ( V_45 ) ;
if ( V_45 -> V_98 == V_99 )
goto V_153;
V_3 = V_68 -> V_70 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_50 ( F_51 ( V_66 ) , F_59 ( V_3 ) ) )
goto V_153;
if ( V_66 -> V_131 ) {
if ( V_3 -> V_154 != V_155 )
F_77 ( V_45 , V_45 -> V_103 - F_78 ( V_45 ) ) ;
else if ( V_45 -> V_98 == V_156 ) {
F_100 ( V_45 , F_101 ( V_45 ) ) ;
}
}
if ( V_45 -> V_195 == V_196 )
V_11 |= V_197 ;
V_152 = V_45 -> V_56 ;
V_145 = F_96 ( V_45 , V_3 , V_152 ) ;
if ( ! V_145 )
goto V_157;
if ( V_152 > V_145 )
V_152 = V_145 ;
if ( V_3 -> V_154 == V_155 ) {
V_185 = V_186 = F_113 ( V_4 -> V_198 ) + 16 +
V_4 -> V_199 ;
} else {
unsigned V_200 = F_101 ( V_45 ) ;
V_186 = F_113 ( V_4 -> V_198 +
( V_200 < 16 ? 16 : V_200 ) ) +
V_4 -> V_199 ;
V_185 = V_186 - V_200 ;
}
if ( V_185 + V_152 > V_4 -> V_201 . V_30 ) {
if ( V_4 -> V_202 &&
F_29 ( & V_3 -> V_36 ) + V_45 -> V_158 <
( unsigned ) V_3 -> V_159 ) {
if ( F_102 ( V_45 ) ) {
V_188 = F_103 ( V_45 , V_62 ) ;
} else {
V_188 = F_114 ( V_45 ) ;
V_150 = V_45 -> V_103 ;
}
if ( V_188 )
F_108 ( V_188 , V_3 ) ;
}
V_152 = V_4 -> V_201 . V_30 - V_185 ;
if ( ( int ) V_152 < 0 )
V_152 = 0 ;
}
F_12 ( & V_3 -> V_176 . V_78 ) ;
V_17 . V_16 = F_23 ( V_4 , & V_4 -> V_201 , V_203 ) ;
if ( ! V_17 . V_16 )
goto V_204;
F_25 ( & V_4 -> V_201 ) ;
V_4 -> V_177 . V_178 ++ ;
if ( V_188 ) {
V_11 |= V_205 ;
F_109 ( & V_3 -> V_176 , V_188 ) ;
}
if ( ! V_4 -> V_177 . V_182 )
V_11 &= ~ V_183 ;
F_10 ( & V_3 -> V_176 . V_78 ) ;
F_115 ( V_45 , 0 , V_17 . V_16 + V_185 , V_152 ) ;
switch ( V_4 -> V_18 ) {
case V_19 :
V_17 . V_13 -> V_206 = V_45 -> V_56 ;
V_17 . V_13 -> V_207 = V_152 ;
V_17 . V_13 -> V_208 = V_185 ;
V_17 . V_13 -> V_209 = V_186 ;
if ( ( V_4 -> V_210 & V_211 )
&& V_194 -> V_212 . V_213 )
V_190 = F_116 ( V_194 -> V_212 ) ;
else if ( ( V_4 -> V_210 & V_214 )
&& V_194 -> V_215 . V_213 )
V_190 = F_116 ( V_194 -> V_215 ) ;
else if ( V_45 -> V_216 . V_213 )
V_190 = F_116 ( V_45 -> V_216 ) ;
else
F_117 ( & V_190 ) ;
V_17 . V_13 -> V_217 = V_190 . V_218 ;
V_17 . V_13 -> V_219 = V_190 . V_220 ;
V_187 = sizeof( * V_17 . V_13 ) ;
break;
case V_21 :
V_17 . V_15 -> V_206 = V_45 -> V_56 ;
V_17 . V_15 -> V_207 = V_152 ;
V_17 . V_15 -> V_208 = V_185 ;
V_17 . V_15 -> V_209 = V_186 ;
if ( ( V_4 -> V_210 & V_211 )
&& V_194 -> V_212 . V_213 )
V_192 = F_118 ( V_194 -> V_212 ) ;
else if ( ( V_4 -> V_210 & V_214 )
&& V_194 -> V_215 . V_213 )
V_192 = F_118 ( V_194 -> V_215 ) ;
else if ( V_45 -> V_216 . V_213 )
V_192 = F_118 ( V_45 -> V_216 ) ;
else
F_119 ( & V_192 ) ;
V_17 . V_15 -> V_217 = V_192 . V_218 ;
V_17 . V_15 -> V_221 = V_192 . V_222 ;
if ( F_120 ( V_45 ) ) {
V_17 . V_15 -> V_223 = F_121 ( V_45 ) ;
V_11 |= V_224 ;
} else {
V_17 . V_15 -> V_223 = 0 ;
}
V_17 . V_15 -> V_225 = 0 ;
V_187 = sizeof( * V_17 . V_15 ) ;
break;
default:
F_18 () ;
}
V_149 = V_17 . V_16 + F_113 ( V_187 ) ;
V_149 -> V_173 = F_106 ( V_45 , V_149 -> V_174 ) ;
V_149 -> V_165 = V_166 ;
V_149 -> V_167 = V_66 -> type ;
V_149 -> V_168 = V_45 -> V_57 ;
V_149 -> V_169 = V_45 -> V_98 ;
if ( F_105 ( V_4 -> V_170 ) )
V_149 -> V_171 = V_69 -> V_172 ;
else
V_149 -> V_171 = V_66 -> V_172 ;
F_122 () ;
#if V_226 == 1
{
T_3 * V_227 , * V_228 ;
V_228 = ( T_3 * ) F_123 ( ( unsigned long ) V_17 . V_16 + V_185 + V_152 ) ;
for ( V_227 = V_17 . V_16 ; V_227 < V_228 ; V_227 += V_229 )
F_15 ( F_16 ( V_227 ) ) ;
F_19 () ;
}
#endif
F_14 ( V_4 , V_17 . V_16 , V_11 ) ;
V_3 -> V_181 ( V_3 , 0 ) ;
V_157:
if ( V_150 != V_45 -> V_103 && F_102 ( V_45 ) ) {
V_45 -> V_103 = V_150 ;
V_45 -> V_56 = V_151 ;
}
V_153:
F_53 ( V_45 ) ;
return 0 ;
V_204:
V_4 -> V_177 . V_182 ++ ;
F_10 ( & V_3 -> V_176 . V_78 ) ;
V_3 -> V_181 ( V_3 , 0 ) ;
F_53 ( V_188 ) ;
goto V_157;
}
static void F_124 ( struct V_44 * V_45 )
{
struct V_1 * V_4 = F_1 ( V_45 -> V_3 ) ;
void * V_230 ;
F_55 ( V_45 == NULL ) ;
if ( F_125 ( V_4 -> V_231 . V_28 ) ) {
V_230 = F_94 ( V_45 ) -> V_232 ;
F_55 ( F_20 ( V_4 , V_230 ) != V_233 ) ;
F_55 ( F_29 ( & V_4 -> V_231 . V_234 ) == 0 ) ;
F_126 ( & V_4 -> V_231 . V_234 ) ;
F_14 ( V_4 , V_230 , V_235 ) ;
}
F_127 ( V_45 ) ;
}
static int F_128 ( struct V_1 * V_4 , struct V_44 * V_45 ,
void * V_10 , struct V_65 * V_66 , int V_236 ,
T_5 V_115 , unsigned char * V_237 )
{
union {
struct V_12 * V_13 ;
struct V_14 * V_15 ;
void * V_16 ;
} V_230 ;
int V_238 , V_239 , V_56 , V_206 , V_240 , V_241 ;
struct V_110 * V_2 = V_4 -> V_3 . V_242 ;
struct V_243 * V_243 ;
void * V_103 ;
int V_84 ;
V_230 . V_16 = V_10 ;
V_45 -> V_57 = V_115 ;
V_45 -> V_66 = V_66 ;
V_45 -> V_140 = V_4 -> V_3 . V_141 ;
V_45 -> V_142 = V_4 -> V_3 . V_143 ;
F_94 ( V_45 ) -> V_232 = V_230 . V_16 ;
switch ( V_4 -> V_18 ) {
case V_21 :
V_206 = V_230 . V_15 -> V_206 ;
break;
default:
V_206 = V_230 . V_13 -> V_206 ;
break;
}
if ( F_105 ( V_206 > V_236 ) ) {
F_17 ( L_3 , V_206 , V_236 ) ;
return - V_125 ;
}
F_87 ( V_45 , F_84 ( V_66 ) ) ;
F_88 ( V_45 ) ;
V_103 = V_230 . V_16 + V_4 -> V_198 - sizeof( struct V_148 ) ;
V_238 = V_206 ;
if ( V_2 -> type == V_155 ) {
V_84 = F_129 ( V_45 , V_66 , F_43 ( V_115 ) , V_237 ,
NULL , V_206 ) ;
if ( F_105 ( V_84 < 0 ) )
return - V_85 ;
} else if ( V_66 -> V_127 ) {
if ( F_105 ( V_206 <= V_66 -> V_127 ) ) {
F_17 ( L_4 ,
V_206 , V_66 -> V_127 ) ;
return - V_85 ;
}
F_77 ( V_45 , V_66 -> V_127 ) ;
V_84 = F_130 ( V_45 , 0 , V_103 ,
V_66 -> V_127 ) ;
if ( F_105 ( V_84 ) )
return V_84 ;
V_103 += V_66 -> V_127 ;
V_238 -= V_66 -> V_127 ;
}
V_84 = - V_244 ;
V_239 = F_131 ( V_103 ) ;
V_241 = V_229 - V_239 ;
V_56 = ( ( V_238 > V_241 ) ? V_241 : V_238 ) ;
V_45 -> V_245 = V_238 ;
V_45 -> V_56 += V_238 ;
V_45 -> V_158 += V_238 ;
F_132 ( V_238 , & V_4 -> V_3 . V_37 ) ;
while ( F_125 ( V_238 ) ) {
V_240 = F_94 ( V_45 ) -> V_240 ;
if ( F_105 ( V_240 >= V_246 ) ) {
F_17 ( L_5 ,
V_246 ) ;
return - V_244 ;
}
V_243 = F_16 ( V_103 ) ;
V_103 += V_56 ;
F_15 ( V_243 ) ;
F_133 ( V_243 ) ;
F_134 ( V_45 , V_240 , V_243 , V_239 , V_56 ) ;
V_238 -= V_56 ;
V_239 = 0 ;
V_241 = V_229 ;
V_56 = ( ( V_238 > V_241 ) ? V_241 : V_238 ) ;
}
return V_206 ;
}
static int F_135 ( struct V_1 * V_4 , struct V_111 * V_112 )
{
struct V_44 * V_45 ;
struct V_65 * V_66 ;
T_5 V_115 ;
bool V_247 = false ;
int V_84 , V_248 = 0 ;
void * V_230 ;
struct V_148 * V_113 = (struct V_148 * ) V_112 -> V_114 ;
int V_206 , V_236 ;
unsigned char * V_237 ;
int V_249 = 0 ;
int V_11 = 0 ;
F_57 ( & V_4 -> V_250 ) ;
V_84 = - V_251 ;
if ( V_113 == NULL ) {
V_66 = V_4 -> V_7 . V_66 ;
V_115 = V_4 -> V_41 ;
V_237 = NULL ;
} else {
V_84 = - V_85 ;
if ( V_112 -> V_116 < sizeof( struct V_148 ) )
goto V_88;
if ( V_112 -> V_116 < ( V_113 -> V_173
+ F_136 ( struct V_148 ,
V_174 ) ) )
goto V_88;
V_115 = V_113 -> V_168 ;
V_237 = V_113 -> V_174 ;
V_66 = F_137 ( F_59 ( & V_4 -> V_3 ) , V_113 -> V_171 ) ;
V_247 = true ;
}
V_84 = - V_252 ;
if ( F_105 ( V_66 == NULL ) )
goto V_88;
V_248 = V_66 -> V_127 ;
V_84 = - V_122 ;
if ( F_105 ( ! ( V_66 -> V_123 & V_124 ) ) )
goto V_253;
V_236 = V_4 -> V_231 . V_30
- ( V_4 -> V_198 - sizeof( struct V_148 ) ) ;
if ( V_236 > V_66 -> V_126 + V_248 )
V_236 = V_66 -> V_126 + V_248 ;
do {
V_230 = F_23 ( V_4 , & V_4 -> V_231 ,
V_254 ) ;
if ( F_105 ( V_230 == NULL ) ) {
F_138 () ;
continue;
}
V_11 = V_254 ;
V_45 = F_139 ( & V_4 -> V_3 ,
F_140 ( V_66 )
+ sizeof( struct V_148 ) ,
0 , & V_84 ) ;
if ( F_105 ( V_45 == NULL ) )
goto V_255;
V_206 = F_128 ( V_4 , V_45 , V_230 , V_66 , V_236 , V_115 ,
V_237 ) ;
if ( F_105 ( V_206 < 0 ) ) {
if ( V_4 -> V_256 ) {
F_14 ( V_4 , V_230 ,
V_235 ) ;
F_25 ( & V_4 -> V_231 ) ;
F_53 ( V_45 ) ;
continue;
} else {
V_11 = V_257 ;
V_84 = V_206 ;
goto V_255;
}
}
V_45 -> V_258 = F_124 ;
F_14 ( V_4 , V_230 , V_233 ) ;
F_66 ( & V_4 -> V_231 . V_234 ) ;
V_11 = V_254 ;
V_84 = F_95 ( V_45 ) ;
if ( F_105 ( V_84 > 0 ) ) {
V_84 = F_141 ( V_84 ) ;
if ( V_84 && F_20 ( V_4 , V_230 ) ==
V_235 ) {
V_45 = NULL ;
goto V_255;
}
V_84 = 0 ;
}
F_25 ( & V_4 -> V_231 ) ;
V_249 += V_206 ;
} while ( F_125 ( ( V_230 != NULL ) ||
( ( ! ( V_112 -> V_259 & V_260 ) ) &&
( F_29 ( & V_4 -> V_231 . V_234 ) ) ) )
);
V_84 = V_249 ;
goto V_253;
V_255:
F_14 ( V_4 , V_230 , V_11 ) ;
F_53 ( V_45 ) ;
V_253:
if ( V_247 )
F_142 ( V_66 ) ;
V_88:
F_67 ( & V_4 -> V_250 ) ;
return V_84 ;
}
static inline struct V_44 * F_143 ( struct V_2 * V_3 , T_4 V_261 ,
T_4 V_248 , T_4 V_56 ,
T_4 V_262 , int V_263 ,
int * V_84 )
{
struct V_44 * V_45 ;
if ( V_261 + V_56 < V_229 || ! V_262 )
V_262 = V_56 ;
V_45 = F_144 ( V_3 , V_261 + V_262 , V_56 - V_262 , V_263 ,
V_84 ) ;
if ( ! V_45 )
return NULL ;
F_87 ( V_45 , V_248 ) ;
F_90 ( V_45 , V_262 ) ;
V_45 -> V_245 = V_56 - V_262 ;
V_45 -> V_56 += V_56 - V_262 ;
return V_45 ;
}
static int F_145 ( struct V_110 * V_2 ,
struct V_111 * V_112 , T_4 V_56 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_148 * V_113 = (struct V_148 * ) V_112 -> V_114 ;
struct V_44 * V_45 ;
struct V_65 * V_66 ;
T_5 V_115 ;
bool V_247 = false ;
unsigned char * V_237 ;
int V_84 , V_248 = 0 ;
struct V_264 V_265 = { 0 } ;
int V_239 = 0 ;
int V_266 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned short V_267 = 0 ;
if ( V_113 == NULL ) {
V_66 = V_4 -> V_7 . V_66 ;
V_115 = V_4 -> V_41 ;
V_237 = NULL ;
} else {
V_84 = - V_85 ;
if ( V_112 -> V_116 < sizeof( struct V_148 ) )
goto V_88;
if ( V_112 -> V_116 < ( V_113 -> V_173 + F_136 ( struct V_148 , V_174 ) ) )
goto V_88;
V_115 = V_113 -> V_168 ;
V_237 = V_113 -> V_174 ;
V_66 = F_137 ( F_59 ( V_3 ) , V_113 -> V_171 ) ;
V_247 = true ;
}
V_84 = - V_252 ;
if ( V_66 == NULL )
goto V_121;
if ( V_2 -> type == V_268 )
V_248 = V_66 -> V_127 ;
V_84 = - V_122 ;
if ( ! ( V_66 -> V_123 & V_124 ) )
goto V_121;
if ( V_4 -> V_269 ) {
V_266 = sizeof( V_265 ) ;
V_84 = - V_85 ;
if ( V_56 < V_266 )
goto V_121;
V_56 -= V_266 ;
V_84 = F_89 ( ( void * ) & V_265 , V_112 -> V_134 ,
V_266 ) ;
if ( V_84 < 0 )
goto V_121;
if ( ( V_265 . V_123 & V_270 ) &&
( V_265 . V_271 + V_265 . V_272 + 2 >
V_265 . V_273 ) )
V_265 . V_273 = V_265 . V_271 +
V_265 . V_272 + 2 ;
V_84 = - V_85 ;
if ( V_265 . V_273 > V_56 )
goto V_121;
if ( V_265 . V_267 != V_274 ) {
switch ( V_265 . V_267 & ~ V_275 ) {
case V_276 :
V_267 = V_277 ;
break;
case V_278 :
V_267 = V_279 ;
break;
case V_280 :
V_267 = V_281 ;
break;
default:
goto V_121;
}
if ( V_265 . V_267 & V_275 )
V_267 |= V_282 ;
if ( V_265 . V_283 == 0 )
goto V_121;
}
}
V_84 = - V_125 ;
if ( ! V_267 && ( V_56 > V_66 -> V_126 + V_248 + V_128 ) )
goto V_121;
V_84 = - V_132 ;
V_45 = F_143 ( V_3 , F_140 ( V_66 ) ,
F_84 ( V_66 ) , V_56 , V_265 . V_273 ,
V_112 -> V_259 & V_260 , & V_84 ) ;
if ( V_45 == NULL )
goto V_121;
F_146 ( V_45 , V_248 ) ;
V_84 = - V_85 ;
if ( V_2 -> type == V_155 &&
( V_239 = F_129 ( V_45 , V_66 , F_43 ( V_115 ) , V_237 , NULL , V_56 ) ) < 0 )
goto V_135;
V_84 = F_147 ( V_45 , V_239 , V_112 -> V_134 , 0 , V_56 ) ;
if ( V_84 )
goto V_135;
V_84 = F_93 ( V_3 , & F_94 ( V_45 ) -> V_144 ) ;
if ( V_84 < 0 )
goto V_135;
if ( ! V_267 && ( V_56 > V_66 -> V_126 + V_248 ) ) {
struct V_136 * V_137 ;
F_91 ( V_45 ) ;
V_137 = F_92 ( V_45 ) ;
if ( V_137 -> V_138 != F_40 ( V_139 ) ) {
V_84 = - V_125 ;
goto V_135;
}
}
V_45 -> V_57 = V_115 ;
V_45 -> V_66 = V_66 ;
V_45 -> V_140 = V_3 -> V_141 ;
V_45 -> V_142 = V_3 -> V_143 ;
if ( V_4 -> V_269 ) {
if ( V_265 . V_123 & V_270 ) {
if ( ! F_148 ( V_45 , V_265 . V_271 ,
V_265 . V_272 ) ) {
V_84 = - V_85 ;
goto V_135;
}
}
F_94 ( V_45 ) -> V_283 = V_265 . V_283 ;
F_94 ( V_45 ) -> V_267 = V_267 ;
F_94 ( V_45 ) -> V_267 |= V_284 ;
F_94 ( V_45 ) -> V_285 = 0 ;
V_56 += V_266 ;
}
V_84 = F_95 ( V_45 ) ;
if ( V_84 > 0 && ( V_84 = F_141 ( V_84 ) ) != 0 )
goto V_121;
if ( V_247 )
F_142 ( V_66 ) ;
return V_56 ;
V_135:
F_53 ( V_45 ) ;
V_121:
if ( V_66 && V_247 )
F_142 ( V_66 ) ;
V_88:
return V_84 ;
}
static int F_149 ( struct V_108 * V_109 , struct V_110 * V_2 ,
struct V_111 * V_112 , T_4 V_56 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_231 . V_28 )
return F_135 ( V_4 , V_112 ) ;
else
return F_145 ( V_2 , V_112 , V_56 ) ;
}
static int F_150 ( struct V_110 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 ;
struct V_72 * V_72 ;
struct V_286 V_287 ;
if ( ! V_3 )
return 0 ;
V_72 = F_59 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
F_151 ( & V_72 -> V_288 . V_289 ) ;
F_152 ( V_3 ) ;
F_153 ( V_72 , V_3 -> V_290 , - 1 ) ;
F_154 ( & V_72 -> V_288 . V_289 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , false ) ;
if ( V_4 -> V_7 . V_66 ) {
F_142 ( V_4 -> V_7 . V_66 ) ;
V_4 -> V_7 . V_66 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_155 ( V_3 ) ;
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
if ( V_4 -> V_201 . V_28 )
F_156 ( V_3 , & V_287 , 1 , 0 ) ;
if ( V_4 -> V_231 . V_28 )
F_156 ( V_3 , & V_287 , 1 , 1 ) ;
F_68 ( V_3 ) ;
F_11 () ;
F_157 ( V_3 ) ;
V_2 -> V_3 = NULL ;
F_27 ( & V_3 -> V_176 ) ;
F_158 ( V_3 ) ;
F_159 ( V_3 ) ;
return 0 ;
}
static int F_160 ( struct V_2 * V_3 , struct V_65 * V_66 , T_5 V_57 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_6 )
return - V_85 ;
F_161 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_3 , true ) ;
V_4 -> V_41 = V_57 ;
V_4 -> V_7 . type = V_57 ;
if ( V_4 -> V_7 . V_66 )
F_142 ( V_4 -> V_7 . V_66 ) ;
V_4 -> V_7 . V_66 = V_66 ;
V_4 -> V_172 = V_66 ? V_66 -> V_172 : 0 ;
if ( V_57 == 0 )
goto V_121;
if ( ! V_66 || ( V_66 -> V_123 & V_124 ) ) {
F_2 ( V_3 ) ;
} else {
V_3 -> V_291 = V_122 ;
if ( ! F_30 ( V_3 , V_38 ) )
V_3 -> V_292 ( V_3 ) ;
}
V_121:
F_10 ( & V_4 -> V_9 ) ;
F_162 ( V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_110 * V_2 , struct V_117 * V_293 ,
int V_294 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
char V_106 [ 15 ] ;
struct V_65 * V_66 ;
int V_84 = - V_120 ;
if ( V_294 != sizeof( struct V_117 ) )
return - V_85 ;
F_79 ( V_106 , V_293 -> V_295 , sizeof( V_106 ) ) ;
V_66 = F_164 ( F_59 ( V_3 ) , V_106 ) ;
if ( V_66 )
V_84 = F_160 ( V_3 , V_66 , F_1 ( V_3 ) -> V_41 ) ;
return V_84 ;
}
static int F_165 ( struct V_110 * V_2 , struct V_117 * V_293 , int V_294 )
{
struct V_148 * V_149 = (struct V_148 * ) V_293 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_65 * V_66 = NULL ;
int V_84 ;
if ( V_294 < sizeof( struct V_148 ) )
return - V_85 ;
if ( V_149 -> V_165 != V_166 )
return - V_85 ;
if ( V_149 -> V_171 ) {
V_84 = - V_120 ;
V_66 = F_137 ( F_59 ( V_3 ) , V_149 -> V_171 ) ;
if ( V_66 == NULL )
goto V_88;
}
V_84 = F_160 ( V_3 , V_66 , V_149 -> V_168 ? : F_1 ( V_3 ) -> V_41 ) ;
V_88:
return V_84 ;
}
static int F_166 ( struct V_72 * V_72 , struct V_110 * V_2 , int V_57 ,
int V_296 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_5 V_115 = ( V_297 T_5 ) V_57 ;
int V_84 ;
if ( ! F_167 ( V_298 ) )
return - V_299 ;
if ( V_2 -> type != V_155 && V_2 -> type != V_268 &&
V_2 -> type != V_300 )
return - V_301 ;
V_2 -> V_302 = V_303 ;
V_84 = - V_132 ;
V_3 = F_168 ( V_72 , V_304 , V_90 , & V_305 ) ;
if ( V_3 == NULL )
goto V_88;
V_2 -> V_306 = & V_307 ;
if ( V_2 -> type == V_300 )
V_2 -> V_306 = & V_308 ;
F_169 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_3 ) ;
V_3 -> V_309 = V_304 ;
V_4 -> V_41 = V_115 ;
V_3 -> V_310 = F_26 ;
F_170 ( V_3 ) ;
F_64 ( & V_4 -> V_9 ) ;
F_171 ( & V_4 -> V_250 ) ;
V_4 -> V_7 . V_77 = F_99 ;
if ( V_2 -> type == V_300 )
V_4 -> V_7 . V_77 = F_73 ;
V_4 -> V_7 . V_70 = V_3 ;
if ( V_115 ) {
V_4 -> V_7 . type = V_115 ;
F_2 ( V_3 ) ;
}
F_151 ( & V_72 -> V_288 . V_289 ) ;
F_172 ( V_3 , & V_72 -> V_288 . V_311 ) ;
F_153 ( V_72 , & V_305 , 1 ) ;
F_154 ( & V_72 -> V_288 . V_289 ) ;
return 0 ;
V_88:
return V_84 ;
}
static int F_173 ( struct V_2 * V_3 , struct V_111 * V_112 , int V_56 )
{
struct V_312 * V_313 ;
struct V_44 * V_45 , * V_314 ;
int V_315 , V_84 ;
V_84 = - V_316 ;
V_45 = F_174 ( & V_3 -> V_35 ) ;
if ( V_45 == NULL )
goto V_88;
V_315 = V_45 -> V_56 ;
if ( V_315 > V_56 ) {
V_112 -> V_259 |= V_317 ;
V_315 = V_56 ;
}
V_84 = F_175 ( V_45 , 0 , V_112 -> V_134 , V_315 ) ;
if ( V_84 )
goto V_318;
F_176 ( V_112 , V_3 , V_45 ) ;
V_313 = F_177 ( V_45 ) ;
F_178 ( V_112 , V_319 , V_320 ,
sizeof( V_313 -> V_321 ) , & V_313 -> V_321 ) ;
V_112 -> V_259 |= V_322 ;
V_84 = V_315 ;
F_151 ( & V_3 -> V_35 . V_78 ) ;
V_3 -> V_291 = 0 ;
if ( ( V_314 = F_179 ( & V_3 -> V_35 ) ) != NULL ) {
V_3 -> V_291 = F_177 ( V_314 ) -> V_321 . V_323 ;
F_154 ( & V_3 -> V_35 . V_78 ) ;
V_3 -> V_292 ( V_3 ) ;
} else
F_154 ( & V_3 -> V_35 . V_78 ) ;
V_318:
F_53 ( V_45 ) ;
V_88:
return V_84 ;
}
static int F_180 ( struct V_108 * V_109 , struct V_110 * V_2 ,
struct V_111 * V_112 , T_4 V_56 , int V_123 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_44 * V_45 ;
int V_315 , V_84 ;
struct V_148 * V_149 ;
int V_266 = 0 ;
V_84 = - V_85 ;
if ( V_123 & ~ ( V_324 | V_260 | V_317 | V_325 | V_322 ) )
goto V_88;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_123 & V_322 ) {
V_84 = F_173 ( V_3 , V_112 , V_56 ) ;
goto V_88;
}
V_45 = F_181 ( V_3 , V_123 , V_123 & V_260 , & V_84 ) ;
if ( V_45 == NULL )
goto V_88;
if ( F_1 ( V_3 ) -> V_269 ) {
struct V_264 V_265 = { 0 } ;
V_84 = - V_85 ;
V_266 = sizeof( V_265 ) ;
if ( V_56 < V_266 )
goto V_135;
V_56 -= V_266 ;
if ( F_182 ( V_45 ) ) {
struct V_326 * V_327 = F_94 ( V_45 ) ;
V_265 . V_273 = F_183 ( V_45 ) ;
V_265 . V_283 = V_327 -> V_283 ;
if ( V_327 -> V_267 & V_277 )
V_265 . V_267 = V_276 ;
else if ( V_327 -> V_267 & V_279 )
V_265 . V_267 = V_278 ;
else if ( V_327 -> V_267 & V_281 )
V_265 . V_267 = V_280 ;
else if ( V_327 -> V_267 & V_328 )
goto V_135;
else
F_18 () ;
if ( V_327 -> V_267 & V_282 )
V_265 . V_267 |= V_275 ;
} else
V_265 . V_267 = V_274 ;
if ( V_45 -> V_195 == V_196 ) {
V_265 . V_123 = V_270 ;
V_265 . V_271 = F_184 ( V_45 ) ;
V_265 . V_272 = V_45 -> V_272 ;
} else if ( V_45 -> V_195 == V_329 ) {
V_265 . V_123 = V_330 ;
}
V_84 = F_185 ( V_112 -> V_134 , ( void * ) & V_265 ,
V_266 ) ;
if ( V_84 < 0 )
goto V_135;
}
V_149 = & F_76 ( V_45 ) -> V_101 . V_164 ;
if ( V_2 -> type == V_300 )
V_112 -> V_116 = sizeof( struct V_96 ) ;
else
V_112 -> V_116 = V_149 -> V_173 + F_136 ( struct V_148 , V_174 ) ;
V_315 = V_45 -> V_56 ;
if ( V_315 > V_56 ) {
V_315 = V_56 ;
V_112 -> V_259 |= V_317 ;
}
V_84 = F_175 ( V_45 , 0 , V_112 -> V_134 , V_315 ) ;
if ( V_84 )
goto V_135;
F_186 ( V_112 , V_3 , V_45 ) ;
if ( V_112 -> V_114 )
memcpy ( V_112 -> V_114 , & F_76 ( V_45 ) -> V_101 ,
V_112 -> V_116 ) ;
if ( F_1 ( V_3 ) -> V_331 ) {
struct V_332 V_333 ;
V_333 . V_20 = V_184 ;
if ( V_45 -> V_195 == V_196 )
V_333 . V_20 |= V_197 ;
V_333 . V_206 = F_76 ( V_45 ) -> V_175 ;
V_333 . V_207 = V_45 -> V_56 ;
V_333 . V_208 = 0 ;
V_333 . V_209 = F_101 ( V_45 ) ;
if ( F_120 ( V_45 ) ) {
V_333 . V_223 = F_121 ( V_45 ) ;
V_333 . V_20 |= V_224 ;
} else {
V_333 . V_223 = 0 ;
}
V_333 . V_225 = 0 ;
F_178 ( V_112 , V_319 , V_334 , sizeof( V_333 ) , & V_333 ) ;
}
V_84 = V_266 + ( ( V_123 & V_317 ) ? V_45 -> V_56 : V_315 ) ;
V_135:
F_187 ( V_3 , V_45 ) ;
V_88:
return V_84 ;
}
static int F_188 ( struct V_110 * V_2 , struct V_117 * V_293 ,
int * V_335 , int V_336 )
{
struct V_65 * V_66 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_336 )
return - V_337 ;
V_293 -> V_338 = V_166 ;
F_82 () ;
V_66 = F_189 ( F_59 ( V_3 ) , F_1 ( V_3 ) -> V_172 ) ;
if ( V_66 )
strncpy ( V_293 -> V_295 , V_66 -> V_106 , 14 ) ;
else
memset ( V_293 -> V_295 , 0 , 14 ) ;
F_85 () ;
* V_335 = sizeof( * V_293 ) ;
return 0 ;
}
static int F_190 ( struct V_110 * V_2 , struct V_117 * V_293 ,
int * V_335 , int V_336 )
{
struct V_65 * V_66 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_191 ( struct V_148 * , V_149 , V_293 ) ;
if ( V_336 )
return - V_337 ;
V_149 -> V_165 = V_166 ;
V_149 -> V_171 = V_4 -> V_172 ;
V_149 -> V_168 = V_4 -> V_41 ;
V_149 -> V_169 = 0 ;
F_82 () ;
V_66 = F_189 ( F_59 ( V_3 ) , V_4 -> V_172 ) ;
if ( V_66 ) {
V_149 -> V_167 = V_66 -> type ;
V_149 -> V_173 = V_66 -> V_294 ;
memcpy ( V_149 -> V_174 , V_66 -> V_339 , V_66 -> V_294 ) ;
} else {
V_149 -> V_167 = 0 ;
V_149 -> V_173 = 0 ;
}
F_85 () ;
* V_335 = F_136 ( struct V_148 , V_174 ) + V_149 -> V_173 ;
return 0 ;
}
static int F_192 ( struct V_65 * V_66 , struct V_340 * V_79 ,
int V_341 )
{
switch ( V_79 -> type ) {
case V_342 :
if ( V_79 -> V_343 != V_66 -> V_294 )
return - V_85 ;
if ( V_341 > 0 )
return F_193 ( V_66 , V_79 -> V_237 ) ;
else
return F_194 ( V_66 , V_79 -> V_237 ) ;
break;
case V_344 :
return F_195 ( V_66 , V_341 ) ;
break;
case V_345 :
return F_196 ( V_66 , V_341 ) ;
break;
case V_346 :
if ( V_79 -> V_343 != V_66 -> V_294 )
return - V_85 ;
if ( V_341 > 0 )
return F_197 ( V_66 , V_79 -> V_237 ) ;
else
return F_198 ( V_66 , V_79 -> V_237 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_199 ( struct V_65 * V_66 , struct V_340 * V_79 , int V_341 )
{
for ( ; V_79 ; V_79 = V_79 -> V_347 ) {
if ( V_79 -> V_172 == V_66 -> V_172 )
F_192 ( V_66 , V_79 , V_341 ) ;
}
}
static int F_200 ( struct V_2 * V_3 , struct V_348 * V_349 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_340 * V_350 , * V_79 ;
struct V_65 * V_66 ;
int V_84 ;
F_201 () ;
V_84 = - V_120 ;
V_66 = F_202 ( F_59 ( V_3 ) , V_349 -> V_351 ) ;
if ( ! V_66 )
goto V_352;
V_84 = - V_85 ;
if ( V_349 -> V_353 > V_66 -> V_294 )
goto V_352;
V_84 = - V_132 ;
V_79 = F_203 ( sizeof( * V_79 ) , V_90 ) ;
if ( V_79 == NULL )
goto V_352;
V_84 = 0 ;
for ( V_350 = V_4 -> V_354 ; V_350 ; V_350 = V_350 -> V_347 ) {
if ( V_350 -> V_172 == V_349 -> V_351 &&
V_350 -> type == V_349 -> V_355 &&
V_350 -> V_343 == V_349 -> V_353 &&
memcmp ( V_350 -> V_237 , V_349 -> V_356 , V_350 -> V_343 ) == 0 ) {
V_350 -> V_357 ++ ;
F_72 ( V_79 ) ;
goto V_352;
}
}
V_79 -> type = V_349 -> V_355 ;
V_79 -> V_172 = V_349 -> V_351 ;
V_79 -> V_343 = V_349 -> V_353 ;
memcpy ( V_79 -> V_237 , V_349 -> V_356 , V_79 -> V_343 ) ;
V_79 -> V_357 = 1 ;
V_79 -> V_347 = V_4 -> V_354 ;
V_4 -> V_354 = V_79 ;
V_84 = F_192 ( V_66 , V_79 , 1 ) ;
if ( V_84 ) {
V_4 -> V_354 = V_79 -> V_347 ;
F_72 ( V_79 ) ;
}
V_352:
F_204 () ;
return V_84 ;
}
static int F_205 ( struct V_2 * V_3 , struct V_348 * V_349 )
{
struct V_340 * V_350 , * * V_358 ;
F_201 () ;
for ( V_358 = & F_1 ( V_3 ) -> V_354 ; ( V_350 = * V_358 ) != NULL ; V_358 = & V_350 -> V_347 ) {
if ( V_350 -> V_172 == V_349 -> V_351 &&
V_350 -> type == V_349 -> V_355 &&
V_350 -> V_343 == V_349 -> V_353 &&
memcmp ( V_350 -> V_237 , V_349 -> V_356 , V_350 -> V_343 ) == 0 ) {
if ( -- V_350 -> V_357 == 0 ) {
struct V_65 * V_66 ;
* V_358 = V_350 -> V_347 ;
V_66 = F_202 ( F_59 ( V_3 ) , V_350 -> V_172 ) ;
if ( V_66 )
F_192 ( V_66 , V_350 , - 1 ) ;
F_72 ( V_350 ) ;
}
F_204 () ;
return 0 ;
}
}
F_204 () ;
return - V_359 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_340 * V_350 ;
if ( ! V_4 -> V_354 )
return;
F_201 () ;
while ( ( V_350 = V_4 -> V_354 ) != NULL ) {
struct V_65 * V_66 ;
V_4 -> V_354 = V_350 -> V_347 ;
V_66 = F_202 ( F_59 ( V_3 ) , V_350 -> V_172 ) ;
if ( V_66 != NULL )
F_192 ( V_66 , V_350 , - 1 ) ;
F_72 ( V_350 ) ;
}
F_204 () ;
}
static int
F_206 ( struct V_110 * V_2 , int V_360 , int V_361 , char T_6 * V_362 , unsigned int V_363 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_364 ;
if ( V_360 != V_319 )
return - V_365 ;
switch ( V_361 ) {
case V_366 :
case V_367 :
{
struct V_348 V_349 ;
int V_56 = V_363 ;
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
if ( V_56 < sizeof( struct V_368 ) )
return - V_85 ;
if ( V_56 > sizeof( V_349 ) )
V_56 = sizeof( V_349 ) ;
if ( F_207 ( & V_349 , V_362 , V_56 ) )
return - V_244 ;
if ( V_56 < ( V_349 . V_353 + F_136 ( struct V_368 , V_356 ) ) )
return - V_85 ;
if ( V_361 == V_366 )
V_364 = F_200 ( V_3 , & V_349 ) ;
else
V_364 = F_205 ( V_3 , & V_349 ) ;
return V_364 ;
}
case V_369 :
case V_370 :
{
struct V_286 V_287 ;
if ( V_363 < sizeof( V_287 ) )
return - V_85 ;
if ( F_1 ( V_3 ) -> V_269 )
return - V_85 ;
if ( F_207 ( & V_287 , V_362 , sizeof( V_287 ) ) )
return - V_244 ;
return F_156 ( V_3 , & V_287 , 0 , V_361 == V_370 ) ;
}
case V_371 :
{
int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
F_1 ( V_3 ) -> V_202 = V_372 ;
return 0 ;
}
case V_373 :
{
int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( V_4 -> V_201 . V_28 || V_4 -> V_231 . V_28 )
return - V_251 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
switch ( V_372 ) {
case V_19 :
case V_21 :
V_4 -> V_18 = V_372 ;
return 0 ;
default:
return - V_85 ;
}
}
case V_374 :
{
unsigned int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( V_4 -> V_201 . V_28 || V_4 -> V_231 . V_28 )
return - V_251 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_199 = V_372 ;
return 0 ;
}
case V_375 :
{
unsigned int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( V_4 -> V_201 . V_28 || V_4 -> V_231 . V_28 )
return - V_251 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_256 = ! ! V_372 ;
return 0 ;
}
case V_334 :
{
int V_372 ;
if ( V_363 < sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_331 = ! ! V_372 ;
return 0 ;
}
case V_376 :
{
int V_372 ;
if ( V_363 < sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_170 = ! ! V_372 ;
return 0 ;
}
case V_377 :
{
int V_372 ;
if ( V_2 -> type != V_268 )
return - V_85 ;
if ( V_4 -> V_201 . V_28 || V_4 -> V_231 . V_28 )
return - V_251 ;
if ( V_363 < sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_269 = ! ! V_372 ;
return 0 ;
}
case V_378 :
{
int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
V_4 -> V_210 = V_372 ;
return 0 ;
}
case V_379 :
{
int V_372 ;
if ( V_363 != sizeof( V_372 ) )
return - V_85 ;
if ( F_207 ( & V_372 , V_362 , sizeof( V_372 ) ) )
return - V_244 ;
return F_56 ( V_3 , V_372 & 0xffff , V_372 >> 16 ) ;
}
default:
return - V_365 ;
}
}
static int F_208 ( struct V_110 * V_2 , int V_360 , int V_361 ,
char T_6 * V_362 , int T_6 * V_363 )
{
int V_56 ;
int V_372 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
void * V_103 ;
struct V_380 V_381 ;
if ( V_360 != V_319 )
return - V_365 ;
if ( F_209 ( V_56 , V_363 ) )
return - V_244 ;
if ( V_56 < 0 )
return - V_85 ;
switch ( V_361 ) {
case V_382 :
if ( V_56 > sizeof( struct V_380 ) )
V_56 = sizeof( struct V_380 ) ;
F_151 ( & V_3 -> V_176 . V_78 ) ;
V_381 = V_4 -> V_177 ;
memset ( & V_4 -> V_177 , 0 , sizeof( V_381 ) ) ;
F_154 ( & V_3 -> V_176 . V_78 ) ;
V_381 . V_178 += V_381 . V_182 ;
V_103 = & V_381 ;
break;
case V_334 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = V_4 -> V_331 ;
V_103 = & V_372 ;
break;
case V_376 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = V_4 -> V_170 ;
V_103 = & V_372 ;
break;
case V_377 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = V_4 -> V_269 ;
V_103 = & V_372 ;
break;
case V_373 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = V_4 -> V_18 ;
V_103 = & V_372 ;
break;
case V_383 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
if ( F_207 ( & V_372 , V_362 , V_56 ) )
return - V_244 ;
switch ( V_372 ) {
case V_19 :
V_372 = sizeof( struct V_12 ) ;
break;
case V_21 :
V_372 = sizeof( struct V_14 ) ;
break;
default:
return - V_85 ;
}
V_103 = & V_372 ;
break;
case V_374 :
if ( V_56 > sizeof( unsigned int ) )
V_56 = sizeof( unsigned int ) ;
V_372 = V_4 -> V_199 ;
V_103 = & V_372 ;
break;
case V_375 :
if ( V_56 > sizeof( unsigned int ) )
V_56 = sizeof( unsigned int ) ;
V_372 = V_4 -> V_256 ;
V_103 = & V_372 ;
break;
case V_378 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = V_4 -> V_210 ;
V_103 = & V_372 ;
break;
case V_379 :
if ( V_56 > sizeof( int ) )
V_56 = sizeof( int ) ;
V_372 = ( V_4 -> V_6 ?
( ( T_1 ) V_4 -> V_6 -> V_80 |
( ( T_1 ) V_4 -> V_6 -> type << 16 ) ) :
0 ) ;
V_103 = & V_372 ;
break;
default:
return - V_365 ;
}
if ( F_210 ( V_56 , V_363 ) )
return - V_244 ;
if ( F_211 ( V_362 , V_103 , V_56 ) )
return - V_244 ;
return 0 ;
}
static int F_212 ( struct V_384 * V_385 , unsigned long V_112 , void * V_103 )
{
struct V_2 * V_3 ;
struct V_386 * V_387 ;
struct V_65 * V_66 = V_103 ;
struct V_72 * V_72 = F_51 ( V_66 ) ;
F_82 () ;
F_213 (sk, node, &net->packet.sklist) {
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_112 ) {
case V_388 :
if ( V_4 -> V_354 )
F_199 ( V_66 , V_4 -> V_354 , - 1 ) ;
case V_389 :
if ( V_66 -> V_172 == V_4 -> V_172 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_3 , false ) ;
V_3 -> V_291 = V_122 ;
if ( ! F_30 ( V_3 , V_38 ) )
V_3 -> V_292 ( V_3 ) ;
}
if ( V_112 == V_388 ) {
V_4 -> V_172 = - 1 ;
if ( V_4 -> V_7 . V_66 )
F_142 ( V_4 -> V_7 . V_66 ) ;
V_4 -> V_7 . V_66 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
}
break;
case V_390 :
if ( V_66 -> V_172 == V_4 -> V_172 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_41 )
F_2 ( V_3 ) ;
F_10 ( & V_4 -> V_9 ) ;
}
break;
}
}
F_85 () ;
return V_391 ;
}
static int F_214 ( struct V_110 * V_2 , unsigned int V_392 ,
unsigned long V_393 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
switch ( V_392 ) {
case V_394 :
{
int V_395 = F_215 ( V_3 ) ;
return F_210 ( V_395 , ( int T_6 * ) V_393 ) ;
}
case V_396 :
{
struct V_44 * V_45 ;
int V_395 = 0 ;
F_151 ( & V_3 -> V_176 . V_78 ) ;
V_45 = F_179 ( & V_3 -> V_176 ) ;
if ( V_45 )
V_395 = V_45 -> V_56 ;
F_154 ( & V_3 -> V_176 . V_78 ) ;
return F_210 ( V_395 , ( int T_6 * ) V_393 ) ;
}
case V_397 :
return F_216 ( V_3 , (struct V_189 T_6 * ) V_393 ) ;
case V_398 :
return F_217 ( V_3 , (struct V_191 T_6 * ) V_393 ) ;
#ifdef F_39
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
return V_413 . V_414 ( V_2 , V_392 , V_393 ) ;
#endif
default:
return - V_415 ;
}
return 0 ;
}
static unsigned int F_218 ( struct V_416 * V_416 , struct V_110 * V_2 ,
T_7 * V_417 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_418 = F_219 ( V_416 , V_2 , V_417 ) ;
F_151 ( & V_3 -> V_176 . V_78 ) ;
if ( V_4 -> V_201 . V_28 ) {
if ( ! F_24 ( V_4 , & V_4 -> V_201 , V_203 ) )
V_418 |= V_419 | V_420 ;
}
F_154 ( & V_3 -> V_176 . V_78 ) ;
F_151 ( & V_3 -> V_421 . V_78 ) ;
if ( V_4 -> V_231 . V_28 ) {
if ( F_23 ( V_4 , & V_4 -> V_231 , V_235 ) )
V_418 |= V_422 | V_423 ;
}
F_154 ( & V_3 -> V_421 . V_78 ) ;
return V_418 ;
}
static void F_220 ( struct V_424 * V_425 )
{
struct V_416 * V_416 = V_425 -> V_426 ;
struct V_110 * V_2 = V_416 -> V_427 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_66 ( & F_1 ( V_3 ) -> V_428 ) ;
}
static void F_221 ( struct V_424 * V_425 )
{
struct V_416 * V_416 = V_425 -> V_426 ;
struct V_110 * V_2 = V_416 -> V_427 ;
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 )
F_126 ( & F_1 ( V_3 ) -> V_428 ) ;
}
static void F_222 ( struct V_429 * V_28 , unsigned int V_430 ,
unsigned int V_56 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_56 ; V_79 ++ ) {
if ( F_125 ( V_28 [ V_79 ] . V_29 ) ) {
if ( F_223 ( V_28 [ V_79 ] . V_29 ) )
F_224 ( V_28 [ V_79 ] . V_29 ) ;
else
F_225 ( ( unsigned long ) V_28 [ V_79 ] . V_29 ,
V_430 ) ;
V_28 [ V_79 ] . V_29 = NULL ;
}
}
F_72 ( V_28 ) ;
}
static inline char * F_226 ( unsigned long V_430 )
{
char * V_29 = NULL ;
T_8 V_431 = V_90 | V_432 |
V_433 | V_434 | V_435 ;
V_29 = ( char * ) F_227 ( V_431 , V_430 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_228 ( ( 1 << V_430 ) * V_229 ) ;
if ( V_29 )
return V_29 ;
V_431 &= ~ V_435 ;
V_29 = ( char * ) F_227 ( V_431 , V_430 ) ;
if ( V_29 )
return V_29 ;
return NULL ;
}
static struct V_429 * F_229 ( struct V_286 * V_287 , int V_430 )
{
unsigned int V_436 = V_287 -> V_437 ;
struct V_429 * V_28 ;
int V_79 ;
V_28 = F_230 ( V_436 , sizeof( struct V_429 ) , V_90 ) ;
if ( F_105 ( ! V_28 ) )
goto V_88;
for ( V_79 = 0 ; V_79 < V_436 ; V_79 ++ ) {
V_28 [ V_79 ] . V_29 = F_226 ( V_430 ) ;
if ( F_105 ( ! V_28 [ V_79 ] . V_29 ) )
goto V_438;
}
V_88:
return V_28 ;
V_438:
F_222 ( V_28 , V_430 , V_436 ) ;
V_28 = NULL ;
goto V_88;
}
static int F_156 ( struct V_2 * V_3 , struct V_286 * V_287 ,
int V_439 , int V_231 )
{
struct V_429 * V_28 = NULL ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_440 , V_430 = 0 ;
struct V_22 * V_23 ;
struct V_441 * V_442 ;
T_5 V_41 ;
int V_84 ;
V_23 = V_231 ? & V_4 -> V_231 : & V_4 -> V_201 ;
V_442 = V_231 ? & V_3 -> V_421 : & V_3 -> V_176 ;
V_84 = - V_251 ;
if ( ! V_439 ) {
if ( F_29 ( & V_4 -> V_428 ) )
goto V_88;
if ( F_29 ( & V_23 -> V_234 ) )
goto V_88;
}
if ( V_287 -> V_437 ) {
V_84 = - V_251 ;
if ( F_105 ( V_23 -> V_28 ) )
goto V_88;
switch ( V_4 -> V_18 ) {
case V_19 :
V_4 -> V_198 = V_443 ;
break;
case V_21 :
V_4 -> V_198 = V_444 ;
break;
}
V_84 = - V_85 ;
if ( F_105 ( ( int ) V_287 -> V_445 <= 0 ) )
goto V_88;
if ( F_105 ( V_287 -> V_445 & ( V_229 - 1 ) ) )
goto V_88;
if ( F_105 ( V_287 -> V_446 < V_4 -> V_198 +
V_4 -> V_199 ) )
goto V_88;
if ( F_105 ( V_287 -> V_446 & ( V_447 - 1 ) ) )
goto V_88;
V_23 -> V_27 = V_287 -> V_445 / V_287 -> V_446 ;
if ( F_105 ( V_23 -> V_27 <= 0 ) )
goto V_88;
if ( F_105 ( ( V_23 -> V_27 * V_287 -> V_437 ) !=
V_287 -> V_448 ) )
goto V_88;
V_84 = - V_89 ;
V_430 = F_231 ( V_287 -> V_445 ) ;
V_28 = F_229 ( V_287 , V_430 ) ;
if ( F_105 ( ! V_28 ) )
goto V_88;
}
else {
V_84 = - V_85 ;
if ( F_105 ( V_287 -> V_448 ) )
goto V_88;
}
F_161 ( V_3 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_440 = V_4 -> V_5 ;
V_41 = V_4 -> V_41 ;
if ( V_440 ) {
V_4 -> V_41 = 0 ;
F_6 ( V_3 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_84 = - V_251 ;
F_57 ( & V_4 -> V_250 ) ;
if ( V_439 || F_29 ( & V_4 -> V_428 ) == 0 ) {
V_84 = 0 ;
F_151 ( & V_442 -> V_78 ) ;
F_232 ( V_23 -> V_28 , V_28 ) ;
V_23 -> V_33 = ( V_287 -> V_448 - 1 ) ;
V_23 -> V_31 = 0 ;
V_23 -> V_30 = V_287 -> V_446 ;
F_154 ( & V_442 -> V_78 ) ;
F_232 ( V_23 -> V_449 , V_430 ) ;
F_232 ( V_23 -> V_450 , V_287 -> V_437 ) ;
V_23 -> V_451 = V_287 -> V_445 / V_229 ;
V_4 -> V_7 . V_77 = ( V_4 -> V_201 . V_28 ) ?
F_111 : F_99 ;
F_27 ( V_442 ) ;
if ( F_29 ( & V_4 -> V_428 ) )
F_17 ( L_6 ,
F_29 ( & V_4 -> V_428 ) ) ;
}
F_67 ( & V_4 -> V_250 ) ;
F_12 ( & V_4 -> V_9 ) ;
if ( V_440 ) {
V_4 -> V_41 = V_41 ;
F_2 ( V_3 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_162 ( V_3 ) ;
if ( V_28 )
F_222 ( V_28 , V_430 , V_287 -> V_437 ) ;
V_88:
return V_84 ;
}
static int F_233 ( struct V_416 * V_416 , struct V_110 * V_2 ,
struct V_424 * V_425 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_452 , V_453 ;
struct V_22 * V_23 ;
unsigned long V_227 ;
int V_84 = - V_85 ;
int V_79 ;
if ( V_425 -> V_454 )
return - V_85 ;
F_57 ( & V_4 -> V_250 ) ;
V_453 = 0 ;
for ( V_23 = & V_4 -> V_201 ; V_23 <= & V_4 -> V_231 ; V_23 ++ ) {
if ( V_23 -> V_28 ) {
V_453 += V_23 -> V_450
* V_23 -> V_451
* V_229 ;
}
}
if ( V_453 == 0 )
goto V_88;
V_452 = V_425 -> V_455 - V_425 -> V_456 ;
if ( V_452 != V_453 )
goto V_88;
V_227 = V_425 -> V_456 ;
for ( V_23 = & V_4 -> V_201 ; V_23 <= & V_4 -> V_231 ; V_23 ++ ) {
if ( V_23 -> V_28 == NULL )
continue;
for ( V_79 = 0 ; V_79 < V_23 -> V_450 ; V_79 ++ ) {
struct V_243 * V_243 ;
void * V_457 = V_23 -> V_28 [ V_79 ] . V_29 ;
int V_458 ;
for ( V_458 = 0 ; V_458 < V_23 -> V_451 ; V_458 ++ ) {
V_243 = F_16 ( V_457 ) ;
V_84 = F_234 ( V_425 , V_227 , V_243 ) ;
if ( F_105 ( V_84 ) )
goto V_88;
V_227 += V_229 ;
V_457 += V_229 ;
}
}
}
F_66 ( & V_4 -> V_428 ) ;
V_425 -> V_459 = & V_460 ;
V_84 = 0 ;
V_88:
F_67 ( & V_4 -> V_250 ) ;
return V_84 ;
}
static void * F_235 ( struct V_461 * V_462 , T_9 * V_463 )
__acquires( T_10 )
{
struct V_72 * V_72 = F_236 ( V_462 ) ;
F_82 () ;
return F_237 ( & V_72 -> V_288 . V_311 , * V_463 ) ;
}
static void * F_238 ( struct V_461 * V_462 , void * V_464 , T_9 * V_463 )
{
struct V_72 * V_72 = F_236 ( V_462 ) ;
return F_239 ( V_464 , & V_72 -> V_288 . V_311 , V_463 ) ;
}
static void F_240 ( struct V_461 * V_462 , void * V_464 )
__releases( T_10 )
{
F_85 () ;
}
static int F_241 ( struct V_461 * V_462 , void * V_464 )
{
if ( V_464 == V_465 )
F_242 ( V_462 , L_7 ) ;
else {
struct V_2 * V_466 = F_243 ( V_464 ) ;
const struct V_1 * V_4 = F_1 ( V_466 ) ;
F_244 ( V_462 ,
L_8 ,
V_466 ,
F_29 ( & V_466 -> V_467 ) ,
V_466 -> V_154 ,
F_43 ( V_4 -> V_41 ) ,
V_4 -> V_172 ,
V_4 -> V_5 ,
F_29 ( & V_466 -> V_36 ) ,
F_245 ( V_466 ) ,
F_246 ( V_466 ) ) ;
}
return 0 ;
}
static int F_247 ( struct V_468 * V_468 , struct V_416 * V_416 )
{
return F_248 ( V_468 , V_416 , & V_469 ,
sizeof( struct V_470 ) ) ;
}
static int T_11 F_249 ( struct V_72 * V_72 )
{
F_64 ( & V_72 -> V_288 . V_289 ) ;
F_250 ( & V_72 -> V_288 . V_311 ) ;
if ( ! F_251 ( V_72 , L_9 , 0 , & V_471 ) )
return - V_89 ;
return 0 ;
}
static void T_12 F_252 ( struct V_72 * V_72 )
{
F_253 ( V_72 , L_9 ) ;
}
static void T_13 F_254 ( void )
{
F_255 ( & V_472 ) ;
F_256 ( & V_473 ) ;
F_257 ( V_304 ) ;
F_258 ( & V_305 ) ;
}
static int T_14 F_259 ( void )
{
int V_474 = F_260 ( & V_305 , 0 ) ;
if ( V_474 != 0 )
goto V_88;
F_261 ( & V_475 ) ;
F_262 ( & V_473 ) ;
F_263 ( & V_472 ) ;
V_88:
return V_474 ;
}
