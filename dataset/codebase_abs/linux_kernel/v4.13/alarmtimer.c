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
void F_35 ( struct V_21 * V_21 , T_1 V_54 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_21 -> V_25 . V_36 = V_54 ;
F_14 ( V_20 , V_21 ) ;
F_36 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 , V_55 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
F_37 ( V_21 , V_20 -> V_35 () ) ;
}
void F_38 ( struct V_21 * V_21 , T_1 V_54 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
V_54 = F_39 ( V_54 , V_20 -> V_35 () ) ;
F_35 ( V_21 , V_54 ) ;
}
void F_40 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
F_20 ( & V_21 -> V_28 , V_21 -> V_25 . V_36 ) ;
V_26 ( & V_21 -> V_28 ) ;
F_14 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
}
int F_41 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
unsigned long V_2 ;
int V_3 ;
F_2 ( & V_20 -> V_33 , V_2 ) ;
V_3 = F_42 ( & V_21 -> V_28 ) ;
if ( V_3 >= 0 )
F_17 ( V_20 , V_21 ) ;
F_3 ( & V_20 -> V_33 , V_2 ) ;
F_43 ( V_21 , V_20 -> V_35 () ) ;
return V_3 ;
}
int F_44 ( struct V_21 * V_21 )
{
for (; ; ) {
int V_3 = F_41 ( V_21 ) ;
if ( V_3 >= 0 )
return V_3 ;
F_45 () ;
}
}
T_2 F_46 ( struct V_21 * V_21 , T_1 V_39 , T_1 V_56 )
{
T_2 V_57 = 1 ;
T_1 V_50 ;
V_50 = F_23 ( V_39 , V_21 -> V_25 . V_36 ) ;
if ( V_50 < 0 )
return 0 ;
if ( F_47 ( V_50 >= V_56 ) ) {
T_3 V_58 = F_26 ( V_56 ) ;
V_57 = F_48 ( V_50 , V_58 ) ;
V_21 -> V_25 . V_36 = F_49 ( V_21 -> V_25 . V_36 ,
V_58 * V_57 ) ;
if ( V_21 -> V_25 . V_36 > V_39 )
return V_57 ;
V_57 ++ ;
}
V_21 -> V_25 . V_36 = F_39 ( V_21 -> V_25 . V_36 , V_56 ) ;
return V_57 ;
}
T_2 F_50 ( struct V_21 * V_21 , T_1 V_56 )
{
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
return F_46 ( V_21 , V_20 -> V_35 () , V_56 ) ;
}
static void F_51 ( T_1 V_59 , enum V_60 type )
{
struct V_19 * V_20 ;
unsigned long V_2 ;
T_1 V_50 ;
switch( type ) {
case V_61 :
V_20 = & V_29 [ V_61 ] ;
type = V_62 ;
break;
case V_63 :
V_20 = & V_29 [ V_63 ] ;
type = V_64 ;
break;
default:
F_52 ( 1 , L_1 , type ) ;
return;
}
V_50 = F_23 ( V_59 , V_20 -> V_35 () ) ;
F_2 ( & V_43 , V_2 ) ;
if ( ! V_44 || ( V_50 < V_44 ) ) {
V_44 = V_50 ;
V_45 = V_59 ;
V_46 = type ;
}
F_3 ( & V_43 , V_2 ) ;
}
static enum V_60 F_53 ( T_4 V_65 )
{
if ( V_65 == V_66 )
return V_61 ;
if ( V_65 == V_67 )
return V_63 ;
return - 1 ;
}
static enum V_68 F_54 ( struct V_21 * V_21 ,
T_1 V_39 )
{
struct V_69 * V_70 = F_19 ( V_21 , struct V_69 ,
V_71 . V_21 . V_72 ) ;
enum V_68 V_73 = V_32 ;
unsigned long V_2 ;
int V_74 = 0 ;
F_2 ( & V_70 -> V_75 , V_2 ) ;
V_70 -> V_76 = 0 ;
if ( V_70 -> V_77 )
V_74 = ++ V_70 -> V_78 ;
if ( F_55 ( V_70 , V_74 ) && V_70 -> V_77 ) {
V_70 -> V_79 += F_50 ( V_21 , V_70 -> V_77 ) ;
++ V_70 -> V_78 ;
V_70 -> V_76 = 1 ;
V_73 = V_80 ;
}
F_3 ( & V_70 -> V_75 , V_2 ) ;
return V_73 ;
}
static void F_56 ( struct V_69 * V_81 )
{
struct V_21 * V_21 = & V_81 -> V_71 . V_21 . V_72 ;
V_81 -> V_79 += F_50 ( V_21 , V_81 -> V_77 ) ;
F_35 ( V_21 , V_21 -> V_25 . V_36 ) ;
}
static int F_57 ( struct V_69 * V_81 , T_1 V_39 )
{
struct V_21 * V_21 = & V_81 -> V_71 . V_21 . V_72 ;
return ( int ) F_46 ( V_21 , V_81 -> V_77 , V_39 ) ;
}
static T_1 F_58 ( struct V_69 * V_81 , T_1 V_39 )
{
struct V_21 * V_21 = & V_81 -> V_71 . V_21 . V_72 ;
return F_23 ( V_39 , V_21 -> V_25 . V_36 ) ;
}
static int F_59 ( struct V_69 * V_81 )
{
return F_41 ( & V_81 -> V_71 . V_21 . V_72 ) ;
}
static void F_60 ( struct V_69 * V_81 , T_1 V_36 ,
bool V_82 , bool V_83 )
{
struct V_21 * V_21 = & V_81 -> V_71 . V_21 . V_72 ;
struct V_19 * V_20 = & V_29 [ V_21 -> type ] ;
if ( ! V_82 )
V_36 = F_39 ( V_36 , V_20 -> V_35 () ) ;
if ( V_83 )
V_21 -> V_25 . V_36 = V_36 ;
else
F_35 ( & V_81 -> V_71 . V_21 . V_72 , V_36 ) ;
}
static int F_61 ( const T_4 V_84 , struct V_85 * V_86 )
{
if ( ! F_1 () )
return - V_87 ;
V_86 -> V_88 = 0 ;
V_86 -> V_89 = V_90 ;
return 0 ;
}
static int F_62 ( T_4 V_84 , struct V_85 * V_86 )
{
struct V_19 * V_20 = & V_29 [ F_53 ( V_84 ) ] ;
if ( ! F_1 () )
return - V_87 ;
* V_86 = F_63 ( V_20 -> V_35 () ) ;
return 0 ;
}
static int F_64 ( struct V_69 * V_91 )
{
enum V_60 type ;
if ( ! F_1 () )
return - V_92 ;
if ( ! F_65 ( V_93 ) )
return - V_94 ;
type = F_53 ( V_91 -> V_95 ) ;
F_66 ( & V_91 -> V_71 . V_21 . V_72 , type , F_54 ) ;
return 0 ;
}
static enum V_68 F_67 ( struct V_21 * V_21 ,
T_1 V_39 )
{
struct V_96 * V_97 = (struct V_96 * ) V_21 -> V_98 ;
V_21 -> V_98 = NULL ;
if ( V_97 )
F_68 ( V_97 ) ;
return V_32 ;
}
static int F_69 ( struct V_21 * V_21 , T_1 V_59 ,
enum V_60 type )
{
struct V_99 * V_31 ;
V_21 -> V_98 = ( void * ) V_100 ;
do {
F_70 ( V_101 ) ;
F_35 ( V_21 , V_59 ) ;
if ( F_71 ( V_21 -> V_98 ) )
F_72 () ;
F_44 ( V_21 ) ;
} while ( V_21 -> V_98 && ! F_73 ( V_100 ) );
F_74 ( V_102 ) ;
if ( ! V_21 -> V_98 )
return 0 ;
if ( F_75 ( V_100 ) )
F_51 ( V_59 , type ) ;
V_31 = & V_100 -> V_99 ;
if ( V_31 -> V_103 . type != V_104 ) {
struct V_85 V_105 ;
T_1 V_106 ;
V_106 = F_23 ( V_59 , V_29 [ type ] . V_35 () ) ;
if ( V_106 <= 0 )
return 0 ;
V_105 = F_63 ( V_106 ) ;
return F_76 ( V_31 , & V_105 ) ;
}
return - V_107 ;
}
static long T_5 F_77 ( struct V_99 * V_31 )
{
enum V_60 type = V_31 -> V_103 . V_65 ;
T_1 exp = V_31 -> V_103 . V_36 ;
struct V_21 V_21 ;
F_66 ( & V_21 , type , F_67 ) ;
return F_69 ( & V_21 , exp , type ) ;
}
static int F_78 ( const T_4 V_84 , int V_2 ,
const struct V_85 * V_108 )
{
enum V_60 type = F_53 ( V_84 ) ;
struct V_99 * V_31 = & V_100 -> V_99 ;
struct V_21 V_21 ;
T_1 exp ;
int V_3 = 0 ;
if ( ! F_1 () )
return - V_92 ;
if ( V_2 & ~ V_109 )
return - V_87 ;
if ( ! F_65 ( V_93 ) )
return - V_94 ;
F_66 ( & V_21 , type , F_67 ) ;
exp = F_79 ( * V_108 ) ;
if ( V_2 != V_109 ) {
T_1 V_39 = V_29 [ type ] . V_35 () ;
exp = F_32 ( V_39 , exp ) ;
}
V_3 = F_69 ( & V_21 , exp , type ) ;
if ( V_3 != - V_107 )
return V_3 ;
if ( V_2 == V_109 )
return - V_110 ;
V_31 -> V_111 = F_77 ;
V_31 -> V_103 . V_65 = type ;
V_31 -> V_103 . V_36 = exp ;
return V_3 ;
}
static int T_6 F_80 ( void )
{
struct V_112 * V_113 ;
int error = 0 ;
int V_40 ;
F_8 () ;
V_29 [ V_61 ] . V_114 = V_115 ;
V_29 [ V_61 ] . V_35 = & V_116 ;
V_29 [ V_63 ] . V_114 = V_117 ;
V_29 [ V_63 ] . V_35 = & V_118 ;
for ( V_40 = 0 ; V_40 < V_47 ; V_40 ++ ) {
F_81 ( & V_29 [ V_40 ] . V_24 ) ;
F_82 ( & V_29 [ V_40 ] . V_33 ) ;
}
error = F_10 () ;
if ( error )
return error ;
error = F_83 ( & V_119 ) ;
if ( error )
goto V_120;
V_113 = F_84 ( L_2 , - 1 , NULL , 0 ) ;
if ( F_85 ( V_113 ) ) {
error = F_86 ( V_113 ) ;
goto V_121;
}
V_52 = F_87 ( L_2 ) ;
return 0 ;
V_121:
F_88 ( & V_119 ) ;
V_120:
F_12 () ;
return error ;
}
