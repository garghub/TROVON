static bool
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_9 ;
struct V_10 * V_11 ;
F_3 ( L_1 , V_12 , V_4 -> type ) ;
V_11 = F_4 ( & V_2 -> V_13 , V_4 ) ;
if ( ! V_11 )
return false ;
if ( ! V_11 -> V_14 || V_11 -> V_14 -> V_15 ( V_11 , V_4 ) ) {
F_5 ( V_11 ) ;
return false ;
}
F_6 ( V_6 ,
L_2
L_3 ,
V_4 -> type , V_4 -> V_16 , V_8 -> V_17 ) ;
V_6 -> V_18 = V_11 ;
return true ;
}
void
F_7 ( struct F_2 * V_19 )
{
struct V_5 * V_6 = ( void * ) V_19 ;
struct V_20 * V_21 = V_20 ( V_19 ) ;
struct V_22 * V_2 = V_22 ( V_19 ) ;
struct V_23 V_24 ;
if ( ! F_8 ( V_21 , V_25 , & V_24 ) ) {
struct V_3 V_26 [] = {
{ F_9 ( L_4 , extdev_entry.addr >> 1 ) } ,
{ }
} ;
V_2 -> V_27 ( V_2 , F_10 ( 0 ) , L_5 ,
V_26 , F_1 ) ;
if ( V_6 -> V_18 )
return;
}
if ( ! F_8 ( V_21 , V_28 , & V_24 ) ) {
struct V_3 V_26 [] = {
{ F_9 ( L_6 , extdev_entry.addr >> 1 ) } ,
{ }
} ;
V_2 -> V_27 ( V_2 , F_10 ( 0 ) , L_5 ,
V_26 , F_1 ) ;
if ( V_6 -> V_18 )
return;
}
V_2 -> V_27 ( V_2 , F_10 ( 0 ) , L_5 ,
V_29 , F_1 ) ;
}
