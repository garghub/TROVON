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
static int F_12 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_7 * V_7 = V_15 -> V_7 ;
struct V_16 * V_17 ;
int V_18 = 0 ;
if ( V_7 -> V_19 == NULL )
return 0 ;
if ( V_7 -> V_19 == NULL )
goto V_20;
F_13 () ;
for ( V_17 = V_7 -> V_19 ; V_17 != NULL ; V_17 = V_17 -> V_21 ) {
if ( ! ( V_17 -> V_22 & ( V_23 | V_24 ) ) )
continue;
if ( F_14 ( V_17 -> V_25 ) != V_13 )
continue;
F_15 () ;
V_18 = F_16 ( V_15 , V_17 ) ;
if ( V_18 < 0 )
goto V_20;
F_13 () ;
}
F_15 () ;
V_20:
return V_18 ;
}
static int F_17 ( struct V_7 * V_7 , const T_2 * V_26 )
{
struct V_27 * V_28 = F_9 ( V_7 ) ;
struct V_12 * V_13 ;
struct V_29 * V_30 ;
struct V_14 * V_15 ;
unsigned int V_31 ;
int V_32 ;
V_33:
F_18 ( & V_7 -> V_34 ) ;
F_19 (ctx, &nfsi->open_files, list) {
V_15 = V_13 -> V_15 ;
if ( V_15 == NULL )
continue;
if ( ! F_10 ( V_35 , & V_15 -> V_6 ) )
continue;
if ( ! F_20 ( & V_15 -> V_26 , V_26 ) )
continue;
F_21 ( V_13 ) ;
F_22 ( & V_7 -> V_34 ) ;
V_30 = V_15 -> V_36 ;
F_23 ( & V_30 -> V_37 ) ;
V_31 = F_24 ( & V_30 -> V_38 ) ;
V_32 = F_25 ( V_13 , V_15 , V_26 ) ;
if ( ! V_32 )
V_32 = F_12 ( V_13 , V_15 ) ;
if ( ! V_32 && F_26 ( & V_30 -> V_38 , V_31 ) )
V_32 = - V_39 ;
F_27 ( & V_30 -> V_37 ) ;
F_28 ( V_13 ) ;
if ( V_32 != 0 )
return V_32 ;
goto V_33;
}
F_22 ( & V_7 -> V_34 ) ;
return 0 ;
}
void F_29 ( struct V_7 * V_7 , struct V_40 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_40 * V_43 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_18 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL ) {
F_30 ( & V_2 -> V_26 , & V_42 -> V_2 ) ;
V_2 -> type = V_42 -> V_45 ;
V_2 -> V_46 = V_42 -> V_46 ;
V_43 = V_2 -> V_3 ;
V_2 -> V_3 = F_31 ( V_3 ) ;
F_32 ( V_47 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_48 = V_2 -> type ;
F_22 ( & V_2 -> V_44 ) ;
F_2 ( V_43 ) ;
F_11 () ;
} else {
F_22 ( & V_2 -> V_44 ) ;
F_11 () ;
F_33 ( V_7 , V_3 , V_42 ) ;
}
} else {
F_11 () ;
}
}
static int F_34 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_49 )
{
int V_42 = 0 ;
V_42 = F_35 ( V_7 , V_2 -> V_3 , & V_2 -> V_26 , V_49 ) ;
F_1 ( V_2 ) ;
return V_42 ;
}
static struct V_7 * F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_18 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_37 ( V_2 -> V_7 ) ;
F_22 ( & V_2 -> V_44 ) ;
return V_7 ;
}
static struct V_1 *
F_38 ( struct V_27 * V_28 )
{
struct V_1 * V_8 = NULL ;
struct V_1 * V_2 = F_8 ( V_28 -> V_2 ) ;
if ( V_2 == NULL )
goto V_20;
F_18 ( & V_2 -> V_44 ) ;
if ( ! F_39 ( V_11 , & V_2 -> V_6 ) )
V_8 = V_2 ;
F_22 ( & V_2 -> V_44 ) ;
V_20:
return V_8 ;
}
static struct V_1 *
F_40 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_38 ( V_28 ) ;
F_11 () ;
return V_2 ;
}
static void
F_41 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
F_18 ( & V_2 -> V_44 ) ;
F_32 ( V_11 , & V_2 -> V_6 ) ;
F_5 ( V_52 , & V_2 -> V_6 ) ;
F_22 ( & V_2 -> V_44 ) ;
F_5 ( V_53 , & V_51 -> V_54 ) ;
}
static struct V_1 *
F_42 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_1 * V_55 =
F_43 ( V_28 -> V_2 ,
F_44 ( & V_51 -> V_56 ) ) ;
if ( V_55 == NULL || V_2 != V_55 )
return NULL ;
F_18 ( & V_2 -> V_44 ) ;
F_5 ( V_11 , & V_2 -> V_6 ) ;
F_45 ( & V_2 -> V_57 ) ;
V_2 -> V_7 = NULL ;
V_28 -> V_48 = 0 ;
F_46 ( V_28 -> V_2 , NULL ) ;
F_22 ( & V_2 -> V_44 ) ;
return V_2 ;
}
static struct V_1 * F_47 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_50 * V_51 = V_59 -> V_50 ;
F_18 ( & V_51 -> V_56 ) ;
V_2 = F_42 ( V_28 , V_2 , V_51 ) ;
F_22 ( & V_51 -> V_56 ) ;
return V_2 ;
}
static struct V_1 *
F_48 ( struct V_7 * V_7 )
{
struct V_27 * V_28 = F_9 ( V_7 ) ;
struct V_58 * V_59 = F_49 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_40 ( V_28 ) ;
if ( V_2 == NULL )
return NULL ;
return F_47 ( V_28 , V_2 , V_59 ) ;
}
int F_33 ( struct V_7 * V_7 , struct V_40 * V_3 , struct V_41 * V_42 )
{
struct V_58 * V_59 = F_49 ( V_7 ) ;
struct V_50 * V_51 = V_59 -> V_50 ;
struct V_27 * V_28 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_60 ;
struct V_1 * V_61 = NULL ;
int V_18 = 0 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_62 ) ;
if ( V_2 == NULL )
return - V_63 ;
F_30 ( & V_2 -> V_26 , & V_42 -> V_2 ) ;
V_2 -> type = V_42 -> V_45 ;
V_2 -> V_46 = V_42 -> V_46 ;
V_2 -> V_64 = V_7 -> V_65 ;
V_2 -> V_3 = F_31 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_51 ( & V_2 -> V_44 ) ;
F_18 ( & V_51 -> V_56 ) ;
V_60 = F_43 ( V_28 -> V_2 ,
F_44 ( & V_51 -> V_56 ) ) ;
if ( V_60 != NULL ) {
if ( F_20 ( & V_2 -> V_26 ,
& V_60 -> V_26 ) &&
V_2 -> type == V_60 -> type ) {
goto V_20;
}
F_52 ( V_66 , L_1
L_2 ,
V_67 , V_51 -> V_68 ) ;
if ( V_2 -> type == V_60 -> type ||
! ( V_2 -> type & V_10 ) ) {
V_61 = V_2 ;
V_2 = NULL ;
goto V_20;
}
V_61 = F_42 ( V_28 ,
V_60 , V_51 ) ;
if ( V_61 == NULL )
goto V_20;
}
F_53 ( & V_2 -> V_57 , & V_59 -> V_69 ) ;
V_28 -> V_48 = V_2 -> type ;
F_46 ( V_28 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_18 ( & V_7 -> V_34 ) ;
V_28 -> V_70 |= V_71 ;
F_22 ( & V_7 -> V_34 ) ;
V_20:
F_22 ( & V_51 -> V_56 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_61 != NULL )
F_34 ( V_7 , V_61 , 0 ) ;
return V_18 ;
}
static int F_54 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_49 )
{
struct V_50 * V_51 = F_49 ( V_7 ) -> V_50 ;
struct V_27 * V_28 = F_9 ( V_7 ) ;
int V_32 ;
if ( V_2 == NULL )
return 0 ;
do {
V_32 = F_17 ( V_7 , & V_2 -> V_26 ) ;
if ( ! V_49 || V_32 != - V_39 )
break;
V_32 = F_55 ( V_51 ) ;
} while ( V_32 == 0 );
if ( V_32 ) {
F_41 ( V_2 , V_51 ) ;
goto V_20;
}
if ( ! F_47 ( V_28 , V_2 , F_49 ( V_7 ) ) )
goto V_20;
V_32 = F_34 ( V_7 , V_2 , V_49 ) ;
V_20:
return V_32 ;
}
int F_56 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_7 * V_7 ;
int V_32 = 0 ;
V_72:
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link) {
F_57 (delegation, &server->delegations,
super_list) {
if ( ! F_58 ( V_52 ,
& V_2 -> V_6 ) )
continue;
V_7 = F_36 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_38 ( F_9 ( V_7 ) ) ;
F_11 () ;
V_32 = F_54 ( V_7 , V_2 , 0 ) ;
F_59 ( V_7 ) ;
if ( ! V_32 )
goto V_72;
F_5 ( V_53 , & V_51 -> V_54 ) ;
return V_32 ;
}
}
F_11 () ;
return 0 ;
}
void F_60 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_7 ) ;
if ( V_2 != NULL )
F_34 ( V_7 , V_2 , 0 ) ;
}
int F_61 ( struct V_7 * V_7 )
{
struct V_27 * V_28 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_32 = 0 ;
F_62 ( V_7 ) ;
V_2 = F_40 ( V_28 ) ;
if ( V_2 != NULL )
V_32 = F_54 ( V_7 , V_2 , 1 ) ;
return V_32 ;
}
static void F_63 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
F_5 ( V_52 , & V_2 -> V_6 ) ;
F_5 ( V_53 , & V_59 -> V_50 -> V_54 ) ;
}
void F_64 ( struct V_58 * V_59 )
{
struct V_50 * V_51 = V_59 -> V_50 ;
struct V_1 * V_2 ;
if ( V_51 == NULL )
return;
F_7 () ;
F_57 (delegation, &server->delegations, super_list) {
F_18 ( & V_2 -> V_44 ) ;
F_5 ( V_52 , & V_2 -> V_6 ) ;
F_22 ( & V_2 -> V_44 ) ;
}
F_11 () ;
if ( F_56 ( V_51 ) != 0 )
F_65 ( V_51 ) ;
}
static void F_66 ( struct V_58 * V_59 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_57 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_9 | V_10 ) ) && ! ( V_6 & V_10 ) )
continue;
if ( V_2 -> type & V_6 )
F_63 ( V_59 , V_2 ) ;
}
}
static void F_67 ( struct V_50 * V_51 ,
T_1 V_6 )
{
struct V_58 * V_59 ;
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link)
F_66 ( V_59 , V_6 ) ;
F_11 () ;
}
static void F_68 ( struct V_50 * V_51 )
{
if ( F_10 ( V_53 , & V_51 -> V_54 ) )
F_65 ( V_51 ) ;
}
void F_69 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_7 ) ;
if ( V_2 ) {
F_70 ( V_7 , & V_2 -> V_26 ) ;
F_1 ( V_2 ) ;
}
}
void F_71 ( struct V_50 * V_51 , T_1 V_6 )
{
F_67 ( V_51 , V_6 ) ;
F_68 ( V_51 ) ;
}
void F_72 ( struct V_50 * V_51 )
{
F_71 ( V_51 , V_9 | V_10 ) ;
}
static void F_73 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
F_57 (delegation, &server->delegations, super_list) {
if ( F_58 ( V_5 , & V_2 -> V_6 ) )
continue;
F_63 ( V_59 , V_2 ) ;
}
}
void F_74 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link)
F_73 ( V_59 ) ;
F_11 () ;
F_68 ( V_51 ) ;
}
int F_75 ( struct V_7 * V_7 ,
const T_2 * V_26 )
{
struct V_58 * V_59 = F_49 ( V_7 ) ;
struct V_50 * V_51 = V_59 -> V_50 ;
struct V_1 * V_2 ;
F_76 ( V_7 -> V_73 ) ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( ! V_51 -> V_74 -> V_75 ( & V_2 -> V_26 , V_26 ) ) {
F_11 () ;
return - V_76 ;
}
F_63 ( V_59 , V_2 ) ;
F_11 () ;
F_68 ( V_51 ) ;
return 0 ;
}
static struct V_7 *
F_77 ( struct V_58 * V_59 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_7 * V_42 = NULL ;
F_57 (delegation, &server->delegations, super_list) {
F_18 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_7 != NULL &&
F_78 ( V_78 , & F_9 ( V_2 -> V_7 ) -> V_79 ) == 0 ) {
V_42 = F_37 ( V_2 -> V_7 ) ;
}
F_22 ( & V_2 -> V_44 ) ;
if ( V_42 != NULL )
break;
}
return V_42 ;
}
struct V_7 * F_79 ( struct V_50 * V_51 ,
const struct V_77 * V_78 )
{
struct V_58 * V_59 ;
struct V_7 * V_42 = NULL ;
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link) {
V_42 = F_77 ( V_59 , V_78 ) ;
if ( V_42 != NULL )
break;
}
F_11 () ;
return V_42 ;
}
static void F_80 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
F_57 (delegation, &server->delegations, super_list)
F_5 ( V_47 , & V_2 -> V_6 ) ;
}
void F_81 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link)
F_80 ( V_59 ) ;
F_11 () ;
}
void F_82 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_7 * V_7 ;
V_72:
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link) {
F_57 (delegation, &server->delegations,
super_list) {
if ( F_10 ( V_47 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_36 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_47 ( F_9 ( V_7 ) ,
V_2 , V_59 ) ;
F_11 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_59 ( V_7 ) ;
goto V_72;
}
}
F_11 () ;
}
int F_83 ( struct V_50 * V_51 )
{
struct V_58 * V_59 ;
int V_8 = 0 ;
F_7 () ;
F_57 (server, &clp->cl_superblocks, client_link)
if ( ! F_84 ( & V_59 -> V_69 ) ) {
V_8 = 1 ;
break;
}
F_11 () ;
return V_8 ;
}
bool F_85 ( T_2 * V_80 , struct V_7 * V_7 ,
T_1 V_6 )
{
struct V_27 * V_28 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_8 ;
V_6 &= V_9 | V_10 ;
F_7 () ;
V_2 = F_8 ( V_28 -> V_2 ) ;
V_8 = ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) ;
if ( V_8 ) {
F_30 ( V_80 , & V_2 -> V_26 ) ;
F_4 ( V_2 ) ;
}
F_11 () ;
return V_8 ;
}
