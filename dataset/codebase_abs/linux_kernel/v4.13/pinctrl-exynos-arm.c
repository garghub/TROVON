static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = ( void T_1 * ) V_2 -> V_4 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_3 + V_7 ) ;
V_6 |= ( V_8 | V_9 | V_10 |
V_11 ) ;
F_3 ( V_6 , V_3 + V_7 ) ;
}
static struct V_12 *
F_4 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_12 * V_15 ;
struct V_16 * V_17 ;
void T_1 * V_3 ;
V_15 = F_5 ( V_2 -> V_18 , sizeof( * V_15 ) , V_19 ) ;
if ( ! V_15 )
return F_6 ( - V_20 ) ;
V_17 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_17 ) {
F_8 ( L_2 ,
V_21 ) ;
return F_6 ( - V_22 ) ;
}
V_3 = F_9 ( V_17 , 0 ) ;
if ( ! V_3 ) {
F_8 ( L_3 , V_21 ) ;
return F_6 ( - V_23 ) ;
}
V_15 -> V_5 = ( void V_24 * ) V_3 ;
V_15 -> V_25 = F_1 ;
return V_15 ;
}
