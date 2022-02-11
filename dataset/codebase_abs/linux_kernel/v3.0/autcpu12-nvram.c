static int T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
V_4 . V_5 = F_2 ( 0x12000000 , V_6 ) ;
if ( ! V_4 . V_5 ) {
F_3 ( L_1 ) ;
V_1 = - V_7 ;
goto V_8;
}
F_4 ( & V_9 ) ;
V_2 = F_5 ( & V_4 , 0 ) ;
V_3 = F_5 ( & V_4 , 0x10000 ) ;
F_6 ( & V_4 , ~ V_2 , 0x10000 ) ;
if ( F_5 ( & V_4 , 0 ) != V_2 ) {
F_6 ( & V_4 , V_2 , 0x0 ) ;
goto V_10;
}
F_6 ( & V_4 , V_3 , 0x10000 ) ;
V_4 . V_11 = V_6 ;
V_10:
V_12 = F_7 ( L_2 , & V_4 ) ;
if ( ! V_12 ) {
F_3 ( L_3 ) ;
V_1 = - V_13 ;
goto V_14;
}
V_12 -> V_15 = V_16 ;
V_12 -> V_17 = 16 ;
if ( F_8 ( V_12 , NULL , 0 ) ) {
F_3 ( L_4 ) ;
V_1 = - V_18 ;
goto V_19;
}
F_3 ( L_5 , V_4 . V_11 / V_20 ) ;
return 0 ;
V_19:
F_9 ( V_12 ) ;
V_12 = 0 ;
V_14:
F_10 ( ( void * ) V_4 . V_5 ) ;
V_8:
return V_1 ;
}
static void T_2 F_11 ( void )
{
if ( V_12 ) {
F_12 ( V_12 ) ;
F_9 ( V_12 ) ;
F_10 ( ( void * ) V_4 . V_5 ) ;
}
}
