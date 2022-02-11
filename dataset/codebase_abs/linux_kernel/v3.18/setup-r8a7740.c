void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( L_1 , - 1 , V_2 ,
F_3 ( V_2 ) ) ;
}
void T_1 F_6 ( void )
{
void T_2 * V_3 ;
V_3 = F_7 ( V_4 , 4 ) ;
if ( V_3 ) {
F_8 ( 0x01600164 , V_3 ) ;
F_9 ( V_3 ) ;
}
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
void T_2 * V_3 ;
V_8 = F_11 ( V_6 , V_9 , 0 ) ;
if ( F_12 ( ! V_8 ) ) {
F_13 ( L_2 ) ;
return;
}
V_3 = F_14 ( V_8 -> V_10 , F_15 ( V_8 ) ) ;
if ( F_12 ( ! V_3 ) ) {
F_13 ( L_3 ) ;
return;
}
F_16 ( V_3 , V_11 , F_17 ( V_3 , V_11 ) | 0x80 ) ;
F_17 ( V_3 , V_11 ) ;
F_16 ( V_3 , V_12 , F_17 ( V_3 , V_12 ) | 0x10 ) ;
F_17 ( V_3 , V_12 ) ;
F_18 ( 10 ) ;
F_16 ( V_3 , V_11 , 0x01 ) ;
F_16 ( V_3 , V_12 , 0x00 ) ;
F_18 ( 10 ) ;
F_16 ( V_3 , V_11 , 0x10 ) ;
F_18 ( 10 ) ;
F_16 ( V_3 , V_11 , 0x00 ) ;
F_18 ( 10 ) ;
F_16 ( V_3 , V_11 , 0x10 ) ;
F_18 ( 10 ) ;
F_9 ( V_3 ) ;
}
void T_1 F_19 ( void )
{
static struct V_13 V_14 [] V_15 = {
{ L_4 , & V_16 } ,
{ L_4 , & V_17 } ,
{ L_4 , & V_18 } ,
{ L_4 , & V_19 } ,
{ L_4 , & V_20 } ,
{ L_4 , & V_21 } ,
{ L_4 , & V_22 } ,
{ L_4 , & V_23 } ,
{ L_4 , & V_24 } ,
{ L_4 , & V_25 } ,
} ;
F_10 ( & V_26 ) ;
F_10 ( & V_25 ) ;
F_20 () ;
F_21 ( V_27 ,
F_3 ( V_27 ) ) ;
F_21 ( V_28 ,
F_3 ( V_28 ) ) ;
F_22 ( V_14 ,
F_3 ( V_14 ) ) ;
}
void T_1 F_23 ( void )
{
F_24 ( V_27 ,
F_3 ( V_27 ) ) ;
F_25 () ;
}
void T_1 F_26 ( void )
{
void T_2 * V_29 = F_7 ( 0xe6900010 , 0x10 ) ;
void T_2 * V_30 = F_7 ( 0xe6900040 , 0x10 ) ;
void T_2 * V_31 = F_7 ( 0xe605807c , 0x4 ) ;
F_27 () ;
F_8 ( 0x0 , V_31 ) ;
F_8 ( 0x0 , V_29 + 0x0 ) ;
F_8 ( 0x0 , V_29 + 0x4 ) ;
F_8 ( 0x0 , V_29 + 0x8 ) ;
F_8 ( 0x0 , V_29 + 0xc ) ;
F_28 ( 0xff , V_30 + 0x0 ) ;
F_28 ( 0xff , V_30 + 0x4 ) ;
F_28 ( 0xff , V_30 + 0x8 ) ;
F_28 ( 0xff , V_30 + 0xc ) ;
F_9 ( V_29 ) ;
F_9 ( V_30 ) ;
F_9 ( V_31 ) ;
}
static void T_1 F_29 ( void )
{
F_6 () ;
#ifdef F_30
F_31 ( F_32 ( 0xf0002000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_33 ( NULL , V_32 , NULL , NULL ) ;
}
static void F_34 ( enum V_33 V_34 , const char * V_35 )
{
F_35 ( 1 << 31 , V_36 ) ;
}
