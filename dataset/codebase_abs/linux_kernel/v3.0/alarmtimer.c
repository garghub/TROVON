static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_6 -> V_7 )
return 0 ;
if ( ! F_3 ( V_5 -> V_2 . V_8 ) )
return 0 ;
* ( const char * * ) V_3 = F_4 ( V_2 ) ;
return 1 ;
}
static struct V_4 * F_5 ( void )
{
struct V_1 * V_2 ;
char * V_9 ;
unsigned long V_10 ;
struct V_4 * V_11 ;
F_6 ( & V_12 , V_10 ) ;
if ( ! V_13 ) {
V_2 = F_7 ( V_14 , NULL , & V_9 , F_1 ) ;
if ( V_2 ) {
V_13 = F_8 ( V_9 ) ;
F_9 ( V_2 ) ;
F_10 ( & V_15 , NULL , NULL ) ;
}
}
V_11 = V_13 ;
F_11 ( & V_12 , V_10 ) ;
return V_11 ;
}
static void F_12 ( struct V_16 * V_17 , struct V_18 * V_18 )
{
F_13 ( & V_17 -> V_19 , & V_18 -> V_20 ) ;
if ( & V_18 -> V_20 == F_14 ( & V_17 -> V_19 ) ) {
F_15 ( & V_17 -> V_21 ) ;
F_16 ( & V_17 -> V_21 , V_18 -> V_20 . V_22 ,
V_23 ) ;
}
}
static void F_17 ( struct V_16 * V_17 , struct V_18 * V_18 )
{
struct V_24 * V_25 = F_14 ( & V_17 -> V_19 ) ;
F_18 ( & V_17 -> V_19 , & V_18 -> V_20 ) ;
if ( V_25 == & V_18 -> V_20 ) {
F_15 ( & V_17 -> V_21 ) ;
V_25 = F_14 ( & V_17 -> V_19 ) ;
if ( ! V_25 )
return;
F_16 ( & V_17 -> V_21 , V_25 -> V_22 , V_23 ) ;
}
}
static enum V_26 F_19 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = F_20 ( V_21 , struct V_16 , V_21 ) ;
struct V_24 * V_25 ;
unsigned long V_10 ;
T_1 V_28 ;
int V_11 = V_29 ;
F_6 ( & V_17 -> V_30 , V_10 ) ;
V_28 = V_17 -> V_31 () ;
while ( ( V_25 = F_14 ( & V_17 -> V_19 ) ) ) {
struct V_18 * V_18 ;
T_1 V_32 = V_25 -> V_22 ;
if ( V_32 . V_33 >= V_28 . V_33 )
break;
V_18 = F_20 ( V_25 , struct V_18 , V_20 ) ;
F_18 ( & V_17 -> V_19 , & V_18 -> V_20 ) ;
V_18 -> V_34 = 0 ;
if ( V_18 -> V_35 . V_33 ) {
V_18 -> V_20 . V_22 = F_21 ( V_32 , V_18 -> V_35 ) ;
F_13 ( & V_17 -> V_19 , & V_18 -> V_20 ) ;
V_18 -> V_34 = 1 ;
}
F_11 ( & V_17 -> V_30 , V_10 ) ;
if ( V_18 -> V_36 )
V_18 -> V_36 ( V_18 ) ;
F_6 ( & V_17 -> V_30 , V_10 ) ;
}
if ( V_25 ) {
F_22 ( & V_17 -> V_21 , V_25 -> V_22 ) ;
V_11 = V_37 ;
}
F_11 ( & V_17 -> V_30 , V_10 ) ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_38 V_39 ;
T_1 V_40 , V_28 ;
unsigned long V_10 ;
struct V_4 * V_41 ;
int V_42 ;
F_6 ( & V_43 , V_10 ) ;
V_40 = V_44 ;
V_44 = F_24 ( 0 , 0 ) ;
F_11 ( & V_43 , V_10 ) ;
V_41 = V_13 ;
if ( ! V_41 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
struct V_16 * V_17 = & V_46 [ V_42 ] ;
struct V_24 * V_25 ;
T_1 V_47 ;
F_6 ( & V_17 -> V_30 , V_10 ) ;
V_25 = F_14 ( & V_17 -> V_19 ) ;
F_11 ( & V_17 -> V_30 , V_10 ) ;
if ( ! V_25 )
continue;
V_47 = F_25 ( V_25 -> V_22 , V_17 -> V_31 () ) ;
if ( ! V_40 . V_33 || ( V_47 . V_33 < V_40 . V_33 ) )
V_40 = V_47 ;
}
if ( V_40 . V_33 == 0 )
return 0 ;
F_26 ( V_40 . V_33 < V_48 ) ;
F_27 ( V_41 , & V_15 ) ;
F_28 ( V_41 , & V_39 ) ;
V_28 = F_29 ( V_39 ) ;
V_28 = F_21 ( V_28 , V_40 ) ;
F_30 ( V_41 , & V_15 , V_28 , F_24 ( 0 , 0 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_31 ( T_1 V_49 , enum V_50 type )
{
T_1 V_47 ;
unsigned long V_10 ;
struct V_16 * V_17 = & V_46 [ type ] ;
V_47 = F_25 ( V_49 , V_17 -> V_31 () ) ;
F_6 ( & V_43 , V_10 ) ;
if ( ! V_44 . V_33 || ( V_47 . V_33 < V_44 . V_33 ) )
V_44 = V_47 ;
F_11 ( & V_43 , V_10 ) ;
}
void F_32 ( struct V_18 * V_18 , enum V_50 type ,
void (* V_36)( struct V_18 * ) )
{
F_33 ( & V_18 -> V_20 ) ;
V_18 -> V_35 = F_24 ( 0 , 0 ) ;
V_18 -> V_36 = V_36 ;
V_18 -> type = type ;
V_18 -> V_34 = 0 ;
}
void F_34 ( struct V_18 * V_18 , T_1 V_51 , T_1 V_35 )
{
struct V_16 * V_17 = & V_46 [ V_18 -> type ] ;
unsigned long V_10 ;
F_6 ( & V_17 -> V_30 , V_10 ) ;
if ( V_18 -> V_34 )
F_17 ( V_17 , V_18 ) ;
V_18 -> V_20 . V_22 = V_51 ;
V_18 -> V_35 = V_35 ;
F_12 ( V_17 , V_18 ) ;
V_18 -> V_34 = 1 ;
F_11 ( & V_17 -> V_30 , V_10 ) ;
}
void F_35 ( struct V_18 * V_18 )
{
struct V_16 * V_17 = & V_46 [ V_18 -> type ] ;
unsigned long V_10 ;
F_6 ( & V_17 -> V_30 , V_10 ) ;
if ( V_18 -> V_34 )
F_17 ( V_17 , V_18 ) ;
V_18 -> V_34 = 0 ;
F_11 ( & V_17 -> V_30 , V_10 ) ;
}
static enum V_50 F_36 ( T_2 V_52 )
{
if ( V_52 == V_53 )
return V_54 ;
if ( V_52 == V_55 )
return V_56 ;
return - 1 ;
}
static void F_37 ( struct V_18 * V_18 )
{
struct V_57 * V_58 = F_20 ( V_18 , struct V_57 ,
V_59 . V_60 ) ;
if ( F_38 ( V_58 , 0 ) != 0 )
V_58 -> V_61 ++ ;
}
static int F_39 ( const T_2 V_62 , struct V_63 * V_64 )
{
T_2 V_65 = V_46 [ F_36 ( V_62 ) ] . V_66 ;
if ( ! F_5 () )
return - V_67 ;
return F_40 ( V_65 , V_64 ) ;
}
static int F_41 ( T_2 V_62 , struct V_63 * V_64 )
{
struct V_16 * V_17 = & V_46 [ F_36 ( V_62 ) ] ;
if ( ! F_5 () )
return - V_67 ;
* V_64 = F_42 ( V_17 -> V_31 () ) ;
return 0 ;
}
static int F_43 ( struct V_57 * V_68 )
{
enum V_50 type ;
struct V_16 * V_17 ;
if ( ! F_5 () )
return - V_67 ;
if ( ! F_44 ( V_69 ) )
return - V_70 ;
type = F_36 ( V_68 -> V_71 ) ;
V_17 = & V_46 [ type ] ;
F_32 ( & V_68 -> V_59 . V_60 , type , F_37 ) ;
return 0 ;
}
static void F_45 ( struct V_57 * V_72 ,
struct V_73 * V_74 )
{
V_74 -> V_75 =
F_42 ( V_72 -> V_59 . V_60 . V_35 ) ;
V_74 -> V_76 =
F_42 ( V_72 -> V_59 . V_60 . V_20 . V_22 ) ;
return;
}
static int F_46 ( struct V_57 * V_72 )
{
if ( ! V_13 )
return - V_67 ;
F_35 ( & V_72 -> V_59 . V_60 ) ;
return 0 ;
}
static int F_47 ( struct V_57 * V_72 , int V_10 ,
struct V_73 * V_77 ,
struct V_73 * V_78 )
{
if ( ! V_13 )
return - V_67 ;
V_78 -> V_75 =
F_42 ( V_72 -> V_59 . V_60 . V_35 ) ;
V_78 -> V_76 =
F_42 ( V_72 -> V_59 . V_60 . V_20 . V_22 ) ;
F_35 ( & V_72 -> V_59 . V_60 ) ;
F_34 ( & V_72 -> V_59 . V_60 ,
F_48 ( V_77 -> V_76 ) ,
F_48 ( V_77 -> V_75 ) ) ;
return 0 ;
}
static void F_49 ( struct V_18 * V_18 )
{
struct V_79 * V_80 = (struct V_79 * ) V_18 -> V_81 ;
V_18 -> V_81 = NULL ;
if ( V_80 )
F_50 ( V_80 ) ;
}
static int F_51 ( struct V_18 * V_18 , T_1 V_49 )
{
V_18 -> V_81 = ( void * ) V_82 ;
do {
F_52 ( V_83 ) ;
F_34 ( V_18 , V_49 , F_24 ( 0 , 0 ) ) ;
if ( F_53 ( V_18 -> V_81 ) )
F_54 () ;
F_35 ( V_18 ) ;
} while ( V_18 -> V_81 && ! F_55 ( V_82 ) );
F_56 ( V_84 ) ;
return ( V_18 -> V_81 == NULL ) ;
}
static int F_57 ( T_1 exp , enum V_50 type ,
struct V_63 T_3 * V_85 )
{
struct V_63 V_86 ;
T_1 V_87 ;
V_87 = F_25 ( exp , V_46 [ type ] . V_31 () ) ;
if ( V_87 . V_33 <= 0 )
return 0 ;
V_86 = F_42 ( V_87 ) ;
if ( F_58 ( V_85 , & V_86 , sizeof( * V_85 ) ) )
return - V_88 ;
return 1 ;
}
static long T_4 F_59 ( struct V_89 * V_90 )
{
enum V_50 type = V_90 -> V_91 . V_52 ;
T_1 exp ;
struct V_63 T_3 * V_85 ;
struct V_18 V_18 ;
int V_11 = 0 ;
exp . V_33 = V_90 -> V_91 . V_22 ;
F_32 ( & V_18 , type , F_49 ) ;
if ( F_51 ( & V_18 , exp ) )
goto V_92;
if ( F_60 ( V_82 ) )
F_31 ( exp , type ) ;
V_85 = V_90 -> V_91 . V_85 ;
if ( V_85 ) {
V_11 = F_57 ( exp , type , V_85 ) ;
if ( V_11 <= 0 )
goto V_92;
}
V_11 = - V_93 ;
V_92:
return V_11 ;
}
static int F_61 ( const T_2 V_62 , int V_10 ,
struct V_63 * V_94 , struct V_63 T_3 * V_85 )
{
enum V_50 type = F_36 ( V_62 ) ;
struct V_18 V_18 ;
T_1 exp ;
int V_11 = 0 ;
struct V_89 * V_90 ;
if ( ! F_5 () )
return - V_67 ;
if ( ! F_44 ( V_69 ) )
return - V_70 ;
F_32 ( & V_18 , type , F_49 ) ;
exp = F_48 ( * V_94 ) ;
if ( V_10 != V_95 ) {
T_1 V_28 = V_46 [ type ] . V_31 () ;
exp = F_21 ( V_28 , exp ) ;
}
if ( F_51 ( & V_18 , exp ) )
goto V_92;
if ( F_60 ( V_82 ) )
F_31 ( exp , type ) ;
if ( V_10 == V_95 ) {
V_11 = - V_96 ;
goto V_92;
}
if ( V_85 ) {
V_11 = F_57 ( exp , type , V_85 ) ;
if ( V_11 <= 0 )
goto V_92;
}
V_90 = & F_62 () -> V_89 ;
V_90 -> V_97 = F_59 ;
V_90 -> V_91 . V_52 = type ;
V_90 -> V_91 . V_22 = exp . V_33 ;
V_90 -> V_91 . V_85 = V_85 ;
V_11 = - V_93 ;
V_92:
return V_11 ;
}
static int T_5 F_63 ( void )
{
int error = 0 ;
int V_42 ;
struct V_98 V_99 = {
. V_100 = F_39 ,
. V_101 = F_41 ,
. V_102 = F_43 ,
. V_103 = F_47 ,
. V_104 = F_46 ,
. V_105 = F_45 ,
. V_106 = F_61 ,
} ;
F_64 ( V_53 , & V_99 ) ;
F_64 ( V_55 , & V_99 ) ;
V_46 [ V_54 ] . V_66 = V_107 ;
V_46 [ V_54 ] . V_31 = & V_108 ;
V_46 [ V_56 ] . V_66 = V_109 ;
V_46 [ V_56 ] . V_31 = & V_110 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
F_65 ( & V_46 [ V_42 ] . V_19 ) ;
F_66 ( & V_46 [ V_42 ] . V_30 ) ;
F_67 ( & V_46 [ V_42 ] . V_21 ,
V_46 [ V_42 ] . V_66 ,
V_23 ) ;
V_46 [ V_42 ] . V_21 . V_36 = F_19 ;
}
error = F_68 ( & V_111 ) ;
F_69 ( L_1 , - 1 , NULL , 0 ) ;
return error ;
}
