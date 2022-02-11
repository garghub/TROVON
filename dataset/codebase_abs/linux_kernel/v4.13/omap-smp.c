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
F_13 ( & V_11 ) ;
if ( F_16 () )
F_17 ( V_19 ,
0xfffffdff ) ;
else
F_18 ( V_20 ,
V_1 . V_21 + V_22 ) ;
if ( ! V_15 && ! V_18 ) {
V_15 = F_19 ( L_2 ) ;
V_18 = F_20 ( L_3 ) ;
}
if ( V_16 && V_18 && V_15 ) {
if ( F_21 ( V_23 ) ) {
F_22 () ;
F_23 () ;
}
F_24 ( V_15 ) ;
F_25 ( V_18 , V_24 ) ;
F_26 ( V_15 ) ;
if ( F_21 ( V_23 ) ) {
while ( F_27 () ) {
F_28 ( 1 ) ;
F_29 () ;
}
F_30 () ;
F_31 () ;
}
} else {
F_32 () ;
V_16 = true ;
}
F_33 ( F_34 ( V_8 ) ) ;
F_14 ( & V_11 ) ;
return 0 ;
}
static void T_3 F_35 ( void )
{
unsigned int V_25 = 0 , V_26 = 1 , V_27 ;
V_27 = F_36 () & V_28 ;
if ( V_27 == V_29 ) {
V_1 . V_2 = F_37 ( F_38 () ) ;
F_39 ( ! V_1 . V_2 ) ;
V_26 = F_40 ( V_1 . V_2 ) ;
} else if ( V_27 == V_30 ) {
V_26 = V_31 ;
}
if ( V_26 > V_32 ) {
F_41 ( L_4 ,
V_26 , V_32 ) ;
V_26 = V_32 ;
}
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ )
F_42 ( V_25 , true ) ;
}
static bool T_3 F_43 ( unsigned long V_33 )
{
if ( ( V_33 >= F_44 ( V_34 ) ) && ( V_33 <= F_44 ( V_35 ) ) )
return false ;
return true ;
}
static void T_3 F_45 ( struct V_36 * V_37 )
{
unsigned long V_38 , V_39 ;
bool V_40 = false ;
T_2 V_41 ;
if ( F_16 () )
V_41 = F_46 () & V_19 ;
else
V_41 = F_47 ( V_1 . V_21 +
V_22 ) &
V_20 ;
if ( V_41 ) {
F_41 ( L_5 ) ;
return;
}
V_38 = F_47 ( V_1 . V_21 +
V_42 ) ;
if ( ! F_43 ( V_38 ) )
V_40 = true ;
if ( ( F_48 () || F_10 () ) ) {
V_39 = F_49 () ;
if ( ! F_43 ( V_39 ) )
V_40 = true ;
} else {
V_39 = 0 ;
}
if ( ! V_40 || ! V_37 -> V_43 )
return;
F_50 ( L_6 ,
V_38 , V_39 ) ;
F_18 ( 1 , V_37 -> V_43 ) ;
F_47 ( V_37 -> V_43 ) ;
F_18 ( 0 , V_37 -> V_43 ) ;
}
static void T_3 F_51 ( unsigned int V_44 )
{
const struct V_36 * V_37 = NULL ;
if ( F_7 () )
V_37 = & V_45 ;
else if ( F_52 () )
V_37 = & V_46 ;
else if ( F_53 () || F_10 () )
V_37 = & V_47 ;
if ( ! V_37 ) {
F_54 ( L_7 , V_7 ) ;
return;
}
V_1 . V_48 = V_37 -> V_48 ;
V_1 . V_49 = V_37 -> V_49 ;
V_1 . V_21 = F_55 () ;
if ( F_53 () || F_10 () ) {
if ( ( V_50 & V_51 ) == V_52 )
V_1 . V_49 = V_53 ;
F_2 () ;
}
V_1 . V_43 = F_56 ( V_1 . V_48 , 4 ) ;
if ( ! V_1 . V_43 )
return;
if ( V_1 . V_2 )
F_57 ( V_1 . V_2 ) ;
F_45 ( & V_1 ) ;
if ( F_16 () )
F_58 ( F_59 ( V_1 . V_49 ) ) ;
else
F_18 ( F_59 ( V_1 . V_49 ) ,
V_1 . V_21 + V_42 ) ;
}
