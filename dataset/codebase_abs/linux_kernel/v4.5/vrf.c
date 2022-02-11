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
const struct V_11 * V_12 ;
struct V_11 V_13 ;
bool V_14 = true ;
V_12 = F_8 ( V_8 , 0 , sizeof( V_13 ) , & V_13 ) ;
if ( ! V_12 )
goto V_15;
if ( V_12 -> V_16 == V_17 ) {
const struct V_18 * V_19 ;
struct V_18 V_20 ;
V_19 = F_8 ( V_8 , sizeof( V_13 ) ,
sizeof( V_20 ) , & V_20 ) ;
if ( ! V_19 )
goto V_15;
switch ( V_19 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_14 = false ;
break;
}
}
V_15:
return V_14 ;
}
static bool F_7 ( const struct V_7 * V_8 )
{
return false ;
}
static bool F_9 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_27 ) {
case F_10 ( V_28 ) :
return true ;
case F_10 ( V_29 ) :
return F_7 ( V_8 ) ;
}
return false ;
}
static void F_11 ( struct V_30 * V_31 , struct V_7 * V_8 )
{
V_31 -> V_32 . V_33 ++ ;
F_12 ( V_8 ) ;
}
static T_2 F_13 ( struct V_7 * * V_34 )
{
struct V_7 * V_8 = * V_34 ;
if ( F_9 ( V_8 ) ) {
struct V_30 * V_9 = F_14 ( V_8 -> V_9 ) ;
struct V_35 * V_36 = F_15 ( V_9 -> V_36 ) ;
F_16 ( & V_36 -> V_37 ) ;
V_36 -> V_38 ++ ;
V_36 -> V_39 += V_8 -> V_40 ;
F_17 ( & V_36 -> V_37 ) ;
V_8 -> V_9 = V_9 ;
return V_41 ;
}
return V_42 ;
}
static struct V_43 * F_18 ( struct V_30 * V_9 ,
struct V_43 * V_32 )
{
int V_44 ;
F_19 (i) {
const struct V_35 * V_36 ;
T_3 V_45 , V_46 , V_47 , V_48 , V_49 ;
unsigned int V_50 ;
V_36 = F_20 ( V_9 -> V_36 , V_44 ) ;
do {
V_50 = F_21 ( & V_36 -> V_37 ) ;
V_45 = V_36 -> V_51 ;
V_46 = V_36 -> V_52 ;
V_47 = V_36 -> V_53 ;
V_48 = V_36 -> V_39 ;
V_49 = V_36 -> V_38 ;
} while ( F_22 ( & V_36 -> V_37 , V_50 ) );
V_32 -> V_51 += V_45 ;
V_32 -> V_54 += V_46 ;
V_32 -> V_55 += V_47 ;
V_32 -> V_39 += V_48 ;
V_32 -> V_56 += V_49 ;
}
return V_32 ;
}
static T_4 F_23 ( struct V_7 * V_8 ,
struct V_30 * V_9 )
{
const struct V_11 * V_57 = F_24 ( V_8 ) ;
struct V_4 * V_4 = F_25 ( V_8 -> V_9 ) ;
struct V_58 V_59 = {
. V_60 = V_9 -> V_61 ,
. V_62 = V_63 ,
. V_64 = V_57 -> V_64 ,
. V_65 = V_57 -> V_65 ,
. V_66 = F_26 ( V_57 ) ,
. V_67 = V_8 -> V_68 ,
. V_69 = V_57 -> V_16 ,
. V_70 = V_71 | V_72 ,
} ;
int V_73 = V_74 ;
struct V_1 * V_2 ;
struct V_1 * V_75 = & V_4 -> V_76 . V_77 -> V_2 ;
V_2 = F_27 ( V_4 , NULL , & V_59 ) ;
if ( V_2 == V_75 )
goto V_78;
F_28 ( V_8 ) ;
F_29 ( V_8 , V_2 ) ;
V_73 = F_30 ( V_4 , V_8 -> V_6 , V_8 ) ;
if ( F_31 ( F_32 ( V_73 ) ) )
V_9 -> V_32 . V_33 ++ ;
else
V_73 = V_79 ;
return V_73 ;
V_78:
F_11 ( V_9 , V_8 ) ;
return V_74 ;
}
static T_4 F_23 ( struct V_7 * V_8 ,
struct V_30 * V_9 )
{
F_11 ( V_9 , V_8 ) ;
return V_74 ;
}
static int F_33 ( struct V_7 * V_8 , struct V_80 * V_81 ,
struct V_30 * V_31 )
{
struct V_82 * V_83 ;
int V_78 = 1 ;
V_83 = F_34 ( F_25 ( V_31 ) , V_81 , NULL ) ;
if ( F_35 ( V_83 ) )
goto V_15;
if ( V_83 -> V_84 != V_85 && V_83 -> V_84 != V_86 ) {
F_36 ( V_83 ) ;
goto V_15;
}
F_28 ( V_8 ) ;
F_29 ( V_8 , & V_83 -> V_2 ) ;
V_78 = 0 ;
V_15:
return V_78 ;
}
static T_4 F_37 ( struct V_7 * V_8 ,
struct V_30 * V_31 )
{
struct V_87 * V_88 = F_38 ( V_8 ) ;
int V_73 = V_74 ;
struct V_80 V_81 = {
. V_89 = V_31 -> V_61 ,
. V_90 = V_63 ,
. V_91 = F_39 ( V_88 -> V_92 ) ,
. V_93 = V_94 | V_71 |
V_72 ,
. V_64 = V_88 -> V_64 ,
} ;
if ( F_33 ( V_8 , & V_81 , V_31 ) )
goto V_78;
if ( ! V_88 -> V_65 ) {
V_88 -> V_65 = F_40 ( F_41 ( V_8 ) -> V_9 , 0 ,
V_95 ) ;
}
V_73 = F_3 ( F_25 ( F_41 ( V_8 ) -> V_9 ) , V_8 -> V_6 , V_8 ) ;
if ( F_31 ( F_32 ( V_73 ) ) )
V_31 -> V_32 . V_33 ++ ;
else
V_73 = V_79 ;
V_15:
return V_73 ;
V_78:
F_11 ( V_31 , V_8 ) ;
goto V_15;
}
static T_4 F_42 ( struct V_7 * V_8 , struct V_30 * V_9 )
{
F_43 ( V_8 , F_44 ( V_8 ) ) ;
switch ( V_8 -> V_27 ) {
case F_10 ( V_28 ) :
return F_37 ( V_8 , V_9 ) ;
case F_10 ( V_29 ) :
return F_23 ( V_8 , V_9 ) ;
default:
F_11 ( V_9 , V_8 ) ;
return V_74 ;
}
}
static T_4 F_45 ( struct V_7 * V_8 , struct V_30 * V_9 )
{
T_4 V_73 = F_42 ( V_8 , V_9 ) ;
if ( F_46 ( V_73 == V_79 || V_73 == V_96 ) ) {
struct V_35 * V_36 = F_15 ( V_9 -> V_36 ) ;
F_16 ( & V_36 -> V_37 ) ;
V_36 -> V_52 ++ ;
V_36 -> V_51 += V_8 -> V_40 ;
F_17 ( & V_36 -> V_37 ) ;
} else {
F_47 ( V_9 -> V_36 -> V_53 ) ;
}
return V_73 ;
}
static struct V_1 * F_48 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 ;
}
static int F_49 ( void )
{
V_97 . V_98 = F_50 ( L_1 ,
sizeof( struct V_99 ) ,
0 ,
V_100 ,
NULL ) ;
if ( ! V_97 . V_98 )
return - V_101 ;
return 0 ;
}
static void F_51 ( void )
{
F_52 ( V_97 . V_98 ) ;
}
static int F_53 ( struct V_7 * V_8 )
{
V_8 -> V_9 -> V_32 . V_102 ++ ;
F_12 ( V_8 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
struct V_30 * V_9 = V_2 -> V_9 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_73 ;
V_8 -> V_27 = F_10 ( V_29 ) ;
V_8 -> V_9 = V_9 ;
F_55 () ;
V_106 = F_56 ( (struct V_99 * ) V_2 , & F_24 ( V_8 ) -> V_64 ) ;
V_104 = F_57 ( V_2 -> V_9 , V_106 ) ;
if ( F_31 ( ! V_104 ) )
V_104 = F_58 ( & V_107 , V_106 , V_2 -> V_9 , false ) ;
if ( ! F_35 ( V_104 ) ) {
V_73 = F_59 ( V_2 , V_104 , V_8 ) ;
F_60 () ;
return V_73 ;
}
F_60 () ;
F_61 ( F_25 ( V_2 -> V_9 ) ,
F_62 ( V_2 ) , V_108 ) ;
F_12 ( V_8 ) ;
return - V_109 ;
}
static int F_63 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
return F_64 ( V_110 , V_111 ,
V_4 , V_6 , V_8 , NULL , F_41 ( V_8 ) -> V_9 ,
F_54 ,
! ( F_65 ( V_8 ) -> V_112 & V_113 ) ) ;
}
static void F_66 ( struct V_114 * V_115 )
{
F_67 ( & V_115 -> V_116 -> V_2 ) ;
F_68 ( V_115 -> V_116 -> V_117 ) ;
V_115 -> V_116 = NULL ;
}
static int F_69 ( struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_99 * V_116 ;
int V_118 ;
int V_14 = - V_101 ;
V_116 = F_71 ( & V_97 , V_9 , 0 ,
V_119 ,
( V_120 | V_121 | V_122 ) ) ;
if ( ! V_116 )
goto V_15;
V_2 = & V_116 -> V_2 ;
V_116 -> V_117 = F_72 ( struct V_99 * , V_123 ) ;
if ( ! V_116 -> V_117 ) {
F_67 ( V_2 ) ;
goto V_15;
}
F_19 (cpu) {
struct V_99 * * V_124 = F_20 ( V_116 -> V_117 , V_118 ) ;
* V_124 = NULL ;
}
memset ( V_2 + 1 , 0 , sizeof( * V_116 ) - sizeof( * V_2 ) ) ;
F_73 ( & V_116 -> V_125 ) ;
F_73 ( & V_116 -> V_126 ) ;
V_116 -> V_2 . V_127 = F_53 ;
V_116 -> V_2 . V_128 = F_63 ;
V_116 -> V_129 = F_74 ( F_25 ( V_9 ) , V_115 -> V_130 ) ;
F_75 ( & V_116 -> V_2 . V_131 , 2 ) ;
V_115 -> V_116 = V_116 ;
V_14 = 0 ;
V_15:
return V_14 ;
}
static int F_49 ( void )
{
return 0 ;
}
static void F_51 ( void )
{
}
static void F_66 ( struct V_114 * V_115 )
{
}
static int F_69 ( struct V_30 * V_9 )
{
return 0 ;
}
static int F_76 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_2 ;
struct V_30 * V_9 = V_2 -> V_9 ;
unsigned int V_132 = F_77 ( V_9 ) ;
struct V_103 * V_104 ;
T_1 V_106 ;
int V_73 = - V_109 ;
if ( F_31 ( F_78 ( V_8 ) < V_132 && V_9 -> V_133 ) ) {
struct V_7 * V_134 ;
V_134 = F_79 ( V_8 , F_77 ( V_9 ) ) ;
if ( ! V_134 ) {
V_73 = - V_101 ;
goto V_78;
}
if ( V_8 -> V_6 )
F_80 ( V_134 , V_8 -> V_6 ) ;
F_81 ( V_8 ) ;
V_8 = V_134 ;
}
F_55 () ;
V_106 = ( V_135 T_1 ) F_82 ( V_83 , F_38 ( V_8 ) -> V_64 ) ;
V_104 = F_83 ( V_9 , V_106 ) ;
if ( F_31 ( ! V_104 ) )
V_104 = F_58 ( & V_136 , & V_106 , V_9 , false ) ;
if ( ! F_35 ( V_104 ) )
V_73 = F_59 ( V_2 , V_104 , V_8 ) ;
F_60 () ;
V_78:
if ( F_31 ( V_73 < 0 ) )
F_11 ( V_8 -> V_9 , V_8 ) ;
return V_73 ;
}
static int F_84 ( struct V_4 * V_4 , struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_30 * V_9 = F_41 ( V_8 ) -> V_9 ;
F_85 ( V_4 , V_137 , V_8 -> V_40 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_27 = F_10 ( V_28 ) ;
return F_64 ( V_138 , V_111 ,
V_4 , V_6 , V_8 , NULL , V_9 ,
F_76 ,
! ( F_86 ( V_8 ) -> V_112 & V_139 ) ) ;
}
static void F_87 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 -> V_140 ;
F_67 ( V_2 ) ;
V_115 -> V_140 = NULL ;
}
static struct V_82 * F_88 ( struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
struct V_82 * V_140 ;
V_140 = F_71 ( & V_141 , V_9 , 2 ,
V_119 ,
( V_120 | V_121 | V_122 ) ) ;
if ( V_140 ) {
V_140 -> V_2 . V_128 = F_84 ;
V_140 -> V_142 = F_89 ( F_25 ( V_9 ) ) ;
V_140 -> V_143 = 0 ;
V_140 -> V_84 = V_85 ;
V_140 -> V_144 = 0 ;
V_140 -> V_145 = 0 ;
V_140 -> V_146 = 0 ;
V_140 -> V_147 = 0 ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = V_115 -> V_130 ;
F_73 ( & V_140 -> V_150 ) ;
V_140 -> V_151 = NULL ;
}
return V_140 ;
}
static void F_90 ( struct V_30 * V_9 )
{
unsigned int V_112 = V_9 -> V_112 ;
int V_73 ;
if ( ! F_91 ( V_9 ) )
return;
V_73 = F_92 ( V_9 , V_112 & ~ V_152 ) ;
if ( V_73 >= 0 )
V_73 = F_92 ( V_9 , V_112 ) ;
if ( V_73 < 0 ) {
F_93 ( V_9 ,
L_2 ,
V_9 -> V_153 ) ;
}
}
static int F_94 ( struct V_30 * V_9 , struct V_30 * V_154 )
{
int V_73 ;
V_73 = F_95 ( V_154 , F_13 , V_9 ) ;
if ( V_73 ) {
F_93 ( V_154 ,
L_3 ,
V_154 -> V_153 ) ;
goto V_155;
}
V_73 = F_96 ( V_154 , V_9 , NULL , NULL ) ;
if ( V_73 < 0 )
goto V_156;
V_154 -> V_157 |= V_158 ;
F_90 ( V_154 ) ;
return 0 ;
V_156:
F_97 ( V_154 ) ;
V_155:
return V_73 ;
}
static int F_98 ( struct V_30 * V_9 , struct V_30 * V_154 )
{
if ( F_99 ( V_154 ) || F_100 ( V_154 ) )
return - V_109 ;
return F_94 ( V_9 , V_154 ) ;
}
static int F_101 ( struct V_30 * V_9 , struct V_30 * V_154 )
{
F_102 ( V_154 , V_9 ) ;
V_154 -> V_157 &= ~ V_158 ;
F_97 ( V_154 ) ;
F_90 ( V_154 ) ;
return 0 ;
}
static int F_103 ( struct V_30 * V_9 , struct V_30 * V_154 )
{
return F_101 ( V_9 , V_154 ) ;
}
static void F_104 ( struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
struct V_30 * V_154 ;
struct V_159 * V_160 ;
F_87 ( V_115 ) ;
F_66 ( V_115 ) ;
F_105 (dev, port_dev, iter)
F_103 ( V_9 , V_154 ) ;
F_68 ( V_9 -> V_36 ) ;
V_9 -> V_36 = NULL ;
}
static int F_106 ( struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
V_9 -> V_36 = F_107 ( struct V_35 ) ;
if ( ! V_9 -> V_36 )
goto V_161;
V_115 -> V_140 = F_88 ( V_9 ) ;
if ( ! V_115 -> V_140 )
goto V_162;
if ( F_69 ( V_9 ) != 0 )
goto V_163;
V_9 -> V_112 = V_164 | V_165 ;
return 0 ;
V_163:
F_87 ( V_115 ) ;
V_162:
F_68 ( V_9 -> V_36 ) ;
V_9 -> V_36 = NULL ;
V_161:
return - V_101 ;
}
static T_1 F_108 ( const struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
return V_115 -> V_130 ;
}
static struct V_82 * F_109 ( const struct V_30 * V_9 ,
const struct V_80 * V_81 )
{
struct V_82 * V_140 = NULL ;
if ( ! ( V_81 -> V_93 & V_71 ) ) {
struct V_114 * V_115 = F_70 ( V_9 ) ;
V_140 = V_115 -> V_140 ;
F_110 ( & V_140 -> V_2 . V_131 ) ;
}
return V_140 ;
}
static int F_111 ( struct V_30 * V_9 , struct V_80 * V_81 )
{
struct V_166 V_167 = { . V_168 = 0 } ;
struct V_4 * V_4 = F_25 ( V_9 ) ;
T_1 V_169 = V_81 -> V_91 ;
T_5 V_112 = V_81 -> V_93 ;
T_5 V_170 = V_81 -> V_171 ;
T_5 V_92 = F_112 ( V_81 ) ;
int V_14 ;
if ( F_31 ( ! V_81 -> V_64 ) )
return 0 ;
V_81 -> V_93 |= V_72 ;
V_81 -> V_90 = V_63 ;
V_81 -> V_91 = V_92 & V_172 ;
V_81 -> V_171 = ( ( V_92 & V_173 ) ?
V_95 : V_174 ) ;
V_14 = F_113 ( V_4 , V_81 , & V_167 , 0 ) ;
if ( ! V_14 ) {
if ( V_167 . type == V_86 )
V_81 -> V_65 = V_167 . V_175 -> V_176 ? : V_81 -> V_64 ;
else
F_114 ( V_4 , & V_167 , V_81 , - 1 ) ;
}
V_81 -> V_93 = V_112 ;
V_81 -> V_91 = V_169 ;
V_81 -> V_171 = V_170 ;
return V_14 ;
}
static struct V_1 * F_115 ( const struct V_30 * V_9 ,
const struct V_58 * V_59 )
{
struct V_99 * V_83 = NULL ;
if ( ! ( V_59 -> V_70 & V_71 ) ) {
struct V_114 * V_115 = F_70 ( V_9 ) ;
V_83 = V_115 -> V_116 ;
F_110 ( & V_83 -> V_2 . V_131 ) ;
}
return (struct V_1 * ) V_83 ;
}
static void F_116 ( struct V_30 * V_9 ,
struct V_177 * V_178 )
{
F_117 ( V_178 -> V_179 , V_180 , sizeof( V_178 -> V_179 ) ) ;
F_117 ( V_178 -> V_181 , V_182 , sizeof( V_178 -> V_181 ) ) ;
}
static void F_118 ( struct V_30 * V_9 )
{
F_119 ( V_9 ) ;
V_9 -> V_183 = & V_184 ;
V_9 -> V_185 = & V_186 ;
V_9 -> V_187 = & V_188 ;
V_9 -> V_189 = V_190 ;
F_120 ( V_9 ) ;
V_9 -> V_191 |= V_192 ;
V_9 -> V_191 |= V_193 ;
}
static int F_121 ( struct V_194 * V_195 [] , struct V_194 * V_196 [] )
{
if ( V_195 [ V_197 ] ) {
if ( F_122 ( V_195 [ V_197 ] ) != V_198 )
return - V_109 ;
if ( ! F_123 ( F_124 ( V_195 [ V_197 ] ) ) )
return - V_199 ;
}
return 0 ;
}
static void F_125 ( struct V_30 * V_9 , struct V_159 * V_200 )
{
F_126 ( V_9 , V_200 ) ;
}
static int F_127 ( struct V_4 * V_201 , struct V_30 * V_9 ,
struct V_194 * V_195 [] , struct V_194 * V_196 [] )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
if ( ! V_196 || ! V_196 [ V_202 ] )
return - V_109 ;
V_115 -> V_130 = F_128 ( V_196 [ V_202 ] ) ;
V_9 -> V_157 |= V_203 ;
return F_129 ( V_9 ) ;
}
static T_6 F_130 ( const struct V_30 * V_9 )
{
return F_131 ( sizeof( T_1 ) ) ;
}
static int F_132 ( struct V_7 * V_8 ,
const struct V_30 * V_9 )
{
struct V_114 * V_115 = F_70 ( V_9 ) ;
return F_133 ( V_8 , V_202 , V_115 -> V_130 ) ;
}
static int F_134 ( struct V_204 * V_205 ,
unsigned long V_206 , void * V_207 )
{
struct V_30 * V_9 = F_135 ( V_207 ) ;
if ( V_206 == V_208 ) {
struct V_30 * V_31 ;
if ( ! F_100 ( V_9 ) )
goto V_15;
V_31 = F_136 ( V_9 ) ;
F_103 ( V_31 , V_9 ) ;
}
V_15:
return V_209 ;
}
static int T_7 F_137 ( void )
{
int V_14 ;
V_141 . V_98 =
F_50 ( L_4 ,
sizeof( struct V_82 ) , 0 ,
V_100 ,
NULL ) ;
if ( ! V_141 . V_98 )
return - V_101 ;
V_14 = F_49 () ;
if ( V_14 != 0 )
goto V_210;
F_138 ( & V_211 ) ;
V_14 = F_139 ( & V_212 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_140 ( & V_211 ) ;
F_51 () ;
V_210:
F_52 ( V_141 . V_98 ) ;
return V_14 ;
}
static void T_8 F_141 ( void )
{
F_142 ( & V_212 ) ;
F_140 ( & V_211 ) ;
F_52 ( V_141 . V_98 ) ;
F_51 () ;
}
