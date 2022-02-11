static int F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + 0xc ) ;
if ( V_1 & 0x40 )
F_3 ( V_2 + 0xc , 0x40 ) ;
V_1 = F_2 ( V_2 + 0x8 ) ;
return ( V_1 & 0x40 ) == 0 ;
}
static int T_2 F_4 ( void )
{
struct V_3 * V_4 ;
V_4 = F_5 ( NULL , NULL , L_1 ) ;
if ( ! V_4 ) {
F_6 ( L_2 , V_5 ) ;
return - V_6 ;
}
V_2 = F_7 ( V_4 , 0 ) ;
F_8 ( V_4 ) ;
if ( ! V_2 ) {
F_6 ( L_3 , V_5 ) ;
return - V_6 ;
}
F_9 ( V_2 + 0xc , 0xffffffff ) ;
F_3 ( V_2 + 0x18 , 0x2000 ) ;
F_3 ( V_2 + 0x10 , 0x40 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
if ( ( V_9 == V_13 ) &&
F_11 ( V_12 -> V_14 , L_4 ) ) {
V_12 -> V_15 = & V_16 ;
return V_17 ;
}
return V_18 ;
}
static void T_2 F_12 ( void )
{
if ( F_4 () )
return;
F_13 ( & V_19 , & V_20 ) ;
}
static inline void T_2 F_12 ( void )
{
}
void T_2 F_14 ( void )
{
F_15 () ;
F_12 () ;
}
static int T_2 F_16 ( void )
{
unsigned long V_21 = F_17 () ;
return F_18 ( V_21 , L_5 ) ;
}
