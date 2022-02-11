static inline struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( V_2 ) ;
}
static int F_3 ( const struct V_2 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( F_4 ( V_4 , V_5 , V_1 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static struct V_2 * F_5 ( const struct V_8 * V_9 )
{
struct V_10 * V_10 = F_6 ( V_9 -> V_11 ) ;
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_1 * V_1 ;
struct V_14 * V_15 ;
struct V_2 * V_2 ;
struct V_12 * V_16 ;
T_1 V_17 ;
int V_18 ;
if ( ! V_13 ) {
V_18 = - V_19 ;
goto error;
}
V_16 = F_7 ( V_13 , V_5 ) ;
if ( V_16 && F_8 ( V_16 ) == sizeof( T_1 ) ) {
V_17 = F_9 ( V_16 ) ;
} else {
V_18 = - V_19 ;
goto error;
}
V_2 = F_10 ( sizeof( struct V_1 ) ,
& V_20 , V_9 ) ;
if ( F_11 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
V_1 -> V_6 = V_17 ;
F_12 () ;
V_15 = F_13 ( V_10 , V_9 -> V_21 , V_22 , V_17 ) ;
if ( F_11 ( V_15 ) ) {
F_14 () ;
F_15 ( V_2 ) ;
return F_16 ( V_15 ) ;
}
F_17 ( V_15 , V_15 -> V_23 | V_24 ) ;
F_14 () ;
return V_2 ;
error:
return F_18 ( V_18 ) ;
}
static struct V_2 * F_19 ( const struct V_8 * V_9 )
{
struct V_2 * V_2 ;
V_2 = F_5 ( V_9 ) ;
if ( F_11 ( V_2 ) )
return V_2 ;
return F_20 ( V_2 , V_9 -> V_21 ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_20 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_20 ) ;
}
