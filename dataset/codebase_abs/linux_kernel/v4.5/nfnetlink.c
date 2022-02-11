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
struct V_17 * F_18 ( struct V_14 * V_14 , unsigned int V_18 ,
T_5 V_19 , T_6 V_20 )
{
return F_19 ( V_14 -> V_16 , V_18 , V_19 , V_20 ) ;
}
int F_20 ( struct V_17 * V_21 , struct V_14 * V_14 , T_5 V_22 ,
unsigned int V_15 , int V_23 , T_6 V_24 )
{
return F_21 ( V_14 -> V_16 , V_21 , V_22 , V_15 , V_23 , V_24 ) ;
}
int F_22 ( struct V_14 * V_14 , T_5 V_22 , T_5 V_15 , int error )
{
return F_23 ( V_14 -> V_16 , V_22 , V_15 , error ) ;
}
int F_24 ( struct V_17 * V_21 , struct V_14 * V_14 , T_5 V_22 ,
int V_24 )
{
return F_25 ( V_14 -> V_16 , V_21 , V_22 , V_24 ) ;
}
static int F_26 ( struct V_17 * V_21 , struct V_25 * V_26 )
{
struct V_14 * V_14 = F_27 ( V_21 -> V_27 ) ;
const struct V_9 * V_28 ;
const struct V_4 * V_10 ;
int type , V_29 ;
if ( F_28 ( V_26 ) < sizeof( struct V_30 ) )
return 0 ;
type = V_26 -> V_31 ;
V_32:
F_29 () ;
V_10 = F_11 ( type ) ;
if ( ! V_10 ) {
#ifdef F_30
F_31 () ;
F_32 ( L_1 , F_12 ( type ) ) ;
F_29 () ;
V_10 = F_11 ( type ) ;
if ( ! V_10 )
#endif
{
F_31 () ;
return - V_33 ;
}
}
V_28 = F_14 ( type , V_10 ) ;
if ( ! V_28 ) {
F_31 () ;
return - V_33 ;
}
{
int V_34 = F_33 ( sizeof( struct V_30 ) ) ;
T_4 V_11 = F_15 ( V_26 -> V_31 ) ;
struct V_35 * V_36 [ V_10 -> V_13 [ V_11 ] . V_37 + 1 ] ;
struct V_35 * V_38 = ( void * ) V_26 + V_34 ;
int V_39 = V_26 -> F_28 - V_34 ;
T_1 V_1 = F_12 ( type ) ;
V_29 = F_34 ( V_36 , V_10 -> V_13 [ V_11 ] . V_37 ,
V_38 , V_39 , V_10 -> V_13 [ V_11 ] . V_40 ) ;
if ( V_29 < 0 ) {
F_31 () ;
return V_29 ;
}
if ( V_28 -> V_41 ) {
V_29 = V_28 -> V_41 ( V_14 , V_14 -> V_16 , V_21 , V_26 ,
( const struct V_35 * * ) V_36 ) ;
F_31 () ;
} else {
F_31 () ;
F_1 ( V_1 ) ;
if ( F_35 ( V_1 ) != V_10 ||
F_14 ( type , V_10 ) != V_28 )
V_29 = - V_42 ;
else if ( V_28 -> V_43 )
V_29 = V_28 -> V_43 ( V_14 , V_14 -> V_16 , V_21 , V_26 ,
( const struct V_35 * * ) V_36 ) ;
else
V_29 = - V_33 ;
F_3 ( V_1 ) ;
}
if ( V_29 == - V_42 )
goto V_32;
return V_29 ;
}
}
static int F_36 ( struct V_44 * V_45 , struct V_25 * V_26 , int V_29 )
{
struct V_46 * V_46 ;
V_46 = F_37 ( sizeof( struct V_46 ) , V_47 ) ;
if ( V_46 == NULL )
return - V_48 ;
V_46 -> V_26 = V_26 ;
V_46 -> V_29 = V_29 ;
F_38 ( & V_46 -> V_49 , V_45 ) ;
return 0 ;
}
static void F_39 ( struct V_46 * V_46 )
{
F_40 ( & V_46 -> V_49 ) ;
F_41 ( V_46 ) ;
}
static void F_42 ( struct V_44 * V_50 )
{
struct V_46 * V_46 , * V_51 ;
F_43 (nfnl_err, next, err_list, head)
F_39 ( V_46 ) ;
}
static void F_44 ( struct V_44 * V_50 , struct V_17 * V_21 )
{
struct V_46 * V_46 , * V_51 ;
F_43 (nfnl_err, next, err_list, head) {
F_45 ( V_21 , V_46 -> V_26 , V_46 -> V_29 ) ;
F_39 ( V_46 ) ;
}
}
static void F_46 ( struct V_17 * V_21 , struct V_25 * V_26 ,
T_3 V_1 )
{
struct V_17 * V_52 = V_21 ;
struct V_14 * V_14 = F_27 ( V_21 -> V_27 ) ;
const struct V_4 * V_10 ;
const struct V_9 * V_28 ;
static F_47 ( V_50 ) ;
T_5 V_53 ;
int V_29 ;
if ( V_1 >= V_8 )
return F_45 ( V_21 , V_26 , - V_33 ) ;
V_32:
V_53 = 0 ;
V_21 = F_48 ( V_52 , V_47 ) ;
if ( ! V_21 )
return F_45 ( V_52 , V_26 , - V_48 ) ;
F_1 ( V_1 ) ;
V_10 = F_35 ( V_1 ) ;
if ( ! V_10 ) {
#ifdef F_30
F_3 ( V_1 ) ;
F_32 ( L_1 , V_1 ) ;
F_1 ( V_1 ) ;
V_10 = F_35 ( V_1 ) ;
if ( ! V_10 )
#endif
{
F_3 ( V_1 ) ;
F_45 ( V_52 , V_26 , - V_54 ) ;
return F_49 ( V_21 ) ;
}
}
if ( ! V_10 -> V_55 || ! V_10 -> abort ) {
F_3 ( V_1 ) ;
F_45 ( V_52 , V_26 , - V_54 ) ;
return F_49 ( V_21 ) ;
}
while ( V_21 -> V_56 >= F_33 ( 0 ) ) {
int V_57 , type ;
V_26 = F_50 ( V_21 ) ;
V_29 = 0 ;
if ( V_26 -> F_28 < V_58 ||
V_21 -> V_56 < V_26 -> F_28 ||
F_28 ( V_26 ) < sizeof( struct V_30 ) ) {
F_42 ( & V_50 ) ;
V_53 |= V_59 ;
goto V_60;
}
if ( ! ( V_26 -> V_61 & V_62 ) ) {
V_29 = - V_33 ;
goto V_63;
}
type = V_26 -> V_31 ;
if ( type == V_64 ) {
F_42 ( & V_50 ) ;
V_53 |= V_59 ;
goto V_60;
} else if ( type == V_65 ) {
V_53 |= V_66 ;
goto V_60;
} else if ( type < V_67 ) {
V_29 = - V_33 ;
goto V_63;
}
if ( F_12 ( type ) != V_1 ) {
V_29 = - V_33 ;
goto V_63;
}
V_28 = F_14 ( type , V_10 ) ;
if ( ! V_28 ) {
V_29 = - V_33 ;
goto V_63;
}
{
int V_34 = F_33 ( sizeof( struct V_30 ) ) ;
T_4 V_11 = F_15 ( V_26 -> V_31 ) ;
struct V_35 * V_36 [ V_10 -> V_13 [ V_11 ] . V_37 + 1 ] ;
struct V_35 * V_38 = ( void * ) V_26 + V_34 ;
int V_39 = V_26 -> F_28 - V_34 ;
V_29 = F_34 ( V_36 , V_10 -> V_13 [ V_11 ] . V_37 ,
V_38 , V_39 , V_10 -> V_13 [ V_11 ] . V_40 ) ;
if ( V_29 < 0 )
goto V_63;
if ( V_28 -> V_68 ) {
V_29 = V_28 -> V_68 ( V_14 , V_14 -> V_16 , V_21 , V_26 ,
( const struct V_35 * * ) V_36 ) ;
}
if ( V_29 == - V_42 ) {
V_53 |= V_69 ;
goto V_51;
}
}
V_63:
if ( V_26 -> V_61 & V_70 || V_29 ) {
if ( F_36 ( & V_50 , V_26 , V_29 ) < 0 ) {
F_42 ( & V_50 ) ;
F_45 ( V_52 , F_50 ( V_52 ) , - V_48 ) ;
V_53 |= V_59 ;
goto V_60;
}
if ( V_29 )
V_53 |= V_59 ;
}
V_51:
V_57 = F_51 ( V_26 -> F_28 ) ;
if ( V_57 > V_21 -> V_56 )
V_57 = V_21 -> V_56 ;
F_52 ( V_21 , V_57 ) ;
}
V_60:
if ( V_53 & V_69 ) {
V_10 -> abort ( V_14 , V_52 ) ;
F_42 ( & V_50 ) ;
F_3 ( V_1 ) ;
F_49 ( V_21 ) ;
goto V_32;
} else if ( V_53 == V_66 ) {
V_10 -> V_55 ( V_14 , V_52 ) ;
} else {
V_10 -> abort ( V_14 , V_52 ) ;
}
F_44 ( & V_50 , V_52 ) ;
F_3 ( V_1 ) ;
F_49 ( V_21 ) ;
}
static void F_53 ( struct V_17 * V_21 )
{
struct V_25 * V_26 = F_50 ( V_21 ) ;
T_3 V_71 ;
int V_57 ;
if ( V_26 -> F_28 < V_58 ||
V_21 -> V_56 < V_26 -> F_28 )
return;
if ( ! F_54 ( V_21 , V_72 ) ) {
F_45 ( V_21 , V_26 , - V_73 ) ;
return;
}
if ( V_26 -> V_31 == V_64 ) {
struct V_30 * V_30 ;
V_57 = F_51 ( V_26 -> F_28 ) ;
if ( V_57 > V_21 -> V_56 )
V_57 = V_21 -> V_56 ;
if ( V_26 -> F_28 < V_58 ||
V_21 -> V_56 < V_58 + sizeof( struct V_30 ) )
return;
V_30 = F_55 ( V_26 ) ;
F_52 ( V_21 , V_57 ) ;
if ( V_30 -> V_71 == V_74 )
V_71 = V_74 ;
else
V_71 = F_56 ( V_30 -> V_71 ) ;
F_46 ( V_21 , V_26 , V_71 ) ;
} else {
F_57 ( V_21 , & F_26 ) ;
}
}
static int F_58 ( struct V_14 * V_14 , int V_15 )
{
const struct V_4 * V_10 ;
int type ;
if ( V_15 <= V_75 || V_15 > V_76 )
return 0 ;
type = V_77 [ V_15 ] ;
F_29 () ;
V_10 = F_11 ( type << 8 ) ;
F_31 () ;
if ( ! V_10 )
F_32 ( L_1 , type ) ;
return 0 ;
}
static int T_7 F_59 ( struct V_14 * V_14 )
{
struct V_78 * V_16 ;
struct V_79 V_80 = {
. V_81 = V_76 ,
. V_82 = F_53 ,
#ifdef F_30
. V_83 = F_58 ,
#endif
} ;
V_16 = F_60 ( V_14 , V_84 , & V_80 ) ;
if ( ! V_16 )
return - V_48 ;
V_14 -> V_85 = V_16 ;
F_8 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_8 F_61 ( struct V_44 * V_86 )
{
struct V_14 * V_14 ;
F_62 (net, net_exit_list, exit_list)
F_63 ( V_14 -> V_16 , NULL ) ;
F_64 () ;
F_62 (net, net_exit_list, exit_list)
F_65 ( V_14 -> V_85 ) ;
}
static int T_9 F_66 ( void )
{
int V_87 ;
for ( V_87 = V_75 + 1 ; V_87 <= V_76 ; V_87 ++ )
F_67 ( V_77 [ V_87 ] == V_88 ) ;
for ( V_87 = 0 ; V_87 < V_8 ; V_87 ++ )
F_68 ( & V_2 [ V_87 ] . V_3 ) ;
F_69 ( L_2 , V_89 ) ;
return F_70 ( & V_90 ) ;
}
static void T_10 F_71 ( void )
{
F_69 ( L_3 ) ;
F_72 ( & V_90 ) ;
}
