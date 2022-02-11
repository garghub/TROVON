static int T_1 F_1 ( void )
{
char * V_1 ;
char * V_2 ;
unsigned long V_3 ;
if( ! V_4 ) {
F_2 ( L_1 ) ;
return - V_5 ;
}
V_1 = V_4 ;
if( ! * V_1 )
return - V_5 ;
V_3 = F_3 ( V_1 , & V_2 , 16 ) ;
if( V_2 == V_1 || V_3 > 0xff ) {
F_4 ( L_2 ) ;
return - V_5 ;
}
V_6 = ( V_7 ) V_3 ;
F_5 ( L_3 , V_6 ) ;
if( * V_2 != ':' ) {
F_4 ( L_4 ) ;
return - V_5 ;
}
V_1 = V_2 + 1 ;
V_3 = F_3 ( V_1 , & V_2 , 16 ) ;
if( V_2 == V_1 || V_3 > 0x1f ) {
F_4 ( L_5 ) ;
return - V_5 ;
}
V_8 = ( V_7 ) V_3 ;
F_5 ( L_6 , V_8 ) ;
F_5 ( L_7 , V_9 ) ;
F_5 ( L_8 , V_10 ) ;
if( ! ( V_9 && V_10 ) ) {
F_4 ( L_9 ) ;
return - V_5 ;
}
if( V_10 < V_9 ) {
F_4 ( L_10 ) ;
return - V_5 ;
}
F_5 ( L_11 , V_11 ) ;
F_5 ( L_12 , V_12 ) ;
if( V_12 > 7 ) {
F_4 ( L_13 ) ;
return - V_5 ;
}
V_13 = 1 << V_12 ;
return 0 ;
}
static int F_6 ( void )
{
V_7 V_14 ;
V_14 = F_7 ( V_11 ) ;
return ( ( V_14 & V_13 ) == V_13 ) ;
}
static int T_1 F_8 ( void )
{
int V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_2 ( V_20 L_14 V_21 ) ;
V_15 = F_1 () ;
if ( V_15 )
return V_15 ;
V_17 = F_9 ( V_11 , 1 , L_15 ) ;
if( ! V_17 )
return - V_22 ;
V_19 = F_10 ( 0 , V_6 ,
F_11 ( V_8 , 0 ) ) ;
if( ! V_19 || V_19 -> V_23 != V_24 ) {
F_4 ( L_16 , V_4 ) ;
F_12 ( V_19 ) ;
return - V_5 ;
}
V_25 = V_19 -> V_26 ;
F_12 ( V_19 ) ;
memset ( & V_27 , 0 , sizeof ( struct V_28 ) ) ;
V_29 . F_6 = F_6 ;
V_27 . V_30 = & V_29 ;
V_15 = F_13 ( & V_27 ) ;
if( V_15 != 0 ) {
F_4 ( L_17 ) ;
return - V_31 ;
}
F_5 ( L_18 ) ;
V_15 = F_14 ( V_25 , V_9 , V_10 ) ;
if( V_15 != 0 ) {
F_4 ( L_19 ) ;
goto V_32;
}
F_5 ( L_20 ) ;
V_15 = F_15 () ;
if( V_15 != 0 ) {
F_4 ( L_21 ) ;
goto V_33;
}
F_5 ( L_22 ) ;
return 0 ;
V_33:
F_16 ( V_25 ) ;
V_32:
F_17 ( & V_27 ) ;
F_4 ( L_23 , V_15 ) ;
return V_15 ;
}
static void T_2 F_18 ( void )
{
F_19 () ;
F_16 ( V_25 ) ;
F_17 ( & V_27 ) ;
F_20 ( V_11 , 1 ) ;
}
