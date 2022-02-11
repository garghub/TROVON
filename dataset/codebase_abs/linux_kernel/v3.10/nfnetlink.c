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
if ( ! F_26 ( V_14 -> V_30 , V_31 ) )
return - V_32 ;
if ( F_27 ( V_26 ) < sizeof( struct V_33 ) )
return 0 ;
type = V_26 -> V_34 ;
V_35:
F_28 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
#ifdef F_29
F_30 () ;
F_31 ( L_1 , F_10 ( type ) ) ;
F_28 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 )
#endif
{
F_30 () ;
return - V_36 ;
}
}
V_28 = F_12 ( type , V_10 ) ;
if ( ! V_28 ) {
F_30 () ;
return - V_36 ;
}
{
int V_37 = F_32 ( sizeof( struct V_33 ) ) ;
T_3 V_11 = F_13 ( V_26 -> V_34 ) ;
struct V_38 * V_39 [ V_10 -> V_13 [ V_11 ] . V_40 + 1 ] ;
struct V_38 * V_41 = ( void * ) V_26 + V_37 ;
int V_42 = V_26 -> F_27 - V_37 ;
T_1 V_1 = F_10 ( type ) ;
V_29 = F_33 ( V_39 , V_10 -> V_13 [ V_11 ] . V_40 ,
V_41 , V_42 , V_10 -> V_13 [ V_11 ] . V_43 ) ;
if ( V_29 < 0 ) {
F_30 () ;
return V_29 ;
}
if ( V_28 -> V_44 ) {
V_29 = V_28 -> V_44 ( V_14 -> V_16 , V_21 , V_26 ,
( const struct V_38 * * ) V_39 ) ;
F_30 () ;
} else {
F_30 () ;
F_1 ( V_1 ) ;
if ( F_34 ( V_2 [ V_1 ] . V_6 ,
F_35 ( & V_2 [ V_1 ] . V_3 ) ) != V_10 ||
F_12 ( type , V_10 ) != V_28 )
V_29 = - V_45 ;
else if ( V_28 -> V_46 )
V_29 = V_28 -> V_46 ( V_14 -> V_16 , V_21 , V_26 ,
( const struct V_38 * * ) V_39 ) ;
else
V_29 = - V_36 ;
F_3 ( V_1 ) ;
}
if ( V_29 == - V_45 )
goto V_35;
return V_29 ;
}
}
static void F_36 ( struct V_17 * V_21 )
{
F_37 ( V_21 , & F_24 ) ;
}
static void F_38 ( int V_15 )
{
const struct V_4 * V_10 ;
int type = V_47 [ V_15 ] ;
F_28 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
F_30 () ;
F_31 ( L_1 , type ) ;
return;
}
F_30 () ;
}
static int T_6 F_39 ( struct V_14 * V_14 )
{
struct V_48 * V_16 ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_53 = F_36 ,
#ifdef F_29
. V_54 = F_38 ,
#endif
} ;
V_16 = F_40 ( V_14 , V_55 , & V_50 ) ;
if ( ! V_16 )
return - V_56 ;
V_14 -> V_57 = V_16 ;
F_6 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_7 F_41 ( struct V_58 * V_59 )
{
struct V_14 * V_14 ;
F_42 (net, net_exit_list, exit_list)
F_43 ( V_14 -> V_16 , NULL ) ;
F_44 () ;
F_42 (net, net_exit_list, exit_list)
F_45 ( V_14 -> V_57 ) ;
}
static int T_8 F_46 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_8 ; V_60 ++ )
F_47 ( & V_2 [ V_60 ] . V_3 ) ;
F_48 ( L_2 , V_61 ) ;
return F_49 ( & V_62 ) ;
}
static void T_9 F_50 ( void )
{
F_48 ( L_3 ) ;
F_51 ( & V_62 ) ;
}
