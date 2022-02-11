static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
F_3 ( V_2 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_5 , & V_2 -> V_6 ) ;
}
static int
F_6 ( struct V_7 * V_7 , T_1 V_6 , bool V_8 )
{
struct V_1 * V_2 ;
int V_9 = 0 ;
V_6 &= V_10 | V_11 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 &&
! F_10 ( V_12 , & V_2 -> V_6 ) ) {
if ( V_8 )
F_4 ( V_2 ) ;
V_9 = 1 ;
}
F_11 () ;
return V_9 ;
}
int F_12 ( struct V_7 * V_7 , T_1 V_6 )
{
return F_6 ( V_7 , V_6 , true ) ;
}
int F_13 ( struct V_7 * V_7 , T_1 V_6 )
{
return F_6 ( V_7 , V_6 , false ) ;
}
static int F_14 ( struct V_13 * V_14 , struct V_15 * V_16 , const T_2 * V_17 )
{
struct V_7 * V_7 = V_16 -> V_7 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( V_7 -> V_21 == NULL )
goto V_22;
F_15 ( & V_7 -> V_23 ) ;
for ( V_19 = V_7 -> V_21 ; V_19 != NULL ; V_19 = V_19 -> V_24 ) {
if ( ! ( V_19 -> V_25 & ( V_26 | V_27 ) ) )
continue;
if ( F_16 ( V_19 -> V_28 ) != V_14 )
continue;
F_17 ( & V_7 -> V_23 ) ;
V_20 = F_18 ( V_19 , V_16 , V_17 ) ;
if ( V_20 < 0 )
goto V_22;
F_15 ( & V_7 -> V_23 ) ;
}
F_17 ( & V_7 -> V_23 ) ;
V_22:
return V_20 ;
}
static int F_19 ( struct V_7 * V_7 , const T_2 * V_17 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_13 * V_14 ;
struct V_31 * V_32 ;
struct V_15 * V_16 ;
unsigned int V_33 ;
int V_34 ;
V_35:
F_15 ( & V_7 -> V_23 ) ;
F_20 (ctx, &nfsi->open_files, list) {
V_16 = V_14 -> V_16 ;
if ( V_16 == NULL )
continue;
if ( ! F_10 ( V_36 , & V_16 -> V_6 ) )
continue;
if ( ! F_21 ( & V_16 -> V_17 , V_17 ) )
continue;
F_22 ( V_14 ) ;
F_17 ( & V_7 -> V_23 ) ;
V_32 = V_16 -> V_37 ;
F_23 ( & V_32 -> V_38 ) ;
V_33 = F_24 ( & V_32 -> V_39 ) ;
V_34 = F_25 ( V_14 , V_16 , V_17 ) ;
if ( ! V_34 )
V_34 = F_14 ( V_14 , V_16 , V_17 ) ;
if ( ! V_34 && F_26 ( & V_32 -> V_39 , V_33 ) )
V_34 = - V_40 ;
F_27 ( & V_32 -> V_38 ) ;
F_28 ( V_14 ) ;
if ( V_34 != 0 )
return V_34 ;
goto V_35;
}
F_17 ( & V_7 -> V_23 ) ;
return 0 ;
}
void F_29 ( struct V_7 * V_7 , struct V_41 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_41 * V_44 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL ) {
F_30 ( & V_2 -> V_17 , & V_43 -> V_2 ) ;
V_2 -> type = V_43 -> V_46 ;
V_2 -> V_47 = V_43 -> V_47 ;
V_44 = V_2 -> V_3 ;
V_2 -> V_3 = F_31 ( V_3 ) ;
F_32 ( V_48 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_49 = V_2 -> type ;
F_17 ( & V_2 -> V_45 ) ;
F_2 ( V_44 ) ;
F_11 () ;
F_33 ( V_7 , V_43 -> V_46 ) ;
} else {
F_17 ( & V_2 -> V_45 ) ;
F_11 () ;
F_34 ( V_7 , V_3 , V_43 ) ;
}
} else {
F_11 () ;
}
}
static int F_35 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_50 )
{
int V_43 = 0 ;
V_43 = F_36 ( V_7 , V_2 -> V_3 , & V_2 -> V_17 , V_50 ) ;
F_1 ( V_2 ) ;
return V_43 ;
}
static struct V_7 * F_37 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_38 ( V_2 -> V_7 ) ;
F_17 ( & V_2 -> V_45 ) ;
return V_7 ;
}
static struct V_1 *
F_39 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = NULL ;
struct V_1 * V_2 = F_8 ( V_30 -> V_2 ) ;
if ( V_2 == NULL )
goto V_22;
F_15 ( & V_2 -> V_45 ) ;
if ( ! F_40 ( V_12 , & V_2 -> V_6 ) )
V_9 = V_2 ;
F_17 ( & V_2 -> V_45 ) ;
V_22:
return V_9 ;
}
static struct V_1 *
F_41 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_39 ( V_30 ) ;
F_11 () ;
return V_2 ;
}
static void
F_42 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
F_15 ( & V_2 -> V_45 ) ;
F_32 ( V_12 , & V_2 -> V_6 ) ;
F_5 ( V_53 , & V_2 -> V_6 ) ;
F_17 ( & V_2 -> V_45 ) ;
F_5 ( V_54 , & V_52 -> V_55 ) ;
}
static struct V_1 *
F_43 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_1 * V_56 =
F_44 ( V_30 -> V_2 ,
F_45 ( & V_52 -> V_57 ) ) ;
if ( V_56 == NULL || V_2 != V_56 )
return NULL ;
F_15 ( & V_2 -> V_45 ) ;
F_5 ( V_12 , & V_2 -> V_6 ) ;
F_46 ( & V_2 -> V_58 ) ;
V_2 -> V_7 = NULL ;
V_30 -> V_49 = 0 ;
F_47 ( V_30 -> V_2 , NULL ) ;
F_17 ( & V_2 -> V_45 ) ;
return V_2 ;
}
static struct V_1 * F_48 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_51 * V_52 = V_60 -> V_51 ;
F_15 ( & V_52 -> V_57 ) ;
V_2 = F_43 ( V_30 , V_2 , V_52 ) ;
F_17 ( & V_52 -> V_57 ) ;
return V_2 ;
}
static struct V_1 *
F_49 ( struct V_7 * V_7 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_59 * V_60 = F_50 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_30 ) ;
if ( V_2 == NULL )
return NULL ;
return F_48 ( V_30 , V_2 , V_60 ) ;
}
int F_34 ( struct V_7 * V_7 , struct V_41 * V_3 , struct V_42 * V_43 )
{
struct V_59 * V_60 = F_50 ( V_7 ) ;
struct V_51 * V_52 = V_60 -> V_51 ;
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_61 ;
struct V_1 * V_62 = NULL ;
int V_20 = 0 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_63 ) ;
if ( V_2 == NULL )
return - V_64 ;
F_30 ( & V_2 -> V_17 , & V_43 -> V_2 ) ;
V_2 -> type = V_43 -> V_46 ;
V_2 -> V_47 = V_43 -> V_47 ;
V_2 -> V_65 = V_7 -> V_66 ;
V_2 -> V_3 = F_31 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_52 ( & V_2 -> V_45 ) ;
F_15 ( & V_52 -> V_57 ) ;
V_61 = F_44 ( V_30 -> V_2 ,
F_45 ( & V_52 -> V_57 ) ) ;
if ( V_61 != NULL ) {
if ( F_21 ( & V_2 -> V_17 ,
& V_61 -> V_17 ) &&
V_2 -> type == V_61 -> type ) {
goto V_22;
}
F_53 ( V_67 , L_1
L_2 ,
V_68 , V_52 -> V_69 ) ;
if ( V_2 -> type == V_61 -> type ||
! ( V_2 -> type & V_11 ) ) {
V_62 = V_2 ;
V_2 = NULL ;
goto V_22;
}
V_62 = F_43 ( V_30 ,
V_61 , V_52 ) ;
if ( V_62 == NULL )
goto V_22;
}
F_54 ( & V_2 -> V_58 , & V_60 -> V_70 ) ;
V_30 -> V_49 = V_2 -> type ;
F_47 ( V_30 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_15 ( & V_7 -> V_23 ) ;
V_30 -> V_71 |= V_72 ;
F_17 ( & V_7 -> V_23 ) ;
F_55 ( V_7 , V_43 -> V_46 ) ;
V_22:
F_17 ( & V_52 -> V_57 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_62 != NULL )
F_35 ( V_7 , V_62 , 0 ) ;
return V_20 ;
}
static int F_56 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_50 )
{
struct V_51 * V_52 = F_50 ( V_7 ) -> V_51 ;
struct V_29 * V_30 = F_9 ( V_7 ) ;
int V_34 ;
if ( V_2 == NULL )
return 0 ;
do {
V_34 = F_19 ( V_7 , & V_2 -> V_17 ) ;
if ( ! V_50 || V_34 != - V_40 )
break;
V_34 = F_57 ( V_52 ) ;
} while ( V_34 == 0 );
if ( V_34 ) {
F_42 ( V_2 , V_52 ) ;
goto V_22;
}
if ( ! F_48 ( V_30 , V_2 , F_50 ( V_7 ) ) )
goto V_22;
V_34 = F_35 ( V_7 , V_2 , V_50 ) ;
V_22:
return V_34 ;
}
static bool F_58 ( struct V_1 * V_2 )
{
bool V_9 = false ;
if ( F_59 ( V_53 , & V_2 -> V_6 ) )
V_9 = true ;
if ( F_59 ( V_73 , & V_2 -> V_6 ) && ! V_9 ) {
struct V_7 * V_7 ;
F_15 ( & V_2 -> V_45 ) ;
V_7 = V_2 -> V_7 ;
if ( V_7 && F_60 ( & F_9 ( V_7 ) -> V_74 ) )
V_9 = true ;
F_17 ( & V_2 -> V_45 ) ;
}
return V_9 ;
}
int F_61 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_7 * V_7 ;
int V_34 = 0 ;
V_75:
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link) {
F_62 (delegation, &server->delegations,
super_list) {
if ( ! F_58 ( V_2 ) )
continue;
V_7 = F_37 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_39 ( F_9 ( V_7 ) ) ;
F_11 () ;
V_34 = F_56 ( V_7 , V_2 , 0 ) ;
F_63 ( V_7 ) ;
if ( ! V_34 )
goto V_75;
F_5 ( V_54 , & V_52 -> V_55 ) ;
return V_34 ;
}
}
F_11 () ;
return 0 ;
}
void F_64 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_49 ( V_7 ) ;
if ( V_2 != NULL )
F_35 ( V_7 , V_2 , 0 ) ;
}
int F_65 ( struct V_7 * V_7 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_34 = 0 ;
F_66 ( V_7 ) ;
V_2 = F_41 ( V_30 ) ;
if ( V_2 != NULL )
V_34 = F_56 ( V_7 , V_2 , 1 ) ;
return V_34 ;
}
static void F_67 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
F_5 ( V_73 , & V_2 -> V_6 ) ;
F_5 ( V_54 , & V_60 -> V_51 -> V_55 ) ;
}
static void F_68 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
F_5 ( V_53 , & V_2 -> V_6 ) ;
F_5 ( V_54 , & V_60 -> V_51 -> V_55 ) ;
}
static bool F_69 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
bool V_9 = false ;
F_62 (delegation, &server->delegations, super_list) {
F_68 ( V_60 , V_2 ) ;
V_9 = true ;
}
return V_9 ;
}
static void F_70 ( struct V_51 * V_52 )
{
struct V_59 * V_60 ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link)
F_69 ( V_60 ) ;
F_11 () ;
}
static void F_71 ( struct V_51 * V_52 )
{
if ( F_10 ( V_54 , & V_52 -> V_55 ) )
F_72 ( V_52 ) ;
}
void F_73 ( struct V_51 * V_52 )
{
F_70 ( V_52 ) ;
F_71 ( V_52 ) ;
}
void F_74 ( struct V_59 * V_60 )
{
struct V_51 * V_52 = V_60 -> V_51 ;
bool V_76 ;
if ( V_52 == NULL )
return;
F_7 () ;
V_76 = F_69 ( V_60 ) ;
F_11 () ;
if ( V_76 ) {
F_72 ( V_52 ) ;
F_57 ( V_52 ) ;
}
}
static void F_75 ( struct V_59 * V_60 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_62 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_10 | V_11 ) ) && ! ( V_6 & V_11 ) )
continue;
if ( V_2 -> type & V_6 )
F_67 ( V_60 , V_2 ) ;
}
}
static void F_76 ( struct V_51 * V_52 ,
T_1 V_6 )
{
struct V_59 * V_60 ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link)
F_75 ( V_60 , V_6 ) ;
F_11 () ;
}
void F_77 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_49 ( V_7 ) ;
if ( V_2 ) {
F_78 ( V_7 , & V_2 -> V_17 ) ;
F_1 ( V_2 ) ;
}
}
void F_79 ( struct V_51 * V_52 , T_1 V_6 )
{
F_76 ( V_52 , V_6 ) ;
F_71 ( V_52 ) ;
}
static void F_80 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
F_62 (delegation, &server->delegations, super_list) {
if ( F_59 ( V_5 , & V_2 -> V_6 ) )
continue;
F_67 ( V_60 , V_2 ) ;
}
}
void F_81 ( struct V_51 * V_52 )
{
struct V_59 * V_60 ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link)
F_80 ( V_60 ) ;
F_11 () ;
F_71 ( V_52 ) ;
}
int F_82 ( struct V_7 * V_7 ,
const T_2 * V_17 )
{
struct V_59 * V_60 = F_50 ( V_7 ) ;
struct V_51 * V_52 = V_60 -> V_51 ;
struct V_1 * V_2 ;
F_83 ( V_7 -> V_77 ) ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 == NULL )
goto V_78;
if ( ! V_52 -> V_79 -> V_80 ( & V_2 -> V_17 , V_17 ) )
goto V_78;
F_68 ( V_60 , V_2 ) ;
F_11 () ;
F_71 ( V_52 ) ;
return 0 ;
V_78:
F_11 () ;
return - V_81 ;
}
static struct V_7 *
F_84 ( struct V_59 * V_60 ,
const struct V_82 * V_83 )
{
struct V_1 * V_2 ;
struct V_7 * V_43 = NULL ;
F_62 (delegation, &server->delegations, super_list) {
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL &&
F_85 ( V_83 , & F_9 ( V_2 -> V_7 ) -> V_84 ) == 0 ) {
V_43 = F_38 ( V_2 -> V_7 ) ;
}
F_17 ( & V_2 -> V_45 ) ;
if ( V_43 != NULL )
break;
}
return V_43 ;
}
struct V_7 * F_86 ( struct V_51 * V_52 ,
const struct V_82 * V_83 )
{
struct V_59 * V_60 ;
struct V_7 * V_43 = NULL ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link) {
V_43 = F_84 ( V_60 , V_83 ) ;
if ( V_43 != NULL )
break;
}
F_11 () ;
return V_43 ;
}
static void F_87 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
F_62 (delegation, &server->delegations, super_list)
F_5 ( V_48 , & V_2 -> V_6 ) ;
}
void F_88 ( struct V_51 * V_52 )
{
struct V_59 * V_60 ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link)
F_87 ( V_60 ) ;
F_11 () ;
}
void F_89 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_7 * V_7 ;
V_75:
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link) {
F_62 (delegation, &server->delegations,
super_list) {
if ( F_10 ( V_48 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_37 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_48 ( F_9 ( V_7 ) ,
V_2 , V_60 ) ;
F_11 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_63 ( V_7 ) ;
goto V_75;
}
}
F_11 () ;
}
int F_90 ( struct V_51 * V_52 )
{
struct V_59 * V_60 ;
int V_9 = 0 ;
F_7 () ;
F_62 (server, &clp->cl_superblocks, client_link)
if ( ! F_60 ( & V_60 -> V_70 ) ) {
V_9 = 1 ;
break;
}
F_11 () ;
return V_9 ;
}
bool F_91 ( T_2 * V_85 , struct V_7 * V_7 ,
T_1 V_6 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_9 ;
V_6 &= V_10 | V_11 ;
F_7 () ;
V_2 = F_8 ( V_30 -> V_2 ) ;
V_9 = ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) ;
if ( V_9 ) {
F_30 ( V_85 , & V_2 -> V_17 ) ;
F_4 ( V_2 ) ;
}
F_11 () ;
return V_9 ;
}
