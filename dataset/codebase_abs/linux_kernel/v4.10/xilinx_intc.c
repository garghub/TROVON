static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 )
F_4 ( V_5 ) ;
V_4 -> V_6 ( & V_2 -> V_7 ) ;
}
static void T_1 F_5 ( void )
{
struct V_8 * V_9 ;
int V_5 ;
V_9 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_9 )
return;
V_5 = F_7 ( V_9 , 0 ) ;
if ( ! V_5 ) {
F_8 ( L_2 ) ;
goto V_10;
}
F_9 ( V_9 , 0 ) ;
F_10 ( V_5 , F_1 ) ;
F_11 ( 0xc0 , 0x4d0 ) ;
F_11 ( 0xc0 , 0x4d1 ) ;
V_10:
F_12 ( V_9 ) ;
}
static inline void F_5 ( void ) { return; }
void T_1 F_13 ( void )
{
F_14 () ;
F_5 () ;
}
