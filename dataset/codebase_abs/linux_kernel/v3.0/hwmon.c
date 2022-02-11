struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 , V_5 ;
V_6:
if ( F_2 ( F_3 ( & V_7 , V_8 ) == 0 ) )
return F_4 ( - V_9 ) ;
F_5 ( & V_10 ) ;
V_5 = F_6 ( & V_7 , NULL , & V_4 ) ;
F_7 ( & V_10 ) ;
if ( F_2 ( V_5 == - V_11 ) )
goto V_6;
else if ( F_2 ( V_5 ) )
return F_4 ( V_5 ) ;
V_4 = V_4 & V_12 ;
V_3 = F_8 ( V_13 , V_2 , F_9 ( 0 , 0 ) , NULL ,
V_14 , V_4 ) ;
if ( F_10 ( V_3 ) ) {
F_5 ( & V_10 ) ;
F_11 ( & V_7 , V_4 ) ;
F_7 ( & V_10 ) ;
}
return V_3 ;
}
void F_12 ( struct V_1 * V_2 )
{
int V_4 ;
if ( F_13 ( sscanf ( F_14 ( V_2 ) , V_14 , & V_4 ) == 1 ) ) {
F_15 ( V_2 ) ;
F_5 ( & V_10 ) ;
F_11 ( & V_7 , V_4 ) ;
F_7 ( & V_10 ) ;
} else
F_16 ( V_2 -> V_15 ,
L_1 ) ;
}
static void T_1 F_17 ( void )
{
#if V_16 V_17 && V_16 V_18
struct V_19 * V_20 ;
T_2 V_21 ;
T_3 V_22 ;
V_20 = F_18 ( V_23 , 0x436c , NULL ) ;
if ( V_20 &&
( V_20 -> V_24 == 0x1462 &&
V_20 -> V_25 == 0x0031 ) ) {
F_19 ( V_20 , 0x48 , & V_22 ) ;
F_20 ( V_20 , 0x64 , & V_21 ) ;
if ( V_21 == 0 && ! ( V_22 & F_21 ( 2 ) ) ) {
F_22 ( & V_20 -> V_2 ,
L_2 ) ;
F_23 ( V_20 , 0x64 , 0x295 ) ;
F_24 ( V_20 , 0x48 , V_22 | F_21 ( 2 ) ) ;
}
}
#endif
}
static int T_1 F_25 ( void )
{
F_17 () ;
V_13 = F_26 ( V_26 , L_3 ) ;
if ( F_10 ( V_13 ) ) {
F_27 ( L_4 ) ;
return F_28 ( V_13 ) ;
}
return 0 ;
}
static void T_4 F_29 ( void )
{
F_30 ( V_13 ) ;
}
