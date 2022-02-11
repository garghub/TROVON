static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const int V_5 = F_2 ( V_4 -> V_6 ) ;
int V_7 ;
V_7 = F_3 () ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_10 [ V_5 ] ) ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_11 [ V_5 ] , V_4 -> V_12 . V_13 >> 9 ) ;
( void ) V_7 ;
F_7 ( & V_2 -> V_8 -> V_9 , V_5 ) ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( V_4 -> V_6 ) ;
unsigned long V_14 = V_15 - V_4 -> V_16 ;
int V_7 ;
V_7 = F_3 () ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_17 [ V_5 ] , V_14 ) ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_10 ( & V_2 -> V_8 -> V_9 , V_5 ) ;
F_8 () ;
}
static struct V_3 * F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 ;
V_4 = F_12 ( V_20 , V_21 ) ;
if ( ! V_4 )
return NULL ;
F_13 ( V_4 , V_19 ) ;
V_4 -> V_22 = F_2 ( V_19 ) == V_23 ? V_24 : 0 ;
V_4 -> V_25 . V_2 = V_2 ;
V_4 -> V_6 = V_19 ;
V_4 -> V_26 = 0 ;
F_14 ( & V_4 -> V_12 ) ;
V_4 -> V_12 . V_27 = V_19 -> V_28 . V_29 ;
V_4 -> V_12 . V_13 = V_19 -> V_28 . V_30 ;
V_4 -> V_12 . V_31 = true ;
V_4 -> V_12 . V_32 = false ;
F_15 ( & V_4 -> V_33 ) ;
F_15 ( & V_4 -> V_25 . V_34 ) ;
F_16 ( & V_4 -> V_35 , 1 ) ;
F_17 ( & V_4 -> V_36 ) ;
return V_4 ;
}
void F_18 ( struct V_36 * V_36 )
{
struct V_3 * V_4 = F_19 ( V_36 , struct V_3 , V_36 ) ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
const unsigned V_37 = V_4 -> V_22 ;
if ( ( V_4 -> V_6 && ! ( V_37 & V_38 ) ) ||
F_20 ( & V_4 -> V_35 ) ||
( V_37 & V_39 ) ||
( ( V_37 & V_40 ) && ! ( V_37 & V_41 ) ) ) {
F_21 ( V_42 , L_1 ,
V_37 , F_20 ( & V_4 -> V_35 ) ) ;
return;
}
F_22 ( & V_4 -> V_33 ) ;
if ( V_37 & V_24 ) {
if ( ( V_37 & ( V_38 | V_43 | V_40 ) ) != V_38 ) {
if ( ! ( V_37 & V_44 ) || ! ( V_37 & V_45 ) )
F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
if ( ( V_37 & V_44 ) && ( V_37 & V_45 ) && ( V_37 & V_46 ) )
F_24 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
if ( V_37 & V_47 ) {
if ( F_25 ( V_2 , V_48 ) ) {
F_26 ( V_2 , & V_4 -> V_12 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_49 ) ) {
F_29 ( V_42 , L_2
L_3 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
}
}
F_30 ( V_4 , V_20 ) ;
}
static void F_31 ( struct V_50 * V_51 ) {
F_32 ( & V_51 -> V_52 . V_53 ) ;
}
void F_33 ( struct V_50 * V_51 )
{
if ( V_51 -> V_54 == 0 )
return;
V_51 -> V_54 = 0 ;
F_34 ( & V_51 -> V_55 ) ;
F_31 ( V_51 ) ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
F_36 ( V_57 -> V_18 , V_57 -> error ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_58 * V_59 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_60 * V_12 = & V_4 -> V_12 ;
F_39 ( V_59 , V_12 ) ;
if ( V_12 -> V_32 )
F_32 ( & V_2 -> V_61 ) ;
}
static
void F_40 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
const unsigned V_37 = V_4 -> V_22 ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
int V_5 ;
int error , V_62 ;
if ( ( V_37 & V_39 && ! ( V_37 & V_63 ) ) ||
( V_37 & V_64 ) || ( V_37 & V_65 ) ||
( V_37 & V_66 ) ) {
F_21 ( V_42 , L_4 , V_37 ) ;
return;
}
if ( ! V_4 -> V_6 ) {
F_21 ( V_42 , L_5 ) ;
return;
}
V_5 = F_41 ( V_4 -> V_6 ) ;
V_62 = ( V_37 & V_45 ) || ( V_37 & V_44 ) ;
error = F_42 ( V_4 -> V_67 ) ;
if ( ! F_43 ( & V_4 -> V_12 ) ) {
struct V_58 * V_59 ;
if ( V_5 == V_23 )
V_59 = & V_2 -> V_68 ;
else
V_59 = & V_2 -> V_69 ;
F_38 ( V_59 , V_4 ) ;
}
if ( V_5 == V_23 &&
V_4 -> V_26 == F_20 ( & V_2 -> V_51 -> V_55 ) )
F_33 ( V_2 -> V_51 ) ;
F_9 ( V_2 , V_4 ) ;
if ( ! V_62 && V_5 == V_70 && ! F_44 ( & V_4 -> V_33 ) )
V_4 -> V_22 |= V_38 ;
if ( ! ( V_4 -> V_22 & V_38 ) ) {
V_57 -> error = V_62 ? 0 : ( error ? : - V_71 ) ;
V_57 -> V_18 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
}
static int F_45 ( struct V_3 * V_4 , struct V_56 * V_57 , int V_72 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
F_46 ( V_57 || ( V_4 -> V_22 & V_38 ) ) ;
if ( ! F_47 ( V_72 , & V_4 -> V_35 ) )
return 0 ;
F_40 ( V_4 , V_57 ) ;
if ( V_4 -> V_22 & V_38 ) {
F_48 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_49 ( struct V_3 * V_4 , struct V_56 * V_57 ,
int V_73 , int V_74 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
unsigned V_37 = V_4 -> V_22 ;
int V_75 = 0 ;
int V_76 = 0 ;
if ( F_50 ( V_2 ) && ! ( ( V_37 | V_73 ) & V_66 ) )
V_74 |= V_66 ;
V_4 -> V_22 &= ~ V_73 ;
V_4 -> V_22 |= V_74 ;
if ( V_4 -> V_22 == V_37 )
return;
if ( ! ( V_37 & V_39 ) && ( V_74 & V_39 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ! ( V_37 & V_65 ) && ( V_74 & V_65 ) ) {
F_51 ( V_2 ) ;
F_34 ( & V_4 -> V_35 ) ;
}
if ( ! ( V_37 & V_64 ) && ( V_74 & V_64 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ! ( V_37 & V_77 ) && ( V_74 & V_77 ) )
F_52 ( & V_4 -> V_36 ) ;
if ( ! ( V_37 & V_78 ) && ( V_74 & V_78 ) )
F_53 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_79 ) ;
if ( ! ( V_37 & V_66 ) && ( V_74 & V_66 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ( V_37 & V_66 ) && ( V_73 & V_66 ) )
++ V_75 ;
if ( ! ( V_37 & V_63 ) && ( V_74 & V_63 ) ) {
F_46 ( V_4 -> V_22 & V_39 ) ;
F_52 ( & V_4 -> V_36 ) ;
++ V_75 ;
}
if ( ( V_37 & V_39 ) && ( V_73 & V_39 ) ) {
if ( V_4 -> V_22 & V_63 )
++ V_76 ;
else
++ V_75 ;
}
if ( ( V_37 & V_65 ) && ( V_73 & V_65 ) ) {
F_54 ( V_2 ) ;
++ V_75 ;
}
if ( ( V_37 & V_64 ) && ( V_73 & V_64 ) )
++ V_75 ;
if ( ( V_37 & V_77 ) && ! ( V_37 & V_41 ) && ( V_74 & V_41 ) ) {
if ( V_4 -> V_22 & V_78 )
F_55 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_79 ) ;
++ V_76 ;
}
if ( V_76 || V_75 ) {
int V_80 = V_76 + ! ! V_75 ;
int V_81 = F_20 ( & V_4 -> V_36 . V_81 ) ;
if ( V_81 < V_80 )
F_21 ( V_42 ,
L_6 ,
V_37 , V_4 -> V_22 , V_81 , V_80 ) ;
}
if ( V_4 -> V_12 . V_32 )
F_32 ( & V_2 -> V_61 ) ;
if ( V_75 )
V_76 += F_45 ( V_4 , V_57 , V_75 ) ;
if ( V_76 )
F_56 ( & V_4 -> V_36 , V_76 , F_18 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_82 [ V_83 ] ;
if ( ! F_28 ( & V_49 ) )
return;
F_29 ( V_42 , L_7 ,
( V_4 -> V_22 & V_24 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_12 . V_27 ,
V_4 -> V_12 . V_13 >> 9 ,
F_58 ( V_2 -> V_84 -> V_85 , V_82 ) ) ;
}
int F_59 ( struct V_3 * V_4 , enum V_86 V_87 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_88 * V_89 ;
int V_90 , V_91 = 0 ;
if ( V_57 )
V_57 -> V_18 = NULL ;
switch ( V_87 ) {
default:
F_21 ( V_42 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_92 :
F_46 ( ! ( V_4 -> V_22 & V_40 ) ) ;
F_60 () ;
V_89 = F_61 ( V_2 -> V_51 -> V_88 ) ;
V_90 = V_89 -> V_93 ;
F_62 () ;
V_4 -> V_22 |=
V_90 == V_94 ? V_95 :
V_90 == V_96 ? V_97 : 0 ;
F_49 ( V_4 , V_57 , 0 , V_65 ) ;
break;
case V_98 :
F_46 ( ! ( V_4 -> V_22 & V_43 ) ) ;
F_49 ( V_4 , V_57 , 0 , V_39 ) ;
break;
case V_99 :
if ( V_4 -> V_22 & V_24 )
V_2 -> V_100 += V_4 -> V_12 . V_13 >> 9 ;
else
V_2 -> V_101 += V_4 -> V_12 . V_13 >> 9 ;
F_49 ( V_4 , V_57 , V_39 ,
V_102 | V_45 ) ;
break;
case V_103 :
F_49 ( V_4 , V_57 , 0 , V_63 ) ;
break;
case V_104 :
F_57 ( V_2 , V_4 ) ;
F_63 ( V_2 , V_105 ) ;
F_49 ( V_4 , V_57 , V_39 , V_102 ) ;
break;
case V_106 :
F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
F_57 ( V_2 , V_4 ) ;
F_63 ( V_2 , V_107 ) ;
case V_108 :
F_49 ( V_4 , V_57 , V_39 , V_102 ) ;
break;
case V_109 :
F_46 ( F_43 ( & V_4 -> V_12 ) ) ;
F_64 ( & V_2 -> V_69 , & V_4 -> V_12 ) ;
F_65 ( V_110 , & V_2 -> V_111 ) ;
F_46 ( V_4 -> V_22 & V_65 ) ;
F_46 ( ( V_4 -> V_22 & V_43 ) == 0 ) ;
F_49 ( V_4 , V_57 , 0 , V_64 ) ;
V_4 -> V_25 . V_112 = V_113 ;
F_66 ( & V_2 -> V_51 -> V_52 , & V_4 -> V_25 ) ;
break;
case V_114 :
F_46 ( F_43 ( & V_4 -> V_12 ) ) ;
F_64 ( & V_2 -> V_68 , & V_4 -> V_12 ) ;
F_65 ( V_110 , & V_2 -> V_111 ) ;
F_46 ( V_4 -> V_22 & V_65 ) ;
F_49 ( V_4 , V_57 , 0 , V_64 | V_77 ) ;
V_4 -> V_25 . V_112 = V_115 ;
F_66 ( & V_2 -> V_51 -> V_52 , & V_4 -> V_25 ) ;
F_60 () ;
V_89 = F_61 ( V_2 -> V_51 -> V_88 ) ;
V_90 = V_89 -> V_116 ;
F_62 () ;
if ( V_2 -> V_51 -> V_54 >= V_90 )
F_33 ( V_2 -> V_51 ) ;
break;
case V_117 :
F_49 ( V_4 , V_57 , 0 , V_64 ) ;
V_4 -> V_25 . V_112 = V_118 ;
F_66 ( & V_2 -> V_51 -> V_52 , & V_4 -> V_25 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
F_49 ( V_4 , V_57 , V_64 , 0 ) ;
break;
case V_122 :
if ( F_2 ( V_4 -> V_6 ) == V_23 &&
! ( V_4 -> V_22 & ( V_97 | V_95 ) ) ) {
if ( V_4 -> V_22 & V_65 )
F_49 ( V_4 , V_57 , V_65 , V_44 ) ;
}
F_49 ( V_4 , V_57 , V_64 , V_78 ) ;
break;
case V_123 :
F_49 ( V_4 , V_57 , V_64 , V_41 ) ;
break;
case V_124 :
F_49 ( V_4 , V_57 ,
V_44 | V_65 | V_66 ,
V_41 ) ;
break;
case V_125 :
F_46 ( V_4 -> V_22 & V_65 ) ;
F_46 ( V_4 -> V_22 & V_95 ) ;
F_49 ( V_4 , V_57 , V_65 , V_41 | V_44 ) ;
break;
case V_126 :
V_4 -> V_22 |= V_46 ;
case V_127 :
F_46 ( V_4 -> V_22 & V_95 ) ;
goto V_128;
case V_129 :
F_46 ( V_4 -> V_22 & V_97 ) ;
V_128:
F_46 ( V_4 -> V_22 & V_65 ) ;
F_49 ( V_4 , V_57 , V_65 , V_44 ) ;
break;
case V_130 :
F_46 ( V_4 -> V_22 & V_95 ) ;
F_46 ( V_4 -> V_22 & V_65 ) ;
V_4 -> V_22 |= V_38 ;
if ( V_4 -> V_12 . V_32 )
F_32 ( & V_2 -> V_61 ) ;
break;
case V_131 :
F_49 ( V_4 , V_57 , V_44 | V_65 , 0 ) ;
break;
case V_132 :
if ( ! ( V_4 -> V_22 & V_102 ) )
break;
F_49 ( V_4 , V_57 , V_66 , 0 ) ;
break;
case V_133 :
if ( ! ( V_4 -> V_22 & V_102 ) )
break;
F_49 ( V_4 , V_57 ,
V_66 | V_102 ,
V_39 ) ;
V_91 = V_134 ;
if ( F_2 ( V_4 -> V_6 ) == V_23 )
V_91 = V_135 ;
F_67 ( V_2 ) ;
V_4 -> V_25 . V_112 = V_136 ;
F_66 ( & V_2 -> V_51 -> V_52 , & V_4 -> V_25 ) ;
break;
case V_137 :
if ( ! ( V_4 -> V_22 & V_24 ) && ! V_4 -> V_25 . V_112 ) {
F_49 ( V_4 , V_57 , V_66 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_22 & V_44 ) ) {
F_49 ( V_4 , V_57 , V_66 , V_64 | V_65 ) ;
if ( V_4 -> V_25 . V_112 ) {
F_66 ( & V_2 -> V_51 -> V_52 , & V_4 -> V_25 ) ;
V_91 = V_4 -> V_22 & V_24 ? V_135 : V_134 ;
}
break;
}
case V_138 :
if ( ! ( V_4 -> V_22 & V_24 ) )
break;
if ( V_4 -> V_22 & V_65 ) {
F_21 ( V_42 , L_11 ) ;
}
F_49 ( V_4 , V_57 , V_66 ,
( V_4 -> V_22 & V_40 ) ? V_41 : 0 ) ;
break;
case V_139 :
F_46 ( V_4 -> V_22 & V_65 ) ;
F_49 ( V_4 , V_57 , V_65 , V_44 | V_41 ) ;
break;
case V_140 :
F_33 ( V_2 -> V_51 ) ;
F_49 ( V_4 , V_57 , 0 , V_44 | V_41 ) ;
break;
} ;
return V_91 ;
}
static bool F_68 ( struct V_1 * V_2 , T_1 V_27 , int V_13 )
{
unsigned long V_141 , V_142 ;
T_1 V_143 , V_144 ;
if ( V_2 -> V_145 . V_146 == V_147 )
return true ;
if ( V_2 -> V_145 . V_146 != V_148 )
return false ;
V_143 = V_27 + ( V_13 >> 9 ) - 1 ;
V_144 = F_69 ( V_2 -> V_149 ) ;
F_46 ( V_27 < V_144 ) ;
F_46 ( V_143 < V_144 ) ;
V_141 = F_70 ( V_27 ) ;
V_142 = F_70 ( V_143 ) ;
return F_71 ( V_2 , V_141 , V_142 ) == 0 ;
}
static bool F_72 ( struct V_1 * V_2 , T_1 V_27 ,
enum V_150 V_151 )
{
struct V_152 * V_153 ;
int V_154 ;
switch ( V_151 ) {
case V_155 :
V_153 = & V_2 -> V_84 -> V_85 -> V_156 -> V_157 -> V_152 ;
return F_73 ( V_153 ) ;
case V_158 :
return F_20 ( & V_2 -> V_159 ) >
F_20 ( & V_2 -> V_160 ) + F_20 ( & V_2 -> V_161 ) ;
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
V_154 = ( V_151 - V_162 + 15 ) ;
return ( V_27 >> ( V_154 - 9 ) ) & 1 ;
case V_168 :
return F_74 ( V_169 , & V_2 -> V_111 ) ;
case V_170 :
return true ;
case V_171 :
default:
return false ;
}
}
static void F_75 ( struct V_3 * V_4 )
{
F_76 ( V_172 ) ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_60 * V_12 ;
T_1 V_27 = V_4 -> V_12 . V_27 ;
int V_13 = V_4 -> V_12 . V_13 ;
V_12 = F_77 ( & V_2 -> V_68 , V_27 , V_13 ) ;
if ( ! V_12 )
return;
for (; ; ) {
F_78 ( & V_2 -> V_61 , & V_172 , V_173 ) ;
V_12 = F_77 ( & V_2 -> V_68 , V_27 , V_13 ) ;
if ( ! V_12 )
break;
V_12 -> V_32 = true ;
F_79 ( & V_2 -> V_51 -> V_174 ) ;
F_80 () ;
F_81 ( & V_2 -> V_51 -> V_174 ) ;
}
F_82 ( & V_2 -> V_61 , & V_172 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
struct V_88 * V_89 ;
bool V_175 = false ;
enum V_176 V_177 ;
F_60 () ;
V_89 = F_61 ( V_51 -> V_88 ) ;
V_177 = V_89 ? V_89 -> V_177 : V_178 ;
F_62 () ;
if ( V_177 == V_178 ||
V_51 -> V_179 < 96 )
return;
if ( ! F_25 ( V_2 , V_147 ) )
return;
if ( V_89 -> V_180 &&
F_20 ( & V_2 -> V_79 ) >= V_89 -> V_180 ) {
F_84 ( V_42 , L_12 ) ;
V_175 = true ;
}
if ( V_2 -> V_181 -> V_182 >= V_89 -> V_183 ) {
F_84 ( V_42 , L_13 ) ;
V_175 = true ;
}
if ( V_175 ) {
F_33 ( V_2 -> V_51 ) ;
if ( V_177 == V_184 )
F_85 ( F_86 ( V_2 , V_185 , V_186 ) , 0 , NULL ) ;
else
F_85 ( F_86 ( V_2 , V_185 , V_187 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
enum V_150 V_151 ;
if ( V_4 -> V_67 ) {
if ( ! F_68 ( V_2 ,
V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ) {
F_88 ( V_4 -> V_67 ) ;
V_4 -> V_67 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_145 . V_188 != V_147 )
return false ;
if ( V_4 -> V_67 == NULL )
return true ;
F_60 () ;
V_151 = F_61 ( V_2 -> V_84 -> V_189 ) -> V_190 ;
F_62 () ;
if ( V_151 == V_171 && V_4 -> V_67 )
return false ;
if ( F_72 ( V_2 , V_4 -> V_12 . V_27 , V_151 ) ) {
if ( V_4 -> V_67 ) {
F_88 ( V_4 -> V_67 ) ;
V_4 -> V_67 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
int V_191 , V_192 ;
V_191 = F_90 ( V_2 -> V_145 ) ;
V_192 = F_91 ( V_2 -> V_145 ) ;
if ( F_92 ( V_4 -> V_12 . V_13 == 0 ) ) {
F_46 ( V_4 -> V_6 -> V_193 & V_194 ) ;
if ( V_191 )
F_93 ( V_4 , V_140 ) ;
return V_191 ;
}
if ( ! V_191 && ! V_192 )
return 0 ;
F_46 ( ! ( V_191 && V_192 ) ) ;
if ( V_191 ) {
F_93 ( V_4 , V_92 ) ;
F_93 ( V_4 , V_114 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) )
F_93 ( V_4 , V_117 ) ;
return V_191 ;
}
static void
F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_18 * V_18 = V_4 -> V_67 ;
const int V_5 = F_41 ( V_18 ) ;
V_18 -> V_195 = V_2 -> V_84 -> V_85 ;
if ( F_67 ( V_2 ) ) {
if ( F_95 ( V_2 ,
V_5 == V_23 ? V_196
: V_5 == V_70 ? V_197
: V_198 ) )
F_36 ( V_18 , - V_71 ) ;
else
F_96 ( V_18 ) ;
F_27 ( V_2 ) ;
} else
F_36 ( V_18 , - V_71 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_98 ( & V_2 -> V_199 . V_200 ) ;
F_99 ( & V_4 -> V_33 , & V_2 -> V_199 . V_201 ) ;
F_100 ( & V_2 -> V_199 . V_200 ) ;
F_101 ( V_2 -> V_199 . V_202 , & V_2 -> V_199 . V_203 ) ;
}
struct V_3 *
F_102 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
const int V_5 = F_2 ( V_18 ) ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_18 ) ;
if ( ! V_4 ) {
F_37 ( V_2 ) ;
F_21 ( V_42 , L_14 ) ;
F_36 ( V_18 , - V_204 ) ;
return F_103 ( - V_204 ) ;
}
V_4 -> V_16 = V_16 ;
if ( ! F_67 ( V_2 ) ) {
F_88 ( V_4 -> V_67 ) ;
V_4 -> V_67 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_5 == V_23 && V_4 -> V_67 && V_4 -> V_12 . V_13
&& ! F_104 ( V_205 , & V_2 -> V_111 ) ) {
if ( ! F_105 ( V_2 , & V_4 -> V_12 ) ) {
F_97 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_22 |= V_47 ;
}
return V_4 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const int V_5 = F_41 ( V_4 -> V_6 ) ;
struct V_56 V_57 = { NULL , } ;
bool V_206 = false ;
F_81 ( & V_2 -> V_51 -> V_174 ) ;
if ( V_5 == V_23 ) {
F_75 ( V_4 ) ;
F_83 ( V_2 ) ;
}
if ( F_50 ( V_2 ) ) {
V_4 -> V_22 |= V_38 ;
if ( V_4 -> V_67 ) {
F_88 ( V_4 -> V_67 ) ;
V_4 -> V_67 = NULL ;
F_27 ( V_2 ) ;
}
goto V_207;
}
if ( V_5 != V_23 ) {
if ( ! F_87 ( V_4 ) && ! V_4 -> V_67 )
goto V_208;
}
V_4 -> V_26 = F_20 ( & V_2 -> V_51 -> V_55 ) ;
if ( F_107 ( V_4 -> V_12 . V_13 != 0 ) ) {
if ( V_5 == V_23 )
V_2 -> V_51 -> V_54 ++ ;
F_99 ( & V_4 -> V_33 , & V_2 -> V_51 -> V_209 ) ;
}
if ( V_5 == V_23 ) {
if ( ! F_89 ( V_4 ) )
V_206 = true ;
} else {
if ( V_4 -> V_67 == NULL ) {
F_93 ( V_4 , V_92 ) ;
F_93 ( V_4 , V_109 ) ;
} else
V_206 = true ;
}
if ( V_4 -> V_67 ) {
F_93 ( V_4 , V_98 ) ;
F_79 ( & V_2 -> V_51 -> V_174 ) ;
F_94 ( V_4 ) ;
F_81 ( & V_2 -> V_51 -> V_174 ) ;
} else if ( V_206 ) {
V_208:
if ( F_28 ( & V_49 ) )
F_21 ( V_42 , L_15 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 >> 9 ) ;
}
V_207:
if ( F_45 ( V_4 , & V_57 , 1 ) )
F_108 ( & V_4 -> V_36 , F_18 ) ;
F_79 ( & V_2 -> V_51 -> V_174 ) ;
if ( V_57 . V_18 )
F_35 ( V_2 , & V_57 ) ;
}
void F_109 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
struct V_3 * V_4 = F_102 ( V_2 , V_18 , V_16 ) ;
if ( F_110 ( V_4 ) )
return;
F_106 ( V_2 , V_4 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_210 * V_211 )
{
struct V_3 * V_4 , * V_212 ;
F_112 (req, tmp, incoming, tl_requests) {
const int V_5 = F_2 ( V_4 -> V_6 ) ;
if ( V_5 == V_23
&& V_4 -> V_67 && V_4 -> V_12 . V_13
&& ! F_104 ( V_205 , & V_2 -> V_111 ) ) {
if ( ! F_105 ( V_2 , & V_4 -> V_12 ) )
continue;
V_4 -> V_22 |= V_47 ;
}
F_22 ( & V_4 -> V_33 ) ;
F_106 ( V_2 , V_4 ) ;
}
}
static bool F_113 ( struct V_1 * V_2 ,
struct V_210 * V_211 ,
struct V_210 * V_213 )
{
struct V_3 * V_4 , * V_212 ;
int V_214 = 0 ;
int V_215 ;
F_81 ( & V_2 -> V_216 ) ;
F_112 (req, tmp, incoming, tl_requests) {
V_215 = F_114 ( V_2 , & V_4 -> V_12 ) ;
if ( V_215 == - V_217 )
V_214 = 1 ;
if ( V_215 )
continue;
V_4 -> V_22 |= V_47 ;
F_115 ( & V_4 -> V_33 , V_213 ) ;
}
F_79 ( & V_2 -> V_216 ) ;
if ( V_214 )
F_32 ( & V_2 -> V_218 ) ;
return ! F_44 ( V_213 ) ;
}
void F_116 ( struct V_219 * V_220 )
{
struct V_1 * V_2 = F_19 ( V_220 , struct V_1 , V_199 . V_203 ) ;
F_117 ( V_211 ) ;
F_117 ( V_213 ) ;
struct V_3 * V_4 , * V_212 ;
for (; ; ) {
F_98 ( & V_2 -> V_199 . V_200 ) ;
F_118 ( & V_2 -> V_199 . V_201 , & V_211 ) ;
F_100 ( & V_2 -> V_199 . V_200 ) ;
F_111 ( V_2 , & V_211 ) ;
if ( F_44 ( & V_211 ) )
break;
F_119 ( V_2 -> V_218 , F_113 ( V_2 , & V_211 , & V_213 ) ) ;
for (; ; ) {
F_117 ( V_221 ) ;
F_117 ( V_222 ) ;
bool V_223 ;
if ( F_44 ( & V_2 -> V_199 . V_201 ) )
break;
F_98 ( & V_2 -> V_199 . V_200 ) ;
F_118 ( & V_2 -> V_199 . V_201 , & V_222 ) ;
F_100 ( & V_2 -> V_199 . V_200 ) ;
if ( F_44 ( & V_222 ) )
break;
V_223 = F_113 ( V_2 , & V_222 , & V_221 ) ;
F_118 ( & V_221 , & V_213 ) ;
F_118 ( & V_222 , & V_211 ) ;
if ( ! V_223 )
break;
}
F_120 ( V_2 , false ) ;
F_112 (req, tmp, &pending, tl_requests) {
F_22 ( & V_4 -> V_33 ) ;
F_106 ( V_2 , V_4 ) ;
}
}
}
void F_121 ( struct V_224 * V_225 , struct V_18 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_225 -> V_226 ;
unsigned long V_16 ;
V_16 = V_15 ;
F_46 ( F_122 ( V_18 -> V_28 . V_30 , 512 ) ) ;
F_123 ( V_2 ) ;
F_109 ( V_2 , V_18 , V_16 ) ;
}
int F_124 ( struct V_224 * V_225 , struct V_227 * V_228 , struct V_229 * V_230 )
{
struct V_1 * V_2 = (struct V_1 * ) V_225 -> V_226 ;
unsigned int V_231 = V_228 -> V_30 ;
int V_232 = V_233 ;
int V_234 ;
if ( V_231 && F_67 ( V_2 ) ) {
unsigned int V_235 = F_125 ( V_225 ) ;
struct V_224 * const V_82 =
V_2 -> V_84 -> V_85 -> V_156 -> V_157 ;
if ( V_82 -> V_236 ) {
V_234 = V_82 -> V_236 ( V_82 , V_228 , V_230 ) ;
V_232 = F_126 ( V_232 , V_234 ) ;
}
F_27 ( V_2 ) ;
if ( ( V_232 >> 9 ) > V_235 )
V_232 = V_235 << 9 ;
}
return V_232 ;
}
struct V_3 * F_127 ( struct V_50 * V_51 )
{
struct V_3 * V_237 ;
F_128 (r, &tconn->transfer_log, tl_requests) {
if ( F_20 ( & V_237 -> V_35 ) )
return V_237 ;
}
return NULL ;
}
void F_129 ( unsigned long V_238 )
{
struct V_1 * V_2 = (struct V_1 * ) V_238 ;
struct V_50 * V_51 = V_2 -> V_51 ;
struct V_3 * V_4 ;
struct V_88 * V_89 ;
unsigned long V_239 = 0 , V_240 = 0 , V_241 , V_242 ;
unsigned long V_243 ;
F_60 () ;
V_89 = F_61 ( V_51 -> V_88 ) ;
if ( V_89 && V_2 -> V_145 . V_185 >= V_244 )
V_239 = V_89 -> V_245 * V_246 / 10 * V_89 -> V_247 ;
if ( F_67 ( V_2 ) ) {
V_240 = F_61 ( V_2 -> V_84 -> V_189 ) -> V_248 * V_246 / 10 ;
F_27 ( V_2 ) ;
}
F_62 () ;
V_241 = F_130 ( V_240 , V_239 ) ;
if ( ! V_241 )
return;
V_243 = V_15 ;
F_81 ( & V_51 -> V_174 ) ;
V_4 = F_127 ( V_51 ) ;
if ( ! V_4 ) {
F_79 ( & V_51 -> V_174 ) ;
F_131 ( & V_2 -> V_249 , V_243 + V_241 ) ;
return;
}
if ( V_239 && V_4 -> V_22 & V_65 &&
F_132 ( V_243 , V_4 -> V_16 + V_239 ) &&
! F_133 ( V_243 , V_51 -> V_250 , V_51 -> V_250 + V_239 ) ) {
F_29 ( V_42 , L_16 ) ;
F_85 ( F_86 ( V_2 , V_185 , V_251 ) , V_252 | V_253 , NULL ) ;
}
if ( V_240 && V_4 -> V_22 & V_39 && V_4 -> V_25 . V_2 == V_2 &&
F_132 ( V_243 , V_4 -> V_16 + V_240 ) &&
! F_133 ( V_243 , V_2 -> V_254 , V_2 -> V_254 + V_240 ) ) {
F_29 ( V_42 , L_17 ) ;
F_63 ( V_2 , V_255 ) ;
}
V_242 = ( F_132 ( V_243 , V_4 -> V_16 + V_241 ) ? V_243 : V_4 -> V_16 ) + V_241 ;
F_79 ( & V_51 -> V_174 ) ;
F_131 ( & V_2 -> V_249 , V_242 ) ;
}
