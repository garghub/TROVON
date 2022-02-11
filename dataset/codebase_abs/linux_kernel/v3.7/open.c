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
static long F_6 ( const char T_2 * V_18 , T_1 V_2 )
{
struct V_19 V_19 ;
struct V_20 * V_20 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_21;
error = F_7 ( V_18 , & V_19 ) ;
if ( error )
goto V_21;
V_20 = V_19 . V_1 -> V_16 ;
error = - V_22 ;
if ( F_8 ( V_20 -> V_23 ) )
goto V_24;
error = - V_9 ;
if ( ! F_9 ( V_20 -> V_23 ) )
goto V_24;
error = F_10 ( V_19 . V_25 ) ;
if ( error )
goto V_24;
error = F_11 ( V_20 , V_26 ) ;
if ( error )
goto V_27;
error = - V_28 ;
if ( F_12 ( V_20 ) )
goto V_27;
error = F_13 ( V_20 ) ;
if ( error )
goto V_27;
error = F_14 ( V_20 , V_29 ) ;
if ( error )
goto V_30;
error = F_15 ( V_20 , NULL , V_2 ) ;
if ( ! error )
error = F_16 ( & V_19 ) ;
if ( ! error )
error = F_1 ( V_19 . V_1 , V_2 , 0 , NULL ) ;
V_30:
F_17 ( V_20 ) ;
V_27:
F_18 ( V_19 . V_25 ) ;
V_24:
F_19 ( & V_19 ) ;
V_21:
return error ;
}
static long F_20 ( unsigned int V_31 , T_1 V_2 , int V_32 )
{
struct V_20 * V_20 ;
struct V_1 * V_1 ;
struct V_31 V_33 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_21;
error = - V_34 ;
V_33 = F_21 ( V_31 ) ;
if ( ! V_33 . V_4 )
goto V_21;
if ( V_33 . V_4 -> V_35 & V_36 )
V_32 = 0 ;
V_1 = V_33 . V_4 -> V_37 . V_1 ;
V_20 = V_1 -> V_16 ;
error = - V_9 ;
if ( ! F_9 ( V_20 -> V_23 ) || ! ( V_33 . V_4 -> V_38 & V_39 ) )
goto V_40;
error = - V_9 ;
if ( V_32 && V_2 > V_41 )
goto V_40;
error = - V_28 ;
if ( F_12 ( V_20 ) )
goto V_40;
F_22 ( V_20 -> V_42 ) ;
error = F_15 ( V_20 , V_33 . V_4 , V_2 ) ;
if ( ! error )
error = F_16 ( & V_33 . V_4 -> V_37 ) ;
if ( ! error )
error = F_1 ( V_1 , V_2 , V_43 | V_44 , V_33 . V_4 ) ;
F_23 ( V_20 -> V_42 ) ;
V_40:
F_24 ( V_33 ) ;
V_21:
return error ;
}
T_3 (F_25)( const char T_2 * V_19 , T_1 V_2 )
{
return F_6 ( V_19 , V_2 ) ;
}
T_4 long F_26 ( long V_19 , T_1 V_2 )
{
return F_27 ( ( const char T_2 * ) V_19 , V_2 ) ;
}
T_3 (F_28)( unsigned int V_31 , T_1 V_2 )
{
long V_6 = F_20 ( V_31 , V_2 , 0 ) ;
F_29 ( 2 , V_6 , V_31 , V_2 ) ;
return V_6 ;
}
T_4 long F_30 ( long V_31 , T_1 V_2 )
{
return F_31 ( ( unsigned int ) V_31 , V_2 ) ;
}
int F_32 ( struct V_4 * V_4 , int V_45 , T_1 V_46 , T_1 V_47 )
{
struct V_20 * V_20 = V_4 -> V_37 . V_1 -> V_16 ;
long V_6 ;
if ( V_46 < 0 || V_47 <= 0 )
return - V_9 ;
if ( V_45 & ~ ( V_48 | V_49 ) )
return - V_50 ;
if ( ( V_45 & V_49 ) &&
! ( V_45 & V_48 ) )
return - V_50 ;
if ( ! ( V_4 -> V_38 & V_39 ) )
return - V_34 ;
if ( V_45 & V_49 && F_12 ( V_20 ) )
return - V_28 ;
if ( F_33 ( V_20 ) )
return - V_28 ;
V_6 = F_34 ( V_4 , V_26 ) ;
if ( V_6 )
return V_6 ;
if ( F_35 ( V_20 -> V_23 ) )
return - V_51 ;
if ( ! F_9 ( V_20 -> V_23 ) && ! F_8 ( V_20 -> V_23 ) )
return - V_52 ;
if ( ( ( V_46 + V_47 ) > V_20 -> V_42 -> V_53 ) || ( ( V_46 + V_47 ) < 0 ) )
return - V_54 ;
if ( ! V_4 -> V_55 -> V_56 )
return - V_50 ;
F_22 ( V_20 -> V_42 ) ;
V_6 = V_4 -> V_55 -> V_56 ( V_4 , V_45 , V_46 , V_47 ) ;
F_23 ( V_20 -> V_42 ) ;
return V_6 ;
}
T_3 (V_56)( int V_31 , int V_45 , T_1 V_46 , T_1 V_47 )
{
struct V_31 V_33 = F_21 ( V_31 ) ;
int error = - V_34 ;
if ( V_33 . V_4 ) {
error = F_32 ( V_33 . V_4 , V_45 , V_46 , V_47 ) ;
F_24 ( V_33 ) ;
}
return error ;
}
T_4 long F_36 ( long V_31 , long V_45 , T_1 V_46 , T_1 V_47 )
{
return F_37 ( ( int ) V_31 , ( int ) V_45 , V_46 , V_47 ) ;
}
static int F_38 ( struct V_19 * V_19 , T_5 V_45 )
{
struct V_20 * V_20 = V_19 -> V_1 -> V_16 ;
struct V_7 V_8 ;
int error ;
error = F_10 ( V_19 -> V_25 ) ;
if ( error )
return error ;
F_3 ( & V_20 -> V_17 ) ;
error = F_39 ( V_19 , V_45 ) ;
if ( error )
goto V_57;
V_8 . V_58 = ( V_45 & V_59 ) | ( V_20 -> V_23 & ~ V_59 ) ;
V_8 . V_11 = V_60 | V_44 ;
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
V_57:
F_5 ( & V_20 -> V_17 ) ;
F_18 ( V_19 -> V_25 ) ;
return error ;
}
static int F_40 ( struct V_19 * V_19 , T_6 V_61 , T_7 V_62 )
{
struct V_20 * V_20 = V_19 -> V_1 -> V_16 ;
int error ;
struct V_7 V_8 ;
T_8 V_63 ;
T_9 V_64 ;
V_63 = F_41 ( F_42 () , V_61 ) ;
V_64 = F_43 ( F_42 () , V_62 ) ;
V_8 . V_11 = V_44 ;
if ( V_61 != ( T_6 ) - 1 ) {
if ( ! F_44 ( V_63 ) )
return - V_9 ;
V_8 . V_11 |= V_65 ;
V_8 . V_66 = V_63 ;
}
if ( V_62 != ( T_7 ) - 1 ) {
if ( ! F_45 ( V_64 ) )
return - V_9 ;
V_8 . V_11 |= V_67 ;
V_8 . V_68 = V_64 ;
}
if ( ! F_8 ( V_20 -> V_23 ) )
V_8 . V_11 |=
V_69 | V_70 | V_71 ;
F_3 ( & V_20 -> V_17 ) ;
error = F_46 ( V_19 , V_63 , V_64 ) ;
if ( ! error )
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
F_5 ( & V_20 -> V_17 ) ;
return error ;
}
static inline int F_47 ( struct V_20 * V_20 ,
struct V_72 * V_25 )
{
int error ;
error = F_13 ( V_20 ) ;
if ( error )
return error ;
if ( ! F_48 ( V_20 -> V_23 ) ) {
error = F_49 ( V_25 ) ;
if ( error )
F_17 ( V_20 ) ;
}
return error ;
}
int F_50 ( struct V_4 * V_33 )
{
if ( V_33 -> V_35 & V_73 ) {
if ( ! V_33 -> V_74 -> V_75 ||
( ( ! V_33 -> V_74 -> V_75 -> V_76 ) &&
( ! V_33 -> V_74 -> V_75 -> V_77 ) ) ) {
return - V_9 ;
}
}
return 0 ;
}
static int F_51 ( struct V_4 * V_33 ,
int (* F_52)( struct V_20 * , struct V_4 * ) ,
const struct V_78 * V_78 )
{
static const struct V_79 V_80 = {} ;
struct V_20 * V_20 ;
int error ;
V_33 -> V_38 = F_53 ( V_33 -> V_35 ) | V_81 |
V_82 | V_83 ;
if ( F_54 ( V_33 -> V_35 & V_84 ) )
V_33 -> V_38 = V_85 ;
F_55 ( & V_33 -> V_37 ) ;
V_20 = V_33 -> V_37 . V_1 -> V_16 ;
if ( V_33 -> V_38 & V_39 ) {
error = F_47 ( V_20 , V_33 -> V_37 . V_25 ) ;
if ( error )
goto V_86;
if ( ! F_48 ( V_20 -> V_23 ) )
F_56 ( V_33 ) ;
}
V_33 -> V_74 = V_20 -> V_87 ;
V_33 -> V_88 = 0 ;
F_57 ( V_33 , V_20 -> V_42 ) ;
if ( F_54 ( V_33 -> V_38 & V_85 ) ) {
V_33 -> V_55 = & V_80 ;
return 0 ;
}
V_33 -> V_55 = F_58 ( V_20 -> V_89 ) ;
error = F_59 ( V_33 , V_78 ) ;
if ( error )
goto V_90;
error = F_14 ( V_20 , V_33 -> V_35 ) ;
if ( error )
goto V_90;
if ( ! F_52 && V_33 -> V_55 )
F_52 = V_33 -> V_55 -> F_52 ;
if ( F_52 ) {
error = F_52 ( V_20 , V_33 ) ;
if ( error )
goto V_90;
}
if ( ( V_33 -> V_38 & ( V_91 | V_39 ) ) == V_91 )
F_60 ( V_20 ) ;
V_33 -> V_35 &= ~ ( V_92 | V_93 | V_94 | V_95 ) ;
F_61 ( & V_33 -> V_96 , V_33 -> V_74 -> V_97 -> V_87 ) ;
return 0 ;
V_90:
F_62 ( V_33 -> V_55 ) ;
F_63 ( V_33 ) ;
if ( V_33 -> V_38 & V_39 ) {
F_17 ( V_20 ) ;
if ( ! F_48 ( V_20 -> V_23 ) ) {
F_64 ( V_33 ) ;
F_65 ( V_33 -> V_37 . V_25 ) ;
}
}
V_86:
F_19 ( & V_33 -> V_37 ) ;
V_33 -> V_37 . V_25 = NULL ;
V_33 -> V_37 . V_1 = NULL ;
return error ;
}
int F_66 ( struct V_4 * V_4 , struct V_1 * V_1 ,
int (* F_52)( struct V_20 * , struct V_4 * ) ,
int * V_98 )
{
int error ;
F_67 ( * V_98 & V_99 ) ;
V_4 -> V_37 . V_1 = V_1 ;
error = F_51 ( V_4 , F_52 , F_68 () ) ;
if ( ! error )
* V_98 |= V_99 ;
return error ;
}
int F_69 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
V_4 -> V_37 . V_1 = V_1 ;
return 1 ;
}
struct V_4 * F_70 ( const struct V_19 * V_19 , int V_100 ,
const struct V_78 * V_78 )
{
int error ;
struct V_4 * V_33 ;
F_71 ( V_78 ) ;
F_67 ( ! V_19 -> V_25 ) ;
error = - V_101 ;
V_33 = F_72 () ;
if ( V_33 == NULL )
return F_73 ( error ) ;
V_33 -> V_35 = V_100 ;
V_33 -> V_37 = * V_19 ;
error = F_51 ( V_33 , NULL , V_78 ) ;
if ( ! error ) {
error = F_50 ( V_33 ) ;
if ( error ) {
F_74 ( V_33 ) ;
V_33 = F_73 ( error ) ;
}
} else {
F_75 ( V_33 ) ;
V_33 = F_73 ( error ) ;
}
return V_33 ;
}
static inline int F_76 ( int V_100 , T_5 V_45 , struct V_102 * V_103 )
{
int V_104 = 0 ;
int V_105 ;
if ( V_100 & V_92 )
V_103 -> V_45 = ( V_45 & V_59 ) | V_106 ;
else
V_103 -> V_45 = 0 ;
V_100 &= ~ V_107 & ~ V_108 ;
if ( V_100 & V_109 )
V_100 |= V_110 ;
if ( V_100 & V_84 ) {
V_100 &= V_111 | V_112 | V_84 ;
V_105 = 0 ;
} else {
V_105 = V_113 | F_77 ( V_100 ) ;
}
V_103 -> V_114 = V_100 ;
if ( V_100 & V_95 )
V_105 |= V_26 ;
if ( V_100 & V_115 )
V_105 |= V_116 ;
V_103 -> V_105 = V_105 ;
V_103 -> V_117 = V_100 & V_84 ? 0 : V_118 ;
if ( V_100 & V_92 ) {
V_103 -> V_117 |= V_119 ;
if ( V_100 & V_93 )
V_103 -> V_117 |= V_120 ;
}
if ( V_100 & V_111 )
V_104 |= V_121 ;
if ( ! ( V_100 & V_112 ) )
V_104 |= V_122 ;
return V_104 ;
}
struct V_4 * F_78 ( struct V_123 * V_124 , int V_100 , T_5 V_45 )
{
struct V_102 V_103 ;
int V_125 = F_76 ( V_100 , V_45 , & V_103 ) ;
return F_79 ( V_126 , V_124 , & V_103 , V_125 ) ;
}
struct V_4 * F_80 ( const char * V_123 , int V_100 , T_5 V_45 )
{
struct V_123 V_124 = { . V_124 = V_123 } ;
return F_78 ( & V_124 , V_100 , V_45 ) ;
}
struct V_4 * F_81 ( struct V_1 * V_1 , struct V_72 * V_25 ,
const char * V_123 , int V_100 )
{
struct V_102 V_103 ;
int V_125 = F_76 ( V_100 , 0 , & V_103 ) ;
if ( V_100 & V_92 )
return F_73 ( - V_9 ) ;
if ( ! V_123 && ( V_100 & V_111 ) )
if ( ! V_1 -> V_16 -> V_127 -> V_125 )
return F_73 ( - V_128 ) ;
return F_82 ( V_1 , V_25 , V_123 , & V_103 , V_125 ) ;
}
long F_83 ( int V_129 , const char T_2 * V_123 , int V_100 , T_5 V_45 )
{
struct V_102 V_103 ;
int V_125 = F_76 ( V_100 , V_45 , & V_103 ) ;
struct V_123 * V_130 = F_84 ( V_123 ) ;
int V_31 = F_85 ( V_130 ) ;
if ( ! F_86 ( V_130 ) ) {
V_31 = F_87 ( V_100 ) ;
if ( V_31 >= 0 ) {
struct V_4 * V_33 = F_79 ( V_129 , V_130 , & V_103 , V_125 ) ;
if ( F_86 ( V_33 ) ) {
F_88 ( V_31 ) ;
V_31 = F_85 ( V_33 ) ;
} else {
F_89 ( V_33 ) ;
F_90 ( V_31 , V_33 ) ;
}
}
F_91 ( V_130 ) ;
}
return V_31 ;
}
int F_92 ( struct V_4 * V_5 , T_10 V_131 )
{
int V_132 = 0 ;
if ( ! F_93 ( V_5 ) ) {
F_94 ( V_133 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_55 && V_5 -> V_55 -> V_134 )
V_132 = V_5 -> V_55 -> V_134 ( V_5 , V_131 ) ;
if ( F_95 ( ! ( V_5 -> V_38 & V_85 ) ) ) {
F_96 ( V_5 , V_131 ) ;
F_97 ( V_5 , V_131 ) ;
}
F_74 ( V_5 ) ;
return V_132 ;
}
int F_98 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_35 & V_36 ) && F_99 ( V_20 ) > V_41 )
return - V_135 ;
return 0 ;
}
int F_100 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
V_5 -> V_38 &= ~ ( V_81 | V_82 | V_83 ) ;
return 0 ;
}
