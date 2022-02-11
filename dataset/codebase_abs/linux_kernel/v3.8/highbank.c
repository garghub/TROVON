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
F_15 ( V_6 ) ;
if ( F_16 ( NULL , NULL , L_1 ) )
F_1 () ;
#ifdef F_17
F_13 ( 0x102 , 0x1 ) ;
F_18 ( 0 , ~ 0UL ) ;
V_7 . V_8 = F_12 ;
#endif
}
static void T_1 F_19 ( void )
{
int V_9 ;
struct V_10 * V_11 ;
void T_2 * V_12 ;
V_11 = F_16 ( NULL , NULL , L_2 ) ;
V_13 = F_20 ( V_11 , 0 ) ;
F_21 ( ! V_13 ) ;
V_11 = F_16 ( NULL , NULL , L_3 ) ;
V_12 = F_20 ( V_11 , 0 ) ;
F_21 ( ! V_12 ) ;
V_9 = F_22 ( V_11 , 0 ) ;
F_23 () ;
V_14 . V_15 = F_24 ( V_11 , 0 ) ;
F_25 ( & V_14 ) ;
F_26 ( V_12 + 0x20 , L_4 ) ;
F_27 ( V_12 , V_9 , L_5 ) ;
F_28 () ;
F_29 () ;
F_30 () ;
}
static void F_31 ( void )
{
F_32 () ;
while ( 1 )
F_33 () ;
}
static int F_34 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
struct V_20 * V_21 ;
int V_22 = - 1 ;
struct V_23 * V_24 = V_19 ;
if ( V_18 != V_25 )
return V_26 ;
if ( F_35 ( V_24 -> V_27 , L_6 ) )
V_22 = 0xc ;
else if ( F_35 ( V_24 -> V_27 , L_7 ) )
V_22 = 0x18 ;
else if ( F_35 ( V_24 -> V_27 , L_8 ) )
V_22 = 0x20 ;
else if ( F_35 ( V_24 -> V_27 , L_9 ) ) {
V_21 = F_36 ( F_37 ( V_24 ) ,
V_28 , 0 ) ;
if ( V_21 ) {
if ( V_21 -> V_29 == 0xfff50000 )
V_22 = 0 ;
else if ( V_21 -> V_29 == 0xfff51000 )
V_22 = 4 ;
}
}
if ( V_22 < 0 )
return V_26 ;
if ( F_38 ( V_24 -> V_27 , L_10 ) ) {
F_6 ( 0xff31 , V_13 + V_22 ) ;
F_39 ( V_24 , & V_30 ) ;
} else
F_6 ( 0 , V_13 + V_22 ) ;
return V_31 ;
}
static void T_1 F_40 ( void )
{
V_32 = F_31 ;
F_41 () ;
F_42 ( & V_33 , & V_34 ) ;
F_42 ( & V_35 , & V_36 ) ;
F_43 ( NULL , V_37 , NULL , NULL ) ;
}
