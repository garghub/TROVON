static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 ;
const char * V_13 ;
const char * V_14 ;
struct V_15 * V_16 ;
void T_1 * V_17 ;
int V_18 ;
int V_19 ;
int V_20 = 0 ;
if ( ! V_4 )
return - V_21 ;
V_10 = F_2 ( V_22 , & V_2 -> V_5 ) ;
if ( ! V_10 )
return - V_21 ;
V_12 = V_10 -> V_12 ;
V_16 = F_3 ( V_2 , V_23 , 0 ) ;
V_17 = F_4 ( & V_2 -> V_5 , V_16 ) ;
if ( F_5 ( V_17 ) )
return F_6 ( V_17 ) ;
V_13 = F_7 ( V_4 , 0 ) ;
if ( ! V_13 )
return - V_24 ;
V_8 = F_8 ( & V_2 -> V_5 , sizeof( struct V_7 ) ,
V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_18 = F_9 ( V_12 -> V_27 , V_28 ) ;
V_8 -> V_29 = F_10 ( & V_2 -> V_5 , ( V_18 + 1 ) ,
sizeof( struct V_30 * ) , V_25 ) ;
if ( ! V_8 -> V_29 )
return - V_26 ;
F_11 (i, data->mask, SUN6I_APB0_GATES_MAX_SIZE) {
F_12 ( V_4 , L_1 ,
V_20 , & V_14 ) ;
V_8 -> V_29 [ V_19 ] = F_13 ( & V_2 -> V_5 , V_14 ,
V_13 , 0 , V_17 , V_19 ,
0 , NULL ) ;
F_14 ( F_5 ( V_8 -> V_29 [ V_19 ] ) ) ;
V_20 ++ ;
}
V_8 -> V_31 = V_18 + 1 ;
return F_15 ( V_4 , V_32 , V_8 ) ;
}
