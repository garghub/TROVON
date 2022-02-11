static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const char * V_3 = L_1 ;
unsigned int V_4 ;
F_2 (i2c_np, NULL, i2c_compat) {
if ( F_3 ( V_2 ) ) {
if ( F_4 ( V_2 , L_2 ) < 4 ) {
V_4 = F_5 ( V_5 ) ;
F_6 ( V_4 & ~ ( 0x1 << F_4 ( V_2 , L_2 ) ) ,
V_5 ) ;
}
}
}
F_7 ( NULL , V_6 , NULL , NULL ) ;
}
static void T_1 F_8 ( void )
{
#ifdef F_9
struct V_7 V_8 ;
V_8 . V_9 = L_3 ;
if ( F_10 ( V_10 , & V_8 ) )
F_11 ( V_8 . V_11 , V_8 . V_12 , V_8 . V_13 ,
V_8 . V_14 ) ;
#endif
}
