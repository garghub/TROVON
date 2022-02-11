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
V_4 -> V_12 . V_27 = V_19 -> V_28 ;
V_4 -> V_12 . V_13 = V_19 -> V_29 ;
V_4 -> V_12 . V_30 = true ;
V_4 -> V_12 . V_31 = false ;
F_15 ( & V_4 -> V_32 ) ;
F_15 ( & V_4 -> V_25 . V_33 ) ;
F_16 ( & V_4 -> V_34 , 1 ) ;
F_17 ( & V_4 -> V_35 ) ;
return V_4 ;
}
void F_18 ( struct V_35 * V_35 )
{
struct V_3 * V_4 = F_19 ( V_35 , struct V_3 , V_35 ) ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
const unsigned V_36 = V_4 -> V_22 ;
if ( ( V_4 -> V_6 && ! ( V_36 & V_37 ) ) ||
F_20 ( & V_4 -> V_34 ) ||
( V_36 & V_38 ) ||
( ( V_36 & V_39 ) && ! ( V_36 & V_40 ) ) ) {
F_21 ( V_41 , L_1 ,
V_36 , F_20 ( & V_4 -> V_34 ) ) ;
return;
}
F_22 ( & V_4 -> V_32 ) ;
if ( V_36 & V_24 ) {
if ( ( V_36 & ( V_37 | V_42 | V_39 ) ) != V_37 ) {
if ( ! ( V_36 & V_43 ) || ! ( V_36 & V_44 ) )
F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
if ( ( V_36 & V_43 ) && ( V_36 & V_44 ) && ( V_36 & V_45 ) )
F_24 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
if ( V_36 & V_46 ) {
if ( F_25 ( V_2 , V_47 ) ) {
F_26 ( V_2 , & V_4 -> V_12 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_48 ) ) {
F_29 ( V_41 , L_2
L_3 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
}
}
}
F_30 ( V_4 , V_20 ) ;
}
static void F_31 ( struct V_49 * V_50 ) {
F_32 ( & V_50 -> V_51 . V_52 ) ;
}
void F_33 ( struct V_49 * V_50 )
{
if ( V_50 -> V_53 == 0 )
return;
V_50 -> V_53 = 0 ;
F_34 ( & V_50 -> V_54 ) ;
F_31 ( V_50 ) ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_36 ( V_56 -> V_18 , V_56 -> error ) ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_57 * V_58 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_59 * V_12 = & V_4 -> V_12 ;
F_39 ( V_58 , V_12 ) ;
if ( V_12 -> V_31 )
F_32 ( & V_2 -> V_60 ) ;
}
static
void F_40 ( struct V_3 * V_4 , struct V_55 * V_56 )
{
const unsigned V_36 = V_4 -> V_22 ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
int V_5 ;
int error , V_61 ;
if ( ( V_36 & V_38 && ! ( V_36 & V_62 ) ) ||
( V_36 & V_63 ) || ( V_36 & V_64 ) ||
( V_36 & V_65 ) ) {
F_21 ( V_41 , L_4 , V_36 ) ;
return;
}
if ( ! V_4 -> V_6 ) {
F_21 ( V_41 , L_5 ) ;
return;
}
V_5 = F_41 ( V_4 -> V_6 ) ;
V_61 = ( V_36 & V_44 ) || ( V_36 & V_43 ) ;
error = F_42 ( V_4 -> V_66 ) ;
if ( ! F_43 ( & V_4 -> V_12 ) ) {
struct V_57 * V_58 ;
if ( V_5 == V_23 )
V_58 = & V_2 -> V_67 ;
else
V_58 = & V_2 -> V_68 ;
F_38 ( V_58 , V_4 ) ;
}
if ( V_5 == V_23 &&
V_4 -> V_26 == F_20 ( & V_2 -> V_50 -> V_54 ) )
F_33 ( V_2 -> V_50 ) ;
F_9 ( V_2 , V_4 ) ;
if ( ! V_61 && V_5 == V_69 && ! F_44 ( & V_4 -> V_32 ) )
V_4 -> V_22 |= V_37 ;
if ( ! ( V_4 -> V_22 & V_37 ) ) {
V_56 -> error = V_61 ? 0 : ( error ? : - V_70 ) ;
V_56 -> V_18 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
}
static int F_45 ( struct V_3 * V_4 , struct V_55 * V_56 , int V_71 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
F_46 ( V_56 || ( V_4 -> V_22 & V_37 ) ) ;
if ( ! F_47 ( V_71 , & V_4 -> V_34 ) )
return 0 ;
F_40 ( V_4 , V_56 ) ;
if ( V_4 -> V_22 & V_37 ) {
F_48 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_49 ( struct V_3 * V_4 , struct V_55 * V_56 ,
int V_72 , int V_73 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
unsigned V_36 = V_4 -> V_22 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( F_50 ( V_2 ) && ! ( ( V_36 | V_72 ) & V_65 ) )
V_73 |= V_65 ;
V_4 -> V_22 &= ~ V_72 ;
V_4 -> V_22 |= V_73 ;
if ( V_4 -> V_22 == V_36 )
return;
if ( ! ( V_36 & V_38 ) && ( V_73 & V_38 ) )
F_34 ( & V_4 -> V_34 ) ;
if ( ! ( V_36 & V_64 ) && ( V_73 & V_64 ) ) {
F_51 ( V_2 ) ;
F_34 ( & V_4 -> V_34 ) ;
}
if ( ! ( V_36 & V_63 ) && ( V_73 & V_63 ) )
F_34 ( & V_4 -> V_34 ) ;
if ( ! ( V_36 & V_76 ) && ( V_73 & V_76 ) )
F_52 ( & V_4 -> V_35 ) ;
if ( ! ( V_36 & V_77 ) && ( V_73 & V_77 ) )
F_53 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_78 ) ;
if ( ! ( V_36 & V_65 ) && ( V_73 & V_65 ) )
F_34 ( & V_4 -> V_34 ) ;
if ( ( V_36 & V_65 ) && ( V_72 & V_65 ) )
++ V_74 ;
if ( ! ( V_36 & V_62 ) && ( V_73 & V_62 ) ) {
F_46 ( V_4 -> V_22 & V_38 ) ;
F_52 ( & V_4 -> V_35 ) ;
++ V_74 ;
}
if ( ( V_36 & V_38 ) && ( V_72 & V_38 ) ) {
if ( V_4 -> V_22 & V_62 )
++ V_75 ;
else
++ V_74 ;
}
if ( ( V_36 & V_64 ) && ( V_72 & V_64 ) ) {
F_54 ( V_2 ) ;
++ V_74 ;
}
if ( ( V_36 & V_63 ) && ( V_72 & V_63 ) )
++ V_74 ;
if ( ( V_36 & V_76 ) && ! ( V_36 & V_40 ) && ( V_73 & V_40 ) ) {
if ( V_4 -> V_22 & V_77 )
F_55 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_78 ) ;
++ V_75 ;
}
if ( V_75 || V_74 ) {
int V_79 = V_75 + ! ! V_74 ;
int V_80 = F_20 ( & V_4 -> V_35 . V_80 ) ;
if ( V_80 < V_79 )
F_21 ( V_41 ,
L_6 ,
V_36 , V_4 -> V_22 , V_80 , V_79 ) ;
}
if ( V_4 -> V_12 . V_31 )
F_32 ( & V_2 -> V_60 ) ;
if ( V_74 )
V_75 += F_45 ( V_4 , V_56 , V_74 ) ;
if ( V_75 )
F_56 ( & V_4 -> V_35 , V_75 , F_18 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_81 [ V_82 ] ;
if ( ! F_28 ( & V_48 ) )
return;
F_29 ( V_41 , L_7 ,
( V_4 -> V_22 & V_24 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_12 . V_27 ,
V_4 -> V_12 . V_13 >> 9 ,
F_58 ( V_2 -> V_83 -> V_84 , V_81 ) ) ;
}
int F_59 ( struct V_3 * V_4 , enum V_85 V_86 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_87 * V_88 ;
int V_89 , V_90 = 0 ;
if ( V_56 )
V_56 -> V_18 = NULL ;
switch ( V_86 ) {
default:
F_21 ( V_41 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_91 :
F_46 ( ! ( V_4 -> V_22 & V_39 ) ) ;
F_60 () ;
V_88 = F_61 ( V_2 -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_92 ;
F_62 () ;
V_4 -> V_22 |=
V_89 == V_93 ? V_94 :
V_89 == V_95 ? V_96 : 0 ;
F_49 ( V_4 , V_56 , 0 , V_64 ) ;
break;
case V_97 :
F_46 ( ! ( V_4 -> V_22 & V_42 ) ) ;
F_49 ( V_4 , V_56 , 0 , V_38 ) ;
break;
case V_98 :
if ( V_4 -> V_22 & V_24 )
V_2 -> V_99 += V_4 -> V_12 . V_13 >> 9 ;
else
V_2 -> V_100 += V_4 -> V_12 . V_13 >> 9 ;
F_49 ( V_4 , V_56 , V_38 ,
V_101 | V_44 ) ;
break;
case V_102 :
F_49 ( V_4 , V_56 , 0 , V_62 ) ;
break;
case V_103 :
F_57 ( V_2 , V_4 ) ;
F_63 ( V_2 , V_104 ) ;
F_49 ( V_4 , V_56 , V_38 , V_101 ) ;
break;
case V_105 :
F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ;
F_57 ( V_2 , V_4 ) ;
F_63 ( V_2 , V_106 ) ;
case V_107 :
F_49 ( V_4 , V_56 , V_38 , V_101 ) ;
break;
case V_108 :
F_46 ( F_43 ( & V_4 -> V_12 ) ) ;
F_64 ( & V_2 -> V_68 , & V_4 -> V_12 ) ;
F_65 ( V_109 , & V_2 -> V_110 ) ;
F_46 ( V_4 -> V_22 & V_64 ) ;
F_46 ( ( V_4 -> V_22 & V_42 ) == 0 ) ;
F_49 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_25 . V_111 = V_112 ;
F_66 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_25 ) ;
break;
case V_113 :
F_46 ( F_43 ( & V_4 -> V_12 ) ) ;
F_64 ( & V_2 -> V_67 , & V_4 -> V_12 ) ;
F_65 ( V_109 , & V_2 -> V_110 ) ;
F_46 ( V_4 -> V_22 & V_64 ) ;
F_49 ( V_4 , V_56 , 0 , V_63 | V_76 ) ;
V_4 -> V_25 . V_111 = V_114 ;
F_66 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_25 ) ;
F_60 () ;
V_88 = F_61 ( V_2 -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_115 ;
F_62 () ;
if ( V_2 -> V_50 -> V_53 >= V_89 )
F_33 ( V_2 -> V_50 ) ;
break;
case V_116 :
F_49 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_25 . V_111 = V_117 ;
F_66 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_25 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
F_49 ( V_4 , V_56 , V_63 , 0 ) ;
break;
case V_121 :
if ( F_2 ( V_4 -> V_6 ) == V_23 &&
! ( V_4 -> V_22 & ( V_96 | V_94 ) ) ) {
if ( V_4 -> V_22 & V_64 )
F_49 ( V_4 , V_56 , V_64 , V_43 ) ;
}
F_49 ( V_4 , V_56 , V_63 , V_77 ) ;
break;
case V_122 :
F_49 ( V_4 , V_56 , V_63 , V_40 ) ;
break;
case V_123 :
F_49 ( V_4 , V_56 ,
V_43 | V_64 | V_65 ,
V_40 ) ;
break;
case V_124 :
F_46 ( V_4 -> V_22 & V_64 ) ;
F_46 ( V_4 -> V_22 & V_94 ) ;
F_49 ( V_4 , V_56 , V_64 , V_40 | V_43 ) ;
break;
case V_125 :
V_4 -> V_22 |= V_45 ;
case V_126 :
F_46 ( V_4 -> V_22 & V_94 ) ;
goto V_127;
case V_128 :
F_46 ( V_4 -> V_22 & V_96 ) ;
V_127:
F_46 ( V_4 -> V_22 & V_64 ) ;
F_49 ( V_4 , V_56 , V_64 , V_43 ) ;
break;
case V_129 :
F_46 ( V_4 -> V_22 & V_94 ) ;
F_46 ( V_4 -> V_22 & V_64 ) ;
V_4 -> V_22 |= V_37 ;
if ( V_4 -> V_12 . V_31 )
F_32 ( & V_2 -> V_60 ) ;
break;
case V_130 :
F_49 ( V_4 , V_56 , V_43 | V_64 , 0 ) ;
break;
case V_131 :
if ( ! ( V_4 -> V_22 & V_101 ) )
break;
F_49 ( V_4 , V_56 , V_65 , 0 ) ;
break;
case V_132 :
if ( ! ( V_4 -> V_22 & V_101 ) )
break;
F_49 ( V_4 , V_56 ,
V_65 | V_101 ,
V_38 ) ;
V_90 = V_133 ;
if ( F_2 ( V_4 -> V_6 ) == V_23 )
V_90 = V_134 ;
F_67 ( V_2 ) ;
V_4 -> V_25 . V_111 = V_135 ;
F_66 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_25 ) ;
break;
case V_136 :
if ( ! ( V_4 -> V_22 & V_24 ) && ! V_4 -> V_25 . V_111 ) {
F_49 ( V_4 , V_56 , V_65 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_22 & V_43 ) ) {
F_49 ( V_4 , V_56 , V_65 , V_63 | V_64 ) ;
if ( V_4 -> V_25 . V_111 ) {
F_66 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_25 ) ;
V_90 = V_4 -> V_22 & V_24 ? V_134 : V_133 ;
}
break;
}
case V_137 :
if ( ! ( V_4 -> V_22 & V_24 ) )
break;
if ( V_4 -> V_22 & V_64 ) {
F_21 ( V_41 , L_11 ) ;
}
F_49 ( V_4 , V_56 , V_65 ,
( V_4 -> V_22 & V_39 ) ? V_40 : 0 ) ;
break;
case V_138 :
F_46 ( V_4 -> V_22 & V_64 ) ;
F_49 ( V_4 , V_56 , V_64 , V_43 | V_40 ) ;
break;
case V_139 :
F_33 ( V_2 -> V_50 ) ;
F_49 ( V_4 , V_56 , 0 , V_43 | V_40 ) ;
break;
} ;
return V_90 ;
}
static bool F_68 ( struct V_1 * V_2 , T_1 V_27 , int V_13 )
{
unsigned long V_140 , V_141 ;
T_1 V_142 , V_143 ;
if ( V_2 -> V_144 . V_145 == V_146 )
return true ;
if ( V_2 -> V_144 . V_145 != V_147 )
return false ;
V_142 = V_27 + ( V_13 >> 9 ) - 1 ;
V_143 = F_69 ( V_2 -> V_148 ) ;
F_46 ( V_27 < V_143 ) ;
F_46 ( V_142 < V_143 ) ;
V_140 = F_70 ( V_27 ) ;
V_141 = F_70 ( V_142 ) ;
return F_71 ( V_2 , V_140 , V_141 ) == 0 ;
}
static bool F_72 ( struct V_1 * V_2 , T_1 V_27 ,
enum V_149 V_150 )
{
struct V_151 * V_152 ;
int V_153 ;
switch ( V_150 ) {
case V_154 :
V_152 = & V_2 -> V_83 -> V_84 -> V_155 -> V_156 -> V_151 ;
return F_73 ( V_152 ) ;
case V_157 :
return F_20 ( & V_2 -> V_158 ) >
F_20 ( & V_2 -> V_159 ) + F_20 ( & V_2 -> V_160 ) ;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_153 = ( V_150 - V_161 + 15 ) ;
return ( V_27 >> ( V_153 - 9 ) ) & 1 ;
case V_167 :
return F_74 ( V_168 , & V_2 -> V_110 ) ;
case V_169 :
return true ;
case V_170 :
default:
return false ;
}
}
static void F_75 ( struct V_3 * V_4 )
{
F_76 ( V_171 ) ;
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_59 * V_12 ;
T_1 V_27 = V_4 -> V_12 . V_27 ;
int V_13 = V_4 -> V_12 . V_13 ;
V_12 = F_77 ( & V_2 -> V_67 , V_27 , V_13 ) ;
if ( ! V_12 )
return;
for (; ; ) {
F_78 ( & V_2 -> V_60 , & V_171 , V_172 ) ;
V_12 = F_77 ( & V_2 -> V_67 , V_27 , V_13 ) ;
if ( ! V_12 )
break;
V_12 -> V_31 = true ;
F_79 ( & V_2 -> V_50 -> V_173 ) ;
F_80 () ;
F_81 ( & V_2 -> V_50 -> V_173 ) ;
}
F_82 ( & V_2 -> V_60 , & V_171 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_87 * V_88 ;
bool V_174 = false ;
enum V_175 V_176 ;
F_60 () ;
V_88 = F_61 ( V_50 -> V_87 ) ;
V_176 = V_88 ? V_88 -> V_176 : V_177 ;
F_62 () ;
if ( V_176 == V_177 ||
V_50 -> V_178 < 96 )
return;
if ( ! F_25 ( V_2 , V_146 ) )
return;
if ( V_88 -> V_179 &&
F_20 ( & V_2 -> V_78 ) >= V_88 -> V_179 ) {
F_84 ( V_41 , L_12 ) ;
V_174 = true ;
}
if ( V_2 -> V_180 -> V_181 >= V_88 -> V_182 ) {
F_84 ( V_41 , L_13 ) ;
V_174 = true ;
}
if ( V_174 ) {
F_33 ( V_2 -> V_50 ) ;
if ( V_176 == V_183 )
F_85 ( F_86 ( V_2 , V_184 , V_185 ) , 0 , NULL ) ;
else
F_85 ( F_86 ( V_2 , V_184 , V_186 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
enum V_149 V_150 ;
if ( V_4 -> V_66 ) {
if ( ! F_68 ( V_2 ,
V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) ) {
F_88 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_144 . V_187 != V_146 )
return false ;
if ( V_4 -> V_66 == NULL )
return true ;
F_60 () ;
V_150 = F_61 ( V_2 -> V_83 -> V_188 ) -> V_189 ;
F_62 () ;
if ( V_150 == V_170 && V_4 -> V_66 )
return false ;
if ( F_72 ( V_2 , V_4 -> V_12 . V_27 , V_150 ) ) {
if ( V_4 -> V_66 ) {
F_88 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
int V_190 , V_191 ;
V_190 = F_90 ( V_2 -> V_144 ) ;
V_191 = F_91 ( V_2 -> V_144 ) ;
if ( F_92 ( V_4 -> V_12 . V_13 == 0 ) ) {
F_46 ( V_4 -> V_6 -> V_192 & V_193 ) ;
if ( V_190 )
F_93 ( V_4 , V_139 ) ;
return V_190 ;
}
if ( ! V_190 && ! V_191 )
return 0 ;
F_46 ( ! ( V_190 && V_191 ) ) ;
if ( V_190 ) {
F_93 ( V_4 , V_91 ) ;
F_93 ( V_4 , V_113 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 ) )
F_93 ( V_4 , V_116 ) ;
return V_190 ;
}
static void
F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_25 . V_2 ;
struct V_18 * V_18 = V_4 -> V_66 ;
const int V_5 = F_41 ( V_18 ) ;
V_18 -> V_194 = V_2 -> V_83 -> V_84 ;
if ( F_67 ( V_2 ) ) {
if ( F_95 ( V_2 ,
V_5 == V_23 ? V_195
: V_5 == V_69 ? V_196
: V_197 ) )
F_36 ( V_18 , - V_70 ) ;
else
F_96 ( V_18 ) ;
F_27 ( V_2 ) ;
} else
F_36 ( V_18 , - V_70 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_98 ( & V_2 -> V_198 . V_199 ) ;
F_99 ( & V_4 -> V_32 , & V_2 -> V_198 . V_200 ) ;
F_100 ( & V_2 -> V_198 . V_199 ) ;
F_101 ( V_2 -> V_198 . V_201 , & V_2 -> V_198 . V_202 ) ;
}
struct V_3 *
F_102 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
const int V_5 = F_2 ( V_18 ) ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_18 ) ;
if ( ! V_4 ) {
F_37 ( V_2 ) ;
F_21 ( V_41 , L_14 ) ;
F_36 ( V_18 , - V_203 ) ;
return F_103 ( - V_203 ) ;
}
V_4 -> V_16 = V_16 ;
if ( ! F_67 ( V_2 ) ) {
F_88 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_5 == V_23 && V_4 -> V_66 && V_4 -> V_12 . V_13
&& ! F_104 ( V_204 , & V_2 -> V_110 ) ) {
if ( ! F_105 ( V_2 , & V_4 -> V_12 ) ) {
F_97 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_22 |= V_46 ;
}
return V_4 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const int V_5 = F_41 ( V_4 -> V_6 ) ;
struct V_55 V_56 = { NULL , } ;
bool V_205 = false ;
F_81 ( & V_2 -> V_50 -> V_173 ) ;
if ( V_5 == V_23 ) {
F_75 ( V_4 ) ;
F_83 ( V_2 ) ;
}
if ( F_50 ( V_2 ) ) {
V_4 -> V_22 |= V_37 ;
if ( V_4 -> V_66 ) {
F_88 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
goto V_206;
}
if ( V_5 != V_23 ) {
if ( ! F_87 ( V_4 ) && ! V_4 -> V_66 )
goto V_207;
}
V_4 -> V_26 = F_20 ( & V_2 -> V_50 -> V_54 ) ;
if ( F_107 ( V_4 -> V_12 . V_13 != 0 ) ) {
if ( V_5 == V_23 )
V_2 -> V_50 -> V_53 ++ ;
F_99 ( & V_4 -> V_32 , & V_2 -> V_50 -> V_208 ) ;
}
if ( V_5 == V_23 ) {
if ( ! F_89 ( V_4 ) )
V_205 = true ;
} else {
if ( V_4 -> V_66 == NULL ) {
F_93 ( V_4 , V_91 ) ;
F_93 ( V_4 , V_108 ) ;
} else
V_205 = true ;
}
if ( V_4 -> V_66 ) {
F_93 ( V_4 , V_97 ) ;
F_79 ( & V_2 -> V_50 -> V_173 ) ;
F_94 ( V_4 ) ;
F_81 ( & V_2 -> V_50 -> V_173 ) ;
} else if ( V_205 ) {
V_207:
if ( F_28 ( & V_48 ) )
F_21 ( V_41 , L_15 ,
( unsigned long long ) V_4 -> V_12 . V_27 , V_4 -> V_12 . V_13 >> 9 ) ;
}
V_206:
if ( F_45 ( V_4 , & V_56 , 1 ) )
F_108 ( & V_4 -> V_35 , F_18 ) ;
F_79 ( & V_2 -> V_50 -> V_173 ) ;
if ( V_56 . V_18 )
F_35 ( V_2 , & V_56 ) ;
}
void F_109 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
struct V_3 * V_4 = F_102 ( V_2 , V_18 , V_16 ) ;
if ( F_110 ( V_4 ) )
return;
F_106 ( V_2 , V_4 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_209 * V_210 )
{
struct V_3 * V_4 , * V_211 ;
F_112 (req, tmp, incoming, tl_requests) {
const int V_5 = F_2 ( V_4 -> V_6 ) ;
if ( V_5 == V_23
&& V_4 -> V_66 && V_4 -> V_12 . V_13
&& ! F_104 ( V_204 , & V_2 -> V_110 ) ) {
if ( ! F_105 ( V_2 , & V_4 -> V_12 ) )
continue;
V_4 -> V_22 |= V_46 ;
}
F_22 ( & V_4 -> V_32 ) ;
F_106 ( V_2 , V_4 ) ;
}
}
static bool F_113 ( struct V_1 * V_2 ,
struct V_209 * V_210 ,
struct V_209 * V_212 )
{
struct V_3 * V_4 , * V_211 ;
int V_213 = 0 ;
int V_214 ;
F_81 ( & V_2 -> V_215 ) ;
F_112 (req, tmp, incoming, tl_requests) {
V_214 = F_114 ( V_2 , & V_4 -> V_12 ) ;
if ( V_214 == - V_216 )
V_213 = 1 ;
if ( V_214 )
continue;
V_4 -> V_22 |= V_46 ;
F_115 ( & V_4 -> V_32 , V_212 ) ;
}
F_79 ( & V_2 -> V_215 ) ;
if ( V_213 )
F_32 ( & V_2 -> V_217 ) ;
return ! F_44 ( V_212 ) ;
}
void F_116 ( struct V_218 * V_219 )
{
struct V_1 * V_2 = F_19 ( V_219 , struct V_1 , V_198 . V_202 ) ;
F_117 ( V_210 ) ;
F_117 ( V_212 ) ;
struct V_3 * V_4 , * V_211 ;
for (; ; ) {
F_98 ( & V_2 -> V_198 . V_199 ) ;
F_118 ( & V_2 -> V_198 . V_200 , & V_210 ) ;
F_100 ( & V_2 -> V_198 . V_199 ) ;
F_111 ( V_2 , & V_210 ) ;
if ( F_44 ( & V_210 ) )
break;
F_119 ( V_2 -> V_217 , F_113 ( V_2 , & V_210 , & V_212 ) ) ;
for (; ; ) {
F_117 ( V_220 ) ;
F_117 ( V_221 ) ;
bool V_222 ;
if ( F_44 ( & V_2 -> V_198 . V_200 ) )
break;
F_98 ( & V_2 -> V_198 . V_199 ) ;
F_118 ( & V_2 -> V_198 . V_200 , & V_221 ) ;
F_100 ( & V_2 -> V_198 . V_199 ) ;
if ( F_44 ( & V_221 ) )
break;
V_222 = F_113 ( V_2 , & V_221 , & V_220 ) ;
F_118 ( & V_220 , & V_212 ) ;
F_118 ( & V_221 , & V_210 ) ;
if ( ! V_222 )
break;
}
F_120 ( V_2 , false ) ;
F_112 (req, tmp, &pending, tl_requests) {
F_22 ( & V_4 -> V_32 ) ;
F_106 ( V_2 , V_4 ) ;
}
}
}
void F_121 ( struct V_223 * V_224 , struct V_18 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_224 -> V_225 ;
unsigned long V_16 ;
V_16 = V_15 ;
F_46 ( F_122 ( V_18 -> V_29 , 512 ) ) ;
F_123 ( V_2 ) ;
F_109 ( V_2 , V_18 , V_16 ) ;
}
int F_124 ( struct V_223 * V_224 , struct V_226 * V_227 , struct V_228 * V_229 )
{
struct V_1 * V_2 = (struct V_1 * ) V_224 -> V_225 ;
unsigned int V_230 = V_227 -> V_29 ;
int V_231 = V_232 ;
int V_233 ;
if ( V_230 && F_67 ( V_2 ) ) {
unsigned int V_234 = F_125 ( V_224 ) ;
struct V_223 * const V_81 =
V_2 -> V_83 -> V_84 -> V_155 -> V_156 ;
if ( V_81 -> V_235 ) {
V_233 = V_81 -> V_235 ( V_81 , V_227 , V_229 ) ;
V_231 = F_126 ( V_231 , V_233 ) ;
}
F_27 ( V_2 ) ;
if ( ( V_231 >> 9 ) > V_234 )
V_231 = V_234 << 9 ;
}
return V_231 ;
}
struct V_3 * F_127 ( struct V_49 * V_50 )
{
struct V_3 * V_236 ;
F_128 (r, &tconn->transfer_log, tl_requests) {
if ( F_20 ( & V_236 -> V_34 ) )
return V_236 ;
}
return NULL ;
}
void F_129 ( unsigned long V_237 )
{
struct V_1 * V_2 = (struct V_1 * ) V_237 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_3 * V_4 ;
struct V_87 * V_88 ;
unsigned long V_238 = 0 , V_239 = 0 , V_240 , V_241 ;
unsigned long V_242 ;
F_60 () ;
V_88 = F_61 ( V_50 -> V_87 ) ;
if ( V_88 && V_2 -> V_144 . V_184 >= V_243 )
V_238 = V_88 -> V_244 * V_245 / 10 * V_88 -> V_246 ;
if ( F_67 ( V_2 ) ) {
V_239 = F_61 ( V_2 -> V_83 -> V_188 ) -> V_247 * V_245 / 10 ;
F_27 ( V_2 ) ;
}
F_62 () ;
V_240 = F_130 ( V_239 , V_238 ) ;
if ( ! V_240 )
return;
V_242 = V_15 ;
F_81 ( & V_50 -> V_173 ) ;
V_4 = F_127 ( V_50 ) ;
if ( ! V_4 ) {
F_79 ( & V_50 -> V_173 ) ;
F_131 ( & V_2 -> V_248 , V_242 + V_240 ) ;
return;
}
if ( V_238 && V_4 -> V_22 & V_64 &&
F_132 ( V_242 , V_4 -> V_16 + V_238 ) &&
! F_133 ( V_242 , V_50 -> V_249 , V_50 -> V_249 + V_238 ) ) {
F_29 ( V_41 , L_16 ) ;
F_85 ( F_86 ( V_2 , V_184 , V_250 ) , V_251 | V_252 , NULL ) ;
}
if ( V_239 && V_4 -> V_22 & V_38 && V_4 -> V_25 . V_2 == V_2 &&
F_132 ( V_242 , V_4 -> V_16 + V_239 ) &&
! F_133 ( V_242 , V_2 -> V_253 , V_2 -> V_253 + V_239 ) ) {
F_29 ( V_41 , L_17 ) ;
F_63 ( V_2 , V_254 ) ;
}
V_241 = ( F_132 ( V_242 , V_4 -> V_16 + V_240 ) ? V_242 : V_4 -> V_16 ) + V_240 ;
F_79 ( & V_50 -> V_173 ) ;
F_131 ( & V_2 -> V_248 , V_241 ) ;
}
