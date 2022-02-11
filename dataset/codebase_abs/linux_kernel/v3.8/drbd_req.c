static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_5 )
{
const int V_6 = F_2 ( V_5 ) ;
int V_7 ;
V_7 = F_3 () ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_5 ( V_7 , & V_2 -> V_8 -> V_9 , V_10 [ V_6 ] ) ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_11 [ V_6 ] , F_7 ( V_5 ) ) ;
( void ) V_7 ;
F_8 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_12 ) ;
unsigned long V_13 = V_14 - V_4 -> V_15 ;
int V_7 ;
V_7 = F_3 () ;
F_6 ( V_7 , & V_2 -> V_8 -> V_9 , V_16 [ V_6 ] , V_13 ) ;
F_4 ( V_7 , & V_2 -> V_8 -> V_9 ) ;
F_11 ( & V_2 -> V_8 -> V_9 , V_6 ) ;
F_9 () ;
}
static struct V_3 * F_12 ( struct V_1 * V_2 ,
struct V_5 * V_17 )
{
struct V_3 * V_4 ;
V_4 = F_13 ( V_18 , V_19 ) ;
if ( ! V_4 )
return NULL ;
F_14 ( V_4 , V_17 ) ;
V_4 -> V_20 = F_2 ( V_17 ) == V_21 ? V_22 : 0 ;
V_4 -> V_23 . V_2 = V_2 ;
V_4 -> V_12 = V_17 ;
V_4 -> V_24 = 0 ;
F_15 ( & V_4 -> V_25 ) ;
V_4 -> V_25 . V_26 = V_17 -> V_27 ;
V_4 -> V_25 . V_28 = V_17 -> V_29 ;
V_4 -> V_25 . V_30 = true ;
V_4 -> V_25 . V_31 = false ;
F_16 ( & V_4 -> V_32 ) ;
F_16 ( & V_4 -> V_23 . V_33 ) ;
F_17 ( & V_4 -> V_34 , 1 ) ;
F_18 ( & V_4 -> V_35 ) ;
return V_4 ;
}
void F_19 ( struct V_35 * V_35 )
{
struct V_3 * V_4 = F_20 ( V_35 , struct V_3 , V_35 ) ;
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
const unsigned V_36 = V_4 -> V_20 ;
if ( ( V_4 -> V_12 && ! ( V_36 & V_37 ) ) ||
F_21 ( & V_4 -> V_34 ) ||
( V_36 & V_38 ) ||
( ( V_36 & V_39 ) && ! ( V_36 & V_40 ) ) ) {
F_22 ( V_41 , L_1 ,
V_36 , F_21 ( & V_4 -> V_34 ) ) ;
return;
}
F_23 ( & V_4 -> V_32 ) ;
if ( V_36 & V_22 ) {
if ( ( V_36 & ( V_37 | V_42 | V_39 ) ) != V_37 ) {
if ( ! ( V_36 & V_43 ) || ! ( V_36 & V_44 ) )
F_24 ( V_2 , V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) ;
if ( ( V_36 & V_43 ) && ( V_36 & V_44 ) && ( V_36 & V_45 ) )
F_25 ( V_2 , V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) ;
}
if ( V_36 & V_46 ) {
if ( F_26 ( V_2 , V_47 ) ) {
F_27 ( V_2 , & V_4 -> V_25 ) ;
F_28 ( V_2 ) ;
} else if ( F_29 ( & V_48 ) ) {
F_30 ( V_41 , L_2
L_3 ,
( unsigned long long ) V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) ;
}
}
}
F_31 ( V_4 , V_18 ) ;
}
static void F_32 ( struct V_49 * V_50 ) {
F_33 ( & V_50 -> V_51 . V_52 ) ;
}
void F_34 ( struct V_49 * V_50 )
{
if ( V_50 -> V_53 == 0 )
return;
V_50 -> V_53 = 0 ;
F_35 ( & V_50 -> V_54 ) ;
F_32 ( V_50 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_37 ( V_56 -> V_5 , V_56 -> error ) ;
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_57 * V_58 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
struct V_59 * V_25 = & V_4 -> V_25 ;
F_40 ( V_58 , V_25 ) ;
if ( V_25 -> V_31 )
F_33 ( & V_2 -> V_60 ) ;
}
static
void F_41 ( struct V_3 * V_4 , struct V_55 * V_56 )
{
const unsigned V_36 = V_4 -> V_20 ;
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
int V_6 ;
int error , V_61 ;
if ( ( V_36 & V_38 && ! ( V_36 & V_62 ) ) ||
( V_36 & V_63 ) || ( V_36 & V_64 ) ||
( V_36 & V_65 ) ) {
F_22 ( V_41 , L_4 , V_36 ) ;
return;
}
if ( ! V_4 -> V_12 ) {
F_22 ( V_41 , L_5 ) ;
return;
}
V_6 = F_42 ( V_4 -> V_12 ) ;
V_61 = ( V_36 & V_44 ) || ( V_36 & V_43 ) ;
error = F_43 ( V_4 -> V_66 ) ;
if ( ! F_44 ( & V_4 -> V_25 ) ) {
struct V_57 * V_58 ;
if ( V_6 == V_21 )
V_58 = & V_2 -> V_67 ;
else
V_58 = & V_2 -> V_68 ;
F_39 ( V_58 , V_4 ) ;
} else if ( ! ( V_36 & V_37 ) )
F_45 ( ( V_36 & ( V_39 & ~ V_40 ) ) == 0 ) ;
if ( V_6 == V_21 &&
V_4 -> V_24 == F_21 ( & V_2 -> V_50 -> V_54 ) )
F_34 ( V_2 -> V_50 ) ;
F_10 ( V_2 , V_4 ) ;
if ( ! V_61 && V_6 == V_69 && ! F_46 ( & V_4 -> V_32 ) )
V_4 -> V_20 |= V_37 ;
if ( ! ( V_4 -> V_20 & V_37 ) ) {
V_56 -> error = V_61 ? 0 : ( error ? : - V_70 ) ;
V_56 -> V_5 = V_4 -> V_12 ;
V_4 -> V_12 = NULL ;
}
}
static int F_47 ( struct V_3 * V_4 , struct V_55 * V_56 , int V_71 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
F_45 ( V_56 || ( V_4 -> V_20 & V_37 ) ) ;
if ( ! F_48 ( V_71 , & V_4 -> V_34 ) )
return 0 ;
F_41 ( V_4 , V_56 ) ;
if ( V_4 -> V_20 & V_37 ) {
F_49 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_3 * V_4 , struct V_55 * V_56 ,
int V_72 , int V_73 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
unsigned V_36 = V_4 -> V_20 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( F_51 ( V_2 ) && ! ( ( V_36 | V_72 ) & V_65 ) )
V_73 |= V_65 ;
V_4 -> V_20 &= ~ V_72 ;
V_4 -> V_20 |= V_73 ;
if ( V_4 -> V_20 == V_36 )
return;
if ( ! ( V_36 & V_38 ) && ( V_73 & V_38 ) )
F_35 ( & V_4 -> V_34 ) ;
if ( ! ( V_36 & V_64 ) && ( V_73 & V_64 ) ) {
F_52 ( V_2 ) ;
F_35 ( & V_4 -> V_34 ) ;
}
if ( ! ( V_36 & V_63 ) && ( V_73 & V_63 ) )
F_35 ( & V_4 -> V_34 ) ;
if ( ! ( V_36 & V_76 ) && ( V_73 & V_76 ) )
F_53 ( & V_4 -> V_35 ) ;
if ( ! ( V_36 & V_77 ) && ( V_73 & V_77 ) )
F_54 ( V_4 -> V_25 . V_28 >> 9 , & V_2 -> V_78 ) ;
if ( ! ( V_36 & V_65 ) && ( V_73 & V_65 ) )
F_35 ( & V_4 -> V_34 ) ;
if ( ( V_36 & V_65 ) && ( V_72 & V_65 ) )
++ V_74 ;
if ( ! ( V_36 & V_62 ) && ( V_73 & V_62 ) ) {
F_45 ( V_4 -> V_20 & V_38 ) ;
F_53 ( & V_4 -> V_35 ) ;
++ V_74 ;
}
if ( ( V_36 & V_38 ) && ( V_72 & V_38 ) ) {
if ( V_4 -> V_20 & V_62 )
++ V_75 ;
else
++ V_74 ;
}
if ( ( V_36 & V_64 ) && ( V_72 & V_64 ) ) {
F_55 ( V_2 ) ;
++ V_74 ;
}
if ( ( V_36 & V_63 ) && ( V_72 & V_63 ) )
++ V_74 ;
if ( ( V_36 & V_76 ) && ! ( V_36 & V_40 ) && ( V_73 & V_40 ) ) {
if ( V_4 -> V_20 & V_77 )
F_56 ( V_4 -> V_25 . V_28 >> 9 , & V_2 -> V_78 ) ;
++ V_75 ;
}
if ( V_75 || V_74 ) {
int V_79 = V_75 + ! ! V_74 ;
int V_80 = F_21 ( & V_4 -> V_35 . V_80 ) ;
if ( V_80 < V_79 )
F_22 ( V_41 ,
L_6 ,
V_36 , V_4 -> V_20 , V_80 , V_79 ) ;
}
if ( V_4 -> V_25 . V_31 )
F_33 ( & V_2 -> V_60 ) ;
if ( V_74 )
V_75 += F_47 ( V_4 , V_56 , V_74 ) ;
if ( V_75 )
F_57 ( & V_4 -> V_35 , V_75 , F_19 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_81 [ V_82 ] ;
if ( ! F_29 ( & V_48 ) )
return;
F_30 ( V_41 , L_7 ,
( V_4 -> V_20 & V_22 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_25 . V_26 ,
V_4 -> V_25 . V_28 >> 9 ,
F_59 ( V_2 -> V_83 -> V_84 , V_81 ) ) ;
}
int F_60 ( struct V_3 * V_4 , enum V_85 V_86 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
struct V_87 * V_88 ;
int V_89 , V_90 = 0 ;
if ( V_56 )
V_56 -> V_5 = NULL ;
switch ( V_86 ) {
default:
F_22 ( V_41 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_91 :
F_45 ( ! ( V_4 -> V_20 & V_39 ) ) ;
F_61 () ;
V_88 = F_62 ( V_2 -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_92 ;
F_63 () ;
V_4 -> V_20 |=
V_89 == V_93 ? V_94 :
V_89 == V_95 ? V_96 : 0 ;
F_50 ( V_4 , V_56 , 0 , V_64 ) ;
break;
case V_97 :
F_45 ( ! ( V_4 -> V_20 & V_42 ) ) ;
F_50 ( V_4 , V_56 , 0 , V_38 ) ;
break;
case V_98 :
if ( V_4 -> V_20 & V_22 )
V_2 -> V_99 += V_4 -> V_25 . V_28 >> 9 ;
else
V_2 -> V_100 += V_4 -> V_25 . V_28 >> 9 ;
F_50 ( V_4 , V_56 , V_38 ,
V_101 | V_44 ) ;
break;
case V_102 :
F_50 ( V_4 , V_56 , 0 , V_62 ) ;
break;
case V_103 :
F_58 ( V_2 , V_4 ) ;
F_64 ( V_2 , V_104 ) ;
F_50 ( V_4 , V_56 , V_38 , V_101 ) ;
break;
case V_105 :
F_24 ( V_2 , V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) ;
F_58 ( V_2 , V_4 ) ;
F_64 ( V_2 , V_106 ) ;
case V_107 :
F_50 ( V_4 , V_56 , V_38 , V_101 ) ;
break;
case V_108 :
F_45 ( F_44 ( & V_4 -> V_25 ) ) ;
F_65 ( & V_2 -> V_68 , & V_4 -> V_25 ) ;
F_66 ( V_109 , & V_2 -> V_110 ) ;
F_45 ( V_4 -> V_20 & V_64 ) ;
F_45 ( ( V_4 -> V_20 & V_42 ) == 0 ) ;
F_50 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_23 . V_111 = V_112 ;
F_67 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_23 ) ;
break;
case V_113 :
F_45 ( F_44 ( & V_4 -> V_25 ) ) ;
F_65 ( & V_2 -> V_67 , & V_4 -> V_25 ) ;
F_66 ( V_109 , & V_2 -> V_110 ) ;
F_45 ( V_4 -> V_20 & V_64 ) ;
F_50 ( V_4 , V_56 , 0 , V_63 | V_76 ) ;
V_4 -> V_23 . V_111 = V_114 ;
F_67 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_23 ) ;
F_61 () ;
V_88 = F_62 ( V_2 -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_115 ;
F_63 () ;
if ( V_2 -> V_50 -> V_53 >= V_89 )
F_34 ( V_2 -> V_50 ) ;
break;
case V_116 :
F_50 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_23 . V_111 = V_117 ;
F_67 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_23 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
F_50 ( V_4 , V_56 , V_63 , 0 ) ;
break;
case V_121 :
if ( F_2 ( V_4 -> V_12 ) == V_21 &&
! ( V_4 -> V_20 & ( V_96 | V_94 ) ) ) {
if ( V_4 -> V_20 & V_64 )
F_50 ( V_4 , V_56 , V_64 , V_43 ) ;
}
F_50 ( V_4 , V_56 , V_63 , V_77 ) ;
break;
case V_122 :
F_50 ( V_4 , V_56 , V_63 , V_40 ) ;
break;
case V_123 :
F_50 ( V_4 , V_56 ,
V_43 | V_64 | V_65 ,
V_40 ) ;
break;
case V_124 :
F_45 ( V_4 -> V_20 & V_64 ) ;
F_45 ( V_4 -> V_20 & V_94 ) ;
F_50 ( V_4 , V_56 , V_64 , V_40 | V_43 ) ;
break;
case V_125 :
V_4 -> V_20 |= V_45 ;
case V_126 :
F_45 ( V_4 -> V_20 & V_94 ) ;
goto V_127;
case V_128 :
F_45 ( V_4 -> V_20 & V_96 ) ;
V_127:
F_45 ( V_4 -> V_20 & V_64 ) ;
F_50 ( V_4 , V_56 , V_64 , V_43 ) ;
break;
case V_129 :
F_45 ( V_4 -> V_20 & V_94 ) ;
F_45 ( V_4 -> V_20 & V_64 ) ;
V_4 -> V_20 |= V_37 ;
if ( V_4 -> V_25 . V_31 )
F_33 ( & V_2 -> V_60 ) ;
break;
case V_130 :
F_50 ( V_4 , V_56 , V_43 | V_64 , 0 ) ;
break;
case V_131 :
if ( ! ( V_4 -> V_20 & V_101 ) )
break;
F_50 ( V_4 , V_56 , V_65 , 0 ) ;
break;
case V_132 :
if ( ! ( V_4 -> V_20 & V_101 ) )
break;
F_50 ( V_4 , V_56 ,
V_65 | V_101 ,
V_38 ) ;
V_90 = V_133 ;
if ( F_2 ( V_4 -> V_12 ) == V_21 )
V_90 = V_134 ;
F_68 ( V_2 ) ;
V_4 -> V_23 . V_111 = V_135 ;
F_67 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_23 ) ;
break;
case V_136 :
if ( ! ( V_4 -> V_20 & V_22 ) && ! V_4 -> V_23 . V_111 ) {
F_50 ( V_4 , V_56 , V_65 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_20 & V_43 ) ) {
F_50 ( V_4 , V_56 , V_65 , V_63 | V_64 ) ;
if ( V_4 -> V_23 . V_111 ) {
F_67 ( & V_2 -> V_50 -> V_51 , & V_4 -> V_23 ) ;
V_90 = V_4 -> V_20 & V_22 ? V_134 : V_133 ;
}
break;
}
case V_137 :
if ( ! ( V_4 -> V_20 & V_22 ) )
break;
if ( V_4 -> V_20 & V_64 ) {
F_22 ( V_41 , L_11 ) ;
}
F_50 ( V_4 , V_56 , V_65 ,
( V_4 -> V_20 & V_39 ) ? V_40 : 0 ) ;
break;
case V_138 :
F_45 ( V_4 -> V_20 & V_64 ) ;
F_50 ( V_4 , V_56 , V_64 , V_43 | V_40 ) ;
break;
} ;
return V_90 ;
}
static bool F_69 ( struct V_1 * V_2 , T_1 V_26 , int V_28 )
{
unsigned long V_139 , V_140 ;
T_1 V_141 , V_142 ;
if ( V_2 -> V_143 . V_144 == V_145 )
return true ;
if ( V_2 -> V_143 . V_144 != V_146 )
return false ;
V_141 = V_26 + ( V_28 >> 9 ) - 1 ;
V_142 = F_70 ( V_2 -> V_147 ) ;
F_45 ( V_26 < V_142 ) ;
F_45 ( V_141 < V_142 ) ;
V_139 = F_71 ( V_26 ) ;
V_140 = F_71 ( V_141 ) ;
return F_72 ( V_2 , V_139 , V_140 ) == 0 ;
}
static bool F_73 ( struct V_1 * V_2 , T_1 V_26 ,
enum V_148 V_149 )
{
struct V_150 * V_151 ;
int V_152 ;
switch ( V_149 ) {
case V_153 :
V_151 = & V_2 -> V_83 -> V_84 -> V_154 -> V_155 -> V_150 ;
return F_74 ( V_151 ) ;
case V_156 :
return F_21 ( & V_2 -> V_157 ) >
F_21 ( & V_2 -> V_158 ) + F_21 ( & V_2 -> V_159 ) ;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_152 = ( V_149 - V_160 + 15 ) ;
return ( V_26 >> ( V_152 - 9 ) ) & 1 ;
case V_166 :
return F_75 ( V_167 , & V_2 -> V_110 ) ;
case V_168 :
return true ;
case V_169 :
default:
return false ;
}
}
static void F_76 ( struct V_3 * V_4 )
{
F_77 ( V_170 ) ;
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
struct V_59 * V_25 ;
T_1 V_26 = V_4 -> V_25 . V_26 ;
int V_28 = V_4 -> V_25 . V_28 ;
V_25 = F_78 ( & V_2 -> V_67 , V_26 , V_28 ) ;
if ( ! V_25 )
return;
for (; ; ) {
F_79 ( & V_2 -> V_60 , & V_170 , V_171 ) ;
V_25 = F_78 ( & V_2 -> V_67 , V_26 , V_28 ) ;
if ( ! V_25 )
break;
V_25 -> V_31 = true ;
F_80 ( & V_2 -> V_50 -> V_172 ) ;
F_81 () ;
F_82 ( & V_2 -> V_50 -> V_172 ) ;
}
F_83 ( & V_2 -> V_60 , & V_170 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_87 * V_88 ;
bool V_173 = false ;
enum V_174 V_175 ;
V_88 = F_62 ( V_50 -> V_87 ) ;
V_175 = V_88 ? V_88 -> V_175 : V_176 ;
if ( V_175 == V_176 ||
V_50 -> V_177 < 96 )
return;
if ( ! F_26 ( V_2 , V_145 ) )
return;
if ( V_88 -> V_178 &&
F_21 ( & V_2 -> V_78 ) >= V_88 -> V_178 ) {
F_85 ( V_41 , L_12 ) ;
V_173 = true ;
}
if ( V_2 -> V_179 -> V_180 >= V_88 -> V_181 ) {
F_85 ( V_41 , L_13 ) ;
V_173 = true ;
}
if ( V_173 ) {
F_34 ( V_2 -> V_50 ) ;
if ( V_175 == V_182 )
F_86 ( F_87 ( V_2 , V_183 , V_184 ) , 0 , NULL ) ;
else
F_86 ( F_87 ( V_2 , V_183 , V_185 ) , 0 , NULL ) ;
}
F_28 ( V_2 ) ;
}
static bool F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
enum V_148 V_149 ;
if ( V_4 -> V_66 ) {
if ( ! F_69 ( V_2 ,
V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_28 ( V_2 ) ;
}
}
if ( V_2 -> V_143 . V_186 != V_145 )
return false ;
if ( V_4 -> V_66 == NULL )
return true ;
F_61 () ;
V_149 = F_62 ( V_2 -> V_83 -> V_187 ) -> V_188 ;
F_63 () ;
if ( V_149 == V_169 && V_4 -> V_66 )
return false ;
if ( F_73 ( V_2 , V_4 -> V_25 . V_26 , V_149 ) ) {
if ( V_4 -> V_66 ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_28 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
int V_189 , V_190 ;
F_61 () ;
V_189 = F_91 ( V_2 -> V_143 ) ;
if ( V_189 ) {
F_84 ( V_2 ) ;
V_189 = F_91 ( V_2 -> V_143 ) ;
}
V_190 = F_92 ( V_2 -> V_143 ) ;
F_63 () ;
if ( F_93 ( V_4 -> V_25 . V_28 == 0 ) ) {
F_45 ( V_4 -> V_12 -> V_191 & V_192 ) ;
if ( V_189 )
F_34 ( V_2 -> V_50 ) ;
return 0 ;
}
if ( ! V_189 && ! V_190 )
return 0 ;
F_45 ( ! ( V_189 && V_190 ) ) ;
if ( V_189 ) {
F_94 ( V_4 , V_91 ) ;
F_94 ( V_4 , V_113 ) ;
} else if ( F_24 ( V_2 , V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 ) )
F_94 ( V_4 , V_116 ) ;
return V_189 ;
}
static void
F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 . V_2 ;
struct V_5 * V_5 = V_4 -> V_66 ;
const int V_6 = F_42 ( V_5 ) ;
V_5 -> V_193 = V_2 -> V_83 -> V_84 ;
if ( F_68 ( V_2 ) ) {
if ( F_96 ( V_2 ,
V_6 == V_21 ? V_194
: V_6 == V_69 ? V_195
: V_196 ) )
F_37 ( V_5 , - V_70 ) ;
else
F_97 ( V_5 ) ;
F_28 ( V_2 ) ;
} else
F_37 ( V_5 , - V_70 ) ;
}
void F_98 ( struct V_1 * V_2 , struct V_5 * V_5 , unsigned long V_15 )
{
const int V_6 = F_42 ( V_5 ) ;
struct V_55 V_56 = { NULL , } ;
struct V_3 * V_4 ;
bool V_197 = false ;
V_4 = F_12 ( V_2 , V_5 ) ;
if ( ! V_4 ) {
F_38 ( V_2 ) ;
F_22 ( V_41 , L_14 ) ;
F_37 ( V_5 , - V_198 ) ;
return;
}
V_4 -> V_15 = V_15 ;
if ( ! F_68 ( V_2 ) ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
if ( V_6 == V_21 && V_4 -> V_66 && V_4 -> V_25 . V_28
&& ! F_99 ( V_199 , & V_2 -> V_110 ) ) {
V_4 -> V_20 |= V_46 ;
F_100 ( V_2 , & V_4 -> V_25 ) ;
}
F_82 ( & V_2 -> V_50 -> V_172 ) ;
if ( V_6 == V_21 ) {
F_76 ( V_4 ) ;
}
if ( F_51 ( V_2 ) ) {
V_4 -> V_20 |= V_37 ;
if ( V_4 -> V_66 ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_28 ( V_2 ) ;
}
goto V_200;
}
F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_6 != V_21 ) {
if ( ! F_88 ( V_4 ) && ! V_4 -> V_66 )
goto V_201;
}
V_4 -> V_24 = F_21 ( & V_2 -> V_50 -> V_54 ) ;
if ( F_101 ( V_4 -> V_25 . V_28 != 0 ) ) {
if ( V_6 == V_21 )
V_2 -> V_50 -> V_53 ++ ;
F_102 ( & V_4 -> V_32 , & V_2 -> V_50 -> V_202 ) ;
}
if ( V_6 == V_21 ) {
if ( ! F_90 ( V_4 ) )
V_197 = true ;
} else {
if ( V_4 -> V_66 == NULL ) {
F_94 ( V_4 , V_91 ) ;
F_94 ( V_4 , V_108 ) ;
} else
V_197 = true ;
}
if ( V_4 -> V_66 ) {
F_94 ( V_4 , V_97 ) ;
F_80 ( & V_2 -> V_50 -> V_172 ) ;
F_95 ( V_4 ) ;
F_82 ( & V_2 -> V_50 -> V_172 ) ;
} else if ( V_197 ) {
V_201:
if ( F_29 ( & V_48 ) )
F_22 ( V_41 , L_15 ,
( unsigned long long ) V_4 -> V_25 . V_26 , V_4 -> V_25 . V_28 >> 9 ) ;
}
V_200:
if ( F_47 ( V_4 , & V_56 , 1 ) )
F_103 ( & V_4 -> V_35 , F_19 ) ;
F_80 ( & V_2 -> V_50 -> V_172 ) ;
if ( V_56 . V_5 )
F_36 ( V_2 , & V_56 ) ;
return;
}
void F_104 ( struct V_203 * V_204 , struct V_5 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_204 -> V_205 ;
unsigned long V_15 ;
V_15 = V_14 ;
F_45 ( F_105 ( V_5 -> V_29 , 512 ) ) ;
F_106 ( V_2 ) ;
F_98 ( V_2 , V_5 , V_15 ) ;
}
int F_107 ( struct V_203 * V_204 , struct V_206 * V_207 , struct V_208 * V_209 )
{
struct V_1 * V_2 = (struct V_1 * ) V_204 -> V_205 ;
unsigned int V_210 = V_207 -> V_29 ;
int V_211 = V_212 ;
int V_213 ;
if ( V_210 && F_68 ( V_2 ) ) {
struct V_203 * const V_81 =
V_2 -> V_83 -> V_84 -> V_154 -> V_155 ;
if ( V_81 -> V_214 ) {
V_213 = V_81 -> V_214 ( V_81 , V_207 , V_209 ) ;
V_211 = F_108 ( V_211 , V_213 ) ;
}
F_28 ( V_2 ) ;
}
return V_211 ;
}
struct V_3 * F_109 ( struct V_49 * V_50 )
{
struct V_3 * V_215 ;
F_110 (r, &tconn->transfer_log, tl_requests) {
if ( F_21 ( & V_215 -> V_34 ) )
return V_215 ;
}
return NULL ;
}
void F_111 ( unsigned long V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_216 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_3 * V_4 ;
struct V_87 * V_88 ;
unsigned long V_217 = 0 , V_218 = 0 , V_219 , V_220 ;
unsigned long V_221 ;
F_61 () ;
V_88 = F_62 ( V_50 -> V_87 ) ;
if ( V_88 && V_2 -> V_143 . V_183 >= V_222 )
V_217 = V_88 -> V_223 * V_224 / 10 * V_88 -> V_225 ;
if ( F_68 ( V_2 ) ) {
V_218 = F_62 ( V_2 -> V_83 -> V_187 ) -> V_226 * V_224 / 10 ;
F_28 ( V_2 ) ;
}
F_63 () ;
V_219 = F_112 ( V_218 , V_217 ) ;
if ( ! V_219 )
return;
V_221 = V_14 ;
F_82 ( & V_50 -> V_172 ) ;
V_4 = F_109 ( V_50 ) ;
if ( ! V_4 ) {
F_80 ( & V_50 -> V_172 ) ;
F_113 ( & V_2 -> V_227 , V_221 + V_219 ) ;
return;
}
if ( V_217 && V_4 -> V_20 & V_64 &&
F_114 ( V_221 , V_4 -> V_15 + V_217 ) &&
! F_115 ( V_221 , V_50 -> V_228 , V_50 -> V_228 + V_217 ) ) {
F_30 ( V_41 , L_16 ) ;
F_86 ( F_87 ( V_2 , V_183 , V_229 ) , V_230 | V_231 , NULL ) ;
}
if ( V_218 && V_4 -> V_20 & V_38 && V_4 -> V_23 . V_2 == V_2 &&
F_114 ( V_221 , V_4 -> V_15 + V_218 ) &&
! F_115 ( V_221 , V_2 -> V_232 , V_2 -> V_232 + V_218 ) ) {
F_30 ( V_41 , L_17 ) ;
F_64 ( V_2 , V_233 ) ;
}
V_220 = ( F_114 ( V_221 , V_4 -> V_15 + V_219 ) ? V_221 : V_4 -> V_15 ) + V_219 ;
F_80 ( & V_50 -> V_172 ) ;
F_113 ( & V_2 -> V_227 , V_220 ) ;
}
