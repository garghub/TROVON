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
F_21 ( V_47 , V_41 ) ;
goto V_59;
case - V_60 :
if ( V_41 != NULL )
F_21 ( V_47 , V_41 ) ;
F_22 ( V_50 ) ;
goto V_59;
case - V_61 :
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
F_9 ( L_3
L_4 , V_25 , V_22 -> V_31 ,
V_43 -> V_68 ) ;
F_23 ( V_43 -> V_53 , V_22 -> V_31 ) ;
break;
case - V_69 :
case - V_70 :
F_24 ( V_22 , V_71 ) ;
break;
case - V_72 :
break;
case - V_73 :
case - V_74 :
case - V_75 :
case - V_76 :
case - V_77 :
case - V_78 :
F_9 ( L_5 , V_25 ,
V_22 -> V_31 ) ;
F_25 ( F_26 ( V_27 ) ) ;
F_27 ( & V_52 -> V_79 ) ;
goto V_80;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
case - V_87 :
F_9 ( L_6 , V_25 ,
V_22 -> V_31 ) ;
F_28 ( V_49 ) ;
F_29 ( V_38 , & V_37 -> V_39 ) ;
F_27 ( & V_52 -> V_79 ) ;
default:
V_80:
F_9 ( L_7 , V_25 ,
V_22 -> V_31 ) ;
return - V_88 ;
}
V_89:
V_22 -> V_31 = 0 ;
return - V_90 ;
V_59:
F_30 ( & V_50 -> V_91 , V_22 , NULL ) ;
if ( F_31 ( V_92 , & V_50 -> V_93 ) == 0 )
F_32 ( & V_50 -> V_91 , V_22 ) ;
goto V_89;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
V_94 = F_17 ( V_22 , V_17 -> args . V_95 -> V_41 ,
V_17 -> V_96 , V_19 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_12 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_90 :
F_34 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static void
F_35 ( struct V_16 * V_97 )
{
struct V_18 * V_19 = V_97 -> V_20 ;
if ( F_5 ( V_19 -> V_12 ) -> V_98 ||
V_97 -> V_99 . V_100 -> V_101 == V_102 )
return;
F_36 ( V_97 ) ;
F_9 ( L_8 , V_25 , V_19 -> V_27 -> V_103 ,
( unsigned long ) F_26 ( V_19 -> V_27 ) -> V_104 -> V_105 ) ;
}
bool
F_37 ( struct V_48 * V_106 )
{
return F_38 ( V_106 ) ||
F_39 ( V_106 ) ;
}
static bool
F_40 ( struct V_11 * V_12 )
{
struct V_48 * V_106 = F_19 ( V_12 ) ;
return F_37 ( V_106 ) ;
}
static void F_41 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_107 = V_17 ;
if ( F_40 ( V_107 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_107 ) ;
F_42 ( V_22 , 0 ) ;
return;
}
V_107 -> V_108 = F_33 ;
F_43 ( V_107 -> V_96 -> V_53 ,
& V_107 -> args . V_109 ,
& V_107 -> V_99 . V_110 ,
V_22 ) ;
}
static void F_44 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_107 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_107 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_107 -> V_20 -> V_111 -> V_112 ( V_22 , V_17 ) ;
}
static void F_45 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_107 = V_17 ;
F_46 ( V_22 , F_18 ( V_107 -> V_20 -> V_27 ) -> V_113 -> V_114 ) ;
}
static void F_47 ( void * V_17 )
{
struct V_35 * V_107 = V_17 ;
struct V_36 * V_37 = V_107 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_48 ( V_107 -> V_96 ) ;
V_107 -> V_20 -> V_111 -> V_115 ( V_17 ) ;
}
static int F_49 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
V_94 = F_17 ( V_22 , V_17 -> args . V_95 -> V_41 ,
V_17 -> V_96 , V_19 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_7 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_90 :
F_34 ( V_22 ) ;
return - V_90 ;
}
F_35 ( V_17 ) ;
return 0 ;
}
static void F_50 ( struct V_116 * V_17 )
{
struct V_117 * V_118 = F_51 ( V_17 -> V_32 . V_119 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_100 . V_120 , & V_118 -> V_121 ,
sizeof( V_17 -> V_100 . V_120 ) ) ;
V_17 -> V_100 . V_120 . V_17 [ 0 ] ++ ;
}
static int F_52 ( struct V_21 * V_22 ,
struct V_116 * V_17 )
{
int V_94 ;
V_94 = F_17 ( V_22 , NULL , V_17 -> V_96 ,
V_17 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_50 ( V_17 ) ;
return - V_90 ;
case - V_90 :
F_34 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_53 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_40 ( V_97 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_97 ) ;
F_42 ( V_22 , 0 ) ;
return;
}
F_43 ( V_97 -> V_96 -> V_53 ,
& V_97 -> args . V_109 ,
& V_97 -> V_99 . V_110 ,
V_22 ) ;
}
static void F_54 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_31 ( V_23 , & V_97 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_97 -> V_20 -> V_111 -> V_112 ( V_22 , V_17 ) ;
}
static void F_55 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
F_46 ( V_22 , F_18 ( V_97 -> V_20 -> V_27 ) -> V_113 -> V_114 ) ;
}
static void F_56 ( void * V_17 )
{
struct V_16 * V_97 = V_17 ;
struct V_36 * V_37 = V_97 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_48 ( V_97 -> V_96 ) ;
V_97 -> V_20 -> V_111 -> V_115 ( V_17 ) ;
}
static void F_57 ( struct V_21 * V_22 , void * V_17 )
{
struct V_116 * V_97 = V_17 ;
F_43 ( V_97 -> V_96 -> V_53 ,
& V_97 -> args . V_109 ,
& V_97 -> V_99 . V_110 ,
V_22 ) ;
}
static void F_58 ( struct V_21 * V_22 , void * V_17 )
{
struct V_116 * V_97 = V_17 ;
V_97 -> V_111 -> V_112 ( V_22 , V_17 ) ;
}
static void F_59 ( struct V_21 * V_22 , void * V_17 )
{
struct V_116 * V_122 = V_17 ;
F_46 ( V_22 , F_18 ( V_122 -> V_27 ) -> V_113 -> V_114 ) ;
}
static void F_60 ( void * V_123 )
{
struct V_116 * V_17 = V_123 ;
V_17 -> V_33 -> V_124 ( V_17 ) ;
F_61 ( V_17 -> V_12 ) ;
F_48 ( V_17 -> V_96 ) ;
F_62 ( V_17 ) ;
}
static enum V_125
F_63 ( struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_126 * V_127 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_128 , V_129 ;
struct V_130 * V_131 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_103 ,
V_17 -> args . V_132 , ( V_133 ) V_17 -> args . V_30 , V_3 ) ;
V_128 = F_64 ( V_12 , V_3 ) ;
V_129 = F_65 ( V_12 , V_128 ) ;
V_127 = F_66 ( V_12 , V_129 ) ;
if ( ! V_127 )
return V_134 ;
F_9 ( L_12 , V_25 ,
V_127 -> V_135 , F_67 ( & V_127 -> V_96 -> V_136 ) ) ;
F_68 ( & V_127 -> V_96 -> V_136 ) ;
V_17 -> V_96 = V_127 -> V_96 ;
V_131 = F_69 ( V_12 , V_128 ) ;
if ( V_131 )
V_17 -> args . V_131 = V_131 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_137 = V_3 ;
F_70 ( V_127 -> V_96 -> V_138 , V_17 ,
& V_139 , V_140 ) ;
return V_141 ;
}
static enum V_125
F_71 ( struct V_16 * V_17 , int V_142 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_126 * V_127 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_128 , V_129 ;
struct V_130 * V_131 ;
V_128 = F_64 ( V_12 , V_3 ) ;
V_129 = F_65 ( V_12 , V_128 ) ;
V_127 = F_66 ( V_12 , V_129 ) ;
if ( ! V_127 )
return V_134 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_103 , V_142 , ( V_133 ) V_17 -> args . V_30 ,
V_3 , V_127 -> V_135 , F_67 ( & V_127 -> V_96 -> V_136 ) ) ;
V_17 -> V_143 = F_49 ;
F_68 ( & V_127 -> V_96 -> V_136 ) ;
V_17 -> V_96 = V_127 -> V_96 ;
V_131 = F_69 ( V_12 , V_128 ) ;
if ( V_131 )
V_17 -> args . V_131 = V_131 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_72 ( V_127 -> V_96 -> V_138 , V_17 ,
& V_144 , V_142 ,
V_140 ) ;
return V_141 ;
}
static int
F_73 ( struct V_36 * V_37 ,
struct V_1 * V_145 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
T_4 V_150 )
{
struct V_48 * V_151 ;
struct V_152 * V_6 ;
int V_153 = - V_154 ;
struct V_46 * V_155 = F_18 ( V_37 -> V_45 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_147 -> V_156 . V_3 != 0 ||
V_147 -> V_156 . V_157 != V_158 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_89;
}
if ( V_145 -> V_10 > V_147 -> V_156 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_145 -> V_10 ) ;
goto V_89;
}
if ( ! V_145 -> V_5 || V_145 -> V_5 % V_159 ) {
F_9 ( L_17 ,
V_25 , V_145 -> V_5 ) ;
goto V_89;
}
V_151 = F_74 ( F_18 ( V_37 -> V_45 ) -> V_160 ,
F_18 ( V_37 -> V_45 ) -> V_42 , V_149 ) ;
if ( V_151 == NULL ) {
V_6 = F_75 ( V_37 -> V_45 , V_149 , V_150 ) ;
if ( V_6 == NULL )
goto V_89;
} else
V_6 = F_76 ( V_151 , struct V_152 , V_161 ) ;
if ( F_37 ( & V_6 -> V_161 ) )
goto V_162;
V_145 -> V_6 = V_6 ;
if ( V_145 -> V_163 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_145 -> V_163 ) ;
goto V_162;
}
if ( ( V_145 -> V_13 == V_14 &&
V_145 -> V_164 > 1 && V_145 -> V_164 != V_6 -> V_165 ) ||
( V_145 -> V_13 == V_15 &&
V_145 -> V_164 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_145 -> V_164 ) ;
goto V_162;
}
if ( V_145 -> V_5 % V_155 -> V_166 || V_145 -> V_5 % V_155 -> V_167 ) {
F_9 ( L_20
L_21 , V_25 , V_145 -> V_5 , V_155 -> V_166 ,
V_155 -> V_167 ) ;
}
V_153 = 0 ;
V_89:
F_9 ( L_22 , V_25 , V_153 ) ;
return V_153 ;
V_162:
F_77 ( V_6 ) ;
goto V_89;
}
static void F_78 ( struct V_1 * V_145 )
{
int V_168 ;
for ( V_168 = 0 ; V_168 < V_145 -> V_164 ; V_168 ++ ) {
if ( ! V_145 -> V_169 [ V_168 ] )
break;
F_79 ( V_145 -> V_169 [ V_168 ] ) ;
}
F_79 ( V_145 -> V_169 ) ;
V_145 -> V_169 = NULL ;
}
static void
F_80 ( struct V_1 * V_145 )
{
F_78 ( V_145 ) ;
F_79 ( V_145 ) ;
}
static int
F_81 ( struct V_36 * V_170 ,
struct V_1 * V_145 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
T_4 V_150 )
{
struct V_171 V_172 ;
struct V_173 V_174 ;
struct V_175 * V_176 ;
T_5 * V_177 ;
T_6 V_178 ;
int V_168 ;
F_9 ( L_23 , V_25 ) ;
V_176 = F_82 ( V_150 ) ;
if ( ! V_176 )
return - V_179 ;
F_83 ( & V_172 , & V_174 , V_147 -> V_180 -> V_32 , V_147 -> V_180 -> V_181 ) ;
F_84 ( & V_172 , F_85 ( V_176 ) , V_159 ) ;
V_177 = F_86 ( & V_172 , V_182 + 20 ) ;
if ( F_87 ( ! V_177 ) )
goto V_183;
memcpy ( V_149 , V_177 , sizeof( * V_149 ) ) ;
V_177 += F_88 ( V_182 ) ;
F_89 ( V_149 ) ;
V_178 = F_90 ( V_177 ++ ) ;
if ( V_178 & V_184 )
V_145 -> V_98 = 1 ;
if ( V_178 & V_185 )
V_145 -> V_13 = V_15 ;
else
V_145 -> V_13 = V_14 ;
V_145 -> V_5 = V_178 & ~ V_186 ;
V_145 -> V_163 = F_90 ( V_177 ++ ) ;
V_177 = F_91 ( V_177 , & V_145 -> V_10 ) ;
V_145 -> V_164 = F_90 ( V_177 ++ ) ;
F_9 ( L_24 ,
V_25 , V_178 , V_145 -> V_164 , V_145 -> V_163 ,
V_145 -> V_10 ) ;
if ( V_145 -> V_164 >
F_92 ( V_187 , V_188 ) )
goto V_183;
if ( V_145 -> V_164 > 0 ) {
V_145 -> V_169 = F_93 ( V_145 -> V_164 , sizeof( V_145 -> V_169 [ 0 ] ) ,
V_150 ) ;
if ( ! V_145 -> V_169 )
goto V_183;
}
for ( V_168 = 0 ; V_168 < V_145 -> V_164 ; V_168 ++ ) {
V_145 -> V_169 [ V_168 ] = F_94 ( sizeof( struct V_130 ) , V_150 ) ;
if ( ! V_145 -> V_169 [ V_168 ] )
goto V_189;
V_177 = F_86 ( & V_172 , 4 ) ;
if ( F_87 ( ! V_177 ) )
goto V_189;
V_145 -> V_169 [ V_168 ] -> V_190 = F_90 ( V_177 ++ ) ;
if ( sizeof( struct V_130 ) < V_145 -> V_169 [ V_168 ] -> V_190 ) {
F_95 ( V_191 L_25 ,
V_168 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
goto V_189;
}
V_177 = F_86 ( & V_172 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
if ( F_87 ( ! V_177 ) )
goto V_189;
memcpy ( V_145 -> V_169 [ V_168 ] -> V_17 , V_177 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
F_9 ( L_26 , V_25 ,
V_145 -> V_169 [ V_168 ] -> V_190 ) ;
}
F_96 ( V_176 ) ;
return 0 ;
V_189:
F_78 ( V_145 ) ;
V_183:
F_96 ( V_176 ) ;
return - V_85 ;
}
static void
F_97 ( struct V_11 * V_12 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_77 ( V_145 -> V_6 ) ;
if ( V_12 -> V_192 . V_193 == V_194 ) {
struct V_195 * V_170 ;
V_170 = F_98 ( V_12 -> V_44 ) ;
V_170 -> V_196 . V_197 = 0 ;
F_79 ( V_170 -> V_196 . V_198 ) ;
V_170 -> V_196 . V_198 = NULL ;
}
F_80 ( V_145 ) ;
}
static int
F_99 ( struct V_11 * V_12 ,
struct V_199 * V_200 ,
T_4 V_150 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
struct V_201 * V_198 ;
int V_190 ;
if ( V_145 -> V_98 )
return 0 ;
if ( V_200 -> V_127 -> V_197 != 0 ) {
return 0 ;
}
V_190 = ( V_145 -> V_13 == V_14 ) ?
V_145 -> V_6 -> V_165 : V_145 -> V_6 -> V_7 ;
V_198 = F_93 ( V_190 , sizeof( struct V_201 ) ,
V_150 ) ;
if ( ! V_198 )
return - V_179 ;
else {
int V_168 ;
F_100 ( V_200 -> V_202 ) ;
if ( V_200 -> V_127 -> V_197 != 0 )
F_79 ( V_198 ) ;
else {
V_200 -> V_127 -> V_198 = V_198 ;
V_200 -> V_127 -> V_197 = V_190 ;
for ( V_168 = 0 ; V_168 < V_190 ; V_168 ++ ) {
F_101 ( & V_198 [ V_168 ] . V_203 ) ;
F_101 ( & V_198 [ V_168 ] . V_204 ) ;
}
}
F_102 ( V_200 -> V_202 ) ;
return 0 ;
}
}
static struct V_11 *
F_103 ( struct V_36 * V_205 ,
struct V_146 * V_147 ,
T_4 V_150 )
{
struct V_1 * V_145 ;
int V_206 ;
struct V_148 V_149 ;
F_9 ( L_14 , V_25 ) ;
V_145 = F_104 ( sizeof( * V_145 ) , V_150 ) ;
if ( ! V_145 )
return NULL ;
V_206 = F_81 ( V_205 , V_145 , V_147 , & V_149 , V_150 ) ;
if ( V_206 != 0 || F_73 ( V_205 , V_145 , V_147 , & V_149 , V_150 ) ) {
F_80 ( V_145 ) ;
return NULL ;
}
return & V_145 -> V_207 ;
}
static bool
F_105 ( struct V_208 * V_209 , struct V_117 * V_210 ,
struct V_117 * V_211 )
{
T_3 V_212 , V_213 ;
T_2 V_5 ;
if ( ! F_106 ( V_209 , V_210 , V_211 ) ||
! F_107 ( V_209 , V_210 , V_211 ) )
return false ;
V_212 = ( T_3 ) F_108 ( V_210 ) ;
V_213 = ( T_3 ) F_108 ( V_211 ) ;
V_5 = F_5 ( V_209 -> V_214 ) -> V_5 ;
F_109 ( V_212 , V_5 ) ;
F_109 ( V_213 , V_5 ) ;
return ( V_212 == V_213 ) ;
}
static void
F_110 ( struct V_208 * V_209 ,
struct V_117 * V_211 )
{
F_111 ( V_209 -> V_214 != NULL ) ;
if ( V_211 -> V_215 != V_211 -> V_216 ) {
F_112 ( V_209 ) ;
return;
}
V_209 -> V_214 = F_113 ( V_209 -> V_217 ,
V_211 -> V_218 ,
0 ,
V_158 ,
V_219 ,
V_220 ) ;
if ( V_209 -> V_214 == NULL )
F_112 ( V_209 ) ;
}
static void
F_114 ( struct V_208 * V_209 ,
struct V_117 * V_211 )
{
struct V_199 V_200 ;
int V_153 ;
F_111 ( V_209 -> V_214 != NULL ) ;
if ( V_211 -> V_215 != V_211 -> V_216 )
goto V_221;
V_209 -> V_214 = F_113 ( V_209 -> V_217 ,
V_211 -> V_218 ,
0 ,
V_158 ,
V_194 ,
V_222 ) ;
if ( V_209 -> V_214 == NULL )
goto V_221;
F_115 ( & V_200 , V_209 -> V_217 , V_209 -> V_223 ) ;
V_153 = F_99 ( V_209 -> V_214 , & V_200 , V_222 ) ;
if ( V_153 < 0 ) {
F_61 ( V_209 -> V_214 ) ;
V_209 -> V_214 = NULL ;
goto V_221;
}
return;
V_221:
F_116 ( V_209 ) ;
}
static T_2 F_117 ( struct V_1 * V_145 , T_2 V_128 )
{
if ( V_145 -> V_13 == V_14 )
return F_65 ( & V_145 -> V_207 , V_128 ) ;
else
return V_128 ;
}
static void
F_118 ( struct V_117 * V_211 ,
struct V_199 * V_200 )
{
struct V_11 * V_224 = NULL ;
F_100 ( V_200 -> V_202 ) ;
if ( ! F_15 ( V_225 , & V_211 -> V_226 ) )
goto V_89;
V_200 -> V_127 -> V_227 -- ;
if ( F_119 ( & V_211 -> V_228 ) ) {
struct V_201 * V_229 ;
V_229 = F_120 ( & V_211 -> V_228 ,
struct V_201 ,
V_203 ) ;
V_224 = V_229 -> V_230 ;
V_229 -> V_230 = NULL ;
}
V_89:
F_121 ( V_211 , V_200 ) ;
F_102 ( V_200 -> V_202 ) ;
F_61 ( V_224 ) ;
}
static struct V_231 *
F_122 ( struct V_117 * V_211 ,
struct V_11 * V_12 ,
struct V_199 * V_200 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
T_2 V_168 , V_128 ;
struct V_231 * V_232 ;
struct V_201 * V_198 ;
if ( V_145 -> V_98 )
return & V_200 -> V_233 -> V_232 ;
V_128 = F_64 ( V_12 , F_108 ( V_211 ) ) ;
V_168 = F_117 ( V_145 , V_128 ) ;
V_198 = V_200 -> V_127 -> V_198 ;
V_232 = & V_198 [ V_168 ] . V_203 ;
if ( F_123 ( V_232 ) ) {
V_198 [ V_168 ] . V_230 = F_124 ( V_12 ) ;
}
F_29 ( V_225 , & V_211 -> V_226 ) ;
V_200 -> V_127 -> V_227 ++ ;
return V_232 ;
}
static void
F_125 ( struct V_117 * V_211 ,
struct V_11 * V_12 ,
struct V_199 * V_200 )
{
struct V_231 * V_232 ;
V_232 = F_122 ( V_211 , V_12 , V_200 ) ;
F_126 ( V_211 , V_232 , V_200 ) ;
}
static T_2 F_127 ( struct V_11 * V_12 , T_2 V_168 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_168 ;
else
return F_65 ( V_12 , V_168 ) ;
}
static struct V_130 *
F_128 ( struct V_11 * V_12 , T_2 V_168 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_164 == 1 )
V_168 = 0 ;
else if ( V_2 -> V_164 == 0 )
return NULL ;
}
return V_2 -> V_169 [ V_168 ] ;
}
static int F_129 ( struct V_116 * V_17 , int V_234 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_126 * V_127 ;
T_2 V_129 ;
struct V_130 * V_131 ;
V_129 = F_127 ( V_12 , V_17 -> V_235 ) ;
V_127 = F_66 ( V_12 , V_129 ) ;
if ( ! V_127 ) {
F_50 ( V_17 ) ;
F_60 ( V_17 ) ;
return - V_90 ;
}
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_103 , V_234 , F_67 ( & V_127 -> V_96 -> V_136 ) ) ;
V_17 -> V_236 = F_52 ;
F_68 ( & V_127 -> V_96 -> V_136 ) ;
V_17 -> V_96 = V_127 -> V_96 ;
V_131 = F_128 ( V_12 , V_17 -> V_235 ) ;
if ( V_131 )
V_17 -> args . V_131 = V_131 ;
return F_130 ( V_127 -> V_96 -> V_138 , V_17 ,
& V_237 , V_234 ,
V_140 ) ;
}
static int
F_131 ( struct V_231 * V_238 , struct V_231 * V_239 ,
struct V_199 * V_200 , int F_92 )
{
struct V_117 * V_211 , * V_240 ;
int V_241 = 0 ;
F_132 (req, tmp, src, wb_list) {
if ( ! F_133 ( V_211 ) )
continue;
F_134 ( & V_211 -> V_242 ) ;
if ( F_135 ( V_200 -> V_202 ) )
F_136 ( V_211 , V_240 , V_228 ) ;
F_121 ( V_211 , V_200 ) ;
F_137 ( V_225 , & V_211 -> V_226 ) ;
F_138 ( V_211 , V_239 ) ;
V_241 ++ ;
if ( ( V_241 == F_92 ) && ! V_200 -> V_34 )
break;
}
return V_241 ;
}
static int
F_139 ( struct V_201 * V_229 ,
struct V_199 * V_200 ,
int F_92 )
{
struct V_231 * V_238 = & V_229 -> V_203 ;
struct V_231 * V_239 = & V_229 -> V_204 ;
int V_241 ;
V_241 = F_131 ( V_238 , V_239 , V_200 , F_92 ) ;
if ( V_241 ) {
V_200 -> V_127 -> V_227 -= V_241 ;
V_200 -> V_127 -> V_243 += V_241 ;
V_229 -> V_244 = V_229 -> V_230 ;
if ( F_123 ( V_238 ) )
V_229 -> V_230 = NULL ;
else
F_124 ( V_229 -> V_244 ) ;
}
return V_241 ;
}
static int F_140 ( struct V_199 * V_200 ,
int F_92 )
{
int V_168 , V_245 = 0 , V_246 ;
for ( V_168 = 0 ; V_168 < V_200 -> V_127 -> V_197 && F_92 != 0 ; V_168 ++ ) {
V_246 = F_139 ( & V_200 -> V_127 -> V_198 [ V_168 ] ,
V_200 , F_92 ) ;
F_92 -= V_246 ;
V_245 += V_246 ;
}
return V_245 ;
}
static void F_141 ( struct V_231 * V_239 ,
struct V_199 * V_200 )
{
struct V_201 * V_247 ;
int V_168 ;
for ( V_168 = 0 , V_247 = V_200 -> V_127 -> V_198 ; V_168 < V_200 -> V_127 -> V_197 ; V_168 ++ , V_247 ++ ) {
if ( F_131 ( & V_247 -> V_203 , V_239 , V_200 , 0 ) ) {
F_61 ( V_247 -> V_230 ) ;
V_247 -> V_230 = NULL ;
}
}
V_200 -> V_127 -> V_227 = 0 ;
}
static unsigned int
F_142 ( struct V_199 * V_200 , struct V_231 * V_232 )
{
struct V_248 * V_249 ;
struct V_201 * V_229 ;
struct V_116 * V_17 ;
int V_168 , V_128 ;
unsigned int V_250 = 0 ;
V_249 = V_200 -> V_127 ;
V_229 = V_249 -> V_198 ;
for ( V_168 = 0 ; V_168 < V_249 -> V_197 ; V_168 ++ , V_229 ++ ) {
if ( F_123 ( & V_229 -> V_204 ) )
continue;
V_17 = F_143 () ;
if ( ! V_17 )
break;
V_17 -> V_235 = V_168 ;
V_17 -> V_12 = V_229 -> V_244 ;
V_229 -> V_244 = NULL ;
F_144 ( & V_17 -> V_32 , V_232 ) ;
V_250 ++ ;
}
for ( V_128 = V_168 ; V_128 < V_249 -> V_197 ; V_128 ++ , V_229 ++ ) {
if ( F_123 ( & V_229 -> V_204 ) )
continue;
F_145 ( & V_229 -> V_204 , V_229 -> V_244 , V_200 ) ;
F_61 ( V_229 -> V_244 ) ;
V_229 -> V_244 = NULL ;
}
return V_250 ;
}
static int
F_146 ( struct V_27 * V_27 , struct V_231 * V_251 ,
int V_234 , struct V_199 * V_200 )
{
struct V_116 * V_17 , * V_240 ;
F_147 ( V_232 ) ;
unsigned int V_250 = 0 ;
if ( ! F_123 ( V_251 ) ) {
V_17 = F_143 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_144 ( & V_17 -> V_32 , & V_232 ) ;
V_250 ++ ;
} else
F_145 ( V_251 , NULL , V_200 ) ;
}
V_250 += F_142 ( V_200 , & V_232 ) ;
if ( V_250 == 0 ) {
V_200 -> V_33 -> V_252 ( F_26 ( V_27 ) ) ;
goto V_89;
}
F_148 ( V_250 , & V_200 -> V_233 -> V_253 ) ;
F_132 (data, tmp, &list, pages) {
F_149 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_150 ( V_17 , V_251 , NULL , V_200 ) ;
F_130 ( F_151 ( V_27 ) , V_17 ,
V_17 -> V_111 , V_234 , 0 ) ;
} else {
struct V_201 * V_198 ;
V_198 = V_200 -> V_127 -> V_198 ;
F_150 ( V_17 , & V_198 [ V_17 -> V_235 ] . V_204 , V_17 -> V_12 , V_200 ) ;
F_129 ( V_17 , V_234 ) ;
}
}
V_89:
V_200 -> V_127 -> V_243 = 0 ;
return V_141 ;
}
static void
F_152 ( struct V_48 * V_151 )
{
F_153 ( F_76 ( V_151 , struct V_152 , V_161 ) ) ;
}
static struct V_36 *
F_154 ( struct V_27 * V_27 , T_4 V_150 )
{
struct V_195 * V_170 ;
V_170 = F_104 ( sizeof( * V_170 ) , V_150 ) ;
return & V_170 -> V_207 ;
}
static void
F_155 ( struct V_36 * V_37 )
{
F_79 ( F_98 ( V_37 ) ) ;
}
static struct V_248 *
F_156 ( struct V_27 * V_27 )
{
struct V_36 * V_104 = F_26 ( V_27 ) -> V_104 ;
if ( V_104 == NULL )
return NULL ;
else
return & F_98 ( V_104 ) -> V_196 ;
}
static int T_7 F_157 ( void )
{
F_95 ( V_254 L_28 ,
V_25 ) ;
return F_158 ( & V_255 ) ;
}
static void T_8 F_159 ( void )
{
F_95 ( V_254 L_29 ,
V_25 ) ;
F_160 ( & V_255 ) ;
}
