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
static bool
F_6 ( const struct V_1 * V_2 ,
T_1 V_6 )
{
if ( V_2 != NULL && ( V_2 -> type & V_6 ) == V_6 &&
! F_7 ( V_7 , & V_2 -> V_6 ) &&
! F_7 ( V_8 , & V_2 -> V_6 ) )
return true ;
return false ;
}
static int
F_8 ( struct V_9 * V_9 , T_1 V_6 , bool V_10 )
{
struct V_1 * V_2 ;
int V_11 = 0 ;
V_6 &= V_12 | V_13 ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( F_6 ( V_2 , V_6 ) ) {
if ( V_10 )
F_4 ( V_2 ) ;
V_11 = 1 ;
}
F_12 () ;
return V_11 ;
}
int F_13 ( struct V_9 * V_9 , T_1 V_6 )
{
return F_8 ( V_9 , V_6 , true ) ;
}
int F_14 ( struct V_9 * V_9 , T_1 V_6 )
{
return F_8 ( V_9 , V_6 , false ) ;
}
static int F_15 ( struct V_14 * V_15 , struct V_16 * V_17 , const T_2 * V_18 )
{
struct V_9 * V_9 = V_17 -> V_9 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = V_9 -> V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( V_22 == NULL )
goto V_27;
V_25 = & V_22 -> V_28 ;
F_16 ( & V_22 -> V_29 ) ;
V_30:
F_17 (fl, list, fl_list) {
if ( F_18 ( V_20 -> V_31 ) != V_15 )
continue;
F_19 ( & V_22 -> V_29 ) ;
V_26 = F_20 ( V_20 , V_17 , V_18 ) ;
if ( V_26 < 0 )
goto V_27;
F_16 ( & V_22 -> V_29 ) ;
}
if ( V_25 == & V_22 -> V_28 ) {
V_25 = & V_22 -> V_32 ;
goto V_30;
}
F_19 ( & V_22 -> V_29 ) ;
V_27:
return V_26 ;
}
static int F_21 ( struct V_9 * V_9 ,
const T_2 * V_18 , T_1 type )
{
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_14 * V_15 ;
struct V_35 * V_36 ;
struct V_16 * V_17 ;
unsigned int V_37 ;
int V_38 ;
V_39:
F_16 ( & V_9 -> V_40 ) ;
F_17 (ctx, &nfsi->open_files, list) {
V_17 = V_15 -> V_17 ;
if ( V_17 == NULL )
continue;
if ( ! F_7 ( V_41 , & V_17 -> V_6 ) )
continue;
if ( ! F_22 ( V_17 ) )
continue;
if ( ! F_23 ( & V_17 -> V_18 , V_18 ) )
continue;
F_24 ( V_15 ) ;
F_19 ( & V_9 -> V_40 ) ;
V_36 = V_17 -> V_42 ;
F_25 ( & V_36 -> V_43 ) ;
V_37 = F_26 ( & V_36 -> V_44 ) ;
V_38 = F_27 ( V_15 , V_17 , V_18 , type ) ;
if ( ! V_38 )
V_38 = F_15 ( V_15 , V_17 , V_18 ) ;
if ( ! V_38 && F_28 ( & V_36 -> V_44 , V_37 ) )
V_38 = - V_45 ;
F_29 ( & V_36 -> V_43 ) ;
F_30 ( V_15 ) ;
if ( V_38 != 0 )
return V_38 ;
goto V_39;
}
F_19 ( & V_9 -> V_40 ) ;
return 0 ;
}
void F_31 ( struct V_9 * V_9 , struct V_46 * V_3 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_46 * V_49 = NULL ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( V_2 != NULL ) {
F_16 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_9 != NULL ) {
F_32 ( & V_2 -> V_18 , & V_48 -> V_2 ) ;
V_2 -> type = V_48 -> V_51 ;
V_2 -> V_52 = V_48 -> V_52 ;
V_49 = V_2 -> V_3 ;
V_2 -> V_3 = F_33 ( V_3 ) ;
F_34 ( V_53 ,
& V_2 -> V_6 ) ;
F_19 ( & V_2 -> V_50 ) ;
F_12 () ;
F_2 ( V_49 ) ;
F_35 ( V_9 , V_48 -> V_51 ) ;
return;
}
F_19 ( & V_2 -> V_50 ) ;
}
F_12 () ;
F_36 ( V_9 , V_3 , V_48 ) ;
}
static int F_37 ( struct V_9 * V_9 , struct V_1 * V_2 , int V_54 )
{
int V_48 = 0 ;
if ( ! F_7 ( V_7 , & V_2 -> V_6 ) )
V_48 = F_38 ( V_9 ,
V_2 -> V_3 ,
& V_2 -> V_18 ,
V_54 ) ;
F_1 ( V_2 ) ;
return V_48 ;
}
static struct V_9 * F_39 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = NULL ;
F_16 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_9 != NULL )
V_9 = F_40 ( V_2 -> V_9 ) ;
F_19 ( & V_2 -> V_50 ) ;
return V_9 ;
}
static struct V_1 *
F_41 ( struct V_33 * V_34 )
{
struct V_1 * V_11 = NULL ;
struct V_1 * V_2 = F_10 ( V_34 -> V_2 ) ;
if ( V_2 == NULL )
goto V_27;
F_16 ( & V_2 -> V_50 ) ;
if ( ! F_42 ( V_8 , & V_2 -> V_6 ) )
V_11 = V_2 ;
F_19 ( & V_2 -> V_50 ) ;
V_27:
return V_11 ;
}
static struct V_1 *
F_43 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
F_9 () ;
V_2 = F_41 ( V_34 ) ;
F_12 () ;
return V_2 ;
}
static void
F_44 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_16 ( & V_2 -> V_50 ) ;
F_34 ( V_8 , & V_2 -> V_6 ) ;
F_5 ( V_57 , & V_2 -> V_6 ) ;
F_19 ( & V_2 -> V_50 ) ;
F_5 ( V_58 , & V_56 -> V_59 ) ;
}
static struct V_1 *
F_45 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_1 * V_60 =
F_46 ( V_34 -> V_2 ,
F_47 ( & V_56 -> V_61 ) ) ;
if ( V_60 == NULL || V_2 != V_60 )
return NULL ;
F_16 ( & V_2 -> V_50 ) ;
F_5 ( V_8 , & V_2 -> V_6 ) ;
F_48 ( & V_2 -> V_62 ) ;
V_2 -> V_9 = NULL ;
F_49 ( V_34 -> V_2 , NULL ) ;
F_19 ( & V_2 -> V_50 ) ;
return V_2 ;
}
static struct V_1 * F_50 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_55 * V_56 = V_64 -> V_55 ;
F_16 ( & V_56 -> V_61 ) ;
V_2 = F_45 ( V_34 , V_2 , V_56 ) ;
F_19 ( & V_56 -> V_61 ) ;
return V_2 ;
}
static struct V_1 *
F_51 ( struct V_9 * V_9 )
{
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_63 * V_64 = F_52 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_43 ( V_34 ) ;
if ( V_2 == NULL )
return NULL ;
return F_50 ( V_34 , V_2 , V_64 ) ;
}
static void
F_53 ( struct V_1 * V_2 ,
const struct V_1 * V_65 )
{
if ( F_54 ( & V_65 -> V_18 , & V_2 -> V_18 ) ) {
V_2 -> V_18 . V_66 = V_65 -> V_18 . V_66 ;
F_55 () ;
V_2 -> type = V_65 -> type ;
}
}
int F_36 ( struct V_9 * V_9 , struct V_46 * V_3 , struct V_47 * V_48 )
{
struct V_63 * V_64 = F_52 ( V_9 ) ;
struct V_55 * V_56 = V_64 -> V_55 ;
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_1 * V_2 , * V_67 ;
struct V_1 * V_68 = NULL ;
int V_26 = 0 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_69 ) ;
if ( V_2 == NULL )
return - V_70 ;
F_32 ( & V_2 -> V_18 , & V_48 -> V_2 ) ;
V_2 -> type = V_48 -> V_51 ;
V_2 -> V_52 = V_48 -> V_52 ;
V_2 -> V_71 = V_9 -> V_72 ;
V_2 -> V_3 = F_33 ( V_3 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_6 = 1 << V_5 ;
F_57 ( & V_2 -> V_50 ) ;
F_16 ( & V_56 -> V_61 ) ;
V_67 = F_46 ( V_34 -> V_2 ,
F_47 ( & V_56 -> V_61 ) ) ;
if ( V_67 != NULL ) {
if ( F_58 ( & V_67 -> V_18 ,
& V_2 -> V_18 ) ) {
F_53 ( V_67 ,
V_2 ) ;
goto V_27;
}
F_59 ( V_73 , L_1
L_2 ,
V_74 , V_56 -> V_75 ) ;
if ( V_2 -> type == V_67 -> type ||
! ( V_2 -> type & V_13 ) ) {
V_68 = V_2 ;
V_2 = NULL ;
goto V_27;
}
if ( F_42 ( V_8 ,
& V_67 -> V_6 ) )
goto V_27;
V_68 = F_45 ( V_34 ,
V_67 , V_56 ) ;
if ( V_68 == NULL )
goto V_27;
}
F_60 ( & V_2 -> V_62 , & V_64 -> V_76 ) ;
F_49 ( V_34 -> V_2 , V_2 ) ;
V_2 = NULL ;
F_61 ( V_9 , V_48 -> V_51 ) ;
V_27:
F_19 ( & V_56 -> V_61 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
if ( V_68 != NULL )
F_37 ( V_9 , V_68 , 0 ) ;
return V_26 ;
}
static int F_62 ( struct V_9 * V_9 , struct V_1 * V_2 , int V_54 )
{
struct V_55 * V_56 = F_52 ( V_9 ) -> V_55 ;
struct V_33 * V_34 = F_11 ( V_9 ) ;
int V_38 = 0 ;
if ( V_2 == NULL )
return 0 ;
do {
if ( F_7 ( V_7 , & V_2 -> V_6 ) )
break;
V_38 = F_21 ( V_9 , & V_2 -> V_18 ,
V_2 -> type ) ;
if ( ! V_54 || V_38 != - V_45 )
break;
V_38 = F_63 ( V_56 ) ;
} while ( V_38 == 0 );
if ( V_38 ) {
F_44 ( V_2 , V_56 ) ;
goto V_27;
}
if ( ! F_50 ( V_34 , V_2 , F_52 ( V_9 ) ) )
goto V_27;
V_38 = F_37 ( V_9 , V_2 , V_54 ) ;
V_27:
return V_38 ;
}
static bool F_64 ( struct V_1 * V_2 )
{
bool V_11 = false ;
if ( F_7 ( V_8 , & V_2 -> V_6 ) )
goto V_27;
if ( F_65 ( V_57 , & V_2 -> V_6 ) )
V_11 = true ;
if ( F_65 ( V_77 , & V_2 -> V_6 ) && ! V_11 ) {
struct V_9 * V_9 ;
F_16 ( & V_2 -> V_50 ) ;
V_9 = V_2 -> V_9 ;
if ( V_9 && F_66 ( & F_11 ( V_9 ) -> V_78 ) )
V_11 = true ;
F_19 ( & V_2 -> V_50 ) ;
}
V_27:
return V_11 ;
}
int F_67 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_9 * V_9 ;
int V_38 = 0 ;
V_30:
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link) {
F_68 (delegation, &server->delegations,
super_list) {
if ( ! F_64 ( V_2 ) )
continue;
if ( ! F_69 ( V_64 -> V_79 ) )
continue;
V_9 = F_39 ( V_2 ) ;
if ( V_9 == NULL ) {
F_12 () ;
F_70 ( V_64 -> V_79 ) ;
goto V_30;
}
V_2 = F_41 ( F_11 ( V_9 ) ) ;
F_12 () ;
V_38 = F_62 ( V_9 , V_2 , 0 ) ;
F_71 ( V_9 ) ;
F_70 ( V_64 -> V_79 ) ;
if ( ! V_38 )
goto V_30;
F_5 ( V_58 , & V_56 -> V_59 ) ;
return V_38 ;
}
}
F_12 () ;
return 0 ;
}
void F_72 ( struct V_9 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_51 ( V_9 ) ;
if ( V_2 != NULL )
F_37 ( V_9 , V_2 , 1 ) ;
}
int F_73 ( struct V_9 * V_9 )
{
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_1 * V_2 ;
int V_38 = 0 ;
F_74 ( V_9 ) ;
V_2 = F_43 ( V_34 ) ;
if ( V_2 != NULL )
V_38 = F_62 ( V_9 , V_2 , 1 ) ;
return V_38 ;
}
static void F_75 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
F_5 ( V_77 , & V_2 -> V_6 ) ;
F_5 ( V_58 , & V_64 -> V_55 -> V_59 ) ;
}
static void F_76 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
F_5 ( V_57 , & V_2 -> V_6 ) ;
F_5 ( V_58 , & V_64 -> V_55 -> V_59 ) ;
}
static bool F_77 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
bool V_11 = false ;
F_68 (delegation, &server->delegations, super_list) {
F_76 ( V_64 , V_2 ) ;
V_11 = true ;
}
return V_11 ;
}
static void F_78 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
F_77 ( V_64 ) ;
F_12 () ;
}
static void F_79 ( struct V_55 * V_56 )
{
if ( F_7 ( V_58 , & V_56 -> V_59 ) )
F_80 ( V_56 ) ;
}
void F_81 ( struct V_55 * V_56 )
{
F_78 ( V_56 ) ;
F_79 ( V_56 ) ;
}
void F_82 ( struct V_63 * V_64 )
{
struct V_55 * V_56 = V_64 -> V_55 ;
bool V_80 ;
if ( V_56 == NULL )
return;
F_9 () ;
V_80 = F_77 ( V_64 ) ;
F_12 () ;
if ( V_80 ) {
F_80 ( V_56 ) ;
F_63 ( V_56 ) ;
}
}
static void F_83 ( struct V_63 * V_64 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
F_68 (delegation, &server->delegations, super_list) {
if ( ( V_2 -> type == ( V_12 | V_13 ) ) && ! ( V_6 & V_13 ) )
continue;
if ( V_2 -> type & V_6 )
F_75 ( V_64 , V_2 ) ;
}
}
static void F_84 ( struct V_55 * V_56 ,
T_1 V_6 )
{
struct V_63 * V_64 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
F_83 ( V_64 , V_6 ) ;
F_12 () ;
}
static void F_85 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
F_5 ( V_7 , & V_2 -> V_6 ) ;
V_2 -> V_18 . type = V_81 ;
F_76 ( V_64 , V_2 ) ;
}
static bool F_86 ( struct V_9 * V_9 ,
const T_2 * V_18 )
{
struct V_1 * V_2 ;
T_2 V_82 ;
bool V_11 = false ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( V_2 == NULL )
goto V_27;
if ( V_18 == NULL ) {
F_32 ( & V_82 , & V_2 -> V_18 ) ;
V_18 = & V_82 ;
} else if ( ! F_23 ( V_18 , & V_2 -> V_18 ) )
goto V_27;
F_85 ( F_52 ( V_9 ) , V_2 ) ;
V_11 = true ;
V_27:
F_12 () ;
if ( V_11 )
F_87 ( V_9 , V_18 ) ;
return V_11 ;
}
void F_88 ( struct V_9 * V_9 ,
const T_2 * V_18 )
{
struct V_1 * V_2 ;
if ( ! F_86 ( V_9 , V_18 ) )
return;
V_2 = F_51 ( V_9 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
}
void F_89 ( struct V_55 * V_56 , T_1 V_6 )
{
F_84 ( V_56 , V_6 ) ;
F_79 ( V_56 ) ;
}
static void F_90 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
F_68 (delegation, &server->delegations, super_list) {
if ( F_65 ( V_5 , & V_2 -> V_6 ) )
continue;
F_75 ( V_64 , V_2 ) ;
}
}
void F_91 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
F_90 ( V_64 ) ;
F_12 () ;
F_79 ( V_56 ) ;
}
int F_92 ( struct V_9 * V_9 ,
const T_2 * V_18 )
{
struct V_63 * V_64 = F_52 ( V_9 ) ;
struct V_55 * V_56 = V_64 -> V_55 ;
struct V_1 * V_2 ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( V_2 == NULL )
goto V_83;
if ( V_18 != NULL &&
! V_56 -> V_84 -> V_85 ( & V_2 -> V_18 , V_18 ) )
goto V_83;
F_76 ( V_64 , V_2 ) ;
F_12 () ;
F_79 ( V_56 ) ;
return 0 ;
V_83:
F_12 () ;
return - V_86 ;
}
static struct V_9 *
F_93 ( struct V_63 * V_64 ,
const struct V_87 * V_88 )
{
struct V_1 * V_2 ;
struct V_9 * V_48 = NULL ;
F_68 (delegation, &server->delegations, super_list) {
F_16 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_9 != NULL &&
F_94 ( V_88 , & F_11 ( V_2 -> V_9 ) -> V_89 ) == 0 ) {
V_48 = F_40 ( V_2 -> V_9 ) ;
}
F_19 ( & V_2 -> V_50 ) ;
if ( V_48 != NULL )
break;
}
return V_48 ;
}
struct V_9 * F_95 ( struct V_55 * V_56 ,
const struct V_87 * V_88 )
{
struct V_63 * V_64 ;
struct V_9 * V_48 = NULL ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link) {
V_48 = F_93 ( V_64 , V_88 ) ;
if ( V_48 != NULL )
break;
}
F_12 () ;
return V_48 ;
}
static void F_96 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
F_68 (delegation, &server->delegations, super_list) {
if ( F_7 ( V_90 , & V_2 -> V_6 ) )
continue;
F_5 ( V_53 , & V_2 -> V_6 ) ;
}
}
void F_97 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
F_96 ( V_64 ) ;
F_12 () ;
}
void F_98 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_9 * V_9 ;
V_30:
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link) {
F_68 (delegation, &server->delegations,
super_list) {
if ( F_7 ( V_8 ,
& V_2 -> V_6 ) )
continue;
if ( F_7 ( V_53 ,
& V_2 -> V_6 ) == 0 )
continue;
if ( ! F_69 ( V_64 -> V_79 ) )
continue;
V_9 = F_39 ( V_2 ) ;
if ( V_9 == NULL ) {
F_12 () ;
F_70 ( V_64 -> V_79 ) ;
goto V_30;
}
V_2 = F_41 ( F_11 ( V_9 ) ) ;
F_12 () ;
if ( V_2 != NULL ) {
V_2 = F_50 ( F_11 ( V_9 ) ,
V_2 , V_64 ) ;
if ( V_2 != NULL )
F_1 ( V_2 ) ;
}
F_71 ( V_9 ) ;
F_70 ( V_64 -> V_79 ) ;
goto V_30;
}
}
F_12 () ;
}
static inline bool F_99 ( const struct V_55 * V_56 )
{
return ( V_56 -> V_59 & ( F_100 ( V_91 ) |
F_100 ( V_92 ) |
F_100 ( V_93 ) ) ) != 0 ;
}
static void F_101 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_18 . type == V_81 )
return;
F_34 ( V_53 , & V_2 -> V_6 ) ;
F_5 ( V_90 , & V_2 -> V_6 ) ;
F_5 ( V_94 , & V_64 -> V_55 -> V_59 ) ;
}
static void F_102 ( struct V_63 * V_64 ,
struct V_9 * V_9 )
{
struct V_1 * V_2 ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( V_2 )
F_101 ( V_64 , V_2 ) ;
F_12 () ;
}
static void F_103 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
F_68 (delegation, &server->delegations, super_list)
F_101 ( V_64 , V_2 ) ;
}
void F_104 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
F_103 ( V_64 ) ;
F_12 () ;
}
void F_105 ( struct V_55 * V_56 )
{
const struct V_95 * V_96 = V_56 -> V_84 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_9 * V_9 ;
struct V_46 * V_3 ;
T_2 V_18 ;
V_30:
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link) {
F_68 (delegation, &server->delegations,
super_list) {
if ( F_7 ( V_8 ,
& V_2 -> V_6 ) )
continue;
if ( F_7 ( V_90 ,
& V_2 -> V_6 ) == 0 )
continue;
if ( ! F_69 ( V_64 -> V_79 ) )
continue;
V_9 = F_39 ( V_2 ) ;
if ( V_9 == NULL ) {
F_12 () ;
F_70 ( V_64 -> V_79 ) ;
goto V_30;
}
V_3 = F_106 ( V_2 -> V_3 ) ;
F_32 ( & V_18 , & V_2 -> V_18 ) ;
F_34 ( V_90 , & V_2 -> V_6 ) ;
F_12 () ;
if ( V_3 != NULL &&
V_96 -> V_97 ( V_64 , & V_18 , V_3 ) < 0 ) {
F_86 ( V_9 , & V_18 ) ;
F_87 ( V_9 , & V_18 ) ;
}
F_2 ( V_3 ) ;
if ( F_99 ( V_56 ) ) {
F_102 ( V_64 , V_9 ) ;
F_71 ( V_9 ) ;
F_70 ( V_64 -> V_79 ) ;
return;
}
F_71 ( V_9 ) ;
F_70 ( V_64 -> V_79 ) ;
goto V_30;
}
}
F_12 () ;
}
void F_107 ( struct V_9 * V_9 ,
const T_2 * V_18 )
{
struct V_55 * V_56 = F_52 ( V_9 ) -> V_55 ;
struct V_1 * V_2 ;
bool V_98 = false ;
F_9 () ;
V_2 = F_10 ( F_11 ( V_9 ) -> V_2 ) ;
if ( V_2 &&
F_58 ( & V_2 -> V_18 , V_18 ) ) {
F_101 ( F_52 ( V_9 ) , V_2 ) ;
V_98 = true ;
}
F_12 () ;
if ( V_98 )
F_80 ( V_56 ) ;
}
int F_108 ( struct V_55 * V_56 )
{
struct V_63 * V_64 ;
int V_11 = 0 ;
F_9 () ;
F_68 (server, &clp->cl_superblocks, client_link)
if ( ! F_66 ( & V_64 -> V_76 ) ) {
V_11 = 1 ;
break;
}
F_12 () ;
return V_11 ;
}
bool F_109 ( struct V_9 * V_9 , T_1 V_6 ,
T_2 * V_99 , struct V_46 * * V_3 )
{
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_1 * V_2 ;
bool V_11 ;
V_6 &= V_12 | V_13 ;
F_9 () ;
V_2 = F_10 ( V_34 -> V_2 ) ;
V_11 = F_6 ( V_2 , V_6 ) ;
if ( V_11 ) {
F_32 ( V_99 , & V_2 -> V_18 ) ;
F_4 ( V_2 ) ;
if ( V_3 )
* V_3 = F_33 ( V_2 -> V_3 ) ;
}
F_12 () ;
return V_11 ;
}
bool F_110 ( const struct V_9 * V_9 )
{
struct V_33 * V_34 = F_11 ( V_9 ) ;
struct V_1 * V_2 ;
bool V_11 = true ;
F_9 () ;
V_2 = F_10 ( V_34 -> V_2 ) ;
if ( V_2 == NULL || ! ( V_2 -> type & V_13 ) )
goto V_27;
if ( F_111 ( & V_34 -> V_100 ) < V_2 -> V_52 )
V_11 = false ;
V_27:
F_12 () ;
return V_11 ;
}
