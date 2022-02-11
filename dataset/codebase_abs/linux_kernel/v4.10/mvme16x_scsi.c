static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 ;
if ( ! V_7 )
goto V_8;
if ( V_9 & V_10 ) {
F_2 ( V_11 L_1
L_2 ) ;
goto V_8;
}
V_6 = F_3 ( sizeof( struct V_5 ) , V_12 ) ;
if ( V_6 == NULL ) {
F_2 ( V_13 L_3
L_4 ) ;
goto V_8;
}
V_6 -> V_14 = ( void V_15 * ) 0xfff47000UL ;
V_6 -> clock = 50 ;
V_6 -> V_16 = 1 ;
V_6 -> V_17 = V_18 ;
V_6 -> V_19 = V_20 ;
V_6 -> V_21 = V_22 ;
V_4 = F_4 ( & V_23 , V_6 ,
& V_2 -> V_2 ) ;
if ( ! V_4 ) {
F_2 ( V_13 L_5
L_6 ) ;
goto V_24;
}
V_4 -> V_25 = 7 ;
V_4 -> V_14 = 0xfff47000UL ;
V_4 -> V_26 = V_27 ;
if ( F_5 ( V_4 -> V_26 , V_28 , 0 , L_7 , V_4 ) ) {
F_2 ( V_13 L_8 ) ;
goto V_29;
}
{
volatile unsigned long V_30 ;
V_30 = F_6 ( 0xfff4202c ) ;
V_30 = ( V_30 & ~ 0xff ) | 0x10 | 4 ;
F_7 ( 0xfff4202c , V_30 ) ;
}
F_8 ( V_2 , V_4 ) ;
F_9 ( V_4 ) ;
return 0 ;
V_29:
F_10 ( V_4 ) ;
V_24:
F_11 ( V_6 ) ;
V_8:
return - V_31 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
struct V_5 * V_6 = F_14 ( V_4 ) ;
{
volatile unsigned long V_30 ;
V_30 = F_6 ( 0xfff4202c ) ;
V_30 &= ~ 0x10 ;
F_7 ( 0xfff4202c , V_30 ) ;
}
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
F_11 ( V_6 ) ;
F_17 ( V_4 -> V_26 , V_4 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
int V_32 ;
V_32 = F_19 ( & V_33 ) ;
if ( V_32 )
return V_32 ;
V_34 = F_20 ( L_7 ,
- 1 , NULL , 0 ) ;
if ( F_21 ( V_34 ) ) {
F_22 ( & V_33 ) ;
return F_23 ( V_34 ) ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_34 ) ;
F_22 ( & V_33 ) ;
}
