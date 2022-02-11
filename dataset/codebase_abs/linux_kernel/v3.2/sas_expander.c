static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 , V_4 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) )
V_3 -> V_6 |= V_8 ;
F_3 ( & V_3 -> V_5 , V_4 ) ;
F_4 ( & V_3 -> V_9 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_6 ( & V_3 -> V_10 ) )
return;
F_4 ( & V_3 -> V_9 ) ;
}
static int F_7 ( struct V_11 * V_12 , void * V_13 , int V_14 ,
void * V_15 , int V_16 )
{
int V_17 , V_18 ;
struct V_2 * V_3 = NULL ;
struct V_19 * V_20 =
F_8 ( V_12 -> V_21 -> V_22 -> V_23 . V_24 -> V_25 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_3 = F_9 ( V_26 ) ;
if ( ! V_3 )
return - V_27 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_28 = V_12 -> V_29 ;
F_10 ( & V_3 -> V_30 . V_31 , V_13 , V_14 ) ;
F_10 ( & V_3 -> V_30 . V_32 , V_15 , V_16 ) ;
V_3 -> V_33 = F_5 ;
V_3 -> V_10 . V_34 = ( unsigned long ) V_3 ;
V_3 -> V_10 . V_35 = F_1 ;
V_3 -> V_10 . V_36 = V_37 + V_38 * V_39 ;
F_11 ( & V_3 -> V_10 ) ;
V_17 = V_20 -> V_40 -> V_41 ( V_3 , 1 , V_26 ) ;
if ( V_17 ) {
F_6 ( & V_3 -> V_10 ) ;
F_12 ( L_1 , V_17 ) ;
goto V_42;
}
F_13 ( & V_3 -> V_9 ) ;
V_17 = - V_43 ;
if ( ( V_3 -> V_6 & V_8 ) ) {
F_12 ( L_2 ) ;
V_20 -> V_40 -> V_44 ( V_3 ) ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_12 ( L_3 ) ;
goto V_42;
}
}
if ( V_3 -> V_45 . V_15 == V_46 &&
V_3 -> V_45 . V_47 == V_48 ) {
V_17 = 0 ;
break;
} if ( V_3 -> V_45 . V_15 == V_46 &&
V_3 -> V_45 . V_47 == V_49 ) {
V_17 = V_3 -> V_45 . V_50 ;
break;
} if ( V_3 -> V_45 . V_15 == V_46 &&
V_3 -> V_45 . V_47 == V_51 ) {
V_17 = - V_52 ;
break;
} else {
F_12 ( L_4
L_5 , V_53 ,
F_14 ( V_12 -> V_54 ) ,
V_3 -> V_45 . V_15 ,
V_3 -> V_45 . V_47 ) ;
F_15 ( V_3 ) ;
V_3 = NULL ;
}
}
V_42:
F_16 ( V_18 == 3 && V_3 != NULL ) ;
if ( V_3 != NULL ) {
F_15 ( V_3 ) ;
}
return V_17 ;
}
static inline void * F_17 ( int V_55 )
{
T_1 * V_56 = F_18 ( V_55 , V_26 ) ;
if ( V_56 )
V_56 [ 0 ] = V_57 ;
return V_56 ;
}
static inline void * F_19 ( int V_55 )
{
return F_18 ( V_55 , V_26 ) ;
}
static void F_20 ( struct V_11 * V_12 , int V_58 ,
void * V_59 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
struct V_32 * V_15 = V_59 ;
struct V_65 * V_66 = & V_15 -> V_67 ;
struct V_68 * V_69 = V_12 -> V_69 ;
int V_70 = ( V_64 -> V_64 != NULL ) ;
if ( ! V_70 ) {
V_64 -> V_64 = F_21 ( & V_69 -> V_12 , V_58 ) ;
F_16 ( ! V_64 -> V_64 ) ;
}
switch ( V_15 -> V_71 ) {
case V_72 :
V_64 -> V_73 = V_74 ;
break;
default:
V_64 -> V_73 = V_75 ;
break;
case V_76 :
V_64 -> V_73 = V_77 ;
break;
}
V_64 -> V_58 = V_58 ;
V_64 -> V_78 = V_66 -> V_78 ;
V_64 -> V_79 = V_66 -> V_79 ;
V_64 -> V_80 = V_66 -> V_80 ;
V_64 -> V_81 = V_66 -> V_81 ;
V_64 -> V_82 = V_66 -> V_82 ;
V_64 -> V_83 = V_66 -> V_84 << 1 ;
V_64 -> V_85 = V_66 -> V_29 << 1 ;
memcpy ( V_64 -> V_86 , V_66 -> V_86 , V_87 ) ;
V_64 -> V_88 = V_66 -> V_88 ;
V_64 -> V_89 = V_66 -> V_90 ;
V_64 -> V_91 = V_66 -> V_91 ;
V_64 -> V_92 = V_66 -> V_92 ;
V_64 -> V_93 = - 1 ;
V_64 -> V_64 -> V_94 . V_95 = F_14 ( V_64 -> V_86 ) ;
V_64 -> V_64 -> V_94 . V_96 = V_64 -> V_78 ;
V_64 -> V_64 -> V_94 . V_97 = V_64 -> V_83 ;
V_64 -> V_64 -> V_94 . V_98 = V_64 -> V_85 ;
V_64 -> V_64 -> V_94 . V_99 = V_58 ;
V_64 -> V_64 -> V_100 = V_66 -> V_101 ;
V_64 -> V_64 -> V_102 = V_66 -> V_103 ;
V_64 -> V_64 -> V_104 = V_66 -> V_105 ;
V_64 -> V_64 -> V_106 = V_66 -> V_107 ;
V_64 -> V_64 -> V_108 = V_64 -> V_79 ;
if ( ! V_70 )
if ( F_22 ( V_64 -> V_64 ) ) {
F_23 ( V_64 -> V_64 ) ;
return;
}
F_12 ( L_6 ,
F_14 ( V_12 -> V_54 ) , V_64 -> V_58 ,
V_64 -> V_91 == V_109 ? 'T' :
V_64 -> V_91 == V_110 ? 'D' :
V_64 -> V_91 == V_111 ? 'S' : '?' ,
F_14 ( V_64 -> V_86 ) ) ;
return;
}
static int F_24 ( struct V_11 * V_12 , T_1 * V_112 ,
T_1 * V_59 , int V_113 )
{
int V_20 , V_17 ;
V_112 [ 9 ] = V_113 ;
for ( V_20 = 1 ; V_20 < 3 ; V_20 ++ ) {
struct V_65 * V_66 ;
V_17 = F_7 ( V_12 , V_112 , V_114 ,
V_59 , V_115 ) ;
if ( V_17 )
return V_17 ;
V_66 = & ( (struct V_32 * ) V_59 ) -> V_67 ;
if ( memcmp ( V_12 -> V_54 , V_66 -> V_86 ,
V_87 ) == 0 ) {
F_25 ( L_7 ) ;
return 0 ;
}
if ( ! ( V_66 -> V_78 == 0 &&
V_66 -> V_81 ) )
break;
F_26 ( V_12 , V_113 , V_116 , NULL ) ;
F_27 ( 500 ) ;
}
F_20 ( V_12 , V_113 , V_59 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 , int V_113 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = 0 ;
T_1 * V_112 ;
T_1 * V_59 ;
V_112 = F_17 ( V_114 ) ;
if ( ! V_112 )
return - V_27 ;
V_59 = F_17 ( V_115 ) ;
if ( ! V_59 ) {
F_29 ( V_112 ) ;
return - V_27 ;
}
V_112 [ 1 ] = V_117 ;
if ( 0 <= V_113 && V_113 < V_61 -> V_118 ) {
V_17 = F_24 ( V_12 , V_112 , V_59 , V_113 ) ;
} else {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
V_17 = F_24 ( V_12 , V_112 ,
V_59 , V_20 ) ;
if ( V_17 )
goto V_119;
}
}
V_119:
F_29 ( V_59 ) ;
F_29 ( V_112 ) ;
return V_17 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = - V_27 ;
V_61 -> V_63 = F_18 ( sizeof( * V_61 -> V_63 ) * V_61 -> V_118 , V_26 ) ;
if ( ! V_61 -> V_63 )
return - V_27 ;
V_17 = F_28 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_119;
return 0 ;
V_119:
F_29 ( V_61 -> V_63 ) ;
V_61 -> V_63 = NULL ;
return V_17 ;
}
static void F_31 ( struct V_11 * V_12 ,
struct V_32 * V_15 )
{
struct V_120 * V_121 = & V_15 -> V_121 ;
V_12 -> V_62 . V_122 = F_32 ( V_121 -> V_90 ) ;
V_12 -> V_62 . V_123 = F_32 ( V_121 -> V_124 ) ;
V_12 -> V_62 . V_118 = F_33 ( V_121 -> V_118 , ( T_1 ) V_125 ) ;
V_12 -> V_62 . V_126 = V_121 -> V_126 ;
V_12 -> V_62 . V_127 = V_121 -> V_127 ;
V_12 -> V_62 . V_128 = V_121 -> V_128 ;
memcpy ( V_12 -> V_62 . V_129 , V_121 -> V_129 , 8 ) ;
}
static int F_34 ( struct V_11 * V_12 )
{
T_1 * V_130 ;
struct V_32 * V_131 ;
int V_17 ;
int V_20 ;
V_130 = F_17 ( V_132 ) ;
if ( ! V_130 )
return - V_27 ;
V_131 = F_19 ( V_133 ) ;
if ( ! V_131 ) {
F_29 ( V_130 ) ;
return - V_27 ;
}
V_130 [ 1 ] = V_134 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_17 = F_7 ( V_12 , V_130 , V_132 , V_131 ,
V_133 ) ;
if ( V_17 ) {
F_12 ( L_8 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_135;
} else if ( V_131 -> V_71 != V_76 ) {
F_12 ( L_9 ,
F_14 ( V_12 -> V_54 ) , V_131 -> V_71 ) ;
V_17 = V_131 -> V_71 ;
goto V_135;
}
F_31 ( V_12 , V_131 ) ;
if ( V_12 -> V_62 . V_128 ) {
F_12 ( L_10 ,
F_14 ( V_12 -> V_54 ) ) ;
F_35 ( 5 * V_39 ) ;
} else
break;
}
V_135:
F_29 ( V_130 ) ;
F_29 ( V_131 ) ;
return V_17 ;
}
static void F_36 ( struct V_11 * V_12 , void
* V_136 )
{
T_1 * V_137 = V_136 ;
struct V_68 * V_69 = V_12 -> V_69 ;
struct V_138 * V_139 = F_37 ( V_69 ) ;
memcpy ( V_139 -> V_140 , V_137 + 12 , V_141 ) ;
memcpy ( V_139 -> V_142 , V_137 + 20 , V_143 ) ;
memcpy ( V_139 -> V_144 , V_137 + 36 ,
V_145 ) ;
if ( V_137 [ 8 ] & 1 ) {
memcpy ( V_139 -> V_146 , V_137 + 40 ,
V_147 ) ;
V_139 -> V_148 = V_137 [ 48 ] << 8 | V_137 [ 49 ] ;
V_139 -> V_149 = V_137 [ 50 ] ;
}
}
static int F_38 ( struct V_11 * V_12 )
{
T_1 * V_150 ;
T_1 * V_137 ;
int V_17 ;
V_150 = F_17 ( V_151 ) ;
if ( ! V_150 )
return - V_27 ;
V_137 = F_19 ( V_152 ) ;
if ( ! V_137 ) {
F_29 ( V_150 ) ;
return - V_27 ;
}
V_150 [ 1 ] = V_153 ;
V_17 = F_7 ( V_12 , V_150 , V_151 , V_137 , V_152 ) ;
if ( V_17 ) {
F_12 ( L_11 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_135;
} else if ( V_137 [ 2 ] != V_76 ) {
F_12 ( L_12 ,
F_14 ( V_12 -> V_54 ) , V_137 [ 2 ] ) ;
goto V_135;
}
F_36 ( V_12 , V_137 ) ;
V_135:
F_29 ( V_150 ) ;
F_29 ( V_137 ) ;
return V_17 ;
}
int F_26 ( struct V_11 * V_12 , int V_58 ,
enum V_154 V_154 ,
struct V_155 * V_156 )
{
T_1 * V_157 ;
T_1 * V_158 ;
int V_17 ;
V_157 = F_17 ( V_159 ) ;
if ( ! V_157 )
return - V_27 ;
V_158 = F_19 ( V_160 ) ;
if ( ! V_158 ) {
F_29 ( V_157 ) ;
return - V_27 ;
}
V_157 [ 1 ] = V_161 ;
V_157 [ 9 ] = V_58 ;
V_157 [ 10 ] = V_154 ;
if ( V_156 ) {
V_157 [ 32 ] = V_156 -> V_104 << 4 ;
V_157 [ 33 ] = V_156 -> V_106 << 4 ;
}
V_17 = F_7 ( V_12 , V_157 , V_159 , V_158 , V_160 ) ;
F_29 ( V_158 ) ;
F_29 ( V_157 ) ;
return V_17 ;
}
static void F_39 ( struct V_11 * V_12 , int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
F_26 ( V_12 , V_58 , V_162 , NULL ) ;
V_64 -> V_79 = V_163 ;
}
static void F_40 ( struct V_11 * V_12 , T_1 * V_54 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( F_14 ( V_64 -> V_86 ) == F_14 ( V_54 ) )
F_39 ( V_12 , V_20 ) ;
}
}
static int F_41 ( struct V_164 * V_21 ,
T_1 * V_54 )
{
struct V_11 * V_12 ;
if ( F_14 ( V_21 -> V_54 ) == F_14 ( V_54 ) )
return 1 ;
F_42 (dev, &port->dev_list, dev_list_node) {
if ( F_14 ( V_12 -> V_54 ) == F_14 ( V_54 ) )
return 1 ;
}
return 0 ;
}
int F_43 ( struct V_165 * V_64 )
{
int V_17 ;
T_1 * V_13 ;
T_1 * V_15 ;
struct V_68 * V_69 = F_44 ( V_64 -> V_12 . V_166 ) ;
struct V_11 * V_12 = F_45 ( V_69 ) ;
V_13 = F_17 ( V_167 ) ;
if ( ! V_13 )
return - V_27 ;
V_15 = F_19 ( V_168 ) ;
if ( ! V_15 ) {
F_29 ( V_13 ) ;
return - V_27 ;
}
V_13 [ 1 ] = V_169 ;
V_13 [ 9 ] = V_64 -> V_170 ;
V_17 = F_7 ( V_12 , V_13 , V_167 ,
V_15 , V_168 ) ;
if ( ! V_17 )
goto V_135;
V_64 -> V_171 = F_46 ( & V_15 [ 12 ] ) ;
V_64 -> V_172 = F_46 ( & V_15 [ 16 ] ) ;
V_64 -> V_173 = F_46 ( & V_15 [ 20 ] ) ;
V_64 -> V_174 = F_46 ( & V_15 [ 24 ] ) ;
V_135:
F_29 ( V_15 ) ;
return V_17 ;
}
static int F_47 ( struct V_11 * V_12 ,
int V_58 ,
struct V_32 * V_175 )
{
int V_17 ;
T_1 * V_176 = F_17 ( V_177 ) ;
T_1 * V_15 = ( T_1 * ) V_175 ;
if ( ! V_176 )
return - V_27 ;
V_176 [ 1 ] = V_178 ;
V_176 [ 9 ] = V_58 ;
V_17 = F_7 ( V_12 , V_176 , V_177 ,
V_175 , V_179 ) ;
if ( ! V_17 && V_15 [ 27 ] == 0x34 && V_15 [ 24 ] != 0x34 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
int V_180 = 24 + ( V_20 * 4 ) ;
T_1 V_181 , V_182 ;
V_181 = V_15 [ V_180 + 0 ] ;
V_182 = V_15 [ V_180 + 1 ] ;
V_15 [ V_180 + 0 ] = V_15 [ V_180 + 3 ] ;
V_15 [ V_180 + 1 ] = V_15 [ V_180 + 2 ] ;
V_15 [ V_180 + 2 ] = V_182 ;
V_15 [ V_180 + 3 ] = V_181 ;
}
}
F_29 ( V_176 ) ;
return V_17 ;
}
static void F_48 ( struct V_11 * V_166 ,
struct V_11 * V_183 ,
struct V_63 * V_184 )
{
struct V_60 * V_185 = & V_166 -> V_62 ;
struct V_186 * V_21 ;
int V_20 ;
V_183 -> V_187 = 0 ;
V_21 = V_184 -> V_21 ;
for ( V_20 = 0 ; V_20 < V_185 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_185 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_183 -> V_54 ) ) {
V_183 -> V_188 = F_33 ( V_166 -> V_188 ,
V_64 -> V_79 ) ;
V_183 -> V_189 = F_49 ( V_166 -> V_189 ,
V_64 -> V_79 ) ;
V_183 -> V_187 ++ ;
F_50 ( V_21 , V_64 -> V_64 ) ;
}
}
V_183 -> V_79 = F_33 ( V_184 -> V_79 , V_183 -> V_189 ) ;
V_183 -> V_187 = F_33 ( V_183 -> V_187 , V_166 -> V_187 ) ;
}
static struct V_11 * F_51 (
struct V_11 * V_166 , int V_58 )
{
struct V_60 * V_185 = & V_166 -> V_62 ;
struct V_63 * V_64 = & V_185 -> V_63 [ V_58 ] ;
struct V_11 * V_183 = NULL ;
struct V_68 * V_69 ;
int V_17 ;
if ( V_64 -> V_80 || V_64 -> V_82 )
return NULL ;
V_183 = F_18 ( sizeof( * V_183 ) , V_26 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_166 = V_166 ;
V_183 -> V_21 = V_166 -> V_21 ;
V_183 -> V_84 = V_64 -> V_83 ;
memcpy ( V_183 -> V_54 , V_64 -> V_86 , V_87 ) ;
F_52 ( V_183 -> V_190 , V_183 -> V_54 ) ;
if ( ! V_64 -> V_21 ) {
V_64 -> V_21 = F_53 ( & V_166 -> V_69 -> V_12 , V_58 ) ;
if ( F_54 ( ! V_64 -> V_21 ) )
goto V_119;
if ( F_54 ( F_55 ( V_64 -> V_21 ) != 0 ) ) {
F_56 ( V_64 -> V_21 ) ;
goto V_119;
}
}
F_48 ( V_166 , V_183 , V_64 ) ;
#ifdef F_57
if ( ( V_64 -> V_85 & V_191 ) || V_64 -> V_81 ) {
V_183 -> V_192 = V_193 ;
if ( V_64 -> V_85 & V_191 )
V_183 -> V_29 = V_64 -> V_85 ;
if ( V_64 -> V_81 )
V_183 -> V_29 |= V_193 ;
V_17 = F_47 ( V_166 , V_58 ,
& V_183 -> V_194 . V_175 ) ;
if ( V_17 ) {
F_12 ( L_13
L_14 , F_14 ( V_166 -> V_54 ) ,
V_58 , V_17 ) ;
goto V_195;
}
memcpy ( V_183 -> V_196 , & V_183 -> V_194 . V_175 . V_197 . V_198 ,
sizeof( struct V_199 ) ) ;
V_69 = F_58 ( V_64 -> V_21 ) ;
if ( F_54 ( ! V_69 ) )
goto V_195;
F_59 ( V_183 ) ;
V_183 -> V_69 = V_69 ;
F_60 ( & V_166 -> V_21 -> V_200 ) ;
F_61 ( & V_183 -> V_201 , & V_166 -> V_21 -> V_202 ) ;
F_62 ( & V_166 -> V_21 -> V_200 ) ;
V_17 = F_63 ( V_183 ) ;
if ( V_17 ) {
F_12 ( L_15
L_16 ,
F_14 ( V_183 -> V_54 ) ,
F_14 ( V_166 -> V_54 ) , V_58 , V_17 ) ;
goto V_203;
}
} else
#endif
if ( V_64 -> V_85 & V_204 ) {
V_183 -> V_192 = V_205 ;
V_69 = F_58 ( V_64 -> V_21 ) ;
if ( F_54 ( ! V_69 ) )
goto V_195;
V_183 -> V_29 = V_64 -> V_85 ;
F_59 ( V_183 ) ;
V_183 -> V_69 = V_69 ;
F_64 ( V_183 , V_69 ) ;
F_60 ( & V_166 -> V_21 -> V_200 ) ;
F_61 ( & V_183 -> V_201 , & V_166 -> V_21 -> V_202 ) ;
F_62 ( & V_166 -> V_21 -> V_200 ) ;
V_17 = F_65 ( V_183 ) ;
if ( V_17 ) {
F_12 ( L_17
L_18 ,
F_14 ( V_183 -> V_54 ) ,
F_14 ( V_166 -> V_54 ) , V_58 , V_17 ) ;
goto V_203;
}
} else {
F_12 ( L_19 ,
V_64 -> V_85 , F_14 ( V_166 -> V_54 ) ,
V_58 ) ;
goto V_195;
}
F_61 ( & V_183 -> V_206 , & V_185 -> V_207 ) ;
return V_183 ;
V_203:
F_66 ( V_183 -> V_69 ) ;
V_183 -> V_69 = NULL ;
F_60 ( & V_166 -> V_21 -> V_200 ) ;
F_67 ( & V_183 -> V_201 ) ;
F_62 ( & V_166 -> V_21 -> V_200 ) ;
V_195:
F_68 ( V_64 -> V_21 ) ;
V_119:
V_64 -> V_21 = NULL ;
F_29 ( V_183 ) ;
return NULL ;
}
static int F_69 ( struct V_11 * V_166 , int V_58 )
{
struct V_63 * V_64 = & V_166 -> V_62 . V_63 [ V_58 ] ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_166 -> V_62 . V_118 ; V_20 ++ ) {
struct V_63 * V_208 = & V_166 -> V_62 . V_63 [ V_20 ] ;
if ( V_208 == V_64 )
continue;
if ( ! memcmp ( V_64 -> V_86 , V_208 -> V_86 ,
V_87 ) && V_208 -> V_21 ) {
F_50 ( V_208 -> V_21 , V_64 -> V_64 ) ;
V_64 -> V_21 = V_208 -> V_21 ;
V_64 -> V_73 = V_209 ;
return 0 ;
}
}
return - V_210 ;
}
static struct V_11 * F_70 (
struct V_11 * V_166 , int V_58 )
{
struct V_138 * V_185 = F_37 ( V_166 -> V_69 ) ;
struct V_63 * V_64 = & V_166 -> V_62 . V_63 [ V_58 ] ;
struct V_11 * V_183 = NULL ;
struct V_68 * V_69 ;
struct V_138 * V_139 ;
struct V_164 * V_21 ;
int V_17 ;
if ( V_64 -> V_91 == V_110 ) {
F_12 ( L_20
L_21 ,
F_14 ( V_166 -> V_54 ) , V_58 ,
F_14 ( V_64 -> V_86 ) ,
V_64 -> V_88 ) ;
return NULL ;
}
V_183 = F_18 ( sizeof( * V_183 ) , V_26 ) ;
if ( ! V_183 )
return NULL ;
V_64 -> V_21 = F_53 ( & V_166 -> V_69 -> V_12 , V_58 ) ;
F_16 ( F_55 ( V_64 -> V_21 ) != 0 ) ;
switch ( V_64 -> V_78 ) {
case V_211 :
V_69 = F_71 ( V_64 -> V_21 ,
V_212 ) ;
break;
case V_213 :
V_69 = F_71 ( V_64 -> V_21 ,
V_214 ) ;
break;
default:
V_69 = NULL ;
F_72 () ;
}
V_21 = V_166 -> V_21 ;
V_183 -> V_69 = V_69 ;
V_139 = F_37 ( V_69 ) ;
V_183 -> V_192 = V_64 -> V_78 ;
V_183 -> V_166 = V_166 ;
V_183 -> V_21 = V_21 ;
V_183 -> V_84 = V_64 -> V_83 ;
V_183 -> V_29 = V_64 -> V_85 ;
memcpy ( V_183 -> V_54 , V_64 -> V_86 , V_87 ) ;
F_52 ( V_183 -> V_190 , V_183 -> V_54 ) ;
F_48 ( V_166 , V_183 , V_64 ) ;
V_139 -> V_215 = V_185 -> V_215 + 1 ;
V_166 -> V_21 -> V_67 . V_216 = F_49 ( V_166 -> V_21 -> V_67 . V_216 ,
V_139 -> V_215 ) ;
F_59 ( V_183 ) ;
F_64 ( V_183 , V_69 ) ;
F_73 ( V_69 ) ;
F_60 ( & V_166 -> V_21 -> V_200 ) ;
F_61 ( & V_183 -> V_201 , & V_166 -> V_21 -> V_202 ) ;
F_62 ( & V_166 -> V_21 -> V_200 ) ;
V_17 = F_74 ( V_183 ) ;
if ( V_17 ) {
F_60 ( & V_166 -> V_21 -> V_200 ) ;
F_67 ( & V_183 -> V_201 ) ;
F_62 ( & V_166 -> V_21 -> V_200 ) ;
F_29 ( V_183 ) ;
return NULL ;
}
F_61 ( & V_183 -> V_206 , & V_166 -> V_62 . V_207 ) ;
return V_183 ;
}
static int F_75 ( struct V_11 * V_12 , int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_63 = & V_61 -> V_63 [ V_58 ] ;
struct V_11 * V_183 = NULL ;
int V_17 = 0 ;
if ( V_63 -> V_79 == V_217 ) {
if ( ! F_26 ( V_12 , V_58 , V_116 , NULL ) )
V_17 = F_28 ( V_12 , V_58 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_12 -> V_166 && ( F_14 ( V_63 -> V_86 ) ==
F_14 ( V_12 -> V_21 -> V_54 ) ) ) {
F_76 ( V_12 , V_58 ) ;
return 0 ;
}
if ( V_12 -> V_166 && ( F_14 ( V_63 -> V_86 ) ==
F_14 ( V_12 -> V_166 -> V_54 ) ) ) {
F_76 ( V_12 , V_58 ) ;
if ( V_63 -> V_91 == V_109 )
F_77 ( V_12 , V_58 , V_12 -> V_21 -> V_54 , 1 ) ;
return 0 ;
}
if ( F_41 ( V_12 -> V_21 , V_63 -> V_86 ) )
F_40 ( V_12 , V_63 -> V_86 ) ;
if ( V_63 -> V_78 == V_218 ) {
if ( V_63 -> V_91 == V_110 ) {
memset ( V_63 -> V_86 , 0 , V_87 ) ;
F_78 ( V_12 , V_63 -> V_86 ) ;
}
return 0 ;
} else if ( V_63 -> V_79 == V_219 )
return 0 ;
if ( V_63 -> V_78 != V_205 &&
V_63 -> V_78 != V_213 &&
V_63 -> V_78 != V_211 ) {
F_12 ( L_22
L_23 , V_63 -> V_78 ,
F_14 ( V_12 -> V_54 ) ,
V_58 ) ;
return 0 ;
}
V_17 = F_78 ( V_12 , V_63 -> V_86 ) ;
if ( V_17 ) {
F_12 ( L_24
L_25 ,
F_14 ( V_63 -> V_86 ) , V_17 ) ;
F_79 ( V_12 , V_63 -> V_86 ) ;
return V_17 ;
}
V_17 = F_69 ( V_12 , V_58 ) ;
if ( ! V_17 ) {
F_12 ( L_26 ,
V_58 , F_14 ( V_63 -> V_86 ) ) ;
return V_17 ;
}
switch ( V_63 -> V_78 ) {
case V_205 :
V_183 = F_51 ( V_12 , V_58 ) ;
break;
case V_213 :
if ( F_14 ( V_12 -> V_21 -> V_67 . V_220 ) ) {
F_12 ( L_27
L_28 ,
F_14 ( V_63 -> V_86 ) ,
V_63 -> V_88 ,
F_14 ( V_12 -> V_54 ) ,
V_58 ) ;
F_39 ( V_12 , V_58 ) ;
break;
} else
memcpy ( V_12 -> V_21 -> V_67 . V_220 ,
V_63 -> V_86 , V_87 ) ;
case V_211 :
V_183 = F_70 ( V_12 , V_58 ) ;
break;
default:
break;
}
if ( V_183 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
if ( V_61 -> V_63 [ V_20 ] . V_73 == V_74 ||
V_61 -> V_63 [ V_20 ] . V_73 == V_75 )
continue;
if ( F_14 ( V_61 -> V_63 [ V_20 ] . V_86 ) ==
F_14 ( V_183 -> V_54 ) ) {
V_61 -> V_63 [ V_20 ] . V_73 = V_209 ;
V_17 = F_69 ( V_12 , V_20 ) ;
if ( ! V_17 )
F_12 ( L_26 ,
V_20 , F_14 ( V_61 -> V_63 [ V_20 ] . V_86 ) ) ;
}
}
}
return V_17 ;
}
static int F_80 ( struct V_11 * V_12 , T_1 * V_221 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( ( V_64 -> V_78 == V_211 ||
V_64 -> V_78 == V_213 ) &&
V_64 -> V_91 == V_111 ) {
memcpy ( V_221 , V_64 -> V_86 , V_87 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_81 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_11 * V_183 ;
T_1 V_221 [ 8 ] = { 0 , } ;
F_42 (child, &ex->children, siblings) {
if ( V_183 -> V_192 != V_211 &&
V_183 -> V_192 != V_213 )
continue;
if ( V_221 [ 0 ] == 0 ) {
F_80 ( V_183 , V_221 ) ;
continue;
} else {
T_1 V_222 [ 8 ] ;
if ( F_80 ( V_183 , V_222 ) &&
( F_14 ( V_221 ) != F_14 ( V_222 ) ) ) {
F_12 ( L_29
L_30
L_31 ,
F_14 ( V_12 -> V_54 ) ,
F_14 ( V_183 -> V_54 ) ,
F_14 ( V_222 ) ,
F_14 ( V_221 ) ) ;
F_40 ( V_183 , V_222 ) ;
}
}
}
return 0 ;
}
static int F_82 ( struct V_11 * V_12 , int V_113 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 = 0 , V_223 = V_61 -> V_118 ;
int V_17 = 0 ;
if ( 0 <= V_113 && V_113 < V_223 ) {
V_20 = V_113 ;
V_223 = V_20 + 1 ;
}
for ( ; V_20 < V_223 ; V_20 ++ ) {
struct V_63 * V_63 = & V_61 -> V_63 [ V_20 ] ;
if ( V_63 -> V_73 == V_74 ||
V_63 -> V_73 == V_75 ||
V_63 -> V_73 == V_209 )
continue;
switch ( V_63 -> V_79 ) {
case V_163 :
case V_224 :
case V_225 :
continue;
default:
V_17 = F_75 ( V_12 , V_20 ) ;
if ( V_17 )
break;
continue;
}
}
if ( ! V_17 )
F_81 ( V_12 ) ;
return V_17 ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 ;
T_1 * V_226 = NULL ;
if ( V_12 -> V_192 != V_211 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( ( V_64 -> V_78 == V_213 ||
V_64 -> V_78 == V_211 ) &&
V_64 -> V_91 == V_111 ) {
if ( ! V_226 )
V_226 = & V_64 -> V_86 [ 0 ] ;
else if ( F_14 ( V_226 ) !=
F_14 ( V_64 -> V_86 ) ) {
F_12 ( L_32
L_33
L_34 ,
F_14 ( V_12 -> V_54 ) , V_20 ,
F_14 ( V_64 -> V_86 ) ,
F_14 ( V_226 ) ) ;
F_39 ( V_12 , V_20 ) ;
}
}
}
return 0 ;
}
static void F_84 ( struct V_11 * V_183 ,
struct V_63 * V_184 ,
struct V_63 * V_227 )
{
static const char V_228 [] = {
[ V_110 ] = 'D' ,
[ V_111 ] = 'S' ,
[ V_109 ] = 'T' ,
} ;
static const char * V_229 [] = {
[ V_211 ] = L_35 ,
[ V_213 ] = L_36 ,
} ;
struct V_11 * V_166 = V_183 -> V_166 ;
F_25 ( L_37
L_38 ,
V_229 [ V_166 -> V_192 ] ,
F_14 ( V_166 -> V_54 ) ,
V_166 -> V_62 . V_126 ,
V_184 -> V_58 ,
V_229 [ V_183 -> V_192 ] ,
F_14 ( V_183 -> V_54 ) ,
V_183 -> V_62 . V_126 ,
V_227 -> V_58 ,
V_228 [ V_184 -> V_91 ] ,
V_228 [ V_227 -> V_91 ] ) ;
}
static int F_85 ( struct V_11 * V_183 ,
struct V_63 * V_184 ,
struct V_63 * V_227 )
{
int V_17 = 0 ;
struct V_11 * V_166 = V_183 -> V_166 ;
if ( F_14 ( V_166 -> V_21 -> V_67 . V_220 ) != 0 ) {
V_17 = - V_210 ;
F_12 ( L_39
L_40 ,
F_14 ( V_166 -> V_54 ) ,
V_184 -> V_58 ,
F_14 ( V_183 -> V_54 ) ,
V_227 -> V_58 ,
F_14 ( V_166 -> V_21 -> V_67 . V_220 ) ) ;
} else if ( F_14 ( V_166 -> V_21 -> V_67 . V_230 ) == 0 ) {
memcpy ( V_166 -> V_21 -> V_67 . V_230 , V_166 -> V_54 ,
V_87 ) ;
memcpy ( V_166 -> V_21 -> V_67 . V_231 , V_183 -> V_54 ,
V_87 ) ;
} else if ( ( ( F_14 ( V_166 -> V_21 -> V_67 . V_230 ) ==
F_14 ( V_166 -> V_54 ) ) ||
( F_14 ( V_166 -> V_21 -> V_67 . V_230 ) ==
F_14 ( V_183 -> V_54 ) ) )
&&
( ( F_14 ( V_166 -> V_21 -> V_67 . V_231 ) ==
F_14 ( V_166 -> V_54 ) ) ||
( F_14 ( V_166 -> V_21 -> V_67 . V_231 ) ==
F_14 ( V_183 -> V_54 ) ) ) )
;
else {
V_17 = - V_210 ;
F_12 ( L_41
L_42 ,
F_14 ( V_166 -> V_54 ) ,
V_184 -> V_58 ,
F_14 ( V_183 -> V_54 ) ,
V_227 -> V_58 ) ;
}
return V_17 ;
}
static int F_86 ( struct V_11 * V_183 )
{
struct V_60 * V_232 = & V_183 -> V_62 ;
struct V_60 * V_185 ;
int V_20 ;
int V_17 = 0 ;
if ( ! V_183 -> V_166 )
return 0 ;
if ( V_183 -> V_166 -> V_192 != V_211 &&
V_183 -> V_166 -> V_192 != V_213 )
return 0 ;
V_185 = & V_183 -> V_166 -> V_62 ;
for ( V_20 = 0 ; V_20 < V_185 -> V_118 ; V_20 ++ ) {
struct V_63 * V_184 = & V_185 -> V_63 [ V_20 ] ;
struct V_63 * V_227 ;
if ( V_184 -> V_73 == V_74 ||
V_184 -> V_73 == V_75 )
continue;
if ( F_14 ( V_184 -> V_86 ) != F_14 ( V_183 -> V_54 ) )
continue;
V_227 = & V_232 -> V_63 [ V_184 -> V_88 ] ;
switch ( V_183 -> V_166 -> V_192 ) {
case V_211 :
if ( V_183 -> V_192 == V_213 ) {
if ( V_184 -> V_91 != V_111 ||
V_227 -> V_91 != V_109 ) {
F_84 ( V_183 , V_184 , V_227 ) ;
V_17 = - V_210 ;
}
} else if ( V_184 -> V_91 == V_111 ) {
if ( V_227 -> V_91 == V_111 ) {
V_17 = F_85 ( V_183 , V_184 , V_227 ) ;
} else if ( V_227 -> V_91 != V_109 ) {
F_84 ( V_183 , V_184 , V_227 ) ;
V_17 = - V_210 ;
}
} else if ( V_184 -> V_91 == V_109 ) {
if ( V_227 -> V_91 == V_111 ||
( V_227 -> V_91 == V_109 &&
V_232 -> V_126 && V_185 -> V_126 ) ) {
;
} else {
F_84 ( V_183 , V_184 , V_227 ) ;
V_17 = - V_210 ;
}
}
break;
case V_213 :
if ( V_184 -> V_91 != V_109 ||
V_227 -> V_91 != V_111 ) {
F_84 ( V_183 , V_184 , V_227 ) ;
V_17 = - V_210 ;
}
break;
default:
break;
}
}
return V_17 ;
}
static int F_87 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int * V_233 , int * V_234 )
{
int V_20 , V_17 = 0 ;
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
T_1 * V_235 ;
T_1 * V_236 ;
* V_234 = 0 ;
* V_233 = 0 ;
V_235 = F_17 ( V_237 ) ;
if ( ! V_235 )
return - V_27 ;
V_236 = F_19 ( V_238 ) ;
if ( ! V_236 ) {
F_29 ( V_235 ) ;
return - V_27 ;
}
V_235 [ 1 ] = V_239 ;
V_235 [ 9 ] = V_58 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_123 ; V_20 ++ ) {
* ( V_240 * ) ( V_235 + 6 ) = F_88 ( V_20 ) ;
V_17 = F_7 ( V_12 , V_235 , V_237 , V_236 ,
V_238 ) ;
if ( V_17 )
goto V_135;
V_17 = V_236 [ 2 ] ;
if ( V_17 == V_241 ) {
F_12 ( L_43
L_44 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_20 ) ;
goto V_135;
} else if ( V_17 != V_76 ) {
F_12 ( L_45
L_46 , V_53 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_20 , V_17 ) ;
goto V_135;
}
if ( F_14 ( V_54 ) != 0 ) {
if ( F_14 ( V_236 + 16 ) == F_14 ( V_54 ) ) {
* V_233 = V_20 ;
if ( ( V_236 [ 12 ] & 0x80 ) == 0x80 )
* V_234 = 0 ;
else
* V_234 = 1 ;
goto V_135;
} else if ( F_14 ( V_236 + 16 ) == 0 ) {
* V_233 = V_20 ;
* V_234 = 0 ;
goto V_135;
}
} else if ( F_14 ( V_236 + 16 ) == 0 &&
V_64 -> V_93 < V_20 ) {
V_64 -> V_93 = V_20 ;
* V_233 = V_20 ;
* V_234 = 0 ;
goto V_135;
}
}
V_17 = - 1 ;
V_135:
F_29 ( V_235 ) ;
F_29 ( V_236 ) ;
return V_17 ;
}
static int F_89 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int V_233 , int include )
{
int V_17 ;
T_1 * V_242 ;
T_1 * V_243 ;
V_242 = F_17 ( V_244 ) ;
if ( ! V_242 )
return - V_27 ;
V_243 = F_19 ( V_245 ) ;
if ( ! V_243 ) {
F_29 ( V_242 ) ;
return - V_27 ;
}
V_242 [ 1 ] = V_246 ;
* ( V_240 * ) ( V_242 + 6 ) = F_88 ( V_233 ) ;
V_242 [ 9 ] = V_58 ;
if ( F_14 ( V_54 ) == 0 || ! include )
V_242 [ 12 ] |= 0x80 ;
memcpy ( V_242 + 16 , V_54 , V_87 ) ;
V_17 = F_7 ( V_12 , V_242 , V_244 , V_243 ,
V_245 ) ;
if ( V_17 )
goto V_135;
V_17 = V_243 [ 2 ] ;
if ( V_17 == V_241 ) {
F_12 ( L_47
L_48 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_233 ) ;
}
V_135:
F_29 ( V_242 ) ;
F_29 ( V_243 ) ;
return V_17 ;
}
static int F_77 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int include )
{
int V_233 ;
int V_234 ;
int V_17 ;
V_17 = F_87 ( V_12 , V_58 , V_54 , & V_233 , & V_234 ) ;
if ( V_17 )
return V_17 ;
if ( include ^ V_234 )
return F_89 ( V_12 , V_58 , V_54 , V_233 , include ) ;
return V_17 ;
}
static int F_90 ( struct V_11 * V_166 ,
struct V_11 * V_183 ,
T_1 * V_54 , int include )
{
struct V_60 * V_247 = & V_166 -> V_62 ;
int V_17 = 0 ;
int V_20 ;
if ( V_166 -> V_166 ) {
V_17 = F_90 ( V_166 -> V_166 , V_166 , V_54 ,
include ) ;
if ( V_17 )
return V_17 ;
}
if ( V_247 -> V_127 == 0 ) {
F_12 ( L_49 ,
F_14 ( V_166 -> V_54 ) ) ;
return 0 ;
}
for ( V_20 = 0 ; V_20 < V_247 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_247 -> V_63 [ V_20 ] ;
if ( ( V_64 -> V_91 == V_109 ) &&
( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_183 -> V_54 ) ) ) {
V_17 = F_77 ( V_166 , V_20 , V_54 , include ) ;
if ( V_17 )
return V_17 ;
}
}
return V_17 ;
}
static int F_78 ( struct V_11 * V_12 , T_1 * V_54 )
{
if ( V_12 -> V_166 )
return F_90 ( V_12 -> V_166 , V_12 , V_54 , 1 ) ;
return 0 ;
}
static int F_79 ( struct V_11 * V_12 , T_1 * V_54 )
{
if ( V_12 -> V_166 )
return F_90 ( V_12 -> V_166 , V_12 , V_54 , 0 ) ;
return 0 ;
}
static int F_74 ( struct V_11 * V_12 )
{
int V_17 ;
V_17 = F_91 ( V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_34 ( V_12 ) ;
if ( V_17 )
goto V_119;
V_17 = F_38 ( V_12 ) ;
if ( V_17 )
goto V_119;
V_17 = F_30 ( V_12 ) ;
if ( V_17 ) {
F_12 ( L_50 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_119;
}
F_83 ( V_12 ) ;
V_17 = F_86 ( V_12 ) ;
if ( V_17 )
goto V_119;
return 0 ;
V_119:
F_92 ( V_12 ) ;
return V_17 ;
}
static int F_93 ( struct V_164 * V_21 , const int V_215 )
{
int V_17 = 0 ;
struct V_11 * V_12 ;
F_42 (dev, &port->dev_list, dev_list_node) {
if ( V_12 -> V_192 == V_211 ||
V_12 -> V_192 == V_213 ) {
struct V_138 * V_61 =
F_37 ( V_12 -> V_69 ) ;
if ( V_215 == V_61 -> V_215 )
V_17 = F_82 ( V_12 , - 1 ) ;
else if ( V_215 > 0 )
V_17 = F_82 ( V_21 -> V_248 , - 1 ) ;
}
}
return V_17 ;
}
static int F_94 ( struct V_164 * V_21 )
{
int V_17 ;
int V_215 ;
do {
V_215 = V_21 -> V_67 . V_216 ;
V_17 = F_93 ( V_21 , V_215 ) ;
F_95 () ;
} while ( V_215 < V_21 -> V_67 . V_216 );
return V_17 ;
}
int F_96 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_138 * V_61 = F_37 ( V_12 -> V_69 ) ;
V_17 = F_73 ( V_12 -> V_69 ) ;
if ( V_17 )
goto V_119;
V_61 -> V_215 = V_12 -> V_21 -> V_67 . V_216 ;
V_17 = F_74 ( V_12 ) ;
if ( V_17 )
goto V_249;
F_94 ( V_12 -> V_21 ) ;
return V_17 ;
V_249:
F_97 ( V_12 -> V_69 ) ;
V_119:
return V_17 ;
}
static int F_98 ( struct V_11 * V_12 ,
int V_58 , struct V_32 * V_59 )
{
int V_17 ;
T_1 * V_112 ;
V_112 = F_17 ( V_114 ) ;
if ( ! V_112 )
return - V_27 ;
V_112 [ 1 ] = V_117 ;
V_112 [ 9 ] = V_58 ;
V_17 = F_7 ( V_12 , V_112 , V_114 ,
V_59 , V_115 ) ;
if ( V_17 )
goto V_135;
else if ( V_59 -> V_71 != V_76 ) {
V_17 = V_59 -> V_71 ;
goto V_135;
}
V_135:
F_29 ( V_112 ) ;
return V_17 ;
}
static int F_99 ( struct V_11 * V_12 ,
int V_58 , int * V_250 )
{
int V_17 ;
struct V_32 * V_59 ;
V_59 = F_19 ( V_115 ) ;
if ( ! V_59 )
return - V_27 ;
V_17 = F_98 ( V_12 , V_58 , V_59 ) ;
if ( ! V_17 )
* V_250 = V_59 -> V_67 . V_90 ;
F_29 ( V_59 ) ;
return V_17 ;
}
static int F_100 ( struct V_11 * V_12 ,
int V_58 , T_1 * V_86 )
{
int V_17 ;
struct V_32 * V_59 ;
struct V_65 * V_66 ;
V_59 = F_19 ( V_115 ) ;
if ( ! V_59 )
return - V_27 ;
V_66 = & V_59 -> V_67 ;
V_17 = F_98 ( V_12 , V_58 , V_59 ) ;
if ( ! V_17 ) {
memcpy ( V_86 , V_59 -> V_67 . V_86 , 8 ) ;
if ( V_66 -> V_78 == 0 )
memset ( V_86 , 0 , 8 ) ;
}
F_29 ( V_59 ) ;
return V_17 ;
}
static int F_101 ( struct V_11 * V_12 , int * V_58 ,
int V_251 , bool V_252 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = 0 ;
int V_20 ;
for ( V_20 = V_251 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
int V_89 = 0 ;
V_17 = F_99 ( V_12 , V_20 , & V_89 ) ;
if ( V_17 )
goto V_135;
else if ( V_89 != V_61 -> V_63 [ V_20 ] . V_89 ) {
if ( V_252 )
V_61 -> V_63 [ V_20 ] . V_89 =
V_89 ;
* V_58 = V_20 ;
return 0 ;
}
}
V_135:
return V_17 ;
}
static int F_102 ( struct V_11 * V_12 , int * V_253 )
{
int V_17 ;
T_1 * V_130 ;
struct V_32 * V_131 ;
V_130 = F_17 ( V_132 ) ;
if ( ! V_130 )
return - V_27 ;
V_131 = F_19 ( V_133 ) ;
if ( ! V_131 ) {
F_29 ( V_130 ) ;
return - V_27 ;
}
V_130 [ 1 ] = V_134 ;
V_17 = F_7 ( V_12 , V_130 , V_132 , V_131 ,
V_133 ) ;
if ( V_17 )
goto V_135;
if ( V_131 -> V_71 != V_76 ) {
V_17 = V_131 -> V_71 ;
goto V_135;
}
* V_253 = F_32 ( V_131 -> V_121 . V_90 ) ;
V_135:
F_29 ( V_131 ) ;
F_29 ( V_130 ) ;
return V_17 ;
}
static int F_103 ( struct V_11 * V_12 ,
struct V_11 * * V_254 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_122 = - 1 ;
int V_58 = - 1 ;
int V_17 ;
struct V_11 * V_255 ;
V_17 = F_102 ( V_12 , & V_122 ) ;
if ( V_17 )
goto V_135;
if ( V_122 != - 1 && V_122 != V_61 -> V_122 ) {
V_17 = F_101 ( V_12 , & V_58 , 0 , false ) ;
if ( V_58 != - 1 ) {
* V_254 = V_12 ;
V_61 -> V_122 = V_122 ;
F_12 ( L_51 ) ;
return V_17 ;
} else
F_12 ( L_52 ) ;
}
F_42 (ch, &ex->children, siblings) {
if ( V_255 -> V_192 == V_211 || V_255 -> V_192 == V_213 ) {
V_17 = F_103 ( V_255 , V_254 ) ;
if ( * V_254 )
return V_17 ;
}
}
V_135:
return V_17 ;
}
static void F_104 ( struct V_164 * V_21 , struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_11 * V_183 , * V_256 ;
F_105 (child, n, &ex->children, siblings) {
V_183 -> V_257 = 1 ;
if ( V_183 -> V_192 == V_211 ||
V_183 -> V_192 == V_213 )
F_104 ( V_21 , V_183 ) ;
else
F_106 ( V_21 , V_183 ) ;
}
F_106 ( V_21 , V_12 ) ;
}
static void F_107 ( struct V_11 * V_166 ,
int V_58 , bool V_258 )
{
struct V_60 * V_62 = & V_166 -> V_62 ;
struct V_63 * V_64 = & V_62 -> V_63 [ V_58 ] ;
struct V_11 * V_183 , * V_256 ;
if ( V_258 ) {
F_105 (child, n,
&ex_dev->children, siblings) {
if ( F_14 ( V_183 -> V_54 ) ==
F_14 ( V_64 -> V_86 ) ) {
V_183 -> V_257 = 1 ;
if ( V_183 -> V_192 == V_211 ||
V_183 -> V_192 == V_213 )
F_104 ( V_166 -> V_21 , V_183 ) ;
else
F_106 ( V_166 -> V_21 , V_183 ) ;
break;
}
}
V_166 -> V_257 = 1 ;
F_79 ( V_166 , V_64 -> V_86 ) ;
}
memset ( V_64 -> V_86 , 0 , V_87 ) ;
if ( V_64 -> V_21 ) {
F_108 ( V_64 -> V_21 , V_64 -> V_64 ) ;
if ( V_64 -> V_21 -> V_118 == 0 )
F_68 ( V_64 -> V_21 ) ;
V_64 -> V_21 = NULL ;
}
}
static int F_109 ( struct V_11 * V_259 ,
const int V_215 )
{
struct V_60 * V_260 = & V_259 -> V_62 ;
struct V_11 * V_183 ;
int V_17 = 0 ;
F_42 (child, &ex_root->children, siblings) {
if ( V_183 -> V_192 == V_211 ||
V_183 -> V_192 == V_213 ) {
struct V_138 * V_61 =
F_37 ( V_183 -> V_69 ) ;
if ( V_215 > V_61 -> V_215 )
V_17 = F_109 ( V_183 ,
V_215 ) ;
else if ( V_215 == V_61 -> V_215 )
V_17 = F_82 ( V_183 , - 1 ) ;
}
}
return V_17 ;
}
static int F_110 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_138 * V_61 = F_37 ( V_12 -> V_69 ) ;
int V_215 = V_61 -> V_215 + 1 ;
V_17 = F_82 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_135;
do {
V_17 = F_109 ( V_12 , V_215 ) ;
F_95 () ;
V_215 += 1 ;
} while ( V_215 <= V_12 -> V_21 -> V_67 . V_216 );
V_135:
return V_17 ;
}
static int F_111 ( struct V_11 * V_12 , int V_58 )
{
struct V_63 * V_63 = & V_12 -> V_62 . V_63 [ V_58 ] ;
struct V_11 * V_183 ;
bool V_261 = false ;
int V_17 , V_20 ;
F_12 ( L_53 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
V_17 = F_28 ( V_12 , V_58 ) ;
if ( V_17 )
goto V_135;
for ( V_20 = 0 ; V_20 < V_12 -> V_62 . V_118 ; V_20 ++ ) {
struct V_63 * V_262 = & V_12 -> V_62 . V_63 [ V_20 ] ;
if ( V_20 == V_58 )
continue;
if ( F_14 ( V_262 -> V_86 ) ==
F_14 ( V_63 -> V_86 ) ) {
V_261 = true ;
break;
}
}
if ( V_261 ) {
F_69 ( V_12 , V_58 ) ;
return 0 ;
}
V_17 = F_82 ( V_12 , V_58 ) ;
if ( ! V_17 )
goto V_135;
F_42 (child, &dev->ex_dev.children, siblings) {
if ( F_14 ( V_183 -> V_54 ) ==
F_14 ( V_63 -> V_86 ) ) {
if ( V_183 -> V_192 == V_211 ||
V_183 -> V_192 == V_213 )
V_17 = F_110 ( V_183 ) ;
break;
}
}
V_135:
return V_17 ;
}
static int F_112 ( struct V_11 * V_12 , int V_58 , bool V_258 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
T_1 V_86 [ 8 ] ;
int V_17 ;
V_17 = F_100 ( V_12 , V_58 , V_86 ) ;
switch ( V_17 ) {
case V_263 :
V_64 -> V_73 = V_75 ;
F_107 ( V_12 , V_58 , V_258 ) ;
goto V_135; break;
case V_72 :
V_64 -> V_73 = V_74 ;
F_107 ( V_12 , V_58 , V_258 ) ;
goto V_135; break;
case V_76 :
break;
}
if ( F_14 ( V_86 ) == 0 ) {
V_64 -> V_73 = V_77 ;
F_107 ( V_12 , V_58 , V_258 ) ;
} else if ( F_14 ( V_86 ) ==
F_14 ( V_64 -> V_86 ) ) {
F_12 ( L_54 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
F_28 ( V_12 , V_58 ) ;
} else
V_17 = F_111 ( V_12 , V_58 ) ;
V_135:
return V_17 ;
}
static int F_113 ( struct V_11 * V_12 , const int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_264 = & V_61 -> V_63 [ V_58 ] ;
int V_17 = 0 ;
int V_20 ;
bool V_258 = true ;
F_12 ( L_55 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
if ( F_14 ( V_264 -> V_86 ) != 0 ) {
for ( V_20 = 0 ; V_20 < V_61 -> V_118 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_20 == V_58 )
continue;
if ( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_264 -> V_86 ) ) {
F_12 ( L_56
L_57 , V_58 , V_20 ) ;
V_258 = false ;
break;
}
}
V_17 = F_112 ( V_12 , V_58 , V_258 ) ;
} else
V_17 = F_111 ( V_12 , V_58 ) ;
return V_17 ;
}
int F_114 ( struct V_11 * V_248 )
{
int V_17 ;
struct V_11 * V_12 = NULL ;
V_17 = F_103 ( V_248 , & V_12 ) ;
if ( V_17 )
goto V_135;
if ( V_12 ) {
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 = 0 , V_58 ;
do {
V_58 = - 1 ;
V_17 = F_101 ( V_12 , & V_58 , V_20 , true ) ;
if ( V_58 == - 1 )
break;
V_17 = F_113 ( V_12 , V_58 ) ;
V_20 = V_58 + 1 ;
} while ( V_20 < V_61 -> V_118 );
}
V_135:
return V_17 ;
}
int F_115 ( struct V_265 * V_24 , struct V_68 * V_69 ,
struct V_266 * V_13 )
{
struct V_11 * V_12 ;
int V_267 , type ;
struct V_266 * V_268 = V_13 -> V_269 ;
if ( ! V_268 ) {
F_116 ( L_58 ,
V_53 ) ;
return - V_270 ;
}
if ( ! V_69 )
return F_117 ( V_24 , V_13 , V_268 ) ;
type = V_69 -> V_94 . V_96 ;
if ( type != V_212 &&
type != V_214 ) {
F_116 ( L_59 ,
V_53 ) ;
return - V_270 ;
}
V_12 = F_45 ( V_69 ) ;
if ( ! V_12 ) {
F_116 ( L_60 , V_53 ) ;
return - V_270 ;
}
if ( V_13 -> V_271 -> V_272 > 1 || V_268 -> V_271 -> V_272 > 1 ) {
F_116 ( L_61 ,
V_53 , V_13 -> V_271 -> V_272 , F_118 ( V_13 ) ,
V_268 -> V_271 -> V_272 , F_118 ( V_268 ) ) ;
return - V_270 ;
}
V_267 = F_7 ( V_12 , F_119 ( V_13 -> V_271 ) , F_118 ( V_13 ) ,
F_119 ( V_268 -> V_271 ) , F_118 ( V_268 ) ) ;
if ( V_267 > 0 ) {
V_268 -> V_273 = V_267 ;
V_13 -> V_273 = 0 ;
V_267 = 0 ;
} else if ( V_267 == 0 ) {
V_268 -> V_273 = 0 ;
V_13 -> V_273 = 0 ;
}
return V_267 ;
}
