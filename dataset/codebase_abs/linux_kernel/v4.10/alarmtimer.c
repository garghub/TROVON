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
F_21 ( V_21 , V_20 -> V_35 () ) ;
return V_3 ;
}
T_1 F_22 ( const struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_23 ( V_21 -> V_25 . V_36 , V_20 -> V_35 () ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
T_1 V_38 , V_39 , V_36 ;
int V_40 , V_3 , type ;
struct V_1 * V_10 ;
unsigned long V_2 ;
struct V_41 V_42 ;
F_2 ( & V_43 , V_2 ) ;
V_38 = V_44 ;
V_36 = V_45 ;
type = V_46 ;
V_44 = 0 ;
F_3 ( & V_43 , V_2 ) ;
V_10 = F_1 () ;
if ( ! V_10 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
struct V_19 * V_20 = & V_29 [ V_40 ] ;
struct V_48 * V_49 ;
T_1 V_50 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_49 = F_25 ( & V_20 -> V_24 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
if ( ! V_49 )
continue;
V_50 = F_23 ( V_49 -> V_36 , V_20 -> V_35 () ) ;
if ( ! V_38 || ( V_50 < V_38 ) ) {
V_36 = V_49 -> V_36 ;
V_38 = V_50 ;
type = V_40 ;
}
}
if ( V_38 == 0 )
return 0 ;
if ( F_26 ( V_38 ) < 2 * V_51 ) {
F_27 ( V_52 , 2 * V_53 ) ;
return - V_11 ;
}
F_28 ( V_36 , type ) ;
F_29 ( V_10 , & V_15 ) ;
F_30 ( V_10 , & V_42 ) ;
V_39 = F_31 ( V_42 ) ;
V_39 = F_32 ( V_39 , V_38 ) ;
V_3 = F_33 ( V_10 , & V_15 , V_39 , 0 ) ;
if ( V_3 < 0 )
F_27 ( V_52 , V_53 ) ;
return V_3 ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_10 ;
V_10 = F_1 () ;
if ( V_10 )
F_29 ( V_10 , & V_15 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_35 ( T_1 V_54 , enum V_55 type )
{
struct V_19 * V_20 ;
unsigned long V_2 ;
T_1 V_50 ;
switch( type ) {
case V_56 :
V_20 = & V_29 [ V_56 ] ;
type = V_57 ;
break;
case V_58 :
V_20 = & V_29 [ V_58 ] ;
type = V_59 ;
break;
default:
F_36 ( 1 , L_1 , type ) ;
return;
}
V_50 = F_23 ( V_54 , V_20 -> V_35 () ) ;
F_2 ( & V_43 , V_2 ) ;
if ( ! V_44 || ( V_50 < V_44 ) ) {
V_44 = V_50 ;
V_45 = V_54 ;
V_46 = type ;
}
F_3 ( & V_43 , V_2 ) ;
}
void F_37 ( struct V_21 * V_21 , T_1 V_60 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_21 -> V_25 . V_36 = V_60 ;
F_14 ( V_20 , V_21 ) ;
F_38 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 , V_61 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
F_39 ( V_21 , V_20 -> V_35 () ) ;
}
void F_40 ( struct V_21 * V_21 , T_1 V_60 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
V_60 = F_32 ( V_60 , V_20 -> V_35 () ) ;
F_37 ( V_21 , V_60 ) ;
}
void F_41 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
F_20 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ) ;
V_26 ( & V_21 -> V_28 ) ;
F_14 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
}
int F_42 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_3 = F_43 ( & V_21 -> V_28 ) ;
if ( V_3 >= 0 )
F_17 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
F_44 ( V_21 , V_20 -> V_35 () ) ;
return V_3 ;
}
int F_45 ( struct V_21 * V_21 )
{
for (; ; ) {
int V_3 = F_42 ( V_21 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_46 () ;
}
}
T_2 F_47 ( struct V_21 * V_21 , T_1 V_39 , T_1 V_62 )
{
T_2 V_63 = 1 ;
T_1 V_50 ;
V_50 = F_23 ( V_39 , V_21 -> V_25 . V_36 ) ;
if ( V_50 < 0 )
return 0 ;
if ( F_48 ( V_50 >= V_62 ) ) {
T_3 V_64 = F_26 ( V_62 ) ;
V_63 = F_49 ( V_50 , V_64 ) ;
V_21 -> V_25 . V_36 = F_50 ( V_21 -> V_25 . V_36 ,
V_64 * V_63 ) ;
if ( V_21 -> V_25 . V_36 > V_39 )
return V_63 ;
V_63 ++ ;
}
V_21 -> V_25 . V_36 = F_32 ( V_21 -> V_25 . V_36 , V_62 ) ;
return V_63 ;
}
T_2 F_51 ( struct V_21 * V_21 , T_1 V_62 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_47 ( V_21 , V_20 -> V_35 () , V_62 ) ;
}
static enum V_55 F_52 ( T_4 V_65 )
{
if ( V_65 == V_66 )
return V_56 ;
if ( V_65 == V_67 )
return V_58 ;
return - 1 ;
}
static enum V_68 F_53 ( struct V_21 * V_21 ,
T_1 V_39 )
{
unsigned long V_2 ;
struct V_69 * V_70 = F_19 ( V_21 , struct V_69 ,
V_71 . V_21 . V_72 ) ;
enum V_68 V_73 = V_32 ;
F_2 ( & V_70 -> V_74 , V_2 ) ;
if ( ( V_70 -> V_75 & ~ V_76 ) != V_77 ) {
if ( F_54 ( V_78 ) &&
F_55 ( V_70 , 0 ) != 0 )
V_70 -> V_79 ++ ;
}
if ( V_70 -> V_71 . V_21 . V_62 ) {
V_70 -> V_79 += F_47 ( V_21 , V_39 ,
V_70 -> V_71 . V_21 . V_62 ) ;
V_73 = V_80 ;
}
F_3 ( & V_70 -> V_74 , V_2 ) ;
return V_73 ;
}
static int F_56 ( const T_4 V_81 , struct V_82 * V_83 )
{
if ( ! F_1 () )
return - V_84 ;
V_83 -> V_85 = 0 ;
V_83 -> V_86 = V_87 ;
return 0 ;
}
static int F_57 ( T_4 V_81 , struct V_82 * V_83 )
{
struct V_19 * V_20 = & V_29 [ F_52 ( V_81 ) ] ;
if ( ! F_1 () )
return - V_84 ;
* V_83 = F_58 ( V_20 -> V_35 () ) ;
return 0 ;
}
static int F_59 ( struct V_69 * V_88 )
{
enum V_55 type ;
if ( ! F_1 () )
return - V_89 ;
if ( ! F_60 ( V_90 ) )
return - V_91 ;
type = F_52 ( V_88 -> V_92 ) ;
F_61 ( & V_88 -> V_71 . V_21 . V_72 , type , F_53 ) ;
return 0 ;
}
static void F_62 ( struct V_69 * V_93 ,
struct V_94 * V_95 )
{
T_1 V_96 =
F_22 ( & ( V_93 -> V_71 . V_21 . V_72 ) ) ;
if ( F_26 ( V_96 ) > 0 ) {
V_95 -> V_97 = F_58 ( V_96 ) ;
} else {
V_95 -> V_97 . V_85 = 0 ;
V_95 -> V_97 . V_86 = 0 ;
}
V_95 -> V_98 = F_58 ( V_93 -> V_71 . V_21 . V_62 ) ;
}
static int F_63 ( struct V_69 * V_93 )
{
if ( ! V_5 )
return - V_89 ;
if ( F_42 ( & V_93 -> V_71 . V_21 . V_72 ) < 0 )
return V_99 ;
return 0 ;
}
static int F_64 ( struct V_69 * V_93 , int V_2 ,
struct V_94 * V_100 ,
struct V_94 * V_101 )
{
T_1 exp ;
if ( ! V_5 )
return - V_89 ;
if ( V_2 & ~ V_102 )
return - V_84 ;
if ( V_101 )
F_62 ( V_93 , V_101 ) ;
if ( F_42 ( & V_93 -> V_71 . V_21 . V_72 ) < 0 )
return V_99 ;
V_93 -> V_71 . V_21 . V_62 = F_65 ( V_100 -> V_98 ) ;
exp = F_65 ( V_100 -> V_97 ) ;
if ( V_2 != V_102 ) {
T_1 V_39 ;
V_39 = V_29 [ V_93 -> V_71 . V_21 . V_72 . type ] . V_35 () ;
exp = F_32 ( V_39 , exp ) ;
}
F_37 ( & V_93 -> V_71 . V_21 . V_72 , exp ) ;
return 0 ;
}
static enum V_68 F_66 ( struct V_21 * V_21 ,
T_1 V_39 )
{
struct V_103 * V_104 = (struct V_103 * ) V_21 -> V_105 ;
V_21 -> V_105 = NULL ;
if ( V_104 )
F_67 ( V_104 ) ;
return V_32 ;
}
static int F_68 ( struct V_21 * V_21 , T_1 V_54 )
{
V_21 -> V_105 = ( void * ) V_106 ;
do {
F_69 ( V_107 ) ;
F_37 ( V_21 , V_54 ) ;
if ( F_70 ( V_21 -> V_105 ) )
F_71 () ;
F_45 ( V_21 ) ;
} while ( V_21 -> V_105 && ! F_72 ( V_106 ) );
F_73 ( V_108 ) ;
return ( V_21 -> V_105 == NULL ) ;
}
static int F_74 ( T_1 exp , enum V_55 type ,
struct V_82 T_5 * V_109 )
{
struct V_82 V_110 ;
T_1 V_111 ;
V_111 = F_23 ( exp , V_29 [ type ] . V_35 () ) ;
if ( V_111 <= 0 )
return 0 ;
V_110 = F_58 ( V_111 ) ;
if ( F_75 ( V_109 , & V_110 , sizeof( * V_109 ) ) )
return - V_112 ;
return 1 ;
}
static long T_6 F_76 ( struct V_113 * V_31 )
{
enum V_55 type = V_31 -> V_114 . V_65 ;
T_1 exp ;
struct V_82 T_5 * V_109 ;
struct V_21 V_21 ;
int V_3 = 0 ;
exp = V_31 -> V_114 . V_36 ;
F_61 ( & V_21 , type , F_66 ) ;
if ( F_68 ( & V_21 , exp ) )
goto V_115;
if ( F_77 ( V_106 ) )
F_35 ( exp , type ) ;
V_109 = V_31 -> V_114 . V_109 ;
if ( V_109 ) {
V_3 = F_74 ( exp , type , V_109 ) ;
if ( V_3 <= 0 )
goto V_115;
}
V_3 = - V_116 ;
V_115:
return V_3 ;
}
static int F_78 ( const T_4 V_81 , int V_2 ,
struct V_82 * V_117 , struct V_82 T_5 * V_109 )
{
enum V_55 type = F_52 ( V_81 ) ;
struct V_21 V_21 ;
T_1 exp ;
int V_3 = 0 ;
struct V_113 * V_31 ;
if ( ! F_1 () )
return - V_89 ;
if ( V_2 & ~ V_102 )
return - V_84 ;
if ( ! F_60 ( V_90 ) )
return - V_91 ;
F_61 ( & V_21 , type , F_66 ) ;
exp = F_65 ( * V_117 ) ;
if ( V_2 != V_102 ) {
T_1 V_39 = V_29 [ type ] . V_35 () ;
exp = F_32 ( V_39 , exp ) ;
}
if ( F_68 ( & V_21 , exp ) )
goto V_115;
if ( F_77 ( V_106 ) )
F_35 ( exp , type ) ;
if ( V_2 == V_102 ) {
V_3 = - V_118 ;
goto V_115;
}
if ( V_109 ) {
V_3 = F_74 ( exp , type , V_109 ) ;
if ( V_3 <= 0 )
goto V_115;
}
V_31 = & V_106 -> V_113 ;
V_31 -> V_119 = F_76 ;
V_31 -> V_114 . V_65 = type ;
V_31 -> V_114 . V_36 = exp ;
V_31 -> V_114 . V_109 = V_109 ;
V_3 = - V_116 ;
V_115:
return V_3 ;
}
static int T_7 F_79 ( void )
{
struct V_120 * V_121 ;
int error = 0 ;
int V_40 ;
struct V_122 V_123 = {
. V_124 = F_56 ,
. V_125 = F_57 ,
. V_126 = F_59 ,
. V_127 = F_64 ,
. V_128 = F_63 ,
. V_129 = F_62 ,
. V_130 = F_78 ,
} ;
F_8 () ;
if ( F_54 ( V_78 ) ) {
F_80 ( V_66 , & V_123 ) ;
F_80 ( V_67 , & V_123 ) ;
}
V_29 [ V_56 ] . V_131 = V_132 ;
V_29 [ V_56 ] . V_35 = & V_133 ;
V_29 [ V_58 ] . V_131 = V_134 ;
V_29 [ V_58 ] . V_35 = & V_135 ;
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
F_81 ( & V_29 [ V_40 ] . V_24 ) ;
F_82 ( & V_29 [ V_40 ] . V_33 ) ;
}
error = F_10 () ;
if ( error )
return error ;
error = F_83 ( & V_136 ) ;
if ( error )
goto V_137;
V_121 = F_84 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_85 ( V_121 ) ) {
error = F_86 ( V_121 ) ;
goto V_138;
}
V_52 = F_87 ( L_2 ) ;
return 0 ;
V_138:
F_88 ( & V_136 ) ;
V_137:
F_12 () ;
return error ;
}
