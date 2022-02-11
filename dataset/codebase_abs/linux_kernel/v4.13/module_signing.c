int F_1 ( const void * V_1 , unsigned long * V_2 )
{
struct V_3 V_4 ;
T_1 V_5 = * V_2 , V_6 ;
F_2 ( L_1 , V_7 , V_5 ) ;
if ( V_5 <= sizeof( V_4 ) )
return - V_8 ;
memcpy ( & V_4 , V_1 + ( V_5 - sizeof( V_4 ) ) , sizeof( V_4 ) ) ;
V_5 -= sizeof( V_4 ) ;
V_6 = F_3 ( V_4 . V_6 ) ;
if ( V_6 >= V_5 )
return - V_8 ;
V_5 -= V_6 ;
* V_2 = V_5 ;
if ( V_4 . V_9 != V_10 ) {
F_4 ( L_2 ) ;
return - V_11 ;
}
if ( V_4 . V_12 != 0 ||
V_4 . V_13 != 0 ||
V_4 . V_14 != 0 ||
V_4 . V_15 != 0 ||
V_4 . V_16 [ 0 ] != 0 ||
V_4 . V_16 [ 1 ] != 0 ||
V_4 . V_16 [ 2 ] != 0 ) {
F_4 ( L_3 ) ;
return - V_8 ;
}
return F_5 ( V_1 , V_5 , V_1 + V_5 , V_6 ,
NULL , V_17 ,
NULL , NULL ) ;
}
