static void T_1 F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
V_2 . V_3 = F_2 ( V_1 ) ;
F_3 ( & V_2 , 1 ) ;
}
static void T_1 F_4 ( void )
{
F_1 () ;
F_5 () ;
}
void F_6 ( int V_4 , void * V_5 )
{
V_4 = F_7 ( V_4 ) ;
F_8 ( F_9 ( V_5 ) , F_10 ( V_4 ) ) ;
F_11 ( F_10 ( V_4 ) , 16 ) ;
F_12 ( F_13 ( V_4 ) ,
F_13 ( V_4 ) + 15 ) ;
}
static void F_14 ( void )
{
F_15 ( 0x102 , 0x0 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_6 ) ;
#ifdef F_18
F_15 ( 0x102 , 0x1 ) ;
F_19 ( 0 , ~ 0UL ) ;
V_7 . V_8 = F_14 ;
#endif
}
static void T_1 F_20 ( void )
{
int V_9 ;
struct V_10 * V_11 ;
void T_2 * V_12 ;
V_11 = F_21 ( NULL , NULL , L_1 ) ;
V_13 = F_22 ( V_11 , 0 ) ;
F_23 ( ! V_13 ) ;
V_11 = F_21 ( NULL , NULL , L_2 ) ;
V_12 = F_22 ( V_11 , 0 ) ;
F_23 ( ! V_12 ) ;
V_9 = F_24 ( V_11 , 0 ) ;
F_25 () ;
V_14 . V_15 = F_26 ( V_11 , 0 ) ;
F_27 ( & V_14 ) ;
F_28 ( V_12 + 0x20 , L_3 ) ;
F_29 ( V_12 , V_9 , L_4 ) ;
F_30 () ;
}
static void F_31 ( void )
{
F_32 () ;
F_33 ( V_16 , V_17 ) ;
while ( 1 )
F_34 () ;
}
static int F_35 ( struct V_18 * V_19 ,
unsigned long V_20 , void * V_21 )
{
struct V_22 * V_23 ;
int V_24 = - 1 ;
struct V_25 * V_26 = V_21 ;
if ( V_20 != V_27 )
return V_28 ;
if ( F_36 ( V_26 -> V_29 , L_5 ) )
V_24 = 0xc ;
else if ( F_36 ( V_26 -> V_29 , L_6 ) )
V_24 = 0x18 ;
else if ( F_36 ( V_26 -> V_29 , L_7 ) )
V_24 = 0x20 ;
else if ( F_36 ( V_26 -> V_29 , L_8 ) ) {
V_23 = F_37 ( F_38 ( V_26 ) ,
V_30 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_31 == 0xfff50000 )
V_24 = 0 ;
else if ( V_23 -> V_31 == 0xfff51000 )
V_24 = 4 ;
}
}
if ( V_24 < 0 )
return V_28 ;
if ( F_39 ( V_26 -> V_29 , L_9 ) ) {
F_8 ( 0xff31 , V_13 + V_24 ) ;
F_40 ( V_26 , & V_32 ) ;
} else
F_8 ( 0 , V_13 + V_24 ) ;
return V_33 ;
}
static void T_1 F_41 ( void )
{
V_34 = F_31 ;
F_42 () ;
F_43 ( & V_35 , & V_36 ) ;
F_43 ( & V_37 , & V_38 ) ;
F_44 ( NULL , V_39 , NULL , NULL ) ;
}
