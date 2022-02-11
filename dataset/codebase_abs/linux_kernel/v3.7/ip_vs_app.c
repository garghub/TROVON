static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int
F_5 ( struct V_4 * V_4 , struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
int V_10 ;
if ( ! ( V_8 = F_6 ( V_5 ) ) )
return - V_11 ;
if ( ! V_8 -> V_12 )
return - V_13 ;
V_9 = F_7 ( V_2 , sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
F_8 ( & V_9 -> V_16 ) ;
F_8 ( & V_9 -> V_17 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = F_9 ( V_6 ) ;
F_10 ( & V_9 -> V_18 , 0 ) ;
if ( V_2 -> V_19 ) {
V_9 -> V_20 =
F_11 ( V_2 -> V_19 ,
V_2 -> V_21 ) ;
if ( ! V_9 -> V_20 ) {
V_10 = - V_15 ;
goto V_22;
}
}
V_10 = V_8 -> V_23 ( V_4 , V_9 ) ;
if ( V_10 )
goto V_22;
F_12 ( & V_9 -> V_24 , & V_2 -> V_17 ) ;
F_13 ( 9 , L_1 ,
V_8 -> V_25 , V_9 -> V_25 , F_14 ( V_9 -> V_6 ) ) ;
return 0 ;
V_22:
F_15 ( V_9 -> V_20 ) ;
F_15 ( V_9 ) ;
return V_10 ;
}
static void
F_16 ( struct V_4 * V_4 , struct V_1 * V_9 )
{
struct V_7 * V_8 ;
if ( ! ( V_8 = F_6 ( V_9 -> V_26 ) ) )
return;
if ( V_8 -> V_12 )
V_8 -> V_12 ( V_4 , V_9 ) ;
F_13 ( 9 , L_2 ,
V_8 -> V_25 , V_9 -> V_25 , F_14 ( V_9 -> V_6 ) ) ;
F_17 ( & V_9 -> V_24 ) ;
F_15 ( V_9 -> V_20 ) ;
F_15 ( V_9 ) ;
}
int F_18 ( struct V_1 * V_9 )
{
int V_27 ;
F_19 ( & V_9 -> V_18 ) ;
if ( F_20 ( ( V_27 = F_1 ( V_9 -> V_2 ) ) != 1 ) )
F_21 ( & V_9 -> V_18 ) ;
return V_27 ;
}
void F_22 ( struct V_1 * V_9 )
{
F_3 ( V_9 -> V_2 ) ;
F_21 ( & V_9 -> V_18 ) ;
}
int
F_23 ( struct V_4 * V_4 , struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 )
{
int V_27 ;
F_24 ( & V_28 ) ;
V_27 = F_5 ( V_4 , V_2 , V_5 , V_6 ) ;
F_25 ( & V_28 ) ;
return V_27 ;
}
struct V_1 * F_26 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_27 ( V_4 ) ;
struct V_1 * V_31 ;
int V_32 = 0 ;
if ( ! V_30 )
return F_28 ( - V_33 ) ;
F_24 ( & V_28 ) ;
F_29 (a, &ipvs->app_list, a_list) {
if ( ! strcmp ( V_2 -> V_25 , V_31 -> V_25 ) ) {
V_32 = - V_34 ;
goto V_35;
}
}
V_31 = F_7 ( V_2 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_31 ) {
V_32 = - V_15 ;
goto V_35;
}
F_8 ( & V_31 -> V_17 ) ;
F_12 ( & V_31 -> V_24 , & V_30 -> V_36 ) ;
F_30 () ;
V_35:
F_25 ( & V_28 ) ;
return V_32 ? F_28 ( V_32 ) : V_31 ;
}
void F_31 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_27 ( V_4 ) ;
struct V_1 * V_31 , * V_37 , * V_9 , * V_38 ;
if ( ! V_30 )
return;
F_24 ( & V_28 ) ;
F_32 (a, anxt, &ipvs->app_list, a_list) {
if ( V_2 && strcmp ( V_2 -> V_25 , V_31 -> V_25 ) )
continue;
F_32 (inc, nxt, &a->incs_list, a_list) {
F_16 ( V_4 , V_9 ) ;
}
F_17 ( & V_31 -> V_24 ) ;
F_15 ( V_31 ) ;
F_33 () ;
}
F_25 ( & V_28 ) ;
}
int F_34 ( struct V_39 * V_40 ,
struct V_7 * V_8 )
{
return V_8 -> V_41 ( V_40 ) ;
}
void F_35 ( struct V_39 * V_40 )
{
struct V_1 * V_9 = V_40 -> V_2 ;
if ( ! V_9 )
return;
if ( V_9 -> V_42 )
V_9 -> V_42 ( V_9 , V_40 ) ;
if ( V_9 -> V_43 )
V_9 -> V_43 ( V_9 , V_40 ) ;
F_22 ( V_9 ) ;
V_40 -> V_2 = NULL ;
}
static inline void F_36 ( const struct V_44 * V_45 , struct V_46 * V_47 )
{
T_2 V_48 = F_37 ( V_47 -> V_48 ) ;
if ( V_45 -> V_49 || V_45 -> V_50 ) {
if( F_38 ( V_48 , V_45 -> V_51 ) ) {
V_47 -> V_48 = F_39 ( V_48 + V_45 -> V_49 ) ;
F_13 ( 9 , L_3 ,
V_52 , V_45 -> V_49 ) ;
} else {
V_47 -> V_48 = F_39 ( V_48 + V_45 -> V_50 ) ;
F_13 ( 9 , L_4 ,
V_52 , V_45 -> V_50 ) ;
}
}
}
static inline void
F_40 ( const struct V_44 * V_45 , struct V_46 * V_47 )
{
T_2 V_53 = F_37 ( V_47 -> V_53 ) ;
if ( V_45 -> V_49 || V_45 -> V_50 ) {
if( F_38 ( V_53 , V_45 -> V_51 + V_45 -> V_49 ) ) {
V_47 -> V_53 = F_39 ( V_53 - V_45 -> V_49 ) ;
F_13 ( 9 , L_5
L_6 , V_52 , V_45 -> V_49 ) ;
} else {
V_47 -> V_53 = F_39 ( V_53 - V_45 -> V_50 ) ;
F_13 ( 9 , L_7
L_8 ,
V_52 , V_45 -> V_50 ) ;
}
}
}
static inline void F_41 ( struct V_39 * V_40 , struct V_44 * V_45 ,
unsigned int V_54 , T_2 V_48 , int V_55 )
{
F_42 ( & V_40 -> V_56 ) ;
if ( ! ( V_40 -> V_57 & V_54 ) || F_38 ( V_48 , V_45 -> V_51 ) ) {
V_45 -> V_50 = V_45 -> V_49 ;
V_45 -> V_49 += V_55 ;
V_45 -> V_51 = V_48 ;
V_40 -> V_57 |= V_54 ;
}
F_43 ( & V_40 -> V_56 ) ;
}
static inline int F_44 ( struct V_39 * V_40 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
int V_55 ;
const unsigned int V_60 = F_45 ( V_59 ) ;
struct V_46 * V_47 ;
T_2 V_48 ;
if ( ! F_46 ( V_59 , V_60 + sizeof( * V_47 ) ) )
return 0 ;
V_47 = (struct V_46 * ) ( F_47 ( V_59 ) + V_60 ) ;
V_48 = F_37 ( V_47 -> V_48 ) ;
if ( V_40 -> V_57 & V_61 )
F_36 ( & V_40 -> V_62 , V_47 ) ;
if ( V_40 -> V_57 & V_63 )
F_40 ( & V_40 -> V_64 , V_47 ) ;
if ( V_2 -> V_65 == NULL )
return 1 ;
if ( ! V_2 -> V_65 ( V_2 , V_40 , V_59 , & V_55 ) )
return 0 ;
if ( V_55 != 0 )
F_41 ( V_40 , & V_40 -> V_62 ,
V_61 , V_48 , V_55 ) ;
return 1 ;
}
int F_48 ( struct V_39 * V_40 , struct V_58 * V_59 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_40 -> V_2 ) == NULL )
return 1 ;
if ( V_40 -> V_26 == V_66 )
return F_44 ( V_40 , V_59 , V_2 ) ;
if ( V_2 -> V_65 == NULL )
return 1 ;
return V_2 -> V_65 ( V_2 , V_40 , V_59 , NULL ) ;
}
static inline int F_49 ( struct V_39 * V_40 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
int V_55 ;
const unsigned int V_60 = F_45 ( V_59 ) ;
struct V_46 * V_47 ;
T_2 V_48 ;
if ( ! F_46 ( V_59 , V_60 + sizeof( * V_47 ) ) )
return 0 ;
V_47 = (struct V_46 * ) ( F_47 ( V_59 ) + V_60 ) ;
V_48 = F_37 ( V_47 -> V_48 ) ;
if ( V_40 -> V_57 & V_63 )
F_36 ( & V_40 -> V_64 , V_47 ) ;
if ( V_40 -> V_57 & V_61 )
F_40 ( & V_40 -> V_62 , V_47 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
if ( ! V_2 -> V_67 ( V_2 , V_40 , V_59 , & V_55 ) )
return 0 ;
if ( V_55 != 0 )
F_41 ( V_40 , & V_40 -> V_64 ,
V_63 , V_48 , V_55 ) ;
return 1 ;
}
int F_50 ( struct V_39 * V_40 , struct V_58 * V_59 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_40 -> V_2 ) == NULL )
return 1 ;
if ( V_40 -> V_26 == V_66 )
return F_49 ( V_40 , V_59 , V_2 ) ;
if ( V_2 -> V_67 == NULL )
return 1 ;
return V_2 -> V_67 ( V_2 , V_40 , V_59 , NULL ) ;
}
static struct V_1 * F_51 ( struct V_29 * V_30 , T_3 V_68 )
{
struct V_1 * V_2 , * V_9 ;
F_29 (app, &ipvs->app_list, a_list) {
F_29 (inc, &app->incs_list, a_list) {
if ( V_68 -- == 0 )
return V_9 ;
}
}
return NULL ;
}
static void * F_52 ( struct V_69 * V_48 , T_3 * V_68 )
{
struct V_4 * V_4 = F_53 ( V_48 ) ;
struct V_29 * V_30 = F_27 ( V_4 ) ;
F_24 ( & V_28 ) ;
return * V_68 ? F_51 ( V_30 , * V_68 - 1 ) : V_70 ;
}
static void * F_54 ( struct V_69 * V_48 , void * V_71 , T_3 * V_68 )
{
struct V_1 * V_9 , * V_2 ;
struct V_72 * V_73 ;
struct V_4 * V_4 = F_53 ( V_48 ) ;
struct V_29 * V_30 = F_27 ( V_4 ) ;
++ * V_68 ;
if ( V_71 == V_70 )
return F_51 ( V_30 , 0 ) ;
V_9 = V_71 ;
V_2 = V_9 -> V_2 ;
if ( ( V_73 = V_9 -> V_24 . V_74 ) != & V_2 -> V_17 )
return F_55 ( V_73 , struct V_1 , V_24 ) ;
for ( V_73 = V_2 -> V_24 . V_74 ; V_73 != & V_30 -> V_36 ; V_73 = V_73 -> V_74 ) {
V_2 = F_55 ( V_73 , struct V_1 , V_24 ) ;
F_29 (inc, &app->incs_list, a_list) {
return V_9 ;
}
}
return NULL ;
}
static void F_56 ( struct V_69 * V_48 , void * V_71 )
{
F_25 ( & V_28 ) ;
}
static int F_57 ( struct V_69 * V_48 , void * V_71 )
{
if ( V_71 == V_70 )
F_58 ( V_48 , L_9 ) ;
else {
const struct V_1 * V_9 = V_71 ;
F_59 ( V_48 , L_10 ,
F_60 ( V_9 -> V_26 ) ,
F_14 ( V_9 -> V_6 ) ,
F_61 ( & V_9 -> V_18 ) ,
V_9 -> V_25 ) ;
}
return 0 ;
}
static int F_62 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
return F_63 ( V_75 , V_76 , & V_77 ,
sizeof( struct V_78 ) ) ;
}
int T_4 F_64 ( struct V_4 * V_4 )
{
struct V_29 * V_30 = F_27 ( V_4 ) ;
F_8 ( & V_30 -> V_36 ) ;
F_65 ( V_4 , L_11 , 0 , & V_79 ) ;
return 0 ;
}
void T_5 F_66 ( struct V_4 * V_4 )
{
F_31 ( V_4 , NULL ) ;
F_67 ( V_4 , L_11 ) ;
}
