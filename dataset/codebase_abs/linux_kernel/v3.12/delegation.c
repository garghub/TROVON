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
int F_6 ( struct V_7 * V_7 , T_1 V_6 )
{
struct V_1 * V_2 ;
int V_8 = 0 ;
V_6 &= V_9 | V_10 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 &&
! F_10 ( V_11 , & V_2 -> V_6 ) ) {
F_4 ( V_2 ) ;
V_8 = 1 ;
}
F_11 () ;
return V_8 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_14 * V_15 , const T_2 * V_16 )
{
struct V_7 * V_7 = V_15 -> V_7 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
if ( V_7 -> V_20 == NULL )
goto V_21;
F_13 ( & V_7 -> V_22 ) ;
for ( V_18 = V_7 -> V_20 ; V_18 != NULL ; V_18 = V_18 -> V_23 ) {
if ( ! ( V_18 -> V_24 & ( V_25 | V_26 ) ) )
continue;
if ( F_14 ( V_18 -> V_27 ) != V_13 )
continue;
F_15 ( & V_7 -> V_22 ) ;
V_19 = F_16 ( V_18 , V_15 , V_16 ) ;
if ( V_19 < 0 )
goto V_21;
F_13 ( & V_7 -> V_22 ) ;
}
F_15 ( & V_7 -> V_22 ) ;
V_21:
return V_19 ;
}
static int F_17 ( struct V_7 * V_7 , const T_2 * V_16 )
{
struct V_28 * V_29 = F_9 ( V_7 ) ;
struct V_12 * V_13 ;
struct V_30 * V_31 ;
struct V_14 * V_15 ;
unsigned int V_32 ;
int V_33 ;
V_34:
F_13 ( & V_7 -> V_22 ) ;
F_18 (ctx, &nfsi->open_files, list) {
V_15 = V_13 -> V_15 ;
if ( V_15 == NULL )
continue;
if ( ! F_10 ( V_35 , & V_15 -> V_6 ) )
continue;
if ( ! F_19 ( & V_15 -> V_16 , V_16 ) )
continue;
F_20 ( V_13 ) ;
F_15 ( & V_7 -> V_22 ) ;
V_31 = V_15 -> V_36 ;
F_21 ( & V_31 -> V_37 ) ;
V_32 = F_22 ( & V_31 -> V_38 ) ;
V_33 = F_23 ( V_13 , V_15 , V_16 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_13 , V_15 , V_16 ) ;
if ( ! V_33 && F_24 ( & V_31 -> V_38 , V_32 ) )
V_33 = - V_39 ;
F_25 ( & V_31 -> V_37 ) ;
F_26 ( V_13 ) ;
if ( V_33 != 0 )
return V_33 ;
goto V_34;
}
F_15 ( & V_7 -> V_22 ) ;
return 0 ;
}
void F_27 ( struct V_7 * V_7 , struct V_40 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_40 * V_43 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_13 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL ) {
F_28 ( & V_2 -> V_16 , & V_42 -> V_2 ) ;
V_2 -> type = V_42 -> V_45 ;
V_2 -> V_46 = V_42 -> V_46 ;
V_43 = V_2 -> V_3 ;
V_2 -> V_3 = F_29 ( V_3 ) ;
F_30 ( V_47 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_48 = V_2 -> type ;
F_15 ( & V_2 -> V_44 ) ;
F_2 ( V_43 ) ;
F_11 () ;
F_31 ( V_7 , V_42 -> V_45 ) ;
} else {
F_15 ( & V_2 -> V_44 ) ;
F_11 () ;
F_32 ( V_7 , V_3 , V_42 ) ;
}
} else {
F_11 () ;
}
}
static int F_33 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_49 )
{
int V_42 = 0 ;
V_42 = F_34 ( V_7 , V_2 -> V_3 , & V_2 -> V_16 , V_49 ) ;
F_1 ( V_2 ) ;
return V_42 ;
}
static struct V_7 * F_35 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_13 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_36 ( V_2 -> V_7 ) ;
F_15 ( & V_2 -> V_44 ) ;
return V_7 ;
}
static struct V_1 *
F_37 ( struct V_28 * V_29 )
{
struct V_1 * V_8 = NULL ;
struct V_1 * V_2 = F_8 ( V_29 -> V_2 ) ;
if ( V_2 == NULL )
goto V_21;
F_13 ( & V_2 -> V_44 ) ;
if ( ! F_38 ( V_11 , & V_2 -> V_6 ) )
V_8 = V_2 ;
F_15 ( & V_2 -> V_44 ) ;
V_21:
return V_8 ;
}
static struct V_1 *
F_39 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_37 ( V_29 ) ;
F_11 () ;
return V_2 ;
}
static void
F_40 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
F_13 ( & V_2 -> V_44 ) ;
F_30 ( V_11 , & V_2 -> V_6 ) ;
F_5 ( V_52 , & V_2 -> V_6 ) ;
F_15 ( & V_2 -> V_44 ) ;
F_5 ( V_53 , & V_51 -> V_54 ) ;
}
static struct V_1 *
F_41 ( struct V_28 * V_29 ,
struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_1 * V_55 =
F_42 ( V_29 -> V_2 ,
F_43 ( & V_51 -> V_56 ) ) ;
if ( V_55 == NULL || V_2 != V_55 )
return NULL ;
F_13 ( & V_2 -> V_44 ) ;
F_5 ( V_11 , & V_2 -> V_6 ) ;
F_44 ( & V_2 -> V_57 ) ;
V_2 -> V_7 = NULL ;
V_29 -> V_48 = 0 ;
F_45 ( V_29 -> V_2 , NULL ) ;
F_15 ( & V_2 -> V_44 ) ;
return V_2 ;
}
static struct V_1 * F_46 ( struct V_28 * V_29 ,
struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_50 * V_51 = V_59 -> V_50 ;
F_13 ( & V_51 -> V_56 ) ;
V_2 = F_41 ( V_29 , V_2 , V_51 ) ;
F_15 ( & V_51 -> V_56 ) ;
return V_2 ;
}
static struct V_1 *
F_47 ( struct V_7 * V_7 )
{
struct V_28 * V_29 = F_9 ( V_7 ) ;
struct V_58 * V_59 = F_48 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_39 ( V_29 ) ;
if ( V_2 == NULL )
return NULL ;
return F_46 ( V_29 , V_2 , V_59 ) ;
}
int F_32 ( struct V_7 * V_7 , struct V_40 * V_3 , struct V_41 * V_42 )
{
struct V_58 * V_59 = F_48 ( V_7 ) ;
struct V_50 * V_51 = V_59 -> V_50 ;
struct V_28 * V_29 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_60 ;
struct V_1 * V_61 = NULL ;
int V_19 = 0 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_62 ) ;
if ( V_2 == NULL )
return - V_63 ;
F_28 ( & V_2 -> V_16 , & V_42 -> V_2 ) ;
V_2 -> type = V_42 -> V_45 ;
V_2 -> V_46 = V_42 -> V_46 ;
V_2 -> V_64 = V_7 -> V_65 ;
V_2 -> V_3 = F_29 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_50 ( & V_2 -> V_44 ) ;
F_13 ( & V_51 -> V_56 ) ;
V_60 = F_42 ( V_29 -> V_2 ,
F_43 ( & V_51 -> V_56 ) ) ;
if ( V_60 != NULL ) {
if ( F_19 ( & V_2 -> V_16 ,
& V_60 -> V_16 ) &&
V_2 -> type == V_60 -> type ) {
goto V_21;
}
F_51 ( V_66 , L_1
L_2 ,
V_67 , V_51 -> V_68 ) ;
if ( V_2 -> type == V_60 -> type ||
! ( V_2 -> type & V_10 ) ) {
V_61 = V_2 ;
V_2 = NULL ;
goto V_21;
}
V_61 = F_41 ( V_29 ,
V_60 , V_51 ) ;
if ( V_61 == NULL )
goto V_21;
}
F_52 ( & V_2 -> V_57 , & V_59 -> V_69 ) ;
V_29 -> V_48 = V_2 -> type ;
F_45 ( V_29 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_13 ( & V_7 -> V_22 ) ;
V_29 -> V_70 |= V_71 ;
F_15 ( & V_7 -> V_22 ) ;
F_53 ( V_7 , V_42 -> V_45 ) ;
V_21:
F_15 ( & V_51 -> V_56 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_61 != NULL )
F_33 ( V_7 , V_61 , 0 ) ;
return V_19 ;
}
static int F_54 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_49 )
{
struct V_50 * V_51 = F_48 ( V_7 ) -> V_50 ;
struct V_28 * V_29 = F_9 ( V_7 ) ;
int V_33 ;
if ( V_2 == NULL )
return 0 ;
do {
V_33 = F_17 ( V_7 , & V_2 -> V_16 ) ;
if ( ! V_49 || V_33 != - V_39 )
break;
V_33 = F_55 ( V_51 ) ;
} while ( V_33 == 0 );
if ( V_33 ) {
F_40 ( V_2 , V_51 ) ;
goto V_21;
}
if ( ! F_46 ( V_29 , V_2 , F_48 ( V_7 ) ) )
goto V_21;
V_33 = F_33 ( V_7 , V_2 , V_49 ) ;
V_21:
return V_33 ;
}
static bool F_56 ( struct V_1 * V_2 )
{
bool V_8 = false ;
if ( F_57 ( V_52 , & V_2 -> V_6 ) )
V_8 = true ;
if ( F_57 ( V_72 , & V_2 -> V_6 ) && ! V_8 ) {
struct V_7 * V_7 ;
F_13 ( & V_2 -> V_44 ) ;
V_7 = V_2 -> V_7 ;
if ( V_7 && F_58 ( & F_9 ( V_7 ) -> V_73 ) )
V_8 = true ;
F_15 ( & V_2 -> V_44 ) ;
}
return V_8 ;
}
int F_59 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_7 * V_7 ;
int V_33 = 0 ;
V_74:
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link) {
F_60 (delegation, &server->delegations,
super_list) {
if ( ! F_56 ( V_2 ) )
continue;
V_7 = F_35 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_37 ( F_9 ( V_7 ) ) ;
F_11 () ;
V_33 = F_54 ( V_7 , V_2 , 0 ) ;
F_61 ( V_7 ) ;
if ( ! V_33 )
goto V_74;
F_5 ( V_53 , & V_51 -> V_54 ) ;
return V_33 ;
}
}
F_11 () ;
return 0 ;
}
void F_62 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_47 ( V_7 ) ;
if ( V_2 != NULL )
F_33 ( V_7 , V_2 , 0 ) ;
}
int F_63 ( struct V_7 * V_7 )
{
struct V_28 * V_29 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_33 = 0 ;
F_64 ( V_7 ) ;
V_2 = F_39 ( V_29 ) ;
if ( V_2 != NULL )
V_33 = F_54 ( V_7 , V_2 , 1 ) ;
return V_33 ;
}
static void F_65 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
F_5 ( V_72 , & V_2 -> V_6 ) ;
F_5 ( V_53 , & V_59 -> V_50 -> V_54 ) ;
}
static void F_66 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
F_5 ( V_52 , & V_2 -> V_6 ) ;
F_5 ( V_53 , & V_59 -> V_50 -> V_54 ) ;
}
static bool F_67 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
bool V_8 = false ;
F_60 (delegation, &server->delegations, super_list) {
F_66 ( V_59 , V_2 ) ;
V_8 = true ;
}
return V_8 ;
}
static void F_68 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link)
F_67 ( V_59 ) ;
F_11 () ;
}
static void F_69 ( struct V_50 * V_51 )
{
if ( F_10 ( V_53 , & V_51 -> V_54 ) )
F_70 ( V_51 ) ;
}
void F_71 ( struct V_50 * V_51 )
{
F_68 ( V_51 ) ;
F_69 ( V_51 ) ;
}
void F_72 ( struct V_58 * V_59 )
{
struct V_50 * V_51 = V_59 -> V_50 ;
bool V_75 ;
if ( V_51 == NULL )
return;
F_7 () ;
V_75 = F_67 ( V_59 ) ;
F_11 () ;
if ( V_75 ) {
F_70 ( V_51 ) ;
F_55 ( V_51 ) ;
}
}
static void F_73 ( struct V_58 * V_59 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_60 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_9 | V_10 ) ) && ! ( V_6 & V_10 ) )
continue;
if ( V_2 -> type & V_6 )
F_65 ( V_59 , V_2 ) ;
}
}
static void F_74 ( struct V_50 * V_51 ,
T_1 V_6 )
{
struct V_58 * V_59 ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link)
F_73 ( V_59 , V_6 ) ;
F_11 () ;
}
void F_75 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_47 ( V_7 ) ;
if ( V_2 ) {
F_76 ( V_7 , & V_2 -> V_16 ) ;
F_1 ( V_2 ) ;
}
}
void F_77 ( struct V_50 * V_51 , T_1 V_6 )
{
F_74 ( V_51 , V_6 ) ;
F_69 ( V_51 ) ;
}
static void F_78 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
F_60 (delegation, &server->delegations, super_list) {
if ( F_57 ( V_5 , & V_2 -> V_6 ) )
continue;
F_65 ( V_59 , V_2 ) ;
}
}
void F_79 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link)
F_78 ( V_59 ) ;
F_11 () ;
F_69 ( V_51 ) ;
}
int F_80 ( struct V_7 * V_7 ,
const T_2 * V_16 )
{
struct V_58 * V_59 = F_48 ( V_7 ) ;
struct V_50 * V_51 = V_59 -> V_50 ;
struct V_1 * V_2 ;
F_81 ( V_7 -> V_76 ) ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( ! V_51 -> V_77 -> V_78 ( & V_2 -> V_16 , V_16 ) ) {
F_11 () ;
return - V_79 ;
}
F_66 ( V_59 , V_2 ) ;
F_11 () ;
F_69 ( V_51 ) ;
return 0 ;
}
static struct V_7 *
F_82 ( struct V_58 * V_59 ,
const struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_7 * V_42 = NULL ;
F_60 (delegation, &server->delegations, super_list) {
F_13 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL &&
F_83 ( V_81 , & F_9 ( V_2 -> V_7 ) -> V_82 ) == 0 ) {
V_42 = F_36 ( V_2 -> V_7 ) ;
}
F_15 ( & V_2 -> V_44 ) ;
if ( V_42 != NULL )
break;
}
return V_42 ;
}
struct V_7 * F_84 ( struct V_50 * V_51 ,
const struct V_80 * V_81 )
{
struct V_58 * V_59 ;
struct V_7 * V_42 = NULL ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link) {
V_42 = F_82 ( V_59 , V_81 ) ;
if ( V_42 != NULL )
break;
}
F_11 () ;
return V_42 ;
}
static void F_85 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
F_60 (delegation, &server->delegations, super_list)
F_5 ( V_47 , & V_2 -> V_6 ) ;
}
void F_86 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link)
F_85 ( V_59 ) ;
F_11 () ;
}
void F_87 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_7 * V_7 ;
V_74:
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link) {
F_60 (delegation, &server->delegations,
super_list) {
if ( F_10 ( V_47 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_35 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_46 ( F_9 ( V_7 ) ,
V_2 , V_59 ) ;
F_11 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_61 ( V_7 ) ;
goto V_74;
}
}
F_11 () ;
}
int F_88 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
int V_8 = 0 ;
F_7 () ;
F_60 (server, &clp->cl_superblocks, client_link)
if ( ! F_58 ( & V_59 -> V_69 ) ) {
V_8 = 1 ;
break;
}
F_11 () ;
return V_8 ;
}
bool F_89 ( T_2 * V_83 , struct V_7 * V_7 ,
T_1 V_6 )
{
struct V_28 * V_29 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_8 ;
V_6 &= V_9 | V_10 ;
F_7 () ;
V_2 = F_8 ( V_29 -> V_2 ) ;
V_8 = ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) ;
if ( V_8 ) {
F_28 ( V_83 , & V_2 -> V_16 ) ;
F_4 ( V_2 ) ;
}
F_11 () ;
return V_8 ;
}
