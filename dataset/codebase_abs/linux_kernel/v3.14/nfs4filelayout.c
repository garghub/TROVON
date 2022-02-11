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
( unsigned long long ) F_10 ( V_19 -> V_27 ) ,
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
( unsigned long long ) F_10 ( V_19 -> V_27 ) ,
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
F_34 ( V_17 , V_22 -> V_31 ) ;
V_95 = F_17 ( V_22 , V_17 -> args . V_96 -> V_41 ,
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
( unsigned long ) F_26 ( V_19 -> V_27 ) -> V_105 -> V_106 ) ;
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
struct V_48 * V_107 = F_19 ( V_12 ) ;
return F_38 ( V_107 ) ;
}
static void F_42 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
if ( F_43 ( F_31 ( V_109 , & V_108 -> args . V_96 -> V_24 ) ) ) {
F_44 ( V_22 , - V_86 ) ;
return;
}
if ( F_41 ( V_108 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_108 ) ;
F_44 ( V_22 , 0 ) ;
return;
}
V_108 -> V_110 = F_33 ;
if ( F_45 ( V_108 -> V_97 -> V_53 ,
& V_108 -> args . V_111 ,
& V_108 -> V_100 . V_112 ,
V_22 ) )
return;
if ( F_46 ( & V_108 -> args . V_113 , V_108 -> args . V_96 ,
V_108 -> args . V_114 , V_115 ) == - V_86 )
F_44 ( V_22 , - V_86 ) ;
}
static void F_47 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_108 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 ) {
F_48 ( V_22 , & V_108 -> V_100 . V_112 ) ;
return;
}
V_108 -> V_20 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_49 ( struct V_21 * V_22 , void * V_17 )
{
struct V_35 * V_108 = V_17 ;
F_50 ( V_22 , F_18 ( V_108 -> V_20 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_51 ( void * V_17 )
{
struct V_35 * V_108 = V_17 ;
struct V_36 * V_37 = V_108 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_52 ( V_108 -> V_97 ) ;
V_108 -> V_20 -> V_116 -> V_120 ( V_17 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_95 ;
F_54 ( V_17 , V_22 -> V_31 ) ;
V_95 = F_17 ( V_22 , V_17 -> args . V_96 -> V_41 ,
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
static void F_55 ( struct V_121 * V_17 )
{
struct V_122 * V_123 = F_56 ( V_17 -> V_32 . V_124 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_101 . V_125 , & V_123 -> V_126 ,
sizeof( V_17 -> V_101 . V_125 ) ) ;
V_17 -> V_101 . V_125 . V_17 [ 0 ] ++ ;
}
static int F_57 ( struct V_21 * V_22 ,
struct V_121 * V_17 )
{
int V_95 ;
F_58 ( V_17 , V_22 -> V_31 ) ;
V_95 = F_17 ( V_22 , NULL , V_17 -> V_97 ,
V_17 -> V_12 ) ;
switch ( V_95 ) {
case - V_89 :
F_55 ( V_17 ) ;
return - V_91 ;
case - V_91 :
F_35 ( V_22 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_59 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_43 ( F_31 ( V_109 , & V_98 -> args . V_96 -> V_24 ) ) ) {
F_44 ( V_22 , - V_86 ) ;
return;
}
if ( F_41 ( V_98 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_98 ) ;
F_44 ( V_22 , 0 ) ;
return;
}
if ( F_45 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_111 ,
& V_98 -> V_100 . V_112 ,
V_22 ) )
return;
if ( F_46 ( & V_98 -> args . V_113 , V_98 -> args . V_96 ,
V_98 -> args . V_114 , V_127 ) == - V_86 )
F_44 ( V_22 , - V_86 ) ;
}
static void F_60 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
if ( F_31 ( V_23 , & V_98 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 ) {
F_48 ( V_22 , & V_98 -> V_100 . V_112 ) ;
return;
}
V_98 -> V_20 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_61 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_98 = V_17 ;
F_50 ( V_22 , F_18 ( V_98 -> V_20 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_62 ( void * V_17 )
{
struct V_16 * V_98 = V_17 ;
struct V_36 * V_37 = V_98 -> V_20 -> V_12 -> V_44 ;
F_14 ( V_37 -> V_45 , V_37 ) ;
F_52 ( V_98 -> V_97 ) ;
V_98 -> V_20 -> V_116 -> V_120 ( V_17 ) ;
}
static void F_63 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_98 = V_17 ;
F_45 ( V_98 -> V_97 -> V_53 ,
& V_98 -> args . V_111 ,
& V_98 -> V_100 . V_112 ,
V_22 ) ;
}
static void F_64 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_98 = V_17 ;
V_98 -> V_116 -> V_117 ( V_22 , V_17 ) ;
}
static void F_65 ( struct V_21 * V_22 , void * V_17 )
{
struct V_121 * V_128 = V_17 ;
F_50 ( V_22 , F_18 ( V_128 -> V_27 ) -> V_118 -> V_119 ) ;
}
static void F_66 ( void * V_129 )
{
struct V_121 * V_17 = V_129 ;
V_17 -> V_33 -> V_130 ( V_17 ) ;
F_67 ( V_17 -> V_12 ) ;
F_52 ( V_17 -> V_97 ) ;
F_68 ( V_17 ) ;
}
static enum V_131
F_69 ( struct V_35 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_136 , V_137 ;
struct V_138 * V_139 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_104 ,
V_17 -> args . V_140 , ( V_141 ) V_17 -> args . V_30 , V_3 ) ;
V_136 = F_70 ( V_12 , V_3 ) ;
V_137 = F_71 ( V_12 , V_136 ) ;
V_133 = F_72 ( V_12 , V_137 ) ;
if ( ! V_133 )
return V_142 ;
V_135 = F_73 ( V_133 -> V_97 , V_19 -> V_27 ) ;
if ( F_74 ( V_135 ) )
return V_142 ;
F_9 ( L_12 , V_25 ,
V_133 -> V_143 , F_75 ( & V_133 -> V_97 -> V_144 ) ) ;
F_76 ( & V_133 -> V_97 -> V_144 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_139 = F_77 ( V_12 , V_136 ) ;
if ( V_139 )
V_17 -> args . V_139 = V_139 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_145 = V_3 ;
F_78 ( V_135 , V_17 ,
& V_146 , V_147 ) ;
return V_148 ;
}
static enum V_131
F_79 ( struct V_16 * V_17 , int V_149 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_136 , V_137 ;
struct V_138 * V_139 ;
V_136 = F_70 ( V_12 , V_3 ) ;
V_137 = F_71 ( V_12 , V_136 ) ;
V_133 = F_72 ( V_12 , V_137 ) ;
if ( ! V_133 )
return V_142 ;
V_135 = F_73 ( V_133 -> V_97 , V_19 -> V_27 ) ;
if ( F_74 ( V_135 ) )
return V_142 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_104 , V_149 , ( V_141 ) V_17 -> args . V_30 ,
V_3 , V_133 -> V_143 , F_75 ( & V_133 -> V_97 -> V_144 ) ) ;
V_17 -> V_150 = F_53 ;
F_76 ( & V_133 -> V_97 -> V_144 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_139 = F_77 ( V_12 , V_136 ) ;
if ( V_139 )
V_17 -> args . V_139 = V_139 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_80 ( V_135 , V_17 ,
& V_151 , V_149 ,
V_147 ) ;
return V_148 ;
}
static int
F_81 ( struct V_36 * V_37 ,
struct V_1 * V_152 ,
struct V_153 * V_154 ,
struct V_155 * V_156 ,
T_4 V_157 )
{
struct V_48 * V_158 ;
struct V_159 * V_6 ;
int V_160 = - V_161 ;
struct V_46 * V_162 = F_18 ( V_37 -> V_45 ) ;
F_9 ( L_14 , V_25 ) ;
if ( V_154 -> V_163 . V_3 != 0 ||
V_154 -> V_163 . V_164 != V_165 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_90;
}
if ( V_152 -> V_10 > V_154 -> V_163 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_152 -> V_10 ) ;
goto V_90;
}
if ( ! V_152 -> V_5 || V_152 -> V_5 % V_166 ) {
F_9 ( L_17 ,
V_25 , V_152 -> V_5 ) ;
goto V_90;
}
V_158 = F_82 ( F_18 ( V_37 -> V_45 ) -> V_167 ,
F_18 ( V_37 -> V_45 ) -> V_42 , V_156 ) ;
if ( V_158 == NULL ) {
V_6 = F_83 ( V_37 -> V_45 , V_156 ,
V_37 -> V_168 , V_157 ) ;
if ( V_6 == NULL )
goto V_90;
} else
V_6 = F_84 ( V_158 , struct V_159 , V_169 ) ;
if ( F_38 ( & V_6 -> V_169 ) )
goto V_170;
V_152 -> V_6 = V_6 ;
if ( V_152 -> V_171 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_152 -> V_171 ) ;
goto V_170;
}
if ( ( V_152 -> V_13 == V_14 &&
V_152 -> V_172 > 1 && V_152 -> V_172 != V_6 -> V_173 ) ||
( V_152 -> V_13 == V_15 &&
V_152 -> V_172 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_152 -> V_172 ) ;
goto V_170;
}
if ( V_152 -> V_5 % V_162 -> V_174 || V_152 -> V_5 % V_162 -> V_175 ) {
F_9 ( L_20
L_21 , V_25 , V_152 -> V_5 , V_162 -> V_174 ,
V_162 -> V_175 ) ;
}
V_160 = 0 ;
V_90:
F_9 ( L_22 , V_25 , V_160 ) ;
return V_160 ;
V_170:
F_85 ( V_6 ) ;
goto V_90;
}
static void F_86 ( struct V_1 * V_152 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_152 -> V_172 ; V_176 ++ ) {
if ( ! V_152 -> V_177 [ V_176 ] )
break;
F_87 ( V_152 -> V_177 [ V_176 ] ) ;
}
F_87 ( V_152 -> V_177 ) ;
V_152 -> V_177 = NULL ;
}
static void
F_88 ( struct V_1 * V_152 )
{
F_86 ( V_152 ) ;
F_87 ( V_152 ) ;
}
static int
F_89 ( struct V_36 * V_178 ,
struct V_1 * V_152 ,
struct V_153 * V_154 ,
struct V_155 * V_156 ,
T_4 V_157 )
{
struct V_179 V_180 ;
struct V_181 V_182 ;
struct V_183 * V_184 ;
T_5 * V_185 ;
T_6 V_186 ;
int V_176 ;
F_9 ( L_23 , V_25 ) ;
V_184 = F_90 ( V_157 ) ;
if ( ! V_184 )
return - V_187 ;
F_91 ( & V_180 , & V_182 , V_154 -> V_188 -> V_32 , V_154 -> V_188 -> V_189 ) ;
F_92 ( & V_180 , F_93 ( V_184 ) , V_166 ) ;
V_185 = F_94 ( & V_180 , V_190 + 20 ) ;
if ( F_43 ( ! V_185 ) )
goto V_191;
memcpy ( V_156 , V_185 , sizeof( * V_156 ) ) ;
V_185 += F_95 ( V_190 ) ;
F_96 ( V_156 ) ;
V_186 = F_97 ( V_185 ++ ) ;
if ( V_186 & V_192 )
V_152 -> V_99 = 1 ;
if ( V_186 & V_193 )
V_152 -> V_13 = V_15 ;
else
V_152 -> V_13 = V_14 ;
V_152 -> V_5 = V_186 & ~ V_194 ;
V_152 -> V_171 = F_97 ( V_185 ++ ) ;
V_185 = F_98 ( V_185 , & V_152 -> V_10 ) ;
V_152 -> V_172 = F_97 ( V_185 ++ ) ;
F_9 ( L_24 ,
V_25 , V_186 , V_152 -> V_172 , V_152 -> V_171 ,
V_152 -> V_10 ) ;
if ( V_152 -> V_172 >
F_99 ( V_195 , V_196 ) )
goto V_191;
if ( V_152 -> V_172 > 0 ) {
V_152 -> V_177 = F_100 ( V_152 -> V_172 , sizeof( V_152 -> V_177 [ 0 ] ) ,
V_157 ) ;
if ( ! V_152 -> V_177 )
goto V_191;
}
for ( V_176 = 0 ; V_176 < V_152 -> V_172 ; V_176 ++ ) {
V_152 -> V_177 [ V_176 ] = F_101 ( sizeof( struct V_138 ) , V_157 ) ;
if ( ! V_152 -> V_177 [ V_176 ] )
goto V_197;
V_185 = F_94 ( & V_180 , 4 ) ;
if ( F_43 ( ! V_185 ) )
goto V_197;
V_152 -> V_177 [ V_176 ] -> V_198 = F_97 ( V_185 ++ ) ;
if ( sizeof( struct V_138 ) < V_152 -> V_177 [ V_176 ] -> V_198 ) {
F_102 ( V_199 L_25 ,
V_176 , V_152 -> V_177 [ V_176 ] -> V_198 ) ;
goto V_197;
}
V_185 = F_94 ( & V_180 , V_152 -> V_177 [ V_176 ] -> V_198 ) ;
if ( F_43 ( ! V_185 ) )
goto V_197;
memcpy ( V_152 -> V_177 [ V_176 ] -> V_17 , V_185 , V_152 -> V_177 [ V_176 ] -> V_198 ) ;
F_9 ( L_26 , V_25 ,
V_152 -> V_177 [ V_176 ] -> V_198 ) ;
}
F_103 ( V_184 ) ;
return 0 ;
V_197:
F_86 ( V_152 ) ;
V_191:
F_103 ( V_184 ) ;
return - V_86 ;
}
static void
F_104 ( struct V_11 * V_12 )
{
struct V_1 * V_152 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_85 ( V_152 -> V_6 ) ;
if ( V_12 -> V_200 . V_201 == V_202 ) {
struct V_203 * V_178 ;
V_178 = F_105 ( V_12 -> V_44 ) ;
V_178 -> V_204 . V_205 = 0 ;
F_87 ( V_178 -> V_204 . V_206 ) ;
V_178 -> V_204 . V_206 = NULL ;
}
F_88 ( V_152 ) ;
}
static int
F_106 ( struct V_11 * V_12 ,
struct V_207 * V_208 ,
T_4 V_157 )
{
struct V_1 * V_152 = F_5 ( V_12 ) ;
struct V_209 * V_206 ;
int V_198 ;
if ( V_152 -> V_99 )
return 0 ;
if ( V_208 -> V_133 -> V_205 != 0 ) {
return 0 ;
}
V_198 = ( V_152 -> V_13 == V_14 ) ?
V_152 -> V_6 -> V_173 : V_152 -> V_6 -> V_7 ;
V_206 = F_100 ( V_198 , sizeof( struct V_209 ) ,
V_157 ) ;
if ( ! V_206 )
return - V_187 ;
else {
int V_176 ;
F_107 ( V_208 -> V_210 ) ;
if ( V_208 -> V_133 -> V_205 != 0 )
F_87 ( V_206 ) ;
else {
V_208 -> V_133 -> V_206 = V_206 ;
V_208 -> V_133 -> V_205 = V_198 ;
for ( V_176 = 0 ; V_176 < V_198 ; V_176 ++ ) {
F_108 ( & V_206 [ V_176 ] . V_211 ) ;
F_108 ( & V_206 [ V_176 ] . V_212 ) ;
}
}
F_109 ( V_208 -> V_210 ) ;
return 0 ;
}
}
static struct V_11 *
F_110 ( struct V_36 * V_213 ,
struct V_153 * V_154 ,
T_4 V_157 )
{
struct V_1 * V_152 ;
int V_214 ;
struct V_155 V_156 ;
F_9 ( L_14 , V_25 ) ;
V_152 = F_111 ( sizeof( * V_152 ) , V_157 ) ;
if ( ! V_152 )
return NULL ;
V_214 = F_89 ( V_213 , V_152 , V_154 , & V_156 , V_157 ) ;
if ( V_214 != 0 || F_81 ( V_213 , V_152 , V_154 , & V_156 , V_157 ) ) {
F_88 ( V_152 ) ;
return NULL ;
}
return & V_152 -> V_215 ;
}
static bool
F_112 ( struct V_216 * V_217 , struct V_122 * V_218 ,
struct V_122 * V_219 )
{
T_3 V_220 , V_221 ;
T_2 V_5 ;
if ( ! F_113 ( V_217 , V_218 , V_219 ) ||
! F_114 ( V_217 , V_218 , V_219 ) )
return false ;
V_220 = ( T_3 ) F_115 ( V_218 ) ;
V_221 = ( T_3 ) F_115 ( V_219 ) ;
V_5 = F_5 ( V_217 -> V_222 ) -> V_5 ;
F_116 ( V_220 , V_5 ) ;
F_116 ( V_221 , V_5 ) ;
return ( V_220 == V_221 ) ;
}
static void
F_117 ( struct V_216 * V_217 ,
struct V_122 * V_219 )
{
F_118 ( V_217 -> V_222 != NULL ) ;
if ( V_219 -> V_223 != V_219 -> V_224 ) {
F_119 ( V_217 ) ;
return;
}
V_217 -> V_222 = F_120 ( V_217 -> V_225 ,
V_219 -> V_226 ,
0 ,
V_165 ,
V_227 ,
V_228 ) ;
if ( V_217 -> V_222 == NULL )
F_119 ( V_217 ) ;
}
static void
F_121 ( struct V_216 * V_217 ,
struct V_122 * V_219 )
{
struct V_207 V_208 ;
int V_160 ;
F_118 ( V_217 -> V_222 != NULL ) ;
if ( V_219 -> V_223 != V_219 -> V_224 )
goto V_229;
V_217 -> V_222 = F_120 ( V_217 -> V_225 ,
V_219 -> V_226 ,
0 ,
V_165 ,
V_202 ,
V_230 ) ;
if ( V_217 -> V_222 == NULL )
goto V_229;
F_122 ( & V_208 , V_217 -> V_225 , V_217 -> V_231 ) ;
V_160 = F_106 ( V_217 -> V_222 , & V_208 , V_230 ) ;
if ( V_160 < 0 ) {
F_67 ( V_217 -> V_222 ) ;
V_217 -> V_222 = NULL ;
goto V_229;
}
return;
V_229:
F_123 ( V_217 ) ;
}
static T_2 F_124 ( struct V_1 * V_152 , T_2 V_136 )
{
if ( V_152 -> V_13 == V_14 )
return F_71 ( & V_152 -> V_215 , V_136 ) ;
else
return V_136 ;
}
static void
F_125 ( struct V_122 * V_219 ,
struct V_207 * V_208 )
{
struct V_11 * V_232 = NULL ;
F_107 ( V_208 -> V_210 ) ;
if ( ! F_15 ( V_233 , & V_219 -> V_234 ) )
goto V_90;
V_208 -> V_133 -> V_235 -- ;
if ( F_126 ( & V_219 -> V_236 ) ) {
struct V_209 * V_237 ;
V_237 = F_127 ( & V_219 -> V_236 ,
struct V_209 ,
V_211 ) ;
V_232 = V_237 -> V_238 ;
V_237 -> V_238 = NULL ;
}
V_90:
F_128 ( V_219 , V_208 ) ;
F_109 ( V_208 -> V_210 ) ;
F_67 ( V_232 ) ;
}
static struct V_239 *
F_129 ( struct V_122 * V_219 ,
struct V_11 * V_12 ,
struct V_207 * V_208 )
{
struct V_1 * V_152 = F_5 ( V_12 ) ;
T_2 V_176 , V_136 ;
struct V_239 * V_240 ;
struct V_209 * V_206 ;
if ( V_152 -> V_99 )
return & V_208 -> V_241 -> V_240 ;
V_136 = F_70 ( V_12 , F_115 ( V_219 ) ) ;
V_176 = F_124 ( V_152 , V_136 ) ;
V_206 = V_208 -> V_133 -> V_206 ;
V_240 = & V_206 [ V_176 ] . V_211 ;
if ( F_130 ( V_240 ) ) {
V_206 [ V_176 ] . V_238 = F_131 ( V_12 ) ;
}
F_29 ( V_233 , & V_219 -> V_234 ) ;
V_208 -> V_133 -> V_235 ++ ;
return V_240 ;
}
static void
F_132 ( struct V_122 * V_219 ,
struct V_11 * V_12 ,
struct V_207 * V_208 )
{
struct V_239 * V_240 ;
V_240 = F_129 ( V_219 , V_12 , V_208 ) ;
F_133 ( V_219 , V_240 , V_208 ) ;
}
static T_2 F_134 ( struct V_11 * V_12 , T_2 V_176 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_176 ;
else
return F_71 ( V_12 , V_176 ) ;
}
static struct V_138 *
F_135 ( struct V_11 * V_12 , T_2 V_176 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_172 == 1 )
V_176 = 0 ;
else if ( V_2 -> V_172 == 0 )
return NULL ;
}
return V_2 -> V_177 [ V_176 ] ;
}
static int F_136 ( struct V_121 * V_17 , int V_242 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
T_2 V_137 ;
struct V_138 * V_139 ;
V_137 = F_134 ( V_12 , V_17 -> V_243 ) ;
V_133 = F_72 ( V_12 , V_137 ) ;
if ( ! V_133 )
goto V_191;
V_135 = F_73 ( V_133 -> V_97 , V_17 -> V_27 ) ;
if ( F_74 ( V_135 ) )
goto V_191;
F_9 ( L_27 , V_25 ,
V_17 -> V_27 -> V_104 , V_242 , F_75 ( & V_133 -> V_97 -> V_144 ) ) ;
V_17 -> V_244 = F_57 ;
F_76 ( & V_133 -> V_97 -> V_144 ) ;
V_17 -> V_97 = V_133 -> V_97 ;
V_139 = F_135 ( V_12 , V_17 -> V_243 ) ;
if ( V_139 )
V_17 -> args . V_139 = V_139 ;
return F_137 ( V_135 , V_17 ,
& V_245 , V_242 ,
V_147 ) ;
V_191:
F_55 ( V_17 ) ;
F_66 ( V_17 ) ;
return - V_91 ;
}
static int
F_138 ( struct V_239 * V_246 , struct V_239 * V_247 ,
struct V_207 * V_208 , int F_99 )
{
struct V_122 * V_219 , * V_248 ;
int V_249 = 0 ;
F_139 (req, tmp, src, wb_list) {
if ( ! F_140 ( V_219 ) )
continue;
F_141 ( & V_219 -> V_250 ) ;
if ( F_142 ( V_208 -> V_210 ) )
F_143 ( V_219 , V_248 , V_236 ) ;
F_128 ( V_219 , V_208 ) ;
F_144 ( V_233 , & V_219 -> V_234 ) ;
F_145 ( V_219 , V_247 ) ;
V_249 ++ ;
if ( ( V_249 == F_99 ) && ! V_208 -> V_34 )
break;
}
return V_249 ;
}
static int
F_146 ( struct V_209 * V_237 ,
struct V_207 * V_208 ,
int F_99 )
{
struct V_239 * V_246 = & V_237 -> V_211 ;
struct V_239 * V_247 = & V_237 -> V_212 ;
int V_249 ;
V_249 = F_138 ( V_246 , V_247 , V_208 , F_99 ) ;
if ( V_249 ) {
V_208 -> V_133 -> V_235 -= V_249 ;
V_208 -> V_133 -> V_251 += V_249 ;
V_237 -> V_252 = V_237 -> V_238 ;
if ( F_130 ( V_246 ) )
V_237 -> V_238 = NULL ;
else
F_131 ( V_237 -> V_252 ) ;
}
return V_249 ;
}
static int F_147 ( struct V_207 * V_208 ,
int F_99 )
{
int V_176 , V_253 = 0 , V_254 ;
for ( V_176 = 0 ; V_176 < V_208 -> V_133 -> V_205 && F_99 != 0 ; V_176 ++ ) {
V_254 = F_146 ( & V_208 -> V_133 -> V_206 [ V_176 ] ,
V_208 , F_99 ) ;
F_99 -= V_254 ;
V_253 += V_254 ;
}
return V_253 ;
}
static void F_148 ( struct V_239 * V_247 ,
struct V_207 * V_208 )
{
struct V_209 * V_255 ;
int V_176 ;
F_107 ( V_208 -> V_210 ) ;
for ( V_176 = 0 , V_255 = V_208 -> V_133 -> V_206 ; V_176 < V_208 -> V_133 -> V_205 ; V_176 ++ , V_255 ++ ) {
if ( F_138 ( & V_255 -> V_211 , V_247 , V_208 , 0 ) ) {
F_109 ( V_208 -> V_210 ) ;
F_67 ( V_255 -> V_238 ) ;
V_255 -> V_238 = NULL ;
F_107 ( V_208 -> V_210 ) ;
}
}
V_208 -> V_133 -> V_235 = 0 ;
F_109 ( V_208 -> V_210 ) ;
}
static unsigned int
F_149 ( struct V_207 * V_208 , struct V_239 * V_240 )
{
struct V_256 * V_257 ;
struct V_209 * V_237 ;
struct V_121 * V_17 ;
int V_176 , V_136 ;
unsigned int V_258 = 0 ;
V_257 = V_208 -> V_133 ;
V_237 = V_257 -> V_206 ;
for ( V_176 = 0 ; V_176 < V_257 -> V_205 ; V_176 ++ , V_237 ++ ) {
if ( F_130 ( & V_237 -> V_212 ) )
continue;
V_17 = F_150 () ;
if ( ! V_17 )
break;
V_17 -> V_243 = V_176 ;
V_17 -> V_12 = V_237 -> V_252 ;
V_237 -> V_252 = NULL ;
F_151 ( & V_17 -> V_32 , V_240 ) ;
V_258 ++ ;
}
for ( V_136 = V_176 ; V_136 < V_257 -> V_205 ; V_136 ++ , V_237 ++ ) {
if ( F_130 ( & V_237 -> V_212 ) )
continue;
F_152 ( & V_237 -> V_212 , V_237 -> V_252 , V_208 ) ;
F_67 ( V_237 -> V_252 ) ;
V_237 -> V_252 = NULL ;
}
return V_258 ;
}
static int
F_153 ( struct V_27 * V_27 , struct V_239 * V_259 ,
int V_242 , struct V_207 * V_208 )
{
struct V_121 * V_17 , * V_248 ;
F_154 ( V_240 ) ;
unsigned int V_258 = 0 ;
if ( ! F_130 ( V_259 ) ) {
V_17 = F_150 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_151 ( & V_17 -> V_32 , & V_240 ) ;
V_258 ++ ;
} else
F_152 ( V_259 , NULL , V_208 ) ;
}
V_258 += F_149 ( V_208 , & V_240 ) ;
if ( V_258 == 0 ) {
V_208 -> V_33 -> V_260 ( F_26 ( V_27 ) ) ;
goto V_90;
}
F_155 ( V_258 , & V_208 -> V_241 -> V_261 ) ;
F_139 (data, tmp, &list, pages) {
F_156 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_157 ( V_17 , V_259 , NULL , V_208 ) ;
F_137 ( F_158 ( V_27 ) , V_17 ,
V_17 -> V_116 , V_242 , 0 ) ;
} else {
struct V_209 * V_206 ;
V_206 = V_208 -> V_133 -> V_206 ;
F_157 ( V_17 , & V_206 [ V_17 -> V_243 ] . V_212 , V_17 -> V_12 , V_208 ) ;
F_136 ( V_17 , V_242 ) ;
}
}
V_90:
V_208 -> V_133 -> V_251 = 0 ;
return V_148 ;
}
static void
F_159 ( struct V_48 * V_158 )
{
F_160 ( F_84 ( V_158 , struct V_159 , V_169 ) ) ;
}
static struct V_36 *
F_161 ( struct V_27 * V_27 , T_4 V_157 )
{
struct V_203 * V_178 ;
V_178 = F_111 ( sizeof( * V_178 ) , V_157 ) ;
return & V_178 -> V_215 ;
}
static void
F_162 ( struct V_36 * V_37 )
{
F_87 ( F_105 ( V_37 ) ) ;
}
static struct V_256 *
F_163 ( struct V_27 * V_27 )
{
struct V_36 * V_105 = F_26 ( V_27 ) -> V_105 ;
if ( V_105 == NULL )
return NULL ;
else
return & F_105 ( V_105 ) -> V_204 ;
}
static int T_7 F_164 ( void )
{
F_102 ( V_262 L_28 ,
V_25 ) ;
return F_165 ( & V_263 ) ;
}
static void T_8 F_166 ( void )
{
F_102 ( V_262 L_29 ,
V_25 ) ;
F_167 ( & V_263 ) ;
}
