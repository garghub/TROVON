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
T_3 (F_27)( const char T_2 * V_18 , T_1 V_2 )
{
return F_18 ( V_18 , V_2 ) ;
}
T_4 long F_28 ( long V_18 , T_1 V_2 )
{
return F_29 ( ( const char T_2 * ) V_18 , V_2 ) ;
}
T_3 (F_30)( unsigned int V_35 , T_1 V_2 )
{
long V_6 = F_22 ( V_35 , V_2 , 0 ) ;
F_31 ( 2 , V_6 , V_35 , V_2 ) ;
return V_6 ;
}
T_4 long F_32 ( long V_35 , T_1 V_2 )
{
return F_33 ( ( unsigned int ) V_35 , V_2 ) ;
}
int F_34 ( struct V_4 * V_4 , int V_49 , T_1 V_50 , T_1 V_51 )
{
struct V_19 * V_19 = V_4 -> V_41 . V_1 -> V_16 ;
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
if ( F_35 ( V_19 ) )
return - V_26 ;
V_6 = F_36 ( V_4 , V_24 ) ;
if ( V_6 )
return V_6 ;
if ( F_37 ( V_19 -> V_20 ) )
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
T_3 (V_60)( int V_35 , int V_49 , T_1 V_50 , T_1 V_51 )
{
struct V_35 V_37 = F_23 ( V_35 ) ;
int error = - V_38 ;
if ( V_37 . V_4 ) {
error = F_34 ( V_37 . V_4 , V_49 , V_50 , V_51 ) ;
F_26 ( V_37 ) ;
}
return error ;
}
T_4 long F_38 ( long V_35 , long V_49 , T_1 V_50 , T_1 V_51 )
{
return F_39 ( ( int ) V_35 , ( int ) V_49 , V_50 , V_51 ) ;
}
static int F_40 ( struct V_18 * V_18 , T_5 V_49 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
struct V_7 V_8 ;
int error ;
error = F_9 ( V_18 -> V_22 ) ;
if ( error )
return error ;
F_3 ( & V_19 -> V_17 ) ;
error = F_41 ( V_18 , V_49 ) ;
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
static int F_42 ( struct V_18 * V_18 , T_6 V_65 , T_7 V_66 )
{
struct V_19 * V_19 = V_18 -> V_1 -> V_16 ;
int error ;
struct V_7 V_8 ;
T_8 V_67 ;
T_9 V_68 ;
V_67 = F_43 ( F_44 () , V_65 ) ;
V_68 = F_45 ( F_44 () , V_66 ) ;
V_8 . V_11 = V_48 ;
if ( V_65 != ( T_6 ) - 1 ) {
if ( ! F_46 ( V_67 ) )
return - V_9 ;
V_8 . V_11 |= V_69 ;
V_8 . V_70 = V_67 ;
}
if ( V_66 != ( T_7 ) - 1 ) {
if ( ! F_47 ( V_68 ) )
return - V_9 ;
V_8 . V_11 |= V_71 ;
V_8 . V_72 = V_68 ;
}
if ( ! F_7 ( V_19 -> V_20 ) )
V_8 . V_11 |=
V_73 | V_74 | V_75 ;
F_3 ( & V_19 -> V_17 ) ;
error = F_48 ( V_18 , V_67 , V_68 ) ;
if ( ! error )
error = F_4 ( V_18 -> V_1 , & V_8 ) ;
F_5 ( & V_19 -> V_17 ) ;
return error ;
}
static inline int F_49 ( struct V_19 * V_19 ,
struct V_76 * V_22 )
{
int error ;
error = F_12 ( V_19 ) ;
if ( error )
return error ;
if ( ! F_50 ( V_19 -> V_20 ) ) {
error = F_51 ( V_22 ) ;
if ( error )
F_16 ( V_19 ) ;
}
return error ;
}
int F_52 ( struct V_4 * V_37 )
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
static int F_53 ( struct V_4 * V_37 ,
int (* F_54)( struct V_19 * , struct V_4 * ) ,
const struct V_82 * V_82 )
{
static const struct V_83 V_84 = {} ;
struct V_19 * V_19 ;
int error ;
V_37 -> V_42 = F_55 ( V_37 -> V_39 ) | V_85 |
V_86 | V_87 ;
if ( F_56 ( V_37 -> V_39 & V_88 ) )
V_37 -> V_42 = V_89 ;
F_57 ( & V_37 -> V_41 ) ;
V_19 = V_37 -> V_41 . V_1 -> V_16 ;
if ( V_37 -> V_42 & V_43 ) {
error = F_49 ( V_19 , V_37 -> V_41 . V_22 ) ;
if ( error )
goto V_90;
if ( ! F_50 ( V_19 -> V_20 ) )
F_58 ( V_37 ) ;
}
V_37 -> V_78 = V_19 -> V_91 ;
V_37 -> V_92 = 0 ;
F_59 ( V_37 , V_19 -> V_46 ) ;
if ( F_56 ( V_37 -> V_42 & V_89 ) ) {
V_37 -> V_59 = & V_84 ;
return 0 ;
}
V_37 -> V_59 = F_60 ( V_19 -> V_93 ) ;
error = F_61 ( V_37 , V_82 ) ;
if ( error )
goto V_94;
error = F_13 ( V_19 , V_37 -> V_39 ) ;
if ( error )
goto V_94;
if ( ! F_54 && V_37 -> V_59 )
F_54 = V_37 -> V_59 -> F_54 ;
if ( F_54 ) {
error = F_54 ( V_19 , V_37 ) ;
if ( error )
goto V_94;
}
if ( ( V_37 -> V_42 & ( V_95 | V_43 ) ) == V_95 )
F_62 ( V_19 ) ;
V_37 -> V_39 &= ~ ( V_96 | V_97 | V_98 | V_99 ) ;
F_63 ( & V_37 -> V_100 , V_37 -> V_78 -> V_101 -> V_91 ) ;
return 0 ;
V_94:
F_64 ( V_37 -> V_59 ) ;
F_65 ( V_37 ) ;
if ( V_37 -> V_42 & V_43 ) {
F_16 ( V_19 ) ;
if ( ! F_50 ( V_19 -> V_20 ) ) {
F_66 ( V_37 ) ;
F_67 ( V_37 -> V_41 . V_22 ) ;
}
}
V_90:
F_20 ( & V_37 -> V_41 ) ;
V_37 -> V_41 . V_22 = NULL ;
V_37 -> V_41 . V_1 = NULL ;
return error ;
}
int F_68 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_54)( struct V_19 * , struct V_4 * ) ,
int * V_102 )
{
int error ;
F_69 ( * V_102 & V_103 ) ;
V_4 -> V_41 . V_1 = V_1 ;
error = F_53 ( V_4 , F_54 , F_70 () ) ;
if ( ! error )
* V_102 |= V_103 ;
return error ;
}
int F_71 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_41 . V_1 = V_1 ;
return 1 ;
}
struct V_4 * F_72 ( const struct V_18 * V_18 , int V_104 ,
const struct V_82 * V_82 )
{
int error ;
struct V_4 * V_37 ;
F_73 ( V_82 ) ;
F_69 ( ! V_18 -> V_22 ) ;
error = - V_105 ;
V_37 = F_74 () ;
if ( V_37 == NULL )
return F_75 ( error ) ;
V_37 -> V_39 = V_104 ;
V_37 -> V_41 = * V_18 ;
error = F_53 ( V_37 , NULL , V_82 ) ;
if ( ! error ) {
error = F_52 ( V_37 ) ;
if ( error ) {
F_76 ( V_37 ) ;
V_37 = F_75 ( error ) ;
}
} else {
F_77 ( V_37 ) ;
V_37 = F_75 ( error ) ;
}
return V_37 ;
}
static inline int F_78 ( int V_104 , T_5 V_49 , struct V_106 * V_107 )
{
int V_30 = 0 ;
int V_108 ;
if ( V_104 & V_96 )
V_107 -> V_49 = ( V_49 & V_63 ) | V_109 ;
else
V_107 -> V_49 = 0 ;
V_104 &= ~ V_110 & ~ V_111 ;
if ( V_104 & V_112 )
V_104 |= V_113 ;
if ( V_104 & V_88 ) {
V_104 &= V_114 | V_115 | V_88 ;
V_108 = 0 ;
} else {
V_108 = V_116 | F_79 ( V_104 ) ;
}
V_107 -> V_117 = V_104 ;
if ( V_104 & V_99 )
V_108 |= V_24 ;
if ( V_104 & V_118 )
V_108 |= V_119 ;
V_107 -> V_108 = V_108 ;
V_107 -> V_120 = V_104 & V_88 ? 0 : V_121 ;
if ( V_104 & V_96 ) {
V_107 -> V_120 |= V_122 ;
if ( V_104 & V_97 )
V_107 -> V_120 |= V_123 ;
}
if ( V_104 & V_114 )
V_30 |= V_124 ;
if ( ! ( V_104 & V_115 ) )
V_30 |= V_31 ;
return V_30 ;
}
struct V_4 * F_80 ( struct V_125 * V_126 , int V_104 , T_5 V_49 )
{
struct V_106 V_107 ;
int V_127 = F_78 ( V_104 , V_49 , & V_107 ) ;
return F_81 ( V_33 , V_126 , & V_107 , V_127 ) ;
}
struct V_4 * F_82 ( const char * V_125 , int V_104 , T_5 V_49 )
{
struct V_125 V_126 = { . V_126 = V_125 } ;
return F_80 ( & V_126 , V_104 , V_49 ) ;
}
struct V_4 * F_83 ( struct V_1 * V_1 , struct V_76 * V_22 ,
const char * V_125 , int V_104 )
{
struct V_106 V_107 ;
int V_127 = F_78 ( V_104 , 0 , & V_107 ) ;
if ( V_104 & V_96 )
return F_75 ( - V_9 ) ;
if ( ! V_125 && ( V_104 & V_114 ) )
if ( ! V_1 -> V_16 -> V_128 -> V_127 )
return F_75 ( - V_129 ) ;
return F_84 ( V_1 , V_22 , V_125 , & V_107 , V_127 ) ;
}
long F_85 ( int V_130 , const char T_2 * V_125 , int V_104 , T_5 V_49 )
{
struct V_106 V_107 ;
int V_127 = F_78 ( V_104 , V_49 , & V_107 ) ;
struct V_125 * V_131 = F_86 ( V_125 ) ;
int V_35 = F_87 ( V_131 ) ;
if ( ! F_88 ( V_131 ) ) {
V_35 = F_89 ( V_104 ) ;
if ( V_35 >= 0 ) {
struct V_4 * V_37 = F_81 ( V_130 , V_131 , & V_107 , V_127 ) ;
if ( F_88 ( V_37 ) ) {
F_90 ( V_35 ) ;
V_35 = F_87 ( V_37 ) ;
} else {
F_91 ( V_37 ) ;
F_92 ( V_35 , V_37 ) ;
}
}
F_93 ( V_131 ) ;
}
return V_35 ;
}
int F_94 ( struct V_4 * V_5 , T_10 V_132 )
{
int V_133 = 0 ;
if ( ! F_95 ( V_5 ) ) {
F_96 ( V_134 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_59 && V_5 -> V_59 -> V_135 )
V_133 = V_5 -> V_59 -> V_135 ( V_5 , V_132 ) ;
if ( F_97 ( ! ( V_5 -> V_42 & V_89 ) ) ) {
F_98 ( V_5 , V_132 ) ;
F_99 ( V_5 , V_132 ) ;
}
F_76 ( V_5 ) ;
return V_133 ;
}
int F_100 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_39 & V_40 ) && F_101 ( V_19 ) > V_45 )
return - V_136 ;
return 0 ;
}
int F_102 ( struct V_19 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_42 &= ~ ( V_85 | V_86 | V_87 ) ;
return 0 ;
}
