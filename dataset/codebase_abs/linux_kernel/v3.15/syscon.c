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
return ! strcmp ( F_10 ( V_2 ) , ( const char * ) V_3 ) ;
}
struct V_7 * F_11 ( const char * V_13 )
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
struct V_7 * F_12 ( struct V_4 * V_8 ,
const char * V_16 )
{
struct V_4 * V_14 ;
struct V_7 * V_7 ;
V_14 = F_13 ( V_8 , V_16 , 0 ) ;
if ( ! V_14 )
return F_4 ( - V_15 ) ;
V_7 = F_2 ( V_14 ) ;
F_8 ( V_14 ) ;
return V_7 ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_9 * V_9 ;
struct V_19 * V_20 ;
void T_1 * V_21 ;
V_9 = F_15 ( V_2 , sizeof( * V_9 ) , V_22 ) ;
if ( ! V_9 )
return - V_23 ;
V_20 = F_16 ( V_18 , V_24 , 0 ) ;
if ( ! V_20 )
return - V_25 ;
V_21 = F_17 ( V_2 , V_20 -> V_26 , F_18 ( V_20 ) ) ;
if ( ! V_21 )
return - V_23 ;
V_27 . V_28 = V_20 -> V_29 - V_20 -> V_26 - 3 ;
V_9 -> V_7 = F_19 ( V_2 , V_21 ,
& V_27 ) ;
if ( F_20 ( V_9 -> V_7 ) ) {
F_21 ( V_2 , L_1 ) ;
return F_22 ( V_9 -> V_7 ) ;
}
F_23 ( V_18 , V_9 ) ;
F_24 ( V_2 , L_2 , V_20 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_10 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_10 ) ;
}
