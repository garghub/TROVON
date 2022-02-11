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
F_33 ( V_17 -> V_24 , V_17 -> V_12 ,
V_17 -> V_94 + V_17 -> V_90 . V_27 ) ;
F_9 ( L_8 , V_22 , V_17 -> V_24 -> V_95 ,
( unsigned long ) F_22 ( V_17 -> V_24 ) -> V_96 -> V_97 ) ;
}
bool
F_34 ( struct V_39 * V_98 )
{
return F_35 ( V_98 ) ||
F_36 ( V_98 ) ;
}
static bool
F_37 ( struct V_11 * V_12 )
{
struct V_39 * V_98 = F_16 ( V_12 ) ;
return F_34 ( V_98 ) ;
}
static void F_38 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
if ( F_39 ( F_27 ( V_100 , & V_17 -> args . V_87 -> V_21 ) ) ) {
F_40 ( V_19 , - V_77 ) ;
return;
}
if ( F_37 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_12 ( V_17 ) ;
F_40 ( V_19 , 0 ) ;
return;
}
V_17 -> V_101 = F_29 ;
if ( F_41 ( V_17 -> V_88 -> V_44 ,
& V_17 -> args . V_102 ,
& V_17 -> V_90 . V_103 ,
V_19 ) )
return;
if ( F_42 ( & V_17 -> args . V_104 , V_17 -> args . V_87 ,
V_17 -> args . V_105 , V_106 ) == - V_77 )
F_40 ( V_19 , - V_77 ) ;
}
static void F_43 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
F_9 ( L_10 , V_22 , V_19 -> V_28 ) ;
if ( F_27 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_44 ( V_19 , & V_17 -> V_90 . V_103 ) ;
return;
}
V_17 -> V_107 -> V_108 ( V_19 , V_99 ) ;
}
static void F_45 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
F_46 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_109 -> V_110 ) ;
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
struct V_111 * V_99 )
{
int V_86 ;
F_50 ( V_99 , V_19 -> V_28 ) ;
V_86 = F_14 ( V_19 , NULL , V_99 -> V_88 ,
V_99 -> V_12 ) ;
switch ( V_86 ) {
case - V_80 :
F_51 ( V_99 ) ;
return - V_82 ;
case - V_82 :
F_31 ( V_19 ) ;
return - V_82 ;
}
if ( V_99 -> V_91 . V_92 == V_112 )
F_33 ( V_99 -> V_24 , V_99 -> V_12 , V_99 -> V_113 ) ;
return 0 ;
}
static void F_52 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
if ( F_39 ( F_27 ( V_100 , & V_17 -> args . V_87 -> V_21 ) ) ) {
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
& V_17 -> args . V_102 ,
& V_17 -> V_90 . V_103 ,
V_19 ) )
return;
if ( F_42 ( & V_17 -> args . V_104 , V_17 -> args . V_87 ,
V_17 -> args . V_105 , V_114 ) == - V_77 )
F_40 ( V_19 , - V_77 ) ;
}
static void F_53 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
if ( F_27 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_44 ( V_19 , & V_17 -> V_90 . V_103 ) ;
return;
}
V_17 -> V_107 -> V_108 ( V_19 , V_99 ) ;
}
static void F_54 ( struct V_18 * V_19 , void * V_99 )
{
struct V_16 * V_17 = V_99 ;
F_46 ( V_19 , F_15 ( V_17 -> V_24 ) -> V_109 -> V_110 ) ;
}
static void F_55 ( struct V_18 * V_19 , void * V_99 )
{
struct V_111 * V_115 = V_99 ;
F_41 ( V_115 -> V_88 -> V_44 ,
& V_115 -> args . V_102 ,
& V_115 -> V_90 . V_103 ,
V_19 ) ;
}
static void F_56 ( struct V_18 * V_19 , void * V_99 )
{
struct V_111 * V_116 = V_99 ;
F_46 ( V_19 , F_15 ( V_116 -> V_24 ) -> V_109 -> V_110 ) ;
}
static enum V_117
F_57 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_122 , V_123 ;
struct V_124 * V_125 ;
F_9 ( L_11 ,
V_22 , V_17 -> V_24 -> V_95 ,
V_17 -> args . V_126 , ( V_127 ) V_17 -> args . V_27 , V_3 ) ;
V_122 = F_58 ( V_12 , V_3 ) ;
V_123 = F_59 ( V_12 , V_122 ) ;
V_119 = F_60 ( V_12 , V_123 ) ;
if ( ! V_119 )
return V_128 ;
V_121 = F_61 ( V_119 -> V_88 , V_17 -> V_24 ) ;
if ( F_62 ( V_121 ) )
return V_128 ;
F_9 ( L_12 , V_22 ,
V_119 -> V_129 , F_63 ( & V_119 -> V_88 -> V_130 ) ) ;
F_64 ( & V_119 -> V_88 -> V_130 ) ;
V_17 -> V_88 = V_119 -> V_88 ;
V_17 -> V_131 = V_123 ;
V_125 = F_65 ( V_12 , V_122 ) ;
if ( V_125 )
V_17 -> args . V_125 = V_125 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_94 = V_3 ;
F_66 ( V_121 , V_17 , V_17 -> V_132 ,
F_67 ( V_17 -> V_24 ) , & V_133 ,
0 , V_134 ) ;
return V_135 ;
}
static enum V_117
F_68 ( struct V_16 * V_17 , int V_136 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_122 , V_123 ;
struct V_124 * V_125 ;
V_122 = F_58 ( V_12 , V_3 ) ;
V_123 = F_59 ( V_12 , V_122 ) ;
V_119 = F_60 ( V_12 , V_123 ) ;
if ( ! V_119 )
return V_128 ;
V_121 = F_61 ( V_119 -> V_88 , V_17 -> V_24 ) ;
if ( F_62 ( V_121 ) )
return V_128 ;
F_9 ( L_13 ,
V_22 , V_17 -> V_24 -> V_95 , V_136 , ( V_127 ) V_17 -> args . V_27 ,
V_3 , V_119 -> V_129 , F_63 ( & V_119 -> V_88 -> V_130 ) ) ;
V_17 -> V_101 = F_47 ;
F_64 ( & V_119 -> V_88 -> V_130 ) ;
V_17 -> V_88 = V_119 -> V_88 ;
V_17 -> V_131 = V_123 ;
V_125 = F_65 ( V_12 , V_122 ) ;
if ( V_125 )
V_17 -> args . V_125 = V_125 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_66 ( V_121 , V_17 , V_17 -> V_132 ,
F_67 ( V_17 -> V_24 ) , & V_137 ,
V_136 , V_134 ) ;
return V_135 ;
}
static int
F_69 ( struct V_33 * V_34 ,
struct V_1 * V_138 ,
struct V_139 * V_140 ,
struct V_141 * V_142 ,
T_4 V_143 )
{
struct V_39 * V_144 ;
struct V_145 * V_6 ;
int V_146 = - V_147 ;
F_9 ( L_14 , V_22 ) ;
if ( V_140 -> V_148 . V_3 != 0 ||
V_140 -> V_148 . V_149 != V_150 ) {
F_9 ( L_15 ,
V_22 ) ;
goto V_81;
}
if ( V_138 -> V_10 > V_140 -> V_148 . V_3 ) {
F_9 ( L_16 ,
V_22 , V_138 -> V_10 ) ;
goto V_81;
}
if ( ! V_138 -> V_5 ) {
F_9 ( L_17 ,
V_22 , V_138 -> V_5 ) ;
goto V_81;
}
V_144 = F_70 ( F_15 ( V_34 -> V_36 ) , V_142 ,
V_34 -> V_151 , V_143 ) ;
if ( V_144 == NULL )
goto V_81;
V_6 = F_71 ( V_144 , struct V_145 , V_152 ) ;
if ( F_34 ( & V_6 -> V_152 ) )
goto V_153;
V_138 -> V_6 = V_6 ;
if ( V_138 -> V_154 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_22 , V_138 -> V_154 ) ;
goto V_153;
}
if ( ( V_138 -> V_13 == V_14 &&
V_138 -> V_155 > 1 && V_138 -> V_155 != V_6 -> V_156 ) ||
( V_138 -> V_13 == V_15 &&
V_138 -> V_155 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_22 , V_138 -> V_155 ) ;
goto V_153;
}
V_146 = 0 ;
V_81:
F_9 ( L_20 , V_22 , V_146 ) ;
return V_146 ;
V_153:
F_72 ( V_6 ) ;
goto V_81;
}
static void F_73 ( struct V_1 * V_138 )
{
int V_157 ;
if ( V_138 -> V_158 ) {
for ( V_157 = 0 ; V_157 < V_138 -> V_155 ; V_157 ++ ) {
if ( ! V_138 -> V_158 [ V_157 ] )
break;
F_74 ( V_138 -> V_158 [ V_157 ] ) ;
}
F_74 ( V_138 -> V_158 ) ;
}
F_74 ( V_138 ) ;
}
static int
F_75 ( struct V_33 * V_159 ,
struct V_1 * V_138 ,
struct V_139 * V_140 ,
struct V_141 * V_142 ,
T_4 V_143 )
{
struct V_160 V_161 ;
struct V_162 V_163 ;
struct V_164 * V_165 ;
T_5 * V_166 ;
T_6 V_167 ;
int V_157 ;
F_9 ( L_21 , V_22 ) ;
V_165 = F_76 ( V_143 ) ;
if ( ! V_165 )
return - V_168 ;
F_77 ( & V_161 , & V_163 , V_140 -> V_169 -> V_170 , V_140 -> V_169 -> V_171 ) ;
F_78 ( & V_161 , F_79 ( V_165 ) , V_172 ) ;
V_166 = F_80 ( & V_161 , V_173 + 20 ) ;
if ( F_39 ( ! V_166 ) )
goto V_174;
memcpy ( V_142 , V_166 , sizeof( * V_142 ) ) ;
V_166 += F_81 ( V_173 ) ;
F_82 ( V_142 ) ;
V_167 = F_83 ( V_166 ++ ) ;
if ( V_167 & V_175 )
V_138 -> V_89 = 1 ;
if ( V_167 & V_176 )
V_138 -> V_13 = V_15 ;
else
V_138 -> V_13 = V_14 ;
V_138 -> V_5 = V_167 & ~ V_177 ;
V_138 -> V_154 = F_83 ( V_166 ++ ) ;
V_166 = F_84 ( V_166 , & V_138 -> V_10 ) ;
V_138 -> V_155 = F_83 ( V_166 ++ ) ;
F_9 ( L_22 ,
V_22 , V_167 , V_138 -> V_155 , V_138 -> V_154 ,
V_138 -> V_10 ) ;
if ( V_138 -> V_155 >
F_85 ( V_178 , V_179 ) )
goto V_174;
if ( V_138 -> V_155 > 0 ) {
V_138 -> V_158 = F_86 ( V_138 -> V_155 , sizeof( V_138 -> V_158 [ 0 ] ) ,
V_143 ) ;
if ( ! V_138 -> V_158 )
goto V_174;
}
for ( V_157 = 0 ; V_157 < V_138 -> V_155 ; V_157 ++ ) {
V_138 -> V_158 [ V_157 ] = F_87 ( sizeof( struct V_124 ) , V_143 ) ;
if ( ! V_138 -> V_158 [ V_157 ] )
goto V_174;
V_166 = F_80 ( & V_161 , 4 ) ;
if ( F_39 ( ! V_166 ) )
goto V_174;
V_138 -> V_158 [ V_157 ] -> V_180 = F_83 ( V_166 ++ ) ;
if ( sizeof( struct V_124 ) < V_138 -> V_158 [ V_157 ] -> V_180 ) {
F_88 ( V_181 L_23 ,
V_157 , V_138 -> V_158 [ V_157 ] -> V_180 ) ;
goto V_174;
}
V_166 = F_80 ( & V_161 , V_138 -> V_158 [ V_157 ] -> V_180 ) ;
if ( F_39 ( ! V_166 ) )
goto V_174;
memcpy ( V_138 -> V_158 [ V_157 ] -> V_99 , V_166 , V_138 -> V_158 [ V_157 ] -> V_180 ) ;
F_9 ( L_24 , V_22 ,
V_138 -> V_158 [ V_157 ] -> V_180 ) ;
}
F_89 ( V_165 ) ;
return 0 ;
V_174:
F_89 ( V_165 ) ;
return - V_77 ;
}
static void
F_90 ( struct V_11 * V_12 )
{
struct V_1 * V_138 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_22 ) ;
F_72 ( V_138 -> V_6 ) ;
if ( V_12 -> V_182 . V_183 == V_184 ) {
struct V_185 * V_159 ;
V_159 = F_91 ( V_12 -> V_35 ) ;
V_159 -> V_186 . V_187 = 0 ;
F_74 ( V_159 -> V_186 . V_188 ) ;
V_159 -> V_186 . V_188 = NULL ;
}
F_73 ( V_138 ) ;
}
static int
F_92 ( struct V_11 * V_12 ,
struct V_189 * V_190 ,
T_4 V_143 )
{
struct V_1 * V_138 = F_5 ( V_12 ) ;
struct V_191 * V_188 ;
int V_180 , V_157 ;
if ( V_138 -> V_89 )
return 0 ;
V_180 = ( V_138 -> V_13 == V_14 ) ?
V_138 -> V_6 -> V_156 : V_138 -> V_6 -> V_7 ;
if ( V_190 -> V_119 -> V_187 >= V_180 ) {
return 0 ;
}
V_188 = F_86 ( V_180 , sizeof( struct V_191 ) ,
V_143 ) ;
if ( ! V_188 )
return - V_168 ;
for ( V_157 = 0 ; V_157 < V_180 ; V_157 ++ ) {
F_93 ( & V_188 [ V_157 ] . V_192 ) ;
F_93 ( & V_188 [ V_157 ] . V_193 ) ;
V_188 [ V_157 ] . V_194 . V_92 = V_195 ;
}
F_94 ( V_190 -> V_196 ) ;
if ( V_190 -> V_119 -> V_187 >= V_180 )
goto V_81;
for ( V_157 = 0 ; V_157 < V_190 -> V_119 -> V_187 ; V_157 ++ ) {
F_95 ( & V_190 -> V_119 -> V_188 [ V_157 ] . V_192 ,
& V_188 [ V_157 ] . V_192 ) ;
F_95 ( & V_190 -> V_119 -> V_188 [ V_157 ] . V_193 ,
& V_188 [ V_157 ] . V_193 ) ;
V_188 [ V_157 ] . V_194 . V_92 =
V_190 -> V_119 -> V_188 [ V_157 ] . V_194 . V_92 ;
V_188 [ V_157 ] . V_197 = V_190 -> V_119 -> V_188 [ V_157 ] . V_197 ;
V_188 [ V_157 ] . V_198 = V_190 -> V_119 -> V_188 [ V_157 ] . V_198 ;
}
F_96 ( V_190 -> V_119 -> V_188 , V_188 ) ;
V_190 -> V_119 -> V_187 = V_180 ;
V_81:
F_97 ( V_190 -> V_196 ) ;
F_74 ( V_188 ) ;
return 0 ;
}
static struct V_11 *
F_98 ( struct V_33 * V_199 ,
struct V_139 * V_140 ,
T_4 V_143 )
{
struct V_1 * V_138 ;
int V_200 ;
struct V_141 V_142 ;
F_9 ( L_14 , V_22 ) ;
V_138 = F_99 ( sizeof( * V_138 ) , V_143 ) ;
if ( ! V_138 )
return NULL ;
V_200 = F_75 ( V_199 , V_138 , V_140 , & V_142 , V_143 ) ;
if ( V_200 != 0 || F_69 ( V_199 , V_138 , V_140 , & V_142 , V_143 ) ) {
F_73 ( V_138 ) ;
return NULL ;
}
return & V_138 -> V_201 ;
}
static V_127
F_100 ( struct V_202 * V_203 , struct V_204 * V_205 ,
struct V_204 * V_206 )
{
unsigned int V_180 ;
T_3 V_207 , V_208 ;
T_2 V_209 ;
T_3 V_210 = V_203 -> V_211 -> V_182 . V_3 ;
T_2 V_5 = F_5 ( V_203 -> V_211 ) -> V_5 ;
V_180 = F_101 ( V_203 , V_205 , V_206 ) ;
if ( ! V_180 )
return 0 ;
if ( V_205 ) {
V_207 = ( T_3 ) F_102 ( V_205 ) - V_210 ;
V_208 = ( T_3 ) F_102 ( V_206 ) - V_210 ;
F_103 ( V_207 , V_5 ) ;
F_103 ( V_208 , V_5 ) ;
if ( V_207 != V_208 )
return 0 ;
}
F_3 ( ( T_3 ) F_102 ( V_206 ) - V_210 ,
V_5 ,
& V_209 ) ;
F_104 ( V_209 > V_5 ) ;
if ( V_209 >= V_5 )
return 0 ;
return F_105 ( V_5 - ( unsigned int ) V_209 , V_180 ) ;
}
static void
F_106 ( struct V_202 * V_203 ,
struct V_204 * V_206 )
{
if ( ! V_203 -> V_211 )
V_203 -> V_211 = F_107 ( V_203 -> V_212 ,
V_206 -> V_213 ,
0 ,
V_150 ,
V_214 ,
V_215 ) ;
if ( V_203 -> V_211 == NULL )
F_108 ( V_203 ) ;
}
static void
F_109 ( struct V_202 * V_203 ,
struct V_204 * V_206 )
{
struct V_189 V_190 ;
int V_146 ;
if ( ! V_203 -> V_211 )
V_203 -> V_211 = F_107 ( V_203 -> V_212 ,
V_206 -> V_213 ,
0 ,
V_150 ,
V_184 ,
V_216 ) ;
if ( V_203 -> V_211 == NULL )
goto V_217;
F_110 ( & V_190 , V_203 -> V_212 , V_203 -> V_218 ) ;
V_146 = F_92 ( V_203 -> V_211 , & V_190 , V_216 ) ;
if ( V_146 < 0 ) {
F_111 ( V_203 -> V_211 ) ;
V_203 -> V_211 = NULL ;
goto V_217;
}
return;
V_217:
F_112 ( V_203 ) ;
}
static T_2 F_113 ( struct V_1 * V_138 , T_2 V_122 )
{
if ( V_138 -> V_13 == V_14 )
return F_59 ( & V_138 -> V_201 , V_122 ) ;
else
return V_122 ;
}
static void
F_114 ( struct V_204 * V_206 ,
struct V_11 * V_12 ,
struct V_189 * V_190 ,
T_2 V_131 )
{
struct V_1 * V_138 = F_5 ( V_12 ) ;
T_2 V_157 , V_122 ;
if ( V_138 -> V_89 ) {
F_115 ( V_206 , & V_190 -> V_219 -> V_220 , V_190 ) ;
} else {
V_122 = F_58 ( V_12 , F_102 ( V_206 ) ) ;
V_157 = F_113 ( V_138 , V_122 ) ;
F_116 ( V_206 , V_12 , V_190 , V_157 ) ;
}
}
static T_2 F_117 ( struct V_11 * V_12 , T_2 V_157 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_157 ;
else
return F_59 ( V_12 , V_157 ) ;
}
static struct V_124 *
F_118 ( struct V_11 * V_12 , T_2 V_157 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_155 == 1 )
V_157 = 0 ;
else if ( V_2 -> V_155 == 0 )
return NULL ;
}
return V_2 -> V_158 [ V_157 ] ;
}
static int F_119 ( struct V_111 * V_99 , int V_221 )
{
struct V_11 * V_12 = V_99 -> V_12 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
T_2 V_123 ;
struct V_124 * V_125 ;
V_123 = F_117 ( V_12 , V_99 -> V_222 ) ;
V_119 = F_60 ( V_12 , V_123 ) ;
if ( ! V_119 )
goto V_174;
V_121 = F_61 ( V_119 -> V_88 , V_99 -> V_24 ) ;
if ( F_62 ( V_121 ) )
goto V_174;
F_9 ( L_25 , V_22 ,
V_99 -> V_24 -> V_95 , V_221 , F_63 ( & V_119 -> V_88 -> V_130 ) ) ;
V_99 -> V_223 = F_49 ;
F_64 ( & V_119 -> V_88 -> V_130 ) ;
V_99 -> V_88 = V_119 -> V_88 ;
V_125 = F_118 ( V_12 , V_99 -> V_222 ) ;
if ( V_125 )
V_99 -> args . V_125 = V_125 ;
return F_120 ( V_121 , V_99 , F_67 ( V_99 -> V_24 ) ,
& V_224 , V_221 ,
V_134 ) ;
V_174:
F_51 ( V_99 ) ;
F_121 ( V_99 ) ;
return - V_82 ;
}
static struct V_204 *
F_122 ( struct V_189 * V_190 , struct V_164 * V_164 )
{
struct V_204 * V_225 , * V_226 ;
struct V_191 * V_227 ;
int V_157 ;
for ( V_157 = 0 , V_227 = V_190 -> V_119 -> V_188 ; V_157 < V_190 -> V_119 -> V_187 ; V_157 ++ , V_227 ++ ) {
F_123 (freq, t, &b->written, wb_list) {
if ( V_225 -> V_228 == V_164 )
return V_225 -> V_229 ;
}
F_123 (freq, t, &b->committing, wb_list) {
if ( V_225 -> V_228 == V_164 )
return V_225 -> V_229 ;
}
}
return NULL ;
}
static int
F_124 ( struct V_24 * V_24 , struct V_230 * V_231 ,
int V_221 , struct V_189 * V_190 )
{
return F_125 ( V_24 , V_231 , V_221 , V_190 ,
F_119 ) ;
}
static struct V_39 *
F_126 ( struct V_37 * V_232 ,
struct V_233 * V_234 , T_4 V_143 )
{
struct V_145 * V_6 ;
V_6 = F_127 ( V_232 , V_234 , V_143 ) ;
if ( ! V_6 )
return NULL ;
return & V_6 -> V_152 ;
}
static void
F_128 ( struct V_39 * V_144 )
{
F_129 ( F_71 ( V_144 , struct V_145 , V_152 ) ) ;
}
static struct V_33 *
F_130 ( struct V_24 * V_24 , T_4 V_143 )
{
struct V_185 * V_159 ;
V_159 = F_99 ( sizeof( * V_159 ) , V_143 ) ;
return V_159 != NULL ? & V_159 -> V_201 : NULL ;
}
static void
F_131 ( struct V_33 * V_34 )
{
F_74 ( F_91 ( V_34 ) ) ;
}
static struct V_235 *
F_132 ( struct V_24 * V_24 )
{
struct V_33 * V_96 = F_22 ( V_24 ) -> V_96 ;
if ( V_96 == NULL )
return NULL ;
else
return & F_91 ( V_96 ) -> V_186 ;
}
static int T_7 F_133 ( void )
{
F_88 ( V_236 L_26 ,
V_22 ) ;
return F_134 ( & V_237 ) ;
}
static void T_8 F_135 ( void )
{
F_88 ( V_236 L_27 ,
V_22 ) ;
F_136 ( & V_237 ) ;
}
