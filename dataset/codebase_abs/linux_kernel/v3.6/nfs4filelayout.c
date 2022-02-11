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
V_19 -> V_33 ) ;
}
}
static void F_12 ( struct V_34 * V_17 )
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
V_19 -> V_33 ) ;
}
}
static int F_14 ( struct V_21 * V_22 ,
struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_11 * V_12 )
{
struct V_27 * V_27 = V_12 -> V_39 -> V_40 ;
struct V_41 * V_42 = F_15 ( V_27 ) ;
struct V_43 * V_44 = F_16 ( V_12 ) ;
struct V_37 * V_45 = V_42 -> V_37 ;
struct V_46 * V_47 = & V_38 -> V_48 -> V_49 ;
if ( V_22 -> V_31 >= 0 )
return 0 ;
switch ( V_22 -> V_31 ) {
case - V_50 :
case - V_51 :
case - V_52 :
if ( V_36 == NULL )
break;
F_17 ( V_36 -> V_27 ) ;
case - V_53 :
if ( V_36 == NULL )
break;
F_18 ( V_42 , V_36 ) ;
goto V_54;
case - V_55 :
if ( V_36 != NULL )
F_18 ( V_42 , V_36 ) ;
F_19 ( V_45 ) ;
goto V_54;
case - V_56 :
case - V_57 :
case - V_58 :
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
F_9 ( L_3
L_4 , V_25 , V_22 -> V_31 ,
V_38 -> V_63 ) ;
F_20 ( V_38 -> V_48 , V_22 -> V_31 ) ;
break;
case - V_64 :
case - V_65 :
case - V_66 :
F_21 ( V_22 , V_67 ) ;
break;
case - V_68 :
break;
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
case - V_73 :
case - V_74 :
F_9 ( L_5 , V_25 ,
V_22 -> V_31 ) ;
F_22 ( V_75 ,
& F_23 ( V_27 ) -> V_76 -> V_77 ) ;
F_24 ( F_23 ( V_27 ) ) ;
F_25 ( & V_47 -> V_78 ) ;
goto V_79;
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
F_9 ( L_6 , V_25 ,
V_22 -> V_31 ) ;
F_26 ( V_44 ) ;
F_27 ( V_87 , & F_23 ( V_27 ) -> V_24 ) ;
F_28 ( V_27 ) ;
F_25 ( & V_47 -> V_78 ) ;
F_29 ( V_38 ) ;
default:
V_79:
F_9 ( L_7 , V_25 ,
V_22 -> V_31 ) ;
return - V_88 ;
}
V_89:
V_22 -> V_31 = 0 ;
return - V_90 ;
V_54:
F_30 ( & V_45 -> V_91 , V_22 , NULL ) ;
if ( F_31 ( V_92 , & V_45 -> V_93 ) == 0 )
F_32 ( & V_45 -> V_91 , V_22 ) ;
goto V_89;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
V_94 = F_14 ( V_22 , V_17 -> args . V_95 -> V_36 ,
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
( unsigned long ) F_23 ( V_19 -> V_27 ) -> V_76 -> V_104 ) ;
}
static void F_37 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_105 = V_17 ;
if ( F_38 ( V_105 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_105 ) ;
F_39 ( V_22 , 0 ) ;
return;
}
V_105 -> V_106 = F_33 ;
if ( F_40 ( V_105 -> V_96 -> V_48 ,
& V_105 -> args . V_107 , & V_105 -> V_99 . V_108 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_42 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_105 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_105 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_105 -> V_20 -> V_109 -> V_110 ( V_22 , V_17 ) ;
}
static void F_43 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_105 = V_17 ;
F_44 ( V_22 , F_15 ( V_105 -> V_20 -> V_27 ) -> V_111 -> V_112 ) ;
}
static void F_45 ( void * V_17 )
{
struct V_34 * V_105 = V_17 ;
F_46 ( V_105 -> V_96 ) ;
V_105 -> V_20 -> V_109 -> V_113 ( V_17 ) ;
}
static int F_47 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
V_94 = F_14 ( V_22 , V_17 -> args . V_95 -> V_36 ,
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
static void F_48 ( struct V_114 * V_17 )
{
struct V_115 * V_116 = F_49 ( V_17 -> V_32 . V_117 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_100 . V_118 , & V_116 -> V_119 ,
sizeof( V_17 -> V_100 . V_118 ) ) ;
V_17 -> V_100 . V_118 . V_17 [ 0 ] ++ ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_114 * V_17 )
{
int V_94 ;
V_94 = F_14 ( V_22 , NULL , V_17 -> V_96 ,
V_17 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_48 ( V_17 ) ;
return - V_90 ;
case - V_90 :
F_34 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_51 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_38 ( V_97 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_97 ) ;
F_39 ( V_22 , 0 ) ;
return;
}
if ( F_40 ( V_97 -> V_96 -> V_48 ,
& V_97 -> args . V_107 , & V_97 -> V_99 . V_108 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_52 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_31 ( V_23 , & V_97 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_97 -> V_20 -> V_109 -> V_110 ( V_22 , V_17 ) ;
}
static void F_53 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
F_44 ( V_22 , F_15 ( V_97 -> V_20 -> V_27 ) -> V_111 -> V_112 ) ;
}
static void F_54 ( void * V_17 )
{
struct V_16 * V_97 = V_17 ;
F_46 ( V_97 -> V_96 ) ;
V_97 -> V_20 -> V_109 -> V_113 ( V_17 ) ;
}
static void F_55 ( struct V_21 * V_22 , void * V_17 )
{
struct V_114 * V_97 = V_17 ;
if ( F_40 ( V_97 -> V_96 -> V_48 ,
& V_97 -> args . V_107 , & V_97 -> V_99 . V_108 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_56 ( struct V_21 * V_22 , void * V_17 )
{
struct V_114 * V_97 = V_17 ;
V_97 -> V_109 -> V_110 ( V_22 , V_17 ) ;
}
static void F_57 ( struct V_21 * V_22 , void * V_17 )
{
struct V_114 * V_120 = V_17 ;
F_44 ( V_22 , F_15 ( V_120 -> V_27 ) -> V_111 -> V_112 ) ;
}
static void F_58 ( void * V_121 )
{
struct V_114 * V_17 = V_121 ;
V_17 -> V_33 -> V_122 ( V_17 ) ;
F_59 ( V_17 -> V_12 ) ;
F_46 ( V_17 -> V_96 ) ;
F_60 ( V_17 ) ;
}
static enum V_123
F_61 ( struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_124 * V_125 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_126 , V_127 ;
struct V_128 * V_129 ;
int V_130 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_103 ,
V_17 -> args . V_131 , ( V_132 ) V_17 -> args . V_30 , V_3 ) ;
V_126 = F_62 ( V_12 , V_3 ) ;
V_127 = F_63 ( V_12 , V_126 ) ;
V_125 = F_64 ( V_12 , V_127 ) ;
if ( ! V_125 )
return V_133 ;
F_9 ( L_12 , V_25 ,
V_125 -> V_134 , F_65 ( & V_125 -> V_96 -> V_135 ) ) ;
F_66 ( & V_125 -> V_96 -> V_135 ) ;
V_17 -> V_96 = V_125 -> V_96 ;
V_129 = F_67 ( V_12 , V_126 ) ;
if ( V_129 )
V_17 -> args . V_129 = V_129 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_136 = V_3 ;
V_130 = F_68 ( V_125 -> V_96 -> V_137 , V_17 ,
& V_138 , V_139 ) ;
F_69 ( V_130 != 0 ) ;
return V_140 ;
}
static enum V_123
F_70 ( struct V_16 * V_17 , int V_141 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_124 * V_125 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_126 , V_127 ;
struct V_128 * V_129 ;
int V_130 ;
V_126 = F_62 ( V_12 , V_3 ) ;
V_127 = F_63 ( V_12 , V_126 ) ;
V_125 = F_64 ( V_12 , V_127 ) ;
if ( ! V_125 )
return V_133 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_103 , V_141 , ( V_132 ) V_17 -> args . V_30 ,
V_3 , V_125 -> V_134 , F_65 ( & V_125 -> V_96 -> V_135 ) ) ;
V_17 -> V_142 = F_47 ;
F_66 ( & V_125 -> V_96 -> V_135 ) ;
V_17 -> V_96 = V_125 -> V_96 ;
V_129 = F_67 ( V_12 , V_126 ) ;
if ( V_129 )
V_17 -> args . V_129 = V_129 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_130 = F_71 ( V_125 -> V_96 -> V_137 , V_17 ,
& V_143 , V_141 ,
V_139 ) ;
F_69 ( V_130 != 0 ) ;
return V_140 ;
}
static int
F_72 ( struct V_144 * V_145 ,
struct V_1 * V_146 ,
struct V_147 * V_148 ,
struct V_149 * V_150 ,
T_4 V_151 )
{
struct V_43 * V_152 ;
struct V_153 * V_6 ;
int V_130 = - V_154 ;
struct V_41 * V_155 = F_15 ( V_145 -> V_40 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_148 -> V_156 . V_3 != 0 ||
V_148 -> V_156 . V_157 != V_158 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_89;
}
if ( V_146 -> V_10 > V_148 -> V_156 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_146 -> V_10 ) ;
goto V_89;
}
if ( ! V_146 -> V_5 || V_146 -> V_5 % V_159 ) {
F_9 ( L_17 ,
V_25 , V_146 -> V_5 ) ;
goto V_89;
}
V_152 = F_73 ( F_15 ( V_145 -> V_40 ) -> V_160 ,
F_15 ( V_145 -> V_40 ) -> V_37 , V_150 ) ;
if ( V_152 == NULL ) {
V_6 = F_74 ( V_145 -> V_40 , V_150 , V_151 ) ;
if ( V_6 == NULL )
goto V_89;
} else
V_6 = F_75 ( V_152 , struct V_153 , V_161 ) ;
if ( F_31 ( V_162 , & V_6 -> V_161 . V_24 ) )
goto V_163;
V_146 -> V_6 = V_6 ;
if ( V_146 -> V_164 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_146 -> V_164 ) ;
goto V_163;
}
if ( ( V_146 -> V_13 == V_14 &&
V_146 -> V_165 > 1 && V_146 -> V_165 != V_6 -> V_166 ) ||
( V_146 -> V_13 == V_15 &&
V_146 -> V_165 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_146 -> V_165 ) ;
goto V_163;
}
if ( V_146 -> V_5 % V_155 -> V_167 || V_146 -> V_5 % V_155 -> V_168 ) {
F_9 ( L_20
L_21 , V_25 , V_146 -> V_5 , V_155 -> V_167 ,
V_155 -> V_168 ) ;
}
V_130 = 0 ;
V_89:
F_9 ( L_22 , V_25 , V_130 ) ;
return V_130 ;
V_163:
F_76 ( V_6 ) ;
goto V_89;
}
static void F_77 ( struct V_1 * V_146 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_146 -> V_165 ; V_169 ++ ) {
if ( ! V_146 -> V_170 [ V_169 ] )
break;
F_78 ( V_146 -> V_170 [ V_169 ] ) ;
}
F_78 ( V_146 -> V_170 ) ;
V_146 -> V_170 = NULL ;
}
static void
F_79 ( struct V_1 * V_146 )
{
F_77 ( V_146 ) ;
F_78 ( V_146 ) ;
}
static int
F_80 ( struct V_144 * V_171 ,
struct V_1 * V_146 ,
struct V_147 * V_148 ,
struct V_149 * V_150 ,
T_4 V_151 )
{
struct V_172 V_173 ;
struct V_174 V_175 ;
struct V_176 * V_177 ;
T_5 * V_178 ;
T_6 V_179 ;
int V_169 ;
F_9 ( L_23 , V_25 ) ;
V_177 = F_81 ( V_151 ) ;
if ( ! V_177 )
return - V_180 ;
F_82 ( & V_173 , & V_175 , V_148 -> V_181 -> V_32 , V_148 -> V_181 -> V_182 ) ;
F_83 ( & V_173 , F_84 ( V_177 ) , V_159 ) ;
V_178 = F_85 ( & V_173 , V_183 + 20 ) ;
if ( F_86 ( ! V_178 ) )
goto V_184;
memcpy ( V_150 , V_178 , sizeof( * V_150 ) ) ;
V_178 += F_87 ( V_183 ) ;
F_88 ( V_150 ) ;
V_179 = F_89 ( V_178 ++ ) ;
if ( V_179 & V_185 )
V_146 -> V_98 = 1 ;
if ( V_179 & V_186 )
V_146 -> V_13 = V_15 ;
else
V_146 -> V_13 = V_14 ;
V_146 -> V_5 = V_179 & ~ V_187 ;
V_146 -> V_164 = F_89 ( V_178 ++ ) ;
V_178 = F_90 ( V_178 , & V_146 -> V_10 ) ;
V_146 -> V_165 = F_89 ( V_178 ++ ) ;
F_9 ( L_24 ,
V_25 , V_179 , V_146 -> V_165 , V_146 -> V_164 ,
V_146 -> V_10 ) ;
if ( V_146 -> V_165 >
F_91 ( V_188 , V_189 ) )
goto V_184;
if ( V_146 -> V_165 > 0 ) {
V_146 -> V_170 = F_92 ( V_146 -> V_165 * sizeof( struct V_128 * ) ,
V_151 ) ;
if ( ! V_146 -> V_170 )
goto V_184;
}
for ( V_169 = 0 ; V_169 < V_146 -> V_165 ; V_169 ++ ) {
V_146 -> V_170 [ V_169 ] = F_93 ( sizeof( struct V_128 ) , V_151 ) ;
if ( ! V_146 -> V_170 [ V_169 ] )
goto V_190;
V_178 = F_85 ( & V_173 , 4 ) ;
if ( F_86 ( ! V_178 ) )
goto V_190;
V_146 -> V_170 [ V_169 ] -> V_191 = F_89 ( V_178 ++ ) ;
if ( sizeof( struct V_128 ) < V_146 -> V_170 [ V_169 ] -> V_191 ) {
F_94 ( V_192 L_25 ,
V_169 , V_146 -> V_170 [ V_169 ] -> V_191 ) ;
goto V_190;
}
V_178 = F_85 ( & V_173 , V_146 -> V_170 [ V_169 ] -> V_191 ) ;
if ( F_86 ( ! V_178 ) )
goto V_190;
memcpy ( V_146 -> V_170 [ V_169 ] -> V_17 , V_178 , V_146 -> V_170 [ V_169 ] -> V_191 ) ;
F_9 ( L_26 , V_25 ,
V_146 -> V_170 [ V_169 ] -> V_191 ) ;
}
F_95 ( V_177 ) ;
return 0 ;
V_190:
F_77 ( V_146 ) ;
V_184:
F_95 ( V_177 ) ;
return - V_84 ;
}
static void
F_96 ( struct V_11 * V_12 )
{
struct V_1 * V_146 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_76 ( V_146 -> V_6 ) ;
if ( V_12 -> V_193 . V_194 == V_195 ) {
struct V_196 * V_171 ;
V_171 = F_97 ( V_12 -> V_39 ) ;
V_171 -> V_197 . V_198 = 0 ;
F_78 ( V_171 -> V_197 . V_199 ) ;
V_171 -> V_197 . V_199 = NULL ;
}
F_79 ( V_146 ) ;
}
static int
F_98 ( struct V_11 * V_12 ,
struct V_200 * V_201 ,
T_4 V_151 )
{
struct V_1 * V_146 = F_5 ( V_12 ) ;
struct V_202 * V_199 ;
int V_191 ;
if ( V_146 -> V_98 )
return 0 ;
if ( V_201 -> V_125 -> V_198 != 0 ) {
return 0 ;
}
V_191 = ( V_146 -> V_13 == V_14 ) ?
V_146 -> V_6 -> V_166 : V_146 -> V_6 -> V_7 ;
V_199 = F_99 ( V_191 , sizeof( struct V_202 ) ,
V_151 ) ;
if ( ! V_199 )
return - V_180 ;
else {
int V_169 ;
F_100 ( V_201 -> V_203 ) ;
if ( V_201 -> V_125 -> V_198 != 0 )
F_78 ( V_199 ) ;
else {
V_201 -> V_125 -> V_199 = V_199 ;
V_201 -> V_125 -> V_198 = V_191 ;
for ( V_169 = 0 ; V_169 < V_191 ; V_169 ++ ) {
F_101 ( & V_199 [ V_169 ] . V_204 ) ;
F_101 ( & V_199 [ V_169 ] . V_205 ) ;
}
}
F_102 ( V_201 -> V_203 ) ;
return 0 ;
}
}
static struct V_11 *
F_103 ( struct V_144 * V_206 ,
struct V_147 * V_148 ,
T_4 V_151 )
{
struct V_1 * V_146 ;
int V_207 ;
struct V_149 V_150 ;
F_9 ( L_14 , V_25 ) ;
V_146 = F_92 ( sizeof( * V_146 ) , V_151 ) ;
if ( ! V_146 )
return NULL ;
V_207 = F_80 ( V_206 , V_146 , V_148 , & V_150 , V_151 ) ;
if ( V_207 != 0 || F_72 ( V_206 , V_146 , V_148 , & V_150 , V_151 ) ) {
F_79 ( V_146 ) ;
return NULL ;
}
return & V_146 -> V_208 ;
}
static bool
F_104 ( struct V_209 * V_210 , struct V_115 * V_211 ,
struct V_115 * V_212 )
{
T_3 V_213 , V_214 ;
T_2 V_5 ;
if ( ! F_105 ( V_210 , V_211 , V_212 ) ||
! F_106 ( V_210 , V_211 , V_212 ) )
return false ;
V_213 = ( T_3 ) F_107 ( V_211 ) ;
V_214 = ( T_3 ) F_107 ( V_212 ) ;
V_5 = F_5 ( V_210 -> V_215 ) -> V_5 ;
F_108 ( V_213 , V_5 ) ;
F_108 ( V_214 , V_5 ) ;
return ( V_213 == V_214 ) ;
}
static void
F_109 ( struct V_209 * V_210 ,
struct V_115 * V_212 )
{
F_69 ( V_210 -> V_215 != NULL ) ;
if ( V_212 -> V_216 != V_212 -> V_217 ) {
F_110 ( V_210 ) ;
return;
}
V_210 -> V_215 = F_111 ( V_210 -> V_218 ,
V_212 -> V_219 ,
0 ,
V_158 ,
V_220 ,
V_221 ) ;
if ( V_210 -> V_215 == NULL )
F_110 ( V_210 ) ;
}
static void
F_112 ( struct V_209 * V_210 ,
struct V_115 * V_212 )
{
struct V_200 V_201 ;
int V_130 ;
F_69 ( V_210 -> V_215 != NULL ) ;
if ( V_212 -> V_216 != V_212 -> V_217 )
goto V_222;
V_210 -> V_215 = F_111 ( V_210 -> V_218 ,
V_212 -> V_219 ,
0 ,
V_158 ,
V_195 ,
V_223 ) ;
if ( V_210 -> V_215 == NULL )
goto V_222;
F_113 ( & V_201 , V_210 -> V_218 , V_210 -> V_224 ) ;
V_130 = F_98 ( V_210 -> V_215 , & V_201 , V_223 ) ;
if ( V_130 < 0 ) {
F_59 ( V_210 -> V_215 ) ;
V_210 -> V_215 = NULL ;
goto V_222;
}
return;
V_222:
F_114 ( V_210 ) ;
}
static T_2 F_115 ( struct V_1 * V_146 , T_2 V_126 )
{
if ( V_146 -> V_13 == V_14 )
return F_63 ( & V_146 -> V_208 , V_126 ) ;
else
return V_126 ;
}
static void
F_116 ( struct V_115 * V_212 ,
struct V_200 * V_201 )
{
struct V_11 * V_225 = NULL ;
F_100 ( V_201 -> V_203 ) ;
if ( ! F_117 ( V_226 , & V_212 -> V_227 ) )
goto V_89;
V_201 -> V_125 -> V_228 -- ;
if ( F_118 ( & V_212 -> V_229 ) ) {
struct V_202 * V_230 ;
V_230 = F_119 ( & V_212 -> V_229 ,
struct V_202 ,
V_204 ) ;
V_225 = V_230 -> V_231 ;
V_230 -> V_231 = NULL ;
}
V_89:
F_120 ( V_212 , V_201 ) ;
F_102 ( V_201 -> V_203 ) ;
F_59 ( V_225 ) ;
}
static struct V_232 *
F_121 ( struct V_115 * V_212 ,
struct V_11 * V_12 ,
struct V_200 * V_201 )
{
struct V_1 * V_146 = F_5 ( V_12 ) ;
T_2 V_169 , V_126 ;
struct V_232 * V_233 ;
struct V_202 * V_199 ;
if ( V_146 -> V_98 )
return & V_201 -> V_234 -> V_233 ;
V_126 = F_62 ( V_12 , F_107 ( V_212 ) ) ;
V_169 = F_115 ( V_146 , V_126 ) ;
V_199 = V_201 -> V_125 -> V_199 ;
V_233 = & V_199 [ V_169 ] . V_204 ;
if ( F_122 ( V_233 ) ) {
V_199 [ V_169 ] . V_231 = F_123 ( V_12 ) ;
}
F_22 ( V_226 , & V_212 -> V_227 ) ;
V_201 -> V_125 -> V_228 ++ ;
return V_233 ;
}
static void
F_124 ( struct V_115 * V_212 ,
struct V_11 * V_12 ,
struct V_200 * V_201 )
{
struct V_232 * V_233 ;
V_233 = F_121 ( V_212 , V_12 , V_201 ) ;
F_125 ( V_212 , V_233 , V_201 ) ;
}
static T_2 F_126 ( struct V_11 * V_12 , T_2 V_169 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_169 ;
else
return F_63 ( V_12 , V_169 ) ;
}
static struct V_128 *
F_127 ( struct V_11 * V_12 , T_2 V_169 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_165 == 1 )
V_169 = 0 ;
else if ( V_2 -> V_165 == 0 )
return NULL ;
}
return V_2 -> V_170 [ V_169 ] ;
}
static int F_128 ( struct V_114 * V_17 , int V_235 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_124 * V_125 ;
T_2 V_127 ;
struct V_128 * V_129 ;
V_127 = F_126 ( V_12 , V_17 -> V_236 ) ;
V_125 = F_64 ( V_12 , V_127 ) ;
if ( ! V_125 ) {
F_48 ( V_17 ) ;
F_58 ( V_17 ) ;
return - V_90 ;
}
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_103 , V_235 , F_65 ( & V_125 -> V_96 -> V_135 ) ) ;
V_17 -> V_237 = F_50 ;
F_66 ( & V_125 -> V_96 -> V_135 ) ;
V_17 -> V_96 = V_125 -> V_96 ;
V_129 = F_127 ( V_12 , V_17 -> V_236 ) ;
if ( V_129 )
V_17 -> args . V_129 = V_129 ;
return F_129 ( V_125 -> V_96 -> V_137 , V_17 ,
& V_238 , V_235 ,
V_139 ) ;
}
static int
F_130 ( struct V_232 * V_239 , struct V_232 * V_240 ,
struct V_200 * V_201 , int F_91 )
{
struct V_115 * V_212 , * V_241 ;
int V_242 = 0 ;
F_131 (req, tmp, src, wb_list) {
if ( ! F_132 ( V_212 ) )
continue;
F_133 ( & V_212 -> V_243 ) ;
if ( F_134 ( V_201 -> V_203 ) )
F_135 ( V_212 , V_241 , V_229 ) ;
F_120 ( V_212 , V_201 ) ;
F_27 ( V_226 , & V_212 -> V_227 ) ;
F_136 ( V_212 , V_240 ) ;
V_242 ++ ;
if ( ( V_242 == F_91 ) && ! V_201 -> V_244 )
break;
}
return V_242 ;
}
static int
F_137 ( struct V_202 * V_230 ,
struct V_200 * V_201 ,
int F_91 )
{
struct V_232 * V_239 = & V_230 -> V_204 ;
struct V_232 * V_240 = & V_230 -> V_205 ;
int V_242 ;
V_242 = F_130 ( V_239 , V_240 , V_201 , F_91 ) ;
if ( V_242 ) {
V_201 -> V_125 -> V_228 -= V_242 ;
V_201 -> V_125 -> V_245 += V_242 ;
V_230 -> V_246 = V_230 -> V_231 ;
if ( F_122 ( V_239 ) )
V_230 -> V_231 = NULL ;
else
F_123 ( V_230 -> V_246 ) ;
}
return V_242 ;
}
static int F_138 ( struct V_200 * V_201 ,
int F_91 )
{
int V_169 , V_247 = 0 , V_248 ;
for ( V_169 = 0 ; V_169 < V_201 -> V_125 -> V_198 && F_91 != 0 ; V_169 ++ ) {
V_248 = F_137 ( & V_201 -> V_125 -> V_199 [ V_169 ] ,
V_201 , F_91 ) ;
F_91 -= V_248 ;
V_247 += V_248 ;
}
return V_247 ;
}
static void F_139 ( struct V_232 * V_240 ,
struct V_200 * V_201 )
{
struct V_202 * V_249 ;
int V_169 ;
for ( V_169 = 0 , V_249 = V_201 -> V_125 -> V_199 ; V_169 < V_201 -> V_125 -> V_198 ; V_169 ++ , V_249 ++ ) {
if ( F_130 ( & V_249 -> V_204 , V_240 , V_201 , 0 ) ) {
F_69 ( ! F_122 ( & V_249 -> V_204 ) ) ;
F_59 ( V_249 -> V_231 ) ;
V_249 -> V_231 = NULL ;
}
}
V_201 -> V_125 -> V_228 = 0 ;
}
static unsigned int
F_140 ( struct V_200 * V_201 , struct V_232 * V_233 )
{
struct V_250 * V_251 ;
struct V_202 * V_230 ;
struct V_114 * V_17 ;
int V_169 , V_126 ;
unsigned int V_252 = 0 ;
V_251 = V_201 -> V_125 ;
V_230 = V_251 -> V_199 ;
for ( V_169 = 0 ; V_169 < V_251 -> V_198 ; V_169 ++ , V_230 ++ ) {
if ( F_122 ( & V_230 -> V_205 ) )
continue;
V_17 = F_141 () ;
if ( ! V_17 )
break;
V_17 -> V_236 = V_169 ;
V_17 -> V_12 = V_230 -> V_246 ;
V_230 -> V_246 = NULL ;
F_142 ( & V_17 -> V_32 , V_233 ) ;
V_252 ++ ;
}
for ( V_126 = V_169 ; V_126 < V_251 -> V_198 ; V_126 ++ , V_230 ++ ) {
if ( F_122 ( & V_230 -> V_205 ) )
continue;
F_143 ( & V_230 -> V_205 , V_230 -> V_246 , V_201 ) ;
F_59 ( V_230 -> V_246 ) ;
V_230 -> V_246 = NULL ;
}
return V_252 ;
}
static int
F_144 ( struct V_27 * V_27 , struct V_232 * V_253 ,
int V_235 , struct V_200 * V_201 )
{
struct V_114 * V_17 , * V_241 ;
F_145 ( V_233 ) ;
unsigned int V_252 = 0 ;
if ( ! F_122 ( V_253 ) ) {
V_17 = F_141 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_142 ( & V_17 -> V_32 , & V_233 ) ;
V_252 ++ ;
} else
F_143 ( V_253 , NULL , V_201 ) ;
}
V_252 += F_140 ( V_201 , & V_233 ) ;
if ( V_252 == 0 ) {
V_201 -> V_33 -> V_254 ( F_23 ( V_27 ) ) ;
goto V_89;
}
F_146 ( V_252 , & V_201 -> V_234 -> V_255 ) ;
F_131 (data, tmp, &list, pages) {
F_147 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_148 ( V_17 , V_253 , NULL , V_201 ) ;
F_129 ( F_149 ( V_27 ) , V_17 ,
V_17 -> V_109 , V_235 , 0 ) ;
} else {
struct V_202 * V_199 ;
V_199 = V_201 -> V_125 -> V_199 ;
F_148 ( V_17 , & V_199 [ V_17 -> V_236 ] . V_205 , V_17 -> V_12 , V_201 ) ;
F_128 ( V_17 , V_235 ) ;
}
}
V_89:
V_201 -> V_125 -> V_245 = 0 ;
return V_140 ;
}
static void
F_150 ( struct V_43 * V_152 )
{
F_151 ( F_75 ( V_152 , struct V_153 , V_161 ) ) ;
}
static struct V_144 *
F_152 ( struct V_27 * V_27 , T_4 V_151 )
{
struct V_196 * V_171 ;
V_171 = F_92 ( sizeof( * V_171 ) , V_151 ) ;
return & V_171 -> V_208 ;
}
static void
F_153 ( struct V_144 * V_145 )
{
F_78 ( F_97 ( V_145 ) ) ;
}
static struct V_250 *
F_154 ( struct V_27 * V_27 )
{
struct V_144 * V_76 = F_23 ( V_27 ) -> V_76 ;
if ( V_76 == NULL )
return NULL ;
else
return & F_97 ( V_76 ) -> V_197 ;
}
static int T_7 F_155 ( void )
{
F_94 ( V_256 L_28 ,
V_25 ) ;
return F_156 ( & V_257 ) ;
}
static void T_8 F_157 ( void )
{
F_94 ( V_256 L_29 ,
V_25 ) ;
F_158 ( & V_257 ) ;
}
