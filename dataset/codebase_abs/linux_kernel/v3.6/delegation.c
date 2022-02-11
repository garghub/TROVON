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
if ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) {
F_4 ( V_2 ) ;
V_8 = 1 ;
}
F_10 () ;
return V_8 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_7 * V_7 = V_14 -> V_7 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
if ( V_7 -> V_18 == NULL )
goto V_19;
F_12 () ;
for ( V_16 = V_7 -> V_18 ; V_16 != NULL ; V_16 = V_16 -> V_20 ) {
if ( ! ( V_16 -> V_21 & ( V_22 | V_23 ) ) )
continue;
if ( F_13 ( V_16 -> V_24 ) != V_12 )
continue;
F_14 () ;
V_17 = F_15 ( V_14 , V_16 ) ;
if ( V_17 < 0 )
goto V_19;
F_12 () ;
}
F_14 () ;
V_19:
return V_17 ;
}
static int F_16 ( struct V_7 * V_7 , const T_2 * V_25 )
{
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_28 ;
V_29:
F_17 ( & V_7 -> V_30 ) ;
F_18 (ctx, &nfsi->open_files, list) {
V_14 = V_12 -> V_14 ;
if ( V_14 == NULL )
continue;
if ( ! F_19 ( V_31 , & V_14 -> V_6 ) )
continue;
if ( ! F_20 ( & V_14 -> V_25 , V_25 ) )
continue;
F_21 ( V_12 ) ;
F_22 ( & V_7 -> V_30 ) ;
V_28 = F_23 ( V_12 , V_14 , V_25 ) ;
if ( V_28 >= 0 )
V_28 = F_11 ( V_12 , V_14 ) ;
F_24 ( V_12 ) ;
if ( V_28 != 0 )
return V_28 ;
goto V_29;
}
F_22 ( & V_7 -> V_30 ) ;
return 0 ;
}
void F_25 ( struct V_7 * V_7 , struct V_32 * V_3 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_32 * V_35 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_17 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_7 != NULL ) {
F_26 ( & V_2 -> V_25 , & V_34 -> V_2 ) ;
V_2 -> type = V_34 -> V_37 ;
V_2 -> V_38 = V_34 -> V_38 ;
V_35 = V_2 -> V_3 ;
V_2 -> V_3 = F_27 ( V_3 ) ;
F_28 ( V_39 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_40 = V_2 -> type ;
F_22 ( & V_2 -> V_36 ) ;
F_2 ( V_35 ) ;
F_10 () ;
} else {
F_22 ( & V_2 -> V_36 ) ;
F_10 () ;
F_29 ( V_7 , V_3 , V_34 ) ;
}
} else {
F_10 () ;
}
}
static int F_30 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_41 )
{
int V_34 = 0 ;
V_34 = F_31 ( V_7 , V_2 -> V_3 , & V_2 -> V_25 , V_41 ) ;
F_1 ( V_2 ) ;
return V_34 ;
}
static struct V_7 * F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_17 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_33 ( V_2 -> V_7 ) ;
F_22 ( & V_2 -> V_36 ) ;
return V_7 ;
}
static struct V_1 *
F_34 ( struct V_26 * V_27 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 =
F_35 ( V_27 -> V_2 ,
F_36 ( & V_43 -> V_44 -> V_45 ) ) ;
if ( V_2 == NULL )
goto V_46;
F_17 ( & V_2 -> V_36 ) ;
F_37 ( & V_2 -> V_47 ) ;
V_2 -> V_7 = NULL ;
V_27 -> V_40 = 0 ;
F_38 ( V_27 -> V_2 , NULL ) ;
F_22 ( & V_2 -> V_36 ) ;
return V_2 ;
V_46:
return NULL ;
}
static struct V_1 * F_39 ( struct V_26 * V_27 ,
struct V_42 * V_43 )
{
struct V_44 * V_48 = V_43 -> V_44 ;
struct V_1 * V_2 ;
F_17 ( & V_48 -> V_45 ) ;
V_2 = F_34 ( V_27 , V_43 ) ;
F_22 ( & V_48 -> V_45 ) ;
return V_2 ;
}
int F_29 ( struct V_7 * V_7 , struct V_32 * V_3 , struct V_33 * V_34 )
{
struct V_42 * V_43 = F_40 ( V_7 ) ;
struct V_44 * V_48 = V_43 -> V_44 ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_49 ;
struct V_1 * V_50 = NULL ;
int V_17 = 0 ;
V_2 = F_41 ( sizeof( * V_2 ) , V_51 ) ;
if ( V_2 == NULL )
return - V_52 ;
F_26 ( & V_2 -> V_25 , & V_34 -> V_2 ) ;
V_2 -> type = V_34 -> V_37 ;
V_2 -> V_38 = V_34 -> V_38 ;
V_2 -> V_53 = V_7 -> V_54 ;
V_2 -> V_3 = F_27 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_42 ( & V_2 -> V_36 ) ;
F_17 ( & V_48 -> V_45 ) ;
V_49 = F_35 ( V_27 -> V_2 ,
F_36 ( & V_48 -> V_45 ) ) ;
if ( V_49 != NULL ) {
if ( F_20 ( & V_2 -> V_25 ,
& V_49 -> V_25 ) &&
V_2 -> type == V_49 -> type ) {
goto V_19;
}
F_43 ( V_55 , L_1
L_2 ,
V_56 , V_48 -> V_57 ) ;
if ( V_2 -> type == V_49 -> type ||
! ( V_2 -> type & V_10 ) ) {
V_50 = V_2 ;
V_2 = NULL ;
goto V_19;
}
V_50 = F_34 ( V_27 , V_43 ) ;
}
F_44 ( & V_2 -> V_47 , & V_43 -> V_58 ) ;
V_27 -> V_40 = V_2 -> type ;
F_38 ( V_27 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_17 ( & V_7 -> V_30 ) ;
V_27 -> V_59 |= V_60 ;
F_22 ( & V_7 -> V_30 ) ;
V_19:
F_22 ( & V_48 -> V_45 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_50 != NULL )
F_30 ( V_7 , V_50 , 0 ) ;
return V_17 ;
}
static int F_45 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_41 )
{
struct V_26 * V_27 = F_9 ( V_7 ) ;
int V_28 ;
F_46 ( & V_27 -> V_61 ) ;
V_28 = F_16 ( V_7 , & V_2 -> V_25 ) ;
F_47 ( & V_27 -> V_61 ) ;
if ( V_28 )
goto V_19;
V_28 = F_30 ( V_7 , V_2 , V_41 ) ;
V_19:
return V_28 ;
}
int F_48 ( struct V_44 * V_48 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_7 * V_7 ;
int V_28 = 0 ;
V_62:
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link) {
F_49 (delegation, &server->delegations,
super_list) {
if ( ! F_50 ( V_63 ,
& V_2 -> V_6 ) )
continue;
V_7 = F_32 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_39 ( F_9 ( V_7 ) ,
V_43 ) ;
F_10 () ;
if ( V_2 != NULL )
V_28 = F_45 ( V_7 ,
V_2 , 0 ) ;
F_51 ( V_7 ) ;
if ( ! V_28 )
goto V_62;
F_5 ( V_64 , & V_48 -> V_65 ) ;
return V_28 ;
}
}
F_10 () ;
return 0 ;
}
void F_52 ( struct V_7 * V_7 )
{
struct V_42 * V_43 = F_40 ( V_7 ) ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
if ( F_53 ( V_27 -> V_2 ) != NULL ) {
V_2 = F_39 ( V_27 , V_43 ) ;
if ( V_2 != NULL )
F_30 ( V_7 , V_2 , 0 ) ;
}
}
int F_54 ( struct V_7 * V_7 )
{
struct V_42 * V_43 = F_40 ( V_7 ) ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_28 = 0 ;
F_55 ( V_7 ) ;
if ( F_53 ( V_27 -> V_2 ) != NULL ) {
V_2 = F_39 ( V_27 , V_43 ) ;
if ( V_2 != NULL ) {
V_28 = F_45 ( V_7 , V_2 , 1 ) ;
}
}
return V_28 ;
}
static void F_56 ( struct V_42 * V_43 ,
struct V_1 * V_2 )
{
F_5 ( V_63 , & V_2 -> V_6 ) ;
F_5 ( V_64 , & V_43 -> V_44 -> V_65 ) ;
}
void F_57 ( struct V_42 * V_43 )
{
struct V_44 * V_48 = V_43 -> V_44 ;
struct V_1 * V_2 ;
if ( V_48 == NULL )
return;
F_7 () ;
F_49 (delegation, &server->delegations, super_list) {
F_17 ( & V_2 -> V_36 ) ;
F_5 ( V_63 , & V_2 -> V_6 ) ;
F_22 ( & V_2 -> V_36 ) ;
}
F_10 () ;
if ( F_48 ( V_48 ) != 0 )
F_58 ( V_48 ) ;
}
static void F_59 ( struct V_42 * V_43 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_49 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_9 | V_10 ) ) && ! ( V_6 & V_10 ) )
continue;
if ( V_2 -> type & V_6 )
F_56 ( V_43 , V_2 ) ;
}
}
static void F_60 ( struct V_44 * V_48 ,
T_1 V_6 )
{
struct V_42 * V_43 ;
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link)
F_59 ( V_43 , V_6 ) ;
F_10 () ;
}
static void F_61 ( struct V_44 * V_48 )
{
if ( F_19 ( V_64 , & V_48 -> V_65 ) )
F_58 ( V_48 ) ;
}
void F_62 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( F_9 ( V_7 ) , F_40 ( V_7 ) ) ;
if ( V_2 ) {
F_63 ( V_7 , & V_2 -> V_25 ) ;
F_1 ( V_2 ) ;
}
}
void F_64 ( struct V_44 * V_48 , T_1 V_6 )
{
F_60 ( V_48 , V_6 ) ;
F_61 ( V_48 ) ;
}
void F_65 ( struct V_44 * V_48 )
{
F_64 ( V_48 , V_9 | V_10 ) ;
}
static void F_66 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
F_49 (delegation, &server->delegations, super_list) {
if ( F_50 ( V_5 , & V_2 -> V_6 ) )
continue;
F_56 ( V_43 , V_2 ) ;
}
}
void F_67 ( struct V_44 * V_48 )
{
struct V_42 * V_43 ;
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link)
F_66 ( V_43 ) ;
F_10 () ;
F_61 ( V_48 ) ;
}
int F_68 ( struct V_7 * V_7 ,
const T_2 * V_25 )
{
struct V_42 * V_43 = F_40 ( V_7 ) ;
struct V_44 * V_48 = V_43 -> V_44 ;
struct V_1 * V_2 ;
F_69 ( V_7 -> V_66 ) ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( ! V_48 -> V_67 -> V_68 ( & V_2 -> V_25 , V_25 ) ) {
F_10 () ;
return - V_69 ;
}
F_56 ( V_43 , V_2 ) ;
F_10 () ;
F_61 ( V_48 ) ;
return 0 ;
}
static struct V_7 *
F_70 ( struct V_42 * V_43 ,
const struct V_70 * V_71 )
{
struct V_1 * V_2 ;
struct V_7 * V_34 = NULL ;
F_49 (delegation, &server->delegations, super_list) {
F_17 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_7 != NULL &&
F_71 ( V_71 , & F_9 ( V_2 -> V_7 ) -> V_72 ) == 0 ) {
V_34 = F_33 ( V_2 -> V_7 ) ;
}
F_22 ( & V_2 -> V_36 ) ;
if ( V_34 != NULL )
break;
}
return V_34 ;
}
struct V_7 * F_72 ( struct V_44 * V_48 ,
const struct V_70 * V_71 )
{
struct V_42 * V_43 ;
struct V_7 * V_34 = NULL ;
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link) {
V_34 = F_70 ( V_43 , V_71 ) ;
if ( V_34 != NULL )
break;
}
F_10 () ;
return V_34 ;
}
static void F_73 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
F_49 (delegation, &server->delegations, super_list)
F_5 ( V_39 , & V_2 -> V_6 ) ;
}
void F_74 ( struct V_44 * V_48 )
{
struct V_42 * V_43 ;
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link)
F_73 ( V_43 ) ;
F_10 () ;
}
void F_75 ( struct V_44 * V_48 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_7 * V_7 ;
V_62:
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link) {
F_49 (delegation, &server->delegations,
super_list) {
if ( F_19 ( V_39 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_32 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_39 ( F_9 ( V_7 ) ,
V_43 ) ;
F_10 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_51 ( V_7 ) ;
goto V_62;
}
}
F_10 () ;
}
int F_76 ( struct V_44 * V_48 )
{
struct V_42 * V_43 ;
int V_8 = 0 ;
F_7 () ;
F_49 (server, &clp->cl_superblocks, client_link)
if ( ! F_77 ( & V_43 -> V_58 ) ) {
V_8 = 1 ;
break;
}
F_10 () ;
return V_8 ;
}
bool F_78 ( T_2 * V_73 , struct V_7 * V_7 ,
T_1 V_6 )
{
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_8 ;
V_6 &= V_9 | V_10 ;
F_7 () ;
V_2 = F_8 ( V_27 -> V_2 ) ;
V_8 = ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) ;
if ( V_8 ) {
F_26 ( V_73 , & V_2 -> V_25 ) ;
F_4 ( V_2 ) ;
}
F_10 () ;
return V_8 ;
}
