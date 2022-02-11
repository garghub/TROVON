static int T_1
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
static struct V_4 * V_5 ;
struct V_1 * V_6 ;
const struct V_7 * V_8 ;
T_2 V_9 ;
V_6 = F_2 ( NULL , V_10 ,
& V_8 ) ;
if ( ! V_6 )
return - V_11 ;
V_9 = ( T_2 ) V_8 -> V_12 ;
V_5 = F_3 ( V_6 ) ;
if ( ! F_4 ( V_5 ) ) {
F_5 ( V_5 , V_13 ,
V_14 ) ;
F_6 ( V_5 , V_9 ,
V_15 ,
V_16 ) ;
F_5 ( V_5 , V_13 , 0x0000 ) ;
F_7 ( L_1 ) ;
} else {
F_8 ( L_2 ) ;
return - V_11 ;
}
return F_9 ( V_2 , V_3 ) ;
}
