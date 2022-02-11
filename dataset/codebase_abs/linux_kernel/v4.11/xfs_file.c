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
if ( F_64 ( V_2 ) ) {
F_65 ( V_2 , V_52 -> V_57 , V_4 ) ;
return - V_87 ;
}
V_68 = V_66 ;
} else {
V_68 = V_58 ;
}
F_7 ( V_2 , V_68 ) ;
V_56 = F_45 ( V_52 , V_67 , & V_68 ) ;
if ( V_56 )
goto V_88;
V_4 = F_28 ( V_67 ) ;
if ( V_81 )
F_53 ( V_41 ) ;
else if ( V_68 == V_66 ) {
F_66 ( V_2 , V_66 ) ;
V_68 = V_58 ;
}
F_67 ( V_2 , V_4 , V_52 -> V_57 ) ;
V_56 = F_31 ( V_52 , V_67 , & V_6 , F_57 ) ;
V_88:
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
goto V_88;
V_3 = V_52 -> V_57 ;
V_4 = F_28 ( V_67 ) ;
F_69 ( V_2 , V_4 , V_3 ) ;
V_56 = F_34 ( V_52 , V_67 , & V_6 ) ;
if ( V_56 > 0 && V_52 -> V_57 > F_50 ( V_41 ) ) {
F_59 ( V_41 , V_52 -> V_57 ) ;
error = F_62 ( V_2 , V_3 , V_56 ) ;
}
V_88:
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
int V_89 = 0 ;
int V_68 ;
V_90:
V_68 = V_66 ;
F_7 ( V_2 , V_68 ) ;
V_56 = F_45 ( V_52 , V_67 , & V_68 ) ;
if ( V_56 )
goto V_88;
V_91 -> V_92 = F_71 ( V_41 ) ;
F_72 ( V_2 , F_28 ( V_67 ) , V_52 -> V_57 ) ;
V_56 = F_73 ( V_52 , V_67 , & V_6 ) ;
if ( F_54 ( V_56 >= 0 ) )
V_52 -> V_57 += V_56 ;
if ( V_56 == - V_93 && ! V_89 ) {
F_17 ( V_2 , V_68 ) ;
V_89 = F_74 ( V_2 ) ;
if ( V_89 )
goto V_90;
V_89 = F_75 ( V_2 ) ;
if ( V_89 )
goto V_90;
V_68 = 0 ;
} else if ( V_56 == - V_94 && ! V_89 ) {
struct V_95 V_96 = { 0 } ;
V_89 = 1 ;
F_76 ( V_2 -> V_11 ) ;
F_17 ( V_2 , V_68 ) ;
V_96 . V_97 = V_98 ;
F_77 ( V_2 -> V_11 , & V_96 ) ;
goto V_90;
}
V_91 -> V_92 = NULL ;
V_88:
if ( V_68 )
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
T_5 V_99 = F_28 ( V_67 ) ;
F_39 ( V_2 -> V_11 , V_100 ) ;
if ( V_99 == 0 )
return 0 ;
if ( F_22 ( V_2 -> V_11 ) )
return - V_44 ;
if ( F_40 ( V_41 ) )
V_56 = F_68 ( V_52 , V_67 ) ;
else if ( V_52 -> V_60 & V_61 ) {
V_56 = F_63 ( V_52 , V_67 ) ;
if ( V_56 == - V_87 )
goto V_101;
} else {
V_101:
V_56 = F_70 ( V_52 , V_67 ) ;
}
if ( V_56 > 0 ) {
F_41 ( V_2 -> V_11 , V_102 , V_56 ) ;
V_56 = F_79 ( V_52 , V_56 ) ;
}
return V_56 ;
}
STATIC long
F_80 (
struct V_28 * V_28 ,
int V_103 ,
T_2 V_63 ,
T_2 V_104 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
long error ;
enum V_7 V_8 = 0 ;
T_8 V_68 = V_66 ;
T_2 V_105 = 0 ;
bool V_106 = 0 ;
if ( ! F_81 ( V_41 -> V_15 ) )
return - V_85 ;
if ( V_103 & ~ V_107 )
return - V_108 ;
F_7 ( V_2 , V_68 ) ;
error = F_47 ( V_41 , & V_68 ) ;
if ( error )
goto V_109;
F_7 ( V_2 , V_110 ) ;
V_68 |= V_110 ;
if ( V_103 & V_111 ) {
error = F_82 ( V_2 , V_63 , V_104 ) ;
if ( error )
goto V_109;
} else if ( V_103 & V_112 ) {
unsigned int V_113 = F_83 ( V_41 ) - 1 ;
if ( V_63 & V_113 || V_104 & V_113 ) {
error = - V_85 ;
goto V_109;
}
if ( V_63 + V_104 >= F_50 ( V_41 ) ) {
error = - V_85 ;
goto V_109;
}
V_105 = F_50 ( V_41 ) - V_104 ;
error = F_84 ( V_2 , V_63 , V_104 ) ;
if ( error )
goto V_109;
} else if ( V_103 & V_114 ) {
unsigned int V_113 = F_83 ( V_41 ) - 1 ;
V_105 = F_50 ( V_41 ) + V_104 ;
if ( V_63 & V_113 || V_104 & V_113 ) {
error = - V_85 ;
goto V_109;
}
if ( V_105 > V_41 -> V_115 -> V_116 ) {
error = - V_117 ;
goto V_109;
}
if ( V_63 >= F_50 ( V_41 ) ) {
error = - V_85 ;
goto V_109;
}
V_106 = 1 ;
} else {
V_8 |= V_21 ;
if ( ! ( V_103 & V_118 ) &&
V_63 + V_104 > F_50 ( V_41 ) ) {
V_105 = V_63 + V_104 ;
error = F_85 ( V_41 , V_105 ) ;
if ( error )
goto V_109;
}
if ( V_103 & V_119 )
error = F_86 ( V_2 , V_63 , V_104 ) ;
else {
if ( V_103 & V_120 ) {
error = F_87 ( V_2 , V_63 , V_104 ) ;
if ( error )
goto V_109;
}
error = F_88 ( V_2 , V_63 , V_104 ,
V_121 ) ;
}
if ( error )
goto V_109;
}
if ( V_28 -> V_122 & V_123 )
V_8 |= V_27 ;
error = F_4 ( V_2 , V_8 ) ;
if ( error )
goto V_109;
if ( V_105 ) {
struct V_124 V_124 ;
V_124 . V_125 = V_126 ;
V_124 . V_127 = V_105 ;
error = F_89 ( F_90 ( V_28 ) , & V_124 ) ;
if ( error )
goto V_109;
}
if ( V_106 )
error = F_91 ( V_2 , V_63 , V_104 ) ;
V_109:
F_17 ( V_2 , V_68 ) ;
return error ;
}
STATIC int
F_92 (
struct V_28 * V_128 ,
T_2 V_129 ,
struct V_28 * V_130 ,
T_2 V_131 ,
T_9 V_104 )
{
return F_93 ( V_128 , V_129 , V_130 , V_131 ,
V_104 , false ) ;
}
STATIC T_4
F_94 (
struct V_28 * V_132 ,
T_9 V_133 ,
T_9 V_104 ,
struct V_28 * V_134 ,
T_9 V_135 )
{
int error ;
error = F_93 ( V_132 , V_133 , V_134 , V_135 ,
V_104 , true ) ;
if ( error )
return error ;
return V_104 ;
}
STATIC int
F_95 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
if ( ! ( V_28 -> V_122 & V_136 ) && F_50 ( V_41 ) > V_137 )
return - V_117 ;
if ( F_22 ( F_96 ( V_41 -> V_115 ) ) )
return - V_44 ;
return 0 ;
}
STATIC int
F_97 (
struct V_41 * V_41 ,
struct V_28 * V_28 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_103 ;
int error ;
error = F_95 ( V_41 , V_28 ) ;
if ( error )
return error ;
V_103 = F_98 ( V_2 ) ;
if ( V_2 -> V_22 . V_138 > 0 )
error = F_99 ( V_2 , 0 , - 1 ) ;
F_17 ( V_2 , V_103 ) ;
return error ;
}
STATIC int
F_100 (
struct V_41 * V_41 ,
struct V_28 * V_139 )
{
return F_101 ( F_14 ( V_41 ) ) ;
}
STATIC int
F_102 (
struct V_28 * V_28 ,
struct V_140 * V_141 )
{
struct V_41 * V_41 = F_27 ( V_28 ) ;
T_10 * V_2 = F_14 ( V_41 ) ;
T_5 V_142 ;
V_142 = ( T_5 ) F_103 ( T_2 , 32768 , V_2 -> V_22 . V_143 ) ;
return F_104 ( V_2 , V_141 , V_142 ) ;
}
STATIC bool
F_105 (
struct V_144 * V_144 ,
T_2 * V_63 ,
unsigned int type )
{
T_2 V_145 = F_106 ( V_144 ) ;
bool V_146 = false ;
struct V_147 * V_148 , * V_149 ;
V_148 = V_149 = F_107 ( V_144 ) ;
do {
if ( F_108 ( V_148 ) ||
F_109 ( V_148 ) ) {
if ( type == V_150 )
V_146 = true ;
} else {
if ( type == V_151 )
V_146 = true ;
}
if ( V_146 ) {
* V_63 = V_145 ;
break;
}
V_145 += V_148 -> V_152 ;
} while ( ( V_148 = V_148 -> V_153 ) != V_149 );
return V_146 ;
}
STATIC bool
F_110 (
struct V_41 * V_41 ,
struct V_154 * V_155 ,
unsigned int type ,
T_2 * V_63 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
struct V_156 V_157 ;
T_11 V_158 ;
T_11 V_30 ;
T_2 V_159 ;
T_2 V_160 = * V_63 ;
T_2 V_145 = V_160 ;
bool V_146 = false ;
F_111 ( & V_157 , 0 ) ;
V_158 = V_160 >> V_161 ;
V_159 = F_112 ( V_35 , V_155 -> V_162 + V_155 -> V_163 ) ;
V_30 = V_159 >> V_161 ;
do {
int V_164 ;
unsigned V_165 ;
unsigned int V_166 ;
V_164 = F_103 ( T_11 , V_30 - V_158 , V_167 ) ;
V_165 = F_113 ( & V_157 , V_41 -> V_43 , V_158 ,
V_164 ) ;
if ( V_165 == 0 ) {
if ( type == V_150 )
break;
ASSERT ( type == V_151 ) ;
if ( V_145 == V_160 || V_145 < V_159 ) {
V_146 = true ;
* V_63 = V_145 ;
}
break;
}
if ( type == V_151 && V_145 == V_160 &&
V_145 < F_106 ( V_157 . V_168 [ 0 ] ) ) {
V_146 = true ;
break;
}
for ( V_166 = 0 ; V_166 < V_165 ; V_166 ++ ) {
struct V_144 * V_144 = V_157 . V_168 [ V_166 ] ;
T_2 V_169 ;
if ( V_144 -> V_158 > V_30 ) {
if ( type == V_151 && V_145 < V_159 ) {
* V_63 = V_145 ;
V_146 = true ;
}
goto V_88;
}
F_114 ( V_144 ) ;
if ( F_115 ( V_144 -> V_80 != V_41 -> V_43 ) ) {
F_116 ( V_144 ) ;
continue;
}
if ( ! F_117 ( V_144 ) ) {
F_116 ( V_144 ) ;
continue;
}
V_146 = F_105 ( V_144 , & V_169 , type ) ;
if ( V_146 ) {
* V_63 = F_118 ( T_2 , V_160 , V_169 ) ;
F_116 ( V_144 ) ;
goto V_88;
}
V_145 = F_106 ( V_144 ) + V_170 ;
F_116 ( V_144 ) ;
}
if ( V_165 < V_164 ) {
if ( type == V_151 ) {
* V_63 = V_145 ;
V_146 = true ;
}
break;
}
V_158 = V_157 . V_168 [ V_166 - 1 ] -> V_158 + 1 ;
F_119 ( & V_157 ) ;
} while ( V_158 <= V_30 );
V_88:
F_119 ( & V_157 ) ;
return V_146 ;
}
T_2
F_120 (
struct V_41 * V_41 ,
T_2 V_29 ,
T_2 V_30 ,
int V_171 )
{
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_2 V_172 ( V_63 ) ;
T_12 V_173 ;
T_13 V_174 ;
int error ;
if ( V_29 >= V_30 ) {
error = - V_175 ;
goto V_176;
}
V_173 = F_121 ( V_35 , V_29 ) ;
V_174 = F_122 ( V_35 , V_30 ) ;
for (; ; ) {
struct V_154 V_155 [ 2 ] ;
int V_177 = 2 ;
unsigned int V_166 ;
error = F_123 ( V_2 , V_173 , V_174 - V_173 , V_155 , & V_177 ,
V_178 ) ;
if ( error )
goto V_176;
if ( V_177 == 0 ) {
error = - V_175 ;
goto V_176;
}
for ( V_166 = 0 ; V_166 < V_177 ; V_166 ++ ) {
V_63 = F_118 ( T_2 , V_29 ,
F_112 ( V_35 , V_155 [ V_166 ] . V_162 ) ) ;
if ( V_171 == V_179 &&
V_155 [ V_166 ] . V_180 == V_181 )
goto V_88;
if ( V_171 == V_182 &&
( V_155 [ V_166 ] . V_180 == V_183 ||
( V_155 [ V_166 ] . V_184 == V_185 &&
! F_124 ( V_155 [ V_166 ] . V_180 ) ) ) )
goto V_88;
if ( V_155 [ V_166 ] . V_184 == V_186 ) {
if ( F_110 ( V_41 , & V_155 [ V_166 ] ,
V_171 == V_179 ? V_151 : V_150 ,
& V_63 ) )
goto V_88;
}
}
if ( V_177 == 1 ) {
if ( V_171 == V_179 ) {
V_63 = V_30 ;
break;
}
ASSERT ( V_171 == V_182 ) ;
error = - V_175 ;
goto V_176;
}
ASSERT ( V_166 > 1 ) ;
V_173 = V_155 [ V_166 - 1 ] . V_162 + V_155 [ V_166 - 1 ] . V_163 ;
V_29 = F_112 ( V_35 , V_173 ) ;
if ( V_29 >= V_30 ) {
if ( V_171 == V_179 ) {
V_63 = V_30 ;
break;
}
ASSERT ( V_171 == V_182 ) ;
error = - V_175 ;
goto V_176;
}
}
V_88:
if ( V_171 == V_179 )
V_63 = F_103 ( T_2 , V_63 , V_30 ) ;
return V_63 ;
V_176:
return error ;
}
STATIC T_2
F_125 (
struct V_28 * V_28 ,
T_2 V_29 ,
int V_171 )
{
struct V_41 * V_41 = V_28 -> V_32 -> V_33 ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
struct V_34 * V_35 = V_2 -> V_11 ;
T_8 V_187 ;
T_2 V_63 , V_30 ;
int error = 0 ;
if ( F_22 ( V_35 ) )
return - V_44 ;
V_187 = F_98 ( V_2 ) ;
V_30 = F_50 ( V_41 ) ;
V_63 = F_120 ( V_41 , V_29 , V_30 , V_171 ) ;
if ( V_63 < 0 ) {
error = V_63 ;
goto V_109;
}
V_63 = F_126 ( V_28 , V_63 , V_41 -> V_115 -> V_116 ) ;
V_109:
F_17 ( V_2 , V_187 ) ;
if ( error )
return error ;
return V_63 ;
}
STATIC T_2
F_127 (
struct V_28 * V_28 ,
T_2 V_63 ,
int V_171 )
{
switch ( V_171 ) {
case V_188 :
case V_189 :
case V_190 :
return F_128 ( V_28 , V_63 , V_171 ) ;
case V_179 :
case V_182 :
return F_125 ( V_28 , V_63 , V_171 ) ;
default:
return - V_85 ;
}
}
STATIC int
F_129 (
struct V_191 * V_192 )
{
struct V_41 * V_41 = F_27 ( V_192 -> V_193 -> V_194 ) ;
int V_56 ;
F_130 ( F_14 ( V_41 ) ) ;
F_131 ( V_41 -> V_115 ) ;
F_55 ( V_192 -> V_193 -> V_194 ) ;
F_7 ( F_14 ( V_41 ) , V_195 ) ;
if ( F_40 ( V_41 ) ) {
V_56 = F_132 ( V_192 , V_196 , & V_6 ) ;
} else {
V_56 = F_133 ( V_192 , & V_6 ) ;
V_56 = F_134 ( V_56 ) ;
}
F_17 ( F_14 ( V_41 ) , V_195 ) ;
F_135 ( V_41 -> V_115 ) ;
return V_56 ;
}
STATIC int
F_136 (
struct V_191 * V_192 )
{
struct V_41 * V_41 = F_27 ( V_192 -> V_193 -> V_194 ) ;
int V_56 ;
F_137 ( F_14 ( V_41 ) ) ;
if ( ( V_192 -> V_8 & V_197 ) && F_40 ( V_41 ) )
return F_129 ( V_192 ) ;
F_7 ( F_14 ( V_41 ) , V_195 ) ;
if ( F_40 ( V_41 ) )
V_56 = F_132 ( V_192 , V_196 , & V_6 ) ;
else
V_56 = F_138 ( V_192 ) ;
F_17 ( F_14 ( V_41 ) , V_195 ) ;
return V_56 ;
}
STATIC int
F_139 (
struct V_191 * V_192 ,
enum V_198 V_199 )
{
struct V_41 * V_41 = F_27 ( V_192 -> V_193 -> V_194 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_56 ;
if ( ! F_40 ( V_41 ) )
return V_200 ;
F_140 ( V_2 ) ;
if ( V_192 -> V_8 & V_197 ) {
F_131 ( V_41 -> V_115 ) ;
F_55 ( V_192 -> V_193 -> V_194 ) ;
}
F_7 ( F_14 ( V_41 ) , V_195 ) ;
V_56 = F_132 ( V_192 , V_199 , & V_6 ) ;
F_17 ( F_14 ( V_41 ) , V_195 ) ;
if ( V_192 -> V_8 & V_197 )
F_135 ( V_41 -> V_115 ) ;
return V_56 ;
}
static int
F_141 (
struct V_191 * V_192 )
{
struct V_41 * V_41 = F_27 ( V_192 -> V_193 -> V_194 ) ;
struct V_1 * V_2 = F_14 ( V_41 ) ;
int V_56 = V_201 ;
T_2 V_75 ;
F_142 ( V_2 ) ;
F_131 ( V_41 -> V_115 ) ;
F_55 ( V_192 -> V_193 -> V_194 ) ;
F_7 ( V_2 , V_195 ) ;
V_75 = ( F_50 ( V_41 ) + V_170 - 1 ) >> V_161 ;
if ( V_192 -> V_202 >= V_75 )
V_56 = V_203 ;
else if ( F_40 ( V_41 ) )
V_56 = F_143 ( V_192 ) ;
F_17 ( V_2 , V_195 ) ;
F_135 ( V_41 -> V_115 ) ;
return V_56 ;
}
STATIC int
F_144 (
struct V_28 * V_139 ,
struct V_204 * V_193 )
{
F_30 ( V_139 ) ;
V_193 -> V_205 = & V_206 ;
if ( F_40 ( F_27 ( V_139 ) ) )
V_193 -> V_207 |= V_208 | V_209 ;
return 0 ;
}
