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
F_25 ( & V_8 -> V_39 , V_38 ) ;
V_34 = F_26 ( & V_27 -> V_40 ) == 0 ? false : true ;
V_9 = F_21 ( V_8 , V_27 , & V_34 ) ;
F_27 ( & V_8 -> V_39 , V_38 ) ;
if ( V_34 && V_9 >= 0 )
F_28 ( V_8 , V_41 , V_9 ) ;
return V_9 ;
}
int F_29 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
unsigned long V_38 ;
int V_9 ;
F_25 ( & V_8 -> V_39 , V_38 ) ;
V_9 = F_23 ( V_8 , V_27 ) ;
F_27 ( & V_8 -> V_39 , V_38 ) ;
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
F_25 ( & V_8 -> V_39 , V_38 ) ;
V_27 = F_33 ( & V_8 -> V_31 , V_9 ) ;
if ( V_27 )
F_34 ( V_27 ) ;
F_27 ( & V_8 -> V_39 , V_38 ) ;
F_35 () ;
return V_27 ;
}
static T_2 int F_36 ( struct V_8 * V_8 , struct V_42 * V_43 )
{
const struct V_17 * V_18 , * V_44 ;
int error = 0 ;
F_37 ( V_25 ) ;
F_38 ( & V_8 -> V_40 , 1 ) ;
F_38 ( & V_8 -> V_45 , 1 ) ;
V_8 -> V_46 = 1 ;
V_8 -> V_43 = V_43 ;
F_39 ( & V_8 -> V_31 ) ;
F_40 ( & V_8 -> V_39 ) ;
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
static struct V_8 * F_44 ( void )
{
struct V_8 * V_8 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_21;
V_8 = F_45 ( V_49 , V_6 ) ;
if ( ! V_8 )
goto V_50;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_21:
return V_8 ;
V_50:
F_12 ( V_2 ) ;
goto V_21;
}
static void F_46 ( struct V_8 * V_8 )
{
F_12 ( F_47 ( V_8 -> V_13 ) ) ;
F_48 ( V_49 , V_8 ) ;
}
void F_49 ( void * V_51 )
{
struct V_8 * V_52 = V_51 ;
if ( V_52 && F_50 ( & V_52 -> V_45 ) )
F_46 ( V_52 ) ;
}
struct V_8 * F_51 ( unsigned long V_38 ,
struct V_42 * V_43 , struct V_8 * V_53 )
{
struct V_8 * V_8 ;
int V_54 ;
if ( ! ( V_38 & V_55 ) )
return F_34 ( V_53 ) ;
V_8 = F_44 () ;
if ( ! V_8 )
return F_52 ( - V_15 ) ;
F_53 ( V_43 ) ;
F_54 ( & V_12 ) ;
V_54 = F_36 ( V_8 , V_43 ) ;
if ( V_54 == 0 ) {
F_55 () ;
F_56 ( & V_8 -> V_56 , & V_57 ) ;
F_57 () ;
}
F_58 ( & V_12 ) ;
if ( V_54 < 0 ) {
F_59 ( V_43 ) ;
F_49 ( V_8 ) ;
return F_52 ( V_54 ) ;
}
return V_8 ;
}
static void F_60 ( struct V_58 * V_59 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_60 ;
struct V_24 V_61 ;
F_37 ( V_25 ) ;
F_61 ( & V_62 ) ;
F_62 ( & V_63 , & V_61 ) ;
F_63 ( & V_62 ) ;
F_54 ( & V_12 ) ;
F_55 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_64 ( & V_8 -> V_56 ) ;
F_65 ( & V_8 -> V_48 , & V_25 ) ;
F_66 (tmp) {
int V_9 ;
F_61 ( & V_60 -> V_39 ) ;
V_9 = F_23 ( V_60 , V_8 ) ;
if ( V_9 >= 0 )
F_67 ( & V_60 -> V_31 , V_9 ) ;
F_63 ( & V_60 -> V_39 ) ;
if ( V_9 >= 0 )
F_28 ( V_60 , V_64 , V_9 ) ;
}
F_61 ( & V_8 -> V_39 ) ;
F_68 ( & V_8 -> V_31 ) ;
F_63 ( & V_8 -> V_39 ) ;
}
F_57 () ;
F_69 () ;
F_70 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_70 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_58 ( & V_12 ) ;
F_43 () ;
F_71 (net, tmp, &net_exit_list, exit_list) {
F_72 ( & V_8 -> V_48 ) ;
F_59 ( V_8 -> V_43 ) ;
F_49 ( V_8 ) ;
}
}
void F_73 ( struct V_8 * V_8 )
{
unsigned long V_38 ;
F_25 ( & V_62 , V_38 ) ;
F_41 ( & V_8 -> V_63 , & V_63 ) ;
F_27 ( & V_62 , V_38 ) ;
F_74 ( V_65 , & V_66 ) ;
}
struct V_8 * F_75 ( int V_67 )
{
struct V_68 * V_68 ;
struct V_69 * V_52 ;
struct V_8 * V_8 ;
V_68 = F_76 ( V_67 ) ;
if ( F_77 ( V_68 ) )
return F_78 ( V_68 ) ;
V_52 = F_79 ( F_80 ( V_68 ) ) ;
if ( V_52 -> V_18 == & V_70 )
V_8 = F_34 ( F_81 ( V_52 , struct V_8 , V_52 ) ) ;
else
V_8 = F_52 ( - V_71 ) ;
F_82 ( V_68 ) ;
return V_8 ;
}
struct V_8 * F_75 ( int V_67 )
{
return F_52 ( - V_71 ) ;
}
struct V_8 * F_83 ( T_3 V_72 )
{
struct V_73 * V_74 ;
struct V_8 * V_8 ;
V_8 = F_52 ( - V_75 ) ;
F_32 () ;
V_74 = F_84 ( V_72 ) ;
if ( V_74 ) {
struct V_76 * V_76 ;
F_85 ( V_74 ) ;
V_76 = V_74 -> V_76 ;
if ( V_76 )
V_8 = F_34 ( V_76 -> V_77 ) ;
F_86 ( V_74 ) ;
}
F_35 () ;
return V_8 ;
}
static T_2 int F_87 ( struct V_8 * V_8 )
{
#ifdef F_88
V_8 -> V_52 . V_18 = & V_70 ;
#endif
return F_89 ( & V_8 -> V_52 ) ;
}
static T_4 void F_90 ( struct V_8 * V_8 )
{
F_91 ( & V_8 -> V_52 ) ;
}
static int F_92 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
struct V_8 * V_8 = F_93 ( V_79 -> V_82 ) ;
struct V_83 * V_84 [ V_85 + 1 ] ;
unsigned long V_38 ;
struct V_8 * V_27 ;
int V_86 , V_19 ;
V_19 = F_94 ( V_81 , sizeof( struct V_87 ) , V_84 , V_85 ,
V_88 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_84 [ V_89 ] )
return - V_71 ;
V_86 = F_95 ( V_84 [ V_89 ] ) ;
if ( V_84 [ V_90 ] )
V_27 = F_83 ( F_96 ( V_84 [ V_90 ] ) ) ;
else if ( V_84 [ V_91 ] )
V_27 = F_75 ( F_96 ( V_84 [ V_91 ] ) ) ;
else
return - V_71 ;
if ( F_77 ( V_27 ) )
return F_97 ( V_27 ) ;
F_25 ( & V_8 -> V_39 , V_38 ) ;
if ( F_23 ( V_8 , V_27 ) >= 0 ) {
F_27 ( & V_8 -> V_39 , V_38 ) ;
V_19 = - V_92 ;
goto V_21;
}
V_19 = F_17 ( V_8 , V_27 , V_86 ) ;
F_27 ( & V_8 -> V_39 , V_38 ) ;
if ( V_19 >= 0 ) {
F_28 ( V_8 , V_41 , V_19 ) ;
V_19 = 0 ;
}
V_21:
F_98 ( V_27 ) ;
return V_19 ;
}
static int F_99 ( void )
{
return F_100 ( sizeof( struct V_87 ) )
+ F_101 ( sizeof( V_93 ) )
;
}
static int F_102 ( struct V_78 * V_79 , T_5 V_94 , T_5 V_95 , int V_38 ,
int V_96 , struct V_8 * V_8 , int V_86 )
{
struct V_80 * V_81 ;
struct V_87 * V_97 ;
V_81 = F_103 ( V_79 , V_94 , V_95 , V_96 , sizeof( * V_97 ) , V_38 ) ;
if ( ! V_81 )
return - V_98 ;
V_97 = F_104 ( V_81 ) ;
V_97 -> V_99 = V_100 ;
if ( F_105 ( V_79 , V_89 , V_86 ) )
goto V_101;
F_106 ( V_79 , V_81 ) ;
return 0 ;
V_101:
F_107 ( V_79 , V_81 ) ;
return - V_98 ;
}
static int F_108 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
struct V_8 * V_8 = F_93 ( V_79 -> V_82 ) ;
struct V_83 * V_84 [ V_85 + 1 ] ;
struct V_78 * V_102 ;
struct V_8 * V_27 ;
int V_19 , V_9 ;
V_19 = F_94 ( V_81 , sizeof( struct V_87 ) , V_84 , V_85 ,
V_88 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_84 [ V_90 ] )
V_27 = F_83 ( F_96 ( V_84 [ V_90 ] ) ) ;
else if ( V_84 [ V_91 ] )
V_27 = F_75 ( F_96 ( V_84 [ V_91 ] ) ) ;
else
return - V_71 ;
if ( F_77 ( V_27 ) )
return F_97 ( V_27 ) ;
V_102 = F_109 ( F_99 () , V_6 ) ;
if ( ! V_102 ) {
V_19 = - V_15 ;
goto V_21;
}
V_9 = F_29 ( V_8 , V_27 ) ;
V_19 = F_102 ( V_102 , F_110 ( V_79 ) . V_94 , V_81 -> V_103 , 0 ,
V_41 , V_8 , V_9 ) ;
if ( V_19 < 0 )
goto V_104;
V_19 = F_111 ( V_102 , V_8 , F_110 ( V_79 ) . V_94 ) ;
goto V_21;
V_104:
F_112 ( V_102 ) ;
V_21:
F_98 ( V_27 ) ;
return V_19 ;
}
static int F_113 ( int V_9 , void * V_27 , void * V_10 )
{
struct V_105 * V_106 = (struct V_105 * ) V_10 ;
int V_107 ;
if ( V_106 -> V_108 < V_106 -> V_109 )
goto V_110;
V_107 = F_102 ( V_106 -> V_79 , F_110 ( V_106 -> V_111 -> V_79 ) . V_94 ,
V_106 -> V_111 -> V_81 -> V_103 , V_112 ,
V_41 , V_106 -> V_8 , V_9 ) ;
if ( V_107 < 0 )
return V_107 ;
V_110:
V_106 -> V_108 ++ ;
return 0 ;
}
static int F_114 ( struct V_78 * V_79 , struct V_113 * V_111 )
{
struct V_8 * V_8 = F_93 ( V_79 -> V_82 ) ;
struct V_105 V_106 = {
. V_8 = V_8 ,
. V_79 = V_79 ,
. V_111 = V_111 ,
. V_108 = 0 ,
. V_109 = V_111 -> args [ 0 ] ,
} ;
unsigned long V_38 ;
F_25 ( & V_8 -> V_39 , V_38 ) ;
F_22 ( & V_8 -> V_31 , F_113 , & V_106 ) ;
F_27 ( & V_8 -> V_39 , V_38 ) ;
V_111 -> args [ 0 ] = V_106 . V_108 ;
return V_79 -> V_7 ;
}
static void F_28 ( struct V_8 * V_8 , int V_96 , int V_9 )
{
struct V_78 * V_102 ;
int V_19 = - V_15 ;
V_102 = F_109 ( F_99 () , V_6 ) ;
if ( ! V_102 )
goto V_21;
V_19 = F_102 ( V_102 , 0 , 0 , 0 , V_96 , V_8 , V_9 ) ;
if ( V_19 < 0 )
goto V_104;
F_115 ( V_102 , V_8 , 0 , V_114 , NULL , 0 ) ;
return;
V_104:
F_112 ( V_102 ) ;
V_21:
F_116 ( V_8 , V_114 , V_19 ) ;
}
static int T_6 F_117 ( void )
{
struct V_1 * V_2 ;
#ifdef F_88
V_49 = F_118 ( L_1 , sizeof( struct V_8 ) ,
V_115 ,
V_116 , NULL ) ;
V_65 = F_119 ( L_2 ) ;
if ( ! V_65 )
F_120 ( L_3 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_120 ( L_4 ) ;
F_9 ( V_117 . V_13 , V_2 ) ;
F_54 ( & V_12 ) ;
if ( F_36 ( & V_117 , & V_118 ) )
F_120 ( L_5 ) ;
F_55 () ;
F_56 ( & V_117 . V_56 , & V_57 ) ;
F_57 () ;
F_58 ( & V_12 ) ;
F_121 ( & V_119 ) ;
F_122 ( V_120 , V_41 , F_92 , NULL , NULL ) ;
F_122 ( V_120 , V_121 , F_108 , F_114 ,
NULL ) ;
return 0 ;
}
static int F_123 ( struct V_24 * V_56 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_37 ( V_25 ) ;
F_65 ( & V_18 -> V_56 , V_56 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_66 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_47;
F_65 ( & V_8 -> V_48 , & V_25 ) ;
}
}
return 0 ;
V_47:
F_124 ( & V_18 -> V_56 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_125 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_37 ( V_25 ) ;
F_124 ( & V_18 -> V_56 ) ;
F_66 (net)
F_65 ( & V_8 -> V_48 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_123 ( struct V_24 * V_56 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_117 ) ;
}
static void F_125 ( struct V_17 * V_18 )
{
F_37 ( V_25 ) ;
F_41 ( & V_117 . V_48 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_126 ( struct V_24 * V_56 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_122:
error = F_127 ( & V_123 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_124 ) {
F_128 ( & V_123 , V_6 ) ;
goto V_122;
}
return error ;
}
V_5 = F_129 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_123 ( V_56 , V_18 ) ;
if ( error ) {
F_43 () ;
if ( V_18 -> V_9 )
F_130 ( & V_123 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_131 ( struct V_17 * V_18 )
{
F_125 ( V_18 ) ;
F_43 () ;
if ( V_18 -> V_9 )
F_130 ( & V_123 , * V_18 -> V_9 ) ;
}
int F_121 ( struct V_17 * V_18 )
{
int error ;
F_54 ( & V_12 ) ;
error = F_126 ( V_125 , V_18 ) ;
F_58 ( & V_12 ) ;
return error ;
}
void F_132 ( struct V_17 * V_18 )
{
F_54 ( & V_12 ) ;
F_131 ( V_18 ) ;
F_58 ( & V_12 ) ;
}
int F_133 ( struct V_17 * V_18 )
{
int error ;
F_54 ( & V_12 ) ;
error = F_126 ( & V_126 , V_18 ) ;
if ( ! error && ( V_125 == & V_126 ) )
V_125 = & V_18 -> V_56 ;
F_58 ( & V_12 ) ;
return error ;
}
void F_134 ( struct V_17 * V_18 )
{
F_54 ( & V_12 ) ;
if ( & V_18 -> V_56 == V_125 )
V_125 = V_125 -> V_127 ;
F_131 ( V_18 ) ;
F_58 ( & V_12 ) ;
}
static struct V_69 * F_135 ( struct V_73 * V_128 )
{
struct V_8 * V_8 = NULL ;
struct V_76 * V_76 ;
F_85 ( V_128 ) ;
V_76 = V_128 -> V_76 ;
if ( V_76 )
V_8 = F_34 ( V_76 -> V_77 ) ;
F_86 ( V_128 ) ;
return V_8 ? & V_8 -> V_52 : NULL ;
}
static inline struct V_8 * F_136 ( struct V_69 * V_52 )
{
return F_81 ( V_52 , struct V_8 , V_52 ) ;
}
static void F_137 ( struct V_69 * V_52 )
{
F_98 ( F_136 ( V_52 ) ) ;
}
static int F_138 ( struct V_76 * V_76 , struct V_69 * V_52 )
{
struct V_8 * V_8 = F_136 ( V_52 ) ;
if ( ! F_139 ( V_8 -> V_43 , V_129 ) ||
! F_139 ( F_140 () , V_129 ) )
return - V_130 ;
F_98 ( V_76 -> V_77 ) ;
V_76 -> V_77 = F_34 ( V_8 ) ;
return 0 ;
}
