static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 . V_6 ++ ;
F_2 ( V_4 ) ;
}
static struct V_7 * F_3 ( struct V_1 * V_8 ,
struct V_7 * V_5 )
{
int V_9 ;
F_4 (i) {
const struct V_10 * V_11 ;
T_1 V_12 , V_13 , V_14 , V_15 , V_16 ;
unsigned int V_17 ;
V_11 = F_5 ( V_8 -> V_11 , V_9 ) ;
do {
V_17 = F_6 ( & V_11 -> V_18 ) ;
V_12 = V_11 -> V_19 ;
V_13 = V_11 -> V_20 ;
V_14 = V_11 -> V_21 ;
V_15 = V_11 -> V_22 ;
V_16 = V_11 -> V_23 ;
} while ( F_7 ( & V_11 -> V_18 , V_17 ) );
V_5 -> V_19 += V_12 ;
V_5 -> V_24 += V_13 ;
V_5 -> V_25 += V_14 ;
V_5 -> V_22 += V_15 ;
V_5 -> V_26 += V_16 ;
}
return V_5 ;
}
static T_2 F_8 ( struct V_3 * V_4 ,
struct V_1 * V_8 )
{
const struct V_27 * V_28 = F_9 ( V_4 ) ;
struct V_29 * V_29 = F_10 ( V_4 -> V_8 ) ;
struct V_30 V_31 = {
. V_32 = V_8 -> V_33 ,
. V_34 = V_35 ,
. V_36 = V_28 -> V_36 ,
. V_37 = V_28 -> V_37 ,
. V_38 = F_11 ( V_28 ) ,
. V_39 = V_4 -> V_40 ,
. V_41 = V_28 -> V_42 ,
. V_43 = V_44 | V_45 ,
} ;
int V_46 = V_47 ;
struct V_48 * V_49 ;
struct V_48 * V_50 = & V_29 -> V_51 . V_52 -> V_49 ;
V_49 = F_12 ( V_29 , NULL , & V_31 ) ;
if ( V_49 == V_50 )
goto V_53;
F_13 ( V_4 ) ;
F_14 ( V_4 , V_49 ) ;
V_46 = F_15 ( V_29 , V_4 -> V_54 , V_4 ) ;
if ( F_16 ( F_17 ( V_46 ) ) )
V_8 -> V_5 . V_6 ++ ;
else
V_46 = V_55 ;
return V_46 ;
V_53:
F_1 ( V_8 , V_4 ) ;
return V_47 ;
}
static T_2 F_8 ( struct V_3 * V_4 ,
struct V_1 * V_8 )
{
F_1 ( V_8 , V_4 ) ;
return V_47 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_56 * V_57 ,
struct V_1 * V_2 )
{
struct V_58 * V_59 ;
int V_53 = 1 ;
V_59 = F_19 ( F_10 ( V_2 ) , V_57 , NULL ) ;
if ( F_20 ( V_59 ) )
goto V_60;
if ( V_59 -> V_61 != V_62 && V_59 -> V_61 != V_63 ) {
F_21 ( V_59 ) ;
goto V_60;
}
F_13 ( V_4 ) ;
F_14 ( V_4 , & V_59 -> V_49 ) ;
V_53 = 0 ;
V_60:
return V_53 ;
}
static T_2 F_22 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_64 * V_65 = F_23 ( V_4 ) ;
int V_46 = V_47 ;
struct V_56 V_57 = {
. V_66 = V_2 -> V_33 ,
. V_67 = V_35 ,
. V_68 = F_24 ( V_65 -> V_69 ) ,
. V_70 = V_71 | V_44 |
V_45 ,
. V_36 = V_65 -> V_36 ,
} ;
if ( F_18 ( V_4 , & V_57 , V_2 ) )
goto V_53;
if ( ! V_65 -> V_37 ) {
V_65 -> V_37 = F_25 ( F_26 ( V_4 ) -> V_8 , 0 ,
V_72 ) ;
}
V_46 = F_27 ( F_10 ( F_26 ( V_4 ) -> V_8 ) , V_4 -> V_54 , V_4 ) ;
if ( F_16 ( F_17 ( V_46 ) ) )
V_2 -> V_5 . V_6 ++ ;
else
V_46 = V_55 ;
V_60:
return V_46 ;
V_53:
F_1 ( V_2 , V_4 ) ;
goto V_60;
}
static T_2 F_28 ( struct V_3 * V_4 , struct V_1 * V_8 )
{
F_29 ( V_4 , F_30 ( V_4 ) ) ;
switch ( V_4 -> V_73 ) {
case F_31 ( V_74 ) :
return F_22 ( V_4 , V_8 ) ;
case F_31 ( V_75 ) :
return F_8 ( V_4 , V_8 ) ;
default:
F_1 ( V_8 , V_4 ) ;
return V_47 ;
}
}
static T_2 F_32 ( struct V_3 * V_4 , struct V_1 * V_8 )
{
T_2 V_46 = F_28 ( V_4 , V_8 ) ;
if ( F_33 ( V_46 == V_55 || V_46 == V_76 ) ) {
struct V_10 * V_11 = F_34 ( V_8 -> V_11 ) ;
F_35 ( & V_11 -> V_18 ) ;
V_11 -> V_20 ++ ;
V_11 -> V_19 += V_4 -> V_77 ;
F_36 ( & V_11 -> V_18 ) ;
} else {
F_37 ( V_8 -> V_11 -> V_21 ) ;
}
return V_46 ;
}
static int F_38 ( struct V_29 * V_29 , struct V_78 * V_54 ,
struct V_3 * V_4 )
{
struct V_48 * V_49 = F_26 ( V_4 ) ;
struct V_1 * V_8 = V_49 -> V_8 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_46 ;
V_4 -> V_73 = F_31 ( V_75 ) ;
V_4 -> V_8 = V_8 ;
F_39 () ;
V_82 = F_40 ( (struct V_83 * ) V_49 , & F_9 ( V_4 ) -> V_36 ) ;
V_80 = F_41 ( V_49 -> V_8 , V_82 ) ;
if ( F_16 ( ! V_80 ) )
V_80 = F_42 ( & V_84 , V_82 , V_49 -> V_8 , false ) ;
if ( ! F_20 ( V_80 ) ) {
V_46 = F_43 ( V_49 , V_80 , V_4 ) ;
F_44 () ;
return V_46 ;
}
F_44 () ;
F_45 ( F_10 ( V_49 -> V_8 ) ,
F_46 ( V_49 ) , V_85 ) ;
F_2 ( V_4 ) ;
return - V_86 ;
}
static int F_47 ( struct V_29 * V_29 , struct V_78 * V_54 , struct V_3 * V_4 )
{
return F_48 ( V_87 , V_88 ,
V_29 , V_54 , V_4 , NULL , F_26 ( V_4 ) -> V_8 ,
F_38 ,
! ( F_49 ( V_4 ) -> V_89 & V_90 ) ) ;
}
static void F_50 ( struct V_91 * V_92 )
{
struct V_83 * V_93 = F_51 ( V_92 -> V_93 ) ;
F_52 ( V_92 -> V_93 , NULL ) ;
if ( V_93 )
F_53 ( & V_93 -> V_49 ) ;
}
static int F_54 ( struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
struct V_29 * V_29 = F_10 ( V_8 ) ;
struct V_94 * V_95 ;
struct V_83 * V_93 ;
int V_96 = - V_97 ;
V_95 = F_56 ( V_29 , V_92 -> V_98 ) ;
if ( ! V_95 )
goto V_60;
V_93 = F_57 ( V_29 , V_8 ,
V_99 | V_100 | V_101 | V_102 ) ;
if ( ! V_93 )
goto V_60;
F_58 ( & V_93 -> V_49 ) ;
V_93 -> V_95 = V_95 ;
V_93 -> V_49 . V_103 = F_47 ;
F_52 ( V_92 -> V_93 , V_93 ) ;
V_96 = 0 ;
V_60:
return V_96 ;
}
static void F_50 ( struct V_91 * V_92 )
{
}
static int F_54 ( struct V_1 * V_8 )
{
return 0 ;
}
static int F_59 ( struct V_29 * V_29 , struct V_78 * V_54 , struct V_3 * V_4 )
{
struct V_48 * V_49 = F_26 ( V_4 ) ;
struct V_58 * V_59 = (struct V_58 * ) V_49 ;
struct V_1 * V_8 = V_49 -> V_8 ;
unsigned int V_104 = F_60 ( V_8 ) ;
struct V_79 * V_80 ;
T_3 V_82 ;
int V_46 = - V_86 ;
if ( F_16 ( F_61 ( V_4 ) < V_104 && V_8 -> V_105 ) ) {
struct V_3 * V_106 ;
V_106 = F_62 ( V_4 , F_60 ( V_8 ) ) ;
if ( ! V_106 ) {
V_46 = - V_97 ;
goto V_53;
}
if ( V_4 -> V_54 )
F_63 ( V_106 , V_4 -> V_54 ) ;
F_64 ( V_4 ) ;
V_4 = V_106 ;
}
F_39 () ;
V_82 = ( V_107 T_3 ) F_65 ( V_59 , F_23 ( V_4 ) -> V_36 ) ;
V_80 = F_66 ( V_8 , V_82 ) ;
if ( F_16 ( ! V_80 ) )
V_80 = F_42 ( & V_108 , & V_82 , V_8 , false ) ;
if ( ! F_20 ( V_80 ) )
V_46 = F_43 ( V_49 , V_80 , V_4 ) ;
F_44 () ;
V_53:
if ( F_16 ( V_46 < 0 ) )
F_1 ( V_4 -> V_8 , V_4 ) ;
return V_46 ;
}
static int F_67 ( struct V_29 * V_29 , struct V_78 * V_54 , struct V_3 * V_4 )
{
struct V_1 * V_8 = F_26 ( V_4 ) -> V_8 ;
F_68 ( V_29 , V_109 , V_4 -> V_77 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_73 = F_31 ( V_74 ) ;
return F_48 ( V_110 , V_88 ,
V_29 , V_54 , V_4 , NULL , V_8 ,
F_59 ,
! ( F_69 ( V_4 ) -> V_89 & V_111 ) ) ;
}
static void F_70 ( struct V_91 * V_92 )
{
struct V_58 * V_112 = F_51 ( V_92 -> V_112 ) ;
F_52 ( V_92 -> V_112 , NULL ) ;
if ( V_112 )
F_53 ( & V_112 -> V_49 ) ;
}
static int F_71 ( struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
struct V_58 * V_112 ;
if ( ! F_72 ( F_10 ( V_8 ) , V_92 -> V_98 ) )
return - V_97 ;
V_112 = F_73 ( V_8 , 0 , V_62 , 1 , 1 , 0 ) ;
if ( ! V_112 )
return - V_97 ;
V_112 -> V_49 . V_103 = F_67 ;
V_112 -> V_113 = V_92 -> V_98 ;
F_52 ( V_92 -> V_112 , V_112 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_8 )
{
unsigned int V_89 = V_8 -> V_89 ;
int V_46 ;
if ( ! F_75 ( V_8 ) )
return;
V_46 = F_76 ( V_8 , V_89 & ~ V_114 ) ;
if ( V_46 >= 0 )
V_46 = F_76 ( V_8 , V_89 ) ;
if ( V_46 < 0 ) {
F_77 ( V_8 ,
L_1 ,
V_8 -> V_115 ) ;
}
}
static int F_78 ( struct V_1 * V_8 , struct V_1 * V_116 )
{
int V_46 ;
V_46 = F_79 ( V_116 , V_8 , NULL , NULL ) ;
if ( V_46 < 0 )
return V_46 ;
V_116 -> V_117 |= V_118 ;
F_74 ( V_116 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_8 , struct V_1 * V_116 )
{
if ( F_81 ( V_116 ) || F_82 ( V_116 ) )
return - V_86 ;
return F_78 ( V_8 , V_116 ) ;
}
static int F_83 ( struct V_1 * V_8 , struct V_1 * V_116 )
{
F_84 ( V_116 , V_8 ) ;
V_116 -> V_117 &= ~ V_118 ;
F_74 ( V_116 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_8 , struct V_1 * V_116 )
{
return F_83 ( V_8 , V_116 ) ;
}
static void F_86 ( struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
struct V_1 * V_116 ;
struct V_119 * V_120 ;
F_70 ( V_92 ) ;
F_50 ( V_92 ) ;
F_87 (dev, port_dev, iter)
F_85 ( V_8 , V_116 ) ;
F_88 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
}
static int F_89 ( struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
V_8 -> V_11 = F_90 ( struct V_10 ) ;
if ( ! V_8 -> V_11 )
goto V_121;
if ( F_71 ( V_8 ) != 0 )
goto V_122;
if ( F_54 ( V_8 ) != 0 )
goto V_123;
V_8 -> V_89 = V_124 | V_125 ;
return 0 ;
V_123:
F_70 ( V_92 ) ;
V_122:
F_88 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
V_121:
return - V_97 ;
}
static T_3 F_91 ( const struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
return V_92 -> V_98 ;
}
static struct V_58 * F_92 ( const struct V_1 * V_8 ,
const struct V_56 * V_57 )
{
struct V_58 * V_112 = NULL ;
if ( ! ( V_57 -> V_70 & V_44 ) ) {
struct V_91 * V_92 = F_55 ( V_8 ) ;
F_93 () ;
V_112 = F_94 ( V_92 -> V_112 ) ;
if ( F_33 ( V_112 ) )
F_58 ( & V_112 -> V_49 ) ;
F_95 () ;
}
return V_112 ;
}
static int F_96 ( struct V_1 * V_8 , struct V_56 * V_57 )
{
struct V_126 V_127 = { . V_128 = 0 } ;
struct V_29 * V_29 = F_10 ( V_8 ) ;
T_3 V_129 = V_57 -> V_68 ;
T_4 V_89 = V_57 -> V_70 ;
T_4 V_130 = V_57 -> V_131 ;
T_4 V_69 = F_97 ( V_57 ) ;
int V_96 ;
if ( F_16 ( ! V_57 -> V_36 ) )
return 0 ;
V_57 -> V_70 |= V_45 ;
V_57 -> V_67 = V_35 ;
V_57 -> V_66 = V_8 -> V_33 ;
V_57 -> V_68 = V_69 & V_132 ;
V_57 -> V_131 = ( ( V_69 & V_133 ) ?
V_72 : V_134 ) ;
V_96 = F_98 ( V_29 , V_57 , & V_127 , 0 ) ;
if ( ! V_96 ) {
if ( V_127 . type == V_63 )
V_57 -> V_37 = V_127 . V_135 -> V_136 ? : V_57 -> V_36 ;
else
F_99 ( V_29 , & V_127 , V_57 , - 1 ) ;
}
V_57 -> V_70 = V_89 ;
V_57 -> V_68 = V_129 ;
V_57 -> V_131 = V_130 ;
return V_96 ;
}
static bool F_100 ( const struct V_3 * V_4 )
{
const struct V_27 * V_28 = F_9 ( V_4 ) ;
bool V_96 = false ;
if ( V_28 -> V_42 == V_137 ) {
const struct V_138 * V_139 ;
struct V_138 V_140 ;
V_139 = F_101 ( V_4 , sizeof( * V_28 ) ,
sizeof( V_140 ) , & V_140 ) ;
if ( ! V_139 )
goto V_60;
switch ( V_139 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_96 = true ;
break;
}
}
V_60:
return V_96 ;
}
static struct V_3 * F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_100 ( V_4 ) ) {
V_4 -> V_8 = V_2 ;
V_4 -> V_147 = V_2 -> V_33 ;
F_103 ( V_4 , V_4 -> V_148 ) ;
F_104 ( V_4 , V_2 ) ;
F_105 ( V_4 , V_4 -> V_148 ) ;
F_49 ( V_4 ) -> V_89 |= V_149 ;
}
return V_4 ;
}
static struct V_3 * F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_4 ;
}
static struct V_3 * F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_8 = V_2 ;
V_4 -> V_147 = V_2 -> V_33 ;
F_103 ( V_4 , V_4 -> V_148 ) ;
F_104 ( V_4 , V_2 ) ;
F_105 ( V_4 , V_4 -> V_148 ) ;
return V_4 ;
}
static struct V_3 * F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_5 V_150 )
{
switch ( V_150 ) {
case V_151 :
return F_106 ( V_2 , V_4 ) ;
case V_152 :
return F_102 ( V_2 , V_4 ) ;
}
return V_4 ;
}
static struct V_48 * F_108 ( const struct V_1 * V_8 ,
const struct V_30 * V_31 )
{
struct V_48 * V_49 = NULL ;
if ( ! ( V_31 -> V_43 & V_44 ) ) {
struct V_91 * V_92 = F_55 ( V_8 ) ;
struct V_83 * V_59 ;
F_93 () ;
V_59 = F_94 ( V_92 -> V_93 ) ;
if ( F_33 ( V_59 ) ) {
V_49 = & V_59 -> V_49 ;
F_58 ( V_49 ) ;
}
F_95 () ;
}
return V_49 ;
}
static void F_109 ( struct V_1 * V_8 ,
struct V_153 * V_154 )
{
F_110 ( V_154 -> V_155 , V_156 , sizeof( V_154 -> V_155 ) ) ;
F_110 ( V_154 -> V_157 , V_158 , sizeof( V_154 -> V_157 ) ) ;
}
static void F_111 ( struct V_1 * V_8 )
{
F_112 ( V_8 ) ;
V_8 -> V_159 = & V_160 ;
V_8 -> V_161 = & V_162 ;
V_8 -> V_163 = & V_164 ;
V_8 -> V_165 = V_166 ;
F_113 ( V_8 ) ;
V_8 -> V_167 |= V_168 ;
V_8 -> V_167 |= V_169 ;
}
static int F_114 ( struct V_170 * V_171 [] , struct V_170 * V_172 [] )
{
if ( V_171 [ V_173 ] ) {
if ( F_115 ( V_171 [ V_173 ] ) != V_174 )
return - V_86 ;
if ( ! F_116 ( F_117 ( V_171 [ V_173 ] ) ) )
return - V_175 ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_8 , struct V_119 * V_176 )
{
F_119 ( V_8 , V_176 ) ;
}
static int F_120 ( struct V_29 * V_177 , struct V_1 * V_8 ,
struct V_170 * V_171 [] , struct V_170 * V_172 [] )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
if ( ! V_172 || ! V_172 [ V_178 ] )
return - V_86 ;
V_92 -> V_98 = F_121 ( V_172 [ V_178 ] ) ;
V_8 -> V_117 |= V_179 ;
return F_122 ( V_8 ) ;
}
static T_6 F_123 ( const struct V_1 * V_8 )
{
return F_124 ( sizeof( T_3 ) ) ;
}
static int F_125 ( struct V_3 * V_4 ,
const struct V_1 * V_8 )
{
struct V_91 * V_92 = F_55 ( V_8 ) ;
return F_126 ( V_4 , V_178 , V_92 -> V_98 ) ;
}
static T_6 F_127 ( const struct V_1 * V_180 ,
const struct V_1 * V_181 )
{
return F_124 ( sizeof( T_3 ) ) ;
}
static int F_128 ( struct V_3 * V_4 ,
const struct V_1 * V_2 ,
const struct V_1 * V_181 )
{
struct V_91 * V_92 = F_55 ( V_2 ) ;
if ( F_126 ( V_4 , V_182 , V_92 -> V_98 ) )
return - V_183 ;
return 0 ;
}
static int F_129 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_1 * V_8 = F_130 ( V_187 ) ;
if ( V_186 == V_188 ) {
struct V_1 * V_2 ;
if ( ! F_82 ( V_8 ) )
goto V_60;
V_2 = F_131 ( V_8 ) ;
F_85 ( V_2 , V_8 ) ;
}
V_60:
return V_189 ;
}
static int T_7 F_132 ( void )
{
int V_96 ;
F_133 ( & V_190 ) ;
V_96 = F_134 ( & V_191 ) ;
if ( V_96 < 0 )
goto error;
return 0 ;
error:
F_135 ( & V_190 ) ;
return V_96 ;
}
