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
static void F_14 ( struct V_24 * V_24 , struct V_29 * V_30 )
{
if ( ! F_15 ( V_31 , & V_30 -> V_32 ) )
return;
F_16 ( V_24 ) ;
}
static int F_17 ( struct V_18 * V_19 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_11 * V_12 )
{
struct V_29 * V_30 = V_12 -> V_37 ;
struct V_24 * V_24 = V_30 -> V_38 ;
struct V_39 * V_40 = F_18 ( V_24 ) ;
struct V_41 * V_42 = F_19 ( V_12 ) ;
struct V_35 * V_43 = V_40 -> V_35 ;
struct V_44 * V_45 = & V_36 -> V_46 -> V_47 ;
if ( V_19 -> V_28 >= 0 )
return 0 ;
switch ( V_19 -> V_28 ) {
case - V_48 :
case - V_49 :
case - V_50 :
if ( V_34 == NULL )
break;
F_20 ( V_34 -> V_24 ) ;
case - V_51 :
if ( V_34 == NULL )
break;
if ( F_21 ( V_40 , V_34 ) < 0 )
goto V_52;
goto V_53;
case - V_54 :
if ( V_34 != NULL ) {
if ( F_21 ( V_40 , V_34 ) < 0 )
goto V_52;
}
F_22 ( V_43 ) ;
goto V_53;
case - V_55 :
case - V_56 :
case - V_57 :
case - V_58 :
case - V_59 :
case - V_60 :
case - V_61 :
F_9 ( L_3
L_4 , V_22 , V_19 -> V_28 ,
V_36 -> V_62 ) ;
F_23 ( V_36 -> V_46 , V_19 -> V_28 ) ;
break;
case - V_63 :
case - V_64 :
F_24 ( V_19 , V_65 ) ;
break;
case - V_66 :
break;
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
F_9 ( L_5 , V_22 ,
V_19 -> V_28 ) ;
F_25 ( F_26 ( V_24 ) ) ;
F_27 ( & V_45 -> V_73 ) ;
goto V_74;
case - V_75 :
case - V_76 :
case - V_77 :
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
F_9 ( L_6 , V_22 ,
V_19 -> V_28 ) ;
F_28 ( V_42 ) ;
F_29 ( V_31 , & V_30 -> V_32 ) ;
F_27 ( & V_45 -> V_73 ) ;
default:
V_74:
F_9 ( L_7 , V_22 ,
V_19 -> V_28 ) ;
return - V_82 ;
}
V_83:
V_19 -> V_28 = 0 ;
return - V_84 ;
V_52:
V_19 -> V_28 = - V_79 ;
return 0 ;
V_53:
F_30 ( & V_43 -> V_85 , V_19 , NULL ) ;
if ( F_31 ( V_86 , & V_43 -> V_87 ) == 0 )
F_32 ( & V_43 -> V_85 , V_19 ) ;
goto V_83;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_88 ;
F_34 ( V_17 , V_19 -> V_28 ) ;
V_88 = F_17 ( V_19 , V_17 -> args . V_89 -> V_34 ,
V_17 -> V_90 , V_17 -> V_12 ) ;
switch ( V_88 ) {
case - V_82 :
F_12 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_84 :
F_35 ( V_19 ) ;
return - V_84 ;
}
return 0 ;
}
static void
F_36 ( struct V_16 * V_17 )
{
if ( F_5 ( V_17 -> V_12 ) -> V_91 ||
V_17 -> V_92 . V_93 -> V_94 == V_95 )
return;
F_37 ( V_17 ) ;
F_9 ( L_8 , V_22 , V_17 -> V_24 -> V_96 ,
( unsigned long ) F_26 ( V_17 -> V_24 ) -> V_97 -> V_98 ) ;
}
bool
F_38 ( struct V_41 * V_99 )
{
return F_39 ( V_99 ) ||
F_40 ( V_99 ) ;
}
static bool
F_41 ( struct V_11 * V_12 )
{
struct V_41 * V_99 = F_19 ( V_12 ) ;
return F_38 ( V_99 ) ;
}
static void F_42 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
if ( F_43 ( F_31 ( V_101 , & V_17 -> args . V_89 -> V_21 ) ) ) {
F_44 ( V_19 , - V_79 ) ;
return;
}
if ( F_41 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_12 ( V_17 ) ;
F_44 ( V_19 , 0 ) ;
return;
}
V_17 -> V_102 = F_33 ;
if ( F_45 ( V_17 -> V_90 -> V_46 ,
& V_17 -> args . V_103 ,
& V_17 -> V_92 . V_104 ,
V_19 ) )
return;
if ( F_46 ( & V_17 -> args . V_105 , V_17 -> args . V_89 ,
V_17 -> args . V_106 , V_107 ) == - V_79 )
F_44 ( V_19 , - V_79 ) ;
}
static void F_47 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
F_9 ( L_10 , V_22 , V_19 -> V_28 ) ;
if ( F_31 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_48 ( V_19 , & V_17 -> V_92 . V_104 ) ;
return;
}
V_17 -> V_108 -> V_109 ( V_19 , V_100 ) ;
}
static void F_49 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
F_50 ( V_19 , F_18 ( V_17 -> V_24 ) -> V_110 -> V_111 ) ;
}
static void F_51 ( void * V_100 )
{
struct V_16 * V_17 = V_100 ;
struct V_29 * V_30 = V_17 -> V_12 -> V_37 ;
F_14 ( V_30 -> V_38 , V_30 ) ;
F_52 ( V_17 -> V_90 ) ;
V_17 -> V_108 -> V_112 ( V_100 ) ;
}
static int F_53 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_88 ;
F_54 ( V_17 , V_19 -> V_28 ) ;
V_88 = F_17 ( V_19 , V_17 -> args . V_89 -> V_34 ,
V_17 -> V_90 , V_17 -> V_12 ) ;
switch ( V_88 ) {
case - V_82 :
F_7 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_84 :
F_35 ( V_19 ) ;
return - V_84 ;
}
F_36 ( V_17 ) ;
return 0 ;
}
static void F_55 ( struct V_113 * V_100 )
{
struct V_114 * V_115 = F_56 ( V_100 -> V_116 . V_117 ) ;
V_100 -> V_19 . V_28 = 0 ;
memcpy ( & V_100 -> V_93 . V_118 , & V_115 -> V_119 ,
sizeof( V_100 -> V_93 . V_118 ) ) ;
V_100 -> V_93 . V_118 . V_100 [ 0 ] ++ ;
}
static int F_57 ( struct V_18 * V_19 ,
struct V_113 * V_100 )
{
int V_88 ;
F_58 ( V_100 , V_19 -> V_28 ) ;
V_88 = F_17 ( V_19 , NULL , V_100 -> V_90 ,
V_100 -> V_12 ) ;
switch ( V_88 ) {
case - V_82 :
F_55 ( V_100 ) ;
return - V_84 ;
case - V_84 :
F_35 ( V_19 ) ;
return - V_84 ;
}
return 0 ;
}
static void F_59 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
if ( F_43 ( F_31 ( V_101 , & V_17 -> args . V_89 -> V_21 ) ) ) {
F_44 ( V_19 , - V_79 ) ;
return;
}
if ( F_41 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_7 ( V_17 ) ;
F_44 ( V_19 , 0 ) ;
return;
}
if ( F_45 ( V_17 -> V_90 -> V_46 ,
& V_17 -> args . V_103 ,
& V_17 -> V_92 . V_104 ,
V_19 ) )
return;
if ( F_46 ( & V_17 -> args . V_105 , V_17 -> args . V_89 ,
V_17 -> args . V_106 , V_120 ) == - V_79 )
F_44 ( V_19 , - V_79 ) ;
}
static void F_60 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
if ( F_31 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_48 ( V_19 , & V_17 -> V_92 . V_104 ) ;
return;
}
V_17 -> V_108 -> V_109 ( V_19 , V_100 ) ;
}
static void F_61 ( struct V_18 * V_19 , void * V_100 )
{
struct V_16 * V_17 = V_100 ;
F_50 ( V_19 , F_18 ( V_17 -> V_24 ) -> V_110 -> V_111 ) ;
}
static void F_62 ( void * V_100 )
{
struct V_16 * V_17 = V_100 ;
struct V_29 * V_30 = V_17 -> V_12 -> V_37 ;
F_14 ( V_30 -> V_38 , V_30 ) ;
F_52 ( V_17 -> V_90 ) ;
V_17 -> V_108 -> V_112 ( V_100 ) ;
}
static void F_63 ( struct V_18 * V_19 , void * V_100 )
{
struct V_113 * V_121 = V_100 ;
F_45 ( V_121 -> V_90 -> V_46 ,
& V_121 -> args . V_103 ,
& V_121 -> V_92 . V_104 ,
V_19 ) ;
}
static void F_64 ( struct V_18 * V_19 , void * V_100 )
{
struct V_113 * V_121 = V_100 ;
V_121 -> V_108 -> V_109 ( V_19 , V_100 ) ;
}
static void F_65 ( struct V_18 * V_19 , void * V_100 )
{
struct V_113 * V_122 = V_100 ;
F_50 ( V_19 , F_18 ( V_122 -> V_24 ) -> V_110 -> V_111 ) ;
}
static void F_66 ( void * V_123 )
{
struct V_113 * V_100 = V_123 ;
V_100 -> V_124 -> V_125 ( V_100 ) ;
F_67 ( V_100 -> V_12 ) ;
F_52 ( V_100 -> V_90 ) ;
F_68 ( V_100 ) ;
}
static enum V_126
F_69 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_131 , V_132 ;
struct V_133 * V_134 ;
F_9 ( L_11 ,
V_22 , V_17 -> V_24 -> V_96 ,
V_17 -> args . V_135 , ( V_136 ) V_17 -> args . V_27 , V_3 ) ;
V_131 = F_70 ( V_12 , V_3 ) ;
V_132 = F_71 ( V_12 , V_131 ) ;
V_128 = F_72 ( V_12 , V_132 ) ;
if ( ! V_128 )
return V_137 ;
V_130 = F_73 ( V_128 -> V_90 , V_17 -> V_24 ) ;
if ( F_74 ( V_130 ) )
return V_137 ;
F_9 ( L_12 , V_22 ,
V_128 -> V_138 , F_75 ( & V_128 -> V_90 -> V_139 ) ) ;
F_76 ( & V_128 -> V_90 -> V_139 ) ;
V_17 -> V_90 = V_128 -> V_90 ;
V_17 -> V_140 = V_132 ;
V_134 = F_77 ( V_12 , V_131 ) ;
if ( V_134 )
V_17 -> args . V_134 = V_134 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_141 = V_3 ;
F_78 ( V_130 , V_17 ,
& V_142 , 0 , V_143 ) ;
return V_144 ;
}
static enum V_126
F_79 ( struct V_16 * V_17 , int V_145 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_131 , V_132 ;
struct V_133 * V_134 ;
V_131 = F_70 ( V_12 , V_3 ) ;
V_132 = F_71 ( V_12 , V_131 ) ;
V_128 = F_72 ( V_12 , V_132 ) ;
if ( ! V_128 )
return V_137 ;
V_130 = F_73 ( V_128 -> V_90 , V_17 -> V_24 ) ;
if ( F_74 ( V_130 ) )
return V_137 ;
F_9 ( L_13 ,
V_22 , V_17 -> V_24 -> V_96 , V_145 , ( V_136 ) V_17 -> args . V_27 ,
V_3 , V_128 -> V_138 , F_75 ( & V_128 -> V_90 -> V_139 ) ) ;
V_17 -> V_102 = F_53 ;
F_76 ( & V_128 -> V_90 -> V_139 ) ;
V_17 -> V_90 = V_128 -> V_90 ;
V_17 -> V_140 = V_132 ;
V_134 = F_77 ( V_12 , V_131 ) ;
if ( V_134 )
V_17 -> args . V_134 = V_134 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_78 ( V_130 , V_17 ,
& V_146 , V_145 ,
V_143 ) ;
return V_144 ;
}
static int
F_80 ( struct V_29 * V_30 ,
struct V_1 * V_147 ,
struct V_148 * V_149 ,
struct V_150 * V_151 ,
T_4 V_152 )
{
struct V_41 * V_153 ;
struct V_154 * V_6 ;
int V_155 = - V_156 ;
F_9 ( L_14 , V_22 ) ;
if ( V_149 -> V_157 . V_3 != 0 ||
V_149 -> V_157 . V_158 != V_159 ) {
F_9 ( L_15 ,
V_22 ) ;
goto V_83;
}
if ( V_147 -> V_10 > V_149 -> V_157 . V_3 ) {
F_9 ( L_16 ,
V_22 , V_147 -> V_10 ) ;
goto V_83;
}
if ( ! V_147 -> V_5 ) {
F_9 ( L_17 ,
V_22 , V_147 -> V_5 ) ;
goto V_83;
}
V_153 = F_81 ( F_18 ( V_30 -> V_38 ) -> V_160 ,
F_18 ( V_30 -> V_38 ) -> V_35 , V_151 ) ;
if ( V_153 == NULL ) {
V_6 = F_82 ( V_30 -> V_38 , V_151 ,
V_30 -> V_161 , V_152 ) ;
if ( V_6 == NULL )
goto V_83;
} else
V_6 = F_83 ( V_153 , struct V_154 , V_162 ) ;
if ( F_38 ( & V_6 -> V_162 ) )
goto V_163;
V_147 -> V_6 = V_6 ;
if ( V_147 -> V_164 >= V_6 -> V_7 ) {
F_9 ( L_18 ,
V_22 , V_147 -> V_164 ) ;
goto V_163;
}
if ( ( V_147 -> V_13 == V_14 &&
V_147 -> V_165 > 1 && V_147 -> V_165 != V_6 -> V_166 ) ||
( V_147 -> V_13 == V_15 &&
V_147 -> V_165 != V_6 -> V_7 ) ) {
F_9 ( L_19 ,
V_22 , V_147 -> V_165 ) ;
goto V_163;
}
V_155 = 0 ;
V_83:
F_9 ( L_20 , V_22 , V_155 ) ;
return V_155 ;
V_163:
F_84 ( V_6 ) ;
goto V_83;
}
static void F_85 ( struct V_1 * V_147 )
{
int V_167 ;
for ( V_167 = 0 ; V_167 < V_147 -> V_165 ; V_167 ++ ) {
if ( ! V_147 -> V_168 [ V_167 ] )
break;
F_86 ( V_147 -> V_168 [ V_167 ] ) ;
}
F_86 ( V_147 -> V_168 ) ;
V_147 -> V_168 = NULL ;
}
static void
F_87 ( struct V_1 * V_147 )
{
F_85 ( V_147 ) ;
F_86 ( V_147 ) ;
}
static int
F_88 ( struct V_29 * V_169 ,
struct V_1 * V_147 ,
struct V_148 * V_149 ,
struct V_150 * V_151 ,
T_4 V_152 )
{
struct V_170 V_171 ;
struct V_172 V_173 ;
struct V_174 * V_175 ;
T_5 * V_176 ;
T_6 V_177 ;
int V_167 ;
F_9 ( L_21 , V_22 ) ;
V_175 = F_89 ( V_152 ) ;
if ( ! V_175 )
return - V_178 ;
F_90 ( & V_171 , & V_173 , V_149 -> V_179 -> V_116 , V_149 -> V_179 -> V_180 ) ;
F_91 ( & V_171 , F_92 ( V_175 ) , V_181 ) ;
V_176 = F_93 ( & V_171 , V_182 + 20 ) ;
if ( F_43 ( ! V_176 ) )
goto V_183;
memcpy ( V_151 , V_176 , sizeof( * V_151 ) ) ;
V_176 += F_94 ( V_182 ) ;
F_95 ( V_151 ) ;
V_177 = F_96 ( V_176 ++ ) ;
if ( V_177 & V_184 )
V_147 -> V_91 = 1 ;
if ( V_177 & V_185 )
V_147 -> V_13 = V_15 ;
else
V_147 -> V_13 = V_14 ;
V_147 -> V_5 = V_177 & ~ V_186 ;
V_147 -> V_164 = F_96 ( V_176 ++ ) ;
V_176 = F_97 ( V_176 , & V_147 -> V_10 ) ;
V_147 -> V_165 = F_96 ( V_176 ++ ) ;
F_9 ( L_22 ,
V_22 , V_177 , V_147 -> V_165 , V_147 -> V_164 ,
V_147 -> V_10 ) ;
if ( V_147 -> V_165 >
F_98 ( V_187 , V_188 ) )
goto V_183;
if ( V_147 -> V_165 > 0 ) {
V_147 -> V_168 = F_99 ( V_147 -> V_165 , sizeof( V_147 -> V_168 [ 0 ] ) ,
V_152 ) ;
if ( ! V_147 -> V_168 )
goto V_183;
}
for ( V_167 = 0 ; V_167 < V_147 -> V_165 ; V_167 ++ ) {
V_147 -> V_168 [ V_167 ] = F_100 ( sizeof( struct V_133 ) , V_152 ) ;
if ( ! V_147 -> V_168 [ V_167 ] )
goto V_189;
V_176 = F_93 ( & V_171 , 4 ) ;
if ( F_43 ( ! V_176 ) )
goto V_189;
V_147 -> V_168 [ V_167 ] -> V_190 = F_96 ( V_176 ++ ) ;
if ( sizeof( struct V_133 ) < V_147 -> V_168 [ V_167 ] -> V_190 ) {
F_101 ( V_191 L_23 ,
V_167 , V_147 -> V_168 [ V_167 ] -> V_190 ) ;
goto V_189;
}
V_176 = F_93 ( & V_171 , V_147 -> V_168 [ V_167 ] -> V_190 ) ;
if ( F_43 ( ! V_176 ) )
goto V_189;
memcpy ( V_147 -> V_168 [ V_167 ] -> V_100 , V_176 , V_147 -> V_168 [ V_167 ] -> V_190 ) ;
F_9 ( L_24 , V_22 ,
V_147 -> V_168 [ V_167 ] -> V_190 ) ;
}
F_102 ( V_175 ) ;
return 0 ;
V_189:
F_85 ( V_147 ) ;
V_183:
F_102 ( V_175 ) ;
return - V_79 ;
}
static void
F_103 ( struct V_11 * V_12 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
F_9 ( L_14 , V_22 ) ;
F_84 ( V_147 -> V_6 ) ;
if ( V_12 -> V_192 . V_193 == V_194 ) {
struct V_195 * V_169 ;
V_169 = F_104 ( V_12 -> V_37 ) ;
V_169 -> V_196 . V_197 = 0 ;
F_86 ( V_169 -> V_196 . V_198 ) ;
V_169 -> V_196 . V_198 = NULL ;
}
F_87 ( V_147 ) ;
}
static int
F_105 ( struct V_11 * V_12 ,
struct V_199 * V_200 ,
T_4 V_152 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
struct V_201 * V_198 ;
int V_190 , V_167 ;
if ( V_147 -> V_91 )
return 0 ;
V_190 = ( V_147 -> V_13 == V_14 ) ?
V_147 -> V_6 -> V_166 : V_147 -> V_6 -> V_7 ;
if ( V_200 -> V_128 -> V_197 >= V_190 ) {
return 0 ;
}
V_198 = F_99 ( V_190 , sizeof( struct V_201 ) ,
V_152 ) ;
if ( ! V_198 )
return - V_178 ;
for ( V_167 = 0 ; V_167 < V_190 ; V_167 ++ ) {
F_106 ( & V_198 [ V_167 ] . V_202 ) ;
F_106 ( & V_198 [ V_167 ] . V_203 ) ;
V_198 [ V_167 ] . V_204 . V_94 = V_205 ;
}
F_107 ( V_200 -> V_206 ) ;
if ( V_200 -> V_128 -> V_197 >= V_190 )
goto V_83;
for ( V_167 = 0 ; V_167 < V_200 -> V_128 -> V_197 ; V_167 ++ ) {
F_108 ( & V_200 -> V_128 -> V_198 [ V_167 ] . V_202 ,
& V_198 [ V_167 ] . V_202 ) ;
F_108 ( & V_200 -> V_128 -> V_198 [ V_167 ] . V_203 ,
& V_198 [ V_167 ] . V_203 ) ;
V_198 [ V_167 ] . V_204 . V_94 =
V_200 -> V_128 -> V_198 [ V_167 ] . V_204 . V_94 ;
V_198 [ V_167 ] . V_207 = V_200 -> V_128 -> V_198 [ V_167 ] . V_207 ;
V_198 [ V_167 ] . V_208 = V_200 -> V_128 -> V_198 [ V_167 ] . V_208 ;
}
F_109 ( V_200 -> V_128 -> V_198 , V_198 ) ;
V_200 -> V_128 -> V_197 = V_190 ;
V_83:
F_110 ( V_200 -> V_206 ) ;
F_86 ( V_198 ) ;
return 0 ;
}
static struct V_11 *
F_111 ( struct V_29 * V_209 ,
struct V_148 * V_149 ,
T_4 V_152 )
{
struct V_1 * V_147 ;
int V_210 ;
struct V_150 V_151 ;
F_9 ( L_14 , V_22 ) ;
V_147 = F_112 ( sizeof( * V_147 ) , V_152 ) ;
if ( ! V_147 )
return NULL ;
V_210 = F_88 ( V_209 , V_147 , V_149 , & V_151 , V_152 ) ;
if ( V_210 != 0 || F_80 ( V_209 , V_147 , V_149 , & V_151 , V_152 ) ) {
F_87 ( V_147 ) ;
return NULL ;
}
return & V_147 -> V_211 ;
}
static V_136
F_113 ( struct V_212 * V_213 , struct V_114 * V_214 ,
struct V_114 * V_215 )
{
unsigned int V_190 ;
T_3 V_216 , V_217 ;
T_2 V_218 ;
T_3 V_219 = V_213 -> V_220 -> V_192 . V_3 ;
T_2 V_5 = F_5 ( V_213 -> V_220 ) -> V_5 ;
V_190 = F_114 ( V_213 , V_214 , V_215 ) ;
if ( ! V_190 )
return 0 ;
if ( V_214 ) {
V_216 = ( T_3 ) F_115 ( V_214 ) - V_219 ;
V_217 = ( T_3 ) F_115 ( V_215 ) - V_219 ;
F_116 ( V_216 , V_5 ) ;
F_116 ( V_217 , V_5 ) ;
if ( V_216 != V_217 )
return 0 ;
}
F_3 ( ( T_3 ) F_115 ( V_215 ) - V_219 ,
V_5 ,
& V_218 ) ;
F_117 ( V_218 > V_5 ) ;
if ( V_218 >= V_5 )
return 0 ;
return F_118 ( V_5 - ( unsigned int ) V_218 , V_190 ) ;
}
static void
F_119 ( struct V_212 * V_213 ,
struct V_114 * V_215 )
{
if ( ! V_213 -> V_220 )
V_213 -> V_220 = F_120 ( V_213 -> V_221 ,
V_215 -> V_222 ,
0 ,
V_159 ,
V_223 ,
V_224 ) ;
if ( V_213 -> V_220 == NULL )
F_121 ( V_213 ) ;
}
static void
F_122 ( struct V_212 * V_213 ,
struct V_114 * V_215 )
{
struct V_199 V_200 ;
int V_155 ;
if ( ! V_213 -> V_220 )
V_213 -> V_220 = F_120 ( V_213 -> V_221 ,
V_215 -> V_222 ,
0 ,
V_159 ,
V_194 ,
V_225 ) ;
if ( V_213 -> V_220 == NULL )
goto V_226;
F_123 ( & V_200 , V_213 -> V_221 , V_213 -> V_227 ) ;
V_155 = F_105 ( V_213 -> V_220 , & V_200 , V_225 ) ;
if ( V_155 < 0 ) {
F_67 ( V_213 -> V_220 ) ;
V_213 -> V_220 = NULL ;
goto V_226;
}
return;
V_226:
F_124 ( V_213 ) ;
}
static T_2 F_125 ( struct V_1 * V_147 , T_2 V_131 )
{
if ( V_147 -> V_13 == V_14 )
return F_71 ( & V_147 -> V_211 , V_131 ) ;
else
return V_131 ;
}
static void
F_126 ( struct V_114 * V_215 ,
struct V_199 * V_200 )
{
struct V_11 * V_228 = NULL ;
if ( ! F_15 ( V_229 , & V_215 -> V_230 ) )
goto V_83;
V_200 -> V_128 -> V_231 -- ;
if ( F_127 ( & V_215 -> V_232 ) ) {
struct V_201 * V_233 ;
V_233 = F_128 ( & V_215 -> V_232 ,
struct V_201 ,
V_202 ) ;
V_228 = V_233 -> V_207 ;
V_233 -> V_207 = NULL ;
}
V_83:
F_129 ( V_215 , V_200 ) ;
F_130 ( V_228 ) ;
}
static void
F_131 ( struct V_114 * V_215 ,
struct V_11 * V_12 ,
struct V_199 * V_200 )
{
struct V_1 * V_147 = F_5 ( V_12 ) ;
T_2 V_167 , V_131 ;
struct V_234 * V_235 ;
struct V_201 * V_198 ;
if ( V_147 -> V_91 ) {
V_235 = & V_200 -> V_236 -> V_235 ;
F_107 ( V_200 -> V_206 ) ;
goto V_237;
}
V_131 = F_70 ( V_12 , F_115 ( V_215 ) ) ;
V_167 = F_125 ( V_147 , V_131 ) ;
F_107 ( V_200 -> V_206 ) ;
V_198 = V_200 -> V_128 -> V_198 ;
V_235 = & V_198 [ V_167 ] . V_202 ;
if ( F_132 ( V_235 ) ) {
V_198 [ V_167 ] . V_207 = F_133 ( V_12 ) ;
}
F_29 ( V_229 , & V_215 -> V_230 ) ;
V_200 -> V_128 -> V_231 ++ ;
V_237:
F_29 ( V_238 , & ( V_215 ) -> V_230 ) ;
F_134 ( V_215 , V_235 ) ;
V_200 -> V_236 -> V_239 ++ ;
F_110 ( V_200 -> V_206 ) ;
if ( ! V_200 -> V_240 ) {
F_135 ( V_215 -> V_241 , V_242 ) ;
F_136 ( F_137 ( V_215 -> V_241 ) -> V_243 ,
V_244 ) ;
F_138 ( V_215 -> V_222 -> V_245 -> V_246 ,
V_247 ) ;
}
}
static T_2 F_139 ( struct V_11 * V_12 , T_2 V_167 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_167 ;
else
return F_71 ( V_12 , V_167 ) ;
}
static struct V_133 *
F_140 ( struct V_11 * V_12 , T_2 V_167 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_165 == 1 )
V_167 = 0 ;
else if ( V_2 -> V_165 == 0 )
return NULL ;
}
return V_2 -> V_168 [ V_167 ] ;
}
static int F_141 ( struct V_113 * V_100 , int V_248 )
{
struct V_11 * V_12 = V_100 -> V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
T_2 V_132 ;
struct V_133 * V_134 ;
V_132 = F_139 ( V_12 , V_100 -> V_249 ) ;
V_128 = F_72 ( V_12 , V_132 ) ;
if ( ! V_128 )
goto V_183;
V_130 = F_73 ( V_128 -> V_90 , V_100 -> V_24 ) ;
if ( F_74 ( V_130 ) )
goto V_183;
F_9 ( L_25 , V_22 ,
V_100 -> V_24 -> V_96 , V_248 , F_75 ( & V_128 -> V_90 -> V_139 ) ) ;
V_100 -> V_250 = F_57 ;
F_76 ( & V_128 -> V_90 -> V_139 ) ;
V_100 -> V_90 = V_128 -> V_90 ;
V_134 = F_140 ( V_12 , V_100 -> V_249 ) ;
if ( V_134 )
V_100 -> args . V_134 = V_134 ;
return F_142 ( V_130 , V_100 ,
& V_251 , V_248 ,
V_143 ) ;
V_183:
F_55 ( V_100 ) ;
F_66 ( V_100 ) ;
return - V_84 ;
}
static int
F_143 ( struct V_234 * V_252 , struct V_234 * V_253 ,
struct V_199 * V_200 , int F_98 )
{
struct V_114 * V_215 , * V_254 ;
int V_255 = 0 ;
F_144 (req, tmp, src, wb_list) {
if ( ! F_145 ( V_215 ) )
continue;
F_146 ( & V_215 -> V_256 ) ;
if ( F_147 ( V_200 -> V_206 ) )
F_148 ( V_215 , V_254 , V_232 ) ;
F_129 ( V_215 , V_200 ) ;
F_149 ( V_229 , & V_215 -> V_230 ) ;
F_134 ( V_215 , V_253 ) ;
V_255 ++ ;
if ( ( V_255 == F_98 ) && ! V_200 -> V_240 )
break;
}
return V_255 ;
}
static int
F_150 ( struct V_201 * V_233 ,
struct V_199 * V_200 ,
int F_98 )
{
struct V_234 * V_252 = & V_233 -> V_202 ;
struct V_234 * V_253 = & V_233 -> V_203 ;
int V_255 ;
V_255 = F_143 ( V_252 , V_253 , V_200 , F_98 ) ;
if ( V_255 ) {
V_200 -> V_128 -> V_231 -= V_255 ;
V_200 -> V_128 -> V_257 += V_255 ;
V_233 -> V_208 = V_233 -> V_207 ;
if ( F_132 ( V_252 ) )
V_233 -> V_207 = NULL ;
else
F_133 ( V_233 -> V_208 ) ;
}
return V_255 ;
}
static int F_151 ( struct V_199 * V_200 ,
int F_98 )
{
int V_167 , V_258 = 0 , V_259 ;
for ( V_167 = 0 ; V_167 < V_200 -> V_128 -> V_197 && F_98 != 0 ; V_167 ++ ) {
V_259 = F_150 ( & V_200 -> V_128 -> V_198 [ V_167 ] ,
V_200 , F_98 ) ;
F_98 -= V_259 ;
V_258 += V_259 ;
}
return V_258 ;
}
static void F_152 ( struct V_234 * V_253 ,
struct V_199 * V_200 )
{
struct V_201 * V_260 ;
struct V_11 * V_228 ;
int V_167 ;
V_261:
F_107 ( V_200 -> V_206 ) ;
for ( V_167 = 0 , V_260 = V_200 -> V_128 -> V_198 ; V_167 < V_200 -> V_128 -> V_197 ; V_167 ++ , V_260 ++ ) {
if ( F_143 ( & V_260 -> V_202 , V_253 , V_200 , 0 ) ) {
V_228 = V_260 -> V_207 ;
V_260 -> V_207 = NULL ;
F_110 ( V_200 -> V_206 ) ;
F_67 ( V_228 ) ;
goto V_261;
}
}
V_200 -> V_128 -> V_231 = 0 ;
F_110 ( V_200 -> V_206 ) ;
}
static struct V_114 *
F_153 ( struct V_199 * V_200 , struct V_174 * V_174 )
{
struct V_114 * V_262 , * V_263 ;
struct V_201 * V_260 ;
int V_167 ;
for ( V_167 = 0 , V_260 = V_200 -> V_128 -> V_198 ; V_167 < V_200 -> V_128 -> V_197 ; V_167 ++ , V_260 ++ ) {
F_144 (freq, t, &b->written, wb_list) {
if ( V_262 -> V_241 == V_174 )
return V_262 -> V_264 ;
}
F_144 (freq, t, &b->committing, wb_list) {
if ( V_262 -> V_241 == V_174 )
return V_262 -> V_264 ;
}
}
return NULL ;
}
static void F_154 ( struct V_199 * V_200 , int V_132 )
{
struct V_265 * V_266 = V_200 -> V_128 ;
struct V_201 * V_233 ;
struct V_11 * V_228 ;
int V_167 ;
for ( V_167 = V_132 ; V_167 < V_266 -> V_197 ; V_167 ++ ) {
V_233 = & V_266 -> V_198 [ V_167 ] ;
if ( F_132 ( & V_233 -> V_203 ) )
continue;
F_155 ( & V_233 -> V_203 , V_233 -> V_208 , V_200 ) ;
F_107 ( V_200 -> V_206 ) ;
V_228 = V_233 -> V_208 ;
V_233 -> V_208 = NULL ;
F_110 ( V_200 -> V_206 ) ;
F_67 ( V_228 ) ;
}
}
static unsigned int
F_156 ( struct V_199 * V_200 , struct V_234 * V_235 )
{
struct V_265 * V_266 ;
struct V_201 * V_233 ;
struct V_113 * V_100 ;
int V_167 ;
unsigned int V_267 = 0 ;
V_266 = V_200 -> V_128 ;
V_233 = V_266 -> V_198 ;
for ( V_167 = 0 ; V_167 < V_266 -> V_197 ; V_167 ++ , V_233 ++ ) {
if ( F_132 ( & V_233 -> V_203 ) )
continue;
V_100 = F_157 () ;
if ( ! V_100 )
break;
V_100 -> V_249 = V_167 ;
F_107 ( V_200 -> V_206 ) ;
V_100 -> V_12 = V_233 -> V_208 ;
V_233 -> V_208 = NULL ;
F_110 ( V_200 -> V_206 ) ;
F_158 ( & V_100 -> V_116 , V_235 ) ;
V_267 ++ ;
}
F_154 ( V_200 , V_167 ) ;
return V_267 ;
}
static int
F_159 ( struct V_24 * V_24 , struct V_234 * V_268 ,
int V_248 , struct V_199 * V_200 )
{
struct V_113 * V_100 , * V_254 ;
F_160 ( V_235 ) ;
unsigned int V_267 = 0 ;
if ( ! F_132 ( V_268 ) ) {
V_100 = F_157 () ;
if ( V_100 != NULL ) {
V_100 -> V_12 = NULL ;
F_158 ( & V_100 -> V_116 , & V_235 ) ;
V_267 ++ ;
} else {
F_155 ( V_268 , NULL , V_200 ) ;
F_154 ( V_200 , 0 ) ;
V_200 -> V_124 -> V_269 ( F_26 ( V_24 ) ) ;
return - V_178 ;
}
}
V_267 += F_156 ( V_200 , & V_235 ) ;
if ( V_267 == 0 ) {
V_200 -> V_124 -> V_269 ( F_26 ( V_24 ) ) ;
goto V_83;
}
F_161 ( V_267 , & V_200 -> V_236 -> V_270 ) ;
F_144 (data, tmp, &list, pages) {
F_162 ( & V_100 -> V_116 ) ;
if ( ! V_100 -> V_12 ) {
F_163 ( V_100 , V_268 , NULL , V_200 ) ;
F_142 ( F_164 ( V_24 ) , V_100 ,
V_100 -> V_108 , V_248 , 0 ) ;
} else {
struct V_201 * V_198 ;
V_198 = V_200 -> V_128 -> V_198 ;
F_163 ( V_100 , & V_198 [ V_100 -> V_249 ] . V_203 , V_100 -> V_12 , V_200 ) ;
F_141 ( V_100 , V_248 ) ;
}
}
V_83:
V_200 -> V_128 -> V_257 = 0 ;
return V_144 ;
}
static void
F_165 ( struct V_41 * V_153 )
{
F_166 ( F_83 ( V_153 , struct V_154 , V_162 ) ) ;
}
static struct V_29 *
F_167 ( struct V_24 * V_24 , T_4 V_152 )
{
struct V_195 * V_169 ;
V_169 = F_112 ( sizeof( * V_169 ) , V_152 ) ;
return V_169 != NULL ? & V_169 -> V_211 : NULL ;
}
static void
F_168 ( struct V_29 * V_30 )
{
F_86 ( F_104 ( V_30 ) ) ;
}
static struct V_265 *
F_169 ( struct V_24 * V_24 )
{
struct V_29 * V_97 = F_26 ( V_24 ) -> V_97 ;
if ( V_97 == NULL )
return NULL ;
else
return & F_104 ( V_97 ) -> V_196 ;
}
static int T_7 F_170 ( void )
{
F_101 ( V_271 L_26 ,
V_22 ) ;
return F_171 ( & V_272 ) ;
}
static void T_8 F_172 ( void )
{
F_101 ( V_271 L_27 ,
V_22 ) ;
F_173 ( & V_272 ) ;
}
