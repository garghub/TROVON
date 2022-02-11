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
struct V_20 * V_21 = V_7 -> V_22 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
if ( V_21 == NULL )
goto V_26;
V_24 = & V_21 -> V_27 ;
F_15 ( & V_21 -> V_28 ) ;
V_29:
F_16 (fl, list, fl_list) {
if ( F_17 ( V_19 -> V_30 ) != V_14 )
continue;
F_18 ( & V_21 -> V_28 ) ;
V_25 = F_19 ( V_19 , V_16 , V_17 ) ;
if ( V_25 < 0 )
goto V_26;
F_15 ( & V_21 -> V_28 ) ;
}
if ( V_24 == & V_21 -> V_27 ) {
V_24 = & V_21 -> V_31 ;
goto V_29;
}
F_18 ( & V_21 -> V_28 ) ;
V_26:
return V_25 ;
}
static int F_20 ( struct V_7 * V_7 ,
const T_2 * V_17 , T_1 type )
{
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_13 * V_14 ;
struct V_34 * V_35 ;
struct V_15 * V_16 ;
unsigned int V_36 ;
int V_37 ;
V_38:
F_15 ( & V_7 -> V_39 ) ;
F_16 (ctx, &nfsi->open_files, list) {
V_16 = V_14 -> V_16 ;
if ( V_16 == NULL )
continue;
if ( ! F_10 ( V_40 , & V_16 -> V_6 ) )
continue;
if ( ! F_21 ( V_16 ) )
continue;
if ( ! F_22 ( & V_16 -> V_17 , V_17 ) )
continue;
F_23 ( V_14 ) ;
F_18 ( & V_7 -> V_39 ) ;
V_35 = V_16 -> V_41 ;
F_24 ( & V_35 -> V_42 ) ;
V_36 = F_25 ( & V_35 -> V_43 ) ;
V_37 = F_26 ( V_14 , V_16 , V_17 , type ) ;
if ( ! V_37 )
V_37 = F_14 ( V_14 , V_16 , V_17 ) ;
if ( ! V_37 && F_27 ( & V_35 -> V_43 , V_36 ) )
V_37 = - V_44 ;
F_28 ( & V_35 -> V_42 ) ;
F_29 ( V_14 ) ;
if ( V_37 != 0 )
return V_37 ;
goto V_38;
}
F_18 ( & V_7 -> V_39 ) ;
return 0 ;
}
void F_30 ( struct V_7 * V_7 , struct V_45 * V_3 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_45 * V_48 = NULL ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_15 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_7 != NULL ) {
F_31 ( & V_2 -> V_17 , & V_47 -> V_2 ) ;
V_2 -> type = V_47 -> V_50 ;
V_2 -> V_51 = V_47 -> V_51 ;
V_48 = V_2 -> V_3 ;
V_2 -> V_3 = F_32 ( V_3 ) ;
F_33 ( V_52 ,
& V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_49 ) ;
F_11 () ;
F_2 ( V_48 ) ;
F_34 ( V_7 , V_47 -> V_50 ) ;
} else {
F_18 ( & V_2 -> V_49 ) ;
F_11 () ;
F_35 ( V_7 , V_3 , V_47 ) ;
}
} else {
F_11 () ;
}
}
static int F_36 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_53 )
{
int V_47 = 0 ;
if ( ! F_10 ( V_54 , & V_2 -> V_6 ) )
V_47 = F_37 ( V_7 ,
V_2 -> V_3 ,
& V_2 -> V_17 ,
V_53 ) ;
F_1 ( V_2 ) ;
return V_47 ;
}
static struct V_7 * F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = NULL ;
F_15 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_7 != NULL )
V_7 = F_39 ( V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_49 ) ;
return V_7 ;
}
static struct V_1 *
F_40 ( struct V_32 * V_33 )
{
struct V_1 * V_9 = NULL ;
struct V_1 * V_2 = F_8 ( V_33 -> V_2 ) ;
if ( V_2 == NULL )
goto V_26;
F_15 ( & V_2 -> V_49 ) ;
if ( ! F_41 ( V_12 , & V_2 -> V_6 ) )
V_9 = V_2 ;
F_18 ( & V_2 -> V_49 ) ;
V_26:
return V_9 ;
}
static struct V_1 *
F_42 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_40 ( V_33 ) ;
F_11 () ;
return V_2 ;
}
static void
F_43 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_15 ( & V_2 -> V_49 ) ;
F_33 ( V_12 , & V_2 -> V_6 ) ;
F_5 ( V_57 , & V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_49 ) ;
F_5 ( V_58 , & V_56 -> V_59 ) ;
}
static struct V_1 *
F_44 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_1 * V_60 =
F_45 ( V_33 -> V_2 ,
F_46 ( & V_56 -> V_61 ) ) ;
if ( V_60 == NULL || V_2 != V_60 )
return NULL ;
F_15 ( & V_2 -> V_49 ) ;
F_5 ( V_12 , & V_2 -> V_6 ) ;
F_47 ( & V_2 -> V_62 ) ;
V_2 -> V_7 = NULL ;
F_48 ( V_33 -> V_2 , NULL ) ;
F_18 ( & V_2 -> V_49 ) ;
return V_2 ;
}
static struct V_1 * F_49 ( struct V_32 * V_33 ,
struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_55 * V_56 = V_64 -> V_55 ;
F_15 ( & V_56 -> V_61 ) ;
V_2 = F_44 ( V_33 , V_2 , V_56 ) ;
F_18 ( & V_56 -> V_61 ) ;
return V_2 ;
}
static struct V_1 *
F_50 ( struct V_7 * V_7 )
{
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_63 * V_64 = F_51 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_42 ( V_33 ) ;
if ( V_2 == NULL )
return NULL ;
return F_49 ( V_33 , V_2 , V_64 ) ;
}
static void
F_52 ( struct V_1 * V_2 ,
const struct V_1 * V_65 )
{
if ( F_53 ( & V_65 -> V_17 , & V_2 -> V_17 ) ) {
V_2 -> V_17 . V_66 = V_65 -> V_17 . V_66 ;
F_54 () ;
V_2 -> type = V_65 -> type ;
}
}
int F_35 ( struct V_7 * V_7 , struct V_45 * V_3 , struct V_46 * V_47 )
{
struct V_63 * V_64 = F_51 ( V_7 ) ;
struct V_55 * V_56 = V_64 -> V_55 ;
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_1 * V_2 , * V_67 ;
struct V_1 * V_68 = NULL ;
int V_25 = 0 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_69 ) ;
if ( V_2 == NULL )
return - V_70 ;
F_31 ( & V_2 -> V_17 , & V_47 -> V_2 ) ;
V_2 -> type = V_47 -> V_50 ;
V_2 -> V_51 = V_47 -> V_51 ;
V_2 -> V_71 = V_7 -> V_72 ;
V_2 -> V_3 = F_32 ( V_3 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = 1 << V_5 ;
F_56 ( & V_2 -> V_49 ) ;
F_15 ( & V_56 -> V_61 ) ;
V_67 = F_45 ( V_33 -> V_2 ,
F_46 ( & V_56 -> V_61 ) ) ;
if ( V_67 != NULL ) {
if ( F_57 ( & V_67 -> V_17 ,
& V_2 -> V_17 ) ) {
F_52 ( V_67 ,
V_2 ) ;
goto V_26;
}
F_58 ( V_73 , L_1
L_2 ,
V_74 , V_56 -> V_75 ) ;
if ( V_2 -> type == V_67 -> type ||
! ( V_2 -> type & V_11 ) ) {
V_68 = V_2 ;
V_2 = NULL ;
goto V_26;
}
if ( F_41 ( V_12 ,
& V_67 -> V_6 ) )
goto V_26;
V_68 = F_44 ( V_33 ,
V_67 , V_56 ) ;
if ( V_68 == NULL )
goto V_26;
}
F_59 ( & V_2 -> V_62 , & V_64 -> V_76 ) ;
F_48 ( V_33 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_15 ( & V_7 -> V_39 ) ;
V_33 -> V_77 |= V_78 ;
F_18 ( & V_7 -> V_39 ) ;
F_60 ( V_7 , V_47 -> V_50 ) ;
V_26:
F_18 ( & V_56 -> V_61 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_68 != NULL )
F_36 ( V_7 , V_68 , 0 ) ;
return V_25 ;
}
static int F_61 ( struct V_7 * V_7 , struct V_1 * V_2 , int V_53 )
{
struct V_55 * V_56 = F_51 ( V_7 ) -> V_55 ;
struct V_32 * V_33 = F_9 ( V_7 ) ;
int V_37 = 0 ;
if ( V_2 == NULL )
return 0 ;
do {
if ( F_10 ( V_54 , & V_2 -> V_6 ) )
break;
V_37 = F_20 ( V_7 , & V_2 -> V_17 ,
V_2 -> type ) ;
if ( ! V_53 || V_37 != - V_44 )
break;
V_37 = F_62 ( V_56 ) ;
} while ( V_37 == 0 );
if ( V_37 ) {
F_43 ( V_2 , V_56 ) ;
goto V_26;
}
if ( ! F_49 ( V_33 , V_2 , F_51 ( V_7 ) ) )
goto V_26;
V_37 = F_36 ( V_7 , V_2 , V_53 ) ;
V_26:
return V_37 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
bool V_9 = false ;
if ( F_10 ( V_12 , & V_2 -> V_6 ) )
goto V_26;
if ( F_64 ( V_57 , & V_2 -> V_6 ) )
V_9 = true ;
if ( F_64 ( V_79 , & V_2 -> V_6 ) && ! V_9 ) {
struct V_7 * V_7 ;
F_15 ( & V_2 -> V_49 ) ;
V_7 = V_2 -> V_7 ;
if ( V_7 && F_65 ( & F_9 ( V_7 ) -> V_80 ) )
V_9 = true ;
F_18 ( & V_2 -> V_49 ) ;
}
V_26:
return V_9 ;
}
int F_66 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_7 * V_7 ;
int V_37 = 0 ;
V_29:
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link) {
F_67 (delegation, &server->delegations,
super_list) {
if ( ! F_63 ( V_2 ) )
continue;
if ( ! F_68 ( V_64 -> V_81 ) )
continue;
V_7 = F_38 ( V_2 ) ;
if ( V_7 == NULL ) {
F_11 () ;
F_69 ( V_64 -> V_81 ) ;
goto V_29;
}
V_2 = F_40 ( F_9 ( V_7 ) ) ;
F_11 () ;
V_37 = F_61 ( V_7 , V_2 , 0 ) ;
F_70 ( V_7 ) ;
F_69 ( V_64 -> V_81 ) ;
if ( ! V_37 )
goto V_29;
F_5 ( V_58 , & V_56 -> V_59 ) ;
return V_37 ;
}
}
F_11 () ;
return 0 ;
}
void F_71 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_50 ( V_7 ) ;
if ( V_2 != NULL )
F_36 ( V_7 , V_2 , 1 ) ;
}
int F_72 ( struct V_7 * V_7 )
{
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_73 ( V_7 ) ;
V_2 = F_42 ( V_33 ) ;
if ( V_2 != NULL )
V_37 = F_61 ( V_7 , V_2 , 1 ) ;
return V_37 ;
}
static void F_74 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
F_5 ( V_79 , & V_2 -> V_6 ) ;
F_5 ( V_58 , & V_64 -> V_55 -> V_59 ) ;
}
static void F_75 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
F_5 ( V_57 , & V_2 -> V_6 ) ;
F_5 ( V_58 , & V_64 -> V_55 -> V_59 ) ;
}
static bool F_76 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
bool V_9 = false ;
F_67 (delegation, &server->delegations, super_list) {
F_75 ( V_64 , V_2 ) ;
V_9 = true ;
}
return V_9 ;
}
static void F_77 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link)
F_76 ( V_64 ) ;
F_11 () ;
}
static void F_78 ( struct V_55 * V_56 )
{
if ( F_10 ( V_58 , & V_56 -> V_59 ) )
F_79 ( V_56 ) ;
}
void F_80 ( struct V_55 * V_56 )
{
F_77 ( V_56 ) ;
F_78 ( V_56 ) ;
}
void F_81 ( struct V_63 * V_64 )
{
struct V_55 * V_56 = V_64 -> V_55 ;
bool V_82 ;
if ( V_56 == NULL )
return;
F_7 () ;
V_82 = F_76 ( V_64 ) ;
F_11 () ;
if ( V_82 ) {
F_79 ( V_56 ) ;
F_62 ( V_56 ) ;
}
}
static void F_82 ( struct V_63 * V_64 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_67 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_10 | V_11 ) ) && ! ( V_6 & V_11 ) )
continue;
if ( V_2 -> type & V_6 )
F_74 ( V_64 , V_2 ) ;
}
}
static void F_83 ( struct V_55 * V_56 ,
T_1 V_6 )
{
struct V_63 * V_64 ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link)
F_82 ( V_64 , V_6 ) ;
F_11 () ;
}
static void F_84 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_5 ( V_54 , & V_2 -> V_6 ) ;
F_75 ( F_51 ( V_7 ) , V_2 ) ;
}
F_11 () ;
}
void F_85 ( struct V_7 * V_7 )
{
struct V_1 * V_2 ;
F_84 ( V_7 ) ;
V_2 = F_50 ( V_7 ) ;
if ( V_2 ) {
F_86 ( V_7 , & V_2 -> V_17 ) ;
F_1 ( V_2 ) ;
}
}
void F_87 ( struct V_55 * V_56 , T_1 V_6 )
{
F_83 ( V_56 , V_6 ) ;
F_78 ( V_56 ) ;
}
static void F_88 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
F_67 (delegation, &server->delegations, super_list) {
if ( F_64 ( V_5 , & V_2 -> V_6 ) )
continue;
F_74 ( V_64 , V_2 ) ;
}
}
void F_89 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link)
F_88 ( V_64 ) ;
F_11 () ;
F_78 ( V_56 ) ;
}
int F_90 ( struct V_7 * V_7 ,
const T_2 * V_17 )
{
struct V_63 * V_64 = F_51 ( V_7 ) ;
struct V_55 * V_56 = V_64 -> V_55 ;
struct V_1 * V_2 ;
F_7 () ;
V_2 = F_8 ( F_9 ( V_7 ) -> V_2 ) ;
if ( V_2 == NULL )
goto V_83;
if ( V_17 != NULL &&
! V_56 -> V_84 -> V_85 ( & V_2 -> V_17 , V_17 ) )
goto V_83;
F_75 ( V_64 , V_2 ) ;
F_11 () ;
F_78 ( V_56 ) ;
return 0 ;
V_83:
F_11 () ;
return - V_86 ;
}
static struct V_7 *
F_91 ( struct V_63 * V_64 ,
const struct V_87 * V_88 )
{
struct V_1 * V_2 ;
struct V_7 * V_47 = NULL ;
F_67 (delegation, &server->delegations, super_list) {
F_15 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_7 != NULL &&
F_92 ( V_88 , & F_9 ( V_2 -> V_7 ) -> V_89 ) == 0 ) {
V_47 = F_39 ( V_2 -> V_7 ) ;
}
F_18 ( & V_2 -> V_49 ) ;
if ( V_47 != NULL )
break;
}
return V_47 ;
}
struct V_7 * F_93 ( struct V_55 * V_56 ,
const struct V_87 * V_88 )
{
struct V_63 * V_64 ;
struct V_7 * V_47 = NULL ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link) {
V_47 = F_91 ( V_64 , V_88 ) ;
if ( V_47 != NULL )
break;
}
F_11 () ;
return V_47 ;
}
static void F_94 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
F_67 (delegation, &server->delegations, super_list)
F_5 ( V_52 , & V_2 -> V_6 ) ;
}
void F_95 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link)
F_94 ( V_64 ) ;
F_11 () ;
}
void F_96 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_7 * V_7 ;
V_29:
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link) {
F_67 (delegation, &server->delegations,
super_list) {
if ( F_10 ( V_12 ,
& V_2 -> V_6 ) )
continue;
if ( F_10 ( V_52 ,
& V_2 -> V_6 ) == 0 )
continue;
if ( ! F_68 ( V_64 -> V_81 ) )
continue;
V_7 = F_38 ( V_2 ) ;
if ( V_7 == NULL ) {
F_11 () ;
F_69 ( V_64 -> V_81 ) ;
goto V_29;
}
V_2 = F_40 ( F_9 ( V_7 ) ) ;
F_11 () ;
if ( V_2 != NULL ) {
V_2 = F_49 ( F_9 ( V_7 ) ,
V_2 , V_64 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
}
F_70 ( V_7 ) ;
F_69 ( V_64 -> V_81 ) ;
goto V_29;
}
}
F_11 () ;
}
int F_97 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
int V_9 = 0 ;
F_7 () ;
F_67 (server, &clp->cl_superblocks, client_link)
if ( ! F_65 ( & V_64 -> V_76 ) ) {
V_9 = 1 ;
break;
}
F_11 () ;
return V_9 ;
}
bool F_98 ( struct V_7 * V_7 , T_1 V_6 ,
T_2 * V_90 , struct V_45 * * V_3 )
{
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_9 ;
V_6 &= V_10 | V_11 ;
F_7 () ;
V_2 = F_8 ( V_33 -> V_2 ) ;
V_9 = ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 ) ;
if ( V_9 ) {
F_31 ( V_90 , & V_2 -> V_17 ) ;
F_4 ( V_2 ) ;
if ( V_3 )
* V_3 = F_32 ( V_2 -> V_3 ) ;
}
F_11 () ;
return V_9 ;
}
bool F_99 ( const struct V_7 * V_7 )
{
struct V_32 * V_33 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
bool V_9 = true ;
F_7 () ;
V_2 = F_8 ( V_33 -> V_2 ) ;
if ( V_2 == NULL || ! ( V_2 -> type & V_11 ) )
goto V_26;
if ( V_33 -> V_91 < V_2 -> V_51 )
V_9 = false ;
V_26:
F_11 () ;
return V_9 ;
}
