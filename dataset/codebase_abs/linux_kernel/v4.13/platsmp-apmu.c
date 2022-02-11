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
if ( F_8 ( F_4 ( V_1 + V_5 ) , V_2 ) == V_6 )
return 1 ;
F_9 ( 1 ) ;
}
return 0 ;
}
static int T_1 F_10 ( int V_7 , int (* F_11)( void T_2 * V_1 , int V_7 ) )
{
void T_2 * V_1 = V_8 [ V_7 ] . V_9 ;
return V_1 ? F_11 ( V_1 , V_8 [ V_7 ] . V_2 ) : - V_10 ;
}
static void F_12 ( struct V_11 * V_12 , int V_7 , int V_2 )
{
T_3 V_13 ;
if ( ( V_7 >= F_13 ( V_8 ) ) || V_8 [ V_7 ] . V_9 )
return;
V_8 [ V_7 ] . V_9 = F_14 ( V_12 -> V_14 , F_15 ( V_12 ) ) ;
V_8 [ V_7 ] . V_2 = V_2 ;
F_16 ( L_1 , V_7 , V_2 , V_12 ) ;
V_13 = F_17 ( V_8 [ V_7 ] . V_9 + V_15 ) ;
V_13 |= V_16 | F_18 ( V_2 ) | V_17 ;
F_19 ( V_13 , V_8 [ V_7 ] . V_9 + V_15 ) ;
}
static void F_20 ( void (* F_11)( struct V_11 * V_12 , int V_7 , int V_2 ) ,
struct V_18 * V_19 , int V_20 )
{
int V_21 ;
int V_4 ;
int V_2 , V_22 ;
bool V_23 ;
for ( V_4 = 0 ; V_4 < V_20 ; V_4 ++ ) {
V_23 = false ;
for ( V_2 = 0 ; V_2 < F_13 ( V_19 [ V_4 ] . V_24 ) ; V_2 ++ ) {
V_21 = V_19 [ V_4 ] . V_24 [ V_2 ] ;
if ( V_21 >= 0 ) {
if ( V_21 == F_21 ( 0 ) )
V_23 = true ;
}
}
if ( ! V_23 )
continue;
for ( V_2 = 0 ; V_2 < F_13 ( V_19 [ V_4 ] . V_24 ) ; V_2 ++ ) {
V_21 = V_19 [ V_4 ] . V_24 [ V_2 ] ;
if ( V_21 >= 0 ) {
V_22 = F_22 ( V_21 ) ;
if ( V_22 >= 0 )
F_11 ( & V_19 [ V_4 ] . V_9 , V_22 , V_2 ) ;
}
}
}
}
static void F_23 ( void (* F_11)( struct V_11 * V_12 , int V_7 , int V_2 ) )
{
struct V_25 * V_26 , * V_27 ;
struct V_11 V_12 ;
int V_2 , V_22 ;
T_3 V_21 ;
F_24 (np_apmu, apmu_ids) {
bool V_23 = false ;
for ( V_2 = 0 ; V_2 < V_28 ; V_2 ++ ) {
V_27 = F_25 ( V_26 , L_2 , V_2 ) ;
if ( V_27 ) {
if ( ! F_26 ( V_27 , L_3 , & V_21 ) ) {
if ( V_21 == F_21 ( 0 ) ) {
V_23 = true ;
F_27 ( V_27 ) ;
break;
}
}
F_27 ( V_27 ) ;
}
}
if ( ! V_23 )
continue;
for ( V_2 = 0 ; V_2 < V_28 ; V_2 ++ ) {
V_27 = F_25 ( V_26 , L_2 , V_2 ) ;
if ( V_27 ) {
if ( ! F_26 ( V_27 , L_3 , & V_21 ) ) {
V_22 = F_22 ( V_21 ) ;
if ( ( V_22 >= 0 ) &&
! F_28 ( V_26 ,
0 , & V_12 ) )
F_11 ( & V_12 , V_22 , V_2 ) ;
}
F_27 ( V_27 ) ;
}
}
}
}
static void T_4 F_29 ( void )
{
V_29 = F_30 ( V_30 ) ;
}
void T_4 F_31 ( unsigned int V_31 ,
struct V_18 * V_19 ,
int V_20 )
{
F_29 () ;
F_20 ( F_12 , V_19 , V_20 ) ;
}
int F_32 ( unsigned int V_7 , struct V_32 * V_33 )
{
F_33 ( V_7 , F_30 ( V_34 ) , 0 ) ;
return F_10 ( V_7 , F_1 ) ;
}
static void T_4 F_34 ( unsigned int V_31 )
{
F_29 () ;
F_23 ( F_12 ) ;
F_35 () ;
}
static inline void F_36 ( void )
{
unsigned int V_35 ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
F_37 () ;
asm volatile(
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (0x40)
: "cc");
F_38 () ;
F_39 () ;
}
static void F_40 ( unsigned int V_7 )
{
F_10 ( V_7 , F_5 ) ;
F_36 () ;
}
static inline void F_41 ( void )
{
unsigned int V_35 ;
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
void F_42 ( unsigned int V_7 )
{
F_33 ( V_7 , 0 , 0 ) ;
F_40 ( V_7 ) ;
F_43 () ;
}
int F_44 ( unsigned int V_7 )
{
return F_10 ( V_7 , F_7 ) ;
}
static int F_45 ( unsigned long V_7 )
{
F_33 ( V_7 , F_30 ( V_36 ) , 0 ) ;
F_40 ( V_7 ) ;
F_46 () ;
return 1 ;
}
static int F_47 ( T_5 V_37 )
{
F_48 ( F_49 () , F_45 ) ;
F_41 () ;
return 0 ;
}
void T_4 F_50 ( void )
{
V_38 . V_39 = F_47 ;
}
