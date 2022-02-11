static struct V_1 * F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 ;
}
static int F_2 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
return F_3 ( V_4 , V_6 , V_8 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 )
{
return V_2 -> V_9 -> V_10 ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static unsigned int F_6 ( const struct V_1 * V_2 )
{
return 65535 - 40 ;
}
static bool F_7 ( const struct V_7 * V_8 )
{
const struct V_11 * V_12 = (struct V_11 * ) V_8 -> V_13 ;
T_2 V_14 = sizeof( * V_12 ) ;
bool V_15 = true ;
if ( V_8 -> V_16 < V_14 )
goto V_17;
if ( V_12 -> V_18 == V_19 ) {
const struct V_20 * V_21 ;
if ( V_8 -> V_16 < V_14 + sizeof( * V_21 ) )
goto V_17;
V_21 = (struct V_20 * ) ( V_8 -> V_13 + sizeof( * V_12 ) ) ;
switch ( V_21 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_15 = false ;
break;
}
}
V_17:
return V_15 ;
}
static bool F_7 ( const struct V_7 * V_8 )
{
return false ;
}
static bool F_8 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_28 ) {
case F_9 ( V_29 ) :
return true ;
case F_9 ( V_30 ) :
return F_7 ( V_8 ) ;
}
return false ;
}
static void F_10 ( struct V_31 * V_32 , struct V_7 * V_8 )
{
V_32 -> V_33 . V_34 ++ ;
F_11 ( V_8 ) ;
}
static T_3 F_12 ( struct V_7 * * V_35 )
{
struct V_7 * V_8 = * V_35 ;
if ( F_8 ( V_8 ) ) {
struct V_31 * V_9 = F_13 ( V_8 -> V_9 ) ;
struct V_36 * V_37 = F_14 ( V_9 -> V_37 ) ;
F_15 ( & V_37 -> V_38 ) ;
V_37 -> V_39 ++ ;
V_37 -> V_40 += V_8 -> V_16 ;
F_16 ( & V_37 -> V_38 ) ;
V_8 -> V_9 = V_9 ;
return V_41 ;
}
return V_42 ;
}
static struct V_43 * F_17 ( struct V_31 * V_9 ,
struct V_43 * V_33 )
{
int V_44 ;
F_18 (i) {
const struct V_36 * V_37 ;
T_4 V_45 , V_46 , V_47 , V_48 , V_49 ;
unsigned int V_50 ;
V_37 = F_19 ( V_9 -> V_37 , V_44 ) ;
do {
V_50 = F_20 ( & V_37 -> V_38 ) ;
V_45 = V_37 -> V_51 ;
V_46 = V_37 -> V_52 ;
V_47 = V_37 -> V_53 ;
V_48 = V_37 -> V_40 ;
V_49 = V_37 -> V_39 ;
} while ( F_21 ( & V_37 -> V_38 , V_50 ) );
V_33 -> V_51 += V_45 ;
V_33 -> V_54 += V_46 ;
V_33 -> V_55 += V_47 ;
V_33 -> V_40 += V_48 ;
V_33 -> V_56 += V_49 ;
}
return V_33 ;
}
static T_5 F_22 ( struct V_7 * V_8 ,
struct V_31 * V_9 )
{
const struct V_11 * V_57 = F_23 ( V_8 ) ;
struct V_4 * V_4 = F_24 ( V_8 -> V_9 ) ;
struct V_58 V_59 = {
. V_60 = V_9 -> V_61 ,
. V_62 = V_63 ,
. V_64 = V_57 -> V_64 ,
. V_65 = V_57 -> V_65 ,
. V_66 = F_25 ( V_57 ) ,
. V_67 = V_8 -> V_68 ,
. V_69 = V_57 -> V_18 ,
. V_70 = V_71 | V_72 ,
} ;
int V_73 = V_74 ;
struct V_1 * V_2 ;
struct V_1 * V_75 = & V_4 -> V_76 . V_77 -> V_2 ;
V_2 = F_26 ( V_4 , NULL , & V_59 ) ;
if ( V_2 == V_75 )
goto V_78;
F_27 ( V_8 ) ;
F_28 ( V_8 , V_2 ) ;
V_73 = F_29 ( V_4 , V_8 -> V_6 , V_8 ) ;
if ( F_30 ( F_31 ( V_73 ) ) )
V_9 -> V_33 . V_34 ++ ;
else
V_73 = V_79 ;
return V_73 ;
V_78:
F_10 ( V_9 , V_8 ) ;
return V_74 ;
}
static T_5 F_22 ( struct V_7 * V_8 ,
struct V_31 * V_9 )
{
F_10 ( V_9 , V_8 ) ;
return V_74 ;
}
static int F_32 ( struct V_7 * V_8 , struct V_80 * V_81 ,
struct V_31 * V_32 )
{
struct V_82 * V_83 ;
int V_78 = 1 ;
V_83 = F_33 ( F_24 ( V_32 ) , V_81 , NULL ) ;
if ( F_34 ( V_83 ) )
goto V_17;
if ( V_83 -> V_84 != V_85 && V_83 -> V_84 != V_86 ) {
F_35 ( V_83 ) ;
goto V_17;
}
F_27 ( V_8 ) ;
F_28 ( V_8 , & V_83 -> V_2 ) ;
V_78 = 0 ;
V_17:
return V_78 ;
}
static T_5 F_36 ( struct V_7 * V_8 ,
struct V_31 * V_32 )
{
struct V_87 * V_88 = F_37 ( V_8 ) ;
int V_73 = V_74 ;
struct V_80 V_81 = {
. V_89 = V_32 -> V_61 ,
. V_90 = V_63 ,
. V_91 = F_38 ( V_88 -> V_92 ) ,
. V_93 = V_94 | V_71 |
V_72 ,
. V_64 = V_88 -> V_64 ,
} ;
if ( F_32 ( V_8 , & V_81 , V_32 ) )
goto V_78;
if ( ! V_88 -> V_65 ) {
V_88 -> V_65 = F_39 ( F_40 ( V_8 ) -> V_9 , 0 ,
V_95 ) ;
}
V_73 = F_3 ( F_24 ( F_40 ( V_8 ) -> V_9 ) , V_8 -> V_6 , V_8 ) ;
if ( F_30 ( F_31 ( V_73 ) ) )
V_32 -> V_33 . V_34 ++ ;
else
V_73 = V_79 ;
V_17:
return V_73 ;
V_78:
F_10 ( V_32 , V_8 ) ;
goto V_17;
}
static T_5 F_41 ( struct V_7 * V_8 , struct V_31 * V_9 )
{
F_42 ( V_8 , F_43 ( V_8 ) ) ;
switch ( V_8 -> V_28 ) {
case F_9 ( V_29 ) :
return F_36 ( V_8 , V_9 ) ;
case F_9 ( V_30 ) :
return F_22 ( V_8 , V_9 ) ;
default:
F_10 ( V_9 , V_8 ) ;
return V_74 ;
}
}
static T_5 F_44 ( struct V_7 * V_8 , struct V_31 * V_9 )
{
T_5 V_73 = F_41 ( V_8 , V_9 ) ;
if ( F_45 ( V_73 == V_79 || V_73 == V_96 ) ) {
struct V_36 * V_37 = F_14 ( V_9 -> V_37 ) ;
F_15 ( & V_37 -> V_38 ) ;
V_37 -> V_52 ++ ;
V_37 -> V_51 += V_8 -> V_16 ;
F_16 ( & V_37 -> V_38 ) ;
} else {
F_46 ( V_9 -> V_37 -> V_53 ) ;
}
return V_73 ;
}
static struct V_1 * F_47 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 ;
}
static int F_48 ( void )
{
V_97 . V_98 = F_49 ( L_1 ,
sizeof( struct V_99 ) ,
0 ,
V_100 ,
NULL ) ;
if ( ! V_97 . V_98 )
return - V_101 ;
return 0 ;
}
static void F_50 ( void )
{
F_51 ( V_97 . V_98 ) ;
}
static int F_52 ( struct V_7 * V_8 )
{
V_8 -> V_9 -> V_33 . V_102 ++ ;
F_11 ( V_8 ) ;
return 0 ;
}
static int F_53 ( struct V_4 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_31 * V_9 = V_2 -> V_9 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_73 ;
V_8 -> V_28 = F_9 ( V_30 ) ;
V_8 -> V_9 = V_9 ;
F_54 () ;
V_106 = F_55 ( (struct V_99 * ) V_2 , & F_23 ( V_8 ) -> V_64 ) ;
V_104 = F_56 ( V_2 -> V_9 , V_106 ) ;
if ( F_30 ( ! V_104 ) )
V_104 = F_57 ( & V_107 , V_106 , V_2 -> V_9 , false ) ;
if ( ! F_34 ( V_104 ) ) {
V_73 = F_58 ( V_2 , V_104 , V_8 ) ;
F_59 () ;
return V_73 ;
}
F_59 () ;
F_60 ( F_24 ( V_2 -> V_9 ) ,
F_61 ( V_2 ) , V_108 ) ;
F_11 ( V_8 ) ;
return - V_109 ;
}
static int F_62 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
return F_63 ( V_110 , V_111 ,
V_4 , V_6 , V_8 , NULL , F_40 ( V_8 ) -> V_9 ,
F_53 ,
! ( F_64 ( V_8 ) -> V_112 & V_113 ) ) ;
}
static void F_65 ( struct V_114 * V_115 )
{
F_66 ( & V_115 -> V_116 -> V_2 ) ;
F_67 ( V_115 -> V_116 -> V_117 ) ;
V_115 -> V_116 = NULL ;
}
static int F_68 ( struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_99 * V_116 ;
int V_118 ;
int V_15 = - V_101 ;
V_116 = F_70 ( & V_97 , V_9 , 0 ,
V_119 ,
( V_120 | V_121 | V_122 ) ) ;
if ( ! V_116 )
goto V_17;
V_2 = & V_116 -> V_2 ;
V_116 -> V_117 = F_71 ( struct V_99 * , V_123 ) ;
if ( ! V_116 -> V_117 ) {
F_66 ( V_2 ) ;
goto V_17;
}
F_18 (cpu) {
struct V_99 * * V_124 = F_19 ( V_116 -> V_117 , V_118 ) ;
* V_124 = NULL ;
}
memset ( V_2 + 1 , 0 , sizeof( * V_116 ) - sizeof( * V_2 ) ) ;
F_72 ( & V_116 -> V_125 ) ;
F_72 ( & V_116 -> V_126 ) ;
V_116 -> V_2 . V_127 = F_52 ;
V_116 -> V_2 . V_128 = F_62 ;
V_116 -> V_129 = F_73 ( F_24 ( V_9 ) , V_115 -> V_130 ) ;
F_74 ( & V_116 -> V_2 . V_131 , 2 ) ;
V_115 -> V_116 = V_116 ;
V_15 = 0 ;
V_17:
return V_15 ;
}
static int F_48 ( void )
{
return 0 ;
}
static void F_50 ( void )
{
}
static void F_65 ( struct V_114 * V_115 )
{
}
static int F_68 ( struct V_31 * V_9 )
{
return 0 ;
}
static int F_75 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_2 ;
struct V_31 * V_9 = V_2 -> V_9 ;
unsigned int V_132 = F_76 ( V_9 ) ;
struct V_103 * V_104 ;
T_1 V_106 ;
int V_73 = - V_109 ;
if ( F_30 ( F_77 ( V_8 ) < V_132 && V_9 -> V_133 ) ) {
struct V_7 * V_134 ;
V_134 = F_78 ( V_8 , F_76 ( V_9 ) ) ;
if ( ! V_134 ) {
V_73 = - V_101 ;
goto V_78;
}
if ( V_8 -> V_6 )
F_79 ( V_134 , V_8 -> V_6 ) ;
F_80 ( V_8 ) ;
V_8 = V_134 ;
}
F_54 () ;
V_106 = ( V_135 T_1 ) F_81 ( V_83 , F_37 ( V_8 ) -> V_64 ) ;
V_104 = F_82 ( V_9 , V_106 ) ;
if ( F_30 ( ! V_104 ) )
V_104 = F_57 ( & V_136 , & V_106 , V_9 , false ) ;
if ( ! F_34 ( V_104 ) )
V_73 = F_58 ( V_2 , V_104 , V_8 ) ;
F_59 () ;
V_78:
if ( F_30 ( V_73 < 0 ) )
F_10 ( V_8 -> V_9 , V_8 ) ;
return V_73 ;
}
static int F_83 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_31 * V_9 = F_40 ( V_8 ) -> V_9 ;
F_84 ( V_4 , V_137 , V_8 -> V_16 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_28 = F_9 ( V_29 ) ;
return F_63 ( V_138 , V_111 ,
V_4 , V_6 , V_8 , NULL , V_9 ,
F_75 ,
! ( F_85 ( V_8 ) -> V_112 & V_139 ) ) ;
}
static void F_86 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 -> V_140 ;
F_66 ( V_2 ) ;
V_115 -> V_140 = NULL ;
}
static struct V_82 * F_87 ( struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
struct V_82 * V_140 ;
V_140 = F_70 ( & V_141 , V_9 , 2 ,
V_119 ,
( V_120 | V_121 | V_122 ) ) ;
if ( V_140 ) {
V_140 -> V_2 . V_128 = F_83 ;
V_140 -> V_142 = F_88 ( F_24 ( V_9 ) ) ;
V_140 -> V_143 = 0 ;
V_140 -> V_84 = V_85 ;
V_140 -> V_144 = 0 ;
V_140 -> V_145 = 0 ;
V_140 -> V_146 = 0 ;
V_140 -> V_147 = 0 ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = V_115 -> V_130 ;
F_72 ( & V_140 -> V_150 ) ;
V_140 -> V_151 = NULL ;
}
return V_140 ;
}
static void F_89 ( struct V_31 * V_9 )
{
unsigned int V_112 = V_9 -> V_112 ;
int V_73 ;
if ( ! F_90 ( V_9 ) )
return;
V_73 = F_91 ( V_9 , V_112 & ~ V_152 ) ;
if ( V_73 >= 0 )
V_73 = F_91 ( V_9 , V_112 ) ;
if ( V_73 < 0 ) {
F_92 ( V_9 ,
L_2 ,
V_9 -> V_153 ) ;
}
}
static struct V_154 * F_93 ( struct V_155 * V_156 ,
struct V_31 * V_9 )
{
struct V_157 * V_158 = & V_156 -> V_159 ;
struct V_154 * V_154 ;
F_94 (slave, head, list) {
if ( V_154 -> V_9 == V_9 )
return V_154 ;
}
return NULL ;
}
static void F_95 ( struct V_155 * V_156 , struct V_154 * V_154 )
{
F_96 ( & V_154 -> V_160 ) ;
}
static void F_97 ( struct V_155 * V_156 , struct V_154 * V_154 )
{
F_98 ( & V_154 -> V_160 , & V_156 -> V_159 ) ;
}
static int F_99 ( struct V_31 * V_9 , struct V_31 * V_161 )
{
struct V_154 * V_154 = F_100 ( sizeof( * V_154 ) , V_123 ) ;
struct V_114 * V_115 = F_69 ( V_9 ) ;
struct V_155 * V_156 = & V_115 -> V_156 ;
int V_73 = - V_101 ;
if ( ! V_154 )
goto V_162;
V_154 -> V_9 = V_161 ;
V_73 = F_101 ( V_161 , F_12 , V_9 ) ;
if ( V_73 ) {
F_92 ( V_161 ,
L_3 ,
V_161 -> V_153 ) ;
goto V_162;
}
V_73 = F_102 ( V_161 , V_9 ) ;
if ( V_73 < 0 )
goto V_163;
V_161 -> V_164 |= V_165 ;
F_97 ( V_156 , V_154 ) ;
F_89 ( V_161 ) ;
return 0 ;
V_163:
F_103 ( V_161 ) ;
V_162:
F_104 ( V_154 ) ;
return V_73 ;
}
static int F_105 ( struct V_31 * V_9 , struct V_31 * V_161 )
{
if ( F_106 ( V_161 ) || F_107 ( V_161 ) )
return - V_109 ;
return F_99 ( V_9 , V_161 ) ;
}
static int F_108 ( struct V_31 * V_9 , struct V_31 * V_161 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
struct V_155 * V_156 = & V_115 -> V_156 ;
struct V_154 * V_154 ;
F_109 ( V_161 , V_9 ) ;
V_161 -> V_164 &= ~ V_165 ;
F_103 ( V_161 ) ;
F_89 ( V_161 ) ;
V_154 = F_93 ( V_156 , V_161 ) ;
if ( V_154 )
F_95 ( V_156 , V_154 ) ;
F_104 ( V_154 ) ;
return 0 ;
}
static int F_110 ( struct V_31 * V_9 , struct V_31 * V_161 )
{
return F_108 ( V_9 , V_161 ) ;
}
static void F_111 ( struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
struct V_155 * V_156 = & V_115 -> V_156 ;
struct V_157 * V_158 = & V_156 -> V_159 ;
struct V_154 * V_154 , * V_166 ;
F_86 ( V_115 ) ;
F_65 ( V_115 ) ;
F_112 (slave, next, head, list)
F_110 ( V_9 , V_154 -> V_9 ) ;
F_67 ( V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
}
static int F_113 ( struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
F_72 ( & V_115 -> V_156 . V_159 ) ;
V_9 -> V_37 = F_114 ( struct V_36 ) ;
if ( ! V_9 -> V_37 )
goto V_167;
V_115 -> V_140 = F_87 ( V_9 ) ;
if ( ! V_115 -> V_140 )
goto V_168;
if ( F_68 ( V_9 ) != 0 )
goto V_169;
V_9 -> V_112 = V_170 | V_171 ;
return 0 ;
V_169:
F_86 ( V_115 ) ;
V_168:
F_67 ( V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
V_167:
return - V_101 ;
}
static T_1 F_115 ( const struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
return V_115 -> V_130 ;
}
static struct V_82 * F_116 ( const struct V_31 * V_9 ,
const struct V_80 * V_81 )
{
struct V_82 * V_140 = NULL ;
if ( ! ( V_81 -> V_93 & V_71 ) ) {
struct V_114 * V_115 = F_69 ( V_9 ) ;
V_140 = V_115 -> V_140 ;
F_117 ( & V_140 -> V_2 . V_131 ) ;
}
return V_140 ;
}
static int F_118 ( struct V_31 * V_9 , struct V_80 * V_81 )
{
struct V_172 V_173 = { . V_174 = 0 } ;
struct V_4 * V_4 = F_24 ( V_9 ) ;
T_1 V_175 = V_81 -> V_91 ;
T_6 V_112 = V_81 -> V_93 ;
T_6 V_176 = V_81 -> V_177 ;
T_6 V_92 = F_119 ( V_81 ) ;
int V_15 ;
if ( F_30 ( ! V_81 -> V_64 ) )
return 0 ;
V_81 -> V_93 |= V_72 ;
V_81 -> V_90 = V_63 ;
V_81 -> V_91 = V_92 & V_178 ;
V_81 -> V_177 = ( ( V_92 & V_179 ) ?
V_95 : V_180 ) ;
V_15 = F_120 ( V_4 , V_81 , & V_173 , 0 ) ;
if ( ! V_15 ) {
if ( V_173 . type == V_86 )
V_81 -> V_65 = V_173 . V_181 -> V_182 ? : V_81 -> V_64 ;
else
F_121 ( V_4 , & V_173 , V_81 , - 1 ) ;
}
V_81 -> V_93 = V_112 ;
V_81 -> V_91 = V_175 ;
V_81 -> V_177 = V_176 ;
return V_15 ;
}
static struct V_1 * F_122 ( const struct V_31 * V_9 ,
const struct V_58 * V_59 )
{
struct V_99 * V_83 = NULL ;
if ( ! ( V_59 -> V_70 & V_71 ) ) {
struct V_114 * V_115 = F_69 ( V_9 ) ;
V_83 = V_115 -> V_116 ;
F_117 ( & V_83 -> V_2 . V_131 ) ;
}
return (struct V_1 * ) V_83 ;
}
static void F_123 ( struct V_31 * V_9 ,
struct V_183 * V_184 )
{
F_124 ( V_184 -> V_185 , V_186 , sizeof( V_184 -> V_185 ) ) ;
F_124 ( V_184 -> V_187 , V_188 , sizeof( V_184 -> V_187 ) ) ;
}
static void F_125 ( struct V_31 * V_9 )
{
F_126 ( V_9 ) ;
V_9 -> V_189 = & V_190 ;
V_9 -> V_191 = & V_192 ;
V_9 -> V_193 = & V_194 ;
V_9 -> V_195 = V_196 ;
F_127 ( V_9 ) ;
V_9 -> V_197 |= V_198 ;
V_9 -> V_197 |= V_199 ;
}
static int F_128 ( struct V_200 * V_201 [] , struct V_200 * V_13 [] )
{
if ( V_201 [ V_202 ] ) {
if ( F_129 ( V_201 [ V_202 ] ) != V_203 )
return - V_109 ;
if ( ! F_130 ( F_131 ( V_201 [ V_202 ] ) ) )
return - V_204 ;
}
return 0 ;
}
static void F_132 ( struct V_31 * V_9 , struct V_157 * V_158 )
{
F_133 ( V_9 , V_158 ) ;
}
static int F_134 ( struct V_4 * V_205 , struct V_31 * V_9 ,
struct V_200 * V_201 [] , struct V_200 * V_13 [] )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
if ( ! V_13 || ! V_13 [ V_206 ] )
return - V_109 ;
V_115 -> V_130 = F_135 ( V_13 [ V_206 ] ) ;
V_9 -> V_164 |= V_207 ;
return F_136 ( V_9 ) ;
}
static T_2 F_137 ( const struct V_31 * V_9 )
{
return F_138 ( sizeof( T_1 ) ) ;
}
static int F_139 ( struct V_7 * V_8 ,
const struct V_31 * V_9 )
{
struct V_114 * V_115 = F_69 ( V_9 ) ;
return F_140 ( V_8 , V_206 , V_115 -> V_130 ) ;
}
static int F_141 ( struct V_208 * V_209 ,
unsigned long V_210 , void * V_211 )
{
struct V_31 * V_9 = F_142 ( V_211 ) ;
if ( V_210 == V_212 ) {
struct V_31 * V_32 ;
if ( ! F_107 ( V_9 ) )
goto V_17;
V_32 = F_143 ( V_9 ) ;
F_110 ( V_32 , V_9 ) ;
}
V_17:
return V_213 ;
}
static int T_7 F_144 ( void )
{
int V_15 ;
V_141 . V_98 =
F_49 ( L_4 ,
sizeof( struct V_82 ) , 0 ,
V_100 ,
NULL ) ;
if ( ! V_141 . V_98 )
return - V_101 ;
V_15 = F_48 () ;
if ( V_15 != 0 )
goto V_214;
F_145 ( & V_215 ) ;
V_15 = F_146 ( & V_216 ) ;
if ( V_15 < 0 )
goto error;
return 0 ;
error:
F_147 ( & V_215 ) ;
F_50 () ;
V_214:
F_51 ( V_141 . V_98 ) ;
return V_15 ;
}
static void T_8 F_148 ( void )
{
F_149 ( & V_216 ) ;
F_147 ( & V_215 ) ;
F_51 ( V_141 . V_98 ) ;
F_50 () ;
}
