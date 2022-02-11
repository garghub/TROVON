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
static T_2 int F_17 ( struct V_8 * V_8 )
{
const struct V_17 * V_18 , * V_27 ;
int error = 0 ;
F_18 ( V_25 ) ;
F_19 ( & V_8 -> V_28 , 1 ) ;
F_19 ( & V_8 -> V_29 , 1 ) ;
V_8 -> V_30 = 1 ;
#ifdef F_20
F_19 ( & V_8 -> V_31 , 0 ) ;
#endif
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_32;
}
V_21:
return error ;
V_32:
F_21 ( & V_8 -> V_33 , & V_25 ) ;
V_27 = V_18 ;
F_22 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
V_18 = V_27 ;
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
V_8 = F_25 ( V_34 , V_6 ) ;
if ( ! V_8 )
goto V_35;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_21:
return V_8 ;
V_35:
F_12 ( V_2 ) ;
goto V_21;
}
static void F_26 ( struct V_8 * V_8 )
{
#ifdef F_20
if ( F_27 ( F_28 ( & V_8 -> V_31 ) != 0 ) ) {
F_29 ( V_36 L_1 ,
F_28 ( & V_8 -> V_31 ) ) ;
return;
}
#endif
F_12 ( V_8 -> V_13 ) ;
F_30 ( V_34 , V_8 ) ;
}
void F_31 ( void * V_37 )
{
struct V_8 * V_38 = V_37 ;
if ( V_38 && F_32 ( & V_38 -> V_29 ) )
F_26 ( V_38 ) ;
}
struct V_8 * F_33 ( unsigned long V_39 , struct V_8 * V_40 )
{
struct V_8 * V_8 ;
int V_41 ;
if ( ! ( V_39 & V_42 ) )
return F_34 ( V_40 ) ;
V_8 = F_24 () ;
if ( ! V_8 )
return F_35 ( - V_15 ) ;
F_36 ( & V_12 ) ;
V_41 = F_17 ( V_8 ) ;
if ( V_41 == 0 ) {
F_37 () ;
F_38 ( & V_8 -> V_43 , & V_44 ) ;
F_39 () ;
}
F_40 ( & V_12 ) ;
if ( V_41 < 0 ) {
F_31 ( V_8 ) ;
return F_35 ( V_41 ) ;
}
return V_8 ;
}
static void F_41 ( struct V_45 * V_46 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_47 ;
F_18 ( V_48 ) ;
F_18 ( V_25 ) ;
F_42 ( & V_49 ) ;
F_43 ( & V_50 , & V_48 ) ;
F_44 ( & V_49 ) ;
F_36 ( & V_12 ) ;
F_37 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_45 ( & V_8 -> V_43 ) ;
F_46 ( & V_8 -> V_33 , & V_25 ) ;
}
F_39 () ;
F_47 () ;
F_48 (ops, &pernet_list, list)
F_14 ( V_18 , & V_25 ) ;
F_48 (ops, &pernet_list, list)
F_16 ( V_18 , & V_25 ) ;
F_40 ( & V_12 ) ;
F_23 () ;
F_49 (net, tmp, &net_exit_list, exit_list) {
F_50 ( & V_8 -> V_33 ) ;
F_31 ( V_8 ) ;
}
}
void F_51 ( struct V_8 * V_8 )
{
unsigned long V_39 ;
F_52 ( & V_49 , V_39 ) ;
F_21 ( & V_8 -> V_50 , & V_50 ) ;
F_53 ( & V_49 , V_39 ) ;
F_54 ( V_51 , & V_52 ) ;
}
struct V_8 * F_55 ( int V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_56 ;
struct V_8 * V_8 ;
V_56 = F_56 ( V_53 ) ;
if ( F_57 ( V_56 ) )
return F_58 ( V_56 ) ;
V_55 = F_59 ( V_56 -> V_57 -> V_58 ) ;
if ( V_55 -> V_59 == & V_60 )
V_8 = F_34 ( V_55 -> V_38 ) ;
else
V_8 = F_35 ( - V_61 ) ;
F_60 ( V_56 ) ;
return V_8 ;
}
struct V_8 * F_33 ( unsigned long V_39 , struct V_8 * V_40 )
{
if ( V_39 & V_42 )
return F_35 ( - V_61 ) ;
return V_40 ;
}
struct V_8 * F_55 ( int V_53 )
{
return F_35 ( - V_61 ) ;
}
struct V_8 * F_61 ( T_3 V_62 )
{
struct V_63 * V_64 ;
struct V_8 * V_8 ;
V_8 = F_35 ( - V_65 ) ;
F_62 () ;
V_64 = F_63 ( V_62 ) ;
if ( V_64 ) {
struct V_66 * V_66 ;
V_66 = F_64 ( V_64 ) ;
if ( V_66 )
V_8 = F_34 ( V_66 -> V_67 ) ;
}
F_65 () ;
return V_8 ;
}
static int T_4 F_66 ( void )
{
struct V_1 * V_2 ;
#ifdef F_67
V_34 = F_68 ( L_2 , sizeof( struct V_8 ) ,
V_68 ,
V_69 , NULL ) ;
V_51 = F_69 ( L_3 ) ;
if ( ! V_51 )
F_70 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_70 ( L_5 ) ;
F_9 ( V_70 . V_13 , V_2 ) ;
F_36 ( & V_12 ) ;
if ( F_17 ( & V_70 ) )
F_70 ( L_6 ) ;
F_37 () ;
F_38 ( & V_70 . V_43 , & V_44 ) ;
F_39 () ;
F_40 ( & V_12 ) ;
return 0 ;
}
static int F_71 ( struct V_24 * V_43 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_18 ( V_25 ) ;
F_46 ( & V_18 -> V_43 , V_43 ) ;
if ( V_18 -> V_23 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_72 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_32;
F_46 ( & V_8 -> V_33 , & V_25 ) ;
}
}
return 0 ;
V_32:
F_73 ( & V_18 -> V_43 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
return error ;
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_18 ( V_25 ) ;
F_73 ( & V_18 -> V_43 ) ;
F_72 (net)
F_46 ( & V_8 -> V_33 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_71 ( struct V_24 * V_43 ,
struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_70 ) ;
}
static void F_74 ( struct V_17 * V_18 )
{
F_18 ( V_25 ) ;
F_21 ( & V_70 . V_33 , & V_25 ) ;
F_14 ( V_18 , & V_25 ) ;
F_16 ( V_18 , & V_25 ) ;
}
static int F_75 ( struct V_24 * V_43 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_71:
error = F_76 ( & V_72 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_73 ) {
F_77 ( & V_72 , V_6 ) ;
goto V_71;
}
return error ;
}
V_5 = F_78 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_71 ( V_43 , V_18 ) ;
if ( error ) {
F_23 () ;
if ( V_18 -> V_9 )
F_79 ( & V_72 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_80 ( struct V_17 * V_18 )
{
F_74 ( V_18 ) ;
F_23 () ;
if ( V_18 -> V_9 )
F_79 ( & V_72 , * V_18 -> V_9 ) ;
}
int F_81 ( struct V_17 * V_18 )
{
int error ;
F_36 ( & V_12 ) ;
error = F_75 ( V_74 , V_18 ) ;
F_40 ( & V_12 ) ;
return error ;
}
void F_82 ( struct V_17 * V_18 )
{
F_36 ( & V_12 ) ;
F_80 ( V_18 ) ;
F_40 ( & V_12 ) ;
}
int F_83 ( struct V_17 * V_18 )
{
int error ;
F_36 ( & V_12 ) ;
error = F_75 ( & V_75 , V_18 ) ;
if ( ! error && ( V_74 == & V_75 ) )
V_74 = & V_18 -> V_43 ;
F_40 ( & V_12 ) ;
return error ;
}
void F_84 ( struct V_17 * V_18 )
{
F_36 ( & V_12 ) ;
if ( & V_18 -> V_43 == V_74 )
V_74 = V_74 -> V_76 ;
F_80 ( V_18 ) ;
F_40 ( & V_12 ) ;
}
static void * F_85 ( struct V_63 * V_77 )
{
struct V_8 * V_8 = NULL ;
struct V_66 * V_66 ;
F_62 () ;
V_66 = F_64 ( V_77 ) ;
if ( V_66 )
V_8 = F_34 ( V_66 -> V_67 ) ;
F_65 () ;
return V_8 ;
}
static void F_86 ( void * V_38 )
{
F_87 ( V_38 ) ;
}
static int F_88 ( struct V_66 * V_66 , void * V_38 )
{
F_87 ( V_66 -> V_67 ) ;
V_66 -> V_67 = F_34 ( V_38 ) ;
return 0 ;
}
