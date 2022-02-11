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
struct V_37 * V_38 = F_15 ( V_12 ) ;
struct V_39 * V_40 = & V_32 -> V_41 -> V_42 ;
if ( V_19 -> V_28 >= 0 )
return 0 ;
switch ( V_19 -> V_28 ) {
case - V_43 :
case - V_44 :
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
F_9 ( L_3
L_4 , V_22 , V_19 -> V_28 ,
V_32 -> V_50 ) ;
F_16 ( V_32 -> V_41 , V_19 -> V_28 ) ;
break;
case - V_51 :
case - V_52 :
F_17 ( V_19 , V_53 ) ;
break;
case - V_54 :
break;
case - V_55 :
case - V_56 :
case - V_57 :
case - V_58 :
case - V_59 :
case - V_60 :
case - V_61 :
F_9 ( L_5 , V_22 ,
V_19 -> V_28 ) ;
F_18 ( F_19 ( V_24 ) ) ;
F_20 ( & V_40 -> V_62 ) ;
goto V_63;
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_9 ( L_6 , V_22 ,
V_19 -> V_28 ) ;
F_21 ( V_38 ) ;
F_22 ( V_24 , V_12 ) ;
F_23 ( V_12 ) ;
F_20 ( & V_40 -> V_62 ) ;
default:
V_63:
F_9 ( L_7 , V_22 ,
V_19 -> V_28 ) ;
return - V_71 ;
}
V_19 -> V_28 = 0 ;
return - V_72 ;
}
static int F_24 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_73 ;
F_25 ( V_17 , V_19 -> V_28 ) ;
V_73 = F_14 ( V_19 , V_17 -> args . V_74 -> V_30 ,
V_17 -> V_75 , V_17 -> V_12 ) ;
switch ( V_73 ) {
case - V_71 :
F_12 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_72 :
F_26 ( V_19 ) ;
return - V_72 ;
}
return 0 ;
}
static void
F_27 ( struct V_16 * V_17 )
{
T_1 V_76 = 0 ;
if ( F_5 ( V_17 -> V_12 ) -> V_77 ||
V_17 -> V_78 . V_79 -> V_80 == V_81 )
return;
if ( V_17 -> V_78 . V_79 -> V_80 == V_82 )
V_76 = V_17 -> V_83 + ( T_1 ) V_17 -> V_78 . V_27 ;
F_28 ( V_17 -> V_24 , V_17 -> V_12 , V_76 ) ;
F_9 ( L_8 , V_22 , V_17 -> V_24 -> V_84 ,
( unsigned long ) F_19 ( V_17 -> V_24 ) -> V_85 -> V_86 ) ;
}
bool
F_29 ( struct V_37 * V_87 )
{
return F_30 ( V_87 ) ||
F_31 ( V_87 ) ;
}
static bool
F_32 ( struct V_11 * V_12 )
{
struct V_37 * V_87 = F_15 ( V_12 ) ;
return F_29 ( V_87 ) ;
}
static void F_33 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
if ( F_34 ( F_35 ( V_89 , & V_17 -> args . V_74 -> V_21 ) ) ) {
F_36 ( V_19 , - V_68 ) ;
return;
}
if ( F_32 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_12 ( V_17 ) ;
F_36 ( V_19 , 0 ) ;
return;
}
V_17 -> V_90 = F_24 ;
if ( F_37 ( V_17 -> V_75 ,
& V_17 -> args . V_91 ,
& V_17 -> V_78 . V_92 ,
V_19 ) )
return;
if ( F_38 ( & V_17 -> args . V_93 , V_17 -> args . V_74 ,
V_17 -> args . V_94 , V_95 ) == - V_68 )
F_36 ( V_19 , - V_68 ) ;
}
static void F_39 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
F_9 ( L_10 , V_22 , V_19 -> V_28 ) ;
if ( F_35 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_40 ( V_19 , & V_17 -> V_78 . V_92 ) ;
return;
}
V_17 -> V_96 -> V_97 ( V_19 , V_88 ) ;
}
static void F_41 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
F_42 ( V_19 , F_43 ( V_17 -> V_24 ) -> V_98 -> V_99 ) ;
}
static int F_44 ( struct V_18 * V_19 ,
struct V_16 * V_17 )
{
int V_73 ;
F_45 ( V_17 , V_19 -> V_28 ) ;
V_73 = F_14 ( V_19 , V_17 -> args . V_74 -> V_30 ,
V_17 -> V_75 , V_17 -> V_12 ) ;
switch ( V_73 ) {
case - V_71 :
F_7 ( V_17 ) ;
return V_19 -> V_28 ;
case - V_72 :
F_26 ( V_19 ) ;
return - V_72 ;
}
F_27 ( V_17 ) ;
V_17 -> V_100 . V_101 = 0 ;
if ( V_19 -> V_28 >= 0 )
F_46 ( V_17 ) ;
return 0 ;
}
static int F_47 ( struct V_18 * V_19 ,
struct V_102 * V_88 )
{
int V_73 ;
F_48 ( V_88 , V_19 -> V_28 ) ;
V_73 = F_14 ( V_19 , NULL , V_88 -> V_75 ,
V_88 -> V_12 ) ;
switch ( V_73 ) {
case - V_71 :
F_49 ( V_88 ) ;
return - V_72 ;
case - V_72 :
F_26 ( V_19 ) ;
return - V_72 ;
}
F_28 ( V_88 -> V_24 , V_88 -> V_12 , V_88 -> V_103 ) ;
return 0 ;
}
static void F_50 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
if ( F_34 ( F_35 ( V_89 , & V_17 -> args . V_74 -> V_21 ) ) ) {
F_36 ( V_19 , - V_68 ) ;
return;
}
if ( F_32 ( V_17 -> V_12 ) ) {
F_9 ( L_9 , V_22 , V_19 -> V_23 ) ;
F_7 ( V_17 ) ;
F_36 ( V_19 , 0 ) ;
return;
}
if ( F_37 ( V_17 -> V_75 ,
& V_17 -> args . V_91 ,
& V_17 -> V_78 . V_92 ,
V_19 ) )
return;
if ( F_38 ( & V_17 -> args . V_93 , V_17 -> args . V_74 ,
V_17 -> args . V_94 , V_104 ) == - V_68 )
F_36 ( V_19 , - V_68 ) ;
}
static void F_51 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
if ( F_35 ( V_20 , & V_17 -> V_21 ) &&
V_19 -> V_28 == 0 ) {
F_40 ( V_19 , & V_17 -> V_78 . V_92 ) ;
return;
}
V_17 -> V_96 -> V_97 ( V_19 , V_88 ) ;
}
static void F_52 ( struct V_18 * V_19 , void * V_88 )
{
struct V_16 * V_17 = V_88 ;
F_42 ( V_19 , F_43 ( V_17 -> V_24 ) -> V_98 -> V_99 ) ;
}
static void F_53 ( struct V_18 * V_19 , void * V_88 )
{
struct V_102 * V_105 = V_88 ;
F_37 ( V_105 -> V_75 ,
& V_105 -> args . V_91 ,
& V_105 -> V_78 . V_92 ,
V_19 ) ;
}
static void F_54 ( struct V_18 * V_19 , void * V_88 )
{
struct V_102 * V_106 = V_88 ;
F_42 ( V_19 , F_43 ( V_106 -> V_24 ) -> V_98 -> V_99 ) ;
}
static enum V_107
F_55 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_112 , V_113 ;
struct V_114 * V_115 ;
F_9 ( L_11 ,
V_22 , V_17 -> V_24 -> V_84 ,
V_17 -> args . V_116 , ( V_117 ) V_17 -> args . V_27 , V_3 ) ;
V_112 = F_56 ( V_12 , V_3 ) ;
V_113 = F_57 ( V_12 , V_112 ) ;
V_109 = F_58 ( V_12 , V_113 ) ;
if ( ! V_109 )
return V_118 ;
V_111 = F_59 ( V_109 -> V_75 , V_17 -> V_24 ) ;
if ( F_60 ( V_111 ) )
return V_118 ;
F_9 ( L_12 , V_22 ,
V_109 -> V_119 , F_61 ( & V_109 -> V_75 -> V_120 ) ) ;
F_62 ( & V_109 -> V_75 -> V_120 ) ;
V_17 -> V_75 = V_109 -> V_75 ;
V_17 -> V_121 = V_113 ;
V_115 = F_63 ( V_12 , V_112 ) ;
if ( V_115 )
V_17 -> args . V_115 = V_115 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
V_17 -> V_83 = V_3 ;
F_64 ( V_111 , V_17 , V_17 -> V_122 ,
F_65 ( V_17 -> V_24 ) , & V_123 ,
0 , V_124 ) ;
return V_125 ;
}
static enum V_107
F_66 ( struct V_16 * V_17 , int V_126 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
T_1 V_3 = V_17 -> args . V_3 ;
T_2 V_112 , V_113 ;
struct V_114 * V_115 ;
V_112 = F_56 ( V_12 , V_3 ) ;
V_113 = F_57 ( V_12 , V_112 ) ;
V_109 = F_58 ( V_12 , V_113 ) ;
if ( ! V_109 )
return V_118 ;
V_111 = F_59 ( V_109 -> V_75 , V_17 -> V_24 ) ;
if ( F_60 ( V_111 ) )
return V_118 ;
F_9 ( L_13 ,
V_22 , V_17 -> V_24 -> V_84 , V_126 , ( V_117 ) V_17 -> args . V_27 ,
V_3 , V_109 -> V_119 , F_61 ( & V_109 -> V_75 -> V_120 ) ) ;
V_17 -> V_90 = F_44 ;
F_62 ( & V_109 -> V_75 -> V_120 ) ;
V_17 -> V_75 = V_109 -> V_75 ;
V_17 -> V_121 = V_113 ;
V_115 = F_63 ( V_12 , V_112 ) ;
if ( V_115 )
V_17 -> args . V_115 = V_115 ;
V_17 -> args . V_3 = F_4 ( V_12 , V_3 ) ;
F_64 ( V_111 , V_17 , V_17 -> V_122 ,
F_65 ( V_17 -> V_24 ) , & V_127 ,
V_126 , V_124 ) ;
return V_125 ;
}
static int
F_67 ( struct V_33 * V_34 ,
struct V_1 * V_128 ,
T_4 V_129 )
{
struct V_37 * V_130 ;
struct V_131 * V_6 ;
int V_132 = - V_133 ;
if ( V_128 -> V_6 != NULL )
return 0 ;
V_130 = F_68 ( F_43 ( V_34 -> V_36 ) , & V_128 -> V_134 ,
V_34 -> V_135 , V_129 ) ;
if ( V_130 == NULL )
goto V_136;
V_6 = F_69 ( V_130 , struct V_131 , V_137 ) ;
if ( F_29 ( & V_6 -> V_137 ) )
goto V_138;
if ( V_128 -> V_139 >= V_6 -> V_7 ) {
F_9 ( L_14 ,
V_22 , V_128 -> V_139 ) ;
goto V_138;
}
if ( ( V_128 -> V_13 == V_14 &&
V_128 -> V_140 > 1 && V_128 -> V_140 != V_6 -> V_141 ) ||
( V_128 -> V_13 == V_15 &&
V_128 -> V_140 != V_6 -> V_7 ) ) {
F_9 ( L_15 ,
V_22 , V_128 -> V_140 ) ;
goto V_138;
}
V_132 = 0 ;
if ( F_70 ( & V_128 -> V_6 , NULL , V_6 ) != NULL )
goto V_138;
V_136:
return V_132 ;
V_138:
F_71 ( V_6 ) ;
goto V_136;
}
static int
F_72 ( struct V_33 * V_34 ,
struct V_1 * V_128 ,
struct V_142 * V_143 ,
T_4 V_129 )
{
int V_132 = - V_133 ;
F_9 ( L_16 , V_22 ) ;
if ( V_143 -> V_144 . V_3 != 0 ||
V_143 -> V_144 . V_145 != V_146 ) {
F_9 ( L_17 ,
V_22 ) ;
goto V_136;
}
if ( V_128 -> V_10 > V_143 -> V_144 . V_3 ) {
F_9 ( L_18 ,
V_22 , V_128 -> V_10 ) ;
goto V_136;
}
if ( ! V_128 -> V_5 ) {
F_9 ( L_19 ,
V_22 , V_128 -> V_5 ) ;
goto V_136;
}
V_132 = 0 ;
V_136:
F_9 ( L_20 , V_22 , V_132 ) ;
return V_132 ;
}
static void F_73 ( struct V_1 * V_128 )
{
int V_147 ;
if ( V_128 -> V_148 ) {
for ( V_147 = 0 ; V_147 < V_128 -> V_140 ; V_147 ++ ) {
if ( ! V_128 -> V_148 [ V_147 ] )
break;
F_74 ( V_128 -> V_148 [ V_147 ] ) ;
}
F_74 ( V_128 -> V_148 ) ;
}
F_74 ( V_128 ) ;
}
static int
F_75 ( struct V_33 * V_149 ,
struct V_1 * V_128 ,
struct V_142 * V_143 ,
T_4 V_129 )
{
struct V_150 V_151 ;
struct V_152 V_153 ;
struct V_154 * V_155 ;
T_5 * V_156 ;
T_6 V_157 ;
int V_147 ;
F_9 ( L_21 , V_22 ) ;
V_155 = F_76 ( V_129 ) ;
if ( ! V_155 )
return - V_158 ;
F_77 ( & V_151 , & V_153 , V_143 -> V_159 -> V_160 , V_143 -> V_159 -> V_161 ) ;
F_78 ( & V_151 , F_79 ( V_155 ) , V_162 ) ;
V_156 = F_80 ( & V_151 , V_163 + 20 ) ;
if ( F_34 ( ! V_156 ) )
goto V_164;
memcpy ( & V_128 -> V_134 , V_156 , sizeof( V_128 -> V_134 ) ) ;
V_156 += F_81 ( V_163 ) ;
F_82 ( & V_128 -> V_134 ) ;
V_157 = F_83 ( V_156 ++ ) ;
if ( V_157 & V_165 )
V_128 -> V_77 = 1 ;
if ( V_157 & V_166 )
V_128 -> V_13 = V_15 ;
else
V_128 -> V_13 = V_14 ;
V_128 -> V_5 = V_157 & ~ V_167 ;
V_128 -> V_139 = F_83 ( V_156 ++ ) ;
V_156 = F_84 ( V_156 , & V_128 -> V_10 ) ;
V_128 -> V_140 = F_83 ( V_156 ++ ) ;
F_9 ( L_22 ,
V_22 , V_157 , V_128 -> V_140 , V_128 -> V_139 ,
V_128 -> V_10 ) ;
if ( V_128 -> V_140 >
F_85 ( V_168 , V_169 ) )
goto V_164;
if ( V_128 -> V_140 > 0 ) {
V_128 -> V_148 = F_86 ( V_128 -> V_140 , sizeof( V_128 -> V_148 [ 0 ] ) ,
V_129 ) ;
if ( ! V_128 -> V_148 )
goto V_164;
}
for ( V_147 = 0 ; V_147 < V_128 -> V_140 ; V_147 ++ ) {
V_128 -> V_148 [ V_147 ] = F_87 ( sizeof( struct V_114 ) , V_129 ) ;
if ( ! V_128 -> V_148 [ V_147 ] )
goto V_164;
V_156 = F_80 ( & V_151 , 4 ) ;
if ( F_34 ( ! V_156 ) )
goto V_164;
V_128 -> V_148 [ V_147 ] -> V_170 = F_83 ( V_156 ++ ) ;
if ( sizeof( struct V_114 ) < V_128 -> V_148 [ V_147 ] -> V_170 ) {
F_88 ( V_171 L_23 ,
V_147 , V_128 -> V_148 [ V_147 ] -> V_170 ) ;
goto V_164;
}
V_156 = F_80 ( & V_151 , V_128 -> V_148 [ V_147 ] -> V_170 ) ;
if ( F_34 ( ! V_156 ) )
goto V_164;
memcpy ( V_128 -> V_148 [ V_147 ] -> V_88 , V_156 , V_128 -> V_148 [ V_147 ] -> V_170 ) ;
F_9 ( L_24 , V_22 ,
V_128 -> V_148 [ V_147 ] -> V_170 ) ;
}
F_89 ( V_155 ) ;
return 0 ;
V_164:
F_89 ( V_155 ) ;
return - V_68 ;
}
static void
F_90 ( struct V_11 * V_12 )
{
struct V_1 * V_128 = F_5 ( V_12 ) ;
F_9 ( L_16 , V_22 ) ;
if ( V_128 -> V_6 != NULL )
F_71 ( V_128 -> V_6 ) ;
if ( V_12 -> V_172 . V_173 == V_174 ) {
struct V_175 * V_149 ;
V_149 = F_91 ( V_12 -> V_35 ) ;
V_149 -> V_176 . V_177 = 0 ;
F_74 ( V_149 -> V_176 . V_178 ) ;
V_149 -> V_176 . V_178 = NULL ;
}
F_73 ( V_128 ) ;
}
static int
F_92 ( struct V_11 * V_12 ,
struct V_179 * V_180 ,
T_4 V_129 )
{
struct V_1 * V_128 = F_5 ( V_12 ) ;
struct V_181 * V_178 ;
int V_170 , V_147 ;
if ( V_128 -> V_77 )
return 0 ;
V_170 = ( V_128 -> V_13 == V_14 ) ?
V_128 -> V_6 -> V_141 : V_128 -> V_6 -> V_7 ;
if ( V_180 -> V_109 -> V_177 >= V_170 ) {
return 0 ;
}
V_178 = F_86 ( V_170 , sizeof( struct V_181 ) ,
V_129 ) ;
if ( ! V_178 )
return - V_158 ;
for ( V_147 = 0 ; V_147 < V_170 ; V_147 ++ ) {
F_93 ( & V_178 [ V_147 ] . V_182 ) ;
F_93 ( & V_178 [ V_147 ] . V_183 ) ;
V_178 [ V_147 ] . V_184 . V_80 = V_185 ;
}
F_94 ( & V_180 -> V_24 -> V_186 ) ;
if ( V_180 -> V_109 -> V_177 >= V_170 )
goto V_136;
for ( V_147 = 0 ; V_147 < V_180 -> V_109 -> V_177 ; V_147 ++ ) {
F_95 ( & V_180 -> V_109 -> V_178 [ V_147 ] . V_182 ,
& V_178 [ V_147 ] . V_182 ) ;
F_95 ( & V_180 -> V_109 -> V_178 [ V_147 ] . V_183 ,
& V_178 [ V_147 ] . V_183 ) ;
V_178 [ V_147 ] . V_184 . V_80 =
V_180 -> V_109 -> V_178 [ V_147 ] . V_184 . V_80 ;
V_178 [ V_147 ] . V_187 = V_180 -> V_109 -> V_178 [ V_147 ] . V_187 ;
V_178 [ V_147 ] . V_188 = V_180 -> V_109 -> V_178 [ V_147 ] . V_188 ;
}
F_96 ( V_180 -> V_109 -> V_178 , V_178 ) ;
V_180 -> V_109 -> V_177 = V_170 ;
V_136:
F_97 ( & V_180 -> V_24 -> V_186 ) ;
F_74 ( V_178 ) ;
return 0 ;
}
static struct V_11 *
F_98 ( struct V_33 * V_189 ,
struct V_142 * V_143 ,
T_4 V_129 )
{
struct V_1 * V_128 ;
int V_190 ;
F_9 ( L_16 , V_22 ) ;
V_128 = F_99 ( sizeof( * V_128 ) , V_129 ) ;
if ( ! V_128 )
return NULL ;
V_190 = F_75 ( V_189 , V_128 , V_143 , V_129 ) ;
if ( V_190 != 0 || F_72 ( V_189 , V_128 , V_143 , V_129 ) ) {
F_73 ( V_128 ) ;
return NULL ;
}
return & V_128 -> V_191 ;
}
static V_117
F_100 ( struct V_192 * V_193 , struct V_194 * V_195 ,
struct V_194 * V_196 )
{
unsigned int V_170 ;
T_3 V_197 , V_198 ;
T_2 V_199 ;
T_3 V_200 = V_193 -> V_201 -> V_172 . V_3 ;
T_2 V_5 = F_5 ( V_193 -> V_201 ) -> V_5 ;
V_170 = F_101 ( V_193 , V_195 , V_196 ) ;
if ( ! V_170 )
return 0 ;
if ( V_195 ) {
V_197 = ( T_3 ) F_102 ( V_195 ) - V_200 ;
V_198 = ( T_3 ) F_102 ( V_196 ) - V_200 ;
F_103 ( V_197 , V_5 ) ;
F_103 ( V_198 , V_5 ) ;
if ( V_197 != V_198 )
return 0 ;
}
F_3 ( ( T_3 ) F_102 ( V_196 ) - V_200 ,
V_5 ,
& V_199 ) ;
F_104 ( V_199 > V_5 ) ;
if ( V_199 >= V_5 )
return 0 ;
return F_105 ( V_5 - ( unsigned int ) V_199 , V_170 ) ;
}
static struct V_11 *
F_106 ( struct V_24 * V_202 ,
struct V_203 * V_204 ,
T_1 V_205 ,
T_3 V_27 ,
enum V_206 V_173 ,
bool V_207 ,
T_4 V_129 )
{
struct V_11 * V_12 = NULL ;
struct V_33 * V_34 ;
struct V_1 * V_128 ;
int V_132 ;
V_12 = F_107 ( V_202 , V_204 , V_205 , V_27 , V_173 , V_207 ,
V_129 ) ;
if ( ! V_12 )
V_12 = F_108 ( - V_158 ) ;
if ( F_60 ( V_12 ) )
goto V_136;
V_34 = F_19 ( V_202 ) -> V_85 ;
V_128 = F_5 ( V_12 ) ;
V_132 = F_67 ( V_34 , V_128 , V_129 ) ;
if ( V_132 ) {
F_109 ( V_12 ) ;
V_12 = F_108 ( V_132 ) ;
}
V_136:
return V_12 ;
}
static void
F_110 ( struct V_192 * V_193 ,
struct V_194 * V_196 )
{
F_111 ( V_193 ) ;
if ( ! V_193 -> V_201 ) {
V_193 -> V_201 = F_106 ( V_193 -> V_208 ,
V_196 -> V_209 ,
0 ,
V_146 ,
V_210 ,
false ,
V_211 ) ;
if ( F_60 ( V_193 -> V_201 ) ) {
V_193 -> V_212 = F_112 ( V_193 -> V_201 ) ;
V_193 -> V_201 = NULL ;
return;
}
}
if ( V_193 -> V_201 == NULL )
F_113 ( V_193 ) ;
}
static void
F_114 ( struct V_192 * V_193 ,
struct V_194 * V_196 )
{
struct V_179 V_180 ;
int V_132 ;
F_111 ( V_193 ) ;
if ( ! V_193 -> V_201 ) {
V_193 -> V_201 = F_106 ( V_193 -> V_208 ,
V_196 -> V_209 ,
0 ,
V_146 ,
V_174 ,
false ,
V_213 ) ;
if ( F_60 ( V_193 -> V_201 ) ) {
V_193 -> V_212 = F_112 ( V_193 -> V_201 ) ;
V_193 -> V_201 = NULL ;
return;
}
}
if ( V_193 -> V_201 == NULL )
goto V_214;
F_115 ( & V_180 , V_193 -> V_208 , V_193 -> V_215 ) ;
V_132 = F_92 ( V_193 -> V_201 , & V_180 , V_213 ) ;
if ( V_132 < 0 ) {
F_109 ( V_193 -> V_201 ) ;
V_193 -> V_201 = NULL ;
goto V_214;
}
return;
V_214:
F_116 ( V_193 ) ;
}
static T_2 F_117 ( struct V_1 * V_128 , T_2 V_112 )
{
if ( V_128 -> V_13 == V_14 )
return F_57 ( & V_128 -> V_191 , V_112 ) ;
else
return V_112 ;
}
static void
F_118 ( struct V_194 * V_196 ,
struct V_11 * V_12 ,
struct V_179 * V_180 ,
T_2 V_121 )
{
struct V_1 * V_128 = F_5 ( V_12 ) ;
T_2 V_147 , V_112 ;
if ( V_128 -> V_77 ) {
F_119 ( V_196 , V_180 ) ;
} else {
V_112 = F_56 ( V_12 , F_102 ( V_196 ) ) ;
V_147 = F_117 ( V_128 , V_112 ) ;
F_120 ( V_196 , V_12 , V_180 , V_147 ) ;
}
}
static T_2 F_121 ( struct V_11 * V_12 , T_2 V_147 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 )
return V_147 ;
else
return F_57 ( V_12 , V_147 ) ;
}
static struct V_114 *
F_122 ( struct V_11 * V_12 , T_2 V_147 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
if ( V_2 -> V_140 == 1 )
V_147 = 0 ;
else if ( V_2 -> V_140 == 0 )
return NULL ;
}
return V_2 -> V_148 [ V_147 ] ;
}
static int F_123 ( struct V_102 * V_88 , int V_216 )
{
struct V_11 * V_12 = V_88 -> V_12 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
T_2 V_113 ;
struct V_114 * V_115 ;
V_113 = F_121 ( V_12 , V_88 -> V_217 ) ;
V_109 = F_58 ( V_12 , V_113 ) ;
if ( ! V_109 )
goto V_164;
V_111 = F_59 ( V_109 -> V_75 , V_88 -> V_24 ) ;
if ( F_60 ( V_111 ) )
goto V_164;
F_9 ( L_25 , V_22 ,
V_88 -> V_24 -> V_84 , V_216 , F_61 ( & V_109 -> V_75 -> V_120 ) ) ;
V_88 -> V_218 = F_47 ;
F_62 ( & V_109 -> V_75 -> V_120 ) ;
V_88 -> V_75 = V_109 -> V_75 ;
V_115 = F_122 ( V_12 , V_88 -> V_217 ) ;
if ( V_115 )
V_88 -> args . V_115 = V_115 ;
return F_124 ( V_111 , V_88 , F_65 ( V_88 -> V_24 ) ,
& V_219 , V_216 ,
V_124 ) ;
V_164:
F_49 ( V_88 ) ;
F_125 ( V_88 ) ;
return - V_72 ;
}
static struct V_194 *
F_126 ( struct V_179 * V_180 , struct V_154 * V_154 )
{
struct V_194 * V_220 , * V_221 ;
struct V_181 * V_222 ;
int V_147 ;
for ( V_147 = 0 , V_222 = V_180 -> V_109 -> V_178 ; V_147 < V_180 -> V_109 -> V_177 ; V_147 ++ , V_222 ++ ) {
F_127 (freq, t, &b->written, wb_list) {
if ( V_220 -> V_223 == V_154 )
return V_220 -> V_224 ;
}
F_127 (freq, t, &b->committing, wb_list) {
if ( V_220 -> V_223 == V_154 )
return V_220 -> V_224 ;
}
}
return NULL ;
}
static int
F_128 ( struct V_24 * V_24 , struct V_225 * V_226 ,
int V_216 , struct V_179 * V_180 )
{
return F_129 ( V_24 , V_226 , V_216 , V_180 ,
F_123 ) ;
}
static struct V_37 *
F_130 ( struct V_227 * V_228 ,
struct V_229 * V_230 , T_4 V_129 )
{
struct V_131 * V_6 ;
V_6 = F_131 ( V_228 , V_230 , V_129 ) ;
if ( ! V_6 )
return NULL ;
return & V_6 -> V_137 ;
}
static void
F_132 ( struct V_37 * V_130 )
{
F_133 ( F_69 ( V_130 , struct V_131 , V_137 ) ) ;
}
static struct V_33 *
F_134 ( struct V_24 * V_24 , T_4 V_129 )
{
struct V_175 * V_149 ;
V_149 = F_99 ( sizeof( * V_149 ) , V_129 ) ;
return V_149 != NULL ? & V_149 -> V_191 : NULL ;
}
static void
F_135 ( struct V_33 * V_34 )
{
F_74 ( F_91 ( V_34 ) ) ;
}
static struct V_231 *
F_136 ( struct V_24 * V_24 )
{
struct V_33 * V_85 = F_19 ( V_24 ) -> V_85 ;
if ( V_85 == NULL )
return NULL ;
else
return & F_91 ( V_85 ) -> V_176 ;
}
static int T_7 F_137 ( void )
{
F_88 ( V_232 L_26 ,
V_22 ) ;
return F_138 ( & V_233 ) ;
}
static void T_8 F_139 ( void )
{
F_88 ( V_232 L_27 ,
V_22 ) ;
F_140 ( & V_233 ) ;
}
