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
if ( V_49 & ~ ( V_52 | V_53 ) )
return - V_54 ;
if ( ( V_49 & V_53 ) &&
! ( V_49 & V_52 ) )
return - V_54 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return - V_38 ;
if ( V_49 & V_53 && F_11 ( V_19 ) )
return - V_26 ;
if ( F_29 ( V_19 ) )
return - V_26 ;
V_6 = F_30 ( V_4 , V_24 ) ;
if ( V_6 )
return V_6 ;
if ( F_31 ( V_19 -> V_20 ) )
return - V_55 ;
if ( ! F_8 ( V_19 -> V_20 ) && ! F_7 ( V_19 -> V_20 ) )
return - V_56 ;
if ( ( ( V_50 + V_51 ) > V_19 -> V_46 -> V_57 ) || ( ( V_50 + V_51 ) < 0 ) )
return - V_58 ;
if ( ! V_4 -> V_59 -> V_60 )
return - V_54 ;
F_24 ( V_19 -> V_46 ) ;
V_6 = V_4 -> V_59 -> V_60 ( V_4 , V_49 , V_50 , V_51 ) ;
F_25 ( V_19 -> V_46 ) ;
return V_6 ;
}
static int F_32 ( struct V_18 * V_18 , T_3 V_49 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_61 = NULL ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
return error ;
V_62:
F_3 ( & V_19 -> V_17 ) ;
error = F_33 ( V_18 , V_49 ) ;
if ( error )
goto V_63;
V_8 . V_64 = ( V_49 & V_65 ) | ( V_19 -> V_20 & ~ V_65 ) ;
V_8 . V_11 = V_66 | V_48 ;
error = F_4 ( V_18 -> V_1 , & V_8 , & V_61 ) ;
V_63:
F_5 ( & V_19 -> V_17 ) ;
if ( V_61 ) {
error = F_34 ( & V_61 ) ;
if ( ! error )
goto V_62;
}
F_17 ( V_18 -> V_22 ) ;
return error ;
}
static int F_35 ( struct V_18 * V_18 , T_4 V_67 , T_5 V_68 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_19 * V_61 = NULL ;
int error ;
struct V_7 V_8 ;
T_6 V_69 ;
T_7 V_70 ;
V_69 = F_36 ( F_37 () , V_67 ) ;
V_70 = F_38 ( F_37 () , V_68 ) ;
V_8 . V_11 = V_48 ;
if ( V_67 != ( T_4 ) - 1 ) {
if ( ! F_39 ( V_69 ) )
return - V_9 ;
V_8 . V_11 |= V_71 ;
V_8 . V_72 = V_69 ;
}
if ( V_68 != ( T_5 ) - 1 ) {
if ( ! F_40 ( V_70 ) )
return - V_9 ;
V_8 . V_11 |= V_73 ;
V_8 . V_74 = V_70 ;
}
if ( ! F_7 ( V_19 -> V_20 ) )
V_8 . V_11 |=
V_75 | V_76 | V_77 ;
V_62:
F_3 ( & V_19 -> V_17 ) ;
error = F_41 ( V_18 , V_69 , V_70 ) ;
if ( ! error )
error = F_4 ( V_18 -> V_1 , & V_8 , & V_61 ) ;
F_5 ( & V_19 -> V_17 ) ;
if ( V_61 ) {
error = F_34 ( & V_61 ) ;
if ( ! error )
goto V_62;
}
return error ;
}
static inline int F_42 ( struct V_19 * V_19 ,
struct V_78 * V_22 )
{
int error ;
error = F_12 ( V_19 ) ;
if ( error )
return error ;
if ( ! F_43 ( V_19 -> V_20 ) ) {
error = F_44 ( V_22 ) ;
if ( error )
F_16 ( V_19 ) ;
}
return error ;
}
int F_45 ( struct V_4 * V_37 )
{
if ( V_37 -> V_39 & V_79 ) {
if ( ! V_37 -> V_80 -> V_81 ||
( ( ! V_37 -> V_80 -> V_81 -> V_82 ) &&
( ! V_37 -> V_80 -> V_81 -> V_83 ) ) ) {
return - V_9 ;
}
}
return 0 ;
}
static int F_46 ( struct V_4 * V_37 ,
int (* F_47)( struct V_19 * , struct V_4 * ) ,
const struct V_84 * V_84 )
{
static const struct V_85 V_86 = {} ;
struct V_19 * V_19 ;
int error ;
V_37 -> V_42 = F_48 ( V_37 -> V_39 ) | V_87 |
V_88 | V_89 ;
if ( F_49 ( V_37 -> V_39 & V_90 ) )
V_37 -> V_42 = V_91 ;
F_50 ( & V_37 -> V_41 ) ;
V_19 = V_37 -> V_92 = V_37 -> V_41 . V_1 -> V_16 ;
if ( V_37 -> V_42 & V_43 ) {
error = F_42 ( V_19 , V_37 -> V_41 . V_22 ) ;
if ( error )
goto V_93;
if ( ! F_43 ( V_19 -> V_20 ) )
F_51 ( V_37 ) ;
}
V_37 -> V_80 = V_19 -> V_94 ;
if ( F_49 ( V_37 -> V_42 & V_91 ) ) {
V_37 -> V_59 = & V_86 ;
return 0 ;
}
V_37 -> V_59 = F_52 ( V_19 -> V_95 ) ;
if ( F_49 ( F_53 ( ! V_37 -> V_59 ) ) ) {
error = - V_56 ;
goto V_96;
}
error = F_54 ( V_37 , V_84 ) ;
if ( error )
goto V_96;
error = F_13 ( V_19 , V_37 -> V_39 ) ;
if ( error )
goto V_96;
if ( ! F_47 )
F_47 = V_37 -> V_59 -> F_47 ;
if ( F_47 ) {
error = F_47 ( V_19 , V_37 ) ;
if ( error )
goto V_96;
}
if ( ( V_37 -> V_42 & ( V_97 | V_43 ) ) == V_97 )
F_55 ( V_19 ) ;
V_37 -> V_39 &= ~ ( V_98 | V_99 | V_100 | V_101 ) ;
F_56 ( & V_37 -> V_102 , V_37 -> V_80 -> V_103 -> V_94 ) ;
return 0 ;
V_96:
F_57 ( V_37 -> V_59 ) ;
if ( V_37 -> V_42 & V_43 ) {
F_16 ( V_19 ) ;
if ( ! F_43 ( V_19 -> V_20 ) ) {
F_58 ( V_37 ) ;
F_59 ( V_37 -> V_41 . V_22 ) ;
}
}
V_93:
F_20 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
V_37 -> V_92 = NULL ;
return error ;
}
int F_60 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_47)( struct V_19 * , struct V_4 * ) ,
int * V_104 )
{
int error ;
F_61 ( * V_104 & V_105 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_46 ( V_4 , F_47 , F_62 () ) ;
if ( ! error )
* V_104 |= V_105 ;
return error ;
}
int F_63 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
struct V_4 * F_64 ( const struct V_18 * V_18 , int V_106 ,
const struct V_84 * V_84 )
{
int error ;
struct V_4 * V_37 ;
F_65 ( V_84 ) ;
F_61 ( ! V_18 -> V_22 ) ;
V_37 = F_66 () ;
if ( ! F_67 ( V_37 ) ) {
V_37 -> V_39 = V_106 ;
V_37 -> V_41 = * V_18 ;
error = F_46 ( V_37 , NULL , V_84 ) ;
if ( ! error ) {
error = F_45 ( V_37 ) ;
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
static inline int F_71 ( int V_106 , T_3 V_49 , struct V_107 * V_108 )
{
int V_30 = 0 ;
int V_109 ;
if ( V_106 & ( V_98 | V_110 ) )
V_108 -> V_49 = ( V_49 & V_65 ) | V_111 ;
else
V_108 -> V_49 = 0 ;
V_106 &= ~ V_112 & ~ V_113 ;
if ( V_106 & V_114 )
V_106 |= V_115 ;
if ( V_106 & V_110 ) {
if ( ( V_106 & V_116 ) != V_117 )
return - V_9 ;
V_109 = V_118 | F_72 ( V_106 ) ;
if ( ! ( V_109 & V_24 ) )
return - V_9 ;
} else if ( V_106 & V_90 ) {
V_106 &= V_119 | V_120 | V_90 ;
V_109 = 0 ;
} else {
V_109 = V_118 | F_72 ( V_106 ) ;
}
V_108 -> V_121 = V_106 ;
if ( V_106 & V_101 )
V_109 |= V_24 ;
if ( V_106 & V_122 )
V_109 |= V_123 ;
V_108 -> V_109 = V_109 ;
V_108 -> V_124 = V_106 & V_90 ? 0 : V_125 ;
if ( V_106 & V_98 ) {
V_108 -> V_124 |= V_126 ;
if ( V_106 & V_99 )
V_108 -> V_124 |= V_127 ;
}
if ( V_106 & V_119 )
V_30 |= V_128 ;
if ( ! ( V_106 & V_120 ) )
V_30 |= V_31 ;
V_108 -> V_30 = V_30 ;
return 0 ;
}
struct V_4 * F_73 ( struct V_129 * V_130 , int V_106 , T_3 V_49 )
{
struct V_107 V_108 ;
int V_131 = F_71 ( V_106 , V_49 , & V_108 ) ;
return V_131 ? F_69 ( V_131 ) : F_74 ( V_33 , V_130 , & V_108 ) ;
}
struct V_4 * F_75 ( const char * V_129 , int V_106 , T_3 V_49 )
{
struct V_129 V_130 = { . V_130 = V_129 } ;
return F_73 ( & V_130 , V_106 , V_49 ) ;
}
struct V_4 * F_76 ( struct V_1 * V_1 , struct V_78 * V_22 ,
const char * V_129 , int V_106 )
{
struct V_107 V_108 ;
int V_131 = F_71 ( V_106 , 0 , & V_108 ) ;
if ( V_131 )
return F_69 ( V_131 ) ;
if ( V_106 & V_98 )
return F_69 ( - V_9 ) ;
if ( ! V_129 && ( V_106 & V_119 ) )
if ( ! V_1 -> V_16 -> V_132 -> V_133 )
return F_69 ( - V_134 ) ;
return F_77 ( V_1 , V_22 , V_129 , & V_108 ) ;
}
long F_78 ( int V_135 , const char T_2 * V_129 , int V_106 , T_3 V_49 )
{
struct V_107 V_108 ;
int V_35 = F_71 ( V_106 , V_49 , & V_108 ) ;
struct V_129 * V_136 ;
if ( V_35 )
return V_35 ;
V_136 = F_79 ( V_129 ) ;
if ( F_67 ( V_136 ) )
return F_80 ( V_136 ) ;
V_35 = F_81 ( V_106 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_74 ( V_135 , V_136 , & V_108 ) ;
if ( F_67 ( V_37 ) ) {
F_82 ( V_35 ) ;
V_35 = F_80 ( V_37 ) ;
} else {
F_83 ( V_37 ) ;
F_84 ( V_35 , V_37 ) ;
}
}
F_85 ( V_136 ) ;
return V_35 ;
}
int F_86 ( struct V_4 * V_5 , T_8 V_137 )
{
int V_138 = 0 ;
if ( ! F_87 ( V_5 ) ) {
F_88 ( V_139 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_59 -> V_140 )
V_138 = V_5 -> V_59 -> V_140 ( V_5 , V_137 ) ;
if ( F_89 ( ! ( V_5 -> V_42 & V_91 ) ) ) {
F_90 ( V_5 , V_137 ) ;
F_91 ( V_5 , V_137 ) ;
}
F_68 ( V_5 ) ;
return V_138 ;
}
int F_92 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_93 ( V_19 ) > V_45 )
return - V_141 ;
return 0 ;
}
int F_94 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_87 | V_88 | V_89 ) ;
return 0 ;
}
