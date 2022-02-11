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
int V_19 ;
if ( V_18 -> V_9 && V_18 -> V_20 ) {
void * V_10 = F_3 ( V_18 -> V_20 , V_6 ) ;
if ( ! V_10 )
return - V_15 ;
V_19 = F_4 ( V_8 , * V_18 -> V_9 , V_10 ) ;
if ( V_19 ) {
F_12 ( V_10 ) ;
return V_19 ;
}
}
if ( V_18 -> V_21 )
return V_18 -> V_21 ( V_8 ) ;
return 0 ;
}
static void F_13 ( const struct V_17 * V_18 , struct V_8 * V_8 )
{
if ( V_18 -> V_9 && V_18 -> V_20 ) {
int V_9 = * V_18 -> V_9 ;
F_12 ( V_1 ( V_8 , V_9 ) ) ;
}
}
static void F_14 ( const struct V_17 * V_18 ,
struct V_22 * V_23 )
{
struct V_8 * V_8 ;
if ( V_18 -> exit ) {
F_15 (net, net_exit_list, exit_list)
V_18 -> exit ( V_8 ) ;
}
if ( V_18 -> V_24 )
V_18 -> V_24 ( V_23 ) ;
}
static void F_16 ( const struct V_17 * V_18 ,
struct V_22 * V_23 )
{
struct V_8 * V_8 ;
if ( V_18 -> V_20 && V_18 -> V_9 ) {
F_15 (net, net_exit_list, exit_list)
F_13 ( V_18 , V_8 ) ;
}
}
static T_2 int F_17 ( struct V_8 * V_8 )
{
const struct V_17 * V_18 , * V_25 ;
int error = 0 ;
F_18 ( V_23 ) ;
F_19 ( & V_8 -> V_26 , 1 ) ;
F_19 ( & V_8 -> V_27 , 1 ) ;
V_8 -> V_28 = 1 ;
#ifdef F_20
F_19 ( & V_8 -> V_29 , 0 ) ;
#endif
F_15 (ops, &pernet_list, list) {
error = F_11 ( V_18 , V_8 ) ;
if ( error < 0 )
goto V_30;
}
V_31:
return error ;
V_30:
F_21 ( & V_8 -> V_32 , & V_23 ) ;
V_25 = V_18 ;
F_22 (ops, &pernet_list, list)
F_14 ( V_18 , & V_23 ) ;
V_18 = V_25 ;
F_22 (ops, &pernet_list, list)
F_16 ( V_18 , & V_23 ) ;
F_23 () ;
goto V_31;
}
static struct V_8 * F_24 ( void )
{
struct V_8 * V_8 = NULL ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
goto V_31;
V_8 = F_25 ( V_33 , V_6 ) ;
if ( ! V_8 )
goto V_34;
F_9 ( V_8 -> V_13 , V_2 ) ;
V_31:
return V_8 ;
V_34:
F_12 ( V_2 ) ;
goto V_31;
}
static void F_26 ( struct V_8 * V_8 )
{
#ifdef F_20
if ( F_27 ( F_28 ( & V_8 -> V_29 ) != 0 ) ) {
F_29 ( V_35 L_1 ,
F_28 ( & V_8 -> V_29 ) ) ;
return;
}
#endif
F_12 ( V_8 -> V_13 ) ;
F_30 ( V_33 , V_8 ) ;
}
void F_31 ( void * V_36 )
{
struct V_8 * V_37 = V_36 ;
if ( V_37 && F_32 ( & V_37 -> V_27 ) )
F_26 ( V_37 ) ;
}
struct V_8 * F_33 ( unsigned long V_38 , struct V_8 * V_39 )
{
struct V_8 * V_8 ;
int V_40 ;
if ( ! ( V_38 & V_41 ) )
return F_34 ( V_39 ) ;
V_8 = F_24 () ;
if ( ! V_8 )
return F_35 ( - V_15 ) ;
F_36 ( & V_12 ) ;
V_40 = F_17 ( V_8 ) ;
if ( V_40 == 0 ) {
F_37 () ;
F_38 ( & V_8 -> V_42 , & V_43 ) ;
F_39 () ;
}
F_40 ( & V_12 ) ;
if ( V_40 < 0 ) {
F_31 ( V_8 ) ;
return F_35 ( V_40 ) ;
}
return V_8 ;
}
static void F_41 ( struct V_44 * V_45 )
{
const struct V_17 * V_18 ;
struct V_8 * V_8 , * V_46 ;
F_18 ( V_47 ) ;
F_18 ( V_23 ) ;
F_42 ( & V_48 ) ;
F_43 ( & V_49 , & V_47 ) ;
F_44 ( & V_48 ) ;
F_36 ( & V_12 ) ;
F_37 () ;
F_15 (net, &net_kill_list, cleanup_list) {
F_45 ( & V_8 -> V_42 ) ;
F_46 ( & V_8 -> V_32 , & V_23 ) ;
}
F_39 () ;
F_47 () ;
F_48 (ops, &pernet_list, list)
F_14 ( V_18 , & V_23 ) ;
F_48 (ops, &pernet_list, list)
F_16 ( V_18 , & V_23 ) ;
F_40 ( & V_12 ) ;
F_23 () ;
F_49 (net, tmp, &net_exit_list, exit_list) {
F_50 ( & V_8 -> V_32 ) ;
F_31 ( V_8 ) ;
}
}
void F_51 ( struct V_8 * V_8 )
{
unsigned long V_38 ;
F_52 ( & V_48 , V_38 ) ;
F_21 ( & V_8 -> V_49 , & V_49 ) ;
F_53 ( & V_48 , V_38 ) ;
F_54 ( V_50 , & V_51 ) ;
}
struct V_8 * F_55 ( int V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_55 ;
struct V_8 * V_8 ;
V_55 = F_56 ( V_52 ) ;
if ( F_57 ( V_55 ) )
return F_58 ( V_55 ) ;
V_54 = F_59 ( V_55 -> V_56 -> V_57 ) ;
if ( V_54 -> V_58 == & V_59 )
V_8 = F_34 ( V_54 -> V_37 ) ;
else
V_8 = F_35 ( - V_60 ) ;
F_60 ( V_55 ) ;
return V_8 ;
}
struct V_8 * F_33 ( unsigned long V_38 , struct V_8 * V_39 )
{
if ( V_38 & V_41 )
return F_35 ( - V_60 ) ;
return V_39 ;
}
struct V_8 * F_55 ( int V_52 )
{
return F_35 ( - V_60 ) ;
}
struct V_8 * F_61 ( T_3 V_61 )
{
struct V_62 * V_63 ;
struct V_8 * V_8 ;
V_8 = F_35 ( - V_64 ) ;
F_62 () ;
V_63 = F_63 ( V_61 ) ;
if ( V_63 ) {
struct V_65 * V_65 ;
V_65 = F_64 ( V_63 ) ;
if ( V_65 )
V_8 = F_34 ( V_65 -> V_66 ) ;
}
F_65 () ;
return V_8 ;
}
static int T_4 F_66 ( void )
{
struct V_1 * V_2 ;
#ifdef F_67
V_33 = F_68 ( L_2 , sizeof( struct V_8 ) ,
V_67 ,
V_68 , NULL ) ;
V_50 = F_69 ( L_3 ) ;
if ( ! V_50 )
F_70 ( L_4 ) ;
#endif
V_2 = F_1 () ;
if ( ! V_2 )
F_70 ( L_5 ) ;
F_9 ( V_69 . V_13 , V_2 ) ;
F_36 ( & V_12 ) ;
if ( F_17 ( & V_69 ) )
F_70 ( L_6 ) ;
F_37 () ;
F_38 ( & V_69 . V_42 , & V_43 ) ;
F_39 () ;
F_40 ( & V_12 ) ;
return 0 ;
}
static int F_71 ( struct V_22 * V_42 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 ;
int error ;
F_18 ( V_23 ) ;
F_46 ( & V_18 -> V_42 , V_42 ) ;
if ( V_18 -> V_21 || ( V_18 -> V_9 && V_18 -> V_20 ) ) {
F_72 (net) {
error = F_11 ( V_18 , V_8 ) ;
if ( error )
goto V_30;
F_46 ( & V_8 -> V_32 , & V_23 ) ;
}
}
return 0 ;
V_30:
F_73 ( & V_18 -> V_42 ) ;
F_14 ( V_18 , & V_23 ) ;
F_16 ( V_18 , & V_23 ) ;
return error ;
}
static void F_74 ( struct V_17 * V_18 )
{
struct V_8 * V_8 ;
F_18 ( V_23 ) ;
F_73 ( & V_18 -> V_42 ) ;
F_72 (net)
F_46 ( & V_8 -> V_32 , & V_23 ) ;
F_14 ( V_18 , & V_23 ) ;
F_16 ( V_18 , & V_23 ) ;
}
static int F_71 ( struct V_22 * V_42 ,
struct V_17 * V_18 )
{
int V_19 = 0 ;
V_19 = F_11 ( V_18 , & V_69 ) ;
if ( V_19 )
F_13 ( V_18 , & V_69 ) ;
return V_19 ;
}
static void F_74 ( struct V_17 * V_18 )
{
F_18 ( V_23 ) ;
F_21 ( & V_69 . V_32 , & V_23 ) ;
F_14 ( V_18 , & V_23 ) ;
F_16 ( V_18 , & V_23 ) ;
}
static int F_75 ( struct V_22 * V_42 ,
struct V_17 * V_18 )
{
int error ;
if ( V_18 -> V_9 ) {
V_70:
error = F_76 ( & V_71 , 1 , V_18 -> V_9 ) ;
if ( error < 0 ) {
if ( error == - V_72 ) {
F_77 ( & V_71 , V_6 ) ;
goto V_70;
}
return error ;
}
V_5 = F_78 (unsigned int, max_gen_ptrs, *ops->id) ;
}
error = F_71 ( V_42 , V_18 ) ;
if ( error ) {
F_23 () ;
if ( V_18 -> V_9 )
F_79 ( & V_71 , * V_18 -> V_9 ) ;
}
return error ;
}
static void F_80 ( struct V_17 * V_18 )
{
F_74 ( V_18 ) ;
F_23 () ;
if ( V_18 -> V_9 )
F_79 ( & V_71 , * V_18 -> V_9 ) ;
}
int F_81 ( struct V_17 * V_18 )
{
int error ;
F_36 ( & V_12 ) ;
error = F_75 ( V_73 , V_18 ) ;
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
error = F_75 ( & V_74 , V_18 ) ;
if ( ! error && ( V_73 == & V_74 ) )
V_73 = & V_18 -> V_42 ;
F_40 ( & V_12 ) ;
return error ;
}
void F_84 ( struct V_17 * V_18 )
{
F_36 ( & V_12 ) ;
if ( & V_18 -> V_42 == V_73 )
V_73 = V_73 -> V_75 ;
F_80 ( V_18 ) ;
F_40 ( & V_12 ) ;
}
static void * F_85 ( struct V_62 * V_76 )
{
struct V_8 * V_8 = NULL ;
struct V_65 * V_65 ;
F_62 () ;
V_65 = F_64 ( V_76 ) ;
if ( V_65 )
V_8 = F_34 ( V_65 -> V_66 ) ;
F_65 () ;
return V_8 ;
}
static void F_86 ( void * V_37 )
{
F_87 ( V_37 ) ;
}
static int F_88 ( struct V_65 * V_65 , void * V_37 )
{
F_87 ( V_65 -> V_66 ) ;
V_65 -> V_66 = F_34 ( V_37 ) ;
return 0 ;
}
