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
if ( memcmp ( V_14 -> V_25 . V_32 , V_25 -> V_32 , sizeof( V_14 -> V_25 . V_32 ) ) != 0 )
continue;
F_20 ( V_12 ) ;
F_21 ( & V_7 -> V_30 ) ;
V_28 = F_22 ( V_12 , V_14 , V_25 ) ;
if ( V_28 >= 0 )
V_28 = F_11 ( V_12 , V_14 ) ;
F_23 ( V_12 ) ;
if ( V_28 != 0 )
return V_28 ;
goto V_29;
}
F_21 ( & V_7 -> V_30 ) ;
return 0 ;
}
void F_24 ( struct V_7 * V_7 , struct V_33 * V_3 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_33 * V_36 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_17 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_7 != NULL ) {
memcpy ( V_2 -> V_25 . V_32 , V_35 -> V_2 . V_32 ,
sizeof( V_2 -> V_25 . V_32 ) ) ;
V_2 -> type = V_35 -> V_38 ;
V_2 -> V_39 = V_35 -> V_39 ;
V_36 = V_2 -> V_3 ;
V_2 -> V_3 = F_25 ( V_3 ) ;
F_26 ( V_40 ,
& V_2 -> V_6 ) ;
F_9 ( V_7 ) -> V_41 = V_2 -> type ;
F_21 ( & V_2 -> V_37 ) ;
F_2 ( V_36 ) ;
F_10 () ;
} else {
F_21 ( & V_2 -> V_37 ) ;
F_10 () ;
F_27 ( V_7 , V_3 , V_35 ) ;
}
} else {
F_10 () ;
}
}
static int F_28 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_42 )
{
int V_35 = 0 ;
V_35 = F_29 ( V_7 , V_2 -> V_3 , & V_2 -> V_25 , V_42 ) ;
F_1 ( V_2 ) ;
return V_35 ;
}
static struct V_7 * F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_17 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_31 ( V_2 -> V_7 ) ;
F_21 ( & V_2 -> V_37 ) ;
return V_7 ;
}
static struct V_1 *
F_32 ( struct V_26 * V_27 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 =
F_33 ( V_27 -> V_2 ,
F_34 ( & V_44 -> V_45 -> V_46 ) ) ;
if ( V_2 == NULL )
goto V_47;
F_17 ( & V_2 -> V_37 ) ;
F_35 ( & V_2 -> V_48 ) ;
V_2 -> V_7 = NULL ;
V_27 -> V_41 = 0 ;
F_36 ( V_27 -> V_2 , NULL ) ;
F_21 ( & V_2 -> V_37 ) ;
return V_2 ;
V_47:
return NULL ;
}
static struct V_1 * F_37 ( struct V_26 * V_27 ,
struct V_43 * V_44 )
{
struct V_45 * V_49 = V_44 -> V_45 ;
struct V_1 * V_2 ;
F_17 ( & V_49 -> V_46 ) ;
V_2 = F_32 ( V_27 , V_44 ) ;
F_21 ( & V_49 -> V_46 ) ;
return V_2 ;
}
int F_27 ( struct V_7 * V_7 , struct V_33 * V_3 , struct V_34 * V_35 )
{
struct V_43 * V_44 = F_38 ( V_7 ) ;
struct V_45 * V_49 = V_44 -> V_45 ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_50 ;
struct V_1 * V_51 = NULL ;
int V_17 = 0 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_52 ) ;
if ( V_2 == NULL )
return - V_53 ;
memcpy ( V_2 -> V_25 . V_32 , V_35 -> V_2 . V_32 ,
sizeof( V_2 -> V_25 . V_32 ) ) ;
V_2 -> type = V_35 -> V_38 ;
V_2 -> V_39 = V_35 -> V_39 ;
V_2 -> V_54 = V_7 -> V_55 ;
V_2 -> V_3 = F_25 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_40 ( & V_2 -> V_37 ) ;
F_17 ( & V_49 -> V_46 ) ;
V_50 = F_33 ( V_27 -> V_2 ,
F_34 ( & V_49 -> V_46 ) ) ;
if ( V_50 != NULL ) {
if ( memcmp ( & V_2 -> V_25 , & V_50 -> V_25 ,
sizeof( V_50 -> V_25 ) ) == 0 &&
V_2 -> type == V_50 -> type ) {
goto V_19;
}
F_41 ( V_56 , L_1
L_2 ,
V_57 , V_49 -> V_58 ) ;
if ( V_2 -> type <= V_50 -> type ) {
V_51 = V_2 ;
V_2 = NULL ;
goto V_19;
}
V_51 = F_32 ( V_27 , V_44 ) ;
}
F_42 ( & V_2 -> V_48 , & V_44 -> V_59 ) ;
V_27 -> V_41 = V_2 -> type ;
F_36 ( V_27 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_17 ( & V_7 -> V_30 ) ;
V_27 -> V_60 |= V_61 ;
F_21 ( & V_7 -> V_30 ) ;
V_19:
F_21 ( & V_49 -> V_46 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_51 != NULL )
F_28 ( V_7 , V_51 , 0 ) ;
return V_17 ;
}
static int F_43 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_42 )
{
struct V_26 * V_27 = F_9 ( V_7 ) ;
int V_28 ;
F_44 ( & V_27 -> V_62 ) ;
V_28 = F_16 ( V_7 , & V_2 -> V_25 ) ;
F_45 ( & V_27 -> V_62 ) ;
if ( V_28 )
goto V_19;
V_28 = F_28 ( V_7 , V_2 , V_42 ) ;
V_19:
return V_28 ;
}
int F_46 ( struct V_45 * V_49 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_7 * V_7 ;
int V_28 = 0 ;
V_63:
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link) {
F_47 (delegation, &server->delegations,
super_list) {
if ( ! F_48 ( V_64 ,
& V_2 -> V_6 ) )
continue;
V_7 = F_30 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_37 ( F_9 ( V_7 ) ,
V_44 ) ;
F_10 () ;
if ( V_2 != NULL ) {
F_49 ( V_7 -> V_65 ) ;
V_28 = F_43 ( V_7 ,
V_2 , 0 ) ;
}
F_50 ( V_7 ) ;
if ( ! V_28 )
goto V_63;
F_5 ( V_66 , & V_49 -> V_67 ) ;
return V_28 ;
}
}
F_10 () ;
return 0 ;
}
void F_51 ( struct V_7 * V_7 )
{
struct V_43 * V_44 = F_38 ( V_7 ) ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
if ( F_52 ( V_27 -> V_2 ) != NULL ) {
V_2 = F_37 ( V_27 , V_44 ) ;
if ( V_2 != NULL )
F_28 ( V_7 , V_2 , 0 ) ;
}
}
int F_53 ( struct V_7 * V_7 )
{
struct V_43 * V_44 = F_38 ( V_7 ) ;
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_28 = 0 ;
if ( F_52 ( V_27 -> V_2 ) != NULL ) {
V_2 = F_37 ( V_27 , V_44 ) ;
if ( V_2 != NULL ) {
F_54 ( V_7 ) ;
V_28 = F_43 ( V_7 , V_2 , 1 ) ;
}
}
return V_28 ;
}
static void F_55 ( struct V_43 * V_44 ,
struct V_1 * V_2 )
{
F_5 ( V_64 , & V_2 -> V_6 ) ;
F_5 ( V_66 , & V_44 -> V_45 -> V_67 ) ;
}
void F_56 ( struct V_68 * V_69 )
{
struct V_43 * V_44 = F_57 ( V_69 ) ;
struct V_45 * V_49 = V_44 -> V_45 ;
struct V_1 * V_2 ;
if ( V_49 == NULL )
return;
F_7 () ;
F_47 (delegation, &server->delegations, super_list) {
F_17 ( & V_2 -> V_37 ) ;
F_5 ( V_64 , & V_2 -> V_6 ) ;
F_21 ( & V_2 -> V_37 ) ;
}
F_10 () ;
if ( F_46 ( V_49 ) != 0 )
F_58 ( V_49 ) ;
}
static void F_59 ( struct V_43 * V_44 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_47 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_9 | V_10 ) ) && ! ( V_6 & V_10 ) )
continue;
if ( V_2 -> type & V_6 )
F_55 ( V_44 , V_2 ) ;
}
}
static void F_60 ( struct V_45 * V_49 ,
T_1 V_6 )
{
struct V_43 * V_44 ;
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link)
F_59 ( V_44 , V_6 ) ;
F_10 () ;
}
static void F_61 ( struct V_45 * V_49 )
{
F_60 ( V_49 , V_9 | V_10 ) ;
}
static void F_62 ( struct V_45 * V_49 )
{
if ( F_19 ( V_66 , & V_49 -> V_67 ) )
F_58 ( V_49 ) ;
}
void F_63 ( struct V_45 * V_49 , T_1 V_6 )
{
F_60 ( V_49 , V_6 ) ;
F_62 ( V_49 ) ;
}
void F_64 ( struct V_45 * V_49 )
{
F_63 ( V_49 , V_9 | V_10 ) ;
}
void F_65 ( struct V_45 * V_49 )
{
if ( V_49 == NULL )
return;
F_61 ( V_49 ) ;
}
static void F_66 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
F_47 (delegation, &server->delegations, super_list) {
if ( F_48 ( V_5 , & V_2 -> V_6 ) )
continue;
F_55 ( V_44 , V_2 ) ;
}
}
void F_67 ( struct V_45 * V_49 )
{
struct V_43 * V_44 ;
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link)
F_66 ( V_44 ) ;
F_10 () ;
F_62 ( V_49 ) ;
}
int F_68 ( struct V_7 * V_7 ,
const T_2 * V_25 )
{
struct V_43 * V_44 = F_38 ( V_7 ) ;
struct V_45 * V_49 = V_44 -> V_45 ;
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( ! V_49 -> V_70 -> V_71 ( V_2 , V_25 ) ) {
F_10 () ;
return - V_72 ;
}
F_55 ( V_44 , V_2 ) ;
F_10 () ;
F_62 ( V_49 ) ;
return 0 ;
}
static struct V_7 *
F_69 ( struct V_43 * V_44 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_7 * V_35 = NULL ;
F_47 (delegation, &server->delegations, super_list) {
F_17 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_7 != NULL &&
F_70 ( V_74 , & F_9 ( V_2 -> V_7 ) -> V_75 ) == 0 ) {
V_35 = F_31 ( V_2 -> V_7 ) ;
}
F_21 ( & V_2 -> V_37 ) ;
if ( V_35 != NULL )
break;
}
return V_35 ;
}
struct V_7 * F_71 ( struct V_45 * V_49 ,
const struct V_73 * V_74 )
{
struct V_43 * V_44 ;
struct V_7 * V_35 = NULL ;
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link) {
V_35 = F_69 ( V_44 , V_74 ) ;
if ( V_35 != NULL )
break;
}
F_10 () ;
return V_35 ;
}
static void F_72 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
F_47 (delegation, &server->delegations, super_list)
F_5 ( V_40 , & V_2 -> V_6 ) ;
}
void F_73 ( struct V_45 * V_49 )
{
struct V_43 * V_44 ;
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link)
F_72 ( V_44 ) ;
F_10 () ;
}
void F_74 ( struct V_45 * V_49 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_7 * V_7 ;
V_63:
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link) {
F_47 (delegation, &server->delegations,
super_list) {
if ( F_19 ( V_40 ,
& V_2 -> V_6 ) == 0 )
continue;
V_7 = F_30 ( V_2 ) ;
if ( V_7 == NULL )
continue;
V_2 = F_37 ( F_9 ( V_7 ) ,
V_44 ) ;
F_10 () ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
F_50 ( V_7 ) ;
goto V_63;
}
}
F_10 () ;
}
int F_75 ( struct V_45 * V_49 )
{
struct V_43 * V_44 ;
int V_8 = 0 ;
F_7 () ;
F_47 (server, &clp->cl_superblocks, client_link)
if ( ! F_76 ( & V_44 -> V_59 ) ) {
V_8 = 1 ;
break;
}
F_10 () ;
return V_8 ;
}
int F_77 ( T_2 * V_76 , struct V_7 * V_7 )
{
struct V_26 * V_27 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_8 = 0 ;
F_7 () ;
V_2 = F_8 ( V_27 -> V_2 ) ;
if ( V_2 != NULL ) {
memcpy ( V_76 -> V_32 , V_2 -> V_25 . V_32 , sizeof( V_76 -> V_32 ) ) ;
V_8 = 1 ;
}
F_10 () ;
return V_8 ;
}
