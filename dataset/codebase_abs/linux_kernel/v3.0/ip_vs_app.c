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
int F_26 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_27 ( V_4 ) ;
F_28 () ;
F_24 ( & V_28 ) ;
F_12 ( & V_2 -> V_24 , & V_30 -> V_31 ) ;
F_25 ( & V_28 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_1 * V_9 , * V_32 ;
F_24 ( & V_28 ) ;
F_30 (inc, nxt, &app->incs_list, a_list) {
F_16 ( V_4 , V_9 ) ;
}
F_17 ( & V_2 -> V_24 ) ;
F_25 ( & V_28 ) ;
F_31 () ;
}
int F_32 ( struct V_33 * V_34 ,
struct V_7 * V_8 )
{
return V_8 -> V_35 ( V_34 ) ;
}
void F_33 ( struct V_33 * V_34 )
{
struct V_1 * V_9 = V_34 -> V_2 ;
if ( ! V_9 )
return;
if ( V_9 -> V_36 )
V_9 -> V_36 ( V_9 , V_34 ) ;
if ( V_9 -> V_37 )
V_9 -> V_37 ( V_9 , V_34 ) ;
F_22 ( V_9 ) ;
V_34 -> V_2 = NULL ;
}
static inline void F_34 ( const struct V_38 * V_39 , struct V_40 * V_41 )
{
T_2 V_42 = F_35 ( V_41 -> V_42 ) ;
if ( V_39 -> V_43 || V_39 -> V_44 ) {
if( F_36 ( V_42 , V_39 -> V_45 ) ) {
V_41 -> V_42 = F_37 ( V_42 + V_39 -> V_43 ) ;
F_13 ( 9 , L_3 ,
V_46 , V_39 -> V_43 ) ;
} else {
V_41 -> V_42 = F_37 ( V_42 + V_39 -> V_44 ) ;
F_13 ( 9 , L_4 ,
V_46 , V_39 -> V_44 ) ;
}
}
}
static inline void
F_38 ( const struct V_38 * V_39 , struct V_40 * V_41 )
{
T_2 V_47 = F_35 ( V_41 -> V_47 ) ;
if ( V_39 -> V_43 || V_39 -> V_44 ) {
if( F_36 ( V_47 , V_39 -> V_45 + V_39 -> V_43 ) ) {
V_41 -> V_47 = F_37 ( V_47 - V_39 -> V_43 ) ;
F_13 ( 9 , L_5
L_6 , V_46 , V_39 -> V_43 ) ;
} else {
V_41 -> V_47 = F_37 ( V_47 - V_39 -> V_44 ) ;
F_13 ( 9 , L_7
L_8 ,
V_46 , V_39 -> V_44 ) ;
}
}
}
static inline void F_39 ( struct V_33 * V_34 , struct V_38 * V_39 ,
unsigned V_48 , T_2 V_42 , int V_49 )
{
F_40 ( & V_34 -> V_50 ) ;
if ( ! ( V_34 -> V_51 & V_48 ) || F_36 ( V_42 , V_39 -> V_45 ) ) {
V_39 -> V_44 = V_39 -> V_43 ;
V_39 -> V_43 += V_49 ;
V_39 -> V_45 = V_42 ;
V_34 -> V_51 |= V_48 ;
}
F_41 ( & V_34 -> V_50 ) ;
}
static inline int F_42 ( struct V_33 * V_34 , struct V_52 * V_53 ,
struct V_1 * V_2 )
{
int V_49 ;
const unsigned int V_54 = F_43 ( V_53 ) ;
struct V_40 * V_41 ;
T_2 V_42 ;
if ( ! F_44 ( V_53 , V_54 + sizeof( * V_41 ) ) )
return 0 ;
V_41 = (struct V_40 * ) ( F_45 ( V_53 ) + V_54 ) ;
V_42 = F_35 ( V_41 -> V_42 ) ;
if ( V_34 -> V_51 & V_55 )
F_34 ( & V_34 -> V_56 , V_41 ) ;
if ( V_34 -> V_51 & V_57 )
F_38 ( & V_34 -> V_58 , V_41 ) ;
if ( V_2 -> V_59 == NULL )
return 1 ;
if ( ! V_2 -> V_59 ( V_2 , V_34 , V_53 , & V_49 ) )
return 0 ;
if ( V_49 != 0 )
F_39 ( V_34 , & V_34 -> V_56 ,
V_55 , V_42 , V_49 ) ;
return 1 ;
}
int F_46 ( struct V_33 * V_34 , struct V_52 * V_53 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_34 -> V_2 ) == NULL )
return 1 ;
if ( V_34 -> V_26 == V_60 )
return F_42 ( V_34 , V_53 , V_2 ) ;
if ( V_2 -> V_59 == NULL )
return 1 ;
return V_2 -> V_59 ( V_2 , V_34 , V_53 , NULL ) ;
}
static inline int F_47 ( struct V_33 * V_34 , struct V_52 * V_53 ,
struct V_1 * V_2 )
{
int V_49 ;
const unsigned int V_54 = F_43 ( V_53 ) ;
struct V_40 * V_41 ;
T_2 V_42 ;
if ( ! F_44 ( V_53 , V_54 + sizeof( * V_41 ) ) )
return 0 ;
V_41 = (struct V_40 * ) ( F_45 ( V_53 ) + V_54 ) ;
V_42 = F_35 ( V_41 -> V_42 ) ;
if ( V_34 -> V_51 & V_57 )
F_34 ( & V_34 -> V_58 , V_41 ) ;
if ( V_34 -> V_51 & V_55 )
F_38 ( & V_34 -> V_56 , V_41 ) ;
if ( V_2 -> V_61 == NULL )
return 1 ;
if ( ! V_2 -> V_61 ( V_2 , V_34 , V_53 , & V_49 ) )
return 0 ;
if ( V_49 != 0 )
F_39 ( V_34 , & V_34 -> V_58 ,
V_57 , V_42 , V_49 ) ;
return 1 ;
}
int F_48 ( struct V_33 * V_34 , struct V_52 * V_53 )
{
struct V_1 * V_2 ;
if ( ( V_2 = V_34 -> V_2 ) == NULL )
return 1 ;
if ( V_34 -> V_26 == V_60 )
return F_47 ( V_34 , V_53 , V_2 ) ;
if ( V_2 -> V_61 == NULL )
return 1 ;
return V_2 -> V_61 ( V_2 , V_34 , V_53 , NULL ) ;
}
static struct V_1 * F_49 ( struct V_29 * V_30 , T_3 V_62 )
{
struct V_1 * V_2 , * V_9 ;
F_50 (app, &ipvs->app_list, a_list) {
F_50 (inc, &app->incs_list, a_list) {
if ( V_62 -- == 0 )
return V_9 ;
}
}
return NULL ;
}
static void * F_51 ( struct V_63 * V_42 , T_3 * V_62 )
{
struct V_4 * V_4 = F_52 ( V_42 ) ;
struct V_29 * V_30 = F_27 ( V_4 ) ;
F_24 ( & V_28 ) ;
return * V_62 ? F_49 ( V_30 , * V_62 - 1 ) : V_64 ;
}
static void * F_53 ( struct V_63 * V_42 , void * V_65 , T_3 * V_62 )
{
struct V_1 * V_9 , * V_2 ;
struct V_66 * V_67 ;
struct V_4 * V_4 = F_52 ( V_42 ) ;
struct V_29 * V_30 = F_27 ( V_4 ) ;
++ * V_62 ;
if ( V_65 == V_64 )
return F_49 ( V_30 , 0 ) ;
V_9 = V_65 ;
V_2 = V_9 -> V_2 ;
if ( ( V_67 = V_9 -> V_24 . V_68 ) != & V_2 -> V_17 )
return F_54 ( V_67 , struct V_1 , V_24 ) ;
for ( V_67 = V_2 -> V_24 . V_68 ; V_67 != & V_30 -> V_31 ; V_67 = V_67 -> V_68 ) {
V_2 = F_54 ( V_67 , struct V_1 , V_24 ) ;
F_50 (inc, &app->incs_list, a_list) {
return V_9 ;
}
}
return NULL ;
}
static void F_55 ( struct V_63 * V_42 , void * V_65 )
{
F_25 ( & V_28 ) ;
}
static int F_56 ( struct V_63 * V_42 , void * V_65 )
{
if ( V_65 == V_64 )
F_57 ( V_42 , L_9 ) ;
else {
const struct V_1 * V_9 = V_65 ;
F_58 ( V_42 , L_10 ,
F_59 ( V_9 -> V_26 ) ,
F_14 ( V_9 -> V_6 ) ,
F_60 ( & V_9 -> V_18 ) ,
V_9 -> V_25 ) ;
}
return 0 ;
}
static int F_61 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_62 ( V_69 , V_70 , & V_71 ,
sizeof( struct V_72 ) ) ;
}
int T_4 F_63 ( struct V_4 * V_4 )
{
struct V_29 * V_30 = F_27 ( V_4 ) ;
F_8 ( & V_30 -> V_31 ) ;
F_64 ( V_4 , L_11 , 0 , & V_73 ) ;
return 0 ;
}
void T_5 F_65 ( struct V_4 * V_4 )
{
F_66 ( V_4 , L_11 ) ;
}
int T_6 F_67 ( void )
{
return 0 ;
}
void F_68 ( void )
{
}
