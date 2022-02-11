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
static void F_12 ( struct V_16 * V_17 )
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
static void F_14 ( struct V_27 * V_27 , struct V_35 * V_36 )
{
if ( ! F_15 ( V_37 , & V_36 -> V_38 ) )
return;
F_16 ( V_27 ) ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_11 * V_12 )
{
struct V_35 * V_36 = V_12 -> V_43 ;
struct V_27 * V_27 = V_36 -> V_44 ;
struct V_45 * V_46 = F_18 ( V_27 ) ;
struct V_47 * V_48 = F_19 ( V_12 ) ;
struct V_41 * V_49 = V_46 -> V_41 ;
struct V_50 * V_51 = & V_42 -> V_52 -> V_53 ;
if ( V_22 -> V_31 >= 0 )
return 0 ;
switch ( V_22 -> V_31 ) {
case - V_54 :
case - V_55 :
case - V_56 :
if ( V_40 == NULL )
break;
F_20 ( V_40 -> V_27 ) ;
case - V_57 :
if ( V_40 == NULL )
break;
if ( F_21 ( V_46 , V_40 ) < 0 )
goto V_58;
goto V_59;
case - V_60 :
if ( V_40 != NULL ) {
if ( F_21 ( V_46 , V_40 ) < 0 )
goto V_58;
}
F_22 ( V_49 ) ;
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
V_42 -> V_68 ) ;
F_23 ( V_42 -> V_52 , V_22 -> V_31 ) ;
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
F_27 ( & V_51 -> V_79 ) ;
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
F_28 ( V_48 ) ;
F_29 ( V_37 , & V_36 -> V_38 ) ;
F_27 ( & V_51 -> V_79 ) ;
default:
V_80:
F_9 ( L_7 , V_25 ,
V_22 -> V_31 ) ;
return - V_88 ;
}
V_89:
V_22 -> V_31 = 0 ;
return - V_90 ;
V_58:
V_22 -> V_31 = - V_85 ;
return 0 ;
V_59:
F_30 ( & V_49 -> V_91 , V_22 , NULL ) ;
if ( F_31 ( V_92 , & V_49 -> V_93 ) == 0 )
F_32 ( & V_49 -> V_91 , V_22 ) ;
goto V_89;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
F_34 ( V_17 , V_22 -> V_31 ) ;
V_94 = F_17 ( V_22 , V_17 -> args . V_95 -> V_40 ,
V_17 -> V_96 , V_19 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_12 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_90 :
F_35 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static void
F_36 ( struct V_16 * V_97 )
{
struct V_18 * V_19 = V_97 -> V_20 ;
if ( F_5 ( V_19 -> V_12 ) -> V_98 ||
V_97 -> V_99 . V_100 -> V_101 == V_102 )
return;
F_37 ( V_97 ) ;
F_9 ( L_8 , V_25 , V_19 -> V_27 -> V_103 ,
( unsigned long ) F_26 ( V_19 -> V_27 ) -> V_104 -> V_105 ) ;
}
bool
F_38 ( struct V_47 * V_106 )
{
return F_39 ( V_106 ) ||
F_40 ( V_106 ) ;
}
static bool
F_41 ( struct V_11 * V_12 )
{
struct V_47 * V_106 = F_19 ( V_12 ) ;
return F_38 ( V_106 ) ;
}
static void F_42 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_107 = V_17 ;
if ( F_43 ( F_31 ( V_108 , & V_107 -> args . V_95 -> V_24 ) ) ) {
F_44 ( V_22 , - V_85 ) ;
return;
}
if ( F_41 ( V_107 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_12 ( V_107 ) ;
F_44 ( V_22 , 0 ) ;
return;
}
V_107 -> V_109 = F_33 ;
if ( F_45 ( V_107 -> V_96 -> V_52 ,
& V_107 -> args . V_110 ,
& V_107 -> V_99 . V_111 ,
V_22 ) )
return;
if ( F_46 ( & V_107 -> args . V_112 , V_107 -> args . V_95 ,
V_107 -> args . V_113 , V_114 ) == - V_85 )
F_44 ( V_22 , - V_85 ) ;
}
static void F_47 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_107 = V_17 ;
F_9 ( L_10 , V_25 , V_22 -> V_31 ) ;
if ( F_31 ( V_23 , & V_107 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 ) {
F_48 ( V_22 , & V_107 -> V_99 . V_111 ) ;
return;
}
V_107 -> V_20 -> V_115 -> V_116 ( V_22 , V_17 ) ;
}
static void F_49 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_107 = V_17 ;
F_50 ( V_22 , F_18 ( V_107 -> V_20 -> V_27 ) -> V_117 -> V_118 ) ;
}
static void F_51 ( void * V_17 )
{
struct V_16 * V_107 = V_17 ;
struct V_35 * V_36 = V_107 -> V_20 -> V_12 -> V_43 ;
F_14 ( V_36 -> V_44 , V_36 ) ;
F_52 ( V_107 -> V_96 ) ;
V_107 -> V_20 -> V_115 -> V_119 ( V_17 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_94 ;
F_54 ( V_17 , V_22 -> V_31 ) ;
V_94 = F_17 ( V_22 , V_17 -> args . V_95 -> V_40 ,
V_17 -> V_96 , V_19 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_7 ( V_17 ) ;
return V_22 -> V_31 ;
case - V_90 :
F_35 ( V_22 ) ;
return - V_90 ;
}
F_36 ( V_17 ) ;
return 0 ;
}
static void F_55 ( struct V_120 * V_17 )
{
struct V_121 * V_122 = F_56 ( V_17 -> V_32 . V_123 ) ;
V_17 -> V_22 . V_31 = 0 ;
memcpy ( & V_17 -> V_100 . V_124 , & V_122 -> V_125 ,
sizeof( V_17 -> V_100 . V_124 ) ) ;
V_17 -> V_100 . V_124 . V_17 [ 0 ] ++ ;
}
static int F_57 ( struct V_21 * V_22 ,
struct V_120 * V_17 )
{
int V_94 ;
F_58 ( V_17 , V_22 -> V_31 ) ;
V_94 = F_17 ( V_22 , NULL , V_17 -> V_96 ,
V_17 -> V_12 ) ;
switch ( V_94 ) {
case - V_88 :
F_55 ( V_17 ) ;
return - V_90 ;
case - V_90 :
F_35 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_59 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_43 ( F_31 ( V_108 , & V_97 -> args . V_95 -> V_24 ) ) ) {
F_44 ( V_22 , - V_85 ) ;
return;
}
if ( F_41 ( V_97 -> V_20 -> V_12 ) ) {
F_9 ( L_9 , V_25 , V_22 -> V_26 ) ;
F_7 ( V_97 ) ;
F_44 ( V_22 , 0 ) ;
return;
}
if ( F_45 ( V_97 -> V_96 -> V_52 ,
& V_97 -> args . V_110 ,
& V_97 -> V_99 . V_111 ,
V_22 ) )
return;
if ( F_46 ( & V_97 -> args . V_112 , V_97 -> args . V_95 ,
V_97 -> args . V_113 , V_126 ) == - V_85 )
F_44 ( V_22 , - V_85 ) ;
}
static void F_60 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
if ( F_31 ( V_23 , & V_97 -> V_20 -> V_24 ) &&
V_22 -> V_31 == 0 ) {
F_48 ( V_22 , & V_97 -> V_99 . V_111 ) ;
return;
}
V_97 -> V_20 -> V_115 -> V_116 ( V_22 , V_17 ) ;
}
static void F_61 ( struct V_21 * V_22 , void * V_17 )
{
struct V_16 * V_97 = V_17 ;
F_50 ( V_22 , F_18 ( V_97 -> V_20 -> V_27 ) -> V_117 -> V_118 ) ;
}
static void F_62 ( void * V_17 )
{
struct V_16 * V_97 = V_17 ;
struct V_35 * V_36 = V_97 -> V_20 -> V_12 -> V_43 ;
F_14 ( V_36 -> V_44 , V_36 ) ;
F_52 ( V_97 -> V_96 ) ;
V_97 -> V_20 -> V_115 -> V_119 ( V_17 ) ;
}
static void F_63 ( struct V_21 * V_22 , void * V_17 )
{
struct V_120 * V_97 = V_17 ;
F_45 ( V_97 -> V_96 -> V_52 ,
& V_97 -> args . V_110 ,
& V_97 -> V_99 . V_111 ,
V_22 ) ;
}
static void F_64 ( struct V_21 * V_22 , void * V_17 )
{
struct V_120 * V_97 = V_17 ;
V_97 -> V_115 -> V_116 ( V_22 , V_17 ) ;
}
static void F_65 ( struct V_21 * V_22 , void * V_17 )
{
struct V_120 * V_127 = V_17 ;
F_50 ( V_22 , F_18 ( V_127 -> V_27 ) -> V_117 -> V_118 ) ;
}
static void F_66 ( void * V_128 )
{
struct V_120 * V_17 = V_128 ;
V_17 -> V_33 -> V_129 ( V_17 ) ;
F_67 ( V_17 -> V_12 ) ;
F_52 ( V_17 -> V_96 ) ;
F_68 ( V_17 ) ;
}
static enum V_130
F_69 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_135 , V_136 ;
struct V_137 * V_138 ;
F_9 ( L_11 ,
V_25 , V_19 -> V_27 -> V_103 ,
V_17 -> args . V_139 , ( V_140 ) V_17 -> args . V_30 , V_3 ) ;
V_135 = F_70 ( V_12 , V_3 ) ;
V_136 = F_71 ( V_12 , V_135 ) ;
V_132 = F_72 ( V_12 , V_136 ) ;
if ( ! V_132 )
return V_141 ;
V_134 = F_73 ( V_132 -> V_96 , V_19 -> V_27 ) ;
if ( F_74 ( V_134 ) )
return V_141 ;
F_9 ( L_12 , V_25 ,
V_132 -> V_142 , F_75 ( & V_132 -> V_96 -> V_143 ) ) ;
F_76 ( & V_132 -> V_96 -> V_143 ) ;
V_17 -> V_96 = V_132 -> V_96 ;
V_17 -> V_144 = V_136 ;
V_138 = F_77 ( V_12 , V_135 ) ;
if ( V_138 )
V_17 -> args . V_138 = V_138 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_145 = V_3 ;
F_78 ( V_134 , V_17 ,
& V_146 , 0 , V_147 ) ;
return V_148 ;
}
static enum V_130
F_79 ( struct V_16 * V_17 , int V_149 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_11 * V_12 = V_19 -> V_12 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_135 , V_136 ;
struct V_137 * V_138 ;
V_135 = F_70 ( V_12 , V_3 ) ;
V_136 = F_71 ( V_12 , V_135 ) ;
V_132 = F_72 ( V_12 , V_136 ) ;
if ( ! V_132 )
return V_141 ;
V_134 = F_73 ( V_132 -> V_96 , V_19 -> V_27 ) ;
if ( F_74 ( V_134 ) )
return V_141 ;
F_9 ( L_13 ,
V_25 , V_19 -> V_27 -> V_103 , V_149 , ( V_140 ) V_17 -> args . V_30 ,
V_3 , V_132 -> V_142 , F_75 ( & V_132 -> V_96 -> V_143 ) ) ;
V_17 -> V_109 = F_53 ;
F_76 ( & V_132 -> V_96 -> V_143 ) ;
V_17 -> V_96 = V_132 -> V_96 ;
V_17 -> V_144 = V_136 ;
V_138 = F_77 ( V_12 , V_135 ) ;
if ( V_138 )
V_17 -> args . V_138 = V_138 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_78 ( V_134 , V_17 ,
& V_150 , V_149 ,
V_147 ) ;
return V_148 ;
}
static int
F_80 ( struct V_35 * V_36 ,
struct V_1 * V_151 ,
struct V_152 * V_153 ,
struct V_154 * V_155 ,
T_4 V_156 )
{
struct V_47 * V_157 ;
struct V_158 * V_6 ;
int V_159 = - V_160 ;
F_9 ( L_14 , V_25 ) ;
if ( V_153 -> V_161 . V_3 != 0 ||
V_153 -> V_161 . V_162 != V_163 ) {
F_9 ( L_15 ,
V_25 ) ;
goto V_89;
}
if ( V_151 -> V_10 > V_153 -> V_161 . V_3 ) {
F_9 ( L_16 ,
V_25 , V_151 -> V_10 ) ;
goto V_89;
}
if ( ! V_151 -> V_5 ) {
F_9 ( L_17 ,
V_25 , V_151 -> V_5 ) ;
goto V_89;
}
V_157 = F_81 ( F_18 ( V_36 -> V_44 ) -> V_164 ,
F_18 ( V_36 -> V_44 ) -> V_41 , V_155 ) ;
if ( V_157 == NULL ) {
V_6 = F_82 ( V_36 -> V_44 , V_155 ,
V_36 -> V_165 , V_156 ) ;
if ( V_6 == NULL )
goto V_89;
} else
V_6 = F_83 ( V_157 , struct V_158 , V_166 ) ;
if ( F_38 ( & V_6 -> V_166 ) )
goto V_167;
V_151 -> V_6 = V_6 ;
if ( V_151 -> V_168 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_25 , V_151 -> V_168 ) ;
goto V_167;
}
if ( ( V_151 -> V_13 == V_14 &&
V_151 -> V_169 > 1 && V_151 -> V_169 != V_6 -> V_170 ) ||
( V_151 -> V_13 == V_15 &&
V_151 -> V_169 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_25 , V_151 -> V_169 ) ;
goto V_167;
}
V_159 = 0 ;
V_89:
F_9 ( L_20 , V_25 , V_159 ) ;
return V_159 ;
V_167:
F_84 ( V_6 ) ;
goto V_89;
}
static void F_85 ( struct V_1 * V_151 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_151 -> V_169 ; V_171 ++ ) {
if ( ! V_151 -> V_172 [ V_171 ] )
break;
F_86 ( V_151 -> V_172 [ V_171 ] ) ;
}
F_86 ( V_151 -> V_172 ) ;
V_151 -> V_172 = NULL ;
}
static void
F_87 ( struct V_1 * V_151 )
{
F_85 ( V_151 ) ;
F_86 ( V_151 ) ;
}
static int
F_88 ( struct V_35 * V_173 ,
struct V_1 * V_151 ,
struct V_152 * V_153 ,
struct V_154 * V_155 ,
T_4 V_156 )
{
struct V_174 V_175 ;
struct V_176 V_177 ;
struct V_178 * V_179 ;
T_5 * V_180 ;
T_6 V_181 ;
int V_171 ;
F_9 ( L_21 , V_25 ) ;
V_179 = F_89 ( V_156 ) ;
if ( ! V_179 )
return - V_182 ;
F_90 ( & V_175 , & V_177 , V_153 -> V_183 -> V_32 , V_153 -> V_183 -> V_184 ) ;
F_91 ( & V_175 , F_92 ( V_179 ) , V_185 ) ;
V_180 = F_93 ( & V_175 , V_186 + 20 ) ;
if ( F_43 ( ! V_180 ) )
goto V_187;
memcpy ( V_155 , V_180 , sizeof( * V_155 ) ) ;
V_180 += F_94 ( V_186 ) ;
F_95 ( V_155 ) ;
V_181 = F_96 ( V_180 ++ ) ;
if ( V_181 & V_188 )
V_151 -> V_98 = 1 ;
if ( V_181 & V_189 )
V_151 -> V_13 = V_15 ;
else
V_151 -> V_13 = V_14 ;
V_151 -> V_5 = V_181 & ~ V_190 ;
V_151 -> V_168 = F_96 ( V_180 ++ ) ;
V_180 = F_97 ( V_180 , & V_151 -> V_10 ) ;
V_151 -> V_169 = F_96 ( V_180 ++ ) ;
F_9 ( L_22 ,
V_25 , V_181 , V_151 -> V_169 , V_151 -> V_168 ,
V_151 -> V_10 ) ;
if ( V_151 -> V_169 >
F_98 ( V_191 , V_192 ) )
goto V_187;
if ( V_151 -> V_169 > 0 ) {
V_151 -> V_172 = F_99 ( V_151 -> V_169 , sizeof( V_151 -> V_172 [ 0 ] ) ,
V_156 ) ;
if ( ! V_151 -> V_172 )
goto V_187;
}
for ( V_171 = 0 ; V_171 < V_151 -> V_169 ; V_171 ++ ) {
V_151 -> V_172 [ V_171 ] = F_100 ( sizeof( struct V_137 ) , V_156 ) ;
if ( ! V_151 -> V_172 [ V_171 ] )
goto V_193;
V_180 = F_93 ( & V_175 , 4 ) ;
if ( F_43 ( ! V_180 ) )
goto V_193;
V_151 -> V_172 [ V_171 ] -> V_194 = F_96 ( V_180 ++ ) ;
if ( sizeof( struct V_137 ) < V_151 -> V_172 [ V_171 ] -> V_194 ) {
F_101 ( V_195 L_23 ,
V_171 , V_151 -> V_172 [ V_171 ] -> V_194 ) ;
goto V_193;
}
V_180 = F_93 ( & V_175 , V_151 -> V_172 [ V_171 ] -> V_194 ) ;
if ( F_43 ( ! V_180 ) )
goto V_193;
memcpy ( V_151 -> V_172 [ V_171 ] -> V_17 , V_180 , V_151 -> V_172 [ V_171 ] -> V_194 ) ;
F_9 ( L_24 , V_25 ,
V_151 -> V_172 [ V_171 ] -> V_194 ) ;
}
F_102 ( V_179 ) ;
return 0 ;
V_193:
F_85 ( V_151 ) ;
V_187:
F_102 ( V_179 ) ;
return - V_85 ;
}
static void
F_103 ( struct V_11 * V_12 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_25 ) ;
F_84 ( V_151 -> V_6 ) ;
if ( V_12 -> V_196 . V_197 == V_198 ) {
struct V_199 * V_173 ;
V_173 = F_104 ( V_12 -> V_43 ) ;
V_173 -> V_200 . V_201 = 0 ;
F_86 ( V_173 -> V_200 . V_202 ) ;
V_173 -> V_200 . V_202 = NULL ;
}
F_87 ( V_151 ) ;
}
static int
F_105 ( struct V_11 * V_12 ,
struct V_203 * V_204 ,
T_4 V_156 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
struct V_205 * V_202 ;
int V_194 , V_171 ;
if ( V_151 -> V_98 )
return 0 ;
V_194 = ( V_151 -> V_13 == V_14 ) ?
V_151 -> V_6 -> V_170 : V_151 -> V_6 -> V_7 ;
if ( V_204 -> V_132 -> V_201 >= V_194 ) {
return 0 ;
}
V_202 = F_99 ( V_194 , sizeof( struct V_205 ) ,
V_156 ) ;
if ( ! V_202 )
return - V_182 ;
for ( V_171 = 0 ; V_171 < V_194 ; V_171 ++ ) {
F_106 ( & V_202 [ V_171 ] . V_206 ) ;
F_106 ( & V_202 [ V_171 ] . V_207 ) ;
V_202 [ V_171 ] . V_208 . V_101 = V_209 ;
}
F_107 ( V_204 -> V_210 ) ;
if ( V_204 -> V_132 -> V_201 >= V_194 )
goto V_89;
for ( V_171 = 0 ; V_171 < V_204 -> V_132 -> V_201 ; V_171 ++ ) {
F_108 ( & V_204 -> V_132 -> V_202 [ V_171 ] . V_206 ,
& V_202 [ V_171 ] . V_206 ) ;
F_108 ( & V_204 -> V_132 -> V_202 [ V_171 ] . V_207 ,
& V_202 [ V_171 ] . V_207 ) ;
V_202 [ V_171 ] . V_208 . V_101 =
V_204 -> V_132 -> V_202 [ V_171 ] . V_208 . V_101 ;
V_202 [ V_171 ] . V_211 = V_204 -> V_132 -> V_202 [ V_171 ] . V_211 ;
V_202 [ V_171 ] . V_212 = V_204 -> V_132 -> V_202 [ V_171 ] . V_212 ;
}
F_109 ( V_204 -> V_132 -> V_202 , V_202 ) ;
V_204 -> V_132 -> V_201 = V_194 ;
V_89:
F_110 ( V_204 -> V_210 ) ;
F_86 ( V_202 ) ;
return 0 ;
}
static struct V_11 *
F_111 ( struct V_35 * V_213 ,
struct V_152 * V_153 ,
T_4 V_156 )
{
struct V_1 * V_151 ;
int V_214 ;
struct V_154 V_155 ;
F_9 ( L_14 , V_25 ) ;
V_151 = F_112 ( sizeof( * V_151 ) , V_156 ) ;
if ( ! V_151 )
return NULL ;
V_214 = F_88 ( V_213 , V_151 , V_153 , & V_155 , V_156 ) ;
if ( V_214 != 0 || F_80 ( V_213 , V_151 , V_153 , & V_155 , V_156 ) ) {
F_87 ( V_151 ) ;
return NULL ;
}
return & V_151 -> V_215 ;
}
static V_140
F_113 ( struct V_216 * V_217 , struct V_121 * V_218 ,
struct V_121 * V_219 )
{
unsigned int V_194 ;
T_3 V_220 , V_221 ;
T_2 V_222 ;
T_3 V_223 = V_217 -> V_224 -> V_196 . V_3 ;
T_2 V_5 = F_5 ( V_217 -> V_224 ) -> V_5 ;
V_194 = F_114 ( V_217 , V_218 , V_219 ) ;
if ( ! V_194 )
return 0 ;
if ( V_218 ) {
V_220 = ( T_3 ) F_115 ( V_218 ) - V_223 ;
V_221 = ( T_3 ) F_115 ( V_219 ) - V_223 ;
F_116 ( V_220 , V_5 ) ;
F_116 ( V_221 , V_5 ) ;
if ( V_220 != V_221 )
return 0 ;
}
F_3 ( ( T_3 ) F_115 ( V_219 ) - V_223 ,
V_5 ,
& V_222 ) ;
F_117 ( V_222 > V_5 ) ;
if ( V_222 >= V_5 )
return 0 ;
return F_118 ( V_5 - ( unsigned int ) V_222 , V_194 ) ;
}
static void
F_119 ( struct V_216 * V_217 ,
struct V_121 * V_219 )
{
if ( ! V_217 -> V_224 )
V_217 -> V_224 = F_120 ( V_217 -> V_225 ,
V_219 -> V_226 ,
0 ,
V_163 ,
V_227 ,
V_228 ) ;
if ( V_217 -> V_224 == NULL )
F_121 ( V_217 ) ;
}
static void
F_122 ( struct V_216 * V_217 ,
struct V_121 * V_219 )
{
struct V_203 V_204 ;
int V_159 ;
if ( ! V_217 -> V_224 )
V_217 -> V_224 = F_120 ( V_217 -> V_225 ,
V_219 -> V_226 ,
0 ,
V_163 ,
V_198 ,
V_229 ) ;
if ( V_217 -> V_224 == NULL )
goto V_230;
F_123 ( & V_204 , V_217 -> V_225 , V_217 -> V_231 ) ;
V_159 = F_105 ( V_217 -> V_224 , & V_204 , V_229 ) ;
if ( V_159 < 0 ) {
F_67 ( V_217 -> V_224 ) ;
V_217 -> V_224 = NULL ;
goto V_230;
}
return;
V_230:
F_124 ( V_217 ) ;
}
static T_2 F_125 ( struct V_1 * V_151 , T_2 V_135 )
{
if ( V_151 -> V_13 == V_14 )
return F_71 ( & V_151 -> V_215 , V_135 ) ;
else
return V_135 ;
}
static void
F_126 ( struct V_121 * V_219 ,
struct V_203 * V_204 )
{
struct V_11 * V_232 = NULL ;
F_107 ( V_204 -> V_210 ) ;
if ( ! F_15 ( V_233 , & V_219 -> V_234 ) )
goto V_89;
V_204 -> V_132 -> V_235 -- ;
if ( F_127 ( & V_219 -> V_236 ) ) {
struct V_205 * V_237 ;
V_237 = F_128 ( & V_219 -> V_236 ,
struct V_205 ,
V_206 ) ;
V_232 = V_237 -> V_211 ;
V_237 -> V_211 = NULL ;
}
V_89:
F_129 ( V_219 , V_204 ) ;
F_110 ( V_204 -> V_210 ) ;
F_67 ( V_232 ) ;
}
static struct V_238 *
F_130 ( struct V_121 * V_219 ,
struct V_11 * V_12 ,
struct V_203 * V_204 )
{
struct V_1 * V_151 = F_5 ( V_12 ) ;
T_2 V_171 , V_135 ;
struct V_238 * V_239 ;
struct V_205 * V_202 ;
if ( V_151 -> V_98 )
return & V_204 -> V_240 -> V_239 ;
V_135 = F_70 ( V_12 , F_115 ( V_219 ) ) ;
V_171 = F_125 ( V_151 , V_135 ) ;
F_107 ( V_204 -> V_210 ) ;
V_202 = V_204 -> V_132 -> V_202 ;
V_239 = & V_202 [ V_171 ] . V_206 ;
if ( F_131 ( V_239 ) ) {
V_202 [ V_171 ] . V_211 = F_132 ( V_12 ) ;
}
F_29 ( V_233 , & V_219 -> V_234 ) ;
V_204 -> V_132 -> V_235 ++ ;
F_110 ( V_204 -> V_210 ) ;
return V_239 ;
}
static void
F_133 ( struct V_121 * V_219 ,
struct V_11 * V_12 ,
struct V_203 * V_204 )
{
struct V_238 * V_239 ;
V_239 = F_130 ( V_219 , V_12 , V_204 ) ;
F_134 ( V_219 , V_239 , V_204 ) ;
}
static T_2 F_135 ( struct V_11 * V_12 , T_2 V_171 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_171 ;
else
return F_71 ( V_12 , V_171 ) ;
}
static struct V_137 *
F_136 ( struct V_11 * V_12 , T_2 V_171 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_169 == 1 )
V_171 = 0 ;
else if ( V_2 -> V_169 == 0 )
return NULL ;
}
return V_2 -> V_172 [ V_171 ] ;
}
static int F_137 ( struct V_120 * V_17 , int V_241 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
T_2 V_136 ;
struct V_137 * V_138 ;
V_136 = F_135 ( V_12 , V_17 -> V_242 ) ;
V_132 = F_72 ( V_12 , V_136 ) ;
if ( ! V_132 )
goto V_187;
V_134 = F_73 ( V_132 -> V_96 , V_17 -> V_27 ) ;
if ( F_74 ( V_134 ) )
goto V_187;
F_9 ( L_25 , V_25 ,
V_17 -> V_27 -> V_103 , V_241 , F_75 ( & V_132 -> V_96 -> V_143 ) ) ;
V_17 -> V_243 = F_57 ;
F_76 ( & V_132 -> V_96 -> V_143 ) ;
V_17 -> V_96 = V_132 -> V_96 ;
V_138 = F_136 ( V_12 , V_17 -> V_242 ) ;
if ( V_138 )
V_17 -> args . V_138 = V_138 ;
return F_138 ( V_134 , V_17 ,
& V_244 , V_241 ,
V_147 ) ;
V_187:
F_55 ( V_17 ) ;
F_66 ( V_17 ) ;
return - V_90 ;
}
static int
F_139 ( struct V_238 * V_245 , struct V_238 * V_246 ,
struct V_203 * V_204 , int F_98 )
{
struct V_121 * V_219 , * V_247 ;
int V_248 = 0 ;
F_140 (req, tmp, src, wb_list) {
if ( ! F_141 ( V_219 ) )
continue;
F_142 ( & V_219 -> V_249 ) ;
if ( F_143 ( V_204 -> V_210 ) )
F_144 ( V_219 , V_247 , V_236 ) ;
F_129 ( V_219 , V_204 ) ;
F_145 ( V_233 , & V_219 -> V_234 ) ;
F_146 ( V_219 , V_246 ) ;
V_248 ++ ;
if ( ( V_248 == F_98 ) && ! V_204 -> V_34 )
break;
}
return V_248 ;
}
static int
F_147 ( struct V_205 * V_237 ,
struct V_203 * V_204 ,
int F_98 )
{
struct V_238 * V_245 = & V_237 -> V_206 ;
struct V_238 * V_246 = & V_237 -> V_207 ;
int V_248 ;
V_248 = F_139 ( V_245 , V_246 , V_204 , F_98 ) ;
if ( V_248 ) {
V_204 -> V_132 -> V_235 -= V_248 ;
V_204 -> V_132 -> V_250 += V_248 ;
V_237 -> V_212 = V_237 -> V_211 ;
if ( F_131 ( V_245 ) )
V_237 -> V_211 = NULL ;
else
F_132 ( V_237 -> V_212 ) ;
}
return V_248 ;
}
static int F_148 ( struct V_203 * V_204 ,
int F_98 )
{
int V_171 , V_251 = 0 , V_252 ;
for ( V_171 = 0 ; V_171 < V_204 -> V_132 -> V_201 && F_98 != 0 ; V_171 ++ ) {
V_252 = F_147 ( & V_204 -> V_132 -> V_202 [ V_171 ] ,
V_204 , F_98 ) ;
F_98 -= V_252 ;
V_251 += V_252 ;
}
return V_251 ;
}
static void F_149 ( struct V_238 * V_246 ,
struct V_203 * V_204 )
{
struct V_205 * V_253 ;
struct V_11 * V_232 ;
int V_171 ;
V_254:
F_107 ( V_204 -> V_210 ) ;
for ( V_171 = 0 , V_253 = V_204 -> V_132 -> V_202 ; V_171 < V_204 -> V_132 -> V_201 ; V_171 ++ , V_253 ++ ) {
if ( F_139 ( & V_253 -> V_206 , V_246 , V_204 , 0 ) ) {
V_232 = V_253 -> V_211 ;
V_253 -> V_211 = NULL ;
F_110 ( V_204 -> V_210 ) ;
F_67 ( V_232 ) ;
goto V_254;
}
}
V_204 -> V_132 -> V_235 = 0 ;
F_110 ( V_204 -> V_210 ) ;
}
static unsigned int
F_150 ( struct V_203 * V_204 , struct V_238 * V_239 )
{
struct V_255 * V_256 ;
struct V_205 * V_237 ;
struct V_120 * V_17 ;
int V_171 , V_135 ;
unsigned int V_257 = 0 ;
struct V_11 * V_232 ;
V_256 = V_204 -> V_132 ;
V_237 = V_256 -> V_202 ;
for ( V_171 = 0 ; V_171 < V_256 -> V_201 ; V_171 ++ , V_237 ++ ) {
if ( F_131 ( & V_237 -> V_207 ) )
continue;
V_17 = F_151 () ;
if ( ! V_17 )
break;
V_17 -> V_242 = V_171 ;
F_107 ( V_204 -> V_210 ) ;
V_17 -> V_12 = V_237 -> V_212 ;
V_237 -> V_212 = NULL ;
F_110 ( V_204 -> V_210 ) ;
F_152 ( & V_17 -> V_32 , V_239 ) ;
V_257 ++ ;
}
for ( V_135 = V_171 ; V_135 < V_256 -> V_201 ; V_135 ++ , V_237 ++ ) {
if ( F_131 ( & V_237 -> V_207 ) )
continue;
F_153 ( & V_237 -> V_207 , V_237 -> V_212 , V_204 ) ;
F_107 ( V_204 -> V_210 ) ;
V_232 = V_237 -> V_212 ;
V_237 -> V_212 = NULL ;
F_110 ( V_204 -> V_210 ) ;
F_67 ( V_232 ) ;
}
return V_257 ;
}
static int
F_154 ( struct V_27 * V_27 , struct V_238 * V_258 ,
int V_241 , struct V_203 * V_204 )
{
struct V_120 * V_17 , * V_247 ;
F_155 ( V_239 ) ;
unsigned int V_257 = 0 ;
if ( ! F_131 ( V_258 ) ) {
V_17 = F_151 () ;
if ( V_17 != NULL ) {
V_17 -> V_12 = NULL ;
F_152 ( & V_17 -> V_32 , & V_239 ) ;
V_257 ++ ;
} else
F_153 ( V_258 , NULL , V_204 ) ;
}
V_257 += F_150 ( V_204 , & V_239 ) ;
if ( V_257 == 0 ) {
V_204 -> V_33 -> V_259 ( F_26 ( V_27 ) ) ;
goto V_89;
}
F_156 ( V_257 , & V_204 -> V_240 -> V_260 ) ;
F_140 (data, tmp, &list, pages) {
F_157 ( & V_17 -> V_32 ) ;
if ( ! V_17 -> V_12 ) {
F_158 ( V_17 , V_258 , NULL , V_204 ) ;
F_138 ( F_159 ( V_27 ) , V_17 ,
V_17 -> V_115 , V_241 , 0 ) ;
} else {
struct V_205 * V_202 ;
V_202 = V_204 -> V_132 -> V_202 ;
F_158 ( V_17 , & V_202 [ V_17 -> V_242 ] . V_207 , V_17 -> V_12 , V_204 ) ;
F_137 ( V_17 , V_241 ) ;
}
}
V_89:
V_204 -> V_132 -> V_250 = 0 ;
return V_148 ;
}
static void
F_160 ( struct V_47 * V_157 )
{
F_161 ( F_83 ( V_157 , struct V_158 , V_166 ) ) ;
}
static struct V_35 *
F_162 ( struct V_27 * V_27 , T_4 V_156 )
{
struct V_199 * V_173 ;
V_173 = F_112 ( sizeof( * V_173 ) , V_156 ) ;
return V_173 != NULL ? & V_173 -> V_215 : NULL ;
}
static void
F_163 ( struct V_35 * V_36 )
{
F_86 ( F_104 ( V_36 ) ) ;
}
static struct V_255 *
F_164 ( struct V_27 * V_27 )
{
struct V_35 * V_104 = F_26 ( V_27 ) -> V_104 ;
if ( V_104 == NULL )
return NULL ;
else
return & F_104 ( V_104 ) -> V_200 ;
}
static int T_7 F_165 ( void )
{
F_101 ( V_261 L_26 ,
V_25 ) ;
return F_166 ( & V_262 ) ;
}
static void T_8 F_167 ( void )
{
F_101 ( V_261 L_27 ,
V_25 ) ;
F_168 ( & V_262 ) ;
}
