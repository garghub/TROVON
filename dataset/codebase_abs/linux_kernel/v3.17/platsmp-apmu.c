static int T_1 F_1 ( void T_2 * V_1 , int V_2 )
{
F_2 ( F_3 ( V_2 ) , V_1 + V_3 ) ;
while ( F_4 ( V_1 + V_3 ) != 0 )
;
return 0 ;
}
static int F_5 ( void T_2 * V_1 , int V_2 )
{
F_2 ( 3 , V_1 + F_6 ( V_2 ) ) ;
return 0 ;
}
static int T_1 F_7 ( void T_2 * V_1 , int V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( ( ( F_4 ( V_1 + V_5 ) >> ( V_2 * 4 ) ) & 0x03 ) == 3 )
return 1 ;
F_8 ( 1 ) ;
}
return 0 ;
}
static int F_9 ( int V_6 , int (* F_10)( void T_2 * V_1 , int V_6 ) )
{
void T_2 * V_1 = V_7 [ V_6 ] . V_8 ;
return V_1 ? F_10 ( V_1 , V_7 [ V_6 ] . V_2 ) : - V_9 ;
}
static void F_11 ( struct V_10 * V_11 , int V_6 , int V_2 )
{
if ( ( V_6 >= F_12 ( V_7 ) ) || V_7 [ V_6 ] . V_8 )
return;
V_7 [ V_6 ] . V_8 = F_13 ( V_11 -> V_12 , F_14 ( V_11 ) ) ;
V_7 [ V_6 ] . V_2 = V_2 ;
F_15 ( L_1 , V_6 , V_2 , V_11 ) ;
}
static void F_16 ( void (* F_10)( struct V_10 * V_11 , int V_6 , int V_2 ) )
{
T_3 V_13 ;
int V_4 ;
int V_2 , V_14 ;
bool V_15 ;
for ( V_4 = 0 ; V_4 < F_12 ( V_16 ) ; V_4 ++ ) {
V_15 = false ;
for ( V_2 = 0 ; V_2 < F_12 ( V_16 [ V_4 ] . V_17 ) ; V_2 ++ ) {
V_13 = V_16 [ V_4 ] . V_17 [ V_2 ] ;
if ( V_13 >= 0 ) {
if ( V_13 == F_17 ( 0 ) )
V_15 = true ;
}
}
if ( ! V_15 )
continue;
for ( V_2 = 0 ; V_2 < F_12 ( V_16 [ V_4 ] . V_17 ) ; V_2 ++ ) {
V_13 = V_16 [ V_4 ] . V_17 [ V_2 ] ;
if ( V_13 >= 0 ) {
V_14 = F_18 ( V_13 ) ;
if ( V_14 >= 0 )
F_10 ( & V_16 [ V_4 ] . V_8 , V_14 , V_2 ) ;
}
}
}
}
void T_4 F_19 ( unsigned int V_18 )
{
V_19 = F_20 ( V_20 ) ;
V_21 = V_22 ;
F_16 ( F_11 ) ;
}
int F_21 ( unsigned int V_6 , struct V_23 * V_24 )
{
F_22 ( V_6 , F_20 ( V_25 ) , 0 ) ;
return F_9 ( V_6 , F_1 ) ;
}
static inline void F_23 ( void )
{
unsigned int V_26 ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
F_24 () ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (0x40)
: "cc");
F_25 () ;
F_26 () ;
}
void F_27 ( unsigned int V_6 )
{
F_9 ( V_6 , F_5 ) ;
F_23 () ;
}
static inline void F_28 ( void )
{
unsigned int V_26 ;
asm volatile("mrc p15, 0, %0, c1, c0, 0\n"
" orr %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" orr %0, %0, %2\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (CR_C), "Ir" (0x40)
: "cc");
}
void F_29 ( unsigned int V_6 )
{
F_22 ( V_6 , 0 , 0 ) ;
F_27 ( V_6 ) ;
F_30 () ;
}
int F_31 ( unsigned int V_6 )
{
return F_9 ( V_6 , F_7 ) ;
}
static int F_32 ( unsigned long V_6 )
{
F_22 ( V_6 , F_20 ( V_27 ) , 0 ) ;
F_27 ( V_6 ) ;
F_33 () ;
return 1 ;
}
static int F_34 ( T_5 V_28 )
{
F_35 ( F_36 () , F_32 ) ;
F_28 () ;
return 0 ;
}
void T_4 F_37 ( void )
{
V_29 . V_30 = F_34 ;
}
