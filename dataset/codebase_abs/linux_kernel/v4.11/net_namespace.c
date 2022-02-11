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
static struct V_49 * F_44 ( struct V_42 * V_50 )
{
return F_45 ( V_50 , F_46 () , V_51 ) ;
}
static void F_47 ( struct V_49 * V_49 )
{
F_48 ( V_49 , V_51 ) ;
}
static struct V_9 * F_49 ( void )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_22;
V_9 = F_50 ( V_52 , V_6 ) ;
if ( ! V_9 )
goto V_53;
F_9 ( V_9 -> V_15 , V_2 ) ;
V_22:
return V_9 ;
V_53:
F_12 ( V_2 ) ;
goto V_22;
}
static void F_51 ( struct V_9 * V_9 )
{
F_12 ( F_52 ( V_9 -> V_15 ) ) ;
F_53 ( V_52 , V_9 ) ;
}
void F_54 ( void * V_54 )
{
struct V_9 * V_50 = V_54 ;
if ( V_50 && F_55 ( & V_50 -> V_45 ) )
F_51 ( V_50 ) ;
}
struct V_9 * F_56 ( unsigned long V_55 ,
struct V_42 * V_43 , struct V_9 * V_56 )
{
struct V_49 * V_49 ;
struct V_9 * V_9 ;
int V_57 ;
if ( ! ( V_55 & V_58 ) )
return F_34 ( V_56 ) ;
V_49 = F_44 ( V_43 ) ;
if ( ! V_49 )
return F_57 ( - V_59 ) ;
V_9 = F_49 () ;
if ( ! V_9 ) {
F_47 ( V_49 ) ;
return F_57 ( - V_16 ) ;
}
F_58 ( V_43 ) ;
V_57 = F_59 ( & V_13 ) ;
if ( V_57 < 0 ) {
F_51 ( V_9 ) ;
F_47 ( V_49 ) ;
F_60 ( V_43 ) ;
return F_57 ( V_57 ) ;
}
V_9 -> V_49 = V_49 ;
V_57 = F_36 ( V_9 , V_43 ) ;
if ( V_57 == 0 ) {
F_61 () ;
F_62 ( & V_9 -> V_60 , & V_61 ) ;
F_63 () ;
}
F_64 ( & V_13 ) ;
if ( V_57 < 0 ) {
F_47 ( V_49 ) ;
F_60 ( V_43 ) ;
F_54 ( V_9 ) ;
return F_57 ( V_57 ) ;
}
return V_9 ;
}
static void F_65 ( struct V_62 * V_63 )
{
const struct V_18 * V_19 ;
struct V_9 * V_9 , * V_64 ;
struct V_25 V_65 ;
F_37 ( V_26 ) ;
F_66 ( & V_66 ) ;
F_67 ( & V_67 , & V_65 ) ;
F_68 ( & V_66 ) ;
F_69 ( & V_13 ) ;
F_61 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_70 ( & V_9 -> V_60 ) ;
F_71 ( & V_9 -> V_48 , & V_26 ) ;
F_72 (tmp) {
int V_10 ;
F_26 ( & V_64 -> V_40 ) ;
V_10 = F_23 ( V_64 , V_9 ) ;
if ( V_10 >= 0 )
F_73 ( & V_64 -> V_32 , V_10 ) ;
F_27 ( & V_64 -> V_40 ) ;
if ( V_10 >= 0 )
F_28 ( V_64 , V_68 , V_10 ) ;
}
F_26 ( & V_9 -> V_40 ) ;
F_74 ( & V_9 -> V_32 ) ;
F_27 ( & V_9 -> V_40 ) ;
}
F_63 () ;
F_75 () ;
F_76 (ops, &pernet_list, list)
F_14 ( V_19 , & V_26 ) ;
F_76 (ops, &pernet_list, list)
F_16 ( V_19 , & V_26 ) ;
F_64 ( & V_13 ) ;
F_43 () ;
F_77 (net, tmp, &net_exit_list, exit_list) {
F_78 ( & V_9 -> V_48 ) ;
F_47 ( V_9 -> V_49 ) ;
F_60 ( V_9 -> V_43 ) ;
F_54 ( V_9 ) ;
}
}
void F_79 ( struct V_9 * V_9 )
{
unsigned long V_55 ;
F_80 ( & V_66 , V_55 ) ;
F_41 ( & V_9 -> V_67 , & V_67 ) ;
F_81 ( & V_66 , V_55 ) ;
F_82 ( V_69 , & V_70 ) ;
}
struct V_9 * F_83 ( int V_71 )
{
struct V_72 * V_72 ;
struct V_73 * V_50 ;
struct V_9 * V_9 ;
V_72 = F_84 ( V_71 ) ;
if ( F_85 ( V_72 ) )
return F_86 ( V_72 ) ;
V_50 = F_87 ( F_88 ( V_72 ) ) ;
if ( V_50 -> V_19 == & V_74 )
V_9 = F_34 ( F_89 ( V_50 , struct V_9 , V_50 ) ) ;
else
V_9 = F_57 ( - V_75 ) ;
F_90 ( V_72 ) ;
return V_9 ;
}
struct V_9 * F_83 ( int V_71 )
{
return F_57 ( - V_75 ) ;
}
struct V_9 * F_91 ( T_2 V_76 )
{
struct V_77 * V_78 ;
struct V_9 * V_9 ;
V_9 = F_57 ( - V_79 ) ;
F_32 () ;
V_78 = F_92 ( V_76 ) ;
if ( V_78 ) {
struct V_80 * V_80 ;
F_93 ( V_78 ) ;
V_80 = V_78 -> V_80 ;
if ( V_80 )
V_9 = F_34 ( V_80 -> V_81 ) ;
F_94 ( V_78 ) ;
}
F_35 () ;
return V_9 ;
}
static T_1 int F_95 ( struct V_9 * V_9 )
{
#ifdef F_96
V_9 -> V_50 . V_19 = & V_74 ;
#endif
return F_97 ( & V_9 -> V_50 ) ;
}
static T_3 void F_98 ( struct V_9 * V_9 )
{
F_99 ( & V_9 -> V_50 ) ;
}
static int F_100 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
struct V_9 * V_9 = F_101 ( V_83 -> V_86 ) ;
struct V_87 * V_88 [ V_89 + 1 ] ;
struct V_9 * V_28 ;
int V_90 , V_20 ;
V_20 = F_102 ( V_85 , sizeof( struct V_91 ) , V_88 , V_89 ,
V_92 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_88 [ V_93 ] )
return - V_75 ;
V_90 = F_103 ( V_88 [ V_93 ] ) ;
if ( V_88 [ V_94 ] )
V_28 = F_91 ( F_104 ( V_88 [ V_94 ] ) ) ;
else if ( V_88 [ V_95 ] )
V_28 = F_83 ( F_104 ( V_88 [ V_95 ] ) ) ;
else
return - V_75 ;
if ( F_85 ( V_28 ) )
return F_105 ( V_28 ) ;
F_26 ( & V_9 -> V_40 ) ;
if ( F_23 ( V_9 , V_28 ) >= 0 ) {
F_27 ( & V_9 -> V_40 ) ;
V_20 = - V_96 ;
goto V_22;
}
V_20 = F_17 ( V_9 , V_28 , V_90 ) ;
F_27 ( & V_9 -> V_40 ) ;
if ( V_20 >= 0 ) {
F_28 ( V_9 , V_41 , V_20 ) ;
V_20 = 0 ;
}
V_22:
F_106 ( V_28 ) ;
return V_20 ;
}
static int F_107 ( void )
{
return F_108 ( sizeof( struct V_91 ) )
+ F_109 ( sizeof( V_97 ) )
;
}
static int F_110 ( struct V_82 * V_83 , T_4 V_98 , T_4 V_99 , int V_55 ,
int V_100 , struct V_9 * V_9 , int V_90 )
{
struct V_84 * V_85 ;
struct V_91 * V_101 ;
V_85 = F_111 ( V_83 , V_98 , V_99 , V_100 , sizeof( * V_101 ) , V_55 ) ;
if ( ! V_85 )
return - V_102 ;
V_101 = F_112 ( V_85 ) ;
V_101 -> V_103 = V_104 ;
if ( F_113 ( V_83 , V_93 , V_90 ) )
goto V_105;
F_114 ( V_83 , V_85 ) ;
return 0 ;
V_105:
F_115 ( V_83 , V_85 ) ;
return - V_102 ;
}
static int F_116 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
struct V_9 * V_9 = F_101 ( V_83 -> V_86 ) ;
struct V_87 * V_88 [ V_89 + 1 ] ;
struct V_82 * V_106 ;
struct V_9 * V_28 ;
int V_20 , V_10 ;
V_20 = F_102 ( V_85 , sizeof( struct V_91 ) , V_88 , V_89 ,
V_92 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_88 [ V_94 ] )
V_28 = F_91 ( F_104 ( V_88 [ V_94 ] ) ) ;
else if ( V_88 [ V_95 ] )
V_28 = F_83 ( F_104 ( V_88 [ V_95 ] ) ) ;
else
return - V_75 ;
if ( F_85 ( V_28 ) )
return F_105 ( V_28 ) ;
V_106 = F_117 ( F_107 () , V_6 ) ;
if ( ! V_106 ) {
V_20 = - V_16 ;
goto V_22;
}
V_10 = F_29 ( V_9 , V_28 ) ;
V_20 = F_110 ( V_106 , F_118 ( V_83 ) . V_98 , V_85 -> V_107 , 0 ,
V_41 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_108;
V_20 = F_119 ( V_106 , V_9 , F_118 ( V_83 ) . V_98 ) ;
goto V_22;
V_108:
F_120 ( V_106 ) ;
V_22:
F_106 ( V_28 ) ;
return V_20 ;
}
static int F_121 ( int V_10 , void * V_28 , void * V_11 )
{
struct V_109 * V_110 = (struct V_109 * ) V_11 ;
int V_111 ;
if ( V_110 -> V_112 < V_110 -> V_113 )
goto V_114;
V_111 = F_110 ( V_110 -> V_83 , F_118 ( V_110 -> V_115 -> V_83 ) . V_98 ,
V_110 -> V_115 -> V_85 -> V_107 , V_116 ,
V_41 , V_110 -> V_9 , V_10 ) ;
if ( V_111 < 0 )
return V_111 ;
V_114:
V_110 -> V_112 ++ ;
return 0 ;
}
static int F_122 ( struct V_82 * V_83 , struct V_117 * V_115 )
{
struct V_9 * V_9 = F_101 ( V_83 -> V_86 ) ;
struct V_109 V_110 = {
. V_9 = V_9 ,
. V_83 = V_83 ,
. V_115 = V_115 ,
. V_112 = 0 ,
. V_113 = V_115 -> args [ 0 ] ,
} ;
F_26 ( & V_9 -> V_40 ) ;
F_22 ( & V_9 -> V_32 , F_121 , & V_110 ) ;
F_27 ( & V_9 -> V_40 ) ;
V_115 -> args [ 0 ] = V_110 . V_112 ;
return V_83 -> V_8 ;
}
static void F_28 ( struct V_9 * V_9 , int V_100 , int V_10 )
{
struct V_82 * V_106 ;
int V_20 = - V_16 ;
V_106 = F_117 ( F_107 () , V_6 ) ;
if ( ! V_106 )
goto V_22;
V_20 = F_110 ( V_106 , 0 , 0 , 0 , V_100 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_108;
F_123 ( V_106 , V_9 , 0 , V_118 , NULL , 0 ) ;
return;
V_108:
F_120 ( V_106 ) ;
V_22:
F_124 ( V_9 , V_118 , V_20 ) ;
}
static int T_5 F_125 ( void )
{
struct V_1 * V_2 ;
#ifdef F_96
V_52 = F_126 ( L_1 , sizeof( struct V_9 ) ,
V_119 ,
V_120 , NULL ) ;
V_69 = F_127 ( L_2 ) ;
if ( ! V_69 )
F_128 ( L_3 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_128 ( L_4 ) ;
F_9 ( V_121 . V_15 , V_2 ) ;
F_69 ( & V_13 ) ;
if ( F_36 ( & V_121 , & V_122 ) )
F_128 ( L_5 ) ;
V_123 = true ;
F_61 () ;
F_62 ( & V_121 . V_60 , & V_61 ) ;
F_63 () ;
F_64 ( & V_13 ) ;
F_129 ( & V_124 ) ;
F_130 ( V_125 , V_41 , F_100 , NULL , NULL ) ;
F_130 ( V_125 , V_126 , F_116 , F_122 ,
NULL ) ;
return 0 ;
}
static int F_131 ( struct V_25 * V_60 ,
struct V_18 * V_19 )
{
struct V_9 * V_9 ;
int error ;
F_37 ( V_26 ) ;
F_71 ( & V_19 -> V_60 , V_60 ) ;
if ( V_19 -> V_24 || ( V_19 -> V_10 && V_19 -> V_21 ) ) {
F_72 (net) {
error = F_11 ( V_19 , V_9 ) ;
if ( error )
goto V_47;
F_71 ( & V_9 -> V_48 , & V_26 ) ;
}
}
return 0 ;
V_47:
F_132 ( & V_19 -> V_60 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
return error ;
}
static void F_133 ( struct V_18 * V_19 )
{
struct V_9 * V_9 ;
F_37 ( V_26 ) ;
F_132 ( & V_19 -> V_60 ) ;
F_72 (net)
F_71 ( & V_9 -> V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
static int F_131 ( struct V_25 * V_60 ,
struct V_18 * V_19 )
{
if ( ! V_123 ) {
F_71 ( & V_19 -> V_60 , V_60 ) ;
return 0 ;
}
return F_11 ( V_19 , & V_121 ) ;
}
static void F_133 ( struct V_18 * V_19 )
{
if ( ! V_123 ) {
F_132 ( & V_19 -> V_60 ) ;
} else {
F_37 ( V_26 ) ;
F_41 ( & V_121 . V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
}
static int F_134 ( struct V_25 * V_60 ,
struct V_18 * V_19 )
{
int error ;
if ( V_19 -> V_10 ) {
V_127:
error = F_135 ( & V_128 , V_14 , V_19 -> V_10 ) ;
if ( error < 0 ) {
if ( error == - V_129 ) {
F_136 ( & V_128 , V_6 ) ;
goto V_127;
}
return error ;
}
V_5 = V_31 ( V_5 , * V_19 -> V_10 + 1 ) ;
}
error = F_131 ( V_60 , V_19 ) ;
if ( error ) {
F_43 () ;
if ( V_19 -> V_10 )
F_137 ( & V_128 , * V_19 -> V_10 ) ;
}
return error ;
}
static void F_138 ( struct V_18 * V_19 )
{
F_133 ( V_19 ) ;
F_43 () ;
if ( V_19 -> V_10 )
F_137 ( & V_128 , * V_19 -> V_10 ) ;
}
int F_129 ( struct V_18 * V_19 )
{
int error ;
F_69 ( & V_13 ) ;
error = F_134 ( V_130 , V_19 ) ;
F_64 ( & V_13 ) ;
return error ;
}
void F_139 ( struct V_18 * V_19 )
{
F_69 ( & V_13 ) ;
F_138 ( V_19 ) ;
F_64 ( & V_13 ) ;
}
int F_140 ( struct V_18 * V_19 )
{
int error ;
F_69 ( & V_13 ) ;
error = F_134 ( & V_131 , V_19 ) ;
if ( ! error && ( V_130 == & V_131 ) )
V_130 = & V_19 -> V_60 ;
F_64 ( & V_13 ) ;
return error ;
}
void F_141 ( struct V_18 * V_19 )
{
F_69 ( & V_13 ) ;
if ( & V_19 -> V_60 == V_130 )
V_130 = V_130 -> V_132 ;
F_138 ( V_19 ) ;
F_64 ( & V_13 ) ;
}
static struct V_73 * F_142 ( struct V_77 * V_133 )
{
struct V_9 * V_9 = NULL ;
struct V_80 * V_80 ;
F_93 ( V_133 ) ;
V_80 = V_133 -> V_80 ;
if ( V_80 )
V_9 = F_34 ( V_80 -> V_81 ) ;
F_94 ( V_133 ) ;
return V_9 ? & V_9 -> V_50 : NULL ;
}
static inline struct V_9 * F_143 ( struct V_73 * V_50 )
{
return F_89 ( V_50 , struct V_9 , V_50 ) ;
}
static void F_144 ( struct V_73 * V_50 )
{
F_106 ( F_143 ( V_50 ) ) ;
}
static int F_145 ( struct V_80 * V_80 , struct V_73 * V_50 )
{
struct V_9 * V_9 = F_143 ( V_50 ) ;
if ( ! F_146 ( V_9 -> V_43 , V_134 ) ||
! F_146 ( F_147 () , V_134 ) )
return - V_135 ;
F_106 ( V_80 -> V_81 ) ;
V_80 -> V_81 = F_34 ( V_9 ) ;
return 0 ;
}
static struct V_42 * F_148 ( struct V_73 * V_50 )
{
return F_143 ( V_50 ) -> V_43 ;
}
