static inline unsigned long F_1 ( void )
{
unsigned int V_1 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (SRMMU_CTXTBL_PTR),
"i" (ASI_LEON_MMUREGS));
return ( V_1 & V_2 ) << 4 ;
}
unsigned long F_2 ( unsigned long V_3 , unsigned long * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 , V_7 , V_8 ;
unsigned int V_9 ;
unsigned int V_10 , V_11 , V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
V_12 = 0 ;
if ( V_15 )
F_3 ( V_16 L_1 ) ;
V_5 = F_1 () ;
if ( ! ( V_5 ) ) {
if ( V_15 )
F_3 ( V_16 L_2 ) ;
return 0 ;
}
if ( ! F_4 ( F_5 ( V_5 ) ) ) {
if ( V_15 )
F_3 ( V_16
L_3 ,
F_5 ( V_5 ) ) ;
return 0 ;
}
V_13 = F_6 () ;
if ( V_15 )
F_3 ( V_16 L_4 , V_13 ) ;
V_6 = F_7 ( V_5 + ( V_13 * 4 ) ) ;
if ( ( ( V_6 & V_17 ) == V_18 ) ) {
if ( V_15 )
F_3 ( V_16 L_5 ) ;
V_10 = 3 ;
V_11 = V_6 ;
V_12 = V_6 & V_19 ;
goto V_20;
}
if ( ( ( V_6 & V_17 ) != V_21 ) ) {
if ( V_15 )
F_3 ( V_16 L_6 ) ;
return 0 ;
}
if ( V_15 )
F_3 ( V_16 L_7 , V_6 ) ;
V_9 = ( V_6 & V_22 ) << 4 ;
V_9 += ( ( ( ( V_3 ) >> V_23 ) & V_24 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_9 ) ) )
return 0 ;
V_7 = F_7 ( V_9 ) ;
if ( ( ( V_7 & V_17 ) == V_18 ) ) {
if ( V_15 )
F_3 ( V_16 L_8 ) ;
V_10 = 2 ;
V_11 = V_7 ;
V_12 = V_7 & V_19 ;
goto V_20;
}
if ( ( ( V_7 & V_17 ) != V_21 ) ) {
if ( V_15 )
F_3 ( V_16 L_9 ) ;
return 0 ;
}
if ( V_15 )
F_3 ( V_16 L_10 , V_7 ) ;
V_9 = ( V_7 & V_22 ) << 4 ;
V_9 += ( ( ( V_3 >> V_25 ) & V_26 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_9 ) ) ) {
if ( V_15 )
F_3 ( V_16 L_3 ,
F_5 ( V_9 ) ) ;
return 0 ;
}
V_8 = F_7 ( V_9 ) ;
if ( ( ( V_8 & V_17 ) == V_18 ) ) {
if ( V_15 )
F_3 ( V_16 L_11 ) ;
V_10 = 1 ;
V_11 = V_8 ;
V_12 = V_8 & V_19 ;
goto V_20;
}
if ( ( ( V_8 & V_17 ) != V_21 ) ) {
if ( V_15 )
F_3 ( V_16 L_12 ) ;
return 0 ;
}
if ( V_15 )
F_3 ( V_16 L_13 , V_8 ) ;
V_9 = ( V_8 & V_22 ) << 4 ;
V_9 += ( ( ( V_3 >> V_27 ) & V_28 ) * 4 ) ;
if ( ! F_4 ( F_5 ( V_9 ) ) )
return 0 ;
V_9 = F_7 ( V_9 ) ;
if ( ( ( V_9 & V_17 ) == V_18 ) ) {
if ( V_15 )
F_3 ( V_16 L_14 ) ;
V_10 = 0 ;
V_11 = V_9 ;
V_12 = V_9 & V_19 ;
goto V_20;
}
if ( V_15 )
F_3 ( V_16 L_15 ) ;
return 0 ;
V_20:
switch ( V_10 ) {
case 0 :
V_14 =
( V_3 & ~ ( - 1 << V_27 ) ) | ( ( V_11 & ~ 0xff ) << 4 ) ;
break;
case 1 :
V_14 =
( V_3 & ~ ( - 1 << V_25 ) ) | ( ( V_11 & ~ 0xff ) << 4 ) ;
break;
case 2 :
V_14 =
( V_3 & ~ ( - 1 << V_23 ) ) | ( ( V_11 & ~ 0xff ) << 4 ) ;
break;
default:
case 3 :
V_14 = V_3 ;
break;
}
if ( V_15 )
F_3 ( V_16 L_16 , V_14 ) ;
if ( V_4 )
* V_4 = V_14 ;
return V_11 ;
}
void F_8 ( void )
{
__asm__ __volatile__(" flush ");
}
void F_9 ( void )
{
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void F_10 ( struct V_29 * V_30 , unsigned long V_31 )
{
if ( V_30 -> V_32 & V_33 )
F_8 () ;
F_9 () ;
}
void F_11 ( void )
{
__asm__ __volatile__(" flush ");
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void F_12 ( void )
{
F_11 () ;
__asm__ __volatile__("sta %%g0, [%0] %1\n\t" : : "r"(0x400),
"i"(ASI_LEON_MMUFLUSH) : "memory");
}
void F_13 ( struct V_34 * V_35 )
{
unsigned long V_36 , V_37 , V_38 ;
if ( ! V_35 )
return;
__asm__ __volatile__("lda [%%g0] %3, %0\n\t"
"mov 0x08, %%g1\n\t"
"lda [%%g1] %3, %1\n\t"
"mov 0x0c, %%g1\n\t"
"lda [%%g1] %3, %2\n\t"
: "=r"(ccr), "=r"(iccr), "=r"(dccr)
: "i"(ASI_LEON_CACHEREGS)
: "g1"
);
V_35 -> V_36 = V_36 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_38 = V_38 ;
}
int T_1 F_14 ( void )
{
int V_39 = - 1 ;
unsigned int V_40 , V_41 ;
char * V_42 [ 4 ] =
{ L_17 , L_18 , L_19 ,
L_20
} ;
struct V_34 V_43 ;
F_13 ( & V_43 ) ;
V_41 = ( V_43 . V_38 & V_44 ) >> 24 ;
V_40 = 1 << ( ( V_43 . V_38 & V_45 ) >> 20 ) ;
F_3 ( V_16 L_21 ,
V_41 > 3 ? L_22 : V_42 [ V_41 ] , V_40 ) ;
if ( ( V_40 <= ( V_46 / 1024 ) ) && ( V_41 == 0 ) ) {
V_39 = 0 ;
F_3 ( V_16 L_23 ) ;
}
return V_39 ;
}
void F_15 ( void )
{
F_16 ( ( void * ) 0 ) ;
if ( V_47 )
F_11 () ;
}
static void F_17 ( struct V_48 * V_49 )
{
F_11 () ;
}
static void F_18 ( struct V_29 * V_30 , unsigned long V_31 )
{
F_10 ( V_30 , V_31 ) ;
}
static void F_19 ( struct V_29 * V_30 ,
unsigned long V_50 ,
unsigned long V_51 )
{
F_11 () ;
}
static void F_20 ( struct V_48 * V_49 )
{
F_12 () ;
}
static void F_21 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
F_12 () ;
}
static void F_22 ( struct V_29 * V_30 ,
unsigned long V_50 ,
unsigned long V_51 )
{
F_12 () ;
}
static void F_23 ( unsigned long V_31 )
{
F_11 () ;
}
static void F_24 ( struct V_48 * V_49 , unsigned long V_31 )
{
F_11 () ;
}
static void F_25 ( unsigned long V_31 )
{
F_9 () ;
}
void T_1 F_26 ( void )
{
}
void T_1 F_27 ( void )
{
V_52 = L_24 ;
V_53 = & V_54 ;
V_55 = F_26 ;
V_47 = F_14 () ;
}
