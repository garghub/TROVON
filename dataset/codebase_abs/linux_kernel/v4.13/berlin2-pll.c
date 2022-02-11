static unsigned long
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
T_1 V_8 , V_9 , V_10 , V_11 , V_12 ;
T_2 V_13 = V_3 ;
V_8 = F_3 ( V_5 -> V_14 + V_15 ) ;
V_9 = ( V_8 >> V_7 -> V_16 ) & V_17 ;
V_10 = ( V_8 >> V_7 -> V_18 ) & V_19 ;
if ( V_10 == 0 ) {
F_4 ( L_1 , F_5 ( V_2 ) ) ;
V_10 = 1 ;
}
V_8 = F_3 ( V_5 -> V_14 + V_20 ) ;
V_11 = ( V_8 >> V_7 -> V_21 ) & V_22 ;
V_12 = V_7 -> V_12 [ V_11 ] ;
if ( V_12 == 0 ) {
F_4 ( L_2 ,
F_5 ( V_2 ) , V_11 ) ;
V_12 = 1 ;
}
V_13 *= V_9 * V_7 -> V_23 ;
F_6 ( V_13 , V_10 * V_12 ) ;
return ( unsigned long ) V_13 ;
}
int T_3
F_7 ( const struct V_6 * V_7 ,
void T_4 * V_14 , const char * V_24 ,
const char * V_25 , unsigned long V_26 )
{
struct V_27 V_28 ;
struct V_4 * V_5 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
memcpy ( & V_5 -> V_7 , V_7 , sizeof( * V_7 ) ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_2 . V_28 = & V_28 ;
V_28 . V_24 = V_24 ;
V_28 . V_31 = & V_32 ;
V_28 . V_33 = & V_25 ;
V_28 . V_34 = 1 ;
V_28 . V_26 = V_26 ;
return F_9 ( NULL , & V_5 -> V_2 ) ;
}
