static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static unsigned int F_4 ( struct V_2 * V_3 )
{
unsigned int V_4 = F_5 ( F_6 ( 0xca000000 + 4 ) ) ;
F_7 ( 8 , V_5 + 8 ) ;
return V_4 & 8 ;
}
static T_2 T_3 F_8 ( void )
{
unsigned int V_6 ;
F_9 ( V_7 , V_8 , & V_6 ) ;
return V_6 ;
}
static void T_1 F_10 ( void )
{
V_7 = F_11 ( L_1 ) ;
if ( F_12 ( V_7 ) )
return;
F_13 ( F_8 , 32 , 24000000 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 () ;
}
static void T_1 F_17 ( void )
{
struct V_9 * V_10 ;
V_10 = F_18 ( NULL , V_11 ) ;
if ( ! V_10 )
return;
V_5 = F_19 ( V_10 , 0 ) ;
if ( ! V_5 )
return;
F_20 ( NULL , V_12 , NULL ) ;
}
