void F_1 ( T_1 V_1 )
{
F_2 ( & V_2 [ V_1 ] . V_3 ) ;
}
void F_3 ( T_1 V_1 )
{
F_4 ( & V_2 [ V_1 ] . V_3 ) ;
}
bool F_5 ( T_2 V_1 )
{
return F_6 ( & V_2 [ V_1 ] . V_3 ) ;
}
int F_7 ( const struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 ) ;
if ( V_2 [ V_5 -> V_1 ] . V_6 ) {
F_3 ( V_5 -> V_1 ) ;
return - V_7 ;
}
F_8 ( V_2 [ V_5 -> V_1 ] . V_6 , V_5 ) ;
F_3 ( V_5 -> V_1 ) ;
return 0 ;
}
int F_9 ( const struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 ) ;
V_2 [ V_5 -> V_1 ] . V_6 = NULL ;
F_3 ( V_5 -> V_1 ) ;
F_10 () ;
return 0 ;
}
static inline const struct V_4 * F_11 ( T_3 type )
{
T_4 V_1 = F_12 ( type ) ;
if ( V_1 >= V_8 )
return NULL ;
return F_13 ( V_2 [ V_1 ] . V_6 ) ;
}
static inline const struct V_9 *
F_14 ( T_3 type , const struct V_4 * V_10 )
{
T_4 V_11 = F_15 ( type ) ;
if ( V_11 >= V_10 -> V_12 )
return NULL ;
return & V_10 -> V_13 [ V_11 ] ;
}
int F_16 ( struct V_14 * V_14 , unsigned int V_15 )
{
return F_17 ( V_14 -> V_16 , V_15 ) ;
}
int F_18 ( struct V_17 * V_18 , struct V_14 * V_14 , T_5 V_19 ,
unsigned int V_15 , int V_20 , T_6 V_21 )
{
return F_19 ( V_14 -> V_16 , V_18 , V_19 , V_15 , V_20 , V_21 ) ;
}
int F_20 ( struct V_14 * V_14 , T_5 V_19 , T_5 V_15 , int error )
{
return F_21 ( V_14 -> V_16 , V_19 , V_15 , error ) ;
}
int F_22 ( struct V_17 * V_18 , struct V_14 * V_14 , T_5 V_19 ,
int V_21 )
{
return F_23 ( V_14 -> V_16 , V_18 , V_19 , V_21 ) ;
}
static int F_24 ( struct V_17 * V_18 , struct V_22 * V_23 )
{
struct V_14 * V_14 = F_25 ( V_18 -> V_24 ) ;
const struct V_9 * V_25 ;
const struct V_4 * V_10 ;
int type , V_26 ;
if ( F_26 ( V_23 ) < sizeof( struct V_27 ) )
return 0 ;
type = V_23 -> V_28 ;
V_29:
F_27 () ;
V_10 = F_11 ( type ) ;
if ( ! V_10 ) {
#ifdef F_28
F_29 () ;
F_30 ( L_1 , F_12 ( type ) ) ;
F_27 () ;
V_10 = F_11 ( type ) ;
if ( ! V_10 )
#endif
{
F_29 () ;
return - V_30 ;
}
}
V_25 = F_14 ( type , V_10 ) ;
if ( ! V_25 ) {
F_29 () ;
return - V_30 ;
}
{
int V_31 = F_31 ( sizeof( struct V_27 ) ) ;
T_4 V_11 = F_15 ( V_23 -> V_28 ) ;
struct V_32 * V_33 [ V_10 -> V_13 [ V_11 ] . V_34 + 1 ] ;
struct V_32 * V_35 = ( void * ) V_23 + V_31 ;
int V_36 = V_23 -> F_26 - V_31 ;
T_1 V_1 = F_12 ( type ) ;
V_26 = F_32 ( V_33 , V_10 -> V_13 [ V_11 ] . V_34 ,
V_35 , V_36 , V_10 -> V_13 [ V_11 ] . V_37 ) ;
if ( V_26 < 0 ) {
F_29 () ;
return V_26 ;
}
if ( V_25 -> V_38 ) {
V_26 = V_25 -> V_38 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_32 * * ) V_33 ) ;
F_29 () ;
} else {
F_29 () ;
F_1 ( V_1 ) ;
if ( F_33 ( V_1 ) != V_10 ||
F_14 ( type , V_10 ) != V_25 )
V_26 = - V_39 ;
else if ( V_25 -> V_40 )
V_26 = V_25 -> V_40 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_32 * * ) V_33 ) ;
else
V_26 = - V_30 ;
F_3 ( V_1 ) ;
}
if ( V_26 == - V_39 )
goto V_29;
return V_26 ;
}
}
static int F_34 ( struct V_41 * V_42 , struct V_22 * V_23 , int V_26 )
{
struct V_43 * V_43 ;
V_43 = F_35 ( sizeof( struct V_43 ) , V_44 ) ;
if ( V_43 == NULL )
return - V_45 ;
V_43 -> V_23 = V_23 ;
V_43 -> V_26 = V_26 ;
F_36 ( & V_43 -> V_46 , V_42 ) ;
return 0 ;
}
static void F_37 ( struct V_43 * V_43 )
{
F_38 ( & V_43 -> V_46 ) ;
F_39 ( V_43 ) ;
}
static void F_40 ( struct V_41 * V_47 )
{
struct V_43 * V_43 , * V_48 ;
F_41 (nfnl_err, next, err_list, head)
F_37 ( V_43 ) ;
}
static void F_42 ( struct V_41 * V_47 , struct V_17 * V_18 )
{
struct V_43 * V_43 , * V_48 ;
F_41 (nfnl_err, next, err_list, head) {
F_43 ( V_18 , V_43 -> V_23 , V_43 -> V_26 ) ;
F_37 ( V_43 ) ;
}
}
static void F_44 ( struct V_17 * V_18 , struct V_22 * V_23 ,
T_3 V_1 )
{
struct V_17 * V_49 = V_18 ;
struct V_14 * V_14 = F_25 ( V_18 -> V_24 ) ;
const struct V_4 * V_10 ;
const struct V_9 * V_25 ;
static F_45 ( V_47 ) ;
T_5 V_50 ;
int V_26 ;
if ( V_1 >= V_8 )
return F_43 ( V_18 , V_23 , - V_30 ) ;
V_29:
V_50 = 0 ;
V_18 = F_46 ( V_49 , V_44 ) ;
if ( ! V_18 )
return F_43 ( V_49 , V_23 , - V_45 ) ;
F_1 ( V_1 ) ;
V_10 = F_33 ( V_1 ) ;
if ( ! V_10 ) {
#ifdef F_28
F_3 ( V_1 ) ;
F_30 ( L_1 , V_1 ) ;
F_1 ( V_1 ) ;
V_10 = F_33 ( V_1 ) ;
if ( ! V_10 )
#endif
{
F_3 ( V_1 ) ;
F_43 ( V_49 , V_23 , - V_51 ) ;
return F_47 ( V_18 ) ;
}
}
if ( ! V_10 -> V_52 || ! V_10 -> abort ) {
F_3 ( V_1 ) ;
F_43 ( V_49 , V_23 , - V_51 ) ;
return F_47 ( V_18 ) ;
}
while ( V_18 -> V_53 >= F_31 ( 0 ) ) {
int V_54 , type ;
V_23 = F_48 ( V_18 ) ;
V_26 = 0 ;
if ( V_23 -> F_26 < V_55 ||
V_18 -> V_53 < V_23 -> F_26 ||
F_26 ( V_23 ) < sizeof( struct V_27 ) ) {
F_40 ( & V_47 ) ;
V_50 |= V_56 ;
goto V_57;
}
if ( ! ( V_23 -> V_58 & V_59 ) ) {
V_26 = - V_30 ;
goto V_60;
}
type = V_23 -> V_28 ;
if ( type == V_61 ) {
F_40 ( & V_47 ) ;
V_50 |= V_56 ;
goto V_57;
} else if ( type == V_62 ) {
V_50 |= V_63 ;
goto V_57;
} else if ( type < V_64 ) {
V_26 = - V_30 ;
goto V_60;
}
if ( F_12 ( type ) != V_1 ) {
V_26 = - V_30 ;
goto V_60;
}
V_25 = F_14 ( type , V_10 ) ;
if ( ! V_25 ) {
V_26 = - V_30 ;
goto V_60;
}
{
int V_31 = F_31 ( sizeof( struct V_27 ) ) ;
T_4 V_11 = F_15 ( V_23 -> V_28 ) ;
struct V_32 * V_33 [ V_10 -> V_13 [ V_11 ] . V_34 + 1 ] ;
struct V_32 * V_35 = ( void * ) V_23 + V_31 ;
int V_36 = V_23 -> F_26 - V_31 ;
V_26 = F_32 ( V_33 , V_10 -> V_13 [ V_11 ] . V_34 ,
V_35 , V_36 , V_10 -> V_13 [ V_11 ] . V_37 ) ;
if ( V_26 < 0 )
goto V_60;
if ( V_25 -> V_65 ) {
V_26 = V_25 -> V_65 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_32 * * ) V_33 ) ;
}
if ( V_26 == - V_39 ) {
V_50 |= V_66 ;
goto V_48;
}
}
V_60:
if ( V_23 -> V_58 & V_67 || V_26 ) {
if ( F_34 ( & V_47 , V_23 , V_26 ) < 0 ) {
F_40 ( & V_47 ) ;
F_43 ( V_49 , F_48 ( V_49 ) , - V_45 ) ;
V_50 |= V_56 ;
goto V_57;
}
if ( V_26 )
V_50 |= V_56 ;
}
V_48:
V_54 = F_49 ( V_23 -> F_26 ) ;
if ( V_54 > V_18 -> V_53 )
V_54 = V_18 -> V_53 ;
F_50 ( V_18 , V_54 ) ;
}
V_57:
if ( V_50 & V_66 ) {
V_10 -> abort ( V_14 , V_49 ) ;
F_40 ( & V_47 ) ;
F_3 ( V_1 ) ;
F_47 ( V_18 ) ;
goto V_29;
} else if ( V_50 == V_63 ) {
V_10 -> V_52 ( V_14 , V_49 ) ;
} else {
V_10 -> abort ( V_14 , V_49 ) ;
}
F_42 ( & V_47 , V_49 ) ;
F_3 ( V_1 ) ;
F_47 ( V_18 ) ;
}
static void F_51 ( struct V_17 * V_18 )
{
struct V_22 * V_23 = F_48 ( V_18 ) ;
T_3 V_68 ;
int V_54 ;
if ( V_23 -> F_26 < V_55 ||
V_18 -> V_53 < V_23 -> F_26 )
return;
if ( ! F_52 ( V_18 , V_69 ) ) {
F_43 ( V_18 , V_23 , - V_70 ) ;
return;
}
if ( V_23 -> V_28 == V_61 ) {
struct V_27 * V_27 ;
V_54 = F_49 ( V_23 -> F_26 ) ;
if ( V_54 > V_18 -> V_53 )
V_54 = V_18 -> V_53 ;
if ( V_23 -> F_26 < V_55 ||
V_18 -> V_53 < V_55 + sizeof( struct V_27 ) )
return;
V_27 = F_53 ( V_23 ) ;
F_50 ( V_18 , V_54 ) ;
if ( V_27 -> V_68 == V_71 )
V_68 = V_71 ;
else
V_68 = F_54 ( V_27 -> V_68 ) ;
F_44 ( V_18 , V_23 , V_68 ) ;
} else {
F_55 ( V_18 , & F_24 ) ;
}
}
static int F_56 ( struct V_14 * V_14 , int V_15 )
{
const struct V_4 * V_10 ;
int type ;
if ( V_15 <= V_72 || V_15 > V_73 )
return 0 ;
type = V_74 [ V_15 ] ;
F_27 () ;
V_10 = F_11 ( type << 8 ) ;
F_29 () ;
if ( ! V_10 )
F_30 ( L_1 , type ) ;
return 0 ;
}
static int T_7 F_57 ( struct V_14 * V_14 )
{
struct V_75 * V_16 ;
struct V_76 V_77 = {
. V_78 = V_73 ,
. V_79 = F_51 ,
#ifdef F_28
. V_80 = F_56 ,
#endif
} ;
V_16 = F_58 ( V_14 , V_81 , & V_77 ) ;
if ( ! V_16 )
return - V_45 ;
V_14 -> V_82 = V_16 ;
F_8 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_8 F_59 ( struct V_41 * V_83 )
{
struct V_14 * V_14 ;
F_60 (net, net_exit_list, exit_list)
F_61 ( V_14 -> V_16 , NULL ) ;
F_62 () ;
F_60 (net, net_exit_list, exit_list)
F_63 ( V_14 -> V_82 ) ;
}
static int T_9 F_64 ( void )
{
int V_84 ;
for ( V_84 = V_72 + 1 ; V_84 <= V_73 ; V_84 ++ )
F_65 ( V_74 [ V_84 ] == V_85 ) ;
for ( V_84 = 0 ; V_84 < V_8 ; V_84 ++ )
F_66 ( & V_2 [ V_84 ] . V_3 ) ;
F_67 ( L_2 , V_86 ) ;
return F_68 ( & V_87 ) ;
}
static void T_10 F_69 ( void )
{
F_67 ( L_3 ) ;
F_70 ( & V_87 ) ;
}
