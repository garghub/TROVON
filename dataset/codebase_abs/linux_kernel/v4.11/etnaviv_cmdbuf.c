struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return F_3 ( - V_7 ) ;
V_4 -> V_3 = V_3 ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = F_6 ( V_3 -> V_11 , V_12 ,
& V_4 -> V_13 , V_6 ) ;
if ( ! V_4 -> V_10 )
goto V_14;
V_5 = F_7 ( V_3 , V_4 -> V_13 ,
& V_4 -> V_15 , V_12 ,
& V_4 -> V_16 ) ;
if ( V_5 )
goto V_17;
return V_4 ;
V_17:
F_8 ( V_3 -> V_11 , V_12 , V_4 -> V_10 , V_4 -> V_13 ) ;
V_14:
F_9 ( V_4 ) ;
return NULL ;
}
void F_10 ( struct V_1 * V_4 )
{
F_11 ( V_4 -> V_3 , & V_4 -> V_15 ,
V_12 , V_4 -> V_16 ) ;
F_8 ( V_4 -> V_3 -> V_11 , V_12 , V_4 -> V_10 ,
V_4 -> V_13 ) ;
F_9 ( V_4 ) ;
}
struct V_18 *
F_12 ( struct V_1 * V_4 , T_1 V_19 ,
T_2 V_20 )
{
struct V_18 * V_21 ;
T_2 V_22 = F_13 ( V_20 , sizeof( V_21 -> V_23 [ 0 ] ) ,
sizeof( * V_21 ) ) ;
int V_24 , V_25 , V_5 ;
V_21 = F_2 ( V_22 , V_6 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_4 = V_4 ;
V_21 -> V_19 = V_19 ;
V_25 = F_14 ( F_15 ( V_19 , V_26 ) / V_26 ) ;
V_27:
F_16 ( & V_4 -> V_8 ) ;
V_24 = F_17 ( V_4 -> V_28 ,
V_29 , V_25 ) ;
if ( V_24 < 0 ) {
V_4 -> V_30 = 0 ;
F_18 ( & V_4 -> V_8 ) ;
V_5 = F_19 ( V_4 -> V_9 ,
V_4 -> V_30 ,
F_20 ( 10 * 1000 ) ) ;
if ( ! V_5 ) {
F_21 ( V_4 -> V_3 -> V_11 ,
L_1 ) ;
return NULL ;
}
goto V_27;
}
F_18 ( & V_4 -> V_8 ) ;
V_21 -> V_31 = V_24 * V_26 ;
V_21 -> V_10 = V_4 -> V_10 + V_21 -> V_31 ;
return V_21 ;
}
void F_22 ( struct V_18 * V_21 )
{
struct V_1 * V_4 = V_21 -> V_4 ;
int V_25 = F_14 ( F_15 ( V_21 -> V_19 , V_26 ) /
V_26 ) ;
F_16 ( & V_4 -> V_8 ) ;
F_23 ( V_4 -> V_28 ,
V_21 -> V_31 / V_26 ,
V_25 ) ;
V_4 -> V_30 = 1 ;
F_18 ( & V_4 -> V_8 ) ;
F_24 ( & V_4 -> V_9 ) ;
F_9 ( V_21 ) ;
}
T_1 F_25 ( struct V_18 * V_32 )
{
return V_32 -> V_4 -> V_16 + V_32 -> V_31 ;
}
T_3 F_26 ( struct V_18 * V_32 )
{
return V_32 -> V_4 -> V_13 + V_32 -> V_31 ;
}
