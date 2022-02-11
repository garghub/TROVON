static void T_1 F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
V_2 = F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( unsigned long V_4 , unsigned V_5 )
{
if ( V_5 == V_6 )
F_4 ( 0x102 , V_4 ) ;
else
F_5 ( 1 , L_1 ,
V_5 ) ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
if ( F_8 ( NULL , NULL , L_2 ) )
F_1 () ;
}
static void F_9 ( void )
{
F_10 () ;
while ( 1 )
F_11 () ;
}
static int F_12 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
struct V_11 * V_12 ;
int V_5 = - 1 ;
T_2 V_4 ;
struct V_13 * V_14 = V_10 ;
if ( V_9 != V_15 )
return V_16 ;
if ( F_13 ( V_14 -> V_17 , L_3 ) )
V_5 = 0xc ;
else if ( F_13 ( V_14 -> V_17 , L_4 ) )
V_5 = 0x18 ;
else if ( F_13 ( V_14 -> V_17 , L_5 ) )
V_5 = 0x20 ;
else if ( F_13 ( V_14 -> V_17 , L_6 ) ) {
V_12 = F_14 ( F_15 ( V_14 ) ,
V_18 , 0 ) ;
if ( V_12 ) {
if ( V_12 -> V_19 == 0xfff50000 )
V_5 = 0 ;
else if ( V_12 -> V_19 == 0xfff51000 )
V_5 = 4 ;
}
}
if ( V_5 < 0 )
return V_16 ;
if ( F_16 ( V_14 -> V_17 , L_7 ) ) {
V_4 = F_17 ( V_20 + V_5 ) ;
F_18 ( V_4 | 0xff01 , V_20 + V_5 ) ;
F_19 ( V_14 , & V_21 ) ;
}
return V_22 ;
}
static int F_20 ( struct V_7 * V_8 , unsigned long V_9 , void * V_23 )
{
T_2 V_24 = * ( T_2 * ) V_23 ;
if ( V_9 != 0x1000 )
return 0 ;
if ( V_24 == V_25 )
F_21 ( false ) ;
else if ( V_24 == 0xffff )
F_22 () ;
return 0 ;
}
static void T_1 F_23 ( void )
{
struct V_26 * V_27 ;
V_27 = F_8 ( NULL , NULL , L_8 ) ;
V_20 = F_24 ( V_27 , 0 ) ;
F_25 ( ! V_20 ) ;
V_28 = F_9 ;
F_26 () ;
F_27 ( & V_29 , & V_30 ) ;
F_27 ( & V_31 , & V_32 ) ;
F_28 ( & V_33 ) ;
if ( V_34 . V_35 )
F_29 ( & V_36 ) ;
}
