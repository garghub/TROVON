static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( ! V_2 && ! F_2 ( V_4 -> V_5 ) && ! V_4 -> V_6 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 -> V_7 , ! V_2 ) ;
F_4 ( V_4 -> V_8 , ! V_2 ) ;
if ( V_2 && ! F_2 ( V_4 -> V_5 ) && V_4 -> V_6 )
F_5 ( V_4 -> V_5 ) ;
V_4 -> V_6 = ! V_2 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
const struct V_11 * V_12 ;
V_12 = F_7 ( V_10 -> V_13 -> V_14 , V_10 ) ;
if ( ! V_12 )
return - V_15 ;
V_4 -> type = ( unsigned ) V_12 -> V_16 ;
return F_8 ( F_9 ( V_10 ) ,
V_17 ) ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 ;
const char * V_22 ;
int V_23 ;
V_4 = F_11 ( & V_19 -> V_10 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
F_12 ( & V_19 -> V_10 , L_1 , & V_4 -> V_26 ) ;
F_12 ( & V_19 -> V_10 , L_2 , & V_22 ) ;
if ( ! V_4 -> V_26 )
V_4 -> V_26 = F_13 ( & V_19 -> V_10 ) ;
V_4 -> type = F_14 ( V_22 ) ;
if ( F_15 ( & V_19 -> V_10 ) ) {
V_23 = F_6 ( & V_19 -> V_10 , V_4 ) ;
if ( V_23 )
return V_23 ;
}
V_4 -> V_5 = F_16 ( & V_19 -> V_10 , NULL ) ;
V_21 = F_17 ( & V_19 -> V_10 , L_3 , V_27 ) ;
if ( F_2 ( V_21 ) )
return F_18 ( V_21 ) ;
V_4 -> V_8 = V_21 ;
V_21 = F_17 ( & V_19 -> V_10 , L_4 , V_27 ) ;
if ( F_2 ( V_21 ) )
return F_18 ( V_21 ) ;
V_4 -> V_7 = V_21 ;
if ( ! V_4 -> V_8 && ! V_4 -> V_7 ) {
F_19 ( & V_19 -> V_10 , L_5 ) ;
return - V_28 ;
}
V_4 -> V_29 = F_20 ( V_4 -> V_26 , & V_19 -> V_10 ,
V_4 -> type , & V_30 ,
V_4 ) ;
if ( ! V_4 -> V_29 )
return - V_25 ;
V_23 = F_21 ( V_4 -> V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
F_22 ( V_19 , V_4 ) ;
F_23 ( & V_19 -> V_10 , L_6 , V_4 -> V_26 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_25 ( V_19 ) ;
F_26 ( V_4 -> V_29 ) ;
F_27 ( V_4 -> V_29 ) ;
F_28 ( F_9 ( & V_19 -> V_10 ) ) ;
return 0 ;
}
