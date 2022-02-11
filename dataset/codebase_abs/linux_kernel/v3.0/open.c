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
static int F_36 ( struct V_19 * V_19 , T_5 V_56 , T_6 V_57 )
{
struct V_20 * V_20 = V_19 -> V_1 -> V_16 ;
int error ;
struct V_7 V_8 ;
V_8 . V_11 = V_42 ;
if ( V_56 != ( T_5 ) - 1 ) {
V_8 . V_11 |= V_58 ;
V_8 . V_59 = V_56 ;
}
if ( V_57 != ( T_6 ) - 1 ) {
V_8 . V_11 |= V_60 ;
V_8 . V_61 = V_57 ;
}
if ( ! F_8 ( V_20 -> V_23 ) )
V_8 . V_11 |=
V_62 | V_63 | V_64 ;
F_3 ( & V_20 -> V_17 ) ;
error = F_37 ( V_19 , V_56 , V_57 ) ;
if ( ! error )
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
F_5 ( & V_20 -> V_17 ) ;
return error ;
}
static inline int F_38 ( struct V_20 * V_20 ,
struct V_65 * V_25 )
{
int error ;
error = F_13 ( V_20 ) ;
if ( error )
return error ;
if ( ! F_39 ( V_20 -> V_23 ) ) {
error = F_10 ( V_25 ) ;
if ( error )
F_17 ( V_20 ) ;
}
return error ;
}
static struct V_4 * F_40 ( struct V_1 * V_1 , struct V_65 * V_25 ,
struct V_4 * V_66 ,
int (* F_41)( struct V_20 * , struct V_4 * ) ,
const struct V_67 * V_67 )
{
static const struct V_68 V_69 = {} ;
struct V_20 * V_20 ;
int error ;
V_66 -> V_37 = F_42 ( V_66 -> V_34 ) | V_70 |
V_71 | V_72 ;
if ( F_43 ( V_66 -> V_34 & V_73 ) )
V_66 -> V_37 = V_74 ;
V_20 = V_1 -> V_16 ;
if ( V_66 -> V_37 & V_38 ) {
error = F_38 ( V_20 , V_25 ) ;
if ( error )
goto V_75;
if ( ! F_39 ( V_20 -> V_23 ) )
F_44 ( V_66 ) ;
}
V_66 -> V_76 = V_20 -> V_77 ;
V_66 -> V_36 . V_1 = V_1 ;
V_66 -> V_36 . V_25 = V_25 ;
V_66 -> V_78 = 0 ;
F_45 ( V_66 , V_20 -> V_51 ) ;
if ( F_43 ( V_66 -> V_37 & V_74 ) ) {
V_66 -> V_54 = & V_69 ;
return V_66 ;
}
V_66 -> V_54 = F_46 ( V_20 -> V_79 ) ;
error = F_47 ( V_66 , V_67 ) ;
if ( error )
goto V_80;
if ( ! F_41 && V_66 -> V_54 )
F_41 = V_66 -> V_54 -> F_41 ;
if ( F_41 ) {
error = F_41 ( V_20 , V_66 ) ;
if ( error )
goto V_80;
}
if ( ( V_66 -> V_37 & ( V_81 | V_38 ) ) == V_81 )
F_48 ( V_20 ) ;
V_66 -> V_34 &= ~ ( V_82 | V_83 | V_84 | V_85 ) ;
F_49 ( & V_66 -> V_86 , V_66 -> V_76 -> V_87 -> V_77 ) ;
if ( V_66 -> V_34 & V_88 ) {
if ( ! V_66 -> V_76 -> V_89 ||
( ( ! V_66 -> V_76 -> V_89 -> V_90 ) &&
( ! V_66 -> V_76 -> V_89 -> V_91 ) ) ) {
F_22 ( V_66 ) ;
V_66 = F_50 ( - V_9 ) ;
}
}
return V_66 ;
V_80:
F_51 ( V_66 -> V_54 ) ;
if ( V_66 -> V_37 & V_38 ) {
F_17 ( V_20 ) ;
if ( ! F_39 ( V_20 -> V_23 ) ) {
F_52 ( V_66 ) ;
F_18 ( V_25 ) ;
}
}
F_53 ( V_66 ) ;
V_66 -> V_36 . V_1 = NULL ;
V_66 -> V_36 . V_25 = NULL ;
V_75:
F_54 ( V_66 ) ;
F_55 ( V_1 ) ;
F_56 ( V_25 ) ;
return F_50 ( error ) ;
}
struct V_4 * F_57 ( struct V_92 * V_93 , struct V_1 * V_1 ,
int (* F_41)( struct V_20 * , struct V_4 * ) )
{
const struct V_67 * V_67 = F_58 () ;
if ( F_59 ( V_93 -> V_94 . F_41 . V_4 ) )
goto V_21;
if ( F_59 ( V_1 ) )
goto V_95;
V_93 -> V_94 . F_41 . V_4 = F_40 ( F_60 ( V_1 ) , F_61 ( V_93 -> V_19 . V_25 ) ,
V_93 -> V_94 . F_41 . V_4 ,
F_41 , V_67 ) ;
V_21:
return V_93 -> V_94 . F_41 . V_4 ;
V_95:
F_62 ( V_93 ) ;
V_93 -> V_94 . F_41 . V_4 = (struct V_4 * ) V_1 ;
goto V_21;
}
struct V_4 * F_63 ( struct V_92 * V_93 )
{
const struct V_67 * V_67 = F_58 () ;
struct V_4 * V_5 ;
V_5 = V_93 -> V_94 . F_41 . V_4 ;
V_93 -> V_94 . F_41 . V_4 = NULL ;
if ( V_5 -> V_36 . V_1 == NULL ) {
F_64 ( & V_93 -> V_19 ) ;
V_5 = F_40 ( V_93 -> V_19 . V_1 , V_93 -> V_19 . V_25 , V_5 ,
NULL , V_67 ) ;
}
return V_5 ;
}
struct V_4 * F_65 ( struct V_1 * V_1 , struct V_65 * V_25 , int V_96 ,
const struct V_67 * V_67 )
{
int error ;
struct V_4 * V_66 ;
F_66 ( V_67 ) ;
F_67 ( ! V_25 ) ;
error = - V_97 ;
V_66 = F_68 () ;
if ( V_66 == NULL ) {
F_55 ( V_1 ) ;
F_56 ( V_25 ) ;
return F_50 ( error ) ;
}
V_66 -> V_34 = V_96 ;
return F_40 ( V_1 , V_25 , V_66 , NULL , V_67 ) ;
}
static void F_69 ( struct V_98 * V_99 , unsigned int V_31 )
{
struct V_100 * V_101 = F_70 ( V_99 ) ;
F_71 ( V_31 , V_101 -> V_102 ) ;
if ( V_31 < V_99 -> V_103 )
V_99 -> V_103 = V_31 ;
}
void F_72 ( unsigned int V_31 )
{
struct V_98 * V_99 = V_104 -> V_99 ;
F_73 ( & V_99 -> V_105 ) ;
F_69 ( V_99 , V_31 ) ;
F_74 ( & V_99 -> V_105 ) ;
}
void F_75 ( unsigned int V_31 , struct V_4 * V_4 )
{
struct V_98 * V_99 = V_104 -> V_99 ;
struct V_100 * V_101 ;
F_73 ( & V_99 -> V_105 ) ;
V_101 = F_70 ( V_99 ) ;
F_67 ( V_101 -> V_31 [ V_31 ] != NULL ) ;
F_76 ( V_101 -> V_31 [ V_31 ] , V_4 ) ;
F_74 ( & V_99 -> V_105 ) ;
}
static inline int F_77 ( int V_96 , int V_43 , struct V_106 * V_107 )
{
int V_108 = 0 ;
int V_109 ;
if ( ! ( V_96 & V_82 ) )
V_43 = 0 ;
V_107 -> V_43 = V_43 ;
V_96 &= ~ V_110 ;
if ( V_96 & V_111 )
V_96 |= V_112 ;
if ( V_96 & V_73 ) {
V_96 &= V_113 | V_114 | V_73 ;
V_109 = 0 ;
} else {
V_109 = V_115 | F_78 ( V_96 ) ;
}
V_107 -> V_116 = V_96 ;
if ( V_96 & V_85 )
V_109 |= V_26 ;
if ( V_96 & V_117 )
V_109 |= V_118 ;
V_107 -> V_109 = V_109 ;
V_107 -> V_94 = V_96 & V_73 ? 0 : V_119 ;
if ( V_96 & V_82 ) {
V_107 -> V_94 |= V_120 ;
if ( V_96 & V_83 )
V_107 -> V_94 |= V_121 ;
}
if ( V_96 & V_113 )
V_108 |= V_122 ;
if ( ! ( V_96 & V_114 ) )
V_108 |= V_123 ;
return V_108 ;
}
struct V_4 * F_79 ( const char * V_124 , int V_96 , int V_43 )
{
struct V_106 V_107 ;
int V_125 = F_77 ( V_96 , V_43 , & V_107 ) ;
return F_80 ( V_126 , V_124 , & V_107 , V_125 ) ;
}
struct V_4 * F_81 ( struct V_1 * V_1 , struct V_65 * V_25 ,
const char * V_124 , int V_96 )
{
struct V_106 V_107 ;
int V_125 = F_77 ( V_96 , 0 , & V_107 ) ;
if ( V_96 & V_82 )
return F_50 ( - V_9 ) ;
if ( ! V_124 && ( V_96 & V_113 ) )
if ( ! V_1 -> V_16 -> V_127 -> V_125 )
return F_50 ( - V_128 ) ;
return F_82 ( V_1 , V_25 , V_124 , & V_107 , V_125 ) ;
}
long F_83 ( int V_129 , const char T_2 * V_124 , int V_96 , int V_43 )
{
struct V_106 V_107 ;
int V_125 = F_77 ( V_96 , V_43 , & V_107 ) ;
char * V_130 = F_84 ( V_124 ) ;
int V_31 = F_85 ( V_130 ) ;
if ( ! F_59 ( V_130 ) ) {
V_31 = F_86 ( V_96 ) ;
if ( V_31 >= 0 ) {
struct V_4 * V_66 = F_80 ( V_129 , V_130 , & V_107 , V_125 ) ;
if ( F_59 ( V_66 ) ) {
F_72 ( V_31 ) ;
V_31 = F_85 ( V_66 ) ;
} else {
F_87 ( V_66 ) ;
F_75 ( V_31 , V_66 ) ;
}
}
F_88 ( V_130 ) ;
}
return V_31 ;
}
int F_89 ( struct V_4 * V_5 , T_7 V_131 )
{
int V_132 = 0 ;
if ( ! F_90 ( V_5 ) ) {
F_91 ( V_133 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_54 && V_5 -> V_54 -> V_134 )
V_132 = V_5 -> V_54 -> V_134 ( V_5 , V_131 ) ;
if ( F_92 ( ! ( V_5 -> V_37 & V_74 ) ) ) {
F_93 ( V_5 , V_131 ) ;
F_94 ( V_5 , V_131 ) ;
}
F_22 ( V_5 ) ;
return V_132 ;
}
int F_95 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_34 & V_35 ) && F_96 ( V_20 ) > V_40 )
return - V_135 ;
return 0 ;
}
int F_97 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
V_5 -> V_37 &= ~ ( V_70 | V_71 | V_72 ) ;
return 0 ;
}
