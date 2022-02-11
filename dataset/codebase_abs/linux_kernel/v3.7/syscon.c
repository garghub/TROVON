static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_3 ;
return ( V_4 -> V_2 -> V_7 == V_6 ) ? 1 : 0 ;
}
struct V_8 * F_3 ( struct V_5 * V_9 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
V_2 = F_4 ( & V_10 . V_11 , NULL , V_9 ,
F_1 ) ;
if ( ! V_2 )
return F_5 ( - V_12 ) ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_8 ;
}
struct V_8 * F_6 ( const char * V_13 )
{
struct V_5 * V_14 ;
struct V_8 * V_8 ;
V_14 = F_7 ( NULL , NULL , V_13 ) ;
if ( ! V_14 )
return F_5 ( - V_15 ) ;
V_8 = F_3 ( V_14 ) ;
F_8 ( V_14 ) ;
return V_8 ;
}
struct V_8 * F_9 ( struct V_5 * V_9 ,
const char * V_16 )
{
struct V_5 * V_14 ;
struct V_8 * V_8 ;
V_14 = F_10 ( V_9 , V_16 , 0 ) ;
if ( ! V_14 )
return F_5 ( - V_15 ) ;
V_8 = F_3 ( V_14 ) ;
F_8 ( V_14 ) ;
return V_8 ;
}
static int T_1 F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_5 * V_9 = V_2 -> V_7 ;
struct V_4 * V_4 ;
struct V_19 V_20 ;
int V_21 ;
if ( ! V_9 )
return - V_22 ;
V_4 = F_12 ( V_2 , sizeof( struct V_4 ) ,
V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_25 = F_13 ( V_9 , 0 ) ;
if ( ! V_4 -> V_25 )
return - V_26 ;
V_21 = F_14 ( V_9 , 0 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_27 . V_28 = V_20 . V_29 - V_20 . V_30 - 3 ;
V_4 -> V_8 = F_15 ( V_2 , V_4 -> V_25 ,
& V_27 ) ;
if ( F_16 ( V_4 -> V_8 ) ) {
F_17 ( V_2 , L_1 ) ;
return F_18 ( V_4 -> V_8 ) ;
}
V_4 -> V_2 = V_2 ;
F_19 ( V_18 , V_4 ) ;
F_20 ( V_2 , L_2 ,
V_20 . V_30 , V_20 . V_29 ) ;
return 0 ;
}
static int T_2 F_21 ( struct V_17 * V_18 )
{
struct V_4 * V_4 ;
V_4 = F_22 ( V_18 ) ;
F_23 ( V_4 -> V_25 ) ;
F_19 ( V_18 , NULL ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_10 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_10 ) ;
}
