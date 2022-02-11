int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
unsigned int V_6 ;
V_5 = F_2 ( V_2 -> V_7 , V_3 , & V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_6 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_9 )
{
return F_5 ( V_2 -> V_7 , V_3 , V_4 , V_9 ) ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_7 ( V_2 -> V_7 , V_3 , V_4 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 , T_1 V_4 )
{
return F_9 ( V_2 -> V_7 , V_3 , V_10 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
return ( V_12 && V_12 -> V_13 ) ? V_12 -> V_13 ( V_2 ) : 0 ;
}
static int F_11 ( struct V_14 * V_15 , const struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 = V_15 -> V_8 . V_18 ;
int V_5 ;
V_2 = F_12 ( & V_15 -> V_8 , sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_7 = F_13 ( V_15 , & V_21 ) ;
if ( F_14 ( V_2 -> V_7 ) ) {
V_5 = F_15 ( V_2 -> V_7 ) ;
F_3 ( & V_15 -> V_8 , L_2 , V_5 ) ;
return V_5 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_8 = & V_15 -> V_8 ;
F_16 ( V_15 , V_2 ) ;
V_5 = F_10 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_17 ( V_2 , V_15 -> V_22 ) ;
if ( V_5 )
return V_5 ;
return F_18 ( V_2 -> V_8 , - 1 , V_23 ,
F_19 ( V_23 ) , NULL , 0 , NULL ) ;
}
static int F_20 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
F_22 ( V_2 -> V_8 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_24 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_24 ) ;
}
