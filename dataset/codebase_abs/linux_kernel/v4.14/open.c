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
F_3 ( V_1 -> V_16 ) ;
V_6 = F_4 ( V_1 , & V_8 , NULL ) ;
F_5 ( V_1 -> V_16 ) ;
return V_6 ;
}
long F_6 ( const struct V_17 * V_17 , T_1 V_2 )
{
struct V_18 * V_18 ;
struct V_1 * V_19 ;
long error ;
V_18 = V_17 -> V_1 -> V_16 ;
if ( F_7 ( V_18 -> V_20 ) )
return - V_21 ;
if ( ! F_8 ( V_18 -> V_20 ) )
return - V_9 ;
error = F_9 ( V_17 -> V_22 ) ;
if ( error )
goto V_23;
error = F_10 ( V_18 , V_24 ) ;
if ( error )
goto V_25;
error = - V_26 ;
if ( F_11 ( V_18 ) )
goto V_25;
V_19 = F_12 ( V_17 -> V_1 , NULL , V_27 , 0 ) ;
error = F_13 ( V_19 ) ;
if ( F_14 ( V_19 ) )
goto V_25;
error = F_15 ( V_19 -> V_16 ) ;
if ( error )
goto V_25;
error = F_16 ( V_18 , V_27 ) ;
if ( error )
goto V_28;
error = F_17 ( V_18 , NULL , V_2 ) ;
if ( ! error )
error = F_18 ( V_17 ) ;
if ( ! error )
error = F_1 ( V_17 -> V_1 , V_2 , 0 , NULL ) ;
V_28:
F_19 ( V_19 -> V_16 ) ;
V_25:
F_20 ( V_17 -> V_22 ) ;
V_23:
return error ;
}
static long F_21 ( const char T_2 * V_29 , T_1 V_2 )
{
unsigned int V_30 = V_31 ;
struct V_17 V_17 ;
int error ;
if ( V_2 < 0 )
return - V_9 ;
V_32:
error = F_22 ( V_33 , V_29 , V_30 , & V_17 ) ;
if ( ! error ) {
error = F_6 ( & V_17 , V_2 ) ;
F_23 ( & V_17 ) ;
}
if ( F_24 ( error , V_30 ) ) {
V_30 |= V_34 ;
goto V_32;
}
return error ;
}
static long F_25 ( unsigned int V_35 , T_1 V_2 , int V_36 )
{
struct V_18 * V_18 ;
struct V_1 * V_1 ;
struct V_35 V_37 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_23;
error = - V_38 ;
V_37 = F_26 ( V_35 ) ;
if ( ! V_37 . V_4 )
goto V_23;
if ( V_37 . V_4 -> V_39 & V_40 )
V_36 = 0 ;
V_1 = V_37 . V_4 -> V_41 . V_1 ;
V_18 = V_1 -> V_16 ;
error = - V_9 ;
if ( ! F_8 ( V_18 -> V_20 ) || ! ( V_37 . V_4 -> V_42 & V_43 ) )
goto V_44;
error = - V_9 ;
if ( V_36 && V_2 > V_45 )
goto V_44;
error = - V_26 ;
if ( F_11 ( F_27 ( V_37 . V_4 ) ) )
goto V_44;
F_28 ( V_18 -> V_46 ) ;
error = F_17 ( V_18 , V_37 . V_4 , V_2 ) ;
if ( ! error )
error = F_18 ( & V_37 . V_4 -> V_41 ) ;
if ( ! error )
error = F_1 ( V_1 , V_2 , V_47 | V_48 , V_37 . V_4 ) ;
F_29 ( V_18 -> V_46 ) ;
V_44:
F_30 ( V_37 ) ;
V_23:
return error ;
}
int F_31 ( struct V_4 * V_4 , int V_49 , T_1 V_50 , T_1 V_51 )
{
struct V_18 * V_18 = F_27 ( V_4 ) ;
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
if ( ( V_49 & V_59 ) &&
( V_49 & ~ ( V_59 | V_56 ) ) )
return - V_9 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return - V_38 ;
if ( ( V_49 & ~ V_56 ) && F_11 ( V_18 ) )
return - V_26 ;
if ( F_32 ( V_18 ) )
return - V_26 ;
if ( F_33 ( V_18 ) )
return - V_60 ;
V_6 = F_34 ( V_4 , V_24 ) ;
if ( V_6 )
return V_6 ;
if ( F_35 ( V_18 -> V_20 ) )
return - V_61 ;
if ( F_7 ( V_18 -> V_20 ) )
return - V_21 ;
if ( ! F_8 ( V_18 -> V_20 ) && ! F_36 ( V_18 -> V_20 ) )
return - V_62 ;
if ( ( ( V_50 + V_51 ) > V_18 -> V_46 -> V_63 ) || ( ( V_50 + V_51 ) < 0 ) )
return - V_64 ;
if ( ! V_4 -> V_65 -> V_66 )
return - V_53 ;
F_37 ( V_4 ) ;
V_6 = V_4 -> V_65 -> V_66 ( V_4 , V_49 , V_50 , V_51 ) ;
if ( V_6 == 0 )
F_38 ( V_4 ) ;
F_39 ( V_4 ) ;
return V_6 ;
}
static int F_40 ( const struct V_17 * V_17 , T_3 V_49 )
{
struct V_18 * V_18 = V_17 -> V_1 -> V_16 ;
struct V_18 * V_67 = NULL ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_17 -> V_22 ) ;
if ( error )
return error ;
V_68:
F_3 ( V_18 ) ;
error = F_41 ( V_17 , V_49 ) ;
if ( error )
goto V_69;
V_8 . V_70 = ( V_49 & V_71 ) | ( V_18 -> V_20 & ~ V_71 ) ;
V_8 . V_11 = V_72 | V_48 ;
error = F_4 ( V_17 -> V_1 , & V_8 , & V_67 ) ;
V_69:
F_5 ( V_18 ) ;
if ( V_67 ) {
error = F_42 ( & V_67 ) ;
if ( ! error )
goto V_68;
}
F_20 ( V_17 -> V_22 ) ;
return error ;
}
static int F_43 ( const struct V_17 * V_17 , T_4 V_73 , T_5 V_74 )
{
struct V_18 * V_18 = V_17 -> V_1 -> V_16 ;
struct V_18 * V_67 = NULL ;
int error ;
struct V_7 V_8 ;
T_6 V_75 ;
T_7 V_76 ;
V_75 = F_44 ( F_45 () , V_73 ) ;
V_76 = F_46 ( F_45 () , V_74 ) ;
V_68:
V_8 . V_11 = V_48 ;
if ( V_73 != ( T_4 ) - 1 ) {
if ( ! F_47 ( V_75 ) )
return - V_9 ;
V_8 . V_11 |= V_77 ;
V_8 . V_78 = V_75 ;
}
if ( V_74 != ( T_5 ) - 1 ) {
if ( ! F_48 ( V_76 ) )
return - V_9 ;
V_8 . V_11 |= V_79 ;
V_8 . V_80 = V_76 ;
}
if ( ! F_7 ( V_18 -> V_20 ) )
V_8 . V_11 |=
V_81 | V_82 | V_83 ;
F_3 ( V_18 ) ;
error = F_49 ( V_17 , V_75 , V_76 ) ;
if ( ! error )
error = F_4 ( V_17 -> V_1 , & V_8 , & V_67 ) ;
F_5 ( V_18 ) ;
if ( V_67 ) {
error = F_42 ( & V_67 ) ;
if ( ! error )
goto V_68;
}
return error ;
}
int F_50 ( struct V_4 * V_37 )
{
if ( V_37 -> V_39 & V_84 ) {
if ( ! V_37 -> V_85 -> V_86 || ! V_37 -> V_85 -> V_86 -> V_87 )
return - V_9 ;
}
return 0 ;
}
static int F_51 ( struct V_4 * V_37 ,
struct V_18 * V_18 ,
int (* F_52)( struct V_18 * , struct V_4 * ) ,
const struct V_88 * V_88 )
{
static const struct V_89 V_90 = {} ;
int error ;
V_37 -> V_42 = F_53 ( V_37 -> V_39 ) | V_91 |
V_92 | V_93 ;
F_54 ( & V_37 -> V_41 ) ;
V_37 -> V_94 = V_18 ;
V_37 -> V_85 = V_18 -> V_95 ;
V_37 -> V_96 = F_55 ( V_37 -> V_85 ) ;
if ( F_56 ( V_37 -> V_39 & V_97 ) ) {
V_37 -> V_42 = V_98 ;
V_37 -> V_65 = & V_90 ;
return 0 ;
}
if ( V_37 -> V_42 & V_43 && ! F_57 ( V_18 -> V_20 ) ) {
error = F_15 ( V_18 ) ;
if ( F_56 ( error ) )
goto V_99;
error = F_58 ( V_37 -> V_41 . V_22 ) ;
if ( F_56 ( error ) ) {
F_19 ( V_18 ) ;
goto V_99;
}
V_37 -> V_42 |= V_100 ;
}
if ( F_8 ( V_18 -> V_20 ) || F_7 ( V_18 -> V_20 ) )
V_37 -> V_42 |= V_101 ;
V_37 -> V_65 = F_59 ( V_18 -> V_102 ) ;
if ( F_56 ( F_60 ( ! V_37 -> V_65 ) ) ) {
error = - V_62 ;
goto V_103;
}
error = F_61 ( V_37 , V_88 ) ;
if ( error )
goto V_103;
error = F_16 ( F_62 ( V_37 ) , V_37 -> V_39 ) ;
if ( error )
goto V_103;
if ( ! F_52 )
F_52 = V_37 -> V_65 -> F_52 ;
if ( F_52 ) {
error = F_52 ( V_18 , V_37 ) ;
if ( error )
goto V_103;
}
if ( ( V_37 -> V_42 & ( V_104 | V_43 ) ) == V_104 )
F_63 ( V_18 ) ;
if ( ( V_37 -> V_42 & V_104 ) &&
F_64 ( V_37 -> V_65 -> V_105 || V_37 -> V_65 -> V_106 ) )
V_37 -> V_42 |= V_107 ;
if ( ( V_37 -> V_42 & V_43 ) &&
F_64 ( V_37 -> V_65 -> V_108 || V_37 -> V_65 -> V_109 ) )
V_37 -> V_42 |= V_110 ;
V_37 -> V_111 = V_112 ;
V_37 -> V_39 &= ~ ( V_113 | V_114 | V_115 | V_116 ) ;
F_65 ( & V_37 -> V_117 , V_37 -> V_85 -> V_118 -> V_95 ) ;
return 0 ;
V_103:
F_66 ( V_37 -> V_65 ) ;
if ( V_37 -> V_42 & V_100 ) {
F_19 ( V_18 ) ;
F_67 ( V_37 -> V_41 . V_22 ) ;
}
V_99:
F_23 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
V_37 -> V_94 = NULL ;
return error ;
}
int F_68 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_52)( struct V_18 * , struct V_4 * ) ,
int * V_119 )
{
int error ;
F_69 ( * V_119 & V_120 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_51 ( V_4 , F_70 ( V_1 ) , F_52 ,
F_71 () ) ;
if ( ! error )
* V_119 |= V_120 ;
return error ;
}
int F_72 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
char * F_73 ( struct V_4 * V_5 , char * V_121 , int V_122 )
{
return F_74 ( & V_5 -> V_41 , V_121 , V_122 ) ;
}
int F_75 ( const struct V_17 * V_17 , struct V_4 * V_4 ,
const struct V_88 * V_88 )
{
struct V_1 * V_1 = F_12 ( V_17 -> V_1 , NULL , V_4 -> V_39 , 0 ) ;
if ( F_14 ( V_1 ) )
return F_13 ( V_1 ) ;
V_4 -> V_41 = * V_17 ;
return F_51 ( V_4 , F_70 ( V_1 ) , NULL , V_88 ) ;
}
struct V_4 * F_76 ( const struct V_17 * V_17 , int V_123 ,
const struct V_88 * V_88 )
{
int error ;
struct V_4 * V_37 ;
F_77 ( V_88 ) ;
F_69 ( ! V_17 -> V_22 ) ;
V_37 = F_78 () ;
if ( ! F_14 ( V_37 ) ) {
V_37 -> V_39 = V_123 ;
error = F_75 ( V_17 , V_37 , V_88 ) ;
if ( ! error ) {
error = F_50 ( V_37 ) ;
if ( error ) {
F_79 ( V_37 ) ;
V_37 = F_80 ( error ) ;
}
} else {
F_81 ( V_37 ) ;
V_37 = F_80 ( error ) ;
}
}
return V_37 ;
}
static inline int F_82 ( int V_123 , T_3 V_49 , struct V_124 * V_125 )
{
int V_30 = 0 ;
int V_126 = F_83 ( V_123 ) ;
V_123 &= V_127 ;
if ( V_123 & ( V_113 | V_128 ) )
V_125 -> V_49 = ( V_49 & V_71 ) | V_129 ;
else
V_125 -> V_49 = 0 ;
V_123 &= ~ V_130 & ~ V_131 ;
if ( V_123 & V_132 )
V_123 |= V_133 ;
if ( V_123 & V_128 ) {
if ( ( V_123 & V_134 ) != V_135 )
return - V_9 ;
if ( ! ( V_126 & V_24 ) )
return - V_9 ;
} else if ( V_123 & V_97 ) {
V_123 &= V_136 | V_137 | V_97 ;
V_126 = 0 ;
}
V_125 -> V_138 = V_123 ;
if ( V_123 & V_116 )
V_126 |= V_24 ;
if ( V_123 & V_139 )
V_126 |= V_140 ;
V_125 -> V_126 = V_126 ;
V_125 -> V_141 = V_123 & V_97 ? 0 : V_142 ;
if ( V_123 & V_113 ) {
V_125 -> V_141 |= V_143 ;
if ( V_123 & V_114 )
V_125 -> V_141 |= V_144 ;
}
if ( V_123 & V_136 )
V_30 |= V_145 ;
if ( ! ( V_123 & V_137 ) )
V_30 |= V_31 ;
V_125 -> V_30 = V_30 ;
return 0 ;
}
struct V_4 * F_84 ( struct V_146 * V_147 , int V_123 , T_3 V_49 )
{
struct V_124 V_125 ;
int V_148 = F_82 ( V_123 , V_49 , & V_125 ) ;
return V_148 ? F_80 ( V_148 ) : F_85 ( V_33 , V_147 , & V_125 ) ;
}
struct V_4 * F_86 ( const char * V_146 , int V_123 , T_3 V_49 )
{
struct V_146 * V_147 = F_87 ( V_146 ) ;
struct V_4 * V_4 = F_88 ( V_147 ) ;
if ( ! F_14 ( V_147 ) ) {
V_4 = F_84 ( V_147 , V_123 , V_49 ) ;
F_89 ( V_147 ) ;
}
return V_4 ;
}
struct V_4 * F_90 ( struct V_1 * V_1 , struct V_149 * V_22 ,
const char * V_146 , int V_123 , T_3 V_49 )
{
struct V_124 V_125 ;
int V_148 = F_82 ( V_123 , V_49 , & V_125 ) ;
if ( V_148 )
return F_80 ( V_148 ) ;
return F_91 ( V_1 , V_22 , V_146 , & V_125 ) ;
}
struct V_4 * F_92 ( struct V_4 * V_150 )
{
struct V_4 * V_4 ;
int V_151 ;
V_4 = F_78 () ;
if ( F_14 ( V_4 ) )
return V_4 ;
V_4 -> V_39 = V_150 -> V_39 ;
V_151 = F_75 ( & V_150 -> V_41 , V_4 , V_150 -> V_152 ) ;
if ( V_151 ) {
F_81 ( V_4 ) ;
return F_80 ( V_151 ) ;
}
return V_4 ;
}
long F_93 ( int V_153 , const char T_2 * V_146 , int V_123 , T_3 V_49 )
{
struct V_124 V_125 ;
int V_35 = F_82 ( V_123 , V_49 , & V_125 ) ;
struct V_146 * V_154 ;
if ( V_35 )
return V_35 ;
V_154 = F_94 ( V_146 ) ;
if ( F_14 ( V_154 ) )
return F_13 ( V_154 ) ;
V_35 = F_95 ( V_123 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_85 ( V_153 , V_154 , & V_125 ) ;
if ( F_14 ( V_37 ) ) {
F_96 ( V_35 ) ;
V_35 = F_13 ( V_37 ) ;
} else {
F_97 ( V_37 ) ;
F_98 ( V_35 , V_37 ) ;
}
}
F_89 ( V_154 ) ;
return V_35 ;
}
int F_99 ( struct V_4 * V_5 , T_8 V_155 )
{
int V_151 = 0 ;
if ( ! F_100 ( V_5 ) ) {
F_101 ( V_156 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_65 -> V_157 )
V_151 = V_5 -> V_65 -> V_157 ( V_5 , V_155 ) ;
if ( F_64 ( ! ( V_5 -> V_42 & V_98 ) ) ) {
F_102 ( V_5 , V_155 ) ;
F_103 ( V_5 , V_155 ) ;
}
F_79 ( V_5 ) ;
return V_151 ;
}
int F_104 ( struct V_18 * V_18 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_105 ( V_18 ) > V_45 )
return - V_158 ;
return 0 ;
}
int F_106 ( struct V_18 * V_18 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_91 | V_92 | V_93 ) ;
return 0 ;
}
