static struct V_1 * F_1 ( void )
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
static inline struct V_1 * F_1 ( void )
{
return NULL ;
}
static inline int F_10 ( void ) { return 0 ; }
static inline void F_12 ( void ) { }
static inline void F_8 ( void ) { }
static void F_14 ( struct V_19 * V_20 , struct V_21 * V_21 )
{
F_15 ( & V_20 -> V_22 , & V_21 -> V_23 ) ;
V_21 -> V_24 |= V_25 ;
if ( & V_21 -> V_23 == F_16 ( & V_20 -> V_22 ) ) {
F_17 ( & V_20 -> V_26 ) ;
F_18 ( & V_20 -> V_26 , V_21 -> V_23 . V_27 ,
V_28 ) ;
}
}
static void F_19 ( struct V_19 * V_20 , struct V_21 * V_21 )
{
struct V_29 * V_30 = F_16 ( & V_20 -> V_22 ) ;
if ( ! ( V_21 -> V_24 & V_25 ) )
return;
F_20 ( & V_20 -> V_22 , & V_21 -> V_23 ) ;
V_21 -> V_24 &= ~ V_25 ;
if ( V_30 == & V_21 -> V_23 ) {
F_17 ( & V_20 -> V_26 ) ;
V_30 = F_16 ( & V_20 -> V_22 ) ;
if ( ! V_30 )
return;
F_18 ( & V_20 -> V_26 , V_30 -> V_27 , V_28 ) ;
}
}
static enum V_31 F_21 ( struct V_32 * V_26 )
{
struct V_19 * V_20 = F_22 ( V_26 , struct V_19 , V_26 ) ;
struct V_29 * V_30 ;
unsigned long V_2 ;
T_1 V_33 ;
int V_3 = V_34 ;
int V_35 = V_36 ;
F_2 ( & V_20 -> V_37 , V_2 ) ;
V_33 = V_20 -> V_38 () ;
while ( ( V_30 = F_16 ( & V_20 -> V_22 ) ) ) {
struct V_21 * V_21 ;
T_1 V_39 = V_30 -> V_27 ;
if ( V_39 . V_40 > V_33 . V_40 )
break;
V_21 = F_22 ( V_30 , struct V_21 , V_23 ) ;
F_20 ( & V_20 -> V_22 , & V_21 -> V_23 ) ;
V_21 -> V_24 &= ~ V_25 ;
V_21 -> V_24 |= V_41 ;
F_3 ( & V_20 -> V_37 , V_2 ) ;
if ( V_21 -> V_42 )
V_35 = V_21 -> V_42 ( V_21 , V_33 ) ;
F_2 ( & V_20 -> V_37 , V_2 ) ;
V_21 -> V_24 &= ~ V_41 ;
if ( V_35 != V_36 ) {
F_15 ( & V_20 -> V_22 , & V_21 -> V_23 ) ;
V_21 -> V_24 |= V_25 ;
}
}
if ( V_30 ) {
F_23 ( & V_20 -> V_26 , V_30 -> V_27 ) ;
V_3 = V_43 ;
}
F_3 ( & V_20 -> V_37 , V_2 ) ;
return V_3 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_44 V_45 ;
T_1 V_46 , V_33 ;
unsigned long V_2 ;
struct V_1 * V_10 ;
int V_47 ;
F_2 ( & V_48 , V_2 ) ;
V_46 = V_49 ;
V_49 = F_25 ( 0 , 0 ) ;
F_3 ( & V_48 , V_2 ) ;
V_10 = F_1 () ;
if ( ! V_10 )
return 0 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
struct V_19 * V_20 = & V_51 [ V_47 ] ;
struct V_29 * V_30 ;
T_1 V_52 ;
F_2 ( & V_20 -> V_37 , V_2 ) ;
V_30 = F_16 ( & V_20 -> V_22 ) ;
F_3 ( & V_20 -> V_37 , V_2 ) ;
if ( ! V_30 )
continue;
V_52 = F_26 ( V_30 -> V_27 , V_20 -> V_38 () ) ;
if ( ! V_46 . V_40 || ( V_52 . V_40 < V_46 . V_40 ) )
V_46 = V_52 ;
}
if ( V_46 . V_40 == 0 )
return 0 ;
F_27 ( V_46 . V_40 < V_53 ) ;
F_28 ( V_10 , & V_15 ) ;
F_29 ( V_10 , & V_45 ) ;
V_33 = F_30 ( V_45 ) ;
V_33 = F_31 ( V_33 , V_46 ) ;
F_32 ( V_10 , & V_15 , V_33 , F_25 ( 0 , 0 ) ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_33 ( T_1 V_54 , enum V_55 type )
{
T_1 V_52 ;
unsigned long V_2 ;
struct V_19 * V_20 = & V_51 [ type ] ;
V_52 = F_26 ( V_54 , V_20 -> V_38 () ) ;
F_2 ( & V_48 , V_2 ) ;
if ( ! V_49 . V_40 || ( V_52 . V_40 < V_49 . V_40 ) )
V_49 = V_52 ;
F_3 ( & V_48 , V_2 ) ;
}
void F_34 ( struct V_21 * V_21 , T_1 V_56 )
{
struct V_19 * V_20 = & V_51 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_37 , V_2 ) ;
if ( F_35 ( V_21 ) )
F_19 ( V_20 , V_21 ) ;
V_21 -> V_23 . V_27 = V_56 ;
F_14 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_37 , V_2 ) ;
}
int F_36 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_51 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 = - 1 ;
F_2 ( & V_20 -> V_37 , V_2 ) ;
if ( F_37 ( V_21 ) )
goto V_57;
if ( F_38 ( V_21 ) ) {
F_19 ( V_20 , V_21 ) ;
V_3 = 1 ;
} else
V_3 = 0 ;
V_57:
F_3 ( & V_20 -> V_37 , V_2 ) ;
return V_3 ;
}
int F_39 ( struct V_21 * V_21 )
{
for (; ; ) {
int V_3 = F_36 ( V_21 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_40 () ;
}
}
T_2 F_41 ( struct V_21 * V_21 , T_1 V_33 , T_1 V_58 )
{
T_2 V_59 = 1 ;
T_1 V_52 ;
V_52 = F_26 ( V_33 , V_21 -> V_23 . V_27 ) ;
if ( V_52 . V_40 < 0 )
return 0 ;
if ( F_42 ( V_52 . V_40 >= V_58 . V_40 ) ) {
T_3 V_60 = F_43 ( V_58 ) ;
V_59 = F_44 ( V_52 , V_60 ) ;
V_21 -> V_23 . V_27 = F_45 ( V_21 -> V_23 . V_27 ,
V_60 * V_59 ) ;
if ( V_21 -> V_23 . V_27 . V_40 > V_33 . V_40 )
return V_59 ;
V_59 ++ ;
}
V_21 -> V_23 . V_27 = F_31 ( V_21 -> V_23 . V_27 , V_58 ) ;
return V_59 ;
}
static enum V_55 F_46 ( T_4 V_61 )
{
if ( V_61 == V_62 )
return V_63 ;
if ( V_61 == V_64 )
return V_65 ;
return - 1 ;
}
static enum V_66 F_47 ( struct V_21 * V_21 ,
T_1 V_33 )
{
struct V_67 * V_68 = F_22 ( V_21 , struct V_67 ,
V_69 . V_21 . V_70 ) ;
if ( F_48 ( V_68 , 0 ) != 0 )
V_68 -> V_71 ++ ;
if ( V_68 -> V_69 . V_21 . V_58 . V_40 ) {
V_68 -> V_71 += F_41 ( V_21 , V_33 ,
V_68 -> V_69 . V_21 . V_58 ) ;
return V_72 ;
}
return V_36 ;
}
static int F_49 ( const T_4 V_73 , struct V_74 * V_75 )
{
T_4 V_76 = V_51 [ F_46 ( V_73 ) ] . V_77 ;
if ( ! F_1 () )
return - V_78 ;
return F_50 ( V_76 , V_75 ) ;
}
static int F_51 ( T_4 V_73 , struct V_74 * V_75 )
{
struct V_19 * V_20 = & V_51 [ F_46 ( V_73 ) ] ;
if ( ! F_1 () )
return - V_78 ;
* V_75 = F_52 ( V_20 -> V_38 () ) ;
return 0 ;
}
static int F_53 ( struct V_67 * V_79 )
{
enum V_55 type ;
struct V_19 * V_20 ;
if ( ! F_1 () )
return - V_78 ;
if ( ! F_54 ( V_80 ) )
return - V_81 ;
type = F_46 ( V_79 -> V_82 ) ;
V_20 = & V_51 [ type ] ;
F_55 ( & V_79 -> V_69 . V_21 . V_70 , type , F_47 ) ;
return 0 ;
}
static void F_56 ( struct V_67 * V_83 ,
struct V_84 * V_85 )
{
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 -> V_86 =
F_52 ( V_83 -> V_69 . V_21 . V_58 ) ;
V_85 -> V_87 =
F_52 ( V_83 -> V_69 . V_21 . V_70 . V_23 . V_27 ) ;
return;
}
static int F_57 ( struct V_67 * V_83 )
{
if ( ! V_5 )
return - V_78 ;
if ( F_36 ( & V_83 -> V_69 . V_21 . V_70 ) < 0 )
return V_88 ;
return 0 ;
}
static int F_58 ( struct V_67 * V_83 , int V_2 ,
struct V_84 * V_89 ,
struct V_84 * V_90 )
{
if ( ! V_5 )
return - V_78 ;
if ( V_90 )
F_56 ( V_83 , V_90 ) ;
if ( F_36 ( & V_83 -> V_69 . V_21 . V_70 ) < 0 )
return V_88 ;
V_83 -> V_69 . V_21 . V_58 = F_59 ( V_89 -> V_86 ) ;
F_34 ( & V_83 -> V_69 . V_21 . V_70 ,
F_59 ( V_89 -> V_87 ) ) ;
return 0 ;
}
static enum V_66 F_60 ( struct V_21 * V_21 ,
T_1 V_33 )
{
struct V_91 * V_92 = (struct V_91 * ) V_21 -> V_93 ;
V_21 -> V_93 = NULL ;
if ( V_92 )
F_61 ( V_92 ) ;
return V_36 ;
}
static int F_62 ( struct V_21 * V_21 , T_1 V_54 )
{
V_21 -> V_93 = ( void * ) V_94 ;
do {
F_63 ( V_95 ) ;
F_34 ( V_21 , V_54 ) ;
if ( F_64 ( V_21 -> V_93 ) )
F_65 () ;
F_39 ( V_21 ) ;
} while ( V_21 -> V_93 && ! F_66 ( V_94 ) );
F_67 ( V_96 ) ;
return ( V_21 -> V_93 == NULL ) ;
}
static int F_68 ( T_1 exp , enum V_55 type ,
struct V_74 T_5 * V_97 )
{
struct V_74 V_98 ;
T_1 V_99 ;
V_99 = F_26 ( exp , V_51 [ type ] . V_38 () ) ;
if ( V_99 . V_40 <= 0 )
return 0 ;
V_98 = F_52 ( V_99 ) ;
if ( F_69 ( V_97 , & V_98 , sizeof( * V_97 ) ) )
return - V_100 ;
return 1 ;
}
static long T_6 F_70 ( struct V_101 * V_35 )
{
enum V_55 type = V_35 -> V_102 . V_61 ;
T_1 exp ;
struct V_74 T_5 * V_97 ;
struct V_21 V_21 ;
int V_3 = 0 ;
exp . V_40 = V_35 -> V_102 . V_27 ;
F_55 ( & V_21 , type , F_60 ) ;
if ( F_62 ( & V_21 , exp ) )
goto V_57;
if ( F_71 ( V_94 ) )
F_33 ( exp , type ) ;
V_97 = V_35 -> V_102 . V_97 ;
if ( V_97 ) {
V_3 = F_68 ( exp , type , V_97 ) ;
if ( V_3 <= 0 )
goto V_57;
}
V_3 = - V_103 ;
V_57:
return V_3 ;
}
static int F_72 ( const T_4 V_73 , int V_2 ,
struct V_74 * V_104 , struct V_74 T_5 * V_97 )
{
enum V_55 type = F_46 ( V_73 ) ;
struct V_21 V_21 ;
T_1 exp ;
int V_3 = 0 ;
struct V_101 * V_35 ;
if ( ! F_1 () )
return - V_78 ;
if ( ! F_54 ( V_80 ) )
return - V_81 ;
F_55 ( & V_21 , type , F_60 ) ;
exp = F_59 ( * V_104 ) ;
if ( V_2 != V_105 ) {
T_1 V_33 = V_51 [ type ] . V_38 () ;
exp = F_31 ( V_33 , exp ) ;
}
if ( F_62 ( & V_21 , exp ) )
goto V_57;
if ( F_71 ( V_94 ) )
F_33 ( exp , type ) ;
if ( V_2 == V_105 ) {
V_3 = - V_106 ;
goto V_57;
}
if ( V_97 ) {
V_3 = F_68 ( exp , type , V_97 ) ;
if ( V_3 <= 0 )
goto V_57;
}
V_35 = & F_73 () -> V_101 ;
V_35 -> V_107 = F_70 ;
V_35 -> V_102 . V_61 = type ;
V_35 -> V_102 . V_27 = exp . V_40 ;
V_35 -> V_102 . V_97 = V_97 ;
V_3 = - V_103 ;
V_57:
return V_3 ;
}
static int T_7 F_74 ( void )
{
struct V_108 * V_109 ;
int error = 0 ;
int V_47 ;
struct V_110 V_111 = {
. V_112 = F_49 ,
. V_113 = F_51 ,
. V_114 = F_53 ,
. V_115 = F_58 ,
. V_116 = F_57 ,
. V_117 = F_56 ,
. V_118 = F_72 ,
} ;
F_8 () ;
F_75 ( V_62 , & V_111 ) ;
F_75 ( V_64 , & V_111 ) ;
V_51 [ V_63 ] . V_77 = V_119 ;
V_51 [ V_63 ] . V_38 = & V_120 ;
V_51 [ V_65 ] . V_77 = V_121 ;
V_51 [ V_65 ] . V_38 = & V_122 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
F_76 ( & V_51 [ V_47 ] . V_22 ) ;
F_77 ( & V_51 [ V_47 ] . V_37 ) ;
F_78 ( & V_51 [ V_47 ] . V_26 ,
V_51 [ V_47 ] . V_77 ,
V_28 ) ;
V_51 [ V_47 ] . V_26 . V_42 = F_21 ;
}
error = F_10 () ;
if ( error )
return error ;
error = F_79 ( & V_123 ) ;
if ( error )
goto V_124;
V_109 = F_80 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_81 ( V_109 ) ) {
error = F_82 ( V_109 ) ;
goto V_125;
}
return 0 ;
V_125:
F_83 ( & V_123 ) ;
V_124:
F_12 () ;
return error ;
}
