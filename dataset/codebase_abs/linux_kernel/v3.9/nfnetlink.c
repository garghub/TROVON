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
int F_16 ( struct V_17 * V_18 , struct V_14 * V_14 , T_4 V_19 ,
unsigned int V_15 , int V_20 , T_5 V_21 )
{
return F_17 ( V_14 -> V_16 , V_18 , V_19 , V_15 , V_20 , V_21 ) ;
}
int F_18 ( struct V_14 * V_14 , T_4 V_19 , T_4 V_15 , int error )
{
return F_19 ( V_14 -> V_16 , V_19 , V_15 , error ) ;
}
int F_20 ( struct V_17 * V_18 , struct V_14 * V_14 , T_6 V_19 , int V_21 )
{
return F_21 ( V_14 -> V_16 , V_18 , V_19 , V_21 ) ;
}
static int F_22 ( struct V_17 * V_18 , struct V_22 * V_23 )
{
struct V_14 * V_14 = F_23 ( V_18 -> V_24 ) ;
const struct V_9 * V_25 ;
const struct V_4 * V_10 ;
int type , V_26 ;
if ( ! F_24 ( V_14 -> V_27 , V_28 ) )
return - V_29 ;
if ( V_23 -> V_30 < F_25 ( sizeof( struct V_31 ) ) )
return 0 ;
type = V_23 -> V_32 ;
V_33:
F_26 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
#ifdef F_27
F_28 () ;
F_29 ( L_1 , F_10 ( type ) ) ;
F_26 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 )
#endif
{
F_28 () ;
return - V_34 ;
}
}
V_25 = F_12 ( type , V_10 ) ;
if ( ! V_25 ) {
F_28 () ;
return - V_34 ;
}
{
int V_35 = F_30 ( sizeof( struct V_31 ) ) ;
T_3 V_11 = F_13 ( V_23 -> V_32 ) ;
struct V_36 * V_37 [ V_10 -> V_13 [ V_11 ] . V_38 + 1 ] ;
struct V_36 * V_39 = ( void * ) V_23 + V_35 ;
int V_40 = V_23 -> V_30 - V_35 ;
T_1 V_1 = F_10 ( type ) ;
V_26 = F_31 ( V_37 , V_10 -> V_13 [ V_11 ] . V_38 ,
V_39 , V_40 , V_10 -> V_13 [ V_11 ] . V_41 ) ;
if ( V_26 < 0 ) {
F_28 () ;
return V_26 ;
}
if ( V_25 -> V_42 ) {
V_26 = V_25 -> V_42 ( V_14 -> V_16 , V_18 , V_23 ,
( const struct V_36 * * ) V_37 ) ;
F_28 () ;
} else {
F_28 () ;
F_1 ( V_1 ) ;
if ( F_32 ( V_2 [ V_1 ] . V_6 ,
F_33 ( & V_2 [ V_1 ] . V_3 ) ) != V_10 ||
F_12 ( type , V_10 ) != V_25 )
V_26 = - V_43 ;
else if ( V_25 -> V_44 )
V_26 = V_25 -> V_44 ( V_14 -> V_16 , V_18 , V_23 ,
( const struct V_36 * * ) V_37 ) ;
else
V_26 = - V_34 ;
F_3 ( V_1 ) ;
}
if ( V_26 == - V_43 )
goto V_33;
return V_26 ;
}
}
static void F_34 ( struct V_17 * V_18 )
{
F_35 ( V_18 , & F_22 ) ;
}
static void F_36 ( int V_15 )
{
const struct V_4 * V_10 ;
int type = V_45 [ V_15 ] ;
F_26 () ;
V_10 = F_9 ( type ) ;
if ( ! V_10 ) {
F_28 () ;
F_29 ( L_1 , type ) ;
return;
}
F_28 () ;
}
static int T_7 F_37 ( struct V_14 * V_14 )
{
struct V_46 * V_16 ;
struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 = F_34 ,
#ifdef F_27
. V_52 = F_36 ,
#endif
} ;
V_16 = F_38 ( V_14 , V_53 , & V_48 ) ;
if ( ! V_16 )
return - V_54 ;
V_14 -> V_55 = V_16 ;
F_6 ( V_14 -> V_16 , V_16 ) ;
return 0 ;
}
static void T_8 F_39 ( struct V_56 * V_57 )
{
struct V_14 * V_14 ;
F_40 (net, net_exit_list, exit_list)
F_41 ( V_14 -> V_16 , NULL ) ;
F_42 () ;
F_40 (net, net_exit_list, exit_list)
F_43 ( V_14 -> V_55 ) ;
}
static int T_9 F_44 ( void )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_8 ; V_58 ++ )
F_45 ( & V_2 [ V_58 ] . V_3 ) ;
F_46 ( L_2 , V_59 ) ;
return F_47 ( & V_60 ) ;
}
static void T_10 F_48 ( void )
{
F_46 ( L_3 ) ;
F_49 ( & V_60 ) ;
}
