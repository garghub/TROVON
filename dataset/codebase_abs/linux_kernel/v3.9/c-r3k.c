unsigned long T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 , V_4 , V_5 ;
volatile unsigned long * V_6 ;
V_6 = ( volatile unsigned long * ) V_7 ;
V_2 = F_2 () ;
F_3 ( ( V_1 | V_2 ) & ~ V_8 ) ;
* V_6 = 0xa5a55a5a ;
V_4 = * V_6 ;
V_3 = F_2 () ;
if ( V_4 != 0xa5a55a5a || ( V_3 & V_9 ) ) {
V_5 = 0 ;
} else {
for ( V_5 = 128 ; V_5 <= 0x40000 ; V_5 <<= 1 )
* ( V_6 + V_5 ) = 0 ;
* V_6 = - 1 ;
for ( V_5 = 128 ;
( V_5 <= 0x40000 ) && ( * ( V_6 + V_5 ) == 0 ) ;
V_5 <<= 1 )
;
if ( V_5 > 0x40000 )
V_5 = 0 ;
}
F_3 ( V_2 ) ;
return V_5 * sizeof( * V_6 ) ;
}
unsigned long T_1 F_4 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 , V_10 , V_11 ;
volatile unsigned long * V_6 ;
V_6 = ( volatile unsigned long * ) V_7 ;
V_2 = F_2 () ;
F_3 ( ( V_1 | V_2 ) & ~ V_8 ) ;
for ( V_11 = 0 ; V_11 < 128 ; V_11 ++ )
* ( V_6 + V_11 ) = 0 ;
* ( volatile unsigned char * ) V_6 = 0 ;
for ( V_10 = 1 ; V_10 < 128 ; V_10 <<= 1 ) {
* ( V_6 + V_10 ) ;
V_3 = F_2 () ;
if ( ! ( V_3 & V_9 ) )
break;
}
for ( V_11 = 0 ; V_11 < 128 ; V_11 += V_10 )
* ( volatile unsigned char * ) ( V_6 + V_11 ) = 0 ;
F_3 ( V_2 ) ;
return V_10 * sizeof( * V_6 ) ;
}
static void T_1 F_5 ( void )
{
V_12 = F_1 ( V_13 ) ;
if ( V_12 )
V_14 = F_4 ( V_13 ) ;
V_15 = F_1 ( V_13 | V_16 ) ;
if ( V_15 )
V_17 = F_4 ( V_13 | V_16 ) ;
}
static void F_6 ( unsigned long V_18 , unsigned long V_19 )
{
unsigned long V_5 , V_11 , V_2 ;
volatile unsigned char * V_6 ;
V_5 = V_19 - V_18 ;
if ( V_5 > V_15 || F_7 ( V_18 ) != V_7 ) {
V_18 = V_7 ;
V_5 = V_15 ;
}
V_6 = ( char * ) V_18 ;
V_2 = F_2 () ;
F_3 ( ( V_13 | V_16 | V_2 ) & ~ V_8 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 += 0x080 ) {
asm( "sb\t$0, 0x000(%0)\n\t"
"sb\t$0, 0x004(%0)\n\t"
"sb\t$0, 0x008(%0)\n\t"
"sb\t$0, 0x00c(%0)\n\t"
"sb\t$0, 0x010(%0)\n\t"
"sb\t$0, 0x014(%0)\n\t"
"sb\t$0, 0x018(%0)\n\t"
"sb\t$0, 0x01c(%0)\n\t"
"sb\t$0, 0x020(%0)\n\t"
"sb\t$0, 0x024(%0)\n\t"
"sb\t$0, 0x028(%0)\n\t"
"sb\t$0, 0x02c(%0)\n\t"
"sb\t$0, 0x030(%0)\n\t"
"sb\t$0, 0x034(%0)\n\t"
"sb\t$0, 0x038(%0)\n\t"
"sb\t$0, 0x03c(%0)\n\t"
"sb\t$0, 0x040(%0)\n\t"
"sb\t$0, 0x044(%0)\n\t"
"sb\t$0, 0x048(%0)\n\t"
"sb\t$0, 0x04c(%0)\n\t"
"sb\t$0, 0x050(%0)\n\t"
"sb\t$0, 0x054(%0)\n\t"
"sb\t$0, 0x058(%0)\n\t"
"sb\t$0, 0x05c(%0)\n\t"
"sb\t$0, 0x060(%0)\n\t"
"sb\t$0, 0x064(%0)\n\t"
"sb\t$0, 0x068(%0)\n\t"
"sb\t$0, 0x06c(%0)\n\t"
"sb\t$0, 0x070(%0)\n\t"
"sb\t$0, 0x074(%0)\n\t"
"sb\t$0, 0x078(%0)\n\t"
"sb\t$0, 0x07c(%0)\n\t"
: : "r" (p) );
V_6 += 0x080 ;
}
F_3 ( V_2 ) ;
}
static void F_8 ( unsigned long V_18 , unsigned long V_19 )
{
unsigned long V_5 , V_11 , V_2 ;
volatile unsigned char * V_6 ;
V_5 = V_19 - V_18 ;
if ( V_5 > V_12 || F_7 ( V_18 ) != V_7 ) {
V_18 = V_7 ;
V_5 = V_12 ;
}
V_6 = ( char * ) V_18 ;
V_2 = F_2 () ;
F_3 ( ( V_13 | V_2 ) & ~ V_8 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 += 0x080 ) {
asm( "sb\t$0, 0x000(%0)\n\t"
"sb\t$0, 0x004(%0)\n\t"
"sb\t$0, 0x008(%0)\n\t"
"sb\t$0, 0x00c(%0)\n\t"
"sb\t$0, 0x010(%0)\n\t"
"sb\t$0, 0x014(%0)\n\t"
"sb\t$0, 0x018(%0)\n\t"
"sb\t$0, 0x01c(%0)\n\t"
"sb\t$0, 0x020(%0)\n\t"
"sb\t$0, 0x024(%0)\n\t"
"sb\t$0, 0x028(%0)\n\t"
"sb\t$0, 0x02c(%0)\n\t"
"sb\t$0, 0x030(%0)\n\t"
"sb\t$0, 0x034(%0)\n\t"
"sb\t$0, 0x038(%0)\n\t"
"sb\t$0, 0x03c(%0)\n\t"
"sb\t$0, 0x040(%0)\n\t"
"sb\t$0, 0x044(%0)\n\t"
"sb\t$0, 0x048(%0)\n\t"
"sb\t$0, 0x04c(%0)\n\t"
"sb\t$0, 0x050(%0)\n\t"
"sb\t$0, 0x054(%0)\n\t"
"sb\t$0, 0x058(%0)\n\t"
"sb\t$0, 0x05c(%0)\n\t"
"sb\t$0, 0x060(%0)\n\t"
"sb\t$0, 0x064(%0)\n\t"
"sb\t$0, 0x068(%0)\n\t"
"sb\t$0, 0x06c(%0)\n\t"
"sb\t$0, 0x070(%0)\n\t"
"sb\t$0, 0x074(%0)\n\t"
"sb\t$0, 0x078(%0)\n\t"
"sb\t$0, 0x07c(%0)\n\t"
: : "r" (p) );
V_6 += 0x080 ;
}
F_3 ( V_2 ) ;
}
static inline void F_9 ( void )
{
}
static inline void F_10 ( void )
{
F_8 ( V_7 , V_7 + V_12 ) ;
F_6 ( V_7 , V_7 + V_15 ) ;
}
static void F_11 ( struct V_20 * V_21 )
{
}
static void F_12 ( struct V_22 * V_23 ,
unsigned long V_18 , unsigned long V_19 )
{
}
static void F_13 ( struct V_22 * V_23 ,
unsigned long V_24 , unsigned long V_25 )
{
unsigned long V_26 = F_14 ( V_25 << V_27 ) ;
int V_28 = V_23 -> V_29 & V_30 ;
struct V_20 * V_21 = V_23 -> V_31 ;
T_2 * V_32 ;
T_3 * V_33 ;
T_4 * V_34 ;
T_5 * V_35 ;
F_15 ( L_1 ,
F_16 ( F_17 () , V_21 ) , V_24 ) ;
if ( F_16 ( F_17 () , V_21 ) == 0 )
return;
V_32 = F_18 ( V_21 , V_24 ) ;
V_33 = F_19 ( V_32 , V_24 ) ;
V_34 = F_20 ( V_33 , V_24 ) ;
V_35 = F_21 ( V_34 , V_24 ) ;
if ( ! ( F_22 ( * V_35 ) & V_36 ) )
return;
F_8 ( V_26 , V_26 + V_37 ) ;
if ( V_28 )
F_6 ( V_26 , V_26 + V_37 ) ;
}
static void F_23 ( void * V_24 )
{
}
static void F_24 ( unsigned long V_24 )
{
}
static void F_25 ( unsigned long V_24 )
{
unsigned long V_2 ;
F_15 ( L_2 , V_24 ) ;
V_2 = F_2 () ;
F_3 ( V_2 & ~ V_8 ) ;
asm( "lw\t$0, 0x000(%0)\n\t"
"lw\t$0, 0x004(%0)\n\t"
: : "r" (addr) );
F_3 ( ( V_13 | V_16 | V_2 ) & ~ V_8 ) ;
asm( "sb\t$0, 0x000(%0)\n\t"
"sb\t$0, 0x004(%0)\n\t"
: : "r" (addr) );
F_3 ( V_2 ) ;
}
static void F_26 ( unsigned long V_38 , int V_5 )
{
F_27 () ;
}
static void F_28 ( unsigned long V_18 , unsigned long V_5 )
{
F_29 ( V_5 == 0 ) ;
F_30 () ;
F_8 ( V_18 , V_18 + V_5 ) ;
}
void T_1 F_31 ( void )
{
extern void V_39 ( void ) ;
extern void V_40 ( void ) ;
F_5 () ;
V_41 = F_9 ;
V_42 = F_10 ;
V_43 = F_11 ;
V_44 = F_12 ;
V_45 = F_13 ;
V_46 = F_6 ;
V_47 = F_6 ;
V_48 = F_26 ;
V_49 = F_25 ;
V_50 = F_23 ;
V_51 = F_24 ;
V_52 = F_28 ;
V_53 = F_28 ;
V_54 = F_28 ;
F_32 ( L_3 ,
V_15 >> 10 , V_17 ) ;
F_32 ( L_4 ,
V_12 >> 10 , V_14 ) ;
V_39 () ;
V_40 () ;
}
