static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( ! V_2 && ! F_2 ( V_4 -> V_5 ) && ! V_4 -> V_6 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 -> V_7 , ! V_2 ) ;
F_4 ( V_4 -> V_8 , ! V_2 ) ;
if ( V_2 && ! F_2 ( V_4 -> V_5 ) && V_4 -> V_6 )
F_5 ( V_4 -> V_5 ) ;
V_4 -> V_6 = V_2 ;
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
return 0 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_10 . V_22 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
int V_25 ;
V_4 = F_10 ( & V_19 -> V_10 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
if ( F_11 ( & V_19 -> V_10 ) ) {
V_25 = F_6 ( & V_19 -> V_10 , V_4 ) ;
if ( V_25 )
return V_25 ;
} else if ( V_21 ) {
V_4 -> V_16 = V_21 -> V_16 ;
V_4 -> type = V_21 -> type ;
} else {
return - V_15 ;
}
V_4 -> V_5 = F_12 ( & V_19 -> V_10 , NULL ) ;
V_24 = F_13 ( & V_19 -> V_10 , L_1 , 0 ) ;
if ( ! F_2 ( V_24 ) ) {
V_25 = F_14 ( V_24 , 0 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_8 = V_24 ;
}
V_24 = F_13 ( & V_19 -> V_10 , L_2 , 1 ) ;
if ( ! F_2 ( V_24 ) ) {
V_25 = F_14 ( V_24 , 0 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_7 = V_24 ;
}
if ( ( ! V_4 -> V_8 && ! V_4 -> V_7 ) || ! V_4 -> V_16 ) {
F_15 ( & V_19 -> V_10 , L_3 ) ;
return - V_28 ;
}
V_4 -> V_29 = F_16 ( V_4 -> V_16 , & V_19 -> V_10 ,
V_4 -> type , & V_30 ,
V_4 ) ;
if ( ! V_4 -> V_29 )
return - V_27 ;
V_25 = F_17 ( V_4 -> V_29 ) ;
if ( V_25 < 0 )
return V_25 ;
F_18 ( V_19 , V_4 ) ;
F_19 ( & V_19 -> V_10 , L_4 , V_4 -> V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_21 ( V_19 ) ;
F_22 ( V_4 -> V_29 ) ;
F_23 ( V_4 -> V_29 ) ;
return 0 ;
}
