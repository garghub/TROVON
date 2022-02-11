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
V_6 = F_4 ( V_1 , & V_8 ) ;
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
struct V_7 V_8 ;
int error ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
return error ;
F_3 ( & V_19 -> V_17 ) ;
error = F_33 ( V_18 , V_49 ) ;
if ( error )
goto V_61;
V_8 . V_62 = ( V_49 & V_63 ) | ( V_19 -> V_20 & ~ V_63 ) ;
V_8 . V_11 = V_64 | V_48 ;
error = F_4 ( V_18 -> V_1 , & V_8 ) ;
V_61:
F_5 ( & V_19 -> V_17 ) ;
F_17 ( V_18 -> V_22 ) ;
return error ;
}
static int F_34 ( struct V_18 * V_18 , T_4 V_65 , T_5 V_66 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
int error ;
struct V_7 V_8 ;
T_6 V_67 ;
T_7 V_68 ;
V_67 = F_35 ( F_36 () , V_65 ) ;
V_68 = F_37 ( F_36 () , V_66 ) ;
V_8 . V_11 = V_48 ;
if ( V_65 != ( T_4 ) - 1 ) {
if ( ! F_38 ( V_67 ) )
return - V_9 ;
V_8 . V_11 |= V_69 ;
V_8 . V_70 = V_67 ;
}
if ( V_66 != ( T_5 ) - 1 ) {
if ( ! F_39 ( V_68 ) )
return - V_9 ;
V_8 . V_11 |= V_71 ;
V_8 . V_72 = V_68 ;
}
if ( ! F_7 ( V_19 -> V_20 ) )
V_8 . V_11 |=
V_73 | V_74 | V_75 ;
F_3 ( & V_19 -> V_17 ) ;
error = F_40 ( V_18 , V_67 , V_68 ) ;
if ( ! error )
error = F_4 ( V_18 -> V_1 , & V_8 ) ;
F_5 ( & V_19 -> V_17 ) ;
return error ;
}
static inline int F_41 ( struct V_19 * V_19 ,
struct V_76 * V_22 )
{
int error ;
error = F_12 ( V_19 ) ;
if ( error )
return error ;
if ( ! F_42 ( V_19 -> V_20 ) ) {
error = F_43 ( V_22 ) ;
if ( error )
F_16 ( V_19 ) ;
}
return error ;
}
int F_44 ( struct V_4 * V_37 )
{
if ( V_37 -> V_39 & V_77 ) {
if ( ! V_37 -> V_78 -> V_79 ||
( ( ! V_37 -> V_78 -> V_79 -> V_80 ) &&
( ! V_37 -> V_78 -> V_79 -> V_81 ) ) ) {
return - V_9 ;
}
}
return 0 ;
}
static int F_45 ( struct V_4 * V_37 ,
int (* F_46)( struct V_19 * , struct V_4 * ) ,
const struct V_82 * V_82 )
{
static const struct V_83 V_84 = {} ;
struct V_19 * V_19 ;
int error ;
V_37 -> V_42 = F_47 ( V_37 -> V_39 ) | V_85 |
V_86 | V_87 ;
if ( F_48 ( V_37 -> V_39 & V_88 ) )
V_37 -> V_42 = V_89 ;
F_49 ( & V_37 -> V_41 ) ;
V_19 = V_37 -> V_90 = V_37 -> V_41 . V_1 -> V_16 ;
if ( V_37 -> V_42 & V_43 ) {
error = F_41 ( V_19 , V_37 -> V_41 . V_22 ) ;
if ( error )
goto V_91;
if ( ! F_42 ( V_19 -> V_20 ) )
F_50 ( V_37 ) ;
}
V_37 -> V_78 = V_19 -> V_92 ;
F_51 ( V_37 , V_19 -> V_46 ) ;
if ( F_48 ( V_37 -> V_42 & V_89 ) ) {
V_37 -> V_59 = & V_84 ;
return 0 ;
}
V_37 -> V_59 = F_52 ( V_19 -> V_93 ) ;
error = F_53 ( V_37 , V_82 ) ;
if ( error )
goto V_94;
error = F_13 ( V_19 , V_37 -> V_39 ) ;
if ( error )
goto V_94;
if ( ! F_46 && V_37 -> V_59 )
F_46 = V_37 -> V_59 -> F_46 ;
if ( F_46 ) {
error = F_46 ( V_19 , V_37 ) ;
if ( error )
goto V_94;
}
if ( ( V_37 -> V_42 & ( V_95 | V_43 ) ) == V_95 )
F_54 ( V_19 ) ;
V_37 -> V_39 &= ~ ( V_96 | V_97 | V_98 | V_99 ) ;
F_55 ( & V_37 -> V_100 , V_37 -> V_78 -> V_101 -> V_92 ) ;
return 0 ;
V_94:
F_56 ( V_37 -> V_59 ) ;
F_57 ( V_37 ) ;
if ( V_37 -> V_42 & V_43 ) {
F_16 ( V_19 ) ;
if ( ! F_42 ( V_19 -> V_20 ) ) {
F_58 ( V_37 ) ;
F_59 ( V_37 -> V_41 . V_22 ) ;
}
}
V_91:
F_20 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
V_37 -> V_90 = NULL ;
return error ;
}
int F_60 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_46)( struct V_19 * , struct V_4 * ) ,
int * V_102 )
{
int error ;
F_61 ( * V_102 & V_103 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_45 ( V_4 , F_46 , F_62 () ) ;
if ( ! error )
* V_102 |= V_103 ;
return error ;
}
int F_63 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
struct V_4 * F_64 ( const struct V_18 * V_18 , int V_104 ,
const struct V_82 * V_82 )
{
int error ;
struct V_4 * V_37 ;
F_65 ( V_82 ) ;
F_61 ( ! V_18 -> V_22 ) ;
V_37 = F_66 () ;
if ( ! F_67 ( V_37 ) ) {
V_37 -> V_39 = V_104 ;
V_37 -> V_41 = * V_18 ;
error = F_45 ( V_37 , NULL , V_82 ) ;
if ( ! error ) {
error = F_44 ( V_37 ) ;
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
static inline int F_71 ( int V_104 , T_3 V_49 , struct V_105 * V_106 )
{
int V_30 = 0 ;
int V_107 ;
if ( V_104 & ( V_96 | V_108 ) )
V_106 -> V_49 = ( V_49 & V_63 ) | V_109 ;
else
V_106 -> V_49 = 0 ;
V_104 &= ~ V_110 & ~ V_111 ;
if ( V_104 & V_112 )
V_104 |= V_113 ;
if ( V_104 & V_108 ) {
if ( ( V_104 & V_114 ) != V_115 )
return - V_9 ;
V_107 = V_116 | F_72 ( V_104 ) ;
if ( ! ( V_107 & V_24 ) )
return - V_9 ;
} else if ( V_104 & V_88 ) {
V_104 &= V_117 | V_118 | V_88 ;
V_107 = 0 ;
} else {
V_107 = V_116 | F_72 ( V_104 ) ;
}
V_106 -> V_119 = V_104 ;
if ( V_104 & V_99 )
V_107 |= V_24 ;
if ( V_104 & V_120 )
V_107 |= V_121 ;
V_106 -> V_107 = V_107 ;
V_106 -> V_122 = V_104 & V_88 ? 0 : V_123 ;
if ( V_104 & V_96 ) {
V_106 -> V_122 |= V_124 ;
if ( V_104 & V_97 )
V_106 -> V_122 |= V_125 ;
}
if ( V_104 & V_117 )
V_30 |= V_126 ;
if ( ! ( V_104 & V_118 ) )
V_30 |= V_31 ;
V_106 -> V_30 = V_30 ;
return 0 ;
}
struct V_4 * F_73 ( struct V_127 * V_128 , int V_104 , T_3 V_49 )
{
struct V_105 V_106 ;
int V_129 = F_71 ( V_104 , V_49 , & V_106 ) ;
return V_129 ? F_69 ( V_129 ) : F_74 ( V_33 , V_128 , & V_106 ) ;
}
struct V_4 * F_75 ( const char * V_127 , int V_104 , T_3 V_49 )
{
struct V_127 V_128 = { . V_128 = V_127 } ;
return F_73 ( & V_128 , V_104 , V_49 ) ;
}
struct V_4 * F_76 ( struct V_1 * V_1 , struct V_76 * V_22 ,
const char * V_127 , int V_104 )
{
struct V_105 V_106 ;
int V_129 = F_71 ( V_104 , 0 , & V_106 ) ;
if ( V_129 )
return F_69 ( V_129 ) ;
if ( V_104 & V_96 )
return F_69 ( - V_9 ) ;
if ( ! V_127 && ( V_104 & V_117 ) )
if ( ! V_1 -> V_16 -> V_130 -> V_131 )
return F_69 ( - V_132 ) ;
return F_77 ( V_1 , V_22 , V_127 , & V_106 ) ;
}
long F_78 ( int V_133 , const char T_2 * V_127 , int V_104 , T_3 V_49 )
{
struct V_105 V_106 ;
int V_35 = F_71 ( V_104 , V_49 , & V_106 ) ;
struct V_127 * V_134 ;
if ( V_35 )
return V_35 ;
V_134 = F_79 ( V_127 ) ;
if ( F_67 ( V_134 ) )
return F_80 ( V_134 ) ;
V_35 = F_81 ( V_104 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_74 ( V_133 , V_134 , & V_106 ) ;
if ( F_67 ( V_37 ) ) {
F_82 ( V_35 ) ;
V_35 = F_80 ( V_37 ) ;
} else {
F_83 ( V_37 ) ;
F_84 ( V_35 , V_37 ) ;
}
}
F_85 ( V_134 ) ;
return V_35 ;
}
int F_86 ( struct V_4 * V_5 , T_8 V_135 )
{
int V_136 = 0 ;
if ( ! F_87 ( V_5 ) ) {
F_88 ( V_137 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_59 && V_5 -> V_59 -> V_138 )
V_136 = V_5 -> V_59 -> V_138 ( V_5 , V_135 ) ;
if ( F_89 ( ! ( V_5 -> V_42 & V_89 ) ) ) {
F_90 ( V_5 , V_135 ) ;
F_91 ( V_5 , V_135 ) ;
}
F_68 ( V_5 ) ;
return V_136 ;
}
int F_92 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_93 ( V_19 ) > V_45 )
return - V_139 ;
return 0 ;
}
int F_94 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_85 | V_86 | V_87 ) ;
return 0 ;
}
