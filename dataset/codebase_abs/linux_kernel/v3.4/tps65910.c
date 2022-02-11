static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_4 )
{
return F_2 ( V_1 -> V_5 , V_2 , V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_6 )
{
return F_4 ( V_1 -> V_5 , V_2 , V_6 , V_3 ) ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 )
{
return F_6 ( V_1 -> V_5 , V_2 , V_7 , V_7 ) ;
}
int F_7 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 )
{
return F_6 ( V_1 -> V_5 , V_2 , V_7 , 0 ) ;
}
static bool F_8 ( struct V_8 * V_9 , unsigned int V_2 )
{
struct V_1 * V_1 = F_9 ( V_9 ) ;
if ( ( V_2 >= V_10 ) && ( V_2 <= V_11 ) ) {
if ( F_10 ( V_1 ) == V_12 )
if ( ( V_2 == V_13 ) ||
( V_2 == V_14 ) )
return true ;
return false ;
}
return true ;
}
static int F_11 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_1 * V_1 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
V_20 = F_12 ( & V_16 -> V_9 ) ;
if ( ! V_20 )
return - V_24 ;
V_22 = F_13 ( sizeof( struct V_21 ) , V_25 ) ;
if ( V_22 == NULL )
return - V_26 ;
V_1 = F_13 ( sizeof( struct V_1 ) , V_25 ) ;
if ( V_1 == NULL ) {
F_14 ( V_22 ) ;
return - V_26 ;
}
F_15 ( V_16 , V_1 ) ;
V_1 -> V_9 = & V_16 -> V_9 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_18 = V_18 -> V_27 ;
V_1 -> V_28 = F_1 ;
V_1 -> V_29 = F_3 ;
F_16 ( & V_1 -> V_30 ) ;
V_1 -> V_5 = F_17 ( V_16 , & V_31 ) ;
if ( F_18 ( V_1 -> V_5 ) ) {
V_23 = F_19 ( V_1 -> V_5 ) ;
F_20 ( & V_16 -> V_9 , L_1 , V_23 ) ;
goto V_32;
}
V_23 = F_21 ( V_1 -> V_9 , - 1 ,
V_33 , F_22 ( V_33 ) ,
NULL , 0 ) ;
if ( V_23 < 0 )
goto V_34;
V_22 -> V_35 = V_20 -> V_35 ;
V_22 -> V_36 = V_20 -> V_36 ;
F_23 ( V_1 , V_20 -> V_37 ) ;
F_24 ( V_1 , V_22 -> V_35 , V_22 ) ;
F_14 ( V_22 ) ;
return V_23 ;
V_34:
F_25 ( V_1 -> V_5 ) ;
V_32:
F_14 ( V_1 ) ;
F_14 ( V_22 ) ;
return V_23 ;
}
static int F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_27 ( V_16 ) ;
F_28 ( V_1 ) ;
F_29 ( V_1 -> V_9 ) ;
F_25 ( V_1 -> V_5 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_38 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_38 ) ;
}
