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
error = F_37 ( V_19 , V_43 ) ;
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
T_8 V_62 ;
T_9 V_63 ;
V_62 = F_39 ( F_40 () , V_60 ) ;
V_63 = F_41 ( F_40 () , V_61 ) ;
V_8 . V_11 = V_42 ;
if ( V_60 != ( T_6 ) - 1 ) {
if ( ! F_42 ( V_62 ) )
return - V_9 ;
V_8 . V_11 |= V_64 ;
V_8 . V_65 = V_62 ;
}
if ( V_61 != ( T_7 ) - 1 ) {
if ( ! F_43 ( V_63 ) )
return - V_9 ;
V_8 . V_11 |= V_66 ;
V_8 . V_67 = V_63 ;
}
if ( ! F_8 ( V_20 -> V_23 ) )
V_8 . V_11 |=
V_68 | V_69 | V_70 ;
F_3 ( & V_20 -> V_17 ) ;
error = F_44 ( V_19 , V_60 , V_61 ) ;
if ( ! error )
error = F_4 ( V_19 -> V_1 , & V_8 ) ;
F_5 ( & V_20 -> V_17 ) ;
return error ;
}
static inline int F_45 ( struct V_20 * V_20 ,
struct V_71 * V_25 )
{
int error ;
error = F_13 ( V_20 ) ;
if ( error )
return error ;
if ( ! F_46 ( V_20 -> V_23 ) ) {
error = F_10 ( V_25 ) ;
if ( error )
F_17 ( V_20 ) ;
}
return error ;
}
int F_47 ( struct V_4 * V_72 )
{
if ( V_72 -> V_34 & V_73 ) {
if ( ! V_72 -> V_74 -> V_75 ||
( ( ! V_72 -> V_74 -> V_75 -> V_76 ) &&
( ! V_72 -> V_74 -> V_75 -> V_77 ) ) ) {
return - V_9 ;
}
}
return 0 ;
}
static struct V_4 * F_48 ( struct V_1 * V_1 , struct V_71 * V_25 ,
struct V_4 * V_72 ,
int (* F_49)( struct V_20 * , struct V_4 * ) ,
const struct V_78 * V_78 )
{
static const struct V_79 V_80 = {} ;
struct V_20 * V_20 ;
int error ;
V_72 -> V_37 = F_50 ( V_72 -> V_34 ) | V_81 |
V_82 | V_83 ;
if ( F_51 ( V_72 -> V_34 & V_84 ) )
V_72 -> V_37 = V_85 ;
V_20 = V_1 -> V_16 ;
if ( V_72 -> V_37 & V_38 ) {
error = F_45 ( V_20 , V_25 ) ;
if ( error )
goto V_86;
if ( ! F_46 ( V_20 -> V_23 ) )
F_52 ( V_72 ) ;
}
V_72 -> V_74 = V_20 -> V_87 ;
V_72 -> V_36 . V_1 = V_1 ;
V_72 -> V_36 . V_25 = V_25 ;
V_72 -> V_88 = 0 ;
F_53 ( V_72 , V_20 -> V_51 ) ;
if ( F_51 ( V_72 -> V_37 & V_85 ) ) {
V_72 -> V_54 = & V_80 ;
return V_72 ;
}
V_72 -> V_54 = F_54 ( V_20 -> V_89 ) ;
error = F_55 ( V_72 , V_78 ) ;
if ( error )
goto V_90;
error = F_14 ( V_20 , V_72 -> V_34 ) ;
if ( error )
goto V_90;
if ( ! F_49 && V_72 -> V_54 )
F_49 = V_72 -> V_54 -> F_49 ;
if ( F_49 ) {
error = F_49 ( V_20 , V_72 ) ;
if ( error )
goto V_90;
}
if ( ( V_72 -> V_37 & ( V_91 | V_38 ) ) == V_91 )
F_56 ( V_20 ) ;
V_72 -> V_34 &= ~ ( V_92 | V_93 | V_94 | V_95 ) ;
F_57 ( & V_72 -> V_96 , V_72 -> V_74 -> V_97 -> V_87 ) ;
return V_72 ;
V_90:
F_58 ( V_72 -> V_54 ) ;
if ( V_72 -> V_37 & V_38 ) {
F_17 ( V_20 ) ;
if ( ! F_46 ( V_20 -> V_23 ) ) {
F_59 ( V_72 ) ;
F_18 ( V_25 ) ;
}
}
F_60 ( V_72 ) ;
V_72 -> V_36 . V_1 = NULL ;
V_72 -> V_36 . V_25 = NULL ;
V_86:
F_61 ( V_1 ) ;
F_62 ( V_25 ) ;
return F_63 ( error ) ;
}
static struct V_4 * F_64 ( struct V_1 * V_1 , struct V_71 * V_25 ,
struct V_4 * V_72 ,
int (* F_49)( struct V_20 * , struct V_4 * ) ,
const struct V_78 * V_78 )
{
struct V_4 * V_98 = F_48 ( V_1 , V_25 , V_72 , F_49 , V_78 ) ;
if ( ! F_65 ( V_98 ) ) {
int error = F_47 ( V_72 ) ;
if ( error ) {
F_22 ( V_98 ) ;
V_98 = F_63 ( error ) ;
}
} else {
F_66 ( V_72 ) ;
}
return V_98 ;
}
struct V_4 * F_67 ( struct V_99 * V_100 , struct V_1 * V_1 ,
int (* F_49)( struct V_20 * , struct V_4 * ) )
{
const struct V_78 * V_78 = F_68 () ;
if ( F_65 ( V_100 -> V_101 . F_49 . V_4 ) )
goto V_21;
if ( F_65 ( V_1 ) )
goto V_102;
V_100 -> V_101 . F_49 . V_4 = F_64 ( F_69 ( V_1 ) , F_70 ( V_100 -> V_19 . V_25 ) ,
V_100 -> V_101 . F_49 . V_4 ,
F_49 , V_78 ) ;
V_21:
return V_100 -> V_101 . F_49 . V_4 ;
V_102:
F_71 ( V_100 ) ;
V_100 -> V_101 . F_49 . V_4 = F_72 ( V_1 ) ;
goto V_21;
}
struct V_4 * F_73 ( struct V_99 * V_100 )
{
const struct V_78 * V_78 = F_68 () ;
struct V_4 * V_5 ;
V_5 = V_100 -> V_101 . F_49 . V_4 ;
if ( V_5 -> V_36 . V_1 != NULL ) {
V_100 -> V_101 . F_49 . V_4 = NULL ;
} else {
struct V_4 * V_98 ;
F_74 ( & V_100 -> V_19 ) ;
V_98 = F_48 ( V_100 -> V_19 . V_1 , V_100 -> V_19 . V_25 ,
V_5 , NULL , V_78 ) ;
if ( ! F_65 ( V_98 ) ) {
int error ;
V_100 -> V_101 . F_49 . V_4 = NULL ;
F_75 ( V_98 != V_5 ) ;
error = F_47 ( V_5 ) ;
if ( error ) {
F_22 ( V_5 ) ;
V_5 = F_63 ( error ) ;
}
} else {
V_5 = V_98 ;
}
}
return V_5 ;
}
struct V_4 * F_76 ( struct V_1 * V_1 , struct V_71 * V_25 , int V_103 ,
const struct V_78 * V_78 )
{
int error ;
struct V_4 * V_72 ;
F_77 ( V_78 ) ;
F_75 ( ! V_25 ) ;
error = - V_104 ;
V_72 = F_78 () ;
if ( V_72 == NULL ) {
F_61 ( V_1 ) ;
F_62 ( V_25 ) ;
return F_63 ( error ) ;
}
V_72 -> V_34 = V_103 ;
return F_64 ( V_1 , V_25 , V_72 , NULL , V_78 ) ;
}
static void F_79 ( struct V_105 * V_106 , unsigned int V_31 )
{
struct V_107 * V_108 = F_80 ( V_106 ) ;
F_81 ( V_31 , V_108 ) ;
if ( V_31 < V_106 -> V_109 )
V_106 -> V_109 = V_31 ;
}
void F_82 ( unsigned int V_31 )
{
struct V_105 * V_106 = V_110 -> V_106 ;
F_83 ( & V_106 -> V_111 ) ;
F_79 ( V_106 , V_31 ) ;
F_84 ( & V_106 -> V_111 ) ;
}
void F_85 ( unsigned int V_31 , struct V_4 * V_4 )
{
struct V_105 * V_106 = V_110 -> V_106 ;
struct V_107 * V_108 ;
F_83 ( & V_106 -> V_111 ) ;
V_108 = F_80 ( V_106 ) ;
F_75 ( V_108 -> V_31 [ V_31 ] != NULL ) ;
F_86 ( V_108 -> V_31 [ V_31 ] , V_4 ) ;
F_84 ( & V_106 -> V_111 ) ;
}
static inline int F_87 ( int V_103 , T_5 V_43 , struct V_112 * V_113 )
{
int V_114 = 0 ;
int V_115 ;
if ( ! ( V_103 & V_92 ) )
V_43 = 0 ;
V_113 -> V_43 = V_43 ;
V_103 &= ~ V_116 ;
if ( V_103 & V_117 )
V_103 |= V_118 ;
if ( V_103 & V_84 ) {
V_103 &= V_119 | V_120 | V_84 ;
V_115 = 0 ;
} else {
V_115 = V_121 | F_88 ( V_103 ) ;
}
V_113 -> V_122 = V_103 ;
if ( V_103 & V_95 )
V_115 |= V_26 ;
if ( V_103 & V_123 )
V_115 |= V_124 ;
V_113 -> V_115 = V_115 ;
V_113 -> V_101 = V_103 & V_84 ? 0 : V_125 ;
if ( V_103 & V_92 ) {
V_113 -> V_101 |= V_126 ;
if ( V_103 & V_93 )
V_113 -> V_101 |= V_127 ;
}
if ( V_103 & V_119 )
V_114 |= V_128 ;
if ( ! ( V_103 & V_120 ) )
V_114 |= V_129 ;
return V_114 ;
}
struct V_4 * F_89 ( const char * V_130 , int V_103 , T_5 V_43 )
{
struct V_112 V_113 ;
int V_131 = F_87 ( V_103 , V_43 , & V_113 ) ;
return F_90 ( V_132 , V_130 , & V_113 , V_131 ) ;
}
struct V_4 * F_91 ( struct V_1 * V_1 , struct V_71 * V_25 ,
const char * V_130 , int V_103 )
{
struct V_112 V_113 ;
int V_131 = F_87 ( V_103 , 0 , & V_113 ) ;
if ( V_103 & V_92 )
return F_63 ( - V_9 ) ;
if ( ! V_130 && ( V_103 & V_119 ) )
if ( ! V_1 -> V_16 -> V_133 -> V_131 )
return F_63 ( - V_134 ) ;
return F_92 ( V_1 , V_25 , V_130 , & V_113 , V_131 ) ;
}
long F_93 ( int V_135 , const char T_2 * V_130 , int V_103 , T_5 V_43 )
{
struct V_112 V_113 ;
int V_131 = F_87 ( V_103 , V_43 , & V_113 ) ;
char * V_136 = F_94 ( V_130 ) ;
int V_31 = F_95 ( V_136 ) ;
if ( ! F_65 ( V_136 ) ) {
V_31 = F_96 ( V_103 ) ;
if ( V_31 >= 0 ) {
struct V_4 * V_72 = F_90 ( V_135 , V_136 , & V_113 , V_131 ) ;
if ( F_65 ( V_72 ) ) {
F_82 ( V_31 ) ;
V_31 = F_95 ( V_72 ) ;
} else {
F_97 ( V_72 ) ;
F_85 ( V_31 , V_72 ) ;
}
}
F_98 ( V_136 ) ;
}
return V_31 ;
}
int F_99 ( struct V_4 * V_5 , T_10 V_137 )
{
int V_138 = 0 ;
if ( ! F_100 ( V_5 ) ) {
F_101 ( V_139 L_1 ) ;
return 0 ;
}
if ( V_5 -> V_54 && V_5 -> V_54 -> V_140 )
V_138 = V_5 -> V_54 -> V_140 ( V_5 , V_137 ) ;
if ( F_102 ( ! ( V_5 -> V_37 & V_85 ) ) ) {
F_103 ( V_5 , V_137 ) ;
F_104 ( V_5 , V_137 ) ;
}
F_22 ( V_5 ) ;
return V_138 ;
}
int F_105 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_34 & V_35 ) && F_106 ( V_20 ) > V_40 )
return - V_141 ;
return 0 ;
}
int F_107 ( struct V_20 * V_20 , struct V_4 * V_5 )
{
V_5 -> V_37 &= ~ ( V_81 | V_82 | V_83 ) ;
return 0 ;
}
