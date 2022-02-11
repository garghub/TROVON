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
F_26 ( & V_41 -> V_83 , V_19 , NULL ) ;
if ( F_27 ( V_84 , & V_41 -> V_85 ) == 0 )
F_28 ( & V_41 -> V_83 , V_19 ) ;
goto V_81;
}
static int F_29 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_86 ;
F_30 ( V_17 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , V_17 -> args . V_87 -> V_30 ,
V_17 -> V_88 , V_17 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_12 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_82 :
F_31 ( V_19 ) ;
return - V_82 ;
}
return 0 ;
}
static void
F_32 ( struct V_16 * V_17 )
{
if ( F_5 ( V_17 -> V_12 ) -> V_89 ||
V_17 -> V_90 . V_91 -> V_92 != V_93 )
return;
F_33 ( V_17 ) ;
F_9 ( L_8 , V_22 , V_17 -> V_24 -> V_94 ,
( unsigned long ) F_22 ( V_17 -> V_24 ) -> V_95 -> V_96 ) ;
}
bool
F_34 ( struct V_39 * V_97 )
{
return F_35 ( V_97 ) ||
F_36 ( V_97 ) ;
}
static bool
F_37 ( struct V_11 * V_12 )
{
struct V_39 * V_97 = F_16 ( V_12 ) ;
return F_34 ( V_97 ) ;
}
static void F_38 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
if ( F_39 ( F_27 ( V_99 , & V_17 -> args . V_87 -> V_21 ) ) ) {
F_40 ( V_19 , - V_77 ) ;
return;
}
if ( F_37 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_12 ( V_17 ) ;
F_40 ( V_19 , 0 ) ;
return;
}
V_17 -> V_100 = F_29 ;
if ( F_41 ( V_17 -> V_88 -> V_44 ,
& V_17 -> args . V_101 ,
& V_17 -> V_90 . V_102 ,
V_19 ) )
return;
if ( F_42 ( & V_17 -> args . V_103 , V_17 -> args . V_87 ,
V_17 -> args . V_104 , V_105 ) == - V_77 )
F_40 ( V_19 , - V_77 ) ;
}
static void F_43 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
F_9 ( L_10 , V_22 , V_19 -> V_28 ) ;
if ( F_27 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_44 ( V_19 , & V_17 -> V_90 . V_102 ) ;
return;
}
V_17 -> V_106 -> V_107 ( V_19 , V_98 ) ;
}
static void F_45 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
F_46 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_108 -> V_109 ) ;
}
static int F_47 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_86 ;
F_48 ( V_17 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , V_17 -> args . V_87 -> V_30 ,
V_17 -> V_88 , V_17 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_7 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_82 :
F_31 ( V_19 ) ;
return - V_82 ;
}
F_32 ( V_17 ) ;
return 0 ;
}
static int F_49 ( struct V_18 * V_19 ,
struct V_110 * V_98 )
{
int V_86 ;
F_50 ( V_98 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , NULL , V_98 -> V_88 ,
V_98 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_51 ( V_98 ) ;
return - V_82 ;
case - V_82 :
F_31 ( V_19 ) ;
return - V_82 ;
}
if ( V_98 -> V_91 . V_92 == V_111 )
F_52 ( V_98 ) ;
return 0 ;
}
static void F_53 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
if ( F_39 ( F_27 ( V_99 , & V_17 -> args . V_87 -> V_21 ) ) ) {
F_40 ( V_19 , - V_77 ) ;
return;
}
if ( F_37 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_7 ( V_17 ) ;
F_40 ( V_19 , 0 ) ;
return;
}
if ( F_41 ( V_17 -> V_88 -> V_44 ,
& V_17 -> args . V_101 ,
& V_17 -> V_90 . V_102 ,
V_19 ) )
return;
if ( F_42 ( & V_17 -> args . V_103 , V_17 -> args . V_87 ,
V_17 -> args . V_104 , V_112 ) == - V_77 )
F_40 ( V_19 , - V_77 ) ;
}
static void F_54 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
if ( F_27 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_44 ( V_19 , & V_17 -> V_90 . V_102 ) ;
return;
}
V_17 -> V_106 -> V_107 ( V_19 , V_98 ) ;
}
static void F_55 ( struct V_18 * V_19 , void * V_98 )
{
struct V_16 * V_17 = V_98 ;
F_46 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_108 -> V_109 ) ;
}
static void F_56 ( struct V_18 * V_19 , void * V_98 )
{
struct V_110 * V_113 = V_98 ;
F_41 ( V_113 -> V_88 -> V_44 ,
& V_113 -> args . V_101 ,
& V_113 -> V_90 . V_102 ,
V_19 ) ;
}
static void F_57 ( struct V_18 * V_19 , void * V_98 )
{
struct V_110 * V_114 = V_98 ;
F_46 ( V_19 , F_15 ( V_114 -> V_24 ) -> V_108 -> V_109 ) ;
}
static enum V_115
F_58 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_120 , V_121 ;
struct V_122 * V_123 ;
F_9 ( L_11 ,
V_22 , V_17 -> V_24 -> V_94 ,
V_17 -> args . V_124 , ( V_125 ) V_17 -> args . V_27 , V_3 ) ;
V_120 = F_59 ( V_12 , V_3 ) ;
V_121 = F_60 ( V_12 , V_120 ) ;
V_117 = F_61 ( V_12 , V_121 ) ;
if ( ! V_117 )
return V_126 ;
V_119 = F_62 ( V_117 -> V_88 , V_17 -> V_24 ) ;
if ( F_63 ( V_119 ) )
return V_126 ;
F_9 ( L_12 , V_22 ,
V_117 -> V_127 , F_64 ( & V_117 -> V_88 -> V_128 ) ) ;
F_65 ( & V_117 -> V_88 -> V_128 ) ;
V_17 -> V_88 = V_117 -> V_88 ;
V_17 -> V_129 = V_121 ;
V_123 = F_66 ( V_12 , V_120 ) ;
if ( V_123 )
V_17 -> args . V_123 = V_123 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_130 = V_3 ;
F_67 ( V_119 , V_17 , V_17 -> V_131 ,
F_68 ( V_17 -> V_24 ) , & V_132 ,
0 , V_133 ) ;
return V_134 ;
}
static enum V_115
F_69 ( struct V_16 * V_17 , int V_135 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_120 , V_121 ;
struct V_122 * V_123 ;
V_120 = F_59 ( V_12 , V_3 ) ;
V_121 = F_60 ( V_12 , V_120 ) ;
V_117 = F_61 ( V_12 , V_121 ) ;
if ( ! V_117 )
return V_126 ;
V_119 = F_62 ( V_117 -> V_88 , V_17 -> V_24 ) ;
if ( F_63 ( V_119 ) )
return V_126 ;
F_9 ( L_13 ,
V_22 , V_17 -> V_24 -> V_94 , V_135 , ( V_125 ) V_17 -> args . V_27 ,
V_3 , V_117 -> V_127 , F_64 ( & V_117 -> V_88 -> V_128 ) ) ;
V_17 -> V_100 = F_47 ;
F_65 ( & V_117 -> V_88 -> V_128 ) ;
V_17 -> V_88 = V_117 -> V_88 ;
V_17 -> V_129 = V_121 ;
V_123 = F_66 ( V_12 , V_120 ) ;
if ( V_123 )
V_17 -> args . V_123 = V_123 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_67 ( V_119 , V_17 , V_17 -> V_131 ,
F_68 ( V_17 -> V_24 ) , & V_136 ,
V_135 , V_133 ) ;
return V_134 ;
}
static int
F_70 ( struct V_33 * V_34 ,
struct V_1 * V_137 ,
struct V_138 * V_139 ,
struct V_140 * V_141 ,
T_4 V_142 )
{
struct V_39 * V_143 ;
struct V_144 * V_6 ;
int V_145 = - V_146 ;
F_9 ( L_14 , V_22 ) ;
if ( V_139 -> V_147 . V_3 != 0 ||
V_139 -> V_147 . V_148 != V_149 ) {
F_9 ( L_15 ,
V_22 ) ;
goto V_81;
}
if ( V_137 -> V_10 > V_139 -> V_147 . V_3 ) {
F_9 ( L_16 ,
V_22 , V_137 -> V_10 ) ;
goto V_81;
}
if ( ! V_137 -> V_5 ) {
F_9 ( L_17 ,
V_22 , V_137 -> V_5 ) ;
goto V_81;
}
V_143 = F_71 ( F_15 ( V_34 -> V_36 ) , V_141 ,
V_34 -> V_150 , V_142 ) ;
if ( V_143 == NULL )
goto V_81;
V_6 = F_72 ( V_143 , struct V_144 , V_151 ) ;
if ( F_34 ( & V_6 -> V_151 ) )
goto V_152;
V_137 -> V_6 = V_6 ;
if ( V_137 -> V_153 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_22 , V_137 -> V_153 ) ;
goto V_152;
}
if ( ( V_137 -> V_13 == V_14 &&
V_137 -> V_154 > 1 && V_137 -> V_154 != V_6 -> V_155 ) ||
( V_137 -> V_13 == V_15 &&
V_137 -> V_154 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_22 , V_137 -> V_154 ) ;
goto V_152;
}
V_145 = 0 ;
V_81:
F_9 ( L_20 , V_22 , V_145 ) ;
return V_145 ;
V_152:
F_73 ( V_6 ) ;
goto V_81;
}
static void F_74 ( struct V_1 * V_137 )
{
int V_156 ;
for ( V_156 = 0 ; V_156 < V_137 -> V_154 ; V_156 ++ ) {
if ( ! V_137 -> V_157 [ V_156 ] )
break;
F_75 ( V_137 -> V_157 [ V_156 ] ) ;
}
F_75 ( V_137 -> V_157 ) ;
V_137 -> V_157 = NULL ;
}
static void
F_76 ( struct V_1 * V_137 )
{
F_74 ( V_137 ) ;
F_75 ( V_137 ) ;
}
static int
F_77 ( struct V_33 * V_158 ,
struct V_1 * V_137 ,
struct V_138 * V_139 ,
struct V_140 * V_141 ,
T_4 V_142 )
{
struct V_159 V_160 ;
struct V_161 V_162 ;
struct V_163 * V_164 ;
T_5 * V_165 ;
T_6 V_166 ;
int V_156 ;
F_9 ( L_21 , V_22 ) ;
V_164 = F_78 ( V_142 ) ;
if ( ! V_164 )
return - V_167 ;
F_79 ( & V_160 , & V_162 , V_139 -> V_168 -> V_169 , V_139 -> V_168 -> V_170 ) ;
F_80 ( & V_160 , F_81 ( V_164 ) , V_171 ) ;
V_165 = F_82 ( & V_160 , V_172 + 20 ) ;
if ( F_39 ( ! V_165 ) )
goto V_173;
memcpy ( V_141 , V_165 , sizeof( * V_141 ) ) ;
V_165 += F_83 ( V_172 ) ;
F_84 ( V_141 ) ;
V_166 = F_85 ( V_165 ++ ) ;
if ( V_166 & V_174 )
V_137 -> V_89 = 1 ;
if ( V_166 & V_175 )
V_137 -> V_13 = V_15 ;
else
V_137 -> V_13 = V_14 ;
V_137 -> V_5 = V_166 & ~ V_176 ;
V_137 -> V_153 = F_85 ( V_165 ++ ) ;
V_165 = F_86 ( V_165 , & V_137 -> V_10 ) ;
V_137 -> V_154 = F_85 ( V_165 ++ ) ;
F_9 ( L_22 ,
V_22 , V_166 , V_137 -> V_154 , V_137 -> V_153 ,
V_137 -> V_10 ) ;
if ( V_137 -> V_154 >
F_87 ( V_177 , V_178 ) )
goto V_173;
if ( V_137 -> V_154 > 0 ) {
V_137 -> V_157 = F_88 ( V_137 -> V_154 , sizeof( V_137 -> V_157 [ 0 ] ) ,
V_142 ) ;
if ( ! V_137 -> V_157 )
goto V_173;
}
for ( V_156 = 0 ; V_156 < V_137 -> V_154 ; V_156 ++ ) {
V_137 -> V_157 [ V_156 ] = F_89 ( sizeof( struct V_122 ) , V_142 ) ;
if ( ! V_137 -> V_157 [ V_156 ] )
goto V_179;
V_165 = F_82 ( & V_160 , 4 ) ;
if ( F_39 ( ! V_165 ) )
goto V_179;
V_137 -> V_157 [ V_156 ] -> V_180 = F_85 ( V_165 ++ ) ;
if ( sizeof( struct V_122 ) < V_137 -> V_157 [ V_156 ] -> V_180 ) {
F_90 ( V_181 L_23 ,
V_156 , V_137 -> V_157 [ V_156 ] -> V_180 ) ;
goto V_179;
}
V_165 = F_82 ( & V_160 , V_137 -> V_157 [ V_156 ] -> V_180 ) ;
if ( F_39 ( ! V_165 ) )
goto V_179;
memcpy ( V_137 -> V_157 [ V_156 ] -> V_98 , V_165 , V_137 -> V_157 [ V_156 ] -> V_180 ) ;
F_9 ( L_24 , V_22 ,
V_137 -> V_157 [ V_156 ] -> V_180 ) ;
}
F_91 ( V_164 ) ;
return 0 ;
V_179:
F_74 ( V_137 ) ;
V_173:
F_91 ( V_164 ) ;
return - V_77 ;
}
static void
F_92 ( struct V_11 * V_12 )
{
struct V_1 * V_137 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_22 ) ;
F_73 ( V_137 -> V_6 ) ;
if ( V_12 -> V_182 . V_183 == V_184 ) {
struct V_185 * V_158 ;
V_158 = F_93 ( V_12 -> V_35 ) ;
V_158 -> V_186 . V_187 = 0 ;
F_75 ( V_158 -> V_186 . V_188 ) ;
V_158 -> V_186 . V_188 = NULL ;
}
F_76 ( V_137 ) ;
}
static int
F_94 ( struct V_11 * V_12 ,
struct V_189 * V_190 ,
T_4 V_142 )
{
struct V_1 * V_137 = F_5 ( V_12 ) ;
struct V_191 * V_188 ;
int V_180 , V_156 ;
if ( V_137 -> V_89 )
return 0 ;
V_180 = ( V_137 -> V_13 == V_14 ) ?
V_137 -> V_6 -> V_155 : V_137 -> V_6 -> V_7 ;
if ( V_190 -> V_117 -> V_187 >= V_180 ) {
return 0 ;
}
V_188 = F_88 ( V_180 , sizeof( struct V_191 ) ,
V_142 ) ;
if ( ! V_188 )
return - V_167 ;
for ( V_156 = 0 ; V_156 < V_180 ; V_156 ++ ) {
F_95 ( & V_188 [ V_156 ] . V_192 ) ;
F_95 ( & V_188 [ V_156 ] . V_193 ) ;
V_188 [ V_156 ] . V_194 . V_92 = V_195 ;
}
F_96 ( V_190 -> V_196 ) ;
if ( V_190 -> V_117 -> V_187 >= V_180 )
goto V_81;
for ( V_156 = 0 ; V_156 < V_190 -> V_117 -> V_187 ; V_156 ++ ) {
F_97 ( & V_190 -> V_117 -> V_188 [ V_156 ] . V_192 ,
& V_188 [ V_156 ] . V_192 ) ;
F_97 ( & V_190 -> V_117 -> V_188 [ V_156 ] . V_193 ,
& V_188 [ V_156 ] . V_193 ) ;
V_188 [ V_156 ] . V_194 . V_92 =
V_190 -> V_117 -> V_188 [ V_156 ] . V_194 . V_92 ;
V_188 [ V_156 ] . V_197 = V_190 -> V_117 -> V_188 [ V_156 ] . V_197 ;
V_188 [ V_156 ] . V_198 = V_190 -> V_117 -> V_188 [ V_156 ] . V_198 ;
}
F_98 ( V_190 -> V_117 -> V_188 , V_188 ) ;
V_190 -> V_117 -> V_187 = V_180 ;
V_81:
F_99 ( V_190 -> V_196 ) ;
F_75 ( V_188 ) ;
return 0 ;
}
static struct V_11 *
F_100 ( struct V_33 * V_199 ,
struct V_138 * V_139 ,
T_4 V_142 )
{
struct V_1 * V_137 ;
int V_200 ;
struct V_140 V_141 ;
F_9 ( L_14 , V_22 ) ;
V_137 = F_101 ( sizeof( * V_137 ) , V_142 ) ;
if ( ! V_137 )
return NULL ;
V_200 = F_77 ( V_199 , V_137 , V_139 , & V_141 , V_142 ) ;
if ( V_200 != 0 || F_70 ( V_199 , V_137 , V_139 , & V_141 , V_142 ) ) {
F_76 ( V_137 ) ;
return NULL ;
}
return & V_137 -> V_201 ;
}
static V_125
F_102 ( struct V_202 * V_203 , struct V_204 * V_205 ,
struct V_204 * V_206 )
{
unsigned int V_180 ;
T_3 V_207 , V_208 ;
T_2 V_209 ;
T_3 V_210 = V_203 -> V_211 -> V_182 . V_3 ;
T_2 V_5 = F_5 ( V_203 -> V_211 ) -> V_5 ;
V_180 = F_103 ( V_203 , V_205 , V_206 ) ;
if ( ! V_180 )
return 0 ;
if ( V_205 ) {
V_207 = ( T_3 ) F_104 ( V_205 ) - V_210 ;
V_208 = ( T_3 ) F_104 ( V_206 ) - V_210 ;
F_105 ( V_207 , V_5 ) ;
F_105 ( V_208 , V_5 ) ;
if ( V_207 != V_208 )
return 0 ;
}
F_3 ( ( T_3 ) F_104 ( V_206 ) - V_210 ,
V_5 ,
& V_209 ) ;
F_106 ( V_209 > V_5 ) ;
if ( V_209 >= V_5 )
return 0 ;
return F_107 ( V_5 - ( unsigned int ) V_209 , V_180 ) ;
}
static void
F_108 ( struct V_202 * V_203 ,
struct V_204 * V_206 )
{
if ( ! V_203 -> V_211 )
V_203 -> V_211 = F_109 ( V_203 -> V_212 ,
V_206 -> V_213 ,
0 ,
V_149 ,
V_214 ,
V_215 ) ;
if ( V_203 -> V_211 == NULL )
F_110 ( V_203 ) ;
}
static void
F_111 ( struct V_202 * V_203 ,
struct V_204 * V_206 )
{
struct V_189 V_190 ;
int V_145 ;
if ( ! V_203 -> V_211 )
V_203 -> V_211 = F_109 ( V_203 -> V_212 ,
V_206 -> V_213 ,
0 ,
V_149 ,
V_184 ,
V_216 ) ;
if ( V_203 -> V_211 == NULL )
goto V_217;
F_112 ( & V_190 , V_203 -> V_212 , V_203 -> V_218 ) ;
V_145 = F_94 ( V_203 -> V_211 , & V_190 , V_216 ) ;
if ( V_145 < 0 ) {
F_113 ( V_203 -> V_211 ) ;
V_203 -> V_211 = NULL ;
goto V_217;
}
return;
V_217:
F_114 ( V_203 ) ;
}
static T_2 F_115 ( struct V_1 * V_137 , T_2 V_120 )
{
if ( V_137 -> V_13 == V_14 )
return F_60 ( & V_137 -> V_201 , V_120 ) ;
else
return V_120 ;
}
static void
F_116 ( struct V_204 * V_206 ,
struct V_11 * V_12 ,
struct V_189 * V_190 ,
T_2 V_129 )
{
struct V_1 * V_137 = F_5 ( V_12 ) ;
T_2 V_156 , V_120 ;
if ( V_137 -> V_89 ) {
F_117 ( V_206 , & V_190 -> V_219 -> V_220 , V_190 ) ;
} else {
V_120 = F_59 ( V_12 , F_104 ( V_206 ) ) ;
V_156 = F_115 ( V_137 , V_120 ) ;
F_118 ( V_206 , V_12 , V_190 , V_156 ) ;
}
}
static T_2 F_119 ( struct V_11 * V_12 , T_2 V_156 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_156 ;
else
return F_60 ( V_12 , V_156 ) ;
}
static struct V_122 *
F_120 ( struct V_11 * V_12 , T_2 V_156 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_154 == 1 )
V_156 = 0 ;
else if ( V_2 -> V_154 == 0 )
return NULL ;
}
return V_2 -> V_157 [ V_156 ] ;
}
static int F_121 ( struct V_110 * V_98 , int V_221 )
{
struct V_11 * V_12 = V_98 -> V_12 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
T_2 V_121 ;
struct V_122 * V_123 ;
V_121 = F_119 ( V_12 , V_98 -> V_222 ) ;
V_117 = F_61 ( V_12 , V_121 ) ;
if ( ! V_117 )
goto V_173;
V_119 = F_62 ( V_117 -> V_88 , V_98 -> V_24 ) ;
if ( F_63 ( V_119 ) )
goto V_173;
F_9 ( L_25 , V_22 ,
V_98 -> V_24 -> V_94 , V_221 , F_64 ( & V_117 -> V_88 -> V_128 ) ) ;
V_98 -> V_223 = F_49 ;
F_65 ( & V_117 -> V_88 -> V_128 ) ;
V_98 -> V_88 = V_117 -> V_88 ;
V_123 = F_120 ( V_12 , V_98 -> V_222 ) ;
if ( V_123 )
V_98 -> args . V_123 = V_123 ;
return F_122 ( V_119 , V_98 , F_68 ( V_98 -> V_24 ) ,
& V_224 , V_221 ,
V_133 ) ;
V_173:
F_51 ( V_98 ) ;
F_123 ( V_98 ) ;
return - V_82 ;
}
static struct V_204 *
F_124 ( struct V_189 * V_190 , struct V_163 * V_163 )
{
struct V_204 * V_225 , * V_226 ;
struct V_191 * V_227 ;
int V_156 ;
for ( V_156 = 0 , V_227 = V_190 -> V_117 -> V_188 ; V_156 < V_190 -> V_117 -> V_187 ; V_156 ++ , V_227 ++ ) {
F_125 (freq, t, &b->written, wb_list) {
if ( V_225 -> V_228 == V_163 )
return V_225 -> V_229 ;
}
F_125 (freq, t, &b->committing, wb_list) {
if ( V_225 -> V_228 == V_163 )
return V_225 -> V_229 ;
}
}
return NULL ;
}
static int
F_126 ( struct V_24 * V_24 , struct V_230 * V_231 ,
int V_221 , struct V_189 * V_190 )
{
return F_127 ( V_24 , V_231 , V_221 , V_190 ,
F_121 ) ;
}
static struct V_39 *
F_128 ( struct V_37 * V_232 ,
struct V_233 * V_234 , T_4 V_142 )
{
struct V_144 * V_6 ;
V_6 = F_129 ( V_232 , V_234 , V_142 ) ;
if ( ! V_6 )
return NULL ;
return & V_6 -> V_151 ;
}
static void
F_130 ( struct V_39 * V_143 )
{
F_131 ( F_72 ( V_143 , struct V_144 , V_151 ) ) ;
}
static struct V_33 *
F_132 ( struct V_24 * V_24 , T_4 V_142 )
{
struct V_185 * V_158 ;
V_158 = F_101 ( sizeof( * V_158 ) , V_142 ) ;
return V_158 != NULL ? & V_158 -> V_201 : NULL ;
}
static void
F_133 ( struct V_33 * V_34 )
{
F_75 ( F_93 ( V_34 ) ) ;
}
static struct V_235 *
F_134 ( struct V_24 * V_24 )
{
struct V_33 * V_95 = F_22 ( V_24 ) -> V_95 ;
if ( V_95 == NULL )
return NULL ;
else
return & F_93 ( V_95 ) -> V_186 ;
}
static int T_7 F_135 ( void )
{
F_90 ( V_236 L_26 ,
V_22 ) ;
return F_136 ( & V_237 ) ;
}
static void T_8 F_137 ( void )
{
F_90 ( V_236 L_27 ,
V_22 ) ;
F_138 ( & V_237 ) ;
}
