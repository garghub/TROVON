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
V_4 -> V_16 = F_8 ( V_10 ) ;
V_4 -> type = ( unsigned ) V_12 -> V_17 ;
return F_9 ( F_10 ( V_10 ) ,
V_18 ) ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_10 . V_23 ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
int V_26 ;
V_4 = F_12 ( & V_20 -> V_10 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
if ( F_13 ( & V_20 -> V_10 ) ) {
V_26 = F_6 ( & V_20 -> V_10 , V_4 ) ;
if ( V_26 )
return V_26 ;
} else if ( V_22 ) {
V_4 -> V_16 = V_22 -> V_16 ;
V_4 -> type = V_22 -> type ;
} else {
return - V_15 ;
}
V_4 -> V_5 = F_14 ( & V_20 -> V_10 , NULL ) ;
V_25 = F_15 ( & V_20 -> V_10 , L_1 ) ;
if ( ! F_2 ( V_25 ) ) {
V_26 = F_16 ( V_25 , 0 ) ;
if ( V_26 )
return V_26 ;
V_4 -> V_8 = V_25 ;
}
V_25 = F_15 ( & V_20 -> V_10 , L_2 ) ;
if ( ! F_2 ( V_25 ) ) {
V_26 = F_16 ( V_25 , 0 ) ;
if ( V_26 )
return V_26 ;
V_4 -> V_7 = V_25 ;
}
if ( ( ! V_4 -> V_8 && ! V_4 -> V_7 ) || ! V_4 -> V_16 ) {
F_17 ( & V_20 -> V_10 , L_3 ) ;
return - V_29 ;
}
V_4 -> V_30 = F_18 ( V_4 -> V_16 , & V_20 -> V_10 ,
V_4 -> type , & V_31 ,
V_4 ) ;
if ( ! V_4 -> V_30 )
return - V_28 ;
V_26 = F_19 ( V_4 -> V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
F_20 ( V_20 , V_4 ) ;
F_21 ( & V_20 -> V_10 , L_4 , V_4 -> V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_23 ( V_20 ) ;
F_24 ( V_4 -> V_30 ) ;
F_25 ( V_4 -> V_30 ) ;
F_26 ( F_10 ( & V_20 -> V_10 ) ) ;
return 0 ;
}
