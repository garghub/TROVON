static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
int V_11 = 0 ;
V_10 = F_2 ( V_4 ) ;
#ifndef F_3
if ( V_10 != 44100 ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
#endif
V_11 = F_5 ( V_9 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
F_4 ( L_2 , V_10 ) ;
#ifndef F_3
return 0 ;
#else
return F_6 ( V_10 ) ;
#endif
}
static int T_1 F_7 ( void )
{
int V_11 ;
if ( ! F_8 () )
return - V_12 ;
F_9 ( & V_14 ) ;
V_15 = F_10 ( L_3 , 0 ) ;
if ( ! V_15 ) {
F_11 ( V_16 L_4 ) ;
return - V_17 ;
}
F_12 ( V_15 , & V_18 ) ;
F_13 ( V_15 , & V_19 ,
sizeof( V_19 ) ) ;
V_11 = F_14 ( V_15 ,
V_20 ,
F_15 ( V_20 ) ) ;
if ( V_11 ) {
F_11 ( V_16 L_5 ) ;
goto error;
}
V_11 = F_16 ( V_15 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_17 ( V_15 ) ;
return V_11 ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_15 ) ;
F_19 ( & V_14 ) ;
}
