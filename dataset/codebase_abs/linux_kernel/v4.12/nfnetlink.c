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
T_2 V_1 = F_12 ( type ) ;
if ( V_1 >= V_8 )
return NULL ;
return F_13 ( V_2 [ V_1 ] . V_6 ) ;
}
static inline const struct V_9 *
F_14 ( T_3 type , const struct V_4 * V_10 )
{
T_2 V_11 = F_15 ( type ) ;
if ( V_11 >= V_10 -> V_12 )
return NULL ;
return & V_10 -> V_13 [ V_11 ] ;
}
int F_16 ( struct V_14 * V_14 , unsigned int V_15 )
{
return F_17 ( V_14 -> V_16 , V_15 ) ;
}
int F_18 ( struct V_17 * V_18 , struct V_14 * V_14 , T_4 V_19 ,
unsigned int V_15 , int V_20 , T_5 V_21 )
{
return F_19 ( V_14 -> V_16 , V_18 , V_19 , V_15 , V_20 , V_21 ) ;
}
int F_20 ( struct V_14 * V_14 , T_4 V_19 , T_4 V_15 , int error )
{
return F_21 ( V_14 -> V_16 , V_19 , V_15 , error ) ;
}
int F_22 ( struct V_17 * V_18 , struct V_14 * V_14 , T_4 V_19 ,
int V_21 )
{
return F_23 ( V_14 -> V_16 , V_18 , V_19 , V_21 ) ;
}
static int F_24 ( struct V_17 * V_18 , struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_14 * V_14 = F_25 ( V_18 -> V_26 ) ;
const struct V_9 * V_27 ;
const struct V_4 * V_10 ;
int type , V_28 ;
if ( F_26 ( V_23 ) < sizeof( struct V_29 ) )
return 0 ;
type = V_23 -> V_30 ;
V_31:
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
return - V_32 ;
}
}
V_27 = F_14 ( type , V_10 ) ;
if ( ! V_27 ) {
F_29 () ;
return - V_32 ;
}
{
int V_33 = F_31 ( sizeof( struct V_29 ) ) ;
T_2 V_11 = F_15 ( V_23 -> V_30 ) ;
struct V_34 * V_35 [ V_10 -> V_13 [ V_11 ] . V_36 + 1 ] ;
struct V_34 * V_37 = ( void * ) V_23 + V_33 ;
int V_38 = V_23 -> F_26 - V_33 ;
T_1 V_1 = F_12 ( type ) ;
V_28 = F_32 ( V_35 , V_10 -> V_13 [ V_11 ] . V_36 , V_37 , V_38 ,
V_10 -> V_13 [ V_11 ] . V_39 , V_25 ) ;
if ( V_28 < 0 ) {
F_29 () ;
return V_28 ;
}
if ( V_27 -> V_40 ) {
V_28 = V_27 -> V_40 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_34 * * ) V_35 ) ;
F_29 () ;
} else {
F_29 () ;
F_1 ( V_1 ) ;
if ( F_33 ( V_1 ) != V_10 ||
F_14 ( type , V_10 ) != V_27 )
V_28 = - V_41 ;
else if ( V_27 -> V_42 )
V_28 = V_27 -> V_42 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_34 * * ) V_35 ) ;
else
V_28 = - V_32 ;
F_3 ( V_1 ) ;
}
if ( V_28 == - V_41 )
goto V_31;
return V_28 ;
}
}
static int F_34 ( struct V_43 * V_44 , struct V_22 * V_23 , int V_28 )
{
struct V_45 * V_45 ;
V_45 = F_35 ( sizeof( struct V_45 ) , V_46 ) ;
if ( V_45 == NULL )
return - V_47 ;
V_45 -> V_23 = V_23 ;
V_45 -> V_28 = V_28 ;
F_36 ( & V_45 -> V_48 , V_44 ) ;
return 0 ;
}
static void F_37 ( struct V_45 * V_45 )
{
F_38 ( & V_45 -> V_48 ) ;
F_39 ( V_45 ) ;
}
static void F_40 ( struct V_43 * V_49 )
{
struct V_45 * V_45 , * V_50 ;
F_41 (nfnl_err, next, err_list, head)
F_37 ( V_45 ) ;
}
static void F_42 ( struct V_43 * V_49 , struct V_17 * V_18 )
{
struct V_45 * V_45 , * V_50 ;
F_41 (nfnl_err, next, err_list, head) {
F_43 ( V_18 , V_45 -> V_23 , V_45 -> V_28 , NULL ) ;
F_37 ( V_45 ) ;
}
}
static void F_44 ( struct V_17 * V_18 , struct V_22 * V_23 ,
T_3 V_1 , T_4 V_51 )
{
struct V_17 * V_52 = V_18 ;
struct V_14 * V_14 = F_25 ( V_18 -> V_26 ) ;
const struct V_4 * V_10 ;
const struct V_9 * V_27 ;
F_45 ( V_49 ) ;
T_4 V_53 ;
int V_28 ;
if ( V_1 >= V_8 )
return F_43 ( V_18 , V_23 , - V_32 , NULL ) ;
V_31:
V_53 = 0 ;
V_18 = F_46 ( V_52 , V_46 ) ;
if ( ! V_18 )
return F_43 ( V_52 , V_23 , - V_47 , NULL ) ;
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
F_43 ( V_52 , V_23 , - V_54 , NULL ) ;
return F_47 ( V_18 ) ;
}
}
if ( ! V_10 -> V_55 || ! V_10 -> abort ) {
F_3 ( V_1 ) ;
F_43 ( V_52 , V_23 , - V_54 , NULL ) ;
return F_47 ( V_18 ) ;
}
if ( V_51 && V_10 -> V_56 && ! V_10 -> V_56 ( V_14 , V_51 ) ) {
F_3 ( V_1 ) ;
F_43 ( V_52 , V_23 , - V_57 , NULL ) ;
return F_47 ( V_18 ) ;
}
while ( V_18 -> V_58 >= F_31 ( 0 ) ) {
int V_59 , type ;
V_23 = F_48 ( V_18 ) ;
V_28 = 0 ;
if ( V_23 -> F_26 < V_60 ||
V_18 -> V_58 < V_23 -> F_26 ||
F_26 ( V_23 ) < sizeof( struct V_29 ) ) {
F_40 ( & V_49 ) ;
V_53 |= V_61 ;
goto V_62;
}
if ( ! ( V_23 -> V_63 & V_64 ) ) {
V_28 = - V_32 ;
goto V_65;
}
type = V_23 -> V_30 ;
if ( type == V_66 ) {
F_40 ( & V_49 ) ;
V_53 |= V_61 ;
goto V_62;
} else if ( type == V_67 ) {
V_53 |= V_68 ;
goto V_62;
} else if ( type < V_69 ) {
V_28 = - V_32 ;
goto V_65;
}
if ( F_12 ( type ) != V_1 ) {
V_28 = - V_32 ;
goto V_65;
}
V_27 = F_14 ( type , V_10 ) ;
if ( ! V_27 ) {
V_28 = - V_32 ;
goto V_65;
}
{
int V_33 = F_31 ( sizeof( struct V_29 ) ) ;
T_2 V_11 = F_15 ( V_23 -> V_30 ) ;
struct V_34 * V_35 [ V_10 -> V_13 [ V_11 ] . V_36 + 1 ] ;
struct V_34 * V_37 = ( void * ) V_23 + V_33 ;
int V_38 = V_23 -> F_26 - V_33 ;
V_28 = F_32 ( V_35 , V_10 -> V_13 [ V_11 ] . V_36 , V_37 ,
V_38 , V_10 -> V_13 [ V_11 ] . V_39 , NULL ) ;
if ( V_28 < 0 )
goto V_65;
if ( V_27 -> V_70 ) {
V_28 = V_27 -> V_70 ( V_14 , V_14 -> V_16 , V_18 , V_23 ,
( const struct V_34 * * ) V_35 ) ;
}
if ( V_28 == - V_41 ) {
V_53 |= V_71 ;
goto V_50;
}
}
V_65:
if ( V_23 -> V_63 & V_72 || V_28 ) {
if ( F_34 ( & V_49 , V_23 , V_28 ) < 0 ) {
F_40 ( & V_49 ) ;
F_43 ( V_52 , F_48 ( V_52 ) , - V_47 ,
NULL ) ;
V_53 |= V_61 ;
goto V_62;
}
if ( V_28 )
V_53 |= V_61 ;
}
V_50:
V_59 = F_49 ( V_23 -> F_26 ) ;
if ( V_59 > V_18 -> V_58 )
V_59 = V_18 -> V_58 ;
F_50 ( V_18 , V_59 ) ;
}
V_62:
if ( V_53 & V_71 ) {
V_10 -> abort ( V_14 , V_52 ) ;
F_40 ( & V_49 ) ;
F_3 ( V_1 ) ;
F_47 ( V_18 ) ;
goto V_31;
} else if ( V_53 == V_68 ) {
V_10 -> V_55 ( V_14 , V_52 ) ;
} else {
V_10 -> abort ( V_14 , V_52 ) ;
}
F_42 ( & V_49 , V_52 ) ;
F_3 ( V_1 ) ;
F_47 ( V_18 ) ;
}
static void F_51 ( struct V_17 * V_18 , struct V_22 * V_23 )
{
int V_33 = F_31 ( sizeof( struct V_29 ) ) ;
struct V_34 * V_37 = ( void * ) V_23 + V_33 ;
struct V_34 * V_35 [ V_73 + 1 ] ;
int V_38 = V_23 -> F_26 - V_33 ;
struct V_29 * V_29 ;
int V_59 , V_28 ;
T_4 V_74 = 0 ;
T_3 V_75 ;
V_59 = F_49 ( V_23 -> F_26 ) ;
if ( V_59 > V_18 -> V_58 )
V_59 = V_18 -> V_58 ;
if ( V_23 -> F_26 < V_60 ||
V_18 -> V_58 < V_60 + sizeof( struct V_29 ) )
return;
V_28 = F_32 ( V_35 , V_73 , V_37 , V_38 , V_76 ,
NULL ) ;
if ( V_28 < 0 ) {
F_43 ( V_18 , V_23 , V_28 , NULL ) ;
return;
}
if ( V_35 [ V_77 ] )
V_74 = F_52 ( F_53 ( V_35 [ V_77 ] ) ) ;
V_29 = F_54 ( V_23 ) ;
F_50 ( V_18 , V_59 ) ;
if ( V_29 -> V_75 == V_78 )
V_75 = V_78 ;
else
V_75 = F_55 ( V_29 -> V_75 ) ;
F_44 ( V_18 , V_23 , V_75 , V_74 ) ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_22 * V_23 = F_48 ( V_18 ) ;
if ( V_23 -> F_26 < V_60 ||
V_18 -> V_58 < V_23 -> F_26 )
return;
if ( ! F_57 ( V_18 , V_79 ) ) {
F_43 ( V_18 , V_23 , - V_80 , NULL ) ;
return;
}
if ( V_23 -> V_30 == V_66 )
F_51 ( V_18 , V_23 ) ;
else
F_58 ( V_18 , F_24 ) ;
}
static int F_59 ( struct V_14 * V_14 , int V_15 )
{
const struct V_4 * V_10 ;
int type ;
if ( V_15 <= V_81 || V_15 > V_82 )
return 0 ;
type = V_83 [ V_15 ] ;
F_27 () ;
V_10 = F_11 ( type << 8 ) ;
F_29 () ;
if ( ! V_10 )
F_30 ( L_1 , type ) ;
return 0 ;
}
static int T_6 F_60 ( struct V_14 * V_14 )
{
struct V_84 * V_16 ;
struct V_85 V_86 = {
. V_87 = V_82 ,
. V_88 = F_56 ,
#ifdef F_28
. V_89 = F_59 ,
#endif
} ;
V_16 = F_61 ( V_14 , V_90 , & V_86 ) ;
if ( ! V_16 )
return - V_47 ;
V_14 -> V_91 = V_16 ;
F_8 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_7 F_62 ( struct V_43 * V_92 )
{
struct V_14 * V_14 ;
F_63 (net, net_exit_list, exit_list)
F_64 ( V_14 -> V_16 , NULL ) ;
F_65 () ;
F_63 (net, net_exit_list, exit_list)
F_66 ( V_14 -> V_91 ) ;
}
static int T_8 F_67 ( void )
{
int V_93 ;
for ( V_93 = V_81 + 1 ; V_93 <= V_82 ; V_93 ++ )
F_68 ( V_83 [ V_93 ] == V_94 ) ;
for ( V_93 = 0 ; V_93 < V_8 ; V_93 ++ )
F_69 ( & V_2 [ V_93 ] . V_3 ) ;
F_70 ( L_2 , V_95 ) ;
return F_71 ( & V_96 ) ;
}
static void T_9 F_72 ( void )
{
F_70 ( L_3 ) ;
F_73 ( & V_96 ) ;
}
