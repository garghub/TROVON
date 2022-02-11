void F_1 ( T_1 V_1 )
{
F_2 ( & V_2 [ V_1 ] . V_3 ) ;
}
void F_3 ( T_1 V_1 )
{
F_4 ( & V_2 [ V_1 ] . V_3 ) ;
}
int F_5 ( const struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 ) ;
if ( V_2 [ V_5 -> V_1 ] . V_6 ) {
F_3 ( V_5 -> V_1 ) ;
return - V_7 ;
}
F_6 ( V_2 [ V_5 -> V_1 ] . V_6 , V_5 ) ;
F_3 ( V_5 -> V_1 ) ;
return 0 ;
}
int F_7 ( const struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 ) ;
V_2 [ V_5 -> V_1 ] . V_6 = NULL ;
F_3 ( V_5 -> V_1 ) ;
F_8 () ;
return 0 ;
}
static inline const struct V_4 * F_9 ( T_2 type )
{
T_3 V_1 = F_10 ( type ) ;
if ( V_1 >= V_8 )
return NULL ;
return F_11 ( V_2 [ V_1 ] . V_6 ) ;
}
static inline const struct V_9 *
F_12 ( T_2 type , const struct V_4 * V_10 )
{
T_3 V_11 = F_13 ( type ) ;
if ( V_11 >= V_10 -> V_12 )
return NULL ;
return & V_10 -> V_13 [ V_11 ] ;
}
int F_14 ( struct V_14 * V_14 , unsigned int V_15 )
{
return F_15 ( V_14 -> V_16 , V_15 ) ;
}
struct V_17 * F_16 ( struct V_14 * V_14 , unsigned int V_18 ,
T_4 V_19 , T_5 V_20 )
{
return F_17 ( V_14 -> V_16 , V_18 , V_19 , V_20 ) ;
}
int F_18 ( struct V_17 * V_21 , struct V_14 * V_14 , T_4 V_22 ,
unsigned int V_15 , int V_23 , T_5 V_24 )
{
return F_19 ( V_14 -> V_16 , V_21 , V_22 , V_15 , V_23 , V_24 ) ;
}
int F_20 ( struct V_14 * V_14 , T_4 V_22 , T_4 V_15 , int error )
{
return F_21 ( V_14 -> V_16 , V_22 , V_15 , error ) ;
}
int F_22 ( struct V_17 * V_21 , struct V_14 * V_14 , T_4 V_22 ,
int V_24 )
{
return F_23 ( V_14 -> V_16 , V_21 , V_22 , V_24 ) ;
}
static int F_24 ( struct V_17 * V_21 , struct V_25 * V_26 )
{
struct V_14 * V_14 = F_25 ( V_21 -> V_27 ) ;
const struct V_9 * V_28 ;
const struct V_4 * V_10 ;
int type , V_29 ;
if ( F_26 ( V_26 ) < sizeof( struct V_30 ) )
return 0 ;
type = V_26 -> V_31 ;
V_32:
F_27 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
#ifdef F_28
F_29 () ;
F_30 ( L_1 , F_10 ( type ) ) ;
F_27 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 )
#endif
{
F_29 () ;
return - V_33 ;
}
}
V_28 = F_12 ( type , V_10 ) ;
if ( ! V_28 ) {
F_29 () ;
return - V_33 ;
}
{
int V_34 = F_31 ( sizeof( struct V_30 ) ) ;
T_3 V_11 = F_13 ( V_26 -> V_31 ) ;
struct V_35 * V_36 [ V_10 -> V_13 [ V_11 ] . V_37 + 1 ] ;
struct V_35 * V_38 = ( void * ) V_26 + V_34 ;
int V_39 = V_26 -> F_26 - V_34 ;
T_1 V_1 = F_10 ( type ) ;
V_29 = F_32 ( V_36 , V_10 -> V_13 [ V_11 ] . V_37 ,
V_38 , V_39 , V_10 -> V_13 [ V_11 ] . V_40 ) ;
if ( V_29 < 0 ) {
F_29 () ;
return V_29 ;
}
if ( V_28 -> V_41 ) {
V_29 = V_28 -> V_41 ( V_14 -> V_16 , V_21 , V_26 ,
( const struct V_35 * * ) V_36 ) ;
F_29 () ;
} else {
F_29 () ;
F_1 ( V_1 ) ;
if ( F_33 ( V_2 [ V_1 ] . V_6 ,
F_34 ( & V_2 [ V_1 ] . V_3 ) ) != V_10 ||
F_12 ( type , V_10 ) != V_28 )
V_29 = - V_42 ;
else if ( V_28 -> V_43 )
V_29 = V_28 -> V_43 ( V_14 -> V_16 , V_21 , V_26 ,
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
static void F_35 ( struct V_17 * V_21 , struct V_25 * V_26 ,
T_2 V_1 )
{
struct V_17 * V_44 , * V_45 = V_21 ;
struct V_14 * V_14 = F_25 ( V_21 -> V_27 ) ;
const struct V_4 * V_10 ;
const struct V_9 * V_28 ;
bool V_46 = true , V_47 = false ;
int V_29 ;
if ( V_1 >= V_8 )
return F_36 ( V_21 , V_26 , - V_33 ) ;
V_32:
V_44 = F_37 ( V_45 , V_48 ) ;
if ( ! V_44 )
return F_36 ( V_45 , V_26 , - V_49 ) ;
V_44 -> V_27 = V_45 -> V_27 ;
V_21 = V_44 ;
F_1 ( V_1 ) ;
V_10 = F_33 ( V_2 [ V_1 ] . V_6 ,
F_34 ( & V_2 [ V_1 ] . V_3 ) ) ;
if ( ! V_10 ) {
#ifdef F_28
F_3 ( V_1 ) ;
F_30 ( L_1 , V_1 ) ;
F_1 ( V_1 ) ;
V_10 = F_33 ( V_2 [ V_1 ] . V_6 ,
F_34 ( & V_2 [ V_1 ] . V_3 ) ) ;
if ( ! V_10 )
#endif
{
F_3 ( V_1 ) ;
F_38 ( V_44 ) ;
return F_36 ( V_21 , V_26 , - V_50 ) ;
}
}
if ( ! V_10 -> V_51 || ! V_10 -> abort ) {
F_3 ( V_1 ) ;
F_38 ( V_44 ) ;
return F_36 ( V_21 , V_26 , - V_50 ) ;
}
while ( V_21 -> V_52 >= F_31 ( 0 ) ) {
int V_53 , type ;
V_26 = F_39 ( V_21 ) ;
V_29 = 0 ;
if ( V_26 -> F_26 < V_54 ) {
V_29 = - V_33 ;
goto V_55;
}
if ( ! ( V_26 -> V_56 & V_57 ) ) {
V_29 = - V_33 ;
goto V_55;
}
type = V_26 -> V_31 ;
if ( type == V_58 ) {
V_46 = false ;
goto V_47;
} else if ( type == V_59 ) {
V_47 = true ;
goto V_47;
} else if ( type < V_60 ) {
V_29 = - V_33 ;
goto V_55;
}
if ( F_10 ( type ) != V_1 ) {
V_29 = - V_33 ;
goto V_55;
}
V_28 = F_12 ( type , V_10 ) ;
if ( ! V_28 ) {
V_29 = - V_33 ;
goto V_55;
}
{
int V_34 = F_31 ( sizeof( struct V_30 ) ) ;
T_3 V_11 = F_13 ( V_26 -> V_31 ) ;
struct V_35 * V_36 [ V_10 -> V_13 [ V_11 ] . V_37 + 1 ] ;
struct V_35 * V_38 = ( void * ) V_26 + V_34 ;
int V_39 = V_26 -> F_26 - V_34 ;
V_29 = F_32 ( V_36 , V_10 -> V_13 [ V_11 ] . V_37 ,
V_38 , V_39 , V_10 -> V_13 [ V_11 ] . V_40 ) ;
if ( V_29 < 0 )
goto V_55;
if ( V_28 -> V_61 ) {
V_29 = V_28 -> V_61 ( V_14 -> V_16 , V_21 , V_26 ,
( const struct V_35 * * ) V_36 ) ;
}
if ( V_29 == - V_42 ) {
V_10 -> abort ( V_21 ) ;
F_3 ( V_1 ) ;
F_38 ( V_44 ) ;
goto V_32;
}
}
V_55:
if ( V_26 -> V_56 & V_62 || V_29 ) {
F_36 ( V_21 , V_26 , V_29 ) ;
if ( V_29 )
V_46 = false ;
}
V_53 = F_40 ( V_26 -> F_26 ) ;
if ( V_53 > V_21 -> V_52 )
V_53 = V_21 -> V_52 ;
F_41 ( V_21 , V_53 ) ;
}
V_47:
if ( V_46 && V_47 )
V_10 -> V_51 ( V_21 ) ;
else
V_10 -> abort ( V_21 ) ;
F_3 ( V_1 ) ;
F_38 ( V_44 ) ;
}
static void F_42 ( struct V_17 * V_21 )
{
struct V_25 * V_26 = F_39 ( V_21 ) ;
struct V_14 * V_14 = F_25 ( V_21 -> V_27 ) ;
int V_53 ;
if ( V_26 -> F_26 < V_54 ||
V_21 -> V_52 < V_26 -> F_26 )
return;
if ( ! F_43 ( V_14 -> V_63 , V_64 ) ) {
F_36 ( V_21 , V_26 , - V_65 ) ;
return;
}
if ( V_26 -> V_31 == V_58 ) {
struct V_30 * V_30 ;
V_53 = F_40 ( V_26 -> F_26 ) ;
if ( V_53 > V_21 -> V_52 )
V_53 = V_21 -> V_52 ;
if ( V_26 -> F_26 < V_54 ||
V_21 -> V_52 < V_54 + sizeof( struct V_30 ) )
return;
V_30 = F_44 ( V_26 ) ;
F_41 ( V_21 , V_53 ) ;
F_35 ( V_21 , V_26 , V_30 -> V_66 ) ;
} else {
F_45 ( V_21 , & F_24 ) ;
}
}
static void F_46 ( int V_15 )
{
const struct V_4 * V_10 ;
int type = V_67 [ V_15 ] ;
F_27 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
F_29 () ;
F_30 ( L_1 , type ) ;
return;
}
F_29 () ;
}
static int T_6 F_47 ( struct V_14 * V_14 )
{
struct V_68 * V_16 ;
struct V_69 V_70 = {
. V_71 = V_72 ,
. V_73 = F_42 ,
#ifdef F_28
. V_74 = F_46 ,
#endif
} ;
V_16 = F_48 ( V_14 , V_75 , & V_70 ) ;
if ( ! V_16 )
return - V_49 ;
V_14 -> V_76 = V_16 ;
F_6 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_7 F_49 ( struct V_77 * V_78 )
{
struct V_14 * V_14 ;
F_50 (net, net_exit_list, exit_list)
F_51 ( V_14 -> V_16 , NULL ) ;
F_52 () ;
F_50 (net, net_exit_list, exit_list)
F_53 ( V_14 -> V_76 ) ;
}
static int T_8 F_54 ( void )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_8 ; V_79 ++ )
F_55 ( & V_2 [ V_79 ] . V_3 ) ;
F_56 ( L_2 , V_80 ) ;
return F_57 ( & V_81 ) ;
}
static void T_9 F_58 ( void )
{
F_56 ( L_3 ) ;
F_59 ( & V_81 ) ;
}
