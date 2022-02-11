int F_1 ( unsigned int * V_1 , unsigned int V_2 )
{
int V_3 ;
F_2 ( V_2 , V_1 , 4 , V_3 ) ;
if ( V_3 )
return V_3 ;
asm ("dcbst 0, %0; sync; icbi 0,%0; sync; isync" : : "r" (addr));
return 0 ;
}
int F_3 ( unsigned int * V_1 , unsigned long V_4 , int V_5 )
{
return F_1 ( V_1 , F_4 ( V_1 , V_4 , V_5 ) ) ;
}
bool F_5 ( long V_6 )
{
return ( V_6 >= - 0x2000000 && V_6 <= 0x1fffffc && ! ( V_6 & 0x3 ) ) ;
}
bool F_6 ( unsigned int V_2 )
{
unsigned int V_7 = V_2 >> 26 ;
if ( V_7 == 16 )
return true ;
if ( V_7 == 19 ) {
switch ( ( V_2 >> 1 ) & 0x3ff ) {
case 16 :
case 528 :
case 560 :
return true ;
}
}
return false ;
}
unsigned int F_4 ( const unsigned int * V_1 ,
unsigned long V_4 , int V_5 )
{
unsigned int V_8 ;
long V_6 ;
V_6 = V_4 ;
if ( ! ( V_5 & V_9 ) )
V_6 = V_6 - ( unsigned long ) V_1 ;
if ( ! F_5 ( V_6 ) )
return 0 ;
V_8 = 0x48000000 | ( V_5 & 0x3 ) | ( V_6 & 0x03FFFFFC ) ;
return V_8 ;
}
unsigned int F_7 ( const unsigned int * V_1 ,
unsigned long V_4 , int V_5 )
{
unsigned int V_8 ;
long V_6 ;
V_6 = V_4 ;
if ( ! ( V_5 & V_9 ) )
V_6 = V_6 - ( unsigned long ) V_1 ;
if ( V_6 < - 0x8000 || V_6 > 0x7FFF || V_6 & 0x3 )
return 0 ;
V_8 = 0x40000000 | ( V_5 & 0x3FF0003 ) | ( V_6 & 0xFFFC ) ;
return V_8 ;
}
static unsigned int F_8 ( unsigned int V_2 )
{
return ( V_2 >> 26 ) & 0x3F ;
}
static int F_9 ( unsigned int V_2 )
{
return F_8 ( V_2 ) == 18 ;
}
static int F_10 ( unsigned int V_2 )
{
return F_8 ( V_2 ) == 16 ;
}
int F_11 ( unsigned int V_2 )
{
if ( V_2 & V_9 )
return 0 ;
return F_9 ( V_2 ) || F_10 ( V_2 ) ;
}
static unsigned long F_12 ( const unsigned int * V_2 )
{
signed long V_10 ;
V_10 = * V_2 & 0x3FFFFFC ;
if ( V_10 & 0x2000000 )
V_10 -= 0x4000000 ;
if ( ( * V_2 & V_9 ) == 0 )
V_10 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_10 ;
}
static unsigned long F_13 ( const unsigned int * V_2 )
{
signed long V_10 ;
V_10 = * V_2 & 0xFFFC ;
if ( V_10 & 0x8000 )
V_10 -= 0x10000 ;
if ( ( * V_2 & V_9 ) == 0 )
V_10 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_10 ;
}
unsigned long F_14 ( const unsigned int * V_2 )
{
if ( F_9 ( * V_2 ) )
return F_12 ( V_2 ) ;
else if ( F_10 ( * V_2 ) )
return F_13 ( V_2 ) ;
return 0 ;
}
int F_15 ( const unsigned int * V_2 , unsigned long V_1 )
{
if ( F_9 ( * V_2 ) || F_10 ( * V_2 ) )
return F_14 ( V_2 ) == V_1 ;
return 0 ;
}
unsigned int F_16 ( const unsigned int * V_11 , const unsigned int * V_12 )
{
unsigned long V_4 ;
V_4 = F_14 ( V_12 ) ;
if ( F_9 ( * V_12 ) )
return F_4 ( V_11 , V_4 , * V_12 ) ;
else if ( F_10 ( * V_12 ) )
return F_7 ( V_11 , V_4 , * V_12 ) ;
return 0 ;
}
void F_17 ( int V_13 , unsigned long V_1 )
{
extern unsigned int V_14 ;
unsigned int * V_15 = & V_14 ;
F_3 ( V_15 + ( V_13 / 4 ) + 1 , V_1 , 0 ) ;
}
static void T_1 F_18 ( void )
{
asm ("nop;\n");
}
static void T_1 F_19 ( void )
{
unsigned int V_2 ;
unsigned long V_1 ;
V_1 = ( unsigned long ) & V_2 ;
F_20 ( F_9 ( 0x48000000 ) ) ;
F_20 ( F_9 ( 0x4bffffff ) ) ;
F_20 ( ! F_9 ( 0xcbffffff ) ) ;
F_20 ( ! F_9 ( 0x7bffffff ) ) ;
F_20 ( F_9 ( 0x48000001 ) ) ;
F_20 ( F_9 ( 0x4bfffffd ) ) ;
F_20 ( F_9 ( 0x4bff00fd ) ) ;
F_20 ( ! F_9 ( 0x7bfffffd ) ) ;
V_2 = 0x48000103 ;
F_20 ( F_15 ( & V_2 , 0x100 ) ) ;
V_2 = 0x480420ff ;
F_20 ( F_15 ( & V_2 , 0x420fc ) ) ;
V_2 = 0x49fffffc ;
F_20 ( F_15 ( & V_2 , V_1 + 0x1FFFFFC ) ) ;
V_2 = 0x4bfffffc ;
F_20 ( F_15 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x4a000000 ;
F_20 ( F_15 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 , V_16 ) ;
F_20 ( F_15 ( & V_2 , V_1 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x100 , V_16 ) ;
F_20 ( F_15 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x100 , 0 ) ;
F_20 ( F_15 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000000 , V_16 ) ;
F_20 ( F_15 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000004 , V_16 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x2000000 , V_16 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 3 , V_16 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 , 0xFFFFFFFC ) ;
F_20 ( F_15 ( & V_2 , V_1 ) ) ;
F_20 ( V_2 == 0x48000000 ) ;
}
static void T_1 F_21 ( void )
{
unsigned int * V_17 ;
unsigned long V_11 ;
V_17 = ( unsigned int * ) F_22 ( F_18 ) ;
V_11 = F_22 ( F_21 ) ;
F_1 ( V_17 , F_4 ( V_17 , V_11 , V_16 ) ) ;
F_20 ( F_15 ( V_17 , V_11 ) ) ;
}
static void T_1 F_23 ( void )
{
unsigned long V_1 ;
unsigned int * V_17 , V_2 , V_5 ;
V_17 = & V_2 ;
V_1 = ( unsigned long ) V_17 ;
F_20 ( F_10 ( 0x40000000 ) ) ;
F_20 ( F_10 ( 0x43ffffff ) ) ;
F_20 ( ! F_10 ( 0xc3ffffff ) ) ;
F_20 ( ! F_10 ( 0x7bffffff ) ) ;
V_2 = 0x43ff0103 ;
F_20 ( F_15 ( & V_2 , 0x100 ) ) ;
V_2 = 0x43ff20ff ;
F_20 ( F_15 ( & V_2 , 0x20fc ) ) ;
V_2 = 0x43ff7ffc ;
F_20 ( F_15 ( & V_2 , V_1 + 0x7FFC ) ) ;
V_2 = 0x43fffffc ;
F_20 ( F_15 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x43ff8000 ;
F_20 ( F_15 ( & V_2 , V_1 - 0x8000 ) ) ;
V_5 = 0x3ff000 | V_16 ;
V_2 = F_7 ( V_17 , V_1 , V_5 ) ;
F_20 ( F_15 ( & V_2 , V_1 ) ) ;
V_2 = F_7 ( V_17 , V_1 - 0x100 , V_5 ) ;
F_20 ( F_15 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_7 ( V_17 , V_1 + 0x100 , V_5 ) ;
F_20 ( F_15 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_7 ( V_17 , V_1 - 0x8000 , V_5 ) ;
F_20 ( F_15 ( & V_2 , V_1 - 0x8000 ) ) ;
V_2 = F_7 ( V_17 , V_1 - 0x8004 , V_5 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_7 ( V_17 , V_1 + 0x8000 , V_5 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_7 ( V_17 , V_1 + 3 , V_5 ) ;
F_20 ( V_2 == 0 ) ;
V_2 = F_7 ( V_17 , V_1 , 0xFFFFFFFC ) ;
F_20 ( F_15 ( & V_2 , V_1 ) ) ;
F_20 ( V_2 == 0x43FF0000 ) ;
}
static void T_1 F_24 ( void )
{
unsigned long V_1 ;
unsigned int * V_18 , * V_19 ;
void * V_20 ;
V_20 = F_25 ( F_26 ( 0x2000000 + 1 ) ) ;
F_20 ( V_20 ) ;
if ( ! V_20 )
return;
V_18 = V_20 ;
V_1 = ( unsigned long ) V_18 ;
F_3 ( V_18 , V_1 , 0 ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
V_19 = V_18 + 1 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
V_18 = V_20 ;
V_1 = ( unsigned long ) V_18 ;
F_3 ( V_18 , V_1 , 0 ) ;
V_19 = V_20 + 0x2000000 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
F_20 ( * V_19 == 0x4a000000 ) ;
V_18 = V_20 + 0x2000000 ;
V_1 = ( unsigned long ) V_18 ;
F_3 ( V_18 , V_1 , 0 ) ;
V_19 = V_20 + 4 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
F_20 ( * V_19 == 0x49fffffc ) ;
V_18 = V_20 ;
V_1 = 0x1000000 + ( unsigned long ) V_20 ;
F_3 ( V_18 , V_1 , V_16 ) ;
V_19 = V_20 + 0x1400000 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
V_18 = V_20 + 0x1000000 ;
V_1 = 0x2000000 + ( unsigned long ) V_20 ;
F_3 ( V_18 , V_1 , 0 ) ;
V_19 = V_20 + 4 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
V_18 = V_20 ;
V_1 = ( unsigned long ) V_18 ;
F_1 ( V_18 , F_7 ( V_18 , V_1 , 0 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
V_19 = V_18 + 1 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
V_18 = V_20 ;
V_1 = ( unsigned long ) V_18 ;
F_1 ( V_18 , F_7 ( V_18 , V_1 , 0xFFFFFFFC ) ) ;
V_19 = V_20 + 0x8000 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
F_20 ( * V_19 == 0x43ff8000 ) ;
V_18 = V_20 + 0x8000 ;
V_1 = ( unsigned long ) V_18 ;
F_1 ( V_18 , F_7 ( V_18 , V_1 , 0xFFFFFFFC ) ) ;
V_19 = V_20 + 4 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
F_20 ( * V_19 == 0x43ff7ffc ) ;
V_18 = V_20 ;
V_1 = 0x3000 + ( unsigned long ) V_20 ;
F_1 ( V_18 , F_7 ( V_18 , V_1 , V_16 ) ) ;
V_19 = V_20 + 0x5000 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
V_18 = V_20 + 0x2000 ;
V_1 = 0x4000 + ( unsigned long ) V_20 ;
F_1 ( V_18 , F_7 ( V_18 , V_1 , 0 ) ) ;
V_19 = V_20 + 4 ;
F_1 ( V_19 , F_16 ( V_19 , V_18 ) ) ;
F_20 ( F_15 ( V_18 , V_1 ) ) ;
F_20 ( F_15 ( V_19 , V_1 ) ) ;
F_27 ( V_20 ) ;
}
static int T_1 F_28 ( void )
{
F_29 ( V_21 L_1 ) ;
F_19 () ;
F_23 () ;
F_21 () ;
F_24 () ;
return 0 ;
}
