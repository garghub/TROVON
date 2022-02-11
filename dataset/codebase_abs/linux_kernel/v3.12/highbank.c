static void T_1 F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
V_2 = F_2 ( V_1 , V_3 ) ;
}
void F_3 ( int V_4 , void * V_5 )
{
V_4 = F_4 ( F_5 ( V_4 ) , 0 ) ;
F_6 ( F_7 ( V_5 ) , F_8 ( V_4 ) ) ;
F_9 ( F_8 ( V_4 ) , 16 ) ;
F_10 ( F_11 ( V_4 ) ,
F_11 ( V_4 ) + 15 ) ;
}
static void F_12 ( void )
{
F_13 ( 0x102 , 0x0 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
if ( F_16 ( NULL , NULL , L_1 ) )
F_1 () ;
if ( F_17 ( V_6 ) &&
F_16 ( NULL , NULL , L_2 ) ) {
F_13 ( 0x102 , 0x1 ) ;
F_18 ( 0 , ~ 0UL ) ;
V_7 . V_8 = F_12 ;
}
}
static void T_1 F_19 ( void )
{
struct V_9 * V_10 ;
V_10 = F_16 ( NULL , NULL , L_3 ) ;
V_11 = F_20 ( V_10 , 0 ) ;
F_21 ( ! V_11 ) ;
F_22 ( NULL ) ;
F_23 () ;
}
static void F_24 ( void )
{
F_25 () ;
while ( 1 )
F_26 () ;
}
static int F_27 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
struct V_16 * V_17 ;
int V_18 = - 1 ;
T_2 V_19 ;
struct V_20 * V_21 = V_15 ;
if ( V_14 != V_22 )
return V_23 ;
if ( F_28 ( V_21 -> V_24 , L_4 ) )
V_18 = 0xc ;
else if ( F_28 ( V_21 -> V_24 , L_5 ) )
V_18 = 0x18 ;
else if ( F_28 ( V_21 -> V_24 , L_6 ) )
V_18 = 0x20 ;
else if ( F_28 ( V_21 -> V_24 , L_7 ) ) {
V_17 = F_29 ( F_30 ( V_21 ) ,
V_25 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_26 == 0xfff50000 )
V_18 = 0 ;
else if ( V_17 -> V_26 == 0xfff51000 )
V_18 = 4 ;
}
}
if ( V_18 < 0 )
return V_23 ;
if ( F_31 ( V_21 -> V_24 , L_8 ) ) {
V_19 = F_32 ( V_11 + V_18 ) ;
F_6 ( V_19 | 0xff01 , V_11 + V_18 ) ;
F_33 ( V_21 , & V_27 ) ;
}
return V_28 ;
}
static void T_1 F_34 ( void )
{
V_29 = F_24 ;
F_35 () ;
F_36 ( & V_30 , & V_31 ) ;
F_36 ( & V_32 , & V_33 ) ;
F_37 ( NULL , V_34 , NULL , NULL ) ;
}
