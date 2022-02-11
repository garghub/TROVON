int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_3 ] . V_5 = ( V_6 * ) F_2 ( ( V_7 | V_8 ) ,
F_3 ( V_9 ) ) ;
if ( ! V_2 -> V_4 [ V_3 ] . V_5 )
return - V_10 ;
memset ( V_2 -> V_4 [ V_3 ] . V_5 , 0 , V_9 ) ;
F_4 ( L_1 , V_3 , V_2 -> V_4 [ V_3 ] . V_5 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( L_2 , V_2 -> V_4 [ V_3 ] . V_11 ) ;
F_6 ( ( V_6 ) V_2 -> V_4 [ V_3 ] . V_11 , F_3 ( V_9 ) ) ;
}
T_1 * F_7 ( V_6 V_12 )
{
T_1 * V_13 ;
V_13 = ( T_1 * ) F_2 ( ( V_7 | V_8 ) ,
F_3 ( V_12 ) ) ;
if ( ! V_13 )
return NULL ;
memset ( V_13 , 0 , V_12 ) ;
F_4 ( L_3 ) ;
return V_13 ;
}
void F_8 ( T_1 * V_13 , V_6 V_12 )
{
F_4 ( L_4 , V_13 ) ;
F_6 ( ( V_6 ) V_13 , F_3 ( V_12 ) ) ;
}
