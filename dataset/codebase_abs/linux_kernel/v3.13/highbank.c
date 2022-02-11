static void T_1 F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
V_2 = F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( void )
{
F_4 () ;
F_5 ( 0x102 , 0x0 ) ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
if ( F_8 ( NULL , NULL , L_1 ) )
F_1 () ;
if ( F_9 ( V_4 ) &&
F_8 ( NULL , NULL , L_2 ) ) {
F_5 ( 0x102 , 0x1 ) ;
F_10 ( 0 , ~ 0UL ) ;
V_5 . V_6 = F_3 ;
}
}
static void F_11 ( void )
{
F_12 () ;
while ( 1 )
F_13 () ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
struct V_11 * V_12 ;
int V_13 = - 1 ;
T_2 V_14 ;
struct V_15 * V_16 = V_10 ;
if ( V_9 != V_17 )
return V_18 ;
if ( F_15 ( V_16 -> V_19 , L_3 ) )
V_13 = 0xc ;
else if ( F_15 ( V_16 -> V_19 , L_4 ) )
V_13 = 0x18 ;
else if ( F_15 ( V_16 -> V_19 , L_5 ) )
V_13 = 0x20 ;
else if ( F_15 ( V_16 -> V_19 , L_6 ) ) {
V_12 = F_16 ( F_17 ( V_16 ) ,
V_20 , 0 ) ;
if ( V_12 ) {
if ( V_12 -> V_21 == 0xfff50000 )
V_13 = 0 ;
else if ( V_12 -> V_21 == 0xfff51000 )
V_13 = 4 ;
}
}
if ( V_13 < 0 )
return V_18 ;
if ( F_18 ( V_16 -> V_19 , L_7 ) ) {
V_14 = F_19 ( V_22 + V_13 ) ;
F_20 ( V_14 | 0xff01 , V_22 + V_13 ) ;
F_21 ( V_16 , & V_23 ) ;
}
return V_24 ;
}
static int F_22 ( struct V_7 * V_8 , unsigned long V_9 , void * V_25 )
{
T_2 V_26 = * ( T_2 * ) V_25 ;
if ( V_9 != 0x1000 )
return 0 ;
if ( V_26 == V_27 )
F_23 ( false ) ;
else if ( V_26 == 0xffff )
F_24 () ;
return 0 ;
}
static void T_1 F_25 ( void )
{
struct V_28 * V_29 ;
V_29 = F_8 ( NULL , NULL , L_8 ) ;
V_22 = F_26 ( V_29 , 0 ) ;
F_27 ( ! V_22 ) ;
V_30 = F_11 ;
F_28 () ;
F_29 ( & V_31 , & V_32 ) ;
F_29 ( & V_33 , & V_34 ) ;
F_30 ( & V_35 ) ;
F_31 ( NULL , V_36 , NULL , NULL ) ;
if ( V_37 . V_38 )
F_32 ( & V_39 ) ;
}
