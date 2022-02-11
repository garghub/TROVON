T_1 int F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( L_1 ) ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
F_4 ( L_2 ) ;
V_2 -> V_4 = V_5 ;
V_6 = F_5 ( L_3 ,
F_6 ( 0 ) , F_7 ( 0 ) , F_8 () ,
( V_7 & ~ V_8 ) |
V_9 | V_10 |
V_11 | V_12 ,
V_13 ,
V_2 , NULL ) ;
if ( F_9 ( V_6 ) )
F_4 ( L_4 ) ;
F_10 ( V_14 , & V_6 -> V_15 ) ;
return 0 ;
}
