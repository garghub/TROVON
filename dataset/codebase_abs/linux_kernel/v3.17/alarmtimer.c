struct V_1 * F_1 ( void )
{
unsigned long V_2 ;
struct V_1 * V_3 ;
F_2 ( & V_4 , V_2 ) ;
V_3 = V_5 ;
F_3 ( & V_4 , V_2 ) ;
return V_3 ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
unsigned long V_2 ;
struct V_1 * V_10 = F_5 ( V_7 ) ;
if ( V_5 )
return - V_11 ;
if ( ! V_10 -> V_12 -> V_13 )
return - 1 ;
if ( ! F_6 ( V_10 -> V_7 . V_14 ) )
return - 1 ;
F_2 ( & V_4 , V_2 ) ;
if ( ! V_5 ) {
V_5 = V_10 ;
F_7 ( V_7 ) ;
}
F_3 ( & V_4 , V_2 ) ;
return 0 ;
}
static inline void F_8 ( void )
{
F_9 ( & V_15 , NULL , NULL ) ;
}
static int F_10 ( void )
{
V_16 . V_17 = V_18 ;
return F_11 ( & V_16 ) ;
}
static void F_12 ( void )
{
F_13 ( & V_16 ) ;
}
struct V_1 * F_1 ( void )
{
return NULL ;
}
static inline int F_10 ( void ) { return 0 ; }
static inline void F_12 ( void ) { }
static inline void F_8 ( void ) { }
static void F_14 ( struct V_19 * V_20 , struct V_21 * V_21 )
{
if ( V_21 -> V_22 & V_23 )
F_15 ( & V_20 -> V_24 , & V_21 -> V_25 ) ;
F_16 ( & V_20 -> V_24 , & V_21 -> V_25 ) ;
V_21 -> V_22 |= V_23 ;
}
static void F_17 ( struct V_19 * V_20 , struct V_21 * V_21 )
{
if ( ! ( V_21 -> V_22 & V_23 ) )
return;
F_15 ( & V_20 -> V_24 , & V_21 -> V_25 ) ;
V_21 -> V_22 &= ~ V_23 ;
}
static enum V_26 F_18 ( struct V_27 * V_28 )
{
struct V_21 * V_21 = F_19 ( V_28 , struct V_21 , V_28 ) ;
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 = V_30 ;
int V_31 = V_32 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
F_17 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
if ( V_21 -> V_34 )
V_31 = V_21 -> V_34 ( V_21 , V_20 -> V_35 () ) ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
if ( V_31 != V_32 ) {
F_20 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ) ;
F_14 ( V_20 , V_21 ) ;
V_3 = V_37 ;
}
F_3 ( & V_20 -> V_33 , V_2 ) ;
return V_3 ;
}
T_1 F_21 ( const struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_22 ( V_21 -> V_25 . V_36 , V_20 -> V_35 () ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_38 V_39 ;
T_1 V_40 , V_41 ;
unsigned long V_2 ;
struct V_1 * V_10 ;
int V_42 ;
int V_3 ;
F_2 ( & V_43 , V_2 ) ;
V_40 = V_44 ;
V_44 = F_24 ( 0 , 0 ) ;
F_3 ( & V_43 , V_2 ) ;
V_10 = F_1 () ;
if ( ! V_10 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
struct V_19 * V_20 = & V_29 [ V_42 ] ;
struct V_46 * V_47 ;
T_1 V_48 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_47 = F_25 ( & V_20 -> V_24 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
if ( ! V_47 )
continue;
V_48 = F_22 ( V_47 -> V_36 , V_20 -> V_35 () ) ;
if ( ! V_40 . V_49 || ( V_48 . V_49 < V_40 . V_49 ) )
V_40 = V_48 ;
}
if ( V_40 . V_49 == 0 )
return 0 ;
if ( F_26 ( V_40 ) < 2 * V_50 ) {
F_27 ( V_51 , 2 * V_52 ) ;
return - V_11 ;
}
F_28 ( V_10 , & V_15 ) ;
F_29 ( V_10 , & V_39 ) ;
V_41 = F_30 ( V_39 ) ;
V_41 = F_31 ( V_41 , V_40 ) ;
V_3 = F_32 ( V_10 , & V_15 , V_41 , F_24 ( 0 , 0 ) ) ;
if ( V_3 < 0 )
F_27 ( V_51 , V_52 ) ;
return V_3 ;
}
static int F_23 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_33 ( T_1 V_53 , enum V_54 type )
{
T_1 V_48 ;
unsigned long V_2 ;
struct V_19 * V_20 = & V_29 [ type ] ;
V_48 = F_22 ( V_53 , V_20 -> V_35 () ) ;
F_2 ( & V_43 , V_2 ) ;
if ( ! V_44 . V_49 || ( V_48 . V_49 < V_44 . V_49 ) )
V_44 = V_48 ;
F_3 ( & V_43 , V_2 ) ;
}
int F_34 ( struct V_21 * V_21 , T_1 V_55 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_21 -> V_25 . V_36 = V_55 ;
F_14 ( V_20 , V_21 ) ;
V_3 = F_35 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ,
V_56 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
return V_3 ;
}
int F_36 ( struct V_21 * V_21 , T_1 V_55 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
V_55 = F_31 ( V_55 , V_20 -> V_35 () ) ;
return F_34 ( V_21 , V_55 ) ;
}
void F_37 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
F_20 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ) ;
V_26 ( & V_21 -> V_28 ) ;
F_14 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
}
int F_38 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_3 = F_39 ( & V_21 -> V_28 ) ;
if ( V_3 >= 0 )
F_17 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
return V_3 ;
}
int F_40 ( struct V_21 * V_21 )
{
for (; ; ) {
int V_3 = F_38 ( V_21 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_41 () ;
}
}
T_2 F_42 ( struct V_21 * V_21 , T_1 V_41 , T_1 V_57 )
{
T_2 V_58 = 1 ;
T_1 V_48 ;
V_48 = F_22 ( V_41 , V_21 -> V_25 . V_36 ) ;
if ( V_48 . V_49 < 0 )
return 0 ;
if ( F_43 ( V_48 . V_49 >= V_57 . V_49 ) ) {
T_3 V_59 = F_26 ( V_57 ) ;
V_58 = F_44 ( V_48 , V_59 ) ;
V_21 -> V_25 . V_36 = F_45 ( V_21 -> V_25 . V_36 ,
V_59 * V_58 ) ;
if ( V_21 -> V_25 . V_36 . V_49 > V_41 . V_49 )
return V_58 ;
V_58 ++ ;
}
V_21 -> V_25 . V_36 = F_31 ( V_21 -> V_25 . V_36 , V_57 ) ;
return V_58 ;
}
T_2 F_46 ( struct V_21 * V_21 , T_1 V_57 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_42 ( V_21 , V_20 -> V_35 () , V_57 ) ;
}
static enum V_54 F_47 ( T_4 V_60 )
{
if ( V_60 == V_61 )
return V_62 ;
if ( V_60 == V_63 )
return V_64 ;
return - 1 ;
}
static enum V_65 F_48 ( struct V_21 * V_21 ,
T_1 V_41 )
{
unsigned long V_2 ;
struct V_66 * V_67 = F_19 ( V_21 , struct V_66 ,
V_68 . V_21 . V_69 ) ;
enum V_65 V_70 = V_32 ;
F_2 ( & V_67 -> V_71 , V_2 ) ;
if ( ( V_67 -> V_72 & ~ V_73 ) != V_74 ) {
if ( F_49 ( V_67 , 0 ) != 0 )
V_67 -> V_75 ++ ;
}
if ( V_67 -> V_68 . V_21 . V_57 . V_49 ) {
V_67 -> V_75 += F_42 ( V_21 , V_41 ,
V_67 -> V_68 . V_21 . V_57 ) ;
V_70 = V_76 ;
}
F_3 ( & V_67 -> V_71 , V_2 ) ;
return V_70 ;
}
static int F_50 ( const T_4 V_77 , struct V_78 * V_79 )
{
T_4 V_80 = V_29 [ F_47 ( V_77 ) ] . V_81 ;
if ( ! F_1 () )
return - V_82 ;
return F_51 ( V_80 , V_79 ) ;
}
static int F_52 ( T_4 V_77 , struct V_78 * V_79 )
{
struct V_19 * V_20 = & V_29 [ F_47 ( V_77 ) ] ;
if ( ! F_1 () )
return - V_82 ;
* V_79 = F_53 ( V_20 -> V_35 () ) ;
return 0 ;
}
static int F_54 ( struct V_66 * V_83 )
{
enum V_54 type ;
struct V_19 * V_20 ;
if ( ! F_1 () )
return - V_84 ;
if ( ! F_55 ( V_85 ) )
return - V_86 ;
type = F_47 ( V_83 -> V_87 ) ;
V_20 = & V_29 [ type ] ;
F_56 ( & V_83 -> V_68 . V_21 . V_69 , type , F_48 ) ;
return 0 ;
}
static void F_57 ( struct V_66 * V_88 ,
struct V_89 * V_90 )
{
T_1 V_91 =
F_21 ( & ( V_88 -> V_68 . V_21 . V_69 ) ) ;
if ( F_26 ( V_91 ) > 0 ) {
V_90 -> V_92 = F_53 ( V_91 ) ;
} else {
V_90 -> V_92 . V_93 = 0 ;
V_90 -> V_92 . V_94 = 0 ;
}
V_90 -> V_95 = F_53 ( V_88 -> V_68 . V_21 . V_57 ) ;
}
static int F_58 ( struct V_66 * V_88 )
{
if ( ! V_5 )
return - V_84 ;
if ( F_38 ( & V_88 -> V_68 . V_21 . V_69 ) < 0 )
return V_96 ;
return 0 ;
}
static int F_59 ( struct V_66 * V_88 , int V_2 ,
struct V_89 * V_97 ,
struct V_89 * V_98 )
{
T_1 exp ;
if ( ! V_5 )
return - V_84 ;
if ( V_2 & ~ V_99 )
return - V_82 ;
if ( V_98 )
F_57 ( V_88 , V_98 ) ;
if ( F_38 ( & V_88 -> V_68 . V_21 . V_69 ) < 0 )
return V_96 ;
V_88 -> V_68 . V_21 . V_57 = F_60 ( V_97 -> V_95 ) ;
exp = F_60 ( V_97 -> V_92 ) ;
if ( V_2 != V_99 ) {
T_1 V_41 ;
V_41 = V_29 [ V_88 -> V_68 . V_21 . V_69 . type ] . V_35 () ;
exp = F_31 ( V_41 , exp ) ;
}
F_34 ( & V_88 -> V_68 . V_21 . V_69 , exp ) ;
return 0 ;
}
static enum V_65 F_61 ( struct V_21 * V_21 ,
T_1 V_41 )
{
struct V_100 * V_101 = (struct V_100 * ) V_21 -> V_102 ;
V_21 -> V_102 = NULL ;
if ( V_101 )
F_62 ( V_101 ) ;
return V_32 ;
}
static int F_63 ( struct V_21 * V_21 , T_1 V_53 )
{
V_21 -> V_102 = ( void * ) V_103 ;
do {
F_64 ( V_104 ) ;
F_34 ( V_21 , V_53 ) ;
if ( F_65 ( V_21 -> V_102 ) )
F_66 () ;
F_40 ( V_21 ) ;
} while ( V_21 -> V_102 && ! F_67 ( V_103 ) );
F_68 ( V_105 ) ;
return ( V_21 -> V_102 == NULL ) ;
}
static int F_69 ( T_1 exp , enum V_54 type ,
struct V_78 T_5 * V_106 )
{
struct V_78 V_107 ;
T_1 V_108 ;
V_108 = F_22 ( exp , V_29 [ type ] . V_35 () ) ;
if ( V_108 . V_49 <= 0 )
return 0 ;
V_107 = F_53 ( V_108 ) ;
if ( F_70 ( V_106 , & V_107 , sizeof( * V_106 ) ) )
return - V_109 ;
return 1 ;
}
static long T_6 F_71 ( struct V_110 * V_31 )
{
enum V_54 type = V_31 -> V_111 . V_60 ;
T_1 exp ;
struct V_78 T_5 * V_106 ;
struct V_21 V_21 ;
int V_3 = 0 ;
exp . V_49 = V_31 -> V_111 . V_36 ;
F_56 ( & V_21 , type , F_61 ) ;
if ( F_63 ( & V_21 , exp ) )
goto V_112;
if ( F_72 ( V_103 ) )
F_33 ( exp , type ) ;
V_106 = V_31 -> V_111 . V_106 ;
if ( V_106 ) {
V_3 = F_69 ( exp , type , V_106 ) ;
if ( V_3 <= 0 )
goto V_112;
}
V_3 = - V_113 ;
V_112:
return V_3 ;
}
static int F_73 ( const T_4 V_77 , int V_2 ,
struct V_78 * V_114 , struct V_78 T_5 * V_106 )
{
enum V_54 type = F_47 ( V_77 ) ;
struct V_21 V_21 ;
T_1 exp ;
int V_3 = 0 ;
struct V_110 * V_31 ;
if ( ! F_1 () )
return - V_84 ;
if ( V_2 & ~ V_99 )
return - V_82 ;
if ( ! F_55 ( V_85 ) )
return - V_86 ;
F_56 ( & V_21 , type , F_61 ) ;
exp = F_60 ( * V_114 ) ;
if ( V_2 != V_99 ) {
T_1 V_41 = V_29 [ type ] . V_35 () ;
exp = F_31 ( V_41 , exp ) ;
}
if ( F_63 ( & V_21 , exp ) )
goto V_112;
if ( F_72 ( V_103 ) )
F_33 ( exp , type ) ;
if ( V_2 == V_99 ) {
V_3 = - V_115 ;
goto V_112;
}
if ( V_106 ) {
V_3 = F_69 ( exp , type , V_106 ) ;
if ( V_3 <= 0 )
goto V_112;
}
V_31 = & F_74 () -> V_110 ;
V_31 -> V_116 = F_71 ;
V_31 -> V_111 . V_60 = type ;
V_31 -> V_111 . V_36 = exp . V_49 ;
V_31 -> V_111 . V_106 = V_106 ;
V_3 = - V_113 ;
V_112:
return V_3 ;
}
static int T_7 F_75 ( void )
{
struct V_117 * V_118 ;
int error = 0 ;
int V_42 ;
struct V_119 V_120 = {
. V_121 = F_50 ,
. V_122 = F_52 ,
. V_123 = F_54 ,
. V_124 = F_59 ,
. V_125 = F_58 ,
. V_126 = F_57 ,
. V_127 = F_73 ,
} ;
F_8 () ;
F_76 ( V_61 , & V_120 ) ;
F_76 ( V_63 , & V_120 ) ;
V_29 [ V_62 ] . V_81 = V_128 ;
V_29 [ V_62 ] . V_35 = & V_129 ;
V_29 [ V_64 ] . V_81 = V_130 ;
V_29 [ V_64 ] . V_35 = & V_131 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
F_77 ( & V_29 [ V_42 ] . V_24 ) ;
F_78 ( & V_29 [ V_42 ] . V_33 ) ;
}
error = F_10 () ;
if ( error )
return error ;
error = F_79 ( & V_132 ) ;
if ( error )
goto V_133;
V_118 = F_80 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_81 ( V_118 ) ) {
error = F_82 ( V_118 ) ;
goto V_134;
}
V_51 = F_83 ( L_1 ) ;
return 0 ;
V_134:
F_84 ( & V_132 ) ;
V_133:
F_12 () ;
return error ;
}
