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
int V_29 = 0 , V_30 = 0 , V_9 ;
F_18 () ;
if ( V_28 >= 0 ) {
V_29 = V_28 ;
V_30 = V_28 + 1 ;
}
V_9 = F_19 ( & V_8 -> V_31 , V_27 , V_29 , V_30 , V_6 ) ;
if ( V_9 >= 0 )
F_20 ( V_8 , V_27 , V_32 , V_9 ) ;
return V_9 ;
}
static int F_21 ( int V_9 , void * V_8 , void * V_27 )
{
if ( F_22 ( V_8 , V_27 ) )
return V_9 ? : V_33 ;
return 0 ;
}
static int F_23 ( struct V_8 * V_8 , struct V_8 * V_27 , bool V_34 )
{
int V_9 = F_24 ( & V_8 -> V_31 , F_21 , V_27 ) ;
F_18 () ;
if ( V_9 == V_33 )
return 0 ;
if ( V_9 > 0 )
return V_9 ;
if ( V_34 )
return F_17 ( V_8 , V_27 , - 1 ) ;
return - V_35 ;
}
int F_25 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
bool V_34 = F_26 ( & V_27 -> V_36 ) == 0 ? false : true ;
int V_9 ;
V_9 = F_23 ( V_8 , V_27 , V_34 ) ;
return V_9 >= 0 ? V_9 : V_37 ;
}
struct V_8 * F_27 ( struct V_8 * V_8 , int V_9 )
{
struct V_8 * V_27 ;
if ( V_9 < 0 )
return NULL ;
F_28 () ;
V_27 = F_29 ( & V_8 -> V_31 , V_9 ) ;
if ( V_27 )
F_30 ( V_27 ) ;
F_31 () ;
return V_27 ;
}
static T_2 int F_32 ( struct V_8 * V_8 , struct V_38 * V_39 )
{
const struct V_17 * V_18 , * V_40 ;
int error = 0 ;
F_33 ( V_25 ) ;
F_34 ( & V_8 -> V_36 , 1 ) ;
F_34 ( & V_8 -> V_41 , 1 ) ;
V_8 -> V_42 = 1 ;
V_8 -> V_39 = V_39 ;
F_35 ( & V_8 -> V_31 ) ;
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_43;
}
V_21:
return error ;
V_43:
F_36 ( & V_8 -> V_44 , & V_25 ) ;
V_40 = V_18 ;
F_37 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
V_18 = V_40 ;
F_37 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_38 () ;
goto V_21;
}
static struct V_8 * F_39 ( void )
{
struct V_8 * V_8 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_21;
V_8 = F_40 ( V_45 , V_6 ) ;
if ( ! V_8 )
goto V_46;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_21:
return V_8 ;
V_46:
F_12 ( V_2 ) ;
goto V_21;
}
static void F_41 ( struct V_8 * V_8 )
{
F_12 ( F_42 ( V_8 -> V_13 ) ) ;
F_43 ( V_45 , V_8 ) ;
}
void F_44 ( void * V_47 )
{
struct V_8 * V_48 = V_47 ;
if ( V_48 && F_45 ( & V_48 -> V_41 ) )
F_41 ( V_48 ) ;
}
struct V_8 * F_46 ( unsigned long V_49 ,
struct V_38 * V_39 , struct V_8 * V_50 )
{
struct V_8 * V_8 ;
int V_51 ;
if ( ! ( V_49 & V_52 ) )
return F_30 ( V_50 ) ;
V_8 = F_39 () ;
if ( ! V_8 )
return F_47 ( - V_15 ) ;
F_48 ( V_39 ) ;
F_49 ( & V_12 ) ;
V_51 = F_32 ( V_8 , V_39 ) ;
if ( V_51 == 0 ) {
F_50 () ;
F_51 ( & V_8 -> V_53 , & V_54 ) ;
F_52 () ;
}
F_53 ( & V_12 ) ;
if ( V_51 < 0 ) {
F_54 ( V_39 ) ;
F_44 ( V_8 ) ;
return F_47 ( V_51 ) ;
}
return V_8 ;
}
static void F_55 ( struct V_55 * V_56 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_57 ;
struct V_24 V_58 ;
F_33 ( V_25 ) ;
F_56 ( & V_59 ) ;
F_57 ( & V_60 , & V_58 ) ;
F_58 ( & V_59 ) ;
F_49 ( & V_12 ) ;
F_50 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_59 ( & V_8 -> V_53 ) ;
F_60 ( & V_8 -> V_44 , & V_25 ) ;
F_61 (tmp) {
int V_9 = F_23 ( V_57 , V_8 , false ) ;
if ( V_9 >= 0 ) {
F_20 ( V_57 , V_8 , V_61 , V_9 ) ;
F_62 ( & V_57 -> V_31 , V_9 ) ;
}
}
F_63 ( & V_8 -> V_31 ) ;
}
F_52 () ;
F_64 () ;
F_65 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_65 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_53 ( & V_12 ) ;
F_38 () ;
F_66 (net, tmp, &net_exit_list, exit_list) {
F_67 ( & V_8 -> V_44 ) ;
F_54 ( V_8 -> V_39 ) ;
F_44 ( V_8 ) ;
}
}
void F_68 ( struct V_8 * V_8 )
{
unsigned long V_49 ;
F_69 ( & V_59 , V_49 ) ;
F_36 ( & V_8 -> V_60 , & V_60 ) ;
F_70 ( & V_59 , V_49 ) ;
F_71 ( V_62 , & V_63 ) ;
}
struct V_8 * F_72 ( int V_64 )
{
struct V_65 * V_65 ;
struct V_66 * V_48 ;
struct V_8 * V_8 ;
V_65 = F_73 ( V_64 ) ;
if ( F_74 ( V_65 ) )
return F_75 ( V_65 ) ;
V_48 = F_76 ( F_77 ( V_65 ) ) ;
if ( V_48 -> V_18 == & V_67 )
V_8 = F_30 ( F_78 ( V_48 , struct V_8 , V_48 ) ) ;
else
V_8 = F_47 ( - V_68 ) ;
F_79 ( V_65 ) ;
return V_8 ;
}
struct V_8 * F_72 ( int V_64 )
{
return F_47 ( - V_68 ) ;
}
struct V_8 * F_80 ( T_3 V_69 )
{
struct V_70 * V_71 ;
struct V_8 * V_8 ;
V_8 = F_47 ( - V_72 ) ;
F_28 () ;
V_71 = F_81 ( V_69 ) ;
if ( V_71 ) {
struct V_73 * V_73 ;
F_82 ( V_71 ) ;
V_73 = V_71 -> V_73 ;
if ( V_73 )
V_8 = F_30 ( V_73 -> V_74 ) ;
F_83 ( V_71 ) ;
}
F_31 () ;
return V_8 ;
}
static T_2 int F_84 ( struct V_8 * V_8 )
{
#ifdef F_85
V_8 -> V_48 . V_18 = & V_67 ;
#endif
return F_86 ( & V_8 -> V_48 ) ;
}
static T_4 void F_87 ( struct V_8 * V_8 )
{
F_88 ( & V_8 -> V_48 ) ;
}
static int F_89 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_8 * V_8 = F_90 ( V_76 -> V_79 ) ;
struct V_80 * V_81 [ V_82 + 1 ] ;
struct V_8 * V_27 ;
int V_83 , V_19 ;
V_19 = F_91 ( V_78 , sizeof( struct V_84 ) , V_81 , V_82 ,
V_85 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_81 [ V_86 ] )
return - V_68 ;
V_83 = F_92 ( V_81 [ V_86 ] ) ;
if ( V_81 [ V_87 ] )
V_27 = F_80 ( F_93 ( V_81 [ V_87 ] ) ) ;
else if ( V_81 [ V_88 ] )
V_27 = F_72 ( F_93 ( V_81 [ V_88 ] ) ) ;
else
return - V_68 ;
if ( F_74 ( V_27 ) )
return F_94 ( V_27 ) ;
if ( F_23 ( V_8 , V_27 , false ) >= 0 ) {
V_19 = - V_89 ;
goto V_21;
}
V_19 = F_17 ( V_8 , V_27 , V_83 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
V_21:
F_95 ( V_27 ) ;
return V_19 ;
}
static int F_96 ( void )
{
return F_97 ( sizeof( struct V_84 ) )
+ F_98 ( sizeof( V_90 ) )
;
}
static int F_99 ( struct V_75 * V_76 , T_5 V_91 , T_5 V_92 , int V_49 ,
int V_93 , struct V_8 * V_8 , struct V_8 * V_27 ,
int V_83 )
{
struct V_77 * V_78 ;
struct V_84 * V_94 ;
int V_9 ;
F_18 () ;
V_78 = F_100 ( V_76 , V_91 , V_92 , V_93 , sizeof( * V_94 ) , V_49 ) ;
if ( ! V_78 )
return - V_95 ;
V_94 = F_101 ( V_78 ) ;
V_94 -> V_96 = V_97 ;
if ( V_83 >= 0 ) {
V_9 = V_83 ;
} else {
V_9 = F_23 ( V_8 , V_27 , false ) ;
if ( V_9 < 0 )
V_9 = V_37 ;
}
if ( F_102 ( V_76 , V_86 , V_9 ) )
goto V_98;
F_103 ( V_76 , V_78 ) ;
return 0 ;
V_98:
F_104 ( V_76 , V_78 ) ;
return - V_95 ;
}
static int F_105 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_8 * V_8 = F_90 ( V_76 -> V_79 ) ;
struct V_80 * V_81 [ V_82 + 1 ] ;
struct V_75 * V_99 ;
struct V_8 * V_27 ;
int V_19 ;
V_19 = F_91 ( V_78 , sizeof( struct V_84 ) , V_81 , V_82 ,
V_85 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_81 [ V_87 ] )
V_27 = F_80 ( F_93 ( V_81 [ V_87 ] ) ) ;
else if ( V_81 [ V_88 ] )
V_27 = F_72 ( F_93 ( V_81 [ V_88 ] ) ) ;
else
return - V_68 ;
if ( F_74 ( V_27 ) )
return F_94 ( V_27 ) ;
V_99 = F_106 ( F_96 () , V_6 ) ;
if ( ! V_99 ) {
V_19 = - V_15 ;
goto V_21;
}
V_19 = F_99 ( V_99 , F_107 ( V_76 ) . V_91 , V_78 -> V_100 , 0 ,
V_32 , V_8 , V_27 , - 1 ) ;
if ( V_19 < 0 )
goto V_101;
V_19 = F_108 ( V_99 , V_8 , F_107 ( V_76 ) . V_91 ) ;
goto V_21;
V_101:
F_109 ( V_99 ) ;
V_21:
F_95 ( V_27 ) ;
return V_19 ;
}
static int F_110 ( int V_9 , void * V_27 , void * V_10 )
{
struct V_102 * V_103 = (struct V_102 * ) V_10 ;
int V_104 ;
if ( V_103 -> V_105 < V_103 -> V_106 )
goto V_107;
V_104 = F_99 ( V_103 -> V_76 , F_107 ( V_103 -> V_108 -> V_76 ) . V_91 ,
V_103 -> V_108 -> V_78 -> V_100 , V_109 ,
V_32 , V_103 -> V_8 , V_27 , V_9 ) ;
if ( V_104 < 0 )
return V_104 ;
V_107:
V_103 -> V_105 ++ ;
return 0 ;
}
static int F_111 ( struct V_75 * V_76 , struct V_110 * V_108 )
{
struct V_8 * V_8 = F_90 ( V_76 -> V_79 ) ;
struct V_102 V_103 = {
. V_8 = V_8 ,
. V_76 = V_76 ,
. V_108 = V_108 ,
. V_105 = 0 ,
. V_106 = V_108 -> args [ 0 ] ,
} ;
F_18 () ;
F_24 ( & V_8 -> V_31 , F_110 , & V_103 ) ;
V_108 -> args [ 0 ] = V_103 . V_105 ;
return V_76 -> V_7 ;
}
static void F_20 ( struct V_8 * V_8 , struct V_8 * V_27 , int V_93 ,
int V_9 )
{
struct V_75 * V_99 ;
int V_19 = - V_15 ;
V_99 = F_106 ( F_96 () , V_6 ) ;
if ( ! V_99 )
goto V_21;
V_19 = F_99 ( V_99 , 0 , 0 , 0 , V_93 , V_8 , V_27 , V_9 ) ;
if ( V_19 < 0 )
goto V_101;
F_112 ( V_99 , V_8 , 0 , V_111 , NULL , 0 ) ;
return;
V_101:
F_109 ( V_99 ) ;
V_21:
F_113 ( V_8 , V_111 , V_19 ) ;
}
static int T_6 F_114 ( void )
{
struct V_1 * V_2 ;
#ifdef F_85
V_45 = F_115 ( L_1 , sizeof( struct V_8 ) ,
V_112 ,
V_113 , NULL ) ;
V_62 = F_116 ( L_2 ) ;
if ( ! V_62 )
F_117 ( L_3 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_117 ( L_4 ) ;
F_9 ( V_114 . V_13 , V_2 ) ;
F_49 ( & V_12 ) ;
if ( F_32 ( & V_114 , & V_115 ) )
F_117 ( L_5 ) ;
F_50 () ;
F_51 ( & V_114 . V_53 , & V_54 ) ;
F_52 () ;
F_53 ( & V_12 ) ;
F_118 ( & V_116 ) ;
F_119 ( V_117 , V_32 , F_89 , NULL , NULL ) ;
F_119 ( V_117 , V_118 , F_105 , F_111 ,
NULL ) ;
return 0 ;
}
static int F_120 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_33 ( V_25 ) ;
F_60 ( & V_18 -> V_53 , V_53 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_61 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_43;
F_60 ( & V_8 -> V_44 , & V_25 ) ;
}
}
return 0 ;
V_43:
F_121 ( & V_18 -> V_53 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_122 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_33 ( V_25 ) ;
F_121 ( & V_18 -> V_53 ) ;
F_61 (net)
F_60 ( & V_8 -> V_44 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_120 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_114 ) ;
}
static void F_122 ( struct V_17 * V_18 )
{
F_33 ( V_25 ) ;
F_36 ( & V_114 . V_44 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_123 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_119:
error = F_124 ( & V_120 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_121 ) {
F_125 ( & V_120 , V_6 ) ;
goto V_119;
}
return error ;
}
V_5 = F_126 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_120 ( V_53 , V_18 ) ;
if ( error ) {
F_38 () ;
if ( V_18 -> V_9 )
F_127 ( & V_120 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_128 ( struct V_17 * V_18 )
{
F_122 ( V_18 ) ;
F_38 () ;
if ( V_18 -> V_9 )
F_127 ( & V_120 , * V_18 -> V_9 ) ;
}
int F_118 ( struct V_17 * V_18 )
{
int error ;
F_49 ( & V_12 ) ;
error = F_123 ( V_122 , V_18 ) ;
F_53 ( & V_12 ) ;
return error ;
}
void F_129 ( struct V_17 * V_18 )
{
F_49 ( & V_12 ) ;
F_128 ( V_18 ) ;
F_53 ( & V_12 ) ;
}
int F_130 ( struct V_17 * V_18 )
{
int error ;
F_49 ( & V_12 ) ;
error = F_123 ( & V_123 , V_18 ) ;
if ( ! error && ( V_122 == & V_123 ) )
V_122 = & V_18 -> V_53 ;
F_53 ( & V_12 ) ;
return error ;
}
void F_131 ( struct V_17 * V_18 )
{
F_49 ( & V_12 ) ;
if ( & V_18 -> V_53 == V_122 )
V_122 = V_122 -> V_124 ;
F_128 ( V_18 ) ;
F_53 ( & V_12 ) ;
}
static struct V_66 * F_132 ( struct V_70 * V_125 )
{
struct V_8 * V_8 = NULL ;
struct V_73 * V_73 ;
F_82 ( V_125 ) ;
V_73 = V_125 -> V_73 ;
if ( V_73 )
V_8 = F_30 ( V_73 -> V_74 ) ;
F_83 ( V_125 ) ;
return V_8 ? & V_8 -> V_48 : NULL ;
}
static inline struct V_8 * F_133 ( struct V_66 * V_48 )
{
return F_78 ( V_48 , struct V_8 , V_48 ) ;
}
static void F_134 ( struct V_66 * V_48 )
{
F_95 ( F_133 ( V_48 ) ) ;
}
static int F_135 ( struct V_73 * V_73 , struct V_66 * V_48 )
{
struct V_8 * V_8 = F_133 ( V_48 ) ;
if ( ! F_136 ( V_8 -> V_39 , V_126 ) ||
! F_136 ( F_137 () , V_126 ) )
return - V_127 ;
F_95 ( V_73 -> V_74 ) ;
V_73 -> V_74 = F_30 ( V_8 ) ;
return 0 ;
}
