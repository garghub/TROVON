static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
V_5 = F_2 ( V_4 -> V_6 , NULL , V_4 -> V_7 ) ;
if ( F_3 ( V_5 ) )
F_4 ( V_4 -> V_8 , L_1 ) ;
return V_9 ;
}
static T_2 F_5 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_3 * V_4 ;
unsigned int V_1 ;
unsigned int V_7 ;
unsigned int V_13 = V_14 ;
struct V_15 * V_8 = V_12 ;
T_3 V_6 = F_6 ( V_8 ) ;
T_3 V_16 ;
struct V_17 V_18 ;
struct V_19 * V_20 = & V_11 -> V_2 . V_1 ;
struct V_21 * V_22 = & V_11 -> V_2 . V_23 ;
if ( V_11 -> type == V_24 )
return V_25 ;
if ( ! F_7 ( V_11 , 0 , & V_18 ) ) {
F_8 ( V_8 , L_2 ) ;
return V_26 ;
}
if ( V_11 -> type == V_27 )
V_7 = V_20 -> V_28 [ 0 ] ;
else
V_7 = V_22 -> V_28 [ 0 ] ;
V_1 = V_18 . V_29 ;
if ( F_3 ( F_9 ( V_6 , L_3 , & V_16 ) ) ) {
F_8 ( V_8 , L_4 ) ;
return V_26 ;
}
F_10 ( V_8 , L_5 , V_7 , V_1 ) ;
V_4 = F_11 ( V_8 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return V_26 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_16 ;
if ( V_18 . V_31 & V_32 )
V_13 |= V_33 ;
if ( F_12 ( V_8 , V_1 , NULL , F_1 ,
V_13 , L_6 , V_4 ) ) {
F_8 ( V_8 , L_7 , V_1 ) ;
return V_26 ;
}
return V_25 ;
}
static int F_13 ( struct V_34 * V_35 )
{
T_2 V_5 ;
V_5 = F_14 ( F_6 ( & V_35 -> V_8 ) , L_8 ,
F_5 , & V_35 -> V_8 ) ;
if ( F_3 ( V_5 ) ) {
F_8 ( & V_35 -> V_8 , L_9 ) ;
return - V_36 ;
}
return 0 ;
}
