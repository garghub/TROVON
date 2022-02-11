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
static int F_33 ( struct V_6 * V_7 )
{
struct V_1 * V_10 ;
V_10 = F_1 () ;
if ( V_10 )
F_28 ( V_10 , & V_15 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_34 ( T_1 V_53 , enum V_54 type )
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
void F_35 ( struct V_21 * V_21 , T_1 V_55 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_21 -> V_25 . V_36 = V_55 ;
F_14 ( V_20 , V_21 ) ;
F_36 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 , V_56 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
}
void F_37 ( struct V_21 * V_21 , T_1 V_55 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
V_55 = F_31 ( V_55 , V_20 -> V_35 () ) ;
F_35 ( V_21 , V_55 ) ;
}
void F_38 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
F_20 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ) ;
V_26 ( & V_21 -> V_28 ) ;
F_14 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
}
int F_39 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_3 = F_40 ( & V_21 -> V_28 ) ;
if ( V_3 >= 0 )
F_17 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
return V_3 ;
}
int F_41 ( struct V_21 * V_21 )
{
for (; ; ) {
int V_3 = F_39 ( V_21 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_42 () ;
}
}
T_2 F_43 ( struct V_21 * V_21 , T_1 V_41 , T_1 V_57 )
{
T_2 V_58 = 1 ;
T_1 V_48 ;
V_48 = F_22 ( V_41 , V_21 -> V_25 . V_36 ) ;
if ( V_48 . V_49 < 0 )
return 0 ;
if ( F_44 ( V_48 . V_49 >= V_57 . V_49 ) ) {
T_3 V_59 = F_26 ( V_57 ) ;
V_58 = F_45 ( V_48 , V_59 ) ;
V_21 -> V_25 . V_36 = F_46 ( V_21 -> V_25 . V_36 ,
V_59 * V_58 ) ;
if ( V_21 -> V_25 . V_36 . V_49 > V_41 . V_49 )
return V_58 ;
V_58 ++ ;
}
V_21 -> V_25 . V_36 = F_31 ( V_21 -> V_25 . V_36 , V_57 ) ;
return V_58 ;
}
T_2 F_47 ( struct V_21 * V_21 , T_1 V_57 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_43 ( V_21 , V_20 -> V_35 () , V_57 ) ;
}
static enum V_54 F_48 ( T_4 V_60 )
{
if ( V_60 == V_61 )
return V_62 ;
if ( V_60 == V_63 )
return V_64 ;
return - 1 ;
}
static enum V_65 F_49 ( struct V_21 * V_21 ,
T_1 V_41 )
{
unsigned long V_2 ;
struct V_66 * V_67 = F_19 ( V_21 , struct V_66 ,
V_68 . V_21 . V_69 ) ;
enum V_65 V_70 = V_32 ;
F_2 ( & V_67 -> V_71 , V_2 ) ;
if ( ( V_67 -> V_72 & ~ V_73 ) != V_74 ) {
if ( F_50 ( V_67 , 0 ) != 0 )
V_67 -> V_75 ++ ;
}
if ( V_67 -> V_68 . V_21 . V_57 . V_49 ) {
V_67 -> V_75 += F_43 ( V_21 , V_41 ,
V_67 -> V_68 . V_21 . V_57 ) ;
V_70 = V_76 ;
}
F_3 ( & V_67 -> V_71 , V_2 ) ;
return V_70 ;
}
static int F_51 ( const T_4 V_77 , struct V_78 * V_79 )
{
if ( ! F_1 () )
return - V_80 ;
V_79 -> V_81 = 0 ;
V_79 -> V_82 = V_83 ;
return 0 ;
}
static int F_52 ( T_4 V_77 , struct V_78 * V_79 )
{
struct V_19 * V_20 = & V_29 [ F_48 ( V_77 ) ] ;
if ( ! F_1 () )
return - V_80 ;
* V_79 = F_53 ( V_20 -> V_35 () ) ;
return 0 ;
}
static int F_54 ( struct V_66 * V_84 )
{
enum V_54 type ;
if ( ! F_1 () )
return - V_85 ;
if ( ! F_55 ( V_86 ) )
return - V_87 ;
type = F_48 ( V_84 -> V_88 ) ;
F_56 ( & V_84 -> V_68 . V_21 . V_69 , type , F_49 ) ;
return 0 ;
}
static void F_57 ( struct V_66 * V_89 ,
struct V_90 * V_91 )
{
T_1 V_92 =
F_21 ( & ( V_89 -> V_68 . V_21 . V_69 ) ) ;
if ( F_26 ( V_92 ) > 0 ) {
V_91 -> V_93 = F_53 ( V_92 ) ;
} else {
V_91 -> V_93 . V_81 = 0 ;
V_91 -> V_93 . V_82 = 0 ;
}
V_91 -> V_94 = F_53 ( V_89 -> V_68 . V_21 . V_57 ) ;
}
static int F_58 ( struct V_66 * V_89 )
{
if ( ! V_5 )
return - V_85 ;
if ( F_39 ( & V_89 -> V_68 . V_21 . V_69 ) < 0 )
return V_95 ;
return 0 ;
}
static int F_59 ( struct V_66 * V_89 , int V_2 ,
struct V_90 * V_96 ,
struct V_90 * V_97 )
{
T_1 exp ;
if ( ! V_5 )
return - V_85 ;
if ( V_2 & ~ V_98 )
return - V_80 ;
if ( V_97 )
F_57 ( V_89 , V_97 ) ;
if ( F_39 ( & V_89 -> V_68 . V_21 . V_69 ) < 0 )
return V_95 ;
V_89 -> V_68 . V_21 . V_57 = F_60 ( V_96 -> V_94 ) ;
exp = F_60 ( V_96 -> V_93 ) ;
if ( V_2 != V_98 ) {
T_1 V_41 ;
V_41 = V_29 [ V_89 -> V_68 . V_21 . V_69 . type ] . V_35 () ;
exp = F_31 ( V_41 , exp ) ;
}
F_35 ( & V_89 -> V_68 . V_21 . V_69 , exp ) ;
return 0 ;
}
static enum V_65 F_61 ( struct V_21 * V_21 ,
T_1 V_41 )
{
struct V_99 * V_100 = (struct V_99 * ) V_21 -> V_101 ;
V_21 -> V_101 = NULL ;
if ( V_100 )
F_62 ( V_100 ) ;
return V_32 ;
}
static int F_63 ( struct V_21 * V_21 , T_1 V_53 )
{
V_21 -> V_101 = ( void * ) V_102 ;
do {
F_64 ( V_103 ) ;
F_35 ( V_21 , V_53 ) ;
if ( F_65 ( V_21 -> V_101 ) )
F_66 () ;
F_41 ( V_21 ) ;
} while ( V_21 -> V_101 && ! F_67 ( V_102 ) );
F_68 ( V_104 ) ;
return ( V_21 -> V_101 == NULL ) ;
}
static int F_69 ( T_1 exp , enum V_54 type ,
struct V_78 T_5 * V_105 )
{
struct V_78 V_106 ;
T_1 V_107 ;
V_107 = F_22 ( exp , V_29 [ type ] . V_35 () ) ;
if ( V_107 . V_49 <= 0 )
return 0 ;
V_106 = F_53 ( V_107 ) ;
if ( F_70 ( V_105 , & V_106 , sizeof( * V_105 ) ) )
return - V_108 ;
return 1 ;
}
static long T_6 F_71 ( struct V_109 * V_31 )
{
enum V_54 type = V_31 -> V_110 . V_60 ;
T_1 exp ;
struct V_78 T_5 * V_105 ;
struct V_21 V_21 ;
int V_3 = 0 ;
exp . V_49 = V_31 -> V_110 . V_36 ;
F_56 ( & V_21 , type , F_61 ) ;
if ( F_63 ( & V_21 , exp ) )
goto V_111;
if ( F_72 ( V_102 ) )
F_34 ( exp , type ) ;
V_105 = V_31 -> V_110 . V_105 ;
if ( V_105 ) {
V_3 = F_69 ( exp , type , V_105 ) ;
if ( V_3 <= 0 )
goto V_111;
}
V_3 = - V_112 ;
V_111:
return V_3 ;
}
static int F_73 ( const T_4 V_77 , int V_2 ,
struct V_78 * V_113 , struct V_78 T_5 * V_105 )
{
enum V_54 type = F_48 ( V_77 ) ;
struct V_21 V_21 ;
T_1 exp ;
int V_3 = 0 ;
struct V_109 * V_31 ;
if ( ! F_1 () )
return - V_85 ;
if ( V_2 & ~ V_98 )
return - V_80 ;
if ( ! F_55 ( V_86 ) )
return - V_87 ;
F_56 ( & V_21 , type , F_61 ) ;
exp = F_60 ( * V_113 ) ;
if ( V_2 != V_98 ) {
T_1 V_41 = V_29 [ type ] . V_35 () ;
exp = F_31 ( V_41 , exp ) ;
}
if ( F_63 ( & V_21 , exp ) )
goto V_111;
if ( F_72 ( V_102 ) )
F_34 ( exp , type ) ;
if ( V_2 == V_98 ) {
V_3 = - V_114 ;
goto V_111;
}
if ( V_105 ) {
V_3 = F_69 ( exp , type , V_105 ) ;
if ( V_3 <= 0 )
goto V_111;
}
V_31 = & V_102 -> V_109 ;
V_31 -> V_115 = F_71 ;
V_31 -> V_110 . V_60 = type ;
V_31 -> V_110 . V_36 = exp . V_49 ;
V_31 -> V_110 . V_105 = V_105 ;
V_3 = - V_112 ;
V_111:
return V_3 ;
}
static int T_7 F_74 ( void )
{
struct V_116 * V_117 ;
int error = 0 ;
int V_42 ;
struct V_118 V_119 = {
. V_120 = F_51 ,
. V_121 = F_52 ,
. V_122 = F_54 ,
. V_123 = F_59 ,
. V_124 = F_58 ,
. V_125 = F_57 ,
. V_126 = F_73 ,
} ;
F_8 () ;
F_75 ( V_61 , & V_119 ) ;
F_75 ( V_63 , & V_119 ) ;
V_29 [ V_62 ] . V_127 = V_128 ;
V_29 [ V_62 ] . V_35 = & V_129 ;
V_29 [ V_64 ] . V_127 = V_130 ;
V_29 [ V_64 ] . V_35 = & V_131 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
F_76 ( & V_29 [ V_42 ] . V_24 ) ;
F_77 ( & V_29 [ V_42 ] . V_33 ) ;
}
error = F_10 () ;
if ( error )
return error ;
error = F_78 ( & V_132 ) ;
if ( error )
goto V_133;
V_117 = F_79 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_80 ( V_117 ) ) {
error = F_81 ( V_117 ) ;
goto V_134;
}
V_51 = F_82 ( L_1 ) ;
return 0 ;
V_134:
F_83 ( & V_132 ) ;
V_133:
F_12 () ;
return error ;
}
