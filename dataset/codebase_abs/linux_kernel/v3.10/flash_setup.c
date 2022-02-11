static int T_1 F_1 ( void )
{
union V_1 V_2 ;
V_2 . V_3 = F_2 ( F_3 ( 0 ) ) ;
if ( V_2 . V_4 . V_5 ) {
V_6 . V_7 = L_1 ;
V_6 . V_8 = V_2 . V_4 . V_9 << 16 ;
V_6 . V_10 = 0x1fc00000 - V_6 . V_8 ;
V_6 . V_11 = V_2 . V_4 . V_12 + 1 ;
V_6 . V_13 = F_4 ( V_6 . V_8 , V_6 . V_10 ) ;
F_5 ( L_2
L_3 , V_6 . V_10 >> 20 , V_6 . V_8 ) ;
F_6 ( & V_6 ) ;
V_14 = F_7 ( L_4 , & V_6 ) ;
if ( V_14 ) {
V_14 -> V_15 = V_16 ;
F_8 ( V_14 , V_17 ,
NULL , NULL , 0 ) ;
} else {
F_9 ( L_5 ) ;
}
}
return 0 ;
}
