static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
return ( V_2 -> V_6 == V_5 ) ? 1 : 0 ;
}
struct V_7 * F_2 ( struct V_4 * V_8 )
{
struct V_9 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_3 ( & V_10 . V_11 , NULL , V_8 ,
F_1 ) ;
if ( ! V_2 )
return F_4 ( - V_12 ) ;
V_9 = F_5 ( V_2 ) ;
return V_9 -> V_7 ;
}
struct V_7 * F_6 ( const char * V_13 )
{
struct V_4 * V_14 ;
struct V_7 * V_7 ;
V_14 = F_7 ( NULL , NULL , V_13 ) ;
if ( ! V_14 )
return F_4 ( - V_15 ) ;
V_7 = F_2 ( V_14 ) ;
F_8 ( V_14 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_16 * V_17 = F_10 ( V_2 ) ;
const struct V_18 * V_19 = F_11 ( V_17 ) ;
if ( V_19 )
if ( ! strcmp ( V_19 -> V_20 , ( const char * ) V_3 ) )
return 1 ;
return ! strcmp ( F_12 ( V_2 ) , ( const char * ) V_3 ) ;
}
struct V_7 * F_13 ( const char * V_13 )
{
struct V_1 * V_2 ;
struct V_9 * V_9 ;
V_2 = F_3 ( & V_10 . V_11 , NULL , ( void * ) V_13 ,
F_9 ) ;
if ( ! V_2 )
return F_4 ( - V_12 ) ;
V_9 = F_5 ( V_2 ) ;
return V_9 -> V_7 ;
}
struct V_7 * F_14 ( struct V_4 * V_8 ,
const char * V_21 )
{
struct V_4 * V_14 ;
struct V_7 * V_7 ;
V_14 = F_15 ( V_8 , V_21 , 0 ) ;
if ( ! V_14 )
return F_4 ( - V_15 ) ;
V_7 = F_2 ( V_14 ) ;
F_8 ( V_14 ) ;
return V_7 ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = & V_17 -> V_2 ;
struct V_9 * V_9 ;
struct V_22 * V_23 ;
void T_1 * V_24 ;
V_9 = F_17 ( V_2 , sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 )
return - V_26 ;
V_23 = F_18 ( V_17 , V_27 , 0 ) ;
if ( ! V_23 )
return - V_28 ;
V_24 = F_19 ( V_2 , V_23 -> V_29 , F_20 ( V_23 ) ) ;
if ( ! V_24 )
return - V_26 ;
V_30 . V_31 = V_23 -> V_32 - V_23 -> V_29 - 3 ;
V_9 -> V_7 = F_21 ( V_2 , V_24 ,
& V_30 ) ;
if ( F_22 ( V_9 -> V_7 ) ) {
F_23 ( V_2 , L_1 ) ;
return F_24 ( V_9 -> V_7 ) ;
}
F_25 ( V_17 , V_9 ) ;
F_26 ( V_2 , L_2 , V_23 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_10 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_10 ) ;
}
