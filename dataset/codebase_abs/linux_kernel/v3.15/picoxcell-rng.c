static inline T_1 F_1 ( void )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline bool F_3 ( void )
{
return F_1 () & V_3 ;
}
static void F_4 ( void )
{
F_5 ( 0 , V_1 + V_4 ) ;
F_5 ( 0 , V_1 + V_2 ) ;
}
static void F_6 ( void )
{
F_5 ( V_5 , V_1 + V_2 ) ;
F_5 ( V_5 , V_1 + V_4 ) ;
F_4 () ;
}
static int F_7 ( struct V_6 * V_7 , void * V_8 , T_2 V_9 ,
bool V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 && F_3 () ; ++ V_11 ) {
if ( ! V_10 )
return 0 ;
F_8 ( 1 ) ;
}
if ( F_1 () & V_13 ) {
F_9 ( V_14 , L_1 ) ;
F_6 () ;
return - V_15 ;
}
if ( V_11 == V_12 )
return 0 ;
* ( T_1 * ) V_8 = F_2 ( V_1 + V_16 ) ;
return sizeof( T_1 ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_20 * V_21 = F_11 ( V_18 , V_22 , 0 ) ;
V_1 = F_12 ( & V_18 -> V_23 , V_21 ) ;
if ( F_13 ( V_1 ) )
return F_14 ( V_1 ) ;
V_24 = F_15 ( & V_18 -> V_23 , NULL ) ;
if ( F_13 ( V_24 ) ) {
F_16 ( & V_18 -> V_23 , L_2 ) ;
return F_14 ( V_24 ) ;
}
V_19 = F_17 ( V_24 ) ;
if ( V_19 ) {
F_16 ( & V_18 -> V_23 , L_3 ) ;
return V_19 ;
}
F_4 () ;
V_19 = F_18 ( & V_25 ) ;
if ( V_19 )
goto V_26;
V_14 = & V_18 -> V_23 ;
F_19 ( & V_18 -> V_23 , L_4 ) ;
return 0 ;
V_26:
F_20 ( V_24 ) ;
return V_19 ;
}
static int F_21 ( struct V_17 * V_18 )
{
F_22 ( & V_25 ) ;
F_20 ( V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_27 * V_23 )
{
F_20 ( V_24 ) ;
return 0 ;
}
static int F_24 ( struct V_27 * V_23 )
{
return F_17 ( V_24 ) ;
}
