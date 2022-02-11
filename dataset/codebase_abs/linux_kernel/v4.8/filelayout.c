static T_1
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = V_2 -> V_5 * V_2 -> V_6 -> V_7 ;
T_3 V_8 ;
T_2 V_9 ;
V_3 -= V_2 -> V_10 ;
V_8 = F_2 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_5 , & V_9 ) ;
return V_8 * V_2 -> V_5 + V_9 ;
}
static T_1
F_4 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
return V_3 ;
case V_15 :
return F_1 ( V_2 , V_3 ) ;
}
F_6 () ;
}
static void F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
if ( ! F_8 ( V_20 , & V_17 -> V_21 ) ) {
F_9 ( L_1
L_2 , V_22 ,
V_17 -> V_19 . V_23 ,
V_17 -> V_24 -> V_25 -> V_26 ,
( unsigned long long ) F_10 ( V_17 -> V_24 ) ,
V_17 -> args . V_27 ,
( unsigned long long ) V_17 -> args . V_3 ) ;
V_19 -> V_28 = F_11 ( V_17 ) ;
}
}
static void F_12 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
if ( ! F_8 ( V_20 , & V_17 -> V_21 ) ) {
F_9 ( L_1
L_2 , V_22 ,
V_17 -> V_19 . V_23 ,
V_17 -> V_24 -> V_25 -> V_26 ,
( unsigned long long ) F_10 ( V_17 -> V_24 ) ,
V_17 -> args . V_27 ,
( unsigned long long ) V_17 -> args . V_3 ) ;
V_19 -> V_28 = F_13 ( V_17 ) ;
}
}
static int F_14 ( struct V_18 * V_19 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_35 ;
struct V_24 * V_24 = V_34 -> V_36 ;
struct V_37 * V_38 = F_15 ( V_24 ) ;
struct V_39 * V_40 = F_16 ( V_12 ) ;
struct V_31 * V_41 = V_38 -> V_31 ;
struct V_42 * V_43 = & V_32 -> V_44 -> V_45 ;
if ( V_19 -> V_28 >= 0 )
return 0 ;
switch ( V_19 -> V_28 ) {
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
if ( V_30 == NULL )
break;
if ( F_17 ( V_38 , V_30 ) < 0 )
goto V_50;
goto V_51;
case - V_52 :
if ( V_30 != NULL ) {
if ( F_17 ( V_38 , V_30 ) < 0 )
goto V_50;
}
F_18 ( V_41 ) ;
goto V_51;
case - V_53 :
case - V_54 :
case - V_55 :
case - V_56 :
case - V_57 :
case - V_58 :
case - V_59 :
F_9 ( L_3
L_4 , V_22 , V_19 -> V_28 ,
V_32 -> V_60 ) ;
F_19 ( V_32 -> V_44 , V_19 -> V_28 ) ;
break;
case - V_61 :
case - V_62 :
F_20 ( V_19 , V_63 ) ;
break;
case - V_64 :
break;
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_9 ( L_5 , V_22 ,
V_19 -> V_28 ) ;
F_21 ( F_22 ( V_24 ) ) ;
F_23 ( & V_43 -> V_71 ) ;
goto V_72;
case - V_73 :
case - V_74 :
case - V_75 :
case - V_76 :
case - V_77 :
case - V_78 :
case - V_79 :
F_9 ( L_6 , V_22 ,
V_19 -> V_28 ) ;
F_24 ( V_40 ) ;
F_25 ( V_24 , V_12 ) ;
F_26 ( V_12 ) ;
F_23 ( & V_43 -> V_71 ) ;
default:
V_72:
F_9 ( L_7 , V_22 ,
V_19 -> V_28 ) ;
return - V_80 ;
}
V_81:
V_19 -> V_28 = 0 ;
return - V_82 ;
V_50:
V_19 -> V_28 = - V_77 ;
return 0 ;
V_51:
F_27 ( & V_41 -> V_83 , V_19 , NULL ) ;
if ( F_28 ( V_84 , & V_41 -> V_85 ) == 0 )
F_29 ( & V_41 -> V_83 , V_19 ) ;
goto V_81;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_86 ;
F_31 ( V_17 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , V_17 -> args . V_87 -> V_30 ,
V_17 -> V_88 , V_17 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_12 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_82 :
F_32 ( V_19 ) ;
return - V_82 ;
}
return 0 ;
}
static void
F_33 ( struct V_16 * V_17 )
{
T_1 V_89 = 0 ;
if ( F_5 ( V_17 -> V_12 ) -> V_90 ||
V_17 -> V_91 . V_92 -> V_93 == V_94 )
return;
if ( V_17 -> V_91 . V_92 -> V_93 == V_95 )
V_89 = V_17 -> V_96 + ( T_1 ) V_17 -> V_91 . V_27 ;
F_34 ( V_17 -> V_24 , V_17 -> V_12 , V_89 ) ;
F_9 ( L_8 , V_22 , V_17 -> V_24 -> V_97 ,
( unsigned long ) F_22 ( V_17 -> V_24 ) -> V_98 -> V_99 ) ;
}
bool
F_35 ( struct V_39 * V_100 )
{
return F_36 ( V_100 ) ||
F_37 ( V_100 ) ;
}
static bool
F_38 ( struct V_11 * V_12 )
{
struct V_39 * V_100 = F_16 ( V_12 ) ;
return F_35 ( V_100 ) ;
}
static void F_39 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
if ( F_40 ( F_28 ( V_102 , & V_17 -> args . V_87 -> V_21 ) ) ) {
F_41 ( V_19 , - V_77 ) ;
return;
}
if ( F_38 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_12 ( V_17 ) ;
F_41 ( V_19 , 0 ) ;
return;
}
V_17 -> V_103 = F_30 ;
if ( F_42 ( V_17 -> V_88 -> V_44 ,
& V_17 -> args . V_104 ,
& V_17 -> V_91 . V_105 ,
V_19 ) )
return;
if ( F_43 ( & V_17 -> args . V_106 , V_17 -> args . V_87 ,
V_17 -> args . V_107 , V_108 ) == - V_77 )
F_41 ( V_19 , - V_77 ) ;
}
static void F_44 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
F_9 ( L_10 , V_22 , V_19 -> V_28 ) ;
if ( F_28 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_45 ( V_19 , & V_17 -> V_91 . V_105 ) ;
return;
}
V_17 -> V_109 -> V_110 ( V_19 , V_101 ) ;
}
static void F_46 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
F_47 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_111 -> V_112 ) ;
}
static int F_48 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_86 ;
F_49 ( V_17 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , V_17 -> args . V_87 -> V_30 ,
V_17 -> V_88 , V_17 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_7 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_82 :
F_32 ( V_19 ) ;
return - V_82 ;
}
F_33 ( V_17 ) ;
V_17 -> V_113 . V_114 = 0 ;
if ( V_19 -> V_28 >= 0 )
F_50 ( V_17 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_19 ,
struct V_115 * V_101 )
{
int V_86 ;
F_52 ( V_101 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , NULL , V_101 -> V_88 ,
V_101 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_53 ( V_101 ) ;
return - V_82 ;
case - V_82 :
F_32 ( V_19 ) ;
return - V_82 ;
}
F_34 ( V_101 -> V_24 , V_101 -> V_12 , V_101 -> V_116 ) ;
return 0 ;
}
static void F_54 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
if ( F_40 ( F_28 ( V_102 , & V_17 -> args . V_87 -> V_21 ) ) ) {
F_41 ( V_19 , - V_77 ) ;
return;
}
if ( F_38 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_7 ( V_17 ) ;
F_41 ( V_19 , 0 ) ;
return;
}
if ( F_42 ( V_17 -> V_88 -> V_44 ,
& V_17 -> args . V_104 ,
& V_17 -> V_91 . V_105 ,
V_19 ) )
return;
if ( F_43 ( & V_17 -> args . V_106 , V_17 -> args . V_87 ,
V_17 -> args . V_107 , V_117 ) == - V_77 )
F_41 ( V_19 , - V_77 ) ;
}
static void F_55 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
if ( F_28 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_45 ( V_19 , & V_17 -> V_91 . V_105 ) ;
return;
}
V_17 -> V_109 -> V_110 ( V_19 , V_101 ) ;
}
static void F_56 ( struct V_18 * V_19 , void * V_101 )
{
struct V_16 * V_17 = V_101 ;
F_47 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_111 -> V_112 ) ;
}
static void F_57 ( struct V_18 * V_19 , void * V_101 )
{
struct V_115 * V_118 = V_101 ;
F_42 ( V_118 -> V_88 -> V_44 ,
& V_118 -> args . V_104 ,
& V_118 -> V_91 . V_105 ,
V_19 ) ;
}
static void F_58 ( struct V_18 * V_19 , void * V_101 )
{
struct V_115 * V_119 = V_101 ;
F_47 ( V_19 , F_15 ( V_119 -> V_24 ) -> V_111 -> V_112 ) ;
}
static enum V_120
F_59 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_125 , V_126 ;
struct V_127 * V_128 ;
F_9 ( L_11 ,
V_22 , V_17 -> V_24 -> V_97 ,
V_17 -> args . V_129 , ( V_130 ) V_17 -> args . V_27 , V_3 ) ;
V_125 = F_60 ( V_12 , V_3 ) ;
V_126 = F_61 ( V_12 , V_125 ) ;
V_122 = F_62 ( V_12 , V_126 ) ;
if ( ! V_122 )
return V_131 ;
V_124 = F_63 ( V_122 -> V_88 , V_17 -> V_24 ) ;
if ( F_64 ( V_124 ) )
return V_131 ;
F_9 ( L_12 , V_22 ,
V_122 -> V_132 , F_65 ( & V_122 -> V_88 -> V_133 ) ) ;
F_66 ( & V_122 -> V_88 -> V_133 ) ;
V_17 -> V_88 = V_122 -> V_88 ;
V_17 -> V_134 = V_126 ;
V_128 = F_67 ( V_12 , V_125 ) ;
if ( V_128 )
V_17 -> args . V_128 = V_128 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_96 = V_3 ;
F_68 ( V_124 , V_17 , V_17 -> V_135 ,
F_69 ( V_17 -> V_24 ) , & V_136 ,
0 , V_137 ) ;
return V_138 ;
}
static enum V_120
F_70 ( struct V_16 * V_17 , int V_139 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_125 , V_126 ;
struct V_127 * V_128 ;
V_125 = F_60 ( V_12 , V_3 ) ;
V_126 = F_61 ( V_12 , V_125 ) ;
V_122 = F_62 ( V_12 , V_126 ) ;
if ( ! V_122 )
return V_131 ;
V_124 = F_63 ( V_122 -> V_88 , V_17 -> V_24 ) ;
if ( F_64 ( V_124 ) )
return V_131 ;
F_9 ( L_13 ,
V_22 , V_17 -> V_24 -> V_97 , V_139 , ( V_130 ) V_17 -> args . V_27 ,
V_3 , V_122 -> V_132 , F_65 ( & V_122 -> V_88 -> V_133 ) ) ;
V_17 -> V_103 = F_48 ;
F_66 ( & V_122 -> V_88 -> V_133 ) ;
V_17 -> V_88 = V_122 -> V_88 ;
V_17 -> V_134 = V_126 ;
V_128 = F_67 ( V_12 , V_125 ) ;
if ( V_128 )
V_17 -> args . V_128 = V_128 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_68 ( V_124 , V_17 , V_17 -> V_135 ,
F_69 ( V_17 -> V_24 ) , & V_140 ,
V_139 , V_137 ) ;
return V_138 ;
}
static int
F_71 ( struct V_33 * V_34 ,
struct V_1 * V_141 ,
struct V_142 * V_143 ,
struct V_144 * V_145 ,
T_4 V_146 )
{
struct V_39 * V_147 ;
struct V_148 * V_6 ;
int V_149 = - V_150 ;
F_9 ( L_14 , V_22 ) ;
if ( V_143 -> V_151 . V_3 != 0 ||
V_143 -> V_151 . V_152 != V_153 ) {
F_9 ( L_15 ,
V_22 ) ;
goto V_81;
}
if ( V_141 -> V_10 > V_143 -> V_151 . V_3 ) {
F_9 ( L_16 ,
V_22 , V_141 -> V_10 ) ;
goto V_81;
}
if ( ! V_141 -> V_5 ) {
F_9 ( L_17 ,
V_22 , V_141 -> V_5 ) ;
goto V_81;
}
V_147 = F_72 ( F_15 ( V_34 -> V_36 ) , V_145 ,
V_34 -> V_154 , V_146 ) ;
if ( V_147 == NULL )
goto V_81;
V_6 = F_73 ( V_147 , struct V_148 , V_155 ) ;
if ( F_35 ( & V_6 -> V_155 ) )
goto V_156;
V_141 -> V_6 = V_6 ;
if ( V_141 -> V_157 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_22 , V_141 -> V_157 ) ;
goto V_156;
}
if ( ( V_141 -> V_13 == V_14 &&
V_141 -> V_158 > 1 && V_141 -> V_158 != V_6 -> V_159 ) ||
( V_141 -> V_13 == V_15 &&
V_141 -> V_158 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_22 , V_141 -> V_158 ) ;
goto V_156;
}
V_149 = 0 ;
V_81:
F_9 ( L_20 , V_22 , V_149 ) ;
return V_149 ;
V_156:
F_74 ( V_6 ) ;
goto V_81;
}
static void F_75 ( struct V_1 * V_141 )
{
int V_160 ;
if ( V_141 -> V_161 ) {
for ( V_160 = 0 ; V_160 < V_141 -> V_158 ; V_160 ++ ) {
if ( ! V_141 -> V_161 [ V_160 ] )
break;
F_76 ( V_141 -> V_161 [ V_160 ] ) ;
}
F_76 ( V_141 -> V_161 ) ;
}
F_76 ( V_141 ) ;
}
static int
F_77 ( struct V_33 * V_162 ,
struct V_1 * V_141 ,
struct V_142 * V_143 ,
struct V_144 * V_145 ,
T_4 V_146 )
{
struct V_163 V_164 ;
struct V_165 V_166 ;
struct V_167 * V_168 ;
T_5 * V_169 ;
T_6 V_170 ;
int V_160 ;
F_9 ( L_21 , V_22 ) ;
V_168 = F_78 ( V_146 ) ;
if ( ! V_168 )
return - V_171 ;
F_79 ( & V_164 , & V_166 , V_143 -> V_172 -> V_173 , V_143 -> V_172 -> V_174 ) ;
F_80 ( & V_164 , F_81 ( V_168 ) , V_175 ) ;
V_169 = F_82 ( & V_164 , V_176 + 20 ) ;
if ( F_40 ( ! V_169 ) )
goto V_177;
memcpy ( V_145 , V_169 , sizeof( * V_145 ) ) ;
V_169 += F_83 ( V_176 ) ;
F_84 ( V_145 ) ;
V_170 = F_85 ( V_169 ++ ) ;
if ( V_170 & V_178 )
V_141 -> V_90 = 1 ;
if ( V_170 & V_179 )
V_141 -> V_13 = V_15 ;
else
V_141 -> V_13 = V_14 ;
V_141 -> V_5 = V_170 & ~ V_180 ;
V_141 -> V_157 = F_85 ( V_169 ++ ) ;
V_169 = F_86 ( V_169 , & V_141 -> V_10 ) ;
V_141 -> V_158 = F_85 ( V_169 ++ ) ;
F_9 ( L_22 ,
V_22 , V_170 , V_141 -> V_158 , V_141 -> V_157 ,
V_141 -> V_10 ) ;
if ( V_141 -> V_158 >
F_87 ( V_181 , V_182 ) )
goto V_177;
if ( V_141 -> V_158 > 0 ) {
V_141 -> V_161 = F_88 ( V_141 -> V_158 , sizeof( V_141 -> V_161 [ 0 ] ) ,
V_146 ) ;
if ( ! V_141 -> V_161 )
goto V_177;
}
for ( V_160 = 0 ; V_160 < V_141 -> V_158 ; V_160 ++ ) {
V_141 -> V_161 [ V_160 ] = F_89 ( sizeof( struct V_127 ) , V_146 ) ;
if ( ! V_141 -> V_161 [ V_160 ] )
goto V_177;
V_169 = F_82 ( & V_164 , 4 ) ;
if ( F_40 ( ! V_169 ) )
goto V_177;
V_141 -> V_161 [ V_160 ] -> V_183 = F_85 ( V_169 ++ ) ;
if ( sizeof( struct V_127 ) < V_141 -> V_161 [ V_160 ] -> V_183 ) {
F_90 ( V_184 L_23 ,
V_160 , V_141 -> V_161 [ V_160 ] -> V_183 ) ;
goto V_177;
}
V_169 = F_82 ( & V_164 , V_141 -> V_161 [ V_160 ] -> V_183 ) ;
if ( F_40 ( ! V_169 ) )
goto V_177;
memcpy ( V_141 -> V_161 [ V_160 ] -> V_101 , V_169 , V_141 -> V_161 [ V_160 ] -> V_183 ) ;
F_9 ( L_24 , V_22 ,
V_141 -> V_161 [ V_160 ] -> V_183 ) ;
}
F_91 ( V_168 ) ;
return 0 ;
V_177:
F_91 ( V_168 ) ;
return - V_77 ;
}
static void
F_92 ( struct V_11 * V_12 )
{
struct V_1 * V_141 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_22 ) ;
F_74 ( V_141 -> V_6 ) ;
if ( V_12 -> V_185 . V_186 == V_187 ) {
struct V_188 * V_162 ;
V_162 = F_93 ( V_12 -> V_35 ) ;
V_162 -> V_189 . V_190 = 0 ;
F_76 ( V_162 -> V_189 . V_191 ) ;
V_162 -> V_189 . V_191 = NULL ;
}
F_75 ( V_141 ) ;
}
static int
F_94 ( struct V_11 * V_12 ,
struct V_192 * V_193 ,
T_4 V_146 )
{
struct V_1 * V_141 = F_5 ( V_12 ) ;
struct V_194 * V_191 ;
int V_183 , V_160 ;
if ( V_141 -> V_90 )
return 0 ;
V_183 = ( V_141 -> V_13 == V_14 ) ?
V_141 -> V_6 -> V_159 : V_141 -> V_6 -> V_7 ;
if ( V_193 -> V_122 -> V_190 >= V_183 ) {
return 0 ;
}
V_191 = F_88 ( V_183 , sizeof( struct V_194 ) ,
V_146 ) ;
if ( ! V_191 )
return - V_171 ;
for ( V_160 = 0 ; V_160 < V_183 ; V_160 ++ ) {
F_95 ( & V_191 [ V_160 ] . V_195 ) ;
F_95 ( & V_191 [ V_160 ] . V_196 ) ;
V_191 [ V_160 ] . V_197 . V_93 = V_198 ;
}
F_96 ( & V_193 -> V_24 -> V_199 ) ;
if ( V_193 -> V_122 -> V_190 >= V_183 )
goto V_81;
for ( V_160 = 0 ; V_160 < V_193 -> V_122 -> V_190 ; V_160 ++ ) {
F_97 ( & V_193 -> V_122 -> V_191 [ V_160 ] . V_195 ,
& V_191 [ V_160 ] . V_195 ) ;
F_97 ( & V_193 -> V_122 -> V_191 [ V_160 ] . V_196 ,
& V_191 [ V_160 ] . V_196 ) ;
V_191 [ V_160 ] . V_197 . V_93 =
V_193 -> V_122 -> V_191 [ V_160 ] . V_197 . V_93 ;
V_191 [ V_160 ] . V_200 = V_193 -> V_122 -> V_191 [ V_160 ] . V_200 ;
V_191 [ V_160 ] . V_201 = V_193 -> V_122 -> V_191 [ V_160 ] . V_201 ;
}
F_98 ( V_193 -> V_122 -> V_191 , V_191 ) ;
V_193 -> V_122 -> V_190 = V_183 ;
V_81:
F_99 ( & V_193 -> V_24 -> V_199 ) ;
F_76 ( V_191 ) ;
return 0 ;
}
static struct V_11 *
F_100 ( struct V_33 * V_202 ,
struct V_142 * V_143 ,
T_4 V_146 )
{
struct V_1 * V_141 ;
int V_203 ;
struct V_144 V_145 ;
F_9 ( L_14 , V_22 ) ;
V_141 = F_101 ( sizeof( * V_141 ) , V_146 ) ;
if ( ! V_141 )
return NULL ;
V_203 = F_77 ( V_202 , V_141 , V_143 , & V_145 , V_146 ) ;
if ( V_203 != 0 || F_71 ( V_202 , V_141 , V_143 , & V_145 , V_146 ) ) {
F_75 ( V_141 ) ;
return NULL ;
}
return & V_141 -> V_204 ;
}
static V_130
F_102 ( struct V_205 * V_206 , struct V_207 * V_208 ,
struct V_207 * V_209 )
{
unsigned int V_183 ;
T_3 V_210 , V_211 ;
T_2 V_212 ;
T_3 V_213 = V_206 -> V_214 -> V_185 . V_3 ;
T_2 V_5 = F_5 ( V_206 -> V_214 ) -> V_5 ;
V_183 = F_103 ( V_206 , V_208 , V_209 ) ;
if ( ! V_183 )
return 0 ;
if ( V_208 ) {
V_210 = ( T_3 ) F_104 ( V_208 ) - V_213 ;
V_211 = ( T_3 ) F_104 ( V_209 ) - V_213 ;
F_105 ( V_210 , V_5 ) ;
F_105 ( V_211 , V_5 ) ;
if ( V_210 != V_211 )
return 0 ;
}
F_3 ( ( T_3 ) F_104 ( V_209 ) - V_213 ,
V_5 ,
& V_212 ) ;
F_106 ( V_212 > V_5 ) ;
if ( V_212 >= V_5 )
return 0 ;
return F_107 ( V_5 - ( unsigned int ) V_212 , V_183 ) ;
}
static void
F_108 ( struct V_205 * V_206 ,
struct V_207 * V_209 )
{
if ( ! V_206 -> V_214 ) {
V_206 -> V_214 = F_109 ( V_206 -> V_215 ,
V_209 -> V_216 ,
0 ,
V_153 ,
V_217 ,
false ,
V_218 ) ;
if ( F_64 ( V_206 -> V_214 ) ) {
V_206 -> V_219 = F_110 ( V_206 -> V_214 ) ;
V_206 -> V_214 = NULL ;
return;
}
}
if ( V_206 -> V_214 == NULL )
F_111 ( V_206 ) ;
}
static void
F_112 ( struct V_205 * V_206 ,
struct V_207 * V_209 )
{
struct V_192 V_193 ;
int V_149 ;
if ( ! V_206 -> V_214 ) {
V_206 -> V_214 = F_109 ( V_206 -> V_215 ,
V_209 -> V_216 ,
0 ,
V_153 ,
V_187 ,
false ,
V_220 ) ;
if ( F_64 ( V_206 -> V_214 ) ) {
V_206 -> V_219 = F_110 ( V_206 -> V_214 ) ;
V_206 -> V_214 = NULL ;
return;
}
}
if ( V_206 -> V_214 == NULL )
goto V_221;
F_113 ( & V_193 , V_206 -> V_215 , V_206 -> V_222 ) ;
V_149 = F_94 ( V_206 -> V_214 , & V_193 , V_220 ) ;
if ( V_149 < 0 ) {
F_114 ( V_206 -> V_214 ) ;
V_206 -> V_214 = NULL ;
goto V_221;
}
return;
V_221:
F_115 ( V_206 ) ;
}
static T_2 F_116 ( struct V_1 * V_141 , T_2 V_125 )
{
if ( V_141 -> V_13 == V_14 )
return F_61 ( & V_141 -> V_204 , V_125 ) ;
else
return V_125 ;
}
static void
F_117 ( struct V_207 * V_209 ,
struct V_11 * V_12 ,
struct V_192 * V_193 ,
T_2 V_134 )
{
struct V_1 * V_141 = F_5 ( V_12 ) ;
T_2 V_160 , V_125 ;
if ( V_141 -> V_90 ) {
F_118 ( V_209 , V_193 ) ;
} else {
V_125 = F_60 ( V_12 , F_104 ( V_209 ) ) ;
V_160 = F_116 ( V_141 , V_125 ) ;
F_119 ( V_209 , V_12 , V_193 , V_160 ) ;
}
}
static T_2 F_120 ( struct V_11 * V_12 , T_2 V_160 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_160 ;
else
return F_61 ( V_12 , V_160 ) ;
}
static struct V_127 *
F_121 ( struct V_11 * V_12 , T_2 V_160 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_158 == 1 )
V_160 = 0 ;
else if ( V_2 -> V_158 == 0 )
return NULL ;
}
return V_2 -> V_161 [ V_160 ] ;
}
static int F_122 ( struct V_115 * V_101 , int V_223 )
{
struct V_11 * V_12 = V_101 -> V_12 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
T_2 V_126 ;
struct V_127 * V_128 ;
V_126 = F_120 ( V_12 , V_101 -> V_224 ) ;
V_122 = F_62 ( V_12 , V_126 ) ;
if ( ! V_122 )
goto V_177;
V_124 = F_63 ( V_122 -> V_88 , V_101 -> V_24 ) ;
if ( F_64 ( V_124 ) )
goto V_177;
F_9 ( L_25 , V_22 ,
V_101 -> V_24 -> V_97 , V_223 , F_65 ( & V_122 -> V_88 -> V_133 ) ) ;
V_101 -> V_225 = F_51 ;
F_66 ( & V_122 -> V_88 -> V_133 ) ;
V_101 -> V_88 = V_122 -> V_88 ;
V_128 = F_121 ( V_12 , V_101 -> V_224 ) ;
if ( V_128 )
V_101 -> args . V_128 = V_128 ;
return F_123 ( V_124 , V_101 , F_69 ( V_101 -> V_24 ) ,
& V_226 , V_223 ,
V_137 ) ;
V_177:
F_53 ( V_101 ) ;
F_124 ( V_101 ) ;
return - V_82 ;
}
static struct V_207 *
F_125 ( struct V_192 * V_193 , struct V_167 * V_167 )
{
struct V_207 * V_227 , * V_228 ;
struct V_194 * V_229 ;
int V_160 ;
for ( V_160 = 0 , V_229 = V_193 -> V_122 -> V_191 ; V_160 < V_193 -> V_122 -> V_190 ; V_160 ++ , V_229 ++ ) {
F_126 (freq, t, &b->written, wb_list) {
if ( V_227 -> V_230 == V_167 )
return V_227 -> V_231 ;
}
F_126 (freq, t, &b->committing, wb_list) {
if ( V_227 -> V_230 == V_167 )
return V_227 -> V_231 ;
}
}
return NULL ;
}
static int
F_127 ( struct V_24 * V_24 , struct V_232 * V_233 ,
int V_223 , struct V_192 * V_193 )
{
return F_128 ( V_24 , V_233 , V_223 , V_193 ,
F_122 ) ;
}
static struct V_39 *
F_129 ( struct V_37 * V_234 ,
struct V_235 * V_236 , T_4 V_146 )
{
struct V_148 * V_6 ;
V_6 = F_130 ( V_234 , V_236 , V_146 ) ;
if ( ! V_6 )
return NULL ;
return & V_6 -> V_155 ;
}
static void
F_131 ( struct V_39 * V_147 )
{
F_132 ( F_73 ( V_147 , struct V_148 , V_155 ) ) ;
}
static struct V_33 *
F_133 ( struct V_24 * V_24 , T_4 V_146 )
{
struct V_188 * V_162 ;
V_162 = F_101 ( sizeof( * V_162 ) , V_146 ) ;
return V_162 != NULL ? & V_162 -> V_204 : NULL ;
}
static void
F_134 ( struct V_33 * V_34 )
{
F_76 ( F_93 ( V_34 ) ) ;
}
static struct V_237 *
F_135 ( struct V_24 * V_24 )
{
struct V_33 * V_98 = F_22 ( V_24 ) -> V_98 ;
if ( V_98 == NULL )
return NULL ;
else
return & F_93 ( V_98 ) -> V_189 ;
}
static int T_7 F_136 ( void )
{
F_90 ( V_238 L_26 ,
V_22 ) ;
return F_137 ( & V_239 ) ;
}
static void T_8 F_138 ( void )
{
F_90 ( V_238 L_27 ,
V_22 ) ;
F_139 ( & V_239 ) ;
}
