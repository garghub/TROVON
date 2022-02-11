void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
int F_5 ( const struct V_2 * V_3 )
{
F_1 () ;
if ( V_4 [ V_3 -> V_5 ] ) {
F_3 () ;
return - V_6 ;
}
F_6 ( V_4 [ V_3 -> V_5 ] , V_3 ) ;
F_3 () ;
return 0 ;
}
int F_7 ( const struct V_2 * V_3 )
{
F_1 () ;
V_4 [ V_3 -> V_5 ] = NULL ;
F_3 () ;
F_8 () ;
return 0 ;
}
static inline const struct V_2 * F_9 ( T_1 type )
{
T_2 V_5 = F_10 ( type ) ;
if ( V_5 >= V_7 )
return NULL ;
return F_11 ( V_4 [ V_5 ] ) ;
}
static inline const struct V_8 *
F_12 ( T_1 type , const struct V_2 * V_9 )
{
T_2 V_10 = F_13 ( type ) ;
if ( V_10 >= V_9 -> V_11 )
return NULL ;
return & V_9 -> V_12 [ V_10 ] ;
}
int F_14 ( struct V_13 * V_13 , unsigned int V_14 )
{
return F_15 ( V_13 -> V_15 , V_14 ) ;
}
int F_16 ( struct V_16 * V_17 , struct V_13 * V_13 , T_3 V_18 ,
unsigned int V_14 , int V_19 , T_4 V_20 )
{
return F_17 ( V_13 -> V_15 , V_17 , V_18 , V_14 , V_19 , V_20 ) ;
}
int F_18 ( struct V_13 * V_13 , T_3 V_18 , T_3 V_14 , int error )
{
return F_19 ( V_13 -> V_15 , V_18 , V_14 , error ) ;
}
int F_20 ( struct V_16 * V_17 , struct V_13 * V_13 , T_5 V_18 , int V_20 )
{
return F_21 ( V_13 -> V_15 , V_17 , V_18 , V_20 ) ;
}
static int F_22 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_13 * V_13 = F_23 ( V_17 -> V_23 ) ;
const struct V_8 * V_24 ;
const struct V_2 * V_9 ;
int type , V_25 ;
if ( ! F_24 ( V_26 ) )
return - V_27 ;
if ( V_22 -> V_28 < F_25 ( sizeof( struct V_29 ) ) )
return 0 ;
type = V_22 -> V_30 ;
V_31:
F_26 () ;
V_9 = F_9 ( type ) ;
if ( ! V_9 ) {
#ifdef F_27
F_28 () ;
F_29 ( L_1 , F_10 ( type ) ) ;
F_26 () ;
V_9 = F_9 ( type ) ;
if ( ! V_9 )
#endif
{
F_28 () ;
return - V_32 ;
}
}
V_24 = F_12 ( type , V_9 ) ;
if ( ! V_24 ) {
F_28 () ;
return - V_32 ;
}
{
int V_33 = F_30 ( sizeof( struct V_29 ) ) ;
T_2 V_10 = F_13 ( V_22 -> V_30 ) ;
struct V_34 * V_35 [ V_9 -> V_12 [ V_10 ] . V_36 + 1 ] ;
struct V_34 * V_37 = ( void * ) V_22 + V_33 ;
int V_38 = V_22 -> V_28 - V_33 ;
V_25 = F_31 ( V_35 , V_9 -> V_12 [ V_10 ] . V_36 ,
V_37 , V_38 , V_9 -> V_12 [ V_10 ] . V_39 ) ;
if ( V_25 < 0 ) {
F_28 () ;
return V_25 ;
}
if ( V_24 -> V_40 ) {
V_25 = V_24 -> V_40 ( V_13 -> V_15 , V_17 , V_22 ,
( const struct V_34 * * ) V_35 ) ;
F_28 () ;
} else {
F_28 () ;
F_1 () ;
if ( F_32 (
V_4 [ F_10 ( type ) ] ,
F_33 ( & V_1 ) ) != V_9 ||
F_12 ( type , V_9 ) != V_24 )
V_25 = - V_41 ;
else if ( V_24 -> V_42 )
V_25 = V_24 -> V_42 ( V_13 -> V_15 , V_17 , V_22 ,
( const struct V_34 * * ) V_35 ) ;
else
V_25 = - V_32 ;
F_3 () ;
}
if ( V_25 == - V_41 )
goto V_31;
return V_25 ;
}
}
static void F_34 ( struct V_16 * V_17 )
{
F_35 ( V_17 , & F_22 ) ;
}
static void F_36 ( int V_14 )
{
const struct V_2 * V_9 ;
int type = V_43 [ V_14 ] ;
F_26 () ;
V_9 = F_9 ( type ) ;
if ( ! V_9 ) {
F_28 () ;
F_29 ( L_1 , type ) ;
return;
}
F_28 () ;
}
static int T_6 F_37 ( struct V_13 * V_13 )
{
struct V_44 * V_15 ;
struct V_45 V_46 = {
. V_47 = V_48 ,
. V_49 = F_34 ,
#ifdef F_27
. V_50 = F_36 ,
#endif
} ;
V_15 = F_38 ( V_13 , V_51 , & V_46 ) ;
if ( ! V_15 )
return - V_52 ;
V_13 -> V_53 = V_15 ;
F_6 ( V_13 -> V_15 , V_15 ) ;
return 0 ;
}
static void T_7 F_39 ( struct V_54 * V_55 )
{
struct V_13 * V_13 ;
F_40 (net, net_exit_list, exit_list)
F_41 ( V_13 -> V_15 , NULL ) ;
F_42 () ;
F_40 (net, net_exit_list, exit_list)
F_43 ( V_13 -> V_53 ) ;
}
static int T_8 F_44 ( void )
{
F_45 ( L_2 , V_56 ) ;
return F_46 ( & V_57 ) ;
}
static void T_9 F_47 ( void )
{
F_45 ( L_3 ) ;
F_48 ( & V_57 ) ;
}
