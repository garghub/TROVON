static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
unsigned int V_3 = F_2 ( struct V_1 , V_4 [ V_5 ] ) ;
V_2 = F_3 ( V_3 , V_6 ) ;
if ( V_2 )
V_2 -> V_7 . V_8 = V_5 ;
return V_2 ;
}
static int F_4 ( struct V_9 * V_9 , unsigned int V_10 , void * V_11 )
{
struct V_1 * V_2 , * V_12 ;
F_5 ( ! F_6 ( & V_13 ) ) ;
F_5 ( V_10 < V_14 ) ;
V_12 = F_7 ( V_9 -> V_15 ,
F_8 ( & V_13 ) ) ;
if ( V_12 -> V_7 . V_8 > V_10 ) {
V_12 -> V_4 [ V_10 ] = V_11 ;
return 0 ;
}
V_2 = F_1 () ;
if ( V_2 == NULL )
return - V_16 ;
memcpy ( & V_2 -> V_4 [ V_14 ] , & V_12 -> V_4 [ V_14 ] ,
( V_12 -> V_7 . V_8 - V_14 ) * sizeof( void * ) ) ;
V_2 -> V_4 [ V_10 ] = V_11 ;
F_9 ( V_9 -> V_15 , V_2 ) ;
F_10 ( V_12 , V_7 . V_17 ) ;
return 0 ;
}
static int F_11 ( const struct V_18 * V_19 , struct V_9 * V_9 )
{
int V_20 = - V_16 ;
void * V_11 = NULL ;
if ( V_19 -> V_10 && V_19 -> V_21 ) {
V_11 = F_3 ( V_19 -> V_21 , V_6 ) ;
if ( ! V_11 )
goto V_22;
V_20 = F_4 ( V_9 , * V_19 -> V_10 , V_11 ) ;
if ( V_20 )
goto V_23;
}
V_20 = 0 ;
if ( V_19 -> V_24 )
V_20 = V_19 -> V_24 ( V_9 ) ;
if ( ! V_20 )
return 0 ;
V_23:
F_12 ( V_11 ) ;
V_22:
return V_20 ;
}
static void F_13 ( const struct V_18 * V_19 , struct V_9 * V_9 )
{
if ( V_19 -> V_10 && V_19 -> V_21 ) {
F_12 ( V_1 ( V_9 , * V_19 -> V_10 ) ) ;
}
}
static void F_14 ( const struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_9 * V_9 ;
if ( V_19 -> exit ) {
F_15 (net, net_exit_list, exit_list)
V_19 -> exit ( V_9 ) ;
}
if ( V_19 -> V_27 )
V_19 -> V_27 ( V_26 ) ;
}
static void F_16 ( const struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_9 * V_9 ;
if ( V_19 -> V_21 && V_19 -> V_10 ) {
F_15 (net, net_exit_list, exit_list)
F_13 ( V_19 , V_9 ) ;
}
}
static int F_17 ( struct V_9 * V_9 , struct V_9 * V_28 , int V_29 )
{
int V_30 = 0 , V_31 = 0 ;
if ( V_29 >= 0 ) {
V_30 = V_29 ;
V_31 = V_29 + 1 ;
}
return F_18 ( & V_9 -> V_32 , V_28 , V_30 , V_31 , V_33 ) ;
}
static int F_19 ( int V_10 , void * V_9 , void * V_28 )
{
if ( F_20 ( V_9 , V_28 ) )
return V_10 ? : V_34 ;
return 0 ;
}
static int F_21 ( struct V_9 * V_9 , struct V_9 * V_28 , bool * V_35 )
{
int V_10 = F_22 ( & V_9 -> V_32 , F_19 , V_28 ) ;
bool V_36 = * V_35 ;
* V_35 = false ;
if ( V_10 == V_34 )
return 0 ;
if ( V_10 > 0 )
return V_10 ;
if ( V_36 ) {
V_10 = F_17 ( V_9 , V_28 , - 1 ) ;
* V_35 = true ;
return V_10 >= 0 ? V_10 : V_37 ;
}
return V_37 ;
}
static int F_23 ( struct V_9 * V_9 , struct V_9 * V_28 )
{
bool V_38 = false ;
return F_21 ( V_9 , V_28 , & V_38 ) ;
}
int F_24 ( struct V_9 * V_9 , struct V_9 * V_28 )
{
bool V_35 ;
int V_10 ;
if ( F_25 ( & V_9 -> V_39 ) == 0 )
return V_37 ;
F_26 ( & V_9 -> V_40 ) ;
V_35 = F_25 ( & V_28 -> V_39 ) == 0 ? false : true ;
V_10 = F_21 ( V_9 , V_28 , & V_35 ) ;
F_27 ( & V_9 -> V_40 ) ;
if ( V_35 && V_10 >= 0 )
F_28 ( V_9 , V_41 , V_10 ) ;
return V_10 ;
}
int F_29 ( struct V_9 * V_9 , struct V_9 * V_28 )
{
int V_10 ;
F_26 ( & V_9 -> V_40 ) ;
V_10 = F_23 ( V_9 , V_28 ) ;
F_27 ( & V_9 -> V_40 ) ;
return V_10 ;
}
bool F_30 ( struct V_9 * V_9 , struct V_9 * V_28 )
{
return F_29 ( V_9 , V_28 ) >= 0 ;
}
struct V_9 * F_31 ( struct V_9 * V_9 , int V_10 )
{
struct V_9 * V_28 ;
if ( V_10 < 0 )
return NULL ;
F_32 () ;
F_26 ( & V_9 -> V_40 ) ;
V_28 = F_33 ( & V_9 -> V_32 , V_10 ) ;
if ( V_28 )
F_34 ( V_28 ) ;
F_27 ( & V_9 -> V_40 ) ;
F_35 () ;
return V_28 ;
}
static T_1 int F_36 ( struct V_9 * V_9 , struct V_42 * V_43 )
{
const struct V_18 * V_19 , * V_44 ;
int error = 0 ;
F_37 ( V_26 ) ;
F_38 ( & V_9 -> V_39 , 1 ) ;
F_38 ( & V_9 -> V_45 , 1 ) ;
V_9 -> V_46 = 1 ;
V_9 -> V_43 = V_43 ;
F_39 ( & V_9 -> V_32 ) ;
F_40 ( & V_9 -> V_40 ) ;
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_19 , V_9 ) ;
if ( error < 0 )
goto V_47;
}
V_22:
return error ;
V_47:
F_41 ( & V_9 -> V_48 , & V_26 ) ;
V_44 = V_19 ;
F_42 (ops, &pernet_list, list)
F_14 ( V_19 , & V_26 ) ;
V_19 = V_44 ;
F_42 (ops, &pernet_list, list)
F_16 ( V_19 , & V_26 ) ;
F_43 () ;
goto V_22;
}
static int T_1 F_44 ( struct V_9 * V_9 )
{
V_9 -> V_49 . V_50 = V_51 ;
return 0 ;
}
static T_2 int F_45 ( void )
{
if ( F_46 ( & V_52 ) )
F_47 ( L_1 ) ;
return 0 ;
}
static struct V_53 * F_48 ( struct V_42 * V_54 )
{
return F_49 ( V_54 , F_50 () , V_55 ) ;
}
static void F_51 ( struct V_53 * V_53 )
{
F_52 ( V_53 , V_55 ) ;
}
static struct V_9 * F_53 ( void )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_22;
V_9 = F_54 ( V_56 , V_6 ) ;
if ( ! V_9 )
goto V_57;
F_9 ( V_9 -> V_15 , V_2 ) ;
V_22:
return V_9 ;
V_57:
F_12 ( V_2 ) ;
goto V_22;
}
static void F_55 ( struct V_9 * V_9 )
{
F_12 ( F_56 ( V_9 -> V_15 ) ) ;
F_57 ( V_56 , V_9 ) ;
}
void F_58 ( void * V_58 )
{
struct V_9 * V_54 = V_58 ;
if ( V_54 && F_59 ( & V_54 -> V_45 ) )
F_55 ( V_54 ) ;
}
struct V_9 * F_60 ( unsigned long V_59 ,
struct V_42 * V_43 , struct V_9 * V_60 )
{
struct V_53 * V_53 ;
struct V_9 * V_9 ;
int V_61 ;
if ( ! ( V_59 & V_62 ) )
return F_34 ( V_60 ) ;
V_53 = F_48 ( V_43 ) ;
if ( ! V_53 )
return F_61 ( - V_63 ) ;
V_9 = F_53 () ;
if ( ! V_9 ) {
F_51 ( V_53 ) ;
return F_61 ( - V_16 ) ;
}
F_62 ( V_43 ) ;
V_61 = F_63 ( & V_13 ) ;
if ( V_61 < 0 ) {
F_55 ( V_9 ) ;
F_51 ( V_53 ) ;
F_64 ( V_43 ) ;
return F_61 ( V_61 ) ;
}
V_9 -> V_53 = V_53 ;
V_61 = F_36 ( V_9 , V_43 ) ;
if ( V_61 == 0 ) {
F_65 () ;
F_66 ( & V_9 -> V_64 , & V_65 ) ;
F_67 () ;
}
F_68 ( & V_13 ) ;
if ( V_61 < 0 ) {
F_51 ( V_53 ) ;
F_64 ( V_43 ) ;
F_58 ( V_9 ) ;
return F_61 ( V_61 ) ;
}
return V_9 ;
}
static void F_69 ( struct V_66 * V_67 )
{
const struct V_18 * V_19 ;
struct V_9 * V_9 , * V_68 ;
struct V_25 V_69 ;
F_37 ( V_26 ) ;
F_70 ( & V_70 ) ;
F_71 ( & V_71 , & V_69 ) ;
F_72 ( & V_70 ) ;
F_73 ( & V_13 ) ;
F_65 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_74 ( & V_9 -> V_64 ) ;
F_75 ( & V_9 -> V_48 , & V_26 ) ;
F_76 (tmp) {
int V_10 ;
F_26 ( & V_68 -> V_40 ) ;
V_10 = F_23 ( V_68 , V_9 ) ;
if ( V_10 >= 0 )
F_77 ( & V_68 -> V_32 , V_10 ) ;
F_27 ( & V_68 -> V_40 ) ;
if ( V_10 >= 0 )
F_28 ( V_68 , V_72 , V_10 ) ;
}
F_26 ( & V_9 -> V_40 ) ;
F_78 ( & V_9 -> V_32 ) ;
F_27 ( & V_9 -> V_40 ) ;
}
F_67 () ;
F_79 () ;
F_80 (ops, &pernet_list, list)
F_14 ( V_19 , & V_26 ) ;
F_80 (ops, &pernet_list, list)
F_16 ( V_19 , & V_26 ) ;
F_68 ( & V_13 ) ;
F_43 () ;
F_81 (net, tmp, &net_exit_list, exit_list) {
F_82 ( & V_9 -> V_48 ) ;
F_51 ( V_9 -> V_53 ) ;
F_64 ( V_9 -> V_43 ) ;
F_58 ( V_9 ) ;
}
}
void F_83 ( struct V_9 * V_9 )
{
unsigned long V_59 ;
F_84 ( & V_70 , V_59 ) ;
F_41 ( & V_9 -> V_71 , & V_71 ) ;
F_85 ( & V_70 , V_59 ) ;
F_86 ( V_73 , & V_74 ) ;
}
struct V_9 * F_87 ( int V_75 )
{
struct V_76 * V_76 ;
struct V_77 * V_54 ;
struct V_9 * V_9 ;
V_76 = F_88 ( V_75 ) ;
if ( F_89 ( V_76 ) )
return F_90 ( V_76 ) ;
V_54 = F_91 ( F_92 ( V_76 ) ) ;
if ( V_54 -> V_19 == & V_78 )
V_9 = F_34 ( F_93 ( V_54 , struct V_9 , V_54 ) ) ;
else
V_9 = F_61 ( - V_79 ) ;
F_94 ( V_76 ) ;
return V_9 ;
}
struct V_9 * F_87 ( int V_75 )
{
return F_61 ( - V_79 ) ;
}
struct V_9 * F_95 ( T_3 V_80 )
{
struct V_81 * V_82 ;
struct V_9 * V_9 ;
V_9 = F_61 ( - V_83 ) ;
F_32 () ;
V_82 = F_96 ( V_80 ) ;
if ( V_82 ) {
struct V_84 * V_84 ;
F_97 ( V_82 ) ;
V_84 = V_82 -> V_84 ;
if ( V_84 )
V_9 = F_34 ( V_84 -> V_85 ) ;
F_98 ( V_82 ) ;
}
F_35 () ;
return V_9 ;
}
static T_1 int F_99 ( struct V_9 * V_9 )
{
#ifdef F_100
V_9 -> V_54 . V_19 = & V_78 ;
#endif
return F_101 ( & V_9 -> V_54 ) ;
}
static T_4 void F_102 ( struct V_9 * V_9 )
{
F_103 ( & V_9 -> V_54 ) ;
}
static int F_104 ( struct V_86 * V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_9 * V_9 = F_105 ( V_87 -> V_92 ) ;
struct V_93 * V_94 [ V_95 + 1 ] ;
struct V_9 * V_28 ;
int V_96 , V_20 ;
V_20 = F_106 ( V_89 , sizeof( struct V_97 ) , V_94 , V_95 ,
V_98 , V_91 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_94 [ V_99 ] )
return - V_79 ;
V_96 = F_107 ( V_94 [ V_99 ] ) ;
if ( V_94 [ V_100 ] )
V_28 = F_95 ( F_108 ( V_94 [ V_100 ] ) ) ;
else if ( V_94 [ V_101 ] )
V_28 = F_87 ( F_108 ( V_94 [ V_101 ] ) ) ;
else
return - V_79 ;
if ( F_89 ( V_28 ) )
return F_109 ( V_28 ) ;
F_26 ( & V_9 -> V_40 ) ;
if ( F_23 ( V_9 , V_28 ) >= 0 ) {
F_27 ( & V_9 -> V_40 ) ;
V_20 = - V_102 ;
goto V_22;
}
V_20 = F_17 ( V_9 , V_28 , V_96 ) ;
F_27 ( & V_9 -> V_40 ) ;
if ( V_20 >= 0 ) {
F_28 ( V_9 , V_41 , V_20 ) ;
V_20 = 0 ;
}
V_22:
F_110 ( V_28 ) ;
return V_20 ;
}
static int F_111 ( void )
{
return F_112 ( sizeof( struct V_97 ) )
+ F_113 ( sizeof( V_103 ) )
;
}
static int F_114 ( struct V_86 * V_87 , T_5 V_104 , T_5 V_105 , int V_59 ,
int V_106 , struct V_9 * V_9 , int V_96 )
{
struct V_88 * V_89 ;
struct V_97 * V_107 ;
V_89 = F_115 ( V_87 , V_104 , V_105 , V_106 , sizeof( * V_107 ) , V_59 ) ;
if ( ! V_89 )
return - V_108 ;
V_107 = F_116 ( V_89 ) ;
V_107 -> V_109 = V_110 ;
if ( F_117 ( V_87 , V_99 , V_96 ) )
goto V_111;
F_118 ( V_87 , V_89 ) ;
return 0 ;
V_111:
F_119 ( V_87 , V_89 ) ;
return - V_108 ;
}
static int F_120 ( struct V_86 * V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_9 * V_9 = F_105 ( V_87 -> V_92 ) ;
struct V_93 * V_94 [ V_95 + 1 ] ;
struct V_86 * V_112 ;
struct V_9 * V_28 ;
int V_20 , V_10 ;
V_20 = F_106 ( V_89 , sizeof( struct V_97 ) , V_94 , V_95 ,
V_98 , V_91 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_94 [ V_100 ] )
V_28 = F_95 ( F_108 ( V_94 [ V_100 ] ) ) ;
else if ( V_94 [ V_101 ] )
V_28 = F_87 ( F_108 ( V_94 [ V_101 ] ) ) ;
else
return - V_79 ;
if ( F_89 ( V_28 ) )
return F_109 ( V_28 ) ;
V_112 = F_121 ( F_111 () , V_6 ) ;
if ( ! V_112 ) {
V_20 = - V_16 ;
goto V_22;
}
V_10 = F_29 ( V_9 , V_28 ) ;
V_20 = F_114 ( V_112 , F_122 ( V_87 ) . V_104 , V_89 -> V_113 , 0 ,
V_41 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_114;
V_20 = F_123 ( V_112 , V_9 , F_122 ( V_87 ) . V_104 ) ;
goto V_22;
V_114:
F_124 ( V_112 ) ;
V_22:
F_110 ( V_28 ) ;
return V_20 ;
}
static int F_125 ( int V_10 , void * V_28 , void * V_11 )
{
struct V_115 * V_116 = (struct V_115 * ) V_11 ;
int V_117 ;
if ( V_116 -> V_118 < V_116 -> V_119 )
goto V_120;
V_117 = F_114 ( V_116 -> V_87 , F_122 ( V_116 -> V_121 -> V_87 ) . V_104 ,
V_116 -> V_121 -> V_89 -> V_113 , V_122 ,
V_41 , V_116 -> V_9 , V_10 ) ;
if ( V_117 < 0 )
return V_117 ;
V_120:
V_116 -> V_118 ++ ;
return 0 ;
}
static int F_126 ( struct V_86 * V_87 , struct V_123 * V_121 )
{
struct V_9 * V_9 = F_105 ( V_87 -> V_92 ) ;
struct V_115 V_116 = {
. V_9 = V_9 ,
. V_87 = V_87 ,
. V_121 = V_121 ,
. V_118 = 0 ,
. V_119 = V_121 -> args [ 0 ] ,
} ;
F_26 ( & V_9 -> V_40 ) ;
F_22 ( & V_9 -> V_32 , F_125 , & V_116 ) ;
F_27 ( & V_9 -> V_40 ) ;
V_121 -> args [ 0 ] = V_116 . V_118 ;
return V_87 -> V_8 ;
}
static void F_28 ( struct V_9 * V_9 , int V_106 , int V_10 )
{
struct V_86 * V_112 ;
int V_20 = - V_16 ;
V_112 = F_121 ( F_111 () , V_6 ) ;
if ( ! V_112 )
goto V_22;
V_20 = F_114 ( V_112 , 0 , 0 , 0 , V_106 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_114;
F_127 ( V_112 , V_9 , 0 , V_124 , NULL , 0 ) ;
return;
V_114:
F_124 ( V_112 ) ;
V_22:
F_128 ( V_9 , V_124 , V_20 ) ;
}
static int T_2 F_129 ( void )
{
struct V_1 * V_2 ;
#ifdef F_100
V_56 = F_130 ( L_2 , sizeof( struct V_9 ) ,
V_125 ,
V_126 , NULL ) ;
V_73 = F_131 ( L_3 ) ;
if ( ! V_73 )
F_47 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_47 ( L_5 ) ;
F_9 ( V_127 . V_15 , V_2 ) ;
F_73 ( & V_13 ) ;
if ( F_36 ( & V_127 , & V_128 ) )
F_47 ( L_6 ) ;
V_129 = true ;
F_65 () ;
F_66 ( & V_127 . V_64 , & V_65 ) ;
F_67 () ;
F_68 ( & V_13 ) ;
F_46 ( & V_130 ) ;
F_132 ( V_131 , V_41 , F_104 , NULL , NULL ) ;
F_132 ( V_131 , V_132 , F_120 , F_126 ,
NULL ) ;
return 0 ;
}
static int F_133 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
struct V_9 * V_9 ;
int error ;
F_37 ( V_26 ) ;
F_75 ( & V_19 -> V_64 , V_64 ) ;
if ( V_19 -> V_24 || ( V_19 -> V_10 && V_19 -> V_21 ) ) {
F_76 (net) {
error = F_11 ( V_19 , V_9 ) ;
if ( error )
goto V_47;
F_75 ( & V_9 -> V_48 , & V_26 ) ;
}
}
return 0 ;
V_47:
F_134 ( & V_19 -> V_64 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
return error ;
}
static void F_135 ( struct V_18 * V_19 )
{
struct V_9 * V_9 ;
F_37 ( V_26 ) ;
F_134 ( & V_19 -> V_64 ) ;
F_76 (net)
F_75 ( & V_9 -> V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
static int F_133 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
if ( ! V_129 ) {
F_75 ( & V_19 -> V_64 , V_64 ) ;
return 0 ;
}
return F_11 ( V_19 , & V_127 ) ;
}
static void F_135 ( struct V_18 * V_19 )
{
if ( ! V_129 ) {
F_134 ( & V_19 -> V_64 ) ;
} else {
F_37 ( V_26 ) ;
F_41 ( & V_127 . V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
}
static int F_136 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
int error ;
if ( V_19 -> V_10 ) {
V_133:
error = F_137 ( & V_134 , V_14 , V_19 -> V_10 ) ;
if ( error < 0 ) {
if ( error == - V_135 ) {
F_138 ( & V_134 , V_6 ) ;
goto V_133;
}
return error ;
}
V_5 = V_31 ( V_5 , * V_19 -> V_10 + 1 ) ;
}
error = F_133 ( V_64 , V_19 ) ;
if ( error ) {
F_43 () ;
if ( V_19 -> V_10 )
F_139 ( & V_134 , * V_19 -> V_10 ) ;
}
return error ;
}
static void F_140 ( struct V_18 * V_19 )
{
F_135 ( V_19 ) ;
F_43 () ;
if ( V_19 -> V_10 )
F_139 ( & V_134 , * V_19 -> V_10 ) ;
}
int F_46 ( struct V_18 * V_19 )
{
int error ;
F_73 ( & V_13 ) ;
error = F_136 ( V_136 , V_19 ) ;
F_68 ( & V_13 ) ;
return error ;
}
void F_141 ( struct V_18 * V_19 )
{
F_73 ( & V_13 ) ;
F_140 ( V_19 ) ;
F_68 ( & V_13 ) ;
}
int F_142 ( struct V_18 * V_19 )
{
int error ;
F_73 ( & V_13 ) ;
error = F_136 ( & V_137 , V_19 ) ;
if ( ! error && ( V_136 == & V_137 ) )
V_136 = & V_19 -> V_64 ;
F_68 ( & V_13 ) ;
return error ;
}
void F_143 ( struct V_18 * V_19 )
{
F_73 ( & V_13 ) ;
if ( & V_19 -> V_64 == V_136 )
V_136 = V_136 -> V_138 ;
F_140 ( V_19 ) ;
F_68 ( & V_13 ) ;
}
static struct V_77 * F_144 ( struct V_81 * V_139 )
{
struct V_9 * V_9 = NULL ;
struct V_84 * V_84 ;
F_97 ( V_139 ) ;
V_84 = V_139 -> V_84 ;
if ( V_84 )
V_9 = F_34 ( V_84 -> V_85 ) ;
F_98 ( V_139 ) ;
return V_9 ? & V_9 -> V_54 : NULL ;
}
static inline struct V_9 * F_145 ( struct V_77 * V_54 )
{
return F_93 ( V_54 , struct V_9 , V_54 ) ;
}
static void F_146 ( struct V_77 * V_54 )
{
F_110 ( F_145 ( V_54 ) ) ;
}
static int F_147 ( struct V_84 * V_84 , struct V_77 * V_54 )
{
struct V_9 * V_9 = F_145 ( V_54 ) ;
if ( ! F_148 ( V_9 -> V_43 , V_140 ) ||
! F_148 ( F_149 () , V_140 ) )
return - V_141 ;
F_110 ( V_84 -> V_85 ) ;
V_84 -> V_85 = F_34 ( V_9 ) ;
return 0 ;
}
static struct V_42 * F_150 ( struct V_77 * V_54 )
{
return F_145 ( V_54 ) -> V_43 ;
}
