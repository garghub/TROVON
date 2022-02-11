static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 , V_6 , V_4 -> V_7 . V_7 ) ;
F_4 ( V_4 -> V_7 . V_7 ) ;
F_5 ( V_4 ) ;
}
static inline struct V_8 *
F_6 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_8 , V_10 ) ;
}
struct V_1 *
F_7 ( struct V_11 * V_12 , struct V_13 * V_14 ,
T_1 V_15 )
{
struct V_16 * V_17 ;
struct V_3 * V_18 = NULL ;
struct V_19 * V_7 ;
struct V_20 V_21 ;
bool V_22 = true ;
T_2 * V_23 ;
int V_24 ;
V_17 = F_8 ( sizeof( * V_17 ) , V_15 ) ;
if ( ! V_17 )
return NULL ;
V_23 = F_9 ( V_14 -> V_25 [ 0 ] ) ;
F_10 ( V_17 , V_23 ) ;
V_21 . V_26 = V_17 -> V_27 . V_28 ;
if ( V_21 . V_26 > sizeof( V_21 . V_29 ) ) {
F_3 ( L_2 ,
V_6 , sizeof( V_21 . V_29 ) ) ;
V_24 = - V_30 ;
goto V_31;
} else if ( V_21 . V_26 )
memcpy ( V_21 . V_29 , V_17 -> V_27 . V_32 ,
V_21 . V_26 ) ;
V_21 . V_33 = V_17 -> V_34 . V_28 ;
V_21 . V_35 = ( V_36 * ) V_17 -> V_34 . V_32 ;
if ( ! V_21 . V_33 && ! V_21 . V_26 ) {
F_3 ( L_3 ,
V_6 ) ;
V_24 = - V_37 ;
goto V_31;
}
V_38:
V_7 = F_11 ( & V_21 ) ;
if ( F_12 ( F_13 ( V_7 ) ) ) {
V_24 = F_14 ( V_7 ) ;
F_3 ( L_4 , V_6 , V_24 ) ;
if ( V_24 == - V_37 && V_22 ) {
V_24 = F_15 ( V_17 ) ;
if ( F_16 ( ! V_24 ) ) {
V_22 = false ;
goto V_38;
}
}
goto V_31;
}
F_3 ( L_5 ,
F_17 ( & V_14 -> V_39 ) , F_18 ( & V_14 -> V_39 ) ) ;
V_18 = F_8 ( sizeof( * V_18 ) , V_15 ) ;
if ( ! V_18 ) {
F_3 ( L_6 , V_6 , V_7 ) ;
goto V_31;
}
F_19 ( & V_18 -> V_5 , V_12 , & V_14 -> V_39 ) ;
F_5 ( V_17 ) ;
V_18 -> V_7 . V_7 = V_7 ;
return & V_18 -> V_5 ;
V_31:
F_5 ( V_17 ) ;
return NULL ;
}
static void F_20 ( struct V_40 * V_41 , unsigned V_42 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_41 -> V_47 [ V_42 ] ;
F_21 ( V_44 -> V_48 . V_49 > 0 ) ;
F_21 ( V_44 -> V_50 . V_49 > sizeof( V_46 -> V_51 ) ) ;
V_46 -> V_52 . V_53 = V_44 -> V_54 . V_55 ;
V_46 -> V_52 . V_56 = V_44 -> V_54 . V_57 ;
memcpy ( V_46 -> V_51 , V_44 -> V_50 . V_51 , sizeof( V_46 -> V_51 ) ) ;
}
static int F_22 ( unsigned V_58 , T_1 V_15 ,
struct V_8 * * V_59 )
{
struct V_8 * V_10 ;
T_3 V_60 = sizeof( * V_10 ) +
V_58 * sizeof( V_10 -> V_41 . V_61 [ 0 ] ) +
V_58 * sizeof( * V_10 -> V_41 . V_47 ) ;
V_10 = F_8 ( V_60 , V_15 ) ;
if ( F_12 ( ! V_10 ) ) {
F_3 ( L_7 , V_6 ,
V_58 , V_60 ) ;
return - V_62 ;
}
V_10 -> V_41 . V_58 = V_58 ;
V_10 -> V_41 . V_63 = V_64 ;
V_10 -> V_41 . V_61 = ( void * ) ( V_10 + 1 ) ;
V_10 -> V_41 . V_47 = ( void * ) ( V_10 -> V_41 . V_61 + V_58 ) ;
* V_59 = V_10 ;
return 0 ;
}
int F_23 ( struct V_9 * * V_65 ,
struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * V_71 ,
T_1 V_15 )
{
struct V_11 * V_12 = F_24 ( V_67 -> V_72 ) ;
struct V_8 * V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
struct V_43 V_44 ;
unsigned V_78 ;
int V_24 ;
V_24 = F_25 ( & V_77 , & V_75 , V_71 ) ;
if ( F_12 ( V_24 ) )
return V_24 ;
V_24 = F_22 ( V_77 . V_79 , V_15 , & V_73 ) ;
if ( F_12 ( V_24 ) )
return V_24 ;
V_73 -> V_77 . V_80 = V_77 . V_81 . V_82 ;
V_73 -> V_77 . V_83 = V_77 . V_81 . V_84 ;
V_73 -> V_77 . V_85 = V_77 . V_81 . V_86 ;
V_73 -> V_77 . V_87 = V_77 . V_81 . V_88 + 1 ;
V_73 -> V_77 . V_89 = V_77 . V_81 . V_90 ;
V_24 = F_26 ( V_77 . V_81 . V_91 ,
& V_73 -> V_77 ) ;
if ( F_12 ( V_24 ) )
goto V_24;
V_73 -> V_41 . V_92 = V_77 . V_93 ;
V_78 = 0 ;
while ( F_27 ( & V_44 , & V_75 , V_71 , & V_24 ) ) {
struct V_1 * V_2 ;
struct V_3 * V_18 ;
F_20 ( & V_73 -> V_41 , V_78 , & V_44 ) ;
V_2 = F_28 ( V_12 ,
& V_44 . V_54 . V_94 ,
V_67 -> V_95 , V_15 ) ;
if ( ! V_2 ) {
V_24 = - V_96 ;
goto V_24;
}
V_18 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_73 -> V_41 . V_61 [ V_78 ++ ] = & V_18 -> V_7 ;
}
if ( F_12 ( V_24 ) )
goto V_24;
* V_65 = & V_73 -> V_10 ;
return 0 ;
V_24:
F_5 ( V_73 ) ;
F_3 ( L_8 , V_6 , V_24 ) ;
* V_65 = NULL ;
return V_24 ;
}
void F_29 ( struct V_9 * V_10 )
{
int V_97 ;
struct V_8 * V_73 = F_6 ( V_10 ) ;
for ( V_97 = 0 ; V_97 < V_73 -> V_41 . V_58 ; V_97 ++ ) {
struct V_98 * V_7 = V_73 -> V_41 . V_61 [ V_97 ] ;
struct V_3 * V_18 ;
if ( ! V_7 )
break;
V_18 = F_2 ( V_7 , F_30 ( * V_18 ) , V_7 ) ;
F_31 ( & V_18 -> V_5 ) ;
}
F_5 ( V_73 ) ;
}
static int
F_32 ( struct V_66 * V_99 , bool V_100 ,
struct V_9 * V_10 , struct V_101 * * V_25 , unsigned V_102 ,
T_4 V_103 , T_3 V_104 , void * V_105 , T_1 V_15 ,
struct V_106 * * V_65 )
{
struct V_8 * V_73 = F_6 ( V_10 ) ;
struct V_107 * V_108 ;
int V_109 ;
struct V_110 {
struct V_106 V_111 ;
struct V_112 V_113 [ V_73 -> V_41 . V_58 ] ;
} * V_114 ;
V_114 = F_8 ( sizeof( * V_114 ) , V_15 ) ;
if ( F_12 ( ! V_114 ) )
return - V_62 ;
F_33 ( & V_114 -> V_111 . V_115 , V_73 -> V_41 . V_58 ,
V_114 -> V_113 , V_105 , V_99 ) ;
V_109 = F_34 ( & V_73 -> V_77 , & V_73 -> V_41 , V_100 ,
V_103 , V_104 , & V_108 ) ;
if ( F_12 ( V_109 ) ) {
F_5 ( V_114 ) ;
return V_109 ;
}
V_108 -> V_25 = V_25 ;
V_108 -> V_102 = V_102 ;
V_108 -> V_116 = V_114 ;
F_35 ( V_108 -> V_117 > ( V_102 + V_104 + V_118 - 1 ) >> V_119 ) ;
V_114 -> V_111 . V_120 = 0 ;
V_114 -> V_111 . V_108 = V_108 ;
* V_65 = & V_114 -> V_111 ;
return 0 ;
}
void F_36 ( struct V_121 * V_115 )
{
struct V_106 * V_111 = F_2 ( V_115 , struct V_106 , V_115 ) ;
F_37 ( V_111 -> V_108 ) ;
F_5 ( V_111 ) ;
}
static enum V_122 F_38 ( enum V_123 V_124 )
{
switch ( V_124 ) {
case V_125 :
return (enum V_122 ) 0 ;
case V_126 :
F_35 ( 1 ) ;
return 0 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
case V_131 :
return V_132 ;
case V_133 :
return V_134 ;
case V_135 :
return V_136 ;
case V_137 :
return V_138 ;
default:
F_21 ( 1 ) ;
case V_139 :
return V_140 ;
}
}
static void F_39 ( struct V_107 * V_108 ,
struct V_98 * V_7 , unsigned V_141 , enum V_123 V_124 ,
T_5 V_142 , T_5 V_143 )
{
struct V_106 * V_111 = V_108 -> V_116 ;
struct V_144 V_145 ;
struct V_3 * V_18 = F_2 ( V_7 , F_30 ( * V_18 ) , V_7 ) ;
unsigned V_146 = V_141 ;
V_145 . V_94 = V_18 -> V_5 . V_147 ;
V_145 . V_55 = V_108 -> V_41 -> V_47 [ V_146 ] . V_52 . V_53 ;
V_145 . V_57 = V_108 -> V_41 -> V_47 [ V_146 ] . V_52 . V_56 ;
F_40 ( & V_111 -> V_115 , V_146 ,
& V_145 , F_38 ( V_124 ) ,
V_142 , V_143 , ! V_108 -> V_148 ) ;
}
static void F_41 ( struct V_107 * V_108 , void * V_116 )
{
struct V_106 * V_111 = V_116 ;
T_6 V_149 ;
int V_109 = F_42 ( V_108 , & F_39 ) ;
if ( F_16 ( ! V_109 ) )
V_149 = V_108 -> V_150 ;
else
V_149 = V_109 ;
F_43 ( & V_111 -> V_115 , V_149 , V_111 -> V_120 ) ;
}
int F_44 ( struct V_151 * V_152 )
{
struct V_106 * V_111 ;
int V_109 ;
V_109 = F_32 ( F_45 ( V_152 -> V_153 ) -> V_77 , true ,
V_152 -> V_10 , V_152 -> args . V_25 , V_152 -> args . V_102 ,
V_152 -> args . V_103 , V_152 -> args . V_104 , V_152 ,
V_154 , & V_111 ) ;
if ( F_12 ( V_109 ) )
return V_109 ;
V_111 -> V_108 -> V_155 = F_41 ;
F_3 ( L_9 , V_6 ,
V_152 -> args . V_103 , V_152 -> args . V_104 ) ;
V_109 = F_46 ( V_111 -> V_108 ) ;
if ( F_12 ( V_109 ) )
F_36 ( & V_111 -> V_115 ) ;
return V_109 ;
}
static void F_47 ( struct V_107 * V_108 , void * V_116 )
{
struct V_106 * V_111 = V_116 ;
T_6 V_149 ;
int V_109 = F_42 ( V_108 , & F_39 ) ;
if ( F_16 ( ! V_109 ) ) {
V_111 -> V_115 . V_156 = V_157 ;
V_149 = V_108 -> V_150 ;
} else {
V_149 = V_109 ;
}
F_48 ( & V_111 -> V_115 , V_149 , V_111 -> V_120 ) ;
}
static struct V_101 * F_49 ( void * V_158 , T_5 V_103 , bool * V_159 )
{
struct V_106 * V_111 = V_158 ;
struct V_151 * V_152 = V_111 -> V_115 . V_105 ;
struct V_160 * V_161 = V_152 -> V_153 -> V_162 ;
T_7 V_163 = V_103 / V_118 ;
struct V_101 * V_101 ;
T_4 V_164 = F_50 ( V_152 -> V_153 ) ;
if ( V_103 >= V_164 ) {
* V_159 = true ;
F_3 ( L_10 , V_6 , V_163 ) ;
return F_51 ( 0 ) ;
}
V_101 = F_52 ( V_161 , V_163 ) ;
if ( ! V_101 ) {
V_101 = F_53 ( V_161 , V_163 , V_165 ) ;
if ( F_12 ( ! V_101 ) ) {
F_3 ( L_11 ,
V_6 , V_163 ) ;
return NULL ;
}
F_54 ( V_101 ) ;
}
if ( F_55 ( V_101 ) || F_56 ( V_101 ) )
* V_159 = true ;
else
* V_159 = F_57 ( V_101 ) ;
F_3 ( L_12 , V_6 , V_163 , * V_159 ) ;
return V_101 ;
}
static void F_58 ( void * V_158 , struct V_101 * V_101 )
{
F_3 ( L_13 , V_6 ,
( V_101 == F_51 ( 0 ) ) ? - 1UL : V_101 -> V_163 ) ;
if ( F_51 ( 0 ) != V_101 )
F_59 ( V_101 ) ;
return;
}
int F_60 ( struct V_151 * V_152 , int V_166 )
{
struct V_106 * V_111 ;
int V_109 ;
V_109 = F_32 ( F_45 ( V_152 -> V_153 ) -> V_77 , false ,
V_152 -> V_10 , V_152 -> args . V_25 , V_152 -> args . V_102 ,
V_152 -> args . V_103 , V_152 -> args . V_104 , V_152 , V_165 ,
& V_111 ) ;
if ( F_12 ( V_109 ) )
return V_109 ;
V_111 -> V_120 = 0 != ( V_166 & V_167 ) ;
V_111 -> V_108 -> V_168 = & V_169 ;
if ( ! V_111 -> V_120 )
V_111 -> V_108 -> V_155 = F_47 ;
F_3 ( L_9 , V_6 ,
V_152 -> args . V_103 , V_152 -> args . V_104 ) ;
V_109 = F_61 ( V_111 -> V_108 ) ;
if ( F_12 ( V_109 ) ) {
F_36 ( & V_111 -> V_115 ) ;
return V_109 ;
}
if ( V_111 -> V_120 )
F_47 ( V_111 -> V_108 , V_111 ) ;
return 0 ;
}
static T_3 F_62 ( struct V_170 * V_171 ,
struct V_172 * V_173 , struct V_172 * V_174 )
{
struct V_175 * V_176 = F_63 ( V_171 ) ;
unsigned int V_177 ;
V_177 = F_64 ( V_171 , V_173 , V_174 ) ;
if ( ! V_177 || V_176 -> V_178 + V_174 -> V_179 >
( unsigned long ) V_171 -> V_180 )
return 0 ;
return F_65 ( V_177 , V_174 -> V_179 ) ;
}
static void F_66 ( struct V_170 * V_171 , struct V_172 * V_174 )
{
F_67 ( V_171 , V_174 ) ;
if ( F_12 ( V_171 -> V_181 == NULL ) )
return;
V_171 -> V_180 = ( void * )
F_6 ( V_171 -> V_181 ) -> V_77 . V_182 ;
}
static bool F_68 ( T_5 V_103 , struct V_183 * V_77 ,
unsigned long * V_184 )
{
T_8 V_185 ;
unsigned V_186 ;
if ( V_77 -> V_89 == V_187 )
return true ;
V_186 = V_77 -> V_80 *
( V_77 -> V_83 - V_77 -> V_188 ) ;
F_69 ( V_103 , V_186 , & V_185 ) ;
if ( ! V_185 )
return true ;
* V_184 = V_186 - V_185 ;
return false ;
}
static void F_70 ( struct V_170 * V_171 , struct V_172 * V_174 )
{
unsigned long V_184 = 0 ;
T_5 V_189 ;
if ( V_171 -> V_190 == NULL )
V_189 = F_50 ( V_171 -> V_191 ) - F_71 ( V_174 ) ;
else
V_189 = F_72 ( V_171 -> V_190 ) ;
F_73 ( V_171 , V_174 , V_189 ) ;
if ( F_12 ( V_171 -> V_181 == NULL ) )
return;
if ( V_174 -> V_192 ||
! F_68 ( V_174 -> V_193 * V_118 ,
& F_6 ( V_171 -> V_181 ) -> V_77 ,
& V_184 ) ) {
V_171 -> V_180 = ( void * ) V_184 ;
} else {
V_171 -> V_180 = ( void * )
F_6 ( V_171 -> V_181 ) -> V_77 . V_182 ;
}
}
static int T_9
F_74 ( void )
{
int V_109 = F_75 ( & V_194 ) ;
if ( V_109 )
F_76 ( V_195
L_14 ,
V_6 , V_109 ) ;
else
F_76 ( V_195 L_15 ,
V_6 ) ;
return V_109 ;
}
static void T_10
F_77 ( void )
{
F_78 ( & V_194 ) ;
F_76 ( V_195 L_16 ,
V_6 ) ;
}
