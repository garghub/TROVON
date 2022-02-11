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
static void T_1 F_15 ( void )
{
asm ("nop;\n");
}
static void T_1 F_16 ( void )
{
unsigned int V_2 ;
unsigned long V_1 ;
V_1 = ( unsigned long ) & V_2 ;
F_17 ( F_7 ( 0x48000000 ) ) ;
F_17 ( F_7 ( 0x4bffffff ) ) ;
F_17 ( ! F_7 ( 0xcbffffff ) ) ;
F_17 ( ! F_7 ( 0x7bffffff ) ) ;
F_17 ( F_7 ( 0x48000001 ) ) ;
F_17 ( F_7 ( 0x4bfffffd ) ) ;
F_17 ( F_7 ( 0x4bff00fd ) ) ;
F_17 ( ! F_7 ( 0x7bfffffd ) ) ;
V_2 = 0x48000103 ;
F_17 ( F_13 ( & V_2 , 0x100 ) ) ;
V_2 = 0x480420ff ;
F_17 ( F_13 ( & V_2 , 0x420fc ) ) ;
V_2 = 0x49fffffc ;
F_17 ( F_13 ( & V_2 , V_1 + 0x1FFFFFC ) ) ;
V_2 = 0x4bfffffc ;
F_17 ( F_13 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x4a000000 ;
F_17 ( F_13 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 , V_12 ) ;
F_17 ( F_13 ( & V_2 , V_1 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x100 , V_12 ) ;
F_17 ( F_13 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x100 , 0 ) ;
F_17 ( F_13 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000000 , V_12 ) ;
F_17 ( F_13 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_4 ( & V_2 , V_1 - 0x2000004 , V_12 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 0x2000000 , V_12 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 + 3 , V_12 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_4 ( & V_2 , V_1 , 0xFFFFFFFC ) ;
F_17 ( F_13 ( & V_2 , V_1 ) ) ;
F_17 ( V_2 == 0x48000000 ) ;
}
static void T_1 F_18 ( void )
{
unsigned int * V_13 ;
unsigned long V_10 ;
V_13 = ( unsigned int * ) F_19 ( F_15 ) ;
V_10 = F_19 ( F_18 ) ;
F_1 ( V_13 , F_4 ( V_13 , V_10 , V_12 ) ) ;
F_17 ( F_13 ( V_13 , V_10 ) ) ;
}
static void T_1 F_20 ( void )
{
unsigned long V_1 ;
unsigned int * V_13 , V_2 , V_5 ;
V_13 = & V_2 ;
V_1 = ( unsigned long ) V_13 ;
F_17 ( F_8 ( 0x40000000 ) ) ;
F_17 ( F_8 ( 0x43ffffff ) ) ;
F_17 ( ! F_8 ( 0xc3ffffff ) ) ;
F_17 ( ! F_8 ( 0x7bffffff ) ) ;
V_2 = 0x43ff0103 ;
F_17 ( F_13 ( & V_2 , 0x100 ) ) ;
V_2 = 0x43ff20ff ;
F_17 ( F_13 ( & V_2 , 0x20fc ) ) ;
V_2 = 0x43ff7ffc ;
F_17 ( F_13 ( & V_2 , V_1 + 0x7FFC ) ) ;
V_2 = 0x43fffffc ;
F_17 ( F_13 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x43ff8000 ;
F_17 ( F_13 ( & V_2 , V_1 - 0x8000 ) ) ;
V_5 = 0x3ff000 | V_12 ;
V_2 = F_5 ( V_13 , V_1 , V_5 ) ;
F_17 ( F_13 ( & V_2 , V_1 ) ) ;
V_2 = F_5 ( V_13 , V_1 - 0x100 , V_5 ) ;
F_17 ( F_13 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_5 ( V_13 , V_1 + 0x100 , V_5 ) ;
F_17 ( F_13 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_5 ( V_13 , V_1 - 0x8000 , V_5 ) ;
F_17 ( F_13 ( & V_2 , V_1 - 0x8000 ) ) ;
V_2 = F_5 ( V_13 , V_1 - 0x8004 , V_5 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_5 ( V_13 , V_1 + 0x8000 , V_5 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_5 ( V_13 , V_1 + 3 , V_5 ) ;
F_17 ( V_2 == 0 ) ;
V_2 = F_5 ( V_13 , V_1 , 0xFFFFFFFC ) ;
F_17 ( F_13 ( & V_2 , V_1 ) ) ;
F_17 ( V_2 == 0x43FF0000 ) ;
}
static void T_1 F_21 ( void )
{
unsigned long V_1 ;
unsigned int * V_14 , * V_15 ;
void * V_16 ;
V_16 = F_22 ( F_23 ( 0x2000000 + 1 ) ) ;
F_17 ( V_16 ) ;
if ( ! V_16 )
return;
V_14 = V_16 ;
V_1 = ( unsigned long ) V_14 ;
F_3 ( V_14 , V_1 , 0 ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
V_15 = V_14 + 1 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
V_14 = V_16 ;
V_1 = ( unsigned long ) V_14 ;
F_3 ( V_14 , V_1 , 0 ) ;
V_15 = V_16 + 0x2000000 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
F_17 ( * V_15 == 0x4a000000 ) ;
V_14 = V_16 + 0x2000000 ;
V_1 = ( unsigned long ) V_14 ;
F_3 ( V_14 , V_1 , 0 ) ;
V_15 = V_16 + 4 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
F_17 ( * V_15 == 0x49fffffc ) ;
V_14 = V_16 ;
V_1 = 0x1000000 + ( unsigned long ) V_16 ;
F_3 ( V_14 , V_1 , V_12 ) ;
V_15 = V_16 + 0x1400000 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
V_14 = V_16 + 0x1000000 ;
V_1 = 0x2000000 + ( unsigned long ) V_16 ;
F_3 ( V_14 , V_1 , 0 ) ;
V_15 = V_16 + 4 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
V_14 = V_16 ;
V_1 = ( unsigned long ) V_14 ;
F_1 ( V_14 , F_5 ( V_14 , V_1 , 0 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
V_15 = V_14 + 1 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
V_14 = V_16 ;
V_1 = ( unsigned long ) V_14 ;
F_1 ( V_14 , F_5 ( V_14 , V_1 , 0xFFFFFFFC ) ) ;
V_15 = V_16 + 0x8000 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
F_17 ( * V_15 == 0x43ff8000 ) ;
V_14 = V_16 + 0x8000 ;
V_1 = ( unsigned long ) V_14 ;
F_1 ( V_14 , F_5 ( V_14 , V_1 , 0xFFFFFFFC ) ) ;
V_15 = V_16 + 4 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
F_17 ( * V_15 == 0x43ff7ffc ) ;
V_14 = V_16 ;
V_1 = 0x3000 + ( unsigned long ) V_16 ;
F_1 ( V_14 , F_5 ( V_14 , V_1 , V_12 ) ) ;
V_15 = V_16 + 0x5000 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
V_14 = V_16 + 0x2000 ;
V_1 = 0x4000 + ( unsigned long ) V_16 ;
F_1 ( V_14 , F_5 ( V_14 , V_1 , 0 ) ) ;
V_15 = V_16 + 4 ;
F_1 ( V_15 , F_14 ( V_15 , V_14 ) ) ;
F_17 ( F_13 ( V_14 , V_1 ) ) ;
F_17 ( F_13 ( V_15 , V_1 ) ) ;
F_24 ( V_16 ) ;
}
static int T_1 F_25 ( void )
{
F_26 ( V_17 L_1 ) ;
F_16 () ;
F_20 () ;
F_18 () ;
F_21 () ;
return 0 ;
}
