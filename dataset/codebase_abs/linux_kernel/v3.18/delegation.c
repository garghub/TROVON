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
if ( ! F_21 ( V_16 ) )
continue;
if ( ! F_22 ( & V_16 -> V_17 , V_17 ) )
continue;
F_23 ( V_14 ) ;
F_17 ( & V_7 -> V_23 ) ;
V_32 = V_16 -> V_37 ;
F_24 ( & V_32 -> V_38 ) ;
V_33 = F_25 ( & V_32 -> V_39 ) ;
V_34 = F_26 ( V_14 , V_16 , V_17 ) ;
if ( ! V_34 )
V_34 = F_14 ( V_14 , V_16 , V_17 ) ;
if ( ! V_34 && F_27 ( & V_32 -> V_39 , V_33 ) )
V_34 = - V_40 ;
F_28 ( & V_32 -> V_38 ) ;
F_29 ( V_14 ) ;
if ( V_34 != 0 )
return V_34 ;
goto V_35;
}
F_17 ( & V_7 -> V_23 ) ;
return 0 ;
}
void F_30 ( struct V_7 * V_7 , struct V_41 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_41 * V_44 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL ) {
F_31 ( & V_2 -> V_17 , & V_43 -> V_2 ) ;
V_2 -> type = V_43 -> V_46 ;
V_2 -> V_47 = V_43 -> V_47 ;
V_44 = V_2 -> V_3 ;
V_2 -> V_3 = F_32 ( V_3 ) ;
F_33 ( V_48 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_49 = V_2 -> type ;
F_17 ( & V_2 -> V_45 ) ;
F_2 ( V_44 ) ;
F_11 () ;
F_34 ( V_7 , V_43 -> V_46 ) ;
} else {
F_17 ( & V_2 -> V_45 ) ;
F_11 () ;
F_35 ( V_7 , V_3 , V_43 ) ;
}
} else {
F_11 () ;
}
}
static int F_36 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_50 )
{
int V_43 = 0 ;
if ( ! F_10 ( V_51 , & V_2 -> V_6 ) )
V_43 = F_37 ( V_7 ,
V_2 -> V_3 ,
& V_2 -> V_17 ,
V_50 ) ;
F_1 ( V_2 ) ;
return V_43 ;
}
static struct V_7 * F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_39 ( V_2 -> V_7 ) ;
F_17 ( & V_2 -> V_45 ) ;
return V_7 ;
}
static struct V_1 *
F_40 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = NULL ;
struct V_1 * V_2 = F_8 ( V_30 -> V_2 ) ;
if ( V_2 == NULL )
goto V_22;
F_15 ( & V_2 -> V_45 ) ;
if ( ! F_41 ( V_12 , & V_2 -> V_6 ) )
V_9 = V_2 ;
F_17 ( & V_2 -> V_45 ) ;
V_22:
return V_9 ;
}
static struct V_1 *
F_42 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_40 ( V_30 ) ;
F_11 () ;
return V_2 ;
}
static void
F_43 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
F_15 ( & V_2 -> V_45 ) ;
F_33 ( V_12 , & V_2 -> V_6 ) ;
F_5 ( V_54 , & V_2 -> V_6 ) ;
F_17 ( & V_2 -> V_45 ) ;
F_5 ( V_55 , & V_53 -> V_56 ) ;
}
static struct V_1 *
F_44 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_1 * V_57 =
F_45 ( V_30 -> V_2 ,
F_46 ( & V_53 -> V_58 ) ) ;
if ( V_57 == NULL || V_2 != V_57 )
return NULL ;
F_15 ( & V_2 -> V_45 ) ;
F_5 ( V_12 , & V_2 -> V_6 ) ;
F_47 ( & V_2 -> V_59 ) ;
V_2 -> V_7 = NULL ;
V_30 -> V_49 = 0 ;
F_48 ( V_30 -> V_2 , NULL ) ;
F_17 ( & V_2 -> V_45 ) ;
return V_2 ;
}
static struct V_1 * F_49 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_52 * V_53 = V_61 -> V_52 ;
F_15 ( & V_53 -> V_58 ) ;
V_2 = F_44 ( V_30 , V_2 , V_53 ) ;
F_17 ( & V_53 -> V_58 ) ;
return V_2 ;
}
static struct V_1 *
F_50 ( struct V_7 * V_7 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_60 * V_61 = F_51 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_42 ( V_30 ) ;
if ( V_2 == NULL )
return NULL ;
return F_49 ( V_30 , V_2 , V_61 ) ;
}
int F_35 ( struct V_7 * V_7 , struct V_41 * V_3 , struct V_42 * V_43 )
{
struct V_60 * V_61 = F_51 ( V_7 ) ;
struct V_52 * V_53 = V_61 -> V_52 ;
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_62 ;
struct V_1 * V_63 = NULL ;
int V_20 = 0 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_65 ;
F_31 ( & V_2 -> V_17 , & V_43 -> V_2 ) ;
V_2 -> type = V_43 -> V_46 ;
V_2 -> V_47 = V_43 -> V_47 ;
V_2 -> V_66 = V_7 -> V_67 ;
V_2 -> V_3 = F_32 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_53 ( & V_2 -> V_45 ) ;
F_15 ( & V_53 -> V_58 ) ;
V_62 = F_45 ( V_30 -> V_2 ,
F_46 ( & V_53 -> V_58 ) ) ;
if ( V_62 != NULL ) {
if ( F_22 ( & V_2 -> V_17 ,
& V_62 -> V_17 ) &&
V_2 -> type == V_62 -> type ) {
goto V_22;
}
F_54 ( V_68 , L_1
L_2 ,
V_69 , V_53 -> V_70 ) ;
if ( V_2 -> type == V_62 -> type ||
! ( V_2 -> type & V_11 ) ) {
V_63 = V_2 ;
V_2 = NULL ;
goto V_22;
}
V_63 = F_44 ( V_30 ,
V_62 , V_53 ) ;
if ( V_63 == NULL )
goto V_22;
}
F_55 ( & V_2 -> V_59 , & V_61 -> V_71 ) ;
V_30 -> V_49 = V_2 -> type ;
F_48 ( V_30 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_15 ( & V_7 -> V_23 ) ;
V_30 -> V_72 |= V_73 ;
F_17 ( & V_7 -> V_23 ) ;
F_56 ( V_7 , V_43 -> V_46 ) ;
V_22:
F_17 ( & V_53 -> V_58 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_63 != NULL )
F_36 ( V_7 , V_63 , 0 ) ;
return V_20 ;
}
static int F_57 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_50 )
{
struct V_52 * V_53 = F_51 ( V_7 ) -> V_52 ;
struct V_29 * V_30 = F_9 ( V_7 ) ;
int V_34 = 0 ;
if ( V_2 == NULL )
return 0 ;
do {
if ( F_10 ( V_51 , & V_2 -> V_6 ) )
break;
V_34 = F_19 ( V_7 , & V_2 -> V_17 ) ;
if ( ! V_50 || V_34 != - V_40 )
break;
V_34 = F_58 ( V_53 ) ;
} while ( V_34 == 0 );
if ( V_34 ) {
F_43 ( V_2 , V_53 ) ;
goto V_22;
}
if ( ! F_49 ( V_30 , V_2 , F_51 ( V_7 ) ) )
goto V_22;
V_34 = F_36 ( V_7 , V_2 , V_50 ) ;
V_22:
return V_34 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
bool V_9 = false ;
if ( F_60 ( V_54 , & V_2 -> V_6 ) )
V_9 = true ;
if ( F_60 ( V_74 , & V_2 -> V_6 ) && ! V_9 ) {
struct V_7 * V_7 ;
F_15 ( & V_2 -> V_45 ) ;
V_7 = V_2 -> V_7 ;
if ( V_7 && F_61 ( & F_9 ( V_7 ) -> V_75 ) )
V_9 = true ;
F_17 ( & V_2 -> V_45 ) ;
}
return V_9 ;
}
int F_62 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_7 * V_7 ;
int V_34 = 0 ;
V_76:
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link) {
F_63 (delegation, &server->delegations,
super_list) {
if ( ! F_59 ( V_2 ) )
continue;
V_7 = F_38 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_40 ( F_9 ( V_7 ) ) ;
F_11 () ;
V_34 = F_57 ( V_7 , V_2 , 0 ) ;
F_64 ( V_7 ) ;
if ( ! V_34 )
goto V_76;
F_5 ( V_55 , & V_53 -> V_56 ) ;
return V_34 ;
}
}
F_11 () ;
return 0 ;
}
void F_65 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_50 ( V_7 ) ;
if ( V_2 != NULL )
F_36 ( V_7 , V_2 , 0 ) ;
}
int F_66 ( struct V_7 * V_7 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_34 = 0 ;
F_67 ( V_7 ) ;
V_2 = F_42 ( V_30 ) ;
if ( V_2 != NULL )
V_34 = F_57 ( V_7 , V_2 , 1 ) ;
return V_34 ;
}
static void F_68 ( struct V_60 * V_61 ,
struct V_1 * V_2 )
{
F_5 ( V_74 , & V_2 -> V_6 ) ;
F_5 ( V_55 , & V_61 -> V_52 -> V_56 ) ;
}
static void F_69 ( struct V_60 * V_61 ,
struct V_1 * V_2 )
{
F_5 ( V_54 , & V_2 -> V_6 ) ;
F_5 ( V_55 , & V_61 -> V_52 -> V_56 ) ;
}
static bool F_70 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
bool V_9 = false ;
F_63 (delegation, &server->delegations, super_list) {
F_69 ( V_61 , V_2 ) ;
V_9 = true ;
}
return V_9 ;
}
static void F_71 ( struct V_52 * V_53 )
{
struct V_60 * V_61 ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link)
F_70 ( V_61 ) ;
F_11 () ;
}
static void F_72 ( struct V_52 * V_53 )
{
if ( F_10 ( V_55 , & V_53 -> V_56 ) )
F_73 ( V_53 ) ;
}
void F_74 ( struct V_52 * V_53 )
{
F_71 ( V_53 ) ;
F_72 ( V_53 ) ;
}
void F_75 ( struct V_60 * V_61 )
{
struct V_52 * V_53 = V_61 -> V_52 ;
bool V_77 ;
if ( V_53 == NULL )
return;
F_7 () ;
V_77 = F_70 ( V_61 ) ;
F_11 () ;
if ( V_77 ) {
F_73 ( V_53 ) ;
F_58 ( V_53 ) ;
}
}
static void F_76 ( struct V_60 * V_61 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_63 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_10 | V_11 ) ) && ! ( V_6 & V_11 ) )
continue;
if ( V_2 -> type & V_6 )
F_68 ( V_61 , V_2 ) ;
}
}
static void F_77 ( struct V_52 * V_53 ,
T_1 V_6 )
{
struct V_60 * V_61 ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link)
F_76 ( V_61 , V_6 ) ;
F_11 () ;
}
static void F_78 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_5 ( V_51 , & V_2 -> V_6 ) ;
F_69 ( F_51 ( V_7 ) , V_2 ) ;
}
F_11 () ;
}
void F_79 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
F_78 ( V_7 ) ;
V_2 = F_50 ( V_7 ) ;
if ( V_2 ) {
F_80 ( V_7 , & V_2 -> V_17 ) ;
F_1 ( V_2 ) ;
}
}
void F_81 ( struct V_52 * V_53 , T_1 V_6 )
{
F_77 ( V_53 , V_6 ) ;
F_72 ( V_53 ) ;
}
static void F_82 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
F_63 (delegation, &server->delegations, super_list) {
if ( F_60 ( V_5 , & V_2 -> V_6 ) )
continue;
F_68 ( V_61 , V_2 ) ;
}
}
void F_83 ( struct V_52 * V_53 )
{
struct V_60 * V_61 ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link)
F_82 ( V_61 ) ;
F_11 () ;
F_72 ( V_53 ) ;
}
int F_84 ( struct V_7 * V_7 ,
const T_2 * V_17 )
{
struct V_60 * V_61 = F_51 ( V_7 ) ;
struct V_52 * V_53 = V_61 -> V_52 ;
struct V_1 * V_2 ;
F_85 ( V_7 -> V_78 ) ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 == NULL )
goto V_79;
if ( ! V_53 -> V_80 -> V_81 ( & V_2 -> V_17 , V_17 ) )
goto V_79;
F_69 ( V_61 , V_2 ) ;
F_11 () ;
F_72 ( V_53 ) ;
return 0 ;
V_79:
F_11 () ;
return - V_82 ;
}
static struct V_7 *
F_86 ( struct V_60 * V_61 ,
const struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_7 * V_43 = NULL ;
F_63 (delegation, &server->delegations, super_list) {
F_15 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 != NULL &&
F_87 ( V_84 , & F_9 ( V_2 -> V_7 ) -> V_85 ) == 0 ) {
V_43 = F_39 ( V_2 -> V_7 ) ;
}
F_17 ( & V_2 -> V_45 ) ;
if ( V_43 != NULL )
break;
}
return V_43 ;
}
struct V_7 * F_88 ( struct V_52 * V_53 ,
const struct V_83 * V_84 )
{
struct V_60 * V_61 ;
struct V_7 * V_43 = NULL ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link) {
V_43 = F_86 ( V_61 , V_84 ) ;
if ( V_43 != NULL )
break;
}
F_11 () ;
return V_43 ;
}
static void F_89 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
F_63 (delegation, &server->delegations, super_list)
F_5 ( V_48 , & V_2 -> V_6 ) ;
}
void F_90 ( struct V_52 * V_53 )
{
struct V_60 * V_61 ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link)
F_89 ( V_61 ) ;
F_11 () ;
}
void F_91 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_7 * V_7 ;
V_76:
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link) {
F_63 (delegation, &server->delegations,
super_list) {
if ( F_10 ( V_48 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_38 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_49 ( F_9 ( V_7 ) ,
V_2 , V_61 ) ;
F_11 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_64 ( V_7 ) ;
goto V_76;
}
}
F_11 () ;
}
int F_92 ( struct V_52 * V_53 )
{
struct V_60 * V_61 ;
int V_9 = 0 ;
F_7 () ;
F_63 (server, &clp->cl_superblocks, client_link)
if ( ! F_61 ( & V_61 -> V_71 ) ) {
V_9 = 1 ;
break;
}
F_11 () ;
return V_9 ;
}
bool F_93 ( T_2 * V_86 , struct V_7 * V_7 ,
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
F_31 ( V_86 , & V_2 -> V_17 ) ;
F_4 ( V_2 ) ;
}
F_11 () ;
return V_9 ;
}
