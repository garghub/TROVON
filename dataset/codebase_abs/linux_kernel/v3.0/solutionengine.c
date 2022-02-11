static int T_1 F_1 ( void )
{
int V_1 = 0 ;
V_2 . V_3 = 0 ;
V_2 . V_4 = ( void V_5 * ) F_2 ( 0 ) ;
V_6 . V_3 = 0x01000000 ;
V_6 . V_4 = ( void V_5 * ) F_3 ( 0x01000000 ) ;
F_4 ( & V_6 ) ;
F_4 ( & V_2 ) ;
F_5 ( V_7 L_1 ) ;
V_8 = F_6 ( L_2 , & V_2 ) ;
if ( ! V_8 ) {
F_5 ( V_7 L_3 ) ;
V_2 . V_3 = 0x01000000 ;
V_2 . V_4 = F_2 ( 0x01000000 ) ;
V_6 . V_3 = 0 ;
V_6 . V_4 = F_3 ( 0 ) ;
V_8 = F_6 ( L_2 , & V_2 ) ;
if ( ! V_8 ) {
F_5 ( V_7 L_4 ) ;
return - V_9 ;
}
}
F_5 ( V_7 L_5 ,
V_2 . V_3 & 0x1fffffff ,
V_6 . V_3 & 0x1fffffff ) ;
V_8 -> V_10 = V_11 ;
V_12 = F_6 ( L_6 , & V_6 ) ;
if ( V_12 ) {
V_12 -> V_10 = V_11 ;
F_7 ( V_12 , NULL , 0 ) ;
}
V_1 = F_8 ( V_8 , V_13 , & V_14 , 0 ) ;
#ifdef F_9
if ( V_1 <= 0 ) {
F_5 ( V_7 L_7 ,
F_9 ) ;
V_14 = V_15 ;
V_1 = sizeof( V_15 ) / sizeof( * V_14 ) ;
}
#endif
if ( V_1 > 0 )
F_7 ( V_8 , V_14 , V_1 ) ;
else
F_7 ( V_8 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_10 ( void )
{
if ( V_12 ) {
F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
}
if ( V_14 )
F_11 ( V_8 ) ;
else
F_11 ( V_8 ) ;
F_12 ( V_8 ) ;
}
