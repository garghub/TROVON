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
unsigned int F_4 ( const unsigned int * V_1 ,
unsigned long V_4 , int V_5 )
{
unsigned int V_6 ;
long V_7 ;
V_7 = V_4 ;
if ( ! ( V_5 & V_8 ) )
V_7 = V_7 - ( unsigned long ) V_1 ;
if ( V_7 < - 0x2000000 || V_7 > 0x1fffffc || V_7 & 0x3 )
return 0 ;
V_6 = 0x48000000 | ( V_5 & 0x3 ) | ( V_7 & 0x03FFFFFC ) ;
return V_6 ;
}
unsigned int F_5 ( const unsigned int * V_1 ,
unsigned long V_4 , int V_5 )
{
unsigned int V_6 ;
long V_7 ;
V_7 = V_4 ;
if ( ! ( V_5 & V_8 ) )
V_7 = V_7 - ( unsigned long ) V_1 ;
if ( V_7 < - 0x8000 || V_7 > 0x7FFF || V_7 & 0x3 )
return 0 ;
V_6 = 0x40000000 | ( V_5 & 0x3FF0003 ) | ( V_7 & 0xFFFC ) ;
return V_6 ;
}
static unsigned int F_6 ( unsigned int V_2 )
{
return ( V_2 >> 26 ) & 0x3F ;
}
static int F_7 ( unsigned int V_2 )
{
return F_6 ( V_2 ) == 18 ;
}
static int F_8 ( unsigned int V_2 )
{
return F_6 ( V_2 ) == 16 ;
}
int F_9 ( unsigned int V_2 )
{
if ( V_2 & V_8 )
return 0 ;
return F_7 ( V_2 ) || F_8 ( V_2 ) ;
}
static unsigned long F_10 ( const unsigned int * V_2 )
{
signed long V_9 ;
V_9 = * V_2 & 0x3FFFFFC ;
if ( V_9 & 0x2000000 )
V_9 -= 0x4000000 ;
if ( ( * V_2 & V_8 ) == 0 )
V_9 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_9 ;
}
static unsigned long F_11 ( const unsigned int * V_2 )
{
signed long V_9 ;
V_9 = * V_2 & 0xFFFC ;
if ( V_9 & 0x8000 )
V_9 -= 0x10000 ;
if ( ( * V_2 & V_8 ) == 0 )
V_9 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_9 ;
}
unsigned long F_12 ( const unsigned int * V_2 )
{
if ( F_7 ( * V_2 ) )
return F_10 ( V_2 ) ;
else if ( F_8 ( * V_2 ) )
return F_11 ( V_2 ) ;
return 0 ;
}
int F_13 ( const unsigned int * V_2 , unsigned long V_1 )
{
if ( F_7 ( * V_2 ) || F_8 ( * V_2 ) )
return F_12 ( V_2 ) == V_1 ;
return 0 ;
}
unsigned int F_14 ( const unsigned int * V_10 , const unsigned int * V_11 )
{
unsigned long V_4 ;
V_4 = F_12 ( V_11 ) ;
if ( F_7 ( * V_11 ) )
return F_4 ( V_10 , V_4 , * V_11 ) ;
else if ( F_8 ( * V_11 ) )
return F_5 ( V_10 , V_4 , * V_11 ) ;
return 0 ;
}
void F_15 ( int V_12 , unsigned long V_1 )
{
extern unsigned int V_13 ;
unsigned int * V_14 = & V_13 ;
F_3 ( V_14 + ( V_12 / 4 ) + 1 , V_1 , 0 ) ;
}
static void T_1 F_16 ( void )
{
asm ("nop;\n");
}
static void T_1 F_17 ( void )
{
unsigned int V_2 ;
unsigned long V_1 ;
V_1 = ( unsigned long ) & V_2 ;
F_18 ( F_7 ( 0x48000000 ) ) ;
F_18 ( F_7 ( 0x4bffffff ) ) ;
F_18 ( ! F_7 ( 0xcbffffff ) ) ;
F_18 ( ! F_7 ( 0x7bffffff ) ) ;
F_18 ( F_7 ( 0x48000001 ) ) ;
F_18 ( F_7 ( 0x4bfffffd ) ) ;
F_18 ( F_7 ( 0x4bff00fd ) ) ;
F_18 ( ! F_7 ( 0x7bfffffd ) ) ;
V_2 = 0x48000103 ;
F_18 ( F_13 ( & V_2 , 0x100 ) ) ;
V_2 = 0x480420ff ;
F_18 ( F_13 ( & V_2 , 0x420fc ) ) ;
V_2 = 0x49fffffc ;
F_18 ( F_13 ( & V_2 , V_1 + 0x1FFFFFC ) ) ;
V_2 = 0x4bfffffc ;
F_18 ( F_13 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x4a000000 ;
F_18 ( F_13 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 , V_15 ) ;
F_18 ( F_13 ( & V_2 , V_1 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x100 , V_15 ) ;
F_18 ( F_13 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x100 , 0 ) ;
F_18 ( F_13 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000000 , V_15 ) ;
F_18 ( F_13 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000004 , V_15 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x2000000 , V_15 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 3 , V_15 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 , 0xFFFFFFFC ) ;
F_18 ( F_13 ( & V_2 , V_1 ) ) ;
F_18 ( V_2 == 0x48000000 ) ;
}
static void T_1 F_19 ( void )
{
unsigned int * V_16 ;
unsigned long V_10 ;
V_16 = ( unsigned int * ) F_20 ( F_16 ) ;
V_10 = F_20 ( F_19 ) ;
F_1 ( V_16 , F_4 ( V_16 , V_10 , V_15 ) ) ;
F_18 ( F_13 ( V_16 , V_10 ) ) ;
}
static void T_1 F_21 ( void )
{
unsigned long V_1 ;
unsigned int * V_16 , V_2 , V_5 ;
V_16 = & V_2 ;
V_1 = ( unsigned long ) V_16 ;
F_18 ( F_8 ( 0x40000000 ) ) ;
F_18 ( F_8 ( 0x43ffffff ) ) ;
F_18 ( ! F_8 ( 0xc3ffffff ) ) ;
F_18 ( ! F_8 ( 0x7bffffff ) ) ;
V_2 = 0x43ff0103 ;
F_18 ( F_13 ( & V_2 , 0x100 ) ) ;
V_2 = 0x43ff20ff ;
F_18 ( F_13 ( & V_2 , 0x20fc ) ) ;
V_2 = 0x43ff7ffc ;
F_18 ( F_13 ( & V_2 , V_1 + 0x7FFC ) ) ;
V_2 = 0x43fffffc ;
F_18 ( F_13 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x43ff8000 ;
F_18 ( F_13 ( & V_2 , V_1 - 0x8000 ) ) ;
V_5 = 0x3ff000 | V_15 ;
V_2 = F_5 ( V_16 , V_1 , V_5 ) ;
F_18 ( F_13 ( & V_2 , V_1 ) ) ;
V_2 = F_5 ( V_16 , V_1 - 0x100 , V_5 ) ;
F_18 ( F_13 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_5 ( V_16 , V_1 + 0x100 , V_5 ) ;
F_18 ( F_13 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_5 ( V_16 , V_1 - 0x8000 , V_5 ) ;
F_18 ( F_13 ( & V_2 , V_1 - 0x8000 ) ) ;
V_2 = F_5 ( V_16 , V_1 - 0x8004 , V_5 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_5 ( V_16 , V_1 + 0x8000 , V_5 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_5 ( V_16 , V_1 + 3 , V_5 ) ;
F_18 ( V_2 == 0 ) ;
V_2 = F_5 ( V_16 , V_1 , 0xFFFFFFFC ) ;
F_18 ( F_13 ( & V_2 , V_1 ) ) ;
F_18 ( V_2 == 0x43FF0000 ) ;
}
static void T_1 F_22 ( void )
{
unsigned long V_1 ;
unsigned int * V_17 , * V_18 ;
void * V_19 ;
V_19 = F_23 ( F_24 ( 0x2000000 + 1 ) ) ;
F_18 ( V_19 ) ;
if ( ! V_19 )
return;
V_17 = V_19 ;
V_1 = ( unsigned long ) V_17 ;
F_3 ( V_17 , V_1 , 0 ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
V_18 = V_17 + 1 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
V_17 = V_19 ;
V_1 = ( unsigned long ) V_17 ;
F_3 ( V_17 , V_1 , 0 ) ;
V_18 = V_19 + 0x2000000 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
F_18 ( * V_18 == 0x4a000000 ) ;
V_17 = V_19 + 0x2000000 ;
V_1 = ( unsigned long ) V_17 ;
F_3 ( V_17 , V_1 , 0 ) ;
V_18 = V_19 + 4 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
F_18 ( * V_18 == 0x49fffffc ) ;
V_17 = V_19 ;
V_1 = 0x1000000 + ( unsigned long ) V_19 ;
F_3 ( V_17 , V_1 , V_15 ) ;
V_18 = V_19 + 0x1400000 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
V_17 = V_19 + 0x1000000 ;
V_1 = 0x2000000 + ( unsigned long ) V_19 ;
F_3 ( V_17 , V_1 , 0 ) ;
V_18 = V_19 + 4 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
V_17 = V_19 ;
V_1 = ( unsigned long ) V_17 ;
F_1 ( V_17 , F_5 ( V_17 , V_1 , 0 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
V_18 = V_17 + 1 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
V_17 = V_19 ;
V_1 = ( unsigned long ) V_17 ;
F_1 ( V_17 , F_5 ( V_17 , V_1 , 0xFFFFFFFC ) ) ;
V_18 = V_19 + 0x8000 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
F_18 ( * V_18 == 0x43ff8000 ) ;
V_17 = V_19 + 0x8000 ;
V_1 = ( unsigned long ) V_17 ;
F_1 ( V_17 , F_5 ( V_17 , V_1 , 0xFFFFFFFC ) ) ;
V_18 = V_19 + 4 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
F_18 ( * V_18 == 0x43ff7ffc ) ;
V_17 = V_19 ;
V_1 = 0x3000 + ( unsigned long ) V_19 ;
F_1 ( V_17 , F_5 ( V_17 , V_1 , V_15 ) ) ;
V_18 = V_19 + 0x5000 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
V_17 = V_19 + 0x2000 ;
V_1 = 0x4000 + ( unsigned long ) V_19 ;
F_1 ( V_17 , F_5 ( V_17 , V_1 , 0 ) ) ;
V_18 = V_19 + 4 ;
F_1 ( V_18 , F_14 ( V_18 , V_17 ) ) ;
F_18 ( F_13 ( V_17 , V_1 ) ) ;
F_18 ( F_13 ( V_18 , V_1 ) ) ;
F_25 ( V_19 ) ;
}
static int T_1 F_26 ( void )
{
F_27 ( V_20 L_1 ) ;
F_17 () ;
F_21 () ;
F_19 () ;
F_22 () ;
return 0 ;
}
