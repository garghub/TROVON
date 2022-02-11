static int T_1 F_1 ( void )
{
V_1 . V_2 = 0 ;
V_1 . V_3 = ( void V_4 * ) F_2 ( 0 ) ;
V_5 . V_2 = 0x01000000 ;
V_5 . V_3 = ( void V_4 * ) F_3 ( 0x01000000 ) ;
F_4 ( & V_5 ) ;
F_4 ( & V_1 ) ;
F_5 ( V_6 L_1 ) ;
V_7 = F_6 ( L_2 , & V_1 ) ;
if ( ! V_7 ) {
F_5 ( V_6 L_3 ) ;
V_1 . V_2 = 0x01000000 ;
V_1 . V_3 = F_2 ( 0x01000000 ) ;
V_5 . V_2 = 0 ;
V_5 . V_3 = F_3 ( 0 ) ;
V_7 = F_6 ( L_2 , & V_1 ) ;
if ( ! V_7 ) {
F_5 ( V_6 L_4 ) ;
return - V_8 ;
}
}
F_5 ( V_6 L_5 ,
V_1 . V_2 & 0x1fffffff ,
V_5 . V_2 & 0x1fffffff ) ;
V_7 -> V_9 = V_10 ;
V_11 = F_6 ( L_6 , & V_5 ) ;
if ( V_11 ) {
V_11 -> V_9 = V_10 ;
F_7 ( V_11 , NULL , 0 ) ;
}
F_8 ( V_7 , V_12 , NULL , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_9 ( void )
{
if ( V_11 ) {
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
}
F_10 ( V_7 ) ;
F_11 ( V_7 ) ;
}
