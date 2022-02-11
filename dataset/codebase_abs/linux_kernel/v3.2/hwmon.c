struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
V_4 = F_2 ( & V_5 , 0 , 0 , V_6 ) ;
if ( V_4 < 0 )
return F_3 ( V_4 ) ;
V_3 = F_4 ( V_7 , V_2 , F_5 ( 0 , 0 ) , NULL ,
V_8 , V_4 ) ;
if ( F_6 ( V_3 ) )
F_7 ( & V_5 , V_4 ) ;
return V_3 ;
}
void F_8 ( struct V_1 * V_2 )
{
int V_4 ;
if ( F_9 ( sscanf ( F_10 ( V_2 ) , V_8 , & V_4 ) == 1 ) ) {
F_11 ( V_2 ) ;
F_7 ( & V_5 , V_4 ) ;
} else
F_12 ( V_2 -> V_9 ,
L_1 ) ;
}
static void T_1 F_13 ( void )
{
#if V_10 V_11 && V_10 V_12
struct V_13 * V_14 ;
T_2 V_15 ;
T_3 V_16 ;
V_14 = F_14 ( V_17 , 0x436c , NULL ) ;
if ( V_14 &&
( V_14 -> V_18 == 0x1462 &&
V_14 -> V_19 == 0x0031 ) ) {
F_15 ( V_14 , 0x48 , & V_16 ) ;
F_16 ( V_14 , 0x64 , & V_15 ) ;
if ( V_15 == 0 && ! ( V_16 & F_17 ( 2 ) ) ) {
F_18 ( & V_14 -> V_2 ,
L_2 ) ;
F_19 ( V_14 , 0x64 , 0x295 ) ;
F_20 ( V_14 , 0x48 , V_16 | F_17 ( 2 ) ) ;
}
}
#endif
}
static int T_1 F_21 ( void )
{
F_13 () ;
V_7 = F_22 ( V_20 , L_3 ) ;
if ( F_6 ( V_7 ) ) {
F_23 ( L_4 ) ;
return F_24 ( V_7 ) ;
}
return 0 ;
}
static void T_4 F_25 ( void )
{
F_26 ( V_7 ) ;
}
