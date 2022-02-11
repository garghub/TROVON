bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
if ( V_2 -> V_6 -> V_7 == V_5 -> V_8 ) {
V_2 -> V_9 = V_3 ;
return true ;
} else {
return false ;
}
}
void T_1 F_2 ( void )
{
F_3 ( 0x06 , V_10 + V_11 ) ;
F_3 ( 0x221 , V_10 + V_12 ) ;
F_3 ( 0x441 , V_10 + V_13 ) ;
F_4 ( V_10 , 0x70A60001 , 0xfe00ffff ) ;
}
void T_1 F_5 ( void )
{
F_6 ( V_14 , F_7 ( V_14 ) ) ;
}
static void T_1 F_8 ( void )
{
if ( F_9 ( L_1 ) )
F_10 () ;
else if ( F_9 ( L_2 ) )
F_11 () ;
else
F_12 ( L_3 , V_15 ) ;
}
static void T_1 F_13 ( void )
{
char V_16 [] = L_4 ;
struct V_17 * V_18 , * V_19 ;
F_8 () ;
V_18 = F_14 ( L_5 , NULL ) ;
if ( F_15 ( V_18 ) ) {
F_12 ( L_6 , V_15 ) ;
F_16 () ;
}
V_19 = F_17 ( NULL , V_16 ) ;
if ( F_15 ( V_19 ) ) {
F_12 ( L_7 , V_15 ,
V_16 ) ;
F_16 () ;
}
F_18 ( V_18 , V_19 ) ;
F_19 ( V_18 ) ;
F_19 ( V_19 ) ;
F_20 () ;
F_21 () ;
}
void T_1 F_22 ( void )
{
F_23 ( V_20 ) ;
}
