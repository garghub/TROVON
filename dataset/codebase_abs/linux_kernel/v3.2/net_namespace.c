static int F_1 ( struct V_1 * V_1 , int V_2 , void * V_3 )
{
struct V_4 * V_5 , * V_6 ;
F_2 ( ! F_3 ( & V_7 ) ) ;
F_2 ( V_2 == 0 ) ;
V_6 = F_4 ( V_1 -> V_8 ,
F_5 ( & V_7 ) ) ;
V_5 = V_6 ;
if ( V_6 -> V_9 >= V_2 )
goto V_10;
V_5 = F_6 ( sizeof( struct V_4 ) +
V_2 * sizeof( void * ) , V_11 ) ;
if ( V_5 == NULL )
return - V_12 ;
V_5 -> V_9 = V_2 ;
memcpy ( & V_5 -> V_13 , & V_6 -> V_13 , V_6 -> V_9 * sizeof( void * ) ) ;
F_7 ( V_1 -> V_8 , V_5 ) ;
F_8 ( V_6 , V_14 ) ;
V_10:
V_5 -> V_13 [ V_2 - 1 ] = V_3 ;
return 0 ;
}
static int F_9 ( const struct V_15 * V_16 , struct V_1 * V_1 )
{
int V_17 ;
if ( V_16 -> V_2 && V_16 -> V_18 ) {
void * V_3 = F_6 ( V_16 -> V_18 , V_11 ) ;
if ( ! V_3 )
return - V_12 ;
V_17 = F_1 ( V_1 , * V_16 -> V_2 , V_3 ) ;
if ( V_17 ) {
F_10 ( V_3 ) ;
return V_17 ;
}
}
if ( V_16 -> V_19 )
return V_16 -> V_19 ( V_1 ) ;
return 0 ;
}
static void F_11 ( const struct V_15 * V_16 , struct V_1 * V_1 )
{
if ( V_16 -> V_2 && V_16 -> V_18 ) {
int V_2 = * V_16 -> V_2 ;
F_10 ( V_4 ( V_1 , V_2 ) ) ;
}
}
static void F_12 ( const struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 ;
if ( V_16 -> exit ) {
F_13 (net, net_exit_list, exit_list)
V_16 -> exit ( V_1 ) ;
}
if ( V_16 -> V_22 )
V_16 -> V_22 ( V_21 ) ;
}
static void F_14 ( const struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 ;
if ( V_16 -> V_18 && V_16 -> V_2 ) {
F_13 (net, net_exit_list, exit_list)
F_11 ( V_16 , V_1 ) ;
}
}
static T_1 int F_15 ( struct V_1 * V_1 )
{
const struct V_15 * V_16 , * V_23 ;
int error = 0 ;
F_16 ( V_21 ) ;
F_17 ( & V_1 -> V_24 , 1 ) ;
F_17 ( & V_1 -> V_25 , 1 ) ;
V_1 -> V_26 = 1 ;
#ifdef F_18
F_17 ( & V_1 -> V_27 , 0 ) ;
#endif
F_13 (ops, &pernet_list, list) {
error = F_9 ( V_16 , V_1 ) ;
if ( error < 0 )
goto V_28;
}
V_29:
return error ;
V_28:
F_19 ( & V_1 -> V_30 , & V_21 ) ;
V_23 = V_16 ;
F_20 (ops, &pernet_list, list)
F_12 ( V_16 , & V_21 ) ;
V_16 = V_23 ;
F_20 (ops, &pernet_list, list)
F_14 ( V_16 , & V_21 ) ;
F_21 () ;
goto V_29;
}
static struct V_4 * F_22 ( void )
{
struct V_4 * V_5 ;
T_2 V_31 = sizeof( struct V_4 ) +
V_32 * sizeof( void * ) ;
V_5 = F_6 ( V_31 , V_11 ) ;
if ( V_5 )
V_5 -> V_9 = V_32 ;
return V_5 ;
}
static struct V_1 * F_23 ( void )
{
struct V_1 * V_1 = NULL ;
struct V_4 * V_5 ;
V_5 = F_22 () ;
if ( ! V_5 )
goto V_29;
V_1 = F_24 ( V_33 , V_11 ) ;
if ( ! V_1 )
goto V_34;
F_7 ( V_1 -> V_8 , V_5 ) ;
V_29:
return V_1 ;
V_34:
F_10 ( V_5 ) ;
goto V_29;
}
static void F_25 ( struct V_1 * V_1 )
{
#ifdef F_18
if ( F_26 ( F_27 ( & V_1 -> V_27 ) != 0 ) ) {
F_28 ( V_35 L_1 ,
F_27 ( & V_1 -> V_27 ) ) ;
return;
}
#endif
F_10 ( V_1 -> V_8 ) ;
F_29 ( V_33 , V_1 ) ;
}
void F_30 ( void * V_36 )
{
struct V_1 * V_37 = V_36 ;
if ( V_37 && F_31 ( & V_37 -> V_25 ) )
F_25 ( V_37 ) ;
}
struct V_1 * F_32 ( unsigned long V_38 , struct V_1 * V_39 )
{
struct V_1 * V_1 ;
int V_40 ;
if ( ! ( V_38 & V_41 ) )
return F_33 ( V_39 ) ;
V_1 = F_23 () ;
if ( ! V_1 )
return F_34 ( - V_12 ) ;
F_35 ( & V_7 ) ;
V_40 = F_15 ( V_1 ) ;
if ( V_40 == 0 ) {
F_36 () ;
F_37 ( & V_1 -> V_42 , & V_43 ) ;
F_38 () ;
}
F_39 ( & V_7 ) ;
if ( V_40 < 0 ) {
F_30 ( V_1 ) ;
return F_34 ( V_40 ) ;
}
return V_1 ;
}
static void F_40 ( struct V_44 * V_45 )
{
const struct V_15 * V_16 ;
struct V_1 * V_1 , * V_46 ;
F_16 ( V_47 ) ;
F_16 ( V_21 ) ;
F_41 ( & V_48 ) ;
F_42 ( & V_49 , & V_47 ) ;
F_43 ( & V_48 ) ;
F_35 ( & V_7 ) ;
F_36 () ;
F_13 (net, &net_kill_list, cleanup_list) {
F_44 ( & V_1 -> V_42 ) ;
F_45 ( & V_1 -> V_30 , & V_21 ) ;
}
F_38 () ;
F_46 () ;
F_47 (ops, &pernet_list, list)
F_12 ( V_16 , & V_21 ) ;
F_47 (ops, &pernet_list, list)
F_14 ( V_16 , & V_21 ) ;
F_39 ( & V_7 ) ;
F_21 () ;
F_48 (net, tmp, &net_exit_list, exit_list) {
F_49 ( & V_1 -> V_30 ) ;
F_30 ( V_1 ) ;
}
}
void F_50 ( struct V_1 * V_1 )
{
unsigned long V_38 ;
F_51 ( & V_48 , V_38 ) ;
F_19 ( & V_1 -> V_49 , & V_49 ) ;
F_52 ( & V_48 , V_38 ) ;
F_53 ( V_50 , & V_51 ) ;
}
struct V_1 * F_54 ( int V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_55 ;
struct V_1 * V_1 ;
V_55 = F_55 ( V_52 ) ;
if ( F_56 ( V_55 ) )
return F_57 ( V_55 ) ;
V_54 = F_58 ( V_55 -> V_56 -> V_57 ) ;
if ( V_54 -> V_58 == & V_59 )
V_1 = F_33 ( V_54 -> V_37 ) ;
else
V_1 = F_34 ( - V_60 ) ;
F_59 ( V_55 ) ;
return V_1 ;
}
struct V_1 * F_32 ( unsigned long V_38 , struct V_1 * V_39 )
{
if ( V_38 & V_41 )
return F_34 ( - V_60 ) ;
return V_39 ;
}
struct V_1 * F_54 ( int V_52 )
{
return F_34 ( - V_60 ) ;
}
struct V_1 * F_60 ( T_3 V_61 )
{
struct V_62 * V_63 ;
struct V_1 * V_1 ;
V_1 = F_34 ( - V_64 ) ;
F_61 () ;
V_63 = F_62 ( V_61 ) ;
if ( V_63 ) {
struct V_65 * V_65 ;
V_65 = F_63 ( V_63 ) ;
if ( V_65 )
V_1 = F_33 ( V_65 -> V_66 ) ;
}
F_64 () ;
return V_1 ;
}
static int T_4 F_65 ( void )
{
struct V_4 * V_5 ;
#ifdef F_66
V_33 = F_67 ( L_2 , sizeof( struct V_1 ) ,
V_67 ,
V_68 , NULL ) ;
V_50 = F_68 ( L_3 ) ;
if ( ! V_50 )
F_69 ( L_4 ) ;
#endif
V_5 = F_22 () ;
if ( ! V_5 )
F_69 ( L_5 ) ;
F_7 ( V_69 . V_8 , V_5 ) ;
F_35 ( & V_7 ) ;
if ( F_15 ( & V_69 ) )
F_69 ( L_6 ) ;
F_36 () ;
F_37 ( & V_69 . V_42 , & V_43 ) ;
F_38 () ;
F_39 ( & V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_20 * V_42 ,
struct V_15 * V_16 )
{
struct V_1 * V_1 ;
int error ;
F_16 ( V_21 ) ;
F_45 ( & V_16 -> V_42 , V_42 ) ;
if ( V_16 -> V_19 || ( V_16 -> V_2 && V_16 -> V_18 ) ) {
F_71 (net) {
error = F_9 ( V_16 , V_1 ) ;
if ( error )
goto V_28;
F_45 ( & V_1 -> V_30 , & V_21 ) ;
}
}
return 0 ;
V_28:
F_72 ( & V_16 -> V_42 ) ;
F_12 ( V_16 , & V_21 ) ;
F_14 ( V_16 , & V_21 ) ;
return error ;
}
static void F_73 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
F_16 ( V_21 ) ;
F_72 ( & V_16 -> V_42 ) ;
F_71 (net)
F_45 ( & V_1 -> V_30 , & V_21 ) ;
F_12 ( V_16 , & V_21 ) ;
F_14 ( V_16 , & V_21 ) ;
}
static int F_70 ( struct V_20 * V_42 ,
struct V_15 * V_16 )
{
int V_17 = 0 ;
V_17 = F_9 ( V_16 , & V_69 ) ;
if ( V_17 )
F_11 ( V_16 , & V_69 ) ;
return V_17 ;
}
static void F_73 ( struct V_15 * V_16 )
{
F_16 ( V_21 ) ;
F_19 ( & V_69 . V_30 , & V_21 ) ;
F_12 ( V_16 , & V_21 ) ;
F_14 ( V_16 , & V_21 ) ;
}
static int F_74 ( struct V_20 * V_42 ,
struct V_15 * V_16 )
{
int error ;
if ( V_16 -> V_2 ) {
V_70:
error = F_75 ( & V_71 , 1 , V_16 -> V_2 ) ;
if ( error < 0 ) {
if ( error == - V_72 ) {
F_76 ( & V_71 , V_11 ) ;
goto V_70;
}
return error ;
}
}
error = F_70 ( V_42 , V_16 ) ;
if ( error ) {
F_21 () ;
if ( V_16 -> V_2 )
F_77 ( & V_71 , * V_16 -> V_2 ) ;
}
return error ;
}
static void F_78 ( struct V_15 * V_16 )
{
F_73 ( V_16 ) ;
F_21 () ;
if ( V_16 -> V_2 )
F_77 ( & V_71 , * V_16 -> V_2 ) ;
}
int F_79 ( struct V_15 * V_16 )
{
int error ;
F_35 ( & V_7 ) ;
error = F_74 ( V_73 , V_16 ) ;
F_39 ( & V_7 ) ;
return error ;
}
void F_80 ( struct V_15 * V_16 )
{
F_35 ( & V_7 ) ;
F_78 ( V_16 ) ;
F_39 ( & V_7 ) ;
}
int F_81 ( struct V_15 * V_16 )
{
int error ;
F_35 ( & V_7 ) ;
error = F_74 ( & V_74 , V_16 ) ;
if ( ! error && ( V_73 == & V_74 ) )
V_73 = & V_16 -> V_42 ;
F_39 ( & V_7 ) ;
return error ;
}
void F_82 ( struct V_15 * V_16 )
{
F_35 ( & V_7 ) ;
if ( & V_16 -> V_42 == V_73 )
V_73 = V_73 -> V_75 ;
F_78 ( V_16 ) ;
F_39 ( & V_7 ) ;
}
static void * F_83 ( struct V_62 * V_76 )
{
struct V_1 * V_1 = NULL ;
struct V_65 * V_65 ;
F_61 () ;
V_65 = F_63 ( V_76 ) ;
if ( V_65 )
V_1 = F_33 ( V_65 -> V_66 ) ;
F_64 () ;
return V_1 ;
}
static void F_84 ( void * V_37 )
{
F_85 ( V_37 ) ;
}
static int F_86 ( struct V_65 * V_65 , void * V_37 )
{
F_85 ( V_65 -> V_66 ) ;
V_65 -> V_66 = F_33 ( V_37 ) ;
return 0 ;
}
