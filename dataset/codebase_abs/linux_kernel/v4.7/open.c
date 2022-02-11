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
long error ;
V_18 = V_17 -> V_1 -> V_16 ;
if ( F_7 ( V_18 -> V_19 ) )
return - V_20 ;
if ( ! F_8 ( V_18 -> V_19 ) )
return - V_9 ;
error = F_9 ( V_17 -> V_21 ) ;
if ( error )
goto V_22;
error = F_10 ( V_18 , V_23 ) ;
if ( error )
goto V_24;
error = - V_25 ;
if ( F_11 ( V_18 ) )
goto V_24;
error = F_12 ( V_18 ) ;
if ( error )
goto V_24;
error = F_13 ( V_18 , V_26 ) ;
if ( error )
goto V_27;
error = F_14 ( V_18 , NULL , V_2 ) ;
if ( ! error )
error = F_15 ( V_17 ) ;
if ( ! error )
error = F_1 ( V_17 -> V_1 , V_2 , 0 , NULL ) ;
V_27:
F_16 ( V_18 ) ;
V_24:
F_17 ( V_17 -> V_21 ) ;
V_22:
return error ;
}
static long F_18 ( const char T_2 * V_28 , T_1 V_2 )
{
unsigned int V_29 = V_30 ;
struct V_17 V_17 ;
int error ;
if ( V_2 < 0 )
return - V_9 ;
V_31:
error = F_19 ( V_32 , V_28 , V_29 , & V_17 ) ;
if ( ! error ) {
error = F_6 ( & V_17 , V_2 ) ;
F_20 ( & V_17 ) ;
}
if ( F_21 ( error , V_29 ) ) {
V_29 |= V_33 ;
goto V_31;
}
return error ;
}
static long F_22 ( unsigned int V_34 , T_1 V_2 , int V_35 )
{
struct V_18 * V_18 ;
struct V_1 * V_1 ;
struct V_34 V_36 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_22;
error = - V_37 ;
V_36 = F_23 ( V_34 ) ;
if ( ! V_36 . V_4 )
goto V_22;
if ( V_36 . V_4 -> V_38 & V_39 )
V_35 = 0 ;
V_1 = V_36 . V_4 -> V_40 . V_1 ;
V_18 = V_1 -> V_16 ;
error = - V_9 ;
if ( ! F_8 ( V_18 -> V_19 ) || ! ( V_36 . V_4 -> V_41 & V_42 ) )
goto V_43;
error = - V_9 ;
if ( V_35 && V_2 > V_44 )
goto V_43;
error = - V_25 ;
if ( F_11 ( V_18 ) )
goto V_43;
F_24 ( V_18 -> V_45 ) ;
error = F_14 ( V_18 , V_36 . V_4 , V_2 ) ;
if ( ! error )
error = F_15 ( & V_36 . V_4 -> V_40 ) ;
if ( ! error )
error = F_1 ( V_1 , V_2 , V_46 | V_47 , V_36 . V_4 ) ;
F_25 ( V_18 -> V_45 ) ;
V_43:
F_26 ( V_36 ) ;
V_22:
return error ;
}
int F_27 ( struct V_4 * V_4 , int V_48 , T_1 V_49 , T_1 V_50 )
{
struct V_18 * V_18 = F_28 ( V_4 ) ;
long V_6 ;
if ( V_49 < 0 || V_50 <= 0 )
return - V_9 ;
if ( V_48 & ~ V_51 )
return - V_52 ;
if ( ( V_48 & ( V_53 | V_54 ) ) ==
( V_53 | V_54 ) )
return - V_52 ;
if ( ( V_48 & V_53 ) &&
! ( V_48 & V_55 ) )
return - V_52 ;
if ( ( V_48 & V_56 ) &&
( V_48 & ~ V_56 ) )
return - V_9 ;
if ( ( V_48 & V_57 ) &&
( V_48 & ~ V_57 ) )
return - V_9 ;
if ( ! ( V_4 -> V_41 & V_42 ) )
return - V_37 ;
if ( ( V_48 & ~ V_55 ) && F_11 ( V_18 ) )
return - V_25 ;
if ( F_29 ( V_18 ) )
return - V_25 ;
if ( F_30 ( V_18 ) )
return - V_58 ;
V_6 = F_31 ( V_4 , V_23 ) ;
if ( V_6 )
return V_6 ;
if ( F_32 ( V_18 -> V_19 ) )
return - V_59 ;
if ( ! F_8 ( V_18 -> V_19 ) && ! F_7 ( V_18 -> V_19 ) )
return - V_60 ;
if ( ( ( V_49 + V_50 ) > V_18 -> V_45 -> V_61 ) || ( ( V_49 + V_50 ) < 0 ) )
return - V_62 ;
if ( ! V_4 -> V_63 -> V_64 )
return - V_52 ;
F_24 ( V_18 -> V_45 ) ;
V_6 = V_4 -> V_63 -> V_64 ( V_4 , V_48 , V_49 , V_50 ) ;
if ( V_6 == 0 )
F_33 ( V_4 ) ;
F_25 ( V_18 -> V_45 ) ;
return V_6 ;
}
static int F_34 ( const struct V_17 * V_17 , T_3 V_48 )
{
struct V_18 * V_18 = V_17 -> V_1 -> V_16 ;
struct V_18 * V_65 = NULL ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_17 -> V_21 ) ;
if ( error )
return error ;
V_66:
F_3 ( V_18 ) ;
error = F_35 ( V_17 , V_48 ) ;
if ( error )
goto V_67;
V_8 . V_68 = ( V_48 & V_69 ) | ( V_18 -> V_19 & ~ V_69 ) ;
V_8 . V_11 = V_70 | V_47 ;
error = F_4 ( V_17 -> V_1 , & V_8 , & V_65 ) ;
V_67:
F_5 ( V_18 ) ;
if ( V_65 ) {
error = F_36 ( & V_65 ) ;
if ( ! error )
goto V_66;
}
F_17 ( V_17 -> V_21 ) ;
return error ;
}
static int F_37 ( const struct V_17 * V_17 , T_4 V_71 , T_5 V_72 )
{
struct V_18 * V_18 = V_17 -> V_1 -> V_16 ;
struct V_18 * V_65 = NULL ;
int error ;
struct V_7 V_8 ;
T_6 V_73 ;
T_7 V_74 ;
V_73 = F_38 ( F_39 () , V_71 ) ;
V_74 = F_40 ( F_39 () , V_72 ) ;
V_66:
V_8 . V_11 = V_47 ;
if ( V_71 != ( T_4 ) - 1 ) {
if ( ! F_41 ( V_73 ) )
return - V_9 ;
V_8 . V_11 |= V_75 ;
V_8 . V_76 = V_73 ;
}
if ( V_72 != ( T_5 ) - 1 ) {
if ( ! F_42 ( V_74 ) )
return - V_9 ;
V_8 . V_11 |= V_77 ;
V_8 . V_78 = V_74 ;
}
if ( ! F_7 ( V_18 -> V_19 ) )
V_8 . V_11 |=
V_79 | V_80 | V_81 ;
F_3 ( V_18 ) ;
error = F_43 ( V_17 , V_73 , V_74 ) ;
if ( ! error )
error = F_4 ( V_17 -> V_1 , & V_8 , & V_65 ) ;
F_5 ( V_18 ) ;
if ( V_65 ) {
error = F_36 ( & V_65 ) ;
if ( ! error )
goto V_66;
}
return error ;
}
int F_44 ( struct V_4 * V_36 )
{
if ( V_36 -> V_38 & V_82 ) {
if ( ! V_36 -> V_83 -> V_84 || ! V_36 -> V_83 -> V_84 -> V_85 )
return - V_9 ;
}
return 0 ;
}
static int F_45 ( struct V_4 * V_36 ,
struct V_18 * V_18 ,
int (* F_46)( struct V_18 * , struct V_4 * ) ,
const struct V_86 * V_86 )
{
static const struct V_87 V_88 = {} ;
int error ;
V_36 -> V_41 = F_47 ( V_36 -> V_38 ) | V_89 |
V_90 | V_91 ;
F_48 ( & V_36 -> V_40 ) ;
V_36 -> V_92 = V_18 ;
V_36 -> V_83 = V_18 -> V_93 ;
if ( F_49 ( V_36 -> V_38 & V_94 ) ) {
V_36 -> V_41 = V_95 ;
V_36 -> V_63 = & V_88 ;
return 0 ;
}
if ( V_36 -> V_41 & V_42 && ! F_50 ( V_18 -> V_19 ) ) {
error = F_12 ( V_18 ) ;
if ( F_49 ( error ) )
goto V_96;
error = F_51 ( V_36 -> V_40 . V_21 ) ;
if ( F_49 ( error ) ) {
F_16 ( V_18 ) ;
goto V_96;
}
V_36 -> V_41 |= V_97 ;
}
if ( F_8 ( V_18 -> V_19 ) || F_7 ( V_18 -> V_19 ) )
V_36 -> V_41 |= V_98 ;
V_36 -> V_63 = F_52 ( V_18 -> V_99 ) ;
if ( F_49 ( F_53 ( ! V_36 -> V_63 ) ) ) {
error = - V_60 ;
goto V_100;
}
error = F_54 ( V_36 , V_86 ) ;
if ( error )
goto V_100;
error = F_13 ( V_18 , V_36 -> V_38 ) ;
if ( error )
goto V_100;
if ( ! F_46 )
F_46 = V_36 -> V_63 -> F_46 ;
if ( F_46 ) {
error = F_46 ( V_18 , V_36 ) ;
if ( error )
goto V_100;
}
if ( ( V_36 -> V_41 & ( V_101 | V_42 ) ) == V_101 )
F_55 ( V_18 ) ;
if ( ( V_36 -> V_41 & V_101 ) &&
F_56 ( V_36 -> V_63 -> V_102 || V_36 -> V_63 -> V_103 ) )
V_36 -> V_41 |= V_104 ;
if ( ( V_36 -> V_41 & V_42 ) &&
F_56 ( V_36 -> V_63 -> V_105 || V_36 -> V_63 -> V_106 ) )
V_36 -> V_41 |= V_107 ;
V_36 -> V_38 &= ~ ( V_108 | V_109 | V_110 | V_111 ) ;
F_57 ( & V_36 -> V_112 , V_36 -> V_83 -> V_113 -> V_93 ) ;
return 0 ;
V_100:
F_58 ( V_36 -> V_63 ) ;
if ( V_36 -> V_41 & V_97 ) {
F_16 ( V_18 ) ;
F_59 ( V_36 -> V_40 . V_21 ) ;
}
V_96:
F_20 ( & V_36 -> V_40 ) ;
V_36 -> V_40 . V_21 = NULL ;
V_36 -> V_40 . V_1 = NULL ;
V_36 -> V_92 = NULL ;
return error ;
}
int F_60 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_46)( struct V_18 * , struct V_4 * ) ,
int * V_114 )
{
int error ;
F_61 ( * V_114 & V_115 ) ;
V_4 -> V_40 . V_1 = V_1 ;
error = F_45 ( V_4 , F_62 ( V_1 ) , F_46 ,
F_63 () ) ;
if ( ! error )
* V_114 |= V_115 ;
return error ;
}
int F_64 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_40 . V_1 = V_1 ;
return 1 ;
}
char * F_65 ( struct V_4 * V_5 , char * V_116 , int V_117 )
{
return F_66 ( & V_5 -> V_40 , V_116 , V_117 ) ;
}
int F_67 ( const struct V_17 * V_17 , struct V_4 * V_4 ,
const struct V_86 * V_86 )
{
struct V_18 * V_18 = F_68 ( V_17 -> V_1 , V_4 -> V_38 ) ;
if ( F_69 ( V_18 ) )
return F_70 ( V_18 ) ;
V_4 -> V_40 = * V_17 ;
return F_45 ( V_4 , V_18 , NULL , V_86 ) ;
}
struct V_4 * F_71 ( const struct V_17 * V_17 , int V_118 ,
const struct V_86 * V_86 )
{
int error ;
struct V_4 * V_36 ;
F_72 ( V_86 ) ;
F_61 ( ! V_17 -> V_21 ) ;
V_36 = F_73 () ;
if ( ! F_69 ( V_36 ) ) {
V_36 -> V_38 = V_118 ;
error = F_67 ( V_17 , V_36 , V_86 ) ;
if ( ! error ) {
error = F_44 ( V_36 ) ;
if ( error ) {
F_74 ( V_36 ) ;
V_36 = F_75 ( error ) ;
}
} else {
F_76 ( V_36 ) ;
V_36 = F_75 ( error ) ;
}
}
return V_36 ;
}
static inline int F_77 ( int V_118 , T_3 V_48 , struct V_119 * V_120 )
{
int V_29 = 0 ;
int V_121 = F_78 ( V_118 ) ;
if ( V_118 & ( V_108 | V_122 ) )
V_120 -> V_48 = ( V_48 & V_69 ) | V_123 ;
else
V_120 -> V_48 = 0 ;
V_118 &= ~ V_124 & ~ V_125 ;
if ( V_118 & V_126 )
V_118 |= V_127 ;
if ( V_118 & V_122 ) {
if ( ( V_118 & V_128 ) != V_129 )
return - V_9 ;
if ( ! ( V_121 & V_23 ) )
return - V_9 ;
} else if ( V_118 & V_94 ) {
V_118 &= V_130 | V_131 | V_94 ;
V_121 = 0 ;
}
V_120 -> V_132 = V_118 ;
if ( V_118 & V_111 )
V_121 |= V_23 ;
if ( V_118 & V_133 )
V_121 |= V_134 ;
V_120 -> V_121 = V_121 ;
V_120 -> V_135 = V_118 & V_94 ? 0 : V_136 ;
if ( V_118 & V_108 ) {
V_120 -> V_135 |= V_137 ;
if ( V_118 & V_109 )
V_120 -> V_135 |= V_138 ;
}
if ( V_118 & V_130 )
V_29 |= V_139 ;
if ( ! ( V_118 & V_131 ) )
V_29 |= V_30 ;
V_120 -> V_29 = V_29 ;
return 0 ;
}
struct V_4 * F_79 ( struct V_140 * V_141 , int V_118 , T_3 V_48 )
{
struct V_119 V_120 ;
int V_142 = F_77 ( V_118 , V_48 , & V_120 ) ;
return V_142 ? F_75 ( V_142 ) : F_80 ( V_32 , V_141 , & V_120 ) ;
}
struct V_4 * F_81 ( const char * V_140 , int V_118 , T_3 V_48 )
{
struct V_140 * V_141 = F_82 ( V_140 ) ;
struct V_4 * V_4 = F_83 ( V_141 ) ;
if ( ! F_69 ( V_141 ) ) {
V_4 = F_79 ( V_141 , V_118 , V_48 ) ;
F_84 ( V_141 ) ;
}
return V_4 ;
}
struct V_4 * F_85 ( struct V_1 * V_1 , struct V_143 * V_21 ,
const char * V_140 , int V_118 , T_3 V_48 )
{
struct V_119 V_120 ;
int V_142 = F_77 ( V_118 , V_48 , & V_120 ) ;
if ( V_142 )
return F_75 ( V_142 ) ;
return F_86 ( V_1 , V_21 , V_140 , & V_120 ) ;
}
long F_87 ( int V_144 , const char T_2 * V_140 , int V_118 , T_3 V_48 )
{
struct V_119 V_120 ;
int V_34 = F_77 ( V_118 , V_48 , & V_120 ) ;
struct V_140 * V_145 ;
if ( V_34 )
return V_34 ;
V_145 = F_88 ( V_140 ) ;
if ( F_69 ( V_145 ) )
return F_70 ( V_145 ) ;
V_34 = F_89 ( V_118 ) ;
if ( V_34 >= 0 ) {
struct V_4 * V_36 = F_80 ( V_144 , V_145 , & V_120 ) ;
if ( F_69 ( V_36 ) ) {
F_90 ( V_34 ) ;
V_34 = F_70 ( V_36 ) ;
} else {
F_91 ( V_36 ) ;
F_92 ( V_34 , V_36 ) ;
}
}
F_84 ( V_145 ) ;
return V_34 ;
}
int F_93 ( struct V_4 * V_5 , T_8 V_146 )
{
int V_147 = 0 ;
if ( ! F_94 ( V_5 ) ) {
F_95 ( V_148 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_63 -> V_149 )
V_147 = V_5 -> V_63 -> V_149 ( V_5 , V_146 ) ;
if ( F_56 ( ! ( V_5 -> V_41 & V_95 ) ) ) {
F_96 ( V_5 , V_146 ) ;
F_97 ( V_5 , V_146 ) ;
}
F_74 ( V_5 ) ;
return V_147 ;
}
int F_98 ( struct V_18 * V_18 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_38 & V_39 ) && F_99 ( V_18 ) > V_44 )
return - V_150 ;
return 0 ;
}
int F_100 ( struct V_18 * V_18 , struct V_4 * V_5 )
{
V_5 -> V_41 &= ~ ( V_89 | V_90 | V_91 ) ;
return 0 ;
}
