static bool F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_3 V_5 ;
bool V_6 = true ;
V_4 = F_2 ( V_2 , 0 , sizeof( V_5 ) , & V_5 ) ;
if ( ! V_4 )
goto V_7;
if ( V_4 -> V_8 == V_9 ) {
const struct V_10 * V_11 ;
struct V_10 V_12 ;
V_11 = F_2 ( V_2 , sizeof( V_5 ) ,
sizeof( V_12 ) , & V_12 ) ;
if ( ! V_11 )
goto V_7;
switch ( V_11 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_6 = false ;
break;
}
}
V_7:
return V_6 ;
}
static bool F_1 ( const struct V_1 * V_2 )
{
return false ;
}
static bool F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case F_4 ( V_20 ) :
return true ;
case F_4 ( V_21 ) :
return F_1 ( V_2 ) ;
}
return false ;
}
static void F_5 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
V_23 -> V_24 . V_25 ++ ;
F_6 ( V_2 ) ;
}
static T_1 F_7 ( struct V_1 * * V_26 )
{
struct V_1 * V_2 = * V_26 ;
if ( F_3 ( V_2 ) ) {
struct V_22 * V_27 = F_8 ( V_2 -> V_27 ) ;
struct V_28 * V_29 = F_9 ( V_27 -> V_29 ) ;
F_10 ( & V_29 -> V_30 ) ;
V_29 -> V_31 ++ ;
V_29 -> V_32 += V_2 -> V_33 ;
F_11 ( & V_29 -> V_30 ) ;
V_2 -> V_27 = V_27 ;
return V_34 ;
}
return V_35 ;
}
static struct V_36 * F_12 ( struct V_22 * V_27 ,
struct V_36 * V_24 )
{
int V_37 ;
F_13 (i) {
const struct V_28 * V_29 ;
T_2 V_38 , V_39 , V_40 , V_41 , V_42 ;
unsigned int V_43 ;
V_29 = F_14 ( V_27 -> V_29 , V_37 ) ;
do {
V_43 = F_15 ( & V_29 -> V_30 ) ;
V_38 = V_29 -> V_44 ;
V_39 = V_29 -> V_45 ;
V_40 = V_29 -> V_46 ;
V_41 = V_29 -> V_32 ;
V_42 = V_29 -> V_31 ;
} while ( F_16 ( & V_29 -> V_30 , V_43 ) );
V_24 -> V_44 += V_38 ;
V_24 -> V_47 += V_39 ;
V_24 -> V_48 += V_40 ;
V_24 -> V_32 += V_41 ;
V_24 -> V_49 += V_42 ;
}
return V_24 ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_22 * V_27 )
{
const struct V_3 * V_50 = F_18 ( V_2 ) ;
struct V_51 * V_51 = F_19 ( V_2 -> V_27 ) ;
struct V_52 V_53 = {
. V_54 = V_27 -> V_55 ,
. V_56 = V_57 ,
. V_58 = V_50 -> V_58 ,
. V_59 = V_50 -> V_59 ,
. V_60 = F_20 ( V_50 ) ,
. V_61 = V_2 -> V_62 ,
. V_63 = V_50 -> V_8 ,
. V_64 = V_65 | V_66 ,
} ;
int V_67 = V_68 ;
struct V_69 * V_70 ;
struct V_69 * V_71 = & V_51 -> V_72 . V_73 -> V_70 ;
V_70 = F_21 ( V_51 , NULL , & V_53 ) ;
if ( V_70 == V_71 )
goto V_74;
F_22 ( V_2 ) ;
F_23 ( V_2 , V_70 ) ;
V_67 = F_24 ( V_51 , V_2 -> V_75 , V_2 ) ;
if ( F_25 ( F_26 ( V_67 ) ) )
V_27 -> V_24 . V_25 ++ ;
else
V_67 = V_76 ;
return V_67 ;
V_74:
F_5 ( V_27 , V_2 ) ;
return V_68 ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_22 * V_27 )
{
F_5 ( V_27 , V_2 ) ;
return V_68 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_77 * V_78 ,
struct V_22 * V_23 )
{
struct V_79 * V_80 ;
int V_74 = 1 ;
V_80 = F_28 ( F_19 ( V_23 ) , V_78 , NULL ) ;
if ( F_29 ( V_80 ) )
goto V_7;
if ( V_80 -> V_81 != V_82 && V_80 -> V_81 != V_83 ) {
F_30 ( V_80 ) ;
goto V_7;
}
F_22 ( V_2 ) ;
F_23 ( V_2 , & V_80 -> V_70 ) ;
V_74 = 0 ;
V_7:
return V_74 ;
}
static T_3 F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_84 * V_85 = F_32 ( V_2 ) ;
int V_67 = V_68 ;
struct V_77 V_78 = {
. V_86 = V_23 -> V_55 ,
. V_87 = V_57 ,
. V_88 = F_33 ( V_85 -> V_89 ) ,
. V_90 = V_91 | V_65 |
V_66 ,
. V_58 = V_85 -> V_58 ,
} ;
if ( F_27 ( V_2 , & V_78 , V_23 ) )
goto V_74;
if ( ! V_85 -> V_59 ) {
V_85 -> V_59 = F_34 ( F_35 ( V_2 ) -> V_27 , 0 ,
V_92 ) ;
}
V_67 = F_36 ( F_19 ( F_35 ( V_2 ) -> V_27 ) , V_2 -> V_75 , V_2 ) ;
if ( F_25 ( F_26 ( V_67 ) ) )
V_23 -> V_24 . V_25 ++ ;
else
V_67 = V_76 ;
V_7:
return V_67 ;
V_74:
F_5 ( V_23 , V_2 ) ;
goto V_7;
}
static T_3 F_37 ( struct V_1 * V_2 , struct V_22 * V_27 )
{
F_38 ( V_2 , F_39 ( V_2 ) ) ;
switch ( V_2 -> V_19 ) {
case F_4 ( V_20 ) :
return F_31 ( V_2 , V_27 ) ;
case F_4 ( V_21 ) :
return F_17 ( V_2 , V_27 ) ;
default:
F_5 ( V_27 , V_2 ) ;
return V_68 ;
}
}
static T_3 F_40 ( struct V_1 * V_2 , struct V_22 * V_27 )
{
T_3 V_67 = F_37 ( V_2 , V_27 ) ;
if ( F_41 ( V_67 == V_76 || V_67 == V_93 ) ) {
struct V_28 * V_29 = F_9 ( V_27 -> V_29 ) ;
F_10 ( & V_29 -> V_30 ) ;
V_29 -> V_45 ++ ;
V_29 -> V_44 += V_2 -> V_33 ;
F_11 ( & V_29 -> V_30 ) ;
} else {
F_42 ( V_27 -> V_29 -> V_46 ) ;
}
return V_67 ;
}
static int F_43 ( struct V_51 * V_51 , struct V_94 * V_75 ,
struct V_1 * V_2 )
{
struct V_69 * V_70 = F_35 ( V_2 ) ;
struct V_22 * V_27 = V_70 -> V_27 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
int V_67 ;
V_2 -> V_19 = F_4 ( V_21 ) ;
V_2 -> V_27 = V_27 ;
F_44 () ;
V_98 = F_45 ( (struct V_99 * ) V_70 , & F_18 ( V_2 ) -> V_58 ) ;
V_96 = F_46 ( V_70 -> V_27 , V_98 ) ;
if ( F_25 ( ! V_96 ) )
V_96 = F_47 ( & V_100 , V_98 , V_70 -> V_27 , false ) ;
if ( ! F_29 ( V_96 ) ) {
V_67 = F_48 ( V_70 , V_96 , V_2 ) ;
F_49 () ;
return V_67 ;
}
F_49 () ;
F_50 ( F_19 ( V_70 -> V_27 ) ,
F_51 ( V_70 ) , V_101 ) ;
F_6 ( V_2 ) ;
return - V_102 ;
}
static int F_52 ( struct V_51 * V_51 , struct V_94 * V_75 , struct V_1 * V_2 )
{
return F_53 ( V_103 , V_104 ,
V_51 , V_75 , V_2 , NULL , F_35 ( V_2 ) -> V_27 ,
F_43 ,
! ( F_54 ( V_2 ) -> V_105 & V_106 ) ) ;
}
static void F_55 ( struct V_107 * V_108 )
{
F_56 ( & V_108 -> V_109 -> V_70 ) ;
V_108 -> V_109 = NULL ;
}
static int F_57 ( struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
struct V_51 * V_51 = F_19 ( V_27 ) ;
struct V_99 * V_109 ;
int V_6 = - V_110 ;
V_109 = F_59 ( V_51 , V_27 ,
V_111 | V_112 | V_113 | V_114 ) ;
if ( ! V_109 )
goto V_7;
V_109 -> V_70 . V_115 = F_52 ;
V_109 -> V_116 = F_60 ( V_51 , V_108 -> V_117 ) ;
F_61 ( & V_109 -> V_70 ) ;
V_108 -> V_109 = V_109 ;
V_6 = 0 ;
V_7:
return V_6 ;
}
static void F_55 ( struct V_107 * V_108 )
{
}
static int F_57 ( struct V_22 * V_27 )
{
return 0 ;
}
static int F_62 ( struct V_51 * V_51 , struct V_94 * V_75 , struct V_1 * V_2 )
{
struct V_69 * V_70 = F_35 ( V_2 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_70 ;
struct V_22 * V_27 = V_70 -> V_27 ;
unsigned int V_118 = F_63 ( V_27 ) ;
struct V_95 * V_96 ;
T_4 V_98 ;
int V_67 = - V_102 ;
if ( F_25 ( F_64 ( V_2 ) < V_118 && V_27 -> V_119 ) ) {
struct V_1 * V_120 ;
V_120 = F_65 ( V_2 , F_63 ( V_27 ) ) ;
if ( ! V_120 ) {
V_67 = - V_110 ;
goto V_74;
}
if ( V_2 -> V_75 )
F_66 ( V_120 , V_2 -> V_75 ) ;
F_67 ( V_2 ) ;
V_2 = V_120 ;
}
F_44 () ;
V_98 = ( V_121 T_4 ) F_68 ( V_80 , F_32 ( V_2 ) -> V_58 ) ;
V_96 = F_69 ( V_27 , V_98 ) ;
if ( F_25 ( ! V_96 ) )
V_96 = F_47 ( & V_122 , & V_98 , V_27 , false ) ;
if ( ! F_29 ( V_96 ) )
V_67 = F_48 ( V_70 , V_96 , V_2 ) ;
F_49 () ;
V_74:
if ( F_25 ( V_67 < 0 ) )
F_5 ( V_2 -> V_27 , V_2 ) ;
return V_67 ;
}
static int F_70 ( struct V_51 * V_51 , struct V_94 * V_75 , struct V_1 * V_2 )
{
struct V_22 * V_27 = F_35 ( V_2 ) -> V_27 ;
F_71 ( V_51 , V_123 , V_2 -> V_33 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_19 = F_4 ( V_20 ) ;
return F_53 ( V_124 , V_104 ,
V_51 , V_75 , V_2 , NULL , V_27 ,
F_62 ,
! ( F_72 ( V_2 ) -> V_105 & V_125 ) ) ;
}
static void F_73 ( struct V_107 * V_108 )
{
struct V_69 * V_70 = (struct V_69 * ) V_108 -> V_126 ;
F_56 ( V_70 ) ;
V_108 -> V_126 = NULL ;
}
static struct V_79 * F_74 ( struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
struct V_79 * V_126 ;
V_126 = F_75 ( V_27 , 0 , V_82 , 1 , 1 , 0 ) ;
if ( V_126 ) {
V_126 -> V_70 . V_115 = F_70 ;
V_126 -> V_127 = V_108 -> V_117 ;
}
return V_126 ;
}
static void F_76 ( struct V_22 * V_27 )
{
unsigned int V_105 = V_27 -> V_105 ;
int V_67 ;
if ( ! F_77 ( V_27 ) )
return;
V_67 = F_78 ( V_27 , V_105 & ~ V_128 ) ;
if ( V_67 >= 0 )
V_67 = F_78 ( V_27 , V_105 ) ;
if ( V_67 < 0 ) {
F_79 ( V_27 ,
L_1 ,
V_27 -> V_129 ) ;
}
}
static int F_80 ( struct V_22 * V_27 , struct V_22 * V_130 )
{
int V_67 ;
V_67 = F_81 ( V_130 , F_7 , V_27 ) ;
if ( V_67 ) {
F_79 ( V_130 ,
L_2 ,
V_130 -> V_129 ) ;
goto V_131;
}
V_67 = F_82 ( V_130 , V_27 , NULL , NULL ) ;
if ( V_67 < 0 )
goto V_132;
V_130 -> V_133 |= V_134 ;
F_76 ( V_130 ) ;
return 0 ;
V_132:
F_83 ( V_130 ) ;
V_131:
return V_67 ;
}
static int F_84 ( struct V_22 * V_27 , struct V_22 * V_130 )
{
if ( F_85 ( V_130 ) || F_86 ( V_130 ) )
return - V_102 ;
return F_80 ( V_27 , V_130 ) ;
}
static int F_87 ( struct V_22 * V_27 , struct V_22 * V_130 )
{
F_88 ( V_130 , V_27 ) ;
V_130 -> V_133 &= ~ V_134 ;
F_83 ( V_130 ) ;
F_76 ( V_130 ) ;
return 0 ;
}
static int F_89 ( struct V_22 * V_27 , struct V_22 * V_130 )
{
return F_87 ( V_27 , V_130 ) ;
}
static void F_90 ( struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
struct V_22 * V_130 ;
struct V_135 * V_136 ;
F_73 ( V_108 ) ;
F_55 ( V_108 ) ;
F_91 (dev, port_dev, iter)
F_89 ( V_27 , V_130 ) ;
F_92 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
}
static int F_93 ( struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
V_27 -> V_29 = F_94 ( struct V_28 ) ;
if ( ! V_27 -> V_29 )
goto V_137;
V_108 -> V_126 = F_74 ( V_27 ) ;
if ( ! V_108 -> V_126 )
goto V_138;
if ( F_57 ( V_27 ) != 0 )
goto V_139;
V_27 -> V_105 = V_140 | V_141 ;
return 0 ;
V_139:
F_73 ( V_108 ) ;
V_138:
F_92 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
V_137:
return - V_110 ;
}
static T_4 F_95 ( const struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
return V_108 -> V_117 ;
}
static struct V_79 * F_96 ( const struct V_22 * V_27 ,
const struct V_77 * V_78 )
{
struct V_79 * V_126 = NULL ;
if ( ! ( V_78 -> V_90 & V_65 ) ) {
struct V_107 * V_108 = F_58 ( V_27 ) ;
V_126 = V_108 -> V_126 ;
F_61 ( & V_126 -> V_70 ) ;
}
return V_126 ;
}
static int F_97 ( struct V_22 * V_27 , struct V_77 * V_78 )
{
struct V_142 V_143 = { . V_144 = 0 } ;
struct V_51 * V_51 = F_19 ( V_27 ) ;
T_4 V_145 = V_78 -> V_88 ;
T_5 V_105 = V_78 -> V_90 ;
T_5 V_146 = V_78 -> V_147 ;
T_5 V_89 = F_98 ( V_78 ) ;
int V_6 ;
if ( F_25 ( ! V_78 -> V_58 ) )
return 0 ;
V_78 -> V_90 |= V_66 ;
V_78 -> V_87 = V_57 ;
V_78 -> V_88 = V_89 & V_148 ;
V_78 -> V_147 = ( ( V_89 & V_149 ) ?
V_92 : V_150 ) ;
V_6 = F_99 ( V_51 , V_78 , & V_143 , 0 ) ;
if ( ! V_6 ) {
if ( V_143 . type == V_83 )
V_78 -> V_59 = V_143 . V_151 -> V_152 ? : V_78 -> V_58 ;
else
F_100 ( V_51 , & V_143 , V_78 , - 1 ) ;
}
V_78 -> V_90 = V_105 ;
V_78 -> V_88 = V_145 ;
V_78 -> V_147 = V_146 ;
return V_6 ;
}
static struct V_69 * F_101 ( const struct V_22 * V_27 ,
const struct V_52 * V_53 )
{
struct V_99 * V_80 = NULL ;
if ( ! ( V_53 -> V_64 & V_65 ) ) {
struct V_107 * V_108 = F_58 ( V_27 ) ;
V_80 = V_108 -> V_109 ;
F_61 ( & V_80 -> V_70 ) ;
}
return (struct V_69 * ) V_80 ;
}
static void F_102 ( struct V_22 * V_27 ,
struct V_153 * V_154 )
{
F_103 ( V_154 -> V_155 , V_156 , sizeof( V_154 -> V_155 ) ) ;
F_103 ( V_154 -> V_157 , V_158 , sizeof( V_154 -> V_157 ) ) ;
}
static void F_104 ( struct V_22 * V_27 )
{
F_105 ( V_27 ) ;
V_27 -> V_159 = & V_160 ;
V_27 -> V_161 = & V_162 ;
V_27 -> V_163 = & V_164 ;
V_27 -> V_165 = V_166 ;
F_106 ( V_27 ) ;
V_27 -> V_167 |= V_168 ;
V_27 -> V_167 |= V_169 ;
}
static int F_107 ( struct V_170 * V_171 [] , struct V_170 * V_172 [] )
{
if ( V_171 [ V_173 ] ) {
if ( F_108 ( V_171 [ V_173 ] ) != V_174 )
return - V_102 ;
if ( ! F_109 ( F_110 ( V_171 [ V_173 ] ) ) )
return - V_175 ;
}
return 0 ;
}
static void F_111 ( struct V_22 * V_27 , struct V_135 * V_176 )
{
F_112 ( V_27 , V_176 ) ;
}
static int F_113 ( struct V_51 * V_177 , struct V_22 * V_27 ,
struct V_170 * V_171 [] , struct V_170 * V_172 [] )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
if ( ! V_172 || ! V_172 [ V_178 ] )
return - V_102 ;
V_108 -> V_117 = F_114 ( V_172 [ V_178 ] ) ;
V_27 -> V_133 |= V_179 ;
return F_115 ( V_27 ) ;
}
static T_6 F_116 ( const struct V_22 * V_27 )
{
return F_117 ( sizeof( T_4 ) ) ;
}
static int F_118 ( struct V_1 * V_2 ,
const struct V_22 * V_27 )
{
struct V_107 * V_108 = F_58 ( V_27 ) ;
return F_119 ( V_2 , V_178 , V_108 -> V_117 ) ;
}
static T_6 F_120 ( const struct V_22 * V_180 ,
const struct V_22 * V_181 )
{
return F_117 ( sizeof( T_4 ) ) ;
}
static int F_121 ( struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_22 * V_181 )
{
struct V_107 * V_108 = F_58 ( V_23 ) ;
if ( F_119 ( V_2 , V_182 , V_108 -> V_117 ) )
return - V_183 ;
return 0 ;
}
static int F_122 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_22 * V_27 = F_123 ( V_187 ) ;
if ( V_186 == V_188 ) {
struct V_22 * V_23 ;
if ( ! F_86 ( V_27 ) )
goto V_7;
V_23 = F_124 ( V_27 ) ;
F_89 ( V_23 , V_27 ) ;
}
V_7:
return V_189 ;
}
static int T_7 F_125 ( void )
{
int V_6 ;
F_126 ( & V_190 ) ;
V_6 = F_127 ( & V_191 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
F_128 ( & V_190 ) ;
return V_6 ;
}
