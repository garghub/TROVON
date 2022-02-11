int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_5 = V_4 -> V_6 [ V_7 ] ;
V_2 -> V_8 = V_9 . V_10 ( V_5 ,
V_11 ) ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( L_1 ) ;
return F_4 ( V_2 -> V_8 ) ;
}
V_2 -> V_12 = F_5 ( V_5 , V_2 -> V_8 )
- V_4 -> V_13 ;
F_6 ( V_2 -> V_12 & ( ( 1 << V_14 ) - 1 ) ) ;
V_2 -> V_15 = V_9 . V_16 ( V_2 -> V_8 ) ;
if ( ! V_2 -> V_15 ) {
V_9 . V_17 ( V_2 -> V_8 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_8 = NULL ;
F_3 ( L_2 ) ;
return - V_18 ;
}
memset ( ( void * ) V_2 -> V_15 , 0 , V_11 ) ;
F_7 () ;
return 0 ;
}
