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
struct V_4 * V_4 ;
int error ;
error = - V_9 ;
if ( V_2 < 0 )
goto V_21;
error = - V_33 ;
V_4 = F_21 ( V_31 ) ;
if ( ! V_4 )
goto V_21;
if ( V_4 -> V_34 & V_35 )
V_32 = 0 ;
V_1 = V_4 -> V_36 . V_1 ;
V_20 = V_1 -> V_16 ;
error = - V_9 ;
if ( ! F_9 ( V_20 -> V_23 ) || ! ( V_4 -> V_37 & V_38 ) )
goto V_39;
error = - V_9 ;
if ( V_32 && V_2 > V_40 )
goto V_39;
error = - V_28 ;
if ( F_12 ( V_20 ) )
goto V_39;
error = F_15 ( V_20 , V_4 , V_2 ) ;
if ( ! error )
error = F_16 ( & V_4 -> V_36 ) ;
if ( ! error )
error = F_1 ( V_1 , V_2 , V_41 | V_42 , V_4 ) ;
V_39:
F_22 ( V_4 ) ;
V_21:
return error ;
}
T_3 (F_23)( const char T_2 * V_19 , T_1 V_2 )
{
return F_6 ( V_19 , V_2 ) ;
}
T_4 long F_24 ( long V_19 , T_1 V_2 )
{
return F_25 ( ( const char T_2 * ) V_19 , V_2 ) ;
}
T_3 (F_26)( unsigned int V_31 , T_1 V_2 )
{
long V_6 = F_20 ( V_31 , V_2 , 0 ) ;
F_27 ( 2 , V_6 , V_31 , V_2 ) ;
return V_6 ;
}
T_4 long F_28 ( long V_31 , T_1 V_2 )
{
return F_29 ( ( unsigned int ) V_31 , V_2 ) ;
}
int F_30 ( struct V_4 * V_4 , int V_43 , T_1 V_44 , T_1 V_45 )
{
struct V_20 * V_20 = V_4 -> V_36 . V_1 -> V_16 ;
long V_6 ;
if ( V_44 < 0 || V_45 <= 0 )
return - V_9 ;
if ( V_43 & ~ ( V_46 | V_47 ) )
return - V_48 ;
if ( ( V_43 & V_47 ) &&
! ( V_43 & V_46 ) )
return - V_48 ;
if ( ! ( V_4 -> V_37 & V_38 ) )
return - V_33 ;
if ( V_43 & V_47 && F_12 ( V_20 ) )
return - V_28 ;
if ( F_31 ( V_20 ) )
return - V_28 ;
V_6 = F_32 ( V_4 , V_26 ) ;
if ( V_6 )
return V_6 ;
if ( F_33 ( V_20 -> V_23 ) )
return - V_49 ;
if ( ! F_9 ( V_20 -> V_23 ) && ! F_8 ( V_20 -> V_23 ) )
return - V_50 ;
if ( ( ( V_44 + V_45 ) > V_20 -> V_51 -> V_52 ) || ( ( V_44 + V_45 ) < 0 ) )
return - V_53 ;
if ( ! V_4 -> V_54 -> V_55 )
return - V_48 ;
return V_4 -> V_54 -> V_55 ( V_4 , V_43 , V_44 , V_45 ) ;
}
T_3 (V_55)( int V_31 , int V_43 , T_1 V_44 , T_1 V_45 )
{
struct V_4 * V_4 ;
int error = - V_33 ;
V_4 = F_21 ( V_31 ) ;
if ( V_4 ) {
error = F_30 ( V_4 , V_43 , V_44 , V_45 ) ;
F_22 ( V_4 ) ;
}
return error ;
}
T_4 long F_34 ( long V_31 , long V_43 , T_1 V_44 , T_1 V_45 )
{
return F_35 ( ( int ) V_31 , ( int ) V_43 , V_44 , V_45 ) ;
}
static int F_36 ( struct V_19 * V_19 , T_5 V_43 )
{
struct V_20 * V_20 = V_19 -> V_1 -> V_16 ;
struct V_7 V_8 ;
int error ;
error = F_10 ( V_19 -> V_25 ) ;
if ( error )
return error ;
F_3 ( & V_20 -> V_17 ) ;
error = F_37 ( V_19 -> V_1 , V_19 -> V_25 , V_43 ) ;
if ( error )
goto V_56;
V_8 . V_57 = ( V_43 & V_58 ) | ( V_20 -> V_23 & ~ V_58 ) ;
V_8 . V_11 = V_59 | V_42 ;
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
V_56:
F_5 ( & V_20 -> V_17 ) ;
F_18 ( V_19 -> V_25 ) ;
return error ;
}
static int F_38 ( struct V_19 * V_19 , T_6 V_60 , T_7 V_61 )
{
struct V_20 * V_20 = V_19 -> V_1 -> V_16 ;
int error ;
struct V_7 V_8 ;
V_8 . V_11 = V_42 ;
if ( V_60 != ( T_6 ) - 1 ) {
V_8 . V_11 |= V_62 ;
V_8 . V_63 = V_60 ;
}
if ( V_61 != ( T_7 ) - 1 ) {
V_8 . V_11 |= V_64 ;
V_8 . V_65 = V_61 ;
}
if ( ! F_8 ( V_20 -> V_23 ) )
V_8 . V_11 |=
V_66 | V_67 | V_68 ;
F_3 ( & V_20 -> V_17 ) ;
error = F_39 ( V_19 , V_60 , V_61 ) ;
if ( ! error )
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
F_5 ( & V_20 -> V_17 ) ;
return error ;
}
static inline int F_40 ( struct V_20 * V_20 ,
struct V_69 * V_25 )
{
int error ;
error = F_13 ( V_20 ) ;
if ( error )
return error ;
if ( ! F_41 ( V_20 -> V_23 ) ) {
error = F_10 ( V_25 ) ;
if ( error )
F_17 ( V_20 ) ;
}
return error ;
}
static struct V_4 * F_42 ( struct V_1 * V_1 , struct V_69 * V_25 ,
struct V_4 * V_70 ,
int (* F_43)( struct V_20 * , struct V_4 * ) ,
const struct V_71 * V_71 )
{
static const struct V_72 V_73 = {} ;
struct V_20 * V_20 ;
int error ;
V_70 -> V_37 = F_44 ( V_70 -> V_34 ) | V_74 |
V_75 | V_76 ;
if ( F_45 ( V_70 -> V_34 & V_77 ) )
V_70 -> V_37 = V_78 ;
V_20 = V_1 -> V_16 ;
if ( V_70 -> V_37 & V_38 ) {
error = F_40 ( V_20 , V_25 ) ;
if ( error )
goto V_79;
if ( ! F_41 ( V_20 -> V_23 ) )
F_46 ( V_70 ) ;
}
V_70 -> V_80 = V_20 -> V_81 ;
V_70 -> V_36 . V_1 = V_1 ;
V_70 -> V_36 . V_25 = V_25 ;
V_70 -> V_82 = 0 ;
F_47 ( V_70 , V_20 -> V_51 ) ;
if ( F_45 ( V_70 -> V_37 & V_78 ) ) {
V_70 -> V_54 = & V_73 ;
return V_70 ;
}
V_70 -> V_54 = F_48 ( V_20 -> V_83 ) ;
error = F_49 ( V_70 , V_71 ) ;
if ( error )
goto V_84;
if ( ! F_43 && V_70 -> V_54 )
F_43 = V_70 -> V_54 -> F_43 ;
if ( F_43 ) {
error = F_43 ( V_20 , V_70 ) ;
if ( error )
goto V_84;
}
if ( ( V_70 -> V_37 & ( V_85 | V_38 ) ) == V_85 )
F_50 ( V_20 ) ;
V_70 -> V_34 &= ~ ( V_86 | V_87 | V_88 | V_89 ) ;
F_51 ( & V_70 -> V_90 , V_70 -> V_80 -> V_91 -> V_81 ) ;
if ( V_70 -> V_34 & V_92 ) {
if ( ! V_70 -> V_80 -> V_93 ||
( ( ! V_70 -> V_80 -> V_93 -> V_94 ) &&
( ! V_70 -> V_80 -> V_93 -> V_95 ) ) ) {
F_22 ( V_70 ) ;
V_70 = F_52 ( - V_9 ) ;
}
}
return V_70 ;
V_84:
F_53 ( V_70 -> V_54 ) ;
if ( V_70 -> V_37 & V_38 ) {
F_17 ( V_20 ) ;
if ( ! F_41 ( V_20 -> V_23 ) ) {
F_54 ( V_70 ) ;
F_18 ( V_25 ) ;
}
}
F_55 ( V_70 ) ;
V_70 -> V_36 . V_1 = NULL ;
V_70 -> V_36 . V_25 = NULL ;
V_79:
F_56 ( V_70 ) ;
F_57 ( V_1 ) ;
F_58 ( V_25 ) ;
return F_52 ( error ) ;
}
struct V_4 * F_59 ( struct V_96 * V_97 , struct V_1 * V_1 ,
int (* F_43)( struct V_20 * , struct V_4 * ) )
{
const struct V_71 * V_71 = F_60 () ;
if ( F_61 ( V_97 -> V_98 . F_43 . V_4 ) )
goto V_21;
if ( F_61 ( V_1 ) )
goto V_99;
V_97 -> V_98 . F_43 . V_4 = F_42 ( F_62 ( V_1 ) , F_63 ( V_97 -> V_19 . V_25 ) ,
V_97 -> V_98 . F_43 . V_4 ,
F_43 , V_71 ) ;
V_21:
return V_97 -> V_98 . F_43 . V_4 ;
V_99:
F_64 ( V_97 ) ;
V_97 -> V_98 . F_43 . V_4 = F_65 ( V_1 ) ;
goto V_21;
}
struct V_4 * F_66 ( struct V_96 * V_97 )
{
const struct V_71 * V_71 = F_60 () ;
struct V_4 * V_5 ;
V_5 = V_97 -> V_98 . F_43 . V_4 ;
V_97 -> V_98 . F_43 . V_4 = NULL ;
if ( V_5 -> V_36 . V_1 == NULL ) {
F_67 ( & V_97 -> V_19 ) ;
V_5 = F_42 ( V_97 -> V_19 . V_1 , V_97 -> V_19 . V_25 , V_5 ,
NULL , V_71 ) ;
}
return V_5 ;
}
struct V_4 * F_68 ( struct V_1 * V_1 , struct V_69 * V_25 , int V_100 ,
const struct V_71 * V_71 )
{
int error ;
struct V_4 * V_70 ;
F_69 ( V_71 ) ;
F_70 ( ! V_25 ) ;
error = - V_101 ;
V_70 = F_71 () ;
if ( V_70 == NULL ) {
F_57 ( V_1 ) ;
F_58 ( V_25 ) ;
return F_52 ( error ) ;
}
V_70 -> V_34 = V_100 ;
return F_42 ( V_1 , V_25 , V_70 , NULL , V_71 ) ;
}
static void F_72 ( struct V_102 * V_103 , unsigned int V_31 )
{
struct V_104 * V_105 = F_73 ( V_103 ) ;
F_74 ( V_31 , V_105 -> V_106 ) ;
if ( V_31 < V_103 -> V_107 )
V_103 -> V_107 = V_31 ;
}
void F_75 ( unsigned int V_31 )
{
struct V_102 * V_103 = V_108 -> V_103 ;
F_76 ( & V_103 -> V_109 ) ;
F_72 ( V_103 , V_31 ) ;
F_77 ( & V_103 -> V_109 ) ;
}
void F_78 ( unsigned int V_31 , struct V_4 * V_4 )
{
struct V_102 * V_103 = V_108 -> V_103 ;
struct V_104 * V_105 ;
F_76 ( & V_103 -> V_109 ) ;
V_105 = F_73 ( V_103 ) ;
F_70 ( V_105 -> V_31 [ V_31 ] != NULL ) ;
F_79 ( V_105 -> V_31 [ V_31 ] , V_4 ) ;
F_77 ( & V_103 -> V_109 ) ;
}
static inline int F_80 ( int V_100 , int V_43 , struct V_110 * V_111 )
{
int V_112 = 0 ;
int V_113 ;
if ( ! ( V_100 & V_86 ) )
V_43 = 0 ;
V_111 -> V_43 = V_43 ;
V_100 &= ~ V_114 ;
if ( V_100 & V_115 )
V_100 |= V_116 ;
if ( V_100 & V_77 ) {
V_100 &= V_117 | V_118 | V_77 ;
V_113 = 0 ;
} else {
V_113 = V_119 | F_81 ( V_100 ) ;
}
V_111 -> V_120 = V_100 ;
if ( V_100 & V_89 )
V_113 |= V_26 ;
if ( V_100 & V_121 )
V_113 |= V_122 ;
V_111 -> V_113 = V_113 ;
V_111 -> V_98 = V_100 & V_77 ? 0 : V_123 ;
if ( V_100 & V_86 ) {
V_111 -> V_98 |= V_124 ;
if ( V_100 & V_87 )
V_111 -> V_98 |= V_125 ;
}
if ( V_100 & V_117 )
V_112 |= V_126 ;
if ( ! ( V_100 & V_118 ) )
V_112 |= V_127 ;
return V_112 ;
}
struct V_4 * F_82 ( const char * V_128 , int V_100 , int V_43 )
{
struct V_110 V_111 ;
int V_129 = F_80 ( V_100 , V_43 , & V_111 ) ;
return F_83 ( V_130 , V_128 , & V_111 , V_129 ) ;
}
struct V_4 * F_84 ( struct V_1 * V_1 , struct V_69 * V_25 ,
const char * V_128 , int V_100 )
{
struct V_110 V_111 ;
int V_129 = F_80 ( V_100 , 0 , & V_111 ) ;
if ( V_100 & V_86 )
return F_52 ( - V_9 ) ;
if ( ! V_128 && ( V_100 & V_117 ) )
if ( ! V_1 -> V_16 -> V_131 -> V_129 )
return F_52 ( - V_132 ) ;
return F_85 ( V_1 , V_25 , V_128 , & V_111 , V_129 ) ;
}
long F_86 ( int V_133 , const char T_2 * V_128 , int V_100 , int V_43 )
{
struct V_110 V_111 ;
int V_129 = F_80 ( V_100 , V_43 , & V_111 ) ;
char * V_134 = F_87 ( V_128 ) ;
int V_31 = F_88 ( V_134 ) ;
if ( ! F_61 ( V_134 ) ) {
V_31 = F_89 ( V_100 ) ;
if ( V_31 >= 0 ) {
struct V_4 * V_70 = F_83 ( V_133 , V_134 , & V_111 , V_129 ) ;
if ( F_61 ( V_70 ) ) {
F_75 ( V_31 ) ;
V_31 = F_88 ( V_70 ) ;
} else {
F_90 ( V_70 ) ;
F_78 ( V_31 , V_70 ) ;
}
}
F_91 ( V_134 ) ;
}
return V_31 ;
}
int F_92 ( struct V_4 * V_5 , T_8 V_135 )
{
int V_136 = 0 ;
if ( ! F_93 ( V_5 ) ) {
F_94 ( V_137 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_54 && V_5 -> V_54 -> V_138 )
V_136 = V_5 -> V_54 -> V_138 ( V_5 , V_135 ) ;
if ( F_95 ( ! ( V_5 -> V_37 & V_78 ) ) ) {
F_96 ( V_5 , V_135 ) ;
F_97 ( V_5 , V_135 ) ;
}
F_22 ( V_5 ) ;
return V_136 ;
}
int F_98 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_34 & V_35 ) && F_99 ( V_20 ) > V_40 )
return - V_139 ;
return 0 ;
}
int F_100 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
V_5 -> V_37 &= ~ ( V_74 | V_75 | V_76 ) ;
return 0 ;
}
