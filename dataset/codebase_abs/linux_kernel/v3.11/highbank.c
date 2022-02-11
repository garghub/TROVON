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
#ifdef F_17
F_13 ( 0x102 , 0x1 ) ;
F_18 ( 0 , ~ 0UL ) ;
V_6 . V_7 = F_12 ;
#endif
}
static void T_1 F_19 ( void )
{
struct V_8 * V_9 ;
V_9 = F_16 ( NULL , NULL , L_2 ) ;
V_10 = F_20 ( V_9 , 0 ) ;
F_21 ( ! V_10 ) ;
F_22 ( NULL ) ;
F_23 () ;
}
static void F_24 ( void )
{
F_25 () ;
while ( 1 )
F_26 () ;
}
static int F_27 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
struct V_15 * V_16 ;
int V_17 = - 1 ;
T_2 V_18 ;
struct V_19 * V_20 = V_14 ;
if ( V_13 != V_21 )
return V_22 ;
if ( F_28 ( V_20 -> V_23 , L_3 ) )
V_17 = 0xc ;
else if ( F_28 ( V_20 -> V_23 , L_4 ) )
V_17 = 0x18 ;
else if ( F_28 ( V_20 -> V_23 , L_5 ) )
V_17 = 0x20 ;
else if ( F_28 ( V_20 -> V_23 , L_6 ) ) {
V_16 = F_29 ( F_30 ( V_20 ) ,
V_24 , 0 ) ;
if ( V_16 ) {
if ( V_16 -> V_25 == 0xfff50000 )
V_17 = 0 ;
else if ( V_16 -> V_25 == 0xfff51000 )
V_17 = 4 ;
}
}
if ( V_17 < 0 )
return V_22 ;
if ( F_31 ( V_20 -> V_23 , L_7 ) ) {
V_18 = F_32 ( V_10 + V_17 ) ;
F_6 ( V_18 | 0xff01 , V_10 + V_17 ) ;
F_33 ( V_20 , & V_26 ) ;
}
return V_27 ;
}
static void T_1 F_34 ( void )
{
V_28 = F_24 ;
F_35 () ;
F_36 ( & V_29 , & V_30 ) ;
F_36 ( & V_31 , & V_32 ) ;
F_37 ( NULL , V_33 , NULL , NULL ) ;
}
