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
F_18 () ;
if ( V_28 >= 0 ) {
V_29 = V_28 ;
V_30 = V_28 + 1 ;
}
return F_19 ( & V_8 -> V_31 , V_27 , V_29 , V_30 , V_6 ) ;
}
static int F_20 ( int V_9 , void * V_8 , void * V_27 )
{
if ( F_21 ( V_8 , V_27 ) )
return V_9 ? : V_32 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_8 , struct V_8 * V_27 , bool V_33 )
{
int V_9 = F_23 ( & V_8 -> V_31 , F_20 , V_27 ) ;
F_18 () ;
if ( V_9 == V_32 )
return 0 ;
if ( V_9 > 0 )
return V_9 ;
if ( V_33 )
return F_17 ( V_8 , V_27 , - 1 ) ;
return - V_34 ;
}
int F_24 ( struct V_8 * V_8 , struct V_8 * V_27 )
{
bool V_33 = F_25 ( & V_27 -> V_35 ) == 0 ? false : true ;
int V_9 ;
V_9 = F_22 ( V_8 , V_27 , V_33 ) ;
return V_9 >= 0 ? V_9 : V_36 ;
}
struct V_8 * F_26 ( struct V_8 * V_8 , int V_9 )
{
struct V_8 * V_27 ;
if ( V_9 < 0 )
return NULL ;
F_27 () ;
V_27 = F_28 ( & V_8 -> V_31 , V_9 ) ;
if ( V_27 )
F_29 ( V_27 ) ;
F_30 () ;
return V_27 ;
}
static T_2 int F_31 ( struct V_8 * V_8 , struct V_37 * V_38 )
{
const struct V_17 * V_18 , * V_39 ;
int error = 0 ;
F_32 ( V_25 ) ;
F_33 ( & V_8 -> V_35 , 1 ) ;
F_33 ( & V_8 -> V_40 , 1 ) ;
V_8 -> V_41 = 1 ;
V_8 -> V_38 = V_38 ;
F_34 ( & V_8 -> V_31 ) ;
#ifdef F_35
F_33 ( & V_8 -> V_42 , 0 ) ;
#endif
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_43;
}
V_21:
return error ;
V_43:
F_36 ( & V_8 -> V_44 , & V_25 ) ;
V_39 = V_18 ;
F_37 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
V_18 = V_39 ;
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
#ifdef F_35
if ( F_42 ( F_25 ( & V_8 -> V_42 ) != 0 ) ) {
F_43 ( L_1 ,
F_25 ( & V_8 -> V_42 ) ) ;
return;
}
#endif
F_12 ( F_44 ( V_8 -> V_13 ) ) ;
F_45 ( V_45 , V_8 ) ;
}
void F_46 ( void * V_47 )
{
struct V_8 * V_48 = V_47 ;
if ( V_48 && F_47 ( & V_48 -> V_40 ) )
F_41 ( V_48 ) ;
}
struct V_8 * F_48 ( unsigned long V_49 ,
struct V_37 * V_38 , struct V_8 * V_50 )
{
struct V_8 * V_8 ;
int V_51 ;
if ( ! ( V_49 & V_52 ) )
return F_29 ( V_50 ) ;
V_8 = F_39 () ;
if ( ! V_8 )
return F_49 ( - V_15 ) ;
F_50 ( V_38 ) ;
F_51 ( & V_12 ) ;
V_51 = F_31 ( V_8 , V_38 ) ;
if ( V_51 == 0 ) {
F_52 () ;
F_53 ( & V_8 -> V_53 , & V_54 ) ;
F_54 () ;
}
F_55 ( & V_12 ) ;
if ( V_51 < 0 ) {
F_56 ( V_38 ) ;
F_46 ( V_8 ) ;
return F_49 ( V_51 ) ;
}
return V_8 ;
}
static void F_57 ( struct V_55 * V_56 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_57 ;
struct V_24 V_58 ;
F_32 ( V_25 ) ;
F_58 ( & V_59 ) ;
F_59 ( & V_60 , & V_58 ) ;
F_60 ( & V_59 ) ;
F_51 ( & V_12 ) ;
F_52 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_61 ( & V_8 -> V_53 ) ;
F_62 ( & V_8 -> V_44 , & V_25 ) ;
F_63 (tmp) {
int V_9 = F_22 ( V_57 , V_8 , false ) ;
if ( V_9 >= 0 )
F_64 ( & V_57 -> V_31 , V_9 ) ;
}
F_65 ( & V_8 -> V_31 ) ;
}
F_54 () ;
F_66 () ;
F_67 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_67 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_55 ( & V_12 ) ;
F_38 () ;
F_68 (net, tmp, &net_exit_list, exit_list) {
F_69 ( & V_8 -> V_44 ) ;
F_56 ( V_8 -> V_38 ) ;
F_46 ( V_8 ) ;
}
}
void F_70 ( struct V_8 * V_8 )
{
unsigned long V_49 ;
F_71 ( & V_59 , V_49 ) ;
F_36 ( & V_8 -> V_60 , & V_60 ) ;
F_72 ( & V_59 , V_49 ) ;
F_73 ( V_61 , & V_62 ) ;
}
struct V_8 * F_74 ( int V_63 )
{
struct V_64 * V_64 ;
struct V_65 * V_48 ;
struct V_8 * V_8 ;
V_64 = F_75 ( V_63 ) ;
if ( F_76 ( V_64 ) )
return F_77 ( V_64 ) ;
V_48 = F_78 ( F_79 ( V_64 ) ) ;
if ( V_48 -> V_18 == & V_66 )
V_8 = F_29 ( F_80 ( V_48 , struct V_8 , V_48 ) ) ;
else
V_8 = F_49 ( - V_67 ) ;
F_81 ( V_64 ) ;
return V_8 ;
}
struct V_8 * F_74 ( int V_63 )
{
return F_49 ( - V_67 ) ;
}
struct V_8 * F_82 ( T_3 V_68 )
{
struct V_69 * V_70 ;
struct V_8 * V_8 ;
V_8 = F_49 ( - V_71 ) ;
F_27 () ;
V_70 = F_83 ( V_68 ) ;
if ( V_70 ) {
struct V_72 * V_72 ;
F_84 ( V_70 ) ;
V_72 = V_70 -> V_72 ;
if ( V_72 )
V_8 = F_29 ( V_72 -> V_73 ) ;
F_85 ( V_70 ) ;
}
F_30 () ;
return V_8 ;
}
static T_2 int F_86 ( struct V_8 * V_8 )
{
#ifdef F_87
V_8 -> V_48 . V_18 = & V_66 ;
#endif
return F_88 ( & V_8 -> V_48 ) ;
}
static T_4 void F_89 ( struct V_8 * V_8 )
{
F_90 ( & V_8 -> V_48 ) ;
}
static int F_91 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_8 * V_8 = F_92 ( V_75 -> V_78 ) ;
struct V_79 * V_80 [ V_81 + 1 ] ;
struct V_8 * V_27 ;
int V_82 , V_19 ;
V_19 = F_93 ( V_77 , sizeof( struct V_83 ) , V_80 , V_81 ,
V_84 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_80 [ V_85 ] )
return - V_67 ;
V_82 = F_94 ( V_80 [ V_85 ] ) ;
if ( V_80 [ V_86 ] )
V_27 = F_82 ( F_95 ( V_80 [ V_86 ] ) ) ;
else if ( V_80 [ V_87 ] )
V_27 = F_74 ( F_95 ( V_80 [ V_87 ] ) ) ;
else
return - V_67 ;
if ( F_76 ( V_27 ) )
return F_96 ( V_27 ) ;
if ( F_22 ( V_8 , V_27 , false ) >= 0 ) {
V_19 = - V_88 ;
goto V_21;
}
V_19 = F_17 ( V_8 , V_27 , V_82 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
V_21:
F_97 ( V_27 ) ;
return V_19 ;
}
static int F_98 ( void )
{
return F_99 ( sizeof( struct V_83 ) )
+ F_100 ( sizeof( V_89 ) )
;
}
static int F_101 ( struct V_74 * V_75 , T_5 V_90 , T_5 V_91 , int V_49 ,
int V_92 , struct V_8 * V_8 , struct V_8 * V_27 )
{
struct V_76 * V_77 ;
struct V_83 * V_93 ;
int V_9 ;
F_18 () ;
V_77 = F_102 ( V_75 , V_90 , V_91 , V_92 , sizeof( * V_93 ) , V_49 ) ;
if ( ! V_77 )
return - V_94 ;
V_93 = F_103 ( V_77 ) ;
V_93 -> V_95 = V_96 ;
V_9 = F_22 ( V_8 , V_27 , false ) ;
if ( V_9 < 0 )
V_9 = V_36 ;
if ( F_104 ( V_75 , V_85 , V_9 ) )
goto V_97;
F_105 ( V_75 , V_77 ) ;
return 0 ;
V_97:
F_106 ( V_75 , V_77 ) ;
return - V_94 ;
}
static int F_107 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_8 * V_8 = F_92 ( V_75 -> V_78 ) ;
struct V_79 * V_80 [ V_81 + 1 ] ;
struct V_74 * V_98 ;
int V_19 = - V_99 ;
struct V_8 * V_27 ;
V_19 = F_93 ( V_77 , sizeof( struct V_83 ) , V_80 , V_81 ,
V_84 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_80 [ V_86 ] )
V_27 = F_82 ( F_95 ( V_80 [ V_86 ] ) ) ;
else if ( V_80 [ V_87 ] )
V_27 = F_74 ( F_95 ( V_80 [ V_87 ] ) ) ;
else
return - V_67 ;
if ( F_76 ( V_27 ) )
return F_96 ( V_27 ) ;
V_98 = F_108 ( F_98 () , V_6 ) ;
if ( ! V_98 ) {
V_19 = - V_15 ;
goto V_21;
}
V_19 = F_101 ( V_98 , F_109 ( V_75 ) . V_90 , V_77 -> V_100 , 0 ,
V_101 , V_8 , V_27 ) ;
if ( V_19 < 0 )
goto V_102;
V_19 = F_110 ( V_98 , V_8 , F_109 ( V_75 ) . V_90 ) ;
goto V_21;
V_102:
F_111 ( V_98 ) ;
V_21:
F_97 ( V_27 ) ;
return V_19 ;
}
static int T_6 F_112 ( void )
{
struct V_1 * V_2 ;
#ifdef F_87
V_45 = F_113 ( L_2 , sizeof( struct V_8 ) ,
V_103 ,
V_104 , NULL ) ;
V_61 = F_114 ( L_3 ) ;
if ( ! V_61 )
F_115 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_115 ( L_5 ) ;
F_9 ( V_105 . V_13 , V_2 ) ;
F_51 ( & V_12 ) ;
if ( F_31 ( & V_105 , & V_106 ) )
F_115 ( L_6 ) ;
F_52 () ;
F_53 ( & V_105 . V_53 , & V_54 ) ;
F_54 () ;
F_55 ( & V_12 ) ;
F_116 ( & V_107 ) ;
F_117 ( V_108 , V_109 , F_91 , NULL , NULL ) ;
F_117 ( V_108 , V_101 , F_107 , NULL , NULL ) ;
return 0 ;
}
static int F_118 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_32 ( V_25 ) ;
F_62 ( & V_18 -> V_53 , V_53 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_63 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_43;
F_62 ( & V_8 -> V_44 , & V_25 ) ;
}
}
return 0 ;
V_43:
F_119 ( & V_18 -> V_53 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_120 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_32 ( V_25 ) ;
F_119 ( & V_18 -> V_53 ) ;
F_63 (net)
F_62 ( & V_8 -> V_44 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_118 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_105 ) ;
}
static void F_120 ( struct V_17 * V_18 )
{
F_32 ( V_25 ) ;
F_36 ( & V_105 . V_44 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_121 ( struct V_24 * V_53 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_110:
error = F_122 ( & V_111 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_112 ) {
F_123 ( & V_111 , V_6 ) ;
goto V_110;
}
return error ;
}
V_5 = F_124 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_118 ( V_53 , V_18 ) ;
if ( error ) {
F_38 () ;
if ( V_18 -> V_9 )
F_125 ( & V_111 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_126 ( struct V_17 * V_18 )
{
F_120 ( V_18 ) ;
F_38 () ;
if ( V_18 -> V_9 )
F_125 ( & V_111 , * V_18 -> V_9 ) ;
}
int F_116 ( struct V_17 * V_18 )
{
int error ;
F_51 ( & V_12 ) ;
error = F_121 ( V_113 , V_18 ) ;
F_55 ( & V_12 ) ;
return error ;
}
void F_127 ( struct V_17 * V_18 )
{
F_51 ( & V_12 ) ;
F_126 ( V_18 ) ;
F_55 ( & V_12 ) ;
}
int F_128 ( struct V_17 * V_18 )
{
int error ;
F_51 ( & V_12 ) ;
error = F_121 ( & V_114 , V_18 ) ;
if ( ! error && ( V_113 == & V_114 ) )
V_113 = & V_18 -> V_53 ;
F_55 ( & V_12 ) ;
return error ;
}
void F_129 ( struct V_17 * V_18 )
{
F_51 ( & V_12 ) ;
if ( & V_18 -> V_53 == V_113 )
V_113 = V_113 -> V_115 ;
F_126 ( V_18 ) ;
F_55 ( & V_12 ) ;
}
static struct V_65 * F_130 ( struct V_69 * V_116 )
{
struct V_8 * V_8 = NULL ;
struct V_72 * V_72 ;
F_84 ( V_116 ) ;
V_72 = V_116 -> V_72 ;
if ( V_72 )
V_8 = F_29 ( V_72 -> V_73 ) ;
F_85 ( V_116 ) ;
return V_8 ? & V_8 -> V_48 : NULL ;
}
static inline struct V_8 * F_131 ( struct V_65 * V_48 )
{
return F_80 ( V_48 , struct V_8 , V_48 ) ;
}
static void F_132 ( struct V_65 * V_48 )
{
F_97 ( F_131 ( V_48 ) ) ;
}
static int F_133 ( struct V_72 * V_72 , struct V_65 * V_48 )
{
struct V_8 * V_8 = F_131 ( V_48 ) ;
if ( ! F_134 ( V_8 -> V_38 , V_117 ) ||
! F_134 ( F_135 () , V_117 ) )
return - V_118 ;
F_97 ( V_72 -> V_73 ) ;
V_72 -> V_73 = F_29 ( V_8 ) ;
return 0 ;
}
