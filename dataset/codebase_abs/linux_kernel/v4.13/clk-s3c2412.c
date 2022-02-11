static int F_1 ( void )
{
F_2 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
return 0 ;
}
static void F_4 ( void )
{
F_5 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
}
static void T_1 F_6 ( void )
{
V_2 = F_7 ( V_3 ,
F_3 ( V_3 ) ) ;
if ( ! V_2 ) {
F_8 ( L_1 ,
V_4 ) ;
return;
}
F_9 ( & V_5 ) ;
return;
}
static void T_1 F_6 ( void ) {}
static int F_10 ( struct V_6 * V_7 ,
unsigned long V_8 , void * V_9 )
{
F_11 ( 0x00 , V_1 + V_10 ) ;
F_11 ( 0x533C2412 , V_1 + V_11 ) ;
return V_12 ;
}
static void T_1 F_12 (
struct V_13 * V_14 ,
unsigned long V_15 , unsigned long V_16 )
{
struct V_17 V_18 = F_13 ( V_19 , NULL , L_2 ) ;
V_20 [ 0 ] . V_21 = V_15 ;
V_20 [ 1 ] . V_21 = V_16 ;
F_14 ( V_14 , V_20 ,
F_3 ( V_20 ) ) ;
F_15 ( V_14 , & V_18 , 1 ) ;
}
void T_1 F_16 ( struct V_22 * V_23 , unsigned long V_15 ,
unsigned long V_16 , void T_2 * V_24 )
{
struct V_13 * V_14 ;
int V_25 ;
V_1 = V_24 ;
if ( V_23 ) {
V_1 = F_17 ( V_23 , 0 ) ;
if ( ! V_1 )
F_18 ( L_3 , V_4 ) ;
}
V_14 = F_19 ( V_23 , V_1 , V_26 ) ;
if ( ! V_23 )
F_12 ( V_14 , V_15 , V_16 ) ;
F_20 ( V_14 , V_27 , F_3 ( V_27 ) ,
V_1 ) ;
F_21 ( V_14 , V_28 , F_3 ( V_28 ) ) ;
F_22 ( V_14 , V_29 ,
F_3 ( V_29 ) ) ;
F_23 ( V_14 , V_30 ,
F_3 ( V_30 ) ) ;
F_24 ( V_14 , V_31 ,
F_3 ( V_31 ) ) ;
F_15 ( V_14 , V_32 ,
F_3 ( V_32 ) ) ;
F_6 () ;
F_25 ( V_23 , V_14 ) ;
V_25 = F_26 ( & V_33 ) ;
if ( V_25 )
F_8 ( L_4 , V_25 ) ;
}
static void T_1 F_27 ( struct V_22 * V_23 )
{
F_16 ( V_23 , 0 , 0 , 0 ) ;
}
