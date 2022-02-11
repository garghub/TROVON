static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_4 )
{
F_6 ( V_4 -> V_5 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_4 = F_8 ( V_7 , struct V_1 , V_6 ) ;
F_5 ( V_4 ) ;
}
static int
F_9 ( struct V_8 * V_8 , struct V_1 * V_2 , T_1 V_9 ,
T_1 V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_4 ;
int V_13 ;
if ( ! ( V_12 = F_10 ( V_9 ) ) )
return - V_14 ;
if ( ! V_12 -> V_15 )
return - V_16 ;
V_4 = F_11 ( V_2 , sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
F_12 ( & V_4 -> V_19 ) ;
F_12 ( & V_4 -> V_20 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_10 = F_13 ( V_10 ) ;
F_14 ( & V_4 -> V_21 , 0 ) ;
if ( V_2 -> V_22 ) {
V_4 -> V_5 =
F_15 ( V_2 -> V_22 ,
V_2 -> V_23 ) ;
if ( ! V_4 -> V_5 ) {
V_13 = - V_18 ;
goto V_24;
}
}
V_13 = V_12 -> V_25 ( V_8 , V_4 ) ;
if ( V_13 )
goto V_24;
F_16 ( & V_4 -> V_26 , & V_2 -> V_20 ) ;
F_17 ( 9 , L_1 ,
V_12 -> V_27 , V_4 -> V_27 , F_18 ( V_4 -> V_10 ) ) ;
return 0 ;
V_24:
F_5 ( V_4 ) ;
return V_13 ;
}
static void
F_19 ( struct V_8 * V_8 , struct V_1 * V_4 )
{
struct V_11 * V_12 ;
if ( ! ( V_12 = F_10 ( V_4 -> V_28 ) ) )
return;
if ( V_12 -> V_15 )
V_12 -> V_15 ( V_8 , V_4 ) ;
F_17 ( 9 , L_2 ,
V_12 -> V_27 , V_4 -> V_27 , F_18 ( V_4 -> V_10 ) ) ;
F_20 ( & V_4 -> V_26 ) ;
F_21 ( & V_4 -> V_6 , F_7 ) ;
}
int F_22 ( struct V_1 * V_4 )
{
int V_29 ;
V_29 = F_1 ( V_4 -> V_2 ) ;
if ( V_29 )
F_23 ( & V_4 -> V_21 ) ;
return V_29 ;
}
void F_24 ( struct V_1 * V_4 )
{
F_25 ( & V_4 -> V_21 ) ;
F_3 ( V_4 -> V_2 ) ;
}
int
F_26 ( struct V_8 * V_8 , struct V_1 * V_2 , T_1 V_9 ,
T_1 V_10 )
{
int V_29 ;
F_27 ( & V_30 ) ;
V_29 = F_9 ( V_8 , V_2 , V_9 , V_10 ) ;
F_28 ( & V_30 ) ;
return V_29 ;
}
struct V_1 * F_29 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_30 ( V_8 ) ;
struct V_1 * V_33 ;
int V_34 = 0 ;
if ( ! V_32 )
return F_31 ( - V_35 ) ;
F_27 ( & V_30 ) ;
F_32 (a, &ipvs->app_list, a_list) {
if ( ! strcmp ( V_2 -> V_27 , V_33 -> V_27 ) ) {
V_34 = - V_36 ;
goto V_37;
}
}
V_33 = F_11 ( V_2 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_33 ) {
V_34 = - V_18 ;
goto V_37;
}
F_12 ( & V_33 -> V_20 ) ;
F_16 ( & V_33 -> V_26 , & V_32 -> V_38 ) ;
F_33 () ;
V_37:
F_28 ( & V_30 ) ;
return V_34 ? F_31 ( V_34 ) : V_33 ;
}
void F_34 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_30 ( V_8 ) ;
struct V_1 * V_33 , * V_39 , * V_4 , * V_40 ;
if ( ! V_32 )
return;
F_27 ( & V_30 ) ;
F_35 (a, anxt, &ipvs->app_list, a_list) {
if ( V_2 && strcmp ( V_2 -> V_27 , V_33 -> V_27 ) )
continue;
F_35 (inc, nxt, &a->incs_list, a_list) {
F_19 ( V_8 , V_4 ) ;
}
F_20 ( & V_33 -> V_26 ) ;
F_6 ( V_33 ) ;
F_36 () ;
}
F_28 ( & V_30 ) ;
}
int F_37 ( struct V_41 * V_42 ,
struct V_11 * V_12 )
{
return V_12 -> V_43 ( V_42 ) ;
}
void F_38 ( struct V_41 * V_42 )
{
struct V_1 * V_4 = V_42 -> V_2 ;
if ( ! V_4 )
return;
if ( V_4 -> V_44 )
V_4 -> V_44 ( V_4 , V_42 ) ;
if ( V_4 -> V_45 )
V_4 -> V_45 ( V_4 , V_42 ) ;
F_24 ( V_4 ) ;
V_42 -> V_2 = NULL ;
}
static inline void F_39 ( const struct V_46 * V_47 , struct V_48 * V_49 )
{
T_2 V_50 = F_40 ( V_49 -> V_50 ) ;
if ( V_47 -> V_51 || V_47 -> V_52 ) {
if( F_41 ( V_50 , V_47 -> V_53 ) ) {
V_49 -> V_50 = F_42 ( V_50 + V_47 -> V_51 ) ;
F_17 ( 9 , L_3 ,
V_54 , V_47 -> V_51 ) ;
} else {
V_49 -> V_50 = F_42 ( V_50 + V_47 -> V_52 ) ;
F_17 ( 9 , L_4 ,
V_54 , V_47 -> V_52 ) ;
}
}
}
static inline void
F_43 ( const struct V_46 * V_47 , struct V_48 * V_49 )
{
T_2 V_55 = F_40 ( V_49 -> V_55 ) ;
if ( V_47 -> V_51 || V_47 -> V_52 ) {
if( F_41 ( V_55 , V_47 -> V_53 + V_47 -> V_51 ) ) {
V_49 -> V_55 = F_42 ( V_55 - V_47 -> V_51 ) ;
F_17 ( 9 , L_5
L_6 , V_54 , V_47 -> V_51 ) ;
} else {
V_49 -> V_55 = F_42 ( V_55 - V_47 -> V_52 ) ;
F_17 ( 9 , L_7
L_8 ,
V_54 , V_47 -> V_52 ) ;
}
}
}
static inline void F_44 ( struct V_41 * V_42 , struct V_46 * V_47 ,
unsigned int V_56 , T_2 V_50 , int V_57 )
{
F_45 ( & V_42 -> V_58 ) ;
if ( ! ( V_42 -> V_59 & V_56 ) || F_41 ( V_50 , V_47 -> V_53 ) ) {
V_47 -> V_52 = V_47 -> V_51 ;
V_47 -> V_51 += V_57 ;
V_47 -> V_53 = V_50 ;
V_42 -> V_59 |= V_56 ;
}
F_46 ( & V_42 -> V_58 ) ;
}
static inline int F_47 ( struct V_41 * V_42 , struct V_60 * V_61 ,
struct V_1 * V_2 )
{
int V_57 ;
const unsigned int V_62 = F_48 ( V_61 ) ;
struct V_48 * V_49 ;
T_2 V_50 ;
if ( ! F_49 ( V_61 , V_62 + sizeof( * V_49 ) ) )
return 0 ;
V_49 = (struct V_48 * ) ( F_50 ( V_61 ) + V_62 ) ;
V_50 = F_40 ( V_49 -> V_50 ) ;
if ( V_42 -> V_59 & V_63 )
F_39 ( & V_42 -> V_64 , V_49 ) ;
if ( V_42 -> V_59 & V_65 )
F_43 ( & V_42 -> V_66 , V_49 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
if ( ! V_2 -> V_67 ( V_2 , V_42 , V_61 , & V_57 ) )
return 0 ;
if ( V_57 != 0 )
F_44 ( V_42 , & V_42 -> V_64 ,
V_63 , V_50 , V_57 ) ;
return 1 ;
}
int F_51 ( struct V_41 * V_42 , struct V_60 * V_61 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_42 -> V_2 ) == NULL )
return 1 ;
if ( V_42 -> V_28 == V_68 )
return F_47 ( V_42 , V_61 , V_2 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
return V_2 -> V_67 ( V_2 , V_42 , V_61 , NULL ) ;
}
static inline int F_52 ( struct V_41 * V_42 , struct V_60 * V_61 ,
struct V_1 * V_2 )
{
int V_57 ;
const unsigned int V_62 = F_48 ( V_61 ) ;
struct V_48 * V_49 ;
T_2 V_50 ;
if ( ! F_49 ( V_61 , V_62 + sizeof( * V_49 ) ) )
return 0 ;
V_49 = (struct V_48 * ) ( F_50 ( V_61 ) + V_62 ) ;
V_50 = F_40 ( V_49 -> V_50 ) ;
if ( V_42 -> V_59 & V_65 )
F_39 ( & V_42 -> V_66 , V_49 ) ;
if ( V_42 -> V_59 & V_63 )
F_43 ( & V_42 -> V_64 , V_49 ) ;
if ( V_2 -> V_69 == NULL )
return 1 ;
if ( ! V_2 -> V_69 ( V_2 , V_42 , V_61 , & V_57 ) )
return 0 ;
if ( V_57 != 0 )
F_44 ( V_42 , & V_42 -> V_66 ,
V_65 , V_50 , V_57 ) ;
return 1 ;
}
int F_53 ( struct V_41 * V_42 , struct V_60 * V_61 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_42 -> V_2 ) == NULL )
return 1 ;
if ( V_42 -> V_28 == V_68 )
return F_52 ( V_42 , V_61 , V_2 ) ;
if ( V_2 -> V_69 == NULL )
return 1 ;
return V_2 -> V_69 ( V_2 , V_42 , V_61 , NULL ) ;
}
static struct V_1 * F_54 ( struct V_31 * V_32 , T_3 V_70 )
{
struct V_1 * V_2 , * V_4 ;
F_32 (app, &ipvs->app_list, a_list) {
F_32 (inc, &app->incs_list, a_list) {
if ( V_70 -- == 0 )
return V_4 ;
}
}
return NULL ;
}
static void * F_55 ( struct V_71 * V_50 , T_3 * V_70 )
{
struct V_8 * V_8 = F_56 ( V_50 ) ;
struct V_31 * V_32 = F_30 ( V_8 ) ;
F_27 ( & V_30 ) ;
return * V_70 ? F_54 ( V_32 , * V_70 - 1 ) : V_72 ;
}
static void * F_57 ( struct V_71 * V_50 , void * V_73 , T_3 * V_70 )
{
struct V_1 * V_4 , * V_2 ;
struct V_74 * V_75 ;
struct V_8 * V_8 = F_56 ( V_50 ) ;
struct V_31 * V_32 = F_30 ( V_8 ) ;
++ * V_70 ;
if ( V_73 == V_72 )
return F_54 ( V_32 , 0 ) ;
V_4 = V_73 ;
V_2 = V_4 -> V_2 ;
if ( ( V_75 = V_4 -> V_26 . V_76 ) != & V_2 -> V_20 )
return F_58 ( V_75 , struct V_1 , V_26 ) ;
for ( V_75 = V_2 -> V_26 . V_76 ; V_75 != & V_32 -> V_38 ; V_75 = V_75 -> V_76 ) {
V_2 = F_58 ( V_75 , struct V_1 , V_26 ) ;
F_32 (inc, &app->incs_list, a_list) {
return V_4 ;
}
}
return NULL ;
}
static void F_59 ( struct V_71 * V_50 , void * V_73 )
{
F_28 ( & V_30 ) ;
}
static int F_60 ( struct V_71 * V_50 , void * V_73 )
{
if ( V_73 == V_72 )
F_61 ( V_50 , L_9 ) ;
else {
const struct V_1 * V_4 = V_73 ;
F_62 ( V_50 , L_10 ,
F_63 ( V_4 -> V_28 ) ,
F_18 ( V_4 -> V_10 ) ,
F_64 ( & V_4 -> V_21 ) ,
V_4 -> V_27 ) ;
}
return 0 ;
}
static int F_65 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_66 ( V_77 , V_78 , & V_79 ,
sizeof( struct V_80 ) ) ;
}
int T_4 F_67 ( struct V_8 * V_8 )
{
struct V_31 * V_32 = F_30 ( V_8 ) ;
F_12 ( & V_32 -> V_38 ) ;
F_68 ( L_11 , 0 , V_8 -> V_81 , & V_82 ) ;
return 0 ;
}
void T_5 F_69 ( struct V_8 * V_8 )
{
F_34 ( V_8 , NULL ) ;
F_70 ( L_11 , V_8 -> V_81 ) ;
}
