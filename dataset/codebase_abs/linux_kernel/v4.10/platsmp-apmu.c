static int T_1 F_1 ( void T_2 * V_1 , int V_2 )
{
F_2 ( F_3 ( V_2 ) , V_1 + V_3 ) ;
while ( F_4 ( V_1 + V_3 ) != 0 )
;
return 0 ;
}
static int T_1 F_5 ( void T_2 * V_1 , int V_2 )
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
static int T_1 F_9 ( int V_6 , int (* F_10)( void T_2 * V_1 , int V_6 ) )
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
static void F_16 ( void (* F_10)( struct V_10 * V_11 , int V_6 , int V_2 ) ,
struct V_13 * V_14 , int V_15 )
{
int V_16 ;
int V_4 ;
int V_2 , V_17 ;
bool V_18 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
V_18 = false ;
for ( V_2 = 0 ; V_2 < F_12 ( V_14 [ V_4 ] . V_19 ) ; V_2 ++ ) {
V_16 = V_14 [ V_4 ] . V_19 [ V_2 ] ;
if ( V_16 >= 0 ) {
if ( V_16 == F_17 ( 0 ) )
V_18 = true ;
}
}
if ( ! V_18 )
continue;
for ( V_2 = 0 ; V_2 < F_12 ( V_14 [ V_4 ] . V_19 ) ; V_2 ++ ) {
V_16 = V_14 [ V_4 ] . V_19 [ V_2 ] ;
if ( V_16 >= 0 ) {
V_17 = F_18 ( V_16 ) ;
if ( V_17 >= 0 )
F_10 ( & V_14 [ V_4 ] . V_8 , V_17 , V_2 ) ;
}
}
}
}
static void F_19 ( void (* F_10)( struct V_10 * V_11 , int V_6 , int V_2 ) )
{
struct V_20 * V_21 , * V_22 ;
struct V_10 V_11 ;
int V_2 , V_17 ;
T_3 V_16 ;
F_20 (np_apmu, apmu_ids) {
bool V_18 = false ;
for ( V_2 = 0 ; V_2 < V_23 ; V_2 ++ ) {
V_22 = F_21 ( V_21 , L_2 , V_2 ) ;
if ( V_22 ) {
if ( ! F_22 ( V_22 , L_3 , & V_16 ) ) {
if ( V_16 == F_17 ( 0 ) ) {
V_18 = true ;
F_23 ( V_22 ) ;
break;
}
}
F_23 ( V_22 ) ;
}
}
if ( ! V_18 )
continue;
for ( V_2 = 0 ; V_2 < V_23 ; V_2 ++ ) {
V_22 = F_21 ( V_21 , L_2 , V_2 ) ;
if ( V_22 ) {
if ( ! F_22 ( V_22 , L_3 , & V_16 ) ) {
V_17 = F_18 ( V_16 ) ;
if ( ( V_17 >= 0 ) &&
! F_24 ( V_21 ,
0 , & V_11 ) )
F_10 ( & V_11 , V_17 , V_2 ) ;
}
F_23 ( V_22 ) ;
}
}
}
}
static void T_4 F_25 ( void )
{
V_24 = F_26 ( V_25 ) ;
}
void T_4 F_27 ( unsigned int V_26 ,
struct V_13 * V_14 ,
int V_15 )
{
F_25 () ;
F_16 ( F_11 , V_14 , V_15 ) ;
}
int F_28 ( unsigned int V_6 , struct V_27 * V_28 )
{
F_29 ( V_6 , F_26 ( V_29 ) , 0 ) ;
return F_9 ( V_6 , F_1 ) ;
}
static void T_4 F_30 ( unsigned int V_26 )
{
F_25 () ;
F_19 ( F_11 ) ;
F_31 () ;
}
static int F_32 ( unsigned int V_6 ,
struct V_27 * V_28 )
{
if ( F_33 () & F_3 ( 21 ) ) {
F_34 ( L_4 , V_6 ) ;
return - V_30 ;
}
return F_28 ( V_6 , V_28 ) ;
}
static inline void F_35 ( void )
{
unsigned int V_31 ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
F_36 () ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (0x40)
: "cc");
F_37 () ;
F_38 () ;
}
static void F_39 ( unsigned int V_6 )
{
F_9 ( V_6 , F_5 ) ;
F_35 () ;
}
static inline void F_40 ( void )
{
unsigned int V_31 ;
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
void F_41 ( unsigned int V_6 )
{
F_29 ( V_6 , 0 , 0 ) ;
F_39 ( V_6 ) ;
F_42 () ;
}
int F_43 ( unsigned int V_6 )
{
return F_9 ( V_6 , F_7 ) ;
}
static int F_44 ( unsigned long V_6 )
{
F_29 ( V_6 , F_26 ( V_32 ) , 0 ) ;
F_39 ( V_6 ) ;
F_45 () ;
return 1 ;
}
static int F_46 ( T_5 V_33 )
{
F_47 ( F_48 () , F_44 ) ;
F_40 () ;
return 0 ;
}
void T_4 F_49 ( void )
{
V_34 . V_35 = F_46 ;
}
