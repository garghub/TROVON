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
if ( V_49 & ~ ( V_52 | V_53 |
V_54 | V_55 ) )
return - V_56 ;
if ( ( V_49 & ( V_53 | V_55 ) ) ==
( V_53 | V_55 ) )
return - V_56 ;
if ( ( V_49 & V_53 ) &&
! ( V_49 & V_52 ) )
return - V_56 ;
if ( ( V_49 & V_54 ) &&
( V_49 & ~ V_54 ) )
return - V_9 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return - V_38 ;
if ( ( V_49 & ~ V_52 ) && F_11 ( V_19 ) )
return - V_26 ;
if ( F_29 ( V_19 ) )
return - V_26 ;
if ( F_30 ( V_19 ) )
return - V_57 ;
V_6 = F_31 ( V_4 , V_24 ) ;
if ( V_6 )
return V_6 ;
if ( F_32 ( V_19 -> V_20 ) )
return - V_58 ;
if ( ! F_8 ( V_19 -> V_20 ) && ! F_7 ( V_19 -> V_20 ) )
return - V_59 ;
if ( ( ( V_50 + V_51 ) > V_19 -> V_46 -> V_60 ) || ( ( V_50 + V_51 ) < 0 ) )
return - V_61 ;
if ( ! V_4 -> V_62 -> V_63 )
return - V_56 ;
F_24 ( V_19 -> V_46 ) ;
V_6 = V_4 -> V_62 -> V_63 ( V_4 , V_49 , V_50 , V_51 ) ;
F_25 ( V_19 -> V_46 ) ;
return V_6 ;
}
static int F_33 ( struct V_18 * V_18 , T_3 V_49 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_64 = NULL ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
return error ;
V_65:
F_3 ( & V_19 -> V_17 ) ;
error = F_34 ( V_18 , V_49 ) ;
if ( error )
goto V_66;
V_8 . V_67 = ( V_49 & V_68 ) | ( V_19 -> V_20 & ~ V_68 ) ;
V_8 . V_11 = V_69 | V_48 ;
error = F_4 ( V_18 -> V_1 , & V_8 , & V_64 ) ;
V_66:
F_5 ( & V_19 -> V_17 ) ;
if ( V_64 ) {
error = F_35 ( & V_64 ) ;
if ( ! error )
goto V_65;
}
F_17 ( V_18 -> V_22 ) ;
return error ;
}
static int F_36 ( struct V_18 * V_18 , T_4 V_70 , T_5 V_71 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_64 = NULL ;
int error ;
struct V_7 V_8 ;
T_6 V_72 ;
T_7 V_73 ;
V_72 = F_37 ( F_38 () , V_70 ) ;
V_73 = F_39 ( F_38 () , V_71 ) ;
V_8 . V_11 = V_48 ;
if ( V_70 != ( T_4 ) - 1 ) {
if ( ! F_40 ( V_72 ) )
return - V_9 ;
V_8 . V_11 |= V_74 ;
V_8 . V_75 = V_72 ;
}
if ( V_71 != ( T_5 ) - 1 ) {
if ( ! F_41 ( V_73 ) )
return - V_9 ;
V_8 . V_11 |= V_76 ;
V_8 . V_77 = V_73 ;
}
if ( ! F_7 ( V_19 -> V_20 ) )
V_8 . V_11 |=
V_78 | V_79 | V_80 ;
V_65:
F_3 ( & V_19 -> V_17 ) ;
error = F_42 ( V_18 , V_72 , V_73 ) ;
if ( ! error )
error = F_4 ( V_18 -> V_1 , & V_8 , & V_64 ) ;
F_5 ( & V_19 -> V_17 ) ;
if ( V_64 ) {
error = F_35 ( & V_64 ) ;
if ( ! error )
goto V_65;
}
return error ;
}
int F_43 ( struct V_4 * V_37 )
{
if ( V_37 -> V_39 & V_81 ) {
if ( ! V_37 -> V_82 -> V_83 ||
( ( ! V_37 -> V_82 -> V_83 -> V_84 ) &&
( ! V_37 -> V_82 -> V_83 -> V_85 ) ) ) {
return - V_9 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_37 ,
int (* F_45)( struct V_19 * , struct V_4 * ) ,
const struct V_86 * V_86 )
{
static const struct V_87 V_88 = {} ;
struct V_19 * V_19 ;
int error ;
V_37 -> V_42 = F_46 ( V_37 -> V_39 ) | V_89 |
V_90 | V_91 ;
F_47 ( & V_37 -> V_41 ) ;
V_19 = V_37 -> V_92 = V_37 -> V_41 . V_1 -> V_16 ;
V_37 -> V_82 = V_19 -> V_93 ;
if ( F_48 ( V_37 -> V_39 & V_94 ) ) {
V_37 -> V_42 = V_95 ;
V_37 -> V_62 = & V_88 ;
return 0 ;
}
if ( V_37 -> V_42 & V_43 && ! F_49 ( V_19 -> V_20 ) ) {
error = F_12 ( V_19 ) ;
if ( F_48 ( error ) )
goto V_96;
error = F_50 ( V_37 -> V_41 . V_22 ) ;
if ( F_48 ( error ) ) {
F_16 ( V_19 ) ;
goto V_96;
}
V_37 -> V_42 |= V_97 ;
}
if ( F_8 ( V_19 -> V_20 ) )
V_37 -> V_42 |= V_98 ;
V_37 -> V_62 = F_51 ( V_19 -> V_99 ) ;
if ( F_48 ( F_52 ( ! V_37 -> V_62 ) ) ) {
error = - V_59 ;
goto V_100;
}
error = F_53 ( V_37 , V_86 ) ;
if ( error )
goto V_100;
error = F_13 ( V_19 , V_37 -> V_39 ) ;
if ( error )
goto V_100;
if ( ! F_45 )
F_45 = V_37 -> V_62 -> F_45 ;
if ( F_45 ) {
error = F_45 ( V_19 , V_37 ) ;
if ( error )
goto V_100;
}
if ( ( V_37 -> V_42 & ( V_101 | V_43 ) ) == V_101 )
F_54 ( V_19 ) ;
if ( ( V_37 -> V_42 & V_101 ) &&
F_55 ( V_37 -> V_62 -> V_102 || V_37 -> V_62 -> V_103 || V_37 -> V_62 -> V_104 ) )
V_37 -> V_42 |= V_105 ;
if ( ( V_37 -> V_42 & V_43 ) &&
F_55 ( V_37 -> V_62 -> V_106 || V_37 -> V_62 -> V_107 || V_37 -> V_62 -> V_108 ) )
V_37 -> V_42 |= V_109 ;
V_37 -> V_39 &= ~ ( V_110 | V_111 | V_112 | V_113 ) ;
F_56 ( & V_37 -> V_114 , V_37 -> V_82 -> V_115 -> V_93 ) ;
return 0 ;
V_100:
F_57 ( V_37 -> V_62 ) ;
if ( V_37 -> V_42 & V_97 ) {
F_16 ( V_19 ) ;
F_58 ( V_37 -> V_41 . V_22 ) ;
}
V_96:
F_20 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
V_37 -> V_92 = NULL ;
return error ;
}
int F_59 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_45)( struct V_19 * , struct V_4 * ) ,
int * V_116 )
{
int error ;
F_60 ( * V_116 & V_117 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_44 ( V_4 , F_45 , F_61 () ) ;
if ( ! error )
* V_116 |= V_117 ;
return error ;
}
int F_62 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
struct V_4 * F_63 ( const struct V_18 * V_18 , int V_118 ,
const struct V_86 * V_86 )
{
int error ;
struct V_4 * V_37 ;
F_64 ( V_86 ) ;
F_60 ( ! V_18 -> V_22 ) ;
V_37 = F_65 () ;
if ( ! F_66 ( V_37 ) ) {
V_37 -> V_39 = V_118 ;
error = F_67 ( V_18 , V_37 , V_86 ) ;
if ( ! error ) {
error = F_43 ( V_37 ) ;
if ( error ) {
F_68 ( V_37 ) ;
V_37 = F_69 ( error ) ;
}
} else {
F_70 ( V_37 ) ;
V_37 = F_69 ( error ) ;
}
}
return V_37 ;
}
int F_67 ( const struct V_18 * V_18 , struct V_4 * V_5 ,
const struct V_86 * V_86 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
if ( V_19 -> V_119 -> F_63 )
return V_19 -> V_119 -> F_63 ( V_18 -> V_1 , V_5 , V_86 ) ;
else {
V_5 -> V_41 = * V_18 ;
return F_44 ( V_5 , NULL , V_86 ) ;
}
}
static inline int F_71 ( int V_118 , T_3 V_49 , struct V_120 * V_121 )
{
int V_30 = 0 ;
int V_122 ;
if ( V_118 & ( V_110 | V_123 ) )
V_121 -> V_49 = ( V_49 & V_68 ) | V_124 ;
else
V_121 -> V_49 = 0 ;
V_118 &= ~ V_125 & ~ V_126 ;
if ( V_118 & V_127 )
V_118 |= V_128 ;
if ( V_118 & V_123 ) {
if ( ( V_118 & V_129 ) != V_130 )
return - V_9 ;
V_122 = V_131 | F_72 ( V_118 ) ;
if ( ! ( V_122 & V_24 ) )
return - V_9 ;
} else if ( V_118 & V_94 ) {
V_118 &= V_132 | V_133 | V_94 ;
V_122 = 0 ;
} else {
V_122 = V_131 | F_72 ( V_118 ) ;
}
V_121 -> V_134 = V_118 ;
if ( V_118 & V_113 )
V_122 |= V_24 ;
if ( V_118 & V_135 )
V_122 |= V_136 ;
V_121 -> V_122 = V_122 ;
V_121 -> V_137 = V_118 & V_94 ? 0 : V_138 ;
if ( V_118 & V_110 ) {
V_121 -> V_137 |= V_139 ;
if ( V_118 & V_111 )
V_121 -> V_137 |= V_140 ;
}
if ( V_118 & V_132 )
V_30 |= V_141 ;
if ( ! ( V_118 & V_133 ) )
V_30 |= V_31 ;
V_121 -> V_30 = V_30 ;
return 0 ;
}
struct V_4 * F_73 ( struct V_142 * V_143 , int V_118 , T_3 V_49 )
{
struct V_120 V_121 ;
int V_144 = F_71 ( V_118 , V_49 , & V_121 ) ;
return V_144 ? F_69 ( V_144 ) : F_74 ( V_33 , V_143 , & V_121 ) ;
}
struct V_4 * F_75 ( const char * V_142 , int V_118 , T_3 V_49 )
{
struct V_142 V_143 = { . V_143 = V_142 } ;
return F_73 ( & V_143 , V_118 , V_49 ) ;
}
struct V_4 * F_76 ( struct V_1 * V_1 , struct V_145 * V_22 ,
const char * V_142 , int V_118 )
{
struct V_120 V_121 ;
int V_144 = F_71 ( V_118 , 0 , & V_121 ) ;
if ( V_144 )
return F_69 ( V_144 ) ;
if ( V_118 & V_110 )
return F_69 ( - V_9 ) ;
if ( ! V_142 && ( V_118 & V_132 ) )
if ( ! V_1 -> V_16 -> V_119 -> V_146 )
return F_69 ( - V_147 ) ;
return F_77 ( V_1 , V_22 , V_142 , & V_121 ) ;
}
long F_78 ( int V_148 , const char T_2 * V_142 , int V_118 , T_3 V_49 )
{
struct V_120 V_121 ;
int V_35 = F_71 ( V_118 , V_49 , & V_121 ) ;
struct V_142 * V_149 ;
if ( V_35 )
return V_35 ;
V_149 = F_79 ( V_142 ) ;
if ( F_66 ( V_149 ) )
return F_80 ( V_149 ) ;
V_35 = F_81 ( V_118 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_74 ( V_148 , V_149 , & V_121 ) ;
if ( F_66 ( V_37 ) ) {
F_82 ( V_35 ) ;
V_35 = F_80 ( V_37 ) ;
} else {
F_83 ( V_37 ) ;
F_84 ( V_35 , V_37 ) ;
}
}
F_85 ( V_149 ) ;
return V_35 ;
}
int F_86 ( struct V_4 * V_5 , T_8 V_150 )
{
int V_151 = 0 ;
if ( ! F_87 ( V_5 ) ) {
F_88 ( V_152 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_62 -> V_153 )
V_151 = V_5 -> V_62 -> V_153 ( V_5 , V_150 ) ;
if ( F_55 ( ! ( V_5 -> V_42 & V_95 ) ) ) {
F_89 ( V_5 , V_150 ) ;
F_90 ( V_5 , V_150 ) ;
}
F_68 ( V_5 ) ;
return V_151 ;
}
int F_91 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_92 ( V_19 ) > V_45 )
return - V_154 ;
return 0 ;
}
int F_93 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_89 | V_90 | V_91 ) ;
return 0 ;
}
