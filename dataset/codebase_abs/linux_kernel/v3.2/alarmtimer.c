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
static int F_8 ( void )
{
V_15 . V_16 = V_17 ;
return F_9 ( & V_15 ) ;
}
static void F_10 ( void )
{
F_11 ( & V_15 ) ;
}
static inline struct V_1 * F_1 ( void )
{
return NULL ;
}
static inline int F_8 ( void ) { return 0 ; }
static inline void F_10 ( void ) { }
static void F_12 ( struct V_18 * V_19 , struct V_20 * V_20 )
{
F_13 ( & V_19 -> V_21 , & V_20 -> V_22 ) ;
V_20 -> V_23 |= V_24 ;
if ( & V_20 -> V_22 == F_14 ( & V_19 -> V_21 ) ) {
F_15 ( & V_19 -> V_25 ) ;
F_16 ( & V_19 -> V_25 , V_20 -> V_22 . V_26 ,
V_27 ) ;
}
}
static void F_17 ( struct V_18 * V_19 , struct V_20 * V_20 )
{
struct V_28 * V_29 = F_14 ( & V_19 -> V_21 ) ;
if ( ! ( V_20 -> V_23 & V_24 ) )
return;
F_18 ( & V_19 -> V_21 , & V_20 -> V_22 ) ;
V_20 -> V_23 &= ~ V_24 ;
if ( V_29 == & V_20 -> V_22 ) {
F_15 ( & V_19 -> V_25 ) ;
V_29 = F_14 ( & V_19 -> V_21 ) ;
if ( ! V_29 )
return;
F_16 ( & V_19 -> V_25 , V_29 -> V_26 , V_27 ) ;
}
}
static enum V_30 F_19 ( struct V_31 * V_25 )
{
struct V_18 * V_19 = F_20 ( V_25 , struct V_18 , V_25 ) ;
struct V_28 * V_29 ;
unsigned long V_2 ;
T_1 V_32 ;
int V_3 = V_33 ;
int V_34 = V_35 ;
F_2 ( & V_19 -> V_36 , V_2 ) ;
V_32 = V_19 -> V_37 () ;
while ( ( V_29 = F_14 ( & V_19 -> V_21 ) ) ) {
struct V_20 * V_20 ;
T_1 V_38 = V_29 -> V_26 ;
if ( V_38 . V_39 > V_32 . V_39 )
break;
V_20 = F_20 ( V_29 , struct V_20 , V_22 ) ;
F_18 ( & V_19 -> V_21 , & V_20 -> V_22 ) ;
V_20 -> V_23 &= ~ V_24 ;
V_20 -> V_23 |= V_40 ;
F_3 ( & V_19 -> V_36 , V_2 ) ;
if ( V_20 -> V_41 )
V_34 = V_20 -> V_41 ( V_20 , V_32 ) ;
F_2 ( & V_19 -> V_36 , V_2 ) ;
V_20 -> V_23 &= ~ V_40 ;
if ( V_34 != V_35 ) {
F_13 ( & V_19 -> V_21 , & V_20 -> V_22 ) ;
V_20 -> V_23 |= V_24 ;
}
}
if ( V_29 ) {
F_21 ( & V_19 -> V_25 , V_29 -> V_26 ) ;
V_3 = V_42 ;
}
F_3 ( & V_19 -> V_36 , V_2 ) ;
return V_3 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_43 V_44 ;
T_1 V_45 , V_32 ;
unsigned long V_2 ;
struct V_1 * V_10 ;
int V_46 ;
F_2 ( & V_47 , V_2 ) ;
V_45 = V_48 ;
V_48 = F_23 ( 0 , 0 ) ;
F_3 ( & V_47 , V_2 ) ;
V_10 = F_1 () ;
if ( ! V_10 )
return 0 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
struct V_18 * V_19 = & V_50 [ V_46 ] ;
struct V_28 * V_29 ;
T_1 V_51 ;
F_2 ( & V_19 -> V_36 , V_2 ) ;
V_29 = F_14 ( & V_19 -> V_21 ) ;
F_3 ( & V_19 -> V_36 , V_2 ) ;
if ( ! V_29 )
continue;
V_51 = F_24 ( V_29 -> V_26 , V_19 -> V_37 () ) ;
if ( ! V_45 . V_39 || ( V_51 . V_39 < V_45 . V_39 ) )
V_45 = V_51 ;
}
if ( V_45 . V_39 == 0 )
return 0 ;
F_25 ( V_45 . V_39 < V_52 ) ;
F_26 ( V_10 , & V_53 ) ;
F_27 ( V_10 , & V_44 ) ;
V_32 = F_28 ( V_44 ) ;
V_32 = F_29 ( V_32 , V_45 ) ;
F_30 ( V_10 , & V_53 , V_32 , F_23 ( 0 , 0 ) ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_31 ( T_1 V_54 , enum V_55 type )
{
T_1 V_51 ;
unsigned long V_2 ;
struct V_18 * V_19 = & V_50 [ type ] ;
V_51 = F_24 ( V_54 , V_19 -> V_37 () ) ;
F_2 ( & V_47 , V_2 ) ;
if ( ! V_48 . V_39 || ( V_51 . V_39 < V_48 . V_39 ) )
V_48 = V_51 ;
F_3 ( & V_47 , V_2 ) ;
}
void F_32 ( struct V_20 * V_20 , T_1 V_56 )
{
struct V_18 * V_19 = & V_50 [ V_20 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_19 -> V_36 , V_2 ) ;
if ( F_33 ( V_20 ) )
F_17 ( V_19 , V_20 ) ;
V_20 -> V_22 . V_26 = V_56 ;
F_12 ( V_19 , V_20 ) ;
F_3 ( & V_19 -> V_36 , V_2 ) ;
}
int F_34 ( struct V_20 * V_20 )
{
struct V_18 * V_19 = & V_50 [ V_20 -> type ] ;
unsigned long V_2 ;
int V_3 = - 1 ;
F_2 ( & V_19 -> V_36 , V_2 ) ;
if ( F_35 ( V_20 ) )
goto V_57;
if ( F_36 ( V_20 ) ) {
F_17 ( V_19 , V_20 ) ;
V_3 = 1 ;
} else
V_3 = 0 ;
V_57:
F_3 ( & V_19 -> V_36 , V_2 ) ;
return V_3 ;
}
int F_37 ( struct V_20 * V_20 )
{
for (; ; ) {
int V_3 = F_34 ( V_20 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_38 () ;
}
}
T_2 F_39 ( struct V_20 * V_20 , T_1 V_32 , T_1 V_58 )
{
T_2 V_59 = 1 ;
T_1 V_51 ;
V_51 = F_24 ( V_32 , V_20 -> V_22 . V_26 ) ;
if ( V_51 . V_39 < 0 )
return 0 ;
if ( F_40 ( V_51 . V_39 >= V_58 . V_39 ) ) {
T_3 V_60 = F_41 ( V_58 ) ;
V_59 = F_42 ( V_51 , V_60 ) ;
V_20 -> V_22 . V_26 = F_43 ( V_20 -> V_22 . V_26 ,
V_60 * V_59 ) ;
if ( V_20 -> V_22 . V_26 . V_39 > V_32 . V_39 )
return V_59 ;
V_59 ++ ;
}
V_20 -> V_22 . V_26 = F_29 ( V_20 -> V_22 . V_26 , V_58 ) ;
return V_59 ;
}
static enum V_55 F_44 ( T_4 V_61 )
{
if ( V_61 == V_62 )
return V_63 ;
if ( V_61 == V_64 )
return V_65 ;
return - 1 ;
}
static enum V_66 F_45 ( struct V_20 * V_20 ,
T_1 V_32 )
{
struct V_67 * V_68 = F_20 ( V_20 , struct V_67 ,
V_69 . V_20 . V_70 ) ;
if ( F_46 ( V_68 , 0 ) != 0 )
V_68 -> V_71 ++ ;
if ( V_68 -> V_69 . V_20 . V_58 . V_39 ) {
V_68 -> V_71 += F_39 ( V_20 , V_32 ,
V_68 -> V_69 . V_20 . V_58 ) ;
return V_72 ;
}
return V_35 ;
}
static int F_47 ( const T_4 V_73 , struct V_74 * V_75 )
{
T_4 V_76 = V_50 [ F_44 ( V_73 ) ] . V_77 ;
if ( ! F_1 () )
return - V_78 ;
return F_48 ( V_76 , V_75 ) ;
}
static int F_49 ( T_4 V_73 , struct V_74 * V_75 )
{
struct V_18 * V_19 = & V_50 [ F_44 ( V_73 ) ] ;
if ( ! F_1 () )
return - V_78 ;
* V_75 = F_50 ( V_19 -> V_37 () ) ;
return 0 ;
}
static int F_51 ( struct V_67 * V_79 )
{
enum V_55 type ;
struct V_18 * V_19 ;
if ( ! F_1 () )
return - V_78 ;
if ( ! F_52 ( V_80 ) )
return - V_81 ;
type = F_44 ( V_79 -> V_82 ) ;
V_19 = & V_50 [ type ] ;
F_53 ( & V_79 -> V_69 . V_20 . V_70 , type , F_45 ) ;
return 0 ;
}
static void F_54 ( struct V_67 * V_83 ,
struct V_84 * V_85 )
{
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 -> V_86 =
F_50 ( V_83 -> V_69 . V_20 . V_58 ) ;
V_85 -> V_87 =
F_50 ( V_83 -> V_69 . V_20 . V_70 . V_22 . V_26 ) ;
return;
}
static int F_55 ( struct V_67 * V_83 )
{
if ( ! V_5 )
return - V_78 ;
if ( F_34 ( & V_83 -> V_69 . V_20 . V_70 ) < 0 )
return V_88 ;
return 0 ;
}
static int F_56 ( struct V_67 * V_83 , int V_2 ,
struct V_84 * V_89 ,
struct V_84 * V_90 )
{
if ( ! V_5 )
return - V_78 ;
if ( V_90 )
F_54 ( V_83 , V_90 ) ;
if ( F_34 ( & V_83 -> V_69 . V_20 . V_70 ) < 0 )
return V_88 ;
V_83 -> V_69 . V_20 . V_58 = F_57 ( V_89 -> V_86 ) ;
F_32 ( & V_83 -> V_69 . V_20 . V_70 ,
F_57 ( V_89 -> V_87 ) ) ;
return 0 ;
}
static enum V_66 F_58 ( struct V_20 * V_20 ,
T_1 V_32 )
{
struct V_91 * V_92 = (struct V_91 * ) V_20 -> V_93 ;
V_20 -> V_93 = NULL ;
if ( V_92 )
F_59 ( V_92 ) ;
return V_35 ;
}
static int F_60 ( struct V_20 * V_20 , T_1 V_54 )
{
V_20 -> V_93 = ( void * ) V_94 ;
do {
F_61 ( V_95 ) ;
F_32 ( V_20 , V_54 ) ;
if ( F_62 ( V_20 -> V_93 ) )
F_63 () ;
F_37 ( V_20 ) ;
} while ( V_20 -> V_93 && ! F_64 ( V_94 ) );
F_65 ( V_96 ) ;
return ( V_20 -> V_93 == NULL ) ;
}
static int F_66 ( T_1 exp , enum V_55 type ,
struct V_74 T_5 * V_97 )
{
struct V_74 V_98 ;
T_1 V_99 ;
V_99 = F_24 ( exp , V_50 [ type ] . V_37 () ) ;
if ( V_99 . V_39 <= 0 )
return 0 ;
V_98 = F_50 ( V_99 ) ;
if ( F_67 ( V_97 , & V_98 , sizeof( * V_97 ) ) )
return - V_100 ;
return 1 ;
}
static long T_6 F_68 ( struct V_101 * V_34 )
{
enum V_55 type = V_34 -> V_102 . V_61 ;
T_1 exp ;
struct V_74 T_5 * V_97 ;
struct V_20 V_20 ;
int V_3 = 0 ;
exp . V_39 = V_34 -> V_102 . V_26 ;
F_53 ( & V_20 , type , F_58 ) ;
if ( F_60 ( & V_20 , exp ) )
goto V_57;
if ( F_69 ( V_94 ) )
F_31 ( exp , type ) ;
V_97 = V_34 -> V_102 . V_97 ;
if ( V_97 ) {
V_3 = F_66 ( exp , type , V_97 ) ;
if ( V_3 <= 0 )
goto V_57;
}
V_3 = - V_103 ;
V_57:
return V_3 ;
}
static int F_70 ( const T_4 V_73 , int V_2 ,
struct V_74 * V_104 , struct V_74 T_5 * V_97 )
{
enum V_55 type = F_44 ( V_73 ) ;
struct V_20 V_20 ;
T_1 exp ;
int V_3 = 0 ;
struct V_101 * V_34 ;
if ( ! F_1 () )
return - V_78 ;
if ( ! F_52 ( V_80 ) )
return - V_81 ;
F_53 ( & V_20 , type , F_58 ) ;
exp = F_57 ( * V_104 ) ;
if ( V_2 != V_105 ) {
T_1 V_32 = V_50 [ type ] . V_37 () ;
exp = F_29 ( V_32 , exp ) ;
}
if ( F_60 ( & V_20 , exp ) )
goto V_57;
if ( F_69 ( V_94 ) )
F_31 ( exp , type ) ;
if ( V_2 == V_105 ) {
V_3 = - V_106 ;
goto V_57;
}
if ( V_97 ) {
V_3 = F_66 ( exp , type , V_97 ) ;
if ( V_3 <= 0 )
goto V_57;
}
V_34 = & F_71 () -> V_101 ;
V_34 -> V_107 = F_68 ;
V_34 -> V_102 . V_61 = type ;
V_34 -> V_102 . V_26 = exp . V_39 ;
V_34 -> V_102 . V_97 = V_97 ;
V_3 = - V_103 ;
V_57:
return V_3 ;
}
static int T_7 F_72 ( void )
{
struct V_108 * V_109 ;
int error = 0 ;
int V_46 ;
struct V_110 V_111 = {
. V_112 = F_47 ,
. V_113 = F_49 ,
. V_114 = F_51 ,
. V_115 = F_56 ,
. V_116 = F_55 ,
. V_117 = F_54 ,
. V_118 = F_70 ,
} ;
F_73 ( V_62 , & V_111 ) ;
F_73 ( V_64 , & V_111 ) ;
V_50 [ V_63 ] . V_77 = V_119 ;
V_50 [ V_63 ] . V_37 = & V_120 ;
V_50 [ V_65 ] . V_77 = V_121 ;
V_50 [ V_65 ] . V_37 = & V_122 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
F_74 ( & V_50 [ V_46 ] . V_21 ) ;
F_75 ( & V_50 [ V_46 ] . V_36 ) ;
F_76 ( & V_50 [ V_46 ] . V_25 ,
V_50 [ V_46 ] . V_77 ,
V_27 ) ;
V_50 [ V_46 ] . V_25 . V_41 = F_19 ;
}
error = F_8 () ;
if ( error )
return error ;
error = F_77 ( & V_123 ) ;
if ( error )
goto V_124;
V_109 = F_78 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_79 ( V_109 ) ) {
error = F_80 ( V_109 ) ;
goto V_125;
}
return 0 ;
V_125:
F_81 ( & V_123 ) ;
V_124:
F_10 () ;
return error ;
}
