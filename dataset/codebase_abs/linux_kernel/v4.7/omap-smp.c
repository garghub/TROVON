void T_1 * F_1 ( void )
{
return V_1 ;
}
void F_2 ( void )
{
T_2 V_2 , V_3 ;
T_2 V_4 ;
asm volatile ("mrc p15, 0, %0, c0, c0, 6" : "=r" (revidr));
if ( V_3 & ( 0x1 << 3 ) )
return;
asm volatile ("mrc p15, 0, %0, c1, c0, 1" : "=r" (acr));
V_4 = ( 0x3 << 25 ) | ( 0x3 << 27 ) ;
if ( ( V_2 & V_4 ) == V_4 )
return;
V_2 |= V_4 ;
F_3 ( V_5 , V_2 ) ;
F_4 ( L_1 ,
V_6 , F_5 () ) ;
}
static inline void F_2 ( void ) { }
static void F_6 ( unsigned int V_7 )
{
if ( F_7 () && ( F_8 () != V_8 ) )
F_9 ( V_9 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
if ( F_10 () || F_11 () ) {
F_12 () ;
F_2 () ;
}
F_13 ( & V_10 ) ;
F_14 ( & V_10 ) ;
}
static int F_15 ( unsigned int V_7 , struct V_11 * V_12 )
{
static struct V_13 * V_14 ;
static bool V_15 ;
static struct V_16 * V_17 ;
void T_1 * V_18 = F_16 () ;
F_13 ( & V_10 ) ;
if ( F_17 () )
F_18 ( 0x200 , 0xfffffdff ) ;
else
F_19 ( 0x20 , V_18 + V_19 ) ;
if ( ! V_14 && ! V_17 ) {
V_14 = F_20 ( L_2 ) ;
V_17 = F_21 ( L_3 ) ;
}
if ( V_15 && V_17 && V_14 ) {
if ( F_22 ( V_20 ) ) {
F_23 () ;
F_24 () ;
}
F_25 ( V_14 ) ;
F_26 ( V_17 , V_21 ) ;
F_27 ( V_14 ) ;
if ( F_22 ( V_20 ) ) {
while ( F_28 () ) {
F_29 ( 1 ) ;
F_30 () ;
}
F_31 () ;
F_32 () ;
}
} else {
F_33 () ;
V_15 = true ;
}
F_34 ( F_35 ( V_7 ) ) ;
F_14 ( & V_10 ) ;
return 0 ;
}
static void T_3 F_36 ( void )
{
unsigned int V_22 = 0 , V_23 = 1 , V_24 ;
V_24 = F_37 () & V_25 ;
if ( V_24 == V_26 ) {
V_1 = F_38 ( F_39 () ) ;
F_40 ( ! V_1 ) ;
V_23 = F_41 ( V_1 ) ;
} else if ( V_24 == V_27 ) {
V_23 = V_28 ;
}
if ( V_23 > V_29 ) {
F_42 ( L_4 ,
V_23 , V_29 ) ;
V_23 = V_29 ;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
F_43 ( V_22 , true ) ;
}
static void T_3 F_44 ( unsigned int V_30 )
{
void * V_31 = V_32 ;
void T_1 * V_18 = F_16 () ;
if ( V_1 )
F_45 ( V_1 ) ;
if ( F_46 () )
V_31 = V_33 ;
if ( F_47 () || F_10 () )
F_2 () ;
if ( F_17 () )
F_48 ( F_49 ( V_31 ) ) ;
else
if ( ( V_34 & V_35 ) == V_36 )
F_19 ( F_49 ( V_37 ) ,
V_18 + V_38 ) ;
else
F_19 ( F_49 ( V_39 ) ,
V_18 + V_38 ) ;
}
