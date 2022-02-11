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
V_64 -> V_64 -> V_94 . V_95 = V_64 -> V_83 ;
V_64 -> V_64 -> V_94 . V_96 = V_64 -> V_85 ;
V_64 -> V_64 -> V_94 . V_97 = V_58 ;
V_64 -> V_64 -> V_98 = V_66 -> V_99 ;
V_64 -> V_64 -> V_100 = V_66 -> V_101 ;
V_64 -> V_64 -> V_102 = V_66 -> V_103 ;
V_64 -> V_64 -> V_104 = V_66 -> V_105 ;
V_64 -> V_64 -> V_106 = V_64 -> V_79 ;
if ( ! V_70 )
if ( F_22 ( V_64 -> V_64 ) ) {
F_23 ( V_64 -> V_64 ) ;
return;
}
F_12 ( L_6 ,
F_14 ( V_12 -> V_54 ) , V_64 -> V_58 ,
V_64 -> V_91 == V_107 ? 'T' :
V_64 -> V_91 == V_108 ? 'D' :
V_64 -> V_91 == V_109 ? 'S' : '?' ,
F_14 ( V_64 -> V_86 ) ) ;
return;
}
static int F_24 ( struct V_11 * V_12 , T_1 * V_110 ,
T_1 * V_59 , int V_111 )
{
int V_20 , V_17 ;
V_110 [ 9 ] = V_111 ;
for ( V_20 = 1 ; V_20 < 3 ; V_20 ++ ) {
struct V_65 * V_66 ;
V_17 = F_7 ( V_12 , V_110 , V_112 ,
V_59 , V_113 ) ;
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
F_26 ( V_12 , V_111 , V_114 , NULL ) ;
F_27 ( 500 ) ;
}
F_20 ( V_12 , V_111 , V_59 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 , int V_111 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = 0 ;
T_1 * V_110 ;
T_1 * V_59 ;
V_110 = F_17 ( V_112 ) ;
if ( ! V_110 )
return - V_27 ;
V_59 = F_17 ( V_113 ) ;
if ( ! V_59 ) {
F_29 ( V_110 ) ;
return - V_27 ;
}
V_110 [ 1 ] = V_115 ;
if ( 0 <= V_111 && V_111 < V_61 -> V_116 ) {
V_17 = F_24 ( V_12 , V_110 , V_59 , V_111 ) ;
} else {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
V_17 = F_24 ( V_12 , V_110 ,
V_59 , V_20 ) ;
if ( V_17 )
goto V_117;
}
}
V_117:
F_29 ( V_59 ) ;
F_29 ( V_110 ) ;
return V_17 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = - V_27 ;
V_61 -> V_63 = F_18 ( sizeof( * V_61 -> V_63 ) * V_61 -> V_116 , V_26 ) ;
if ( ! V_61 -> V_63 )
return - V_27 ;
V_17 = F_28 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_117;
return 0 ;
V_117:
F_29 ( V_61 -> V_63 ) ;
V_61 -> V_63 = NULL ;
return V_17 ;
}
static void F_31 ( struct V_11 * V_12 ,
struct V_32 * V_15 )
{
struct V_118 * V_119 = & V_15 -> V_119 ;
V_12 -> V_62 . V_120 = F_32 ( V_119 -> V_90 ) ;
V_12 -> V_62 . V_121 = F_32 ( V_119 -> V_122 ) ;
V_12 -> V_62 . V_116 = F_33 ( V_119 -> V_116 , ( T_1 ) V_123 ) ;
V_12 -> V_62 . V_124 = V_119 -> V_124 ;
V_12 -> V_62 . V_125 = V_119 -> V_125 ;
memcpy ( V_12 -> V_62 . V_126 , V_119 -> V_126 , 8 ) ;
}
static int F_34 ( struct V_11 * V_12 )
{
T_1 * V_127 ;
struct V_32 * V_128 ;
int V_17 ;
int V_20 ;
V_127 = F_17 ( V_129 ) ;
if ( ! V_127 )
return - V_27 ;
V_128 = F_19 ( V_130 ) ;
if ( ! V_128 ) {
F_29 ( V_127 ) ;
return - V_27 ;
}
V_127 [ 1 ] = V_131 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_17 = F_7 ( V_12 , V_127 , V_129 , V_128 ,
V_130 ) ;
if ( V_17 ) {
F_12 ( L_8 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_132;
} else if ( V_128 -> V_71 != V_76 ) {
F_12 ( L_9 ,
F_14 ( V_12 -> V_54 ) , V_128 -> V_71 ) ;
V_17 = V_128 -> V_71 ;
goto V_132;
}
F_31 ( V_12 , V_128 ) ;
if ( V_12 -> V_62 . V_125 ) {
F_12 ( L_10 ,
F_14 ( V_12 -> V_54 ) ) ;
F_35 ( 5 * V_39 ) ;
} else
break;
}
V_132:
F_29 ( V_127 ) ;
F_29 ( V_128 ) ;
return V_17 ;
}
static void F_36 ( struct V_11 * V_12 , void
* V_133 )
{
T_1 * V_134 = V_133 ;
struct V_68 * V_69 = V_12 -> V_69 ;
struct V_135 * V_136 = F_37 ( V_69 ) ;
memcpy ( V_136 -> V_137 , V_134 + 12 , V_138 ) ;
memcpy ( V_136 -> V_139 , V_134 + 20 , V_140 ) ;
memcpy ( V_136 -> V_141 , V_134 + 36 ,
V_142 ) ;
if ( V_134 [ 8 ] & 1 ) {
memcpy ( V_136 -> V_143 , V_134 + 40 ,
V_144 ) ;
V_136 -> V_145 = V_134 [ 48 ] << 8 | V_134 [ 49 ] ;
V_136 -> V_146 = V_134 [ 50 ] ;
}
}
static int F_38 ( struct V_11 * V_12 )
{
T_1 * V_147 ;
T_1 * V_134 ;
int V_17 ;
V_147 = F_17 ( V_148 ) ;
if ( ! V_147 )
return - V_27 ;
V_134 = F_19 ( V_149 ) ;
if ( ! V_134 ) {
F_29 ( V_147 ) ;
return - V_27 ;
}
V_147 [ 1 ] = V_150 ;
V_17 = F_7 ( V_12 , V_147 , V_148 , V_134 , V_149 ) ;
if ( V_17 ) {
F_12 ( L_11 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_132;
} else if ( V_134 [ 2 ] != V_76 ) {
F_12 ( L_12 ,
F_14 ( V_12 -> V_54 ) , V_134 [ 2 ] ) ;
goto V_132;
}
F_36 ( V_12 , V_134 ) ;
V_132:
F_29 ( V_147 ) ;
F_29 ( V_134 ) ;
return V_17 ;
}
int F_26 ( struct V_11 * V_12 , int V_58 ,
enum V_151 V_151 ,
struct V_152 * V_153 )
{
T_1 * V_154 ;
T_1 * V_155 ;
int V_17 ;
V_154 = F_17 ( V_156 ) ;
if ( ! V_154 )
return - V_27 ;
V_155 = F_19 ( V_157 ) ;
if ( ! V_155 ) {
F_29 ( V_154 ) ;
return - V_27 ;
}
V_154 [ 1 ] = V_158 ;
V_154 [ 9 ] = V_58 ;
V_154 [ 10 ] = V_151 ;
if ( V_153 ) {
V_154 [ 32 ] = V_153 -> V_102 << 4 ;
V_154 [ 33 ] = V_153 -> V_104 << 4 ;
}
V_17 = F_7 ( V_12 , V_154 , V_156 , V_155 , V_157 ) ;
F_29 ( V_155 ) ;
F_29 ( V_154 ) ;
return V_17 ;
}
static void F_39 ( struct V_11 * V_12 , int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
F_26 ( V_12 , V_58 , V_159 , NULL ) ;
V_64 -> V_79 = V_160 ;
}
static void F_40 ( struct V_11 * V_12 , T_1 * V_54 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( F_14 ( V_64 -> V_86 ) == F_14 ( V_54 ) )
F_39 ( V_12 , V_20 ) ;
}
}
static int F_41 ( struct V_161 * V_21 ,
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
int F_43 ( struct V_162 * V_64 )
{
int V_17 ;
T_1 * V_13 ;
T_1 * V_15 ;
struct V_68 * V_69 = F_44 ( V_64 -> V_12 . V_163 ) ;
struct V_11 * V_12 = F_45 ( V_69 ) ;
V_13 = F_17 ( V_164 ) ;
if ( ! V_13 )
return - V_27 ;
V_15 = F_19 ( V_165 ) ;
if ( ! V_15 ) {
F_29 ( V_13 ) ;
return - V_27 ;
}
V_13 [ 1 ] = V_166 ;
V_13 [ 9 ] = V_64 -> V_167 ;
V_17 = F_7 ( V_12 , V_13 , V_164 ,
V_15 , V_165 ) ;
if ( ! V_17 )
goto V_132;
V_64 -> V_168 = F_46 ( & V_15 [ 12 ] ) ;
V_64 -> V_169 = F_46 ( & V_15 [ 16 ] ) ;
V_64 -> V_170 = F_46 ( & V_15 [ 20 ] ) ;
V_64 -> V_171 = F_46 ( & V_15 [ 24 ] ) ;
V_132:
F_29 ( V_15 ) ;
return V_17 ;
}
static int F_47 ( struct V_11 * V_12 ,
int V_58 ,
struct V_32 * V_172 )
{
int V_17 ;
T_1 * V_173 = F_17 ( V_174 ) ;
T_1 * V_15 = ( T_1 * ) V_172 ;
if ( ! V_173 )
return - V_27 ;
V_173 [ 1 ] = V_175 ;
V_173 [ 9 ] = V_58 ;
V_17 = F_7 ( V_12 , V_173 , V_174 ,
V_172 , V_176 ) ;
if ( ! V_17 && V_15 [ 27 ] == 0x34 && V_15 [ 24 ] != 0x34 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
int V_177 = 24 + ( V_20 * 4 ) ;
T_1 V_178 , V_179 ;
V_178 = V_15 [ V_177 + 0 ] ;
V_179 = V_15 [ V_177 + 1 ] ;
V_15 [ V_177 + 0 ] = V_15 [ V_177 + 3 ] ;
V_15 [ V_177 + 1 ] = V_15 [ V_177 + 2 ] ;
V_15 [ V_177 + 2 ] = V_179 ;
V_15 [ V_177 + 3 ] = V_178 ;
}
}
F_29 ( V_173 ) ;
return V_17 ;
}
static void F_48 ( struct V_11 * V_163 ,
struct V_11 * V_180 ,
struct V_63 * V_181 )
{
struct V_60 * V_182 = & V_163 -> V_62 ;
struct V_183 * V_21 ;
int V_20 ;
V_180 -> V_184 = 0 ;
V_21 = V_181 -> V_21 ;
for ( V_20 = 0 ; V_20 < V_182 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_182 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_180 -> V_54 ) ) {
V_180 -> V_185 = F_33 ( V_163 -> V_185 ,
V_64 -> V_79 ) ;
V_180 -> V_186 = F_49 ( V_163 -> V_186 ,
V_64 -> V_79 ) ;
V_180 -> V_184 ++ ;
F_50 ( V_21 , V_64 -> V_64 ) ;
}
}
V_180 -> V_79 = F_33 ( V_181 -> V_79 , V_180 -> V_186 ) ;
V_180 -> V_184 = F_33 ( V_180 -> V_184 , V_163 -> V_184 ) ;
}
static struct V_11 * F_51 (
struct V_11 * V_163 , int V_58 )
{
struct V_60 * V_182 = & V_163 -> V_62 ;
struct V_63 * V_64 = & V_182 -> V_63 [ V_58 ] ;
struct V_11 * V_180 = NULL ;
struct V_68 * V_69 ;
int V_17 ;
if ( V_64 -> V_80 || V_64 -> V_82 )
return NULL ;
V_180 = F_18 ( sizeof( * V_180 ) , V_26 ) ;
if ( ! V_180 )
return NULL ;
V_180 -> V_163 = V_163 ;
V_180 -> V_21 = V_163 -> V_21 ;
V_180 -> V_84 = V_64 -> V_83 ;
memcpy ( V_180 -> V_54 , V_64 -> V_86 , V_87 ) ;
F_52 ( V_180 -> V_187 , V_180 -> V_54 ) ;
if ( ! V_64 -> V_21 ) {
V_64 -> V_21 = F_53 ( & V_163 -> V_69 -> V_12 , V_58 ) ;
if ( F_54 ( ! V_64 -> V_21 ) )
goto V_117;
if ( F_54 ( F_55 ( V_64 -> V_21 ) != 0 ) ) {
F_56 ( V_64 -> V_21 ) ;
goto V_117;
}
}
F_48 ( V_163 , V_180 , V_64 ) ;
#ifdef F_57
if ( ( V_64 -> V_85 & V_188 ) || V_64 -> V_81 ) {
V_180 -> V_189 = V_190 ;
if ( V_64 -> V_85 & V_188 )
V_180 -> V_29 = V_64 -> V_85 ;
if ( V_64 -> V_81 )
V_180 -> V_29 |= V_190 ;
V_17 = F_47 ( V_163 , V_58 ,
& V_180 -> V_191 . V_172 ) ;
if ( V_17 ) {
F_12 ( L_13
L_14 , F_14 ( V_163 -> V_54 ) ,
V_58 , V_17 ) ;
goto V_192;
}
memcpy ( V_180 -> V_193 , & V_180 -> V_191 . V_172 . V_194 . V_195 ,
sizeof( struct V_196 ) ) ;
V_69 = F_58 ( V_64 -> V_21 ) ;
if ( F_54 ( ! V_69 ) )
goto V_192;
F_59 ( V_180 ) ;
V_180 -> V_69 = V_69 ;
F_60 ( & V_163 -> V_21 -> V_197 ) ;
F_61 ( & V_180 -> V_198 , & V_163 -> V_21 -> V_199 ) ;
F_62 ( & V_163 -> V_21 -> V_197 ) ;
V_17 = F_63 ( V_180 ) ;
if ( V_17 ) {
F_12 ( L_15
L_16 ,
F_14 ( V_180 -> V_54 ) ,
F_14 ( V_163 -> V_54 ) , V_58 , V_17 ) ;
goto V_200;
}
} else
#endif
if ( V_64 -> V_85 & V_201 ) {
V_180 -> V_189 = V_202 ;
V_69 = F_58 ( V_64 -> V_21 ) ;
if ( F_54 ( ! V_69 ) )
goto V_192;
V_180 -> V_29 = V_64 -> V_85 ;
F_59 ( V_180 ) ;
V_180 -> V_69 = V_69 ;
F_64 ( V_180 , V_69 ) ;
F_60 ( & V_163 -> V_21 -> V_197 ) ;
F_61 ( & V_180 -> V_198 , & V_163 -> V_21 -> V_199 ) ;
F_62 ( & V_163 -> V_21 -> V_197 ) ;
V_17 = F_65 ( V_180 ) ;
if ( V_17 ) {
F_12 ( L_17
L_18 ,
F_14 ( V_180 -> V_54 ) ,
F_14 ( V_163 -> V_54 ) , V_58 , V_17 ) ;
goto V_200;
}
} else {
F_12 ( L_19 ,
V_64 -> V_85 , F_14 ( V_163 -> V_54 ) ,
V_58 ) ;
goto V_192;
}
F_61 ( & V_180 -> V_203 , & V_182 -> V_204 ) ;
return V_180 ;
V_200:
F_66 ( V_180 -> V_69 ) ;
V_180 -> V_69 = NULL ;
F_67 ( & V_180 -> V_198 ) ;
V_192:
F_68 ( V_64 -> V_21 ) ;
V_117:
V_64 -> V_21 = NULL ;
F_29 ( V_180 ) ;
return NULL ;
}
static int F_69 ( struct V_11 * V_163 , int V_58 )
{
struct V_63 * V_64 = & V_163 -> V_62 . V_63 [ V_58 ] ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_163 -> V_62 . V_116 ; V_20 ++ ) {
struct V_63 * V_205 = & V_163 -> V_62 . V_63 [ V_20 ] ;
if ( V_205 == V_64 )
continue;
if ( ! memcmp ( V_64 -> V_86 , V_205 -> V_86 ,
V_87 ) && V_205 -> V_21 ) {
F_50 ( V_205 -> V_21 , V_64 -> V_64 ) ;
V_64 -> V_21 = V_205 -> V_21 ;
V_64 -> V_73 = V_206 ;
return 0 ;
}
}
return - V_207 ;
}
static struct V_11 * F_70 (
struct V_11 * V_163 , int V_58 )
{
struct V_135 * V_182 = F_37 ( V_163 -> V_69 ) ;
struct V_63 * V_64 = & V_163 -> V_62 . V_63 [ V_58 ] ;
struct V_11 * V_180 = NULL ;
struct V_68 * V_69 ;
struct V_135 * V_136 ;
struct V_161 * V_21 ;
int V_17 ;
if ( V_64 -> V_91 == V_108 ) {
F_12 ( L_20
L_21 ,
F_14 ( V_163 -> V_54 ) , V_58 ,
F_14 ( V_64 -> V_86 ) ,
V_64 -> V_88 ) ;
return NULL ;
}
V_180 = F_18 ( sizeof( * V_180 ) , V_26 ) ;
if ( ! V_180 )
return NULL ;
V_64 -> V_21 = F_53 ( & V_163 -> V_69 -> V_12 , V_58 ) ;
F_16 ( F_55 ( V_64 -> V_21 ) != 0 ) ;
switch ( V_64 -> V_78 ) {
case V_208 :
V_69 = F_71 ( V_64 -> V_21 ,
V_209 ) ;
break;
case V_210 :
V_69 = F_71 ( V_64 -> V_21 ,
V_211 ) ;
break;
default:
V_69 = NULL ;
F_72 () ;
}
V_21 = V_163 -> V_21 ;
V_180 -> V_69 = V_69 ;
V_136 = F_37 ( V_69 ) ;
V_180 -> V_189 = V_64 -> V_78 ;
V_180 -> V_163 = V_163 ;
V_180 -> V_21 = V_21 ;
V_180 -> V_84 = V_64 -> V_83 ;
V_180 -> V_29 = V_64 -> V_85 ;
memcpy ( V_180 -> V_54 , V_64 -> V_86 , V_87 ) ;
F_52 ( V_180 -> V_187 , V_180 -> V_54 ) ;
F_48 ( V_163 , V_180 , V_64 ) ;
V_136 -> V_212 = V_182 -> V_212 + 1 ;
V_163 -> V_21 -> V_67 . V_213 = F_49 ( V_163 -> V_21 -> V_67 . V_213 ,
V_136 -> V_212 ) ;
F_59 ( V_180 ) ;
F_64 ( V_180 , V_69 ) ;
F_73 ( V_69 ) ;
F_60 ( & V_163 -> V_21 -> V_197 ) ;
F_61 ( & V_180 -> V_198 , & V_163 -> V_21 -> V_199 ) ;
F_62 ( & V_163 -> V_21 -> V_197 ) ;
V_17 = F_74 ( V_180 ) ;
if ( V_17 ) {
F_29 ( V_180 ) ;
return NULL ;
}
F_61 ( & V_180 -> V_203 , & V_163 -> V_62 . V_204 ) ;
return V_180 ;
}
static int F_75 ( struct V_11 * V_12 , int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_63 = & V_61 -> V_63 [ V_58 ] ;
struct V_11 * V_180 = NULL ;
int V_17 = 0 ;
if ( V_63 -> V_79 == V_214 ) {
if ( ! F_26 ( V_12 , V_58 , V_114 , NULL ) )
V_17 = F_28 ( V_12 , V_58 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! V_12 -> V_163 && ( F_14 ( V_63 -> V_86 ) ==
F_14 ( V_12 -> V_21 -> V_54 ) ) ) {
F_76 ( V_12 , V_58 ) ;
return 0 ;
}
if ( V_12 -> V_163 && ( F_14 ( V_63 -> V_86 ) ==
F_14 ( V_12 -> V_163 -> V_54 ) ) ) {
F_76 ( V_12 , V_58 ) ;
if ( V_63 -> V_91 == V_107 )
F_77 ( V_12 , V_58 , V_12 -> V_21 -> V_54 , 1 ) ;
return 0 ;
}
if ( F_41 ( V_12 -> V_21 , V_63 -> V_86 ) )
F_40 ( V_12 , V_63 -> V_86 ) ;
if ( V_63 -> V_78 == V_215 ) {
if ( V_63 -> V_91 == V_108 ) {
memset ( V_63 -> V_86 , 0 , V_87 ) ;
F_78 ( V_12 , V_63 -> V_86 ) ;
}
return 0 ;
} else if ( V_63 -> V_79 == V_216 )
return 0 ;
if ( V_63 -> V_78 != V_202 &&
V_63 -> V_78 != V_210 &&
V_63 -> V_78 != V_208 ) {
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
case V_202 :
V_180 = F_51 ( V_12 , V_58 ) ;
break;
case V_210 :
if ( F_14 ( V_12 -> V_21 -> V_67 . V_217 ) ) {
F_12 ( L_27
L_28 ,
F_14 ( V_63 -> V_86 ) ,
V_63 -> V_88 ,
F_14 ( V_12 -> V_54 ) ,
V_58 ) ;
F_39 ( V_12 , V_58 ) ;
break;
} else
memcpy ( V_12 -> V_21 -> V_67 . V_217 ,
V_63 -> V_86 , V_87 ) ;
case V_208 :
V_180 = F_70 ( V_12 , V_58 ) ;
break;
default:
break;
}
if ( V_180 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
if ( V_61 -> V_63 [ V_20 ] . V_73 == V_74 ||
V_61 -> V_63 [ V_20 ] . V_73 == V_75 )
continue;
if ( F_14 ( V_61 -> V_63 [ V_20 ] . V_86 ) ==
F_14 ( V_180 -> V_54 ) ) {
V_61 -> V_63 [ V_20 ] . V_73 = V_206 ;
V_17 = F_69 ( V_12 , V_20 ) ;
if ( ! V_17 )
F_12 ( L_26 ,
V_20 , F_14 ( V_61 -> V_63 [ V_20 ] . V_86 ) ) ;
}
}
}
return V_17 ;
}
static int F_80 ( struct V_11 * V_12 , T_1 * V_218 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( ( V_64 -> V_78 == V_208 ||
V_64 -> V_78 == V_210 ) &&
V_64 -> V_91 == V_109 ) {
memcpy ( V_218 , V_64 -> V_86 , V_87 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_81 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_11 * V_180 ;
T_1 V_218 [ 8 ] = { 0 , } ;
F_42 (child, &ex->children, siblings) {
if ( V_180 -> V_189 != V_208 &&
V_180 -> V_189 != V_210 )
continue;
if ( V_218 [ 0 ] == 0 ) {
F_80 ( V_180 , V_218 ) ;
continue;
} else {
T_1 V_219 [ 8 ] ;
if ( F_80 ( V_180 , V_219 ) &&
( F_14 ( V_218 ) != F_14 ( V_219 ) ) ) {
F_12 ( L_29
L_30
L_31 ,
F_14 ( V_12 -> V_54 ) ,
F_14 ( V_180 -> V_54 ) ,
F_14 ( V_219 ) ,
F_14 ( V_218 ) ) ;
F_40 ( V_180 , V_219 ) ;
}
}
}
return 0 ;
}
static int F_82 ( struct V_11 * V_12 , int V_111 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_20 = 0 , V_220 = V_61 -> V_116 ;
int V_17 = 0 ;
if ( 0 <= V_111 && V_111 < V_220 ) {
V_20 = V_111 ;
V_220 = V_20 + 1 ;
}
for ( ; V_20 < V_220 ; V_20 ++ ) {
struct V_63 * V_63 = & V_61 -> V_63 [ V_20 ] ;
if ( V_63 -> V_73 == V_74 ||
V_63 -> V_73 == V_75 ||
V_63 -> V_73 == V_206 )
continue;
switch ( V_63 -> V_79 ) {
case V_160 :
case V_221 :
case V_222 :
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
T_1 * V_223 = NULL ;
if ( V_12 -> V_189 != V_208 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_64 -> V_73 == V_74 ||
V_64 -> V_73 == V_75 )
continue;
if ( ( V_64 -> V_78 == V_210 ||
V_64 -> V_78 == V_208 ) &&
V_64 -> V_91 == V_109 ) {
if ( ! V_223 )
V_223 = & V_64 -> V_86 [ 0 ] ;
else if ( F_14 ( V_223 ) !=
F_14 ( V_64 -> V_86 ) ) {
F_12 ( L_32
L_33
L_34 ,
F_14 ( V_12 -> V_54 ) , V_20 ,
F_14 ( V_64 -> V_86 ) ,
F_14 ( V_223 ) ) ;
F_39 ( V_12 , V_20 ) ;
}
}
}
return 0 ;
}
static void F_84 ( struct V_11 * V_180 ,
struct V_63 * V_181 ,
struct V_63 * V_224 )
{
static const char V_225 [] = {
[ V_108 ] = 'D' ,
[ V_109 ] = 'S' ,
[ V_107 ] = 'T' ,
} ;
static const char * V_226 [] = {
[ V_208 ] = L_35 ,
[ V_210 ] = L_36 ,
} ;
struct V_11 * V_163 = V_180 -> V_163 ;
F_25 ( L_37
L_38 ,
V_226 [ V_163 -> V_189 ] ,
F_14 ( V_163 -> V_54 ) ,
V_181 -> V_58 ,
V_226 [ V_180 -> V_189 ] ,
F_14 ( V_180 -> V_54 ) ,
V_224 -> V_58 ,
V_225 [ V_181 -> V_91 ] ,
V_225 [ V_224 -> V_91 ] ) ;
}
static int F_85 ( struct V_11 * V_180 ,
struct V_63 * V_181 ,
struct V_63 * V_224 )
{
int V_17 = 0 ;
struct V_11 * V_163 = V_180 -> V_163 ;
if ( F_14 ( V_163 -> V_21 -> V_67 . V_217 ) != 0 ) {
V_17 = - V_207 ;
F_12 ( L_39
L_40 ,
F_14 ( V_163 -> V_54 ) ,
V_181 -> V_58 ,
F_14 ( V_180 -> V_54 ) ,
V_224 -> V_58 ,
F_14 ( V_163 -> V_21 -> V_67 . V_217 ) ) ;
} else if ( F_14 ( V_163 -> V_21 -> V_67 . V_227 ) == 0 ) {
memcpy ( V_163 -> V_21 -> V_67 . V_227 , V_163 -> V_54 ,
V_87 ) ;
memcpy ( V_163 -> V_21 -> V_67 . V_228 , V_180 -> V_54 ,
V_87 ) ;
} else if ( ( ( F_14 ( V_163 -> V_21 -> V_67 . V_227 ) ==
F_14 ( V_163 -> V_54 ) ) ||
( F_14 ( V_163 -> V_21 -> V_67 . V_227 ) ==
F_14 ( V_180 -> V_54 ) ) )
&&
( ( F_14 ( V_163 -> V_21 -> V_67 . V_228 ) ==
F_14 ( V_163 -> V_54 ) ) ||
( F_14 ( V_163 -> V_21 -> V_67 . V_228 ) ==
F_14 ( V_180 -> V_54 ) ) ) )
;
else {
V_17 = - V_207 ;
F_12 ( L_41
L_42 ,
F_14 ( V_163 -> V_54 ) ,
V_181 -> V_58 ,
F_14 ( V_180 -> V_54 ) ,
V_224 -> V_58 ) ;
}
return V_17 ;
}
static int F_86 ( struct V_11 * V_180 )
{
struct V_60 * V_229 = & V_180 -> V_62 ;
struct V_60 * V_182 ;
int V_20 ;
int V_17 = 0 ;
if ( ! V_180 -> V_163 )
return 0 ;
if ( V_180 -> V_163 -> V_189 != V_208 &&
V_180 -> V_163 -> V_189 != V_210 )
return 0 ;
V_182 = & V_180 -> V_163 -> V_62 ;
for ( V_20 = 0 ; V_20 < V_182 -> V_116 ; V_20 ++ ) {
struct V_63 * V_181 = & V_182 -> V_63 [ V_20 ] ;
struct V_63 * V_224 ;
if ( V_181 -> V_73 == V_74 ||
V_181 -> V_73 == V_75 )
continue;
if ( F_14 ( V_181 -> V_86 ) != F_14 ( V_180 -> V_54 ) )
continue;
V_224 = & V_229 -> V_63 [ V_181 -> V_88 ] ;
switch ( V_180 -> V_163 -> V_189 ) {
case V_208 :
if ( V_180 -> V_189 == V_210 ) {
if ( V_181 -> V_91 != V_109 ||
V_224 -> V_91 != V_107 ) {
F_84 ( V_180 , V_181 , V_224 ) ;
V_17 = - V_207 ;
}
} else if ( V_181 -> V_91 == V_109 ) {
if ( V_224 -> V_91 == V_109 ) {
V_17 = F_85 ( V_180 , V_181 , V_224 ) ;
} else if ( V_224 -> V_91 != V_107 ) {
F_84 ( V_180 , V_181 , V_224 ) ;
V_17 = - V_207 ;
}
} else if ( V_181 -> V_91 == V_107 &&
V_224 -> V_91 != V_109 ) {
F_84 ( V_180 , V_181 , V_224 ) ;
V_17 = - V_207 ;
}
break;
case V_210 :
if ( V_181 -> V_91 != V_107 ||
V_224 -> V_91 != V_109 ) {
F_84 ( V_180 , V_181 , V_224 ) ;
V_17 = - V_207 ;
}
break;
default:
break;
}
}
return V_17 ;
}
static int F_87 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int * V_230 , int * V_231 )
{
int V_20 , V_17 = 0 ;
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
T_1 * V_232 ;
T_1 * V_233 ;
* V_231 = 0 ;
* V_230 = 0 ;
V_232 = F_17 ( V_234 ) ;
if ( ! V_232 )
return - V_27 ;
V_233 = F_19 ( V_235 ) ;
if ( ! V_233 ) {
F_29 ( V_232 ) ;
return - V_27 ;
}
V_232 [ 1 ] = V_236 ;
V_232 [ 9 ] = V_58 ;
for ( V_20 = 0 ; V_20 < V_61 -> V_121 ; V_20 ++ ) {
* ( V_237 * ) ( V_232 + 6 ) = F_88 ( V_20 ) ;
V_17 = F_7 ( V_12 , V_232 , V_234 , V_233 ,
V_235 ) ;
if ( V_17 )
goto V_132;
V_17 = V_233 [ 2 ] ;
if ( V_17 == V_238 ) {
F_12 ( L_43
L_44 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_20 ) ;
goto V_132;
} else if ( V_17 != V_76 ) {
F_12 ( L_45
L_46 , V_53 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_20 , V_17 ) ;
goto V_132;
}
if ( F_14 ( V_54 ) != 0 ) {
if ( F_14 ( V_233 + 16 ) == F_14 ( V_54 ) ) {
* V_230 = V_20 ;
if ( ( V_233 [ 12 ] & 0x80 ) == 0x80 )
* V_231 = 0 ;
else
* V_231 = 1 ;
goto V_132;
} else if ( F_14 ( V_233 + 16 ) == 0 ) {
* V_230 = V_20 ;
* V_231 = 0 ;
goto V_132;
}
} else if ( F_14 ( V_233 + 16 ) == 0 &&
V_64 -> V_93 < V_20 ) {
V_64 -> V_93 = V_20 ;
* V_230 = V_20 ;
* V_231 = 0 ;
goto V_132;
}
}
V_17 = - 1 ;
V_132:
F_29 ( V_232 ) ;
F_29 ( V_233 ) ;
return V_17 ;
}
static int F_89 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int V_230 , int include )
{
int V_17 ;
T_1 * V_239 ;
T_1 * V_240 ;
V_239 = F_17 ( V_241 ) ;
if ( ! V_239 )
return - V_27 ;
V_240 = F_19 ( V_242 ) ;
if ( ! V_240 ) {
F_29 ( V_239 ) ;
return - V_27 ;
}
V_239 [ 1 ] = V_243 ;
* ( V_237 * ) ( V_239 + 6 ) = F_88 ( V_230 ) ;
V_239 [ 9 ] = V_58 ;
if ( F_14 ( V_54 ) == 0 || ! include )
V_239 [ 12 ] |= 0x80 ;
memcpy ( V_239 + 16 , V_54 , V_87 ) ;
V_17 = F_7 ( V_12 , V_239 , V_241 , V_240 ,
V_242 ) ;
if ( V_17 )
goto V_132;
V_17 = V_240 [ 2 ] ;
if ( V_17 == V_238 ) {
F_12 ( L_47
L_48 ,
F_14 ( V_12 -> V_54 ) , V_58 , V_230 ) ;
}
V_132:
F_29 ( V_239 ) ;
F_29 ( V_240 ) ;
return V_17 ;
}
static int F_77 ( struct V_11 * V_12 , int V_58 ,
T_1 * V_54 , int include )
{
int V_230 ;
int V_231 ;
int V_17 ;
V_17 = F_87 ( V_12 , V_58 , V_54 , & V_230 , & V_231 ) ;
if ( V_17 )
return V_17 ;
if ( include ^ V_231 )
return F_89 ( V_12 , V_58 , V_54 , V_230 , include ) ;
return V_17 ;
}
static int F_90 ( struct V_11 * V_163 ,
struct V_11 * V_180 ,
T_1 * V_54 , int include )
{
struct V_60 * V_244 = & V_163 -> V_62 ;
int V_17 = 0 ;
int V_20 ;
if ( V_163 -> V_163 ) {
V_17 = F_90 ( V_163 -> V_163 , V_163 , V_54 ,
include ) ;
if ( V_17 )
return V_17 ;
}
if ( V_244 -> V_124 == 0 ) {
F_12 ( L_49 ,
F_14 ( V_163 -> V_54 ) ) ;
return 0 ;
}
for ( V_20 = 0 ; V_20 < V_244 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_244 -> V_63 [ V_20 ] ;
if ( ( V_64 -> V_91 == V_107 ) &&
( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_180 -> V_54 ) ) ) {
V_17 = F_77 ( V_163 , V_20 , V_54 , include ) ;
if ( V_17 )
return V_17 ;
}
}
return V_17 ;
}
static int F_78 ( struct V_11 * V_12 , T_1 * V_54 )
{
if ( V_12 -> V_163 )
return F_90 ( V_12 -> V_163 , V_12 , V_54 , 1 ) ;
return 0 ;
}
static int F_79 ( struct V_11 * V_12 , T_1 * V_54 )
{
if ( V_12 -> V_163 )
return F_90 ( V_12 -> V_163 , V_12 , V_54 , 0 ) ;
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
goto V_117;
V_17 = F_38 ( V_12 ) ;
if ( V_17 )
goto V_117;
V_17 = F_30 ( V_12 ) ;
if ( V_17 ) {
F_12 ( L_50 ,
F_14 ( V_12 -> V_54 ) , V_17 ) ;
goto V_117;
}
F_83 ( V_12 ) ;
V_17 = F_86 ( V_12 ) ;
if ( V_17 )
goto V_117;
return 0 ;
V_117:
F_92 ( V_12 ) ;
return V_17 ;
}
static int F_93 ( struct V_161 * V_21 , const int V_212 )
{
int V_17 = 0 ;
struct V_11 * V_12 ;
F_42 (dev, &port->dev_list, dev_list_node) {
if ( V_12 -> V_189 == V_208 ||
V_12 -> V_189 == V_210 ) {
struct V_135 * V_61 =
F_37 ( V_12 -> V_69 ) ;
if ( V_212 == V_61 -> V_212 )
V_17 = F_82 ( V_12 , - 1 ) ;
else if ( V_212 > 0 )
V_17 = F_82 ( V_21 -> V_245 , - 1 ) ;
}
}
return V_17 ;
}
static int F_94 ( struct V_161 * V_21 )
{
int V_17 ;
int V_212 ;
do {
V_212 = V_21 -> V_67 . V_213 ;
V_17 = F_93 ( V_21 , V_212 ) ;
F_95 () ;
} while ( V_212 < V_21 -> V_67 . V_213 );
return V_17 ;
}
int F_96 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_135 * V_61 = F_37 ( V_12 -> V_69 ) ;
V_17 = F_73 ( V_12 -> V_69 ) ;
if ( V_17 )
goto V_117;
V_61 -> V_212 = V_12 -> V_21 -> V_67 . V_213 ;
V_17 = F_74 ( V_12 ) ;
if ( V_17 )
goto V_246;
F_94 ( V_12 -> V_21 ) ;
return V_17 ;
V_246:
F_97 ( V_12 -> V_69 ) ;
V_117:
return V_17 ;
}
static int F_98 ( struct V_11 * V_12 ,
int V_58 , struct V_32 * V_59 )
{
int V_17 ;
T_1 * V_110 ;
V_110 = F_17 ( V_112 ) ;
if ( ! V_110 )
return - V_27 ;
V_110 [ 1 ] = V_115 ;
V_110 [ 9 ] = V_58 ;
V_17 = F_7 ( V_12 , V_110 , V_112 ,
V_59 , V_113 ) ;
if ( V_17 )
goto V_132;
else if ( V_59 -> V_71 != V_76 ) {
V_17 = V_59 -> V_71 ;
goto V_132;
}
V_132:
F_29 ( V_110 ) ;
return V_17 ;
}
static int F_99 ( struct V_11 * V_12 ,
int V_58 , int * V_247 )
{
int V_17 ;
struct V_32 * V_59 ;
V_59 = F_19 ( V_113 ) ;
if ( ! V_59 )
return - V_27 ;
V_17 = F_98 ( V_12 , V_58 , V_59 ) ;
if ( ! V_17 )
* V_247 = V_59 -> V_67 . V_90 ;
F_29 ( V_59 ) ;
return V_17 ;
}
static int F_100 ( struct V_11 * V_12 ,
int V_58 , T_1 * V_86 )
{
int V_17 ;
struct V_32 * V_59 ;
struct V_65 * V_66 ;
V_59 = F_19 ( V_113 ) ;
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
int V_248 , bool V_249 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_17 = 0 ;
int V_20 ;
for ( V_20 = V_248 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
int V_89 = 0 ;
V_17 = F_99 ( V_12 , V_20 , & V_89 ) ;
if ( V_17 )
goto V_132;
else if ( V_89 != V_61 -> V_63 [ V_20 ] . V_89 ) {
if ( V_249 )
V_61 -> V_63 [ V_20 ] . V_89 =
V_89 ;
* V_58 = V_20 ;
return 0 ;
}
}
V_132:
return V_17 ;
}
static int F_102 ( struct V_11 * V_12 , int * V_250 )
{
int V_17 ;
T_1 * V_127 ;
struct V_32 * V_128 ;
V_127 = F_17 ( V_129 ) ;
if ( ! V_127 )
return - V_27 ;
V_128 = F_19 ( V_130 ) ;
if ( ! V_128 ) {
F_29 ( V_127 ) ;
return - V_27 ;
}
V_127 [ 1 ] = V_131 ;
V_17 = F_7 ( V_12 , V_127 , V_129 , V_128 ,
V_130 ) ;
if ( V_17 )
goto V_132;
if ( V_128 -> V_71 != V_76 ) {
V_17 = V_128 -> V_71 ;
goto V_132;
}
* V_250 = F_32 ( V_128 -> V_119 . V_90 ) ;
V_132:
F_29 ( V_128 ) ;
F_29 ( V_127 ) ;
return V_17 ;
}
static int F_103 ( struct V_11 * V_12 ,
struct V_11 * * V_251 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
int V_120 = - 1 ;
int V_58 = - 1 ;
int V_17 ;
struct V_11 * V_252 ;
V_17 = F_102 ( V_12 , & V_120 ) ;
if ( V_17 )
goto V_132;
if ( V_120 != - 1 && V_120 != V_61 -> V_120 ) {
V_17 = F_101 ( V_12 , & V_58 , 0 , false ) ;
if ( V_58 != - 1 ) {
* V_251 = V_12 ;
V_61 -> V_120 = V_120 ;
F_12 ( L_51 ) ;
return V_17 ;
} else
F_12 ( L_52 ) ;
}
F_42 (ch, &ex->children, siblings) {
if ( V_252 -> V_189 == V_208 || V_252 -> V_189 == V_210 ) {
V_17 = F_103 ( V_252 , V_251 ) ;
if ( V_251 )
return V_17 ;
}
}
V_132:
return V_17 ;
}
static void F_104 ( struct V_11 * V_12 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_11 * V_180 , * V_253 ;
F_105 (child, n, &ex->children, siblings) {
V_180 -> V_254 = 1 ;
if ( V_180 -> V_189 == V_208 ||
V_180 -> V_189 == V_210 )
F_104 ( V_180 ) ;
else
F_106 ( V_180 ) ;
}
F_106 ( V_12 ) ;
}
static void F_107 ( struct V_11 * V_163 ,
int V_58 , bool V_255 )
{
struct V_60 * V_62 = & V_163 -> V_62 ;
struct V_63 * V_64 = & V_62 -> V_63 [ V_58 ] ;
struct V_11 * V_180 , * V_253 ;
if ( V_255 ) {
F_105 (child, n,
&ex_dev->children, siblings) {
if ( F_14 ( V_180 -> V_54 ) ==
F_14 ( V_64 -> V_86 ) ) {
V_180 -> V_254 = 1 ;
if ( V_180 -> V_189 == V_208 ||
V_180 -> V_189 == V_210 )
F_104 ( V_180 ) ;
else
F_106 ( V_180 ) ;
break;
}
}
V_163 -> V_254 = 1 ;
F_79 ( V_163 , V_64 -> V_86 ) ;
}
memset ( V_64 -> V_86 , 0 , V_87 ) ;
F_108 ( V_64 -> V_21 , V_64 -> V_64 ) ;
if ( V_64 -> V_21 -> V_116 == 0 )
F_68 ( V_64 -> V_21 ) ;
V_64 -> V_21 = NULL ;
}
static int F_109 ( struct V_11 * V_256 ,
const int V_212 )
{
struct V_60 * V_257 = & V_256 -> V_62 ;
struct V_11 * V_180 ;
int V_17 = 0 ;
F_42 (child, &ex_root->children, siblings) {
if ( V_180 -> V_189 == V_208 ||
V_180 -> V_189 == V_210 ) {
struct V_135 * V_61 =
F_37 ( V_180 -> V_69 ) ;
if ( V_212 > V_61 -> V_212 )
V_17 = F_109 ( V_180 ,
V_212 ) ;
else if ( V_212 == V_61 -> V_212 )
V_17 = F_82 ( V_180 , - 1 ) ;
}
}
return V_17 ;
}
static int F_110 ( struct V_11 * V_12 )
{
int V_17 ;
struct V_135 * V_61 = F_37 ( V_12 -> V_69 ) ;
int V_212 = V_61 -> V_212 + 1 ;
V_17 = F_82 ( V_12 , - 1 ) ;
if ( V_17 )
goto V_132;
do {
V_17 = F_109 ( V_12 , V_212 ) ;
F_95 () ;
V_212 += 1 ;
} while ( V_212 <= V_12 -> V_21 -> V_67 . V_213 );
V_132:
return V_17 ;
}
static int F_111 ( struct V_11 * V_12 , int V_58 )
{
struct V_63 * V_63 = & V_12 -> V_62 . V_63 [ V_58 ] ;
struct V_11 * V_180 ;
bool V_258 = false ;
int V_17 , V_20 ;
F_12 ( L_53 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
V_17 = F_28 ( V_12 , V_58 ) ;
if ( V_17 )
goto V_132;
for ( V_20 = 0 ; V_20 < V_12 -> V_62 . V_116 ; V_20 ++ ) {
struct V_63 * V_259 = & V_12 -> V_62 . V_63 [ V_20 ] ;
if ( V_20 == V_58 )
continue;
if ( F_14 ( V_259 -> V_86 ) ==
F_14 ( V_63 -> V_86 ) ) {
V_258 = true ;
break;
}
}
if ( V_258 ) {
F_69 ( V_12 , V_58 ) ;
return 0 ;
}
V_17 = F_82 ( V_12 , V_58 ) ;
if ( ! V_17 )
goto V_132;
F_42 (child, &dev->ex_dev.children, siblings) {
if ( F_14 ( V_180 -> V_54 ) ==
F_14 ( V_63 -> V_86 ) ) {
if ( V_180 -> V_189 == V_208 ||
V_180 -> V_189 == V_210 )
V_17 = F_110 ( V_180 ) ;
break;
}
}
V_132:
return V_17 ;
}
static int F_112 ( struct V_11 * V_12 , int V_58 , bool V_255 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_64 = & V_61 -> V_63 [ V_58 ] ;
T_1 V_86 [ 8 ] ;
int V_17 ;
V_17 = F_100 ( V_12 , V_58 , V_86 ) ;
switch ( V_17 ) {
case V_260 :
V_64 -> V_73 = V_75 ;
F_107 ( V_12 , V_58 , V_255 ) ;
goto V_132; break;
case V_72 :
V_64 -> V_73 = V_74 ;
F_107 ( V_12 , V_58 , V_255 ) ;
goto V_132; break;
case V_76 :
break;
}
if ( F_14 ( V_86 ) == 0 ) {
V_64 -> V_73 = V_77 ;
F_107 ( V_12 , V_58 , V_255 ) ;
} else if ( F_14 ( V_86 ) ==
F_14 ( V_64 -> V_86 ) ) {
F_12 ( L_54 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
F_28 ( V_12 , V_58 ) ;
} else
V_17 = F_111 ( V_12 , V_58 ) ;
V_132:
return V_17 ;
}
static int F_113 ( struct V_11 * V_12 , const int V_58 )
{
struct V_60 * V_61 = & V_12 -> V_62 ;
struct V_63 * V_261 = & V_61 -> V_63 [ V_58 ] ;
int V_17 = 0 ;
int V_20 ;
bool V_255 = true ;
F_12 ( L_55 ,
F_14 ( V_12 -> V_54 ) , V_58 ) ;
if ( F_14 ( V_261 -> V_86 ) != 0 ) {
for ( V_20 = 0 ; V_20 < V_61 -> V_116 ; V_20 ++ ) {
struct V_63 * V_64 = & V_61 -> V_63 [ V_20 ] ;
if ( V_20 == V_58 )
continue;
if ( F_14 ( V_64 -> V_86 ) ==
F_14 ( V_261 -> V_86 ) ) {
F_12 ( L_56
L_57 , V_58 , V_20 ) ;
V_255 = false ;
break;
}
}
V_17 = F_112 ( V_12 , V_58 , V_255 ) ;
} else
V_17 = F_111 ( V_12 , V_58 ) ;
return V_17 ;
}
int F_114 ( struct V_11 * V_245 )
{
int V_17 ;
struct V_11 * V_12 = NULL ;
V_17 = F_103 ( V_245 , & V_12 ) ;
if ( V_17 )
goto V_132;
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
} while ( V_20 < V_61 -> V_116 );
}
V_132:
return V_17 ;
}
int F_115 ( struct V_262 * V_24 , struct V_68 * V_69 ,
struct V_263 * V_13 )
{
struct V_11 * V_12 ;
int V_264 , type ;
struct V_263 * V_265 = V_13 -> V_266 ;
if ( ! V_265 ) {
F_116 ( L_58 ,
V_53 ) ;
return - V_267 ;
}
if ( ! V_69 )
return F_117 ( V_24 , V_13 , V_265 ) ;
type = V_69 -> V_94 . V_268 ;
if ( type != V_209 &&
type != V_211 ) {
F_116 ( L_59 ,
V_53 ) ;
return - V_267 ;
}
V_12 = F_45 ( V_69 ) ;
if ( ! V_12 ) {
F_116 ( L_60 , V_53 ) ;
return - V_267 ;
}
if ( V_13 -> V_269 -> V_270 > 1 || V_265 -> V_269 -> V_270 > 1 ) {
F_116 ( L_61 ,
V_53 , V_13 -> V_269 -> V_270 , F_118 ( V_13 ) ,
V_265 -> V_269 -> V_270 , F_118 ( V_265 ) ) ;
return - V_267 ;
}
V_264 = F_7 ( V_12 , F_119 ( V_13 -> V_269 ) , F_118 ( V_13 ) ,
F_119 ( V_265 -> V_269 ) , F_118 ( V_265 ) ) ;
if ( V_264 > 0 ) {
V_265 -> V_271 = V_264 ;
V_13 -> V_271 = 0 ;
V_264 = 0 ;
} else if ( V_264 == 0 ) {
V_265 -> V_271 = 0 ;
V_13 -> V_271 = 0 ;
}
return V_264 ;
}
