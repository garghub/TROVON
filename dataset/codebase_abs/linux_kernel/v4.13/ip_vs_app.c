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
F_9 ( struct V_8 * V_9 , struct V_1 * V_2 , T_1 V_10 ,
T_1 V_11 )
{
struct V_12 * V_13 ;
struct V_1 * V_4 ;
int V_14 ;
if ( ! ( V_13 = F_10 ( V_10 ) ) )
return - V_15 ;
if ( ! V_13 -> V_16 )
return - V_17 ;
V_4 = F_11 ( V_2 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
F_12 ( & V_4 -> V_20 ) ;
F_12 ( & V_4 -> V_21 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_11 = F_13 ( V_11 ) ;
F_14 ( & V_4 -> V_22 , 0 ) ;
if ( V_2 -> V_23 ) {
V_4 -> V_5 =
F_15 ( V_2 -> V_23 ,
V_2 -> V_24 ) ;
if ( ! V_4 -> V_5 ) {
V_14 = - V_19 ;
goto V_25;
}
}
V_14 = V_13 -> V_26 ( V_9 , V_4 ) ;
if ( V_14 )
goto V_25;
F_16 ( & V_4 -> V_27 , & V_2 -> V_21 ) ;
F_17 ( 9 , L_1 ,
V_13 -> V_28 , V_4 -> V_28 , F_18 ( V_4 -> V_11 ) ) ;
return 0 ;
V_25:
F_5 ( V_4 ) ;
return V_14 ;
}
static void
F_19 ( struct V_8 * V_9 , struct V_1 * V_4 )
{
struct V_12 * V_13 ;
if ( ! ( V_13 = F_10 ( V_4 -> V_29 ) ) )
return;
if ( V_13 -> V_16 )
V_13 -> V_16 ( V_9 , V_4 ) ;
F_17 ( 9 , L_2 ,
V_13 -> V_28 , V_4 -> V_28 , F_18 ( V_4 -> V_11 ) ) ;
F_20 ( & V_4 -> V_27 ) ;
F_21 ( & V_4 -> V_6 , F_7 ) ;
}
int F_22 ( struct V_1 * V_4 )
{
int V_30 ;
V_30 = F_1 ( V_4 -> V_2 ) ;
if ( V_30 )
F_23 ( & V_4 -> V_22 ) ;
return V_30 ;
}
void F_24 ( struct V_1 * V_4 )
{
F_25 ( & V_4 -> V_22 ) ;
F_3 ( V_4 -> V_2 ) ;
}
int
F_26 ( struct V_8 * V_9 , struct V_1 * V_2 , T_1 V_10 ,
T_1 V_11 )
{
int V_30 ;
F_27 ( & V_31 ) ;
V_30 = F_9 ( V_9 , V_2 , V_10 , V_11 ) ;
F_28 ( & V_31 ) ;
return V_30 ;
}
struct V_1 * F_29 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_1 * V_32 ;
int V_33 = 0 ;
F_27 ( & V_31 ) ;
F_30 (a, &ipvs->app_list, a_list) {
if ( ! strcmp ( V_2 -> V_28 , V_32 -> V_28 ) ) {
V_33 = - V_34 ;
goto V_35;
}
}
V_32 = F_11 ( V_2 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_32 ) {
V_33 = - V_19 ;
goto V_35;
}
F_12 ( & V_32 -> V_21 ) ;
F_16 ( & V_32 -> V_27 , & V_9 -> V_36 ) ;
F_31 () ;
V_35:
F_28 ( & V_31 ) ;
return V_33 ? F_32 ( V_33 ) : V_32 ;
}
void F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_1 * V_32 , * V_37 , * V_4 , * V_38 ;
F_27 ( & V_31 ) ;
F_34 (a, anxt, &ipvs->app_list, a_list) {
if ( V_2 && strcmp ( V_2 -> V_28 , V_32 -> V_28 ) )
continue;
F_34 (inc, nxt, &a->incs_list, a_list) {
F_19 ( V_9 , V_4 ) ;
}
F_20 ( & V_32 -> V_27 ) ;
F_6 ( V_32 ) ;
F_35 () ;
}
F_28 ( & V_31 ) ;
}
int F_36 ( struct V_39 * V_40 ,
struct V_12 * V_13 )
{
return V_13 -> V_41 ( V_40 ) ;
}
void F_37 ( struct V_39 * V_40 )
{
struct V_1 * V_4 = V_40 -> V_2 ;
if ( ! V_4 )
return;
if ( V_4 -> V_42 )
V_4 -> V_42 ( V_4 , V_40 ) ;
if ( V_4 -> V_43 )
V_4 -> V_43 ( V_4 , V_40 ) ;
F_24 ( V_4 ) ;
V_40 -> V_2 = NULL ;
}
static inline void F_38 ( const struct V_44 * V_45 , struct V_46 * V_47 )
{
T_2 V_48 = F_39 ( V_47 -> V_48 ) ;
if ( V_45 -> V_49 || V_45 -> V_50 ) {
if( F_40 ( V_48 , V_45 -> V_51 ) ) {
V_47 -> V_48 = F_41 ( V_48 + V_45 -> V_49 ) ;
F_17 ( 9 , L_3 ,
V_52 , V_45 -> V_49 ) ;
} else {
V_47 -> V_48 = F_41 ( V_48 + V_45 -> V_50 ) ;
F_17 ( 9 , L_4 ,
V_52 , V_45 -> V_50 ) ;
}
}
}
static inline void
F_42 ( const struct V_44 * V_45 , struct V_46 * V_47 )
{
T_2 V_53 = F_39 ( V_47 -> V_53 ) ;
if ( V_45 -> V_49 || V_45 -> V_50 ) {
if( F_40 ( V_53 , V_45 -> V_51 + V_45 -> V_49 ) ) {
V_47 -> V_53 = F_41 ( V_53 - V_45 -> V_49 ) ;
F_17 ( 9 , L_5
L_6 , V_52 , V_45 -> V_49 ) ;
} else {
V_47 -> V_53 = F_41 ( V_53 - V_45 -> V_50 ) ;
F_17 ( 9 , L_7
L_8 ,
V_52 , V_45 -> V_50 ) ;
}
}
}
static inline void F_43 ( struct V_39 * V_40 , struct V_44 * V_45 ,
unsigned int V_54 , T_2 V_48 , int V_55 )
{
F_44 ( & V_40 -> V_56 ) ;
if ( ! ( V_40 -> V_57 & V_54 ) || F_40 ( V_48 , V_45 -> V_51 ) ) {
V_45 -> V_50 = V_45 -> V_49 ;
V_45 -> V_49 += V_55 ;
V_45 -> V_51 = V_48 ;
V_40 -> V_57 |= V_54 ;
}
F_45 ( & V_40 -> V_56 ) ;
}
static inline int F_46 ( struct V_39 * V_40 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
int V_55 ;
const unsigned int V_60 = F_47 ( V_59 ) ;
struct V_46 * V_47 ;
T_2 V_48 ;
if ( ! F_48 ( V_59 , V_60 + sizeof( * V_47 ) ) )
return 0 ;
V_47 = (struct V_46 * ) ( F_49 ( V_59 ) + V_60 ) ;
V_48 = F_39 ( V_47 -> V_48 ) ;
if ( V_40 -> V_57 & V_61 )
F_38 ( & V_40 -> V_62 , V_47 ) ;
if ( V_40 -> V_57 & V_63 )
F_42 ( & V_40 -> V_64 , V_47 ) ;
if ( V_2 -> V_65 == NULL )
return 1 ;
if ( ! V_2 -> V_65 ( V_2 , V_40 , V_59 , & V_55 ) )
return 0 ;
if ( V_55 != 0 )
F_43 ( V_40 , & V_40 -> V_62 ,
V_61 , V_48 , V_55 ) ;
return 1 ;
}
int F_50 ( struct V_39 * V_40 , struct V_58 * V_59 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_40 -> V_2 ) == NULL )
return 1 ;
if ( V_40 -> V_29 == V_66 )
return F_46 ( V_40 , V_59 , V_2 ) ;
if ( V_2 -> V_65 == NULL )
return 1 ;
return V_2 -> V_65 ( V_2 , V_40 , V_59 , NULL ) ;
}
static inline int F_51 ( struct V_39 * V_40 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
int V_55 ;
const unsigned int V_60 = F_47 ( V_59 ) ;
struct V_46 * V_47 ;
T_2 V_48 ;
if ( ! F_48 ( V_59 , V_60 + sizeof( * V_47 ) ) )
return 0 ;
V_47 = (struct V_46 * ) ( F_49 ( V_59 ) + V_60 ) ;
V_48 = F_39 ( V_47 -> V_48 ) ;
if ( V_40 -> V_57 & V_63 )
F_38 ( & V_40 -> V_64 , V_47 ) ;
if ( V_40 -> V_57 & V_61 )
F_42 ( & V_40 -> V_62 , V_47 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
if ( ! V_2 -> V_67 ( V_2 , V_40 , V_59 , & V_55 ) )
return 0 ;
if ( V_55 != 0 )
F_43 ( V_40 , & V_40 -> V_64 ,
V_63 , V_48 , V_55 ) ;
return 1 ;
}
int F_52 ( struct V_39 * V_40 , struct V_58 * V_59 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_40 -> V_2 ) == NULL )
return 1 ;
if ( V_40 -> V_29 == V_66 )
return F_51 ( V_40 , V_59 , V_2 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
return V_2 -> V_67 ( V_2 , V_40 , V_59 , NULL ) ;
}
static struct V_1 * F_53 ( struct V_8 * V_9 , T_3 V_68 )
{
struct V_1 * V_2 , * V_4 ;
F_30 (app, &ipvs->app_list, a_list) {
F_30 (inc, &app->incs_list, a_list) {
if ( V_68 -- == 0 )
return V_4 ;
}
}
return NULL ;
}
static void * F_54 ( struct V_69 * V_48 , T_3 * V_68 )
{
struct V_70 * V_70 = F_55 ( V_48 ) ;
struct V_8 * V_9 = F_56 ( V_70 ) ;
F_27 ( & V_31 ) ;
return * V_68 ? F_53 ( V_9 , * V_68 - 1 ) : V_71 ;
}
static void * F_57 ( struct V_69 * V_48 , void * V_72 , T_3 * V_68 )
{
struct V_1 * V_4 , * V_2 ;
struct V_73 * V_74 ;
struct V_70 * V_70 = F_55 ( V_48 ) ;
struct V_8 * V_9 = F_56 ( V_70 ) ;
++ * V_68 ;
if ( V_72 == V_71 )
return F_53 ( V_9 , 0 ) ;
V_4 = V_72 ;
V_2 = V_4 -> V_2 ;
if ( ( V_74 = V_4 -> V_27 . V_75 ) != & V_2 -> V_21 )
return F_58 ( V_74 , struct V_1 , V_27 ) ;
for ( V_74 = V_2 -> V_27 . V_75 ; V_74 != & V_9 -> V_36 ; V_74 = V_74 -> V_75 ) {
V_2 = F_58 ( V_74 , struct V_1 , V_27 ) ;
F_30 (inc, &app->incs_list, a_list) {
return V_4 ;
}
}
return NULL ;
}
static void F_59 ( struct V_69 * V_48 , void * V_72 )
{
F_28 ( & V_31 ) ;
}
static int F_60 ( struct V_69 * V_48 , void * V_72 )
{
if ( V_72 == V_71 )
F_61 ( V_48 , L_9 ) ;
else {
const struct V_1 * V_4 = V_72 ;
F_62 ( V_48 , L_10 ,
F_63 ( V_4 -> V_29 ) ,
F_18 ( V_4 -> V_11 ) ,
F_64 ( & V_4 -> V_22 ) ,
V_4 -> V_28 ) ;
}
return 0 ;
}
static int F_65 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_66 ( V_76 , V_77 , & V_78 ,
sizeof( struct V_79 ) ) ;
}
int T_4 F_67 ( struct V_8 * V_9 )
{
F_12 ( & V_9 -> V_36 ) ;
F_68 ( L_11 , 0 , V_9 -> V_70 -> V_80 , & V_81 ) ;
return 0 ;
}
void T_5 F_69 ( struct V_8 * V_9 )
{
F_33 ( V_9 , NULL ) ;
F_70 ( L_11 , V_9 -> V_70 -> V_80 ) ;
}
