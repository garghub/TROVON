int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
bool * V_5 )
{
return F_2 ( F_3 ( V_2 ) , V_3 , V_4 , NULL , & V_6 ) ;
}
int
F_4 (
struct V_1 * V_2 ,
enum V_7 V_8 )
{
struct V_9 * V_10 ;
int error ;
error = F_5 ( V_2 -> V_11 , & F_6 ( V_2 -> V_11 ) -> V_12 ,
0 , 0 , 0 , & V_10 ) ;
if ( error )
return error ;
F_7 ( V_2 , V_13 ) ;
F_8 ( V_10 , V_2 , V_13 ) ;
if ( ! ( V_8 & V_14 ) ) {
F_3 ( V_2 ) -> V_15 &= ~ V_16 ;
if ( F_3 ( V_2 ) -> V_15 & V_17 )
F_3 ( V_2 ) -> V_15 &= ~ V_18 ;
F_9 ( V_10 , V_2 , V_19 | V_20 ) ;
}
if ( V_8 & V_21 )
V_2 -> V_22 . V_23 |= V_24 ;
if ( V_8 & V_25 )
V_2 -> V_22 . V_23 &= ~ V_24 ;
F_10 ( V_10 , V_2 , V_26 ) ;
if ( V_8 & V_27 )
F_11 ( V_10 ) ;
return F_12 ( V_10 ) ;
}
STATIC int
F_13 (
struct V_28 * V_28 ,
T_2 V_29 ,
T_2 V_30 ,
int V_31 )
{
struct V_1 * V_2 = F_14 ( V_28 -> V_32 -> V_33 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_3 V_36 = 0 ;
F_15 ( V_2 ) ;
F_7 ( V_2 , V_37 ) ;
if ( F_16 ( V_2 ) )
V_36 = V_2 -> V_38 -> V_39 ;
F_17 ( V_2 , V_37 ) ;
if ( ! V_36 )
return 0 ;
return F_18 ( V_35 , V_36 , V_40 , NULL ) ;
}
STATIC int
F_19 (
struct V_28 * V_28 ,
T_2 V_29 ,
T_2 V_30 ,
int V_31 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
int error = 0 ;
int V_42 = 0 ;
T_3 V_36 = 0 ;
F_20 ( V_2 ) ;
error = F_21 ( V_41 -> V_43 , V_29 , V_30 ) ;
if ( error )
return error ;
if ( F_22 ( V_35 ) )
return - V_44 ;
F_23 ( V_2 , V_45 ) ;
if ( F_24 ( V_2 ) )
F_25 ( V_35 -> V_46 ) ;
else if ( V_35 -> V_47 != V_35 -> V_48 )
F_25 ( V_35 -> V_48 ) ;
F_7 ( V_2 , V_37 ) ;
if ( F_16 ( V_2 ) ) {
if ( ! V_31 ||
( V_2 -> V_38 -> V_49 & ~ V_50 ) )
V_36 = V_2 -> V_38 -> V_39 ;
}
if ( V_36 ) {
error = F_18 ( V_35 , V_36 , V_40 , & V_42 ) ;
V_2 -> V_38 -> V_49 = 0 ;
}
F_17 ( V_2 , V_37 ) ;
if ( ! V_42 && ! F_24 ( V_2 ) &&
V_35 -> V_47 == V_35 -> V_48 )
F_25 ( V_35 -> V_48 ) ;
return error ;
}
STATIC T_4
F_26 (
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_14 ( F_27 ( V_52 -> V_55 ) ) ;
T_5 V_4 = F_28 ( V_54 ) ;
T_4 V_56 ;
F_29 ( V_2 , V_4 , V_52 -> V_57 ) ;
if ( ! V_4 )
return 0 ;
F_30 ( V_52 -> V_55 ) ;
F_7 ( V_2 , V_58 ) ;
V_56 = F_31 ( V_52 , V_54 , & V_6 , NULL ) ;
F_17 ( V_2 , V_58 ) ;
return V_56 ;
}
static T_6 T_4
F_32 (
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_14 ( V_52 -> V_55 -> V_32 -> V_33 ) ;
T_5 V_4 = F_28 ( V_54 ) ;
T_4 V_56 = 0 ;
F_33 ( V_2 , V_4 , V_52 -> V_57 ) ;
if ( ! V_4 )
return 0 ;
F_7 ( V_2 , V_58 ) ;
V_56 = F_34 ( V_52 , V_54 , & V_6 ) ;
F_17 ( V_2 , V_58 ) ;
F_30 ( V_52 -> V_55 ) ;
return V_56 ;
}
STATIC T_4
F_35 (
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_14 ( F_27 ( V_52 -> V_55 ) ) ;
T_4 V_56 ;
F_36 ( V_2 , F_28 ( V_54 ) , V_52 -> V_57 ) ;
F_7 ( V_2 , V_58 ) ;
V_56 = F_37 ( V_52 , V_54 ) ;
F_17 ( V_2 , V_58 ) ;
return V_56 ;
}
STATIC T_4
F_38 (
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_41 * V_41 = F_27 ( V_52 -> V_55 ) ;
struct V_34 * V_35 = F_14 ( V_41 ) -> V_11 ;
T_4 V_56 = 0 ;
F_39 ( V_35 , V_59 ) ;
if ( F_22 ( V_35 ) )
return - V_44 ;
if ( F_40 ( V_41 ) )
V_56 = F_32 ( V_52 , V_54 ) ;
else if ( V_52 -> V_60 & V_61 )
V_56 = F_26 ( V_52 , V_54 ) ;
else
V_56 = F_35 ( V_52 , V_54 ) ;
if ( V_56 > 0 )
F_41 ( V_35 , V_62 , V_56 ) ;
return V_56 ;
}
int
F_42 (
struct V_1 * V_2 ,
T_1 V_63 ,
T_7 V_64 ,
bool * V_65 )
{
ASSERT ( F_43 ( V_2 , V_66 ) ) ;
ASSERT ( V_63 > V_64 ) ;
F_44 ( V_2 , V_64 , V_63 - V_64 ) ;
return F_1 ( V_2 , V_64 , V_63 - V_64 , V_65 ) ;
}
STATIC T_4
F_45 (
struct V_51 * V_52 ,
struct V_53 * V_67 ,
int * V_68 )
{
struct V_28 * V_28 = V_52 -> V_55 ;
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 error = 0 ;
T_5 V_4 = F_28 ( V_67 ) ;
bool V_69 = false ;
V_70:
error = F_46 ( V_52 , V_67 ) ;
if ( error <= 0 )
return error ;
error = F_47 ( V_41 , V_68 ) ;
if ( error )
return error ;
if ( * V_68 == V_58 && ! F_48 ( V_41 ) ) {
F_17 ( V_2 , * V_68 ) ;
* V_68 = V_66 ;
F_7 ( V_2 , * V_68 ) ;
goto V_70;
}
F_49 ( & V_2 -> V_71 ) ;
if ( V_52 -> V_57 > F_50 ( V_41 ) ) {
bool V_72 = false ;
F_51 ( & V_2 -> V_71 ) ;
if ( ! V_69 ) {
if ( * V_68 == V_58 ) {
F_17 ( V_2 , * V_68 ) ;
* V_68 = V_66 ;
F_7 ( V_2 , * V_68 ) ;
F_52 ( V_67 , V_4 ) ;
}
F_53 ( V_41 ) ;
V_69 = true ;
goto V_70;
}
error = F_42 ( V_2 , V_52 -> V_57 , F_50 ( V_41 ) , & V_72 ) ;
if ( error )
return error ;
} else
F_51 ( & V_2 -> V_71 ) ;
if ( F_54 ( ! ( V_28 -> V_73 & V_74 ) ) ) {
error = F_55 ( V_28 ) ;
if ( error )
return error ;
}
if ( ! F_48 ( V_41 ) )
return F_56 ( V_28 ) ;
return 0 ;
}
static int
F_57 (
struct V_51 * V_52 ,
T_4 V_75 ,
unsigned V_8 )
{
struct V_41 * V_41 = F_27 ( V_52 -> V_55 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_2 V_63 = V_52 -> V_57 ;
bool V_76 = false ;
int error = 0 ;
F_58 ( V_2 , V_63 , V_75 ) ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_44 ;
if ( V_75 <= 0 )
return V_75 ;
F_49 ( & V_2 -> V_71 ) ;
if ( V_63 + V_75 > F_50 ( V_41 ) ) {
F_59 ( V_41 , V_63 + V_75 ) ;
V_76 = true ;
}
F_51 ( & V_2 -> V_71 ) ;
if ( V_8 & V_77 ) {
error = F_60 ( V_2 , V_63 , V_75 ) ;
if ( error )
return error ;
}
if ( V_8 & V_78 )
error = F_61 ( V_2 , V_63 , V_75 ) ;
else if ( V_76 )
error = F_62 ( V_2 , V_63 , V_75 ) ;
return error ;
}
STATIC T_4
F_63 (
struct V_51 * V_52 ,
struct V_53 * V_67 )
{
struct V_28 * V_28 = V_52 -> V_55 ;
struct V_79 * V_80 = V_28 -> V_32 ;
struct V_41 * V_41 = V_80 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_4 V_56 = 0 ;
int V_81 = 0 ;
int V_68 ;
T_5 V_4 = F_28 ( V_67 ) ;
struct V_82 * V_83 = F_24 ( V_2 ) ?
V_35 -> V_46 : V_35 -> V_48 ;
if ( ( V_52 -> V_57 | V_4 ) & V_83 -> V_84 )
return - V_85 ;
if ( ( V_52 -> V_57 & V_35 -> V_86 ) ||
( ( V_52 -> V_57 + V_4 ) & V_35 -> V_86 ) ) {
V_81 = 1 ;
V_68 = V_66 ;
} else {
V_68 = V_58 ;
}
F_7 ( V_2 , V_68 ) ;
V_56 = F_45 ( V_52 , V_67 , & V_68 ) ;
if ( V_56 )
goto V_87;
V_4 = F_28 ( V_67 ) ;
if ( V_81 )
F_53 ( V_41 ) ;
else if ( V_68 == V_66 ) {
F_64 ( V_2 , V_66 ) ;
V_68 = V_58 ;
}
F_65 ( V_2 , V_4 , V_52 -> V_57 ) ;
if ( F_66 ( V_2 ) && ! V_81 ) {
V_56 = F_67 ( V_2 , V_52 -> V_57 , V_4 ) ;
if ( V_56 )
goto V_87;
}
V_56 = F_31 ( V_52 , V_67 , & V_6 , F_57 ) ;
V_87:
F_17 ( V_2 , V_68 ) ;
ASSERT ( V_56 < 0 || V_56 == V_4 ) ;
return V_56 ;
}
static T_6 T_4
F_68 (
struct V_51 * V_52 ,
struct V_53 * V_67 )
{
struct V_41 * V_41 = V_52 -> V_55 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_68 = V_66 ;
T_4 V_56 , error = 0 ;
T_5 V_4 ;
T_2 V_3 ;
F_7 ( V_2 , V_68 ) ;
V_56 = F_45 ( V_52 , V_67 , & V_68 ) ;
if ( V_56 )
goto V_87;
V_3 = V_52 -> V_57 ;
V_4 = F_28 ( V_67 ) ;
F_69 ( V_2 , V_4 , V_3 ) ;
V_56 = F_34 ( V_52 , V_67 , & V_6 ) ;
if ( V_56 > 0 && V_52 -> V_57 > F_50 ( V_41 ) ) {
F_59 ( V_41 , V_52 -> V_57 ) ;
error = F_62 ( V_2 , V_3 , V_56 ) ;
}
V_87:
F_17 ( V_2 , V_68 ) ;
return error ? error : V_56 ;
}
STATIC T_4
F_70 (
struct V_51 * V_52 ,
struct V_53 * V_67 )
{
struct V_28 * V_28 = V_52 -> V_55 ;
struct V_79 * V_80 = V_28 -> V_32 ;
struct V_41 * V_41 = V_80 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_56 ;
int V_88 = 0 ;
int V_68 = V_66 ;
F_7 ( V_2 , V_68 ) ;
V_56 = F_45 ( V_52 , V_67 , & V_68 ) ;
if ( V_56 )
goto V_87;
V_89 -> V_90 = F_71 ( V_41 ) ;
V_91:
F_72 ( V_2 , F_28 ( V_67 ) , V_52 -> V_57 ) ;
V_56 = F_73 ( V_52 , V_67 , & V_6 ) ;
if ( F_54 ( V_56 >= 0 ) )
V_52 -> V_57 += V_56 ;
if ( V_56 == - V_92 && ! V_88 ) {
V_88 = F_74 ( V_2 ) ;
if ( V_88 )
goto V_91;
V_88 = F_75 ( V_2 ) ;
if ( V_88 )
goto V_91;
} else if ( V_56 == - V_93 && ! V_88 ) {
struct V_94 V_95 = { 0 } ;
V_88 = 1 ;
F_76 ( V_2 -> V_11 ) ;
V_95 . V_96 = V_2 -> V_97 ;
V_95 . V_98 = V_99 ;
F_77 ( V_2 -> V_11 , & V_95 ) ;
goto V_91;
}
V_89 -> V_90 = NULL ;
V_87:
F_17 ( V_2 , V_68 ) ;
return V_56 ;
}
STATIC T_4
F_78 (
struct V_51 * V_52 ,
struct V_53 * V_67 )
{
struct V_28 * V_28 = V_52 -> V_55 ;
struct V_79 * V_80 = V_28 -> V_32 ;
struct V_41 * V_41 = V_80 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
T_4 V_56 ;
T_5 V_100 = F_28 ( V_67 ) ;
F_39 ( V_2 -> V_11 , V_101 ) ;
if ( V_100 == 0 )
return 0 ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_44 ;
if ( F_40 ( V_41 ) )
V_56 = F_68 ( V_52 , V_67 ) ;
else if ( V_52 -> V_60 & V_61 ) {
V_56 = F_63 ( V_52 , V_67 ) ;
if ( V_56 == - V_102 )
goto V_103;
} else {
V_103:
V_56 = F_70 ( V_52 , V_67 ) ;
}
if ( V_56 > 0 ) {
F_41 ( V_2 -> V_11 , V_104 , V_56 ) ;
V_56 = F_79 ( V_52 , V_56 ) ;
}
return V_56 ;
}
STATIC long
F_80 (
struct V_28 * V_28 ,
int V_105 ,
T_2 V_63 ,
T_2 V_106 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
long error ;
enum V_7 V_8 = 0 ;
T_8 V_68 = V_66 ;
T_2 V_107 = 0 ;
bool V_108 = 0 ;
if ( ! F_81 ( V_41 -> V_15 ) )
return - V_85 ;
if ( V_105 & ~ V_109 )
return - V_110 ;
F_7 ( V_2 , V_68 ) ;
error = F_47 ( V_41 , & V_68 ) ;
if ( error )
goto V_111;
F_7 ( V_2 , V_112 ) ;
V_68 |= V_112 ;
if ( V_105 & V_113 ) {
error = F_82 ( V_2 , V_63 , V_106 ) ;
if ( error )
goto V_111;
} else if ( V_105 & V_114 ) {
unsigned V_115 = ( 1 << V_41 -> V_116 ) - 1 ;
if ( V_63 & V_115 || V_106 & V_115 ) {
error = - V_85 ;
goto V_111;
}
if ( V_63 + V_106 >= F_50 ( V_41 ) ) {
error = - V_85 ;
goto V_111;
}
V_107 = F_50 ( V_41 ) - V_106 ;
error = F_83 ( V_2 , V_63 , V_106 ) ;
if ( error )
goto V_111;
} else if ( V_105 & V_117 ) {
unsigned V_115 = ( 1 << V_41 -> V_116 ) - 1 ;
V_107 = F_50 ( V_41 ) + V_106 ;
if ( V_63 & V_115 || V_106 & V_115 ) {
error = - V_85 ;
goto V_111;
}
if ( V_107 > V_41 -> V_118 -> V_119 ) {
error = - V_120 ;
goto V_111;
}
if ( V_63 >= F_50 ( V_41 ) ) {
error = - V_85 ;
goto V_111;
}
V_108 = 1 ;
} else {
V_8 |= V_21 ;
if ( ! ( V_105 & V_121 ) &&
V_63 + V_106 > F_50 ( V_41 ) ) {
V_107 = V_63 + V_106 ;
error = F_84 ( V_41 , V_107 ) ;
if ( error )
goto V_111;
}
if ( V_105 & V_122 )
error = F_85 ( V_2 , V_63 , V_106 ) ;
else {
if ( V_105 & V_123 ) {
error = F_86 ( V_2 , V_63 , V_106 ) ;
if ( error )
goto V_111;
}
error = F_87 ( V_2 , V_63 , V_106 ,
V_124 ) ;
}
if ( error )
goto V_111;
}
if ( V_28 -> V_125 & V_126 )
V_8 |= V_27 ;
error = F_4 ( V_2 , V_8 ) ;
if ( error )
goto V_111;
if ( V_107 ) {
struct V_127 V_127 ;
V_127 . V_128 = V_129 ;
V_127 . V_130 = V_107 ;
error = F_88 ( F_89 ( V_28 ) , & V_127 ) ;
if ( error )
goto V_111;
}
if ( V_108 )
error = F_90 ( V_2 , V_63 , V_106 ) ;
V_111:
F_17 ( V_2 , V_68 ) ;
return error ;
}
STATIC int
F_91 (
struct V_28 * V_131 ,
T_2 V_132 ,
struct V_28 * V_133 ,
T_2 V_134 ,
T_9 V_106 )
{
return F_92 ( V_131 , V_132 , V_133 , V_134 ,
V_106 , false ) ;
}
STATIC T_4
F_93 (
struct V_28 * V_135 ,
T_9 V_136 ,
T_9 V_106 ,
struct V_28 * V_137 ,
T_9 V_138 )
{
int error ;
error = F_92 ( V_135 , V_136 , V_137 , V_138 ,
V_106 , true ) ;
if ( error )
return error ;
return V_106 ;
}
STATIC int
F_94 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
if ( ! ( V_28 -> V_125 & V_139 ) && F_50 ( V_41 ) > V_140 )
return - V_120 ;
if ( F_22 ( F_95 ( V_41 -> V_118 ) ) )
return - V_44 ;
return 0 ;
}
STATIC int
F_96 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_105 ;
int error ;
error = F_94 ( V_41 , V_28 ) ;
if ( error )
return error ;
V_105 = F_97 ( V_2 ) ;
if ( V_2 -> V_22 . V_141 > 0 )
F_98 ( V_2 , 0 , - 1 ) ;
F_17 ( V_2 , V_105 ) ;
return 0 ;
}
STATIC int
F_99 (
struct V_41 * V_41 ,
struct V_28 * V_142 )
{
return F_100 ( F_14 ( V_41 ) ) ;
}
STATIC int
F_101 (
struct V_28 * V_28 ,
struct V_143 * V_144 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
T_10 * V_2 = F_14 ( V_41 ) ;
T_5 V_145 ;
V_145 = ( T_5 ) F_102 ( T_2 , 32768 , V_2 -> V_22 . V_146 ) ;
return F_103 ( V_2 , V_144 , V_145 ) ;
}
STATIC bool
F_104 (
struct V_147 * V_147 ,
T_2 * V_63 ,
unsigned int type )
{
T_2 V_148 = F_105 ( V_147 ) ;
bool V_149 = false ;
struct V_150 * V_151 , * V_152 ;
V_151 = V_152 = F_106 ( V_147 ) ;
do {
if ( F_107 ( V_151 ) ||
F_108 ( V_151 ) ) {
if ( type == V_153 )
V_149 = true ;
} else {
if ( type == V_154 )
V_149 = true ;
}
if ( V_149 ) {
* V_63 = V_148 ;
break;
}
V_148 += V_151 -> V_155 ;
} while ( ( V_151 = V_151 -> V_156 ) != V_152 );
return V_149 ;
}
STATIC bool
F_109 (
struct V_41 * V_41 ,
struct V_157 * V_158 ,
unsigned int type ,
T_2 * V_63 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
struct V_159 V_160 ;
T_11 V_161 ;
T_11 V_30 ;
T_2 V_162 ;
T_2 V_163 = * V_63 ;
T_2 V_148 = V_163 ;
bool V_149 = false ;
F_110 ( & V_160 , 0 ) ;
V_161 = V_163 >> V_164 ;
V_162 = F_111 ( V_35 , V_158 -> V_165 + V_158 -> V_166 ) ;
V_30 = V_162 >> V_164 ;
do {
int V_167 ;
unsigned V_168 ;
unsigned int V_169 ;
V_167 = F_102 ( T_11 , V_30 - V_161 , V_170 ) ;
V_168 = F_112 ( & V_160 , V_41 -> V_43 , V_161 ,
V_167 ) ;
if ( V_168 == 0 ) {
if ( type == V_153 )
break;
ASSERT ( type == V_154 ) ;
if ( V_148 == V_163 || V_148 < V_162 ) {
V_149 = true ;
* V_63 = V_148 ;
}
break;
}
if ( type == V_154 && V_148 == V_163 &&
V_148 < F_105 ( V_160 . V_171 [ 0 ] ) ) {
V_149 = true ;
break;
}
for ( V_169 = 0 ; V_169 < V_168 ; V_169 ++ ) {
struct V_147 * V_147 = V_160 . V_171 [ V_169 ] ;
T_2 V_172 ;
if ( V_147 -> V_161 > V_30 ) {
if ( type == V_154 && V_148 < V_162 ) {
* V_63 = V_148 ;
V_149 = true ;
}
goto V_87;
}
F_113 ( V_147 ) ;
if ( F_114 ( V_147 -> V_80 != V_41 -> V_43 ) ) {
F_115 ( V_147 ) ;
continue;
}
if ( ! F_116 ( V_147 ) ) {
F_115 ( V_147 ) ;
continue;
}
V_149 = F_104 ( V_147 , & V_172 , type ) ;
if ( V_149 ) {
* V_63 = F_117 ( T_2 , V_163 , V_172 ) ;
F_115 ( V_147 ) ;
goto V_87;
}
V_148 = F_105 ( V_147 ) + V_173 ;
F_115 ( V_147 ) ;
}
if ( V_168 < V_167 ) {
if ( type == V_154 ) {
* V_63 = V_148 ;
V_149 = true ;
}
break;
}
V_161 = V_160 . V_171 [ V_169 - 1 ] -> V_161 + 1 ;
F_118 ( & V_160 ) ;
} while ( V_161 <= V_30 );
V_87:
F_118 ( & V_160 ) ;
return V_149 ;
}
T_2
F_119 (
struct V_41 * V_41 ,
T_2 V_29 ,
T_2 V_30 ,
int V_174 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_2 V_175 ( V_63 ) ;
T_12 V_176 ;
T_13 V_177 ;
int error ;
if ( V_29 >= V_30 ) {
error = - V_178 ;
goto V_179;
}
V_176 = F_120 ( V_35 , V_29 ) ;
V_177 = F_121 ( V_35 , V_30 ) ;
for (; ; ) {
struct V_157 V_158 [ 2 ] ;
int V_180 = 2 ;
unsigned int V_169 ;
error = F_122 ( V_2 , V_176 , V_177 - V_176 , V_158 , & V_180 ,
V_181 ) ;
if ( error )
goto V_179;
if ( V_180 == 0 ) {
error = - V_178 ;
goto V_179;
}
for ( V_169 = 0 ; V_169 < V_180 ; V_169 ++ ) {
V_63 = F_117 ( T_2 , V_29 ,
F_111 ( V_35 , V_158 [ V_169 ] . V_165 ) ) ;
if ( V_174 == V_182 &&
V_158 [ V_169 ] . V_183 == V_184 )
goto V_87;
if ( V_174 == V_185 &&
( V_158 [ V_169 ] . V_183 == V_186 ||
( V_158 [ V_169 ] . V_187 == V_188 &&
! F_123 ( V_158 [ V_169 ] . V_183 ) ) ) )
goto V_87;
if ( V_158 [ V_169 ] . V_187 == V_189 ) {
if ( F_109 ( V_41 , & V_158 [ V_169 ] ,
V_174 == V_182 ? V_154 : V_153 ,
& V_63 ) )
goto V_87;
}
}
if ( V_180 == 1 ) {
if ( V_174 == V_182 ) {
V_63 = V_30 ;
break;
}
ASSERT ( V_174 == V_185 ) ;
error = - V_178 ;
goto V_179;
}
ASSERT ( V_169 > 1 ) ;
V_176 = V_158 [ V_169 - 1 ] . V_165 + V_158 [ V_169 - 1 ] . V_166 ;
V_29 = F_111 ( V_35 , V_176 ) ;
if ( V_29 >= V_30 ) {
if ( V_174 == V_182 ) {
V_63 = V_30 ;
break;
}
ASSERT ( V_174 == V_185 ) ;
error = - V_178 ;
goto V_179;
}
}
V_87:
if ( V_174 == V_182 )
V_63 = F_102 ( T_2 , V_63 , V_30 ) ;
return V_63 ;
V_179:
return error ;
}
STATIC T_2
F_124 (
struct V_28 * V_28 ,
T_2 V_29 ,
int V_174 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_8 V_190 ;
T_2 V_63 , V_30 ;
int error = 0 ;
if ( F_22 ( V_35 ) )
return - V_44 ;
V_190 = F_97 ( V_2 ) ;
V_30 = F_50 ( V_41 ) ;
V_63 = F_119 ( V_41 , V_29 , V_30 , V_174 ) ;
if ( V_63 < 0 ) {
error = V_63 ;
goto V_111;
}
V_63 = F_125 ( V_28 , V_63 , V_41 -> V_118 -> V_119 ) ;
V_111:
F_17 ( V_2 , V_190 ) ;
if ( error )
return error ;
return V_63 ;
}
STATIC T_2
F_126 (
struct V_28 * V_28 ,
T_2 V_63 ,
int V_174 )
{
switch ( V_174 ) {
case V_191 :
case V_192 :
case V_193 :
return F_127 ( V_28 , V_63 , V_174 ) ;
case V_182 :
case V_185 :
return F_124 ( V_28 , V_63 , V_174 ) ;
default:
return - V_85 ;
}
}
STATIC int
F_128 (
struct V_194 * V_195 ,
struct V_196 * V_197 )
{
struct V_41 * V_41 = F_27 ( V_195 -> V_198 ) ;
int V_56 ;
F_129 ( F_14 ( V_41 ) ) ;
F_130 ( V_41 -> V_118 ) ;
F_55 ( V_195 -> V_198 ) ;
F_7 ( F_14 ( V_41 ) , V_199 ) ;
if ( F_40 ( V_41 ) ) {
V_56 = F_131 ( V_195 , V_197 , & V_6 ) ;
} else {
V_56 = F_132 ( V_195 , V_197 , & V_6 ) ;
V_56 = F_133 ( V_56 ) ;
}
F_17 ( F_14 ( V_41 ) , V_199 ) ;
F_134 ( V_41 -> V_118 ) ;
return V_56 ;
}
STATIC int
F_135 (
struct V_194 * V_195 ,
struct V_196 * V_197 )
{
struct V_41 * V_41 = F_27 ( V_195 -> V_198 ) ;
int V_56 ;
F_136 ( F_14 ( V_41 ) ) ;
if ( ( V_197 -> V_8 & V_200 ) && F_40 ( V_41 ) )
return F_128 ( V_195 , V_197 ) ;
F_7 ( F_14 ( V_41 ) , V_199 ) ;
if ( F_40 ( V_41 ) )
V_56 = F_131 ( V_195 , V_197 , & V_6 ) ;
else
V_56 = F_137 ( V_195 , V_197 ) ;
F_17 ( F_14 ( V_41 ) , V_199 ) ;
return V_56 ;
}
STATIC int
F_138 (
struct V_194 * V_195 ,
unsigned long V_201 ,
T_14 * V_202 ,
unsigned int V_8 )
{
struct V_41 * V_41 = F_27 ( V_195 -> V_198 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_56 ;
if ( ! F_40 ( V_41 ) )
return V_203 ;
F_139 ( V_2 ) ;
if ( V_8 & V_200 ) {
F_130 ( V_41 -> V_118 ) ;
F_55 ( V_195 -> V_198 ) ;
}
F_7 ( F_14 ( V_41 ) , V_199 ) ;
V_56 = F_140 ( V_195 , V_201 , V_202 , V_8 , & V_6 ) ;
F_17 ( F_14 ( V_41 ) , V_199 ) ;
if ( V_8 & V_200 )
F_134 ( V_41 -> V_118 ) ;
return V_56 ;
}
static int
F_141 (
struct V_194 * V_195 ,
struct V_196 * V_197 )
{
struct V_41 * V_41 = F_27 ( V_195 -> V_198 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_56 = V_204 ;
T_2 V_75 ;
F_142 ( V_2 ) ;
F_130 ( V_41 -> V_118 ) ;
F_55 ( V_195 -> V_198 ) ;
F_7 ( V_2 , V_199 ) ;
V_75 = ( F_50 ( V_41 ) + V_173 - 1 ) >> V_164 ;
if ( V_197 -> V_205 >= V_75 )
V_56 = V_206 ;
else if ( F_40 ( V_41 ) )
V_56 = F_143 ( V_195 , V_197 ) ;
F_17 ( V_2 , V_199 ) ;
F_134 ( V_41 -> V_118 ) ;
return V_56 ;
}
STATIC int
F_144 (
struct V_28 * V_142 ,
struct V_194 * V_195 )
{
F_30 ( V_142 ) ;
V_195 -> V_207 = & V_208 ;
if ( F_40 ( F_27 ( V_142 ) ) )
V_195 -> V_209 |= V_210 | V_211 ;
return 0 ;
}
