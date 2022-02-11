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
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = V_19 ;
V_4 -> V_25 = 0 ;
F_14 ( & V_4 -> V_12 ) ;
V_4 -> V_12 . V_26 = V_19 -> V_27 . V_28 ;
V_4 -> V_12 . V_13 = V_19 -> V_27 . V_29 ;
V_4 -> V_12 . V_30 = true ;
V_4 -> V_12 . V_31 = false ;
F_15 ( & V_4 -> V_32 ) ;
F_15 ( & V_4 -> V_33 . V_34 ) ;
F_16 ( & V_4 -> V_35 , 1 ) ;
F_17 ( & V_4 -> V_36 ) ;
return V_4 ;
}
void F_18 ( struct V_36 * V_36 )
{
struct V_3 * V_4 = F_19 ( V_36 , struct V_3 , V_36 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
const unsigned V_37 = V_4 -> V_22 ;
if ( ( V_4 -> V_6 && ! ( V_37 & V_38 ) ) ||
F_20 ( & V_4 -> V_35 ) ||
( V_37 & V_39 ) ||
( ( V_37 & V_40 ) && ! ( V_37 & V_41 ) ) ) {
F_21 ( V_2 , L_1 ,
V_37 , F_20 ( & V_4 -> V_35 ) ) ;
return;
}
F_22 ( & V_4 -> V_32 ) ;
if ( V_37 & V_24 ) {
if ( ( V_37 & ( V_38 | V_42 | V_40 ) ) != V_38 ) {
if ( ! ( V_37 & V_43 ) || ! ( V_37 & V_44 ) )
F_23 ( V_2 , V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) ;
if ( ( V_37 & V_43 ) && ( V_37 & V_44 ) && ( V_37 & V_45 ) )
F_24 ( V_2 , V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) ;
}
if ( V_37 & V_46 ) {
if ( F_25 ( V_2 , V_47 ) ) {
F_26 ( V_2 , & V_4 -> V_12 ) ;
F_27 ( V_2 ) ;
} else if ( F_28 ( & V_48 ) ) {
F_29 ( V_2 , L_2
L_3 ,
( unsigned long long ) V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) ;
}
}
}
F_30 ( V_4 , V_20 ) ;
}
static void F_31 ( struct V_49 * V_50 )
{
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
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_59 * V_12 = & V_4 -> V_12 ;
F_39 ( V_58 , V_12 ) ;
if ( V_12 -> V_31 )
F_32 ( & V_2 -> V_60 ) ;
}
static
void F_40 ( struct V_3 * V_4 , struct V_55 * V_56 )
{
const unsigned V_37 = V_4 -> V_22 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_5 ;
int error , V_61 ;
if ( ( V_37 & V_39 && ! ( V_37 & V_62 ) ) ||
( V_37 & V_63 ) || ( V_37 & V_64 ) ||
( V_37 & V_65 ) ) {
F_21 ( V_2 , L_4 , V_37 ) ;
return;
}
if ( ! V_4 -> V_6 ) {
F_21 ( V_2 , L_5 ) ;
return;
}
V_5 = F_41 ( V_4 -> V_6 ) ;
V_61 = ( V_37 & V_44 ) || ( V_37 & V_43 ) ;
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
V_4 -> V_25 == F_20 ( & F_44 ( V_2 ) -> V_50 -> V_54 ) )
F_33 ( F_44 ( V_2 ) -> V_50 ) ;
F_9 ( V_2 , V_4 ) ;
if ( ! V_61 && V_5 == V_69 && ! F_45 ( & V_4 -> V_32 ) )
V_4 -> V_22 |= V_38 ;
if ( ! ( V_4 -> V_22 & V_38 ) ) {
V_56 -> error = V_61 ? 0 : ( error ? : - V_70 ) ;
V_56 -> V_18 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
}
}
static int F_46 ( struct V_3 * V_4 , struct V_55 * V_56 , int V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_47 ( V_2 , V_56 || ( V_4 -> V_22 & V_38 ) ) ;
if ( ! F_48 ( V_71 , & V_4 -> V_35 ) )
return 0 ;
F_40 ( V_4 , V_56 ) ;
if ( V_4 -> V_22 & V_38 ) {
F_49 ( V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_3 * V_4 , struct V_55 * V_56 ,
int V_72 , int V_73 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned V_37 = V_4 -> V_22 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( F_51 ( V_2 ) && ! ( ( V_37 | V_72 ) & V_65 ) )
V_73 |= V_65 ;
V_4 -> V_22 &= ~ V_72 ;
V_4 -> V_22 |= V_73 ;
if ( V_4 -> V_22 == V_37 )
return;
if ( ! ( V_37 & V_39 ) && ( V_73 & V_39 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ! ( V_37 & V_64 ) && ( V_73 & V_64 ) ) {
F_52 ( V_2 ) ;
F_34 ( & V_4 -> V_35 ) ;
}
if ( ! ( V_37 & V_63 ) && ( V_73 & V_63 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ! ( V_37 & V_76 ) && ( V_73 & V_76 ) )
F_53 ( & V_4 -> V_36 ) ;
if ( ! ( V_37 & V_77 ) && ( V_73 & V_77 ) )
F_54 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_78 ) ;
if ( ! ( V_37 & V_65 ) && ( V_73 & V_65 ) )
F_34 ( & V_4 -> V_35 ) ;
if ( ( V_37 & V_65 ) && ( V_72 & V_65 ) )
++ V_74 ;
if ( ! ( V_37 & V_62 ) && ( V_73 & V_62 ) ) {
F_47 ( V_2 , V_4 -> V_22 & V_39 ) ;
F_53 ( & V_4 -> V_36 ) ;
++ V_74 ;
}
if ( ( V_37 & V_39 ) && ( V_72 & V_39 ) ) {
if ( V_4 -> V_22 & V_62 )
++ V_75 ;
else
++ V_74 ;
}
if ( ( V_37 & V_64 ) && ( V_72 & V_64 ) ) {
F_55 ( V_2 ) ;
++ V_74 ;
}
if ( ( V_37 & V_63 ) && ( V_72 & V_63 ) )
++ V_74 ;
if ( ( V_37 & V_76 ) && ! ( V_37 & V_41 ) && ( V_73 & V_41 ) ) {
if ( V_4 -> V_22 & V_77 )
F_56 ( V_4 -> V_12 . V_13 >> 9 , & V_2 -> V_78 ) ;
++ V_75 ;
}
if ( V_75 || V_74 ) {
int V_79 = V_75 + ! ! V_74 ;
int V_80 = F_20 ( & V_4 -> V_36 . V_80 ) ;
if ( V_80 < V_79 )
F_21 ( V_2 ,
L_6 ,
V_37 , V_4 -> V_22 , V_80 , V_79 ) ;
}
if ( V_4 -> V_12 . V_31 )
F_32 ( & V_2 -> V_60 ) ;
if ( V_74 )
V_75 += F_46 ( V_4 , V_56 , V_74 ) ;
if ( V_75 )
F_57 ( & V_4 -> V_36 , V_75 , F_18 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_81 [ V_82 ] ;
if ( ! F_28 ( & V_48 ) )
return;
F_29 ( V_2 , L_7 ,
( V_4 -> V_22 & V_24 ) ? L_8 : L_9 ,
( unsigned long long ) V_4 -> V_12 . V_26 ,
V_4 -> V_12 . V_13 >> 9 ,
F_59 ( V_2 -> V_83 -> V_84 , V_81 ) ) ;
}
int F_60 ( struct V_3 * V_4 , enum V_85 V_86 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_87 * V_88 ;
int V_89 , V_90 = 0 ;
if ( V_56 )
V_56 -> V_18 = NULL ;
switch ( V_86 ) {
default:
F_21 ( V_2 , L_10 , __FILE__ , __LINE__ ) ;
break;
case V_91 :
F_47 ( V_2 , ! ( V_4 -> V_22 & V_40 ) ) ;
F_61 () ;
V_88 = F_62 ( F_44 ( V_2 ) -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_92 ;
F_63 () ;
V_4 -> V_22 |=
V_89 == V_93 ? V_94 :
V_89 == V_95 ? V_96 : 0 ;
F_50 ( V_4 , V_56 , 0 , V_64 ) ;
break;
case V_97 :
F_47 ( V_2 , ! ( V_4 -> V_22 & V_42 ) ) ;
F_50 ( V_4 , V_56 , 0 , V_39 ) ;
break;
case V_98 :
if ( V_4 -> V_22 & V_24 )
V_2 -> V_99 += V_4 -> V_12 . V_13 >> 9 ;
else
V_2 -> V_100 += V_4 -> V_12 . V_13 >> 9 ;
F_50 ( V_4 , V_56 , V_39 ,
V_101 | V_44 ) ;
break;
case V_102 :
F_50 ( V_4 , V_56 , 0 , V_62 ) ;
break;
case V_103 :
F_58 ( V_2 , V_4 ) ;
F_64 ( V_2 , V_104 ) ;
F_50 ( V_4 , V_56 , V_39 , V_101 ) ;
break;
case V_105 :
F_23 ( V_2 , V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) ;
F_58 ( V_2 , V_4 ) ;
F_64 ( V_2 , V_106 ) ;
case V_107 :
F_50 ( V_4 , V_56 , V_39 , V_101 ) ;
break;
case V_108 :
F_47 ( V_2 , F_43 ( & V_4 -> V_12 ) ) ;
F_65 ( & V_2 -> V_68 , & V_4 -> V_12 ) ;
F_66 ( V_109 , & V_2 -> V_110 ) ;
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
F_47 ( V_2 , ( V_4 -> V_22 & V_42 ) == 0 ) ;
F_50 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_33 . V_111 = V_112 ;
F_67 ( & F_44 ( V_2 ) -> V_50 -> V_51 ,
& V_4 -> V_33 ) ;
break;
case V_113 :
F_47 ( V_2 , F_43 ( & V_4 -> V_12 ) ) ;
F_65 ( & V_2 -> V_67 , & V_4 -> V_12 ) ;
F_66 ( V_109 , & V_2 -> V_110 ) ;
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
F_50 ( V_4 , V_56 , 0 , V_63 | V_76 ) ;
V_4 -> V_33 . V_111 = V_114 ;
F_67 ( & F_44 ( V_2 ) -> V_50 -> V_51 ,
& V_4 -> V_33 ) ;
F_61 () ;
V_88 = F_62 ( F_44 ( V_2 ) -> V_50 -> V_87 ) ;
V_89 = V_88 -> V_115 ;
F_63 () ;
if ( F_44 ( V_2 ) -> V_50 -> V_53 >= V_89 )
F_33 ( F_44 ( V_2 ) -> V_50 ) ;
break;
case V_116 :
F_50 ( V_4 , V_56 , 0 , V_63 ) ;
V_4 -> V_33 . V_111 = V_117 ;
F_67 ( & F_44 ( V_2 ) -> V_50 -> V_51 ,
& V_4 -> V_33 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
F_50 ( V_4 , V_56 , V_63 , 0 ) ;
break;
case V_121 :
if ( F_2 ( V_4 -> V_6 ) == V_23 &&
! ( V_4 -> V_22 & ( V_96 | V_94 ) ) ) {
if ( V_4 -> V_22 & V_64 )
F_50 ( V_4 , V_56 , V_64 , V_43 ) ;
}
F_50 ( V_4 , V_56 , V_63 , V_77 ) ;
break;
case V_122 :
F_50 ( V_4 , V_56 , V_63 , V_41 ) ;
break;
case V_123 :
F_50 ( V_4 , V_56 ,
V_43 | V_64 | V_65 ,
V_41 ) ;
break;
case V_124 :
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
F_47 ( V_2 , V_4 -> V_22 & V_94 ) ;
F_50 ( V_4 , V_56 , V_64 , V_41 | V_43 ) ;
break;
case V_125 :
V_4 -> V_22 |= V_45 ;
case V_126 :
F_47 ( V_2 , V_4 -> V_22 & V_94 ) ;
goto V_127;
case V_128 :
F_47 ( V_2 , V_4 -> V_22 & V_96 ) ;
V_127:
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
F_50 ( V_4 , V_56 , V_64 , V_43 ) ;
break;
case V_129 :
F_47 ( V_2 , V_4 -> V_22 & V_94 ) ;
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
V_4 -> V_22 |= V_38 ;
if ( V_4 -> V_12 . V_31 )
F_32 ( & V_2 -> V_60 ) ;
break;
case V_130 :
F_50 ( V_4 , V_56 , V_43 | V_64 , 0 ) ;
break;
case V_131 :
if ( ! ( V_4 -> V_22 & V_101 ) )
break;
F_50 ( V_4 , V_56 , V_65 , 0 ) ;
break;
case V_132 :
if ( ! ( V_4 -> V_22 & V_101 ) )
break;
F_50 ( V_4 , V_56 ,
V_65 | V_101 ,
V_39 ) ;
V_90 = V_133 ;
if ( F_2 ( V_4 -> V_6 ) == V_23 )
V_90 = V_134 ;
F_68 ( V_2 ) ;
V_4 -> V_33 . V_111 = V_135 ;
F_67 ( & F_44 ( V_2 ) -> V_50 -> V_51 ,
& V_4 -> V_33 ) ;
break;
case V_136 :
if ( ! ( V_4 -> V_22 & V_24 ) && ! V_4 -> V_33 . V_111 ) {
F_50 ( V_4 , V_56 , V_65 , 0 ) ;
break;
}
if ( ! ( V_4 -> V_22 & V_43 ) ) {
F_50 ( V_4 , V_56 , V_65 , V_63 | V_64 ) ;
if ( V_4 -> V_33 . V_111 ) {
F_67 ( & F_44 ( V_2 ) -> V_50 -> V_51 ,
& V_4 -> V_33 ) ;
V_90 = V_4 -> V_22 & V_24 ? V_134 : V_133 ;
}
break;
}
case V_137 :
if ( ! ( V_4 -> V_22 & V_24 ) )
break;
if ( V_4 -> V_22 & V_64 ) {
F_21 ( V_2 , L_11 ) ;
}
F_50 ( V_4 , V_56 , V_65 ,
( V_4 -> V_22 & V_40 ) ? V_41 : 0 ) ;
break;
case V_138 :
F_47 ( V_2 , V_4 -> V_22 & V_64 ) ;
F_50 ( V_4 , V_56 , V_64 , V_43 | V_41 ) ;
break;
case V_139 :
F_33 ( F_44 ( V_2 ) -> V_50 ) ;
F_50 ( V_4 , V_56 , 0 , V_43 | V_41 ) ;
break;
} ;
return V_90 ;
}
static bool F_69 ( struct V_1 * V_2 , T_1 V_26 , int V_13 )
{
unsigned long V_140 , V_141 ;
T_1 V_142 , V_143 ;
if ( V_2 -> V_144 . V_145 == V_146 )
return true ;
if ( V_2 -> V_144 . V_145 != V_147 )
return false ;
V_142 = V_26 + ( V_13 >> 9 ) - 1 ;
V_143 = F_70 ( V_2 -> V_148 ) ;
F_47 ( V_2 , V_26 < V_143 ) ;
F_47 ( V_2 , V_142 < V_143 ) ;
V_140 = F_71 ( V_26 ) ;
V_141 = F_71 ( V_142 ) ;
return F_72 ( V_2 , V_140 , V_141 ) == 0 ;
}
static bool F_73 ( struct V_1 * V_2 , T_1 V_26 ,
enum V_149 V_150 )
{
struct V_151 * V_152 ;
int V_153 ;
switch ( V_150 ) {
case V_154 :
V_152 = & V_2 -> V_83 -> V_84 -> V_155 -> V_156 -> V_151 ;
return F_74 ( V_152 ) ;
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
return ( V_26 >> ( V_153 - 9 ) ) & 1 ;
case V_167 :
return F_75 ( V_168 , & V_2 -> V_110 ) ;
case V_169 :
return true ;
case V_170 :
default:
return false ;
}
}
static void F_76 ( struct V_3 * V_4 )
{
F_77 ( V_171 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_59 * V_12 ;
T_1 V_26 = V_4 -> V_12 . V_26 ;
int V_13 = V_4 -> V_12 . V_13 ;
V_12 = F_78 ( & V_2 -> V_67 , V_26 , V_13 ) ;
if ( ! V_12 )
return;
for (; ; ) {
F_79 ( & V_2 -> V_60 , & V_171 , V_172 ) ;
V_12 = F_78 ( & V_2 -> V_67 , V_26 , V_13 ) ;
if ( ! V_12 )
break;
V_12 -> V_31 = true ;
F_80 ( & V_2 -> V_173 -> V_174 ) ;
F_81 () ;
F_82 ( & V_2 -> V_173 -> V_174 ) ;
}
F_83 ( & V_2 -> V_60 , & V_171 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_44 ( V_2 ) -> V_50 ;
struct V_87 * V_88 ;
bool V_175 = false ;
enum V_176 V_177 ;
F_61 () ;
V_88 = F_62 ( V_50 -> V_87 ) ;
V_177 = V_88 ? V_88 -> V_177 : V_178 ;
F_63 () ;
if ( V_177 == V_178 ||
V_50 -> V_179 < 96 )
return;
if ( ! F_25 ( V_2 , V_146 ) )
return;
if ( V_88 -> V_180 &&
F_20 ( & V_2 -> V_78 ) >= V_88 -> V_180 ) {
F_85 ( V_2 , L_12 ) ;
V_175 = true ;
}
if ( V_2 -> V_181 -> V_182 >= V_88 -> V_183 ) {
F_85 ( V_2 , L_13 ) ;
V_175 = true ;
}
if ( V_175 ) {
F_33 ( F_44 ( V_2 ) -> V_50 ) ;
if ( V_177 == V_184 )
F_86 ( F_87 ( V_2 , V_185 , V_186 ) , 0 , NULL ) ;
else
F_86 ( F_87 ( V_2 , V_185 , V_187 ) , 0 , NULL ) ;
}
F_27 ( V_2 ) ;
}
static bool F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_149 V_150 ;
if ( V_4 -> V_66 ) {
if ( ! F_69 ( V_2 ,
V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
}
if ( V_2 -> V_144 . V_188 != V_146 )
return false ;
if ( V_4 -> V_66 == NULL )
return true ;
F_61 () ;
V_150 = F_62 ( V_2 -> V_83 -> V_189 ) -> V_190 ;
F_63 () ;
if ( V_150 == V_170 && V_4 -> V_66 )
return false ;
if ( F_73 ( V_2 , V_4 -> V_12 . V_26 , V_150 ) ) {
if ( V_4 -> V_66 ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
return true ;
}
return false ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_191 , V_192 ;
V_191 = F_91 ( V_2 -> V_144 ) ;
V_192 = F_92 ( V_2 -> V_144 ) ;
if ( F_93 ( V_4 -> V_12 . V_13 == 0 ) ) {
F_47 ( V_2 , V_4 -> V_6 -> V_193 & V_194 ) ;
if ( V_191 )
F_94 ( V_4 , V_139 ) ;
return V_191 ;
}
if ( ! V_191 && ! V_192 )
return 0 ;
F_47 ( V_2 , ! ( V_191 && V_192 ) ) ;
if ( V_191 ) {
F_94 ( V_4 , V_91 ) ;
F_94 ( V_4 , V_113 ) ;
} else if ( F_23 ( V_2 , V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 ) )
F_94 ( V_4 , V_116 ) ;
return V_191 ;
}
static void
F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_18 * V_18 = V_4 -> V_66 ;
const int V_5 = F_41 ( V_18 ) ;
V_18 -> V_195 = V_2 -> V_83 -> V_84 ;
if ( F_68 ( V_2 ) ) {
if ( F_96 ( V_2 ,
V_5 == V_23 ? V_196
: V_5 == V_69 ? V_197
: V_198 ) )
F_36 ( V_18 , - V_70 ) ;
else
F_97 ( V_18 ) ;
F_27 ( V_2 ) ;
} else
F_36 ( V_18 , - V_70 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_99 ( & V_2 -> V_199 . V_200 ) ;
F_100 ( & V_4 -> V_32 , & V_2 -> V_199 . V_201 ) ;
F_101 ( & V_2 -> V_199 . V_200 ) ;
F_102 ( V_2 -> V_199 . V_202 , & V_2 -> V_199 . V_203 ) ;
}
static struct V_3 *
F_103 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
const int V_5 = F_2 ( V_18 ) ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_18 ) ;
if ( ! V_4 ) {
F_37 ( V_2 ) ;
F_21 ( V_2 , L_14 ) ;
F_36 ( V_18 , - V_204 ) ;
return F_104 ( - V_204 ) ;
}
V_4 -> V_16 = V_16 ;
if ( ! F_68 ( V_2 ) ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
F_1 ( V_2 , V_4 ) ;
if ( V_5 == V_23 && V_4 -> V_66 && V_4 -> V_12 . V_13
&& ! F_105 ( V_205 , & V_2 -> V_110 ) ) {
if ( ! F_106 ( V_2 , & V_4 -> V_12 ) ) {
F_98 ( V_2 , V_4 ) ;
return NULL ;
}
V_4 -> V_22 |= V_46 ;
}
return V_4 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const int V_5 = F_41 ( V_4 -> V_6 ) ;
struct V_55 V_56 = { NULL , } ;
bool V_206 = false ;
F_82 ( & V_2 -> V_173 -> V_174 ) ;
if ( V_5 == V_23 ) {
F_76 ( V_4 ) ;
F_84 ( V_2 ) ;
}
if ( F_51 ( V_2 ) ) {
V_4 -> V_22 |= V_38 ;
if ( V_4 -> V_66 ) {
F_89 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
F_27 ( V_2 ) ;
}
goto V_207;
}
if ( V_5 != V_23 ) {
if ( ! F_88 ( V_4 ) && ! V_4 -> V_66 )
goto V_208;
}
V_4 -> V_25 = F_20 ( & F_44 ( V_2 ) -> V_50 -> V_54 ) ;
if ( F_108 ( V_4 -> V_12 . V_13 != 0 ) ) {
if ( V_5 == V_23 )
F_44 ( V_2 ) -> V_50 -> V_53 ++ ;
F_100 ( & V_4 -> V_32 , & F_44 ( V_2 ) -> V_50 -> V_209 ) ;
}
if ( V_5 == V_23 ) {
if ( ! F_90 ( V_4 ) )
V_206 = true ;
} else {
if ( V_4 -> V_66 == NULL ) {
F_94 ( V_4 , V_91 ) ;
F_94 ( V_4 , V_108 ) ;
} else
V_206 = true ;
}
if ( V_4 -> V_66 ) {
F_94 ( V_4 , V_97 ) ;
F_80 ( & V_2 -> V_173 -> V_174 ) ;
F_95 ( V_4 ) ;
F_82 ( & V_2 -> V_173 -> V_174 ) ;
} else if ( V_206 ) {
V_208:
if ( F_28 ( & V_48 ) )
F_21 ( V_2 , L_15 ,
( unsigned long long ) V_4 -> V_12 . V_26 , V_4 -> V_12 . V_13 >> 9 ) ;
}
V_207:
if ( F_46 ( V_4 , & V_56 , 1 ) )
F_109 ( & V_4 -> V_36 , F_18 ) ;
F_80 ( & V_2 -> V_173 -> V_174 ) ;
if ( V_56 . V_18 )
F_35 ( V_2 , & V_56 ) ;
}
void F_110 ( struct V_1 * V_2 , struct V_18 * V_18 , unsigned long V_16 )
{
struct V_3 * V_4 = F_103 ( V_2 , V_18 , V_16 ) ;
if ( F_111 ( V_4 ) )
return;
F_107 ( V_2 , V_4 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_210 * V_211 )
{
struct V_3 * V_4 , * V_212 ;
F_113 (req, tmp, incoming, tl_requests) {
const int V_5 = F_2 ( V_4 -> V_6 ) ;
if ( V_5 == V_23
&& V_4 -> V_66 && V_4 -> V_12 . V_13
&& ! F_105 ( V_205 , & V_2 -> V_110 ) ) {
if ( ! F_106 ( V_2 , & V_4 -> V_12 ) )
continue;
V_4 -> V_22 |= V_46 ;
}
F_22 ( & V_4 -> V_32 ) ;
F_107 ( V_2 , V_4 ) ;
}
}
static bool F_114 ( struct V_1 * V_2 ,
struct V_210 * V_211 ,
struct V_210 * V_213 )
{
struct V_3 * V_4 , * V_212 ;
int V_214 = 0 ;
int V_215 ;
F_82 ( & V_2 -> V_216 ) ;
F_113 (req, tmp, incoming, tl_requests) {
V_215 = F_115 ( V_2 , & V_4 -> V_12 ) ;
if ( V_215 == - V_217 )
V_214 = 1 ;
if ( V_215 )
continue;
V_4 -> V_22 |= V_46 ;
F_116 ( & V_4 -> V_32 , V_213 ) ;
}
F_80 ( & V_2 -> V_216 ) ;
if ( V_214 )
F_32 ( & V_2 -> V_218 ) ;
return ! F_45 ( V_213 ) ;
}
void F_117 ( struct V_219 * V_220 )
{
struct V_1 * V_2 = F_19 ( V_220 , struct V_1 , V_199 . V_203 ) ;
F_118 ( V_211 ) ;
F_118 ( V_213 ) ;
struct V_3 * V_4 , * V_212 ;
for (; ; ) {
F_99 ( & V_2 -> V_199 . V_200 ) ;
F_119 ( & V_2 -> V_199 . V_201 , & V_211 ) ;
F_101 ( & V_2 -> V_199 . V_200 ) ;
F_112 ( V_2 , & V_211 ) ;
if ( F_45 ( & V_211 ) )
break;
F_120 ( V_2 -> V_218 , F_114 ( V_2 , & V_211 , & V_213 ) ) ;
for (; ; ) {
F_118 ( V_221 ) ;
F_118 ( V_222 ) ;
bool V_223 ;
if ( F_45 ( & V_2 -> V_199 . V_201 ) )
break;
F_99 ( & V_2 -> V_199 . V_200 ) ;
F_119 ( & V_2 -> V_199 . V_201 , & V_222 ) ;
F_101 ( & V_2 -> V_199 . V_200 ) ;
if ( F_45 ( & V_222 ) )
break;
V_223 = F_114 ( V_2 , & V_222 , & V_221 ) ;
F_119 ( & V_221 , & V_213 ) ;
F_119 ( & V_222 , & V_211 ) ;
if ( ! V_223 )
break;
}
F_121 ( V_2 , false ) ;
F_113 (req, tmp, &pending, tl_requests) {
F_22 ( & V_4 -> V_32 ) ;
F_107 ( V_2 , V_4 ) ;
}
}
}
void F_122 ( struct V_224 * V_225 , struct V_18 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_225 -> V_226 ;
unsigned long V_16 ;
V_16 = V_15 ;
F_47 ( V_2 , F_123 ( V_18 -> V_27 . V_29 , 512 ) ) ;
F_124 ( V_2 ) ;
F_110 ( V_2 , V_18 , V_16 ) ;
}
int F_125 ( struct V_224 * V_225 , struct V_227 * V_228 , struct V_229 * V_230 )
{
struct V_1 * V_2 = (struct V_1 * ) V_225 -> V_226 ;
unsigned int V_231 = V_228 -> V_29 ;
int V_232 = V_233 ;
int V_234 ;
if ( V_231 && F_68 ( V_2 ) ) {
unsigned int V_235 = F_126 ( V_225 ) ;
struct V_224 * const V_81 =
V_2 -> V_83 -> V_84 -> V_155 -> V_156 ;
if ( V_81 -> V_236 ) {
V_234 = V_81 -> V_236 ( V_81 , V_228 , V_230 ) ;
V_232 = F_127 ( V_232 , V_234 ) ;
}
F_27 ( V_2 ) ;
if ( ( V_232 >> 9 ) > V_235 )
V_232 = V_235 << 9 ;
}
return V_232 ;
}
static struct V_3 * F_128 ( struct V_49 * V_50 )
{
struct V_3 * V_237 ;
F_129 (r, &connection->transfer_log, tl_requests) {
if ( F_20 ( & V_237 -> V_35 ) )
return V_237 ;
}
return NULL ;
}
void F_130 ( unsigned long V_238 )
{
struct V_1 * V_2 = (struct V_1 * ) V_238 ;
struct V_49 * V_50 = F_44 ( V_2 ) -> V_50 ;
struct V_3 * V_4 ;
struct V_87 * V_88 ;
unsigned long V_239 = 0 , V_240 = 0 , V_241 , V_242 ;
unsigned long V_243 ;
F_61 () ;
V_88 = F_62 ( V_50 -> V_87 ) ;
if ( V_88 && V_2 -> V_144 . V_185 >= V_244 )
V_239 = V_88 -> V_245 * V_246 / 10 * V_88 -> V_247 ;
if ( F_68 ( V_2 ) ) {
V_240 = F_62 ( V_2 -> V_83 -> V_189 ) -> V_248 * V_246 / 10 ;
F_27 ( V_2 ) ;
}
F_63 () ;
V_241 = F_131 ( V_240 , V_239 ) ;
if ( ! V_241 )
return;
V_243 = V_15 ;
F_82 ( & V_2 -> V_173 -> V_174 ) ;
V_4 = F_128 ( V_50 ) ;
if ( ! V_4 ) {
F_80 ( & V_2 -> V_173 -> V_174 ) ;
F_132 ( & V_2 -> V_249 , V_243 + V_241 ) ;
return;
}
if ( V_239 && V_4 -> V_22 & V_64 &&
F_133 ( V_243 , V_4 -> V_16 + V_239 ) &&
! F_134 ( V_243 , V_50 -> V_250 , V_50 -> V_250 + V_239 ) ) {
F_29 ( V_2 , L_16 ) ;
F_86 ( F_87 ( V_2 , V_185 , V_251 ) , V_252 | V_253 , NULL ) ;
}
if ( V_240 && V_4 -> V_22 & V_39 && V_4 -> V_2 == V_2 &&
F_133 ( V_243 , V_4 -> V_16 + V_240 ) &&
! F_134 ( V_243 , V_2 -> V_254 , V_2 -> V_254 + V_240 ) ) {
F_29 ( V_2 , L_17 ) ;
F_64 ( V_2 , V_255 ) ;
}
V_242 = ( F_133 ( V_243 , V_4 -> V_16 + V_241 ) ? V_243 : V_4 -> V_16 ) + V_241 ;
F_80 ( & V_50 -> V_173 -> V_174 ) ;
F_132 ( & V_2 -> V_249 , V_242 ) ;
}
