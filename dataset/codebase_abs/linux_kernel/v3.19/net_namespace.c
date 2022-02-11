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
F_12 ( F_30 ( V_8 -> V_13 ) ) ;
F_31 ( V_36 , V_8 ) ;
}
void F_32 ( void * V_38 )
{
struct V_8 * V_39 = V_38 ;
if ( V_39 && F_33 ( & V_39 -> V_31 ) )
F_26 ( V_39 ) ;
}
struct V_8 * F_34 ( unsigned long V_40 ,
struct V_27 * V_28 , struct V_8 * V_41 )
{
struct V_8 * V_8 ;
int V_42 ;
if ( ! ( V_40 & V_43 ) )
return F_35 ( V_41 ) ;
V_8 = F_24 () ;
if ( ! V_8 )
return F_36 ( - V_15 ) ;
F_37 ( V_28 ) ;
F_38 ( & V_12 ) ;
V_42 = F_17 ( V_8 , V_28 ) ;
if ( V_42 == 0 ) {
F_39 () ;
F_40 ( & V_8 -> V_44 , & V_45 ) ;
F_41 () ;
}
F_42 ( & V_12 ) ;
if ( V_42 < 0 ) {
F_43 ( V_28 ) ;
F_32 ( V_8 ) ;
return F_36 ( V_42 ) ;
}
return V_8 ;
}
static void F_44 ( struct V_46 * V_47 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_48 ;
struct V_24 V_49 ;
F_18 ( V_25 ) ;
F_45 ( & V_50 ) ;
F_46 ( & V_51 , & V_49 ) ;
F_47 ( & V_50 ) ;
F_38 ( & V_12 ) ;
F_39 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_48 ( & V_8 -> V_44 ) ;
F_49 ( & V_8 -> V_35 , & V_25 ) ;
}
F_41 () ;
F_50 () ;
F_51 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_51 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_42 ( & V_12 ) ;
F_23 () ;
F_52 (net, tmp, &net_exit_list, exit_list) {
F_53 ( & V_8 -> V_35 ) ;
F_43 ( V_8 -> V_28 ) ;
F_32 ( V_8 ) ;
}
}
void F_54 ( struct V_8 * V_8 )
{
unsigned long V_40 ;
F_55 ( & V_50 , V_40 ) ;
F_21 ( & V_8 -> V_51 , & V_51 ) ;
F_56 ( & V_50 , V_40 ) ;
F_57 ( V_52 , & V_53 ) ;
}
struct V_8 * F_58 ( int V_54 )
{
struct V_55 * V_55 ;
struct V_56 * V_39 ;
struct V_8 * V_8 ;
V_55 = F_59 ( V_54 ) ;
if ( F_60 ( V_55 ) )
return F_61 ( V_55 ) ;
V_39 = F_62 ( F_63 ( V_55 ) ) ;
if ( V_39 -> V_18 == & V_57 )
V_8 = F_35 ( F_64 ( V_39 , struct V_8 , V_39 ) ) ;
else
V_8 = F_36 ( - V_58 ) ;
F_65 ( V_55 ) ;
return V_8 ;
}
struct V_8 * F_58 ( int V_54 )
{
return F_36 ( - V_58 ) ;
}
struct V_8 * F_66 ( T_3 V_59 )
{
struct V_60 * V_61 ;
struct V_8 * V_8 ;
V_8 = F_36 ( - V_62 ) ;
F_67 () ;
V_61 = F_68 ( V_59 ) ;
if ( V_61 ) {
struct V_63 * V_63 ;
F_69 ( V_61 ) ;
V_63 = V_61 -> V_63 ;
if ( V_63 )
V_8 = F_35 ( V_63 -> V_64 ) ;
F_70 ( V_61 ) ;
}
F_71 () ;
return V_8 ;
}
static T_2 int F_72 ( struct V_8 * V_8 )
{
#ifdef F_73
V_8 -> V_39 . V_18 = & V_57 ;
#endif
return F_74 ( & V_8 -> V_39 ) ;
}
static T_4 void F_75 ( struct V_8 * V_8 )
{
F_76 ( & V_8 -> V_39 ) ;
}
static int T_5 F_77 ( void )
{
struct V_1 * V_2 ;
#ifdef F_73
V_36 = F_78 ( L_2 , sizeof( struct V_8 ) ,
V_65 ,
V_66 , NULL ) ;
V_52 = F_79 ( L_3 ) ;
if ( ! V_52 )
F_80 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_80 ( L_5 ) ;
F_9 ( V_67 . V_13 , V_2 ) ;
F_38 ( & V_12 ) ;
if ( F_17 ( & V_67 , & V_68 ) )
F_80 ( L_6 ) ;
F_39 () ;
F_40 ( & V_67 . V_44 , & V_45 ) ;
F_41 () ;
F_42 ( & V_12 ) ;
F_81 ( & V_69 ) ;
return 0 ;
}
static int F_82 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_18 ( V_25 ) ;
F_49 ( & V_18 -> V_44 , V_44 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_83 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_34;
F_49 ( & V_8 -> V_35 , & V_25 ) ;
}
}
return 0 ;
V_34:
F_84 ( & V_18 -> V_44 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_85 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_18 ( V_25 ) ;
F_84 ( & V_18 -> V_44 ) ;
F_83 (net)
F_49 ( & V_8 -> V_35 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_82 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_67 ) ;
}
static void F_85 ( struct V_17 * V_18 )
{
F_18 ( V_25 ) ;
F_21 ( & V_67 . V_35 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_86 ( struct V_24 * V_44 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_70:
error = F_87 ( & V_71 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_72 ) {
F_88 ( & V_71 , V_6 ) ;
goto V_70;
}
return error ;
}
V_5 = F_89 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_82 ( V_44 , V_18 ) ;
if ( error ) {
F_23 () ;
if ( V_18 -> V_9 )
F_90 ( & V_71 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_91 ( struct V_17 * V_18 )
{
F_85 ( V_18 ) ;
F_23 () ;
if ( V_18 -> V_9 )
F_90 ( & V_71 , * V_18 -> V_9 ) ;
}
int F_81 ( struct V_17 * V_18 )
{
int error ;
F_38 ( & V_12 ) ;
error = F_86 ( V_73 , V_18 ) ;
F_42 ( & V_12 ) ;
return error ;
}
void F_92 ( struct V_17 * V_18 )
{
F_38 ( & V_12 ) ;
F_91 ( V_18 ) ;
F_42 ( & V_12 ) ;
}
int F_93 ( struct V_17 * V_18 )
{
int error ;
F_38 ( & V_12 ) ;
error = F_86 ( & V_74 , V_18 ) ;
if ( ! error && ( V_73 == & V_74 ) )
V_73 = & V_18 -> V_44 ;
F_42 ( & V_12 ) ;
return error ;
}
void F_94 ( struct V_17 * V_18 )
{
F_38 ( & V_12 ) ;
if ( & V_18 -> V_44 == V_73 )
V_73 = V_73 -> V_75 ;
F_91 ( V_18 ) ;
F_42 ( & V_12 ) ;
}
static struct V_56 * F_95 ( struct V_60 * V_76 )
{
struct V_8 * V_8 = NULL ;
struct V_63 * V_63 ;
F_69 ( V_76 ) ;
V_63 = V_76 -> V_63 ;
if ( V_63 )
V_8 = F_35 ( V_63 -> V_64 ) ;
F_70 ( V_76 ) ;
return V_8 ? & V_8 -> V_39 : NULL ;
}
static inline struct V_8 * F_96 ( struct V_56 * V_39 )
{
return F_64 ( V_39 , struct V_8 , V_39 ) ;
}
static void F_97 ( struct V_56 * V_39 )
{
F_98 ( F_96 ( V_39 ) ) ;
}
static int F_99 ( struct V_63 * V_63 , struct V_56 * V_39 )
{
struct V_8 * V_8 = F_96 ( V_39 ) ;
if ( ! F_100 ( V_8 -> V_28 , V_77 ) ||
! F_100 ( F_101 () , V_77 ) )
return - V_78 ;
F_98 ( V_63 -> V_64 ) ;
V_63 -> V_64 = F_35 ( V_8 ) ;
return 0 ;
}
