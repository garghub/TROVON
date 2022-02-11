int F_1 ( struct V_1 * V_1 , T_1 V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
struct V_7 V_8 ;
if ( V_2 < 0 )
return - V_9 ;
V_8 . V_10 = V_2 ;
V_8 . V_11 = V_12 | V_3 ;
if ( V_5 ) {
V_8 . V_13 = V_5 ;
V_8 . V_11 |= V_14 ;
}
V_6 = F_2 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 )
V_8 . V_11 |= V_6 | V_15 ;
F_3 ( & V_1 -> V_16 -> V_17 ) ;
V_6 = F_4 ( V_1 , & V_8 , NULL ) ;
F_5 ( & V_1 -> V_16 -> V_17 ) ;
return V_6 ;
}
long F_6 ( struct V_18 * V_18 , T_1 V_2 )
{
struct V_19 * V_19 ;
long error ;
V_19 = V_18 -> V_1 -> V_16 ;
if ( F_7 ( V_19 -> V_20 ) )
return - V_21 ;
if ( ! F_8 ( V_19 -> V_20 ) )
return - V_9 ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
goto V_23;
error = F_10 ( V_19 , V_24 ) ;
if ( error )
goto V_25;
error = - V_26 ;
if ( F_11 ( V_19 ) )
goto V_25;
error = F_12 ( V_19 ) ;
if ( error )
goto V_25;
error = F_13 ( V_19 , V_27 ) ;
if ( error )
goto V_28;
error = F_14 ( V_19 , NULL , V_2 ) ;
if ( ! error )
error = F_15 ( V_18 ) ;
if ( ! error )
error = F_1 ( V_18 -> V_1 , V_2 , 0 , NULL ) ;
V_28:
F_16 ( V_19 ) ;
V_25:
F_17 ( V_18 -> V_22 ) ;
V_23:
return error ;
}
static long F_18 ( const char T_2 * V_29 , T_1 V_2 )
{
unsigned int V_30 = V_31 ;
struct V_18 V_18 ;
int error ;
if ( V_2 < 0 )
return - V_9 ;
V_32:
error = F_19 ( V_33 , V_29 , V_30 , & V_18 ) ;
if ( ! error ) {
error = F_6 ( & V_18 , V_2 ) ;
F_20 ( & V_18 ) ;
}
if ( F_21 ( error , V_30 ) ) {
V_30 |= V_34 ;
goto V_32;
}
return error ;
}
static long F_22 ( unsigned int V_35 , T_1 V_2 , int V_36 )
{
struct V_19 * V_19 ;
struct V_1 * V_1 ;
struct V_35 V_37 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_23;
error = - V_38 ;
V_37 = F_23 ( V_35 ) ;
if ( ! V_37 . V_4 )
goto V_23;
if ( V_37 . V_4 -> V_39 & V_40 )
V_36 = 0 ;
V_1 = V_37 . V_4 -> V_41 . V_1 ;
V_19 = V_1 -> V_16 ;
error = - V_9 ;
if ( ! F_8 ( V_19 -> V_20 ) || ! ( V_37 . V_4 -> V_42 & V_43 ) )
goto V_44;
error = - V_9 ;
if ( V_36 && V_2 > V_45 )
goto V_44;
error = - V_26 ;
if ( F_11 ( V_19 ) )
goto V_44;
F_24 ( V_19 -> V_46 ) ;
error = F_14 ( V_19 , V_37 . V_4 , V_2 ) ;
if ( ! error )
error = F_15 ( & V_37 . V_4 -> V_41 ) ;
if ( ! error )
error = F_1 ( V_1 , V_2 , V_47 | V_48 , V_37 . V_4 ) ;
F_25 ( V_19 -> V_46 ) ;
V_44:
F_26 ( V_37 ) ;
V_23:
return error ;
}
int F_27 ( struct V_4 * V_4 , int V_49 , T_1 V_50 , T_1 V_51 )
{
struct V_19 * V_19 = F_28 ( V_4 ) ;
long V_6 ;
if ( V_50 < 0 || V_51 <= 0 )
return - V_9 ;
if ( V_49 & ~ V_52 )
return - V_53 ;
if ( ( V_49 & ( V_54 | V_55 ) ) ==
( V_54 | V_55 ) )
return - V_53 ;
if ( ( V_49 & V_54 ) &&
! ( V_49 & V_56 ) )
return - V_53 ;
if ( ( V_49 & V_57 ) &&
( V_49 & ~ V_57 ) )
return - V_9 ;
if ( ( V_49 & V_58 ) &&
( V_49 & ~ V_58 ) )
return - V_9 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return - V_38 ;
if ( ( V_49 & ~ V_56 ) && F_11 ( V_19 ) )
return - V_26 ;
if ( F_29 ( V_19 ) )
return - V_26 ;
if ( F_30 ( V_19 ) )
return - V_59 ;
V_6 = F_31 ( V_4 , V_24 ) ;
if ( V_6 )
return V_6 ;
if ( F_32 ( V_19 -> V_20 ) )
return - V_60 ;
if ( ! F_8 ( V_19 -> V_20 ) && ! F_7 ( V_19 -> V_20 ) )
return - V_61 ;
if ( ( ( V_50 + V_51 ) > V_19 -> V_46 -> V_62 ) || ( ( V_50 + V_51 ) < 0 ) )
return - V_63 ;
if ( ! V_4 -> V_64 -> V_65 )
return - V_53 ;
F_24 ( V_19 -> V_46 ) ;
V_6 = V_4 -> V_64 -> V_65 ( V_4 , V_49 , V_50 , V_51 ) ;
if ( V_6 == 0 )
F_33 ( V_4 ) ;
F_25 ( V_19 -> V_46 ) ;
return V_6 ;
}
static int F_34 ( struct V_18 * V_18 , T_3 V_49 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_66 = NULL ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
return error ;
V_67:
F_3 ( & V_19 -> V_17 ) ;
error = F_35 ( V_18 , V_49 ) ;
if ( error )
goto V_68;
V_8 . V_69 = ( V_49 & V_70 ) | ( V_19 -> V_20 & ~ V_70 ) ;
V_8 . V_11 = V_71 | V_48 ;
error = F_4 ( V_18 -> V_1 , & V_8 , & V_66 ) ;
V_68:
F_5 ( & V_19 -> V_17 ) ;
if ( V_66 ) {
error = F_36 ( & V_66 ) ;
if ( ! error )
goto V_67;
}
F_17 ( V_18 -> V_22 ) ;
return error ;
}
static int F_37 ( struct V_18 * V_18 , T_4 V_72 , T_5 V_73 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_66 = NULL ;
int error ;
struct V_7 V_8 ;
T_6 V_74 ;
T_7 V_75 ;
V_74 = F_38 ( F_39 () , V_72 ) ;
V_75 = F_40 ( F_39 () , V_73 ) ;
V_67:
V_8 . V_11 = V_48 ;
if ( V_72 != ( T_4 ) - 1 ) {
if ( ! F_41 ( V_74 ) )
return - V_9 ;
V_8 . V_11 |= V_76 ;
V_8 . V_77 = V_74 ;
}
if ( V_73 != ( T_5 ) - 1 ) {
if ( ! F_42 ( V_75 ) )
return - V_9 ;
V_8 . V_11 |= V_78 ;
V_8 . V_79 = V_75 ;
}
if ( ! F_7 ( V_19 -> V_20 ) )
V_8 . V_11 |=
V_80 | V_81 | V_82 ;
F_3 ( & V_19 -> V_17 ) ;
error = F_43 ( V_18 , V_74 , V_75 ) ;
if ( ! error )
error = F_4 ( V_18 -> V_1 , & V_8 , & V_66 ) ;
F_5 ( & V_19 -> V_17 ) ;
if ( V_66 ) {
error = F_36 ( & V_66 ) ;
if ( ! error )
goto V_67;
}
return error ;
}
int F_44 ( struct V_4 * V_37 )
{
if ( V_37 -> V_39 & V_83 ) {
if ( ! V_37 -> V_84 -> V_85 || ! V_37 -> V_84 -> V_85 -> V_86 )
return - V_9 ;
}
return 0 ;
}
static int F_45 ( struct V_4 * V_37 ,
struct V_19 * V_19 ,
int (* F_46)( struct V_19 * , struct V_4 * ) ,
const struct V_87 * V_87 )
{
static const struct V_88 V_89 = {} ;
int error ;
V_37 -> V_42 = F_47 ( V_37 -> V_39 ) | V_90 |
V_91 | V_92 ;
F_48 ( & V_37 -> V_41 ) ;
V_37 -> V_93 = V_19 ;
V_37 -> V_84 = V_19 -> V_94 ;
if ( F_49 ( V_37 -> V_39 & V_95 ) ) {
V_37 -> V_42 = V_96 ;
V_37 -> V_64 = & V_89 ;
return 0 ;
}
if ( V_37 -> V_42 & V_43 && ! F_50 ( V_19 -> V_20 ) ) {
error = F_12 ( V_19 ) ;
if ( F_49 ( error ) )
goto V_97;
error = F_51 ( V_37 -> V_41 . V_22 ) ;
if ( F_49 ( error ) ) {
F_16 ( V_19 ) ;
goto V_97;
}
V_37 -> V_42 |= V_98 ;
}
if ( F_8 ( V_19 -> V_20 ) )
V_37 -> V_42 |= V_99 ;
V_37 -> V_64 = F_52 ( V_19 -> V_100 ) ;
if ( F_49 ( F_53 ( ! V_37 -> V_64 ) ) ) {
error = - V_61 ;
goto V_101;
}
error = F_54 ( V_37 , V_87 ) ;
if ( error )
goto V_101;
error = F_13 ( V_19 , V_37 -> V_39 ) ;
if ( error )
goto V_101;
if ( ! F_46 )
F_46 = V_37 -> V_64 -> F_46 ;
if ( F_46 ) {
error = F_46 ( V_19 , V_37 ) ;
if ( error )
goto V_101;
}
if ( ( V_37 -> V_42 & ( V_102 | V_43 ) ) == V_102 )
F_55 ( V_19 ) ;
if ( ( V_37 -> V_42 & V_102 ) &&
F_56 ( V_37 -> V_64 -> V_103 || V_37 -> V_64 -> V_104 ) )
V_37 -> V_42 |= V_105 ;
if ( ( V_37 -> V_42 & V_43 ) &&
F_56 ( V_37 -> V_64 -> V_106 || V_37 -> V_64 -> V_107 ) )
V_37 -> V_42 |= V_108 ;
V_37 -> V_39 &= ~ ( V_109 | V_110 | V_111 | V_112 ) ;
F_57 ( & V_37 -> V_113 , V_37 -> V_84 -> V_114 -> V_94 ) ;
return 0 ;
V_101:
F_58 ( V_37 -> V_64 ) ;
if ( V_37 -> V_42 & V_98 ) {
F_16 ( V_19 ) ;
F_59 ( V_37 -> V_41 . V_22 ) ;
}
V_97:
F_20 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
V_37 -> V_93 = NULL ;
return error ;
}
int F_60 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_46)( struct V_19 * , struct V_4 * ) ,
int * V_115 )
{
int error ;
F_61 ( * V_115 & V_116 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_45 ( V_4 , F_62 ( V_1 ) , F_46 ,
F_63 () ) ;
if ( ! error )
* V_115 |= V_116 ;
return error ;
}
int F_64 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
char * F_65 ( struct V_4 * V_5 , char * V_117 , int V_118 )
{
return F_66 ( & V_5 -> V_41 , V_117 , V_118 ) ;
}
int F_67 ( const struct V_18 * V_18 , struct V_4 * V_4 ,
const struct V_87 * V_87 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_19 * V_19 = V_1 -> V_16 ;
V_4 -> V_41 = * V_18 ;
if ( V_1 -> V_119 & V_120 ) {
V_19 = V_1 -> V_121 -> V_122 ( V_1 , V_4 -> V_39 ) ;
if ( F_68 ( V_19 ) )
return F_69 ( V_19 ) ;
}
return F_45 ( V_4 , V_19 , NULL , V_87 ) ;
}
struct V_4 * F_70 ( const struct V_18 * V_18 , int V_123 ,
const struct V_87 * V_87 )
{
int error ;
struct V_4 * V_37 ;
F_71 ( V_87 ) ;
F_61 ( ! V_18 -> V_22 ) ;
V_37 = F_72 () ;
if ( ! F_68 ( V_37 ) ) {
V_37 -> V_39 = V_123 ;
error = F_67 ( V_18 , V_37 , V_87 ) ;
if ( ! error ) {
error = F_44 ( V_37 ) ;
if ( error ) {
F_73 ( V_37 ) ;
V_37 = F_74 ( error ) ;
}
} else {
F_75 ( V_37 ) ;
V_37 = F_74 ( error ) ;
}
}
return V_37 ;
}
static inline int F_76 ( int V_123 , T_3 V_49 , struct V_124 * V_125 )
{
int V_30 = 0 ;
int V_126 ;
if ( V_123 & ( V_109 | V_127 ) )
V_125 -> V_49 = ( V_49 & V_70 ) | V_128 ;
else
V_125 -> V_49 = 0 ;
V_123 &= ~ V_129 & ~ V_130 ;
if ( V_123 & V_131 )
V_123 |= V_132 ;
if ( V_123 & V_127 ) {
if ( ( V_123 & V_133 ) != V_134 )
return - V_9 ;
V_126 = V_135 | F_77 ( V_123 ) ;
if ( ! ( V_126 & V_24 ) )
return - V_9 ;
} else if ( V_123 & V_95 ) {
V_123 &= V_136 | V_137 | V_95 ;
V_126 = 0 ;
} else {
V_126 = V_135 | F_77 ( V_123 ) ;
}
V_125 -> V_138 = V_123 ;
if ( V_123 & V_112 )
V_126 |= V_24 ;
if ( V_123 & V_139 )
V_126 |= V_140 ;
V_125 -> V_126 = V_126 ;
V_125 -> V_141 = V_123 & V_95 ? 0 : V_142 ;
if ( V_123 & V_109 ) {
V_125 -> V_141 |= V_143 ;
if ( V_123 & V_110 )
V_125 -> V_141 |= V_144 ;
}
if ( V_123 & V_136 )
V_30 |= V_145 ;
if ( ! ( V_123 & V_137 ) )
V_30 |= V_31 ;
V_125 -> V_30 = V_30 ;
return 0 ;
}
struct V_4 * F_78 ( struct V_146 * V_147 , int V_123 , T_3 V_49 )
{
struct V_124 V_125 ;
int V_148 = F_76 ( V_123 , V_49 , & V_125 ) ;
return V_148 ? F_74 ( V_148 ) : F_79 ( V_33 , V_147 , & V_125 ) ;
}
struct V_4 * F_80 ( const char * V_146 , int V_123 , T_3 V_49 )
{
struct V_146 * V_147 = F_81 ( V_146 ) ;
struct V_4 * V_4 = F_82 ( V_147 ) ;
if ( ! F_68 ( V_147 ) ) {
V_4 = F_78 ( V_147 , V_123 , V_49 ) ;
F_83 ( V_147 ) ;
}
return V_4 ;
}
struct V_4 * F_84 ( struct V_1 * V_1 , struct V_149 * V_22 ,
const char * V_146 , int V_123 )
{
struct V_124 V_125 ;
int V_148 = F_76 ( V_123 , 0 , & V_125 ) ;
if ( V_148 )
return F_74 ( V_148 ) ;
if ( V_123 & V_109 )
return F_74 ( - V_9 ) ;
return F_85 ( V_1 , V_22 , V_146 , & V_125 ) ;
}
long F_86 ( int V_150 , const char T_2 * V_146 , int V_123 , T_3 V_49 )
{
struct V_124 V_125 ;
int V_35 = F_76 ( V_123 , V_49 , & V_125 ) ;
struct V_146 * V_151 ;
if ( V_35 )
return V_35 ;
V_151 = F_87 ( V_146 ) ;
if ( F_68 ( V_151 ) )
return F_69 ( V_151 ) ;
V_35 = F_88 ( V_123 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_79 ( V_150 , V_151 , & V_125 ) ;
if ( F_68 ( V_37 ) ) {
F_89 ( V_35 ) ;
V_35 = F_69 ( V_37 ) ;
} else {
F_90 ( V_37 ) ;
F_91 ( V_35 , V_37 ) ;
}
}
F_83 ( V_151 ) ;
return V_35 ;
}
int F_92 ( struct V_4 * V_5 , T_8 V_152 )
{
int V_153 = 0 ;
if ( ! F_93 ( V_5 ) ) {
F_94 ( V_154 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_64 -> V_155 )
V_153 = V_5 -> V_64 -> V_155 ( V_5 , V_152 ) ;
if ( F_56 ( ! ( V_5 -> V_42 & V_96 ) ) ) {
F_95 ( V_5 , V_152 ) ;
F_96 ( V_5 , V_152 ) ;
}
F_73 ( V_5 ) ;
return V_153 ;
}
int F_97 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_98 ( V_19 ) > V_45 )
return - V_156 ;
return 0 ;
}
int F_99 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_90 | V_91 | V_92 ) ;
return 0 ;
}
