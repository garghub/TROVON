static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 , V_6 , V_4 -> V_7 . V_7 ) ;
F_4 ( V_4 -> V_7 . V_7 ) ;
F_5 ( V_2 , V_8 ) ;
}
static inline struct V_9 *
F_6 ( struct V_10 * V_11 )
{
return F_2 ( V_11 , struct V_9 , V_11 ) ;
}
struct V_1 *
F_7 ( struct V_12 * V_13 , struct V_14 * V_15 ,
T_1 V_16 )
{
struct V_17 * V_18 ;
struct V_3 * V_19 = NULL ;
struct V_20 * V_7 ;
struct V_21 V_22 ;
bool V_23 = true ;
T_2 * V_24 ;
int V_25 ;
V_18 = F_8 ( sizeof( * V_18 ) , V_16 ) ;
if ( ! V_18 )
return NULL ;
V_24 = F_9 ( V_15 -> V_26 [ 0 ] ) ;
F_10 ( V_18 , V_24 ) ;
V_22 . V_27 = V_18 -> V_28 . V_29 ;
if ( V_22 . V_27 > sizeof( V_22 . V_30 ) ) {
F_3 ( L_2 ,
V_6 , sizeof( V_22 . V_30 ) ) ;
V_25 = - V_31 ;
goto V_32;
} else if ( V_22 . V_27 )
memcpy ( V_22 . V_30 , V_18 -> V_28 . V_33 ,
V_22 . V_27 ) ;
V_22 . V_34 = V_18 -> V_35 . V_29 ;
V_22 . V_36 = ( V_37 * ) V_18 -> V_35 . V_33 ;
if ( ! V_22 . V_34 && ! V_22 . V_27 ) {
F_3 ( L_3 ,
V_6 ) ;
V_25 = - V_38 ;
goto V_32;
}
V_39:
V_7 = F_11 ( & V_22 ) ;
if ( F_12 ( F_13 ( V_7 ) ) ) {
V_25 = F_14 ( V_7 ) ;
F_3 ( L_4 , V_6 , V_25 ) ;
if ( V_25 == - V_38 && V_23 ) {
V_25 = F_15 ( V_18 ) ;
if ( F_16 ( ! V_25 ) ) {
V_23 = false ;
goto V_39;
}
}
goto V_32;
}
F_3 ( L_5 ,
F_17 ( & V_15 -> V_40 ) , F_18 ( & V_15 -> V_40 ) ) ;
V_19 = F_8 ( sizeof( * V_19 ) , V_16 ) ;
if ( ! V_19 ) {
F_3 ( L_6 , V_6 , V_7 ) ;
goto V_32;
}
F_19 ( & V_19 -> V_5 , V_13 , & V_15 -> V_40 ) ;
F_20 ( V_18 ) ;
V_19 -> V_7 . V_7 = V_7 ;
return & V_19 -> V_5 ;
V_32:
F_20 ( V_18 ) ;
return NULL ;
}
static void F_21 ( struct V_41 * V_42 , unsigned V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = & V_42 -> V_48 [ V_43 ] ;
F_22 ( V_45 -> V_49 . V_50 > 0 ) ;
F_22 ( V_45 -> V_51 . V_50 > sizeof( V_47 -> V_52 ) ) ;
V_47 -> V_53 . V_54 = V_45 -> V_55 . V_56 ;
V_47 -> V_53 . V_57 = V_45 -> V_55 . V_58 ;
memcpy ( V_47 -> V_52 , V_45 -> V_51 . V_52 , sizeof( V_47 -> V_52 ) ) ;
}
static int F_23 ( unsigned V_59 , T_1 V_16 ,
struct V_9 * * V_60 )
{
struct V_9 * V_11 ;
T_3 V_61 = sizeof( * V_11 ) +
V_59 * sizeof( V_11 -> V_42 . V_62 [ 0 ] ) +
V_59 * sizeof( * V_11 -> V_42 . V_48 ) ;
V_11 = F_8 ( V_61 , V_16 ) ;
if ( F_12 ( ! V_11 ) ) {
F_3 ( L_7 , V_6 ,
V_59 , V_61 ) ;
return - V_63 ;
}
V_11 -> V_42 . V_59 = V_59 ;
V_11 -> V_42 . V_64 = V_65 ;
V_11 -> V_42 . V_62 = ( void * ) ( V_11 + 1 ) ;
V_11 -> V_42 . V_48 = ( void * ) ( V_11 -> V_42 . V_62 + V_59 ) ;
* V_60 = V_11 ;
return 0 ;
}
int F_24 ( struct V_10 * * V_66 ,
struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 ,
T_1 V_16 )
{
struct V_12 * V_13 = F_25 ( V_68 -> V_73 ) ;
struct V_9 * V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
struct V_44 V_45 ;
unsigned V_79 ;
int V_25 ;
V_25 = F_26 ( & V_78 , & V_76 , V_72 ) ;
if ( F_12 ( V_25 ) )
return V_25 ;
V_25 = F_23 ( V_78 . V_80 , V_16 , & V_74 ) ;
if ( F_12 ( V_25 ) )
return V_25 ;
V_74 -> V_78 . V_81 = V_78 . V_82 . V_83 ;
V_74 -> V_78 . V_84 = V_78 . V_82 . V_85 ;
V_74 -> V_78 . V_86 = V_78 . V_82 . V_87 ;
V_74 -> V_78 . V_88 = V_78 . V_82 . V_89 + 1 ;
V_74 -> V_78 . V_90 = V_78 . V_82 . V_91 ;
V_25 = F_27 ( V_78 . V_82 . V_92 ,
& V_74 -> V_78 ) ;
if ( F_12 ( V_25 ) )
goto V_25;
V_74 -> V_42 . V_93 = V_78 . V_94 ;
V_79 = 0 ;
while ( F_28 ( & V_45 , & V_76 , V_72 , & V_25 ) ) {
struct V_1 * V_2 ;
struct V_3 * V_19 ;
F_21 ( & V_74 -> V_42 , V_79 , & V_45 ) ;
V_2 = F_29 ( V_13 ,
& V_45 . V_55 . V_95 ,
V_68 -> V_96 , V_16 ) ;
if ( ! V_2 ) {
V_25 = - V_97 ;
goto V_25;
}
V_19 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_74 -> V_42 . V_62 [ V_79 ++ ] = & V_19 -> V_7 ;
}
if ( F_12 ( V_25 ) )
goto V_25;
* V_66 = & V_74 -> V_11 ;
return 0 ;
V_25:
F_20 ( V_74 ) ;
F_3 ( L_8 , V_6 , V_25 ) ;
* V_66 = NULL ;
return V_25 ;
}
void F_30 ( struct V_10 * V_11 )
{
int V_98 ;
struct V_9 * V_74 = F_6 ( V_11 ) ;
for ( V_98 = 0 ; V_98 < V_74 -> V_42 . V_59 ; V_98 ++ ) {
struct V_99 * V_7 = V_74 -> V_42 . V_62 [ V_98 ] ;
struct V_3 * V_19 ;
if ( ! V_7 )
break;
V_19 = F_2 ( V_7 , F_31 ( * V_19 ) , V_7 ) ;
F_32 ( & V_19 -> V_5 ) ;
}
F_20 ( V_74 ) ;
}
static int
F_33 ( struct V_67 * V_100 , bool V_101 ,
struct V_10 * V_11 , struct V_102 * * V_26 , unsigned V_103 ,
T_4 V_104 , T_3 V_105 , void * V_106 , T_1 V_16 ,
struct V_107 * * V_66 )
{
struct V_9 * V_74 = F_6 ( V_11 ) ;
struct V_108 * V_109 ;
int V_110 ;
struct V_111 {
struct V_107 V_112 ;
struct V_113 V_114 [ V_74 -> V_42 . V_59 ] ;
} * V_115 ;
V_115 = F_8 ( sizeof( * V_115 ) , V_16 ) ;
if ( F_12 ( ! V_115 ) )
return - V_63 ;
F_34 ( & V_115 -> V_112 . V_116 , V_74 -> V_42 . V_59 ,
V_115 -> V_114 , V_106 , V_100 ) ;
V_110 = F_35 ( & V_74 -> V_78 , & V_74 -> V_42 , V_101 ,
V_104 , V_105 , & V_109 ) ;
if ( F_12 ( V_110 ) ) {
F_20 ( V_115 ) ;
return V_110 ;
}
V_109 -> V_26 = V_26 ;
V_109 -> V_103 = V_103 ;
V_109 -> V_117 = V_115 ;
F_36 ( V_109 -> V_118 > ( V_103 + V_105 + V_119 - 1 ) >> V_120 ) ;
V_115 -> V_112 . V_121 = 0 ;
V_115 -> V_112 . V_109 = V_109 ;
* V_66 = & V_115 -> V_112 ;
return 0 ;
}
void F_37 ( struct V_122 * V_116 )
{
struct V_107 * V_112 = F_2 ( V_116 , struct V_107 , V_116 ) ;
F_38 ( V_112 -> V_109 ) ;
F_20 ( V_112 ) ;
}
static enum V_123 F_39 ( enum V_124 V_125 )
{
switch ( V_125 ) {
case V_126 :
return (enum V_123 ) 0 ;
case V_127 :
F_36 ( 1 ) ;
return 0 ;
case V_128 :
return V_129 ;
case V_130 :
return V_131 ;
case V_132 :
return V_133 ;
case V_134 :
return V_135 ;
case V_136 :
return V_137 ;
case V_138 :
return V_139 ;
default:
F_22 ( 1 ) ;
case V_140 :
return V_141 ;
}
}
static void F_40 ( struct V_108 * V_109 ,
struct V_99 * V_7 , unsigned V_142 , enum V_124 V_125 ,
T_5 V_143 , T_5 V_144 )
{
struct V_107 * V_112 = V_109 -> V_117 ;
struct V_145 V_146 ;
struct V_3 * V_19 = F_2 ( V_7 , F_31 ( * V_19 ) , V_7 ) ;
unsigned V_147 = V_142 ;
V_146 . V_95 = V_19 -> V_5 . V_148 ;
V_146 . V_56 = V_109 -> V_42 -> V_48 [ V_147 ] . V_53 . V_54 ;
V_146 . V_58 = V_109 -> V_42 -> V_48 [ V_147 ] . V_53 . V_57 ;
F_41 ( & V_112 -> V_116 , V_147 ,
& V_146 , F_39 ( V_125 ) ,
V_143 , V_144 , ! V_109 -> V_149 ) ;
}
static void F_42 ( struct V_108 * V_109 , void * V_117 )
{
struct V_107 * V_112 = V_117 ;
T_6 V_150 ;
int V_110 = F_43 ( V_109 , & F_40 ) ;
if ( F_16 ( ! V_110 ) )
V_150 = V_109 -> V_151 ;
else
V_150 = V_110 ;
F_44 ( & V_112 -> V_116 , V_150 , V_112 -> V_121 ) ;
}
int F_45 ( struct V_152 * V_153 )
{
struct V_107 * V_112 ;
int V_110 ;
V_110 = F_33 ( F_46 ( V_153 -> V_154 ) -> V_78 , true ,
V_153 -> V_11 , V_153 -> args . V_26 , V_153 -> args . V_103 ,
V_153 -> args . V_104 , V_153 -> args . V_105 , V_153 ,
V_155 , & V_112 ) ;
if ( F_12 ( V_110 ) )
return V_110 ;
V_112 -> V_109 -> V_156 = F_42 ;
F_3 ( L_9 , V_6 ,
V_153 -> args . V_104 , V_153 -> args . V_105 ) ;
V_110 = F_47 ( V_112 -> V_109 ) ;
if ( F_12 ( V_110 ) )
F_37 ( & V_112 -> V_116 ) ;
return V_110 ;
}
static void F_48 ( struct V_108 * V_109 , void * V_117 )
{
struct V_107 * V_112 = V_117 ;
T_6 V_150 ;
int V_110 = F_43 ( V_109 , & F_40 ) ;
if ( F_16 ( ! V_110 ) ) {
V_112 -> V_116 . V_157 = V_158 ;
V_150 = V_109 -> V_151 ;
} else {
V_150 = V_110 ;
}
F_49 ( & V_112 -> V_116 , V_150 , V_112 -> V_121 ) ;
}
static struct V_102 * F_50 ( void * V_159 , T_5 V_104 , bool * V_160 )
{
struct V_107 * V_112 = V_159 ;
struct V_152 * V_153 = V_112 -> V_116 . V_106 ;
struct V_161 * V_162 = V_153 -> V_154 -> V_163 ;
T_7 V_164 = V_104 / V_119 ;
struct V_102 * V_102 ;
T_4 V_165 = F_51 ( V_153 -> V_154 ) ;
if ( V_104 >= V_165 ) {
* V_160 = true ;
F_3 ( L_10 , V_6 , V_164 ) ;
return F_52 ( 0 ) ;
}
V_102 = F_53 ( V_162 , V_164 ) ;
if ( ! V_102 ) {
V_102 = F_54 ( V_162 , V_164 , V_166 ) ;
if ( F_12 ( ! V_102 ) ) {
F_3 ( L_11 ,
V_6 , V_164 ) ;
return NULL ;
}
F_55 ( V_102 ) ;
}
if ( F_56 ( V_102 ) || F_57 ( V_102 ) )
* V_160 = true ;
else
* V_160 = F_58 ( V_102 ) ;
F_3 ( L_12 , V_6 , V_164 , * V_160 ) ;
return V_102 ;
}
static void F_59 ( void * V_159 , struct V_102 * V_102 )
{
F_3 ( L_13 , V_6 ,
( V_102 == F_52 ( 0 ) ) ? - 1UL : V_102 -> V_164 ) ;
if ( F_52 ( 0 ) != V_102 )
F_60 ( V_102 ) ;
return;
}
int F_61 ( struct V_152 * V_153 , int V_167 )
{
struct V_107 * V_112 ;
int V_110 ;
V_110 = F_33 ( F_46 ( V_153 -> V_154 ) -> V_78 , false ,
V_153 -> V_11 , V_153 -> args . V_26 , V_153 -> args . V_103 ,
V_153 -> args . V_104 , V_153 -> args . V_105 , V_153 , V_166 ,
& V_112 ) ;
if ( F_12 ( V_110 ) )
return V_110 ;
V_112 -> V_121 = 0 != ( V_167 & V_168 ) ;
V_112 -> V_109 -> V_169 = & V_170 ;
if ( ! V_112 -> V_121 )
V_112 -> V_109 -> V_156 = F_48 ;
F_3 ( L_9 , V_6 ,
V_153 -> args . V_104 , V_153 -> args . V_105 ) ;
V_110 = F_62 ( V_112 -> V_109 ) ;
if ( F_12 ( V_110 ) ) {
F_37 ( & V_112 -> V_116 ) ;
return V_110 ;
}
if ( V_112 -> V_121 )
F_48 ( V_112 -> V_109 , V_112 ) ;
return 0 ;
}
static T_3 F_63 ( struct V_171 * V_172 ,
struct V_173 * V_174 , struct V_173 * V_175 )
{
struct V_176 * V_177 = F_64 ( V_172 ) ;
unsigned int V_178 ;
V_178 = F_65 ( V_172 , V_174 , V_175 ) ;
if ( ! V_178 || V_177 -> V_179 + V_175 -> V_180 >
( unsigned long ) V_172 -> V_181 )
return 0 ;
return F_66 ( V_178 , V_175 -> V_180 ) ;
}
static void F_67 ( struct V_171 * V_172 , struct V_173 * V_175 )
{
F_68 ( V_172 , V_175 ) ;
if ( F_12 ( V_172 -> V_182 == NULL ) )
return;
V_172 -> V_181 = ( void * )
F_6 ( V_172 -> V_182 ) -> V_78 . V_183 ;
}
static bool F_69 ( T_5 V_104 , struct V_184 * V_78 ,
unsigned long * V_185 )
{
T_8 V_186 ;
unsigned V_187 ;
if ( V_78 -> V_90 == V_188 )
return true ;
V_187 = V_78 -> V_81 *
( V_78 -> V_84 - V_78 -> V_189 ) ;
F_70 ( V_104 , V_187 , & V_186 ) ;
if ( ! V_186 )
return true ;
* V_185 = V_187 - V_186 ;
return false ;
}
static void F_71 ( struct V_171 * V_172 , struct V_173 * V_175 )
{
unsigned long V_185 = 0 ;
T_5 V_190 ;
if ( V_172 -> V_191 == NULL )
V_190 = F_51 ( V_172 -> V_192 ) - F_72 ( V_175 ) ;
else
V_190 = F_73 ( V_172 -> V_191 ) ;
F_74 ( V_172 , V_175 , V_190 ) ;
if ( F_12 ( V_172 -> V_182 == NULL ) )
return;
if ( V_175 -> V_193 ||
! F_69 ( V_175 -> V_194 * V_119 ,
& F_6 ( V_172 -> V_182 ) -> V_78 ,
& V_185 ) ) {
V_172 -> V_181 = ( void * ) V_185 ;
} else {
V_172 -> V_181 = ( void * )
F_6 ( V_172 -> V_182 ) -> V_78 . V_183 ;
}
}
static int T_9
F_75 ( void )
{
int V_110 = F_76 ( & V_195 ) ;
if ( V_110 )
F_77 ( V_196
L_14 ,
V_6 , V_110 ) ;
else
F_77 ( V_196 L_15 ,
V_6 ) ;
return V_110 ;
}
static void T_10
F_78 ( void )
{
F_79 ( & V_195 ) ;
F_77 ( V_196 L_16 ,
V_6 ) ;
}
