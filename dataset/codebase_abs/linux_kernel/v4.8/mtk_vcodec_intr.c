int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
T_1 * V_5 ;
long V_6 , V_7 ;
int V_8 = 0 ;
V_5 = ( T_1 * ) & V_2 -> V_9 ;
V_6 = F_2 ( V_4 ) ;
V_7 = F_3 ( * V_5 ,
( V_2 -> V_10 &&
( V_2 -> V_11 == V_3 ) ) ,
V_6 ) ;
if ( ! V_7 ) {
V_8 = - 1 ;
F_4 ( L_1 ,
V_2 -> V_12 , V_2 -> type , V_3 , V_4 ,
V_2 -> V_10 , V_2 -> V_11 ) ;
} else if ( - V_13 == V_7 ) {
F_4 ( L_2 ,
V_2 -> V_12 , V_2 -> type , V_3 , V_2 -> V_10 ,
V_2 -> V_11 ) ;
V_8 = - 1 ;
}
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
return V_8 ;
}
