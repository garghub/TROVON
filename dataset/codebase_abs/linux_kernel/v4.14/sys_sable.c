static void
F_1 ( unsigned long V_1 , unsigned long V_2 )
{
int V_3 = 0x537 ;
if ( V_1 >= 16 ) {
V_3 = 0x53d ;
V_2 >>= 16 ;
} else if ( V_1 >= 8 ) {
V_3 = 0x53b ;
V_2 >>= 8 ;
}
F_2 ( V_2 , V_3 ) ;
}
static void
F_3 ( unsigned long V_1 )
{
int V_3 , V_4 , V_5 ;
if ( V_1 >= 16 ) {
V_3 = 0x53c ;
V_4 = 0xE0 | ( V_1 - 16 ) ;
V_5 = 0xE0 | 4 ;
} else if ( V_1 >= 8 ) {
V_3 = 0x53a ;
V_4 = 0xE0 | ( V_1 - 8 ) ;
V_5 = 0xE0 | 3 ;
} else {
V_3 = 0x536 ;
V_4 = 0xE0 | ( V_1 - 0 ) ;
V_5 = 0xE0 | 1 ;
}
F_2 ( V_4 , V_3 ) ;
F_2 ( V_5 , 0x534 ) ;
}
static void T_1
F_4 ( void )
{
F_2 ( - 1 , 0x537 ) ;
F_2 ( - 1 , 0x53b ) ;
F_2 ( - 1 , 0x53d ) ;
F_2 ( 0x44 , 0x535 ) ;
V_6 = & V_7 ;
F_5 ( 40 ) ;
}
static int
F_6 ( const struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
static char V_12 [ 9 ] [ 5 ] = {
{ 32 + 0 , 32 + 0 , 32 + 0 , 32 + 0 , 32 + 0 } ,
{ 32 + 1 , 32 + 1 , 32 + 1 , 32 + 1 , 32 + 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 32 + 2 , 32 + 2 , 32 + 2 , 32 + 2 , 32 + 2 } ,
{ 32 + 3 , 32 + 3 , 32 + 3 , 32 + 3 , 32 + 3 } ,
{ 32 + 4 , 32 + 4 , 32 + 4 , 32 + 4 , 32 + 4 }
} ;
long V_13 = 0 , V_14 = 8 , V_15 = 5 ;
return V_16 ;
}
static void
F_7 ( unsigned long V_1 , unsigned long V_2 )
{
* ( V_17 ) V_18 = 0x40 ;
F_8 () ;
* ( V_17 ) V_18 ;
F_8 () ;
* ( V_17 ) V_19 = V_2 ;
F_8 () ;
F_8 () ;
}
static void
F_9 ( unsigned long V_1 )
{
* ( V_17 ) V_20 = ( V_21 ) V_1 ;
F_8 () ;
F_8 () ;
}
static void T_1
F_10 ( void )
{
V_6 = & V_22 ;
F_5 ( 64 ) ;
}
static int
F_11 ( const struct V_8 * V_9 , T_2 V_10 , T_2 V_11 )
{
static char V_12 [ 19 ] [ 5 ] = {
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 28 , 28 , 28 , 28 , 28 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 32 , 32 , 33 , 34 , 35 } ,
{ 36 , 36 , 37 , 38 , 39 } ,
{ 40 , 40 , 41 , 42 , 43 } ,
{ 44 , 44 , 45 , 46 , 47 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 28 , 28 , 28 , 28 , 28 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 48 , 48 , 49 , 50 , 51 } ,
{ 52 , 52 , 53 , 54 , 55 } ,
{ 56 , 56 , 57 , 58 , 59 } ,
{ 60 , 60 , 61 , 62 , 63 }
} ;
const long V_13 = 2 , V_14 = 20 , V_15 = 5 ;
return V_16 ;
}
static T_2
F_12 ( struct V_8 * V_9 , T_2 * V_23 )
{
int V_10 , V_11 = * V_23 ;
if ( V_9 -> V_24 -> V_25 == 0 ) {
V_10 = F_13 ( V_9 -> V_26 ) ;
}
else if ( F_13 ( V_9 -> V_24 -> V_27 -> V_26 ) == 3 ) {
V_10 = F_13 ( V_9 -> V_26 ) + 11 ;
}
else
{
do {
if ( F_13 ( V_9 -> V_24 -> V_27 -> V_26 ) == 3 ) {
V_10 = F_13 ( V_9 -> V_26 ) + 11 ;
break;
}
V_11 = F_14 ( V_9 , V_11 ) ;
V_9 = V_9 -> V_24 -> V_27 ;
V_10 = F_13 ( V_9 -> V_26 ) ;
} while ( V_9 -> V_24 -> V_27 );
}
* V_23 = V_11 ;
return V_10 ;
}
static inline void
F_15 ( struct V_28 * V_29 )
{
unsigned long V_1 , V_2 ;
V_1 = V_6 -> V_30 [ V_29 -> V_31 ] ;
F_16 ( & V_32 ) ;
V_2 = V_6 -> V_33 &= ~ ( 1UL << V_1 ) ;
V_6 -> V_34 ( V_1 , V_2 ) ;
F_17 ( & V_32 ) ;
#if 0
printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
__func__, mask, bit, irq);
#endif
}
static void
F_18 ( struct V_28 * V_29 )
{
unsigned long V_1 , V_2 ;
V_1 = V_6 -> V_30 [ V_29 -> V_31 ] ;
F_16 ( & V_32 ) ;
V_2 = V_6 -> V_33 |= 1UL << V_1 ;
V_6 -> V_34 ( V_1 , V_2 ) ;
F_17 ( & V_32 ) ;
#if 0
printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
__func__, mask, bit, irq);
#endif
}
static void
F_19 ( struct V_28 * V_29 )
{
unsigned long V_1 , V_2 ;
V_1 = V_6 -> V_30 [ V_29 -> V_31 ] ;
F_16 ( & V_32 ) ;
V_2 = V_6 -> V_33 |= 1UL << V_1 ;
V_6 -> V_34 ( V_1 , V_2 ) ;
V_6 -> V_35 ( V_1 ) ;
F_17 ( & V_32 ) ;
}
static void
F_20 ( unsigned long V_36 )
{
int V_1 , V_31 ;
V_1 = ( V_36 - 0x800 ) >> 4 ;
V_31 = V_6 -> V_37 [ V_1 ] ;
#if 0
printk("%s: vector 0x%lx bit 0x%x irq 0x%x\n",
__func__, vector, bit, irq);
#endif
F_21 ( V_31 ) ;
}
static void T_1
F_5 ( int V_38 )
{
long V_39 ;
for ( V_39 = 0 ; V_39 < V_38 ; ++ V_39 ) {
F_22 ( V_39 , & V_40 ,
V_41 ) ;
F_23 ( V_39 , V_42 ) ;
}
F_24 () ;
}
static void T_1
F_25 ( void )
{
F_26 () ;
}
