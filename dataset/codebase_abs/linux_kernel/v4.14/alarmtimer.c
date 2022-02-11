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
struct V_11 * V_12 ;
if ( V_5 )
return - V_13 ;
if ( ! V_10 -> V_14 -> V_15 )
return - 1 ;
if ( ! F_6 ( V_10 -> V_7 . V_16 ) )
return - 1 ;
V_12 = F_7 ( L_1 ) ;
F_2 ( & V_4 , V_2 ) ;
if ( ! V_5 ) {
if ( ! F_8 ( V_10 -> V_17 ) ) {
F_3 ( & V_4 , V_2 ) ;
return - 1 ;
}
V_5 = V_10 ;
F_9 ( V_7 ) ;
V_18 = V_12 ;
V_12 = NULL ;
}
F_3 ( & V_4 , V_2 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
static inline void F_11 ( void )
{
F_12 ( & V_19 , NULL , NULL ) ;
}
static int F_13 ( void )
{
V_20 . V_21 = V_22 ;
return F_14 ( & V_20 ) ;
}
static void F_15 ( void )
{
F_16 ( & V_20 ) ;
}
struct V_1 * F_1 ( void )
{
return NULL ;
}
static inline int F_13 ( void ) { return 0 ; }
static inline void F_15 ( void ) { }
static inline void F_11 ( void ) { }
static void F_17 ( struct V_23 * V_24 , struct V_25 * V_25 )
{
if ( V_25 -> V_26 & V_27 )
F_18 ( & V_24 -> V_28 , & V_25 -> V_29 ) ;
F_19 ( & V_24 -> V_28 , & V_25 -> V_29 ) ;
V_25 -> V_26 |= V_27 ;
}
static void F_20 ( struct V_23 * V_24 , struct V_25 * V_25 )
{
if ( ! ( V_25 -> V_26 & V_27 ) )
return;
F_18 ( & V_24 -> V_28 , & V_25 -> V_29 ) ;
V_25 -> V_26 &= ~ V_27 ;
}
static enum V_30 F_21 ( struct V_31 * V_32 )
{
struct V_25 * V_25 = F_22 ( V_32 , struct V_25 , V_32 ) ;
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
unsigned long V_2 ;
int V_3 = V_34 ;
int V_35 = V_36 ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
F_20 ( V_24 , V_25 ) ;
F_3 ( & V_24 -> V_37 , V_2 ) ;
if ( V_25 -> V_38 )
V_35 = V_25 -> V_38 ( V_25 , V_24 -> V_39 () ) ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
if ( V_35 != V_36 ) {
F_23 ( & V_25 -> V_32 , V_25 -> V_29 . V_40 ) ;
F_17 ( V_24 , V_25 ) ;
V_3 = V_41 ;
}
F_3 ( & V_24 -> V_37 , V_2 ) ;
F_24 ( V_25 , V_24 -> V_39 () ) ;
return V_3 ;
}
T_1 F_25 ( const struct V_25 * V_25 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
return F_26 ( V_25 -> V_29 . V_40 , V_24 -> V_39 () ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
T_1 V_42 , V_43 , V_40 ;
int V_44 , V_3 , type ;
struct V_1 * V_10 ;
unsigned long V_2 ;
struct V_45 V_46 ;
F_2 ( & V_47 , V_2 ) ;
V_42 = V_48 ;
V_40 = V_49 ;
type = V_50 ;
V_48 = 0 ;
F_3 ( & V_47 , V_2 ) ;
V_10 = F_1 () ;
if ( ! V_10 )
return 0 ;
for ( V_44 = 0 ; V_44 < V_51 ; V_44 ++ ) {
struct V_23 * V_24 = & V_33 [ V_44 ] ;
struct V_52 * V_53 ;
T_1 V_54 ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
V_53 = F_28 ( & V_24 -> V_28 ) ;
F_3 ( & V_24 -> V_37 , V_2 ) ;
if ( ! V_53 )
continue;
V_54 = F_26 ( V_53 -> V_40 , V_24 -> V_39 () ) ;
if ( ! V_42 || ( V_54 < V_42 ) ) {
V_40 = V_53 -> V_40 ;
V_42 = V_54 ;
type = V_44 ;
}
}
if ( V_42 == 0 )
return 0 ;
if ( F_29 ( V_42 ) < 2 * V_55 ) {
F_30 ( V_18 , 2 * V_56 ) ;
return - V_13 ;
}
F_31 ( V_40 , type ) ;
F_32 ( V_10 , & V_19 ) ;
F_33 ( V_10 , & V_46 ) ;
V_43 = F_34 ( V_46 ) ;
V_43 = F_35 ( V_43 , V_42 ) ;
V_3 = F_36 ( V_10 , & V_19 , V_43 , 0 ) ;
if ( V_3 < 0 )
F_30 ( V_18 , V_56 ) ;
return V_3 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_10 ;
V_10 = F_1 () ;
if ( V_10 )
F_32 ( V_10 , & V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
return 0 ;
}
void F_38 ( struct V_25 * V_25 , T_1 V_57 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
V_25 -> V_29 . V_40 = V_57 ;
F_17 ( V_24 , V_25 ) ;
F_39 ( & V_25 -> V_32 , V_25 -> V_29 . V_40 , V_58 ) ;
F_3 ( & V_24 -> V_37 , V_2 ) ;
F_40 ( V_25 , V_24 -> V_39 () ) ;
}
void F_41 ( struct V_25 * V_25 , T_1 V_57 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
V_57 = F_42 ( V_57 , V_24 -> V_39 () ) ;
F_38 ( V_25 , V_57 ) ;
}
void F_43 ( struct V_25 * V_25 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
F_23 ( & V_25 -> V_32 , V_25 -> V_29 . V_40 ) ;
V_30 ( & V_25 -> V_32 ) ;
F_17 ( V_24 , V_25 ) ;
F_3 ( & V_24 -> V_37 , V_2 ) ;
}
int F_44 ( struct V_25 * V_25 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_24 -> V_37 , V_2 ) ;
V_3 = F_45 ( & V_25 -> V_32 ) ;
if ( V_3 >= 0 )
F_20 ( V_24 , V_25 ) ;
F_3 ( & V_24 -> V_37 , V_2 ) ;
F_46 ( V_25 , V_24 -> V_39 () ) ;
return V_3 ;
}
int F_47 ( struct V_25 * V_25 )
{
for (; ; ) {
int V_3 = F_44 ( V_25 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_48 () ;
}
}
T_2 F_49 ( struct V_25 * V_25 , T_1 V_43 , T_1 V_59 )
{
T_2 V_60 = 1 ;
T_1 V_54 ;
V_54 = F_26 ( V_43 , V_25 -> V_29 . V_40 ) ;
if ( V_54 < 0 )
return 0 ;
if ( F_50 ( V_54 >= V_59 ) ) {
T_3 V_61 = F_29 ( V_59 ) ;
V_60 = F_51 ( V_54 , V_61 ) ;
V_25 -> V_29 . V_40 = F_52 ( V_25 -> V_29 . V_40 ,
V_61 * V_60 ) ;
if ( V_25 -> V_29 . V_40 > V_43 )
return V_60 ;
V_60 ++ ;
}
V_25 -> V_29 . V_40 = F_42 ( V_25 -> V_29 . V_40 , V_59 ) ;
return V_60 ;
}
T_2 F_53 ( struct V_25 * V_25 , T_1 V_59 )
{
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
return F_49 ( V_25 , V_24 -> V_39 () , V_59 ) ;
}
static void F_54 ( T_1 V_62 , enum V_63 type )
{
struct V_23 * V_24 ;
unsigned long V_2 ;
T_1 V_54 ;
switch( type ) {
case V_64 :
V_24 = & V_33 [ V_64 ] ;
type = V_65 ;
break;
case V_66 :
V_24 = & V_33 [ V_66 ] ;
type = V_67 ;
break;
default:
F_55 ( 1 , L_2 , type ) ;
return;
}
V_54 = F_26 ( V_62 , V_24 -> V_39 () ) ;
F_2 ( & V_47 , V_2 ) ;
if ( ! V_48 || ( V_54 < V_48 ) ) {
V_48 = V_54 ;
V_49 = V_62 ;
V_50 = type ;
}
F_3 ( & V_47 , V_2 ) ;
}
static enum V_63 F_56 ( T_4 V_68 )
{
if ( V_68 == V_69 )
return V_64 ;
if ( V_68 == V_70 )
return V_66 ;
return - 1 ;
}
static enum V_71 F_57 ( struct V_25 * V_25 ,
T_1 V_43 )
{
struct V_72 * V_73 = F_22 ( V_25 , struct V_72 ,
V_74 . V_25 . V_75 ) ;
enum V_71 V_76 = V_36 ;
unsigned long V_2 ;
int V_77 = 0 ;
F_2 ( & V_73 -> V_78 , V_2 ) ;
V_73 -> V_79 = 0 ;
if ( V_73 -> V_80 )
V_77 = ++ V_73 -> V_81 ;
if ( F_58 ( V_73 , V_77 ) && V_73 -> V_80 ) {
V_73 -> V_82 += F_53 ( V_25 , V_73 -> V_80 ) ;
++ V_73 -> V_81 ;
V_73 -> V_79 = 1 ;
V_76 = V_83 ;
}
F_3 ( & V_73 -> V_78 , V_2 ) ;
return V_76 ;
}
static void F_59 ( struct V_72 * V_84 )
{
struct V_25 * V_25 = & V_84 -> V_74 . V_25 . V_75 ;
V_84 -> V_82 += F_53 ( V_25 , V_84 -> V_80 ) ;
F_38 ( V_25 , V_25 -> V_29 . V_40 ) ;
}
static int F_60 ( struct V_72 * V_84 , T_1 V_43 )
{
struct V_25 * V_25 = & V_84 -> V_74 . V_25 . V_75 ;
return ( int ) F_49 ( V_25 , V_84 -> V_80 , V_43 ) ;
}
static T_1 F_61 ( struct V_72 * V_84 , T_1 V_43 )
{
struct V_25 * V_25 = & V_84 -> V_74 . V_25 . V_75 ;
return F_26 ( V_43 , V_25 -> V_29 . V_40 ) ;
}
static int F_62 ( struct V_72 * V_84 )
{
return F_44 ( & V_84 -> V_74 . V_25 . V_75 ) ;
}
static void F_63 ( struct V_72 * V_84 , T_1 V_40 ,
bool V_85 , bool V_86 )
{
struct V_25 * V_25 = & V_84 -> V_74 . V_25 . V_75 ;
struct V_23 * V_24 = & V_33 [ V_25 -> type ] ;
if ( ! V_85 )
V_40 = F_42 ( V_40 , V_24 -> V_39 () ) ;
if ( V_86 )
V_25 -> V_29 . V_40 = V_40 ;
else
F_38 ( & V_84 -> V_74 . V_25 . V_75 , V_40 ) ;
}
static int F_64 ( const T_4 V_87 , struct V_88 * V_89 )
{
if ( ! F_1 () )
return - V_90 ;
V_89 -> V_91 = 0 ;
V_89 -> V_92 = V_93 ;
return 0 ;
}
static int F_65 ( T_4 V_87 , struct V_88 * V_89 )
{
struct V_23 * V_24 = & V_33 [ F_56 ( V_87 ) ] ;
if ( ! F_1 () )
return - V_90 ;
* V_89 = F_66 ( V_24 -> V_39 () ) ;
return 0 ;
}
static int F_67 ( struct V_72 * V_94 )
{
enum V_63 type ;
if ( ! F_1 () )
return - V_95 ;
if ( ! F_68 ( V_96 ) )
return - V_97 ;
type = F_56 ( V_94 -> V_98 ) ;
F_69 ( & V_94 -> V_74 . V_25 . V_75 , type , F_57 ) ;
return 0 ;
}
static enum V_71 F_70 ( struct V_25 * V_25 ,
T_1 V_43 )
{
struct V_99 * V_100 = (struct V_99 * ) V_25 -> V_101 ;
V_25 -> V_101 = NULL ;
if ( V_100 )
F_71 ( V_100 ) ;
return V_36 ;
}
static int F_72 ( struct V_25 * V_25 , T_1 V_62 ,
enum V_63 type )
{
struct V_102 * V_35 ;
V_25 -> V_101 = ( void * ) V_103 ;
do {
F_73 ( V_104 ) ;
F_38 ( V_25 , V_62 ) ;
if ( F_74 ( V_25 -> V_101 ) )
F_75 () ;
F_47 ( V_25 ) ;
} while ( V_25 -> V_101 && ! F_76 ( V_103 ) );
F_77 ( V_105 ) ;
if ( ! V_25 -> V_101 )
return 0 ;
if ( F_78 ( V_103 ) )
F_54 ( V_62 , type ) ;
V_35 = & V_103 -> V_102 ;
if ( V_35 -> V_106 . type != V_107 ) {
struct V_88 V_108 ;
T_1 V_109 ;
V_109 = F_26 ( V_62 , V_33 [ type ] . V_39 () ) ;
if ( V_109 <= 0 )
return 0 ;
V_108 = F_66 ( V_109 ) ;
return F_79 ( V_35 , & V_108 ) ;
}
return - V_110 ;
}
static long T_5 F_80 ( struct V_102 * V_35 )
{
enum V_63 type = V_35 -> V_106 . V_68 ;
T_1 exp = V_35 -> V_106 . V_40 ;
struct V_25 V_25 ;
F_69 ( & V_25 , type , F_70 ) ;
return F_72 ( & V_25 , exp , type ) ;
}
static int F_81 ( const T_4 V_87 , int V_2 ,
const struct V_88 * V_111 )
{
enum V_63 type = F_56 ( V_87 ) ;
struct V_102 * V_35 = & V_103 -> V_102 ;
struct V_25 V_25 ;
T_1 exp ;
int V_3 = 0 ;
if ( ! F_1 () )
return - V_95 ;
if ( V_2 & ~ V_112 )
return - V_90 ;
if ( ! F_68 ( V_96 ) )
return - V_97 ;
F_69 ( & V_25 , type , F_70 ) ;
exp = F_82 ( * V_111 ) ;
if ( V_2 != V_112 ) {
T_1 V_43 = V_33 [ type ] . V_39 () ;
exp = F_35 ( V_43 , exp ) ;
}
V_3 = F_72 ( & V_25 , exp , type ) ;
if ( V_3 != - V_110 )
return V_3 ;
if ( V_2 == V_112 )
return - V_113 ;
V_35 -> V_114 = F_80 ;
V_35 -> V_106 . V_68 = type ;
V_35 -> V_106 . V_40 = exp ;
return V_3 ;
}
static int T_6 F_83 ( void )
{
struct V_115 * V_116 ;
int error = 0 ;
int V_44 ;
F_11 () ;
V_33 [ V_64 ] . V_117 = V_118 ;
V_33 [ V_64 ] . V_39 = & V_119 ;
V_33 [ V_66 ] . V_117 = V_120 ;
V_33 [ V_66 ] . V_39 = & V_121 ;
for ( V_44 = 0 ; V_44 < V_51 ; V_44 ++ ) {
F_84 ( & V_33 [ V_44 ] . V_28 ) ;
F_85 ( & V_33 [ V_44 ] . V_37 ) ;
}
error = F_13 () ;
if ( error )
return error ;
error = F_86 ( & V_122 ) ;
if ( error )
goto V_123;
V_116 = F_87 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_88 ( V_116 ) ) {
error = F_89 ( V_116 ) ;
goto V_124;
}
return 0 ;
V_124:
F_90 ( & V_122 ) ;
V_123:
F_15 () ;
return error ;
}
