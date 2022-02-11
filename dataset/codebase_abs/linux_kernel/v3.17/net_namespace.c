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
static T_2 int F_17 ( struct V_8 * V_8 , struct V_27 * V_28 )
{
const struct V_17 * V_18 , * V_29 ;
int error = 0 ;
F_18 ( V_25 ) ;
F_19 ( & V_8 -> V_30 , 1 ) ;
F_19 ( & V_8 -> V_31 , 1 ) ;
V_8 -> V_32 = 1 ;
V_8 -> V_28 = V_28 ;
#ifdef F_20
F_19 ( & V_8 -> V_33 , 0 ) ;
#endif
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_34;
}
V_21:
return error ;
V_34:
F_21 ( & V_8 -> V_35 , & V_25 ) ;
V_29 = V_18 ;
F_22 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
V_18 = V_29 ;
F_22 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_23 () ;
goto V_21;
}
static struct V_8 * F_24 ( void )
{
struct V_8 * V_8 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_21;
V_8 = F_25 ( V_36 , V_6 ) ;
if ( ! V_8 )
goto V_37;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_21:
return V_8 ;
V_37:
F_12 ( V_2 ) ;
goto V_21;
}
static void F_26 ( struct V_8 * V_8 )
{
#ifdef F_20
if ( F_27 ( F_28 ( & V_8 -> V_33 ) != 0 ) ) {
F_29 ( L_1 ,
F_28 ( & V_8 -> V_33 ) ) ;
return;
}
#endif
F_12 ( V_8 -> V_13 ) ;
F_30 ( V_36 , V_8 ) ;
}
void F_31 ( void * V_38 )
{
struct V_8 * V_39 = V_38 ;
if ( V_39 && F_32 ( & V_39 -> V_31 ) )
F_26 ( V_39 ) ;
}
struct V_8 * F_33 ( unsigned long V_40 ,
struct V_27 * V_28 , struct V_8 * V_41 )
{
struct V_8 * V_8 ;
int V_42 ;
if ( ! ( V_40 & V_43 ) )
return F_34 ( V_41 ) ;
V_8 = F_24 () ;
if ( ! V_8 )
return F_35 ( - V_15 ) ;
F_36 ( V_28 ) ;
F_37 ( & V_12 ) ;
V_42 = F_17 ( V_8 , V_28 ) ;
if ( V_42 == 0 ) {
F_38 () ;
F_39 ( & V_8 -> V_44 , & V_45 ) ;
F_40 () ;
}
F_41 ( & V_12 ) ;
if ( V_42 < 0 ) {
F_42 ( V_28 ) ;
F_31 ( V_8 ) ;
return F_35 ( V_42 ) ;
}
return V_8 ;
}
static void F_43 ( struct V_46 * V_47 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_48 ;
struct V_24 V_49 ;
F_18 ( V_25 ) ;
F_44 ( & V_50 ) ;
F_45 ( & V_51 , & V_49 ) ;
F_46 ( & V_50 ) ;
F_37 ( & V_12 ) ;
F_38 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_47 ( & V_8 -> V_44 ) ;
F_48 ( & V_8 -> V_35 , & V_25 ) ;
}
F_40 () ;
F_49 () ;
F_50 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_50 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_41 ( & V_12 ) ;
F_23 () ;
F_51 (net, tmp, &net_exit_list, exit_list) {
F_52 ( & V_8 -> V_35 ) ;
F_42 ( V_8 -> V_28 ) ;
F_31 ( V_8 ) ;
}
}
void F_53 ( struct V_8 * V_8 )
{
unsigned long V_40 ;
F_54 ( & V_50 , V_40 ) ;
F_21 ( & V_8 -> V_51 , & V_51 ) ;
F_55 ( & V_50 , V_40 ) ;
F_56 ( V_52 , & V_53 ) ;
}
struct V_8 * F_57 ( int V_54 )
{
struct V_55 * V_56 ;
struct V_57 * V_57 ;
struct V_8 * V_8 ;
V_57 = F_58 ( V_54 ) ;
if ( F_59 ( V_57 ) )
return F_60 ( V_57 ) ;
V_56 = F_61 ( F_62 ( V_57 ) ) ;
if ( V_56 -> V_58 == & V_59 )
V_8 = F_34 ( V_56 -> V_39 ) ;
else
V_8 = F_35 ( - V_60 ) ;
F_63 ( V_57 ) ;
return V_8 ;
}
struct V_8 * F_57 ( int V_54 )
{
return F_35 ( - V_60 ) ;
}
struct V_8 * F_64 ( T_3 V_61 )
{
struct V_62 * V_63 ;
struct V_8 * V_8 ;
V_8 = F_35 ( - V_64 ) ;
F_65 () ;
V_63 = F_66 ( V_61 ) ;
if ( V_63 ) {
struct V_65 * V_65 ;
F_67 ( V_63 ) ;
V_65 = V_63 -> V_65 ;
if ( V_65 )
V_8 = F_34 ( V_65 -> V_66 ) ;
F_68 ( V_63 ) ;
}
F_69 () ;
return V_8 ;
}
static T_2 int F_70 ( struct V_8 * V_8 )
{
return F_71 ( & V_8 -> V_67 ) ;
}
static T_4 void F_72 ( struct V_8 * V_8 )
{
F_73 ( V_8 -> V_67 ) ;
}
static int T_5 F_74 ( void )
{
struct V_1 * V_2 ;
#ifdef F_75
V_36 = F_76 ( L_2 , sizeof( struct V_8 ) ,
V_68 ,
V_69 , NULL ) ;
V_52 = F_77 ( L_3 ) ;
if ( ! V_52 )
F_78 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_78 ( L_5 ) ;
F_9 ( V_70 . V_13 , V_2 ) ;
F_37 ( & V_12 ) ;
if ( F_17 ( & V_70 , & V_71 ) )
F_78 ( L_6 ) ;
F_38 () ;
F_39 ( & V_70 . V_44 , & V_45 ) ;
F_40 () ;
F_41 ( & V_12 ) ;
F_79 ( & V_72 ) ;
return 0 ;
}
static int F_80 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_18 ( V_25 ) ;
F_48 ( & V_18 -> V_44 , V_44 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_81 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_34;
F_48 ( & V_8 -> V_35 , & V_25 ) ;
}
}
return 0 ;
V_34:
F_82 ( & V_18 -> V_44 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_83 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_18 ( V_25 ) ;
F_82 ( & V_18 -> V_44 ) ;
F_81 (net)
F_48 ( & V_8 -> V_35 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_80 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_70 ) ;
}
static void F_83 ( struct V_17 * V_18 )
{
F_18 ( V_25 ) ;
F_21 ( & V_70 . V_35 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_84 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_73:
error = F_85 ( & V_74 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_75 ) {
F_86 ( & V_74 , V_6 ) ;
goto V_73;
}
return error ;
}
V_5 = F_87 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_80 ( V_44 , V_18 ) ;
if ( error ) {
F_23 () ;
if ( V_18 -> V_9 )
F_88 ( & V_74 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_89 ( struct V_17 * V_18 )
{
F_83 ( V_18 ) ;
F_23 () ;
if ( V_18 -> V_9 )
F_88 ( & V_74 , * V_18 -> V_9 ) ;
}
int F_79 ( struct V_17 * V_18 )
{
int error ;
F_37 ( & V_12 ) ;
error = F_84 ( V_76 , V_18 ) ;
F_41 ( & V_12 ) ;
return error ;
}
void F_90 ( struct V_17 * V_18 )
{
F_37 ( & V_12 ) ;
F_89 ( V_18 ) ;
F_41 ( & V_12 ) ;
}
int F_91 ( struct V_17 * V_18 )
{
int error ;
F_37 ( & V_12 ) ;
error = F_84 ( & V_77 , V_18 ) ;
if ( ! error && ( V_76 == & V_77 ) )
V_76 = & V_18 -> V_44 ;
F_41 ( & V_12 ) ;
return error ;
}
void F_92 ( struct V_17 * V_18 )
{
F_37 ( & V_12 ) ;
if ( & V_18 -> V_44 == V_76 )
V_76 = V_76 -> V_78 ;
F_89 ( V_18 ) ;
F_41 ( & V_12 ) ;
}
static void * F_93 ( struct V_62 * V_79 )
{
struct V_8 * V_8 = NULL ;
struct V_65 * V_65 ;
F_67 ( V_79 ) ;
V_65 = V_79 -> V_65 ;
if ( V_65 )
V_8 = F_34 ( V_65 -> V_66 ) ;
F_68 ( V_79 ) ;
return V_8 ;
}
static void F_94 ( void * V_39 )
{
F_95 ( V_39 ) ;
}
static int F_96 ( struct V_65 * V_65 , void * V_39 )
{
struct V_8 * V_8 = V_39 ;
if ( ! F_97 ( V_8 -> V_28 , V_80 ) ||
! F_97 ( F_98 () , V_80 ) )
return - V_81 ;
F_95 ( V_65 -> V_66 ) ;
V_65 -> V_66 = F_34 ( V_8 ) ;
return 0 ;
}
static unsigned int F_99 ( void * V_39 )
{
struct V_8 * V_8 = V_39 ;
return V_8 -> V_67 ;
}
