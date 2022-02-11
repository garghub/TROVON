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
static void F_14 ( struct V_27 * V_27 , struct V_35 * V_36 )
{
if ( ! F_15 ( V_37 , & V_36 -> V_38 ) )
return;
F_16 ( V_39 , & F_17 ( V_27 ) -> V_24 ) ;
F_18 ( V_27 ) ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_11 * V_12 )
{
struct V_35 * V_36 = V_12 -> V_44 ;
struct V_27 * V_27 = V_36 -> V_45 ;
struct V_46 * V_47 = F_20 ( V_27 ) ;
struct V_48 * V_49 = F_21 ( V_12 ) ;
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
F_22 ( V_41 -> V_27 ) ;
case - V_58 :
if ( V_41 == NULL )
break;
F_23 ( V_47 , V_41 ) ;
goto V_59;
case - V_60 :
if ( V_41 != NULL )
F_23 ( V_47 , V_41 ) ;
F_24 ( V_50 ) ;
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
F_25 ( V_43 -> V_53 , V_22 -> V_31 ) ;
break;
case - V_69 :
case - V_70 :
case - V_71 :
F_26 ( V_22 , V_72 ) ;
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
F_27 ( F_17 ( V_27 ) ) ;
F_28 ( & V_52 -> V_80 ) ;
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
F_29 ( V_49 ) ;
F_30 ( V_37 , & V_36 -> V_38 ) ;
F_28 ( & V_52 -> V_80 ) ;
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
F_31 ( & V_50 -> V_92 , V_22 , NULL ) ;
if ( F_32 ( V_93 , & V_50 -> V_94 ) == 0 )
F_33 ( & V_50 -> V_92 , V_22 ) ;
goto V_90;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_95 ;
V_95 = F_19 ( V_22 , V_17 -> args . V_96 -> V_41 ,
V_17 -> V_97 , V_19 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_12 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_91 :
F_35 ( V_22 ) ;
return - V_91 ;
}
return 0 ;
}
static void
F_36 ( struct V_16 * V_98 )
{
struct V_18 * V_19 = V_98 -> V_20 ;
if ( F_5 ( V_19 -> V_12 ) -> V_99 ||
V_98 -> V_100 . V_101 -> V_102 == V_103 )
return;
F_37 ( V_98 ) ;
F_9 ( L_8 , V_25 , V_19 -> V_27 -> V_104 ,
( unsigned long ) F_17 ( V_19 -> V_27 ) -> V_105 -> V_106 ) ;
}
bool
F_38 ( struct V_48 * V_107 )
{
return F_39 ( V_107 ) ||
F_40 ( V_107 ) ;
}
static bool
F_41 ( struct V_11 * V_12 )
{
struct V_48 * V_107 = F_21 ( V_12 ) ;
return F_38 ( V_107 ) ;
}
static void F_42 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_108 = V_17 ;
if ( F_41 ( V_108 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_108 ) ;
F_43 ( V_22 , 0 ) ;
return;
}
V_108 -> V_109 = F_34 ;
if ( F_44 ( V_108 -> V_97 -> V_53 ,
& V_108 -> args . V_110 , & V_108 -> V_100 . V_111 ,
V_22 ) )
return;
F_45 ( V_22 ) ;
}
static void F_46 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_108 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_32 ( V_23 , & V_108 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_108 -> V_20 -> V_112 -> V_113 ( V_22 , V_17 ) ;
}
static void F_47 ( struct V_21 * V_22 , void * V_17 )
{
struct V_34 * V_108 = V_17 ;
F_48 ( V_22 , F_20 ( V_108 -> V_20 -> V_27 ) -> V_114 -> V_115 ) ;
}
static void F_49 ( void * V_17 )
{
struct V_34 * V_108 = V_17 ;
struct V_35 * V_36 = V_108 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_36 -> V_45 , V_36 ) ;
F_50 ( V_108 -> V_97 ) ;
V_108 -> V_20 -> V_112 -> V_116 ( V_17 ) ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_95 ;
V_95 = F_19 ( V_22 , V_17 -> args . V_96 -> V_41 ,
V_17 -> V_97 , V_19 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_7 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_91 :
F_35 ( V_22 ) ;
return - V_91 ;
}
F_36 ( V_17 ) ;
return 0 ;
}
static void F_52 ( struct V_117 * V_17 )
{
struct V_118 * V_119 = F_53 ( V_17 -> V_32 . V_120 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_101 . V_121 , & V_119 -> V_122 ,
sizeof( V_17 -> V_101 . V_121 ) ) ;
V_17 -> V_101 . V_121 . V_17 [ 0 ] ++ ;
}
static int F_54 ( struct V_21 * V_22 ,
struct V_117 * V_17 )
{
int V_95 ;
V_95 = F_19 ( V_22 , NULL , V_17 -> V_97 ,
V_17 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_52 ( V_17 ) ;
return - V_91 ;
case - V_91 :
F_35 ( V_22 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_55 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_41 ( V_98 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_98 ) ;
F_43 ( V_22 , 0 ) ;
return;
}
if ( F_44 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_110 , & V_98 -> V_100 . V_111 ,
V_22 ) )
return;
F_45 ( V_22 ) ;
}
static void F_56 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_32 ( V_23 , & V_98 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 )
return;
V_98 -> V_20 -> V_112 -> V_113 ( V_22 , V_17 ) ;
}
static void F_57 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
F_48 ( V_22 , F_20 ( V_98 -> V_20 -> V_27 ) -> V_114 -> V_115 ) ;
}
static void F_58 ( void * V_17 )
{
struct V_16 * V_98 = V_17 ;
struct V_35 * V_36 = V_98 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_36 -> V_45 , V_36 ) ;
F_50 ( V_98 -> V_97 ) ;
V_98 -> V_20 -> V_112 -> V_116 ( V_17 ) ;
}
static void F_59 ( struct V_21 * V_22 , void * V_17 )
{
struct V_117 * V_98 = V_17 ;
if ( F_44 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_110 , & V_98 -> V_100 . V_111 ,
V_22 ) )
return;
F_45 ( V_22 ) ;
}
static void F_60 ( struct V_21 * V_22 , void * V_17 )
{
struct V_117 * V_98 = V_17 ;
V_98 -> V_112 -> V_113 ( V_22 , V_17 ) ;
}
static void F_61 ( struct V_21 * V_22 , void * V_17 )
{
struct V_117 * V_123 = V_17 ;
F_48 ( V_22 , F_20 ( V_123 -> V_27 ) -> V_114 -> V_115 ) ;
}
static void F_62 ( void * V_124 )
{
struct V_117 * V_17 = V_124 ;
V_17 -> V_33 -> V_125 ( V_17 ) ;
F_63 ( V_17 -> V_12 ) ;
F_50 ( V_17 -> V_97 ) ;
F_64 ( V_17 ) ;
}
static enum V_126
F_65 ( struct V_34 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_127 * V_128 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_129 , V_130 ;
struct V_131 * V_132 ;
int V_133 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_104 ,
V_17 -> args . V_134 , ( V_135 ) V_17 -> args . V_30 , V_3 ) ;
V_129 = F_66 ( V_12 , V_3 ) ;
V_130 = F_67 ( V_12 , V_129 ) ;
V_128 = F_68 ( V_12 , V_130 ) ;
if ( ! V_128 )
return V_136 ;
F_9 ( L_12 , V_25 ,
V_128 -> V_137 , F_69 ( & V_128 -> V_97 -> V_138 ) ) ;
F_70 ( & V_128 -> V_97 -> V_138 ) ;
V_17 -> V_97 = V_128 -> V_97 ;
V_132 = F_71 ( V_12 , V_129 ) ;
if ( V_132 )
V_17 -> args . V_132 = V_132 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_139 = V_3 ;
V_133 = F_72 ( V_128 -> V_97 -> V_140 , V_17 ,
& V_141 , V_142 ) ;
F_73 ( V_133 != 0 ) ;
return V_143 ;
}
static enum V_126
F_74 ( struct V_16 * V_17 , int V_144 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_127 * V_128 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_129 , V_130 ;
struct V_131 * V_132 ;
int V_133 ;
V_129 = F_66 ( V_12 , V_3 ) ;
V_130 = F_67 ( V_12 , V_129 ) ;
V_128 = F_68 ( V_12 , V_130 ) ;
if ( ! V_128 )
return V_136 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_104 , V_144 , ( V_135 ) V_17 -> args . V_30 ,
V_3 , V_128 -> V_137 , F_69 ( & V_128 -> V_97 -> V_138 ) ) ;
V_17 -> V_145 = F_51 ;
F_70 ( & V_128 -> V_97 -> V_138 ) ;
V_17 -> V_97 = V_128 -> V_97 ;
V_132 = F_71 ( V_12 , V_129 ) ;
if ( V_132 )
V_17 -> args . V_132 = V_132 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_133 = F_75 ( V_128 -> V_97 -> V_140 , V_17 ,
& V_146 , V_144 ,
V_142 ) ;
F_73 ( V_133 != 0 ) ;
return V_143 ;
}
static int
F_76 ( struct V_35 * V_36 ,
struct V_1 * V_147 ,
struct V_148 * V_149 ,
struct V_150 * V_151 ,
T_4 V_152 )
{
struct V_48 * V_153 ;
struct V_154 * V_6 ;
int V_133 = - V_155 ;
struct V_46 * V_156 = F_20 ( V_36 -> V_45 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_149 -> V_157 . V_3 != 0 ||
V_149 -> V_157 . V_158 != V_159 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_90;
}
if ( V_147 -> V_10 > V_149 -> V_157 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_147 -> V_10 ) ;
goto V_90;
}
if ( ! V_147 -> V_5 || V_147 -> V_5 % V_160 ) {
F_9 ( L_17 ,
V_25 , V_147 -> V_5 ) ;
goto V_90;
}
V_153 = F_77 ( F_20 ( V_36 -> V_45 ) -> V_161 ,
F_20 ( V_36 -> V_45 ) -> V_42 , V_151 ) ;
if ( V_153 == NULL ) {
V_6 = F_78 ( V_36 -> V_45 , V_151 , V_152 ) ;
if ( V_6 == NULL )
goto V_90;
} else
V_6 = F_79 ( V_153 , struct V_154 , V_162 ) ;
if ( F_38 ( & V_6 -> V_162 ) )
goto V_163;
V_147 -> V_6 = V_6 ;
if ( V_147 -> V_164 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_147 -> V_164 ) ;
goto V_163;
}
if ( ( V_147 -> V_13 == V_14 &&
V_147 -> V_165 > 1 && V_147 -> V_165 != V_6 -> V_166 ) ||
( V_147 -> V_13 == V_15 &&
V_147 -> V_165 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_147 -> V_165 ) ;
goto V_163;
}
if ( V_147 -> V_5 % V_156 -> V_167 || V_147 -> V_5 % V_156 -> V_168 ) {
F_9 ( L_20
L_21 , V_25 , V_147 -> V_5 , V_156 -> V_167 ,
V_156 -> V_168 ) ;
}
V_133 = 0 ;
V_90:
F_9 ( L_22 , V_25 , V_133 ) ;
return V_133 ;
V_163:
F_80 ( V_6 ) ;
goto V_90;
}
static void F_81 ( struct V_1 * V_147 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_147 -> V_165 ; V_169 ++ ) {
if ( ! V_147 -> V_170 [ V_169 ] )
break;
F_82 ( V_147 -> V_170 [ V_169 ] ) ;
}
F_82 ( V_147 -> V_170 ) ;
V_147 -> V_170 = NULL ;
}
static void
F_83 ( struct V_1 * V_147 )
{
F_81 ( V_147 ) ;
F_82 ( V_147 ) ;
}
static int
F_84 ( struct V_35 * V_171 ,
struct V_1 * V_147 ,
struct V_148 * V_149 ,
struct V_150 * V_151 ,
T_4 V_152 )
{
struct V_172 V_173 ;
struct V_174 V_175 ;
struct V_176 * V_177 ;
T_5 * V_178 ;
T_6 V_179 ;
int V_169 ;
F_9 ( L_23 , V_25 ) ;
V_177 = F_85 ( V_152 ) ;
if ( ! V_177 )
return - V_180 ;
F_86 ( & V_173 , & V_175 , V_149 -> V_181 -> V_32 , V_149 -> V_181 -> V_182 ) ;
F_87 ( & V_173 , F_88 ( V_177 ) , V_160 ) ;
V_178 = F_89 ( & V_173 , V_183 + 20 ) ;
if ( F_90 ( ! V_178 ) )
goto V_184;
memcpy ( V_151 , V_178 , sizeof( * V_151 ) ) ;
V_178 += F_91 ( V_183 ) ;
F_92 ( V_151 ) ;
V_179 = F_93 ( V_178 ++ ) ;
if ( V_179 & V_185 )
V_147 -> V_99 = 1 ;
if ( V_179 & V_186 )
V_147 -> V_13 = V_15 ;
else
V_147 -> V_13 = V_14 ;
V_147 -> V_5 = V_179 & ~ V_187 ;
V_147 -> V_164 = F_93 ( V_178 ++ ) ;
V_178 = F_94 ( V_178 , & V_147 -> V_10 ) ;
V_147 -> V_165 = F_93 ( V_178 ++ ) ;
F_9 ( L_24 ,
V_25 , V_179 , V_147 -> V_165 , V_147 -> V_164 ,
V_147 -> V_10 ) ;
if ( V_147 -> V_165 >
F_95 ( V_188 , V_189 ) )
goto V_184;
if ( V_147 -> V_165 > 0 ) {
V_147 -> V_170 = F_96 ( V_147 -> V_165 , sizeof( V_147 -> V_170 [ 0 ] ) ,
V_152 ) ;
if ( ! V_147 -> V_170 )
goto V_184;
}
for ( V_169 = 0 ; V_169 < V_147 -> V_165 ; V_169 ++ ) {
V_147 -> V_170 [ V_169 ] = F_97 ( sizeof( struct V_131 ) , V_152 ) ;
if ( ! V_147 -> V_170 [ V_169 ] )
goto V_190;
V_178 = F_89 ( & V_173 , 4 ) ;
if ( F_90 ( ! V_178 ) )
goto V_190;
V_147 -> V_170 [ V_169 ] -> V_191 = F_93 ( V_178 ++ ) ;
if ( sizeof( struct V_131 ) < V_147 -> V_170 [ V_169 ] -> V_191 ) {
F_98 ( V_192 L_25 ,
V_169 , V_147 -> V_170 [ V_169 ] -> V_191 ) ;
goto V_190;
}
V_178 = F_89 ( & V_173 , V_147 -> V_170 [ V_169 ] -> V_191 ) ;
if ( F_90 ( ! V_178 ) )
goto V_190;
memcpy ( V_147 -> V_170 [ V_169 ] -> V_17 , V_178 , V_147 -> V_170 [ V_169 ] -> V_191 ) ;
F_9 ( L_26 , V_25 ,
V_147 -> V_170 [ V_169 ] -> V_191 ) ;
}
F_99 ( V_177 ) ;
return 0 ;
V_190:
F_81 ( V_147 ) ;
V_184:
F_99 ( V_177 ) ;
return - V_86 ;
}
static void
F_100 ( struct V_11 * V_12 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_80 ( V_147 -> V_6 ) ;
if ( V_12 -> V_193 . V_194 == V_195 ) {
struct V_196 * V_171 ;
V_171 = F_101 ( V_12 -> V_44 ) ;
V_171 -> V_197 . V_198 = 0 ;
F_82 ( V_171 -> V_197 . V_199 ) ;
V_171 -> V_197 . V_199 = NULL ;
}
F_83 ( V_147 ) ;
}
static int
F_102 ( struct V_11 * V_12 ,
struct V_200 * V_201 ,
T_4 V_152 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
struct V_202 * V_199 ;
int V_191 ;
if ( V_147 -> V_99 )
return 0 ;
if ( V_201 -> V_128 -> V_198 != 0 ) {
return 0 ;
}
V_191 = ( V_147 -> V_13 == V_14 ) ?
V_147 -> V_6 -> V_166 : V_147 -> V_6 -> V_7 ;
V_199 = F_96 ( V_191 , sizeof( struct V_202 ) ,
V_152 ) ;
if ( ! V_199 )
return - V_180 ;
else {
int V_169 ;
F_103 ( V_201 -> V_203 ) ;
if ( V_201 -> V_128 -> V_198 != 0 )
F_82 ( V_199 ) ;
else {
V_201 -> V_128 -> V_199 = V_199 ;
V_201 -> V_128 -> V_198 = V_191 ;
for ( V_169 = 0 ; V_169 < V_191 ; V_169 ++ ) {
F_104 ( & V_199 [ V_169 ] . V_204 ) ;
F_104 ( & V_199 [ V_169 ] . V_205 ) ;
}
}
F_105 ( V_201 -> V_203 ) ;
return 0 ;
}
}
static struct V_11 *
F_106 ( struct V_35 * V_206 ,
struct V_148 * V_149 ,
T_4 V_152 )
{
struct V_1 * V_147 ;
int V_207 ;
struct V_150 V_151 ;
F_9 ( L_14 , V_25 ) ;
V_147 = F_107 ( sizeof( * V_147 ) , V_152 ) ;
if ( ! V_147 )
return NULL ;
V_207 = F_84 ( V_206 , V_147 , V_149 , & V_151 , V_152 ) ;
if ( V_207 != 0 || F_76 ( V_206 , V_147 , V_149 , & V_151 , V_152 ) ) {
F_83 ( V_147 ) ;
return NULL ;
}
return & V_147 -> V_208 ;
}
static bool
F_108 ( struct V_209 * V_210 , struct V_118 * V_211 ,
struct V_118 * V_212 )
{
T_3 V_213 , V_214 ;
T_2 V_5 ;
if ( ! F_109 ( V_210 , V_211 , V_212 ) ||
! F_110 ( V_210 , V_211 , V_212 ) )
return false ;
V_213 = ( T_3 ) F_111 ( V_211 ) ;
V_214 = ( T_3 ) F_111 ( V_212 ) ;
V_5 = F_5 ( V_210 -> V_215 ) -> V_5 ;
F_112 ( V_213 , V_5 ) ;
F_112 ( V_214 , V_5 ) ;
return ( V_213 == V_214 ) ;
}
static void
F_113 ( struct V_209 * V_210 ,
struct V_118 * V_212 )
{
F_73 ( V_210 -> V_215 != NULL ) ;
if ( V_212 -> V_216 != V_212 -> V_217 ) {
F_114 ( V_210 ) ;
return;
}
V_210 -> V_215 = F_115 ( V_210 -> V_218 ,
V_212 -> V_219 ,
0 ,
V_159 ,
V_220 ,
V_221 ) ;
if ( V_210 -> V_215 == NULL )
F_114 ( V_210 ) ;
}
static void
F_116 ( struct V_209 * V_210 ,
struct V_118 * V_212 )
{
struct V_200 V_201 ;
int V_133 ;
F_73 ( V_210 -> V_215 != NULL ) ;
if ( V_212 -> V_216 != V_212 -> V_217 )
goto V_222;
V_210 -> V_215 = F_115 ( V_210 -> V_218 ,
V_212 -> V_219 ,
0 ,
V_159 ,
V_195 ,
V_223 ) ;
if ( V_210 -> V_215 == NULL )
goto V_222;
F_117 ( & V_201 , V_210 -> V_218 , V_210 -> V_224 ) ;
V_133 = F_102 ( V_210 -> V_215 , & V_201 , V_223 ) ;
if ( V_133 < 0 ) {
F_63 ( V_210 -> V_215 ) ;
V_210 -> V_215 = NULL ;
goto V_222;
}
return;
V_222:
F_118 ( V_210 ) ;
}
static T_2 F_119 ( struct V_1 * V_147 , T_2 V_129 )
{
if ( V_147 -> V_13 == V_14 )
return F_67 ( & V_147 -> V_208 , V_129 ) ;
else
return V_129 ;
}
static void
F_120 ( struct V_118 * V_212 ,
struct V_200 * V_201 )
{
struct V_11 * V_225 = NULL ;
F_103 ( V_201 -> V_203 ) ;
if ( ! F_15 ( V_226 , & V_212 -> V_227 ) )
goto V_90;
V_201 -> V_128 -> V_228 -- ;
if ( F_121 ( & V_212 -> V_229 ) ) {
struct V_202 * V_230 ;
V_230 = F_122 ( & V_212 -> V_229 ,
struct V_202 ,
V_204 ) ;
V_225 = V_230 -> V_231 ;
V_230 -> V_231 = NULL ;
}
V_90:
F_123 ( V_212 , V_201 ) ;
F_105 ( V_201 -> V_203 ) ;
F_63 ( V_225 ) ;
}
static struct V_232 *
F_124 ( struct V_118 * V_212 ,
struct V_11 * V_12 ,
struct V_200 * V_201 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
T_2 V_169 , V_129 ;
struct V_232 * V_233 ;
struct V_202 * V_199 ;
if ( V_147 -> V_99 )
return & V_201 -> V_234 -> V_233 ;
V_129 = F_66 ( V_12 , F_111 ( V_212 ) ) ;
V_169 = F_119 ( V_147 , V_129 ) ;
V_199 = V_201 -> V_128 -> V_199 ;
V_233 = & V_199 [ V_169 ] . V_204 ;
if ( F_125 ( V_233 ) ) {
V_199 [ V_169 ] . V_231 = F_126 ( V_12 ) ;
}
F_30 ( V_226 , & V_212 -> V_227 ) ;
V_201 -> V_128 -> V_228 ++ ;
return V_233 ;
}
static void
F_127 ( struct V_118 * V_212 ,
struct V_11 * V_12 ,
struct V_200 * V_201 )
{
struct V_232 * V_233 ;
V_233 = F_124 ( V_212 , V_12 , V_201 ) ;
F_128 ( V_212 , V_233 , V_201 ) ;
}
static T_2 F_129 ( struct V_11 * V_12 , T_2 V_169 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_169 ;
else
return F_67 ( V_12 , V_169 ) ;
}
static struct V_131 *
F_130 ( struct V_11 * V_12 , T_2 V_169 )
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
static int F_131 ( struct V_117 * V_17 , int V_235 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_127 * V_128 ;
T_2 V_130 ;
struct V_131 * V_132 ;
V_130 = F_129 ( V_12 , V_17 -> V_236 ) ;
V_128 = F_68 ( V_12 , V_130 ) ;
if ( ! V_128 ) {
F_52 ( V_17 ) ;
F_62 ( V_17 ) ;
return - V_91 ;
}
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_104 , V_235 , F_69 ( & V_128 -> V_97 -> V_138 ) ) ;
V_17 -> V_237 = F_54 ;
F_70 ( & V_128 -> V_97 -> V_138 ) ;
V_17 -> V_97 = V_128 -> V_97 ;
V_132 = F_130 ( V_12 , V_17 -> V_236 ) ;
if ( V_132 )
V_17 -> args . V_132 = V_132 ;
return F_132 ( V_128 -> V_97 -> V_140 , V_17 ,
& V_238 , V_235 ,
V_142 ) ;
}
static int
F_133 ( struct V_232 * V_239 , struct V_232 * V_240 ,
struct V_200 * V_201 , int F_95 )
{
struct V_118 * V_212 , * V_241 ;
int V_242 = 0 ;
F_134 (req, tmp, src, wb_list) {
if ( ! F_135 ( V_212 ) )
continue;
F_136 ( & V_212 -> V_243 ) ;
if ( F_137 ( V_201 -> V_203 ) )
F_138 ( V_212 , V_241 , V_229 ) ;
F_123 ( V_212 , V_201 ) ;
F_16 ( V_226 , & V_212 -> V_227 ) ;
F_139 ( V_212 , V_240 ) ;
V_242 ++ ;
if ( ( V_242 == F_95 ) && ! V_201 -> V_244 )
break;
}
return V_242 ;
}
static int
F_140 ( struct V_202 * V_230 ,
struct V_200 * V_201 ,
int F_95 )
{
struct V_232 * V_239 = & V_230 -> V_204 ;
struct V_232 * V_240 = & V_230 -> V_205 ;
int V_242 ;
V_242 = F_133 ( V_239 , V_240 , V_201 , F_95 ) ;
if ( V_242 ) {
V_201 -> V_128 -> V_228 -= V_242 ;
V_201 -> V_128 -> V_245 += V_242 ;
V_230 -> V_246 = V_230 -> V_231 ;
if ( F_125 ( V_239 ) )
V_230 -> V_231 = NULL ;
else
F_126 ( V_230 -> V_246 ) ;
}
return V_242 ;
}
static int F_141 ( struct V_200 * V_201 ,
int F_95 )
{
int V_169 , V_247 = 0 , V_248 ;
for ( V_169 = 0 ; V_169 < V_201 -> V_128 -> V_198 && F_95 != 0 ; V_169 ++ ) {
V_248 = F_140 ( & V_201 -> V_128 -> V_199 [ V_169 ] ,
V_201 , F_95 ) ;
F_95 -= V_248 ;
V_247 += V_248 ;
}
return V_247 ;
}
static void F_142 ( struct V_232 * V_240 ,
struct V_200 * V_201 )
{
struct V_202 * V_249 ;
int V_169 ;
for ( V_169 = 0 , V_249 = V_201 -> V_128 -> V_199 ; V_169 < V_201 -> V_128 -> V_198 ; V_169 ++ , V_249 ++ ) {
if ( F_133 ( & V_249 -> V_204 , V_240 , V_201 , 0 ) ) {
F_73 ( ! F_125 ( & V_249 -> V_204 ) ) ;
F_63 ( V_249 -> V_231 ) ;
V_249 -> V_231 = NULL ;
}
}
V_201 -> V_128 -> V_228 = 0 ;
}
static unsigned int
F_143 ( struct V_200 * V_201 , struct V_232 * V_233 )
{
struct V_250 * V_251 ;
struct V_202 * V_230 ;
struct V_117 * V_17 ;
int V_169 , V_129 ;
unsigned int V_252 = 0 ;
V_251 = V_201 -> V_128 ;
V_230 = V_251 -> V_199 ;
for ( V_169 = 0 ; V_169 < V_251 -> V_198 ; V_169 ++ , V_230 ++ ) {
if ( F_125 ( & V_230 -> V_205 ) )
continue;
V_17 = F_144 () ;
if ( ! V_17 )
break;
V_17 -> V_236 = V_169 ;
V_17 -> V_12 = V_230 -> V_246 ;
V_230 -> V_246 = NULL ;
F_145 ( & V_17 -> V_32 , V_233 ) ;
V_252 ++ ;
}
for ( V_129 = V_169 ; V_129 < V_251 -> V_198 ; V_129 ++ , V_230 ++ ) {
if ( F_125 ( & V_230 -> V_205 ) )
continue;
F_146 ( & V_230 -> V_205 , V_230 -> V_246 , V_201 ) ;
F_63 ( V_230 -> V_246 ) ;
V_230 -> V_246 = NULL ;
}
return V_252 ;
}
static int
F_147 ( struct V_27 * V_27 , struct V_232 * V_253 ,
int V_235 , struct V_200 * V_201 )
{
struct V_117 * V_17 , * V_241 ;
F_148 ( V_233 ) ;
unsigned int V_252 = 0 ;
if ( ! F_125 ( V_253 ) ) {
V_17 = F_144 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_145 ( & V_17 -> V_32 , & V_233 ) ;
V_252 ++ ;
} else
F_146 ( V_253 , NULL , V_201 ) ;
}
V_252 += F_143 ( V_201 , & V_233 ) ;
if ( V_252 == 0 ) {
V_201 -> V_33 -> V_254 ( F_17 ( V_27 ) ) ;
goto V_90;
}
F_149 ( V_252 , & V_201 -> V_234 -> V_255 ) ;
F_134 (data, tmp, &list, pages) {
F_150 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_151 ( V_17 , V_253 , NULL , V_201 ) ;
F_132 ( F_152 ( V_27 ) , V_17 ,
V_17 -> V_112 , V_235 , 0 ) ;
} else {
struct V_202 * V_199 ;
V_199 = V_201 -> V_128 -> V_199 ;
F_151 ( V_17 , & V_199 [ V_17 -> V_236 ] . V_205 , V_17 -> V_12 , V_201 ) ;
F_131 ( V_17 , V_235 ) ;
}
}
V_90:
V_201 -> V_128 -> V_245 = 0 ;
return V_143 ;
}
static void
F_153 ( struct V_48 * V_153 )
{
F_154 ( F_79 ( V_153 , struct V_154 , V_162 ) ) ;
}
static struct V_35 *
F_155 ( struct V_27 * V_27 , T_4 V_152 )
{
struct V_196 * V_171 ;
V_171 = F_107 ( sizeof( * V_171 ) , V_152 ) ;
return & V_171 -> V_208 ;
}
static void
F_156 ( struct V_35 * V_36 )
{
F_82 ( F_101 ( V_36 ) ) ;
}
static struct V_250 *
F_157 ( struct V_27 * V_27 )
{
struct V_35 * V_105 = F_17 ( V_27 ) -> V_105 ;
if ( V_105 == NULL )
return NULL ;
else
return & F_101 ( V_105 ) -> V_197 ;
}
static int T_7 F_158 ( void )
{
F_98 ( V_256 L_28 ,
V_25 ) ;
return F_159 ( & V_257 ) ;
}
static void T_8 F_160 ( void )
{
F_98 ( V_256 L_29 ,
V_25 ) ;
F_161 ( & V_257 ) ;
}
