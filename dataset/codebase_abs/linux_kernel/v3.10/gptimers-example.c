static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( ! F_2 ( V_5 ) )
return V_6 ;
V_4 -> V_7 = F_3 ( V_5 ) ;
V_4 -> V_8 = F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
return V_9 ;
}
static int T_2 F_6 ( void )
{
int V_10 ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( V_10 ) {
F_8 (KERN_NOTICE DRIVER_NAME L_1 ) ;
return V_10 ;
}
V_10 = F_9 ( V_13 , F_1 , V_14 , V_12 , & V_4 ) ;
if ( V_10 ) {
F_8 (KERN_NOTICE DRIVER_NAME L_2 ) ;
F_10 ( V_11 ) ;
return V_10 ;
}
F_11 ( V_5 , V_15 | V_16 | V_17 | V_18 ) ;
F_12 ( V_19 ) ;
return 0 ;
}
static void T_3 F_13 ( void )
{
F_14 ( V_19 ) ;
F_15 ( V_13 , & V_4 ) ;
F_10 ( V_11 ) ;
}
