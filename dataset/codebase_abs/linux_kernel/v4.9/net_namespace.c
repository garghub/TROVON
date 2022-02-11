static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
T_1 V_3 = F_2 ( struct V_1 , V_4 [ V_5 ] ) ;
V_2 = F_3 ( V_3 , V_6 ) ;
if ( V_2 )
V_2 -> V_7 = V_5 ;
return V_2 ;
}
static int F_4 ( struct V_8 * V_8 , int V_9 , void * V_10 )
{
struct V_1 * V_2 , * V_11 ;
F_5 ( ! F_6 ( & V_12 ) ) ;
F_5 ( V_9 == 0 ) ;
V_11 = F_7 ( V_8 -> V_13 ,
F_8 ( & V_12 ) ) ;
V_2 = V_11 ;
if ( V_11 -> V_7 >= V_9 )
goto V_14;
V_2 = F_1 () ;
if ( V_2 == NULL )
return - V_15 ;
memcpy ( & V_2 -> V_4 , & V_11 -> V_4 , V_11 -> V_7 * sizeof( void * ) ) ;
F_9 ( V_8 -> V_13 , V_2 ) ;
F_10 ( V_11 , V_16 ) ;
V_14:
V_2 -> V_4 [ V_9 - 1 ] = V_10 ;
return 0 ;
}
static int F_11 ( const struct V_17 * V_18 , struct V_8 * V_8 )
{
int V_19 = - V_15 ;
void * V_10 = NULL ;
if ( V_18 -> V_9 && V_18 -> V_20 ) {
V_10 = F_3 ( V_18 -> V_20 , V_6 ) ;
if ( ! V_10 )
goto V_21;
V_19 = F_4 ( V_8 , * V_18 -> V_9 , V_10 ) ;
if ( V_19 )
goto V_22;
}
V_19 = 0 ;
if ( V_18 -> V_23 )
V_19 = V_18 -> V_23 ( V_8 ) ;
if ( ! V_19 )
return 0 ;
V_22:
F_12 ( V_10 ) ;
V_21:
return V_19 ;
}
static void F_13 ( const struct V_17 * V_18 , struct V_8 * V_8 )
{
if ( V_18 -> V_9 && V_18 -> V_20 ) {
int V_9 = * V_18 -> V_9 ;
F_12 ( V_1 ( V_8 , V_9 ) ) ;
}
}
static void F_14 ( const struct V_17 * V_18 ,
struct V_24 * V_25 )
{
struct V_8 * V_8 ;
if ( V_18 -> exit ) {
F_15 (net, net_exit_list, exit_list)
V_18 -> exit ( V_8 ) ;
}
if ( V_18 -> V_26 )
V_18 -> V_26 ( V_25 ) ;
}
static void F_16 ( const struct V_17 * V_18 ,
struct V_24 * V_25 )
{
struct V_8 * V_8 ;
if ( V_18 -> V_20 && V_18 -> V_9 ) {
F_15 (net, net_exit_list, exit_list)
F_13 ( V_18 , V_8 ) ;
}
}
static int F_17 ( struct V_8 * V_8 , struct V_8 * V_27 , int V_28 )
{
int V_29 = 0 , V_30 = 0 ;
if ( V_28 >= 0 ) {
V_29 = V_28 ;
V_30 = V_28 + 1 ;
}
return F_18 ( & V_8 -> V_31 , V_27 , V_29 , V_30 , V_32 ) ;
}
static int F_19 ( int V_9 , void * V_8 , void * V_27 )
{
if ( F_20 ( V_8 , V_27 ) )
return V_9 ? : V_33 ;
return 0 ;
}
static int F_21 ( struct V_8 * V_8 , struct V_8 * V_27 , bool * V_34 )
{
int V_9 = F_22 ( & V_8 -> V_31 , F_19 , V_27 ) ;
bool V_35 = * V_34 ;
* V_34 = false ;
if ( V_9 == V_33 )
return 0 ;
if ( V_9 > 0 )
return V_9 ;
if ( V_35 ) {
V_9 = F_17 ( V_8 , V_27 , - 1 ) ;
* V_34 = true ;
return V_9 >= 0 ? V_9 : V_36 ;
}
return V_36 ;
}
static int F_23 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
bool V_37 = false ;
return F_21 ( V_8 , V_27 , & V_37 ) ;
}
int F_24 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
unsigned long V_38 ;
bool V_34 ;
int V_9 ;
if ( F_25 ( & V_8 -> V_39 ) == 0 )
return V_36 ;
F_26 ( & V_8 -> V_40 , V_38 ) ;
V_34 = F_25 ( & V_27 -> V_39 ) == 0 ? false : true ;
V_9 = F_21 ( V_8 , V_27 , & V_34 ) ;
F_27 ( & V_8 -> V_40 , V_38 ) ;
if ( V_34 && V_9 >= 0 )
F_28 ( V_8 , V_41 , V_9 ) ;
return V_9 ;
}
int F_29 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
unsigned long V_38 ;
int V_9 ;
F_26 ( & V_8 -> V_40 , V_38 ) ;
V_9 = F_23 ( V_8 , V_27 ) ;
F_27 ( & V_8 -> V_40 , V_38 ) ;
return V_9 ;
}
bool F_30 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
return F_29 ( V_8 , V_27 ) >= 0 ;
}
struct V_8 * F_31 ( struct V_8 * V_8 , int V_9 )
{
unsigned long V_38 ;
struct V_8 * V_27 ;
if ( V_9 < 0 )
return NULL ;
F_32 () ;
F_26 ( & V_8 -> V_40 , V_38 ) ;
V_27 = F_33 ( & V_8 -> V_31 , V_9 ) ;
if ( V_27 )
F_34 ( V_27 ) ;
F_27 ( & V_8 -> V_40 , V_38 ) ;
F_35 () ;
return V_27 ;
}
static T_2 int F_36 ( struct V_8 * V_8 , struct V_42 * V_43 )
{
const struct V_17 * V_18 , * V_44 ;
int error = 0 ;
F_37 ( V_25 ) ;
F_38 ( & V_8 -> V_39 , 1 ) ;
F_38 ( & V_8 -> V_45 , 1 ) ;
V_8 -> V_46 = 1 ;
V_8 -> V_43 = V_43 ;
F_39 ( & V_8 -> V_31 ) ;
F_40 ( & V_8 -> V_40 ) ;
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_47;
}
V_21:
return error ;
V_47:
F_41 ( & V_8 -> V_48 , & V_25 ) ;
V_44 = V_18 ;
F_42 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
V_18 = V_44 ;
F_42 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_43 () ;
goto V_21;
}
static struct V_49 * F_44 ( struct V_42 * V_50 )
{
return F_45 ( V_50 , F_46 () , V_51 ) ;
}
static void F_47 ( struct V_49 * V_49 )
{
F_48 ( V_49 , V_51 ) ;
}
static struct V_8 * F_49 ( void )
{
struct V_8 * V_8 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_21;
V_8 = F_50 ( V_52 , V_6 ) ;
if ( ! V_8 )
goto V_53;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_21:
return V_8 ;
V_53:
F_12 ( V_2 ) ;
goto V_21;
}
static void F_51 ( struct V_8 * V_8 )
{
F_12 ( F_52 ( V_8 -> V_13 ) ) ;
F_53 ( V_52 , V_8 ) ;
}
void F_54 ( void * V_54 )
{
struct V_8 * V_50 = V_54 ;
if ( V_50 && F_55 ( & V_50 -> V_45 ) )
F_51 ( V_50 ) ;
}
struct V_8 * F_56 ( unsigned long V_38 ,
struct V_42 * V_43 , struct V_8 * V_55 )
{
struct V_49 * V_49 ;
struct V_8 * V_8 ;
int V_56 ;
if ( ! ( V_38 & V_57 ) )
return F_34 ( V_55 ) ;
V_49 = F_44 ( V_43 ) ;
if ( ! V_49 )
return F_57 ( - V_58 ) ;
V_8 = F_49 () ;
if ( ! V_8 ) {
F_47 ( V_49 ) ;
return F_57 ( - V_15 ) ;
}
F_58 ( V_43 ) ;
F_59 ( & V_12 ) ;
V_8 -> V_49 = V_49 ;
V_56 = F_36 ( V_8 , V_43 ) ;
if ( V_56 == 0 ) {
F_60 () ;
F_61 ( & V_8 -> V_59 , & V_60 ) ;
F_62 () ;
}
F_63 ( & V_12 ) ;
if ( V_56 < 0 ) {
F_47 ( V_49 ) ;
F_64 ( V_43 ) ;
F_54 ( V_8 ) ;
return F_57 ( V_56 ) ;
}
return V_8 ;
}
static void F_65 ( struct V_61 * V_62 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_63 ;
struct V_24 V_64 ;
F_37 ( V_25 ) ;
F_66 ( & V_65 ) ;
F_67 ( & V_66 , & V_64 ) ;
F_68 ( & V_65 ) ;
F_59 ( & V_12 ) ;
F_60 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_69 ( & V_8 -> V_59 ) ;
F_70 ( & V_8 -> V_48 , & V_25 ) ;
F_71 (tmp) {
int V_9 ;
F_66 ( & V_63 -> V_40 ) ;
V_9 = F_23 ( V_63 , V_8 ) ;
if ( V_9 >= 0 )
F_72 ( & V_63 -> V_31 , V_9 ) ;
F_68 ( & V_63 -> V_40 ) ;
if ( V_9 >= 0 )
F_28 ( V_63 , V_67 , V_9 ) ;
}
F_66 ( & V_8 -> V_40 ) ;
F_73 ( & V_8 -> V_31 ) ;
F_68 ( & V_8 -> V_40 ) ;
}
F_62 () ;
F_74 () ;
F_75 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_75 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_63 ( & V_12 ) ;
F_43 () ;
F_76 (net, tmp, &net_exit_list, exit_list) {
F_77 ( & V_8 -> V_48 ) ;
F_47 ( V_8 -> V_49 ) ;
F_64 ( V_8 -> V_43 ) ;
F_54 ( V_8 ) ;
}
}
void F_78 ( struct V_8 * V_8 )
{
unsigned long V_38 ;
F_26 ( & V_65 , V_38 ) ;
F_41 ( & V_8 -> V_66 , & V_66 ) ;
F_27 ( & V_65 , V_38 ) ;
F_79 ( V_68 , & V_69 ) ;
}
struct V_8 * F_80 ( int V_70 )
{
struct V_71 * V_71 ;
struct V_72 * V_50 ;
struct V_8 * V_8 ;
V_71 = F_81 ( V_70 ) ;
if ( F_82 ( V_71 ) )
return F_83 ( V_71 ) ;
V_50 = F_84 ( F_85 ( V_71 ) ) ;
if ( V_50 -> V_18 == & V_73 )
V_8 = F_34 ( F_86 ( V_50 , struct V_8 , V_50 ) ) ;
else
V_8 = F_57 ( - V_74 ) ;
F_87 ( V_71 ) ;
return V_8 ;
}
struct V_8 * F_80 ( int V_70 )
{
return F_57 ( - V_74 ) ;
}
struct V_8 * F_88 ( T_3 V_75 )
{
struct V_76 * V_77 ;
struct V_8 * V_8 ;
V_8 = F_57 ( - V_78 ) ;
F_32 () ;
V_77 = F_89 ( V_75 ) ;
if ( V_77 ) {
struct V_79 * V_79 ;
F_90 ( V_77 ) ;
V_79 = V_77 -> V_79 ;
if ( V_79 )
V_8 = F_34 ( V_79 -> V_80 ) ;
F_91 ( V_77 ) ;
}
F_35 () ;
return V_8 ;
}
static T_2 int F_92 ( struct V_8 * V_8 )
{
#ifdef F_93
V_8 -> V_50 . V_18 = & V_73 ;
#endif
return F_94 ( & V_8 -> V_50 ) ;
}
static T_4 void F_95 ( struct V_8 * V_8 )
{
F_96 ( & V_8 -> V_50 ) ;
}
static int F_97 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_8 * V_8 = F_98 ( V_82 -> V_85 ) ;
struct V_86 * V_87 [ V_88 + 1 ] ;
unsigned long V_38 ;
struct V_8 * V_27 ;
int V_89 , V_19 ;
V_19 = F_99 ( V_84 , sizeof( struct V_90 ) , V_87 , V_88 ,
V_91 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_87 [ V_92 ] )
return - V_74 ;
V_89 = F_100 ( V_87 [ V_92 ] ) ;
if ( V_87 [ V_93 ] )
V_27 = F_88 ( F_101 ( V_87 [ V_93 ] ) ) ;
else if ( V_87 [ V_94 ] )
V_27 = F_80 ( F_101 ( V_87 [ V_94 ] ) ) ;
else
return - V_74 ;
if ( F_82 ( V_27 ) )
return F_102 ( V_27 ) ;
F_26 ( & V_8 -> V_40 , V_38 ) ;
if ( F_23 ( V_8 , V_27 ) >= 0 ) {
F_27 ( & V_8 -> V_40 , V_38 ) ;
V_19 = - V_95 ;
goto V_21;
}
V_19 = F_17 ( V_8 , V_27 , V_89 ) ;
F_27 ( & V_8 -> V_40 , V_38 ) ;
if ( V_19 >= 0 ) {
F_28 ( V_8 , V_41 , V_19 ) ;
V_19 = 0 ;
}
V_21:
F_103 ( V_27 ) ;
return V_19 ;
}
static int F_104 ( void )
{
return F_105 ( sizeof( struct V_90 ) )
+ F_106 ( sizeof( V_96 ) )
;
}
static int F_107 ( struct V_81 * V_82 , T_5 V_97 , T_5 V_98 , int V_38 ,
int V_99 , struct V_8 * V_8 , int V_89 )
{
struct V_83 * V_84 ;
struct V_90 * V_100 ;
V_84 = F_108 ( V_82 , V_97 , V_98 , V_99 , sizeof( * V_100 ) , V_38 ) ;
if ( ! V_84 )
return - V_101 ;
V_100 = F_109 ( V_84 ) ;
V_100 -> V_102 = V_103 ;
if ( F_110 ( V_82 , V_92 , V_89 ) )
goto V_104;
F_111 ( V_82 , V_84 ) ;
return 0 ;
V_104:
F_112 ( V_82 , V_84 ) ;
return - V_101 ;
}
static int F_113 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_8 * V_8 = F_98 ( V_82 -> V_85 ) ;
struct V_86 * V_87 [ V_88 + 1 ] ;
struct V_81 * V_105 ;
struct V_8 * V_27 ;
int V_19 , V_9 ;
V_19 = F_99 ( V_84 , sizeof( struct V_90 ) , V_87 , V_88 ,
V_91 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_87 [ V_93 ] )
V_27 = F_88 ( F_101 ( V_87 [ V_93 ] ) ) ;
else if ( V_87 [ V_94 ] )
V_27 = F_80 ( F_101 ( V_87 [ V_94 ] ) ) ;
else
return - V_74 ;
if ( F_82 ( V_27 ) )
return F_102 ( V_27 ) ;
V_105 = F_114 ( F_104 () , V_6 ) ;
if ( ! V_105 ) {
V_19 = - V_15 ;
goto V_21;
}
V_9 = F_29 ( V_8 , V_27 ) ;
V_19 = F_107 ( V_105 , F_115 ( V_82 ) . V_97 , V_84 -> V_106 , 0 ,
V_41 , V_8 , V_9 ) ;
if ( V_19 < 0 )
goto V_107;
V_19 = F_116 ( V_105 , V_8 , F_115 ( V_82 ) . V_97 ) ;
goto V_21;
V_107:
F_117 ( V_105 ) ;
V_21:
F_103 ( V_27 ) ;
return V_19 ;
}
static int F_118 ( int V_9 , void * V_27 , void * V_10 )
{
struct V_108 * V_109 = (struct V_108 * ) V_10 ;
int V_110 ;
if ( V_109 -> V_111 < V_109 -> V_112 )
goto V_113;
V_110 = F_107 ( V_109 -> V_82 , F_115 ( V_109 -> V_114 -> V_82 ) . V_97 ,
V_109 -> V_114 -> V_84 -> V_106 , V_115 ,
V_41 , V_109 -> V_8 , V_9 ) ;
if ( V_110 < 0 )
return V_110 ;
V_113:
V_109 -> V_111 ++ ;
return 0 ;
}
static int F_119 ( struct V_81 * V_82 , struct V_116 * V_114 )
{
struct V_8 * V_8 = F_98 ( V_82 -> V_85 ) ;
struct V_108 V_109 = {
. V_8 = V_8 ,
. V_82 = V_82 ,
. V_114 = V_114 ,
. V_111 = 0 ,
. V_112 = V_114 -> args [ 0 ] ,
} ;
unsigned long V_38 ;
F_26 ( & V_8 -> V_40 , V_38 ) ;
F_22 ( & V_8 -> V_31 , F_118 , & V_109 ) ;
F_27 ( & V_8 -> V_40 , V_38 ) ;
V_114 -> args [ 0 ] = V_109 . V_111 ;
return V_82 -> V_7 ;
}
static void F_28 ( struct V_8 * V_8 , int V_99 , int V_9 )
{
struct V_81 * V_105 ;
int V_19 = - V_15 ;
V_105 = F_114 ( F_104 () , V_6 ) ;
if ( ! V_105 )
goto V_21;
V_19 = F_107 ( V_105 , 0 , 0 , 0 , V_99 , V_8 , V_9 ) ;
if ( V_19 < 0 )
goto V_107;
F_120 ( V_105 , V_8 , 0 , V_117 , NULL , 0 ) ;
return;
V_107:
F_117 ( V_105 ) ;
V_21:
F_121 ( V_8 , V_117 , V_19 ) ;
}
static int T_6 F_122 ( void )
{
struct V_1 * V_2 ;
#ifdef F_93
V_52 = F_123 ( L_1 , sizeof( struct V_8 ) ,
V_118 ,
V_119 , NULL ) ;
V_68 = F_124 ( L_2 ) ;
if ( ! V_68 )
F_125 ( L_3 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_125 ( L_4 ) ;
F_9 ( V_120 . V_13 , V_2 ) ;
F_59 ( & V_12 ) ;
if ( F_36 ( & V_120 , & V_121 ) )
F_125 ( L_5 ) ;
V_122 = true ;
F_60 () ;
F_61 ( & V_120 . V_59 , & V_60 ) ;
F_62 () ;
F_63 ( & V_12 ) ;
F_126 ( & V_123 ) ;
F_127 ( V_124 , V_41 , F_97 , NULL , NULL ) ;
F_127 ( V_124 , V_125 , F_113 , F_119 ,
NULL ) ;
return 0 ;
}
static int F_128 ( struct V_24 * V_59 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_37 ( V_25 ) ;
F_70 ( & V_18 -> V_59 , V_59 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_71 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_47;
F_70 ( & V_8 -> V_48 , & V_25 ) ;
}
}
return 0 ;
V_47:
F_129 ( & V_18 -> V_59 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_130 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_37 ( V_25 ) ;
F_129 ( & V_18 -> V_59 ) ;
F_71 (net)
F_70 ( & V_8 -> V_48 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_128 ( struct V_24 * V_59 ,
struct V_17 * V_18 )
{
if ( ! V_122 ) {
F_70 ( & V_18 -> V_59 , V_59 ) ;
return 0 ;
}
return F_11 ( V_18 , & V_120 ) ;
}
static void F_130 ( struct V_17 * V_18 )
{
if ( ! V_122 ) {
F_129 ( & V_18 -> V_59 ) ;
} else {
F_37 ( V_25 ) ;
F_41 ( & V_120 . V_48 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
}
static int F_131 ( struct V_24 * V_59 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_126:
error = F_132 ( & V_127 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_128 ) {
F_133 ( & V_127 , V_6 ) ;
goto V_126;
}
return error ;
}
V_5 = F_134 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_128 ( V_59 , V_18 ) ;
if ( error ) {
F_43 () ;
if ( V_18 -> V_9 )
F_135 ( & V_127 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_136 ( struct V_17 * V_18 )
{
F_130 ( V_18 ) ;
F_43 () ;
if ( V_18 -> V_9 )
F_135 ( & V_127 , * V_18 -> V_9 ) ;
}
int F_126 ( struct V_17 * V_18 )
{
int error ;
F_59 ( & V_12 ) ;
error = F_131 ( V_129 , V_18 ) ;
F_63 ( & V_12 ) ;
return error ;
}
void F_137 ( struct V_17 * V_18 )
{
F_59 ( & V_12 ) ;
F_136 ( V_18 ) ;
F_63 ( & V_12 ) ;
}
int F_138 ( struct V_17 * V_18 )
{
int error ;
F_59 ( & V_12 ) ;
error = F_131 ( & V_130 , V_18 ) ;
if ( ! error && ( V_129 == & V_130 ) )
V_129 = & V_18 -> V_59 ;
F_63 ( & V_12 ) ;
return error ;
}
void F_139 ( struct V_17 * V_18 )
{
F_59 ( & V_12 ) ;
if ( & V_18 -> V_59 == V_129 )
V_129 = V_129 -> V_131 ;
F_136 ( V_18 ) ;
F_63 ( & V_12 ) ;
}
static struct V_72 * F_140 ( struct V_76 * V_132 )
{
struct V_8 * V_8 = NULL ;
struct V_79 * V_79 ;
F_90 ( V_132 ) ;
V_79 = V_132 -> V_79 ;
if ( V_79 )
V_8 = F_34 ( V_79 -> V_80 ) ;
F_91 ( V_132 ) ;
return V_8 ? & V_8 -> V_50 : NULL ;
}
static inline struct V_8 * F_141 ( struct V_72 * V_50 )
{
return F_86 ( V_50 , struct V_8 , V_50 ) ;
}
static void F_142 ( struct V_72 * V_50 )
{
F_103 ( F_141 ( V_50 ) ) ;
}
static int F_143 ( struct V_79 * V_79 , struct V_72 * V_50 )
{
struct V_8 * V_8 = F_141 ( V_50 ) ;
if ( ! F_144 ( V_8 -> V_43 , V_133 ) ||
! F_144 ( F_145 () , V_133 ) )
return - V_134 ;
F_103 ( V_79 -> V_80 ) ;
V_79 -> V_80 = F_34 ( V_8 ) ;
return 0 ;
}
static struct V_42 * F_146 ( struct V_72 * V_50 )
{
return F_141 ( V_50 ) -> V_43 ;
}
