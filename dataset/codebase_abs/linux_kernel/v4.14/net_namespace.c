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
F_39 ( & V_9 -> V_45 , 1 ) ;
V_9 -> V_46 = 1 ;
V_9 -> V_43 = V_43 ;
F_40 ( & V_9 -> V_32 ) ;
F_41 ( & V_9 -> V_40 ) ;
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_19 , V_9 ) ;
if ( error < 0 )
goto V_47;
}
V_22:
return error ;
V_47:
F_42 ( & V_9 -> V_48 , & V_26 ) ;
V_44 = V_19 ;
F_43 (ops, &pernet_list, list)
F_14 ( V_19 , & V_26 ) ;
V_19 = V_44 ;
F_43 (ops, &pernet_list, list)
F_16 ( V_19 , & V_26 ) ;
F_44 () ;
goto V_22;
}
static int T_1 F_45 ( struct V_9 * V_9 )
{
V_9 -> V_49 . V_50 = V_51 ;
return 0 ;
}
static T_2 int F_46 ( void )
{
if ( F_47 ( & V_52 ) )
F_48 ( L_1 ) ;
return 0 ;
}
static struct V_53 * F_49 ( struct V_42 * V_54 )
{
return F_50 ( V_54 , F_51 () , V_55 ) ;
}
static void F_52 ( struct V_53 * V_53 )
{
F_53 ( V_53 , V_55 ) ;
}
static struct V_9 * F_54 ( void )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_22;
V_9 = F_55 ( V_56 , V_6 ) ;
if ( ! V_9 )
goto V_57;
F_9 ( V_9 -> V_15 , V_2 ) ;
V_22:
return V_9 ;
V_57:
F_12 ( V_2 ) ;
goto V_22;
}
static void F_56 ( struct V_9 * V_9 )
{
F_12 ( F_57 ( V_9 -> V_15 ) ) ;
F_58 ( V_56 , V_9 ) ;
}
void F_59 ( void * V_58 )
{
struct V_9 * V_54 = V_58 ;
if ( V_54 && F_60 ( & V_54 -> V_45 ) )
F_56 ( V_54 ) ;
}
struct V_9 * F_61 ( unsigned long V_59 ,
struct V_42 * V_43 , struct V_9 * V_60 )
{
struct V_53 * V_53 ;
struct V_9 * V_9 ;
int V_61 ;
if ( ! ( V_59 & V_62 ) )
return F_34 ( V_60 ) ;
V_53 = F_49 ( V_43 ) ;
if ( ! V_53 )
return F_62 ( - V_63 ) ;
V_9 = F_54 () ;
if ( ! V_9 ) {
F_52 ( V_53 ) ;
return F_62 ( - V_16 ) ;
}
F_63 ( V_43 ) ;
V_61 = F_64 ( & V_13 ) ;
if ( V_61 < 0 ) {
F_56 ( V_9 ) ;
F_52 ( V_53 ) ;
F_65 ( V_43 ) ;
return F_62 ( V_61 ) ;
}
V_9 -> V_53 = V_53 ;
V_61 = F_36 ( V_9 , V_43 ) ;
if ( V_61 == 0 ) {
F_66 () ;
F_67 ( & V_9 -> V_64 , & V_65 ) ;
F_68 () ;
}
F_69 ( & V_13 ) ;
if ( V_61 < 0 ) {
F_52 ( V_53 ) ;
F_65 ( V_43 ) ;
F_59 ( V_9 ) ;
return F_62 ( V_61 ) ;
}
return V_9 ;
}
static void F_70 ( struct V_66 * V_67 )
{
const struct V_18 * V_19 ;
struct V_9 * V_9 , * V_68 ;
struct V_25 V_69 ;
F_37 ( V_26 ) ;
F_71 ( & V_70 ) ;
F_72 ( & V_71 , & V_69 ) ;
F_73 ( & V_70 ) ;
F_74 ( & V_13 ) ;
F_66 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_75 ( & V_9 -> V_64 ) ;
F_76 ( & V_9 -> V_48 , & V_26 ) ;
F_77 (tmp) {
int V_10 ;
F_26 ( & V_68 -> V_40 ) ;
V_10 = F_23 ( V_68 , V_9 ) ;
if ( V_10 >= 0 )
F_78 ( & V_68 -> V_32 , V_10 ) ;
F_27 ( & V_68 -> V_40 ) ;
if ( V_10 >= 0 )
F_28 ( V_68 , V_72 , V_10 ) ;
}
F_26 ( & V_9 -> V_40 ) ;
F_79 ( & V_9 -> V_32 ) ;
F_27 ( & V_9 -> V_40 ) ;
}
F_68 () ;
F_80 () ;
F_81 (ops, &pernet_list, list)
F_14 ( V_19 , & V_26 ) ;
F_81 (ops, &pernet_list, list)
F_16 ( V_19 , & V_26 ) ;
F_69 ( & V_13 ) ;
F_44 () ;
F_82 (net, tmp, &net_exit_list, exit_list) {
F_83 ( & V_9 -> V_48 ) ;
F_52 ( V_9 -> V_53 ) ;
F_65 ( V_9 -> V_43 ) ;
F_59 ( V_9 ) ;
}
}
void F_84 ( void )
{
F_74 ( & V_13 ) ;
F_69 ( & V_13 ) ;
}
void F_85 ( struct V_9 * V_9 )
{
unsigned long V_59 ;
F_86 ( & V_70 , V_59 ) ;
F_42 ( & V_9 -> V_71 , & V_71 ) ;
F_87 ( & V_70 , V_59 ) ;
F_88 ( V_73 , & V_74 ) ;
}
struct V_9 * F_89 ( int V_75 )
{
struct V_76 * V_76 ;
struct V_77 * V_54 ;
struct V_9 * V_9 ;
V_76 = F_90 ( V_75 ) ;
if ( F_91 ( V_76 ) )
return F_92 ( V_76 ) ;
V_54 = F_93 ( F_94 ( V_76 ) ) ;
if ( V_54 -> V_19 == & V_78 )
V_9 = F_34 ( F_95 ( V_54 , struct V_9 , V_54 ) ) ;
else
V_9 = F_62 ( - V_79 ) ;
F_96 ( V_76 ) ;
return V_9 ;
}
struct V_9 * F_89 ( int V_75 )
{
return F_62 ( - V_79 ) ;
}
struct V_9 * F_97 ( T_3 V_80 )
{
struct V_81 * V_82 ;
struct V_9 * V_9 ;
V_9 = F_62 ( - V_83 ) ;
F_32 () ;
V_82 = F_98 ( V_80 ) ;
if ( V_82 ) {
struct V_84 * V_84 ;
F_99 ( V_82 ) ;
V_84 = V_82 -> V_84 ;
if ( V_84 )
V_9 = F_34 ( V_84 -> V_85 ) ;
F_100 ( V_82 ) ;
}
F_35 () ;
return V_9 ;
}
static T_1 int F_101 ( struct V_9 * V_9 )
{
#ifdef F_102
V_9 -> V_54 . V_19 = & V_78 ;
#endif
return F_103 ( & V_9 -> V_54 ) ;
}
static T_4 void F_104 ( struct V_9 * V_9 )
{
F_105 ( & V_9 -> V_54 ) ;
}
static int F_106 ( struct V_86 * V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_9 * V_9 = F_107 ( V_87 -> V_92 ) ;
struct V_93 * V_94 [ V_95 + 1 ] ;
struct V_93 * V_96 ;
struct V_9 * V_28 ;
int V_97 , V_20 ;
V_20 = F_108 ( V_89 , sizeof( struct V_98 ) , V_94 , V_95 ,
V_99 , V_91 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_94 [ V_100 ] ) {
F_109 ( V_91 , L_2 ) ;
return - V_79 ;
}
V_97 = F_110 ( V_94 [ V_100 ] ) ;
if ( V_94 [ V_101 ] ) {
V_28 = F_97 ( F_111 ( V_94 [ V_101 ] ) ) ;
V_96 = V_94 [ V_101 ] ;
} else if ( V_94 [ V_102 ] ) {
V_28 = F_89 ( F_111 ( V_94 [ V_102 ] ) ) ;
V_96 = V_94 [ V_102 ] ;
} else {
F_109 ( V_91 , L_3 ) ;
return - V_79 ;
}
if ( F_91 ( V_28 ) ) {
F_112 ( V_91 , V_96 ) ;
F_109 ( V_91 , L_4 ) ;
return F_113 ( V_28 ) ;
}
F_26 ( & V_9 -> V_40 ) ;
if ( F_23 ( V_9 , V_28 ) >= 0 ) {
F_27 ( & V_9 -> V_40 ) ;
V_20 = - V_103 ;
F_112 ( V_91 , V_96 ) ;
F_109 ( V_91 ,
L_5 ) ;
goto V_22;
}
V_20 = F_17 ( V_9 , V_28 , V_97 ) ;
F_27 ( & V_9 -> V_40 ) ;
if ( V_20 >= 0 ) {
F_28 ( V_9 , V_41 , V_20 ) ;
V_20 = 0 ;
} else if ( V_20 == - V_63 && V_97 >= 0 ) {
V_20 = - V_103 ;
F_112 ( V_91 , V_94 [ V_100 ] ) ;
F_109 ( V_91 , L_6 ) ;
}
V_22:
F_114 ( V_28 ) ;
return V_20 ;
}
static int F_115 ( void )
{
return F_116 ( sizeof( struct V_98 ) )
+ F_117 ( sizeof( V_104 ) )
;
}
static int F_118 ( struct V_86 * V_87 , T_5 V_105 , T_5 V_106 , int V_59 ,
int V_107 , struct V_9 * V_9 , int V_97 )
{
struct V_88 * V_89 ;
struct V_98 * V_108 ;
V_89 = F_119 ( V_87 , V_105 , V_106 , V_107 , sizeof( * V_108 ) , V_59 ) ;
if ( ! V_89 )
return - V_109 ;
V_108 = F_120 ( V_89 ) ;
V_108 -> V_110 = V_111 ;
if ( F_121 ( V_87 , V_100 , V_97 ) )
goto V_112;
F_122 ( V_87 , V_89 ) ;
return 0 ;
V_112:
F_123 ( V_87 , V_89 ) ;
return - V_109 ;
}
static int F_124 ( struct V_86 * V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_9 * V_9 = F_107 ( V_87 -> V_92 ) ;
struct V_93 * V_94 [ V_95 + 1 ] ;
struct V_93 * V_96 ;
struct V_86 * V_113 ;
struct V_9 * V_28 ;
int V_20 , V_10 ;
V_20 = F_108 ( V_89 , sizeof( struct V_98 ) , V_94 , V_95 ,
V_99 , V_91 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_94 [ V_101 ] ) {
V_28 = F_97 ( F_111 ( V_94 [ V_101 ] ) ) ;
V_96 = V_94 [ V_101 ] ;
} else if ( V_94 [ V_102 ] ) {
V_28 = F_89 ( F_111 ( V_94 [ V_102 ] ) ) ;
V_96 = V_94 [ V_102 ] ;
} else {
F_109 ( V_91 , L_3 ) ;
return - V_79 ;
}
if ( F_91 ( V_28 ) ) {
F_112 ( V_91 , V_96 ) ;
F_109 ( V_91 , L_4 ) ;
return F_113 ( V_28 ) ;
}
V_113 = F_125 ( F_115 () , V_6 ) ;
if ( ! V_113 ) {
V_20 = - V_16 ;
goto V_22;
}
V_10 = F_29 ( V_9 , V_28 ) ;
V_20 = F_118 ( V_113 , F_126 ( V_87 ) . V_105 , V_89 -> V_114 , 0 ,
V_41 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_115;
V_20 = F_127 ( V_113 , V_9 , F_126 ( V_87 ) . V_105 ) ;
goto V_22;
V_115:
F_128 ( V_113 ) ;
V_22:
F_114 ( V_28 ) ;
return V_20 ;
}
static int F_129 ( int V_10 , void * V_28 , void * V_11 )
{
struct V_116 * V_117 = (struct V_116 * ) V_11 ;
int V_118 ;
if ( V_117 -> V_119 < V_117 -> V_120 )
goto V_121;
V_118 = F_118 ( V_117 -> V_87 , F_126 ( V_117 -> V_122 -> V_87 ) . V_105 ,
V_117 -> V_122 -> V_89 -> V_114 , V_123 ,
V_41 , V_117 -> V_9 , V_10 ) ;
if ( V_118 < 0 )
return V_118 ;
V_121:
V_117 -> V_119 ++ ;
return 0 ;
}
static int F_130 ( struct V_86 * V_87 , struct V_124 * V_122 )
{
struct V_9 * V_9 = F_107 ( V_87 -> V_92 ) ;
struct V_116 V_117 = {
. V_9 = V_9 ,
. V_87 = V_87 ,
. V_122 = V_122 ,
. V_119 = 0 ,
. V_120 = V_122 -> args [ 0 ] ,
} ;
F_26 ( & V_9 -> V_40 ) ;
F_22 ( & V_9 -> V_32 , F_129 , & V_117 ) ;
F_27 ( & V_9 -> V_40 ) ;
V_122 -> args [ 0 ] = V_117 . V_119 ;
return V_87 -> V_8 ;
}
static void F_28 ( struct V_9 * V_9 , int V_107 , int V_10 )
{
struct V_86 * V_113 ;
int V_20 = - V_16 ;
V_113 = F_125 ( F_115 () , V_6 ) ;
if ( ! V_113 )
goto V_22;
V_20 = F_118 ( V_113 , 0 , 0 , 0 , V_107 , V_9 , V_10 ) ;
if ( V_20 < 0 )
goto V_115;
F_131 ( V_113 , V_9 , 0 , V_125 , NULL , 0 ) ;
return;
V_115:
F_128 ( V_113 ) ;
V_22:
F_132 ( V_9 , V_125 , V_20 ) ;
}
static int T_2 F_133 ( void )
{
struct V_1 * V_2 ;
#ifdef F_102
V_56 = F_134 ( L_7 , sizeof( struct V_9 ) ,
V_126 ,
V_127 , NULL ) ;
V_73 = F_135 ( L_8 ) ;
if ( ! V_73 )
F_48 ( L_9 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_48 ( L_10 ) ;
F_9 ( V_128 . V_15 , V_2 ) ;
F_74 ( & V_13 ) ;
if ( F_36 ( & V_128 , & V_129 ) )
F_48 ( L_11 ) ;
V_130 = true ;
F_66 () ;
F_67 ( & V_128 . V_64 , & V_65 ) ;
F_68 () ;
F_69 ( & V_13 ) ;
F_47 ( & V_131 ) ;
F_136 ( V_132 , V_41 , F_106 , NULL ,
V_133 ) ;
F_136 ( V_132 , V_134 , F_124 , F_130 ,
V_133 ) ;
return 0 ;
}
static int F_137 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
struct V_9 * V_9 ;
int error ;
F_37 ( V_26 ) ;
F_76 ( & V_19 -> V_64 , V_64 ) ;
if ( V_19 -> V_24 || ( V_19 -> V_10 && V_19 -> V_21 ) ) {
F_77 (net) {
error = F_11 ( V_19 , V_9 ) ;
if ( error )
goto V_47;
F_76 ( & V_9 -> V_48 , & V_26 ) ;
}
}
return 0 ;
V_47:
F_138 ( & V_19 -> V_64 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
return error ;
}
static void F_139 ( struct V_18 * V_19 )
{
struct V_9 * V_9 ;
F_37 ( V_26 ) ;
F_138 ( & V_19 -> V_64 ) ;
F_77 (net)
F_76 ( & V_9 -> V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
static int F_137 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
if ( ! V_130 ) {
F_76 ( & V_19 -> V_64 , V_64 ) ;
return 0 ;
}
return F_11 ( V_19 , & V_128 ) ;
}
static void F_139 ( struct V_18 * V_19 )
{
if ( ! V_130 ) {
F_138 ( & V_19 -> V_64 ) ;
} else {
F_37 ( V_26 ) ;
F_42 ( & V_128 . V_48 , & V_26 ) ;
F_14 ( V_19 , & V_26 ) ;
F_16 ( V_19 , & V_26 ) ;
}
}
static int F_140 ( struct V_25 * V_64 ,
struct V_18 * V_19 )
{
int error ;
if ( V_19 -> V_10 ) {
V_135:
error = F_141 ( & V_136 , V_14 , V_19 -> V_10 ) ;
if ( error < 0 ) {
if ( error == - V_137 ) {
F_142 ( & V_136 , V_6 ) ;
goto V_135;
}
return error ;
}
V_5 = V_31 ( V_5 , * V_19 -> V_10 + 1 ) ;
}
error = F_137 ( V_64 , V_19 ) ;
if ( error ) {
F_44 () ;
if ( V_19 -> V_10 )
F_143 ( & V_136 , * V_19 -> V_10 ) ;
}
return error ;
}
static void F_144 ( struct V_18 * V_19 )
{
F_139 ( V_19 ) ;
F_44 () ;
if ( V_19 -> V_10 )
F_143 ( & V_136 , * V_19 -> V_10 ) ;
}
int F_47 ( struct V_18 * V_19 )
{
int error ;
F_74 ( & V_13 ) ;
error = F_140 ( V_138 , V_19 ) ;
F_69 ( & V_13 ) ;
return error ;
}
void F_145 ( struct V_18 * V_19 )
{
F_74 ( & V_13 ) ;
F_144 ( V_19 ) ;
F_69 ( & V_13 ) ;
}
int F_146 ( struct V_18 * V_19 )
{
int error ;
F_74 ( & V_13 ) ;
error = F_140 ( & V_139 , V_19 ) ;
if ( ! error && ( V_138 == & V_139 ) )
V_138 = & V_19 -> V_64 ;
F_69 ( & V_13 ) ;
return error ;
}
void F_147 ( struct V_18 * V_19 )
{
F_74 ( & V_13 ) ;
if ( & V_19 -> V_64 == V_138 )
V_138 = V_138 -> V_140 ;
F_144 ( V_19 ) ;
F_69 ( & V_13 ) ;
}
static struct V_77 * F_148 ( struct V_81 * V_141 )
{
struct V_9 * V_9 = NULL ;
struct V_84 * V_84 ;
F_99 ( V_141 ) ;
V_84 = V_141 -> V_84 ;
if ( V_84 )
V_9 = F_34 ( V_84 -> V_85 ) ;
F_100 ( V_141 ) ;
return V_9 ? & V_9 -> V_54 : NULL ;
}
static inline struct V_9 * F_149 ( struct V_77 * V_54 )
{
return F_95 ( V_54 , struct V_9 , V_54 ) ;
}
static void F_150 ( struct V_77 * V_54 )
{
F_114 ( F_149 ( V_54 ) ) ;
}
static int F_151 ( struct V_84 * V_84 , struct V_77 * V_54 )
{
struct V_9 * V_9 = F_149 ( V_54 ) ;
if ( ! F_152 ( V_9 -> V_43 , V_142 ) ||
! F_152 ( F_153 () , V_142 ) )
return - V_143 ;
F_114 ( V_84 -> V_85 ) ;
V_84 -> V_85 = F_34 ( V_9 ) ;
return 0 ;
}
static struct V_42 * F_154 ( struct V_77 * V_54 )
{
return F_149 ( V_54 ) -> V_43 ;
}
