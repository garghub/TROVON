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
V_4 [ V_3 -> V_5 ] = V_3 ;
F_3 () ;
return 0 ;
}
int F_6 ( const struct V_2 * V_3 )
{
F_1 () ;
V_4 [ V_3 -> V_5 ] = NULL ;
F_3 () ;
return 0 ;
}
static inline const struct V_2 * F_7 ( T_1 type )
{
T_2 V_5 = F_8 ( type ) ;
if ( V_5 >= V_7 )
return NULL ;
return V_4 [ V_5 ] ;
}
static inline const struct V_8 *
F_9 ( T_1 type , const struct V_2 * V_9 )
{
T_2 V_10 = F_10 ( type ) ;
if ( V_10 >= V_9 -> V_11 )
return NULL ;
return & V_9 -> V_12 [ V_10 ] ;
}
int F_11 ( struct V_13 * V_13 , unsigned int V_14 )
{
return F_12 ( V_13 -> V_15 , V_14 ) ;
}
int F_13 ( struct V_16 * V_17 , struct V_13 * V_13 , T_3 V_18 ,
unsigned V_14 , int V_19 , T_4 V_20 )
{
return F_14 ( V_13 -> V_15 , V_17 , V_18 , V_14 , V_19 , V_20 ) ;
}
int F_15 ( struct V_13 * V_13 , T_3 V_18 , T_3 V_14 , int error )
{
return F_16 ( V_13 -> V_15 , V_18 , V_14 , error ) ;
}
int F_17 ( struct V_16 * V_17 , struct V_13 * V_13 , T_5 V_18 , int V_20 )
{
return F_18 ( V_13 -> V_15 , V_17 , V_18 , V_20 ) ;
}
static int F_19 ( struct V_16 * V_17 , struct V_21 * V_22 )
{
struct V_13 * V_13 = F_20 ( V_17 -> V_23 ) ;
const struct V_8 * V_24 ;
const struct V_2 * V_9 ;
int type , V_25 ;
if ( F_21 ( V_17 , V_26 ) )
return - V_27 ;
if ( V_22 -> V_28 < F_22 ( sizeof( struct V_29 ) ) )
return 0 ;
type = V_22 -> V_30 ;
V_31:
V_9 = F_7 ( type ) ;
if ( ! V_9 ) {
#ifdef F_23
F_3 () ;
F_24 ( L_1 , F_8 ( type ) ) ;
F_1 () ;
V_9 = F_7 ( type ) ;
if ( ! V_9 )
#endif
return - V_32 ;
}
V_24 = F_9 ( type , V_9 ) ;
if ( ! V_24 )
return - V_32 ;
{
int V_33 = F_25 ( sizeof( struct V_29 ) ) ;
T_2 V_10 = F_10 ( V_22 -> V_30 ) ;
struct V_34 * V_35 [ V_9 -> V_12 [ V_10 ] . V_36 + 1 ] ;
struct V_34 * V_37 = ( void * ) V_22 + V_33 ;
int V_38 = V_22 -> V_28 - V_33 ;
V_25 = F_26 ( V_35 , V_9 -> V_12 [ V_10 ] . V_36 ,
V_37 , V_38 , V_9 -> V_12 [ V_10 ] . V_39 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = V_24 -> V_40 ( V_13 -> V_15 , V_17 , V_22 , ( const struct V_34 * * ) V_35 ) ;
if ( V_25 == - V_41 )
goto V_31;
return V_25 ;
}
}
static void F_27 ( struct V_16 * V_17 )
{
F_1 () ;
F_28 ( V_17 , & F_19 ) ;
F_3 () ;
}
static int T_6 F_29 ( struct V_13 * V_13 )
{
struct V_42 * V_15 ;
V_15 = F_30 ( V_13 , V_43 , V_44 ,
F_27 , NULL , V_45 ) ;
if ( ! V_15 )
return - V_46 ;
V_13 -> V_47 = V_15 ;
F_31 ( V_13 -> V_15 , V_15 ) ;
return 0 ;
}
static void T_7 F_32 ( struct V_48 * V_49 )
{
struct V_13 * V_13 ;
F_33 (net, net_exit_list, exit_list)
F_31 ( V_13 -> V_15 , NULL ) ;
F_34 () ;
F_33 (net, net_exit_list, exit_list)
F_35 ( V_13 -> V_47 ) ;
}
static int T_8 F_36 ( void )
{
F_37 ( L_2 , V_50 ) ;
return F_38 ( & V_51 ) ;
}
static void T_9 F_39 ( void )
{
F_37 ( L_3 ) ;
F_40 ( & V_51 ) ;
}
