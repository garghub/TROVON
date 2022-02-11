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
T_1 V_6 ;
int V_17 ;
if ( ! V_13 ) {
V_17 = - V_18 ;
goto error;
}
V_16 = F_7 ( V_13 , V_5 ) ;
if ( V_16 && F_8 ( V_16 ) == sizeof( T_1 ) ) {
V_6 = F_9 ( V_16 ) ;
} else {
V_17 = - V_18 ;
goto error;
}
V_2 = F_10 ( sizeof( struct V_1 ) ,
& V_19 , V_9 ) ;
if ( F_11 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
V_1 -> V_6 = V_6 ;
F_12 () ;
V_15 = F_13 ( V_10 , V_9 -> V_20 , V_21 , V_6 ) ;
if ( F_11 ( V_15 ) ) {
F_14 () ;
F_15 ( V_2 ) ;
return F_16 ( V_15 ) ;
}
V_17 = F_17 ( V_15 , V_15 -> V_22 | V_23 ) ;
if ( V_17 < 0 ) {
F_18 ( V_15 ) ;
F_14 () ;
F_15 ( V_2 ) ;
goto error;
}
F_14 () ;
return V_2 ;
error:
return F_19 ( V_17 ) ;
}
static struct V_2 * F_20 ( const struct V_8 * V_9 )
{
struct V_2 * V_2 ;
V_2 = F_5 ( V_9 ) ;
if ( F_11 ( V_2 ) )
return V_2 ;
return F_21 ( V_2 , V_9 -> V_20 ) ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_19 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_19 ) ;
}
