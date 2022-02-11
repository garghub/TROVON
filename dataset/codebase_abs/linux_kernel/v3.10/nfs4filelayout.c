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
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 = & V_17 -> V_22 ;
if ( ! F_8 ( V_23 , & V_19 -> V_24 ) ) {
F_9 ( L_1
L_2 , V_25 ,
V_17 -> V_22 . V_26 ,
V_19 -> V_27 -> V_28 -> V_29 ,
( long long ) F_10 ( V_19 -> V_27 ) ,
V_17 -> args . V_30 ,
( unsigned long long ) V_17 -> args . V_3 ) ;
V_22 -> V_31 = F_11 ( V_19 -> V_27 ,
& V_19 -> V_32 ,
V_19 -> V_33 ,
V_19 -> V_34 ) ;
}
}
static void F_12 ( struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 = & V_17 -> V_22 ;
if ( ! F_8 ( V_23 , & V_19 -> V_24 ) ) {
F_9 ( L_1
L_2 , V_25 ,
V_17 -> V_22 . V_26 ,
V_19 -> V_27 -> V_28 -> V_29 ,
( long long ) F_10 ( V_19 -> V_27 ) ,
V_17 -> args . V_30 ,
( unsigned long long ) V_17 -> args . V_3 ) ;
V_22 -> V_31 = F_13 ( V_19 -> V_27 ,
& V_19 -> V_32 ,
V_19 -> V_33 ,
V_19 -> V_34 ) ;
}
}
static void F_14 ( struct V_27 * V_27 , struct V_36 * V_37 )
{
if ( ! F_15 ( V_38 , & V_37 -> V_39 ) )
return;
F_16 ( V_27 ) ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_11 * V_12 )
{
struct V_36 * V_37 = V_12 -> V_44 ;
struct V_27 * V_27 = V_37 -> V_45 ;
struct V_46 * V_47 = F_18 ( V_27 ) ;
struct V_48 * V_49 = F_19 ( V_12 ) ;
struct V_42 * V_50 = V_47 -> V_42 ;
struct V_51 * V_52 = & V_43 -> V_53 -> V_54 ;
if ( V_22 -> V_31 >= 0 )
return 0 ;
switch ( V_22 -> V_31 ) {
case - V_55 :
case - V_56 :
case - V_57 :
if ( V_41 == NULL )
break;
F_20 ( V_41 -> V_27 ) ;
case - V_58 :
if ( V_41 == NULL )
break;
if ( F_21 ( V_47 , V_41 ) < 0 )
goto V_59;
goto V_60;
case - V_61 :
if ( V_41 != NULL ) {
if ( F_21 ( V_47 , V_41 ) < 0 )
goto V_59;
}
F_22 ( V_50 ) ;
goto V_60;
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
F_9 ( L_3
L_4 , V_25 , V_22 -> V_31 ,
V_43 -> V_69 ) ;
F_23 ( V_43 -> V_53 , V_22 -> V_31 ) ;
break;
case - V_70 :
case - V_71 :
F_24 ( V_22 , V_72 ) ;
break;
case - V_73 :
break;
case - V_74 :
case - V_75 :
case - V_76 :
case - V_77 :
case - V_78 :
case - V_79 :
F_9 ( L_5 , V_25 ,
V_22 -> V_31 ) ;
F_25 ( F_26 ( V_27 ) ) ;
F_27 ( & V_52 -> V_80 ) ;
goto V_81;
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
case - V_87 :
case - V_88 :
F_9 ( L_6 , V_25 ,
V_22 -> V_31 ) ;
F_28 ( V_49 ) ;
F_29 ( V_38 , & V_37 -> V_39 ) ;
F_27 ( & V_52 -> V_80 ) ;
default:
V_81:
F_9 ( L_7 , V_25 ,
V_22 -> V_31 ) ;
return - V_89 ;
}
V_90:
V_22 -> V_31 = 0 ;
return - V_91 ;
V_59:
V_22 -> V_31 = - V_86 ;
return 0 ;
V_60:
F_30 ( & V_50 -> V_92 , V_22 , NULL ) ;
if ( F_31 ( V_93 , & V_50 -> V_94 ) == 0 )
F_32 ( & V_50 -> V_92 , V_22 ) ;
goto V_90;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_95 ;
V_95 = F_17 ( V_22 , V_17 -> args . V_96 -> V_41 ,
V_17 -> V_97 , V_19 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_12 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_91 :
F_34 ( V_22 ) ;
return - V_91 ;
}
return 0 ;
}
static void
F_35 ( struct V_16 * V_98 )
{
struct V_18 * V_19 = V_98 -> V_20 ;
if ( F_5 ( V_19 -> V_12 ) -> V_99 ||
V_98 -> V_100 . V_101 -> V_102 == V_103 )
return;
F_36 ( V_98 ) ;
F_9 ( L_8 , V_25 , V_19 -> V_27 -> V_104 ,
( unsigned long ) F_26 ( V_19 -> V_27 ) -> V_105 -> V_106 ) ;
}
bool
F_37 ( struct V_48 * V_107 )
{
return F_38 ( V_107 ) ||
F_39 ( V_107 ) ;
}
static bool
F_40 ( struct V_11 * V_12 )
{
struct V_48 * V_107 = F_19 ( V_12 ) ;
return F_37 ( V_107 ) ;
}
static void F_41 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
if ( F_42 ( F_31 ( V_109 , & V_108 -> args . V_96 -> V_24 ) ) ) {
F_43 ( V_22 , - V_86 ) ;
return;
}
if ( F_40 ( V_108 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_108 ) ;
F_43 ( V_22 , 0 ) ;
return;
}
V_108 -> V_110 = F_33 ;
if ( F_44 ( V_108 -> V_97 -> V_53 ,
& V_108 -> args . V_111 ,
& V_108 -> V_100 . V_112 ,
V_22 ) )
return;
F_45 ( & V_108 -> args . V_113 , V_108 -> args . V_96 ,
V_108 -> args . V_114 , V_115 ) ;
}
static void F_46 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_108 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_108 -> V_20 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_47 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
F_48 ( V_22 , F_18 ( V_108 -> V_20 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_49 ( void * V_17 )
{
struct V_35 * V_108 = V_17 ;
struct V_36 * V_37 = V_108 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_50 ( V_108 -> V_97 ) ;
V_108 -> V_20 -> V_116 -> V_120 ( V_17 ) ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_95 ;
V_95 = F_17 ( V_22 , V_17 -> args . V_96 -> V_41 ,
V_17 -> V_97 , V_19 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_7 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_91 :
F_34 ( V_22 ) ;
return - V_91 ;
}
F_35 ( V_17 ) ;
return 0 ;
}
static void F_52 ( struct V_121 * V_17 )
{
struct V_122 * V_123 = F_53 ( V_17 -> V_32 . V_124 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_101 . V_125 , & V_123 -> V_126 ,
sizeof( V_17 -> V_101 . V_125 ) ) ;
V_17 -> V_101 . V_125 . V_17 [ 0 ] ++ ;
}
static int F_54 ( struct V_21 * V_22 ,
struct V_121 * V_17 )
{
int V_95 ;
V_95 = F_17 ( V_22 , NULL , V_17 -> V_97 ,
V_17 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_52 ( V_17 ) ;
return - V_91 ;
case - V_91 :
F_34 ( V_22 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_55 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_42 ( F_31 ( V_109 , & V_98 -> args . V_96 -> V_24 ) ) ) {
F_43 ( V_22 , - V_86 ) ;
return;
}
if ( F_40 ( V_98 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_98 ) ;
F_43 ( V_22 , 0 ) ;
return;
}
if ( F_44 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_111 ,
& V_98 -> V_100 . V_112 ,
V_22 ) )
return;
F_45 ( & V_98 -> args . V_113 , V_98 -> args . V_96 ,
V_98 -> args . V_114 , V_127 ) ;
}
static void F_56 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_31 ( V_23 , & V_98 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_98 -> V_20 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_57 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
F_48 ( V_22 , F_18 ( V_98 -> V_20 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_58 ( void * V_17 )
{
struct V_16 * V_98 = V_17 ;
struct V_36 * V_37 = V_98 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_50 ( V_98 -> V_97 ) ;
V_98 -> V_20 -> V_116 -> V_120 ( V_17 ) ;
}
static void F_59 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_98 = V_17 ;
F_44 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_111 ,
& V_98 -> V_100 . V_112 ,
V_22 ) ;
}
static void F_60 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_98 = V_17 ;
V_98 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_61 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_128 = V_17 ;
F_48 ( V_22 , F_18 ( V_128 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_62 ( void * V_129 )
{
struct V_121 * V_17 = V_129 ;
V_17 -> V_33 -> V_130 ( V_17 ) ;
F_63 ( V_17 -> V_12 ) ;
F_50 ( V_17 -> V_97 ) ;
F_64 ( V_17 ) ;
}
static enum V_131
F_65 ( struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_132 * V_133 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_134 , V_135 ;
struct V_136 * V_137 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_104 ,
V_17 -> args . V_138 , ( V_139 ) V_17 -> args . V_30 , V_3 ) ;
V_134 = F_66 ( V_12 , V_3 ) ;
V_135 = F_67 ( V_12 , V_134 ) ;
V_133 = F_68 ( V_12 , V_135 ) ;
if ( ! V_133 )
return V_140 ;
F_9 ( L_12 , V_25 ,
V_133 -> V_141 , F_69 ( & V_133 -> V_97 -> V_142 ) ) ;
F_70 ( & V_133 -> V_97 -> V_142 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_137 = F_71 ( V_12 , V_134 ) ;
if ( V_137 )
V_17 -> args . V_137 = V_137 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_143 = V_3 ;
F_72 ( V_133 -> V_97 -> V_144 , V_17 ,
& V_145 , V_146 ) ;
return V_147 ;
}
static enum V_131
F_73 ( struct V_16 * V_17 , int V_148 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_132 * V_133 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_134 , V_135 ;
struct V_136 * V_137 ;
V_134 = F_66 ( V_12 , V_3 ) ;
V_135 = F_67 ( V_12 , V_134 ) ;
V_133 = F_68 ( V_12 , V_135 ) ;
if ( ! V_133 )
return V_140 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_104 , V_148 , ( V_139 ) V_17 -> args . V_30 ,
V_3 , V_133 -> V_141 , F_69 ( & V_133 -> V_97 -> V_142 ) ) ;
V_17 -> V_149 = F_51 ;
F_70 ( & V_133 -> V_97 -> V_142 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_137 = F_71 ( V_12 , V_134 ) ;
if ( V_137 )
V_17 -> args . V_137 = V_137 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_74 ( V_133 -> V_97 -> V_144 , V_17 ,
& V_150 , V_148 ,
V_146 ) ;
return V_147 ;
}
static int
F_75 ( struct V_36 * V_37 ,
struct V_1 * V_151 ,
struct V_152 * V_153 ,
struct V_154 * V_155 ,
T_4 V_156 )
{
struct V_48 * V_157 ;
struct V_158 * V_6 ;
int V_159 = - V_160 ;
struct V_46 * V_161 = F_18 ( V_37 -> V_45 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_153 -> V_162 . V_3 != 0 ||
V_153 -> V_162 . V_163 != V_164 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_90;
}
if ( V_151 -> V_10 > V_153 -> V_162 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_151 -> V_10 ) ;
goto V_90;
}
if ( ! V_151 -> V_5 || V_151 -> V_5 % V_165 ) {
F_9 ( L_17 ,
V_25 , V_151 -> V_5 ) ;
goto V_90;
}
V_157 = F_76 ( F_18 ( V_37 -> V_45 ) -> V_166 ,
F_18 ( V_37 -> V_45 ) -> V_42 , V_155 ) ;
if ( V_157 == NULL ) {
V_6 = F_77 ( V_37 -> V_45 , V_155 , V_156 ) ;
if ( V_6 == NULL )
goto V_90;
} else
V_6 = F_78 ( V_157 , struct V_158 , V_167 ) ;
if ( F_37 ( & V_6 -> V_167 ) )
goto V_168;
V_151 -> V_6 = V_6 ;
if ( V_151 -> V_169 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_151 -> V_169 ) ;
goto V_168;
}
if ( ( V_151 -> V_13 == V_14 &&
V_151 -> V_170 > 1 && V_151 -> V_170 != V_6 -> V_171 ) ||
( V_151 -> V_13 == V_15 &&
V_151 -> V_170 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_151 -> V_170 ) ;
goto V_168;
}
if ( V_151 -> V_5 % V_161 -> V_172 || V_151 -> V_5 % V_161 -> V_173 ) {
F_9 ( L_20
L_21 , V_25 , V_151 -> V_5 , V_161 -> V_172 ,
V_161 -> V_173 ) ;
}
V_159 = 0 ;
V_90:
F_9 ( L_22 , V_25 , V_159 ) ;
return V_159 ;
V_168:
F_79 ( V_6 ) ;
goto V_90;
}
static void F_80 ( struct V_1 * V_151 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_151 -> V_170 ; V_174 ++ ) {
if ( ! V_151 -> V_175 [ V_174 ] )
break;
F_81 ( V_151 -> V_175 [ V_174 ] ) ;
}
F_81 ( V_151 -> V_175 ) ;
V_151 -> V_175 = NULL ;
}
static void
F_82 ( struct V_1 * V_151 )
{
F_80 ( V_151 ) ;
F_81 ( V_151 ) ;
}
static int
F_83 ( struct V_36 * V_176 ,
struct V_1 * V_151 ,
struct V_152 * V_153 ,
struct V_154 * V_155 ,
T_4 V_156 )
{
struct V_177 V_178 ;
struct V_179 V_180 ;
struct V_181 * V_182 ;
T_5 * V_183 ;
T_6 V_184 ;
int V_174 ;
F_9 ( L_23 , V_25 ) ;
V_182 = F_84 ( V_156 ) ;
if ( ! V_182 )
return - V_185 ;
F_85 ( & V_178 , & V_180 , V_153 -> V_186 -> V_32 , V_153 -> V_186 -> V_187 ) ;
F_86 ( & V_178 , F_87 ( V_182 ) , V_165 ) ;
V_183 = F_88 ( & V_178 , V_188 + 20 ) ;
if ( F_42 ( ! V_183 ) )
goto V_189;
memcpy ( V_155 , V_183 , sizeof( * V_155 ) ) ;
V_183 += F_89 ( V_188 ) ;
F_90 ( V_155 ) ;
V_184 = F_91 ( V_183 ++ ) ;
if ( V_184 & V_190 )
V_151 -> V_99 = 1 ;
if ( V_184 & V_191 )
V_151 -> V_13 = V_15 ;
else
V_151 -> V_13 = V_14 ;
V_151 -> V_5 = V_184 & ~ V_192 ;
V_151 -> V_169 = F_91 ( V_183 ++ ) ;
V_183 = F_92 ( V_183 , & V_151 -> V_10 ) ;
V_151 -> V_170 = F_91 ( V_183 ++ ) ;
F_9 ( L_24 ,
V_25 , V_184 , V_151 -> V_170 , V_151 -> V_169 ,
V_151 -> V_10 ) ;
if ( V_151 -> V_170 >
F_93 ( V_193 , V_194 ) )
goto V_189;
if ( V_151 -> V_170 > 0 ) {
V_151 -> V_175 = F_94 ( V_151 -> V_170 , sizeof( V_151 -> V_175 [ 0 ] ) ,
V_156 ) ;
if ( ! V_151 -> V_175 )
goto V_189;
}
for ( V_174 = 0 ; V_174 < V_151 -> V_170 ; V_174 ++ ) {
V_151 -> V_175 [ V_174 ] = F_95 ( sizeof( struct V_136 ) , V_156 ) ;
if ( ! V_151 -> V_175 [ V_174 ] )
goto V_195;
V_183 = F_88 ( & V_178 , 4 ) ;
if ( F_42 ( ! V_183 ) )
goto V_195;
V_151 -> V_175 [ V_174 ] -> V_196 = F_91 ( V_183 ++ ) ;
if ( sizeof( struct V_136 ) < V_151 -> V_175 [ V_174 ] -> V_196 ) {
F_96 ( V_197 L_25 ,
V_174 , V_151 -> V_175 [ V_174 ] -> V_196 ) ;
goto V_195;
}
V_183 = F_88 ( & V_178 , V_151 -> V_175 [ V_174 ] -> V_196 ) ;
if ( F_42 ( ! V_183 ) )
goto V_195;
memcpy ( V_151 -> V_175 [ V_174 ] -> V_17 , V_183 , V_151 -> V_175 [ V_174 ] -> V_196 ) ;
F_9 ( L_26 , V_25 ,
V_151 -> V_175 [ V_174 ] -> V_196 ) ;
}
F_97 ( V_182 ) ;
return 0 ;
V_195:
F_80 ( V_151 ) ;
V_189:
F_97 ( V_182 ) ;
return - V_86 ;
}
static void
F_98 ( struct V_11 * V_12 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_79 ( V_151 -> V_6 ) ;
if ( V_12 -> V_198 . V_199 == V_200 ) {
struct V_201 * V_176 ;
V_176 = F_99 ( V_12 -> V_44 ) ;
V_176 -> V_202 . V_203 = 0 ;
F_81 ( V_176 -> V_202 . V_204 ) ;
V_176 -> V_202 . V_204 = NULL ;
}
F_82 ( V_151 ) ;
}
static int
F_100 ( struct V_11 * V_12 ,
struct V_205 * V_206 ,
T_4 V_156 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
struct V_207 * V_204 ;
int V_196 ;
if ( V_151 -> V_99 )
return 0 ;
if ( V_206 -> V_133 -> V_203 != 0 ) {
return 0 ;
}
V_196 = ( V_151 -> V_13 == V_14 ) ?
V_151 -> V_6 -> V_171 : V_151 -> V_6 -> V_7 ;
V_204 = F_94 ( V_196 , sizeof( struct V_207 ) ,
V_156 ) ;
if ( ! V_204 )
return - V_185 ;
else {
int V_174 ;
F_101 ( V_206 -> V_208 ) ;
if ( V_206 -> V_133 -> V_203 != 0 )
F_81 ( V_204 ) ;
else {
V_206 -> V_133 -> V_204 = V_204 ;
V_206 -> V_133 -> V_203 = V_196 ;
for ( V_174 = 0 ; V_174 < V_196 ; V_174 ++ ) {
F_102 ( & V_204 [ V_174 ] . V_209 ) ;
F_102 ( & V_204 [ V_174 ] . V_210 ) ;
}
}
F_103 ( V_206 -> V_208 ) ;
return 0 ;
}
}
static struct V_11 *
F_104 ( struct V_36 * V_211 ,
struct V_152 * V_153 ,
T_4 V_156 )
{
struct V_1 * V_151 ;
int V_212 ;
struct V_154 V_155 ;
F_9 ( L_14 , V_25 ) ;
V_151 = F_105 ( sizeof( * V_151 ) , V_156 ) ;
if ( ! V_151 )
return NULL ;
V_212 = F_83 ( V_211 , V_151 , V_153 , & V_155 , V_156 ) ;
if ( V_212 != 0 || F_75 ( V_211 , V_151 , V_153 , & V_155 , V_156 ) ) {
F_82 ( V_151 ) ;
return NULL ;
}
return & V_151 -> V_213 ;
}
static bool
F_106 ( struct V_214 * V_215 , struct V_122 * V_216 ,
struct V_122 * V_217 )
{
T_3 V_218 , V_219 ;
T_2 V_5 ;
if ( ! F_107 ( V_215 , V_216 , V_217 ) ||
! F_108 ( V_215 , V_216 , V_217 ) )
return false ;
V_218 = ( T_3 ) F_109 ( V_216 ) ;
V_219 = ( T_3 ) F_109 ( V_217 ) ;
V_5 = F_5 ( V_215 -> V_220 ) -> V_5 ;
F_110 ( V_218 , V_5 ) ;
F_110 ( V_219 , V_5 ) ;
return ( V_218 == V_219 ) ;
}
static void
F_111 ( struct V_214 * V_215 ,
struct V_122 * V_217 )
{
F_112 ( V_215 -> V_220 != NULL ) ;
if ( V_217 -> V_221 != V_217 -> V_222 ) {
F_113 ( V_215 ) ;
return;
}
V_215 -> V_220 = F_114 ( V_215 -> V_223 ,
V_217 -> V_224 ,
0 ,
V_164 ,
V_225 ,
V_226 ) ;
if ( V_215 -> V_220 == NULL )
F_113 ( V_215 ) ;
}
static void
F_115 ( struct V_214 * V_215 ,
struct V_122 * V_217 )
{
struct V_205 V_206 ;
int V_159 ;
F_112 ( V_215 -> V_220 != NULL ) ;
if ( V_217 -> V_221 != V_217 -> V_222 )
goto V_227;
V_215 -> V_220 = F_114 ( V_215 -> V_223 ,
V_217 -> V_224 ,
0 ,
V_164 ,
V_200 ,
V_228 ) ;
if ( V_215 -> V_220 == NULL )
goto V_227;
F_116 ( & V_206 , V_215 -> V_223 , V_215 -> V_229 ) ;
V_159 = F_100 ( V_215 -> V_220 , & V_206 , V_228 ) ;
if ( V_159 < 0 ) {
F_63 ( V_215 -> V_220 ) ;
V_215 -> V_220 = NULL ;
goto V_227;
}
return;
V_227:
F_117 ( V_215 ) ;
}
static T_2 F_118 ( struct V_1 * V_151 , T_2 V_134 )
{
if ( V_151 -> V_13 == V_14 )
return F_67 ( & V_151 -> V_213 , V_134 ) ;
else
return V_134 ;
}
static void
F_119 ( struct V_122 * V_217 ,
struct V_205 * V_206 )
{
struct V_11 * V_230 = NULL ;
F_101 ( V_206 -> V_208 ) ;
if ( ! F_15 ( V_231 , & V_217 -> V_232 ) )
goto V_90;
V_206 -> V_133 -> V_233 -- ;
if ( F_120 ( & V_217 -> V_234 ) ) {
struct V_207 * V_235 ;
V_235 = F_121 ( & V_217 -> V_234 ,
struct V_207 ,
V_209 ) ;
V_230 = V_235 -> V_236 ;
V_235 -> V_236 = NULL ;
}
V_90:
F_122 ( V_217 , V_206 ) ;
F_103 ( V_206 -> V_208 ) ;
F_63 ( V_230 ) ;
}
static struct V_237 *
F_123 ( struct V_122 * V_217 ,
struct V_11 * V_12 ,
struct V_205 * V_206 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
T_2 V_174 , V_134 ;
struct V_237 * V_238 ;
struct V_207 * V_204 ;
if ( V_151 -> V_99 )
return & V_206 -> V_239 -> V_238 ;
V_134 = F_66 ( V_12 , F_109 ( V_217 ) ) ;
V_174 = F_118 ( V_151 , V_134 ) ;
V_204 = V_206 -> V_133 -> V_204 ;
V_238 = & V_204 [ V_174 ] . V_209 ;
if ( F_124 ( V_238 ) ) {
V_204 [ V_174 ] . V_236 = F_125 ( V_12 ) ;
}
F_29 ( V_231 , & V_217 -> V_232 ) ;
V_206 -> V_133 -> V_233 ++ ;
return V_238 ;
}
static void
F_126 ( struct V_122 * V_217 ,
struct V_11 * V_12 ,
struct V_205 * V_206 )
{
struct V_237 * V_238 ;
V_238 = F_123 ( V_217 , V_12 , V_206 ) ;
F_127 ( V_217 , V_238 , V_206 ) ;
}
static T_2 F_128 ( struct V_11 * V_12 , T_2 V_174 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_174 ;
else
return F_67 ( V_12 , V_174 ) ;
}
static struct V_136 *
F_129 ( struct V_11 * V_12 , T_2 V_174 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_170 == 1 )
V_174 = 0 ;
else if ( V_2 -> V_170 == 0 )
return NULL ;
}
return V_2 -> V_175 [ V_174 ] ;
}
static int F_130 ( struct V_121 * V_17 , int V_240 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_132 * V_133 ;
T_2 V_135 ;
struct V_136 * V_137 ;
V_135 = F_128 ( V_12 , V_17 -> V_241 ) ;
V_133 = F_68 ( V_12 , V_135 ) ;
if ( ! V_133 ) {
F_52 ( V_17 ) ;
F_62 ( V_17 ) ;
return - V_91 ;
}
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_104 , V_240 , F_69 ( & V_133 -> V_97 -> V_142 ) ) ;
V_17 -> V_242 = F_54 ;
F_70 ( & V_133 -> V_97 -> V_142 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_137 = F_129 ( V_12 , V_17 -> V_241 ) ;
if ( V_137 )
V_17 -> args . V_137 = V_137 ;
return F_131 ( V_133 -> V_97 -> V_144 , V_17 ,
& V_243 , V_240 ,
V_146 ) ;
}
static int
F_132 ( struct V_237 * V_244 , struct V_237 * V_245 ,
struct V_205 * V_206 , int F_93 )
{
struct V_122 * V_217 , * V_246 ;
int V_247 = 0 ;
F_133 (req, tmp, src, wb_list) {
if ( ! F_134 ( V_217 ) )
continue;
F_135 ( & V_217 -> V_248 ) ;
if ( F_136 ( V_206 -> V_208 ) )
F_137 ( V_217 , V_246 , V_234 ) ;
F_122 ( V_217 , V_206 ) ;
F_138 ( V_231 , & V_217 -> V_232 ) ;
F_139 ( V_217 , V_245 ) ;
V_247 ++ ;
if ( ( V_247 == F_93 ) && ! V_206 -> V_34 )
break;
}
return V_247 ;
}
static int
F_140 ( struct V_207 * V_235 ,
struct V_205 * V_206 ,
int F_93 )
{
struct V_237 * V_244 = & V_235 -> V_209 ;
struct V_237 * V_245 = & V_235 -> V_210 ;
int V_247 ;
V_247 = F_132 ( V_244 , V_245 , V_206 , F_93 ) ;
if ( V_247 ) {
V_206 -> V_133 -> V_233 -= V_247 ;
V_206 -> V_133 -> V_249 += V_247 ;
V_235 -> V_250 = V_235 -> V_236 ;
if ( F_124 ( V_244 ) )
V_235 -> V_236 = NULL ;
else
F_125 ( V_235 -> V_250 ) ;
}
return V_247 ;
}
static int F_141 ( struct V_205 * V_206 ,
int F_93 )
{
int V_174 , V_251 = 0 , V_252 ;
for ( V_174 = 0 ; V_174 < V_206 -> V_133 -> V_203 && F_93 != 0 ; V_174 ++ ) {
V_252 = F_140 ( & V_206 -> V_133 -> V_204 [ V_174 ] ,
V_206 , F_93 ) ;
F_93 -= V_252 ;
V_251 += V_252 ;
}
return V_251 ;
}
static void F_142 ( struct V_237 * V_245 ,
struct V_205 * V_206 )
{
struct V_207 * V_253 ;
int V_174 ;
for ( V_174 = 0 , V_253 = V_206 -> V_133 -> V_204 ; V_174 < V_206 -> V_133 -> V_203 ; V_174 ++ , V_253 ++ ) {
if ( F_132 ( & V_253 -> V_209 , V_245 , V_206 , 0 ) ) {
F_63 ( V_253 -> V_236 ) ;
V_253 -> V_236 = NULL ;
}
}
V_206 -> V_133 -> V_233 = 0 ;
}
static unsigned int
F_143 ( struct V_205 * V_206 , struct V_237 * V_238 )
{
struct V_254 * V_255 ;
struct V_207 * V_235 ;
struct V_121 * V_17 ;
int V_174 , V_134 ;
unsigned int V_256 = 0 ;
V_255 = V_206 -> V_133 ;
V_235 = V_255 -> V_204 ;
for ( V_174 = 0 ; V_174 < V_255 -> V_203 ; V_174 ++ , V_235 ++ ) {
if ( F_124 ( & V_235 -> V_210 ) )
continue;
V_17 = F_144 () ;
if ( ! V_17 )
break;
V_17 -> V_241 = V_174 ;
V_17 -> V_12 = V_235 -> V_250 ;
V_235 -> V_250 = NULL ;
F_145 ( & V_17 -> V_32 , V_238 ) ;
V_256 ++ ;
}
for ( V_134 = V_174 ; V_134 < V_255 -> V_203 ; V_134 ++ , V_235 ++ ) {
if ( F_124 ( & V_235 -> V_210 ) )
continue;
F_146 ( & V_235 -> V_210 , V_235 -> V_250 , V_206 ) ;
F_63 ( V_235 -> V_250 ) ;
V_235 -> V_250 = NULL ;
}
return V_256 ;
}
static int
F_147 ( struct V_27 * V_27 , struct V_237 * V_257 ,
int V_240 , struct V_205 * V_206 )
{
struct V_121 * V_17 , * V_246 ;
F_148 ( V_238 ) ;
unsigned int V_256 = 0 ;
if ( ! F_124 ( V_257 ) ) {
V_17 = F_144 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_145 ( & V_17 -> V_32 , & V_238 ) ;
V_256 ++ ;
} else
F_146 ( V_257 , NULL , V_206 ) ;
}
V_256 += F_143 ( V_206 , & V_238 ) ;
if ( V_256 == 0 ) {
V_206 -> V_33 -> V_258 ( F_26 ( V_27 ) ) ;
goto V_90;
}
F_149 ( V_256 , & V_206 -> V_239 -> V_259 ) ;
F_133 (data, tmp, &list, pages) {
F_150 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_151 ( V_17 , V_257 , NULL , V_206 ) ;
F_131 ( F_152 ( V_27 ) , V_17 ,
V_17 -> V_116 , V_240 , 0 ) ;
} else {
struct V_207 * V_204 ;
V_204 = V_206 -> V_133 -> V_204 ;
F_151 ( V_17 , & V_204 [ V_17 -> V_241 ] . V_210 , V_17 -> V_12 , V_206 ) ;
F_130 ( V_17 , V_240 ) ;
}
}
V_90:
V_206 -> V_133 -> V_249 = 0 ;
return V_147 ;
}
static void
F_153 ( struct V_48 * V_157 )
{
F_154 ( F_78 ( V_157 , struct V_158 , V_167 ) ) ;
}
static struct V_36 *
F_155 ( struct V_27 * V_27 , T_4 V_156 )
{
struct V_201 * V_176 ;
V_176 = F_105 ( sizeof( * V_176 ) , V_156 ) ;
return & V_176 -> V_213 ;
}
static void
F_156 ( struct V_36 * V_37 )
{
F_81 ( F_99 ( V_37 ) ) ;
}
static struct V_254 *
F_157 ( struct V_27 * V_27 )
{
struct V_36 * V_105 = F_26 ( V_27 ) -> V_105 ;
if ( V_105 == NULL )
return NULL ;
else
return & F_99 ( V_105 ) -> V_202 ;
}
static int T_7 F_158 ( void )
{
F_96 ( V_260 L_28 ,
V_25 ) ;
return F_159 ( & V_261 ) ;
}
static void T_8 F_160 ( void )
{
F_96 ( V_260 L_29 ,
V_25 ) ;
F_161 ( & V_261 ) ;
}
