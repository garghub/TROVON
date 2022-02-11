static int T_1 F_1 ( void )
{
char * V_1 = NULL ;
V_2 . V_3 = F_2 ( V_2 . V_4 , V_2 . V_5 ) ;
if ( ! V_2 . V_3 ) {
F_3 ( V_6 L_1 ) ;
return - V_7 ;
}
F_4 ( & V_2 ) ;
F_3 ( V_8 L_2 ) ;
V_9 = F_5 ( L_3 , & V_2 ) ;
if ( ! V_9 ) {
F_3 ( V_8 L_4 ) ;
V_2 . V_10 = 2 ;
V_9 = F_5 ( L_3 , & V_2 ) ;
}
if ( V_9 ) {
V_9 -> V_11 = V_12 ;
V_13 = F_6 ( V_9 , V_14 , & V_15 , 0 ) ;
if ( V_13 > 0 )
V_1 = L_5 ;
if ( V_13 <= 0 ) {
V_15 = V_16 ;
V_13 = V_17 ;
V_1 = L_6 ;
}
F_3 ( V_8 L_7 , V_1 ) ;
F_7 ( V_9 , V_15 , V_13 ) ;
return 0 ;
}
F_8 ( ( void * ) V_2 . V_3 ) ;
return - V_18 ;
}
static void T_2 F_9 ( void )
{
if ( V_9 ) {
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
}
if ( V_15 && ( V_15 != V_16 ) )
F_12 ( V_15 ) ;
if ( V_2 . V_3 ) {
F_8 ( ( void * ) V_2 . V_3 ) ;
V_2 . V_3 = 0 ;
}
}
