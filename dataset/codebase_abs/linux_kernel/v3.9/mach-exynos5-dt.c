static void T_1 F_1 ( void )
{
unsigned long V_1 = F_2 () ;
F_3 ( NULL , 0 ) ;
if ( F_4 ( V_1 , L_1 ) )
F_5 ( 24000000 ) ;
}
static void T_1 F_6 ( void )
{
struct V_2 * V_3 ;
const char * V_4 = L_2 ;
unsigned int V_5 ;
F_7 (i2c_np, NULL, i2c_compat) {
if ( F_8 ( V_3 ) ) {
if ( F_9 ( V_3 , L_3 ) < 4 ) {
V_5 = F_10 ( V_6 ) ;
F_11 ( V_5 & ~ ( 0x1 << F_9 ( V_3 , L_3 ) ) ,
V_6 ) ;
}
}
}
if ( F_12 ( L_1 ) )
F_13 ( NULL , V_7 ,
V_8 , NULL ) ;
else if ( F_12 ( L_4 ) )
F_13 ( NULL , V_7 ,
V_9 , NULL ) ;
}
static void T_1 F_14 ( void )
{
#ifdef F_15
struct V_10 V_11 ;
V_11 . V_12 = L_5 ;
if ( F_16 ( V_13 , & V_11 ) )
F_17 ( V_11 . V_14 , V_11 . V_15 , V_11 . V_16 ,
V_11 . V_17 ) ;
#endif
}
