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
if ( ! F_26 ( V_44 ) )
F_27 ( V_27 ) ;
F_28 ( V_44 ) ;
F_25 ( & V_47 -> V_78 ) ;
F_29 ( V_38 ) ;
default:
V_79:
F_9 ( L_7 , V_25 ,
V_22 -> V_31 ) ;
return - V_87 ;
}
V_88:
V_22 -> V_31 = 0 ;
return - V_89 ;
V_54:
F_30 ( & V_45 -> V_90 , V_22 , NULL ) ;
if ( F_31 ( V_91 , & V_45 -> V_92 ) == 0 )
F_32 ( & V_45 -> V_90 , V_22 ) ;
goto V_88;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_93 ;
V_93 = F_14 ( V_22 , V_17 -> args . V_94 -> V_36 ,
V_17 -> V_95 , V_19 -> V_12 ) ;
switch ( V_93 ) {
case - V_87 :
F_12 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_89 :
F_34 ( V_22 ) ;
return - V_89 ;
}
return 0 ;
}
static void
F_35 ( struct V_16 * V_96 )
{
struct V_18 * V_19 = V_96 -> V_20 ;
if ( F_5 ( V_19 -> V_12 ) -> V_97 ||
V_96 -> V_98 . V_99 -> V_100 == V_101 )
return;
F_36 ( V_96 ) ;
F_9 ( L_8 , V_25 , V_19 -> V_27 -> V_102 ,
( unsigned long ) F_23 ( V_19 -> V_27 ) -> V_76 -> V_103 ) ;
}
static void F_37 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_104 = V_17 ;
if ( F_38 ( V_104 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_104 ) ;
F_39 ( V_22 , 0 ) ;
return;
}
V_104 -> V_105 = F_33 ;
if ( F_40 ( V_104 -> V_95 -> V_48 ,
& V_104 -> args . V_106 , & V_104 -> V_98 . V_107 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_42 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_104 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_104 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_104 -> V_20 -> V_108 -> V_109 ( V_22 , V_17 ) ;
}
static void F_43 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_104 = V_17 ;
F_44 ( V_22 , F_15 ( V_104 -> V_20 -> V_27 ) -> V_110 -> V_111 ) ;
}
static void F_45 ( void * V_17 )
{
struct V_34 * V_104 = V_17 ;
F_46 ( V_104 -> V_95 ) ;
V_104 -> V_20 -> V_108 -> V_112 ( V_17 ) ;
}
static int F_47 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_93 ;
V_93 = F_14 ( V_22 , V_17 -> args . V_94 -> V_36 ,
V_17 -> V_95 , V_19 -> V_12 ) ;
switch ( V_93 ) {
case - V_87 :
F_7 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_89 :
F_34 ( V_22 ) ;
return - V_89 ;
}
F_35 ( V_17 ) ;
return 0 ;
}
static void F_48 ( struct V_113 * V_17 )
{
struct V_114 * V_115 = F_49 ( V_17 -> V_32 . V_116 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( V_17 -> V_99 . V_117 , V_115 -> V_118 . V_117 ,
sizeof( V_115 -> V_118 . V_117 ) ) ;
V_17 -> V_99 . V_117 [ 0 ] ++ ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_113 * V_17 )
{
int V_93 ;
V_93 = F_14 ( V_22 , NULL , V_17 -> V_95 ,
V_17 -> V_12 ) ;
switch ( V_93 ) {
case - V_87 :
F_48 ( V_17 ) ;
return - V_89 ;
case - V_89 :
F_34 ( V_22 ) ;
return - V_89 ;
}
return 0 ;
}
static void F_51 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_96 = V_17 ;
if ( F_38 ( V_96 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_96 ) ;
F_39 ( V_22 , 0 ) ;
return;
}
if ( F_40 ( V_96 -> V_95 -> V_48 ,
& V_96 -> args . V_106 , & V_96 -> V_98 . V_107 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_52 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_96 = V_17 ;
if ( F_31 ( V_23 , & V_96 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_96 -> V_20 -> V_108 -> V_109 ( V_22 , V_17 ) ;
}
static void F_53 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_96 = V_17 ;
F_44 ( V_22 , F_15 ( V_96 -> V_20 -> V_27 ) -> V_110 -> V_111 ) ;
}
static void F_54 ( void * V_17 )
{
struct V_16 * V_96 = V_17 ;
F_46 ( V_96 -> V_95 ) ;
V_96 -> V_20 -> V_108 -> V_112 ( V_17 ) ;
}
static void F_55 ( struct V_21 * V_22 , void * V_17 )
{
struct V_113 * V_96 = V_17 ;
if ( F_40 ( V_96 -> V_95 -> V_48 ,
& V_96 -> args . V_106 , & V_96 -> V_98 . V_107 ,
V_22 ) )
return;
F_41 ( V_22 ) ;
}
static void F_56 ( struct V_21 * V_22 , void * V_17 )
{
struct V_113 * V_96 = V_17 ;
V_96 -> V_108 -> V_109 ( V_22 , V_17 ) ;
}
static void F_57 ( struct V_21 * V_22 , void * V_17 )
{
struct V_113 * V_119 = V_17 ;
F_44 ( V_22 , F_15 ( V_119 -> V_27 ) -> V_110 -> V_111 ) ;
}
static void F_58 ( void * V_120 )
{
struct V_113 * V_17 = V_120 ;
V_17 -> V_33 -> V_121 ( V_17 ) ;
F_59 ( V_17 -> V_12 ) ;
F_46 ( V_17 -> V_95 ) ;
F_60 ( V_17 ) ;
}
static enum V_122
F_61 ( struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_123 * V_124 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_125 , V_126 ;
struct V_127 * V_128 ;
int V_129 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_102 ,
V_17 -> args . V_130 , ( V_131 ) V_17 -> args . V_30 , V_3 ) ;
V_125 = F_62 ( V_12 , V_3 ) ;
V_126 = F_63 ( V_12 , V_125 ) ;
V_124 = F_64 ( V_12 , V_126 ) ;
if ( ! V_124 )
return V_132 ;
F_9 ( L_12 , V_25 ,
V_124 -> V_133 , F_65 ( & V_124 -> V_95 -> V_134 ) ) ;
F_66 ( & V_124 -> V_95 -> V_134 ) ;
V_17 -> V_95 = V_124 -> V_95 ;
V_128 = F_67 ( V_12 , V_125 ) ;
if ( V_128 )
V_17 -> args . V_128 = V_128 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_135 = V_3 ;
V_129 = F_68 ( V_124 -> V_95 -> V_136 , V_17 ,
& V_137 , V_138 ) ;
F_69 ( V_129 != 0 ) ;
return V_139 ;
}
static enum V_122
F_70 ( struct V_16 * V_17 , int V_140 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_123 * V_124 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_125 , V_126 ;
struct V_127 * V_128 ;
int V_129 ;
V_125 = F_62 ( V_12 , V_3 ) ;
V_126 = F_63 ( V_12 , V_125 ) ;
V_124 = F_64 ( V_12 , V_126 ) ;
if ( ! V_124 )
return V_132 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_102 , V_140 , ( V_131 ) V_17 -> args . V_30 ,
V_3 , V_124 -> V_133 , F_65 ( & V_124 -> V_95 -> V_134 ) ) ;
V_17 -> V_141 = F_47 ;
F_66 ( & V_124 -> V_95 -> V_134 ) ;
V_17 -> V_95 = V_124 -> V_95 ;
V_128 = F_67 ( V_12 , V_125 ) ;
if ( V_128 )
V_17 -> args . V_128 = V_128 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_129 = F_71 ( V_124 -> V_95 -> V_136 , V_17 ,
& V_142 , V_140 ,
V_138 ) ;
F_69 ( V_129 != 0 ) ;
return V_139 ;
}
static int
F_72 ( struct V_143 * V_144 ,
struct V_1 * V_145 ,
struct V_146 * V_147 ,
struct V_148 * V_149 ,
T_4 V_150 )
{
struct V_43 * V_151 ;
struct V_152 * V_6 ;
int V_129 = - V_153 ;
struct V_41 * V_154 = F_15 ( V_144 -> V_40 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_147 -> V_155 . V_3 != 0 ||
V_147 -> V_155 . V_156 != V_157 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_88;
}
if ( V_145 -> V_10 > V_147 -> V_155 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_145 -> V_10 ) ;
goto V_88;
}
if ( ! V_145 -> V_5 || V_145 -> V_5 % V_158 ) {
F_9 ( L_17 ,
V_25 , V_145 -> V_5 ) ;
goto V_88;
}
V_151 = F_73 ( F_15 ( V_144 -> V_40 ) -> V_159 ,
F_15 ( V_144 -> V_40 ) -> V_37 , V_149 ) ;
if ( V_151 == NULL ) {
V_6 = F_74 ( V_144 -> V_40 , V_149 , V_150 ) ;
if ( V_6 == NULL )
goto V_88;
} else
V_6 = F_75 ( V_151 , struct V_152 , V_160 ) ;
if ( F_31 ( V_161 , & V_6 -> V_160 . V_24 ) )
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
if ( V_145 -> V_5 % V_154 -> V_166 || V_145 -> V_5 % V_154 -> V_167 ) {
F_9 ( L_20
L_21 , V_25 , V_145 -> V_5 , V_154 -> V_166 ,
V_154 -> V_167 ) ;
}
V_129 = 0 ;
V_88:
F_9 ( L_22 , V_25 , V_129 ) ;
return V_129 ;
V_162:
F_76 ( V_6 ) ;
goto V_88;
}
static void F_77 ( struct V_1 * V_145 )
{
int V_168 ;
for ( V_168 = 0 ; V_168 < V_145 -> V_164 ; V_168 ++ ) {
if ( ! V_145 -> V_169 [ V_168 ] )
break;
F_78 ( V_145 -> V_169 [ V_168 ] ) ;
}
F_78 ( V_145 -> V_169 ) ;
V_145 -> V_169 = NULL ;
}
static void
F_79 ( struct V_1 * V_145 )
{
F_77 ( V_145 ) ;
F_78 ( V_145 ) ;
}
static int
F_80 ( struct V_143 * V_170 ,
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
V_176 = F_81 ( V_150 ) ;
if ( ! V_176 )
return - V_179 ;
F_82 ( & V_172 , & V_174 , V_147 -> V_180 -> V_32 , V_147 -> V_180 -> V_181 ) ;
F_83 ( & V_172 , F_84 ( V_176 ) , V_158 ) ;
V_177 = F_85 ( & V_172 , V_182 + 20 ) ;
if ( F_86 ( ! V_177 ) )
goto V_183;
memcpy ( V_149 , V_177 , sizeof( * V_149 ) ) ;
V_177 += F_87 ( V_182 ) ;
F_88 ( V_149 ) ;
V_178 = F_89 ( V_177 ++ ) ;
if ( V_178 & V_184 )
V_145 -> V_97 = 1 ;
if ( V_178 & V_185 )
V_145 -> V_13 = V_15 ;
else
V_145 -> V_13 = V_14 ;
V_145 -> V_5 = V_178 & ~ V_186 ;
V_145 -> V_163 = F_89 ( V_177 ++ ) ;
V_177 = F_90 ( V_177 , & V_145 -> V_10 ) ;
V_145 -> V_164 = F_89 ( V_177 ++ ) ;
F_9 ( L_24 ,
V_25 , V_178 , V_145 -> V_164 , V_145 -> V_163 ,
V_145 -> V_10 ) ;
if ( V_145 -> V_164 >
F_91 ( V_187 , V_188 ) )
goto V_183;
if ( V_145 -> V_164 > 0 ) {
V_145 -> V_169 = F_92 ( V_145 -> V_164 * sizeof( struct V_127 * ) ,
V_150 ) ;
if ( ! V_145 -> V_169 )
goto V_183;
}
for ( V_168 = 0 ; V_168 < V_145 -> V_164 ; V_168 ++ ) {
V_145 -> V_169 [ V_168 ] = F_93 ( sizeof( struct V_127 ) , V_150 ) ;
if ( ! V_145 -> V_169 [ V_168 ] )
goto V_189;
V_177 = F_85 ( & V_172 , 4 ) ;
if ( F_86 ( ! V_177 ) )
goto V_189;
V_145 -> V_169 [ V_168 ] -> V_190 = F_89 ( V_177 ++ ) ;
if ( sizeof( struct V_127 ) < V_145 -> V_169 [ V_168 ] -> V_190 ) {
F_94 ( V_191 L_25 ,
V_168 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
goto V_189;
}
V_177 = F_85 ( & V_172 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
if ( F_86 ( ! V_177 ) )
goto V_189;
memcpy ( V_145 -> V_169 [ V_168 ] -> V_17 , V_177 , V_145 -> V_169 [ V_168 ] -> V_190 ) ;
F_9 ( L_26 , V_25 ,
V_145 -> V_169 [ V_168 ] -> V_190 ) ;
}
F_95 ( V_176 ) ;
return 0 ;
V_189:
F_77 ( V_145 ) ;
V_183:
F_95 ( V_176 ) ;
return - V_84 ;
}
static void
F_96 ( struct V_11 * V_12 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_76 ( V_145 -> V_6 ) ;
if ( V_12 -> V_192 . V_193 == V_194 ) {
struct V_195 * V_170 ;
V_170 = F_97 ( V_12 -> V_39 ) ;
V_170 -> V_196 . V_197 = 0 ;
F_78 ( V_170 -> V_196 . V_198 ) ;
V_170 -> V_196 . V_198 = NULL ;
}
F_79 ( V_145 ) ;
}
static int
F_98 ( struct V_11 * V_12 ,
struct V_199 * V_200 ,
T_4 V_150 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
struct V_201 * V_198 ;
int V_190 ;
if ( V_145 -> V_97 )
return 0 ;
if ( V_200 -> V_124 -> V_197 != 0 ) {
return 0 ;
}
V_190 = ( V_145 -> V_13 == V_14 ) ?
V_145 -> V_6 -> V_165 : V_145 -> V_6 -> V_7 ;
V_198 = F_99 ( V_190 , sizeof( struct V_201 ) ,
V_150 ) ;
if ( ! V_198 )
return - V_179 ;
else {
int V_168 ;
F_100 ( V_200 -> V_202 ) ;
if ( V_200 -> V_124 -> V_197 != 0 )
F_78 ( V_198 ) ;
else {
V_200 -> V_124 -> V_198 = V_198 ;
V_200 -> V_124 -> V_197 = V_190 ;
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
F_103 ( struct V_143 * V_205 ,
struct V_146 * V_147 ,
T_4 V_150 )
{
struct V_1 * V_145 ;
int V_206 ;
struct V_148 V_149 ;
F_9 ( L_14 , V_25 ) ;
V_145 = F_92 ( sizeof( * V_145 ) , V_150 ) ;
if ( ! V_145 )
return NULL ;
V_206 = F_80 ( V_205 , V_145 , V_147 , & V_149 , V_150 ) ;
if ( V_206 != 0 || F_72 ( V_205 , V_145 , V_147 , & V_149 , V_150 ) ) {
F_79 ( V_145 ) ;
return NULL ;
}
return & V_145 -> V_207 ;
}
static bool
F_104 ( struct V_208 * V_209 , struct V_114 * V_210 ,
struct V_114 * V_211 )
{
T_3 V_212 , V_213 ;
T_2 V_5 ;
if ( ! F_105 ( V_209 , V_210 , V_211 ) ||
! F_106 ( V_209 , V_210 , V_211 ) )
return false ;
V_212 = ( T_3 ) F_107 ( V_210 ) ;
V_213 = ( T_3 ) F_107 ( V_211 ) ;
V_5 = F_5 ( V_209 -> V_214 ) -> V_5 ;
F_108 ( V_212 , V_5 ) ;
F_108 ( V_213 , V_5 ) ;
return ( V_212 == V_213 ) ;
}
static void
F_109 ( struct V_208 * V_209 ,
struct V_114 * V_211 )
{
F_69 ( V_209 -> V_214 != NULL ) ;
if ( V_211 -> V_215 != V_211 -> V_216 ) {
F_110 ( V_209 ) ;
return;
}
V_209 -> V_214 = F_111 ( V_209 -> V_217 ,
V_211 -> V_218 ,
0 ,
V_157 ,
V_219 ,
V_220 ) ;
if ( V_209 -> V_214 == NULL )
F_110 ( V_209 ) ;
}
static void
F_112 ( struct V_208 * V_209 ,
struct V_114 * V_211 )
{
struct V_199 V_200 ;
int V_129 ;
F_69 ( V_209 -> V_214 != NULL ) ;
if ( V_211 -> V_215 != V_211 -> V_216 )
goto V_221;
V_209 -> V_214 = F_111 ( V_209 -> V_217 ,
V_211 -> V_218 ,
0 ,
V_157 ,
V_194 ,
V_222 ) ;
if ( V_209 -> V_214 == NULL )
goto V_221;
F_113 ( & V_200 , V_209 -> V_217 , V_209 -> V_223 ) ;
V_129 = F_98 ( V_209 -> V_214 , & V_200 , V_222 ) ;
if ( V_129 < 0 ) {
F_59 ( V_209 -> V_214 ) ;
V_209 -> V_214 = NULL ;
goto V_221;
}
return;
V_221:
F_114 ( V_209 ) ;
}
static T_2 F_115 ( struct V_1 * V_145 , T_2 V_125 )
{
if ( V_145 -> V_13 == V_14 )
return F_63 ( & V_145 -> V_207 , V_125 ) ;
else
return V_125 ;
}
static void
F_116 ( struct V_114 * V_211 ,
struct V_199 * V_200 )
{
struct V_11 * V_224 = NULL ;
F_100 ( V_200 -> V_202 ) ;
if ( ! F_117 ( V_225 , & V_211 -> V_226 ) )
goto V_88;
V_200 -> V_124 -> V_227 -- ;
if ( F_118 ( & V_211 -> V_228 ) ) {
struct V_201 * V_229 ;
V_229 = F_119 ( & V_211 -> V_228 ,
struct V_201 ,
V_203 ) ;
V_224 = V_229 -> V_230 ;
V_229 -> V_230 = NULL ;
}
V_88:
F_120 ( V_211 , V_200 ) ;
F_102 ( V_200 -> V_202 ) ;
F_59 ( V_224 ) ;
}
static struct V_231 *
F_121 ( struct V_114 * V_211 ,
struct V_11 * V_12 ,
struct V_199 * V_200 )
{
struct V_1 * V_145 = F_5 ( V_12 ) ;
T_2 V_168 , V_125 ;
struct V_231 * V_232 ;
struct V_201 * V_198 ;
if ( V_145 -> V_97 )
return & V_200 -> V_233 -> V_232 ;
V_125 = F_62 ( V_12 , F_107 ( V_211 ) ) ;
V_168 = F_115 ( V_145 , V_125 ) ;
V_198 = V_200 -> V_124 -> V_198 ;
V_232 = & V_198 [ V_168 ] . V_203 ;
if ( F_122 ( V_232 ) ) {
V_198 [ V_168 ] . V_230 = F_123 ( V_12 ) ;
}
F_22 ( V_225 , & V_211 -> V_226 ) ;
V_200 -> V_124 -> V_227 ++ ;
return V_232 ;
}
static void
F_124 ( struct V_114 * V_211 ,
struct V_11 * V_12 ,
struct V_199 * V_200 )
{
struct V_231 * V_232 ;
V_232 = F_121 ( V_211 , V_12 , V_200 ) ;
F_125 ( V_211 , V_232 , V_200 ) ;
}
static T_2 F_126 ( struct V_11 * V_12 , T_2 V_168 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_168 ;
else
return F_63 ( V_12 , V_168 ) ;
}
static struct V_127 *
F_127 ( struct V_11 * V_12 , T_2 V_168 )
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
static int F_128 ( struct V_113 * V_17 , int V_234 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_123 * V_124 ;
T_2 V_126 ;
struct V_127 * V_128 ;
V_126 = F_126 ( V_12 , V_17 -> V_235 ) ;
V_124 = F_64 ( V_12 , V_126 ) ;
if ( ! V_124 ) {
F_48 ( V_17 ) ;
F_58 ( V_17 ) ;
return - V_89 ;
}
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_102 , V_234 , F_65 ( & V_124 -> V_95 -> V_134 ) ) ;
V_17 -> V_236 = F_50 ;
F_66 ( & V_124 -> V_95 -> V_134 ) ;
V_17 -> V_95 = V_124 -> V_95 ;
V_128 = F_127 ( V_12 , V_17 -> V_235 ) ;
if ( V_128 )
V_17 -> args . V_128 = V_128 ;
return F_129 ( V_124 -> V_95 -> V_136 , V_17 ,
& V_237 , V_234 ,
V_138 ) ;
}
static int
F_130 ( struct V_231 * V_238 , struct V_231 * V_239 ,
struct V_199 * V_200 , int F_91 )
{
struct V_114 * V_211 , * V_240 ;
int V_241 = 0 ;
F_131 (req, tmp, src, wb_list) {
if ( ! F_132 ( V_211 ) )
continue;
F_133 ( & V_211 -> V_242 ) ;
if ( F_134 ( V_200 -> V_202 ) )
F_135 ( V_211 , V_240 , V_228 ) ;
F_120 ( V_211 , V_200 ) ;
F_136 ( V_225 , & V_211 -> V_226 ) ;
F_137 ( V_211 , V_239 ) ;
V_241 ++ ;
if ( ( V_241 == F_91 ) && ! V_200 -> V_243 )
break;
}
return V_241 ;
}
static int
F_138 ( struct V_201 * V_229 ,
struct V_199 * V_200 ,
int F_91 )
{
struct V_231 * V_238 = & V_229 -> V_203 ;
struct V_231 * V_239 = & V_229 -> V_204 ;
int V_241 ;
V_241 = F_130 ( V_238 , V_239 , V_200 , F_91 ) ;
if ( V_241 ) {
V_200 -> V_124 -> V_227 -= V_241 ;
V_200 -> V_124 -> V_244 += V_241 ;
V_229 -> V_245 = V_229 -> V_230 ;
if ( F_122 ( V_238 ) )
V_229 -> V_230 = NULL ;
else
F_123 ( V_229 -> V_245 ) ;
}
return V_241 ;
}
static int F_139 ( struct V_199 * V_200 ,
int F_91 )
{
int V_168 , V_246 = 0 , V_247 ;
for ( V_168 = 0 ; V_168 < V_200 -> V_124 -> V_197 && F_91 != 0 ; V_168 ++ ) {
V_247 = F_138 ( & V_200 -> V_124 -> V_198 [ V_168 ] ,
V_200 , F_91 ) ;
F_91 -= V_247 ;
V_246 += V_247 ;
}
return V_246 ;
}
static void F_140 ( struct V_231 * V_239 ,
struct V_199 * V_200 )
{
struct V_201 * V_248 ;
int V_168 ;
for ( V_168 = 0 , V_248 = V_200 -> V_124 -> V_198 ; V_168 < V_200 -> V_124 -> V_197 ; V_168 ++ , V_248 ++ ) {
if ( F_130 ( & V_248 -> V_203 , V_239 , V_200 , 0 ) ) {
F_69 ( ! F_122 ( & V_248 -> V_203 ) ) ;
F_59 ( V_248 -> V_230 ) ;
V_248 -> V_230 = NULL ;
}
}
V_200 -> V_124 -> V_227 = 0 ;
}
static unsigned int
F_141 ( struct V_199 * V_200 , struct V_231 * V_232 )
{
struct V_249 * V_250 ;
struct V_201 * V_229 ;
struct V_113 * V_17 ;
int V_168 , V_125 ;
unsigned int V_251 = 0 ;
V_250 = V_200 -> V_124 ;
V_229 = V_250 -> V_198 ;
for ( V_168 = 0 ; V_168 < V_250 -> V_197 ; V_168 ++ , V_229 ++ ) {
if ( F_122 ( & V_229 -> V_204 ) )
continue;
V_17 = F_142 () ;
if ( ! V_17 )
break;
V_17 -> V_235 = V_168 ;
V_17 -> V_12 = V_229 -> V_245 ;
V_229 -> V_245 = NULL ;
F_143 ( & V_17 -> V_32 , V_232 ) ;
V_251 ++ ;
}
for ( V_125 = V_168 ; V_125 < V_250 -> V_197 ; V_125 ++ , V_229 ++ ) {
if ( F_122 ( & V_229 -> V_204 ) )
continue;
F_144 ( & V_229 -> V_204 , V_229 -> V_245 , V_200 ) ;
F_59 ( V_229 -> V_245 ) ;
V_229 -> V_245 = NULL ;
}
return V_251 ;
}
static int
F_145 ( struct V_27 * V_27 , struct V_231 * V_252 ,
int V_234 , struct V_199 * V_200 )
{
struct V_113 * V_17 , * V_240 ;
F_146 ( V_232 ) ;
unsigned int V_251 = 0 ;
if ( ! F_122 ( V_252 ) ) {
V_17 = F_142 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_143 ( & V_17 -> V_32 , & V_232 ) ;
V_251 ++ ;
} else
F_144 ( V_252 , NULL , V_200 ) ;
}
V_251 += F_141 ( V_200 , & V_232 ) ;
if ( V_251 == 0 ) {
V_200 -> V_33 -> V_253 ( F_23 ( V_27 ) ) ;
goto V_88;
}
F_147 ( V_251 , & V_200 -> V_233 -> V_254 ) ;
F_131 (data, tmp, &list, pages) {
F_148 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_149 ( V_17 , V_252 , NULL , V_200 ) ;
F_129 ( F_150 ( V_27 ) , V_17 ,
V_17 -> V_108 , V_234 , 0 ) ;
} else {
struct V_201 * V_198 ;
V_198 = V_200 -> V_124 -> V_198 ;
F_149 ( V_17 , & V_198 [ V_17 -> V_235 ] . V_204 , V_17 -> V_12 , V_200 ) ;
F_128 ( V_17 , V_234 ) ;
}
}
V_88:
V_200 -> V_124 -> V_244 = 0 ;
return V_139 ;
}
static void
F_151 ( struct V_43 * V_151 )
{
F_152 ( F_75 ( V_151 , struct V_152 , V_160 ) ) ;
}
static struct V_143 *
F_153 ( struct V_27 * V_27 , T_4 V_150 )
{
struct V_195 * V_170 ;
V_170 = F_92 ( sizeof( * V_170 ) , V_150 ) ;
return & V_170 -> V_207 ;
}
static void
F_154 ( struct V_143 * V_144 )
{
F_78 ( F_97 ( V_144 ) ) ;
}
static struct V_249 *
F_155 ( struct V_27 * V_27 )
{
struct V_143 * V_76 = F_23 ( V_27 ) -> V_76 ;
if ( V_76 == NULL )
return NULL ;
else
return & F_97 ( V_76 ) -> V_196 ;
}
static int T_7 F_156 ( void )
{
F_94 ( V_255 L_28 ,
V_25 ) ;
return F_157 ( & V_256 ) ;
}
static void T_8 F_158 ( void )
{
F_94 ( V_255 L_29 ,
V_25 ) ;
F_159 ( & V_256 ) ;
}
