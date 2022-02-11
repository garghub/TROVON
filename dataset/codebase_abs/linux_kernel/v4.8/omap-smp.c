void T_1 * F_1 ( void )
{
return V_1 . V_2 ;
}
void F_2 ( void )
{
T_2 V_3 , V_4 ;
T_2 V_5 ;
asm volatile ("mrc p15, 0, %0, c0, c0, 6" : "=r" (revidr));
if ( V_4 & ( 0x1 << 3 ) )
return;
asm volatile ("mrc p15, 0, %0, c1, c0, 1" : "=r" (acr));
V_5 = ( 0x3 << 25 ) | ( 0x3 << 27 ) ;
if ( ( V_3 & V_5 ) == V_5 )
return;
V_3 |= V_5 ;
F_3 ( V_6 , V_3 ) ;
F_4 ( L_1 ,
V_7 , F_5 () ) ;
}
static inline void F_2 ( void ) { }
static void F_6 ( unsigned int V_8 )
{
if ( F_7 () && ( F_8 () != V_9 ) )
F_9 ( V_10 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
if ( F_10 () || F_11 () ) {
F_12 () ;
F_2 () ;
}
F_13 ( & V_11 ) ;
F_14 ( & V_11 ) ;
}
static int F_15 ( unsigned int V_8 , struct V_12 * V_13 )
{
static struct V_14 * V_15 ;
static bool V_16 ;
static struct V_17 * V_18 ;
void T_1 * V_19 = F_16 () ;
F_13 ( & V_11 ) ;
if ( F_17 () )
F_18 ( 0x200 , 0xfffffdff ) ;
else
F_19 ( 0x20 , V_19 + V_20 ) ;
if ( ! V_15 && ! V_18 ) {
V_15 = F_20 ( L_2 ) ;
V_18 = F_21 ( L_3 ) ;
}
if ( V_16 && V_18 && V_15 ) {
if ( F_22 ( V_21 ) ) {
F_23 () ;
F_24 () ;
}
F_25 ( V_15 ) ;
F_26 ( V_18 , V_22 ) ;
F_27 ( V_15 ) ;
if ( F_22 ( V_21 ) ) {
while ( F_28 () ) {
F_29 ( 1 ) ;
F_30 () ;
}
F_31 () ;
F_32 () ;
}
} else {
F_33 () ;
V_16 = true ;
}
F_34 ( F_35 ( V_8 ) ) ;
F_14 ( & V_11 ) ;
return 0 ;
}
static void T_3 F_36 ( void )
{
unsigned int V_23 = 0 , V_24 = 1 , V_25 ;
V_25 = F_37 () & V_26 ;
if ( V_25 == V_27 ) {
V_1 . V_2 = F_38 ( F_39 () ) ;
F_40 ( ! V_1 . V_2 ) ;
V_24 = F_41 ( V_1 . V_2 ) ;
} else if ( V_25 == V_28 ) {
V_24 = V_29 ;
}
if ( V_24 > V_30 ) {
F_42 ( L_4 ,
V_24 , V_30 ) ;
V_24 = V_30 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
F_43 ( V_23 , true ) ;
}
static void T_3 F_44 ( unsigned int V_31 )
{
void T_1 * V_19 = F_16 () ;
const struct V_32 * V_33 = NULL ;
if ( F_7 () )
V_33 = & V_34 ;
else if ( F_45 () )
V_33 = & V_35 ;
else if ( F_46 () || F_10 () )
V_33 = & V_36 ;
if ( ! V_33 ) {
F_47 ( L_5 , V_7 ) ;
return;
}
V_1 . V_37 = V_33 -> V_37 ;
V_1 . V_38 = V_33 -> V_38 ;
if ( F_46 () || F_10 () ) {
if ( ( V_39 & V_40 ) == V_41 )
V_1 . V_38 = V_42 ;
F_2 () ;
}
V_1 . V_43 = F_48 ( V_1 . V_37 , 4 ) ;
if ( ! V_1 . V_43 )
return;
if ( V_1 . V_2 )
F_49 ( V_1 . V_2 ) ;
if ( V_1 . V_43 ) {
F_19 ( 1 , V_1 . V_43 ) ;
F_50 ( V_1 . V_43 ) ;
F_19 ( 0 , V_1 . V_43 ) ;
}
if ( F_17 () )
F_51 ( F_52 ( V_1 . V_38 ) ) ;
else
F_19 ( F_52 ( V_1 . V_38 ) ,
V_19 + V_44 ) ;
}
